#ifndef MC_ME_REG_H_
#define MC_ME_REG_H_

/* ============================================================================
   =============================== Module: MC_ME ==============================
   ============================================================================ */

#define MC_ME_MODE_RESET_FUNC   (0U)
#define MC_ME_MODE_TEST         (1U)
#define MC_ME_MODE_SAFE         (2U)
#define MC_ME_MODE_DRUN         (3U)
#define MC_ME_MODE_RUN0         (4U)
#define MC_ME_MODE_RUN1         (5U)
#define MC_ME_MODE_RUN2         (6U)
#define MC_ME_MODE_RUN3         (7U)
#define MC_ME_MODE_HALT         (8U)
#define MC_ME_MODE_STOP         (0xAU)
#if defined(CCFC3008PT)
/* CCFC3008PT unsupported. */
#else
#define MC_ME_MODE_STANDBY      (0xDU)
#endif
#define MC_ME_MODE_RESET_DEST   (0xFU)

typedef union MC_ME_GS_union_tag {     /* Global Status Register */
  vuint32_t R;
  struct {
    vuint32_t S_CURRENT_MODE:4;
    vuint32_t S_MTRANS:1;
    vuint32_t  :1;
    vuint32_t  :2;
    vuint32_t S_PDO:1;
    vuint32_t  :2;
    vuint32_t S_MVR:1;
    vuint32_t  :2;
    vuint32_t S_FLA:2;
    vuint32_t  :8;
    vuint32_t S_PLL1:1;
    vuint32_t S_PLL0:1;
    vuint32_t S_XOSC:1;
    vuint32_t S_IRC:1;
    vuint32_t S_SYSCLK:4;
  } B;
} MC_ME_GS_tag;

typedef union MC_ME_MCTL_union_tag {   /* Mode Control Register */
  vuint32_t R;
  struct {
    vuint32_t TARGET_MODE:4;
    vuint32_t  :12;
    vuint32_t KEY:16;
  } B;
} MC_ME_MCTL_tag;

typedef union MC_ME_ME_union_tag {     /* Mode Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t RESET_DEST:1;
#if defined(CCFC3008PT)
/* CCFC3008PT unsupported STANDBY. */
    vuint32_t  :4;
#else
    vuint32_t  :1;
    vuint32_t STANDBY:1;
    vuint32_t  :2;
#endif
    vuint32_t STOP0:1;
    vuint32_t  :1;
    vuint32_t HALT0:1;
    vuint32_t RUN3:1;
    vuint32_t RUN2:1;
    vuint32_t RUN1:1;
    vuint32_t RUN0:1;
    vuint32_t DRUN:1;
    vuint32_t SAFE:1;
    vuint32_t TEST:1;
    vuint32_t RESET_FUNC:1;
  } B;
} MC_ME_ME_tag;

typedef union MC_ME_IS_union_tag {     /* Interrupt Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t I_ICONF_CC:1;
    vuint32_t I_ICONF_CU:1;
    vuint32_t I_ICONF:1;
    vuint32_t I_IMODE:1;
    vuint32_t I_SAFE:1;
    vuint32_t I_MTC:1;
  } B;
} MC_ME_IS_tag;

typedef union MC_ME_IM_union_tag {     /* Interrupt Mask Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t M_ICONF_CC:1;
    vuint32_t M_ICONF_CU:1;
    vuint32_t M_ICONF:1;
    vuint32_t M_IMODE:1;
    vuint32_t M_SAFE:1;
    vuint32_t M_MTC:1;
  } B;
} MC_ME_IM_tag;

typedef union MC_ME_IMTS_union_tag {   /* Invalid Mode Transition Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t S_MRIG:1;
    vuint32_t S_MTI:1;
    vuint32_t S_MRI:1;
    vuint32_t S_DMA:1;
    vuint32_t S_NMA:1;
    vuint32_t S_SEA:1;
  } B;
} MC_ME_IMTS_tag;

typedef union MC_ME_DMTS_union_tag {   /* Debug Mode Transition Status Register */
  vuint32_t R;
  struct {
    vuint32_t PREVIOUS_MODE:4;
    vuint32_t  :4;
    vuint32_t MPH_BUSY:1;
    vuint32_t  :2;
    vuint32_t PMC_PROG:1;
    vuint32_t DBG_MODE:1;
    vuint32_t CCKL_PROG:1;
    vuint32_t PCS_PROG:1;
    vuint32_t SMR:1;
    vuint32_t  :1;
    vuint32_t VREG_CSRC_SC:1;
    vuint32_t CSRC_CSRC_SC:1;
    vuint32_t IRC_SC:1;
    vuint32_t SCSRC_SC:1;
    vuint32_t SYSCLK_SW:1;
    vuint32_t  :1;
    vuint32_t FLASH_SC:1;
    vuint32_t CDP_PRPH_224_255:1;
    vuint32_t CDP_PRPH_192_223:1;
    vuint32_t CDP_PRPH_160_191:1;
    vuint32_t CDP_PRPH_128_159:1;
    vuint32_t CDP_PRPH_96_127:1;
    vuint32_t CDP_PRPH_64_95:1;
    vuint32_t CDP_PRPH_32_63:1;
    vuint32_t CDP_PRPH_0_31:1;
  } B;
} MC_ME_DMTS_tag;

typedef union MC_ME_RESET_MC_union_tag { /* RESET Mode Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t PWRLVL:3;
    vuint32_t  :4;
    vuint32_t PDO:1;
    vuint32_t  :2;
    vuint32_t MVRON:1;
    vuint32_t  :2;
    vuint32_t FLAON:2;
    vuint32_t  :8;
    vuint32_t PLL1ON:1;
    vuint32_t PLL0ON:1;
    vuint32_t XOSCON:1;
    vuint32_t IRCON:1;
    vuint32_t SYSCLK:4;
  } B;
} MC_ME_RESET_MC_tag;

typedef union MC_ME_TEST_MC_union_tag { /* TEST Mode Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t PWRLVL:3;
    vuint32_t  :4;
    vuint32_t PDO:1;
    vuint32_t  :2;
    vuint32_t MVRON:1;
    vuint32_t  :2;
    vuint32_t FLAON:2;
    vuint32_t  :8;
    vuint32_t PLL1ON:1;
    vuint32_t PLL0ON:1;
    vuint32_t XOSCON:1;
    vuint32_t IRCON:1;
    vuint32_t SYSCLK:4;
  } B;
} MC_ME_TEST_MC_tag;

typedef union MC_ME_SAFE_MC_union_tag { /* SAFE Mode Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t PWRLVL:3;
    vuint32_t  :4;
    vuint32_t PDO:1;
    vuint32_t  :2;
    vuint32_t MVRON:1;
    vuint32_t  :2;
    vuint32_t FLAON:2;
    vuint32_t  :8;
    vuint32_t PLL1ON:1;
    vuint32_t PLL0ON:1;
    vuint32_t XOSCON:1;
    vuint32_t IRCON:1;
    vuint32_t SYSCLK:4;
  } B;
} MC_ME_SAFE_MC_tag;

typedef union MC_ME_DRUN_MC_union_tag { /* DRUN Mode Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t PWRLVL:3;
    vuint32_t  :4;
    vuint32_t PDO:1;
    vuint32_t  :2;
    vuint32_t MVRON:1;
    vuint32_t  :2;
    vuint32_t FLAON:2;
    vuint32_t  :8;
    vuint32_t PLL1ON:1;
    vuint32_t PLL0ON:1;
    vuint32_t XOSCON:1;
    vuint32_t IRCON:1;
    vuint32_t SYSCLK:4;
  } B;
} MC_ME_DRUN_MC_tag;

typedef union MC_ME_RUN_MC_union_tag { /* RUN0 Mode Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t PWRLVL:3;
    vuint32_t  :4;
    vuint32_t PDO:1;
    vuint32_t  :2;
    vuint32_t MVRON:1;
    vuint32_t  :2;
    vuint32_t FLAON:2;
    vuint32_t  :8;
    vuint32_t PLL1ON:1;
    vuint32_t PLL0ON:1;
    vuint32_t XOSCON:1;
    vuint32_t IRCON:1;
    vuint32_t SYSCLK:4;
  } B;
} MC_ME_RUN_MC_tag;

typedef union MC_ME_HALT0_MC_union_tag { /* HALT0 Mode Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t PWRLVL:3;
    vuint32_t  :4;
    vuint32_t PDO:1;
    vuint32_t  :2;
    vuint32_t MVRON:1;
    vuint32_t  :2;
    vuint32_t FLAON:2;
    vuint32_t  :8;
    vuint32_t PLL1ON:1;
    vuint32_t PLL0ON:1;
    vuint32_t XOSCON:1;
    vuint32_t IRCON:1;
    vuint32_t SYSCLK:4;
  } B;
} MC_ME_HALT0_MC_tag;

typedef union MC_ME_STOP0_MC_union_tag { /* STOP0 Mode Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t PWRLVL:3;
    vuint32_t  :4;
    vuint32_t PDO:1;
    vuint32_t  :2;
    vuint32_t MVRON:1;
    vuint32_t  :2;
    vuint32_t FLAON:2;
    vuint32_t  :8;
    vuint32_t PLL1ON:1;
    vuint32_t PLL0ON:1;
    vuint32_t XOSCON:1;
    vuint32_t IRCON:1;
    vuint32_t SYSCLK:4;
  } B;
} MC_ME_STOP0_MC_tag;

#if defined(CCFC3008PT)
/* CCFC3008PT unsupported STANDBY. */
#else
typedef union MC_ME_STANDBY_MC_union_tag {  /* STANDBY Mode Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t PWRLVL:3;
    vuint32_t  :4;
    vuint32_t PDO:1;
    vuint32_t  :2;
    vuint32_t MVRON:1;
    vuint32_t  :2;
    vuint32_t FLAON:2;
    vuint32_t  :8;
    vuint32_t PLL1ON:1;
    vuint32_t PLL0ON:1;
    vuint32_t XOSCON:1;
    vuint32_t IRCON:1;  /* r/w */
    vuint32_t SYSCLK:4;
  } B;
} MC_ME_STANDBY_MC_tag;
#endif

