/**
****************************************************************************************
 * @FilePath: saf_cmu.c
 * @Author: CCORE
 * @Date: 2024-03-05
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: Safety Cmu C Source File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "mcu_lld.h"/*PRQA S 0380*/
#include "saf_cpu.h"
#include "saf_fccu.h"
#include "saf_cmu.h"
#include "Mcu_LLDriver.h"
#include "Saf_MemMap.h"
/*PRQA S 0315,0491,0492,0686,0704 EOF*/
/*PRQA S 1258,1281,1514,1840,1842,1862,1881 EOF*/
/*PRQA S 2052,2844,2934 EOF*/
/*PRQA S 3200,3218,3344,3408 EOF*/
/*PRQA S 4304,4322,4404,4461 EOF*/
/**
****************************************************************************************
 * @brief: Local Variables
****************************************************************************************
*/
SAF_CMU_SEC_VAR_INIT
static CMU_Type *s_pCmuRegList[SAF_CMU_MAX_INSTANCE] = SAF_CMU_BASE_PTRS;

SAF_CMU_SEC_VAR_INIT
static saf_cmu_mgr_monitor_t s_cmuMgr =
{
    .freqMonitorObjList =
    {
        .monitorObj = {{0}},
    }
};

SAF_CMU_SEC_VAR_INIT
static saf_cmu_monitor_test_t s_cmuMonitorTest =
{
    .output =
    {
        .monitorInstance =
        {
            {
                .freqOverHigh = 0,
                .freqOverLow = 0,
                .oscFreqOverLow = 0,
            },
        },
    },
};

SAF_CMU_SEC_VAR_INIT
static saf_cmu_config_check_test_t s_cmuCfgCheckTest =
{
    .output =
    {
        .cfgCheckPassedBitmap = 0xFFFFFFFF,
    },
};

SAF_CMU_SEC_VAR_NO_INIT
fccu_rf_config_t realCmuFccuRfCfg[SAF_FCCU_RF_MAX_SIZE];

SAF_CMU_SEC_VAR_INIT
fccu_rf_config_t fccCmuStartUpRfCfg[] = {
    {
        /* FCCU Channel ID */
        .channel        = (uint8_t)SAF_FCCU_FAILURE_CMU_0_OSC_CH_31,
        /* FCCU recoverable fault definitions */
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        /* FCCU recoverable fault state definitions */
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_NO_RESET,
        /* Fault time-out enable */
        .timeout_alarm_enable = (bool)true,
        /* FCCU recoverable faults reaction type definitions */
        .reaction = {
            /* IRQ alarm switch */
            .irq_alarm_en = (bool)true,
            /* NMI switch */
            .nmi_en       = (bool)false,
            /* EOUT signal switch */
            .eout_sig_en  = (bool)false,
        },
        /* Alarm notification function */
        .callback       = NULL_PTR,
        /* The parameters of the alarm notification function */
        .callbackParam  = NULL_PTR
    },

    {
        /* FCCU Channel ID */
        .channel        = (uint8_t)SAF_FCCU_FAILURE_CMU_0_PLL_CH_32,
        /* FCCU recoverable fault definitions */
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        /* FCCU recoverable fault state definitions */
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_NO_RESET,
        /* Fault time-out enable */
        .timeout_alarm_enable = (bool)true,
        /* FCCU recoverable faults reaction type definitions */
        .reaction = {
            /* IRQ alarm switch */
            .irq_alarm_en = (bool)true,
            /* NMI switch */
            .nmi_en       = (bool)false,
            /* EOUT signal switch */
            .eout_sig_en  = (bool)false,
        },
        /* Alarm notification function */
        .callback       = NULL_PTR,
        /* The parameters of the alarm notification function */
        .callbackParam  = NULL_PTR
    },

    {
        /* FCCU Channel ID */
        .channel        = (uint8_t)SAF_FCCU_FAILURE_CMU_COMP_SUBSYS_CH_33,
        /* FCCU recoverable fault definitions */
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        /* FCCU recoverable fault state definitions */
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_NO_RESET,
        /* Fault time-out enable */
        .timeout_alarm_enable = (bool)true,
        /* FCCU recoverable faults reaction type definitions */
        .reaction = {
            /* IRQ alarm switch */
            .irq_alarm_en = (bool)true,
            /* NMI switch */
            .nmi_en       = (bool)false,
            /* EOUT signal switch */
            .eout_sig_en  = (bool)false,
        },
        /* Alarm notification function */
        .callback       = NULL_PTR,
        /* The parameters of the alarm notification function */
        .callbackParam  = NULL_PTR
    },

    {
        /* FCCU Channel ID */
        .channel        = (uint8_t)SAF_FCCU_FAILURE_CMU_OTHER_CH_34,
        /* FCCU recoverable fault definitions */
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        /* FCCU recoverable fault state definitions */
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_NO_RESET,
        /* Fault time-out enable */
        .timeout_alarm_enable = (bool)true,
        /* FCCU recoverable faults reaction type definitions */
        .reaction = {
            /* IRQ alarm switch */
            .irq_alarm_en = (bool)true,
            /* NMI switch */
            .nmi_en       = (bool)false,
            /* EOUT signal switch */
            .eout_sig_en  = (bool)false,
        },
        /* Alarm notification function */
        .callback       = NULL_PTR,
        /* The parameters of the alarm notification function */
        .callbackParam  = NULL_PTR
    },
};

