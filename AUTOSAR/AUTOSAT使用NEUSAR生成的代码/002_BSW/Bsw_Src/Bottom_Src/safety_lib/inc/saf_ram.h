/**
****************************************************************************************
 * @FilePath: saf_ram.h
 * @Author: CCORE
 * @Date: 2024-02-12
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety Ram head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_RAM_H
#define SAF_RAM_H

#ifdef __cplusplus
extern "C"{
#endif


/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/

#include "saf_common.h"
#include "saf_mem.h"
#include "saf_cpu.h"


/**
****************************************************************************************
 * @brief: Macro
****************************************************************************************
*/
#define IMA_SAF             (*(volatile struct IMA_Saf_tag *)      0xFFF54000UL)

#define SAF_SYSRAM_INJECT_CE_ERROR_DEMO_NUM                         (10U)
#define SAF_SYSRAM_INJECT_UCE_ERROR_DEMO_NUM                        (11U)
#define SAF_SYSRAM_ITCM_WAIT_WHILE_OPERATION_TIMEOUT_CNT            (40000U)

#define MEMU_RAM_CE                       (16U)
#define MEMU_RAM_UCE                      (17U)
#define MEMU_RAM_BOV                      (18U)
#define MEMU_PER_CE                       (19U)
#define MEMU_PER_UCE                      (20U)
#define MEMU_PER_BOV                      (21U)

#define SAF_RAM_FTTI_CHECK_WRITE_DATA                               0x55AA55AAU

#define SAF_RAM_SBC_READ_CHECK_FIRST_WRITE_DATA                     0x55555555U
#define SAF_RAM_SBC_READ_CHECK_SECOND_WRITE_DATA                    0xAAAAAAAAU
/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/

typedef union IMA_ENABLE_union_saf_tag {   /*PRQA S 1536*//* Enable Access Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t EN:1;
  } B;
} IMA_ENABLE_Saf_tag;

struct IMA_Saf_tag {
  IMA_CTRL_tag CTRL;                   /* Control Register */
  IMA_ENABLE_Saf_tag ENABLE_R;               /* Enable Access Register */
  IMA_STATUS_tag STATUS;               /* Status Register */
  IMA_SLCT_tag SLCT;                   /* RAM Select Register */
  IMA_WRITE_UNLOCK_tag WRITE_UNLOCK;   /* Write Unlock Register */
  IMA_READ_UNLOCK_tag READ_UNLOCK;     /* Read Unlock Register */
  uint8_t IMA_reserved0[20];
  IMA_WRITE_DATA_4_tag WRITE_DATA_4;   /* RAM Write Data Register 4 */
  IMA_WRITE_DATA_3_tag WRITE_DATA_3;   /* RAM Write Data Register 3 */
  IMA_WRITE_DATA_2_tag WRITE_DATA_2;   /* RAM Write Data Register 2 */
  IMA_WRITE_DATA_1_tag WRITE_DATA_1;   /* RAM Write Data Register 1 */
  IMA_WRITE_DATA_0_tag WRITE_DATA_0;   /* RAM Write Data Register 0 */
  uint8_t IMA_reserved1[12];
  IMA_READ_DATA_4_tag READ_DATA_4;     /* RAM Read Data Register 4 */
  IMA_READ_DATA_3_tag READ_DATA_3;     /* RAM Read Data Register 3 */
  IMA_READ_DATA_2_tag READ_DATA_2;     /* RAM Read Data Register 2 */
  IMA_READ_DATA_1_tag READ_DATA_1;     /* RAM Read Data Register 1 */
  IMA_READ_DATA_0_tag READ_DATA_0;     /* RAM Read Data Register 0 */
};

/**
* @brief  This is the RAM test select bitmap. It consists of test objects.
*/
typedef struct
{
    /* SRAM single bitmap value */
    uint32_t sramSingleBit:1;
    /* SRAM multi bitmap value */
    uint32_t sramMultiBit:1;
    /* PRAM single bitmap value */
    uint32_t pramSingleBit:1;
    /* PRAM multi bitmap value */
    uint32_t pramMultiBit:1;
#if SAF_ITCM_SUPPORTED
    /* itcm multi-bit error test  */
    uint32_t itcmSingleBit:1;
    /* itcm multi-bit error test  */
    uint32_t itcmMultiBit:1;
#endif
} saf_ram_test_object_t;

/**
* @brief  The RAM error inject information.
*/
typedef struct
{
    /* The memory error type */
    SAF_MEM_ERR_TYPE  injectBitType;
    /* The memory type */
    SAF_MEM_TYPE ramType;
} saf_ram_inject_bit_type_t;

/**
* @brief  The RAM ECC report path test parameter structure.
*/
typedef struct
{
    /* The RAM test select bitmap */
    saf_ram_test_object_t testSelect;
} saf_ram_ecc_report_path_test_param_t;

/**
* @brief  The RAM ECC report path test result structure.
*/
typedef struct
{
    /* The RAM test select bitmap, 1 for passed, 0 for not passed */
    saf_ram_test_object_t testPassed;
} saf_ram_ecc_report_path_test_result_t;

/**
* @brief  The RAM ECC report path test structure.
*/
typedef struct
{
    /* The RAM ECC report path test parameter structure */
    saf_ram_ecc_report_path_test_param_t input;
    /* The RAM ECC report path test result structure */
    saf_ram_ecc_report_path_test_result_t output;
} saf_ram_ecc_report_path_test_t;

/**
****************************************************************************************
 * @brief: Function Prototypes
****************************************************************************************
*/
extern void SetupE2EECSR0_for_1b_ECC_fault(void);/* parasoft-suppress MISRAC2012-RULE_8_6-a "function requirement" */

extern void SetupE2EECSR0_for_2b_ECC_fault(void);/* parasoft-suppress MISRAC2012-RULE_8_6-a "function requirement" */

extern void SetupE2EECSR0_for_ClearECC(uint32_t addr, uint32_t size);/* parasoft-suppress MISRAC2012-RULE_8_6-a "function requirement" */

extern void SetupE2EECSR0_for_ClearWRC(void);/* parasoft-suppress MISRAC2012-RULE_8_6-a "function requirement" */

/**
****************************************************************************************
 * @brief: Function Prototypes
****************************************************************************************
*/

FS_STATUS SAF_RAM_InjectBitError(const saf_ram_inject_bit_type_t injectType);

FS_STATUS SAF_RAM_EccReportPathTest(void);

FS_STATUS SAF_RAM_PramEccReportPathTest(const saf_ram_test_object_t *pParam, saf_ram_ecc_report_path_test_result_t *pResult);

FS_STATUS SAF_RAM_SramEccReportPathTest(const saf_ram_test_object_t *pParam, saf_ram_ecc_report_path_test_result_t *pResult);

FS_STATUS SAF_RAM_EccReportPathTestResult(saf_ram_ecc_report_path_test_result_t *pTestResult);

FS_STATUS SAF_RAM_SBCReadCheck(uint32_t* addr);

FS_STATUS SAF_RAM_ItcmEccReportPathTest(const saf_ram_test_object_t *pParam, saf_ram_ecc_report_path_test_result_t *pResult);

FS_STATUS SAF_RAM_FTTICheck(uint32_t unusedAddr);

FS_STATUS SAF_RAM_ITCMEccReportPathTest(void);

uint32_t SAF_RAM_PRAMCReadBack(void);

#if defined (__cplusplus)
}
#endif

#endif

