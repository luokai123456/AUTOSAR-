/**
****************************************************************************************
 * @FilePath: saf_dma.c
 * @Author: CCORE
 * @Date: 2024-02-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: DMA Source File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifdef __cplusplus
extern "C"{
#endif
/*PRQA S 0315,0686,1843,2844,3408,4304,4403,4404,4434 EOF*/
/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_cpu.h"/*PRQA S 0380*/
#include "edma_lld.h"
#include <stdbool.h>
#include "saf_dma.h"
#include "Saf_MemMap.h"
/**
****************************************************************************************
 * @brief: Local Variables
****************************************************************************************
*/
SAF_DMA_SEC_VAR_INIT
static saf_dma_mgr_t s_dmaMonitorMgr =
{
	    .chanDoneCount      = {0},
	    .chanErrorCount     = {0},
	    .dmaStartTempValue  = {0},
	    .dmaEndTempValue    = {0},
	    .callback           = {0},
	    .callbackParam      = {{0}},
};

SAF_DMA_SEC_VAR_INIT
static saf_dma_monitor_test_param_t s_dmaMonitorParamTest =
{
    .monitorvChanIDArray     = SAF_DMA_MONITOR_CHAN_LIST,
    .expectedDoneTimesArray  = SAF_DMA_EXPECTED_DONE_TIMES,
    .monitorChanCount          = SAF_DMA_MONITOR_CHAN_COUNT,
};

SAF_DMA_SEC_VAR_INIT
static saf_dma_monitor_test_result_t s_dmaMonitorResultTest = 
{
    .realDoneTimesArray      = {0},
    .realErrorTimesArray     = {0},
    .monitorvChanPassedArray = {(bool)true},
};/*PRQA S 0704*/

/* cyh: add 4B alignment */
/*PRQA S 0315,0316,1840,2844,3200,3218,3397,3401,4322,4422 EOF*/
SAF_DMA_SEC_VAR_INIT
volatile uint8_t __attribute__((aligned(4))) s_dmaTestSrcData[SAF_LOOP_TRANSFER_NOF_BYTES] = "SafeDMA Data Transfer test.";/*PRQA S 3218*/
SAF_DMA_SEC_VAR_NO_INIT
static uint8_t __attribute__((aligned(4))) s_dmaTestDstData[SAF_LOOP_TRANSFER_NOF_BYTES];
SAF_DMA_SEC_VAR_NO_INIT
static uint8_t s_counter;

extern saf_dma_monitor_test_param_t s_dmaMonitorParamTest;

/**
****************************************************************************************
 * @brief: Local Functions
****************************************************************************************
*/
/**
****************************************************************************************
* @brief: [] This function is DMA monitor test callback function.
* @param[in] pParam  DMA callback function parameters
* @param[in] status  DMA channel transmission status
* @return void
****************************************************************************************
*/
SAF_DMA_SEC_CODE
static void SAF_DMA_AccessMonitorTestCallback(void *pParam, SafeDMAChnStatusType status)
{
    saf_dma_callback_param_t *callbackParam = (saf_dma_callback_param_t *)pParam;/*PRQA S 0316*/
    saf_dma_mgr_t *pDmaMgr = &s_dmaMonitorMgr;
    volatile uint8_t chan = callbackParam->chan;/* polyspace RTE:NIV,IDP */

    SAF_DMA_GetEndTransmissionTime(chan);
    if (SAF_EDMA_CHN_STATUS_NORMAL == status)
    {
        /* need to monitor this channel */
        if(SAF_UIN16_MAX <= pDmaMgr->chanDoneCount[chan])/* polyspace RTE:OBAI */
        {
            pDmaMgr->chanDoneCount[chan] = 1U;/* polyspace RTE:OBAI */
        }
        else
        {
            pDmaMgr->chanDoneCount[chan] += 1U;/* polyspace RTE:OBAI */
        }
    }
    else if (SAF_EDMA_CHN_STATUS_ERROR == status)
    {
        if(SAF_UIN16_MAX <= pDmaMgr->chanErrorCount[chan])/* polyspace RTE:OBAI */
        {
            pDmaMgr->chanErrorCount[chan] = 1U;/* polyspace RTE:OBAI */
        }
        else
        {
            pDmaMgr->chanErrorCount[chan] += 1U;/* polyspace RTE:OBAI */
        }
    }
    else
    {
        /* do nothing */
    }

    /* call callback */
    if (NULL != pDmaMgr->callback[chan])/* polyspace RTE:OBAI */
    {
        pDmaMgr->callback[chan]((void*)&pDmaMgr->callbackParam[chan], status);/*PRQA S 0314,2934*//* polyspace RTE:OBAI,COR */
    }
}