/* FCCU module configuration */
SAF_CMU_SEC_VAR_INIT
fccu_config_t fccuCmuStartUpCfg=
{
    /* Filter bypss */
    .filter_bypass_enable = (bool)false,
    /* Filter width */
    .filter_width         = 0,
    /* Debug mode entry */
    .debug_enable         = (bool)false,
    /* FCCU EOUT configurations */
    .eout_config          = {
                            /* EOUT signal activation flag */
                            .set_after_reset = (bool)false,
                            /* EOUT control definitions */
                            .control         = (SAF_fccu_ep_control_t)SAF_FCCU_EP_INDEPENDENT_ABOVE_SW,
                            /* FCCU EOUT output definitions */
                            .output          = (SAF_fccu_ep_output_t)SAF_FCCU_EP_OUTPUT_OPEN_DRAIN,
                            /* FCCU EOUT protocol definitions */
                            .switch_mode     = (SAF_fccu_eout_sm_t)SAF_FCCU_EOUT_PROTOCOL_SLOW_SM,
                            /* FCCU EOUT polar select definitions */
                            .polarity_sel    = (SAF_fccu_eout_ps_t)SAF_FCCU_EOUT_0_LOW_1_HIGH,
                            /* Fault Output Mode selection */
                            .mode            = (SAF_fccu_eout_fom_t)SAF_FCCU_FOM_DUAL_RAIL,
                            /* Pin is set to the minimum time of failure state */
                            .delta_t_value   = 0U,
                            },
    /* Configuration time-out interrupt enabled */
    .irq_type             = (SAF_fccu_irq_type_t)SAF_FCCU_IRQ_NONE,
    /* The preset value of the watchdog timer for the recovery from the CONFIG state. */
    .cfg_timeout          = 0,
    /* FCCU lock type definitions */
    .lock_type            = (SAF_fccu_lock_type_t)SAF_FCCU_TRANSIENTLY_UNLOCK,
    /* The number of configured FCCU channels */
    .rfConfigNumber       = (uint8_t)(sizeof(fccCmuStartUpRfCfg)/sizeof(fccCmuStartUpRfCfg[0])),
    /* time-out notification function */
    .callbackFunc         = NULL_PTR,
    /* The parameters of the time-out notification function */
    .callbackParam        = NULL_PTR
};

/**
****************************************************************************************
 * @brief: Gloabl Variables
****************************************************************************************
*/
extern bool SAF_b_cmu_start;

/**
****************************************************************************************
 * @brief: Local Functions
****************************************************************************************
*/

