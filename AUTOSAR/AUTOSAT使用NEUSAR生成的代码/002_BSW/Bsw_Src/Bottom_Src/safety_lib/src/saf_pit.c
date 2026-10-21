/**
****************************************************************************************
 * @FilePath: saf_pit.c
 * @Author: CCORE
 * @Date: 2024-02-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety pit C File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/

#ifdef __cplusplus
extern "C"{
#endif
/*PRQA S 0315,0491,0492,0686,0704,1257,1881,2844,2976 EOF*/
/*PRQA S 3119,3200,3344,3393,3401,3604 EOF*/
/*PRQA S 4304,4404,4416,4424,4558 EOF*/
/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/

#include "saf_pit.h"/*PRQA S 0380*/
#include "saf_stm.h"
#include "saf_swt.h"
#include "console.h"
#include "Saf_MemMap.h"
/**
****************************************************************************************
 * @brief: Local Variables
****************************************************************************************
*/
SAF_PIT_SEC_VAR_INIT
static saf_pit_timer_monitor_t s_pitTimerMonitor =
{
    .initialized = (bool)false,
};

SAF_PIT_SEC_VAR_INIT
static saf_pit_timer_monitor_test_result_t s_pitMonitorTest =
{
    .configured         = {SAF_PIT_CONFIG_UNINIT},
    .pitTimerMaxErrRang         = {{0}},
    .pitTimerNotAccurateBitmap  = {{0}},
    .pitTimerMonitorFailedBitmap = {{0}},
};
SAF_PIT_SEC_VAR_INIT
static saf_pit_monitor_timer_data_t s_pitObject =
{
    .timerConfigured = {false},
    .timerEnable = {false},
    .pitPeriodUs = SAF_PIT_TIMER_MONITOR_PERIOD_US,
    .curTimerCounter = {0},
};

/**
****************************************************************************************
 * @brief: Local Function Prototypes
****************************************************************************************
*/

static void SAF_PIT_AccessMonitorInit(void);

/**
****************************************************************************************
 * @brief: Local Functions
****************************************************************************************
*/
/**
****************************************************************************************
* @brief: [SW_73]This function initializes the data of the monitoring PIT timer.
* @return void.
****************************************************************************************
*/
SAF_PIT_SEC_CODE
static void SAF_PIT_AccessMonitorInit(void)
{
    saf_pit_timer_monitor_t *pPitMonitor = &s_pitTimerMonitor;
    uint8_t pitChanCountList[] = SAF_PIT_CHAN_COUNT;/*PRQA S 3604*/
    uint8_t pitInst = 0u;
    uint8_t chan = 0u;

    if (false == pPitMonitor->initialized)
    {
        pPitMonitor->initialized = (bool)true;
        for (pitInst = 0; pitInst < SAF_PIT_INSTANCE_COUNT; pitInst++)
        {
            for (chan = 0; chan < pitChanCountList[pitInst]; chan++)
            {
                pPitMonitor->callback[pitInst][chan] = NULL;
                pPitMonitor->monitorTimerPeriod[pitInst][chan] = 0;
                pPitMonitor->monitorTimerErrRange[pitInst][chan] = 0;
                pPitMonitor->monitorTimerNo[pitInst][chan] = SAF_PIT_DEFAULT_NUMBER;
                pPitMonitor->monitorTimerEnable[pitInst][chan] = (bool)false;
                pPitMonitor->monitorTimerAccuracy[pitInst][chan] = (bool)true;
                pPitMonitor->monitorTimerMaxErrUs[pitInst][chan] = 0;
                pPitMonitor->monitorTimerWell[pitInst][chan] = (bool)true;
            }
        }
    }
}

