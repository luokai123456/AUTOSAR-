/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     SDAdc_Cfg.h
* @version  3.0.0
* @date     2024 - 03 - 06
* @brief    Initial version.
*
*****************************************************************************/
/* PRQA S 1753,1594 EOF*/
#ifndef SDADC_CFG_H
#define SDADC_CFG_H

#include "Compiler.h"
#include "Std_Types.h"
#include "eDma_LLDriver.h"
#include "Mcal.h"
#ifdef RESOURCE_SUPPORT_SDADC_IP
#define SDADC_CFG_H_VENDOR_ID                       176
#define SDADC_MODULE_ID                             252
#define SDADC_CFG_H_AR_REL_MAJOR_VER                4
#define SDADC_CFG_H_AR_REL_MINOR_VER                4
#define SDADC_CFG_H_AR_REL_REV_VER                  0
#define SDADC_CFG_H_SW_MAJOR_VER                    3
#define SDADC_CFG_H_SW_MINOR_VER                    0
#define SDADC_CFG_H_SW_PATCH_VER                    0

#if (MCAL_VENDOR_ID               != SDADC_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : SDADC_CFG_H_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION    != SDADC_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : SDADC_CFG_H_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION    != SDADC_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : SDADC_CFG_H_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != SDADC_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : SDADC_CFG_H_AR_REL_REV_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION        != SDADC_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : SDADC_CFG_H_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION        != SDADC_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : SDADC_CFG_H_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION        != SDADC_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : SDADC_CFG_H_SW_PATCH_VER "
#endif

#define SDADC_PRECOMPILE_SUPPORT     (STD_OFF)

#define SDADC_DEV_ERROR_DETECT     (STD_ON)
#define SDADC_ENABLE_MULTICORE     (STD_OFF)
/*The inline status*/
#define SDADC_INLINE     LOCAL_INLINE
#define SDADC_DEFAULT_COREID 0U

#define SDADC_INSTANCE_CDG_NUM 2U
#define SDADC_CFG_CHANNEL_ID_0   0U
#define SDADC_CFG_CHANNEL_ID_1   1U

#endif /*RESOURCE_SUPPORT_SDADC_IP*/

#endif /* SDADC_CFG_H */

/** @} */
