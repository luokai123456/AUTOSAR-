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
*   @file    Gpt.h
*   @version 3.0.0
*
*    AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Gpt MCAL driver.
*
*   @addtogroup Gpt
*   @{
*/
/* PRQA S 3432 EOF */

#ifndef GPT_H
#define GPT_H

#ifdef __cplusplus
extern "C"{
#endif

/*==============================================INCLUDE FILES=======================================*/
#include "Gpt_Cfg.h"
#include "EcuM_Types.h" //DQ add
#include "Std_Types.h"
#include "Gpt_Stm_LLDriver.h"
#include "Gpt_Pit_LLDriver.h"
#include "Gpt_Rtc_LLDriver.h"
#if (defined(RESOURCE_SUPPORT_GTM104) || defined(RESOURCE_SUPPORT_GTM410))
#include "Gpt_Gtm_LLDriver.h"
#endif
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
#include "EcuM.h"
#endif
#endif


/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define GPT_VENDOR_ID_H                     176
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

#define GPT_MODULE_ID                       100

#define GPT_CORE_NUM                        MCAL_CORE_NUM

#if (GPT_ENABLE_MULTICORE == STD_ON)
    #define Gpt_GetCoreID()     (GetCoreID())
#else
    #define Gpt_GetCoreID()     (GPT_DEFAULT_COREID)
#endif

#define GPT_MAX_PARTITION       GPT_CORE_NUM


#define GPT_CHN_USED                ((uint8)255U)

#define GPT_INSTANCE_ID             ((uint8)0U)

/*
    [SWS_Gpt_00345] API service called without module initialization
*/
#define GPT_E_UNINIT                ((uint8)0x0AU)
/*
    [SWS_Gpt_00347] API service for initialization called when already initialized
*/
#define GPT_E_ALREADY_INITIALIZED   ((uint8)0x0DU)
/*
    [SWS_Gpt_00404] API error return code: Init function failed
*/
#define GPT_E_INIT_FAILED           ((uint8)0x0EU)
/*
    [SWS_Gpt_00348] API parameter checking: invalid Channel
*/
#define GPT_E_PARAM_CHANNEL         ((uint8)0x14U)
/*
    [SWS_Gpt_00349] API parameter checking: invalid value
*/
#define GPT_E_PARAM_VALUE           ((uint8)0x15U)
/*
    [SWS_Gpt_00350] API parameter checking: invalid pointer
*/
#define GPT_E_PARAM_POINTER         ((uint8)0x16U)
/*
    [SWS_Gpt_00388] API parameter checking: invalid Predef Timer
*/
#define GPT_E_PARAM_PREDEF_TIMER    ((uint8)0x17U)
/*
    [SWS_Gpt_00351] API parameter checking: invalid mode
*/
#define GPT_E_PARAM_MODE            ((uint8)0x1FU)
/*
    [SWS_Gpt_00346] API service called when timer Channel is still busy (running)
*/
#define GPT_E_BUSY                  ((uint8)0x0BU)
/*
    [SWS_Gpt_00387] API service called when driver is in wrong mode
*/
#define GPT_E_MODE                  ((uint8)0x0CU)

#define GPT_E_PARAM_CLOCK_MODE      ((uint8)0x18U)

#define GPT_E_PARAM_CONFIG          ((uint8)0x19U)

/* API DET SERVICE IDs */
#define GPT_SID_GETVERSIONINFO       ((uint8)0x00U)

#define GPT_SID_INIT                 ((uint8)0x01U)

#define GPT_SID_DEINIT               ((uint8)0x02U)

#define GPT_SID_TIMEELAPSED          ((uint8)0x03U)

#define GPT_SID_TIMEREMAINING        ((uint8)0x04U)

#define GPT_SID_STARTTIMER           ((uint8)0x05U)

#define GPT_SID_STOPTIMER            ((uint8)0x06U)

#define GPT_SID_ENABLENOTIFICATION   ((uint8)0x07U)

#define GPT_SID_DISABLENOTIFICATION  ((uint8)0x08U)

#define GPT_SID_SETMODE              ((uint8)0x09U)

#define GPT_SID_DISABLEWAKEUP        ((uint8)0x0AU)

#define GPT_SID_ENABLEWAKEUP         ((uint8)0x0BU)

#define GPT_SID_CHECKWAKEUP          ((uint8)0x0CU)

#define GPT_SID_GPT_GTM_INIT         ((uint8)0x0EU)
#define GPT_SID_GPT_GTM_DEINIT       ((uint8)0x0FU)

#define GPT_SID_GETSTATUS            ((uint8)0x10U)

#define GPT_SID_GET_PREDEF_TIMERVALUE           ((uint8)0x0DU)

#define GTM_CH_MODE_CONTINUOUS                  (0x00UL)
#define GTM_CH_MODE_ONESHOT                     (0x80UL)

/*
    [SWS_Gpt_00358]
*/
typedef uint8 Gpt_ChannelType;

/*
    [SWS_Gpt_00359]
*/
typedef uint32 Gpt_ValueType;

typedef P2FUNC(void, GPT_APPL_CODE, Gpt_NotificationFunc)(void);

/*===================================================ENUMS==========================================*/
#if (GPT_SET_CLOCK_MODE == STD_ON)
typedef enum
{
    GPT_CLOCKMODE_NORMAL    = 0x0U,
    GPT_CLOCKMODE_ALTERNATE = 0x1U
}Gpt_ClockModeType;
#endif /* GPT_SET_CLOCK_MODE */

/*
    [SWS_Gpt_00360]
*/
typedef enum
{
    GPT_MODE_NORMAL = 0U,          /* GPT Normal operation mode of the GPT */
    GPT_MODE_SLEEP  = 1U           /* Operation for reduced power operation mode. In sleep mode only wakeup capable channels are available */
} Gpt_ModeType;

typedef enum
{
    GPT_CH_MODE_CONTINUOUS = 0U,   /*  After reaching the target time, the
                                         timer continues running with the value "zero" again. */
    GPT_CH_MODE_ONESHOT    = 1U    /*  After reaching the target time, the
                                         timer stops automatically (timer expired). */
} Gpt_ChannelMode;

/*
    [SWS_Gpt_00389]
    [SWS_Gpt_00383]
*/
typedef enum
{
    GPT_PREDEF_TIMER_1US_16BIT = 0x0U,  /* GPT Predef Timer with tick duration 1µs and range 16bit */
    GPT_PREDEF_TIMER_1US_24BIT = 0x1U,         /* GPT Predef Timer with tick duration 1µs and range 24bit */
    GPT_PREDEF_TIMER_1US_32BIT = 0x2U,         /* GPT Predef Timer with tick duration 1µs and range 32bit */
    GPT_PREDEF_TIMER_100US_32BIT = 0x3U        /* GPT Predef Timer with tick duration 100µs and range 32bit */
} Gpt_PredefTimerType;

typedef enum
{
    CLK_SOURCE_CMU_FXCLK0 = 0x0U,
    CLK_SOURCE_CMU_FXCLK1 = 0x1U,
    CLK_SOURCE_CMU_FXCLK2 = 0x2U,
    CLK_SOURCE_CMU_FXCLK3 = 0x3U,
    CLK_SOURCE_CMU_FXCLK4 = 0x4U,
} Gpt_GTM_TOM_ClockSource;

typedef enum
{
    GPT_MODULE_GTM = 0x0U,
    GPT_MODULE_PIT = 0x1U,
    GPT_MODULE_STM = 0x2U,
    GPT_MODULE_RTC = 0x3U,
    GPT_MODULE_API = 0x4U,
} Gpt_Module;

typedef enum
{
    GPT_UNINIT = 0x0U,
    GPT_READY = 0x1U,
} Gpt_StatusType;


/*=======================================STRUCTURES AND OTHER TYPEDEFS==============================*/
#if (GPT_ENABLE_MULTICORE == STD_ON)
typedef struct{
    VAR(uint8, GPT_VAR) u8HwChannel;
    VAR(uint8, GPT_VAR) u8CoreId;
}Gpt_CoreMapItemType;
#endif
typedef struct
{
    VAR(uint8, GPT_VAR) u8HwChannel;                   /* GPT hw Channel ID */
    VAR(Gpt_Module, GPT_VAR) eHwModule;               /* GPT hw module used */
    VAR(boolean, GPT_VAR) bFreezeEnable;               /* Channel freeze enable */
    VAR(uint32, GPT_VAR) u32GtmChannelRegCtrl1;        /* GTM Channel count mode and counter source configured by CTRL1 */
#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    VAR(boolean, GPT_VAR) bGtmSupportEnableOutput;     /* GTM Channel out mode configured by OUTEN_STAT register */
#endif /* GPT_GTM_OUTPUT_ENABLE_MODE */
    VAR(uint8, GPT_VAR) u8StmPrescaler;                /* Channel prescaler value*/
    VAR(uint32, GPT_VAR) u32ClkFreq;
#ifdef RESOURCE_SUPPORT_RTC_API
    VAR(rtcapi_clk_t, GPT_VAR) eRtcClk;
    VAR(rtcapi_div_t, GPT_VAR) eRtcDiv;
#endif
    #if (GPT_SET_CLOCK_MODE == STD_ON)
    VAR(uint8, GPT_VAR) u8Prescaler_Alternate;    /**<@brief STM channel prescaler value*/
    VAR(uint32, GPT_VAR) u32GtmChannelRegCtrl1_Alternate;  /**<@brief Gtm channel prescaler Alternate value*/
    #endif /* GPT_DUAL_CLOCK_MODE */
} Gpt_HwChannelConfig;

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)

/* Low level configuration for Channel specific parameters*/
typedef struct
{
    VAR(uint8, GPT_VAR) u8HwChannel;                    /* GPT hw Channel ID */
    VAR(Gpt_Module, GPT_VAR) eHwModule;                     /* GPT hw module used */
    VAR(boolean, GPT_VAR) bFreezeEnable;                /* Channel freeze enable */
    VAR(uint8, GPT_VAR) u8StmPrescaler;                     /* Channel prescaler value*/
} Gpt_HwPredefChannelConfig;
#endif

/* Gpt Channel configuration type.*/
typedef struct
{
    VAR(uint8, GPT_VAR) u8Instance;
    /* GPT ch WakeUp enable */
    VAR(boolean, GPT_VAR) bEnableWakeup;
    /*
        [SWS_Gpt_00086]
    */
    /* Pointer to external callback */
    VAR(Gpt_NotificationFunc, GPT_VAR) pfNotification;
    /* EcuM wake up source Id */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
    VAR(EcuM_WakeupSourceType, GPT_VAR) uWakeupSource;
#endif
    /* Channel max tick value */
    VAR(Gpt_ValueType, GPT_VAR) uChannelTickValueMax;
    /* GPT Channel mode */
    VAR(Gpt_ChannelMode, GPT_VAR) eChannelMode;
    /* Hardware dependent Channel configuration*/
    CONST(Gpt_HwChannelConfig,GPT_VAR) *pHwChannelConfig;
} Gpt_ChannelConfig;

/*
    [SWS_Gpt_00357]
*/
typedef struct
{
    /* Number of GPT channels (configured in tresos plugin builder)*/
    CONST(Gpt_ChannelType, GPT_CONST) uChannelCount;
    /* Pointer to the GPT Channel configuration */
    CONST(Gpt_ChannelConfig, GPT_CONST) (*pChannelConfig)[];
#if (GPT_ENABLE_MULTICORE == STD_ON)
    P2CONST(Gpt_CoreMapItemType, GPT_CONST, GPT_APPL_CONST) pGpt_CoreMap;
#endif
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
    /* Pointer to the GPT Channel predef timer configuration */
    CONSTP2CONST(Gpt_HwPredefChannelConfig, GPT_CONST, GPT_APPL_CONST) (*pChannelPredefConfigType);
#endif
    /* Hardware to logic channel map table*/
    CONST(Gpt_ChannelType, GPT_CONST) Gpt_aHw2LogicChannelMap[GPT_CHANNEL_IDX_NUM];
} Gpt_ConfigType;

#if (defined(RESOURCE_SUPPORT_GTM104) || defined(RESOURCE_SUPPORT_GTM410))
extern CONST(Gpt_GtmCmuConfigType, GPT_CONST) Gpt_Gtm_Cmu_PBCfg;
#endif
#define GptChannelConfigSet Gpt_Config
extern CONST(Gpt_ConfigType, GPT_CONST) Gpt_Config;

/*==============================================GLOBAL FUNCTIONS====================================*/
#if (GPT_VERSION_INFO_API == STD_ON)
/*****************************************************************************
**  Service Name     : Gpt_GetVersionInfo
**                                                                            
**  Description      : This function returns the version information of
**                     this module.
**                                                                            
**  Service ID       : 0x00
**                                                                            
**  Sync/Async       : Synchronous
**                                                                            
**  Reentrancy       : Reentrant
**                                                                            
**  Parameters (in)  : None
**                                                                            
**  Parameters (out) : versioninfo: Pointer to where to store the version
**                     information of this module.
**                                                                            
**  Return value     : None
**                                                                            
******************************************************************************/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_GetVersionInfo 								\
( 																		\
    P2VAR(Std_VersionInfoType, AUTOMATIC, GPT_APPL_DATA) VersionInfoPtr \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif /* GPT_VERSION_INFO_API */

/*****************************************************************************
**  Service Name     : Gpt_Init
**                                                                            
**  Description      : Initializes the GPT driver
**                                                                            
**  Service ID       : 0x01
**                                                                            
**  Sync/Async       : Synchronous
**                                                                            
**  Reentrancy       : Reentrant
**                                                                            
**  Parameters (in)  : ConfigPtr:Pointer to a selected configuration structure
**                                                                            
**  Parameters (out) : None
**                                                                            
**  Return value     : None
**                                                                            
******************************************************************************/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Init(P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_CONST) ConfigPtr);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#if (GPT_DEINIT_API == STD_ON)
/*****************************************************************************
**  Service Name     : Gpt_DeInit
**                                                                            
**  Description      : Deinitializes the GPT driver
**                                                                            
**  Service ID       : 0x02
**                                                                            
**  Sync/Async       : Synchronous
**                                                                            
**  Reentrancy       : Reentrant
**                                                                            
**  Parameters (in)  : None
**                                                                            
**  Parameters (out) : None
**                                                                            
**  Return value     : None
**                                                                            
******************************************************************************/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_DeInit(void);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif /* GPT_DEINIT_API */

#if (GPT_TIME_ELAPSED_API == STD_ON)
/*****************************************************************************
**  Service Name     : Gpt_GetTimeElapsed
**                                                                            
**  Description      : Returns the time already elapsed.
**                                                                            
**  Service ID       : 0x03
**                                                                            
**  Sync/Async       : Synchronous
**                                                                            
**  Reentrancy       : Reentrant
**                                                                            
**  Parameters (in)  : Numeric identifier of the GPT Channel
**                                                                            
**  Parameters (out) : None
**                                                                            
**  Return value     : Elapsed timer value (in number of ticks)
**                                                                            
******************************************************************************/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeElapsed(VAR(Gpt_ChannelType, AUTOMATIC) Channel);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif /* GPT_TIME_ELAPSED_API */

#if (GPT_TIME_REMAINING_API == STD_ON)
/*****************************************************************************
**  Service Name     : Gpt_GetTimeRemaining
**                                                                            
**  Description      : Returns the time remaining until the target time is reached
**                                                                            
**  Service ID       : 0x04
**                                                                            
**  Sync/Async       : Synchronous
**                                                                            
**  Reentrancy       : Reentrant
**                                                                            
**  Parameters (in)  : Numeric identifier of the GPT Channel
**                                                                            
**  Parameters (out) : None
**                                                                            
**  Return value     : Remaining timer value (in number of ticks)
**                                                                            
******************************************************************************/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeRemaining(VAR(Gpt_ChannelType, AUTOMATIC) Channel);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif /* GPT_TIME_REMAINING_API */
/*****************************************************************************
**  Service Name     : Gpt_StartTimer
**                                                                            
**  Description      : Starts a timer Channel.
**                                                                            
**  Service ID       : 0x05
**                                                                            
**  Sync/Async       : Synchronous
**                                                                            
**  Reentrancy       : Reentrant
**                                                                            
**  Parameters (in)  : Channel:Numeric identifier of the GPT Channel
**  Parameters (in)  : value: Target time in number of ticks.
**                                                                            
**  Parameters (out) : None
**                                                                            
**  Return value     : Remaining timer value (in number of ticks)
**                                                                            
******************************************************************************/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_StartTimer(
    VAR(Gpt_ChannelType,    AUTOMATIC) Channel,
    VAR(Gpt_ValueType,      AUTOMATIC) Value
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
/*****************************************************************************
**  Service Name     : Gpt_StopTimer
**                                                                            
**  Description      : Stops a timer Channel
**                                                                            
**  Service ID       : 0x06
**                                                                            
**  Sync/Async       : Synchronous
**                                                                            
**  Reentrancy       : Reentrant
**                                                                            
**  Parameters (in)  : Channel:Numeric identifier of the GPT Channel
**                                                                            
**  Parameters (out) : None
**                                                                            
**  Return value     : None
**                                                                            
******************************************************************************/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_StopTimer(VAR(Gpt_ChannelType, AUTOMATIC) Channel);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/*****************************************************************************
**  Service Name     : Gpt_EnableNotification
**                                                                            
**  Description      : Enables the interrupt notification for a Channel
**                                                                            
**  Service ID       : 0x07
**                                                                            
**  Sync/Async       : Synchronous
**                                                                            
**  Reentrancy       : Reentrant
**                                                                            
**  Parameters (in)  : Channel:Numeric identifier of the GPT Channel
**                                                                            
**  Parameters (out) : None
**                                                                            
**  Return value     : None
**                                                                            
******************************************************************************/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_EnableNotification(VAR(Gpt_ChannelType, AUTOMATIC) Channel);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(boolean, GPT_CODE) Gpt_GetNotificationStatus(VAR(Gpt_ChannelType, AUTOMATIC) Channel);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

/*****************************************************************************
**  Service Name     : Gpt_DisableNotification
**                                                                            
**  Description      : Disables the interrupt notification for a Channel
**                                                                            
**  Service ID       : 0x08
**                                                                            
**  Sync/Async       : Synchronous
**                                                                            
**  Reentrancy       : Reentrant
**                                                                            
**  Parameters (in)  : Channel:Numeric identifier of the GPT Channel
**                                                                            
**  Parameters (out) : None
**                                                                            
**  Return value     : None
**                                                                            
******************************************************************************/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_DisableNotification(VAR(Gpt_ChannelType, AUTOMATIC) Channel);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif /* GPT_ENABLE_DISABLE_NOTIFICATION_API */

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/*****************************************************************************
**  Service Name     : Gpt_SetMode
**                                                                            
**  Description      : Sets the operation mode of the GPT.
**                                                                            
**  Service ID       : 0x09
**                                                                            
**  Sync/Async       : Synchronous
**                                                                            
**  Reentrancy       : Reentrant
**                                                                            
**  Parameters (in)  : mode:GPT_MODE_NORMAL: Normal operation mode of the GPT driver.
**                          GPT_MODE_SLEEP: Sleep mode of the GPT driver (wakeup capable).
**                                                                            
**  Parameters (out) : None
**                                                                            
**  Return value     : None
**                                                                            
******************************************************************************/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_SetMode(VAR(Gpt_ModeType, AUTOMATIC) Mode);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
/*****************************************************************************
**  Service Name     : Gpt_GetMode
**                                                                            
**  Description      : Get the operation mode of the GPT.
**                                                                            
**  Service ID       : None
**                                                                            
**  Sync/Async       : Synchronous
**                                                                            
**  Reentrancy       : Reentrant
**                                                                            
**  Parameters (in)  : None
**                                                                            
**  Parameters (out) : None
**                                                                            
**  Return value     : GPT_MODE_NORMAL: Normal operation mode of the GPT driver.
**                     GPT_MODE_SLEEP: Sleep mode of the GPT driver (wakeup capable).
**                                                                            
******************************************************************************/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Gpt_ModeType, GPT_CODE) Gpt_GetMode(void);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif /* GPT_WAKEUP_FUNCTIONALITY_API */

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/*****************************************************************************
**  Service Name     : Gpt_DisableWakeup
**                                                                            
**  Description      : Disables the wakeup interrupt of a Channel (relevant in sleep mode).
**                                                                            
**  Service ID       : 0x0a
**                                                                            
**  Sync/Async       : Synchronous
**                                                                            
**  Reentrancy       : Reentrant
**                                                                            
**  Parameters (in)  : Channel:Numeric identifier of the GPT Channel.
**                                                                            
**  Parameters (out) : None
**                                                                            
**  Return value     : None
**                                                                            
******************************************************************************/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_DisableWakeup(VAR(Gpt_ChannelType, AUTOMATIC) Channel);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
/*****************************************************************************
**  Service Name     : Gpt_EnableWakeup
**                                                                            
**  Description      : Enables the wakeup interrupt of a Channel (relevant in sleep mode).
**                                                                            
**  Service ID       : 0x0b
**                                                                            
**  Sync/Async       : Synchronous
**                                                                            
**  Reentrancy       : Reentrant
**                                                                            
**  Parameters (in)  : Channel:Numeric identifier of the GPT Channel.
**                                                                            
**  Parameters (out) : None
**                                                                            
**  Return value     : None
**                                                                            
******************************************************************************/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_EnableWakeup(VAR(Gpt_ChannelType, AUTOMATIC) Channel);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
/*****************************************************************************
**  Service Name     : Gpt_CheckWakeup
**                                                                            
**  Description      : Checks if a wakeup capable GPT Channel is the source for a wakeup event and
                       calls the ECU state manager service EcuM_SetWakeupEvent in case of a valid
                       GPT Channel wakeup event.
**                                                                            
**  Service ID       : 0x0c
**                                                                            
**  Sync/Async       : Synchronous
**                                                                            
**  Reentrancy       : Reentrant
**                                                                            
**  Parameters (in)  : wakeupSource: Information on wakeup source to be checked. The associated
                                GPT Channel can be determined from configuration data
**                                                                            
**  Parameters (out) : None
**                                                                            
**  Return value     : None
**                                                                            
******************************************************************************/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_CheckWakeup(VAR(EcuM_WakeupSourceType, AUTOMATIC) u32WakeupSource);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif /* GPT_WAKEUP_FUNCTIONALITY_API */

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/*****************************************************************************
**  Service Name     : Gpt_GetPredefTimerValue
**                                                                            
**  Description      : Delivers the current value of the desired GPT Predef Timer.
**                                                                            
**  Service ID       : 0x0d
**                                                                            
**  Sync/Async       : Synchronous
**                                                                            
**  Reentrancy       : Reentrant
**                                                                            
**  Parameters (in)  : PredefTimer: GPT Predef Timer
**  Parameters (in)  : None
**                                                                            
**  Parameters (out) : TimeValuePtr: Pointer to time value destination data in RAM
**                                                                            
**  Return value     : E_OK: no error has been detected
                       E_NOT_OK: aborted due to errors
**                                                                            
******************************************************************************/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) Gpt_GetPredefTimerValue
(
    VAR(Gpt_PredefTimerType, AUTOMATIC) ePredefTimer,
    P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pu32TimeValue
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif /* GPT_PREDEFTIMER_FUNCTIONALITY_API */

/*****************************************************************************
**  Service Name     : Gpt_GetChannelStatus
**                                                                            
**  Description      : get GPT Channel status.
**                                                                            
**  Service ID       : None
**                                                                            
**  Sync/Async       : Synchronous
**                                                                            
**  Reentrancy       : Reentrant
**                                                                            
**  Parameters (in)  : Channel:Numeric identifier of the GPT Channel
**  Parameters (in)  : None
**                                                                            
**  Parameters (out) : None
**                                                                            
**  Return value     : Channel status, ref@Gpt_ChannelStatus
**                                                                            
******************************************************************************/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint8, GPT_CODE) Gpt_GetChannelStatus(VAR(Gpt_ChannelType, AUTOMATIC) Channel);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
/*****************************************************************************
**  Service Name     : Gpt_ProcessCommonIrq
**                                                                            
**  Description      : Gpt common handler to implements generic part of the ISR.
**                                                                            
**  Service ID       : None
**                                                                            
**  Sync/Async       : Synchronous
**                                                                            
**  Reentrancy       : Reentrant
**                                                                            
**  Parameters (in)  : Channel:Numeric identifier of the GPT Channel
**  Parameters (in)  : None
**                                                                            
**  Parameters (out) : None
**                                                                            
**  Return value     : None
**                                                                            
******************************************************************************/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_ProcessCommonIrq(VAR(Gpt_ChannelType, AUTOMATIC) Channel);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint8, GPT_CODE) Gpt_GetInstance
(
    VAR(Gpt_Module, AUTOMATIC) module,
    VAR(uint8, AUTOMATIC) Channel
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(boolean, GPT_CODE) Gpt_GetWakeupStatus(VAR(Gpt_ChannelType, AUTOMATIC) Channel);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#if (GPT_ENABLE_GTMCMU == STD_ON)

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) GPT_Gtm_Init(P2CONST(Gpt_GtmCmuConfigType, AUTOMATIC, GPT_APPL_CONST) ConfigPtr);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) GPT_Gtm_Deinit(void);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 


#endif

#ifdef __cplusplus
}
#endif

#endif /* GPT_H */

