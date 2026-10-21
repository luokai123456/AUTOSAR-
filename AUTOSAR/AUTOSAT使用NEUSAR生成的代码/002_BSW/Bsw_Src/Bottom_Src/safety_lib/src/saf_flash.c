/**
****************************************************************************************
 * @FilePath: saf_flash.c
 * @Author: CCORE
 * @Date: 2024-02-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety flash C File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifdef __cplusplus
extern "C"{
#endif
/*PRQA S 0315,0492,0499,0686,0704,0751 EOF*/
/*PRQA S 1514,1840,1842,1862,1881,1891,1259 EOF*/
/*PRQA S 2844,2963,2982,2991,2995 EOF*/
/*PRQA S 3401,3200,3393,3397,3119,3334,3408,3218,3344,3400,3432,3604 EOF*/
/*PRQA S 4322,4404,4522,4304,4342,4397,4499 EOF*/
/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_flash.h"/*PRQA S 0380*/
#include "saf_cpu.h"
#include "fccu_lld.h"
#include "saf_fccu.h"
#include "Saf_MemMap.h"
#include "common.h"
/**
****************************************************************************************
 * @brief: Definitions
****************************************************************************************
*/
#define BUFFER_SIZE_TEST                                    (0x80U)

#define SAF_FLASH_CALC_SINGLE_BLOCK_MISR_TIMEOUT_MS          (500U)

#define SAF_FLASH_SINGLE_BIT_INJECT_DATA_LIST                {{0xFFFFFFFF, 0x00000000}, {0xFFFFFFFF, 0x00000001}}
#define SAF_FLASH_MULTI_BIT_INJECT_DATA_LIST                 {{0x00450000, 0x00000000}, {0x00580000, 0x00000000}}

/**
****************************************************************************************
 * @brief: Variables
****************************************************************************************
*/
SAF_FLASH_SEC_VAR_INIT
uint32_t flsOverlayTestMirrAddr = SAF_FLASH_OVERLAY_TEST_FLASH_MIRR_ADDR;
SAF_FLASH_SEC_VAR_INIT
static uint32_t s_flsOverlaySramAddr = SAF_FLASH_OVERLAY_TEST_SRAM_ADDR;
SAF_FLASH_SEC_VAR_INIT
static uint32_t s_flsOverlayTestRemapSize = SAF_FLASH_OVERLAY_TEST_REMAP_SIZE;

#if !(defined(CCFC3008PT) | defined(CCFC3008PC) | defined(CCFC3008PCSN))
/* SRAM buffer for access code */
#if defined(CCFC3008PT)
SAF_FLASH_SEC_VAR_INIT
static uint32_t SAF_AcCodeArea[1024] = {0U};
#endif /* defined(CCFC3008PT) */
#else
SAF_FLASH_SEC_VAR_INIT
static uint32_t SAF_AcCodeAreaAI[512] = {0U};
SAF_FLASH_SEC_VAR_INIT
static uint32_t SAF_AcCodeAreaMR[512] = {0U};
/* Function pointer of access code */
SAF_FLASH_SEC_VAR_NO_INIT
static saf_fls_acload_t SAF_AcCodePtr;

SAF_FLASH_SEC_VAR_NO_INIT
static flash_context_data_t aiMrCtxData;
SAF_FLASH_SEC_VAR_NO_INIT
static fls_blk_sel_t aiMrBlockSelect;
SAF_FLASH_SEC_VAR_NO_INIT
static flash_misr_t aiMrMisrValue;
SAF_FLASH_SEC_VAR_INIT
static status_t aiMrStatus = STATUS_SUCCESS;        /* return code */
SAF_FLASH_SEC_VAR_INIT
static flash_margin_option_t marginLevel = C55_MARGIN_LEVEL_PROGRAM;
#endif /* !(defined(CCFC3008PT) | defined(CCFC3008PC) | defined(CCFC3008PCSN)) */
SAF_FLASH_SEC_VAR_INIT
uint32_t saf_timeout_cnt = 0U;
SAF_FLASH_SEC_VAR_INIT
uint32_t saf_test_start = 0U;

extern const saf_flash_ecc_report_path_test_param_t s_flashEccConfigSet;
extern const fls_blk_sel_t s_flashAIConfigSet;
extern const fls_blk_sel_t s_flashMRConfigSet;
extern uint32_t sramEccIntcFlag;

SAF_FLASH_SEC_VAR_INIT
static uint32_t s_flashCeTriggerAddr = SAF_FLASH_ECC_CE_TRIGGER_ADDRESS;
SAF_FLASH_SEC_VAR_INIT
static uint32_t s_flashUceTriggerAddr = SAF_FLASH_ECC_UCE_TRIGGER_ADDRESS;

SAF_FLASH_SEC_VAR_NO_INIT
static saf_flash_saved_test_data_t s_storeSafetyInfo;

/* ECC report path test object */
SAF_FLASH_SEC_VAR_INIT
static saf_flash_ecc_report_path_test_t s_flashEccReportPathTest =
{
    .output =
    {
        .singleBitPassed = 0,
        .multiBitPassed  = 0,
    },
};

/* Flash array integrity test object */
SAF_FLASH_SEC_VAR_INIT
static saf_flash_ai_test_t s_flashArrayIntegriteTest =
{
    .output.blockPassed =
    {
        .lowBlkSel = 0,
        .midBlkSel = 0,
        .highBlkSel = 0,
        #ifndef CCFC3012PT
		.first256KBlkSel = 0,
        .second256KBlkSel = 0,
		#else
        .large0BlkSel = 0,
        .large1BlkSel = 0,
		.large2BlkSel = 0,
		.large3BlkSel = 0,
		.large4BlkSel = 0,
		.large5BlkSel = 0,
		#endif
    }
};

/* Flash margin read test object */
SAF_FLASH_SEC_VAR_INIT
static saf_flash_mr_test_t s_flashMarginReadTest =
{
    .output.blockPassed =
    {
        .lowBlkSel = 0,
        .midBlkSel = 0,
        .highBlkSel = 0,
        #ifndef CCFC3012PT
        .first256KBlkSel = 0,
        .second256KBlkSel = 0,
        #else
        .large0BlkSel = 0,
        .large1BlkSel = 0,
        .large2BlkSel = 0,
        .large3BlkSel = 0,
        .large4BlkSel = 0,
        .large5BlkSel = 0,
		#endif
    }
};

SAF_FLASH_SEC_VAR_NO_INIT
static uint32_t s_flashCETestAddressList[MEMU_FLASH_CORRECTABLE_ERROR_TABLE_NUM];

SAF_FLASH_SEC_VAR_NO_INIT
static uint32_t s_flashUCETestAddressList;

SAF_FLASH_SEC_VAR_INIT
static uint32_t s_flashCETestAddress = 0U;

SAF_FLASH_SEC_VAR_INIT
static uint32_t s_flashUCETestAddress = 0U;

SAF_FLASH_SEC_VAR_NO_INIT
fccu_rf_config_t realFlashEccFccuRfCfg[SAF_FCCU_RF_MAX_SIZE];

SAF_FLASH_SEC_VAR_INIT
fccu_rf_config_t fccFlashEccStartUpRfCfg[] = {
    {
        /* FCCU Channel ID */
        .channel        = (uint8_t)SAF_FCCU_FAILURE_MEMU_FLS_CE_CH_22,
        /* FCCU recoverable fault definitions */
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        /* FCCU recoverable fault state definitions */
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_NO_RESET,
        /* Fault time-out enable */
        .timeout_alarm_enable = (bool)true,
        /* FCCU recoverable faults reaction type definitions */
        .reaction = {
            /* IRQ alarm switch */
            .irq_alarm_en = (bool)true,
            /* NMI switch */
            .nmi_en       = (bool)false,
            /* EOUT signal switch */
            .eout_sig_en  = (bool)false,
        },
        /* Alarm notification function */
        .callback       = &Saf_FlashCEInject_Callback,
        /* The parameters of the alarm notification function */
        .callbackParam  = NULL_PTR
    },

    {
        /* FCCU Channel ID */
        .channel        = (uint8_t)SAF_FCCU_FAILURE_MEMU_FLS_UCE_CH_23,
        /* FCCU recoverable fault definitions */
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        /* FCCU recoverable fault state definitions */
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_NO_RESET,
        /* Fault time-out enable */
        .timeout_alarm_enable = (bool)true,
        /* FCCU recoverable faults reaction type definitions */
        .reaction = {
            /* IRQ alarm switch */
            .irq_alarm_en = (bool)true,
            /* NMI switch */
            .nmi_en       = (bool)false,
            /* EOUT signal switch */
            .eout_sig_en  = (bool)false,
        },
        /* Alarm notification function */
        .callback       = NULL_PTR,
        /* The parameters of the alarm notification function */
        .callbackParam  = NULL_PTR
    },

    {
        /* FCCU Channel ID */
        .channel        = (uint8_t)SAF_FCCU_FAILURE_MEMU_FLS_BOV_CH_24,
        /* FCCU recoverable fault definitions */
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        /* FCCU recoverable fault state definitions */
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_NO_RESET,
        /* Fault time-out enable */
        .timeout_alarm_enable = (bool)true,
        /* FCCU recoverable faults reaction type definitions */
        .reaction = {
            /* IRQ alarm switch */
            .irq_alarm_en = (bool)true,
            /* NMI switch */
            .nmi_en       = (bool)false,
            /* EOUT signal switch */
            .eout_sig_en  = (bool)false,
        },
        /* Alarm notification function */
        .callback       = NULL_PTR,
        /* The parameters of the alarm notification function */
        .callbackParam  = NULL_PTR
    },
};

SAF_FLASH_SEC_VAR_INIT
fccu_config_t fccuFlashEccStartUpCfg=
{
    /* Filter bypss */
    .filter_bypass_enable = (bool)false,
    /* Filter width */
    .filter_width         = 0,
    /* Debug mode entry */
    .debug_enable         = (bool)false,
    /* FCCU EOUT configurations */
    .eout_config          = {
                            /* EOUT signal activation flag */
                            .set_after_reset = (bool)false,
                            /* EOUT control definitions */
                            .control         = (SAF_fccu_ep_control_t)SAF_FCCU_EP_INDEPENDENT_ABOVE_SW,
                            /* FCCU EOUT output definitions */
                            .output          = (SAF_fccu_ep_output_t)SAF_FCCU_EP_OUTPUT_OPEN_DRAIN,
                            /* FCCU EOUT protocol definitions */
                            .switch_mode     = (SAF_fccu_eout_sm_t)SAF_FCCU_EOUT_PROTOCOL_SLOW_SM,
                            /* FCCU EOUT polar select definitions */
                            .polarity_sel    = (SAF_fccu_eout_ps_t)SAF_FCCU_EOUT_0_LOW_1_HIGH,
                            /* Fault Output Mode selection */
                            .mode            = (SAF_fccu_eout_fom_t)SAF_FCCU_FOM_DUAL_RAIL,
                            /* Pin is set to the minimum time of failure state */
                            .delta_t_value   = 0U,
                            },
    /* Configuration time-out interrupt enabled */
    .irq_type             = (SAF_fccu_irq_type_t)SAF_FCCU_IRQ_NONE,
    /* The preset value of the watchdog timer for the recovery from the CONFIG state. */
    .cfg_timeout          = 0,
    /* FCCU lock type definitions */
    .lock_type            = (SAF_fccu_lock_type_t)SAF_FCCU_TRANSIENTLY_UNLOCK,
    /* The number of configured FCCU channels */
    .rfConfigNumber       = (uint8_t)(sizeof(fccFlashEccStartUpRfCfg)/sizeof(fccFlashEccStartUpRfCfg[0])),
    /* time-out notification function */
    .callbackFunc         = NULL_PTR,
    /* The parameters of the time-out notification function */
    .callbackParam        = NULL_PTR
};
/**
****************************************************************************************
 * @brief: Local Function
****************************************************************************************
*/

/**
****************************************************************************************
* @brief:  FLASH single bit error callback.
* @return  void
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
static void SAF_FLASH_CECallback(void)
{
    uint8_t i;
    for(i = 0U; i < MEMU_FLASH_CORRECTABLE_ERROR_TABLE_NUM; i++)
    {
        s_flashCETestAddressList[i] = MEMU_LLD_GetCorrectableErrorAddress(MEMU_FLASH_DETECT, i);
    }
}

/**
****************************************************************************************
* @brief:  FLASH multiple bit error callback.
* @return  void
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
static void SAF_FLASH_UCECallback(void)
{
    s_flashUCETestAddressList = MEMU_LLD_GetUncorrectableErrorAddress(MEMU_FLASH_DETECT);
}

/**
****************************************************************************************
* @brief:  This function is used to enable flash ECC correctable error report.
* @return  void
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
static void SAF_FLASH_AccessEnableCEReport(void)
{
    /* Enable single bit ECC error reporting in flash controller */
    /* Enable UTE user test.For UTE, the password 0xF9F9_9999 must be written to the UT0 register.*/
    FLS_FMC.UT0.R = C55FMC_UT0_PASSWORD;/*PRQA S 1281*/
    /*Enable single bit error correction*/
    FLS_FMC.UT0.R = C55FMC_UT0_SBCE(1);/*PRQA S 1259*/
    /* Disable UTE */
    FLS_FMC.UT0.R = C55FMC_UT0_UTE(0); /*PRQA S 1259*/
}

/**
****************************************************************************************
* @brief:  This function is used to get MISR value in flash AI/MR test.
* @param[in]    regIdx    UMISR register index.
* @return       uint32_t  MISR value
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
static uint32_t SAF_FLASH_AccessGetMisrRegValue(const uint8_t regIdx)
{
    uint32_t reg = 0U;

    if (C55FMC_UM9_OFFEST <= regIdx)
    {
        /* Special reg. */
        reg = FLS_FMC.UM9.B.MISR;
    }
    else
    {
        reg = FLS_FMC.UM[regIdx].B.MISR;
    }
    
    return reg;
}