/**
****************************************************************************************
* @brief[NA] This function is used to configure the monitor DMA channel.
* @param[in] chnConfigArray: DMA channel configuration list.
* @param[in] chnCount: Configure channel number.
* @param[in] monitorvChanArray: DMA monitor channels List.
* @param[in] monitorvChanCount: Monitor channel count.
* @return void
****************************************************************************************
*/
SAF_DMA_SEC_CODE
static void SAF_DMA_AccessCfgMonitorChan(SafeDMAChanConfigType * const chnConfigArray[],const uint32_t chnCount,
                                         const uint8_t monitorvChanArray[],const uint8_t monitorvChanCount)
{
    uint8_t i, j, chan;
    saf_dma_mgr_t *pDmaMgr = &s_dmaMonitorMgr;
    boolean needToMonitor = false;

    for (i = 0; i < chnCount ; i++)
    {
        chan  = chnConfigArray[i]->mappedChnConfig;
        needToMonitor = false;
        for (j = 0; j < monitorvChanCount; j++)
        {
            if (chnConfigArray[i]->mappedChnConfig == monitorvChanArray[j])
            {
                needToMonitor = true;
                break;
            }
        }

        if (true == needToMonitor)/*PRQA S 1881*/
        {
            pDmaMgr->callback[chan]              = chnConfigArray[i]->callback;
            pDmaMgr->callbackParam[chan].param   = chnConfigArray[i]->callbackParam;
            pDmaMgr->callbackParam[chan].chan = chan;
            chnConfigArray[i]->callback             = &SAF_DMA_AccessMonitorTestCallback;
            chnConfigArray[i]->callbackParam        = &pDmaMgr->callbackParam[chan];/*PRQA S 2934*/
        }
    }

}

