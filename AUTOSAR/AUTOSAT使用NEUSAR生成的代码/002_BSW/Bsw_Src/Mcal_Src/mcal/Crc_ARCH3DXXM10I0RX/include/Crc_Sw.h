/*PRQA S 2053 EOF*/
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
*   @file    Crc_Hw.h
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Crc MCAL driver.
*
*   @addtogroup Crc
*   @{
*/

#ifndef CRC_SW_H
#define CRC_SW_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================
INCLUDE FILES
====================================================================================================*/
#include "Crc.h"
/*====================================================================================================
HEAD FILE VERSION INFORMATION
====================================================================================================*/
#define CRC_SW_VENDOR_ID                     176
#define CRC_SW_AR_MAJOR_VER                  4
#define CRC_SW_AR_MINOR_VER                  4
#define CRC_SW_AR_PATCH_VER                  0
#define CRC_SW_SW_MAJOR_VER                  3
#define CRC_SW_SW_MINOR_VER                  0
#define CRC_SW_SW_PATCH_VER                  0
/*====================================================================================================
FILE VERSION CHECKS
====================================================================================================*/
/* Check if current file and CRC header file are of the same vendor */
#if (CRC_SW_VENDOR_ID != CRC_VENDOR_ID)
#error "NON-MATCHED DATA : CRC_VENDOR_ID"
#endif

/* Check if current file and CRC header file are of the same Autosar version */
#if (CRC_SW_AR_MAJOR_VER != CRC_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : CRC_AR_RELEASE_MAJOR_VERSION"
#endif
#if (CRC_SW_AR_MINOR_VER != CRC_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : CRC_AR_RELEASE_MINOR_VERSION"
#endif
#if (CRC_SW_AR_PATCH_VER != CRC_AR_PATCH_VER)
#error "NON-MATCHED DATA : CRC_AR_PATCH_VER"
#endif

/* Check if current file and CRC header file are of the same Software version */
#if (CRC_SW_SW_MAJOR_VER != CRC_SW_MAJOR_VER)
#error "NON-MATCHED DATA : CRC_SW_MAJOR_VER"
#endif
#if (CRC_SW_SW_MINOR_VER != CRC_SW_MINOR_VER)
#error "NON-MATCHED DATA : CRC_SW_MINOR_VER"
#endif
#if (CRC_SW_SW_PATCH_VER != CRC_SW_PATCH_VER)
#error "NON-MATCHED DATA : CRC_SW_PATCH_VER"
#endif

/*====================================================================================================
DEFINES
====================================================================================================*/

/*====================================================================================================
ENUMS
====================================================================================================*/

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
FUNC(uint8, CRC_CODE) Crc_Sw_CalculateCRC8(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
                                 VAR(uint32, AUTOMATIC) Crc_Length, 
                                 VAR(uint8, AUTOMATIC) Crc_StartValue,
                                 VAR(uint8, AUTOMATIC) Polynomial );
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint16, CRC_CODE) Crc_Sw_CalculateCRC16(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
                                VAR(uint32, AUTOMATIC) Crc_Length, 
                                VAR(uint16, AUTOMATIC) Crc_StartValue);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint16, CRC_CODE) Crc_Sw_CalculateCRC16ARC(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
                                VAR(uint32, AUTOMATIC) Crc_Length, 
                                VAR(uint16, AUTOMATIC) Crc_StartValue );
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint32, CRC_CODE) Crc_Sw_CalculateCRC32(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
                                VAR(uint32, AUTOMATIC) Crc_Length, 
                                VAR(uint32, AUTOMATIC) Crc_StartValue,
                                VAR(uint32, AUTOMATIC) Polynomial );
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint64, CRC_CODE) Crc_Sw_CalculateCRC64(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
                                VAR(uint32, AUTOMATIC) Crc_Length, 
                                VAR(uint64, AUTOMATIC) Crc_StartValue,
                                VAR(uint64, AUTOMATIC) Polynomial );
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* CRC_SW_H */
