/*
 * File      : SecuAlgo.c
 * Brief     : Security authentication module.
 * Note      : This file implements the HE9145 driver code.
 * Author    : dwyane tade
 * Version   : 1.0.0
 * Date      : 2026-02-01
 * Copyright : (c) 2025 Tianjin Yidingfeng. All rights reserved.
 */

#include "Crypto.h"          /* PRQA S 0380 */ /* provides Csm.h transitively */
#include "SecuAlgo.h"        /* provides SecuAlgo_Cfg.h transitively */
#include "Crypto_common.h"
#include "Fls_DflashLock_LLDriver.h" /* Flash_Lock */




static Crypto_KeyElementType *Secu_GetKeyMaterialElement(uint32 keyId)
{
    uint32 keyIndex = Crypto_SearchKeyIdIndex(keyId);
    uint32 keyElementIndex;

    if (keyIndex >= CRYPTO_NUMBER_OF_KEYS) {
        return NULL_PTR;
    }

    keyElementIndex = Crypto_SearchKeyElementIdIndex(keyIndex, CRYPTO_KE_CIPHER_KEY);
    if (keyElementIndex >= (uint32)CRYPTO_NUMBER_OF_KEY_ELEMENTS) {
        return NULL_PTR;
    }

    return Crypto_KeyElementList[keyElementIndex];
}


uint32 SecuUtils_GetKeyHandle(uint32 key_id) {
    Crypto_KeyElementType *keyMaterial = Secu_GetKeyMaterialElement(key_id);

    if (keyMaterial == NULL_PTR) {
        return HSM_INVALID_KEY_HANDLE;
    }

    return keyMaterial->u32HsmKeyHandle;
}


/**
 * Perform HSM DevAuth. Required when using NvM key.
 */
static Std_ReturnType SecuUtils_PerformHsmAuth(void) {
    uint8 cmacResult[16];
    uint8 challenge[32];
    uint32 cmacResultLen = sizeof(cmacResult);
    hsmAuthScheme_t authScheme;
    status_t status;
    Std_ReturnType retVal;
    hsmKeyInfo_t keyInfo = { 0 };

    authScheme.macScheme.macAlgo = HSM_MAC_ALGO_CMAC;

    status = HSM_LLD_GetKeyInfo(SECU_AUTH_KEY_HANDLE, &keyInfo);
    
    if ((status == STATUS_SUCCESS) && ((uint32)keyInfo.keyBitLen != 0UL)) {
        /* HSM_DEV_AUTH_ALL ORs hsmDevAuthOption_t (unsigned char) values -> integral promotion. */
        retVal = Crypto_AutoSar_Ext_DevAuthReq(SECU_AUTH_KEY_HANDLE, HSM_DEV_AUTH_ALL, &authScheme, challenge); /* PRQA S 2100 */
    } else {
        retVal = CRYPTO_E_KEY_EMPTY;
    }

    if (retVal == E_OK) {
        retVal = Secu_KeyElementSet(SECU_KEY_ID_AUTH_RAM, SECU_KE_CIPHER_KEY, HSM_Internal_KEY_AUTH, sizeof(HSM_Internal_KEY_AUTH));
    }

    if (retVal == E_OK) {
        retVal = SecuAuth_Calculate_AesCmacGenerate(
            SECU_KEY_ID_AUTH_RAM,
            SECU_OPERATIONMODE_SINGLECALL,
            challenge,
            sizeof(challenge),
            cmacResult,
            &cmacResultLen
        ); 
    }

    if (retVal == E_OK) {
        (void)Crypto_AutoSar_Ext_DevAuthResp(cmacResult, 16U, NULL_PTR, 0U);
    }        

    return retVal;
}