/**
****************************************************************************************
* @brief: This function set value to CMU_CSR SEL1 bit.
* @param[in] pBase:  Cmu base address  value:CMU_CSR SEL1 bit value
* @return
****************************************************************************************
*/
SAF_CMU_SEC_CODE
static void SAF_CMU_AccessSetClkSel1(CMU_Type *pBase, const uint32_t value)
{
    uint32_t regValue;

    regValue = pBase->CSR.R;
    regValue &= (uint32_t)(~(CMU_CSR_CKSEL1_MASK));/*PRQA S 4399*/
    regValue |= CMU_CSR_CKSEL1(value);
    pBase->CSR.R = regValue;

    READ_AFTER_WRITE_ASSERT(pBase->CSR.R, regValue);
}

/**
****************************************************************************************
* @brief: This function set value to CMU_MDR MD bit.
* @param[in] pBase:  Cmu base address  value:CMU_MDR MD bit value
* @return
****************************************************************************************
*/
SAF_CMU_SEC_CODE
static void SAF_CMU_AccessSetMeasureDuration(CMU_Type *pBase, const uint32_t value)
{
    uint32_t regValue = pBase->MDR.R; /* polyspace RTE:NIV */

    regValue &= (uint32_t)(~(CMU_MDR_MD_MASK));
    regValue |= CMU_MDR_MD(value);/*PRQA S 2985*/
    pBase->MDR.R = regValue;

    READ_AFTER_WRITE_ASSERT(pBase->MDR.R, regValue);
}

/**
****************************************************************************************
* @brief: This function enable/disable IROSC frequency measure.
* @param[in] pBase:  Cmu base address  enable:Enable/Disable IROSC frequency measure.
* @return
****************************************************************************************
*/
SAF_CMU_SEC_CODE
static void SAF_CMU_AccessStartFreqMeasure(CMU_Type *pBase, const bool enable)
{
    uint32_t regValue = pBase->CSR.R; /* polyspace RTE:NIV */

    regValue &= (uint32_t)(~(CMU_CSR_SFM_MASK));
    regValue |= CMU_CSR_SFM(enable ? 1UL:0UL);/*PRQA S 2985,4559*/
    pBase->CSR.R = regValue;

    READ_AFTER_WRITE_ASSERT(pBase->CSR.R, regValue);
}

/**
****************************************************************************************
* @brief: This function get cmu measured SFM value.
* @param[in] pBase:  Cmu base address
* @return
****************************************************************************************
*/
SAF_CMU_SEC_CODE
static uint32_t SAF_CMU_AccessGetSfmValue(const CMU_Type *pBase)
{
    uint32_t regValue = ((pBase->CSR.R) & ((uint32_t)(CMU_CSR_SFM_MASK))) >> CMU_CSR_SFM_SHIFT; /* polyspace RTE:NIV */

    return regValue;
}

/**
****************************************************************************************
* @brief: This function get cmu measured FD value.
* @param[in] pBase:  Cmu base address
* @return
****************************************************************************************
*/
SAF_CMU_SEC_CODE
static uint32_t SAF_CMU_AccessGetFDValue(const CMU_Type *pBase)
{
    uint32_t regValue = ((pBase->FDR.R) & ((uint32_t)(CMU_FDR_FD_MASK))) >> CMU_FDR_FD_SHIFT; /* polyspace RTE:NIV */

    return regValue;
}

/**
****************************************************************************************
* @brief: This function get cmu high configuration frequencye.
* @param[in] pBase:  Cmu base address
* @return
****************************************************************************************
*/
SAF_CMU_SEC_CODE
static uint32_t SAF_CMU_AccessGetHighFreqReg(const CMU_Type *pBase)
{
    uint32_t regValue = ((pBase->HFREFR.R) & ((uint32_t)(CMU_HFREFR_HFREF_MASK))) >> CMU_HFREFR_HFREF_SHIFT; /* polyspace RTE:NIV */

    return regValue;
}

/**
****************************************************************************************
* @brief: This function get low high configuration frequencye.
* @param[in] pBase:  Cmu base address
* @return
****************************************************************************************
*/
SAF_CMU_SEC_CODE
static uint32_t SAF_CMU_AccessGetLowFreqReg(const CMU_Type *pBase)
{
    uint32_t regValue = ((pBase->LFREFR.R) & ((uint32_t)(CMU_LFREFR_LFREF_MASK))) >> CMU_LFREFR_LFREF_SHIFT; /* polyspace RTE:NIV */

    return regValue;
}