typedef union MC_ME_PS0_union_tag {    /* Peripheral Status Register 0 */
  vuint32_t R;
  struct {
    vuint32_t S_PIT_RTC_1:1;
    vuint32_t S_PIT_RTC_0:1;
    vuint32_t  :14;
    vuint32_t S_SIUL:1;
    vuint32_t  :3;
    vuint32_t S_SIPI_0:1;
    vuint32_t  :1;
    vuint32_t S_LFAST_0:1;
    vuint32_t  :5;
    vuint32_t S_EBI_0:1;
    vuint32_t  :3;
  } B;
} MC_ME_PS0_tag;

typedef union MC_ME_PS1_union_tag {    /* Peripheral Status Register 1 */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t S_ADCSD_0:1;
    vuint32_t S_ADCSD_2:1;
    vuint32_t S_ADCSD_4:1;
    vuint32_t S_ADCSD_6:1;
    vuint32_t S_ADCSD_8:1;
    vuint32_t  :17;
    vuint32_t S_CRC_0:1;
    vuint32_t  :1;
    vuint32_t S_DMAMUX_0:1;
    vuint32_t  :4;
  } B;
} MC_ME_PS1_tag;

typedef union MC_ME_PS2_union_tag {    /* Peripheral Status Register 2 */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t S_DSPI_12:1;
    vuint32_t S_LINFlexD_0:1;
    vuint32_t S_LINFlexD_1:1;
    vuint32_t  :5;
    vuint32_t S_LINFlexD_14:1;
    vuint32_t S_LINFlexD_16:1;
    vuint32_t  :9;
    vuint32_t S_CAN_RAM_CTRL:1;
    vuint32_t  :1;
    vuint32_t S_TTCAN:1;
    vuint32_t  :1;
    vuint32_t S_MCAN_1:1;
    vuint32_t S_MCAN_2:1;
    vuint32_t S_MCAN_3:1;
    vuint32_t S_MCAN_4:1;
    vuint32_t  :3;
  } B;
} MC_ME_PS2_tag;

typedef union MC_ME_PS3_union_tag {    /* Peripheral Status Register 3 */
  vuint32_t R;
  struct {
    vuint32_t S_ADCSAR_0:1;
    vuint32_t  :3;
    vuint32_t S_ADCSAR_4:1;
    vuint32_t  :10;
    vuint32_t S_ADCSAR_b:1;
    vuint32_t S_PSI5_0:1;
    vuint32_t  :3;
    vuint32_t S_FLEXRAY_0:1;
    vuint32_t  :2;
    vuint32_t S_SENT_0:1;
    vuint32_t  :2;
    vuint32_t S_IIC_0:1;
    vuint32_t  :1;
    vuint32_t S_DSPI_0:1;
    vuint32_t S_DSPI_1:1;
    vuint32_t S_DSPI_4:1;
    vuint32_t S_DSPI_6:1;
  } B;
} MC_ME_PS3_tag;

typedef union MC_ME_PS4_union_tag {    /* Peripheral Status Register 4 */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t S_GTMINT:1;
  } B;
} MC_ME_PS4_tag;

typedef union MC_ME_PS5_union_tag {    /* Peripheral Status Register 5 */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t S_ADCSD_1:1;
    vuint32_t S_ADCSD_3:1;
    vuint32_t S_ADCSD_5:1;
    vuint32_t S_ADCSD_7:1;
    vuint32_t S_ADCSD_9:1;
    vuint32_t  :17;
    vuint32_t S_CRC_1:1;
    vuint32_t  :3;
    vuint32_t S_PSI5S_0:1;
    vuint32_t  :2;
  } B;
} MC_ME_PS5_tag;

typedef union MC_ME_PS6_union_tag {    /* Peripheral Status Register 6 */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t S_LINFlexD_2:1;
    vuint32_t  :6;
    vuint32_t S_LINFlexD_15:1;
    vuint32_t  :21;
  } B;
} MC_ME_PS6_tag;

typedef union MC_ME_PS7_union_tag {    /* Peripheral Status Register 7 */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t S_ADCSAR_1:1;
    vuint32_t S_ADCSAR_2:1;
    vuint32_t S_ADCSAR_3:1;
    vuint32_t  :1;
    vuint32_t S_ADCSAR_5:1;
    vuint32_t S_ADCSAR_6:1;
    vuint32_t S_ADCSAR_7:1;
    vuint32_t S_ADCSAR_8:1;
    vuint32_t S_ADCSAR_9:1;
    vuint32_t S_ADCSAR_10:1;
    vuint32_t  :5;
    vuint32_t S_PSI5_1:1;
    vuint32_t  :3;
    vuint32_t S_FLEXRAY_1:1;
    vuint32_t  :2;
    vuint32_t S_SENT_1:1;
    vuint32_t  :2;
    vuint32_t S_IIC_1:1;
    vuint32_t  :1;
    vuint32_t S_DSPI_2:1;
    vuint32_t S_DSPI_3:1;
    vuint32_t S_DSPI_5:1;
    vuint32_t  :1;
  } B;
} MC_ME_PS7_tag;

