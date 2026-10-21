/**
****************************************************************************************
 * @FilePath: saf_fccu.c
 * @Author: CCORE
 * @Date: 2024-02-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: FCCU Source File
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
#include "saf_cpu.h"/*PRQA S 0380*/
#include "saf_fccu.h"
#include "saf_core.h"
#include "mcu_lld.h"
#include "saf_ccfc30xx.h"
#include "SafetyFccuTst_Cfg.h"
#include "SafetyMemTst_Cfg.h"
#include "intc_lld.h"
#include "Saf_MemMap.h"
#include "memu_lld.h"
/*PRQA S 0492,0686 EOF*/
/*PRQA S 1441,1881,1841,1891 EOF*/
/*PRQA S 2462,2463,2844 EOF*/
/*PRQA S 3200,3218,3344,3397,3408,3400,3401,3418,3604 EOF*/
/*PRQA S 4115,4116,4304,4322,4332,4342,4397,4404,4461,4542,4558 EOF*/
/**
****************************************************************************************
 * @brief: Global Variable
****************************************************************************************
*/
extern const fccu_config_t fccuCfg;
extern const fccu_rf_config_t fccRfCfg[];/*PRQA S 3684*/
SAF_FCCU_SEC_VAR_NO_INIT
fccu_config_t realfccuCfg;
SAF_FCCU_SEC_VAR_NO_INIT
fccu_rf_config_t realFccuRfCfg[SAF_FCCU_RF_MAX_SIZE];

/**
****************************************************************************************
 * @brief: Local Variables
****************************************************************************************
*/
SAF_FCCU_SEC_VAR_INIT
static uint8_t funcSoftResetFlag = 0;

SAF_FCCU_SEC_VAR_INIT
saf_fccu_rf_test_t s_fccuRfTest =
{
	.testRfCnt  = SAF_FCCU_RF_FAULT_ID_INDEX_COUNT,
	.faultIDList= SAF_FCCU_ALL_RF_FAULT_INDEX_LIST,
};

SAF_FCCU_SEC_VAR_INIT
static saf_fccu_rf_test_result_t pTestResult=
{
	.rfFailureBitmap[0] = 0,/*PRQA S 0691*/
};

SAF_FCCU_SEC_VAR_INIT
static fccu_rf_config_t sfccRfCfg[1] = {
    {
        .channel        = (uint8_t)SAF_FCCU_FAILURE_STCU_UF_CH_6,
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_NO_RESET,
        .timeout_alarm_enable = false,
        .reaction = {
            .irq_alarm_en = false,
            .nmi_en       = false,
            .eout_sig_en  = true,
        },
        .callback       = NULL_PTR,
        .callbackParam  = NULL_PTR
    },
};


/**
****************************************************************************************
 * @brief: Local Function Prototypes
****************************************************************************************
*/
static bool SAF_FCCU_AccessRfIsInjectable(const uint8_t faultIdx);

static void SAF_FCCU_AccessSetRfTestFailureBitmap(const uint32_t faultIdx, saf_fccu_rf_test_result_t *pResult);

static bool SAF_FCCU_AccessGetRfCfgStatus(const FCCU_Type * const base, const uint8_t faultIdx);

static FS_STATUS SAF_FCCU_AccessCheckerResetAndCore(void);

/**
****************************************************************************************
 * @brief: Local Functions
****************************************************************************************
*/
/**
****************************************************************************************
* @brief: [SW_SM024] This function detects if the appointed RF can be injected.
* @param[in] faultIdx  FCCU RF channel ID
* @return bool
            true:  The current channel ID can be used for injection testing.
            false: The current channel ID cannot be used for injection testing.
****************************************************************************************
*/
SAF_FCCU_SEC_CODE
static bool SAF_FCCU_AccessRfIsInjectable(const uint8_t faultIdx)
{
    uint8_t pReservedUsedRfList[] = SAF_FCCU_RF_TEST_RESERVED_FAULT_INDEX_LIST;
    uint8_t pNotInjectedRfList[]  = SAF_FCCU_RF_TEST_NOT_BE_INJECTED_FAULT_INDEX_LIST;
    uint8_t reservedFaultIndexLen  = (uint8_t)(sizeof(pReservedUsedRfList) / sizeof(pReservedUsedRfList[0]));
    uint8_t notInjectFaultIndexLen = (uint8_t)(sizeof(pNotInjectedRfList) / sizeof(pNotInjectedRfList[0]));
    uint8_t rfIdx=0;
    bool ret = (bool)true;    
  
    /* Check reserved fault faultIdx lists */
    for (rfIdx = 0; rfIdx < reservedFaultIndexLen; rfIdx++)
    {
        if (pReservedUsedRfList[rfIdx] == faultIdx)
        {
            ret = (bool)false;
            break;
        }
    }
    
    if (ret)
    {
        /* Check not injected fault faultIdx lists */
        for (rfIdx = 0; rfIdx < notInjectFaultIndexLen; rfIdx++)
        {
            if (pNotInjectedRfList[rfIdx] == faultIdx)
            {
                ret = (bool)false;
                break;
            }
        }    
    }
    
    return ret;
}

