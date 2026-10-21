/**
****************************************************************************************
 * @FilePath: saf_userservice_startup.c
 * @Author: CCORE
 * @Date: 2024-02-12
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety User Service Startup C Source File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_userservice_startup.h"
#include "saf_osc.h"/*PRQA S 0380*/
#include "saf_flash.h"
#include "saf_ram.h"
#include "saf_fccu.h"
#include "saf_pll.h"
#include "saf_bist.h"
#include "saf_adc.h"
#include "saf_cmu.h"
#include "saf_cache.h"
#include "saf_stack.h"
#include "saf_pmc.h"
#include "saf_tsens.h"
#include "saf_crc.h"
#include "saf_swt.h"
#include "saf_stm.h"
#include "saf_pit.h"
#include "saf_mpu.h"
#include "saf_smpu.h"
#include "Saf_MemMap.h"
#include "ErrorDiag_Swc.h"
#include "ErrorHandler_Swc.h"


/*PRQA S 1259,1881,2844,3006,3200,3344,3397,3400,3401,3408,3604,4304 EOF*/

/**
****************************************************************************************
 * @brief: Global Variables
****************************************************************************************
*/
SAF_SEC_VAR_INIT
bool SAF_b_cmu_start = (bool)false;
extern saf_fccu_rf_test_t s_fccuRfTest;
extern const call_config_t s_flashAICallSet;
extern const call_config_t s_flashMRCallSet;
extern const call_config_t s_flashEccCallSet;
extern const call_config_t s_ramEccCallSet;
extern const call_config_t s_oscCallSet;
extern const call_config_t s_pllSysClkCallSet;
extern const call_config_t s_fccuCallSet;
extern const call_config_t s_fccuCfgCallSet;
extern const call_config_t s_AdcTestCallSet;
extern const call_config_t s_offlinebistCallSet;
extern const call_config_t s_OnlinebistCallSet;
extern const call_config_t s_dcfCallSet;
extern const call_config_t s_cmuConfigcheckCallSet;
extern const call_config_t s_cmuMonitorTestFreqOverHighCallSet;
extern const call_config_t s_cmuMonitorTestFreqOverLowCallSet;
extern const call_config_t s_cmuMonitorTestOscFreqOverLowCallSet;
extern const call_config_t s_cmuUserServiceTestCallSet;

extern saf_cmu_monitor_configure_t s_cmuConfigList[CMU_INSTANCE_COUNT];
/**
****************************************************************************************
 * @brief: Global Function
****************************************************************************************
*/
/**
****************************************************************************************
* @brief:  The service run the osc tests.
* @return   FS_STATUS_SUCCESS: The osc test is successful.
            FS_STATUS_ERROR: The osc test is error.
****************************************************************************************
*/
SAF_SEC_CODE
FS_STATUS SAF_UserService_OscTest(void)
{
    FS_STATUS result = FS_STATUS_SUCCESS;
    saf_osc_xosc_sys_clk_test_result_t oscSysClkSrcTestResult;
    saf_osc_ircosc_freq_check_test_result_t oscFreqTestResult;

    (void)SAF_OSC_IrcoscFreqAccuracyInit();

    if(FS_STATUS_SUCCESS != SAF_OSC_XoscSysClkSrcCheckTest())
    {
        result = FS_STATUS_ERROR;
        /*APP error handle*/
        ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_OSC_XoscSysClkSrcCheckTest);
    }

    (void)SAF_OSC_GetSysClkSrcCheckResult(&oscSysClkSrcTestResult);

    /* 1. Check ircosc is stable*/
    if(FS_STATUS_SUCCESS != SAF_OSC_IrcoscFreqIsStable())
    {
    	result = FS_STATUS_ERROR;
    	/*APP error handle*/
        ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_OSC_IrcoscFreqIsStable);
    }
    /* 2. Check xosc is stable*/
    if(FS_STATUS_SUCCESS != SAF_OSC_XoscFreqIsStable())
    {
    	result = FS_STATUS_ERROR;
    	/*APP error handle*/
        ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_OSC_XoscFreqIsStable);
    }
    /* 3. IRCOSC frequency accuracy test*/
    if(FS_STATUS_SUCCESS != SAF_OSC_IrcoscFreqAccuracyTest())
    {
        result = FS_STATUS_ERROR;
        /*APP error handle*/
        ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_OSC_IrcoscFreqAccuracyTest);
    }

    (void)SAF_OSC_GetFreqCheckResult(&oscFreqTestResult);

    /* 4. start up cmu*/
    if(result == FS_STATUS_SUCCESS)
    {
    	SAF_b_cmu_start = (bool)true;
    }

    /* 5. check PLL0 & PLL1 is stable*/
    if(FS_STATUS_SUCCESS != SAF_PLL_IsStable())
    {
        result = FS_STATUS_ERROR;
        /*APP error handle*/
        ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_PLL_IsStable);
    }
	if ((result != FS_STATUS_SUCCESS) && (s_oscCallSet.callback != NULL))
	{
		s_oscCallSet.callback(s_oscCallSet.callbackParam);
	}
    return result;
}

