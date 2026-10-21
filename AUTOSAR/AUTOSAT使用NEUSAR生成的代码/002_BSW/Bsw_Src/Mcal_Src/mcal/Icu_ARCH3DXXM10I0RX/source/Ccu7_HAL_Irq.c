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
*   @file    Ccu7_HAL_Irq.c
*   @version
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
/* PRQA S 0380,4424,2982,2983,1753,1594,1599 EOF */
/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#ifdef __cplusplus
extern "C"{
#endif
#include "Ccu7_HAL_Irq.h"
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
#include "Icu_Ccu7_LLDrivers.h"
#include "Icu_Ccu7_HAL_Wrapper.h"
/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/

#define Ccu7_HAL_IRQ_VENDOR_ID_C                   176

#define Ccu7_HAL_IRQ_MAJOR_VER_C                   4
#define Ccu7_HAL_IRQ_MINOR_VER_C                   4
#define Ccu7_HAL_IRQ_REVISION_VER_C                0

#define Ccu7_HAL_IRQ_SW_MAJOR_VER_C                3
#define Ccu7_HAL_IRQ_SW_MINOR_VER_C                0
#define Ccu7_HAL_IRQ_SW_PATCH_VER_C                0

#if (Ccu7_HAL_IRQ_VENDOR_ID_C != Ccu7_HAL_IRQ_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (Ccu7_HAL_IRQ_MAJOR_VER_C != Ccu7_HAL_IRQ_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (Ccu7_HAL_IRQ_MINOR_VER_C != Ccu7_HAL_IRQ_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (Ccu7_HAL_IRQ_REVISION_VER_C != Ccu7_HAL_IRQ_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (Ccu7_HAL_IRQ_SW_MAJOR_VER_C != Ccu7_HAL_IRQ_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (Ccu7_HAL_IRQ_SW_MINOR_VER_C != Ccu7_HAL_IRQ_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (Ccu7_HAL_IRQ_SW_PATCH_VER_C != Ccu7_HAL_IRQ_SW_PATCH_VER_H)
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
*                                      LOCAL FUNCTION
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ISR(ICU_CCU7_0_ISR)
{
    uint8 chflag = 0u;
    chflag = ICU_CCU7_LLD_GetIsCC7xR(CCU7_INS0, CCU7_CH_0);
    if(chflag != 0u)
    {
        chflag = 0u;
        Icu_Ccu7_ProcessInterrupt(CCU7_INS0,CCU7_CH_0);
    }

    chflag = ICU_CCU7_LLD_GetIsCC7xR(CCU7_INS0, CCU7_CH_1);
    if(chflag != 0u)
    {
        chflag = 0u;
        Icu_Ccu7_ProcessInterrupt(CCU7_INS0,CCU7_CH_1);
    }

    chflag = ICU_CCU7_LLD_GetIsCC7xR(CCU7_INS0, CCU7_CH_2);
    if(chflag != 0u)
    {
        chflag = 0u;
        Icu_Ccu7_ProcessInterrupt(CCU7_INS0,CCU7_CH_2);
    }

}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ISR(ICU_CCU7_1_ISR)
{
    uint8 chflag = 0u;
    chflag = ICU_CCU7_LLD_GetIsCC7xR(CCU7_INS1, CCU7_CH_0);
    if(chflag != 0u)
    {
        chflag = 0u;
        Icu_Ccu7_ProcessInterrupt(CCU7_INS1,CCU7_CH_0);
    }

    chflag = ICU_CCU7_LLD_GetIsCC7xR(CCU7_INS1, CCU7_CH_1);
    if(chflag != 0u)
    {
        chflag = 0u;
        Icu_Ccu7_ProcessInterrupt(CCU7_INS1,CCU7_CH_1);
    }

    chflag = ICU_CCU7_LLD_GetIsCC7xR(CCU7_INS1, CCU7_CH_2);
    if(chflag != 0u)
    {
        chflag = 0u;
        Icu_Ccu7_ProcessInterrupt(CCU7_INS1,CCU7_CH_2);
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */
#ifdef __cplusplus
}
#endif
