/**
****************************************************************************************
 * @FilePath: SafetyFccuTst_Cfg.c
 * @Author: CCORE
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety FCCU configuration C File
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
#include "SafetyFccuTst_Cfg.h"
#include "saf_userservice_callback.h"
#include "saf_sch.h"
#include "saf_flash.h"/*PRQA S 0380*/
#include "saf_fccu.h"
#include "memu_lld.h"
#include "Saf_MemMap.h"
/* PRQA S 0704, 0753, 1533, 3408, 4322, 4304 EOF*/
/**
****************************************************************************************
 * @brief: Function declaration
****************************************************************************************
*/
                                          
/**
****************************************************************************************
 * @brief: Structs
****************************************************************************************
*/

   
   

/* FCCU test call back */
SAF_FCCU_SEC_CONFIG_DATA
const call_config_t s_fccuCallSet =
{

    /* Fccu notification function */
    .callback       = NULL,
    /* Fccu notification function parameter */
    .callbackParam  = NULL

};

   
   

/* FCCU cfg call back */
SAF_FCCU_SEC_CONFIG_DATA
const call_config_t s_fccuCfgCallSet =
{

    /* Fccu cfg notification function */
    .callback       = NULL,
    /* Fccu cfg notification function parameter */
    .callbackParam  = NULL

};

#ifdef CCFC3012PT