/**
****************************************************************************************
* @brief[SW_73] This function is used to get the monitor pit counter.
* @param[in] timerNo: The index of the monitored timer.
* @param[in] pCounter: Counter value.
* @return status
            FS_STATUS_SUCCESS: Get counter success.
            FS_STATUS_ERROR: Get counter failed.
****************************************************************************************
*/
static FS_STATUS SAF_PIT_AccessGetMonitorTimerCounter(const uint32_t timerNo, uint32_t *pCounter)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_pit_monitor_timer_data_t *pPitObj = &s_pitObject;

    if (timerNo >= SAF_PIT_MONITOR_TIMER_NUM)
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
        *pCounter = pPitObj->curTimerCounter[timerNo];
        pPitObj->curTimerCounter[timerNo] = 0;
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
* @brief: [SW_73]This function is the PIT interrupt callback function.
* @param[in] pitInst: pit instance.
* @param[in] chan: pit channel id.
* @return void.
****************************************************************************************
*/
SAF_PIT_SEC_CODE
void SAF_PIT_IrqHandler(const uint8_t pitInst,const uint8_t chan)
{

    SAF_PIT_DET_ERR((uint8)pitInst < (uint8)SAF_PIT_INSTANCE_COUNT);

    if (PIT0 == pitInst)
    {
        SAF_PIT_DET_ERR((uint8)chan < (uint8)SAF_PIT0_CHANNEL_COUNT);
    }
    else
    {
        SAF_PIT_DET_ERR((uint8)chan < (uint8)SAF_PIT1_CHANNEL_COUNT);
    }

    uint32_t realPeriodUs = 0;
    uint32_t expectedPeriodUs = 0;
    uint32_t expectedRangUs = 0;
    uint32_t errRangeUs = 0;
    uint32_t i;

	if (true == s_pitTimerMonitor.monitorTimerEnable[pitInst][chan])
	{
		if (FS_STATUS_SUCCESS != SAF_STM_GetMonitorTimerPeriodUs(s_pitTimerMonitor.monitorTimerNo[pitInst][chan],
																&realPeriodUs))
		{
            s_pitTimerMonitor.monitorTimerWell[pitInst][chan] = false;
		}
		{
			expectedPeriodUs = s_pitTimerMonitor.monitorTimerPeriod[pitInst][chan];
			expectedRangUs   = s_pitTimerMonitor.monitorTimerErrRange[pitInst][chan];
			errRangeUs = (realPeriodUs < expectedPeriodUs) ?/*PRQA S 3396,3401*/
						  expectedPeriodUs - realPeriodUs :
						  realPeriodUs - expectedPeriodUs;

			if (errRangeUs > expectedRangUs)
			{
				s_pitTimerMonitor.monitorTimerAccuracy[pitInst][chan] = (bool)false;
				if (errRangeUs > s_pitTimerMonitor.monitorTimerMaxErrUs[pitInst][chan])
				{
					s_pitTimerMonitor.monitorTimerMaxErrUs[pitInst][chan] = errRangeUs;
				}
			}
		}
	}

    if(true == s_pitObject.MonitorEnable[pitInst][chan])
    {
        for (i = 0; i < SAF_PIT_MONITOR_TIMER_NUM; i++)
        {
            if (s_pitObject.timerEnable[i])
            {
                s_pitObject.curTimerCounter[i]++;
            }
        }
    }
}

/**
****************************************************************************************
* @brief: [SW_73]This function is used for PIT safety test initialization.
* @return FS_STATUS: FS_STATUS_SUCCESS :initialization success.
*                    FS_STATUS_ERROR :initialization failed.
****************************************************************************************
*/
SAF_PIT_SEC_CODE
FS_STATUS SAF_PitRuntimeSafetyTestInit(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_pit_timer_monitor_test_result_t pitMonitorObj;

    status = SAF_PIT_ConfigDataInit();
    if (FS_STATUS_SUCCESS == status)
    {
    	 pitMonitorObj.configured[SAF_PIT_TEST_INSTANCE] = SAF_PIT_CONFIG_INIT;
    	 status = SAF_PIT_TimerMonitorTestInit(&pitMonitorObj);
    }

    return status;
}