static void Secu_SyncNvmKeyValidity(void)
{
    uint32 keyIndex;
    Crypto_KeyElementType *keyMaterial;
    hsmKeyInfo_t keyInfo;
    status_t status;

    for (keyIndex = 0U; keyIndex < CRYPTO_NUMBER_OF_KEYS; keyIndex++) {
        keyMaterial = Secu_GetKeyMaterialElement(Crypto_KeyList[keyIndex]->u32Crypto_KeyId);

        if ((keyMaterial != NULL_PTR) &&
            (keyMaterial->u32HsmKeyHandle != HSM_INVALID_KEY_HANDLE) &&
            (GET_CATALOG_ID(keyMaterial->u32HsmKeyHandle) == HSM_KEY_CATALOG_ID_NVM) &&
            (keyMaterial->u16HsmKeyType != HSM_KEY_TYPE_NOT_SET)) {
            keyInfo.keyBitLen = 0U;

            status = HSM_LLD_GetKeyInfo(keyMaterial->u32HsmKeyHandle, &keyInfo);
            if ((status == STATUS_SUCCESS) &&
                (keyInfo.keyBitLen != 0UL) &&
                (keyInfo.keyType == keyMaterial->u16HsmKeyType) &&
                (keyInfo.keyBitLen == keyMaterial->u32HsmKeyBits)) {
                (void)Crypto_KeySetValid(Crypto_KeyList[keyIndex]->u32Crypto_KeyId);
            }
        }
    }
}


static boolean Secu_IsHsmEnabled(void)
{
    boolean isEnabled = FALSE;

    /* SSCM is a device-header register macro (CCFC3012PT.h) that casts an integer
       literal to a pointer to volatile; the cast is inherent to memory-mapped
       register access and cannot be removed. */
    if ((uint32)SSCM.UOPS.B.HSE == 1UL) { /* PRQA S 0303 */
        if ((uint32)SSCM.HSA.B.HADR != 0UL) { /* PRQA S 0303 */
            isEnabled = TRUE;
        } else {
            /* Do nothing */
        }
    } else {
        /* Do nothing */
    }

    return isEnabled;
}


void SecuAlgo_Init(void)
{
    Std_ReturnType authResult;
    const boolean isHsmEnabled = Secu_IsHsmEnabled();

    if ((uint32)isHsmEnabled != (uint32)FALSE) {
        Crypto_Init(NULL_PTR);
        (void)HSM_LLD_SetParam(&Flash_Lock, 1UL);

        authResult = SecuUtils_PerformHsmAuth();
        if ((uint32)E_OK == (uint32)authResult) {
            Secu_SyncNvmKeyValidity();
        }
    }
}

static Std_ReturnType Secu_CheckKeyValid
(
    uint32 cryptoKeyId,
    hsmKeyGroupIdx_t expectedKeyGroup
)
{
    uint32 keyHandle = SecuUtils_GetKeyHandle(cryptoKeyId);
    Std_ReturnType retVal = (Std_ReturnType)CRYPTO_E_KEY_NOT_VALID;

    if ((keyHandle != HSM_INVALID_KEY_HANDLE) &&
        (GET_GROUP_IDX(keyHandle) == expectedKeyGroup)) {
        retVal = (Std_ReturnType)E_OK;
    }

    return retVal;
}


static hsmCipherBlockMode_t Secu_GetSymCipherMode(Secu_SymAlgorithmType algo) {
    hsmCipherBlockMode_t mode = HSM_CIPHER_BLOCK_MODE_NULL;

    switch (algo) {
    case SECU_SYM_AES128_CBC:
    case SECU_SYM_SM4_CBC:
        mode = HSM_CIPHER_BLOCK_MODE_CBC;
        break;

    case SECU_SYM_AES128_ECB:
    case SECU_SYM_SM4_ECB:
        mode = HSM_CIPHER_BLOCK_MODE_ECB;
        break;

    default:
        mode = HSM_CIPHER_BLOCK_MODE_NULL;
        break;
    }

    return mode;
}


