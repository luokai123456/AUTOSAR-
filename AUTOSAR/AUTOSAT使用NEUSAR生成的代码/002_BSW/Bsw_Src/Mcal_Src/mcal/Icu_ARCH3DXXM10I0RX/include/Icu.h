/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC 
*   Peripheral           : ICU
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
*   @file    Icu.h
*   @version 3.0.0 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
/* PRQA S 3432, 1759, 1594,1758, 1752 EOF */

#ifndef ICU_H
#define ICU_H

#ifdef __cplusplus
extern "C"
{
#endif

/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "Icu_Cfg.h"
#include "EcuM.h"
#include "eDMA.h"

#if (ICU_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif

/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_VENDOR_ID_H                   176
#define ICU_MODULE_ID                     122

#define ICU_AR_RELEASE_MAJOR_VERSION      4
#define ICU_AR_RELEASE_MINOR_VERSION      4
#define ICU_REVISION_VER_H                0

#define ICU_SW_MAJOR_VER_H                3
#define ICU_SW_MINOR_VER_H                0
#define ICU_SW_PATCH_VER_H                0

#if (ICU_VENDOR_ID_H != ICU_VENDOR_ID_CFG)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_AR_RELEASE_MAJOR_VERSION != ICU_AR_RELEASE_MAJOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION_CFG"
#endif
#if (ICU_AR_RELEASE_MINOR_VERSION != ICU_AR_RELEASE_MINOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION_CFG"
#endif
#if (ICU_REVISION_VER_H != ICU_AR_RELEASE_REVISION_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_REVISION_VERSION_CFG"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_SW_MAJOR_VER_H != ICU_SW_MAJOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VERSION_CFG"
#endif
#if (ICU_SW_MINOR_VER_H != ICU_SW_MINOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VERSION_CFG"
#endif
#if (ICU_SW_PATCH_VER_H != ICU_SW_PATCH_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VERSION_CFG"
#endif

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* API IS called with invalid pointer */
#define ICU_E_PARAM_POINTER                 ((uint8)0x0A)

/* API service used with an invalid channel identifier or channel was not
   configured for the functionality of the calling API */
#define ICU_E_PARAM_CHANNEL                 ((uint8)0x0B)

/* API service used with an invalid or not feasible activation */
#define ICU_E_PARAM_ACTIVATION              ((uint8)0x0C)

/* Init function failed */
#define ICU_E_INIT_FAILED                   ((uint8)0x0D)

/* API service used with an invalid buffer size*/
#define ICU_E_PARAM_BUFFER_SIZE             ((uint8)0x0E)

/* API service Icu_SetMode used with an invalid mode */
#define ICU_E_PARAM_MODE                    ((uint8)0x0F)

/* API service used without module initialization */
#define ICU_E_UNINIT                        ((uint8)0x14)

/* API service Icu_StopTimestamp called on a channel which was not started or already stopped */
#define ICU_E_NOT_STARTED                   ((uint8)0x15)

/* API service Icu_SetMode is called while a running operation */
#define ICU_E_BUSY_OPERATION                ((uint8)0x16)

/* API Icu_Init service is called and when the ICU driver and the Hardware are already initialized */
#define ICU_E_ALREADY_INITIALIZED           ((uint8)0x17)

/* API Icu_StartTimeStamp is called and the parameter NotifyInterval is invalid */
#define ICU_E_PARAM_NOTIFY_INTERVAL         ((uint8)0x18)

/* API Icu_GetVersionInfo is called and the parameter versioninfo
   is is invalid */
#define ICU_E_PARAM_VINFO                   ((uint8)0x19)

/* API Icu_EnableEdgeDetection is called, the Over Flow error detect */
#define ICU_E_EDGECOUNTING_OVERFLOW         ((uint8)0xD0)

/* API Icu_StartTimeStamp is called, the Over Flow error detect */
#define ICU_E_TIMESTAMP_OVERFLOW            ((uint8)0xD1)

/* API Icu_StartMeasurement is called, the Over Flow error detect */
#define ICU_E_MEASUREMENT_OVERFLOW          ((uint8)0xD2)

/**
* Service ID of Icu_Init function
*/
#define ICU_INIT_ID                         ((uint8)0x00)
#define ICU_DEINIT_ID                       ((uint8)0x01)
#define ICU_SETMODE_ID                      ((uint8)0x02)
#define ICU_DISABLEWAKEUP_ID                ((uint8)0x03)
#define ICU_ENABLEWAKEUP_ID                 ((uint8)0x04)
#define ICU_SETACTIVATIONCONDITION_ID       ((uint8)0x05)
#define ICU_DISABLENOTIFICATION_ID          ((uint8)0x06)
#define ICU_ENABLENOTIFICATION_ID           ((uint8)0X07)
#define ICU_GETINPUTSTATE_ID                ((uint8)0x08)
#define ICU_STARTTIMESTAMP_ID               ((uint8)0x09)
#define ICU_STOPTIMESTAMP_ID                ((uint8)0x0A)
#define ICU_GETTIMESTAMPINDEX_ID            ((uint8)0x0B)
#define ICU_RESETEDGECOUNT_ID               ((uint8)0x0C)
#define ICU_ENABLEEDGECOUNT_ID              ((uint8)0x0D)
#define ICU_DISABLEEDGECOUNT_ID             ((uint8)0x0E)
#define ICU_GETEDGENUMBERS_ID               ((uint8)0x0F)
#define ICU_GETTIMEELAPSED_ID               ((uint8)0x10)
#define ICU_GETDUTYCYCLEVALUES_ID           ((uint8)0x11)
#define ICU_GETVERSIONINFO_ID               ((uint8)0x12)
#define ICU_STARTSIGNALMEASUREMENT_ID       ((uint8)0x13)
#define ICU_STOPSIGNALMEASUREMENT_ID        ((uint8)0x14)
#define ICU_CHECKWAKEUP_ID                  ((uint8)0x15)
#define ICU_ENABLEEDGEDETECTION_ID          ((uint8)0x16)
#define ICU_DISABLEEDGEDETECTION_ID         ((uint8)0x17)
#define ICU_GETINPUTLEVEL_ID                ((uint8)0x18)
#define ICU_GETREGISTERVALUE_ID             ((uint8)0x19)

/**
* Definition of ICU Channel state & mask
*/
#define ICU_CHANNEL_STATE_RUNNING           (0x00000008UL)
#define ICU_CHANNEL_STATE_RUNNING_SHIFT     (3U)
#define ICU_CHANNEL_STATE_RUNNING_MASK      (0x00000008UL)

#define ICU_CHANNEL_STATE_WKUP              (0x00000001UL)
#define ICU_CHANNEL_STATE_WKUP_SHIFT        (0U)
#define ICU_CHANNEL_STATE_WKUP_MASK         (0x00000001UL)

#define ICU_CHANNEL_STATE_IDLE              (0x00000002UL)
#define ICU_CHANNEL_STATE_IDLE_SHIFT        (1U)
#define ICU_CHANNEL_STATE_IDLE_MASK         (0x00000002UL)

#define ICU_CHANNEL_STATE_NOTIFICATION      (0x00000004UL)
#define ICU_CHANNEL_STATE_NOTIF_SHIFT       (2U)
#define ICU_CHANNEL_STATE_NOTIF_MASK        (0x00000004UL)

#define ICU_CHANNEL_STATE_OVERFLOW          (0x00000010UL)
#define ICU_CHANNEL_STATE_OVERF_SHIFT       (4U)
#define ICU_CHANNEL_STATE_OVERFLOW_MASK     (0x00000010UL)

#define ICU_CHANNEL_IS_WAKEUP_SOURCE        (0x00000020UL)
#define ICU_CHANNEL_WAKEUP_SOURCE_SHIFT     (5U)
#define ICU_CHANNEL_WAKEUP_SOURCE_MASK      (0x00000020UL)

/**
* Definition invalid channel value
*/
#define ICU_INVALID_INSTANCE                (ICU_MAX_CHANNEL)

/**
* Definition coreID of Icu
*/
#if(ICU_MULTI_CORE_SUPPORT == STD_ON)
    #define Icu_GetCoreID()                 ((uint8)1U << GetCoreID())
#else
    #define Icu_GetCoreID()                 (1U << ICU_DEFAULT_COREID)
#endif

#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
#define ICU_CHN_USED                        ((uint8)255U)
#define ICU_CHN_UNUSED                      ((uint8)0U)
#endif

#define ICU_CORE_NUM                        MCAL_CORE_NUM

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/**
* ICU GTM module Structure declaration
*/
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))	
struct ICU_Gtm_ConfigType;
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
/**
* Numeric identifier of an ICU channel
*/
typedef uint16 Icu_ChannelType;

