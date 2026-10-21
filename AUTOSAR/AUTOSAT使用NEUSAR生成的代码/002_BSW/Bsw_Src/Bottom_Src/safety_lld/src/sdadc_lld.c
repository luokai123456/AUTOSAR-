/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     sdadc_lld.c
* @version  1.0
* @date     2023 - 09 - 01
* @brief    Initial version.
* @MCAL 	Version: 3.0.1
* @Safety 	Version: 3.0.0
*
*****************************************************************************/
/* PRQA S 1258,1431,1881 EOF*/
/* PRQA S 2844,2985,2986,2995 EOF*/
/* PRQA S 3119,3469,4342,4404,4424,4461 EOF*/

#include "sdadc_lld.h"		/* PRQA S 0380,4095*/
#include "sdadc_reg.h"
#include "Saf_MemMap.h"
#include "common.h"
#ifdef SAF_ADC_SDADC_SUPPORTED
SAF_ADC_SEC_CONFIG_DATA
static SAF_SDADC_TagType * const Adc_SdadcBase[ADC_SAF_SDADC_MAX_INSTANCE] = SAF_SDADC_BASE_PTR_ARRAY;

static status_t SAF_SDADC_LLD_SetPin(const Saf_Sdadc_InstanceType instance, const uint8_t chn, boolean diffEn);

SAF_ADC_SEC_CODE
static status_t SAF_SDADC_LLD_SetPin(const Saf_Sdadc_InstanceType instance, const uint8_t chn, boolean diffEn)
{
	status_t ret = STATUS_SUCCESS;

	switch(instance)
	{
		case SAF_SDADC_INSTANCE_0:
		{
			if(chn == 0U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PB2].R = 0x00000000U;
				}
				else
				{
					SIUL2.MSCR_IO[PB2].R = 0x00000000U;

					SIUL2.MSCR_IO[PB3].R = 0x00000000U;
				}
			}
			else if(chn == 1U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PB3].R = 0x00000000U;
				}
				else
				{
			        ret = STATUS_ERROR;
				}
			}
			else
			{
		        ret = STATUS_ERROR;
			}
			break;
		}

		case SAF_SDADC_INSTANCE_1:
		{
			if(chn == 0U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PB0].R = 0x00000000U;
				}
				else
				{
					SIUL2.MSCR_IO[PB0].R = 0x00000000U;

					SIUL2.MSCR_IO[PB1].R = 0x00000000U;
				}
			}
			else if(chn == 1U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PB1].R = 0x00000000U;
				}
				else
				{
			        ret = STATUS_ERROR;
				}
			}
			else
			{
		        ret = STATUS_ERROR;
			}

			break;
		}

		case SAF_SDADC_INSTANCE_2:
		{
			if(chn == 0U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PK0].R = 0x00000000U;
				}
				else
				{
					SIUL2.MSCR_IO[PK0].R = 0x00000000U;

					SIUL2.MSCR_IO[PK1].R = 0x00000000U;
				}
			}
			else if(chn == 1U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PK1].R = 0x00000000U;
				}
				else
				{
					SIUL2.MSCR_IO[PK2].R = 0x00000000U;

					SIUL2.MSCR_IO[PK3].R = 0x00000000U;
				}
			}
			else if(chn == 2U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PK2].R = 0x00000000U;
				}
				else
				{
			        ret = STATUS_ERROR;
				}
			}
			else if(chn == 3U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PK3].R = 0x00000000U;
				}
				else
				{
			        ret = STATUS_ERROR;
				}
			}
			else
			{
		        ret = STATUS_ERROR;
			}

			break;
		}

		case SAF_SDADC_INSTANCE_3:
		{
			if(chn == 0U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PB12].R = 0x00000000U;
				}
				else
				{
					SIUL2.MSCR_IO[PB12].R = 0x00000000U;

					SIUL2.MSCR_IO[PB13].R = 0x00000000U;
				}
			}
			else if(chn == 1U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PB13].R = 0x00000000U;
				}
				else
				{
					SIUL2.MSCR_IO[PB14].R = 0x00000000U;

					SIUL2.MSCR_IO[PB15].R = 0x00000000U;
				}
			}
			else if(chn == 2U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PB14].R = 0x00000000U;
				}
				else
				{
					SIUL2.MSCR_IO[PG4].R = 0x00000000U;

					SIUL2.MSCR_IO[PG3].R = 0x00000000U;
				}
			}
			else if(chn == 3U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PB15].R = 0x00000000U;
				}
				else
				{
					SIUL2.MSCR_IO[PG2].R = 0x00000000U;

					SIUL2.MSCR_IO[PG1].R = 0x00000000U;
				}
			}
			else if(chn == 4U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PG4].R = 0x00000000U;
				}
				else
				{
			        ret = STATUS_ERROR;
				}
			}
			else if(chn == 5U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PG3].R = 0x00000000U;
				}
				else
				{
			        ret = STATUS_ERROR;
				}
			}
			else if(chn == 6U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PG2].R = 0x00000000U;
				}
				else
				{
			        ret = STATUS_ERROR;
				}
			}
			else if(chn == 7U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PG1].R = 0x00000000U;
				}
				else
				{
			        ret = STATUS_ERROR;
				}
			}
			else
			{
		        ret = STATUS_ERROR;
			}

			break;
		}

		case SAF_SDADC_INSTANCE_4:
		{
			if(chn == 0U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PE3].R = 0x00000000U;
				}
				else
				{
					SIUL2.MSCR_IO[PE3].R = 0x00000000U;

					SIUL2.MSCR_IO[PD13].R = 0x00000000U;
				}
			}
			else if(chn == 1U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PD13].R = 0x00000000U;
				}
				else
				{
					SIUL2.MSCR_IO[PC0].R = 0x00000000U;

					SIUL2.MSCR_IO[PC1].R = 0x00000000U;
				}
			}
			else if(chn == 2U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PC0].R = 0x00000000U;
				}
				else
				{
			        ret = STATUS_ERROR;
				}
			}
			else if(chn == 3U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PC1].R = 0x00000000U;
				}
				else
				{
			        ret = STATUS_ERROR;
				}
			}
			else
			{
		        ret = STATUS_ERROR;
			}

			break;
		}

		case SAF_SDADC_INSTANCE_6:
		{
			if(chn == 0U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PR2].R = 0x00000000U;
				}
				else
				{
					SIUL2.MSCR_IO[PR2].R = 0x00000000U;

					SIUL2.MSCR_IO[PR3].R = 0x00000000U;
				}
			}
			else if(chn == 1U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PR3].R = 0x00000000U;
				}
				else
				{
					SIUL2.MSCR_IO[PR4].R = 0x00000000U;

					SIUL2.MSCR_IO[PR5].R = 0x00000000U;
				}
			}
			else if(chn == 2U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PR4].R = 0x00000000U;
				}
				else
				{
			        ret = STATUS_ERROR;
				}
			}
			else if(chn == 3U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PR5].R = 0x00000000U;
				}
				else
				{
			        ret = STATUS_ERROR;
				}
			}
			else
			{
		        ret = STATUS_ERROR;
			}

			break;
		}

		case SAF_SDADC_INSTANCE_7:
		{
			if(chn == 0U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PR8].R = 0x00000000U;
				}
				else
				{
					SIUL2.MSCR_IO[PR8].R = 0x00000000U;

					SIUL2.MSCR_IO[PR9].R = 0x00000000U;
				}
			}
			else if(chn == 1U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PR9].R = 0x00000000U;
				}
				else
				{
					SIUL2.MSCR_IO[PY0].R = 0x00000000U;

					SIUL2.MSCR_IO[PY1].R = 0x00000000U;
				}
			}
			else if(chn == 2U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PY0].R = 0x00000000U;
				}
				else
				{
			        ret = STATUS_ERROR;
				}
			}
			else if(chn == 3U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PY1].R = 0x00000000U;
				}
				else
				{
			        ret = STATUS_ERROR;
				}
			}
			else
			{
		        ret = STATUS_ERROR;
			}

			break;
		}

		case SAF_SDADC_INSTANCE_8:
		{
			if(chn == 0U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PR12].R = 0x00000000U;
				}
				else
				{
					SIUL2.MSCR_IO[PR12].R = 0x00000000U;

					SIUL2.MSCR_IO[PR13].R = 0x00000000U;
				}
			}
			else if(chn == 1U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PR13].R = 0x00000000U;
				}
				else
				{
					SIUL2.MSCR_IO[PR14].R = 0x00000000U;

					SIUL2.MSCR_IO[PR15].R = 0x00000000U;
				}
			}
			else if(chn == 2U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PR14].R = 0x00000000U;
				}
				else
				{
			        ret = STATUS_ERROR;
				}
			}
			else if(chn == 3U)
			{
				if(FALSE == diffEn)
				{
					SIUL2.MSCR_IO[PR15].R = 0x00000000U;
				}
				else
				{
			        ret = STATUS_ERROR;
				}
			}
			else
			{
		        ret = STATUS_ERROR;
			}

			break;
		}

		default:
		{
			ret = STATUS_ERROR;
			break;
		}
	}

	return ret;
}

