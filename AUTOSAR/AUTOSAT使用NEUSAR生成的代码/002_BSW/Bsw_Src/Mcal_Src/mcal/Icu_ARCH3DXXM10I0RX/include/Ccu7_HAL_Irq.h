/* PRQA S 2053,1599 EOF */
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
*   @file    Ccu7_HAL_Irq.h
*   @version
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/

#ifndef Ccu7_HAL_IRQ_H
#define Ccu7_HAL_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif
/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "Std_Types.h"
#include "Icu_Ccu7_LLDrivers.h"
#include "Mcal.h"
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

#define Ccu7_HAL_IRQ_VENDOR_ID_H                   176

#define Ccu7_HAL_IRQ_MAJOR_VER_H                   4
#define Ccu7_HAL_IRQ_MINOR_VER_H                   4
#define Ccu7_HAL_IRQ_REVISION_VER_H                0

#define Ccu7_HAL_IRQ_SW_MAJOR_VER_H                3
#define Ccu7_HAL_IRQ_SW_MINOR_VER_H                0
#define Ccu7_HAL_IRQ_SW_PATCH_VER_H                0

#if (Ccu7_HAL_IRQ_VENDOR_ID_H != STANDARD_VENDOR_ID)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (Ccu7_HAL_IRQ_MAJOR_VER_H != STANDARD_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (Ccu7_HAL_IRQ_MINOR_VER_H != STANDARD_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (Ccu7_HAL_IRQ_REVISION_VER_H != STANDARD_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (Ccu7_HAL_IRQ_SW_MAJOR_VER_H != STANDARD_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (Ccu7_HAL_IRQ_SW_MINOR_VER_H != STANDARD_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (Ccu7_HAL_IRQ_SW_PATCH_VER_H != STANDARD_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define CCU7_CH_0    ((uint8)ICU_CCU70)
#define CCU7_CH_1    ((uint8)ICU_CCU71)
#define CCU7_CH_2    ((uint8)ICU_CCU72)


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
extern ISR(ICU_CCU7_0_ISR);
extern ISR(ICU_CCU7_1_ISR);

#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */
#ifdef __cplusplus
}
#endif
#endif /* Ccu7_HAL_IRQ_H */
