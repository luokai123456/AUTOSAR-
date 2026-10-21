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
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    Mcu_Irq.c
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Mcu MCAL driver.
*
*   @addtogroup Mcu
*   @{
*/
/*PRQA S 0380 EOF*/
#ifdef __cplusplus
extern "C"{
#endif

#include "Mcu_LLDriver.h"
#include "Mcu_Irq.h"

/*====================================================================================================
HEAD FILE VERSION INFORMATION
====================================================================================================*/
#define MCU_IRQ_VENDOR_ID_C                     176
#define MCU_IRQ_AR_MAJOR_VER_C                  4
#define MCU_IRQ_AR_MINOR_VER_C                  4
#define MCU_IRQ_AR_PATCH_VER_C                  0
#define MCU_IRQ_SW_MAJOR_VER_C                  3
#define MCU_IRQ_SW_MINOR_VER_C                  0
#define MCU_IRQ_SW_PATCH_VER_C                  0
/*====================================================================================================
FILE VERSION CHECKS
====================================================================================================*/
/* Check if current file and MCU header file are of the same vendor */
#if (MCU_IRQ_VENDOR_ID != MCU_IRQ_VENDOR_ID_C)
#error "NON-MATCHED DATA : MCU_IRQ_VENDOR_ID_C"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#if (MCU_IRQ_AR_MAJOR_VER != MCU_IRQ_AR_MAJOR_VER_C)
#error "NON-MATCHED DATA : MCU_IRQ_AR_MAJOR_VER_C"
#endif
#if (MCU_IRQ_AR_MINOR_VER != MCU_IRQ_AR_MINOR_VER_C)
#error "NON-MATCHED DATA : MCU_IRQ_AR_MINOR_VER_C"
#endif
#if (MCU_IRQ_AR_PATCH_VER != MCU_IRQ_AR_PATCH_VER_C)
#error "NON-MATCHED DATA : MCU_IRQ_AR_PATCH_VER_C"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (MCU_IRQ_SW_MAJOR_VER != MCU_IRQ_SW_MAJOR_VER_C)
#error "NON-MATCHED DATA : MCU_IRQ_SW_MAJOR_VER_C"
#endif
#if (MCU_IRQ_SW_MINOR_VER != MCU_IRQ_SW_MINOR_VER_C)
#error "NON-MATCHED DATA : MCU_IRQ_SW_MINOR_VER_C"
#endif
#if (MCU_IRQ_SW_PATCH_VER != MCU_IRQ_SW_PATCH_VER_C)
#error "NON-MATCHED DATA : MCU_IRQ_SW_PATCH_VER_C"
#endif


#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
ISR(Mcu_Xosc_Isr)
{
    (void)Mcu_LLD_XoscISR();
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/* Vector # 251 MC_ME 0 ME_IS[I_SAFE] */
/* Vector # 252 MC_ME 1 ME_IS[I_MTC] */
/* Vector # 253 MC_ME 2 ME_IS[I_IMODE] */
/* Vector # 254 MC_ME 3 ME_IS[I_ICONF] */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
ISR(Mcu_InvalidConfig_Isr)
{
    (void)Mcu_LLD_InvalidConfig_ISR();
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
ISR(Mcu_InvalidMode_Isr)
{
    (void)Mcu_LLD_InvalidMode_ISR();
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
ISR(Mcu_SafeMode_Isr)
{
    (void)Mcu_LLD_SafeMode_ISR();
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
ISR(Mcu_ModeComplete_Isr)
{
    (void)Mcu_LLD_ModeComplete_ISR();
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/* Internal voltage out of range ISR. */
ISR(Mcu_VoltageError_Isr)
{
    (void)Mcu_LLD_VoltageError_ISR();
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/*  Chip temperature ISR. */
ISR(Mcu_TemperatureError_Isr)
{
    (void)Mcu_LLD_TemperatureErrorError_ISR();
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
ISR(Mcu_Fccu_Isr)
{
    #if MCU_FCCU_ENABLE == STD_ON
    (void)Mcu_LLD_Fccu_ISR();
    #endif
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"




#ifdef __cplusplus
}
#endif
