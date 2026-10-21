/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : EMIOS
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
*   @file    eMIOS_Cfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of eMIOS MCAL driver.
*
*   @addtogroup eMIOS
*   @{
*/


#ifndef EMIOS_CFG_H_
#define EMIOS_CFG_H_

#include "Mcal.h"

#define EMIOS_VENDOR_ID                       176
#define EMIOS_MODULE_ID                       250
#define EMIOS_AR_REL_MAJOR_VER                4
#define EMIOS_AR_REL_MINOR_VER                4
#define EMIOS_AR_REL_REV_VER                  0
#define EMIOS_SW_MAJOR_VER                    3
#define EMIOS_SW_MINOR_VER                    0
#define EMIOS_SW_PATCH_VER                    0

/*============================================FILE VERSION CHECKS===================================*/

#if (EMIOS_VENDOR_ID != MCAL_VENDOR_ID)
#error "NON-MATCHED DATA : MCAL_VENDOR_ID"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#if (EMIOS_AR_REL_MAJOR_VER != MCAL_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : EMIOS_AR_REL_MAJOR_VER"
#endif
#if (EMIOS_AR_REL_MINOR_VER != MCAL_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : EMIOS_AR_REL_MINOR_VER"
#endif
#if (EMIOS_AR_REL_REV_VER != MCAL_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : EMIOS_AR_REL_REV_VER"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (EMIOS_SW_MAJOR_VER != MCAL_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : EMIOS_SW_MAJOR_VER"
#endif
#if (EMIOS_SW_MINOR_VER != MCAL_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : EMIOS_SW_MINOR_VER"
#endif
#if (EMIOS_SW_PATCH_VER != MCAL_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : EMIOS_SW_PATCH_VER"
#endif


#define EMIOS_PRECOMPILE_SUPPORT     (STD_OFF)

#define EMIOS_DEV_ERROR_DETECT     (STD_ON)

#define EMIOS_INSTANCE_NUM  1U

#endif /* EMIOS_CFG_H_ */
