/**
****************************************************************************************
 * @FilePath: saf_smpu.h
 * @Author: CCORE
 * @Date: 2024-03-05
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety SMPU head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_SMPU_H
#define SAF_SMPU_H

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/

#include "saf_cpu.h"
#include "saf_common.h"
#include "smpu_lldriver.h"
#include "SafetyMemTst_Cfg.h"

#if SAF_SMPU_SUPPORTED
/**
****************************************************************************************
* @brief: Macros
****************************************************************************************
*/
#ifdef CCFC3012PT
#define SMPU_INSTANCE_COUNT             (4U)
#define SAF_SMPU0                        0
#define SAF_SMPU1                        1
#define SAF_SMPU2                        2
#define SAF_SMPU3                        3
#else
#define SMPU_INSTANCE_COUNT             (2U)
#define SAF_SMPU0                        0
#define SAF_SMPU1                        1
#endif

#define CUR_DEMO_MASTER_CORE (SAF_SMPU_MASTER_CORE0)

/* Protected address for test */
#define SMPU0_DEMO_TEST_PROTECT_ADDR    SAFETYMEMTEST_SMPU_ACCESS_RIGHT_TEST_ADDR
#define SMPU0_DEMO_TEST_DATA            (0x01U)


/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/
/**
* @brief  The master access rights structure.
*/
typedef struct
{
    /* Master number */
    uint8_t masterNum;
    /* Access right */
    uint8_t accessRight;
} smpu_master_access_right_t;

/**
* @brief  The SMPU access right test parameter structure.
*/
typedef struct
{
    /* SMPU read limit select bitmap value */
    uint8_t readLimitSelect:1;
    /* SMPU write limit select bitmap value */
    uint8_t writeLimitSelect:1;
} saf_smpu_access_right_test_param_t;

/**
* @brief  The SMPU access right test result structure.
*/
typedef struct
{
    /* SMPU read limit test result */
    uint8_t readLimitPassed:1;
    /* SMPU write limit test result */
    uint8_t writeLimitPassed:1;
} saf_smpu_access_right_test_result_t;

/**
* @brief  The SMPU access right test structure.
*/
typedef struct
{
    /* The SMPU access right test parameter structure */
    saf_smpu_access_right_test_param_t input;
    /* The SMPU access right test result structure */
    saf_smpu_access_right_test_result_t output;
} saf_smpu_access_right_test_t;

/**
****************************************************************************************
 * @brief: Global Variable
****************************************************************************************
*/
extern smpu_master_acc_right_t s_smpu0MasterAccConfig[SAFETYMEMTEST_SMPU_0_ENTRY_COUNT][6];
extern smpu_config_t smpu0EntryArray[SAFETYMEMTEST_SMPU_0_ENTRY_COUNT];
extern smpu_master_acc_right_t s_smpu1MasterAccConfig[SAFETYMEMTEST_SMPU_1_ENTRY_COUNT][6];
extern smpu_config_t smpu1EntryArray[SAFETYMEMTEST_SMPU_1_ENTRY_COUNT];
extern const saf_smpu_access_right_test_param_t s_smpuAcRightTestCfg;

/**
****************************************************************************************
 * @brief: Function Prototypes
****************************************************************************************
*/

FS_STATUS SAF_SMPU_SafetyInit(const uint32_t smpuInst,
                             const uint8_t regionCnt,
                             const smpu_config_t * userConfigPtr);

FS_STATUS SAF_SMPU_SafetyDeinit(const uint32_t smpuInst);

FS_STATUS SAF_SMPU_SafetySetRegionConfig(uint32_t smpuInst, uint8_t regionNum, const smpu_config_t *regionConfigPtr);

FS_STATUS SAF_SMPU_SafetySetRegionAddr(const uint32_t smpuInst,
                                      const uint8_t regionNum,
                                      const uint32_t startAddr,
                                      const uint32_t endAddr);

FS_STATUS SAF_SMPU_SafetyEnableRegion(const uint32_t smpuInst,
                                     const uint8_t regionNum,
                                     const bool enable);  

FS_STATUS SAF_SMPU_SafetySetMasterAccessRights(const uint32_t smpuInst,
                                              const uint8_t regionNum,
                                              const smpu_master_access_right_t *pMasterAccRight);

FS_STATUS SAF_SMPU_SafetySetRegionLockConfig(const uint32_t smpuInst,
                                            const uint8_t regionNum,
                                            const uint8_t lockConfig);

FS_STATUS SAF_SMPU_SafetyGetRegionLockInfo(const uint32_t smpuInst,
                                          const uint8_t regionNum,
                                          uint8_t *pRegionLock);

FS_STATUS SAF_SMPU_SafetyGetDetailErrorInfo(const uint32_t smpuInst, const uint8_t errorNum, smpu_acc_err_t *errInfoPtr);

FS_STATUS SAF_SMPU_GetSMPURegionConfig(smpu_config_t *pConfig);

FS_STATUS SAF_SMPU_AccessRightTest(void);

FS_STATUS SAF_SMPU_AccessRightTestResult(saf_smpu_access_right_test_result_t *pTestResult);

void SAF_SMPU_IvorHandler(void);

#endif

#if defined (__cplusplus)
}
#endif

#endif
