/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : PWM
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
*   @file    Pwm_AutoSar_Wrapper.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Pwm MCAL driver.
*
*   @addtogroup Pwm
*   @{
*/

#ifndef PWM_AUTOSAR_WRAPPER_H
#define PWM_AUTOSAR_WRAPPER_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Pwm_HAL_Wrapper.h"
#include "Pwm_Cfg.h"

#define PWM_ATS_WRA_H_VENDOR_ID                      176
#define PWM_ATS_WRA_H_AR_REL_MAJOR_VER               4
#define PWM_ATS_WRA_H_AR_REL_MINOR_VER               4
#define PWM_ATS_WRA_H_AR_REL_REV_VER                 0
#define PWM_ATS_WRA_H_SW_MAJOR_VER                   3
#define PWM_ATS_WRA_H_SW_MINOR_VER                   0
#define PWM_ATS_WRA_H_SW_PATCH_VER                   0

#if (PWM_ATS_WRA_H_VENDOR_ID != PWM_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : PWM_ATS_WRA_H_VENDOR_ID "
#endif
#if (PWM_ATS_WRA_H_AR_REL_MAJOR_VER != PWM_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_ATS_WRA_H_AR_REL_MAJOR_VER "
#endif
#if (PWM_ATS_WRA_H_AR_REL_MINOR_VER != PWM_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_ATS_WRA_H_AR_REL_MINOR_VER "
#endif
#if (PWM_ATS_WRA_H_AR_REL_REV_VER != PWM_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : PWM_ATS_WRA_H_AR_REL_REV_VER "
#endif
#if (PWM_ATS_WRA_H_SW_MAJOR_VER != PWM_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_ATS_WRA_H_SW_MAJOR_VER "
#endif
#if (PWM_ATS_WRA_H_SW_MINOR_VER != PWM_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_ATS_WRA_H_SW_MINOR_VER "
#endif
#if (PWM_ATS_WRA_H_SW_PATCH_VER != PWM_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : PWM_ATS_WRA_H_SW_PATCH_VER "
#endif

#define Pwm_AutoSar_Wrapper_Init      Pwm_Wrapper_Init
#define Pwm_AutoSar_Wrapper_DeInit    Pwm_Wrapper_DeInit
#define Pwm_AutoSar_Wrapper_SetDuty   Pwm_Wrapper_SetDutyCycle
#define Pwm_AutoSar_Wrapper_SetPAndD  Pwm_Wrapper_SetPeriodAndDuty
#define Pwm_AutoSar_Wrapper_SetIdle   Pwm_Wrapper_SetOutputToIdle
#define Pwm_AutoSar_Wrapper_GetOutput Pwm_Wrapper_GetOutputState
#define Pwm_AutoSar_Wrapper_DiNotifi  Pwm_Wrapper_DisableNotification
#define Pwm_AutoSar_Wrapper_EnNotifi  Pwm_Wrapper_EnableNotification
#define Pwm_AutoSar_Wrapper_CheckD    Pwm_Wrapper_Check_DutyCycle
#define Pwm_AutoSar_Wrapper_CheckP_D  Pwm_Wrapper_Check_PeriodAndDuty
#define Pwm_AutoSar_Wrapper_MaxD      Pwm_Wrapper_Get_MaxDutycycle

#ifdef __cplusplus
}
#endif

#endif
