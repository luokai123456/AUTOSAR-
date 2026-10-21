/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : Crypto
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     :
*   Autosar Conf.Variant :
*   SW Version           :
*   Build Version        :
*
*****************************************************************************/

/**
*   @file    Crypto_HAL_Wrapper.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Crypto MCAL driver.
*
*   @addtogroup Crypto
*   @{
*/

/*
 * QAC violations
 *
 * @ID:rcma-4.0.0-1505 Rule:M3CM Rule-8.7
 * The function '%1s' is only referenced in the translation unit where it is defined.
 *
 * @ID:dataflow-1.0.0-2919 Rule:Dataflow 5.7
 * Possible: Storing the address of an object in a pointer that has greater lifetime.
 */

/* PRQA S 1505, 2919, 0380, 3432, 2844, 0491, 1881, 2991, 2955 EOF */
/* PRQA S 1258, 2052, 2004, 3305, 0310, 0311, 2982 EOF */
#ifdef __cplusplus
extern "C"{
#endif

#include "Crypto.h"
#include "Crypto_HAL_Wrapper.h"
#include "Crypto_LLDriver.h"
#include "Crypto_Common.h"

#define CRYPTO_START_SEC_VAR_NO_INIT
#include "Crypto_MemMap.h"
static VAR(Crypto_JobStateType, CRYPTO_VAR) eCrypto_CurrentJobState;
#define CRYPTO_STOP_SEC_VAR_NO_INIT
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_NO_INIT
#include "Crypto_MemMap.h"
static P2CONST(Crypto_JobType, CRYPTO_VAR, CRYPTO_APPL_CONST) pCrypto_JobInProgress;	/* PRQA S 1527 */
#define CRYPTO_STOP_SEC_VAR_NO_INIT
#include "Crypto_MemMap.h"

extern P2VAR(Crypto_ObjectType, CRYPTO_VAR, CRYPTO_APPL_DATA) pCrypto_ObjectJobList[CRYPTO_NUMBER_OF_DRIVER_OBJECTS];

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_Wrapper_ProcessOperation
(
	P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
)
{
    VAR (Std_ReturnType, CRYPTO_VAR) retVal = E_NOT_OK;

    if (CRYPTO_JOBSTATE_IDLE == eCrypto_CurrentJobState)
    {
        pCrypto_JobInProgress = pJob;
        eCrypto_CurrentJobState = CRYPTO_JOBSTATE_ACTIVE;

        switch (pJob->jobPrimitiveInfo->primitiveInfo->service)/* polyspace RTE:NIV,NIP,COR,IDP */ 
        {
            case CRYPTO_HASH:
                retVal = Crypto_Wrapper_Hash(pJob);
                break;

            case CRYPTO_RANDOMGENERATE:
            	retVal = Crypto_Wrapper_RandomGenerate(pJob);
            	break;

            case CRYPTO_MACGENERATE:
            	retVal = Crypto_Wrapper_MacGenerate(pJob);
            	break;

            case CRYPTO_MACVERIFY:
            	retVal = Crypto_Wrapper_MacVerify(pJob);
            	break;

            case CRYPTO_ENCRYPT:
            	retVal = Crypto_Wrapper_Encrypt(pJob);
            	break;

            case CRYPTO_DECRYPT:
             	retVal = Crypto_Wrapper_Decrypt(pJob);
             	break;

            case CRYPTO_AEADENCRYPT:
            	retVal = Crypto_Wrapper_AeadEncrypt(pJob);
            	break;

            case CRYPTO_AEADDECRYPT:
            	retVal = Crypto_Wrapper_AeadDecrypt(pJob);
            	break;

            case CRYPTO_SIGNATUREGENERATE:
            	retVal = Crypto_Wrapper_SignatureGenerate(pJob);
            	break;

            case CRYPTO_SIGNATUREVERIFY:
            	retVal = Crypto_Wrapper_SignatureVerify(pJob);
            	break;

            default:
                /*Do nothing*/
                break;
        }
        eCrypto_CurrentJobState = CRYPTO_JOBSTATE_IDLE;
    }
    else
    {
        retVal = (Std_ReturnType)CRYPTO_E_BUSY;
    }

    CryIf_CallbackNotification(pJob, retVal);
    return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_Wrapper_DequeueJob
(
    VAR(uint32, CRYPTO_VAR) u32ObjectIdx,
	P2VAR(Crypto_JobInfoType, AUTOMATIC, CRYPTO_APPL_DATA) pJobInfo
)
{
	VAR  (Std_ReturnType, CRYPTO_VAR) eRetVal = (Std_ReturnType)E_NOT_OK;
	VAR(uint32,CRYPTO_VAR) u32QueueNumber = 0;
	VAR(uint32,CRYPTO_VAR) u32QueueJobNumber = 0 ;
	VAR(boolean,CRYPTO_VAR)bJobAlreadyQueued = (boolean)FALSE;
	for(u32QueueNumber = 0U; ((u32QueueNumber < pCrypto_ObjectJobList[u32ObjectIdx]->u32Crypto_QueueSize)&&((boolean)FALSE == bJobAlreadyQueued)); u32QueueNumber++)/* polyspace RTE:OBAI */
	{
		if (NULL_PTR != pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[u32QueueNumber].pJob)/* polyspace RTE:IDP,NIP */
		{
			if ( pJobInfo->jobId == pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[u32QueueNumber].pJob->jobId)/* polyspace RTE:NIV,COR,IDP */
			{
				bJobAlreadyQueued = (boolean)TRUE;
				u32QueueJobNumber = u32QueueNumber;
				for(u32QueueJobNumber = u32QueueNumber; u32QueueJobNumber < (pCrypto_ObjectJobList[u32ObjectIdx]->u32Crypto_QueueSize - 1UL); u32QueueJobNumber++)
				{
					pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[u32QueueJobNumber].pJob = pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[u32QueueJobNumber+1UL].pJob;/* polyspace RTE:COR,IDP,NIP */
					pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[pCrypto_ObjectJobList[u32ObjectIdx]->u32Crypto_QueueSize - 1UL].pJob = NULL_PTR;/* polyspace RTE:COR,IDP */
					pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[pCrypto_ObjectJobList[u32ObjectIdx]->u32Crypto_QueueSize - 1UL].bCrypto_JobValid = (boolean)FALSE;/* polyspace RTE:COR,IDP */
				}
				eRetVal = (Std_ReturnType)E_OK;
			}
		}
	}
	return eRetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_Wrapper_CancelJob
(
    VAR(uint32, CRYPTO_VAR) ObjectIdx,
	P2VAR(Crypto_JobInfoType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
)
{
    VAR(Std_ReturnType, CRYPTO_VAR) u8RetVal;

    if ((CRYPTO_JOBSTATE_ACTIVE == eCrypto_CurrentJobState) && (pJob->jobId == pCrypto_JobInProgress->jobInfo->jobId))
    {
        u8RetVal = (Std_ReturnType)CRYPTO_E_JOB_CANCELED;
    }
    else
    {
        u8RetVal = Crypto_Wrapper_DequeueJob(ObjectIdx, pJob);
    }

    return u8RetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_Init
(
	P2CONST(Crypto_ConfigType, CRYPTO_CONST, CRYPTO_APPL_CONST) pCrypto_ConfigPtr
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;

	(void)pCrypto_ConfigPtr;

	status = HSM_LLD_Init();
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_Hash
(
	P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
)
{
	VAR(status_t,				CRYPTO_VAR) resp            = STATUS_HSM_GENERAL_ERRPR;
	VAR(hsmHashAlgo_t,			CRYPTO_VAR) hashAlgo		= HSM_HASH_ALGO_NOT_SET;
    VAR(Std_ReturnType,         CRYPTO_VAR) retVal          = (Std_ReturnType)E_OK;
    VAR(Crypto_ProcessingType,  CRYPTO_VAR) eProcessingType = pJob->jobPrimitiveInfo->processingType;/* polyspace RTE:NIV */ 
    VAR (Crypto_OperationModeType, CRYPTO_VAR) eOptMode = pJob->jobPrimitiveInputOutput.mode;/* polyspace RTE:NIV */

    VAR(uint32,                 CRYPTO_VAR) u32OutputLen    = 0UL;


    switch (pJob->jobPrimitiveInfo->primitiveInfo->algorithm.family)/* polyspace RTE:NIV */ 
    {
		case CRYPTO_ALGOFAM_SHA1:
			hashAlgo = HSM_HASH_ALGO_SHA1;
			//u32ResLen = 20U;
			break;
		case CRYPTO_ALGOFAM_RIPEMD160:
			hashAlgo = HSM_HASH_ALGO_RIPEMD160;
			//u32ResLen = 20U;
			break;
		case CRYPTO_ALGOFAM_SHA2_224:
			hashAlgo = HSM_HASH_ALGO_SHA2_224;
			//u32ResLen = 28U;
			break;
		case CRYPTO_ALGOFAM_SHA3_224:
			hashAlgo = HSM_HASH_ALGO_SHA3_224;
			//u32ResLen = 28U;
			break;
		case CRYPTO_ALGOFAM_SHA2_256:
			hashAlgo = HSM_HASH_ALGO_SHA2_256;
			//u32ResLen = 32U;
			break;
		case CRYPTO_ALGOFAM_SHA3_256:
			hashAlgo = HSM_HASH_ALGO_SHA3_256;
			//u32ResLen = 32U;
			break;
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
		case CRYPTO_ALGOFAM_SM3:
			hashAlgo = HSM_HASH_ALGO_SM3;
			//u32ResLen = 32U;
			break;
#endif
		case CRYPTO_ALGOFAM_SHA2_384:
			hashAlgo = HSM_HASH_ALGO_SHA2_384;
			//u32ResLen = 48U;
			break;
		case CRYPTO_ALGOFAM_SHA3_384:
			hashAlgo = HSM_HASH_ALGO_SHA3_384;
			//u32ResLen = 48U;
			break;
		case CRYPTO_ALGOFAM_SHA2_512:
			hashAlgo = HSM_HASH_ALGO_SHA2_512;
			//u32ResLen = 64U;
			break;
		case CRYPTO_ALGOFAM_SHA3_512:
			hashAlgo = HSM_HASH_ALGO_SHA3_512;
			//u32ResLen = 64U;
			break;
		default:
			retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
			break;
    }
#if 0
    if((eOptMode==CRYPTO_OPERATIONMODE_SINGLECALL) || (eOptMode==CRYPTO_OPERATIONMODE_FINISH))
    {
        if ((Std_ReturnType)E_OK == retVal)
        {
        	if (*pJob->jobPrimitiveInputOutput.outputLengthPtr >= u32ResLen)
        	{
        		*pJob->jobPrimitiveInputOutput.outputLengthPtr = u32ResLen;
        	}
        	else
        	{
        		retVal = (Std_ReturnType)CRYPTO_E_SMALL_BUFFER;
        	}
        }

    }
#endif

    if((eOptMode==CRYPTO_OPERATIONMODE_SINGLECALL) || (eOptMode==CRYPTO_OPERATIONMODE_FINISH))
    {
          if ((Std_ReturnType)E_OK == retVal)
          {
        	    u32OutputLen = *pJob->jobPrimitiveInputOutput.outputLengthPtr;/* polyspace RTE:NIV *//* polyspace RTE:NIP *//* polyspace RTE:IDP */

        	    u32OutputLen = (uint32)(u32OutputLen |(uint32)0xA55AA500UL);

        	    *pJob->jobPrimitiveInputOutput.outputLengthPtr = u32OutputLen;
          }
     }

    if(eOptMode==CRYPTO_OPERATIONMODE_SINGLECALL)
    {

    	eOptMode= (Crypto_OperationModeType)HSM_OPERATION_MODE_SINGLE_CALL;	/* PRQA S 4342 */

    }

    if(eOptMode==CRYPTO_OPERATIONMODE_FINISH)
    {

    	eOptMode= (Crypto_OperationModeType)HSM_OPERATION_MODE_FINISH;		/* PRQA S 4342 */

    }

    if ((Std_ReturnType)E_OK == retVal)
    {
    	if (CRYPTO_PROCESSING_SYNC == eProcessingType)
    	{
    		resp = HSM_LLD_Hash(eOptMode,hashAlgo,
								pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */ 
								pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */ 
								pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */ 
								pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIP */ 
    	}else if((uint16_t)CRYPTO_PROCESSING_ASYNC_POLLING_MODE == (uint16_t)eProcessingType)
    	{
    		resp = HSM_LLD_Hash_Async(eOptMode,hashAlgo,
								pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
								pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
								pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */
								pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIP */

    	}else
        {
            /* do nothing */
        }
    	retVal = Crypto_VerifyHsmResp(resp);
    }

    return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_RandomGenerate
(
	P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
)
{
	VAR(status_t,				AUTOMATIC) status          = STATUS_HSM_GENERAL_ERRPR;
    VAR(Std_ReturnType,         AUTOMATIC) retVal          = (Std_ReturnType)E_NOT_OK;
    VAR(Crypto_ProcessingType,  AUTOMATIC) eProcessingType = pJob->jobPrimitiveInfo->processingType;/* polyspace RTE:NIV */ 
    VAR(Crypto_AlgorithmModeType,  AUTOMATIC) emode =pJob->jobPrimitiveInfo->primitiveInfo->algorithm.mode;/* polyspace RTE:NIV */

	if (CRYPTO_PROCESSING_SYNC == eProcessingType)
	{
		if (emode == CRYPTO_ALGOMODE_NOT_SET)
		{
			status = HSM_LLD_GenerateTrngNum(pJob->jobPrimitiveInputOutput.outputPtr, *pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIV,NIP,COR,IDP */
			retVal = Crypto_VerifyHsmResp(status);

		}
		else
		{
			retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
		}
	}
	else
	{
		retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
	}

    return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_ImportPlainSymKey
(
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pKey,
	VAR(uint32, AUTOMATIC) u32KeyLength,
	VAR(uint32, AUTOMATIC) u32KeyMaterialKeyElemIdx
)
{
	VAR(uint32, AUTOMATIC) hImportKey = Crypto_KeyElementList[u32KeyMaterialKeyElemIdx]->u32HsmKeyHandle;
	VAR(uint16, AUTOMATIC) keyType = Crypto_KeyElementList[u32KeyMaterialKeyElemIdx]->u16HsmKeyType;
	VAR(uint16, AUTOMATIC) keyFlags = Crypto_KeyElementList[u32KeyMaterialKeyElemIdx]->u16HsmKeyFlags;
	VAR(status_t, AUTOMATIC) status = STATUS_HSM_GENERAL_ERRPR;
	VAR(Std_ReturnType, AUTOMAITC) retVal = (Std_ReturnType)E_NOT_OK;

	status = HSM_LLD_ImportPlainSymKey((hsmKeyHandle_t) hImportKey,
									   (hsmKeyType_t) keyType,
									   (hsmKeyFlags_t) keyFlags,
									   (uint16) u32KeyLength,
									   pKey);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_ImportPlainSm2Key
(
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pKey,
	VAR(uint32, AUTOMATIC) u32KeyMaterialKeyElemIdx
)
{
	VAR(uint32, AUTOMATIC) hImportKey = Crypto_KeyElementList[u32KeyMaterialKeyElemIdx]->u32HsmKeyHandle;
	VAR(uint16, AUTOMATIC) keyType = Crypto_KeyElementList[u32KeyMaterialKeyElemIdx]->u16HsmKeyType;
	VAR(uint16, AUTOMATIC) keyFlags = Crypto_KeyElementList[u32KeyMaterialKeyElemIdx]->u16HsmKeyFlags;
	VAR(uint16, AUTOMATIC) keyBitLen = (uint16)Crypto_KeyElementList[u32KeyMaterialKeyElemIdx]->u32HsmKeyBits;
	VAR(status_t, AUTOMATIC) status = STATUS_HSM_GENERAL_ERRPR;
	VAR(Std_ReturnType, AUTOMAITC) retVal = (Std_ReturnType)E_NOT_OK;
	P2VAR(Crypto_HSM_KeyImportExportType, AUTOMATIC, CRYPTO_APPL_CONST) pImportKeyCustomStruct = (Crypto_HSM_KeyImportExportType *)pKey;

	status = HSM_LLD_ImportPlainSm2Key((hsmKeyHandle_t) hImportKey,
									   (hsmKeyType_t) keyType,
									   (hsmKeyFlags_t) keyFlags,
									   (hsmKeyBits_t)keyBitLen,
									   (uint8 *)pImportKeyCustomStruct->pKey[0],/* polyspace RTE:COR,IDP */
									   (uint8 *)pImportKeyCustomStruct->pKey[2]);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_ImportPlainEccKey
(
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pKey,
	VAR(uint32, AUTOMATIC) u32KeyMaterialKeyElemIdx
)
{
	VAR(uint32, AUTOMATIC) hImportKey = Crypto_KeyElementList[u32KeyMaterialKeyElemIdx]->u32HsmKeyHandle;
	VAR(uint16, AUTOMATIC) keyType = Crypto_KeyElementList[u32KeyMaterialKeyElemIdx]->u16HsmKeyType;
	VAR(uint16, AUTOMATIC) keyFlags = Crypto_KeyElementList[u32KeyMaterialKeyElemIdx]->u16HsmKeyFlags;
	VAR(uint16, AUTOMATIC) keyBitLen = (uint16)Crypto_KeyElementList[u32KeyMaterialKeyElemIdx]->u32HsmKeyBits;
	VAR(uint8, AUTOMATIC) eccCurveId = Crypto_KeyElementList[u32KeyMaterialKeyElemIdx]->u8HsmEccCurveId;
	VAR(status_t, AUTOMATIC) status = STATUS_HSM_GENERAL_ERRPR;
	VAR(Std_ReturnType, AUTOMAITC) retVal = (Std_ReturnType)E_NOT_OK;
	P2VAR(Crypto_HSM_KeyImportExportType, AUTOMATIC, CRYPTO_APPL_CONST) pImportKeyCustomStruct = (Crypto_HSM_KeyImportExportType *)pKey;

	status = HSM_LLD_ImportPlainEccKey((hsmKeyHandle_t) hImportKey,
									   (hsmKeyType_t) keyType,
									   (hsmKeyFlags_t) keyFlags,
									   (hsmEccCurveId_t)eccCurveId,
									   (hsmKeyBits_t)keyBitLen,
									   (uint8 *)pImportKeyCustomStruct->pKey[0],/* polyspace RTE:COR,IDP */
									   (uint8 *)pImportKeyCustomStruct->pKey[2]);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#if defined(RESOURCE_SUPPORT_CRYPTO_EB4)
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_ImportPlainED25519Key
(
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pKey,
	VAR(uint32, AUTOMATIC) u32KeyMaterialKeyElemIdx
)
{
	VAR(uint32, AUTOMATIC) hImportKey = Crypto_KeyElementList[u32KeyMaterialKeyElemIdx]->u32HsmKeyHandle;
	VAR(uint16, AUTOMATIC) keyType = Crypto_KeyElementList[u32KeyMaterialKeyElemIdx]->u16HsmKeyType;
	VAR(uint16, AUTOMATIC) keyFlags = Crypto_KeyElementList[u32KeyMaterialKeyElemIdx]->u16HsmKeyFlags;
	VAR(uint16, AUTOMATIC) keyBitLen = (uint16)Crypto_KeyElementList[u32KeyMaterialKeyElemIdx]->u32HsmKeyBits;
	VAR(status_t, AUTOMATIC) status = STATUS_HSM_GENERAL_ERRPR;
	VAR(Std_ReturnType, AUTOMAITC) retVal = (Std_ReturnType)E_NOT_OK;
	P2VAR(Crypto_HSM_KeyImportExportType, AUTOMATIC, CRYPTO_APPL_CONST) pImportKeyCustomStruct = (Crypto_HSM_KeyImportExportType *)pKey;

	status = HSM_LLD_ImportPlainED25519Key((hsmKeyHandle_t) hImportKey,
									   (hsmKeyType_t) keyType,
									   (hsmKeyFlags_t) keyFlags,
									   (hsmKeyBits_t)keyBitLen,
									   (uint8 *)pImportKeyCustomStruct->pKey[0],/* polyspace RTE:COR,IDP */
									   (uint8 *)pImportKeyCustomStruct->pKey[2]);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_ImportPlainRsaKey
(
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pKey,
	VAR(uint32, AUTOMATIC) u32KeyMaterialKeyElemIdx
)
{
	VAR(uint32, AUTOMATIC) hImportKey = Crypto_KeyElementList[u32KeyMaterialKeyElemIdx]->u32HsmKeyHandle;
	VAR(uint16, AUTOMATIC) keyType = Crypto_KeyElementList[u32KeyMaterialKeyElemIdx]->u16HsmKeyType;
	VAR(uint16, AUTOMATIC) keyFlags = Crypto_KeyElementList[u32KeyMaterialKeyElemIdx]->u16HsmKeyFlags;
	VAR(uint16, AUTOMATIC) keyBitLen = (uint16)Crypto_KeyElementList[u32KeyMaterialKeyElemIdx]->u32HsmKeyBits;
	VAR(status_t, AUTOMATIC) status = STATUS_HSM_GENERAL_ERRPR;
	VAR(Std_ReturnType, AUTOMAITC) retVal = (Std_ReturnType)E_NOT_OK;
	P2VAR(Crypto_HSM_KeyImportExportType, AUTOMATIC, CRYPTO_APPL_CONST) pImportKeyCustomStruct = (Crypto_HSM_KeyImportExportType *)pKey;

	status = HSM_LLD_ImportPlainRsaKey((hsmKeyHandle_t) hImportKey,
									   (hsmKeyType_t) keyType,
									   (hsmKeyFlags_t) keyFlags,
									   (hsmKeyBits_t)keyBitLen,
									   (uint8 *)pImportKeyCustomStruct->pKey[0],/* polyspace RTE:COR,IDP */
									   pImportKeyCustomStruct->u16KeyLength[1],
									   (uint8 *)pImportKeyCustomStruct->pKey[1],
									   (uint8 *)pImportKeyCustomStruct->pKey[2]);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_Wrapper_KeyGenerate
(
    VAR(uint32, CRYPTO_VAR) cryptoKeyId
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType,    AUTOMATIC) retVal          	= (Std_ReturnType)CRYPTO_E_PARAM_HANDLE;
    VAR(uint32, AUTOMATIC) cryptoKeyIndex  		 		= Crypto_SearchKeyIdIndex(cryptoKeyId);
    VAR(uint32,	AUTOMATIC) cryptoKeyMaterialElemIndex;

    if (CRYPTO_HSM_INVALID_KEY_IDX != cryptoKeyIndex)
    {
    	cryptoKeyMaterialElemIndex = Crypto_SearchKeyElementIdIndex(cryptoKeyIndex, CRYPTO_KE_CIPHER_KEY);
    	//CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
    	if((CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX != cryptoKeyMaterialElemIndex)&&(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32Crypto_KeyElementActualSize == 0U))
    	{

    		retVal = (Std_ReturnType)CRYPTO_E_KEY_EMPTY;

    	}
    	else if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX != cryptoKeyMaterialElemIndex)
    	{
    		if ((HSM_KEY_TYPE_AES == Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u16HsmKeyType)
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
    				||
    			(HSM_KEY_TYPE_SM4 == Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u16HsmKeyType)
#endif
    		)
    		{
				status = HSM_LLD_GenerateSymKey(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
												Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u16HsmKeyType,
												Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u16HsmKeyFlags,
												(uint16)Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyBits >> 3);
				retVal = Crypto_VerifyHsmResp(status);
    		}
    		else
    		{
    			retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
    		}
    	}
    }

    return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_MacGenerate
(
	P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
)
{
	VAR(status_t,			    	AUTOMATIC) status          				= STATUS_HSM_GENERAL_ERRPR;
    VAR(Std_ReturnType,         	AUTOMATIC) retVal          				= (Std_ReturnType)E_NOT_OK;
    VAR(Crypto_ProcessingType,  	AUTOMATIC) eProcessingType 				= pJob->jobPrimitiveInfo->processingType;/* polyspace RTE:NIV */ 
    VAR(Crypto_AlgorithmFamilyType, AUTOMATIC) algoFam						= pJob->jobPrimitiveInfo->primitiveInfo->algorithm.family;/* polyspace RTE:NIV */ 
    VAR(Crypto_AlgorithmModeType, 	AUTOMATIC) algoMode						= pJob->jobPrimitiveInfo->primitiveInfo->algorithm.mode;/* polyspace RTE:NIV */ 
    VAR(uint32, 					AUTOMATIC) cryptoKeyIndex  		 		= Crypto_SearchKeyIdIndex(pJob->jobPrimitiveInfo->cryIfKeyId);/* polyspace RTE:NIV */ 
    VAR(uint32,				    	AUTOMATIC) cryptoKeyMaterialElemIndex;
    VAR(hsmHashAlgo_t,				AUTOMATIC) hashAlgo = (hsmHashAlgo_t)HSM_HASH_ALGO_NOT_SET;
    VAR (Crypto_OperationModeType, AUTOMATIC) eOptMode                      = pJob->jobPrimitiveInputOutput.mode; /* polyspace RTE:NIV */
    VAR(uint32,                 CRYPTO_VAR) u32OutputLen    = 0UL;


    if (CRYPTO_HSM_INVALID_KEY_IDX != cryptoKeyIndex)
    {
    	cryptoKeyMaterialElemIndex = Crypto_SearchKeyElementIdIndex(cryptoKeyIndex, CRYPTO_KE_CIPHER_KEY);
    	if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX != cryptoKeyMaterialElemIndex)
    	{
			if (CRYPTO_ALGOMODE_HMAC == algoMode)
			{
				retVal = (Std_ReturnType)E_OK;
				switch (algoFam)
				{
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
					case CRYPTO_ALGOFAM_SM3: 	   hashAlgo = HSM_HASH_ALGO_SM3; break;
#endif
					case CRYPTO_ALGOFAM_SHA1: 	   hashAlgo = HSM_HASH_ALGO_SHA1; break;
					case CRYPTO_ALGOFAM_SHA2_224:  hashAlgo = HSM_HASH_ALGO_SHA2_224; break;
					case CRYPTO_ALGOFAM_SHA2_256:  hashAlgo = HSM_HASH_ALGO_SHA2_256; break;
					case CRYPTO_ALGOFAM_SHA2_384:  hashAlgo = HSM_HASH_ALGO_SHA2_384; break;
					case CRYPTO_ALGOFAM_SHA2_512:  hashAlgo = HSM_HASH_ALGO_SHA2_512; break;
					case CRYPTO_ALGOFAM_RIPEMD160: hashAlgo = HSM_HASH_ALGO_RIPEMD160; break;
					default:
						retVal = (Std_ReturnType)CRYPTO_E_INVALID_PARAM;
						break;

				}

			    if(eOptMode==CRYPTO_OPERATIONMODE_SINGLECALL)
			    {

			    	eOptMode= (Crypto_OperationModeType)HSM_OPERATION_MODE_SINGLE_CALL;		/* PRQA S 4342 */

			    }

			    if(eOptMode==CRYPTO_OPERATIONMODE_FINISH)
			    {

			    	eOptMode= (Crypto_OperationModeType)HSM_OPERATION_MODE_FINISH;		/* PRQA S 4342 */

			    }

				if ((Std_ReturnType)E_OK == retVal)
				{
					if (CRYPTO_PROCESSING_SYNC == eProcessingType)
					{
						status = HSM_LLD_HmacGenerate(eOptMode,Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
													  hashAlgo,
													  pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */ 
													  pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */ 
													  pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */ 
													  pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIP */
						retVal = Crypto_VerifyHsmResp(status);
					}
					else if((uint16_t)CRYPTO_PROCESSING_ASYNC_POLLING_MODE == (uint16_t)eProcessingType)
					{
						status = HSM_LLD_HmacGenerate_Async(eOptMode,Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
													  hashAlgo,
													  pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
													  pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
													  pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */
													  pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIP */
						retVal = Crypto_VerifyHsmResp(status);

					}
                    else
                    {
                        /* do nothing */
                    }

				}
			}
			else if (CRYPTO_ALGOMODE_CMAC == algoMode)
			{
#if 0
			    if((eOptMode==CRYPTO_OPERATIONMODE_SINGLECALL) || (eOptMode==CRYPTO_OPERATIONMODE_FINISH))
			    {

			    	if(*pJob->jobPrimitiveInputOutput.outputLengthPtr>= 16U)
			    	{

			    		*pJob->jobPrimitiveInputOutput.outputLengthPtr = 16U;

			    	}
					else
					{
						retVal = (Std_ReturnType)CRYPTO_E_SMALL_BUFFER;
					}

			    }
#endif
			    if((eOptMode==CRYPTO_OPERATIONMODE_SINGLECALL) || (eOptMode==CRYPTO_OPERATIONMODE_FINISH))
			    {
			    	u32OutputLen = *pJob->jobPrimitiveInputOutput.outputLengthPtr;/* polyspace RTE:NIV *//* polyspace RTE:NIP *//* polyspace RTE:IDP */

			        u32OutputLen = (uint32)(u32OutputLen |(uint32)0xA55AA500UL);

			        *pJob->jobPrimitiveInputOutput.outputLengthPtr = u32OutputLen;

			    }

			    if(eOptMode==CRYPTO_OPERATIONMODE_SINGLECALL)
			    {

			    	eOptMode= (Crypto_OperationModeType)HSM_OPERATION_MODE_SINGLE_CALL;	/* PRQA S 4342 */

			    }

			    if(eOptMode==CRYPTO_OPERATIONMODE_FINISH)
			    {

			    	eOptMode= (Crypto_OperationModeType)HSM_OPERATION_MODE_FINISH;	/* PRQA S 4342 */

			    }

				if (CRYPTO_PROCESSING_SYNC == eProcessingType)
				{

					status = HSM_LLD_AesCmacGenerate(eOptMode,Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
													 pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
													 pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
													 pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */
													 pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIP */
					retVal = Crypto_VerifyHsmResp(status);
				}

				else if((uint16_t)CRYPTO_PROCESSING_ASYNC_POLLING_MODE == (uint16_t)eProcessingType)
				{
					status = HSM_LLD_AesCmacGenerate_Async(eOptMode,Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
													 pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
													 pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
													 pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */
													 pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIP */
					retVal = Crypto_VerifyHsmResp(status);


				}
                else
                {
                 	/* do nothing */
                }

			}
			else
			{
				retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
			}
    	}
    }

    return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_MacVerify
(
	P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
)
{
	VAR(status_t,			    	AUTOMATIC) status          				= STATUS_HSM_GENERAL_ERRPR;
    VAR(Std_ReturnType,         	AUTOMATIC) retVal          				= (Std_ReturnType)E_NOT_OK;
    VAR(Crypto_ProcessingType,  	AUTOMATIC) eProcessingType 				= pJob->jobPrimitiveInfo->processingType;/* polyspace RTE:NIV */ 
    VAR(Crypto_AlgorithmFamilyType, AUTOMATIC) algoFam						= pJob->jobPrimitiveInfo->primitiveInfo->algorithm.family;/* polyspace RTE:NIV */ 
    VAR(Crypto_AlgorithmModeType, 	AUTOMATIC) algoMode						= pJob->jobPrimitiveInfo->primitiveInfo->algorithm.mode;/* polyspace RTE:NIV */ 
    VAR(uint32, 					AUTOMATIC) cryptoKeyIndex  		 		= Crypto_SearchKeyIdIndex(pJob->jobPrimitiveInfo->cryIfKeyId);/* polyspace RTE:NIV */ 
    VAR(uint32,				    	AUTOMATIC) cryptoKeyMaterialElemIndex;
    VAR(hsmHashAlgo_t,				AUTOMATIC) hashAlgo = (hsmHashAlgo_t)HSM_HASH_ALGO_NOT_SET;
    VAR (Crypto_OperationModeType, AUTOMATIC) eOptMode                      = pJob->jobPrimitiveInputOutput.mode; /* polyspace RTE:NIV */

    if(eOptMode==CRYPTO_OPERATIONMODE_SINGLECALL)
    {

    	eOptMode= (Crypto_OperationModeType)HSM_OPERATION_MODE_SINGLE_CALL;	/* PRQA S 4342 */

    }

    if(eOptMode==CRYPTO_OPERATIONMODE_FINISH)
    {

    	eOptMode= (Crypto_OperationModeType)HSM_OPERATION_MODE_FINISH;		/* PRQA S 4342 */

    }

    if (CRYPTO_HSM_INVALID_KEY_IDX != cryptoKeyIndex)
    {
    	cryptoKeyMaterialElemIndex = Crypto_SearchKeyElementIdIndex(cryptoKeyIndex, CRYPTO_KE_CIPHER_KEY);
    	if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX != cryptoKeyMaterialElemIndex)
    	{
			if (CRYPTO_ALGOMODE_HMAC == algoMode)
			{
				retVal = (Std_ReturnType)E_OK;
				switch (algoFam)
				{
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
					case CRYPTO_ALGOFAM_SM3: 	   hashAlgo = HSM_HASH_ALGO_SM3; break;
#endif
					case CRYPTO_ALGOFAM_SHA1: 	   hashAlgo = HSM_HASH_ALGO_SHA1; break;
					case CRYPTO_ALGOFAM_SHA2_224:  hashAlgo = HSM_HASH_ALGO_SHA2_224; break;
					case CRYPTO_ALGOFAM_SHA2_256:  hashAlgo = HSM_HASH_ALGO_SHA2_256; break;
					case CRYPTO_ALGOFAM_SHA2_384:  hashAlgo = HSM_HASH_ALGO_SHA2_384; break;
					case CRYPTO_ALGOFAM_SHA2_512:  hashAlgo = HSM_HASH_ALGO_SHA2_512; break;
					case CRYPTO_ALGOFAM_RIPEMD160: hashAlgo = HSM_HASH_ALGO_RIPEMD160; break;
					default:
						retVal = (Std_ReturnType)CRYPTO_E_INVALID_PARAM;
						break;

				}
				if ((Std_ReturnType)E_OK == retVal)
				{
					if (CRYPTO_PROCESSING_SYNC == eProcessingType)
					{
						status = HSM_LLD_HmacVerify(eOptMode,Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
													hashAlgo,
													pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
													pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
													pJob->jobPrimitiveInputOutput.secondaryInputPtr,/* polyspace RTE:NIP */
													(uint32 *)&pJob->jobPrimitiveInputOutput.secondaryInputLength,
													(uint32*)pJob->jobPrimitiveInputOutput.verifyPtr/* polyspace RTE:NIP */
													);
						retVal = Crypto_VerifyHsmResp(status);
					}
					else if((uint16)CRYPTO_PROCESSING_ASYNC_POLLING_MODE == (uint16)eProcessingType)
					{
						status = HSM_LLD_HmacVerify_Async(eOptMode,Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
													hashAlgo,
													pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
													pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
													pJob->jobPrimitiveInputOutput.secondaryInputPtr,/* polyspace RTE:NIP */
													(uint32 *)&pJob->jobPrimitiveInputOutput.secondaryInputLength,
													(uint32*)pJob->jobPrimitiveInputOutput.verifyPtr/* polyspace RTE:NIP */
													);
						retVal = Crypto_VerifyHsmResp(status);

					}
                    else
                    {
                        /* do nothing */
                    }
				}
			}
			else if (CRYPTO_ALGOMODE_CMAC == algoMode)
			{
				if (CRYPTO_PROCESSING_SYNC == eProcessingType)
				{
					status = HSM_LLD_AesCmacVerify(eOptMode,Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
													pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */ 
													pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */ 
													pJob->jobPrimitiveInputOutput.secondaryInputPtr,/* polyspace RTE:NIP */ 
													(uint32 *)&pJob->jobPrimitiveInputOutput.secondaryInputLength,
													(uint32*)pJob->jobPrimitiveInputOutput.verifyPtr);/* polyspace RTE:NIP */
					retVal = Crypto_VerifyHsmResp(status);

				}
				else if((uint16)CRYPTO_PROCESSING_ASYNC_POLLING_MODE == (uint16)eProcessingType)
				{
					status = HSM_LLD_AesCmacVerify_Async(eOptMode,Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
													pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
													pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
													pJob->jobPrimitiveInputOutput.secondaryInputPtr,/* polyspace RTE:NIP */
													(uint32 *)&pJob->jobPrimitiveInputOutput.secondaryInputLength,
													(uint32*)pJob->jobPrimitiveInputOutput.verifyPtr);/* polyspace RTE:NIP */
					retVal = Crypto_VerifyHsmResp(status);

				}
                else
                {
                    /* do nothing */
                }
			}
			else
			{
				retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
			}
			//}
    	}
    }
#if 0
    if ((Std_ReturnType)E_OK == retVal)
    {
    	if (TRUE == verifyStatus)
    	{
    		*pJob->jobPrimitiveInputOutput.verifyPtr = CRYPTO_E_VER_OK;/* polyspace RTE:NIP,COR */ 
    	}
    	else
    	{
    		*pJob->jobPrimitiveInputOutput.verifyPtr = CRYPTO_E_VER_NOT_OK;/* polyspace RTE:NIP,COR */ 
    	}
    }
#endif
    return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_Encrypt
(
	P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
)
{
	VAR(status_t,		  			AUTOMATIC) status            			= STATUS_HSM_GENERAL_ERRPR;
    VAR(Std_ReturnType,           	AUTOMATIC) retVal          				= (Std_ReturnType)E_NOT_OK;
    VAR(Crypto_ProcessingType,    	AUTOMATIC) eProcessingType 				= pJob->jobPrimitiveInfo->processingType;/* polyspace RTE:NIV */ 
    VAR(Crypto_AlgorithmFamilyType, AUTOMATIC) algoFam						= pJob->jobPrimitiveInfo->primitiveInfo->algorithm.family;/* polyspace RTE:NIV */ 
    VAR(Crypto_AlgorithmModeType, 	AUTOMATIC) algoMode						= pJob->jobPrimitiveInfo->primitiveInfo->algorithm.mode;/* polyspace RTE:NIV */ 
    VAR(Crypto_AlgorithmFamilyType, AUTOMATIC) secondaryAlgoFam             = pJob->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily;/* polyspace RTE:NIV */
    VAR(uint32, 					AUTOMATIC) cryptoKeyIndex  		 		= Crypto_SearchKeyIdIndex(pJob->jobPrimitiveInfo->cryIfKeyId);/* polyspace RTE:NIV */ 
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pIV 						= NULL_PTR;
    VAR(uint32,				    	AUTOMATIC) cryptoKeyMaterialElemIndex;
    VAR(uint32,				    	AUTOMATIC) cryptoIvElemIndex;
    VAR(uint8,						AUTOMATIC) cipherBlockMode;
    VAR (Crypto_OperationModeType, AUTOMATIC) eOptMode                      = pJob->jobPrimitiveInputOutput.mode;/* polyspace RTE:NIV */
    VAR(hsmHashAlgo_t,				AUTOMATIC) hashAlgo = (hsmHashAlgo_t)HSM_HASH_ALGO_NOT_SET;

    if(eOptMode==CRYPTO_OPERATIONMODE_SINGLECALL)
    {

    	eOptMode= (Crypto_OperationModeType)HSM_OPERATION_MODE_SINGLE_CALL;		/* PRQA S 4342 */

    }

    if(eOptMode==CRYPTO_OPERATIONMODE_FINISH)
    {

    	eOptMode= (Crypto_OperationModeType)HSM_OPERATION_MODE_FINISH;			/* PRQA S 4342 */

    }

    if (CRYPTO_HSM_INVALID_KEY_IDX != cryptoKeyIndex)
    {
    	cryptoKeyMaterialElemIndex = Crypto_SearchKeyElementIdIndex(cryptoKeyIndex, CRYPTO_KE_CIPHER_KEY);
    	if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX != cryptoKeyMaterialElemIndex)
    	{
    		if ((CRYPTO_ALGOFAM_AES == algoFam)
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
    				|| (CRYPTO_ALGOFAM_SM4 == algoFam)
#endif
					)
    		{
    			if (CRYPTO_ALGOMODE_ECB == algoMode)
    			{
    				cipherBlockMode = HSM_CIPHER_BLOCK_MODE_ECB;
    				retVal = (Std_ReturnType)E_OK;
    			}
    			else if (CRYPTO_ALGOMODE_CBC == algoMode)
    			{
    				cipherBlockMode = HSM_CIPHER_BLOCK_MODE_CBC;
    				retVal = (Std_ReturnType)E_OK;
    			}
    			else if (CRYPTO_ALGOMODE_CTR == algoMode)
    			{
    				cipherBlockMode = HSM_CIPHER_BLOCK_MODE_CTR;
    				retVal = (Std_ReturnType)E_OK;
    			}
    			else
    			{
    				retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
    			}
    			if ((Std_ReturnType)E_OK == retVal)
    			{
    				if (CRYPTO_ALGOMODE_ECB != algoMode)
    				{
        				cryptoIvElemIndex = Crypto_SearchKeyElementIdIndex(cryptoKeyIndex, CRYPTO_KE_CIPHER_IV);
        				if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX != cryptoIvElemIndex)
        				{
        					pIV = Crypto_KeyElementList[cryptoIvElemIndex]->pCrypto_ElementArray;
        				}
        				else
        				{
        					retVal = (Std_ReturnType)E_NOT_OK;
        				}
    				}
    			}
    			if ((Std_ReturnType)E_OK == retVal)
    			{
    				if (CRYPTO_PROCESSING_SYNC == eProcessingType)
    				{
    					if (CRYPTO_ALGOFAM_AES == algoFam)/* PRQA S 2991, 2995 */
    					{
							status = HSM_LLD_AesEncrypt(eOptMode,Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
														(hsmCipherBlockMode_t)cipherBlockMode,
														HSM_CIPHER_STREAM_BITS_NULL,
														pIV,
														pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */ 
														pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */ 
														pJob->jobPrimitiveInputOutput.outputPtr);/* polyspace RTE:NIP */ 
    					}
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
    					else
    					{
							status = HSM_LLD_Sm4Encrypt(eOptMode,Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
														(hsmCipherBlockMode_t)cipherBlockMode,
														HSM_CIPHER_STREAM_BITS_NULL,
														pIV,
														pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */ 
														pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */ 
														pJob->jobPrimitiveInputOutput.outputPtr);/* polyspace RTE:NIP */ 
    					}
#endif
						retVal = Crypto_VerifyHsmResp(status);
					    if ((Std_ReturnType)E_OK == retVal)
					    {
					    	if(eOptMode != CRYPTO_OPERATIONMODE_START)
					    	{
						        if (*pJob->jobPrimitiveInputOutput.outputLengthPtr >= pJob->jobPrimitiveInputOutput.inputLength)/* polyspace RTE:NIV,NIP,COR,IDP */
						        {
						        	*pJob->jobPrimitiveInputOutput.outputLengthPtr = pJob->jobPrimitiveInputOutput.inputLength;
						        }
						        else
						        {
						        	retVal = (Std_ReturnType)CRYPTO_E_SMALL_BUFFER;
						        }

					    	}
					    }
    				}
    				else if((uint16)CRYPTO_PROCESSING_ASYNC_POLLING_MODE == (uint16)eProcessingType)
    				{
    					if (CRYPTO_ALGOFAM_AES == algoFam)/* PRQA S 2991, 2995 */
    					{
							status = HSM_LLD_AesEncrypt_Async(eOptMode,Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
														(hsmCipherBlockMode_t)cipherBlockMode,
														HSM_CIPHER_STREAM_BITS_NULL,
														pIV,
														pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
														pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
														pJob->jobPrimitiveInputOutput.outputPtr);/* polyspace RTE:NIP */
    					}
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
    					else
    					{
							status = HSM_LLD_Sm4Encrypt_Async(eOptMode,Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
														(hsmCipherBlockMode_t)cipherBlockMode,
														HSM_CIPHER_STREAM_BITS_NULL,
														pIV,
														pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
														pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
														pJob->jobPrimitiveInputOutput.outputPtr);/* polyspace RTE:NIP */
    					}
#endif
						retVal = Crypto_VerifyHsmResp(status);
					    if ((Std_ReturnType)E_OK == retVal)
					    {
					    	if(eOptMode != CRYPTO_OPERATIONMODE_START)
					    	{
						        if (*pJob->jobPrimitiveInputOutput.outputLengthPtr >= pJob->jobPrimitiveInputOutput.inputLength)/* polyspace RTE:IDP,NIV,NIP */
						        {
						        	*pJob->jobPrimitiveInputOutput.outputLengthPtr = pJob->jobPrimitiveInputOutput.inputLength;
						        }
						        else
						        {
						        	retVal = (Std_ReturnType)CRYPTO_E_SMALL_BUFFER;
						        }

					    	}
					    }

    				}
    				else
    				{
    					retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
    				}
    			}
    		}
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
    		else if (CRYPTO_ALGOFAM_SM2 == algoFam)
    		{
    			if (CRYPTO_PROCESSING_SYNC == eProcessingType)
    			{
					status = HSM_LLD_Sm2Encrypt(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
												pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */ 
												pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */ 
												pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */ 
												pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIP */ 
					retVal = Crypto_VerifyHsmResp(status);
    			}
    			else if(CRYPTO_PROCESSING_ASYNC_POLLING_MODE == eProcessingType)
    			{
					status = HSM_LLD_Sm2Encrypt_Async(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
												pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
												pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
												pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */
												pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIP */
					retVal = Crypto_VerifyHsmResp(status);

    			}
                else
                {
                    /* do nothing */
                }
			}
#endif
    		else if (CRYPTO_ALGOFAM_RSA == algoFam)
    		{
    			if(CRYPTO_ALGOMODE_RSAES_OAEP == algoMode)
    			{
        			switch (secondaryAlgoFam)
    				{
    					case CRYPTO_ALGOFAM_SHA2_256:
    						hashAlgo = HSM_HASH_ALGO_SHA2_256;
    						break;
    					case CRYPTO_ALGOFAM_SHA2_384:
    						hashAlgo = HSM_HASH_ALGO_SHA2_384;
    						break;
    					case CRYPTO_ALGOFAM_SHA2_512:
    						hashAlgo = HSM_HASH_ALGO_SHA2_512;
    						break;
    					default:
    						retVal = (Std_ReturnType)CRYPTO_E_INVALID_PARAM;
    						break;

    				}
    			}
				if (CRYPTO_PROCESSING_SYNC == eProcessingType)
				{
					if (CRYPTO_ALGOMODE_RSAES_PKCS1_v1_5 == algoMode)
					{
						status = HSM_LLD_RsaPkcs1V15Encrypt(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
																	  pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */ 
																	  pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */ 
																	  pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */ 
																	  pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIP */ 
						retVal = Crypto_VerifyHsmResp(status);
					}
					else if (CRYPTO_ALGOMODE_NOT_SET == algoMode)
					{

						status = HSM_LLD_RsaNoPaddEncrypt(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
																	  pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
																	  pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
																	  pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */
																	  pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIP */
						retVal = Crypto_VerifyHsmResp(status);

					}
					else if(CRYPTO_ALGOMODE_RSAES_OAEP == algoMode)
					{
						status = HSM_LLD_RsaOAEPEncrypt(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
								  hashAlgo,
								  pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
								  pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
								  pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */
								  pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIP */

						retVal = Crypto_VerifyHsmResp(status);

					}
					else
					{
						retVal = (Std_ReturnType)CRYPTO_E_INVALID_PARAM;
					}
				}
				else if((uint16)CRYPTO_PROCESSING_ASYNC_POLLING_MODE == (uint16)eProcessingType)
				{
					if (CRYPTO_ALGOMODE_RSAES_PKCS1_v1_5 == algoMode)
					{
						status = HSM_LLD_RsaPkcs1V15Encrypt_Async(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
																	  pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
																	  pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
																	  pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */
																	  pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIP */
						retVal = Crypto_VerifyHsmResp(status);
					}
					else if (CRYPTO_ALGOMODE_NOT_SET == algoMode)
					{
						status = HSM_LLD_RsaNoPaddEncrypt_Async(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
																	  pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
																	  pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
																	  pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */
																	  pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIP */
						retVal = Crypto_VerifyHsmResp(status);
					}
					else if(CRYPTO_ALGOMODE_RSAES_OAEP == algoMode)
					{
						status = HSM_LLD_RsaOAEPEncrypt_Async(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
								  hashAlgo,
								  pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
								  pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
								  pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */
								  pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIP */

						retVal = Crypto_VerifyHsmResp(status);
					}
					else
					{
						retVal = (Std_ReturnType)CRYPTO_E_INVALID_PARAM;
					}

				}
				else
				{
					retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
				}
    		}
    		else
    		{
    			retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
    		}
    	}
	}

    return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_Decrypt
(
	P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
)
{
	VAR(status_t,		  			AUTOMATIC) status            			= STATUS_HSM_GENERAL_ERRPR;
    VAR(Std_ReturnType,           	AUTOMATIC) retVal          				= (Std_ReturnType)E_NOT_OK;
    VAR(Crypto_ProcessingType,    	AUTOMATIC) eProcessingType 				= pJob->jobPrimitiveInfo->processingType;/* polyspace RTE:NIV */ 
    VAR(Crypto_AlgorithmFamilyType, AUTOMATIC) algoFam						= pJob->jobPrimitiveInfo->primitiveInfo->algorithm.family;/* polyspace RTE:NIV */ 
    VAR(Crypto_AlgorithmModeType, 	AUTOMATIC) algoMode						= pJob->jobPrimitiveInfo->primitiveInfo->algorithm.mode;/* polyspace RTE:NIV */ 
    VAR(Crypto_AlgorithmFamilyType, AUTOMATIC) secondaryAlgoFam             = pJob->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily;/* polyspace RTE:NIV */
    VAR(uint32, 					AUTOMATIC) cryptoKeyIndex  		 		= Crypto_SearchKeyIdIndex(pJob->jobPrimitiveInfo->cryIfKeyId);/* polyspace RTE:NIV */ 
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pIV 						= NULL_PTR;
    VAR(uint32,				    	AUTOMATIC) cryptoKeyMaterialElemIndex;
    VAR(uint32,				    	AUTOMATIC) cryptoIvElemIndex;
    VAR(uint8,						AUTOMATIC) cipherBlockMode;
    VAR (Crypto_OperationModeType, AUTOMATIC) eOptMode                      = pJob->jobPrimitiveInputOutput.mode; /* polyspace RTE:NIV */
    VAR(hsmHashAlgo_t,				AUTOMATIC) hashAlgo = (hsmHashAlgo_t)HSM_HASH_ALGO_NOT_SET;

    if(eOptMode==CRYPTO_OPERATIONMODE_SINGLECALL)
    {

    	eOptMode= (Crypto_OperationModeType)HSM_OPERATION_MODE_SINGLE_CALL;			/* PRQA S 4342 */

    }

    if(eOptMode==CRYPTO_OPERATIONMODE_FINISH)
    {

    	eOptMode= (Crypto_OperationModeType)HSM_OPERATION_MODE_FINISH;			/* PRQA S 4342 */

    }

    if (CRYPTO_HSM_INVALID_KEY_IDX != cryptoKeyIndex)
    {
    	cryptoKeyMaterialElemIndex = Crypto_SearchKeyElementIdIndex(cryptoKeyIndex, CRYPTO_KE_CIPHER_KEY);
    	if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX != cryptoKeyMaterialElemIndex)
    	{
    		if ((CRYPTO_ALGOFAM_AES == algoFam)
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
    				|| (CRYPTO_ALGOFAM_SM4 == algoFam)
#endif
					)
    		{
    			if (CRYPTO_ALGOMODE_ECB == algoMode)
    			{
    				cipherBlockMode = HSM_CIPHER_BLOCK_MODE_ECB;
    				retVal = (Std_ReturnType)E_OK;
    			}
    			else if (CRYPTO_ALGOMODE_CBC == algoMode)
    			{
    				cipherBlockMode = HSM_CIPHER_BLOCK_MODE_CBC;
    				retVal = (Std_ReturnType)E_OK;
    			}
    			else if (CRYPTO_ALGOMODE_CTR == algoMode)
    			{
    				cipherBlockMode = HSM_CIPHER_BLOCK_MODE_CTR;
    				retVal = (Std_ReturnType)E_OK;
    			}
    			else
    			{
    				retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
    			}
    			if ((Std_ReturnType)E_OK == retVal)
    			{
    				if (CRYPTO_ALGOMODE_ECB != algoMode)
    				{
        				cryptoIvElemIndex = Crypto_SearchKeyElementIdIndex(cryptoKeyIndex, CRYPTO_KE_CIPHER_IV);
        				if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX != cryptoIvElemIndex)
        				{
        					pIV = Crypto_KeyElementList[cryptoIvElemIndex]->pCrypto_ElementArray;
        				}
        				else
        				{
        					retVal = (Std_ReturnType)E_NOT_OK;
        				}
    				}
    			}
    			if ((Std_ReturnType)E_OK == retVal)
    			{
    				if (CRYPTO_PROCESSING_SYNC == eProcessingType)
    				{
    					if (CRYPTO_ALGOFAM_AES == algoFam)/* PRQA S 2991, 2995 */
    					{
							status = HSM_LLD_AesDecrypt(eOptMode,Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
														cipherBlockMode,
														HSM_CIPHER_STREAM_BITS_NULL,
														pIV,
														pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */ 
														pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */ 
														pJob->jobPrimitiveInputOutput.outputPtr);/* polyspace RTE:NIP */ 
    					}
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
    					else
    					{
    						status = HSM_LLD_Sm4Decrypt(eOptMode,Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
    													cipherBlockMode,
    													HSM_CIPHER_STREAM_BITS_NULL,
    													pIV,
    													pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */ 
    													pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */ 
    													pJob->jobPrimitiveInputOutput.outputPtr);/* polyspace RTE:NIP */ 
    					}
#endif
						retVal = Crypto_VerifyHsmResp(status);
					    if ((Std_ReturnType)E_OK == retVal)
					    {
					    	if(eOptMode != CRYPTO_OPERATIONMODE_START)
					    	{

						        if (*pJob->jobPrimitiveInputOutput.outputLengthPtr >= pJob->jobPrimitiveInputOutput.inputLength)/* polyspace RTE:NIV,NIP,COR,IDP */
						        {
						        	*pJob->jobPrimitiveInputOutput.outputLengthPtr = pJob->jobPrimitiveInputOutput.inputLength;
						        }
						        else
						        {
						        	retVal = (Std_ReturnType)CRYPTO_E_SMALL_BUFFER;
						        }

					    	}
					    }
    				}
    				else if((uint16)CRYPTO_PROCESSING_ASYNC_POLLING_MODE == (uint16)eProcessingType)
    				{
    					if (CRYPTO_ALGOFAM_AES == algoFam)/* PRQA S 2991, 2995 */
    					{
							status = HSM_LLD_AesDecrypt_Async(eOptMode,Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
														cipherBlockMode,
														HSM_CIPHER_STREAM_BITS_NULL,
														pIV,
														pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
														pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
														pJob->jobPrimitiveInputOutput.outputPtr);/* polyspace RTE:NIP */
    					}
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
    					else
    					{
    						status = HSM_LLD_Sm4Decrypt_Async(eOptMode,Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
    													cipherBlockMode,
    													HSM_CIPHER_STREAM_BITS_NULL,
    													pIV,
    													pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
    													pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
    													pJob->jobPrimitiveInputOutput.outputPtr);/* polyspace RTE:NIP */
    					}
#endif
						retVal = Crypto_VerifyHsmResp(status);
					    if ((Std_ReturnType)E_OK == retVal)
					    {
					    	if(eOptMode != CRYPTO_OPERATIONMODE_START)
					    	{
						        if (*pJob->jobPrimitiveInputOutput.outputLengthPtr >= pJob->jobPrimitiveInputOutput.inputLength)/* polyspace RTE:IDP,NIV,NIP */
						        {
						        	*pJob->jobPrimitiveInputOutput.outputLengthPtr = pJob->jobPrimitiveInputOutput.inputLength;
						        }
						        else
						        {
						        	retVal = (Std_ReturnType)CRYPTO_E_SMALL_BUFFER;
						        }

					    	}
					    }

    				}
    				else
    				{
    					retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
    				}
    			}
    		}
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
    		else if (CRYPTO_ALGOFAM_SM2 == algoFam)
    		{
    			if (CRYPTO_PROCESSING_SYNC == eProcessingType)
    			{
					status = HSM_LLD_Sm2Decrypt(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
												pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */ 
												pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */ 
												pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */ 
												pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIP */ 
					retVal = Crypto_VerifyHsmResp(status);
    			}
    			else if(CRYPTO_PROCESSING_ASYNC_POLLING_MODE == eProcessingType)
    			{
					status = HSM_LLD_Sm2Decrypt_Async(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
												pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
												pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
												pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */
												pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIP */
					retVal = Crypto_VerifyHsmResp(status);

    			}
    		}
#endif
    		else if (CRYPTO_ALGOFAM_RSA == algoFam)
			{

    			if(CRYPTO_ALGOMODE_RSAES_OAEP == algoMode)
    			{
        			switch (secondaryAlgoFam)
    				{
    					case CRYPTO_ALGOFAM_SHA2_256:
    						hashAlgo = HSM_HASH_ALGO_SHA2_256;
    						break;
    					case CRYPTO_ALGOFAM_SHA2_384:
    						hashAlgo = HSM_HASH_ALGO_SHA2_384;
    						break;
    					case CRYPTO_ALGOFAM_SHA2_512:
    						hashAlgo = HSM_HASH_ALGO_SHA2_512;
    						break;
    					default:
    						retVal = (Std_ReturnType)CRYPTO_E_INVALID_PARAM;
    						break;

    				}
    			}

				if (CRYPTO_PROCESSING_SYNC == eProcessingType)
				{
					if (CRYPTO_ALGOMODE_RSAES_PKCS1_v1_5 == algoMode)
					{
						status = HSM_LLD_RsaPkcs1V15Decrypt(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
															pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */ 
															pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */ 
															pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */ 
															pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIP */ 
						retVal = Crypto_VerifyHsmResp(status);
					}
					else if (CRYPTO_ALGOMODE_NOT_SET == algoMode)
					{
						status = HSM_LLD_RsaNoPaddDecrypt(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
															pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
															pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
															pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */
															pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIP */
						retVal = Crypto_VerifyHsmResp(status);
					}
					else if(CRYPTO_ALGOMODE_RSAES_OAEP == algoMode)
					{
						status = HSM_LLD_RsaOAEPDecrypt(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
															hashAlgo,
															pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
															pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
															pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */
															pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIP */
						retVal = Crypto_VerifyHsmResp(status);

					}
					else
					{
						retVal = (Std_ReturnType)CRYPTO_E_INVALID_PARAM;
					}
				}
				else if((uint16)CRYPTO_PROCESSING_ASYNC_POLLING_MODE == (uint16)eProcessingType)
				{
					if (CRYPTO_ALGOMODE_RSAES_PKCS1_v1_5 == algoMode)
					{
						status = HSM_LLD_RsaPkcs1V15Decrypt_Async(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
															pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
															pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
															pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */
															pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIP */
						retVal = Crypto_VerifyHsmResp(status);
					}
					else if (CRYPTO_ALGOMODE_NOT_SET == algoMode)
					{
						status = HSM_LLD_RsaNoPaddDecrypt_Async(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
															pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
															pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
															pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */
															pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIP */
						retVal = Crypto_VerifyHsmResp(status);
					}
					else if(CRYPTO_ALGOMODE_RSAES_OAEP == algoMode)
					{
						status = HSM_LLD_RsaOAEPDecrypt_Async(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
															hashAlgo,
															pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
															pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
															pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */
															pJob->jobPrimitiveInputOutput.outputLengthPtr);/* polyspace RTE:NIP */
						retVal = Crypto_VerifyHsmResp(status);

					}
					else
					{
						retVal = (Std_ReturnType)CRYPTO_E_INVALID_PARAM;
					}

				}
				else
				{
					retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
				}
			}
    		else
    		{
    			retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
    		}
    	}
	}

    return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_AeadEncrypt
(
	P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
)
{
	VAR(status_t,		  			AUTOMATIC) status            			= STATUS_HSM_GENERAL_ERRPR;
	VAR(Std_ReturnType,           	AUTOMATIC) retVal          				= (Std_ReturnType)E_OK;
	VAR(Crypto_ProcessingType,    	AUTOMATIC) eProcessingType 				= pJob->jobPrimitiveInfo->processingType;/* polyspace RTE:NIV */ 
	VAR(Crypto_AlgorithmFamilyType, AUTOMATIC) algoFam						= pJob->jobPrimitiveInfo->primitiveInfo->algorithm.family;/* polyspace RTE:NIV */ 
	VAR(uint32, 					AUTOMATIC) cryptoKeyIndex  		 		= Crypto_SearchKeyIdIndex(pJob->jobPrimitiveInfo->cryIfKeyId);/* polyspace RTE:NIV */ 
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pIV 						= NULL_PTR;
	VAR(uint32,				    	AUTOMATIC) cryptoKeyMaterialElemIndex;
	VAR(uint32,				    	AUTOMATIC) cryptoIvElemIndex;
    VAR (Crypto_OperationModeType, AUTOMATIC) eOptMode                      = pJob->jobPrimitiveInputOutput.mode;/* polyspace RTE:NIV */

    if(eOptMode==CRYPTO_OPERATIONMODE_SINGLECALL)
    {

    	eOptMode= (Crypto_OperationModeType)HSM_OPERATION_MODE_SINGLE_CALL;			/* PRQA S 4342 */

    }
    else
    {
    	/*Stream mode not supported*/

    	retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;

    }

#if 0
    if(eOptMode==CRYPTO_OPERATIONMODE_FINISH)
    {

    	eOptMode= (Crypto_OperationModeType)HSM_OPERATION_MODE_FINISH;

    }
#endif
	if (CRYPTO_HSM_INVALID_KEY_IDX != cryptoKeyIndex)
	{
		cryptoKeyMaterialElemIndex = Crypto_SearchKeyElementIdIndex(cryptoKeyIndex, CRYPTO_KE_CIPHER_KEY);
		if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX != cryptoKeyMaterialElemIndex)
		{
			if (CRYPTO_ALGOFAM_AES == algoFam)
			{
				cryptoIvElemIndex = Crypto_SearchKeyElementIdIndex(cryptoKeyIndex, CRYPTO_KE_CIPHER_IV);
				if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX != cryptoIvElemIndex)
				{
					pIV = Crypto_KeyElementList[cryptoIvElemIndex]->pCrypto_ElementArray;
				}
				else
				{
					retVal = (Std_ReturnType)E_NOT_OK;
				}
				if ((Std_ReturnType)E_OK == retVal)
				{
					if (CRYPTO_PROCESSING_SYNC == eProcessingType)
					{
						status = HSM_LLD_AesAeadEncrypt(eOptMode,Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
														HSM_AUTH_CIPHER_MODE_GCM,
														pIV,
														Crypto_KeyElementList[cryptoIvElemIndex]->u32Crypto_KeyElementActualSize,
														pJob->jobPrimitiveInputOutput.secondaryInputPtr,/* polyspace RTE:NIP */ 
														pJob->jobPrimitiveInputOutput.secondaryInputLength,/* polyspace RTE:NIV */ 
														pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */ 
														pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */ 
														pJob->jobPrimitiveInputOutput.secondaryOutputPtr,/* polyspace RTE:NIP */ 
														*(uint32_t *)pJob->jobPrimitiveInputOutput.secondaryOutputLengthPtr,/* polyspace RTE:NIV,NIP,COR,IDP */ 
														pJob->jobPrimitiveInputOutput.outputPtr/* polyspace RTE:NIP */ 
														);
						retVal = Crypto_VerifyHsmResp(status);
						if ((Std_ReturnType)E_OK == retVal)
						{
							if (*pJob->jobPrimitiveInputOutput.outputLengthPtr >= pJob->jobPrimitiveInputOutput.inputLength)/* polyspace RTE:NIV,NIP,COR,IDP */ 
							{
								*pJob->jobPrimitiveInputOutput.outputLengthPtr = pJob->jobPrimitiveInputOutput.inputLength;
							}
							else
							{
								retVal = (Std_ReturnType)CRYPTO_E_SMALL_BUFFER;
							}
						}
					}
					else if((uint16)CRYPTO_PROCESSING_ASYNC_POLLING_MODE == (uint16)eProcessingType)
					{
						status = HSM_LLD_AesAeadEncrypt_Async(eOptMode,Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
														HSM_AUTH_CIPHER_MODE_GCM,
														pIV,
														Crypto_KeyElementList[cryptoIvElemIndex]->u32Crypto_KeyElementActualSize,
														pJob->jobPrimitiveInputOutput.secondaryInputPtr,/* polyspace RTE:NIP */
														pJob->jobPrimitiveInputOutput.secondaryInputLength,/* polyspace RTE:NIV */
														pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
														pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
														pJob->jobPrimitiveInputOutput.secondaryOutputPtr,/* polyspace RTE:NIP */
														*(uint32_t *)pJob->jobPrimitiveInputOutput.secondaryOutputLengthPtr,/* polyspace RTE:IDP,NIV,NIP */
														pJob->jobPrimitiveInputOutput.outputPtr/* polyspace RTE:NIP */
														);
						retVal = Crypto_VerifyHsmResp(status);
						if ((Std_ReturnType)E_OK == retVal)
						{
							if (*pJob->jobPrimitiveInputOutput.outputLengthPtr >= pJob->jobPrimitiveInputOutput.inputLength)/* polyspace RTE:IDP,NIV,NIP */
							{
								*pJob->jobPrimitiveInputOutput.outputLengthPtr = pJob->jobPrimitiveInputOutput.inputLength;
							}
							else
							{
								retVal = (Std_ReturnType)CRYPTO_E_SMALL_BUFFER;
							}
						}

					}
					else
					{
						retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
					}
				}
			}
		}
	}

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_AeadDecrypt
(
	P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
)
{
	VAR(status_t,		  			AUTOMATIC) status            			= STATUS_HSM_GENERAL_ERRPR;
	VAR(Std_ReturnType,           	AUTOMATIC) retVal          				= (Std_ReturnType)E_OK;
	VAR(Crypto_ProcessingType,    	AUTOMATIC) eProcessingType 				= pJob->jobPrimitiveInfo->processingType;/* polyspace RTE:NIV */ 
	VAR(Crypto_AlgorithmFamilyType, AUTOMATIC) algoFam						= pJob->jobPrimitiveInfo->primitiveInfo->algorithm.family;/* polyspace RTE:NIV */ 
	VAR(uint32, 					AUTOMATIC) cryptoKeyIndex  		 		= Crypto_SearchKeyIdIndex(pJob->jobPrimitiveInfo->cryIfKeyId);/* polyspace RTE:NIV */ 
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pIV 						= NULL_PTR;
	VAR(uint32,				    	AUTOMATIC) cryptoKeyMaterialElemIndex;
	VAR(uint32,				    	AUTOMATIC) cryptoIvElemIndex;
    VAR (Crypto_OperationModeType, AUTOMATIC) eOptMode                      = pJob->jobPrimitiveInputOutput.mode;/* polyspace RTE:NIV */

    if(eOptMode==CRYPTO_OPERATIONMODE_SINGLECALL)
    {

    	eOptMode= (Crypto_OperationModeType)HSM_OPERATION_MODE_SINGLE_CALL;			/* PRQA S 4342 */

    }
    else
    {
    	/*Stream mode not supported*/

    	retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;

    }

#if 0
    if(eOptMode==CRYPTO_OPERATIONMODE_FINISH)
    {

    	eOptMode= (Crypto_OperationModeType)HSM_OPERATION_MODE_FINISH;

    }
#endif

	if (CRYPTO_HSM_INVALID_KEY_IDX != cryptoKeyIndex)
	{
		cryptoKeyMaterialElemIndex = Crypto_SearchKeyElementIdIndex(cryptoKeyIndex, CRYPTO_KE_CIPHER_KEY);
		if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX != cryptoKeyMaterialElemIndex)
		{
			if (CRYPTO_ALGOFAM_AES == algoFam)
			{
				cryptoIvElemIndex = Crypto_SearchKeyElementIdIndex(cryptoKeyIndex, CRYPTO_KE_CIPHER_IV);
				if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX != cryptoIvElemIndex)
				{
					pIV = Crypto_KeyElementList[cryptoIvElemIndex]->pCrypto_ElementArray;
				}
				else
				{
					retVal = (Std_ReturnType)E_NOT_OK;
				}
				if ((Std_ReturnType)E_OK == retVal)
				{
					if (CRYPTO_PROCESSING_SYNC == eProcessingType)
					{
						status = HSM_LLD_AesAeadDecrypt(eOptMode,Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
														HSM_AUTH_CIPHER_MODE_GCM,
														pIV,
														Crypto_KeyElementList[cryptoIvElemIndex]->u32Crypto_KeyElementActualSize,
														pJob->jobPrimitiveInputOutput.secondaryInputPtr,/* polyspace RTE:NIP */ 
														pJob->jobPrimitiveInputOutput.secondaryInputLength,/* polyspace RTE:NIV */ 
														pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */ 
														pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */ 
														pJob->jobPrimitiveInputOutput.tertiaryInputPtr,/* polyspace RTE:NIP */ 
														pJob->jobPrimitiveInputOutput.tertiaryInputLength,/* polyspace RTE:NIV */ 
														pJob->jobPrimitiveInputOutput.outputPtr/* polyspace RTE:NIP */ 
														);
						retVal = Crypto_VerifyHsmResp(status);
						if ((Std_ReturnType)E_OK == retVal)
						{
							*pJob->jobPrimitiveInputOutput.verifyPtr = CRYPTO_E_VER_OK;/* polyspace RTE:NIP,COR,IDP */ 

							if (*pJob->jobPrimitiveInputOutput.outputLengthPtr >= pJob->jobPrimitiveInputOutput.inputLength)/* polyspace RTE:NIV,NIP,COR,IDP */ 
							{
								*pJob->jobPrimitiveInputOutput.outputLengthPtr = pJob->jobPrimitiveInputOutput.inputLength;
							}
							else
							{
								retVal = (Std_ReturnType)CRYPTO_E_SMALL_BUFFER;
							}
						}
						else
						{
							*pJob->jobPrimitiveInputOutput.verifyPtr = CRYPTO_E_VER_NOT_OK;/* polyspace RTE:IDP,NIP */
						}
					}
					else if((uint16)CRYPTO_PROCESSING_ASYNC_POLLING_MODE == (uint16)eProcessingType)
					{
						status = HSM_LLD_AesAeadDecrypt_Async(eOptMode,Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
														HSM_AUTH_CIPHER_MODE_GCM,
														pIV,
														Crypto_KeyElementList[cryptoIvElemIndex]->u32Crypto_KeyElementActualSize,
														pJob->jobPrimitiveInputOutput.secondaryInputPtr,/* polyspace RTE:NIP */
														pJob->jobPrimitiveInputOutput.secondaryInputLength,/* polyspace RTE:NIV */
														pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
														pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
														pJob->jobPrimitiveInputOutput.tertiaryInputPtr,/* polyspace RTE:NIP */
														pJob->jobPrimitiveInputOutput.tertiaryInputLength,/* polyspace RTE:NIV,NIP */
														pJob->jobPrimitiveInputOutput.outputPtr/* polyspace RTE:NIP */
														);
						retVal = Crypto_VerifyHsmResp(status);
						if ((Std_ReturnType)E_OK == retVal)
						{
							*pJob->jobPrimitiveInputOutput.verifyPtr = CRYPTO_E_VER_OK;/* polyspace RTE:IDP,NIV,NIP */

							if (*pJob->jobPrimitiveInputOutput.outputLengthPtr >= pJob->jobPrimitiveInputOutput.inputLength)/* polyspace RTE:IDP,NIV,NIP */
							{
								*pJob->jobPrimitiveInputOutput.outputLengthPtr = pJob->jobPrimitiveInputOutput.inputLength;
							}
							else
							{
								retVal = (Std_ReturnType)CRYPTO_E_SMALL_BUFFER;
							}
						}
						else
						{
							*pJob->jobPrimitiveInputOutput.verifyPtr = CRYPTO_E_VER_NOT_OK;/* polyspace RTE:IDP,NIP */
						}
					}
					else
					{
						retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
					}
				}
			}
		}
	}

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_SignatureGenerate
(
	P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
)
{
	VAR(status_t,		  			AUTOMATIC) status            = STATUS_HSM_GENERAL_ERRPR;
    VAR(Std_ReturnType,           	AUTOMATIC) retVal            = (Std_ReturnType)E_NOT_OK;
    VAR(Crypto_ProcessingType,    	AUTOMATIC) eProcessingType   = pJob->jobPrimitiveInfo->processingType;/* polyspace RTE:NIV */ 
    VAR(Crypto_AlgorithmFamilyType, AUTOMATIC) algoFam			 = pJob->jobPrimitiveInfo->primitiveInfo->algorithm.family;/* polyspace RTE:NIV */ 
    VAR(Crypto_AlgorithmFamilyType, AUTOMATIC) secondaryAlgoFam  = pJob->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily;/* polyspace RTE:NIV */ 
    VAR(Crypto_AlgorithmModeType, 	AUTOMATIC) algoMode		     = pJob->jobPrimitiveInfo->primitiveInfo->algorithm.mode;/* polyspace RTE:NIV */ 
    VAR(uint32, 					AUTOMATIC) cryptoKeyIndex  	 = Crypto_SearchKeyIdIndex(pJob->jobPrimitiveInfo->cryIfKeyId);/* polyspace RTE:NIV */ 
    VAR(hsmHashAlgo_t,				AUTOMATIC) hashAlgo = (hsmHashAlgo_t)HSM_HASH_ALGO_NOT_SET;
    VAR(uint32,				    	AUTOMATIC) cryptoKeyMaterialElemIndex;
    VAR(uint32,						ATUOMATIC) signRLen = 0;
    VAR(uint32,						ATUOMATIC) signSLen = 0;
    VAR(uint32,						ATUOMATIC) saltLen = 0;

    if (CRYPTO_HSM_INVALID_KEY_IDX != cryptoKeyIndex)
    {
    	cryptoKeyMaterialElemIndex = Crypto_SearchKeyElementIdIndex(cryptoKeyIndex, CRYPTO_KE_SIGNATURE_KEY);
    	if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX != cryptoKeyMaterialElemIndex)
    	{
    		if (CRYPTO_ALGOFAM_RSA == algoFam)
    		{
    			retVal = (Std_ReturnType)E_OK;

        		switch (secondaryAlgoFam)
        		{
        			case CRYPTO_ALGOFAM_SHA1:
        				hashAlgo = HSM_HASH_ALGO_SHA1;
        				saltLen = 20U;
        				break;
        			case CRYPTO_ALGOFAM_SHA2_224:
        				if(CRYPTO_ALGOMODE_RSASSA_PSS == algoMode)
        				{
               				hashAlgo = HSM_HASH_ALGO_SHA2_224;
                			saltLen = 28U;
        				}
        				else if(CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5 == algoMode)
        				{
        					retVal = (Std_ReturnType)CRYPTO_E_INVALID_PARAM;
        				}
                        else
                        {
                            /* do nothing */
                        }
        				break;
        			case CRYPTO_ALGOFAM_SHA2_256:
        				hashAlgo = HSM_HASH_ALGO_SHA2_256;
        				saltLen = 32U;
        				break;
        			case CRYPTO_ALGOFAM_SHA2_384:
        				hashAlgo = HSM_HASH_ALGO_SHA2_384;
        				saltLen = 48U;
        				break;
        			case CRYPTO_ALGOFAM_SHA2_512:
        				hashAlgo = HSM_HASH_ALGO_SHA2_512;
        				saltLen = 64U;
        				break;
        			default:
        				retVal = (Std_ReturnType)CRYPTO_E_INVALID_PARAM;
        				break;

        		}
    			if ((Std_ReturnType)E_OK == retVal)
    			{
    				if (*pJob->jobPrimitiveInputOutput.outputLengthPtr >= (Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyBits >> 3))/* polyspace RTE:NIV,NIP,COR,IDP */ 
					{
						if (CRYPTO_PROCESSING_SYNC == eProcessingType)
						{
							if (CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5 == algoMode)
							{


								status = HSM_LLD_RsaPkcs1V15GenerateSignature(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
																			  hashAlgo,
																			  pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */ 
																			  pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */ 
																			  FALSE,
																			  pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */ 
																			  pJob->jobPrimitiveInputOutput.outputLengthPtr);
								retVal = Crypto_VerifyHsmResp(status);
							}
							else if (CRYPTO_ALGOMODE_RSASSA_PSS == algoMode)
							{
								status = HSM_LLD_RsaPssGenerateSignature(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
																			  hashAlgo,
																			  saltLen,
																			  pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
																			  pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
																			  FALSE,
																			  pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */
																			  pJob->jobPrimitiveInputOutput.outputLengthPtr);
								retVal = Crypto_VerifyHsmResp(status);
							}
							else
							{
								retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
							}
						}
						else if((uint16)CRYPTO_PROCESSING_ASYNC_POLLING_MODE == (uint16)eProcessingType)
						{
							if (CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5 == algoMode)
							{


								status = HSM_LLD_RsaPkcs1V15GenerateSignature_Async(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
																			  hashAlgo,
																			  pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
																			  pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
																			  FALSE,
																			  pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */
																			  pJob->jobPrimitiveInputOutput.outputLengthPtr);
								retVal = Crypto_VerifyHsmResp(status);
							}
							else if (CRYPTO_ALGOMODE_RSASSA_PSS == algoMode)
							{
								status = HSM_LLD_RsaPssGenerateSignature_Async(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
																			  hashAlgo,
																			  saltLen,
																			  pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
																			  pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
																			  FALSE,
																			  pJob->jobPrimitiveInputOutput.outputPtr,/* polyspace RTE:NIP */
																			  pJob->jobPrimitiveInputOutput.outputLengthPtr);
								retVal = Crypto_VerifyHsmResp(status);
							}
							else
							{
								retVal = (Std_ReturnType)CRYPTO_E_INVALID_PARAM;
							}

						}
						else
						{
							retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
						}
					}
					else
					{
						retVal = (Std_ReturnType)CRYPTO_E_SMALL_BUFFER;
					}
    			}
    		}
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
    		else if (CRYPTO_ALGOFAM_SM2 == algoFam)
    		{
				if (*pJob->jobPrimitiveInputOutput.outputLengthPtr >= (Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyBits >> 2))/* polyspace RTE:NIV,NIP,COR,IDP */ 
				{
					if (CRYPTO_PROCESSING_SYNC == eProcessingType)
					{
						status = HSM_LLD_Sm2GenerateSignature(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
															  pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */ 
															  pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */ 
															  FALSE,
															  &pJob->jobPrimitiveInputOutput.outputPtr[0],/* polyspace RTE:NIP */ 
															  (uint32 *)&signRLen,
															  &pJob->jobPrimitiveInputOutput.outputPtr[Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyBits >> 3],
															  (uint32 *)&signSLen);
						retVal = Crypto_VerifyHsmResp(status);
						if ((Std_ReturnType)E_OK == retVal)
						{
							*pJob->jobPrimitiveInputOutput.outputLengthPtr = signRLen + signSLen;
						}
					}
					else if(CRYPTO_PROCESSING_ASYNC_POLLING_MODE == eProcessingType)
					{
						status = HSM_LLD_Sm2GenerateSignature_Async(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
															  pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
															  pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
															  FALSE,
															  &pJob->jobPrimitiveInputOutput.outputPtr[0],/* polyspace RTE:NIP */
															  (uint32 *)&signRLen,
															  &pJob->jobPrimitiveInputOutput.outputPtr[Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyBits >> 3],
															  (uint32 *)&signSLen);
						retVal = Crypto_VerifyHsmResp(status);
						if ((Std_ReturnType)E_OK == retVal)
						{
							*pJob->jobPrimitiveInputOutput.outputLengthPtr = 64;//signRLen + signSLen;
						}

					}
					else
					{
						retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
					}
				}
				else
				{
					retVal = (Std_ReturnType)CRYPTO_E_SMALL_BUFFER;
				}
    		}
#endif
    		else if (CRYPTO_ALGOFAM_ECDSA == algoFam)
    		{
      			retVal = (Std_ReturnType)E_OK;

				switch (secondaryAlgoFam)
				{
					case CRYPTO_ALGOFAM_SHA1: hashAlgo = HSM_HASH_ALGO_SHA1; break;
					case CRYPTO_ALGOFAM_SHA2_224: hashAlgo = HSM_HASH_ALGO_SHA2_224; break;
					case CRYPTO_ALGOFAM_SHA2_256: hashAlgo = HSM_HASH_ALGO_SHA2_256; break;
					case CRYPTO_ALGOFAM_SHA2_384: hashAlgo = HSM_HASH_ALGO_SHA2_384; break;
					case CRYPTO_ALGOFAM_SHA2_512: hashAlgo = HSM_HASH_ALGO_SHA2_512; break;
					default:
						retVal = (Std_ReturnType)CRYPTO_E_INVALID_PARAM;
						break;
				}
				if ((Std_ReturnType)E_OK == retVal)
				{
					if (*pJob->jobPrimitiveInputOutput.outputLengthPtr >= (Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyBits >> 2))/* polyspace RTE:NIV,NIP,COR,IDP */ 
					{
						if (CRYPTO_PROCESSING_SYNC == eProcessingType)
						{
							status = HSM_LLD_EcdsaGenerateSignature(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
																	hashAlgo,
																  	pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */ 
																	pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */ 
																	FALSE,
																	&pJob->jobPrimitiveInputOutput.outputPtr[0],/* polyspace RTE:NIP */ 
																	(uint32 *)&signRLen,
																	&pJob->jobPrimitiveInputOutput.outputPtr[Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyBits >> 3],
																	(uint32 *)&signSLen);
							retVal = Crypto_VerifyHsmResp(status);
							if ((Std_ReturnType)E_OK == retVal)
							{
								*pJob->jobPrimitiveInputOutput.outputLengthPtr = signRLen + signSLen;
							}
						}
						else if((uint16)CRYPTO_PROCESSING_ASYNC_POLLING_MODE == (uint16)eProcessingType)
						{
							status = HSM_LLD_EcdsaGenerateSignature_Async(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
																	hashAlgo,
																  	pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
																	pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
																	FALSE,
																	&pJob->jobPrimitiveInputOutput.outputPtr[0],/* polyspace RTE:NIP */
																	(uint32 *)&signRLen,
																	&pJob->jobPrimitiveInputOutput.outputPtr[Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyBits >> 3],
																	(uint32 *)&signSLen);
							retVal = Crypto_VerifyHsmResp(status);
							if ((Std_ReturnType)E_OK == retVal)
							{
								*pJob->jobPrimitiveInputOutput.outputLengthPtr = 64;//signRLen + signSLen;
							}


						}
						else
						{
							retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
						}
					}
					else
					{
						retVal = (Std_ReturnType)CRYPTO_E_SMALL_BUFFER;
					}
				}
    		}
#if defined(RESOURCE_SUPPORT_CRYPTO_EB4)
    		else if(CRYPTO_ALGOFAM_ED25519 == algoFam)
    		{
				if (CRYPTO_PROCESSING_SYNC == eProcessingType)
				{
	      			retVal = (Std_ReturnType)E_OK;

					switch (secondaryAlgoFam)
					{
						case CRYPTO_ALGOFAM_SHA1: hashAlgo = HSM_HASH_ALGO_SHA1; break;
						case CRYPTO_ALGOFAM_SHA2_224: hashAlgo = HSM_HASH_ALGO_SHA2_224; break;
						case CRYPTO_ALGOFAM_SHA2_256: hashAlgo = HSM_HASH_ALGO_SHA2_256; break;
						case CRYPTO_ALGOFAM_SHA2_384: hashAlgo = HSM_HASH_ALGO_SHA2_384; break;
						case CRYPTO_ALGOFAM_SHA2_512: hashAlgo = HSM_HASH_ALGO_SHA2_512; break;
						default:
							retVal = (Std_ReturnType)CRYPTO_E_INVALID_PARAM;
							break;
					}

					if ((Std_ReturnType)E_OK == retVal)
					{
						status = HSM_LLD_ED25519GenerateSignature(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
															  hashAlgo,
															  pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
															  pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
															  FALSE,
															  &pJob->jobPrimitiveInputOutput.outputPtr[0],/* polyspace RTE:NIP */
															  (uint32 *)&signRLen,
															  &pJob->jobPrimitiveInputOutput.outputPtr[Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyBits >> 3],
															  (uint32 *)&signSLen);
						retVal = Crypto_VerifyHsmResp(status);
						if ((Std_ReturnType)E_OK == retVal)
						{
							*pJob->jobPrimitiveInputOutput.outputLengthPtr = 64;
						}

					}

				}

    		}
#endif
    		else
    		{
    			retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
    		}
    	}
    }

    return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_SignatureVerify
(
	P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
)
{
	VAR(status_t,		  			AUTOMATIC) status            = STATUS_HSM_GENERAL_ERRPR;
    VAR(Std_ReturnType,           	AUTOMATIC) retVal            = (Std_ReturnType)E_NOT_OK;
    VAR(Crypto_ProcessingType,    	AUTOMATIC) eProcessingType   = pJob->jobPrimitiveInfo->processingType;/* polyspace RTE:NIV */  
    VAR(Crypto_AlgorithmFamilyType, AUTOMATIC) algoFam			 = pJob->jobPrimitiveInfo->primitiveInfo->algorithm.family;/* polyspace RTE:NIV */  
    VAR(Crypto_AlgorithmFamilyType, AUTOMATIC) secondaryAlgoFam  = pJob->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily;/* polyspace RTE:NIV */  
    VAR(Crypto_AlgorithmModeType, 	AUTOMATIC) algoMode		     = pJob->jobPrimitiveInfo->primitiveInfo->algorithm.mode;/* polyspace RTE:NIV */  
    VAR(uint32, 					AUTOMATIC) cryptoKeyIndex  	 = Crypto_SearchKeyIdIndex(pJob->jobPrimitiveInfo->cryIfKeyId);/* polyspace RTE:NIV */  
    VAR(hsmHashAlgo_t,				AUTOMATIC) hashAlgo = (hsmHashAlgo_t)HSM_HASH_ALGO_NOT_SET;
    VAR(uint32,				    	AUTOMATIC) cryptoKeyMaterialElemIndex;
    VAR(static uint32,						ATUOMATIC) signRLen;
    VAR(static uint32,						ATUOMATIC) signSLen;
    VAR(uint32,						ATUOMATIC) saltLen = 0;

    if (CRYPTO_HSM_INVALID_KEY_IDX != cryptoKeyIndex)
    {
    	cryptoKeyMaterialElemIndex = Crypto_SearchKeyElementIdIndex(cryptoKeyIndex, CRYPTO_KE_SIGNATURE_KEY);
    	if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX != cryptoKeyMaterialElemIndex)
    	{
    		if (CRYPTO_ALGOFAM_RSA == algoFam)
    		{
    			retVal = (Std_ReturnType)E_OK;

        		switch (secondaryAlgoFam)
        		{
					case CRYPTO_ALGOFAM_SHA1:
						hashAlgo = HSM_HASH_ALGO_SHA1;
						saltLen = 20U;
						break;
        			case CRYPTO_ALGOFAM_SHA2_224:
        				if(CRYPTO_ALGOMODE_RSASSA_PSS == algoMode)
        				{
               				hashAlgo = HSM_HASH_ALGO_SHA2_224;
                			saltLen = 28U;
        				}
        				else if(CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5 == algoMode)
        				{
        					retVal = (Std_ReturnType)CRYPTO_E_INVALID_PARAM;
        				}
                        else
                        {
                            /* do nothing */
                        }
        				break;
					case CRYPTO_ALGOFAM_SHA2_256:
						hashAlgo = HSM_HASH_ALGO_SHA2_256;
						saltLen = 32U;
						break;
					case CRYPTO_ALGOFAM_SHA2_384:
						hashAlgo = HSM_HASH_ALGO_SHA2_384;
						saltLen = 48U;
						break;
					case CRYPTO_ALGOFAM_SHA2_512:
						hashAlgo = HSM_HASH_ALGO_SHA2_512;
						saltLen = 64U;
						break;
        			default:
        				retVal = (Std_ReturnType)CRYPTO_E_INVALID_PARAM;
        				break;

        		}
    			if ((Std_ReturnType)E_OK == retVal)
    			{
					if (CRYPTO_PROCESSING_SYNC == eProcessingType)
					{
						if (CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5 == algoMode)
						{
							status = HSM_LLD_RsaPkcs1V15VerifySignature(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
																		hashAlgo,
																		pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
																		pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
																		FALSE,
																		pJob->jobPrimitiveInputOutput.secondaryInputPtr,/* polyspace RTE:NIP */
																		(uint32 *)&pJob->jobPrimitiveInputOutput.secondaryInputLength,
																		(uint32*)pJob->jobPrimitiveInputOutput.verifyPtr);/* polyspace RTE:NIP */
							retVal = Crypto_VerifyHsmResp(status);
						}
						else if (CRYPTO_ALGOMODE_RSASSA_PSS == algoMode)
						{
							status = HSM_LLD_RsaPssVerifySignature(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
																		hashAlgo,
																		saltLen,
																		pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
																		pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
																		FALSE,
																		pJob->jobPrimitiveInputOutput.secondaryInputPtr,/* polyspace RTE:NIP */
																		(uint32 *)&pJob->jobPrimitiveInputOutput.secondaryInputLength,
																		(uint32*)pJob->jobPrimitiveInputOutput.verifyPtr);/* polyspace RTE:NIP */
							retVal = Crypto_VerifyHsmResp(status);
						}
						else
						{
							retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
						}
					}
					else if((uint16)CRYPTO_PROCESSING_ASYNC_POLLING_MODE == (uint16)eProcessingType)
					{
						if (CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5 == algoMode)
						{
							status = HSM_LLD_RsaPkcs1V15VerifySignature_Async(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
																		hashAlgo,
																		pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
																		pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
																		FALSE,
																		pJob->jobPrimitiveInputOutput.secondaryInputPtr,/* polyspace RTE:NIP */ 
																		(uint32 *)&pJob->jobPrimitiveInputOutput.secondaryInputLength,
																		(uint32*)pJob->jobPrimitiveInputOutput.verifyPtr);/* polyspace RTE:NIP */
							retVal = Crypto_VerifyHsmResp(status);
						}
						else if (CRYPTO_ALGOMODE_RSASSA_PSS == algoMode)
						{
							status = HSM_LLD_RsaPssVerifySignature_Async(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
																		hashAlgo,
																		saltLen,
																		pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
																		pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
																		FALSE,
																		pJob->jobPrimitiveInputOutput.secondaryInputPtr,/* polyspace RTE:NIP */
																		(uint32 *)&pJob->jobPrimitiveInputOutput.secondaryInputLength,
																		(uint32*)pJob->jobPrimitiveInputOutput.verifyPtr);/* polyspace RTE:NIP */
							retVal = Crypto_VerifyHsmResp(status);
						}
						else
						{
							retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
						}

					}
					else
					{
						retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
					}
    			}
    		}
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
    		else if (CRYPTO_ALGOFAM_SM2 == algoFam)
    		{
				if (CRYPTO_PROCESSING_SYNC == eProcessingType)
				{
					signRLen = pJob->jobPrimitiveInputOutput.secondaryInputLength >> 1;/* polyspace RTE:NIV */  
					signSLen = pJob->jobPrimitiveInputOutput.secondaryInputLength >> 1;

					status = HSM_LLD_Sm2VerifySignature(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
														  pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
														  pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
														  FALSE,
														  &pJob->jobPrimitiveInputOutput.secondaryInputPtr[0],/* polyspace RTE:NIP */
														  &signRLen,
														  &pJob->jobPrimitiveInputOutput.secondaryInputPtr[pJob->jobPrimitiveInputOutput.secondaryInputLength >> 1],
														  &signSLen,
														  (uint32*)pJob->jobPrimitiveInputOutput.verifyPtr);/* polyspace RTE:NIP */
					retVal = Crypto_VerifyHsmResp(status);

				}
				else if(CRYPTO_PROCESSING_ASYNC_POLLING_MODE == eProcessingType)
				{
					signRLen = pJob->jobPrimitiveInputOutput.secondaryInputLength >> 1;/* polyspace RTE:NIV */
					signSLen = pJob->jobPrimitiveInputOutput.secondaryInputLength >> 1;

					status = HSM_LLD_Sm2VerifySignature_Async(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
														  pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
														  pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
														  FALSE,
														  &pJob->jobPrimitiveInputOutput.secondaryInputPtr[0],/* polyspace RTE:NIP */ 
														  &signRLen,
														  &pJob->jobPrimitiveInputOutput.secondaryInputPtr[pJob->jobPrimitiveInputOutput.secondaryInputLength >> 1],
														  &signSLen,
														  (uint32*)pJob->jobPrimitiveInputOutput.verifyPtr);/* polyspace RTE:NIP */
					retVal = Crypto_VerifyHsmResp(status);

				}
				else
				{
					retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
				}
    		}
#endif
    		else if (CRYPTO_ALGOFAM_ECDSA == algoFam)
			{
				retVal = (Std_ReturnType)E_OK;

				switch (secondaryAlgoFam)
				{
					case CRYPTO_ALGOFAM_SHA1: hashAlgo = HSM_HASH_ALGO_SHA1; break;
					case CRYPTO_ALGOFAM_SHA2_224: hashAlgo = HSM_HASH_ALGO_SHA2_224; break;
					case CRYPTO_ALGOFAM_SHA2_256: hashAlgo = HSM_HASH_ALGO_SHA2_256; break;
					case CRYPTO_ALGOFAM_SHA2_384: hashAlgo = HSM_HASH_ALGO_SHA2_384; break;
					case CRYPTO_ALGOFAM_SHA2_512: hashAlgo = HSM_HASH_ALGO_SHA2_512; break;
					default:
						retVal = (Std_ReturnType)CRYPTO_E_INVALID_PARAM;
						break;
				}
				if ((Std_ReturnType)E_OK == retVal)
				{
					if (CRYPTO_PROCESSING_SYNC == eProcessingType)
					{
						signRLen = pJob->jobPrimitiveInputOutput.secondaryInputLength >> 1;/* polyspace RTE:NIV */ 
						signSLen = pJob->jobPrimitiveInputOutput.secondaryInputLength >> 1;

						status = HSM_LLD_EcdsaVerifySignature(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
															  hashAlgo,
															  pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
															  pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
															  FALSE,
															  &pJob->jobPrimitiveInputOutput.secondaryInputPtr[0],/* polyspace RTE:NIP */
															  &signRLen,
															  &pJob->jobPrimitiveInputOutput.secondaryInputPtr[pJob->jobPrimitiveInputOutput.secondaryInputLength >> 1],
															  &signSLen,
															  (uint32*)pJob->jobPrimitiveInputOutput.verifyPtr);/* polyspace RTE:NIP */
						retVal = Crypto_VerifyHsmResp(status);

					}
					else if((uint16)CRYPTO_PROCESSING_ASYNC_POLLING_MODE == (uint16)eProcessingType)
					{
						signRLen = pJob->jobPrimitiveInputOutput.secondaryInputLength >> 1;/* polyspace RTE:NIV */
						signSLen = pJob->jobPrimitiveInputOutput.secondaryInputLength >> 1;

						status = HSM_LLD_EcdsaVerifySignature_Async(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
															  hashAlgo,
															  pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
															  pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
															  FALSE,
															  &pJob->jobPrimitiveInputOutput.secondaryInputPtr[0],/* polyspace RTE:NIP */ 
															  &signRLen,
															  &pJob->jobPrimitiveInputOutput.secondaryInputPtr[pJob->jobPrimitiveInputOutput.secondaryInputLength >> 1],
															  &signSLen,
															  (uint32*)pJob->jobPrimitiveInputOutput.verifyPtr);/* polyspace RTE:NIP */
						retVal = Crypto_VerifyHsmResp(status);

					}
					else
					{
						retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
					}
				}
			}
#if defined(RESOURCE_SUPPORT_CRYPTO_EB4)
    		else if(CRYPTO_ALGOFAM_ED25519 == algoFam)
    		{
				retVal = (Std_ReturnType)E_OK;
				if ((Std_ReturnType)E_OK == retVal)
				{
					if (CRYPTO_PROCESSING_SYNC == eProcessingType)
					{

						retVal = (Std_ReturnType)E_OK;

						switch (secondaryAlgoFam)
						{
							case CRYPTO_ALGOFAM_SHA1: hashAlgo = HSM_HASH_ALGO_SHA1; break;
							case CRYPTO_ALGOFAM_SHA2_224: hashAlgo = HSM_HASH_ALGO_SHA2_224; break;
							case CRYPTO_ALGOFAM_SHA2_256: hashAlgo = HSM_HASH_ALGO_SHA2_256; break;
							case CRYPTO_ALGOFAM_SHA2_384: hashAlgo = HSM_HASH_ALGO_SHA2_384; break;
							case CRYPTO_ALGOFAM_SHA2_512: hashAlgo = HSM_HASH_ALGO_SHA2_512; break;
							default:
								retVal = (Std_ReturnType)CRYPTO_E_INVALID_PARAM;
								break;
						}

						if ((Std_ReturnType)E_OK == retVal)
						{
							signRLen = pJob->jobPrimitiveInputOutput.secondaryInputLength >> 1;/* polyspace RTE:NIV */
							signSLen = pJob->jobPrimitiveInputOutput.secondaryInputLength >> 1;

							status = HSM_LLD_ED25519VerifySignature(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle,
																  hashAlgo,
																  pJob->jobPrimitiveInputOutput.inputPtr,/* polyspace RTE:NIP */
																  pJob->jobPrimitiveInputOutput.inputLength,/* polyspace RTE:NIV */
																  FALSE,
																  &pJob->jobPrimitiveInputOutput.secondaryInputPtr[0],/* polyspace RTE:NIP */
																  &signRLen,
																  &pJob->jobPrimitiveInputOutput.secondaryInputPtr[pJob->jobPrimitiveInputOutput.secondaryInputLength >> 1],
																  &signSLen,
																  (uint32*)pJob->jobPrimitiveInputOutput.verifyPtr);/* polyspace RTE:NIP */
							retVal = Crypto_VerifyHsmResp(status);

						}

					}
				}
				else
				{
					retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
				}
    		}
#endif
    		else
    		{
    			retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
    		}
    	}
    }
#if 0
    if ((Std_ReturnType)E_OK == retVal)
    {
    	if (TRUE == verifyStatus)
    	{
    		*pJob->jobPrimitiveInputOutput.verifyPtr = CRYPTO_E_VER_OK;/* polyspace RTE:NIP,COR */ 
    	}
    	else
    	{
    		*pJob->jobPrimitiveInputOutput.verifyPtr = CRYPTO_E_VER_NOT_OK;/* polyspace RTE:NIP,COR */ 
    	}
    }
#endif

    return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
