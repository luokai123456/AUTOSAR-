/**
****************************************************************************************
 * @FilePath: SafetyMemTst_Cfg.c
 * @Author: CCORE
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety memory test configuration C File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifdef __cplusplus
extern "C"{
#endif
/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_flash.h"/*PRQA S 0380*/
#include "saf_ram.h"
#include "saf_mpu.h"
#include "saf_smpu.h"
#include "saf_cache.h"
#include "saf_userservice_callback.h"
#include "Saf_MemMap.h"
/*PRQA S 1533,3408 EOF*/
/**
****************************************************************************************
 * @brief: Structs
****************************************************************************************
*/
/* Flash ECC error inject test parameter. */
SAF_FLASH_SEC_CONFIG_DATA
const saf_flash_ecc_report_path_test_param_t s_flashEccConfigSet =
{
  /* FLASH single-bit error test */
  .singleBitSelect = 1U,
  /* FLASH multi-bit error test  */
  .multiBitSelect = 1U,
};

/* Flash ECC report path test call back */
SAF_FLASH_SEC_CONFIG_DATA
const call_config_t s_flashEccCallSet =
{
    /* Flash notification function */
    .callback       = NULL,
    /* Flash notification function parameter */
    .callbackParam  = NULL
};

/* Flash array integrity test parameter. */
SAF_FLASH_SEC_CONFIG_DATA
const fls_blk_sel_t s_flashAIConfigSet =
{
  /* Low block selected of array integrity test */
  0x0000000fU,
  /* Mid block selected of array integrity test  */
  0x00000000U,
  /* High block selected of array integrity test */
  0x00000000U,
  /* First large block selected of array integrity test  */
  0x0000000fU,
  /* Second large block selected of array integrity test */
  0x00000000U,
  #ifdef RESOURCE_SUPPORT_PFI
  /* Large2 block selected of array integrity test  */
  0x00000000U,
  /* Large3 block selected of array integrity test  */
  0x00000000U,
  /* Large4 block selected of array integrity test  */
  0x00000000U,
  /* Large5 block selected of array integrity test  */
  0x00000000U,
  #endif
};

/* Flash array integrity test call back */
SAF_FLASH_SEC_CONFIG_DATA
const call_config_t s_flashAICallSet =
{
    /* Flash notification function */
    .callback       = NULL,
    /* Flash notification function parameter */
    .callbackParam  = NULL
};

/* Flash margin read test parameter. */
SAF_FLASH_SEC_CONFIG_DATA
const fls_blk_sel_t s_flashMRConfigSet =
{
  /* Low block selected of margin read test */
  0x0000000fU,
  /* Mid block selected of margin read test  */
  0x00000000U,
  /* High block selected of margin read test */
  0x00000000U,
  /* First large block selected of margin read test  */
  0x000000ffU,
  /* Second large block selected of margin read test */
  0x00000000U,
  #ifdef RESOURCE_SUPPORT_PFI
  /* Large2 block selected of margin read test  */
  0x00000000U,
  /* Large3 block selected of margin read test  */
  0x00000000U,
  /* Large4 block selected of margin read test  */
  0x00000000U,
  /* Large5 block selected of margin read test  */
  0x00000000U,
  #endif
};

/* Flash margin read test call back */
SAF_FLASH_SEC_CONFIG_DATA
const call_config_t s_flashMRCallSet =
{
    /* Flash notification function */
    .callback       = NULL,
    /* Flash notification function parameter */
    .callbackParam  = NULL
};

/* Ram ECC error inject test parameter. */
SAF_RAM_SEC_CONFIG_DATA
const saf_ram_test_object_t s_ramEccConfigSet =
{
  /* PRAM single-bit error test */
  .pramSingleBit = 1U,
  /* PRAM multi-bit error test  */
  .pramMultiBit = 1U,
  /* SRAM single-bit error test */
  .sramSingleBit = 1U,
  /* SRAM multi-bit error test  */
  .sramMultiBit = 1U,
  #if SAF_ITCM_SUPPORTED
  /* itcm multi-bit error test  */
  .itcmSingleBit = 1U,
  /* itcm multi-bit error test  */
  .itcmMultiBit = 1U,
#endif
};

