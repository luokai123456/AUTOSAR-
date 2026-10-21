/**
****************************************************************************************
 * @FilePath: saf_adc.c
 * @Author: CCORE
 * @Date: 2024-02-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: ADC Source File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "compiler_api.h"
#include "intc_lld.h"/*PRQA S 0380*/
#include "console.h"
#include "common.h"
#include "siul2_lld.h"
#include "saf_adc.h"
#include "Saf_MemMap.h"
/*PRQA S 0704,1441,1514,1843,2052,2844,3218,3408,3604,4342,4442 EOF*/
/**
****************************************************************************************
 * @brief: Local Variables
****************************************************************************************
*/
SAF_ADC_SEC_VAR_INIT
static uint16_t Saf_Supadc_Result = 0U;

#if SAF_ADC_EQADC_SUPPORTED
SAF_ADC_SEC_VAR_INIT
static uint16_t Saf_Eqadc_Result = 0;
#endif

#if SAF_ADC_SDADC_SUPPORTED
SAF_ADC_SEC_VAR_NO_INIT
static int16_t saf_sdadc_data [SAF_SDADC_DATA_SIZE];
SAF_ADC_SEC_VAR_NO_INIT
static uint32_t saf_u32sdadc_data [SAF_SDADC_DATA_SIZE];
#endif

SAF_ADC_SEC_CONFIG_DATA
static const uint8_t eqadcConverterCountList[] =SAF_ADC_EQADC_CONVERTER_COUNT_LIST;
SAF_ADC_SEC_CONFIG_DATA
static const uint8_t eqadcChannelList[] =SAF_ADC_EQADC_CHANNEL_LIST;
SAF_ADC_SEC_CONFIG_DATA
static const uint8_t supadcChannelList[] = SAF_ADC_SUPADC_EQ_CHANNEL_LIST;

#if SAF_ADC_SDADC_SUPPORTED
SAF_ADC_SEC_CONFIG_DATA
static const uint8_t sdadcInstList[] = SAF_ADC_SDADC_CONVERTER_COUNT_LIST;
SAF_ADC_SEC_CONFIG_DATA
static const uint8_t sdadcChannelList[] = SAF_ADC_SDADC_CHANNEL_COUNT_LIST;
SAF_ADC_SEC_CONFIG_DATA
static const uint8_t supadcsdChannelList[] = SAF_ADC_SUPADC_SD_CHANNEL_LIST;
#endif

SAF_ADC_SEC_VAR_INIT
static saf_adc_mode_safety_test_result_t saf_adcModeSafetyTest =
{

#if SAF_ADC_SDADC_SUPPORTED
    .sdadcCalTestResultBitmap   = {0},
#endif
#if SAF_ADC_EQADC_SUPPORTED
    .eqadcCalTestResultBitmap   = {0},
#endif
    .supadcCalTestResult        = 0,
};


/*******************************************************************************
 * ADC instance configuration
 *******************************************************************************/
#if SAF_ADC_EQADC_SUPPORTED
SAF_ADC_SEC_VAR_INIT
SafEqadcHwInstanceType Eqadc_HwInstCfg =
{
#if defined(CCFC3008PC) | defined(CCFC3008PCSN)
	.SafEqadc_HwInstId             = SAF_EQADC_INSTANCE_1,
#else
    .SafEqadc_HwInstId             = SAF_EQADC_INSTANCE_0,
#endif
	.DebugModeEn                = FALSE,
    .ExtTrigDigitalFilterLen    = 0U,
    .TimeBasePresDiv            = SAF_EQADC_TBC_CLK_PS_DISABLED,
};
#endif

SAF_ADC_SEC_VAR_INIT
SafEqadcHwInstanceType Supadc_HwInstCfg =
{
#if (defined(CCFC3007PT) || defined(CCFC3008PT))
    .SafEqadc_HwInstId          = SAF_EQADC_INSTANCE_4,
#elif defined(CCFC3007BC)
    .SafEqadc_HwInstId          = SAF_EQADC_INSTANCE_0,
#elif defined(CCFC3008PC)
    .SafEqadc_HwInstId          = SAF_EQADC_INSTANCE_1,
#elif defined(CCFC3008PCSN)
	.SafEqadc_HwInstId          = SAF_EQADC_INSTANCE_0,
#elif defined(CCFC3012PT)
    .SafEqadc_HwInstId          = SAF_EQADC_INSTANCE_6,
#else
#endif

    .DebugModeEn                = FALSE,
    .ExtTrigDigitalFilterLen    = 0U,
    .TimeBasePresDiv            = SAF_EQADC_TBC_CLK_PS_DISABLED,
};

/*******************************************************************************
 * ADC OnChip ADC configuration
 *******************************************************************************/
#if SAF_ADC_EQADC_SUPPORTED
SAF_ADC_SEC_VAR_INIT
SafEqadc_AdcConfigType Eqadc_AdcCfgArray[1U] =
{
    {
        .AdcIdx                 = SAF_EQADC_ADC_1,
        .AdcExtMuxEn            = FALSE,
        .TimeBaseSel            = SAF_EQADC_TBS_INTERNAL,
        .ClkSel                 = SAF_EQADC_CLK_SEL_PS_DIV,
        .ClkPrescale            = SAF_EQADC_CLK_PS_DIV_2,
        .AdcGainCalibConst      = 0x4000U,
        .AdcOffsetCalibConst    = 0,
        .ImmediateConvCmdEn     = FALSE
    }
};
#endif