/**
****************************************************************************************
* @brief:  The service run the pll tests.
* @return   FS_STATUS_SUCCESS: The pll test is successful.
            FS_STATUS_ERROR: The pll test is error.
****************************************************************************************
*/
SAF_SEC_CODE
FS_STATUS SAF_UserService_PllTest(void)
{
	FS_STATUS result = FS_STATUS_SUCCESS;

	if(FS_STATUS_SUCCESS != SAF_PLL_SysClkSrcCheckTest())
	{
		result = FS_STATUS_ERROR;
		if (s_pllSysClkCallSet.callback != NULL)
		{
			s_pllSysClkCallSet.callback(s_pllSysClkCallSet.callbackParam);
		}
        ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_PLL_SysClkSrcCheckTest);
	}

    /* 2. Check MCAN and FlexRay clock source*/
    if(FS_STATUS_SUCCESS != SAF_PLL_PeriphClkSrcCheckTest())
    {
        result = FS_STATUS_ERROR;
        if (NULL != s_pllPeriphClkCallSet.callback)
        {
            s_pllPeriphClkCallSet.callback(s_pllPeriphClkCallSet.callbackParam);
        }
        /*APP error handle*/
        ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_PLL_PeriphClkSrcCheckTest);
    }

	return result;
}

/**
****************************************************************************************
* @brief The service run the FLASH tests.
* @return FS_STATUS_SUCCESS :All FLASH tests are successful.
          FS_STATUS_ERROR :One or more of the FLASH tests failed .
****************************************************************************************
*/
SAF_SEC_CODE
FS_STATUS SAF_UserService_FlashTest(void)
{
    FS_STATUS status = FS_STATUS_ERROR;
    FS_STATUS flashEccStatus = FS_STATUS_ERROR;
    FS_STATUS flashAiStatus = FS_STATUS_ERROR;
    FS_STATUS flashMrStatus= FS_STATUS_ERROR;

    /* FLASH ECC test. */  
   flashEccStatus = SAF_FLASH_EccReportPathTest();
    if (FS_STATUS_SUCCESS != flashEccStatus)
    {
        if (NULL != s_flashEccCallSet.callback)
        {
            s_flashEccCallSet.callback(s_flashEccCallSet.callbackParam);
        }
        ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_FLASH_EccReportPathTest);
    }

     /* FLASH Array Integrity test. */
    flashAiStatus = SAF_FLASH_ArrayIntegrityTest();
    if (FS_STATUS_SUCCESS != flashAiStatus)
    {
         if (NULL != s_flashAICallSet.callback)
         {
             s_flashAICallSet.callback(s_flashAICallSet.callbackParam);
         }
    }

     /* FLASH Margin Read test. */
    flashMrStatus = SAF_FLASH_MarginReadTest();
     if (FS_STATUS_SUCCESS != flashMrStatus)
     {
         if (NULL != s_flashMRCallSet.callback)
         {
             s_flashMRCallSet.callback(s_flashMRCallSet.callbackParam);
         }
     }

     if (FS_STATUS_SUCCESS == flashEccStatus\
         && FS_STATUS_SUCCESS == flashAiStatus\
         && FS_STATUS_SUCCESS == flashMrStatus)
    if (FS_STATUS_SUCCESS == flashEccStatus)
    {
        status = FS_STATUS_SUCCESS;
    }

    SAF_FLASH_ClearCodeRam();

    return status;
}