/**
****************************************************************************************
* @brief:  This function shall be check the assign flash block is selected.
* @param[in]   type       block type.
* @param[in]   blockID    block id.
* @param[in]   pSelect    block selected status point.
* @return      bool
*              true       block is selected
*              false      block is not selected
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
static bool SAF_FLASH_AccessBlockIsSelected(const SAF_FLASH_BLOCK_TYPE type, const uint8_t blockID, const fls_blk_sel_t *pSelect)
{
    bool ret = (bool)false;
    uint32_t blockSelect = 0U;
    #ifndef RESOURCE_SUPPORT_PFI
    uint32_t blockSelectArray[SAF_FLASH_BLOCK_TYPE_COUNT] = { pSelect->lowBlkSel, pSelect->midBlkSel, \
                                                              pSelect->highBlkSel, pSelect->first256KBlkSel, \
                                                              pSelect->second256KBlkSel };
    #else
    uint32_t blockSelectArray[SAF_FLASH_BLOCK_TYPE_COUNT] = { pSelect->lowBlkSel, pSelect->midBlkSel, \
                                                              pSelect->highBlkSel, pSelect->large0BlkSel, \
                                                              pSelect->large1BlkSel, pSelect->large2BlkSel, \
															  pSelect->large3BlkSel, pSelect->large4BlkSel, \
                                                              pSelect->large5BlkSel };
    #endif
    
    if (blockID < SAF_FLASH_MAX_BLOCK_SELECTED)
    {
        if (type < SAF_FLASH_BLOCK_TYPE_COUNT)
        {
            blockSelect = blockSelectArray[type];

            if (SAF_FLASH_NONE_BLOCK_SELECTED != (blockSelect & SAF_FLASH_BLOCK_SELECT_BITS_MASK(blockID)))
            {
                ret = true;
            }
        }
    }

    return ret;
}

/**
****************************************************************************************
* @brief:  This function shall be to get the details of the flash block corresponding
*          to the destination address.
* @param[in]   addr        check target address.
* @param[in]   pFlashInfo  assign flash block information point.
* @return      FS_STATUS
*              FS_STATUS_SUCCESS     get the details succeed
*              FS_STATUS_ERROR       get the details failed
****************************************************************************************
*/
#if defined(CCFC3008PC) | defined(CCFC3008PCSN) | defined(CCFC3008PT)
SAF_FLASH_SEC_CODE
#else
SAF_SEC_RAMCODE
#endif
static FS_STATUS SAF_FLASH_AccessGetFlashInfoByAddr(const uint32_t addr, saf_flash_info_t *pFlashInfo)
{
    FS_STATUS status = FS_STATUS_ERROR;
    uint32_t pBlockBaseAddrList[] = SAF_FLASH_BLOCK_START_ADDR_LIST;
    uint32_t pBlockMemSizeList[] = SAF_FLASH_BLOCK_MEMORY_SIZE_LIST;
    uint8_t blockCountList[] = SAF_FLASH_BLOCK_COUNT_LIST;
    uint8_t type = 0;
    uint8_t blockIndex = 0;
    uint8_t blockID = 0;

    if (NULL != pFlashInfo)
    {
        pFlashInfo->isUtestBlock = false;
        for (type = (uint8_t)SAF_FLASH_LOW_BLOCK; type < (uint8_t)SAF_FLASH_BLOCK_TYPE_COUNT; type++)
        {
            for (blockID = 0; blockID < blockCountList[type]; blockID++)
            {
                if ((addr >= pBlockBaseAddrList[blockIndex]) && ((addr - pBlockBaseAddrList[blockIndex]) < pBlockMemSizeList[blockIndex]))/* polyspace RTE:OBAI */
                {
                    pFlashInfo->blockType = (SAF_FLASH_BLOCK_TYPE)type;
                    pFlashInfo->blockID   = blockID;
                    status = FS_STATUS_SUCCESS;
                    break;
                }
                blockIndex++;
            }
            if (FS_STATUS_SUCCESS == status)
            {
                break;
            }
        }

        if (FS_STATUS_SUCCESS != status)
        {
            if ((addr >= SAF_FLASH_DCF_START_ADDR) && (addr < (SAF_FLASH_DCF_START_ADDR + SAF_FLASH_DCF_SIZE_BYTES)))
            {
                pFlashInfo->isUtestBlock = true;
                status = FS_STATUS_SUCCESS;
            }
        }
    }
    
    return status;
}

/**
****************************************************************************************
* @brief:  This function shall be to set flash block select information.
* @param[in]   blockType        block type.
* @param[in]   blockID          block id.
* @param[out]  pBlockSelect     block selected status point.
* @return      FS_STATUS
*              FS_STATUS_SUCCESS     set flash block select information succeed
*              FS_STATUS_ERROR       set flash block select information failed
****************************************************************************************
*/
#if defined(CCFC3008PC) | defined(CCFC3008PCSN) | defined(CCFC3008PT)
SAF_FLASH_SEC_CODE
#else
SAF_SEC_RAMCODE
#endif
static FS_STATUS SAF_FLASH_AccessSetFlashArrayBlock(const SAF_FLASH_BLOCK_TYPE blockType, const uint8_t blockID, fls_blk_sel_t *pBlockSelect)
{
    FS_STATUS status = FS_STATUS_SUCCESS; 
    
    #ifndef RESOURCE_SUPPORT_PFI
    uint32_t *pBlockSelectArray[SAF_FLASH_BLOCK_TYPE_COUNT] = { &pBlockSelect->lowBlkSel, &pBlockSelect->midBlkSel, \
    														  &pBlockSelect->highBlkSel, &pBlockSelect->first256KBlkSel, \
															  &pBlockSelect->second256KBlkSel };
    #else
    uint32_t *pBlockSelectArray[SAF_FLASH_BLOCK_TYPE_COUNT] = { &pBlockSelect->lowBlkSel, &pBlockSelect->midBlkSel, \
    														  &pBlockSelect->highBlkSel, &pBlockSelect->large0BlkSel, \
															  &pBlockSelect->large1BlkSel, &pBlockSelect->large2BlkSel, \
															  &pBlockSelect->large3BlkSel, &pBlockSelect->large4BlkSel, \
															  &pBlockSelect->large5BlkSel };
    #endif

    if (blockID < SAF_FLASH_MAX_BLOCK_SELECTED)
    {
        if (blockType < SAF_FLASH_BLOCK_TYPE_COUNT)
        {
            *pBlockSelectArray[blockType] |= SAF_FLASH_BLOCK_SELECT_BITS_MASK(blockID);
        }
        else
        {
            status = FS_STATUS_ERROR;
        }
    }
    return status;

}

/**
****************************************************************************************
* @brief:  This function shall be to initialize store information.
* @return      void
****************************************************************************************
*/
#if defined(CCFC3008PT) | defined(CCFC3008PC) | defined(CCFC3008PCSN)
SAF_FLASH_SEC_CODE
#else
SAF_SEC_RAMCODE
#endif
static void SAF_FLASH_AccessSafetyInfoStoreInit(void)
{
    uint32_t totalLen = sizeof(saf_flash_saved_test_data_t);
    saf_flash_saved_test_data_t *pRamSafetyInfoObj = &s_storeSafetyInfo;

    /* Prevent unnecessary re-entry */
    saf_test_start = 1U;

	pRamSafetyInfoObj->totalLen = totalLen;

	/* init FLASH AI*/
	pRamSafetyInfoObj->flashAiMisr.updated = 0;
	pRamSafetyInfoObj->flashAiMisr.header.type = SAF_FLASH_AI;
	pRamSafetyInfoObj->flashAiMisr.header.len = sizeof(saf_flash_ai_safety_info_t);

	/* init FLASH MR*/
	pRamSafetyInfoObj->flashMrMisr.updated = 0;
	pRamSafetyInfoObj->flashMrMisr.header.type = SAF_FLASH_MR;
	pRamSafetyInfoObj->flashMrMisr.header.len = sizeof(saf_flash_mr_safety_info_t);

	/* init FLASH ECC */
	pRamSafetyInfoObj->flashEccPathTest.header.type = SAF_FLASH_ECC;
	pRamSafetyInfoObj->flashEccPathTest.header.len = sizeof(saf_flash_ecc_safety_info_t);

}

/**
****************************************************************************************
* @brief:  This function is be used to get safety information header.
* @param[in]   type      flash test type.
* @return      void*     flash test information header.
****************************************************************************************
*/
#if defined(CCFC3008PT) | defined(CCFC3008PC) | defined(CCFC3008PCSN)
SAF_FLASH_SEC_CODE
#else
SAF_SEC_RAMCODE
#endif
static void *SAF_FLASH_AccessGetSafetyInfoHeader(SAF_FLASH_SAFETY_INFO_TYPE type)/*PRQA S 3675*/
{
    saf_flash_saved_test_data_t *pSafetyInfoObj = &s_storeSafetyInfo;
    saf_flash_safety_info_header_t *ptHeader = NULL;
    uint32_t offset = sizeof(pSafetyInfoObj->totalLen);
    uint32_t totalLen = 0U;

    if (SAF_FLASH_SAFETY_INFO_STORE_UNINITIALIZED == saf_test_start)
    {
        SAF_FLASH_AccessSafetyInfoStoreInit();
    }

    totalLen = pSafetyInfoObj->totalLen;

    if ((pSafetyInfoObj->totalLen > 0U) && (pSafetyInfoObj->totalLen != SAF_FLASH_SAFETY_INFO_STORE_INVALID_VALUE))
    {
        while (offset < totalLen)
        {
            ptHeader = (saf_flash_safety_info_header_t *)((uint32_t )pSafetyInfoObj + offset);
            if (ptHeader->type == type)/* polyspace RTE:NIV,IDP */
            {
                break;
            }

            offset += ptHeader->len;/* polyspace RTE:NIV */
        }
    }

    return ptHeader;
}

/**
****************************************************************************************
* @brief:  This function shall be to confirm test status and compare flash block MISR value.
* @param[in]   pCtxData   test context data point.
* @param[out]  opStatus   test operation status point.
* @return      status_t
*              STATUS_SUCCESS   confirm and compare succeed
*              STATUS_ERROR     confirm and compare failed
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
static status_t SAF_FLASH_AccessCheckUserTestStatusExecution
(
    const flash_context_data_t * pCtxData,
    flash_state_t * opStatus
)
{
    status_t returnCode = STATUS_SUCCESS;           /* return code */
    *opStatus = C55_OK;
    uint32_t temp;
    uint8_t index;

    /* Compare the hardware calculated MISR to the user input */
    for (index = 0x0U; index < C55FMC_UM_COUNT; index++)
    {
        temp = pCtxData->pMisr->arrMISRValue[index];/* polyspace RTE:NIV,NIP,IDP */
        if (FLS_FMC.UM[index].B.MISR != temp)/* polyspace RTE:NIV */
        {
            returnCode = STATUS_ERROR;
            break;
        }
    }

    if (FLS_FMC.UM9.B.MISR != pCtxData->pMisr->arrMISRValue[9])/* polyspace RTE:NIV */
    {
        returnCode = STATUS_ERROR;
    }

    /* If the operation is broken */
    if (FLS_FMC.UT0.B.NAIBP != 0x0U)
    {
        *opStatus = (FLS_FMC.MCR.B.SBC != 0x0U) ? C55_USER_TEST_BREAK_SBC : C55_USER_TEST_BREAK_DBD;
    }
    else
    {
        /* Clear UT0_MRE, UT0_AIS, UT0_AIE, then UT0_UTE */
        FLS_FMC.UT0.B.AIS = 0U;
        FLS_FMC.UT0.B.MRE = 0U;
        FLS_FMC.UT0.B.AIE = 0U;
        FLS_FMC.UT0.B.UTE = 0U;
    }

    return returnCode;
}

/**
****************************************************************************************
* @brief:  This function shall be to confirm test status.
* @param[in]   pCtxData   test context data point.
* @param[out]  opStatus   test operation status point.
* @return      status_t
*              STATUS_SUCCESS   confirm succeed
*              STATUS_ERROR     confirm failed
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
static status_t SAF_FLASH_AccessCheckUserTestStatus
(
    const flash_context_data_t * pCtxData,
    flash_state_t * opResult
)
{
    status_t returnCode = STATUS_SUCCESS;

    if (NULL_PTR == pCtxData || NULL_PTR == opResult)
    {
        returnCode = STATUS_UNSUPPORTED;
    }
    else
    {
        *opResult = C55_OK;

        /* There must be an UTest operation. */
        if (C55FMC_ARRAY_INTEGRITY_CHECK_DISABLE != FLS_FMC.UT0.B.AIE)
        {
            /* If DONE bit goes high. */
            if (C55FMC_ARRAY_INTEGRITY_CHECK_ONGOING != FLS_FMC.UT0.B.AID)
            {
                /* If the operation is suspended. */
                if (C55FMC_ARRAY_INTEGRITY_SEQUENCE_NOT_SUSPENDED != FLS_FMC.UT0.B.AISUS)
                {
                    *opResult = C55_USER_TEST_SUS;
                }
                else
                {
                    returnCode = SAF_FLASH_AccessCheckUserTestStatusExecution(pCtxData, opResult);
                }
            }
            else
            {
                /* DONE bit is still low means the operation is in-progress. */
                returnCode = STATUS_FLASH_INPROGRESS;
            }
        }
    }

    return returnCode;
}