SAF_ADC_SEC_VAR_INIT
SafEqadc_AdcConfigType Supadc_AdcCfgArray[1U] =
{
    {
#if defined(CCFC3012PT) | defined(CCFC3011PT) | defined(CCFC3010PT) | defined(CCFC3008PC)
        .AdcIdx                 = SAF_EQADC_ADC_0,
#else
        .AdcIdx                 = SAF_EQADC_ADC_1,
#endif
        .AdcExtMuxEn            = FALSE,
        .TimeBaseSel            = SAF_EQADC_TBS_INTERNAL,
        .ClkSel                 = SAF_EQADC_CLK_SEL_PS_DIV,
        .ClkPrescale            = SAF_EQADC_CLK_PS_DIV_2,
        .AdcGainCalibConst      = 0x4000U,
        .AdcOffsetCalibConst    = 0,
        .ImmediateConvCmdEn     = FALSE
    }
};

/*******************************************************************************
 * ADC CFIFO configuration
 *******************************************************************************/
#if SAF_ADC_EQADC_SUPPORTED
SAF_ADC_SEC_VAR_INIT
SafEqadc_CfifoConfigType Eqadc_CfifoCfgArray[1U] =
{
    {
        .CfifoIdx               = SAF_EQADC_FIFO_0,
        .CfifoMode              = SAF_EQADC_CFIFO_MODE_SINGLE_SW_TRIG,
        .IntDmaFillSel          = SAF_EQADC_FILL_SEL_INT,
        .DmaMappedChan          = 0U,
        .SourcePtr              = NULL,
        .SourceLen              = 0U,
        .Callback               = NULL,
        .CallbackParam          = NULL,
        .HwTrigSel              = SAF_EQADC_HW_TRIG_NOT_CONNECTED,
        .Cfifo0EntryExtensionEn = FALSE,
        .Cfifo0AdvanceMode      = SAF_EQADC_CFIFO0_AMODE_DISABLE,
        .Cfifo0AdvanceTrigSel   = SAF_EQADC_ADVANCE_TRIG_NOT
    },
};
#endif

SAF_ADC_SEC_VAR_INIT
SafEqadc_CfifoConfigType Supadc_CfifoCfgArray[1U] =
{
    {
        .CfifoIdx               = SAF_EQADC_FIFO_0,
        .CfifoMode              = SAF_EQADC_CFIFO_MODE_SINGLE_SW_TRIG,
        .IntDmaFillSel          = SAF_EQADC_FILL_SEL_INT,
        .DmaMappedChan          = 0U,
        .SourcePtr              = NULL,
        .SourceLen              = 0U,
        .Callback               = NULL,
        .CallbackParam          = NULL,
        .HwTrigSel              = SAF_EQADC_HW_TRIG_NOT_CONNECTED,
        .Cfifo0EntryExtensionEn = FALSE,
        .Cfifo0AdvanceMode      = SAF_EQADC_CFIFO0_AMODE_DISABLE,
        .Cfifo0AdvanceTrigSel   = SAF_EQADC_ADVANCE_TRIG_NOT
    },
};


/*******************************************************************************
 * ADC configuration
 *******************************************************************************/
SAF_ADC_SEC_VAR_INIT
Adc_SafEqadcConfigType Supadc_Cfg =
{
    .SafEqadcHwInst             = &Supadc_HwInstCfg,
    .AdcConfigNum               = 1U,
    .AdcConfigArray             = Supadc_AdcCfgArray,
    .CfifoConfigNum             = 1U,
    .CfifoConfigArray           = Supadc_CfifoCfgArray,
    .ResultDmaConfigNum         = 0U,
    .ResultDmaConfigArray       = NULL,
    .AlternateConfigNum         = 0U,
    .AlternateConfigArray       = NULL,
    .RedLineClientConfigNum     = 0U,
    .RedLineClientConfigArray   = NULL

};


#if SAF_ADC_EQADC_SUPPORTED
SAF_ADC_SEC_VAR_INIT
Adc_SafEqadcConfigType Eqadc_Cfg =
{
    .SafEqadcHwInst             = &Eqadc_HwInstCfg,
    .AdcConfigNum               = 1U,
    .AdcConfigArray             = Eqadc_AdcCfgArray,
    .CfifoConfigNum             = 1U,
    .CfifoConfigArray           = Eqadc_CfifoCfgArray,
    .ResultDmaConfigNum         = 0U,
    .ResultDmaConfigArray       = NULL,
    .AlternateConfigNum         = 0U,
    .AlternateConfigArray       = NULL,
    .RedLineClientConfigNum     = 0U,
    .RedLineClientConfigArray   = NULL
};
#endif

/*******************************************************************************
 * ADC conversion command configuration
 *******************************************************************************/