/* Ram Ecc report path test call back */
SAF_RAM_SEC_CONFIG_DATA
const call_config_t s_ramEccCallSet =
{
    /* Ram notification function */
    .callback       = NULL,
    /* Ram notification function parameter */
    .callbackParam  = NULL
};

/* CMPU access right test object */
SAF_CMPU_SEC_CONFIG_DATA
const saf_mpu_access_right_test_param_t s_mpuAcRightTestCfg =
{
  /* CMPU read limit select value */
  .readLimitSelect = 1U,
  /* CMPU write limit select value */
  .writeLimitSelect = 1U,
};

/* CMPU access right test call back */
SAF_CMPU_SEC_CONFIG_DATA
const call_config_t s_mpuCallSet =
{
    /* Cmpu notification function */
    .callback       = NULL,
    /* Cmpu notification function parameter */
    .callbackParam  = NULL
};

/* SMPU access right test object */
SAF_SMPU_SEC_CONFIG_DATA
const saf_smpu_access_right_test_param_t s_smpuAcRightTestCfg =
{
  /* SMPU read limit select value */
  .readLimitSelect = 1U,
  /* SMPU write limit select value */
  .writeLimitSelect = 1U,
};

/* SMPU access right test call back */
SAF_SMPU_SEC_CONFIG_DATA
const call_config_t s_smpuCallSet =
{
    /* Smpu notification function */
    .callback       = NULL,
    /* Smpu notification function parameter */
    .callbackParam  = NULL
};

/* Cache Edc test call back */
SAF_CACHE_SEC_CONFIG_DATA
const call_config_t s_cacheCallSet =
{
    /* Cache notification function */
    .callback       = NULL,
    /* Cache notification function parameter */
    .callbackParam  = NULL
};

/**
* @brief Stack monitor test call back.
*/
SAF_STACK_SEC_CONFIG_DATA
const call_config_t s_stackCallSet =
{
    /* Stack notification function */
    .callback       = NULL,
    /* Stack notification function parameter */
    .callbackParam  = NULL
};

