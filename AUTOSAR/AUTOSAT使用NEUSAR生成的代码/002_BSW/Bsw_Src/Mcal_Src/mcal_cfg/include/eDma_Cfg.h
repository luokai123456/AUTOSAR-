/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : edma
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    eDma_Cfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of eDma MCAL driver.
*
*   @addtogroup eDma
*   @{
*/

#ifndef EDMA_CFG_H_
#define EDMA_CFG_H_

#ifdef __cplusplus
extern "C"{
#endif

#include "Mcal.h"

#define EDMA_CFG_H_VENDOR_ID                     176
#define EDMA_CFG_H_AR_REL_MAJOR_VER              4
#define EDMA_CFG_H_AR_REL_MINOR_VER              4
#define EDMA_CFG_H_AR_REL_REV_VER                0
#define EDMA_CFG_H_SW_MAJOR_VER                  3
#define EDMA_CFG_H_SW_MINOR_VER                  0
#define EDMA_CFG_H_SW_PATCH_VER                  0

#if (MCAL_VENDOR_ID != EDMA_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : EDMA_CFG_H_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != EDMA_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : EDMA_CFG_H_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != EDMA_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : EDMA_CFG_H_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != EDMA_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : EDMA_CFG_H_AR_REL_REV_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != EDMA_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : EDMA_CFG_H_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != EDMA_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : EDMA_CFG_H_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != EDMA_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : EDMA_CFG_H_SW_PATCH_VER "
#endif

#define EDMA_PRECOMPILE_SUPPORT    (STD_OFF)

/*! @brief The total number of configured channels */
#define EDMA_CONFIG_CHANNELS_COUNT    70U

#define EDMA_DEV_ERROR_DETECT    (STD_OFF)

#define EDMA_VERSION_INFO_API    (STD_OFF)

#define EDMA_INLINE    LOCAL_INLINE

/*! @brief Configuration declaration */
#define EDMA_PB_CONFIG_DECLARATION extern CONST(EDma_ConfigType, EDMA_VAR) EDma_Config;

#ifdef __cplusplus
}
#endif

#endif /* EDMA_CFG_H_ */
