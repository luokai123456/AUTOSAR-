/**
****************************************************************************************
 * @FilePath: saf_flash.h
 * @Author: CCORE
 * @Date: 2024-02-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety flash head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_FLASH_H
#define SAF_FLASH_H

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_common.h"
#include "saf_ccfc30xx.h"
#include "saf_mem.h"
#include "saf_memu.h"
#include "saf_bist.h"
#include "../../safety_lld/inc/flash_lld.h"
#include "memu_lld.h"
#include "SafetyMemTst_Cfg.h"
#include "Saf_MemMap.h"
/*PRQA S 0722,0779,1336,1535,2052,3108,4491,4499 EOF*/
/**
****************************************************************************************
* @brief: Macros
****************************************************************************************
*/
//#define START_FUNCTION_DECLARATION_RAMSECTION      __attribute__((section (".fuc_ram")))

/* UTEST Customer Single Bit Correction Area. */
#define SAF_FLASH_ECC_CE_TRIGGER_ADDRESS                     0x00400040U
/* UTEST Customer Double Bit Detection Area. */
#define SAF_FLASH_ECC_UCE_TRIGGER_ADDRESS                    0x00400060U

#define SAF_FLASH_OVERLAY_RAM_TEST_CRD_INDEX                 0U
#define SAF_FLASH_OVERLAY_RAM_TEST_FIRST_WRITE_WORD_DATA     0x11111111U
#define SAF_FLASH_OVERLAY_RAM_TEST_SECOND_WRITE_WORD_DATA    0x22222222U

#define SAF_FLASH_SAFETY_INFO_STORE_INITIALIZED              1U
#define SAF_FLASH_SAFETY_INFO_STORE_UNINITIALIZED            0U
#define SAF_FLASH_SAFETY_INFO_STORE_INVALID_VALUE            0XFFFFFFFFU

#define SAF_FLASH_ECC_BIT_ERROR_TYPE_VALID_VALUE             1U
#define SAF_FLASH_ECC_BIT_ERROR_TYPE_INVALID_VALUE           0U

#define SAF_FLASH_ECC_CE_TEST_ADDRESS_CHECK_OFFEST           0U

#define SAF_FLASH_BLOCK_STATE_LOCK                           1U
#define SAF_FLASH_BLOCK_STATE_UNLOCK                         0U

#define SAF_FLASH_BLOCK_SELECT_BITS_MASK(x)                  (1U << x)
#define SAF_FLASH_MAX_BLOCK_SELECTED                         32U
#define SAF_FLASH_NONE_BLOCK_SELECTED                        0U


#define SAF_SCH_PROGRAM_SAFETY_INFO_TIMEOUT_MS               (5000)
#define SAF_SCH_ERASE_SAFETY_INFO_TIMEOUT_MS                 (5000)

#define SAF_SCH_WAIT_WHILE_OPERATION_TIMEOUT_CNT             (0xFFFFFFFFU)

/* for Overlay test, flash address and Sram address */
#define SAF_FLASH_OVERLAY_TEST_FLASH_ADDR                0x00FE0000U
#define SAF_FLASH_OVERLAY_TEST_SRAM_ADDR                 0x400D0000U
#define SAF_FLASH_OVERLAY_TEST_FLASH_MIRR_ADDR           0x08FE0000U
#define SAF_FLASH_OVERLAY_TEST_REMAP_SIZE                0x800U

#define SAF_FLASH_DCF_HSM_PROGRAM                        (0U)

#define SAF_FLASH_CALC_MISR_BY_AI                        (0U)
#define SAF_FLASH_CALC_MISR_BY_MR                        (1U)
#define SAF_FLASH_CALC_MISR_BY_NONE                      (2U)

#define SAF_FLASH_CDR_NUM_ALL                            (32U)
#define SAF_FLASH_PFCDRN_MASK                            (0xFFFFFFF0UL)


#define PFLASH_WORD2_M0EN_MASK                           (0x80000000u)
#define PFLASH_WORD2_M1EN_MASK                           (0x40000000u)