#if defined(CCFC3008PC) | defined(CCFC3008PCSN) | defined(CCFC3008PT)
/**
****************************************************************************************
* @brief:  This function shall be to execute array integrity self check of the flash.
* @return      void
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
static void SAF_FLASH_ACAICheck(void)
#else
SAF_SEC_RAMCODE
/**
****************************************************************************************
* @brief:  This function shall be to execute array integrity self check of the flash.
* @param[out]  pCtxData         test context data point.
* @param[in]   blockSelect      block selected status point.
* @param[in]   breakOption      array integrity self check break option.
* @param[in]   addrSeq          array integrity self check address sequence.
* @param[in]   pMisrValue       MISR value point.
* @return      status_t
*              STATUS_SUCCESS   the operation succeed
*              STATUS_BUSY      the previous run has not ended, and the situation is busy
*              STATUS_TIMEOUT   the operation timed out
*              STATUS_FLASH_ERROR_NO_BLOCK  the value is selected as block
*              STATUS_FLASH_ERROR_ENABLE    failed to enter UTEST mode
****************************************************************************************
*/
SAF_SEC_RAMCODE
static status_t SAF_FLASH_ArrayIntegrityCheck
(
    flash_context_data_t *pCtxData,
    fls_blk_sel_t *blockSelect,
    flash_ai_break_option_t breakOption,
    flash_ai_sequence_option_t addrSeq,
    flash_misr_t *pMisrValue
)
#endif
{
#if !(defined(CCFC3008PC) | defined(CCFC3008PCSN) | defined(CCFC3008PT))
    DEV_ASSERT((bool)(pCtxData != NULL));
    DEV_ASSERT((bool)(pMisrValue != NULL));
    DEV_ASSERT((bool)(blockSelect != NULL));
    DEV_ASSERT((bool)((addrSeq == C55_AI_ADDR_SEQ_LINEAR) || (addrSeq == C55_AI_ADDR_SEQ_PROPRIETARY)));
    status_t returnCode = STATUS_SUCCESS;        /* return code */
#endif
    uint32_t count;                              /* the loop count for the wait loop */
    uint32_t temp;
    uint32_t tempErrorBit;

    count = FLASH_USER_TEST_WAIT;
    /* There is an in-progress UTest operation */
    if (FLS_FMC.UT0.B.AIE != 0x0U)
    {
        /* In case the previous check is broken, we allow to start a new check */
        if ((FLS_FMC.UT0.B.AIBPE != 0x0U) && (FLS_FMC.UT0.B.NAIBP != 0x0U))
        {
            /* Clear error bits MCR_EER, MCR_RWE, MCR_SBC */
            tempErrorBit = C55_MCR_EER | C55_MCR_RWE | C55_MCR_SBC | C55_MCR_RVE | C55_MCR_RRE | C55_MCR_AEE | C55_MCR_EEE;
            FLS_FMC.MCR.R = tempErrorBit;

            /* Clear bits Array Integrity Break Point */
            FLS_FMC.UT0.B.NAIBP = 0U;
            /* abort to start next operation */
            FLS_FMC.UT0.B.AIE = 0U;

            while ((FLS_FMC.UT0.B.AID == 0x0U) && (count > 0U))
            {
                count--;
            }

            /* Clear UT0_AIS, UT0_UTE */
            FLS_FMC.UT0.B.AIS = 0U;
            FLS_FMC.UT0.B.UTE = 0U;
        }
        else
        {
#if defined(CCFC3008PC) | defined(CCFC3008PCSN) | defined(CCFC3008PT)
                aiMrStatus = STATUS_BUSY;
#else
                returnCode = STATUS_BUSY;
#endif
        }
    }
#if defined(CCFC3008PC) | defined(CCFC3008PCSN) | defined(CCFC3008PT)
    if (STATUS_SUCCESS == aiMrStatus)
    {
        aiMrCtxData.pMisr = &aiMrMisrValue;

         /* get the number of 256K blocks */
        temp = ((FLS_FMC.MCRE.B.n256K) << 1U);

        /* Mask off reserved bits for 256K address space */
        if (temp <= 32U)
        {
            aiMrBlockSelect.second256KBlkSel &= 0U;
        }

        if ((aiMrBlockSelect.lowBlkSel | aiMrBlockSelect.midBlkSel | aiMrBlockSelect.highBlkSel | aiMrBlockSelect.first256KBlkSel | aiMrBlockSelect.second256KBlkSel) == 0x0U)
        {
            /* No blocks to be selected for evaluation */
            aiMrStatus = STATUS_FLASH_ERROR_NO_BLOCK;
        }
        else
        {
#if defined(CCFC3008PC)
        	uint32_t temp = 0U;
#endif
            /* Write password to UT0 register to enable test mode */
            FLS_FMC.UT0.R = C55_USER_TEST_ENABLE_PASSWORD;

            if (FLS_FMC.UT0.B.UTE == 0x0U)
            {
                aiMrStatus = STATUS_FLASH_ERROR_ENABLE;
            }
            else
            {
#if defined(CCFC3008PC)
            	FLS_FMC.SEL0.B.LOWSEL = ((aiMrBlockSelect.lowBlkSel & 0xFU) << 1U) | ((aiMrBlockSelect.lowBlkSel & 0xF0U) << 2U);

#elif defined(CCFC3008PCSN)
                FLS_FMC.SEL0.B.LOWSEL = aiMrBlockSelect.lowBlkSel & FLS_SEL_MASK_LOW0;
                FLS_FMC.SEL1.B.LOWSEL = (aiMrBlockSelect.lowBlkSel >> FLS_LOCK_OFFSET_LOW) & FLS_LOCK_MASK_LOW1;
#else
                /* Set the block selection registers */
                FLS_FMC.SEL0.B.LOWSEL = aiMrBlockSelect.lowBlkSel;
#endif// CCFC3008PC || CCFC3008PCSN

			#if defined(CCFC3008PC)
				*((volatile uint8_t *)(&C55FMC) + 0x1FC) = 0x20;
				*((volatile uint8_t *)(&C55FMC) + 0x1FD) = 0x22;
				*((volatile uint8_t *)(&C55FMC) + 0x1FE) = 0x08;
				*((volatile uint8_t *)(&C55FMC) + 0x1FF) = 0x01;

				temp = aiMrBlockSelect.midBlkSel << FLS_LOCK_OFFSET_MID;
				FLS_FMC.SEL1.R = temp;
			#elif defined(CCFC3008PCSN)
				FLS_FMC.SEL4.B.MIDSEL = aiMrBlockSelect.midBlkSel & FLS_SEL_MASK_MID;
			#else
				FLS_FMC.SEL0.B.MIDSEL = aiMrBlockSelect.midBlkSel << FLS_LOCK_OFFSET_MID;
			#endif // CCFC3008PC || CCFC3008PCSN

			#ifndef CCFC3008PC
			#if defined(CCFC3008PCSN)
				FLS_FMC.SEL0.B.MIDSEL = aiMrBlockSelect.highBlkSel & FLS_SEL_MASK_HIGH0;
				*((volatile uint8_t *)(&C55FMC) + 0x1FC) = 0x20;/* polyspace RTE:IDP */
				*((volatile uint8_t *)(&C55FMC) + 0x1FD) = 0x22;/* polyspace RTE:IDP */
				*((volatile uint8_t *)(&C55FMC) + 0x1FE) = 0x08;/* polyspace RTE:IDP */
				*((volatile uint8_t *)(&C55FMC) + 0x1FF) = 0x01;/* polyspace RTE:IDP */
				FLS_FMC.SEL1.B.MTSEL = (aiMrBlockSelect.highBlkSel >> FLS_LOCK_OFFSET_HIGH) & FLS_LOCK_MASK_HIGH1;
			#else
				FLS_FMC.SEL1.R = aiMrBlockSelect.highBlkSel;
			#endif // CCFC3008PCSN
			#endif // CCFC3008PC
                /* Confirm that the selection mapping relationship of large blocks is not considered */
                FLS_FMC.SEL2.B.A256KSEL = aiMrBlockSelect.first256KBlkSel;
                FLS_FMC.SEL3.B.A256KSEL = aiMrBlockSelect.second256KBlkSel;

                /* The logical sequence is used */
                FLS_FMC.UT0.B.AIS = 1U;

                /* Clear AIBPE bit if no break */
                FLS_FMC.UT0.B.AIBPE = 0U;
                /* Clear SBCE bit if only double bit detection is selected */
                FLS_FMC.UT0.B.SBCE = 0U;

                /* Set the seed values of the MISR in UMx registers */
                FLS_FMC.UM[0].B.MISR = 0U;
                FLS_FMC.UM[1].B.MISR = 0U;
                FLS_FMC.UM[2].B.MISR = 0U;
                FLS_FMC.UM[3].B.MISR = 0U;
                FLS_FMC.UM[4].B.MISR = 0U;
                FLS_FMC.UM[5].B.MISR = 0U;
                FLS_FMC.UM[6].B.MISR = 0U;
                FLS_FMC.UM[7].B.MISR = 0U;
                FLS_FMC.UM[8].B.MISR = 0U;
                FLS_FMC.UM9.B.MISR = 0U;

                /* Initiate the Array Integrity Check by writing 1 to UT0_AIE bit*/
                FLS_FMC.UT0.B.AIE = 1U;
                /* wait until UT0_AID is set */
                saf_timeout_cnt = 0U;
                while(FLS_FMC.UT0.B.AID == 0U)
                {
                    saf_timeout_cnt++;
                    if(saf_timeout_cnt >= SAF_SCH_WAIT_WHILE_OPERATION_TIMEOUT_CNT)
                    {
                        aiMrStatus = STATUS_TIMEOUT;
                        break;
                    }
                }
            }
        }
    }
#else
    if (returnCode == STATUS_SUCCESS)
    {
        pCtxData->pMisr = pMisrValue;

        /* get the number of 256K blocks */
        temp = FLASH_GetNumOf256KBlock();
		#ifndef CCFC3012PT
        if (temp <= 32U)
        {
            blockSelect->second256KBlkSel &= 0U;
        }

        if ((blockSelect->lowBlkSel | blockSelect->midBlkSel | blockSelect->highBlkSel | blockSelect->first256KBlkSel | blockSelect->second256KBlkSel) == 0x0U)
        #else
        (void)temp;

        if ((blockSelect->lowBlkSel | blockSelect->midBlkSel | blockSelect->highBlkSel | blockSelect->large0BlkSel | blockSelect->large1BlkSel | blockSelect->large2BlkSel | blockSelect->large3BlkSel | blockSelect->large4BlkSel | blockSelect->large5BlkSel) == 0x0U)
		#endif
        {
            /* No blocks to be selected for evaluation */
            returnCode = STATUS_FLASH_ERROR_NO_BLOCK;
        }
        else
        {
            count = FLASH_USER_TEST_WAIT;/*PRQA S 2983*/

            /* Write password to UT0 register to enable test mode */
            FLS_FMC.UT0.R = C55_USER_TEST_ENABLE_PASSWORD;

            if (FLS_FMC.UT0.B.UTE == 0x0U)
            {
                returnCode = STATUS_FLASH_ERROR_ENABLE;
            }
            else
            {
                /* Set the block selection registers */
                FLS_FMC.SEL0.B.LOWSEL = blockSelect->lowBlkSel;
                FLS_FMC.SEL0.B.MIDSEL = blockSelect->midBlkSel;
                FLS_FMC.SEL1.B.HIGHSEL = blockSelect->highBlkSel;
                #ifndef CCFC3012PT
                /* Confirm that the selection mapping relationship of large blocks is not considered */
                FLS_FMC.SEL2.B.A256KSEL = blockSelect->first256KBlkSel;
                FLS_FMC.SEL3.B.A256KSEL = blockSelect->second256KBlkSel;
                #else
                #endif
                /* Set the Address sequence to be used */
                if (C55_AI_ADDR_SEQ_LINEAR == addrSeq)
                {
                    /* The logical sequence is used */
                    FLS_FMC.UT0.B.AIS = 1U;
                }
                else
                {
                    /* The proprietary sequence is used */
                    FLS_FMC.UT0.B.AIS = 0U;
                }
                /* Set the breakpoint if need to */
                switch (breakOption)
                {
                    case C55_AI_BREAK_ON_DBD:
                        /* Clear bits MCR_EER, MCR_SBC (notes: write 1 to clear) */
                        FLS_FMC.MCR.B.EER = 1U;
                        FLS_FMC.MCR.B.SBC = 1U;
                        /* Set bit UT0_AIBPE */
                        FLS_FMC.UT0.B.AIBPE = 1U;
                        /* Clear SBCE bit if only double bit detection is selected */
                        FLS_FMC.UT0.B.SBCE = 0U;
                        break;
                    case C55_AI_BREAK_ON_DBD_SBC:
                        /* Clear bits MCR_EER, MCR_SBC (notes: write 1 to clear) */
                        FLS_FMC.MCR.B.EER = 1U;
                        FLS_FMC.MCR.B.SBC = 1U;
                        /* Set bit UT0_AIBPE */
                        FLS_FMC.UT0.B.AIBPE = 1U;
                        /* Set bit UT0_SBCE */
                        FLS_FMC.UT0.B.SBCE = 1U;
                        break;
                    default:
                        /* Clear AIBPE bit if no break */
                        FLS_FMC.UT0.B.AIBPE = 0U;
                        /* Clear SBCE bit if only double bit detection is selected */
                        FLS_FMC.UT0.B.SBCE = 0U;
                        break;
                }

                /* Set the seed values of the MISR in UMx registers */
                FLS_FMC.UM[0].B.MISR = 0U;
                FLS_FMC.UM[1].B.MISR = 0U;
                FLS_FMC.UM[2].B.MISR = 0U;
                FLS_FMC.UM[3].B.MISR = 0U;
                FLS_FMC.UM[4].B.MISR = 0U;
                FLS_FMC.UM[5].B.MISR = 0U;
                FLS_FMC.UM[6].B.MISR = 0U;
                FLS_FMC.UM[7].B.MISR = 0U;
                FLS_FMC.UM[8].B.MISR = 0U;
                FLS_FMC.UM9.B.MISR = 0U;

                /* Initiate the Array Integrity Check by writing 1 to UT0_AIE bit*/
                FLS_FMC.UT0.B.AIE = 1U;
                /* wait until UT0_AID is set */
                saf_timeout_cnt = 0U;
                while(FLS_FMC.UT0.B.AID == 0U)
                {
                    saf_timeout_cnt++;
                    if(saf_timeout_cnt >= SAF_SCH_WAIT_WHILE_OPERATION_TIMEOUT_CNT)
                    {
                        returnCode = STATUS_TIMEOUT;
                        break;
                    }
                }
            }
        }
    }

    return returnCode;
#endif
}

