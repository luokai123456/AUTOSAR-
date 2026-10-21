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
*   Autosar Revision     : 
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*  
*****************************************************************************/
/* PRQA S 2023,1821,4521,4543,4532 EOF */    /* QAC_CWE */
/**
*   @file    Icu_Gtm_Tim_LLDrivers.c
*   @version 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
/* PRQA S 3432, 0380, 2024, 4499, 4523 EOF */
/* PRQA S 2844, 1258, 2985, 4491, 2053 EOF */
/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#ifdef __cplusplus
extern "C"{
#endif
#include "Icu_Gtm410_Tim_LLDrivers.h"
#if (defined(RESOURCE_SUPPORT_GTM410))


/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_GTM_TIM_LLDRIVERS_VENDOR_ID_C                   176

#define ICU_GTM_TIM_LLDRIVERS_MAJOR_VER_C                   4
#define ICU_GTM_TIM_LLDRIVERS_MINOR_VER_C                   4
#define ICU_GTM_TIM_LLDRIVERS_REVISION_VER_C                0

#define ICU_GTM_TIM_LLDRIVERS_SW_MAJOR_VER_C                3
#define ICU_GTM_TIM_LLDRIVERS_SW_MINOR_VER_C                0
#define ICU_GTM_TIM_LLDRIVERS_SW_PATCH_VER_C                0

#if (ICU_GTM_TIM_LLDRIVERS_VENDOR_ID_C != ICU_GTM_TIM_LLDRIVERS_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_GTM_TIM_LLDRIVERS_MAJOR_VER_C != ICU_GTM_TIM_LLDRIVERS_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_GTM_TIM_LLDRIVERS_MINOR_VER_C != ICU_GTM_TIM_LLDRIVERS_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_GTM_TIM_LLDRIVERS_REVISION_VER_C != ICU_GTM_TIM_LLDRIVERS_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_GTM_TIM_LLDRIVERS_SW_MAJOR_VER_C != ICU_GTM_TIM_LLDRIVERS_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_GTM_TIM_LLDRIVERS_SW_MINOR_VER_C != ICU_GTM_TIM_LLDRIVERS_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_GTM_TIM_LLDRIVERS_SW_PATCH_VER_C != ICU_GTM_TIM_LLDRIVERS_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define GTM_TIM_0_BASE_ADDR                          (&GTM_TIM_0)
#define GTM_TIM_1_BASE_ADDR                          (&GTM_TIM_1)
#define GTM_TIM_2_BASE_ADDR                          (&GTM_TIM_2)
#define GTM_TIM_3_BASE_ADDR                          (&GTM_TIM_3)
#define GTM_TIM_4_BASE_ADDR                          (&GTM_TIM_4)
#define GTM_TIM_5_BASE_ADDR                          (&GTM_TIM_5)

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

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
)
{
    return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].GPR0.B.GPR0;/* polyspace RTE:NIV,OBAI */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


/*
 * @brief Get Input signal characteristic parameter 1.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 *
 * @result = Input signal characteristic parameter 1.
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint32, ICU_CODE) GTM_TIM_LLD_Ch_GetGPR1Parameter \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn \
)
{
    return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].GPR1.B.GPR1;/* polyspace RTE:NIV,OBAI */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