#define PFLASH_PFCRDE_CRD7EN_SHIFT                       (24u)
#define SAF_FLASH_PFCRDE_CRD07_MASK                      (0xFF000000UL)

#define NUM_BLOCK                                        FLS_BLOCK_ALL


#define SAF_FLASH_BLOCK_COUNT                            (NUM_BLOCK)
#define SAF_FLASH_MISR_REGISTER_COUNT                    (10U)

#if defined(CCFC3012PT)
#define SAF_FLASH_BLOCK_TYPE_LIST                        {FLS_BLK_LOW, FLS_BLK_MID, FLS_BLK_HIGH, FLS_BLK_LARGE0_256K, FLS_BLK_LARGE1_256K,FLS_BLK_LARGE2_256K,FLS_BLK_LARGE3_256K,FLS_BLK_LARGE4_256K,FLS_BLK_LARGE5_256K}
#define SAF_FLASH_BLOCK_COUNT_LIST                       {FLS_LOW_BLOCK, FLS_MID_BLOCK, FLS_HIGH_BLOCK, FLS_256K_LARGE0_OFFSET, FLS_256K_LARGE1_OFFSET,FLS_256K_LARGE2_OFFSET,FLS_256K_LARGE3_OFFSET,FLS_256K_LARGE4_OFFSET,FLS_256K_LARGE5_OFFSET}
#else
#define SAF_FLASH_BLOCK_TYPE_LIST                        {FLS_BLK_LOW, FLS_BLK_MID, FLS_BLK_HIGH, FLS_BLK_FIRST_256K, FLS_BLK_SECOND_256K}
#define SAF_FLASH_BLOCK_COUNT_LIST                       {FLS_LOW_BLOCK, FLS_MID_BLOCK, FLS_HIGH_BLOCK, FLS_256K_BLOCK_FIRST, FLS_256K_BLOCK_SECOND}
#endif
#define SAF_FLASH_ECC_TEST_CALC_SIZE_BYTES               (SAF_FLASH_ECC_CALC_SIZE_BYTES << 1)
#define SAF_FLASH_ECC_CALC_SIZE_BYTES                    (32U)

#define SAF_FLASH_CE_LOSSY_MASK                          (0x1U)
#define SAF_FLASH_UCE_LOSSY_MASK                         (0x2U)

#define SAF_FLASH_ECC_ERR_NONE                           0U

/* Cycles counter used in AI/MR test*/
#define FLASH_USER_TEST_WAIT             450U

/* LOCK0 register. */
/* TSLOCK bit fields. */
#define C55FMC_LOCK_TSLOCK_SHIFT                31U
#define C55FMC_LOCK_TSLOCK_WIDTH                1U
#define C55FMC_LOCK_TSLOCK_MASK                 (1U << C55FMC_LOCK_TSLOCK_SHIFT)
#define C55FMC_LOCK_TSLOCK(x)                   (((uint32_t)(((uint32_t)(x)) << C55FMC_LOCK_TSLOCK_SHIFT)) & C55FMC_LOCK_TSLOCK_MASK)

/* C55FMC - Size of Registers Arrays */
#define C55FMC_UM_COUNT                   9U

/* The password in UTest mode which written to the UT0 register */
#define C55_USER_TEST_ENABLE_PASSWORD     0xF9F99999U

#define C55_LOW_BLOCK_TYPE_SELECT         (0U)
#define C55_MID_BLOCK_TYPE_SELECT         (1U)
#define C55_HIGH_BLOCK_TYPE_SELECT        (2U)
#define C55_256_BLOCK_FIRST_TYPE_SELECT   (3U)
#define C55_256_BLOCK_SECOND_TYPE_SELECT  (4U)

/* get the value of bit mask in register */
#define FLASH_C55_GET_REG(reg, mask, shift) ((reg & mask) >> shift)

#define C55FMC_UT0_SBCE(x)     (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000U)
#define C55FMC_UT0_UTE(x)      (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000U)