/**
****************************************************************************************
* @brief: This function get cmu manager monitor data.
* @param[in] cmuInst:  Cmu instance number.
* @return
*
****************************************************************************************
*/
SAF_CMU_SEC_CODE
static void SAF_CMU_AccessGetMonitorData(const uint8_t cmuInst, saf_cmu_freq_fault_type_t *pFreqMonitor)
{
    saf_cmu_freq_fault_type_t *pCmuMgr = &s_cmuMgr.freqMonitorObjList.monitorObj[cmuInst];

    pFreqMonitor->freqOverHigh   = pCmuMgr->freqOverHigh;
    pFreqMonitor->freqOverLow    = pCmuMgr->freqOverLow;
    pFreqMonitor->oscFreqOverLow = pCmuMgr->oscFreqOverLow;

}

/**
****************************************************************************************
* @brief: This function clean cmu manager monitor data.
* @param[in] cmuInst:  Cmu instance number.
* @return
*
****************************************************************************************
*/
SAF_CMU_SEC_CODE
static void SAF_CMU_AccessResetMonitorData(const uint8_t cmuInst)
{
    saf_cmu_freq_fault_type_t *pCmuMgr = &s_cmuMgr.freqMonitorObjList.monitorObj[cmuInst];

    pCmuMgr->oscFreqOverLow = SAF_CMU_FREQ_TEST_SUCCESS;
    pCmuMgr->freqOverHigh   = SAF_CMU_FREQ_TEST_SUCCESS;
    pCmuMgr->freqOverLow    = SAF_CMU_FREQ_TEST_SUCCESS;
}

/**
****************************************************************************************
* @brief: This function clean the FCCU errors for CMU.
* @param[in] cmuInst:  Cmu instance number. errorType:CMU monitor fault type.
* @return
*
****************************************************************************************
*/
SAF_CMU_SEC_CODE
static void SAF_CMU_AccessCleanFccuStatus( const uint8_t cmuInst, saf_cmu_freq_fault_type_t errorType)
{
    uint8_t faultIndex = 0;

    if (SAF_CMU_FREQ_TEST_SUCCESS != errorType.oscFreqOverLow)
    {
        faultIndex = SAF_CMU_FCCU_RF_INDEX_CMU_OLR;
    }
    else if (SAF_CMU_PLL_CLK_INSTANCE == cmuInst)
    {
        faultIndex = SAF_CMU_FCCU_RF_INDEX_CMU_PLL;
    }
    else if ((SAF_CMU_Z7_CLK_INSTANCE == cmuInst) || (SAF_CMU_SYS_CLK_MAX_INSTANCE >= cmuInst))
    {
        faultIndex = SAF_CMU_FCCU_RF_INDEX_CMU_COMP;
    }
    else
    {
        faultIndex = SAF_CMU_FCCU_RF_INDEX_CMU_OTHER;
    }

    SAF_FCCU_RestoreFault(faultIndex);
}


/*******************************************************************************
 * Public Functions
 ******************************************************************************/
/**
****************************************************************************************
* @brief: This function expression that CMU can be started.
* @return void
****************************************************************************************
*/
SAF_CMU_SEC_CODE
void SAF_CMU_Start(void)
{
    SAF_b_cmu_start = true;
}

