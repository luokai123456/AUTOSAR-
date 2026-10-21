/**
****************************************************************************************
 * @FilePath: saf_cache.h
 * @Author: CCORE
 * @Date: 2024-03-01
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety Cache head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_CACHE_H
#define SAF_CACHE_H

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_cpu.h"
#include "saf_fccu.h"
#include "memu_lld.h"
#include "SafetyMemTst_Cfg.h"
/*PRQA S 0722,0779 EOF*/
/**
****************************************************************************************
* @brief: Macros
****************************************************************************************
*/
#define SAF_CORE_L1CSR0_SPR_ID                  (1010U)
#define SAF_CORE_L1CSR1_SPR_ID                  (1011U)
#define SAF_CORE_L1FINV0_SPR_ID                 (1016U)
#define SAF_CORE_L1FINV1_SPR_ID                 (959U)
#define SAF_CORE_DCACHE_WAY_COUNT               (2U)
#define SAF_CORE_DCACHE_SET_COUNT               (64U)
#define SAF_CORE_ICACHE_WAY_COUNT               (2U)
#define SAF_CORE_ICACHE_SET_COUNT               (64U)
#define SAF_CORE_DCACHE_SET_SIZE                (0x20U)
#define SAF_CORE_DCACHE_SET_WORD_COUNT          (SAF_CORE_ICACHE_SET_SIZE / sizeof(uint32_t))
#define SAF_CORE_ICACHE_SET_SIZE                (0x20U)
#define SAF_CORE_ICACHE_SET_WORD_COUNT          (SAF_CORE_ICACHE_SET_SIZE / sizeof(uint32_t))

#define DCR_CDADATA                             350  /*Cache Debug Access Data Register*/
#define DCR_CDACNTL                             351  /*Cache Debug Access Control Register*/

#ifndef MFDCR
#define MFDCR(dcr)                              ({uint32_t rval; PPCASM volatile("mfdcr %0," stringify(dcr) : "=r" (rval)); rval;})
#endif

#ifndef MTDCR
#define MTDCR(dcr, v)                           PPCASM volatile("mtdcr " stringify(dcr) ",%0" : : "r" (v))
#endif


