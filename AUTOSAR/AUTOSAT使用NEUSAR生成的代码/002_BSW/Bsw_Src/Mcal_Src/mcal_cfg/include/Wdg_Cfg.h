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
*   @file    Wdg_Cfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Wdg MCAL driver.
*
*   @addtogroup Wdg
*   @{
*/
#ifndef WDG_CFG_H
#define WDG_CFG_H
#ifdef __cplusplus
extern "C"{
#endif
#include "Mcal.h"



#define WDG_CFG_H_VENDOR_ID                   176
#define WDG_CFG_H_VER_MAJOR                  4
#define WDG_CFG_H_VER_MINOR                  4
#define WDG_CFG_H_VER_REVISION               0
#define WDG_CFG_H_SW_VER_MAJOR               3
#define WDG_CFG_H_SW_VER_MINOR               0
#define WDG_CFG_H_SW_VER_PATCH               0

#if (WDG_CFG_H_VENDOR_ID != MCAL_VENDOR_ID)
    #error " NON-MATCHED DATA : WDG_CFG_H_VENDOR_ID "
#endif
#if (WDG_CFG_H_VER_MAJOR != MCAL_AR_RELEASE_MAJOR_VERSION)
    #error " NON-MATCHED DATA : WDG_CFG_H_VER_MAJOR "
#endif
#if (WDG_CFG_H_VER_MINOR != MCAL_AR_RELEASE_MINOR_VERSION)
    #error " NON-MATCHED DATA : WDG_CFG_H_VER_MINOR "
#endif
#if (WDG_CFG_H_VER_REVISION != MCAL_AR_RELEASE_REVISION_VERSION)
    #error " NON-MATCHED DATA : WDG_CFG_H_VER_REVISION "
#endif
#if (WDG_CFG_H_SW_VER_MAJOR != MCAL_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : WDG_CFG_H_SW_VER_MAJOR "
#endif
#if (WDG_CFG_H_SW_VER_MINOR != MCAL_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : WDG_CFG_H_SW_VER_MINOR "
#endif
#if (WDG_CFG_H_SW_VER_PATCH != MCAL_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : WDG_CFG_H_SW_VER_PATCH "
#endif

#define WDG_DEV_ERROR_REPORT                 (STD_ON)

#define WDG_DISABLE_ALLOWED                  (STD_ON)

#define WDG_INLINE                          LOCAL_INLINE
#define WDG_INSTANCES_NUM                    (8U)

#define WDG_INTERNAL_MODULE                  (0U)
#define WDG_EXTERNAL_MODULE_SPI              (1U)
#define WDG_EXTERNAL_MODULE_DIO              (2U)
#define WDG_POSTBUILD_SUPPORT              (STD_ON)
#define WDG_TYPE                          (    WDG_INTERNAL_MODULE)
#define WDG_DEM_REPORT_ERROR_ENABLE           (STD_ON)   
#define WDG_VERSION_INFO_API                  (STD_ON)
#define WdgIndex0             ((uint8)0U)
#define WdgIndex1             ((uint8)1U)
#define WdgIndex2             ((uint8)2U)
#define WdgIndex3             ((uint8)3U)
#define WdgIndex4             ((uint8)4U)
#define WdgIndex5             ((uint8)5U)
#define WdgIndex6             ((uint8)6U)
#define WdgIndex7             ((uint8)7U)


#define WDGINSTANCE0    (STD_ON)
#define WDGINSTANCE1    (STD_ON)
#define WDGINSTANCE2    (STD_ON)
#define WDGINSTANCE3    (STD_ON)
#define WDGINSTANCE4    (STD_ON)
#define WDGINSTANCE5    (STD_ON)
#define WDGINSTANCE6    (STD_ON)
#define WDGINSTANCE7_AO    (STD_ON)

        
extern FUNC(void, WDG_CODE)Wdg_Cbk_GptNotification0(void);
            
extern FUNC(void, WDG_CODE)Wdg_Cbk_GptNotification1(void);
            
extern FUNC(void, WDG_CODE)Wdg_Cbk_GptNotification2(void);
    
extern FUNC(void, WDG_CODE)Wdg_Cbk_GptNotification3(void);
        
extern FUNC(void, WDG_CODE)Wdg_Cbk_GptNotification4(void);
            
extern FUNC(void, WDG_CODE)Wdg_Cbk_GptNotification5(void);
            
extern FUNC(void, WDG_CODE)Wdg_Cbk_GptNotification6(void);
    
extern FUNC(void, WDG_CODE)Wdg_Cbk_GptNotification7(void);
#define WDG_INITIAL_TIMEOUT_U32              (2000000u)
#define WDG_MAX_TIMEOUT_U32                  (5000000u)
#define WDG_ROM

extern CONST(Mcal_DemErrorType, WDG_CONST)Wdg_E_Disable_Rejected;
extern CONST(Mcal_DemErrorType, WDG_CONST)Wdg_E_Mode_Failed;

#if(WDGINSTANCE0 == STD_ON)
#define WDG_PB_CONFIG_DECLARATION_0 extern CONST(Wdg_ConfigType, WDG_CONST) Wdg_Config_0;
#define WdgSettingsConfig_0 Wdg_Config_0
#endif
#if(WDGINSTANCE1 == STD_ON)
#define WDG_PB_CONFIG_DECLARATION_1 extern CONST(Wdg_ConfigType, WDG_CONST) Wdg_Config_1;
#define WdgSettingsConfig_1 Wdg_Config_1
#endif
#if(WDGINSTANCE2 == STD_ON)
#define WDG_PB_CONFIG_DECLARATION_2 extern CONST(Wdg_ConfigType, WDG_CONST) Wdg_Config_2;
#define WdgSettingsConfig_2 Wdg_Config_2
#endif
#if(WDGINSTANCE3 == STD_ON)
#define WDG_PB_CONFIG_DECLARATION_3  extern CONST(Wdg_ConfigType, WDG_CONST) Wdg_Config_3;
#define WdgSettingsConfig_3 Wdg_Config_3
#endif
#if(WDGINSTANCE4 == STD_ON)
#define WDG_PB_CONFIG_DECLARATION_4  extern CONST(Wdg_ConfigType, WDG_CONST) Wdg_Config_4;
#define WdgSettingsConfig_4 Wdg_Config_4
#endif
#if(WDGINSTANCE5 == STD_ON)
#define WDG_PB_CONFIG_DECLARATION_5  extern CONST(Wdg_ConfigType, WDG_CONST) Wdg_Config_5;
#define WdgSettingsConfig_5 Wdg_Config_5
#endif
#if(WDGINSTANCE6 == STD_ON)
#define WDG_PB_CONFIG_DECLARATION_6  extern CONST(Wdg_ConfigType, WDG_CONST) Wdg_Config_6;
#define WdgSettingsConfig_6 Wdg_Config_6
#endif
#if(WDGINSTANCE7_AO == STD_ON)
#define WDG_PB_CONFIG_DECLARATION_7  extern CONST(Wdg_ConfigType, WDG_CONST) Wdg_Config_7;
#define WdgSettingsConfig_7 Wdg_Config_7
#endif
#ifdef __cplusplus
}
#endif
#endif