/**
****************************************************************************************
* @brief: [SW_SM024] This function is used to set the test result of RF test.
* @param[in] faultIdx: FCCU RF channel ID.
* @param[in] pResult: Pointer of FCCU RF test result.
* @return void
****************************************************************************************
*/
SAF_FCCU_SEC_CODE
static void SAF_FCCU_AccessSetRfTestFailureBitmap(const uint32_t faultIdx, saf_fccu_rf_test_result_t *pResult)
{
    uint32_t idx = faultIdx >> FS_DIV_32_RIGHT_SHIFT_BIT;
    uint32_t offset = faultIdx & FS_MOD_32_MASK;

    pResult->rfFailureBitmap[idx] |= (SAF_FCCU_RFS_FAILURE_BIT << offset); /* polyspace RTE:OBAI *//* parasoft-suppress MISRAC2012-RULE_12_2-a "function requirement" */
}

/**
****************************************************************************************
* @brief: [SW_SM024] This function is used to get the status of the appointed RF.
* @param[in] base     FCCU register base address pointer.
* @param[in] faultIdx FCCU RF channel ID
* @return bool
            true:  The current channel is configured as IRQ/NMI/EOUT/SHORT_RESET/
                   LONG_RESET reaction.
            false: The current channel is not be configured.
****************************************************************************************
*/
SAF_FCCU_SEC_CODE
static bool SAF_FCCU_AccessGetRfCfgStatus(const FCCU_Type * const base, const uint8_t faultIdx)
{   
    uint8_t rfEnRegIdx    = SAF_FCCU_RF_EN_REG(faultIdx);
    uint8_t rfEnBitIdx    = SAF_FCCU_RF_EN_BIT(faultIdx);
    uint8_t rfsCfgnRegIdx = SAF_FCCU_RFS_CFGN_REG(faultIdx);
    uint8_t rfsCfgnBitIdx = SAF_FCCU_RFS_CFGN_BIT(faultIdx);
    bool ret = (bool)false;

    if ((base->IRQ_ALARM_EN[rfEnRegIdx].R >> rfEnBitIdx) & 0x1U)
    {
        ret = (bool)true;
    }
    else if ((base->NMI_EN[rfEnRegIdx].R >> rfEnBitIdx) & 0x1U)
    {
        ret = (bool)true;
    }
    else if ((base->EOUT_SIG_EN[rfEnRegIdx].R >> rfEnBitIdx) & 0x1U)
    {
        ret = (bool)true;
    }
    else if (((base->RFS_CFG[rfsCfgnRegIdx].R >> rfsCfgnBitIdx) & 0x3U) ==
    		SAF_FCCU_RFS_SHORT_RESET)
    {
        ret = (bool)true;
    }
    else if (((base->RFS_CFG[rfsCfgnRegIdx].R >> rfsCfgnBitIdx) & 0x3U) ==
    		SAF_FCCU_RFS_LONG_RESET)
    {
        ret = (bool)true;
    } 
    else
    {
        /* do nothing for satisfy the misra 2012*/
    }

    return ret;
}

/**
****************************************************************************************
* @brief: [ ] This function is used to check functional reset and lock step core.
* @return status
            FS_STATUS_SUCCESS: Lock step core enabled.
            FS_STATUS_ERROR: Lock step core not enabled.
****************************************************************************************
*/
SAF_FCCU_SEC_CODE
static FS_STATUS SAF_FCCU_AccessCheckerResetAndCore(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_fccu_rf_test_result_t *pResult = &pTestResult;
    uint8_t regIdx;

    funcSoftResetFlag = SAF_FCCU_CLEAR_FUNC_RESET_FLAG;

    if (SAF_CORE_CheckerResetFlag(SAF_RESET_FUNC_FCCU_SOFT))
    {
        funcSoftResetFlag = SAF_FCCU_RFS_FUNC_RESET_FLAG;
    }
    else
    {
        /* if the checker core isn't enable will be detected by FCCU */
        if (false == SAF_CORE_CheckerCoreIsEnabled())
        {
            status = FS_STATUS_ERROR;
        }

        /* the first time */
        for (regIdx = 0; regIdx < SAF_FCCU_RF_STATUS_REG_COUNT; regIdx++)
        {
            pResult->rfFailureBitmap[regIdx] = SAF_FCCU_RFS_NO_FAILURE;
        }
    }

    return status;

}

