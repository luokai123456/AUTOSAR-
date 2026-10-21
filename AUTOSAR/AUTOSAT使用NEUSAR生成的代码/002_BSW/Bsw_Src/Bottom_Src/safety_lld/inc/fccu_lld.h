/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     fccu_lld.h
* @version  1.0
* @date     2023 - 04 - 24
* @brief    Initial version.
* @MCAL 	Version: 3.0.1
* @Safety 	Version: 3.0.0
*
*****************************************************************************/

#ifndef FCCU_LLD_H
#define FCCU_LLD_H

#include "status.h"
#include "derivative.h"
#include "Mcu_Cfg.h"

/* FCCU Operation Timeout definition */
#define SAF_FCCU_OP_TIMEOUT_CONFIG      0xFFFFFFFFU

#define SAF_FCCU_MAX_FAULTS_NO          128U

#define SAF_FCCU_RF_MAX_GROUP           4U

/* Control register key macros */
#define SAF_FCCU_RECOVERABLE_FAULT_KEY  0xAB3498FEU
#define SAF_FCCU_UNLOCK_OP1_KEY         0x913756AFU
#define SAF_FCCU_UNLOCK_OP2_KEY         0x825A132BU

/* Transition Unlocking Key value */
#define SAF_FCCU_TRANSKEY_UNLOCK_VAL    0xBCU
#define SAF_FCCU_TRANSKEY_LOCK_VAL      0xFFU

/* Transition Locking Key value */
#define SAF_FCCU_PERMENTKEY_LOCK_VAL    0xFFU


#define SAF_FCCU_RF_MAX_GROUP           4U


#if MCU_FCCU_ENABLE == STD_OFF/* PRQA S 3332 */
/*
 * @brief fccu failure inputs definitions
 */