SAF_ADC_SEC_CODE
void SAF_SDADC_LLD_Init(const Saf_Sdadc_InstanceType instance, const Saf_Sdadc_ConfigType * const ConfigPtr)
{
    DEV_ASSERT(((uint8_t)instance < ADC_SAF_SDADC_MAX_INSTANCE) && ((uint8_t)instance != 5U));
    DEV_ASSERT(ConfigPtr != NULL);

    uint8_t u8inst = (uint8_t)instance;

    uint8_t i;

    SAF_SDADC_TagType * const BasePtr = Adc_SdadcBase[u8inst];

	uint32_t gain_cal_val,offset_cal_val = 0U;

	IntrId const sdadc_irq_num[10U] = {SDADC_0_IRQn, SDADC_1_IRQn ,SDADC_2_IRQn ,SDADC_3_IRQn ,SDADC_4_IRQn,/*PRQA S 3604*/
			SDADC_5_IRQn, SDADC_6_IRQn, SDADC_7_IRQn, SDADC_8_IRQn, SDADC_9_IRQn};

    DEV_ASSERT((ConfigPtr->AnalogCfg.PreGain == SAF_SDADC_PRE_GAIN_X1) || \
               (ConfigPtr->AnalogCfg.PreGain == SAF_SDADC_PRE_GAIN_X2) || \
               (ConfigPtr->AnalogCfg.PreGain == SAF_SDADC_PRE_GAIN_X4));
    DEV_ASSERT((uint8_t)(ConfigPtr->AnalogCfg.VcomSel) <= (uint8_t)SAF_SDADC_VCOM_SEL_VREF_L);
    DEV_ASSERT((uint8_t)(ConfigPtr->AnalogCfg.ClkDiv) <= (uint8_t)SAF_SDADC_CLK_DIV_8);

    (void)SAF_SDADC_LLD_PinInit(instance, ConfigPtr->ChanSel.ChanDefaultId, ConfigPtr->ChanWrap.ChanWraparoundEn,
    		                          ConfigPtr->ChanWrap.ChanWraparoundNum, ConfigPtr->ChanSel.DifferenceEn);

    /*protect calculate process*/
    INTC_LLD_Set_IRQ_Disable(sdadc_irq_num[u8inst]);/*PRQA S 3200*/

    /* Analog Module PRE configuration */
    SAF_SDADC_ATT_SetAnalogModuleCfg(BasePtr, 1U, ConfigPtr->AnalogCfg.VcomSel, ConfigPtr->AnalogCfg.ClkDiv);

    /* Calculate Gain Value */
    gain_cal_val = SAF_SDADC_LLD_CalculateGain((Saf_Sdadc_InstanceType)u8inst);/*PRQA S 1441,4442*/

    /* Calculate Offset Value */
    offset_cal_val = SAF_SDADC_LLD_CalculateOffset((Saf_Sdadc_InstanceType)u8inst, gain_cal_val);/*PRQA S 1441,4442*/

    SAF_SDADC_CTRL_SetSdadcEnDis(BasePtr, FALSE);

    SAF_SDADC_STCFG_ClearSoftTrig(BasePtr);

    SAF_SDADC_STCFG_SetFifoSoftReset(BasePtr);

    SAF_SDADC_ATT_SetAnalogModuleCfg(BasePtr, ConfigPtr->AnalogCfg.PreGain, ConfigPtr->AnalogCfg.VcomSel, ConfigPtr->AnalogCfg.ClkDiv);

    uint32_t cicFilterDecimationFactor;
    uint32_t cicFilterOutputShifter;
    boolean fir0State = TRUE, fir1State = TRUE, preFilterState = TRUE;

    switch(ConfigPtr->OsrVal)
    {
		case SAF_SDADC_OSR_12:
		{
			if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
			{
				cicFilterDecimationFactor = 5U;

				cicFilterOutputShifter = 2U;

				if(ConfigPtr->AnalogCfg.PreGain == 2U)
				{
					cicFilterOutputShifter += 1U;
				}

				fir0State = FALSE;

				preFilterState = FALSE;
			}
			else
			{
				cicFilterDecimationFactor = 2U;

				cicFilterOutputShifter = 3U;

				fir0State = FALSE;
			}

			break;
		}

		case SAF_SDADC_OSR_16:
		{
			if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
			{
				cicFilterDecimationFactor = 3U;

				cicFilterOutputShifter = 3U;

				if(ConfigPtr->AnalogCfg.PreGain == 2U)
				{
					cicFilterOutputShifter += 1U;
				}

				fir0State = FALSE;
			}
			else
			{
				cicFilterDecimationFactor = 3U;

				cicFilterOutputShifter = 4U;

				fir0State = FALSE;
			}

			break;
		}

		case SAF_SDADC_OSR_24:
		{
			if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
			{
				cicFilterDecimationFactor = 5U;

				cicFilterOutputShifter = 6U;

				if(ConfigPtr->AnalogCfg.PreGain == 2U)
				{
					cicFilterOutputShifter += 1U;
				}

				fir0State = FALSE;
			}
			else
			{
				cicFilterDecimationFactor = 2U;

				cicFilterOutputShifter = 7U;
			}

			break;
		}

		case SAF_SDADC_OSR_32:
		{
			if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
			{
				cicFilterDecimationFactor = 3U;

				cicFilterOutputShifter = 3U;

				if(ConfigPtr->AnalogCfg.PreGain == 2U)
				{
					cicFilterOutputShifter += 1U;
				}
			}
			else
			{
				cicFilterDecimationFactor = 3U;

				cicFilterOutputShifter = 4U;
			}

			break;
		}

		case SAF_SDADC_OSR_48:
		{
			if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
			{
				cicFilterDecimationFactor = 5U;

				cicFilterOutputShifter = 6U;

				if(ConfigPtr->AnalogCfg.PreGain == 2U)
				{
					cicFilterOutputShifter += 1U;
				}
			}
			else
			{
				cicFilterDecimationFactor = 5U;

				cicFilterOutputShifter = 7U;
			}

			break;
		}

		case SAF_SDADC_OSR_64:
		{
			if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
			{
				cicFilterDecimationFactor = 7U;

				cicFilterOutputShifter = 7U;

				if(ConfigPtr->AnalogCfg.PreGain == 2U)
				{
					cicFilterOutputShifter += 1U;
				}
			}
			else
			{
				cicFilterDecimationFactor = 7U;

				cicFilterOutputShifter = 8U;
			}

			break;
		}

		case SAF_SDADC_OSR_96:
		{
			if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
			{
				cicFilterDecimationFactor = 11U;

				cicFilterOutputShifter = 10U;

				if(ConfigPtr->AnalogCfg.PreGain == 2U)
				{
					cicFilterOutputShifter += 1U;
				}
			}
			else
			{
				cicFilterDecimationFactor = 11U;

				cicFilterOutputShifter = 11U;
			}

			break;
		}

		case SAF_SDADC_OSR_128:
		{
			if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
			{
				cicFilterDecimationFactor = 15U;

				cicFilterOutputShifter = 11U;

				if(ConfigPtr->AnalogCfg.PreGain == 2U)
				{
					cicFilterOutputShifter += 1U;
				}
			}
			else
			{
				cicFilterDecimationFactor = 15U;

				cicFilterOutputShifter = 12U;
			}

			break;
		}

		case SAF_SDADC_OSR_160:
		{
			if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
			{
				cicFilterDecimationFactor = 19U;

				cicFilterOutputShifter = 12U;

				if(ConfigPtr->AnalogCfg.PreGain == 2U)
				{
					cicFilterOutputShifter += 1U;
				}
			}
			else
			{
				cicFilterDecimationFactor = 19U;

				cicFilterOutputShifter = 13U;
			}

			break;
		}

		case SAF_SDADC_OSR_192:
		{
			if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
			{
				cicFilterDecimationFactor = 23U;

				cicFilterOutputShifter = 13U;

				if(ConfigPtr->AnalogCfg.PreGain == 2U)
				{
					cicFilterOutputShifter += 1U;
				}
			}
			else
			{
				cicFilterDecimationFactor = 23U;

				cicFilterOutputShifter = 14U;
			}

			break;
		}

		case SAF_SDADC_OSR_224:
		{
			if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
			{
				cicFilterDecimationFactor = 27U;

				cicFilterOutputShifter = 14U;

				if(ConfigPtr->AnalogCfg.PreGain == 2U)
				{
					cicFilterOutputShifter += 1U;
				}
			}
			else
			{
				cicFilterDecimationFactor = 27U;

				cicFilterOutputShifter = 15U;
			}

			break;
		}

		case SAF_SDADC_OSR_256:
		{
			if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
			{
				cicFilterDecimationFactor = 31U;

				cicFilterOutputShifter = 15U;

				if(ConfigPtr->AnalogCfg.PreGain == 2U)
				{
					cicFilterOutputShifter += 1U;
				}
			}
			else
			{
				cicFilterDecimationFactor = 31U;

				cicFilterOutputShifter = 16U;
			}

			break;
		}

		default:/*PRQA S 2016*/
		{
			break;
		}
    }

    SAF_SDADC_GAINCORR_SetCorrection(BasePtr, gain_cal_val, cicFilterOutputShifter);/*PRQA S 2962*/

    SAF_SDADC_FCFGC_SetCICFilterDecFactor(BasePtr, cicFilterDecimationFactor);/*PRQA S 2962*/

    SAF_SDADC_FCFGC_SetCICFilterStartVal(BasePtr, cicFilterDecimationFactor + 1U);

	SAF_SDADC_OFFCOMP_SetOffsetVal(BasePtr, offset_cal_val);

	SAF_SDADC_FCNTC_SetCICFilterDecCounter(BasePtr, cicFilterDecimationFactor);

	SAF_SDADC_CH_WRAP_SetChannelDefault(BasePtr, ConfigPtr->ChanSel.ChanDefaultId, ConfigPtr->ChanWrap.ChanWraparoundNum);

	SAF_SDADC_GAINCAL_SetMultiFactor(BasePtr, 0x1000U);

    SAF_SDADC_FCFGM_SetFIR0FilterEnDis(BasePtr, fir0State);

    SAF_SDADC_FCFGM_SetFIR1FilterEnDis(BasePtr, fir1State);

    SAF_SDADC_FCFGM_SetOvershootCompenEnDis(BasePtr, ConfigPtr->FirFilter.OvershootCompEn);

    SAF_SDADC_FCFGM_SetFIR1FilterDecRate(BasePtr, ConfigPtr->FirFilter.Fir1DecimationRate);

    SAF_SDADC_FCFGM_SetCICFilterMode(BasePtr, ConfigPtr->FirFilter.CicMode);

    SAF_SDADC_FCFGM_SetPrefilterEnDis(BasePtr, preFilterState);

    if(ConfigPtr->Comparator.BoundaryComparatorEn == TRUE)
    {
        SAF_SDADC_FCFGM_SetBoundaryComparatorEnDis(BasePtr, TRUE);

        SAF_SDADC_BOUNDSEL_SetLowerUpperBoundaryLimit(BasePtr, ConfigPtr->Comparator.LowerBoundary, ConfigPtr->Comparator.UpperBoundary);
    }

    SAF_SDADC_FCFGM_SetExtMeshClkEnDis(BasePtr, ConfigPtr->ExtMeshClkSel);

    if(ConfigPtr->DCTestEn == FALSE)
    {
        SAF_SDADC_FCFGM_SetOffsetCompenFilterEn(BasePtr, ConfigPtr->FirFilter.OffsetCompFilterEn);
    }
    else
    {
    	SAF_SDADC_FCFGM_SetOffsetCompenFilterEn(BasePtr, FALSE);
    }

    SAF_SDADC_FCFGM_SetChannelWraparoundEnDis(BasePtr, ConfigPtr->ChanWrap.ChanWraparoundEn);

    SAF_SDADC_FCFGM_SetDifferenceEnDis(BasePtr, ConfigPtr->ChanSel.DifferenceEn);

    SAF_SDADC_FCFGM_SetCalibEnDis(BasePtr, ConfigPtr->FirFilter.CalibrationEn);

    /* Overshoot Compensation */
    if (ConfigPtr->FirFilter.OvershootCompEn != FALSE)
    {
        DEV_ASSERT(ConfigPtr->OvershootComp.StepDetectionThreshold <= SAF_SDADC_OVERSHOOT_STEP_DETECTION_THRESHOLD_MAX);

        SAF_SDADC_OVSCFG_SetSlewRateFilterStrength(BasePtr, ConfigPtr->OvershootComp.SlewRateFilterStrength);

        SAF_SDADC_OVSCFG_SetSlewRateFilterRunTime(BasePtr, ConfigPtr->OvershootComp.SlewRateFilterRunTime);

        SAF_SDADC_OVSCFG_SetStepDetectionMode(BasePtr, ConfigPtr->OvershootComp.StepDetectionMode);

        SAF_SDADC_OVSCFG_SetStepDetectionThreshold(BasePtr, ConfigPtr->OvershootComp.StepDetectionThreshold);
    }

    /* Interrupt/DMA Enable Configuration */
    SAF_SDADC_IECFG_SetFifoWaterMarkerIntEnDis(BasePtr, ConfigPtr->IntDma.FifoWaterMarkerIntEn);

    SAF_SDADC_IECFG_SetFifoOverFlowIntEnDis(BasePtr, ConfigPtr->IntDma.FifoOverFlowIntEn);

    SAF_SDADC_IECFG_SetDataOverFlowIntEnDis(BasePtr, ConfigPtr->IntDma.DataOverFlowIntEn);

    SAF_SDADC_IECFG_SetDMAReqEnDis(BasePtr, ConfigPtr->IntDma.DmaReqEn);

    if(ConfigPtr->IntDma.DmaReqEn == TRUE)
    {
    	SAF_SDADC_LLD_ConfigDma(instance, ConfigPtr->FifoCfg.FifoWaterMarker, ConfigPtr->DmaCfg);
    }

	/* Integration configuration */
    if(ConfigPtr->IntegratorEn == TRUE)
    {
		DEV_ASSERT((ConfigPtr->Integrator.IntegratorTrigMode) <= SAF_SDADC_INTEGRATOR_TRIG_MODE_ALWAYS_ACTIVE);
		DEV_ASSERT((ConfigPtr->Integrator.IntegratorShiftCtrl) <= SAF_SDADC_INTEGRATOR_SHIFT_CTRL_SEL_BITS_9_25);

		SAF_SDADC_DICFG_SetIntegratorTriggerMode(BasePtr, ConfigPtr->Integrator.IntegratorTrigMode);

		SAF_SDADC_IWCTR_SetIntegratorShiftCtrl(BasePtr, ConfigPtr->Integrator.IntegratorShiftCtrl);

		SAF_SDADC_IWCTR_SetIntegrationWindowSize(BasePtr, ConfigPtr->Integrator.IntegrationWindowSize);

		SAF_SDADC_IWCTR_SetFilterRestartCtrl(BasePtr, ConfigPtr->Integrator.FilterChainRestartCtrl);

		SAF_SDADC_IWCTR_SetIntegrationCycle(BasePtr, ConfigPtr->Integrator.NumOfIntegrationCycles);

		SAF_SDADC_IWCTR_SetNumberOfValDiscarded(BasePtr, ConfigPtr->Integrator.NumOfDiscardedVal);

		SAF_SDADC_IWCTR_SetNumberOfValAccumulated(BasePtr, ConfigPtr->Integrator.NumOfAccumulatedVal);
    }

	/* Filter Chain Discard */
	SAF_SDADC_FCDIS_SetFilterChainDiscardEnDis(BasePtr, ConfigPtr->FilterChainDiscard.FilterChainDiscardEn);

	SAF_SDADC_FCDIS_SetFilterChainDiscardNum(BasePtr, ConfigPtr->FilterChainDiscard.FilterChainDiscardNum);

	/* FIFO Configuration */
	DEV_ASSERT(ConfigPtr->FifoCfg.FifoSize <= SAF_SDADC_FIFO_SIZE_MAX);
	DEV_ASSERT(ConfigPtr->FifoCfg.FifoSize >= ConfigPtr->FifoCfg.FifoWaterMarker);

	SAF_SDADC_FCFG_SetFifoSize(BasePtr, ConfigPtr->FifoCfg.FifoSize);

	SAF_SDADC_FCFG_SetFifoWaterMarkerVal(BasePtr, ConfigPtr->FifoCfg.FifoWaterMarker);

	SAF_SDADC_FCFG_SetInfoEnDis(BasePtr, ConfigPtr->FifoCfg.InfoEn);

	SAF_SDADC_FCFG_SetSignEnDis(BasePtr, ConfigPtr->FifoCfg.SignEn);

	/* Hardware Trigger Configuration */
	for(i = 0U; i < SAF_SDADC_HW_TRIG_CNT; i++)
	{
		SAF_SDADC_HTCFG_SetHwTriggerEdge(BasePtr, i, ConfigPtr->HwTrigSel[i]);
	}

    /* Clear flag */
    SAF_SDADC_WMINTSTAT_ClearWaterMarkerIntState(BasePtr);
    SAF_SDADC_OVINTSTAT_ClearDataOverFlowIntState(BasePtr);
    SAF_SDADC_OVINTSTAT_ClearFifoOverFlowIntState(BasePtr);

    /*protect calculate process*/
    INTC_LLD_Set_IRQ_Enable(sdadc_irq_num[u8inst]);/*PRQA S 3200*/
}

