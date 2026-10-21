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
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/

/**
*   @file    Sent.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of SENT MCAL driver.
*
*   @addtogroup SENT
*   @{
*/

#ifndef SENT_H
#define SENT_H

#include "SENT_LLDriver.h"
#include "Std_Types.h"
#include "Sent_Cfg.h"

#ifdef RESOURCE_SUPPORT_SENT

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define SENT_VENDOR_ID_H                     176
#define SENT_MODULE_ID_H                     100
#define SENT_AR_MAJOR_VER_H                  4
#define SENT_AR_MINOR_VER_H                  4
#define SENT_AR_PATCH_VER_H                  0
#define SENT_SW_MAJOR_VER_H                  3
#define SENT_SW_MINOR_VER_H                  0
#define SENT_SW_PATCH_VER_H                  0

/*============================================FILE VERSION CHECKS===================================*/

#if (SENT_VENDOR_ID_H != SENT_VENDOR_ID)
#error "NON-MATCHED DATA : SENT_CFG_VENDOR_ID"
#endif

#if (SENT_AR_MAJOR_VER_H != SENT_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_AR_MAJOR_VER"
#endif
#if (SENT_AR_MINOR_VER_H != SENT_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_AR_MINOR_VER"
#endif
#if (SENT_AR_PATCH_VER_H != SENT_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : SENT_CFG_AR_PATCH_VER"
#endif

#if (SENT_SW_MAJOR_VER_H != SENT_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_SW_MAJOR_VER"
#endif
#if (SENT_SW_MINOR_VER_H != SENT_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_SW_MINOR_VER"
#endif
#if (SENT_SW_PATCH_VER_H != SENT_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : SENT_CFG_SW_PATCH_VER"
#endif


#define SENT_MODULE_ID                       255

#define SENT_CORE_NUM                        MCAL_CORE_NUM

#if (SENT_ENABLE_MULTICORE == STD_ON)
    #define Sent_GetCoreID()     (GetCoreID())
#else
    #define Sent_GetCoreID()     SENT_DEFAULT_COREID
#endif

#define SENT_MAX_PARTITION          RESOURCE_CHIP_CORE_NUM
#define SENT_INSTANCE_ID            ((uint8)0U)

#define SENT_SID_INIT               ((uint8)0x00U)
#define SENT_SID_SETCHANNEL         ((uint8)0x01U)
#define SENT_SID_READDATA           ((uint8)0x02U)
#define SENT_SID_READSERIALDATA     ((uint8)0x03U)
#define SENT_SID_READCHANNELSTATUS  ((uint8)0x04U)
#define SENT_SID_SPCGENPULSE        ((uint8)0x05U)
#define SENT_SID_SETWDGTIMER        ((uint8)0x06U)
#define SENT_SID_GETVERSIONINFO     ((uint8)0x07U)
#define SENT_SID_GETACCESSENABLE    ((uint8)0x08U)
#define SENT_SID_SETACCESSENABLE    ((uint8)0x09U)
#define SENT_SID_DEINIT             ((uint8)0x0AU)

#define SENT_E_ALREADY_INITIALIZED  ((uint8)0x00U)
#define SENT_E_PARAM_INSTANCE       ((uint8)0x01U)
#define SENT_E_PARAM_POINTER        ((uint8)0x02U)
#define SENT_E_PARAM_CHANNEL        ((uint8)0x03U)
#define SENT_E_PARAM_CONFIG         ((uint8)0x04U)
#define SENT_E_UNINIT               ((uint8)0x05U)
#define SENT_E_PARAM_INVALID        ((uint8)0x06U)
#define SENT_E_CORE                 ((uint8)0x07U)

typedef uint8  Sent_ChannelType;
typedef P2FUNC(void, GPT_APPL_CODE, Sent_NotifFnPtrType)(Sent_ChannelType Channel, uint32 event);/* PRQA S 1535 */

typedef enum
{
    SENT_UNINIT = 0U,
    SENT_READY  = 1U
} Sent_StatusType;

typedef enum
{
    SENT_DISABLE = 0U,
    SENT_ENABLE = 1U,
}Sent_StatType;

typedef P2FUNC(void, SENT_APPL_CODE, Sent_NotificationFunc)(Sent_ChannelType channel, srx_callback_type_t type);