typedef enum {
    FCCU_FAILURE_TEMP_ERROR_CH_0                           = 0U,
    FCCU_FAILURE_LVD_ERROR_CH_1                            = 1U,
    FCCU_FAILURE_HVD_ERROR_CH_2                            = 2U,
    FCCU_FAILURE_DPMC_DCF_SAFETY_ERR_CH_3                  = 3U,
    FCCU_FAILURE_MEMORY_DCF_SAFETY_ERR_CH_4                = 4U,
    FCCU_FAILURE_SSCM_XFER_FLASH_ERR_CH_5                  = 5U,
    FCCU_FAILURE_STCU_UF_CH_6                              = 6U,
    FCCU_FAILURE_STCU_RF_CH_7                              = 7U,
    FCCU_FAILURE_STCU_LMBIST_USR_ERR_CH_8                  = 8U,
    FCCU_FAILURE_SPURIOUS_DEBUG_SSCM_ACTIVATION_CH_9       = 9U,
    FCCU_FAILURE_RCCU_O_CH_10                              = 10U,
    FCCU_FAILURE_RCCU_1_CH_11                              = 11U,
#if (defined(CCFC3012PT) | defined(CCFC3011PT) | defined(CCFC3010PT))
    FCCU_FAILURE_SWT1_INTERRUPT_REQ_CH_12                  = 12U,
#elif (defined(CCFC3008PCSN) | defined(CCFC3008PC))
#else
    FCCU_FAILURE_SWT2_RESET_REQ_CH_12                      = 12U,
#endif
#if !(defined(CCFC3008PCSN) | defined(CCFC3008PC))
    FCCU_FAILURE_SWT1_RESET_REQ_CH_13                      = 13U,
#endif
    FCCU_FAILURE_SWT0_INTERRUPT_REQ_CH_14                  = 14U,
    FCCU_FAILURE_SWT0_RESET_REQ_CH_15                      = 15U,
    FCCU_FAILURE_MEMU_RAM_CE_CH_16                         = 16U,
    FCCU_FAILURE_MEMU_RAM_UCE_CH_17                        = 17U,
    FCCU_FAILURE_MEMU_RAM_BOV_CH_18                        = 18U,
    FCCU_FAILURE_MEMU_PER_CE_CH_19                         = 19U,
    FCCU_FAILURE_MEMU_PER_UCE_CH_20                        = 20U,
    FCCU_FAILURE_MEMU_PER_BOV_CH_21                        = 21U,
    FCCU_FAILURE_MEMU_FLS_CE_CH_22                         = 22U,
    FCCU_FAILURE_MEMU_FLS_UCE_CH_23                        = 23U,
    FCCU_FAILURE_MEMU_FLS_BOV_CH_24                        = 24U,
    FCCU_FAILURE_MEMU_IMA_SOC_CH_25                        = 25U,
    FCCU_FAILURE_SMPU_MONITOR_CH_26                        = 26U,
	FCCU_FAILURE_GTM_CMP_ERR_CH_28                         = 28U,
    FCCU_FAILURE_FM_PLL_0_CH_29                            = 29U,
    FCCU_FAILURE_FM_PLL_1_CH_30                            = 30U,
    FCCU_FAILURE_CMU_0_OSC_CH_31                           = 31U,
    FCCU_FAILURE_CMU_0_PLL_CH_32                           = 32U,
    FCCU_FAILURE_CMU_COMP_SUBSYS_CH_33                     = 33U,
    FCCU_FAILURE_CMU_OTHER_CH_34                           = 34U,
    FCCU_FAILURE_PERIPH_XBIC_GASKET_MONITOR_CH_35          = 35U,
    FCCU_FAILURE_EDC_ECC_FLASH_CH_36                       = 36U,
    FCCU_FAILURE_EDC_ECC_FLASH_C_CH_37                     = 37U,
    FCCU_FAILURE_ENC_ERR_FLASH_CH_38                       = 38U,
    FCCU_FAILURE_ADDR_FDBK_ERR_FLASH_C_CH_39               = 39U,
    FCCU_FAILURE_COMP_XBIC_DSMC_MONITOR_CH_40              = 40U,
    FCCU_FAILURE_ADDR_FDBK_ERR_CAL_RAM_CH_41               = 41U,
    FCCU_FAILURE_SAFE_CAL_ERR_CH_42                        = 42U,
    FCCU_FAILURE_ADDR_FDB_ERR_PRAM_RAM_LWB_ERR_CH_43       = 43U,
    FCCU_FAILURE_SMPU_ERRPR_CH_44                          = 44U,
    FCCU_FAILURE_EDC_ERR_PRAM_CH_45                        = 45U,
    FCCU_FAILURE_DFT1_CH_46                                = 46U,
    FCCU_FAILURE_DFT2_CH_47                                = 47U,
    FCCU_FAILURE_DFT3_CH_48                                = 48U,
    FCCU_FAILURE_DFT4_CH_49                                = 49U,
    FCCU_FAILURE_SAFETY_CORE_MACHINE_CHECK_EXCEPTION_CH_50 = 50U,
#if (defined(CCFC3012PT) | defined(CCFC3011PT) | defined(CCFC3010PT))
    FCCU_FAILURE_LOCKSTEP0_MODE_CH_51                      = 51U,
#else
    FCCU_FAILURE_LOCKSTEP_MODE_CH_51                       = 51U,
#endif
    FCCU_FAILURE_SAFE_MODE_CH_52                           = 52U,
    FCCU_FAILURE_COMPENSATION_DISABLE_CH_53                = 53U,
    FCCU_FAILURE_EIN_ERR_CH_54                             = 54U,
    FCCU_FAILURE_SWT3_RESET_REQ_CH_55                      = 55U,
#if (defined(CCFC3012PT) | defined(CCFC3011PT) | defined(CCFC3010PT))
    FCCU_FAILURE_LOCKSTEP1_MODE_CH_56                      = 56U,
    FCCU_FAILURE_LOCKSTEP2_MODE_CH_57                      = 57U,
    FCCU_FAILURE_LOCKSTEP2_MODE_CH_58                      = 58U,
    FCCU_FAILURE_RCCU1_0_CH_59                             = 59U,
    FCCU_FAILURE_RCCU2_0_CH_60                             = 60U,
    FCCU_FAILURE_RCCU3_0_CH_61                             = 61U,
    FCCU_FAILURE_RCCU1_1_CH_62                             = 62U,
    FCCU_FAILURE_RCCU2_1_CH_63                             = 63U,
    FCCU_FAILURE_RCCU3_1_CH_64                             = 64U,
    FCCU_FAILURE_SWT2_INTERRUPT_REQ_CH_65                  = 65U,
    FCCU_FAILURE_SWT2_RESET_REQ_CH_66                      = 66U,
    FCCU_FAILURE_SWT4_INTERRUPT_REQ_CH_67                  = 67U,
    FCCU_FAILURE_SWT4_RESET_REQ_CH_68                      = 68U,
    FCCU_FAILURE_SWT5_RESET_REQ_CH_69                      = 69U,
    FCCU_FAILURE_SWT6_RESET_REQ_CH_70                      = 70U,
    FCCU_FAILURE_CMU_1_PLL_CH_71                           = 71U,
    FCCU_FAILURE_INTC_MON_ERR_0_CH_72                      = 72U,
    FCCU_FAILURE_INTC_MON_ERR_1_CH_73                      = 73U,
    FCCU_FAILURE_INTC_MON_ERR_2_CH_74                      = 74U,
    FCCU_FAILURE_INTC_MON_ERR_3_CH_75                      = 75U,
    FCCU_FAILURE_INTC_MON_ERR_4_CH_76                      = 76U,
    FCCU_FAILURE_INTC_MON_ERR_5_CH_77                      = 77U,
    FCCU_FAILURE_INTC_MON_ERR_6_CH_78                      = 78U,
    FCCU_FAILURE_INTC_MON_ERR_7_CH_79                      = 79U,
    FCCU_FAILURE_INTC_MON_ERR_8_CH_80                      = 80U,
    FCCU_FAILURE_INTC_MON_ERR_9_CH_81                      = 81U,
    FCCU_FAILURE_INTC_MON_ERR_10_CH_82                     = 82U,
    FCCU_FAILURE_INTC_MON_ERR_11_CH_83                     = 83U,
    FCCU_FAILURE_INTC_MON_ERR_12_CH_84                     = 84U,
    FCCU_FAILURE_INTC_MON_ERR_13_CH_85                     = 85U,
    FCCU_FAILURE_INTC_MON_ERR_14_CH_86                     = 86U,
    FCCU_FAILURE_INTC_MON_ERR_15_CH_87                     = 87U,
    FCCU_FAILURE_GMAC_RECEIVE_DATA_ERROR_CH_88             = 88U,
    FCCU_FAILURE_AXBS0_TIMEOUT_CH_89                       = 89U,
    FCCU_FAILURE_AXBS1_TIMEOUT_CH_90                       = 90U,
    FCCU_FAILURE_AXBS2_TIMEOUT_CH_91                       = 91U,
    FCCU_FAILURE_TCM0_AXBS_TIMEOUT_CH_92                   = 92U,
    FCCU_FAILURE_CANFD1_SAFE_ERR_CH_93                     = 93U,
    FCCU_FAILURE_CANFD9_SAFE_ERR_CH_94                     = 94U,
#elif (defined(CCFC3008PC) | defined(CCFC3008PCSN))
    FCCU_FAILURE_GTM_CMP_ERR_CH_56                         = 56U,
    FCCU_FAILURE_AXBS_P2_TIMEOUT_CH_57                     = 57U,
    FCCU_FAILURE_AXBS_P3_TIMEOUT_CH_58                     = 58U,
    FCCU_FAILURE_INTC_MON_ERR_0_CH_59                      = 59U,
	FCCU_FAILURE_INTC_MON_ERR_1_CH_60                      = 60U,
	FCCU_FAILURE_INTC_MON_ERR_2_CH_61                      = 61U,
#elif (defined(CCFC3007BC))
    FCCU_FAILURE_PERIPHERAL_BUS_TIMEOUT_CH_56              = 56U,
    FCCU_FAILURE_SYSTEM_BUS_TIMEOUT_CH_57                  = 57U,
    FCCU_FAILURE_INT_A_ACK_TIMEOUT_OF_CPU0_CH_58           = 58U,
    FCCU_FAILURE_INT_B_ACK_TIMEOUT_OF_CPU0_CH_59           = 59U,
    FCCU_FAILURE_INT_C_ACK_TIMEOUT_OF_CPU0_CH_60           = 60U,
    FCCU_FAILURE_INT_A_ACK_TIMEOUT_OF_CPU1_CH_62           = 62U,
    FCCU_FAILURE_INT_B_ACK_TIMEOUT_OF_CPU1_CH_63           = 63U,
    FCCU_FAILURE_INT_C_ACK_TIMEOUT_OF_CPU1_CH_64           = 64U,
    FCCU_FAILURE_INT_A_ACK_TIMEOUT_OF_CPU2_CH_66           = 66U,
    FCCU_FAILURE_INT_B_ACK_TIMEOUT_OF_CPU2_CH_67           = 67U,
    FCCU_FAILURE_INT_C_ACK_TIMEOUT_OF_CPU2_CH_68           = 68U,
    FCCU_FAILURE_FEC_WDATA_PERR_CH_74                      = 74U
#elif (defined(CCFC3007PT))
#else
#endif
} fccu_failure_inputs_t;/* PRQA S 1535 */

