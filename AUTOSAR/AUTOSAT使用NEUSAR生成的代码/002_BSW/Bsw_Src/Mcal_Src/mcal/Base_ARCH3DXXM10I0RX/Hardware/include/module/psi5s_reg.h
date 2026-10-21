#ifndef PSI5S_REG_H_
#define PSI5S_REG_H_

/* ============================================================================
   =============================== Module: PSI5S ==============================
   ============================================================================ */

typedef union PSI5S_LINCR1_union_tag { /* PSI5-S LIN Control Register 1 */
  vuint32_t R;
  struct {
    vuint32_t  :19;
    vuint32_t AUTOWU:1;
    vuint32_t  :4;
    vuint32_t  :1;
    vuint32_t SLFM:1;
    vuint32_t LBKM:1;
    vuint32_t  :1;
    vuint32_t  :1;
    vuint32_t RBLM:1;
    vuint32_t SLEEP:1;
    vuint32_t INIT:1;
  } B;
} PSI5S_LINCR1_tag;

typedef union PSI5S_LINIER_union_tag { /* PSI5-S LIN Interrupt enable register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t SZIE:1;
    vuint32_t OCIE:1;
    vuint32_t  :5;
    vuint32_t FEIE:1;
    vuint32_t BOIE:1;
    vuint32_t  :1;
    vuint32_t WUIE:1;
    vuint32_t  :1;
    vuint32_t TOIE:1;
    vuint32_t DRIE:1;
    vuint32_t DTIE:1;
    vuint32_t  :1;
  } B;
} PSI5S_LINIER_tag;

typedef union PSI5S_LINSR_union_tag {  /* PSI5-S LIN Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t LINS3:1;
    vuint32_t LINS2:1;
    vuint32_t LINS1:1;
    vuint32_t LINS0:1;
    vuint32_t  :5;
    vuint32_t  :1;
    vuint32_t  :6;
  } B;
} PSI5S_LINSR_tag;

typedef union PSI5S_UARTCR_union_tag { /* PSI5-S UART Mode Control Register */
  vuint32_t R;
  struct {
    vuint32_t MIS:1;
    vuint32_t CSP:3;
    vuint32_t OSR:4;
    vuint32_t ROSE:1;
    vuint32_t NEF:3;
    vuint32_t PCE_TXDTU:1;
    vuint32_t SBUR:2;
    vuint32_t WLS:1;
    vuint32_t TDFLTFC:3;
    vuint32_t RDFLRFC:3;
    vuint32_t RFBM:1;
    vuint32_t TFBM:1;
    vuint32_t WL1:1;
    vuint32_t PC_1:1;
    vuint32_t RxEn:1;
    vuint32_t TxEn:1;
    vuint32_t PC_0:1;
    vuint32_t PCE_Rx:1;
    vuint32_t WL0:1;
    vuint32_t UART:1;
  } B;
} PSI5S_UARTCR_tag;

typedef union PSI5S_UARTSR_union_tag { /* PSI5-S UART Mode Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t SZF:1;
    vuint32_t OCF:1;
    vuint32_t PE3:1;
    vuint32_t PE2:1;
    vuint32_t PE1:1;
    vuint32_t PE0:1;
    vuint32_t RMB:1;
    vuint32_t FEF:1;
    vuint32_t BOF:1;
    vuint32_t RDI:1;
    vuint32_t WUF:1;
    vuint32_t RFNE:1;
    vuint32_t TO:1;
    vuint32_t DRF:1;
    vuint32_t DTF:1;
    vuint32_t NF:1;
  } B;
} PSI5S_UARTSR_tag;

typedef union PSI5S_LINFBRR_union_tag { /* PSI5-S LIN Fractional Baud Rate Register */
  vuint32_t R;
  struct {
    vuint32_t  :28;
    vuint32_t FBR:4;
  } B;
} PSI5S_LINFBRR_tag;

typedef union PSI5S_LINIBRR_union_tag { /* PSI5-S LIN Integer Baud Rate Register */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t IBR:20;
  } B;
} PSI5S_LINIBRR_tag;

typedef union PSI5S_LINCR2_union_tag { /* PSI5-S LIN Control Register 2 */
  vuint32_t R;
  struct {
    vuint32_t  :17;
    vuint32_t  :1;
    vuint32_t  :4;
    vuint32_t ABRQ:1;
    vuint32_t  :9;
  } B;
} PSI5S_LINCR2_tag;

typedef union PSI5S_BDRL_union_tag {   /* PSI5-S Buffer Data Register Least Significant */
  vuint32_t R;
  struct {
    vuint32_t DATA_TX3:8;
    vuint32_t DATA_TX2:8;
    vuint32_t DATA_TX1:8;
    vuint32_t DATA_TX0:8;
  } B;
} PSI5S_BDRL_tag;

typedef union PSI5S_BDRM_union_tag {   /* PSI5-S Buffer Data Register Most Significant */
  vuint32_t R;
  struct {
    vuint32_t DATA_RX3:8;
    vuint32_t DATA_RX2:8;
    vuint32_t DATA_RX1:8;
    vuint32_t DATA_RX0:8;
  } B;
} PSI5S_BDRM_tag;

typedef union PSI5S_GCR_union_tag {    /* PSI5-S Global Control register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t TDFBM:1;
    vuint32_t RDFBM:1;
    vuint32_t TDLIS:1;
    vuint32_t RDLIS:1;
    vuint32_t STOP:1;
    vuint32_t SR:1;
  } B;
} PSI5S_GCR_tag;

typedef union PSI5S_UARTPTO_union_tag { /* PSI5-S UART Preset Timeout Register */
  vuint32_t R;
  struct {
    vuint32_t  :20;
    vuint32_t PTO:12;
  } B;
} PSI5S_UARTPTO_tag;

typedef union PSI5S_UARTCTO_union_tag { /* UPSI5-S ART Current Timeout register */
  vuint32_t R;
  struct {
    vuint32_t  :20;
    vuint32_t CTO:12;
  } B;
} PSI5S_UARTCTO_tag;

typedef union PSI5S_DMATXE_union_tag { /* DMA Tx Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t DTE0:1;
  } B;
} PSI5S_DMATXE_tag;

typedef union PSI5S_DMARXE_union_tag { /* DMA Rx Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t DRE0:1;
  } B;
} PSI5S_DMARXE_tag;

typedef union PSI5S_PTD_union_tag {    /* PSI5-S UART Tx Idle Delay Time Register */
  vuint32_t R;
  struct {
    vuint32_t  :27;
    vuint32_t IFD:4;
    vuint32_t EN:1;
  } B;
} PSI5S_PTD_tag;

typedef union PSI5S_GLCR_union_tag {   /* PSI5-S Global Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t DIRCMD_LEN:2;
    vuint32_t  :1;
    vuint32_t IE_DIRCMD_RDY:1;
    vuint32_t  :1;
    vuint32_t DEBUG_EN:1;
    vuint32_t GTM_TRIG_SEL:2;
    vuint32_t GL_DDSR_TRIG:1;
    vuint32_t GL_MODETR_DONE_EN:1;
    vuint32_t MRU_ERR_EN:1;
    vuint32_t TSCS_B:1;
    vuint32_t TSCS_A:1;
    vuint32_t CLR_CNTR_B:1;
    vuint32_t CLR_CNTR_A:1;
    vuint32_t CLRTSCNT_G:1;
    vuint32_t CLRTSCNT_G_L:1;
    vuint32_t TSCNT_EN_B:1;
    vuint32_t TSCNT_EN_A:1;
    vuint32_t TSCNTEN_G:1;
    vuint32_t TSCNTEN_G_L:1;
    vuint32_t GLOBAL_MODE:3;
  } B;
} PSI5S_GLCR_tag;

typedef union PSI5S_GLSR_union_tag {   /* PSI5-S Global Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :11;
    vuint32_t DIRCMD_RDY:1;
    vuint32_t  :5;
    vuint32_t GL_MODETR_DONE:1;
    vuint32_t MRU_ERR:1;
    vuint32_t  :7;
    vuint32_t FID:3;
    vuint32_t CHID:3;
  } B;
} PSI5S_GLSR_tag;

typedef union PSI5S_CH_BASE_ADDR_union_tag { /* PSI5-S CHANNEL_BASE_ADDRESS */
  vuint32_t R;
  struct {
    vuint32_t MAILBOX_BASE_ADDR:32;
  } B;
} PSI5S_CH_BASE_ADDR_tag;