/**
* Type, to ICU config IP module type
*/
typedef uint8 Icu_Module_Type;

/**
* Width of the buffer for timestamp ticks and measured elapsed timeticks
*/
typedef uint32 Icu_ValueType;

/**
* Type, to abstract the return value of the service Icu_GetTimestampIndex().Since
* circular buffer handling is supported and Icu_GetTimestampIndex can return '0' as
* a legally true value 
*/
typedef uint16 Icu_IndexType;

/**
* used for channel mask state
*/
typedef uint32 Icu_ChannelState_Type;

/**
* Type, to abstract the return value of the service Icu_GetEdgeNumbers()
*/
typedef uint16 Icu_EdgeNumberType;

/**
* Type, to abstract the wakeup value, used for channel wakeup event
*/

/**
* The notification function declaration used for Icu_StartTimestamp
*/
typedef VAR(void,ICU_VAR) (*Icu_NotifyType)(void);

/**
* Definition of ICU hardware channel
*/
typedef enum
{
    ICU_GTM_TIM0,                           /**< Gtm module type TIM0 */
    ICU_GTM_TIM1,                           /**< Gtm module type TIM1 */
    ICU_GTM_TIM2,                           /**< Gtm module type TIM2 */
    ICU_GTM_TIM3,                           /**< Gtm module type TIM3 */
    ICU_GTM_TIM4,                           /**< Gtm module type TIM4 */
    ICU_GTM_TIM5,                           /**< Gtm module type TIM5 */
#if defined RESOURCE_SUPPORT_GTM410
    ICU_GTM_TIM6,                           /**< Gtm module type TIM6 */
    ICU_GTM_TIM7,                           /**< Gtm module type TIM7 */
#endif

    ICU_eMIOS_0,                            /**< eMios module type 0 */
    ICU_eMIOS_1,                            /**< eMios module type 1 */
    ICU_CCU7_INS0,                             /**< eTPU module type Ccu7_0 ICU_CCU7_INS0*/
    ICU_CCU7_INS1,                             /**< eTPU module type Ccu7_1 */
#ifdef RESOURCE_SUPPORT_ETPU                         
    ICU_eTPU_A,                             /**< eTPU module type eTPU_0 block A */
    ICU_eTPU_B,                             /**< eTPU module type eTPU_0 block B */
    ICU_eTPU_C,                             /**< eTPU module type eTPU_1 block A */
#endif                           
    ICU_WKPU
} ICU_HwModule_Type;

