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
*   @file    Icu_eMIOS_Wrapper.h
*   @version 3.0.0 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
/* PRQA S 1535 EOF */

#ifndef ICU_EMIOS_WRAPPER_H
#define ICU_EMIOS_WRAPPER_H

#ifdef __cplusplus
extern "C"
{
#endif

/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "Icu_eMIOS_HAL_Wrapper.h"
struct ICU_eMIOS_ConfigType;
#include "Icu.h"
#include "Icu_eMIOS_LLDrivers.h"
#include "Icu_eMIOS_Types.h"


/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_EMIOS_WRAPPER_VENDOR_ID_H                   176

#define ICU_EMIOS_WRAPPER_MAJOR_VER_H                   4
#define ICU_EMIOS_WRAPPER_MINOR_VER_H                   4
#define ICU_EMIOS_WRAPPER_REVISION_VER_H                0

#define ICU_EMIOS_WRAPPER_SW_MAJOR_VER_H                3
#define ICU_EMIOS_WRAPPER_SW_MINOR_VER_H                0
#define ICU_EMIOS_WRAPPER_SW_PATCH_VER_H                0

#if (ICU_EMIOS_WRAPPER_VENDOR_ID_H != ICU_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_EMIOS_WRAPPER_MAJOR_VER_H != ICU_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_EMIOS_WRAPPER_MINOR_VER_H != ICU_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_EMIOS_WRAPPER_REVISION_VER_H != ICU_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_EMIOS_WRAPPER_SW_MAJOR_VER_H != ICU_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_EMIOS_WRAPPER_SW_MINOR_VER_H != ICU_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_EMIOS_WRAPPER_SW_PATCH_VER_H != ICU_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define ICU_EMIOS_CHANNEL_MAP            STD_ON

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

typedef enum
{
    EMIOS_IC_SAIC           = 0U,   /* Edge detect */
    EMIOS_IC_IPWM           = 1U,   /* Pulse width measurement */
    EMIOS_IC_IPM            = 2U,   /* Period of pulse */
    EMIOS_IC_PEA            = 3U,   /* Pulse/Edge detect Accumulation times */
    EMIOS_IC_PEC            = 4U,   /* Pulse/Edge detect in disered time  */
    EMIOS_IC_QDEC           = 5U,   /* Quadrature Decode */
    EMIOS_IC_WPTA           = 6U,   /* Windowed Programmable Time Accumulation */
} ICU_eMIOS_Types;

typedef enum
{
    EMIOS_IC_REQ_INT        = 0U,
    EMIOS_IC_REQ_DMA        = 1U
} ICU_eMIOS_IntDmaType;

typedef struct
{
    /* select detect mode. ref@eMIOS_IC_ModeType */
    CONST(eMIOS_IC_ModeType,            ICU_CONST) mode;
    /* select timebase. ref@eMIOS_UC_CounterBusSelType */
    CONST(eMIOS_UC_CounterBusSelType,   ICU_CONST) timebase;
    /* select input filter. ref@eMIOS_UC_InputFilterType */
    CONST(eMIOS_UC_InputFilterType,     ICU_CONST) filter;
    /* config desire edge/pulse number. used for PEA, QDEC mode */
    CONST(uint32,                       ICU_CONST) desirednum;
    /* config window time. used for PEC, WPTA*/
    CONST(uint32,                       ICU_CONST) startime;
    CONST(uint32,                       ICU_CONST) endtime;
    /* emios global prescaler, 0~255 */
    CONST(uint8,                        ICU_CONST) masterPrescaler;
    /* emios channel prescaler, 0~3 */
    CONST(uint8,                        ICU_CONST) channelPrescaler;
} ICU_eMIOS_HwConfig;

typedef struct
{
    /* ICU channel instance */
    CONST(Icu_IndexType,           ICU_CONST) IcuConfig_Instance;
    /* eMIOS module. ref@ICU_eMIOS_Module_Types*/
    CONST(Icu_Module_Type,          ICU_CONST) IcuConfig_ModuleId;
    /* eMIOS channel. 0~7, 16~23 */
    CONST(Icu_ChannelType,          ICU_CONST) IcuConfig_ChannelId;
    CONST(Icu_MeasurementModeType,  ICU_CONST) IcuConfig_ChannelMode;
    /* detect mode */
    CONST(Icu_ActivationType,       ICU_CONST) IcuChannel_DefaultStartEdge;
    CONST(Icu_NotifyType,           ICU_CONST) IcuChannel_Notification;
    CONST(Icu_NotifyType,           ICU_CONST) IcuChannel_TimestampNotification;
    CONST(Icu_NotifyType,           ICU_CONST) IcuChannel_OverflowNotification;
    CONST(Icu_SignalMeasurementPropertyType, ICU_CONST) IcuChannel_SignalMeasurementProperty;
    CONST(Icu_TimestampBufferType,  ICU_CONST) IcuChannel_TimestampBufferProperty;
    CONST(boolean,                  ICU_CONST) IcuChannel_WakeupCapability;
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
    CONST(EcuM_WakeupSourceType,    ICU_CONST) IcuChannel_WakeupValue;
#endif
    /* TRUE: dma enable, FALSE: dma disable */
    CONST(boolean,                  ICU_CONST) IcuChannel_bDmaSupport;
    CONST(uint8,                    ICU_CONST) IcuChannel_DmaChannel;
    CONST(boolean,                  ICU_CONST) IcuChannel_bSignalMeasureWithoutInterrupt;
    CONST(ICU_eMIOS_HwConfig,       ICU_CONST) *pIcuConfig_HwConfig;
} ICU_eMIOS_ChannelConfig;

typedef struct ICU_eMIOS_ConfigType
{
    /* Number of ICU eMIOS channels */
    CONST(Icu_ChannelType,          ICU_CONST) uChannelCount;
    /* Hardware dependent Channel configuration */
    CONST(ICU_eMIOS_ChannelConfig,  ICU_VAR) *peMiosChannelConfig;
} ICU_eMIOS_Config;

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_ChannelType, ICU_CODE) Icu_eMios_Wrapper_GetInstance \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_eMios_Wrapper_Init \
( \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_eMios_Wrapper_DeInit \
( \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eMios_Wrapper_SetActivationCondition \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    VAR(Icu_ActivationType,              AUTOMATIC) eActivation, \
    VAR(Icu_MeasurementModeType,         AUTOMATIC) eMode, \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (Icu_InputStateType, ICU_CODE) Icu_eMios_Wrapper_GetInputState \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eMios_Wrapper_EnableEdgeDetection \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eMios_Wrapper_DisableEdgeDetection \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_STARTSIGNALMEASUREMENT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eMios_Wrapper_StartSignalMeasurement \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    VAR(uint32,                          AUTOMATIC) u32StartEdge, \
    VAR(uint16,                          AUTOMATIC) u16MeasProperty, \
    VAR(boolean,                         AUTOMATIC) bDmaSupport, \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eMios_Wrapper_StopSignalMeasurement \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_STARTSIGNALMEASUREMENT_API */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (Std_ReturnType, ICU_CODE) Icu_eMios_Wrapper_ValidateSignalMeasureWithoutInterrupt \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (uint32, ICU_CODE) Icu_eMios_Wrapper_GetStartAddress \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_STARTTIMESTAMP_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eMios_Wrapper_StartTimestamp \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    VAR(boolean,                         AUTOMATIC) bDmaSupport, \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eMios_Wrapper_StopTimestamp \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_STARTTIMESTAMP_API */

#if (ICU_ENABLEEDGECOUNT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eMios_Wrapper_ResetEdgeCount \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eMios_Wrapper_EnableEdgeCount \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eMios_Wrapper_DisableEdgeCount \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (uint32, ICU_CODE) Icu_eMios_Wrapper_GetEdgeNumbers \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_ENABLEEDGECOUNT_API */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (boolean, ICU_CODE) Icu_eMios_Wrapper_GetOverflow \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (Icu_LevelType, ICU_CODE) Icu_eMios_Wrapper_GetInputLevel \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (Icu_ValueType, ICU_CODE) Icu_eMios_Wrapper_GetCaptureRegisterValue \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eMios_Wrapper_GetPulseWidth \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_ValueType, ICU_CODE) Icu_eMios_Wrapper_GetTimeElapsed \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(EcuM_WakeupSourceType, ICU_CODE) Icu_eMios_Wrapper_GetWakeupSource \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* ICU_REPORT_WAKEUP_SOURCE */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_TimestampBufferType, ICU_CODE) Icu_eMios_Wrapper_GetTimestampBufferType \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_eMios_Wrapper_IrqConfig
(
    VAR(Icu_ChannelType,                               AUTOMATIC) nChannel, \
    P2CONST(struct ICU_eMIOS_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr, \
    VAR(boolean,                                       AUTOMATIC) IsEnable
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* ICU_EMIOS_WRAPPER_H */