/**
****************************************************************************************
* @brief: This function is used to initialize and configure the monitor DMA channel.
* @param[in] controllerState DMA monitor status
* @param[in] controllerCfg Configuration of DMA monitor.
* @param[in] chanStateObjList The channel is configured.
* @param[in] chnConfigArray Channel configuration list.
* @param[in] chnCount Configure channel number
* @param[in] monitorvChanArray List of monitor channels.
* @param[in] monitorvChanCount Monitor channel count.
* @return status
            FS_STATUS_SUCCESS: Successfully initialized and configured DMA channel.
            FS_STATUS_ERROR: Failed to initialize or configure DMA channel.
****************************************************************************************
*/
SAF_DMA_SEC_CODE
FS_STATUS SAF_DMA_InitAndCfgMonitorChan(safedma_state_t *controllerState,  /* driver to use */
                                       const SafeDMAModuleConfigType *controllerCfg,
									   SafeDMAChnStateType *chanStateObjList[],/*PRQA S 1330,1881*/
									   SafeDMAChanConfigType * const chnConfigArray[],
                                       const uint32_t chnCount,
                                       const uint8_t monitorvChanArray[],
                                       const uint8_t monitorvChanCount)
{    
    FS_STATUS status = FS_STATUS_SUCCESS;    

    if ((NULL == controllerState) || (NULL == chanStateObjList) || (NULL == controllerCfg) || (NULL == chnConfigArray) || (0U == chnCount))
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
        SAF_DMA_AccessCfgMonitorChan(chnConfigArray,chnCount,monitorvChanArray,monitorvChanCount);
        {
            const SafeDMAChanConfigType * cfg_ro[SAF_EDMA_MAPPED_CHANNELS];
            uint32_t i;
            for (i = 0u; i < chnCount; i++)
            {
                if (NULL == chnConfigArray[i])
                {
                	status = FS_STATUS_ERROR;
                	break;
                }
                cfg_ro[i] = chnConfigArray[i];
            }

            if (STATUS_SUCCESS != SAF_EDMA_LLD_ModuleInit(controllerState,controllerCfg,
                                                          chanStateObjList,cfg_ro,chnCount))/*PRQA S 2973*/
            {
                status = FS_STATUS_ERROR;
            }
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief: This function is used to clean the DMA channel transmit counter.
* @param[in] chan DMA channel ID
* @return void
****************************************************************************************
*/
SAF_DMA_SEC_CODE
void SAF_DMA_CleanChanTxCount(const uint8_t chan)
{
    saf_dma_mgr_t *pDmaMgr = &s_dmaMonitorMgr;

    if(SAF_DMA_ALL_CHAN_COUNT > chan)
    {
        pDmaMgr->chanDoneCount[chan] = 0;
        pDmaMgr->chanErrorCount[chan] = 0;
    }
}


/**
****************************************************************************************
* @brief: This function is used to get the test result of DMA monitor test.
* @param[in] pTestResult Pointer to obtain DMA monitoring results
* @return status
            FS_STATUS_SUCCESS: Successfully obtained DMA monitoring results.
            FS_STATUS_ERROR: Failed to obtain DMA monitoring results.
****************************************************************************************
*/
SAF_DMA_SEC_CODE
FS_STATUS SAF_DMA_MonitorTestResult(saf_dma_monitor_test_result_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (NULL != pTestResult)
    {
        status = FS_STATUS_SUCCESS;
        memcpy(pTestResult, &s_dmaMonitorResultTest, sizeof(s_dmaMonitorResultTest));/*PRQA S 3200*/
    }

    return status;
}

/**
****************************************************************************************
* @brief: This function executes DMA monitor test.
* @param[in] pTestResult Pointer to obtain DMA monitoring results
* @return status
            FS_STATUS_SUCCESS: DMA monitor test passed.
            FS_STATUS_ERROR: DMA monitor test failed.
****************************************************************************************
*/
SAF_DMA_SEC_CODE
FS_STATUS SAF_DMA_MonitorTest(void)
{  
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_dma_monitor_test_param_t *pParam   = &s_dmaMonitorParamTest;
    saf_dma_monitor_test_result_t *pResult = &s_dmaMonitorResultTest;
    saf_dma_mgr_t *pDmaMgr = &s_dmaMonitorMgr;
    uint32_t i;
    uint32_t tempValue;
    uint8_t chan;

    (void)memset(&pResult->monitorvChanPassedArray[0], true, sizeof(pResult->monitorvChanPassedArray));
    for (i = 0; i < pParam->monitorChanCount; i++)
    {
        chan = pParam->monitorvChanIDArray[i];
        pResult->monitorvChanPassedArray[chan] = false;
        pResult->realDoneTimesArray[chan]  = pDmaMgr->chanDoneCount[chan];
        pResult->realErrorTimesArray[chan] = pDmaMgr->chanErrorCount[chan];
        pResult->realStartTempValue[chan] = pDmaMgr->dmaStartTempValue[chan];
        pResult->realEndTempValue[chan] = pDmaMgr->dmaEndTempValue[chan];

        if((SAF_DMA_INIT_TIME != pResult->realEndTempValue[chan])&&(SAF_DMA_INIT_TIME != pResult->realStartTempValue[chan]))
        {
            if(pResult->realEndTempValue[chan] <= pResult->realStartTempValue[chan])
            {
                tempValue = (FS_UIN32_MAX - pResult->realStartTempValue[chan]) + pResult->realEndTempValue[chan];
            }
            else
            {
                tempValue = pResult->realEndTempValue[chan] - pResult->realStartTempValue[chan];
            }
            if(SAF_DMA_TIMEOUT > tempValue)
            {
                if ((pResult->realDoneTimesArray[chan] == pParam->expectedDoneTimesArray[i])&&(pResult->realDoneTimesArray[chan] != 0U))
                {
                    pResult->monitorvChanPassedArray[chan] = true;
                }
                else
                {
                    status = FS_STATUS_ERROR;
                }
            }
            else
            {
                status = FS_STATUS_TIMEOUT;
            }
        }
        else
        {
            status = FS_STATUS_ERROR;
        }

        pDmaMgr->dmaStartTempValue[chan] = 0;
        pDmaMgr->dmaEndTempValue[chan] = 0;
    }

    return status;
}

/**
****************************************************************************************
* @brief: This function is used to append the excepted transmit counter.
* @param[in] chan DMA channel ID.
* @param[in] incTxTimes The expected number of transmissions that need to be increased.
* @return void
****************************************************************************************
*/
SAF_DMA_SEC_CODE
void SAF_DMA_AppendExpectedTxCount(const uint8_t chan, const uint32_t incTxTimes)
{
    uint32_t i;

    for (i = 0; i < s_dmaMonitorParamTest.monitorChanCount; i++)
    {
        if (chan == s_dmaMonitorParamTest.monitorvChanIDArray[i])
        {
            /* update increment times */
            if (SAF_UIN16_MAX < (s_dmaMonitorParamTest.expectedDoneTimesArray[i] + incTxTimes))
            {
                s_dmaMonitorParamTest.expectedDoneTimesArray[i] = (uint16_t)(incTxTimes - (SAF_UIN16_MAX - s_dmaMonitorParamTest.expectedDoneTimesArray[i]));
            }
            else
            {
                s_dmaMonitorParamTest.expectedDoneTimesArray[i] += (uint16_t)incTxTimes;
            }
            break;
        }
    }
}

/**
****************************************************************************************
* @brief: This function is used to append the actual transmit counter.
* @param[in] chan DMA channel ID.
* @param[in] incTxTimes The actual number of transmissions that need to be increased.
* @return void
****************************************************************************************
*/
SAF_DMA_SEC_CODE
void SAF_DMA_AppendDoneTxCount(const uint8_t chan, const uint32_t incTxTimes)
{
    uint32_t i;
    saf_dma_mgr_t *pDmaMgr = &s_dmaMonitorMgr;

    for (i = 0; i < s_dmaMonitorParamTest.monitorChanCount; i++)
    {
        if (chan == s_dmaMonitorParamTest.monitorvChanIDArray[i])
        {
            if (SAF_UIN16_MAX < pDmaMgr->chanDoneCount[chan] + incTxTimes)/*PRQA S 3401,3397*/
            {
                pDmaMgr->chanDoneCount[chan] = (uint16_t)(incTxTimes - (SAF_UIN16_MAX - pDmaMgr->chanDoneCount[chan]));
            }
            else
            {
                pDmaMgr->chanDoneCount[chan] += (uint16_t)incTxTimes;
            }
            break;
        }
    }
}

/**
****************************************************************************************
* @brief[NA] This function is used to obtain the time when DMA starts transferring.
* @param[in] chan: DMA channel ID.
* @return void
****************************************************************************************
*/
void SAF_DMA_GetStartTransmissionTime(const uint8_t chan)
{
    saf_dma_mgr_t *pDmaMgr = &s_dmaMonitorMgr;

    if(SAF_DMA_ALL_CHAN_COUNT > chan)
    {
        pDmaMgr->dmaStartTempValue[chan] = (uint32_t)Gpt_Stm_LLD_GetCounter(STM1);
    }
}

/**
****************************************************************************************
* @brief[NA] This function is used to obtain the time at which DMA transfer ends.
* @param[in] chan: DMA channel ID.
* @return void
****************************************************************************************
*/
SAF_DMA_SEC_CODE
void SAF_DMA_GetEndTransmissionTime(const uint8_t chan)
{
    saf_dma_mgr_t *pDmaMgr = &s_dmaMonitorMgr;

    if(SAF_DMA_ALL_CHAN_COUNT > chan)
    {
        pDmaMgr->dmaEndTempValue[chan] = (uint32_t)Gpt_Stm_LLD_GetCounter(STM1);
    }
}

SAF_DMA_SEC_CODE
void FS_DEMO_DmaMonitorTestVch0Callback(void *pParam, SafeDMAChnStatusType status)
{
    saf_dma_callback_param_t *pDmaParam = (saf_dma_callback_param_t *)pParam;/*PRQA S 0316*/
    (void)status;/* PRQA S 3119 */
    *((uint32_t *)pDmaParam->param) += 1; /*PRQA S 1840*/ /* polyspace RTE:NIV,IDP,NIP */
}

SAF_DMA_SEC_CODE
uint32_t s_FstempCount = 0;
FS_STATUS SAF_DmaRuntimeSafetyTestInit(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
#if 0
    static SafeDMALoopTransferConfigType majorLoopTransferConfig;
    static SafeDMATransferConfigType minorTransferConfig;
    static safedma_state_t dmaCtlState;
    static SafeDMAChnStateType dmaCtlChn0State;
    static 
    uint8_t dmaMonitorChanList[] = SAF_DMA_MONITOR_CHANNEL_LIST;/*PRQA S 3604*/

     /* DMA chan config */
     static SafeDMAChnStateType * edmaChnStateArray[] =
     {
         &dmaCtlChn0State
     };

     static SafeDMAChanConfigType dmaController1Chn0Cfg =
     {
         .chnPrioSet = (SafeDMAChannelPriorityType)SAF_EDMA_CHN_PRIORITY_DEFALUT,
         .mappedChnConfig = SAF_TEST_CHN_COUNT,
         .callback = &FS_DEMO_DmaMonitorTestVch0Callback,
         .callbackParam = &s_FstempCount,/*PRQA S 0315*/
         .triggerEn = (bool)false/*PRQA S 4304*/
     };/*PRQA S 0704*/

     static SafeDMAChanConfigType * const edmaChnConfigArray[] =
     {
         &dmaController1Chn0Cfg
     };

     /* DMA controller config */
     static const SafeDMAModuleConfigType dmaCtlInitCfg =
     {
         .setChnArbitMode = (SafeDMASelArbitrationModeType)SAF_EDMA_ARBITRATION_MODE_FIXED_PRIORITY,
         .groupArbitration = (SafeDMASelArbitrationModeType)SAF_EDMA_ARBITRATION_MODE_FIXED_PRIORITY,
         .prioGroup0 = (SafeDMAGroupPriorityType)SAF_EDMA_GRP_PRIORITY0,
         .prioGroup1 = (SafeDMAGroupPriorityType)SAF_EDMA_GRP_PRIORITY1,
         .prioGroup2 = (SafeDMAGroupPriorityType)SAF_EDMA_GRP_PRIORITY2,
         .prioGroup3 = (SafeDMAGroupPriorityType)SAF_EDMA_GRP_PRIORITY3,
         .haltOnError = (bool)false,/*PRQA S 4304*/
     };



     status = SAF_DMA_InitAndCfgMonitorChan(&dmaCtlState,
                                         &dmaCtlInitCfg,
                                         edmaChnStateArray,
                                         edmaChnConfigArray,
                                         1,
                                         dmaMonitorChanList,
                                         SAF_CONFIGURED_CHANNELS_COUNT);
    
     if (FS_STATUS_SUCCESS == status)
     {
        /* 2. edma transfer config */
    majorLoopTransferConfig.majorLpIterCnt   = SAF_MAJOR_LOOP_NOF_MINOR_LOOPS;
    minorTransferConfig.srcAddrAdjustLast     = -32;
    minorTransferConfig.destAddrAdjustLast    = -32;
    minorTransferConfig.srcAddr = (uint32_t)&s_dmaTestSrcData[0];
    minorTransferConfig.destAddr = (uint32_t)&s_dmaTestDstData[0];
    minorTransferConfig.destAddrOffset = SAF_TRANSFER_OFFSET;/*PRQA S 1291*/
    minorTransferConfig.srcAddrOffset = SAF_TRANSFER_OFFSET;/*PRQA S 1291*/
    minorTransferConfig.srcTransDataSize = (SafeDMATransferSizeType)SAF_EDMA_TRANSFER_SIZE_4B;
    minorTransferConfig.destTransDataSize = (SafeDMATransferSizeType)SAF_EDMA_TRANSFER_SIZE_4B;
    minorTransferConfig.srcAddrModulo = (SafeDMAModuloType)SAF_EDMA_ADDRESS_MODULO_OFF;
    minorTransferConfig.destAddrModulo = (SafeDMAModuloType)SAF_EDMA_ADDRESS_MODULO_OFF;
    minorTransferConfig.minorTransByte    = SAF_MINOR_LOOP_BYTE_COUNT;
    minorTransferConfig.lpTransConfigPtr = &majorLoopTransferConfig;
    minorTransferConfig.completeIntEn = (unsigned char)true;/*PRQA S 4304*/

    (void)EDMA_LLD_SetLoopTransferConfig(SAF_TEST_CHN_COUNT, &minorTransferConfig);
     }
#endif
    return status;
   
}



FS_STATUS EVPT_SAF_DmaRuntimeSafetyTestInit(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    #if 1
    static SafeDMALoopTransferConfigType majorLoopTransferConfig;
    static SafeDMATransferConfigType minorTransferConfig;

    majorLoopTransferConfig.majorLpIterCnt   = SAF_MAJOR_LOOP_NOF_MINOR_LOOPS;
    minorTransferConfig.srcAddrAdjustLast     = -32;
    minorTransferConfig.destAddrAdjustLast    = -32;
    minorTransferConfig.srcAddr = (uint32_t)&s_dmaTestSrcData[0];
    minorTransferConfig.destAddr = (uint32_t)&s_dmaTestDstData[0];
    minorTransferConfig.destAddrOffset = SAF_TRANSFER_OFFSET;/*PRQA S 1291*/
    minorTransferConfig.srcAddrOffset = SAF_TRANSFER_OFFSET;/*PRQA S 1291*/
    minorTransferConfig.srcTransDataSize = (SafeDMATransferSizeType)SAF_EDMA_TRANSFER_SIZE_4B;
    minorTransferConfig.destTransDataSize = (SafeDMATransferSizeType)SAF_EDMA_TRANSFER_SIZE_4B;
    minorTransferConfig.srcAddrModulo = (SafeDMAModuloType)SAF_EDMA_ADDRESS_MODULO_OFF;
    minorTransferConfig.destAddrModulo = (SafeDMAModuloType)SAF_EDMA_ADDRESS_MODULO_OFF;
    minorTransferConfig.minorTransByte    = SAF_MINOR_LOOP_BYTE_COUNT;
    minorTransferConfig.lpTransConfigPtr = &majorLoopTransferConfig;
    minorTransferConfig.completeIntEn = (unsigned char)true;/*PRQA S 4304*/

    EDMA_LLD_SetLoopTransferConfig(SAF_TEST_CHN_COUNT, &minorTransferConfig);
    #endif
    return status;

}

SAF_DMA_SEC_CODE
static FS_STATUS SAF_DmaTxOnce(const uint8_t chan, uint8_t type)
{
    volatile uint32_t i;
    FS_STATUS status = FS_STATUS_SUCCESS;

    memset(s_dmaTestDstData, 0, SAF_LOOP_TRANSFER_NOF_BYTES);
    if (type == (uint8_t)0)
    {
	    for (i = 0; i < SAF_MAJOR_LOOP_NOF_MINOR_LOOPS; i++)
	    {
			SAF_EDMA_LLD_SwRequestTriggerEn(chan);
	    }
    }
    else
    {
    	s_counter = 0xff;
        eDMA_0.SSRT.R = 0x3f;
        while((eDMA_0.TCD[chan].CITER.ELINKNO.B.CITER == SAF_MAJOR_LOOP_NOF_MINOR_LOOPS) && (s_counter != (uint8_t)0)) /* polyspace RTE:NIV */
        {
        	s_counter--;
        }
        eDMA_0.SSRT.R = 0x3f;
        while((eDMA_0.TCD[chan].CITER.ELINKNO.B.CITER == SAF_MAJOR_LOOP_NOF_MINOR_LOOPS - 1) && (s_counter != (uint8_t)0)) /* polyspace RTE:NIV */
        {
        	s_counter--;
        }
        eDMA_0.SSRT.R = 0x3f;
        while((eDMA_0.TCD[chan].CITER.ELINKNO.B.CITER == SAF_MAJOR_LOOP_NOF_MINOR_LOOPS - 2) && (s_counter != (uint8_t)0)) /* polyspace RTE:NIV */
        {
        	s_counter--;
        }
        eDMA_0.SSRT.R = 0x3f;
        while((eDMA_0.TCD[chan].CITER.ELINKNO.B.CITER == SAF_MAJOR_LOOP_NOF_MINOR_LOOPS - 3) && (s_counter != (uint8_t)0)) /* polyspace RTE:NIV */
        {
        	s_counter--;
        }
        if (s_counter == (uint8_t)0)
        {
        	status = FS_STATUS_TIMEOUT;
        }
    }
    return status;
}

SAF_DMA_SEC_CODE
void SAF_DmaDataTransfer(void)
{
    uint8_t chan[] = SAF_DMA_MONITOR_CHAN_LIST;/*PRQA S 3604*/
    volatile uint32_t i;

    for (i = 0; i < sizeof(chan); i++)
    {
        SAF_DMA_AppendExpectedTxCount(chan[i], 1); /*PRQA S 2844*/ /* polyspace RTE:OBAI */
        SAF_DMA_GetStartTransmissionTime(chan[i]);/* polyspace RTE:OBAI */
#ifdef __ghs__
        (void)SAF_DmaTxOnce(chan[i], 1); /*PRQA S 2844*/ /* polyspace RTE:OBAI */
#else
        (void)SAF_DmaTxOnce(chan[i], 0); /*PRQA S 2844*/
#endif
    }

    
}

#ifdef __cplusplus
}
#endif