/**
* Definition of ICU Module state
*/
typedef enum
{
    ICU_STATE_UNINIT        = 0x00,         /**< ICU Not initializtion */
    ICU_STATE_IDLE          = 0x01          /**< ICU already initializtion complete */
} Icu_ModuleState_Type;

/**
* Definition of the timestamp measurement property type
*/
typedef enum
{
    ICU_LINEAR_BUFFER       = 0x10U,        /**< The buffer will just be filled once */
    ICU_CIRCULAR_BUFFER     = 0x20U         /**< After reaching the end of the buffer, the driver restarts at
                                                 the beginning of the buffer */
} Icu_TimestampBufferType;

/**
* Definition of the measurement property type
*/
typedef enum
{
    ICU_LOW_TIME            = 1U,           /**< The channel is configured for reading the elapsed Signal
                                                 Low Time */
    ICU_HIGH_TIME           = 2U,           /**< The channel is configured for reading the elapsed Signal
                                                 High Time */
    ICU_PERIOD_TIME         = 3U,           /**< The channel is configured for reading the elapsed Signal
                                                 Period Time */
    ICU_DUTY_CYCLE          = 4U            /**< The channel is configured to read values which are needed
                                                 for calculating the duty cycle (coherent Active and Period
                                                 Time).*/
} Icu_SignalMeasurementPropertyType;

