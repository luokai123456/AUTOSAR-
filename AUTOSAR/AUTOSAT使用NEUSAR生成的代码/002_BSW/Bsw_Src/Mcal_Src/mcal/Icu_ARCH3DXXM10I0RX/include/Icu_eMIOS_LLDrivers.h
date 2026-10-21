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
*   @file    Icu_eMIOS_LLDrivers.h
*   @version 3.0.0 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/

#ifndef ICU_EMIOS_LLDrivers_H
#define ICU_EMIOS_LLDrivers_H

#ifdef __cplusplus
extern "C"
{
#endif

/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "eMIOS_LLDriver.h"
#include "Icu_Cfg.h"
/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_EMIOS_LLDRIVERS_VENDOR_ID_H                   176

#define ICU_EMIOS_LLDRIVERS_MAJOR_VER_H                   4
#define ICU_EMIOS_LLDRIVERS_MINOR_VER_H                   4
#define ICU_EMIOS_LLDRIVERS_REVISION_VER_H                0

#define ICU_EMIOS_LLDRIVERS_SW_MAJOR_VER_H                3
#define ICU_EMIOS_LLDRIVERS_SW_MINOR_VER_H                0
#define ICU_EMIOS_LLDRIVERS_SW_PATCH_VER_H                0

#if (ICU_EMIOS_LLDRIVERS_VENDOR_ID_H != ICU_VENDOR_ID_CFG)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_EMIOS_LLDRIVERS_MAJOR_VER_H != ICU_AR_RELEASE_MAJOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_EMIOS_LLDRIVERS_MINOR_VER_H != ICU_AR_RELEASE_MINOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_EMIOS_LLDRIVERS_REVISION_VER_H != ICU_AR_RELEASE_REVISION_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_EMIOS_LLDRIVERS_SW_MAJOR_VER_H != ICU_SW_MAJOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_EMIOS_LLDRIVERS_SW_MINOR_VER_H != ICU_SW_MINOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_EMIOS_LLDRIVERS_SW_PATCH_VER_H != ICU_SW_PATCH_VERSION_CFG)
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
typedef enum
{
    EMIOS_UC_MODE_SAIC_TRIGGER_EDGE_FALLING          = 0x00U,              /* Falling edge trigger */
    EMIOS_UC_MODE_SAIC_EDGE_RISING_TRIGGER           = 0x01U,              /* Rising edge trigger */
    EMIOS_UC_MODE_SAIC_EDGE_ANY_TRIGGER              = 0x02U,              /* Rising and falling edge trigger */

    EMIOS_UC_MODE_IPM_EDGE_RISING                    = 0x03U,              /* Period measurement between two consecutive rising edges */
    EMIOS_UC_MODE_IPM_EDGE_FALLING                   = 0x04U,              /* Period measurement between two consecutive falling edges */

    EMIOS_UC_MODE_IPWM_PERIOD_ON                     = 0x05U,              /* The time measurement taken for the pulse to remain ON or HIGH state */
    EMIOS_UC_MODE_IPWM_PERIOD_OFF                    = 0x06U,              /* The time measurement taken for the pulse to remain OFF or LOW state */

    EMIOS_UC_MODE_PEA_CONTIN_EDGE_RISING             = 0x07U,
    EMIOS_UC_MODE_PEA_CONTIN_EDGE_FALLING            = 0x08U,
    EMIOS_UC_MODE_PEA_CONTIN_EDGE_ANY                = 0x09U,

    EMIOS_UC_MODE_PEA_SINGLE_EDGE_RISING             = 0x10U,
    EMIOS_UC_MODE_PEA_SINGLE_EDGE_FALLING            = 0x11U,
    EMIOS_UC_MODE_PEA_SINGLE_EDGE_ANY                = 0x12U,

    EMIOS_UC_MODE_PEC_CONTIN_EDGE_RISING             = 0x13U,
    EMIOS_UC_MODE_PEC_CONTIN_EDGE_FALLING            = 0x14U,
    EMIOS_UC_MODE_PEC_CONTIN_EDGE_ANY                = 0x15U,

    EMIOS_UC_MODE_PEC_SINGLE_EDGE_RISING             = 0x16U,
    EMIOS_UC_MODE_PEC_SINGLE_EDGE_FALLING            = 0x17U,
    EMIOS_UC_MODE_PEC_SINGLE_EDGE_ANY                = 0x18U,

    EMIOS_UC_MODE_QDEC_FOR_COUNT_DIRECT_EDGE_RISING  = 0x19U,
    EMIOS_UC_MODE_QDEC_EDGE_FALLING_FOR_COUNT_DIRECT = 0x20U,

    EMIOS_UC_MODE_QDEC_FOR_PHASE_A_B_DIRECT_POSITIVE = 0x21U,
    EMIOS_UC_MODE_QDEC_NEGATIVE_FOR_PHASE_A_B_DIRECT = 0x22U,

    EMIOS_UC_MODE_WPTA_PERIOD_ON                     = 0x23U,
    EMIOS_UC_MODE_WPTA_PERIOD_OFF                    = 0x24U,

    EMIOS_UC_MODE_GPIO_EDGE_RISING                   = 0x25U,
    EMIOS_UC_MODE_GPIO_EDGE_FALLING                  = 0x26U,
} eMIOS_IC_ModeType;

typedef struct
{
    VAR(eMIOS_IC_ModeType,          ICU_VAR) mode;
    VAR(eMIOS_UC_CounterBusSelType, ICU_VAR) timebase;
    VAR(eMIOS_UC_InputFilterType,   ICU_VAR) filter;
    VAR(uint32,                     ICU_VAR) desirednum;
    VAR(uint32,                     ICU_VAR) startime;
    VAR(uint32,                     ICU_VAR) endtime;
    VAR(uint8,                      ICU_VAR) ucPrescaler;
} eMIOS_IC_ParamType;

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) eMIOS_LLD_IC_Init
( \
    CONST(uint8, ICU_VAR) emiosIndex, \
    CONST(uint8, ICU_VAR) ChanNum, \
    CONST(eMIOS_IC_ParamType, ICU_VAR) *ParamPtr \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) eMIOS_LLD_IC_GetLastMeasurement
(
    CONST(uint8, ICU_VAR) emiosIndex, \
    CONST(uint8, ICU_VAR) ChanNum, \
    VAR(uint32,  ICU_VAR) *value \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) eMIOS_LLD_IC_PEA_SingleTrigger
( \
    CONST(uint8, ICU_VAR) emiosIndex, \
    CONST(uint8, ICU_VAR) ChanNum, \
    VAR(uint32,  ICU_VAR) count \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) eMIOS_LLD_IC_PEC_SingleTrigger
( \
    CONST(uint8, ICU_VAR) emiosIndex, \
    CONST(uint8, ICU_VAR) ChanNum, \
    VAR(uint32,  ICU_VAR) endtime, \
    VAR(uint32,  ICU_VAR) starttime \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* ICU_EMIOS_LLDrivers_H */

