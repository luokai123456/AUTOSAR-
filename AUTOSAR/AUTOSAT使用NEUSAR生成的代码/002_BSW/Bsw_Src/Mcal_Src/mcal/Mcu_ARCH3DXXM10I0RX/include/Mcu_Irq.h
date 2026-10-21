/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC
*   Peripheral           : Mcu
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
*   @file    Mcu_Irq.h
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Mcu MCAL driver.
*
*   @addtogroup Mcu
*   @{
*/
#ifndef MCU_IRQ_H
#define MCU_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Mcu.h"

/*====================================================================================================
HEAD FILE VERSION INFORMATION
====================================================================================================*/
#define MCU_IRQ_VENDOR_ID                     176
#define MCU_IRQ_AR_MAJOR_VER                  4
#define MCU_IRQ_AR_MINOR_VER                  4
#define MCU_IRQ_AR_PATCH_VER                  0
#define MCU_IRQ_SW_MAJOR_VER                  3
#define MCU_IRQ_SW_MINOR_VER                  0
#define MCU_IRQ_SW_PATCH_VER                  0
/*====================================================================================================
FILE VERSION CHECKS
====================================================================================================*/
/* Check if current file and MCU header file are of the same vendor */
#if (MCU_VENDOR_ID != MCU_IRQ_VENDOR_ID)
#error "NON-MATCHED DATA : MCU_IRQ_VENDOR_ID"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#if (MCU_AR_RELEASE_MAJOR_VERSION != MCU_IRQ_AR_MAJOR_VER)
#error "NON-MATCHED DATA : MCU_IRQ_AR_MAJOR_VER"
#endif
#if (MCU_AR_RELEASE_MINOR_VERSION != MCU_IRQ_AR_MINOR_VER)
#error "NON-MATCHED DATA : MCU_IRQ_AR_MINOR_VER"
#endif
#if (MCU_AR_PATCH_VER != MCU_IRQ_AR_PATCH_VER)
#error "NON-MATCHED DATA : MCU_IRQ_AR_PATCH_VER"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (MCU_SW_MAJOR_VER != MCU_IRQ_SW_MAJOR_VER)
#error "NON-MATCHED DATA : MCU_IRQ_SW_MAJOR_VER"
#endif
#if (MCU_SW_MINOR_VER != MCU_IRQ_SW_MINOR_VER)
#error "NON-MATCHED DATA : MCU_IRQ_SW_MINOR_VER"
#endif
#if (MCU_SW_PATCH_VER != MCU_IRQ_SW_PATCH_VER)
#error "NON-MATCHED DATA : MCU_IRQ_SW_PATCH_VER"
#endif


#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
ISR(Mcu_Xosc_Isr);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
ISR(Mcu_InvalidConfig_Isr);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
ISR(Mcu_InvalidMode_Isr);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
ISR(Mcu_SafeMode_Isr);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
ISR(Mcu_ModeComplete_Isr);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
ISR(Mcu_VoltageError_Isr);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
ISR(Mcu_TemperatureError_Isr);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
ISR(Mcu_Fccu_Isr);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"



#ifdef __cplusplus
}
#endif

#endif
