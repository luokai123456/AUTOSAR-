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
*   @file    Mcu_HAL_Wrapper.h
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Mcu MCAL driver.
*
*   @addtogroup Mcu
*   @{
*/
#ifndef MCU_HAL_WRAPPER_H
#define MCU_HAL_WRAPPER_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Mcu.h"

/*====================================================================================================
HEAD FILE VERSION INFORMATION
====================================================================================================*/
#define MCU_HAL_VENDOR_ID                     176
#define MCU_HAL_AR_MAJOR_VER                  4
#define MCU_HAL_AR_MINOR_VER                  4
#define MCU_HAL_AR_PATCH_VER                  0
#define MCU_HAL_SW_MAJOR_VER                  3
#define MCU_HAL_SW_MINOR_VER                  0
#define MCU_HAL_SW_PATCH_VER                  0
/*====================================================================================================
FILE VERSION CHECKS
====================================================================================================*/
/* Check if current file and MCU header file are of the same vendor */
#if (MCU_VENDOR_ID != MCU_HAL_VENDOR_ID)
#error "NON-MATCHED DATA : MCU_HAL_VENDOR_ID"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#if (MCU_AR_RELEASE_MAJOR_VERSION != MCU_HAL_AR_MAJOR_VER)
#error "NON-MATCHED DATA : MCU_HAL_AR_MAJOR_VER"
#endif
#if (MCU_AR_RELEASE_MINOR_VERSION != MCU_HAL_AR_MINOR_VER)
#error "NON-MATCHED DATA : MCU_HAL_AR_MINOR_VER"
#endif
#if (MCU_AR_PATCH_VER != MCU_HAL_AR_PATCH_VER)
#error "NON-MATCHED DATA : MCU_HAL_AR_PATCH_VER"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (MCU_SW_MAJOR_VER != MCU_HAL_SW_MAJOR_VER)
#error "NON-MATCHED DATA : MCU_HAL_SW_MAJOR_VER"
#endif
#if (MCU_SW_MINOR_VER != MCU_HAL_SW_MINOR_VER)
#error "NON-MATCHED DATA : MCU_HAL_SW_MINOR_VER"
#endif
#if (MCU_SW_PATCH_VER != MCU_HAL_SW_PATCH_VER)
#error "NON-MATCHED DATA : MCU_HAL_SW_PATCH_VER"
#endif

#define Mcu_HAL_Init               Mcu_LLD_Init

#define Mcu_HAL_InitClock          Mcu_LLD_Clock_Init

#define Mcu_HAL_GetPllStatus       Mcu_LLD_GetPllStatus

#define Mcu_HAL_DistributePllClock Mcu_LLD_DistributePllClock

#define Mcu_HAL_GetResetReason     Mcu_LLD_GetResetReason

#define Mcu_HAL_GetResetRaw        Mcu_LLD_GetResetRaw

#define Mcu_HAL_SetMode            Mcu_LLD_SetMode

#define Mcu_HAL_PerformReset       Mcu_LLD_PerformReset

#define Mcu_HAL_GetRamState        Mcu_LLD_GetRamState

#if MCU_FCCU_ENABLE == STD_ON
#define Mcu_HAL_FccuInit           Mcu_LLD_FccuInit
#define Mcu_HAL_FccuClearFaults    FCCU_LLD_ClearFaults
#endif

#define Mcu_HAL_PeriModeSet        Mcu_LLD_PeriModeSet

#define Mcu_HAL_PeriResetPend      Mcu_LLD_PeriResetPend

#define Mcu_HAL_PeriResetClose     Mcu_LLD_PeriResetClose

#define Mcu_HAL_CoreSynchronise    Mcu_LLD_CoreSynchronise

#define Mcu_HAL_PctlPeriRunSet     Mcu_LLD_PctlPeriRunSet

#define Mcu_HAL_RgmlPeriRstSet     Mcu_LLD_RgmlPeriRstSet

#ifdef __cplusplus
}
#endif

#endif