#define C55_MCR             0x0000U       /*!< Module Configuration Register */
#define C55_MCRE            0x0008U       /*!< Extended Module Configuration Register */
#define C55_LOCK0           0x0010U       /*!< Lock 0 Register */
#define C55_LOCK1           0x0014U       /*!< Lock 1 Register */
#define C55_LOCK2           0x0018U       /*!< Lock 2 Register */
#define C55_LOCK3           0x001CU       /*!< Lock 3 Register */
#define C55_SEL0            0x0038U       /*!< Select 0 Register */
#define C55_SEL1            0x003CU       /*!< Select 1 Register */
#define C55_SEL2            0x0040U       /*!< Select 2 Register */
#define C55_SEL3            0x0044U       /*!< Select 3 Register */
#define C55_ADR             0x0050U       /*!< Address Register */
#define C55_UT0             0x0054U       /*!< User Test 0 register */
#define C55_UM0             0x0058U       /*!< User MISR 0 Register */
#define C55_UM1             0x005CU       /*!< User MISR 1 Register */
#define C55_UM2             0x0060U       /*!< User MISR 2 Register */
#define C55_UM3             0x0064U       /*!< User MISR 3 Register */
#define C55_UM4             0x0068U       /*!< User MISR 4 Register */
#define C55_UM5             0x006CU       /*!< User MISR 5 Register */
#define C55_UM6             0x0070U       /*!< User MISR 6 Register */
#define C55_UM7             0x0074U       /*!< User MISR 7 Register */
#define C55_UM8             0x0078U       /*!< User MISR 8 Register */
#define C55_UM9             0x007CU       /*!< User MISR 9 Register */
#define C55_OPP0            0x0080U       /*!< Over-Program Protection 0 Register */
#define C55_OPP1            0x0084U       /*!< Over-Program Protection 1 Register */
#define C55_OPP2            0x0088U       /*!< Over-Program Protection 2 Register */
#define C55_OPP3            0x008CU       /*!< Over-Program Protection 3 Register */

#define C55_MCR_RVE                       0x80000000U        /*!< Read Voltage Error */
#define C55_MCR_RRE                       0x40000000U        /*!< Read Reference Error */
#define C55_MCR_AEE                       0x20000000U        /*!< Address Encode Error */
#define C55_MCR_EEE                       0x10000000U        /*!< ECC after ECC Error */
#define C55_MCR_EER                       0x8000U            /*!< ECC Event Error */
#define C55_MCR_RWE                       0x4000U            /*!< Read While Write Event Error */
#define C55_MCR_SBC                       0x2000U            /*!< Single Bit Correction Error */
#define C55_MCR_PEAS                      0x800U             /*!< Program/Erase Access Space */
#define C55_MCR_DONE                      0x400U             /*!< State Machine Status */
#define C55_MCR_PEG                       0x200U             /*!< Program/Erase Good */
#define C55_MCR_PECIE                     0x100U             /*!< Program/Erase Complete Interrupt Enable */
#define C55_MCR_PGM                       0x10U              /*!< Program */
#define C55_MCR_PSUS                      0x8U               /*!< Program Suspend */
#define C55_MCR_ERS                       0x4U               /*!< Erase */
#define C55_MCR_ESUS                      0x2U               /*!< Erase Suspend */
#define C55_MCR_EHV                       0x1U               /*!< Enable High Voltage */

#define MEMU_FLS_CE                       (22U)
#define MEMU_FLS_UCE                      (23U)
#define MEMU_FLS_BOV                      (24U)

#define SAF_TIMER_TIMEOUT_DELAY_US                           (200)
#define SAF_TIMER_TIMEOUT_FUNC(cond, ms, timeout)                 {\
        uint32_t counter = ms * 1000 / SAF_TIMER_TIMEOUT_DELAY_US;         \
        timeout = true;                                                   \
        while(counter-- > 0)                                              \
        {                                                                 \
            if (cond)                                                     \
            {                                                             \
                timeout = false;                                          \
                break;                                                    \
            }                                                             \
            SAF_TIMER_DelayUs_FUNC(SAF_TIMER_TIMEOUT_DELAY_US);              \
        }                                                                 \
    }

 /** Number of instances of the C55FMC module. */
#define C55FMC_INSTANCE_COUNT                    (1u)

#define C55FMC_UMx_SEED_VALUE                             0U
#define C55FMC_UM9_OFFEST                                 9U

