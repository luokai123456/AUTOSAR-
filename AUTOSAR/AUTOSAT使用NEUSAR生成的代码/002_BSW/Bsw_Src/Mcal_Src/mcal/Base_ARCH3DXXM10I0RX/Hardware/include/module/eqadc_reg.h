#ifndef EQADC_REG_H_
#define EQADC_REG_H_

/* ============================================================================
   =============================== Module: EQADC ==============================
   ============================================================================ */

typedef union EQADC_MCR_union_tag {    /* EQADC Module Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t CS_EN7:1;
    vuint32_t CS_ST7:1;
    vuint32_t CS_EN6:1;
    vuint32_t CS_ST6:1;
    vuint32_t CS_EN5:1;
    vuint32_t CS_ST5:1;
    vuint32_t CS_EN4:1;
    vuint32_t CS_ST4:1;
    vuint32_t CS_EN3:1;
    vuint32_t CS_ST3:1;
    vuint32_t CS_EN2:1;
    vuint32_t CS_ST2:1;
    vuint32_t CS_EN1:1;
    vuint32_t CS_ST1:1;
    vuint32_t CS_EN0:1;
    vuint32_t CS_ST0:1;
    vuint32_t  :8;
    vuint32_t ICEA0:1;
    vuint32_t ICEA1:1;
    vuint32_t DAM:1;
    vuint32_t  :2;
    vuint32_t  :1;
    vuint32_t DBG:2;
  } B;
} EQADC_MCR_tag;

typedef union EQADC_TST_union_tag {    /* EQADC Test Register */
  vuint32_t R;
  struct {
    vuint32_t  :32;
  } B;
} EQADC_TST_tag;

typedef union EQADC_ETDFR_union_tag {  /* EQADC External Trigger Digital Filter Register */
  vuint32_t R;
  struct {
    vuint32_t  :28;
    vuint32_t DFL:4;
  } B;
} EQADC_ETDFR_tag;

typedef union EQADC_CFPR_union_tag {   /* EQADC CFIFO Push Register */
  vuint32_t R;
  struct {
    vuint32_t CF_PUSHX:32;
  } B;
} EQADC_CFPR_tag;

typedef union EQADC_RFPR_union_tag {   /* EQADC Result FIFO Pop Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t RF_ADC_NUM:1;
    vuint32_t RF_CH_NUM:8;
    vuint32_t RF_POPX:16;
  } B;
} EQADC_RFPR_tag;

typedef union EQADC_CFCR0_union_tag {  /* EQADC CFIFO Control Register 0 */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t CFEEE0:1;
    vuint32_t STRME0:1;
    vuint32_t SSE0:1;
    vuint32_t CFINV0:1;
    vuint32_t  :1;
    vuint32_t MODE0:4;
    vuint32_t AMODE0:4;
    vuint32_t  :5;
    vuint32_t SSE1:1;
    vuint32_t CFINV1:1;
    vuint32_t  :1;
    vuint32_t MODE1:4;
    vuint32_t  :4;
  } B;
} EQADC_CFCR0_tag;

typedef union EQADC_CFCR1_union_tag {  /* EQADC CFIFO Control Register 1 */
  vuint32_t R;
  struct {
    vuint32_t  :5;
    vuint32_t SSE2:1;
    vuint32_t CFINV2:1;
    vuint32_t  :1;
    vuint32_t MODE2:4;
    vuint32_t  :9;
    vuint32_t SSE3:1;
    vuint32_t CFINV3:1;
    vuint32_t  :1;
    vuint32_t MODE3:4;
    vuint32_t  :4;
  } B;
} EQADC_CFCR1_tag;

typedef union EQADC_CFCR2_union_tag {  /* EQADC CFIFO Control Register 2 */
  vuint32_t R;
  struct {
    vuint32_t  :5;
    vuint32_t SSE4:1;
    vuint32_t CFINV4:1;
    vuint32_t  :1;
    vuint32_t MODE4:4;
    vuint32_t  :9;
    vuint32_t SSE5:1;
    vuint32_t CFINV5:1;
    vuint32_t  :1;
    vuint32_t MODE5:4;
    vuint32_t  :4;
  } B;
} EQADC_CFCR2_tag;

typedef union EQADC_CFCR3_union_tag {  /* EQADC CFIFO Control Register 3 */
  vuint32_t R;
  struct {
    vuint32_t  :5;
    vuint32_t SSE6:1;
    vuint32_t CFINV6:1;
    vuint32_t INJ_EN6:1;
    vuint32_t MODE6:4;
    vuint32_t  :9;
    vuint32_t SSE7:1;
    vuint32_t CFINV7:1;
    vuint32_t INJ_EN7:1;
    vuint32_t MODE7:4;
    vuint32_t  :4;
  } B;
} EQADC_CFCR3_tag;

typedef union EQADC_IDCR0_union_tag {  /* EQADC Interrupt and DMA Control Register 0 */
  vuint32_t R;
  struct {
    vuint32_t NCIE0:1;
    vuint32_t TORIE0:1;
    vuint32_t PIE0:1;
    vuint32_t EOQIE0:1;
    vuint32_t CFUIE0:1;
    vuint32_t  :1;
    vuint32_t CFFE0:1;
    vuint32_t CFFS0:1;
    vuint32_t  :4;
    vuint32_t RFOIE0:1;
    vuint32_t  :1;
    vuint32_t RFDE0:1;
    vuint32_t RFDS0:1;
    vuint32_t NCIE1:1;
    vuint32_t TORIE1:1;
    vuint32_t PIE1:1;
    vuint32_t EOQIE1:1;
    vuint32_t CFUIE1:1;
    vuint32_t  :1;
    vuint32_t CFFE1:1;
    vuint32_t CFFS1:1;
    vuint32_t  :4;
    vuint32_t RFOIE1:1;
    vuint32_t  :1;
    vuint32_t RFDE1:1;
    vuint32_t RFDS1:1;
  } B;
} EQADC_IDCR0_tag;

typedef union EQADC_IDCR1_union_tag {  /* EQADC Interrupt and DMA Control Register 1 */
  vuint32_t R;
  struct {
    vuint32_t NCIE2:1;
    vuint32_t TORIE2:1;
    vuint32_t PIE2:1;
    vuint32_t EOQIE2:1;
    vuint32_t CFUIE2:1;
    vuint32_t  :1;
    vuint32_t CFFE2:1;
    vuint32_t CFFS2:1;
    vuint32_t  :4;
    vuint32_t RFOIE2:1;
    vuint32_t  :1;
    vuint32_t RFDE2:1;
    vuint32_t RFDS2:1;
    vuint32_t NCIE3:1;
    vuint32_t TORIE3:1;
    vuint32_t PIE3:1;
    vuint32_t EOQIE3:1;
    vuint32_t CFUIE3:1;
    vuint32_t  :1;
    vuint32_t CFFE3:1;
    vuint32_t CFFS3:1;
    vuint32_t  :4;
    vuint32_t RFOIE3:1;
    vuint32_t  :1;
    vuint32_t RFDE3:1;
    vuint32_t RFDS3:1;
  } B;
} EQADC_IDCR1_tag;

typedef union EQADC_IDCR2_union_tag {  /* EQADC Interrupt and DMA Control Register 2 */
  vuint32_t R;
  struct {
    vuint32_t NCIE4:1;
    vuint32_t TORIE4:1;
    vuint32_t PIE4:1;
    vuint32_t EOQIE4:1;
    vuint32_t CFUIE4:1;
    vuint32_t  :1;
    vuint32_t CFFE4:1;
    vuint32_t CFFS4:1;
    vuint32_t  :4;
    vuint32_t RFOIE4:1;
    vuint32_t  :1;
    vuint32_t RFDE4:1;
    vuint32_t RFDS4:1;
    vuint32_t NCIE5:1;
    vuint32_t TORIE5:1;
    vuint32_t PIE5:1;
    vuint32_t EOQIE5:1;
    vuint32_t CFUIE5:1;
    vuint32_t  :1;
    vuint32_t CFFE5:1;
    vuint32_t CFFS5:1;
    vuint32_t  :4;
    vuint32_t RFOIE5:1;
    vuint32_t  :1;
    vuint32_t RFDE5:1;
    vuint32_t RFDS5:1;
  } B;
} EQADC_IDCR2_tag;

typedef union EQADC_IDCR3_union_tag {  /* EQADC Interrupt and DMA Control Register 3 */
  vuint32_t R;
  struct {
    vuint32_t NCIE6:1;
    vuint32_t TORIE6:1;
    vuint32_t PIE6:1;
    vuint32_t EOQIE6:1;
    vuint32_t CFUIE6:1;
    vuint32_t  :1;
    vuint32_t CFFE6:1;
    vuint32_t CFFS6:1;
    vuint32_t  :4;
    vuint32_t RFOIE6:1;
    vuint32_t  :1;
    vuint32_t RFDE6:1;
    vuint32_t RFDS6:1;
    vuint32_t NCIE7:1;
    vuint32_t TORIE7:1;
    vuint32_t PIE7:1;
    vuint32_t EOQIE7:1;
    vuint32_t CFUIE7:1;
    vuint32_t  :1;
    vuint32_t CFFE7:1;
    vuint32_t CFFS7:1;
    vuint32_t  :4;
    vuint32_t RFOIE7:1;
    vuint32_t  :1;
    vuint32_t RFDE7:1;
    vuint32_t RFDS7:1;
  } B;
} EQADC_IDCR3_tag;

typedef union EQADC_FISR_union_tag {   /* EQADC FIFO and Interrupt Status Register */
  vuint32_t R;
  struct {
    vuint32_t NCFX:1;
    vuint32_t TORFX:1;
    vuint32_t PFX:1;
    vuint32_t EOQFX:1;
    vuint32_t CFUFX:1;
    vuint32_t SSSX:1;
    vuint32_t CFFFX:1;
    vuint32_t  :5;
    vuint32_t RFOFX:1;
    vuint32_t  :1;
    vuint32_t RFDFX:1;
    vuint32_t  :1;
    vuint32_t CFCTRX:4;
    vuint32_t TNXTPTRX:4;
    vuint32_t RFCTRX:4;
    vuint32_t POPNXTPTRX:4;
  } B;
} EQADC_FISR_tag;

typedef union EQADC_CFTCR0_union_tag { /* EQADC CFIFO Transfer Counter Register 0 */
  vuint32_t R;
  struct {
    vuint32_t  :5;
    vuint32_t TC_CF0:11;
    vuint32_t  :5;
    vuint32_t TC_CF1:11;
  } B;
} EQADC_CFTCR0_tag;

typedef union EQADC_CFTCR1_union_tag { /* EQADC CFIFO Transfer Counter Register 1 */
  vuint32_t R;
  struct {
    vuint32_t  :5;
    vuint32_t TC_CF2:11;
    vuint32_t  :5;
    vuint32_t TC_CF3:11;
  } B;
} EQADC_CFTCR1_tag;

typedef union EQADC_CFTCR2_union_tag { /* EQADC CFIFO Transfer Counter Register 2 */
  vuint32_t R;
  struct {
    vuint32_t  :5;
    vuint32_t TC_CF4:11;
    vuint32_t  :5;
    vuint32_t TC_CF5:11;
  } B;
} EQADC_CFTCR2_tag;

typedef union EQADC_CFTCR3_union_tag { /* EQADC CFIFO Transfer Counter Register 3 */
  vuint32_t R;
  struct {
    vuint32_t  :5;
    vuint32_t TC_CF6:11;
    vuint32_t  :5;
    vuint32_t TC_CF7:11;
  } B;
} EQADC_CFTCR3_tag;

typedef union EQADC_CFSSR0_union_tag { /* EQADC CFIFO Status Snapshot Register 0 */
  vuint32_t R;
  struct {
    vuint32_t CFS0_TCB0:2;
    vuint32_t CFS1_TCB0:2;
    vuint32_t CFS2_TCB0:2;
    vuint32_t CFS3_TCB0:2;
    vuint32_t CFS4_TCB0:2;
    vuint32_t CFS5_TCB0:2;
    vuint32_t CFS6_TCB0:2;
    vuint32_t CFS7_TCB0:2;
    vuint32_t  :1;
    vuint32_t LCFTCB0:4;
    vuint32_t TC_LCFTCB0:11;
  } B;
} EQADC_CFSSR0_tag;

typedef union EQADC_CFSSR1_union_tag { /* EQADC CFIFO Status Snapshot Register 1 */
  vuint32_t R;
  struct {
    vuint32_t CFS0_TCB1:2;
    vuint32_t CFS1_TCB1:2;
    vuint32_t CFS2_TCB1:2;
    vuint32_t CFS3_TCB1:2;
    vuint32_t CFS4_TCB1:2;
    vuint32_t CFS5_TCB1:2;
    vuint32_t CFS6_TCB1:2;
    vuint32_t CFS7_TCB1:2;
    vuint32_t  :1;
    vuint32_t LCFTCB1:4;
    vuint32_t TC_LCFTCB1:11;
  } B;
} EQADC_CFSSR1_tag;

typedef union EQADC_CFSR_union_tag {   /* EQADC CFIFO Status Register */
  vuint32_t R;
  struct {
    vuint32_t CFS0:2;
    vuint32_t CFS1:2;
    vuint32_t CFS2:2;
    vuint32_t CFS3:2;
    vuint32_t CFS4:2;
    vuint32_t CFS5:2;
    vuint32_t CFS6:2;
    vuint32_t CFS7:2;
    vuint32_t  :16;
  } B;
} EQADC_CFSR_tag;

typedef union EQADC_STACCCR_union_tag { /* EQADC STAC Bus Client Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t STACBS2:4;
    vuint32_t SRV2:4;
    vuint32_t STACBS1:4;
    vuint32_t SRV1:4;
  } B;
} EQADC_STACCCR_tag;

typedef union EQADC_CF0R_union_tag {   /* EQADC CFIFO0 Register */
  vuint32_t R;
  struct {
    vuint32_t CFIFO0_DATAW:32;
  } B;
} EQADC_CF0R_tag;

typedef union EQADC_CF0ER_union_tag {  /* EQADC CFIFO0 Extension Register */
  vuint32_t R;
  struct {
    vuint32_t CFIFO0_EDATAW:32;
  } B;
} EQADC_CF0ER_tag;

typedef union EQADC_CF1R_union_tag {   /* EQADC CFIFO1 Register */
  vuint32_t R;
  struct {
    vuint32_t CFIFO1_DATAW:32;
  } B;
} EQADC_CF1R_tag;

typedef union EQADC_CF2R_union_tag {   /* EQADC CFIFO2 Register */
  vuint32_t R;
  struct {
    vuint32_t CFIFO2_DATAW:32;
  } B;
} EQADC_CF2R_tag;

typedef union EQADC_CF3R_union_tag {   /* EQADC CFIFO3 Register */
  vuint32_t R;
  struct {
    vuint32_t CFIFO3_DATAW:32;
  } B;
} EQADC_CF3R_tag;

typedef union EQADC_CF4R_union_tag {   /* EQADC CFIFO4 Register */
  vuint32_t R;
  struct {
    vuint32_t CFIFO4_DATAW:32;
  } B;
} EQADC_CF4R_tag;

typedef union EQADC_CF5R_union_tag {   /* EQADC CFIFO5 Register */
  vuint32_t R;
  struct {
    vuint32_t CFIFO5_DATAW:32;
  } B;
} EQADC_CF5R_tag;

typedef union EQADC_CF6R_union_tag {   /* EQADC CFIFO6 Register */
  vuint32_t R;
  struct {
    vuint32_t CFIFO6_DATAW:32;
  } B;
} EQADC_CF6R_tag;

typedef union EQADC_CF7R_union_tag {   /* EQADC CFIFO7 Register */
  vuint32_t R;
  struct {
    vuint32_t CFIFO7_DATAW:32;
  } B;
} EQADC_CF7R_tag;

typedef union EQADC_RF0R_union_tag {   /* EQADC RFIFO0 Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t RFIFO0_ADC_NUM:1;
    vuint32_t RFIFO0_CH_NUM:8;
    vuint32_t RFIFO0_DATAW:16;
  } B;
} EQADC_RF0R_tag;

typedef union EQADC_RF1R_union_tag {   /* EQADC RFIFO1 Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t RFIFO1_ADC_NUM:1;
    vuint32_t RFIFO1_CH_NUM:8;
    vuint32_t RFIFO1_DATAW:16;
  } B;
} EQADC_RF1R_tag;

typedef union EQADC_RF2R_union_tag {   /* EQADC RFIFO2 Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t RFIFO2_ADC_NUM:1;
    vuint32_t RFIFO2_CH_NUM:8;
    vuint32_t RFIFO2_DATAW:16;
  } B;
} EQADC_RF2R_tag;

typedef union EQADC_RF3R_union_tag {   /* EQADC RFIFO3 Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t RFIFO3_ADC_NUM:1;
    vuint32_t RFIFO3_CH_NUM:8;
    vuint32_t RFIFO3_DATAW:16;
  } B;
} EQADC_RF3R_tag;

typedef union EQADC_RF4R_union_tag {   /* EQADC RFIFO4 Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t RFIFO4_ADC_NUM:1;
    vuint32_t RFIFO4_CH_NUM:8;
    vuint32_t RFIFO4_DATAW:16;
  } B;
} EQADC_RF4R_tag;

typedef union EQADC_RF5R_union_tag {   /* EQADC RFIFO5 Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t RFIFO5_ADC_NUM:1;
    vuint32_t RFIFO5_CH_NUM:8;
    vuint32_t RFIFO5_DATAW:16;
  } B;
} EQADC_RF5R_tag;

typedef union EQADC_RF6R_union_tag {   /* EQADC RFIFO6 Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t RFIFO6_ADC_NUM:1;
    vuint32_t RFIFO6_CH_NUM:8;
    vuint32_t RFIFO6_DATAW:16;
  } B;
} EQADC_RF6R_tag;

typedef union EQADC_RF7R_union_tag {   /* EQADC RFIFO7 Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t RFIFO7_ADC_NUM:1;
    vuint32_t RFIFO7_CH_NUM:8;
    vuint32_t RFIFO7_DATAW:16;
  } B;
} EQADC_RF7R_tag;

typedef union EQADC_DLY_union_tag {   /* EQADC CFIFO Trigger Delay Register */
  vuint32_t R;
  struct {
    vuint32_t DLY_EN:1;
    vuint32_t  :11;
    vuint32_t DLY_CFG:20;
  } B;
} EQADC_DLY_tag;