typedef union MC_ME_RUN_PC_union_tag { /* Run Peripheral Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t RUN3:1;
    vuint32_t RUN2:1;
    vuint32_t RUN1:1;
    vuint32_t RUN0:1;
    vuint32_t DRUN:1;
    vuint32_t SAFE:1;
    vuint32_t TEST:1;
    vuint32_t RESET:1;
  } B;
} MC_ME_RUN_PC_tag;

typedef union MC_ME_LP_PC_union_tag {  /* Low-Power Peripheral Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :21;
    vuint32_t STOP0:1;
    vuint32_t  :1;
    vuint32_t HALT0:1;
    vuint32_t  :8;
  } B;
} MC_ME_LP_PC_tag;

typedef union MC_ME_PCTL_union_tag {  /* Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL_tag;

#if 0u
typedef union MC_ME_PCTL3_union_tag {  /* EBI_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL3_tag;

typedef union MC_ME_PCTL9_union_tag {  /* LFAST_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL9_tag;

typedef union MC_ME_PCTL11_union_tag { /* SIPI_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL11_tag;

typedef union MC_ME_PCTL15_union_tag { /* SIUL Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL15_tag;

typedef union MC_ME_PCTL30_union_tag { /* PIT_RTC_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL30_tag;

typedef union MC_ME_PCTL31_union_tag { /* PIT_RTC_1 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL31_tag;

typedef union MC_ME_PCTL36_union_tag { /* DMAMUX_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL36_tag;

typedef union MC_ME_PCTL38_union_tag { /* CRC_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL38_tag;

typedef union MC_ME_PCTL56_union_tag { /* ADCSD_8 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL56_tag;

typedef union MC_ME_PCTL57_union_tag { /* ADCSD_6 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL57_tag;

typedef union MC_ME_PCTL58_union_tag { /* ADCSD_4 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL58_tag;

typedef union MC_ME_PCTL59_union_tag { /* ADCSD_2 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL59_tag;

typedef union MC_ME_PCTL60_union_tag { /* ADCSD_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL60_tag;

typedef union MC_ME_PCTL67_union_tag { /* MCAN_4 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL67_tag;

typedef union MC_ME_PCTL68_union_tag { /* MCAN_3 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL68_tag;

typedef union MC_ME_PCTL69_union_tag { /* MCAN_2 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL69_tag;

typedef union MC_ME_PCTL70_union_tag { /* MCAN_1 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL70_tag;

typedef union MC_ME_PCTL72_union_tag { /* TTCAN Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL72_tag;

typedef union MC_ME_PCTL74_union_tag { /* CAN_RAM_CTRL Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL74_tag;

typedef union MC_ME_PCTL84_union_tag { /* LINFlexD_16 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL84_tag;

typedef union MC_ME_PCTL85_union_tag { /* LINFlexD_14 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL85_tag;

typedef union MC_ME_PCTL91_union_tag { /* LINFlexD_1 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL91_tag;

typedef union MC_ME_PCTL92_union_tag { /* LINFlexD_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL92_tag;

typedef union MC_ME_PCTL93_union_tag { /* DSPI_12 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL93_tag;

typedef union MC_ME_PCTL96_union_tag { /* DSPI_6 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL96_tag;

typedef union MC_ME_PCTL97_union_tag { /* DSPI_4 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL97_tag;

typedef union MC_ME_PCTL98_union_tag { /* DSPI_1 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL98_tag;

typedef union MC_ME_PCTL99_union_tag { /* DSPI_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL99_tag;

typedef union MC_ME_PCTL101_union_tag { /* IIC_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL101_tag;

typedef union MC_ME_PCTL104_union_tag { /* SENT_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL104_tag;

typedef union MC_ME_PCTL107_union_tag { /* FLEXRAY_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL107_tag;

typedef union MC_ME_PCTL111_union_tag { /* PSI5_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL111_tag;

typedef union MC_ME_PCTL112_union_tag { /* ADCSAR_b Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL112_tag;

typedef union MC_ME_PCTL123_union_tag { /* ADCSAR_4 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL123_tag;

typedef union MC_ME_PCTL127_union_tag { /* ADCSAR_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL127_tag;

typedef union MC_ME_PCTL128_union_tag { /* GTMINT Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL128_tag;

typedef union MC_ME_PCTL162_union_tag { /* PSI5_S_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL162_tag;

typedef union MC_ME_PCTL166_union_tag { /* CRC_1 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL166_tag;

typedef union MC_ME_PCTL184_union_tag { /* ADCSD_9 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL184_tag;

typedef union MC_ME_PCTL185_union_tag { /* ADCSD_7 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL185_tag;

typedef union MC_ME_PCTL186_union_tag { /* ADCSD_5 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL186_tag;

typedef union MC_ME_PCTL187_union_tag { /* ADCSD_3 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL187_tag;

typedef union MC_ME_PCTL188_union_tag { /* ADCSD_1 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL188_tag;

typedef union MC_ME_PCTL213_union_tag { /* LINFlexD_15 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL213_tag;

typedef union MC_ME_PCTL220_union_tag { /* LINFlexD_2 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL220_tag;

typedef union MC_ME_PCTL225_union_tag { /* DSPI_5 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL225_tag;

typedef union MC_ME_PCTL226_union_tag { /* DSPI_3 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL226_tag;

typedef union MC_ME_PCTL227_union_tag { /* DSPI_2 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL227_tag;

typedef union MC_ME_PCTL229_union_tag { /* IIC_1 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL229_tag;

typedef union MC_ME_PCTL232_union_tag { /* SENT_1 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL232_tag;

typedef union MC_ME_PCTL235_union_tag { /* FLEXRAY_1 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL235_tag;

typedef union MC_ME_PCTL239_union_tag { /* PSI5_1 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL239_tag;

typedef union MC_ME_PCTL245_union_tag { /* ADCSAR_10 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL245_tag;

typedef union MC_ME_PCTL246_union_tag { /* ADCSAR_9 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL246_tag;

typedef union MC_ME_PCTL247_union_tag { /* ADCSAR_8 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL247_tag;

typedef union MC_ME_PCTL248_union_tag { /* ADCSAR_7 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL248_tag;

typedef union MC_ME_PCTL249_union_tag { /* ADCSAR_6 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL249_tag;

typedef union MC_ME_PCTL250_union_tag { /* ADCSAR_5 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL250_tag;

typedef union MC_ME_PCTL252_union_tag { /* ADCSAR_3 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL252_tag;

typedef union MC_ME_PCTL253_union_tag { /* ADCSAR_2 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL253_tag;

typedef union MC_ME_PCTL254_union_tag { /* ADCSAR_1 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL254_tag;
#endif

typedef union MC_ME_CS_union_tag {     /* Core Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :27;
    vuint32_t S_CORE4:1;
    vuint32_t S_CORE3:1;
    vuint32_t S_CORE2:1;
    vuint32_t S_CORE1:1;
    vuint32_t S_CORE0:1;
  } B;
} MC_ME_CS_tag;

typedef union MC_ME_CCTL0_union_tag {  /* CORE0 Core Control Register */
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL0_tag;

typedef union MC_ME_CCTL1_union_tag {  /* CORE1 Core Control Register */
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL1_tag;

typedef union MC_ME_CCTL2_union_tag {  /* CORE2 Core Control Register */
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL2_tag;

typedef union MC_ME_CCTL3_union_tag {  /* CORE3 Core Control Register */
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL3_tag;

typedef union MC_ME_CCTL4_union_tag {  /* CORE4 Core Control Register */
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL4_tag;

typedef union MC_ME_CCTL5_union_tag {
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL5_tag;

typedef union MC_ME_CCTL6_union_tag {
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL6_tag;

typedef union MC_ME_CCTL7_union_tag {
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL7_tag;

typedef union MC_ME_CCTL8_union_tag {
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL8_tag;

typedef union MC_ME_CCTL9_union_tag {
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL9_tag;

typedef union MC_ME_CCTL10_union_tag {
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL10_tag;

typedef union MC_ME_CCTL11_union_tag {
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL11_tag;
typedef union MC_ME_CADDR0_union_tag { /* CORE0 Core Address Register */
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR0_tag;

typedef union MC_ME_CADDR1_union_tag { /* CORE1 Core Address Register */
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR1_tag;

typedef union MC_ME_CADDR2_union_tag { /* CORE2 Core Address Register */
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR2_tag;

typedef union MC_ME_CADDR3_union_tag { /* CORE3 Core Address Register */
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR3_tag;

typedef union MC_ME_CADDR4_union_tag { /* CORE4 Core Address Register */
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR4_tag;

typedef union MC_ME_CADDR5_union_tag {
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR5_tag;

typedef union MC_ME_CADDR6_union_tag {
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR6_tag;

typedef union MC_ME_CADDR7_union_tag {
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR7_tag;

typedef union MC_ME_CADDR8_union_tag {
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR8_tag;

typedef union MC_ME_CADDR9_union_tag {
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR9_tag;

typedef union MC_ME_CADDR10_union_tag {
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR10_tag;

typedef union MC_ME_CADDR11_union_tag {
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR11_tag;
struct MC_ME_tag {
  MC_ME_GS_tag GS;                     /* Global Status Register */
  MC_ME_MCTL_tag MCTL;                 /* Mode Control Register */
  MC_ME_ME_tag ME;                     /* Mode Enable Register */
  MC_ME_IS_tag IS;                     /* Interrupt Status Register */
  MC_ME_IM_tag IM;                     /* Interrupt Mask Register */
  MC_ME_IMTS_tag IMTS;                 /* Invalid Mode Transition Status Register */
  MC_ME_DMTS_tag DMTS;                 /* Debug Mode Transition Status Register */
  uint8_t MC_ME_reserved0[4];
  MC_ME_RESET_MC_tag RESET_MC;         /* RESET Mode Configuration Register */
  MC_ME_TEST_MC_tag TEST_MC;           /* TEST Mode Configuration Register */
  MC_ME_SAFE_MC_tag SAFE_MC;           /* SAFE Mode Configuration Register */
  MC_ME_DRUN_MC_tag DRUN_MC;           /* DRUN Mode Configuration Register */
  MC_ME_RUN_MC_tag RUN_MC[4];          /* RUN0 Mode Configuration Register */
  MC_ME_HALT0_MC_tag HALT0_MC;         /* HALT0 Mode Configuration Register */
  uint8_t MC_ME_reserved1[4];
  MC_ME_STOP0_MC_tag STOP0_MC;         /* STOP0 Mode Configuration Register */
#if defined(CCFC3008PT)
/* CCFC3008PT unsupported STANDBY. */
  uint8_t MC_ME_reserved2[20];
#else
  uint8_t MC_ME_reserved2[8];
  MC_ME_STANDBY_MC_tag STANDBY_MC;     /* STANDBY Mode Configuration Register */
  uint8_t MC_ME_reserved3[8];
#endif
  MC_ME_PS0_tag PS_0;                  /* Peripheral Status Register 0 */
  MC_ME_PS1_tag PS_1;                  /* Peripheral Status Register 1 */
  MC_ME_PS2_tag PS_2;                  /* Peripheral Status Register 2 */
  MC_ME_PS3_tag PS_3;                  /* Peripheral Status Register 3 */
  MC_ME_PS4_tag PS_4;                  /* Peripheral Status Register 4 */
  MC_ME_PS5_tag PS_5;                  /* Peripheral Status Register 5 */
  MC_ME_PS6_tag PS_6;                  /* Peripheral Status Register 6 */
  MC_ME_PS7_tag PS_7;                  /* Peripheral Status Register 7 */
  MC_ME_RUN_PC_tag RUN_PC[8];          /* Run Peripheral Configuration Register */
  MC_ME_LP_PC_tag LP_PC[8];            /* Low-Power Peripheral Configuration Register */

  MC_ME_PCTL_tag PCTL[255];            /* Peripheral Control Registers 0 ~ 254 */
  uint8_t MC_ME_reserved35[1];
  MC_ME_CS_tag CS;                     /* Core Status Register */
#if (defined(CCFC3012PT) || defined(CCFC3011PT) || defined(CCFC3010PT) || defined(CCFC3010PTD))
  MC_ME_CCTL0_tag CCTL0;               /* CORE0 Core Control Register */
  MC_ME_CCTL1_tag CCTL1;               /* CORE0 Checker Core Control Register */
  MC_ME_CCTL2_tag CCTL2;               /* CORE1 Core Control Register */
  MC_ME_CCTL3_tag CCTL3;               /* CORE1 Checker Core Control Register */
  MC_ME_CCTL4_tag CCTL4;               /* HSM Core Control Register */
  MC_ME_CCTL5_tag CCTL5;                           /* Reserved */
  MC_ME_CCTL6_tag CCTL6;               /* CORE2 Core Control Register */
  MC_ME_CCTL7_tag CCTL7;               /* CORE2 Checker Core Control Register */
  MC_ME_CCTL8_tag CCTL8;               /* CORE3 Core Control Register */
  MC_ME_CCTL9_tag CCTL9;               /* CORE3 Checker Core Control Register */
  MC_ME_CCTL10_tag CCTL10;             /* CORE4 Core Control Register */
  MC_ME_CCTL11_tag CCTL11;             /* CORE5 Core Control Register */
  uint8_t MC_ME_reserved36[36];
  MC_ME_CADDR0_tag CADDR0;             /* CORE0 Core Address Register */
  MC_ME_CADDR1_tag CADDR1;             /* CORE0 Checker Core Address Register */
  MC_ME_CADDR2_tag CADDR2;             /* CORE1 Core Address Register */
  MC_ME_CADDR3_tag CADDR3;             /* CORE1 Checker Core Address Register */
  MC_ME_CADDR4_tag CADDR4;             /* HSM Core Address Register */
  MC_ME_CADDR5_tag CADDR5;             /* Reserved */
  MC_ME_CADDR6_tag CADDR6;             /* CORE2 Core Address Register */
  MC_ME_CADDR7_tag CADDR7;             /* CORE2 Checker Core Address Register */
  MC_ME_CADDR8_tag CADDR8;             /* CORE3 Core Address Register */
  MC_ME_CADDR9_tag CADDR9;             /* CORE3 Checker Core Address Register */
  MC_ME_CADDR10_tag CADDR10;            /* CORE4 Core Address Register */
  MC_ME_CADDR11_tag CADDR11;            /* CORE5 Core Address Register */
#else
  MC_ME_CCTL0_tag CCTL0;               /* CORE0 Core Control Register */
  MC_ME_CCTL1_tag CCTL1;               /* CORE1 Core Control Register */
  MC_ME_CCTL2_tag CCTL2;               /* CORE2 Core Control Register */
  MC_ME_CCTL3_tag CCTL3;               /* CORE3 Core Control Register */
  MC_ME_CCTL4_tag CCTL4;               /* CORE4 Core Control Register */
  uint8_t MC_ME_reserved36[18];
  MC_ME_CADDR0_tag CADDR0;             /* CORE0 Core Address Register */
  MC_ME_CADDR1_tag CADDR1;             /* CORE1 Core Address Register */
  MC_ME_CADDR2_tag CADDR2;             /* CORE2 Core Address Register */
  MC_ME_CADDR3_tag CADDR3;             /* CORE3 Core Address Register */
  MC_ME_CADDR4_tag CADDR4;             /* CORE4 Core Address Register */
#endif
};



/*******************************************************************************
 * MC_ME Register Bit Fields
 *******************************************************************************/
/* GS Bit Fields */
#define MC_ME_GS_S_SYSCLK_MASK                   0xFu
#define MC_ME_GS_S_SYSCLK_SHIFT                  0u
#define MC_ME_GS_S_SYSCLK_WIDTH                  4u
#define MC_ME_GS_S_SYSCLK(x)                     (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_GS_S_SYSCLK_SHIFT)) \
                                                  &MC_ME_GS_S_SYSCLK_MASK)
#define MC_ME_GS_S_IRC_MASK                      0x10u
#define MC_ME_GS_S_IRC_SHIFT                     4u
#define MC_ME_GS_S_IRC_WIDTH                     1u
#define MC_ME_GS_S_IRC(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_GS_S_IRC_SHIFT)) \
                                                  &MC_ME_GS_S_IRC_MASK)
#define MC_ME_GS_S_XOSC_MASK                     0x20u
#define MC_ME_GS_S_XOSC_SHIFT                    5u
#define MC_ME_GS_S_XOSC_WIDTH                    1u
#define MC_ME_GS_S_XOSC(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_GS_S_XOSC_SHIFT)) \
                                                  &MC_ME_GS_S_XOSC_MASK)
#define MC_ME_GS_S_PLL0_MASK                     0x40u
#define MC_ME_GS_S_PLL0_SHIFT                    6u
#define MC_ME_GS_S_PLL0_WIDTH                    1u
#define MC_ME_GS_S_PLL0(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_GS_S_PLL0_SHIFT)) \
                                                  &MC_ME_GS_S_PLL0_MASK)
#define MC_ME_GS_S_PLL1_MASK                     0x80u
#define MC_ME_GS_S_PLL1_SHIFT                    7u
#define MC_ME_GS_S_PLL1_WIDTH                    1u
#define MC_ME_GS_S_PLL1(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_GS_S_PLL1_SHIFT)) \
                                                  &MC_ME_GS_S_PLL1_MASK)
/* MCTL Bit Fields */
#define MC_ME_MCTL_KEY_MASK                      0xFFFFu
#define MC_ME_MCTL_KEY_SHIFT                     0u
#define MC_ME_MCTL_KEY_WIDTH                     16u
#define MC_ME_MCTL_KEY(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_MCTL_KEY_SHIFT)) \
                                                  &MC_ME_MCTL_KEY_MASK)
#define MC_ME_MCTL_TARGET_MODE_MASK              0xF0000000u
#define MC_ME_MCTL_TARGET_MODE_SHIFT             28u
#define MC_ME_MCTL_TARGET_MODE_WIDTH             4u
#define MC_ME_MCTL_TARGET_MODE(x)                (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_MCTL_TARGET_MODE_SHIFT)) \
                                                  &MC_ME_MCTL_TARGET_MODE_MASK)
/* ME Bit Fields */
#define MC_ME_ME_RESET_FUNC_MASK                 0x1u
#define MC_ME_ME_RESET_FUNC_SHIFT                0u
#define MC_ME_ME_RESET_FUNC_WIDTH                1u
#define MC_ME_ME_RESET_FUNC(x)                   (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_ME_RESET_FUNC_SHIFT)) \
                                                  &MC_ME_ME_RESET_FUNC_MASK)
#define MC_ME_ME_TEST_MASK                       0x2u
#define MC_ME_ME_TEST_SHIFT                      1u
#define MC_ME_ME_TEST_WIDTH                      1u
#define MC_ME_ME_TEST(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_ME_TEST_SHIFT)) \
                                                  &MC_ME_ME_TEST_MASK)
#define MC_ME_ME_SAFE_MASK                       0x4u
#define MC_ME_ME_SAFE_SHIFT                      2u
#define MC_ME_ME_SAFE_WIDTH                      1u
#define MC_ME_ME_SAFE(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_ME_SAFE_SHIFT)) \
                                                  &MC_ME_ME_SAFE_MASK)
#define MC_ME_ME_DRUN_MASK                       0x8u
#define MC_ME_ME_DRUN_SHIFT                      3u
#define MC_ME_ME_DRUN_WIDTH                      1u
#define MC_ME_ME_DRUN(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_ME_DRUN_SHIFT)) \
                                                  &MC_ME_ME_DRUN_MASK)
#define MC_ME_ME_RUN0_MASK                       0x10u
#define MC_ME_ME_RUN0_SHIFT                      4u
#define MC_ME_ME_RUN0_WIDTH                      1u
#define MC_ME_ME_RUN0(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_ME_RUN0_SHIFT)) \
                                                  &MC_ME_ME_RUN0_MASK)
#define MC_ME_ME_RUN1_MASK                       0x20u
#define MC_ME_ME_RUN1_SHIFT                      5u
#define MC_ME_ME_RUN1_WIDTH                      1u
#define MC_ME_ME_RUN1(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_ME_RUN1_SHIFT)) \
                                                  &MC_ME_ME_RUN1_MASK)
#define MC_ME_ME_RUN2_MASK                       0x40u
#define MC_ME_ME_RUN2_SHIFT                      6u
#define MC_ME_ME_RUN2_WIDTH                      1u
#define MC_ME_ME_RUN2(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_ME_RUN2_SHIFT)) \
                                                  &MC_ME_ME_RUN2_MASK)
#define MC_ME_ME_RUN3_MASK                       0x80u
#define MC_ME_ME_RUN3_SHIFT                      7u
#define MC_ME_ME_RUN3_WIDTH                      1u
#define MC_ME_ME_RUN3(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_ME_RUN3_SHIFT)) \
                                                  &MC_ME_ME_RUN3_MASK)

#define MC_ME_ME_HALT0_MASK                      0x100u
#define MC_ME_ME_HALT0_SHIFT                     8u
#define MC_ME_ME_HALT0_WIDTH                     1u
#define MC_ME_ME_HALT0(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_ME_HALT0_SHIFT)) \
                                                  &MC_ME_ME_HALT0_MASK)
#define MC_ME_ME_STOP0_MASK                      0x400u
#define MC_ME_ME_STOP0_SHIFT                     10u
#define MC_ME_ME_STOP0_WIDTH                     1u
#define MC_ME_ME_STOP0(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_ME_STOP0_SHIFT)) \
                                                  &MC_ME_ME_STOP0_MASK)

#define MC_ME_ME_STANDBY_MASK                      0x2000u
#define MC_ME_ME_STANDBY_SHIFT                     13u
#define MC_ME_ME_STANDBY_WIDTH                     1u
#define MC_ME_ME_STANDBY(x)                        (((uint32)(((uint32)(x)) \
                                                   <<MC_ME_ME_STANDBY_SHIFT)) \
                                                   &MC_ME_ME_STANDBY_MASK)
/* PCTLn Bit Fields */
#define MC_ME_PCTLn_RUN_CFG_MASK                 0x7u
#define MC_ME_PCTLn_RUN_CFG_SHIFT                0u
#define MC_ME_PCTLn_RUN_CFG_WIDTH                3u
#define MC_ME_PCTLn_RUN_CFG(x)                   (((uint8)(((uint8)(x)) \
                                                  <<MC_ME_PCTLn_RUN_CFG_SHIFT)) \
                                                  &MC_ME_PCTLn_RUN_CFG_MASK)
#define MC_ME_PCTLn_LP_CFG_MASK                  0x38u
#define MC_ME_PCTLn_LP_CFG_SHIFT                 3u
#define MC_ME_PCTLn_LP_CFG_WIDTH                 3u
#define MC_ME_PCTLn_LP_CFG(x)                    (((uint8)(((uint8)(x)) \
                                                  <<MC_ME_PCTLn_LP_CFG_SHIFT)) \
                                                  &MC_ME_PCTLn_LP_CFG_MASK)