/*
 * @brief FCCU filter width definition
 */
typedef enum
{
    FCCU_FILTER_GILTCHES_50US  = 0U,    /* filters glitches up to 50 us */
    FCCU_FILTER_GILTCHES_75US  = 1U,    /* filters glitches up to 75 us */
    FCCU_FILTER_GILTCHES_100US = 2U,    /* filters glitches up to 100 us */
} fccu_filter_width_t; /* PRQA S 1535 */

/*
 * @brief FCCU operation run definition
 */
typedef enum {
    FCCU_RUN_OP0  = 0U,     /* No operation */
    FCCU_RUN_OP1  = 1U,     /* Set the FCCU into the CONFIG state */
    FCCU_RUN_OP2  = 2U,     /* Set the ECCU into the NORMAL state */
    FCCU_RUN_OP3  = 3U,     /* Read the FCCU state */
    FCCU_RUN_OP4  = 4U,     /* Read the FCCU frozen status flags - N2AF_STATUS */
    FCCU_RUN_OP5  = 5U,     /* Read the FCCU frozen status flags - A2FF_STATUS */
    FCCU_RUN_OP6  = 6U,     /* Read the FCCU frozen status flags - N2FF_STATUS */
    FCCU_RUN_OP7  = 7U,     /* Read the FCCU frozen status flags - F2AF_STATUS */
    FCCU_RUN_OP10 = 10U,    /* Read the RF status register */
    FCCU_RUN_OP12 = 12U,    /* RF status clear operation in progress */
    FCCU_RUN_OP13 = 13U,    /* Clear the freeze status register */
    FCCU_RUN_OP14 = 14U,    /* CONFIG to NORMAL FCCU state (configuration timeout) in progress */
    FCCU_RUN_OP15 = 15U,    /* Clear the operation status (OPS=idle) */
    FCCU_RUN_OP17 = 17U,    /* Read the ALARM timer */
    FCCU_RUN_OP19 = 19U,    /* Read the CFG timer */
    FCCU_RUN_OP20 = 20U,    /* Read the Error Pin low counter value */
} fccu_op_run_t;/* PRQA S 1535 */

/*
 * @brief FCCU operation status definition
 */
typedef enum
{
	FCCU_OPS_IDLE        = 0U,    /* idle */
	FCCU_OPS_IN_PROGRESS = 1U,    /* in progress */
	FCCU_OPS_ABORTED     = 2U,    /* aborted */
	FCCU_OPS_SUCCESSFUL  = 3U     /* successful */
} fccu_op_status_t; /* PRQA S 1535 */

/*
 * @brief FCCU status definitions
 */
typedef enum {
    FCCU_NORMAL_STATE  = 0U,
    FCCU_CONFIG_STATE  = 1U,
    FCCU_ALARM_STATE   = 2U,
    FCCU_FAULT_STATE   = 3U,
    FCCU_UNKNOWN_STATE = 4U,
} fccu_status_t;


/*
 * @brief FCCU frozen status definitions
 */
typedef enum {
    FCCU_FROZEN_N2AF_STATUS = 0U,
    FCCU_FROZEN_A2FF_STATUS = 1U,
    FCCU_FROZEN_N2FF_STATUS = 2U,
    FCCU_FROZEN_F2AF_STATUS = 3U
} fccu_frozen_type_t;/* PRQA S 1535 */


/*
 * @brief FCCU XTMR type definitions
 */
typedef enum {
    FCCU_XTMR_ALARM = 0U,
    FCCU_XTMR_CFG   = 1U,
    FCCU_XTMR_ETMR  = 2U
} fccu_xtmr_type_t;/* PRQA S 1535 */

/*
 * @brief FCCU INT source definitions
 */
