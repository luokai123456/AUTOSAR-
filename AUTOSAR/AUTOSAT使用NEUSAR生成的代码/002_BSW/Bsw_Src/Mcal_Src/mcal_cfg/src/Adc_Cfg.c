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
*   @file    Adc_Cfg.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Adc MCAL driver.
*
*   @addtogroup Adc
*   @{
*/
/* PRQA S 0380, 2053, 4342, 0704 EOF */
#ifdef __cplusplus
extern "C"{
#endif

#include "Adc.h"
#include "Adc_Irq.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/

#define ADC_PB_VENDOR_ID_C                 176
#define ADC_PB_AR_MAJOR_VER_C              4
#define ADC_PB_AR_MINOR_VER_C              4
#define ADC_PB_AR_PATCH_VER_C              0
#define ADC_PB_SW_MAJOR_VER_C              3
#define ADC_PB_SW_MINOR_VER_C              0
#define ADC_PB_SW_PATCH_VER_C              0

/*============================================FILE VERSION CHECKS===================================*/

#if (ADC_VENDOR_ID != ADC_PB_VENDOR_ID_C)
#error "NON-MATCHED DATA : ADC_PB_VENDOR_ID_C"
#endif

/* Check if current file and ADC header file are of the same Autosar version */
#if (ADC_AR_REL_MAJOR_VER != ADC_PB_AR_MAJOR_VER_C)
#error "NON-MATCHED DATA : ADC_PB_AR_MAJOR_VER_C"
#endif
#if (ADC_AR_REL_MINOR_VER != ADC_PB_AR_MINOR_VER_C)
#error "NON-MATCHED DATA : ADC_PB_AR_MINOR_VER_C"
#endif
#if (ADC_AR_REL_REV_VER != ADC_PB_AR_PATCH_VER_C)
#error "NON-MATCHED DATA : ADC_PB_AR_PATCH_VER_C"
#endif

/* Check if current file and ADC header file are of the same Software version */
#if (ADC_SW_MAJOR_VER != ADC_PB_SW_MAJOR_VER_C)
#error "NON-MATCHED DATA : ADC_PB_SW_MAJOR_VER_C"
#endif
#if (ADC_SW_MINOR_VER != ADC_PB_SW_MINOR_VER_C)
#error "NON-MATCHED DATA : ADC_PB_SW_MINOR_VER_C"
#endif
#if (ADC_SW_PATCH_VER != ADC_PB_SW_PATCH_VER_C)
#error "NON-MATCHED DATA : ADC_PB_SW_PATCH_VER_C"
#endif

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit0_Group0_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit0_Group0_CmdBuf[4U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit0_Group0_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit0_Group0_ResultBuf[4U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit1_Group1_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit1_Group1_CmdBuf[2U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit1_Group1_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit1_Group1_ResultBuf[2U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit1_Group2_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit1_Group2_CmdBuf[4U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit1_Group2_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit1_Group2_ResultBuf[4U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit2_Group3_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit2_Group3_CmdBuf[2U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit2_Group3_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit2_Group3_ResultBuf[2U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit2_Group4_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit2_Group4_CmdBuf[4U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit2_Group4_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit2_Group4_ResultBuf[4U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit3_Group5_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit3_Group5_CmdBuf[2U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit3_Group5_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit3_Group5_ResultBuf[2U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit4_Group6_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit4_Group6_CmdBuf[2U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit4_Group6_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit4_Group6_ResultBuf[2U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit4_Group7_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit4_Group7_CmdBuf[2U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit4_Group7_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit4_Group7_ResultBuf[2U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit5_Group8_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit5_Group8_CmdBuf[2U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit5_Group8_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit5_Group8_ResultBuf[2U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit6_Group9_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit6_Group9_CmdBuf[2U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit6_Group9_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit6_Group9_ResultBuf[2U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit7_Group10_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit7_Group10_CmdBuf[4U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit7_Group10_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit7_Group10_ResultBuf[4U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit8_Group11_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit8_Group11_CmdBuf[4U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit8_Group11_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit8_Group11_ResultBuf[4U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit9_Group12_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit9_Group12_CmdBuf[2U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit9_Group12_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit9_Group12_ResultBuf[2U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit10_Group13_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit10_Group13_CmdBuf[2U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit10_Group13_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit10_Group13_ResultBuf[2U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit10_Group14_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit10_Group14_CmdBuf[4U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit10_Group14_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit10_Group14_ResultBuf[4U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit11_Group15_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit11_Group15_CmdBuf[2U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit11_Group15_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit11_Group15_ResultBuf[2U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit0_Group16_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit0_Group16_CmdBuf[4U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit0_Group16_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit0_Group16_ResultBuf[4U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit7_Group17_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit7_Group17_CmdBuf[2U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit7_Group17_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit7_Group17_ResultBuf[2U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit8_Group18_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit8_Group18_CmdBuf[4U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit8_Group18_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit8_Group18_ResultBuf[4U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit9_Group19_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit9_Group19_CmdBuf[4U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit9_Group19_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit9_Group19_ResultBuf[4U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit9_Group20_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit9_Group20_CmdBuf[4U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit9_Group20_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit9_Group20_ResultBuf[4U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit2_Group23_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit2_Group23_CmdBuf[2U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit2_Group23_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit2_Group23_ResultBuf[2U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit6_Group26_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit6_Group26_CmdBuf[16U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit6_Group26_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit6_Group26_ResultBuf[16U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit7_Group27_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit7_Group27_CmdBuf[8U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit7_Group27_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit7_Group27_ResultBuf[8U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"




#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_0[4U] =
{   
    {   /* Group_0 ChannelIndex_0: MCU_AN_TEMP_IGBT_IN1 CH1 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH1,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_0 ChannelIndex_1: MCU_AN_TEMP_IGBT_IN2 CH10 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH10,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_0 ChannelIndex_2: MCU_D_HS1_DIAG CH9 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH9,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_0 ChannelIndex_3: VDD5REF11 CH8 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH8,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_0[4U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_1[2U] =
{   
    {   /* Group_1 ChannelIndex_0: MCU_CUR_W_AN1 CH0 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_0,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH0,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_1 ChannelIndex_1: VDD5REF4 CH11 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_0,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH11,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_1[2U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_2[4U] =
{   
    {   /* Group_2 ChannelIndex_0: MCU_AN_TEMP_IGBT_IN3 CH1 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_2,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH1,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_2 ChannelIndex_1: MCU_D_HS5_DIAG CH2 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_2,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH2,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_2 ChannelIndex_2: MCU_D_HS9_DIAG CH8 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_2,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH8,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_2 ChannelIndex_3: MCU_D_HS10_DIAG CH9 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_2,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH9,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_2[4U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_3[2U] =
{   
    {   /* Group_3 ChannelIndex_0: MCU_CUR_U_AN0 CH0 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_0,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH0,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_3 ChannelIndex_1: VDD5REF3 CH3 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_0,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH3,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_3[2U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_4[4U] =
{   
    {   /* Group_4 ChannelIndex_0: MCU_D_HS7_DIAG CH9 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH9,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_4 ChannelIndex_1: MCU_D_HS8_DIAG CH2 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH2,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_4 ChannelIndex_2: AN_9015_ERRQ CH11 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH11,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_4 ChannelIndex_3: AN_OBC_Mic CH1 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH1,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_4[4U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_5[2U] =
{   
    {   /* Group_5 ChannelIndex_0: MCU_CUR_V_AN0 CH11 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_2,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH11,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_5 ChannelIndex_1: VDD5REF6 CH10 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_2,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH10,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_5[2U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_6[2U] =
{   
    {   /* Group_6 ChannelIndex_0: MCU_CUR_U_AN1 CH1 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_0,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH1,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_6 ChannelIndex_1: VDD5REF5 CH0 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_0,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH0,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_6[2U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_7[2U] =
{   
    {   /* Group_7 ChannelIndex_0: AN_OBC_ON_Mic CH2 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH2,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_7 ChannelIndex_1: AN_CAN_WK_Mic CH3 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH3,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_7[2U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_8[2U] =
{   
    {   /* Group_8 ChannelIndex_0: MCU_CUR_W_AN0 CH0 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_2,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH0,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_8 ChannelIndex_1: VDD5REF2 CH2 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_2,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH2,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_8[2U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_9[2U] =
{   
    {   /* Group_9 ChannelIndex_0: IN_AN1 CH3 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_0,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH3,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_9 ChannelIndex_1: VDD5REF10 CH2 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_0,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH2,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_9[2U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_10[4U] =
{   
    {   /* Group_10 ChannelIndex_0: AN_5Vsensor2 CH9 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH9,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_10 ChannelIndex_1: VDD5REF7 CH10 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH10,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_10 ChannelIndex_2: IN_AN2 CH3 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH3,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_10 ChannelIndex_3: IN_AN4 CH8 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH8,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_10[4U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_11[4U] =
{   
    {   /* Group_11 ChannelIndex_0: AN_DC_APlus1_Mic CH5 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_0,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH5,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_11 ChannelIndex_1: AN_CAN_5V CH4 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_0,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH4,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_11 ChannelIndex_2: AN_Driver_5V CH6 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_0,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH6,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_11 ChannelIndex_3: IN_AN11 CH2 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_0,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH2,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_11[4U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_12[2U] =
{   
    {   /* Group_12 ChannelIndex_0: MCU_AN_Motor_TEMP_N CH5 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH5,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_12 ChannelIndex_1: MCU_AN_Motor_TEMP_P CH4 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH4,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_12[2U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_13[2U] =
{   
    {   /* Group_13 ChannelIndex_0: MCU_CUR_V_AN1 CH7 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_0,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH7,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_13 ChannelIndex_1: VDD5REF1 CH6 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_0,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH6,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_13[2U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_14[4U] =
{   
    {   /* Group_14 ChannelIndex_0: MCU_LS_9_DIAG CH2 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH2,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_14 ChannelIndex_1: MCU_LS_11_DIAG CH3 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH3,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_14 ChannelIndex_2: MCU_LS_12_DIAG CH0 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH0,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_14 ChannelIndex_3: AN_1V8 CH5 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH5,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_14[4U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_15[2U] =
{   
    {   /* Group_15 ChannelIndex_0: AN_KEY_Mic CH9 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_2,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH9,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_15 ChannelIndex_1: AN_DC_APlus2_Mic CH3 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_2,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH3,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_15[2U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_16[4U] =
{   
    {   /* Group_16 ChannelIndex_0: MCU_D_HS3_DIAG CH11 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_3,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH11,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_16 ChannelIndex_1: MCU_D_HS4_DIAG CH0 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_3,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH0,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_16 ChannelIndex_2: MCU_D_HS6_DIAG CH2 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_3,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH2,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_16 ChannelIndex_3: MCU_LS_10_DIAG CH3 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_3,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH3,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_16[4U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_17[2U] =
{   
    {   /* Group_17 ChannelIndex_0: IN_AN7 CH2 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_3,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH2,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_17 ChannelIndex_1: IN_AN12 CH1 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_3,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH1,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_17[2U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_18[4U] =
{   
    {   /* Group_18 ChannelIndex_0: IN_AN3 CH11 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_3,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH11,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_18 ChannelIndex_1: IN_AN5 CH3 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_3,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH3,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_18 ChannelIndex_2: IN_AN6 CH10 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_3,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH10,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_18 ChannelIndex_3: IN_AN8 CH14 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_3,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH14,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_18[4U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_19[4U] =
{   
    {   /* Group_19 ChannelIndex_0: IN_AN10 CH15 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_4,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH15,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_19 ChannelIndex_1: IN_AN13 CH14 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_4,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH14,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_19 ChannelIndex_2: MCU_AN_HS1and7_CFB CH10 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_4,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH10,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_19 ChannelIndex_3: VDD5REF9 CH9 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_4,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH9,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_19[4U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_20[4U] =
{   
    {   /* Group_20 ChannelIndex_0: MCU_AN_HS2and8_CFB CH0 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_5,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH0,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_20 ChannelIndex_1: MCU_AN_HS3and9_CFB CH3 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_5,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH3,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_20 ChannelIndex_2: MCU_AN_HS4and10_CFB CH11 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_5,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH11,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_20 ChannelIndex_3: MCU_AN_HS5and6_CFB CH13 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_5,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH13,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_20[4U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_21[6U] =
{   
    {   /* Group_21 ChannelIndex_0: IN_AN14 CH12 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_2,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH12,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_21 ChannelIndex_1: VDD5REF8 CH15 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_2,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH15,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_21 ChannelIndex_2: AN_HV_Driver_5V CH8 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_2,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH8,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_21 ChannelIndex_3: AN_5Vsensor1 CH9 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_2,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH9,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_21 ChannelIndex_4: AN_12_RES_Mic CH13 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_2,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH13,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_21 ChannelIndex_5: AN_UBD_Mic CH0 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_2,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH0,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_21[6U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_22[2U] =
{   
    {   /* Group_22 ChannelIndex_0: MCU_AN_HV_DC2 CH3 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_5,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH3,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_22 ChannelIndex_1: MCU_D_HS2_DIAG CH10 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_5,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH10,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_22[2U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_23[2U] =
{   
    {   /* Group_23 ChannelIndex_0: AN_Temp_MCU CH8 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_3,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH8,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_23 ChannelIndex_1: AN_UBR_Mic CH10 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_3,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH10,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_23[2U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_24[2U] =
{   
    {   /* Group_24 ChannelIndex_0: IN_AN9 CH3 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_4,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH3,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_24 ChannelIndex_1: AN_Temp_SBC CH2 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_4,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH2,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_24[2U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_25[2U] =
{   
    {   /* Group_25 ChannelIndex_0: MCU_AN_HV_DC1 CH1 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_4,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH1,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_25 ChannelIndex_1: AN_F_V_PRE CH11 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_4,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH11,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_25[2U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_26[4U] =
{   
    {   /* Group_26 ChannelIndex_0: MCU_COS_N_FB CH1 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_4,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH1,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_26 ChannelIndex_1: MCU_COS_P_FB CH0 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_4,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH0,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_26 ChannelIndex_2: MCU_SIN_N_FB CH10 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_4,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH10,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_26 ChannelIndex_3: MCU_SIN_P_FB CH9 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_4,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH9,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_26[4U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_27[2U] =
{   
    {   /* Group_27 ChannelIndex_0: MCU_EXC_N_FB CH0 */
        .Eoq                = FALSE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_2,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH0,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
    {   /* Group_27 ChannelIndex_1: MCU_EXC_P_FB CH11 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_2,
        .LongSampTime       = EQADC_ADCLK_SAMPLING_CYCLES_2,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH11,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_27[2U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    },
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Adc_GroupConfigType, ADC_VAR) Group_Cfg[28U] =
{
	{   /* Group 0, ADC0, HardWareTrig */
        .HwUnitId            = 0U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN2_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit0_Group0_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN3_NUMBER,
        .ResultIrq           = &Eqadc0_DmaResult1,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit0_Group0_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_CIRCULAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 4U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_1,
        .HwTrigSrc           = EQADC_HW_TRIG_EMIOS0_CH16,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_NO_TRIG,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_0,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_0,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 1, ADC1, HardWareTrig */
        .HwUnitId            = 1U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN0_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit1_Group1_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN1_NUMBER,
        .ResultIrq           = &Eqadc0_DmaResult0,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit1_Group1_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_FALLING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 2U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_0,
        .HwTrigSrc           = EQADC_HW_TRIG_GTM_TRIG0_MEMBER0,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_7,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_1,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_1,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 2, ADC1, HardWareTrig */
        .HwUnitId            = 1U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN4_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit1_Group2_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN5_NUMBER,
        .ResultIrq           = &Eqadc0_DmaResult2,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit1_Group2_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 4U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_2,
        .HwTrigSrc           = EQADC_HW_TRIG_GTM_TRIG0_MEMBER0,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_7,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_2,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_2,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 3, ADC2, HardWareTrig */
        .HwUnitId            = 2U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN16_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit2_Group3_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN17_NUMBER,
        .ResultIrq           = &Eqadc1_DmaResult0,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit2_Group3_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_FALLING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 2U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_0,
        .HwTrigSrc           = EQADC_HW_TRIG_GTM_TRIG0_MEMBER0,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_7,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_3,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_3,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 4, ADC2, HardWareTrig */
        .HwUnitId            = 2U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN18_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit2_Group4_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN19_NUMBER,
        .ResultIrq           = &Eqadc1_DmaResult1,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit2_Group4_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 4U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_1,
        .HwTrigSrc           = EQADC_HW_TRIG_EMIOS0_CH17,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_NO_TRIG,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_4,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_4,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 5, ADC3, HardWareTrig */
        .HwUnitId            = 3U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN20_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit3_Group5_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN21_NUMBER,
        .ResultIrq           = &Eqadc1_DmaResult2,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit3_Group5_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_FALLING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 2U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_2,
        .HwTrigSrc           = EQADC_HW_TRIG_GTM_TRIG0_MEMBER0,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_7,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_5,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_5,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 6, ADC4, HardWareTrig */
        .HwUnitId            = 4U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN24_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit4_Group6_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN25_NUMBER,
        .ResultIrq           = &Eqadc2_DmaResult0,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit4_Group6_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_FALLING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 2U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_0,
        .HwTrigSrc           = EQADC_HW_TRIG_GTM_TRIG0_MEMBER0,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_7,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_6,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_6,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 7, ADC4, HardWareTrig */
        .HwUnitId            = 4U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN26_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit4_Group7_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN27_NUMBER,
        .ResultIrq           = &Eqadc2_DmaResult1,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit4_Group7_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_FALLING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 2U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_1,
        .HwTrigSrc           = EQADC_HW_TRIG_GTM_TRIG1_MEMBER11,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_2,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_7,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_7,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 8, ADC5, HardWareTrig */
        .HwUnitId            = 5U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN28_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit5_Group8_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN29_NUMBER,
        .ResultIrq           = &Eqadc2_DmaResult2,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit5_Group8_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_FALLING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 2U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_2,
        .HwTrigSrc           = EQADC_HW_TRIG_GTM_TRIG0_MEMBER0,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_7,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_8,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_8,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 9, ADC6, HardWareTrig */
        .HwUnitId            = 6U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN32_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit6_Group9_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN33_NUMBER,
        .ResultIrq           = &Eqadc3_DmaResult0,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit6_Group9_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 2U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_0,
        .HwTrigSrc           = EQADC_HW_TRIG_EMIOS0_CH18,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_NO_TRIG,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_9,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_9,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 10, ADC7, HardWareTrig */
        .HwUnitId            = 7U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN34_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit7_Group10_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN35_NUMBER,
        .ResultIrq           = &Eqadc3_DmaResult1,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit7_Group10_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_FALLING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 4U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_1,
        .HwTrigSrc           = EQADC_HW_TRIG_EMIOS0_CH18,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_NO_TRIG,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_10,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_10,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 11, ADC8, HardWareTrig */
        .HwUnitId            = 8U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN53_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit8_Group11_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN54_NUMBER,
        .ResultIrq           = &Eqadc4_DmaResult0,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit8_Group11_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_FALLING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 4U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_0,
        .HwTrigSrc           = EQADC_HW_TRIG_GTM_TRIG1_MEMBER11,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_2,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_11,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_11,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 12, ADC9, HardWareTrig */
        .HwUnitId            = 9U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN50_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit9_Group12_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN52_NUMBER,
        .ResultIrq           = &Eqadc4_DmaResult1,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit9_Group12_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_FALLING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 2U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_1,
        .HwTrigSrc           = EQADC_HW_TRIG_EMIOS0_CH19,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_NO_TRIG,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_12,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_12,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 13, ADC10, HardWareTrig */
        .HwUnitId            = 10U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN120_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit10_Group13_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN121_NUMBER,
        .ResultIrq           = &Eqadc5_DmaResult0,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit10_Group13_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_FALLING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 2U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_0,
        .HwTrigSrc           = EQADC_HW_TRIG_GTM_TRIG0_MEMBER0,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_7,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_13,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_13,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 14, ADC10, HardWareTrig */
        .HwUnitId            = 10U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN122_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit10_Group14_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN123_NUMBER,
        .ResultIrq           = &Eqadc5_DmaResult1,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit10_Group14_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 4U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_1,
        .HwTrigSrc           = EQADC_HW_TRIG_GTM_TRIG0_MEMBER0,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_7,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_14,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_14,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 15, ADC11, HardWareTrig */
        .HwUnitId            = 11U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN124_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit11_Group15_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN125_NUMBER,
        .ResultIrq           = &Eqadc5_DmaResult2,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit11_Group15_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 2U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_2,
        .HwTrigSrc           = EQADC_HW_TRIG_GTM_TRIG1_MEMBER11,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_2,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_15,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_15,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 16, ADC0, HardWareTrig */
        .HwUnitId            = 0U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN6_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit0_Group16_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN7_NUMBER,
        .ResultIrq           = &Eqadc0_DmaResult3,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit0_Group16_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_CIRCULAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_FALLING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 4U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_3,
        .HwTrigSrc           = EQADC_HW_TRIG_EMIOS0_CH16,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_NO_TRIG,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_16,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_16,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 17, ADC7, HardWareTrig */
        .HwUnitId            = 7U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN37_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit7_Group17_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN38_NUMBER,
        .ResultIrq           = &Eqadc3_DmaResult3,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit7_Group17_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_CIRCULAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 2U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_3,
        .HwTrigSrc           = EQADC_HW_TRIG_EMIOS0_CH18,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_NO_TRIG,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_17,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_17,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 18, ADC8, HardWareTrig */
        .HwUnitId            = 8U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN57_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit8_Group18_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN58_NUMBER,
        .ResultIrq           = &Eqadc4_DmaResult3,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit8_Group18_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_CIRCULAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 4U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_3,
        .HwTrigSrc           = EQADC_HW_TRIG_EMIOS0_CH19,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_NO_TRIG,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_18,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_18,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 19, ADC9, HardWareTrig */
        .HwUnitId            = 9U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN59_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit9_Group19_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN60_NUMBER,
        .ResultIrq           = &Eqadc4_DmaResult4,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit9_Group19_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_CIRCULAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 4U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_4,
        .HwTrigSrc           = EQADC_HW_TRIG_EMIOS0_CH21,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_NO_TRIG,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_19,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_19,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 20, ADC9, HardWareTrig */
        .HwUnitId            = 9U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN61_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit9_Group20_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN62_NUMBER,
        .ResultIrq           = &Eqadc4_DmaResult5,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit9_Group20_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_CIRCULAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_FALLING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 4U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_5,
        .HwTrigSrc           = EQADC_HW_TRIG_EMIOS0_CH21,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_NO_TRIG,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_20,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_20,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 21, ADC8, SoftWareTrig */
        .HwUnitId            = 8U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)2U,
        .DmaMappedChan       = 0U,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = NULL_PTR,
        .ResultDmaMappedChan = 0U,
        .ResultIrq           = NULL_PTR,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = NULL_PTR,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_SW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 6U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_2,
        .HwTrigSrc           = EQADC_HW_TRIG_NOT_CONNECTED,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_NO_TRIG,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_21,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_21,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 22, ADC1, SoftWareTrig */
        .HwUnitId            = 1U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)2U,
        .DmaMappedChan       = 0U,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = NULL_PTR,
        .ResultDmaMappedChan = 0U,
        .ResultIrq           = NULL_PTR,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = NULL_PTR,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_SW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 2U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_5,
        .HwTrigSrc           = EQADC_HW_TRIG_NOT_CONNECTED,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_NO_TRIG,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_22,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_22,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 23, ADC2, HardWareTrig */
        .HwUnitId            = 2U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN22_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit2_Group23_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN23_NUMBER,
        .ResultIrq           = &Eqadc1_DmaResult3,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit2_Group23_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 2U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_3,
        .HwTrigSrc           = EQADC_HW_TRIG_EMIOS0_CH19,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_NO_TRIG,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_23,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_23,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 24, ADC3, SoftWareTrig */
        .HwUnitId            = 3U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)2U,
        .DmaMappedChan       = 0U,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = NULL_PTR,
        .ResultDmaMappedChan = 0U,
        .ResultIrq           = NULL_PTR,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = NULL_PTR,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_SW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 2U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_4,
        .HwTrigSrc           = EQADC_HW_TRIG_NOT_CONNECTED,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_NO_TRIG,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_24,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_24,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 25, ADC5, SoftWareTrig */
        .HwUnitId            = 5U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)2U,
        .DmaMappedChan       = 0U,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = NULL_PTR,
        .ResultDmaMappedChan = 0U,
        .ResultIrq           = NULL_PTR,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = NULL_PTR,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_SW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 2U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_4,
        .HwTrigSrc           = EQADC_HW_TRIG_NOT_CONNECTED,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_NO_TRIG,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_25,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_25,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 26, ADC6, HardWareTrig */
        .HwUnitId            = 6U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN39_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit6_Group26_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN40_NUMBER,
        .ResultIrq           = &Eqadc3_DmaResult4,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit6_Group26_ResultBuf,
        .DmaSampleNum        = 4U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 4U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_4,
        .HwTrigSrc           = EQADC_HW_TRIG_GTM_TRIG1_MEMBER6,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_15,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_26,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_26,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 27, ADC7, HardWareTrig */
        .HwUnitId            = 7U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,

        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN41_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit7_Group27_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN42_NUMBER,
        .ResultIrq           = &Eqadc3_DmaResult2,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit7_Group27_ResultBuf,
        .DmaSampleNum        = 4U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
        .Prio                = 0U,
        .ConvMode            = ADC_CONV_MODE_ONESHOT,
        .StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
        .AccessMode          = ADC_ACCESS_MODE_SINGLE,
        .HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
        .ChannelCount        = 2U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_2,
        .HwTrigSrc           = EQADC_HW_TRIG_GTM_TRIG1_MEMBER7,
#ifdef RESOURCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_15,
#endif  /* RESOURCE_SUPPORT_GTM_TO_EQADC */
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */
        .Resolution          = ADC_RESOLUTION_BIT12,
        .Eqadc_ConvCmd       = Eqadc_ConvCfg_27,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_27,
#endif
        .Adc_AlternatSet     = NULL_PTR
	}
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
static CONST(Adc_CoreMapItemType, ADC_CONST) Adc_CoreMap[ADC_CONFIG_GROUPS] =
{
    {
        .GroupId = 0U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 1U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 2U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 3U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 4U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 5U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 6U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 7U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 8U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 9U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 10U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 11U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 12U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 13U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 14U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 15U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 16U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 17U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 18U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 19U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 20U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 21U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 22U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 23U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 24U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 25U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 26U,
        .GroupCoreId = 1U
    },
    {
        .GroupId = 27U,
        .GroupCoreId = 1U
    }
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#define ADC_START_SEC_CONFIG_DATA
#include "Adc_MemMap.h"
CONST(Adc_ConfigType, ADC_CONST) Adc_Config =
{
    .Adc_GroupConfig = Group_Cfg,
    .Adc_CoreMapItem = Adc_CoreMap
};
#define ADC_STOP_SEC_CONFIG_DATA
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif
