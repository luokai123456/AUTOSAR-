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
*   @file    Icu_eTPU_HAL_Wrapper.h
*   @version 3.0.0 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
/* PRQA S 3432, 1535 EOF */
#ifndef ICU_ETPU_HAL_WRAPPER_H
#define ICU_ETPU_HAL_WRAPPER_H

#ifdef __cplusplus
extern "C"
{
#endif
/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "derivative.h"
#if (defined(RESOURCE_SUPPORT_ETPU))
#include "Icu_eTPU_LLDrivers.h"
#include "Icu.h"
#include "Icu_eMIOS_Types.h"

/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_ETPU_HAL_WRAPPER_VENDOR_ID_H                   176

#define ICU_ETPU_HAL_WRAPPER_MAJOR_VER_H                   4
#define ICU_ETPU_HAL_WRAPPER_MINOR_VER_H                   4
#define ICU_ETPU_HAL_WRAPPER_REVISION_VER_H                0

#define ICU_ETPU_HAL_WRAPPER_SW_MAJOR_VER_H                3
#define ICU_ETPU_HAL_WRAPPER_SW_MINOR_VER_H                0
#define ICU_ETPU_HAL_WRAPPER_SW_PATCH_VER_H                0

#if (ICU_ETPU_HAL_WRAPPER_VENDOR_ID_H != ICU_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_ETPU_HAL_WRAPPER_MAJOR_VER_H != ICU_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_ETPU_HAL_WRAPPER_MINOR_VER_H != ICU_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_ETPU_HAL_WRAPPER_REVISION_VER_H != ICU_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_ETPU_HAL_WRAPPER_SW_MAJOR_VER_H != ICU_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_ETPU_HAL_WRAPPER_SW_MINOR_VER_H != ICU_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_ETPU_HAL_WRAPPER_SW_PATCH_VER_H != ICU_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define ETPU_TIME_COUT_MAX                  (0x00FFFFFFU)

/**
* Definition of eTPU channel
*/
#define ETPU_CHANNEL_0                      (uint8)0U
#define ETPU_CHANNEL_1                      (uint8)1U
#define ETPU_CHANNEL_2                      (uint8)2U
#define ETPU_CHANNEL_3                      (uint8)3U
#define ETPU_CHANNEL_4                      (uint8)4U
#define ETPU_CHANNEL_5                      (uint8)5U
#define ETPU_CHANNEL_6                      (uint8)6U
#define ETPU_CHANNEL_7                      (uint8)7U
#define ETPU_CHANNEL_8                      (uint8)8U
#define ETPU_CHANNEL_9                      (uint8)9U
#define ETPU_CHANNEL_10                     (uint8)10U
#define ETPU_CHANNEL_11                     (uint8)11U
#define ETPU_CHANNEL_12                     (uint8)12U
#define ETPU_CHANNEL_13                     (uint8)13U
#define ETPU_CHANNEL_14                     (uint8)14U
#define ETPU_CHANNEL_15                     (uint8)15U
#define ETPU_CHANNEL_16                     (uint8)16U
#define ETPU_CHANNEL_17                     (uint8)17U
#define ETPU_CHANNEL_18                     (uint8)18U
#define ETPU_CHANNEL_19                     (uint8)19U
#define ETPU_CHANNEL_20                     (uint8)20U
#define ETPU_CHANNEL_21                     (uint8)21U
#define ETPU_CHANNEL_22                     (uint8)22U
#define ETPU_CHANNEL_23                     (uint8)23U
#define ETPU_CHANNEL_24                     (uint8)24U
#define ETPU_CHANNEL_25                     (uint8)25U
#define ETPU_CHANNEL_26                     (uint8)26U
#define ETPU_CHANNEL_27                     (uint8)27U
#define ETPU_CHANNEL_28                     (uint8)28U
#define ETPU_CHANNEL_29                     (uint8)29U
#define ETPU_CHANNEL_30                     (uint8)30U
#define ETPU_CHANNEL_31                     (uint8)31U

#define ETPU_MODULE_MAX                     (3U)
#define ETPU_CHANEEL_MAX                    (32U)
#define ETPU_HANDLE_MODULE_MASK             (5U)
#define ETPU_MODU_CHAN_COMBIN(m, c)         (uint8)(((uint8)((m) << ETPU_HANDLE_MODULE_MASK)) | (c))

/* declare config data indicator */
#define ETPU_CONFIG_DATA_INITED             (0UL)
/* used for select Mode for detecting */
#define ETPU_CONFIG_DATA_MEASMODE           (1UL)
/* used for ETPU CN Register Mode */
#define ETPU_CONFIG_DATA_OPMODE             (2UL)
#define ETPU_CONFIG_DATA_DMA                (3UL)
#define ETPU_CONFIG_DATA_PROPERTY           (4UL)
#define ETPU_CONFIG_DATA_CLEAR              (0xFFUL)

/* Mode for detecting edges. */
#define ETPU_MODE_SIGNAL_EDGE_DETECT       0x01UL
/* Mode for measuring different times between various configurable edges. */
#define ETPU_MODE_SIGNAL_MEASUREMENT       0x02UL
/* Mode for capturing timer values on configurable edges. */
#define ETPU_MODETIMESTAMP_WITHOUT_DMA     0x04UL
/* Mode for capturing timer values on configurable edges. */
#define ETPU_MODE_TIMESTAMP_WITH_DMA       0x10UL
/* Mode for counting edges on configurable edges. */
#define ETPU_MODE_EDGE_COUNTER             0x08UL

/* Signal Measurment Type */
#define ETPU_MEAS_TYPE_LOW_TIME            0x01UL
#define ETPU_MEAS_TYPE_HIGH_TIME           0x02UL
#define ETPU_MEAS_TYPE_PERIOD_TIME         0x04UL
#define ETPU_MEAS_TYPE_DUTY_CYCLE          0x08UL


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
typedef enum
{
    eTPU_A,
    eTPU_B,
    eTPU_C
} eTPU_Module_Types;

typedef struct
{
    VAR(etpu_ic_param_t,    AUTOMATIC) sChannelParam;
    VAR(boolean,            AUTOMATIC) bDmaSupport;
} eTPU_Channel_Config;

/**
* Saves channel config data
*/
typedef union
{
    uint32 data;
    struct
    {
        volatile unsigned int inited:1;
        volatile unsigned int mode:7;
        volatile unsigned int opmode:4;
        volatile unsigned int property:4;
        volatile unsigned int dma:1;
        volatile unsigned int reserved:15;
    } bits;
} eTPU_Channel_ConfigData;

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_Init \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel, \
    P2VAR(eTPU_Channel_Config, AUTOMATIC, ICU_CODE) peTpuChannelConfig \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_ConfigInit \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel, \
    P2VAR(eTPU_Channel_Config, AUTOMATIC, ICU_CODE) peTpuChannelConfig \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_DeInit \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_SetActivationCondition \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    CONST(eTPU_EdgeTrigModeType, AUTOMATIC) eActivation
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_EnableEdgeDetection \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_DisableEdgeDetection \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_STARTTIMESTAMP_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_StartTimestamp \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(boolean,    AUTOMATIC) bDmaSupport \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_StopTimestamp \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (ICU_STARTTIMESTAMP_API == STD_ON) */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint32, ICU_CODE) eTpu_Channel_GetStartAddress \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_ENABLEEDGECOUNT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_ResetEdgeCount \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_EnableEdgeCount \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_DisableEdgeCount \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (uint32, ICU_CODE) eTpu_Channel_GetEdgeNumbers \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (ICU_ENABLEEDGECOUNT_API == STD_ON) */

