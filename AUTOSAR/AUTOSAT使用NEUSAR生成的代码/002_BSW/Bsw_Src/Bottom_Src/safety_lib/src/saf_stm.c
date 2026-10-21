/**
****************************************************************************************
 * @FilePath: saf_stm.c
 * @Author: CCORE
 * @Date: 2024-02-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety stm C File
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

#include "saf_swt.h"/*PRQA S 0380*/
#include "saf_stm.h"
#include "saf_pit.h"
#include "console.h"
#include "Saf_MemMap.h"
/*PRQA S 0315,0491,0492,0686,0704,1881,2844,2934,2976,3200,3119,3344,3401,4304,4404,4424 EOF*/
/**
****************************************************************************************
 * @brief: Local Variables
****************************************************************************************
*/
SAF_STM_SEC_VAR_INIT
static saf_stm_timer_monitor_t s_stmTimerMonitor =
{
    .initialized = (bool)false,
};/*PRQA S 0704*/
SAF_STM_SEC_VAR_INIT
static saf_stm_timer_monitor_test_result_t s_stmMonitorTest =
{
	.configured         		= {SAF_STM_CONFIG_UNINIT},/*PRQA S 0686*/
	.stmTimerMaxErrRang         = {{0}},
	.stmTimerNotAccurateBitmap  = {0},
    .stmTimerMonitorFailedBitmap = {{0}},
};
SAF_STM_SEC_VAR_INIT
static saf_stm_monitor_timer_data_t s_stmObject =
{
    .timerConfigured = {false},
    .timerEnable = {false},
    .stmPeriodUs = SAF_STM_TIMER_MONITOR_PERIOD_US,
    .curTimerCounter = {0},
};

/**
****************************************************************************************
 * @brief: Local Function Prototypes
****************************************************************************************
*/

static void SAF_STM_AccessMonitorInit(void);

/**
****************************************************************************************
 * @brief: Local Functions
****************************************************************************************
*/
/**
****************************************************************************************
* @brief: [SW_74]This function initializes the data of the monitoring STM timer.
* @return void.
****************************************************************************************
*/
SAF_STM_SEC_CODE
static void SAF_STM_AccessMonitorInit(void)
{
    saf_stm_timer_monitor_t *pStmMonitor = &s_stmTimerMonitor;
    uint8_t stmChanCountList[] = SAF_STM_CHAN_COUNT_LIST;/*PRQA S 3604*/
    uint8_t stmInst, chan;

    if (false == pStmMonitor->initialized)
    {
        pStmMonitor->initialized = (bool)true;
        for (stmInst = 0; stmInst < SAF_STM_INSTANCE_COUNT; stmInst++)
        {
            /* the first time to clean env */
            for (chan = 0; chan < stmChanCountList[stmInst]; chan++)
            {
                pStmMonitor->monitorTimerPeriod[stmInst][chan] = 0;
                pStmMonitor->monitorTimerErrRange[stmInst][chan] = 0;
                pStmMonitor->monitorTimerNo[stmInst][chan] = SAF_STM_DEFAULT_NUMBER;
                pStmMonitor->monitorTimerEnable[stmInst][chan] = false;
                pStmMonitor->monitorTimerAccuracy[stmInst][chan] = true;
                pStmMonitor->monitorTimerMaxErrUs[stmInst][chan] = 0;
                pStmMonitor->monitorTimerWell[stmInst][chan] = true;
            }
        }
    }
}

/**
****************************************************************************************
* @brief[SW_74] This function is used to get the monitor stm counter.
* @param[in] timerNo: The index of the monitored timer.
* @param[in] pCounter: Counter value.
* @return status
            FS_STATUS_SUCCESS: Get counter success.
            FS_STATUS_ERROR: Get counter failed.
****************************************************************************************
*/
SAF_STM_SEC_CODE
static FS_STATUS SAF_STM_AccessGetMonitorTimerCounter(const uint32_t timerNo, uint32_t *pCounter)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_stm_monitor_timer_data_t *pStmObj = &s_stmObject;

    if (timerNo >= SAF_STM_MONITOR_TIMER_NUM)
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
        *pCounter = pStmObj->curTimerCounter[timerNo];
        pStmObj->curTimerCounter[timerNo] = 0;
    }

    return status;
}

