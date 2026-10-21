/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : DIO
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : -
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*****************************************************************************/
/**
*   @file    Dio_LLDriver.h
*   @version 3.0.0
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Dio MCAL driver.
*   @addtogroup Dio
*   @{
*/

#ifndef DIO_LLDRIVERS_H
#define DIO_LLDRIVERS_H

#ifdef __cplusplus
extern "C"{
#endif
/*PRQA S 1755 EOF*/
/* ==============================================INCLUDE FILES======================================= */
#include "derivative.h"
#include "Dio_Cfg.h"

/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define DIO_LLD_H_VENDOR_ID                     176
#define DIO_LLD_H_MAJOR_VERSION                 4
#define DIO_LLD_H_MINOR_VERSION                 4
#define DIO_LLD_H_patch_VERSION                 0
#define DIO_LLD_H_SW_MAJOR_VERSION              3
#define DIO_LLD_H_SW_MINOR_VERSION              0
#define DIO_LLD_H_SW_PATCH_VERSION              0

/* ============================================FILE VERSION CHECKS=================================== */
#if (DIO_LLD_H_VENDOR_ID != DIO_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : DIO_LLD_H_VENDOR_ID "
#endif
#if (DIO_LLD_H_MAJOR_VERSION != DIO_CFG_H_MAJOR_VERSION)
    #error " NON-MATCHED DATA : DIO_LLD_H_MAJOR_VERSION "
#endif
#if (DIO_LLD_H_MINOR_VERSION != DIO_CFG_H_MINOR_VERSION)
    #error " NON-MATCHED DATA : DIO_LLD_H_MINOR_VERSION "
#endif
#if (DIO_LLD_H_patch_VERSION != DIO_CFG_H_patch_VERSION)
    #error " NON-MATCHED DATA : DIO_LLD_H_patch_VERSION "
#endif
#if (DIO_LLD_H_SW_MAJOR_VERSION != DIO_CFG_H_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : DIO_LLD_H_SW_MAJOR_VERSION "
#endif
#if (DIO_LLD_H_SW_MINOR_VERSION != DIO_CFG_H_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : DIO_LLD_H_SW_MINOR_VERSION "
#endif
#if (DIO_LLD_H_SW_PATCH_VERSION != DIO_CFG_H_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : DIO_LLD_H_SW_PATCH_VERSION "
#endif

/* ============================================DEFINES AND MACROS==================================== */

/* ============================================FUNCTION PROTOTYPES=================================== */
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC (Dio_LevelType, DIO_CODE) Dio_LLDrivers_ReadChannel \
( \
    CONST(Dio_ChannelType, AUTOMATIC) u16Dio_ChannelId \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC (void, DIO_CODE) Dio_LLDrivers_WriteChannel \
( \
    CONST(Dio_ChannelType, AUTOMATIC) u16Dio_ChannelId, \
    CONST(Dio_LevelType, AUTOMATIC) u8Dio_Level \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#ifdef __ghs__
#pragma ghs ZO
#endif
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC(Dio_LevelType, DIO_CODE) Dio_LLDrivers_FlipChannel \
( \
    CONST(Dio_ChannelType, AUTOMATIC) u16Dio_ChannelId, \
    VAR(Dio_LevelType, DIO_VAR) u8Dio_ChannelLevel \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#ifdef __ghs__
#pragma ghs OS
#endif
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC (Dio_PortLevelType, DIO_CODE) Dio_LLDrivers_ReadPort \
( \
    CONST(Dio_PortType, DIO_CONST) u8Dio_PortId \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC (void, DIO_CODE) Dio_LLDrivers_WritePort \
( \
    CONST(Dio_PortType, DIO_CONST) u8Dio_PortId, \
    CONST(Dio_PortLevelType, DIO_CONST) uDio_Level \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#if defined(RESOURCE_SUPPORT_SIUL2_IP)
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC (Dio_PortLevelType, DIO_CODE) Dio_LLDrivers_ReadChannelGroup \
( \
    VAR(Dio_PortType, AUTOMATIC) u8Dio_ChannelGroupport, \
    VAR(uint8, AUTOMATIC) u8Dio_ChannelGroupoffset, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_ChannelGroupmask, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_PortLevel \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#elif defined(RESOURCE_SUPPORT_SIUL_IP)
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC (Dio_PortLevelType, DIO_CODE) Dio_LLDrivers_ReadChannelGroup \
( \
    VAR(Dio_PortType, AUTOMATIC) u8Dio_ChannelGroupport, \
    VAR(Dio_PortType, AUTOMATIC) u8Dio_ChannelGroup, \
    VAR(uint8, AUTOMATIC) u8Dio_ChannelGroupoffset, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_ChannelGroupmask, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_PortLevel \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#endif  /* RESOURCE_SUPPORT_SIUL2_IP */
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC (void, DIO_CODE) Dio_LLDrivers_WriteChannelGroup \
( \
    VAR(Dio_PortType, AUTOMATIC) u8Dio_port, \
    VAR(uint8, AUTOMATIC) u8Dio_offset, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_mask, \
    CONST(Dio_PortLevelType, DIO_CONST) u16Dio_Level \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC (void, DIO_CODE) Dio_LLDrivers_MaskedWritePort \
( \
    CONST(Dio_PortType, DIO_CONST) u8Dio_176PortId, \
    CONST(Dio_PortLevelType, DIO_CONST) u16Dio_176Level, \
    CONST(Dio_PortLevelType, DIO_CONST) u16Dio_176Mask \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#ifdef __cplusplus
}
#endif

#endif
