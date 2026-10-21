/****************************************************************************
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
*   @file    Pwm_AutoSar_Wrapper.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Pwm MCAL driver.
*
*   @addtogroup Pwm
*   @{
*/

#include "Pwm_AutoSar_Wrapper.h" /* PRQA S 0380 */
#include "Pwm_Cfg.h"

#define PWM_ATS_WRA_C_VENDOR_ID                      176
#define PWM_ATS_WRA_C_AR_REL_MAJOR_VER               4
#define PWM_ATS_WRA_C_AR_REL_MINOR_VER               4
#define PWM_ATS_WRA_C_AR_REL_REV_VER                 0
#define PWM_ATS_WRA_C_SW_MAJOR_VER                   3
#define PWM_ATS_WRA_C_SW_MINOR_VER                   0
#define PWM_ATS_WRA_C_SW_PATCH_VER                   0

#if (PWM_ATS_WRA_C_VENDOR_ID != PWM_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : PWM_ATS_WRA_C_VENDOR_ID "
#endif
#if (PWM_ATS_WRA_C_AR_REL_MAJOR_VER != PWM_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_ATS_WRA_C_AR_REL_MAJOR_VER "
#endif
#if (PWM_ATS_WRA_C_AR_REL_MINOR_VER != PWM_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_ATS_WRA_C_AR_REL_MINOR_VER "
#endif
#if (PWM_ATS_WRA_C_AR_REL_REV_VER != PWM_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : PWM_ATS_WRA_C_AR_REL_REV_VER "
#endif
#if (PWM_ATS_WRA_C_SW_MAJOR_VER != PWM_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_ATS_WRA_C_SW_MAJOR_VER "
#endif
#if (PWM_ATS_WRA_C_SW_MINOR_VER != PWM_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_ATS_WRA_C_SW_MINOR_VER "
#endif
#if (PWM_ATS_WRA_C_SW_PATCH_VER != PWM_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : PWM_ATS_WRA_C_SW_PATCH_VER "
#endif

