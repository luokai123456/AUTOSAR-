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
*   @file    Dio_AutoSar_Wrapper.h
*   @version 3.0.0
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Dio MCAL driver.
*   @addtogroup Dio
*   @{
*/

#ifndef DIO_AUTOSAR_WRAPPER_H
#define DIO_AUTOSAR_WRAPPER_H

#ifdef __cplusplus
extern "C"{
#endif

/* ==============================================INCLUDE FILES======================================= */
#include "Dio_LLDriver.h"

/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define DIO_ATS_WRA_H_VENDOR_ID                     176
#define DIO_ATS_WRA_H_MAJOR_VERSION                 4
#define DIO_ATS_WRA_H_MINOR_VERSION                 4
#define DIO_ATS_WRA_H_patch_VERSION                 0
#define DIO_ATS_WRAH_SW_MAJOR_VERSION               3
#define DIO_ATS_WRA_H_SW_MINOR_VERSION              0
#define DIO_ATS_WRA_H_SW_PATCH_VERSION              0

/* ============================================FILE VERSION CHECKS=================================== */
#if (DIO_ATS_WRA_H_VENDOR_ID != DIO_LLD_H_VENDOR_ID)
    #error " NON-MATCHED DATA : DIO_ATS_WRA_H_VENDOR_ID "
#endif
#if (DIO_ATS_WRA_H_MAJOR_VERSION != DIO_LLD_H_MAJOR_VERSION)
    #error " NON-MATCHED DATA : DIO_ATS_WRA_H_MAJOR_VERSION "
#endif
#if (DIO_ATS_WRA_H_MINOR_VERSION != DIO_LLD_H_MINOR_VERSION)
    #error " NON-MATCHED DATA : DIO_ATS_WRA_H_MINOR_VERSION "
#endif
#if (DIO_ATS_WRA_H_patch_VERSION != DIO_LLD_H_patch_VERSION)
    #error " NON-MATCHED DATA : DIO_ATS_WRA_H_patch_VERSION "
#endif
#if (DIO_ATS_WRAH_SW_MAJOR_VERSION != DIO_LLD_H_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : DIO_ATS_WRAH_SW_MAJOR_VERSION "
#endif
#if (DIO_ATS_WRA_H_SW_MINOR_VERSION != DIO_LLD_H_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : DIO_ATS_WRA_H_SW_MINOR_VERSION "
#endif
#if (DIO_ATS_WRA_H_SW_PATCH_VERSION != DIO_LLD_H_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : DIO_ATS_WRA_H_SW_PATCH_VERSION "
#endif

/* ============================================FUNCTION PROTOTYPES=================================== */
#define Dio_Auto_Wrap_ReadChannel(ChannelId) \
Dio_LLDrivers_ReadChannel(ChannelId);
#define Dio_Auto_Wrap_WriteChanne(ChannelId,ChannelLevel) \
Dio_LLDrivers_WriteChannel(ChannelId,ChannelLevel);
#define Dio_Auto_Wrap_ReadPort(PortId) \
Dio_LLDrivers_ReadPort(PortId);
#define Dio_Auto_Wrap_WritePort(PortId,Level) \
Dio_LLDrivers_WritePort(PortId,Level);
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC (Dio_PortLevelType, DIO_CODE) Dio_Auto_Wrap_ReadChannelGroup \
( \
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) sDio_ChannelGroupIdPtr \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC (void, DIO_CODE) Dio_Auto_Wrap_WriteChanneGroup \
( \
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) sDio_ChannelGroupIdPtr, \
    CONST(Dio_PortLevelType, DIO_CONST) u16Dio_Level \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC(Dio_LevelType, DIO_CODE) Dio_Auto_Wrap_FlipChannel \
( \
    CONST(Dio_ChannelType, AUTOMATIC) u16Dio_ChannelId \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#if (STD_ON == DIO_MASKEDWRITEPORT_API)
#define Dio_Auto_Wrap_MaskedWritePort(PortId,Level,Mask) \
Dio_LLDrivers_MaskedWritePort(PortId,Level,Mask);
#endif
#ifdef __cplusplus
}
#endif

#endif