typedef enum {
    FCCU_INT_TIMEOUT = 0U,
    FCCU_INT_ALARM   = 1U,
    FCCU_INT_NMI     = 2U,
} fccu_int_status_t;/* PRQA S 1535 */


/*
 * @brief Fault State Flags for Recoverable Faults
 */
typedef struct /* PRQA S 3630 */
{
    uint32 faultsFlags[SAF_FCCU_RF_MAX_GROUP]; /*!< Faults Flags */
} fccu_faults_flags_t;

#endif
/*
 * @brief fccu failure inputs definitions
 */
typedef enum {
    SAF_FCCU_FAILURE_TEMP_ERROR_CH_0                           = 0U,
	SAF_FCCU_FAILURE_LVD_ERROR_CH_1                            = 1U,
	SAF_FCCU_FAILURE_HVD_ERROR_CH_2                            = 2U,
	SAF_FCCU_FAILURE_DPMC_DCF_SAFETY_ERR_CH_3                  = 3U,
	SAF_FCCU_FAILURE_MEMORY_DCF_SAFETY_ERR_CH_4                = 4U,
	SAF_FCCU_FAILURE_SSCM_XFER_FLASH_ERR_CH_5                  = 5U,
#ifndef CCFC3008PT
    SAF_FCCU_FAILURE_STCU_UF_CH_6                              = 6U,
    SAF_FCCU_FAILURE_STCU_RF_CH_7                              = 7U,
    SAF_FCCU_FAILURE_STCU_LMBIST_USR_ERR_CH_8                  = 8U,
#endif
	SAF_FCCU_FAILURE_SPURIOUS_DEBUG_SSCM_ACTIVATION_CH_9       = 9U,
	SAF_FCCU_FAILURE_RCCU_O_CH_10                              = 10U,
	SAF_FCCU_FAILURE_RCCU_1_CH_11                              = 11U,
#if defined(CCFC3007PT) || defined(CCFC3008PT) || defined(CCFC3007BC)
    SAF_FCCU_FAILURE_SWT2_RESET_REQ_CH_12                      = 12U,
    SAF_FCCU_FAILURE_SWT1_RESET_REQ_CH_13                      = 13U,
#elif defined(CCFC3012PT)
	SAF_FCCU_FAILURE_SWT1_INTERRUPT_REQ_CH_12                  = 12U,
    SAF_FCCU_FAILURE_SWT1_RESET_REQ_CH_13                      = 13U,
#else
#endif
	SAF_FCCU_FAILURE_SWT0_INTERRUPT_REQ_CH_14                  = 14U,
	SAF_FCCU_FAILURE_SWT0_RESET_REQ_CH_15                      = 15U,
	SAF_FCCU_FAILURE_MEMU_RAM_CE_CH_16                         = 16U,
	SAF_FCCU_FAILURE_MEMU_RAM_UCE_CH_17                        = 17U,
	SAF_FCCU_FAILURE_MEMU_RAM_BOV_CH_18                        = 18U,
	SAF_FCCU_FAILURE_MEMU_PER_CE_CH_19                         = 19U,
	SAF_FCCU_FAILURE_MEMU_PER_UCE_CH_20                        = 20U,
	SAF_FCCU_FAILURE_MEMU_PER_BOV_CH_21                        = 21U,
	SAF_FCCU_FAILURE_MEMU_FLS_CE_CH_22                         = 22U,
	SAF_FCCU_FAILURE_MEMU_FLS_UCE_CH_23                        = 23U,
	SAF_FCCU_FAILURE_MEMU_FLS_BOV_CH_24                        = 24U,
	SAF_FCCU_FAILURE_MEMU_IMA_SOC_CH_25                        = 25U,
	SAF_FCCU_FAILURE_SMPU_MONITOR_CH_26                        = 26U,
#if defined(CCFC3012PT)
    SAF_FCCU_FAILURE_GTM_CMP_ERR_CH_28                         = 28U,
#endif
	SAF_FCCU_FAILURE_FM_PLL_0_CH_29                            = 29U,
	SAF_FCCU_FAILURE_FM_PLL_1_CH_30                            = 30U,
	SAF_FCCU_FAILURE_CMU_0_OSC_CH_31                           = 31U,
	SAF_FCCU_FAILURE_CMU_0_PLL_CH_32                           = 32U,
	SAF_FCCU_FAILURE_CMU_COMP_SUBSYS_CH_33                     = 33U,
	SAF_FCCU_FAILURE_CMU_OTHER_CH_34                           = 34U,
	SAF_FCCU_FAILURE_PERIPH_XBIC_GASKET_MONITOR_CH_35          = 35U,
	SAF_FCCU_FAILURE_EDC_ECC_FLASH_CH_36                       = 36U,
	SAF_FCCU_FAILURE_EDC_ECC_FLASH_C_CH_37                     = 37U,/* PRQA S 0779 */
	SAF_FCCU_FAILURE_ENC_ERR_FLASH_CH_38                       = 38U,
	SAF_FCCU_FAILURE_ADDR_FDBK_ERR_FLASH_C_CH_39               = 39U,
	SAF_FCCU_FAILURE_COMP_XBIC_DSMC_MONITOR_CH_40              = 40U,
	SAF_FCCU_FAILURE_ADDR_FDBK_ERR_CAL_RAM_CH_41               = 41U,/* PRQA S 0779 */
	SAF_FCCU_FAILURE_SAFE_CAL_ERR_CH_42                        = 42U,
	SAF_FCCU_FAILURE_ADDR_FDB_ERR_PRAM_RAM_LWB_ERR_CH_43       = 43U,
	SAF_FCCU_FAILURE_SMPU_ERRPR_CH_44                          = 44U,
	SAF_FCCU_FAILURE_EDC_ERR_PRAM_CH_45                        = 45U,
	SAF_FCCU_FAILURE_DFT1_CH_46                                = 46U,
	SAF_FCCU_FAILURE_DFT2_CH_47                                = 47U,
	SAF_FCCU_FAILURE_DFT3_CH_48                                = 48U,
	SAF_FCCU_FAILURE_DFT4_CH_49                                = 49U,
	SAF_FCCU_FAILURE_SAFETY_CORE_MACHINE_CHECK_EXCEPTION_CH_50 = 50U,
#if defined(CCFC3012PT)
	SAF_FCCU_FAILURE_LOCKSTEP0_MODE_CH_51                      = 51U,
#else
	SAF_FCCU_FAILURE_LOCKSTEP_MODE_CH_51                       = 51U,
#endif
	SAF_FCCU_FAILURE_SAFE_MODE_CH_52                           = 52U,
	SAF_FCCU_FAILURE_COMPENSATION_DISABLE_CH_53                = 53U,
	SAF_FCCU_FAILURE_EIN_ERR_CH_54                             = 54U,
	SAF_FCCU_FAILURE_SWT3_RESET_REQ_CH_55                      = 55U,
#if defined(CCFC3007BC)
    SAF_FCCU_FAILURE_PERIPHERAL_BUS_TIMEOUT_CH_56              = 56U,
    SAF_FCCU_FAILURE_SYSTEM_BUS_TIMEOUT_CH_57                  = 57U,
    SAF_FCCU_FAILURE_INT_A_ACK_TIMEOUT_OF_CPU0_CH_58           = 58U,
    SAF_FCCU_FAILURE_INT_B_ACK_TIMEOUT_OF_CPU0_CH_59           = 59U,
    SAF_FCCU_FAILURE_INT_C_ACK_TIMEOUT_OF_CPU0_CH_60           = 60U,
    SAF_FCCU_FAILURE_INT_A_ACK_TIMEOUT_OF_CPU1_CH_62           = 62U,
    SAF_FCCU_FAILURE_INT_B_ACK_TIMEOUT_OF_CPU1_CH_63           = 63U,
    SAF_FCCU_FAILURE_INT_C_ACK_TIMEOUT_OF_CPU1_CH_64           = 64U,
    SAF_FCCU_FAILURE_INT_A_ACK_TIMEOUT_OF_CPU2_CH_66           = 66U,
    SAF_FCCU_FAILURE_INT_B_ACK_TIMEOUT_OF_CPU2_CH_67           = 67U,
    SAF_FCCU_FAILURE_INT_C_ACK_TIMEOUT_OF_CPU2_CH_68           = 68U,
    SAF_FCCU_FAILURE_FEC_WDATA_PERR_CH_74                      = 74U,
#elif defined(CCFC3008PC) | defined(CCFC3008PCSN)
    SAF_FCCU_FAILURE_GTM_CMP_ERR_CH_56                         = 56U,
    SAF_FCCU_FAILURE_AXBS_P2_TIMEOUT_CH_57                     = 57U,
    SAF_FCCU_FAILURE_AXBS_P3_TIMEOUT_CH_58                     = 58U,
    SAF_FCCU_FAILURE_INTC_MON_ERR_0_CH_59                      = 59U,
	SAF_FCCU_FAILURE_INTC_MON_ERR_1_CH_60                      = 60U,
	SAF_FCCU_FAILURE_INTC_MON_ERR_2_CH_61                      = 61U,
#elif defined(CCFC3012PT)
	SAF_FCCU_FAILURE_LOCKSTEP1_MODE_CH_56                      = 56U,
	SAF_FCCU_FAILURE_LOCKSTEP2_MODE_CH_57                      = 57U,
	SAF_FCCU_FAILURE_LOCKSTEP2_MODE_CH_58                      = 58U,
	SAF_FCCU_FAILURE_RCCU1_0_CH_59                             = 59U,
	SAF_FCCU_FAILURE_RCCU2_0_CH_60                             = 60U,
	SAF_FCCU_FAILURE_RCCU3_0_CH_61                             = 61U,
	SAF_FCCU_FAILURE_RCCU1_1_CH_62                             = 62U,
	SAF_FCCU_FAILURE_RCCU2_1_CH_63                             = 63U,
	SAF_FCCU_FAILURE_RCCU3_1_CH_64                             = 64U,
	SAF_FCCU_FAILURE_SWT2_INTERRUPT_REQ_CH_65                  = 65U,
	SAF_FCCU_FAILURE_SWT2_RESET_REQ_CH_66                      = 66U,
	SAF_FCCU_FAILURE_SWT4_INTERRUPT_REQ_CH_67                  = 67U,
	SAF_FCCU_FAILURE_SWT4_RESET_REQ_CH_68                      = 68U,
	SAF_FCCU_FAILURE_SWT5_RESET_REQ_CH_69                      = 69U,
	SAF_FCCU_FAILURE_SWT6_RESET_REQ_CH_70                      = 70U,
	SAF_FCCU_FAILURE_CMU_1_PLL_CH_71                           = 71U,
	SAF_FCCU_FAILURE_INTC_MON_ERR_0_CH_72                      = 72U,
	SAF_FCCU_FAILURE_INTC_MON_ERR_1_CH_73                      = 73U,
	SAF_FCCU_FAILURE_INTC_MON_ERR_2_CH_74                      = 74U,
	SAF_FCCU_FAILURE_INTC_MON_ERR_3_CH_75                      = 75U,
	SAF_FCCU_FAILURE_INTC_MON_ERR_4_CH_76                      = 76U,
	SAF_FCCU_FAILURE_INTC_MON_ERR_5_CH_77                      = 77U,
	SAF_FCCU_FAILURE_INTC_MON_ERR_6_CH_78                      = 78U,
	SAF_FCCU_FAILURE_INTC_MON_ERR_7_CH_79                      = 79U,
	SAF_FCCU_FAILURE_INTC_MON_ERR_8_CH_80                      = 80U,
	SAF_FCCU_FAILURE_INTC_MON_ERR_9_CH_81                      = 81U,
	SAF_FCCU_FAILURE_INTC_MON_ERR_10_CH_82                     = 82U,
	SAF_FCCU_FAILURE_INTC_MON_ERR_11_CH_83                     = 83U,
	SAF_FCCU_FAILURE_INTC_MON_ERR_12_CH_84                     = 84U,
	SAF_FCCU_FAILURE_INTC_MON_ERR_13_CH_85                     = 85U,
	SAF_FCCU_FAILURE_INTC_MON_ERR_14_CH_86                     = 86U,
	SAF_FCCU_FAILURE_INTC_MON_ERR_15_CH_87                     = 87U,
	SAF_FCCU_FAILURE_GMAC_RECEIVE_DATA_ERROR_CH_88             = 88U,
	SAF_FCCU_FAILURE_AXBS0_TIMEOUT_CH_89                       = 89U,
	SAF_FCCU_FAILURE_AXBS1_TIMEOUT_CH_90                       = 90U,
	SAF_FCCU_FAILURE_AXBS2_TIMEOUT_CH_91                       = 91U,
	SAF_FCCU_FAILURE_TCM0_AXBS_TIMEOUT_CH_92                   = 92U,
	SAF_FCCU_FAILURE_CANFD1_SAFE_ERR_CH_93                     = 93U,
	SAF_FCCU_FAILURE_CANFD9_SAFE_ERR_CH_94                     = 94U,
#else
#endif
} SAF_fccu_failure_inputs_t;