/* CACHE related registers. */
/* L1CSR0 register. */
/* DCE bit fields. */
#define SAF_CACHE_L1CSR0_DCE_SHIFT              0U
#define SAF_CACHE_L1CSR0_DCE_WIDTH              1U
#define SAF_CACHE_L1CSR0_DCE_MASK               (1U << SAF_CACHE_L1CSR0_DCE_SHIFT)
#define SAF_CACHE_L1CSR0_DCE(x)                 (((uint32_t)(((uint32_t)(x)) << SAF_CACHE_L1CSR0_DCE_SHIFT)) & SAF_CACHE_L1CSR0_DCE_MASK)
/* DCINV bit fields. */
#define SAF_CACHE_L1CSR0_DCINV_SHIFT            1U
#define SAF_CACHE_L1CSR0_DCINV_WIDTH            1U
#define SAF_CACHE_L1CSR0_DCINV_MASK             (1U << SAF_CACHE_L1CSR0_DCINV_SHIFT)
#define SAF_CACHE_L1CSR0_DCINV(x)               (((uint32_t)(((uint32_t)(x)) << SAF_CACHE_L1CSR0_DCINV_SHIFT)) & SAF_CACHE_L1CSR0_DCINV_MASK)
/* DCEA bit fields. */
#define SAF_CACHE_L1CSR0_DCEA_SHIFT             5U
#define SAF_CACHE_L1CSR0_DCEA_WIDTH             2U
#define SAF_CACHE_L1CSR0_DCEA_MASK              (3U << SAF_CACHE_L1CSR0_DCEA_SHIFT)
#define SAF_CACHE_L1CSR0_DCEA(x)                (((uint32_t)(((uint32_t)(x)) << SAF_CACHE_L1CSR0_DCEA_SHIFT)) & SAF_CACHE_L1CSR0_DCEA_MASK)
/* DCEI bit fields. */
#define SAF_CACHE_L1CSR0_DCEI_SHIFT             15U
#define SAF_CACHE_L1CSR0_DCEI_WIDTH             1U
#define SAF_CACHE_L1CSR0_DCEI_MASK              (1U << SAF_CACHE_L1CSR0_DCEI_SHIFT)
#define SAF_CACHE_L1CSR0_DCEI(x)                (((uint32_t)(((uint32_t)(x)) << SAF_CACHE_L1CSR0_DCEI_SHIFT)) & SAF_CACHE_L1CSR0_DCEI_MASK)
/* DCECE bit fields. */
#define SAF_CACHE_L1CSR0_DCECE_SHIFT            16U
#define SAF_CACHE_L1CSR0_DCECE_WIDTH            1U
#define SAF_CACHE_L1CSR0_DCECE_MASK             (1U << SAF_CACHE_L1CSR0_DCECE_SHIFT)
#define SAF_CACHE_L1CSR0_DCECE(x)               (((uint32_t)(((uint32_t)(x)) << SAF_CACHE_L1CSR0_DCECE_SHIFT)) & SAF_CACHE_L1CSR0_DCECE_MASK)
/* DCWA bit fields. */
#define SAF_CACHE_L1CSR0_DCWA_SHIFT             19U
#define SAF_CACHE_L1CSR0_DCWA_WIDTH             1U
#define SAF_CACHE_L1CSR0_DCWA_MASK              (1U << SAF_CACHE_L1CSR0_DCWA_SHIFT)
#define SAF_CACHE_L1CSR0_DCWA(x)                (((uint32_t)(((uint32_t)(x)) << SAF_CACHE_L1CSR0_DCWA_SHIFT)) & SAF_CACHE_L1CSR0_DCWA_MASK)

/* L1CSR1 register. */
/* ICE bit fields. */
#define SAF_CACHE_L1CSR1_ICE_SHIFT              0U
#define SAF_CACHE_L1CSR1_ICE_WIDTH              1U
#define SAF_CACHE_L1CSR1_ICE_MASK               (1U << SAF_CACHE_L1CSR1_ICE_SHIFT)
#define SAF_CACHE_L1CSR1_ICE(x)                 (((uint32_t)(((uint32_t)(x)) << SAF_CACHE_L1CSR1_ICE_SHIFT)) & SAF_CACHE_L1CSR1_ICE_MASK)
/* ICINV bit fields. */
#define SAF_CACHE_L1CSR1_ICINV_SHIFT            1U
#define SAF_CACHE_L1CSR1_ICINV_WIDTH            1U
#define SAF_CACHE_L1CSR1_ICINV_MASK             (1U << SAF_CACHE_L1CSR1_ICINV_SHIFT)
#define SAF_CACHE_L1CSR1_ICINV(x)               (((uint32_t)(((uint32_t)(x)) << SAF_CACHE_L1CSR1_ICINV_SHIFT)) & SAF_CACHE_L1CSR1_ICINV_MASK)
/* DCEA bit fields. */
#define SAF_CACHE_L1CSR1_ICEA_SHIFT             5U
#define SAF_CACHE_L1CSR1_ICEA_WIDTH             2U
#define SAF_CACHE_L1CSR1_ICEA_MASK              (3U << SAF_CACHE_L1CSR1_ICEA_SHIFT)
#define SAF_CACHE_L1CSR1_ICEA(x)                (((uint32_t)(((uint32_t)(x)) << SAF_CACHE_L1CSR1_ICEA_SHIFT)) & SAF_CACHE_L1CSR1_ICEA_MASK)
/* ICEI bit fields. */
#define SAF_CACHE_L1CSR1_ICEI_SHIFT             15U
#define SAF_CACHE_L1CSR1_ICEI_WIDTH             1U
#define SAF_CACHE_L1CSR1_ICEI_MASK              (1U << SAF_CACHE_L1CSR1_ICEI_SHIFT)
#define SAF_CACHE_L1CSR1_ICEI(x)                (((uint32_t)(((uint32_t)(x)) << SAF_CACHE_L1CSR1_ICEI_SHIFT)) & SAF_CACHE_L1CSR1_ICEI_MASK)
/* ICECE bit fields. */
#define SAF_CACHE_L1CSR1_ICECE_SHIFT            16U
#define SAF_CACHE_L1CSR1_ICECE_WIDTH            1U
#define SAF_CACHE_L1CSR1_ICECE_MASK             (1U << SAF_CACHE_L1CSR1_ICECE_SHIFT)
#define SAF_CACHE_L1CSR1_ICECE(x)               (((uint32_t)(((uint32_t)(x)) << SAF_CACHE_L1CSR1_ICECE_SHIFT)) & SAF_CACHE_L1CSR1_ICECE_MASK)