/**
* Definition of the type of activation of an ICU channel
*/
typedef enum
{
    ICU_FALLING_EDGE        = 0x0U,         /**< An appropriate action shall be executed when a falling
                                                 edge occurs on the ICU input signal */
    ICU_RISING_EDGE         = 0x1U,         /**< An appropriate action shall be executed when a rising edge
                                                 occurs on the ICU input signal */
    ICU_BOTH_EDGES          = 0x2U          /**< An appropriate action shall be executed when either a
                                                 rising or falling edge occur on the ICU input signal */
} Icu_ActivationType;

/**
* Input state of an ICU channel
*/
typedef enum
{
    ICU_ACTIVE              = 0U,           /**< An activation edge has been detected */
    ICU_IDLE                = 1U            /**< No activation edge has been detected since the last call of
                                                 Icu_GetInputState() or Icu_Init() */
} Icu_InputStateType;

/**
*  Definition of the measurement mode type
*/
typedef enum
{
    ICU_MODE_SIGNAL_EDGE_DETECT = 0x01U,    /**< Mode for detecting edges */
    ICU_MODE_SIGNAL_MEASUREMENT = 0x02U,    /**< Mode for measuring different times between
                                                 various configurable edges */
    ICU_MODE_TIMESTAMP          = 0x04U,    /**< Mode for capturing timer values on
                                                 configurable edges */
    ICU_MODE_EDGE_COUNTER       = 0x08U     /**< Mode for counting edges on configurable edges */
} Icu_MeasurementModeType;

/**
* Allow enabling / disabling of all interrupts which are not required for the ECU wakeup.
*/
typedef enum
{
    ICU_MODE_NORMAL         = 0U,           /**< Normal operation, all used interrupts are enabled according
                                                 to the notification requests */
    ICU_MODE_SLEEP          = 1U               /**< Reduced power operation. In sleep mode only those
                                                 notifications are available which are configured as wakeup
                                                 capable */
} Icu_ModeType;

/**
* Definition of Dual clock config type
*/
typedef enum
{
    ICU_CLOCK_MODE_NORMAL    = 0x0U,        /**< Normal state clock */
    ICU_CLOCK_MODE_ALTERNATE = 0x1U         /**< Alternate state clock, used for dual clock */
} Icu_SelectPrescalerType;

/**
* Definition of ICU channel input pin level
*/
typedef enum
{
    ICU_LEVEL_LOW           = 0x0U,         /**< The input pin level is low */
    ICU_LEVEL_HIGH          = 0x1U          /**< The input pin level is high */
} Icu_LevelType;

#include "Icu_eMIOS_Wrapper.h"
#include "Icu_eTPU_Wrapper.h"
#include "Icu_Gtm_Wrapper.h"
#include "Icu_Wkpu_Wrapper.h"

/**
* ICU configure channel parameter, save for GTM, eMios, eTPU module
*/
typedef struct
{
    VAR(Icu_MeasurementModeType,  ICU_VAR) IcuConfig_ChannelMode;
    VAR(Icu_NotifyType,           ICU_VAR) IcuChannel_Notification;
    VAR(Icu_NotifyType,           ICU_VAR) IcuChannel_TimestampNotification;
    VAR(Icu_NotifyType,           ICU_VAR) IcuChannel_OverflowNotification;
    VAR(Icu_SignalMeasurementPropertyType, ICU_VAR) IcuChannel_SignalMeasurementProperty;
    VAR(Icu_TimestampBufferType,  ICU_VAR) IcuChannel_TimestampBufferProperty;
    VAR(boolean,                  ICU_VAR) IcuChannel_WakeupCapability;
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
    VAR(EcuM_WakeupSourceType,    ICU_VAR) IcuChannel_WakeupValue;
#endif
    VAR(boolean,                  ICU_VAR) IcuChannel_bDmaSupport;
    VAR(uint8,                    ICU_VAR) IcuChannel_DmaChannel;
} Icu_ChannelConfigInfoType;

