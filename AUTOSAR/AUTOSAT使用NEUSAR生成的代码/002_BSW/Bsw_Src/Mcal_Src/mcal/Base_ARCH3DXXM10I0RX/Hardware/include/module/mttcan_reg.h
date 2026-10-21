#ifndef M_TTCAN_REG_H_
#define M_TTCAN_REG_H_

/* ============================================================================
   =============================== Module: M_TTCAN ============================
   ============================================================================ */

typedef union M_TTCAN_CREL_union_tag { /* Core Release Register */
  vuint32_t R;
  struct {
    vuint32_t REL:4;
    vuint32_t STEP:4;
    vuint32_t SUBSTEP:4;
    vuint32_t YEAR:4;
    vuint32_t MON:8;
    vuint32_t DAY:8;
  } B;
} M_TTCAN_CREL_tag;

typedef union M_TTCAN_ENDN_union_tag { /* Endian Register */
  vuint32_t R;
  struct {
    vuint32_t ETV:32;
  } B;
} M_TTCAN_ENDN_tag;

typedef union M_TTCAN_FBTP_union_tag { /* Fast Bit Timing and Prescaler Register */
  vuint32_t R;
  struct {
    vuint32_t TDCO:4;                  /* Transceiver Delay Compensation Offset */
    vuint32_t TDC:1;                   /* Transceiver Delay Compensation */
    vuint32_t  :1;
    vuint32_t FBRP:10;                 /* Fast Baud Rate Prescaler */
    vuint32_t  :4;
    vuint32_t FTSEG1:4;                /* Fast time segment before sample point */
    vuint32_t  :1;
    vuint32_t FTSEG2:3;                /* Fast time segment before sample point */
    vuint32_t  :2;
    vuint32_t FSJW:2;                  /* Fast (Re) Synchronization Jump Width */
  } B;
} M_TTCAN_FBTP_tag;

typedef union M_TTCAN_TEST_union_tag { /* Test Register */
  vuint32_t R;
  struct {
    vuint32_t  :19;
    vuint32_t TDCV:5;                  /* Transceiver Delay Compensation Value */
    vuint32_t RX:1;
    vuint32_t TX:2;
    vuint32_t LBCK:1;
    vuint32_t CAT:1;                   /* Check ASC Transmit Control */
    vuint32_t CAM:1;                   /* Check ASC Multiplexer Control */
    vuint32_t TAT:1;                   /* Test ASC Transmit Control */
    vuint32_t TAM:1;                   /* Test ASC Multiplexer Control */
  } B;
} M_TTCAN_TEST_tag;

typedef union M_TTCAN_RWD_union_tag {  /* RAM Watchdog Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t WDV:8;
    vuint32_t WDC:8;
  } B;
} M_TTCAN_RWD_tag;

typedef union M_TTCAN_CCCR_union_tag { /* CC Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :18;
    vuint32_t FDBS:1;                  /* Long Frame Mode Active */
    vuint32_t FDO:1;                   /* Fast Frame Mode Active */
    vuint32_t CMR:2;                   /* CAN Mode Request */
    vuint32_t CME:2;                   /* CAN Mode Enable */
    vuint32_t TEST:1;
    vuint32_t DAR:1;
    vuint32_t MON:1;
    vuint32_t CSR:1;
    vuint32_t CSA:1;
    vuint32_t ASM:1;                   /* ASM Restricted Operation Mode */
    vuint32_t CCE:1;
    vuint32_t INIT:1;
  } B;
} M_TTCAN_CCCR_tag;

typedef union M_TTCAN_BTP_union_tag {  /* Bit Timing and Prescaler Register */
  vuint32_t R;
  struct {
    vuint32_t  :6;
    vuint32_t BRP:10;                  /* Baud Rate Prescaler */
    vuint32_t  :2;
    vuint32_t TSEG1:6;
    vuint32_t TSEG2:4;                 /* Time segment after sample point */
    vuint32_t SJW:4;                   /* (Re) Synchronization Jump Width */
  } B;
} M_TTCAN_BTP_tag;