#if defined(CCFC3008PT) | defined(CCFC3008PC) | defined(CCFC3008PCSN)
/**
****************************************************************************************
* @brief:  This function shall be to execute user margin reads of the flash.
* @return      void
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
static void SAF_FLASH_ACMRCheck(void)
{

    uint32_t count;                              /* the loop count for the wait loop */
    uint32_t temp;
    uint32_t tempErrorBit;

    count = FLASH_USER_TEST_WAIT;

    /* There is an in-progress UTest operation */
    if (FLS_FMC.UT0.B.AIE != 0x0U)
    {
        /* In case the previous check is broken, we allow to start a new check */
        if (FLS_FMC.UT0.B.NAIBP != 0x0U)
        {
            /* Clear error bits MCR_EER, MCR_RWE, MCR_SBC */
            tempErrorBit = C55_MCR_EER | C55_MCR_RWE | C55_MCR_SBC | C55_MCR_RVE | C55_MCR_RRE | C55_MCR_AEE | C55_MCR_EEE;
            FLS_FMC.MCR.R = tempErrorBit;
            /* Clear bits Array Integrity Break Point */
            FLS_FMC.UT0.B.NAIBP = 0U;
            /* abort to start next operation */
            FLS_FMC.UT0.B.AIE = 0U;

            while ((FLS_FMC.UT0.B.AID == 0x0U)&& (count > 0U))
            {
                count--;
            }

            /* Clear UT0_AIS, UT0_UTE, UT0_MRE */
            FLS_FMC.UT0.B.AIS = 0U;
            FLS_FMC.UT0.B.UTE = 0U;
            FLS_FMC.UT0.B.MRE = 0U;
        }
        else
        {
            aiMrStatus = STATUS_BUSY;
        }
    }

    if (STATUS_SUCCESS == aiMrStatus)
    {
        aiMrCtxData.pMisr = &aiMrMisrValue;
        /* get the number of 256K blocks */
        temp = ((FLS_FMC.MCRE.B.n256K) << 1U);

        /* Mask off reserved bits for 256K address space */
        if (temp <= 32U)
        {
            aiMrBlockSelect.second256KBlkSel &= 0U;
        }

        if ((aiMrBlockSelect.lowBlkSel | aiMrBlockSelect.midBlkSel | aiMrBlockSelect.highBlkSel |
                aiMrBlockSelect.first256KBlkSel | aiMrBlockSelect.second256KBlkSel) == 0x0U)
        {
            /* No blocks to be selected for evaluation */
            aiMrStatus = STATUS_FLASH_ERROR_NO_BLOCK;
        }
        else
        {
            /* Write password to UT0 register to enable test mode */
            FLS_FMC.UT0.R = C55_USER_TEST_ENABLE_PASSWORD;

            if (FLS_FMC.UT0.B.UTE == 0x0U)
            {
                aiMrStatus = STATUS_FLASH_ERROR_ENABLE;
            }
            else
            {
                /* Set the block selection registers */
#if defined(CCFC3008PC)
            	FLS_FMC.SEL0.B.LOWSEL = ((aiMrBlockSelect.lowBlkSel & 0xFU) << 1U) | ((aiMrBlockSelect.lowBlkSel & 0xF0U) << 2U);

#elif defined(CCFC3008PCSN)
                FLS_FMC.SEL0.B.LOWSEL = aiMrBlockSelect.lowBlkSel & FLS_SEL_MASK_LOW0;
                FLS_FMC.SEL1.B.LOWSEL = (aiMrBlockSelect.lowBlkSel >> FLS_LOCK_OFFSET_LOW) & FLS_LOCK_MASK_LOW1;
#else
                /* Set the block selection registers */
                FLS_FMC.SEL0.B.LOWSEL = aiMrBlockSelect.lowBlkSel;
#endif// CCFC3008PC || CCFC3008PCSN

			#if defined(CCFC3008PC)
				*((volatile uint8_t *)(&C55FMC) + 0x1FC) = 0x20;
				*((volatile uint8_t *)(&C55FMC) + 0x1FD) = 0x22;
				*((volatile uint8_t *)(&C55FMC) + 0x1FE) = 0x08;
				*((volatile uint8_t *)(&C55FMC) + 0x1FF) = 0x01;

				temp = aiMrBlockSelect.midBlkSel << FLS_LOCK_OFFSET_MID;
				FLS_FMC.SEL1.R = temp;
			#elif defined(CCFC3008PCSN)
				FLS_FMC.SEL4.B.MIDSEL = aiMrBlockSelect.midBlkSel & FLS_SEL_MASK_MID;
			#else
				FLS_FMC.SEL0.B.MIDSEL = aiMrBlockSelect.midBlkSel << FLS_LOCK_OFFSET_MID;
			#endif // CCFC3008PC || CCFC3008PCSN

			#ifndef CCFC3008PC
			#if defined(CCFC3008PCSN)
				FLS_FMC.SEL0.B.MIDSEL = aiMrBlockSelect.highBlkSel & FLS_SEL_MASK_HIGH0;
				*((volatile uint8_t *)(&C55FMC) + 0x1FC) = 0x20;/* polyspace RTE:IDP */
				*((volatile uint8_t *)(&C55FMC) + 0x1FD) = 0x22;/* polyspace RTE:IDP */
				*((volatile uint8_t *)(&C55FMC) + 0x1FE) = 0x08;/* polyspace RTE:IDP */
				*((volatile uint8_t *)(&C55FMC) + 0x1FF) = 0x01;/* polyspace RTE:IDP */
				FLS_FMC.SEL1.B.MTSEL = (aiMrBlockSelect.highBlkSel >> FLS_LOCK_OFFSET_HIGH) & FLS_LOCK_MASK_HIGH1;
			#else
				FLS_FMC.SEL1.R = aiMrBlockSelect.highBlkSel;
			#endif // CCFC3008PCSN
			#endif // CCFC3008PC
                /* Confirm that the selection mapping relationship of large blocks is not considered */
                FLS_FMC.SEL2.B.A256KSEL = aiMrBlockSelect.first256KBlkSel;
                FLS_FMC.SEL3.B.A256KSEL = aiMrBlockSelect.second256KBlkSel;

                /* Set the Address sequence to be used: linear sequence */
                FLS_FMC.UT0.B.AIS = 1U;

                /* Set the breakpoint if need to */
                /* Clear AIBPE bit if no break */
                FLS_FMC.UT0.B.AIBPE = 0U;
                /* Clear SBCE bit if only double bit detection is selected */
                FLS_FMC.UT0.B.SBCE = 0U;

                /* Set UT0_MRE to enable User Margin Read */
                FLS_FMC.UT0.B.MRE = 1U;

                /* Set the Margin level to be used */
                /* The programmed level is used */
                FLS_FMC.UT0.B.MRV = (uint8_t)marginLevel;

                /* Set the seed values of the MISR in UMx registers */
                FLS_FMC.UM[0].B.MISR = 0U;
                FLS_FMC.UM[1].B.MISR = 0U;
                FLS_FMC.UM[2].B.MISR = 0U;
                FLS_FMC.UM[3].B.MISR = 0U;
                FLS_FMC.UM[4].B.MISR = 0U;
                FLS_FMC.UM[5].B.MISR = 0U;
                FLS_FMC.UM[6].B.MISR = 0U;
                FLS_FMC.UM[7].B.MISR = 0U;
                FLS_FMC.UM[8].B.MISR = 0U;
                FLS_FMC.UM9.B.MISR = 0U;
                /* Initiate the Array Integrity Check by writing 1 to UT0_AIE bit*/
                FLS_FMC.UT0.B.AIE = 1U;
                /* wait until UT0_AID is set */
                saf_timeout_cnt = 0U;
                while(FLS_FMC.UT0.B.AID == 0U)
                {
                    saf_timeout_cnt++;
                    if(saf_timeout_cnt >= SAF_SCH_WAIT_WHILE_OPERATION_TIMEOUT_CNT)
                    {
                        aiMrStatus = STATUS_TIMEOUT;
                        break;
                    }
                }
            }
        }
    }
}
#else
/**
****************************************************************************************
* @brief:  This function shall be to execute user margin reads of the flash.
* @param[out]  pCtxData         test context data point.
* @param[in]   blockSelect      block selected status point.
* @param[in]   breakOption      break option.
* @param[in]   marginLevel      margin level.
* @param[in]   pMisrValue       MISR value point.
* @return      status_t
*              STATUS_SUCCESS   the operation succeed
*              STATUS_BUSY      the previous run has not ended, and the situation is busy
*              STATUS_TIMEOUT   the operation timed out
*              STATUS_FLASH_ERROR_NO_BLOCK  the value is selected as block
*              STATUS_FLASH_ERROR_ENABLE    failed to enter UTEST mode
****************************************************************************************
*/
SAF_SEC_RAMCODE
static status_t SAF_FLASH_MarginReadCheck
(
    flash_context_data_t * pCtxData,
    fls_blk_sel_t * blockSelect,
    flash_mr_break_option_t breakOption,
    flash_margin_option_t marginLevel,
    flash_misr_t * pMisrValue
)
{
    DEV_ASSERT((bool)(pCtxData != NULL));
    DEV_ASSERT((bool)(pMisrValue != NULL));
    DEV_ASSERT((bool)(blockSelect != NULL));
    DEV_ASSERT((bool) ((marginLevel == C55_MARGIN_LEVEL_ERASE) || (marginLevel == C55_MARGIN_LEVEL_PROGRAM)) );
    status_t returnCode = STATUS_SUCCESS;        /* return code */
    uint32_t count;                              /* the loop count for the wait loop */
    uint32_t temp;
    uint32_t tempErrorBit;

    count = FLASH_USER_TEST_WAIT;

    /* There is an in-progress UTest operation */
    if (FLS_FMC.UT0.B.AIE != 0x0U)
    {
        /* In case the previous check is broken, we allow to start a new check */
        if (FLS_FMC.UT0.B.NAIBP != 0x0U)
        {
            /* Clear error bits MCR_EER, MCR_RWE, MCR_SBC */
            tempErrorBit = C55_MCR_EER | C55_MCR_RWE | C55_MCR_SBC | C55_MCR_RVE | C55_MCR_RRE | C55_MCR_AEE | C55_MCR_EEE;
            FLS_FMC.MCR.R = tempErrorBit;
            /* Clear bits Array Integrity Break Point */
            FLS_FMC.UT0.B.NAIBP = 0U;
            /* abort to start next operation */
            FLS_FMC.UT0.B.AIE = 0U;

            while ((FLS_FMC.UT0.B.AID == 0x0U)&& (count > 0U))
            {
                count--;
            }

            /* Clear UT0_AIS, UT0_UTE, UT0_MRE */
            FLS_FMC.UT0.B.AIS = 0U;
            FLS_FMC.UT0.B.UTE = 0U;
            FLS_FMC.UT0.B.MRE = 0U;
        }
        else
        {
            returnCode = STATUS_BUSY;
        }
    }

    if (returnCode == STATUS_SUCCESS)
    {
        pCtxData->pMisr = pMisrValue;

        /* get the number of 256K blocks */
        temp = FLASH_GetNumOf256KBlock();
		#ifndef CCFC3012PT
        /* Mask off reserved bits for 256K address space */
        if (temp <= 32U)
        {
            blockSelect->second256KBlkSel &= 0U;
        }


        if ((blockSelect->lowBlkSel | blockSelect->midBlkSel | blockSelect->highBlkSel |
                blockSelect->first256KBlkSel | blockSelect->second256KBlkSel) == 0x0U)
		#else
	    (void)temp;

		if ((blockSelect->lowBlkSel | blockSelect->midBlkSel | blockSelect->highBlkSel | blockSelect->large0BlkSel | blockSelect->large1BlkSel | blockSelect->large2BlkSel | blockSelect->large3BlkSel | blockSelect->large4BlkSel | blockSelect->large5BlkSel) == 0x0U)
		#endif
        {
            /* No blocks to be selected for evaluation */
            returnCode = STATUS_FLASH_ERROR_NO_BLOCK;
        }
        else
        {
            /* Write password to UT0 register to enable test mode */
            FLS_FMC.UT0.R = C55_USER_TEST_ENABLE_PASSWORD;

            if (FLS_FMC.UT0.B.UTE == 0x0U)
            {
                returnCode = STATUS_FLASH_ERROR_ENABLE;
            }
            else
            {
                /* Set the block selection registers */
                FLS_FMC.SEL0.B.LOWSEL = blockSelect->lowBlkSel;
                FLS_FMC.SEL0.B.MIDSEL = blockSelect->midBlkSel;
                FLS_FMC.SEL1.B.HIGHSEL = blockSelect->highBlkSel;
				#ifndef CCFC3012PT
                /* Confirm that the selection mapping relationship of large blocks is not considered */
                FLS_FMC.SEL2.B.A256KSEL = blockSelect->first256KBlkSel;
                FLS_FMC.SEL3.B.A256KSEL = blockSelect->second256KBlkSel;
				#else
				#endif
                /* Set the Address sequence to be used: linear sequence */
                FLS_FMC.UT0.B.AIS = 1U;

                /* Set the breakpoint if need to */
                switch (breakOption)
                {
                    case C55_MR_BREAK_ON_DBD:
                        /* Clear bits MCR_EER, MCR_SBC (notes: write 1 to clear) */
                        FLS_FMC.MCR.B.EER = 1U;
                        FLS_FMC.MCR.B.SBC = 1U;
                        /* Set bit UT0_AIBPE */
                        FLS_FMC.UT0.B.AIBPE = 1U;
                        /* Clear SBCE bit if only double bit detection is selected */
                        FLS_FMC.UT0.B.SBCE = 0U;
                        break;
                    case C55_MR_BREAK_ON_DBD_SBC:
                        /* Clear bits MCR_EER, MCR_SBC (notes: write 1 to clear) */
                        FLS_FMC.MCR.B.EER = 1U;
                        FLS_FMC.MCR.B.SBC = 1U;
                        /* Set bit UT0_AIBPE */
                        FLS_FMC.UT0.B.AIBPE = 1U;
                        /* Set bit UT0_SBCE */
                        FLS_FMC.UT0.B.SBCE = 1U;
                        break;
                    default:
                        /* Clear AIBPE bit if no break */
                        FLS_FMC.UT0.B.AIBPE = 0U;
                        /* Clear SBCE bit if only double bit detection is selected */
                        FLS_FMC.UT0.B.SBCE = 0U;
                        break;
                }

                /* Set UT0_MRE to enable User Margin Read */
                FLS_FMC.UT0.B.MRE = 1U;

                /* Set the Margin level to be used */
                if (C55_MARGIN_LEVEL_ERASE == marginLevel)
                {
                    /* The erased level is used */
                    FLS_FMC.UT0.B.MRV = 1U;
                }
                else
                {
                    /* The programmed level is used */
                    FLS_FMC.UT0.B.MRV = 0U;
                }

                /* Set the seed values of the MISR in UMx registers */
                FLS_FMC.UM[0].B.MISR = 0U;
                FLS_FMC.UM[1].B.MISR = 0U;
                FLS_FMC.UM[2].B.MISR = 0U;
                FLS_FMC.UM[3].B.MISR = 0U;
                FLS_FMC.UM[4].B.MISR = 0U;
                FLS_FMC.UM[5].B.MISR = 0U;
                FLS_FMC.UM[6].B.MISR = 0U;
                FLS_FMC.UM[7].B.MISR = 0U;
                FLS_FMC.UM[8].B.MISR = 0U;
                FLS_FMC.UM9.B.MISR = 0U;
                /* Initiate the Array Integrity Check by writing 1 to UT0_AIE bit*/
                FLS_FMC.UT0.B.AIE = 1U;
                /* wait until UT0_AID is set */
                saf_timeout_cnt = 0U;
                while(FLS_FMC.UT0.B.AID == 0U)
                {
                    saf_timeout_cnt++;
                    if(saf_timeout_cnt >= SAF_SCH_WAIT_WHILE_OPERATION_TIMEOUT_CNT)
                    {
                        returnCode = STATUS_TIMEOUT;
                        break;
                    }
                }
            }
        }
    }

    return returnCode;
}
#endif

#if defined(CCFC3008PT) | defined(CCFC3008PC) | defined(CCFC3008PCSN)
/**
****************************************************************************************
* @brief:  This function shall be to execute access code load from flash to ram.
* @param[in]   CalcKind      calculate resource.
* @return      FS_STATUS
*              STATUS_SUCCESS   the operation succeed
*              STATUS_ERROR     the operation failed
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
FS_STATUS SAF_FLASH_ACLoadInit(uint8_t CalcKind)
{
    FS_STATUS ACStatus = FS_STATUS_ERROR;
    uint32_t * RomPtr = NULL_PTR;
    uint32_t * RomEndPtr = NULL_PTR;
    uint32_t * RamPtr = NULL_PTR;
    /* Copy Flash Access Code to SRAM */
#if	defined(CCFC3008PC) | defined(CCFC3008PCSN)
    cc_memset((uint8_t *)SAF_AcCodeAreaAI,0U,(uint32_t)sizeof(SAF_AcCodeAreaAI));
    cc_memset((uint8_t *)SAF_AcCodeAreaMR,0U,(uint32_t)sizeof(SAF_AcCodeAreaMR));
    if(SAF_FLASH_CALC_MISR_BY_AI == CalcKind)
    {
        RomPtr = (uint32_t *)&SAF_FLASH_ACAICheck; /* parasoft-suppress MISRAC2012-RULE_11_1-a "function requirement" */
        RomEndPtr = RomPtr + (sizeof(SAF_AcCodeAreaAI)/4U);
        RamPtr = (uint32_t *)SAF_AcCodeAreaAI;
    }
    else
    {
        RomPtr = (uint32_t *)&SAF_FLASH_ACMRCheck; /* parasoft-suppress MISRAC2012-RULE_11_1-a "function requirement" */
        RomEndPtr = RomPtr + (sizeof(SAF_AcCodeAreaMR)/4U);
        RamPtr = (uint32_t *)SAF_AcCodeAreaMR;
    }


    if(!((NULL_PTR == RomPtr) || (NULL_PTR == RomEndPtr) || (NULL_PTR == RamPtr)))
    {
        for (; (uint32_t)RomPtr < (uint32_t)RomEndPtr; RomPtr++)
        {
            *RamPtr = *RomPtr; /* polyspace RTE:NIV,IDP */
            RamPtr++;
        }

        if(SAF_FLASH_CALC_MISR_BY_AI == CalcKind)
        {
        	SAF_AcCodePtr = (saf_fls_acload_t)&SAF_AcCodeAreaAI; /* parasoft-suppress MISRAC2012-RULE_11_1-a "function requirement" */
        }
        else
        {
        	SAF_AcCodePtr = (saf_fls_acload_t)&SAF_AcCodeAreaMR; /* parasoft-suppress MISRAC2012-RULE_11_1-a "function requirement" */
        }
        ACStatus = FS_STATUS_SUCCESS;
    }
    else
    {
        ACStatus = FS_STATUS_ERROR;
    }
#else
    cc_memset((uint8_t *)SAF_AcCodeArea,0U,(const uint32_t)sizeof(SAF_AcCodeArea));

    /* Copy Flash Access Code to SRAM */
    if(SAF_FLASH_CALC_MISR_BY_AI == CalcKind)
    {
        RomPtr = (uint32_t *)&SAF_FLASH_ACAICheck; /* parasoft-suppress MISRAC2012-RULE_11_1-a "function requirement" */
    }
    else
    {
        RomPtr = (uint32_t *)&SAF_FLASH_ACMRCheck; /* parasoft-suppress MISRAC2012-RULE_11_1-a "function requirement" */
    }

    RomEndPtr = RomPtr + (sizeof(SAF_AcCodeArea)/4U);
    RamPtr = (uint32_t *)SAF_AcCodeArea;

    if(!((NULL_PTR == RomPtr) || (NULL_PTR == RomEndPtr) || (NULL_PTR == RamPtr)))
    {
        for (; (uint32_t)RomPtr < (uint32_t)RomEndPtr; RomPtr++)
        {
            *RamPtr = *RomPtr;
            RamPtr++;
        }

        SAF_AcCodePtr = (saf_fls_acload_t)&SAF_AcCodeArea; /* parasoft-suppress MISRAC2012-RULE_11_1-a "function requirement" */
        ACStatus = FS_STATUS_SUCCESS;
    }
    else
    {
        ACStatus = FS_STATUS_ERROR;
    }
#endif
    return ACStatus;
}
/**
****************************************************************************************
* @brief:  This function shall be to calculate flash block MISR value.
* @param[out]  pMisr         MISR value stored buffer.
* @param[in]   pBlockSelect  block selected status point.
* @return      FS_STATUS
*              FS_STATUS_SUCCESS   calculate succeed
*              FS_STATUS_ERROR     calculate failed
*              FS_STATUS_TIMEOUT   calculate timed out
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
static FS_STATUS SAF_FLASH_CalcBlockMisrValue
(
    flash_misr_t pMisr[],
    const fls_blk_sel_t *pBlockSelect
)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    status_t sdkStatus = STATUS_SUCCESS;
    flash_state_t opResult;
    uint8_t blockType;
    uint8_t pBlockCountList[] = SAF_FLASH_BLOCK_COUNT_LIST;
    uint8_t i, blockID;
    uint8_t misrIndex = 0;
    bool timeout = true;

    for (blockType = (uint8_t)SAF_FLASH_LOW_BLOCK; blockType < (uint8_t)SAF_FLASH_BLOCK_TYPE_COUNT; blockType++)
    {
        for(blockID = 0; blockID < pBlockCountList[blockType]; blockID++)
        {
            if (SAF_FLASH_AccessBlockIsSelected((SAF_FLASH_BLOCK_TYPE)blockType, blockID, pBlockSelect))
            {
                (void)memset(&aiMrBlockSelect, 0, sizeof(aiMrBlockSelect));
                (void)SAF_FLASH_AccessSetFlashArrayBlock((SAF_FLASH_BLOCK_TYPE)blockType, blockID, &aiMrBlockSelect);

                /* calc MISR and store */
                SAF_AcCodePtr();  /* polyspace RTE:COR */

                if (STATUS_SUCCESS == aiMrStatus)
                {
                	sdkStatus = SAF_FLASH_AccessCheckUserTestStatus(&aiMrCtxData, &opResult);
                    SAF_TIMER_TIMEOUT_FUNC(sdkStatus != STATUS_FLASH_INPROGRESS,
                                     SAF_FLASH_CALC_SINGLE_BLOCK_MISR_TIMEOUT_MS,
                                     timeout);

                    if (timeout)
                    {
                        return status = FS_STATUS_TIMEOUT;
                    }
                    else
                    {
                        for (i = 0; i < SAF_FLASH_MISR_REGISTER_COUNT; i++ )
                        {
                            pMisr[misrIndex].arrMISRValue[i] = SAF_FLASH_AccessGetMisrRegValue(i); /* polyspace RTE:IDP */
                        }
                    }
                }
                else if (STATUS_TIMEOUT == aiMrStatus)
                {
                    return status = FS_STATUS_TIMEOUT;
                }
                else
                {
                    return status = FS_STATUS_ERROR;
                }

            }
            misrIndex++;
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function shall be to calculate and compare flash block MISR value.
* @param[in]   pExpectedMisr   expected MISR value stored buffer.
* @param[in]   pBlockSelect    block selected status point.
* @param[out]  pCompareResult  compare result stored buffer.
* @param[in]   CalcKind        calculate resource.
* @return      FS_STATUS
*              FS_STATUS_SUCCESS   calculate and compare succeed
*              FS_STATUS_ERROR     calculate and compare failed
*              FS_STATUS_TIMEOUT   calculate and compare timed out
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
static FS_STATUS SAF_FLASH_CalcAndCompareBlockMisr
(
    flash_misr_t pExpectedMisr[],
    const fls_blk_sel_t *pBlockSelect,
    fls_blk_sel_t *pCompareResult
)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    status_t sdkStatus = STATUS_SUCCESS;
    flash_state_t opResult;
    uint8_t blockType;
    uint8_t pBlockCountList[] = SAF_FLASH_BLOCK_COUNT_LIST;
    uint8_t blockID, misrIndex = 0;
    bool timeout = false;

    for (blockType = (uint8_t)SAF_FLASH_LOW_BLOCK; blockType < (uint8_t)SAF_FLASH_BLOCK_TYPE_COUNT; blockType++)
    {
        for(blockID = 0; blockID < pBlockCountList[blockType]; blockID++)
        {
            if (SAF_FLASH_AccessBlockIsSelected((SAF_FLASH_BLOCK_TYPE)blockType, blockID, pBlockSelect))
            {
                (void)memset(&aiMrBlockSelect, 0, sizeof(aiMrBlockSelect));
                (void)SAF_FLASH_AccessSetFlashArrayBlock((SAF_FLASH_BLOCK_TYPE)blockType, blockID, &aiMrBlockSelect);

                aiMrMisrValue = pExpectedMisr[misrIndex]; /* polyspace RTE:NIV,IDP */

                /* calc MISR and store */
                SAF_AcCodePtr(); /* polyspace RTE:COR */

                if (STATUS_SUCCESS == aiMrStatus)
                {
                    SAF_TIMER_TIMEOUT_FUNC(STATUS_FLASH_INPROGRESS != (sdkStatus = SAF_FLASH_AccessCheckUserTestStatus(&aiMrCtxData, &opResult)),
                                     SAF_FLASH_CALC_SINGLE_BLOCK_MISR_TIMEOUT_MS,
                                     timeout);
                    if (timeout)
                    {
                        status = FS_STATUS_TIMEOUT;
                    }
                }
                else if (STATUS_TIMEOUT == aiMrStatus)
                {
                    return status = FS_STATUS_TIMEOUT;
                }
                else
                {
                    return status = FS_STATUS_ERROR;
                }

                if (STATUS_SUCCESS == sdkStatus)
                {
                    (void)SAF_FLASH_AccessSetFlashArrayBlock((SAF_FLASH_BLOCK_TYPE)blockType, blockID, pCompareResult);
                }
                else
                {
                    return status = FS_STATUS_ERROR;
                }
            }
            misrIndex++;
        }
    }

    return status;
}
#else
/**
****************************************************************************************
* @brief:  This function shall be to calculate flash block MISR value.
* @param[out]  pMisr         MISR value stored buffer.
* @param[in]   pBlockSelect  block selected status point.
* @param[in]   CalcKind      calculate resource.
* @return      FS_STATUS
*              FS_STATUS_SUCCESS   calculate succeed
*              FS_STATUS_ERROR     calculate failed
*              FS_STATUS_TIMEOUT   calculate timed out
****************************************************************************************
*/
SAF_SEC_RAMCODE
static FS_STATUS SAF_FLASH_CalcBlockMisrValue
(
    flash_misr_t pMisr[],
    const fls_blk_sel_t *pBlockSelect,
	flash_margin_option_t mrLevel,
    uint8_t CalcKind
)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    status_t ret = STATUS_SUCCESS;
    status_t sdkStatus = STATUS_SUCCESS;
    fls_blk_sel_t blockSelect;
    flash_context_data_t ctxData;
    flash_misr_t misrValue;
    flash_state_t opResult;
    SAF_FLASH_BLOCK_TYPE blockType;
    uint8_t pBlockCountList[] = SAF_FLASH_BLOCK_COUNT_LIST;
    uint8_t i, blockID;
    uint8_t misrIndex = 0;
    bool timeout = (bool)true;

    for (blockType = SAF_FLASH_LOW_BLOCK; blockType < SAF_FLASH_BLOCK_TYPE_COUNT; blockType++)/*PRQA S 4527*/
    {
        for(blockID = 0; blockID < pBlockCountList[blockType]; blockID++)
        {
            if (SAF_FLASH_AccessBlockIsSelected(blockType, blockID, pBlockSelect))
            {
                memset(&blockSelect, 0, sizeof(blockSelect));/*PRQA S 0315,3200*/
                SAF_FLASH_AccessSetFlashArrayBlock(blockType, blockID, &blockSelect);/*PRQA S 3200*/

                /* calc MISR and store */
                if(SAF_FLASH_CALC_MISR_BY_AI == CalcKind)
                {
                    ret = SAF_FLASH_ArrayIntegrityCheck(&ctxData, &blockSelect, C55_AI_BREAK_NONE, C55_AI_ADDR_SEQ_LINEAR, &misrValue);
                    (void)mrLevel;
                }
                else
                {
                    ret = SAF_FLASH_MarginReadCheck(&ctxData, &blockSelect, C55_MR_BREAK_NONE, mrLevel, &misrValue);
                }

                if (STATUS_SUCCESS == ret)
                {
                	sdkStatus = SAF_FLASH_AccessCheckUserTestStatus(&ctxData, &opResult); /*PRQA S 4404,3393,2976,2983,1840,1842,3326,3401*/
                    SAF_TIMER_TIMEOUT_FUNC(sdkStatus != STATUS_FLASH_INPROGRESS,
                                     SAF_FLASH_CALC_SINGLE_BLOCK_MISR_TIMEOUT_MS,/*PRQA S 3432*/
                                     timeout);/*PRQA S 3432*/

                    if (timeout)
                    {
                        return status = FS_STATUS_TIMEOUT;/*PRQA S 3226,2983*/
                    }
                    else
                    {
                        for (i = 0; i < SAF_FLASH_MISR_REGISTER_COUNT; i++ )
                        {
                            pMisr[misrIndex].arrMISRValue[i] = SAF_FLASH_AccessGetMisrRegValue(i);/* polyspace RTE:IDP */
                        }
                    }
                }
                else if (STATUS_TIMEOUT == ret)
                {
                    return status = FS_STATUS_TIMEOUT;/*PRQA S 2983,3226*/
                }
                else
                {
                    return status = FS_STATUS_ERROR;/*PRQA S 3226,2983*/
                }

            }
            misrIndex++;
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function shall be to calculate and compare flash block MISR value.
* @param[in]   pExpectedMisr   expected MISR value stored buffer.
* @param[in]   pBlockSelect    block selected status point.
* @param[out]  pCompareResult  compare result stored buffer.
* @param[in]   CalcKind        calculate resource.
* @return      FS_STATUS
*              FS_STATUS_SUCCESS   calculate and compare succeed
*              FS_STATUS_ERROR     calculate and compare failed
*              FS_STATUS_TIMEOUT   calculate and compare timed out
****************************************************************************************
*/
SAF_SEC_RAMCODE
static FS_STATUS SAF_FLASH_CalcAndCompareBlockMisr
(
    flash_misr_t pExpectedMisr[],
    const fls_blk_sel_t *pBlockSelect,
    fls_blk_sel_t *pCompareResult,
	flash_margin_option_t mrLevel,
    uint8_t CalcKind
)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    status_t ret, sdkStatus = STATUS_SUCCESS;
    fls_blk_sel_t blockSelect;
    flash_context_data_t ctxData;
    flash_state_t opResult;
    SAF_FLASH_BLOCK_TYPE blockType;
    uint8_t pBlockCountList[] = SAF_FLASH_BLOCK_COUNT_LIST;
    uint8_t blockID, misrIndex = 0;
    bool timeout = (unsigned int)false;/*PRQA S 1259,4464*/

    for (blockType = SAF_FLASH_LOW_BLOCK; blockType < SAF_FLASH_BLOCK_TYPE_COUNT; blockType++)/*PRQA S 4527*/
    {
        for(blockID = 0; blockID < pBlockCountList[blockType]; blockID++)
        {
            if (SAF_FLASH_AccessBlockIsSelected(blockType, blockID, pBlockSelect))
            {
                memset(&blockSelect, 0, sizeof(blockSelect));/*PRQA S 3200,0315*/
                SAF_FLASH_AccessSetFlashArrayBlock(blockType, blockID, &blockSelect);/*PRQA S 3200*/

                /* calc MISR and store */
                if(SAF_FLASH_CALC_MISR_BY_AI == CalcKind)
                {
                    ret = SAF_FLASH_ArrayIntegrityCheck(&ctxData, &blockSelect, C55_AI_BREAK_NONE, C55_AI_ADDR_SEQ_LINEAR, &pExpectedMisr[misrIndex]);
                    (void)mrLevel;
                }
                else
                {
                    ret = SAF_FLASH_MarginReadCheck(&ctxData, &blockSelect, C55_MR_BREAK_NONE, mrLevel, &pExpectedMisr[misrIndex]);
                }
                if (STATUS_SUCCESS == ret)
                {

                    SAF_TIMER_TIMEOUT_FUNC(STATUS_FLASH_INPROGRESS != (sdkStatus = SAF_FLASH_AccessCheckUserTestStatus(&ctxData, &opResult)),/*PRQA S 4404,1840,1842,2976,3401,3393,3326*/
                                     SAF_FLASH_CALC_SINGLE_BLOCK_MISR_TIMEOUT_MS,/*PRQA S 3432*/
                                     timeout);/*PRQA S 3432*/
                    if (timeout)
                    {
                        status = FS_STATUS_TIMEOUT;
                    }
                }
                else if (STATUS_TIMEOUT == ret)
                {
                    return status = FS_STATUS_TIMEOUT;/*PRQA S 2983,3226*/
                }
                else
                {
                    return status = FS_STATUS_ERROR;/*PRQA S 2983,3226*/
                }

                if (STATUS_SUCCESS == sdkStatus)
                {
                    SAF_FLASH_AccessSetFlashArrayBlock(blockType, blockID, pCompareResult);/*PRQA S 3200*/
                }
                else
                {
                    return status = FS_STATUS_ERROR;/*PRQA S 2983,3226*/
                }
            }
            misrIndex++;
        }
    }

    return status;
}
#endif

/**
****************************************************************************************
* @brief This function shall be used to verify permanent multibit errors.
* @param[in] sbcInfoPre :The first read FLASH ECC error info.
* @param[in] sbcInfoCurr :The second read FLASH ECC error info.
* @param[out] addrBuff :Addresses that might have permanent multibit errors, the buffer size should bigger than SAF_MEM_ERROR_INFO_NUM.
* @return FS_STATUS
*         FS_STATUS_SUCCESS :Verify permanent multibit errors is normal.
*         FS_STATUS_ERROR :Verify permanent multibit errors is abnormal.
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
static FS_STATUS SAF_FLASH_AccessFlashSbcReadCheck( saf_mem_err_detect_info_t* sbcInfoPre, saf_mem_err_detect_info_t* sbcInfoCurr, uint32_t* addrBuff )
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint32_t errIndexPre = 0U;
    uint32_t errIndexCurr = 0U;
    bool errAddrFound = false;
    uint32_t permanentErrCount = SAF_FLASH_ECC_ERR_NONE;

    for (errIndexPre = 0U; errIndexPre < sbcInfoPre->errCount; errIndexPre++)
    {
        if (SAF_MEM_FLASH == sbcInfoPre->errMemType[errIndexPre] \
            && SAF_MEM_CE_BIT_ERR == sbcInfoPre->errType[errIndexPre])
        {
            for (errIndexCurr = 0U; errIndexCurr < sbcInfoCurr->errCount; errIndexCurr++)
            {
                if (sbcInfoPre->errAddr[errIndexPre] == sbcInfoCurr->errAddr[errIndexCurr])
                {
                    if(SAF_MEM_CE_BIT_ERR != sbcInfoCurr->errType[errIndexCurr])
                    {
                        addrBuff[permanentErrCount++] = sbcInfoPre->errAddr[errIndexPre];
                    }

                    errAddrFound = true;
                }
            }

            if (false == errAddrFound)
            {
                addrBuff[permanentErrCount++] = sbcInfoPre->errAddr[errIndexPre];
            }

            errAddrFound = false;
        }
    }

    if (SAF_FLASH_ECC_ERR_NONE < permanentErrCount)
    {
        status = FS_STATUS_ERROR;
    }

    return status;
}

/**
****************************************************************************************
 * @brief: Global Function
****************************************************************************************
*/


/**
****************************************************************************************
* @brief:  This function is used to time delay.
* @param[in]    periodUs    expect delay time.
* @return  void
****************************************************************************************
*/
#if defined(CCFC3008PT) | defined(CCFC3008PC) | defined(CCFC3008PCSN)
SAF_FLASH_SEC_CODE
#else
SAF_SEC_RAMCODE
#endif
void SAF_TIMER_DelayUs_FUNC(uint32_t periodUs)
{
    uint32_t count = 0U;
    while(count <= periodUs)
    {
        count++;
    }
}

/**
****************************************************************************************
* @brief:  This function is used to copy test code from flash to ram.
* @return  void
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
void SAF_FLASH_CopyCodeRam(void)
{
#if defined(CCFC3007PT) | defined(CCFC3007BC) | defined(CCFC3012PT)
    uint8_t * code_rom, * code_rom_end ,* code_ram;
#if defined(CCFC3007PT)
    code_ram        = (uint8_t *)0x400e6000;//400e6000
    code_rom_end    = (uint8_t *)0x01402000;//01400db0
    code_rom        = (uint8_t *)0x01400000;//01400000
#elif defined(CCFC3007BC)
    code_ram        = (uint8_t *)0x400e2000;//400e6000
    code_rom_end    = (uint8_t *)0x01302000;//01400db0
    code_rom        = (uint8_t *)0x01300000;//01400000
#elif defined(CCFC3012PT)
    code_ram        = (uint8_t *)0x400be000;//400be000
    code_rom_end    = (uint8_t *)0x01402000;//01400db0
    code_rom        = (uint8_t *)0x01400000;//01400000
#else
#endif
    /* Copy functions from ROM to RAM */
    while (code_rom_end != code_rom)/*PRQA S 2871,2990*/ /* polyspace RTE:NTL */
    {
        *code_ram = *code_rom;/*PRQA S 2841*/ /* polyspace RTE:IDP,NIV */
        code_ram++;/*PRQA S 2931,0498*/
        code_rom++;/*PRQA S 2931,0498*/
    }
#endif
}

/**
****************************************************************************************
* @brief:  This function is used to clean used ram code.
* @return  void
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
void SAF_FLASH_ClearCodeRam(void)
{
#if defined(CCFC3007PT) | defined(CCFC3007BC) | defined(CCFC3012PT)
    uint8_t * code_rom, * code_rom_end ,* code_ram;;
#if defined(CCFC3007PT)
    code_ram        = (uint8_t *)0x400e6000;//400e6000
    code_rom_end    = (uint8_t *)0x01402000;//01400db0
    code_rom        = (uint8_t *)0x01400000;//01400000
#elif defined(CCFC3007BC)
    code_ram        = (uint8_t *)0x400e2000;//400e6000
    code_rom_end    = (uint8_t *)0x01302000;//01400db0
    code_rom        = (uint8_t *)0x01300000;//01400000
#elif defined(CCFC3012PT)
    code_ram        = (uint8_t *)0x400be000;//400be000
    code_rom_end    = (uint8_t *)0x01402000;//01400db0
    code_rom        = (uint8_t *)0x01400000;//01400000
#else
#endif
    /* Copy functions from ROM to RAM */
    while (code_rom_end != code_rom)/*PRQA S 2871,2990*/ /* polyspace RTE:NTL */
    {
        *code_ram = 0;/*PRQA S 2841*/ /* polyspace RTE:IDP */
        code_ram++;/*PRQA S 2931,0498*/
        code_rom++;/*PRQA S 2931,0498*/
    }
#endif
}

/**
****************************************************************************************
* @brief:  This function shall be to set the flash block unlock/lock.
* @param[in]   lockedBlkSel      block selection.
* @param[in]   lockedBlkStatus   block locked status.
* @return      FS_STATUS
*              STATUS_SUCCESS   set succeed
*              STATUS_ERROR     set failed
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
FS_STATUS SAF_FLASH_SetLock(uint8_t lockedBlkSel, uint32_t lockedBlkStatus)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    if (STATUS_SUCCESS != SAF_FLASH_LLD_SetLock(lockedBlkSel, lockedBlkStatus))
    {
        status = FS_STATUS_ERROR;
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function shall be to get the flash block unlock/lock message.
* @param[in]   lockedBlkSel      block selection.
* @param[out]  lockedBlkStatus   block locked status point.
* @return      FS_STATUS
*              STATUS_SUCCESS    get succeed
*              STATUS_ERROR      get failed
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
FS_STATUS SAF_FLASH_GetLock(uint8_t lockedBlkSel, uint32_t * lockedBlkStatus)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    if (STATUS_SUCCESS != SAF_FLASH_LLD_GetLock(lockedBlkSel, lockedBlkStatus))
    {
        status = FS_STATUS_ERROR;
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function shall be to unlock/lock the flash block by the assign address.
* @param[in]   addr      assign address.
* @param[in]   lock      block locked status.
* @return      FS_STATUS
*              STATUS_SUCCESS    unlock/lock succeed
*              STATUS_ERROR      unlock/lock failed
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
FS_STATUS SAF_FLASH_LockBlockByAddr(const uint32_t addr, const bool lock)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_flash_info_t safflashInfo;
    uint32_t lockedBlockState = 0;
    uint32_t value = 0x0U;

    status = SAF_FLASH_AccessGetFlashInfoByAddr(addr, &safflashInfo);

    if (FS_STATUS_SUCCESS == status)
    {
        if (true == safflashInfo.isUtestBlock)
        {
            if (true == lock)
            {
                lockedBlockState = SAF_FLASH_BLOCK_STATE_LOCK;
            }
            else
            {
                lockedBlockState = SAF_FLASH_BLOCK_STATE_UNLOCK;
            }

            value = lockedBlockState;
            FLS_FMC.LOCK0.B.TSLOCK = C55FMC_UTEST_BLOCK_UNLCOK;
            FLS_FMC.LOCK0.B.TSLOCK = (uint8_t)value;

            status = SAF_ReadBackCompare(FLS_FMC.LOCK0.R, C55FMC_LOCK_TSLOCK(value), C55FMC_LOCK_TSLOCK_MASK);/*PRQA S 2985*/
        }
        else
        {
            if (FS_STATUS_SUCCESS != SAF_FLASH_GetLock((uint8_t)safflashInfo.blockType, &lockedBlockState))
            {
                status = FS_STATUS_ERROR;
            }
            else
            {
                if(SAF_FLASH_MAX_BLOCK_SELECTED > safflashInfo.blockID)
                {
                    if (true == lock)
                    {
                        lockedBlockState |= (SAF_FLASH_BLOCK_STATE_LOCK << safflashInfo.blockID);
                    }
                    else
                    {
                        lockedBlockState &= ~(SAF_FLASH_BLOCK_STATE_LOCK << safflashInfo.blockID);
                    }

                    status = SAF_FLASH_SetLock((uint8_t)safflashInfo.blockType, lockedBlockState);
                }
            }
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief This function shall be used to trigger flash ECC error.
* @param[in] type :ECC error type.
* @return FS_STATUS
*         FS_STATUS_SUCCESS :Trigger succeed.
*         FS_STATUS_ERROR :Trigger failed.
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
FS_STATUS SAF_FLASH_TriggerBitError(const SAF_MEM_ERR_TYPE type)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    volatile uint32_t* singlebitErrorTriggerAddr = NULL;
    volatile uint32_t* mulitibitErrorTriggerAddr = NULL;
    volatile uint32_t testReadCE = 0;
    volatile uint32_t testReadUCE = 0;
    uint8_t timeout = 0xff;

    if (SAF_MEM_CE_BIT_ERR == type)
    {
        SAF_FLASH_AccessEnableCEReport();

        singlebitErrorTriggerAddr = (volatile uint32_t*)s_flashCeTriggerAddr;
        s_flashCETestAddress = (uint32_t)singlebitErrorTriggerAddr;
        do
        {
        	testReadCE = *singlebitErrorTriggerAddr;/* polyspace RTE:NIV,IDP */
        	testReadCE = *singlebitErrorTriggerAddr;/* polyspace RTE:NIV,IDP */
        	testReadCE = *singlebitErrorTriggerAddr;/* polyspace RTE:NIV,IDP */
        	(void)testReadCE;
        	(void)testReadCE;
        	(void)testReadCE;
        	timeout--;
        }while ((MEMU.FLASH_CERR[0].ADDR.R == (uint32_t)0) && (timeout != (uint8_t)0));

        if (timeout == (uint8_t)0)
        {
        	status = FS_STATUS_TIMEOUT;
        }
    }
    else if (SAF_MEM_UCE_BIT_ERR == type)
    {
    	mulitibitErrorTriggerAddr = (volatile uint32_t*)s_flashUceTriggerAddr;
        s_flashUCETestAddress = (uint32_t)mulitibitErrorTriggerAddr;
        do
        {
        	testReadUCE = *mulitibitErrorTriggerAddr;/* polyspace RTE:NIV,IDP */
        	testReadUCE = *mulitibitErrorTriggerAddr;/* polyspace RTE:NIV,IDP */
        	testReadUCE = *mulitibitErrorTriggerAddr;/* polyspace RTE:NIV,IDP */
        	(void)testReadUCE;
        	(void)testReadUCE;
        	(void)testReadUCE;
        	timeout--;
        } while ((MEMU.FLASH_UNCERR_ADDR.R == (uint32_t)0) && (timeout != (uint8_t)0));

        if ((timeout == (uint8_t)0) && (MEMU.SYS_RAM_UNCERR_ADDR.R == (uint32_t)0))
        {
        	status = FS_STATUS_TIMEOUT;
        }
    }
    else
    {
        status = FS_STATUS_ERROR;
    }

    (void)s_flashCETestAddress;
    (void)s_flashUCETestAddress;

    return status;
}

/**
****************************************************************************************
* @brief:  This function shall be used to get flash ECC error report path test result.
* @param[out]   pTestResult   ECC error report path test result.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     get result succeed
*               FS_STATUS_ERROR       get result failed
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
FS_STATUS SAF_FLASH_EccReportPathTestResult(saf_flash_ecc_report_path_test_result_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (NULL != pTestResult)
    {
        status = FS_STATUS_SUCCESS;
        memcpy(pTestResult, &s_flashEccReportPathTest.output, sizeof(s_flashEccReportPathTest.output));/*PRQA S 3200*/
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function shall be used to execute lossless injection flash ECC error report path test.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     flash ECC error report path test succeed
*               FS_STATUS_ERROR       flash ECC error report path test failed
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
FS_STATUS SAF_FLASH_EccReportPathTest(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    FS_STATUS singleStatus = FS_STATUS_SUCCESS, mulitiStatus = FS_STATUS_SUCCESS;
    FS_STATUS switchStatus = FS_STATUS_SUCCESS;
    FS_STATUS flashFccuStatus = FS_STATUS_SUCCESS;
    SAF_MEM_ERR_TYPE memErrorType;
    uint32_t switchOn = 1;
    uint32_t switchOff = 0;
    const saf_flash_ecc_report_path_test_param_t *pParam  = &s_flashEccConfigSet;
    saf_flash_ecc_report_path_test_result_t *pResult = &s_flashEccReportPathTest.output;

    SAF_FCCU_CopyUninitChannelConfig(&fccuFlashEccStartUpCfg, realFlashEccFccuRfCfg, fccFlashEccStartUpRfCfg, MEMU_FLS_CE, 3);

    /* check fccu status */
    if (fccuFlashEccStartUpCfg.rfConfigNumber > 0)
    {
    	SAF_FCCU_ClearAllChannelFault();
    	flashFccuStatus = SAF_FCCU_HardwareInit(&fccuFlashEccStartUpCfg, realFlashEccFccuRfCfg);
    }

    if (FS_STATUS_SUCCESS != (FS_STATUS)SAF_FCCU_LLD_StartupCallbackSwitch(switchOn))/*PRQA S 4322*/
    {
    	switchStatus = FS_STATUS_ERROR;
    }

	SAF_MEM_ErrorReportInit(SAF_MEM_FLASH);

	SAF_FLASH_LLD_SafOperationInit();

	if (SAF_FLASH_ECC_BIT_ERROR_TYPE_INVALID_VALUE != pParam->singleBitSelect)
	{
		pResult->singleBitPassed = SAF_FLASH_ECC_BIT_ERROR_TYPE_INVALID_VALUE;

		(void)MEMU_LLD_SetUpCallback(MEMU_FLASH_DETECT,
							   MEMU_CORRECTABLE_ERROR_DETECT,
							   &SAF_FLASH_CECallback);

		singleStatus = SAF_FLASH_TriggerBitError(SAF_MEM_CE_BIT_ERR);
		if (singleStatus == FS_STATUS_SUCCESS)
		{
			/* 1. check error report module */
			singleStatus = SAF_MEM_GetEccErrorResult(SAF_MEM_FLASH, SAF_FLASH_ECC_CE_TRIGGER_ADDRESS, &memErrorType);

			if (FS_STATUS_SUCCESS == singleStatus)
			{
				if (SAF_MEM_CE_BIT_ERR == memErrorType)
				{
					pResult->singleBitPassed = (unsigned int)true;
				}
				else
				{
					singleStatus = FS_STATUS_FLASH_ECC_REPROT_TEST_FAILED;
				}

				/* 2. check FCCU path */
				if (FS_STATUS_SUCCESS == singleStatus)
				{
					if (s_flashCETestAddressList[0] != SAF_FLASH_ECC_CE_TRIGGER_ADDRESS)
					{
						singleStatus = FS_STATUS_ERROR;
					}
				}
			}
		}
	}

	if (SAF_FLASH_ECC_BIT_ERROR_TYPE_INVALID_VALUE != pParam->multiBitSelect)
	{
		pResult->multiBitPassed = SAF_FLASH_ECC_BIT_ERROR_TYPE_INVALID_VALUE;

		(void)MEMU_LLD_SetUpCallback(MEMU_FLASH_DETECT,
							   MEMU_UNCORRECTABLE_ERROR_DETECT,
							   &SAF_FLASH_UCECallback);

		if (FS_STATUS_SUCCESS == mulitiStatus)
		{
			mulitiStatus = SAF_FLASH_TriggerBitError(SAF_MEM_UCE_BIT_ERR);
			if (mulitiStatus == FS_STATUS_SUCCESS)
			{
				/* check error report module */
				mulitiStatus = SAF_MEM_GetEccErrorResult(SAF_MEM_FLASH, SAF_FLASH_ECC_UCE_TRIGGER_ADDRESS, &memErrorType);

				if (FS_STATUS_SUCCESS == mulitiStatus)
				{
					if (SAF_MEM_UCE_BIT_ERR == memErrorType)
					{
						pResult->multiBitPassed = (unsigned int)true;
					}
					else
					{
						mulitiStatus = FS_STATUS_FLASH_ECC_REPROT_TEST_FAILED;
					}

					/* 2. check FCCU path */
					if (FS_STATUS_SUCCESS == mulitiStatus)
					{
						if (s_flashUCETestAddressList != SAF_FLASH_ECC_UCE_TRIGGER_ADDRESS)
						{
							mulitiStatus = FS_STATUS_ERROR;
						}
					}
#if defined(CCFC3008PC) | defined(CCFC3007BC)
				    if (memErrorType == SAF_MEM_NONE_BIT_ERR)
				    {
				        mulitiStatus = SAF_MEM_GetEccErrorResult(SAF_MEM_SRAM, SAF_FLASH_ECC_UCE_TRIGGER_ADDRESS, &memErrorType);
						if (SAF_MEM_UCE_BIT_ERR == memErrorType)
						{
							pResult->multiBitPassed = (unsigned int)true;
							mulitiStatus = FS_STATUS_SUCCESS;
						}
						else
						{
							mulitiStatus = FS_STATUS_FLASH_ECC_REPROT_TEST_FAILED;
						}
				    }
				    else
				    {
			    	    /* do nothing for satisfy the misra 2012*/
				    }
#endif
				}
			}
		}
	}

	if (FS_STATUS_SUCCESS == status)
	{
		if ((mulitiStatus == FS_STATUS_SUCCESS) && (singleStatus == FS_STATUS_SUCCESS))
		{
			status =  FS_STATUS_SUCCESS;
		}
		else
		{
			if (singleStatus != FS_STATUS_SUCCESS)
			{
				pResult->singleBitPassed = (unsigned int)false;
			}

			if (mulitiStatus != FS_STATUS_SUCCESS)
			{
				pResult->multiBitPassed = (unsigned int)false;
			}
			status = FS_STATUS_FLASH_ECC_REPROT_TEST_FAILED;
		}
	}

    if (FS_STATUS_SUCCESS != (FS_STATUS)SAF_FCCU_LLD_StartupCallbackSwitch(switchOff))/*PRQA S 4322*/
    {
    	switchStatus = FS_STATUS_ERROR;
    }
    (void)MEMU_LLD_Reset();
    if ((switchStatus == FS_STATUS_ERROR) || (flashFccuStatus == FS_STATUS_ERROR))
    {
    	status = FS_STATUS_ERROR;
    }

    return status;
}


/**
****************************************************************************************
* @brief:  This function shall be used to read of a number of patterns after an ECC correction occurs.
* @param[out]   errInfo   error message buffer after multiple read operations.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     multiple read operations normal
*               FS_STATUS_ERROR       multiple read operations abnormal
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
FS_STATUS SAF_FLASH_SBCReadCheck(uint32_t* addrBuff)
{
    FS_STATUS status = FS_STATUS_ERROR;
    saf_mem_err_detect_info_t sbcInfoPre = { { SAF_MEM_CE_BIT_ERR }, { SAF_MEM_SRAM }, { 0U }, SAF_FLASH_ECC_ERR_NONE };
    saf_mem_err_detect_info_t sbcInfoCurr = { { SAF_MEM_CE_BIT_ERR }, { SAF_MEM_SRAM }, { 0U }, SAF_FLASH_ECC_ERR_NONE };
    uint32_t errIndexPre = 0U;
    uint32_t errAddr = 0U;
    uint32_t data = 0U;

    if(NULL != addrBuff)
    {
        if (C55FMC_SINGLE_BIT_CORRECTION_EVENT_OCCURRED == FLS_FMC.MCR.B.SBC)
        {
            (void)memset((uint8_t *)&sbcInfoPre, 0, sizeof(saf_mem_err_detect_info_t));
            (void)SAF_MEMU_DetectAllErr(SAF_MEM_FLASH, &sbcInfoPre);
            SAF_MEMU_CleanAllErr(SAF_MEM_FLASH);

            /* Clear error bit. */
            FLS_FMC.MCR.B.EER = C55FMC_ECC_EVENT_ERROR_CLEAR;
            FLS_FMC.MCR.B.SBC = C55FMC_SINGLE_BIT_CORRECTION_EVENT_CLEAR;

            for (errIndexPre = 0U; errIndexPre < sbcInfoPre.errCount; errIndexPre++)
            {
                if (SAF_MEM_FLASH == sbcInfoPre.errMemType[errIndexPre]\
                    && SAF_MEM_CE_BIT_ERR == sbcInfoPre.errType[errIndexPre])
                {
                    errAddr = sbcInfoPre.errAddr[errIndexPre];

                    /* Read data from SBC address */
                    data = *((volatile uint32_t *)(errAddr));/* polyspace RTE:NIV,IDP */
                    data = *((volatile uint32_t *)(errAddr));/* polyspace RTE:NIV,IDP */
                    data = *((volatile uint32_t *)(errAddr));/* polyspace RTE:NIV,IDP */
                    data = *((volatile uint32_t *)(errAddr));/* polyspace RTE:NIV,IDP */
                }
            }

            (void)memset((uint8_t *)&sbcInfoCurr, 0, sizeof(saf_mem_err_detect_info_t));
            (void)SAF_MEMU_DetectAllErr(SAF_MEM_FLASH, &sbcInfoCurr);

            status = SAF_FLASH_AccessFlashSbcReadCheck(&sbcInfoPre, &sbcInfoCurr, addrBuff);
        }
    }

    (void)data;

    return status;
}

/**
****************************************************************************************
* @brief:  This function shall be used to get flash array integrity test result.
* @param[out]   pTestResult   flash array integrity test result.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     get result succeed
*               FS_STATUS_ERROR       get result failed
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
FS_STATUS SAF_FLASH_ArrayIntegrityTestResult(saf_flash_ai_test_result_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (NULL != pTestResult)
    {
        status = FS_STATUS_SUCCESS;
        memcpy(pTestResult, &s_flashArrayIntegriteTest.output, sizeof(s_flashArrayIntegriteTest.output));/*PRQA S 3200*/
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function shall be used to execute flash array integrity test.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     flash array integrity test succeed
*               FS_STATUS_ERROR       flash array integrity test failed
****************************************************************************************
*/
#if defined(CCFC3008PT) | defined(CCFC3008PC) | defined(CCFC3008PCSN)
SAF_FLASH_SEC_CODE
#else
SAF_SEC_RAMCODE
#endif
FS_STATUS SAF_FLASH_ArrayIntegrityTest(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_flash_ai_test_result_t *pResult = &s_flashArrayIntegriteTest.output;
    saf_flash_ai_safety_info_t *pAiMisrObj = NULL;
    #if defined(CCFC3008PT) | defined(CCFC3008PC) | defined(CCFC3008PCSN)
    status = SAF_FLASH_ACLoadInit(SAF_FLASH_CALC_MISR_BY_AI);
    if (FS_STATUS_SUCCESS == status)
    {
    #endif
		do
		{
			pAiMisrObj = SAF_FLASH_AccessGetSafetyInfoHeader(SAF_FLASH_AI);/*PRQA S 0317*/
	        if (NULL == pAiMisrObj)
			{
				status = FS_STATUS_FLASH_AI_TEST_FAILED;
				break;
			}

            #if !(defined(CCFC3008PT) | defined(CCFC3008PC) | defined(CCFC3008PCSN))
			status = SAF_FLASH_CalcBlockMisrValue(&pAiMisrObj->flashBlockMisr[0], &s_flashAIConfigSet, C55_MARGIN_LEVEL_PROGRAM, SAF_FLASH_CALC_MISR_BY_AI);
            #else
			status = SAF_FLASH_CalcBlockMisrValue(&pAiMisrObj->flashBlockMisr[0], &s_flashAIConfigSet);
            #endif
			if (FS_STATUS_SUCCESS == status)
			{
                #if !(defined(CCFC3008PT) | defined(CCFC3008PC) | defined(CCFC3008PCSN))
				status = SAF_FLASH_CalcAndCompareBlockMisr(&pAiMisrObj->flashBlockMisr[0], &s_flashAIConfigSet, &pResult->blockPassed, C55_MARGIN_LEVEL_PROGRAM, SAF_FLASH_CALC_MISR_BY_AI);
                #else
				status = SAF_FLASH_CalcAndCompareBlockMisr(&pAiMisrObj->flashBlockMisr[0], &s_flashAIConfigSet, &pResult->blockPassed);
                #endif
			}

		} while(0);
    #if defined(CCFC3008PT) | defined(CCFC3008PC) | defined(CCFC3008PCSN)
    }
    #endif

    return status;
}

/**
****************************************************************************************
* @brief:  This function shall be used to get flash margin read result.
* @param[out]   pTestResult   flash margin read result.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     get result succeed
*               FS_STATUS_ERROR       get result failed
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
FS_STATUS SAF_FLASH_MarginReadTestResult(saf_flash_mr_test_result_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (NULL != pTestResult)
    {
        status = FS_STATUS_SUCCESS;
        memcpy(pTestResult, &s_flashMarginReadTest.output, sizeof(s_flashMarginReadTest.output));/*PRQA S 3200*/
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function shall be used to execute flash margin read check.
* @param[in]    level   flash margin read level.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     flash margin read check succeed
*               FS_STATUS_ERROR       flash margin read check failed
****************************************************************************************
*/
#if !(defined(CCFC3008PT) | defined(CCFC3008PC) | defined(CCFC3008PCSN))
SAF_SEC_RAMCODE
FS_STATUS SAF_FLASH_MarginReadLevelTest(flash_margin_option_t level)
#else
SAF_FLASH_SEC_CODE
FS_STATUS SAF_FLASH_MarginReadLevelTest(void)
#endif
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_flash_mr_test_result_t *pResult = &s_flashMarginReadTest.output;
    saf_flash_mr_safety_info_t *pMrMisrObj = NULL;

    do
    {
        pMrMisrObj = SAF_FLASH_AccessGetSafetyInfoHeader(SAF_FLASH_MR);/*PRQA S 0317*/
        if (pMrMisrObj == NULL)
        {
            status = FS_STATUS_FLASH_MR_TEST_FAILED;
            break;
        }
        #if !(defined(CCFC3008PT) | defined(CCFC3008PC) | defined(CCFC3008PCSN))
        status = SAF_FLASH_CalcBlockMisrValue(&pMrMisrObj->flashBlockMisr[0], &s_flashMRConfigSet, level, SAF_FLASH_CALC_MISR_BY_MR);
        #else
        status = SAF_FLASH_CalcBlockMisrValue(&pMrMisrObj->flashBlockMisr[0], &s_flashMRConfigSet);
        #endif

        if (FS_STATUS_SUCCESS == status)
        {
            #if !(defined(CCFC3008PT) | defined(CCFC3008PC) | defined(CCFC3008PCSN))
            status = SAF_FLASH_CalcAndCompareBlockMisr(&pMrMisrObj->flashBlockMisr[0], &s_flashMRConfigSet, &pResult->blockPassed, level, SAF_FLASH_CALC_MISR_BY_MR);
            #else
            status = SAF_FLASH_CalcAndCompareBlockMisr(&pMrMisrObj->flashBlockMisr[0], &s_flashMRConfigSet, &pResult->blockPassed);
            #endif
        }

    } while(0);

    return status;
}

/**
****************************************************************************************
* @brief:  This function shall be used to execute flash margin read check.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     flash margin read check succeed
*               FS_STATUS_ERROR       flash margin read check failed
****************************************************************************************
*/
#if !(defined(CCFC3008PT) | defined(CCFC3008PC) | defined(CCFC3008PCSN))
SAF_SEC_RAMCODE
#else
SAF_FLASH_SEC_CODE
#endif
FS_STATUS SAF_FLASH_MarginReadTest(void)
{
    FS_STATUS status = FS_STATUS_ERROR;
#if defined(CCFC3008PT) | defined(CCFC3008PC) | defined(CCFC3008PCSN)
    status = SAF_FLASH_ACLoadInit(SAF_FLASH_CALC_MISR_BY_MR);

    if(FS_STATUS_SUCCESS == status)
    {
        status = SAF_FLASH_MarginReadLevelTest();

        if(FS_STATUS_SUCCESS == status)
        {
            marginLevel = C55_MARGIN_LEVEL_ERASE;
            status = SAF_FLASH_MarginReadLevelTest();
        }
    }
#else
    status = SAF_FLASH_MarginReadLevelTest(C55_MARGIN_LEVEL_PROGRAM);

    if(FS_STATUS_SUCCESS == status)
    {
    	status = SAF_FLASH_MarginReadLevelTest(C55_MARGIN_LEVEL_ERASE);
    }
#endif
    return status;
}
/**
****************************************************************************************
* @brief:  This function shall be used to execute overlay remap test.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     overlay remap test succeed
*               FS_STATUS_ERROR       overlay remap test failed
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
FS_STATUS SAF_FLASH_OverlayTest(void)
{
    status_t ret = STATUS_SUCCESS;
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint32_t flashMirrAddr = flsOverlayTestMirrAddr;
    uint32_t sramAddr = s_flsOverlaySramAddr;
    const uint32_t remapSize = s_flsOverlayTestRemapSize; /* 4KByte */
    flash_remap_config_t remapConfig = { 0U, 0U, REMAP_SIZE_32B};

    /* Step 1: Copy data from Flash Mirror Address to Sram Address. */
    cc_memcpy((uint8_t *)(sramAddr), (const uint8_t *)flashMirrAddr, remapSize);

    /* Step 2: Overlay Config Enable (remap Flash Mirror Address to Sram Address). */
    remapConfig.flsLogicAddr = flashMirrAddr;
    remapConfig.ramPhyAddr = sramAddr;
    remapConfig.remapSize = REMAP_SIZE_2KB;
    ret = SAF_FLASH_LLD_Overlay_Config_Enable(SAF_FLASH_OVERLAY_RAM_TEST_CRD_INDEX, &remapConfig);
    if (STATUS_SUCCESS != ret)
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
        ret = SAF_FLASH_LLD_Overlay_Golbal_Enable();
        if (STATUS_SUCCESS != ret)
        {
            status = FS_STATUS_ERROR;
        }
        else
        {
            /* Step 3: Write 0x11111111U,0x22222222U to Sram Address.*/
            *(uint32_t*)sramAddr = SAF_FLASH_OVERLAY_RAM_TEST_FIRST_WRITE_WORD_DATA;/* polyspace RTE:IDP */
            *(uint32_t*)(sramAddr + 4U) = SAF_FLASH_OVERLAY_RAM_TEST_SECOND_WRITE_WORD_DATA;/* polyspace RTE:IDP */

            /* Step 4: Check the effect in flash mirrored address space.
            * (Except: value in flashMirrAddr is equal to value in sramAddr). */
            if ((SAF_FLASH_OVERLAY_RAM_TEST_FIRST_WRITE_WORD_DATA != (*(volatile uint32_t *)(flashMirrAddr))) || (SAF_FLASH_OVERLAY_RAM_TEST_SECOND_WRITE_WORD_DATA != (*(volatile uint32_t *)(flashMirrAddr + 4U))))/* polyspace RTE:NIV,IDP */
            {
                status = FS_STATUS_ERROR;
            }
            else
            {
                /* Step 5: Overlay Config Disable.
                * (Except: value in flashMirrAddr is recover). */
                ret = SAF_FLASH_LLD_Overlay_Config_Disable(SAF_FLASH_OVERLAY_RAM_TEST_CRD_INDEX);
                if (STATUS_SUCCESS != ret)
                {
                    status = FS_STATUS_ERROR;
                }
                else
                {
                    ret = SAF_FLASH_LLD_Overlay_Golbal_Disable();
                    if (STATUS_SUCCESS != ret)
                    {
                        status = FS_STATUS_ERROR;
                    }
                }
            }
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function shall be used to initialize the unused PFLASH remap descriptors.
* @param[in]    unusedLogicAddress   unused logic address.
* @return       void
****************************************************************************************
*/
SAF_FLASH_SEC_CODE
void SAF_FLASH_RemapDescriptorUnusedInit(uint32_t unusedLogicAddress)
{
    uint8_t CDR;

    /* Unused PFLASH remap descriptors shall be initialized to an unused logical address */
    for(CDR = 0; CDR < SAF_FLASH_CDR_NUM_ALL; CDR++)
    {
        if (PFLASH.PFCRDE.R & (0x1U << CDR))/*PRQA S 1891,4397*/
        {
            PFLASH.PFCRD[CDR].Word0.R = unusedLogicAddress & SAF_FLASH_PFCDRN_MASK;
        }
    }

}

#ifdef __cplusplus
}
#endif

