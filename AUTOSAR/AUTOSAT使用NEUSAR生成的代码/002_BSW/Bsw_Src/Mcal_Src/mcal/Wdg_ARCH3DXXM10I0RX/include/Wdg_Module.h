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
*   @file    Wdg_Module.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Wdg MCAL driver.
*
*   @addtogroup Wdg
*   @{
*/
/*PRQA S 3332,1536,1752 EOF*/
#ifndef Wdg_Module_H
#define Wdg_Module_H


#ifdef __cplusplus
extern "C"{
#endif


#include "Wdg_LLDriver.h"
#include "Wdg_cfg.h"
/*====================================== INCLUDE FILES==============================================*/



/*=============================SOURCE FILE VERSION INFORMATION====================================*/
#define WDG_H_VENDOR_ID                    176
#define WDG_H_MODULE_ID                    102
#define WDG_AR_RELEASE_MAJOR_VERSION       4
#define WDG_AR_RELEASE_MINOR_VERSION       4
#define WDG_H_REVISION_VERSION             0
#define WDG_H_SW_MAJOR_VERSION             3
#define WDG_H_SW_MINOR_VERSION             0
#define WDG_H_SW_PATCH_VERSION             0

/*===================================FILE VERSION CHECKS=======================================*/
#if (WDG_H_VENDOR_ID != WDG_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : WDG_H_VENDOR_ID "
#endif
#if (WDG_AR_RELEASE_MAJOR_VERSION != WDG_CFG_H_VER_MAJOR)
    #error " NON-MATCHED DATA : WDG_AR_RELEASE_MAJOR_VERSION "
#endif
#if (WDG_AR_RELEASE_MINOR_VERSION != WDG_CFG_H_VER_MINOR)
    #error " NON-MATCHED DATA : WDG_AR_RELEASE_MINOR_VERSION "
#endif
#if (WDG_H_REVISION_VERSION != WDG_CFG_H_VER_REVISION)
    #error " NON-MATCHED DATA : WDG_H_REVISION_VERSION "
#endif
#if (WDG_H_SW_MAJOR_VERSION != WDG_CFG_H_SW_VER_MAJOR)
    #error " NON-MATCHED DATA : WDG_H_SW_MAJOR_VERSION "
#endif
#if (WDG_H_SW_MINOR_VERSION != WDG_CFG_H_SW_VER_MINOR)
    #error " NON-MATCHED DATA : WDG_H_SW_MINOR_VERSION "
#endif
#if (WDG_H_SW_PATCH_VERSION != WDG_CFG_H_SW_VER_PATCH)
    #error " NON-MATCHED DATA : WDG_H_SW_PATCH_VERSION "
#endif

/*======================================= CONSTANTS============================================*/

/*==================================== DEFINES AND MACROS=========================================*/

#define WDG_ERROR_CHECK (WDG_DEV_ERROR_REPORT)
#define WDG_CORE_NUM                    MCAL_CORE_NUM
/*==========================================ENUMS=================================================*/
typedef enum Wdg_ServiceId
{
    WDG_INIT_ID                 = 0x00U,
    WDG_SETMODE_ID              = 0x01U,
    WDG_SETTRIGGERCONDITION_ID  = 0x02U,
    WDG_TRIGGER_ID              = 0x03U,
#if (WDG_VERSION_INFO_API == STD_ON)
    WDG_GETVERSION_ID           = 0x04U
#endif    
} Wdg_ServiceId_Type;
typedef enum Wdg_ErrorId
{
    WDG_E_DRIVER_STATE  = 0x10U,
    WDG_E_PARAM_MODE =    0x11U,
    WDG_E_PARAM_CONFIG =  0x12U,
    WDG_E_PARAM_TIMEOUT = 0x13U,
    WDG_E_PARAM_POINTER = 0x14U,
    WDG_E_INIT_FAILED =   0x15U
} Wdg_ErrorId_Type;

typedef enum {
    WDG_UNINIT         = 0x00U,
    WDG_IDLE           = 0x01U,
    WDG_BUSY           = 0x02U
} Wdg_Status_Type;

typedef struct {
    P2CONST(SWT_Module_Config_Type, AUTOMATIC, WDG_APPL_CONST) SWT_Config_Type;
} Wdg_ConfigType;
/*=============================== STRUCTURES AND OTHER TYPEDEFS===================================*/

#if (WDG_POSTBUILD_SUPPORT==STD_OFF)
#if (WDGINSTANCE0==STD_ON)
WDG_PB_CONFIG_DECLARATION_0
#endif
#if (WDGINSTANCE1==STD_ON)
WDG_PB_CONFIG_DECLARATION_1
#endif
#if (WDGINSTANCE2==STD_ON)
WDG_PB_CONFIG_DECLARATION_2
#endif
#if (WDGINSTANCE3==STD_ON)
WDG_PB_CONFIG_DECLARATION_3
#endif
#if (WDGINSTANCE4==STD_ON)
WDG_PB_CONFIG_DECLARATION_4
#endif
#if (WDGINSTANCE5==STD_ON)
WDG_PB_CONFIG_DECLARATION_5
#endif
#if (WDGINSTANCE6==STD_ON)
WDG_PB_CONFIG_DECLARATION_6
#endif
#if (WDGINSTANCE7_AO==STD_ON)
WDG_PB_CONFIG_DECLARATION_7
#endif
#else
#if (WDGINSTANCE0==STD_ON)
extern CONST(Wdg_ConfigType, WDG_CONST) Wdg_Config_0;
#endif
#if (WDGINSTANCE1==STD_ON)
extern CONST(Wdg_ConfigType, WDG_CONST) Wdg_Config_1;
#endif
#if (WDGINSTANCE2==STD_ON)
extern CONST(Wdg_ConfigType, WDG_CONST) Wdg_Config_2;
#endif
#if (WDGINSTANCE3==STD_ON)
extern CONST(Wdg_ConfigType, WDG_CONST) Wdg_Config_3;
#endif
#if (WDGINSTANCE4==STD_ON)
extern CONST(Wdg_ConfigType, WDG_CONST) Wdg_Config_4;
#endif
#if (WDGINSTANCE5==STD_ON)
extern CONST(Wdg_ConfigType, WDG_CONST) Wdg_Config_5;
#endif
#if (WDGINSTANCE6==STD_ON)
extern CONST(Wdg_ConfigType, WDG_CONST) Wdg_Config_6;
#endif
#if (WDGINSTANCE7_AO==STD_ON)
extern CONST(Wdg_ConfigType, WDG_CONST) Wdg_Config_7;
#endif
#endif

extern P2CONST(Wdg_ConfigType, WDG_VAR, WDG_APPL_CONST) pWdg_ConfigPtr[WDG_INSTANCES_NUM];

/*===================================FUNCTION PROTOTYPES============================================*/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(void, WDG_CODE) WdgTrigger(VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID);
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
FUNC(void, WDG_CODE) Wdg_RunInstance_Init \
( \
    P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr, \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID \
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
FUNC(void, WDG_CODE) Wdg_RunGetVersionInfo \
( \
		P2VAR(Std_VersionInfoType, AUTOMATIC, WDG_APPL_DATA) Versioninfo, \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID \
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
FUNC(Std_ReturnType, WDG_CODE) Wdg_RunInstance_SetMode \
( \
    VAR(WdgIf_ModeType,AUTOMATIC) Mode, \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID \
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
FUNC(void, WDG_CODE) Wdg_RunSetTriggerCondition \
( \
    VAR(uint16,AUTOMATIC) timeout, \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef __cplusplus
}
#endif /* WDG_H */
/** @} */
#endif
