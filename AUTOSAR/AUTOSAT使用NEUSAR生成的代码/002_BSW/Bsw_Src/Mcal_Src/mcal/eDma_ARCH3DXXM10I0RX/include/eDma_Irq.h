/**************************************************************************** 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : eDma
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/

/**
*   @file    eDma_Irq.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of eDma MCAL driver.
*
*   @addtogroup eDma
*   @{
*/

#ifndef EDMA_IRQ_H_
#define EDMA_IRQ_H_

#ifdef __cplusplus
extern "C"{
#endif

#include "eDma_LLDriver.h"

#define EDMA_IRQ_H_VENDOR_ID                     176
#define EDMA_IRQ_H_AR_REL_MAJOR_VER              4
#define EDMA_IRQ_H_AR_REL_MINOR_VER              4
#define EDMA_IRQ_H_AR_REL_REV_VER                0
#define EDMA_IRQ_H_SW_MAJOR_VER                  3
#define EDMA_IRQ_H_SW_MINOR_VER                  0
#define EDMA_IRQ_H_SW_PATCH_VER                  0

#if (EDMA_CFG_H_VENDOR_ID != EDMA_IRQ_H_VENDOR_ID)
    #error " NON-MATCHED DATA : EDMA_IRQ_H_VENDOR_ID "
#endif
#if (EDMA_CFG_H_AR_REL_MAJOR_VER != EDMA_IRQ_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_H_AR_REL_MAJOR_VER "
#endif
#if (EDMA_CFG_H_AR_REL_MINOR_VER != EDMA_IRQ_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_H_AR_REL_MINOR_VER "
#endif
#if (EDMA_CFG_H_AR_REL_REV_VER != EDMA_IRQ_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_H_AR_REL_REV_VER "
#endif
#if (EDMA_CFG_H_SW_MAJOR_VER != EDMA_IRQ_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_H_SW_MAJOR_VER "
#endif
#if (EDMA_CFG_H_SW_MINOR_VER != EDMA_IRQ_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_H_SW_MINOR_VER "
#endif
#if (EDMA_CFG_H_SW_PATCH_VER != EDMA_IRQ_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_H_SW_PATCH_VER "
#endif

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch0_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch1_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch2_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch3_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch4_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch5_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch6_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch7_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch8_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch9_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch10_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch11_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch12_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch13_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch14_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch15_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch16_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch17_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch18_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch19_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch20_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch21_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch22_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch23_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch24_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch25_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch26_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch27_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch28_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch29_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch30_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch31_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch32_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch33_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch34_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch35_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch36_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch37_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch38_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch39_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch40_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch41_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch42_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch43_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch44_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch45_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch46_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch47_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch48_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch49_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch50_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch51_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch52_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch53_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch54_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch55_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch56_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch57_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch58_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch59_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch60_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch61_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch62_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch63_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch64_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch65_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch66_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch67_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch68_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch69_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch70_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch71_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch72_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch73_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch74_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch75_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch76_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch77_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch78_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch79_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch80_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch81_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch82_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch83_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch84_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch85_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch86_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch87_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch88_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch89_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch90_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch91_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch92_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch93_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch94_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch95_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch96_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch97_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch98_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch99_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch100_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch101_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch102_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch103_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch104_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch105_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch106_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch107_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch108_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch109_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch110_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch111_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch112_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch113_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch114_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch115_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch116_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch117_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch118_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch119_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch120_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch121_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch122_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch123_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch124_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch125_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch126_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch127_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch0_CH127_ErrIRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#ifdef __cplusplus
}
#endif

#endif /* EDMA_LLD__H_ */
