/**************************************************************************** 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : SSI
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
*   @file    CDD_Ssi_Cfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CDD_Ssi MCAL driver.
*
*   @addtogroup CDD_Ssi
*   @{
*/


#ifndef CDD_SSI_CFG_H_
#define CDD_SSI_CFG_H_


#include "Compiler.h"
#include "StandardTypes.h"
#include "Mcal.h"

#define CDD_VENDOR_ID_OUTPUT                      176
#define CDD_MODULE_ID_OUTPUT                      251
#define CDD_AR_REL_MAJOR_VER_OUTPUT               4
#define CDD_AR_REL_MINOR_VER_OUTPUT               4
#define CDD_AR_REL_REVISION_VER_OUTPUT            0
#define CDD_SW_MAJOR_VERSION_OUTPUT               3
#define CDD_SW_MINOR_VERSION_OUTPUT               0
#define CDD_SW_PATCH_VERSION_OUTPUT               0

#if (MCAL_VENDOR_ID != CDD_VENDOR_ID_OUTPUT)
    #error " NON-MATCHED DATA : CDD_VENDOR_ID_OUTPUT "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != CDD_AR_REL_MAJOR_VER_OUTPUT)
    #error " NON-MATCHED DATA : CDD_AR_REL_MAJOR_VER_OUTPUT "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != CDD_AR_REL_MINOR_VER_OUTPUT)
    #error " NON-MATCHED DATA : CDD_AR_REL_MINOR_VER_OUTPUT "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != CDD_AR_REL_REVISION_VER_OUTPUT)
    #error " NON-MATCHED DATA : CDD_AR_REL_REVISION_VER_OUTPUT "
#endif
#if (MCAL_SW_MAJOR_VERSION != CDD_SW_MAJOR_VERSION_OUTPUT)
    #error " NON-MATCHED DATA : CDD_SW_MAJOR_VERSION_OUTPUT "
#endif
#if (MCAL_SW_MINOR_VERSION != CDD_SW_MINOR_VERSION_OUTPUT)
    #error " NON-MATCHED DATA : CDD_SW_MINOR_VERSION_OUTPUT "
#endif
#if (MCAL_SW_PATCH_VERSION != CDD_SW_PATCH_VERSION_OUTPUT)
    #error " NON-MATCHED DATA : CDD_SW_PATCH_VERSION_OUTPUT "
#endif

#define SSI_PRECOMPILE_SUPPORT        (STD_OFF)

#endif /* CDD_SSI_CFG_H_ */