#if (SENT_ENABLE_MULTICORE == STD_ON)
typedef struct{
    VAR(uint8, SENT_VAR) u8HwChannel;
    VAR(uint8, SENT_VAR) u8CoreId;
}Sent_CoreMapItemType;
#endif

typedef struct
{
    VAR(Sent_ChannelType,           SENT_VAR) u8ChannelId;
    VAR(float32,                    SENT_VAR) u8TickDuration;
    VAR(srx_channel_input_filter_t, SENT_VAR) inputFilter;
    VAR(srx_diag_config_t,          SENT_VAR) sSentDiagCfg;
    VAR(srx_fast_msg_config_t,      SENT_VAR) sSentFastMsg; /*!< Fast messages configuration structure */
    VAR(srx_slow_msg_config_t,      SENT_VAR) sSentSlowMsg; /*!< Slow messages configuration structure */
    VAR(Sent_NotificationFunc,      SENT_VAR) pfNotification;
}Sent_ChannelCfgtype;

typedef struct 
{
    VAR(uint8,                 SENT_VAR) u8MaxHwChannels;
    VAR(uint32,                SENT_VAR) u32SentClkFreq;
    VAR(uint8,                 SENT_VAR) u8TimestampPrescaler;
#if (SENT_ENABLE_MULTICORE == STD_ON)
    P2CONST(Sent_CoreMapItemType, SENT_CONST, SENT_APPL_CONST) pCoreMap;
#endif
    P2CONST(Sent_ChannelCfgtype,  SENT_CONST, SENT_APPL_CONST) pChanCfgPtr;
}Sent_ConfigType;

typedef struct
{
    VAR(uint16, SENT_VAR) Data;
    VAR(uint8,  SENT_VAR) MsgId;
    VAR(uint8,  SENT_VAR) CRC;
    VAR(uint8,  SENT_VAR) Configuration;
}Sent_RxSerialDataType;

typedef struct
{
    VAR(uint32, SENT_VAR) RxTimeStamp;
    VAR(uint32, SENT_VAR) ChanStat;
    VAR(boolean,SENT_VAR) IntSata;
    VAR(uint8,  SENT_VAR) RxCRC;
}Sent_ChanStatusType;

extern P2CONST(Sent_ConfigType, SENT_CONST, SENT_APPL_CONST) pSent_ConfigPtr;
extern CONST(Sent_ConfigType, SENT_CONST)SentChannelConfigSet;

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) Sent_Init(P2CONST(Sent_ConfigType, AUTOMATIC, SENT_APPL_CONST) ConfigPtr);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) Sent_DeInit(void);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) Sent_SetChannel
(
    VAR(Sent_ChannelType, AUTOMATIC) ChannelId,
    VAR(Sent_StatType, AUTOMATIC) Operation
);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(uint32, SENT_CODE) Sent_ReadData(VAR(Sent_ChannelType, AUTOMATIC) ChannelId);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) Sent_ReadSerialData
(
    VAR(Sent_ChannelType, AUTOMATIC) ChannelId,
    P2VAR(Sent_RxSerialDataType, AUTOMATIC, SENT_APPL_DATA)DataPtr
);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) Sent_ReadChannelStatus
(
    VAR(Sent_ChannelType, AUTOMATIC) ChannelId,
    P2VAR(Sent_ChanStatusType, AUTOMATIC, SENT_APPL_DATA)StatPtr
);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) Sent_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, SENT_APPL_DATA) VersionInfoPtr
);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) Sent_ProcessCommonIrq
(
    VAR(Sent_ChannelType, AUTOMATIC) Channel,
    VAR(srx_callback_type_t, AUTOMATIC) type
);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(uint8, SENT_CODE)Sent_GetInstance
(
    VAR(uint8, AUTOMATIC) module,
    VAR(uint8, AUTOMATIC) Channel
);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#if SENT_DMA_EN
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(boolean, SENT_CODE) SENT_EDmaConfig ( VAR(uint8_t, AUTOMATIC) instance, \
    CONST(boolean , AUTOMATIC) fDmaEn,CONST(boolean , AUTOMATIC) sDmaEn, \
    P2CONST(srx_driver_user_config_t, SENT_CONST,SENT_APPL_CONST) DmaconfigPtr);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"
#endif /* SENT_DMA_EN */

#endif /* RESOURCE_SUPPORT_SENT */

#endif /* SENT_H */