/**
****************************************************************************************
* @brief: This function check and update cmu interrupt status.
* @param[in] cmuInst:  Cmu instance number.
* @return
*
****************************************************************************************
*/
SAF_CMU_SEC_CODE
void SAF_CMU_GetAndCleanIrqStatus(const uint32_t cmuInst)
{    
    CMU_Type *pBase = s_pCmuRegList[cmuInst];
    saf_cmu_freq_fault_type_t *pMonitor = &s_cmuMgr.freqMonitorObjList.monitorObj[0];
    uint32_t irqStatus = 0;

    pBase = s_pCmuRegList[cmuInst];
    if (NULL != pBase)
    {
    	irqStatus = SAF_CMU_LLD_GetStatus(pBase);

        if (0u < irqStatus)
        {
            SAF_CMU_AccessResetMonitorData(cmuInst);

            if (CMU_ISR_FLLI_MASK == (irqStatus & CMU_ISR_FLLI_MASK))
            {
                pMonitor[cmuInst].freqOverLow = SAF_CMU_FREQ_TEST_ERROR;
            }
            if (CMU_ISR_FHHI_MASK == (irqStatus & CMU_ISR_FHHI_MASK))
            {
                pMonitor[cmuInst].freqOverHigh = SAF_CMU_FREQ_TEST_ERROR;
            }
            if(cmuInst==0)/*PRQA S 1843*/
            {
            	if (CMU_ISR_OLRI_MASK == (irqStatus & CMU_ISR_OLRI_MASK))
            	{
            		pMonitor[cmuInst].oscFreqOverLow = SAF_CMU_FREQ_TEST_ERROR;
            	}
            }
            SAF_CMU_LLD_CleanStatusRegister(pBase);
        }
     }
}


/**
****************************************************************************************
* @brief: This function check cmu is enabled.
* @param[in] pBase:  Cmu base address.
* @return
*
****************************************************************************************
*/
SAF_CMU_SEC_CODE
bool SAF_CMU_IsEnabled(const CMU_Type *pBase)
{
	bool regValue = (bool)(pBase->CSR.R & CMU_CSR_CME(1)) ? (bool)true : (bool)false;/*PRQA S 1259,2813,4559*/ /* polyspace RTE:NIV */
    return regValue;
}

/**
****************************************************************************************
* @brief: This function measure IROSC frequency by cmu.
* @param[out] pFreq:  Cmu measure Freqency.
* @return
*
****************************************************************************************
*/
#ifdef __ghs__
#pragma ghs ZO
#endif
SAF_CMU_SEC_CODE
FS_STATUS SAF_CMU_IrcoscFreqMeasure(uint32_t *pFreq)
{
    uint64_t ircoscFreq;
    FS_STATUS status = FS_STATUS_SUCCESS;
    CMU_Type *pBase = (CMU_Type *)SAF_CMU_MEASURE_IRCOSC_CMU_BASE_ADDR;
    uint32_t mdValue = SAF_CMU_MEASURE_IRCOSC_MD_VALUE, fdValue = 0;
    uint32_t timeoutCycle = 0, oscFreq = 0;
    /* 1. configure clock select & measurement duration */
    SAF_CMU_AccessSetClkSel1(pBase, SAF_CMU_CLK_SELECT_IRCOSC);
    SAF_CMU_AccessSetMeasureDuration(pBase, mdValue);

    /* 2. start measure */
    SAF_CMU_AccessStartFreqMeasure(pBase, (bool)true);

    while(SAF_CMU_MEASURE_IRCOSC_COMPLETE == SAF_CMU_AccessGetSfmValue(pBase)&&(timeoutCycle != SAF_CMU_IRCOSC_MEASURE_TIMEOUT_CYCLE))/*PRQA S 3400,3401,3397,2961*/
    {
    	timeoutCycle++;/*PRQA S 2985,2961*/
    }

    if (timeoutCycle == SAF_CMU_IRCOSC_MEASURE_TIMEOUT_CYCLE )/*PRQA S 2963*/
    {
        status = FS_STATUS_TIMEOUT;
    }

    /* 4. calculate IRCOSC frequency */
    if(FS_STATUS_SUCCESS == status)
    {
    	SAF_MCU_LLD_CalculateFrequenciesOfClockSources(0U);
        if (STATUS_SUCCESS != SAF_CLOCK_GetClockSourceFreq(SAF_XOSC_CLK, &oscFreq))
        {
            status = FS_STATUS_ERROR;
        }
        else
        {
            fdValue = SAF_CMU_AccessGetFDValue(pBase);
            ircoscFreq = ((uint64_t)oscFreq * (uint64_t)mdValue)/(uint64_t)fdValue; /*PRQA S 2834*/ /* polyspace RTE:ZDV */
            *pFreq = (uint32_t )ircoscFreq;
        }
    }
    
    return status;
}
#ifdef __ghs__
#pragma ghs OS
#endif
/**
****************************************************************************************
* @brief: This function enable specially CMU module.
* @param[in] cmuInst:  Cmu instance. enable:Disable/Enable cmu.
* @return FS_STATUS: FS_STATUS_ERROR  :Disable cmu error.
*                    FS_STATUS_SUCESS :Disable cmu success.
****************************************************************************************
*/
SAF_CMU_SEC_CODE
FS_STATUS SAF_CMU_Enable(const uint8_t cmuInst, const bool enable)
{ 
    FS_STATUS status = FS_STATUS_ERROR;
    CMU_Type *pBase = NULL;

    if (cmuInst < SAF_CMU_MAX_INSTANCE)
    {
        pBase = s_pCmuRegList[cmuInst];
        if (NULL != pBase)
        {
        	SAF_CMU_LLD_EnableCMU(pBase, enable);
            status = FS_STATUS_SUCCESS;
        }
    }
    
    return status;
}

