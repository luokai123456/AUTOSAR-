/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           :
*   Dependencies         :
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           :
*   Build Version        :
*
*****************************************************************************/

/**
*   @file    Crypto_HAL_Wrapper.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Can MCAL driver.
*
*   @addtogroup Crypto
*   @{
*/

#ifndef CRYPTO_HAL_WRAPPER_H
#define CRYPTO_HAL_WRAPPER_H

#include "Crypto_LLDriver.h"

#define CRYPTO_HSM_CMAC_OUT_LEN             ((uint32)0x10U)
#define CRYPTO_HSM_SHA256_OUT_LEN           ((uint32)0x20U)
#define CRYPTO_HSM_MP_COMP_OUT_LEN          ((uint32)0x10U)
#define CRYPTO_HSM_AES_BLOCK_SIZE           ((uint32)0x10U)
#define CRYPTO_HSM_RESULT_LEN               ((uint32)0x20U)

/*===========================================VARIABLE DECLARATIONS==================================*/


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_VerifyHsmStatus	/* PRQA S 1753 */
(
    VAR(status_t, CRYPTO_VAR) status
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_Init
(
    P2CONST(Crypto_ConfigType, CRYPTO_CONST, CRYPTO_APPL_CONST) pCrypto_ConfigPtr
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_Wrapper_DequeueJob
(
    VAR(uint32, CRYPTO_VAR) u32ObjectIdx,
	P2VAR(Crypto_JobInfoType, AUTOMATIC, CRYPTO_APPL_DATA) pJobInfo
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_Hash
(
	P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_RandomGenerate
(
	P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_Wrapper_MacGenerate
(
	P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_MacVerify
(
	P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_Encrypt
(
	P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_Decrypt
(
	P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_AeadEncrypt
(
	P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_AeadDecrypt
(
	P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_SignatureGenerate
(
	P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_SignatureVerify
(
	P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_ImportPlainSymKey
(
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pKey,
	VAR(uint32, AUTOMATIC) u32KeyLength,
	VAR(uint32, AUTOMATIC) u32KeyMaterialKeyElemIdx
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_ImportPlainSm2Key
(
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pKey,
	VAR(uint32, AUTOMATIC) u32KeyMaterialKeyElemIdx
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_ImportPlainEccKey
(
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pKey,
	VAR(uint32, AUTOMATIC) u32KeyMaterialKeyElemIdx
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#if defined(RESOURCE_SUPPORT_CRYPTO_EB4)
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_ImportPlainED25519Key
(
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pKey,
	VAR(uint32, AUTOMATIC) u32KeyMaterialKeyElemIdx
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Wrapper_ImportPlainRsaKey
(
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pKey,
	VAR(uint32, AUTOMATIC) u32KeyMaterialKeyElemIdx
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_Wrapper_KeyGenerate
(
    VAR(uint32, AUTOMATIC) cryptoKeyId
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_Wrapper_ProcessOperation
(
	P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_Wrapper_CancelJob
(
    VAR(uint32, AUTOMATIC) ObjectIdx,
	P2VAR(Crypto_JobInfoType, AUTOMATIC, CRYPTO_APPL_DATA) pJob
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#endif /* CRYPTO_HAL_WRAPPER_H */


/** @} */
