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
*   Autosar Revision     :-
*   Autosar Conf.Variant :-
*   SW Version           :-
*   Build Version        :-
*   *****************************************************************************/
/**
*   @file    Wdg_176_ModId2.h
*   @version 3.0.0
*
*   @addtogroup Wdg
*   @{
*/
#ifndef WDG_176_MODID2_H
#define WDG_176_MODID2_H
#ifdef __cplusplus
extern "C"{
#endif

#include "Wdg_Module.h"
#if (defined(RESOURCE_SUPPORT_SWT2))
#define WDG_176_MOD2_H_VENDOR_ID                   176
#define WDG_176_MOD2_H_VER_MAJOR                  4
#define WDG_176_MOD2_H_VER_MINOR                  4
#define WDG_176_MOD2_H_VER_REVISION               0
#define WDG_176_MOD2_H_SW_VER_MAJOR               3
#define WDG_176_MOD2_H_SW_VER_MINOR               0
#define WDG_176_MOD2_H_SW_VER_PATCH               0
#if (WDG_176_MOD2_H_VENDOR_ID != WDG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : WDG_176_MOD2_H_VENDOR_ID "
#endif
#if (WDG_176_MOD2_H_VER_MAJOR != WDG_AR_RELEASE_MAJOR_VERSION)
    #error " NON-MATCHED DATA : WDG_176_MOD2_H_VER_MAJOR "
#endif
#if (WDG_176_MOD2_H_VER_MINOR != WDG_AR_RELEASE_MINOR_VERSION)
    #error " NON-MATCHED DATA : WDG_176_MOD2_H_VER_MINOR "
#endif
#if (WDG_176_MOD2_H_VER_REVISION != WDG_H_REVISION_VERSION)
    #error " NON-MATCHED DATA : WDG_176_MOD2_H_VER_REVISION "
#endif
#if (WDG_176_MOD2_H_SW_VER_MAJOR != WDG_H_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : WDG_176_MOD2_H_SW_VER_MAJOR "
#endif
#if (WDG_176_MOD2_H_SW_VER_MINOR != WDG_H_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : WDG_176_MOD2_H_SW_VER_MINOR "
#endif
#if (WDG_176_MOD2_H_SW_VER_PATCH != WDG_H_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : WDG_176_MOD2_H_SW_VER_PATCH "
#endif
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(void, WDG_CODE) Wdg_176_ModId2_Init \
( \
    P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr \
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
FUNC(Std_ReturnType, WDG_CODE) Wdg_176_ModId2_SetMode(VAR(WdgIf_ModeType,AUTOMATIC) Mode);
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
FUNC(void, WDG_CODE) Wdg_176_ModId2_SetTriggerCondition(VAR(uint16,AUTOMATIC) timeout);

#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
#if(WDG_VERSION_INFO_API==STD_ON)
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(void, WDG_CODE) Wdg_176_ModId2_GetVersionInfo \
( \
    P2VAR(Std_VersionInfoType, AUTOMATIC, WDG_APPL_DATA) Versioninfo \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
#endif
#endif /* RESOURCE_SUPPORT_SWT2 */

#ifdef __cplusplus
}
#endif
/** @} */
#endif
