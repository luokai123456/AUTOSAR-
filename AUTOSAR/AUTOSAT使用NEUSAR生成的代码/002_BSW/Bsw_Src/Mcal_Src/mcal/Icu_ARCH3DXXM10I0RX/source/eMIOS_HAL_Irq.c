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
*   @file    eMIOS_HAL_Irq.c
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
#include "eMIOS_HAL_Irq.h"
#include "eMIOS_LLDriver.h"
#include "Icu_Cfg.h"
#include "Icu.h"
/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define EMIOS_HAL_IRQ_VENDOR_ID_C                   176

#define EMIOS_HAL_IRQ_MAJOR_VER_C                   4
#define EMIOS_HAL_IRQ_MINOR_VER_C                   4
#define EMIOS_HAL_IRQ_REVISION_VER_C                0

#define EMIOS_HAL_IRQ_SW_MAJOR_VER_C                3
#define EMIOS_HAL_IRQ_SW_MINOR_VER_C                0
#define EMIOS_HAL_IRQ_SW_PATCH_VER_C                0

#if (EMIOS_HAL_IRQ_VENDOR_ID_C != ICU_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (EMIOS_HAL_IRQ_MAJOR_VER_C != ICU_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (EMIOS_HAL_IRQ_MINOR_VER_C != ICU_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (EMIOS_HAL_IRQ_REVISION_VER_C != ICU_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (EMIOS_HAL_IRQ_SW_MAJOR_VER_C != ICU_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (EMIOS_HAL_IRQ_SW_MINOR_VER_C != ICU_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (EMIOS_HAL_IRQ_SW_PATCH_VER_C != ICU_SW_PATCH_VER_H)
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
ICU_INLINE FUNC(void, ICU_CODE) eMIOS_LLD_IRQHandler
(
    VAR(uint8_t, AUTOMATIC) emiosIndex, \
    VAR(uint8_t, AUTOMATIC) ChanNum \
)
{
    /* Clear INT flag */
    eMIOS_UC_Sn_ClearFLAG(emiosIndex, ChanNum);

    eMios_Channel_ProcessCommonIrq(emiosIndex, ChanNum);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if defined(RESOURCE_SUPPORT_EMIOS0)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH0_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 0);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH1_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 1);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH2_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 2);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH3_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 3);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH4_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 4);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH5_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 5);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH6_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 6);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH7_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 7);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH8_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 8);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH9_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 9);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH10_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 10);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH11_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 11);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH12_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 12);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH13_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 13);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH14_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 14);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH15_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 15);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH16_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 16);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH17_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 17);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH18_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 18);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH19_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 19);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH20_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 20);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH21_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 21);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH22_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 22);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH23_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 23);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH24_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 24);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH25_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 25);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH26_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 26);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH27_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 27);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH28_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 28);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH29_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 29);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH30_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 30);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS0_CH31_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_0, 31);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif


#if defined(RESOURCE_SUPPORT_EMIOS1)
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH0_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 0);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH1_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 1);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH2_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 2);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH3_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 3);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH4_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 4);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH5_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 5);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH6_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 6);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH7_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 7);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH8_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 8);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH9_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 9);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH10_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 10);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH11_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 11);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH12_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 12);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH13_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 13);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH14_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 14);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH15_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 15);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH16_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 16);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH17_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 17);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH18_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 18);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH19_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 19);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH20_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 20);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH21_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 21);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH22_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 22);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH23_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 23);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH24_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 24);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH25_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 25);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH26_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 26);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH27_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 27);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH28_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 28);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH29_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 29);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH30_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 30);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) eMIOS1_CH31_Handler(void)
{
    eMIOS_LLD_IRQHandler((uint8)EMIOS_INSTANCE_1, 31);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif

