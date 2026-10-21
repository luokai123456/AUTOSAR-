/**
****************************************************************************************
 * @FilePath: saf_stm.h
 * @Author: CCORE
 * @Date: 2024-02-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: Stm Head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/

#ifndef SAF_STM_H
#define SAF_STM_H

#ifdef __cplusplus
extern "C"{
#endif
/*PRQA S 0722 EOF*/
/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/

#include "saf_swt.h"
#include "saf_common.h"
#include "Gpt_Stm_LLDriver.h"
#include "SafetyPeriphTst_Cfg.h"

/**
****************************************************************************************
 * @brief: Macros
****************************************************************************************
*/
#define SAF_STM_MONITOR_TIMER_NUM               (8U)
#define SAF_STM_FULL_RANGE                      (100U)
#define SAF_STM_DEFAULT_NUMBER                  (0xFFU)
#define SAF_STM_MONITOR_TIMER_NUM               (8U)

#define SAF_STM_INSTANCE_COUNT                      			(3U)

#define SAF_STM_CHANNEL_COUNT                       			(4U)

#define SAF_STM_CHAN_COUNT_LIST                     			{SAF_STM_CHANNEL_COUNT,SAF_STM_CHANNEL_COUNT,SAF_STM_CHANNEL_COUNT}

#define SAF_STM_DET_ERR(x)                      DEV_ASSERT(x)

/**
****************************************************************************************
 * @brief: Enum
****************************************************************************************
*/
/**
* @brief The STM timer config status.
*/
typedef enum
{
    /* This parameter represents stm config uninit. */
    SAF_STM_CONFIG_UNINIT = 0,
    /* This parameter represents stm config init. */
    SAF_STM_CONFIG_INIT,
    /* This parameter represents stm config init error. */
    SAF_STM_CONFIG_INIT_ERROR
} saf_stm_config_status_type;

/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/

/**
* @brief The STM timer monitor manage structure.
*/
typedef struct
{
	/* User call back function */
    saf_intc_irq_callback callback[SAF_STM_INSTANCE_COUNT][SAF_STM_CHANNEL_COUNT];
    /* monitor timer max error. */
    uint32_t monitorTimerMaxErrUs[SAF_STM_INSTANCE_COUNT][SAF_STM_CHANNEL_COUNT];
    /* Monitor timer number. */
    uint32_t monitorTimerNo[SAF_STM_INSTANCE_COUNT][SAF_STM_CHANNEL_COUNT];
    /* Monitor timer Period. */
    uint32_t monitorTimerPeriod[SAF_STM_INSTANCE_COUNT][SAF_STM_CHANNEL_COUNT];
    /* Monitor timer error range. */
    uint32_t monitorTimerErrRange[SAF_STM_INSTANCE_COUNT][SAF_STM_CHANNEL_COUNT];
    /* Monitor timer Enable. */
    bool monitorTimerEnable[SAF_STM_INSTANCE_COUNT][SAF_STM_CHANNEL_COUNT];
    /* Monitor timer Accuracy. */
    bool monitorTimerAccuracy[SAF_STM_INSTANCE_COUNT][SAF_STM_CHANNEL_COUNT];
    /* This parameter represents monitor timer well. */
    bool monitorTimerWell[SAF_STM_INSTANCE_COUNT][SAF_STM_CHANNEL_COUNT];
    /* Monitor timer initialized. */
    bool initialized;
} saf_stm_timer_monitor_t;

/**
* @brief The STM timer monitor information structure.
*/
typedef struct 
{
	/* User call back function */
    saf_intc_irq_callback callback;
    /* Timer period error range ration(%). */
    uint32_t periodErrRangeRatio;
    /* Stm channel period configuration */
    uint32_t periodUs;
    /* Stm channel select */
    uint32_t chan;
    /* Stm interrupt priority */
    uint8_t priority;
    /* Channel monitor flag */
    bool needToMonitor;
    /* This parameter represents stm monitor enable flag. */
    bool MonitorEnable;
} saf_stm_timer_config_data_t;

