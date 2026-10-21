/*PRQA S 0380,2053,1258 EOF*/
/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : Wdg
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
*   @file    Wdg_CfgExt.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Wdg MCAL driver.
*
*   @addtogroup Wdg
*   @{
*/
/*PRQA S 0380 EOF */    /* QAC_CWE */
#ifdef __cplusplus
extern "C"{
#endif
#include "Wdg_Module.h"
#include "Wdg_Cfg.h"
#define WDG_CFGEXT_C_VENDOR_ID                   176
#define WDG_CFGEXT_C_VER_MAJOR                  4
#define WDG_CFGEXT_C_VER_MINOR                  4
#define WDG_CFGEXT_C_VER_REVISION               0
#define WDG_CFGEXT_C_SW_VER_MAJOR               3
#define WDG_CFGEXT_C_SW_VER_MINOR               0
#define WDG_CFGEXT_C_SW_VER_PATCH               0
#if (WDG_CFGEXT_C_VENDOR_ID != WDG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : WDG_CFGEXT_C_VENDOR_ID "
#endif
#if (WDG_CFGEXT_C_VER_MAJOR != WDG_AR_RELEASE_MAJOR_VERSION)
    #error " NON-MATCHED DATA : WDG_CFGEXT_C_VER_MAJOR "
#endif
#if (WDG_CFGEXT_C_VER_MINOR != WDG_AR_RELEASE_MINOR_VERSION)
    #error " NON-MATCHED DATA : WDG_CFGEXT_C_VER_MINOR "
#endif
#if (WDG_CFGEXT_C_VER_REVISION != WDG_H_REVISION_VERSION)
    #error " NON-MATCHED DATA : WDG_CFGEXT_C_VER_REVISION "
#endif
#if (WDG_CFGEXT_C_SW_VER_MAJOR != WDG_H_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : WDG_CFGEXT_C_SW_VER_MAJOR "
#endif
#if (WDG_CFGEXT_C_SW_VER_MINOR != WDG_H_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : WDG_CFGEXT_C_SW_VER_MINOR "
#endif
#if (WDG_CFGEXT_C_SW_VER_PATCH != WDG_H_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : WDG_CFGEXT_C_SW_VER_PATCH "
#endif
#define WDG_START_SEC_CONFIG_DATA
#include "Wdg_MemMap.h"
CONST(Mcal_DemErrorType, WDG_CONST) Wdg_E_Disable_Rejected = 
{

    STD_OFF,


    1U

};
#define WDG_STOP_SEC_CONFIG_DATA
#include "Wdg_MemMap.h"   

#define WDG_START_SEC_CONFIG_DATA
#include "Wdg_MemMap.h"
CONST(Mcal_DemErrorType, WDG_CONST) Wdg_E_Mode_Failed = 
{

    STD_OFF,


    2U

};
#define WDG_STOP_SEC_CONFIG_DATA
#include "Wdg_MemMap.h" 

#ifdef __cplusplus
}
#endif

