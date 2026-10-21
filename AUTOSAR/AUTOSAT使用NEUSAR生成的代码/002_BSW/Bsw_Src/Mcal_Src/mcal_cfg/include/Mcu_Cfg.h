/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC
*   Peripheral           : Mcu
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    Mcu_Cfg.h
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Mcu MCAL driver.
*
*   @addtogroup Mcu
*   @{
*/

#ifndef MCU_CFG_H
#define MCU_CFG_H

#ifdef __cplusplus
extern "C"{
#endif


/*==============================================INCLUDE FILES=======================================*/

#include "Mcal.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define MCU_CFG_VENDOR_ID                    176
#define MCU_CFG_AR_MAJOR_VER                 4
#define MCU_CFG_AR_MINOR_VER                 4
#define MCU_CFG_AR_PATCH_VER                 0
#define MCU_CFG_SW_MAJOR_VER                 3
#define MCU_CFG_SW_MINOR_VER                 0
#define MCU_CFG_SW_PATCH_VER                 0

#define MCU_MODULE_ID                        101

/*============================================FILE VERSION CHECKS===================================*/

#if (MCU_CFG_VENDOR_ID != MCAL_VENDOR_ID)
#error "NON-MATCHED DATA : MCAL_VENDOR_ID"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#if (MCU_CFG_AR_MAJOR_VER != MCAL_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : MCAL_AR_MAJOR_VER"
#endif
#if (MCU_CFG_AR_MINOR_VER != MCAL_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : MCAL_AR_MINOR_VER"
#endif
#if (MCU_CFG_AR_PATCH_VER != MCAL_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : MCAL_AR_PATCH_VER"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (MCU_CFG_SW_MAJOR_VER != MCAL_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : MCAL_SW_MAJOR_VER"
#endif
#if (MCU_CFG_SW_MINOR_VER != MCAL_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : MCAL_SW_MINOR_VER"
#endif
#if (MCU_CFG_SW_PATCH_VER != MCAL_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : MCAL_SW_PATCH_VER"
#endif


/*==================================================================================================
DEFINES
==================================================================================================*/
#define MCU_HARDVER                         5

#define McuModuleConfiguration  Mcu_Config
#define MCU_CONFIG_TYPE_PB                          (STD_ON)

#define MCU_DEV_ERROR_DETECT                        (STD_ON)
#define MCU_DISABLE_DEM_REPORT_ERROR_STATUS         (STD_ON)

#define MCU_INIT_CLOCK                              (STD_ON)
#define MCU_NO_PLL                                  (STD_OFF)
#define MCU_PERFORM_RESET_API                       (STD_ON)
#define MCU_GET_RAM_STATE_API                       (STD_ON)
#define MCU_VERSION_INFO_API                        (STD_ON)

#define MC_ME_RUN_CONFIG_COUNT                      8U
#define MC_ME_LOWPOWER_CONFIG_COUNT                 8U
#define MC_ME_PERIPH_CONFIG_COUNT                   2U
#define MC_ME_PERIPH_INSTANCE_COUNT                 118U

#define MCU_PERIRESET_COUNT                         0U

#define CMU_INSTANCE_COUNT                          13U

#define MCU_CLOCKS_FAILURE_EN                       (STD_ON)

#define MCU_FCCU_ENABLE                             (STD_ON)

#define MCU_TIMEOUT_LOOPS                           ((uint32)200000U)

#define MCU_XOSC_FREQ                               ((uint32)40000000U)

#define MCU_INLINE                                  LOCAL_INLINE

#define MCU_BOOT_CORE_ID                            CORE_ID_0
#define MCU_INIT_CORE_ID                            CORE_ID_0

/* FCCU Operation Timeout definition */
#define FCCU_OP_TIMEOUT_CONFIG                       0xFFFFFFFFU

#define FCCU_MAX_FAULTS_NO                           128U

#define FCCU_RF_MAX_GROUP                            4U

/* Control register key macros */                 
#define FCCU_RECOVERABLE_FAULT_KEY                   0xAB3498FEU
#define FCCU_UNLOCK_OP1_KEY                          0x913756AFU
#define FCCU_UNLOCK_OP2_KEY                          0x825A132BU

/* Transition Unlocking Key value */                 
#define FCCU_TRANSKEY_UNLOCK_VAL                     0xBCU
#define FCCU_TRANSKEY_LOCK_VAL                       0xFFU

/* Transition Locking Key value */                 
#define FCCU_PERMENTKEY_LOCK_VAL                     0xFFU



/**
*             Create defines with the IDs assigned to Mcu Clock configurations.
*                   These IDs will be transmitted as input parameters for Mcu_InitClock() API.
*/


#define McuClockSettingConfig_0   ((Mcu_ClockType)0U)

#define McuConf_McuClockSettingConfig_McuClockSettingConfig_0   ((Mcu_ClockType)0U) 


/**
*             Create defines with the IDs assigned to Mcu Mode configurations.
*                   These IDs will be transmitted as input parameters for Mcu_SetMode() API.
*/

#define McuModeSettingConf_0   ((Mcu_ModeType)0U)

#define McuConf_McuModeSettingConf_McuModeSettingConf_0   ((Mcu_ModeType)0U)


#define McuModeSettingConf_1   ((Mcu_ModeType)1U)

#define McuConf_McuModeSettingConf_McuModeSettingConf_1   ((Mcu_ModeType)1U)


#define McuModeSettingConf_2   ((Mcu_ModeType)2U)

#define McuConf_McuModeSettingConf_McuModeSettingConf_2   ((Mcu_ModeType)2U)


#define McuModeSettingConf_3   ((Mcu_ModeType)3U)

#define McuConf_McuModeSettingConf_McuModeSettingConf_3   ((Mcu_ModeType)3U)


#define McuModeSettingConf_4   ((Mcu_ModeType)4U)

#define McuConf_McuModeSettingConf_McuModeSettingConf_4   ((Mcu_ModeType)4U)


/**
*             Create defines with the IDs assigned to Mcu RAM Section configurations.
*                   These IDs will be transmitted as input parameters for Mcu_InitRamSection() API.
*/


#define McuRamSectorSettingConf_0   ((Mcu_RamSectionType)0U)

#define McuConf_McuRamSectorSettingConf_McuRamSectorSettingConf_0   ((Mcu_RamSectionType)0U)








#include "Mcu.h"

#define MCU_PB_CONFIG_DECLARATION   extern CONST(Mcu_ConfigType, MCU_CONST) Mcu_Config;

#ifdef __cplusplus
}
#endif

#endif
