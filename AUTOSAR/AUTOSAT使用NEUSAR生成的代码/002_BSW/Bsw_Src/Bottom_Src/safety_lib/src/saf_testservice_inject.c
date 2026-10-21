/**
****************************************************************************************
 * @FilePath: saf_testservice_inject.c
 * @Author: CCORE
 * @Date: 2024-02-12
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety Test Service inject C File
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
#include "saf_testservice_inject.h"/*PRQA S 0380*/
#include "saf_osc.h"
#include "saf_crc.h"
#include "saf_pmc.h"
#include "saf_mpu.h"
#include "saf_smpu.h"
#include "saf_intc.h"
#include "saf_flash.h"
#include "saf_ram.h"
#include "Saf_MemMap.h"
#include "ErrorHandler_Swc.h"
/*PRQA S 1861,4397,4434,4542,3200,2052 EOF*/
#define FS_OSC_IRCOSC_FREQ_CHECK_FAULT_INJ_ERR_SIZE         (10000000U)

SAF_SEC_VAR_INIT
static uint32_t s_ircoscFaultInjFreqBackup = 0;

/**
****************************************************************************************
 * @brief: Global Function
****************************************************************************************
*/
#if SAF_CACHE_SUPPORTED
SAF_SEC_CODE
FS_STATUS SAF_UserService_CacheEdcTest(void)
{
    FS_STATUS result = FS_STATUS_SUCCESS;
    saf_cache_edc_report_path_test_result_t InjectResult;

    InjectResult.dcacheTestPassed = 0U;
    InjectResult.icacheTestPassed = 0U;
   
    result = SAF_CACHE_EdcReportPathTest();

    if(FS_STATUS_SUCCESS != result)
    {
    	if (s_cacheCallSet.callback != NULL)
    	{
    		s_cacheCallSet.callback(s_cacheCallSet.callbackParam);
    	}
    }

    if(FS_STATUS_SUCCESS == result)
    {
        result = SAF_CACHE_EdcReportPathTestResult(&InjectResult);
    }

    return result;
}
#endif

SAF_SEC_CODE
FS_STATUS SAF_UserService_StackMonitorTest(void)
{
    FS_STATUS result = FS_STATUS_SUCCESS;
    saf_stack_monitor_test_result_t InjectResult;

    InjectResult.overflowPassed = 0U;
    InjectResult.underflowPassed = 0U;
    
    result = SAF_STACK_MonitorTest();

    if(FS_STATUS_SUCCESS == result)
    {
        result = SAF_STACK_MonitorTestResult(&InjectResult);
    }

    
    return result;
}


#if SAF_MPU_SUPPORTED
SAF_SEC_CODE
FS_STATUS SAF_UserService_MpuAccessRightTest(void)
{
    FS_STATUS result = FS_STATUS_SUCCESS;
    saf_mpu_access_right_test_result_t InjectResult;

    InjectResult.readLimitPassed = 0U;
    InjectResult.writeLimitPassed = 0U;

    result = SAF_MPU_AccessRightTest();

    if(FS_STATUS_SUCCESS != result)
    {
        ErrorHandler_ResetAndReport(ERRORID_MCU_STARTUP_INJ_CMPU);
    	if (s_mpuCallSet.callback != NULL)
    	{
    		s_mpuCallSet.callback(s_mpuCallSet.callbackParam);
    	}
    }

    if(FS_STATUS_SUCCESS == result)
    {
        result = SAF_MPU_AccessRightTestResult(&InjectResult);
    }

    return result;
}
#endif

#if SAF_SMPU_SUPPORTED
SAF_SEC_CODE
FS_STATUS SAF_UserService_SmpuAccessRightTest(void)
{
    FS_STATUS result = FS_STATUS_SUCCESS;
    saf_smpu_access_right_test_result_t InjectResult;

    InjectResult.readLimitPassed = 0U;
    InjectResult.writeLimitPassed = 0U;

    result = SAF_SMPU_AccessRightTest();

    if(FS_STATUS_SUCCESS != result)
    {
    	if (s_smpuCallSet.callback != NULL)
    	{
    		s_smpuCallSet.callback(s_smpuCallSet.callbackParam);
    	}
    }

    if(FS_STATUS_SUCCESS == result)
    {
        result = SAF_SMPU_AccessRightTestResult(&InjectResult);
    }

    return result;
}
#endif

