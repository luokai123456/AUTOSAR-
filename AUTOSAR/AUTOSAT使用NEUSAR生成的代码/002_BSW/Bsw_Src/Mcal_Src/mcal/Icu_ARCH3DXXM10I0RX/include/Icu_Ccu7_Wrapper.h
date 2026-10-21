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
*   Autosar Revision     :
*   Autosar Conf.Variant :
*   SW Version           :
*   Build Version        :
*
*****************************************************************************/

/**
*   @file    Icu_Ccu7_Wrapper.h
*   @version
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
#ifndef ICU_Ccu7_WRAPPER_H
#define ICU_Ccu7_WRAPPER_H
#ifdef __cplusplus
extern "C"
{
#endif

/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "Icu_Ccu7_HAL_Wrapper.h"
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
struct ICU_Ccu7_ConfigType;
#include "Icu.h"
#include "Icu_eMIOS_Types.h"

/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_Ccu7_WRAPPER_VENDOR_ID_H                   176

#define ICU_Ccu7_WRAPPER_MAJOR_VER_H                   4
#define ICU_Ccu7_WRAPPER_MINOR_VER_H                   4
#define ICU_Ccu7_WRAPPER_REVISION_VER_H                0

#define ICU_Ccu7_WRAPPER_SW_MAJOR_VER_H                3
#define ICU_Ccu7_WRAPPER_SW_MINOR_VER_H                0
#define ICU_Ccu7_WRAPPER_SW_PATCH_VER_H                0

#if (ICU_Ccu7_WRAPPER_VENDOR_ID_H != ICU_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_Ccu7_WRAPPER_MAJOR_VER_H != ICU_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_Ccu7_WRAPPER_MINOR_VER_H != ICU_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_Ccu7_WRAPPER_REVISION_VER_H != ICU_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_Ccu7_WRAPPER_SW_MAJOR_VER_H != ICU_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_Ccu7_WRAPPER_SW_MINOR_VER_H != ICU_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_Ccu7_WRAPPER_SW_PATCH_VER_H != ICU_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

typedef struct
{
	uint8 PinSelection;
	uint8 T12PRE;
	uint8 CTM;
	uint8 INPCC7X;
	uint8 TimerModeSelectReg;
} ICU_Ccu7_HwConfig;

typedef struct
{
    /* ICU channel instance */
    CONST(Icu_IndexType,           ICU_CONST) IcuConfig_Instance;
    /* module.  */
    CONST(Icu_Module_Type,          ICU_CONST) IcuConfig_ModuleId;
    /* channel. */
    CONST(Icu_ChannelType,          ICU_CONST) IcuConfig_ChannelId;
    CONST(Icu_MeasurementModeType,  ICU_CONST) IcuConfig_ChannelMode;
    /* detect mode */
    CONST(Icu_ActivationType,       ICU_CONST) IcuChannel_DefaultStartEdge;
    CONST(Icu_NotifyType,           ICU_CONST) IcuChannel_Notification;
    CONST(Icu_NotifyType,           ICU_CONST) IcuChannel_TimestampNotification;
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
    CONST(ICU_Ccu7_HwConfig,        ICU_CONST) *pIcuConfig_HwConfig;
} ICU_Ccu7_ChannelConfig;

typedef struct ICU_Ccu7_ConfigType
{
    /* Number of ICU Ccu7 channels */
    CONST(Icu_ChannelType,          ICU_CONST) uChannelCount;
    /* Hardware dependent Channel configuration */
    CONST(ICU_Ccu7_ChannelConfig,   ICU_CONST) *pCcu7ChannelConfig;
} ICU_Ccu7_Config;

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_ChannelType, ICU_CODE) Icu_Ccu7_Wrapper_GetInstance \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Wrapper_Init \
( \
    P2CONST(struct ICU_Ccu7_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Wrapper_DeInit \
( \
    P2CONST(struct ICU_Ccu7_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_Ccu7_Wrapper_IrqConfig
(
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_Ccu7_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr, \
    VAR(boolean,                 AUTOMATIC) IsEnable
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_Ccu7_Wrapper_SetActivationCondition \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    VAR(Icu_ActivationType,              AUTOMATIC) eActivation, \
    P2CONST(struct ICU_Ccu7_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_ValueType, ICU_CODE) Icu_Ccu7_Wrapper_GetTimeElapsed \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_Ccu7_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_TIMESTAMP_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_Ccu7_Wrapper_StartTimestamp \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_Ccu7_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_Ccu7_Wrapper_StopTimestamp \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_Ccu7_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_Ccu7_Wrapper_EnableEdgeDetection \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_Ccu7_ConfigType,  ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (ICU_TIMESTAMP_API == STD_ON) */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_Ccu7_Wrapper_DisableEdgeDetection \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_Ccu7_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_Ccu7_Wrapper_StartSignalMeasurement \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    VAR(uint32,                          AUTOMATIC) u32StartEdge, \
    VAR(uint16,                          AUTOMATIC) u16MeasProperty, \
    P2CONST(struct ICU_Ccu7_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_Ccu7_Wrapper_StopSignalMeasurement \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_Ccu7_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (ICU_SIGNAL_MEASUREMENT_API == STD_ON) */
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */
#ifdef __cplusplus
}
#endif
#endif /* ICU_Ccu7_WRAPPER_H */