typedef union PSI5S_MRU_BUF2_REG0_union_tag { /* PSI5-S MRU OUTPUT BUFFER2 REGISTER0 */
  vuint32_t R;
  struct {
    vuint32_t CHANNEL_SPECIFIC_MAILBOX_ADDR:32;
  } B;
} PSI5S_MRU_BUF2_REG0_tag;

typedef union PSI5S_MRU_BUF2_REG1_union_tag { /* PSI5-S MRU OUTPUT BUFFER2 REGISTER1 */
  vuint32_t R;
  struct {
    vuint32_t DCI:4;
    vuint32_t  :1;
    vuint32_t R_UVL_ERR:1;
    vuint32_t N_ERR:1;
    vuint32_t CHID:3;
    vuint32_t FID:3;
    vuint32_t R_OVL_ERR:1;
    vuint32_t F_WD_ERR:1;
    vuint32_t SCI_O_ERR:1;
    vuint32_t SCI_F_ERR:1;
    vuint32_t SCI_P_ERR:1;
    vuint32_t HD_ERR:1;
    vuint32_t ERR:2;
    vuint32_t CRC_ERR_P_ERR:1;
    vuint32_t CRC:3;
    vuint32_t XCRC_ERR:1;
    vuint32_t XCRC:6;
  } B;
} PSI5S_MRU_BUF2_REG1_tag;

typedef union PSI5S_MRU_BUF2_REG2_union_tag { /* PSI5-S MRU OUTPUT BUFFER2 REGISTER2 */
  vuint32_t R;
  struct {
    vuint32_t DCI:4;
    vuint32_t PS_DATA:28;
  } B;
} PSI5S_MRU_BUF2_REG2_tag;

typedef union PSI5S_MRU_BUF2_REG3_union_tag { /* PSI5-S MRU OUTPUT BUFFER2 REGISTER3 */
  vuint32_t R;
  struct {
    vuint32_t DCI:4;
    vuint32_t  :4;
    vuint32_t TIMESTAMP:24;
  } B;
} PSI5S_MRU_BUF2_REG3_tag;

typedef union PSI5S_MBOX_SR_IRQ_union_tag { /* PSI5-S Mbox Status Irq */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t MBOX_CH7:1;
    vuint32_t MBOX_CH6:1;
    vuint32_t MBOX_CH5:1;
    vuint32_t MBOX_CH4:1;
    vuint32_t MBOX_CH3:1;
    vuint32_t MBOX_CH2:1;
    vuint32_t MBOX_CH1:1;
    vuint32_t MBOX_CH0:1;
  } B;
} PSI5S_MBOX_SR_IRQ_tag;

typedef union PSI5S_ERR_SR_IRQ_union_tag { /* PSI5-S Error Status Irq */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t R_UVL_ERR:1;
    vuint32_t N_ERR:1;
    vuint32_t R_OVL_ERR:1;
    vuint32_t F_WD_ERR:1;
    vuint32_t SCI_O_ERR:1;
    vuint32_t SCI_F_ERR:1;
    vuint32_t SCI_P_ERR:1;
    vuint32_t HD_ERR:1;
    vuint32_t CRC_ERR_P_ERR:1;
    vuint32_t XCRC_ERR:1;
  } B;
} PSI5S_ERR_SR_IRQ_tag;

typedef union PSI5S_SEL_IRQ_MBOX_union_tag { /* PSI5-S Mailbox select IRQ[irq_n] */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t MBOX_CH7_SEL:1;
    vuint32_t MBOX_CH6_SEL:1;
    vuint32_t MBOX_CH5_SEL:1;
    vuint32_t MBOX_CH4_SEL:1;
    vuint32_t MBOX_CH3_SEL:1;
    vuint32_t MBOX_CH2_SEL:1;
    vuint32_t MBOX_CH1_SEL:1;
    vuint32_t MBOX_CH0_SEL:1;
  } B;
} PSI5S_SEL_IRQ_MBOX_tag;

typedef union PSI5S_SEL_IRQ_ERR_union_tag { /* PSI5-S Error Select IRQ[iq_n] */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t R_UVL_ERR_SEL:1;
    vuint32_t N_ERR_SEL:1;
    vuint32_t R_OVL_ERR_SEL:1;
    vuint32_t F_WD_ERR_SEL:1;
    vuint32_t SCI_O_ERR_SEL:1;
    vuint32_t SCI_F_ERR_SEL:1;
    vuint32_t SCI_P_ERR_SEL:1;
    vuint32_t HD_ERR_SEL:1;
    vuint32_t CRC_ERR_SEL:1;
    vuint32_t XCRC_ERR_SEL:1;
  } B;
} PSI5S_SEL_IRQ_ERR_tag;

typedef struct PSI5S_SEL_IRQ_struct_tag {
  PSI5S_SEL_IRQ_MBOX_tag MBOX;         /* PSI5-S Mailbox select IRQ[irq_n] */
  PSI5S_SEL_IRQ_ERR_tag ERR;           /* PSI5-S Error Select IRQ[iq_n] */
} PSI5S_SEL_IRQ_tag;

typedef union PSI5S_WDGTSSR_union_tag { /* PSI5-S Watchdog Error Status and Watchdog Timestamp status register */
  vuint32_t R;
  struct {
    vuint32_t F_WD_ERR_STATUS:7;
    vuint32_t  :1;
    vuint32_t WDTS_STATUS:24;
  } B;
} PSI5S_WDGTSSR_tag;

typedef union PSI5S_DIRCMD_union_tag { /* PSI5-S ECU to Sensor Direct Command Write register */
  vuint32_t R;
  struct {
    vuint32_t DIRCMD_BYTE3:8;
    vuint32_t DIRCMD_BYTE2:8;
    vuint32_t DIRCMD_BYTE1:8;
    vuint32_t DIRCMD_BYTE0:8;
  } B;
} PSI5S_DIRCMD_tag;

typedef union PSI5S_MSGA_CH0_union_tag { /* PSI5-S channel 0 message configuration register A */
  vuint32_t R;
  struct {
    vuint32_t  :21;
    vuint32_t F0_BYTE:3;
    vuint32_t  :2;
    vuint32_t TIMESTAMP_A_B_SEL:1;
    vuint32_t  :1;
    vuint32_t TSBUF_CLR:1;
    vuint32_t TSBUF_EN:1;
    vuint32_t  :2;
  } B;
} PSI5S_MSGA_CH0_tag;

typedef union PSI5S_MSGB_CH0_union_tag { /* PSI5-S channel 0 message configuration register B */
  vuint32_t R;
  struct {
    vuint32_t  :27;
    vuint32_t F0_payload:5;
  } B;
} PSI5S_MSGB_CH0_tag;

typedef union PSI5S_MBOX_SR_CH0_union_tag { /* PSI5-S Mailbox status register channel0 */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t F1_ERR:1;
    vuint32_t F1_OV:1;
    vuint32_t F1_READ:1;
    vuint32_t F0_ERR:1;
    vuint32_t F0_OV:1;
    vuint32_t F0_READ:1;
  } B;
} PSI5S_MBOX_SR_CH0_tag;

typedef union PSI5S_MSGA_CH1_union_tag { /* PSI5-S channel message configuration register A */
  vuint32_t R;
  struct {
    vuint32_t L_PC_EN:1;
    vuint32_t F5_BYTE:3;
    vuint32_t L_PC5:1;
    vuint32_t F4_BYTE:3;
    vuint32_t L_PC4:1;
    vuint32_t F3_BYTE:3;
    vuint32_t L_PC3:1;
    vuint32_t F2_BYTE:3;
    vuint32_t L_PC2:1;
    vuint32_t F1_BYTE:3;
    vuint32_t L_PC1:1;
    vuint32_t F0_BYTE:3;
    vuint32_t L_PC0:1;
    vuint32_t MODE:1;
    vuint32_t TIME_STAMP_A_B_SEL:1;
    vuint32_t TMSG_TCMD:1;
    vuint32_t TSBUF_CLR:1;
    vuint32_t TSBUF_EN:1;
    vuint32_t G_PC:1;
    vuint32_t CH_EN:1;
  } B;
} PSI5S_MSGA_CH1_tag;