/**
****************************************************************************************
* @brief: [ ] This function is used to perform fault injection, fault detection, and
              fault recovery testing.
* @param[in] faultId: FCCU RF channel ID.
* @return void
****************************************************************************************
*/
SAF_FCCU_SEC_CODE
static void SAF_FCCU_AccessInjectFaultTest(uint8_t faultId)
{
    FS_STATUS status = FS_STATUS_ERROR;
    saf_fccu_rf_test_result_t *pResult = &pTestResult;

    if (false == SAF_FCCU_RfIsConfigured(faultId) || (((SAF_FCCU_RFS_FUNC_RESET_FLAG != funcSoftResetFlag) || (SAF_CORE_CheckerResetFlag(SAF_RESET_DEST_EDR))) && ((uint8_t)SAF_FCCU_FAILURE_STCU_UF_CH_6 == faultId)))
    {
        /* 1. fault inject */
        if (FS_STATUS_SUCCESS == SAF_FCCU_InjectFault(faultId))
        {
            /* 2. fault detect */
            /* has been configured, ISR shall clear the flag, SAF_FCCU_DetectFault shall return error */
            if (FS_STATUS_SUCCESS == SAF_FCCU_DetectFault(faultId))
            {
                /* 3. restore */
                if (FS_STATUS_SUCCESS == SAF_FCCU_RestoreFault(faultId))
                {
                    status = FS_STATUS_SUCCESS;
                }
            }

        }

        if(FS_STATUS_SUCCESS != status)
        {
            SAF_FCCU_AccessSetRfTestFailureBitmap(faultId, pResult);
        }
    }

}

/**
****************************************************************************************
* @brief: [ ] This function is used to perform error path detection for all FCCU channels.
* @return void
****************************************************************************************
*/
SAF_FCCU_SEC_CODE
static void SAF_FCCU_AccessAllChannelRfTest(void)
{
    uint8_t faultIdx, testIdx;
    for (testIdx = 0u; testIdx < s_fccuRfTest.testRfCnt; testIdx++)
    {
        faultIdx = s_fccuRfTest.faultIDList[testIdx]; /* polyspace RTE:OBAI */

        if(((SAF_FCCU_RFS_FUNC_RESET_FLAG != funcSoftResetFlag) || (SAF_CORE_CheckerResetFlag(SAF_RESET_DEST_EDR))) && ((uint8_t)SAF_FCCU_FAILURE_STCU_UF_CH_6 == faultIdx))
        {
            SAF_FCCU_LLD_SetRfConfig(sfccRfCfg);
        }
        /* some fault idx could not be injected. */
        if(true == SAF_FCCU_AccessRfIsInjectable(faultIdx))
        {
        	SAF_FCCU_AccessInjectFaultTest(faultIdx);
        }

    }
}

/**
****************************************************************************************
 * @brief: Global Functions
****************************************************************************************
*/
/**
****************************************************************************************
* @brief: [SW_SM010] This function is used to detect if the RF is configured.
* @param[in] faultIdx  FCCU RF channel ID
* @return bool
            true:  The current channel is configured as IRQ/NMI/EOUT/SHORT_RESET/
                   LONG_RESET reaction.
            false: The current channel is not be configured. 
****************************************************************************************
*/
SAF_FCCU_SEC_CODE
boolean SAF_FCCU_RfIsConfigured(const uint8_t faultIdx)
{   
    FCCU_Type *pBase = NULL;
    bool    ret = (bool)false;

    if (faultIdx < SAF_FCCU_RF_FAULT_ID_INDEX_COUNT)
    {          
        pBase = SAF_FCCU_BASE_PTRS;
        ret = SAF_FCCU_AccessGetRfCfgStatus(pBase, faultIdx);
    }
   
    return ret;       
}

