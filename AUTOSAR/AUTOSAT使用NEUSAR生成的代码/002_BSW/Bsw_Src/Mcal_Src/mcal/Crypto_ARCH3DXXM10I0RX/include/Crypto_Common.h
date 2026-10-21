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
*   @file    Crypto_Common.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Crypto MCAL driver.
*
*   @addtogroup Crypto
*   @{
*/
/* PRQA S 0602,1752 EOF */
#ifndef _CRYPTO_COMMON_H_
#define _CRYPTO_COMMON_H_

#include "Crypto_Cfg.h"
#include "Crypto.h"

extern P2VAR(Crypto_ObjectType, AUTOMATIC, CRYPTO_APPL_DATA) pCrypto_ObjectJobList[CRYPTO_NUMBER_OF_DRIVER_OBJECTS];
extern P2VAR(Crypto_KeyType, AUTOMATIC, CRYPTO_APPL_DATA) Crypto_KeyList[CRYPTO_NUMBER_OF_KEYS];
extern P2VAR(Crypto_KeyElementType, AUTOMATIC, CRYPTO_APPL_DATA) Crypto_KeyElementList[CRYPTO_NUMBER_OF_KEY_ELEMENTS];

#define CRYPTO_INVALID_OBJECT_IDX					((uint32)0xFFFFFFFFU)
#define CRYPTO_HSM_INVALID_KEY_IDX					((uint32)0xFFFFFFFFU)
#define CRYPTO_HSM_INVALID_KEY_ELEMENT_IDX			((uint32)0xFFFFFFFFU)

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_CODE) Crypto_memcpy
(
	P2VAR(uint8,   AUTOMATIC,   CRYPTO_APPL_DATA ) pDest,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pSrc,
	VAR(uint32,    AUTOMATIC                     ) nBytes
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_CODE) Crypto_memset
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pDest,
	VAR(uint32, AUTOMATIC					 ) var,
	VAR(uint32, AUTOMATIC				     ) nBytes
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(uint32, CRYPTO_CODE) Crypto_memcmp
(
	P2CONST(uint8, AUTOMATIC,   CRYPTO_APPL_CONST) pSrc1,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pSrc2,
	VAR(uint32,    AUTOMATIC                     ) len
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(boolean, CRYPTO_PRIVATE_CODE) Crypto_InitQueueJob
(
    VAR(uint32, AUTOMATIC) u32ObjectIdx,
    P2CONST(Crypto_JobType, AUTOMATIC,  CRYPTO_APPL_CONST) pJob
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_DequeueJob
(
    VAR(uint32, AUTOMATIC) u32ObjectIdx,
    P2CONST(Crypto_JobInfoType, AUTOMATIC, CRYPTO_APPL_CONST) pJobInfo
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(uint32, CRYPTO_CODE) Crypto_SearchObjectIndex
(
    VAR (uint32, AUTOMATIC) u32ObjectId
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(uint32, CRYPTO_CODE) Crypto_SearchKeyIdIndex
(
    VAR (uint32, AUTOMATIC) u32CryptoKeyId
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(uint32, CRYPTO_CODE) Crypto_SearchKeyElementIdIndex
(
    VAR(uint32, AUTOMATIC) u32keyIndex,
    VAR(uint32, AUTOMATIC) u32keyElementId
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC (Std_ReturnType, CRYPTO_CODE) Crypto_VerifyHsmResp
(
    VAR (status_t, AUTOMATIC) status
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_CODE)Crypto_RestoreKeyValidInfor(void);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#endif /* _CRYPTO_COMMON_H_ */

/** @} */