/* Cache debug access registers. */
/* CDACNTL register. */
/* T/D bit fields. */
#define SAF_CACHE_CDACNTL_TD_SHIFT              31U
#define SAF_CACHE_CDACNTL_TD_WIDTH              1U
#define SAF_CACHE_CDACNTL_TD_MASK               (1U << SAF_CACHE_CDACNTL_TD_SHIFT)
#define SAF_CACHE_CDACNTL_TD(x)                 (((uint32_t)(((uint32_t)(x)) << SAF_CACHE_CDACNTL_TD_SHIFT)) & SAF_CACHE_CDACNTL_TD_MASK)
/* CWAY bit fields. */
#define SAF_CACHE_CDACNTL_CWAY_SHIFT            28U
#define SAF_CACHE_CDACNTL_CWAY_WIDTH            1U
#define SAF_CACHE_CDACNTL_CWAY_MASK             (1U << SAF_CACHE_CDACNTL_CWAY_SHIFT)
#define SAF_CACHE_CDACNTL_CWAY(x)               (((uint32_t)(((uint32_t)(x)) << SAF_CACHE_CDACNTL_CWAY_SHIFT)) & SAF_CACHE_CDACNTL_CWAY_MASK)
/* CSET bit fields. */
#define SAF_CACHE_CDACNTL_CSET_SHIFT            19U
#define SAF_CACHE_CDACNTL_CSET_WIDTH            7U
#define SAF_CACHE_CDACNTL_CSET_MASK             (127U << SAF_CACHE_CDACNTL_CSET_SHIFT)
#define SAF_CACHE_CDACNTL_CSET(x)               (((uint32_t)(((uint32_t)(x)) << SAF_CACHE_CDACNTL_CSET_SHIFT)) & SAF_CACHE_CDACNTL_CSET_MASK)
/* WORD bit fields. */
#define SAF_CACHE_CDACNTL_WORD_SHIFT            16U
#define SAF_CACHE_CDACNTL_WORD_WIDTH            3U
#define SAF_CACHE_CDACNTL_WORD_MASK             (7U << SAF_CACHE_CDACNTL_WORD_SHIFT)
#define SAF_CACHE_CDACNTL_WORD(x)               (((uint32_t)(((uint32_t)(x)) << SAF_CACHE_CDACNTL_WORD_SHIFT)) & SAF_CACHE_CDACNTL_WORD_MASK)
/* PARITY CHECK bit fields. */
#define SAF_CACHE_CDACNTL_PARITY_CHECK_SHIFT    8U
#define SAF_CACHE_CDACNTL_PARITY_CHECK_WIDTH    8U
#define SAF_CACHE_CDACNTL_PARITY_CHECK_MASK     (255U << SAF_CACHE_CDACNTL_PARITY_CHECK_SHIFT)
#define SAF_CACHE_CDACNTL_PARITY_CHECK(x)       (((uint32_t)(((uint32_t)(x)) << SAF_CACHE_CDACNTL_PARITY_CHECK_SHIFT)) & SAF_CACHE_CDACNTL_PARITY_CHECK_MASK)
/* CACHE bit fields. */
#define SAF_CACHE_CDACNTL_CACHE_SELECT_SHIFT    3U
#define SAF_CACHE_CDACNTL_CACHE_SELECT_WIDTH    1U
#define SAF_CACHE_CDACNTL_CACHE_SELECT_MASK     (1U << SAF_CACHE_CDACNTL_CACHE_SELECT_SHIFT)
#define SAF_CACHE_CDACNTL_CACHE_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << SAF_CACHE_CDACNTL_CACHE_SELECT_SHIFT)) & SAF_CACHE_CDACNTL_CACHE_SELECT_MASK)
/* R/W bit fields. */
#define SAF_CACHE_CDACNTL_RW_SHIFT              2U
#define SAF_CACHE_CDACNTL_RW_WIDTH              1U
#define SAF_CACHE_CDACNTL_RW_MASK               (1U << SAF_CACHE_CDACNTL_RW_SHIFT)
#define SAF_CACHE_CDACNTL_RW(x)                 (((uint32_t)(((uint32_t)(x)) << SAF_CACHE_CDACNTL_RW_SHIFT)) & SAF_CACHE_CDACNTL_RW_MASK)
/* GO bit fields. */
#define SAF_CACHE_CDACNTL_GO_SHIFT              0U
#define SAF_CACHE_CDACNTL_GO_WIDTH              2U
#define SAF_CACHE_CDACNTL_GO_MASK               (3U << SAF_CACHE_CDACNTL_GO_SHIFT)
#define SAF_CACHE_CDACNTL_GO(x)                 (((uint32_t)(((uint32_t)(x)) << SAF_CACHE_CDACNTL_GO_SHIFT)) & SAF_CACHE_CDACNTL_GO_MASK)