SAF_ADC_SEC_CODE
void SAF_SDADC_LLD_DeInit(const Saf_Sdadc_InstanceType instance)
{
    DEV_ASSERT(((uint8_t)instance < ADC_SAF_SDADC_MAX_INSTANCE) && ((uint8_t)instance != 5U));

    Saf_Sdadc_InstanceType instance_l = instance;

    SAF_SDADC_TagType * const BasePtr = Adc_SdadcBase[(uint8_t)instance_l];

    /* SDADC disable */
    SAF_SDADC_CTRL_SetSdadcEnDis(BasePtr, FALSE);

    /* Flush FIFO */
    SAF_SDADC_STCFG_SetFifoSoftReset(BasePtr);

    /* Interrupt/DMA */
    BasePtr->IECFG.R    = 0UL;
    /* Control */
    BasePtr->FCFGM.R    = 0UL;
    BasePtr->DICFG.R    = 0UL;
    /* Configuration */
    BasePtr->GAINCORR.R = 0UL;
    BasePtr->GAINCAL.R  = 0UL;
    BasePtr->FCFGC.R    = 0UL;
    BasePtr->OFFCOMP.R  = 0UL;
    BasePtr->FCFG.R     = SAF_SDADC_FCFG_FIFOSIZE(SAF_SDADC_FIFO_SIZE_MAX);
    BasePtr->IWCTR.R    = 0UL;
    BasePtr->BOUNDSEL.R = 0UL;
    BasePtr->OVSCFG.R   = 0UL;
    BasePtr->HTCFG.R    = 0UL;
    BasePtr->FCDIS.R    = 0UL;
    BasePtr->CH_WRAP.R  = 0UL;

    SAF_SDADC_RES_SetResistorSelChan(BasePtr, 0U, 0U);
    SAF_SDADC_ATT_SetAnalogModuleCfg(BasePtr, 0U, 0U, 0U);

    /* Clear flag */
    SAF_SDADC_WMINTSTAT_ClearWaterMarkerIntState(BasePtr);
    SAF_SDADC_OVINTSTAT_ClearDataOverFlowIntState(BasePtr);
    SAF_SDADC_OVINTSTAT_ClearFifoOverFlowIntState(BasePtr);

	MC_RGM.PRST1.R = 0x1f000000;
	MC_RGM.PRST5.R = 0x1f000000;
	MC_RGM.PRST1.R = 0x00000000;
	MC_RGM.PRST5.R = 0x00000000;

}

