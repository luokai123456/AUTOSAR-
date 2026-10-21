/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : Adc
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : -
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/

/**
*   @file    Adc_HAL_Wrapper.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Adc MCAL driver.
*
*   @addtogroup Adc
*   @{
*/

#ifndef ADC_HAL_WRAPPER_H
#define ADC_HAL_WRAPPER_H

#include "Adc.h"

#define ADC_HAL_WRA_H_VENDOR_ID                     176
#define ADC_HAL_WRA_H_AR_REL_MAJOR_VER              4
#define ADC_HAL_WRA_H_AR_REL_MINOR_VER              4
#define ADC_HAL_WRA_H_AR_REL_REV_VER                0
#define ADC_HAL_WRA_H_SW_MAJOR_VER                  3
#define ADC_HAL_WRA_H_SW_MINOR_VER                  0
#define ADC_HAL_WRA_H_SW_PATCH_VER                  0

#if (ADC_VENDOR_ID               != ADC_HAL_WRA_H_VENDOR_ID)
    #error " NON-MATCHED DATA : ADC_HAL_WRA_H_VENDOR_ID "
#endif
#if (ADC_AR_REL_MAJOR_VER    != ADC_HAL_WRA_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ADC_HAL_WRA_H_AR_REL_MAJOR_VER "
#endif
#if (ADC_AR_REL_MINOR_VER    != ADC_HAL_WRA_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ADC_HAL_WRA_H_AR_REL_MINOR_VER "
#endif
#if (ADC_AR_REL_REV_VER != ADC_HAL_WRA_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ADC_HAL_WRA_H_AR_REL_REV_VER "
#endif
#if (ADC_SW_MAJOR_VER        != ADC_HAL_WRA_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ADC_HAL_WRA_H_SW_MAJOR_VER "
#endif
#if (ADC_SW_MINOR_VER        != ADC_HAL_WRA_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ADC_HAL_WRA_H_SW_MINOR_VER "
#endif
#if (ADC_SW_PATCH_VER        != ADC_HAL_WRA_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ADC_HAL_WRA_H_SW_PATCH_VER "
#endif

extern VAR(Adc_RunningGroupType, ADC_VAR) sAdc_RunningGroup[ADC_CORE_NUM][ADC_CONFIG_GROUPS];
#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
extern VAR(uint16, ADC_VAR) Adc_gIrqMapping[ADC_CORE_NUM][56U];
#else
extern VAR(uint16, ADC_VAR) Adc_gIrqMapping[ADC_CORE_NUM][42U];
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */

#if (ADC_ENABLE_MULTICORE == STD_ON)
#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
extern VAR(Adc_GroupState, ADC_VAR) sAdc_GroupState[ADC_CONFIG_GROUPS];
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
extern VAR(Adc_AdcHwInitState, ADC_VAR) sAdc_AdcHwInitState[ADC_MAX_HW_UNITS];
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Std_ReturnType, ADC_CODE) Adc_Wrapper_Init \
( \
    P2CONST(Adc_ConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_ConfigPtr \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (STD_ON == ADC_DEINIT_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Std_ReturnType, ADC_CODE) Adc_Wrapper_DeInit(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif

#if (STD_ON == ADC_ENABLE_START_STOP_GROUP_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Std_ReturnType, ADC_CODE) Adc_Wrapper_StartGroupConversion \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_Group \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Std_ReturnType, ADC_CODE) Adc_Wrapper_StopGroupConversion \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_Group \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif

#if (STD_ON == ADC_HW_TRIGGER_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Std_ReturnType, ADC_CODE) Adc_Wrapper_EnableHardwareTrigger \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_Group \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Std_ReturnType, ADC_CODE) Adc_Wrapper_DisableHardwareTrigger \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_Group \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif

#endif /* ADC_HAL_WRAPPER_H */

/** @} */