/**
****************************************************************************************
* @brief:  The service run the ram ECC report path tests.
* @return   FS_STATUS_SUCCESS: The ram ECC report path test is successful.
            FS_STATUS_ERROR: The ram ECC report path test is error.
****************************************************************************************
*/
SAF_SEC_CODE
FS_STATUS SAF_UserService_RamTest(void)
{
    FS_STATUS result = FS_STATUS_SUCCESS;

    result = SAF_RAM_EccReportPathTest();

    if(FS_STATUS_SUCCESS != result)
    {
    	if (NULL != s_ramEccCallSet.callback)
    	{
    		s_ramEccCallSet.callback(s_ramEccCallSet.callbackParam);
    	}
        ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_RAM_EccReportPathTest);
    }

    return result;
}

/**
****************************************************************************************
* @brief The service run the CACHE tests.
* @return FS_STATUS_SUCCESS :All CACHE tests are successful.
          FS_STATUS_ERROR :One or more of the CACHE tests failed .
****************************************************************************************
*/
SAF_SEC_CODE
FS_STATUS SAF_UserService_CacheTest(void)
{
    FS_STATUS status = FS_STATUS_ERROR;

    status = SAF_CACHE_EdcReportPathTest();
    if(FS_STATUS_SUCCESS != status)
    {
        if (NULL != s_cacheCallSet.callback)
        {
            s_cacheCallSet.callback(s_cacheCallSet.callbackParam);
        }
        ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_CACHE_EdcReportPathTest);
    }

    return status;
}

/**
****************************************************************************************
* @brief The service run the STACK tests.
* @return FS_STATUS_SUCCESS :All STACK tests are successful.
          FS_STATUS_ERROR :One or more of the CACHE tests failed .
****************************************************************************************
*/
uint8 StackTest_u8;
SAF_SEC_CODE
FS_STATUS SAF_UserService_StackTest(void)
{
     FS_STATUS status = FS_STATUS_ERROR;
     #if 1
     StackTest_u8 = 255;
     status = SAF_STACK_MonitorTest();
     if(FS_STATUS_SUCCESS != status)
     {
         if (NULL != s_stackCallSet.callback)
         {
             s_stackCallSet.callback(s_stackCallSet.callbackParam);
         }
     }
    #endif
     StackTest_u8 = status;
    return status;
}

/**
****************************************************************************************
* @brief:  The service run the fccu tests.
* @return   FS_STATUS_SUCCESS: The fccu test is successful.
            FS_STATUS_ERROR: The fccu test is error.
****************************************************************************************
*/

