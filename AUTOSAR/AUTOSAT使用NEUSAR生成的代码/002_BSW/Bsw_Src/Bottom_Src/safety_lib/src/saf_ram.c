/**
****************************************************************************************
 * @FilePath: saf_ram.c
 * @Author: CCORE
 * @Date: 2024-02-12
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety Ram C File
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
#include "saf_ram.h"/*PRQA S 0380*/
#include "saf_cpu.h"
#include "saf_memu.h"
#include "memu_lld.h"
#include "intc_lld.h"
#include "saf_cache.h"
#include "fccu_lld.h"
#include "saf_fccu.h"
#include "Saf_MemMap.h"
/*PRQA S 0315,0492,0704,1006,1258,1259,1514,1862,2841,2844,2962,2982,3006 EOF*/
/*PRQA S 3119,3200,3332,3344,3408,4115,4304,4322,4422,4424,4558,4461 EOF*/
/**
****************************************************************************************
 * @brief: Global Variables
****************************************************************************************
*/
SAF_RAM_SEC_VAR_INIT
volatile uint32_t sramitcmTestFlag = RAM_SAFETY_OP_INITIAL;
SAF_RAM_SEC_VAR_INIT
volatile uint32_t sramEccIntcFlag = SAFETY_INTC_NO_INITIAL;
SAF_RAM_SEC_VAR_INIT/*PRQA S 1514*/
uint32_t sramitcmTestTimeout = 0U;

extern const saf_ram_test_object_t s_ramEccConfigSet;
extern MEMU_Type *s_pMemuRegList[SAF_MEMU_INSTANCE_COUNT];

/**
****************************************************************************************
 * @brief: Local Variables
****************************************************************************************
*/
SAF_RAM_SEC_VAR_NO_INIT
static uint32_t s_sysramCETestParamAddressList[MEMU_SYSRAM_CORRECTABLE_ERROR_TABLE_NUM];

SAF_RAM_SEC_VAR_NO_INIT
static uint32_t s_sysramUCETestParamAddress;

SAF_RAM_SEC_VAR_NO_INIT
static uint32_t s_pramCETestParamAddressList[MEMU_PRRAM_CORRECTABLE_ERROR_TABLE_NUM];

SAF_RAM_SEC_VAR_NO_INIT
static uint32_t s_pramUCETestParamAddress;

SAF_RAM_SEC_VAR_NO_INIT
static vuint32_t original_data;

SAF_RAM_SEC_VAR_NO_INIT
static vuint32_t original_ecc_data;

static vuint32_t sramTest[26] __attribute__ ((section(".saf_ram_data"))) = /*PRQA S 3218*/
{
    0xBABADEDAU,
    0xABBAABBAU,
    0xABBAABBAU,
    0xABBAABBAU,
    0xABBAABBAU,
    0xABBAABBAU,
    0xABBAABBAU,
    0xABBAABBAU,
    0xABBAABBAU,
    0xABBAABBAU,
    0xABBAABBAU,
    0xBABADEDAU,
    0xABBAABBAU,
    0xABBAABBAU,
    0xABBAABBAU,
    0xABBAABBAU,
    0xABBAABBAU,
    0xABBAABBAU,
    0xABBAABBAU,
    0xABBAABBAU,
    0xABBAABBAU,
    0xABBAABBAU,
    0xABBAABBAU,
    0xABBAABBAU,
    0xABBAABBAU,
    0xABBAABBAU
};

static vuint32_t itcmTestAddr[16] __attribute__ ((section(".saf_ram_data"))) = /*PRQA S 3218*/
{
    0x50000000U,
    0x50000008U,
    0x50000010U,
    0x50000018U,
    0x50000020U,
    0x50000028U,
    0x50000030U,
    0x50000038U,
    0x50000040U,
    0x50000048U,
    0x50000050U,
    0x50000058U,
    0x50000060U,
    0x50000068U,
    0x50000070U,
    0x50000078U
};

SAF_RAM_SEC_VAR_INIT
static saf_ram_ecc_report_path_test_t s_ramEccCheckTest =
{
    .output =
    {
        .testPassed =
        {
            .pramSingleBit = 0,
            .pramMultiBit  = 0,
            .sramSingleBit = 0,
            .sramMultiBit  = 0,
#if SAF_ITCM_SUPPORTED
            .itcmSingleBit = 0,
            .itcmMultiBit  = 0,
#endif
        },
    }
};

SAF_RAM_SEC_VAR_NO_INIT
fccu_rf_config_t realSramEccFccuRfCfg[SAF_FCCU_RF_MAX_SIZE];
SAF_RAM_SEC_VAR_NO_INIT
fccu_rf_config_t realPramEccFccuRfCfg[SAF_FCCU_RF_MAX_SIZE];

