#ifndef MC_RGM_REG_H_
#define MC_RGM_REG_H_

/* ============================================================================
   =============================== Module: MC_RGM =============================
   ============================================================================ */

typedef union MC_RGM_DES_union_tag {   /* 'Destructive' Event Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t F_VOR_DEST:1;
    vuint32_t F_TSR_DEST:1;
    vuint32_t  :7;
    vuint32_t F_HSM_DEST:1;
    vuint32_t F_SSCM_DEST:1;
    vuint32_t  :3;
    vuint32_t F_JTAG_DEST:1;
    vuint32_t F_FIF:1;
    vuint32_t F_EDR:1;
    vuint32_t  :2;
    vuint32_t F_SUF:1;
    vuint32_t F_FFRR:1;
    vuint32_t F_SOFT_DEST:1;
    vuint32_t  :1;
    vuint32_t F_PORST:1;
    vuint32_t F_POR:1;
  } B;
} MC_RGM_DES_tag;

typedef union MC_RGM_DERD_union_tag {  /* 'Destructive' Event Reset Disable Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t D_VOR_DEST:1;
    vuint32_t  :8;
    vuint32_t D_HSM_DEST:1;
    vuint32_t D_SSCM_DEST:1;
    vuint32_t  :3;
    vuint32_t D_JTAG_DEST:1;
    vuint32_t D_FIF:1;
    vuint32_t D_EDR:1;
    vuint32_t  :2;
    vuint32_t D_SUF:1;
    vuint32_t D_FFRR:1;
    vuint32_t D_SOFT_DEST:1;
    vuint32_t  :1;
    vuint32_t D_PORST:1;
    vuint32_t D_POR:1;
  } B;
} MC_RGM_DERD_tag;

typedef union MC_RGM_DEAR_union_tag {  /* 'Destructive' Event Alternate Request Register */
  vuint32_t R;
  struct {
    vuint32_t  :30;
    vuint32_t AR_PORST:1;
    vuint32_t  :1;
  } B;
} MC_RGM_DEAR_tag;