typedef union M_TTCAN_TSCC_union_tag { /* Timestamp Counter Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t TCP:4;
    vuint32_t  :14;
    vuint32_t TSS:2;
  } B;
} M_TTCAN_TSCC_tag;

typedef union M_TTCAN_TSCV_union_tag { /* Timestamp Counter Value Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t TSC:16;
  } B;
} M_TTCAN_TSCV_tag;

typedef union M_TTCAN_TOCC_union_tag { /* Timeout Counter Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t TOP:16;
    vuint32_t  :13;
    vuint32_t TOS:2;
    vuint32_t ETOC:1;
  } B;
} M_TTCAN_TOCC_tag;

typedef union M_TTCAN_TOCV_union_tag { /* Timeout Counter Value Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t TOC:16;
  } B;
} M_TTCAN_TOCV_tag;

typedef union M_TTCAN_ECR_union_tag {  /* Error Counter Register */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t CEL:8;
    vuint32_t RP:1;
    vuint32_t REC:7;
    vuint32_t TEC:8;
  } B;
} M_TTCAN_ECR_tag;

typedef union M_TTCAN_PSR_union_tag {  /* Protocol Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :18;
    vuint32_t REDL:1;                  /* Received a CAN FD Message */
    vuint32_t RBRS:1;                  /* BRS flag of last received CAN FD Message */
    vuint32_t RESI:1;                  /* ESI CAN FD Message with ESI flag */
    vuint32_t FLEC:3;                  /* Fast Last Error Code */
    vuint32_t BO:1;
    vuint32_t EW:1;
    vuint32_t EP:1;
    vuint32_t ACT:2;
    vuint32_t LEC:3;
  } B;
} M_TTCAN_PSR_tag;

typedef union M_TTCAN_IR_union_tag {   /* Interrupt Register */
  vuint32_t R;
  struct {
    vuint32_t STE:1;
    vuint32_t FOE:1;
    vuint32_t ACKE:1;
    vuint32_t BE:1;
    vuint32_t CRCE:1;
    vuint32_t WDI:1;
    vuint32_t BO:1;
    vuint32_t EW:1;
    vuint32_t EP:1;
    vuint32_t ELO:1;
    vuint32_t BEU:1;
    vuint32_t BEC:1;
    vuint32_t DRX:1;                   /* Message stored to Dedicated Rx Buffer */
    vuint32_t TOO:1;
    vuint32_t UMD:1;
    vuint32_t TSW:1;
    vuint32_t TEFL:1;
    vuint32_t TEFF:1;
    vuint32_t TEFW:1;
    vuint32_t TEFN:1;
    vuint32_t TFE:1;
    vuint32_t TCF:1;
    vuint32_t TC:1;
    vuint32_t HPM:1;
    vuint32_t RF1L:1;
    vuint32_t RF1F:1;
    vuint32_t RF1W:1;
    vuint32_t RF1N:1;
    vuint32_t RF0L:1;
    vuint32_t RF0F:1;
    vuint32_t RF0W:1;
    vuint32_t RF0N:1;
  } B;
} M_TTCAN_IR_tag;

typedef union M_TTCAN_IE_union_tag {   /* Interrupt Enable Register */
  vuint32_t R;
  struct {
    vuint32_t STEE:1;
    vuint32_t FOEE:1;
    vuint32_t ACKEE:1;
    vuint32_t BEE:1;
    vuint32_t CRCEE:1;
    vuint32_t WDIE:1;
    vuint32_t BOE:1;
    vuint32_t EWE:1;
    vuint32_t EPE:1;
    vuint32_t ELOE:1;
    vuint32_t BEUE:1;
    vuint32_t BECE:1;
    vuint32_t DRXE:1;                  /* Message stored to Dedicated Rx Buffer Interrupt Enable */
    vuint32_t TOOE:1;
    vuint32_t UMDE:1;
    vuint32_t TSWE:1;
    vuint32_t TEFLE:1;
    vuint32_t TEFFE:1;
    vuint32_t TEFWE:1;
    vuint32_t TEFNE:1;
    vuint32_t TFEE:1;
    vuint32_t TCFE:1;
    vuint32_t TCE:1;
    vuint32_t HPME:1;
    vuint32_t RF1LE:1;
    vuint32_t RF1FE:1;
    vuint32_t RF1WE:1;
    vuint32_t RF1NE:1;
    vuint32_t RF0LE:1;
    vuint32_t RF0FE:1;
    vuint32_t RF0WE:1;
    vuint32_t RF0NE:1;
  } B;
} M_TTCAN_IE_tag;