/*
 * @brief FCCU filter width definition
 */
typedef enum
{
    SAF_FCCU_FILTER_GILTCHES_50US  = 0U,    /* filters glitches up to 50 us */
	SAF_FCCU_FILTER_GILTCHES_75US  = 1U,    /* filters glitches up to 75 us */
	SAF_FCCU_FILTER_GILTCHES_100US = 2U,    /* filters glitches up to 100 us */
} SAF_fccu_filter_width_t; /* PRQA S 1535 */

/*
 * @brief FCCU operation status definition
 */
typedef enum
{
	SAF_FCCU_OPS_IDLE        = 0U,    /* idle */
	SAF_FCCU_OPS_IN_PROGRESS = 1U,    /* in progress */
	SAF_FCCU_OPS_ABORTED     = 2U,    /* aborted */
	SAF_FCCU_OPS_SUCCESSFUL  = 3U     /* successful */
} SAF_fccu_op_status_t; /* PRQA S 1535 */

/*
 * @brief FCCU operation run definition
 */
typedef enum {
	SAF_FCCU_RUN_OP0  = 0U,     /* No operation */
	SAF_FCCU_RUN_OP1  = 1U,     /* Set the FCCU into the CONFIG state */
	SAF_FCCU_RUN_OP2  = 2U,     /* Set the ECCU into the NORMAL state */
	SAF_FCCU_RUN_OP3  = 3U,     /* Read the FCCU state */
	SAF_FCCU_RUN_OP4  = 4U,     /* Read the FCCU frozen status flags - N2AF_STATUS */
	SAF_FCCU_RUN_OP5  = 5U,     /* Read the FCCU frozen status flags - A2FF_STATUS */
	SAF_FCCU_RUN_OP6  = 6U,     /* Read the FCCU frozen status flags - N2FF_STATUS */
	SAF_FCCU_RUN_OP7  = 7U,     /* Read the FCCU frozen status flags - F2AF_STATUS */
	SAF_FCCU_RUN_OP10 = 10U,    /* Read the RF status register */
	SAF_FCCU_RUN_OP12 = 12U,    /* RF status clear operation in progress */
	SAF_FCCU_RUN_OP13 = 13U,    /* Clear the freeze status register */
	SAF_FCCU_RUN_OP14 = 14U,    /* CONFIG to NORMAL FCCU state (configuration timeout) in progress */
	SAF_FCCU_RUN_OP15 = 15U,    /* Clear the operation status (OPS=idle) */
	SAF_FCCU_RUN_OP17 = 17U,    /* Read the ALARM timer */
	SAF_FCCU_RUN_OP19 = 19U,    /* Read the CFG timer */
	SAF_FCCU_RUN_OP20 = 20U,    /* Read the Error Pin low counter value */
} SAF_fccu_op_run_t;

