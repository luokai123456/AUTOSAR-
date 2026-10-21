/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : SENT
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : -
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*  
*****************************************************************************/
/* PRQA S 0380, 1258, 4445, 1533 EOF */
/**
*   @file    Sent_Cfg.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Sent MCAL driver.
*
*   @addtogroup Sent
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Sent.h"
#include "Sent_Cfg.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define SENT_VENDOR_ID                           176
#define SENT_CFG_C_AR_MAJOR_VER                  4
#define SENT_CFG_C_AR_MINOR_VER                  4
#define SENT_CFG_C_AR_PATCH_VER                  0
#define SENT_CFG_C_SW_MAJOR_VER                  3
#define SENT_CFG_C_SW_MINOR_VER                  0
#define SENT_CFG_C_SW_PATCH_VER                  0

/*============================================FILE VERSION CHECKS===================================*/
#if (MCAL_VENDOR_ID != SENT_VENDOR_ID)
    #error " NON-MATCHED DATA : SENT_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != SENT_CFG_C_AR_MAJOR_VER)
    #error " NON-MATCHED DATA : SENT_CFG_AR_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != SENT_CFG_C_AR_MINOR_VER)
    #error " NON-MATCHED DATA : SENT_CFG_AR_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != SENT_CFG_C_AR_PATCH_VER)
    #error " NON-MATCHED DATA : SENT_CFG_AR_PATCH_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != SENT_CFG_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : SENT_CFG_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != SENT_CFG_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : SENT_CFG_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != SENT_CFG_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : SENT_CFG_SW_PATCH_VER "
#endif

extern void Sensor_srxNotification(Sent_ChannelType channel, srx_callback_type_t type); /*PRQA S 1753*/

#if (SENT_ENABLE_MULTICORE == STD_ON)
#define SENT_START_SEC_CONFIG_DATA
#include "Sent_MemMap.h"
static CONST(Sent_CoreMapItemType, SENT_CONST) Sent_CoreMap[1] =
{
    {
        .u8HwChannel = 0,
        .u8CoreId = 0
    },
};
#define SENT_STOP_SEC_CONFIG_DATA
#include "Sent_MemMap.h"
#endif

#define SENT_START_SEC_CONFIG_DATA
#include "Sent_MemMap.h"
static CONST(Sent_ChannelCfgtype, SENT_CONST) Sent_InitChannel[1] =
{
    {
        .u8ChannelId = (uint8)(SENT_0_CH_0),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_2,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_BOTH,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_NOT_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_DISABLE,
            .crcType = SRX_CRC_RECOMMENDED
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_RECOMMENDED,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
};
#define SENT_STOP_SEC_CONFIG_DATA
#include "Sent_MemMap.h"

#define SENT_START_SEC_CONFIG_DATA
#include "Sent_MemMap.h"
CONST(Sent_ConfigType, SENT_CONST)SentChannelConfigSet =
{
    .u8MaxHwChannels = (uint8)1U,
    .u8TimestampPrescaler = (uint8)100U,
    .u32SentClkFreq = (uint32)100000000U,
#if (SENT_ENABLE_MULTICORE == STD_ON)
    .pCoreMap = Sent_CoreMap,
#endif
    .pChanCfgPtr = Sent_InitChannel,
};
#define SENT_STOP_SEC_CONFIG_DATA
#include "Sent_MemMap.h"

#ifdef __cplusplus
}
#endif
