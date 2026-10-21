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
*   @file    Crypto.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Crypto MCAL driver.
*
*   @addtogroup Crypto
*   @{
*/
/*PRQA S 3119, 3432, 2053, 0380, 3408, 3200, 1258, 2844, 0491, 3400, 3401, 3397,1594 EOF*/
/*PRQA S 2004, 1843, 2212, 4322, 0498, 1842, 2842, 2852, 2843, 3397, 2843, 1514, 1756 EOF*/
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Crypto.h"
#include "CryIf_Cbk.h"
#include "Crypto_AutoSar_Wrapper.h"
#include "Crypto_Common.h"
#if (CRYPTO_DET_ERROR_REPORT == STD_ON)
#include "Det.h"
#endif

#define CRYPTO_START_SEC_VAR_INIT
#include "Crypto_MemMap.h"
static VAR(Crypto_DriverStateType, AUTOMATIC) g_Crypto_DriverStatus = CRYPTO_UNINIT;
#define CRYPTO_STOP_SEC_VAR_INIT
#include "Crypto_MemMap.h"
#define CRYPTO_START_SEC_VAR_INIT
#include "Crypto_MemMap.h"
P2CONST(Crypto_ConfigType, AUTOMATIC, CRYPTO_APPL_CONST) Crypto_ConfigPtr = NULL_PTR;
#define CRYPTO_STOP_SEC_VAR_INIT
#include "Crypto_MemMap.h"
extern P2VAR(Crypto_ObjectType, AUTOMATIC, CRYPTO_APPL_DATA) pCrypto_ObjectJobList[CRYPTO_NUMBER_OF_DRIVER_OBJECTS];

#if (CRYPTO_DET_ERROR_REPORT == STD_ON)
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
CRYPTO_INLINE FUNC(void, CRYPTO_CODE) Crypto_ReportError
(
    VAR(uint8, AUTOMATIC) u8Crypto_ServiceId,
    VAR(uint8, AUTOMATIC) u8Crypto_ErrorId
)
{

    (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, u8Crypto_ServiceId, u8Crypto_ErrorId);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
CRYPTO_INLINE FUNC(void, CRYPTO_APPL_CODE) Crypto_ReportRuntimeError
(
    VAR(uint8, AUTOMATIC) u8Crypto_ServiceId,
    VAR(uint8, AUTOMATIC) u8Crypto_ErrorId
)
{
    (void)Det_ReportRuntimeError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, u8Crypto_ServiceId, u8Crypto_ErrorId);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
CRYPTO_INLINE FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_VerifyKeyValidity
(
    P2VAR (Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
)
{
	VAR(Crypto_ServiceInfoType, AUTOMATIC) eJobService = pJob->jobPrimitiveInfo->primitiveInfo->service;
	VAR(Std_ReturnType, 		AUTOMATIC) retVal = (Std_ReturnType)E_OK;
	VAR(uint32, 			    AUTOMATIC) u32CryptoKeyIndex = Crypto_SearchKeyIdIndex(pJob->jobPrimitiveInfo->cryIfKeyId);

	if ((eJobService != CRYPTO_HASH) 		   &&
		(eJobService != CRYPTO_RANDOMGENERATE) &&
	    (eJobService != CRYPTO_RANDOMSEED))

	{
		if ((CRYPTO_HSM_INVALID_KEY_IDX == u32CryptoKeyIndex)||((CRYPTO_HSM_INVALID_KEY_IDX != u32CryptoKeyIndex)&&(FALSE == Crypto_KeyList[u32CryptoKeyIndex]->bCrypto_KeyValid)))/* PRQA S 2995 */
		{

			retVal = (Std_ReturnType)CRYPTO_E_KEY_NOT_VALID;

		}
	}
	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#if (CRYPTO_DET_ERROR_REPORT == STD_ON)

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
CRYPTO_INLINE FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_CheckServiceSupport
(
    P2CONST(Crypto_PrimitiveInfoType, CRYPTO_CONST, CRYPTO_APPL_CONST) pJobPrimitiveInfo,
    P2CONST(Crypto_PrimitiveType, CRYPTO_CONST, CRYPTO_APPL_CONST) pObjPrimitive
)
{
    VAR(Std_ReturnType, CRYPTO_VAR) retVal = E_NOT_OK;

    switch (pJobPrimitiveInfo->service)
    {
        case CRYPTO_HASH: /* Hash Service */
        case CRYPTO_MACGENERATE: /* MacGenerate Service */
        case CRYPTO_MACVERIFY: /* MacVerify Service */
        case CRYPTO_ENCRYPT: /* Encrypt Service */
        case CRYPTO_DECRYPT: /* Decrypt Service */
        case CRYPTO_AEADENCRYPT: /* AEADEncrypt Service */
        case CRYPTO_AEADDECRYPT: /* AEADDecrypt Service */
        case CRYPTO_SIGNATUREGENERATE: /* SignatureGenerate Service */
        case CRYPTO_SIGNATUREVERIFY: /* SignatureVerify Service */
        case CRYPTO_RANDOMGENERATE: /* RandomGenerate Service */
            retVal = E_OK;
            break;
        case CRYPTO_RANDOMSEED:  /* RandomSeed Service */
        case CRYPTO_KEYGENERATE:/* KeyGenerate Service */
        case CRYPTO_KEYDERIVE:/* KeyDerive Service */
        case CRYPTO_KEYEXCHANGECALCPUBVAL : /* KeyExchangeCalcPubVaL Service */
        case CRYPTO_KEYEXCHANGECALCSECRET : /* KeyExchangeCalcSecret Service */
        case CRYPTO_CERTIFICATEPARSE		 :  /* CertificiateParse Service */
        case CRYPTO_CERTIFICATEVERIFY	 :  /* CertificateVerify Service */
        case CRYPTO_KEYSETVALID           :  /* KeySetValid Service */
        	retVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
        	break;

        default:
            /* not support */
            break;
    }

    if ((Std_ReturnType)E_OK == retVal)
    {
        if (pJobPrimitiveInfo->service != pObjPrimitive->eCrypto_Service)/* polyspace RTE:COR,IDP,NIV */
        {
            retVal = E_NOT_OK;
        }
    }

    return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
CRYPTO_INLINE FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_VerifyPrimitive
(
    VAR (uint32, CRYPTO_VAR) u32ObjectIndex,
    P2VAR (Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
)
{
    VAR(uint32, 				      AUTOMATIC				      ) counter = 0;
    VAR(Std_ReturnType, 			  AUTOMATIC				  	  ) retVal = (Std_ReturnType)E_NOT_OK;
    P2CONST(Crypto_PrimitiveType,     AUTOMATIC, CRYPTO_APPL_CONST) pCryptoPrimitive;
    P2CONST(Crypto_PrimitiveInfoType, AUTOMATIC, CRYPTO_APPL_CONST) pJobPrimitiveInfo = pJob->jobPrimitiveInfo->primitiveInfo;

    for (counter = 0U; counter < pCrypto_ObjectJobList[u32ObjectIndex]->u32Crypto_PrimitivesNumber; counter++)/* polyspace RTE:OBAI */
    {
    	pCryptoPrimitive = &pCrypto_ObjectJobList[u32ObjectIndex]->pCrypto_Primitives[counter];
    	if (((Std_ReturnType)E_OK 				 == Crypto_CheckServiceSupport(pJobPrimitiveInfo, pCryptoPrimitive)) && \
    	    (pJobPrimitiveInfo->algorithm.family == pCryptoPrimitive->eCrypto_Family) && /* polyspace RTE:NIV */ 
			(pJobPrimitiveInfo->algorithm.mode   == pCryptoPrimitive->eCrypto_Mode) &&
			(pJobPrimitiveInfo->algorithm.secondaryFamily   == pCryptoPrimitive->eCrypto_SecondaryFamily))    /* polyspace RTE:NIV */
    	{
    		retVal = (Std_ReturnType)E_OK;
    	}
    }

    return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
CRYPTO_INLINE FUNC(Crypto_ReturnType, CRYPTO_CODE) Crypto_VerifyHashMacGenSignGenServiceParams
(
    P2VAR (Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) job
)
{
    VAR(Crypto_ReturnType, AUTOMATIC) RetVal = (Crypto_ReturnType)CRYPTO_OK;
    VAR(Crypto_OperationModeType, AUTOMATIC) JobOptMode = job->jobPrimitiveInputOutput.mode;

    if ((CRYPTO_OPERATIONMODE_SINGLECALL == JobOptMode) ||
        (CRYPTO_OPERATIONMODE_UPDATE     == JobOptMode))
    {
        if (NULL_PTR == job->jobPrimitiveInputOutput.inputPtr)
        {
            RetVal = CRYPTO_NULL_PTR;
        }
        else
        {
            if (0U == job->jobPrimitiveInputOutput.inputLength)
            {
                RetVal = CRYPTO_INVALID_LEN;
            }
        }
    }
    else if(CRYPTO_OPERATIONMODE_FINISH  == JobOptMode)
    {
        if ((NULL_PTR == job->jobPrimitiveInputOutput.inputPtr)&&(0U != job->jobPrimitiveInputOutput.inputLength))
        {
            RetVal = CRYPTO_NULL_PTR;
        }
        else if((NULL_PTR != job->jobPrimitiveInputOutput.inputPtr)&&(0U == job->jobPrimitiveInputOutput.inputLength))
        {

        	 RetVal = CRYPTO_INVALID_LEN;
        }
    }

    if ((Crypto_ReturnType)CRYPTO_OK == RetVal)
    {
        if ((CRYPTO_OPERATIONMODE_SINGLECALL == JobOptMode) ||
            (CRYPTO_OPERATIONMODE_FINISH     == JobOptMode))
        {
            if (NULL_PTR == job->jobPrimitiveInputOutput.outputPtr)
            {
                RetVal = CRYPTO_NULL_PTR;
            }
            else
            {
                if (0U == *job->jobPrimitiveInputOutput.outputLengthPtr)
                {
                    RetVal = CRYPTO_INVALID_LEN;
                }
            }
        }
    }

    return RetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
CRYPTO_INLINE FUNC(Crypto_ReturnType, CRYPTO_CODE) Crypto_VerifyMacVerifySignVerifyServiceParams
(
    P2VAR (Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) job
)
{
    VAR(Crypto_ReturnType, AUTOMATIC) RetVal = (Crypto_ReturnType)CRYPTO_OK;
    VAR(Crypto_OperationModeType, AUTOMATIC) JobOptMode = job->jobPrimitiveInputOutput.mode;

    if ((CRYPTO_OPERATIONMODE_SINGLECALL == JobOptMode) ||
        (CRYPTO_OPERATIONMODE_UPDATE     == JobOptMode))
    {
        if (NULL_PTR == job->jobPrimitiveInputOutput.inputPtr)
        {
            RetVal = CRYPTO_NULL_PTR;
        }
        else
        {
            if (0U == job->jobPrimitiveInputOutput.inputLength)
            {
                RetVal = CRYPTO_INVALID_LEN;
            }
        }
    }
    else if(CRYPTO_OPERATIONMODE_FINISH  == JobOptMode)
    {
        if ((NULL_PTR == job->jobPrimitiveInputOutput.inputPtr)&&(0U != job->jobPrimitiveInputOutput.inputLength))
        {
            RetVal = CRYPTO_NULL_PTR;
        }
        else if((NULL_PTR != job->jobPrimitiveInputOutput.inputPtr)&&(0U == job->jobPrimitiveInputOutput.inputLength))
        {

        	 RetVal = CRYPTO_INVALID_LEN;
        }
    }

    if ((Crypto_ReturnType)CRYPTO_OK == RetVal)
    {
        if ((CRYPTO_OPERATIONMODE_SINGLECALL == JobOptMode) ||
            (CRYPTO_OPERATIONMODE_FINISH     == JobOptMode))
        {
            if (NULL_PTR == job->jobPrimitiveInputOutput.secondaryInputPtr)
            {
                RetVal = CRYPTO_NULL_PTR;
            }
            else
            {
                if (0U == job->jobPrimitiveInputOutput.secondaryInputLength)
                {
                    RetVal = CRYPTO_INVALID_LEN;
                }
            }
        }
    }

    if ((Crypto_ReturnType)CRYPTO_OK == RetVal)
    {
        if ((CRYPTO_OPERATIONMODE_SINGLECALL == JobOptMode) ||
            (CRYPTO_OPERATIONMODE_FINISH     == JobOptMode))
        {
            if (NULL_PTR == job->jobPrimitiveInputOutput.verifyPtr)
            {
                RetVal = CRYPTO_NULL_PTR;
            }
        }
    }

    return RetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
CRYPTO_INLINE FUNC(Crypto_ReturnType, CRYPTO_CODE) Crypto_VerifyEnDeCryptServiceParams
(
    P2VAR (Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) job
)
{
    VAR(Crypto_ReturnType, AUTOMATIC) RetVal = (Crypto_ReturnType)CRYPTO_OK;
    VAR(Crypto_OperationModeType, AUTOMATIC) JobOptMode = job->jobPrimitiveInputOutput.mode;

    if ((CRYPTO_OPERATIONMODE_SINGLECALL == JobOptMode) ||
        (CRYPTO_OPERATIONMODE_UPDATE     == JobOptMode))
    {
        if (NULL_PTR == job->jobPrimitiveInputOutput.inputPtr)
        {
            RetVal = CRYPTO_NULL_PTR;
        }
        else
        {
            if (0U == job->jobPrimitiveInputOutput.inputLength)
            {
                RetVal = CRYPTO_INVALID_LEN;
            }
        }
    }
    else if(CRYPTO_OPERATIONMODE_FINISH  == JobOptMode)
    {
        if ((NULL_PTR == job->jobPrimitiveInputOutput.inputPtr)&&(0U != job->jobPrimitiveInputOutput.inputLength))
        {
            RetVal = CRYPTO_NULL_PTR;
        }
        else if((NULL_PTR != job->jobPrimitiveInputOutput.inputPtr)&&(0U == job->jobPrimitiveInputOutput.inputLength))
        {

        	 RetVal = CRYPTO_INVALID_LEN;
        }
    }

    if ((Crypto_ReturnType)CRYPTO_OK == RetVal)
    {
        if ((CRYPTO_OPERATIONMODE_SINGLECALL == JobOptMode) ||
            (CRYPTO_OPERATIONMODE_UPDATE     == JobOptMode) ||
            (CRYPTO_OPERATIONMODE_FINISH     == JobOptMode))
        {
            if (NULL_PTR == job->jobPrimitiveInputOutput.outputPtr)
            {
                RetVal = CRYPTO_NULL_PTR;
            }
            else
            {
                if (0U == *job->jobPrimitiveInputOutput.outputLengthPtr)
                {
                    RetVal = CRYPTO_INVALID_LEN;
                }
            }
        }
    }

    return RetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
CRYPTO_INLINE FUNC(Crypto_ReturnType, CRYPTO_CODE) Crypto_VerifyAeadEncryptServiceParams
(
    P2VAR (Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) job
)
{
    VAR(Crypto_ReturnType, AUTOMATIC) RetVal = (Crypto_ReturnType)CRYPTO_OK;
    VAR(Crypto_OperationModeType, AUTOMATIC) JobOptMode = job->jobPrimitiveInputOutput.mode;

    if ((CRYPTO_OPERATIONMODE_SINGLECALL == JobOptMode) ||
        (CRYPTO_OPERATIONMODE_UPDATE     == JobOptMode))
    {
        if ((NULL_PTR == job->jobPrimitiveInputOutput.inputPtr) ||
            (NULL_PTR == job->jobPrimitiveInputOutput.outputPtr) ||
            (NULL_PTR == job->jobPrimitiveInputOutput.outputLengthPtr))
        {
            RetVal = CRYPTO_NULL_PTR;
        }
        else
        {
            if ((0U == job->jobPrimitiveInputOutput.inputLength) ||
                (0U == *job->jobPrimitiveInputOutput.outputLengthPtr))
            {
                RetVal = CRYPTO_INVALID_LEN;
            }
        }
    }
    else if(CRYPTO_OPERATIONMODE_FINISH  == JobOptMode)
    {
        if ((NULL_PTR == job->jobPrimitiveInputOutput.inputPtr)&&(0U != job->jobPrimitiveInputOutput.inputLength))
        {
            RetVal = CRYPTO_NULL_PTR;
        }
        else if((NULL_PTR != job->jobPrimitiveInputOutput.inputPtr)&&(0U == job->jobPrimitiveInputOutput.inputLength))
        {

        	 RetVal = CRYPTO_INVALID_LEN;
        }
    }

    if ((Crypto_ReturnType)CRYPTO_OK == RetVal)
    {
        if ((CRYPTO_OPERATIONMODE_SINGLECALL == JobOptMode) ||
            (CRYPTO_OPERATIONMODE_FINISH     == JobOptMode))
        {
            if ((NULL_PTR == job->jobPrimitiveInputOutput.secondaryInputPtr)||
                (NULL_PTR == job->jobPrimitiveInputOutput.outputPtr)  ||
                (NULL_PTR == job->jobPrimitiveInputOutput.outputLengthPtr) ||
                (NULL_PTR == job->jobPrimitiveInputOutput.secondaryOutputPtr) ||
                (NULL_PTR == job->jobPrimitiveInputOutput.secondaryOutputLengthPtr))
            {
                RetVal = CRYPTO_NULL_PTR;
            }
            else
            {
                if ((0U == job->jobPrimitiveInputOutput.secondaryInputLength) ||
                    (0U == *job->jobPrimitiveInputOutput.outputLengthPtr) ||
                    (0U == *job->jobPrimitiveInputOutput.secondaryOutputLengthPtr))
                {
                    RetVal = CRYPTO_INVALID_LEN;
                }
            }
        }
    }

    return RetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
CRYPTO_INLINE FUNC(Crypto_ReturnType, CRYPTO_CODE) Crypto_VerifyAeadDecryptServiceParams
(
    P2VAR (Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) job
)
{
    VAR(Crypto_ReturnType, AUTOMATIC) RetVal = (Crypto_ReturnType)CRYPTO_OK;
    VAR(Crypto_OperationModeType, AUTOMATIC) JobOptMode = job->jobPrimitiveInputOutput.mode;

    if ((CRYPTO_OPERATIONMODE_SINGLECALL == JobOptMode) ||
        (CRYPTO_OPERATIONMODE_UPDATE     == JobOptMode))
    {
        if ((NULL_PTR == job->jobPrimitiveInputOutput.inputPtr) ||
            (NULL_PTR == job->jobPrimitiveInputOutput.outputPtr))
        {
            RetVal = CRYPTO_NULL_PTR;
        }
        else
        {
            if ((0U == job->jobPrimitiveInputOutput.inputLength) ||
                (NULL_PTR == job->jobPrimitiveInputOutput.outputLengthPtr))
            {
                RetVal = CRYPTO_INVALID_LEN;
            }
        }
    }
    else if(CRYPTO_OPERATIONMODE_FINISH  == JobOptMode)
    {
        if ((NULL_PTR == job->jobPrimitiveInputOutput.inputPtr)&&(0U != job->jobPrimitiveInputOutput.inputLength))
        {
            RetVal = CRYPTO_NULL_PTR;
        }
        else if((NULL_PTR != job->jobPrimitiveInputOutput.inputPtr)&&(0U == job->jobPrimitiveInputOutput.inputLength))
        {

        	 RetVal = CRYPTO_INVALID_LEN;
        }
    }

    if ((Crypto_ReturnType)CRYPTO_OK == RetVal)
    {
        if ((CRYPTO_OPERATIONMODE_SINGLECALL == JobOptMode) ||
            (CRYPTO_OPERATIONMODE_FINISH     == JobOptMode))
        {
            if ((NULL_PTR == job->jobPrimitiveInputOutput.secondaryInputPtr) ||
                (NULL_PTR == job->jobPrimitiveInputOutput.tertiaryInputPtr) ||
                (NULL_PTR == job->jobPrimitiveInputOutput.outputPtr) ||
                (NULL_PTR == job->jobPrimitiveInputOutput.outputLengthPtr) ||
                (NULL_PTR == job->jobPrimitiveInputOutput.verifyPtr))
            {
                RetVal = CRYPTO_NULL_PTR;
            }
            else
            {
                if ((0U == job->jobPrimitiveInputOutput.secondaryInputLength) ||
                    (0U == job->jobPrimitiveInputOutput.tertiaryInputLength) ||
                    (0U == *job->jobPrimitiveInputOutput.outputLengthPtr))
                {
                    RetVal = CRYPTO_INVALID_LEN;
                }
            }
        }
    }

    return RetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
CRYPTO_INLINE FUNC(Crypto_ReturnType, CRYPTO_CODE) Crypto_VerifyRndGenServiceParams
(
    P2VAR (Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) job
)
{
    VAR(Crypto_ReturnType, CRYPTO_VAR) RetVal = (Crypto_ReturnType)CRYPTO_OK;
    VAR(Crypto_OperationModeType, CRYPTO_VAR) JobOptMode = job->jobPrimitiveInputOutput.mode;

    if ((CRYPTO_OPERATIONMODE_SINGLECALL == JobOptMode) ||
        (CRYPTO_OPERATIONMODE_FINISH     == JobOptMode))
    {
        if (NULL_PTR == job->jobPrimitiveInputOutput.outputPtr)
        {
            RetVal = CRYPTO_NULL_PTR;
        }
        else
        {
            if (0U == *job->jobPrimitiveInputOutput.outputLengthPtr)
            {
                RetVal = CRYPTO_INVALID_LEN;
            }
        }
    }

    return RetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
CRYPTO_INLINE FUNC(Crypto_ReturnType, CRYPTO_CODE) Crypto_VerifySeriveParams
(
    P2VAR (Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) job
)
{
    VAR(Crypto_ReturnType, AUTOMATIC) RetVal = (Crypto_ReturnType)CRYPTO_NOT_OK;
    VAR(Crypto_ServiceInfoType, AUTOMATIC) JobService = job->jobPrimitiveInfo->primitiveInfo->service;
    VAR(Crypto_OperationModeType, AUTOMATIC) JobOptMode = job->jobPrimitiveInputOutput.mode;

    if ((CRYPTO_OPERATIONMODE_SINGLECALL != JobOptMode)&&
    		(CRYPTO_OPERATIONMODE_START != JobOptMode)&&
			(CRYPTO_OPERATIONMODE_UPDATE != JobOptMode)&&
			(CRYPTO_OPERATIONMODE_FINISH != JobOptMode))
    {
    	return RetVal;
    }

    switch (JobService)
    {
        case CRYPTO_HASH:
        case CRYPTO_MACGENERATE:
        case CRYPTO_SIGNATUREGENERATE:
            RetVal = Crypto_VerifyHashMacGenSignGenServiceParams(job);
            break;

        case CRYPTO_MACVERIFY:
        case CRYPTO_SIGNATUREVERIFY:
            RetVal = Crypto_VerifyMacVerifySignVerifyServiceParams(job);
            break;

        case CRYPTO_ENCRYPT:
        case CRYPTO_DECRYPT:
            RetVal = Crypto_VerifyEnDeCryptServiceParams(job);
            break;

        case CRYPTO_AEADENCRYPT:
            RetVal = Crypto_VerifyAeadEncryptServiceParams(job);
            break;

        case CRYPTO_AEADDECRYPT:
            RetVal = Crypto_VerifyAeadDecryptServiceParams(job);
            break;

        case CRYPTO_RANDOMGENERATE:
            RetVal = Crypto_VerifyRndGenServiceParams(job);
            break;

        default:
            /* DO NOTHING */
            break;
    }

    return RetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#endif

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*****************************************************************************
**  Service Name     : Crypto_Init
**
**  Description      : Initializes the Crypto Driver.
**
**  Service ID       : 0x00
**
**  Sync/Async       : Synchronous
**
**  Reentrancy       : Non-Reentrant
**
**  Parameters (in)  : configPtr: Pointer to a selected configuration structure.
**
**  Parameters (out) : None
**
**  Return value     : None
**
*********************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_CODE) Crypto_Init
(
     P2CONST(Crypto_ConfigType, AUTOMATIC, CRYPTO_APPL_CONST) configPtr
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Crypto_RetVal = (Std_ReturnType)E_NOT_OK;

    if (g_Crypto_DriverStatus == CRYPTO_UNINIT)
    {
#if (CRYPTO_PRECOMPILE_SUPPORT == STD_ON)
        u8Crypto_RetVal = Crypto_AutoSar_Wrapper_Init(&Crypto_Config);
        (void)configPtr;
#else
        u8Crypto_RetVal = Crypto_AutoSar_Wrapper_Init(configPtr);
#endif
        if (u8Crypto_RetVal == E_OK)
        {
        	/*[SWS_Crypto_00198] if so, the corresponding key shall be set to VALID state*/
        	Crypto_RestoreKeyValidInfor();

#if (CRYPTO_PRECOMPILE_SUPPORT == STD_ON)
            Crypto_ConfigPtr = &Crypto_Config;	/* PRQA S 2919*/
#else
            Crypto_ConfigPtr = configPtr;	/* PRQA S 2919*/
#endif
            g_Crypto_DriverStatus = CRYPTO_READY;
        }
        else
        {
#if (CRYPTO_DET_ERROR_REPORT == STD_ON)
            /** Specification of Crypto Driver : [SWS_Crypto_00045] **/
            Crypto_ReportError(CRYPTO_INIT_ID, (uint8)CRYPTO_E_INIT_FAILED);
#endif
        }
    }
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/*****************************************************************************
**  Service Name     : Crypto_GetVersionInfo
**
**  Description      : Returns the version information of this module.
**
**  Service ID       : 0x01
**
**  Sync/Async       : Synchronous
**
**  Reentrancy       : Non-Reentrant
**
**  Parameters (in)  : versioninfo: Pointer to where to store the version information of this module.
**
**  Parameters (out) : None
**
**  Return value     : None
**
*********************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_CODE) Crypto_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CRYPTO_APPL_DATA) versioninfo/* PRQA S 1756  */
)
{
#if (CRYPTO_DET_ERROR_REPORT == STD_ON)
    /** Specification of Crypto Driver : [SWS_Crypto_00047] **/
    if (NULL_PTR == versioninfo)
    {
        Crypto_ReportError(CRYPTO_INIT_ID, (uint8)CRYPTO_E_PARAM_POINTER);
    }
    else
#endif
    {
        versioninfo->moduleID           = (uint16)CRYPTO_MODULE_ID;
        versioninfo->vendorID           = (uint16)CRYPTO_VENDOR_ID;
        versioninfo->sw_major_version   = (uint8)CRYPTO_SW_MAJOR_VER;
        versioninfo->sw_minor_version   = (uint8)CRYPTO_SW_MINOR_VER;
        versioninfo->sw_patch_version   = (uint8)CRYPTO_SW_PATCH_VER;
    }
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/*****************************************************************************
**  Service Name     : Crypto_ProcessJob
**
**  Description      : Performs the crypto primitive, that is configured in the job parameter.
**
**  Service ID       : 0x03
**
**  Sync/Async       : Sync or Async, depends on the job configuration
**
**  Reentrancy       : Reentrant
**
**  Parameters (in)  : objectId: Holds the identifier of the Crypto Driver Object.
**                     job: Pointer to the configuration of the job. Contains structures with
**                          job and primitive relevant information but also pointer to result buffers.
**
**  Parameters (out) : None
**
**  Return value     : E_OK: Request successful
**                     E_NOT_OK: Request failed
**                     CRYPTO_E_BUSY: Request failed, Crypro Driver Object is busy
**                     CRYPTO_E_KEY_NOT_VALID: Request failed, the key is not valid
**                     CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, a key element has the wrong size
**                     CRYPTO_E_QUEUE_FULL: Request failed, the queue is full
**                     CRYPTO_E_KEY_READ_FAIL: The service request failed, because key element extraction is not allowed
**                     CRYPTO_E_KEY_WRITE_FAIL: The service request failed because the writing access failed
**                     CRYPTO_E_KEY_NOT_AVAILABLE: The service request failed because the key is not available
**                     CRYPTO_E_ENTROPY_EXHAUSTION: Request failed, the entropy is exhausted
**                     CRYPTO_E_SMALL_BUFFER: The provided buffer is too small to store the result
**                     CRYPTO_E_JOB_CANCELED: The service request failed because the synchronous Job has been canceled
**                     CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
**
*********************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE)Crypto_ProcessJob
(
    VAR(uint32, AUTOMATIC) objectId,
    P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) job
)
{

    VAR(Std_ReturnType, AUTOMATIC) u8RetVal = (Std_ReturnType)E_NOT_OK;
#if (CRYPTO_DET_ERROR_REPORT == STD_ON)
    VAR(Crypto_ReturnType, AUTOMATIC) Crypto_RetVal = (Crypto_ReturnType)CRYPTO_NOT_OK;
#endif
    VAR(uint32, AUTOMATIC) u32CryptoObjectIndex = Crypto_SearchObjectIndex(objectId);

#if (CRYPTO_DET_ERROR_REPORT == STD_ON)
    /** Specification of Crypto Driver : [SWS_Crypto_00057] **/
    if (CRYPTO_UNINIT == g_Crypto_DriverStatus)
    {
        Crypto_ReportError((uint8)CRYPTO_PROCESSJOB_ID, (uint8)CRYPTO_E_UNINIT);
    }
    /** Specification of Crypto Driver : [SWS_Crypto_00058] **/
    else if (CRYPTO_INVALID_OBJECT_IDX == u32CryptoObjectIndex)	/* PRQA S 2992,2996 */
    {
        Crypto_ReportError((uint8)CRYPTO_PROCESSJOB_ID, (uint8)CRYPTO_E_PARAM_HANDLE);/* PRQA S 2880 */
    }
    /** Specification of Crypto Driver : [SWS_Crypto_00059] **/
    else if (NULL_PTR == job)
    {
        Crypto_ReportError((uint8)CRYPTO_PROCESSJOB_ID, (uint8)CRYPTO_E_PARAM_POINTER);
    }
    /** Specification of Crypto Driver : [SWS_Crypto_00067] and [SWS_Crypto_00064] **/
    else if ((Std_ReturnType)E_NOT_OK == Crypto_VerifyPrimitive(u32CryptoObjectIndex, job))
    {
        Crypto_ReportError((uint8)CRYPTO_PROCESSJOB_ID, (uint8)CRYPTO_E_PARAM_HANDLE);
    }
    else
    {
        Crypto_RetVal = Crypto_VerifySeriveParams(job);
        /** Specification of Crypto Driver : [SWS_Crypto_00070] **/
        if ((Crypto_ReturnType)CRYPTO_NULL_PTR == Crypto_RetVal)
        {
            Crypto_ReportError((uint8)CRYPTO_PROCESSJOB_ID, (uint8)CRYPTO_E_PARAM_POINTER);
        }
        /** Specification of Crypto Driver :  [SWS_Crypto_00142]  **/
        else if ((Crypto_ReturnType)CRYPTO_INVALID_LEN == Crypto_RetVal)
        {
            Crypto_ReportError((uint8)CRYPTO_PROCESSJOB_ID, (uint8)CRYPTO_E_PARAM_VALUE);
        }
        else if ((Crypto_ReturnType)CRYPTO_NOT_OK == Crypto_RetVal)
        {
            Crypto_ReportError((uint8)CRYPTO_PROCESSJOB_ID, (uint8)CRYPTO_E_PARAM_HANDLE);
        }
        else
#endif
        {
            u8RetVal = Crypto_VerifyKeyValidity(job);
            if ((Std_ReturnType)E_OK == u8RetVal)
            {
                u8RetVal = Crypto_AutoSar_Wrapper_ProcessJob((uint8)u32CryptoObjectIndex, job);
            }
            if ((Std_ReturnType)CRYPTO_E_SMALL_BUFFER == u8RetVal)
            {
                Crypto_ReportRuntimeError((uint8)CRYPTO_PROCESSJOB_ID, (uint8)CRYPTO_E_RE_SMALL_BUFFER);
            }
            else if ((Std_ReturnType)E_NOT_OK == u8RetVal)
            {
#if (CRYPTO_DET_ERROR_REPORT == STD_ON) // cyh
            	Crypto_ReportError((uint8)CRYPTO_PROCESSJOB_ID, (uint8)CRYPTO_E_PARAM_HANDLE);
#endif
            }
        }
#if (CRYPTO_DET_ERROR_REPORT == STD_ON)
    }
#endif
    return u8RetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/*****************************************************************************
**  Service Name     : Crypto_CancelJob
**
**  Description      : This interface removes the provided job from the queue and cancels the processing of the job if possible.
**
**  Service ID       : 0x0e
**
**  Sync/Async       : Synchronous
**
**  Reentrancy       : Reentrant, but not for same Crypto Driver Object
**
**  Parameters (in)  : objectId: Holds the identifier of the Crypto Driver Object.
**                     job: Pointer to the configuration of the job. Contains structures with
**                          job and primitive relevant information.
**
**  Parameters (out) : None
**
**  Return value     : E_OK: Request successful, job has been removed.
**                     E_NOT_OK: Request failed, job couldn't be removed.
**                     CRYPTO_E_JOB_CANCELED: The job has been cancelled but
**                                            is still processed. No results will be returned to the application.
**
*********************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE)Crypto_CancelJob
(
    VAR(uint32, AUTOMATIC) objectId,
    P2VAR(Crypto_JobInfoType, AUTOMATIC, CRYPTO_APPL_DATA) job
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Crypto_CancelJobRetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Crypto_ObjectIndex = Crypto_SearchObjectIndex(objectId);

#if (CRYPTO_DET_ERROR_REPORT == STD_ON)
    /** Specification of Crypto Driver : [SWS_Crypto_00123] **/
    if (CRYPTO_UNINIT == g_Crypto_DriverStatus)
    {
        Crypto_ReportError((uint8)CRYPTO_CANCELJOB_ID, (uint8)CRYPTO_E_UNINIT);
    }
    /** Specification of Crypto Driver : [SWS_Crypto_00124] **/
    else if (CRYPTO_INVALID_OBJECT_IDX == u32Crypto_ObjectIndex )/* PRQA S 2992,2996 */
    {
        Crypto_ReportError((uint8)CRYPTO_CANCELJOB_ID, (uint8)CRYPTO_E_PARAM_HANDLE );/* PRQA S 2880 */
    }
    /** Specification of Crypto Driver : [SWS_Crypto_00125] **/
    else if (NULL_PTR == job)
    {
        Crypto_ReportError((uint8)CRYPTO_CANCELJOB_ID, (uint8)CRYPTO_E_PARAM_POINTER );
    }
    else
#endif
    {
        u8Crypto_CancelJobRetVal = Crypto_AutoSar_Wrapper_CancelJob(u32Crypto_ObjectIndex, job);
    }

    return u8Crypto_CancelJobRetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/*****************************************************************************
**  Service Name     : Crypto_KeyElementSet
**
**  Description      : Sets the given key element bytes to the key identified by cryptoKeyId.
**
**  Service ID       : 0x04
**
**  Sync/Async       : Synchronous
**
**  Reentrancy       : Non Reentrant
**
**  Parameters (in)  : cryptoKeyId: Holds the identifier of the key whose key element shall be set.
**                     keyElementId: Holds the identifier of the key element which shall be set.
**                     keyPtr: Holds the pointer to the key data which shall be set as key element.
**                     keyLength: Contains the length of the key element in bytes.
**
**  Parameters (out) : None
**
**  Return value     : E_OK: Request successful
**                     E_NOT_OK: Request failed
**                     CRYPTO_E_BUSY: Request failed, Crypto Driver Object is busy
**                     CRYPTO_E_KEY_WRITE_FAIL:Request failed because write access was denied
**                     CRYPTO_E_KEY_NOT_AVAILABLE: Request failed because the key is not available
**                     CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element size does not match size of provided data
**
*********************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE)Crypto_KeyElementSet
(
    VAR(uint32, AUTOMATIC) cryptoKeyId,
    VAR(uint32, AUTOMATIC) keyElementId,
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) keyPtr,
    VAR(uint32, AUTOMATIC) keyLength
)
{
    VAR(uint32, CRYPTO_VAR) u32CryptoKeyElementIndex = 0U;
    VAR(uint32,CRYPTO_VAR) u32CryptoKeyIndex = Crypto_SearchKeyIdIndex(cryptoKeyId);
    VAR(Std_ReturnType, CRYPTO_VAR) u8RetVal = (Std_ReturnType)E_NOT_OK;

#if (CRYPTO_DET_ERROR_REPORT == STD_ON)
    /** Specification of Crypto Driver : [SWS_Crypto_00075] **/
    if (CRYPTO_UNINIT == g_Crypto_DriverStatus)
    {
        Crypto_ReportError((uint8)CRYPTO_KEYELEMENTSET_ID, (uint8)CRYPTO_E_UNINIT);
    }
    /** Specification of Crypto Driver : [SWS_Crypto_00076] **/
    else if (CRYPTO_HSM_INVALID_KEY_IDX == u32CryptoKeyIndex)
    {
        Crypto_ReportError((uint8)CRYPTO_KEYELEMENTSET_ID, (uint8)CRYPTO_E_PARAM_HANDLE);
    }
    /** Specification of Crypto Driver : [SWS_Crypto_00078] **/
    else if (NULL_PTR == keyPtr)
    {
        Crypto_ReportError((uint8)CRYPTO_KEYELEMENTSET_ID, (uint8)CRYPTO_E_PARAM_POINTER);
    }
    /** Specification of Crypto Driver : [SWS_Crypto_00079] **/
    else if (0U == keyLength)
    {
        Crypto_ReportError((uint8)CRYPTO_KEYELEMENTSET_ID, (uint8)CRYPTO_E_PARAM_VALUE);
    }
    else
#endif
    {
    	u32CryptoKeyElementIndex = Crypto_SearchKeyElementIdIndex(u32CryptoKeyIndex, keyElementId);
        if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX != u32CryptoKeyElementIndex)
        {
            if  ((keyLength < Crypto_KeyElementList[u32CryptoKeyElementIndex]->u32Crypto_KeyElementMaxSize) &&(Crypto_KeyElementList[u32CryptoKeyElementIndex]->bCrypto_KeyElementAllowPartialAccess == FALSE))
            {
            	u8RetVal = (Std_ReturnType)CRYPTO_E_KEY_SIZE_MISMATCH;
            }
            else if (CRYPTO_WA_DENIED == Crypto_KeyElementList[u32CryptoKeyElementIndex]->eCrypto_KeyElementWriteAccess)
            {
            	u8RetVal = (Std_ReturnType)CRYPTO_E_KEY_WRITE_FAIL;
            }
            else if((CRYPTO_WA_ENCRYPTED == Crypto_KeyElementList[u32CryptoKeyElementIndex]->eCrypto_KeyElementWriteAccess)||(CRYPTO_WA_INTERNAL_COPY == Crypto_KeyElementList[u32CryptoKeyElementIndex]->eCrypto_KeyElementWriteAccess))
            {
            	u8RetVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED; //No support for encrypted import and internal copy
            }
            else
            {
                Crypto_KeyList[u32CryptoKeyIndex]->bCrypto_KeyValid = FALSE;

                if (CRYPTO_HSM_KEY_MATERIAL == keyElementId) /* set key */
                {
                	u8RetVal = Crypto_AutoSar_Wrapper_ImportKey(keyPtr, keyLength, u32CryptoKeyElementIndex);
                }
                else /* set iv or other else */
                {
                    Crypto_memcpy(Crypto_KeyElementList[u32CryptoKeyElementIndex]->pCrypto_ElementArray, keyPtr, keyLength);
                    u8RetVal = (Std_ReturnType)E_OK;
                }
                if ((Std_ReturnType)E_OK == u8RetVal)
                {
                    Crypto_KeyElementList[u32CryptoKeyElementIndex]->u32Crypto_KeyElementActualSize = keyLength;
                }
            }
        }
        else
        {
            /** Specification of Crypto Driver : [SWS_Crypto_00077] **/
#if (CRYPTO_DET_ERROR_REPORT == STD_ON)
            Crypto_ReportError((uint8)CRYPTO_KEYELEMENTSET_ID, (uint8)CRYPTO_E_PARAM_HANDLE);
#endif
        }
    }

    return u8RetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/*****************************************************************************
**  Service Name     : Crypto_KeySetValid
**
**  Description      : Sets the key state of the key identified by cryptoKeyId to valid.
**
**  Service ID       : 0x05
**
**  Sync/Async       : Synchronous
**
**  Reentrancy       : Non Reentrant
**
**  Parameters (in)  : cryptoKeyId: Holds the identifier of the key which shall be set to valid.
**
**  Parameters (out) : None
**
**  Return value     : E_OK: Request successful
**                     E_NOT_OK: Request failed
**                     CRYPTO_E_BUSY: Request failed, Crypro Driver Object is busy
**
*********************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE)Crypto_KeySetValid
(
    VAR(uint32, AUTOMATIC) cryptoKeyId
)
{
    VAR(uint32, AUTOMATIC) u32CryptoKeyIndex = Crypto_SearchKeyIdIndex(cryptoKeyId);
    VAR(Std_ReturnType, AUTOMATIC) u8RetVal = (Std_ReturnType)E_NOT_OK;

#if (CRYPTO_DET_ERROR_REPORT == STD_ON)
    /** Specification of Crypto Driver : [SWS_Crypto_000196] **/
    if (CRYPTO_UNINIT == g_Crypto_DriverStatus)
    {
        Crypto_ReportError((uint8)CRYPTO_KEYVALIDSET_ID, (uint8)CRYPTO_E_UNINIT);
    }
    /** Specification of Crypto Driver : [SWS_Crypto_000197] **/
    else if (CRYPTO_HSM_INVALID_KEY_IDX == u32CryptoKeyIndex)
    {
        Crypto_ReportError((uint8)CRYPTO_KEYVALIDSET_ID, (uint8)CRYPTO_E_PARAM_HANDLE);
    }
    else
#endif
    {
        Crypto_KeyList[u32CryptoKeyIndex]->bCrypto_KeyValid = (boolean)TRUE;
        u8RetVal = (Std_ReturnType)E_OK;
    }

    return u8RetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/*****************************************************************************
**  Service Name     : Crypto_KeyElementGet
**
**  Description      : This interface shall be used to get a key element of the key identified by the
**                     cryptoKeyId and store the key element in the memory location pointed by the result pointer.
**                     Note:
**                     If the actual key element is directly mapped to flash memory, there could be a
**                     bigger delay when calling this function (synchronous operation).
**
**  Service ID       : 0x06
**
**  Sync/Async       : Synchronous
**
**  Reentrancy       : Reentrant
**
**  Parameters (in)  : cryptoKeyId: Holds the identifier of the key whose key element shall be returned.
**                     keyElementId: Holds the identifier of the key element which shall be returned.
**
**  Parameters (inout) : resultLengthPtr: Holds a pointer to a memory location in which the length
**                                        information is stored. On calling this function this parameter shall
**                                        contain the size of the buffer provided by resultPtr. If the key
**                                        element is configured to allow partial access, this parameter
**                                        contains the amount of data which should be read from the key
**                                        element. The size may not be equal to the size of the provided
**                                        buffer anymore. When the request has finished, the amount of
**                                        data that has been stored shall be stored.
**
**  Parameters (out): resultPtr: Holds the pointer of the buffer for the returned key element
**
**  Return value     : E_OK: Request successful
**                     E_NOT_OK: Request failed
**                     CRYPTO_E_BUSY: Request failed, Crypto Driver Object is busy
**                     CRYPTO_E_KEY_NOT_AVAILABLE: Request failed, the requested key element is not available
**                     CRYPTO_E_KEY_READ_FAIL: Request failed because read access was denied
**                     CRYPTO_E_SMALL_BUFFER: The provided buffer is too small to store the result
**                     CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
**
*********************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE)Crypto_KeyElementGet
(
    VAR(uint32, AUTOMATIC) cryptoKeyId,
    VAR(uint32, AUTOMATIC) keyElementId,
    P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) resultPtr,
    P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) resultLengthPtr
)
{

    VAR(uint32, AUTOMATIC) u32CryptoKeyElementIndex = 0U;
    VAR(Std_ReturnType, AUTOMATIC) u8RetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32CryptoKeyIndex = Crypto_SearchKeyIdIndex(cryptoKeyId);

#if (CRYPTO_DET_ERROR_REPORT == STD_ON)
    /** Specification of Crypto Driver : [SWS_Crypto_00085] **/
    if (CRYPTO_UNINIT == g_Crypto_DriverStatus)
    {
        Crypto_ReportError((uint8)CRYPTO_KEYELEMENTGET_ID, (uint8)CRYPTO_E_UNINIT);
    }
    /** Specification of Crypto Driver : [SWS_Crypto_00086] [SWS_Crypto_00087] **/
    else if (CRYPTO_HSM_INVALID_KEY_IDX == u32CryptoKeyIndex)
    {
        Crypto_ReportError((uint8)CRYPTO_KEYELEMENTGET_ID, (uint8)CRYPTO_E_PARAM_HANDLE);
    }
    /** Specification of Crypto Driver : [SWS_Crypto_00088] [SWS_Crypto_00089] **/
    else if ((NULL_PTR == resultPtr) || (NULL_PTR == resultLengthPtr))
    {
        Crypto_ReportError((uint8)CRYPTO_KEYELEMENTGET_ID, (uint8)CRYPTO_E_PARAM_POINTER);
    }
    /** Specification of Crypto Driver : [SWS_Crypto_00090] **/
    else if (0UL == *resultLengthPtr)
    {
        Crypto_ReportError((uint8)CRYPTO_KEYELEMENTGET_ID, (uint8) CRYPTO_E_PARAM_VALUE);
    }
    else
#endif
    {
    	u32CryptoKeyElementIndex = Crypto_SearchKeyElementIdIndex(u32CryptoKeyIndex, keyElementId);
        if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX != u32CryptoKeyElementIndex)
        {
            if (CRYPTO_RA_DENIED == Crypto_KeyElementList[u32CryptoKeyElementIndex]->eCrypto_KeyElementReadAccess)
            {
                u8RetVal = (Std_ReturnType)CRYPTO_E_KEY_READ_FAIL;

#if (CRYPTO_DET_ERROR_REPORT == STD_ON)
                /*
                 * [SWS_Crypto_00139] ? If the function Crypto_KeyElementGet returns CRYPTO_E_KEY_READ_FAIL,
                 * the function shall additionally report the runtime error CRYPTO_E_RE_KEY_READ_FAIL
                 */
                Crypto_ReportRuntimeError((uint8)CRYPTO_KEYELEMENTGET_ID, (uint8) CRYPTO_E_RE_KEY_READ_FAIL);

#endif
            }
            else if((CRYPTO_RA_ENCRYPTED == Crypto_KeyElementList[u32CryptoKeyElementIndex]->eCrypto_KeyElementReadAccess)||(CRYPTO_RA_INTERNAL_COPY == Crypto_KeyElementList[u32CryptoKeyElementIndex]->eCrypto_KeyElementReadAccess))
            {

            	 u8RetVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;

            }
            else if(*resultLengthPtr <Crypto_KeyElementList[u32CryptoKeyElementIndex]->u32Crypto_KeyElementActualSize)
            {

            	u8RetVal = (Std_ReturnType)CRYPTO_E_SMALL_BUFFER;
#if (CRYPTO_DET_ERROR_REPORT == STD_ON)
            	/*
            	[SWS_Crypto_00195]? If a Crypto API is called with a buffer too small to perform
            	the desires operation CRYPTO_E_RE_SMALL_BUFFER shall be reported to the
            	DET and the operation shall not be performed
            	*/
            	Crypto_ReportError((uint8)CRYPTO_KEYELEMENTGET_ID, (uint8) CRYPTO_E_SMALL_BUFFER);
#endif
            }
            else
            {
                if (CRYPTO_HSM_KEY_MATERIAL == keyElementId)
                {
                    u8RetVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;; /* not support */

                }
                else /* iv or other */
                {

                	if(0U < Crypto_KeyElementList[u32CryptoKeyElementIndex]->u32Crypto_KeyElementActualSize)
                	{

                		if(NULL_PTR != Crypto_KeyElementList[u32CryptoKeyElementIndex]->pCrypto_ElementArray)
                		{

                            Crypto_memcpy(resultPtr, Crypto_KeyElementList[u32CryptoKeyElementIndex]->pCrypto_ElementArray, Crypto_KeyElementList[u32CryptoKeyElementIndex]->u32Crypto_KeyElementActualSize);

                             *resultLengthPtr = Crypto_KeyElementList[u32CryptoKeyElementIndex]->u32Crypto_KeyElementActualSize;

                             u8RetVal = (Std_ReturnType)E_OK;
                		}
                		else
                		{
                			u8RetVal = (Std_ReturnType)E_NOT_OK;

                		}

                	}
                	else
                	{

                		u8RetVal = (Std_ReturnType)CRYPTO_E_KEY_EMPTY;

                	}

                }
            }
        }
#if (CRYPTO_DET_ERROR_REPORT == STD_ON)
        else
        {
        	Crypto_ReportError((uint8)CRYPTO_KEYELEMENTGET_ID, (uint8)CRYPTO_E_PARAM_HANDLE);
        }
#endif
    }

    return u8RetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/*****************************************************************************
**  Service Name     : Crypto_KeyElementCopy
**
**  Description      : Copies a key element to another key element in the same crypto driver.
**                     Note:
**                     If the actual key element is directly mapped to flash memory, there could be a
**                     bigger delay when calling this function (synchronous operation)
**
**  Service ID       : 0x0f
**
**  Sync/Async       : Synchronous
**
**  Reentrancy       : Reentrant
**
**  Parameters (in)  : cryptoKeyId: Holds the identifier of the key whose key element shall be
**                                  the source element.
**                     keyElementId: Holds the identifier of the key element which shall be the
**                                   source for the copy operation.
**                     targetCryptoKeyId: Holds the identifier of the key whose key element shall be
**                                        the destination element.
**                     targetKeyElementId: Holds the identifier of the key element which shall be the
**                                         destination for the copy operation.
**
**  Parameters (inout) : None
**
**  Parameters (out): None
**
**  Return value     : E_OK: Request successful
**                     E_NOT_OK: Request failed
**                     E_BUSY: Request failed, Crypto Driver Object is busy
**                     CRYPTO_E_KEY_NOT_AVAILABLE: Request failed, the requested key element is not available
**                     CRYPTO_E_KEY_READ_FAIL: Request failed, not allowed to extract key element
**                     CRYPTO_E_KEY_WRITE_FAIL: Request failed, not allowed to write key element
**                     CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element sizes are not compatible
**                     CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
**
*********************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE)Crypto_KeyElementCopy
(
    VAR(uint32, AUTOMATIC) cryptoKeyId,
    VAR(uint32, AUTOMATIC) keyElementId,
    VAR(uint32, AUTOMATIC) targetCryptoKeyId,
    VAR(uint32, AUTOMATIC) targetKeyElementId
)
{
    VAR(uint32, AUTOMATIC) u32CryptoKeyElementIndex = 0U;
    VAR(uint32, AUTOMATIC) u32CryptoTargetKeyElementIndex = 0U;
    VAR(uint32, AUTOMATIC) u32CryptoKeyIndex = Crypto_SearchKeyIdIndex(cryptoKeyId);
    VAR(uint32, AUTOMATIC) u32CryptoTargetKeyIndex = Crypto_SearchKeyIdIndex(targetCryptoKeyId);
    VAR(Std_ReturnType, AUTOMATIC) u8RetVal = (Std_ReturnType)E_NOT_OK;

#if (CRYPTO_DET_ERROR_REPORT == STD_ON)
    /** Specification of Crypto Driver : [SWS_Crypto_00156] **/
    if (CRYPTO_UNINIT == g_Crypto_DriverStatus)
    {
        Crypto_ReportError((uint8)CRYPTO_KEYELEMENTCOPY_ID, (uint8)CRYPTO_E_UNINIT);
    }
    /** Specification of Crypto Driver : [SWS_Crypto_00157] **/
    else if (CRYPTO_HSM_INVALID_KEY_IDX == u32CryptoKeyIndex)
    {
        Crypto_ReportError((uint8)CRYPTO_KEYELEMENTCOPY_ID, (uint8)CRYPTO_E_PARAM_HANDLE);
    }
    /** Specification of Crypto Driver : [SWS_Crypto_00158] **/
    else if (CRYPTO_HSM_INVALID_KEY_IDX == u32CryptoTargetKeyIndex)
    {
        Crypto_ReportError((uint8)CRYPTO_KEYELEMENTCOPY_ID, (uint8)CRYPTO_E_PARAM_HANDLE);
    }
    else
#endif
    {
		u32CryptoKeyElementIndex = Crypto_SearchKeyElementIdIndex(u32CryptoKeyIndex, keyElementId);
		u32CryptoTargetKeyElementIndex = Crypto_SearchKeyElementIdIndex(u32CryptoTargetKeyIndex, targetKeyElementId);

		if ((CRYPTO_HSM_INVALID_KEY_IDX != u32CryptoKeyElementIndex) && (CRYPTO_HSM_INVALID_KEY_IDX != u32CryptoTargetKeyElementIndex))
		{
			if ((Crypto_KeyElementReadAccessType)CRYPTO_RA_DENIED == (Crypto_KeyElementList[u32CryptoKeyElementIndex]->eCrypto_KeyElementReadAccess))
			{
				u8RetVal = (Std_ReturnType)CRYPTO_E_KEY_READ_FAIL;
			}
			else if ((Crypto_KeyElementWriteAccessType)CRYPTO_WA_DENIED == (Crypto_KeyElementList[u32CryptoTargetKeyElementIndex]->eCrypto_KeyElementWriteAccess))
			{
				u8RetVal = (Std_ReturnType)CRYPTO_E_KEY_WRITE_FAIL;
			}
			else if(0U == Crypto_KeyElementList[u32CryptoKeyElementIndex]->u32Crypto_KeyElementActualSize)
			{

				u8RetVal = (Std_ReturnType)CRYPTO_E_KEY_EMPTY;
			}
			else if (((Crypto_KeyElementList[u32CryptoKeyElementIndex]->u32Crypto_KeyElementActualSize) >(Crypto_KeyElementList[u32CryptoTargetKeyElementIndex]->u32Crypto_KeyElementMaxSize))\
					||(((Crypto_KeyElementList[u32CryptoKeyElementIndex]->u32Crypto_KeyElementActualSize) !=(Crypto_KeyElementList[u32CryptoTargetKeyElementIndex]->u32Crypto_KeyElementActualSize))
					  &&((boolean)FALSE == (Crypto_KeyElementList[u32CryptoKeyElementIndex]->bCrypto_KeyElementAllowPartialAccess)))
					)
			{
				u8RetVal = (Std_ReturnType)CRYPTO_E_KEY_SIZE_MISMATCH;
			}
			else
			{
				if(keyElementId != CRYPTO_HSM_KEY_MATERIAL)
				{
					if (CRYPTO_HSM_KEY_MATERIAL == targetKeyElementId)
					{
						u8RetVal = Crypto_AutoSar_Wrapper_ImportKey(Crypto_KeyElementList[u32CryptoKeyElementIndex]->pCrypto_ElementArray, Crypto_KeyElementList[u32CryptoKeyElementIndex]->u32Crypto_KeyElementActualSize, u32CryptoTargetKeyElementIndex);
					}
					else
					{
						Crypto_memcpy((Crypto_KeyElementList[u32CryptoTargetKeyElementIndex]->pCrypto_ElementArray), Crypto_KeyElementList[u32CryptoKeyElementIndex]->pCrypto_ElementArray, Crypto_KeyElementList[u32CryptoKeyElementIndex]->u32Crypto_KeyElementActualSize);
						u8RetVal = (Std_ReturnType)E_OK;
					}
					if ((Std_ReturnType)E_OK == u8RetVal)
					{
						Crypto_KeyElementList[u32CryptoTargetKeyElementIndex]->u32Crypto_KeyElementActualSize = Crypto_KeyElementList[u32CryptoKeyElementIndex]->u32Crypto_KeyElementActualSize;
					}

				}
				else
				{
					/* Copying a key material in another key element is not allowed. */
					u8RetVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;

				}
			}
		}
		else
		{
#if (CRYPTO_DET_ERROR_REPORT == STD_ON)
			(void)Crypto_ReportError((uint8)CRYPTO_KEYELEMENTCOPY_ID, (uint8)CRYPTO_E_PARAM_HANDLE);
#endif
		}

    }
    return u8RetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/*****************************************************************************
**  Service Name       : Crypto_KeyElementCopyPartial
**
**  Description        : Copies a key element to another key element in the same crypto driver. The
**                       keyElementSourceOffset and keyElementCopyLength allows to copy just a part of
**                       the source key element into the destination. The offset of the target key is also
**                       specified with this function.
**                       Note:
**                       If the actual key element is directly mapped to flash memory, there could be a
**                       bigger delay when calling this function (synchronous operation)
**
**  Service ID         : 0x13
**
**  Sync/Async         : Synchronous
**
**  Reentrancy         : Reentrant, but not for the same cryptoKeyId
**
**  Parameters (in)    : cryptoKeyId: Holds the identifier of the key whose key element shall
**                                  be the source element.
**                       keyElementId: Holds the identifier of the key element which shall be
**                                   the source for the copy operation.
**                       keyElementSourceOffset: This is the offset of the of the source key element
**                                             indicating the start index of the copy operation.
**                       keyElementTargetOffset: This is the offset of the of the target key element
**                                              indicating the start index of the copy operation.
**                       keyElementCopyLength: Specifies the number of bytes that shall be copied.
**                       targetCryptoKeyId: Holds the identifier of the key whose key element shall
**                                        be the destination element.
**                       targetKeyElementId: Holds the identifier of the key element which shall be
**                                         the destination for the copy operation.
**
**  Parameters (inout) : None
**
**  Parameters (out)   : None
**
**  Return value       : E_OK: Request successful
**                       E_NOT_OK: Request failed
**                       E_BUSY: Request failed, Crypto Driver Object is busy
**                       CRYPTO_E_KEY_NOT_AVAILABLE: Request failed, the requested key element is not available
**                       CRYPTO_E_KEY_READ_FAIL: Request failed, not allowed to extract key element
**                       CRYPTO_E_KEY_WRITE_FAIL: Request failed, not allowed to write key element
**                       CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element sizes are not compatible
**                       CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
*********************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE)Crypto_KeyElementCopyPartial
(
    VAR(uint32, AUTOMATIC) cryptoKeyId,
    VAR(uint32, AUTOMATIC) keyElementId,
    VAR(uint32, AUTOMATIC) keyElementSourceOffset,
    VAR(uint32, AUTOMATIC) keyElementTargetOffset,
    VAR(uint32, AUTOMATIC) keyElementCopyLength,
    VAR(uint32, AUTOMATIC) targetCryptoKeyId,
    VAR(uint32, AUTOMATIC) targetKeyElementId
)
{
    VAR(Std_ReturnType, CRYPTO_VAR) u8ReturnValue = (Std_ReturnType)E_NOT_OK;

    (void)cryptoKeyId;
    (void)keyElementId;
    (void)keyElementSourceOffset;
    (void)keyElementTargetOffset;
    (void)keyElementCopyLength;
    (void)targetCryptoKeyId;
    (void)targetKeyElementId;

    return u8ReturnValue;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/*****************************************************************************
**  Service Name       : Crypto_KeyCopy
**
**  Description        : Copies a key with all its elements to another key in the same crypto driver.
**                       Note:
**                       If the actual key element is directly mapped to flash memory, there could be a
**                       bigger delay when calling this function (synchronous operation)
**
**  Service ID         : 0x10
**
**  Sync/Async         : Synchronous
**
**  Reentrancy         : Reentrant, but not for the same cryptoKeyId
**
**  Parameters (in)    : cryptoKeyId: Holds the identifier of the key whose key element shall be the
**                                    source element.
**                       targetCryptoKeyId: Holds the identifier of the key whose key element shall be the
**                                          destination element.
**
**  Parameters (inout) : None
**
**  Parameters (out)   : None
**
**  Return value       : E_OK: Request successful
**                       E_NOT_OK: Request failed
**                       E_BUSY: Request failed, Crypto Driver Object is busy
**                       CRYPTO_E_KEY_NOT_AVAILABLE: Request failed, the
**                       requested key element is not available
**                       CRYPTO_E_KEY_READ_FAIL: Request failed, not allowed to extract key element
**                       CRYPTO_E_KEY_WRITE_FAIL: Request failed, not allowed to write key element
**                       CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element sizes are not compatible
**                       CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
**
*********************************************************************************/
/*****************************************************************************
**  Service Name       : Crypto_KeyElementIdsGet
**
**  Description        : Used to retrieve information which key elements are available in a given key
**
**  Service ID         : 0x11
**
**  Sync/Async         : Synchronous
**
**  Reentrancy         : Reentrant, but not for the same cryptoKeyId
**
**  Parameters (in)    : cryptoKeyId: Holds the identifier of the key whose available element
**                                    ids shall be exported.
**                       keyElementIdsLengthPtr: Holds a pointer to the memory location in which the
**                                               number of key elements in the given key is stored. On
**                                               calling this function, this parameter shall contain the size
**                                               of the buffer provided by keyElementIdsPtr. When the
**                                               request has finished, the actual number of key elements
**                                               shall be stored.
**
**  Parameters (inout) : keyElementIdsPtr: Contains the pointer to the array where the ids of the key
**                                         elements shall be stored
**
**  Parameters (out)   : None
**
**  Return value       : E_OK: Request successful
**                       E_NOT_OK: Request failed
**                       E_BUSY: Request failed, Crypto Driver Object is busy
**                       CRYPTO_E_SMALL_BUFFER: The provided buffer is too small to store the result
**
*********************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE)Crypto_KeyElementIdsGet
(
    VAR(uint32, AUTOMATIC) cryptoKeyId,
    P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) keyElementIdsPtr,
    P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) keyElementIdsLengthPtr
)
{
    VAR(uint32, AUTOMATIC) u32Crypto_KeyElementCounter = 0U;
    VAR(uint32, AUTOMATIC) u32CryptoKeyIndex = Crypto_SearchKeyIdIndex(cryptoKeyId);
    VAR(Std_ReturnType, AUTOMATIC) u8RetVal = (Std_ReturnType)E_NOT_OK;

#if (CRYPTO_DET_ERROR_REPORT == STD_ON)
    /** Specification of Crypto Driver : [SWS_Crypto_00161] **/
    if (CRYPTO_UNINIT == g_Crypto_DriverStatus )
    {
        Crypto_ReportError((uint8)CRYPTO_KEYELEMENTIDSGET_ID, (uint8)CRYPTO_E_UNINIT);
    }
    /** Specification of Crypto Driver : [SWS_Crypto_00162] **/
    else if (CRYPTO_HSM_INVALID_KEY_IDX == u32CryptoKeyIndex)
    {
        Crypto_ReportError((uint8)CRYPTO_KEYELEMENTIDSGET_ID, (uint8)CRYPTO_E_PARAM_HANDLE);
    }
    else if(Crypto_KeyList[u32CryptoKeyIndex]->pCrypto_KeyElementConfig->u32CryptoKeyElementsCount > *keyElementIdsLengthPtr)/* PRQA S 2812 */
    {

    	u8RetVal = (Std_ReturnType)CRYPTO_E_SMALL_BUFFER;

    	Crypto_ReportRuntimeError((uint8)CRYPTO_KEYELEMENTIDSGET_ID, (uint8)CRYPTO_E_RE_SMALL_BUFFER);
    }
    else
#endif
    {
        if ((NULL_PTR != keyElementIdsPtr) && (NULL_PTR != keyElementIdsLengthPtr))
        {
            *keyElementIdsLengthPtr = Crypto_KeyList[u32CryptoKeyIndex]->pCrypto_KeyElementConfig->u32CryptoKeyElementsCount;
            for (u32Crypto_KeyElementCounter = 0U;
                 u32Crypto_KeyElementCounter < Crypto_KeyList[u32CryptoKeyIndex]->pCrypto_KeyElementConfig->u32CryptoKeyElementsCount;
                 u32Crypto_KeyElementCounter++ )
            {
                *keyElementIdsPtr = Crypto_KeyElementList[Crypto_KeyList[u32CryptoKeyIndex]->pCrypto_KeyElementConfig->pCryptoKeyElementsNumberConfig[u32Crypto_KeyElementCounter]]->u32Crypto_KeyElementId;/* polyspace RTE:COR,IDP,OBAI */ 
                keyElementIdsPtr++;
            }
            u8RetVal = (Std_ReturnType)E_OK;
        }
    }

    return u8RetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/*****************************************************************************
**  Service Name       : Crypto_RandomSeed
**
**  Description        : This function generates the internal seed state using the provided entropy source.
**                       Furthermore, this function can be used to update the seed state with new entropy
**
**  Service ID         : 0x0d
**
**  Sync/Async         : Synchronous
**
**  Reentrancy         : Reentrant, but not for the same cryptoKeyId
**
**  Parameters (in)    : cryptoKeyId: Holds the identifier of the key for which a new seed shall be generated.
**                       seedPtr: Holds a pointer to the memory location which contains the data to feed the seed.
**                       seedLength: Contains the length of the seed in bytes.
**
**  Parameters (inout) : None
**
**  Parameters (out)   : None
**
**  Return value       : E_OK: Request successful
**                       E_NOT_OK: Request failed
**
*********************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE)Crypto_KeyCopy
(
    VAR(uint32, AUTOMATIC) cryptoKeyId,
    VAR(uint32, AUTOMATIC) targetCryptoKeyId
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8ReturnValue = (Std_ReturnType)E_NOT_OK;
    VAR(boolean, AUTOMATIC) bFound = (boolean)FALSE;
    VAR(uint32, AUTOMATIC) u32CryptoTargetKeyIndex = Crypto_SearchKeyIdIndex(targetCryptoKeyId);
    VAR(uint32, AUTOMATIC) u32CryptoKeyIndex = Crypto_SearchKeyIdIndex(cryptoKeyId);;
    VAR(uint32, AUTOMATIC) u32Crypto_KeyElementCounter = 0;
    VAR(uint32, AUTOMATIC) u32Crypto_TargetKeyElementCounter = 0;
    VAR(uint32, AUTOMATIC) u32ActualKeyElementIndex = 0;
    VAR(uint32, AUTOMATIC) u32ActualTargetKeyElementIndex = 0;

#if (CRYPTO_DET_ERROR_REPORT == STD_ON)
    /** Specification of Crypto Driver : [SWS_Crypto_00156] **/
    if (CRYPTO_UNINIT == g_Crypto_DriverStatus)
    {
        Crypto_ReportError((uint8)CRYPTO_KEYCOPY_ID, (uint8)CRYPTO_E_UNINIT);
    }
    /** Specification of Crypto Driver : [SWS_Crypto_00157] ? If cryptoKeyId is out of range and if development error detection for the Crypto Driver is enabled, the function Crypto_KeyCopy shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.
     *  [SWS_Crypto_00158] ? If targetCryptoKeyId is out of range and if development error detection for the Crypto Driver is enabled, the function Crypto_KeyCopy shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK
     *  **/
    else if ((CRYPTO_HSM_INVALID_KEY_IDX == u32CryptoKeyIndex)||(CRYPTO_HSM_INVALID_KEY_IDX == u32CryptoTargetKeyIndex))
    {
        Crypto_ReportError((uint8)CRYPTO_KEYCOPY_ID, (uint8)CRYPTO_E_PARAM_HANDLE);
    }
    else
#endif
    {
		if((Crypto_KeyList[u32CryptoKeyIndex]->pCrypto_KeyElementConfig->u32CryptoKeyElementsCount) >(Crypto_KeyList[u32CryptoTargetKeyIndex]->pCrypto_KeyElementConfig->u32CryptoKeyElementsCount))/* polyspace RTE:OBAI */
		{
			u8ReturnValue = (Std_ReturnType)E_NOT_OK;
		}
		else
		{
			for (u32Crypto_KeyElementCounter = 0U; ((u32Crypto_KeyElementCounter < ((Crypto_KeyList[u32CryptoKeyIndex]->pCrypto_KeyElementConfig->u32CryptoKeyElementsCount))) && ((boolean)FALSE == bFound)); u32Crypto_KeyElementCounter++ )
			{
				for (u32Crypto_TargetKeyElementCounter = 0U; ((u32Crypto_TargetKeyElementCounter < ((Crypto_KeyList[u32CryptoTargetKeyIndex]->pCrypto_KeyElementConfig->u32CryptoKeyElementsCount))) && ((boolean)FALSE == bFound)); u32Crypto_TargetKeyElementCounter++ )
				{
					u32ActualKeyElementIndex = (uint8)Crypto_KeyList[u32CryptoKeyIndex]->pCrypto_KeyElementConfig->pCryptoKeyElementsNumberConfig[u32Crypto_KeyElementCounter];/* polyspace RTE:IDP */
					u32ActualTargetKeyElementIndex = (uint8)Crypto_KeyList[u32CryptoTargetKeyIndex]->pCrypto_KeyElementConfig->pCryptoKeyElementsNumberConfig[u32Crypto_TargetKeyElementCounter];/* polyspace RTE:IDP */

					if(Crypto_KeyElementList[u32ActualKeyElementIndex]->u32Crypto_KeyElementId == Crypto_KeyElementList[u32ActualTargetKeyElementIndex]->u32Crypto_KeyElementId)/* polyspace RTE:OBAI */
					{
						bFound = (boolean)TRUE;
						if ((Crypto_KeyElementReadAccessType)CRYPTO_RA_DENIED == (Crypto_KeyElementList[u32ActualKeyElementIndex]->eCrypto_KeyElementReadAccess))
						{
							u8ReturnValue = (Std_ReturnType)CRYPTO_E_KEY_READ_FAIL;
						}
						else if ((Crypto_KeyElementWriteAccessType)CRYPTO_WA_DENIED == (Crypto_KeyElementList[u32ActualTargetKeyElementIndex]->eCrypto_KeyElementWriteAccess))
						{
							u8ReturnValue = (Std_ReturnType)CRYPTO_E_KEY_WRITE_FAIL;
						}
						else if(Crypto_KeyElementList[u32ActualKeyElementIndex]->u32Crypto_KeyElementActualSize == 0U)
						{

							u8ReturnValue = (Std_ReturnType)CRYPTO_E_KEY_EMPTY;

						}
						else if (
								((Crypto_KeyElementList[u32ActualKeyElementIndex]->u32Crypto_KeyElementActualSize) >(Crypto_KeyElementList[u32ActualTargetKeyElementIndex]->u32Crypto_KeyElementMaxSize))\
								||(((Crypto_KeyElementList[u32ActualKeyElementIndex]->u32Crypto_KeyElementActualSize) !=(Crypto_KeyElementList[u32ActualTargetKeyElementIndex]->u32Crypto_KeyElementActualSize))
								&&((boolean)FALSE == (Crypto_KeyElementList[u32ActualTargetKeyElementIndex]->bCrypto_KeyElementAllowPartialAccess)))
								)
						{
							u8ReturnValue = (Std_ReturnType)CRYPTO_E_KEY_SIZE_MISMATCH;
						}
						else
						{
							if ((Crypto_KeyElementList[u32ActualKeyElementIndex]->u32Crypto_KeyElementId == Crypto_KeyElementList[u32ActualTargetKeyElementIndex]->u32Crypto_KeyElementId) &&
									(Crypto_KeyElementList[u32ActualKeyElementIndex]->u32Crypto_KeyElementId !=CRYPTO_HSM_KEY_MATERIAL))/* polyspace RTE:OBAI */
							{
								bFound = (boolean)TRUE;
								Crypto_memcpy(Crypto_KeyElementList[u32ActualTargetKeyElementIndex]->pCrypto_ElementArray,\
											  Crypto_KeyElementList[u32ActualKeyElementIndex]->pCrypto_ElementArray,\
											  Crypto_KeyElementList[u32ActualKeyElementIndex]->u32Crypto_KeyElementActualSize);
								Crypto_KeyElementList[u32ActualTargetKeyElementIndex]->u32Crypto_KeyElementActualSize = Crypto_KeyElementList[u32ActualKeyElementIndex]->u32Crypto_KeyElementActualSize;/* polyspace RTE:OBAI */

								u8ReturnValue = (Std_ReturnType)E_OK;
							}
						}
					}
				}
			}

#if 0
			if ((Std_ReturnType)E_OK == u8ReturnValue)
			{
				bFound = (boolean)FALSE;
				for (u32Crypto_KeyElementCounter = 0U; ((u32Crypto_KeyElementCounter < ((Crypto_KeyList[u32CryptoKeyIndex]->pCrypto_KeyElementConfig->u32CryptoKeyElementsCount))) && ((boolean)FALSE == bFound)); u32Crypto_KeyElementCounter++ )
				{
					bFound = (boolean)FALSE;
					for (u32Crypto_TargetKeyElementCounter = 0U; ((u32Crypto_TargetKeyElementCounter < ((Crypto_KeyList[u32CryptoTargetKeyIndex]->pCrypto_KeyElementConfig->u32CryptoKeyElementsCount))) && ((boolean)FALSE == bFound)); u32Crypto_TargetKeyElementCounter++ )
					{
		                /* Need to check if:
		                   1. Key elements have same KeyElementId
		                   2. The KeyElementId is not KeyMaterial
						*/
						u32ActualKeyElementIndex = (uint8)Crypto_KeyList[u32CryptoKeyIndex]->pCrypto_KeyElementConfig->pCryptoKeyElementsNumberConfig[u32Crypto_KeyElementCounter];/* polyspace RTE:IDP */
						u32ActualTargetKeyElementIndex = (uint8)Crypto_KeyList[u32CryptoTargetKeyIndex]->pCrypto_KeyElementConfig->pCryptoKeyElementsNumberConfig[u32Crypto_TargetKeyElementCounter];/* polyspace RTE:IDP */
						if ((Crypto_KeyElementList[u32ActualKeyElementIndex]->u32Crypto_KeyElementId == Crypto_KeyElementList[u32ActualTargetKeyElementIndex]->u32Crypto_KeyElementId) &&
								(Crypto_KeyElementList[u32ActualKeyElementIndex]->u32Crypto_KeyElementId !=CRYPTO_HSM_KEY_MATERIAL))/* polyspace RTE:OBAI */
						{
							bFound = (boolean)TRUE;
							Crypto_memcpy(Crypto_KeyElementList[u32ActualTargetKeyElementIndex]->pCrypto_ElementArray,\
										  Crypto_KeyElementList[u32ActualKeyElementIndex]->pCrypto_ElementArray,\
										  Crypto_KeyElementList[u32ActualKeyElementIndex]->u32Crypto_KeyElementActualSize);
							Crypto_KeyElementList[u32ActualTargetKeyElementIndex]->u32Crypto_KeyElementActualSize = Crypto_KeyElementList[u32ActualKeyElementIndex]->u32Crypto_KeyElementActualSize;/* polyspace RTE:OBAI */

						}
					}
				}
			}
#endif
		}
    }
    return u8ReturnValue;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE)Crypto_RandomSeed
(
    VAR(uint32, AUTOMATIC) cryptoKeyId,
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) seedPtr,
    VAR(uint32, AUTOMATIC) seedLength
)
{
    VAR(Std_ReturnType, CRYPTO_VAR) u8Crypto_RandomSeedRetVal = (Std_ReturnType)E_NOT_OK;

    /* Add this to avoid compiler warnings */
    (void) cryptoKeyId;
    (void) seedPtr;
    (void) seedLength;

    return u8Crypto_RandomSeedRetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/*****************************************************************************
**  Service Name       : Crypto_KeyGenerate
**
**  Description        : Generates new key material store it in the key identified by cryptoKeyId
**
**  Service ID         : 0x07
**
**  Sync/Async         : Synchronous
**
**  Reentrancy         : Reentrant, but not for the same cryptoKeyId
**
**  Parameters (in)    : cryptoKeyId: Holds the identifier of the key which is to be updated with the generated value.
**
**  Parameters (inout) : None
**
**  Parameters (out)   : None
**
**  Return value       : E_OK: Request successful
**                       E_NOT_OK: Request failed
**                       E_BUSY: Request failed, Crypto Driver Object is busy
**                       CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
**
*********************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE)Crypto_KeyGenerate
(
    VAR(uint32, AUTOMATIC) cryptoKeyId
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8RetVal = (Std_ReturnType)E_NOT_OK;

    VAR(uint32, AUTOMATIC) u32cryptoKeyIdIndex = Crypto_SearchKeyIdIndex(cryptoKeyId);

#if (CRYPTO_DET_ERROR_REPORT == STD_ON)
    /** Specification of Crypto Driver : [SWS_Crypto_00094] **/
    if (CRYPTO_UNINIT == g_Crypto_DriverStatus)
    {
        Crypto_ReportError((uint8)CRYPTO_KEYGENERATE_ID, (uint8)CRYPTO_E_UNINIT);
    }
    else if(CRYPTO_HSM_INVALID_KEY_IDX == u32cryptoKeyIdIndex)
    {
    	/*
    	 *[SWS_Crypto_00095] ? If the parameter cryptoKeyId is out of range and if development error detection for the Crypto Driver is enabled, the function Crypto_KeyGenerate shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK.
    	 * */
    	Crypto_ReportError((uint8)CRYPTO_KEYELEMENTCOPY_ID, (uint8)CRYPTO_E_PARAM_HANDLE);

    }
    else
#endif
    {
        u8RetVal = Crypto_AutoSar_Wrapper_KeyGenerate(cryptoKeyId);
    }
    return u8RetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/*****************************************************************************
**  Service Name       : Crypto_KeyDerive
**
**  Description        : Derives a new key by using the key elements in the given key identified by the
**                       cryptoKeyId. The given key contains the key elements for the password, salt. The
**                       derived key is stored in the key element with the id 1 of the key identified by
**                       targetCryptoKeyId. The number of iterations is given in the key element
**                       CRYPTO_KE_KEYDERIVATION_ITERATIONS
**
**  Service ID         : 0x08
**
**  Sync/Async         : Synchronous
**
**  Reentrancy         : Reentrant, but not for the same cryptoKeyId
**
**  Parameters (in)    : cryptoKeyId: Holds the identifier of the key which is used for key derivation.
**                       targetCryptoKeyId: Holds the identifier of the key which is used to store the derived key
**
**  Parameters (inout) : None
**
**  Parameters (out)   : None
**
**  Return value       : E_OK: Request successful
**                       E_NOT_OK: Request failed
**                       E_BUSY: Request failed, Crypto Driver Object is busy
**                       CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
**
*********************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE)Crypto_KeyDerive
(
    VAR(uint32, AUTOMATIC) cryptoKeyId,
    VAR(uint32, AUTOMATIC) targetCryptoKeyId
)
{
    VAR(Std_ReturnType, CRYPTO_VAR) u8ReturnValue = (Std_ReturnType)E_NOT_OK;

    (void)cryptoKeyId;
    (void)targetCryptoKeyId;

    return u8ReturnValue;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/*****************************************************************************
**  Service Name       : Crypto_KeyExchangeCalcPubVal
**
**  Description        : Calculates the public value for the key exchange and stores the public key in the
**                       memory location pointed by the public value pointer
**
**  Service ID         : 0x09
**
**  Sync/Async         : Synchronous
**
**  Reentrancy         : Reentrant, but not for the same cryptoKeyId
**
**  Parameters (in)    : cryptoKeyId: Holds the identifier of the key which shall be used for the key
**                                    exchange protocol.
**                       targetCryptoKeyId: Holds the identifier of the key which is used to store the derived key
**
**  Parameters (inout) : publicValueLengthPtr: Holds a pointer to the memory location in which the public
**                                             value length information is stored. On calling this function,
**                                             this parameter shall contain the size of the buffer provided
**                                             by publicValuePtr. When the request has finished, the actual
**                                             length of the returned value shall be stored
**
**  Parameters (out)   : publicValuePtr: Contains the pointer to the data where the public value shall be stored
**
**  Return value       : E_OK: Request successful
**                       E_NOT_OK: Request failed
**                       E_BUSY: Request failed, Crypto Driver Object is busy
**                       CRYPTO_E_SMALL_BUFFER: The provided buffer is too small to store the result
**                       CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
**
*********************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE)Crypto_KeyExchangeCalcPubVal
(
    VAR(uint32, AUTOMATIC) cryptoKeyId,
    P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) publicValuePtr,
    P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) publicValueLengthPtr
)
{
    VAR(Std_ReturnType, CRYPTO_VAR) u8ReturnValue = (Std_ReturnType)E_NOT_OK;

    (void) cryptoKeyId;
    (void) publicValuePtr;
    (void) publicValueLengthPtr;

    return u8ReturnValue;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/*****************************************************************************
**  Service Name       : Crypto_KeyExchangeCalcSecret
**
**  Description        : Calculates the shared secret key for the key exchange with the key material of the
**                       key identified by the cryptoKeyId and the partner public key. The shared secret
**                       key is stored as a key element in the same key
**
**  Service ID         : 0x0a
**
**  Sync/Async         : Synchronous
**
**  Reentrancy         : Reentrant, but not for the same cryptoKeyId
**
**  Parameters (in)    : cryptoKeyId: Holds the identifier of the key which shall be used
**                                    for the key exchange protocol.
**                       partnerPublicValuePtr: Holds the pointer to the memory location which
**                                              contains the partner's public value
**                       partnerPublicValueLength: Contains the length of the partner's public value in bytes
**
**  Parameters (inout) : None
**
**  Parameters (out)   : None
**
**  Return value       : E_OK: Request successful
**                       E_NOT_OK: Request failed
**                       E_BUSY: Request failed, Crypto Driver Object is busy
**                       CRYPTO_E_SMALL_BUFFER: The provided buffer is too small to store the result
**                       CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
**
*********************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE)Crypto_KeyExchangeCalcSecret
(
    VAR(uint32, AUTOMATIC) cryptoKeyId,
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) partnerPublicValuePtr,
    VAR(uint32, AUTOMATIC) partnerPublicValueLength
)
{
    VAR(Std_ReturnType, CRYPTO_VAR) u8ReturnValue = (Std_ReturnType)E_NOT_OK;

    (void) cryptoKeyId;
    (void) partnerPublicValuePtr;
    (void) partnerPublicValueLength;

    return u8ReturnValue;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/*****************************************************************************
**  Service Name       : Crypto_CertificateParse
**
**  Description        : Parses the certificate data stored in the key element CRYPTO_KE_CERT_DATA
**                       and fills the key elements CRYPTO_KE_CERT_SIGNEDDATA,
**                       CRYPTO_KE_CERT_PARSEDPUBLICKEY and
**                       CRYPTO_KE_CERT_SIGNATURE
**
**  Service ID         : 0x0b
**
**  Sync/Async         : Synchronous
**
**  Reentrancy         : Reentrant, but not for the same cryptoKeyId
**
**  Parameters (in)    : cryptoKeyId: Holds the identifier of the key which shall be parsed.
**
**  Parameters (inout) : None
**
**  Parameters (out)   : None
**
**  Return value       : E_OK: Request successful
**                       E_NOT_OK: Request failed
**                       E_BUSY: Request failed, Crypto Driver Object is busy
**                       CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
**
*********************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE)Crypto_CertificateParse
(
    VAR(uint32, AUTOMATIC) cryptoKeyId
)
{
    (void)cryptoKeyId;

    return (Std_ReturnType)E_NOT_OK;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/*****************************************************************************
**  Service Name       : Crypto_CertificateVerify
**
**  Description        : Verifies the certificate stored in the key referenced by cryptoValidateKeyId with the
**                       certificate stored in the key referenced by cryptoKeyId
**
**  Service ID         : 0x12
**
**  Sync/Async         : Synchronous
**
**  Reentrancy         : Reentrant, but not for the same cryptoKeyId
**
**  Parameters (in)    : cryptoKeyId: Holds the identifier of the key which shall be parsed.
**                       verifyCryptoKeyId:  Holds the identifier of the key contain
**
**  Parameters (inout) : None
**
**  Parameters (out)   : verifyPtr: Holds a pointer to the memory location which will contain the
**                                  result of the certificate verification.
**
**  Return value       : E_OK: Request successful
**                       E_NOT_OK: Request failed
**                       E_BUSY: Request failed, Crypto Driver Object is busy
**                       CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key element
**
*********************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE)Crypto_CertificateVerify
(
    VAR(uint32, AUTOMATIC) cryptoKeyId,
    VAR(uint32, AUTOMATIC) verifyCryptoKeyId,
    P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYPTO_APPL_DATA) verifyPtr
)
{
    (void)cryptoKeyId;
    (void)verifyCryptoKeyId;
    (void)verifyPtr;

    return (Std_ReturnType)E_NOT_OK;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/*****************************************************************************
**  Service Name       : Crypto_MainFunction
**
**  Description        : If asynchronous job processing is configured and there are job queues, the
**                       function is called cyclically to process queued jobs
**
**  Service ID         : 0x0c
**
**  Sync/Async         : Synchronous
**
**  Reentrancy         : None
**
**  Parameters (in)    : None
**
**  Parameters (inout) : None
**
**  Parameters (out)   : None.
**
**  Return value       : None
**
*********************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_CODE)Crypto_MainFunction(void)
{
    Crypto_AutoSar_Wrapper_MainFunction();
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