#define C55FMC_UT0_PASSWORD                               0xF9F99999U

/* TSLOCK. */
#define C55FMC_UTEST_BLOCK_LOCK                           SAF_FLASH_BLOCK_STATE_LOCK
#define C55FMC_UTEST_BLOCK_UNLCOK                         SAF_FLASH_BLOCK_STATE_UNLOCK

/* UTE. */
#define C55FMC_UTEST_ENABLE                               1U
#define C55FMC_UTEST_DISABLE                              0U
/* AIE. */
#define C55FMC_ARRAY_INTEGRITY_CHECK_ENABLE               1U
#define C55FMC_ARRAY_INTEGRITY_CHECK_DISABLE              0U
/* MRE. */
#define C55FMC_MARGIN_READ_CHECK_ENABLE                   1U
#define C55FMC_MARGIN_READ_CHECK_DISABLE                  0U
/* MRV. */
#define C55FMC_MARGIN_READ_VALUE_ONE                      1U
#define C55FMC_MARGIN_READ_VALUE_ZERO                     0U
/* AID. */
#define C55FMC_ARRAY_INTEGRITY_CHECK_DONE                 1U
#define C55FMC_ARRAY_INTEGRITY_CHECK_ONGOING              0U
/* AISUS. */
#define C55FMC_ARRAY_INTEGRITY_SEQUENCE_SUSPENDED         1U
#define C55FMC_ARRAY_INTEGRITY_SEQUENCE_NOT_SUSPENDED     0U
/* AIS. */
#define C55FMC_ARRAY_INTEGRITY_SEQUENCE_SEQUENTIAL        1U
#define C55FMC_ARRAY_INTEGRITY_SEQUENCE_PROPRIETARY       0U
/* AIBPE. */
#define C55FMC_ARRAY_INTEGRITY_BREAK_POINT_ENABLE         1U
#define C55FMC_ARRAY_INTEGRITY_BREAK_POINT_DISABLE        0U
/* NAIBP. */
#define C55FMC_ARRAY_INTEGRITY_AT_A_BREAK_POINT           1U
#define C55FMC_ARRAY_INTEGRITY_NOT_AT_A_BREAK_POINT       0U
/* SBCE. */
#define C55FMC_SINGLE_BIT_CORRECTION_ENABLE               1U
#define C55FMC_SINGLE_BIT_CORRECTION_DISABLE              0U
/* SBC. */
#define C55FMC_SINGLE_BIT_CORRECTION_EVENT_OCCURRED       1U
#define C55FMC_SINGLE_BIT_CORRECTION_EVENT_NOT_OCCURRED   0U

#define C55FMC_ECC_EVENT_ERROR_CLEAR                      1U
#define C55FMC_SINGLE_BIT_CORRECTION_EVENT_CLEAR          1U

/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/

/**
* @brief  Flash UTEST information structure.
*/
typedef struct
{
    uint32_t startAddr;
    uint32_t HsmtartAddr;
    uint32_t size;
    uint32_t HsmSize;
    uint32_t curPos;
    bool initialized;
} saf_flash_utest_opr_t;

/**
* @brief  Flash block type.
*/
#if defined(CCFC3012PT)
typedef enum
{
    SAF_FLASH_LOW_BLOCK            = 0,
    SAF_FLASH_MID_BLOCK            = 1,
    SAF_FLASH_HIGH_BLOCK           = 2,
    SAF_FLASH_LARGE0_BLOCK         = 3,
	SAF_FLASH_LARGE1_BLOCK         = 4,
	SAF_FLASH_LARGE2_BLOCK         = 5,
	SAF_FLASH_LARGE3_BLOCK         = 6,
	SAF_FLASH_LARGE4_BLOCK         = 7,
	SAF_FLASH_LARGE5_BLOCK         = 8,
	SAF_FLASH_BLOCK_TYPE_COUNT     = 9,
} SAF_FLASH_BLOCK_TYPE;
#else
typedef enum
{
    SAF_FLASH_LOW_BLOCK = 0,
    SAF_FLASH_MID_BLOCK,
    SAF_FLASH_HIGH_BLOCK,
    SAF_FLASH_FIRST_LARGE_BLOCK,
    SAF_FLASH_SECOND_LARGE_BLOCK,
#ifdef SAF_FLASH_SUPPORT_SECOND_LARGE_BLOCK
    SAF_FLASH_BLOCK_TYPE_COUNT,
#else
    SAF_FLASH_BLOCK_TYPE_COUNT = SAF_FLASH_SECOND_LARGE_BLOCK,
#endif
} SAF_FLASH_BLOCK_TYPE;
#endif
/**
* @brief  Flash LossyTest type.
*/
typedef enum
{
	SAF_FLASH_CE_LOSSY = 1,
	SAF_FLASH_UCE_LOSSY,
	SAF_FLASH_ALL_LOSSY,
} SAF_FLASH_LOSSY_TYPE;

