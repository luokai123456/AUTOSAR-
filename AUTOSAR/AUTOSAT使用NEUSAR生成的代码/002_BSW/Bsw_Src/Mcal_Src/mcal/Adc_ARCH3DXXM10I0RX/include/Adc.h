/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : Adc
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
*   @file    Adc.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Adc MCAL driver.
*
*   @addtogroup Adc
*   @{
*/

/* PRQA S 1535,1752 EOF */

#ifndef ADC_H
#define ADC_H

#include "Adc_Cfg.h"
#include "Adc_LLDriver.h"
#include "eDma.h"
#include "Mcal.h"

#define ADC_H_VENDOR_ID                     176
#define ADC_AR_RELEASE_MAJOR_VERSION        4
#define ADC_AR_RELEASE_MINOR_VERSION        4
#define ADC_H_AR_REL_REV_VER                0
#define ADC_H_SW_MAJOR_VER                  3
#define ADC_H_SW_MINOR_VER                  0
#define ADC_H_SW_PATCH_VER                  0

#if (ADC_VENDOR_ID               != ADC_H_VENDOR_ID)
    #error " NON-MATCHED DATA : ADC_H_VENDOR_ID "
#endif
#if (ADC_AR_REL_MAJOR_VER    != ADC_AR_RELEASE_MAJOR_VERSION)
    #error " NON-MATCHED DATA : ADC_AR_RELEASE_MAJOR_VERSION "
#endif
#if (ADC_AR_REL_MINOR_VER    != ADC_AR_RELEASE_MINOR_VERSION)
    #error " NON-MATCHED DATA : ADC_AR_RELEASE_MINOR_VERSION "
#endif
#if (ADC_AR_REL_REV_VER != ADC_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ADC_H_AR_REL_REV_VER "
#endif
#if (ADC_SW_MAJOR_VER        != ADC_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ADC_H_SW_MAJOR_VER "
#endif
#if (ADC_SW_MINOR_VER        != ADC_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ADC_H_SW_MINOR_VER "
#endif
#if (ADC_SW_PATCH_VER        != ADC_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ADC_H_SW_PATCH_VER "
#endif

#if (ADC_ENABLE_MULTICORE == STD_ON)
    #define Adc_GetCoreID()     (1U << GetCoreID())
#else
    #define Adc_GetCoreID()     (1U << ADC_DEFAULT_COREID)
#endif

#define ADC_CORE_NUM                    MCAL_CORE_NUM

/* API service ID for Adc_Init function. */
#define ADC_INIT_ID                         0x00U
/* API service ID for Adc_DeInit function. */
#define ADC_DEINIT_ID                       0x01U
/* API service ID for Adc_StartGroupConversion function. */
#define ADC_STARTGROUPCONVERSION_ID         0x02U
/* API service ID for Adc_StopGroupConversion function. */
#define ADC_STOPGROUPCONVERSION_ID          0x03U
/* API service ID for Adc_ReadGroup function. */
#define ADC_READGROUP_ID                    0x04U
/* API service ID for Adc_EnableHardwareTrigger function. */
#define ADC_ENABLEHARDWARETRIGGER_ID        0x05U
/* API service ID for Adc_DisableHardwareTrigger function. */
#define ADC_DISABLEHARDWARETRIGGER_ID       0x06U
/* API service ID for Adc_EnableGroupNotification function. */
#define ADC_ENABLEGROUPNOTIFICATION_ID      0x07U
/* API service ID for Adc_DisableGroupNotification function. */
#define ADC_DISABLEGROUPNOTIFICATION_ID     0x08U
/* API service ID for Adc_GetGroupStatus function.*/
#define ADC_GETGROUPSTATUS_ID               0x09U
/* API service ID for Adc_GetVersionInfo function. */
#define ADC_GETVERSIONINFO_ID               0x0AU
/* API service ID for Adc_GetStreamLastPointer function. */
#define ADC_GETSTREAMLASTPOINTER_ID         0x0BU
/* API service ID for Adc_SetupResultBuffer function. */
#define ADC_SETUPRESULTBUFFER_ID            0x0CU
/* API service ID for Adc_SetPowerState function. */
#define ADC_SETPOWERSTATE_ID                0x10U
/** API service ID for Adc_GetCurrentPowerState function. */
#define ADC_GETCURRENTPOWERSTATE_ID         0x11U
/* API service ID for Adc_GetTargetPowerState function. */
#define ADC_GETTARGETPOWERSTATE_ID          0x12U
/* API service ID for Adc_PreparePowerState function. */
#define ADC_PREPAREPOWERSTATE_ID            0x13U

#define ADC_MAINFUNCTION_ID                 0x14U

/* API service used without Adc module initialization. */
#define ADC_E_UNINIT                       ((uint8)0x0AU)
/* Adc module is busy with a running operation. */
#define ADC_E_BUSY                         ((uint8)0x0BU)
/* Adc module is in idle state. */
#define ADC_E_IDLE                         ((uint8)0x0CU)
/* The ADC module is already initilized. */
#define ADC_E_ALREADY_INITIALIZED          ((uint8)0x0DU)
/* The ADC module is not properly configured. */
#define ADC_E_PARAM_CONFIG                 ((uint8)0x0EU)
/* API service is called using an invalid pointer (e.g. the pointer should not be NULL). */
#define ADC_E_PARAM_POINTER                ((uint8)0x14U)
/* API service used with an invalid ADC group. */
#define ADC_E_PARAM_GROUP                  ((uint8)0x15U)
/* API service used with an invalid ADC Conversion Mode. */
#define ADC_E_WRONG_CONV_MODE              ((uint8)0x16U)
/* API service used with an invalid ADC Trigger Source. */
#define ADC_E_WRONG_TRIGG_SRC              ((uint8)0x17U)
/* Check the notification capability of a group. */
#define ADC_E_NOTIF_CAPABILITY             ((uint8)0x18U)
/* API service used without initializing the buffer. */
#define ADC_E_BUFFER_UNINIT                ((uint8)0x19U)
/* One or more HW channels are in a state different then IDLE. */
#define ADC_E_NOT_DISENGAGED               ((uint8)0x1AU)
/* Unsupported power state request. */
#define ADC_E_POWER_STATE_NOT_SUPPORTED    ((uint8)0x1BU)
/* Requested power state can not be reached directly. */
#define ADC_E_TRANSITION_NOT_POSSIBLE      ((uint8)0x1CU)
/* ADC not prepared for target power state. */
#define ADC_E_PERIPHERAL_NOT_PREPARED      ((uint8)0x1DU)

#define ADC_E_QUEUE_FULL                   ((uint8)0x20U)

#define ADC_E_TRIG_CONFLICT                ((uint8)0x21U)

#define PRIORITY_NONE  0U
#define PRIORITY_HW_SW 2U

typedef enum
{
    ADC_GS_UNINIT   = 0U,
    ADC_GS_INITED   = 1U
} Adc_GlobalStatusType;

typedef enum
{
    HWUNIT_ST_IDLE              = 0U,
    HWUNIT_ST_BUSY_LAST         = 1U,
    HWUNIT_ST_BUSY_QUEUING      = 2U
} Adc_HwUnitSTStatusType;

typedef enum
{
    HWUNIT_HT_OFF               = 0U,
    HWUNIT_HT_ON                = 1U
} Adc_HwUnitHTStatusType;

/** Current status of the conversion of the requested ADC Channel group. */
/** Specification of ADC Driver : [SWS_Adc_00513] **/
typedef enum
{
    ADC_IDLE                    = 0U,   /* The conversion of the specified group has not been started. */
    ADC_BUSY                    = 1U,   /* The conversion of the specified group has been started and is still going on. */
    ADC_COMPLETED               = 2U,   /* A conversion round (which is not the final one) of the specified group has been finished.*/
    ADC_STREAM_COMPLETED        = 3U    /* The result buffer is completely filled. */
} Adc_StatusType;

/** Type for configuring the trigger source for an ADC Channel group. **/
/** Specification of ADC Driver : [SWS_Adc_00514] **/
typedef enum
{
    ADC_TRIGG_SRC_SW            = 0U,   /* Group is triggered by a software API call. */
    ADC_TRIGG_SRC_HW            = 1U    /* Group is triggered by a hardware event. */
} Adc_TriggerSourceType;

/** Type for configuring the conversion mode of an ADC Channel group. **/
/** Specification of ADC Driver : [SWS_Adc_00515] **/
typedef enum
{
    ADC_CONV_MODE_ONESHOT       = 0U,   /* Exactly one conversion of each channel in an ADC channel group is performed after the configured trigger event.*/
    ADC_CONV_MODE_CONTINUOUS    = 1U    /* Repeated conversions of each ADC channel in an ADC channel group are performed. */
} Adc_GroupConvModeType;

/** Type for configuring the streaming access mode buffer type. **/
/** Specification of ADC Driver : [SWS_Adc_00519] **/
typedef enum
{
    ADC_STREAM_BUFFER_LINEAR    = 0U,   /* The ADC Driver stops the conversion as soon as the stream buffer is full (number of samples reached). */
    ADC_STREAM_BUFFER_CIRCULAR  = 1U    /* The ADC Driver continues the conversion even if the stream buffer is full (number of samples reached) by wrapping around the stream buffer itself. */
} Adc_StreamBufferModeType;

/** Type for configuring the access mode to group conversion results. **/
/** Specification of ADC Driver : [SWS_Adc_00528] **/
typedef enum
{
    ADC_ACCESS_MODE_SINGLE      = 0U,   /* Single value access mode. */
    ADC_ACCESS_MODE_STREAMING   = 1U    /* Streaming access mode. */
} Adc_GroupAccessModeType;

/** Type for configuring on which edge of the hardware trigger signal the driver should 
    react, i.e. start the conversion (only if supported by the ADC hardware). **/
/** Specification of ADC Driver : [SWS_Adc_00520] **/
typedef enum
{
    ADC_HW_TRIG_RISING_EDGE     = 0U,   /* React on the rising edge of the hardware trigger signal (only if supported by the ADC hardware). */
    ADC_HW_TRIG_FALLING_EDGE    = 1U,   /* React on the falling edge of the hardware trigger signal (only if supported by the ADC hardware). */
    ADC_HW_TRIG_BOTH_EDGES      = 2U    /* React on both edges of the hardware trigger signal (only if supported by the ADC hardware). */
} Adc_HwTriggerSignalType;

/** Type for configuring the prioritization mechanism. **/
/** Specification of ADC Driver : [SWS_Adc_00522] **/
typedef enum
{
    ADC_PRIORITY_NONE           = 0U,   /* priority mechanism is not available. */
    ADC_PRIORITY_HW             = 1U,   /* Hardware priority mechanism is available only. */
    ADC_PRIORITY_HW_SW          = 2U    /* Hardware and software priority mechanism is available. */
} Adc_PriorityImplementationType;

/** Replacement mechanism, which is used on ADC group level, if a group conversion 
    is interrupted by a group which has a higher priority. **/
/** Specification of ADC Driver : [SWS_Adc_00523] **/
typedef enum
{
    ADC_GROUP_REPL_ABORT_RESTART    = 0U,   /* Abort/Restart mechanism is used on group level, if a group is interrupted by a higher priority group. */
    ADC_GROUP_REPL_SUSPEND_RESUME   = 1U    /* Suspend/Resume mechanism is used on group level, if a group is interrupted by a higher priority group. */
} Adc_GroupReplacementType;

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/** In case of active limit checking: defines which conversion values are taken into 
    account related to the boardes defineed with AdcChannelLowLimit and AdcChannelHighLimit. **/
/** Specification of ADC Driver : [SWS_Adc_00524] **/
typedef enum
{
    ADC_RANGE_UNDER_LOW         = 0U,   /* below low limit - low limit value included */
    ADC_RANGE_BETWEEN           = 1U,   /* Range between low limit and high limit - high limit value included */
    ADC_RANGE_OVER_HIGH         = 2U,   /* Range above high limit */
    ADC_RANGE_ALWAYS            = 3U,   /* Complete range - independent from channel limit settings */
    ADC_RANGE_NOT_UNDER_LOW     = 4U,   /* Range above low limit */
    ADC_RANGE_NOT_BETWEEN       = 5U,   /* Range above high limit or below low limit - low limit value included */
    ADC_RANGE_NOT_OVER_HIGH     = 6U    /* Range below high limit - high limit value included */
} Adc_ChannelRangeSelectType;
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */

/** Type for alignment of ADC raw results in ADC result buffer (left/right alignment). **/
/** Specification of ADC Driver : [SWS_Adc_00525] **/
typedef enum
{
    ADC_ALIGN_RIGHT             = 0U,   /* right alignment/ */
    ADC_ALIGN_LEFT              = 1U    /* left alignment/ */
} Adc_ResultAlignmentType;

typedef enum
{
    ADC_RESOLUTION_BIT8         = 8U,
    ADC_RESOLUTION_BIT10        = 10U,
    ADC_RESOLUTION_BIT12        = 12U
} Adc_ResolutionType;

typedef enum
{
    ADC_GROUP_HWTRIGGER_DISABLED = 0U,
    ADC_GROUP_HWTRIGGER_ENABLED  = 1U
} Adc_HwTriggSwitch;

typedef enum
{
    ADC_GROUP_NOTIFICATION_DISABLED = 0U,
    ADC_GROUP_NOTIFICATION_ENABLED  = 1U
} Adc_NotifSwitch;

typedef enum
{
    ADC_GROUP_STATUS_UNINIT     = 0U,
    ADC_GROUP_STATUS_INITED     = 1U
} Adc_GroupState;

typedef enum
{
    ADC_HW_NOT_USE              = 0U,
    ADC_HW_STATUS_UNINIT        = 1U,
    ADC_HW_STATUS_INITED        = 2U
} Adc_AdcHwInitState;

#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
/** Power state currently active or set as target power state. **/
/** Specification of ADC Driver : [SWS_Adc_00526] **/
typedef enum
{
    ADC_FULL_POWER              = 0U,   /* Full Power. */
    ADC_LOW_POWER               = 1U,   /* power modes with decreasing power consumptions. */
    ADC_NODEFINE_POWER          = 2U
} Adc_PowerStateType;

/** Result of the requests related to power state transitions. **/
/** Specification of ADC Driver : [SWS_Adc_00527] **/
typedef enum
{
    ADC_SERVICE_ACCEPTED        = 0U,   /* Power state change executed. */
    ADC_NOT_INIT                = 1U,   /* ADC Module not initialized. */
    ADC_SEQUENCE_ERROR          = 2U,   /* Wrong API call sequence. */
    ADC_HW_FAILURE              = 3U,   /* The HW module has a failure which prevents it to enter the required power state. */
    ADC_POWER_STATE_NOT_SUPP    = 4U,   /* Module does not support the requested power state. */
    ADC_TRANS_NOT_POSSIBLE      = 5U    /* ADC Module cannot transition directly from the current power state to the requested power state or the HW peripheral is still busy. */
} Adc_PowerStateRequestResultType;
#endif /* ADC_POWER_STATE_SUPPORTED == STD_ON */

/** Numeric ID of an ADC channel. **/
/** Specification of ADC Driver : [SWS_Adc_00506] **/
typedef uint8 Adc_ChannelType;

/** Numeric ID of an ADC channel group. **/
/** Specification of ADC Driver : [SWS_Adc_00507] **/
typedef uint16 Adc_GroupType;

/** Type for reading the converted values of a channel group (raw, without further scaling, alignment according precompile switch ADC_RESULT_ALIGNMENT). **/
/** Specification of ADC Driver : [SWS_Adc_00508] **/
typedef uint16 Adc_ValueGroupType;

/** Type of clock prescaler factor. **/
/** Specification of ADC Driver : [SWS_Adc_00509] **/
typedef uint8 Adc_PrescaleType;

/** Priority level of the channel. Lowest priority is 0. **/
/** Specification of ADC Driver : [SWS_Adc_00516] **/
typedef uint8 Adc_GroupPriorityType;      

/** Type for assignment of channels to a channel group. **/
/** Specification of ADC Driver : [SWS_Adc_00517] **/
typedef Adc_ChannelType Adc_GroupDefType; 

/** Type for configuring the number of group conversions in streaming access mode(in single access mode, parameter is 1). **/
/** Specification of ADC Driver : [SWS_Adc_00518] **/
typedef uint16 Adc_StreamNumSampleType;

/** Type for the reload value of the ADC module embedded timer (only if supported by the ADC hardware). **/
/** Specification of ADC Driver : [SWS_Adc_00521] **/
typedef uint16 Adc_HwTriggerTimerType;

typedef uint16 Adc_HwUnitType;

typedef void (*Eqadc_pNotificationType)(void);

typedef struct
{
    VAR(Adc_HwUnitSTStatusType, ADC_VAR) HwUnit_STStatus;
    VAR(Adc_HwUnitHTStatusType, ADC_VAR) HwUnit_HTStatus;
    VAR(uint8, ADC_VAR) HwUnit_HwTriEnableCount;
#if (STD_OFF == ADC_ENABLE_QUEUING)
    VAR(Adc_GroupType, ADC_VAR) HwUnit_RunGroupId;
#else
    VAR(Adc_GroupType, ADC_VAR) HwUnit_RunGroupQueueId[ADC_QUEUE_MAX_DEPTH];
    VAR(uint16, ADC_VAR ) HwUnit_QueueNumEmpSlot;
    #if(PRIORITY_HW_SW == ADC_PRIORITY_IMPLEMENTATION)
    VAR(Adc_GroupPriorityType, ADC_VAR) HwUnit_RunGroupPrio;
    #endif
#endif
} Adc_RunningHwUnitType;

typedef struct
{
    VAR(Adc_StatusType, ADC_VAR) GroupStatus;
    P2VAR(Adc_ValueGroupType, ADC_VAR, ADC_APPL_DATA ) GroupResultBufferPtr;
    VAR(Adc_StreamNumSampleType, ADC_VAR) GroupResultIndex;
    VAR(boolean, ADC_VAR) GroupImplicStop;
#if (STD_ON == ADC_HW_TRIGGER_API)
    VAR(Adc_HwTriggSwitch, ADC_VAR) GroupSwitchHwTrig;
#endif
#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
    VAR(Adc_NotifSwitch, ADC_VAR) GroupSwitchNotifCall;
#endif
    VAR(Adc_StreamNumSampleType, ADC_VAR) StreamNumSamp;
    VAR(Adc_ChannelType, ADC_VAR) ChannelCount;
    VAR(uint8, ADC_VAR) CfifoFlag;
} Adc_RunningGroupType;

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
typedef struct
{
    VAR(Adc_ChannelRangeSelectType, ADC_VAR) RangeSelect;
    VAR(boolean, ADC_VAR) LimitCheck;
    VAR(uint32, ADC_VAR) HighLimit;
    VAR(uint32, ADC_VAR) LowLimit;
} Eqadc_ChannelLimitType;
#endif

typedef struct
{
    VAR(Eqadc_AltConfigSelType, ADC_VAR) AltConfigSel;
    VAR(boolean, ADC_VAR) ResultTransInhibit;
    VAR(Eqadc_AltConfigDestType, ADC_VAR) AltConvResultDEST;
    VAR(boolean, ADC_VAR) FMTA_SignEn;
    VAR(Eqadc_PreGainType, ADC_VAR) AdcPreGain;
} Eqadc_AlternateSetType;

typedef struct
{
    VAR(Adc_HwUnitType, ADC_VAR) HwUnitId;
    VAR(uint8, ADC_VAR) ExtTrigDigFilter;
#ifdef RESOURCE_SUPPORT_EQADC_RFIFO_CLK_SWITCH
    VAR(Eqadc_RFifoClkSwitchType, ADC_VAR) RfifoClkSwitchCfg[EQADC_RFIFO_COUNT];
#endif  /* RESOURCE_SUPPORT_EQADC_RFIFO_CLK_SWITCH */
    VAR(Eqadc_ClkPrescaleType, ADC_VAR) Clk_Prescale;
    VAR(boolean, ADC_VAR) ExtMuxEn;
#ifdef RESOURCE_SUPPORT_EQADC_CFG_PRECHARGE
    VAR(Eqadc_PrechargeClkCycleSelType, ADC_VAR) PrechargeCfg;
#endif  /* RESOURCE_SUPPORT_EQADC_CFG_PRECHARGE */
    VAR(Eqadc_IntDmaFillSelType, ADC_VAR) IntDma_Sel;
    VAR(uint8, ADC_VAR) DmaMappedChan;
    VAR(boolean, ADC_VAR) DMACompleteClearERQ;
    CONST(eDMACallbackType, ADC_CONST) Callback;
    P2VAR(void, ADC_VAR, ADC_APPL_CONST) CallbackParam;
    P2VAR(uint32, ADC_VAR, ADC_APPL_CONST) StrPtr;
    VAR(uint8, ADC_VAR) ResultDmaMappedChan;
    CONST(eDMACallbackType, ADC_CONST) ResultIrq;
    CONST(eDMACallbackType, ADC_CONST) ResultCallback;
    P2VAR(void, ADC_VAR, ADC_APPL_CONST) ResultCallbackParam;
    P2VAR(uint16, ADC_VAR, ADC_APPL_CONST) DestPtr;
    VAR(uint16, ADC_VAR) DmaSampleNum;
    VAR(Adc_TriggerSourceType, ADC_VAR) SwOrHw;
    VAR(Adc_GroupPriorityType, ADC_VAR) Prio;
    VAR(Adc_GroupConvModeType, ADC_VAR) ConvMode;
    VAR(Adc_StreamBufferModeType, ADC_VAR) StreamBufMode;
    VAR(Adc_GroupAccessModeType, ADC_VAR) AccessMode;
    VAR(Adc_HwTriggerSignalType, ADC_VAR) HwTriggerSignal;
    VAR(Adc_StreamNumSampleType, ADC_VAR) StreamNumSamp;
    VAR(Adc_ChannelType, ADC_VAR) ChannelCount;
    CONST(Eqadc_pNotificationType , ADC_CONST) GroupNotif;
    CONST(Eqadc_pNotificationType , ADC_CONST) GroupNotif_OverFlow;
    VAR(EqadcFifoIdxType, ADC_VAR) CFifo;
    VAR(uint8, ADC_VAR) HwTrigSrc;
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
    VAR(uint8, AUTOMATIC) GtmTrigAdcOutsel;
#endif
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
    VAR(boolean,  ADC_VAR) TrigDelayEn;   /* CFIFO Trigger Delay enable */
    VAR(uint32, ADC_VAR) TrigDelayVal; /* CFIFO Trigger Delay configuration value */
#endif
#ifdef RESOURCE_SUPPORT_EQADC_CFIFO_INJECTION
    VAR(boolean,  ADC_VAR) InjectionEnOfCfifo;  /* CFIFO6/CFIFO7 only */
#endif  /* RESOURCE_SUPPORT_EQADC_CFIFO_INJECTION */
    VAR(Adc_ResolutionType, ADC_VAR) Resolution;
    P2CONST(Eqadc_ConvCmdType, ADC_VAR, ADC_APPL_CONST) Eqadc_ConvCmd;
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    P2CONST(Eqadc_ChannelLimitType, ADC_VAR, ADC_APPL_CONST) Eqadc_ChannelLimit;
#endif
    P2CONST(Eqadc_AlternateSetType, ADC_VAR, ADC_APPL_CONST) Adc_AlternatSet;
} Adc_GroupConfigType;

typedef struct{
    CONST(Adc_GroupType, ADC_CONST) GroupId;
    CONST(uint8, ADC_CONST) GroupCoreId;
} Adc_CoreMapItemType;

/** Data structure containing the set of configuration parameters required for initializing the ADC Driver and ADC HW Unit(s). **/
/** Specification of ADC Driver : [SWS_Adc_00505] **/
typedef struct 
{
    P2CONST(Adc_GroupConfigType, ADC_VAR, ADC_APPL_CONST) Adc_GroupConfig;
    P2CONST(Adc_CoreMapItemType, ADC_CONST, ADC_APPL_CONST) Adc_CoreMapItem;
} Adc_ConfigType;

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_Init(P2CONST(Adc_ConfigType, ADC_CONST, ADC_APPL_CONST) ConfigPtr);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Std_ReturnType, ADC_CODE) Adc_SetupResultBuffer \
( \
    VAR(Adc_GroupType, AUTOMATIC) Group, \
    CONSTP2VAR(Adc_ValueGroupType, ADC_CONST, ADC_APPL_CONST) DataBufferPtr \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (STD_ON == ADC_DEINIT_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_DeInit(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif

#if (STD_ON == ADC_ENABLE_START_STOP_GROUP_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_StartGroupConversion(VAR(Adc_GroupType, AUTOMATIC) Group);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_StopGroupConversion(VAR(Adc_GroupType, AUTOMATIC) Group);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif

#if (STD_ON == ADC_READ_GROUP_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Std_ReturnType, ADC_CODE) Adc_ReadGroup \
( \
    VAR(Adc_GroupType, AUTOMATIC) Group, \
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) DataBufferPtr \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif

#if (STD_ON == ADC_HW_TRIGGER_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_EnableHardwareTrigger(VAR(Adc_GroupType, AUTOMATIC) Group);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_DisableHardwareTrigger(VAR(Adc_GroupType, AUTOMATIC) Group);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif

#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_EnableGroupNotification(VAR(Adc_GroupType, ADCAUTOMATIC_VAR) Group);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_DisableGroupNotification(VAR(Adc_GroupType, AUTOMATIC) Group);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Adc_StatusType, ADC_CODE) Adc_GetGroupStatus(VAR(Adc_GroupType, AUTOMATIC) Group);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Adc_StreamNumSampleType, ADC_CODE) Adc_GetStreamLastPointer \
( \
    VAR(Adc_GroupType, AUTOMATIC) Group, \
    P2P2VAR(Adc_ValueGroupType, ADC_VAR, ADC_APPL_DATA) PtrToSamplePtr \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (STD_ON == ADC_VERSION_INFO_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_GetVersionInfo \
( \
    P2VAR(Std_VersionInfoType, ADC_VAR, ADC_APPL_DATA) versioninfo \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif

#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Std_ReturnType, ADC_CODE) Adc_SetPowerState \
( \
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) Result \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Std_ReturnType, ADC_CODE) Adc_GetCurrentPowerState \
( \
    P2VAR(Adc_PowerStateType, AUTOMATIC, ADC_APPL_DATA) CurrentPowerState, \
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) Result \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Std_ReturnType, ADC_CODE) Adc_GetTargetPowerState \
( \
    P2VAR(Adc_PowerStateType, AUTOMATIC, ADC_APPL_DATA) TargetPowerState, \
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) Result \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Std_ReturnType, ADC_CODE) Adc_PreparePowerState \
( \
    VAR(Adc_PowerStateType, AUTOMATIC) PowerState, \
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) Result \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif

extern FUNC(void, ADC_CODE) Adc_GetResultIrq \
( \
    VAR(EqadcInstanceType, AUTOMATIC) eAdc_instance, \
    VAR(EqadcFifoIdxType, AUTOMATIC) eAdc_Rfifo_x,\
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_GroupId \
);

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_MainFunction(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

extern CONST(Adc_ConfigType, ADC_VAR) Adc_Config;

#endif /* ADC_H */

/** @} */
