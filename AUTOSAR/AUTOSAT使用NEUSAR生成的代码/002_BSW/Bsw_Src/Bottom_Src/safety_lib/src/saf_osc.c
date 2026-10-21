/**
****************************************************************************************
 * @FilePath: saf_osc.c
 * @Author: CCORE
 * @Date: 2024-02-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: Safety OSC C Source File
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
#include "saf_osc.h"/*PRQA S 0380*/
#include "saf_cmu.h"
#include "Saf_MemMap.h"
/*PRQA S 0315,2052,3200,4116,4304,4404,4558 EOF*/

/*******************************************************************************
 * Variables
 ******************************************************************************/

SAF_OSC_SEC_VAR_NO_INIT
static saf_osc_ircosc_freq_check_test_result_t s_ircoscFreqCheckTest;
SAF_OSC_SEC_VAR_NO_INIT
static saf_osc_xosc_sys_clk_test_result_t s_xoscSysClkSrcCheckTest;
SAF_OSC_SEC_VAR_NO_INIT
static uint32_t saf_ircoscFreq;

/*******************************************************************************
 * Local Functions
 ******************************************************************************/

/**
****************************************************************************************
* @brief:  This function is used to detects if the system clock source is XOSC..
* @param[in]    Void
* @return       status		test result
****************************************************************************************
*/
SAF_OSC_SEC_CODE
static FS_STATUS SAF_OSC_AccessSysClkSrcIsXosc(SAF_CLOCK_SOURCE_TYPE clkType)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    if((SAF_CLOCK_SOURCE_IS_IRCOSC == clkType) || (SAF_CLOCK_SOURCE_IS_DISABLED == clkType))
    {
        status = FS_STATUS_ERROR;
    }
    else if((SAF_CLOCK_SOURCE_IS_FMPLL == clkType) || (SAF_CLOCK_SOURCE_IS_NON_FMPLL == clkType))
    {
        /*Non_FMPLL clock source should be configured as XOSC*/
        if(SAF_CLOCK_SOURCE_IS_XOSC != SAF_MCU_ClkGetClkSrc(SAF_NON_FMPLL_CLK))
        {
            status = FS_STATUS_ERROR;
        }
    }
    else
    {
    	status = FS_STATUS_ERROR;
    }

    return status;
}

/*******************************************************************************
 * Global Functions
 ******************************************************************************/