SAF_ADC_SEC_CODE
void SAF_SDADC_LLD_ModuleEnable(const Saf_Sdadc_InstanceType instance)
{
    DEV_ASSERT(((uint8_t)instance < ADC_SAF_SDADC_MAX_INSTANCE) && ((uint8_t)instance != 5U));

    Saf_Sdadc_InstanceType instance_l = instance;

    SAF_SDADC_TagType * const BasePtr = Adc_SdadcBase[(uint8_t)instance_l];

    SAF_SDADC_CTRL_SetSdadcEnDis(BasePtr, TRUE);
}

SAF_ADC_SEC_CODE
void SAF_SDADC_LLD_ModuleDisable(const Saf_Sdadc_InstanceType instance)
{
    DEV_ASSERT(((uint8_t)instance < ADC_SAF_SDADC_MAX_INSTANCE) && ((uint8_t)instance != 5U));

    Saf_Sdadc_InstanceType instance_l = instance;

    SAF_SDADC_TagType * const BasePtr = Adc_SdadcBase[(uint8_t)instance_l];

    SAF_SDADC_CTRL_SetSdadcEnDis(BasePtr, FALSE);
}

SAF_ADC_SEC_CODE
uint32_t SAF_SDADC_LLD_CalculateGain(const Saf_Sdadc_InstanceType instance)
{
    DEV_ASSERT(((uint8_t)instance < ADC_SAF_SDADC_MAX_INSTANCE) && ((uint8_t)instance != 5U));

    Saf_Sdadc_InstanceType instance_l = instance;

    SAF_SDADC_TagType * const BasePtr = Adc_SdadcBase[(uint8_t)instance_l];

    uint32_t attValue, attVcomSelValue, attClkDivValue;

	uint32_t gain_corr_p = 0x1000;

	uint32_t gain_corr_n = 0x1000;

	uint32_t gain_sft_mask = 0x1000;

	uint32_t hard_data ,gain_corr= 0;

	uint32_t tmp = 0;

    attValue = SAF_SDADC_ATT_GetAnalogModuleCfg(BasePtr);

    attClkDivValue = (attValue & SAF_SDADC_ATT_ADC_DIV_LV_MASK) >> SAF_SDADC_ATT_ADC_DIV_LV_SHIFT;

    attVcomSelValue = (attValue & SAF_SDADC_ATT_VCOM_SEL_LV_MASK) >> SAF_SDADC_ATT_VCOM_SEL_LV_SHIFT;

    SAF_SDADC_ATT_SetAnalogModuleCfg(BasePtr, 1U, attVcomSelValue, attClkDivValue);

    SAF_SDADC_RES_SetResistorSelChan(BasePtr, 0U, 0U);

    SAF_SDADC_CTRL_SetSdadcEnDis(BasePtr, FALSE);

    SAF_SDADC_CH_WRAP_SetChannelDefault(BasePtr, 6U, 0U);

    SAF_SDADC_GAINCORR_SetCorrection(BasePtr, 0U, 0U);

    SAF_SDADC_GAINCAL_SetMultiFactor(BasePtr, 0x1000U);

    SAF_SDADC_FCFGC_SetCICFilterDecFactor(BasePtr, 5U);

    SAF_SDADC_FCFGC_SetCICFilterStartVal(BasePtr, 7U);

    SAF_SDADC_FCNTC_SetCICFilterDecCounter(BasePtr, 5U);

    SAF_SDADC_OFFCOMP_SetOffsetVal(BasePtr, 0U);

    SAF_SDADC_FCFGM_SetFIR0FilterEnDis(BasePtr, TRUE);

    SAF_SDADC_FCFGM_SetFIR1FilterEnDis(BasePtr, TRUE);

    SAF_SDADC_FCFGM_SetOvershootCompenEnDis(BasePtr, FALSE);

    SAF_SDADC_FCFGM_SetFIR1FilterDecRate(BasePtr, 0U);

    SAF_SDADC_FCFGM_SetCICFilterMode(BasePtr, 0U);

    SAF_SDADC_FCFGM_SetPrefilterEnDis(BasePtr, TRUE);

    SAF_SDADC_FCFGM_SetBoundaryComparatorEnDis(BasePtr, FALSE);

    SAF_SDADC_FCFGM_SetExtMeshClkEnDis(BasePtr, FALSE);

    SAF_SDADC_FCFGM_SetOffsetCompenFilterEn(BasePtr, 0U);

    SAF_SDADC_FCFGM_SetChannelWraparoundEnDis(BasePtr, FALSE);

    SAF_SDADC_FCFGM_SetDifferenceEnDis(BasePtr, TRUE);

    SAF_SDADC_FCFGM_SetCalibEnDis(BasePtr, TRUE);

    SAF_SDADC_IECFG_SetFifoWaterMarkerIntEnDis(BasePtr, TRUE);

    SAF_SDADC_IECFG_SetFifoOverFlowIntEnDis(BasePtr, TRUE);

    SAF_SDADC_IECFG_SetDataOverFlowIntEnDis(BasePtr, TRUE);

    SAF_SDADC_IECFG_SetDMAReqEnDis(BasePtr, FALSE);

    SAF_SDADC_FCFG_SetFifoSize(BasePtr, 0x40U);

    SAF_SDADC_FCFG_SetFifoWaterMarkerVal(BasePtr, 0x20U);

    SAF_SDADC_FCFG_SetInfoEnDis(BasePtr, FALSE);

    SAF_SDADC_FCFG_SetSignEnDis(BasePtr, FALSE);

    SAF_SDADC_FCDIS_SetFilterChainDiscardEnDis(BasePtr, TRUE);

    SAF_SDADC_FCDIS_SetFilterChainDiscardNum(BasePtr, 0x80U);

    SAF_SDADC_CTRL_SetSdadcEnDis(BasePtr, TRUE);

    tmp = SAF_SDADC_FDATA_GetFifoData(BasePtr);

    tmp = tmp & 0x0000FFFFU;/*PRQA S 2983*/

    /*GAIN_CAL_P*/
    while(gain_sft_mask != 0)/*PRQA S 1843*/
	{
    	SAF_SDADC_WMINTSTAT_ClearWaterMarkerIntState(BasePtr);

		SAF_SDADC_GAINCORR_SetCorrection(BasePtr, gain_corr_p, 0x07U);

		SAF_SDADC_STCFG_SetSoftTrigEn(BasePtr);

		while(SAF_SDADC_WMINTSTAT_GetWaterMarkerIntState(BasePtr) == 0U)
		{
			;
		}

		hard_data = SAF_SDADC_FDATA_GetFifoData(BasePtr);

	    hard_data = hard_data & 0x0000FFFFU;

	    SAF_SDADC_STCFG_ClearSoftTrig(BasePtr);

		delay(0x200U);

		SAF_SDADC_STCFG_SetFifoSoftReset(BasePtr);

		if(hard_data > 0x0007000U)
		{
			gain_corr_p = (gain_corr_p & (~gain_sft_mask)) | (gain_sft_mask >> 1);

		}
		else
		{
			gain_corr_p = gain_corr_p + (gain_sft_mask >> 1);
		}

		gain_sft_mask = gain_sft_mask >> 1;
	}

    /*GAIN_CAL_N*/
	gain_sft_mask = 0x1000U;

    SAF_SDADC_CH_WRAP_SetChannelDefault(BasePtr, 7U, 0U);

	while(gain_sft_mask != 0)/*PRQA S 1843*/
	{
    	SAF_SDADC_WMINTSTAT_ClearWaterMarkerIntState(BasePtr);

		SAF_SDADC_GAINCORR_SetCorrection(BasePtr, gain_corr_n, 0x07U);

		SAF_SDADC_STCFG_SetSoftTrigEn(BasePtr);

		while(SAF_SDADC_WMINTSTAT_GetWaterMarkerIntState(BasePtr) == 0U)
		{
			;
		}

		hard_data = SAF_SDADC_FDATA_GetFifoData(BasePtr);

	    hard_data = hard_data & 0x0000FFFFU;

	    SAF_SDADC_STCFG_ClearSoftTrig(BasePtr);

		delay(0x200U);

		SAF_SDADC_STCFG_SetFifoSoftReset(BasePtr);

		if(hard_data < 0x0009000U)
		{
			gain_corr_n = (gain_corr_n & (~gain_sft_mask)) | (gain_sft_mask >> 1);
		}
		else
		{
			gain_corr_n = gain_corr_n + (gain_sft_mask >> 1);
		}

		gain_sft_mask = gain_sft_mask >> 1;
	}

	gain_corr = (gain_corr_p + gain_corr_n ) >> 1;

	return gain_corr ;
}

