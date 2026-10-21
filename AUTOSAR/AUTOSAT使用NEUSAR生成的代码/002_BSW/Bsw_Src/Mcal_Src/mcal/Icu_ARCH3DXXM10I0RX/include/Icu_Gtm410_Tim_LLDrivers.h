/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC 
*   Peripheral           : ICU
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
*   @file    Icu_Gtm410_Tim_LLDrivers.h
*   @version 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
/* PRQA S 1535,0722 EOF */

#ifndef ICU_GTM_TIM_LLDRIVERS_H
#define ICU_GTM_TIM_LLDRIVERS_H

#ifdef __cplusplus
extern "C"
{
#endif

/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "derivative.h"
#include "status.h"
#include "Compiler.h"
#include "Gpt_Gtm_LLDriver.h"
#if (defined(RESOURCE_SUPPORT_GTM410))
#include "Icu_Cfg.h"
/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_GTM_TIM_LLDRIVERS_VENDOR_ID_H                   176

#define ICU_GTM_TIM_LLDRIVERS_MAJOR_VER_H                   4
#define ICU_GTM_TIM_LLDRIVERS_MINOR_VER_H                   4
#define ICU_GTM_TIM_LLDRIVERS_REVISION_VER_H                0

#define ICU_GTM_TIM_LLDRIVERS_SW_MAJOR_VER_H                3
#define ICU_GTM_TIM_LLDRIVERS_SW_MINOR_VER_H                0
#define ICU_GTM_TIM_LLDRIVERS_SW_PATCH_VER_H                0

#if (ICU_GTM_TIM_LLDRIVERS_VENDOR_ID_H != GPT_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_GTM_TIM_LLDRIVERS_MAJOR_VER_H != GPT_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_GTM_TIM_LLDRIVERS_MINOR_VER_H != GPT_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_GTM_TIM_LLDRIVERS_REVISION_VER_H != GPT_AR_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_GTM_TIM_LLDRIVERS_SW_MAJOR_VER_H != GPT_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_GTM_TIM_LLDRIVERS_SW_MINOR_VER_H != GPT_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_GTM_TIM_LLDRIVERS_SW_PATCH_VER_H != GPT_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
typedef enum
{
    Ch_0_H = 0,
    Ch_1_H,
    Ch_2_H,
    Ch_3_H,
    Ch_4_H,
    Ch_5_H,
    Ch_6_H,
    Ch_7_H,
    Ch_8_H,
    Ch_9_H,
    Ch_A_H,
    Ch_B_H,
    Ch_C_H,
    Ch_D_H,
    Ch_E_H,
    Ch_F_H
} GTM_TIM_Channel_Input_Selection_Type;

typedef enum
{
    GTM_TIM0 = 0x0U,
    GTM_TIM1 = 0x1U,
    GTM_TIM2 = 0x2U,
    GTM_TIM3 = 0x3U,
    GTM_TIM4 = 0x4U,
    GTM_TIM5 = 0x5U,
    GTM_TIM6 = 0x6U,
	GTM_TIM7 = 0x7U
} GTM_TIM_Type;

typedef enum
{
    GTM_TIM_CH0 = 0x0U,
    GTM_TIM_CH1 = 0x1U,
    GTM_TIM_CH2 = 0x2U,
    GTM_TIM_CH3 = 0x3U,
    GTM_TIM_CH4 = 0x4U,
    GTM_TIM_CH5 = 0x5U,
    GTM_TIM_CH6 = 0x6U,
    GTM_TIM_CH7 = 0x7U
} GTM_TIM_Channel_Type;

typedef enum
{
    TBU_TS0 = 0x0U,
    TBU_TS1 = 0x1U,
    TBU_TS2 = 0x2U,
    CNT = 0x3U
} GTM_TIM_GPRInput_Type;

typedef enum
{
    TIM_MODE_TPWM = 0x0U,
    TIM_MODE_TPIM = 0x1U,
    TIM_MODE_TIEM = 0x2U,
    TIM_MODE_TIPM = 0x3U,
    TIM_MODE_TBCM = 0x4U,
    TIM_MODE_TGPS = 0x5U,
	TIM_MODE_TSSM = 0x6U
} GTM_TIM_MODE_Type;

typedef enum
{
    TIM_TCS_CMU_CLK0 = 0x0U,
    TIM_TCS_CMU_CLK1 = 0x1U,
    TIM_TCS_CMU_CLK2 = 0x2U,
    TIM_TCS_CMU_CLK3 = 0x3U,
    TIM_TCS_CMU_CLK4 = 0x4U,
    TIM_TCS_CMU_CLK5 = 0x5U,
    TIM_TCS_CMU_CLK6 = 0x6U,
    TIM_TCS_CMU_CLK7 = 0x7U
} GTM_TIM_TimeoutClock_Type;

typedef enum
{
    TIM_Timeout_Disabled = 0x0U,
    TIM_Timeout_Enabled_Rising = 0x1U,
    TIM_Timeout_Enabled_Falling = 0x2U,
    TIM_Timeout_Enabled_Both = 0x3U
} GTM_TIM_TimeoutControl_Type;

typedef enum
{
    TIM_CLK_SEL_CMU_CLK0 = 0x0U,
    TIM_CLK_SEL_CMU_CLK1 = 0x1U,
    TIM_CLK_SEL_CMU_CLK2 = 0x2U,
    TIM_CLK_SEL_CMU_CLK3 = 0x3U,
    TIM_CLK_SEL_CMU_CLK4 = 0x4U,
    TIM_CLK_SEL_CMU_CLK5 = 0x5U,
    TIM_CLK_SEL_CMU_CLK6 = 0x6U,
    TIM_CLK_SEL_CMU_CLK7 = 0x7U
} GTM_TIM_CLK_SEL_Type;

typedef enum
{
    TIM_Up_Down_Counter = 0x0U,
    TIM_Hold_Counter = 0x1U
} GTM_TIM_FilterCounterMode_Type;

typedef enum
{
    TIM_Immediate_Propagation = 0x0U,
    TIM_Individual_Glitch = 0x1U
} GTM_TIM_FilterMode_Type;

typedef enum
{
    TIM_FLT_CNT_FRQ_CMU_CLK0 = 0x0U,
    TIM_FLT_CNT_FRQ_CMU_CLK1 = 0x1U,
    TIM_FLT_CNT_FRQ_CMU_CLK6 = 0x2U,
    TIM_FLT_CNT_FRQ_CMU_CLK7 = 0x3U
} GTM_TIM_FilterCounterFrequency_Type;

typedef enum
{
    TIM_IRQ_GLITCHDET = 0x0U,
    TIM_IRQ_TODET = 0x1U,
    TIM_IRQ_GPROFL = 0x2U,
    TIM_IRQ_CNTOFL = 0x3U,
    TIM_IRQ_ECNTOFL = 0x4U,
    TIM_IRQ_NEWVAL = 0x5U
} GTM_TIM_Interrupt_Type;

#define GTM4_TIM_RST_RST_CH0_OFF                    (0u)

#define GTM4_TIM_DET_ERR(x)                         DEV_ASSERT(x)

#define CH_IRQ_NOTIFY_MASK_GLITCHDET                ((uint32)(0x00000020U))
#define CH_IRQ_NOTIFY_MASK_TODET                    ((uint32)(0x00000010U))
#define CH_IRQ_NOTIFY_MASK_GPROFL                   ((uint32)(0x00000008U))
#define CH_IRQ_NOTIFY_MASK_CNTOFL                   ((uint32)(0x00000004U))
#define CH_IRQ_NOTIFY_MASK_ECNTOFL                  ((uint32)(0x00000002U))
#define CH_IRQ_NOTIFY_MASK_NEWVAL                   ((uint32)(0x00000001U))

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint32, ICU_CODE) GTM_TIM_LLD_Ch_GetGPR0Param \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint32, ICU_CODE) GTM_TIM_LLD_Ch_GetGPR1Parameter \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SelectClkSource \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TIM_CLK_SEL_Type, AUTOMATIC) ClockSource \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SelFLCountFall \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TIM_FilterCounterMode_Type, AUTOMATIC) FilterCounterMode \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SelFLCountRise \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TIM_FilterCounterMode_Type, AUTOMATIC) FilterCounterMode \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_ChSelFLModeFallEdge \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TIM_FilterMode_Type, AUTOMATIC) FilterMode \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_ChSelFLModeRiseEdge \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TIM_FilterMode_Type, AUTOMATIC) FilterMode \
); 
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_IsEnableFL \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SelectGPRInput \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TIM_GPRInput_Type, AUTOMATIC) GPR0, \
    VAR(GTM_TIM_GPRInput_Type, AUTOMATIC) GPR1 \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SetChannelMode \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TIM_MODE_Type, AUTOMATIC) TIM_MODE \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_IsEnableChannel \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint8, ICU_CODE) GTM_TIM_LLD_Ch_GetInterruptFlag \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TIM_Interrupt_Type, AUTOMATIC) Interrupt \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_ClearIntcFlag \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TIM_Interrupt_Type, AUTOMATIC) Interrupt \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_IsEnableIntc \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TIM_Interrupt_Type, AUTOMATIC) Interrupt, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_RstChannel \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SetFLCounFreq \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,  \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TIM_FilterCounterFrequency_Type, AUTOMATIC) FilterCounterFrequency \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint32_t, ICU_CODE) GTM_TIM_LLD_Channel_GetGPR0EdgeCounter \
( \
	    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,  \
	    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#ifdef RESOURCE_SUPPORT_GTM_TIMINPUTSEL
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_LLD_SetTimsel \
( \
	    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,  \
	    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,  \
        VAR(GTM_TIM_Channel_Input_Selection_Type, AUTOMATIC) TIMIN_SEL  \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif/* RESOURCE_SUPPORT_GTM_TIMINPUTSEL */

#endif /* (defined(RESOURCE_SUPPORT_GTM410)) */
#ifdef __cplusplus
}
#endif

#endif /* ICU_GTM_TIM_LLDRIVERS_H */