/**
****************************************************************************************
* @brief: [SW_73]This function is used to initialize the monitoring PIT data and test environment.
* @param[in] pitInst: pit instance.
* @param[in] pMonitorTimer: Configuration of the pit timer.
* @param[in] ChanNumber: pit channel number.
* @return FS_STATUS: FS_STATUS_SUCCESS :initialization success.
*                    FS_STATUS_ERROR :initialization failed.
****************************************************************************************
*/
SAF_PIT_SEC_CODE
FS_STATUS SAF_PIT_ConfigDataInit(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint8_t pitInst = SAF_PIT_TEST_INSTANCE;
    uint32_t ChanNumber = SAF_PIT_TEST_USED_CHANNEL;
    s_pitMonitorTest.configured[SAF_PIT_TEST_INSTANCE] = SAF_PIT_CONFIG_INIT_ERROR;
    const saf_pit_timer_config_data_t *pMonitorTimer = &s_SafPitTimerConfig[0];
    saf_pit_timer_monitor_t *pPitMonitor   = &s_pitTimerMonitor;
    saf_pit_monitor_timer_data_t *pPitMonitorData = &s_pitObject;
    uint32_t errRangeUs;
    uint8_t chan = 0;
    uint8_t i = 0;

    SAF_PIT_AccessMonitorInit();

    for (i = 0; i < ChanNumber; i++)
    {
        chan = pMonitorTimer[i].chan;/*PRQA S 4461*/

        pPitMonitorData->MonitorEnable[pitInst][chan]        = pMonitorTimer[i].MonitorEnable;
        if(false == pPitMonitorData->MonitorEnable[pitInst][chan])
        {
            errRangeUs = pMonitorTimer[i].periodErrRangeRatio * pMonitorTimer[i].periodUs / SAF_PIT_FULL_RANGE;
            if (SAF_STM_TIMER_MONITOR_PERIOD_US > errRangeUs)
            {
                errRangeUs = SAF_STM_TIMER_MONITOR_PERIOD_US;
            }
            pPitMonitor->monitorTimerAccuracy[pitInst][chan] = true;
            pPitMonitor->monitorTimerWell[pitInst][chan]     = true;
            pPitMonitor->monitorTimerMaxErrUs[pitInst][chan] = 0;
            pPitMonitor->monitorTimerPeriod[pitInst][chan]   = pMonitorTimer[i].periodUs;
            pPitMonitor->monitorTimerErrRange[pitInst][chan] = errRangeUs;
            if (true == pMonitorTimer[i].needToMonitor)
            {
                pPitMonitor->monitorTimerEnable[pitInst][chan]   = true;
                /*add PIT timer into STM monitor module*/
                status = SAF_STM_AddMonitorTimer(&pPitMonitor->monitorTimerNo[pitInst][chan]);/*PRQA S 2934*/
            }
            if (FS_STATUS_SUCCESS == status)
            {
                if (true == pPitMonitor->monitorTimerEnable[pitInst][chan])
                {
                    status = SAF_STM_EnableMonitorTimer(pPitMonitor->monitorTimerNo[pitInst][chan]);
                }
            }
        }
    }

    if (FS_STATUS_SUCCESS == status)
    {
        s_pitMonitorTest.configured[SAF_PIT_TEST_INSTANCE] = SAF_PIT_CONFIG_INIT;
    }

    return status;
}

/**
****************************************************************************************
* @brief: [SW_73]This function initializes the PIT timer test parameters.
* @param[in] pTestConfig: test parameters.
* @return FS_STATUS: FS_STATUS_SUCCESS :initializes success.
*                    FS_STATUS_ERROR :initializes failed.
****************************************************************************************
*/
SAF_PIT_SEC_CODE
FS_STATUS SAF_PIT_TimerMonitorTestInit(const saf_pit_timer_monitor_test_result_t *pTestConfig)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (pTestConfig != NULL)
    {
        memcpy(&s_pitMonitorTest, pTestConfig, sizeof(s_pitMonitorTest));
        status = FS_STATUS_SUCCESS;
    }

    return status;
}
/**
****************************************************************************************
* @brief: [SW_73]This function is used to get the PIT test results.
* @param[out] pTestResult: test parameters.
* @return FS_STATUS: FS_STATUS_SUCCESS :get results success.
*               	 FS_STATUS_ERROR :get results failed.
****************************************************************************************
*/
SAF_PIT_SEC_CODE
FS_STATUS SAF_PIT_TimerMonitorTestResult(saf_pit_timer_monitor_test_result_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;
    
    if (pTestResult != NULL)
    {
        memcpy(pTestResult, &s_pitMonitorTest, sizeof(s_pitMonitorTest));
        status = FS_STATUS_SUCCESS;
    }

    return status;
}

