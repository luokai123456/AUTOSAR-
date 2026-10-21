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
*   @file    Wdg_instance7_Cfg.c
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
#define SWT_MAPCONFIG                         ((uint8)0xFFU)
#include "Wdg_Cfg.h"
#include "Wdg_176_ModId7.h"



#define WDG_INST7_CFG_C_VENDOR_ID                   176
#define WDG_INST7_CFG_C_VER_MAJOR                  4
#define WDG_INST7_CFG_C_VER_MINOR                  4
#define WDG_INST7_CFG_C_VER_REVISION               0
#define WDG_INST7_CFG_C_SW_VER_MAJOR               3
#define WDG_INST7_CFG_C_SW_VER_MINOR               0
#define WDG_INST7_CFG_C_SW_VER_PATCH               0
#if (WDG_INST7_CFG_C_VENDOR_ID != WDG_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_VENDOR_ID "
#endif
#if (WDG_INST7_CFG_C_VER_MAJOR != WDG_CFG_H_VER_MAJOR)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_VER_MAJOR "
#endif
#if (WDG_INST7_CFG_C_VER_MINOR != WDG_CFG_H_VER_MINOR)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_VER_MINOR "
#endif
#if (WDG_INST7_CFG_C_VER_REVISION != WDG_CFG_H_VER_REVISION)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_VER_REVISION "
#endif
#if (WDG_INST7_CFG_C_SW_VER_MAJOR != WDG_CFG_H_SW_VER_MAJOR)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_SW_VER_MAJOR "
#endif
#if (WDG_INST7_CFG_C_SW_VER_MINOR != WDG_CFG_H_SW_VER_MINOR)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_SW_VER_MINOR "
#endif
#if (WDG_INST7_CFG_C_SW_VER_PATCH != WDG_CFG_H_SW_VER_PATCH)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_SW_VER_PATCH "
#endif
#if (WDG_INST7_CFG_C_VENDOR_ID != WDG_176_MOD7_H_VENDOR_ID)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_VENDOR_ID "
#endif
#if (WDG_INST7_CFG_C_VER_MAJOR != WDG_176_MOD7_H_VER_MAJOR)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_VER_MAJOR "
#endif
#if (WDG_INST7_CFG_C_VER_MINOR != WDG_176_MOD7_H_VER_MINOR)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_VER_MINOR "
#endif
#if (WDG_INST7_CFG_C_VER_REVISION != WDG_176_MOD7_H_VER_REVISION)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_VER_REVISION "
#endif
#if (WDG_INST7_CFG_C_SW_VER_MAJOR != WDG_176_MOD7_H_SW_VER_MAJOR)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_SW_VER_MAJOR "
#endif
#if (WDG_INST7_CFG_C_SW_VER_MINOR != WDG_176_MOD7_H_SW_VER_MINOR)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_SW_VER_MINOR "
#endif
#if (WDG_INST7_CFG_C_SW_VER_PATCH != WDG_176_MOD7_H_SW_VER_PATCH)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_SW_VER_PATCH "
#endif

#if (WDGINSTANCE7_AO == STD_ON)
#define WDG_START_SEC_CONFIG_DATA
#include "Wdg_MemMap.h" 
static CONST(SWT_ModeConfig_Type, WDG_CONST) Wdg_Swt_OffModeSettings_Instance7=
{
    .SWT_MAPConfig=             SWT_MAPCONFIG,
    .SWT_ServiceMode=           Fixed_Serv_Seq,
    .SWT_ResetonInvalidAccess=  SWT_SystemReset,
    .SWT_WindowMode=             SWT_Disable,
    .SWT_InterruptMode=         SWT_RESET_FIRST,
    .SWT_StopMode=              SWT_CONTINUE,
    .SWT_DebugMode=             SWT_FreezeOFF, 
    .SWT_Lock_Mode=             SWT_Softlock,     
    .SWT_InitialSK=             0x00000000u,                 
    .SWT_Timeout=               0x00000100u   ,              
    .SWT_WindowValue=           0x00000000u  ,               
    .Wdg_InternalClock=         16000u,
	.Wdg_TriggerAddr =          0u
} ;    
#define WDG_STOP_SEC_CONFIG_DATA
#include "Wdg_MemMap.h" 

#define WDG_START_SEC_CONFIG_DATA
#include "Wdg_MemMap.h"    
static CONST(SWT_ModeConfig_Type, WDG_CONST) Wdg_Swt_FastModeSettings_7=
{
    .SWT_MAPConfig=             SWT_MAPCONFIG,
    .SWT_ServiceMode=           Fixed_Serv_Seq,
    .SWT_ResetonInvalidAccess=  SWT_SystemReset,
    .SWT_WindowMode=            SWT_Disable,
    .SWT_InterruptMode=         SWT_RESET_FIRST,
    .SWT_StopMode=              SWT_CONTINUE,
    .SWT_DebugMode=             SWT_FreezeOFF,          
    .SWT_Lock_Mode=             SWT_Softlock,
    .SWT_InitialSK=             0u,  
    .SWT_Timeout=               0x0000fa00u,                 
    .SWT_WindowValue=           0x00006400u,
    .Wdg_InternalClock=         32u,
	.Wdg_TriggerAddr =          0u
};
#define WDG_STOP_SEC_CONFIG_DATA
#include "Wdg_MemMap.h" 

#define WDG_START_SEC_CONFIG_DATA
#include "Wdg_MemMap.h" 
static CONST(SWT_ModeConfig_Type, WDG_CONST) Wdg_Swt_SlowModeSettings_7=
{
    .SWT_MAPConfig=             SWT_MAPCONFIG,
    .SWT_ServiceMode=           Fixed_Serv_Seq,
    .SWT_ResetonInvalidAccess=  SWT_SystemReset,
    .SWT_WindowMode=            SWT_Disable,
    .SWT_InterruptMode=         SWT_RESET_FIRST,
    .SWT_StopMode=              SWT_CONTINUE,
    .SWT_DebugMode=             SWT_FreezeOFF,          
    .SWT_Lock_Mode=             SWT_Softlock,
    .SWT_InitialSK=             0u,              
    .SWT_Timeout=               0x0000fa00u,                 
    .SWT_WindowValue=           0x00006400u,
    .Wdg_InternalClock=         32u,
	.Wdg_TriggerAddr =          0u
};
#define WDG_STOP_SEC_CONFIG_DATA
#include "Wdg_MemMap.h" 

#define WDG_START_SEC_CONFIG_DATA
#include "Wdg_MemMap.h" 
static CONST(SWT_Module_Config_Type, WDG_CONST)WdgConfigSetType7 =
{
    .SWT_ModuleID = SWT7_AO,
    .SWT_DefaultRunMode = WDGIF_FAST_MODE,
    .u8Wdg_GptTimerChannel = (Gpt_ChannelType)7u,
    .u32Wdg_TriggerSourceClock = 100000u,
    .SWT_Config = { &Wdg_Swt_OffModeSettings_Instance7, &Wdg_Swt_SlowModeSettings_7, &Wdg_Swt_FastModeSettings_7},
    .SWT_Callback =NULL_PTR 
};
#define WDG_STOP_SEC_CONFIG_DATA
#include "Wdg_MemMap.h" 

#define WDG_START_SEC_CONFIG_DATA
#include "Wdg_MemMap.h" 
CONST(Wdg_ConfigType, WDG_CONST) WdgSettingsConfig_7 =
{
			&WdgConfigSetType7,
};
#define WDG_STOP_SEC_CONFIG_DATA
#include "Wdg_MemMap.h"


#endif


#ifdef __cplusplus
}
#endif