/**
****************************************************************************************
 * @brief: Global Functions
****************************************************************************************
*/
/**
****************************************************************************************
* @brief: [SW_74]This function is the STM interrupt callback function.
* @param[in] stmInst: stm instance.
* @param[in] chan: stm channel id.
* @return void.
****************************************************************************************
*/
SAF_STM_SEC_CODE
void SAF_STM_IrqHandler(const uint8_t stmInst,const uint8_t chan)
{
    SAF_STM_DET_ERR((uint8)stmInst < (uint8)GPT_STM_MODULE_MAX);
    SAF_STM_DET_ERR((uint8)chan < (uint8)GPT_STM_CHANNEL_MAX);
    uint32_t realPeriodUs = 0;
    uint32_t expectedPeriodUs = 0;
    uint32_t expectedRangUs = 0;
    uint32_t errRangeUs = 0;
    uint32_t i = 0;

	if (true == s_stmTimerMonitor.monitorTimerEnable[stmInst][chan])
	{
		/* monitor part */
		if (FS_STATUS_SUCCESS != SAF_PIT_GetMonitorTimerPeriodUs(s_stmTimerMonitor.monitorTimerNo[stmInst][chan], &realPeriodUs))
        {
            s_stmTimerMonitor.monitorTimerWell[stmInst][chan] = false;
        }
        else
        {
			expectedPeriodUs = s_stmTimerMonitor.monitorTimerPeriod[stmInst][chan];
			expectedRangUs   = s_stmTimerMonitor.monitorTimerErrRange[stmInst][chan];

			errRangeUs = (realPeriodUs < expectedPeriodUs) ? /*PRQA S 3401,3396*/
						  expectedPeriodUs - realPeriodUs :
						  realPeriodUs - expectedPeriodUs;
			if (errRangeUs > expectedRangUs)
			{
				s_stmTimerMonitor.monitorTimerAccuracy[stmInst][chan] = (bool)false;
				/* update the max err range US */
				if (errRangeUs > s_stmTimerMonitor.monitorTimerMaxErrUs[stmInst][chan])
				{
					s_stmTimerMonitor.monitorTimerMaxErrUs[stmInst][chan] = errRangeUs;
				}
			}
		}
	}

    if(true == s_stmObject.MonitorEnable[stmInst][chan])
    {
        for (i = 0; i < SAF_STM_MONITOR_TIMER_NUM; i++)
        {
            if (s_stmObject.timerEnable[i])
            {
                s_stmObject.curTimerCounter[i]++;
            }
        }
    }
}

/**
****************************************************************************************
* @brief: [SW_74]This function is used for STM safety test initialization.
* @return FS_STATUS: FS_STATUS_SUCCESS :initialization success.
*                   FS_STATUS_ERROR :initialization failed.
****************************************************************************************
*/
SAF_STM_SEC_CODE
FS_STATUS SAF_StmRuntimeSafetyTestInit(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_stm_timer_monitor_test_result_t stmTimerMonitorObj;

    status = SAF_STM_ConfigDataInit();

    if (FS_STATUS_SUCCESS == status)
    {
    	stmTimerMonitorObj.configured[SAF_STM_TEST_INSTANCE] = SAF_STM_CONFIG_INIT;

    	status = SAF_STM_TimerMonitorTestInit(&stmTimerMonitorObj);
    }

    return status;
}

