/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC
*   Peripheral           : Mcu
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           :
*   Build Version        :
*
*****************************************************************************/

/**
*   @file    Mcu_Types.h
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Mcu MCAL driver.
*
*   @addtogroup Mcu
*   @{
*/

#ifndef MCU_TYPES_CCFC3010PTD_H_
#define MCU_TYPES_CCFC3010PTD_H_
#ifdef CCFC3010PTD
/* RGM0 */
#define MCU_RGM_PIT_RTC_1               0x80000000U
#define MCU_RGM_PIT_RTC_0               0x40000000U
#define MCU_RGM_SIUL                    0x00008000U
#define MCU_RGM_SIPI_0                  0x00000800U

/* RGM1 */
#define MCU_RGM_ADCSD_0                 0x10000000U
#define MCU_RGM_ADCSD_2                 0x08000000U
#define MCU_RGM_TTCAN0                  0x00200000U
#define MCU_RGM_CRC_0                   0x00000040U
#define MCU_RGM_DMAMUX_0                0x00000010U

/* RGM2 */
#define MCU_RGM_LINFlexD_0              0x10000000U
#define MCU_RGM_LINFlexD_1              0x08000000U
#define MCU_RGM_LINFlexD_3              0x04000000U
#define MCU_RGM_MCAN_8                  0x00004000U
#define MCU_RGM_MCAN_7                  0x00002000U
#define MCU_RGM_MCAN_6                  0x00001000U
#define MCU_RGM_MCAN_5                  0x00000800U
#define MCU_RGM_CAN_RAM0_CTR            0x00000400U
#define MCU_RGM_MCAN_1                  0x00000040U
#define MCU_RGM_MCAN_2                  0x00000020U
#define MCU_RGM_MCAN_3                  0x00000010U
#define MCU_RGM_MCAN_4                  0x00000008U
#define MCU_RGM_CAN_RAM1_CTR            0x00000004U

/* RGM3 */
#define MCU_RGM_ADCSAR_0                0x80000000U
#define MCU_RGM_ACMP0                   0x00200000U
#define MCU_RGM_PSI5_0                  0x00008000U
#define MCU_RGM_DSPI_19                 0x00004000U
#define MCU_RGM_SENT_0                  0x00000100U
#define MCU_RGM_IIC_0                   0x00000020U
#define MCU_RGM_DSPI_0                  0x00000008U
#define MCU_RGM_DSPI_1                  0x00000004U
#define MCU_RGM_DSPI_4                  0x00000002U

/* RGM4 */
#define MCU_RGM_DSPI_16                 0x00008000U
#define MCU_RGM_DSPI_17                 0x00004000U
#define MCU_RGM_DSPI_18                 0x00002000U
#define MCU_RGM_DSPI_11                 0x00000400U
#define MCU_RGM_SPORT                   0x00000020U
#define MCU_RGM_EMIOS0                  0x00000008U
#define MCU_RGM_GTMINT                  0x00000001U

/* RGM5 */
#define MCU_RGM_ADCSD_1                 0x10000000U
#define MCU_RGM_ADCSD_3                 0x08000000U
#define MCU_RGM_FCCU                    0x00000200U
#define MCU_RGM_CRC_1                   0x00000040U
#define MCU_RGM_PSI5_S_0                0x00000004U

/* RGM6 */
#define MCU_RGM_LINFlexD_2              0x10000000U
#define MCU_RGM_LINFlexD_7              0x08000000U
#define MCU_RGM_LINFlexD_8              0x04000000U
#define MCU_RGM_LINFlexD_9              0x02000000U
#define MCU_RGM_LINFlexD_10             0x01000000U
#define MCU_RGM_LINFlexD_11             0x00800000U
#define MCU_RGM_ACMP4                   0x00100000U
#define MCU_RGM_ACMP5                   0x00080000U
#define MCU_RGM_ACMP6                   0x00040000U

/* RGM7 */
#define MCU_RGM_ADCSAR_2                0x20000000U
#define MCU_RGM_ADCSAR_8                0x00800000U
#define MCU_RGM_CGDMA                   0x00040000U
#define MCU_RGM_DSPI_2                  0x00000008U
#define MCU_RGM_DSPI_3                  0x00000004U