#if SAF_ADC_EQADC_SUPPORTED
SAF_ADC_SEC_VAR_INIT
SafEqadc_ConvCmdType Eqadc_ConvCfg[SAF_EQADC_CMD_NUM] =
{
    {
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8_t)SAF_EQADC_ADC_0,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = SAF_EQADC_MSG_TAG_RFIFO1,
        .LongSampTime       = SAF_EQADC_ADCLK_SAMPLING_CYCLES_64,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = SAF_EQADC_CH(8),
        .AltConfigSel       = SAF_EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};
#endif

SAF_ADC_SEC_VAR_INIT
SafEqadc_ConvCmdType Supadc_ConvCfg[SAF_SUPADC_TIMES] =
{
    {
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
#if defined(CCFC3012PT) | defined(CCFC3011PT) | defined(CCFC3010PT) | defined(CCFC3008PC)
        .cBufNum            = (uint8_t)SAF_EQADC_ADC_0,
#else
        .cBufNum            = (uint8_t)SAF_EQADC_ADC_1,
#endif
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = SAF_EQADC_MSG_TAG_RFIFO1,
        .LongSampTime       = SAF_EQADC_ADCLK_SAMPLING_CYCLES_64,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = SAF_EQADC_CH_VDD_HV_FLA,
        .AltConfigSel       = SAF_EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    },
};

/*******************************************************************************
 * SDADC conversion command configuration
 *******************************************************************************/
#if SAF_ADC_SDADC_SUPPORTED

SAF_ADC_SEC_VAR_INIT
Saf_Sdadc_ConfigType SdadcCfg =
{
    .ChanSel            = {
        .ChanDefaultId          = 2U,
        .DifferenceEn           = FALSE
    },
    .ExtMeshClkSel      = SAF_SDADC_MESH_SEL_ADC_CORE,
	.DCTestEn           = TRUE,
	.AnalogCfg          = {
			.PreGain = SAF_SDADC_PRE_GAIN_X2,
			.VcomSel = SAF_SDADC_VCOM_SEL_HALF_OF_VREF_H,
			.ClkDiv  = SAF_SDADC_CLK_DIV_2,
	},
	.OsrVal             = SAF_SDADC_OSR_48,
    .FirFilter          = {
        .Fir1DecimationRate     = SAF_SDADC_FIR1_DECI_2_TO_1,
        .CicMode                = FALSE,
        .OvershootCompEn        = FALSE,
        .OffsetCompFilterEn     = SAF_SDADC_OFFSET_COMPENSATION_FILTER_DISABLED,
        .CalibrationEn          = FALSE
    },
    .OvershootComp      = {
        .SlewRateFilterStrength = SAF_SDADC_SLEW_RATE_FILTER_STRENGTH_MIN,
        .SlewRateFilterRunTime  = SAF_SDADC_SLEW_RATE_FILTER_RUNTIME_2_IN_CYCLES,
        .StepDetectionMode      = SAF_SDADC_STEP_DETECTION_MODE_LAST_INPUT,
        .StepDetectionThreshold = 0U
    },
    .IntDma             = {
        .FifoWaterMarkerIntEn   = TRUE,
        .FifoOverFlowIntEn      = TRUE,
        .DataOverFlowIntEn      = TRUE,
        .DmaReqEn               = FALSE
    },
	.IntegratorEn       = FALSE,
    .Integrator         = {
        .IntegratorTrigMode     = SAF_SDADC_INTEGRATOR_TRIG_MODE_BYPASSED,
        .IntegrationWindowSize  = SAF_SDADC_INTEGRATION_WINDOW_SIZE_INTERNAL_CTRL,
        .NumOfDiscardedVal      = 0U,
        .NumOfAccumulatedVal    = 0U,
        .NumOfIntegrationCycles = 0U,
        .IntegratorShiftCtrl    = SAF_SDADC_INTEGRATOR_SHIFT_CTRL_SEL_BITS_4_20,
        .FilterChainRestartCtrl = SAF_SDADC_FILTER_CHAIN_RESTART_ENABLE
    },
    .FilterChainDiscard = {
        .FilterChainDiscardEn   = TRUE,
        .FilterChainDiscardNum  = 0xFFU
    },
    .ChanWrap           = {
        .ChanWraparoundEn       = FALSE,
        .ChanWraparoundNum      = 0U
    },
    .Comparator         = {
        .BoundaryComparatorEn   = FALSE,
        .LowerBoundary          = 0U,
        .UpperBoundary          = 0xFFFFU
    },
    .FifoCfg            = {
        .FifoSize               = 0x40U,
        .FifoWaterMarker        = 0x20U,
        .InfoEn                 = FALSE,
        .SignEn                 = FALSE
    },
    .HwTrigSel          = {
        SAF_SDADC_HW_TRIG_DISABLE,
        SAF_SDADC_HW_TRIG_DISABLE,
        SAF_SDADC_HW_TRIG_DISABLE,
        SAF_SDADC_HW_TRIG_DISABLE,
        SAF_SDADC_HW_TRIG_DISABLE,
        SAF_SDADC_HW_TRIG_DISABLE,
        SAF_SDADC_HW_TRIG_DISABLE,
        SAF_SDADC_HW_TRIG_DISABLE,
        SAF_SDADC_HW_TRIG_DISABLE,
        SAF_SDADC_HW_TRIG_DISABLE,
        SAF_SDADC_HW_TRIG_DISABLE,
        SAF_SDADC_HW_TRIG_DISABLE,
        SAF_SDADC_HW_TRIG_DISABLE,
        SAF_SDADC_HW_TRIG_DISABLE,
        SAF_SDADC_HW_TRIG_DISABLE,
        SAF_SDADC_HW_TRIG_DISABLE
    }
};
#endif