/* Define cache test flag. */
#define CACHE_SAFETY_OP_INITIAL                             1U
#define CACHE_SAFETY_OP_CHANGED                             0U

#define SAF_CACHE_INVALIDATE_COUNT                          1000U
#define SAF_CACHE_DCACHE_INVALIDATE_TIME_OUT                100U
#define SAF_CACHE_ICACHE_INVALIDATE_TIME_OUT                300U

#define SAF_CACHE_ICACHE_LOAD_VALUE                         0x00040004U /**< The bl instruction. */
#define SAF_CACHE_DCACHE_LOAD_VALUE                         0x00040004U

#define SAF_CACHE_REGISTER_BITS_SET_VALUE(x)                ((uint32_t)x)
#define SAF_CACHE_REGISTER_BITS_CLEAR_VALUE                 (0U)

/* DC_DPERR. */
#define SAF_MCSR_DACHE_DATA_ARRAY_PARITY_ERROR_OCCURRED      1U
#define SAF_MCSR_DACHE_DATA_ARRAY_PARITY_ERROR_NOT_OCCURRED  0U

/* IC_DPERR. */
#define SAF_MCSR_IACHE_DATA_ARRAY_PARITY_ERROR_OCCURRED      1U
#define SAF_MCSR_IACHE_DATA_ARRAY_PARITY_ERROR_NOT_OCCURRED  0U

/* DCWA. */
#define SAF_CACHE_DCACHE_LINE_ALLOCATION_ENABLE              1U
#define SAF_CACHE_DCACHE_LINE_ALLOCATION_DISABLE             0U
/* DCEA. */
#define SAF_CACHE_DCACHE_ERROR_ACTION_AUTO_HANDLE_SELECT     1U
#define SAF_CACHE_DCACHE_ERROR_ACTION_MACHINE_CHECK_SELECT   0U
/* DCEI. */
#define SAF_CACHE_DCACHE_ERROR_INJECTION_ENABLE              1U
#define SAF_CACHE_DCACHE_ERROR_INJECTION_DISABLE             0U
/* DCECE. */
#define SAF_CACHE_DCACHE_ERROR_CHECKING_ENABLE               1U
#define SAF_CACHE_DCACHE_ERROR_CHECKING_DISABLE              0U
/* DCINV. */
#define SAF_CACHE_DCACHE_INVALIDATION_OPERATION              1U
#define SAF_CACHE_DCACHE_NO_INVALIDATION_OPERATION           0U
/* DCE. */
#define SAF_CACHE_DCACHE_ENABLE                              1U
#define SAF_CACHE_DCACHE_DISABLE                             0U