typedef union PSI5S_MSGB_CH1_union_tag { /* PSI5-S channel message configuration register B */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t F5_payload:5;
    vuint32_t F4_payload:5;
    vuint32_t F3_payload:5;
    vuint32_t F2_payload:5;
    vuint32_t F1_payload:5;
    vuint32_t F0_payload:5;
  } B;
} PSI5S_MSGB_CH1_tag;

typedef union PSI5S_MBOX_SR_CH1_union_tag { /* PSI5-S Mailbox status register channel */
  vuint32_t R;
  struct {
    vuint32_t  :14;
    vuint32_t F5_ERR:1;
    vuint32_t F5_OV:1;
    vuint32_t F5_READ:1;
    vuint32_t F4_ERR:1;
    vuint32_t F4_OV:1;
    vuint32_t F4_READ:1;
    vuint32_t F3_ERR:1;
    vuint32_t F3_OV:1;
    vuint32_t F3_READ:1;
    vuint32_t F2_ERR:1;
    vuint32_t F2_OV:1;
    vuint32_t F2_READ:1;
    vuint32_t F1_ERR:1;
    vuint32_t F1_OV:1;
    vuint32_t F1_READ:1;
    vuint32_t F0_ERR:1;
    vuint32_t F0_OV:1;
    vuint32_t F0_READ:1;
  } B;
} PSI5S_MBOX_SR_CH1_tag;

typedef union PSI5S_WD_CFGR_CH1_union_tag { /* PSI5-S channel watchdog configuration register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t WDRST:1;
    vuint32_t WDCS:1;
    vuint32_t WDEN:1;
    vuint32_t  :1;
    vuint32_t WD_TO:24;
  } B;
} PSI5S_WD_CFGR_CH1_tag;

typedef union PSI5S_DDTRIG_OFFR_CH1_union_tag { /* PSI5-S DDSR Trigger offset register channel */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t DDTRIG_OFFR:16;
  } B;
} PSI5S_DDTRIG_OFFR_CH1_tag;

typedef union PSI5S_DDTRIG_PERR_CH1_union_tag { /* PSI5-S DDSR Trigger period register channel */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t DDTRIG_PERR:16;
  } B;
} PSI5S_DDTRIG_PERR_CH1_tag;

typedef union PSI5S_E2SCR_CH1_union_tag { /* PSI5-S ECU to Sensor Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t CMD:5;
    vuint32_t  :1;
    vuint32_t ACMD:5;
    vuint32_t  :2;
    vuint32_t CH_TRIG:1;
    vuint32_t GL_TRIG_SEL:1;
    vuint32_t DEFAULT_SYNC:1;
    vuint32_t DDSR_SHIFT_SEL:1;
    vuint32_t DDSR_CLR:1;
    vuint32_t DDSR_CLK_SEL:1;
    vuint32_t CMDTR_SW_CTRL:1;
    vuint32_t  :1;
    vuint32_t SYNCHRO_OVF_IE:1;
    vuint32_t  :1;
    vuint32_t CMDTR_NWRT_IE:1;
    vuint32_t CMDPR_BZY_IE:1;
    vuint32_t DDSR_RDY_IE:1;
    vuint32_t  :2;
    vuint32_t CMD_TYPE:3;
  } B;
} PSI5S_E2SCR_CH1_tag;

typedef union PSI5S_E2SSR_CH1_union_tag { /* PSI5-S ECU to Sensor Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t SYCHRO_OVF:1;
    vuint32_t  :1;
    vuint32_t CMDTR_NWRT:1;
    vuint32_t CMDPR_BZY:1;
    vuint32_t DDSR_RDY:1;
    vuint32_t  :5;
  } B;
} PSI5S_E2SSR_CH1_tag;

typedef union PSI5S_DDSR_H_CH1_union_tag { /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register High */
  vuint32_t R;
  struct {
    vuint32_t  :21;
    vuint32_t DDSR_H:11;
  } B;
} PSI5S_DDSR_H_CH1_tag;

typedef union PSI5S_DDSR_L_CH1_union_tag { /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register Low */
  vuint32_t R;
  struct {
    vuint32_t DDSR_L1:8;
    vuint32_t DDSR_L2:24;
  } B;
} PSI5S_DDSR_L_CH1_tag;

typedef union PSI5S_MSGA_CH2_union_tag { /* PSI5-S channel message configuration register A */
  vuint32_t R;
  struct {
    vuint32_t L_PC_EN:1;
    vuint32_t F5_BYTE:3;
    vuint32_t L_PC5:1;
    vuint32_t F4_BYTE:3;
    vuint32_t L_PC4:1;
    vuint32_t F3_BYTE:3;
    vuint32_t L_PC3:1;
    vuint32_t F2_BYTE:3;
    vuint32_t L_PC2:1;
    vuint32_t F1_BYTE:3;
    vuint32_t L_PC1:1;
    vuint32_t F0_BYTE:3;
    vuint32_t L_PC0:1;
    vuint32_t MODE:1;
    vuint32_t TIME_STAMP_A_B_SEL:1;
    vuint32_t TMSG_TCMD:1;
    vuint32_t TSBUF_CLR:1;
    vuint32_t TSBUF_EN:1;
    vuint32_t G_PC:1;
    vuint32_t CH_EN:1;
  } B;
} PSI5S_MSGA_CH2_tag;

typedef union PSI5S_MSGB_CH2_union_tag { /* PSI5-S channel message configuration register B */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t F5_payload:5;
    vuint32_t F4_payload:5;
    vuint32_t F3_payload:5;
    vuint32_t F2_payload:5;
    vuint32_t F1_payload:5;
    vuint32_t F0_payload:5;
  } B;
} PSI5S_MSGB_CH2_tag;

typedef union PSI5S_MBOX_SR_CH2_union_tag { /* PSI5-S Mailbox status register channel */
  vuint32_t R;
  struct {
    vuint32_t  :14;
    vuint32_t F5_ERR:1;
    vuint32_t F5_OV:1;
    vuint32_t F5_READ:1;
    vuint32_t F4_ERR:1;
    vuint32_t F4_OV:1;
    vuint32_t F4_READ:1;
    vuint32_t F3_ERR:1;
    vuint32_t F3_OV:1;
    vuint32_t F3_READ:1;
    vuint32_t F2_ERR:1;
    vuint32_t F2_OV:1;
    vuint32_t F2_READ:1;
    vuint32_t F1_ERR:1;
    vuint32_t F1_OV:1;
    vuint32_t F1_READ:1;
    vuint32_t F0_ERR:1;
    vuint32_t F0_OV:1;
    vuint32_t F0_READ:1;
  } B;
} PSI5S_MBOX_SR_CH2_tag;

typedef union PSI5S_WD_CFGR_CH2_union_tag { /* PSI5-S channel watchdog configuration register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t WDRST:1;
    vuint32_t WDCS:1;
    vuint32_t WDEN:1;
    vuint32_t  :1;
    vuint32_t WD_TO:24;
  } B;
} PSI5S_WD_CFGR_CH2_tag;

typedef union PSI5S_DDTRIG_OFFR_CH2_union_tag { /* PSI5-S DDSR Trigger offset register channel */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t DDTRIG_OFFR:16;
  } B;
} PSI5S_DDTRIG_OFFR_CH2_tag;

typedef union PSI5S_DDTRIG_PERR_CH2_union_tag { /* PSI5-S DDSR Trigger period register channel */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t DDTRIG_PERR:16;
  } B;
} PSI5S_DDTRIG_PERR_CH2_tag;

