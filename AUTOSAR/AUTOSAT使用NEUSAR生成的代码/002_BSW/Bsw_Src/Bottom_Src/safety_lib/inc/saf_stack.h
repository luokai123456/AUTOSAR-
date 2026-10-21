/**
****************************************************************************************
 * @FilePath: saf_stack.h
 * @Author: CCORE
 * @Date: 2024-03-12
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety stack head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_STACK_H
#define SAF_STACK_H

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_common.h"

/**
****************************************************************************************
 * @brief: Global Variable
****************************************************************************************
*/
extern uint32_t SAF_STACK_MONITOR_BOTTOM_LIMIT_ADDR; /* parasoft-suppress MISRAC2012-RULE_8_6-a "extern function from Linker file" */
extern uint32_t SAF_STACK_TOP_ADDR; /* parasoft-suppress MISRAC2012-RULE_8_6-a "extern function from Linker file" */
extern uint32_t SAF_STACK_BOTTOM_ADDR; /* parasoft-suppress MISRAC2012-RULE_8_6-a "extern function from Linker file" */

/**
****************************************************************************************
* @brief: Macros
****************************************************************************************
*/
#define SAF_STACK_DAC_TRIGGER_EXCEPTION                      (0U)

#define SAF_STACK_DAC_MAX_BIT_MASK                           (12U)   /* max 4k, 0x1 << 12 */
#define SAF_STACK_DAC_DISABLE_DEBUG_EVENT                    (0x00U)
#define SAF_STACK_DAC_EABLE_DEBUG_EVENT_STROE                (0x01U)
#define SAF_STACK_DAC_EABLE_DEBUG_EVENT_LOAD                 (0x02U)
#define SAF_STACK_DAC_EABLE_DEBUG_EVENT_STROE_AND_LOAD       (0x03U)

/* Debug related registers. */
/* DBCR0(Debug Control Register 0). */
/* DAC2 bit fields. */
#define SAF_DEBUG_DBCR0_DAC2_SHIFT              16U
#define SAF_DEBUG_DBCR0_DAC2_WIDTH              2U
#define SAF_DEBUG_DBCR0_DAC2_MASK               (3U << SAF_DEBUG_DBCR0_DAC2_SHIFT)
#define SAF_DEBUG_DBCR0_DAC2(x)                 (((uint32_t)(((uint32_t)(x)) << SAF_DEBUG_DBCR0_DAC2_SHIFT)) & SAF_DEBUG_DBCR0_DAC2_MASK)
/* DAC1 bit fields. */
#define SAF_DEBUG_DBCR0_DAC1_SHIFT              18U
#define SAF_DEBUG_DBCR0_DAC1_WIDTH              2U
#define SAF_DEBUG_DBCR0_DAC1_MASK               (3U << SAF_DEBUG_DBCR0_DAC1_SHIFT)
#define SAF_DEBUG_DBCR0_DAC1(x)                 (((uint32_t)(((uint32_t)(x)) << SAF_DEBUG_DBCR0_DAC1_SHIFT)) & SAF_DEBUG_DBCR0_DAC1_MASK)
/* IDM bit fields. */
#define SAF_DEBUG_DBCR0_IDM_SHIFT               30U
#define SAF_DEBUG_DBCR0_IDM_WIDTH               1U
#define SAF_DEBUG_DBCR0_IDM_MASK                (1U << SAF_DEBUG_DBCR0_IDM_SHIFT)
#define SAF_DEBUG_DBCR0_IDM(x)                  (((uint32_t)(((uint32_t)(x)) << SAF_DEBUG_DBCR0_IDM_SHIFT)) & SAF_DEBUG_DBCR0_IDM_MASK)
/* EDM bit fields. */
#define SAF_DEBUG_DBCR0_EDM_SHIFT               31U
#define SAF_DEBUG_DBCR0_EDM_WIDTH               1U
#define SAF_DEBUG_DBCR0_EDM_MASK                (1U << SAF_DEBUG_DBCR0_EDM_SHIFT)
#define SAF_DEBUG_DBCR0_EDM(x)                  (((uint32_t)(((uint32_t)(x)) << SAF_DEBUG_DBCR0_EDM_SHIFT)) & SAF_DEBUG_DBCR0_EDM_MASK)