/* ICEA. */
#define SAF_CACHE_ICACHE_ERROR_ACTION_AUTO_HANDLE_SELECT     1U
#define SAF_CACHE_ICACHE_ERROR_ACTION_MACHINE_CHECK_SELECT   0U
/* ICEI. */
#define SAF_CACHE_ICACHE_ERROR_INJECTION_ENABLE              1U
#define SAF_CACHE_ICACHE_ERROR_INJECTION_DISABLE             0U
/* ICECE. */
#define SAF_CACHE_ICACHE_ERROR_CHECKING_ENABLE               1U
#define SAF_CACHE_ICACHE_ERROR_CHECKING_DISABLE              0U
/* ICINV. */
#define SAF_CACHE_ICACHE_INVALIDATION_OPERATION              1U
#define SAF_CACHE_ICACHE_NO_INVALIDATION_OPERATION           0U
/* ICE. */
#define SAF_CACHE_ICACHE_ENABLE                              1U
#define SAF_CACHE_ICACHE_DISABLE                             0U

#define SAF_CACHE_ICACHE_CLEAN_CHECK_BITS_MASK               (SAF_CACHE_L1CSR1_ICEI_MASK | SAF_CACHE_L1CSR1_ICECE_MASK)
#define SAF_CACHE_ICACHE_CLEAN_CHECK_BITS_CLEARD             0U
#define SAF_CACHE_L1CSR1_CLEAR_VALUE                         0U

#define SAF_CACHE_DCACHE_CLEAN_CHECK_BITS_MASK               (SAF_CACHE_L1CSR0_DCEI_MASK | SAF_CACHE_L1CSR0_DCECE_MASK | SAF_CACHE_L1CSR0_DCWA_MASK)
#define SAF_CACHE_DCACHE_CLEAN_CHECK_BITS_CLEARD             0U
#define SAF_CACHE_L1CSR0_CLEAR_VALUE                         0U

#define SAF_CACHE_ICACHE_ERROR_INJECTION_BITS_SET           (SAF_CACHE_L1CSR1_ICE(SAF_CACHE_ICACHE_ENABLE)\
                                                                | SAF_CACHE_L1CSR1_ICINV(SAF_CACHE_ICACHE_INVALIDATION_OPERATION)\
                                                                | SAF_CACHE_L1CSR1_ICEI(SAF_CACHE_ICACHE_ERROR_INJECTION_ENABLE)\
                                                                | SAF_CACHE_L1CSR1_ICECE(SAF_CACHE_ICACHE_ERROR_CHECKING_ENABLE))
#define SAF_CACHE_DCACHE_ERROR_INJECTION_BITS_SET           (SAF_CACHE_L1CSR0_DCE(SAF_CACHE_DCACHE_ENABLE)\
                                                                | SAF_CACHE_L1CSR0_DCINV(SAF_CACHE_DCACHE_INVALIDATION_OPERATION)\
                                                                | SAF_CACHE_L1CSR0_DCEI(SAF_CACHE_DCACHE_ERROR_INJECTION_ENABLE)\
                                                                | SAF_CACHE_L1CSR0_DCECE(SAF_CACHE_ICACHE_ERROR_CHECKING_ENABLE)\
                                                                | SAF_CACHE_L1CSR0_DCWA(SAF_CACHE_DCACHE_LINE_ALLOCATION_ENABLE))