typedef enum
{
    /* RGM0 */
    RGM_PIT_RTC_1 = 31U,
    RGM_PIT_RTC_0 = 30U,
    RGM_SIUL = 15U,
    RGM_SIPI_0 = 11U,

    /* RGM1 */
    RGM_ADCSD_0 = 60U,
    RGM_ADCSD_2 = 59U,
    RGM_TTCAN0 = 53U,
    RGM_CRC_0 = 38U,
    RGM_DMAMUX_0 = 36U,

    /* RGM2 */
    RGM_LINFlexD_0 = 92U,
    RGM_LINFlexD_1 = 91U,
    RGM_LINFlexD_3 = 90U,
    RGM_MCAN_8 = 78U,
    RGM_MCAN_7 = 77U,
    RGM_MCAN_6 = 76U,
    RGM_MCAN_5 = 75U,
    RGM_CAN_RAM0_CTR = 74U,
    RGM_MCAN_1 = 70U,
    RGM_MCAN_2 = 69U,
    RGM_MCAN_3 = 68U,
    RGM_MCAN_4 = 67U,
    RGM_CAN_RAM1_CTR = 66U,

    /* RGM3 */
    RGM_ADCSAR_0 = 127U,
    RGM_ACMP0 = 117U,
    RGM_PSI5_0 = 111U,
    RGM_DSPI_19 = 110U,
    RGM_SENT_0 = 104U,
    RGM_IIC_0 = 101U,
    RGM_DSPI_0 = 99U,
    RGM_DSPI_1 = 98U,
    RGM_DSPI_4 = 97U,

    /* RGM4 */
    RGM_DSPI_16 = 143U,
    RGM_DSPI_17 = 142U,
    RGM_DSPI_18 = 141U,
    RGM_DSPI_11 = 138U,
    RGM_SPORT = 133U,
    RGM_EMIOS0 = 131U,
    RGM_GTMINT = 128U,

    /* RGM5 */
    RGM_ADCSD_1 = 188U,
    RGM_ADCSD_3 = 187U,
    RGM_FCCU = 169U,
    RGM_CRC_1 = 166U,
    RGM_PSI5_S_0 = 162U,

    /* RGM6 */
    RGM_LINFlexD_2 = 220U,
    RGM_LINFlexD_7 = 219U,
    RGM_LINFlexD_8 = 218U,
    RGM_LINFlexD_9 = 217U,
    RGM_LINFlexD_10 = 216U,
    RGM_LINFlexD_11 = 215U,
    RGM_ACMP4 = 212U,
    RGM_ACMP5 = 211U,
    RGM_ACMP6 = 210U,

    /* RGM7 */
    RGM_ADCSAR_2 = 253U,
    RGM_ADCSAR_8 = 247U,
    RGM_CGDMA = 242U,
    RGM_DSPI_2 = 227U,
    RGM_DSPI_3 = 226U,
    /* Other */
    MC_RGM_ALL = 256U,
}Mcu_RgmPeriRstType;