SAF_SEC_CODE
FS_STATUS SAF_UserService_FccuRfTest(void)
{
    saf_fccu_rf_test_result_t fccuRfTestResult;
    uint8_t faultID, testRfIndex, rfStatusRegIndex;
    FS_STATUS status = FS_STATUS_SUCCESS;

    uint32_t temp = 0;
    temp = MFSPR(572); /* PRQA S 1006, 2983 # write clear */
    MTSPR(572, temp); /* PRQA S 1006 */
    SAF_FCCU_ClearAllChannelFault();
    status = SAF_FCCU_RfErrReportPathTest();
    SAF_FCCU_RfErrReportPathTestResult(&fccuRfTestResult);
    for (testRfIndex = 0;testRfIndex < s_fccuRfTest.testRfCnt;testRfIndex++)
    {
        faultID = s_fccuRfTest.faultIDList[testRfIndex];
        rfStatusRegIndex = faultID >> FS_DIV_32_RIGHT_SHIFT_BIT;

        if (fccuRfTestResult.rfFailureBitmap[rfStatusRegIndex] & (0x1UL << (faultID & FS_MOD_32_MASK))) /*PRQA S 1861,4534,4542*/ /* polyspace RTE:OBAI */
        {
            if (testRfIndex == 10 || testRfIndex == 11 || testRfIndex == 50) { continue; }

            if (s_fccuCallSet.callback != NULL)
            {
                s_fccuCallSet.callback(s_fccuCallSet.callbackParam);
            }
            
            // ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_FCCU_RfErrReportPathTest);
        }
    }

    for(testRfIndex = 0; testRfIndex < realfccuCfg.rfConfigNumber; testRfIndex++)
    {
        faultID = realFccuRfCfg[testRfIndex].channel; /* polyspace RTE:OBAI */

        if (testRfIndex == 10 || testRfIndex == 11 || testRfIndex == 50) { continue; }

        if(false == SAF_FCCU_RfIsConfigured(faultID))
        {
        	status = FS_STATUS_ERROR;
            if (s_fccuCfgCallSet.callback != NULL)
            {
                s_fccuCfgCallSet.callback(s_fccuCfgCallSet.callbackParam);
            }
            // ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_FCCU_RfIsConfigured);
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief:  The service run the dcf&bist tests.
* @return   FS_STATUS_SUCCESS: The dcf&bist test is successful.
            FS_STATUS_ERROR: The dcf&bist test is error.
****************************************************************************************
*/
SAF_SEC_CODE
FS_STATUS SAF_UserService_DcfAndBistTest(void)
{
    FS_STATUS status = FS_STATUS_ERROR;
    FS_STATUS dcfStatus = FS_STATUS_SUCCESS;
    FS_STATUS bistStatus = FS_STATUS_SUCCESS;
    saf_bist_check_result_t OfflineBistResult = { SAF_BIST_CHECK_FAIL_RESULT, SAF_BIST_CHECK_FAIL_RESULT\
                                                    , SAF_BIST_CHECK_FAIL_RESULT, SAF_BIST_CHECK_FAIL_RESULT, { 0U }, { 0U } };

    dcfStatus = SAF_BIST_DcfCmpValue((uint32_t)SAF_DCF_START_ADDR);
    if(FS_STATUS_SUCCESS != dcfStatus)
    {
        if (s_dcfCallSet.callback != NULL)
        {
            s_dcfCallSet.callback(s_dcfCallSet.callbackParam);
        }
        // ErrorHandler_ResetAndReport(ERRORID_MCU_Prestartup_ResetDetectInit_Test);
    }

    bistStatus = SAF_BIST_OfflineCheck(&OfflineBistResult);
    if(FS_STATUS_SUCCESS != bistStatus)
    {
        if (s_offlinebistCallSet.callback != NULL)
        {
            s_offlinebistCallSet.callback(s_offlinebistCallSet.callbackParam);
        }
        ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_BIST_Offline_Record_Test);
    }

    if ((FS_STATUS_SUCCESS == dcfStatus) && (FS_STATUS_SUCCESS == bistStatus))
    {
        status = FS_STATUS_SUCCESS;
    }

    return status;
}

/**
****************************************************************************************
* @brief:  The service run the adc tests.
* @return   FS_STATUS_SUCCESS: The adc test is successful.
            FS_STATUS_ERROR: The adc test is error.
****************************************************************************************
*/
SAF_SEC_CODE
FS_STATUS SAF_UserService_AdcTest(void)
{
    FS_STATUS result = FS_STATUS_SUCCESS;

    if(FS_STATUS_SUCCESS != SAF_ADC_ModeSafetyTest())
    {
    	if (s_AdcTestCallSet.callback != NULL)
    	{
    		s_AdcTestCallSet.callback(s_AdcTestCallSet.callbackParam);
    	}

        result = FS_STATUS_ERROR;
        /*APP error handle*/
        ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_ADC_ModeSafetyTest);
    }

    return result;

}

/**
****************************************************************************************
* @brief: This function is used by the user to call the cmu test interface and add their own
          code based on the relevant results during the cmu test.
* @param[in] void
* @return status
            FS_STATUS_SUCCESS: The cmu test is successful.
            FS_STATUS_ERROR: The cmu test is error.
****************************************************************************************
*/
SAF_SEC_CODE
FS_STATUS SAF_UserService_CmuTest(void)
{
	saf_cmu_monitor_test_t cmuMonitorTestResult;
	saf_cmu_config_check_test_t cmuCfgTestResult;
    FS_STATUS status = FS_STATUS_SUCCESS;
#if 1
    SAF_CMU_Deinit();
    if(FS_STATUS_SUCCESS != SAF_CMU_Init(&s_cmuConfigList[0], CMU_INSTANCE_COUNT))
    {
        status = FS_STATUS_ERROR;
        if(NULL != s_cmuUserServiceTestCallSet.callback)
        {
            s_cmuUserServiceTestCallSet.callback(s_cmuUserServiceTestCallSet.callbackParam);
        }
        ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_CMU_Init);
    }
    else if(FS_STATUS_SUCCESS != SAF_CMU_ConfigCheckTest())//1.Configuration check test
    {
        status = FS_STATUS_ERROR;
        (void)SAF_CMU_ConfigCheckTestResult(&cmuCfgTestResult);

        if (NULL != s_cmuConfigcheckCallSet.callback)
        {
            s_cmuConfigcheckCallSet.callback(s_cmuConfigcheckCallSet.callbackParam);
        }
        ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_CMU_ConfigCheckTest);
    }
    else if(FS_STATUS_SUCCESS != SAF_CMU_MonitorTest())//2. CMU monitor test
    {
        status = FS_STATUS_ERROR;
        (void)SAF_CMU_MonitorTestResult(&cmuMonitorTestResult);

        if(NULL != s_cmuMonitorTestFreqOverHighCallSet.callback)
        {
            s_cmuMonitorTestFreqOverHighCallSet.callback(s_cmuMonitorTestFreqOverHighCallSet.callbackParam);
        }

        if(NULL != s_cmuMonitorTestFreqOverLowCallSet.callback)
        {
            s_cmuMonitorTestFreqOverLowCallSet.callback(s_cmuMonitorTestFreqOverLowCallSet.callbackParam);
        }

        if(NULL != s_cmuMonitorTestOscFreqOverLowCallSet.callback)
        {
            s_cmuMonitorTestOscFreqOverLowCallSet.callback(s_cmuMonitorTestOscFreqOverLowCallSet.callbackParam);
        }
        ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_CMU_MonitorTest);

    }
    else
    {
        /* do nothing for satisfy the misra 2012*/
    }