static hsmOperationMode_t Secu_GetOptMode(Secu_OperationModeType eOptMode) {
    hsmOperationMode_t ret;

    switch (eOptMode) {
        case SECU_OPERATIONMODE_SINGLECALL:
            ret = HSM_OPERATION_MODE_SINGLE_CALL;
            break;

        case SECU_OPERATIONMODE_FINISH:
            ret = HSM_OPERATION_MODE_FINISH;
            break;
        
        default:
            ret = (hsmOperationMode_t)eOptMode;
	    break;
    }

    return ret;
}


extern Std_ReturnType Secu_KeyElementSet
(
    uint32 cryptoKeyId,
    Secu_KeyElementIdType keyElementId,
    const uint8 *keyPtr,
    uint32 keyLength
) {
    return Crypto_KeyElementSet(cryptoKeyId, (uint32) keyElementId, keyPtr, keyLength);
}


extern Std_ReturnType SecuAuth_RandomGenerate
(
	uint8 *outputPtr,
    uint32 outputLength   
)
{
	VAR(status_t,				AUTOMATIC) status          = STATUS_HSM_GENERAL_ERRPR;
    VAR(Std_ReturnType,         AUTOMATIC) retVal          = (Std_ReturnType)E_NOT_OK;

	status = HSM_LLD_GenerateTrngNum(outputPtr, outputLength); 
	retVal = Crypto_VerifyHsmResp(status);

    return retVal;
}


extern Std_ReturnType SecuAuth_Calculate_AesCmacGenerate
(
    uint32 cryptoKeyId,
	Secu_OperationModeType eOptMode,
    const uint8 *pInput,
    uint32 inputLen,
	uint8 *pOutput,
    uint32 *pOutputLen
)
{
    uint32 cryptoKeyMaterialElemIndex;  /* choose key    in CryptoKeyElement[] */
    uint8 cipherBlockMode;
    status_t status;
    Std_ReturnType retVal = E_OK;

    if((eOptMode==SECU_OPERATIONMODE_SINGLECALL) || (eOptMode==SECU_OPERATIONMODE_FINISH)) {
        if (pOutputLen != NULL_PTR) {
            if(*pOutputLen >= 16U) {
                *pOutputLen = 16U;
            } else {
                retVal = (Std_ReturnType)CRYPTO_E_SMALL_BUFFER;
            }
        } else {
            retVal = CRYPTO_E_PARAM_POINTER;
        }
    }

    if (E_OK == retVal) {
        retVal = Secu_CheckKeyValid(cryptoKeyId, HSM_KEY_GROUP_SYM);
    }

    if(E_OK == retVal)
    {
        cryptoKeyMaterialElemIndex = Crypto_SearchKeyElementIdIndex(cryptoKeyId, CRYPTO_KE_CIPHER_KEY);
        if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX != cryptoKeyMaterialElemIndex)
        {
            eOptMode = (Secu_OperationModeType)Secu_GetOptMode(eOptMode);
            status = HSM_LLD_AesCmacGenerate((Crypto_OperationModeType) eOptMode,
                                            Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
                                            pInput,
                                            inputLen,
                                            pOutput,
                                            pOutputLen);
            retVal = Crypto_VerifyHsmResp(status);
        }
        else
        {
            retVal = (Std_ReturnType)E_NOT_OK;
        }
    }

    return retVal;
}


extern Std_ReturnType SecuAuth_Calculate_AesCmacVerify
(
    uint32 cryptoKeyId,
	Secu_OperationModeType eOptMode,
    const uint8 *pInput,
    uint32 inputLen,
	const uint8 *pCmac,
	uint32 *pCmacLen,
	uint32 *pVerifyStatus
)
{
    uint32 cryptoKeyMaterialElemIndex;  /* choose key    in CryptoKeyElement[] */
    uint8 cipherBlockMode;
    status_t status;
    Std_ReturnType retVal = E_OK;

    retVal = Secu_CheckKeyValid(cryptoKeyId, HSM_KEY_GROUP_SYM);

    if(E_OK == retVal)
    {
        cryptoKeyMaterialElemIndex = Crypto_SearchKeyElementIdIndex(cryptoKeyId, CRYPTO_KE_CIPHER_KEY);
        if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX != cryptoKeyMaterialElemIndex)
        {
            eOptMode = (Secu_OperationModeType)Secu_GetOptMode(eOptMode);
            status = HSM_LLD_AesCmacVerify((Crypto_OperationModeType) eOptMode,
                                        Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
                                        pInput,         //pJob->jobPrimitiveInputOutput.inputPtr, 
                                        inputLen,
                                        pCmac,
                                        pCmacLen,
                                        pVerifyStatus);

            retVal = Crypto_VerifyHsmResp(status);
        }
    }

    return retVal;
}