/**
****************************************************************************************
* @brief: [SW_SM047] This function Supervisor ADC voltage sampling.
* @param[in] chan  Supervisor ADC channel ID.
* @param[out] pResultMv  Supervisor ADC Sampling result.
* @return status
            FS_STATUS_TIMEOUT :Sampling voltage timeout.
            FS_STATUS_SUCCESS :Sampling voltage successful.
****************************************************************************************
*/
#pragma ghs ZO
SAF_ADC_SEC_CODE
static FS_STATUS SAF_SUPADC_Sample_Votage(const uint8_t chan,uint16_t *pResultMv)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint32_t TestTimeout = SAF_EQADC_TIMEOUT_COUNT;
    const SafEqadcInstanceType instance = Supadc_Cfg.SafEqadcHwInst->SafEqadc_HwInstId;
    const SafEqadcFifoIdxType Cfifo_x = Supadc_Cfg.CfifoConfigArray[0U].CfifoIdx;/*PRQA S 0491*/
    const SafEqadcFifoIdxType Rfifo_x = (SafEqadcFifoIdxType)(Supadc_ConvCfg[0U].RfifoMsgTag);/*PRQA S 4322*/
    SAF_EQADC_DET_ERR((uint8_t)Supadc_Cfg.AdcConfigArray[0U].AdcIdx == (Supadc_ConvCfg[0U].cBufNum));/*PRQA S 3119*/
    
    /* Push conversion command and trigger */
    Supadc_ConvCfg[0].ChanNum = chan;
    SAF_EQADC_LLD_CfifoPushConvCmd(instance, Cfifo_x, &Supadc_ConvCfg[0]);
    
    SAF_EQADC_LLD_SingleScanEn(instance, Cfifo_x);

    /* 1.Waiting for the conversion command push to complete (end of queue),
    * 2.Waiting for RFIFO to receive data on the number of CFIFO commands. */
    while (((SAF_EQADC_LLD_GetFifoFlagStatus(instance, Cfifo_x, SAF_EQADC_FISR_END_OF_QUEUE) != 1U) || \
            (SAF_EQADC_LLD_GetFifoFlagStatus(instance, Rfifo_x, SAF_EQADC_FISR_RFIFO_ENTRY_COUNT) != 1U)) && \
            (TestTimeout > 0UL))
    {
        TestTimeout--;
    }

    if (TestTimeout > 0UL)
    {
        /* Pop Rfifo result data */
        Saf_Supadc_Result = SAF_EQADC_LLD_RfifoPopData(instance, Rfifo_x);  

        /* Clear Flag */
        SAF_EQADC_LLD_ClearFifoIntFlag(instance, Rfifo_x, SAF_EQADC_FIFO_FLAG_RFIFO_DRAIN);
        SAF_EQADC_LLD_ClearFifoIntFlag(instance, Cfifo_x, SAF_EQADC_FIFO_FLAG_END_OF_QUEUE);

        *pResultMv = (uint32_t)Saf_Supadc_Result * SAF_EQADC_VRH_MVOLT / SAF_EQADC_RESOLUTION_BIT12;/*PRQA S 4461,3393,3401*/
    
    }
    else
    {
        status = FS_STATUS_TIMEOUT;
    }

    return status;
}
#pragma ghs Odefault

/**
****************************************************************************************
* @brief: [SW_SM047] This function Supervisor ADC voltage sampling average calculation.
* @param[in] supch  Supervisor ADC channel ID.
* @param[out] pResultMv  Supervisor ADC Sampling result.
* @param[in] times  Supervisor ADC Sampling times.
* @return enum
            FS_STATUS_TIMEOUT ：Sampling voltage timeout.
            FS_STATUS_SUCCESS ：Sampling voltage successful.
****************************************************************************************
*/
SAF_ADC_SEC_CODE
FS_STATUS SAF_ADC_SupadcSampleAvgVoltage(const uint16_t supch, uint16_t *pResultMv, const uint16_t times)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint16_t resultMv  = 0;
    uint32_t sumMv =0;
    uint8_t i;
    const SafEqadcInstanceType instance = Supadc_Cfg.SafEqadcHwInst->SafEqadc_HwInstId;

    Adc_SafEqadc_LLD_Init(&Supadc_Cfg);
    
    for (i = 0; i < times; i++)
    {
        status = SAF_SUPADC_Sample_Votage(supch, &resultMv);/*PRQA S 4461*/
        if (FS_STATUS_SUCCESS == status)
        {
            sumMv += resultMv;               
        }
        else
        {
            break;
        }
    }

    if (FS_STATUS_SUCCESS == status)
    {
        *pResultMv = (uint16_t)(sumMv / times);/*PRQA S 2908,2833*/
    }

    Adc_SafEqadc_LLD_DeInit(instance);

    return status;
}