/*
 * @brief FCCU status definitions
 */
typedef enum {
	SAF_FCCU_NORMAL_STATE  = 0U,
	SAF_FCCU_CONFIG_STATE  = 1U,
	SAF_FCCU_ALARM_STATE   = 2U,
	SAF_FCCU_FAULT_STATE   = 3U,
	SAF_FCCU_UNKNOWN_STATE = 4U,
} SAF_fccu_status_t;

/*
 * @brief FCCU frozen status definitions
 */
typedef enum {
	SAF_FCCU_FROZEN_N2AF_STATUS = 0U,
	SAF_FCCU_FROZEN_A2FF_STATUS = 1U,
	SAF_FCCU_FROZEN_N2FF_STATUS = 2U,
	SAF_FCCU_FROZEN_F2AF_STATUS = 3U
} SAF_fccu_frozen_type_t;

/*
 * @brief FCCU XTMR type definitions
 */
typedef enum {
	SAF_FCCU_XTMR_ALARM = 0U,
	SAF_FCCU_XTMR_CFG   = 1U,
	SAF_FCCU_XTMR_ETMR  = 2U
} SAF_fccu_xtmr_type_t;

/*
 * @brief FCCU lock type definitions
 */
typedef enum {
	SAF_FCCU_TRANSIENTLY_UNLOCK = 0U,    /* No lock on the configuration */
	SAF_FCCU_TRANSIENTLY_LOCK   = 1U,    /* Transiently lock on the configuration */
	SAF_FCCU_PERANENTLY_LOCK    = 2U     /* Permanently lock on the configuration */
} SAF_fccu_lock_type_t;