SAF_ADC_SEC_CODE
uint32_t SAF_SDADC_LLD_CalculateOffset(const Saf_Sdadc_InstanceType instance, uint32_t gainVal)
{
    DEV_ASSERT(((uint8_t)instance < ADC_SAF_SDADC_MAX_INSTANCE) && ((uint8_t)instance != 5U));

    Saf_Sdadc_InstanceType instance_l = instance;

    SAF_SDADC_TagType * const BasePtr = Adc_SdadcBase[(uint8_t)instance_l];

    uint32_t attValue, attVcomSelValue, attClkDivValue;

	uint32_t offcmp_n1 = 0;

	uint16_t off_data = 0;

    attValue = SAF_SDADC_ATT_GetAnalogModuleCfg(BasePtr);

    attClkDivValue = (attValue & SAF_SDADC_ATT_ADC_DIV_LV_MASK) >> SAF_SDADC_ATT_ADC_DIV_LV_SHIFT;

    attVcomSelValue = (attValue & SAF_SDADC_ATT_VCOM_SEL_LV_MASK) >> SAF_SDADC_ATT_VCOM_SEL_LV_SHIFT;

    SAF_SDADC_ATT_SetAnalogModuleCfg(BasePtr, 1U, attVcomSelValue, attClkDivValue);

    SAF_SDADC_RES_SetResistorSelChan(BasePtr, 0U, 0U);

    /*Step 1*/
    SAF_SDADC_CTRL_SetSdadcEnDis(BasePtr, FALSE);

    SAF_SDADC_CTRL_SetSdadcEnDis(BasePtr, TRUE);

    /*Step 2*/
    SAF_SDADC_CH_WRAP_SetChannelDefault(BasePtr, 5U, 0U);

    delay(0x200U);

    SAF_SDADC_GAINCORR_SetCorrection(BasePtr, gainVal, 7U);

    SAF_SDADC_FCNTC_SetCICFilterDecCounter(BasePtr, 5U);

    SAF_SDADC_GAINCAL_SetMultiFactor(BasePtr, 0x1000U);

    SAF_SDADC_FCFGC_SetCICFilterDecFactor(BasePtr, 5U);

    SAF_SDADC_FCFGC_SetCICFilterStartVal(BasePtr, 6U);

    SAF_SDADC_FCFGM_SetFIR0FilterEnDis(BasePtr, TRUE);

    SAF_SDADC_FCFGM_SetFIR1FilterEnDis(BasePtr, TRUE);

    SAF_SDADC_FCFGM_SetOvershootCompenEnDis(BasePtr, FALSE);

    SAF_SDADC_FCFGM_SetFIR1FilterDecRate(BasePtr, 0U);

    SAF_SDADC_FCFGM_SetCICFilterMode(BasePtr, 0U);

    SAF_SDADC_FCFGM_SetPrefilterEnDis(BasePtr, TRUE);

    SAF_SDADC_FCFGM_SetBoundaryComparatorEnDis(BasePtr, FALSE);

    SAF_SDADC_FCFGM_SetExtMeshClkEnDis(BasePtr, FALSE);

    SAF_SDADC_FCFGM_SetOffsetCompenFilterEn(BasePtr, 0x4U);

    SAF_SDADC_FCFGM_SetChannelWraparoundEnDis(BasePtr, FALSE);

    SAF_SDADC_FCFGM_SetDifferenceEnDis(BasePtr, TRUE);

    SAF_SDADC_FCFGM_SetCalibEnDis(BasePtr, FALSE);

    SAF_SDADC_OFFCOMP_SetOffsetVal(BasePtr, 0U);

    SAF_SDADC_IECFG_SetFifoWaterMarkerIntEnDis(BasePtr, TRUE);

    SAF_SDADC_IECFG_SetFifoOverFlowIntEnDis(BasePtr, TRUE);

    SAF_SDADC_IECFG_SetDataOverFlowIntEnDis(BasePtr, TRUE);

    SAF_SDADC_IECFG_SetDMAReqEnDis(BasePtr, FALSE);

    SAF_SDADC_FCFG_SetFifoSize(BasePtr, 0x40U);

    SAF_SDADC_FCFG_SetFifoWaterMarkerVal(BasePtr, 0x20U);

    SAF_SDADC_FCDIS_SetFilterChainDiscardEnDis(BasePtr, TRUE);

    SAF_SDADC_FCDIS_SetFilterChainDiscardNum(BasePtr, 0xFFU);

    /*Step 3*/
	SAF_SDADC_STCFG_SetSoftTrigEn(BasePtr);

    delay(0x200U);

    /*Step 4*/
	while(1)
	{
		while(SAF_SDADC_WMINTSTAT_GetWaterMarkerIntState(BasePtr) == FALSE)
		{

		}

		(void)SAF_SDADC_FDATA_GetFifoData(BasePtr);

	    /*Step 5*/
		off_data = (short)(SAF_SDADC_OFFCOMP_GetOffsetVal(BasePtr) & 0x0000FFFFU) ;/*PRQA S 4394,4434*/ /* polyspace RTE:OVFL */

		if(abs(offcmp_n1 - off_data) > (int)0x03U)/*PRQA S 3335*/
		{
	    	SAF_SDADC_WMINTSTAT_ClearWaterMarkerIntState(BasePtr);
			offcmp_n1 = off_data;

		}
		else
		{
			break;
		}
	}
	return (uint32_t)off_data;
}

