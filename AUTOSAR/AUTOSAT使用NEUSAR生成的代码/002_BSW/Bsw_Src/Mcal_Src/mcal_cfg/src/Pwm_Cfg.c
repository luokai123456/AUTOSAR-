/* PRQA S 0704,4424 EOF */

/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : -
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
*   @file    Pwm_Cfg.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Pwm MCAL driver.
*
*   @addtogroup Pwm
*   @{
*/

/* PRQA S 0686 EOF */

#ifdef __cplusplus
extern "C"{
#endif

#include "Pwm_Cfg.h"/* PRQA S 0380 */

#define PWM_CFG_C_VENDOR_ID                      176
#define PWM_CFG_C_AR_REL_MAJOR_VER               4
#define PWM_CFG_C_AR_REL_MINOR_VER               4
#define PWM_CFG_C_AR_REL_REV_VER                 0
#define PWM_CFG_C_SW_MAJOR_VER                   3
#define PWM_CFG_C_SW_MINOR_VER                   0
#define PWM_CFG_C_SW_PATCH_VER                   0

#if (PWM_CFG_C_VENDOR_ID != MCAL_VENDOR_ID)
    #error " NON-MATCHED DATA : PWM_CFG_C_VENDOR_ID "
#endif
#if (PWM_CFG_C_AR_REL_MAJOR_VER != MCAL_AR_RELEASE_MAJOR_VERSION)
    #error " NON-MATCHED DATA : PWM_CFG_C_AR_REL_MAJOR_VER "
#endif
#if (PWM_CFG_C_AR_REL_MINOR_VER != MCAL_AR_RELEASE_MINOR_VERSION)
    #error " NON-MATCHED DATA : PWM_CFG_C_AR_REL_MINOR_VER "
#endif
#if (PWM_CFG_C_AR_REL_REV_VER != MCAL_AR_RELEASE_REVISION_VERSION)
    #error " NON-MATCHED DATA : PWM_CFG_C_AR_REL_REV_VER "
#endif
#if (PWM_CFG_C_SW_MAJOR_VER != MCAL_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : PWM_CFG_C_SW_MAJOR_VER "
#endif
#if (PWM_CFG_C_SW_MINOR_VER != MCAL_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : PWM_CFG_C_SW_MINOR_VER "
#endif
#if (PWM_CFG_C_SW_PATCH_VER != MCAL_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : PWM_CFG_C_SW_PATCH_VER "
#endif





#define PWM_START_SEC_CONFIG_DATA
#include "Pwm_MemMap.h"
static CONST(Pwm_NotifyTableItemType, PWM_CONST) Pwm_TomNotifyTable[PWM_TOM_MAX * PWM_TOM_CHANNEL_MAX];
#define PWM_STOP_SEC_CONFIG_DATA
#include "Pwm_MemMap.h"
#define PWM_START_SEC_CONFIG_DATA
#include "Pwm_MemMap.h"
static CONST(Pwm_NotifyTableItemType, PWM_CONST) Pwm_AtomNotifyTable[PWM_ATOM_MAX * PWM_ATOM_CHANNEL_MAX];
#define PWM_STOP_SEC_CONFIG_DATA
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CONFIG_DATA
#include "Pwm_MemMap.h"
static CONST(Pwm_NotifyTableItemType, PWM_CONST) Pwm_EmiosNotifyTable[PWM_EMIOS_MAX * PWM_EMIOS_CHANNEL_MAX];
#define PWM_STOP_SEC_CONFIG_DATA
#include "Pwm_MemMap.h"
#define PWM_START_SEC_CONFIG_DATA
#include "Pwm_MemMap.h"
static CONST(Pwm_CoreMapItemType, PWM_CONST)     Pwm_CoreMap[PWM_CHANNEL_NUM];
#define PWM_STOP_SEC_CONFIG_DATA
#include "Pwm_MemMap.h"
                                                
#define PWM_START_SEC_CONFIG_DATA
#include "Pwm_MemMap.h"
CONST(Pwm_ConfigType, PWM_CONST) Pwm_Config=
{
    .nNum=PWM_CHANNEL_NUM,
    .pPwm_TomNotifyTable=Pwm_TomNotifyTable,
    .pPwm_AtomNotifyTable=Pwm_AtomNotifyTable,
    .pPwm_EmiosNotifyTable=Pwm_EmiosNotifyTable,
    .pPwm_CoreMap=Pwm_CoreMap,
    .sPwmChConfigs={
        {
            .nPwmChannelId=0,
            .ePwmHwIP=PWM_TOM,
            .sHwConfig={
                .nPwmHwIndex=5,
                .nPwmChIndex=2
            },
            .nPwmPeriodDefault=1,
            .nPwmDutycycleDefault=16384,
            .ePwmChannelClass=PWM_VARIABLE_PERIOD,
            .ePwmPolarity=PWM_HIGH,
            .ePwmIdleState=PWM_LOW,
            .pfPwmChannelNotification=NULL_PTR,
            .nGtm4Tout=192,
            .nToutNum=1,
            .sCmuClk={
                .TOM_ClkSrc={
                    .ClkSrc=FXClk0,
                }
            },
            		.nPwmMaxDutycycle=32768,
        },
        {
            .nPwmChannelId=1,
            .ePwmHwIP=PWM_TOM,
            .sHwConfig={
                .nPwmHwIndex=3,
                .nPwmChIndex=11
            },
            .nPwmPeriodDefault=1,
            .nPwmDutycycleDefault=16384,
            .ePwmChannelClass=PWM_VARIABLE_PERIOD,
            .ePwmPolarity=PWM_HIGH,
            .ePwmIdleState=PWM_LOW,
            .pfPwmChannelNotification=NULL_PTR,
            .nGtm4Tout=185,
            .nToutNum=0,
            .sCmuClk={
                .TOM_ClkSrc={
                    .ClkSrc=FXClk0,
                }
            },
            		.nPwmMaxDutycycle=32768,
        },
        {
            .nPwmChannelId=2,
            .ePwmHwIP=PWM_TOM,
            .sHwConfig={
                .nPwmHwIndex=3,
                .nPwmChIndex=14
            },
            .nPwmPeriodDefault=1,
            .nPwmDutycycleDefault=16384,
            .ePwmChannelClass=PWM_VARIABLE_PERIOD,
            .ePwmPolarity=PWM_HIGH,
            .ePwmIdleState=PWM_LOW,
            .pfPwmChannelNotification=NULL_PTR,
            .nGtm4Tout=188,
            .nToutNum=0,
            .sCmuClk={
                .TOM_ClkSrc={
                    .ClkSrc=FXClk0,
                }
            },
            		.nPwmMaxDutycycle=32768,
        },
        {
            .nPwmChannelId=3,
            .ePwmHwIP=PWM_TOM,
            .sHwConfig={
                .nPwmHwIndex=5,
                .nPwmChIndex=3
            },
            .nPwmPeriodDefault=1,
            .nPwmDutycycleDefault=16384,
            .ePwmChannelClass=PWM_VARIABLE_PERIOD,
            .ePwmPolarity=PWM_HIGH,
            .ePwmIdleState=PWM_LOW,
            .pfPwmChannelNotification=NULL_PTR,
            .nGtm4Tout=193,
            .nToutNum=1,
            .sCmuClk={
                .TOM_ClkSrc={
                    .ClkSrc=FXClk0,
                }
            },
            		.nPwmMaxDutycycle=32768,
        },
        {
            .nPwmChannelId=4,
            .ePwmHwIP=PWM_TOM,
            .sHwConfig={
                .nPwmHwIndex=3,
                .nPwmChIndex=8
            },
            .nPwmPeriodDefault=1,
            .nPwmDutycycleDefault=16384,
            .ePwmChannelClass=PWM_VARIABLE_PERIOD,
            .ePwmPolarity=PWM_HIGH,
            .ePwmIdleState=PWM_LOW,
            .pfPwmChannelNotification=NULL_PTR,
            .nGtm4Tout=182,
            .nToutNum=0,
            .sCmuClk={
                .TOM_ClkSrc={
                    .ClkSrc=FXClk0,
                }
            },
            		.nPwmMaxDutycycle=32768,
        },
        {
            .nPwmChannelId=5,
            .ePwmHwIP=PWM_TOM,
            .sHwConfig={
                .nPwmHwIndex=5,
                .nPwmChIndex=15
            },
            .nPwmPeriodDefault=1,
            .nPwmDutycycleDefault=16384,
            .ePwmChannelClass=PWM_VARIABLE_PERIOD,
            .ePwmPolarity=PWM_HIGH,
            .ePwmIdleState=PWM_LOW,
            .pfPwmChannelNotification=NULL_PTR,
            .nGtm4Tout=189,
            .nToutNum=1,
            .sCmuClk={
                .TOM_ClkSrc={
                    .ClkSrc=FXClk0,
                }
            },
            		.nPwmMaxDutycycle=32768,
        },
        {
            .nPwmChannelId=6,
            .ePwmHwIP=PWM_TOM,
            .sHwConfig={
                .nPwmHwIndex=4,
                .nPwmChIndex=12
            },
            .nPwmPeriodDefault=1,
            .nPwmDutycycleDefault=16384,
            .ePwmChannelClass=PWM_VARIABLE_PERIOD,
            .ePwmPolarity=PWM_HIGH,
            .ePwmIdleState=PWM_LOW,
            .pfPwmChannelNotification=NULL_PTR,
            .nGtm4Tout=234,
            .nToutNum=0,
            .sCmuClk={
                .TOM_ClkSrc={
                    .ClkSrc=FXClk0,
                }
            },
            		.nPwmMaxDutycycle=32768,
        },
        {
            .nPwmChannelId=7,
            .ePwmHwIP=PWM_TOM,
            .sHwConfig={
                .nPwmHwIndex=4,
                .nPwmChIndex=15
            },
            .nPwmPeriodDefault=1,
            .nPwmDutycycleDefault=16384,
            .ePwmChannelClass=PWM_VARIABLE_PERIOD,
            .ePwmPolarity=PWM_HIGH,
            .ePwmIdleState=PWM_LOW,
            .pfPwmChannelNotification=NULL_PTR,
            .nGtm4Tout=205,
            .nToutNum=0,
            .sCmuClk={
                .TOM_ClkSrc={
                    .ClkSrc=FXClk0,
                }
            },
            		.nPwmMaxDutycycle=32768,
        },
        {
            .nPwmChannelId=8,
            .ePwmHwIP=PWM_TOM,
            .sHwConfig={
                .nPwmHwIndex=4,
                .nPwmChIndex=14
            },
            .nPwmPeriodDefault=1,
            .nPwmDutycycleDefault=16384,
            .ePwmChannelClass=PWM_VARIABLE_PERIOD,
            .ePwmPolarity=PWM_HIGH,
            .ePwmIdleState=PWM_LOW,
            .pfPwmChannelNotification=NULL_PTR,
            .nGtm4Tout=204,
            .nToutNum=0,
            .sCmuClk={
                .TOM_ClkSrc={
                    .ClkSrc=FXClk0,
                }
            },
            		.nPwmMaxDutycycle=32768,
        },
        {
            .nPwmChannelId=9,
            .ePwmHwIP=PWM_TOM,
            .sHwConfig={
                .nPwmHwIndex=5,
                .nPwmChIndex=1
            },
            .nPwmPeriodDefault=1,
            .nPwmDutycycleDefault=16384,
            .ePwmChannelClass=PWM_VARIABLE_PERIOD,
            .ePwmPolarity=PWM_HIGH,
            .ePwmIdleState=PWM_LOW,
            .pfPwmChannelNotification=NULL_PTR,
            .nGtm4Tout=207,
            .nToutNum=1,
            .sCmuClk={
                .TOM_ClkSrc={
                    .ClkSrc=FXClk0,
                }
            },
            		.nPwmMaxDutycycle=32768,
        },
        {
            .nPwmChannelId=10,
            .ePwmHwIP=PWM_TOM,
            .sHwConfig={
                .nPwmHwIndex=5,
                .nPwmChIndex=6
            },
            .nPwmPeriodDefault=1,
            .nPwmDutycycleDefault=16384,
            .ePwmChannelClass=PWM_VARIABLE_PERIOD,
            .ePwmPolarity=PWM_HIGH,
            .ePwmIdleState=PWM_LOW,
            .pfPwmChannelNotification=NULL_PTR,
            .nGtm4Tout=228,
            .nToutNum=1,
            .sCmuClk={
                .TOM_ClkSrc={
                    .ClkSrc=FXClk0,
                }
            },
            		.nPwmMaxDutycycle=32768,
        },
        {
            .nPwmChannelId=11,
            .ePwmHwIP=PWM_TOM,
            .sHwConfig={
                .nPwmHwIndex=3,
                .nPwmChIndex=13
            },
            .nPwmPeriodDefault=1,
            .nPwmDutycycleDefault=16384,
            .ePwmChannelClass=PWM_VARIABLE_PERIOD,
            .ePwmPolarity=PWM_HIGH,
            .ePwmIdleState=PWM_LOW,
            .pfPwmChannelNotification=NULL_PTR,
            .nGtm4Tout=168,
            .nToutNum=0,
            .sCmuClk={
                .TOM_ClkSrc={
                    .ClkSrc=FXClk0,
                }
            },
            		.nPwmMaxDutycycle=32768,
        },
    }
};
#define PWM_STOP_SEC_CONFIG_DATA
#include "Pwm_MemMap.h"


#define PWM_START_SEC_CONFIG_DATA
#include "Pwm_MemMap.h"
static CONST(Pwm_NotifyTableItemType, PWM_CONST) Pwm_TomNotifyTable[PWM_TOM_MAX * PWM_TOM_CHANNEL_MAX]=
{
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=4},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=1},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=11},
    {.pNotification=NULL_PTR,.nPwmChannelId=2},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=6},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=8},
    {.pNotification=NULL_PTR,.nPwmChannelId=7},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=9},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=3},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=10},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=5},
};
#define PWM_STOP_SEC_CONFIG_DATA
#include "Pwm_MemMap.h"


