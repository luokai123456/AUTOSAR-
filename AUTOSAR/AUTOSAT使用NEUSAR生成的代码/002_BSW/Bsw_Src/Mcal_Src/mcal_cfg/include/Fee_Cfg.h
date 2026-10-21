/**************************************************************************** 
* 

* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
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
*   @file    Fee_cfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of FEE MCAL driver.
*
*   @addtogroup FEE
*   @{
*/

#ifndef FEE_CFG_H
#define FEE_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Fee_Types.h"

#define FEE_VENDOR_ID_OUTPUT                      176
#define FEE_MODULE_ID_OUTPUT                      92
#define FEE_AR_REL_MAJOR_VER_OUTPUT               4
#define FEE_AR_REL_MINOR_VER_OUTPUT               4
#define FEE_AR_REL_REVISION_VER_OUTPUT            0
#define FEE_SW_MAJOR_VERSION_OUTPUT               3
#define FEE_SW_MINOR_VERSION_OUTPUT               0
#define FEE_SW_PATCH_VERSION_OUTPUT               0

#if (MCAL_VENDOR_ID != FEE_VENDOR_ID_OUTPUT)
    #error " NON-MATCHED DATA : FEE_VENDOR_ID_OUTPUT "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != FEE_AR_REL_MAJOR_VER_OUTPUT)
    #error " NON-MATCHED DATA : FEE_AR_REL_MAJOR_VER_OUTPUT "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != FEE_AR_REL_MINOR_VER_OUTPUT)
    #error " NON-MATCHED DATA : FEE_AR_REL_MINOR_VER_OUTPUT "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != FEE_AR_REL_REVISION_VER_OUTPUT)
    #error " NON-MATCHED DATA : FEE_AR_REL_REVISION_VER_OUTPUT "
#endif
#if (MCAL_SW_MAJOR_VERSION != FEE_SW_MAJOR_VERSION_OUTPUT)
    #error " NON-MATCHED DATA : FEE_SW_MAJOR_VERSION_OUTPUT "
#endif
#if (MCAL_SW_MINOR_VERSION != FEE_SW_MINOR_VERSION_OUTPUT)
    #error " NON-MATCHED DATA : FEE_SW_MINOR_VERSION_OUTPUT "
#endif
#if (MCAL_SW_PATCH_VERSION != FEE_SW_PATCH_VERSION_OUTPUT)
    #error " NON-MATCHED DATA : FEE_SW_PATCH_VERSION_OUTPUT "
#endif

#define FEE_PRECOMPILE_SUPPORT        (STD_OFF)

#define FEE_DEV_ERROR_DETECT        (STD_ON)

#define FEE_SETMODE_API_SUPPORTED        (STD_ON)

#define FEE_VERSION_INFO_API        (STD_ON)

#define FEE_INLINE     LOCAL_INLINE
#define FEE_CANCEL_API        (STD_ON)

#define FEE_VIRTUAL_PAGE_SIZE    (32U)

#define FEE_BLOCK_ALWAYS_AVAILABLE        (STD_OFF)

#define FEE_LEGACY_MODE        (STD_OFF)

#define FEE_LEGACY_IMM_ERASE_MODE        (STD_OFF)

#define FEE_SWAP_FOREIGN_BLOCKS_ENABLED        (STD_OFF)

#define FEE_MARK_EMPTY_BLOCKS_INVALID        (STD_ON)

#define FEE_BOOTLOADER_CONFIG        (STD_OFF)

#define FEE_NVM_JOB_END_NOTIFICATION_DECL    
#define FEE_NVM_JOB_END_NOTIFICATION    
#define FEE_NVM_JOB_ERROR_NOTIFICATION_DECL    
#define FEE_NVM_JOB_ERROR_NOTIFICATION    
#define FEE_NVM_CLUSTER_FORMAT_NOTIFICATION_DECL    
#define FEE_NVM_CLUSTER_FORMAT_NOTIFICATION    
#define FEE_NUMBER_OF_CLUSTER_GROUPS          2U

#define FEE_NUMBER_OF_BLOCKS                  2U

#define FEE_MAX_NR_OF_BLOCKS        (FEE_NUMBER_OF_BLOCKS)
#define FEE_BLOCK_OVERHEAD                    (96U)

#define FEE_CLUSTER_OVERHEAD                  (96U)

#define FEE_DATA_BUFFER_SIZE                  (128U)

#define FEE_ERASED_VALUE                      (0xffU)

#define FEE_VALIDATED_VALUE                   (0x81U)

#define FEE_INVALIDATED_VALUE                 (0x18U)

#define FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_0     1U
#define FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_1     2U

#define FeeConf_FeeBlockConfiguration_0       (1U)
#define FeeConf_FeeBlockConfiguration_1       (2U)

typedef struct 
{
    P2CONST( Fee_ClusterGroup_Type, FEE_CONST, FEE_APPL_CONST ) Fee_ClusterGroup;
    P2CONST( Fee_BlockConfig_Type, FEE_CONST, FEE_APPL_CONST ) Fee_BlockConfig;     /* PRQA S 1759 EOF*/ 
} Fee_ConfigType;

extern CONST(Fee_ConfigType, FEE_CONST) Fee_Config;

#ifdef __cplusplus
}
#endif

#endif /* FEE_CFG_H */