SAF_SEC_CODE
void SAF_IrcoscFreqMonitorFaultInj(void)
{
	if (FS_STATUS_SUCCESS == SAF_OSC_GetIrcoscMgrFreq(&s_ircoscFaultInjFreqBackup))
	{
		SAF_OSC_SetIrcoscMgrFreq(s_ircoscFaultInjFreqBackup + FS_OSC_IRCOSC_FREQ_CHECK_FAULT_INJ_ERR_SIZE);
		SAF_OSC_IrcoscFreqAccuracyTest();
	}
}

SAF_SEC_CODE
void SAF_IrcoscFreqMonitorFaultRestore(void)
{
	SAF_OSC_SetIrcoscMgrFreq(s_ircoscFaultInjFreqBackup);
	SAF_OSC_IrcoscFreqAccuracyTest();

}

SAF_SEC_CODE
void SAF_CRCReadBackFaultInj(void)
{
	uint8_t tempvalue = 0;

	/*xbar*/
	tempvalue = XBAR_0.PORT[7].CRS.B.HPE0;/* polyspace RTE:NIV */
	tempvalue = ~tempvalue & 0x01;
	XBAR_0.PORT[7].CRS.B.HPE0 = tempvalue;

	/*PIT*/
	tempvalue = PIT_0.MCR.B.FRZ;
	tempvalue = ~tempvalue & 0x01;
	PIT_0.MCR.B.FRZ = tempvalue;

	/*CMU*/
	tempvalue = CMU_ADCSAR.CSR.B.CME;
	tempvalue = ~tempvalue & 0x01;
	CMU_ADCSAR.CSR.B.CME = tempvalue;
	/*EMIOS*/
	tempvalue = EMIOS_0.MCR.B.FRZ;
	tempvalue = ~tempvalue & 0x01;
	EMIOS_0.MCR.B.FRZ = tempvalue;

	/*EMIOS*/
//	tempvalue = ETPU_AB_CR_ENG1.CHAN[0].CR.B.ODIS;
//	tempvalue = ~tempvalue & 0x01;
//	ETPU_AB_CR_ENG1.CHAN[0].CR.B.ODIS = tempvalue;

	/*EQADC0*/
#if defined(CCFC3008PC) | defined(CCFC3008PCSN)
	tempvalue = EQADC1_ADC23.MCR.B.DAM;
#else
	tempvalue = EQADC0_ADC01.MCR.B.DAM;
#endif
	tempvalue = ~tempvalue & 0x01;
#if defined(CCFC3008PC) | defined(CCFC3008PCSN)
	EQADC1_ADC23.MCR.B.DAM = tempvalue;
#else
	EQADC0_ADC01.MCR.B.DAM = tempvalue;
#endif

	/*SDADC*/
//	tempvalue = SDADC_0.MCR.B.EN;
//	tempvalue = ~tempvalue & 0x01;
//	SDADC_0.MCR.B.EN = tempvalue;

	/*PMC*/
	tempvalue = PMCDIG.REE_VD3.B.LVD3_C;
	tempvalue = ~tempvalue & 0x01;
	PMCDIG.REE_VD3.B.LVD3_C = tempvalue;

#ifndef CCFC3012PT
	/*SIUL2*/
	tempvalue = SIUL2.SCR0.B.FEC_MODE;
	tempvalue = ~tempvalue & 0x01;
	SIUL2.SCR0.B.FEC_MODE = tempvalue;
#endif
}

#if SAF_ITCM_SUPPORTED
SAF_SEC_CODE
FS_STATUS SAF_UserService_ITCMEccTest(void)
{
    FS_STATUS result = FS_STATUS_SUCCESS;

    result = SAF_RAM_ITCMEccReportPathTest();

    return result;
}
#endif

SAF_SEC_CODE
FS_STATUS SAF_UserService_IntcMonitorTest(void)
{
    FS_STATUS result = FS_STATUS_SUCCESS;

    result = SAF_INTC_MonitorReportPathTest();

    return result;
}

SAF_SEC_CODE
void SAF_UserInject_StartupTest(void)
{
    (void) SAF_UserService_MpuAccessRightTest();
}