/* T/D. */
#define SAF_CACHE_CDACNTL_TAG_ARRAY_SELECT                  1U
#define SAF_CACHE_CDACNTL_DATA_ARRAY_SELECT                 0U

/* CACHE. */
#define SAF_CACHE_CDACNTL_INSTRUCTION_CACHE_SELECT          1U
#define SAF_CACHE_CDACNTL_DATA_CACHE_SELECT                 0U

/* R/W. */
#define SAF_CACHE_CDACNTL_CACHE_ACCESS_READ_SELECT          1U
#define SAF_CACHE_CDACNTL_CACHE_ACCESS_WRITE_SELECT         0U

/* GO. */
#define SAF_CACHE_CDACNTL_GO_COMMAND_RW_ACTION_SELECT       1U
#define SAF_CACHE_CDACNTL_GO_COMMAND_NO_ACTION_SELECT       0U

#define SAF_CACHE_WAY_SELECT                                0x0U
#define SAF_CACHE_SET_SELECT                                0x0U
#define SAF_CACHE_WORD_SELECT                               0x0U

#define SAF_CACHE_SBE_INJECT_XOR_DATA                       0x01U
#define SAF_CACHE_MBE_INJECT_XOR_DATA                       0x03U

#define SAF_CACHE_TEST_SET_COUNT                            4U

#if SAF_CACHE_SUPPORTED


/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/
/**
* @brief  CACHE test ptr.
*/
typedef void (*icache_func_ptr_t)(void);

/**
* @brief  CACHE type.
*/
typedef enum
{
    SAF_CACHE_TYPE_DCACHE = 0U,
    SAF_CACHE_TYPE_ICACHE,
    SAF_CACHE_TYPE_COUNT
} SAF_CACHE_TYPE;

/**
* @brief CACHE error auto handle test type.
*/
typedef enum
{
    /* The single-bit correction. */
    SAF_CACHE_TEST_TYPE_SBC = 0U,
    /* The muti-bit invalidation. */
    SAF_CACHE_TEST_TYPE_MBE,
    /* The count of CACHE error auto handle test type. */
    SAF_CACHE_TEST_TYPE_COUNT
} SAF_CACHE_ERR_AUTO_HANDLE_TEST_TYPE;

/**
 * @brief  CACHE EDC report path test result structure.
 */
typedef struct
{
    /* Dcache test result, 1 for passed, 0 for not passed */
    bool dcacheTestPassed;
    /* Icache test result, 1 for passed, 0 for not passed */
    bool icacheTestPassed;
} saf_cache_edc_report_path_test_result_t;

/**
 * @brief  CACHE EDC report path test structure.
 */
typedef struct
{
    /* The CACHE EDC report path test result structure */
    saf_cache_edc_report_path_test_result_t output;
} saf_cache_edc_report_path_test_t;

/**
****************************************************************************************
 * @brief: Function Prototypes
****************************************************************************************
*/

FS_STATUS SAF_CACHE_Disable(const SAF_CACHE_TYPE cacheType);

FS_STATUS SAF_CACHE_Enable(const SAF_CACHE_TYPE cacheType);

FS_STATUS SAF_CACHE_EdcReportPathTest(void);

FS_STATUS SAF_CACHE_EdcReportPathTestResult(saf_cache_edc_report_path_test_result_t *pTestResult);

FS_STATUS SAF_CACHE_ConfigCmpu(void);

void SAF_CACHE_IvorHandler(void);

void SAF_CACHE_AccessEnableDcache(void);
void SAF_CACHE_AccessEnableIcache(void);
void SAF_CACHE_AccessDisableDcache(void);
void SAF_CACHE_AccessDisableIcache(void);
bool SAF_CACHE_AccessDcacheIsEnabled(void);
bool SAF_CACHE_AccessIcacheIsEnabled(void);

FS_STATUS SAF_CACHE_ErrorAutoHandleTest(void);

#endif

#ifdef __cplusplus
}
#endif

#endif