typedef union M_TTCAN_ILS_union_tag {  /* Interrupt Line Select Register */
  vuint32_t R;
  struct {
    vuint32_t STEL:1;
    vuint32_t FOEL:1;
    vuint32_t ACKEL:1;
    vuint32_t BEL:1;
    vuint32_t CRCEL:1;
    vuint32_t WDIL:1;
    vuint32_t BOL:1;
    vuint32_t EWL:1;
    vuint32_t EPL:1;
    vuint32_t ELOL:1;
    vuint32_t BEUL:1;
    vuint32_t BECL:1;
    vuint32_t DRXL:1;                  /* Message stored to Dedicated Rx Buffer Interrupt Line */
    vuint32_t TOOL:1;
    vuint32_t UMDL:1;
    vuint32_t TSWL:1;
    vuint32_t TEFLL:1;
    vuint32_t TEFFL:1;
    vuint32_t TEFWL:1;
    vuint32_t TEFNL:1;
    vuint32_t TFEL:1;
    vuint32_t TCFL:1;
    vuint32_t TCL:1;
    vuint32_t HPML:1;
    vuint32_t RF1LL:1;
    vuint32_t RF1FL:1;
    vuint32_t RF1WL:1;
    vuint32_t RF1NL:1;
    vuint32_t RF0LL:1;
    vuint32_t RF0FL:1;
    vuint32_t RF0WL:1;
    vuint32_t RF0NL:1;
  } B;
} M_TTCAN_ILS_tag;

typedef union M_TTCAN_ILE_union_tag {  /* Interrupt Line Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :30;
    vuint32_t EINT1:1;
    vuint32_t EINT0:1;
  } B;
} M_TTCAN_ILE_tag;

typedef union M_TTCAN_GFC_union_tag {  /* Global Filter Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t ANFS:2;
    vuint32_t ANFE:2;
    vuint32_t RRFS:1;
    vuint32_t RRFE:1;
  } B;
} M_TTCAN_GFC_tag;

typedef union M_TTCAN_SIDFC_union_tag { /* Standard ID Filter Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t LSS:8;
    vuint32_t FLSSA:14;
    vuint32_t  :2;
  } B;
} M_TTCAN_SIDFC_tag;

typedef union M_TTCAN_XIDFC_union_tag { /* Extended ID Filter Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :9;
    vuint32_t LSE:7;
    vuint32_t FLESA:14;
    vuint32_t  :2;
  } B;
} M_TTCAN_XIDFC_tag;

typedef union M_TTCAN_XIDAM_union_tag { /* Extended ID and Mask Register */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t EIDM:29;
  } B;
} M_TTCAN_XIDAM_tag;

typedef union M_TTCAN_HPMS_union_tag { /* High Priority Message Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t FLST:1;
    vuint32_t FIDX:7;
    vuint32_t MSI:2;
    vuint32_t BIDX:6;
  } B;
} M_TTCAN_HPMS_tag;

typedef union M_TTCAN_NDAT1_union_tag { /* New Data 1 Register */
  vuint32_t R;
  struct {
    vuint32_t ND1:32;                  /* New Data[0:31] */
  } B;
} M_TTCAN_NDAT1_tag;

typedef union M_TTCAN_NDAT2_union_tag { /* New Data 2 Register */
  vuint32_t R;
  struct {
    vuint32_t ND2:32;                  /* New Data[63:32] */
  } B;
} M_TTCAN_NDAT2_tag;