#endif
    return status;
}

/**
****************************************************************************************
* @brief The service run the pmc tests.
* @return status
            FS_STATUS_SUCCESS: The pmc tests is sucess.
            FS_STATUS_ERROR: The pmc tests is error.
****************************************************************************************
*/
SAF_SEC_CODE
FS_STATUS SAF_UserService_PmcSelfTest(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    if(FS_STATUS_SUCCESS != SAF_PMC_SelfTest())
    {
        status = FS_STATUS_ERROR;
        if (NULL != s_pmcSelfTestCallSet.callback)
        {
            s_pmcSelfTestCallSet.callback(s_pmcSelfTestCallSet.callbackParam);
        }
        ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_PMC_SelfTest);
    }

    return status;
}

/**
****************************************************************************************
* @brief The service run the tsens tests.
* @return status
            FS_STATUS_SUCCESS: The tsens tests is sucess.
            FS_STATUS_ERROR: The tsens tests is error.
****************************************************************************************
*/
SAF_SEC_CODE
FS_STATUS SAF_UserService_TsensPathTest(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    if(FS_STATUS_SUCCESS != SAF_TSENS_HtdPathInjTest())
    {
        status = FS_STATUS_ERROR;
        if (NULL != s_TsensChipTempHtdPathCallSet.callback)
        {
            s_TsensChipTempHtdPathCallSet.callback(s_TsensChipTempHtdPathCallSet.callbackParam);
        }
        ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_TSENS_HtdPathInjTest);
    }
    SAF_TSENS_ConfigDeInit();

    if(FS_STATUS_SUCCESS != SAF_TSENS_LtdPathInjTest())
    {
        status = FS_STATUS_ERROR;
        if (NULL != s_TsensChipTempLtdPathCallSet.callback)
        {
            s_TsensChipTempLtdPathCallSet.callback(s_TsensChipTempLtdPathCallSet.callbackParam);
        }
        ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_TSENS_LtdPathInjTest);
    }
    SAF_TSENS_ConfigDeInit();

    SAF_TSENS_ConfigInit();

    return status;
}

/**
****************************************************************************************
* @brief:  The service run the crc self tests.
* @return  FS_STATUS_SUCESS: crc self test is success
*          FS_STATUS_ERROR: crc self test is error
****************************************************************************************
*/
SAF_SEC_CODE
FS_STATUS SAF_UserService_CrcSelfTest(void)
{
    FS_STATUS result = FS_STATUS_SUCCESS;

    if(FS_STATUS_SUCCESS != SAF_CRC_SelfTest())
    {
        result = FS_STATUS_ERROR;
        if (NULL != s_crcSelfTestCallSet.callback)
        {
            s_crcSelfTestCallSet.callback(s_crcSelfTestCallSet.callbackParam);
        }
        ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_CRC_SelfTest);
    }
    return result;
}