/**
****************************************************************************************
* @brief: [SW_73]This function is used to PIT monitor tests and update test results.
* @return FS_STATUS: FS_STATUS_SUCCESS :test success.
*               	 FS_STATUS_ERROR :test failed.
****************************************************************************************
*/
SAF_PIT_SEC_CODE
FS_STATUS SAF_PIT_TimerMonitorTest(void)
{    
    saf_pit_timer_monitor_test_result_t *pResult = &s_pitMonitorTest;
    saf_pit_timer_monitor_t *pPitMonitor = &s_pitTimerMonitor;
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint8_t pitChanCountList[] = SAF_PIT_CHAN_COUNT;
    uint8_t chan = 0;
    uint8_t pitInst = 0;

    for (pitInst = 0; pitInst < SAF_PIT_INSTANCE_COUNT; pitInst++)
    {
        if (SAF_PIT_CONFIG_UNINIT  == pResult->configured[pitInst])
        {
            continue;
        }
        for (chan = 0; chan < pitChanCountList[pitInst]; chan++)
        {
            pResult->pitTimerNotAccurateBitmap[pitInst][chan] = 0;
            pResult->pitTimerMonitorFailedBitmap[pitInst][chan] = 0;

            if (false == pPitMonitor->monitorTimerAccuracy[pitInst][chan])
            {
                pPitMonitor->monitorTimerAccuracy[pitInst][chan] = true;
                pResult->pitTimerNotAccurateBitmap[pitInst][chan] = 0x1;
                pResult->pitTimerMaxErrRang[pitInst][chan] = pPitMonitor->monitorTimerMaxErrUs[pitInst][chan];
                pPitMonitor->monitorTimerMaxErrUs[pitInst][chan] = 0;
                status = FS_STATUS_ERROR;
            }

            if (false == pPitMonitor->monitorTimerWell[pitInst][chan])
            {
                pPitMonitor->monitorTimerWell[pitInst][chan] = true;
                pResult->pitTimerMonitorFailedBitmap[pitInst][chan] = 0x1;
                status = FS_STATUS_ERROR;
            }
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief[SW_73] This function is used to add one pit monitor timer.
* @param[in] pTimerNo: The index of the monitored timer.
* @return status
            FS_STATUS_SUCCESS: Add monitor timer success.
            FS_STATUS_ERROR: Add monitor timer failed.
****************************************************************************************
*/
SAF_PIT_SEC_CODE
FS_STATUS SAF_PIT_AddMonitorTimer(uint32_t *pTimerNo)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_pit_monitor_timer_data_t *pPitObj = &s_pitObject;
    uint32_t i;

    for (i = 0; i < SAF_PIT_MONITOR_TIMER_NUM; i++)
    {
        if (false == pPitObj->timerConfigured[i])
        {
            pPitObj->timerConfigured[i] = true;
            *pTimerNo = i;
            break;
        }
    }

    if (i == SAF_PIT_MONITOR_TIMER_NUM)
    {
        status = FS_STATUS_ERROR;
    }

    return status;
}

/**
****************************************************************************************
* @brief[SW_73] This function is used to delete one pit monitor timer.
* @param[in] timerNo: The index of the monitored timer.
* @return status
            FS_STATUS_SUCCESS: Delete monitor timer success.
            FS_STATUS_ERROR: Delete monitor timer failed.
****************************************************************************************
*/
SAF_PIT_SEC_CODE
FS_STATUS SAF_PIT_DeleteMonitorTimer(const uint32_t timerNo)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_pit_monitor_timer_data_t *pPitObj = &s_pitObject;

    if (timerNo >= SAF_PIT_MONITOR_TIMER_NUM)
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
        pPitObj->timerEnable[timerNo]     = false;
        pPitObj->timerConfigured[timerNo] = false;
    }

    return status;
}

/**
****************************************************************************************
* @brief[SW_73] This function will be used to enable monitor timer.
* @param[in] timerNo: The index of the monitored timer.
* @return status
            FS_STATUS_SUCCESS: Enable monitor timer success.
            FS_STATUS_ERROR: Enable monitor timer failed.
****************************************************************************************
*/
SAF_PIT_SEC_CODE
FS_STATUS SAF_PIT_EnableMonitorTimer(const uint32_t timerNo)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_pit_monitor_timer_data_t *pPitObj = &s_pitObject;

    if (timerNo >= SAF_PIT_MONITOR_TIMER_NUM)
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
        pPitObj->timerEnable[timerNo] = true;
        pPitObj->curTimerCounter[timerNo] = 0;
    }

    return status;
}

/**
****************************************************************************************
* @brief[SW_73] This function will be used to disable monitor timer.
* @param[in] timerNo: The index of the monitored timer.
* @return status
            FS_STATUS_SUCCESS: Disable monitor timer success.
            FS_STATUS_ERROR: Disable monitor timer failed.
****************************************************************************************
*/
SAF_PIT_SEC_CODE
FS_STATUS SAF_PIT_DisableMonitorTimer(const uint32_t timerNo)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_pit_monitor_timer_data_t *pPitObj = &s_pitObject;

    if (timerNo >= SAF_PIT_MONITOR_TIMER_NUM)
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
        pPitObj->timerEnable[timerNo] = false;
    }

    return status;
}