typedef union MC_RGM_DBRE_union_tag {  /* 'Destructive' Bidirectional Reset Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t BE_VOR_DEST:1;
    vuint32_t BE_TSR_DEST:1;
    vuint32_t  :7;
    vuint32_t BE_HSM_DEST:1;
    vuint32_t BE_SSCM_DEST:1;
    vuint32_t  :3;
    vuint32_t BE_JTAG_DEST:1;
    vuint32_t BE_FIF:1;
    vuint32_t BE_EDR:1;
    vuint32_t  :2;
    vuint32_t BE_SUF:1;
    vuint32_t BE_FFRR:1;
    vuint32_t BE_SOFT_DEST:1;
    vuint32_t  :1;
    vuint32_t BE_PORST:1;
    vuint32_t BE_POR:1;
  } B;
} MC_RGM_DBRE_tag;

typedef union MC_RGM_FES_union_tag {   /* 'Functional' Event Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t F_VOR_FUNC:1;
    vuint32_t F_TSR_FUNC:1;
    vuint32_t  :7;
    vuint32_t F_HSM_FUNC:1;
    vuint32_t  :4;
    vuint32_t F_JTAG_FUNC:1;
    vuint32_t  :3;
    vuint32_t F_FCCU_SOFT:1;
    vuint32_t F_FCCU_HARD:1;
    vuint32_t  :1;
    vuint32_t F_SOFT_FUNC:1;
    vuint32_t F_ST_DONE:1;
    vuint32_t F_ESR1:1;
    vuint32_t F_ESR0:1;
  } B;
} MC_RGM_FES_tag;

typedef union MC_RGM_FERD_union_tag {  /* 'Functional' Event Reset Disable Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t D_VOR_FUNC:1;
    vuint32_t D_TSR_FUNC:1;
    vuint32_t  :7;
    vuint32_t D_HSM_FUNC:1;
    vuint32_t  :4;
    vuint32_t D_JTAG_FUNC:1;
    vuint32_t  :3;
    vuint32_t D_FCCU_SOFT:1;
    vuint32_t D_FCCU_HARD:1;
    vuint32_t D_SOFT_FUNC:1;
    vuint32_t  :1;
    vuint32_t D_ST_DONE:1;
    vuint32_t D_ESR1:1;
    vuint32_t D_ESR0:1;
  } B;
} MC_RGM_FERD_tag;

typedef union MC_RGM_FEAR_union_tag {  /* 'Functional' Event Alternate Request Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t AR_VOR_FUNC:1;
    vuint32_t AR_TSR_FUNC:1;
    vuint32_t  :21;
    vuint32_t AR_ESR1:1;
    vuint32_t  :1;
  } B;
} MC_RGM_FEAR_tag;

typedef union MC_RGM_FBRE_union_tag {  /* 'Functional' Bidirectional Reset Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t BE_VOR_FUNC:1;
    vuint32_t BE_TSR_FUNC:1;
    vuint32_t  :7;
    vuint32_t BE_HSM_FUNC:1;
    vuint32_t  :4;
    vuint32_t BE_JTAG_FUNC:1;
    vuint32_t  :3;
    vuint32_t BE_FCCU_SOFT:1;
    vuint32_t BE_FCCU_HARD:1;
    vuint32_t  :1;
    vuint32_t BE_SOFT_FUNC:1;
    vuint32_t BE_ST_DONE:1;
    vuint32_t BE_ESR1:1;
    vuint32_t BE_ESR0:1;
  } B;
} MC_RGM_FBRE_tag;

typedef union MC_RGM_FESS_union_tag {  /* 'Functional' Event Short Sequence Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t SS_VOR_FUNC:1;
    vuint32_t SS_TSR_FUNC:1;
    vuint32_t  :7;
    vuint32_t SS_HSM_FUNC:1;
    vuint32_t  :4;
    vuint32_t SS_JTAG_FUNC:1;
    vuint32_t  :3;
    vuint32_t SS_FCCU_SOFT:1;
    vuint32_t SS_FCCU_HARD:1;
    vuint32_t  :1;
    vuint32_t SS_SOFT_FUNC:1;
    vuint32_t SS_ST_DONE:1;
    vuint32_t SS_ESR1:1;
    vuint32_t SS_ESR0:1;
  } B;
} MC_RGM_FESS_tag;

typedef union MC_RGM_FRET_union_tag {  /* 'Functional' Reset Escalation Threshold Register */
  vuint8_t R;
  struct {
    vuint8_t  :4;
    vuint8_t FRET:4;
  } B;
} MC_RGM_FRET_tag;

typedef union MC_RGM_DRET_union_tag {  /* 'Destructive' Reset Escalation Threshold Register */
  vuint8_t R;
  struct {
    vuint8_t  :4;
    vuint8_t DRET:4;
  } B;
} MC_RGM_DRET_tag;

typedef union MC_RGM_EROEC_union_tag { /* External Reset Output Extension Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :6;
    vuint8_t ERIS:1;
    vuint8_t EROEC:1;
  } B;
} MC_RGM_EROEC_tag;

typedef union MC_RGM_PRST0_union_tag { /* Peripheral Reset Register 0 */
  vuint32_t R;
  struct {
    vuint32_t PIT_RTC_1_RST:1;
    vuint32_t PIT_RTC_0_RST:1;
    vuint32_t  :14;
    vuint32_t SIUL_RST:1;
    vuint32_t  :3;
    vuint32_t SIPI_0_RST:1;
    vuint32_t  :1;
    vuint32_t LFAST_0_RST:1;
    vuint32_t  :5;
    vuint32_t EBI_0_RST:1;
    vuint32_t  :3;
  } B;
} MC_RGM_PRST0_tag;