/**
****************************************************************************************
* @brief: [SW_SM047] This function Compare the sampling results of Supervisor ADC 
                     internal channels with the expected values.
* @param[out] pResult  Supervisor ADC self test result.
* @return status
            FS_STATUS_ERROR :The error between the sampled value and the expected 
                              value is not within a reasonable range.
            FS_STATUS_SUCCESS :The error between the sampled value and the expected
                                value is within a reasonable range.
****************************************************************************************
*/
#pragma ghs ZO
SAF_ADC_SEC_CODE
FS_STATUS SAF_ADC_SupadcSampleTest(saf_adc_mode_safety_test_result_t *pResult)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint16_t errorRange = 0;
    uint16_t supadc_sampleResult =0;
    uint16_t sd_adcEnable = 0;
    uint16_t expected_resultlist[] =SAF_ADC_SUPADC_EXPECTED_VALUE_LIST;
    uint8_t chan_list[] = SAF_ADC_SUPADC_INTERNAL_CHANNEL_LIST;
    uint8_t i;

    for(i = 0; i < sizeof(chan_list); i++)/*PRQA S 2877*/
    {
		if (SAF_EQADC_CH_TEMP_SENSOR == chan_list[i])
		{
			SAF_SSCM_VRC33_ENABLE = 0x000000c;
		}

		if (sd_adcEnable == (uint16_t)1)
		{
			continue;
		}
		else
		{
			sd_adcEnable = 1;/*PRQA S 2983*/
			if ((MC_CGM.AC0_DC1.R >> 31) == 1)
			{
				*(uint32_t*)0xFFF0C000 |= 1;/*PRQA S 1281,1841,4542*/
			}
			else
			{
				return FS_STATUS_ERROR;
			}
		}
    }
#if defined(CCFC3012PT)
    SAF_SSCM_VRC33_ENABLE = 0x000000f;
#endif

    pResult->supadcCalTestResult = 0;
    for(i = 0; i < sizeof(chan_list); i++)/*PRQA S 2877*/
    {
        if (FS_STATUS_SUCCESS == SAF_ADC_SupadcSampleAvgVoltage(chan_list[i], &supadc_sampleResult,SAF_ADC_SUPADC_SAMPLE_TIMES))
        {
            errorRange = (expected_resultlist[i] > supadc_sampleResult) ?
                         (expected_resultlist[i] - supadc_sampleResult) :
                         (supadc_sampleResult - expected_resultlist[i]);
            if (errorRange >= SAF_AVG_ERROR)
            {
                status  = FS_STATUS_ERROR;
                //break;
            }
        }
        else
        {
            status  = FS_STATUS_ERROR;
            break;
        }
    }
    if(status == FS_STATUS_SUCCESS)
    {
        pResult->supadcCalTestResult = 1 ;
    }

    return status;
}
#pragma ghs Odefault


#if SAF_ADC_EQADC_SUPPORTED
/**
****************************************************************************************
* @brief: [SW_SM048] This function EQADC voltage sampling.
* @param[in] chan  EQADC channel ID.
* @param[out] pResultMv  EQADC Sampling result.
* @return status
            FS_STATUS_TIMEOUT :Sampling voltage timeout.
            FS_STATUS_SUCCESS :Sampling voltage successful.
****************************************************************************************
*/
SAF_ADC_SEC_CODE
static FS_STATUS SAF_EQADC_Sample_Votage(const uint8_t chan,uint16_t *pResultMv)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint32_t TestTimeout = SAF_EQADC_TIMEOUT_COUNT;

    const SafEqadcInstanceType instance = Eqadc_Cfg.SafEqadcHwInst->SafEqadc_HwInstId;
    const SafEqadcFifoIdxType Cfifo_x = Eqadc_Cfg.CfifoConfigArray[0U].CfifoIdx;/*PRQA S 0491*/
    const SafEqadcFifoIdxType Rfifo_x = (SafEqadcFifoIdxType)(Eqadc_ConvCfg[0U].RfifoMsgTag);/*PRQA S 4322*/
     
    SAF_EQADC_DET_ERR((uint8_t)Eqadc_Cfg.AdcConfigArray[0U].AdcIdx == (Eqadc_ConvCfg[0U].cBufNum));/*PRQA S 3119*/

  
    /* Push conversion command and trigger */
    Eqadc_ConvCfg[0].ChanNum = chan;
    SAF_EQADC_LLD_CfifoPushConvCmd(instance, Cfifo_x, &Eqadc_ConvCfg[0U]);
    SAF_EQADC_LLD_SingleScanEn(instance, Cfifo_x);

    /* Wait Rfifo Drain */
    while (((SAF_EQADC_LLD_GetFifoFlagStatus(instance, Cfifo_x, SAF_EQADC_FISR_END_OF_QUEUE) != 1U) || \
            (SAF_EQADC_LLD_GetFifoFlagStatus(instance, Rfifo_x, SAF_EQADC_FISR_RFIFO_DRAIN) != 1U)) &&  \
            (TestTimeout > 0UL))
    {
        TestTimeout--;
    }

    if (TestTimeout > 0UL)
    {
        /* Pop Rfifo result data */
        Saf_Eqadc_Result = SAF_EQADC_LLD_RfifoPopData(instance, Rfifo_x);
    }
    else
    {
        status = FS_STATUS_TIMEOUT;
    }

    /* Clear Flag */
    SAF_EQADC_LLD_ClearFifoIntFlag(instance, Rfifo_x, SAF_EQADC_FIFO_FLAG_RFIFO_DRAIN);
    SAF_EQADC_LLD_ClearFifoIntFlag(instance, Cfifo_x, SAF_EQADC_FIFO_FLAG_END_OF_QUEUE);
    

    if (FS_STATUS_SUCCESS == status)
    {
        *pResultMv = (uint32_t)Saf_Eqadc_Result * SAF_EQADC_VRH_MVOLT / SAF_EQADC_RESOLUTION_BIT12;/*PRQA S 4461,3393,3401*/

    }

    return status;
}