/**
****************************************************************************************
* @brief[SW_73] This function is used to get the period of the monitor timer.
* @param[in] timerNo: The index of the monitored timer.
* @param[in] periodUs: Monitor timer period.
* @return status
            FS_STATUS_SUCCESS: Get monitor timer period success.
            FS_STATUS_ERROR: Get monitor timer period failed.
****************************************************************************************
*/
FS_STATUS SAF_PIT_GetMonitorTimerPeriodUs(uint32_t timerNo, uint32_t *pPeriodUs)
{
    FS_STATUS status = FS_STATUS_ERROR;
    uint32_t counter;
    saf_pit_monitor_timer_data_t *pPitObj = &s_pitObject;

    if (FS_STATUS_SUCCESS == SAF_PIT_AccessGetMonitorTimerCounter(timerNo, &counter))
    {
        *pPeriodUs = counter * pPitObj->pitPeriodUs;
        status = FS_STATUS_SUCCESS;
    }

    return status;
}

/**
****************************************************************************************
* @brief: [SW_73]This function is Pit 0 channel 0 interrupt handler function.
* @return void.
****************************************************************************************
*/
SAF_PIT_SEC_CODE
void SAF_PIT_Pit0Chan0Handler(void)
{
	SAF_PIT_IrqHandler(PIT0,PIT_Channel0);
}
/**
****************************************************************************************
* @brief: [SW_73]This function is Pit 0 channel 1 interrupt handler function.
* @return void.
****************************************************************************************
*/
SAF_PIT_SEC_CODE
void SAF_PIT_Pit0Chan1Handler(void)
{
	SAF_PIT_IrqHandler(PIT0,PIT_Channel1);
}
/**
****************************************************************************************
* @brief: [SW_73]This function is Pit 0 channel 2 interrupt handler function.
* @return void.
****************************************************************************************
*/
SAF_PIT_SEC_CODE
void SAF_PIT_Pit0Chan2Handler(void)
{
	SAF_PIT_IrqHandler(PIT0,PIT_Channel2);
}
/**
****************************************************************************************
* @brief: [SW_73]This function is Pit 0 channel 3 interrupt handler function.
* @return void.
****************************************************************************************
*/
SAF_PIT_SEC_CODE
void SAF_PIT_Pit0Chan3Handler(void)
{
	SAF_PIT_IrqHandler(PIT0,PIT_Channel3);
}
/**
****************************************************************************************
* @brief: [SW_73]This function is Pit 0 channel 4 interrupt handler function.
* @return void.
****************************************************************************************
*/
SAF_PIT_SEC_CODE
void SAF_PIT_Pit0Chan4Handler(void)
{
	SAF_PIT_IrqHandler(PIT0,PIT_Channel4);
}
/**
****************************************************************************************
* @brief: [SW_73]This function is Pit 0 channel 5 interrupt handler function.
* @return void.
****************************************************************************************
*/
SAF_PIT_SEC_CODE
void SAF_PIT_Pit0Chan5Handler(void)
{
	SAF_PIT_IrqHandler(PIT0,PIT_Channel5);
}
/**
****************************************************************************************
* @brief: [SW_73]This function is Pit 0 channel 6 interrupt handler function.
* @return void.
****************************************************************************************
*/
SAF_PIT_SEC_CODE
void SAF_PIT_Pit0Chan6Handler(void)
{
	SAF_PIT_IrqHandler(PIT0,PIT_Channel6);
}
/**
****************************************************************************************
* @brief: [SW_73]This function is Pit 0 channel 7 interrupt handler function.
* @return void.
****************************************************************************************
*/
SAF_PIT_SEC_CODE
void SAF_PIT_Pit0Chan7Handler(void)
{
	SAF_PIT_IrqHandler(PIT0,PIT_Channel7);
}
/**
****************************************************************************************
* @brief: [SW_73]This function is Pit 1 channel 0 interrupt handler function.
* @return void.
****************************************************************************************
*/
SAF_PIT_SEC_CODE
void SAF_PIT_Pit1Chan0Handler(void)
{
    SAF_PIT_IrqHandler(PIT1,PIT_Channel0);
}
/**
****************************************************************************************
* @brief: [SW_73]This function is Pit 1 channel 1 interrupt handler function.
* @return void.
****************************************************************************************
*/
SAF_PIT_SEC_CODE
void SAF_PIT_Pit1Chan1Handler(void)
{
    SAF_PIT_IrqHandler(PIT1,PIT_Channel1);
}

SAF_PIT_SEC_CODE
boolean SAF_PitstatusCheck_Pit1Chan0()
{
    uint32_t stmCirValue = 0;
    boolean ret = false;
    stmCirValue = Gpt_Pit_LLD_GetIntFlag((PIT_Module_t)PIT1, (PIT_Channel_t)PIT_Channel0);/*PRQA S 1411,1296*/
    ret = (0x0UL != stmCirValue ) ? true : false;

    return ret;
}

#ifdef __cplusplus
}
#endif

