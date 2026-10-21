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
*   @file    Icu_Gtm_Wrapper.h
*   @version 3.0.0 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
/* PRQA S 1535 EOF */

#ifndef ICU_GTM_WRAPPER_H
#define ICU_GTM_WRAPPER_H

#ifdef __cplusplus
extern "C"
{
#endif
/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "Icu_Gtm_HAL_Wrapper.h"
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))

struct ICU_GTM_TIM_HwConfigType;
#include "Icu.h"



/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_GTM_WRAPPER_VENDOR_ID_H                   176

#define ICU_GTM_WRAPPER_MAJOR_VER_H                   4
#define ICU_GTM_WRAPPER_MINOR_VER_H                   4
#define ICU_GTM_WRAPPER_REVISION_VER_H                0

#define ICU_GTM_WRAPPER_SW_MAJOR_VER_H                3
#define ICU_GTM_WRAPPER_SW_MINOR_VER_H                0
#define ICU_GTM_WRAPPER_SW_PATCH_VER_H                0

#if (ICU_GTM_WRAPPER_VENDOR_ID_H != ICU_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_GTM_WRAPPER_MAJOR_VER_H != ICU_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_GTM_WRAPPER_MINOR_VER_H != ICU_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_GTM_WRAPPER_REVISION_VER_H != ICU_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_GTM_WRAPPER_SW_MAJOR_VER_H != ICU_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_GTM_WRAPPER_SW_MINOR_VER_H != ICU_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_GTM_WRAPPER_SW_PATCH_VER_H != ICU_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define ICU_GTM_CHANNEL_MAP            STD_ON

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/**
* Definition of Gtm Tim time base
*/
typedef enum
{
    GTM_TIM_CMU_CLK0,
    GTM_TIM_CMU_CLK1,
    GTM_TIM_CMU_CLK2,
    GTM_TIM_CMU_CLK3,
    GTM_TIM_CMU_CLK4,
    GTM_TIM_CMU_CLK5,
    GTM_TIM_CMU_CLK6,
    GTM_TIM_CMU_CLK7,
} GTM_TIM_TimeBase_Types;

/**
* Definition of Gtm tim filter counter frequency CMU clock
*/
typedef enum
{
    GTM_TIM_FCF_CMU_CLK0,
    GTM_TIM_FCF_CMU_CLK1,
    GTM_TIM_FCF_CMU_CLK6,
    GTM_TIM_FCF_CMU_CLK7,
} GTM_TIM_FCF_Types;

/**
* Definition of Gtm tim filter mode
*/
typedef enum
{
    GTM_TIM_FLT_MODE_IMMEDIATE,
    GTM_TIM_FLT_MODE_INDIVIDUAL,
} GTM_TIM_FM_Types;

/**
* Definition of Gtm tim filter counter mode
*/
typedef enum
{
    GTM_TIM_FLT_CNT_MODE_UD,
    GTM_TIM_FLT_CNT_MODE_HOLD,
} GTM_TIM_FCM_Types;

/**
* Definition of Gtm tim time base type
*/
typedef enum{
    GTM_TIM_TBU_TS0,
    GTM_TIM_TBU_TS1,
    GTM_TIM_TBU_TS2,
    GTM_TIM_CNT,
} GTM_TIM_GPRSel_Types;

/**
* Definition of TBU bit select
*/
typedef enum
{
    GTM_TBU0_23_0,
    GTM_TBU0_26_3,
} GTM_TBU0Sel_Types;

/**
* Gtm tim hardware config structure
*/
typedef struct ICU_GTM_TIM_HwConfigType
{
    /* TimeBase Clock ref@GTM_TIM_TimeBase_Types */
    VAR(uint8,  ICU_VAR) timebase;
    /* rising edge filter mode ref@GTM_TIM_FM_Types */
    VAR(uint8,  ICU_VAR) riseEdgeFilterMode;
    /* rising edge filter counter mode ref@GTM_TIM_FCM_Types */
    VAR(uint8,  ICU_VAR) riseCounterFilterMode;
    /* falling edge filter mode ref@GTM_TIM_FM_Types */
    VAR(uint8,  ICU_VAR) fallEdgeFilterMode;
    /* rising edge filter counter mode ref@GTM_TIM_FCM_Types */
    VAR(uint8,  ICU_VAR) fallCounterFilterMode;
    /* filter counter frequency ref@GTM_TIM_FCF_Types */
    VAR(uint8,  ICU_VAR) filterCounterFrequency;
    VAR(boolean,ICU_VAR) filterEnable;
    /* filter parameter for rising/falling edge, 0x0 ~ 0x00FFFFFF */
    VAR(uint32, ICU_VAR) filterParamRiseEdge;
    VAR(uint32, ICU_VAR) filterParamFallEdge;
    /* GPR0/1 select input source ref@GTM_TIM_GPRSel_Types */
    VAR(uint8,  ICU_VAR) GPRSel;
    /* TBU0 type ref@GTM_TBU0Sel_Types */
    VAR(uint8,  ICU_VAR) TBU0Sel;
} ICU_GTM_TIM_HwConfig;

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_ChannelType, ICU_CODE) Icu_Gtm_Wrapper_GetInstance \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_Init \
( \
    P2CONST(struct ICU_Gtm_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_DeInit \
( \
    P2CONST(struct ICU_Gtm_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_SetActivationCondition \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    VAR(Icu_ActivationType, AUTOMATIC) eIcu_Activation, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_StartTimestamp \
( \
    VAR(Icu_ChannelType,                    AUTOMATIC) u16Icu_ChannelNumber, \
    VAR(boolean,                            AUTOMATIC) bDmaSupport, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_StopTimestamp \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_IndexType, ICU_CODE) Icu_Gtm_Wrapper_GetTimestampIndex \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_ResetEdgeCount \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_EnableEdgeCount \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_DisableEdgeCount \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_EdgeNumberType, ICU_CODE) Icu_Gtm_Wrapper_GetEdgeNumbers \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_EnableEdgeDetection \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_DisableEdgeDetection \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_StartSignalMeasurement \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_StopSignalMeasurement \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_ValueType, ICU_CODE) Icu_Gtm_Wrapper_GetTimeElapsed \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_CheckWakeup \
( \
    VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource, \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelIndex \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_GetVersionInfo
( \
    P2VAR(Std_VersionInfoType, AUTOMATIC, ICU_APPL_DATA) versioninfo \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(Icu_InputStateType, ICU_CODE) Icu_Gtm_Wrapper_GetInputState \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint32, ICU_CODE) Icu_Gtm_Wrapper_GetStartAddress \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(boolean, ICU_CODE) Icu_Gtm_Wrapper_GetOverflow \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber, \
    CONSTP2CONST(struct ICU_Gtm_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (Icu_LevelType, ICU_CODE) Icu_Gtm_Wrapper_GetInputLevel \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_Gtm_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (Icu_ValueType, ICU_CODE) Icu_Gtm_Wrapper_GetCaptureRegisterValue \
( \
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(struct ICU_Gtm_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Gtm_Wrapper_IrqConfig \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber,\
    P2CONST(struct ICU_Gtm_ConfigType,   ICU_CONST, ICU_APPL_DATA) Icu_GtmConfig,\
    VAR(boolean, AUTOMATIC) IsEnable
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
#ifdef __cplusplus
}
#endif

#endif /* ICU_GTM_WRAPPER_H */