/* Configuration structure for Core CMPU which is used by CPU_Z7_0 */
SAF_CMPU_SEC_VAR_INIT
cmpu_module_cfg_t mpu_CfgZ70 = {

    .sBypass   = CMPU_BYPASS_EXEC,
    .uBypass   = CMPU_BYPASS_NONE,
    .debugOpt  = CMPU_DEBUG_NONE,
    .tidCtrl   = 0
};
/* Array of entry configurations for CMPU CPU_Z7_0 */
SAF_CMPU_SEC_VAR_INIT
cmpu_entry_cfg_t mpuEntryArrayZ70[SAFETYMEMTEST_CMPU_Z70_ENTRY_COUNT_BY_SELF] = {
    {
        .iprot                  = 0U,
        .readOnly               = 0U,
        .debug                  = 0U,
        .regType                = CMPU_DATA_REGION,
        .regId                  = 0U,
        .addrMask               = 0U,
        .uRight                 = CMPU_RW,
        .sRight                 = CMPU_RW,
        .cacheInhibitOverride   = 0U,
        .guardOverride          = 0U,
        .cacheInhibit           = 0U,
        .guard                  = 0U,
        .tid                    = 0U,
        .tidMask                = 0U,
        .startAddr              = (uint32_t)0x0UL,
        .endAddr                = (uint32_t)0x40060fffUL
    },
    {
        .iprot                  = 0U,
        .readOnly               = 0U,
        .debug                  = 0U,
        .regType                = CMPU_DATA_REGION,
        .regId                  = 1U,
        .addrMask               = 0U,
        .uRight                 = CMPU_W,
        .sRight                 = CMPU_W,
        .cacheInhibitOverride   = 0U,
        .guardOverride          = 0U,
        .cacheInhibit           = 0U,
        .guard                  = 0U,
        .tid                    = 0U,
        .tidMask                = 0U,
        .startAddr              = (uint32_t)0x40061000UL,
        .endAddr                = (uint32_t)0x400611ffUL
    },
    {
        .iprot                  = 0U,
        .readOnly               = 0U,
        .debug                  = 0U,
        .regType                = CMPU_DATA_REGION,
        .regId                  = 2U,
        .addrMask               = 0U,
        .uRight                 = CMPU_R,
        .sRight                 = CMPU_R,
        .cacheInhibitOverride   = 0U,
        .guardOverride          = 0U,
        .cacheInhibit           = 0U,
        .guard                  = 0U,
        .tid                    = 0U,
        .tidMask                = 0U,
        .startAddr              = (uint32_t)0x40061000UL,
        .endAddr                = (uint32_t)0x400611ffUL
    },
    {
        .iprot                  = 0U,
        .readOnly               = 0U,
        .debug                  = 0U,
        .regType                = CMPU_DATA_REGION,
        .regId                  = 3U,
        .addrMask               = 0U,
        .uRight                 = CMPU_RW,
        .sRight                 = CMPU_RW,
        .cacheInhibitOverride   = 0U,
        .guardOverride          = 0U,
        .cacheInhibit           = 0U,
        .guard                  = 0U,
        .tid                    = 0U,
        .tidMask                = 0U,
        .startAddr              = (uint32_t)0x40061200UL,
        .endAddr                = (uint32_t)0xffffffffUL
    },
};
/* Configuration structure for Core CMPU which is used by CACHE  */
SAF_CMPU_SEC_VAR_INIT
cmpu_module_cfg_t cache_mpu_Cfg = {
    .sBypass   = CMPU_BYPASS_NONE,
    .uBypass   = CMPU_BYPASS_NONE,
    .debugOpt  = CMPU_DEBUG_NONE,
    .tidCtrl   = 0
};
/* Array of entry configurations for CACHE */
SAF_CMPU_SEC_VAR_INIT
cmpu_entry_cfg_t cache_mpuEntryArray[SAFETYMEMTEST_CMPU_ENTRY_COUNT_BY_CACHE] = {
    {
        .iprot                  = 1U,
        .readOnly               = 0U,
        .debug                  = 0U,
        .regType                = CMPU_SHARED_DATA_REGION,
        .regId                  = 0U,
        .addrMask               = 0U,
        .uRight                 = CMPU_RW,
        .sRight                 = CMPU_RW,
        .cacheInhibitOverride   = 0U,
        .guardOverride          = 0U,
        .cacheInhibit           = 1U,
        .guard                  = 1U,
        .tid                    = 0U,
        .tidMask                = 0U,
        .startAddr              = (uint32_t)0x40000000UL,
        .endAddr                = (uint32_t)0x400bffffUL
    },
    {
        .iprot                  = 1U,
        .readOnly               = 0U,
        .debug                  = 0U,
        .regType                = CMPU_SHARED_DATA_REGION,
        .regId                  = 1U,
        .addrMask               = 0U,
        .uRight                 = CMPU_RW,
        .sRight                 = CMPU_RW,
        .cacheInhibitOverride   = 0U,
        .guardOverride          = 0U,
        .cacheInhibit           = 1U,
        .guard                  = 1U,
        .tid                    = 0U,
        .tidMask                = 0U,
        .startAddr              = (uint32_t)0x1000000UL,
        .endAddr                = (uint32_t)0x13e1000UL
    },
    {
        .iprot                  = 1U,
        .readOnly               = 0U,
        .debug                  = 0U,
        .regType                = CMPU_SHARED_EXEC_REGION,
        .regId                  = 0U,
        .addrMask               = 0U,
        .uRight                 = CMPU_RW,
        .sRight                 = CMPU_RW,
        .cacheInhibitOverride   = 0U,
        .guardOverride          = 0U,
        .cacheInhibit           = 1U,
        .guard                  = 1U,
        .tid                    = 0U,
        .tidMask                = 0U,
        .startAddr              = (uint32_t)0x40000000UL,
        .endAddr                = (uint32_t)0x400bffffUL
    },
    {
        .iprot                  = 1U,
        .readOnly               = 0U,
        .debug                  = 0U,
        .regType                = CMPU_SHARED_EXEC_REGION,
        .regId                  = 1U,
        .addrMask               = 0U,
        .uRight                 = CMPU_RW,
        .sRight                 = CMPU_RW,
        .cacheInhibitOverride   = 0U,
        .guardOverride          = 0U,
        .cacheInhibit           = 1U,
        .guard                  = 1U,
        .tid                    = 0U,
        .tidMask                = 0U,
        .startAddr              = (uint32_t)0x1000000UL,
        .endAddr                = (uint32_t)0x13e1000UL
    },
    {
        .iprot                  = 1U,
        .readOnly               = 0U,
        .debug                  = 0U,
        .regType                = CMPU_DATA_REGION,
        .regId                  = 0U,
        .addrMask               = 0U,
        .uRight                 = CMPU_NONE,
        .sRight                 = CMPU_RW,
        .cacheInhibitOverride   = 1U,
        .guardOverride          = 1U,
        .cacheInhibit           = 1U,
        .guard                  = 0U,
        .tid                    = 0U,
        .tidMask                = 0U,
        .startAddr              = (uint32_t)0x0UL,
        .endAddr                = (uint32_t)0x40000000UL
    },
    {
        .iprot                  = 1U,
        .readOnly               = 0U,
        .debug                  = 0U,
        .regType                = CMPU_DATA_REGION,
        .regId                  = 1U,
        .addrMask               = 0U,
        .uRight                 = CMPU_NONE,
        .sRight                 = CMPU_RW,
        .cacheInhibitOverride   = 1U,
        .guardOverride          = 1U,
        .cacheInhibit           = 1U,
        .guard                  = 0U,
        .tid                    = 0U,
        .tidMask                = 0U,
        .startAddr              = (uint32_t)0x40000000UL,
        .endAddr                = (uint32_t)0x4002ffffUL
    },
    {
        .iprot                  = 1U,
        .readOnly               = 0U,
        .debug                  = 0U,
        .regType                = CMPU_DATA_REGION,
        .regId                  = 2U,
        .addrMask               = 0U,
        .uRight                 = CMPU_NONE,
        .sRight                 = CMPU_RW,
        .cacheInhibitOverride   = 1U,
        .guardOverride          = 1U,
        .cacheInhibit           = 0U,
        .guard                  = 0U,
        .tid                    = 0U,
        .tidMask                = 0U,
        .startAddr              = (uint32_t)0x40030000UL,
        .endAddr                = (uint32_t)0x40030fffUL
    },
    {
        .iprot                  = 1U,
        .readOnly               = 0U,
        .debug                  = 0U,
        .regType                = CMPU_DATA_REGION,
        .regId                  = 3U,
        .addrMask               = 0U,
        .uRight                 = CMPU_NONE,
        .sRight                 = CMPU_RW,
        .cacheInhibitOverride   = 1U,
        .guardOverride          = 1U,
        .cacheInhibit           = 1U,
        .guard                  = 0U,
        .tid                    = 0U,
        .tidMask                = 0U,
        .startAddr              = (uint32_t)0x40031000UL,
        .endAddr                = (uint32_t)0xffffffffUL
    },
    {
        .iprot                  = 1U,
        .readOnly               = 0U,
        .debug                  = 0U,
        .regType                = CMPU_EXEC_REGION,
        .regId                  = 0U,
        .addrMask               = 0U,
        .uRight                 = CMPU_NONE,
        .sRight                 = CMPU_R,
        .cacheInhibitOverride   = 1U,
        .guardOverride          = 1U,
        .cacheInhibit           = 1U,
        .guard                  = 0U,
        .tid                    = 0U,
        .tidMask                = 0U,
        .startAddr              = (uint32_t)0x40000000UL,
        .endAddr                = (uint32_t)0x40030fffUL
    },
    {
        .iprot                  = 1U,
        .readOnly               = 0U,
        .debug                  = 0U,
        .regType                = CMPU_EXEC_REGION,
        .regId                  = 1U,
        .addrMask               = 0U,
        .uRight                 = CMPU_NONE,
        .sRight                 = CMPU_R,
        .cacheInhibitOverride   = 1U,
        .guardOverride          = 1U,
        .cacheInhibit           = 0U,
        .guard                  = 0U,
        .tid                    = 0U,
        .tidMask                = 0U,
        .startAddr              = (uint32_t)0x40031000UL,
        .endAddr                = (uint32_t)0x40031fffUL
    },
    {
        .iprot                  = 1U,
        .readOnly               = 0U,
        .debug                  = 0U,
        .regType                = CMPU_EXEC_REGION,
        .regId                  = 2U,
        .addrMask               = 0U,
        .uRight                 = CMPU_NONE,
        .sRight                 = CMPU_R,
        .cacheInhibitOverride   = 1U,
        .guardOverride          = 1U,
        .cacheInhibit           = 1U,
        .guard                  = 0U,
        .tid                    = 0U,
        .tidMask                = 0U,
        .startAddr              = (uint32_t)0x40032000UL,
        .endAddr                = (uint32_t)0x40032fffUL
    },
    {
        .iprot                  = 1U,
        .readOnly               = 0U,
        .debug                  = 0U,
        .regType                = CMPU_EXEC_REGION,
        .regId                  = 3U,
        .addrMask               = 0U,
        .uRight                 = CMPU_NONE,
        .sRight                 = CMPU_R,
        .cacheInhibitOverride   = 1U,
        .guardOverride          = 1U,
        .cacheInhibit           = 1U,
        .guard                  = 0U,
        .tid                    = 0U,
        .tidMask                = 0U,
        .startAddr              = (uint32_t)0x40033000UL,
        .endAddr                = (uint32_t)0xffffffffUL
    },
};

