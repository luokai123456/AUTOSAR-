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
*   @file    Icu_eMIOS_Types.h
*   @version 3.0.0 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
#ifndef ICU_EMIOS_TYPES_H
#define ICU_EMIOS_TYPES_H

/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/

#include "Icu_Cfg.h"
/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
===================================================================================================*/

/*==================================================================================================
                                        FILE VERSION CHECKS
===================================================================================================*/
#define ICU_EMIOS_TYPES_VENDOR_ID_H                   176

#define ICU_EMIOS_TYPES_MAJOR_VER_H                   4
#define ICU_EMIOS_TYPES_MINOR_VER_H                   4
#define ICU_EMIOS_TYPES_REVISION_VER_H                0

#define ICU_EMIOS_TYPES_SW_MAJOR_VER_H                3
#define ICU_EMIOS_TYPES_SW_MINOR_VER_H                0
#define ICU_EMIOS_TYPES_SW_PATCH_VER_H                0

#if (ICU_EMIOS_TYPES_VENDOR_ID_H != ICU_VENDOR_ID_CFG)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_EMIOS_TYPES_MAJOR_VER_H != ICU_AR_RELEASE_MAJOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_EMIOS_TYPES_MINOR_VER_H != ICU_AR_RELEASE_MINOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_EMIOS_TYPES_REVISION_VER_H != ICU_AR_RELEASE_REVISION_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_EMIOS_TYPES_SW_MAJOR_VER_H != ICU_SW_MAJOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_EMIOS_TYPES_SW_MINOR_VER_H != ICU_SW_MINOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_EMIOS_TYPES_SW_PATCH_VER_H != ICU_SW_PATCH_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#if (ICU_STARTSIGNALMEASUREMENT_API == STD_ON)
#define ICU_SIGNAL_MEASUREMENT_API          (STD_ON)
#endif
#ifndef ICU_ENABLEEDGECOUNT_API
#define ICU_EDGE_COUNT_API                  (STD_ON)
#endif

#if (ICU_STARTTIMESTAMP_API == STD_ON)
#define ICU_TIMESTAMP_API                   (STD_ON)
#endif
/*
#ifndef ICU_DUAL_CLOCK_MODE_API
#define ICU_DUAL_CLOCK_MODE_API             (STD_ON)
#endif

#define ICU_EMIOS_MODULE_INIT               (STD_OFF)
*/
#define EMIOS_CHANNEL_MAX                   (64U)

#if (defined(RESOURCE_SUPPORT_EMIOS0) && defined(RESOURCE_SUPPORT_EMIOS1))
#define EMIOS_MODULE_MAX                    (2U)
#else
#define EMIOS_MODULE_MAX                    (1U)
#endif

#define ICU_MEASUREMENT_USES_SAIC_MODE

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


#endif