/*
 * @brief FCCU IRQ type definitions
 */
typedef enum {
	SAF_FCCU_IRQ_NONE       = 0U,    /* No Interrupts are configured */
	SAF_FCCU_IRQ_CFG_TO_IEN = 1U,    /* Configuration time-out interrupt enabled */
} SAF_fccu_irq_type_t;

/*
 * @brief FCCU INT source definitions
 */
typedef enum {
	SAF_FCCU_INT_TIMEOUT = 0U,
	SAF_FCCU_INT_ALARM   = 1U,
	SAF_FCCU_INT_NMI     = 2U,
} SAF_fccu_int_status_t;

/*
 * @brief FCCU recoverable fault definitions
 */
typedef enum {
	SAF_FCCU_RF_HW_RECOVERABLE_FAULT = 0U,
	SAF_FCCU_RF_SW_RECOVERABLE_FAULT = 1U
} SAF_fccu_rf_setting_t;

/*
 * @brief FCCU recoverable fault state definitions
 */
typedef enum {
	SAF_FCCU_RFS_NO_RESET    = 0U,
	SAF_FCCU_RFS_SHORT_RESET = 1U,
	SAF_FCCU_RFS_LONG_RESET  = 2U
} SAF_fccu_rfs_setting_t;

/*
 * @brief FCCU EOUT control definitions
 */
typedef enum {
	SAF_FCCU_EP_INDEPENDENT_ABOVE_SW = 0U,
	SAF_FCCU_EP_FAULTY_STATE         = 1U,
	SAF_FCCU_EP_OK_STATE             = 3U
} SAF_fccu_ep_control_t;

/*
 * @brief FCCU EOUT output definitions
 */
typedef enum {
	SAF_FCCU_EP_OUTPUT_OPEN_DRAIN = 0U,
	SAF_FCCU_EP_OUTPUT_PUSH_PULL  = 1U
} SAF_fccu_ep_output_t;

/*
 * @brief FCCU EOUT protocol definitions
 */
typedef enum {
	SAF_FCCU_EOUT_PROTOCOL_SLOW_SM = 0U,
	SAF_FCCU_EOUT_PROTOCOL_FAST_SM = 1U
} SAF_fccu_eout_sm_t;

/*
 * @brief FCCU EOUT polar select definitions
 */
typedef enum {
	SAF_FCCU_EOUT_0_LOW_1_HIGH  = 0U,
	SAF_FCCU_EOUT_0_HIGH_0_LOW  = 1U
} SAF_fccu_eout_ps_t;

/*
 * @brief FCCU EOUT Fom definitions
 */
typedef enum {
	SAF_FCCU_FOM_DUAL_RAIL      = 0U,
	SAF_FCCU_FOM_TIME_SWITCHING = 1U,
	SAF_FCCU_FOM_BI_STABLE      = 2U,
	SAF_FCCU_FOM_TEST_0         = 5U,
	SAF_FCCU_FOM_TEST_1         = 6U,
	SAF_FCCU_FOM_TEST_2         = 7U
} SAF_fccu_eout_fom_t;

/*
 * @brief FCCU EOUT output frequency 6 definitions
 */
typedef enum {
    SAF_FCCU_EOUT_FOP_VARIABLE           = 0U,
	SAF_FCCU_EOUT_FOP_30_5_EXT_LT_122HZ  = 1U
} SAF_fccu_eout_fop_t;

/*
 * @brief FCCU EOUT output frequency 7/8 definitions
 */
typedef enum {
	SAF_FCCU_EOUT_FOP_EXT_VARIABLE    = 0U,
	SAF_FCCU_EOUT_FOP_EXT_61HZ        = 1U,
	SAF_FCCU_EOUT_FOP_EXT_30_5HZ      = 3U
} SAF_fccu_eout_fop_ext_t;

/*
 * @brief FCCU EOUT output frequency definitions
 */
#ifdef RESOURCE_SUPPORT_FCCU_EOUT_FREQ_EXT
typedef enum {
    SAF_FCCU_EOUT_EOF_LOWFREQ   = 63U,
    SAF_FCCU_EOUT_EOF_244HZ     = 63U,
    SAF_FCCU_EOUT_EOF_488HZ     = 31U,
	SAF_FCCU_EOUT_EOF_976HZ     = 15U,
	SAF_FCCU_EOUT_EOF_1952HZ    = 7U,
	SAF_FCCU_EOUT_EOF_3904HZ    = 3U,
	SAF_FCCU_EOUT_EOF_7808HZ    = 1U,
	SAF_FCCU_EOUT_EOF_15616HZ   = 0U
} SAF_fccu_eout_eof_t;
#else
typedef enum {
	SAF_FCCU_EOUT_EOF_LOWFREQ  = 63U,
	SAF_FCCU_EOUT_EOF_61HZ     = 63U,
	SAF_FCCU_EOUT_EOF_122HZ    = 31U,
	SAF_FCCU_EOUT_EOF_244HZ    = 15U,
	SAF_FCCU_EOUT_EOF_488HZ    = 7U,
	SAF_FCCU_EOUT_EOF_976HZ    = 3U,
	SAF_FCCU_EOUT_EOF_1952HZ   = 1U,
	SAF_FCCU_EOUT_EOF_3904HZ   = 0U
} SAF_fccu_eout_eof_t;
#endif