/**
****************************************************************************************
* @brief: [SW_SM048] This function Initializes EQADC module.
* @param[in] eqadcInst  EQADC instance.
* @param[in] adcIdx  EQADC ADCID.
****************************************************************************************
*/
SAF_ADC_SEC_CODE
static void SAF_ADC_EqadcSampleInit(const uint8_t eqadcInst, const uint8_t adcIdx)
{
    Eqadc_ConvCfg[0U].cBufNum = adcIdx;

    Eqadc_Cfg.SafEqadcHwInst->SafEqadc_HwInstId = (SafEqadcInstanceType)eqadcInst;
    Eqadc_Cfg.AdcConfigArray[0U].AdcIdx = (SafEqadcAdcIdxType)adcIdx;/*PRQA S 0491*/
    
    Adc_SafEqadc_LLD_Init(&Eqadc_Cfg);

}

/**
****************************************************************************************
* @brief: [SW_SM048] This function EQADC voltage sampling average calculation.
* @param[in] eqadcInst  EQADC instance.
* @param[in] adcIdx  EQADC ADCID.
* @param[in] chan  EQADC channel ID.
* @param[out] pResultMv  EQADC Sampling result.
* @param[in] times  EQADC Sampling times.
* @return status
            FS_STATUS_TIMEOUT :Sampling voltage timeout.
            FS_STATUS_SUCCESS :Sampling voltage successful.
****************************************************************************************
*/
SAF_ADC_SEC_CODE
FS_STATUS SAF_ADC_EqadcSampleAvgVoltage(const uint8_t eqadcInst, const uint8_t adcIdx, const uint8_t chan, uint16_t *pResultMv, const uint16_t times)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint16_t resultMv  = 0;
    uint32_t sumMv =0;
    uint8_t i;

    /* sample init */
    SAF_ADC_EqadcSampleInit(eqadcInst, adcIdx);
    /* sample loop */
    for (i = 0; i < times; i++)
    {
        status = SAF_EQADC_Sample_Votage(chan, &resultMv);
        if (FS_STATUS_SUCCESS == status)
        {
            sumMv += resultMv;               
        }
        else
        {
            break;
        }
    }
    
    if (FS_STATUS_SUCCESS == status)
    {
        *pResultMv = (uint16_t)(sumMv / times);/*PRQA S 2908,2833*/
    }

     /* EQADC DeInit */
    Adc_SafEqadc_LLD_DeInit((SafEqadcInstanceType)eqadcInst);

    return status;
}

/**
****************************************************************************************
* @brief: [SW_SM048] EQADC test,Compare the voltage value of EQADC sampling result with
                     the voltage value of supervisor ADC sampling result.
* @param[out] pResult  EQADC self test result.
* @return status
            FS_STATUS_ERROR :The error between the sampled value and the expected 
                              value is not within a reasonable range.
            FS_STATUS_SUCCESS :The error between the sampled value and the expected
                                value is within a reasonable range.
****************************************************************************************
*/
SAF_ADC_SEC_CODE
FS_STATUS SAF_ADC_EqadcSampleTest(saf_adc_mode_safety_test_result_t *pResult)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
//    uint8_t eqadcConverterCountList[] =SAF_ADC_EQADC_CONVERTER_COUNT_LIST;
//    uint8_t eqadcChannelList[] =SAF_ADC_EQADC_CHANNEL_LIST;
//    uint8_t supadcChannelList[] = SAF_ADC_SUPADC_EQ_CHANNEL_LIST;
    uint16_t errorRange = 0;
    uint16_t supadc_sampleResult =0;
    uint16_t eqadc_sampleResult =0;
    uint8_t eqadcInst, adcIdx;
    uint8_t i = 0;
    saf_eqadc_sample_t FsEqadcSample;
   
    for (eqadcInst = 0; eqadcInst <SAF_ADC_EQADC_INSTANCE_COUNT; eqadcInst++)
    {
        
        for (adcIdx = 0; adcIdx < eqadcConverterCountList[eqadcInst]; adcIdx++)
        {
            FsEqadcSample.eqadcCh = eqadcChannelList[i];
            FsEqadcSample.supadcCh = supadcChannelList[i];
            
            if(FsEqadcSample.eqadcCh != (uint8_t)255u)
            {
                pResult->eqadcCalTestResultBitmap[i] = 0;
                if (FS_STATUS_SUCCESS == SAF_ADC_EqadcSampleAvgVoltage(eqadcInst, adcIdx, FsEqadcSample.eqadcCh, &eqadc_sampleResult,SAF_ADC_EQADC_SAMPLE_TIMES))
                {
                    if(FS_STATUS_SUCCESS == SAF_ADC_SupadcSampleAvgVoltage(FsEqadcSample.supadcCh, &supadc_sampleResult,SAF_ADC_SUPADC_SAMPLE_TIMES))
                    {
                        errorRange = (eqadc_sampleResult > supadc_sampleResult) ?
                        (eqadc_sampleResult - supadc_sampleResult) :
                        (supadc_sampleResult - eqadc_sampleResult);
                        if (errorRange < SAF_AVG_ERROR)
                        {
                            pResult->eqadcCalTestResultBitmap[i] |= (0x1U);
                        }
                        else
                        {
                            status  = FS_STATUS_ERROR;
                        }
                    }
                    else
                    {
                        status  = FS_STATUS_ERROR;
                    }
                }
                else
                {
                    status  = FS_STATUS_ERROR;
                }
            }
            i++;
        }
    }

    i = 0;/*PRQA S 2983*/

    return status;
}
#endif