/*! @brief Clock names. */
typedef enum {
    /* peripheral name */
    MC_ME_PCTL_SIUL_INDEX                    = 15U,/*PS0*/
    MC_ME_PCTL_PIT_RTC_0_INDEX               = 30U,/*PS0*/
    MC_ME_PCTL_PIT_RTC_1_INDEX               = 31U,/*PS0*/
    MC_ME_PCTL_DMAMUX0_INDEX                 = 36U,/*PS1*/
    MC_ME_PCTL_CRC_0_INDEX                   = 38U,/*PS1*/
    MC_ME_PCTL_GMAC_INDEX                    = 44U,/*PS1*/
    MC_ME_PCTL_ADCSD_2_INDEX                 = 59U,/*PS1*/
    MC_ME_PCTL_ADCSD_0_INDEX                 = 60U,/*PS1*/
    MC_ME_PCTL_CAM_RAM_1_0_INDEX             = 65U,/*PS2*/
    MC_ME_PCTL_CAM_RAM_1_1_INDEX             = 66U,/*PS2*/
    MC_ME_PCTL_MCAN4_INDEX                   = 67U,/*PS2*/
    MC_ME_PCTL_MCAN3_INDEX                   = 68U,/*PS2*/
    MC_ME_PCTL_MCAN2_INDEX                   = 69U,/*PS2*/
    MC_ME_PCTL_MCAN1_INDEX                   = 70U,/*PS2*/
    MC_ME_PCTL_TTCAN_0_INDEX                 = 72U,/*PS2*/
    MC_ME_PCTL_CAN_RAM_0_0_INDEX             = 73U,/*PS2*/
    MC_ME_PCTL_CAN_RAM_0_1_INDEX             = 74U,/*PS2*/
    MC_ME_PCTL_MCAN5_INDEX                   = 75U,/*PS2*/
    MC_ME_PCTL_MCAN6_INDEX                   = 76U,/*PS2*/
    MC_ME_PCTL_MCAN7_INDEX                   = 77U,/*PS2*/
    MC_ME_PCTL_MCAN8_INDEX                   = 78U,/*PS2*/
    MC_ME_PCTL_CAN_SAMPLER_INDEX             = 82U,/*PS2*/
    MC_ME_PCTL_RTC_INDEX                     = 83U,/*PS2*/
    MC_ME_PCTL_LINFlexD_6_INDEX              = 87U,/*PS2*/
    MC_ME_PCTL_LINFlexD_5_INDEX              = 88U,/*PS2*/
    MC_ME_PCTL_LINFlexD_4_INDEX              = 89U,/*PS2*/
    MC_ME_PCTL_LINFlexD_3_INDEX              = 90U,/*PS2*/
    MC_ME_PCTL_LINFlexD_1_INDEX              = 91U,/*PS2*/
    MC_ME_PCTL_LINFlexD_0_INDEX              = 92U,/*PS2*/
    MC_ME_PCTL_DSPI_4_INDEX                  = 97U,/*PS3*/
    MC_ME_PCTL_DSPI_1_INDEX                  = 98U,/*PS3*/
    MC_ME_PCTL_IIC_0_INDEX                   = 101U,/*PS3*/
    MC_ME_PCTL_SENT_0_INDEX                  = 104U,/*PS3*/
    MC_ME_PCTL_DSPI_19_INDEX                 = 110U,/*PS3*/
    MC_ME_PCTL_PSI5_0_INDEX                  = 111U,/*PS3*/
    MC_ME_PCTL_ACMP3_INDEX                   = 114U,/*PS3*/
    MC_ME_PCTL_ACMP2_INDEX                   = 115U,/*PS3*/
    MC_ME_PCTL_ACMP1_INDEX                   = 116U,/*PS3*/
    MC_ME_PCTL_ACMP0_INDEX                   = 117U,/*PS3*/
    MC_ME_PCTL_FILTER_INDEX                  = 123U,
    MC_ME_PCTL_ADCSAR_0_INDEX                = 127U,/*PS3*/
    MC_ME_PCTL_GTMINT_INDEX                  = 128U,/*PS4*/
    MC_ME_PCTL_EMIOS_0_INDEX                 = 131U,/*PS4*/
    MC_ME_PCTL_SPORT_INDEX                   = 133U,/*PS4*/
    MC_ME_PCTL_DSPI_11_INDEX                 = 138U,/*PS4*/
    MC_ME_PCTL_DSPI_18_INDEX                 = 141U,/*PS4*/
    MC_ME_PCTL_DSPI_17_INDEX                 = 142U,/*PS4*/
    MC_ME_PCTL_DSPI_16_INDEX                 = 143U,/*PS4*/
    MC_ME_PCTL_CMU_INDEX                     = 147U,/*PS4*/
    MC_ME_PCTL_PSI5_S_0_INDEX                = 162U,/*PS5*/
    MC_ME_PCTL_CRC_1_INDEX                   = 166U,/*PS5*/
    MC_ME_PCTL_ADCSD_3_INDEX                 = 187U,/*PS5*/
    MC_ME_PCTL_ADCSD_1_INDEX                 = 188U,/*PS5*/
    MC_ME_PCTL_ACMP_7_INDEX                  = 209U,/*PS6*/
    MC_ME_PCTL_LINFlexD_11_INDEX             = 215U,/*PS6*/
    MC_ME_PCTL_LINFlexD_10_INDEX             = 216U,/*PS6*/
    MC_ME_PCTL_LINFlexD_9_INDEX              = 217U,/*PS6*/
    MC_ME_PCTL_LINFlexD_8_INDEX              = 218U,/*PS6*/
    MC_ME_PCTL_LINFlexD_7_INDEX              = 219U,/*PS6*/
    MC_ME_PCTL_LINFlexD_2_INDEX              = 220U,/*PS6*/
    MC_ME_PCTL_DSPI_3_INDEX                  = 226U,/*PS7*/
    MC_ME_PCTL_DSPI_2_INDEX                  = 227U,/*PS7*/
    MC_ME_PCTL_SENT_1_INDEX                  = 232U,/*PS7*/
    MC_ME_PCTL_SSI_0_INDEX                   = 234U,
    MC_ME_PCTL_ADCSAR_8_INDEX                = 247U,/*PS7*/
    MC_ME_PCTL_ADCSAR_2_INDEX                = 253U,/*PS7*/
    MC_ME_PCTLn_COUNT                        = 256U,
    MC_ME_PCTL_ALL                           = 257U,
} Mcu_McMePeriNameType;


typedef enum
{
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
    FCCU_FAILURE_SWT1_INTERRUPT_REQ_CH_12                  = 12U,
    FCCU_FAILURE_SWT1_RESET_REQ_CH_13                      = 13U,
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
    FCCU_FAILURE_LOCKSTEP_0_MODE_CH_51                     = 51U,
    FCCU_FAILURE_SAFE_MODE_CH_52                           = 52U,
    FCCU_FAILURE_COMPENSATION_DISABLE_CH_53                = 53U,
    FCCU_FAILURE_EIN_ERR_CH_54                             = 54U,
    FCCU_FAILURE_SWT3_RESET_REQ_CH_55                      = 55U,

    FCCU_FAILURE_LOCKSTEP_1_MODE_CH_56                     = 56U,

    FCCU_FAILURE_RCCU1_0_CH_59                             = 59U,
    FCCU_FAILURE_RCCU1_1_CH_62                             = 62U,

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

    FCCU_FAILURE_GMAC_REC_ERR_CH_88                        = 88U,
    FCCU_FAILURE_AXBS_0_TIMEOUT_CH_89                      = 89U

} fccu_failure_inputs_t;
#endif /* CCFC3010PTD */
#endif /* MCU_TYPES_CCFC3010PTD_H_ */