typedef union M_TTCAN_RXF0C_union_tag { /* Rx FIFO 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t F0WM:7;
    vuint32_t  :1;
    vuint32_t F0S:7;
    vuint32_t FOSA:14;
    vuint32_t  :2;
  } B;
} M_TTCAN_RXF0C_tag;

typedef union M_TTCAN_RXF0S_union_tag { /* Rx FIFO 0 Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :6;
    vuint32_t RF0L:1;
    vuint32_t F0F:1;
    vuint32_t  :2;
    vuint32_t F0PI:6;
    vuint32_t  :2;
    vuint32_t F0GI:6;
    vuint32_t  :1;
    vuint32_t F0FL:7;
  } B;
} M_TTCAN_RXF0S_tag;

typedef union M_TTCAN_RXF0A_union_tag { /* Rx FIFO 0 Acknowledge Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t F0AI:6;
  } B;
} M_TTCAN_RXF0A_tag;

typedef union M_TTCAN_RXBC_union_tag { /* Rx Buffer Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t RBSA:14;                 /* Rx Buffer Start Address */
    vuint32_t  :2;
  } B;
} M_TTCAN_RXBC_tag;

typedef union M_TTCAN_RXF1C_union_tag { /* Rx FIFO 1 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t F1WM:7;
    vuint32_t  :1;
    vuint32_t F1S:7;
    vuint32_t F1SA:14;
    vuint32_t  :2;
  } B;
} M_TTCAN_RXF1C_tag;

typedef union M_TTCAN_RXF1S_union_tag { /* Rx FIFO 1 Status Register */
  vuint32_t R;
  struct {
    vuint32_t DMS:2;                   /* Debug Message Status */
    vuint32_t  :4;
    vuint32_t RF1L:1;
    vuint32_t F1F:1;
    vuint32_t  :2;
    vuint32_t F1PI:6;
    vuint32_t  :2;
    vuint32_t F1GI:6;
    vuint32_t  :1;
    vuint32_t F1FL:7;
  } B;
} M_TTCAN_RXF1S_tag;

typedef union M_TTCAN_RXF1A_union_tag { /* Rx FIFO 1 Acknowledge register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t F1A1:6;
  } B;
} M_TTCAN_RXF1A_tag;

typedef union M_TTCAN_TXBC_union_tag { /* Tx Buffer Configuration register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t TFQM:1;
    vuint32_t TFQS:6;
    vuint32_t  :2;
    vuint32_t NDTB:6;
    vuint32_t TBSA:14;
    vuint32_t  :2;
  } B;
} M_TTCAN_TXBC_tag;

typedef union M_TTCAN_TXFQS_union_tag { /* Tx FIFO/Queue Status register */
  vuint32_t R;
  struct {
    vuint32_t  :10;
    vuint32_t TFQF:1;
    vuint32_t TFQPI:5;
    vuint32_t  :3;
    vuint32_t TFGI:5;
    vuint32_t  :2;
    vuint32_t TFFL:6;
  } B;
} M_TTCAN_TXFQS_tag;

typedef union M_TTCAN_TXBRP_union_tag { /* Tx Buffer Request Pending register */
  vuint32_t R;
  struct {
    vuint32_t TRP:32;
  } B;
} M_TTCAN_TXBRP_tag;

typedef union M_TTCAN_TXBAR_union_tag { /* Tx Buffer Add Request register */
  vuint32_t R;
  struct {
    vuint32_t AR:32;
  } B;
} M_TTCAN_TXBAR_tag;

typedef union M_TTCAN_TXBCR_union_tag { /* Tx Buffer Cancellation Request register */
  vuint32_t R;
  struct {
    vuint32_t CR:32;
  } B;
} M_TTCAN_TXBCR_tag;

typedef union M_TTCAN_TXBTO_union_tag { /* Tx Buffer Transmission Occurred register */
  vuint32_t R;
  struct {
    vuint32_t TO:32;
  } B;
} M_TTCAN_TXBTO_tag;