#if defined(CCFC3008PT)
typedef union MC_RGM_PRST1_union_tag { /* Peripheral Reset Register 1 */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t ADCSD_0_RST:1;
    vuint32_t ADCSD_2_RST:1;
    vuint32_t ADCSD_4_RST:1;
    vuint32_t ADCSD_6_RST:1;
    vuint32_t ADCSD_8_RST:1;
    vuint32_t  :17;
    vuint32_t CRC_0_RST:1;
    vuint32_t  :1;
    vuint32_t DMAMUX_0_RST:1;
    vuint32_t  :4;
  } B;
} MC_RGM_PRST1_tag;
#else
typedef union MC_RGM_PRST1_union_tag { /* Peripheral Reset Register 1 */
  vuint32_t R;
  struct {
    vuint32_t  MCAN_12_RST:1;
    vuint32_t  :2;
    vuint32_t ADCSD_0_RST:1;
    vuint32_t ADCSD_2_RST:1;
    vuint32_t ADCSD_4_RST:1;
    vuint32_t ADCSD_6_RST:1;
    vuint32_t ADCSD_8_RST:1;
    vuint32_t  :17;
    vuint32_t CRC_0_RST:1;
    vuint32_t  :1;
    vuint32_t DMAMUX_0_RST:1;
    vuint32_t  :4;
  } B;
} MC_RGM_PRST1_tag;
#endif

#if defined(CCFC3008PT)
typedef union MC_RGM_PRST2_union_tag { /* Peripheral Reset Register 2 */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t DSPI_12_RST:1;
    vuint32_t LINFlexD_0_RST:1;
    vuint32_t LINFlexD_1_RST:1;
    vuint32_t  :5;
    vuint32_t LINFlexD_14_RST:1;
    vuint32_t LINFlexD_16_RST:1;
    vuint32_t  :9;
    vuint32_t CAN_RAM_CTR_RST:1;
    vuint32_t  :1;
    vuint32_t TTCAN_RST:1;
    vuint32_t  :1;
    vuint32_t MCAN_1_RST:1;
    vuint32_t MCAN_2_RST:1;
    vuint32_t MCAN_3_RST:1;
    vuint32_t MCAN_4_RST:1;
    vuint32_t  :3;
  } B;
} MC_RGM_PRST2_tag;
#else
typedef union MC_RGM_PRST2_union_tag { /* Peripheral Reset Register 2 */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t DSPI_12_RST:1;
    vuint32_t LINFlexD_0_RST:1;
    vuint32_t LINFlexD_1_RST:1;
    vuint32_t LINFlexD_3_RST:1;
    vuint32_t  :4;
    vuint32_t LINFlexD_14_RST:1;
    vuint32_t LINFlexD_16_RST:1;
    vuint32_t  :2;
    vuint32_t TTCAN_2_RST:1;
    vuint32_t MCAN_9_RST:1;
    vuint32_t MCAN_10_RST:1;
    vuint32_t MCAN_8_RST:1;
    vuint32_t MCAN_7_RST:1;
    vuint32_t MCAN_6_RST:1;
    vuint32_t MCAN_5_RST:1;
    vuint32_t CAN_RAM_CTR_RST:1;
    vuint32_t  :1;
    vuint32_t TTCAN_RST:1;
    vuint32_t  :1;
    vuint32_t MCAN_1_RST:1;
    vuint32_t MCAN_2_RST:1;
    vuint32_t MCAN_3_RST:1;
    vuint32_t MCAN_4_RST:1;
    vuint32_t CAN_RAM1_CTR_RST:1;
    vuint32_t  :1;
    vuint32_t MCAN_11_RST:1;
  } B;
} MC_RGM_PRST2_tag;
#endif

