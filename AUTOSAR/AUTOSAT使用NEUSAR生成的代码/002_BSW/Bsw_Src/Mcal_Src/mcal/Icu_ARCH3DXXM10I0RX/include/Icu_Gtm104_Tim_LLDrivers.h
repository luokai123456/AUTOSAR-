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
*   @file    Icu_Gtm104_Tim_LLDrivers.h
*   @version 3.0.0 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
/* PRQA S 1535 EOF */

#ifndef ICU_GTM_TIM_LLDRIVERS_H
#define ICU_GTM_TIM_LLDRIVERS_H

#ifdef __cplusplus
extern "C"
{
#endif
/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "status.h"
#include "Gpt_Gtm_LLDriver.h"
#if (defined(RESOURCE_SUPPORT_GTM104))
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

#if (ICU_GTM_TIM_LLDRIVERS_VENDOR_ID_H != ICU_VENDOR_ID_CFG)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_GTM_TIM_LLDRIVERS_MAJOR_VER_H != ICU_AR_RELEASE_MAJOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_GTM_TIM_LLDRIVERS_MINOR_VER_H != ICU_AR_RELEASE_MINOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_GTM_TIM_LLDRIVERS_REVISION_VER_H != ICU_AR_RELEASE_REVISION_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_GTM_TIM_LLDRIVERS_SW_MAJOR_VER_H != ICU_SW_MAJOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_GTM_TIM_LLDRIVERS_SW_MINOR_VER_H != ICU_SW_MINOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_GTM_TIM_LLDRIVERS_SW_PATCH_VER_H != ICU_SW_PATCH_VERSION_CFG)
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
#define GTM_TIM_0_BASE_ADDR                          (&GTM_TIM_0)
#define GTM_TIM_1_BASE_ADDR                          (&GTM_TIM_1)
#define GTM_TIM_2_BASE_ADDR                          (&GTM_TIM_2)
#define GTM_TIM_3_BASE_ADDR                          (&GTM_TIM_3)
#define GTM_TIM_4_BASE_ADDR                          (&GTM_TIM_4)
#define GTM_TIM_5_BASE_ADDR                          (&GTM_TIM_5)


#define CH0_IRQ_NOTIFY_MASK_GLITCHDET                (0x00000020U)
#define CH0_IRQ_NOTIFY_MASK_TODET                    (0x00000010U)
#define CH0_IRQ_NOTIFY_MASK_GPROFL                   (0x00000008U)
#define CH0_IRQ_NOTIFY_MASK_CNTOFL                   (0x00000004U)
#define CH0_IRQ_NOTIFY_MASK_ECNTOFL                  (0x00000002U)
#define CH0_IRQ_NOTIFY_MASK_NEWVAL                   (0x00000001U)

#define CH1_IRQ_NOTIFY_MASK_GLITCHDET                (0x00000020U)
#define CH1_IRQ_NOTIFY_MASK_TODET                    (0x00000010U)
#define CH1_IRQ_NOTIFY_MASK_GPROFL                   (0x00000008U)
#define CH1_IRQ_NOTIFY_MASK_CNTOFL                   (0x00000004U)
#define CH1_IRQ_NOTIFY_MASK_ECNTOFL                  (0x00000002U)
#define CH1_IRQ_NOTIFY_MASK_NEWVAL                   (0x00000001U)

#define CH2_IRQ_NOTIFY_MASK_GLITCHDET                (0x00000020U)
#define CH2_IRQ_NOTIFY_MASK_TODET                    (0x00000010U)
#define CH2_IRQ_NOTIFY_MASK_GPROFL                   (0x00000008U)
#define CH2_IRQ_NOTIFY_MASK_CNTOFL                   (0x00000004U)
#define CH2_IRQ_NOTIFY_MASK_ECNTOFL                  (0x00000002U)
#define CH2_IRQ_NOTIFY_MASK_NEWVAL                   (0x00000001U)

#define CH3_IRQ_NOTIFY_MASK_GLITCHDET                (0x00000020U)
#define CH3_IRQ_NOTIFY_MASK_TODET                    (0x00000010U)
#define CH3_IRQ_NOTIFY_MASK_GPROFL                   (0x00000008U)
#define CH3_IRQ_NOTIFY_MASK_CNTOFL                   (0x00000004U)
#define CH3_IRQ_NOTIFY_MASK_ECNTOFL                  (0x00000002U)
#define CH3_IRQ_NOTIFY_MASK_NEWVAL                   (0x00000001U)

#define CH4_IRQ_NOTIFY_MASK_GLITCHDET                (0x00000020U)
#define CH4_IRQ_NOTIFY_MASK_TODET                    (0x00000010U)
#define CH4_IRQ_NOTIFY_MASK_GPROFL                   (0x00000008U)
#define CH4_IRQ_NOTIFY_MASK_CNTOFL                   (0x00000004U)
#define CH4_IRQ_NOTIFY_MASK_ECNTOFL                  (0x00000002U)
#define CH4_IRQ_NOTIFY_MASK_NEWVAL                   (0x00000001U)

#define CH5_IRQ_NOTIFY_MASK_GLITCHDET                (0x00000020U)
#define CH5_IRQ_NOTIFY_MASK_TODET                    (0x00000010U)
#define CH5_IRQ_NOTIFY_MASK_GPROFL                   (0x00000008U)
#define CH5_IRQ_NOTIFY_MASK_CNTOFL                   (0x00000004U)
#define CH5_IRQ_NOTIFY_MASK_ECNTOFL                  (0x00000002U)
#define CH5_IRQ_NOTIFY_MASK_NEWVAL                   (0x00000001U)

#define CH6_IRQ_NOTIFY_MASK_GLITCHDET                (0x00000020U)
#define CH6_IRQ_NOTIFY_MASK_TODET                    (0x00000010U)
#define CH6_IRQ_NOTIFY_MASK_GPROFL                   (0x00000008U)
#define CH6_IRQ_NOTIFY_MASK_CNTOFL                   (0x00000004U)
#define CH6_IRQ_NOTIFY_MASK_ECNTOFL                  (0x00000002U)
#define CH6_IRQ_NOTIFY_MASK_NEWVAL                   (0x00000001U)

#define CH7_IRQ_NOTIFY_MASK_GLITCHDET                (0x00000020U)
#define CH7_IRQ_NOTIFY_MASK_TODET                    (0x00000010U)
#define CH7_IRQ_NOTIFY_MASK_GPROFL                   (0x00000008U)
#define CH7_IRQ_NOTIFY_MASK_CNTOFL                   (0x00000004U)
#define CH7_IRQ_NOTIFY_MASK_ECNTOFL                  (0x00000002U)
#define CH7_IRQ_NOTIFY_MASK_NEWVAL                   (0x00000001U)

typedef volatile struct GTM_TIM_tag st_GTM_TIM_tag;
typedef enum
{
    GTM_TIM0 = 0x0U,
    GTM_TIM1 = 0x1U,
    GTM_TIM2 = 0x2U,
    GTM_TIM3 = 0x3U,
    GTM_TIM4 = 0x4U,
    GTM_TIM5 = 0x5U
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
    TIM_MODE_TBCM = 0x4U
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

#endif /* (defined(RESOURCE_SUPPORT_GTM104)) */
#ifdef __cplusplus
}
#endif

#endif /* ICU_GTM_TIM_LLDRIVERS_H */