typedef union PSI5S_E2SCR_CH2_union_tag { /* PSI5-S ECU to Sensor Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t CMD:5;
    vuint32_t  :1;
    vuint32_t ACMD:5;
    vuint32_t  :2;
    vuint32_t CH_TRIG:1;
    vuint32_t GL_TRIG_SEL:1;
    vuint32_t DEFAULT_SYNC:1;
    vuint32_t DDSR_SHIFT_SEL:1;
    vuint32_t DDSR_CLR:1;
    vuint32_t DDSR_CLK_SEL:1;
    vuint32_t CMDTR_SW_CTRL:1;
    vuint32_t  :1;
    vuint32_t SYNCHRO_OVF_IE:1;
    vuint32_t  :1;
    vuint32_t CMDTR_NWRT_IE:1;
    vuint32_t CMDPR_BZY_IE:1;
    vuint32_t DDSR_RDY_IE:1;
    vuint32_t  :2;
    vuint32_t CMD_TYPE:3;
  } B;
} PSI5S_E2SCR_CH2_tag;

typedef union PSI5S_E2SSR_CH2_union_tag { /* PSI5-S ECU to Sensor Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t SYCHRO_OVF:1;
    vuint32_t  :1;
    vuint32_t CMDTR_NWRT:1;
    vuint32_t CMDPR_BZY:1;
    vuint32_t DDSR_RDY:1;
    vuint32_t  :5;
  } B;
} PSI5S_E2SSR_CH2_tag;

typedef union PSI5S_DDSR_H_CH2_union_tag { /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register High */
  vuint32_t R;
  struct {
    vuint32_t  :21;
    vuint32_t DDSR_H:11;
  } B;
} PSI5S_DDSR_H_CH2_tag;

typedef union PSI5S_DDSR_L_CH2_union_tag { /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register Low */
  vuint32_t R;
  struct {
    vuint32_t DDSR_L1:8;
    vuint32_t DDSR_L2:24;
  } B;
} PSI5S_DDSR_L_CH2_tag;

typedef union PSI5S_MSGA_CH3_union_tag { /* PSI5-S channel message configuration register A */
  vuint32_t R;
  struct {
    vuint32_t L_PC_EN:1;
    vuint32_t F5_BYTE:3;
    vuint32_t L_PC5:1;
    vuint32_t F4_BYTE:3;
    vuint32_t L_PC4:1;
    vuint32_t F3_BYTE:3;
    vuint32_t L_PC3:1;
    vuint32_t F2_BYTE:3;
    vuint32_t L_PC2:1;
    vuint32_t F1_BYTE:3;
    vuint32_t L_PC1:1;
    vuint32_t F0_BYTE:3;
    vuint32_t L_PC0:1;
    vuint32_t MODE:1;
    vuint32_t TIME_STAMP_A_B_SEL:1;
    vuint32_t TMSG_TCMD:1;
    vuint32_t TSBUF_CLR:1;
    vuint32_t TSBUF_EN:1;
    vuint32_t G_PC:1;
    vuint32_t CH_EN:1;
  } B;
} PSI5S_MSGA_CH3_tag;

typedef union PSI5S_MSGB_CH3_union_tag { /* PSI5-S channel message configuration register B */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t F5_payload:5;
    vuint32_t F4_payload:5;
    vuint32_t F3_payload:5;
    vuint32_t F2_payload:5;
    vuint32_t F1_payload:5;
    vuint32_t F0_payload:5;
  } B;
} PSI5S_MSGB_CH3_tag;

typedef union PSI5S_MBOX_SR_CH3_union_tag { /* PSI5-S Mailbox status register channel */
  vuint32_t R;
  struct {
    vuint32_t  :14;
    vuint32_t F5_ERR:1;
    vuint32_t F5_OV:1;
    vuint32_t F5_READ:1;
    vuint32_t F4_ERR:1;
    vuint32_t F4_OV:1;
    vuint32_t F4_READ:1;
    vuint32_t F3_ERR:1;
    vuint32_t F3_OV:1;
    vuint32_t F3_READ:1;
    vuint32_t F2_ERR:1;
    vuint32_t F2_OV:1;
    vuint32_t F2_READ:1;
    vuint32_t F1_ERR:1;
    vuint32_t F1_OV:1;
    vuint32_t F1_READ:1;
    vuint32_t F0_ERR:1;
    vuint32_t F0_OV:1;
    vuint32_t F0_READ:1;
  } B;
} PSI5S_MBOX_SR_CH3_tag;

typedef union PSI5S_WD_CFGR_CH3_union_tag { /* PSI5-S channel watchdog configuration register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t WDRST:1;
    vuint32_t WDCS:1;
    vuint32_t WDEN:1;
    vuint32_t  :1;
    vuint32_t WD_TO:24;
  } B;
} PSI5S_WD_CFGR_CH3_tag;

typedef union PSI5S_DDTRIG_OFFR_CH3_union_tag { /* PSI5-S DDSR Trigger offset register channel */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t DDTRIG_OFFR:16;
  } B;
} PSI5S_DDTRIG_OFFR_CH3_tag;

typedef union PSI5S_DDTRIG_PERR_CH3_union_tag { /* PSI5-S DDSR Trigger period register channel */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t DDTRIG_PERR:16;
  } B;
} PSI5S_DDTRIG_PERR_CH3_tag;

typedef union PSI5S_E2SCR_CH3_union_tag { /* PSI5-S ECU to Sensor Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t CMD:5;
    vuint32_t  :1;
    vuint32_t ACMD:5;
    vuint32_t  :2;
    vuint32_t CH_TRIG:1;
    vuint32_t GL_TRIG_SEL:1;
    vuint32_t DEFAULT_SYNC:1;
    vuint32_t DDSR_SHIFT_SEL:1;
    vuint32_t DDSR_CLR:1;
    vuint32_t DDSR_CLK_SEL:1;
    vuint32_t CMDTR_SW_CTRL:1;
    vuint32_t  :1;
    vuint32_t SYNCHRO_OVF_IE:1;
    vuint32_t  :1;
    vuint32_t CMDTR_NWRT_IE:1;
    vuint32_t CMDPR_BZY_IE:1;
    vuint32_t DDSR_RDY_IE:1;
    vuint32_t  :2;
    vuint32_t CMD_TYPE:3;
  } B;
} PSI5S_E2SCR_CH3_tag;

typedef union PSI5S_E2SSR_CH3_union_tag { /* PSI5-S ECU to Sensor Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t SYCHRO_OVF:1;
    vuint32_t  :1;
    vuint32_t CMDTR_NWRT:1;
    vuint32_t CMDPR_BZY:1;
    vuint32_t DDSR_RDY:1;
    vuint32_t  :5;
  } B;
} PSI5S_E2SSR_CH3_tag;

typedef union PSI5S_DDSR_H_CH3_union_tag { /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register High */
  vuint32_t R;
  struct {
    vuint32_t  :21;
    vuint32_t DDSR_H:11;
  } B;
} PSI5S_DDSR_H_CH3_tag;

typedef union PSI5S_DDSR_L_CH3_union_tag { /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register Low */
  vuint32_t R;
  struct {
    vuint32_t DDSR_L1:8;
    vuint32_t DDSR_L2:24;
  } B;
} PSI5S_DDSR_L_CH3_tag;

typedef union PSI5S_MSGA_CH4_union_tag { /* PSI5-S channel message configuration register A */
  vuint32_t R;
  struct {
    vuint32_t L_PC_EN:1;
    vuint32_t F5_BYTE:3;
    vuint32_t L_PC5:1;
    vuint32_t F4_BYTE:3;
    vuint32_t L_PC4:1;
    vuint32_t F3_BYTE:3;
    vuint32_t L_PC3:1;
    vuint32_t F2_BYTE:3;
    vuint32_t L_PC2:1;
    vuint32_t F1_BYTE:3;
    vuint32_t L_PC1:1;
    vuint32_t F0_BYTE:3;
    vuint32_t L_PC0:1;
    vuint32_t MODE:1;
    vuint32_t TIME_STAMP_A_B_SEL:1;
    vuint32_t TMSG_TCMD:1;
    vuint32_t TSBUF_CLR:1;
    vuint32_t TSBUF_EN:1;
    vuint32_t G_PC:1;
    vuint32_t CH_EN:1;
  } B;
} PSI5S_MSGA_CH4_tag;

typedef union PSI5S_MSGB_CH4_union_tag { /* PSI5-S channel message configuration register B */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t F5_payload:5;
    vuint32_t F4_payload:5;
    vuint32_t F3_payload:5;
    vuint32_t F2_payload:5;
    vuint32_t F1_payload:5;
    vuint32_t F0_payload:5;
  } B;
} PSI5S_MSGB_CH4_tag;