/**
* ICU configure channel parameter, save for GTM, eMios, eTPU module
* And Definition of Detect data
*/
typedef struct 
{
    VAR(Icu_IndexType,          ICU_VAR) u16Icu_Instance;                       /**< Icu channel */
    VAR(Icu_ChannelState_Type,  ICU_VAR) u32Icu_ChannelState;                   /**< Icu channel state */
    P2VAR(Icu_ValueType,        ICU_VAR, ICU_APPL_DATA) u32Icu_ChannelBuffer;   /**< Pointer to timestamp buffer */
    VAR(Icu_IndexType,          ICU_VAR) u32Icu_ChannelBufferSize;              /**< Timestamp buffer size */
    VAR(Icu_IndexType,          ICU_VAR) u32Icu_ChannelBufferNotify;            /**< Timestamp receive data counter */
    VAR(Icu_IndexType,          ICU_VAR) u32Icu_ChannelBufferNotifyCount;       /**< Timestamp notify counter */
    VAR(Icu_IndexType,          ICU_VAR) u32Icu_ChannelBufferIndex;             /**< Timestamp receive data number */
    VAR(Icu_ValueType,          ICU_VAR) u32Icu_ChannelPeriod;                  /**< Measurement period counter */
    VAR(Icu_ValueType,          ICU_VAR) u32Icu_ChannelActiveTime;              /**< Measurement active counter */
    VAR(uint16,                 ICU_VAR) u32Icu_ChannelEdgeNumbers;             /**< Save edge number */
    VAR(Icu_InputStateType,     ICU_VAR) u32Icu_ChannelEdgeDetection;           /**< Input data state, measurement & edgedetect */
    VAR(Icu_ChannelConfigInfoType, ICU_VAR) sIcu_ChannelConfig;
} Icu_ChannelInfoType;

/**
* Gtm module config parameter
*/
typedef struct
{
    /* ICU channel instance */
    CONST(Icu_IndexType,            ICU_CONST) IcuConfig_Instance;          /**< ICU channel number */
    CONST(Icu_Module_Type,          ICU_CONST) IcuConfig_ModuleId;          /**< Gtm module number */
    CONST(Icu_ChannelType,          ICU_CONST) IcuConfig_ChannelId;         /**< Gtm module channel number */
    CONST(Icu_ChannelType,          ICU_CONST)IcuConfig_Tim_Selection;
    CONST(Icu_MeasurementModeType,  ICU_CONST) IcuConfig_ChannelMode;       /**< Gtm channel measurement mode */
    CONST(Icu_ActivationType,       ICU_CONST) IcuChannel_DefaultStartEdge; /**< Gtm channel detect edge */
    CONST(Icu_NotifyType,           ICU_CONST) IcuChannel_Notification;     /**< Gtm Channel notification function */
    CONST(Icu_NotifyType,           ICU_CONST) IcuChannel_TimestampNotification;    /**< Timestamp notification */
    CONST(Icu_NotifyType,           ICU_CONST) IcuChannel_OverflowNotification;
    CONST(Icu_SignalMeasurementPropertyType, ICU_CONST) IcuChannel_SignalMeasurementProperty;   /**< Measurement type */
    CONST(Icu_TimestampBufferType,  ICU_CONST) IcuChannel_TimestampBufferProperty;  /**< Timestamp buffer mode */
    CONST(boolean,                  ICU_CONST) IcuChannel_WakeupCapability; /* Wakeup enable */
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
    CONST(EcuM_WakeupSourceType,    ICU_CONST) IcuChannel_WakeupValue;      /**< Wakeup source */
#endif
    CONST(boolean,                  ICU_CONST) IcuChannel_bDmaSupport;      /**< DMA enable */
    CONST(uint8,                    ICU_CONST) IcuChannel_DmaChannel;       /**< DMA channel */
    CONST(struct ICU_GTM_TIM_HwConfigType,     ICU_CONST) *pIcuConfig_HwConfig; /**< GTM hardware configure */
} Icu_ChannelConfig_Type;

/**
* Gtm module channel config structure
*/
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))	
typedef struct ICU_Gtm_ConfigType
{
    CONST(Icu_ChannelType,          ICU_CONST) uChannelCount;               /**< Number of ICU etpu channels */
    CONST(Icu_ChannelConfig_Type,   ICU_CONST) *pGtmChannelConfig;          /**< Hardware dependent Channel configuration */
} ICU_Gtm_Config;
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
/**
* Icu core map structure
*/
typedef struct
{
    CONST(Icu_ChannelType,          ICU_CONST) nIcuChannelId;
    CONST(uint8,                    ICU_CONST) nCoreId;
} Icu_CoreMapItemType;

