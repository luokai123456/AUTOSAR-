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
/* PRQA S 1535,1756,1594,1758 EOF */
/**
*   @file    Icu_Ccu7_HAL_Wrapper.h
*   @version
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
#ifndef ICU_Ccu7_HAL_WRAPPER_H
#define ICU_Ccu7_HAL_WRAPPER_H
#ifdef __cplusplus
extern "C"{
#endif


/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "Std_Types.h"
#include "Icu.h"
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
#include "Icu_Ccu7_LLDrivers.h"

/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_Ccu7_HAL_WRAPPER_VENDOR_ID_H                   176

#define ICU_Ccu7_HAL_WRAPPER_MAJOR_VER_H                   4
#define ICU_Ccu7_HAL_WRAPPER_MINOR_VER_H                   4
#define ICU_Ccu7_HAL_WRAPPER_REVISION_VER_H                0

#define ICU_Ccu7_HAL_WRAPPER_SW_MAJOR_VER_H                3
#define ICU_Ccu7_HAL_WRAPPER_SW_MINOR_VER_H                0
#define ICU_Ccu7_HAL_WRAPPER_SW_PATCH_VER_H                0

#if (ICU_Ccu7_HAL_WRAPPER_VENDOR_ID_H != ICU_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_Ccu7_HAL_WRAPPER_MAJOR_VER_H != ICU_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_Ccu7_HAL_WRAPPER_MINOR_VER_H != ICU_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_Ccu7_HAL_WRAPPER_REVISION_VER_H != ICU_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_Ccu7_HAL_WRAPPER_SW_MAJOR_VER_H != ICU_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_Ccu7_HAL_WRAPPER_SW_MINOR_VER_H != ICU_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_Ccu7_HAL_WRAPPER_SW_PATCH_VER_H != ICU_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define CCU7_CONFIG_DATA_INITED              (0U)
#define CCU7_CONFIG_DATA_MEASMODE            (1U)
#define CCU7_CONFIG_DATA_OPMODE              (2U)
#define CCU7_CONFIG_DATA_DMA                 (3U)
#define CCU7_CONFIG_DATA_PROPERTY            (4U)
#define CCU7_CONFIG_DATA_CLEAR               (0xFFU)

/* Mode for detecting edges. */
#define CCU7_MODE_SIGNAL_EDGE_DETECT       (uint32)0x01U
/* Mode for measuring different times between various configurable edges. */
#define CCU7_MODE_SIGNAL_MEASUREMENT       (uint32)0x02U
/* Mode for capturing timer values on configurable edges. */
#define CCU7_MODETIMESTAMP_WITHOUT_DMA     (uint32)0x04U
/* Mode for counting edges on configurable edges. */
#define CCU7_MODE_EDGE_COUNTER             (uint32)0x08U

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define ICU_CCU7_HANDLE_MODULE_MASK          (uint8)(2U)
#define ICU_CCU7_MODU_CHAN_COMBIN(m, c)      (uint8)((uint8)((m * ICU_CCU7_MODULE_CHANNEL_MAX) + c))
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
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
} Ccu7_Channel_ConfigData;

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


typedef struct
{
    VAR(Ccu7_ic_param_t,    AUTOMATIC) sChannelParam;
    VAR(boolean,            AUTOMATIC) bDmaSupport;
} Ccu7_Channel_Config;

typedef enum
{
    ICU_Ccu7_TimerId_t12 = 0,  /**< \brief Timer 12 */
    ICU_Ccu7_TimerId_t13 = 1   /**< \brief Timer 13 */
} Ccu7_TimerId;

/*==================================================================================================
*                              NOT AUTOSAR FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Channel_Init \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel, \
    P2VAR(Ccu7_Channel_Config, AUTOMATIC, ICU_CODE) pCcu7ChannelConfig \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Channel_DeInit \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Channel_EnIrq \
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    VAR(Ccu7_Edge_Type, AUTOMATIC) edge
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Channel_DisIrq \
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (ICU_STARTTIMESTAMP_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Channel_StartTimestamp \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(Icu_ActivationType,      AUTOMATIC) ActiveEdge
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (ICU_STARTTIMESTAMP_API == STD_ON) */

#if (ICU_STOPTIMESTAMP_API == STD_ON)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Channel_StopTimestamp \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (ICU_STOPTIMESTAMP_API == STD_ON) */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Channel_EnableEdgeDetection \
( \
        VAR(uint8,      AUTOMATIC) u8Module, \
        VAR(uint8,      AUTOMATIC) u8Channel, \
        VAR(Icu_ActivationType,      AUTOMATIC) ActiveEdge
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Channel_DisableEdgeDetection \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Channel_StartSignalMeasurement \
( \
    VAR(uint8,                    AUTOMATIC) u8Module, \
    VAR(uint8,                    AUTOMATIC) u8Channel, \
    VAR(Ccu7_Edge_Type,    AUTOMATIC) eActivation, \
    VAR(uint16,                   AUTOMATIC) nMeasProperty
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_Channel_StopSignalMeasurement \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Ccu7_ProcessInterrupt \
( \
    VAR(Icu_Module_Type,       AUTOMATIC)ModuleId, \
    VAR(Icu_ChannelType,    AUTOMATIC) Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */
#ifdef __cplusplus
}
#endif
#endif /* ICU_Ccu7_HAL_WRAPPER_H */

