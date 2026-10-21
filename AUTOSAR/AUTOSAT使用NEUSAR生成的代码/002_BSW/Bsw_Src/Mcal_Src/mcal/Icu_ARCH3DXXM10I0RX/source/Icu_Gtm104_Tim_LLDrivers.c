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
/* PRQA S 2023 EOF */    /* QAC_CWE */
/**
*   @file    Icu_Gtm_Tim_LLDrivers.c
*   @version 3.0.0 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
/* PRQA S 3432, 0380 EOF */
/* PRQA S 2844 EOF */
/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#ifdef __cplusplus
extern "C"{
#endif
#include "Icu_Gtm104_Tim_LLDrivers.h"
#if (defined(RESOURCE_SUPPORT_GTM104))


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
#define ICU_START_SEC_VAR_INIT
#include "Icu_MemMap.h"
static st_GTM_TIM_tag* g_GTM_TIM_Base[6U] = \
{ \
    GTM_TIM_0_BASE_ADDR, \
    GTM_TIM_1_BASE_ADDR, \
    GTM_TIM_2_BASE_ADDR, \
    GTM_TIM_3_BASE_ADDR, \
    GTM_TIM_4_BASE_ADDR, \
    GTM_TIM_5_BASE_ADDR \
}; 
#define ICU_STOP_SEC_VAR_INIT
#include "Icu_MemMap.h"
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
    P2CONST(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_CONST) GTM_TIM_Reg_n = g_GTM_TIM_Base[GTM_TIMn];/* polyspace RTE:OBAI */
    VAR(uint32, AUTOMATIC) result = 0U;
    switch(CHn)
    {
    case GTM_TIM_CH0:
    {
    	result = GTM_TIM_Reg_n->CH0_GPR0.B.GPR0;/* polyspace RTE:NIV */
    	break;
    }
    case GTM_TIM_CH1:
    {
    	result = GTM_TIM_Reg_n->CH1_GPR0.B.GPR0;/* polyspace RTE:NIV */
    	break;
    }
    case GTM_TIM_CH2:
    {
    	result = GTM_TIM_Reg_n->CH2_GPR0.B.GPR0;/* polyspace RTE:NIV */
    	break;
    }
    case GTM_TIM_CH3:
    {
    	result = GTM_TIM_Reg_n->CH3_GPR0.B.GPR0;/* polyspace RTE:NIV */
    	break;
    }
    case GTM_TIM_CH4:
    {
    	result = GTM_TIM_Reg_n->CH4_GPR0.B.GPR0;/* polyspace RTE:NIV */
    	break;
    }
    case GTM_TIM_CH5:
    {
    	result = GTM_TIM_Reg_n->CH5_GPR0.B.GPR0;/* polyspace RTE:NIV */
    	break;
    }
    case GTM_TIM_CH6:
    {
    	result = GTM_TIM_Reg_n->CH6_GPR0.B.GPR0;/* polyspace RTE:NIV */
    	break;
    }
    case GTM_TIM_CH7:
    {
    	result = GTM_TIM_Reg_n->CH7_GPR0.B.GPR0;/* polyspace RTE:NIV */
    	break;
    }
    default:
    {
    	/*nothing*/
        break;
    }
    }
    return result;
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
    P2CONST(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_CONST) GTM_TIM_Reg_n = g_GTM_TIM_Base[GTM_TIMn];/* polyspace RTE:OBAI */
    VAR(uint32, AUTOMATIC) result = 0U;
    switch(CHn)
    {
    case GTM_TIM_CH0:
    {
    	result = GTM_TIM_Reg_n->CH0_GPR1.B.GPR1;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH1:
    {
        result = GTM_TIM_Reg_n->CH1_GPR1.B.GPR1;/* polyspace RTE:NIV */
    	break;
    }
    case GTM_TIM_CH2:
    {
        result = GTM_TIM_Reg_n->CH2_GPR1.B.GPR1;/* polyspace RTE:NIV */
    	break;
    }
    case GTM_TIM_CH3:
    {
        result = GTM_TIM_Reg_n->CH3_GPR1.B.GPR1;/* polyspace RTE:NIV */
    	break;
    }
    case GTM_TIM_CH4:
    {
        result = GTM_TIM_Reg_n->CH4_GPR1.B.GPR1;/* polyspace RTE:NIV */
    	break;
    }
    case GTM_TIM_CH5:
    {
        result = GTM_TIM_Reg_n->CH5_GPR1.B.GPR1;/* polyspace RTE:NIV */
    	break;
    }
    case GTM_TIM_CH6:
    {
        result = GTM_TIM_Reg_n->CH6_GPR1.B.GPR1;/* polyspace RTE:NIV */
    	break;
    }
    case GTM_TIM_CH7:
    {
        result = GTM_TIM_Reg_n->CH7_GPR1.B.GPR1;/* polyspace RTE:NIV */
    	break;
    }
    default:
    {
    	/*nothing*/
        break;
    }
    }
    return result;
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
	P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_CONST) GTM_TIM_Reg_n = g_GTM_TIM_Base[GTM_TIMn];
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

	switch(CHn)
	{
	case GTM_TIM_CH0:
	{
		GTM_TIM_Reg_n->CH0_CTRL.B.CLK_SEL = (uint8)ClockSource;
		if(GTM_TIM_Reg_n->CH0_CTRL.B.CLK_SEL != (uint8)ClockSource)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH1:
	{
		GTM_TIM_Reg_n->CH1_CTRL.B.CLK_SEL = (uint8)ClockSource;
		if(GTM_TIM_Reg_n->CH1_CTRL.B.CLK_SEL != (uint8)ClockSource)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH2:
	{
		GTM_TIM_Reg_n->CH2_CTRL.B.CLK_SEL = (uint8)ClockSource;
		if(GTM_TIM_Reg_n->CH2_CTRL.B.CLK_SEL != (uint8)ClockSource)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH3:
	{
		GTM_TIM_Reg_n->CH3_CTRL.B.CLK_SEL = (uint8)ClockSource;
		if(GTM_TIM_Reg_n->CH3_CTRL.B.CLK_SEL != (uint8)ClockSource)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH4:
	{
		GTM_TIM_Reg_n->CH4_CTRL.B.CLK_SEL = (uint8)ClockSource;
		if(GTM_TIM_Reg_n->CH4_CTRL.B.CLK_SEL != (uint8)ClockSource)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH5:
	{
		GTM_TIM_Reg_n->CH5_CTRL.B.CLK_SEL = (uint8)ClockSource;
		if(GTM_TIM_Reg_n->CH5_CTRL.B.CLK_SEL != (uint8)ClockSource)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH6:
	{
		GTM_TIM_Reg_n->CH6_CTRL.B.CLK_SEL = (uint8)ClockSource;
		if(GTM_TIM_Reg_n->CH6_CTRL.B.CLK_SEL != (uint8)ClockSource)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH7:
	{
		GTM_TIM_Reg_n->CH7_CTRL.B.CLK_SEL = (uint8)ClockSource;
		if(GTM_TIM_Reg_n->CH7_CTRL.B.CLK_SEL != (uint8)ClockSource)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	default:
	{
		/*nothing*/
		result = STATUS_ERROR;
    	break;
	}
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
	P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_CONST) GTM_TIM_Reg_n = g_GTM_TIM_Base[GTM_TIMn];
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

	switch(CHn)
	{
	case GTM_TIM_CH0:
	{
		GTM_TIM_Reg_n->CH0_CTRL.B.FLT_CTR_FE = (uint8)FilterCounterMode;
		if(GTM_TIM_Reg_n->CH0_CTRL.B.FLT_CTR_FE != (uint8)FilterCounterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH1:
	{
		GTM_TIM_Reg_n->CH1_CTRL.B.FLT_CTR_FE = (uint8)FilterCounterMode;
		if(GTM_TIM_Reg_n->CH1_CTRL.B.FLT_CTR_FE != (uint8)FilterCounterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH2:
	{
		GTM_TIM_Reg_n->CH2_CTRL.B.FLT_CTR_FE = (uint8)FilterCounterMode;
		if(GTM_TIM_Reg_n->CH2_CTRL.B.FLT_CTR_FE != (uint8)FilterCounterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH3:
	{
		GTM_TIM_Reg_n->CH3_CTRL.B.FLT_CTR_FE = (uint8)FilterCounterMode;
		if(GTM_TIM_Reg_n->CH3_CTRL.B.FLT_CTR_FE != (uint8)FilterCounterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH4:
	{
		GTM_TIM_Reg_n->CH4_CTRL.B.FLT_CTR_FE = (uint8)FilterCounterMode;
		if(GTM_TIM_Reg_n->CH4_CTRL.B.FLT_CTR_FE != (uint8)FilterCounterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH5:
	{
		GTM_TIM_Reg_n->CH5_CTRL.B.FLT_CTR_FE = (uint8)FilterCounterMode;
		if(GTM_TIM_Reg_n->CH5_CTRL.B.FLT_CTR_FE != (uint8)FilterCounterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH6:
	{
		GTM_TIM_Reg_n->CH6_CTRL.B.FLT_CTR_FE = (uint8)FilterCounterMode;
		if(GTM_TIM_Reg_n->CH6_CTRL.B.FLT_CTR_FE != (uint8)FilterCounterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH7:
	{
		GTM_TIM_Reg_n->CH7_CTRL.B.FLT_CTR_FE = (uint8)FilterCounterMode;
		if(GTM_TIM_Reg_n->CH7_CTRL.B.FLT_CTR_FE != (uint8)FilterCounterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	default:
	{
		/*nothing*/
		result = STATUS_ERROR;
    	break;
	}
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
	P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_CONST) GTM_TIM_Reg_n = g_GTM_TIM_Base[GTM_TIMn];
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

	switch(CHn)
	{
	case GTM_TIM_CH0:
	{
		GTM_TIM_Reg_n->CH0_CTRL.B.FLT_CTR_RE = (uint8)FilterCounterMode;
		if(GTM_TIM_Reg_n->CH0_CTRL.B.FLT_CTR_RE != (uint8)FilterCounterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH1:
	{
		GTM_TIM_Reg_n->CH1_CTRL.B.FLT_CTR_RE = (uint8)FilterCounterMode;
		if(GTM_TIM_Reg_n->CH1_CTRL.B.FLT_CTR_RE != (uint8)FilterCounterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH2:
	{
		GTM_TIM_Reg_n->CH2_CTRL.B.FLT_CTR_RE = (uint8)FilterCounterMode;
		if(GTM_TIM_Reg_n->CH2_CTRL.B.FLT_CTR_RE != (uint8)FilterCounterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH3:
	{
		GTM_TIM_Reg_n->CH3_CTRL.B.FLT_CTR_RE = (uint8)FilterCounterMode;
		if(GTM_TIM_Reg_n->CH3_CTRL.B.FLT_CTR_RE != (uint8)FilterCounterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH4:
	{
		GTM_TIM_Reg_n->CH4_CTRL.B.FLT_CTR_RE = (uint8)FilterCounterMode;
		if(GTM_TIM_Reg_n->CH4_CTRL.B.FLT_CTR_RE != (uint8)FilterCounterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH5:
	{
		GTM_TIM_Reg_n->CH5_CTRL.B.FLT_CTR_RE = (uint8)FilterCounterMode;
		if(GTM_TIM_Reg_n->CH5_CTRL.B.FLT_CTR_RE != (uint8)FilterCounterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH6:
	{
		GTM_TIM_Reg_n->CH6_CTRL.B.FLT_CTR_RE = (uint8)FilterCounterMode;
		if(GTM_TIM_Reg_n->CH6_CTRL.B.FLT_CTR_RE != (uint8)FilterCounterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH7:
	{
		GTM_TIM_Reg_n->CH7_CTRL.B.FLT_CTR_RE = (uint8)FilterCounterMode;
		if(GTM_TIM_Reg_n->CH7_CTRL.B.FLT_CTR_RE != (uint8)FilterCounterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	default:
	{
		/*nothing*/
		result = STATUS_ERROR;
    	break;
	}
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
	P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_CONST) GTM_TIM_Reg_n = g_GTM_TIM_Base[GTM_TIMn];
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

	switch(CHn)
	{
	case GTM_TIM_CH0:
	{
		GTM_TIM_Reg_n->CH0_CTRL.B.FLT_MODE_FE = (uint8)FilterMode;
		if(GTM_TIM_Reg_n->CH0_CTRL.B.FLT_MODE_FE != (uint8)FilterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH1:
	{
		GTM_TIM_Reg_n->CH1_CTRL.B.FLT_MODE_FE = (uint8)FilterMode;
		if(GTM_TIM_Reg_n->CH1_CTRL.B.FLT_MODE_FE != (uint8)FilterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH2:
	{
		GTM_TIM_Reg_n->CH2_CTRL.B.FLT_MODE_FE = (uint8)FilterMode;
		if(GTM_TIM_Reg_n->CH2_CTRL.B.FLT_MODE_FE != (uint8)FilterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH3:
	{
		GTM_TIM_Reg_n->CH3_CTRL.B.FLT_MODE_FE = (uint8)FilterMode;
		if(GTM_TIM_Reg_n->CH3_CTRL.B.FLT_MODE_FE != (uint8)FilterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH4:
	{
		GTM_TIM_Reg_n->CH4_CTRL.B.FLT_MODE_FE = (uint8)FilterMode;
		if(GTM_TIM_Reg_n->CH4_CTRL.B.FLT_MODE_FE != (uint8)FilterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH5:
	{
		GTM_TIM_Reg_n->CH5_CTRL.B.FLT_MODE_FE = (uint8)FilterMode;
		if(GTM_TIM_Reg_n->CH5_CTRL.B.FLT_MODE_FE != (uint8)FilterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH6:
	{
		GTM_TIM_Reg_n->CH6_CTRL.B.FLT_MODE_FE = (uint8)FilterMode;
		if(GTM_TIM_Reg_n->CH6_CTRL.B.FLT_MODE_FE != (uint8)FilterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH7:
	{
		GTM_TIM_Reg_n->CH7_CTRL.B.FLT_MODE_FE = (uint8)FilterMode;
		if(GTM_TIM_Reg_n->CH7_CTRL.B.FLT_MODE_FE != (uint8)FilterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	default:
	{
		/*nothing*/
		result = STATUS_ERROR;
    	break;
	}
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
	P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_CONST) GTM_TIM_Reg_n = g_GTM_TIM_Base[GTM_TIMn];
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

	switch(CHn)
	{
	case GTM_TIM_CH0:
	{
		GTM_TIM_Reg_n->CH0_CTRL.B.FLT_MODE_RE = (uint8)FilterMode;
		if(GTM_TIM_Reg_n->CH0_CTRL.B.FLT_MODE_RE != (uint8)FilterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH1:
	{
		GTM_TIM_Reg_n->CH1_CTRL.B.FLT_MODE_RE = (uint8)FilterMode;
		if(GTM_TIM_Reg_n->CH1_CTRL.B.FLT_MODE_RE != (uint8)FilterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH2:
	{
		GTM_TIM_Reg_n->CH2_CTRL.B.FLT_MODE_RE = (uint8)FilterMode;
		if(GTM_TIM_Reg_n->CH2_CTRL.B.FLT_MODE_RE != (uint8)FilterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH3:
	{
		GTM_TIM_Reg_n->CH3_CTRL.B.FLT_MODE_RE = (uint8)FilterMode;
		if(GTM_TIM_Reg_n->CH3_CTRL.B.FLT_MODE_RE != (uint8)FilterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH4:
	{
		GTM_TIM_Reg_n->CH4_CTRL.B.FLT_MODE_RE = (uint8)FilterMode;
		if(GTM_TIM_Reg_n->CH4_CTRL.B.FLT_MODE_RE != (uint8)FilterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH5:
	{
		GTM_TIM_Reg_n->CH5_CTRL.B.FLT_MODE_RE = (uint8)FilterMode;
		if(GTM_TIM_Reg_n->CH5_CTRL.B.FLT_MODE_RE != (uint8)FilterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH6:
	{
		GTM_TIM_Reg_n->CH6_CTRL.B.FLT_MODE_RE = (uint8)FilterMode;
		if(GTM_TIM_Reg_n->CH6_CTRL.B.FLT_MODE_RE != (uint8)FilterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH7:
	{
		GTM_TIM_Reg_n->CH7_CTRL.B.FLT_MODE_RE = (uint8)FilterMode;
		if(GTM_TIM_Reg_n->CH7_CTRL.B.FLT_MODE_RE != (uint8)FilterMode)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	default:
	{
		/*nothing*/
		result = STATUS_ERROR;
    	break;
	}
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
	P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_CONST) GTM_TIM_Reg_n = g_GTM_TIM_Base[GTM_TIMn];
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

	switch(CHn)
	{
	case GTM_TIM_CH0:
	{
		GTM_TIM_Reg_n->CH0_CTRL.B.FLT_EN = (uint8)IsEnable;
		if(GTM_TIM_Reg_n->CH0_CTRL.B.FLT_EN != (uint8)IsEnable)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH1:
	{
		GTM_TIM_Reg_n->CH1_CTRL.B.FLT_EN = (uint8)IsEnable;
		if(GTM_TIM_Reg_n->CH1_CTRL.B.FLT_EN != (uint8)IsEnable)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH2:
	{
		GTM_TIM_Reg_n->CH2_CTRL.B.FLT_EN = (uint8)IsEnable;
		if(GTM_TIM_Reg_n->CH2_CTRL.B.FLT_EN != (uint8)IsEnable)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH3:
	{
		GTM_TIM_Reg_n->CH3_CTRL.B.FLT_EN = (uint8)IsEnable;
		if(GTM_TIM_Reg_n->CH3_CTRL.B.FLT_EN != (uint8)IsEnable)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH4:
	{
		GTM_TIM_Reg_n->CH4_CTRL.B.FLT_EN = (uint8)IsEnable;
		if(GTM_TIM_Reg_n->CH4_CTRL.B.FLT_EN != (uint8)IsEnable)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH5:
	{
		GTM_TIM_Reg_n->CH5_CTRL.B.FLT_EN = (uint8)IsEnable;
		if(GTM_TIM_Reg_n->CH5_CTRL.B.FLT_EN != (uint8)IsEnable)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH6:
	{
		GTM_TIM_Reg_n->CH6_CTRL.B.FLT_EN = (uint8)IsEnable;
		if(GTM_TIM_Reg_n->CH6_CTRL.B.FLT_EN != (uint8)IsEnable)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH7:
	{
		GTM_TIM_Reg_n->CH7_CTRL.B.FLT_EN = (uint8)IsEnable;
		if(GTM_TIM_Reg_n->CH7_CTRL.B.FLT_EN != (uint8)IsEnable)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	default:
	{
		/*nothing*/
		result = STATUS_ERROR;
    	break;
	}
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
	P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_CONST) GTM_TIM_Reg_n = g_GTM_TIM_Base[GTM_TIMn];
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

	switch(CHn)
	{
	case GTM_TIM_CH0:
	{
		GTM_TIM_Reg_n->CH0_CTRL.B.GPR0_SEL = (uint8)GPR0;
		GTM_TIM_Reg_n->CH0_CTRL.B.GPR1_SEL = (uint8)GPR1;
		break;
	}
	case GTM_TIM_CH1:
	{
		GTM_TIM_Reg_n->CH1_CTRL.B.GPR0_SEL = (uint8)GPR0;
		GTM_TIM_Reg_n->CH1_CTRL.B.GPR1_SEL = (uint8)GPR1;
		break;
	}
	case GTM_TIM_CH2:
	{
		GTM_TIM_Reg_n->CH2_CTRL.B.GPR0_SEL = (uint8)GPR0;
		GTM_TIM_Reg_n->CH2_CTRL.B.GPR1_SEL = (uint8)GPR1;
		break;
	}
	case GTM_TIM_CH3:
	{
		GTM_TIM_Reg_n->CH3_CTRL.B.GPR0_SEL = (uint8)GPR0;
		GTM_TIM_Reg_n->CH3_CTRL.B.GPR1_SEL = (uint8)GPR1;
		break;
	}
	case GTM_TIM_CH4:
	{
		GTM_TIM_Reg_n->CH4_CTRL.B.GPR0_SEL = (uint8)GPR0;
		GTM_TIM_Reg_n->CH4_CTRL.B.GPR1_SEL = (uint8)GPR1;
		break;
	}
	case GTM_TIM_CH5:
	{
		GTM_TIM_Reg_n->CH5_CTRL.B.GPR0_SEL = (uint8)GPR0;
		GTM_TIM_Reg_n->CH5_CTRL.B.GPR1_SEL = (uint8)GPR1;
		break;
	}
	case GTM_TIM_CH6:
	{
		GTM_TIM_Reg_n->CH6_CTRL.B.GPR0_SEL = (uint8)GPR0;
		GTM_TIM_Reg_n->CH6_CTRL.B.GPR1_SEL = (uint8)GPR1;
		break;
	}
	case GTM_TIM_CH7:
	{
		GTM_TIM_Reg_n->CH7_CTRL.B.GPR0_SEL = (uint8)GPR0;
		GTM_TIM_Reg_n->CH7_CTRL.B.GPR1_SEL = (uint8)GPR1;
		break;
	}
	default:
	{
		/*nothing*/
		result = STATUS_ERROR;
    	break;
	}
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
	P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_CONST) GTM_TIM_Reg_n = g_GTM_TIM_Base[GTM_TIMn];
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

	switch(CHn)
	{
	case GTM_TIM_CH0:
	{
		GTM_TIM_Reg_n->CH0_CTRL.B.TIM_MODE = (uint8)TIM_MODE;
		if(GTM_TIM_Reg_n->CH0_CTRL.B.TIM_MODE != (uint8)TIM_MODE)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH1:
	{
		GTM_TIM_Reg_n->CH1_CTRL.B.TIM_MODE = (uint8)TIM_MODE;
		if(GTM_TIM_Reg_n->CH1_CTRL.B.TIM_MODE != (uint8)TIM_MODE)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH2:
	{
		GTM_TIM_Reg_n->CH2_CTRL.B.TIM_MODE = (uint8)TIM_MODE;
		if(GTM_TIM_Reg_n->CH2_CTRL.B.TIM_MODE != (uint8)TIM_MODE)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH3:
	{
		GTM_TIM_Reg_n->CH3_CTRL.B.TIM_MODE = (uint8)TIM_MODE;
		if(GTM_TIM_Reg_n->CH3_CTRL.B.TIM_MODE != (uint8)TIM_MODE)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH4:
	{
		GTM_TIM_Reg_n->CH4_CTRL.B.TIM_MODE = (uint8)TIM_MODE;
		if(GTM_TIM_Reg_n->CH4_CTRL.B.TIM_MODE != (uint8)TIM_MODE)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH5:
	{
		GTM_TIM_Reg_n->CH5_CTRL.B.TIM_MODE = (uint8)TIM_MODE;
		if(GTM_TIM_Reg_n->CH5_CTRL.B.TIM_MODE != (uint8)TIM_MODE)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH6:
	{
		GTM_TIM_Reg_n->CH6_CTRL.B.TIM_MODE = (uint8)TIM_MODE;
		if(GTM_TIM_Reg_n->CH6_CTRL.B.TIM_MODE != (uint8)TIM_MODE)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH7:
	{
		GTM_TIM_Reg_n->CH7_CTRL.B.TIM_MODE = (uint8)TIM_MODE;
		if(GTM_TIM_Reg_n->CH7_CTRL.B.TIM_MODE != (uint8)TIM_MODE)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	default:
	{
		/*nothing*/
		result = STATUS_ERROR;
    	break;
	}
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
	P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_CONST) GTM_TIM_Reg_n = g_GTM_TIM_Base[GTM_TIMn];/* polyspace RTE:OBAI */
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

	switch(CHn)
	{
	case GTM_TIM_CH0:
	{
		GTM_TIM_Reg_n->CH0_CTRL.B.TIM_EN = (uint8)IsEnable;
		if(GTM_TIM_Reg_n->CH0_CTRL.B.TIM_EN != (uint8)IsEnable)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH1:
	{
		GTM_TIM_Reg_n->CH1_CTRL.B.TIM_EN = (uint8)IsEnable;
		if(GTM_TIM_Reg_n->CH1_CTRL.B.TIM_EN != (uint8)IsEnable)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH2:
	{
		GTM_TIM_Reg_n->CH2_CTRL.B.TIM_EN = (uint8)IsEnable;
		if(GTM_TIM_Reg_n->CH2_CTRL.B.TIM_EN != (uint8)IsEnable)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH3:
	{
		GTM_TIM_Reg_n->CH3_CTRL.B.TIM_EN = (uint8)IsEnable;
		if(GTM_TIM_Reg_n->CH3_CTRL.B.TIM_EN != (uint8)IsEnable)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH4:
	{
		GTM_TIM_Reg_n->CH4_CTRL.B.TIM_EN = (uint8)IsEnable;
		if(GTM_TIM_Reg_n->CH4_CTRL.B.TIM_EN != (uint8)IsEnable)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH5:
	{
		GTM_TIM_Reg_n->CH5_CTRL.B.TIM_EN = (uint8)IsEnable;
		if(GTM_TIM_Reg_n->CH5_CTRL.B.TIM_EN != (uint8)IsEnable)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH6:
	{
		GTM_TIM_Reg_n->CH6_CTRL.B.TIM_EN = (uint8)IsEnable;
		if(GTM_TIM_Reg_n->CH6_CTRL.B.TIM_EN != (uint8)IsEnable)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH7:
	{
		GTM_TIM_Reg_n->CH7_CTRL.B.TIM_EN = (uint8)IsEnable;
		if(GTM_TIM_Reg_n->CH7_CTRL.B.TIM_EN != (uint8)IsEnable)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	default:
	{
		/*nothing*/
		result = STATUS_ERROR;
    	break;
	}
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
	P2CONST(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_CONST) GTM_TIM_Reg_n = g_GTM_TIM_Base[GTM_TIMn];/* polyspace RTE:OBAI */
	VAR(uint32, AUTOMATIC) result = 0U;

	switch(CHn)
	{
	case GTM_TIM_CH0:
	{
		switch(Interrupt)
		{
		case TIM_IRQ_GLITCHDET:
		{
			result = GTM_TIM_Reg_n->CH0_IRQ_NOTIFY.B.GLITCHDET;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_TODET:
		{
			result = GTM_TIM_Reg_n->CH0_IRQ_NOTIFY.B.TODET;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_GPROFL:
		{
			result = GTM_TIM_Reg_n->CH0_IRQ_NOTIFY.B.GPROFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_CNTOFL:
		{
			result = GTM_TIM_Reg_n->CH0_IRQ_NOTIFY.B.CNTOFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			result = GTM_TIM_Reg_n->CH0_IRQ_NOTIFY.B.ECNTOFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_NEWVAL:
		{
			result = GTM_TIM_Reg_n->CH0_IRQ_NOTIFY.B.NEWVAL;/* polyspace RTE:NIV */
	    	break;
		}
		default:
		{
			/*nothing*/
			break;
		}
		}
		break;
	}
	case GTM_TIM_CH1:
	{
		switch(Interrupt)
		{
		case TIM_IRQ_GLITCHDET:
		{
			result = GTM_TIM_Reg_n->CH1_IRQ_NOTIFY.B.GLITCHDET;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_TODET:
		{
			result = GTM_TIM_Reg_n->CH1_IRQ_NOTIFY.B.TODET;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_GPROFL:
		{
			result = GTM_TIM_Reg_n->CH1_IRQ_NOTIFY.B.GPROFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_CNTOFL:
		{
			result = GTM_TIM_Reg_n->CH1_IRQ_NOTIFY.B.CNTOFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			result = GTM_TIM_Reg_n->CH1_IRQ_NOTIFY.B.ECNTOFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_NEWVAL:
		{
			result = GTM_TIM_Reg_n->CH1_IRQ_NOTIFY.B.NEWVAL;/* polyspace RTE:NIV */
	    	break;
		}
		default:
		{
			/*nothing*/
			break;
		}
		}
		break;
	}
	case GTM_TIM_CH2:
	{
		switch(Interrupt)
		{
		case TIM_IRQ_GLITCHDET:
		{
			result = GTM_TIM_Reg_n->CH2_IRQ_NOTIFY.B.GLITCHDET;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_TODET:
		{
			result = GTM_TIM_Reg_n->CH2_IRQ_NOTIFY.B.TODET;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_GPROFL:
		{
			result = GTM_TIM_Reg_n->CH2_IRQ_NOTIFY.B.GPROFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_CNTOFL:
		{
			result = GTM_TIM_Reg_n->CH2_IRQ_NOTIFY.B.CNTOFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			result = GTM_TIM_Reg_n->CH2_IRQ_NOTIFY.B.ECNTOFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_NEWVAL:
		{
			result = GTM_TIM_Reg_n->CH2_IRQ_NOTIFY.B.NEWVAL;/* polyspace RTE:NIV */
	    	break;
		}
		default:
		{
			/*nothing*/
			break;
		}
		}
		break;
	}
	case GTM_TIM_CH3:
	{
		switch(Interrupt)
		{
		case TIM_IRQ_GLITCHDET:
		{
			result = GTM_TIM_Reg_n->CH3_IRQ_NOTIFY.B.GLITCHDET;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_TODET:
		{
			result = GTM_TIM_Reg_n->CH3_IRQ_NOTIFY.B.TODET;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_GPROFL:
		{
			result = GTM_TIM_Reg_n->CH3_IRQ_NOTIFY.B.GPROFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_CNTOFL:
		{
			result = GTM_TIM_Reg_n->CH3_IRQ_NOTIFY.B.CNTOFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			result = GTM_TIM_Reg_n->CH3_IRQ_NOTIFY.B.ECNTOFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_NEWVAL:
		{
			result = GTM_TIM_Reg_n->CH3_IRQ_NOTIFY.B.NEWVAL;/* polyspace RTE:NIV */
	    	break;
		}
		default:
		{
			/*nothing*/
			break;
		}
		}
		break;
	}
	case GTM_TIM_CH4:
	{
		switch(Interrupt)
		{
		case TIM_IRQ_GLITCHDET:
		{
			result = GTM_TIM_Reg_n->CH4_IRQ_NOTIFY.B.GLITCHDET;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_TODET:
		{
			result = GTM_TIM_Reg_n->CH4_IRQ_NOTIFY.B.TODET;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_GPROFL:
		{
			result = GTM_TIM_Reg_n->CH4_IRQ_NOTIFY.B.GPROFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_CNTOFL:
		{
			result = GTM_TIM_Reg_n->CH4_IRQ_NOTIFY.B.CNTOFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			result = GTM_TIM_Reg_n->CH4_IRQ_NOTIFY.B.ECNTOFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_NEWVAL:
		{
			result = GTM_TIM_Reg_n->CH4_IRQ_NOTIFY.B.NEWVAL;/* polyspace RTE:NIV */
	    	break;
		}
		default:
		{
			/*nothing*/
			break;
		}
		}
	    break;
	}
	case GTM_TIM_CH5:
	{
		switch(Interrupt)
		{
		case TIM_IRQ_GLITCHDET:
		{
			result = GTM_TIM_Reg_n->CH5_IRQ_NOTIFY.B.GLITCHDET;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_TODET:
		{
			result = GTM_TIM_Reg_n->CH5_IRQ_NOTIFY.B.TODET;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_GPROFL:
		{
			result = GTM_TIM_Reg_n->CH5_IRQ_NOTIFY.B.GPROFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_CNTOFL:
		{
			result = GTM_TIM_Reg_n->CH5_IRQ_NOTIFY.B.CNTOFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			result = GTM_TIM_Reg_n->CH5_IRQ_NOTIFY.B.ECNTOFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_NEWVAL:
		{
			result = GTM_TIM_Reg_n->CH5_IRQ_NOTIFY.B.NEWVAL;/* polyspace RTE:NIV */
	    	break;
		}
		default:
		{
			/*nothing*/
			break;
		}
		}
	break;
	}
	case GTM_TIM_CH6:
	{
	switch(Interrupt)
	{
		case TIM_IRQ_GLITCHDET:
		{
			result = GTM_TIM_Reg_n->CH6_IRQ_NOTIFY.B.GLITCHDET;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_TODET:
		{
			result = GTM_TIM_Reg_n->CH6_IRQ_NOTIFY.B.TODET;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_GPROFL:
		{
			result = GTM_TIM_Reg_n->CH6_IRQ_NOTIFY.B.GPROFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_CNTOFL:
		{
			result = GTM_TIM_Reg_n->CH6_IRQ_NOTIFY.B.CNTOFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			result = GTM_TIM_Reg_n->CH6_IRQ_NOTIFY.B.ECNTOFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_NEWVAL:
		{
			result = GTM_TIM_Reg_n->CH6_IRQ_NOTIFY.B.NEWVAL;/* polyspace RTE:NIV */
	    	break;
		}
		default:
		{
			/*nothing*/
			break;
		}
	}
	break;
	}
	case GTM_TIM_CH7:
	{
	switch(Interrupt)
	{
		case TIM_IRQ_GLITCHDET:
		{
			result = GTM_TIM_Reg_n->CH7_IRQ_NOTIFY.B.GLITCHDET;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_TODET:
		{
			result = GTM_TIM_Reg_n->CH7_IRQ_NOTIFY.B.TODET;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_GPROFL:
		{
			result = GTM_TIM_Reg_n->CH7_IRQ_NOTIFY.B.GPROFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_CNTOFL:
		{
			result = GTM_TIM_Reg_n->CH7_IRQ_NOTIFY.B.CNTOFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			result = GTM_TIM_Reg_n->CH7_IRQ_NOTIFY.B.ECNTOFL;/* polyspace RTE:NIV */
	    	break;
		}
		case TIM_IRQ_NEWVAL:
		{
			result = GTM_TIM_Reg_n->CH7_IRQ_NOTIFY.B.NEWVAL;/* polyspace RTE:NIV */
	    	break;
		}
		default:
		{
			/*nothing*/
			break;
		}
	}
	break;
	}
	default:
	{
		/*nothing*/
		break;
	}
    }
	return (uint8)result;
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
	P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_CONST) GTM_TIM_Reg_n = g_GTM_TIM_Base[GTM_TIMn];/* polyspace RTE:OBAI */
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

	switch(CHn)
	{
	case GTM_TIM_CH0:
	{
		switch(Interrupt)
		{
		case TIM_IRQ_GLITCHDET:
		{
			GTM_TIM_Reg_n->CH0_IRQ_NOTIFY.R = CH0_IRQ_NOTIFY_MASK_GLITCHDET;
			if(GTM_TIM_Reg_n->CH0_IRQ_NOTIFY.B.GLITCHDET != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_TODET:
		{
			GTM_TIM_Reg_n->CH0_IRQ_NOTIFY.R = CH0_IRQ_NOTIFY_MASK_TODET;
			if(GTM_TIM_Reg_n->CH0_IRQ_NOTIFY.B.TODET != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_GPROFL:
		{
			GTM_TIM_Reg_n->CH0_IRQ_NOTIFY.R = CH0_IRQ_NOTIFY_MASK_GPROFL;
			if(GTM_TIM_Reg_n->CH0_IRQ_NOTIFY.B.GPROFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_CNTOFL:
		{
			GTM_TIM_Reg_n->CH0_IRQ_NOTIFY.R = CH0_IRQ_NOTIFY_MASK_CNTOFL;
			if(GTM_TIM_Reg_n->CH0_IRQ_NOTIFY.B.CNTOFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			GTM_TIM_Reg_n->CH0_IRQ_NOTIFY.R = CH0_IRQ_NOTIFY_MASK_ECNTOFL;
			if(GTM_TIM_Reg_n->CH0_IRQ_NOTIFY.B.ECNTOFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_NEWVAL:
		{
			GTM_TIM_Reg_n->CH0_IRQ_NOTIFY.R = CH0_IRQ_NOTIFY_MASK_NEWVAL;
			if(GTM_TIM_Reg_n->CH0_IRQ_NOTIFY.B.NEWVAL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		default:
		{
			/*nothing*/
			result = STATUS_ERROR;
	    	break;
		}
		}
		break;
	}
	case GTM_TIM_CH1:
	{
		switch(Interrupt)
		{
		case TIM_IRQ_GLITCHDET:
		{
			GTM_TIM_Reg_n->CH1_IRQ_NOTIFY.R = CH1_IRQ_NOTIFY_MASK_GLITCHDET;
			if(GTM_TIM_Reg_n->CH1_IRQ_NOTIFY.B.GLITCHDET != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_TODET:
		{
			GTM_TIM_Reg_n->CH1_IRQ_NOTIFY.R = CH1_IRQ_NOTIFY_MASK_TODET;
			if(GTM_TIM_Reg_n->CH1_IRQ_NOTIFY.B.TODET != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_GPROFL:
		{
			GTM_TIM_Reg_n->CH1_IRQ_NOTIFY.R = CH1_IRQ_NOTIFY_MASK_GPROFL;
			if(GTM_TIM_Reg_n->CH1_IRQ_NOTIFY.B.GPROFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_CNTOFL:
		{
			GTM_TIM_Reg_n->CH1_IRQ_NOTIFY.R = CH1_IRQ_NOTIFY_MASK_CNTOFL;
			if(GTM_TIM_Reg_n->CH1_IRQ_NOTIFY.B.CNTOFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			GTM_TIM_Reg_n->CH1_IRQ_NOTIFY.R = CH1_IRQ_NOTIFY_MASK_ECNTOFL;
			if(GTM_TIM_Reg_n->CH1_IRQ_NOTIFY.B.ECNTOFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_NEWVAL:
		{
			GTM_TIM_Reg_n->CH1_IRQ_NOTIFY.R = CH1_IRQ_NOTIFY_MASK_NEWVAL;
			if(GTM_TIM_Reg_n->CH1_IRQ_NOTIFY.B.NEWVAL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		default:
		{
			/*nothing*/
			result = STATUS_ERROR;
	    	break;
		}
		}
	break;
	}
	case GTM_TIM_CH2:
	{
		switch(Interrupt)
		{
		case TIM_IRQ_GLITCHDET:
		{
			GTM_TIM_Reg_n->CH2_IRQ_NOTIFY.R = CH2_IRQ_NOTIFY_MASK_GLITCHDET;
			if(GTM_TIM_Reg_n->CH2_IRQ_NOTIFY.B.GLITCHDET != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_TODET:
		{
			GTM_TIM_Reg_n->CH2_IRQ_NOTIFY.R = CH2_IRQ_NOTIFY_MASK_TODET;
			if(GTM_TIM_Reg_n->CH2_IRQ_NOTIFY.B.TODET != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_GPROFL:
		{
			GTM_TIM_Reg_n->CH2_IRQ_NOTIFY.R = CH2_IRQ_NOTIFY_MASK_GPROFL;
			if(GTM_TIM_Reg_n->CH2_IRQ_NOTIFY.B.GPROFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_CNTOFL:
		{
			GTM_TIM_Reg_n->CH2_IRQ_NOTIFY.R = CH2_IRQ_NOTIFY_MASK_CNTOFL;
			if(GTM_TIM_Reg_n->CH2_IRQ_NOTIFY.B.CNTOFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			GTM_TIM_Reg_n->CH2_IRQ_NOTIFY.R = CH2_IRQ_NOTIFY_MASK_ECNTOFL;
			if(GTM_TIM_Reg_n->CH2_IRQ_NOTIFY.B.ECNTOFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_NEWVAL:
		{
			GTM_TIM_Reg_n->CH2_IRQ_NOTIFY.R = CH2_IRQ_NOTIFY_MASK_NEWVAL;
			if(GTM_TIM_Reg_n->CH2_IRQ_NOTIFY.B.NEWVAL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		default:
		{
			result = STATUS_ERROR;
	    	break;
		}
		}
	break;
	}
	case GTM_TIM_CH3:
	{
		switch(Interrupt)
		{
		case TIM_IRQ_GLITCHDET:
		{
			GTM_TIM_Reg_n->CH3_IRQ_NOTIFY.R = CH3_IRQ_NOTIFY_MASK_GLITCHDET;
			if(GTM_TIM_Reg_n->CH3_IRQ_NOTIFY.B.GLITCHDET != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_TODET:
		{
			GTM_TIM_Reg_n->CH3_IRQ_NOTIFY.R = CH3_IRQ_NOTIFY_MASK_TODET;
			if(GTM_TIM_Reg_n->CH3_IRQ_NOTIFY.B.TODET != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_GPROFL:
		{
			GTM_TIM_Reg_n->CH3_IRQ_NOTIFY.R = CH3_IRQ_NOTIFY_MASK_GPROFL;
			if(GTM_TIM_Reg_n->CH3_IRQ_NOTIFY.B.GPROFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_CNTOFL:
		{
			GTM_TIM_Reg_n->CH3_IRQ_NOTIFY.R = CH3_IRQ_NOTIFY_MASK_CNTOFL;
			if(GTM_TIM_Reg_n->CH3_IRQ_NOTIFY.B.CNTOFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			GTM_TIM_Reg_n->CH3_IRQ_NOTIFY.R = CH3_IRQ_NOTIFY_MASK_ECNTOFL;
			if(GTM_TIM_Reg_n->CH3_IRQ_NOTIFY.B.ECNTOFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_NEWVAL:
		{
			GTM_TIM_Reg_n->CH3_IRQ_NOTIFY.R = CH3_IRQ_NOTIFY_MASK_NEWVAL;
			if(GTM_TIM_Reg_n->CH3_IRQ_NOTIFY.B.NEWVAL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		default:
		{
			/*nothing*/
			result = STATUS_ERROR;
	    	break;
		}
		}
	break;
	}
	case GTM_TIM_CH4:
	{
		switch(Interrupt)
		{
		case TIM_IRQ_GLITCHDET:
		{
			GTM_TIM_Reg_n->CH4_IRQ_NOTIFY.R = CH4_IRQ_NOTIFY_MASK_GLITCHDET;
			if(GTM_TIM_Reg_n->CH4_IRQ_NOTIFY.B.GLITCHDET != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_TODET:
		{
			GTM_TIM_Reg_n->CH4_IRQ_NOTIFY.R = CH4_IRQ_NOTIFY_MASK_TODET;
			if(GTM_TIM_Reg_n->CH4_IRQ_NOTIFY.B.TODET != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_GPROFL:
		{
			GTM_TIM_Reg_n->CH4_IRQ_NOTIFY.R = CH4_IRQ_NOTIFY_MASK_GPROFL;
			if(GTM_TIM_Reg_n->CH4_IRQ_NOTIFY.B.GPROFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_CNTOFL:
		{
			GTM_TIM_Reg_n->CH4_IRQ_NOTIFY.R = CH4_IRQ_NOTIFY_MASK_CNTOFL;
			if(GTM_TIM_Reg_n->CH4_IRQ_NOTIFY.B.CNTOFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			GTM_TIM_Reg_n->CH4_IRQ_NOTIFY.R = CH4_IRQ_NOTIFY_MASK_ECNTOFL;
			if(GTM_TIM_Reg_n->CH4_IRQ_NOTIFY.B.ECNTOFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_NEWVAL:
		{
			GTM_TIM_Reg_n->CH4_IRQ_NOTIFY.R = CH4_IRQ_NOTIFY_MASK_NEWVAL;
			if(GTM_TIM_Reg_n->CH4_IRQ_NOTIFY.B.NEWVAL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		default:
		{
			/*nothing*/
			result = STATUS_ERROR;
	    	break;
		}
		}
	break;
	}
	case GTM_TIM_CH5:
	{
		switch(Interrupt)
		{
		case TIM_IRQ_GLITCHDET:
		{
			GTM_TIM_Reg_n->CH5_IRQ_NOTIFY.R = CH5_IRQ_NOTIFY_MASK_GLITCHDET;
			if(GTM_TIM_Reg_n->CH5_IRQ_NOTIFY.B.GLITCHDET != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_TODET:
		{
			GTM_TIM_Reg_n->CH5_IRQ_NOTIFY.R = CH5_IRQ_NOTIFY_MASK_TODET;
			if(GTM_TIM_Reg_n->CH5_IRQ_NOTIFY.B.TODET != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_GPROFL:
		{
			GTM_TIM_Reg_n->CH5_IRQ_NOTIFY.R = CH5_IRQ_NOTIFY_MASK_GPROFL;
			if(GTM_TIM_Reg_n->CH5_IRQ_NOTIFY.B.GPROFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_CNTOFL:
		{
			GTM_TIM_Reg_n->CH5_IRQ_NOTIFY.R = CH5_IRQ_NOTIFY_MASK_CNTOFL;
			if(GTM_TIM_Reg_n->CH5_IRQ_NOTIFY.B.CNTOFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			GTM_TIM_Reg_n->CH5_IRQ_NOTIFY.R = CH5_IRQ_NOTIFY_MASK_ECNTOFL;
			if(GTM_TIM_Reg_n->CH5_IRQ_NOTIFY.B.ECNTOFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_NEWVAL:
		{
			GTM_TIM_Reg_n->CH5_IRQ_NOTIFY.R = CH5_IRQ_NOTIFY_MASK_NEWVAL;
			if(GTM_TIM_Reg_n->CH5_IRQ_NOTIFY.B.NEWVAL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		default:
		{
			/*nothing*/
			result = STATUS_ERROR;
	    	break;
		}
		}
	break;
	}
	case GTM_TIM_CH6:
	{
		switch(Interrupt)
		{
		case TIM_IRQ_GLITCHDET:
		{
			GTM_TIM_Reg_n->CH6_IRQ_NOTIFY.R = CH6_IRQ_NOTIFY_MASK_GLITCHDET;
			if(GTM_TIM_Reg_n->CH6_IRQ_NOTIFY.B.GLITCHDET != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_TODET:
		{
			GTM_TIM_Reg_n->CH6_IRQ_NOTIFY.R = CH6_IRQ_NOTIFY_MASK_TODET;
			if(GTM_TIM_Reg_n->CH6_IRQ_NOTIFY.B.TODET != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_GPROFL:
		{
			GTM_TIM_Reg_n->CH6_IRQ_NOTIFY.R = CH6_IRQ_NOTIFY_MASK_GPROFL;
			if(GTM_TIM_Reg_n->CH6_IRQ_NOTIFY.B.GPROFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_CNTOFL:
		{
			GTM_TIM_Reg_n->CH6_IRQ_NOTIFY.R = CH6_IRQ_NOTIFY_MASK_CNTOFL;
			if(GTM_TIM_Reg_n->CH6_IRQ_NOTIFY.B.CNTOFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			GTM_TIM_Reg_n->CH6_IRQ_NOTIFY.R = CH6_IRQ_NOTIFY_MASK_ECNTOFL;
			if(GTM_TIM_Reg_n->CH6_IRQ_NOTIFY.B.ECNTOFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_NEWVAL:
		{
			GTM_TIM_Reg_n->CH6_IRQ_NOTIFY.R = CH6_IRQ_NOTIFY_MASK_NEWVAL;
			if(GTM_TIM_Reg_n->CH6_IRQ_NOTIFY.B.NEWVAL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		default:
		{
			/*nothing*/
			result = STATUS_ERROR;
	    	break;
		}
		}
	break;
	}
	case GTM_TIM_CH7:
	{
		switch(Interrupt)
		{
		case TIM_IRQ_GLITCHDET:
		{
			GTM_TIM_Reg_n->CH7_IRQ_NOTIFY.R = CH7_IRQ_NOTIFY_MASK_GLITCHDET;
			if(GTM_TIM_Reg_n->CH7_IRQ_NOTIFY.B.GLITCHDET != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_TODET:
		{
			GTM_TIM_Reg_n->CH7_IRQ_NOTIFY.R = CH7_IRQ_NOTIFY_MASK_TODET;
			if(GTM_TIM_Reg_n->CH7_IRQ_NOTIFY.B.TODET != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_GPROFL:
		{
			GTM_TIM_Reg_n->CH7_IRQ_NOTIFY.R = CH7_IRQ_NOTIFY_MASK_GPROFL;
			if(GTM_TIM_Reg_n->CH7_IRQ_NOTIFY.B.GPROFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_CNTOFL:
		{
			GTM_TIM_Reg_n->CH7_IRQ_NOTIFY.R = CH7_IRQ_NOTIFY_MASK_CNTOFL;
			if(GTM_TIM_Reg_n->CH7_IRQ_NOTIFY.B.CNTOFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			GTM_TIM_Reg_n->CH7_IRQ_NOTIFY.R = CH7_IRQ_NOTIFY_MASK_ECNTOFL;
			if(GTM_TIM_Reg_n->CH7_IRQ_NOTIFY.B.ECNTOFL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_NEWVAL:
		{
			GTM_TIM_Reg_n->CH7_IRQ_NOTIFY.R = CH7_IRQ_NOTIFY_MASK_NEWVAL;
			if(GTM_TIM_Reg_n->CH7_IRQ_NOTIFY.B.NEWVAL != 0u)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		default:
		{
			/*nothing*/
			result = STATUS_ERROR;
	    	break;
		}
		}
	break;
	}
	default:
	{
		result = STATUS_ERROR;
    	break;
	}
	}
	return result;
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
	P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_CONST) GTM_TIM_Reg_n = g_GTM_TIM_Base[GTM_TIMn];/* polyspace RTE:OBAI */
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

	switch(CHn)
	{
	case GTM_TIM_CH0:
	{
		switch(Interrupt)
		{
		case TIM_IRQ_GLITCHDET:
		{
			GTM_TIM_Reg_n->CH0_IRQ_EN.B.GLITCHDET_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH0_IRQ_EN.B.GLITCHDET_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_TODET:
		{
			GTM_TIM_Reg_n->CH0_IRQ_EN.B.TODET_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH0_IRQ_EN.B.TODET_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_GPROFL:
		{
			GTM_TIM_Reg_n->CH0_IRQ_EN.B.GPROFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH0_IRQ_EN.B.GPROFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_CNTOFL:
		{
			GTM_TIM_Reg_n->CH0_IRQ_EN.B.CNTOFL_IRQ_EN =(uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH0_IRQ_EN.B.CNTOFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			GTM_TIM_Reg_n->CH0_IRQ_EN.B.ECNTOFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH0_IRQ_EN.B.ECNTOFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_NEWVAL:
		{
			GTM_TIM_Reg_n->CH0_IRQ_EN.B.NEWVAL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH0_IRQ_EN.B.NEWVAL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		default:
		{
			/*nothing*/
			break;
		}
		}
	break;
	}
	case GTM_TIM_CH1:
	{
	switch(Interrupt)
	{
		case TIM_IRQ_GLITCHDET:
		{
			GTM_TIM_Reg_n->CH1_IRQ_EN.B.GLITCHDET_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH1_IRQ_EN.B.GLITCHDET_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_TODET:
		{
			GTM_TIM_Reg_n->CH1_IRQ_EN.B.TODET_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH1_IRQ_EN.B.TODET_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_GPROFL:
		{
			GTM_TIM_Reg_n->CH1_IRQ_EN.B.GPROFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH1_IRQ_EN.B.GPROFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_CNTOFL:
		{
			GTM_TIM_Reg_n->CH1_IRQ_EN.B.CNTOFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH1_IRQ_EN.B.CNTOFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			GTM_TIM_Reg_n->CH1_IRQ_EN.B.ECNTOFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH1_IRQ_EN.B.ECNTOFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_NEWVAL:
		{
			GTM_TIM_Reg_n->CH1_IRQ_EN.B.NEWVAL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH1_IRQ_EN.B.NEWVAL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		default:
		{
			/*nothing*/
			result = STATUS_ERROR;
	    	break;
		}
		}
	break;
	}
	case GTM_TIM_CH2:
	{
		switch(Interrupt)
		{
		case TIM_IRQ_GLITCHDET:
		{
			GTM_TIM_Reg_n->CH2_IRQ_EN.B.GLITCHDET_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH2_IRQ_EN.B.GLITCHDET_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_TODET:
		{
			GTM_TIM_Reg_n->CH2_IRQ_EN.B.TODET_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH2_IRQ_EN.B.TODET_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_GPROFL:
		{
			GTM_TIM_Reg_n->CH2_IRQ_EN.B.GPROFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH2_IRQ_EN.B.GPROFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_CNTOFL:
		{
			GTM_TIM_Reg_n->CH2_IRQ_EN.B.CNTOFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH2_IRQ_EN.B.CNTOFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			GTM_TIM_Reg_n->CH2_IRQ_EN.B.ECNTOFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH2_IRQ_EN.B.ECNTOFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_NEWVAL:
		{
			GTM_TIM_Reg_n->CH2_IRQ_EN.B.NEWVAL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH2_IRQ_EN.B.NEWVAL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		default:
		{
			/*nothing*/
			result = STATUS_ERROR;
	    	break;
		}
		}
		break;
	}
	case GTM_TIM_CH3:
	{
		switch(Interrupt)
		{
		case TIM_IRQ_GLITCHDET:
		{
			GTM_TIM_Reg_n->CH3_IRQ_EN.B.GLITCHDET_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH3_IRQ_EN.B.GLITCHDET_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_TODET:
		{
			GTM_TIM_Reg_n->CH3_IRQ_EN.B.TODET_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH3_IRQ_EN.B.TODET_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_GPROFL:
		{
			GTM_TIM_Reg_n->CH3_IRQ_EN.B.GPROFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH3_IRQ_EN.B.GPROFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_CNTOFL:
		{
			GTM_TIM_Reg_n->CH3_IRQ_EN.B.CNTOFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH3_IRQ_EN.B.CNTOFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			GTM_TIM_Reg_n->CH3_IRQ_EN.B.ECNTOFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH3_IRQ_EN.B.ECNTOFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_NEWVAL:
		{
			GTM_TIM_Reg_n->CH3_IRQ_EN.B.NEWVAL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH3_IRQ_EN.B.NEWVAL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		default:
		{
			/*nothing*/
			result = STATUS_ERROR;
	    	break;
		}
		}
	break;
	}
	case GTM_TIM_CH4:
	{
		switch(Interrupt)
		{
		case TIM_IRQ_GLITCHDET:
		{
			GTM_TIM_Reg_n->CH4_IRQ_EN.B.GLITCHDET_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH4_IRQ_EN.B.GLITCHDET_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_TODET:
		{
			GTM_TIM_Reg_n->CH4_IRQ_EN.B.TODET_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH4_IRQ_EN.B.TODET_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_GPROFL:
		{
			GTM_TIM_Reg_n->CH4_IRQ_EN.B.GPROFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH4_IRQ_EN.B.GPROFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_CNTOFL:
		{
			GTM_TIM_Reg_n->CH4_IRQ_EN.B.CNTOFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH4_IRQ_EN.B.CNTOFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			GTM_TIM_Reg_n->CH4_IRQ_EN.B.ECNTOFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH4_IRQ_EN.B.ECNTOFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_NEWVAL:
		{
			GTM_TIM_Reg_n->CH4_IRQ_EN.B.NEWVAL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH4_IRQ_EN.B.NEWVAL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		default:
		{
			/*nothing*/
			result = STATUS_ERROR;
	    	break;
		}
		}
		break;
	}
	case GTM_TIM_CH5:
	{
		switch(Interrupt)
		{
		case TIM_IRQ_GLITCHDET:
		{
			GTM_TIM_Reg_n->CH5_IRQ_EN.B.GLITCHDET_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH5_IRQ_EN.B.GLITCHDET_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_TODET:
		{
			GTM_TIM_Reg_n->CH5_IRQ_EN.B.TODET_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH5_IRQ_EN.B.TODET_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_GPROFL:
		{
			GTM_TIM_Reg_n->CH5_IRQ_EN.B.GPROFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH5_IRQ_EN.B.GPROFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_CNTOFL:
		{
			GTM_TIM_Reg_n->CH5_IRQ_EN.B.CNTOFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH5_IRQ_EN.B.CNTOFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			GTM_TIM_Reg_n->CH5_IRQ_EN.B.ECNTOFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH5_IRQ_EN.B.ECNTOFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_NEWVAL:
		{
			GTM_TIM_Reg_n->CH5_IRQ_EN.B.NEWVAL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH5_IRQ_EN.B.NEWVAL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		default:
		{
			/*nothing*/
			result = STATUS_ERROR;
	    	break;
		}
		}
		break;
	}
	case GTM_TIM_CH6:
	{
		switch(Interrupt)
		{
		case TIM_IRQ_GLITCHDET:
		{
			GTM_TIM_Reg_n->CH6_IRQ_EN.B.GLITCHDET_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH6_IRQ_EN.B.GLITCHDET_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_TODET:
		{
			GTM_TIM_Reg_n->CH6_IRQ_EN.B.TODET_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH6_IRQ_EN.B.TODET_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_GPROFL:
		{
			GTM_TIM_Reg_n->CH6_IRQ_EN.B.GPROFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH6_IRQ_EN.B.GPROFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_CNTOFL:
		{
			GTM_TIM_Reg_n->CH6_IRQ_EN.B.CNTOFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH6_IRQ_EN.B.CNTOFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			GTM_TIM_Reg_n->CH6_IRQ_EN.B.ECNTOFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH6_IRQ_EN.B.ECNTOFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_NEWVAL:
		{
			GTM_TIM_Reg_n->CH6_IRQ_EN.B.NEWVAL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH6_IRQ_EN.B.NEWVAL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		default:
		{
			/*nothing*/
			result = STATUS_ERROR;
	    	break;
		}
		}
	break;
	}
	case GTM_TIM_CH7:
	{
		switch(Interrupt)
		{
		case TIM_IRQ_GLITCHDET:
		{
			GTM_TIM_Reg_n->CH7_IRQ_EN.B.GLITCHDET_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH7_IRQ_EN.B.GLITCHDET_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_TODET:
		{
			GTM_TIM_Reg_n->CH7_IRQ_EN.B.TODET_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH7_IRQ_EN.B.TODET_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_GPROFL:
		{
			GTM_TIM_Reg_n->CH7_IRQ_EN.B.GPROFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH7_IRQ_EN.B.GPROFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_CNTOFL:
		{
			GTM_TIM_Reg_n->CH7_IRQ_EN.B.CNTOFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH7_IRQ_EN.B.CNTOFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_ECNTOFL:
		{
			GTM_TIM_Reg_n->CH7_IRQ_EN.B.ECNTOFL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH7_IRQ_EN.B.ECNTOFL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		case TIM_IRQ_NEWVAL:
		{
			GTM_TIM_Reg_n->CH7_IRQ_EN.B.NEWVAL_IRQ_EN = (uint8)IsEnable;
			if(GTM_TIM_Reg_n->CH7_IRQ_EN.B.NEWVAL_IRQ_EN != (uint8)IsEnable)
			{
				result = STATUS_ERROR;
			}
			break;
		}
		default:
		{
			result = STATUS_ERROR;
	    	break;
		}
		}
	break;
	}
	default:
	{
		/*nothing*/
		result = STATUS_ERROR;
    	break;
	}
	}
	
	return result;
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
	P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_CONST) GTM_TIM_Reg_n = g_GTM_TIM_Base[GTM_TIMn];/* polyspace RTE:OBAI */
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

	switch(CHn)
	{
	case GTM_TIM_CH0:
	{
		GTM_TIM_Reg_n->RST.B.RST_CH0 = 1u;
		break;
	}
	case GTM_TIM_CH1:
	{
		GTM_TIM_Reg_n->RST.B.RST_CH1 = 1u;
		break;
	}
	case GTM_TIM_CH2:
	{
		GTM_TIM_Reg_n->RST.B.RST_CH2 = 1u;
		break;
	}
	case GTM_TIM_CH3:
	{
		GTM_TIM_Reg_n->RST.B.RST_CH3 = 1u;
		break;
	}
	case GTM_TIM_CH4:
	{
		GTM_TIM_Reg_n->RST.B.RST_CH4 = 1u;
		break;
	}
	case GTM_TIM_CH5:
	{
		GTM_TIM_Reg_n->RST.B.RST_CH5 = 1u;
		break;
	}
	case GTM_TIM_CH6:
	{
		GTM_TIM_Reg_n->RST.B.RST_CH6 = 1u;
		break;
	}
	case GTM_TIM_CH7:
	{
		GTM_TIM_Reg_n->RST.B.RST_CH7 = 1u;
		break;
	}
	default:
	{
		/*nothing*/
		result = STATUS_ERROR;
    	break;
	}
	}
	return result;
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
	P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_CONST) GTM_TIM_Reg_n = g_GTM_TIM_Base[GTM_TIMn];
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;
	switch(CHn)
	{
	case GTM_TIM_CH0:
	{
		GTM_TIM_Reg_n->CH0_CTRL.B.FLT_CNT_FRQ = (uint8)FilterCounterFrequency;
		if(GTM_TIM_Reg_n->CH0_CTRL.B.FLT_CNT_FRQ != (uint8)FilterCounterFrequency)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH1:
	{
		GTM_TIM_Reg_n->CH1_CTRL.B.FLT_CNT_FRQ = (uint8)FilterCounterFrequency;
		if(GTM_TIM_Reg_n->CH1_CTRL.B.FLT_CNT_FRQ != (uint8)FilterCounterFrequency)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH2:
	{
		GTM_TIM_Reg_n->CH2_CTRL.B.FLT_CNT_FRQ = (uint8)FilterCounterFrequency;
		if(GTM_TIM_Reg_n->CH2_CTRL.B.FLT_CNT_FRQ != (uint8)FilterCounterFrequency)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH3:
	{
		GTM_TIM_Reg_n->CH3_CTRL.B.FLT_CNT_FRQ = (uint8)FilterCounterFrequency;
		if(GTM_TIM_Reg_n->CH3_CTRL.B.FLT_CNT_FRQ != (uint8)FilterCounterFrequency)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH4:
	{
		GTM_TIM_Reg_n->CH4_CTRL.B.FLT_CNT_FRQ = (uint8)FilterCounterFrequency;
		if(GTM_TIM_Reg_n->CH4_CTRL.B.FLT_CNT_FRQ != (uint8)FilterCounterFrequency)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH5:
	{
		GTM_TIM_Reg_n->CH5_CTRL.B.FLT_CNT_FRQ = (uint8)FilterCounterFrequency;
		if(GTM_TIM_Reg_n->CH5_CTRL.B.FLT_CNT_FRQ != (uint8)FilterCounterFrequency)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH6:
	{
		GTM_TIM_Reg_n->CH6_CTRL.B.FLT_CNT_FRQ = (uint8)FilterCounterFrequency;
		if(GTM_TIM_Reg_n->CH6_CTRL.B.FLT_CNT_FRQ != (uint8)FilterCounterFrequency)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	case GTM_TIM_CH7:
	{
		GTM_TIM_Reg_n->CH7_CTRL.B.FLT_CNT_FRQ = (uint8)FilterCounterFrequency;
		if(GTM_TIM_Reg_n->CH7_CTRL.B.FLT_CNT_FRQ != (uint8)FilterCounterFrequency)
		{
			result = STATUS_ERROR;
		}
		break;
	}
	default:
	{
		/*nothing*/
		result = STATUS_ERROR;
    	break;
	}
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
	st_GTM_TIM_tag const*  GTM_TIM_n = g_GTM_TIM_Base[GTM_TIMn];/* polyspace RTE:OBAI */

	switch(CHn)
	{
		case GTM_TIM_CH0:
			return GTM_TIM_n->CH0_GPR0.B.ECNT;/* polyspace RTE:NIV */

		case GTM_TIM_CH1:
			return GTM_TIM_n->CH1_GPR0.B.ECNT;/* polyspace RTE:NIV */

		case GTM_TIM_CH2:
			return GTM_TIM_n->CH2_GPR0.B.ECNT;/* polyspace RTE:NIV */

		case GTM_TIM_CH3:
			return GTM_TIM_n->CH3_GPR0.B.ECNT;/* polyspace RTE:NIV */

		case GTM_TIM_CH4:
			return GTM_TIM_n->CH4_GPR0.B.ECNT;/* polyspace RTE:NIV */

		case GTM_TIM_CH5:
			return GTM_TIM_n->CH5_GPR0.B.ECNT;/* polyspace RTE:NIV */

		case GTM_TIM_CH6:
			return GTM_TIM_n->CH6_GPR0.B.ECNT;/* polyspace RTE:NIV */

		case GTM_TIM_CH7:
			return GTM_TIM_n->CH7_GPR0.B.ECNT;/* polyspace RTE:NIV */

		default:
			/* do nothing*/
		    break;
	}
	return 0U;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* RESOURCE_SUPPORT_GTM104 */
#ifdef __cplusplus
}
#endif