typedef union M_TTCAN_TXBCF_union_tag { /* Tx Buffer Cancellation Finished register */
  vuint32_t R;
  struct {
    vuint32_t CF:32;
  } B;
} M_TTCAN_TXBCF_tag;

typedef union M_TTCAN_TXBTIE_union_tag { /* Tx Buffer Transmission Interrupt Enable register */
  vuint32_t R;
  struct {
    vuint32_t TIE:32;
  } B;
} M_TTCAN_TXBTIE_tag;

typedef union M_TTCAN_TXBCIE_union_tag { /* Tx Buffer Cancellation Finished Interrupt Enable register */
  vuint32_t R;
  struct {
    vuint32_t CFIE:32;
  } B;
} M_TTCAN_TXBCIE_tag;

typedef union M_TTCAN_TXEFC_union_tag { /* Tx Event FIFO Configuration register */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t EFWM:6;
    vuint32_t  :2;
    vuint32_t EFS:6;
    vuint32_t EFSA:14;
    vuint32_t  :2;
  } B;
} M_TTCAN_TXEFC_tag;

typedef union M_TTCAN_TXEFS_union_tag { /* Tx Event FIFO Status register */
  vuint32_t R;
  struct {
    vuint32_t  :6;
    vuint32_t TEFL:1;
    vuint32_t EFF:1;
    vuint32_t  :3;
    vuint32_t EFPI:5;
    vuint32_t  :3;
    vuint32_t EFGI:5;
    vuint32_t  :2;
    vuint32_t EFFL:6;
  } B;
} M_TTCAN_TXEFS_tag;

typedef union M_TTCAN_TXEFA_union_tag { /* Tx Event FIFO Acknowledge register */
  vuint32_t R;
  struct {
    vuint32_t  :27;
    vuint32_t EFAI:5;
  } B;
} M_TTCAN_TXEFA_tag;

typedef union M_TTCAN_TTTMC_union_tag { /* TT Trigger Memory Configuration register */
  vuint32_t R;
  struct {
    vuint32_t  :9;
    vuint32_t TME:7;
    vuint32_t TMSA:14;
    vuint32_t  :2;
  } B;
} M_TTCAN_TTTMC_tag;

typedef union M_TTCAN_TTRMC_union_tag { /* TT Reference Message Configuration register */
  vuint32_t R;
  struct {
    vuint32_t RMPS:1;
    vuint32_t XTD:1;
    vuint32_t  :1;
    vuint32_t RID:29;
  } B;
} M_TTCAN_TTRMC_tag;

typedef union M_TTCAN_TTOCF_union_tag { /* TT Operation Configuration register */
  vuint32_t R;
  struct {
    vuint32_t  :5;
    vuint32_t EVTP:1;
    vuint32_t ECC:1;
    vuint32_t EGTF:1;
    vuint32_t AWL:8;
    vuint32_t EECS:1;
    vuint32_t IRTO:7;
    vuint32_t LDSDL:3;
    vuint32_t TM:1;
    vuint32_t GEN:1;
    vuint32_t  :1;
    vuint32_t OM:2;
  } B;
} M_TTCAN_TTOCF_tag;

typedef union M_TTCAN_TTMLM_union_tag { /* TT Matrix Limits register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t ENTT:12;
    vuint32_t  :4;
    vuint32_t TXEW:4;
    vuint32_t CSS:2;                   /* Cycle Start Synchronization */
    vuint32_t CCM:6;
  } B;
} M_TTCAN_TTMLM_tag;

typedef union M_TTCAN_TURCF_union_tag { /* TUR Configuration register */
  vuint32_t R;
  struct {
    vuint32_t ELT:1;
    vuint32_t  :1;
    vuint32_t DC:14;
    vuint32_t NCL:16;
  } B;
} M_TTCAN_TURCF_tag;