typedef union EQADC_RFSRR_union_tag {   /* EQADC RFIFO Software Reset Register */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t RF_SW7:1;
    vuint32_t RF_SW6:1;
    vuint32_t RF_SW5:1;
    vuint32_t RF_SW4:1;
    vuint32_t RF_SW3:1;
    vuint32_t RF_SW2:1;
    vuint32_t RF_SW1:1;
    vuint32_t RF_SW0:1;
  } B;
} EQADC_RFSRR_tag;

typedef union EQADC_DMA_SEL_union_tag {   /* EQADC DMA Select Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t RF7_DMA_SEL:1;
    vuint32_t RF6_DMA_SEL:1;
    vuint32_t RF5_DMA_SEL:1;
    vuint32_t RF4_DMA_SEL:1;
    vuint32_t RF3_DMA_SEL:1;
    vuint32_t RF2_DMA_SEL:1;
    vuint32_t RF1_DMA_SEL:1;
    vuint32_t RF0_DMA_SEL:1;
    vuint32_t CF7_DMA_SEL:1;
    vuint32_t CF6_DMA_SEL:1;
    vuint32_t CF5_DMA_SEL:1;
    vuint32_t CF4_DMA_SEL:1;
    vuint32_t CF3_DMA_SEL:1;
    vuint32_t CF2_DMA_SEL:1;
    vuint32_t CF1_DMA_SEL:1;
    vuint32_t CF0_DMA_SEL:1;
  } B;
} EQADC_DMA_SEL_tag;

struct EQADC_tag {
  EQADC_MCR_tag MCR;                   /* EQADC Module Configuration Register (Offset: 0x0000) */
  EQADC_TST_tag TST;                   /* EQADC Test Register (Offset: 0x0004) */
  uint8_t EQADC_reserved0[4];
  EQADC_ETDFR_tag ETDFR;               /* EQADC External Trigger Digital Filter Register (Offset: 0x000C) */
  EQADC_CFPR_tag CFPR[8];              /* EQADC CFIFO Push Register (Offset: 0x0010) */
  EQADC_RFPR_tag RFPR[8];              /* EQADC Result FIFO Pop Register (Offset: 0x0030) */
  EQADC_CFCR0_tag CFCR0;               /* EQADC CFIFO Control Register 0 (Offset: 0x0050) */
  EQADC_CFCR1_tag CFCR1;               /* EQADC CFIFO Control Register 1 (Offset: 0x0054) */
  EQADC_CFCR2_tag CFCR2;               /* EQADC CFIFO Control Register 2 (Offset: 0x0058) */
  EQADC_CFCR3_tag CFCR3;               /* EQADC CFIFO Control Register 3 (Offset: 0x005C) */
  EQADC_IDCR0_tag IDCR0;               /* EQADC Interrupt and DMA Control Register 0 (Offset: 0x0060) */
  EQADC_IDCR1_tag IDCR1;               /* EQADC Interrupt and DMA Control Register 1 (Offset: 0x0064) */
  EQADC_IDCR2_tag IDCR2;               /* EQADC Interrupt and DMA Control Register 2 (Offset: 0x0068) */
  EQADC_IDCR3_tag IDCR3;               /* EQADC Interrupt and DMA Control Register 3 (Offset: 0x006C) */
  EQADC_FISR_tag FISR[8];              /* EQADC FIFO and Interrupt Status Register (Offset: 0x0070) */
  EQADC_CFTCR0_tag CFTCR0;             /* EQADC CFIFO Transfer Counter Register 0 (Offset: 0x0090) */
  EQADC_CFTCR1_tag CFTCR1;             /* EQADC CFIFO Transfer Counter Register 1 (Offset: 0x0094) */
  EQADC_CFTCR2_tag CFTCR2;             /* EQADC CFIFO Transfer Counter Register 2 (Offset: 0x0098) */
  EQADC_CFTCR3_tag CFTCR3;             /* EQADC CFIFO Transfer Counter Register 3 (Offset: 0x009C) */
  EQADC_CFSSR0_tag CFSSR0;             /* EQADC CFIFO Status Snapshot Register 0 (Offset: 0x00A0) */
  EQADC_CFSSR1_tag CFSSR1;             /* EQADC CFIFO Status Snapshot Register 1 (Offset: 0x00A4) */
  uint8_t EQADC_reserved7[4];
  EQADC_CFSR_tag CFSR;                 /* EQADC CFIFO Status Register (Offset: 0x00AC) */
  uint8_t EQADC_reserved8[32];
  EQADC_STACCCR_tag STACCCR;           /* EQADC STAC Bus Client Configuration Register (Offset: 0x00D0) */
  uint8_t EQADC_reserved9[44];
  EQADC_CF0R_tag CF0R[4];              /* EQADC CFIFO0 Register (Offset: 0x0100) */
  EQADC_CF0ER_tag CF0ER[4];            /* EQADC CFIFO0 Extension Register (Offset: 0x0110) */
  uint8_t EQADC_reserved10[32];
  EQADC_CF1R_tag CF1R[4];              /* EQADC CFIFO1 Register (Offset: 0x0140) */
  uint8_t EQADC_reserved11[48];
  EQADC_CF2R_tag CF2R[4];              /* EQADC CFIFO2 Register (Offset: 0x0180) */
  uint8_t EQADC_reserved12[48];
  EQADC_CF3R_tag CF3R[4];              /* EQADC CFIFO3 Register (Offset: 0x01C0) */
  uint8_t EQADC_reserved13[48];
  EQADC_CF4R_tag CF4R[4];              /* EQADC CFIFO4 Register (Offset: 0x0200) */
  uint8_t EQADC_reserved14[48];
  EQADC_CF5R_tag CF5R[4];              /* EQADC CFIFO5 Register (Offset: 0x0240) */
  uint8_t EQADC_reserved15[48];
  EQADC_CF6R_tag CF6R[4];              /* EQADC CFIFO6 Register (Offset: 0x0280) */
  uint8_t EQADC_reserved16[48];
  EQADC_CF7R_tag CF7R[4];              /* EQADC CFIFO7 Register (Offset: 0x02C0) */
  uint8_t EQADC_reserved17[48];
  EQADC_RF0R_tag RF0R[8];              /* EQADC RFIFO0 Register (Offset: 0x0300) */
  uint8_t EQADC_reserved18[32];
  EQADC_RF1R_tag RF1R[8];              /* EQADC RFIFO1 Register (Offset: 0x0340) */
  uint8_t EQADC_reserved19[32];
  EQADC_RF2R_tag RF2R[8];              /* EQADC RFIFO2 Register (Offset: 0x0380) */
  uint8_t EQADC_reserved20[32];
  EQADC_RF3R_tag RF3R[8];              /* EQADC RFIFO3 Register (Offset: 0x03C0) */
  uint8_t EQADC_reserved21[32];
  EQADC_RF4R_tag RF4R[8];              /* EQADC RFIFO4 Register (Offset: 0x0400) */
  uint8_t EQADC_reserved22[32];
  EQADC_RF5R_tag RF5R[8];              /* EQADC RFIFO5 Register (Offset: 0x0440) */
  uint8_t EQADC_reserved23[32];
  EQADC_RF6R_tag RF6R[8];              /* EQADC RFIFO6 Register (Offset: 0x0480) */
  uint8_t EQADC_reserved24[32];
  EQADC_RF7R_tag RF7R[8];              /* EQADC RFIFO7 Register (Offset: 0x04C0) */
  uint8_t EQADC_reserved25[32];
  EQADC_DLY_tag DLY[8];                /* EQADC CFIFO Trigger Delay Register (Offset: 0x0500) */
  EQADC_RFSRR_tag RFSRR;               /* EQADC RFIFO Software Reset Register (Offset: 0x0520) */
  EQADC_DMA_SEL_tag DMA_SEL;           /* EQADC DMA Select Register (Offset: 0x0524) */
};

/*******************************************************************************
 * EQADC Register Bit Fields
 *******************************************************************************/
