/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC
*   Peripheral           : Gpt
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : -
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/

/**
*   @file    Gpt_AutoSAR_Wrapper.h
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Gpt MCAL driver.
*
*   @addtogroup Gpt
*   @{
*/
/* PRQA S 3432,1753 EOF */

#ifndef GPT_AUTOSAR_WRAPPER_H
#define GPT_AUTOSAR_WRAPPER_H

#ifdef __cplusplus
extern "C"{
#endif

/*==============================================INCLUDE FILES=======================================*/

#include "Std_Types.h"
#include "Gpt.h"
#if (defined(RESOURCE_SUPPORT_GTM104) || defined(RESOURCE_SUPPORT_GTM410))
#include "Gpt_Gtm_LLDriver.h"
#endif

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define GPT_VENDOR_ID_H                     176
#define GPT_MODULE_ID_H                     100
#define GPT_AR_RELEASE_MAJOR_VERSION        4
#define GPT_AR_RELEASE_MINOR_VERSION        4
#define GPT_AR_PATCH_VER_H                  0
#define GPT_SW_MAJOR_VER_H                  3
#define GPT_SW_MINOR_VER_H                  0
#define GPT_SW_PATCH_VER_H                  0

/*============================================FILE VERSION CHECKS===================================*/

#if (GPT_VENDOR_ID_H != GPT_VENDOR_ID)
#error "NON-MATCHED DATA : GPT_CFG_VENDOR_ID"
#endif

#if (GPT_AR_RELEASE_MAJOR_VERSION != GPT_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_MAJOR_VER"
#endif
#if (GPT_AR_RELEASE_MINOR_VERSION != GPT_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_MINOR_VER"
#endif
#if (GPT_AR_PATCH_VER_H != GPT_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_PATCH_VER"
#endif

#if (GPT_SW_MAJOR_VER_H != GPT_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_MAJOR_VER"
#endif
#if (GPT_SW_MINOR_VER_H != GPT_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_MINOR_VER"
#endif
#if (GPT_SW_PATCH_VER_H != GPT_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_PATCH_VER"
#endif

/*=================================================Constants========================================*/

/*============================================DEFINES AND MACROS====================================*/

/*===================================================ENUMS==========================================*/

typedef enum
{
    GPT_STATUS_UNINITIALIZED = 0,       /* GPT channel status - uninitialized */
    GPT_STATUS_INITIALIZED = 1,         /* GPT channel status - initialized */
    GPT_STATUS_STOPPED = 2,             /* GPT channel status - stopped */
    GPT_STATUS_EXPIRED = 3,             /* GPT channel status - expired */
    GPT_STATUS_RUNNING = 4              /* GPT channel status - running */
} Gpt_ChannelStatus;

/*=======================================STRUCTURES AND OTHER TYPEDEFS==============================*/
typedef struct
{
    VAR(boolean, GPT_VAR) bChannelRollover;    /* GPT channel rollover information*/
    VAR(Gpt_ValueType, GPT_VAR) uTargetTime;   /* GPT channel target value*/
} Gpt_Wrapper_HwChannelInfo;

typedef struct
{

    VAR(Gpt_ChannelStatus,GPT_VAR) eChannelStatus; /* GPT channel runtime status */
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    VAR(boolean,GPT_VAR) bNotificationEnabled;     /* GPT channel has notification enabled at runtime */
#endif

#if((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
    VAR(boolean,GPT_VAR) bWakeupEnabled;     /* GPT channel has wakeup enabled at runtime*/
    VAR(boolean,GPT_VAR) bWakeupGenerated;   /* GPT channel executed wakeup */
#endif
    VAR(Gpt_ValueType,GPT_VAR) aStopTimeVal;

#if (GPT_ENABLE_MULTICORE == STD_ON)
    VAR(uint8, GPT_VAR) pGpt_CoreId[GPT_HW_CHANNEL_NUM];
#endif

} Gpt_Wrapper_ChannelInfo;

/*==============================================GLOBAL FUNCTIONS====================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Gpt_Wrapper_ChannelInfo*, GPT_CODE) Gpt_AutoSar_Wrapper_GetChannelInfo \
( 																			\
    VAR(Gpt_ChannelType, AUTOMATIC) u8Gpt_Channel 							\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_AutoSar_Wrapper_Init 								\
( 																			\
    P2CONST(Gpt_HwChannelConfig, AUTOMATIC, GPT_APPL_CONST) psGpt_HwConfig  \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_AutoSar_Wrapper_DeInit 							\
( 																			\
    P2CONST(Gpt_HwChannelConfig, AUTOMATIC, GPT_APPL_CONST) psGpt_HwConfig  \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Gpt_ValueType, GPT_CODE) Gpt_AutoSar_Wrapper_GetTimeElapsed 						\
( 																						\
    P2CONST(Gpt_HwChannelConfig, AUTOMATIC, GPT_APPL_CONST) psGpt_HwConfig, 			\
    P2VAR(Gpt_Wrapper_HwChannelInfo, AUTOMATIC,GPT_APPL_DATA) psGpt_HwChannelInfoPtr 	\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint32, GPT_CODE) Gpt_AutoSar_Wrapper_GetTimeRemaining 				\
( 																			\
    P2CONST(Gpt_HwChannelConfig, AUTOMATIC, GPT_APPL_CONST) psGpt_HwConfig 	\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC (void, GPT_CODE) Gpt_AutoSar_Wrapper_StartTimer 						\
( 																			\
    P2CONST(Gpt_HwChannelConfig, AUTOMATIC,GPT_APPL_CONST) psGpt_HwConfig,  \
    VAR(Gpt_ValueType, AUTOMATIC) u32Gpt_Value 								\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC (void, GPT_CODE) Gpt_AutoSar_Wrapper_StopTimer 						\
( 																			\
    P2CONST(Gpt_HwChannelConfig, AUTOMATIC,GPT_APPL_CONST) psGpt_HwConfig 	\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC (void, GPT_CODE) Gpt_AutoSar_Wrapper_EnableInterrupt 					\
( 																			\
    P2CONST(Gpt_HwChannelConfig, AUTOMATIC,GPT_APPL_CONST) psGpt_HwConfig 	\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC (void, GPT_CODE) Gpt_AutoSar_Wrapper_DisableInterrupt 					\
( 																			\
    P2CONST(Gpt_HwChannelConfig, AUTOMATIC,GPT_APPL_CONST) psGpt_HwConfig 	\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC (void, GPT_CODE) Gpt_AutoSar_Wrapper_GetPredefTimerValue 						\
( 																					\
    P2CONST(Gpt_HwPredefChannelConfig, AUTOMATIC,GPT_APPL_CONST) psGpt_HwConfig, 	\
    VAR(Gpt_PredefTimerType, AUTOMATIC) eGpt_PredefTimer, 							\
    P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pu32Gpt_TimeValuePtr 					\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC (void, GPT_CODE) Gpt_Wrapper_StartPredefTimer
(
    P2CONST(Gpt_ConfigType, AUTOMATIC,GPT_APPL_CONST) pGptConfig
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC (void, GPT_CODE) Gpt_Wrapper_StopPredefTimer
(
    P2CONST(Gpt_ConfigType, AUTOMATIC,GPT_APPL_CONST) pGptConfig
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif
#if (defined(RESOURCE_SUPPORT_GTM104) || defined(RESOURCE_SUPPORT_GTM410))
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_AutoSar_Wrapper_Gtm_Init   \
(                                                   \
    P2CONST( Gpt_GtmCmuConfigType, AUTOMATIC, GPT_APPL_CONST) ConfigPtr \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_AutoSar_Wrapper_Gtm_Denit(void);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#ifdef __cplusplus
}
#endif

#endif// GPT_AUTOSAR_WRAPPER_H