/**
****************************************************************************************
* @brief: This function initialize cmu manager.
* @param[in] pCmuConfigArr: cmu configure structure  cmuCount: Cmu number.
* @return FS_STATUS: FS_STATUS_ERROR  :Init cmu error.
*                    FS_STATUS_SUCESS :Init cmu success.
****************************************************************************************
*/
SAF_CMU_SEC_CODE
FS_STATUS SAF_CMU_Init(const saf_cmu_monitor_configure_t *pCmuConfigArr, const uint8_t cmuCount)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_cmu_mgr_monitor_t *pCmuMgr = &s_cmuMgr;
    CMU_Type *pBase = NULL;
    uint32_t  clkmt0RmnFreq;
    uint64_t hfref, lfref;
    uint8_t i, cmuInst;
	SAF_MCU_LLD_CalculateFrequenciesOfClockSources(0U);
    if ((STATUS_SUCCESS != SAF_CLOCK_GetClockSourceFreq(SAF_IRCOSC_CLK, &clkmt0RmnFreq)) || (true != SAF_b_cmu_start) || NULL == pCmuConfigArr)/*PRQA S 3400,3397,3401,3390*/
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
        for (i = 0; i < cmuCount; i++)
        {
            cmuInst = pCmuConfigArr[i].cmuInst;/*PRQA S 0492*/
            if (cmuInst == 7 || cmuInst == 8 || cmuInst == 9 || cmuInst == 10) {
                continue;
            }
            if (SAF_CMU_MAX_INSTANCE <= cmuInst)
            {
                status = FS_STATUS_ERROR;
                break;
            }
            pBase = s_pCmuRegList[cmuInst];
            if (NULL != pBase)
            {
            	if (pCmuConfigArr[i].errRatio != 100U)
            	{
					/* 1. configure CMU monitor */
					pCmuMgr->overHighFreq[cmuInst] = (uint64_t)pCmuConfigArr[i].frequency * SAF_CMU_FULL_RANGE / (SAF_CMU_FULL_RANGE - (uint64_t)pCmuConfigArr[i].errRatio);/*PRQA S 4461,3393,2834,0492,3401*/
					pCmuMgr->overLowFreq[cmuInst]  = (uint64_t)pCmuConfigArr[i].frequency * SAF_CMU_FULL_RANGE / (SAF_CMU_FULL_RANGE + (uint64_t)pCmuConfigArr[i].errRatio);/*PRQA S 4461,3393,2834,0492,3401*/
                    #if defined(CCFC3012PT)
					if (SAF_CMU_INS0 == cmuInst)
					{
						pCmuMgr->overHighFreq[cmuInst] >>= SAF_CMU_DIV_BY4_SHIFT;
						pCmuMgr->overLowFreq[cmuInst] >>= SAF_CMU_DIV_BY4_SHIFT;
					}
					#endif
					hfref = ((double)pCmuMgr->overHighFreq[cmuInst] * SAF_CMU_FREF_COEFF + clkmt0RmnFreq - 1) / clkmt0RmnFreq;/*PRQA S 4454,3393,3395,1800,3401*/ /* polyspace RTE:ZDV */
					lfref = (double)pCmuMgr->overLowFreq[cmuInst] / clkmt0RmnFreq * SAF_CMU_FREF_COEFF;/*PRQA S 4454,3393,1800,3401*/

					if(SAF_CMU_HFREF_MAX < hfref)
	                {
	                    status = FS_STATUS_ERROR;
	                }
	                else
	                {
	                    SAF_CMU_LLD_SetLowFreq(pBase, lfref);
	                    SAF_CMU_LLD_SetHighFreq(pBase, hfref);
	                }
					/* 2. clean ISR */
					SAF_CMU_LLD_CleanStatusRegister(pBase);

					/* 3. enable CMU */
					SAF_CMU_LLD_EnableCMU(pBase, (bool)true);
            	}
            	else
            	{
            		status = FS_STATUS_ERROR;
            	}
            }
        }
    }
    
    return status;
}

