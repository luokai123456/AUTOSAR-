/* PRQA S 2053 EOF */ 
/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : Wdg
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : -
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*   *****************************************************************************/
/**
*   @file    Wdg_irq.h
*   @version 3.0.0
*
*   @addtogroup Wdg
*   @{
*/
#ifndef WDG_IRQ_H
#define WDG_IRQ_H
#ifdef __cplusplus
extern "C"{
#endif

#include "Mcal.h"
#include "Wdg_Cfg.h"

#define WDG_IRQ_H_VENDOR_ID                   176
#define WDG_IRQ_H_VER_MAJOR                  4
#define WDG_IRQ_H_VER_MINOR                  4
#define WDG_IRQ_H_VER_REVISION               0
#define WDG_IRQ_H_SW_VER_MAJOR               3
#define WDG_IRQ_H_SW_VER_MINOR               0
#define WDG_IRQ_H_SW_VER_PATCH               0

#if (WDG_IRQ_H_VENDOR_ID != WDG_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : WDG_IRQ_H_VENDOR_ID "
#endif
#if (WDG_IRQ_H_VER_MAJOR != WDG_CFG_H_VER_MAJOR)
    #error " NON-MATCHED DATA : WDG_IRQ_H_VER_MAJOR "
#endif
#if (WDG_IRQ_H_VER_MINOR != WDG_CFG_H_VER_MINOR)
    #error " NON-MATCHED DATA : WDG_IRQ_H_VER_MINOR "
#endif
#if (WDG_IRQ_H_VER_REVISION != WDG_CFG_H_VER_REVISION)
    #error " NON-MATCHED DATA : WDG_IRQ_H_VER_REVISION "
#endif
#if (WDG_IRQ_H_SW_VER_MAJOR != WDG_CFG_H_SW_VER_MAJOR)
    #error " NON-MATCHED DATA : WDG_IRQ_H_SW_VER_MAJOR "
#endif
#if (WDG_IRQ_H_SW_VER_MINOR != WDG_CFG_H_SW_VER_MINOR)
    #error " NON-MATCHED DATA : WDG_IRQ_H_SW_VER_MINOR "
#endif
#if (WDG_IRQ_H_SW_VER_PATCH != WDG_CFG_H_SW_VER_PATCH)
    #error " NON-MATCHED DATA : WDG_IRQ_H_SW_VER_PATCH "
#endif

#ifdef USER_SWT0_IRQ
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(void, WDG_CODE) SWT0_ISR(void);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
#endif

#ifdef USER_SWT1_IRQ
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(void, WDG_CODE) SWT1_ISR(void);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
#endif

#ifdef USER_SWT2_IRQ
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(void, WDG_CODE) SWT2_ISR(void);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
#endif

#ifdef USER_SWT3_IRQ
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(void, WDG_CODE) SWT3_ISR(void);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
#endif


#ifdef USER_SWT4_IRQ
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif

#include "Wdg_MemMap.h"
FUNC(void, WDG_CODE) SWT4_ISR(void);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
#endif

#ifdef USER_SWT5_IRQ
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif

#include "Wdg_MemMap.h"
FUNC(void, WDG_CODE) SWT5_ISR(void);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
#endif

#ifdef USER_SWT6_IRQ
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif

#include "Wdg_MemMap.h"
FUNC(void, WDG_CODE) SWT6_ISR(void);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
#endif
#ifdef __cplusplus
}
#endif
/** @} */
#endif