/**
* @brief  Declarations for flash suspend operation and resume operation and user test check state.
*/
typedef enum
{
    /*!< Successful operation */
    C55_OK                           = 0x00U,
    /*!< No program/erase operation */
    C55_SUS_NOTHING                  = 0x10U,
    /*!< The UTest check operation is in suspend state */
    C55_USER_TEST_SUS                = 0x11U,
    /*!< The UTest check operation is broken by Single bit correction */
    C55_USER_TEST_BREAK_SBC          = 0x30U,
    /*!< The UTest check operation is broken by Double bit detection */
    C55_USER_TEST_BREAK_DBD          = 0x31U
} flash_state_t;

/**
* @brief  MISR structure.
*/
typedef struct
{
    uint32_t arrMISRValue[C55FMC_UM_COUNT + 1U];    /*!< The value of MISR */
} flash_misr_t;

/**
* @brief  The structure store the context of data. This consists of parameters input are necessary for the APIs.
*/
typedef struct
{
    /*!< The context destination address of the program operation */
    uint32_t dest;
    /*!< The context size of the program operation */
    uint32_t size;
    /*!< The context source of the program operation */
    uint32_t source;
    /*!< The context MISR values of the operation in user test mode */
    flash_misr_t * pMisr;
} flash_context_data_t;

/**
* @brief  Next Array Integrity Break Point options.
*/
typedef enum
{
    /*!< No break at all */
    C55_AI_BREAK_NONE              = 0x00U,
    /*!< Break on Double bit detection */
    C55_AI_BREAK_ON_DBD            = 0x01U,
    /*!< Break on both Double bit detection and Single bit correction */
    C55_AI_BREAK_ON_DBD_SBC        = 0x02U
} flash_ai_break_option_t;

/**
* @brief  Next Margin read Break Point options.
*/
typedef enum
{
    /*!< No break at all */
    C55_MR_BREAK_NONE              = 0x00U,
    /*!< Break on Double bit detection */
    C55_MR_BREAK_ON_DBD            = 0x01U,
    /*!< Break on both Double bit detection and Single bit correction */
    C55_MR_BREAK_ON_DBD_SBC        = 0x02U
} flash_mr_break_option_t;

/**
* @brief  Array Integrity Sequence.
*/
typedef enum
{
    /*!< Array integrity sequence is proprietary sequence */
    C55_AI_ADDR_SEQ_PROPRIETARY    = 0x00U,
    /*!< Array integrity sequence is sequential */
    C55_AI_ADDR_SEQ_LINEAR         = 0x01U
} flash_ai_sequence_option_t;

/**
* @brief  Flash block information structure.
*/
typedef struct
{
    SAF_FLASH_BLOCK_TYPE blockType;
    uint8_t blockID;
    bool isUtestBlock;
} saf_flash_info_t;

/**
* @brief  Flash memory array integrity test parameter structure.
*/
typedef struct 
{
    fls_blk_sel_t blockSelect;    /* input */
} saf_flash_ai_test_param_t;

/**
* @brief  Flash memory array integrity test result structure.
*/
typedef struct 
{
    fls_blk_sel_t blockPassed;
} saf_flash_ai_test_result_t;