/**
* @brief The STM timer monitor test result structure.
*/
typedef struct
{
    /* A bool value of which STM instance is configurated.*/
	saf_stm_config_status_type configured[SAF_STM_INSTANCE_COUNT];
    /* STM timer max error range. */
    uint32_t stmTimerMaxErrRang[SAF_STM_INSTANCE_COUNT][SAF_STM_CHANNEL_COUNT];
    /* This parameter represents stm timer monitor failed bit map. */
    uint32_t stmTimerMonitorFailedBitmap[SAF_STM_INSTANCE_COUNT][SAF_STM_CHANNEL_COUNT];
    /* Channel monitor flag */
    uint32_t stmTimerNotAccurateBitmap[SAF_STM_INSTANCE_COUNT];
} saf_stm_timer_monitor_test_result_t;

/**
* @brief The stm monitor timer data manage structure.
*/
typedef struct
{
    /*!< This parameter represents current timer counter. */
    uint32_t curTimerCounter[SAF_STM_MONITOR_TIMER_NUM];
    /*!< This parameter represents stm timer monitor period. */
    uint32_t stmPeriodUs;
    /*!< This parameter represents use timer configuration. */
    bool timerConfigured[SAF_STM_MONITOR_TIMER_NUM];
    /*!< This parameter represents timer enable. */
    bool timerEnable[SAF_STM_MONITOR_TIMER_NUM];
    /*!< This parameter represents timer monitor enable flag. */
    bool MonitorEnable[SAF_STM_INSTANCE_COUNT][SAF_STM_CHANNEL_COUNT];
} saf_stm_monitor_timer_data_t;

/**
****************************************************************************************
 * @brief: Global Variable
****************************************************************************************
*/

extern const saf_stm_timer_config_data_t s_SafStmTimerConfig[SAF_STM_TEST_USED_CHANNEL];


/**
****************************************************************************************
 * @brief: Function prototypes
****************************************************************************************
*/
FS_STATUS SAF_STM_ConfigDataInit(void);

FS_STATUS SAF_STM_TimerMonitorTestInit(const saf_stm_timer_monitor_test_result_t *pTestConfig);

FS_STATUS SAF_STM_TimerMonitorTestResult(saf_stm_timer_monitor_test_result_t *pTestResult);

FS_STATUS SAF_StmRuntimeSafetyTestInit(void);

FS_STATUS SAF_STM_TimerMonitorTest(void);

void SAF_STM_IrqHandler(const uint8_t stmInst,const uint8_t chan);

FS_STATUS SAF_STM_GetMonitorTimerPeriodUs(uint32_t timerNo, uint32_t *pPeriodUs);

FS_STATUS SAF_STM_DisableMonitorTimer(const uint32_t timerNo);

FS_STATUS SAF_STM_EnableMonitorTimer(const uint32_t timerNo);

FS_STATUS SAF_STM_DeleteMonitorTimer(const uint32_t timerNo);

FS_STATUS SAF_STM_AddMonitorTimer(uint32_t *pTimerNo);

void SAF_STM_Stm0Chan0Handler(void);
void SAF_STM_Stm0Chan1Handler(void);
void SAF_STM_Stm0Chan2Handler(void);
void SAF_STM_Stm0Chan3Handler(void);

void SAF_STM_Stm1Chan0Handler(void);
void SAF_STM_Stm1Chan1Handler(void);
void SAF_STM_Stm1Chan2Handler(void);
void SAF_STM_Stm1Chan3Handler(void);

void SAF_STM_Stm2Chan0Handler(void);
void SAF_STM_Stm2Chan1Handler(void);
void SAF_STM_Stm2Chan2Handler(void);
void SAF_STM_Stm2Chan3Handler(void);

#if defined (__cplusplus)
}
#endif

#endif