/*
 * @brief CMU clock source select for channel.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] ClockSource CMU clock source.
 *
 * @result = Operation status.
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SelectClkSource \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GTM_TIM_CLK_SEL_Type, AUTOMATIC) ClockSource \
)
{
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.CLK_SEL = (uint8_t)ClockSource;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.CLK_SEL != (uint8_t)ClockSource)
    {
        result = STATUS_ERROR;
    }

    return result;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/*
 * @brief Filter counter mode for falling edge.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] FilterCounterMode Filter counter mode.
 *
 * @result = Operation status.
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SelFLCountFall \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GTM_TIM_FilterCounterMode_Type, AUTOMATIC) FilterCounterMode \
)
{
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_CTR_FE = (uint8_t)FilterCounterMode;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_CTR_FE != (uint8_t)FilterCounterMode)
    {
        result = STATUS_ERROR;
    }

    return result;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/*
 * @brief Filter counter mode for rising edge.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] FilterCounterMode Filter counter mode.
 *
 * @result = Operation status.
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SelFLCountRise \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GTM_TIM_FilterCounterMode_Type, AUTOMATIC) FilterCounterMode \
)
{
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_CTR_RE = (uint8_t)FilterCounterMode;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_CTR_RE != (uint8_t)FilterCounterMode)
    {
        result = STATUS_ERROR;
    }

    return result;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/*
 * @brief Filter mode for falling edge.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] FilterMode Filter mode.
 *
 * @result = Operation status.
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_ChSelFLModeFallEdge \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GTM_TIM_FilterMode_Type, AUTOMATIC) FilterMode \
)
{
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_MODE_FE = (uint8_t)FilterMode;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_MODE_FE != (uint8_t)FilterMode)
    {
        result = STATUS_ERROR;
    }

    return result;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/*
 * @brief Filter mode for rising edge.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] FilterMode Filter mode.
 *
 * @result = Operation status.
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_ChSelFLModeRiseEdge \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GTM_TIM_FilterMode_Type, AUTOMATIC) FilterMode \
)
{
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_MODE_RE = (uint8_t)FilterMode;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_MODE_RE != (uint8_t)FilterMode)
    {
        result = STATUS_ERROR;
    }

    return result;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_IsEnableFL \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable \
)
{
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_EN = (uint8_t)IsEnable;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_EN != (uint8_t)IsEnable)
    {
        result = STATUS_ERROR;
    }

    return result;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/*
 * @brief Selection for GPR register.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] GPR0 GPR0 input type.
 * @param[in] GPR1 GPR1 input type.
 *
 * @result = Operation status.
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SelectGPRInput \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GTM_TIM_GPRInput_Type, AUTOMATIC) GPR0, \
	VAR(GTM_TIM_GPRInput_Type, AUTOMATIC) GPR1 \
)
{
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.GPR0_SEL = (uint8_t)GPR0;
    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.GPR1_SEL = (uint8_t)GPR1;
    if((GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.GPR0_SEL != (uint8_t)GPR0) || (GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.GPR1_SEL != (uint8_t)GPR1))
    {
        result = STATUS_ERROR;
    }

    return result;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/*
 * @brief TIM channel n mode.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] TIM_MODE TIM mode.
 *
 * @result = Operation status.
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SetChannelMode \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GTM_TIM_MODE_Type, AUTOMATIC) TIM_MODE \
)
{
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.TIM_MODE = (uint8_t)TIM_MODE;/* polyspace RTE:OBAI */
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.TIM_MODE != (uint8_t)TIM_MODE)
    {
        result = STATUS_ERROR;
    }

    return result;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/*
 * @brief TIM channel n enable.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable Enable status.
 *
 * @result = Operation status.
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_IsEnableChannel \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable \
)
{
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.TIM_EN = (uint8_t)IsEnable;/* polyspace RTE:OBAI */
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.TIM_EN != (uint8_t)IsEnable)/* polyspace RTE:NIV,OBAI */
    {
        result = STATUS_ERROR;
    }

    return result;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/*
 * @brief Get Interrupt Flag.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] Interrupt Interrupt type.
 *
 * @result = Interrupt Flag.
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint8, ICU_CODE) GTM_TIM_LLD_Ch_GetInterruptFlag \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GTM_TIM_Interrupt_Type, AUTOMATIC) Interrupt \
)
{
    switch(Interrupt)
    {
        case TIM_IRQ_GLITCHDET:
            return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.GLITCHDET;

        case TIM_IRQ_TODET:
            return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.TODET;

        case TIM_IRQ_GPROFL:
            return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.GPROFL;

        case TIM_IRQ_CNTOFL:
            return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.CNTOFL;/* polyspace RTE:NIV,OBAI */

        case TIM_IRQ_ECNTOFL:
            return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.ECNTOFL;

        case TIM_IRQ_NEWVAL:
            return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.NEWVAL;/* polyspace RTE:NIV,OBAI */

        default:
            /* nothing to do */
                break;
    }
    return 0U;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/*
 * @brief Clear Interrupt Flag.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] Interrupt Interrupt type.
 *
 * @result =  Operation status.
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_ClearIntcFlag \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GTM_TIM_Interrupt_Type, AUTOMATIC) Interrupt \
)
{
    switch(Interrupt)
    {
        case TIM_IRQ_GLITCHDET:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.R = CH_IRQ_NOTIFY_MASK_GLITCHDET;
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.GLITCHDET != 0u)
            {
                return STATUS_ERROR;
            }
        break;
        case TIM_IRQ_TODET:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.R = CH_IRQ_NOTIFY_MASK_TODET;
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.TODET != 0u)
            {
                return STATUS_ERROR;
            }
        break;
        case TIM_IRQ_GPROFL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.R = CH_IRQ_NOTIFY_MASK_GPROFL;
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.GPROFL != 0u)
            {
                return STATUS_ERROR;
            }
        break;
        case TIM_IRQ_CNTOFL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.R = CH_IRQ_NOTIFY_MASK_CNTOFL;
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.CNTOFL != 0u)
            {
                return STATUS_ERROR;
            }
        break;
        case TIM_IRQ_ECNTOFL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.R = CH_IRQ_NOTIFY_MASK_ECNTOFL;
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.ECNTOFL != 0u)
            {
                return STATUS_ERROR;
            }
        break;
        case TIM_IRQ_NEWVAL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.R = CH_IRQ_NOTIFY_MASK_NEWVAL;/* polyspace RTE:OBAI */
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.NEWVAL != 0u)/* polyspace RTE:NIV */
            {
                return STATUS_ERROR;
            }
        break;
        default:
            return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/*
 * @brief TIM_TODETn_IRQ interrupt enable.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable Enable status.
 *
 * @result = Operation status.
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_IsEnableIntc \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GTM_TIM_Interrupt_Type, AUTOMATIC) Interrupt, \
	VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable \
)
{
    switch(Interrupt)
    {
        case TIM_IRQ_GLITCHDET:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.GLITCHDET_IRQ_EN = (uint8_t)IsEnable;
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.GLITCHDET_IRQ_EN != (uint8_t)IsEnable)
            {
                return STATUS_ERROR;
            }
        break;
        case TIM_IRQ_TODET:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.TODET_IRQ_EN = (uint8_t)IsEnable;
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.TODET_IRQ_EN != (uint8_t)IsEnable)
            {
                return STATUS_ERROR;
            }
        break;
        case TIM_IRQ_GPROFL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.GPROFL_IRQ_EN = (uint8_t)IsEnable;
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.GPROFL_IRQ_EN != (uint8_t)IsEnable)
            {
                return STATUS_ERROR;
            }
        break;
        case TIM_IRQ_CNTOFL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.CNTOFL_IRQ_EN =(uint8_t)IsEnable;
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.CNTOFL_IRQ_EN != (uint8_t)IsEnable)
            {
                return STATUS_ERROR;
            }
        break;
        case TIM_IRQ_ECNTOFL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.ECNTOFL_IRQ_EN = (uint8_t)IsEnable;
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.ECNTOFL_IRQ_EN != (uint8_t)IsEnable)
            {
                return STATUS_ERROR;
            }
        break;
        case TIM_IRQ_NEWVAL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.NEWVAL_IRQ_EN = (uint8_t)IsEnable;/* polyspace RTE:OBAI */
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.NEWVAL_IRQ_EN != (uint8_t)IsEnable)/* polyspace RTE:NIV */
            {
                return STATUS_ERROR;
            }
        break;
        default:
        /* nothing to do */
        break;
    }

    return STATUS_SUCCESS;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/*
 * @brief Software reset of channel.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 *
 * @result =  Operation status.
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_RstChannel \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn \
)
{
    uint8 shift = ((uint8)CHn % 8u) + (uint8)GTM4_TIM_RST_RST_CH0_OFF;

    GTM4.GLS[GTM_TIMn].TIM.RST.R = (1U << shift);/* polyspace RTE:OBAI */

    return STATUS_SUCCESS;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SetFLCounFreq \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,  \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GTM_TIM_FilterCounterFrequency_Type, AUTOMATIC) FilterCounterFrequency \
)
{
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_CNT_FRQ = (uint8_t)FilterCounterFrequency;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_CNT_FRQ != (uint8_t)FilterCounterFrequency)
    {
        result = STATUS_ERROR;
    }

    return result;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/*
 * @brief Get Edge counter.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 *
 * @return Edge counter.
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint32_t, ICU_CODE) GTM_TIM_LLD_Channel_GetGPR0EdgeCounter(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn)
{
    return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].GPR0.B.ECNT;/* polyspace RTE:NIV,OBAI */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#ifdef RESOURCE_SUPPORT_GTM_TIMINPUTSEL
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_LLD_SetTimsel
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(GTM_TIM_Channel_Input_Selection_Type, AUTOMATIC) TIMIN_SEL
)
{
    VAR(uint32, AUTOMATIC) current_value;

	current_value = GTM4.GLS[0].TIMINSEL[GTM_TIMn].R;/* polyspace RTE:OBAI */

	current_value &= ~(0xF << (CHn * 4u));/* polyspace RTE:SHF,OVFL */

	current_value |= (TIMIN_SEL << (CHn * 4u));

	GTM4.GLS[0].TIMINSEL[GTM_TIMn].R = current_value;

    return STATUS_SUCCESS;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif/* RESOURCE_SUPPORT_GTM_TIMINPUTSEL */

#endif /* RESOURCE_SUPPORT_GTM410 */
#ifdef __cplusplus
}
#endif