/**
****************************************************************************************
* @brief: [SW_74]This function is used to initialize the monitoring STM data and test environment.
* @param[in] stmInst: stm instance.
* @param[in] pMonitorTimer: Configuration of the stm timer.
* @param[in] ChanNumber: stm channel number.
* @return FS_STATUS: FS_STATUS_SUCCESS :initialization success.
*                   FS_STATUS_ERROR :initialization failed.
****************************************************************************************
*/
SAF_STM_SEC_CODE
FS_STATUS SAF_STM_ConfigDataInit(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint8_t stmInst = SAF_STM_TEST_INSTANCE;
    uint8_t ChanNumber = SAF_STM_TEST_USED_CHANNEL;
    s_stmMonitorTest.configured[SAF_STM_TEST_INSTANCE] = SAF_STM_CONFIG_INIT_ERROR;
    const saf_stm_timer_config_data_t *pMonitorTimer = &s_SafStmTimerConfig[0];
    saf_stm_timer_monitor_t *pStmMonitor = &s_stmTimerMonitor;
    saf_stm_monitor_timer_data_t *pStmMonitorData = &s_stmObject;
    uint32_t errRangeUs = 0;
    uint8_t chan = 0;
    uint8_t i = 0;

    SAF_STM_AccessMonitorInit();

    for (i = 0; i < ChanNumber; i++)
    {
        chan = pMonitorTimer[i].chan;/*PRQA S 4461*/

        pStmMonitorData->MonitorEnable[stmInst][chan]        = pMonitorTimer[i].MonitorEnable;
        if(false == pStmMonitorData->MonitorEnable[stmInst][chan])
        {
            errRangeUs = pMonitorTimer[i].periodErrRangeRatio * pMonitorTimer[i].periodUs / SAF_STM_FULL_RANGE;/*PRQA S 0491,3393*/
            if (SAF_PIT_TIMER_MONITOR_PERIOD_US > errRangeUs)
            {
                errRangeUs = SAF_PIT_TIMER_MONITOR_PERIOD_US;
            }
            pStmMonitor->monitorTimerAccuracy[stmInst][chan] = true;
            pStmMonitor->monitorTimerWell[stmInst][chan]     = true;
            pStmMonitor->monitorTimerMaxErrUs[stmInst][chan] = 0;
            pStmMonitor->monitorTimerPeriod[stmInst][chan]   = pMonitorTimer[i].periodUs;
            pStmMonitor->monitorTimerErrRange[stmInst][chan] = errRangeUs;

            if (true == pMonitorTimer[i].needToMonitor)
            {
                pStmMonitor->monitorTimerEnable[stmInst][chan]   = true;
                /*add STM timer into PIT monitor module*/
                status = SAF_PIT_AddMonitorTimer(&pStmMonitor->monitorTimerNo[stmInst][chan]);
            }
            if (FS_STATUS_SUCCESS == status)
            {
                if (true == pStmMonitor->monitorTimerEnable[stmInst][chan])
                {
                    status = SAF_PIT_EnableMonitorTimer(pStmMonitor->monitorTimerNo[stmInst][chan]);
                }
            }
        }
    }

    if (FS_STATUS_SUCCESS == status)
    {
        s_stmMonitorTest.configured[SAF_STM_TEST_INSTANCE] = SAF_STM_CONFIG_INIT;
    }

    return status;
}
/**
****************************************************************************************
* @brief: [SW_74]This function initializes the STM timer test parameters.
* @param[in] pTestConfig: test parameters.
* @return FS_STATUS: FS_STATUS_SUCCESS :initializes success.
*                   FS_STATUS_ERROR :initializes failed.
****************************************************************************************
*/
SAF_STM_SEC_CODE
FS_STATUS SAF_STM_TimerMonitorTestInit(const saf_stm_timer_monitor_test_result_t *pTestConfig)
{
    FS_STATUS status = FS_STATUS_ERROR;
    if (pTestConfig != NULL)
    {
        memcpy(&s_stmMonitorTest, pTestConfig, sizeof(s_stmMonitorTest));
        status = FS_STATUS_SUCCESS;
    }

    return status;
}
/**
****************************************************************************************
* @brief: [SW_74]This function is used to get the STM test results.
* @param[out] pTestResult: test parameters.
* @return FS_STATUS: FS_STATUS_SUCCESS :get results success.
*                   FS_STATUS_ERROR :get results failed.
****************************************************************************************
*/
SAF_STM_SEC_CODE
FS_STATUS SAF_STM_TimerMonitorTestResult(saf_stm_timer_monitor_test_result_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;
    if (pTestResult != NULL)
    {
        memcpy(pTestResult, &s_stmMonitorTest, sizeof(s_stmMonitorTest));
        status = FS_STATUS_SUCCESS;
    }

    return status;
}

/**
****************************************************************************************
* @brief: [SW_74]This function is used to STM monitor tests and update test results.
* @return FS_STATUS: FS_STATUS_SUCCESS :test success.
*                   FS_STATUS_ERROR :test failed.
****************************************************************************************
*/
SAF_STM_SEC_CODE
FS_STATUS SAF_STM_TimerMonitorTest(void)
{
    saf_stm_timer_monitor_test_result_t *pResult = &s_stmMonitorTest;
    saf_stm_timer_monitor_t *pStmMonitor = &s_stmTimerMonitor;
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint8_t chan, stmInst;
    uint8_t stmChanCountList[] = SAF_STM_CHAN_COUNT_LIST;/*PRQA S 3604*/

    if (pStmMonitor->initialized == (bool)false)
	{
    	status = SAF_StmRuntimeSafetyTestInit();
	}

    for (stmInst = 0; stmInst < SAF_STM_INSTANCE_COUNT; stmInst++)
    {
        pResult->stmTimerNotAccurateBitmap[stmInst] = 0;

        if (SAF_STM_CONFIG_UNINIT == pResult->configured[stmInst])
        {
            continue;
        }

        for (chan = 0; chan < stmChanCountList[stmInst]; chan++)
        {
            if (pStmMonitor->monitorTimerAccuracy[stmInst][chan] == (bool)false)
            {

                pStmMonitor->monitorTimerAccuracy[stmInst][chan] = (bool)true;
                pResult->stmTimerNotAccurateBitmap[stmInst] |= (0x1UL << chan);
                pResult->stmTimerMaxErrRang[stmInst][chan] = pStmMonitor->monitorTimerMaxErrUs[stmInst][chan];
                pStmMonitor->monitorTimerMaxErrUs[stmInst][chan] = 0;
                status = FS_STATUS_ERROR;
            }

        } 
    }
    
    return status;
}