#if SAF_ADC_SDADC_SUPPORTED
/**
****************************************************************************************
* @brief: [SW_SM048] This function SDADC voltage sampling.
* @param[in] sdadcId  SDADC ID.
* @param[out] pResult  SDADC Sampling result.
* @return status
            FS_STATUS_TIMEOUT :Sampling voltage timeout.
            FS_STATUS_SUCCESS :Sampling voltage successful.
****************************************************************************************
*/
SAF_ADC_SEC_CODE
static FS_STATUS SAF_SDADC_Sample_Votage(const Saf_Sdadc_InstanceType sdadcId, uint16_t *pResult)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint32_t TestTimeout = SAF_SDADC_TIMEOUT_COUNT;
    uint16_t i;
    int64_t sumMv = 0;
 
	SAF_SDADC_LLD_ModuleEnable(sdadcId);
	SAF_SDADC_LLD_SetSoftTrigger(sdadcId);
    for(i = 0U; i < SAF_SDADC_DATA_SIZE; i++)
	{
		while((SAF_SDADC_LLD_GetWaterMarkerIntState(sdadcId) != TRUE)&&(TestTimeout > 0))/*PRQA S 1842*/
		{
            TestTimeout --;
		}

		saf_sdadc_data[i] = (uint16_t)(SAF_SDADC_LLD_GetFifoData(sdadcId) & 0xFFFFU);/*PRQA S 4446*/ /* polyspace RTE:OVFL */

		SAF_SDADC_LLD_ClearWaterMarkerIntState(sdadcId);
	}

    if(TestTimeout > 0)/*PRQA S 1842*/
    {
        for(i = 0U; i < SAF_SDADC_DATA_SIZE; i++)
        {
            saf_u32sdadc_data[i] = (uint32_t)(saf_sdadc_data[i] + 32768) * SAF_SDADC_VRH_MVOLT / SAF_SDADC_RESOLUTION;/*PRQA S 3393,4393,3401*/

            sumMv += saf_u32sdadc_data[i];/*PRQA S 1850*/
    
        }
        *pResult = sumMv / SAF_SDADC_DATA_SIZE;/*PRQA S 4434,1850*/
    }
    else
    {
        status = FS_STATUS_TIMEOUT;
    }

    return status; 
}


/**
****************************************************************************************
* @brief: [SW_SM048] This function Initializes SDADC module.
* @param[in] sdadcId  SDADC ADC ID.
* @param[in] chan  SDADC channel ID.
****************************************************************************************
*/
SAF_ADC_SEC_CODE
static void SAF_ADC_SdadcSampleInit(const Saf_Sdadc_InstanceType sdadcId, const uint8_t chan)
{
	Saf_Sdadc_ConfigType config;

	config = SdadcCfg;

    config.ChanSel.ChanDefaultId = chan;
	SAF_SDADC_LLD_Init(sdadcId, &config);
}


/**
****************************************************************************************
* @brief: [SW_SM048] This function SDADC voltage sampling average calculation.
* @param[in] sdadcId  SDADC ADC ID.
* @param[in] chan  SDADC channel ID.
* @param[out] pResultMv  SDADC Sampling result.
* @param[in] times  SDADC Sampling times.
* @return status
            FS_STATUS_TIMEOUT :Sampling voltage timeout.
            FS_STATUS_SUCCESS :Sampling voltage successful.
****************************************************************************************
*/
SAF_ADC_SEC_CODE
FS_STATUS SAF_ADC_SdadcSampleAvgVoltage(const Saf_Sdadc_InstanceType sdadcId, const uint8_t chan, uint16_t *pResultMv, const uint16_t times)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint16_t resultMv  = 0;
    uint32_t sumMv =0;
    uint8_t i;

    SAF_ADC_SdadcSampleInit(sdadcId, chan);

    for (i = 0; i < times; i++)
    {
        status = SAF_SDADC_Sample_Votage(sdadcId, &resultMv);
        if (FS_STATUS_SUCCESS == status)
        {
            sumMv += resultMv;               
        }
        else
        {
            break;
        }
    }

    if (FS_STATUS_SUCCESS == status)
    {
        *pResultMv = (uint16_t)(sumMv / times); /*PRQA S 2908,2833*/
    }

    SAF_SDADC_LLD_DeInit(sdadcId);

    return status;
}