typedef union PSI5S_MBOX_SR_CH4_union_tag { /* PSI5-S Mailbox status register channel */
  vuint32_t R;
  struct {
    vuint32_t  :14;
    vuint32_t F5_ERR:1;
    vuint32_t F5_OV:1;
    vuint32_t F5_READ:1;
    vuint32_t F4_ERR:1;
    vuint32_t F4_OV:1;
    vuint32_t F4_READ:1;
    vuint32_t F3_ERR:1;
    vuint32_t F3_OV:1;
    vuint32_t F3_READ:1;
    vuint32_t F2_ERR:1;
    vuint32_t F2_OV:1;
    vuint32_t F2_READ:1;
    vuint32_t F1_ERR:1;
    vuint32_t F1_OV:1;
    vuint32_t F1_READ:1;
    vuint32_t F0_ERR:1;
    vuint32_t F0_OV:1;
    vuint32_t F0_READ:1;
  } B;
} PSI5S_MBOX_SR_CH4_tag;

typedef union PSI5S_WD_CFGR_CH4_union_tag { /* PSI5-S channel watchdog configuration register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t WDRST:1;
    vuint32_t WDCS:1;
    vuint32_t WDEN:1;
    vuint32_t  :1;
    vuint32_t WD_TO:24;
  } B;
} PSI5S_WD_CFGR_CH4_tag;

typedef union PSI5S_DDTRIG_OFFR_CH4_union_tag { /* PSI5-S DDSR Trigger offset register channel */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t DDTRIG_OFFR:16;
  } B;
} PSI5S_DDTRIG_OFFR_CH4_tag;

typedef union PSI5S_DDTRIG_PERR_CH4_union_tag { /* PSI5-S DDSR Trigger period register channel */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t DDTRIG_PERR:16;
  } B;
} PSI5S_DDTRIG_PERR_CH4_tag;

typedef union PSI5S_E2SCR_CH4_union_tag { /* PSI5-S ECU to Sensor Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t CMD:5;
    vuint32_t  :1;
    vuint32_t ACMD:5;
    vuint32_t  :2;
    vuint32_t CH_TRIG:1;
    vuint32_t GL_TRIG_SEL:1;
    vuint32_t DEFAULT_SYNC:1;
    vuint32_t DDSR_SHIFT_SEL:1;
    vuint32_t DDSR_CLR:1;
    vuint32_t DDSR_CLK_SEL:1;
    vuint32_t CMDTR_SW_CTRL:1;
    vuint32_t  :1;
    vuint32_t SYNCHRO_OVF_IE:1;
    vuint32_t  :1;
    vuint32_t CMDTR_NWRT_IE:1;
    vuint32_t CMDPR_BZY_IE:1;
    vuint32_t DDSR_RDY_IE:1;
    vuint32_t  :2;
    vuint32_t CMD_TYPE:3;
  } B;
} PSI5S_E2SCR_CH4_tag;

typedef union PSI5S_E2SSR_CH4_union_tag { /* PSI5-S ECU to Sensor Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t SYCHRO_OVF:1;
    vuint32_t  :1;
    vuint32_t CMDTR_NWRT:1;
    vuint32_t CMDPR_BZY:1;
    vuint32_t DDSR_RDY:1;
    vuint32_t  :5;
  } B;
} PSI5S_E2SSR_CH4_tag;

typedef union PSI5S_DDSR_H_CH4_union_tag { /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register High */
  vuint32_t R;
  struct {
    vuint32_t  :21;
    vuint32_t DDSR_H:11;
  } B;
} PSI5S_DDSR_H_CH4_tag;

typedef union PSI5S_DDSR_L_CH4_union_tag { /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register Low */
  vuint32_t R;
  struct {
    vuint32_t DDSR_L1:8;
    vuint32_t DDSR_L2:24;
  } B;
} PSI5S_DDSR_L_CH4_tag;

typedef union PSI5S_MSGA_CH5_union_tag { /* PSI5-S channel message configuration register A */
  vuint32_t R;
  struct {
    vuint32_t L_PC_EN:1;
    vuint32_t F5_BYTE:3;
    vuint32_t L_PC5:1;
    vuint32_t F4_BYTE:3;
    vuint32_t L_PC4:1;
    vuint32_t F3_BYTE:3;
    vuint32_t L_PC3:1;
    vuint32_t F2_BYTE:3;
    vuint32_t L_PC2:1;
    vuint32_t F1_BYTE:3;
    vuint32_t L_PC1:1;
    vuint32_t F0_BYTE:3;
    vuint32_t L_PC0:1;
    vuint32_t MODE:1;
    vuint32_t TIME_STAMP_A_B_SEL:1;
    vuint32_t TMSG_TCMD:1;
    vuint32_t TSBUF_CLR:1;
    vuint32_t TSBUF_EN:1;
    vuint32_t G_PC:1;
    vuint32_t CH_EN:1;
  } B;
} PSI5S_MSGA_CH5_tag;

typedef union PSI5S_MSGB_CH5_union_tag { /* PSI5-S channel message configuration register B */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t F5_payload:5;
    vuint32_t F4_payload:5;
    vuint32_t F3_payload:5;
    vuint32_t F2_payload:5;
    vuint32_t F1_payload:5;
    vuint32_t F0_payload:5;
  } B;
} PSI5S_MSGB_CH5_tag;

typedef union PSI5S_MBOX_SR_CH5_union_tag { /* PSI5-S Mailbox status register channel */
  vuint32_t R;
  struct {
    vuint32_t  :14;
    vuint32_t F5_ERR:1;
    vuint32_t F5_OV:1;
    vuint32_t F5_READ:1;
    vuint32_t F4_ERR:1;
    vuint32_t F4_OV:1;
    vuint32_t F4_READ:1;
    vuint32_t F3_ERR:1;
    vuint32_t F3_OV:1;
    vuint32_t F3_READ:1;
    vuint32_t F2_ERR:1;
    vuint32_t F2_OV:1;
    vuint32_t F2_READ:1;
    vuint32_t F1_ERR:1;
    vuint32_t F1_OV:1;
    vuint32_t F1_READ:1;
    vuint32_t F0_ERR:1;
    vuint32_t F0_OV:1;
    vuint32_t F0_READ:1;
  } B;
} PSI5S_MBOX_SR_CH5_tag;

typedef union PSI5S_WD_CFGR_CH5_union_tag { /* PSI5-S channel watchdog configuration register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t WDRST:1;
    vuint32_t WDCS:1;
    vuint32_t WDEN:1;
    vuint32_t  :1;
    vuint32_t WD_TO:24;
  } B;
} PSI5S_WD_CFGR_CH5_tag;

typedef union PSI5S_DDTRIG_OFFR_CH5_union_tag { /* PSI5-S DDSR Trigger offset register channel */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t DDTRIG_OFFR:16;
  } B;
} PSI5S_DDTRIG_OFFR_CH5_tag;

typedef union PSI5S_DDTRIG_PERR_CH5_union_tag { /* PSI5-S DDSR Trigger period register channel */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t DDTRIG_PERR:16;
  } B;
} PSI5S_DDTRIG_PERR_CH5_tag;

typedef union PSI5S_E2SCR_CH5_union_tag { /* PSI5-S ECU to Sensor Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t CMD:5;
    vuint32_t  :1;
    vuint32_t ACMD:5;
    vuint32_t  :2;
    vuint32_t CH_TRIG:1;
    vuint32_t GL_TRIG_SEL:1;
    vuint32_t DEFAULT_SYNC:1;
    vuint32_t DDSR_SHIFT_SEL:1;
    vuint32_t DDSR_CLR:1;
    vuint32_t DDSR_CLK_SEL:1;
    vuint32_t CMDTR_SW_CTRL:1;
    vuint32_t  :1;
    vuint32_t SYNCHRO_OVF_IE:1;
    vuint32_t  :1;
    vuint32_t CMDTR_NWRT_IE:1;
    vuint32_t CMDPR_BZY_IE:1;
    vuint32_t DDSR_RDY_IE:1;
    vuint32_t  :2;
    vuint32_t CMD_TYPE:3;
  } B;
} PSI5S_E2SCR_CH5_tag;

typedef union PSI5S_E2SSR_CH5_union_tag { /* PSI5-S ECU to Sensor Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t SYCHRO_OVF:1;
    vuint32_t  :1;
    vuint32_t CMDTR_NWRT:1;
    vuint32_t CMDPR_BZY:1;
    vuint32_t DDSR_RDY:1;
    vuint32_t  :5;
  } B;
} PSI5S_E2SSR_CH5_tag;

typedef union PSI5S_DDSR_H_CH5_union_tag { /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register High */
  vuint32_t R;
  struct {
    vuint32_t  :21;
    vuint32_t DDSR_H:11;
  } B;
} PSI5S_DDSR_H_CH5_tag;

