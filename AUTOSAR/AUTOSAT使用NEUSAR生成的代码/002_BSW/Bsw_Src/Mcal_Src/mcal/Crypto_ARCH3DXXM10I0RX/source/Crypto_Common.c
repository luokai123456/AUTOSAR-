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
*   @file    Crypto_Common.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Crypto MCAL driver.
*
*   @addtogroup Crypto
*   @{
*/

/* PRQA S 0380, 3432, 1330, 0498, 4461, 0491 EOF */
/* PRQA S 0311, 1258, 1842, 2844, 2982, 2902 EOF */
#ifdef __cplusplus
extern "C"{
#endif

#include "Crypto_Common.h"

/*******************************************************************************
 * Code
 ******************************************************************************/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
/************************************************************************
 * @brief      Crypto_memcpy function.
 *             This function shall be copy data buffer.
 * @param[in]  uint8_t * dest, const uint8_t * src, uint32_t bytes
 * @param[out] None
 * @notapi
 *************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_CODE) Crypto_memcpy
(
	P2VAR(uint8,   AUTOMATIC,   CRYPTO_APPL_DATA ) pDest,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pSrc,
	VAR(uint32,    AUTOMATIC                     ) nBytes
)
{
    uint32 bytes_temp;
    uint8 * dest_temp = NULL_PTR;
    uint8 const * src_temp = NULL_PTR;

    bytes_temp = nBytes;
    dest_temp = pDest;
    src_temp = pSrc;

    while (bytes_temp > 0u)
    {
        *dest_temp = *src_temp;/* polyspace RTE:COR,IDP */
        bytes_temp--;
        if (0u == bytes_temp)
        {
            break;
        }
        dest_temp++;
        src_temp++;
    }
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/************************************************************************
 * @brief      Crypto_memset function.
 *             This function shall be set buffer value.
 * @param[in]  uint8_t * dest, uint8_t val, uint32_t bytes
 * @param[out] None
 * @notapi
 *************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_CODE) Crypto_memset
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pDest,
	VAR(uint32, AUTOMATIC					 ) var,
	VAR(uint32, AUTOMATIC				     ) nBytes
)
{
    uint32 bytes_temp;
    uint8  * dest_temp = NULL_PTR;

    dest_temp = pDest;
    bytes_temp = nBytes;

    while (bytes_temp > 0u)
    {
        *dest_temp = var;/* polyspace RTE:COR,IDP */
        bytes_temp--;
        if (0u == bytes_temp)
        {
            break;
        }
        dest_temp++;
    }
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/************************************************************************
 * @brief      Crypto_memcmp function.
 *             This function shall be compare buffer value.
 * @param[in]  const void *src1, const void *src2, uint32_t len
 * @param[out] None
 * @notapi
 *************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(uint32, CRYPTO_CODE) Crypto_memcmp
(
	P2CONST(uint8, AUTOMATIC,   CRYPTO_APPL_CONST) pSrc1,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pSrc2,
	VAR(uint32,    AUTOMATIC                     ) len
)
{
    uint8 const *p1 = NULL_PTR;
    uint8 const *p2 = NULL_PTR;
    uint32 len_temp = 0u;

    len_temp = len;
    p1 = pSrc1;
    p2 = pSrc2;

    do
    {
        if (*p1 != *p2)/* polyspace RTE:COR,IDP */
        {
            return 1;
        }
        p1++;
        p2++;
        len_temp--;
    } while (len_temp != 0u);

    return 0;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(boolean, CRYPTO_PRIVATE_CODE) Crypto_InitQueueJob