extern Std_ReturnType SecuAuth_Calculate_SymmetricAlgorithm
(
    uint32 cryptoKeyId,
    Secu_SymAlgorithmType algorithm,
    Secu_DirectionType direction,
	Secu_OperationModeType eOptMode,
    const uint8 *pInput,
    uint32 inputLength, 
	uint8 *pOutput
)
{
    uint32 cryptoKeyMaterialElemIndex;  /* choose key    in CryptoKeyElement[] */
    uint32 cryptoIvElemIndex;            /* choose CBC IV in CryptoKeyElement[] */
    uint8 cipherBlockMode;
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pIV = NULL_PTR;
    status_t status;
    VAR(Std_ReturnType,AUTOMATIC) retVal = (Std_ReturnType)E_OK;

    retVal = Secu_CheckKeyValid(cryptoKeyId, HSM_KEY_GROUP_SYM);

    if(E_OK == retVal)
    {
        cryptoKeyMaterialElemIndex = Crypto_SearchKeyElementIdIndex(cryptoKeyId, CRYPTO_KE_CIPHER_KEY);
        if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX == cryptoKeyMaterialElemIndex)
        {
            retVal = (Std_ReturnType)CRYPTO_E_KEY_NOT_VALID;
        }
    }

    if(E_OK == retVal)
    {
        cipherBlockMode = Secu_GetSymCipherMode(algorithm);
        if (cipherBlockMode == HSM_CIPHER_BLOCK_MODE_NULL) {
            retVal = CRYPTO_E_INVALID_PARAM;
        } else {
            if (direction != SECU_DIR_ENCRYPT && direction != SECU_DIR_DECRYPT) {
                retVal = CRYPTO_E_INVALID_PARAM;
            }
        }
    }

    if(E_OK == retVal)
    {
        if(HSM_CIPHER_BLOCK_MODE_ECB != cipherBlockMode)
        {
            cryptoIvElemIndex = Crypto_SearchKeyElementIdIndex(cryptoKeyId, CRYPTO_KE_CIPHER_IV);
            if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX == cryptoIvElemIndex)
            {
                retVal = (Std_ReturnType)CRYPTO_E_KEY_NOT_VALID;
            } else {
                pIV = Crypto_KeyElementList[cryptoIvElemIndex]->pCrypto_ElementArray;
            }
        }
    }
    
    if(E_OK == retVal)
    {
        eOptMode = (Secu_OperationModeType)Secu_GetOptMode(eOptMode);

        if (algorithm == SECU_SYM_AES128_CBC ||
            algorithm == SECU_SYM_AES128_ECB
        ) {
            if (direction == SECU_DIR_ENCRYPT) {
                status = HSM_LLD_AesEncrypt((Crypto_OperationModeType) eOptMode,
                                        Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
                                        (hsmCipherBlockMode_t)cipherBlockMode,
                                        HSM_CIPHER_STREAM_BITS_NULL,
                                        pIV,
                                        inputLength,
                                        pInput,
                                        pOutput
                                        );
            } else {
                status = HSM_LLD_AesDecrypt((Crypto_OperationModeType) eOptMode,
                                        Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
                                        (hsmCipherBlockMode_t)cipherBlockMode,
                                        HSM_CIPHER_STREAM_BITS_NULL,
                                        pIV,
                                        inputLength,
                                        pInput,
                                        pOutput
                                        );
            }
            retVal = Crypto_VerifyHsmResp(status);
        } else if (
            algorithm == SECU_SYM_SM4_CBC ||
            algorithm == SECU_SYM_SM4_ECB
        ) {
            if (direction == SECU_DIR_ENCRYPT) {
                status = HSM_LLD_Sm4Encrypt((Crypto_OperationModeType) eOptMode,
                            Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
                            (hsmCipherBlockMode_t)cipherBlockMode,
                            HSM_CIPHER_STREAM_BITS_NULL,
                            pIV,
                            inputLength,
                            pInput,
                            pOutput
                            );
            } else {
                status = HSM_LLD_Sm4Decrypt((Crypto_OperationModeType) eOptMode,
                            Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
                            (hsmCipherBlockMode_t)cipherBlockMode,
                            HSM_CIPHER_STREAM_BITS_NULL,
                            pIV,
                            inputLength,
                            pInput,
                            pOutput
                            );
            }

            retVal = Crypto_VerifyHsmResp(status);
        } else {
            retVal = CRYPTO_E_INVALID_PARAM;
        }
    }

    return retVal;
}


