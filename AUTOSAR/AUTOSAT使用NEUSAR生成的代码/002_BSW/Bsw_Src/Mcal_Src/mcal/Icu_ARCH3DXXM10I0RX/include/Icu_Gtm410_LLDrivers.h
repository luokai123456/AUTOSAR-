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
*   @file    Icu_Gtm_LLDrivers.h
*   @version 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
/* PRQA S 0779 EOF */

#ifndef ICU_GTM_LLDRIVERS_H
#define ICU_GTM_LLDRIVERS_H

#ifdef __cplusplus
extern "C"
{
#endif
/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "Icu_Gtm410_Tim_LLDrivers.h"
#include "Icu.h"
#include "Gpt_Gtm_LLDriver.h"

/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_GTM_LLDRIVERS_VENDOR_ID_H                   176

#define ICU_GTM_LLDRIVERS_MAJOR_VER_H                   4
#define ICU_GTM_LLDRIVERS_MINOR_VER_H                   4
#define ICU_GTM_LLDRIVERS_REVISION_VER_H                0

#define ICU_GTM_LLDRIVERS_SW_MAJOR_VER_H                3
#define ICU_GTM_LLDRIVERS_SW_MINOR_VER_H                0
#define ICU_GTM_LLDRIVERS_SW_PATCH_VER_H                0

#if (ICU_GTM_LLDRIVERS_VENDOR_ID_H != ICU_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_GTM_LLDRIVERS_MAJOR_VER_H != ICU_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_GTM_LLDRIVERS_MINOR_VER_H != ICU_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_GTM_LLDRIVERS_REVISION_VER_H != ICU_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_GTM_LLDRIVERS_SW_MAJOR_VER_H != ICU_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_GTM_LLDRIVERS_SW_MINOR_VER_H != ICU_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_GTM_LLDRIVERS_SW_PATCH_VER_H != ICU_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifndef BIT2
    #define BIT2    ((uint32)0x00000004UL)
#else 
      #if (BIT2 != 0x00000004UL) 
             #error "BIT2 is defined outside MCAL and it is value  is not 0x00000004UL". 
       #endif 
#endif 

#define GTM_TIM_CH_IRQ_NTFY_CNTOF_M        ((uint32)(BIT2))

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
typedef enum
{
    FLT_CNT_CMU_CLK0,
    FLT_CNT_CMU_CLK1,
    FLT_CNT_CMU_CLK6,
    FLT_CNT_CMU_CLK7
} Filter_CNT_Freq_Type;

typedef enum
{
    TBU_TS0_23_0,
    TBU_TS0_26_3
} GTM_TIME_TBU_TS0_Type;

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
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_CTRL_ISL
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(Icu_ValueType, AUTOMATIC) u32Icu_SingleLevel
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_GPR0_ECNT
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(Icu_ValueType, AUTOMATIC) u32Icu_EdgeCounter
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_CNTS_ECNT
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(Icu_ValueType, AUTOMATIC) u32Icu_EdgeCounter
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint8, ICU_CODE) GTM_TIM_LLD_Channel_ReadIRQEN
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint8, ICU_CODE) GTM_TIM_LLD_Channel_ReadIRQNOTIFY
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_ClearInterruptEN
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_ClearInterruptNOTIFY
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_IsEnableIntcEN
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(GPT_GTM_Status_Type, AUTOMATIC) u32Icu_IsEnable
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_IsEnableIntcNOTIFY
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(GPT_GTM_Status_Type, AUTOMATIC) u32Icu_IsEnable
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_WriteFallingCTRL
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_WriteRisingCTRL
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint32, ICU_CODE) GTM_TIM_LLD_Channel_GetAddress
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) GTM_TIM_LLD_Channel_SetFPRE
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(uint32, AUTOMATIC) parameter
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) GTM_TIM_LLD_Channel_SetFPFE
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(uint32, AUTOMATIC) parameter
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) GTM_TIM_LLD_Channel_SetTBUSel
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(GTM_TIME_TBU_TS0_Type, AUTOMATIC) type
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /* ICU_GTM_LLDRIVERS_H */