typedef union PSI5S_DDSR_L_CH5_union_tag { /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register Low */
  vuint32_t R;
  struct {
    vuint32_t DDSR_L1:8;
    vuint32_t DDSR_L2:24;
  } B;
} PSI5S_DDSR_L_CH5_tag;

typedef union PSI5S_MSGA_CH6_union_tag { /* PSI5-S channel message configuration register A */
  vuint32_t R;
  struct {
    vuint32_t L_PC_EN:1;
    vuint32_t F5_BYTE:3;
    vuint32_t L_PC5:1;
    vuint32_t F4_BYTE:3;
    vuint32_t L_PC4:1;
    vuint32_t F3_BYTE:3;
    vuint32_t L_PC3:1;
    vuint32_t F2_BYTE:3;
    vuint32_t L_PC2:1;
    vuint32_t F1_BYTE:3;
    vuint32_t L_PC1:1;
    vuint32_t F0_BYTE:3;
    vuint32_t L_PC0:1;
    vuint32_t MODE:1;
    vuint32_t TIME_STAMP_A_B_SEL:1;
    vuint32_t TMSG_TCMD:1;
    vuint32_t TSBUF_CLR:1;
    vuint32_t TSBUF_EN:1;
    vuint32_t G_PC:1;
    vuint32_t CH_EN:1;
  } B;
} PSI5S_MSGA_CH6_tag;

typedef union PSI5S_MSGB_CH6_union_tag { /* PSI5-S channel message configuration register B */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t F5_payload:5;
    vuint32_t F4_payload:5;
    vuint32_t F3_payload:5;
    vuint32_t F2_payload:5;
    vuint32_t F1_payload:5;
    vuint32_t F0_payload:5;
  } B;
} PSI5S_MSGB_CH6_tag;

typedef union PSI5S_MBOX_SR_CH6_union_tag { /* PSI5-S Mailbox status register channel */
  vuint32_t R;
  struct {
    vuint32_t  :14;
    vuint32_t F5_ERR:1;
    vuint32_t F5_OV:1;
    vuint32_t F5_READ:1;
    vuint32_t F4_ERR:1;
    vuint32_t F4_OV:1;
    vuint32_t F4_READ:1;
    vuint32_t F3_ERR:1;
    vuint32_t F3_OV:1;
    vuint32_t F3_READ:1;
    vuint32_t F2_ERR:1;
    vuint32_t F2_OV:1;
    vuint32_t F2_READ:1;
    vuint32_t F1_ERR:1;
    vuint32_t F1_OV:1;
    vuint32_t F1_READ:1;
    vuint32_t F0_ERR:1;
    vuint32_t F0_OV:1;
    vuint32_t F0_READ:1;
  } B;
} PSI5S_MBOX_SR_CH6_tag;

typedef union PSI5S_WD_CFGR_CH6_union_tag { /* PSI5-S channel watchdog configuration register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t WDRST:1;
    vuint32_t WDCS:1;
    vuint32_t WDEN:1;
    vuint32_t  :1;
    vuint32_t WD_TO:24;
  } B;
} PSI5S_WD_CFGR_CH6_tag;

typedef union PSI5S_DDTRIG_OFFR_CH6_union_tag { /* PSI5-S DDSR Trigger offset register channel */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t DDTRIG_OFFR:16;
  } B;
} PSI5S_DDTRIG_OFFR_CH6_tag;

typedef union PSI5S_DDTRIG_PERR_CH6_union_tag { /* PSI5-S DDSR Trigger period register channel */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t DDTRIG_PERR:16;
  } B;
} PSI5S_DDTRIG_PERR_CH6_tag;

typedef union PSI5S_E2SCR_CH6_union_tag { /* PSI5-S ECU to Sensor Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t CMD:5;
    vuint32_t  :1;
    vuint32_t ACMD:5;
    vuint32_t  :2;
    vuint32_t CH_TRIG:1;
    vuint32_t GL_TRIG_SEL:1;
    vuint32_t DEFAULT_SYNC:1;
    vuint32_t DDSR_SHIFT_SEL:1;
    vuint32_t DDSR_CLR:1;
    vuint32_t DDSR_CLK_SEL:1;
    vuint32_t CMDTR_SW_CTRL:1;
    vuint32_t  :1;
    vuint32_t SYNCHRO_OVF_IE:1;
    vuint32_t  :1;
    vuint32_t CMDTR_NWRT_IE:1;
    vuint32_t CMDPR_BZY_IE:1;
    vuint32_t DDSR_RDY_IE:1;
    vuint32_t  :2;
    vuint32_t CMD_TYPE:3;
  } B;
} PSI5S_E2SCR_CH6_tag;

typedef union PSI5S_E2SSR_CH6_union_tag { /* PSI5-S ECU to Sensor Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t SYCHRO_OVF:1;
    vuint32_t  :1;
    vuint32_t CMDTR_NWRT:1;
    vuint32_t CMDPR_BZY:1;
    vuint32_t DDSR_RDY:1;
    vuint32_t  :5;
  } B;
} PSI5S_E2SSR_CH6_tag;

typedef union PSI5S_DDSR_H_CH6_union_tag { /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register High */
  vuint32_t R;
  struct {
    vuint32_t  :21;
    vuint32_t DDSR_H:11;
  } B;
} PSI5S_DDSR_H_CH6_tag;

typedef union PSI5S_DDSR_L_CH6_union_tag { /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register Low */
  vuint32_t R;
  struct {
    vuint32_t DDSR_L1:8;
    vuint32_t DDSR_L2:24;
  } B;
} PSI5S_DDSR_L_CH6_tag;

typedef union PSI5S_MSGA_CH7_union_tag { /* PSI5-S channel message configuration register A */
  vuint32_t R;
  struct {
    vuint32_t L_PC_EN:1;
    vuint32_t F5_BYTE:3;
    vuint32_t L_PC5:1;
    vuint32_t F4_BYTE:3;
    vuint32_t L_PC4:1;
    vuint32_t F3_BYTE:3;
    vuint32_t L_PC3:1;
    vuint32_t F2_BYTE:3;
    vuint32_t L_PC2:1;
    vuint32_t F1_BYTE:3;
    vuint32_t L_PC1:1;
    vuint32_t F0_BYTE:3;
    vuint32_t L_PC0:1;
    vuint32_t MODE:1;
    vuint32_t TIME_STAMP_A_B_SEL:1;
    vuint32_t TMSG_TCMD:1;
    vuint32_t TSBUF_CLR:1;
    vuint32_t TSBUF_EN:1;
    vuint32_t G_PC:1;
    vuint32_t CH_EN:1;
  } B;
} PSI5S_MSGA_CH7_tag;

typedef union PSI5S_MSGB_CH7_union_tag { /* PSI5-S channel message configuration register B */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t F5_payload:5;
    vuint32_t F4_payload:5;
    vuint32_t F3_payload:5;
    vuint32_t F2_payload:5;
    vuint32_t F1_payload:5;
    vuint32_t F0_payload:5;
  } B;
} PSI5S_MSGB_CH7_tag;

typedef union PSI5S_MBOX_SR_CH7_union_tag { /* PSI5-S Mailbox status register channel */
  vuint32_t R;
  struct {
    vuint32_t  :14;
    vuint32_t F5_ERR:1;
    vuint32_t F5_OV:1;
    vuint32_t F5_READ:1;
    vuint32_t F4_ERR:1;
    vuint32_t F4_OV:1;
    vuint32_t F4_READ:1;
    vuint32_t F3_ERR:1;
    vuint32_t F3_OV:1;
    vuint32_t F3_READ:1;
    vuint32_t F2_ERR:1;
    vuint32_t F2_OV:1;
    vuint32_t F2_READ:1;
    vuint32_t F1_ERR:1;
    vuint32_t F1_OV:1;
    vuint32_t F1_READ:1;
    vuint32_t F0_ERR:1;
    vuint32_t F0_OV:1;
    vuint32_t F0_READ:1;
  } B;
} PSI5S_MBOX_SR_CH7_tag;