/**
****************************************************************************************
* @brief The service run the swt tests.
* @return status
            FS_STATUS_SUCCESS: The swt tests is success.
            FS_STATUS_ERROR: The swt tests is error.
****************************************************************************************
*/
SAF_SEC_CODE
FS_STATUS SAF_UserService_SwtPathTest(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    // if(FS_STATUS_SUCCESS != SAF_SWT_PathTest())
    // {
    //     status = FS_STATUS_ERROR;
    //     if (NULL != s_SwtPathCallSet.callback)
    //     {
    //         s_SwtPathCallSet.callback(s_SwtPathCallSet.callbackParam);
    //     }
    //     /*APP error handle*/
    // }

    return status;
}

/**
****************************************************************************************
* @brief The service run the stm tests.
* @return result
            FS_STATUS_SUCCESS: The stm tests is success.
            FS_STATUS_ERROR: The stm tests is error.
****************************************************************************************
*/
SAF_SEC_CODE
FS_STATUS SAF_UserService_StmConfigDataInit(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    if(FS_STATUS_SUCCESS != SAF_STM_ConfigDataInit())
    {
        status = FS_STATUS_ERROR;
        if (NULL != s_StmTimerConfigDataInitCallSet.callback)
        {
            s_StmTimerConfigDataInitCallSet.callback(s_StmTimerConfigDataInitCallSet.callbackParam);
        }
        /*APP error handle*/
        ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_STM_ConfigDataInit);
    }

    return status;
}


/**
****************************************************************************************
* @brief The service run the pit tests.
* @return result
            FS_STATUS_SUCCESS: The pit tests is success.
            FS_STATUS_ERROR: The pit tests is error.
****************************************************************************************
*/
SAF_SEC_CODE
FS_STATUS SAF_UserService_PitConfigDataInit(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    if(FS_STATUS_SUCCESS != SAF_PIT_ConfigDataInit())
    {
        status = FS_STATUS_ERROR;
        if (NULL != s_PitTimerConfigDataInitCallSet.callback)
        {
            s_PitTimerConfigDataInitCallSet.callback(s_PitTimerConfigDataInitCallSet.callbackParam);
        }
        /*APP error handle*/
        ErrorHandler_ResetAndReport(ERRORID_MCU_Startup_PIT_ConfigDataInit);
    }

    return status;
}

/**
****************************************************************************************
* @brief The service init MPU
* @return result
            FS_STATUS_SUCCESS: The mpu init success.
            FS_STATUS_ERROR: The mpu init error .
****************************************************************************************
*/
SAF_SEC_CODE
FS_STATUS SAF_UserService_MPUInit(void)
{
    FS_STATUS result = FS_STATUS_SUCCESS;

    /* Init MPU config  */
    if(FS_STATUS_SUCCESS != SAF_MPU_SafetyInit(0, &mpu_CfgZ70, mpuEntryArrayZ70, SAFETYMEMTEST_CMPU_Z70_ENTRY_COUNT_BY_SELF))
    {
        result = FS_STATUS_ERROR;
        if (NULL != s_mpuCallSet.callback)
        {
            s_mpuCallSet.callback(s_mpuCallSet.callbackParam);
        }
    }
    return result;
}

/**
****************************************************************************************
* @brief The service run the pit tests.
* @return result
            FS_STATUS_SUCCESS: The smpu init success.
            FS_STATUS_ERROR: The smpu init error.
****************************************************************************************
*/
SAF_SEC_CODE
FS_STATUS SAF_UserService_SMPUInit(void)
{
    FS_STATUS result = FS_STATUS_SUCCESS;


    /* Init SMPU0 config  */
    if(FS_STATUS_SUCCESS != SAF_SMPU_SafetyInit(SAF_SMPU0, SAFETYMEMTEST_SMPU_0_ENTRY_COUNT, (const smpu_config_t *)smpu0EntryArray))
    {
        result = FS_STATUS_ERROR;
        if (NULL != s_smpuCallSet.callback)
        {
            s_smpuCallSet.callback(s_smpuCallSet.callbackParam);
        }
    }


    /* Init SMPU1 config  */
    if(FS_STATUS_SUCCESS != SAF_SMPU_SafetyInit(SAF_SMPU1, SAFETYMEMTEST_SMPU_1_ENTRY_COUNT, (const smpu_config_t *)smpu1EntryArray))
    {
        result = FS_STATUS_ERROR;
        if (NULL != s_smpuCallSet.callback)
        {
            s_smpuCallSet.callback(s_smpuCallSet.callbackParam);
        }
    }

    return result;
}