SAF_ADC_SEC_CODE
uint32_t SAF_SDADC_LLD_GetFifoData(const Saf_Sdadc_InstanceType instance)
{
    DEV_ASSERT(((uint8_t)instance < ADC_SAF_SDADC_MAX_INSTANCE) && ((uint8_t)instance != 5U));
    Saf_Sdadc_InstanceType instance_l = instance;

    SAF_SDADC_TagType * const BasePtr = Adc_SdadcBase[(uint8_t)instance_l];

    return SAF_SDADC_FDATA_GetFifoData(BasePtr);
}

SAF_ADC_SEC_CODE
void SAF_SDADC_LLD_SetSoftTrigger(const Saf_Sdadc_InstanceType instance)
{
    DEV_ASSERT(((uint8_t)instance < ADC_SAF_SDADC_MAX_INSTANCE) && ((uint8_t)instance != 5U));
    Saf_Sdadc_InstanceType instance_l = instance;

    SAF_SDADC_TagType * const BasePtr = Adc_SdadcBase[(uint8_t)instance_l];

	SAF_SDADC_STCFG_SetSoftTrigEn(BasePtr);
}

SAF_ADC_SEC_CODE
boolean SAF_SDADC_LLD_GetWaterMarkerIntState(const Saf_Sdadc_InstanceType instance)
{
    DEV_ASSERT(((uint8_t)instance < ADC_SAF_SDADC_MAX_INSTANCE) && ((uint8_t)instance != 5U));
    Saf_Sdadc_InstanceType instance_l = instance;

    SAF_SDADC_TagType * const BasePtr = Adc_SdadcBase[(uint8_t)instance_l];

    boolean ret;

    ret = SAF_SDADC_WMINTSTAT_GetWaterMarkerIntState(BasePtr);

    return ret;
}

SAF_ADC_SEC_CODE
void SAF_SDADC_LLD_ClearWaterMarkerIntState(const Saf_Sdadc_InstanceType instance)
{
    DEV_ASSERT(((uint8_t)instance < ADC_SAF_SDADC_MAX_INSTANCE) && ((uint8_t)instance != 5U));
    Saf_Sdadc_InstanceType instance_l = instance;

    SAF_SDADC_TagType * const BasePtr = Adc_SdadcBase[(uint8_t)instance_l];

    SAF_SDADC_WMINTSTAT_ClearWaterMarkerIntState(BasePtr);
}

SAF_ADC_SEC_CODE
boolean SAF_SDADC_LLD_GetDataOverFlowIntState(const Saf_Sdadc_InstanceType instance)
{
    DEV_ASSERT(((uint8_t)instance < ADC_SAF_SDADC_MAX_INSTANCE) && ((uint8_t)instance != 5U));
    Saf_Sdadc_InstanceType instance_l = instance;

    SAF_SDADC_TagType * const BasePtr = Adc_SdadcBase[(uint8_t)instance_l];

    boolean ret;

    ret = SAF_SDADC_OVINTSTAT_GetDataOverFlowIntState(BasePtr);

    return ret;
}

SAF_ADC_SEC_CODE
void SAF_SDADC_LLD_ClearDataOverFlowIntState(const Saf_Sdadc_InstanceType instance)
{
    DEV_ASSERT(((uint8_t)instance < ADC_SAF_SDADC_MAX_INSTANCE) && ((uint8_t)instance != 5U));
    Saf_Sdadc_InstanceType instance_l = instance;

    SAF_SDADC_TagType * const BasePtr = Adc_SdadcBase[(uint8_t)instance_l];

    SAF_SDADC_OVINTSTAT_ClearDataOverFlowIntState(BasePtr);
}