/**
****************************************************************************************
* @brief: This function Deinit CMU manager.
* @param[in]
* @return
*         FS_STATUS_ERROR: Cmu deinit error.
*         FS_STATUS_SUCCESS:Cmu deinit success.
****************************************************************************************
*/
SAF_CMU_SEC_CODE
FS_STATUS SAF_CMU_Deinit(void)
{
    CMU_Type *pBase = NULL;
    uint32_t i;
    FS_STATUS status = FS_STATUS_SUCCESS;

    for (i = 0; i < SAF_CMU_MAX_INSTANCE; i++)
    {
        pBase = s_pCmuRegList[i];
        if (NULL != pBase)
        {
        	SAF_CMU_LLD_EnableCMU(pBase, (bool)false);
        }
        if (SAF_CMU_IsEnabled(pBase) != false)
        {
        	status = FS_STATUS_ERROR;
        }
    }
    return status;
}

/**
****************************************************************************************
* @brief: This function program cmu monitor test.
* @param[out]pTestResult:the pointer of test result
* @return FS_STATUS:FS_STATUS_ERROR: Cmu monitor test error.
*                   FS_STATUS_SUCCESS:Cmu monitor test success.
****************************************************************************************
*/
SAF_CMU_SEC_CODE
FS_STATUS SAF_CMU_MonitorTest(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_cmu_monitor_test_result_t *pResult = &s_cmuMonitorTest.output;
    uint32_t i;

    for (i = 0; i < SAF_CMU_MAX_INSTANCE; i++)
    {
        if (i == 7 || i == 8 || i == 9 || i == 10) {
            continue;
        }
        /*CCFC30XX get and clean status by hand*/
        SAF_CMU_GetAndCleanIrqStatus(i);
        /* clear all bitmap */
        pResult->monitorInstance[i].freqOverHigh  = SAF_CMU_FREQ_TEST_SUCCESS;
        pResult->monitorInstance[i].freqOverLow   = SAF_CMU_FREQ_TEST_SUCCESS;
        pResult->monitorInstance[i].oscFreqOverLow= SAF_CMU_FREQ_TEST_SUCCESS;

        SAF_CMU_AccessGetMonitorData((uint8_t)i, &pResult->monitorInstance[i]);
        SAF_CMU_AccessResetMonitorData((uint8_t)i);
        if ((SAF_CMU_FREQ_TEST_SUCCESS != pResult->monitorInstance[i].freqOverHigh) || \
            (SAF_CMU_FREQ_TEST_SUCCESS != pResult->monitorInstance[i].freqOverLow) || \
            (SAF_CMU_FREQ_TEST_SUCCESS != pResult->monitorInstance[i].oscFreqOverLow))
        {

        	SAF_CMU_AccessCleanFccuStatus((uint8_t)i, pResult->monitorInstance[i]);

        	status = FS_STATUS_ERROR;
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief: This function get CMU monitor test result.
* @param[out] pTestResult:the pointer of test result
* @return FS_STATUS:FS_STATUS_ERROR: get monitor test result error.
*                   FS_STATUS_SUCCESS:get monitor test result success.
****************************************************************************************
*/
SAF_CMU_SEC_CODE
FS_STATUS SAF_CMU_MonitorTestResult(saf_cmu_monitor_test_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (NULL != pTestResult)
    {
        status = FS_STATUS_SUCCESS;
        (void)memcpy(pTestResult, &s_cmuMonitorTest, sizeof(s_cmuMonitorTest));
    }

    return status;
}

/**
****************************************************************************************
* @brief: This function configuration check test.
* @param[out] pTestResult:the pointer of test result.
* @return FS_STATUS:FS_STATUS_ERROR: Cmu configuration check test error.
*                   FS_STATUS_SUCCESS:Cmu configuration check test success.
****************************************************************************************
*/
SAF_CMU_SEC_CODE
FS_STATUS SAF_CMU_ConfigCheckTest(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    FS_STATUS cmuFccuStatus = FS_STATUS_SUCCESS;
    CMU_Type *pBase = NULL;
    saf_cmu_config_check_test_result_t *pResult = &s_cmuCfgCheckTest.output;
    uint8_t cmuFccuIndexList[] = SAF_CMU_FCCU_INDEX_LIST;/*PRQA S 3604*/
    uint32_t highReg, lowReg;
    uint32_t i;

    SAF_FCCU_CopyUninitChannelConfig(&fccuCmuStartUpCfg, realCmuFccuRfCfg, fccCmuStartUpRfCfg, SAF_CMU_FCCU_RF_INDEX_CMU_OLR, 4);

    /* check fccu status */
    if (fccuCmuStartUpCfg.rfConfigNumber > 0)
    {
    	SAF_FCCU_ClearAllChannelFault();
    	cmuFccuStatus = SAF_FCCU_HardwareInit(&fccuCmuStartUpCfg, realCmuFccuRfCfg);
    }
    if (cmuFccuStatus != FS_STATUS_SUCCESS)
    {
    	status = FS_STATUS_ERROR;
    }


    for (i = 0; i < SAF_CMU_MAX_INSTANCE; i++)
    {
        if (i == 7 || i == 8 || i == 9 || i == 10) {
            continue;
        }

        pBase = s_pCmuRegList[i];
        if (NULL != pBase)
        {
            lowReg  = SAF_CMU_AccessGetLowFreqReg(pBase);
            highReg = SAF_CMU_AccessGetHighFreqReg(pBase);

            if ((lowReg > highReg) || !SAF_CMU_IsEnabled(pBase))/*PRQA S 3399,4116,4558*/
            {
                pResult->cfgCheckPassedBitmap &= ~((uint32_t)0x1 << i);/*PRQA S 1259*/
                status = FS_STATUS_ERROR;
            }
            /*  CMU_0 with two FCCU index, other is one*/
            if (SAF_CMU_PLL_CLK_INSTANCE == i)/*PRQA S 1843*/
            {
                if (!SAF_FCCU_RfIsConfigured(SAF_CMU_FCCU_RF_INDEX_CMU_OLR))/*PRQA S 4116,4558*/
                {
                    pResult->cfgCheckPassedBitmap &= ~((uint32_t)0x1 << i);/*PRQA S 1259,2984*/
                    status = FS_STATUS_ERROR;
                }
            }
            if (!SAF_FCCU_RfIsConfigured(cmuFccuIndexList[i]))/*PRQA S 4116,4558*/
            {
                pResult->cfgCheckPassedBitmap &= ~((uint32_t)0x1 << i);/*PRQA S 1259*/
                status = FS_STATUS_ERROR;
            }
        }
        else
        {
            pResult->cfgCheckPassedBitmap &= ~(0x1u << i);/*PRQA S 1891,4397*/
            status = FS_STATUS_ERROR;
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief: This function configuration check test.
* @param[out] pTestResult:the pointer of test result.
* @return FS_STATUS:FS_STATUS_ERROR: Get cmu configuration check test error.
*                   FS_STATUS_SUCCESS:Get cmu configuration check test success.
****************************************************************************************
*/
SAF_CMU_SEC_CODE
FS_STATUS SAF_CMU_ConfigCheckTestResult(saf_cmu_config_check_test_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (NULL != pTestResult)
    {
        status = FS_STATUS_SUCCESS;
        (void)memcpy(pTestResult, &s_cmuCfgCheckTest, sizeof(s_cmuCfgCheckTest));
    }

    return status;
}