/********************************************************/
/*          Core Control Register (ME_CCTLn)            */
/********************************************************/
#define MC_ME_CCTL_RWBITS_MASK16                    ((uint16)0x00FEU)

#define MC_ME_CCTL_RUN3_MASK16                      ((uint16)0x0080U)
#define MC_ME_CCTL_RUN2_MASK16                      ((uint16)0x0040U)
#define MC_ME_CCTL_RUN1_MASK16                      ((uint16)0x0020U)
#define MC_ME_CCTL_RUN0_MASK16                      ((uint16)0x0010U)
#define MC_ME_CCTL_DRUN_MASK16                      ((uint16)0x0008U)
#define MC_ME_CCTL_SAFE_MASK16                      ((uint16)0x0004U)
#define MC_ME_CCTL_TEST_MASK16                      ((uint16)0x0002U)

#define MC_ME_CADDR_ADDR_MASK32                     ((uint32)0xFFFFFFFCU)
#define MC_ME_CADDR_RMC_MASK32                      ((uint32)0x00000001U)

#define MC_ME_CADDR_RESET_ENABLE                    (MC_ME_CADDR_RMC_MASK32)
#define MC_ME_CADDR_RESET_DISABLE                   ((uint32)0x00000000U)

#define MC_ME_CCTL_RUN3_ON                          (MC_ME_CCTL_RUN3_MASK16)
#define MC_ME_CCTL_RUN3_OFF                         ((uint16)0x0000)
        
#define MC_ME_CCTL_RUN2_ON                          (MC_ME_CCTL_RUN2_MASK16)
#define MC_ME_CCTL_RUN2_OFF                         ((uint16)0x0000)
        
#define MC_ME_CCTL_RUN1_ON                          (MC_ME_CCTL_RUN1_MASK16)
#define MC_ME_CCTL_RUN1_OFF                         ((uint16)0x0000)
        
#define MC_ME_CCTL_RUN0_ON                          (MC_ME_CCTL_RUN0_MASK16)
#define MC_ME_CCTL_RUN0_OFF                         ((uint16)0x0000)
        
#define MC_ME_CCTL_DRUN_ON                          (MC_ME_CCTL_DRUN_MASK16)
#define MC_ME_CCTL_DRUN_OFF                         ((uint16)0x0000)
        
#define MC_ME_CCTL_SAFE_ON                          (MC_ME_CCTL_SAFE_MASK16)
#define MC_ME_CCTL_SAFE_OFF                         ((uint16)0x0000)
        
#define MC_ME_CCTL_TEST_ON                          (MC_ME_CCTL_TEST_MASK16)
#define MC_ME_CCTL_TEST_OFF                         ((uint16)0x0000)

#endif  /* MC_ME_REG_H_ */
