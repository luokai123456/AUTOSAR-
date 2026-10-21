/*PRQA S 3332,2053 EOF*/
/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC
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
*   @file    Crc.h
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Crc MCAL driver.
*
*   @addtogroup Crc
*   @{
*/
/*PRQA S 0779,1535,1536,0722,1752 EOF*/
#ifndef CRC_H
#define CRC_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================
INCLUDE FILES
====================================================================================================*/
#include "Crc_Cfg.h"
/*====================================================================================================
HEAD FILE VERSION INFORMATION
====================================================================================================*/
#define CRC_VENDOR_ID                     176
#define CRC_AR_RELEASE_MAJOR_VERSION      4
#define CRC_AR_RELEASE_MINOR_VERSION      4
#define CRC_AR_PATCH_VER                  0
#define CRC_SW_MAJOR_VER                  3
#define CRC_SW_MINOR_VER                  0
#define CRC_SW_PATCH_VER                  0
/*====================================================================================================
FILE VERSION CHECKS
====================================================================================================*/
/* Check if current file and CRC header file are of the same vendor */
#if (CRC_VENDOR_ID != CRC_CFG_H_VENDOR_ID)
#error "NON-MATCHED DATA : CRC_CFG_H_VENDOR_ID"
#endif

/* Check if current file and CRC header file are of the same Autosar version */
#if (CRC_AR_RELEASE_MAJOR_VERSION != CRC_CFG_H_AR_REL_MAJOR_VER)
#error "NON-MATCHED DATA : CRC_CFG_H_AR_REL_MAJOR_VER"
#endif
#if (CRC_AR_RELEASE_MINOR_VERSION != CRC_CFG_H_AR_REL_MINOR_VER)
#error "NON-MATCHED DATA : CRC_CFG_H_AR_REL_MINOR_VER"
#endif
#if (CRC_AR_PATCH_VER != CRC_CFG_H_AR_REL_REV_VER)
#error "NON-MATCHED DATA : CRC_CFG_H_AR_PATCH_VER"
#endif

/* Check if current file and CRC header file are of the same Software version */
#if (CRC_SW_MAJOR_VER != CRC_CFG_H_SW_MAJOR_VER)
#error "NON-MATCHED DATA : CRC_CFG_H_SW_MAJOR_VER"
#endif
#if (CRC_SW_MINOR_VER != CRC_CFG_H_SW_MINOR_VER)
#error "NON-MATCHED DATA : CRC_CFG_H_SW_MINOR_VER"
#endif
#if (CRC_SW_PATCH_VER != CRC_CFG_H_SW_PATCH_VER)
#error "NON-MATCHED DATA : CRC_CFG_H_SW_PATCH_VER"
#endif

/*====================================================================================================
DEFINES
====================================================================================================*/

#define CRC_CORE_NUM                    MCAL_CORE_NUM
/*====================================================================================================
ENUMS
====================================================================================================*/

#define CRC_8_HARDWARE             0
#define CRC_8_RUNTIME              1
#define CRC_8_TABLE                2

#define CRC_8H2F_HARDWARE          0
#define CRC_8H2F_RUNTIME           1
#define CRC_8H2F_TABLE             2

#define CRC_16_HARDWARE            0
#define CRC_16_RUNTIME             1
#define CRC_16_TABLE               2

#define CRC_16_ARC_HARDWARE        0
#define CRC_16_ARC_RUNTIME         1
#define CRC_16_ARC_TABLE           2

#define CRC_32_HARDWARE            0
#define CRC_32_RUNTIME             1
#define CRC_32_TABLE               2

#define CRC_32P4_HARDWARE          0
#define CRC_32P4_RUNTIME           1
#define CRC_32P4_TABLE             2

#define CRC_64_HARDWARE            0
#define CRC_64_RUNTIME             1
#define CRC_64_TABLE               2

#define CRC0                       0
#define CRC1                       1

#define CRC_POLYNOMIAL_8           0x1U
#define CRC_POLYNOMIAL_16          0x2U
#define CRC_POLYNOMIAL_32          0x3U
typedef void (*CRC_Callback_Type)(VAR(uint32, AUTOMATIC) result);
typedef enum{
	CRC_NOUSE,
	CRC_BUSY
}CRC_StatusType;

typedef struct 
{
    VAR(uint8, CRC_VAR) u8CrcChannel; 
    VAR(uint32, CRC_VAR) Calculate;
    VAR(uint8, CRC_VAR) u8CrcId; 
    VAR(uint8, CRC_VAR) u8DMAChannel;
    CRC_Callback_Type CRC_Callback;
} Crc_ConfigGroupType;

typedef struct 
{
    P2CONST( Crc_ConfigGroupType, CRC_CONST, CRC_APPL_CONST ) Crc_ConfigGroup;
} Crc_ConfigType;

extern CONST(Crc_ConfigType, CRC_CONST) Crc_Config;
/*====================================================================================================
TYPEDEFS
====================================================================================================*/

/*====================================================================================================
STRUCT
====================================================================================================*/

/*====================================================================================================
FUNCTION DECLARATION
====================================================================================================*/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(void, CRC_CODE) CRC_GetVersionInfo \
( \
		P2VAR(Std_VersionInfoType, AUTOMATIC, CRC_APPL_DATA) Versioninfo
);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint8, CRC_CODE) Crc_CalculateCRC8(
    P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC) Crc_DataPtr, 
    VAR(uint32, AUTOMATIC) Crc_Length, 
    VAR(uint8, AUTOMATIC) Crc_StartValue8, 
    VAR(boolean, AUTOMATIC) Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint8, CRC_CODE) Crc_CalculateCRC8H2F(
    P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC) Crc_DataPtr, 
    VAR(uint32, AUTOMATIC) Crc_Length, 
    VAR(uint8, AUTOMATIC) Crc_StartValue8, 
    VAR(boolean, AUTOMATIC) Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint16, CRC_CODE) Crc_CalculateCRC16(
    P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC) Crc_DataPtr, 
    VAR(uint32, AUTOMATIC) Crc_Length, 
    VAR(uint16, AUTOMATIC) Crc_StartValue16, 
    VAR(boolean, AUTOMATIC) Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint16, CRC_CODE) Crc_CalculateCRC16ARC(
    P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC) Crc_DataPtr, 
    VAR(uint32, AUTOMATIC) Crc_Length, 
    VAR(uint16, AUTOMATIC) Crc_StartValue16, 
    VAR(boolean, AUTOMATIC) Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint16, CRC_CODE) Crc_CalculateCRC16ARC(
    P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC) Crc_DataPtr, 
    VAR(uint32, AUTOMATIC) Crc_Length, 
    VAR(uint16, AUTOMATIC) Crc_StartValue16, 
    VAR(boolean, AUTOMATIC) Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint32, CRC_CODE) Crc_CalculateCRC32( 
    P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC) Crc_DataPtr, 
    VAR(uint32, AUTOMATIC) Crc_Length, 
    VAR(uint32, AUTOMATIC) Crc_StartValue32, 
    VAR(boolean, AUTOMATIC) Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint32, CRC_CODE) Crc_CalculateCRC32P4(
    P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC) Crc_DataPtr, 
    VAR(uint32, AUTOMATIC) Crc_Length, 
    VAR(uint32, AUTOMATIC) Crc_StartValue32, 
    VAR(boolean, AUTOMATIC) Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint64, CRC_CODE) Crc_CalculateCRC64(
    P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
    VAR(uint32, AUTOMATIC) Crc_Length, 
    VAR(uint64, AUTOMATIC) Crc_StartValue64, 
    VAR(boolean, AUTOMATIC) Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"
/*--------------------------------------------------------*/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint8, CRC_CODE) Crc_CalculateCRC8_Ext(
    P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC) Crc_DataPtr, 
    VAR(uint32, AUTOMATIC) Crc_Length, 
    VAR(uint8, AUTOMATIC) Crc_StartValue8, 
    VAR(boolean, AUTOMATIC) Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint8, CRC_CODE) Crc_CalculateCRC8H2F_Ext(
    P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC) Crc_DataPtr, 
    VAR(uint32, AUTOMATIC) Crc_Length, 
    VAR(uint8, AUTOMATIC) Crc_StartValue8, 
    VAR(boolean, AUTOMATIC) Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint16, CRC_CODE) Crc_CalculateCRC16_Ext(
    P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC) Crc_DataPtr, 
    VAR(uint32, AUTOMATIC) Crc_Length, 
    VAR(uint16, AUTOMATIC) Crc_StartValue16, 
    VAR(boolean, AUTOMATIC) Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint16, CRC_CODE) Crc_CalculateCRC16ARC_Ext(
    P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC) Crc_DataPtr, 
    VAR(uint32, AUTOMATIC) Crc_Length, 
    VAR(uint16, AUTOMATIC) Crc_StartValue16, 
    VAR(boolean, AUTOMATIC) Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint16, CRC_CODE) Crc_CalculateCRC16ARC_Ext(
    P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC) Crc_DataPtr, 
    VAR(uint32, AUTOMATIC) Crc_Length, 
    VAR(uint16, AUTOMATIC) Crc_StartValue16, 
    VAR(boolean, AUTOMATIC) Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint32, CRC_CODE) Crc_CalculateCRC32_Ext( 
    P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC) Crc_DataPtr, 
    VAR(uint32, AUTOMATIC) Crc_Length, 
    VAR(uint32, AUTOMATIC) Crc_StartValue32, 
    VAR(boolean, AUTOMATIC) Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint32, CRC_CODE) Crc_CalculateCRC32P4_Ext(
    P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC) Crc_DataPtr, 
    VAR(uint32, AUTOMATIC) Crc_Length, 
    VAR(uint32, AUTOMATIC) Crc_StartValue32, 
    VAR(boolean, AUTOMATIC) Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint64, CRC_CODE) Crc_CalculateCRC64_Ext(
    P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
    VAR(uint32, AUTOMATIC) Crc_Length, 
    VAR(uint64, AUTOMATIC) Crc_StartValue64, 
    VAR(boolean, AUTOMATIC) Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(Std_ReturnType, CRC_CODE) Crc_AsyncCalculate(
    VAR(uint8, AUTOMATIC) CrcIndex,
    P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
    VAR(uint32, AUTOMATIC) Crc_Length, 
    VAR(uint32, AUTOMATIC) Crc_StartValue32, 
    VAR(boolean, AUTOMATIC)  Crc_IsFirstCall) ;
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"  

#ifdef __cplusplus
}
#endif

#endif /* CRC_H */