typedef union PSI5S_WD_CFGR_CH7_union_tag { /* PSI5-S channel watchdog configuration register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t WDRST:1;
    vuint32_t WDCS:1;
    vuint32_t WDEN:1;
    vuint32_t  :1;
    vuint32_t WD_TO:24;
  } B;
} PSI5S_WD_CFGR_CH7_tag;

typedef union PSI5S_DDTRIG_OFFR_CH7_union_tag { /* PSI5-S DDSR Trigger offset register channel */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t DDTRIG_OFFR:16;
  } B;
} PSI5S_DDTRIG_OFFR_CH7_tag;

typedef union PSI5S_DDTRIG_PERR_CH7_union_tag { /* PSI5-S DDSR Trigger period register channel */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t DDTRIG_PERR:16;
  } B;
} PSI5S_DDTRIG_PERR_CH7_tag;

typedef union PSI5S_E2SCR_CH7_union_tag { /* PSI5-S ECU to Sensor Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t CMD:5;
    vuint32_t  :1;
    vuint32_t ACMD:5;
    vuint32_t  :2;
    vuint32_t CH_TRIG:1;
    vuint32_t GL_TRIG_SEL:1;
    vuint32_t DEFAULT_SYNC:1;
    vuint32_t DDSR_SHIFT_SEL:1;
    vuint32_t DDSR_CLR:1;
    vuint32_t DDSR_CLK_SEL:1;
    vuint32_t CMDTR_SW_CTRL:1;
    vuint32_t  :1;
    vuint32_t SYNCHRO_OVF_IE:1;
    vuint32_t  :1;
    vuint32_t CMDTR_NWRT_IE:1;
    vuint32_t CMDPR_BZY_IE:1;
    vuint32_t DDSR_RDY_IE:1;
    vuint32_t  :2;
    vuint32_t CMD_TYPE:3;
  } B;
} PSI5S_E2SCR_CH7_tag;

typedef union PSI5S_E2SSR_CH7_union_tag { /* PSI5-S ECU to Sensor Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t SYCHRO_OVF:1;
    vuint32_t  :1;
    vuint32_t CMDTR_NWRT:1;
    vuint32_t CMDPR_BZY:1;
    vuint32_t DDSR_RDY:1;
    vuint32_t  :5;
  } B;
} PSI5S_E2SSR_CH7_tag;

typedef union PSI5S_DDSR_H_CH7_union_tag { /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register High */
  vuint32_t R;
  struct {
    vuint32_t  :21;
    vuint32_t DDSR_H:11;
  } B;
} PSI5S_DDSR_H_CH7_tag;

typedef union PSI5S_DDSR_L_CH7_union_tag { /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register Low */
  vuint32_t R;
  struct {
    vuint32_t DDSR_L1:8;
    vuint32_t DDSR_L2:24;
  } B;
} PSI5S_DDSR_L_CH7_tag;

