/**
****************************************************************************************
 * @FilePath: saf_dma.h
 * @Author: CCORE
 * @Date: 2024-02-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: DMA Head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_DMA_H
#define SAF_DMA_H

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_cpu.h"
#include "edma_lld.h"
#include "SafetyPeriphTst_Cfg.h"
#include "Gpt_Stm_LLDriver.h"
/**
****************************************************************************************
 * @brief: Macros
****************************************************************************************
*/
#define SAF_DMA_MONITOR_CHANEL_FLAG                          (0x1)
#define SAF_DMA_INSTANCE_COUNT                               (EDMA_INSTANCE_COUNT)
#define SAF_DMA_INSTCANSE_CHANNEL_COUNT                      (64U)
#define SAF_DMA_ALL_CHAN_COUNT                               (SAF_DMA_INSTCANSE_CHANNEL_COUNT * SAF_DMA_INSTANCE_COUNT)
#define SAF_DMA_INIT_TIME                                    (0U)


/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/
typedef void (*saf_dma_isr_callback_t)(void *pParam, SafeDMAChnStatusType status);

/**
* @brief  DMA call back function parameter.
*/
typedef struct
{
    /**
    * @brief Callback function parameters
    */
    void* param;
    /**
    * @brief Callback function channel
    */
    uint8_t chan;
} saf_dma_callback_param_t;

/**
* @brief  DMA manage structure.This is used to manage DMA transmit.
*/
typedef struct
{
    /*Number of DMA monitor tests passed.*/
    uint16_t chanDoneCount[SAF_DMA_ALL_CHAN_COUNT];
    /*Number of DMA monitor test errors.*/
    uint16_t chanErrorCount[SAF_DMA_ALL_CHAN_COUNT];
    /*Timer value when DMA starts transmission.*/
    uint32_t dmaStartTempValue[SAF_DMA_ALL_CHAN_COUNT];
    /*Timer value at the end of DMA transmission.*/
    uint32_t dmaEndTempValue[SAF_DMA_ALL_CHAN_COUNT];
    /*DMA callback function.*/
    saf_dma_isr_callback_t callback[SAF_DMA_ALL_CHAN_COUNT];
    /*DMA callback parameters.*/
    saf_dma_callback_param_t callbackParam[SAF_DMA_ALL_CHAN_COUNT];
} saf_dma_mgr_t;

/*!
 * @brief DMA monitor test parameter structure.
 *
 * This is used for the test parameter of DMA monitor test.
 * Implements : saf_dma_monitor_test_param_t_Class
 */
typedef struct 
{
    /* Expected done times array */
    uint16_t expectedDoneTimesArray[SAF_DMA_MONITOR_CHAN_COUNT];
    /* The number of monitor channel */
    uint8_t monitorChanCount;
    /* Monitor channel ID array */
    uint8_t monitorvChanIDArray[SAF_DMA_ALL_CHAN_COUNT];
} saf_dma_monitor_test_param_t;

/**
 * @brief DMA monitor test result structure.
 */
typedef struct 
{
    /* Actual transfer completed timer array.*/
    uint16_t realDoneTimesArray[SAF_DMA_ALL_CHAN_COUNT];
    /* Actual transfer error timer array.*/
    uint16_t realErrorTimesArray[SAF_DMA_ALL_CHAN_COUNT];
    /*The timer value at the actual start of DMA transmission.*/
    uint32_t realStartTempValue[SAF_DMA_ALL_CHAN_COUNT];
    /*Timer value at the end of DMA actual transmission.*/
    uint32_t realEndTempValue[SAF_DMA_ALL_CHAN_COUNT];
    /* Monitor channel test result.*/
    boolean monitorvChanPassedArray[SAF_DMA_ALL_CHAN_COUNT];
} saf_dma_monitor_test_result_t;


/**
****************************************************************************************
 * @brief: Function prototypes
****************************************************************************************
*/

FS_STATUS SAF_DMA_InitAndCfgMonitorChan(safedma_state_t *controllerState,
                                       const SafeDMAModuleConfigType *controllerCfg,
									   SafeDMAChnStateType *chanObjList[],
									   SafeDMAChanConfigType * const chnConfigArray[],
                                       const uint32_t chnCount,
                                       const uint8_t monitorvChanArray[],
                                       const uint8_t monitorvChanCount);

 
void SAF_DMA_CleanChanTxCount(const uint8_t chan);

void SAF_DMA_AppendExpectedTxCount(const uint8_t chan, const uint32_t incTxTimes);

FS_STATUS SAF_DMA_MonitorTest(void);

FS_STATUS SAF_DMA_MonitorTestResult(saf_dma_monitor_test_result_t *pTestResult);

void SAF_DMA_AppendDoneTxCount(const uint8_t chan, const uint32_t incTxTimes);

void SAF_DMA_GetStartTransmissionTime(const uint8_t chan);

void SAF_DMA_GetEndTransmissionTime(const uint8_t chan);

#define SAF_TEST_CHN_COUNT                              (63U)
#define SAF_DMA_MONITOR_CHANNEL_LIST                    {SAF_TEST_CHN_COUNT}
#define SAF_CONFIGURED_CHANNELS_COUNT                   (1U)
#define SAF_MAJOR_LOOP_NOF_MINOR_LOOPS                  (4U)
#define SAF_MINOR_LOOP_BYTE_COUNT                       (8U)
#define SAF_LOOP_TRANSFER_NOF_BYTES                     (256U)
#define SAF_TRANSFER_OFFSET                             (4U)

FS_STATUS SAF_DmaRuntimeSafetyTestInit(void);
FS_STATUS EVPT_SAF_DmaRuntimeSafetyTestInit(void);
void SAF_DmaDataTransfer(void);

#ifdef __cplusplus
}
#endif

#endif/* SAF_DMA_H */
