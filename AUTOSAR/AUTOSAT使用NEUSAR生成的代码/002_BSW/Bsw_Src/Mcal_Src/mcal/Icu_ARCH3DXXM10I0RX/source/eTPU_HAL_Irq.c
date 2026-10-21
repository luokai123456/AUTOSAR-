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
*   @file    eTPU_HAL_Irq.c
*   @version 3.0.0 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
/* PRQA S 0380 EOF */

/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#ifdef __cplusplus
extern "C"{
#endif
#include "eTPU_HAL_Irq.h"
#if (defined(RESOURCE_SUPPORT_ETPU))
#include "Icu_eTPU_LLDrivers.h"
#include "eTPU_LLDrivers.h"
#include "Icu_eTPU_HAL_Wrapper.h"
/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/

#define ETPU_HAL_IRQ_VENDOR_ID_C                   176

#define ETPU_HAL_IRQ_MAJOR_VER_C                   4
#define ETPU_HAL_IRQ_MINOR_VER_C                   4
#define ETPU_HAL_IRQ_REVISION_VER_C                0

#define ETPU_HAL_IRQ_SW_MAJOR_VER_C                3
#define ETPU_HAL_IRQ_SW_MINOR_VER_C                0
#define ETPU_HAL_IRQ_SW_PATCH_VER_C                0

#if (ETPU_HAL_IRQ_VENDOR_ID_C != ICU_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ETPU_HAL_IRQ_MAJOR_VER_C != ICU_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ETPU_HAL_IRQ_MINOR_VER_C != ICU_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ETPU_HAL_IRQ_REVISION_VER_C != ICU_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ETPU_HAL_IRQ_SW_MAJOR_VER_C != ICU_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ETPU_HAL_IRQ_SW_MINOR_VER_C != ICU_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ETPU_HAL_IRQ_SW_PATCH_VER_C != ICU_SW_PATCH_VER_H)
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
ETPU_INLINE FUNC(void, ICU_CODE) eTPU_LLD_IRQHandler
(
    VAR(uint8_t, AUTOMATIC) etpuIndex, \
    VAR(uint8_t, AUTOMATIC) ChanNum \
)
{
    /* Clear INT flag */
    if (etpuIndex == (uint8)eTPU_A)
    {
        ETPU_LLD_ClearChannelInterruptFlag(ETPU_INSTANCE_A_B, ETPU_A_CHANNLE(ChanNum));
    }
    else if (etpuIndex ==(uint8) eTPU_B)
    {
        ETPU_LLD_ClearChannelInterruptFlag(ETPU_INSTANCE_A_B, ETPU_B_CHANNLE(ChanNum));
    }
    else
    {
        ETPU_LLD_ClearChannelInterruptFlag(ETPU_INSTANCE_C, ETPU_C_CHANNLE(ChanNum));
    }

    eTpu_Channel_ProcessCommonIrq(etpuIndex, ChanNum);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH0_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 0);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH1_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 1);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH2_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 2);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH3_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 3);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH4_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 4);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH5_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 5);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH6_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 6);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH7_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 7);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH8_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 8);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH9_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 9);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH10_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 10);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH11_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 11);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH12_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 12);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH13_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 13);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH14_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 14);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH15_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 15);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH16_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 16);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH17_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 17);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH18_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 18);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH19_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 19);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH20_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 20);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH21_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 21);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH22_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 22);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH23_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 23);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH24_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 24);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH25_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 25);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH26_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 26);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH27_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 27);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH28_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 28);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH29_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 29);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH30_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 30);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUA_CH31_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 31);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH0_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 0);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH1_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 1);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH2_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 2);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH3_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 3);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH4_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 4);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH5_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 5);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH6_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 6);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH7_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 7);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH8_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 8);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH9_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 9);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH10_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 10);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH11_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 11);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH12_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 12);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH13_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 13);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH14_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 14);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH15_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 15);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH16_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 16);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH17_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 17);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH18_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 18);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH19_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 19);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH20_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 20);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH21_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 21);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH22_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 22);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH23_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 23);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH24_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 24);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH25_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 25);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH26_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 26);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH27_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 27);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH28_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 28);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH29_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 29);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH30_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 30);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUB_CH31_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 31);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH0_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 0);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH1_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 1);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH2_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 2);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH3_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 3);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH4_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 4);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH5_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 5);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH6_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 6);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH7_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 7);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH8_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 8);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH9_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 9);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH10_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 10);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH11_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 11);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH12_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 12);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH13_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 13);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH14_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 14);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH15_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 15);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH16_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 16);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH17_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 17);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH18_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 18);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH19_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 19);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH20_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 20);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH21_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 21);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH22_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 22);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH23_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 23);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH24_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 24);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH25_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 25);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH26_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 26);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH27_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 27);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH28_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 28);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH29_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 29);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH30_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 30);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eTPUC_CH31_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 31);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (defined(RESOURCE_SUPPORT_ETPU)) */
#ifdef __cplusplus
}
#endif

