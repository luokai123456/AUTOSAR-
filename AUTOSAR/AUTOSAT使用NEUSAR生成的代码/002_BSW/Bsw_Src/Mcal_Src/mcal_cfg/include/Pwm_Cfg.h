/* PRQA S 0722,1535,0723 EOF */

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
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/

/**
*   @file    Pwm_Cfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Pwm MCAL driver.
*
*   @addtogroup Pwm
*   @{
*/

#ifndef PWM_CFG_H_
#define PWM_CFG_H_

#ifdef __cplusplus
extern "C"{
#endif







































#include "Mcal.h"
#include "Pwm_Emios_LLDriver.h"

#include "Std_Types.h"



#define PWM_INDEX                                (0U)
#define PWM_CHANNEL_NUM                          (12U)

#define PWM_TOM_MAX                              RESOURCE_SUPPORT_GTM_TOM_NUM
#define PWM_TOM_CHANNEL_MAX                      (16U)

#define PWM_ATOM_MAX                             RESOURCE_SUPPORT_GTM_ATOM_NUM
#define PWM_ATOM_CHANNEL_MAX                     (8U)

#define PWM_EMIOS_MAX                            EMIOS_INSTANCE_MAX

#define PWM_EMIOS_CHANNEL_MAX                    (32U)






typedef uint8 Pwm_IndexType;
typedef uint16 Pwm_ChannelType;
typedef uint32 Pwm_PeriodType;
typedef uint32 Pwm_DutycycleType;

typedef uint16 Gtm4ToutType;
typedef uint16 ToutNumType;



typedef enum
{
    FXClk0 = 0,
    FXClk1,
    FXClk2,
    FXClk3,
    FXClk4
} Pwm_TOM_ClkSrcType;

typedef enum
{
    CMU_CLK0 = 0,
    CMU_CLK1,
    CMU_CLK2,
    CMU_CLK3,
    CMU_CLK4,
    CMU_CLK5,
    CMU_CLK6,
    CMU_CLK7
} Pwm_ATOM_ClkSrcType;

typedef struct{
    CONST(Pwm_TOM_ClkSrcType,      PWM_CONST) ClkSrc;
}Pwm_TOM_ClkType;

typedef struct{
    CONST(Pwm_ATOM_ClkSrcType,     PWM_CONST) ClkSrc;
}Pwm_ATOM_ClkType;

typedef union{
    CONST(Pwm_TOM_ClkType,      PWM_CONST) TOM_ClkSrc;
    CONST(Pwm_ATOM_ClkType,     PWM_CONST) ATOM_ClkSrc;
}Pwm_CmuClkType;


typedef enum
{

    PWM_TOM = 0,
    PWM_ATOM,
    PWM_EMIOS,



} Pwm_HwIPType;

typedef enum
{
    Bit_16 = 0,
    Bit_24
} Pwm_PrecisionType;

typedef enum
{
    PWM_VARIABLE_PERIOD = 0,
    PWM_FIXED_PERIOD,

    PWM_FIXED_PERIOD_SHIFTED = 2U,
    PWM_FIXED_PERIOD_CENTER_ALIGNED = 3U

} Pwm_ChannelClassType;

typedef enum
{
    PWM_LOW = 0,
    PWM_HIGH
} Pwm_OutputStateType;

typedef enum
{
    DIV_1 = 1,
    DIV_2,
    DIV_3,
    DIV_4
} Pwm_eMiosPrescalerType;






typedef struct{
    CONST(Pwm_ChannelType,             PWM_CONST) nPwmChannelId;
    CONST(uint8,                       PWM_CONST) nCoreId;
}Pwm_CoreMapItemType;

typedef struct{
    CONST(Pwm_eMiosPrescalerType,      PWM_CONST) nPwmeMiosPrescaler;
    CONST(eMIOS_PWM_ModeType,          PWM_CONST) nPwmeMiosMode;
    CONST(eMIOS_UC_CounterBusSelType,  PWM_CONST) nPwmeMiosBus;
    CONST(uint32,                      PWM_CONST) nIdealDutyCycle;
    CONST(uint32,                      PWM_CONST) nDeadtime;
    CONST(uint32,                      PWM_CONST) nOffset;
    CONST(boolean,                     PWM_CONST) nPwmeMiosDmaSwitch;

    CONST(uint32,                      PWM_CONST) ntrigTime;

}Pwm_eMiosChannelConfigType;

typedef struct
{
    CONST(Pwm_IndexType, PWM_CONST) nPwmHwIndex;
    CONST(Pwm_IndexType, PWM_CONST) nPwmChIndex;
} Pwm_HwConfigType;

typedef void (*Pwm_NotifyType)(void);

typedef struct{
    CONST(Pwm_NotifyType,               PWM_CONST) pNotification;
    CONST(Pwm_ChannelType,              PWM_CONST) nPwmChannelId;
}Pwm_NotifyTableItemType;



typedef struct
{
    CONST(Pwm_ChannelType,              PWM_CONST) nPwmChannelId;
    CONST(Pwm_HwIPType,                 PWM_CONST) ePwmHwIP;
    CONST(Pwm_HwConfigType,             PWM_CONST) sHwConfig;
    CONST(Pwm_PeriodType,               PWM_CONST) nPwmPeriodDefault;
    CONST(Pwm_DutycycleType,            PWM_CONST) nPwmDutycycleDefault;
    CONST(Pwm_ChannelClassType,         PWM_CONST) ePwmChannelClass;
    CONST(Pwm_OutputStateType,          PWM_CONST) ePwmPolarity;
    CONST(Pwm_OutputStateType,          PWM_CONST) ePwmIdleState;
    CONST(Pwm_NotifyType,               PWM_CONST) pfPwmChannelNotification;
    CONST(Pwm_eMiosChannelConfigType,   PWM_CONST) sEmiosChannelConfig;

    CONST(Gtm4ToutType,                 PWM_CONST) nGtm4Tout;
    CONST(ToutNumType,                  PWM_CONST) nToutNum;



    CONST(Pwm_CmuClkType,               PWM_CONST) sCmuClk;


    CONST(Pwm_DutycycleType,            PWM_CONST) nPwmMaxDutycycle;

} Pwm_ChConfigType;

typedef struct
{
    CONST(Pwm_IndexType,                        PWM_CONST)      nNum;

    P2CONST(Pwm_NotifyTableItemType, PWM_CONST, PWM_APPL_CONST) pPwm_TomNotifyTable;
    P2CONST(Pwm_NotifyTableItemType, PWM_CONST, PWM_APPL_CONST) pPwm_AtomNotifyTable;

    P2CONST(Pwm_NotifyTableItemType, PWM_CONST, PWM_APPL_CONST) pPwm_EmiosNotifyTable;


    P2CONST(Pwm_CoreMapItemType,     PWM_CONST, PWM_APPL_CONST) pPwm_CoreMap;
    CONST(Pwm_ChConfigType,                     PWM_CONST)      sPwmChConfigs[PWM_CHANNEL_NUM];
} Pwm_ChConfigsType;

typedef Pwm_ChConfigsType Pwm_ConfigType;

#define PWM_CFG_H_VENDOR_ID                      176
#define PWM_CFG_H_AR_REL_MAJOR_VER               4
#define PWM_CFG_H_AR_REL_MINOR_VER               4
#define PWM_CFG_H_AR_REL_REV_VER                 0
#define PWM_CFG_H_SW_MAJOR_VER                   3
#define PWM_CFG_H_SW_MINOR_VER                   0
#define PWM_CFG_H_SW_PATCH_VER                   0

#if (PWM_CFG_H_VENDOR_ID != MCAL_VENDOR_ID)
    #error " NON-MATCHED DATA : PWM_CFG_H_VENDOR_ID "
#endif
#if (PWM_CFG_H_AR_REL_MAJOR_VER != MCAL_AR_RELEASE_MAJOR_VERSION)
    #error " NON-MATCHED DATA : PWM_CFG_H_AR_REL_MAJOR_VER "
#endif
#if (PWM_CFG_H_AR_REL_MINOR_VER != MCAL_AR_RELEASE_MINOR_VERSION)
    #error " NON-MATCHED DATA : PWM_CFG_H_AR_REL_MINOR_VER "
#endif
#if (PWM_CFG_H_AR_REL_REV_VER != MCAL_AR_RELEASE_REVISION_VERSION)
    #error " NON-MATCHED DATA : PWM_CFG_H_AR_REL_REV_VER "
#endif
#if (PWM_CFG_H_SW_MAJOR_VER != MCAL_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : PWM_CFG_H_SW_MAJOR_VER "
#endif
#if (PWM_CFG_H_SW_MINOR_VER != MCAL_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : PWM_SW_MINOR_VER "
#endif
#if (PWM_CFG_H_SW_PATCH_VER != MCAL_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : PWM_SW_PATCH_VER "
#endif

#define PWM_PRECOMPILE_SUPPORT                   (STD_OFF)

#define PWM_DEV_ERROR_DETECT                     (STD_ON)
#define PWM_DEINIT_API                           (STD_ON)
#define PWM_SET_DUTY_CYCLE_API                   (STD_ON)
#define PWM_SET_PERIOD_AND_DUTY_API              (STD_ON)
#define PWM_GET_OUTPUT_STATE_API                 (STD_ON)
#define PWM_SET_OUTPUT_TO_IDLE_API               (STD_ON)
#define PWM_VERSION_INFO_API                     (STD_ON)
#define PWM_NOTIFICATION_SUPPORT                 (STD_ON)
#define PWM_DUTYCYCLE_UPDATED_ENDPERIOD          (STD_ON)
#define PWM_DUTY_PERIOD_UPDATED_ENDPERIOD        (STD_ON)
#define PWM_POWER_STATE_SUPPORTED                (STD_ON)
#define PWM_POWER_STATE_ASYNCH_MODE_SUPPORTED    (STD_OFF)

extern CONST(Pwm_ConfigType, PWM_CONST) Pwm_Config;

#define PWM_INLINE    LOCAL_INLINE



#define PwmChannel_MCU_PWMOUT_CON1                             ((Pwm_ChannelType) 0U)
#define PwmChannel_MCU_PWMOUT_CON2                             ((Pwm_ChannelType) 1U)
#define PwmChannel_MCU_PWMOUT_CON3                             ((Pwm_ChannelType) 2U)
#define PwmChannel_MCU_PWMOUT_CON4                             ((Pwm_ChannelType) 3U)
#define PwmChannel_MCU_PWMOUT_CON5                             ((Pwm_ChannelType) 4U)
#define PwmChannel_MCU_PWMOUT_CON6                             ((Pwm_ChannelType) 5U)
#define PwmChannel_MCU_PWMOUT_CON10                             ((Pwm_ChannelType) 6U)
#define PwmChannel_MCU_VrefPhase_OCP_N                             ((Pwm_ChannelType) 7U)
#define PwmChannel_MCU_VrefPhase_OCP_P                             ((Pwm_ChannelType) 8U)
#define PwmChannel_MCU_Vref_VDC                             ((Pwm_ChannelType) 9U)
#define PwmChannel_MCU_PWMOUT_CON7                             ((Pwm_ChannelType) 10U)
#define PwmChannel_MCU_PWMOUT_CON11                             ((Pwm_ChannelType) 11U)

#define PWM_PwmChannel_MCU_PWMOUT_CON1                             ((Pwm_ChannelType) 0U)
#define PWM_PwmChannel_MCU_PWMOUT_CON2                             ((Pwm_ChannelType) 1U)
#define PWM_PwmChannel_MCU_PWMOUT_CON3                             ((Pwm_ChannelType) 2U)
#define PWM_PwmChannel_MCU_PWMOUT_CON4                             ((Pwm_ChannelType) 3U)
#define PWM_PwmChannel_MCU_PWMOUT_CON5                             ((Pwm_ChannelType) 4U)
#define PWM_PwmChannel_MCU_PWMOUT_CON6                             ((Pwm_ChannelType) 5U)
#define PWM_PwmChannel_MCU_PWMOUT_CON10                             ((Pwm_ChannelType) 6U)
#define PWM_PwmChannel_MCU_VrefPhase_OCP_N                             ((Pwm_ChannelType) 7U)
#define PWM_PwmChannel_MCU_VrefPhase_OCP_P                             ((Pwm_ChannelType) 8U)
#define PWM_PwmChannel_MCU_Vref_VDC                             ((Pwm_ChannelType) 9U)
#define PWM_PwmChannel_MCU_PWMOUT_CON7                             ((Pwm_ChannelType) 10U)
#define PWM_PwmChannel_MCU_PWMOUT_CON11                             ((Pwm_ChannelType) 11U)

#define PwmConf_PwmChannel_PwmChannel_MCU_PWMOUT_CON1              ((Pwm_ChannelType) 0U)
#define PwmConf_PwmChannel_PwmChannel_MCU_PWMOUT_CON2              ((Pwm_ChannelType) 1U)
#define PwmConf_PwmChannel_PwmChannel_MCU_PWMOUT_CON3              ((Pwm_ChannelType) 2U)
#define PwmConf_PwmChannel_PwmChannel_MCU_PWMOUT_CON4              ((Pwm_ChannelType) 3U)
#define PwmConf_PwmChannel_PwmChannel_MCU_PWMOUT_CON5              ((Pwm_ChannelType) 4U)
#define PwmConf_PwmChannel_PwmChannel_MCU_PWMOUT_CON6              ((Pwm_ChannelType) 5U)
#define PwmConf_PwmChannel_PwmChannel_MCU_PWMOUT_CON10              ((Pwm_ChannelType) 6U)
#define PwmConf_PwmChannel_PwmChannel_MCU_VrefPhase_OCP_N              ((Pwm_ChannelType) 7U)
#define PwmConf_PwmChannel_PwmChannel_MCU_VrefPhase_OCP_P              ((Pwm_ChannelType) 8U)
#define PwmConf_PwmChannel_PwmChannel_MCU_Vref_VDC              ((Pwm_ChannelType) 9U)
#define PwmConf_PwmChannel_PwmChannel_MCU_PWMOUT_CON7              ((Pwm_ChannelType) 10U)
#define PwmConf_PwmChannel_PwmChannel_MCU_PWMOUT_CON11              ((Pwm_ChannelType) 11U)

#ifdef __cplusplus
}
#endif

#endif