typedef union M_TTCAN_TTOCN_union_tag { /* TT Operation Control register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t LCKC:1;
    vuint32_t  :1;
    vuint32_t ESCN:1;
    vuint32_t NIG:1;
    vuint32_t TMG:1;
    vuint32_t FGP:1;
    vuint32_t GCS:1;
    vuint32_t TTIE:1;                  /* Trigger Time Mark Interrupt Pulse Enable */
    vuint32_t TMC:2;
    vuint32_t RTIE:1;
    vuint32_t SWS:2;
    vuint32_t SWP:1;
    vuint32_t ECS:1;
    vuint32_t SGT:1;
  } B;
} M_TTCAN_TTOCN_tag;

typedef union M_TTCAN_TTGTP_union_tag { /* TT Global Time Preset register */
  vuint32_t R;
  struct {
    vuint32_t CTP:16;
    vuint32_t TP:16;
  } B;
} M_TTCAN_TTGTP_tag;

typedef union M_TTCAN_TTTMK_union_tag { /* TT Time Mark register */
  vuint32_t R;
  struct {
    vuint32_t LCKM:1;
    vuint32_t  :8;
    vuint32_t TICC:7;
    vuint32_t TM:16;
  } B;
} M_TTCAN_TTTMK_tag;

typedef union M_TTCAN_TTIR_union_tag { /* TT Interrupt Register */
  vuint32_t R;
  struct {
    vuint32_t  :13;
    vuint32_t CER:1;
    vuint32_t AW:1;
    vuint32_t WT:1;
    vuint32_t IWT:1;
    vuint32_t ELC:1;
    vuint32_t SE2:1;
    vuint32_t SE1:1;
    vuint32_t TXO:1;
    vuint32_t TXU:1;
    vuint32_t GTE:1;
    vuint32_t GTD:1;
    vuint32_t GTW:1;
    vuint32_t SWE:1;
    vuint32_t TTMI:1;
    vuint32_t RTMI:1;
    vuint32_t SOG:1;
    vuint32_t CSM:1;
    vuint32_t SMC:1;
    vuint32_t SBC:1;
  } B;
} M_TTCAN_TTIR_tag;

typedef union M_TTCAN_TTIE_union_tag { /* TT Interrupt Enable register */
  vuint32_t R;
  struct {
    vuint32_t  :13;
    vuint32_t CERE:1;
    vuint32_t AWE:1;
    vuint32_t WTE:1;
    vuint32_t IWTE:1;
    vuint32_t ELCE:1;
    vuint32_t SE2E:1;
    vuint32_t SE1E:1;
    vuint32_t TXOE:1;
    vuint32_t TXUE:1;
    vuint32_t GTEE:1;
    vuint32_t GTDE:1;
    vuint32_t GTWE:1;
    vuint32_t SWEE:1;
    vuint32_t TTMIE:1;
    vuint32_t RTMIE:1;
    vuint32_t SOGE:1;
    vuint32_t CSME:1;
    vuint32_t SMCE:1;
    vuint32_t SBCE:1;
  } B;
} M_TTCAN_TTIE_tag;

typedef union M_TTCAN_TTILS_union_tag { /* TT Interrupt Line Select register */
  vuint32_t R;
  struct {
    vuint32_t  :13;
    vuint32_t CERL:1;
    vuint32_t AWL:1;
    vuint32_t WTL:1;
    vuint32_t IWTL:1;
    vuint32_t ELCL:1;
    vuint32_t SE2L:1;
    vuint32_t SE1L:1;
    vuint32_t TXOL:1;
    vuint32_t TXUL:1;
    vuint32_t GTEL:1;
    vuint32_t GTDL:1;
    vuint32_t GTWE:1;
    vuint32_t SWEL:1;
    vuint32_t TTMIL:1;
    vuint32_t RTMIL:1;
    vuint32_t SOGL:1;
    vuint32_t CSML:1;
    vuint32_t SMCL:1;
    vuint32_t SBCL:1;
  } B;
} M_TTCAN_TTILS_tag;