Std_ReturnType SecuAuth_Calculate_SymmetricAEADEncrypt
(
    uint32 cryptoKeyId,
    const uint8 *plaintextPtr,
    uint32 plaintextLength,
    const uint8 *associatedDataPtr,
    uint32 associatedDataLength,
    uint8 *ciphertextPtr,
    uint32 *ciphertextLengthPtr,
    uint8 *tagPtr,
    uint32 *tagLengthPtr
)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    VAR(status_t, AUTOMATIC) status = STATUS_HSM_GENERAL_ERRPR;
    VAR(uint32, AUTOMATIC) cryptoKeyMaterialElemIndex;
    VAR(uint32, AUTOMATIC) cryptoIvElemIndex;
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pIV = NULL_PTR;
    VAR(uint32, AUTOMATIC) ivLength = 0;

    if (tagLengthPtr == NULL_PTR || ciphertextLengthPtr == NULL_PTR) {
        retVal = CRYPTO_E_INVALID_PARAM;
    }

    if (E_OK == retVal)
    {
        retVal = Secu_CheckKeyValid(cryptoKeyId, HSM_KEY_GROUP_SYM);
    }

    if (E_OK == retVal)
    {
        cryptoKeyMaterialElemIndex = Crypto_SearchKeyElementIdIndex(cryptoKeyId, CRYPTO_KE_CIPHER_KEY);
        if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX == cryptoKeyMaterialElemIndex)
        {
            retVal = (Std_ReturnType)CRYPTO_E_KEY_NOT_VALID;
        }
    }

    if (E_OK == retVal)
    {
        cryptoIvElemIndex = Crypto_SearchKeyElementIdIndex(cryptoKeyId, CRYPTO_KE_CIPHER_IV);
        if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX == cryptoIvElemIndex)
        {
            retVal = (Std_ReturnType)CRYPTO_E_KEY_NOT_VALID;
        }
        else
        {
            pIV = Crypto_KeyElementList[cryptoIvElemIndex]->pCrypto_ElementArray;
            ivLength = Crypto_KeyElementList[cryptoIvElemIndex]->u32Crypto_KeyElementActualSize;
        }
    }

    if (E_OK == retVal)
    {
        status = HSM_LLD_AesAeadEncrypt(
            (Crypto_OperationModeType) HSM_OPERATION_MODE_SINGLE_CALL,
            Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
            HSM_AUTH_CIPHER_MODE_GCM, /* Assuming GCM mode */
            pIV,
            ivLength,
            associatedDataPtr,
            associatedDataLength,
            plaintextPtr,
            plaintextLength,
            tagPtr,
            *tagLengthPtr,
            ciphertextPtr
        );

        retVal = Crypto_VerifyHsmResp(status);

        if (E_OK == retVal)
        {
            /* For GCM, ciphertext length is the same as plaintext length. */
            if (*ciphertextLengthPtr >= plaintextLength)
            {
                *ciphertextLengthPtr = plaintextLength;
            }
            else
            {
                retVal = (Std_ReturnType)CRYPTO_E_SMALL_BUFFER;
            }
        }
    }

    return retVal;
}


