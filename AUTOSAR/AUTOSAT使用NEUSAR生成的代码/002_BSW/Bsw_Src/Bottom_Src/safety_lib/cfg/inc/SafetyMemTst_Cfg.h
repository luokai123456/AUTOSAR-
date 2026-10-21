/**
****************************************************************************************
 * @FilePath: SafetyMemTst_Cfg.h
 * @Author: CCORE
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety memory test configuration head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/

#ifndef SAFETYMEMTST_CFG_H
#define SAFETYMEMTST_CFG_H

#ifdef __cplusplus
extern "C"{
#endif
/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/ 
#include "saf_userservice_callback.h"

/**
****************************************************************************************
* @brief: Macros
****************************************************************************************
*/
/* FLASH ECC error report path test define */

#define SAFETYMEMTEST_FLASH_ECC_REPORT_PATH_TEST        (STD_ON)

/* PRAM ECC error report path test define */
#define SAFETYMEMTEST_PRAM_ECC_REPORT_PATH_TEST         (STD_ON)

/* SRAM ECC error report path test define */
#define SAFETYMEMTEST_SRAM_ECC_REPORT_PATH_TEST         (STD_ON)

/* MPU access right test define */
#define SAFETYMEMTEST_CMPU_ACCESS_RIGHT_TEST            (STD_ON)

/* MPU access right test define */
#define SAFETYMEMTEST_SMPU_ACCESS_RIGHT_TEST            (STD_ON)

/* ICACHE ECC/EDC report test address define */
#define SAFETYMEMTEST_EDC_I_CACHE_TEST_ADDR             (0x40031000U)

/* DCACHE ECC/EDC report test address define */
#define SAFETYMEMTEST_EDC_D_CACHE_TEST_ADDR             (0x40030000U)

/* SMPU access right test address define */
#define SAFETYMEMTEST_SMPU_ACCESS_RIGHT_TEST_ADDR       (0x400e0020U)

                                                                                                                                                                                                        
/* CMPU0 is defined in the configuration */
#define SAFETY_RESOURCE_DEF_CMPU_CORE0

/* Number of entries in the configuration array for CMPU */
#define SAFETYMEMTEST_CMPU_Z42_ENTRY_COUNT_BY_SELF          (0U)
#define SAFETYMEMTEST_CMPU_Z70_ENTRY_COUNT_BY_SELF          (4U)
#define SAFETYMEMTEST_CMPU_Z71_ENTRY_COUNT_BY_SELF          (0U)
#define SAFETYMEMTEST_CMPU_CORE3_ENTRY_COUNT_BY_SELF        (0U)
#define SAFETYMEMTEST_CMPU_CORE4_ENTRY_COUNT_BY_SELF        (0U)
#define SAFETYMEMTEST_CMPU_CORE5_ENTRY_COUNT_BY_SELF        (0U)

/* Number of entries in the configuration array for CACHE */
#define SAFETYMEMTEST_CMPU_ENTRY_COUNT_BY_CACHE         (12U)

                                                                                                        
/* Number of entries in the configuration array for SMPU0 */
#define SAFETYMEMTEST_SMPU_0_ENTRY_COUNT                (4U)

/* Number of entries in the configuration array for SMPU1 */
#define SAFETYMEMTEST_SMPU_1_ENTRY_COUNT                (4U)


#ifdef __cplusplus
}
#endif

#endif  /* SAFETYMEMTST_CFG_H */