#if (ICU_STARTSIGNALMEASUREMENT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_StartSignalMeasurement \
( \
    VAR(uint8,                    AUTOMATIC) u8Module, \
    VAR(uint8,                    AUTOMATIC) u8Channel, \
    VAR(eTPU_EdgeTrigModeType,    AUTOMATIC) eActivation, \
    VAR(uint16,                   AUTOMATIC) nMeasProperty, \
    VAR(boolean,                  AUTOMATIC) bDmaSupport, \
    VAR(boolean,                  AUTOMATIC) bWithoutInterrupt \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_StopSignalMeasurement \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif  /* ICU_STARTSIGNALMEASUREMENT_API == STD_ON */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (boolean, ICU_CODE) eTpu_Channel_GetInputState \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (boolean, ICU_CODE) eTpu_Channel_GetOverflow \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(boolean, ICU_CODE) eTpu_Channel_GetInputLevel \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint32, ICU_CODE) eTpu_Channel_GetFinalTime \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTpu_Channel_ProcessCommonIrq \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_STARTSIGNALMEASUREMENT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint32, ICU_CODE) eTpu_GetPulseWidth
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

#if (ICU_ENABLEEDGECOUNT_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint32, ICU_CODE) eTpu_GetEdgeValue
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif
#endif /* (defined(RESOURCE_SUPPORT_ETPU)) */
#ifdef __cplusplus
}
#endif

#endif /* ICU_ETPU_HAL_WRAPPER_H */