/**
****************************************************************************************
* @brief: [SW_SM024] This function will trigger a recoverable fault fake to allow a test  
                     of behavior of configured recoverable Faults. This function is in 
                     scope of debug the configuration of FCCU module.
* @param[in] faultIdx  FCCU RF channel ID
* @return status
            FS_STATUS_SUCCESS: success to inject a recoverable fault.
            FS_STATUS_ERROR: fail to inject a recoverable fault.
****************************************************************************************
*/
SAF_FCCU_SEC_CODE
FS_STATUS SAF_FCCU_InjectFault(const uint8_t faultIdx)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (faultIdx < SAF_FCCU_RF_FAULT_ID_INDEX_COUNT)
    {
    	SAF_FCCU_LLD_SetRfFake((SAF_fccu_failure_inputs_t)faultIdx);/*PRQA S 4442*/
        status = FS_STATUS_SUCCESS;
    }
    
    return status;
}

/**
****************************************************************************************
* @brief: [SW_SM005][SW_013][SW_SM024] This function will detect the special ID fault 
                     to allow a test of behavior of configured recoverable Faults. This 
                     function is in scope of Debug the Configuration of FCCU Module.
* @param[in] faultIdx  FCCU RF channel ID
* @return status
            FS_STATUS_SUCCESS: The channel has fault.
            FS_STATUS_ERROR: The channel has no fault.
****************************************************************************************
*/
SAF_FCCU_SEC_CODE
FS_STATUS SAF_FCCU_DetectFault(const uint8_t faultIdx)
{
    SAF_fccu_faults_flags_t faults = {{0}};
    FS_STATUS status = FS_STATUS_ERROR;
    FS_STATUS rstatus = FS_STATUS_ERROR;
    uint8_t shift, regIndex;

    if (faultIdx < SAF_FCCU_RF_FAULT_ID_INDEX_COUNT)
    {
        shift    = (uint8_t)(faultIdx & FS_MOD_32_MASK);/*PRQA S 4542,1861,4393*/
        regIndex = (uint8_t)(faultIdx >> FS_DIV_32_RIGHT_SHIFT_BIT);

        rstatus = (FS_STATUS)SAF_FCCU_LLD_ReadFaults(&faults);

        if(rstatus == FS_STATUS_SUCCESS)
        {
			if (SAF_FCCU_RFS_NO_FAILURE != ((faults.faultsFlags[regIndex] >> shift) & SAF_FCCU_RFS_FAILURE_BIT))
			{
				status = FS_STATUS_SUCCESS;
			}
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief: [SW_SM005][SW_013] This function will restore the special ID fault to allow a 
                     test of behavior of configured recoverable Faults. This 
                     function is in scope of Debug the Configuration of FCCU Module.
* @param[in] faultIdx  FCCU RF channel ID
* @return status
            FS_STATUS_SUCCESS: Success to clear the falut status of the fccu channels.
            FS_STATUS_ERROR: Fail to clear the falut status of the fccu channels.
****************************************************************************************
*/
SAF_FCCU_SEC_CODE
FS_STATUS SAF_FCCU_RestoreFault(const uint8_t faultIdx)
{
    FS_STATUS status = FS_STATUS_ERROR;
  
    if (faultIdx < SAF_FCCU_RF_FAULT_ID_INDEX_COUNT)
    {
        if (STATUS_SUCCESS == SAF_FCCU_LLD_ClearFaults(faultIdx))
        {
            if (FS_STATUS_SUCCESS != SAF_FCCU_DetectFault(faultIdx))
            {
                status = FS_STATUS_SUCCESS;
            }
        }
    }
    
    return status;
}

/**
****************************************************************************************
* @brief: [SW_SM005][SW_013][SW_SM024] This function will detect all ID fault.
* @param[in] void
* @return status
            FS_STATUS_SUCCESS: One of the channels has an fault.
            FS_STATUS_ERROR: All channels are normal.
****************************************************************************************
*/
SAF_FCCU_SEC_CODE
FS_STATUS SAF_FCCU_DetectAllChannelFault(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint8_t faultIdx, testRfIdx, rfStatusRegIndex;
    uint8_t faultIdInc = 0;
    uint8_t faultId[SAF_FCCU_RF_MAX_SIZE] = {0};
    saf_fccu_rf_test_result_t fccuRfTestResult;

    realfccuCfg = fccuCfg;

    SAF_FCCU_RfErrReportPathTestResult(&fccuRfTestResult);

    for(testRfIdx = 0; testRfIdx < s_fccuRfTest.testRfCnt; testRfIdx++)
    {
    	faultIdx = s_fccuRfTest.faultIDList[testRfIdx]; /* polyspace RTE:OBAI */
    	rfStatusRegIndex = faultIdx >> FS_DIV_32_RIGHT_SHIFT_BIT;

        if(SAF_FCCU_RFS_NO_FAILURE != (fccuRfTestResult.rfFailureBitmap[rfStatusRegIndex] & (SAF_FCCU_RFS_FAILURE_BIT << (faultIdx & FS_MOD_32_MASK)))) /*PRQA S 4542,1861,4534*/ /* polyspace RTE:OBAI */
    	{
            faultId[faultIdx] = SAF_FCCU_MASKCODE;
            status = FS_STATUS_ERROR;
    	}
    }

    for(testRfIdx = 0; testRfIdx < SAFETYFCCUTST_CFG_CHANNEL_COUNT; testRfIdx++)/*PRQA S 2462,2877,3418,2982*/
    {
        faultIdx = fccRfCfg[testRfIdx].channel;
        if(faultId[faultIdx] != SAF_FCCU_MASKCODE)/*PRQA S 1863*/ /* polyspace RTE:OBAI */
        {
            realFccuRfCfg[faultIdInc] = fccRfCfg[testRfIdx];
            faultIdInc++;/*PRQA S 2983,2984*/
        }
    }

    realfccuCfg.rfConfigNumber = faultIdInc;

    return status;
}

/**
****************************************************************************************
* @brief: [SW_005] This function detects FCCU channels that are not configured.
*         If a channel is unconfigured, its configuration entry from the temporary
*         configuration array will be copied into the real configuration array.
*         Finally, the number of valid entries in the real configuration is updated.
*
* @param[in]  fccuStartUpCfg : Pointer to FCCU startup configuration structure.
* @param[out] realRfCfg      : Pointer to the array that stores valid (unconfigured)
*                              channel configurations.
* @param[in]  tempRfCfg      : Pointer to the temporary configuration array containing
*                              candidate channel configurations.
* @param[in]  chanOffset     : Start index offset of FCCU channels to be checked.
* @param[in]  length         : Number of FCCU channels to be checked.
*
* @return     void
****************************************************************************************
*/
SAF_FCCU_SEC_CODE
void SAF_FCCU_CopyUninitChannelConfig(fccu_config_t* fccuStartUpCfg,fccu_rf_config_t* realRfCfg,fccu_rf_config_t* tempRfCfg, uint32_t chanOffset, uint32_t length)
{
    uint32_t i, chanIdx, realFccuIndex, FccuIndex;

    for (i = 0, FccuIndex = 0, realFccuIndex = 0; i < length; i++, FccuIndex++)
    {
    	chanIdx = i + chanOffset;
    	if (!SAF_FCCU_RfIsConfigured(chanIdx))/*PRQA S 4116,4558*/
		{
    		realRfCfg[realFccuIndex++] = tempRfCfg[FccuIndex];
		}
    }
    fccuStartUpCfg->rfConfigNumber = realFccuIndex;
}

/**
****************************************************************************************
* @brief: [SW_SM005][SW_013] This function will clear the error status of all channels.
* @param[in] void
* @return status
            FS_STATUS_SUCCESS: Success to clear the falut status of all fccu channels.
            FS_STATUS_ERROR: Fail to clear the falut status of all fccu channels.
****************************************************************************************
*/
SAF_FCCU_SEC_CODE
FS_STATUS SAF_FCCU_ClearAllChannelFault(void)
{
    FS_STATUS status = FS_STATUS_ERROR;
    uint8_t faultIdx, testIdx = 0;

    for(testIdx = 0; testIdx < s_fccuRfTest.testRfCnt; testIdx++)
    {
        if((false == SAF_CORE_CheckerCoreIsEnabled()) && (51 == testIdx))/*PRQA S 1863*/
        {
            continue;
        }
        
        faultIdx = s_fccuRfTest.faultIDList[testIdx]; /* polyspace RTE:OBAI */
        status = SAF_FCCU_RestoreFault(faultIdx);
        if (FS_STATUS_SUCCESS != status)
        {
            break;
        }
    }

    status = (FS_STATUS)MEMU_LLD_Reset();

    if (status == FS_STATUS_SUCCESS)
    {
    	status = (FS_STATUS)SAF_FCCU_LLD_ClearFaults(SAF_FCCU_MAX_FAULTS_NO);
    }

    return status;
}

/**
****************************************************************************************
* @brief: This function is used to execute FCCU RF error report path test.
* @param[in] void
* @return status
            FS_STATUS_SUCCESS: The FCCU test is successful.
            FS_STATUS_ERROR: The FCCU test is error.
****************************************************************************************
*/
SAF_FCCU_SEC_CODE
FS_STATUS SAF_FCCU_RfErrReportPathTest(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    FS_STATUS injStatus = FS_STATUS_SUCCESS;
    saf_fccu_rf_test_result_t *pResult = &pTestResult;
    uint8_t regIdx = 0;

	/* check fccu reset state and check core */
    status = SAF_FCCU_AccessCheckerResetAndCore();
    /* clear all faults */
    if (STATUS_SUCCESS != SAF_FCCU_LLD_ClearFaults(SAF_FCCU_MAX_FAULTS_NO))
    {
        for (regIdx = 0; regIdx < SAF_FCCU_RF_STATUS_REG_COUNT; regIdx++)
        {
            /* Mark all fault faultIdIdx test is error */
        	pResult->rfFailureBitmap[regIdx] = FS_UIN32_MAX;
        }
        status = FS_STATUS_ERROR;
    }
    else
    {
    	SAF_FCCU_AccessAllChannelRfTest();
        /* Decide the return status */
        for (regIdx = 0; regIdx < SAF_FCCU_RF_STATUS_REG_COUNT; regIdx++)
        {
            if (pResult->rfFailureBitmap[regIdx] > 0)/*PRQA S 1842*/
            {
            	injStatus = FS_STATUS_FCCU_STARTUP_TEST_FAILED;
            }
        }
    }

    SAF_FCCU_DetectAllChannelFault();
    if((SAF_FCCU_RFS_FUNC_RESET_FLAG != funcSoftResetFlag) || (SAF_CORE_CheckerResetFlag(SAF_RESET_DEST_EDR)))/*PRQA S 1863,4115*/
    {
    	status = SAF_FCCU_HardwareInit(&realfccuCfg, realFccuRfCfg);
    }

    if (injStatus != FS_STATUS_SUCCESS)
    {
    	status = FS_STATUS_FCCU_STARTUP_TEST_FAILED;
    }

    return status;
}

/**
****************************************************************************************
* @brief: This function is used to get the test result FCCU RF error report path test.
* @param[in] void
* @return status
            FS_STATUS_SUCCESS: The test result report successfully.
            FS_STATUS_ERROR: The test result report failed.
****************************************************************************************
*/
SAF_FCCU_SEC_CODE
FS_STATUS SAF_FCCU_RfErrReportPathTestResult(saf_fccu_rf_test_result_t *TestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (NULL != TestResult)
    {
        memcpy(TestResult, &pTestResult, sizeof(pTestResult));/*PRQA S 0315*/
        status = FS_STATUS_SUCCESS;
    }

    return status;
}

/**
****************************************************************************************
* @brief: This function is used to configure fccu channels.
* @param[in] config fccu module configuration
* @param[in] rfConfig fccu recoverable faults configuration
* @return status
            FS_STATUS_SUCCESS: The fccu channel is successfully configured.
            FS_STATUS_ERROR: Failed to configure the fccu channel.
****************************************************************************************
*/
SAF_FCCU_SEC_CODE
FS_STATUS SAF_FCCU_HardwareInit(fccu_config_t *config, fccu_rf_config_t *rfConfig)
{
	FS_STATUS status = FS_STATUS_ERROR;
	status_t FCCU_Status = STATUS_ERROR;

	FCCU_Status = FCCU_LLD_Init(config, (fccu_rf_config_t const *)rfConfig);

	if(STATUS_SUCCESS == FCCU_Status)
	{
		status = FS_STATUS_SUCCESS;
	}

#if (STACK_MONITOR_ENABLE == STD_ON) && (SAFETYMEMTEST_SRAM_ECC_REPORT_PATH_TEST == STD_OFF)
	(void)SAF_FCCU_LLD_CloseChReaction(SAF_FCCU_FAILURE_MEMU_RAM_UCE_CH_17);
	(void)SAF_FCCU_LLD_CloseChReaction(SAF_FCCU_FAILURE_MEMU_RAM_BOV_CH_18);
#endif

	return status;
}

#ifdef __cplusplus
}
#endif