(
    VAR(uint32, AUTOMATIC) u32ObjectIdx,
    P2CONST(Crypto_JobType, AUTOMATIC,  CRYPTO_APPL_CONST) pJob
)
{
    VAR(boolean, AUTOMATIC) bJobQueued   = (boolean)FALSE;
    P2VAR(Crypto_JobType, AUTOMATIC,  CRYPTO_APPL_CONST) pCrypto_Job = NULL_PTR;
    VAR(uint32,AUTOMATIC) u32QueueJobNumber = 0 ;
    VAR(uint32,AUTOMATIC) u32QueueNumber = 0 ;
    VAR(boolean, AUTOMATIC) bJobFreeQueued = (boolean)FALSE;

    for(u32QueueNumber = 0U; (( u32QueueNumber < pCrypto_ObjectJobList[u32ObjectIdx]->u32Crypto_QueueSize) &&((boolean)FALSE == bJobFreeQueued )); u32QueueNumber++)
    {
        if ((boolean)FALSE == pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[u32QueueNumber].bCrypto_JobValid)
        {
            bJobFreeQueued = (boolean)TRUE;
            u32QueueJobNumber = u32QueueNumber;
            pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[u32QueueNumber].bCrypto_JobValid = (boolean)TRUE;
            pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[u32QueueNumber].pJob = (P2VAR(Crypto_JobType, AUTOMATIC,  CRYPTO_APPL_CONST))pJob;
        }
    }
    if ((boolean)TRUE == bJobFreeQueued)
    {
        for(u32QueueNumber = 0U; ( u32QueueNumber < pCrypto_ObjectJobList[u32ObjectIdx]->u32Crypto_QueueSize); u32QueueNumber++)
        {
            if(0UL == u32QueueJobNumber )
            {
                /* do nothing */
            }
            else
            {
                if ( pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[u32QueueJobNumber].pJob->jobInfo->jobPriority >\
                        pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[u32QueueNumber].pJob->jobInfo->jobPriority)
                {
                    pCrypto_Job = pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[u32QueueNumber].pJob;
                    pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[u32QueueNumber].pJob = pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[u32QueueJobNumber].pJob;
                    pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[u32QueueJobNumber].pJob = pCrypto_Job;
                }
            }
        }
        bJobQueued = (boolean)TRUE;
    }
    else
    {
        bJobQueued = (boolean)FALSE;
    }
    return bJobQueued;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_DequeueJob
(
    VAR(uint32, AUTOMATIC) u32ObjectIdx,
    P2CONST(Crypto_JobInfoType, AUTOMATIC, CRYPTO_APPL_CONST) pJobInfo
)
{
    VAR  (Std_ReturnType, AUTOMATIC                  ) eRetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32,AUTOMATIC) u32QueueNumber = 0;
    VAR(uint32,AUTOMATIC) u32QueueJobNumber = 0 ;
    VAR(boolean,AUTOMATIC)bJobAlreadyQueued = (boolean)FALSE;
    for(u32QueueNumber = 0U; ((u32QueueNumber < pCrypto_ObjectJobList[u32ObjectIdx]->u32Crypto_QueueSize)&&((boolean)FALSE == bJobAlreadyQueued)); u32QueueNumber++)/* polyspace RTE:OBAI */
    {
        if ( pJobInfo->jobId == pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[u32QueueNumber].pJob->jobId)/* polyspace RTE:NIV,COR,IDP,NIP */ 
        {
            bJobAlreadyQueued = (boolean)TRUE;
            for(u32QueueJobNumber = u32QueueNumber; u32QueueJobNumber < (pCrypto_ObjectJobList[u32ObjectIdx]->u32Crypto_QueueSize - 1UL); u32QueueJobNumber++)
            {
                pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[u32QueueJobNumber].pJob = pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[u32QueueJobNumber+1UL].pJob;/* polyspace RTE:COR,IDP,NIP */
                pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[pCrypto_ObjectJobList[u32ObjectIdx]->u32Crypto_QueueSize - 1UL].pJob = NULL_PTR;/* polyspace RTE:COR,IDP */
                pCrypto_ObjectJobList[u32ObjectIdx]->pCrypto_QueuedJobs[pCrypto_ObjectJobList[u32ObjectIdx]->u32Crypto_QueueSize - 1UL].bCrypto_JobValid = (boolean)FALSE;/* polyspace RTE:COR,IDP */
            }
            eRetVal = (Std_ReturnType)E_OK;
        }
    }
    return eRetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(uint32, CRYPTO_CODE) Crypto_SearchObjectIndex
(
    VAR (uint32, AUTOMATIC) u32ObjectId
)
{
	return (u32ObjectId < CRYPTO_NUMBER_OF_DRIVER_OBJECTS) ? u32ObjectId : CRYPTO_INVALID_OBJECT_IDX;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(uint32, CRYPTO_CODE) Crypto_SearchKeyIdIndex
(
    VAR (uint32, AUTOMATIC) u32CryptoKeyId
)
{
    return (u32CryptoKeyId < CRYPTO_NUMBER_OF_KEYS) ? u32CryptoKeyId : CRYPTO_HSM_INVALID_KEY_IDX;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(uint32, CRYPTO_CODE) Crypto_SearchKeyElementIdIndex
(
    VAR(uint32, CRYPTO_VAR) u32keyIndex,
    VAR(uint32, CRYPTO_VAR) u32keyElementId
)
{
    VAR(uint32, CRYPTO_VAR) u32Crypto_KeyElementCounter;
    VAR(uint32, CRYPTO_VAR) u32keyElementIdx = CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX;
    if(u32keyIndex < CRYPTO_NUMBER_OF_KEYS)
    {
        for (u32Crypto_KeyElementCounter = 0U;
         u32Crypto_KeyElementCounter < Crypto_KeyList[u32keyIndex]->pCrypto_KeyElementConfig->u32CryptoKeyElementsCount;/* polyspace RTE:OBAI */
         u32Crypto_KeyElementCounter++)
        {
            if (u32keyElementId == Crypto_KeyElementList[Crypto_KeyList[u32keyIndex]->pCrypto_KeyElementConfig->pCryptoKeyElementsNumberConfig[u32Crypto_KeyElementCounter]]->u32Crypto_KeyElementId)/* polyspace RTE:COR,IDP,OBAI */
            {
                u32keyElementIdx = Crypto_KeyList[u32keyIndex]->pCrypto_KeyElementConfig->pCryptoKeyElementsNumberConfig[u32Crypto_KeyElementCounter];
                break;
            }
        }
    }

    return u32keyElementIdx;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC (Std_ReturnType, CRYPTO_CODE) Crypto_VerifyHsmResp
(
    VAR (status_t, AUTOMATIC) status
)
{
    VAR (Std_ReturnType, AUTOMATIC) retVal;

    switch (status)
    {
    case STATUS_SUCCESS:
    	retVal = (Std_ReturnType)E_OK;
    	break;
    case STATUS_TIMEOUT:
    	retVal = (Std_ReturnType)CRYPTO_RET_OPERATION_TIMEOUT;
    	break;
    case STATUS_HSM_GENERAL_ERRPR:
    	retVal = (Std_ReturnType)E_NOT_OK;
    	break;
    case STATUS_HSM_SEQUENCE_ERROR:
    	retVal = (Std_ReturnType)E_NOT_OK;
    	break;
    case STATUS_HSM_KEY_NOT_AVAILABLE:
    	retVal = (Std_ReturnType)CRYPTO_E_KEY_NOT_AVAILABLE;
    	break;
    case STATUS_HSM_KEY_INVALID:
    	retVal = (Std_ReturnType)CRYPTO_E_KEY_NOT_VALID;
    	break;
    case STATUS_HSM_KEY_EMPTY:
    	retVal = (Std_ReturnType)CRYPTO_E_KEY_EMPTY;
    	break;
    case STATUS_HSM_NO_SECURE_BOOT:
    	retVal = (Std_ReturnType)E_NOT_OK;
    	break;
    case STATUS_HSM_KEY_WRITE_PROTECTED:
    	retVal = (Std_ReturnType)CRYPTO_E_KEY_WRITE_FAIL;
    	break;
    case STATUS_HSM_KEY_UPDATE_ERROR:
    	retVal = (Std_ReturnType)E_NOT_OK;
        break;
    case STATUS_HSM_RNG_SEED:
    	retVal = (Std_ReturnType)E_NOT_OK;
    	break;
    case STATUS_HSM_DEV_AUTH_FAILED:
    	retVal = (Std_ReturnType)E_NOT_OK;
    	break;
    case STATUS_HSM_INVALID_COMMAND:
    	retVal = (Std_ReturnType)E_NOT_OK;
    	break;
    case STATUS_HSM_INVALID_PARAM:
    	retVal = (Std_ReturnType)CRYPTO_RET_INVALID_PARAM;
    	break;
    case STATUS_HSM_HSM_FLASH_BLOCK_ERROR:
    	retVal = (Std_ReturnType)E_NOT_OK;
    	break;
    case STATUS_HSM_NOT_ENOUGH_SPACE:
    	retVal = (Std_ReturnType)E_NOT_OK;
    	break;
    case STATUS_HSM_DECRYPT_FAIL:
    	retVal = (Std_ReturnType)E_NOT_OK;
    	break;
    case STATUS_HSM_NOT_ALLOWED:
    	retVal = (Std_ReturnType)E_NOT_OK;
    	break;
    case STATUS_HSM_NOT_SUPPORTED:
    	retVal = (Std_ReturnType)CRYPTO_RET_NOT_SUPPORTED;
    	break;
    case STATUS_HSM_NULL_POINTER:
    	retVal = (Std_ReturnType)CRYPTO_E_PARAM_POINTER;
    	break;
    case STATUS_HSM_VERIFY_FAILED:
    	retVal = (Std_ReturnType)E_NOT_OK;
    	break;
    case STATUS_HSM_OPERATION_TIMEOUT:
    	retVal = (Std_ReturnType)E_NOT_OK;
    	break;
    case STATUS_HSM_DEV_NOT_AUTHED:
    	retVal = (Std_ReturnType)E_NOT_OK;
    	break;
    case STATUS_HSM_SMALL_BUFFER:
    	retVal = (Std_ReturnType)CRYPTO_E_SMALL_BUFFER;
    	break;
    case STATUS_HSM_LENGTH_ERROR:
    	retVal = (Std_ReturnType)E_NOT_OK;
    	break;
    default:
    	retVal = (Std_ReturnType)E_NOT_OK;
    	break;
    }

    return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_CODE)Crypto_RestoreKeyValidInfor(void)
{

    VAR(uint32, AUTOMATIC) u32CryptoKeyIndex = 0U;
    VAR(uint32,AUTOMATIC) cryptoKeyMaterialElemIndex;
    VAR(hsmKeyInfo_t,AUTOMATIC) keyInfo;
    VAR(uint16_t,AUTOMATIC) AppStatus= (uint16_t)STATUS_SUCCESS;

    for (u32CryptoKeyIndex = 0; u32CryptoKeyIndex < CRYPTO_NUMBER_OF_KEYS; u32CryptoKeyIndex++)
    {

    	if(Crypto_KeyList[u32CryptoKeyIndex]->bCrypto_KeyValid == (boolean)TRUE)
    	{

        	cryptoKeyMaterialElemIndex = Crypto_SearchKeyElementIdIndex(u32CryptoKeyIndex, CRYPTO_KE_CIPHER_KEY);
        	if (CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX != cryptoKeyMaterialElemIndex)
        	{

        		if(Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle != HSM_INVALID_KEY_HANDLE)
        		{
            		AppStatus = (uint16_t)HSM_LLD_GetKeyInfo((Crypto_KeyElementList[cryptoKeyMaterialElemIndex]->u32HsmKeyHandle), &keyInfo);
            		if ((uint16_t)STATUS_SUCCESS != AppStatus)
            		{
            			Crypto_KeyList[u32CryptoKeyIndex]->bCrypto_KeyValid = (boolean)FALSE;

            		}
        		}
        	}
    	}
    }
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