/* FCCU recoverable faults configurations */
SAF_FCCU_SEC_CONFIG_DATA
const fccu_rf_config_t fccRfCfg[] = {
    
    {
        /* FCCU Channel ID */
        .channel        = (uint8_t)SAF_FCCU_FAILURE_MEMORY_DCF_SAFETY_ERR_CH_4,
        /* FCCU recoverable fault definitions */
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        /* FCCU recoverable fault state definitions */
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_SHORT_RESET,
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
        .channel        = (uint8_t)SAF_FCCU_FAILURE_SSCM_XFER_FLASH_ERR_CH_5,
        /* FCCU recoverable fault definitions */
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        /* FCCU recoverable fault state definitions */
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_SHORT_RESET,
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
        .channel        = (uint8_t)SAF_FCCU_FAILURE_STCU_UF_CH_6,
        /* FCCU recoverable fault definitions */
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        /* FCCU recoverable fault state definitions */
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_SHORT_RESET,
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
        .channel        = (uint8_t)SAF_FCCU_FAILURE_STCU_LMBIST_USR_ERR_CH_8,
        /* FCCU recoverable fault definitions */
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        /* FCCU recoverable fault state definitions */
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_LONG_RESET,
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
        .channel        = (uint8_t)SAF_FCCU_FAILURE_SPURIOUS_DEBUG_SSCM_ACTIVATION_CH_9,
        /* FCCU recoverable fault definitions */
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        /* FCCU recoverable fault state definitions */
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_LONG_RESET,
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
        .channel        = (uint8_t)SAF_FCCU_FAILURE_SWT1_INTERRUPT_REQ_CH_12,
        /* FCCU recoverable fault definitions */
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        /* FCCU recoverable fault state definitions */
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_SHORT_RESET,
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
        .channel        = (uint8_t)SAF_FCCU_FAILURE_SWT1_RESET_REQ_CH_13,
        /* FCCU recoverable fault definitions */
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        /* FCCU recoverable fault state definitions */
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_SHORT_RESET,
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
        .channel        = (uint8_t)SAF_FCCU_FAILURE_SWT0_INTERRUPT_REQ_CH_14,
        /* FCCU recoverable fault definitions */
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        /* FCCU recoverable fault state definitions */
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_SHORT_RESET,
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
        .channel        = (uint8_t)SAF_FCCU_FAILURE_SWT0_RESET_REQ_CH_15,
        /* FCCU recoverable fault definitions */
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        /* FCCU recoverable fault state definitions */
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_SHORT_RESET,
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
        .channel        = (uint8_t)SAF_FCCU_FAILURE_GTM_CMP_ERR_CH_28,
        /* FCCU recoverable fault definitions */
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        /* FCCU recoverable fault state definitions */
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_LONG_RESET,
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
        .channel        = (uint8_t)SAF_FCCU_FAILURE_CMU_0_OSC_CH_31,
        /* FCCU recoverable fault definitions */
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        /* FCCU recoverable fault state definitions */
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_SHORT_RESET,
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
        .channel        = (uint8_t)SAF_FCCU_FAILURE_CMU_0_PLL_CH_32,
        /* FCCU recoverable fault definitions */
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        /* FCCU recoverable fault state definitions */
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_SHORT_RESET,
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
        .channel        = (uint8_t)SAF_FCCU_FAILURE_CMU_COMP_SUBSYS_CH_33,
        /* FCCU recoverable fault definitions */
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        /* FCCU recoverable fault state definitions */
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_SHORT_RESET,
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
        .channel        = (uint8_t)SAF_FCCU_FAILURE_CMU_OTHER_CH_34,
        /* FCCU recoverable fault definitions */
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        /* FCCU recoverable fault state definitions */
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_SHORT_RESET,
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
        .channel        = (uint8_t)SAF_FCCU_FAILURE_CMU_1_PLL_CH_71,
        /* FCCU recoverable fault definitions */
        .hwSw_recovery  = (SAF_fccu_rf_setting_t)SAF_FCCU_RF_SW_RECOVERABLE_FAULT,
        /* FCCU recoverable fault state definitions */
        .reset          = (SAF_fccu_rfs_setting_t)SAF_FCCU_RFS_SHORT_RESET,
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
#else
SAF_FCCU_SEC_CONFIG_DATA
const fccu_rf_config_t fccRfCfg[] = {
    
    {
        /* FCCU Channel ID */
        .channel        = (uint8_t)SAF_FCCU_FAILURE_TEMP_ERROR_CH_0,
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
#endif


/* FCCU module configuration */
SAF_FCCU_SEC_CONFIG_DATA
const fccu_config_t fccuCfg=
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
                            .set_after_reset = (bool)false, // CYH: disable error pin temporarily,
                            /* EOUT control definitions */
                            .control         = (SAF_fccu_ep_control_t)SAF_FCCU_EP_INDEPENDENT_ABOVE_SW,
                            /* FCCU EOUT output definitions */
                            .output          = (SAF_fccu_ep_output_t)SAF_FCCU_EP_OUTPUT_OPEN_DRAIN,
                            /* FCCU EOUT frequency configurations */
                            #if (defined(RESOURCE_SUPPORT_FCCU_EOUT_FREQ) | defined(RESOURCE_SUPPORT_FCCU_EOUT_FREQ_EXT))
                            #ifdef RESOURCE_SUPPORT_FCCU_EOUT_FREQ_EXT
                            .fop_ext         = (SAF_fccu_eout_fop_ext_t)SAF_FCCU_EOUT_FOP_EXT_61HZ,
                            .fop             = (SAF_fccu_eout_fop_t)SAF_FCCU_EOUT_FOP_30_5_EXT_LT_122HZ,
                            .eof             = (SAF_fccu_eout_eof_t)SAF_FCCU_EOUT_EOF_LOWFREQ,
                            #else
                            .fop             = (SAF_fccu_eout_fop_t)SAF_FCCU_EOUT_FOP_VARIABLE,
                            .eof             = (SAF_fccu_eout_eof_t)SAF_FCCU_EOUT_EOF_61HZ,
                            #endif
                            #endif /* RESOURCE_SUPPORT_FCCU_EOUT_FREQ_EXT | RESOURCE_SUPPORT_FCCU_EOUT_FREQ */
                            /* FCCU EOUT protocol definitions */
                            .switch_mode     = (SAF_fccu_eout_sm_t)SAF_FCCU_EOUT_PROTOCOL_SLOW_SM,
                            /* FCCU EOUT polar select definitions */
                            .polarity_sel    = (SAF_fccu_eout_ps_t)SAF_FCCU_EOUT_0_LOW_1_HIGH,
                            /* Fault Output Mode selection */
                            .mode            = (SAF_fccu_eout_fom_t)SAF_FCCU_FOM_BI_STABLE,
                            /* Pin is set to the minimum time of failure state */
                            .delta_t_value   = 0U,
                            },
    /* Configuration time-out interrupt enabled */
    .irq_type             = (SAF_fccu_irq_type_t)SAF_FCCU_IRQ_CFG_TO_IEN,
    /* The preset value of the watchdog timer for the recovery from the CONFIG state. */
    .cfg_timeout          = 0,
    /* FCCU lock type definitions */
    .lock_type            = (SAF_fccu_lock_type_t)SAF_FCCU_TRANSIENTLY_UNLOCK,
    /* The number of configured FCCU channels */
    .rfConfigNumber       = (uint8_t)(sizeof(fccRfCfg)/sizeof(fccRfCfg[0])),
    /* time-out notification function */
    .callbackFunc         = NULL_PTR,
    /* The parameters of the time-out notification function */
    .callbackParam        = NULL_PTR
};



#ifdef __cplusplus
}
#endif
