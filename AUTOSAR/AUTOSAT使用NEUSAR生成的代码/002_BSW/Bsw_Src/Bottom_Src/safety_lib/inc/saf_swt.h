/**
****************************************************************************************
 * @FilePath: saf_swt.h
 * @Author: CCORE
 * @Date: 2024-03-01
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: Swt Head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_SWT_H
#define SAF_SWT_H

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/

#include "intc_lld.h"
#include "saf_common.h"
#include "saf_ccfc30xx.h"
#include "saf_cpu.h"
#include "mcu_lld.h"
#include "Wdg_LLDriver.h"
/*PRQA S 2052 EOF*/
/**
****************************************************************************************
 * @brief: Macros
****************************************************************************************
*/
#define SAF_SWT_MONITOER_TIMER_INT_PRIORITY                  (15U)

#define SAF_SWT_MONITOR_TIMER_NUM                            (8U)

#define SAF_SWT_FIXED_SERVICE_DATA_LIST                      {0xA602U, 0xB480U}

#define SAF_SWT_INST_FCCU_FAULT_INDEX                        {FCCU_FAILURE_SWT0_RESET_REQ_CH_15 ,FCCU_FAILURE_SWT1_RESET_REQ_CH_13 ,FCCU_FAILURE_SWT2_RESET_REQ_CH_12 ,FCCU_FAILURE_SWT3_RESET_REQ_CH_55}
#if defined(CCFC3008PC) | defined(CCFC3008PCSN)
#define SWT1_IRQn 33
#define SWT2_IRQn 34
#endif
#ifndef CCFC3012PT
#define SWT4_IRQn 220
#define SWT5_IRQn 219
#define SWT6_IRQn 218
#endif
#define SWT_IRQS                                 { (IntrId)SWT0_IRQn, (IntrId)SWT1_IRQn, (IntrId)SWT2_IRQn, (IntrId)SWT3_IRQn, (IntrId)SWT4_IRQn, (IntrId)SWT5_IRQn, (IntrId)SWT6_IRQn}
#define SAF_SWT_INTERRUPT_FLAG                              (1U)
#define SAF_SWT_INSTANCE_COUNT                  			(8U)


#define SAF_FEATURE_SIRCOSC0_FREQ                           (128000U)
#define SAF_SIRC_DEFAULT_DIV                                (4U)
#define SAF_SWT_REG_READBACK                            	(1U)
#define SAF_SWT_REG_ENABLE                                  (1U)
#define SAF_SWT_REG_DISABLE                                 (0U)
#define SAF_SWT_IR_MASK                                     (0U)
#define SAF_SWT_CLEAR_IR_MASK                               (0x1U)
#define FEATURE_SWT_UNLOCK_VALUE1                           (0xC520U)
#define FEATURE_SWT_UNLOCK_VALUE2                           (0xD928U)

/* @brief The reset value of the control register */
#define FEATURE_SWT_CR_RESET_VALUE          (0xFF00010AU)
/* @brief The reset value of the timeout register */
#define FEATURE_SWT_TO_RESET_VALUE          (0x5FCD0U)
/* @brief The reset value of the window register */
#define FEATURE_SWT_WN_RESET_VALUE          (0x0U)
/* @brief The reset value of the service key register */
#define FEATURE_SWT_SK_RESET_VALUE          (0x0U)
/* @brief The minimum timeout value */
#define FEATURE_SWT_TO_MINIMUM_VALUE        (0x100U)

/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/
/**
* @brief  The swt path test result structure.
*/
typedef struct
{
    /* This parameter represents swt path test check passed mark. */
    bool PathTestCheckPassed[SWT_INSTANCE_COUNT];
} saf_swt_path_test_result_t;

/**
* @brief  The swt config type structure.
*/
typedef struct
{
    /* The structure contains the configuration of the swt module Settings. */
    SWT_Module_Config_Type (*pUsedSwtConfig)[];
} saf_swt_config_type;

/**
****************************************************************************************
 * @brief: Function prototypes
****************************************************************************************
*/
bool SAF_SWT_MonitorPeriodIsAvailable(const uint8_t swtInst, const uint32_t fttiPeriodUs);

FS_STATUS SAF_SWT_EnableHardlock(const uint8_t swtInst);

FS_STATUS SAF_SWT_PathTest(void);

FS_STATUS SAF_SWT_Deinit(const uint8_t swtInst);

bool SAF_SWT_SwtIsEnabled(const uint8_t swtInst);

bool SAF_SWT_CheckHardlock(const uint8_t swtInst);

FS_STATUS SAF_SWT_PathTestResult(saf_swt_path_test_result_t *pTestResult);

bool SAF_SWT_IsInstanceAvailable(SWT_ModuleID_Type swtInst);
#ifdef __cplusplus
}
#endif

#endif