typedef union M_TTCAN_TTOST_union_tag { /* TT Operation Status register */
  vuint32_t R;
  struct {
    vuint32_t SPL:1;
    vuint32_t WECS:1;
    vuint32_t AWE:1;
    vuint32_t WFE:1;
    vuint32_t GSI:1;
    vuint32_t TMP:3;
    vuint32_t GFI:1;
    vuint32_t WGTD:1;
    vuint32_t  :6;
    vuint32_t RTO:8;
    vuint32_t QCS:1;
    vuint32_t QGTP:1;
    vuint32_t SYS:2;
    vuint32_t MS:2;
    vuint32_t EL:2;
  } B;
} M_TTCAN_TTOST_tag;

typedef union M_TTCAN_TURNA_union_tag { /* TUR Numerator Actual register */
  vuint32_t R;
  struct {
    vuint32_t  :14;
    vuint32_t NAV:18;
  } B;
} M_TTCAN_TURNA_tag;

typedef union M_TTCAN_TTLGT_union_tag { /* TT Local and Global Time register */
  vuint32_t R;
  struct {
    vuint32_t GT:16;
    vuint32_t LT:16;
  } B;
} M_TTCAN_TTLGT_tag;

typedef union M_TTCAN_TTCTC_union_tag { /* TT Cycle Time and Count register */
  vuint32_t R;
  struct {
    vuint32_t  :10;
    vuint32_t CC:6;
    vuint32_t CT:16;
  } B;
} M_TTCAN_TTCTC_tag;

typedef union M_TTCAN_TTCPT_union_tag { /* TT Capture Time register */
  vuint32_t R;
  struct {
    vuint32_t SWV:16;
    vuint32_t  :10;
    vuint32_t CCV:6;
  } B;
} M_TTCAN_TTCPT_tag;