/* DBSR(Debug Status Register). */
/* DACW bit fields. */
#define SAF_DEBUG_DBSR_DACW_SHIFT               18U
#define SAF_DEBUG_DBSR_DACW_WIDTH               1U
#define SAF_DEBUG_DBSR_DACW_MASK                (1U << SAF_DEBUG_DBSR_DACW_SHIFT)
#define SAF_DEBUG_DBSR_DACW(x)                  (((uint32_t)(((uint32_t)(x)) << SAF_DEBUG_DBSR_DACW_SHIFT)) & SAF_DEBUG_DBSR_DACW_MASK)
/* DACR bit fields. */
#define SAF_DEBUG_DBSR_DACR_SHIFT               19U
#define SAF_DEBUG_DBSR_DACR_WIDTH               1U
#define SAF_DEBUG_DBSR_DACR_MASK                (1U << SAF_DEBUG_DBSR_DACR_SHIFT)
#define SAF_DEBUG_DBSR_DACR(x)                  (((uint32_t)(((uint32_t)(x)) << SAF_DEBUG_DBSR_DACR_SHIFT)) & SAF_DEBUG_DBSR_DACR_MASK)

#define SAF_STACK_WRITE_VALUE                   0x12345678U

#define SAF_DEBUG_REGISTER_BITS_SET_VALUE(x)    ((uint32_t)x)
#define SAF_DEBUG_REGISTER_BITS_CLEAR_VALUE     (0U)
#define SAF_DEBUG_REGISTER_LSB_MASK             1U

/* IDM. */
#define SAF_DEBUG_INTERNAL_DEBUG_MODE_ENABLE    1U
#define SAF_DEBUG_INTERNAL_DEBUG_MODE_DISABLE   0U
/* EDM. */
#define SAF_DEBUG_EXTERNAL_DEBUG_MODE_ENABLE    1U
#define SAF_DEBUG_EXTERNAL_DEBUG_MODE_DISABLE   0U

/* DAC12M. */
#define SAF_DEBUG_DAC_MODE_EXACT_ADDRESS_COMPARE            0U
#define SAF_DEBUG_DAC_MODE_ADDRESS_BIT_MATCH                1U
#define SAF_DEBUG_DAC_MODE_INCLUSIVE_ADDRESS_RANGE_COMPARE  2U
#define SAF_DEBUG_DAC_MODE_EXCLUSIVE_ADDRESS_RANGE_COMPARE  3U
/* DE. */
#define SAF_DEBUG_INTERRUPT_ENABLE              1U
#define SAF_DEBUG_INTERRUPT_DISABLE             0U

/* DACR. */
#define SAF_DEBUG_DAC_READ_EVENT_OCCURRED       1U
#define SAF_DEBUG_DAC_READ_EVENT_NOT_OCCURRED   0U
/* DACR clear. */
#define SAF_DEBUG_DAC_READ_EVENT_CLEAR          1U

/* DACW. */
#define SAF_DEBUG_DAC_WRITE_EVENT_OCCURRED      1U
#define SAF_DEBUG_DAC_WRITE_EVENT_NOT_OCCURRED  0U
/* DACW clear. */
#define SAF_DEBUG_DAC_WRITE_EVENT_CLEAR         1U


/* DACW clear. */
#define SAF_DEBUG_DAC_WRITE_EVENT_CLEAR         1U

#define SAF_STACK_DAC_EVENT_CHECK_BITS_MASK     (SAF_DEBUG_DBSR_DACW_MASK | SAF_DEBUG_DBSR_DACR_MASK)
#define SAF_STACK_DAC_EVENT_CHECK_BITS_CLEARD   0U

#define SAF_STACK_DBSR_CLEAR_VALUE              0U

#ifndef  MFMSR
#define MFMSR()                                             ({unsigned int rval; PPCASM volatile("mfmsr %0" : "=r" (rval)); rval;})
#endif

#ifndef  MTMSR
#define MTMSR(v)                                            ({unsigned int rval = v; PPCASM volatile("mtmsr %0" : "=r" (rval)); rval;}) 
#endif

/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/
/**
* @brief  The stack monitor test result structure.
*/
typedef struct
{
    bool overflowPassed;
    bool underflowPassed;
} saf_stack_monitor_test_result_t;

/**
* @brief  The stack monitor test structure.
*/
typedef struct
{
    saf_stack_monitor_test_result_t output;
} saf_stack_monitor_test_t;

/**
****************************************************************************************
 * @brief: Function Prototypes
****************************************************************************************
*/
void SAF_STACK_MonitorDisable(void);

FS_STATUS SAF_STACK_MonitorEnable(void);

void SAF_STACK_CleanDbsrDac(void);

uint32_t SAF_STACK_GetDbsrValue(void);

FS_STATUS SAF_STACK_CheckStatus(void);

FS_STATUS SAF_STACK_MonitorTest(void);

FS_STATUS SAF_STACK_MonitorTestResult(saf_stack_monitor_test_result_t *pTestResult);


#if defined (__cplusplus)
}
#endif

#endif

