/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*/
/*==================================================================================================
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
==================================================================================================*/
/**
*   @file    Wdg_HAL_Wrapper.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Wdg MCAL driver.
*
*   @addtogroup Wdg
*   @{
*/
#ifndef Wdg_HAL_WRAPPER_H
#define Wdg_HAL_WRAPPER_H

#ifdef __cplusplus
extern "C"{
#endif
/*=======================================INCLUDE FILES=====================================s======*/
#include "Wdg_Cfg.h"
#include "Wdg_LLDriver.h"
#include "Mcal.h"
#include "Wdg_Module.h"
/*============================= SOURCE FILE VERSION INFORMATION====================================*/
#define Wdg_HAL_WRA_H_VENDOR_ID                      176
#define Wdg_HAL_WRA_H_VERSION_MAJOR                  4
#define Wdg_HAL_WRA_H_VERSION_MINOR                  4
#define Wdg_HAL_WRA_H_VERSION_REVISION               0
#define Wdg_HAL_WRA_H_SW_VERSION_MAJOR               3
#define Wdg_HAL_WRA_H_SW_VERSION_MINOR               0
#define Wdg_HAL_WRA_H_SW_VERSION_PATCH               0

/*===================================  FILE VERSION CHECKS=======================================*/
#if (Wdg_HAL_WRA_H_VENDOR_ID != WDG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : Wdg_HAL_WRA_H_VENDOR_ID "
#endif
#if (Wdg_HAL_WRA_H_VERSION_MAJOR != WDG_AR_RELEASE_MAJOR_VERSION)
    #error " NON-MATCHED DATA : Wdg_HAL_WRA_H_VERSION_MAJOR "
#endif
#if (Wdg_HAL_WRA_H_VERSION_MINOR != WDG_AR_RELEASE_MINOR_VERSION)
    #error " NON-MATCHED DATA : Wdg_HAL_WRA_H_VERSION_MINOR "
#endif
#if (Wdg_HAL_WRA_H_VERSION_REVISION != WDG_H_REVISION_VERSION)
    #error " NON-MATCHED DATA : Wdg_HAL_WRA_H_VERSION_REVISION "
#endif
#if (Wdg_HAL_WRA_H_SW_VERSION_MAJOR != WDG_H_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : Wdg_HAL_WRA_H_SW_VERSION_MAJOR "
#endif
#if (Wdg_HAL_WRA_H_SW_VERSION_MINOR != WDG_H_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : Wdg_HAL_WRA_H_SW_VERSION_MINOR "
#endif
#if (Wdg_HAL_WRA_H_SW_VERSION_PATCH != WDG_H_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : Wdg_HAL_WRA_H_SW_VERSION_PATCH "
#endif
#if (Wdg_HAL_WRA_H_VENDOR_ID != WDG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : Wdg_HAL_WRA_H_VENDOR_ID "
#endif
#if (Wdg_HAL_WRA_H_VERSION_MAJOR != WDG_AR_RELEASE_MAJOR_VERSION)
    #error " NON-MATCHED DATA : Wdg_HAL_WRA_H_VERSION_MAJOR "
#endif
#if (Wdg_HAL_WRA_H_VERSION_MINOR != WDG_AR_RELEASE_MINOR_VERSION)
    #error " NON-MATCHED DATA : Wdg_HAL_WRA_H_VERSION_MINOR "
#endif
#if (Wdg_HAL_WRA_H_VERSION_REVISION != WDG_H_REVISION_VERSION)
    #error " NON-MATCHED DATA : Wdg_HAL_WRA_H_VERSION_REVISION "
#endif
#if (Wdg_HAL_WRA_H_SW_VERSION_MAJOR != WDG_H_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : Wdg_HAL_WRA_H_SW_VERSION_MAJOR "
#endif
#if (Wdg_HAL_WRA_H_SW_VERSION_MINOR != WDG_H_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : Wdg_HAL_WRA_H_SW_VERSION_MINOR "
#endif
#if (Wdg_HAL_WRA_H_SW_VERSION_PATCH != WDG_H_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : Wdg_HAL_WRA_H_SW_VERSION_PATCH "
#endif

/*=================================== FUNCTION PROTOTYPES=========================================*/


#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(uint32, WDG_CODE) Wdg_HAL_WRA_Init \
( \
    P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) pConfigPtr \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(uint32, WDG_CODE) Wdg_HAL_WRA_SetMode \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
	VAR(WdgIf_ModeType, WDG_VAR) Mode  \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(void, WDG_CODE) Wdg_HAL_WRA_Trigger(VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /*REG_E_SYS_SWT_DEFINES_H*/

/** @} */