/**
****************************************************************************************
* @brief: [SW_SM048] SDADC test,Compare the voltage value of SDADC sampling result with
                     the voltage value of supervisor ADC sampling result.
* @param[out] pResult  SDADC self test result.
* @return status
            FS_STATUS_ERROR :The error between the sampled value and the expected 
                              value is not within a reasonable range.
            FS_STATUS_SUCCESS :The error between the sampled value and the expected
                                value is within a reasonable range.
****************************************************************************************
*/
SAF_ADC_SEC_CODE
FS_STATUS SAF_ADC_SdadcSampleTest(saf_adc_mode_safety_test_result_t *pResult)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
//    uint8_t sdadcInstList[] = SAF_ADC_SDADC_CONVERTER_COUNT_LIST;
//    uint8_t sdadcChannelList[] = SAF_ADC_SDADC_CHANNEL_COUNT_LIST;
//    uint8_t supadcsdChannelList[] = SAF_ADC_SUPADC_SD_CHANNEL_LIST;
    uint8_t i ;
    uint16_t errorRange = 0;
    uint16_t supadc_sampleResult =0;
    uint16_t sdadc_sampleResult =0;
    saf_sdadc_sample_t FsSdadcSample;
        
    for (i = 0; i < SAF_ADC_SDADC_INSTANCE_COUNT; i++)
    {
        FsSdadcSample.sdadcId = sdadcInstList[i];
        FsSdadcSample.sdadcCh = sdadcChannelList[i];
        FsSdadcSample.supadcCh = supadcsdChannelList[i];
        
        if(sdadcChannelList[i] != (uint8_t)255u)
        {
            pResult->sdadcCalTestResultBitmap[i] = 0;
            if (FS_STATUS_SUCCESS == SAF_ADC_SdadcSampleAvgVoltage((Saf_Sdadc_InstanceType)FsSdadcSample.sdadcId, FsSdadcSample.sdadcCh, &sdadc_sampleResult,SAF_ADC_SDADC_SAMPLE_TIMES))
            {
                if(FS_STATUS_SUCCESS == SAF_ADC_SupadcSampleAvgVoltage(FsSdadcSample.supadcCh, &supadc_sampleResult,SAF_ADC_SUPADC_SAMPLE_TIMES))
                {
                    errorRange = (sdadc_sampleResult > supadc_sampleResult) ?
                    (sdadc_sampleResult - supadc_sampleResult) :
                    (supadc_sampleResult - sdadc_sampleResult);
                    if (errorRange < SAF_AVG_ERROR)
                    {
                        pResult->sdadcCalTestResultBitmap[i] |= 0x1U ;
                    }
                    else
                    {
                        status  = FS_STATUS_ERROR;
                    }  

                }
                else
                {
                    status  = FS_STATUS_ERROR;
                }
            } 
            else
            {
                status  = FS_STATUS_ERROR;
            } 
        }
    }

    return status;
}
#endif

/**
****************************************************************************************
* @brief: [SW_SM050,SW_SM060] This function execute ADC mode safet test.
* @param[in] void
* @return status
            FS_STATUS_ERROR :ADC self test failed.
            FS_STATUS_SUCCESS :ADC self test successful.
****************************************************************************************
*/
SAF_ADC_SEC_CODE
FS_STATUS SAF_ADC_ModeSafetyTest(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;   
    saf_adc_mode_safety_test_result_t *pResult = &saf_adcModeSafetyTest;

    memset(pResult, 0xff, sizeof(saf_adc_mode_safety_test_result_t));/*PRQA S 0315,3200 EOF*/   
    if (FS_STATUS_SUCCESS == SAF_ADC_SupadcSampleTest(pResult))
    {
#ifdef SAF_ADC_SAMPLE_SUPPORTED
#if SAF_ADC_EQADC_SUPPORTED
        if (FS_STATUS_SUCCESS != SAF_ADC_EqadcSampleTest(pResult))
        {
            status = FS_STATUS_ERROR;
        }
#endif

#if SAF_ADC_SDADC_SUPPORTED
        if (FS_STATUS_SUCCESS != SAF_ADC_SdadcSampleTest(pResult))
        {
            status = FS_STATUS_ERROR;
        }
#endif
#endif
    }
    else
    {
        status = FS_STATUS_ERROR;
    }

    return status;
}

/**
****************************************************************************************
* @brief: [SW_SM050,SW_SM060] This function is used to get the test result ADC mode
                              safety test.
* @param[out] pTestResult  ADC self test result.
* @return status
            FS_STATUS_ERROR :PTestResult equals NULL, obtaining ADC test result failed
            FS_STATUS_SUCCESS :PTestResult equals NULL, obtaining ADC test result successful.
****************************************************************************************
*/
SAF_ADC_SEC_CODE
FS_STATUS SAF_ADC_ModeSafetyTestResult(saf_adc_mode_safety_test_result_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;
    
    if (pTestResult != NULL)
    {
        memcpy(pTestResult, &saf_adcModeSafetyTest, sizeof(saf_adcModeSafetyTest));/*PRQA S 0315,3200 EOF*/
        status = FS_STATUS_SUCCESS;
    }

    return status;
}


#ifdef __cplusplus
}
#endif