typedef union MC_RGM_PRST3_union_tag { /* Peripheral Reset Register 3 */
  vuint32_t R;
  struct {
    vuint32_t ADCSAR_0_RST:1;
    vuint32_t  :3;
    vuint32_t ADCSAR_4_RST:1;
    vuint32_t  :10;
    vuint32_t ADCSAR_b_RST:1;
    vuint32_t PSI5_0_RST:1;
    vuint32_t  :3;
    vuint32_t FLEXRAY_0_RST:1;
    vuint32_t  :2;
    vuint32_t SENT_0_RST:1;
    vuint32_t  :2;
    vuint32_t IIC_0_RST:1;
    vuint32_t  :1;
    vuint32_t DSPI_0_RST:1;
    vuint32_t DSPI_1_RST:1;
    vuint32_t DSPI_4_RST:1;
    vuint32_t DSPI_6_RST:1;
  } B;
} MC_RGM_PRST3_tag;

#if defined(CCFC3008PT)
typedef union MC_RGM_PRST4_union_tag { /* Peripheral Reset Register 4 */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t GTMINT_RST:1;
  } B;
} MC_RGM_PRST4_tag;
#else
typedef union MC_RGM_PRST4_union_tag { /* Peripheral Reset Register 4 */
  vuint32_t R;
  struct {
    vuint32_t  CANFD12:1;
    vuint32_t  CANFD11:1;
    vuint32_t  CANFD10:1;
    vuint32_t  CANFD9:1;
    vuint32_t  CANFD8:1;
    vuint32_t  CANFD7:1;
    vuint32_t  CANFD6:1;
    vuint32_t  CANFD5:1;
    vuint32_t  CANFD4:1;
    vuint32_t  CANFD3:1;
    vuint32_t  CANFD2:1;
    vuint32_t  CANFD1:1;
    vuint32_t  :13;
    vuint32_t  I2S0:1;
    vuint32_t  I2S1:1;
    vuint32_t  EMIOS1:1;
    vuint32_t  EMIOS0:1;
    vuint32_t  ETPU_C:1;
    vuint32_t  ETPU:1;
    vuint32_t GTMINT_RST:1;
  } B;
} MC_RGM_PRST4_tag;
#endif

typedef union MC_RGM_PRST5_union_tag { /* Peripheral Reset Register 5 */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t ADCSD_1_RST:1;
    vuint32_t ADCSD_3_RST:1;
    vuint32_t ADCSD_5_RST:1;
    vuint32_t ADCSD_7_RST:1;
    vuint32_t ADCSD_9_RST:1;
    vuint32_t  :14;
    vuint32_t FCCU_RST:1;
    vuint32_t  :2;
    vuint32_t CRC_1_RST:1;
    vuint32_t  :3;
    vuint32_t PSI5_S_0_RST:1;
    vuint32_t  :2;
  } B;
} MC_RGM_PRST5_tag;

#if defined(CCFC3008PT)
typedef union MC_RGM_PRST6_union_tag { /* Peripheral Reset Register 6 */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t LINFlexD_2_RST:1;
    vuint32_t  :6;
    vuint32_t LINFlexD_15_RST:1;
    vuint32_t  :21;
  } B;
} MC_RGM_PRST6_tag;
#else
typedef union MC_RGM_PRST6_union_tag { /* Peripheral Reset Register 6 */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t LINFlexD_2_RST:1;
    vuint32_t LINFlexD_7_RST:1;
    vuint32_t LINFlexD_8_RST:1;
    vuint32_t LINFlexD_9_RST:1;
    vuint32_t LINFlexD_10_RST:1;
    vuint32_t LINFlexD_11_RST:1;
    vuint32_t LINFlexD_12_RST:1;
    vuint32_t LINFlexD_15_RST:1;
    vuint32_t  :21;
  } B;
} MC_RGM_PRST6_tag;
#endif

