/**
****************************************************************************************
 * @FilePath: saf_mpu.h
 * @Author: CCORE
 * @Date: 2024-01-22
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety MPU head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_MPU_H
#define SAF_MPU_H

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
#include "SafetyMemTst_Cfg.h"
#include "cmpu_lld.h"

#if SAF_MPU_SUPPORTED

/**
****************************************************************************************
* @brief: Macros
****************************************************************************************
*/

/* Number of entry select for the CMPU module. */
#define CMPU_ENTRY_MAX_COUNT                     (24u)

/* Number of instances of the SMPU module. */
#define CMPU_INSTANCE_COUNT                      (1u)

/* Define mpu test flag */
#define CMPU_OP_SUCC                (0U)
#define CMPU_OP_FAIL                (1U)

/* Protected address for test */
#define CMPU_DEMO_PROTECT_SRAM      (0x40061020U)


/* Number of entries in the configuration array */
#define CMPU_DEMO_ENTRY_COUNT       (4U)

/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/
/**
* @brief  The CMPU access right test parameter structure.
*/
typedef struct
{
    /* CMPU read limit select bitmap value */
    uint8_t readLimitSelect:1;
    /* CMPU write limit select bitmap value */
    uint8_t writeLimitSelect:1;
} saf_mpu_access_right_test_param_t;

/**
* @brief  The CMPU access right test result structure.
*/
typedef struct
{
    /* CMPU read limit test result */
    uint8_t readLimitPassed:1;
    /* CMPU write limit test result */
    uint8_t writeLimitPassed:1;
} saf_mpu_access_right_test_result_t;

/**
* @brief  The CMPU access right test structure.
*/
typedef struct
{
    /* The CMPU access right test parameter structure */
    saf_mpu_access_right_test_param_t input;
    /* The CMPU access right test result structure */
    saf_mpu_access_right_test_result_t output;
} saf_mpu_access_right_test_t;

/**
****************************************************************************************
 * @brief: Global Variable
****************************************************************************************
*/
#ifdef SAFETY_RESOURCE_DEF_CMPU_CORE0
extern cmpu_module_cfg_t mpu_CfgZ70;
extern cmpu_entry_cfg_t mpuEntryArrayZ70[SAFETYMEMTEST_CMPU_Z70_ENTRY_COUNT_BY_SELF];
#endif
#ifdef SAFETY_RESOURCE_DEF_CMPU_CORE1
extern cmpu_module_cfg_t mpu_CfgZ71;
extern cmpu_entry_cfg_t mpuEntryArrayZ71[SAFETYMEMTEST_CMPU_Z71_ENTRY_COUNT_BY_SELF];
#endif
#ifdef SAFETY_RESOURCE_DEF_CMPU_CORE2
extern cmpu_module_cfg_t mpu_CfgZ42;
extern cmpu_entry_cfg_t mpuEntryArrayZ42[SAFETYMEMTEST_CMPU_Z42_ENTRY_COUNT_BY_SELF];
#endif

extern const saf_mpu_access_right_test_param_t s_mpuAcRightTestCfg;

/**
****************************************************************************************
 * @brief: Function Prototypes
****************************************************************************************
*/

FS_STATUS SAF_MPU_SafetyInit(const uint32_t mpuInst, const cmpu_module_cfg_t *mpuConfig, const cmpu_entry_cfg_t *entryConfig, const uint8_t entryCnt);

FS_STATUS SAF_MPU_SafetyDeinit(const uint8_t mpuInst);

FS_STATUS SAF_MPU_SafetyGetEntryConfig(uint32_t mpuInst, uint8_t regionId, const uint8_t regType, cmpu_entry_cfg_t *entryConfig);

FS_STATUS SAF_MPU_SafetyGetModuleConfig(uint32_t mpuInst, cmpu_module_cfg_t *mpuConfig);

FS_STATUS SAF_MPU_SafetySetEntryConfig(const uint32_t mpuInst, const cmpu_entry_cfg_t *entryConfig);

FS_STATUS SAF_MPU_AccessRightTest(void);

FS_STATUS SAF_MPU_AccessRightTestResult(saf_mpu_access_right_test_result_t *pTestResult);

void SAF_MPU_IvorHandler(void);
#endif

#if defined (__cplusplus)
}
#endif

#endif