struct PSI5S_tag {
  PSI5S_LINCR1_tag LINCR1;             /* PSI5-S LIN Control Register 1 */
  PSI5S_LINIER_tag LINIER;             /* PSI5-S LIN Interrupt enable register */
  PSI5S_LINSR_tag LINSR;               /* PSI5-S LIN Status Register */
  uint8_t PSI5S_reserved0[4];
  PSI5S_UARTCR_tag UARTCR;             /* PSI5-S UART Mode Control Register */
  PSI5S_UARTSR_tag UARTSR;             /* PSI5-S UART Mode Status Register */
  uint8_t PSI5S_reserved1[12];
  PSI5S_LINFBRR_tag LINFBRR;           /* PSI5-S LIN Fractional Baud Rate Register */
  PSI5S_LINIBRR_tag LINIBRR;           /* PSI5-S LIN Integer Baud Rate Register */
  uint8_t PSI5S_reserved2[4];
  PSI5S_LINCR2_tag LINCR2;             /* PSI5-S LIN Control Register 2 */
  uint8_t PSI5S_reserved3[4];
  PSI5S_BDRL_tag BDRL;                 /* PSI5-S Buffer Data Register Least Significant */
  PSI5S_BDRM_tag BDRM;                 /* PSI5-S Buffer Data Register Most Significant */
  uint8_t PSI5S_reserved4[12];
  PSI5S_GCR_tag GCR;                   /* PSI5-S Global Control register */
  PSI5S_UARTPTO_tag UARTPTO;           /* PSI5-S UART Preset Timeout Register */
  PSI5S_UARTCTO_tag UARTCTO;           /* UPSI5-S ART Current Timeout register */
  PSI5S_DMATXE_tag DMATXE;             /* DMA Tx Enable Register */
  PSI5S_DMARXE_tag DMARXE;             /* DMA Rx Enable Register */
  PSI5S_PTD_tag PTD;                   /* PSI5-S UART Tx Idle Delay Time Register */
  uint8_t PSI5S_reserved5[80];
  PSI5S_GLCR_tag GLCR;                 /* PSI5-S Global Control Register */
  PSI5S_GLSR_tag GLSR;                 /* PSI5-S Global Status Register */
  PSI5S_CH_BASE_ADDR_tag CH_BASE_ADDR; /* PSI5-S CHANNEL_BASE_ADDRESS */
  PSI5S_MRU_BUF2_REG0_tag MRU_BUF2_REG0; /* PSI5-S MRU OUTPUT BUFFER2 REGISTER0 */
  PSI5S_MRU_BUF2_REG1_tag MRU_BUF2_REG1; /* PSI5-S MRU OUTPUT BUFFER2 REGISTER1 */
  PSI5S_MRU_BUF2_REG2_tag MRU_BUF2_REG2; /* PSI5-S MRU OUTPUT BUFFER2 REGISTER2 */
  PSI5S_MRU_BUF2_REG3_tag MRU_BUF2_REG3; /* PSI5-S MRU OUTPUT BUFFER2 REGISTER3 */
  uint8_t PSI5S_reserved6[16];
  PSI5S_MBOX_SR_IRQ_tag MBOX_SR_IRQ;   /* PSI5-S Mbox Status Irq */
  PSI5S_ERR_SR_IRQ_tag ERR_SR_IRQ;     /* PSI5-S Error Status Irq */
  PSI5S_SEL_IRQ_tag SEL_IRQ[8];
  PSI5S_WDGTSSR_tag WDGTSSR;           /* PSI5-S Watchdog Error Status and Watchdog Timestamp status register */
  PSI5S_DIRCMD_tag DIRCMD;             /* PSI5-S ECU to Sensor Direct Command Write register */
  uint8_t PSI5S_reserved7[60];
  PSI5S_MSGA_CH0_tag MSGA_CH0;         /* PSI5-S channel 0 message configuration register A */
  PSI5S_MSGB_CH0_tag MSGB_CH0;         /* PSI5-S channel 0 message configuration register B */
  uint8_t PSI5S_reserved8[4];
  PSI5S_MBOX_SR_CH0_tag MBOX_SR_CH0;   /* PSI5-S Mailbox status register channel0 */
  uint8_t PSI5S_reserved9[20];
  PSI5S_MSGA_CH1_tag MSGA_CH1;         /* PSI5-S channel message configuration register A */
  PSI5S_MSGB_CH1_tag MSGB_CH1;         /* PSI5-S channel message configuration register B */
  uint8_t PSI5S_reserved10[4];
  PSI5S_MBOX_SR_CH1_tag MBOX_SR_CH1;   /* PSI5-S Mailbox status register channel */
  PSI5S_WD_CFGR_CH1_tag WD_CFGR_CH1;   /* PSI5-S channel watchdog configuration register */
  PSI5S_DDTRIG_OFFR_CH1_tag DDTRIG_OFFR_CH1; /* PSI5-S DDSR Trigger offset register channel */
  PSI5S_DDTRIG_PERR_CH1_tag DDTRIG_PERR_CH1; /* PSI5-S DDSR Trigger period register channel */
  PSI5S_E2SCR_CH1_tag E2SCR_CH1;       /* PSI5-S ECU to Sensor Control Register */
  PSI5S_E2SSR_CH1_tag E2SSR_CH1;       /* PSI5-S ECU to Sensor Status Register */
  PSI5S_DDSR_H_CH1_tag DDSR_H_CH1;     /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register High */
  PSI5S_DDSR_L_CH1_tag DDSR_L_CH1;     /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register Low */
  uint8_t PSI5S_reserved11[16];
  PSI5S_MSGA_CH2_tag MSGA_CH2;         /* PSI5-S channel message configuration register A */
  PSI5S_MSGB_CH2_tag MSGB_CH2;         /* PSI5-S channel message configuration register B */
  uint8_t PSI5S_reserved12[4];
  PSI5S_MBOX_SR_CH2_tag MBOX_SR_CH2;   /* PSI5-S Mailbox status register channel */
  PSI5S_WD_CFGR_CH2_tag WD_CFGR_CH2;   /* PSI5-S channel watchdog configuration register */
  PSI5S_DDTRIG_OFFR_CH2_tag DDTRIG_OFFR_CH2; /* PSI5-S DDSR Trigger offset register channel */
  PSI5S_DDTRIG_PERR_CH2_tag DDTRIG_PERR_CH2; /* PSI5-S DDSR Trigger period register channel */
  PSI5S_E2SCR_CH2_tag E2SCR_CH2;       /* PSI5-S ECU to Sensor Control Register */
  PSI5S_E2SSR_CH2_tag E2SSR_CH2;       /* PSI5-S ECU to Sensor Status Register */
  PSI5S_DDSR_H_CH2_tag DDSR_H_CH2;     /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register High */
  PSI5S_DDSR_L_CH2_tag DDSR_L_CH2;     /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register Low */
  uint8_t PSI5S_reserved13[16];
  PSI5S_MSGA_CH3_tag MSGA_CH3;         /* PSI5-S channel message configuration register A */
  PSI5S_MSGB_CH3_tag MSGB_CH3;         /* PSI5-S channel message configuration register B */
  uint8_t PSI5S_reserved14[4];
  PSI5S_MBOX_SR_CH3_tag MBOX_SR_CH3;   /* PSI5-S Mailbox status register channel */
  PSI5S_WD_CFGR_CH3_tag WD_CFGR_CH3;   /* PSI5-S channel watchdog configuration register */
  PSI5S_DDTRIG_OFFR_CH3_tag DDTRIG_OFFR_CH3; /* PSI5-S DDSR Trigger offset register channel */
  PSI5S_DDTRIG_PERR_CH3_tag DDTRIG_PERR_CH3; /* PSI5-S DDSR Trigger period register channel */
  PSI5S_E2SCR_CH3_tag E2SCR_CH3;       /* PSI5-S ECU to Sensor Control Register */
  PSI5S_E2SSR_CH3_tag E2SSR_CH3;       /* PSI5-S ECU to Sensor Status Register */
  PSI5S_DDSR_H_CH3_tag DDSR_H_CH3;     /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register High */
  PSI5S_DDSR_L_CH3_tag DDSR_L_CH3;     /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register Low */
  uint8_t PSI5S_reserved15[16];
  PSI5S_MSGA_CH4_tag MSGA_CH4;         /* PSI5-S channel message configuration register A */
  PSI5S_MSGB_CH4_tag MSGB_CH4;         /* PSI5-S channel message configuration register B */
  uint8_t PSI5S_reserved16[4];
  PSI5S_MBOX_SR_CH4_tag MBOX_SR_CH4;   /* PSI5-S Mailbox status register channel */
  PSI5S_WD_CFGR_CH4_tag WD_CFGR_CH4;   /* PSI5-S channel watchdog configuration register */
  PSI5S_DDTRIG_OFFR_CH4_tag DDTRIG_OFFR_CH4; /* PSI5-S DDSR Trigger offset register channel */
  PSI5S_DDTRIG_PERR_CH4_tag DDTRIG_PERR_CH4; /* PSI5-S DDSR Trigger period register channel */
  PSI5S_E2SCR_CH4_tag E2SCR_CH4;       /* PSI5-S ECU to Sensor Control Register */
  PSI5S_E2SSR_CH4_tag E2SSR_CH4;       /* PSI5-S ECU to Sensor Status Register */
  PSI5S_DDSR_H_CH4_tag DDSR_H_CH4;     /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register High */
  PSI5S_DDSR_L_CH4_tag DDSR_L_CH4;     /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register Low */
  uint8_t PSI5S_reserved17[16];
  PSI5S_MSGA_CH5_tag MSGA_CH5;         /* PSI5-S channel message configuration register A */
  PSI5S_MSGB_CH5_tag MSGB_CH5;         /* PSI5-S channel message configuration register B */
  uint8_t PSI5S_reserved18[4];
  PSI5S_MBOX_SR_CH5_tag MBOX_SR_CH5;   /* PSI5-S Mailbox status register channel */
  PSI5S_WD_CFGR_CH5_tag WD_CFGR_CH5;   /* PSI5-S channel watchdog configuration register */
  PSI5S_DDTRIG_OFFR_CH5_tag DDTRIG_OFFR_CH5; /* PSI5-S DDSR Trigger offset register channel */
  PSI5S_DDTRIG_PERR_CH5_tag DDTRIG_PERR_CH5; /* PSI5-S DDSR Trigger period register channel */
  PSI5S_E2SCR_CH5_tag E2SCR_CH5;       /* PSI5-S ECU to Sensor Control Register */
  PSI5S_E2SSR_CH5_tag E2SSR_CH5;       /* PSI5-S ECU to Sensor Status Register */
  PSI5S_DDSR_H_CH5_tag DDSR_H_CH5;     /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register High */
  PSI5S_DDSR_L_CH5_tag DDSR_L_CH5;     /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register Low */
  uint8_t PSI5S_reserved19[16];
  PSI5S_MSGA_CH6_tag MSGA_CH6;         /* PSI5-S channel message configuration register A */
  PSI5S_MSGB_CH6_tag MSGB_CH6;         /* PSI5-S channel message configuration register B */
  uint8_t PSI5S_reserved20[4];
  PSI5S_MBOX_SR_CH6_tag MBOX_SR_CH6;   /* PSI5-S Mailbox status register channel */
  PSI5S_WD_CFGR_CH6_tag WD_CFGR_CH6;   /* PSI5-S channel watchdog configuration register */
  PSI5S_DDTRIG_OFFR_CH6_tag DDTRIG_OFFR_CH6; /* PSI5-S DDSR Trigger offset register channel */
  PSI5S_DDTRIG_PERR_CH6_tag DDTRIG_PERR_CH6; /* PSI5-S DDSR Trigger period register channel */
  PSI5S_E2SCR_CH6_tag E2SCR_CH6;       /* PSI5-S ECU to Sensor Control Register */
  PSI5S_E2SSR_CH6_tag E2SSR_CH6;       /* PSI5-S ECU to Sensor Status Register */
  PSI5S_DDSR_H_CH6_tag DDSR_H_CH6;     /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register High */
  PSI5S_DDSR_L_CH6_tag DDSR_L_CH6;     /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register Low */
  uint8_t PSI5S_reserved21[16];
  PSI5S_MSGA_CH7_tag MSGA_CH7;         /* PSI5-S channel message configuration register A */
  PSI5S_MSGB_CH7_tag MSGB_CH7;         /* PSI5-S channel message configuration register B */
  uint8_t PSI5S_reserved22[4];
  PSI5S_MBOX_SR_CH7_tag MBOX_SR_CH7;   /* PSI5-S Mailbox status register channel */
  PSI5S_WD_CFGR_CH7_tag WD_CFGR_CH7;   /* PSI5-S channel watchdog configuration register */
  PSI5S_DDTRIG_OFFR_CH7_tag DDTRIG_OFFR_CH7; /* PSI5-S DDSR Trigger offset register channel */
  PSI5S_DDTRIG_PERR_CH7_tag DDTRIG_PERR_CH7; /* PSI5-S DDSR Trigger period register channel */
  PSI5S_E2SCR_CH7_tag E2SCR_CH7;       /* PSI5-S ECU to Sensor Control Register */
  PSI5S_E2SSR_CH7_tag E2SSR_CH7;       /* PSI5-S ECU to Sensor Status Register */
  PSI5S_DDSR_H_CH7_tag DDSR_H_CH7;     /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register High */
  PSI5S_DDSR_L_CH7_tag DDSR_L_CH7;     /* PSI5-S channel1 ECU to Sensor Downstream Data Shift Register Low */
};

#endif
