/**************************************************************************** 
* 
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
*   @file    CDD_Ssi_Cfg.c
*   @version 
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CDD_Ssi MCAL driver.
*
*   @addtogroup CDD_Ssi
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "CDD_Ssi_LLDriver.h" /*PRQA S 0380,0704 EOF*/

#define CDD_VENDOR_ID_PLUGIN_CFG_C          176
#define CDD_AR_REL_MAJOR_VER_CFG_C          4
#define CDD_AR_REL_MINOR_VER_CFG_C          4
#define CDD_AR_REL_REVISION_VER_CFG_C       0
#define CDD_SW_MAJOR_VERSION_CFG_C          3
#define CDD_SW_MINOR_VERSION_CFG_C          0
#define CDD_SW_PATCH_VERSION_CFG_C          0

#if (MCAL_VENDOR_ID != CDD_VENDOR_ID_PLUGIN_CFG_C)
    #error " NON-MATCHED DATA : CDD_VENDOR_ID_PLUGIN_CFG_C "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != CDD_AR_REL_MAJOR_VER_CFG_C)
    #error " NON-MATCHED DATA : CDD_AR_REL_MAJOR_VER_CFG_C "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != CDD_AR_REL_MINOR_VER_CFG_C)
    #error " NON-MATCHED DATA : CDD_AR_REL_MINOR_VER_CFG_C "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != CDD_AR_REL_REVISION_VER_CFG_C)
    #error " NON-MATCHED DATA : CDD_AR_REL_REVISION_VER_CFG_C "
#endif
#if (MCAL_SW_MAJOR_VERSION != CDD_SW_MAJOR_VERSION_CFG_C)
    #error " NON-MATCHED DATA : CDD_SW_MAJOR_VERSION_CFG_C "
#endif
#if (MCAL_SW_MINOR_VERSION != CDD_SW_MINOR_VERSION_CFG_C)
    #error " NON-MATCHED DATA : CDD_SW_MINOR_VERSION_CFG_C "
#endif
#if (MCAL_SW_PATCH_VERSION != CDD_SW_PATCH_VERSION_CFG_C)
    #error " NON-MATCHED DATA : CDD_SW_PATCH_VERSION_CFG_C "
#endif

#define SSI_START_SEC_CONFIG_DATA
#include "Ssi_MemMap.h"
CONST(SSI_ConfigType_t, SSI_CONST) SSI_Config;

CONST(SSI_ConfigType_t, SSI_CONST) SSI_Config = 
{
    {
    	SSI0_StPtr,
        {
            .DFS = (uint8)DFS_08_BIT,
            .Format = (uint8)STD_mode,
            .SSI_BaudRatePrescaler = 0x04
        },
        .State = HAL_SSI_STATE_RESET
    },
    .timeout = ssi_timeout
};
#define SSI_STOP_SEC_CONFIG_DATA
#include "Ssi_MemMap.h"


#ifdef __cplusplus
}
#endif