/**
****************************************************************************************
* @brief[SW_74] This function is used to add one stm monitor timer.
* @param[in] pTimerNo: The index of the monitored timer.
* @return status
            FS_STATUS_SUCCESS: Add monitor timer success.
            FS_STATUS_ERROR: Add monitor timer failed.
****************************************************************************************
*/
SAF_STM_SEC_CODE
FS_STATUS SAF_STM_AddMonitorTimer(uint32_t *pTimerNo)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_stm_monitor_timer_data_t *pStmObj = &s_stmObject;
    uint32_t i;

    for (i = 0; i < SAF_STM_MONITOR_TIMER_NUM; i++)
    {
        if (false == pStmObj->timerConfigured[i])
        {
            pStmObj->timerConfigured[i] = true;
            *pTimerNo = i;
            break;
        }
    }

    if (i == SAF_STM_MONITOR_TIMER_NUM)
    {
        status = FS_STATUS_ERROR;
    }

    return status;
}

/**
****************************************************************************************
* @brief[SW_74] This function is used to delete one stm monitor timer.
* @param[in] timerNo: The index of the monitored timer.
* @return status
            FS_STATUS_SUCCESS: Delete monitor timer success.
            FS_STATUS_ERROR: Delete monitor timer failed.
****************************************************************************************
*/
SAF_STM_SEC_CODE
FS_STATUS SAF_STM_DeleteMonitorTimer(const uint32_t timerNo)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_stm_monitor_timer_data_t *pStmObj = &s_stmObject;

    if (timerNo >= SAF_STM_MONITOR_TIMER_NUM)
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
        pStmObj->timerEnable[timerNo]     = false;
        pStmObj->timerConfigured[timerNo] = false;
    }

    return status;
}

/**
****************************************************************************************
* @brief[SW_74] This function will be used to enable monitor timer.
* @param[in] timerNo: The index of the monitored timer.
* @return status
            FS_STATUS_SUCCESS: Enable monitor timer success.
            FS_STATUS_ERROR: Enable monitor timer failed.
****************************************************************************************
*/
SAF_STM_SEC_CODE
FS_STATUS SAF_STM_EnableMonitorTimer(const uint32_t timerNo)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_stm_monitor_timer_data_t *pStmObj = &s_stmObject;

    if (timerNo >= SAF_STM_MONITOR_TIMER_NUM)
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
        pStmObj->timerEnable[timerNo] = true;
        pStmObj->curTimerCounter[timerNo] = 0;
    }

    return status;
}

/**
****************************************************************************************
* @brief[SW_74] This function will be used to disable monitor timer.
* @param[in] timerNo: The index of the monitored timer.
* @return status
            FS_STATUS_SUCCESS: Disable monitor timer success.
            FS_STATUS_ERROR: Disable monitor timer failed.
****************************************************************************************
*/
SAF_STM_SEC_CODE
FS_STATUS SAF_STM_DisableMonitorTimer(const uint32_t timerNo)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_stm_monitor_timer_data_t *pStmObj = &s_stmObject;

    if (timerNo >= SAF_STM_MONITOR_TIMER_NUM)
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
        pStmObj->timerEnable[timerNo] = false;
    }

    return status;
}

/**
****************************************************************************************
* @brief[SW_74] This function is used to get the period of the monitor timer.
* @param[in] timerNo: The index of the monitored timer.
* @param[in] periodUs: Monitor timer period.
* @return status
            FS_STATUS_SUCCESS: Get monitor timer period success.
            FS_STATUS_ERROR: Get monitor timer period failed.
****************************************************************************************
*/
SAF_STM_SEC_CODE
FS_STATUS SAF_STM_GetMonitorTimerPeriodUs(uint32_t timerNo, uint32_t *pPeriodUs)
{
    FS_STATUS status = FS_STATUS_ERROR;
    uint32_t counter;
    saf_stm_monitor_timer_data_t *pStmObj = &s_stmObject;

    if (FS_STATUS_SUCCESS == SAF_STM_AccessGetMonitorTimerCounter(timerNo, &counter))
    {
        *pPeriodUs = counter * pStmObj->stmPeriodUs;
        status = FS_STATUS_SUCCESS;
    }

    return status;
}