/**
****************************************************************************************
* @brief:  This function is used to detects if the XOSC frequency is stable.
* @param[in]    Void
* @return       status		test result
****************************************************************************************
*/
SAF_OSC_SEC_CODE
FS_STATUS SAF_OSC_XoscFreqIsStable(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    if(GS_S_OSC_STABLE != MC_ME.GS.B.S_XOSC)
    {
        status = SAF_STATUS_XOSC_NOT_SATBLE;
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to detects if the Irc osc frequency is stable.
* @param[in]    Void
* @return       status		test result
****************************************************************************************
*/
SAF_OSC_SEC_CODE
FS_STATUS SAF_OSC_IrcoscFreqIsStable(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    if(GS_S_OSC_STABLE != MC_ME.GS.B.S_IRC)
    {
        status = SAF_STATUS_IRCOSC_NOT_SATBLE;
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to get IRCOSC frequency.
* @param[in]    freq		point of irc osc frequence
* @return       status		get result
****************************************************************************************
*/
SAF_OSC_SEC_CODE
FS_STATUS SAF_OSC_GetIrcoscMgrFreq(uint32_t *pFreq)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (pFreq != NULL)
    {
        if (saf_ircoscFreq != 0)/*PRQA S 1843*/
        {
            *pFreq = saf_ircoscFreq;
            status = FS_STATUS_SUCCESS;
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to set IRCOSC frequency.
* @param[in]    freq		irc osc set frequence
* @return       status		set result
****************************************************************************************
*/
SAF_OSC_SEC_CODE
FS_STATUS SAF_OSC_SetIrcoscMgrFreq(uint32_t freq)
{
	saf_ircoscFreq = freq;

    return FS_STATUS_SUCCESS;
}

/**
****************************************************************************************
* @brief:  This function is used to execute IRCOSC frequency accuracy test.
* @param[in]    void
* @return       status		test result
****************************************************************************************
*/
SAF_OSC_SEC_CODE
FS_STATUS SAF_OSC_IrcoscFreqAccuracyTest(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint32_t realFreq, expectedFreq, expectedFreqMax, expectedFreqMin;

    /*1.get ircoscFreq allowed arrange and expectedFreq*/
    expectedFreq = saf_ircoscFreq;
	expectedFreqMax = expectedFreq + saf_osc_kConfigSet.ircoscMaxMargin;
	expectedFreqMin = expectedFreq - saf_osc_kConfigSet.ircoscMinMargin;

    s_ircoscFreqCheckTest.checkPassed = (bool)false;
    /*2.get ircoscFreqmeasured value*/
    if (FS_STATUS_SUCCESS != SAF_CMU_IrcoscFreqMeasure(&realFreq))
    {
        status = SAF_STATUS_XOSC_TEST_FAILED;
    }
    else
    {
        s_ircoscFreqCheckTest.realIrcoscFreq = realFreq;
		if((realFreq <= expectedFreqMax) && (realFreq >= expectedFreqMin))
        {
            s_ircoscFreqCheckTest.checkPassed = (bool)true;
        }
		else
		{
			status = SAF_STATUS_XOSC_OUT_RANGE;
		}
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to initialize IRCOSC frequency accuracy test.
* @param[in]    void
* @return       status		test result
****************************************************************************************
*/
SAF_OSC_SEC_CODE
void SAF_OSC_IrcoscFreqAccuracyInit(void)
{
    saf_ircoscFreq = FEATURE_IRCOSC0_FREQ;
}

/**
****************************************************************************************
* @brief:  This function is used to executes XOSC system clock source check test.
* @param[in]    void
* @return       status		test result
****************************************************************************************
*/
SAF_OSC_SEC_CODE
FS_STATUS SAF_OSC_XoscSysClkSrcCheckTest(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    SAF_CLOCK_SOURCE_TYPE clkType = SAF_CLOCK_SOURCE_IS_INVALID;

    /*1.check whether the system clock source is from XOSC*/
    s_xoscSysClkSrcCheckTest.sourceCheckPassed = true;

    clkType = SAF_MCU_ClkGetClkSrc(SAF_SYSTEM_CLK);
    if (FS_STATUS_ERROR == SAF_OSC_AccessSysClkSrcIsXosc(clkType))
    {
		s_xoscSysClkSrcCheckTest.sourceCheckPassed = false;
        status = FS_STATUS_ERROR;
    }

    return status;
}

/**
****************************************************************************************
* @brief:  		This function is used to get the OSC system clock source test results.
* @param[in]    pTestResult         test parameters.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     get results success
*               FS_STATUS_ERROR       get results failed
****************************************************************************************
*/
SAF_OSC_SEC_CODE
FS_STATUS SAF_OSC_GetSysClkSrcCheckResult(saf_osc_xosc_sys_clk_test_result_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (NULL != pTestResult)
    {
        memcpy(pTestResult, &s_xoscSysClkSrcCheckTest, sizeof(s_xoscSysClkSrcCheckTest));
        status = FS_STATUS_SUCCESS;
    }

    return status;
}


/**
****************************************************************************************
* @brief:  		This function is used to get the OSC Frequence check test results.
* @param[in]    pTestResult         test parameters.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     get results success
*               FS_STATUS_ERROR       get results failed
****************************************************************************************
*/
SAF_OSC_SEC_CODE
FS_STATUS SAF_OSC_GetFreqCheckResult(saf_osc_ircosc_freq_check_test_result_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (NULL != pTestResult)
    {
        memcpy(pTestResult, &s_ircoscFreqCheckTest, sizeof(s_ircoscFreqCheckTest));
        status = FS_STATUS_SUCCESS;
    }

    return status;
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