Std_ReturnType SecuAuth_Calculate_SymmetricAEADDecrypt
(
    uint32 cryptoKeyId,
    const uint8 *ciphertextPtr,
    uint32 ciphertextLength,
    const uint8 *associatedDataPtr,
    uint32 associatedDataLength,
    const uint8 *tagPtr,
    uint32 tagLength,
    uint8 *plaintextPtr,
    uint32 *plaintextLengthPtr,
    Secu_VerifyResultType *verifyPtr
)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    VAR(status_t, AUTOMATIC) status = STATUS_HSM_GENERAL_ERRPR;
    VAR(uint32, AUTOMATIC) cryptoKeyMaterialElemIndex;
    VAR(uint32, AUTOMATIC) cryptoIvElemIndex;
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pIV = NULL_PTR;
    VAR(uint32, AUTOMATIC) ivLength = 0;

    if (verifyPtr == NULL_PTR || plaintextLengthPtr == NULL_PTR) {
        retVal = CRYPTO_E_PARAM_POINTER;
    }

    if (E_OK == retVal) {
        /* Default verification status to not ok */
        *verifyPtr = SECU_E_VER_NOT_OK;

        retVal = Secu_CheckKeyValid(cryptoKeyId, HSM_KEY_GROUP_SYM);
    }

    if (E_OK == retVal)
    {
        cryptoKeyMaterialElemIndex = Crypto_SearchKeyElementIdIndex(cryptoKeyId, CRYPTO_KE_CIPHER_KEY);
        if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX == cryptoKeyMaterialElemIndex)
        {
            retVal = (Std_ReturnType)CRYPTO_E_KEY_NOT_VALID;
        }
    }

    if (E_OK == retVal)
    {
        cryptoIvElemIndex = Crypto_SearchKeyElementIdIndex(cryptoKeyId, CRYPTO_KE_CIPHER_IV);
        if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX == cryptoIvElemIndex)
        {
            retVal = (Std_ReturnType)CRYPTO_E_KEY_NOT_VALID;
        }
        else
        {
            pIV = Crypto_KeyElementList[cryptoIvElemIndex]->pCrypto_ElementArray;
            ivLength = Crypto_KeyElementList[cryptoIvElemIndex]->u32Crypto_KeyElementActualSize;
        }
    }

    if (E_OK == retVal)
    {
        status = HSM_LLD_AesAeadDecrypt(
            (Crypto_OperationModeType) HSM_OPERATION_MODE_SINGLE_CALL,
            Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
            HSM_AUTH_CIPHER_MODE_GCM, /* Assuming GCM mode */
            pIV,
            ivLength,
            associatedDataPtr,
            associatedDataLength,
            ciphertextPtr,
            ciphertextLength,
            tagPtr,
            tagLength,
            plaintextPtr
        );

        retVal = Crypto_VerifyHsmResp(status);

        if (E_OK == retVal)
        {
            /* HSM operation succeeded, which for decryption implies tag verification passed. */
            *verifyPtr = SECU_E_VER_OK;

            /* For GCM, plaintext length is the same as ciphertext length. */
            if (*plaintextLengthPtr >= ciphertextLength)
            {
                *plaintextLengthPtr = ciphertextLength;
            }
            else
            {
                retVal = (Std_ReturnType)CRYPTO_E_SMALL_BUFFER;
                /* Even if buffer is small, verification was ok. Caller should see the error. */
            }
        }
        /* If retVal is not E_OK, it means HSM returned an error (e.g. auth failed, key invalid).
           verifyPtr is already set to CRYPTO_E_VER_NOT_OK. */
    }

    return retVal;
}