SAF_ADC_SEC_CODE
boolean SAF_SDADC_LLD_GetFifoOverFlowIntState(const Saf_Sdadc_InstanceType instance)
{
    DEV_ASSERT(((uint8_t)instance < ADC_SAF_SDADC_MAX_INSTANCE) && ((uint8_t)instance != 5U));
    Saf_Sdadc_InstanceType instance_l = instance;

    SAF_SDADC_TagType * const BasePtr = Adc_SdadcBase[(uint8_t)instance_l];

    boolean ret;

    ret = SAF_SDADC_OVINTSTAT_GetFifoOverFlowIntState(BasePtr);

    return ret;
}

SAF_ADC_SEC_CODE
void SAF_SDADC_LLD_ClearFifoOverFlowIntState(const Saf_Sdadc_InstanceType instance)
{
    DEV_ASSERT(((uint8_t)instance < ADC_SAF_SDADC_MAX_INSTANCE) && ((uint8_t)instance != 5U));
    Saf_Sdadc_InstanceType instance_l = instance;

    SAF_SDADC_TagType * const BasePtr = Adc_SdadcBase[(uint8_t)instance_l];

    SAF_SDADC_OVINTSTAT_ClearFifoOverFlowIntState(BasePtr);
}

SAF_ADC_SEC_CODE
void SAF_SDADC_LLD_SetInterruptState(const Saf_Sdadc_InstanceType instance, Saf_Sdadc_InterruptType intType, boolean intState)
{
    DEV_ASSERT(((uint8_t)instance < ADC_SAF_SDADC_MAX_INSTANCE) && ((uint8_t)instance != 5U));
    Saf_Sdadc_InstanceType instance_l = instance;

    SAF_SDADC_TagType * const BasePtr = Adc_SdadcBase[(uint8_t)instance_l];

    if(SAF_SDADC_INT_WATERMARKER == intType)
    {
        SAF_SDADC_IECFG_SetFifoWaterMarkerIntEnDis(BasePtr, intState);
    }
    else if(SAF_SDADC_INT_DATAOVERRUN == intType)
    {
    	SAF_SDADC_IECFG_SetDataOverFlowIntEnDis(BasePtr, intState);
    }
    else if(SAF_SDADC_INT_FIFOOVERRUN == intType)
    {
    	SAF_SDADC_IECFG_SetFifoOverFlowIntEnDis(BasePtr, intState);
    }
    else
    {
        /*Null*/
    }
}

SAF_ADC_SEC_CODE
void SAF_SDADC_LLD_ResetFifo(const Saf_Sdadc_InstanceType instance)
{
    DEV_ASSERT(((uint8_t)instance < ADC_SAF_SDADC_MAX_INSTANCE) && ((uint8_t)instance != 5U));
    Saf_Sdadc_InstanceType instance_l = instance;

    SAF_SDADC_TagType * const BasePtr = Adc_SdadcBase[(uint8_t)instance_l];

    SAF_SDADC_STCFG_SetFifoSoftReset(BasePtr);
}

SAF_ADC_SEC_CODE
void SAF_SDADC_LLD_ConfigDma(const Saf_Sdadc_InstanceType instance, uint8_t waterMarkerValue, Saf_Sdadc_DmaCfgType config)
{
    DEV_ASSERT(((uint8_t)instance < ADC_SAF_SDADC_MAX_INSTANCE) && ((uint8_t)instance != 5U));
    Saf_Sdadc_InstanceType instance_l = instance;

    SAF_SDADC_TagType * const BasePtr = Adc_SdadcBase[(uint8_t)instance_l];

    SafeDMARequestSourceType  sdadc_dma_src;
    uint32_t major_loop_time;
    uint32_t minor_transfer_byte;

    uint32_t dmaChannel;

    dmaChannel = config.DmaCh;

    major_loop_time = config.DmaRxSize / waterMarkerValue; /*PRQA S 2834*/ /* polyspace RTE:ZDV */

    minor_transfer_byte = waterMarkerValue * sizeof(uint32_t);

    SafeDMALoopTransferConfigType sdadcLoopConfig = /*PRQA S 3604*/
    {
        .dstAddrOffsetEn    = TRUE,
        .srcAddrOffsetEn    = FALSE,
        .minorLpOffset      = 0,
        .minorLpLinkEn      = FALSE,
        .minorLpLinkChn     = 0U,
        .majorLpLinkEn      = FALSE,
        .majorLpLinkChn     = 0U,
        .majorLpIterCnt     = major_loop_time
    };


    SafeDMATransferConfigType dmaConfigforsdadc = /*PRQA S 3604*/
    {
    	.srcAddr = (uint32_t)(&BasePtr->FDATA.R), /* Modified by function */
    	.destAddr = (uint32_t)(config.DmaRxBuf), /* Modified by function */
    	.srcTransDataSize = SAF_EDMA_TRANSFER_SIZE_4B,
    	.destTransDataSize = SAF_EDMA_TRANSFER_SIZE_4B,
    	.srcAddrOffset = (int16_t)0,
    	.destAddrOffset = (int16_t)sizeof(uint32_t),
    	.srcAddrAdjustLast = 0,
    	.destAddrAdjustLast = -(major_loop_time * minor_transfer_byte), /* PRQA S 3101,4446 */ /* polyspace RTE:OVFL */
    	.srcAddrModulo = SAF_EDMA_ADDRESS_MODULO_OFF,
    	.destAddrModulo = SAF_EDMA_ADDRESS_MODULO_OFF,
    	.minorTransByte = minor_transfer_byte, /* Modified by function */
    	.featureScatterGatherEn = FALSE,
    	.featureScatterGatherNextDescriptor = 0U,
    	.completeIntEn = FALSE,
        .lpTransConfigPtr = &sdadcLoopConfig,
    };/*PRQA S 0704*/

	switch(instance)
	{
		case SAF_SDADC_INSTANCE_0:
		{
			if((dmaChannel <= 7U))
			{
				sdadc_dma_src = SAF_DMAMUX0_ADC_SD_0_EOC;
			}
			else if((dmaChannel >= 80U)&&(dmaChannel <= 95U))
			{
				sdadc_dma_src = SAF_DMAMUX7_ADC_SD_0_EOC;
			}
			else
			{
				return;
			}

			break;
		}

		case SAF_SDADC_INSTANCE_1:
		{
			if((dmaChannel >= 16U)&&(dmaChannel <= 23U))
			{
				sdadc_dma_src = SAF_DMAMUX2_ADC_SD_1_EOC;
			}
			else if((dmaChannel >= 80U)&&(dmaChannel <= 95U))
			{
				sdadc_dma_src = SAF_DMAMUX7_ADC_SD_1_EOC;
			}
			else
			{
				return;
			}

			break;
		}

		case SAF_SDADC_INSTANCE_2:
		{
			if((dmaChannel >= 16U)&&(dmaChannel <= 23U))
			{
				sdadc_dma_src = SAF_DMAMUX2_ADC_SD_2_EOC;
			}
			else if((dmaChannel >= 32U)&&(dmaChannel <= 47U))
			{
				sdadc_dma_src = SAF_DMAMUX4_ADC_SD_2_EOC;
			}
			else if((dmaChannel >= 80U)&&(dmaChannel <= 95U))
			{
				sdadc_dma_src = SAF_DMAMUX7_ADC_SD_2_EOC;
			}
			else
			{
				return;
			}

			break;
		}

		case SAF_SDADC_INSTANCE_3:
		{
			if((dmaChannel <= 7U))
			{
				sdadc_dma_src = SAF_DMAMUX0_ADC_SD_3_EOC;
			}
			else if((dmaChannel >= 8U)&&(dmaChannel <= 15U))
			{
				sdadc_dma_src = SAF_DMAMUX1_ADC_SD_3_EOC;
			}
			else if((dmaChannel >= 32U)&&(dmaChannel <= 47U))
			{
				sdadc_dma_src = SAF_DMAMUX4_ADC_SD_3_EOC;
			}
			else if((dmaChannel >= 80U)&&(dmaChannel <= 95U))
			{
				sdadc_dma_src = SAF_DMAMUX7_ADC_SD_3_EOC;
			}
			else
			{
				return;
			}

			break;
		}

		case SAF_SDADC_INSTANCE_4:
		{
			if((dmaChannel >= 48U)&&(dmaChannel <= 63U))
			{
				sdadc_dma_src = SAF_DMAMUX5_ADC_SD_4_EOC;
			}
			else if((dmaChannel >= 96U)&&(dmaChannel <= 111U))
			{
				sdadc_dma_src = SAF_DMAMUX8_ADC_SD_4_EOC;
			}
			else
			{
				return;
			}

			break;
		}

		case SAF_SDADC_INSTANCE_6:
		{
			if((dmaChannel >= 64U)&&(dmaChannel <= 79U))
			{
				sdadc_dma_src = SAF_DMAMUX6_ADC_SD_6_EOC;
			}
			else if((dmaChannel >= 80U)&&(dmaChannel <= 95U))
			{
				sdadc_dma_src = SAF_DMAMUX7_ADC_SD_6_EOC;
			}
			else
			{
				return;
			}

			break;
		}

		case SAF_SDADC_INSTANCE_7:
		{
			if((dmaChannel >= 64U)&&(dmaChannel <= 79U))
			{
				sdadc_dma_src = SAF_DMAMUX6_ADC_SD_7_EOC;
			}
			else if((dmaChannel >= 80U)&&(dmaChannel <= 95U))
			{
				sdadc_dma_src = SAF_DMAMUX7_ADC_SD_7_EOC;
			}
			else
			{
				return;
			}

			break;
		}

		case SAF_SDADC_INSTANCE_8:
		{
			if((dmaChannel >= 64U)&&(dmaChannel <= 79U))
			{
				sdadc_dma_src = SAF_DMAMUX6_ADC_SD_8_EOC;
			}
			else if((dmaChannel >= 96U)&&(dmaChannel <= 111U))
			{
				sdadc_dma_src = SAF_DMAMUX8_ADC_SD_8_EOC;
			}
			else
			{
				return;
			}

			break;
		}

		default:/*PRQA S 2024*/
		{
			return;
		}
	}

    (void)SAF_EDMA_LLD_SetChannelSourceConfig(dmaChannel, sdadc_dma_src, FALSE);

    (void)SAF_EDMA_LLD_SetLoopTransferConfig(dmaChannel, &dmaConfigforsdadc);

    if(config.DreqEn == TRUE)
    {
        (void)SAF_EDMA_LLD_SetChnDisRequestsOnTransferComplete(dmaChannel,TRUE);
    }

    (void)SAF_EDMA_LLD_SetChannelRequest(dmaChannel);
}