/* MCR Bit Fields */
#define EQADC_MCR_DBG_MASK                       0x3u
#define EQADC_MCR_DBG_SHIFT                      0u
#define EQADC_MCR_DBG_WIDTH                      2u
#define EQADC_MCR_DBG(x)                         (((uint32_t)(((uint32_t)(x))<<EQADC_MCR_DBG_SHIFT))&EQADC_MCR_DBG_MASK)
#define EQADC_MCR_DAM_MASK                       0x20u
#define EQADC_MCR_DAM_SHIFT                      5u
#define EQADC_MCR_DAM_WIDTH                      1u
#define EQADC_MCR_DAM(x)                         (((uint32_t)(((uint32_t)(x))<<EQADC_MCR_DAM_SHIFT))&EQADC_MCR_DAM_MASK)
#define EQADC_MCR_ICEA1_MASK                     0x40u
#define EQADC_MCR_ICEA1_SHIFT                    6u
#define EQADC_MCR_ICEA1_WIDTH                    1u
#define EQADC_MCR_ICEA1(x)                       (((uint32_t)(((uint32_t)(x))<<EQADC_MCR_ICEA1_SHIFT))&EQADC_MCR_ICEA1_MASK)
#define EQADC_MCR_ICEA0_MASK                     0x80u
#define EQADC_MCR_ICEA0_SHIFT                    7u
#define EQADC_MCR_ICEA0_WIDTH                    1u
#define EQADC_MCR_ICEA0(x)                       (((uint32_t)(((uint32_t)(x))<<EQADC_MCR_ICEA0_SHIFT))&EQADC_MCR_ICEA0_MASK)
#define EQADC_MCR_CS_ST0_MASK                    0x10000u
#define EQADC_MCR_CS_ST0_SHIFT                   16u
#define EQADC_MCR_CS_ST0_WIDTH                   1u
#define EQADC_MCR_CS_ST0(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_MCR_CS_ST0_SHIFT))&EQADC_MCR_CS_ST0_MASK)
#define EQADC_MCR_CS_EN0_MASK                    0x20000u
#define EQADC_MCR_CS_EN0_SHIFT                   17u
#define EQADC_MCR_CS_EN0_WIDTH                   1u
#define EQADC_MCR_CS_EN0(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_MCR_CS_EN0_SHIFT))&EQADC_MCR_CS_EN0_MASK)
#define EQADC_MCR_CS_ST1_MASK                    0x40000u
#define EQADC_MCR_CS_ST1_SHIFT                   18u
#define EQADC_MCR_CS_ST1_WIDTH                   1u
#define EQADC_MCR_CS_ST1(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_MCR_CS_ST1_SHIFT))&EQADC_MCR_CS_ST1_MASK)
#define EQADC_MCR_CS_EN1_MASK                    0x80000u
#define EQADC_MCR_CS_EN1_SHIFT                   19u
#define EQADC_MCR_CS_EN1_WIDTH                   1u
#define EQADC_MCR_CS_EN1(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_MCR_CS_EN1_SHIFT))&EQADC_MCR_CS_EN1_MASK)
#define EQADC_MCR_CS_ST2_MASK                    0x100000u
#define EQADC_MCR_CS_ST2_SHIFT                   20u
#define EQADC_MCR_CS_ST2_WIDTH                   1u
#define EQADC_MCR_CS_ST2(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_MCR_CS_ST2_SHIFT))&EQADC_MCR_CS_ST2_MASK)
#define EQADC_MCR_CS_EN2_MASK                    0x200000u
#define EQADC_MCR_CS_EN2_SHIFT                   21u
#define EQADC_MCR_CS_EN2_WIDTH                   1u
#define EQADC_MCR_CS_EN2(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_MCR_CS_EN2_SHIFT))&EQADC_MCR_CS_EN2_MASK)
#define EQADC_MCR_CS_ST3_MASK                    0x400000u
#define EQADC_MCR_CS_ST3_SHIFT                   22u
#define EQADC_MCR_CS_ST3_WIDTH                   1u
#define EQADC_MCR_CS_ST3(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_MCR_CS_ST3_SHIFT))&EQADC_MCR_CS_ST3_MASK)
#define EQADC_MCR_CS_EN3_MASK                    0x800000u
#define EQADC_MCR_CS_EN3_SHIFT                   23u
#define EQADC_MCR_CS_EN3_WIDTH                   1u
#define EQADC_MCR_CS_EN3(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_MCR_CS_EN3_SHIFT))&EQADC_MCR_CS_EN3_MASK)
#define EQADC_MCR_CS_ST4_MASK                    0x1000000u
#define EQADC_MCR_CS_ST4_SHIFT                   24u
#define EQADC_MCR_CS_ST4_WIDTH                   1u
#define EQADC_MCR_CS_ST4(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_MCR_CS_ST4_SHIFT))&EQADC_MCR_CS_ST4_MASK)
#define EQADC_MCR_CS_EN4_MASK                    0x2000000u
#define EQADC_MCR_CS_EN4_SHIFT                   25u
#define EQADC_MCR_CS_EN4_WIDTH                   1u
#define EQADC_MCR_CS_EN4(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_MCR_CS_EN4_SHIFT))&EQADC_MCR_CS_EN4_MASK)
#define EQADC_MCR_CS_ST5_MASK                    0x4000000u
#define EQADC_MCR_CS_ST5_SHIFT                   26u
#define EQADC_MCR_CS_ST5_WIDTH                   1u
#define EQADC_MCR_CS_ST5(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_MCR_CS_ST5_SHIFT))&EQADC_MCR_CS_ST5_MASK)
#define EQADC_MCR_CS_EN5_MASK                    0x8000000u
#define EQADC_MCR_CS_EN5_SHIFT                   27u
#define EQADC_MCR_CS_EN5_WIDTH                   1u
#define EQADC_MCR_CS_EN5(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_MCR_CS_EN5_SHIFT))&EQADC_MCR_CS_EN5_MASK)
#define EQADC_MCR_CS_ST6_MASK                    0x10000000u
#define EQADC_MCR_CS_ST6_SHIFT                   28u
#define EQADC_MCR_CS_ST6_WIDTH                   1u
#define EQADC_MCR_CS_ST6(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_MCR_CS_ST6_SHIFT))&EQADC_MCR_CS_ST6_MASK)
#define EQADC_MCR_CS_EN6_MASK                    0x20000000u
#define EQADC_MCR_CS_EN6_SHIFT                   29u
#define EQADC_MCR_CS_EN6_WIDTH                   1u
#define EQADC_MCR_CS_EN6(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_MCR_CS_EN6_SHIFT))&EQADC_MCR_CS_EN6_MASK)
#define EQADC_MCR_CS_ST7_MASK                    0x40000000u
#define EQADC_MCR_CS_ST7_SHIFT                   30u
#define EQADC_MCR_CS_ST7_WIDTH                   1u
#define EQADC_MCR_CS_ST7(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_MCR_CS_ST7_SHIFT))&EQADC_MCR_CS_ST7_MASK)
#define EQADC_MCR_CS_EN7_MASK                    0x80000000u
#define EQADC_MCR_CS_EN7_SHIFT                   31u
#define EQADC_MCR_CS_EN7_WIDTH                   1u
#define EQADC_MCR_CS_EN7(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_MCR_CS_EN7_SHIFT))&EQADC_MCR_CS_EN7_MASK)
/* ETDFR Bit Fields */
#define EQADC_ETDFR_DFL_MASK                     0xFu
#define EQADC_ETDFR_DFL_SHIFT                    0u
#define EQADC_ETDFR_DFL_WIDTH                    4u
#define EQADC_ETDFR_DFL(x)                       (((uint32_t)(((uint32_t)(x))<<EQADC_ETDFR_DFL_SHIFT))&EQADC_ETDFR_DFL_MASK)
/* CFPR Bit Fields */
#define EQADC_CFPR_CF_PUSHX_MASK                 0xFFFFFFFFu
#define EQADC_CFPR_CF_PUSHX_SHIFT                0u
#define EQADC_CFPR_CF_PUSHX_WIDTH                32u
#define EQADC_CFPR_CF_PUSHX(x)                   (((uint32_t)(((uint32_t)(x))<<EQADC_CFPR_CF_PUSHX_SHIFT))&EQADC_CFPR_CF_PUSHX_MASK)
/* RFPR Bit Fields */
#define EQADC_RFPR_RF_POPX_MASK                  0xFFFFu
#define EQADC_RFPR_RF_POPX_SHIFT                 0u
#define EQADC_RFPR_RF_POPX_WIDTH                 16u
#define EQADC_RFPR_RF_POPX(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_RFPR_RF_POPX_SHIFT))&EQADC_RFPR_RF_POPX_MASK)
#define EQADC_RFPR_RF_CH_NUM_MASK                0xFF0000u
#define EQADC_RFPR_RF_CH_NUM_SHIFT               16u
#define EQADC_RFPR_RF_CH_NUM_WIDTH               8u
#define EQADC_RFPR_RF_CH_NUM(x)                  (((uint32_t)(((uint32_t)(x))<<EQADC_RFPR_RF_CH_NUM_SHIFT))&EQADC_RFPR_RF_CH_NUM_MASK)
#define EQADC_RFPR_RF_ADC_NUM_MASK               0x1000000u
#define EQADC_RFPR_RF_ADC_NUM_SHIFT              24u
#define EQADC_RFPR_RF_ADC_NUM_WIDTH              1u
#define EQADC_RFPR_RF_ADC_NUM(x)                 (((uint32_t)(((uint32_t)(x))<<EQADC_RFPR_RF_ADC_NUM_SHIFT))&EQADC_RFPR_RF_ADC_NUM_MASK)
/* CFCR0 Bit Fields */
#define EQADC_CFCR0_MODE1_MASK                   0xF0u
#define EQADC_CFCR0_MODE1_SHIFT                  4u
#define EQADC_CFCR0_MODE1_WIDTH                  4u
#define EQADC_CFCR0_MODE1(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR0_MODE1_SHIFT))&EQADC_CFCR0_MODE1_MASK)
#define EQADC_CFCR0_CFINV1_MASK                  0x200u
#define EQADC_CFCR0_CFINV1_SHIFT                 9u
#define EQADC_CFCR0_CFINV1_WIDTH                 1u
#define EQADC_CFCR0_CFINV1(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR0_CFINV1_SHIFT))&EQADC_CFCR0_CFINV1_MASK)
#define EQADC_CFCR0_SSE1_MASK                    0x400u
#define EQADC_CFCR0_SSE1_SHIFT                   10u
#define EQADC_CFCR0_SSE1_WIDTH                   1u
#define EQADC_CFCR0_SSE1(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR0_SSE1_SHIFT))&EQADC_CFCR0_SSE1_MASK)
#define EQADC_CFCR0_AMODE0_MASK                  0xF0000u
#define EQADC_CFCR0_AMODE0_SHIFT                 16u
#define EQADC_CFCR0_AMODE0_WIDTH                 4u
#define EQADC_CFCR0_AMODE0(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR0_AMODE0_SHIFT))&EQADC_CFCR0_AMODE0_MASK)
#define EQADC_CFCR0_MODE0_MASK                   0xF00000u
#define EQADC_CFCR0_MODE0_SHIFT                  20u
#define EQADC_CFCR0_MODE0_WIDTH                  4u
#define EQADC_CFCR0_MODE0(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR0_MODE0_SHIFT))&EQADC_CFCR0_MODE0_MASK)
#define EQADC_CFCR0_CFINV0_MASK                  0x2000000u
#define EQADC_CFCR0_CFINV0_SHIFT                 25u
#define EQADC_CFCR0_CFINV0_WIDTH                 1u
#define EQADC_CFCR0_CFINV0(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR0_CFINV0_SHIFT))&EQADC_CFCR0_CFINV0_MASK)
#define EQADC_CFCR0_SSE0_MASK                    (0x4000000u)
#define EQADC_CFCR0_SSE0_SHIFT                   26u
#define EQADC_CFCR0_SSE0_WIDTH                   1u
#define EQADC_CFCR0_SSE0(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR0_SSE0_SHIFT))&EQADC_CFCR0_SSE0_MASK)
#define EQADC_CFCR0_STRME0_MASK                  0x8000000u
#define EQADC_CFCR0_STRME0_SHIFT                 27u
#define EQADC_CFCR0_STRME0_WIDTH                 1u
#define EQADC_CFCR0_STRME0(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR0_STRME0_SHIFT))&EQADC_CFCR0_STRME0_MASK)
#define EQADC_CFCR0_CFEEE0_MASK                  0x10000000u
#define EQADC_CFCR0_CFEEE0_SHIFT                 28u
#define EQADC_CFCR0_CFEEE0_WIDTH                 1u
#define EQADC_CFCR0_CFEEE0(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR0_CFEEE0_SHIFT))&EQADC_CFCR0_CFEEE0_MASK)
/* CFCR1 Bit Fields */
#define EQADC_CFCR1_MODE3_MASK                   0xF0u
#define EQADC_CFCR1_MODE3_SHIFT                  4u
#define EQADC_CFCR1_MODE3_WIDTH                  4u
#define EQADC_CFCR1_MODE3(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR1_MODE3_SHIFT))&EQADC_CFCR1_MODE3_MASK)
#define EQADC_CFCR1_CFINV3_MASK                  0x200u
#define EQADC_CFCR1_CFINV3_SHIFT                 9u
#define EQADC_CFCR1_CFINV3_WIDTH                 1u
#define EQADC_CFCR1_CFINV3(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR1_CFINV3_SHIFT))&EQADC_CFCR1_CFINV3_MASK)
#define EQADC_CFCR1_SSE3_MASK                    0x400u
#define EQADC_CFCR1_SSE3_SHIFT                   10u
#define EQADC_CFCR1_SSE3_WIDTH                   1u
#define EQADC_CFCR1_SSE3(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR1_SSE3_SHIFT))&EQADC_CFCR1_SSE3_MASK)
#define EQADC_CFCR1_MODE2_MASK                   0xF00000u
#define EQADC_CFCR1_MODE2_SHIFT                  20u
#define EQADC_CFCR1_MODE2_WIDTH                  4u
#define EQADC_CFCR1_MODE2(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR1_MODE2_SHIFT))&EQADC_CFCR1_MODE2_MASK)
#define EQADC_CFCR1_CFINV2_MASK                  0x2000000u
#define EQADC_CFCR1_CFINV2_SHIFT                 25u
#define EQADC_CFCR1_CFINV2_WIDTH                 1u
#define EQADC_CFCR1_CFINV2(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR1_CFINV2_SHIFT))&EQADC_CFCR1_CFINV2_MASK)
#define EQADC_CFCR1_SSE2_MASK                    0x4000000u
#define EQADC_CFCR1_SSE2_SHIFT                   26u
#define EQADC_CFCR1_SSE2_WIDTH                   1u
#define EQADC_CFCR1_SSE2(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR1_SSE2_SHIFT))&EQADC_CFCR1_SSE2_MASK)
/* CFCR2 Bit Fields */
#define EQADC_CFCR2_MODE5_MASK                   0xF0u
#define EQADC_CFCR2_MODE5_SHIFT                  4u
#define EQADC_CFCR2_MODE5_WIDTH                  4u
#define EQADC_CFCR2_MODE5(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR2_MODE5_SHIFT))&EQADC_CFCR2_MODE5_MASK)
#define EQADC_CFCR2_CFINV5_MASK                  0x200u
#define EQADC_CFCR2_CFINV5_SHIFT                 9u
#define EQADC_CFCR2_CFINV5_WIDTH                 1u
#define EQADC_CFCR2_CFINV5(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR2_CFINV5_SHIFT))&EQADC_CFCR2_CFINV5_MASK)
#define EQADC_CFCR2_SSE5_MASK                    0x400u
#define EQADC_CFCR2_SSE5_SHIFT                   10u
#define EQADC_CFCR2_SSE5_WIDTH                   1u
#define EQADC_CFCR2_SSE5(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR2_SSE5_SHIFT))&EQADC_CFCR2_SSE5_MASK)
#define EQADC_CFCR2_MODE4_MASK                   0xF00000u
#define EQADC_CFCR2_MODE4_SHIFT                  20u
#define EQADC_CFCR2_MODE4_WIDTH                  4u
#define EQADC_CFCR2_MODE4(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR2_MODE4_SHIFT))&EQADC_CFCR2_MODE4_MASK)
#define EQADC_CFCR2_CFINV4_MASK                  0x2000000u
#define EQADC_CFCR2_CFINV4_SHIFT                 25u
#define EQADC_CFCR2_CFINV4_WIDTH                 1u
#define EQADC_CFCR2_CFINV4(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR2_CFINV4_SHIFT))&EQADC_CFCR2_CFINV4_MASK)
#define EQADC_CFCR2_SSE4_MASK                    0x4000000u
#define EQADC_CFCR2_SSE4_SHIFT                   26u
#define EQADC_CFCR2_SSE4_WIDTH                   1u
#define EQADC_CFCR2_SSE4(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR2_SSE4_SHIFT))&EQADC_CFCR2_SSE4_MASK)
/* CFCR3 Bit Fields */
#define EQADC_CFCR3_MODE7_MASK                   0xF0u
#define EQADC_CFCR3_MODE7_SHIFT                  4u
#define EQADC_CFCR3_MODE7_WIDTH                  4u
#define EQADC_CFCR3_MODE7(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR3_MODE7_SHIFT))&EQADC_CFCR3_MODE7_MASK)
#define EQADC_CFCR3_INJ_EN7_MASK                 0x100u
#define EQADC_CFCR3_INJ_EN7_SHIFT                8u
#define EQADC_CFCR3_INJ_EN7_WIDTH                1u
#define EQADC_CFCR3_INJ_EN7(x)                   (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR3_INJ_EN7_SHIFT))&EQADC_CFCR3_INJ_EN7_MASK)
#define EQADC_CFCR3_CFINV7_MASK                  0x200u
#define EQADC_CFCR3_CFINV7_SHIFT                 9u
#define EQADC_CFCR3_CFINV7_WIDTH                 1u
#define EQADC_CFCR3_CFINV7(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR3_CFINV7_SHIFT))&EQADC_CFCR3_CFINV7_MASK)
#define EQADC_CFCR3_SSE7_MASK                    0x400u
#define EQADC_CFCR3_SSE7_SHIFT                   10u
#define EQADC_CFCR3_SSE7_WIDTH                   1u
#define EQADC_CFCR3_SSE7(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR3_SSE7_SHIFT))&EQADC_CFCR3_SSE7_MASK)
#define EQADC_CFCR3_MODE6_MASK                   0xF00000u
#define EQADC_CFCR3_MODE6_SHIFT                  20u
#define EQADC_CFCR3_MODE6_WIDTH                  4u
#define EQADC_CFCR3_MODE6(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR2_MODE4_SHIFT))&EQADC_CFCR2_MODE4_MASK)
#define EQADC_CFCR3_INJ_EN6_MASK                 0x1000000u
#define EQADC_CFCR3_INJ_EN6_SHIFT                24u
#define EQADC_CFCR3_INJ_EN6_WIDTH                1u
#define EQADC_CFCR3_INJ_EN6(x)                   (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR3_INJ_EN6_SHIFT))&EQADC_CFCR3_INJ_EN6_MASK)
#define EQADC_CFCR3_CFINV6_MASK                  0x2000000u
#define EQADC_CFCR3_CFINV6_SHIFT                 25u
#define EQADC_CFCR3_CFINV6_WIDTH                 1u
#define EQADC_CFCR3_CFINV6(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR2_CFINV4_SHIFT))&EQADC_CFCR2_CFINV4_MASK)
#define EQADC_CFCR3_SSE6_MASK                    0x4000000u
#define EQADC_CFCR3_SSE6_SHIFT                   26u
#define EQADC_CFCR3_SSE6_WIDTH                   1u
#define EQADC_CFCR3_SSE6(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_CFCR2_SSE4_SHIFT))&EQADC_CFCR2_SSE4_MASK)
/* IDCR0 Bit Fields */
#define EQADC_IDCR0_RFDS1_MASK                   0x1u
#define EQADC_IDCR0_RFDS1_SHIFT                  0u
#define EQADC_IDCR0_RFDS1_WIDTH                  1u
#define EQADC_IDCR0_RFDS1(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR0_RFDS1_SHIFT))&EQADC_IDCR0_RFDS1_MASK)
#define EQADC_IDCR0_RFDE1_MASK                   0x2u
#define EQADC_IDCR0_RFDE1_SHIFT                  1u
#define EQADC_IDCR0_RFDE1_WIDTH                  1u
#define EQADC_IDCR0_RFDE1(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR0_RFDE1_SHIFT))&EQADC_IDCR0_RFDE1_MASK)
#define EQADC_IDCR0_RFOIE1_MASK                  0x8u
#define EQADC_IDCR0_RFOIE1_SHIFT                 3u
#define EQADC_IDCR0_RFOIE1_WIDTH                 1u
#define EQADC_IDCR0_RFOIE1(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR0_RFOIE1_SHIFT))&EQADC_IDCR0_RFOIE1_MASK)
#define EQADC_IDCR0_CFFS1_MASK                   0x100u
#define EQADC_IDCR0_CFFS1_SHIFT                  8u
#define EQADC_IDCR0_CFFS1_WIDTH                  1u
#define EQADC_IDCR0_CFFS1(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR0_CFFS1_SHIFT))&EQADC_IDCR0_CFFS1_MASK)
#define EQADC_IDCR0_CFFE1_MASK                   0x200u
#define EQADC_IDCR0_CFFE1_SHIFT                  9u
#define EQADC_IDCR0_CFFE1_WIDTH                  1u
#define EQADC_IDCR0_CFFE1(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR0_CFFE1_SHIFT))&EQADC_IDCR0_CFFE1_MASK)
#define EQADC_IDCR0_CFUIE1_MASK                  0x800u
#define EQADC_IDCR0_CFUIE1_SHIFT                 11u
#define EQADC_IDCR0_CFUIE1_WIDTH                 1u
#define EQADC_IDCR0_CFUIE1(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR0_CFUIE1_SHIFT))&EQADC_IDCR0_CFUIE1_MASK)
#define EQADC_IDCR0_EOQIE1_MASK                  0x1000u
#define EQADC_IDCR0_EOQIE1_SHIFT                 12u
#define EQADC_IDCR0_EOQIE1_WIDTH                 1u
#define EQADC_IDCR0_EOQIE1(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR0_EOQIE1_SHIFT))&EQADC_IDCR0_EOQIE1_MASK)
#define EQADC_IDCR0_PIE1_MASK                    0x2000u
#define EQADC_IDCR0_PIE1_SHIFT                   13u
#define EQADC_IDCR0_PIE1_WIDTH                   1u
#define EQADC_IDCR0_PIE1(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR0_PIE1_SHIFT))&EQADC_IDCR0_PIE1_MASK)
#define EQADC_IDCR0_TORIE1_MASK                  0x4000u
#define EQADC_IDCR0_TORIE1_SHIFT                 14u
#define EQADC_IDCR0_TORIE1_WIDTH                 1u
#define EQADC_IDCR0_TORIE1(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR0_TORIE1_SHIFT))&EQADC_IDCR0_TORIE1_MASK)
#define EQADC_IDCR0_NCIE1_MASK                   0x8000u
#define EQADC_IDCR0_NCIE1_SHIFT                  15u
#define EQADC_IDCR0_NCIE1_WIDTH                  1u
#define EQADC_IDCR0_NCIE1(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR0_NCIE1_SHIFT))&EQADC_IDCR0_NCIE1_MASK)
#define EQADC_IDCR0_RFDS0_MASK                   0x10000u
#define EQADC_IDCR0_RFDS0_SHIFT                  16u
#define EQADC_IDCR0_RFDS0_WIDTH                  1u
#define EQADC_IDCR0_RFDS0(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR0_RFDS0_SHIFT))&EQADC_IDCR0_RFDS0_MASK)
#define EQADC_IDCR0_RFDE0_MASK                   0x20000u
#define EQADC_IDCR0_RFDE0_SHIFT                  17u
#define EQADC_IDCR0_RFDE0_WIDTH                  1u
#define EQADC_IDCR0_RFDE0(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR0_RFDE0_SHIFT))&EQADC_IDCR0_RFDE0_MASK)
#define EQADC_IDCR0_RFOIE0_MASK                  0x80000u
#define EQADC_IDCR0_RFOIE0_SHIFT                 19u
#define EQADC_IDCR0_RFOIE0_WIDTH                 1u
#define EQADC_IDCR0_RFOIE0(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR0_RFOIE0_SHIFT))&EQADC_IDCR0_RFOIE0_MASK)
#define EQADC_IDCR0_CFFS0_MASK                   0x1000000u
#define EQADC_IDCR0_CFFS0_SHIFT                  24u
#define EQADC_IDCR0_CFFS0_WIDTH                  1u
#define EQADC_IDCR0_CFFS0(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR0_CFFS0_SHIFT))&EQADC_IDCR0_CFFS0_MASK)
#define EQADC_IDCR0_CFFE0_MASK                   0x2000000u
#define EQADC_IDCR0_CFFE0_SHIFT                  25u
#define EQADC_IDCR0_CFFE0_WIDTH                  1u
#define EQADC_IDCR0_CFFE0(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR0_CFFE0_SHIFT))&EQADC_IDCR0_CFFE0_MASK)
#define EQADC_IDCR0_CFUIE0_MASK                  0x8000000u
#define EQADC_IDCR0_CFUIE0_SHIFT                 27u
#define EQADC_IDCR0_CFUIE0_WIDTH                 1u
#define EQADC_IDCR0_CFUIE0(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR0_CFUIE0_SHIFT))&EQADC_IDCR0_CFUIE0_MASK)
#define EQADC_IDCR0_EOQIE0_MASK                  0x10000000u
#define EQADC_IDCR0_EOQIE0_SHIFT                 28u
#define EQADC_IDCR0_EOQIE0_WIDTH                 1u
#define EQADC_IDCR0_EOQIE0(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR0_EOQIE0_SHIFT))&EQADC_IDCR0_EOQIE0_MASK)
#define EQADC_IDCR0_PIE0_MASK                    0x20000000u
#define EQADC_IDCR0_PIE0_SHIFT                   29u
#define EQADC_IDCR0_PIE0_WIDTH                   1u
#define EQADC_IDCR0_PIE0(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR0_PIE0_SHIFT))&EQADC_IDCR0_PIE0_MASK)
#define EQADC_IDCR0_TORIE0_MASK                  0x40000000u
#define EQADC_IDCR0_TORIE0_SHIFT                 30u
#define EQADC_IDCR0_TORIE0_WIDTH                 1u
#define EQADC_IDCR0_TORIE0(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR0_TORIE0_SHIFT))&EQADC_IDCR0_TORIE0_MASK)
#define EQADC_IDCR0_NCIE0_MASK                   0x80000000u
#define EQADC_IDCR0_NCIE0_SHIFT                  31u
#define EQADC_IDCR0_NCIE0_WIDTH                  1u
#define EQADC_IDCR0_NCIE0(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR0_NCIE0_SHIFT))&EQADC_IDCR0_NCIE0_MASK)
/* IDCR1 Bit Fields */
#define EQADC_IDCR1_RFDS3_MASK                   0x1u
#define EQADC_IDCR1_RFDS3_SHIFT                  0u
#define EQADC_IDCR1_RFDS3_WIDTH                  1u
#define EQADC_IDCR1_RFDS3(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR1_RFDS3_SHIFT))&EQADC_IDCR1_RFDS3_MASK)
#define EQADC_IDCR1_RFDE3_MASK                   0x2u
#define EQADC_IDCR1_RFDE3_SHIFT                  1u
#define EQADC_IDCR1_RFDE3_WIDTH                  1u
#define EQADC_IDCR1_RFDE3(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR1_RFDE3_SHIFT))&EQADC_IDCR1_RFDE3_MASK)
#define EQADC_IDCR1_RFOIE3_MASK                  0x8u
#define EQADC_IDCR1_RFOIE3_SHIFT                 3u
#define EQADC_IDCR1_RFOIE3_WIDTH                 1u
#define EQADC_IDCR1_RFOIE3(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR1_RFOIE3_SHIFT))&EQADC_IDCR1_RFOIE3_MASK)
#define EQADC_IDCR1_CFFS3_MASK                   0x100u
#define EQADC_IDCR1_CFFS3_SHIFT                  8u
#define EQADC_IDCR1_CFFS3_WIDTH                  1u
#define EQADC_IDCR1_CFFS3(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR1_CFFS3_SHIFT))&EQADC_IDCR1_CFFS3_MASK)
#define EQADC_IDCR1_CFFE3_MASK                   0x200u
#define EQADC_IDCR1_CFFE3_SHIFT                  9u
#define EQADC_IDCR1_CFFE3_WIDTH                  1u
#define EQADC_IDCR1_CFFE3(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR1_CFFE3_SHIFT))&EQADC_IDCR1_CFFE3_MASK)
#define EQADC_IDCR1_CFUIE3_MASK                  0x800u
#define EQADC_IDCR1_CFUIE3_SHIFT                 11u
#define EQADC_IDCR1_CFUIE3_WIDTH                 1u
#define EQADC_IDCR1_CFUIE3(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR1_CFUIE3_SHIFT))&EQADC_IDCR1_CFUIE3_MASK)
#define EQADC_IDCR1_EOQIE3_MASK                  0x1000u
#define EQADC_IDCR1_EOQIE3_SHIFT                 12u
#define EQADC_IDCR1_EOQIE3_WIDTH                 1u
#define EQADC_IDCR1_EOQIE3(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR1_EOQIE3_SHIFT))&EQADC_IDCR1_EOQIE3_MASK)
#define EQADC_IDCR1_PIE3_MASK                    0x2000u
#define EQADC_IDCR1_PIE3_SHIFT                   13u
#define EQADC_IDCR1_PIE3_WIDTH                   1u
#define EQADC_IDCR1_PIE3(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR1_PIE3_SHIFT))&EQADC_IDCR1_PIE3_MASK)
#define EQADC_IDCR1_TORIE3_MASK                  0x4000u
#define EQADC_IDCR1_TORIE3_SHIFT                 14u
#define EQADC_IDCR1_TORIE3_WIDTH                 1u
#define EQADC_IDCR1_TORIE3(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR1_TORIE3_SHIFT))&EQADC_IDCR1_TORIE3_MASK)
#define EQADC_IDCR1_NCIE3_MASK                   0x8000u
#define EQADC_IDCR1_NCIE3_SHIFT                  15u
#define EQADC_IDCR1_NCIE3_WIDTH                  1u
#define EQADC_IDCR1_NCIE3(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR1_NCIE3_SHIFT))&EQADC_IDCR1_NCIE3_MASK)
#define EQADC_IDCR1_RFDS2_MASK                   0x10000u
#define EQADC_IDCR1_RFDS2_SHIFT                  16u
#define EQADC_IDCR1_RFDS2_WIDTH                  1u
#define EQADC_IDCR1_RFDS2(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR1_RFDS2_SHIFT))&EQADC_IDCR1_RFDS2_MASK)
#define EQADC_IDCR1_RFDE2_MASK                   0x20000u
#define EQADC_IDCR1_RFDE2_SHIFT                  17u
#define EQADC_IDCR1_RFDE2_WIDTH                  1u
#define EQADC_IDCR1_RFDE2(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR1_RFDE2_SHIFT))&EQADC_IDCR1_RFDE2_MASK)
#define EQADC_IDCR1_RFOIE2_MASK                  0x80000u
#define EQADC_IDCR1_RFOIE2_SHIFT                 19u
#define EQADC_IDCR1_RFOIE2_WIDTH                 1u
#define EQADC_IDCR1_RFOIE2(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR1_RFOIE2_SHIFT))&EQADC_IDCR1_RFOIE2_MASK)
#define EQADC_IDCR1_CFFS2_MASK                   0x1000000u
#define EQADC_IDCR1_CFFS2_SHIFT                  24u
#define EQADC_IDCR1_CFFS2_WIDTH                  1u
#define EQADC_IDCR1_CFFS2(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR1_CFFS2_SHIFT))&EQADC_IDCR1_CFFS2_MASK)
#define EQADC_IDCR1_CFFE2_MASK                   0x2000000u
#define EQADC_IDCR1_CFFE2_SHIFT                  25u
#define EQADC_IDCR1_CFFE2_WIDTH                  1u
#define EQADC_IDCR1_CFFE2(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR1_CFFE2_SHIFT))&EQADC_IDCR1_CFFE2_MASK)
#define EQADC_IDCR1_CFUIE2_MASK                  0x8000000u
#define EQADC_IDCR1_CFUIE2_SHIFT                 27u
#define EQADC_IDCR1_CFUIE2_WIDTH                 1u
#define EQADC_IDCR1_CFUIE2(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR1_CFUIE2_SHIFT))&EQADC_IDCR1_CFUIE2_MASK)
#define EQADC_IDCR1_EOQIE2_MASK                  0x10000000u
#define EQADC_IDCR1_EOQIE2_SHIFT                 28u
#define EQADC_IDCR1_EOQIE2_WIDTH                 1u
#define EQADC_IDCR1_EOQIE2(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR1_EOQIE2_SHIFT))&EQADC_IDCR1_EOQIE2_MASK)
#define EQADC_IDCR1_PIE2_MASK                    0x20000000u
#define EQADC_IDCR1_PIE2_SHIFT                   29u
#define EQADC_IDCR1_PIE2_WIDTH                   1u
#define EQADC_IDCR1_PIE2(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR1_PIE2_SHIFT))&EQADC_IDCR1_PIE2_MASK)
#define EQADC_IDCR1_TORIE2_MASK                  0x40000000u
#define EQADC_IDCR1_TORIE2_SHIFT                 30u
#define EQADC_IDCR1_TORIE2_WIDTH                 1u
#define EQADC_IDCR1_TORIE2(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR1_TORIE2_SHIFT))&EQADC_IDCR1_TORIE2_MASK)
#define EQADC_IDCR1_NCIE2_MASK                   0x80000000u
#define EQADC_IDCR1_NCIE2_SHIFT                  31u
#define EQADC_IDCR1_NCIE2_WIDTH                  1u
#define EQADC_IDCR1_NCIE2(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR1_NCIE2_SHIFT))&EQADC_IDCR1_NCIE2_MASK)
/* IDCR2 Bit Fields */
#define EQADC_IDCR2_RFDS5_MASK                   0x1u
#define EQADC_IDCR2_RFDS5_SHIFT                  0u
#define EQADC_IDCR2_RFDS5_WIDTH                  1u
#define EQADC_IDCR2_RFDS5(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR2_RFDS5_SHIFT))&EQADC_IDCR2_RFDS5_MASK)
#define EQADC_IDCR2_RFDE5_MASK                   0x2u
#define EQADC_IDCR2_RFDE5_SHIFT                  1u
#define EQADC_IDCR2_RFDE5_WIDTH                  1u
#define EQADC_IDCR2_RFDE5(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR2_RFDE5_SHIFT))&EQADC_IDCR2_RFDE5_MASK)
#define EQADC_IDCR2_RFOIE5_MASK                  0x8u
#define EQADC_IDCR2_RFOIE5_SHIFT                 3u
#define EQADC_IDCR2_RFOIE5_WIDTH                 1u
#define EQADC_IDCR2_RFOIE5(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR2_RFOIE5_SHIFT))&EQADC_IDCR2_RFOIE5_MASK)
#define EQADC_IDCR2_CFFS5_MASK                   0x100u
#define EQADC_IDCR2_CFFS5_SHIFT                  8u
#define EQADC_IDCR2_CFFS5_WIDTH                  1u
#define EQADC_IDCR2_CFFS5(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR2_CFFS5_SHIFT))&EQADC_IDCR2_CFFS5_MASK)
#define EQADC_IDCR2_CFFE5_MASK                   0x200u
#define EQADC_IDCR2_CFFE5_SHIFT                  9u
#define EQADC_IDCR2_CFFE5_WIDTH                  1u
#define EQADC_IDCR2_CFFE5(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR2_CFFE5_SHIFT))&EQADC_IDCR2_CFFE5_MASK)
#define EQADC_IDCR2_CFUIE5_MASK                  0x800u
#define EQADC_IDCR2_CFUIE5_SHIFT                 11u
#define EQADC_IDCR2_CFUIE5_WIDTH                 1u
#define EQADC_IDCR2_CFUIE5(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR2_CFUIE5_SHIFT))&EQADC_IDCR2_CFUIE5_MASK)
#define EQADC_IDCR2_EOQIE5_MASK                  0x1000u
#define EQADC_IDCR2_EOQIE5_SHIFT                 12u
#define EQADC_IDCR2_EOQIE5_WIDTH                 1u
#define EQADC_IDCR2_EOQIE5(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR2_EOQIE5_SHIFT))&EQADC_IDCR2_EOQIE5_MASK)
#define EQADC_IDCR2_PIE5_MASK                    0x2000u
#define EQADC_IDCR2_PIE5_SHIFT                   13u
#define EQADC_IDCR2_PIE5_WIDTH                   1u
#define EQADC_IDCR2_PIE5(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR2_PIE5_SHIFT))&EQADC_IDCR2_PIE5_MASK)
#define EQADC_IDCR2_TORIE5_MASK                  0x4000u
#define EQADC_IDCR2_TORIE5_SHIFT                 14u
#define EQADC_IDCR2_TORIE5_WIDTH                 1u
#define EQADC_IDCR2_TORIE5(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR2_TORIE5_SHIFT))&EQADC_IDCR2_TORIE5_MASK)
#define EQADC_IDCR2_NCIE5_MASK                   0x8000u
#define EQADC_IDCR2_NCIE5_SHIFT                  15u
#define EQADC_IDCR2_NCIE5_WIDTH                  1u
#define EQADC_IDCR2_NCIE5(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR2_NCIE5_SHIFT))&EQADC_IDCR2_NCIE5_MASK)
#define EQADC_IDCR2_RFDS4_MASK                   0x10000u
#define EQADC_IDCR2_RFDS4_SHIFT                  16u
#define EQADC_IDCR2_RFDS4_WIDTH                  1u
#define EQADC_IDCR2_RFDS4(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR2_RFDS4_SHIFT))&EQADC_IDCR2_RFDS4_MASK)
#define EQADC_IDCR2_RFDE4_MASK                   0x20000u
#define EQADC_IDCR2_RFDE4_SHIFT                  17u
#define EQADC_IDCR2_RFDE4_WIDTH                  1u
#define EQADC_IDCR2_RFDE4(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR2_RFDE4_SHIFT))&EQADC_IDCR2_RFDE4_MASK)
#define EQADC_IDCR2_RFOIE4_MASK                  0x80000u
#define EQADC_IDCR2_RFOIE4_SHIFT                 19u
#define EQADC_IDCR2_RFOIE4_WIDTH                 1u
#define EQADC_IDCR2_RFOIE4(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR2_RFOIE4_SHIFT))&EQADC_IDCR2_RFOIE4_MASK)
#define EQADC_IDCR2_CFFS4_MASK                   0x1000000u
#define EQADC_IDCR2_CFFS4_SHIFT                  24u
#define EQADC_IDCR2_CFFS4_WIDTH                  1u
#define EQADC_IDCR2_CFFS4(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR2_CFFS4_SHIFT))&EQADC_IDCR2_CFFS4_MASK)
#define EQADC_IDCR2_CFFE4_MASK                   0x2000000u
#define EQADC_IDCR2_CFFE4_SHIFT                  25u
#define EQADC_IDCR2_CFFE4_WIDTH                  1u
#define EQADC_IDCR2_CFFE4(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR2_CFFE4_SHIFT))&EQADC_IDCR2_CFFE4_MASK)
#define EQADC_IDCR2_CFUIE4_MASK                  0x8000000u
#define EQADC_IDCR2_CFUIE4_SHIFT                 27u
#define EQADC_IDCR2_CFUIE4_WIDTH                 1u
#define EQADC_IDCR2_CFUIE4(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR2_CFUIE4_SHIFT))&EQADC_IDCR2_CFUIE4_MASK)
#define EQADC_IDCR2_EOQIE4_MASK                  0x10000000u
#define EQADC_IDCR2_EOQIE4_SHIFT                 28u
#define EQADC_IDCR2_EOQIE4_WIDTH                 1u
#define EQADC_IDCR2_EOQIE4(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR2_EOQIE4_SHIFT))&EQADC_IDCR2_EOQIE4_MASK)
#define EQADC_IDCR2_PIE4_MASK                    0x20000000u
#define EQADC_IDCR2_PIE4_SHIFT                   29u
#define EQADC_IDCR2_PIE4_WIDTH                   1u
#define EQADC_IDCR2_PIE4(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR2_PIE4_SHIFT))&EQADC_IDCR2_PIE4_MASK)
#define EQADC_IDCR2_TORIE4_MASK                  0x40000000u
#define EQADC_IDCR2_TORIE4_SHIFT                 30u
#define EQADC_IDCR2_TORIE4_WIDTH                 1u
#define EQADC_IDCR2_TORIE4(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR2_TORIE4_SHIFT))&EQADC_IDCR2_TORIE4_MASK)
#define EQADC_IDCR2_NCIE4_MASK                   0x80000000u
#define EQADC_IDCR2_NCIE4_SHIFT                  31u
#define EQADC_IDCR2_NCIE4_WIDTH                  1u
#define EQADC_IDCR2_NCIE4(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR2_NCIE4_SHIFT))&EQADC_IDCR2_NCIE4_MASK)
/* IDCR3 Bit Fields */
#define EQADC_IDCR3_RFDS7_MASK                   0x1u
#define EQADC_IDCR3_RFDS7_SHIFT                  0u
#define EQADC_IDCR3_RFDS7_WIDTH                  1u
#define EQADC_IDCR3_RFDS7(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR3_RFDS7_SHIFT))&EQADC_IDCR3_RFDS7_MASK)
#define EQADC_IDCR3_RFDE7_MASK                   0x2u
#define EQADC_IDCR3_RFDE7_SHIFT                  1u
#define EQADC_IDCR3_RFDE7_WIDTH                  1u
#define EQADC_IDCR3_RFDE7(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR3_RFDE7_SHIFT))&EQADC_IDCR3_RFDE7_MASK)
#define EQADC_IDCR3_RFOIE7_MASK                  0x8u
#define EQADC_IDCR3_RFOIE7_SHIFT                 3u
#define EQADC_IDCR3_RFOIE7_WIDTH                 1u
#define EQADC_IDCR3_RFOIE7(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR3_RFOIE7_SHIFT))&EQADC_IDCR3_RFOIE7_MASK)
#define EQADC_IDCR3_CFFS7_MASK                   0x100u
#define EQADC_IDCR3_CFFS7_SHIFT                  8u
#define EQADC_IDCR3_CFFS7_WIDTH                  1u
#define EQADC_IDCR3_CFFS7(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR3_CFFS7_SHIFT))&EQADC_IDCR3_CFFS7_MASK)
#define EQADC_IDCR3_CFFE7_MASK                   0x200u
#define EQADC_IDCR3_CFFE7_SHIFT                  9u
#define EQADC_IDCR3_CFFE7_WIDTH                  1u
#define EQADC_IDCR3_CFFE7(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR3_CFFE7_SHIFT))&EQADC_IDCR3_CFFE7_MASK)
#define EQADC_IDCR3_CFUIE7_MASK                  0x800u
#define EQADC_IDCR3_CFUIE7_SHIFT                 11u
#define EQADC_IDCR3_CFUIE7_WIDTH                 1u
#define EQADC_IDCR3_CFUIE7(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR3_CFUIE7_SHIFT))&EQADC_IDCR3_CFUIE7_MASK)
#define EQADC_IDCR3_EOQIE7_MASK                  0x1000u
#define EQADC_IDCR3_EOQIE7_SHIFT                 12u
#define EQADC_IDCR3_EOQIE7_WIDTH                 1u
#define EQADC_IDCR3_EOQIE7(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR3_EOQIE7_SHIFT))&EQADC_IDCR3_EOQIE7_MASK)
#define EQADC_IDCR3_PIE7_MASK                    0x2000u
#define EQADC_IDCR3_PIE7_SHIFT                   13u
#define EQADC_IDCR3_PIE7_WIDTH                   1u
#define EQADC_IDCR3_PIE7(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR3_PIE7_SHIFT))&EQADC_IDCR3_PIE7_MASK)
#define EQADC_IDCR3_TORIE7_MASK                  0x4000u
#define EQADC_IDCR3_TORIE7_SHIFT                 14u
#define EQADC_IDCR3_TORIE7_WIDTH                 1u
#define EQADC_IDCR3_TORIE7(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR3_TORIE7_SHIFT))&EQADC_IDCR3_TORIE7_MASK)
#define EQADC_IDCR3_NCIE7_MASK                   0x8000u
#define EQADC_IDCR3_NCIE7_SHIFT                  15u
#define EQADC_IDCR3_NCIE7_WIDTH                  1u
#define EQADC_IDCR3_NCIE7(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR3_NCIE7_SHIFT))&EQADC_IDCR3_NCIE7_MASK)
#define EQADC_IDCR3_RFDS6_MASK                   0x10000u
#define EQADC_IDCR3_RFDS6_SHIFT                  16u
#define EQADC_IDCR3_RFDS6_WIDTH                  1u
#define EQADC_IDCR3_RFDS6(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR3_RFDS6_SHIFT))&EQADC_IDCR3_RFDS6_MASK)
#define EQADC_IDCR3_RFDE6_MASK                   0x20000u
#define EQADC_IDCR3_RFDE6_SHIFT                  17u
#define EQADC_IDCR3_RFDE6_WIDTH                  1u
#define EQADC_IDCR3_RFDE6(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR3_RFDE6_SHIFT))&EQADC_IDCR3_RFDE6_MASK)
#define EQADC_IDCR3_RFOIE6_MASK                  0x80000u
#define EQADC_IDCR3_RFOIE6_SHIFT                 19u
#define EQADC_IDCR3_RFOIE6_WIDTH                 1u
#define EQADC_IDCR3_RFOIE6(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR3_RFOIE6_SHIFT))&EQADC_IDCR3_RFOIE6_MASK)
#define EQADC_IDCR3_CFFS6_MASK                   0x1000000u
#define EQADC_IDCR3_CFFS6_SHIFT                  24u
#define EQADC_IDCR3_CFFS6_WIDTH                  1u
#define EQADC_IDCR3_CFFS6(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR3_CFFS6_SHIFT))&EQADC_IDCR3_CFFS6_MASK)
#define EQADC_IDCR3_CFFE6_MASK                   0x2000000u
#define EQADC_IDCR3_CFFE6_SHIFT                  25u
#define EQADC_IDCR3_CFFE6_WIDTH                  1u
#define EQADC_IDCR3_CFFE6(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR3_CFFE6_SHIFT))&EQADC_IDCR3_CFFE6_MASK)
#define EQADC_IDCR3_CFUIE6_MASK                  0x8000000u
#define EQADC_IDCR3_CFUIE6_SHIFT                 27u
#define EQADC_IDCR3_CFUIE6_WIDTH                 1u
#define EQADC_IDCR3_CFUIE6(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR3_CFUIE6_SHIFT))&EQADC_IDCR3_CFUIE6_MASK)
#define EQADC_IDCR3_EOQIE6_MASK                  0x10000000u
#define EQADC_IDCR3_EOQIE6_SHIFT                 28u
#define EQADC_IDCR3_EOQIE6_WIDTH                 1u
#define EQADC_IDCR3_EOQIE6(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR3_EOQIE6_SHIFT))&EQADC_IDCR3_EOQIE6_MASK)
#define EQADC_IDCR3_PIE6_MASK                    0x20000000u
#define EQADC_IDCR3_PIE6_SHIFT                   29u
#define EQADC_IDCR3_PIE6_WIDTH                   1u
#define EQADC_IDCR3_PIE6(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR3_PIE6_SHIFT))&EQADC_IDCR3_PIE6_MASK)
#define EQADC_IDCR3_TORIE6_MASK                  0x40000000u
#define EQADC_IDCR3_TORIE6_SHIFT                 30u
#define EQADC_IDCR3_TORIE6_WIDTH                 1u
#define EQADC_IDCR3_TORIE6(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR3_TORIE6_SHIFT))&EQADC_IDCR3_TORIE6_MASK)
#define EQADC_IDCR3_NCIE6_MASK                   0x80000000u
#define EQADC_IDCR3_NCIE6_SHIFT                  31u
#define EQADC_IDCR3_NCIE6_WIDTH                  1u
#define EQADC_IDCR3_NCIE6(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_IDCR3_NCIE6_SHIFT))&EQADC_IDCR3_NCIE6_MASK)
/* FISR Bit Fields */
#define EQADC_FISR_POPNXTPTRX_MASK               0xFu
#define EQADC_FISR_POPNXTPTRX_SHIFT              0u
#define EQADC_FISR_POPNXTPTRX_WIDTH              4u
#define EQADC_FISR_POPNXTPTRX(x)                 (((uint32_t)(((uint32_t)(x))<<EQADC_FISR_POPNXTPTRX_SHIFT))&EQADC_FISR_POPNXTPTRX_MASK)
#define EQADC_FISR_RFCTRX_MASK                   0xF0u
#define EQADC_FISR_RFCTRX_SHIFT                  4u
#define EQADC_FISR_RFCTRX_WIDTH                  4u
#define EQADC_FISR_RFCTRX(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_FISR_RFCTRX_SHIFT))&EQADC_FISR_RFCTRX_MASK)
#define EQADC_FISR_TNXTPTRX_MASK                 0xF00u
#define EQADC_FISR_TNXTPTRX_SHIFT                8u
#define EQADC_FISR_TNXTPTRX_WIDTH                4u
#define EQADC_FISR_TNXTPTRX(x)                   (((uint32_t)(((uint32_t)(x))<<EQADC_FISR_TNXTPTRX_SHIFT))&EQADC_FISR_TNXTPTRX_MASK)
#define EQADC_FISR_CFCTRX_MASK                   0xF000u
#define EQADC_FISR_CFCTRX_SHIFT                  12u
#define EQADC_FISR_CFCTRX_WIDTH                  4u
#define EQADC_FISR_CFCTRX(x)                     (((uint32_t)(((uint32_t)(x))<<EQADC_FISR_CFCTRX_SHIFT))&EQADC_FISR_CFCTRX_MASK)
#define EQADC_FISR_RFDFX_MASK                    0x20000u
#define EQADC_FISR_RFDFX_SHIFT                   17u
#define EQADC_FISR_RFDFX_WIDTH                   1u
#define EQADC_FISR_RFDFX(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_FISR_RFDFX_SHIFT))&EQADC_FISR_RFDFX_MASK)
#define EQADC_FISR_RFOFX_MASK                    0x80000u
#define EQADC_FISR_RFOFX_SHIFT                   19u
#define EQADC_FISR_RFOFX_WIDTH                   1u
#define EQADC_FISR_RFOFX(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_FISR_RFOFX_SHIFT))&EQADC_FISR_RFOFX_MASK)
#define EQADC_FISR_CFFFX_MASK                    0x2000000u
#define EQADC_FISR_CFFFX_SHIFT                   25u
#define EQADC_FISR_CFFFX_WIDTH                   1u
#define EQADC_FISR_CFFFX(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_FISR_CFFFX_SHIFT))&EQADC_FISR_CFFFX_MASK)
#define EQADC_FISR_SSSX_MASK                     0x4000000u
#define EQADC_FISR_SSSX_SHIFT                    26u
#define EQADC_FISR_SSSX_WIDTH                    1u
#define EQADC_FISR_SSSX(x)                       (((uint32_t)(((uint32_t)(x))<<EQADC_FISR_SSSX_SHIFT))&EQADC_FISR_SSSX_MASK)
#define EQADC_FISR_CFUFX_MASK                    0x8000000u
#define EQADC_FISR_CFUFX_SHIFT                   27u
#define EQADC_FISR_CFUFX_WIDTH                   1u
#define EQADC_FISR_CFUFX(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_FISR_CFUFX_SHIFT))&EQADC_FISR_CFUFX_MASK)
#define EQADC_FISR_EOQFX_MASK                    0x10000000u
#define EQADC_FISR_EOQFX_SHIFT                   28u
#define EQADC_FISR_EOQFX_WIDTH                   1u
#define EQADC_FISR_EOQFX(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_FISR_EOQFX_SHIFT))&EQADC_FISR_EOQFX_MASK)
#define EQADC_FISR_PFX_MASK                      0x20000000u
#define EQADC_FISR_PFX_SHIFT                     29u
#define EQADC_FISR_PFX_WIDTH                     1u
#define EQADC_FISR_PFX(x)                        (((uint32_t)(((uint32_t)(x))<<EQADC_FISR_PFX_SHIFT))&EQADC_FISR_PFX_MASK)
#define EQADC_FISR_TORFX_MASK                    0x40000000u
#define EQADC_FISR_TORFX_SHIFT                   30u
#define EQADC_FISR_TORFX_WIDTH                   1u
#define EQADC_FISR_TORFX(x)                      (((uint32_t)(((uint32_t)(x))<<EQADC_FISR_TORFX_SHIFT))&EQADC_FISR_TORFX_MASK)
#define EQADC_FISR_NCFX_MASK                     0x80000000u
#define EQADC_FISR_NCFX_SHIFT                    31u
#define EQADC_FISR_NCFX_WIDTH                    1u
#define EQADC_FISR_NCFX(x)                       (((uint32_t)(((uint32_t)(x))<<EQADC_FISR_NCFX_SHIFT))&EQADC_FISR_NCFX_MASK)
/* CFTCR0 Bit Fields */
#define EQADC_CFTCR0_TC_CF1_MASK                 0x7FFu
#define EQADC_CFTCR0_TC_CF1_SHIFT                0u
#define EQADC_CFTCR0_TC_CF1_WIDTH                11u
#define EQADC_CFTCR0_TC_CF1(x)                   (((uint32_t)(((uint32_t)(x))<<EQADC_CFTCR0_TC_CF1_SHIFT))&EQADC_CFTCR0_TC_CF1_MASK)
#define EQADC_CFTCR0_TC_CF0_MASK                 0x7FF0000u
#define EQADC_CFTCR0_TC_CF0_SHIFT                16u
#define EQADC_CFTCR0_TC_CF0_WIDTH                11u
#define EQADC_CFTCR0_TC_CF0(x)                   (((uint32_t)(((uint32_t)(x))<<EQADC_CFTCR0_TC_CF0_SHIFT))&EQADC_CFTCR0_TC_CF0_MASK)
/* CFTCR1 Bit Fields */
#define EQADC_CFTCR1_TC_CF3_MASK                 0x7FFu
#define EQADC_CFTCR1_TC_CF3_SHIFT                0u
#define EQADC_CFTCR1_TC_CF3_WIDTH                11u
#define EQADC_CFTCR1_TC_CF3(x)                   (((uint32_t)(((uint32_t)(x))<<EQADC_CFTCR1_TC_CF3_SHIFT))&EQADC_CFTCR1_TC_CF3_MASK)
#define EQADC_CFTCR1_TC_CF2_MASK                 0x7FF0000u
#define EQADC_CFTCR1_TC_CF2_SHIFT                16u
#define EQADC_CFTCR1_TC_CF2_WIDTH                11u
#define EQADC_CFTCR1_TC_CF2(x)                   (((uint32_t)(((uint32_t)(x))<<EQADC_CFTCR1_TC_CF2_SHIFT))&EQADC_CFTCR1_TC_CF2_MASK)
/* CFTCR2 Bit Fields */
#define EQADC_CFTCR2_TC_CF5_MASK                 0x7FFu
#define EQADC_CFTCR2_TC_CF5_SHIFT                0u
#define EQADC_CFTCR2_TC_CF5_WIDTH                11u
#define EQADC_CFTCR2_TC_CF5(x)                   (((uint32_t)(((uint32_t)(x))<<EQADC_CFTCR2_TC_CF5_SHIFT))&EQADC_CFTCR2_TC_CF5_MASK)
#define EQADC_CFTCR2_TC_CF4_MASK                 0x7FF0000u
#define EQADC_CFTCR2_TC_CF4_SHIFT                16u
#define EQADC_CFTCR2_TC_CF4_WIDTH                11u
#define EQADC_CFTCR2_TC_CF4(x)                   (((uint32_t)(((uint32_t)(x))<<EQADC_CFTCR2_TC_CF4_SHIFT))&EQADC_CFTCR2_TC_CF4_MASK)
/* CFTCR3 Bit Fields */
#define EQADC_CFTCR3_TC_CF7_MASK                 0x7FFu
#define EQADC_CFTCR3_TC_CF7_SHIFT                0u
#define EQADC_CFTCR3_TC_CF7_WIDTH                11u
#define EQADC_CFTCR3_TC_CF7(x)                   (((uint32_t)(((uint32_t)(x))<<EQADC_CFTCR3_TC_CF7_SHIFT))&EQADC_CFTCR3_TC_CF7_MASK)
#define EQADC_CFTCR3_TC_CF6_MASK                 0x7FF0000u
#define EQADC_CFTCR3_TC_CF6_SHIFT                16u
#define EQADC_CFTCR3_TC_CF6_WIDTH                11u
#define EQADC_CFTCR3_TC_CF6(x)                   (((uint32_t)(((uint32_t)(x))<<EQADC_CFTCR3_TC_CF6_SHIFT))&EQADC_CFTCR3_TC_CF6_MASK)
/* CFSSR0 Bit Fields */
#define EQADC_CFSSR0_TC_LCFTCB0_MASK             0x7FFu
#define EQADC_CFSSR0_TC_LCFTCB0_SHIFT            0u
#define EQADC_CFSSR0_TC_LCFTCB0_WIDTH            11u
#define EQADC_CFSSR0_TC_LCFTCB0(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_CFSSR0_TC_LCFTCB0_SHIFT))&EQADC_CFSSR0_TC_LCFTCB0_MASK)
#define EQADC_CFSSR0_LCFTCB0_MASK                0x7800u
#define EQADC_CFSSR0_LCFTCB0_SHIFT               11u
#define EQADC_CFSSR0_LCFTCB0_WIDTH               4u
#define EQADC_CFSSR0_LCFTCB0(x)                  (((uint32_t)(((uint32_t)(x))<<EQADC_CFSSR0_LCFTCB0_SHIFT))&EQADC_CFSSR0_LCFTCB0_MASK)
#define EQADC_CFSSR0_CFS7_TCB0_MASK              0x30000u
#define EQADC_CFSSR0_CFS7_TCB0_SHIFT             16u
#define EQADC_CFSSR0_CFS7_TCB0_WIDTH             2u
#define EQADC_CFSSR0_CFS7_TCB0(x)                (((uint32_t)(((uint32_t)(x))<<EQADC_CFSSR0_CFS7_TCB0_SHIFT))&EQADC_CFSSR0_CFS7_TCB0_MASK)
#define EQADC_CFSSR0_CFS6_TCB0_MASK              0xC0000u
#define EQADC_CFSSR0_CFS6_TCB0_SHIFT             18u
#define EQADC_CFSSR0_CFS6_TCB0_WIDTH             2u
#define EQADC_CFSSR0_CFS6_TCB0(x)                (((uint32_t)(((uint32_t)(x))<<EQADC_CFSSR0_CFS6_TCB0_SHIFT))&EQADC_CFSSR0_CFS6_TCB0_MASK)
#define EQADC_CFSSR0_CFS5_TCB0_MASK              0x300000u
#define EQADC_CFSSR0_CFS5_TCB0_SHIFT             20u
#define EQADC_CFSSR0_CFS5_TCB0_WIDTH             2u
#define EQADC_CFSSR0_CFS5_TCB0(x)                (((uint32_t)(((uint32_t)(x))<<EQADC_CFSSR0_CFS5_TCB0_SHIFT))&EQADC_CFSSR0_CFS5_TCB0_MASK)
#define EQADC_CFSSR0_CFS4_TCB0_MASK              0xC00000u
#define EQADC_CFSSR0_CFS4_TCB0_SHIFT             22u
#define EQADC_CFSSR0_CFS4_TCB0_WIDTH             2u
#define EQADC_CFSSR0_CFS4_TCB0(x)                (((uint32_t)(((uint32_t)(x))<<EQADC_CFSSR0_CFS4_TCB0_SHIFT))&EQADC_CFSSR0_CFS4_TCB0_MASK)
#define EQADC_CFSSR0_CFS3_TCB0_MASK              0x3000000u
#define EQADC_CFSSR0_CFS3_TCB0_SHIFT             24u
#define EQADC_CFSSR0_CFS3_TCB0_WIDTH             2u
#define EQADC_CFSSR0_CFS3_TCB0(x)                (((uint32_t)(((uint32_t)(x))<<EQADC_CFSSR0_CFS3_TCB0_SHIFT))&EQADC_CFSSR0_CFS3_TCB0_MASK)
#define EQADC_CFSSR0_CFS2_TCB0_MASK              0xC000000u
#define EQADC_CFSSR0_CFS2_TCB0_SHIFT             26u
#define EQADC_CFSSR0_CFS2_TCB0_WIDTH             2u
#define EQADC_CFSSR0_CFS2_TCB0(x)                (((uint32_t)(((uint32_t)(x))<<EQADC_CFSSR0_CFS2_TCB0_SHIFT))&EQADC_CFSSR0_CFS2_TCB0_MASK)
#define EQADC_CFSSR0_CFS1_TCB0_MASK              0x30000000u
#define EQADC_CFSSR0_CFS1_TCB0_SHIFT             28u
#define EQADC_CFSSR0_CFS1_TCB0_WIDTH             2u
#define EQADC_CFSSR0_CFS1_TCB0(x)                (((uint32_t)(((uint32_t)(x))<<EQADC_CFSSR0_CFS1_TCB0_SHIFT))&EQADC_CFSSR0_CFS1_TCB0_MASK)
#define EQADC_CFSSR0_CFS0_TCB0_MASK              0xC0000000u
#define EQADC_CFSSR0_CFS0_TCB0_SHIFT             30u
#define EQADC_CFSSR0_CFS0_TCB0_WIDTH             2u
#define EQADC_CFSSR0_CFS0_TCB0(x)                (((uint32_t)(((uint32_t)(x))<<EQADC_CFSSR0_CFS0_TCB0_SHIFT))&EQADC_CFSSR0_CFS0_TCB0_MASK)
/* CFSSR1 Bit Fields */
#define EQADC_CFSSR1_TC_LCFTCB1_MASK             0x7FFu
#define EQADC_CFSSR1_TC_LCFTCB1_SHIFT            0u
#define EQADC_CFSSR1_TC_LCFTCB1_WIDTH            11u
#define EQADC_CFSSR1_TC_LCFTCB1(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_CFSSR1_TC_LCFTCB1_SHIFT))&EQADC_CFSSR1_TC_LCFTCB1_MASK)
#define EQADC_CFSSR1_LCFTCB1_MASK                0x7800u
#define EQADC_CFSSR1_LCFTCB1_SHIFT               11u
#define EQADC_CFSSR1_LCFTCB1_WIDTH               4u
#define EQADC_CFSSR1_LCFTCB1(x)                  (((uint32_t)(((uint32_t)(x))<<EQADC_CFSSR1_LCFTCB1_SHIFT))&EQADC_CFSSR1_LCFTCB1_MASK)
#define EQADC_CFSSR1_CFS7_TCB1_MASK              0x30000u
#define EQADC_CFSSR1_CFS7_TCB1_SHIFT             16u
#define EQADC_CFSSR1_CFS7_TCB1_WIDTH             2u
#define EQADC_CFSSR1_CFS7_TCB1(x)                (((uint32_t)(((uint32_t)(x))<<EQADC_CFSSR1_CFS7_TCB1_SHIFT))&EQADC_CFSSR1_CFS7_TCB1_MASK)
#define EQADC_CFSSR1_CFS6_TCB1_MASK              0xC0000u
#define EQADC_CFSSR1_CFS6_TCB1_SHIFT             18u
#define EQADC_CFSSR1_CFS6_TCB1_WIDTH             2u
#define EQADC_CFSSR1_CFS6_TCB1(x)                (((uint32_t)(((uint32_t)(x))<<EQADC_CFSSR1_CFS6_TCB1_SHIFT))&EQADC_CFSSR1_CFS6_TCB1_MASK)
#define EQADC_CFSSR1_CFS5_TCB1_MASK              0x300000u
#define EQADC_CFSSR1_CFS5_TCB1_SHIFT             20u
#define EQADC_CFSSR1_CFS5_TCB1_WIDTH             2u
#define EQADC_CFSSR1_CFS5_TCB1(x)                (((uint32_t)(((uint32_t)(x))<<EQADC_CFSSR1_CFS5_TCB1_SHIFT))&EQADC_CFSSR1_CFS5_TCB1_MASK)
#define EQADC_CFSSR1_CFS4_TCB1_MASK              0xC00000u
#define EQADC_CFSSR1_CFS4_TCB1_SHIFT             22u
#define EQADC_CFSSR1_CFS4_TCB1_WIDTH             2u
#define EQADC_CFSSR1_CFS4_TCB1(x)                (((uint32_t)(((uint32_t)(x))<<EQADC_CFSSR1_CFS4_TCB1_SHIFT))&EQADC_CFSSR1_CFS4_TCB1_MASK)
#define EQADC_CFSSR1_CFS3_TCB1_MASK              0x3000000u
#define EQADC_CFSSR1_CFS3_TCB1_SHIFT             24u
#define EQADC_CFSSR1_CFS3_TCB1_WIDTH             2u
#define EQADC_CFSSR1_CFS3_TCB1(x)                (((uint32_t)(((uint32_t)(x))<<EQADC_CFSSR1_CFS3_TCB1_SHIFT))&EQADC_CFSSR1_CFS3_TCB1_MASK)
#define EQADC_CFSSR1_CFS2_TCB1_MASK              0xC000000u
#define EQADC_CFSSR1_CFS2_TCB1_SHIFT             26u
#define EQADC_CFSSR1_CFS2_TCB1_WIDTH             2u
#define EQADC_CFSSR1_CFS2_TCB1(x)                (((uint32_t)(((uint32_t)(x))<<EQADC_CFSSR1_CFS2_TCB1_SHIFT))&EQADC_CFSSR1_CFS2_TCB1_MASK)
#define EQADC_CFSSR1_CFS1_TCB1_MASK              0x30000000u
#define EQADC_CFSSR1_CFS1_TCB1_SHIFT             28u
#define EQADC_CFSSR1_CFS1_TCB1_WIDTH             2u
#define EQADC_CFSSR1_CFS1_TCB1(x)                (((uint32_t)(((uint32_t)(x))<<EQADC_CFSSR1_CFS1_TCB1_SHIFT))&EQADC_CFSSR1_CFS1_TCB1_MASK)
#define EQADC_CFSSR1_CFS0_TCB1_MASK              0xC0000000u
#define EQADC_CFSSR1_CFS0_TCB1_SHIFT             30u
#define EQADC_CFSSR1_CFS0_TCB1_WIDTH             2u
#define EQADC_CFSSR1_CFS0_TCB1(x)                (((uint32_t)(((uint32_t)(x))<<EQADC_CFSSR1_CFS0_TCB1_SHIFT))&EQADC_CFSSR1_CFS0_TCB1_MASK)
/* CFSR Bit Fields */
#define EQADC_CFSR_CFS7_MASK                     0x30000u
#define EQADC_CFSR_CFS7_SHIFT                    16u
#define EQADC_CFSR_CFS7_WIDTH                    2u
#define EQADC_CFSR_CFS7(x)                       (((uint32_t)(((uint32_t)(x))<<EQADC_CFSR_CFS7_SHIFT))&EQADC_CFSR_CFS7_MASK)
#define EQADC_CFSR_CFS6_MASK                     0xC0000u
#define EQADC_CFSR_CFS6_SHIFT                    18u
#define EQADC_CFSR_CFS6_WIDTH                    2u
#define EQADC_CFSR_CFS6(x)                       (((uint32_t)(((uint32_t)(x))<<EQADC_CFSR_CFS6_SHIFT))&EQADC_CFSR_CFS6_MASK)
#define EQADC_CFSR_CFS5_MASK                     0x300000u
#define EQADC_CFSR_CFS5_SHIFT                    20u
#define EQADC_CFSR_CFS5_WIDTH                    2u
#define EQADC_CFSR_CFS5(x)                       (((uint32_t)(((uint32_t)(x))<<EQADC_CFSR_CFS5_SHIFT))&EQADC_CFSR_CFS5_MASK)
#define EQADC_CFSR_CFS4_MASK                     0xC00000u
#define EQADC_CFSR_CFS4_SHIFT                    22u
#define EQADC_CFSR_CFS4_WIDTH                    2u
#define EQADC_CFSR_CFS4(x)                       (((uint32_t)(((uint32_t)(x))<<EQADC_CFSR_CFS4_SHIFT))&EQADC_CFSR_CFS4_MASK)
#define EQADC_CFSR_CFS3_MASK                     0x3000000u
#define EQADC_CFSR_CFS3_SHIFT                    24u
#define EQADC_CFSR_CFS3_WIDTH                    2u
#define EQADC_CFSR_CFS3(x)                       (((uint32_t)(((uint32_t)(x))<<EQADC_CFSR_CFS3_SHIFT))&EQADC_CFSR_CFS3_MASK)
#define EQADC_CFSR_CFS2_MASK                     0xC000000u
#define EQADC_CFSR_CFS2_SHIFT                    26u
#define EQADC_CFSR_CFS2_WIDTH                    2u
#define EQADC_CFSR_CFS2(x)                       (((uint32_t)(((uint32_t)(x))<<EQADC_CFSR_CFS2_SHIFT))&EQADC_CFSR_CFS2_MASK)
#define EQADC_CFSR_CFS1_MASK                     0x30000000u
#define EQADC_CFSR_CFS1_SHIFT                    28u
#define EQADC_CFSR_CFS1_WIDTH                    2u
#define EQADC_CFSR_CFS1(x)                       (((uint32_t)(((uint32_t)(x))<<EQADC_CFSR_CFS1_SHIFT))&EQADC_CFSR_CFS1_MASK)
#define EQADC_CFSR_CFS0_MASK                     0xC0000000u
#define EQADC_CFSR_CFS0_SHIFT                    30u
#define EQADC_CFSR_CFS0_WIDTH                    2u
#define EQADC_CFSR_CFS0(x)                       (((uint32_t)(((uint32_t)(x))<<EQADC_CFSR_CFS0_SHIFT))&EQADC_CFSR_CFS0_MASK)
/* STACCCR Bit Fields */
#define EQADC_STACCCR_SRV1_MASK                  0xFu
#define EQADC_STACCCR_SRV1_SHIFT                 0u
#define EQADC_STACCCR_SRV1_WIDTH                 4u
#define EQADC_STACCCR_SRV1(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_STACCCR_SRV1_SHIFT))&EQADC_STACCCR_SRV1_MASK)
#define EQADC_STACCCR_STACBS1_MASK               0xF0u
#define EQADC_STACCCR_STACBS1_SHIFT              4u
#define EQADC_STACCCR_STACBS1_WIDTH              4u
#define EQADC_STACCCR_STACBS1(x)                 (((uint32_t)(((uint32_t)(x))<<EQADC_STACCCR_STACBS1_SHIFT))&EQADC_STACCCR_STACBS1_MASK)
#define EQADC_STACCCR_SRV2_MASK                  0xF00u
#define EQADC_STACCCR_SRV2_SHIFT                 8u
#define EQADC_STACCCR_SRV2_WIDTH                 4u
#define EQADC_STACCCR_SRV2(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_STACCCR_SRV2_SHIFT))&EQADC_STACCCR_SRV2_MASK)
#define EQADC_STACCCR_STACBS2_MASK               0xF000u
#define EQADC_STACCCR_STACBS2_SHIFT              12u
#define EQADC_STACCCR_STACBS2_WIDTH              4u
#define EQADC_STACCCR_STACBS2(x)                 (((uint32_t)(((uint32_t)(x))<<EQADC_STACCCR_STACBS2_SHIFT))&EQADC_STACCCR_STACBS2_MASK)
/* CF0R Bit Fields */
#define EQADC_CF0R_CFIFO0_DATAW_MASK             0xFFFFFFFFu
#define EQADC_CF0R_CFIFO0_DATAW_SHIFT            0u
#define EQADC_CF0R_CFIFO0_DATAW_WIDTH            32u
#define EQADC_CF0R_CFIFO0_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_CF0R_CFIFO0_DATAW_SHIFT))&EQADC_CF0R_CFIFO0_DATAW_MASK)
/* CF0ER Bit Fields */
#define EQADC_CF0ER_CFIFO0_EDATAW_MASK           0xFFFFFFFFu
#define EQADC_CF0ER_CFIFO0_EDATAW_SHIFT          0u
#define EQADC_CF0ER_CFIFO0_EDATAW_WIDTH          32u
#define EQADC_CF0ER_CFIFO0_EDATAW(x)             (((uint32_t)(((uint32_t)(x))<<EQADC_CF0ER_CFIFO0_EDATAW_SHIFT))&EQADC_CF0ER_CFIFO0_EDATAW_MASK)
/* CF1R Bit Fields */
#define EQADC_CF1R_CFIFO1_DATAW_MASK             0xFFFFFFFFu
#define EQADC_CF1R_CFIFO1_DATAW_SHIFT            0u
#define EQADC_CF1R_CFIFO1_DATAW_WIDTH            32u
#define EQADC_CF1R_CFIFO1_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_CF1R_CFIFO1_DATAW_SHIFT))&EQADC_CF1R_CFIFO1_DATAW_MASK)
/* CF2R Bit Fields */
#define EQADC_CF2R_CFIFO2_DATAW_MASK             0xFFFFFFFFu
#define EQADC_CF2R_CFIFO2_DATAW_SHIFT            0u
#define EQADC_CF2R_CFIFO2_DATAW_WIDTH            32u
#define EQADC_CF2R_CFIFO2_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_CF2R_CFIFO2_DATAW_SHIFT))&EQADC_CF2R_CFIFO2_DATAW_MASK)
/* CF3R Bit Fields */
#define EQADC_CF3R_CFIFO3_DATAW_MASK             0xFFFFFFFFu
#define EQADC_CF3R_CFIFO3_DATAW_SHIFT            0u
#define EQADC_CF3R_CFIFO3_DATAW_WIDTH            32u
#define EQADC_CF3R_CFIFO3_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_CF3R_CFIFO3_DATAW_SHIFT))&EQADC_CF3R_CFIFO3_DATAW_MASK)
/* CF4R Bit Fields */
#define EQADC_CF4R_CFIFO4_DATAW_MASK             0xFFFFFFFFu
#define EQADC_CF4R_CFIFO4_DATAW_SHIFT            0u
#define EQADC_CF4R_CFIFO4_DATAW_WIDTH            32u
#define EQADC_CF4R_CFIFO4_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_CF4R_CFIFO4_DATAW_SHIFT))&EQADC_CF4R_CFIFO4_DATAW_MASK)
/* CF5R Bit Fields */
#define EQADC_CF5R_CFIFO5_DATAW_MASK             0xFFFFFFFFu
#define EQADC_CF5R_CFIFO5_DATAW_SHIFT            0u
#define EQADC_CF5R_CFIFO5_DATAW_WIDTH            32u
#define EQADC_CF5R_CFIFO5_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_CF5R_CFIFO5_DATAW_SHIFT))&EQADC_CF5R_CFIFO5_DATAW_MASK)
/* CF6R Bit Fields */
#define EQADC_CF6R_CFIFO6_DATAW_MASK             0xFFFFFFFFu
#define EQADC_CF6R_CFIFO6_DATAW_SHIFT            0u
#define EQADC_CF6R_CFIFO6_DATAW_WIDTH            32u
#define EQADC_CF6R_CFIFO6_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_CF6R_CFIFO6_DATAW_SHIFT))&EQADC_CF6R_CFIFO6_DATAW_MASK)
/* CF7R Bit Fields */
#define EQADC_CF7R_CFIFO7_DATAW_MASK             0xFFFFFFFFu
#define EQADC_CF7R_CFIFO7_DATAW_SHIFT            0u
#define EQADC_CF7R_CFIFO7_DATAW_WIDTH            32u
#define EQADC_CF7R_CFIFO7_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_CF7R_CFIFO7_DATAW_SHIFT))&EQADC_CF7R_CFIFO7_DATAW_MASK)
/* RF0R Bit Fields */
#define EQADC_RF0R_RFIFO0_DATAW_MASK             0xFFFFu
#define EQADC_RF0R_RFIFO0_DATAW_SHIFT            0u
#define EQADC_RF0R_RFIFO0_DATAW_WIDTH            16u
#define EQADC_RF0R_RFIFO0_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_RF0R_RFIFO0_DATAW_SHIFT))&EQADC_RF0R_RFIFO0_DATAW_MASK)
/* RF1R Bit Fields */
#define EQADC_RF1R_RFIFO1_DATAW_MASK             0xFFFFu
#define EQADC_RF1R_RFIFO1_DATAW_SHIFT            0u
#define EQADC_RF1R_RFIFO1_DATAW_WIDTH            16u
#define EQADC_RF1R_RFIFO1_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_RF1R_RFIFO1_DATAW_SHIFT))&EQADC_RF1R_RFIFO1_DATAW_MASK)
/* RF2R Bit Fields */
#define EQADC_RF2R_RFIFO2_DATAW_MASK             0xFFFFu
#define EQADC_RF2R_RFIFO2_DATAW_SHIFT            0u
#define EQADC_RF2R_RFIFO2_DATAW_WIDTH            16u
#define EQADC_RF2R_RFIFO2_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_RF2R_RFIFO2_DATAW_SHIFT))&EQADC_RF2R_RFIFO2_DATAW_MASK)
/* RF3R Bit Fields */
#define EQADC_RF3R_RFIFO3_DATAW_MASK             0xFFFFu
#define EQADC_RF3R_RFIFO3_DATAW_SHIFT            0u
#define EQADC_RF3R_RFIFO3_DATAW_WIDTH            16u
#define EQADC_RF3R_RFIFO3_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_RF3R_RFIFO3_DATAW_SHIFT))&EQADC_RF3R_RFIFO3_DATAW_MASK)
/* RF4R Bit Fields */
#define EQADC_RF4R_RFIFO4_DATAW_MASK             0xFFFFu
#define EQADC_RF4R_RFIFO4_DATAW_SHIFT            0u
#define EQADC_RF4R_RFIFO4_DATAW_WIDTH            16u
#define EQADC_RF4R_RFIFO4_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_RF4R_RFIFO4_DATAW_SHIFT))&EQADC_RF4R_RFIFO4_DATAW_MASK)
/* RF5R Bit Fields */
#define EQADC_RF5R_RFIFO5_DATAW_MASK             0xFFFFu
#define EQADC_RF5R_RFIFO5_DATAW_SHIFT            0u
#define EQADC_RF5R_RFIFO5_DATAW_WIDTH            16u
#define EQADC_RF5R_RFIFO5_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_RF5R_RFIFO5_DATAW_SHIFT))&EQADC_RF5R_RFIFO5_DATAW_MASK)
/* RF6R Bit Fields */
#define EQADC_RF6R_RFIFO6_DATAW_MASK             0xFFFFu
#define EQADC_RF6R_RFIFO6_DATAW_SHIFT            0u
#define EQADC_RF6R_RFIFO6_DATAW_WIDTH            16u
#define EQADC_RF6R_RFIFO6_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_RF6R_RFIFO6_DATAW_SHIFT))&EQADC_RF6R_RFIFO6_DATAW_MASK)
/* RF7R Bit Fields */
#define EQADC_RF7R_RFIFO7_DATAW_MASK             0xFFFFu
#define EQADC_RF7R_RFIFO7_DATAW_SHIFT            0u
#define EQADC_RF7R_RFIFO7_DATAW_WIDTH            16u
#define EQADC_RF7R_RFIFO7_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_RF7R_RFIFO7_DATAW_SHIFT))&EQADC_RF7R_RFIFO7_DATAW_MASK)
/* RF0R - RF7R Bit Fields */
#define EQADC_RFXR_RFIFOX_CH_NUM_MASK            0xFF0000u
#define EQADC_RFXR_RFIFOX_CH_NUM_SHIFT           16u
#define EQADC_RFXR_RFIFOX_CH_NUM_WIDTH           8u
#define EQADC_RFXR_RFIFOX_CH_NUM(x)              (((uint32_t)(((uint32_t)(x))<<EQADC_RFXR_RFIFOX_CH_NUM_SHIFT))&EQADC_RFXR_RFIFOX_CH_NUM_MASK)
#define EQADC_RFXR_RFIFOX_ADC_NUM_MASK           0x1000000u
#define EQADC_RFXR_RFIFOX_ADC_NUM_SHIFT          24u
#define EQADC_RFXR_RFIFOX_ADC_NUM_WIDTH          1u
#define EQADC_RFXR_RFIFOX_ADC_NUM(x)             (((uint32_t)(((uint32_t)(x))<<EQADC_RFXR_RFIFOX_ADC_NUM_SHIFT))&EQADC_RFXR_RFIFOX_ADC_NUM_MASK)
/* DLY(CFTDR) Bit Fields */
#define EQADC_DLY_CFIFO_TRIG_DELAY_EN_MASK       0x80000000u
#define EQADC_DLY_CFIFO_TRIG_DELAY_EN_SHIFT      31u
#define EQADC_DLY_CFIFO_TRIG_DELAY_EN_WIDTH      1u
#define EQADC_DLY_CFIFO_TRIG_DELAY_EN(x)         (((uint32_t)(((uint32_t)(x))<<EQADC_DLY_CFIFO_TRIG_DELAY_EN_SHIFT))&EQADC_DLY_CFIFO_TRIG_DELAY_EN_MASK)
#define EQADC_DLY_CFIFO_TRIG_DELAY_VAL_MASK      0xFFFFFu
#define EQADC_DLY_CFIFO_TRIG_DELAY_VAL_SHIFT     0u
#define EQADC_DLY_CFIFO_TRIG_DELAY_VAL_WIDTH     20u
#define EQADC_DLY_CFIFO_TRIG_DELAY_VAL(x)        (((uint32_t)(((uint32_t)(x))<<EQADC_DLY_CFIFO_TRIG_DELAY_VAL_SHIFT))&EQADC_DLY_CFIFO_TRIG_DELAY_VAL_MASK)
/* RFSRR Bit Fields */
#define EQADC_RFSRR_RF_SW0_MASK                  0x1u
#define EQADC_RFSRR_RF_SW0_SHIFT                 0u
#define EQADC_RFSRR_RF_SW0_WIDTH                 1u
#define EQADC_RFSRR_RF_SW0(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_RFSRR_RF_SW0_SHIFT))&EQADC_RFSRR_RF_SW0_MASK)
#define EQADC_RFSRR_RF_SW1_MASK                  0x2u
#define EQADC_RFSRR_RF_SW1_SHIFT                 1u
#define EQADC_RFSRR_RF_SW1_WIDTH                 1u
#define EQADC_RFSRR_RF_SW1(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_RFSRR_RF_SW1_SHIFT))&EQADC_RFSRR_RF_SW1_MASK)
#define EQADC_RFSRR_RF_SW2_MASK                  0x4u
#define EQADC_RFSRR_RF_SW2_SHIFT                 2u
#define EQADC_RFSRR_RF_SW2_WIDTH                 1u
#define EQADC_RFSRR_RF_SW2(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_RFSRR_RF_SW2_SHIFT))&EQADC_RFSRR_RF_SW2_MASK)
#define EQADC_RFSRR_RF_SW3_MASK                  0x8u
#define EQADC_RFSRR_RF_SW3_SHIFT                 3u
#define EQADC_RFSRR_RF_SW3_WIDTH                 1u
#define EQADC_RFSRR_RF_SW3(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_RFSRR_RF_SW3_SHIFT))&EQADC_RFSRR_RF_SW3_MASK)
#define EQADC_RFSRR_RF_SW4_MASK                  0x10u
#define EQADC_RFSRR_RF_SW4_SHIFT                 4u
#define EQADC_RFSRR_RF_SW4_WIDTH                 1u
#define EQADC_RFSRR_RF_SW4(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_RFSRR_RF_SW4_SHIFT))&EQADC_RFSRR_RF_SW4_MASK)
#define EQADC_RFSRR_RF_SW5_MASK                  0x20u
#define EQADC_RFSRR_RF_SW5_SHIFT                 5u
#define EQADC_RFSRR_RF_SW5_WIDTH                 1u
#define EQADC_RFSRR_RF_SW5(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_RFSRR_RF_SW5_SHIFT))&EQADC_RFSRR_RF_SW5_MASK)
#define EQADC_RFSRR_RF_SW6_MASK                  0x40u
#define EQADC_RFSRR_RF_SW6_SHIFT                 6u
#define EQADC_RFSRR_RF_SW6_WIDTH                 1u
#define EQADC_RFSRR_RF_SW6(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_RFSRR_RF_SW6_SHIFT))&EQADC_RFSRR_RF_SW6_MASK)
#define EQADC_RFSRR_RF_SW7_MASK                  0x80u
#define EQADC_RFSRR_RF_SW7_SHIFT                 7u
#define EQADC_RFSRR_RF_SW7_WIDTH                 1u
#define EQADC_RFSRR_RF_SW7(x)                    (((uint32_t)(((uint32_t)(x))<<EQADC_RFSRR_RF_SW7_SHIFT))&EQADC_RFSRR_RF_SW7_MASK)
/* DMA_SEL Bit Fields */
#define EQADC_DMA_SEL_CF0_DMA_SEL_MASK             0x1u
#define EQADC_DMA_SEL_CF0_DMA_SEL_SHIFT            0u
#define EQADC_DMA_SEL_CF0_DMA_SEL_WIDTH            1u
#define EQADC_DMA_SEL_CF0_DMA_SEL(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_DMA_SEL_CF0_DMA_SEL_SHIFT))&EQADC_DMA_SEL_CF0_DMA_SEL_MASK)
#define EQADC_DMA_SEL_CF1_DMA_SEL_MASK             0x2u
#define EQADC_DMA_SEL_CF1_DMA_SEL_SHIFT            1u
#define EQADC_DMA_SEL_CF1_DMA_SEL_WIDTH            1u
#define EQADC_DMA_SEL_CF1_DMA_SEL(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_DMA_SEL_CF1_DMA_SEL_SHIFT))&EQADC_DMA_SEL_CF1_DMA_SEL_MASK)
#define EQADC_DMA_SEL_CF2_DMA_SEL_MASK             0x4u
#define EQADC_DMA_SEL_CF2_DMA_SEL_SHIFT            2u
#define EQADC_DMA_SEL_CF2_DMA_SEL_WIDTH            1u
#define EQADC_DMA_SEL_CF2_DMA_SEL(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_DMA_SEL_CF2_DMA_SEL_SHIFT))&EQADC_DMA_SEL_CF2_DMA_SEL_MASK)
#define EQADC_DMA_SEL_CF3_DMA_SEL_MASK             0x8u
#define EQADC_DMA_SEL_CF3_DMA_SEL_SHIFT            3u
#define EQADC_DMA_SEL_CF3_DMA_SEL_WIDTH            1u
#define EQADC_DMA_SEL_CF3_DMA_SEL(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_DMA_SEL_CF3_DMA_SEL_SHIFT))&EQADC_DMA_SEL_CF3_DMA_SEL_MASK)
#define EQADC_DMA_SEL_CF4_DMA_SEL_MASK             0x10u
#define EQADC_DMA_SEL_CF4_DMA_SEL_SHIFT            4u
#define EQADC_DMA_SEL_CF4_DMA_SEL_WIDTH            1u
#define EQADC_DMA_SEL_CF4_DMA_SEL(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_DMA_SEL_CF4_DMA_SEL_SHIFT))&EQADC_DMA_SEL_CF4_DMA_SEL_MASK)
#define EQADC_DMA_SEL_CF5_DMA_SEL_MASK             0x20u
#define EQADC_DMA_SEL_CF5_DMA_SEL_SHIFT            5u
#define EQADC_DMA_SEL_CF5_DMA_SEL_WIDTH            1u
#define EQADC_DMA_SEL_CF5_DMA_SEL(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_DMA_SEL_CF5_DMA_SEL_SHIFT))&EQADC_DMA_SEL_CF5_DMA_SEL_MASK)
#define EQADC_DMA_SEL_CF6_DMA_SEL_MASK             0x40u
#define EQADC_DMA_SEL_CF6_DMA_SEL_SHIFT            6u
#define EQADC_DMA_SEL_CF6_DMA_SEL_WIDTH            1u
#define EQADC_DMA_SEL_CF6_DMA_SEL(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_DMA_SEL_CF6_DMA_SEL_SHIFT))&EQADC_DMA_SEL_CF6_DMA_SEL_MASK)
#define EQADC_DMA_SEL_CF7_DMA_SEL_MASK             0x80u
#define EQADC_DMA_SEL_CF7_DMA_SEL_SHIFT            7u
#define EQADC_DMA_SEL_CF7_DMA_SEL_WIDTH            1u
#define EQADC_DMA_SEL_CF7_DMA_SEL(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_DMA_SEL_CF7_DMA_SEL_SHIFT))&EQADC_DMA_SEL_CF7_DMA_SEL_MASK)
#define EQADC_DMA_SEL_RF0_DMA_SEL_MASK             0x100u
#define EQADC_DMA_SEL_RF0_DMA_SEL_SHIFT            8u
#define EQADC_DMA_SEL_RF0_DMA_SEL_WIDTH            1u
#define EQADC_DMA_SEL_RF0_DMA_SEL(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_DMA_SEL_RF0_DMA_SEL_SHIFT))&EQADC_DMA_SEL_RF0_DMA_SEL_MASK)
#define EQADC_DMA_SEL_RF1_DMA_SEL_MASK             0x200u
#define EQADC_DMA_SEL_RF1_DMA_SEL_SHIFT            9u
#define EQADC_DMA_SEL_RF1_DMA_SEL_WIDTH            1u
#define EQADC_DMA_SEL_RF1_DMA_SEL(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_DMA_SEL_RF1_DMA_SEL_SHIFT))&EQADC_DMA_SEL_RF1_DMA_SEL_MASK)
#define EQADC_DMA_SEL_RF2_DMA_SEL_MASK             0x400u
#define EQADC_DMA_SEL_RF2_DMA_SEL_SHIFT            10u
#define EQADC_DMA_SEL_RF2_DMA_SEL_WIDTH            1u
#define EQADC_DMA_SEL_RF2_DMA_SEL(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_DMA_SEL_RF2_DMA_SEL_SHIFT))&EQADC_DMA_SEL_RF2_DMA_SEL_MASK)
#define EQADC_DMA_SEL_RF3_DMA_SEL_MASK             0x800u
#define EQADC_DMA_SEL_RF3_DMA_SEL_SHIFT            11u
#define EQADC_DMA_SEL_RF3_DMA_SEL_WIDTH            1u
#define EQADC_DMA_SEL_RF3_DMA_SEL(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_DMA_SEL_RF3_DMA_SEL_SHIFT))&EQADC_DMA_SEL_RF3_DMA_SEL_MASK)
#define EQADC_DMA_SEL_RF4_DMA_SEL_MASK             0x1000u
#define EQADC_DMA_SEL_RF4_DMA_SEL_SHIFT            12u
#define EQADC_DMA_SEL_RF4_DMA_SEL_WIDTH            1u
#define EQADC_DMA_SEL_RF4_DMA_SEL(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_DMA_SEL_RF4_DMA_SEL_SHIFT))&EQADC_DMA_SEL_RF4_DMA_SEL_MASK)
#define EQADC_DMA_SEL_RF5_DMA_SEL_MASK             0x2000u
#define EQADC_DMA_SEL_RF5_DMA_SEL_SHIFT            13u
#define EQADC_DMA_SEL_RF5_DMA_SEL_WIDTH            1u
#define EQADC_DMA_SEL_RF5_DMA_SEL(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_DMA_SEL_RF5_DMA_SEL_SHIFT))&EQADC_DMA_SEL_RF5_DMA_SEL_MASK)
#define EQADC_DMA_SEL_RF6_DMA_SEL_MASK             0x4000u
#define EQADC_DMA_SEL_RF6_DMA_SEL_SHIFT            14u
#define EQADC_DMA_SEL_RF6_DMA_SEL_WIDTH            1u
#define EQADC_DMA_SEL_RF6_DMA_SEL(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_DMA_SEL_RF6_DMA_SEL_SHIFT))&EQADC_DMA_SEL_RF6_DMA_SEL_MASK)
#define EQADC_DMA_SEL_RF7_DMA_SEL_MASK             0x8000u
#define EQADC_DMA_SEL_RF7_DMA_SEL_SHIFT            15u
#define EQADC_DMA_SEL_RF7_DMA_SEL_WIDTH            1u
#define EQADC_DMA_SEL_RF7_DMA_SEL(x)               (((uint32_t)(((uint32_t)(x))<<EQADC_DMA_SEL_RF7_DMA_SEL_SHIFT))&EQADC_DMA_SEL_RF7_DMA_SEL_MASK)