/**
* This type contains initialization data
* Hardware and implementation dependent structure.
* The contents of the initialization data structure are microcontroller specific.
*/
typedef struct
{
    CONST(Icu_ChannelType,               ICU_CONST) Icu_NumChannels;                    /**< ICU config all channel number */
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))	
    P2CONST(struct ICU_Gtm_ConfigType,   ICU_CONST, ICU_APPL_DATA) Icu_GtmConfig;       /**< ICU GTM module configure */
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_CONST, ICU_APPL_DATA) Icu_eMoisConfig;     /**< ICU eMios module configure */
#if (defined(RESOURCE_SUPPORT_ETPU))
    P2CONST(struct ICU_eTPU_ConfigType,  ICU_CONST, ICU_APPL_DATA) Icu_eTpuConfig;      /**< ICU eTPU module configure */
#endif /*#RESOURCE_SUPPORT_ETPU*/
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
    P2CONST(struct ICU_Ccu7_ConfigType,  ICU_CONST, ICU_APPL_DATA) Icu_Ccu7Config;      /**< ICU Ccu7 module configure */
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */
#if (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI))
    P2CONST(struct ICU_Wkpu_Config,      ICU_CONST, ICU_APPL_DATA) Icu_WkpuConfig;
#endif /* (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI)) */
    CONST(ICU_HwModule_Type,             ICU_CONST) (*Icu_HwChMap)[ICU_MAX_CHANNEL];    /**< ICU Channel module map array */
    P2CONST(Icu_CoreMapItemType,         ICU_CONST, ICU_APPL_DATA) Icu_CoreMap;         /**< ICU Channel module map array */
} Icu_ConfigType;

/**
* Type which shall contain the values, needed for calculating duty cycles.
*/
typedef struct
{
    VAR(Icu_ValueType, ICU_VAR) ActiveTime;             /**< This shall be the coherent active-time
                                                             measured on a channel */
    VAR(Icu_ValueType, ICU_VAR) PeriodTime;             /**< This shall be the coherent period-time
                                                             measured on a channel */
} Icu_DutyCycleType;

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
#define ICU_START_SEC_VAR_SHARED_INIT
/**
* Flag to Channel init
*/
#include "Icu_MemMap.h"
extern volatile VAR(uint8, ICU_VAR) sIcu_u8Hw2LogicChannelMap[ICU_CORE_NUM][ICU_MAX_CHANNEL];
#define ICU_STOP_SEC_VAR_SHARED_INIT
#include "Icu_MemMap.h"
#endif