/**
* @brief  Flash memory array integrity test structure.
*/
typedef struct 
{
    saf_flash_ai_test_param_t    input;
    saf_flash_ai_test_result_t   output;
} saf_flash_ai_test_t;

/**
* @brief  Flash memory margin read check parameter structure.
*/
typedef struct
{
    fls_blk_sel_t blockSelect;    /* input */
} saf_flash_mr_test_param_t;

/**
* @brief  Flash memory margin read check result structure.
*/
typedef struct
{
    fls_blk_sel_t blockPassed;
} saf_flash_mr_test_result_t;

/**
* @brief  Flash memory margin read check structure.
*/
typedef struct
{
    saf_flash_mr_test_param_t    input;
    saf_flash_mr_test_result_t   output;
} saf_flash_mr_test_t;

/**
* @brief  Flash ECC error inject test parameter structure.
*/
typedef struct
{
    uint8_t singleBitSelect:1;
    uint8_t multiBitSelect:1;
} saf_flash_ecc_report_path_test_param_t;

/**
* @brief  Flash ECC error inject test result structure.
*/
typedef struct
{
    uint8_t singleBitPassed:1;
    uint8_t multiBitPassed:1;
} saf_flash_ecc_report_path_test_result_t;

/**
* @brief  Flash ECC error inject test structure.
*/
typedef struct
{
    saf_flash_ecc_report_path_test_param_t input;
    saf_flash_ecc_report_path_test_result_t output;
} saf_flash_ecc_report_path_test_t;

/**
* @brief  Declarations of margin levels.
*/
typedef enum
{
    /*!< a programmed level */
    C55_MARGIN_LEVEL_PROGRAM    = 0x00U,
    /*!< a erased level */
    C55_MARGIN_LEVEL_ERASE      = 0x01U
} flash_margin_option_t;

typedef FS_STATUS (* fs_safety_test_func)(void *);

/**
* @brief  PFLASH PFCRD structure.
*/
typedef struct
{
    uint32_t word0;
    uint32_t word1;
    uint32_t word2;
} saf_pfcrd_t;

/**
* @brief  PFLASH controller read structure.
*/
typedef struct
{
    uint32_t pfcr1;
    uint32_t pfcr2;
    uint32_t pfcr3;
    uint32_t pfapr;
    uint32_t pfcrcr;
    uint32_t pfcrde;
    saf_pfcrd_t pfcdr[32];
} saf_pflash_store_t;

/**
* @brief  The flash test information type.
*/
typedef enum
{
    SAF_FLASH_AI = 0,
    SAF_FLASH_MR,
    SAF_FLASH_ECC,
    SAF_FLASH_COUNT,
} SAF_FLASH_SAFETY_INFO_TYPE;

/**
* @brief  The flash test information header.
*/
typedef struct
{
    uint32_t len;
    SAF_FLASH_SAFETY_INFO_TYPE type;
} saf_flash_safety_info_header_t;

/**
* @brief  The flash array integrity data structure.
*/
typedef struct
{
    saf_flash_safety_info_header_t header;
    uint32_t updated;   /* 0 for no calc */
    flash_misr_t flashBlockMisr[SAF_FLASH_BLOCK_COUNT];
} saf_flash_ai_safety_info_t;

/**
* @brief  The flash margin read structure.
*/
typedef struct
{
    saf_flash_safety_info_header_t header;
    uint32_t updated;   /* 0 for no calc */
    flash_misr_t flashBlockMisr[SAF_FLASH_BLOCK_COUNT];
} saf_flash_mr_safety_info_t;

/**
* @brief  The flash ecc test data information.
*/
typedef struct
{
    saf_flash_safety_info_header_t header;
    uint32_t testStartAddr;
} saf_flash_ecc_safety_info_t;

/**
* @brief  Flash safety test information top structure .
*/
typedef struct
{
    uint32_t totalLen;
    /* use to save flash array integrate test */
    saf_flash_ai_safety_info_t flashAiMisr;
    /* use to save flash margin read test */
    saf_flash_mr_safety_info_t flashMrMisr;
    /* use to save flash ECC report path test */
    saf_flash_ecc_safety_info_t flashEccPathTest;
} saf_flash_saved_test_data_t;