/*******************************************************************************
 * EQADC On-Chip ADC Register Bit Fields
 *******************************************************************************/
/*! ADC CR Bit Fields */
#define EQADC_ADC_CR_CLK_PS_MASK                 0x1Fu
#define EQADC_ADC_CR_CLK_PS_SHIFT                0u
#define EQADC_ADC_CR_CLK_PS_WIDTH                5u
#define EQADC_ADC_CR_CLK_PS(x)                   ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_CR_CLK_PS_SHIFT))&EQADC_ADC_CR_CLK_PS_MASK))
#ifdef EQADC_ADC_CR_CLK_SEL_EN
#define EQADC_ADC_CR_CLK_SEL_MASK                0x20u
#define EQADC_ADC_CR_CLK_SEL_SHIFT               5u
#define EQADC_ADC_CR_CLK_SEL_WIDTH               1u
#define EQADC_ADC_CR_CLK_SEL(x)                  ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_CR_CLK_SEL_SHIFT))&EQADC_ADC_CR_CLK_SEL_MASK))
#endif  /* EQADC_ADC_CR_CLK_SEL_EN */
#ifdef EQADC_ADC_CR_CLK_DTY_EN
#define EQADC_ADC_CR_CLK_DTY_MASK                0x40u
#define EQADC_ADC_CR_CLK_DTY_SHIFT               6u
#define EQADC_ADC_CR_CLK_DTY_WIDTH               1u
#define EQADC_ADC_CR_CLK_DTY(x)                  ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_CR_CLK_DTY_SHIFT))&EQADC_ADC_CR_CLK_DTY_MASK))
#endif  /* EQADC_ADC_CR_CLK_DTY_EN */
#ifdef EQADC_ADC_CR_ODD_PS_EN
#define EQADC_ADC_CR_ODD_PS_MASK                 0x80u
#define EQADC_ADC_CR_ODD_PS_SHIFT                7u
#define EQADC_ADC_CR_ODD_PS_WIDTH                1u
#define EQADC_ADC_CR_ODD_PS(x)                   ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_CR_ODD_PS_SHIFT))&EQADC_ADC_CR_ODD_PS_MASK))
#else
#define EQADC_ADC_CR_SHIFT_MASK                  0x80u
#endif  /* EQADC_ADC_CR_ODD_PS_EN */
#define EQADC_ADC_CR_TBSEL_MASK                  0x300u
#define EQADC_ADC_CR_TBSEL_SHIFT                 8u
#define EQADC_ADC_CR_TBSEL_WIDTH                 2u
#define EQADC_ADC_CR_TBSEL(x)                    ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_CR_TBSEL_SHIFT))&EQADC_ADC_CR_TBSEL_MASK))
#define EQADC_ADC_CR_EMUX_MASK                   0x800u
#define EQADC_ADC_CR_EMUX_SHIFT                  11u
#define EQADC_ADC_CR_EMUX_WIDTH                  1u
#define EQADC_ADC_CR_EMUX(x)                     ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_CR_EMUX_SHIFT))&EQADC_ADC_CR_EMUX_MASK))
#define EQADC_ADC_CR_PRC_SEL_MASK                0x7000u
#define EQADC_ADC_CR_PRC_SEL_SHIFT               12u
#define EQADC_ADC_CR_PRC_SEL_WIDTH               3u
#define EQADC_ADC_CR_PRC_SEL(x)                  ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_CR_PRC_SEL_SHIFT))&EQADC_ADC_CR_PRC_SEL_MASK))
#define EQADC_ADC_CR_EN_MASK                     0x8000u
#define EQADC_ADC_CR_EN_SHIFT                    15u
#define EQADC_ADC_CR_EN_WIDTH                    1u
#define EQADC_ADC_CR_EN(x)                       ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_CR_EN_SHIFT))&EQADC_ADC_CR_EN_MASK))
/*! ADC TSCR Bit Fields */
#define EQADC_ADC_TSCR_TBC_CLK_PS_MASK           0xFu
#define EQADC_ADC_TSCR_TBC_CLK_PS_SHIFT          0u
#define EQADC_ADC_TSCR_TBC_CLK_PS_WIDTH          4u
#define EQADC_ADC_TSCR_TBC_CLK_PS(x)             ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_TSCR_TBC_CLK_PS_SHIFT))&EQADC_ADC_TSCR_TBC_CLK_PS_MASK))
/*! ADC TBCR Bit Fields */
#define EQADC_ADC_TBCR_TBC_VALUE_MASK            0xFFFFu
#define EQADC_ADC_TBCR_TBC_VALUE_SHIFT           0u
#define EQADC_ADC_TBCR_TBC_VALUE_WIDTH           16u
#define EQADC_ADC_TBCR_TBC_VALUE(x)              ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_TBCR_TBC_VALUE_SHIFT))&EQADC_ADC_TBCR_TBC_VALUE_MASK))
/*! ADC GCCR Bit Fields */
#define EQADC_ADC_GCCR_GCC_MASK                  0x7FFFu
#define EQADC_ADC_GCCR_GCC_SHIFT                 0u
#define EQADC_ADC_GCCR_GCC_WIDTH                 15u
#define EQADC_ADC_GCCR_GCC(x)                    ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_GCCR_GCC_SHIFT))&EQADC_ADC_GCCR_GCC_MASK))
/*! ADC OCCR Bit Fields */
#define EQADC_ADC_OCCR_OCC_MASK                  0x3FFFu
#define EQADC_ADC_OCCR_OCC_SHIFT                 0u
#define EQADC_ADC_OCCR_OCC_WIDTH                 14u
#define EQADC_ADC_OCCR_OCC(x)                    ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_OCCR_OCC_SHIFT))&EQADC_ADC_OCCR_OCC_MASK))
/*! ADC ACR Bit Fields */
#ifdef EQADC_ADC_ACR_PRE_GAIN_EN
#define EQADC_ADC_ACR_PRE_GAIN_MASK              0x3u
#define EQADC_ADC_ACR_PRE_GAIN_SHIFT             0u
#define EQADC_ADC_ACR_PRE_GAIN_WIDTH             2u
#define EQADC_ADC_ACR_PRE_GAIN(x)                ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_ACR_PRE_GAIN_SHIFT))&EQADC_ADC_ACR_PRE_GAIN_MASK))
#endif  /* EQADC_ADC_ACR_PRE_GAIN_EN */
#ifdef EQADC_ADC_ACR_ATBSEL_EN
#define EQADC_ADC_ACR_ATBSEL_MASK                0xCu
#define EQADC_ADC_ACR_ATBSEL_SHIFT               2u
#define EQADC_ADC_ACR_ATBSEL_WIDTH               2u
#define EQADC_ADC_ACR_ATBSEL(x)                  ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_ACR_ATBSEL_SHIFT))&EQADC_ADC_ACR_ATBSEL_MASK))
#endif  /* EQADC_ADC_ACR_ATBSEL_EN */
#define EQADC_ADC_ACR_RESSEL_MASK                0xC0u
#define EQADC_ADC_ACR_RESSEL_SHIFT               6u
#define EQADC_ADC_ACR_RESSEL_WIDTH               2u
#define EQADC_ADC_ACR_RESSEL(x)                  ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_ACR_RESSEL_SHIFT))&EQADC_ADC_ACR_RESSEL_MASK))
#ifdef EQADC_ADC_ACR_RPSI_EN
#define EQADC_ADC_ACR_RPSI_MASK                  0x100u
#define EQADC_ADC_ACR_RPSI_SHIFT                 8u
#define EQADC_ADC_ACR_RPSI_WIDTH                 1u
#define EQADC_ADC_ACR_RPSI(x)                    ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_ACR_RPSI_SHIFT))&EQADC_ADC_ACR_RPSI_MASK))
#endif  /* EQADC_ADC_ACR_RPSI_EN */
#define EQADC_ADC_ACR_FMTA_MASK                  0x200u
#define EQADC_ADC_ACR_FMTA_SHIFT                 9u
#define EQADC_ADC_ACR_FMTA_WIDTH                 1u
#define EQADC_ADC_ACR_FMTA(x)                    ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_ACR_FMTA_SHIFT))&EQADC_ADC_ACR_FMTA_MASK))
#define EQADC_ADC_ACR_DEST_MASK                  0x3C00u
#define EQADC_ADC_ACR_DEST_SHIFT                 10u
#define EQADC_ADC_ACR_DEST_WIDTH                 4u
#define EQADC_ADC_ACR_DEST(x)                    ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_ACR_DEST_SHIFT))&EQADC_ADC_ACR_DEST_MASK))
#define EQADC_ADC_ACR_RET_INH_MASK               0x8000u
#define EQADC_ADC_ACR_RET_INH_SHIFT              15u
#define EQADC_ADC_ACR_RET_INH_WIDTH              1u
#define EQADC_ADC_ACR_RET_INH(x)                 ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_ACR_RET_INH_SHIFT))&EQADC_ADC_ACR_RET_INH_MASK))
/*! ADC AGR Bit Fields */
#define EQADC_ADC_AGR_ALTGCC_MASK                0x7FFFu
#define EQADC_ADC_AGR_ALTGCC_SHIFT               0u
#define EQADC_ADC_AGR_ALTGCC_WIDTH               15u
#define EQADC_ADC_AGR_ALTGCC(x)                  ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_AGR_ALTGCC_SHIFT))&EQADC_ADC_AGR_ALTGCC_MASK))
/*! ADC AOR Bit Fields */
#define EQADC_ADC_AOR_ALTOCC_MASK                0x3FFFu
#define EQADC_ADC_AOR_ALTOCC_SHIFT               0u
#define EQADC_ADC_AOR_ALTOCC_WIDTH               14u
#define EQADC_ADC_AOR_ALTOCC(x)                  ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_AOR_ALTOCC_SHIFT))&EQADC_ADC_AOR_ALTOCC_MASK))
#ifdef EQADC_ADC_EACR_EN
/*! ADC EACR Bit Fields */
#define EQADC_ADC_EACR_MESSAGE_TAG2_MASK         0xFu
#define EQADC_ADC_EACR_MESSAGE_TAG2_SHIFT        0u
#define EQADC_ADC_EACR_MESSAGE_TAG2_WIDTH        4u
#define EQADC_ADC_EACR_MESSAGE_TAG2(x)           ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_EACR_MESSAGE_TAG2_SHIFT))&EQADC_ADC_EACR_MESSAGE_TAG2_MASK))
#define EQADC_ADC_EACR_TEN2_MASK                 0x10u
#define EQADC_ADC_EACR_TEN2_SHIFT                4u
#define EQADC_ADC_EACR_TEN2_WIDTH                1u
#define EQADC_ADC_EACR_TEN2(x)                   ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_EACR_TEN2_SHIFT))&EQADC_ADC_EACR_TEN2_MASK))
#define EQADC_ADC_EACR_FLEN2_MASK                0x80u
#define EQADC_ADC_EACR_FLEN2_SHIFT               7u
#define EQADC_ADC_EACR_FLEN2_WIDTH               1u
#define EQADC_ADC_EACR_FLEN2(x)                  ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_EACR_FLEN2_SHIFT))&EQADC_ADC_EACR_FLEN2_MASK))
#define EQADC_ADC_EACR_RPSI2_MASK                0x100u
#define EQADC_ADC_EACR_RPSI2_SHIFT               8u
#define EQADC_ADC_EACR_RPSI2_WIDTH               1u
#define EQADC_ADC_EACR_RPSI2(x)                  ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_EACR_RPSI2_SHIFT))&EQADC_ADC_EACR_RPSI2_MASK))
#define EQADC_ADC_EACR_FMTA2_MASK                0x200u
#define EQADC_ADC_EACR_FMTA2_SHIFT               9u
#define EQADC_ADC_EACR_FMTA2_WIDTH               1u
#define EQADC_ADC_EACR_FMTA2(x)                  ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_EACR_FMTA2_SHIFT))&EQADC_ADC_EACR_FMTA2_MASK))
#define EQADC_ADC_EACR_DEST2_MASK                0x3C00u
#define EQADC_ADC_EACR_DEST2_SHIFT               10u
#define EQADC_ADC_EACR_DEST2_WIDTH               4u
#define EQADC_ADC_EACR_DEST2(x)                  ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_EACR_DEST2_SHIFT))&EQADC_ADC_EACR_DEST2_MASK))
#define EQADC_ADC_EACR_RET_INH2_MASK             0x8000u
#define EQADC_ADC_EACR_RET_INH2_SHIFT            15u
#define EQADC_ADC_EACR_RET_INH2_WIDTH            1u
#define EQADC_ADC_EACR_RET_INH2(x)               ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_EACR_RET_INH2_SHIFT))&EQADC_ADC_EACR_RET_INH2_MASK))
#endif  /* EQADC_ADC_EACR_EN */
#ifdef EQADC_ADC_PUDCR_EN
/*! ADC PUDCR Bit Fields */
#define EQADC_ADC_PUDCR_PULL_STR_MASK            0x300u
#define EQADC_ADC_PUDCR_PULL_STR_SHIFT           8u
#define EQADC_ADC_PUDCR_PULL_STR_WIDTH           2u
#define EQADC_ADC_PUDCR_PULL_STR(x)              ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_PUDCR_PULL_STR_SHIFT))&EQADC_ADC_PUDCR_PULL_STR_MASK))
#define EQADC_ADC_PUDCR_CH_PULL_MASK             0x3000u
#define EQADC_ADC_PUDCR_CH_PULL_SHIFT            12u
#define EQADC_ADC_PUDCR_CH_PULL_WIDTH            2u
#define EQADC_ADC_PUDCR_CH_PULL(x)               ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_PUDCR_CH_PULL_SHIFT))&EQADC_ADC_PUDCR_CH_PULL_MASK))
#endif  /* EQADC_ADC_PUDCR_EN */
#ifdef EQADC_ADC_STACTBR_TB_VALUE_EN
/*! ADC STACTBR Bit Fields */
#define EQADC_ADC_STACTBR_TB_VALUE_MASK          0xFFFFu
#define EQADC_ADC_STACTBR_TB_VALUE_SHIFT         0u
#define EQADC_ADC_STACTBR_TB_VALUE_WIDTH         16u
#define EQADC_ADC_STACTBR_TB_VALUE(x)            ((uint16_t)(((uint16_t)(((uint16_t)(x))<<EQADC_ADC_STACTBR_TB_VALUE_SHIFT))&EQADC_ADC_STACTBR_TB_VALUE_MASK))
#endif  /* EQADC_ADC_STACTBR_TB_VALUE_EN */

