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

/**
*   @file    Icu_Gtm_LLDrivers.c
*   @version 3.0.0 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
/* PRQA S 3432, 0380 EOF */
/* PRQA S 2844, 4342 EOF */
/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#ifdef __cplusplus
extern "C"{
#endif
#include "Icu.h"
#if (defined(RESOURCE_SUPPORT_GTM104))
#include "Icu_Gtm104_LLDrivers.h"
#include "Icu_Gtm104_Tim_LLDrivers.h"

/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_GTM_LLDRIVERS_VENDOR_ID_C                   176

#define ICU_GTM_LLDRIVERS_MAJOR_VER_C                   4
#define ICU_GTM_LLDRIVERS_MINOR_VER_C                   4
#define ICU_GTM_LLDRIVERS_REVISION_VER_C                0

#define ICU_GTM_LLDRIVERS_SW_MAJOR_VER_C                3
#define ICU_GTM_LLDRIVERS_SW_MINOR_VER_C                0
#define ICU_GTM_LLDRIVERS_SW_PATCH_VER_C                0

#if (ICU_GTM_LLDRIVERS_VENDOR_ID_C != ICU_GTM_LLDRIVERS_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_GTM_LLDRIVERS_MAJOR_VER_C != ICU_GTM_LLDRIVERS_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_GTM_LLDRIVERS_MINOR_VER_C != ICU_GTM_LLDRIVERS_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_GTM_LLDRIVERS_REVISION_VER_C != ICU_GTM_LLDRIVERS_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_GTM_LLDRIVERS_SW_MAJOR_VER_C != ICU_GTM_LLDRIVERS_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_GTM_LLDRIVERS_SW_MINOR_VER_C != ICU_GTM_LLDRIVERS_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_GTM_LLDRIVERS_SW_PATCH_VER_C != ICU_GTM_LLDRIVERS_SW_PATCH_VER_H)
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
#define ICU_START_SEC_VAR_INIT
#include "Icu_MemMap.h"
static st_GTM_TIM_tag* GTM_TIM_Base[6U] = \
{
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
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_ActivationEdge
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(Icu_ValueType, AUTOMATIC) u32Icu_IsEnable
)
{
    P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_DATA) GTM_TIM_n = GTM_TIM_Base[GTM_TIMn];
    VAR(status_t, AUTOMATIC) result = (status_t)0U;

    switch(CHn)
    {
    case GTM_TIM_CH0:
    {
        if(GTM_TIM_n->CH0_CTRL.B.DSL != (uint32)u32Icu_IsEnable)/* polyspace RTE:NIV */
        {
        	GTM_TIM_n->CH0_CTRL.B.DSL = (uint32)u32Icu_IsEnable;
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH1:
    {
        GTM_TIM_n->CH1_CTRL.B.DSL = (uint32)u32Icu_IsEnable;
        if(GTM_TIM_n->CH1_CTRL.B.DSL != (uint32)u32Icu_IsEnable)/* polyspace RTE:NIV */
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH2:
    {
        GTM_TIM_n->CH2_CTRL.B.DSL = (uint32)u32Icu_IsEnable;
        if(GTM_TIM_n->CH2_CTRL.B.DSL != (uint32)u32Icu_IsEnable)/* polyspace RTE:NIV */
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH3:
    {
        GTM_TIM_n->CH3_CTRL.B.DSL = (uint32)u32Icu_IsEnable;
        if(GTM_TIM_n->CH3_CTRL.B.DSL != (uint32)u32Icu_IsEnable)/* polyspace RTE:NIV */
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH4:
    {
        GTM_TIM_n->CH4_CTRL.B.DSL = (uint32)u32Icu_IsEnable;
        if(GTM_TIM_n->CH4_CTRL.B.DSL != (uint32)u32Icu_IsEnable)/* polyspace RTE:NIV */
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH5:
    {
        GTM_TIM_n->CH5_CTRL.B.DSL = (uint32)u32Icu_IsEnable;
        if(GTM_TIM_n->CH5_CTRL.B.DSL != (uint32)u32Icu_IsEnable)/* polyspace RTE:NIV */
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH6:
    {
        GTM_TIM_n->CH6_CTRL.B.DSL = (uint32)u32Icu_IsEnable;
        if(GTM_TIM_n->CH6_CTRL.B.DSL != (uint32)u32Icu_IsEnable)/* polyspace RTE:NIV */
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH7:
    {
        GTM_TIM_n->CH7_CTRL.B.DSL = (uint32)u32Icu_IsEnable;
        if(GTM_TIM_n->CH7_CTRL.B.DSL != (uint32)u32Icu_IsEnable)/* polyspace RTE:NIV */
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
    return result;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_CTRL_ISL
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(Icu_ValueType, AUTOMATIC) u32Icu_SingleLevel
)
{
    P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_DATA) GTM_TIM_n = GTM_TIM_Base[GTM_TIMn];/* polyspace RTE:OBAI */
    VAR(status_t, AUTOMATIC) result = (status_t)0U;

    switch(CHn)
    {
    case GTM_TIM_CH0:
    {
        if(GTM_TIM_n->CH0_CTRL.B.ISL != (uint32)u32Icu_SingleLevel)/* polyspace RTE:NIV */
        {
        	GTM_TIM_n->CH0_CTRL.B.ISL = (uint32)u32Icu_SingleLevel;

        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH1:
    {
        GTM_TIM_n->CH1_CTRL.B.ISL = (uint32)u32Icu_SingleLevel;
        if(GTM_TIM_n->CH1_CTRL.B.ISL != (uint32)u32Icu_SingleLevel)/* polyspace RTE:NIV */
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH2:
    {
        GTM_TIM_n->CH2_CTRL.B.ISL = (uint32)u32Icu_SingleLevel;
        if(GTM_TIM_n->CH2_CTRL.B.ISL != (uint32)u32Icu_SingleLevel)/* polyspace RTE:NIV */
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH3:
    {
        GTM_TIM_n->CH3_CTRL.B.ISL = (uint32)u32Icu_SingleLevel;
        if(GTM_TIM_n->CH3_CTRL.B.ISL != (uint32)u32Icu_SingleLevel)/* polyspace RTE:NIV */
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH4:
    {
        GTM_TIM_n->CH4_CTRL.B.ISL = (uint32)u32Icu_SingleLevel;
        if(GTM_TIM_n->CH4_CTRL.B.ISL != (uint32)u32Icu_SingleLevel)/* polyspace RTE:NIV */
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH5:
    {
        GTM_TIM_n->CH5_CTRL.B.ISL = (uint32)u32Icu_SingleLevel;
        if(GTM_TIM_n->CH5_CTRL.B.ISL != (uint32)u32Icu_SingleLevel)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH6:
    {
        GTM_TIM_n->CH6_CTRL.B.ISL = (uint32)u32Icu_SingleLevel;
        if(GTM_TIM_n->CH6_CTRL.B.ISL != (uint32)u32Icu_SingleLevel)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH7:
    {
        GTM_TIM_n->CH7_CTRL.B.ISL = (uint32)u32Icu_SingleLevel;
        if(GTM_TIM_n->CH7_CTRL.B.ISL != (uint32)u32Icu_SingleLevel)
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
    return result;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_GPR0_ECNT
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(Icu_ValueType, AUTOMATIC) u32Icu_EdgeCounter
)
{
    P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_DATA) GTM_TIM_n = GTM_TIM_Base[GTM_TIMn];
    VAR(status_t, AUTOMATIC) result = (status_t)0U;

    switch(CHn)
    {
    case GTM_TIM_CH0:
    {
        GTM_TIM_n->CH0_GPR0.B.ECNT = (uint32)u32Icu_EdgeCounter;
        if(GTM_TIM_n->CH0_GPR0.B.ECNT != (uint32)u32Icu_EdgeCounter)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH1:
    {
        GTM_TIM_n->CH1_GPR0.B.ECNT = (uint32)u32Icu_EdgeCounter;
        if(GTM_TIM_n->CH1_GPR0.B.ECNT != (uint32)u32Icu_EdgeCounter)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH2:
    {
        GTM_TIM_n->CH2_GPR0.B.ECNT = (uint32)u32Icu_EdgeCounter;
        if(GTM_TIM_n->CH2_GPR0.B.ECNT != (uint32)u32Icu_EdgeCounter)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH3:
    {
        GTM_TIM_n->CH3_GPR0.B.ECNT = (uint32)u32Icu_EdgeCounter;
        if(GTM_TIM_n->CH3_GPR0.B.ECNT != (uint32)u32Icu_EdgeCounter)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH4:
    {
        GTM_TIM_n->CH4_GPR0.B.ECNT = (uint32)u32Icu_EdgeCounter;
        if(GTM_TIM_n->CH4_GPR0.B.ECNT != (uint32)u32Icu_EdgeCounter)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH5:
    {
        GTM_TIM_n->CH5_GPR0.B.ECNT = (uint32)u32Icu_EdgeCounter;
        if(GTM_TIM_n->CH5_GPR0.B.ECNT != (uint32)u32Icu_EdgeCounter)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH6:
    {
        GTM_TIM_n->CH6_GPR0.B.ECNT = (uint32)u32Icu_EdgeCounter;
        if(GTM_TIM_n->CH6_GPR0.B.ECNT != (uint32)u32Icu_EdgeCounter)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH7:
    {
        GTM_TIM_n->CH7_GPR0.B.ECNT = (uint32)u32Icu_EdgeCounter;
        if(GTM_TIM_n->CH7_GPR0.B.ECNT != (uint32)u32Icu_EdgeCounter)
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
    return result;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_CNTS_ECNT
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(Icu_ValueType, AUTOMATIC) u32Icu_EdgeCounter
)
{
    P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_DATA) GTM_TIM_n = GTM_TIM_Base[GTM_TIMn];
    VAR(status_t, AUTOMATIC) result = (status_t)0U;

    switch(CHn)
    {
    case GTM_TIM_CH0:
    {
        GTM_TIM_n->CH0_CNTS.B.ECNT = (uint32)u32Icu_EdgeCounter;
        if(GTM_TIM_n->CH0_CNTS.B.ECNT != (uint32)u32Icu_EdgeCounter)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH1:
    {
        GTM_TIM_n->CH1_CNTS.B.ECNT = (uint32)u32Icu_EdgeCounter;
        if(GTM_TIM_n->CH1_CNTS.B.ECNT != (uint32)u32Icu_EdgeCounter)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH2:
    {
        GTM_TIM_n->CH2_CNTS.B.ECNT = (uint32)u32Icu_EdgeCounter;
        if(GTM_TIM_n->CH2_CNTS.B.ECNT != (uint32)u32Icu_EdgeCounter)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH3:
    {
        GTM_TIM_n->CH3_CNTS.B.ECNT = (uint32)u32Icu_EdgeCounter;
        if(GTM_TIM_n->CH3_CNTS.B.ECNT != (uint32)u32Icu_EdgeCounter)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH4:
    {
        GTM_TIM_n->CH4_CNTS.B.ECNT = (uint32)u32Icu_EdgeCounter;
        if(GTM_TIM_n->CH4_CNTS.B.ECNT != (uint32)u32Icu_EdgeCounter)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH5:
    {
        GTM_TIM_n->CH5_CNTS.B.ECNT = (uint32)u32Icu_EdgeCounter;
        if(GTM_TIM_n->CH5_CNTS.B.ECNT != (uint32)u32Icu_EdgeCounter)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH6:
    {
        GTM_TIM_n->CH6_CNTS.B.ECNT = (uint32)u32Icu_EdgeCounter;
        if(GTM_TIM_n->CH6_CNTS.B.ECNT != (uint32)u32Icu_EdgeCounter)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH7:
    {
        GTM_TIM_n->CH7_CNTS.B.ECNT = (uint32)u32Icu_EdgeCounter;
        if(GTM_TIM_n->CH7_CNTS.B.ECNT != (uint32)u32Icu_EdgeCounter)
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
    return result;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint8, ICU_CODE) GTM_TIM_LLD_Channel_ReadIRQNOTIFY
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn
)
{
	P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_DATA) GTM_TIM_n = GTM_TIM_Base[GTM_TIMn];
    VAR(uint32, AUTOMATIC) result = 0U;

    switch(CHn)
    {
    case GTM_TIM_CH0:
    {
    	result = GTM_TIM_n->CH0_IRQ_NOTIFY.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH1:
    {
    	result = GTM_TIM_n->CH1_IRQ_NOTIFY.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH2:
    {
    	result = GTM_TIM_n->CH2_IRQ_NOTIFY.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH3:
    {
    	result = GTM_TIM_n->CH3_IRQ_NOTIFY.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH4:
    {
    	result = GTM_TIM_n->CH4_IRQ_NOTIFY.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH5:
    {
    	result = GTM_TIM_n->CH5_IRQ_NOTIFY.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH6:
    {
    	result = GTM_TIM_n->CH6_IRQ_NOTIFY.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH7:
    {
    	result = GTM_TIM_n->CH7_IRQ_NOTIFY.R;/* polyspace RTE:NIV */
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


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint8, ICU_CODE) GTM_TIM_LLD_Channel_ReadIRQEN
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn
)
{
	P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_DATA) GTM_TIM_n = GTM_TIM_Base[GTM_TIMn];
	VAR(uint32, AUTOMATIC) result = 0U;

    switch(CHn)
    {
    case GTM_TIM_CH0:
    {
    	result = GTM_TIM_n->CH0_IRQ_EN.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH1:
    {
    	result = GTM_TIM_n->CH1_IRQ_EN.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH2:
    {
    	result = GTM_TIM_n->CH2_IRQ_EN.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH3:
    {
    	result = GTM_TIM_n->CH3_IRQ_EN.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH4:
    {
    	result = GTM_TIM_n->CH4_IRQ_EN.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH5:
    {
    	result = GTM_TIM_n->CH5_IRQ_EN.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH6:
    {
    	result = GTM_TIM_n->CH6_IRQ_EN.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH7:
    {
    	result = GTM_TIM_n->CH7_IRQ_EN.R;/* polyspace RTE:NIV */
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

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_ClearInterruptEN
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn
)
{
	P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_DATA) GTM_TIM_n = GTM_TIM_Base[GTM_TIMn];
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

    switch(CHn)
    {
    case GTM_TIM_CH0:
    {
        GTM_TIM_n->CH0_IRQ_EN.R = GTM_TIM_n->CH0_IRQ_EN.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH1:
    {
        GTM_TIM_n->CH1_IRQ_EN.R = GTM_TIM_n->CH1_IRQ_EN.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH2:
    {
        GTM_TIM_n->CH2_IRQ_EN.R = GTM_TIM_n->CH2_IRQ_EN.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH3:
    {
        GTM_TIM_n->CH3_IRQ_EN.R = GTM_TIM_n->CH3_IRQ_EN.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH4:
    {
        GTM_TIM_n->CH4_IRQ_EN.R = GTM_TIM_n->CH4_IRQ_EN.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH5:
    {
        GTM_TIM_n->CH5_IRQ_EN.R = GTM_TIM_n->CH5_IRQ_EN.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH6:
    {
        GTM_TIM_n->CH6_IRQ_EN.R = GTM_TIM_n->CH6_IRQ_EN.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH7:
    {
        GTM_TIM_n->CH7_IRQ_EN.R = GTM_TIM_n->CH7_IRQ_EN.R;/* polyspace RTE:NIV */
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

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_ClearInterruptNOTIFY
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn
)
{
    P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_DATA) GTM_TIM_n = GTM_TIM_Base[GTM_TIMn];/* polyspace RTE:OBAI */
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

    switch(CHn)
    {
    case GTM_TIM_CH0:
    {
        GTM_TIM_n->CH0_IRQ_NOTIFY.R = GTM_TIM_n->CH0_IRQ_NOTIFY.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH1:
    {
        GTM_TIM_n->CH1_IRQ_NOTIFY.R = GTM_TIM_n->CH1_IRQ_NOTIFY.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH2:
    {
        GTM_TIM_n->CH2_IRQ_NOTIFY.R = GTM_TIM_n->CH2_IRQ_NOTIFY.R;/* polyspace RTE:NIV */
        break;
    }    
    case GTM_TIM_CH3:
    {
        GTM_TIM_n->CH3_IRQ_NOTIFY.R = GTM_TIM_n->CH3_IRQ_NOTIFY.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH4:
    {
        GTM_TIM_n->CH4_IRQ_NOTIFY.R = GTM_TIM_n->CH4_IRQ_NOTIFY.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH5:
    {
        GTM_TIM_n->CH5_IRQ_NOTIFY.R = GTM_TIM_n->CH5_IRQ_NOTIFY.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH6:
    {
        GTM_TIM_n->CH6_IRQ_NOTIFY.R = GTM_TIM_n->CH6_IRQ_NOTIFY.R;/* polyspace RTE:NIV */
        break;
    }
    case GTM_TIM_CH7:
    {
        GTM_TIM_n->CH7_IRQ_NOTIFY.R = GTM_TIM_n->CH7_IRQ_NOTIFY.R;/* polyspace RTE:NIV */
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

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_IsEnableIntcEN
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(GPT_GTM_Status_Type, AUTOMATIC) u32Icu_IsEnable \
)
{
    P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_DATA) GTM_TIM_n = GTM_TIM_Base[GTM_TIMn];/* polyspace RTE:OBAI */
	VAR(status_t, AUTOMATIC) result = (status_t)0U;

    switch(CHn)
    {
    case GTM_TIM_CH0:
    {
        GTM_TIM_n->CH0_IRQ_EN.R = (uint8)u32Icu_IsEnable;
        if(GTM_TIM_n->CH0_IRQ_EN.R != (uint8)u32Icu_IsEnable)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH1:
    {
        GTM_TIM_n->CH1_IRQ_EN.R = (uint8)u32Icu_IsEnable;
        if(GTM_TIM_n->CH1_IRQ_EN.R != (uint8)u32Icu_IsEnable)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH2:
    {
        GTM_TIM_n->CH2_IRQ_EN.R = (uint8)u32Icu_IsEnable;
        if(GTM_TIM_n->CH2_IRQ_EN.R != (uint8)u32Icu_IsEnable)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH3:
    {
        GTM_TIM_n->CH3_IRQ_EN.R = (uint8)u32Icu_IsEnable;
        if(GTM_TIM_n->CH3_IRQ_EN.R != (uint8)u32Icu_IsEnable)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH4:
    {
        GTM_TIM_n->CH4_IRQ_EN.R = (uint8)u32Icu_IsEnable;
        if(GTM_TIM_n->CH4_IRQ_EN.R != (uint8)u32Icu_IsEnable)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH5:
    {
        GTM_TIM_n->CH5_IRQ_EN.R = (uint8)u32Icu_IsEnable;
        if(GTM_TIM_n->CH5_IRQ_EN.R != (uint8)u32Icu_IsEnable)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH6:
    {
        GTM_TIM_n->CH6_IRQ_EN.R = (uint8)u32Icu_IsEnable;
        if(GTM_TIM_n->CH6_IRQ_EN.R != (uint8)u32Icu_IsEnable)
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH7:
    {
        GTM_TIM_n->CH7_IRQ_EN.R = (uint8)u32Icu_IsEnable;
        if(GTM_TIM_n->CH7_IRQ_EN.R != (uint8)u32Icu_IsEnable)
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
    return result;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_IsEnableIntcNOTIFY
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(GPT_GTM_Status_Type, AUTOMATIC) u32Icu_IsEnable
)
{
    P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_DATA) GTM_TIM_n = GTM_TIM_Base[GTM_TIMn];
	VAR(status_t, AUTOMATIC) result = (status_t)0U;

    switch(CHn)
    {
    case GTM_TIM_CH0:
    {
        GTM_TIM_n->CH0_IRQ_NOTIFY.R = (uint8)u32Icu_IsEnable;
        if(GTM_TIM_n->CH0_IRQ_NOTIFY.R != (uint8)u32Icu_IsEnable)/* polyspace RTE:NIV */
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH1:
    {
        GTM_TIM_n->CH1_IRQ_NOTIFY.R = (uint8)u32Icu_IsEnable;
        if(GTM_TIM_n->CH1_IRQ_NOTIFY.R != (uint8)u32Icu_IsEnable)/* polyspace RTE:NIV */
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH2:
    {
        GTM_TIM_n->CH2_IRQ_NOTIFY.R = (uint8)u32Icu_IsEnable;
        if(GTM_TIM_n->CH2_IRQ_NOTIFY.R != (uint8)u32Icu_IsEnable)/* polyspace RTE:NIV */
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH3:
    {
        GTM_TIM_n->CH3_IRQ_NOTIFY.R = (uint8)u32Icu_IsEnable;
        if(GTM_TIM_n->CH3_IRQ_NOTIFY.R != (uint8)u32Icu_IsEnable)/* polyspace RTE:NIV */
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH4:
    {
        GTM_TIM_n->CH4_IRQ_NOTIFY.R = (uint8)u32Icu_IsEnable;
        if(GTM_TIM_n->CH4_IRQ_NOTIFY.R != (uint8)u32Icu_IsEnable)/* polyspace RTE:NIV */
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH5:
    {
        GTM_TIM_n->CH5_IRQ_NOTIFY.R = (uint8)u32Icu_IsEnable;
        if(GTM_TIM_n->CH5_IRQ_NOTIFY.R != (uint8)u32Icu_IsEnable)/* polyspace RTE:NIV */
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH6:
    {
        GTM_TIM_n->CH6_IRQ_NOTIFY.R = (uint8)u32Icu_IsEnable;
        if(GTM_TIM_n->CH6_IRQ_NOTIFY.R != (uint8)u32Icu_IsEnable)/* polyspace RTE:NIV */
        {
        	result = STATUS_ERROR;
        }
        break;
    }
    case GTM_TIM_CH7:
    {
        GTM_TIM_n->CH7_IRQ_NOTIFY.R = (uint8)u32Icu_IsEnable;
        if(GTM_TIM_n->CH7_IRQ_EN.R != (uint8)u32Icu_IsEnable)/* polyspace RTE:NIV */
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
    return result;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_WriteFallingCTRL
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn
)
{
    P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_DATA) GTM_TIM_n = GTM_TIM_Base[GTM_TIMn];

    switch(CHn)
    {
    case GTM_TIM_CH0:
    {
        GTM_TIM_n->CH0_CTRL.B.DSL = 0;
        break;
    }

    case GTM_TIM_CH1:
    {
        GTM_TIM_n->CH1_CTRL.B.DSL = 0;
        break;
    }

    case GTM_TIM_CH2:
    {
        GTM_TIM_n->CH2_CTRL.B.DSL = 0;
        break;
    }

    case GTM_TIM_CH3:
    {
        GTM_TIM_n->CH3_CTRL.B.DSL = 0;
        break;
    }

    case GTM_TIM_CH4:
    {
        GTM_TIM_n->CH4_CTRL.B.DSL = 0;
        break;
    }

    case GTM_TIM_CH5:
    {
        GTM_TIM_n->CH5_CTRL.B.DSL = 0;
        break;
    }

    case GTM_TIM_CH6:
    {
        GTM_TIM_n->CH6_CTRL.B.DSL = 0;
        break;
    }
    case GTM_TIM_CH7:
    {
        GTM_TIM_n->CH7_CTRL.B.DSL = 0;
        break;
    }

    default:
    {
    	/*nothing*/
        break;
    }
    }
    return STATUS_SUCCESS;
    
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_WriteRisingCTRL
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn
)
{
    P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_DATA) GTM_TIM_n = GTM_TIM_Base[GTM_TIMn];

    switch(CHn)
    {
    case GTM_TIM_CH0:
    {
        GTM_TIM_n->CH0_CTRL.B.DSL = 1;
        break;
    }
    case GTM_TIM_CH1:
    {
        GTM_TIM_n->CH1_CTRL.B.DSL = 1;
        break;
    }
    case GTM_TIM_CH2:
    {
        GTM_TIM_n->CH2_CTRL.B.DSL = 1;
        break;
    }
    case GTM_TIM_CH3:
    {
        GTM_TIM_n->CH3_CTRL.B.DSL = 1;
        break;
    }
    case GTM_TIM_CH4:
    {
        GTM_TIM_n->CH4_CTRL.B.DSL = 1;
        break;
    }
    case GTM_TIM_CH5:
    {
        GTM_TIM_n->CH5_CTRL.B.DSL = 1;
        break;
    }
    case GTM_TIM_CH6:
    {
        GTM_TIM_n->CH6_CTRL.B.DSL = 1;
        break;
    }
    case GTM_TIM_CH7:
    {
        GTM_TIM_n->CH7_CTRL.B.DSL = 1;
        break;
    }
    default:
    {
    	/*nothing*/
        break;
    }
    }
    return STATUS_SUCCESS;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_WriteBothCTRL
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn
)
{
    P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_DATA) GTM_TIM_n = GTM_TIM_Base[GTM_TIMn];

    switch(CHn)
    {
    case GTM_TIM_CH0:
    {
        GTM_TIM_n->CH0_CTRL.B.DSL = 1;
        break;
    }
    case GTM_TIM_CH1:
    {
        GTM_TIM_n->CH1_CTRL.B.DSL = 1;
        break;
    }
    case GTM_TIM_CH2:
    {
        GTM_TIM_n->CH2_CTRL.B.DSL = 1;
        break;
    }
    case GTM_TIM_CH3:
    {
        GTM_TIM_n->CH3_CTRL.B.DSL = 1;
        break;
    }
    case GTM_TIM_CH4:
    {
        GTM_TIM_n->CH4_CTRL.B.DSL = 1;
        break;
    }
    case GTM_TIM_CH5:
    {
        GTM_TIM_n->CH5_CTRL.B.DSL = 1;
        break;
    }
    case GTM_TIM_CH6:
    {
        GTM_TIM_n->CH6_CTRL.B.DSL = 1;
        break;
    }
    case GTM_TIM_CH7:
    {
        GTM_TIM_n->CH7_CTRL.B.DSL = 1;
        break;
    }
    default:
    {
    	/*nothing*/
        break;
    }
    }
    return STATUS_SUCCESS;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint32, ICU_CODE) GTM_TIM_LLD_Channel_GetAddress
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn
)
{
    P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_DATA) GTM_TIM_n = GTM_TIM_Base[GTM_TIMn];/* polyspace RTE:OBAI */
    VAR(uint32, AUTOMATIC) result = 0U;

    switch(CHn)
    {
    case GTM_TIM_CH0:
    {
        result = (uint32)&GTM_TIM_n->CH0_GPR0.R;
        break;
    }
    case GTM_TIM_CH1:
    {
        result = (uint32)&GTM_TIM_n->CH1_GPR0.R;
        break;
    }
    case GTM_TIM_CH2:
    {
        result = (uint32)&GTM_TIM_n->CH2_GPR0.R;
        break;
    }
    case GTM_TIM_CH3:
    {
        result = (uint32)&GTM_TIM_n->CH3_GPR0.R;
        break;
    }
    case GTM_TIM_CH4:
    {
        result = (uint32)&GTM_TIM_n->CH4_GPR0.R;
        break;
    }
    case GTM_TIM_CH5:
    {
        result = (uint32)&GTM_TIM_n->CH5_GPR0.R;
        break;
    }
    case GTM_TIM_CH6:
    {
        result = (uint32)&GTM_TIM_n->CH6_GPR0.R;
        break;
    }
    case GTM_TIM_CH7:
    {
        result = (uint32)&GTM_TIM_n->CH7_GPR0.R;
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

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) GTM_TIM_LLD_Channel_FilterCTRL
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(GPT_GTM_Status_Type, AUTOMATIC) Stauts
)
{
    P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_DATA) GTM_TIM_n = GTM_TIM_Base[GTM_TIMn];

    switch(CHn)
    {
    case GTM_TIM_CH0:
    {
        GTM_TIM_n->CH0_CTRL.B.FLT_EN = (uint32)Stauts;
        GTM_TIM_n->CH0_CTRL.B.FLT_MODE_FE = (uint32)Stauts;
        GTM_TIM_n->CH0_CTRL.B.FLT_CTR_FE =(uint32) Stauts;
        GTM_TIM_n->CH0_CTRL.B.FLT_CTR_RE = (uint32)Stauts;
        GTM_TIM_n->CH0_CTRL.B.FLT_MODE_RE = (uint32)Stauts;
        GTM_TIM_n->CH0_CTRL.B.FLT_CNT_FRQ = 0;
        break;
    }
    case GTM_TIM_CH1:
    {
        GTM_TIM_n->CH1_CTRL.B.FLT_EN = (uint32)Stauts;
        GTM_TIM_n->CH1_CTRL.B.FLT_MODE_FE = (uint32)Stauts;
        GTM_TIM_n->CH1_CTRL.B.FLT_CTR_FE = (uint32)Stauts;
        GTM_TIM_n->CH1_CTRL.B.FLT_CTR_RE = (uint32)Stauts;
        GTM_TIM_n->CH1_CTRL.B.FLT_MODE_RE = (uint32)Stauts;
        GTM_TIM_n->CH1_CTRL.B.FLT_CNT_FRQ = 0;
        break;
    }
    case GTM_TIM_CH2:
    {
        GTM_TIM_n->CH2_CTRL.B.FLT_EN = (uint32)Stauts;
        GTM_TIM_n->CH2_CTRL.B.FLT_MODE_FE = (uint32)Stauts;
        GTM_TIM_n->CH2_CTRL.B.FLT_CTR_FE = (uint32)Stauts;
        GTM_TIM_n->CH2_CTRL.B.FLT_CTR_RE = (uint32)Stauts;
        GTM_TIM_n->CH2_CTRL.B.FLT_MODE_RE = (uint32)Stauts;
        GTM_TIM_n->CH2_CTRL.B.FLT_CNT_FRQ = 0;
        break;
    }
    case GTM_TIM_CH3:
    {
        GTM_TIM_n->CH3_CTRL.B.FLT_EN = (uint32)Stauts;
        GTM_TIM_n->CH3_CTRL.B.FLT_MODE_FE = (uint32)Stauts;
        GTM_TIM_n->CH3_CTRL.B.FLT_CTR_FE = (uint32)Stauts;
        GTM_TIM_n->CH3_CTRL.B.FLT_CTR_RE = (uint32)Stauts;
        GTM_TIM_n->CH3_CTRL.B.FLT_MODE_RE =(uint32) Stauts;
        GTM_TIM_n->CH3_CTRL.B.FLT_CNT_FRQ = 0;
        break;
    }
    case GTM_TIM_CH4:
    {
        GTM_TIM_n->CH4_CTRL.B.FLT_EN = (uint32)Stauts;
        GTM_TIM_n->CH4_CTRL.B.FLT_MODE_FE = (uint32)Stauts;
        GTM_TIM_n->CH4_CTRL.B.FLT_CTR_FE = (uint32)Stauts;
        GTM_TIM_n->CH4_CTRL.B.FLT_CTR_RE = (uint32)Stauts;
        GTM_TIM_n->CH4_CTRL.B.FLT_MODE_RE = (uint32)Stauts;
        GTM_TIM_n->CH4_CTRL.B.FLT_CNT_FRQ = 0;
        break;
    }
    case GTM_TIM_CH5:
    {
        GTM_TIM_n->CH5_CTRL.B.FLT_EN = (uint32)Stauts;
        GTM_TIM_n->CH5_CTRL.B.FLT_MODE_FE = (uint32)Stauts;
        GTM_TIM_n->CH5_CTRL.B.FLT_CTR_FE = (uint32)Stauts;
        GTM_TIM_n->CH5_CTRL.B.FLT_CTR_RE = (uint32)Stauts;
        GTM_TIM_n->CH5_CTRL.B.FLT_MODE_RE = (uint32)Stauts;
        GTM_TIM_n->CH5_CTRL.B.FLT_CNT_FRQ = 0;
        break;
    }
    case GTM_TIM_CH6:
    {
        GTM_TIM_n->CH6_CTRL.B.FLT_EN = (uint32)Stauts;
        GTM_TIM_n->CH6_CTRL.B.FLT_MODE_FE = (uint32)Stauts;
        GTM_TIM_n->CH6_CTRL.B.FLT_CTR_FE = (uint32)Stauts;
        GTM_TIM_n->CH6_CTRL.B.FLT_CTR_RE =(uint32) Stauts;
        GTM_TIM_n->CH6_CTRL.B.FLT_MODE_RE = (uint32)Stauts;
        GTM_TIM_n->CH6_CTRL.B.FLT_CNT_FRQ = 0;
        break;
    }
    case GTM_TIM_CH7:
    {
        GTM_TIM_n->CH7_CTRL.B.FLT_EN = (uint32)Stauts;
        GTM_TIM_n->CH7_CTRL.B.FLT_MODE_FE = (uint32)Stauts;
        GTM_TIM_n->CH7_CTRL.B.FLT_CTR_FE = (uint32)Stauts;
        GTM_TIM_n->CH7_CTRL.B.FLT_CTR_RE = (uint32)Stauts;
        GTM_TIM_n->CH7_CTRL.B.FLT_MODE_RE = (uint32)Stauts;
        GTM_TIM_n->CH7_CTRL.B.FLT_CNT_FRQ = 0;
        break;
    }
    default:
    {
        /*nothing*/
        break;
    }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) GTM_TIM_LLD_Channel_FilterFreqCTRL
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(Filter_CNT_Freq_Type, AUTOMATIC) Freq
)
{
    P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_DATA) GTM_TIM_n = GTM_TIM_Base[GTM_TIMn];

    switch(CHn)
    {
    case GTM_TIM_CH0:
    {
        GTM_TIM_n->CH0_CTRL.B.FLT_CNT_FRQ = (uint32)Freq;
        break;
    }
    case GTM_TIM_CH1:
    {
        GTM_TIM_n->CH1_CTRL.B.FLT_CNT_FRQ = (uint32)Freq;
        break;
    }
    case GTM_TIM_CH2:
    {
        GTM_TIM_n->CH2_CTRL.B.FLT_CNT_FRQ =(uint32) Freq;
        break;
    }
    case GTM_TIM_CH3:
    {
        GTM_TIM_n->CH3_CTRL.B.FLT_CNT_FRQ = (uint32)Freq;
        break;
    }
    case GTM_TIM_CH4:
    {
        GTM_TIM_n->CH4_CTRL.B.FLT_CNT_FRQ = (uint32)Freq;
        break;
    }
    case GTM_TIM_CH5:
    {
        GTM_TIM_n->CH5_CTRL.B.FLT_CNT_FRQ =(uint32) Freq;
        break;
    }
    case GTM_TIM_CH6:
    {
        GTM_TIM_n->CH6_CTRL.B.FLT_CNT_FRQ = (uint32)Freq;
        break;
    }
    case GTM_TIM_CH7:
    {
        GTM_TIM_n->CH7_CTRL.B.FLT_CNT_FRQ = (uint32)Freq;
        break;
    }
    default:
    {
        /*nothing*/
        break;
    }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) GTM_TIM_LLD_Channel_SetFPRE
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(uint32, AUTOMATIC) parameter
)
{
    P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_DATA) GTM_TIM_n = GTM_TIM_Base[GTM_TIMn];

    switch(CHn)
    {
    case GTM_TIM_CH0:
    {
        GTM_TIM_n->CH0_FLT_RE.B.FLT_RE = parameter;
        break;
    }
    case GTM_TIM_CH1:
    {
        GTM_TIM_n->CH1_FLT_RE.B.FLT_RE = parameter;
        break;
    }
    case GTM_TIM_CH2:
    {
        GTM_TIM_n->CH2_FLT_RE.B.FLT_RE = parameter;
        break;
    }
    case GTM_TIM_CH3:
    {
        GTM_TIM_n->CH3_FLT_RE.B.FLT_RE = parameter;
        break;
    }
    case GTM_TIM_CH4:
    {
        GTM_TIM_n->CH4_FLT_RE.B.FLT_RE = parameter;
        break;
    }
    case GTM_TIM_CH5:
    {
        GTM_TIM_n->CH5_FLT_RE.B.FLT_RE = parameter;
        break;
    }
    case GTM_TIM_CH6:
    {
        GTM_TIM_n->CH6_FLT_RE.B.FLT_RE = parameter;
        break;
    }
    case GTM_TIM_CH7:
    {
        GTM_TIM_n->CH7_FLT_RE.B.FLT_RE = parameter;
        break;
    }
    default:
    {
        /*nothing*/
        break;
    }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) GTM_TIM_LLD_Channel_SetFPFE
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(uint32, AUTOMATIC) parameter
)
{
    P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_DATA) GTM_TIM_n = GTM_TIM_Base[GTM_TIMn];

    switch(CHn)
    {
    case GTM_TIM_CH0:
    {
        GTM_TIM_n->CH0_FLT_FE.B.FLT_FE = parameter;
        break;
    }
    case GTM_TIM_CH1:
    {
        GTM_TIM_n->CH1_FLT_FE.B.FLT_FE = parameter;
        break;
    }
    case GTM_TIM_CH2:
    {
        GTM_TIM_n->CH2_FLT_FE.B.FLT_FE = parameter;
        break;
    }
    case GTM_TIM_CH3:
    {
        GTM_TIM_n->CH3_FLT_FE.B.FLT_FE = parameter;
        break;
    }
    case GTM_TIM_CH4:
    {
        GTM_TIM_n->CH4_FLT_FE.B.FLT_FE = parameter;
        break;
    }
    case GTM_TIM_CH5:
    {
        GTM_TIM_n->CH5_FLT_FE.B.FLT_FE = parameter;
        break;
    }
    case GTM_TIM_CH6:
    {
        GTM_TIM_n->CH6_FLT_FE.B.FLT_FE = parameter;
        break;
    }
    case GTM_TIM_CH7:
    {
        GTM_TIM_n->CH7_FLT_FE.B.FLT_FE = parameter;
        break;
    }
    default:
    {
        /*nothing*/
        break;
    }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) GTM_TIM_LLD_Channel_SetTBUSel
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(GTM_TIME_TBU_TS0_Type, AUTOMATIC) type
)
{
    P2VAR(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_DATA) GTM_TIM_n = GTM_TIM_Base[GTM_TIMn];

    switch(CHn)
    {
    case GTM_TIM_CH0:
    {
        GTM_TIM_n->CH0_CTRL.B.TBU0_SEL = (uint32)type;
        break;
    }
    case GTM_TIM_CH1:
    {
        GTM_TIM_n->CH1_CTRL.B.TBU0_SEL = (uint32)type;
        break;
    }
    case GTM_TIM_CH2:
    {
        GTM_TIM_n->CH2_CTRL.B.TBU0_SEL = (uint32)type;
        break;
    }
    case GTM_TIM_CH3:
    {
        GTM_TIM_n->CH3_CTRL.B.TBU0_SEL = (uint32)type;
        break;
    }
    case GTM_TIM_CH4:
    {
        GTM_TIM_n->CH4_CTRL.B.TBU0_SEL = (uint32)type;
        break;
    }
    case GTM_TIM_CH5:
    {
        GTM_TIM_n->CH5_CTRL.B.TBU0_SEL = (uint32)type;
        break;
    }
    case GTM_TIM_CH6:
    {
        GTM_TIM_n->CH6_CTRL.B.TBU0_SEL = (uint32)type;
        break;
    }
    case GTM_TIM_CH7:
    {
        GTM_TIM_n->CH7_CTRL.B.TBU0_SEL =(uint32)type;
        break;
    }
    default:
    {
        /*nothing*/
        break;
    }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* RESOURCE_SUPPORT_GTM104 */
#ifdef __cplusplus
}
#endif