extern P2CONST(Icu_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_CfgPtr[ICU_CORE_NUM]; 
extern VAR(Icu_ChannelInfoType, AUTOMATIC) sIcu_ChannelInfo[ICU_CORE_NUM][ICU_MAX_CHANNEL];
extern VAR(Icu_ModeType, ICU_VAR) eIcu_CurrentMode[ICU_CORE_NUM];

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Init(P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) ConfigPtr);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_DEINIT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_DeInit(void);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#if (ICU_SETMODE_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_SetMode(VAR(Icu_ModeType,AUTOMATIC) Mode);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#if (ICU_DISABLEWAKEUP_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_DisableWakeup(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#if (ICU_ENABLEWAKEUP_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_EnableWakeup(VAR(Icu_ChannelType,AUTOMATIC) Channel);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_SetActivationCondition \
( \
    VAR(Icu_ChannelType, AUTOMATIC) Channel, \
    VAR(Icu_ActivationType, AUTOMATIC) Activation \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_DisableNotification(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_EnableNotification(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_GETINPUTSTATE_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_InputStateType, ICU_CODE) Icu_GetInputState(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#if (ICU_STARTTIMESTAMP_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_StartTimestamp \
( \
    VAR(Icu_ChannelType, AUTOMATIC) Channel, \
    P2VAR(Icu_ValueType, AUTOMATIC, ICU_APPL_DATA) BufferPtr, \
    VAR(uint16, AUTOMATIC) BufferSize, \
    VAR(uint16, AUTOMATIC) NotifyInterval \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#if (ICU_STOPTIMESTAMP_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_StopTimestamp(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#if (ICU_GETTIMESTAMPINDEX_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_IndexType, ICU_CODE) Icu_GetTimestampIndex(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#if (ICU_RESETEDGECOUNT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_ResetEdgeCount(VAR(Icu_ChannelType,AUTOMATIC) Channel);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#if (ICU_ENABLEEDGECOUNT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_EnableEdgeCount(VAR(Icu_ChannelType,AUTOMATIC) Channel);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#if (ICU_DISABLEEDGECOUNT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_DisableEdgeCount(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#if (ICU_GETEDGENUMBERS_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_EdgeNumberType, ICU_CODE) Icu_GetEdgeNumbers(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#if (ICU_ENABLEEDGEDETECTION_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_EnableEdgeDetection(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#if (ICU_DISABLEEDGEDETECTION_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_DisableEdgeDetection(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#if (ICU_STARTSIGNALMEASUREMENT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_StartSignalMeasurement(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#if (ICU_STOPSIGNALMEASUREMENT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_StopSignalMeasurement(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#if (ICU_GETTIMEELAPSED_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_ValueType, ICU_CODE) Icu_GetTimeElapsed(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#if (ICU_GETDUTYCYCLEVALUES_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_GetDutyCycleValues \
( \
    VAR(Icu_ChannelType, AUTOMATIC) Channel, \
    P2VAR(Icu_DutyCycleType, AUTOMATIC, ICU_APPL_DATA) DutyCycleValues \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#if (ICU_CHECKWAKEUP_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_CheckWakeup(VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#if (ICU_GETVERSIONINFO_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_GetVersionInfo \
( \
    P2VAR(Std_VersionInfoType, AUTOMATIC, ICU_APPL_DATA) versioninfo \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

/*==================================================================================================
*                                    FUNCTION NOT AUTOSAR
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void,ICU_CODE) Icu_ClearChannelState \
( \
    VAR(Icu_ChannelType,AUTOMATIC) u16Icu_Channel, \
    VAR(Icu_ChannelState_Type,AUTOMATIC) u32Icu_StateMask \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_ChannelState_Type,ICU_CODE) Icu_GetChannelState \
( \
    VAR(Icu_ChannelType,AUTOMATIC) u16Icu_Channel, \
    VAR(Icu_ChannelState_Type,AUTOMATIC) u32Icu_StateMask \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_LevelType,ICU_CODE) Icu_GetInputLevel \
( \
    VAR(Icu_ChannelType,AUTOMATIC) u16Icu_Channel
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_CAPTURERGISTER_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (Icu_ValueType, ICU_CODE) Icu_GetCaptureRegisterValue \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_SetChannelState \
( \
    VAR(Icu_ChannelType,AUTOMATIC) u16Icu_Channel, \
    VAR(Icu_ChannelState_Type,AUTOMATIC) u32Icu_StateMask \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_ReportWakeupAndOverflow \
( \
    VAR(Icu_ChannelType,    AUTOMATIC) Channel, \
    VAR(boolean,            AUTOMATIC) bOverflow \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_ReportEvents \
( \
    VAR(Icu_ChannelType,    AUTOMATIC) Channel, \
    VAR(boolean,            AUTOMATIC) bOverflow \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void,ICU_CODE) Icu_Timestamp \
( \
    VAR(Icu_ChannelType,    AUTOMATIC) Channel, \
    VAR(uint8,              AUTOMATIC) u8CapturedWords, \
    P2CONST(Icu_ValueType,  AUTOMATIC,  ICU_APPL_CONST) pBufferPtr, \
    VAR(boolean,            AUTOMATIC) bOverflow \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_STARTSIGNALMEASUREMENT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void,ICU_CODE) Icu_SignalMeasurement \
( \
    VAR(Icu_ChannelType,    AUTOMATIC) Channel, \
    VAR(Icu_ValueType,      AUTOMATIC) activePulseWidth, \
    VAR(Icu_ValueType,      AUTOMATIC) period, \
    VAR(boolean,            AUTOMATIC) bOverflow \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_STARTSIGNALMEASUREMENT_API */

ICU_CONFIG_DECLARATION


#ifdef __cplusplus
}
#endif

#endif