/*
 * @brief FCCU NMI to Cores definitions
 */
typedef enum {
	SAF_FCCU_NMI_CORE_0         = 0U,
	SAF_FCCU_NMI_CORE_1         = 1U,
	SAF_FCCU_NMI_CORE_2         = 2U,
	SAF_FCCU_NMI_CORE_3         = 3U,
} SAF_fccu_nmi_control_t;/* PRQA S 1535 */

/*
 * @brief FCCU ISR state definitions
 */
typedef struct {
    uint8_t rfConfigNu;
    void    (*SafcallBackFunction)(void *param);
    void    *callBaclParam;
} fcc_isr_state_t;

/*
 * @brief FCC recoverable faults reaction type definitions
 */
typedef struct {
    boolean irq_alarm_en;
    boolean nmi_en;
    boolean eout_sig_en;
} fccu_rf_reaction_t;

/*
 * @brief FCCU recoverable faults configurations
 */
typedef struct /* PRQA S 3630 */
{
    uint8_t             channel;
    SAF_fccu_rf_setting_t   hwSw_recovery;
    SAF_fccu_rfs_setting_t  reset;
    boolean             timeout_alarm_enable;
    fccu_rf_reaction_t  reaction;
    void                (*callback)(void *param);
    void                *callbackParam;
} fccu_rf_config_t;

/*
 * @brief FCCU Eout configurations
 */
typedef struct
{
    boolean set_after_reset; /* TRUE:  EOUT Signals controled bt FCCU,
                              * FALSE: EOUT Signals are in High-Z state */
    SAF_fccu_ep_control_t control;
    SAF_fccu_ep_output_t output;
    SAF_fccu_eout_fop_ext_t fop_ext;
    SAF_fccu_eout_fop_t fop;
    SAF_fccu_eout_sm_t switch_mode;
    SAF_fccu_eout_ps_t polarity_sel;
    SAF_fccu_eout_fom_t mode;
    SAF_fccu_eout_eof_t eof;
    uint16_t delta_t_value;
} fccu_eout_config_t;

/*
 * @brief Fault State Flags for Recoverable Faults
 */
typedef struct /* PRQA S 3630 */
{
    uint32_t faultsFlags[SAF_FCCU_RF_MAX_GROUP]; /*!< Faults Flags */
} SAF_fccu_faults_flags_t;

/*
 * @brief FCCU module configuration
 */
typedef struct /* PRQA S 3630 */
{
    boolean             filter_bypass_enable;    /* Filter bypss */
    uint8_t             filter_width;            /* Filter width */
    boolean             debug_enable;            /* Debug mode entry */
    fccu_eout_config_t  eout_config;
    SAF_fccu_irq_type_t     irq_type;
    uint32_t            cfg_timeout;
    SAF_fccu_lock_type_t    lock_type;
    uint8_t             rfConfigNumber;
    void                (*callbackFunc)(void *param);
    void                *callbackParam;
} fccu_config_t;

/*
 * @brief FCCU driver APIs
 */
extern status_t SAF_FCCU_LLD_StartupCallbackSwitch(uint32_t value);
extern status_t SAF_FCCU_LLD_ClearFaults(uint8_t faultIndex);
extern status_t SAF_FCCU_LLD_RunOperation(const SAF_fccu_op_run_t opRun);
extern status_t SAF_FCCU_LLD_ReadFaults(SAF_fccu_faults_flags_t *flags);
extern SAF_fccu_status_t SAF_FCCU_LLD_GetState(void);
extern status_t SAF_FCCU_LLD_SetConfigState(void);
extern status_t SAF_FCCU_LLD_SetNormalState(void);
extern status_t SAF_FCCU_LLD_SetCfgTimeout(uint8_t to);
extern void SAF_FCCU_LLD_LockConfig(const SAF_fccu_lock_type_t lock);
extern uint8_t SAF_FCCU_LLD_CheckIntStatus(SAF_fccu_int_status_t intStatus);
extern void SAF_FCCU_LLD_ClearIntFlag(SAF_fccu_int_status_t intStatus);
extern void FCCU_IRQ_Handler(void);
extern void FCCU_CFG_TO_IRQ_Handler(void);
extern uint32_t FCCU_IVOR_Handler(void);
extern uint32_t FCCU_StartInject_Check(void);
extern status_t SAF_FCCU_LLD_SetRfConfig(const fccu_rf_config_t *cfg);
extern status_t SAF_FCCU_LLD_SetEout(fccu_eout_config_t *eoutCfg);
extern status_t FCCU_LLD_Init(fccu_config_t *config, fccu_rf_config_t const *rfConfig);
extern status_t SAF_FCCU_LLD_GetFrozenStatus(SAF_fccu_frozen_type_t frozenType, uint16_t *frozenStatus);
extern status_t SAF_FCCU_LLD_ClearFreezeStatus(void);
extern uint32_t SAF_FCCU_LLD_GetXtmrValue(SAF_fccu_xtmr_type_t xtmrType);
extern void SAF_FCCU_LLD_SetRfFake(SAF_fccu_failure_inputs_t fakeCode);
extern status_t SAF_FCCU_LLD_CloseChReaction(SAF_fccu_failure_inputs_t closeCh);
extern status_t SAF_FCCU_LLD_OpenChReaction(SAF_fccu_failure_inputs_t openCh);
extern status_t SAF_FCCU_LLD_CheckChEnState(SAF_fccu_failure_inputs_t checkCh);
#if defined(CCFC3012PT)
extern void SAF_FCCU_LLD_SetNMICore(SAF_fccu_nmi_control_t nmiCores);
#endif
#endif /* LLD_INC_FCCU_LLD_H_ */