/**
****************************************************************************************
* @brief: [SW_74]This function is Stm 0 channel 0 interrupt handler function.
* @return void.
****************************************************************************************
*/
SAF_STM_SEC_CODE
void SAF_STM_Stm0Chan0Handler(void)
{
   SAF_STM_IrqHandler(STM0,STM_Channel0);
}
/**
****************************************************************************************
* @brief: [SW_74]This function is Stm 0 channel 1 interrupt handler function.
* @return void.
****************************************************************************************
*/
SAF_STM_SEC_CODE
void SAF_STM_Stm0Chan1Handler(void)
{
   SAF_STM_IrqHandler(STM0,STM_Channel1);
}
/**
****************************************************************************************
* @brief: [SW_74]This function is Stm 0 channel 2 interrupt handler function.
* @return void.
****************************************************************************************
*/
SAF_STM_SEC_CODE
void SAF_STM_Stm0Chan2Handler(void)
{
   SAF_STM_IrqHandler(STM0,STM_Channel2);
}
/**
****************************************************************************************
* @brief: [SW_74]This function is Stm 0 channel 3 interrupt handler function.
* @return void.
****************************************************************************************
*/
SAF_STM_SEC_CODE
void SAF_STM_Stm0Chan3Handler(void)
{
   SAF_STM_IrqHandler(STM0,STM_Channel3);
}
/**
****************************************************************************************
* @brief: [SW_74]This function is Stm 1 channel 0 interrupt handler function.
* @return void.
****************************************************************************************
*/
SAF_STM_SEC_CODE
void SAF_STM_Stm1Chan0Handler(void)
{
   SAF_STM_IrqHandler(STM1,STM_Channel0);
}
/**
****************************************************************************************
* @brief: [SW_74]This function is Stm 1 channel 1 interrupt handler function.
* @return void.
****************************************************************************************
*/
SAF_STM_SEC_CODE
void SAF_STM_Stm1Chan1Handler(void)
{
   SAF_STM_IrqHandler(STM1,STM_Channel1);
}
/**
****************************************************************************************
* @brief: [SW_74]This function is Stm 1 channel 2 interrupt handler function.
* @return void.
****************************************************************************************
*/
SAF_STM_SEC_CODE
void SAF_STM_Stm1Chan2Handler(void)
{
   SAF_STM_IrqHandler(STM1,STM_Channel2);
}
/**
****************************************************************************************
* @brief: [SW_74]This function is Stm 1 channel 3 interrupt handler function.
* @return void.
****************************************************************************************
*/
SAF_STM_SEC_CODE
void SAF_STM_Stm1Chan3Handler(void)
{
   SAF_STM_IrqHandler(STM1,STM_Channel3);
}
/**
****************************************************************************************
* @brief: [SW_74]This function is Stm 2 channel 0 interrupt handler function.
* @return void.
****************************************************************************************
*/
SAF_STM_SEC_CODE
void SAF_STM_Stm2Chan0Handler(void)
{
   SAF_STM_IrqHandler(STM2,STM_Channel0);
}
/**
****************************************************************************************
* @brief: [SW_74]This function is Stm 2 channel 1 interrupt handler function.
* @return void.
****************************************************************************************
*/
SAF_STM_SEC_CODE
void SAF_STM_Stm2Chan1Handler(void)
{
   SAF_STM_IrqHandler(STM2,STM_Channel1);
}
/**
****************************************************************************************
* @brief: [SW_74]This function is Stm 2 channel 2 interrupt handler function.
* @return void.
****************************************************************************************
*/
SAF_STM_SEC_CODE
void SAF_STM_Stm2Chan2Handler(void)
{
   SAF_STM_IrqHandler(STM2,STM_Channel2);
}
/**
****************************************************************************************
* @brief: [SW_74]This function is Stm 2 channel 3 interrupt handler function.
* @return void.
****************************************************************************************
*/
SAF_STM_SEC_CODE
void SAF_STM_Stm2Chan3Handler(void)
{
   SAF_STM_IrqHandler(STM2,STM_Channel3);
}

SAF_STM_SEC_CODE
boolean SAF_StmstatusCheck_Stm0Chan0()
{
    uint32_t stmCirValue = 0;
    boolean ret = false;
    stmCirValue = Gpt_Stm_LLD_GetIntFlag((STM_ModuleID_Type)STM0, (STM_ChannelID_Type)STM_Channel0);/*PRQA S 1411,1296*/
    ret = (0x0UL != stmCirValue ) ? true : false;

    return ret;
}


#ifdef __cplusplus
}
#endif
