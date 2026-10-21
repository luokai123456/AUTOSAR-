/**************************************************************************** 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : MCL
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    eDma_Irq.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of eDma MCAL driver.
*
*   @addtogroup eDma
*   @{
*/
/* PRQA S 0380 EOF */

#ifdef __cplusplus
extern "C"{
#endif

#include "eDma_Irq.h"

#define EDMA_IRQ_C_VENDOR_ID                     176
#define EDMA_IRQ_C_AR_REL_MAJOR_VER              4
#define EDMA_IRQ_C_AR_REL_MINOR_VER              4
#define EDMA_IRQ_C_AR_REL_REV_VER                0
#define EDMA_IRQ_C_SW_MAJOR_VER                  3
#define EDMA_IRQ_C_SW_MINOR_VER                  0
#define EDMA_IRQ_C_SW_PATCH_VER                  0

#if (EDMA_CFG_H_VENDOR_ID != EDMA_IRQ_C_VENDOR_ID)
    #error " NON-MATCHED DATA : EDMA_IRQ_C_VENDOR_ID "
#endif
#if (EDMA_CFG_H_AR_REL_MAJOR_VER != EDMA_IRQ_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_C_AR_REL_MAJOR_VER "
#endif
#if (EDMA_CFG_H_AR_REL_MINOR_VER != EDMA_IRQ_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_C_AR_REL_MINOR_VER "
#endif
#if (EDMA_CFG_H_AR_REL_REV_VER != EDMA_IRQ_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_C_AR_REL_REV_VER "
#endif
#if (EDMA_CFG_H_SW_MAJOR_VER != EDMA_IRQ_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_C_SW_MAJOR_VER "
#endif
#if (EDMA_CFG_H_SW_MINOR_VER != EDMA_IRQ_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_C_SW_MINOR_VER "
#endif
#if (EDMA_CFG_H_SW_PATCH_VER != EDMA_IRQ_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_C_SW_PATCH_VER "
#endif

#if EDMA_CH0_CH127_INT
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch0_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(0U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch1_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(1U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch2_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(2U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch3_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(3U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch4_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(4U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch5_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(5U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch6_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(6U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch7_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(7U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch8_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(8U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch9_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(9U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch10_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(10U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch11_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(11U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch12_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(12U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch13_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(13U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch14_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(14U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch15_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(15U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch16_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(16U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch17_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(17U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch18_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(18U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch19_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(19U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch20_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(20U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch21_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(21U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch22_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(22U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch23_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(23U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch24_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(24U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch25_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(25U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch26_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(26U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch27_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(27U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch28_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(28U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch29_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(29U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch30_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(30U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch31_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(31U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch32_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(32U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch33_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(33U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch34_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(34U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch35_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(35U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch36_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(36U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch37_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(37U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch38_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(38U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch39_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(39U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch40_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(40U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch41_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(41U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch42_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(42U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch43_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(43U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch44_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(44U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch45_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(45U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch46_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(46U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch47_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(47U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch48_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(48U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch49_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(49U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch50_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(50U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch51_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(51U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch52_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(52U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch53_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(53U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch54_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(54U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch55_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(55U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch56_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(56U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch57_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(57U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch58_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(58U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch59_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(59U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch60_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(60U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch61_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(61U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch62_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(62U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch63_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(63U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch64_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(64U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch65_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(65U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch66_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(66U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch67_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(67U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch68_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(68U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch69_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(69U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch70_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(70U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch71_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(71U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch72_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(72U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch73_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(73U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch74_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(74U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch75_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(75U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch76_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(76U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch77_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(77U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch78_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(78U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch79_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(79U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch80_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(80U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch81_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(81U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch82_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(82U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch83_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(83U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch84_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(84U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch85_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(85U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch86_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(86U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch87_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(87U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch88_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(88U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch89_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(89U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch90_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(90U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch91_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(91U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch92_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(92U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch93_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(93U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch94_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(94U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch95_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(95U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch96_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(96U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch97_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(97U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch98_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(98U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch99_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(99U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch100_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(100U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch101_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(101U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch102_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(102U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch103_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(103U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch104_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(104U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch105_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(105U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch106_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(106U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch107_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(107U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch108_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(108U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch109_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(109U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch110_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(110U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch111_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(111U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch112_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(112U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch113_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(113U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch114_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(114U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch115_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(115U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch116_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(116U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch117_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(117U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch118_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(118U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch119_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(119U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch120_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(120U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch121_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(121U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch122_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(122U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch123_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(123U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch124_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(124U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch125_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(125U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch126_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(126U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch127_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(127U);
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch0_CH127_ErrIRQHandler(void)
{
    EDMA_Ch0_Ch127_Error_IRQHandler();
}
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#endif
#ifdef __cplusplus
}
#endif