SAF_RAM_SEC_VAR_INIT
fccu_rf_config_t fccSramEccStartUpRfCfg[] = {
	    {
	        /* FCCU Channel ID */
	        .channel        = (uint8_t)FCCU_FAILURE_MEMU_RAM_CE_CH_16,
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
	        .callback       = &Saf_RamCEInject_Callback,
	        /* The parameters of the alarm notification function */
	        .callbackParam  = NULL_PTR
	    },

	    {
	        /* FCCU Channel ID */
	        .channel        = (uint8_t)FCCU_FAILURE_MEMU_RAM_UCE_CH_17,
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
	        .channel        = (uint8_t)FCCU_FAILURE_MEMU_RAM_BOV_CH_18,
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

SAF_RAM_SEC_VAR_INIT
fccu_config_t fccuSramEccStartUpCfg=
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
    .rfConfigNumber       = (uint8_t)(sizeof(fccSramEccStartUpRfCfg)/sizeof(fccSramEccStartUpRfCfg[0])),
    /* time-out notification function */
    .callbackFunc         = NULL_PTR,
    /* The parameters of the time-out notification function */
    .callbackParam        = NULL_PTR
};

SAF_RAM_SEC_VAR_INIT
fccu_rf_config_t fccPramEccStartUpRfCfg[] = {
	    {
	        /* FCCU Channel ID */
	        .channel        = (uint8_t)FCCU_FAILURE_MEMU_PER_CE_CH_19,
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
	        .channel        = (uint8_t)FCCU_FAILURE_MEMU_PER_UCE_CH_20,
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
	        .channel        = (uint8_t)FCCU_FAILURE_MEMU_PER_BOV_CH_21,
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

SAF_RAM_SEC_VAR_INIT
fccu_config_t fccuPramEccStartUpCfg=
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
    .rfConfigNumber       = (uint8_t)(sizeof(fccPramEccStartUpRfCfg)/sizeof(fccPramEccStartUpRfCfg[0])),
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
* @brief:  PRRAM generate ECC error.
* @param[in]    eccType  PRAM error type(single bit type or multi bit type).
* @param[in]    offset   MEMU PRAM error table offset.
* @return       status_t
*               STATUS_SUCCESS     PRRAM generate ECC error succeed
*               STATUS_ERROR       PRRAM generate ECC error failed
****************************************************************************************
*/
SAF_RAM_SEC_CODE
static FS_STATUS SAF_RAM_PRRAMGenerateEccError(uint8_t eccType, uint8_t offset)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    uint32_t value;

    uint8_t row_slct;

    uint32_t data;

    uint32_t ecc_data;

    row_slct = offset + 1U;

    original_data = 0x00;

    if(eccType == 0U)
    {
        data = original_data ^ (uint32_t)0x01;
    }
    else
    {
        data = original_data ^ (uint32_t)0x03;
    }

    IMA_SAF.SLCT.B.ARRAY_SLCT = 0;

    switch(offset)
    {
        case 252U:
        {	    
            eDMA_1.TCD[63].NBYTES.MLNO.R = original_data;
            value = eDMA_1.TCD[63].NBYTES.MLNO.R;  /* polyspace RTE:NIV */
        }
        break;

        case 253U:
        {
            eDMA_1.TCD[63].DADDR.R = original_data;
            value = eDMA_1.TCD[63].DADDR.R;  /* polyspace RTE:NIV */
        }
        break;

        default:
            status = FS_STATUS_ERROR;
        break;
    }

    IMA_SAF.READ_UNLOCK.R = 0xF06AB5BCU;
    IMA_SAF.READ_UNLOCK.R = 0x14081B56U;
    IMA_SAF.SLCT.B.ARRAY_SLCT = 2;
    IMA_SAF.SLCT.B.ROW_SLCT = row_slct;
    original_ecc_data = IMA_SAF.READ_DATA_2.R;
    IMA_SAF.CTRL.B.READ = 1;
    IMA_SAF.ENABLE_R.B.EN = 1;

	ecc_data = original_ecc_data;

    IMA_SAF.WRITE_UNLOCK.R = 0x04A43F95U;
    IMA_SAF.WRITE_UNLOCK.R = 0xE4A9EBF7U;
    IMA_SAF.SLCT.B.ARRAY_SLCT = 2;
    IMA_SAF.SLCT.B.ROW_SLCT = row_slct;
    IMA_SAF.WRITE_DATA_1.R = data;
    IMA_SAF.WRITE_DATA_2.R = ecc_data;
    IMA_SAF.CTRL.B.READ = 0;
    IMA_SAF.ENABLE_R.B.EN = 1;

    IMA_SAF.READ_UNLOCK.R = 0xF06AB5BCU;
    IMA_SAF.READ_UNLOCK.R = 0x14081B56U;
    IMA_SAF.SLCT.B.ARRAY_SLCT = 2;
    IMA_SAF.SLCT.B.ROW_SLCT = row_slct;
    IMA_SAF.CTRL.B.READ = 1;
    IMA_SAF.ENABLE_R.B.EN = 1;

    IMA_SAF.SLCT.B.ARRAY_SLCT = 0;
    SAF_FCCU_LLD_ClearFaults(25U);
    switch(offset)
    {
        case 252U:
        {
            value = eDMA_1.TCD[63].NBYTES.MLNO.R;  /* polyspace RTE:NIV */
        }
        break;

        case 253U:
        {
            value = eDMA_1.TCD[63].DADDR.R;  /* polyspace RTE:NIV */
        }
        break;

        default:
            status = FS_STATUS_ERROR;
  break;
    }
    (void)value;/*PRQA S 3119*/
    return status;
}

/**
****************************************************************************************
* @brief:  PRRAM Delete ECC error.
* @param[in]    eccType  PRAM error type(single bit type or multi bit type).
* @param[in]    offset   MEMU PRAM error table offset.
* @return       status_t
*               STATUS_SUCCESS     PRRAM Delete ECC error succeed
*               STATUS_ERROR       PRRAM Delete ECC error failed
****************************************************************************************
*/
SAF_RAM_SEC_CODE
static FS_STATUS SAF_RAM_PRRAMDeleteEccError(uint8_t offset)
{
    uint8_t row_slct;
	row_slct = offset + 1U;

	IMA_SAF.WRITE_UNLOCK.R = 0x04A43F95U;
	IMA_SAF.WRITE_UNLOCK.R = 0xE4A9EBF7U;
	IMA_SAF.SLCT.B.ARRAY_SLCT = 2;
	IMA_SAF.SLCT.B.ROW_SLCT = row_slct;
	IMA_SAF.WRITE_DATA_1.R = original_data;
	IMA_SAF.WRITE_DATA_2.R = original_ecc_data;
	IMA_SAF.CTRL.B.READ = 0;
	IMA_SAF.ENABLE_R.B.EN = 1;

	IMA_SAF.READ_UNLOCK.R = 0xF06AB5BCU;
	IMA_SAF.READ_UNLOCK.R = 0x14081B56U;
	IMA_SAF.SLCT.B.ARRAY_SLCT = 2;
	IMA_SAF.SLCT.B.ROW_SLCT = row_slct;
	IMA_SAF.CTRL.B.READ = 1;
	IMA_SAF.ENABLE_R.B.EN = 1;

	IMA_SAF.SLCT.B.ARRAY_SLCT = 0;
	SAF_FCCU_LLD_ClearFaults(25U);

    return FS_STATUS_SUCCESS;
}

/**
****************************************************************************************
* @brief:  SRRAM generate ECC error.
* @param[in]    eccType  SRAM error type(single bit type or multi bit type).
* @param[in]    offset   MEMU SRAM error table offset.
* @return       status_t
*               STATUS_SUCCESS     SRRAM generate ECC error succeed
*               STATUS_ERROR       SRRAM generate ECC error failed
****************************************************************************************
*/
SAF_RAM_SEC_CODE
static status_t SAF_RAM_SRAMGenerateEccError(uint8_t eccType, uint8_t offset)
{
    uint8_t tempOffset;

    tempOffset = offset * 2U;

    if(eccType == 0U)
    {
        register uint32_t testRead = 0;

        (void)SetupE2EECSR0_for_1b_ECC_fault();

        sramTest[tempOffset] = testRead;

        testRead = sramTest[tempOffset];/*PRQA S 2983*/
    }
    else
    {
        register uint32_t testRead = 0;

        (void)SetupE2EECSR0_for_2b_ECC_fault();

        sramTest[tempOffset] = testRead;

        testRead = sramTest[tempOffset];/*PRQA S 2983*/
    }

    (void)SetupE2EECSR0_for_ClearWRC();

    return STATUS_SUCCESS;
}

/**
****************************************************************************************
* @brief This function shall be used to write complementary mode after SRAM SBC occurs.
* @param[in] memType :Selected RAM type.
* @param[in] pMemInfo :All selected RAM ECC error info.
* @param[out] addr :SRAM ECC MBE address buffer.
* @return FS_STATUS
*         FS_STATUS_SUCCESS :Multiple read operations normal.
*         FS_STATUS_ERROR :Multiple read operations abnormal.
****************************************************************************************
*/
SAF_RAM_SEC_CODE
static FS_STATUS SAF_RAM_AccessRamSbcReadCheck(SAF_MEM_TYPE memType, saf_mem_err_detect_info_t *pMemInfo, uint32_t* addr)
{
    uint32_t errAddr = 0U;
    uint32_t tempData = 0U;
    FS_STATUS status = FS_STATUS_SUCCESS;
    SAF_MEM_ERR_TYPE errType = SAF_MEM_NONE_BIT_ERR;
    uint32_t errNum = 0U;
    uint8_t addrNum = 0;

    errNum = pMemInfo->errCount;

    for (uint8_t num = 0; num < errNum; num++)
    {
        if ((memType != SAF_MEM_FLASH) && (memType == pMemInfo->errMemType[num]) && (SAF_MEM_CE_BIT_ERR == pMemInfo->errType[num]))
        {
            errAddr = pMemInfo->errAddr[num];

            /* First write and read. */
            if (NULL != (uint32_t *)(errAddr))
            {
                *((uint32_t *)(errAddr)) = (uint32_t)(SAF_RAM_SBC_READ_CHECK_FIRST_WRITE_DATA);/* polyspace RTE:IDP */
                tempData = *((uint32_t *)(errAddr));/* polyspace RTE:NIV,IDP */

                (void)SAF_MEMU_GetMemErrAndClean(memType, errAddr, &errType);

                if (SAF_MEM_CE_BIT_ERR == errType)
                {
                    /* Second write and read. */
                    *((uint32_t *)(errAddr)) = (uint32_t)(SAF_RAM_SBC_READ_CHECK_SECOND_WRITE_DATA);/* polyspace RTE:IDP */
                    tempData = *((uint32_t *)(errAddr));/* polyspace RTE:NIV,IDP */

                    (void)SAF_MEMU_GetMemErrAndClean(memType, errAddr, &errType);

                    if (SAF_MEM_NONE_BIT_ERR != errType)
                    {
                        addr[addrNum] = errAddr;
                        addrNum++;
                        status = FS_STATUS_ERROR;
                    }
                }
                else if (SAF_MEM_UCE_BIT_ERR == errType)
                {
                    addr[addrNum] = errAddr;
                    addrNum++;
                    status = FS_STATUS_ERROR;
                }
                else
                {
                    /* Do nothing. */
                }
            }
            else
            {
                status = FS_STATUS_ERROR;
                break;
            }
        }

        SAF_MEMU_CleanAllErr(memType);
    }

    (void)tempData;

    return status;
}

/**
****************************************************************************************
* @brief:  ITCM generate ECC error.
* @param[in]    eccType  ITCM error type(single bit type or multi bit type).
* @param[in]    offset   MEMU SRAM error table offset.
* @return       status_t
*               STATUS_SUCCESS     ITCM generate ECC error succeed
*               STATUS_ERROR       ITCM generate ECC error failed
****************************************************************************************
*/
SAF_RAM_SEC_CODE
static status_t SAF_RAM_ITCMGenerateEccError(uint8_t eccType, uint8_t offset)
{

    if(eccType == 0U)
    {
        register uint32_t testRead = 0;

        (void)SetupE2EECSR0_for_1b_ECC_fault();

        PPCASM("se_lwz %r7,8(%r31)");
        PPCASM("e_stmw %r30,0(%r7)");   /* Write 64 bit to SRAM */

        testRead = *(uint64_t*)itcmTestAddr[offset];/*PRQA S 2983*//* polyspace RTE:NIV,IDP */
        (void)testRead;
    }
    else
    {
        register uint32_t testRead = 0;

        (void)SetupE2EECSR0_for_2b_ECC_fault();

        PPCASM("se_lwz %r7,8(%r31)");
        PPCASM("e_stmw %r30,0(%r7)");   /* Write 64 bit to SRAM */

        testRead = *(uint64_t*)itcmTestAddr[offset];/*PRQA S 2983*//* polyspace RTE:NIV,IDP */
        (void)testRead;
    }

    (void)SetupE2EECSR0_for_ClearWRC();

    return STATUS_SUCCESS;
}

/**
****************************************************************************************
* @brief:  PRAM single bit error callback.
* @return  void
****************************************************************************************
*/
SAF_RAM_SEC_CODE
static void SAF_RAM_PrramCECallback(void)
{
    uint8_t i;
    static uint8_t k = 0;
    if (k >= MEMU_PRRAM_CORRECTABLE_ERROR_TABLE_NUM)
    {
    	k = 0;
    }
    (void)SAF_RAM_PRRAMDeleteEccError(252 + k);
    k++;
    for(i = 0U; i < MEMU_PRRAM_CORRECTABLE_ERROR_TABLE_NUM; i++)
    {
        s_pramCETestParamAddressList[i] = MEMU_LLD_GetCorrectableErrorAddress(MEMU_PERIPHERAL_RAM_DETECT, i);
    }
}

/**
****************************************************************************************
* @brief:  PRAM multiple bit error callback.
* @return  void
****************************************************************************************
*/
SAF_RAM_SEC_CODE
static void SAF_RAM_PrramUCECallback(void)
{
	(void)SAF_RAM_PRRAMDeleteEccError(252);
    s_pramUCETestParamAddress = MEMU_LLD_GetUncorrectableErrorAddress(MEMU_PERIPHERAL_RAM_DETECT);
}

/**
****************************************************************************************
* @brief:  SRAM single bit error callback.
* @return  void
****************************************************************************************
*/
SAF_RAM_SEC_CODE
static void SAF_RAM_SysramCECallback(void)
{
    uint8_t i;
    for(i = 0U; i < MEMU_SYSRAM_CORRECTABLE_ERROR_TABLE_NUM; i++)
    {
        s_sysramCETestParamAddressList[i] = MEMU_LLD_GetCorrectableErrorAddress(MEMU_SYSTEM_RAM_DETECT, i);
    }
}

/**
****************************************************************************************
* @brief:  SRAM multiple bit error callback.
* @return  void
****************************************************************************************
*/
SAF_RAM_SEC_CODE
static void SAF_RAM_SysramUCECallback(void)
{
    s_sysramUCETestParamAddress = MEMU_LLD_GetUncorrectableErrorAddress(MEMU_SYSTEM_RAM_DETECT);
}

/**
****************************************************************************************
 * @brief: Global Functions
****************************************************************************************
*/

/**
****************************************************************************************
* @brief:  This function shall be used to inject 1-bit or 2-bit error with a specified RAM address.
* @param[in]    injectType  inject RAM error type(single bit type or multi bit type).
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     inject bit error succeed
*               FS_STATUS_ERROR       inject bit error failed
****************************************************************************************
*/
SAF_RAM_SEC_CODE
FS_STATUS SAF_RAM_InjectBitError(const saf_ram_inject_bit_type_t injectType)
{
    uint8_t i,j;
    uint8_t breakFlag = 0U;
    FS_STATUS status = FS_STATUS_SUCCESS;

    if (SAF_MEM_PRAM == injectType.ramType)
    {
        if(SAF_MEM_CE_BIT_ERR == injectType.injectBitType)
        {
            (void)MEMU_LLD_SetUpCallback(MEMU_PERIPHERAL_RAM_DETECT,
                                       MEMU_CORRECTABLE_ERROR_DETECT,
                                       &SAF_RAM_PrramCECallback);

            for(i = 0U; i < MEMU_PRRAM_CORRECTABLE_ERROR_TABLE_NUM; i++)
            {
                status = SAF_RAM_PRRAMGenerateEccError(SAF_MEM_CE_BIT_ERR, (uint8_t)((uint32_t)i + 252U));

                if(FS_STATUS_SUCCESS != status)/*PRQA S 2996,2992*/
                {
                    break;
                }
            }
        }
        else if(SAF_MEM_UCE_BIT_ERR == injectType.injectBitType)
        {
            (void)MEMU_LLD_SetUpCallback(MEMU_PERIPHERAL_RAM_DETECT,
                                   MEMU_UNCORRECTABLE_ERROR_DETECT,
                                   &SAF_RAM_PrramUCECallback);

            status = SAF_RAM_PRRAMGenerateEccError(SAF_MEM_UCE_BIT_ERR, (uint8_t)(0U + 252U));
        }
        else
        {
            /*Do nothing*/
        }
    }
    else if (SAF_MEM_SRAM == injectType.ramType)
    {
        if(SAF_MEM_CE_BIT_ERR == injectType.injectBitType)
        {
            (void)MEMU_LLD_SetUpCallback(MEMU_SYSTEM_RAM_DETECT,
                                       MEMU_CORRECTABLE_ERROR_DETECT,
                                       &SAF_RAM_SysramCECallback);

            for(j = 0U; j < 10U; j++)
            {
            	sramitcmTestFlag = RAM_SAFETY_OP_INITIAL;
                (void)SAF_RAM_SRAMGenerateEccError(0U, j);

                /* wait FCCU interrupt */
            	sramitcmTestTimeout = 0U;
                while(RAM_SAFETY_OP_INITIAL == sramitcmTestFlag)
                {
                	sramitcmTestTimeout++;
                    if(sramitcmTestTimeout >= SAF_SYSRAM_ITCM_WAIT_WHILE_OPERATION_TIMEOUT_CNT)
                    {
                    	status = FS_STATUS_TIMEOUT;
                    	breakFlag = 1U;
                    	break;
                    }
                }

                if(1U == breakFlag)
                {
                	break;
                }
            }

        }
        else if(SAF_MEM_UCE_BIT_ERR == injectType.injectBitType)
        {
            (void)MEMU_LLD_SetUpCallback(MEMU_SYSTEM_RAM_DETECT,
                                       MEMU_UNCORRECTABLE_ERROR_DETECT,
                                       &SAF_RAM_SysramUCECallback);

            (void)SAF_RAM_SRAMGenerateEccError(1, 11);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else if (SAF_MEM_ITCM == injectType.ramType)
    {
        if(SAF_MEM_CE_BIT_ERR == injectType.injectBitType)
        {
            (void)MEMU_LLD_SetUpCallback(MEMU_SYSTEM_RAM_DETECT,
                                       MEMU_CORRECTABLE_ERROR_DETECT,
                                       &SAF_RAM_SysramCECallback);

            for(j = 0U; j < 10U; j++)
            {
            	sramitcmTestFlag = RAM_SAFETY_OP_INITIAL;
                (void)SAF_RAM_ITCMGenerateEccError(0U, j);

                /* wait FCCU interrupt */
            	sramitcmTestTimeout = 0U;
                while(RAM_SAFETY_OP_INITIAL == sramitcmTestFlag)
                {
                	sramitcmTestTimeout++;
                    if(sramitcmTestTimeout >= SAF_SYSRAM_ITCM_WAIT_WHILE_OPERATION_TIMEOUT_CNT)
                    {
                    	status = FS_STATUS_TIMEOUT;
                    	breakFlag = 1U;
                    	break;
                    }
                }

                if(1U == breakFlag)
                {
                	break;
                }
            }

        }
        else if(SAF_MEM_UCE_BIT_ERR == injectType.injectBitType)
        {
            (void)MEMU_LLD_SetUpCallback(MEMU_SYSTEM_RAM_DETECT,
                                       MEMU_UNCORRECTABLE_ERROR_DETECT,
                                       &SAF_RAM_SysramUCECallback);

            (void)SAF_RAM_ITCMGenerateEccError(1, 11);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /* Do nothing */
    }

    return status;
}


/**
****************************************************************************************
* @brief:  This function is used to test PRAM ECC error report path.
* @param[in]    pParam    test input (inject PRAM error type: single bit type or multi bit type).
* @param[out]   pResult   test result.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     PRAM ECC error report path test succeed
*               FS_STATUS_ERROR       PRAM ECC error report path test failed
****************************************************************************************
*/
SAF_RAM_SEC_CODE
FS_STATUS SAF_RAM_PramEccReportPathTest(const saf_ram_test_object_t *pParam, saf_ram_ecc_report_path_test_result_t *pResult)
{    
    uint8_t i;
    FS_STATUS status = FS_STATUS_ERROR;
    FS_STATUS singleStatus = FS_STATUS_SUCCESS, mulitiStatus = FS_STATUS_SUCCESS;
    FS_STATUS pramFccuStatus = FS_STATUS_SUCCESS;
    saf_ram_inject_bit_type_t eccInjectParam;
    SAF_MEM_ERR_TYPE pramErrType;

    SAF_FCCU_CopyUninitChannelConfig(&fccuPramEccStartUpCfg, realPramEccFccuRfCfg, fccPramEccStartUpRfCfg, MEMU_PER_CE, 3);

    /* check fccu status */
    if (fccuPramEccStartUpCfg.rfConfigNumber > 0)
    {
    	SAF_FCCU_ClearAllChannelFault();
    	pramFccuStatus = SAF_FCCU_HardwareInit(&fccuPramEccStartUpCfg, realPramEccFccuRfCfg);
    }


    do
    {
        (void)MEMU_LLD_Reset();
        SAF_MEM_ErrorReportInit(SAF_MEM_PRAM);
        /*ensure PRAM error*/
        eccInjectParam.ramType = SAF_MEM_PRAM;

        if (pParam->pramSingleBit)
        {
            pResult->testPassed.pramSingleBit = (bool)false;
            eccInjectParam.injectBitType = SAF_MEM_CE_BIT_ERR;

            singleStatus = SAF_RAM_InjectBitError(eccInjectParam);

            if (FS_STATUS_SUCCESS == singleStatus)
            {
                for(i = 0U; i < MEMU_PRRAM_CORRECTABLE_ERROR_TABLE_NUM; i++)
                {
                    singleStatus = SAF_MEM_GetEccErrorResult(SAF_MEM_PRAM, s_pramCETestParamAddressList[i], &pramErrType);
                    if(FS_STATUS_SUCCESS != singleStatus)
                    {
                        break;
                    }
                }

                if (FS_STATUS_SUCCESS == singleStatus)
                {
                    if (SAF_MEM_CE_BIT_ERR == pramErrType)
                    {
                        pResult->testPassed.pramSingleBit = (bool)true;
                    }
                    else
                    {
                        singleStatus = FS_STATUS_RAM_INJECTION_FAILED;
                    }
                }
            }
        }

        (void)MEMU_LLD_Reset();

        if (pParam->pramMultiBit)
        {
            pResult->testPassed.pramMultiBit = (bool)false;
            eccInjectParam.injectBitType = SAF_MEM_UCE_BIT_ERR;

            mulitiStatus = SAF_RAM_InjectBitError(eccInjectParam);

            if (FS_STATUS_SUCCESS == mulitiStatus)
            {
                mulitiStatus = SAF_MEM_GetEccErrorResult(SAF_MEM_PRAM, s_pramUCETestParamAddress, &pramErrType);
                if (FS_STATUS_SUCCESS == mulitiStatus)
                {
                    if (SAF_MEM_UCE_BIT_ERR == pramErrType)
                    {
                        pResult->testPassed.pramMultiBit = (bool)true;
                    }
                    else
                    {
                        mulitiStatus = FS_STATUS_RAM_INJECTION_FAILED;
                    }
                }
            }
        }
        (void)MEMU_LLD_Reset();
    } while(0);
    
    if ((singleStatus == FS_STATUS_SUCCESS) && (mulitiStatus == FS_STATUS_SUCCESS))
    {
        status =  FS_STATUS_SUCCESS;
    }
    else
    {
        if (singleStatus != FS_STATUS_SUCCESS)
        {
            pResult->testPassed.pramSingleBit = (bool)false;
        }

        if (mulitiStatus != FS_STATUS_SUCCESS)
        {
            pResult->testPassed.pramMultiBit = (bool)false;
        }
        status = FS_STATUS_PRAM_ECC_REPROT_TEST_FAILED;
    }

    if (pramFccuStatus != FS_STATUS_SUCCESS)
    {
    	status = FS_STATUS_ERROR;
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to test SRAM ECC error report path.
* @param[in]    pParam    test input (inject SRAM error type: single bit type or multi bit type).
* @param[out]   pResult   test result.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     SRAM ECC error report path test succeed
*               FS_STATUS_ERROR       SRAM ECC error report path test failed
****************************************************************************************
*/
SAF_RAM_SEC_CODE
FS_STATUS SAF_RAM_SramEccReportPathTest(const saf_ram_test_object_t *pParam, saf_ram_ecc_report_path_test_result_t *pResult)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    FS_STATUS singleStatus = FS_STATUS_SUCCESS, mulitiStatus = FS_STATUS_SUCCESS;
    FS_STATUS sramFccuStatus = FS_STATUS_SUCCESS;
    SAF_MEM_ERR_TYPE sramErrType;
    saf_ram_inject_bit_type_t eccInjectParam;
    uint8_t i;
    uint32_t sramEccAddr = (uint32_t)&sramTest[0];
    uint32_t sramEccSize = sizeof(sramTest) / sizeof(sramTest[0]);
#if SAF_DCACHE_SUPPORTED
    bool DCacheStatus = (bool)false;
#endif
#if SAF_ICACHE_SUPPORTED
    bool ICacheStatus = (bool)false;
#endif
    SAF_FCCU_CopyUninitChannelConfig(&fccuSramEccStartUpCfg, realSramEccFccuRfCfg, fccSramEccStartUpRfCfg, MEMU_RAM_CE, 3);

    /* check fccu status */
    if (fccuSramEccStartUpCfg.rfConfigNumber > 0)
    {
    	SAF_FCCU_ClearAllChannelFault();
    	sramFccuStatus = SAF_FCCU_HardwareInit(&fccuSramEccStartUpCfg, realSramEccFccuRfCfg);
    }
#if SAF_DCACHE_SUPPORTED
    DCacheStatus = SAF_CACHE_AccessDcacheIsEnabled();
    SAF_CACHE_AccessDisableDcache();
#endif
#if SAF_ICACHE_SUPPORTED
    ICacheStatus = SAF_CACHE_AccessIcacheIsEnabled();
    SAF_CACHE_AccessDisableIcache();
#endif

    do
    {
        (void)MEMU_LLD_Reset();
        SAF_MEM_ErrorReportInit(SAF_MEM_SRAM);
        eccInjectParam.ramType = SAF_MEM_SRAM;

        if (pParam->sramMultiBit)
        {
            pResult->testPassed.sramMultiBit = (bool)false;
            eccInjectParam.injectBitType = SAF_MEM_UCE_BIT_ERR;

            mulitiStatus = SAF_RAM_InjectBitError(eccInjectParam);

            if (FS_STATUS_SUCCESS == mulitiStatus)
            {
                mulitiStatus = SAF_MEM_GetEccErrorResult(SAF_MEM_SRAM, s_sysramUCETestParamAddress, &sramErrType);
                if (FS_STATUS_SUCCESS == mulitiStatus)
                {
                    if (SAF_MEM_UCE_BIT_ERR == sramErrType)
                    {
                        pResult->testPassed.sramMultiBit = (bool)true;
                    }
                    else
                    {
                        mulitiStatus = FS_STATUS_RAM_INJECTION_FAILED;
                    }
                }
            }
        }

        (void)MEMU_LLD_Reset();

        if (pParam->sramSingleBit)
        {
            pResult->testPassed.sramSingleBit = (bool)false;
            eccInjectParam.injectBitType = SAF_MEM_CE_BIT_ERR;
            sramitcmTestFlag = RAM_SAFETY_OP_INITIAL;

            singleStatus = SAF_RAM_InjectBitError(eccInjectParam);

            if (FS_STATUS_SUCCESS == singleStatus)
            {
                for(i = 0U; i < MEMU_SYSRAM_CORRECTABLE_ERROR_TABLE_NUM; i++)
                {
                    singleStatus = SAF_MEM_GetEccErrorResult(SAF_MEM_SRAM, s_sysramCETestParamAddressList[i], &sramErrType);
                    if(FS_STATUS_SUCCESS != singleStatus)
                    {
                        break;
                    }
                }

                if (FS_STATUS_SUCCESS == singleStatus)
                {
                    if (SAF_MEM_CE_BIT_ERR == sramErrType)
                    {
                        pResult->testPassed.sramSingleBit = (bool)true;
                    }
                    else
                    {
                        singleStatus = FS_STATUS_RAM_INJECTION_FAILED;
                    }
                }
            }
        }

        (void)MEMU_LLD_Reset();

    } while(0);
#if SAF_DCACHE_SUPPORTED
    if (DCacheStatus == true)/*PRQA S 1881*/
    {
    	SAF_CACHE_AccessEnableDcache();
    }
#endif
#if SAF_ICACHE_SUPPORTED
    if (ICacheStatus == true)/*PRQA S 1881*/
    {
    	SAF_CACHE_AccessEnableIcache();
    }
#endif
    if ((singleStatus == FS_STATUS_SUCCESS) && (mulitiStatus == FS_STATUS_SUCCESS))
    {
        status =  FS_STATUS_SUCCESS;
    }
    else
    {
        if (singleStatus != FS_STATUS_SUCCESS)
        {
            pResult->testPassed.sramSingleBit = (bool)false;
        }

        if (mulitiStatus != FS_STATUS_SUCCESS)
        {
            pResult->testPassed.sramMultiBit = (bool)false;
        }
        status = FS_STATUS_SRAM_ECC_REPROT_TEST_FAILED;
    }

    if (sramFccuStatus != FS_STATUS_SUCCESS)
    {
    	status = FS_STATUS_ERROR;
    }
    (void)SetupE2EECSR0_for_ClearECC(sramEccAddr, sramEccSize/2);
    return status;
}

/**
****************************************************************************************
* @brief:  This function shall be used to get RAM ECC error report path test result.
* @param[out]   pTestResult   ECC error report path test result.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     get result succeed
*               FS_STATUS_ERROR       get result failed
****************************************************************************************
*/
SAF_RAM_SEC_CODE
FS_STATUS SAF_RAM_EccReportPathTestResult(saf_ram_ecc_report_path_test_result_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;
    
    if (NULL != pTestResult)
    {
        (void)memcpy(pTestResult, &s_ramEccCheckTest.output, sizeof(s_ramEccCheckTest.output));
        status = FS_STATUS_SUCCESS;
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to test RAM ECC error report path.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     RAM ECC error report path test succeed
*               FS_STATUS_ERROR       RAM ECC error report path test failed
****************************************************************************************
*/
SAF_RAM_SEC_CODE
FS_STATUS SAF_RAM_EccReportPathTest(void)
{
    FS_STATUS status = FS_STATUS_ERROR;
    FS_STATUS sramStatus = FS_STATUS_ERROR;
    FS_STATUS pramStatus = FS_STATUS_ERROR;
    FS_STATUS switchStatus = FS_STATUS_SUCCESS;
    uint32_t switchOn = 1;
    uint32_t switchOff = 0;
    saf_ram_ecc_report_path_test_result_t *pResult = &s_ramEccCheckTest.output;

    if (FS_STATUS_SUCCESS != (FS_STATUS)SAF_FCCU_LLD_StartupCallbackSwitch(switchOn))
    {
    	switchStatus = FS_STATUS_ERROR;
    }

    if ((s_ramEccConfigSet.pramSingleBit) || (s_ramEccConfigSet.pramMultiBit))
    {
        pramStatus = SAF_RAM_PramEccReportPathTest(&s_ramEccConfigSet, pResult); 
    }

    if ((s_ramEccConfigSet.sramSingleBit) || (s_ramEccConfigSet.sramMultiBit))
    {
        sramStatus = SAF_RAM_SramEccReportPathTest(&s_ramEccConfigSet, pResult);
#if STACK_MONITOR_ENABLE == STD_ON
        (void)SAF_FCCU_LLD_CloseChReaction(SAF_FCCU_FAILURE_MEMU_RAM_UCE_CH_17);
        (void)SAF_FCCU_LLD_CloseChReaction(SAF_FCCU_FAILURE_MEMU_RAM_BOV_CH_18);
#endif
    }

    if (FS_STATUS_SUCCESS != (FS_STATUS)SAF_FCCU_LLD_StartupCallbackSwitch(switchOff))
    {
    	switchStatus = FS_STATUS_ERROR;
    }

    if ((sramStatus == FS_STATUS_SUCCESS) && (pramStatus == FS_STATUS_SUCCESS))
    {
        status = FS_STATUS_SUCCESS;
    }
    if (switchStatus == FS_STATUS_ERROR)
    {
    	status = FS_STATUS_ERROR;
    }
    return status;
}


/**
****************************************************************************************
* @brief:  This function shall be used to write complementary mode after ram SBC occurs.
* @param[out]   addr   SRAM ECC MBE address buffer.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     multiple read operations normal
*               FS_STATUS_ERROR       multiple read operations abnormal
****************************************************************************************
*/
SAF_RAM_SEC_CODE
FS_STATUS SAF_RAM_SBCReadCheck(uint32_t* addr)
{
    FS_STATUS status = FS_STATUS_ERROR;
    FS_STATUS sramStatus = FS_STATUS_SUCCESS;
    FS_STATUS pramStatus = FS_STATUS_SUCCESS;
    saf_mem_err_detect_info_t sbcSramInfo = { { (SAF_MEM_ERR_TYPE)0U }, { (SAF_MEM_TYPE)0U }, { 0U }, 0U };/*PRQA S 0686,3604,4342*/
    saf_mem_err_detect_info_t sbcPramInfo = { { (SAF_MEM_ERR_TYPE)0U }, { (SAF_MEM_TYPE)0U }, { 0U }, 0U };/*PRQA S 0686,3604,4342*/
    MEMU_Type *pBase = s_pMemuRegList[0];

    if (NULL != addr)
    {
        /* SRAM. */
        if (SAF_MEMU_SRAM_CORRECTABLE_ERROR_DETECT == pBase->ERR_FLAG.B.SR_CE)/* polyspace RTE:NIV */
        {
            (void)memset(&sbcSramInfo, 0, sizeof(saf_mem_err_detect_info_t));
            (void)SAF_MEMU_DetectAllErr(SAF_MEM_SRAM, &sbcSramInfo);
            SAF_MEMU_CleanAllErr(SAF_MEM_SRAM);

            sramStatus = SAF_RAM_AccessRamSbcReadCheck(SAF_MEM_SRAM, &sbcSramInfo, addr);
        }

        /* PRAM. */
        if (SAF_MEMU_PRAM_CORRECTABLE_ERROR_DETECT == pBase->ERR_FLAG.B.PR_CE)/* polyspace RTE:NIV */
        {
            (void)memset(&sbcPramInfo, 0, sizeof(saf_mem_err_detect_info_t));
            (void)SAF_MEMU_DetectAllErr(SAF_MEM_PRAM, &sbcPramInfo);
            SAF_MEMU_CleanAllErr(SAF_MEM_PRAM);

            pramStatus = SAF_RAM_AccessRamSbcReadCheck(SAF_MEM_PRAM, &sbcPramInfo, addr);
        }

        if ((sramStatus == FS_STATUS_SUCCESS) && (pramStatus == FS_STATUS_SUCCESS))
        {
            status = FS_STATUS_SUCCESS;
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function shall be used to execute two accesses to the SRAM within the FTTI.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     accesses operation succeed
*               FS_STATUS_ERROR       accesses operation failed
****************************************************************************************
*/
SAF_RAM_SEC_CODE
FS_STATUS SAF_RAM_FTTICheck(uint32_t unusedAddr)
{
    uint32_t data = SAF_RAM_FTTI_CHECK_WRITE_DATA;
    FS_STATUS status = FS_STATUS_ERROR;

    if(NULL != (uint32_t*)unusedAddr)
    {
        /* Write data. */
        *((volatile uint32_t *)(unusedAddr)) = (uint32_t)data;/* polyspace RTE:IDP */
        status = SAF_ReadBackCompare(*((volatile uint32_t *)(unusedAddr)), data, CMPVALUE_UNSIGNED_INT_MASK);/* polyspace RTE:NIV,IDP */
    }

    return status;

}

/**
****************************************************************************************
* @brief:  This function is used to test ITCM ECC error report path.
* @param[in]    pParam    test input (inject ITCM error type: single bit type or multi bit type).
* @param[out]   pResult   test result.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     ITCM ECC error report path test succeed
*               FS_STATUS_ERROR       ITCM ECC error report path test failed
****************************************************************************************
*/
SAF_RAM_SEC_CODE
FS_STATUS SAF_RAM_ItcmEccReportPathTest(const saf_ram_test_object_t *pParam, saf_ram_ecc_report_path_test_result_t *pResult)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
#if SAF_ITCM_SUPPORTED
    FS_STATUS singleStatus = FS_STATUS_SUCCESS, mulitiStatus = FS_STATUS_SUCCESS;
    FS_STATUS itcmFccuStatus = FS_STATUS_SUCCESS;
    SAF_MEM_ERR_TYPE itcmErrType;
    saf_ram_inject_bit_type_t eccInjectParam;
    uint8_t i;
    uint32_t sramEccAddr = (uint32_t)&sramTest[0];
    uint32_t sramEccSize = sizeof(sramTest) / sizeof(sramTest[0]);
#if SAF_DCACHE_SUPPORTED
    bool DCacheStatus = (bool)false;
#endif
#if SAF_ICACHE_SUPPORTED
    bool ICacheStatus = (bool)false;
#endif

    SAF_FCCU_CopyUninitChannelConfig(&fccuSramEccStartUpCfg, realSramEccFccuRfCfg, fccSramEccStartUpRfCfg, MEMU_RAM_CE, 3);

    /* check fccu status */
    if (fccuSramEccStartUpCfg.rfConfigNumber > 0)
    {
    	SAF_FCCU_ClearAllChannelFault();
    	itcmFccuStatus = SAF_FCCU_HardwareInit(&fccuSramEccStartUpCfg, realSramEccFccuRfCfg);
    }
#if SAF_DCACHE_SUPPORTED
    DCacheStatus = SAF_CACHE_AccessDcacheIsEnabled();
    SAF_CACHE_AccessDisableDcache();
#endif
#if SAF_ICACHE_SUPPORTED
    ICacheStatus = SAF_CACHE_AccessIcacheIsEnabled();
    SAF_CACHE_AccessDisableIcache();
#endif
    do
    {
        (void)MEMU_LLD_Reset();
        SAF_MEM_ErrorReportInit(SAF_MEM_ITCM);
        eccInjectParam.ramType = SAF_MEM_ITCM;

        if (pParam->itcmMultiBit)
        {
            pResult->testPassed.itcmMultiBit = (bool)false;
            eccInjectParam.injectBitType = SAF_MEM_UCE_BIT_ERR;

            mulitiStatus = SAF_RAM_InjectBitError(eccInjectParam);

            if (FS_STATUS_SUCCESS == mulitiStatus)
            {
                mulitiStatus = SAF_MEM_GetEccErrorResult(SAF_MEM_ITCM, s_sysramUCETestParamAddress, &itcmErrType);
                if (FS_STATUS_SUCCESS == mulitiStatus)
                {
                    if (SAF_MEM_UCE_BIT_ERR == itcmErrType)
                    {
                        pResult->testPassed.itcmMultiBit = (bool)true;
                    }
                    else
                    {
                        mulitiStatus = FS_STATUS_RAM_INJECTION_FAILED;
                    }
                }
            }
        }

        (void)MEMU_LLD_Reset();

        if (pParam->itcmSingleBit)
        {
            pResult->testPassed.itcmSingleBit = (bool)false;
            eccInjectParam.injectBitType = SAF_MEM_CE_BIT_ERR;
            sramitcmTestFlag = RAM_SAFETY_OP_INITIAL;

            singleStatus = SAF_RAM_InjectBitError(eccInjectParam);

            if (FS_STATUS_SUCCESS == singleStatus)
            {
                for(i = 0U; i < MEMU_SYSRAM_CORRECTABLE_ERROR_TABLE_NUM; i++)
                {
                    singleStatus = SAF_MEM_GetEccErrorResult(SAF_MEM_ITCM, s_sysramCETestParamAddressList[i], &itcmErrType);
                    if(FS_STATUS_SUCCESS != singleStatus)
                    {
                        break;
                    }
                }

                if (FS_STATUS_SUCCESS == singleStatus)
                {
                    if (SAF_MEM_CE_BIT_ERR == itcmErrType)
                    {
                        pResult->testPassed.itcmSingleBit = (bool)true;
                    }
                    else
                    {
                        singleStatus = FS_STATUS_RAM_INJECTION_FAILED;
                    }
                }
            }
        }

        (void)MEMU_LLD_Reset();

    } while(0);
#if SAF_DCACHE_SUPPORTED
    if (DCacheStatus == true)/*PRQA S 1881*/
    {
    	SAF_CACHE_AccessEnableDcache();
    }
#endif
#if SAF_ICACHE_SUPPORTED
    if (ICacheStatus == true)/*PRQA S 1881*/
    {
    	SAF_CACHE_AccessEnableIcache();
    }
#endif
    if ((singleStatus == FS_STATUS_SUCCESS) && (mulitiStatus == FS_STATUS_SUCCESS))
    {
        status =  FS_STATUS_SUCCESS;
    }
    else
    {
        if (singleStatus != FS_STATUS_SUCCESS)
        {
            pResult->testPassed.sramSingleBit = (bool)false;
        }

        if (mulitiStatus != FS_STATUS_SUCCESS)
        {
            pResult->testPassed.sramMultiBit = (bool)false;
        }
        status = FS_STATUS_SRAM_ECC_REPROT_TEST_FAILED;
    }

    if (itcmFccuStatus != FS_STATUS_SUCCESS)
    {
    	status = FS_STATUS_ERROR;
    }
    (void)SetupE2EECSR0_for_ClearECC(sramEccAddr, sramEccSize);
#else
    (void)pParam;
    (void)pResult;
    status = FS_STATUS_INVALID;
#endif
    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to test ITCM ECC error report path.
* @param[in]    pParam    test input (inject SRAM error type: single bit type or multi bit type).
* @param[out]   pResult   test result.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     SRAM ECC error report path test succeed
*               FS_STATUS_ERROR       SRAM ECC error report path test failed
****************************************************************************************
*/
SAF_RAM_SEC_CODE
FS_STATUS SAF_RAM_ITCMEccReportPathTest(void)
{
    FS_STATUS status = FS_STATUS_ERROR;
    FS_STATUS itcmStatus = FS_STATUS_ERROR;
    FS_STATUS switchStatus = FS_STATUS_SUCCESS;
    uint32_t switchOn = 1;
    uint32_t switchOff = 0;
    saf_ram_ecc_report_path_test_result_t *pResult = &s_ramEccCheckTest.output;

    if (FS_STATUS_SUCCESS != (FS_STATUS)SAF_FCCU_LLD_StartupCallbackSwitch(switchOn))
    {
    	switchStatus = FS_STATUS_ERROR;
    }

    itcmStatus = SAF_RAM_ItcmEccReportPathTest(&s_ramEccConfigSet, pResult);

    if (FS_STATUS_SUCCESS != (FS_STATUS)SAF_FCCU_LLD_StartupCallbackSwitch(switchOff))
    {
    	switchStatus = FS_STATUS_ERROR;
    }

    if (itcmStatus == FS_STATUS_SUCCESS)/*PRQA S 2992,2996*/
    {
        status = FS_STATUS_SUCCESS;
    }
    if (switchStatus == FS_STATUS_ERROR)
    {
    	status = FS_STATUS_ERROR;
    }
    return status;
}

/**
****************************************************************************************
* @brief:  This function shall be used to read back from Platform RAM Configuration Register.
*          This register is accessible only in supervisor mode. Accesses in user mode return a transfer error.
* @return       uint32_t   platform RAM configuration register value
****************************************************************************************
*/
SAF_RAM_SEC_CODE
uint32_t SAF_RAM_PRAMCReadBack(void)
{
    /* Platform RAM Configuration Register */
    return PRAMC.PRCR1.R;
}

#ifdef __cplusplus
}
#endif
/*******************************************************************************
 * EOF
 ******************************************************************************/