/* Array of master access right configurations for SMPU0 */
SAF_SMPU_SEC_VAR_INIT
smpu_master_acc_right_t s_smpu0MasterAccConfig[SAFETYMEMTEST_SMPU_0_ENTRY_COUNT][6] = {
    /* SMPU0 entry 0 master access right*/
    {
        /* MASTER_CORE0*/
        {
            .masterNum              = SAF_SMPU_MASTER_CORE0,
            .accRight               = SMPU_RW
        },
        /* MASTER_DMA0*/
        {
            .masterNum              = SAF_SMPU_MASTER_DMA0,
            .accRight               = SMPU_RW
        },
        /* MASTER_CORE0DEBUG*/
        {
            .masterNum              = SAF_SMPU_MASTER_CORE0DEBUG,
            .accRight               = SMPU_RW
        },
        /* MASTER_DMA1*/
        {
            .masterNum              = SAF_SMPU_MASTER_DMA1,
            .accRight               = SMPU_RW
        },
        /* MASTER_HSM*/
        {
            .masterNum              = SAF_SMPU_MASTER_HSM,
            .accRight               = SMPU_RW
        },
        /* MASTER_NAR*/
        {
            .masterNum              = SAF_SMPU_MASTER_NAR,
            .accRight               = SMPU_RW
        },
    },
    /* SMPU0 entry 1 master access right*/
    {
        /* MASTER_CORE0*/
        {
            .masterNum              = SAF_SMPU_MASTER_CORE0,
            .accRight               = SMPU_R
        },
        /* MASTER_DMA0*/
        {
            .masterNum              = SAF_SMPU_MASTER_DMA0,
            .accRight               = SMPU_RW
        },
        /* MASTER_CORE0DEBUG*/
        {
            .masterNum              = SAF_SMPU_MASTER_CORE0DEBUG,
            .accRight               = SMPU_RW
        },
        /* MASTER_DMA1*/
        {
            .masterNum              = SAF_SMPU_MASTER_DMA1,
            .accRight               = SMPU_RW
        },
        /* MASTER_HSM*/
        {
            .masterNum              = SAF_SMPU_MASTER_HSM,
            .accRight               = SMPU_RW
        },
        /* MASTER_NAR*/
        {
            .masterNum              = SAF_SMPU_MASTER_NAR,
            .accRight               = SMPU_RW
        },
    },
    /* SMPU0 entry 2 master access right*/
    {
        /* MASTER_CORE0*/
        {
            .masterNum              = SAF_SMPU_MASTER_CORE0,
            .accRight               = SMPU_W
        },
        /* MASTER_DMA0*/
        {
            .masterNum              = SAF_SMPU_MASTER_DMA0,
            .accRight               = SMPU_RW
        },
        /* MASTER_CORE0DEBUG*/
        {
            .masterNum              = SAF_SMPU_MASTER_CORE0DEBUG,
            .accRight               = SMPU_RW
        },
        /* MASTER_DMA1*/
        {
            .masterNum              = SAF_SMPU_MASTER_DMA1,
            .accRight               = SMPU_RW
        },
        /* MASTER_HSM*/
        {
            .masterNum              = SAF_SMPU_MASTER_HSM,
            .accRight               = SMPU_RW
        },
        /* MASTER_NAR*/
        {
            .masterNum              = SAF_SMPU_MASTER_NAR,
            .accRight               = SMPU_RW
        },
    },
    /* SMPU0 entry 3 master access right*/
    {
        /* MASTER_CORE0*/
        {
            .masterNum              = SAF_SMPU_MASTER_CORE0,
            .accRight               = SMPU_RW
        },
        /* MASTER_DMA0*/
        {
            .masterNum              = SAF_SMPU_MASTER_DMA0,
            .accRight               = SMPU_RW
        },
        /* MASTER_CORE0DEBUG*/
        {
            .masterNum              = SAF_SMPU_MASTER_CORE0DEBUG,
            .accRight               = SMPU_RW
        },
        /* MASTER_DMA1*/
        {
            .masterNum              = SAF_SMPU_MASTER_DMA1,
            .accRight               = SMPU_RW
        },
        /* MASTER_HSM*/
        {
            .masterNum              = SAF_SMPU_MASTER_HSM,
            .accRight               = SMPU_RW
        },
        /* MASTER_NAR*/
        {
            .masterNum              = SAF_SMPU_MASTER_NAR,
            .accRight               = SMPU_RW
        },
    },
};

