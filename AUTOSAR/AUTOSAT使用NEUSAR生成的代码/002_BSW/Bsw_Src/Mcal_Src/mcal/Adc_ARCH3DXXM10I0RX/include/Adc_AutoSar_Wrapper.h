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
*   @file    Adc_AutoSar_Wrapper.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Adc MCAL driver.
*
*   @addtogroup Adc
*   @{
*/

#ifndef ADC_AUTOSAR_WRAPPER_H
#define ADC_AUTOSAR_WRAPPER_H

#include "Adc.h"

#define ADC_ATS_WRA_H_VENDOR_ID                     176
#define ADC_ATS_WRA_H_AR_REL_MAJOR_VER              4
#define ADC_ATS_WRA_H_AR_REL_MINOR_VER              4
#define ADC_ATS_WRA_H_AR_REL_REV_VER                0
#define ADC_ATS_WRA_H_SW_MAJOR_VER                  3
#define ADC_ATS_WRA_H_SW_MINOR_VER                  0
#define ADC_ATS_WRA_H_SW_PATCH_VER                  0

#if (ADC_VENDOR_ID               != ADC_ATS_WRA_H_VENDOR_ID)
    #error " NON-MATCHED DATA : ADC_ATS_WRA_H_VENDOR_ID "
#endif
#if (ADC_AR_REL_MAJOR_VER    != ADC_ATS_WRA_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ADC_ATS_WRA_H_AR_REL_MAJOR_VER "
#endif
#if (ADC_AR_REL_MINOR_VER    != ADC_ATS_WRA_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ADC_ATS_WRA_H_AR_RELEASE_MINOR_VERSION_PLUGIN "
#endif
#if (ADC_AR_REL_REV_VER != ADC_ATS_WRA_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ADC_ATS_WRA_H_AR_RELEASE_REVISION_VERSION_PLUGIN "
#endif
#if (ADC_SW_MAJOR_VER        != ADC_ATS_WRA_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ADC_ATS_WRA_H_SW_MAJOR_VER_PLUGIN "
#endif
#if (ADC_SW_MINOR_VER        != ADC_ATS_WRA_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ADC_ATS_WRA_H_SW_MINOR_VER_PLUGIN "
#endif
#if (ADC_SW_PATCH_VER        != ADC_ATS_WRA_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ADC_ATS_WRA_H_SW_PATCH_VER_PLUGIN "
#endif

extern P2CONST(Adc_ConfigType, ADC_CONST, ADC_APPL_CONST) Adc_ConfigPtr[ADC_CORE_NUM];
extern VAR(Adc_GlobalStatusType, ADC_VAR) Adc_GlobalStatus[ADC_CORE_NUM];
extern VAR(Adc_RunningGroupType, ADC_VAR) sAdc_RunningGroup[ADC_CORE_NUM][ADC_CONFIG_GROUPS];
extern VAR(Adc_RunningHwUnitType, ADC_VAR) sAdc_RunningUnit[ADC_CORE_NUM][ADC_MAX_HW_UNITS];
extern VAR(uint8, ADC_VAR) u8Adc_MainFunctionFlag[ADC_CONFIG_GROUPS][ADC_CORE_NUM];

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

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
extern VAR(uint8, ADC_VAR) Adc_HwInitStateFlag;
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_AutoSar_Wrapper_Init \
( \
    P2CONST(Adc_ConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_ConfigPtr \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (STD_ON == ADC_DEINIT_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Std_ReturnType, ADC_CODE) Adc_AutoSar_Wrapper_DeInit(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif

#if (STD_ON == ADC_ENABLE_START_STOP_GROUP_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_AutoSar_Wrapper_StartGroupConversion \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_Group \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_AutoSar_Wrapper_StopGroupConversion \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_Group \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif

#if(STD_ON == ADC_ENABLE_QUEUING)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_SchedulerMain(VAR(Adc_HwUnitType, AUTOMATIC) u16Adc_HwUnitId);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif

#if (STD_ON == ADC_READ_GROUP_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Std_ReturnType, ADC_CODE) Adc_AutoSar_Wrapper_ReadGroup \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_Group, \
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pAdc_DataBufferPtr \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif

#if (STD_ON == ADC_HW_TRIGGER_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_AutoSar_Wrapper_EnableHardwareTrigger \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_Group \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_AutoSar_Wrapper_DisableHardwareTrigger \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_Group \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Adc_StreamNumSampleType, ADC_CODE) Adc_AutoSar_Wrapper_GetStreamLastPointer \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_Group, \
    P2P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pAdc_PtrToSamplePtr \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Std_ReturnType, ADC_CODE) Adc_AutoSar_Wrapper_SetPowerState \
( \
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) pAdc_Result \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif

#endif /* ADC_AUTOSAR_WRAPPER_H */

/** @} */