#define PWM_START_SEC_CONFIG_DATA
#include "Pwm_MemMap.h"
static CONST(Pwm_NotifyTableItemType, PWM_CONST) Pwm_AtomNotifyTable[PWM_ATOM_MAX * PWM_ATOM_CHANNEL_MAX]=
{
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
};
#define PWM_STOP_SEC_CONFIG_DATA
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CONFIG_DATA
#include "Pwm_MemMap.h"
static CONST(Pwm_NotifyTableItemType, PWM_CONST) Pwm_EmiosNotifyTable[PWM_EMIOS_MAX * PWM_EMIOS_CHANNEL_MAX]=
{
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
};
#define PWM_STOP_SEC_CONFIG_DATA
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CONFIG_DATA
#include "Pwm_MemMap.h"
static CONST(Pwm_CoreMapItemType, PWM_CONST) Pwm_CoreMap[PWM_CHANNEL_NUM]=
{
    {
        .nPwmChannelId=0,
        .nCoreId=1
    },
    {
        .nPwmChannelId=1,
        .nCoreId=1
    },
    {
        .nPwmChannelId=2,
        .nCoreId=1
    },
    {
        .nPwmChannelId=3,
        .nCoreId=1
    },
    {
        .nPwmChannelId=4,
        .nCoreId=1
    },
    {
        .nPwmChannelId=5,
        .nCoreId=1
    },
    {
        .nPwmChannelId=6,
        .nCoreId=1
    },
    {
        .nPwmChannelId=7,
        .nCoreId=1
    },
    {
        .nPwmChannelId=8,
        .nCoreId=1
    },
    {
        .nPwmChannelId=9,
        .nCoreId=1
    },
    {
        .nPwmChannelId=10,
        .nCoreId=1
    },
    {
        .nPwmChannelId=11,
        .nCoreId=1
    },
};
#define PWM_STOP_SEC_CONFIG_DATA
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif
