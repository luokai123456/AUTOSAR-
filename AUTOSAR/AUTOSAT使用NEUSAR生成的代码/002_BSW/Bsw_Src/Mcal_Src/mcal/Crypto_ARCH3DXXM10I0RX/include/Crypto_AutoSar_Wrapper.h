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
*   Autosar Revision     :
*   Autosar Conf.Variant :
*   SW Version           :
*   Build Version        :
*
*****************************************************************************/

/**
*   @file    Crypto_AutoSar_Wrapper.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Crypto MCAL driver.
*
*   @addtogroup Crypto
*   @{
*/

#ifndef CRYPTO_AUTOSAR_WRAPPER_H
#define CRYPTO_AUTOSAR_WRAPPER_H

#include "Crypto_Cfg.h"
#include "Crypto_HAL_Wrapper.h"

/*===========================================VARIABLE DECLARATIONS==================================*/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_PUBLIC_CODE) Crypto_InitJobQueues(void);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_AutoSar_Wrapper_Init
(
    P2CONST(Crypto_ConfigType, AUTOMATIC, CRYPTO_APPL_CONST) pCrypto_ConfigPtr
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Wrapper_ProcessJob
(
    VAR(Std_ReturnType, AUTOMATIC) u32ObjectIdx,
    P2VAR(Crypto_JobType, AUTOMATIC, CRYPY_APPL_DATA) pJob
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Wrapper_CancelJob
(
    VAR(uint32, CRYPTO_VAR) u32ObjectIdx,
	P2VAR(Crypto_JobInfoType, AUTOMATIC, CRYPTO_APPL_CONST) pJob
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC (Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Wrapper_ImportKey
(
    P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_CONST) pKey,
    CONST(uint32, AUTOMATIC) u32KeyLength,
	CONST(uint32, AUTOMATIC) u32CryptoKeyElementIndex
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Wrapper_KeyGenerate
(
    VAR(uint32, AUTOMATIC) u32CryptoKeyId
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Wrapper_MainFunction(void);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#endif /* ADC_AUTOSAR_WRAPPER_H */

/** @} */