extern Std_ReturnType SecuAuth_Calculate_HashAlgorithm
(
    Secu_AlgorithmFamilyType hashAlgorithm,
	Secu_OperationModeType eOptMode,
    const uint8 *pInput,
    uint32 inputLength, 
	uint8 *pOutput,
    uint32 *outputLengthPtr
)
{
    VAR(status_t,				CRYPTO_VAR) resp            = STATUS_HSM_GENERAL_ERRPR;
    VAR(Std_ReturnType,         CRYPTO_VAR) retVal          = (Std_ReturnType)E_OK;
    uint32 u32ResLen =0;
    hsmHashAlgo_t hashAlgo;

    if(SECU_ALGOFAM_SHA2_512 == hashAlgorithm)
    {
        hashAlgo = HSM_HASH_ALGO_SHA2_512;
        u32ResLen = 64U;
    }
    else if(SECU_ALGOFAM_SHA2_256 == hashAlgorithm)
    {
        hashAlgo = HSM_HASH_ALGO_SHA2_256;
        u32ResLen = 32U;
    }
    else if (SECU_ALGOFAM_SM3 == hashAlgorithm) {
        hashAlgo = HSM_HASH_ALGO_SM3;
        u32ResLen = 32U;
    }
    else
    {
        retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
    }

    if((eOptMode==SECU_OPERATIONMODE_SINGLECALL) || (eOptMode==SECU_OPERATIONMODE_FINISH))
    {
        if ((Std_ReturnType)E_OK == retVal)
        {
            if (outputLengthPtr != NULL_PTR) {
                if(*outputLengthPtr>=u32ResLen)
                {
                    *outputLengthPtr=u32ResLen;
                }
            } else {
                retVal = CRYPTO_E_PARAM_POINTER;
            }
        }
    }

    if ((Std_ReturnType)E_OK == retVal)
    {
        eOptMode = (Secu_OperationModeType)Secu_GetOptMode(eOptMode);
        resp = HSM_LLD_Hash((Crypto_OperationModeType) eOptMode, hashAlgo, pInput, inputLength, pOutput, outputLengthPtr);
        retVal = Crypto_VerifyHsmResp(resp);
    }
    return retVal;
}


extern Std_ReturnType SecuAuth_Calculate_SignatureVerify
(
   uint32 cryptoKeyId,
   Secu_AsymAlgorithmType algorithm,
   const uint8 *inputPtr,  
   uint32 inputLength,
   boolean inputHashed,
   const uint8 *signaturePtr,
   uint32 signatureLength,
   Secu_VerifyResultType *verifyPtr
)
{
	//VAR(boolean,				    AUTOMATIC) verifyStatus	     = FALSE;
	VAR(status_t,		  			AUTOMATIC) status            = STATUS_HSM_GENERAL_ERRPR;
    VAR(Std_ReturnType,           	AUTOMATIC) retVal            = (Std_ReturnType)E_OK;
    VAR(hsmHashAlgo_t,				AUTOMATIC) hashAlgo;
    VAR(uint32,				    	AUTOMATIC) cryptoKeyMaterialElemIndex;
    VAR(Crypto_AlgorithmFamilyType, AUTOMATIC) algoFam;

    VAR(static uint32,						ATUOMATIC) signRLen;
    VAR(static uint32,						ATUOMATIC) signSLen;

    retVal = Secu_CheckKeyValid(cryptoKeyId, HSM_KEY_GROUP_ASYM);

    if(E_OK == retVal)
    {
        cryptoKeyMaterialElemIndex = Crypto_SearchKeyElementIdIndex(cryptoKeyId, CRYPTO_KE_CIPHER_KEY);
        if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX == cryptoKeyMaterialElemIndex)
        {
            retVal = (Std_ReturnType)CRYPTO_E_KEY_NOT_VALID;
        }
    }

    if(algorithm == SECU_ASYM_ECC256_SHA256)
    {
       hashAlgo = HSM_HASH_ALGO_SHA2_256;
       algoFam  = CRYPTO_ALGOFAM_ECDSA;
    }
    else if(algorithm == SECU_ASYM_RSA3072_SHA256)
    {
       hashAlgo = HSM_HASH_ALGO_SHA2_256;
       algoFam  = CRYPTO_ALGOFAM_RSA; 
    }
    else if(algorithm == SECU_ASYM_RSA4096_SHA512)
    {
       hashAlgo = HSM_HASH_ALGO_SHA2_512;
       algoFam  = CRYPTO_ALGOFAM_RSA;
    }
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
    else if(algorithm == SECU_ASYM_SM2_SM3)
    {
       hashAlgo = HSM_HASH_ALGO_SM3;
       algoFam  = CRYPTO_ALGOFAM_SM2; 
    }
