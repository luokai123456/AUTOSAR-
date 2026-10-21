/****************************************************************************
*
* Copyright (c) 2024  C*Core -   All Rights Reserved
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
*   @file    Crypto_AutoSar_Externsion.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Crypto MCAL driver.
*
*   @addtogroup Crypto
*   @{
*/
/*PRQA S 0779 EOF*/
#ifndef CRYPTO_AUTOSAR_EXTERNSION_H
#define CRYPTO_AUTOSAR_EXTERNSION_H

#include "Crypto_LLDriver.h"

typedef struct
{
	uint8*                          pKey[3];
	uint16                          u16KeyLength[3];
} Crypto_HSM_KeyImportExportType;

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_ReadHsmVersion
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pVersion,
	VAR(uint32, AUTOMATIC) versionLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_GetCounter
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pCounter,
	VAR(uint32, AUTOMATIC) counterLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_ReadHsmStack
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pVal,
	VAR(uint32, AUTOMATIC) Len
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_ReadHsmDataVersion
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pVersion,
	VAR(uint32, AUTOMATIC) versionLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_ReadBootType
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pType,
	VAR(uint32, AUTOMATIC) typeLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_ReadSmrEntry
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSmrEntry,
	VAR(uint32, AUTOMATIC) SmrEntryLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_DevAuthReq
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
    VAR(hsmDevAuthOption_t, AUTOMATIC) devAuthOption,
	P2VAR(hsmAuthScheme_t, AUTOMATIC, CRYPTO_APPL_DATA) pAuthScheme,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pChallenge
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_DevAuthResp
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pAuth0,
	VAR(uint32, AUTOMATIC) auth0Len,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pAuth1,
	VAR(uint32, AUTOMATIC) auth1Len
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_DevAuthRst
(
	VAR(hsmDevAuthOption_t, AUTOMATIC) devAuthOption
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_WriteUserData
(
	P2CONST(uint8, AUTOMATIC, CRYPTO_CONST) pData,
	VAR(uint32, AUTOMATIC) len,
	VAR(uint32, AUTOMATIC) offset,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_ReadUserData
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pData,
	VAR(uint32, AUTOMATIC) len,
	VAR(uint32, AUTOMATIC) offset,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_ConfigSecureBoot
(
	VAR(hsmSecureBootType_t, AUTOMATIC) bootType,
	VAR(hsmKeyHandle_t, AUTOMATIC) authKeyHandle,
	VAR(hsmSecureBootFailOp_t, AUTOMATIC) op,
	P2VAR(xoscClkCofigData_t, AUTOMATIC, CRYPTO_APPL_DATA) xoscConfigData,
	P2VAR(verifyCodeSegments, AUTOMATIC, CRYPTO_APPL_DATA) pCodeSegs,
	P2VAR(codeSigns0, AUTOMATIC, CRYPTO_APPL_DATA) pSign,
	VAR(uint32, AUTOMATIC) segcnt,
	VAR(boolean, AUTOMATIC) bootZ4_2,
	VAR(boolean, AUTOMATIC) bootZ7_0,
	VAR(boolean, AUTOMATIC) bootZ7_1
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_ConfigSecureBoot_SWP
(
	VAR(hsmSecureBootType_t, AUTOMATIC) bootType,
	VAR(hsmKeyHandle_t, AUTOMATIC) authKeyHandle,
	VAR(hsmSecureBootFailOp_t, AUTOMATIC) op,
	P2VAR(xoscClkCofigData_t, AUTOMATIC, CRYPTO_APPL_DATA) xoscConfigData,
	P2VAR(verifyCodeSegments, AUTOMATIC, CRYPTO_APPL_DATA) pCodeSegs,
	P2VAR(verifyCodeSegments, AUTOMATIC, CRYPTO_APPL_DATA) pSwpCodeSegs,
	P2VAR(codeSigns0, AUTOMATIC, CRYPTO_APPL_DATA) pSign,
	P2VAR(codeSigns0, AUTOMATIC, CRYPTO_APPL_DATA) pSwpSign,
	VAR(uint32, AUTOMATIC) segcnt,
	VAR(boolean, AUTOMATIC) bootZ4_2,
	VAR(boolean, AUTOMATIC) bootZ7_0,
	VAR(boolean, AUTOMATIC) bootZ7_1
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_InstallSmrEntry
(
	VAR(uint8, AUTOMATIC) bootCore,
	VAR(hsmSecureBootType_t, AUTOMATIC) bootType,
	VAR(hsmSecureBootFailOp_t, AUTOMATIC) op,
	P2VAR(xoscClkCofigData_t, AUTOMATIC, CRYPTO_APPL_DATA) xoscConfigData,
	VAR(uint32, AUTOMATIC) smrCnt,
	P2VAR(hsmSmrEntry_t, AUTOMATIC, CRYPTO_APPL_DATA) pSmrEntry
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_GetSecureBootStatus
(
	P2VAR(hsmSecureBootStatus_t, AUTOMATIC, CRYPTO_APPL_DATA) pSecureBootStatus
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_EnableHsmFeature(void);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_SetIgnoreSecureBootOnce(void);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_FWUpdateInit(void);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_FWUpdateInit_Async(void);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_FWUpdateProcess
(
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pFwImage,
	VAR(uint32, AUTOMATIC) fwLength,
	VAR(uint32, AUTOMATIC) fwOffset
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_FWUpdateProcess_Async
(
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pFwImage,
	VAR(uint32, AUTOMATIC) fwLength,
	VAR(uint32, AUTOMATIC) fwOffset
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_FWUpdateFinal
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(uint32_t, AUTOMATIC) fwLength,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) mac
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_FWUpdateFinal2
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(uint32_t, AUTOMATIC) fwLength,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) mac,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) dVer,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) stDycode,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) runDycode,
	VAR(uint32, AUTOMATIC) codeLength
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_FWUpdateFinal_Async
(
	VAR(uint32, AUTOMATIC) fwLength,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) key,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) mac
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_FWUpdateFinal_Async_New
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(uint32_t, AUTOMATIC) fwLength,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) mac
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_CheckServiceResponce
(
	P2VAR(status_t, AUTOMATIC, CRYPTO_APPL_DATA) pStatus
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_RamWait_S0
(
	P2VAR(volatile uint32_t, AUTOMATIC, CRYPTO_APPL_DATA) checkaddr,
	VAR(uint32_t, AUTOMATIC) ram_timeout
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_RamWait_S1
(
	P2VAR(volatile uint32_t, AUTOMATIC, CRYPTO_APPL_DATA) checkaddr
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_RamWait_S1_Err(void);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_GetKeyHash
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pkeyHash
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#endif /* CRYPTO_AUTOSAR_EXTERNSION_H */