/* Array of entry configurations for SMPU0 */
SAF_SMPU_SEC_VAR_INIT
smpu_config_t smpu0EntryArray[SAFETYMEMTEST_SMPU_0_ENTRY_COUNT] = {
    {
        .startAddr              = (uint32_t)0x0UL,
        .endAddr                = (uint32_t)0x400dffffUL,
        .masterAccRight         = s_smpu0MasterAccConfig[0],
        .cacheInhibitEnable     = 0U,
        .lockConfig             = SMPU_UNLOCK
    },
    {
        .startAddr              = (uint32_t)0x400e0000UL,
        .endAddr                = (uint32_t)0x400e1fffUL,
        .masterAccRight         = s_smpu0MasterAccConfig[1],
        .cacheInhibitEnable     = 0U,
        .lockConfig             = SMPU_UNLOCK
    },
    {
        .startAddr              = (uint32_t)0x400e0000UL,
        .endAddr                = (uint32_t)0x400e1fffUL,
        .masterAccRight         = s_smpu0MasterAccConfig[2],
        .cacheInhibitEnable     = 0U,
        .lockConfig             = SMPU_UNLOCK
    },
    {
        .startAddr              = (uint32_t)0x400e2000UL,
        .endAddr                = (uint32_t)0xefffffffUL,
        .masterAccRight         = s_smpu0MasterAccConfig[3],
        .cacheInhibitEnable     = 0U,
        .lockConfig             = SMPU_UNLOCK
    },
};
/* Array of master access right configurations for SMPU1 */
SAF_SMPU_SEC_VAR_INIT
smpu_master_acc_right_t s_smpu1MasterAccConfig[SAFETYMEMTEST_SMPU_1_ENTRY_COUNT][6] = {
    /* SMPU1 entry 0 master access right*/
    {
        /* MASTER_CORE0*/
        {
            .masterNum              = SAF_SMPU_MASTER_CORE0,
            .accRight               = SMPU_RW
        },
        /* MASTER_DMA0*/
        {
            .masterNum              = SAF_SMPU_MASTER_DMA0,
            .accRight               = SMPU_RW
        },
        /* MASTER_CORE0DEBUG*/
        {
            .masterNum              = SAF_SMPU_MASTER_CORE0DEBUG,
            .accRight               = SMPU_RW
        },
        /* MASTER_DMA1*/
        {
            .masterNum              = SAF_SMPU_MASTER_DMA1,
            .accRight               = SMPU_RW
        },
        /* MASTER_HSM*/
        {
            .masterNum              = SAF_SMPU_MASTER_HSM,
            .accRight               = SMPU_RW
        },
        /* MASTER_NAR*/
        {
            .masterNum              = SAF_SMPU_MASTER_NAR,
            .accRight               = SMPU_RW
        },
    },
    /* SMPU1 entry 1 master access right*/
    {
        /* MASTER_CORE0*/
        {
            .masterNum              = SAF_SMPU_MASTER_CORE0,
            .accRight               = SMPU_R
        },
        /* MASTER_DMA0*/
        {
            .masterNum              = SAF_SMPU_MASTER_DMA0,
            .accRight               = SMPU_RW
        },
        /* MASTER_CORE0DEBUG*/
        {
            .masterNum              = SAF_SMPU_MASTER_CORE0DEBUG,
            .accRight               = SMPU_RW
        },
        /* MASTER_DMA1*/
        {
            .masterNum              = SAF_SMPU_MASTER_DMA1,
            .accRight               = SMPU_RW
        },
        /* MASTER_HSM*/
        {
            .masterNum              = SAF_SMPU_MASTER_HSM,
            .accRight               = SMPU_RW
        },
        /* MASTER_NAR*/
        {
            .masterNum              = SAF_SMPU_MASTER_NAR,
            .accRight               = SMPU_RW
        },
    },
    /* SMPU1 entry 2 master access right*/
    {
        /* MASTER_CORE0*/
        {
            .masterNum              = SAF_SMPU_MASTER_CORE0,
            .accRight               = SMPU_W
        },
        /* MASTER_DMA0*/
        {
            .masterNum              = SAF_SMPU_MASTER_DMA0,
            .accRight               = SMPU_RW
        },
        /* MASTER_CORE0DEBUG*/
        {
            .masterNum              = SAF_SMPU_MASTER_CORE0DEBUG,
            .accRight               = SMPU_RW
        },
        /* MASTER_DMA1*/
        {
            .masterNum              = SAF_SMPU_MASTER_DMA1,
            .accRight               = SMPU_RW
        },
        /* MASTER_HSM*/
        {
            .masterNum              = SAF_SMPU_MASTER_HSM,
            .accRight               = SMPU_RW
        },
        /* MASTER_NAR*/
        {
            .masterNum              = SAF_SMPU_MASTER_NAR,
            .accRight               = SMPU_RW
        },
    },
    /* SMPU1 entry 3 master access right*/
    {
        /* MASTER_CORE0*/
        {
            .masterNum              = SAF_SMPU_MASTER_CORE0,
            .accRight               = SMPU_RW
        },
        /* MASTER_DMA0*/
        {
            .masterNum              = SAF_SMPU_MASTER_DMA0,
            .accRight               = SMPU_RW
        },
        /* MASTER_CORE0DEBUG*/
        {
            .masterNum              = SAF_SMPU_MASTER_CORE0DEBUG,
            .accRight               = SMPU_RW
        },
        /* MASTER_DMA1*/
        {
            .masterNum              = SAF_SMPU_MASTER_DMA1,
            .accRight               = SMPU_RW
        },
        /* MASTER_HSM*/
        {
            .masterNum              = SAF_SMPU_MASTER_HSM,
            .accRight               = SMPU_RW
        },
        /* MASTER_NAR*/
        {
            .masterNum              = SAF_SMPU_MASTER_NAR,
            .accRight               = SMPU_RW
        },
    },
};

