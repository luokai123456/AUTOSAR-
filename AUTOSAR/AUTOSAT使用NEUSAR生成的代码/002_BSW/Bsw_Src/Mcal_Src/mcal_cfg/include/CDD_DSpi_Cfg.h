/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : DSPI
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/

/**
*   @file    CDD_Dspi_Cfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Dspi MCAL driver.
*
*   @addtogroup Dspi
*   @{
*/

#ifndef CDD_DSpi_CFG_H_
#define CDD_DSpi_CFG_H_

#ifdef __cplusplus
extern "C"{
#endif

#include "StandardTypes.h"
#include "Mcal.h"

#define CDD_DSPI_VENDOR_ID_OUTPUT                       176
#define CDD_DSPI_AR_RELEASE_MAJOR_VERSION_OUTPUT        4
#define CDD_DSPI_AR_RELEASE_MINOR_VERSION_OUTPUT        4
#define CDD_DSPI_AR_RELEASE_REVISION_VERSION_OUTPUT     0
#define CDD_DSPI_SW_MAJOR_VERSION_OUTPUT                3
#define CDD_DSPI_SW_MINOR_VERSION_OUTPUT                0
#define CDD_DSPI_SW_PATCH_VERSION_OUTPUT                0

#if (CDD_DSPI_VENDOR_ID_OUTPUT != MCAL_VENDOR_ID)
#error "NON-MATCHED DATA : CDD_DSPI_VENDOR_ID_OUTPUT"
#endif

/* Check if current file and SPI header file are of the same Autosar version */
#if (CDD_DSPI_AR_RELEASE_MAJOR_VERSION_OUTPUT != MCAL_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : CDD_DSPI_AR_RELEASE_MAJOR_VERSION_OUTPUT"
#endif
#if (CDD_DSPI_AR_RELEASE_MINOR_VERSION_OUTPUT != MCAL_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : CDD_DSPI_AR_RELEASE_MINOR_VERSION_OUTPUT"
#endif
#if (CDD_DSPI_AR_RELEASE_REVISION_VERSION_OUTPUT != MCAL_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : CDD_DSPI_AR_RELEASE_REVISION_VERSION_OUTPUT"
#endif

/* Check if current file and SPI header file are of the same Software version */
#if (CDD_DSPI_SW_MAJOR_VERSION_OUTPUT != MCAL_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : CDD_DSPI_SW_MAJOR_VERSION_OUTPUT"
#endif
#if (CDD_DSPI_SW_MINOR_VERSION_OUTPUT != MCAL_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : CDD_DSPI_SW_MINOR_VERSION_OUTPUT"
#endif
#if (CDD_DSPI_SW_PATCH_VERSION_OUTPUT != MCAL_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : CDD_DSPI_SW_PATCH_VERSION_OUTPUT"
#endif

#define CDD_DSPI_PRECOMPILE_SUPPORT    (STD_OFF)
#define CDD_DSPI_DEV_ERROR_DETECT    (STD_ON)
#ifdef RESOURCE_SUPPORT_GTM_TO_MSC
#define CDD_DSPI_GTM_MSC_ENABLE    (STD_OFF)
#define CDD_DSPI_GTM_MSC_SET_COUNT    0U
#endif /* RESORUCE_SUPPORT_GTM410 */

#define CDD_DSPI_CONTROLLER_COUNT    22U
#define CDD_DSpiDriver_0    0U
#define CDD_DSpiDriver_1    1U
#define CDD_DSpiDriver_2    2U
#define CDD_DSpiDriver_3    3U
#define CDD_DSpiDriver_4    4U
#define CDD_DSpiDriver_5    5U
#define CDD_DSpiDriver_7    6U
#define CDD_DSpiDriver_8    7U
#define CDD_DSpiDriver_9    8U
#define CDD_DSpiDriver_10    9U
#define CDD_DSpiDriver_11    10U
#define CDD_DSpiDriver_12    11U
#define CDD_DSpiDriver_13    12U
#define CDD_DSpiDriver_14    13U
#define CDD_DSpiDriver_15    14U
#define CDD_DSpiDriver_16    15U
#define CDD_DSpiDriver_17    16U
#define CDD_DSpiDriver_18    17U
#define CDD_DSpiDriver_19    18U
#define CDD_DSpiDriver_20    19U
#define CDD_DSpiDriver_21    20U
#define CDD_DSpiDriver_22    21U

#define CDD_DSPI_PB_CONFIG_DECLARATION   extern CONST(CDD_DSpi_ConfigType, DSPI_VAR) CDD_DSpi_Config;

#define DSPI_INLINE    LOCAL_INLINE

#ifdef __cplusplus
}
#endif

#endif /* CDD_DSpi_CFG_H_ */