typedef union MC_RGM_PRST7_union_tag { /* Peripheral Reset Register 7 */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t ADCSAR_1_RST:1;
    vuint32_t ADCSAR_2_RST:1;
    vuint32_t ADCSAR_3_RST:1;
    vuint32_t  :1;
    vuint32_t ADCSAR_5_RST:1;
    vuint32_t ADCSAR_6_RST:1;
    vuint32_t ADCSAR_7_RST:1;
    vuint32_t ADCSAR_8_RST:1;
    vuint32_t ADCSAR_9_RST:1;
    vuint32_t ADCSAR_10_RST:1;
    vuint32_t  :5;
    vuint32_t PSI5_1_RST:1;
    vuint32_t  :3;
    vuint32_t FLEXRAY_1_RST:1;
    vuint32_t  :2;
    vuint32_t SENT_1_RST:1;
    vuint32_t  :2;
    vuint32_t IIC_1_RST:1;
    vuint32_t  :1;
    vuint32_t DSPI_2_RST:1;
    vuint32_t DSPI_3_RST:1;
    vuint32_t DSPI_5_RST:1;
    vuint32_t  :1;
  } B;
} MC_RGM_PRST7_tag;

struct MC_RGM_tag {
  MC_RGM_DES_tag DES;                  /* 'Destructive' Event Status Register */
  uint8_t MC_RGM_reserved0[12];
  MC_RGM_DERD_tag DERD;                /* 'Destructive' Event Reset Disable Register */
  uint8_t MC_RGM_reserved1[12];
  MC_RGM_DEAR_tag DEAR;                /* 'Destructive' Event Alternate Request Register */
  uint8_t MC_RGM_reserved2[12];
  MC_RGM_DBRE_tag DBRE;                /* 'Destructive' Bidirectional Reset Enable Register */
  uint8_t MC_RGM_reserved3[716];
  MC_RGM_FES_tag FES;                  /* 'Functional' Event Status Register */
  uint8_t MC_RGM_reserved4[12];
  MC_RGM_FERD_tag FERD;                /* 'Functional' Event Reset Disable Register */
  uint8_t MC_RGM_reserved5[12];
  MC_RGM_FEAR_tag FEAR;                /* 'Functional' Event Alternate Request Register */
  uint8_t MC_RGM_reserved6[12];
  MC_RGM_FBRE_tag FBRE;                /* 'Functional' Bidirectional Reset Enable Register */
  uint8_t MC_RGM_reserved7[12];
  MC_RGM_FESS_tag FESS;                /* 'Functional' Event Short Sequence Register */
  uint8_t MC_RGM_reserved8[704];
  MC_RGM_FRET_tag FRET;                /* 'Functional' Reset Escalation Threshold Register */
  uint8_t MC_RGM_reserved9[3];
  MC_RGM_DRET_tag DRET;                /* 'Destructive' Reset Escalation Threshold Register */
  uint8_t MC_RGM_reserved10[3];
  MC_RGM_EROEC_tag EROEC;              /* External Reset Output Extension Control Register */
  uint8_t MC_RGM_reserved11[3];
  MC_RGM_PRST0_tag PRST0;              /* Peripheral Reset Register 0 */
  MC_RGM_PRST1_tag PRST1;              /* Peripheral Reset Register 1 */
  MC_RGM_PRST2_tag PRST2;              /* Peripheral Reset Register 2 */
  MC_RGM_PRST3_tag PRST3;              /* Peripheral Reset Register 3 */
  MC_RGM_PRST4_tag PRST4;              /* Peripheral Reset Register 4 */
  MC_RGM_PRST5_tag PRST5;              /* Peripheral Reset Register 5 */
  MC_RGM_PRST6_tag PRST6;              /* Peripheral Reset Register 6 */
  MC_RGM_PRST7_tag PRST7;              /* Peripheral Reset Register 7 */
};



/*******************************************************************************
 * MC_RGM Register Bit Fields
 *******************************************************************************/
#define RGM_DES_RWBITS_MASK32                    ((uint32)0x0180C73BU)
#define RGM_FES_RWBITS_MASK32                    ((uint32)0x0180846FU)

#endif  /* MC_RGM_REG_H_ */