/*******************************************************************************
 *******************************************************************************/
/* @brief EQADC FIFO interrupt & DMA select */
#define EQADC_IRQDMA_REQ_SEL_CFIFOFILL    (EQADC_IDCR0_CFFS1_MASK)
#define EQADC_IRQDMA_REQ_SEL_RFIFODRAIN   (EQADC_IDCR0_RFDS1_MASK)

/* @brief EQADC FIFO interrupt & DMA source */
#define EQADC_IRQ_EN_NON_COHERENCY          (EQADC_IDCR0_NCIE1_MASK)   /* Non-Coherency Interrupt Enable */
#define EQADC_IRQ_EN_TRIGGER_OVERRUN        (EQADC_IDCR0_TORIE1_MASK)  /* Trigger Overrun Interrupt Enable */
#define EQADC_IRQ_EN_PAUSE                  (EQADC_IDCR0_PIE1_MASK)    /* Pause Interrupt Enable */
#define EQADC_IRQ_EN_END_OF_QUEUE           (EQADC_IDCR0_EOQIE1_MASK)  /* End of Queue Interrupt Enable */
#define EQADC_IRQ_EN_CFIFO_UNDERFLOW        (EQADC_IDCR0_CFUIE1_MASK)  /* CFIFO Underflow Interrupt Enable */
#define EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL     (EQADC_IDCR0_CFFE1_MASK)   /* CFIFO Fill Enable */
#define EQADC_IRQ_EN_RFIFO_OVERFLOW         (EQADC_IDCR0_RFOIE1_MASK)  /* RFIFO Overflow Interrupt Enable */
#define EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN    (EQADC_IDCR0_RFDE1_MASK)   /* RFIFO Drain Enable */
#define EQADC_IRQ_EN_GRP_ALL                (EQADC_IRQ_EN_NON_COHERENCY | \
                                             EQADC_IRQ_EN_PAUSE | \
                                             EQADC_IRQ_EN_END_OF_QUEUE | \
                                             EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL | \
                                             EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN)  /* No TORIE/CFUIE/RFOIE, for GTM module use */