typedef union M_TTCAN_TTCSM_union_tag { /* TT Cycle Sync Mark register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t CSM:16;
  } B;
} M_TTCAN_TTCSM_tag;

struct M_TTCAN_tag {
  M_TTCAN_CREL_tag CREL;               /* Core Release Register */
  M_TTCAN_ENDN_tag ENDN;               /* Endian Register */
  uint8_t M_TTCAN_reserved0[4];
  M_TTCAN_FBTP_tag FBTP;               /* Fast Bit Timing and Prescaler Register */
  M_TTCAN_TEST_tag TEST;               /* Test Register */
  M_TTCAN_RWD_tag RWD;                 /* RAM Watchdog Register */
  M_TTCAN_CCCR_tag CCCR;               /* CC Control Register */
  M_TTCAN_BTP_tag BTP;                 /* Bit Timing and Prescaler Register */
  M_TTCAN_TSCC_tag TSCC;               /* Timestamp Counter Configuration Register */
  M_TTCAN_TSCV_tag TSCV;               /* Timestamp Counter Value Register */
  M_TTCAN_TOCC_tag TOCC;               /* Timeout Counter Configuration Register */
  M_TTCAN_TOCV_tag TOCV;               /* Timeout Counter Value Register */
  uint8_t M_TTCAN_reserved1[16];
  M_TTCAN_ECR_tag ECR;                 /* Error Counter Register */
  M_TTCAN_PSR_tag PSR;                 /* Protocol Status Register */
  uint8_t M_TTCAN_reserved2[8];
  M_TTCAN_IR_tag IR;                   /* Interrupt Register */
  M_TTCAN_IE_tag IE;                   /* Interrupt Enable Register */
  M_TTCAN_ILS_tag ILS;                 /* Interrupt Line Select Register */
  M_TTCAN_ILE_tag ILE;                 /* Interrupt Line Enable Register */
  uint8_t M_TTCAN_reserved3[32];
  M_TTCAN_GFC_tag GFC;                 /* Global Filter Configuration Register */
  M_TTCAN_SIDFC_tag SIDFC;             /* Standard ID Filter Configuration Register */
  M_TTCAN_XIDFC_tag XIDFC;             /* Extended ID Filter Configuration Register */
  uint8_t M_TTCAN_reserved4[4];
  M_TTCAN_XIDAM_tag XIDAM;             /* Extended ID and Mask Register */
  M_TTCAN_HPMS_tag HPMS;               /* High Priority Message Status Register */
  M_TTCAN_NDAT1_tag NDAT1;             /* New Data 1 Register */
  M_TTCAN_NDAT2_tag NDAT2;             /* New Data 2 Register */
  M_TTCAN_RXF0C_tag RXF0C;             /* Rx FIFO 0 Configuration Register */
  M_TTCAN_RXF0S_tag RXF0S;             /* Rx FIFO 0 Status Register */
  M_TTCAN_RXF0A_tag RXF0A;             /* Rx FIFO 0 Acknowledge Register */
  M_TTCAN_RXBC_tag RXBC;               /* Rx Buffer Configuration Register */
  M_TTCAN_RXF1C_tag RXF1C;             /* Rx FIFO 1 Configuration Register */
  M_TTCAN_RXF1S_tag RXF1S;             /* Rx FIFO 1 Status Register */
  M_TTCAN_RXF1A_tag RXF1A;             /* Rx FIFO 1 Acknowledge register */
  uint8_t M_TTCAN_reserved5[4];
  M_TTCAN_TXBC_tag TXBC;               /* Tx Buffer Configuration register */
  M_TTCAN_TXFQS_tag TXFQS;             /* Tx FIFO/Queue Status register */
  uint8_t M_TTCAN_reserved6[4];
  M_TTCAN_TXBRP_tag TXBRP;             /* Tx Buffer Request Pending register */
  M_TTCAN_TXBAR_tag TXBAR;             /* Tx Buffer Add Request register */
  M_TTCAN_TXBCR_tag TXBCR;             /* Tx Buffer Cancellation Request register */
  M_TTCAN_TXBTO_tag TXBTO;             /* Tx Buffer Transmission Occurred register */
  M_TTCAN_TXBCF_tag TXBCF;             /* Tx Buffer Cancellation Finished register */
  M_TTCAN_TXBTIE_tag TXBTIE;           /* Tx Buffer Transmission Interrupt Enable register */
  M_TTCAN_TXBCIE_tag TXBCIE;           /* Tx Buffer Cancellation Finished Interrupt Enable register */
  uint8_t M_TTCAN_reserved7[8];
  M_TTCAN_TXEFC_tag TXEFC;             /* Tx Event FIFO Configuration register */
  M_TTCAN_TXEFS_tag TXEFS;             /* Tx Event FIFO Status register */
  M_TTCAN_TXEFA_tag TXEFA;             /* Tx Event FIFO Acknowledge register */
  uint8_t M_TTCAN_reserved8[4];
  M_TTCAN_TTTMC_tag TTTMC;             /* TT Trigger Memory Configuration register */
  M_TTCAN_TTRMC_tag TTRMC;             /* TT Reference Message Configuration register */
  M_TTCAN_TTOCF_tag TTOCF;             /* TT Operation Configuration register */
  M_TTCAN_TTMLM_tag TTMLM;             /* TT Matrix Limits register */
  M_TTCAN_TURCF_tag TURCF;             /* TUR Configuration register */
  M_TTCAN_TTOCN_tag TTOCN;             /* TT Operation Control register */
  M_TTCAN_TTGTP_tag TTGTP;             /* TT Global Time Preset register */
  M_TTCAN_TTTMK_tag TTTMK;             /* TT Time Mark register */
  M_TTCAN_TTIR_tag TTIR;               /* TT Interrupt Register */
  M_TTCAN_TTIE_tag TTIE;               /* TT Interrupt Enable register */
  M_TTCAN_TTILS_tag TTILS;             /* TT Interrupt Line Select register */
  M_TTCAN_TTOST_tag TTOST;             /* TT Operation Status register */
  M_TTCAN_TURNA_tag TURNA;             /* TUR Numerator Actual register */
  M_TTCAN_TTLGT_tag TTLGT;             /* TT Local and Global Time register */
  M_TTCAN_TTCTC_tag TTCTC;             /* TT Cycle Time and Count register */
  M_TTCAN_TTCPT_tag TTCPT;             /* TT Capture Time register */
  M_TTCAN_TTCSM_tag TTCSM;             /* TT Cycle Sync Mark register */
};

#endif