#endif    
    else if(algorithm == SECU_ASYM_ED25519_SHA256)
    {
       hashAlgo = HSM_HASH_ALGO_SHA2_256;
       algoFam  = CRYPTO_ALGOFAM_ED25519;
    }
    else if(algorithm == SECU_ASYM_ECDSA384_SHA512)
    {
       hashAlgo = HSM_HASH_ALGO_SHA2_512;
       algoFam  = CRYPTO_ALGOFAM_ECDSA;
    }
    else
    {
       retVal = (Std_ReturnType)CRYPTO_E_INVALID_PARAM;
    }

    if ((Std_ReturnType)E_OK == retVal)
    {
        if(algoFam  == CRYPTO_ALGOFAM_RSA)
        {
            status = HSM_LLD_RsaPkcs1V15VerifySignature(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
                                                        hashAlgo,
                                                        inputPtr,
                                                        inputLength,
                                                        inputHashed,
                                                        signaturePtr,
                                                        (uint32 *)&signatureLength,
                                                        (uint32*)verifyPtr); /* PRQA S 0310 */
            retVal = Crypto_VerifyHsmResp(status);

        }
        else if(algoFam  == CRYPTO_ALGOFAM_SM2)
        {
            signRLen = signatureLength >> 1U; 
			signSLen = signatureLength >> 1U;

            status = HSM_LLD_Sm2VerifySignature(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
                                                inputPtr,
                                                inputLength,
                                                inputHashed,
                                                &signaturePtr[0],
                                                &signRLen,
                                                &signaturePtr[signatureLength >> 1U],
                                                &signSLen,
                                                (uint32*)verifyPtr); /* PRQA S 0310 */
            retVal = Crypto_VerifyHsmResp(status);
        }
        else if(algoFam  == CRYPTO_ALGOFAM_ECDSA)
        {
            signRLen = signatureLength >> 1U; 
			signSLen = signatureLength >> 1U;

            status = HSM_LLD_EcdsaVerifySignature(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
                                                  hashAlgo,
                                                  inputPtr,
                                                  inputLength,
                                                  inputHashed,
                                                  &signaturePtr[0],
                                                  &signRLen,
                                                  &signaturePtr[signatureLength >> 1U],
                                                  &signSLen,
                                                  (uint32*)verifyPtr); /* PRQA S 0310 */
            retVal = Crypto_VerifyHsmResp(status);
        }
        else /* Only CRYPTO_ALGOFAM_ED25519 remains here: RSA/SM2/ECDSA excluded above */
        {
            signRLen = signatureLength >> 1U;
            signSLen = signatureLength >> 1U;

            status = HSM_LLD_ED25519VerifySignature(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
                                                    hashAlgo,
                                                    inputPtr,
                                                    inputLength,
                                                    inputHashed,
                                                    signaturePtr,
                                                    &signRLen,
                                                    &signaturePtr[signatureLength >> 1U],
                                                    &signSLen,
                                                    (uint32*)verifyPtr); /* PRQA S 0310 */
            retVal = Crypto_VerifyHsmResp(status);
        }
    }
    return retVal;
}