/* Array of entry configurations for SMPU1 */
SAF_SMPU_SEC_VAR_INIT
smpu_config_t smpu1EntryArray[SAFETYMEMTEST_SMPU_1_ENTRY_COUNT] = {
    {
        .startAddr              = (uint32_t)0xf0000000UL,
        .endAddr                = (uint32_t)0xffe8bfffUL,
        .masterAccRight         = s_smpu1MasterAccConfig[0],
        .cacheInhibitEnable     = 0U,
        .lockConfig             = SMPU_UNLOCK
    },
    {
        .startAddr              = (uint32_t)0xffe8c000UL,
        .endAddr                = (uint32_t)0xffe8c09fUL,
        .masterAccRight         = s_smpu1MasterAccConfig[1],
        .cacheInhibitEnable     = 0U,
        .lockConfig             = SMPU_UNLOCK
    },
    {
        .startAddr              = (uint32_t)0xffe8c000UL,
        .endAddr                = (uint32_t)0xffe8c09fUL,
        .masterAccRight         = s_smpu1MasterAccConfig[2],
        .cacheInhibitEnable     = 0U,
        .lockConfig             = SMPU_UNLOCK
    },
    {
        .startAddr              = (uint32_t)0xffe8c0a0UL,
        .endAddr                = (uint32_t)0xffffffffUL,
        .masterAccRight         = s_smpu1MasterAccConfig[3],
        .cacheInhibitEnable     = 0U,
        .lockConfig             = SMPU_UNLOCK
    },
};

#ifdef __cplusplus
}
#endif