SAF_ADC_SEC_CODE
status_t SAF_SDADC_LLD_PinInit(const Saf_Sdadc_InstanceType instance, uint8_t ch_default, boolean chWrapEn, uint8_t ch_num, boolean diffEn)
{
    uint8_t chn;
    uint8_t i;
    uint8_t loop_time;
    chn = ch_default;

	if(chWrapEn == TRUE)
	{
	    loop_time = ch_num;
	}
	else
	{
		loop_time = 1U;
	}

    for(i = 0U; i < loop_time; i++)
    {
    	SAF_SDADC_LLD_SetPin(instance, chn, diffEn);/*PRQA S 3200*/

    	switch(instance)
    	{
    		case SAF_SDADC_INSTANCE_0:
    		{
    			if(FALSE == diffEn)
    			{
    				if(chn > 1U)
    				{
    					chn = 0U;
    				}
    				else
    				{
    					chn = 1U;
    				}
    			}
    			else
    			{
    				break;
    			}

    			break;
    		}

    		case SAF_SDADC_INSTANCE_1:
    		{
    			if(FALSE == diffEn)
    			{
    				if(chn > 0U)
    				{
    					chn = 0U;
    				}
    				else
    				{
    					chn++;
    				}
    			}
    			else
    			{
    				break;
    			}

    			break;
    		}

    		case SAF_SDADC_INSTANCE_2:
    		{
    			if(FALSE == diffEn)
    			{
    				if(chn > 2U)
    				{
    					chn = 0U;
    				}
    				else
    				{
    					chn++;
    				}
    			}
    			else
    			{
       				if(chn > 0U)
					{
						chn = 0U;
					}
					else
					{
						chn++;
					}
    			}

    			break;
    		}

    		case SAF_SDADC_INSTANCE_3:
    		{
    			if(FALSE == diffEn)
    			{
    				if(chn > 6U)
    				{
    					chn = 0U;
    				}
    				else
    				{
    					chn++;
    				}
    			}
    			else
    			{
       				if(chn > 2U)
					{
						chn = 0U;
					}
					else
					{
						chn++;
					}
    			}

    			break;
    		}

    		case SAF_SDADC_INSTANCE_4:
    		{
    			if(FALSE == diffEn)
    			{
    				if(chn > 2U)
    				{
    					chn = 0U;
    				}
    				else
    				{
    					chn++;
    				}
    			}
    			else
    			{
       				if(chn > 0U)
					{
						chn = 0U;
					}
					else
					{
						chn++;
					}
    			}

    			break;
    		}

    		case SAF_SDADC_INSTANCE_6:
    		{
    			if(FALSE == diffEn)
    			{
    				if(chn > 2U)
    				{
    					chn = 0U;
    				}
    				else
    				{
    					chn++;
    				}
    			}
    			else
    			{
       				if(chn > 0U)
					{
						chn = 0U;
					}
					else
					{
						chn++;
					}
    			}

    			break;
    		}

    		case SAF_SDADC_INSTANCE_7:
    		{
    			if(FALSE == diffEn)
    			{
    				if(chn > 2U)
    				{
    					chn = 0U;
    				}
    				else
    				{
    					chn++;
    				}
    			}
    			else
    			{
       				if(chn > 0U)
					{
						chn = 0U;
					}
					else
					{
						chn++;
					}
    			}

    			break;
    		}

    		case SAF_SDADC_INSTANCE_8:
    		{
    			if(FALSE == diffEn)
    			{
    				if(chn > 2U)
    				{
    					chn = 0U;
    				}
    				else
    				{
    					chn++;
    				}
    			}
    			else
    			{
       				if(chn > 0U)
					{
						chn = 0U;
					}
					else
					{
						chn++;
					}
    			}

    			break;
    		}

    		default:/*PRQA S 2024*/
    		{
    			return STATUS_ERROR;
    		}
    	}
    }

	return STATUS_SUCCESS;
}

SAF_ADC_SEC_CODE
uint32_t SAF_SDADC_LLD_GetRecentAccumulation(const Saf_Sdadc_InstanceType instance)
{
    DEV_ASSERT(((uint8_t)instance < ADC_SAF_SDADC_MAX_INSTANCE) && ((uint8_t)instance != 5U));
    Saf_Sdadc_InstanceType instance_l = instance;

    SAF_SDADC_TagType * const BasePtr = Adc_SdadcBase[(uint8_t)instance_l];

    return SAF_SDADC_IIVAL_GetInterIntegrationVal(BasePtr);
}

SAF_ADC_SEC_CODE
boolean SAF_SDADC_LLD_GetIntegrationEnable(const Saf_Sdadc_InstanceType instance)
{
    DEV_ASSERT(((uint8_t)instance < ADC_SAF_SDADC_MAX_INSTANCE) && ((uint8_t)instance != 5U));
    Saf_Sdadc_InstanceType instance_l = instance;

    SAF_SDADC_TagType * const BasePtr = Adc_SdadcBase[(uint8_t)instance_l];

    return SAF_SDADC_ISTAT_GetIntegrationEn(BasePtr);
}
#endif /* SAF_ADC_SDADC_SUPPORTED */
