/**
****************************************************************************************
 * @FilePath: saf_pit.h
 * @Author: CCORE
 * @Date: 2024-02-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: Pit Head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_PIT_H
#define SAF_PIT_H

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
#include "Gpt_Pit_LLDriver.h"
#include "SafetyPeriphTst_Cfg.h"

/**
****************************************************************************************
 * @brief: Macros
****************************************************************************************
*/
#define SAF_PIT_MONITOR_TIMER_NUM               (4U)
#define SAF_PIT_FULL_RANGE                      (100U)
#define SAF_PIT_DEFAULT_NUMBER                  (0xFFU)
#define SAF_PIT_DET_ERR(x)                      DEV_ASSERT(x)

#define SAF_PIT0_CHANNEL_COUNT                                	(8UL)

#define SAF_PIT1_CHANNEL_COUNT                                	(8UL)

#define SAF_PIT_INSTANCE_COUNT                              	(2UL)

#define SAF_PIT_CHANNEL_COUNT                                	(8UL)

#define SAF_PIT_CHAN_COUNT                              		{SAF_PIT0_CHANNEL_COUNT, SAF_PIT1_CHANNEL_COUNT}

/**
****************************************************************************************
 * @brief: Enum
****************************************************************************************
*/
/**
* @brief The pit timer config status.
*/
typedef enum
{
    /* This parameter represents pit config uninit. */
    SAF_PIT_CONFIG_UNINIT = 0,
    /* This parameter represents pit config init. */
    SAF_PIT_CONFIG_INIT,
    /* This parameter represents pit config init error. */
    SAF_PIT_CONFIG_INIT_ERROR
} saf_pit_config_status_type;
/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/

/**
* @brief  The PIT timer monitor manage structure.
*/
typedef struct
{
	/* User call back function */
    saf_intc_irq_callback callback[SAF_PIT_INSTANCE_COUNT][SAF_PIT_CHANNEL_COUNT];
    /* monitor timer max error. */
    uint32_t monitorTimerMaxErrUs[SAF_PIT_INSTANCE_COUNT][SAF_PIT_CHANNEL_COUNT];
    /* Monitor timer number. */
    uint32_t monitorTimerNo[SAF_PIT_INSTANCE_COUNT][SAF_PIT_CHANNEL_COUNT];
    /* Monitor timer Period. */
    uint32_t monitorTimerPeriod[SAF_PIT_INSTANCE_COUNT][SAF_PIT_CHANNEL_COUNT];
    /* Monitor timer error range. */
    uint32_t monitorTimerErrRange[SAF_PIT_INSTANCE_COUNT][SAF_PIT_CHANNEL_COUNT];
    /* Monitor timer initialized. */
    bool initialized;
    /* Monitor timer Enable. */
    bool monitorTimerEnable[SAF_PIT_INSTANCE_COUNT][SAF_PIT_CHANNEL_COUNT];
    /* Monitor timer Accuracy. */
    bool monitorTimerAccuracy[SAF_PIT_INSTANCE_COUNT][SAF_PIT_CHANNEL_COUNT];
    /* This parameter represents monitor timer well. */
    bool monitorTimerWell[SAF_PIT_INSTANCE_COUNT][SAF_PIT_CHANNEL_COUNT];
} saf_pit_timer_monitor_t;

/**
* @brief  The PIT timer monitor information structure.
*/
typedef struct
{
	/* User call back function */
    saf_intc_irq_callback callback;
    /* Timer period error range ration(%). */
    uint32_t periodErrRangeRatio;
    /* Pit channel period configuration */
    uint32_t periodUs;
    /* Pit channel select */
    uint32_t chan;
    /* Pit interrupt priority */
    uint8_t priority;
    /* Channel monitor flag */
    bool needToMonitor;
    /* This parameter represents pit monitor enable flag. */
    bool MonitorEnable;
} saf_pit_timer_config_data_t;

/**
* @brief  The PIT timer monitor test result structure.
*/
typedef struct
{
    /* This parameter represents configured pit instance. */
	saf_pit_config_status_type configured[SAF_PIT_INSTANCE_COUNT];
    /* pit timer max error. */
    uint32_t pitTimerMaxErrRang [SAF_PIT_INSTANCE_COUNT][SAF_PIT_CHANNEL_COUNT];
    /* This parameter represents pit timer monitor failed bit map. */
    uint32_t pitTimerMonitorFailedBitmap[SAF_PIT_INSTANCE_COUNT][SAF_PIT_CHANNEL_COUNT];
    /* This parameter represents pit timer work not accurate bit map. */
    uint32_t pitTimerNotAccurateBitmap[SAF_PIT_INSTANCE_COUNT][SAF_PIT_CHANNEL_COUNT];
} saf_pit_timer_monitor_test_result_t;

/**
* @brief The pit timer monitor data manage structure.
*/
typedef struct
{
    /*!< This parameter represents current timer counter. */
    uint32_t curTimerCounter[SAF_PIT_MONITOR_TIMER_NUM];
    /*!< This parameter represents pit timer monitor period. */
    uint32_t pitPeriodUs;
    /*!< This parameter represents use timer configuration. */
    bool timerConfigured[SAF_PIT_MONITOR_TIMER_NUM];
    /*!< This parameter represents timer enable. */
    bool timerEnable[SAF_PIT_MONITOR_TIMER_NUM];
    /*!< This parameter represents timer monitor enable flag. */
    bool MonitorEnable[SAF_PIT_INSTANCE_COUNT][SAF_PIT_CHANNEL_COUNT];
} saf_pit_monitor_timer_data_t;

/**
****************************************************************************************
 * @brief: Global Variable
****************************************************************************************
*/
extern const saf_pit_timer_config_data_t s_SafPitTimerConfig[SAF_PIT_TEST_USED_CHANNEL];

/**
****************************************************************************************
 * @brief: Function prototypes
****************************************************************************************
*/
FS_STATUS SAF_PIT_ConfigDataInit(void);

FS_STATUS SAF_PIT_TimerMonitorTestResult(saf_pit_timer_monitor_test_result_t *pTestResult);

FS_STATUS SAF_PIT_TimerMonitorTestInit(const saf_pit_timer_monitor_test_result_t *pTestConfig);

FS_STATUS SAF_PitRuntimeSafetyTestInit(void);

FS_STATUS SAF_PIT_TimerMonitorTest(void);

FS_STATUS SAF_PIT_DisableMonitorTimer(const uint32_t timerNo);

FS_STATUS SAF_PIT_EnableMonitorTimer(const uint32_t timerNo);

FS_STATUS SAF_PIT_DeleteMonitorTimer(const uint32_t timerNo);

FS_STATUS SAF_PIT_AddMonitorTimer(uint32_t *pTimerNo);

void SAF_PIT_IrqHandler(const uint8_t pitInst,const uint8_t chan);

FS_STATUS SAF_PIT_GetMonitorTimerPeriodUs(uint32_t timerNo, uint32_t *pPeriodUs);

void SAF_PIT_Pit0Chan0Handler(void);
void SAF_PIT_Pit0Chan1Handler(void);
void SAF_PIT_Pit0Chan2Handler(void);
void SAF_PIT_Pit0Chan3Handler(void);
void SAF_PIT_Pit0Chan4Handler(void);
void SAF_PIT_Pit0Chan5Handler(void);
void SAF_PIT_Pit0Chan6Handler(void);
void SAF_PIT_Pit0Chan7Handler(void);

void SAF_PIT_Pit1Chan0Handler(void);
void SAF_PIT_Pit1Chan1Handler(void);

#if defined (__cplusplus)
}
#endif

#endif
