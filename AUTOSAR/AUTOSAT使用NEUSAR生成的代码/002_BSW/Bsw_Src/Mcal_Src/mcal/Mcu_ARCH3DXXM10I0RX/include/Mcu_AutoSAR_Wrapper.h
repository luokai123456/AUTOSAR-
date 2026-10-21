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
*   @file    Mcu_AutoSAR_Wrapper.h
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Mcu MCAL driver.
*
*   @addtogroup Mcu
*   @{
*/

#ifndef MCU_AUTOSAR_WRAPPER_H
#define MCU_AUTOSAR_WRAPPER_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Mcu_HAL_Wrapper.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define MCU_WAR_VENDOR_ID                   176
#define MCU_WAR_AR_MAJOR_VER                4
#define MCU_WAR_AR_MINOR_VER                4
#define MCU_WAR_AR_PATCH_VER                0
#define MCU_WAR_SW_MAJOR_VER                3
#define MCU_WAR_SW_MINOR_VER                0
#define MCU_WAR_SW_PATCH_VER                0
/*============================================FILE VERSION CHECKS===================================*/

/* Check if current file and MCU header file are of the same vendor */
#if (MCU_WAR_VENDOR_ID != MCU_CFG_VENDOR_ID)
#error "NON-MATCHED DATA : MCU_CFG_VENDOR_ID"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#if (MCU_WAR_AR_MAJOR_VER != MCU_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : MCU_CFG_AR_MAJOR_VER"
#endif
#if (MCU_WAR_AR_MINOR_VER != MCU_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : MCU_CFG_AR_MINOR_VER"
#endif
#if (MCU_WAR_AR_PATCH_VER != MCU_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : MCU_CFG_AR_PATCH_VER"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (MCU_WAR_SW_MAJOR_VER != MCU_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : MCU_CFG_SW_MAJOR_VER"
#endif
#if (MCU_WAR_SW_MINOR_VER != MCU_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : MCU_CFG_SW_MINOR_VER"
#endif
#if (MCU_WAR_SW_PATCH_VER != MCU_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : MCU_CFG_SW_PATCH_VER"
#endif




#define RESETREASON_MASK            ( MCU_POWER_ON_RESET \
                                    | MCU_EXT_POWER_ON_RESET \
                                    | MCU_SOFT_DES_RESET \
                                    | MCU_FCCU_FAIL_RESET \
                                    | MCU_STCU_UNRE_RESET \
                                    | MCU_FUNCTIONAL_RESET \
                                    | MCU_FLASH_FAIL_RESET \
                                    | MCU_JTAG_DES_RESET \
                                    | MCU_SSCH_DES_RESET \
                                    | MCU_HSM_DES_RESET \
                                    | MCU_TEMP_DES_RESET \
                                    | MCU_VOL_DES_RESET)

/*===================================FUNCTION PROTOTYPES==========================================*/

#define Mcu_Wrap_Init                Mcu_HAL_Init

#if (MCU_INIT_CLOCK == STD_ON)
#define Mcu_Wrap_InitClock           Mcu_HAL_InitClock  
#endif /* MCU_INIT_CLOCK == STD_ON */

#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_NO_PLL == STD_OFF)
#define Mcu_Wrap_DistributePllClock  Mcu_HAL_DistributePllClock
#endif /* MCU_NO_PLL == STD_OFF */
#endif /* MCU_INIT_CLOCK == STD_ON */

#define Mcu_Wrap_GetResetReason      Mcu_HAL_GetResetReason

#define Mcu_Wrap_GetResetRaw         Mcu_HAL_GetResetRaw

#define Mcu_Wrap_SetMode             Mcu_HAL_SetMode

#if (MCU_PERFORM_RESET_API == STD_ON)
#define Mcu_Wrap_PerformReset        Mcu_HAL_PerformReset
#endif

#if (MCU_GET_RAM_STATE_API == STD_ON)
#define Mcu_Wrap_GetRamState         Mcu_HAL_GetRamState
#endif

#if (MCU_FCCU_ENABLE == STD_ON)
#define Mcu_Wrap_FccuInit            Mcu_HAL_FccuInit
#define Mcu_Wrap_FccuClearFaults     Mcu_HAL_FccuClearFaults
#endif

#define Mcu_Wrap_PeriModeSet         Mcu_HAL_PeriModeSet

#define Mcu_Wrap_PeriResetPend       Mcu_HAL_PeriResetPend

#define Mcu_Wrap_PeriResetClose      Mcu_HAL_PeriResetClose

#define Mcu_Wrap_CoreSynchronise     Mcu_HAL_CoreSynchronise

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE)Mcu_Wrap_InitRamSection
(
    P2CONST( Mcu_RamConfigType, AUTOMATIC, MCU_APPL_CONST) pMcu_RamConfigPtr
);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_NO_PLL == STD_OFF)
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Mcu_PllStatusType, MCU_CODE) Mcu_Wrap_GetPllStatus( VAR(void, AUTOMATIC) );
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
#endif /* MCU_NO_PLL == STD_OFF */
#endif /* MCU_INIT_CLOCK == STD_ON */

#define Mcu_Wrap_PctlPeriRunSet   Mcu_HAL_PctlPeriRunSet    

#define Mcu_Wrap_RgmlPeriRstSet   Mcu_HAL_RgmlPeriRstSet

#ifdef __cplusplus
}
#endif

#endif /* _MCU_WAR_H_ */
