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
*   @file    Crypto_AutoSar_Wrapper.c
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
 * @ID:rcma-4.0.0-1503 Rule:M3CM Rule-2.1
 * The function '%1s' is defined but is not used within this project.
 */

/* PRQA S 1503, 0380, 3432, 3218, 1842, 2987  EOF */
/* PRQA S 0491, 1842, 0491, 2844, 2002, 1842  EOF */
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Crypto.h"
#include "Crypto_common.h"
#include "Crypto_AutoSar_Wrapper.h"

/* Variable storing the pointer to the job that is currently processing */
#define CRYPTO_START_SEC_VAR_NO_INIT
#include "Crypto_MemMap.h"
static P2VAR (Crypto_JobType, CRYPTO_VAR, CRYPTO_APPL_CONST) pCrypto_JobInProgress;	/* PRQA S 1527 */
#define CRYPTO_STOP_SEC_VAR_NO_INIT
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_PUBLIC_CODE) Crypto_InitJobQueues(void)
{
    VAR(uint32, CRYPTO_VAR) u32Crypto_ObjectNumber = 0;
    VAR(uint32, CRYPTO_VAR) u32Crypto_QueueNumber = 0;

    for(u32Crypto_ObjectNumber = 0UL;u32Crypto_ObjectNumber < CRYPTO_NUMBER_OF_DRIVER_OBJECTS;u32Crypto_ObjectNumber++) /* PRQA S 1842 */
    {
        for(u32Crypto_QueueNumber = 0U; u32Crypto_QueueNumber < pCrypto_ObjectJobList[u32Crypto_ObjectNumber]->u32Crypto_QueueSize;u32Crypto_QueueNumber++)
        {
            pCrypto_ObjectJobList[u32Crypto_ObjectNumber]->pCrypto_QueuedJobs[u32Crypto_QueueNumber].pJob = NULL_PTR;/* polyspace RTE:COR,IDP */
            pCrypto_ObjectJobList[u32Crypto_ObjectNumber]->pCrypto_QueuedJobs[u32Crypto_QueueNumber].bCrypto_JobValid = FALSE;/* polyspace RTE:COR,IDP */
        }
    }
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_AutoSar_Wrapper_Init
(
    P2CONST(Crypto_ConfigType, CRYPTO_CONST, CRYPTO_APPL_CONST) pCrypto_ConfigPtr
)
{
    VAR(Std_ReturnType, ADC_VAR) u8Crypto_retVal = (Std_ReturnType)E_NOT_OK;

    u8Crypto_retVal = Crypto_Wrapper_Init(pCrypto_ConfigPtr);
    if (u8Crypto_retVal == (Std_ReturnType)E_OK)
    {
        Crypto_InitJobQueues();
    }

    return u8Crypto_retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Wrapper_ProcessJob
(
    VAR(Std_ReturnType, CRYPTO_VAR) u32ObjectIdx,
    P2VAR(Crypto_JobType, CRYPTO_VAR, CRYPY_APPL_DATA) pJob
)
{
    VAR (Std_ReturnType, CRYPTO_VAR) retVal = E_NOT_OK;
    VAR (Crypto_ProcessingType, CRYPTO_VAR) eProcType = pJob->jobPrimitiveInfo->processingType;
#if 0
    if ((CRYPTO_OPERATIONMODE_SINGLECALL != eOptMode)&&
    		(CRYPTO_OPERATIONMODE_START != eOptMode)&&
			(CRYPTO_OPERATIONMODE_UPDATE != eOptMode)&&
			(CRYPTO_OPERATIONMODE_FINISH != eOptMode))
    {
    	retVal = (Std_ReturnType)E_NOT_OK;
    }
#endif

	retVal = Crypto_Wrapper_ProcessOperation(pJob);
	if ((Std_ReturnType)CRYPTO_E_BUSY == retVal)
	{
		if ((CRYPTO_PROCESSING_ASYNC == eProcType) && \
			(0U != pCrypto_ObjectJobList[u32ObjectIdx]->u32Crypto_QueueSize))
		{
			if(pCrypto_JobInProgress != NULL_PTR)
			{
				if (pJob->jobInfo->jobId == pCrypto_JobInProgress->jobInfo->jobId)
				{
					retVal = (Std_ReturnType)E_NOT_OK;
				}
				else
				{
					/* Try to queue the job */
					if((boolean)TRUE == Crypto_InitQueueJob(u32ObjectIdx, pJob))
					{
						/* Set return value to E_OK, as the async job has been queued successfully for later processing */
						retVal = (Std_ReturnType)E_OK;
					}
					else
					{
						/* Job could not be queued as the CDO queue is full */
						retVal = (Std_ReturnType)CRYPTO_E_QUEUE_FULL;
					}
				}
			}
		}
	}
	else
	{
		pJob->jobState = CRYPTO_JOBSTATE_IDLE;
	}
    return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Wrapper_CancelJob
(
    VAR(uint32, CRYPTO_VAR) u32ObjectIdx,
	P2VAR(Crypto_JobInfoType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
)
{
    VAR(Std_ReturnType, CRYPTO_VAR) u8RetVal = (Std_ReturnType)E_NOT_OK;

    u8RetVal = Crypto_Wrapper_CancelJob(u32ObjectIdx, pJob);

    return u8RetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC (Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Wrapper_ImportKey
(
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pKey,
    CONST(uint32, AUTOMATIC) u32KeyLength,
	CONST(uint32, AUTOMATIC) u32CryptoKeyElementIndex
)
{
	VAR(uint16, AUTOMATIC) u16keyType = Crypto_KeyElementList[u32CryptoKeyElementIndex]->u16HsmKeyType;
	VAR(Crypto_KeyFormatType, AUTOMATIC) keyElementFormat = Crypto_KeyElementList[u32CryptoKeyElementIndex]->eCrypto_KeyFormatType;
    VAR(Crypto_KeyElementWriteAccessType, AUTOMATIC) keyElementWriteAccess = Crypto_KeyElementList[u32CryptoKeyElementIndex]->eCrypto_KeyElementWriteAccess;
	VAR(Std_ReturnType, AUTOMATIC) u8RetVal = (Std_ReturnType)E_NOT_OK;

    switch (u16keyType)
    {
    	case HSM_KEY_TYPE_HMAC:
    	case HSM_KEY_TYPE_AES:
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
    	case HSM_KEY_TYPE_SM4:
#endif
    		if (CRYPTO_KE_FORMAT_BIN_OCTET == keyElementFormat)
    		{
    			if (CRYPTO_WA_ENCRYPTED != keyElementWriteAccess)
    			{
    				u8RetVal = Crypto_Wrapper_ImportPlainSymKey(pKey, u32KeyLength, u32CryptoKeyElementIndex);
    			}
    		}
    		break;
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
    	case HSM_KEY_TYPE_SM2_PUB:
    	case HSM_KEY_TYPE_SM2_PRIV:
    	case HSM_KEY_TYPE_SM2_PAIR:
    		if (CRYPTO_KE_FORMAT_BIN_OCTET == keyElementFormat)
    		{
    			if (CRYPTO_WA_ENCRYPTED != keyElementWriteAccess)
    			{
    				u8RetVal = Crypto_Wrapper_ImportPlainSm2Key(pKey, u32CryptoKeyElementIndex);
    			}
    		}
    		break;
#endif
    	case HSM_KEY_TYPE_ECC_PUB:
    	case HSM_KEY_TYPE_ECC_PRIV:
    	case HSM_KEY_TYPE_ECC_PAIR:
    		if (CRYPTO_KE_FORMAT_BIN_OCTET == keyElementFormat)
    		{
    			if (CRYPTO_WA_ENCRYPTED != keyElementWriteAccess)
    			{
    				u8RetVal = Crypto_Wrapper_ImportPlainEccKey(pKey, u32CryptoKeyElementIndex);
    			}
    		}
    		break;

    	case HSM_KEY_TYPE_RSA_PUB:
    	case HSM_KEY_TYPE_RSA_PRIV:
    	case HSM_KEY_TYPE_RSA_PAIR:
    		if (CRYPTO_KE_FORMAT_BIN_OCTET == keyElementFormat)
    		{
    			if (CRYPTO_WA_ENCRYPTED != keyElementWriteAccess)
    			{
    				u8RetVal = Crypto_Wrapper_ImportPlainRsaKey(pKey, u32CryptoKeyElementIndex);
    			}
    		}
    		break;

#if defined(RESOURCE_SUPPORT_CRYPTO_EB4)
    	case HSM_KEY_TYPE_ED_25519_PUB:
    	case HSM_KEY_TYPE_ED_25519_PRIV:

    		if (CRYPTO_KE_FORMAT_BIN_OCTET == keyElementFormat)
    		{
    			if (CRYPTO_WA_ENCRYPTED != keyElementWriteAccess)
    			{
    				u8RetVal = Crypto_Wrapper_ImportPlainED25519Key(pKey, u32CryptoKeyElementIndex);
    			}
    		}
    		break;
#endif

		default:
			u8RetVal = (Std_ReturnType)CRYPTO_E_NOT_SUPPORTED;
			/*Nothing todo*/
			break;
    }

    return u8RetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Wrapper_KeyGenerate
(
    VAR(uint32, AUTOMATIC) u32CryptoKeyId
)
{
    VAR(Std_ReturnType, CRYPTO_VAR) u8RetVal;

    u8RetVal = Crypto_Wrapper_KeyGenerate(u32CryptoKeyId);

    return u8RetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Wrapper_MainFunction(void)
{
    P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob = NULL_PTR;
    VAR(uint32, AUTOMATIC) u32ObjectIdx = 0U;
    VAR(uint32, AUTOMATIC) u32QueueNumber = 0;

    for (u32ObjectIdx = 0U; u32ObjectIdx < CRYPTO_NUMBER_OF_DRIVER_OBJECTS; ++u32ObjectIdx)
    {
        if (NULL_PTR != pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[0].pJob)	/* polyspace RTE:NIP,IDP */
        {
            break;
        }
    }
    if(u32ObjectIdx < CRYPTO_NUMBER_OF_DRIVER_OBJECTS)
    {
        pJob = pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[0].pJob;	/* polyspace RTE:NIP,IDP */
        (void)Crypto_Wrapper_ProcessOperation(pJob);
        for(u32QueueNumber = 0U; ((u32QueueNumber < pCrypto_ObjectJobList[u32ObjectIdx]->u32Crypto_QueueSize)); u32QueueNumber++)
        {
            pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[u32QueueNumber].pJob = pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[u32QueueNumber+1UL].pJob;/* polyspace RTE:COR,IDP,NIP */
            pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[pCrypto_ObjectJobList[u32ObjectIdx]->u32Crypto_QueueSize - 1UL].pJob = NULL_PTR;/* polyspace RTE:COR,IDP */
            pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[pCrypto_ObjectJobList[u32ObjectIdx]->u32Crypto_QueueSize - 1UL].bCrypto_JobValid = (boolean)FALSE;/* polyspace RTE:COR,IDP */
        }
    }
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