#define EQADC_IRQ_EN_ALL                    (EQADC_IRQ_EN_NON_COHERENCY | \
                                             EQADC_IRQ_EN_TRIGGER_OVERRUN | \
                                             EQADC_IRQ_EN_PAUSE | \
                                             EQADC_IRQ_EN_END_OF_QUEUE | \
                                             EQADC_IRQ_EN_CFIFO_UNDERFLOW | \
                                             EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL | \
                                             EQADC_IRQ_EN_RFIFO_OVERFLOW | \
                                             EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN)
#define EQADC_DMA_EN_ALL                    (EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL | \
                                             EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN)

/* @brief EQADC FIFO status flags */
#define EQADC_FIFO_FLAG_NON_COHERENCY       (EQADC_FISR_NCFX_MASK)
#define EQADC_FIFO_FLAG_TRIG_OVERRUN        (EQADC_FISR_TORFX_MASK)
#define EQADC_FIFO_FLAG_PAUSE               (EQADC_FISR_PFX_MASK)
#define EQADC_FIFO_FLAG_END_OF_QUEUE        (EQADC_FISR_EOQFX_MASK)
#define EQADC_FIFO_FLAG_CFIFO_UNDERFLOW     (EQADC_FISR_CFUFX_MASK)
#define EQADC_FIFO_FLAG_CFIFO_FILL          (EQADC_FISR_CFFFX_MASK)
#define EQADC_FIFO_FLAG_RFIFO_OVERFLOW      (EQADC_FISR_RFOFX_MASK)
#define EQADC_FIFO_FLAG_RFIFO_DRAIN         (EQADC_FISR_RFDFX_MASK)
#define EQADC_FIFO_FLAG_ALL                 (EQADC_FIFO_FLAG_NON_COHERENCY | \
                                             EQADC_FIFO_FLAG_TRIG_OVERRUN | \
                                             EQADC_FIFO_FLAG_PAUSE | \
                                             EQADC_FIFO_FLAG_END_OF_QUEUE | \
                                             EQADC_FIFO_FLAG_CFIFO_UNDERFLOW | \
                                             EQADC_FIFO_FLAG_CFIFO_FILL | \
                                             EQADC_FIFO_FLAG_RFIFO_OVERFLOW | \
                                             EQADC_FIFO_FLAG_RFIFO_DRAIN)

#endif  /* EQADC_REG_H_ */
