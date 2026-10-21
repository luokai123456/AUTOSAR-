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
*   @file    Mcu_HAL_Wrapper.c
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Mcu MCAL driver.
*
*   @addtogroup Mcu
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Mcu_LLDriver.h" /*PRQA S 0380*/
#include "Mcu_HAL_Wrapper.h"

/*====================================================================================================
HEAD FILE VERSION INFORMATION
====================================================================================================*/
#define MCU_HAL_VENDOR_ID_C                     176
#define MCU_HAL_AR_MAJOR_VER_C                  4
#define MCU_HAL_AR_MINOR_VER_C                  4
#define MCU_HAL_AR_PATCH_VER_C                  0
#define MCU_HAL_SW_MAJOR_VER_C                  3
#define MCU_HAL_SW_MINOR_VER_C                  0
#define MCU_HAL_SW_PATCH_VER_C                  0
/*====================================================================================================
FILE VERSION CHECKS
====================================================================================================*/
/* Check if current file and MCU header file are of the same vendor */
#if (MCU_HAL_VENDOR_ID != MCU_HAL_VENDOR_ID_C)
#error "NON-MATCHED DATA : MCU_HAL_VENDOR_ID_C"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#if (MCU_HAL_AR_MAJOR_VER != MCU_HAL_AR_MAJOR_VER_C)
#error "NON-MATCHED DATA : MCU_HAL_AR_MAJOR_VER_C"
#endif
#if (MCU_HAL_AR_MINOR_VER != MCU_HAL_AR_MINOR_VER_C)
#error "NON-MATCHED DATA : MCU_HAL_AR_MINOR_VER_C"
#endif
#if (MCU_HAL_AR_PATCH_VER != MCU_HAL_AR_PATCH_VER_C)
#error "NON-MATCHED DATA : MCU_HAL_AR_PATCH_VER_C"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (MCU_HAL_SW_MAJOR_VER != MCU_HAL_SW_MAJOR_VER_C)
#error "NON-MATCHED DATA : MCU_HAL_SW_MAJOR_VER_C"
#endif
#if (MCU_HAL_SW_MINOR_VER != MCU_HAL_SW_MINOR_VER_C)
#error "NON-MATCHED DATA : MCU_HAL_SW_MINOR_VER_C"
#endif
#if (MCU_HAL_SW_PATCH_VER != MCU_HAL_SW_PATCH_VER_C)
#error "NON-MATCHED DATA : MCU_HAL_SW_PATCH_VER_C"
#endif

#ifdef __cplusplus
}
#endif