/**
****************************************************************************************
 * @brief: Function Prototypes
****************************************************************************************
*/
#if defined(CCFC3008PT) | defined(CCFC3008PC) | defined(CCFC3008PCSN)
FS_STATUS SAF_FLASH_ACLoadInit(uint8_t CalcKind);
#endif

status_t SAF_FLASH_CheckUserTestStatus(const flash_context_data_t * pCtxData, flash_state_t * opResult);

FS_STATUS SAF_FLASH_ArrayIntegrityTest(void);

FS_STATUS SAF_FLASH_ArrayIntegrityTestResult(saf_flash_ai_test_result_t *pTestResult);

FS_STATUS SAF_FLASH_MarginReadTest(void);

#if !(defined(CCFC3008PT) | defined(CCFC3008PC) | defined(CCFC3008PCSN))
FS_STATUS SAF_FLASH_MarginReadLevelTest(flash_margin_option_t level);
#else
FS_STATUS SAF_FLASH_MarginReadLevelTest(void);
#endif

FS_STATUS SAF_FLASH_MarginReadTestResult(saf_flash_mr_test_result_t *pTestResult);

FS_STATUS SAF_FLASH_EccReportPathTest(void);

FS_STATUS SAF_FLASH_EccReportPathTestResult(saf_flash_ecc_report_path_test_result_t *pTestResult);

FS_STATUS SAF_FLASH_LockBlockByAddr(const uint32_t addr, const bool lock);

FS_STATUS SAF_FLASH_TriggerBitError(const SAF_MEM_ERR_TYPE type);

void SAF_TIMER_DelayUs_FUNC(uint32_t periodUs);

void SAF_FLASH_RemapDescriptorUnusedInit(uint32_t unusedLogicAddress);

FS_STATUS SAF_FLASH_SBCReadCheck(uint32_t* addrBuff);

FS_STATUS SAF_FLASH_OverlayTest(void);

FS_STATUS SAF_FLASH_GetLock(uint8_t lockedBlkSel, uint32_t * lockedBlkStatus);

FS_STATUS SAF_FLASH_SetLock(uint8_t lockedBlkSel, uint32_t lockedBlkStatus);

void SAF_FLASH_CopyCodeRam(void);

void SAF_FLASH_ClearCodeRam(void);

/**
****************************************************************************************
 * @brief: Inline Function
****************************************************************************************
*/
///**
// * @brief Get the number of low blocks in flash memory.
// */
//SAF_FLASH_SEC_CODE
//static inline uint32_t FLASH_GetNumOfLowBlock(void)
//{
//    uint32_t retValue;
//
//    retValue = FLS_FMC.MCRE.B.n16Kl + FLS_FMC.MCRE.B.n32Kl + FLS_FMC.MCRE.B.n64Kl;
//    retValue = retValue << 1U;
//
//    return retValue;
//}
//
///**
// * @brief Get the number of mid blocks in flash memory.
// */
//SAF_FLASH_SEC_CODE
//static inline uint32_t FLASH_GetNumOfMidBlock(void)
//{
//    uint32_t retValue;
//
//    retValue = FLS_FMC.MCRE.B.n16Km + FLS_FMC.MCRE.B.n32Km + FLS_FMC.MCRE.B.n64Km;
//    retValue = retValue << 1U;
//
//    return retValue;
//}
//
///**
// * @brief Get the number of high blocks in flash memory.
// */
//SAF_FLASH_SEC_CODE
//static inline uint32_t FLASH_GetNumOfHighBlock(void)
//{
//    uint32_t retValue;
//
//    retValue = FLS_FMC.MCRE.B.n16Kh + FLS_FMC.MCRE.B.n32Kh + FLS_FMC.MCRE.B.n64Kh;
//    retValue = retValue << 1U;
//
//    return retValue;
//}

/**
 * @brief Get the number of 256K blocks in flash memory.
 */
SAF_FLASH_SEC_CODE
static inline uint32_t FLASH_GetNumOf256KBlock(void)
{
    return ((FLS_FMC.MCRE.B.n256K) << 1U);
}

#if defined (__cplusplus)
}
#endif

#endif

