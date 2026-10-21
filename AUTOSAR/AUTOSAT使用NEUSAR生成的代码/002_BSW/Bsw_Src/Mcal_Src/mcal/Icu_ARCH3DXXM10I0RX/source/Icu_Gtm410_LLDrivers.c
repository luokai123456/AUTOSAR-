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
*   @version 
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
#if (defined(RESOURCE_SUPPORT_GTM410))
#include "Icu_Gtm410_LLDrivers.h"
#include "Icu_Gtm410_Tim_LLDrivers.h"

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
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_ActivationEdge
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(Icu_ValueType, AUTOMATIC) u32Icu_IsEnable
)
{
    VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.DSL = (uint32_t)u32Icu_IsEnable;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.DSL != (uint32_t)u32Icu_IsEnable)
    {
        result = STATUS_ERROR;
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
    VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.ISL = (uint32_t)u32Icu_SingleLevel;/* polyspace RTE:OBAI */
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.ISL != (uint32_t)u32Icu_SingleLevel)/* polyspace RTE:NIV,OBAI */
    {
        result = STATUS_ERROR;
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
    VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].GPR0.B.ECNT = (uint32_t)u32Icu_EdgeCounter;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].GPR0.B.ECNT != (uint32_t)u32Icu_EdgeCounter)
    {
        result = STATUS_ERROR;
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
    VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CNTS.B.ECNT = (uint32_t)u32Icu_EdgeCounter;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CNTS.B.ECNT != (uint32_t)u32Icu_EdgeCounter)
    {
        result = STATUS_ERROR;
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
    return (uint8)GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.R;
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
    return (uint8)GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.R;
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
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

	GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.R = 0x0;

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
	VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.R = GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.R;/* polyspace RTE:NIV,OBAI */

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
    VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.R = (uint32_t)u32Icu_IsEnable;/* polyspace RTE:OBAI */
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.R != (uint32_t)u32Icu_IsEnable)/* polyspace RTE:NIV */
    {
        result = STATUS_ERROR;
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
    VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.R = (uint32_t)u32Icu_IsEnable;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.R != (uint32_t)u32Icu_IsEnable)
    {
        result = STATUS_ERROR;
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
    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.DSL = 0u;

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
    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.DSL = 1u;

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
    return (uint32)&GTM4.GLS[GTM_TIMn].TIM.CH[CHn].GPR0.R;
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
    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].FLT_RE.B.FLT_RE = parameter;
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
    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].FLT_FE.B.FLT_FE = parameter;
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
    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.TBU0_SEL = (uint32)type;
}

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* RESOURCE_SUPPORT_GTM410 */
#ifdef __cplusplus
}
#endif
