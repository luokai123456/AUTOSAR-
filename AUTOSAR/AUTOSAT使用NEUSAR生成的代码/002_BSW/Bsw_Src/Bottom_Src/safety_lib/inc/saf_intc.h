/**
****************************************************************************************
 * @FilePath: saf_intc.h
 * @Author: CCORE
 * @Date: 2024-02-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: INTC Head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_INTC_H
#define SAF_INTC_H

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_common.h"
#include "mcu_lld.h"
#include "intc_lld.h"
#include "saf_cpu.h"
#include "saf_fccu.h"
#include "SafetyPeriphTst_Cfg.h"

#define FCCU_INTC_MON_ERR_MASK          0x38000000U
/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/
typedef boolean (*saf_intc_check_int_status_func)(void);

/**
* @brief  Interrupt monitor manage structure.
*/
typedef struct 
{
    /*Records the flag bits for spurious monitoring interrupts.*/
    boolean spuriousFlag[SAF_INTC_IRQ_COUNT];
    /*Records the flag bits for missing monitoring interrupts.*/
    boolean missingFlag[SAF_INTC_IRQ_COUNT];
} saf_intc_mgr_monitor_type_t;

/**
* @brief  Interrupt monitor test parameter structure.
*/
typedef struct
{
    /**
    * @brief  The Number of monitored interrupts .
    */
    uint16_t monitorCount;
    /**
    * @brief  Records monitored interruptions.
    */
    uint16_t irqNoMapArray[SAF_INTC_MONITOR_COUNT];
    /**
    * @brief  interrupt status check function.
    */
    saf_intc_check_int_status_func irqStatusChecApi[SAF_INTC_MONITOR_COUNT];
} saf_intc_monitor_test_param_t;

/**
* @brief  Interrupt monitor test result structure.
*/
typedef struct
{
    /**
    * @brief  Records missing results of monitored interruptions.
    */
    uint8_t missingIrqBitmapArray[(SAF_INTC_MONITOR_IRQ_COUNT >> SAF_DIV_8_RIGHT_SHIFT_BIT)+1];/*PRQA S 1840*/
    /**
    * @brief  Records spurious results of monitored interruptions.
    */
    uint8_t spuriousIrqBitmapArray[(SAF_INTC_MONITOR_IRQ_COUNT >> SAF_DIV_8_RIGHT_SHIFT_BIT)+1];/*PRQA S 1840*/
} saf_intc_monitor_test_result_t;

/**
****************************************************************************************
 * @brief: Function prototypes
****************************************************************************************
*/
FS_STATUS SAF_INTC_CheckSpuriousInterrupt(const uint32_t irq);

FS_STATUS SAF_INTC_CheckMissingInterrupt(void);

void SAF_IntcRuntimeSafetyTestInit(void);

FS_STATUS SAF_INTC_IrqMonitorTest(void);

FS_STATUS SAF_INTC_IrqMonitorTestResult(saf_intc_monitor_test_result_t *pTestResult); 

void SAF_INTC_Get_Core_Id(uint8_t *id);

void SAF_INTC_IrqMonitorFault(void);

FS_STATUS SAF_INTC_MonitorReportPathTest(void);

FS_STATUS SAF_INTC_Get_Global_Priority(uint32_t* intr_prior);


#ifdef __cplusplus
}
#endif

#endif/* SAF_INTC_H */

