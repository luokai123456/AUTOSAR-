#ifndef M_CAN_REG_H_
#define M_CAN_REG_H_

/* ============================================================================
   =============================== Module: M_CAN ==============================
   ============================================================================ */

typedef union M_CAN_CREL_union_tag {   /* Core Release Register */
  vuint32_t R;
  struct {
    vuint32_t REL:4;
    vuint32_t STEP:4;
    vuint32_t SUBSTEP:4;
    vuint32_t YEAR:4;
    vuint32_t MON:8;
    vuint32_t DAY:8;
  } B;
} M_CAN_CREL_tag;

typedef union M_CAN_ENDN_union_tag {   /* Endian Register */
  vuint32_t R;
  struct {
    vuint32_t ETV:32;
  } B;
} M_CAN_ENDN_tag;

typedef union M_CAN_DBTP_union_tag {
  vuint32_t R;
  struct {
    vuint32_t     :8;
    vuint32_t TDC :1;
    vuint32_t     :2;
    vuint32_t DBRP:5;
    vuint32_t     :3;
    vuint32_t DTSEG1:5;
    vuint32_t DTSEG2:4;
    vuint32_t DSJW  :4;
  } B;
} M_CAN_DBTP_tag;

typedef union M_CAN_TEST_union_tag {   /* Test Register */
  vuint32_t R;
  struct {
    vuint32_t     :10;
    vuint32_t SVAL :1;
    vuint32_t TXBNS:5;
    vuint32_t     :2;
    vuint32_t PVAL :1;
    vuint32_t TXBNP:5;
    vuint32_t RX   :1;
    vuint32_t TX   :2;
    vuint32_t LBCK :1;
    vuint32_t     :4;
  } B;
} M_CAN_TEST_tag;

typedef union M_CAN_RWD_union_tag {    /* RAM Watchdog Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t WDV:8;
    vuint32_t WDC:8;
  } B;
} M_CAN_RWD_tag;

typedef union M_CAN_CCCR_union_tag {   /* CC Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t NISO :1;
    vuint32_t TXP  :1;
    vuint32_t EFBI :1;
    vuint32_t PXHD :1;
    vuint32_t WMM  :1;
    vuint32_t UTSU :1;
    vuint32_t BRSE :1;
    vuint32_t FDOE :1;
    vuint32_t TEST :1;
    vuint32_t DAR  :1;
    vuint32_t MON  :1;
    vuint32_t CSR  :1;
    vuint32_t CSA  :1;
    vuint32_t ASM  :1;
    vuint32_t CCE  :1;
    vuint32_t INIT :1;
  } B;
} M_CAN_CCCR_tag;

typedef union M_CAN_NBTP_union_tag {    /* Bit Timing and Prescaler Register */
  vuint32_t R;
  struct {
    vuint32_t NSJW   :7;
    vuint32_t NBRP   :9;
    vuint32_t NTSEG1 :8;
    vuint32_t        :1;
    vuint32_t NTSEG2 :7;
  } B;
} M_CAN_NBTP_tag;

typedef union M_CAN_TSCC_union_tag {   /* Timestamp Counter Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t TCP:4;
    vuint32_t  :14;
    vuint32_t TSS:2;
  } B;
} M_CAN_TSCC_tag;

typedef union M_CAN_TSCV_union_tag {   /* Timestamp Counter Value Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t TSC:16;                  /* Timestamp Counter */
  } B;
} M_CAN_TSCV_tag;

typedef union M_CAN_TOCC_union_tag {   /* Timeout Counter Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t TOP:16;
    vuint32_t  :13;
    vuint32_t TOS:2;
    vuint32_t ETOC:1;
  } B;
} M_CAN_TOCC_tag;

typedef union M_CAN_TOCV_union_tag {   /* Timeout Counter Value Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t TOC:16;
  } B;
} M_CAN_TOCV_tag;

typedef union M_CAN_ECR_union_tag {    /* Error Counter Register */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t CEL:8;
    vuint32_t RP:1;
    vuint32_t REC:7;
    vuint32_t TEC:8;
  } B;
} M_CAN_ECR_tag;

typedef union M_CAN_PSR_union_tag {    /* Protocol Status Register */
  vuint32_t R;
  struct {
    vuint32_t     :9;
    vuint32_t TDCV:7;
    vuint32_t     :1;
    vuint32_t PXE :1;
    vuint32_t RFDF:1;
    vuint32_t RBRS:1;
    vuint32_t RESI:1;
    vuint32_t DLEC:3;
    vuint32_t BO  :1;
    vuint32_t EW  :1;
    vuint32_t EP  :1;
    vuint32_t ACT :2;
    vuint32_t LEC :3;
  } B;
} M_CAN_PSR_tag;

typedef union M_CAN_TDCR_union_tag {
  vuint32_t R;
  struct {
    vuint32_t     :17;
    vuint32_t TDCO:7;
    vuint32_t     :1;
    vuint32_t TDCF:7;
  } B;
} M_CAN_TDCR_tag;
typedef union M_CAN_IR_union_tag {     /* Interrupt Register */
  vuint32_t R;
  struct {
    vuint32_t    :2;
    vuint32_t ARA:1;
    vuint32_t PED:1;
    vuint32_t PEA:1;
    vuint32_t WDI:1;
    vuint32_t BO:1;
    vuint32_t EW:1;
    vuint32_t EP:1;
    vuint32_t ELO:1;
    vuint32_t BEU:1;
    vuint32_t BEC:1;
    vuint32_t DRX:1;                   /* Message stored to Dedicated Rx Buffer */
    vuint32_t TOO:1;
    vuint32_t MRAF:1;                  /* Message RAM Access Failure */
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
} M_CAN_IR_tag;

typedef union M_CAN_IE_union_tag {     /* Interrupt Enable Register */
  vuint32_t R;
  struct {
    vuint32_t    :2;
    vuint32_t ARAE:1;
    vuint32_t PEDE:1;
    vuint32_t PEAE:1;
    vuint32_t WDIE:1;
    vuint32_t BOE:1;
    vuint32_t EWE:1;
    vuint32_t EPE:1;
    vuint32_t ELOE:1;
    vuint32_t BEUE:1;
    vuint32_t BECE:1;
    vuint32_t DRXE:1;                  /* Message stored to Dedicated Rx Buffer Interrupt Enable */
    vuint32_t TOOE:1;
    vuint32_t MRAFE:1;
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
} M_CAN_IE_tag;

typedef union M_CAN_ILS_union_tag {    /* Interrupt Line Select Register */
  vuint32_t R;
  struct {
    vuint32_t    :2;
    vuint32_t ARAL:1;
    vuint32_t PEDL:1;
    vuint32_t PEAL:1;
    vuint32_t WDIL:1;
    vuint32_t BOL:1;
    vuint32_t EWL:1;
    vuint32_t EPL:1;
    vuint32_t ELOL:1;
    vuint32_t BEUL:1;
    vuint32_t BECL:1;
    vuint32_t DRXL:1;                  /* Message stored to Dedicated Rx Buffer Interrupt Line */
    vuint32_t TOOL:1;
    vuint32_t MRAFL:1;
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
} M_CAN_ILS_tag;

typedef union M_CAN_ILE_union_tag {    /* Interrupt Line Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :30;
    vuint32_t EINT1:1;
    vuint32_t EINT0:1;
  } B;
} M_CAN_ILE_tag;

typedef union M_CAN_GFC_union_tag {    /* Global Filter Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t ANFS:2;
    vuint32_t ANFE:2;
    vuint32_t RRFS:1;
    vuint32_t RRFE:1;
  } B;
} M_CAN_GFC_tag;

typedef union M_CAN_SIDFC_union_tag {  /* Standard ID Filter Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t LSS:8;
    vuint32_t FLSSA:14;
    vuint32_t  :2;
  } B;
} M_CAN_SIDFC_tag;

typedef union M_CAN_XIDFC_union_tag {  /* Extended ID Filter Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :9;
    vuint32_t LSE:7;
    vuint32_t FLESA:14;
    vuint32_t  :2;
  } B;
} M_CAN_XIDFC_tag;

typedef union M_CAN_XIDAM_union_tag {  /* Extended ID and Mask Register */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t EIDM:29;
  } B;
} M_CAN_XIDAM_tag;

typedef union M_CAN_HPMS_union_tag {   /* High Priority Message Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t FLST:1;
    vuint32_t FIDX:7;
    vuint32_t MSI:2;
    vuint32_t BIDX:6;
  } B;
} M_CAN_HPMS_tag;

typedef union M_CAN_NDAT1_union_tag {  /* New Data 1 Register */
  vuint32_t R;
  struct {
    vuint32_t ND1:32;                  /* New Data[0:31] */
  } B;
} M_CAN_NDAT1_tag;

typedef union M_CAN_NDAT2_union_tag {  /* New Data 2 Register */
  vuint32_t R;
  struct {
    vuint32_t ND2:32;                  /* New Data[32:63] */
  } B;
} M_CAN_NDAT2_tag;

typedef union M_CAN_RXF0C_union_tag {  /* Rx FIFO 0 Configuration */
  vuint32_t R;
  struct {
    vuint32_t F0OM:1;                  /* FIFO 0 Operation Mode */
    vuint32_t F0WM:7;
    vuint32_t  :1;
    vuint32_t F0S:7;
    vuint32_t F0SA:14;
    vuint32_t  :2;
  } B;
} M_CAN_RXF0C_tag;

typedef union M_CAN_RXF0S_union_tag {  /* Rx FIFO 0 Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :6;
    vuint32_t RF0L:1;
    vuint32_t F0F:1;
    vuint32_t  :2;
    vuint32_t F0PI:6;                  /* Rx FIFO 0 Put Index */
    vuint32_t  :2;
    vuint32_t F0GI:6;
    vuint32_t  :1;
    vuint32_t F0FL:7;
  } B;
} M_CAN_RXF0S_tag;

typedef union M_CAN_RXF0A_union_tag {  /* Rx FIFO 0 Acknowledge Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t F0AI:6;
  } B;
} M_CAN_RXF0A_tag;

typedef union M_CAN_RXBC_union_tag {   /* Rx Buffer Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t RBSA:14;                 /* Rx Buffer Start Address */
    vuint32_t  :2;
  } B;
} M_CAN_RXBC_tag;

typedef union M_CAN_RXF1C_union_tag {  /* Rx FIFO 1 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t F1OM:1;                  /* FIFO 1 Operation Mode */
    vuint32_t F1WM:7;
    vuint32_t  :1;
    vuint32_t F1S:7;
    vuint32_t F1SA:14;
    vuint32_t  :2;
  } B;
} M_CAN_RXF1C_tag;

typedef union M_CAN_RXF1S_union_tag {  /* Rx FIFO 1 Status Register */
  vuint32_t R;
  struct {
    vuint32_t DMS:2;
    vuint32_t  :4;
    vuint32_t RF1L:1;
    vuint32_t F1F:1;
    vuint32_t  :2;
    vuint32_t F1PI:6;                  /* Rx FIFO 1 Put Index */
    vuint32_t  :2;
    vuint32_t F1G1:6;
    vuint32_t  :1;
    vuint32_t F1FL:7;
  } B;
} M_CAN_RXF1S_tag;

typedef union M_CAN_RXF1A_union_tag {  /* Rx FIFO 1 Acknowledge Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t F1AI:6;
  } B;
} M_CAN_RXF1A_tag;

typedef union M_CAN_RXESC_union_tag {  /* Rx Buffer / FIFO Element Size Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :21;
    vuint32_t RBDS:3;                  /* Rx Buffer Data Field Size */
    vuint32_t  :1;
    vuint32_t F1DS:3;                  /* Rx FIFO 1 Data Field Size */
    vuint32_t  :1;
    vuint32_t F0DS:3;                  /* Rx FIFO 0 Data Field Size */
  } B;
} M_CAN_RXESC_tag;

typedef union M_CAN_TXBC_union_tag {   /* Tx Buffer Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t TQFM:1;
    vuint32_t TQFS:6;
    vuint32_t  :2;
    vuint32_t NDTB:6;
    vuint32_t TBSA:14;
    vuint32_t  :2;
  } B;
} M_CAN_TXBC_tag;

typedef union M_CAN_TXFQS_union_tag {  /* Tx FIFO/Queue Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :10;
    vuint32_t TFQF:1;
    vuint32_t TFQPI:5;
    vuint32_t  :3;
    vuint32_t TFGI:5;                  /* Tx FIFO Get Index */
    vuint32_t  :2;
    vuint32_t TFFL:6;
  } B;
} M_CAN_TXFQS_tag;

typedef union M_CAN_TXESC_union_tag {  /* Tx Buffer Element Size Configuration */
  vuint32_t R;
  struct {
    vuint32_t  :29;
    vuint32_t TBDS:3;
  } B;
} M_CAN_TXESC_tag;

typedef union M_CAN_TXBRP_union_tag {  /* Tx Buffer Request Pending Register */
  vuint32_t R;
  struct {
    vuint32_t TRP:32;                  /* Transmission Request Pending */
  } B;
} M_CAN_TXBRP_tag;

typedef union M_CAN_TXBAR_union_tag {  /* Tx Buffer Add Request register */
  vuint32_t R;
  struct {
    vuint32_t AR:32;                   /* Add Request */
  } B;
} M_CAN_TXBAR_tag;

typedef union M_CAN_TXBCR_union_tag {  /* Tx Buffer Cancellation Request register */
  vuint32_t R;
  struct {
    vuint32_t CR:32;                   /* Cancellation Request */
  } B;
} M_CAN_TXBCR_tag;

typedef union M_CAN_TXBTO_union_tag {  /* Tx Buffer Transmission Occurred register */
  vuint32_t R;
  struct {
    vuint32_t TO:32;                   /* Transmission Occurred */
  } B;
} M_CAN_TXBTO_tag;

typedef union M_CAN_TXBCF_union_tag {  /* Tx Buffer Cancellation Finished register */
  vuint32_t R;
  struct {
    vuint32_t CF:32;                   /* Cancellation Finished */
  } B;
} M_CAN_TXBCF_tag;

typedef union M_CAN_TXBTIE_union_tag { /* Tx Buffer Transmission Interrupt Enable register */
  vuint32_t R;
  struct {
    vuint32_t TIE:32;
  } B;
} M_CAN_TXBTIE_tag;

typedef union M_CAN_TXBCIE_union_tag { /* Tx Buffer Cancellation Finished Interrupt Enable register */
  vuint32_t R;
  struct {
    vuint32_t CFIE:32;
  } B;
} M_CAN_TXBCIE_tag;

typedef union M_CAN_TXEFC_union_tag {  /* Tx Event FIFO Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t EFWM:6;
    vuint32_t  :2;
    vuint32_t EFS:6;
    vuint32_t EFSA:14;
    vuint32_t  :2;
  } B;
} M_CAN_TXEFC_tag;

typedef union M_CAN_TXEFS_union_tag {  /* Tx Event FIFO Status register */
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
} M_CAN_TXEFS_tag;

typedef union M_CAN_TXEFA_union_tag {  /* Tx Event FIFO Acknowledge register */
  vuint32_t R;
  struct {
    vuint32_t  :27;
    vuint32_t EFAI:5;
  } B;
} M_CAN_TXEFA_tag;

/* ============================================================================
   =============================== Module: M_CAN-TSU ==========================
   ============================================================================ */
typedef union M_CAN_TSU_CREL_union_tag {  /* Core Release Register */
  vuint32_t R;
  struct {
    vuint32_t REL:4;
    vuint32_t STEP:4;
    vuint32_t SUBSTEP:4;
    vuint32_t YEAR:4;
    vuint32_t MON:8;
    vuint32_t DAY:8;
  } B;
} M_CAN_TSU_CREL_tag;

typedef union M_CAN_TSCFG_union_tag {  /* Timestamp Configuration TSCFG */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t TBPRE:8;
    vuint32_t  :5;
    vuint32_t SCP:1;
    vuint32_t TBCS:1;
    vuint32_t TSUE:1;
  } B;
} M_CAN_TSCFG_tag;

typedef union M_CAN_TSS1_union_tag {  /* Timestamp Status 1 TSS1 */
  vuint32_t R;
  struct {
    vuint32_t TSL15:1;
    vuint32_t TSL14:1;
    vuint32_t TSL13:1;
    vuint32_t TSL12:1;
    vuint32_t TSL11:1;
    vuint32_t TSL10:1;
    vuint32_t TSL9:1;
    vuint32_t TSL8:1;
    vuint32_t TSL7:1;
    vuint32_t TSL6:1;
    vuint32_t TSL5:1;
    vuint32_t TSL4:1;
    vuint32_t TSL3:1;
    vuint32_t TSL2:1;
    vuint32_t TSL1:1;
    vuint32_t TSL0:1;
    vuint32_t TSN15:1;
    vuint32_t TSN14:1;
    vuint32_t TSN13:1;
    vuint32_t TSN12:1;
    vuint32_t TSN11:1;
    vuint32_t TSN10:1;
    vuint32_t TSN9:1;
    vuint32_t TSN8:1;
    vuint32_t TSN7:1;
    vuint32_t TSN6:1;
    vuint32_t TSN5:1;
    vuint32_t TSN4:1;
    vuint32_t TSN3:1;
    vuint32_t TSN2:1;
    vuint32_t TSN1:1;
    vuint32_t TSN0:1;
  } B;
} M_CAN_TSS1_tag;

typedef union M_CAN_TSS2_union_tag {  /* Timestamp Status 2 TSS2 */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t ITBG:2;
    vuint32_t NTSG:2;
    vuint32_t  :8;
    vuint32_t TSP:4;
  } B;
} M_CAN_TSS2_tag;

typedef union M_CAN_TS0_union_tag {  /* Timestamp 0 TS0 */
  vuint32_t R;
  struct {
    vuint32_t TS:32;
  } B;
} M_CAN_TS0_tag;

typedef union M_CAN_TS1_union_tag {  /* Timestamp 1 TS1 */
  vuint32_t R;
  struct {
    vuint32_t TS:32;
  } B;
} M_CAN_TS1_tag;

typedef union M_CAN_TS2_union_tag {  /* Timestamp 2 TS2 */
  vuint32_t R;
  struct {
    vuint32_t TS:32;
  } B;
} M_CAN_TS2_tag;

typedef union M_CAN_TS3_union_tag {  /* Timestamp 3 TS3 */
  vuint32_t R;
  struct {
    vuint32_t TS:32;
  } B;
} M_CAN_TS3_tag;

typedef union M_CAN_TS4_union_tag {  /* Timestamp 4 TS4 */
  vuint32_t R;
  struct {
    vuint32_t TS:32;
  } B;
} M_CAN_TS4_tag;

typedef union M_CAN_TS5_union_tag {  /* Timestamp 5 TS5 */
  vuint32_t R;
  struct {
    vuint32_t TS:32;
  } B;
} M_CAN_TS5_tag;

typedef union M_CAN_TS6_union_tag {  /* Timestamp 6 TS6 */
  vuint32_t R;
  struct {
    vuint32_t TS:32;
  } B;
} M_CAN_TS6_tag;

typedef union M_CAN_TS7_union_tag {  /* Timestamp 7 TS7 */
  vuint32_t R;
  struct {
    vuint32_t TS:32;
  } B;
} M_CAN_TS7_tag;
typedef union M_CAN_TS8_union_tag {  /* Timestamp 8 TS8 */
  vuint32_t R;
  struct {
    vuint32_t TS:32;
  } B;
} M_CAN_TS8_tag;

typedef union M_CAN_TS9_union_tag {  /* Timestamp 9 TS9 */
  vuint32_t R;
  struct {
    vuint32_t TS:32;
  } B;
} M_CAN_TS9_tag;

typedef union M_CAN_TS10_union_tag {  /* Timestamp 10 TS10 */
  vuint32_t R;
  struct {
    vuint32_t TS:32;
  } B;
} M_CAN_TS10_tag;

typedef union M_CAN_TS11_union_tag {  /* Timestamp 11 TS11 */
  vuint32_t R;
  struct {
    vuint32_t TS:32;
  } B;
} M_CAN_TS11_tag;
typedef union M_CAN_TS12_union_tag {  /* Timestamp 12 TS12 */
  vuint32_t R;
  struct {
    vuint32_t TS:32;
  } B;
} M_CAN_TS12_tag;

typedef union M_CAN_TS13_union_tag {  /* Timestamp 13 TS13 */
  vuint32_t R;
  struct {
    vuint32_t TS:32;
  } B;
} M_CAN_TS13_tag;

typedef union M_CAN_TS14_union_tag {  /* Timestamp 14 TS14 */
  vuint32_t R;
  struct {
    vuint32_t TS:32;
  } B;
} M_CAN_TS14_tag;

typedef union M_CAN_TS15_union_tag {  /* Timestamp 15 TS15 */
  vuint32_t R;
  struct {
    vuint32_t TS:32;
  } B;
} M_CAN_TS15_tag;

typedef union M_CAN_TSU_ATB_union_tag {  /* Timestamp 15 TS15 */
  vuint32_t R;
  struct {
    vuint32_t TB:32;
  } B;
} M_CAN_TSU_ATB_tag;
/* ============================================================================
   =============================== Module: M_CAN-DMU ==========================
   ============================================================================ */
typedef union M_CAN_DMUCR_union_tag {  /* DMU Core Release Register */
  vuint32_t R;
  struct {
    vuint32_t REL:4;
    vuint32_t STEP:4;
    vuint32_t SUBSTEP:4;
    vuint32_t YEAR:4;
    vuint32_t MON:8;
    vuint32_t DAY:8;
  } B;
} M_CAN_DMUCR_tag;

typedef union M_CAN_DMUI_union_tag {  /* DMU Internals Register */
  vuint32_t R;
  struct {
    vuint32_t TXE:1;
    vuint32_t RX1:1;
    vuint32_t RX0:1;
    vuint32_t TX:1;
    vuint32_t  :1;
    vuint32_t EHS:3;
    vuint32_t DTXE:1;
    vuint32_t DRX1:1;
    vuint32_t DRX0:1;
    vuint32_t DTX:1;
    vuint32_t  :1;
    vuint32_t DEHS:3;
    vuint32_t ENA:1;
    vuint32_t  :2;
    vuint32_t TFQPIP:5;
    vuint32_t  :4;
    vuint32_t TXER:1;
    vuint32_t RX1R:1;
    vuint32_t RX0R:1;
    vuint32_t TXR:1;
  } B;
} M_CAN_DMUI_tag;

typedef union M_CAN_DMUQC_union_tag {  /* DMU Queueing Counter Register */
  vuint32_t R;
  struct {
    vuint32_t TXEEDC:8;
    vuint32_t RX1EDC:8;
    vuint32_t RX0EDC:8;
    vuint32_t TXEEC:8;
  } B;
} M_CAN_DMUQC_tag;

typedef union M_CAN_DMUIR_union_tag {  /* DMU Interrupt Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t IAC:1;
    vuint32_t DT:1;
    vuint32_t TXEED:1;
    vuint32_t TXEEIW:1;
    vuint32_t TXEEIAS:1;
    vuint32_t TXEEID:1;
    vuint32_t TXEENSA:1;
    vuint32_t  :2;
    vuint32_t RX1EIO:1;
    vuint32_t RX1ED:1;
    vuint32_t RX1EIW:1;
    vuint32_t RX1EIAS:1;
    vuint32_t RX1EID:1;
    vuint32_t RX1ENSA:1;
    vuint32_t BEU:1;
    vuint32_t BEC:1;
    vuint32_t RX0EIO:1;
    vuint32_t RX0ED:1;
    vuint32_t RX0EIW:1;
    vuint32_t RX0EIAS:1;
    vuint32_t RX0EID:1;
    vuint32_t RX0ENSA:1;
    vuint32_t  :1;
    vuint32_t TXEE:1;
    vuint32_t TXEIR:1;
    vuint32_t TXEWATA:1;
    vuint32_t TXEIDLC:1;
    vuint32_t TXEIAS:1;
    vuint32_t TXEIE:1;
    vuint32_t TXENSA:1;
  } B;
} M_CAN_DMUIR_tag;

typedef union M_CAN_DMUIE_union_tag {  /* DMU Interrupt Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t IACE:1;
    vuint32_t DTE:1;
    vuint32_t TXEEDE:1;
    vuint32_t TXEEIWE:1;
    vuint32_t TXEEIASE:1;
    vuint32_t TXEEIDE:1;
    vuint32_t TXEENSAE:1;
    vuint32_t  :2;
    vuint32_t RX1EIOE:1;
    vuint32_t RX1EDE:1;
    vuint32_t RX1EIWE:1;
    vuint32_t RX1EIASE:1;
    vuint32_t RX1EIDE:1;
    vuint32_t RX1ENSAE:1;
    vuint32_t BEUE:1;
    vuint32_t BECE:1;
    vuint32_t RX0EIOE:1;
    vuint32_t RX0EDE:1;
    vuint32_t RX0EIWE:1;
    vuint32_t RX0EIASE:1;
    vuint32_t RX0EIDE:1;
    vuint32_t RX0ENSAE:1;
    vuint32_t  :1;
    vuint32_t TXEEE:1;
    vuint32_t TXEIRE:1;
    vuint32_t TXEWATAE:1;
    vuint32_t TXEIDLCE:1;
    vuint32_t TXEIASE:1;
    vuint32_t TXEIEE:1;
    vuint32_t TXENSAE:1;
  } B;
} M_CAN_DMUIE_tag;

typedef union M_CAN_DMUC_union_tag {  /* DMU Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t TTS:1;
  } B;
} M_CAN_DMUC_tag;

struct M_CAN_tag {
  M_CAN_CREL_tag CREL;                 /* Core Release Register */
  M_CAN_ENDN_tag ENDN;                 /* Endian Register */
  uint8_t M_CAN_reserved0[4];
  M_CAN_DBTP_tag DBTP;                 /* Fast Bit Timing and Prescaler Register */
  M_CAN_TEST_tag TEST;                 /* Test Register */
  M_CAN_RWD_tag RWD;                   /* RAM Watchdog Register */
  M_CAN_CCCR_tag CCCR;                 /* CC Control Register */
  M_CAN_NBTP_tag NBTP;                   /* Bit Timing and Prescaler Register */
  M_CAN_TSCC_tag TSCC;                 /* Timestamp Counter Configuration Register */
  M_CAN_TSCV_tag TSCV;                 /* Timestamp Counter Value Register */
  M_CAN_TOCC_tag TOCC;                 /* Timeout Counter Configuration Register */
  M_CAN_TOCV_tag TOCV;                 /* Timeout Counter Value Register */
  uint8_t M_CAN_reserved1[16];
  M_CAN_ECR_tag ECR;                   /* Error Counter Register */
  M_CAN_PSR_tag PSR;                   /* Protocol Status Register */
  M_CAN_TDCR_tag TDCR;
  uint8_t M_CAN_reserved2[4];
  M_CAN_IR_tag IR;                     /* Interrupt Register */
  M_CAN_IE_tag IE;                     /* Interrupt Enable Register */
  M_CAN_ILS_tag ILS;                   /* Interrupt Line Select Register */
  M_CAN_ILE_tag ILE;                   /* Interrupt Line Enable Register */
  uint8_t M_CAN_reserved3[32];
  M_CAN_GFC_tag GFC;                   /* Global Filter Configuration Register */
  M_CAN_SIDFC_tag SIDFC;               /* Standard ID Filter Configuration Register */
  M_CAN_XIDFC_tag XIDFC;               /* Extended ID Filter Configuration Register */
  uint8_t M_CAN_reserved4[4];
  M_CAN_XIDAM_tag XIDAM;               /* Extended ID and Mask Register */
  M_CAN_HPMS_tag HPMS;                 /* High Priority Message Status Register */
  M_CAN_NDAT1_tag NDAT1;               /* New Data 1 Register */
  M_CAN_NDAT2_tag NDAT2;               /* New Data 2 Register */
  M_CAN_RXF0C_tag RXF0C;               /* Rx FIFO 0 Configuration */
  M_CAN_RXF0S_tag RXF0S;               /* Rx FIFO 0 Status Register */
  M_CAN_RXF0A_tag RXF0A;               /* Rx FIFO 0 Acknowledge Register */
  M_CAN_RXBC_tag RXBC;                 /* Rx Buffer Configuration Register */
  M_CAN_RXF1C_tag RXF1C;               /* Rx FIFO 1 Configuration Register */
  M_CAN_RXF1S_tag RXF1S;               /* Rx FIFO 1 Status Register */
  M_CAN_RXF1A_tag RXF1A;               /* Rx FIFO 1 Acknowledge Register */
  M_CAN_RXESC_tag RXESC;               /* Rx Buffer / FIFO Element Size Configuration Register */
  M_CAN_TXBC_tag TXBC;                 /* Tx Buffer Configuration Register */
  M_CAN_TXFQS_tag TXFQS;               /* Tx FIFO/Queue Status Register */
  M_CAN_TXESC_tag TXESC;               /* Tx Buffer Element Size Configuration */
  M_CAN_TXBRP_tag TXBRP;               /* Tx Buffer Request Pending Register */
  M_CAN_TXBAR_tag TXBAR;               /* Tx Buffer Add Request register */
  M_CAN_TXBCR_tag TXBCR;               /* Tx Buffer Cancellation Request register */
  M_CAN_TXBTO_tag TXBTO;               /* Tx Buffer Transmission Occurred register */
  M_CAN_TXBCF_tag TXBCF;               /* Tx Buffer Cancellation Finished register */
  M_CAN_TXBTIE_tag TXBTIE;             /* Tx Buffer Transmission Interrupt Enable register */
  M_CAN_TXBCIE_tag TXBCIE;             /* Tx Buffer Cancellation Finished Interrupt Enable register */
  uint8_t M_CAN_reserved5[8];
  M_CAN_TXEFC_tag TXEFC;               /* Tx Event FIFO Configuration Register */
  M_CAN_TXEFS_tag TXEFS;               /* Tx Event FIFO Status register */
  M_CAN_TXEFA_tag TXEFA;               /* Tx Event FIFO Acknowledge register */
  uint8_t M_CAN_reserved6[100];
  M_CAN_TSU_CREL_tag TSU_CREL;
  M_CAN_TSCFG_tag TSCFG;
  M_CAN_TSS1_tag TSS1;
  M_CAN_TSS2_tag TSS2;
  M_CAN_TS0_tag TS0;
  M_CAN_TS1_tag TS1;
  M_CAN_TS2_tag TS2;
  M_CAN_TS3_tag TS3;
  M_CAN_TS4_tag TS4;
  M_CAN_TS5_tag TS5;
  M_CAN_TS6_tag TS6;
  M_CAN_TS7_tag TS7;
  M_CAN_TS8_tag TS8;
  M_CAN_TS9_tag TS9;
  M_CAN_TS10_tag TS10;
  M_CAN_TS11_tag TS11;
  M_CAN_TS12_tag TS12;
  M_CAN_TS13_tag TS13;
  M_CAN_TS14_tag TS14;
  M_CAN_TS15_tag TS15;
  M_CAN_TSU_ATB_tag TSU_ATB;
  uint8_t M_CAN_reserved7[76];
  uint8_t M_CAN_reserved8[448];
  M_CAN_DMUCR_tag DMUCR;
  M_CAN_DMUI_tag DMUI;
  M_CAN_DMUQC_tag DMUQC;
  M_CAN_DMUIR_tag DMUIR;
  M_CAN_DMUIE_tag DMUIE;
  M_CAN_DMUC_tag DMUC;
};

/* ----------------------------------------------------------------------------
   -- M_CAN Register Masks
   ---------------------------------------------------------------------------- */

/* CREL Bit Fields */
#define MCAN_CREL_DAY_MASK                      0xFFu
#define MCAN_CREL_DAY_SHIFT                     0u
#define MCAN_CREL_DAY_WIDTH                     8u
#define MCAN_CREL_DAY(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_CREL_DAY_SHIFT)) \
                                                  &MCAN_CREL_DAY_MASK)
#define MCAN_CREL_MON_MASK                      0xFF00u
#define MCAN_CREL_MON_SHIFT                     8u
#define MCAN_CREL_MON_WIDTH                     8u
#define MCAN_CREL_MON(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_CREL_MON_SHIFT)) \
                                                  &MCAN_CREL_MON_MASK)
#define MCAN_CREL_YEAR_MASK                     0xF0000u
#define MCAN_CREL_YEAR_SHIFT                    16u
#define MCAN_CREL_YEAR_WIDTH                    4u
#define MCAN_CREL_YEAR(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_CREL_YEAR_SHIFT)) \
                                                  &MCAN_CREL_YEAR_MASK)
#define MCAN_CREL_SUBSTEP_MASK                  0xF00000u
#define MCAN_CREL_SUBSTEP_SHIFT                 20u
#define MCAN_CREL_SUBSTEP_WIDTH                 4u
#define MCAN_CREL_SUBSTEP(x)                    (((uint32)(((uint32)(x)) \
                                                  <<MCAN_CREL_SUBSTEP_SHIFT)) \
                                                  &MCAN_CREL_SUBSTEP_MASK)
#define MCAN_CREL_STEP_MASK                     0xF000000u
#define MCAN_CREL_STEP_SHIFT                    24u
#define MCAN_CREL_STEP_WIDTH                    4u
#define MCAN_CREL_STEP(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_CREL_STEP_SHIFT)) \
                                                  &MCAN_CREL_STEP_MASK)
#define MCAN_CREL_REL_MASK                      0xF0000000u
#define MCAN_CREL_REL_SHIFT                     28u
#define MCAN_CREL_REL_WIDTH                     4u
#define MCAN_CREL_REL(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_CREL_REL_SHIFT)) \
                                                  &MCAN_CREL_REL_MASK)
/* ENDN Bit Fields */
#define MCAN_ENDN_ETV_MASK                      0xFFFFFFFFu
#define MCAN_ENDN_ETV_SHIFT                     0u
#define MCAN_ENDN_ETV_WIDTH                     32u
#define MCAN_ENDN_ETV(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ENDN_ETV_SHIFT)) \
                                                  &MCAN_ENDN_ETV_MASK)
/* DBTP Bit Fields */
#define MCAN_DBTP_DSJW_MASK                     0xFu
#define MCAN_DBTP_DSJW_SHIFT                    0u
#define MCAN_DBTP_DSJW_WIDTH                    4u
#define MCAN_DBTP_DSJW(x)                       (((uint32)(x)) \
                                                  &MCAN_DBTP_DSJW_MASK)
#define MCAN_DBTP_DTSEG2_MASK                   0xF0u
#define MCAN_DBTP_DTSEG2_SHIFT                  4u
#define MCAN_DBTP_DTSEG2_WIDTH                  4u
#define MCAN_DBTP_DTSEG2(x)                     (((uint32)(((uint32)(x)) \
                                                  <<MCAN_DBTP_DTSEG2_SHIFT)) \
                                                  &MCAN_DBTP_DTSEG2_MASK)
#define MCAN_DBTP_DTSEG1_MASK                   0x1F00u
#define MCAN_DBTP_DTSEG1_SHIFT                  8u
#define MCAN_DBTP_DTSEG1_WIDTH                  5u
#define MCAN_DBTP_DTSEG1(x)                     (((uint32)(((uint32)(x)) \
                                                  <<MCAN_DBTP_DTSEG1_SHIFT)) \
                                                  &MCAN_DBTP_DTSEG1_MASK)
#define MCAN_DBTP_DBRP_MASK                     0x1F0000u
#define MCAN_DBTP_DBRP_SHIFT                    16u
#define MCAN_DBTP_DBRP_WIDTH                    5u
#define MCAN_DBTP_DBRP(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_DBTP_DBRP_SHIFT)) \
                                                  &MCAN_DBTP_DBRP_MASK)
#define MCAN_DBTP_TDC_MASK                      0x800000u
#define MCAN_DBTP_TDC_SHIFT                     23u
#define MCAN_DBTP_TDC_WIDTH                     1u
#define MCAN_DBTP_TDC(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_DBTP_TDC_SHIFT)) \
                                                  &MCAN_DBTP_TDC_MASK)
/* TEST Bit Fields */
#define MCAN_TEST_LBCK_MASK                     0x10u
#define MCAN_TEST_LBCK_SHIFT                    4u
#define MCAN_TEST_LBCK_WIDTH                    1u
#define MCAN_TEST_LBCK(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TEST_LBCK_SHIFT)) \
                                                  &MCAN_TEST_LBCK_MASK)
#define MCAN_TEST_TX_MASK                       0x60u
#define MCAN_TEST_TX_SHIFT                      5u
#define MCAN_TEST_TX_WIDTH                      2u
#define MCAN_TEST_TX(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TEST_TX_SHIFT)) \
                                                  &MCAN_TEST_TX_MASK)
#define MCAN_TEST_RX_MASK                       0x80u
#define MCAN_TEST_RX_SHIFT                      7u
#define MCAN_TEST_RX_WIDTH                      1u
#define MCAN_TEST_RX(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TEST_RX_SHIFT)) \
                                                  &MCAN_TEST_RX_MASK)
#define MCAN_TEST_TXBNP_MASK                    0x1F00u
#define MCAN_TEST_TXBNP_SHIFT                   8u
#define MCAN_TEST_TXBNP_WIDTH                   5u
#define MCAN_TEST_TXBNP(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TEST_TXBNP_SHIFT)) \
                                                  &MCAN_TEST_TXBNP_MASK)
#define MCAN_TEST_PVAL_MASK                     0x2000u
#define MCAN_TEST_PVAL_SHIFT                    13u
#define MCAN_TEST_PVAL_WIDTH                    1u
#define MCAN_TEST_PVAL(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TEST_PVAL_SHIFT)) \
                                                  &MCAN_TEST_PVAL_MASK)
#define MCAN_TEST_TXBNS_MASK                    0x1F0000u
#define MCAN_TEST_TXBNS_SHIFT                   16u
#define MCAN_TEST_TXBNS_WIDTH                   5u
#define MCAN_TEST_TXBNS(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TEST_TXBNS_SHIFT)) \
                                                  &MCAN_TEST_TXBNS_MASK)
#define MCAN_TEST_SVAL_MASK                     0x200000u
#define MCAN_TEST_SVAL_SHIFT                    21u
#define MCAN_TEST_SVAL_WIDTH                    1u
#define MCAN_TEST_SVAL(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TEST_SVAL_SHIFT)) \
                                                  &MCAN_TEST_SVAL_MASK)
/* RWD Bit Fields */
#define MCAN_RWD_WDC_MASK                       0xFFu
#define MCAN_RWD_WDC_SHIFT                      0u
#define MCAN_RWD_WDC_WIDTH                      8u
#define MCAN_RWD_WDC(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RWD_WDC_SHIFT)) \
                                                  &MCAN_RWD_WDC_MASK)
#define MCAN_RWD_WDV_MASK                       0xFF00u
#define MCAN_RWD_WDV_SHIFT                      8u
#define MCAN_RWD_WDV_WIDTH                      8u
#define MCAN_RWD_WDV(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RWD_WDV_SHIFT)) \
                                                  &MCAN_RWD_WDV_MASK)
/* CCCR Bit Fields */
#define MCAN_CCCR_INIT_MASK                     (0x1u)
#define MCAN_CCCR_INIT_SHIFT                    (0u)
#define MCAN_CCCR_INIT_WIDTH                    1u
#define MCAN_CCCR_INIT(x)                       (uint32)((x \
                                                  <<MCAN_CCCR_INIT_SHIFT) \
                                                  &MCAN_CCCR_INIT_MASK)
#define MCAN_CCCR_CCE_MASK                      0x2u
#define MCAN_CCCR_CCE_SHIFT                     1u
#define MCAN_CCCR_CCE_WIDTH                     1u
#define MCAN_CCCR_CCE(x)                        (uint32)((x \
                                                  <<MCAN_CCCR_CCE_SHIFT) \
                                                  &MCAN_CCCR_CCE_MASK)
#define MCAN_CCCR_ASM_MASK                      0x4u
#define MCAN_CCCR_ASM_SHIFT                     2u
#define MCAN_CCCR_ASM_WIDTH                     1u
#define MCAN_CCCR_ASM(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_CCCR_ASM_SHIFT)) \
                                                  &MCAN_CCCR_ASM_MASK)
#define MCAN_CCCR_CSA_MASK                      0x8u
#define MCAN_CCCR_CSA_SHIFT                     3u
#define MCAN_CCCR_CSA_WIDTH                     1u
#define MCAN_CCCR_CSA(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_CCCR_CSA_SHIFT)) \
                                                  &MCAN_CCCR_CSA_MASK)
#define MCAN_CCCR_CSR_MASK                      0x10u
#define MCAN_CCCR_CSR_SHIFT                     4u
#define MCAN_CCCR_CSR_WIDTH                     1u
#define MCAN_CCCR_CSR(x)                        (uint32)((x \
                                                  <<MCAN_CCCR_CSR_SHIFT) \
                                                  &MCAN_CCCR_CSR_MASK)
#define MCAN_CCCR_MON_MASK                      0x20u
#define MCAN_CCCR_MON_SHIFT                     5u
#define MCAN_CCCR_MON_WIDTH                     1u
#define MCAN_CCCR_MON(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_CCCR_MON_SHIFT)) \
                                                  &MCAN_CCCR_MON_MASK)
#define MCAN_CCCR_DAR_MASK                      0x40u
#define MCAN_CCCR_DAR_SHIFT                     6u
#define MCAN_CCCR_DAR_WIDTH                     1u
#define MCAN_CCCR_DAR(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_CCCR_DAR_SHIFT)) \
                                                  &MCAN_CCCR_DAR_MASK)
#define MCAN_CCCR_TEST_MASK                     0x80u
#define MCAN_CCCR_TEST_SHIFT                    7u
#define MCAN_CCCR_TEST_WIDTH                    1u
#define MCAN_CCCR_TEST(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_CCCR_TEST_SHIFT)) \
                                                  &MCAN_CCCR_TEST_MASK)
#define MCAN_CCCR_FDOE_MASK                     0x100u
#define MCAN_CCCR_FDOE_SHIFT                    8u
#define MCAN_CCCR_FDOE_WIDTH                    1u
#define MCAN_CCCR_FDOE(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_CCCR_FDOE_SHIFT)) \
                                                  &MCAN_CCCR_FDOE_MASK)
#define MCAN_CCCR_BRSE_MASK                     0x200u
#define MCAN_CCCR_BRSE_SHIFT                    9u
#define MCAN_CCCR_BRSE_WIDTH                    1u
#define MCAN_CCCR_BRSE(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_CCCR_BRSE_SHIFT)) \
                                                  &MCAN_CCCR_BRSE_MASK)
#define MCAN_CCCR_UTSU_MASK                     0x400u
#define MCAN_CCCR_UTSU_SHIFT                    10u
#define MCAN_CCCR_UTSU_WIDTH                    1u
#define MCAN_CCCR_UTSU(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_CCCR_UTSU_SHIFT)) \
                                                  &MCAN_CCCR_UTSU_MASK)
#define MCAN_CCCR_WMM_MASK                      0x800u
#define MCAN_CCCR_WMM_SHIFT                     11u
#define MCAN_CCCR_WMM_WIDTH                     1u
#define MCAN_CCCR_WMM(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_CCCR_UTSU_SHIFT)) \
                                                  &MCAN_CCCR_UTSU_MASK)
#define MCAN_CCCR_PHDX_MASK                     0x1000u
#define MCAN_CCCR_PHDX_SHIFT                    12u
#define MCAN_CCCR_PHDX_WIDTH                    1u
#define MCAN_CCCR_PHDX(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_CCCR_PHDX_SHIFT)) \
                                                  &MCAN_CCCR_PHDX_MASK)
#define MCAN_CCCR_EFBI_MASK                     0x2000u
#define MCAN_CCCR_EFBI_SHIFT                    13u
#define MCAN_CCCR_EFBI_WIDTH                    1u
#define MCAN_CCCR_EFBI(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_CCCR_EFBI_SHIFT)) \
                                                  &MCAN_CCCR_EFBI_MASK)
#define MCAN_CCCR_TXP_MASK                      0x4000u
#define MCAN_CCCR_TXP_SHIFT                     14u
#define MCAN_CCCR_TXP_WIDTH                     1u
#define MCAN_CCCR_TXP(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_CCCR_TXP_SHIFT)) \
                                                  &MCAN_CCCR_TXP_MASK)
#define MCAN_CCCR_NISO_MASK                     0x8000u
#define MCAN_CCCR_NISO_SHIFT                    15u
#define MCAN_CCCR_NISO_WIDTH                    1u
#define MCAN_CCCR_NISO(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_CCCR_NISO_SHIFT)) \
                                                  &MCAN_CCCR_NISO_MASK)
/* NBTP Bit Fields */
#define MCAN_NBTP_NTSEG2_MASK                   0x3Fu
#define MCAN_NBTP_NTSEG2_SHIFT                  0u
#define MCAN_NBTP_NTSEG2_WIDTH                  7u
#define MCAN_NBTP_NTSEG2(x)                     (((uint32)(x)) \
                                                  &MCAN_NBTP_NTSEG2_MASK)
#define MCAN_NBTP_NTSEG1_MASK                   0xFF00u
#define MCAN_NBTP_NTSEG1_SHIFT                  8u
#define MCAN_NBTP_NTSEG1_WIDTH                  8u
#define MCAN_NBTP_NTSEG1(x)                     (((uint32)(((uint32)(x)) \
                                                  <<MCAN_NBTP_NTSEG1_SHIFT)) \
                                                  &MCAN_NBTP_NTSEG1_MASK)
#define MCAN_NBTP_NBRP_MASK                     0x1FF0000u
#define MCAN_NBTP_NBRP_SHIFT                    16u
#define MCAN_NBTP_NBRP_WIDTH                    9u
#define MCAN_NBTP_NBRP(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_NBTP_NBRP_SHIFT)) \
                                                  &MCAN_NBTP_NBRP_MASK)
#define MCAN_NBTP_NSJW_MASK                     0xFE000000u
#define MCAN_NBTP_NSJW_SHIFT                    25u
#define MCAN_NBTP_NSJW_WIDTH                    7u
#define MCAN_NBTP_NSJW(x)                       ((uint32)(((uint32)(x)) \
                                                  <<MCAN_NBTP_NSJW_SHIFT))
/* TSCC Bit Fields */
#define MCAN_TSCC_TSS_MASK                      0x3u
#define MCAN_TSCC_TSS_SHIFT                     0u
#define MCAN_TSCC_TSS_WIDTH                     2u
#define MCAN_TSCC_TSS(x)                        (((uint32)(x)) \
                                                  &MCAN_TSCC_TSS_MASK)
#define MCAN_TSCC_TCP_MASK                      0xF0000u
#define MCAN_TSCC_TCP_SHIFT                     16u
#define MCAN_TSCC_TCP_WIDTH                     4u
#define MCAN_TSCC_TCP(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TSCC_TCP_SHIFT)) \
                                                  &MCAN_TSCC_TCP_MASK)
/* TSCV Bit Fields */
#define MCAN_TSCV_TSC_MASK                      0xFFFFu
#define MCAN_TSCV_TSC_SHIFT                     0u
#define MCAN_TSCV_TSC_WIDTH                     16u
#define MCAN_TSCV_TSC(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TSCV_TSC_SHIFT)) \
                                                  &MCAN_TSCV_TSC_MASK)
/* TOCC Bit Fields */
#define MCAN_TOCC_ETOC_MASK                     0x1u
#define MCAN_TOCC_ETOC_SHIFT                    0u
#define MCAN_TOCC_ETOC_WIDTH                    1u
#define MCAN_TOCC_ETOC(x)                       (uint32)((x \
                                                  <<MCAN_TOCC_ETOC_SHIFT) \
                                                  &MCAN_TOCC_ETOC_MASK)
#define MCAN_TOCC_TOS_MASK                      0x6u
#define MCAN_TOCC_TOS_SHIFT                     1u
#define MCAN_TOCC_TOS_WIDTH                     2u
#define MCAN_TOCC_TOS(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TOCC_TOS_SHIFT)) \
                                                  &MCAN_TOCC_TOS_MASK)
#define MCAN_TOCC_TOP_MASK                      0xFFFF0000u
#define MCAN_TOCC_TOP_SHIFT                     16u
#define MCAN_TOCC_TOP_WIDTH                     16u
#define MCAN_TOCC_TOP(x)                        ((uint32)(((uint32)(x)) \
                                                  <<MCAN_TOCC_TOP_SHIFT))
/* TOCV Bit Fields */
#define MCAN_TOCV_TOC_MASK                      0xFFFFu
#define MCAN_TOCV_TOC_SHIFT                     0u
#define MCAN_TOCV_TOC_WIDTH                     16u
#define MCAN_TOCV_TOC(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TOCV_TOC_SHIFT)) \
                                                  &MCAN_TOCV_TOC_MASK)
/* ECR Bit Fields */
#define MCAN_ECR_TEC_MASK                       0xFFu
#define MCAN_ECR_TEC_SHIFT                      0u
#define MCAN_ECR_TEC_WIDTH                      8u
#define MCAN_ECR_TEC(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ECR_TEC_SHIFT)) \
                                                  &MCAN_ECR_TEC_MASK)
#define MCAN_ECR_REC_MASK                       0x7F00u
#define MCAN_ECR_REC_SHIFT                      8u
#define MCAN_ECR_REC_WIDTH                      7u
#define MCAN_ECR_REC(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ECR_REC_SHIFT)) \
                                                  &MCAN_ECR_REC_MASK)
#define MCAN_ECR_RP_MASK                        0x8000u
#define MCAN_ECR_RP_SHIFT                       15u
#define MCAN_ECR_RP_WIDTH                       1u
#define MCAN_ECR_RP(x)                          (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ECR_RP_SHIFT)) \
                                                  &MCAN_ECR_RP_MASK)
#define MCAN_ECR_CEL_MASK                       0xFF0000u
#define MCAN_ECR_CEL_SHIFT                      16u
#define MCAN_ECR_CEL_WIDTH                      8u
#define MCAN_ECR_CEL(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ECR_CEL_SHIFT)) \
                                                  &MCAN_ECR_CEL_MASK)
/* PSR Bit Fields */
#define MCAN_PSR_LEC_MASK                       0x7u
#define MCAN_PSR_LEC_SHIFT                      0u
#define MCAN_PSR_LEC_WIDTH                      3u
#define MCAN_PSR_LEC(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_PSR_LEC_SHIFT)) \
                                                  &MCAN_PSR_LEC_MASK)
#define MCAN_PSR_ACT_MASK                       0x18u
#define MCAN_PSR_ACT_SHIFT                      3u
#define MCAN_PSR_ACT_WIDTH                      2u
#define MCAN_PSR_ACT(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_PSR_ACT_SHIFT)) \
                                                  &MCAN_PSR_ACT_MASK)
#define MCAN_PSR_EP_MASK                        0x20u
#define MCAN_PSR_EP_SHIFT                       5u
#define MCAN_PSR_EP_WIDTH                       1u
#define MCAN_PSR_EP(x)                          (((uint32)(((uint32)(x)) \
                                                  <<MCAN_PSR_EP_SHIFT)) \
                                                  &MCAN_PSR_EP_MASK)
#define MCAN_PSR_EW_MASK                        0x40u
#define MCAN_PSR_EW_SHIFT                       6u
#define MCAN_PSR_EW_WIDTH                       1u
#define MCAN_PSR_EW(x)                          (((uint32)(((uint32)(x)) \
                                                  <<MCAN_PSR_EW_SHIFT)) \
                                                  &MCAN_PSR_EW_MASK)
#define MCAN_PSR_BO_MASK                        0x80u
#define MCAN_PSR_BO_SHIFT                       7u
#define MCAN_PSR_BO_WIDTH                       1u
#define MCAN_PSR_BO(x)                          (((uint32)(((uint32)(x)) \
                                                  <<MCAN_PSR_BO_SHIFT)) \
                                                  &MCAN_PSR_BO_MASK)
#define MCAN_PSR_DLEC_MASK                      0x700u
#define MCAN_PSR_DLEC_SHIFT                     8u
#define MCAN_PSR_DLEC_WIDTH                     3u
#define MCAN_PSR_DLEC(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_PSR_DLEC_SHIFT)) \
                                                  &MCAN_PSR_DLEC_MASK)
#define MCAN_PSR_RESI_MASK                      0x800u
#define MCAN_PSR_RESI_SHIFT                     11u
#define MCAN_PSR_RESI_WIDTH                     1u
#define MCAN_PSR_RESI(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_PSR_RESI_SHIFT)) \
                                                  &MCAN_PSR_RESI_MASK)
#define MCAN_PSR_RBRS_MASK                      0x1000u
#define MCAN_PSR_RBRS_SHIFT                     12u
#define MCAN_PSR_RBRS_WIDTH                     1u
#define MCAN_PSR_RBRS(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_PSR_RBRS_SHIFT)) \
                                                  &MCAN_PSR_RBRS_MASK)
#define MCAN_PSR_RFDF_MASK                      0x2000u
#define MCAN_PSR_RFDF_SHIFT                     13u
#define MCAN_PSR_RFDF_WIDTH                     1u
#define MCAN_PSR_RFDF(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_PSR_RFDF_SHIFT)) \
                                                  &MCAN_PSR_RFDF_MASK)
#define MCAN_PSR_PXE_MASK                       0x4000u
#define MCAN_PSR_PXE_SHIFT                      14u
#define MCAN_PSR_PXE_WIDTH                      1u
#define MCAN_PSR_PXE(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_PSR_PXE_SHIFT)) \
                                                  &MCAN_PSR_PXE_MASK)
#define MCAN_PSR_TDCV_MASK                      0x7F0000u
#define MCAN_PSR_TDCV_SHIFT                     16u
#define MCAN_PSR_TDCV_WIDTH                     7u
#define MCAN_PSR_TDCV(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_PSR_TDCV_SHIFT)) \
                                                  &MCAN_PSR_TDCV_MASK)
/* TDCR Bit Fields */
#define MCAN_TDCR_TDCF_MASK                     0x7Fu
#define MCAN_TDCR_TDCF_SHIFT                    0u
#define MCAN_TDCR_TDCF_WIDTH                    7u
#define MCAN_TDCR_TDCF(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TDCR_TDCF_SHIFT)) \
                                                  &MCAN_TDCR_TDCF_MASK)
#define MCAN_TDCR_TDCO_MASK                     0x7F00u
#define MCAN_TDCR_TDCO_SHIFT                    8u
#define MCAN_TDCR_TDCO_WIDTH                    7u
#define MCAN_TDCR_TDCO(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TDCR_TDCO_SHIFT)) \
                                                  &MCAN_TDCR_TDCO_MASK)
/* IR Bit Fields */
#define MCAN_IR_RF0N_MASK                       0x1u
#define MCAN_IR_RF0N_SHIFT                      0u
#define MCAN_IR_RF0N_WIDTH                      1u
#define MCAN_IR_RF0N(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_RF0N_SHIFT)) \
                                                  &MCAN_IR_RF0N_MASK)
#define MCAN_IR_RF0W_MASK                       0x2u
#define MCAN_IR_RF0W_SHIFT                      1u
#define MCAN_IR_RF0W_WIDTH                      1u
#define MCAN_IR_RF0W(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_RF0W_SHIFT)) \
                                                  &MCAN_IR_RF0W_MASK)
#define MCAN_IR_RF0F_MASK                       0x4u
#define MCAN_IR_RF0F_SHIFT                      2u
#define MCAN_IR_RF0F_WIDTH                      1u
#define MCAN_IR_RF0F(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_RF0F_SHIFT)) \
                                                  &MCAN_IR_RF0F_MASK)
#define MCAN_IR_RF0L_MASK                       0x8u
#define MCAN_IR_RF0L_SHIFT                      3u
#define MCAN_IR_RF0L_WIDTH                      1u
#define MCAN_IR_RF0L(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_RF0L_SHIFT)) \
                                                  &MCAN_IR_RF0L_MASK)
#define MCAN_IR_RF1N_MASK                       0x10u
#define MCAN_IR_RF1N_SHIFT                      4u
#define MCAN_IR_RF1N_WIDTH                      1u
#define MCAN_IR_RF1N(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_RF1N_SHIFT)) \
                                                  &MCAN_IR_RF1N_MASK)
#define MCAN_IR_RF1W_MASK                       0x20u
#define MCAN_IR_RF1W_SHIFT                      5u
#define MCAN_IR_RF1W_WIDTH                      1u
#define MCAN_IR_RF1W(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_RF1W_SHIFT)) \
                                                  &MCAN_IR_RF1W_MASK)
#define MCAN_IR_RF1F_MASK                       0x40u
#define MCAN_IR_RF1F_SHIFT                      6u
#define MCAN_IR_RF1F_WIDTH                      1u
#define MCAN_IR_RF1F(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_RF1F_SHIFT)) \
                                                  &MCAN_IR_RF1F_MASK)
#define MCAN_IR_RF1L_MASK                       0x80u
#define MCAN_IR_RF1L_SHIFT                      7u
#define MCAN_IR_RF1L_WIDTH                      1u
#define MCAN_IR_RF1L(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_RF1L_SHIFT)) \
                                                  &MCAN_IR_RF1L_MASK)
#define MCAN_IR_HPM_MASK                        0x100u
#define MCAN_IR_HPM_SHIFT                       8u
#define MCAN_IR_HPM_WIDTH                       1u
#define MCAN_IR_HPM(x)                          (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_HPM_SHIFT)) \
                                                  &MCAN_IR_HPM_MASK)
#define MCAN_IR_TC_MASK                         0x200u
#define MCAN_IR_TC_SHIFT                        9u
#define MCAN_IR_TC_WIDTH                        1u
#define MCAN_IR_TC(x)                           (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_TC_SHIFT)) \
                                                  &MCAN_IR_TC_MASK)
#define MCAN_IR_TCF_MASK                        0x400u
#define MCAN_IR_TCF_SHIFT                       10u
#define MCAN_IR_TCF_WIDTH                       1u
#define MCAN_IR_TCF(x)                          (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_TCF_SHIFT)) \
                                                  &MCAN_IR_TCF_MASK)
#define MCAN_IR_TFE_MASK                        0x800u
#define MCAN_IR_TFE_SHIFT                       11u
#define MCAN_IR_TFE_WIDTH                       1u
#define MCAN_IR_TFE(x)                          (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_TFE_SHIFT)) \
                                                  &MCAN_IR_TFE_MASK)
#define MCAN_IR_TEFN_MASK                       0x1000u
#define MCAN_IR_TEFN_SHIFT                      12u
#define MCAN_IR_TEFN_WIDTH                      1u
#define MCAN_IR_TEFN(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_TEFN_SHIFT)) \
                                                  &MCAN_IR_TEFN_MASK)
#define MCAN_IR_TEFW_MASK                       0x2000u
#define MCAN_IR_TEFW_SHIFT                      13u
#define MCAN_IR_TEFW_WIDTH                      1u
#define MCAN_IR_TEFW(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_TEFW_SHIFT)) \
                                                  &MCAN_IR_TEFW_MASK)
#define MCAN_IR_TEFF_MASK                       0x4000u
#define MCAN_IR_TEFF_SHIFT                      14u
#define MCAN_IR_TEFF_WIDTH                      1u
#define MCAN_IR_TEFF(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_TEFF_SHIFT)) \
                                                  &MCAN_IR_TEFF_MASK)
#define MCAN_IR_TEFL_MASK                       0x8000u
#define MCAN_IR_TEFL_SHIFT                      15u
#define MCAN_IR_TEFL_WIDTH                      1u
#define MCAN_IR_TEFL(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_TEFL_SHIFT)) \
                                                  &MCAN_IR_TEFL_MASK)
#define MCAN_IR_TSW_MASK                        0x10000u
#define MCAN_IR_TSW_SHIFT                       16u
#define MCAN_IR_TSW_WIDTH                       1u
#define MCAN_IR_TSW(x)                          (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_TSW_SHIFT)) \
                                                  &MCAN_IR_TSW_MASK)
#define MCAN_IR_MRAF_MASK                       0x20000u
#define MCAN_IR_MRAF_SHIFT                      17u
#define MCAN_IR_MRAF_WIDTH                      1u
#define MCAN_IR_MRAF(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_MRAF_SHIFT)) \
                                                  &MCAN_IR_MRAF_MASK)
#define MCAN_IR_TOO_MASK                        0x40000u
#define MCAN_IR_TOO_SHIFT                       18u
#define MCAN_IR_TOO_WIDTH                       1u
#define MCAN_IR_TOO(x)                          (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_TOO_SHIFT)) \
                                                  &MCAN_IR_TOO_MASK)
#define MCAN_IR_DRX_MASK                        0x80000u
#define MCAN_IR_DRX_SHIFT                       19u
#define MCAN_IR_DRX_WIDTH                       1u
#define MCAN_IR_DRX(x)                          (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_DRX_SHIFT)) \
                                                  &MCAN_IR_DRX_MASK)
#define MCAN_IR_BEC_MASK                        0x100000u
#define MCAN_IR_BEC_SHIFT                       20u
#define MCAN_IR_BEC_WIDTH                       1u
#define MCAN_IR_BEC(x)                          (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_BEC_SHIFT)) \
                                                  &MCAN_IR_BEC_MASK)
#define MCAN_IR_BEU_MASK                        0x200000u
#define MCAN_IR_BEU_SHIFT                       21u
#define MCAN_IR_BEU_WIDTH                       1u
#define MCAN_IR_BEU(x)                          (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_BEU_SHIFT)) \
                                                  &MCAN_IR_BEU_MASK)
#define MCAN_IR_ELO_MASK                        0x400000u
#define MCAN_IR_ELO_SHIFT                       22u
#define MCAN_IR_ELO_WIDTH                       1u
#define MCAN_IR_ELO(x)                          (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_ELO_SHIFT)) \
                                                  &MCAN_IR_ELO_MASK)
#define MCAN_IR_EP_MASK                         0x800000u
#define MCAN_IR_EP_SHIFT                        23u
#define MCAN_IR_EP_WIDTH                        1u
#define MCAN_IR_EP(x)                           (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_EP_SHIFT)) \
                                                  &MCAN_IR_EP_MASK)
#define MCAN_IR_EW_MASK                         0x1000000u
#define MCAN_IR_EW_SHIFT                        24u
#define MCAN_IR_EW_WIDTH                        1u
#define MCAN_IR_EW(x)                           (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_EW_SHIFT)) \
                                                  &MCAN_IR_EW_MASK)
#define MCAN_IR_BO_MASK                         0x2000000u
#define MCAN_IR_BO_SHIFT                        25u
#define MCAN_IR_BO_WIDTH                        1u
#define MCAN_IR_BO(x)                           (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_BO_SHIFT)) \
                                                  &MCAN_IR_BO_MASK)
#define MCAN_IR_WDI_MASK                        0x4000000u
#define MCAN_IR_WDI_SHIFT                       26u
#define MCAN_IR_WDI_WIDTH                       1u
#define MCAN_IR_WDI(x)                          (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_WDI_SHIFT)) \
                                                  &MCAN_IR_WDI_MASK)
#define MCAN_IR_PEA_MASK                        0x8000000u
#define MCAN_IR_PEA_SHIFT                       27u
#define MCAN_IR_PEA_WIDTH                       1u
#define MCAN_IR_PEA(x)                          (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_PEA_SHIFT)) \
                                                  &MCAN_IR_PEA_MASK)
#define MCAN_IR_PED_MASK                        0x10000000u
#define MCAN_IR_PED_SHIFT                       28u
#define MCAN_IR_PED_WIDTH                       1u
#define MCAN_IR_PED(x)                          (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_PED_SHIFT)) \
                                                  &MCAN_IR_PED_MASK)
#define MCAN_IR_ARA_MASK                        0x20000000u
#define MCAN_IR_ARA_SHIFT                       29u
#define MCAN_IR_ARA_WIDTH                       1u
#define MCAN_IR_ARA(x)                          (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IR_ARA_SHIFT)) \
                                                  &MCAN_IR_ARA_MASK)

/* IE Bit Fields */
#define MCAN_IE_RF0NE_MASK                      0x1u
#define MCAN_IE_RF0NE_SHIFT                     0u
#define MCAN_IE_RF0NE_WIDTH                     1u
#define MCAN_IE_RF0NE(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_RF0NE_SHIFT)) \
                                                  &MCAN_IE_RF0NE_MASK)
#define MCAN_IE_RF0WE_MASK                      0x2u
#define MCAN_IE_RF0WE_SHIFT                     1u
#define MCAN_IE_RF0WE_WIDTH                     1u
#define MCAN_IE_RF0WE(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_RF0WE_SHIFT)) \
                                                  &MCAN_IE_RF0WE_MASK)
#define MCAN_IE_RF0FE_MASK                      0x4u
#define MCAN_IE_RF0FE_SHIFT                     2u
#define MCAN_IE_RF0FE_WIDTH                     1u
#define MCAN_IE_RF0FE(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_RF0FE_SHIFT)) \
                                                  &MCAN_IE_RF0FE_MASK)
#define MCAN_IE_RF0LE_MASK                      0x8u
#define MCAN_IE_RF0LE_SHIFT                     3u
#define MCAN_IE_RF0LE_WIDTH                     1u
#define MCAN_IE_RF0LE(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_RF0LE_SHIFT)) \
                                                  &MCAN_IE_RF0LE_MASK)
#define MCAN_IE_RF1NE_MASK                      0x10u
#define MCAN_IE_RF1NE_SHIFT                     4u
#define MCAN_IE_RF1NE_WIDTH                     1u
#define MCAN_IE_RF1NE(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_RF1NE_SHIFT)) \
                                                  &MCAN_IE_RF1NE_MASK)
#define MCAN_IE_RF1WE_MASK                      0x20u
#define MCAN_IE_RF1WE_SHIFT                     5u
#define MCAN_IE_RF1WE_WIDTH                     1u
#define MCAN_IE_RF1WE(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_RF1WE_SHIFT)) \
                                                  &MCAN_IE_RF1WE_MASK)
#define MCAN_IE_RF1FE_MASK                      0x40u
#define MCAN_IE_RF1FE_SHIFT                     6u
#define MCAN_IE_RF1FE_WIDTH                     1u
#define MCAN_IE_RF1FE(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_RF1FE_SHIFT)) \
                                                  &MCAN_IE_RF1FE_MASK)
#define MCAN_IE_RF1LE_MASK                      0x80u
#define MCAN_IE_RF1LE_SHIFT                     7u
#define MCAN_IE_RF1LE_WIDTH                     1u
#define MCAN_IE_RF1LE(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_RF1LE_SHIFT)) \
                                                  &MCAN_IE_RF1LE_MASK)
#define MCAN_IE_HPME_MASK                       0x100u
#define MCAN_IE_HPME_SHIFT                      8u
#define MCAN_IE_HPME_WIDTH                      1u
#define MCAN_IE_HPME(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_HPME_SHIFT)) \
                                                  &MCAN_IE_HPME_MASK)
#define MCAN_IE_TCE_MASK                        0x200u
#define MCAN_IE_TCE_SHIFT                       9u
#define MCAN_IE_TCE_WIDTH                       1u
#define MCAN_IE_TCE(x)                          (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_TCE_SHIFT)) \
                                                  &MCAN_IE_TCE_MASK)
#define MCAN_IE_TCFE_MASK                       0x400u
#define MCAN_IE_TCFE_SHIFT                      10u
#define MCAN_IE_TCFE_WIDTH                      1u
#define MCAN_IE_TCFE(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_TCFE_SHIFT)) \
                                                  &MCAN_IE_TCFE_MASK)
#define MCAN_IE_TFEE_MASK                       0x800u
#define MCAN_IE_TFEE_SHIFT                      11u
#define MCAN_IE_TFEE_WIDTH                      1u
#define MCAN_IE_TFEE(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_TFEE_SHIFT)) \
                                                  &MCAN_IE_TFEE_MASK)
#define MCAN_IE_TEFNE_MASK                      0x1000u
#define MCAN_IE_TEFNE_SHIFT                     12u
#define MCAN_IE_TEFNE_WIDTH                     1u
#define MCAN_IE_TEFNE(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_TEFNE_SHIFT)) \
                                                  &MCAN_IE_TEFNE_MASK)
#define MCAN_IE_TEFWE_MASK                      0x2000u
#define MCAN_IE_TEFWE_SHIFT                     13u
#define MCAN_IE_TEFWE_WIDTH                     1u
#define MCAN_IE_TEFWE(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_TEFWE_SHIFT)) \
                                                  &MCAN_IE_TEFWE_MASK)
#define MCAN_IE_TEFFE_MASK                      0x4000u
#define MCAN_IE_TEFFE_SHIFT                     14u
#define MCAN_IE_TEFFE_WIDTH                     1u
#define MCAN_IE_TEFFE(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_TEFFE_SHIFT)) \
                                                  &MCAN_IE_TEFFE_MASK)
#define MCAN_IE_TEFLE_MASK                      0x8000u
#define MCAN_IE_TEFLE_SHIFT                     15u
#define MCAN_IE_TEFLE_WIDTH                     1u
#define MCAN_IE_TEFLE(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_TEFLE_SHIFT)) \
                                                  &MCAN_IE_TEFLE_MASK)
#define MCAN_IE_TSWE_MASK                       0x10000u
#define MCAN_IE_TSWE_SHIFT                      16u
#define MCAN_IE_TSWE_WIDTH                      1u
#define MCAN_IE_TSWE(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_TSWE_SHIFT)) \
                                                  &MCAN_IE_TSWE_MASK)
#define MCAN_IE_MRAFE_MASK                      0x20000u
#define MCAN_IE_MRAFE_SHIFT                     17u
#define MCAN_IE_MRAFE_WIDTH                     1u
#define MCAN_IE_MRAFE(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_MRAFE_SHIFT)) \
                                                  &MCAN_IE_MRAFE_MASK)
#define MCAN_IE_TOOE_MASK                       0x40000u
#define MCAN_IE_TOOE_SHIFT                      18u
#define MCAN_IE_TOOE_WIDTH                      1u
#define MCAN_IE_TOOE(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_TOOE_SHIFT)) \
                                                  &MCAN_IE_TOOE_MASK)
#define MCAN_IE_DRXE_MASK                       0x80000u
#define MCAN_IE_DRXE_SHIFT                      19u
#define MCAN_IE_DRXE_WIDTH                      1u
#define MCAN_IE_DRXE(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_DRXE_SHIFT)) \
                                                  &MCAN_IE_DRXE_MASK)
#define MCAN_IE_BECE_MASK                       0x100000u
#define MCAN_IE_BECE_SHIFT                      20u
#define MCAN_IE_BECE_WIDTH                      1u
#define MCAN_IE_BECE(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_BECE_SHIFT)) \
                                                  &MCAN_IE_BECE_MASK)
#define MCAN_IE_BEUE_MASK                       0x200000u
#define MCAN_IE_BEUE_SHIFT                      21u
#define MCAN_IE_BEUE_WIDTH                      1u
#define MCAN_IE_BEUE(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_BEUE_SHIFT)) \
                                                  &MCAN_IE_BEUE_MASK)
#define MCAN_IE_ELOE_MASK                       0x400000u
#define MCAN_IE_ELOE_SHIFT                      22u
#define MCAN_IE_ELOE_WIDTH                      1u
#define MCAN_IE_ELOE(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_ELOE_SHIFT)) \
                                                  &MCAN_IE_ELOE_MASK)
#define MCAN_IE_EPE_MASK                        0x800000u
#define MCAN_IE_EPE_SHIFT                       23u
#define MCAN_IE_EPE_WIDTH                       1u
#define MCAN_IE_EPE(x)                          (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_EPE_SHIFT)) \
                                                  &MCAN_IE_EPE_MASK)
#define MCAN_IE_EWE_MASK                        0x1000000u
#define MCAN_IE_EWE_SHIFT                       24u
#define MCAN_IE_EWE_WIDTH                       1u
#define MCAN_IE_EWE(x)                          (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_EWE_SHIFT)) \
                                                  &MCAN_IE_EWE_MASK)
#define MCAN_IE_BOE_MASK                        0x2000000u
#define MCAN_IE_BOE_SHIFT                       25u
#define MCAN_IE_BOE_WIDTH                       1u
#define MCAN_IE_BOE(x)                          (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_BOE_SHIFT)) \
                                                  &MCAN_IE_BOE_MASK)
#define MCAN_IE_WDIE_MASK                       0x4000000u
#define MCAN_IE_WDIE_SHIFT                      26u
#define MCAN_IE_WDIE_WIDTH                      1u
#define MCAN_IE_WDIE(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_WDIE_SHIFT)) \
                                                  &MCAN_IE_WDIE_MASK)
#define MCAN_IE_PEAE_MASK                       0x8000000u
#define MCAN_IE_PEAE_SHIFT                      27u
#define MCAN_IE_PEAE_WIDTH                      1u
#define MCAN_IE_PEAE(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_PEAE_SHIFT)) \
                                                  &MCAN_IE_PEAE_MASK)
#define MCAN_IE_PEDE_MASK                       0x10000000u
#define MCAN_IE_PEDE_SHIFT                      28u
#define MCAN_IE_PEDE_WIDTH                      1u
#define MCAN_IE_PEDE(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_PEDE_SHIFT)) \
                                                  &MCAN_IE_PEDE_MASK)
#define MCAN_IE_ARAE_MASK                       0x20000000u
#define MCAN_IE_ARAE_SHIFT                      29u
#define MCAN_IE_ARAE_WIDTH                      1u
#define MCAN_IE_ARAE(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_IE_ARAE_SHIFT)) \
                                                  &MCAN_IE_ARAE_MASK)
/* ILS Bit Fields */
#define MCAN_ILS_RF0NL_MASK                     0x1u
#define MCAN_ILS_RF0NL_SHIFT                    0u
#define MCAN_ILS_RF0NL_WIDTH                    1u
#define MCAN_ILS_RF0NL(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_RF0NL_SHIFT)) \
                                                  &MCAN_ILS_RF0NL_MASK)
#define MCAN_ILS_RF0WL_MASK                     0x2u
#define MCAN_ILS_RF0WL_SHIFT                    1u
#define MCAN_ILS_RF0WL_WIDTH                    1u
#define MCAN_ILS_RF0WL(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_RF0WL_SHIFT)) \
                                                  &MCAN_ILS_RF0WL_MASK)
#define MCAN_ILS_RF0FL_MASK                     0x4u
#define MCAN_ILS_RF0FL_SHIFT                    2u
#define MCAN_ILS_RF0FL_WIDTH                    1u
#define MCAN_ILS_RF0FL(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_RF0FL_SHIFT)) \
                                                  &MCAN_ILS_RF0FL_MASK)
#define MCAN_ILS_RF0LL_MASK                     0x8u
#define MCAN_ILS_RF0LL_SHIFT                    3u
#define MCAN_ILS_RF0LL_WIDTH                    1u
#define MCAN_ILS_RF0LL(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_RF0LL_SHIFT)) \
                                                  &MCAN_ILS_RF0LL_MASK)
#define MCAN_ILS_RF1NL_MASK                     0x10u
#define MCAN_ILS_RF1NL_SHIFT                    4u
#define MCAN_ILS_RF1NL_WIDTH                    1u
#define MCAN_ILS_RF1NL(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_RF1NL_SHIFT)) \
                                                  &MCAN_ILS_RF1NL_MASK)
#define MCAN_ILS_RF1WL_MASK                     0x20u
#define MCAN_ILS_RF1WL_SHIFT                    5u
#define MCAN_ILS_RF1WL_WIDTH                    1u
#define MCAN_ILS_RF1WL(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_RF1WL_SHIFT)) \
                                                  &MCAN_ILS_RF1WL_MASK)
#define MCAN_ILS_RF1FL_MASK                     0x40u
#define MCAN_ILS_RF1FL_SHIFT                    6u
#define MCAN_ILS_RF1FL_WIDTH                    1u
#define MCAN_ILS_RF1FL(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_RF1FL_SHIFT)) \
                                                  &MCAN_ILS_RF1FL_MASK)
#define MCAN_ILS_RF1LL_MASK                     0x80u
#define MCAN_ILS_RF1LL_SHIFT                    7u
#define MCAN_ILS_RF1LL_WIDTH                    1u
#define MCAN_ILS_RF1LL(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_RF1LL_SHIFT)) \
                                                  &MCAN_ILS_RF1LL_MASK)
#define MCAN_ILS_HPML_MASK                      0x100u
#define MCAN_ILS_HPML_SHIFT                     8u
#define MCAN_ILS_HPML_WIDTH                     1u
#define MCAN_ILS_HPML(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_HPML_SHIFT)) \
                                                  &MCAN_ILS_HPML_MASK)
#define MCAN_ILS_TCL_MASK                       0x200u
#define MCAN_ILS_TCL_SHIFT                      9u
#define MCAN_ILS_TCL_WIDTH                      1u
#define MCAN_ILS_TCL(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_TCL_SHIFT)) \
                                                  &MCAN_ILS_TCL_MASK)
#define MCAN_ILS_TCFL_MASK                      0x400u
#define MCAN_ILS_TCFL_SHIFT                     10u
#define MCAN_ILS_TCFL_WIDTH                     1u
#define MCAN_ILS_TCFL(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_TCFL_SHIFT)) \
                                                  &MCAN_ILS_TCFL_MASK)
#define MCAN_ILS_TFEL_MASK                      0x800u
#define MCAN_ILS_TFEL_SHIFT                     11u
#define MCAN_ILS_TFEL_WIDTH                     1u
#define MCAN_ILS_TFEL(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_TFEL_SHIFT)) \
                                                  &MCAN_ILS_TFEL_MASK)
#define MCAN_ILS_TEFNL_MASK                     0x1000u
#define MCAN_ILS_TEFNL_SHIFT                    12u
#define MCAN_ILS_TEFNL_WIDTH                    1u
#define MCAN_ILS_TEFNL(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_TEFNL_SHIFT)) \
                                                  &MCAN_ILS_TEFNL_MASK)
#define MCAN_ILS_TEFWL_MASK                     0x2000u
#define MCAN_ILS_TEFWL_SHIFT                    13u
#define MCAN_ILS_TEFWL_WIDTH                    1u
#define MCAN_ILS_TEFWL(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_TEFWL_SHIFT)) \
                                                  &MCAN_ILS_TEFWL_MASK)
#define MCAN_ILS_TEFFL_MASK                     0x4000u
#define MCAN_ILS_TEFFL_SHIFT                    14u
#define MCAN_ILS_TEFFL_WIDTH                    1u
#define MCAN_ILS_TEFFL(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_TEFFL_SHIFT)) \
                                                  &MCAN_ILS_TEFFL_MASK)
#define MCAN_ILS_TEFLL_MASK                     0x8000u
#define MCAN_ILS_TEFLL_SHIFT                    15u
#define MCAN_ILS_TEFLL_WIDTH                    1u
#define MCAN_ILS_TEFLL(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_TEFLL_SHIFT)) \
                                                  &MCAN_ILS_TEFLL_MASK)
#define MCAN_ILS_TSWL_MASK                      0x10000u
#define MCAN_ILS_TSWL_SHIFT                     16u
#define MCAN_ILS_TSWL_WIDTH                     1u
#define MCAN_ILS_TSWL(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_TSWL_SHIFT)) \
                                                  &MCAN_ILS_TSWL_MASK)
#define MCAN_ILS_MRAFL_MASK                     0x20000u
#define MCAN_ILS_MRAFL_SHIFT                    17u
#define MCAN_ILS_MRAFL_WIDTH                    1u
#define MCAN_ILS_MRAFL(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_MRAFL_SHIFT)) \
                                                  &MCAN_ILS_MRAFL_MASK)
#define MCAN_ILS_TOOL_MASK                      0x40000u
#define MCAN_ILS_TOOL_SHIFT                     18u
#define MCAN_ILS_TOOL_WIDTH                     1u
#define MCAN_ILS_TOOL(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_TOOL_SHIFT)) \
                                                  &MCAN_ILS_TOOL_MASK)
#define MCAN_ILS_DRXL_MASK                      0x80000u
#define MCAN_ILS_DRXL_SHIFT                     19u
#define MCAN_ILS_DRXL_WIDTH                     1u
#define MCAN_ILS_DRXL(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_DRXL_SHIFT)) \
                                                  &MCAN_ILS_DRXL_MASK)
#define MCAN_ILS_BECL_MASK                      0x100000u
#define MCAN_ILS_BECL_SHIFT                     20u
#define MCAN_ILS_BECL_WIDTH                     1u
#define MCAN_ILS_BECL(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_BECL_SHIFT)) \
                                                  &MCAN_ILS_BECL_MASK)
#define MCAN_ILS_BEUL_MASK                      0x200000u
#define MCAN_ILS_BEUL_SHIFT                     21u
#define MCAN_ILS_BEUL_WIDTH                     1u
#define MCAN_ILS_BEUL(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_BEUL_SHIFT)) \
                                                  &MCAN_ILS_BEUL_MASK)
#define MCAN_ILS_ELOL_MASK                      0x400000u
#define MCAN_ILS_ELOL_SHIFT                     22u
#define MCAN_ILS_ELOL_WIDTH                     1u
#define MCAN_ILS_ELOL(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_ELOL_SHIFT)) \
                                                  &MCAN_ILS_ELOL_MASK)
#define MCAN_ILS_EPL_MASK                       0x800000u
#define MCAN_ILS_EPL_SHIFT                      23u
#define MCAN_ILS_EPL_WIDTH                      1u
#define MCAN_ILS_EPL(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_EPL_SHIFT)) \
                                                  &MCAN_ILS_EPL_MASK)
#define MCAN_ILS_EWL_MASK                       0x1000000u
#define MCAN_ILS_EWL_SHIFT                      24u
#define MCAN_ILS_EWL_WIDTH                      1u
#define MCAN_ILS_EWL(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_EWL_SHIFT)) \
                                                  &MCAN_ILS_EWL_MASK)
#define MCAN_ILS_BOL_MASK                       0x2000000u
#define MCAN_ILS_BOL_SHIFT                      25u
#define MCAN_ILS_BOL_WIDTH                      1u
#define MCAN_ILS_BOL(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_BOL_SHIFT)) \
                                                  &MCAN_ILS_BOL_MASK)
#define MCAN_ILS_WDIL_MASK                      0x4000000u
#define MCAN_ILS_WDIL_SHIFT                     26u
#define MCAN_ILS_WDIL_WIDTH                     1u
#define MCAN_ILS_WDIL(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_WDIL_SHIFT)) \
                                                  &MCAN_ILS_WDIL_MASK)
#define MCAN_ILS_PEAL_MASK                      0x8000000u
#define MCAN_ILS_PEAL_SHIFT                     27u
#define MCAN_ILS_PEAL_WIDTH                     1u
#define MCAN_ILS_PEAL(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_PEAL_SHIFT)) \
                                                  &MCAN_ILS_PEAL_MASK)
#define MCAN_ILS_PEDL_MASK                      0x10000000u
#define MCAN_ILS_PEDL_SHIFT                     28u
#define MCAN_ILS_PEDL_WIDTH                     1u
#define MCAN_ILS_PEDL(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_PEDL_SHIFT)) \
                                                  &MCAN_ILS_PEDL_MASK)
#define MCAN_ILS_ARAL_MASK                      0x20000000u
#define MCAN_ILS_ARAL_SHIFT                     29u
#define MCAN_ILS_ARAL_WIDTH                     1u
#define MCAN_ILS_ARAL(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILS_ARAL_SHIFT)) \
                                                  &MCAN_ILS_ARAL_MASK)
/* ILE Bit Fields */
#define MCAN_ILE_EINT0_MASK                     0x1u
#define MCAN_ILE_EINT0_SHIFT                    0u
#define MCAN_ILE_EINT0_WIDTH                    1u
#define MCAN_ILE_EINT0(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILE_EINT0_SHIFT)) \
                                                  &MCAN_ILE_EINT0_MASK)
#define MCAN_ILE_EINT1_MASK                     0x2u
#define MCAN_ILE_EINT1_SHIFT                    1u
#define MCAN_ILE_EINT1_WIDTH                    1u
#define MCAN_ILE_EINT1(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_ILE_EINT1_SHIFT)) \
                                                  &MCAN_ILE_EINT1_MASK)
/* GFC Bit Fields */
#define MCAN_GFC_RRFE_MASK                      0x1u
#define MCAN_GFC_RRFE_SHIFT                     0u
#define MCAN_GFC_RRFE_WIDTH                     1u
#define MCAN_GFC_RRFE(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_GFC_RRFE_SHIFT)) \
                                                  &MCAN_GFC_RRFE_MASK)
#define MCAN_GFC_RRFS_MASK                      0x2u
#define MCAN_GFC_RRFS_SHIFT                     1u
#define MCAN_GFC_RRFS_WIDTH                     1u
#define MCAN_GFC_RRFS(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_GFC_RRFS_SHIFT)) \
                                                  &MCAN_GFC_RRFS_MASK)
#define MCAN_GFC_ANFE_MASK                      0xCu
#define MCAN_GFC_ANFE_SHIFT                     2u
#define MCAN_GFC_ANFE_WIDTH                     2u
#define MCAN_GFC_ANFE(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_GFC_ANFE_SHIFT)) \
                                                  &MCAN_GFC_ANFE_MASK)
#define MCAN_GFC_ANFS_MASK                      0x30u
#define MCAN_GFC_ANFS_SHIFT                     4u
#define MCAN_GFC_ANFS_WIDTH                     2u
#define MCAN_GFC_ANFS(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_GFC_ANFS_SHIFT)) \
                                                  &MCAN_GFC_ANFS_MASK)
/* SIDFC Bit Fields */
#define MCAN_SIDFC_FLSSA_MASK                   0xFFFCu
#define MCAN_SIDFC_FLSSA_SHIFT                  2u
#define MCAN_SIDFC_FLSSA_WIDTH                  14u
#define MCAN_SIDFC_FLSSA(x)                     (((uint32)(((uint32)(x)) \
                                                  <<MCAN_SIDFC_FLSSA_SHIFT)) \
                                                  &MCAN_SIDFC_FLSSA_MASK)
#define MCAN_SIDFC_LSS_MASK                     0xFF0000u
#define MCAN_SIDFC_LSS_SHIFT                    16u
#define MCAN_SIDFC_LSS_WIDTH                    8u
#define MCAN_SIDFC_LSS(x)                       ((uint32)(((uint32)(x)) \
                                                  <<MCAN_SIDFC_LSS_SHIFT))
/* XIDFC Bit Fields */
#define MCAN_XIDFC_FLESA_MASK                   0xFFFCu
#define MCAN_XIDFC_FLESA_SHIFT                  2u
#define MCAN_XIDFC_FLESA_WIDTH                  14u
#define MCAN_XIDFC_FLESA(x)                     (((uint32)(((uint32)(x)) \
                                                  <<MCAN_XIDFC_FLESA_SHIFT)) \
                                                  &MCAN_XIDFC_FLESA_MASK)
#define MCAN_XIDFC_LSE_MASK                     0x7F0000u
#define MCAN_XIDFC_LSE_SHIFT                    16u
#define MCAN_XIDFC_LSE_WIDTH                    7u
#define MCAN_XIDFC_LSE(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_XIDFC_LSE_SHIFT)) \
                                                  &MCAN_XIDFC_LSE_MASK)
/* XIDAM Bit Fields */
#define MCAN_XIDAM_EIDM_MASK                    0x1FFFFFFFu
#define MCAN_XIDAM_EIDM_SHIFT                   0u
#define MCAN_XIDAM_EIDM_WIDTH                   29u
#define MCAN_XIDAM_EIDM(x)                      (((uint32)(x)) \
                                                  &MCAN_XIDAM_EIDM_MASK)
/* HPMS Bit Fields */
#define MCAN_HPMS_BIDX_MASK                     0x3Fu
#define MCAN_HPMS_BIDX_SHIFT                    0u
#define MCAN_HPMS_BIDX_WIDTH                    6u
#define MCAN_HPMS_BIDX(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_HPMS_BIDX_SHIFT)) \
                                                  &MCAN_HPMS_BIDX_MASK)
#define MCAN_HPMS_MSI_MASK                      0xC0u
#define MCAN_HPMS_MSI_SHIFT                     6u
#define MCAN_HPMS_MSI_WIDTH                     2u
#define MCAN_HPMS_MSI(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_HPMS_MSI_SHIFT)) \
                                                  &MCAN_HPMS_MSI_MASK)
#define MCAN_HPMS_FIDX_MASK                     0x7F00u
#define MCAN_HPMS_FIDX_SHIFT                    8u
#define MCAN_HPMS_FIDX_WIDTH                    7u
#define MCAN_HPMS_FIDX(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_HPMS_FIDX_SHIFT)) \
                                                  &MCAN_HPMS_FIDX_MASK)
#define MCAN_HPMS_FLST_MASK                     0x8000u
#define MCAN_HPMS_FLST_SHIFT                    15u
#define MCAN_HPMS_FLST_WIDTH                    1u
#define MCAN_HPMS_FLST(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_HPMS_FLST_SHIFT)) \
                                                  &MCAN_HPMS_FLST_MASK)
/* NDAT1 Bit Fields */
#define MCAN_NDAT1_ND1_MASK                     0xFFFFFFFFu
#define MCAN_NDAT1_ND1_SHIFT                    0u
#define MCAN_NDAT1_ND1_WIDTH                    32u
#define MCAN_NDAT1_ND1(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_NDAT1_ND1_SHIFT)) \
                                                  &MCAN_NDAT1_ND1_MASK)
/* NDAT2 Bit Fields */
#define MCAN_NDAT2_ND2_MASK                     0xFFFFFFFFu
#define MCAN_NDAT2_ND2_SHIFT                    0u
#define MCAN_NDAT2_ND2_WIDTH                    32u
#define MCAN_NDAT2_ND2(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_NDAT2_ND2_SHIFT)) \
                                                  &MCAN_NDAT2_ND2_MASK)
/* RXF0C Bit Fields */
#define MCAN_RXF0C_F0SA_MASK                    0xFFFCu
#define MCAN_RXF0C_F0SA_SHIFT                   2u
#define MCAN_RXF0C_F0SA_WIDTH                   14u
#define MCAN_RXF0C_F0SA(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXF0C_F0SA_SHIFT)) \
                                                  &MCAN_RXF0C_F0SA_MASK)
#define MCAN_RXF0C_F0S_MASK                     0x7F0000u
#define MCAN_RXF0C_F0S_SHIFT                    16u
#define MCAN_RXF0C_F0S_WIDTH                    7u
#define MCAN_RXF0C_F0S(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXF0C_F0S_SHIFT)) \
                                                  &MCAN_RXF0C_F0S_MASK)
#define MCAN_RXF0C_F0WM_MASK                    0x7F000000u
#define MCAN_RXF0C_F0WM_SHIFT                   24u
#define MCAN_RXF0C_F0WM_WIDTH                   7u
#define MCAN_RXF0C_F0WM(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXF0C_F0WM_SHIFT)) \
                                                  &MCAN_RXF0C_F0WM_MASK)
#define MCAN_RXF0C_F0OM_MASK                    0x80000000u
#define MCAN_RXF0C_F0OM_SHIFT                   31u
#define MCAN_RXF0C_F0OM_WIDTH                   1u
#define MCAN_RXF0C_F0OM(x)                      ((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXF0C_F0OM_SHIFT))
/* RXF0S Bit Fields */
#define MCAN_RXF0S_F0FL_MASK                    0x7Fu
#define MCAN_RXF0S_F0FL_SHIFT                   0u
#define MCAN_RXF0S_F0FL_WIDTH                   7u
#define MCAN_RXF0S_F0FL(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXF0S_F0FL_SHIFT)) \
                                                  &MCAN_RXF0S_F0FL_MASK)
#define MCAN_RXF0S_F0GI_MASK                    0x3F00u
#define MCAN_RXF0S_F0GI_SHIFT                   8u
#define MCAN_RXF0S_F0GI_WIDTH                   6u
#define MCAN_RXF0S_F0GI(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXF0S_F0GI_SHIFT)) \
                                                  &MCAN_RXF0S_F0GI_MASK)
#define MCAN_RXF0S_F0PI_MASK                    0x3F0000u
#define MCAN_RXF0S_F0PI_SHIFT                   16u
#define MCAN_RXF0S_F0PI_WIDTH                   6u
#define MCAN_RXF0S_F0PI(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXF0S_F0PI_SHIFT)) \
                                                  &MCAN_RXF0S_F0PI_MASK)
#define MCAN_RXF0S_F0F_MASK                     0x1000000u
#define MCAN_RXF0S_F0F_SHIFT                    24u
#define MCAN_RXF0S_F0F_WIDTH                    1u
#define MCAN_RXF0S_F0F(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXF0S_F0F_SHIFT)) \
                                                  &MCAN_RXF0S_F0F_MASK)
#define MCAN_RXF0S_RF0L_MASK                    0x2000000u
#define MCAN_RXF0S_RF0L_SHIFT                   25u
#define MCAN_RXF0S_RF0L_WIDTH                   1u
#define MCAN_RXF0S_RF0L(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXF0S_RF0L_SHIFT)) \
                                                  &MCAN_RXF0S_RF0L_MASK)
/* RXF0A Bit Fields */
#define MCAN_RXF0A_F0AI_MASK                    0x3Fu
#define MCAN_RXF0A_F0AI_SHIFT                   0u
#define MCAN_RXF0A_F0AI_WIDTH                   6u
#define MCAN_RXF0A_F0AI(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXF0A_F0AI_SHIFT)) \
                                                  &MCAN_RXF0A_F0AI_MASK)
/* RXBC Bit Fields */
#define MCAN_RXBC_RBSA_MASK                     0xFFFCu
#define MCAN_RXBC_RBSA_SHIFT                    2u
#define MCAN_RXBC_RBSA_WIDTH                    14u
#define MCAN_RXBC_RBSA(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXBC_RBSA_SHIFT)) \
                                                  &MCAN_RXBC_RBSA_MASK)
/* RXF1C Bit Fields */
#define MCAN_RXF1C_F1SA_MASK                    0xFFFCu
#define MCAN_RXF1C_F1SA_SHIFT                   2u
#define MCAN_RXF1C_F1SA_WIDTH                   14u
#define MCAN_RXF1C_F1SA(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXF1C_F1SA_SHIFT)) \
                                                  &MCAN_RXF1C_F1SA_MASK)
#define MCAN_RXF1C_F1S_MASK                     0x7F0000u
#define MCAN_RXF1C_F1S_SHIFT                    16u
#define MCAN_RXF1C_F1S_WIDTH                    7u
#define MCAN_RXF1C_F1S(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXF1C_F1S_SHIFT)) \
                                                  &MCAN_RXF1C_F1S_MASK)
#define MCAN_RXF1C_F1WM_MASK                    0x7F000000u
#define MCAN_RXF1C_F1WM_SHIFT                   24u
#define MCAN_RXF1C_F1WM_WIDTH                   7u
#define MCAN_RXF1C_F1WM(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXF1C_F1WM_SHIFT)) \
                                                  &MCAN_RXF1C_F1WM_MASK)
#define MCAN_RXF1C_F1OM_MASK                    0x80000000u
#define MCAN_RXF1C_F1OM_SHIFT                   31u
#define MCAN_RXF1C_F1OM_WIDTH                   1u
#define MCAN_RXF1C_F1OM(x)                      ((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXF1C_F1OM_SHIFT))
/* RXF1S Bit Fields */
#define MCAN_RXF1S_F1FL_MASK                    0x7Fu
#define MCAN_RXF1S_F1FL_SHIFT                   0u
#define MCAN_RXF1S_F1FL_WIDTH                   7u
#define MCAN_RXF1S_F1FL(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXF1S_F1FL_SHIFT)) \
                                                  &MCAN_RXF1S_F1FL_MASK)
#define MCAN_RXF1S_F1GI_MASK                    0x3F00u
#define MCAN_RXF1S_F1GI_SHIFT                   8u
#define MCAN_RXF1S_F1GI_WIDTH                   6u
#define MCAN_RXF1S_F1GI(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXF1S_F1GI_SHIFT)) \
                                                  &MCAN_RXF1S_F1GI_MASK)
#define MCAN_RXF1S_F1PI_MASK                    0x3F0000u
#define MCAN_RXF1S_F1PI_SHIFT                   16u
#define MCAN_RXF1S_F1PI_WIDTH                   6u
#define MCAN_RXF1S_F1PI(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXF1S_F1PI_SHIFT)) \
                                                  &MCAN_RXF1S_F1PI_MASK)
#define MCAN_RXF1S_F1F_MASK                     0x1000000u
#define MCAN_RXF1S_F1F_SHIFT                    24u
#define MCAN_RXF1S_F1F_WIDTH                    1u
#define MCAN_RXF1S_F1F(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXF1S_F1F_SHIFT)) \
                                                  &MCAN_RXF1S_F1F_MASK)
#define MCAN_RXF1S_RF1L_MASK                    0x2000000u
#define MCAN_RXF1S_RF1L_SHIFT                   25u
#define MCAN_RXF1S_RF1L_WIDTH                   1u
#define MCAN_RXF1S_RF1L(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXF1S_RF1L_SHIFT)) \
                                                  &MCAN_RXF1S_RF1L_MASK)
#define MCAN_RXF1S_DMS_MASK                     0xC0000000u
#define MCAN_RXF1S_DMS_SHIFT                    30u
#define MCAN_RXF1S_DMS_WIDTH                    2u
#define MCAN_RXF1S_DMS(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXF1S_DMS_SHIFT)) \
                                                  &MCAN_RXF1S_DMS_MASK)
/* RXF1A Bit Fields */
#define MCAN_RXF1A_F1AI_MASK                    0x3Fu
#define MCAN_RXF1A_F1AI_SHIFT                   0u
#define MCAN_RXF1A_F1AI_WIDTH                   6u
#define MCAN_RXF1A_F1AI(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXF1A_F1AI_SHIFT)) \
                                                  &MCAN_RXF1A_F1AI_MASK)
/* RXESC Bit Fields */
#define MCAN_RXESC_F0DS_MASK                    0x7u
#define MCAN_RXESC_F0DS_SHIFT                   0u
#define MCAN_RXESC_F0DS_WIDTH                   3u
#define MCAN_RXESC_F0DS(x)                      (((uint32)(x)) \
                                                  &MCAN_RXESC_F0DS_MASK)
#define MCAN_RXESC_F1DS_MASK                    0x70u
#define MCAN_RXESC_F1DS_SHIFT                   4u
#define MCAN_RXESC_F1DS_WIDTH                   3u
#define MCAN_RXESC_F1DS(x)                      ((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXESC_F1DS_SHIFT))
#define MCAN_RXESC_RBDS_MASK                    0x700u
#define MCAN_RXESC_RBDS_SHIFT                   8u
#define MCAN_RXESC_RBDS_WIDTH                   3u
#define MCAN_RXESC_RBDS(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_RXESC_RBDS_SHIFT)) \
                                                  &MCAN_RXESC_RBDS_MASK)
/* TXBC Bit Fields */
#define MCAN_TXBC_TBSA_MASK                     0xFFFCu
#define MCAN_TXBC_TBSA_SHIFT                    2u
#define MCAN_TXBC_TBSA_WIDTH                    14u
#define MCAN_TXBC_TBSA(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXBC_TBSA_SHIFT)) \
                                                  &MCAN_TXBC_TBSA_MASK)
#define MCAN_TXBC_NDTB_MASK                     0x3F0000u
#define MCAN_TXBC_NDTB_SHIFT                    16u
#define MCAN_TXBC_NDTB_WIDTH                    6u
#define MCAN_TXBC_NDTB(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXBC_NDTB_SHIFT)) \
                                                  &MCAN_TXBC_NDTB_MASK)
#define MCAN_TXBC_TFQS_MASK                     0x3F000000u
#define MCAN_TXBC_TFQS_SHIFT                    24u
#define MCAN_TXBC_TFQS_WIDTH                    6u
#define MCAN_TXBC_TFQS(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXBC_TFQS_SHIFT)) \
                                                  &MCAN_TXBC_TFQS_MASK)
#define MCAN_TXBC_TFQM_MASK                     0x40000000u
#define MCAN_TXBC_TFQM_SHIFT                    30u
#define MCAN_TXBC_TFQM_WIDTH                    1u
#define MCAN_TXBC_TFQM(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXBC_TFQM_SHIFT)) \
                                                  &MCAN_TXBC_TFQM_MASK)
/* TXFQS Bit Fields */
#define MCAN_TXFQS_TFFL_MASK                    0x3Fu
#define MCAN_TXFQS_TFFL_SHIFT                   0u
#define MCAN_TXFQS_TFFL_WIDTH                   6u
#define MCAN_TXFQS_TFFL(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXFQS_TFFL_SHIFT)) \
                                                  &MCAN_TXFQS_TFFL_MASK)
#define MCAN_TXFQS_TFGI_MASK                    0x1F00u
#define MCAN_TXFQS_TFGI_SHIFT                   8u
#define MCAN_TXFQS_TFGI_WIDTH                   5u
#define MCAN_TXFQS_TFGI(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXFQS_TFGI_SHIFT)) \
                                                  &MCAN_TXFQS_TFGI_MASK)
#define MCAN_TXFQS_TFQPI_MASK                   0x1F0000u
#define MCAN_TXFQS_TFQPI_SHIFT                  16u
#define MCAN_TXFQS_TFQPI_WIDTH                  5u
#define MCAN_TXFQS_TFQPI(x)                     (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXFQS_TFQPI_SHIFT)) \
                                                  &MCAN_TXFQS_TFQPI_MASK)
#define MCAN_TXFQS_TFQF_MASK                    0x200000u
#define MCAN_TXFQS_TFQF_SHIFT                   21u
#define MCAN_TXFQS_TFQF_WIDTH                   1u
#define MCAN_TXFQS_TFQF(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXFQS_TFQF_SHIFT)) \
                                                  &MCAN_TXFQS_TFQF_MASK)
/* TXESC Bit Fields */
#define MCAN_TXESC_TBDS_MASK                    0x7u
#define MCAN_TXESC_TBDS_SHIFT                   0u
#define MCAN_TXESC_TBDS_WIDTH                   3u
#define MCAN_TXESC_TBDS(x)                      (((uint32)(x)) \
                                                  &MCAN_TXESC_TBDS_MASK)
/* TXBRP Bit Fields */
#define MCAN_TXBRP_TRP_MASK                     0xFFFFFFFFu
#define MCAN_TXBRP_TRP_SHIFT                    0u
#define MCAN_TXBRP_TRP_WIDTH                    32u
#define MCAN_TXBRP_TRP(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXBRP_TRP_SHIFT)) \
                                                  &MCAN_TXBRP_TRP_MASK)
/* TXBAR Bit Fields */
#define MCAN_TXBAR_AR_MASK                      0xFFFFFFFFu
#define MCAN_TXBAR_AR_SHIFT                     0u
#define MCAN_TXBAR_AR_WIDTH                     32u
#define MCAN_TXBAR_AR(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXBAR_AR_SHIFT)) \
                                                  &MCAN_TXBAR_AR_MASK)
/* TXBCR Bit Fields */
#define MCAN_TXBCR_CR_MASK                      0xFFFFFFFFu
#define MCAN_TXBCR_CR_SHIFT                     0u
#define MCAN_TXBCR_CR_WIDTH                     32u
#define MCAN_TXBCR_CR(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXBCR_CR_SHIFT)) \
                                                  &MCAN_TXBCR_CR_MASK)
/* TXBTO Bit Fields */
#define MCAN_TXBTO_TO_MASK                      0xFFFFFFFFu
#define MCAN_TXBTO_TO_SHIFT                     0u
#define MCAN_TXBTO_TO_WIDTH                     32u
#define MCAN_TXBTO_TO(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXBTO_TO_SHIFT)) \
                                                  &MCAN_TXBTO_TO_MASK)
/* TXBCF Bit Fields */
#define MCAN_TXBCF_CF_MASK                      0xFFFFFFFFu
#define MCAN_TXBCF_CF_SHIFT                     0u
#define MCAN_TXBCF_CF_WIDTH                     32u
#define MCAN_TXBCF_CF(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXBCF_CF_SHIFT)) \
                                                  &MCAN_TXBCF_CF_MASK)
/* TXBTIE Bit Fields */
#define MCAN_TXBTIE_TIE_MASK                    0xFFFFFFFFu
#define MCAN_TXBTIE_TIE_SHIFT                   0u
#define MCAN_TXBTIE_TIE_WIDTH                   32u
#define MCAN_TXBTIE_TIE(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXBTIE_TIE_SHIFT)) \
                                                  &MCAN_TXBTIE_TIE_MASK)
/* TXBCIE Bit Fields */
#define MCAN_TXBCIE_CFIE_MASK                   0xFFFFFFFFu
#define MCAN_TXBCIE_CFIE_SHIFT                  0u
#define MCAN_TXBCIE_CFIE_WIDTH                  32u
#define MCAN_TXBCIE_CFIE(x)                     (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXBCIE_CFIE_SHIFT)) \
                                                  &MCAN_TXBCIE_CFIE_MASK)
/* TXEFC Bit Fields */
#define MCAN_TXEFC_EFSA_MASK                    0xFFFCu
#define MCAN_TXEFC_EFSA_SHIFT                   2u
#define MCAN_TXEFC_EFSA_WIDTH                   14u
#define MCAN_TXEFC_EFSA(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXEFC_EFSA_SHIFT)) \
                                                  &MCAN_TXEFC_EFSA_MASK)
#define MCAN_TXEFC_EFS_MASK                     0x3F0000u
#define MCAN_TXEFC_EFS_SHIFT                    16u
#define MCAN_TXEFC_EFS_WIDTH                    6u
#define MCAN_TXEFC_EFS(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXEFC_EFS_SHIFT)) \
                                                  &MCAN_TXEFC_EFS_MASK)
#define MCAN_TXEFC_EFWM_MASK                    0x3F000000u
#define MCAN_TXEFC_EFWM_SHIFT                   24u
#define MCAN_TXEFC_EFWM_WIDTH                   6u
#define MCAN_TXEFC_EFWM(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXEFC_EFWM_SHIFT)) \
                                                  &MCAN_TXEFC_EFWM_MASK)
/* TXEFS Bit Fields */
#define MCAN_TXEFS_EFFL_MASK                    0x3Fu
#define MCAN_TXEFS_EFFL_SHIFT                   0u
#define MCAN_TXEFS_EFFL_WIDTH                   6u
#define MCAN_TXEFS_EFFL(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXEFS_EFFL_SHIFT)) \
                                                  &MCAN_TXEFS_EFFL_MASK)
#define MCAN_TXEFS_EFGI_MASK                    0x1F00u
#define MCAN_TXEFS_EFGI_SHIFT                   8u
#define MCAN_TXEFS_EFGI_WIDTH                   5u
#define MCAN_TXEFS_EFGI(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXEFS_EFGI_SHIFT)) \
                                                  &MCAN_TXEFS_EFGI_MASK)
#define MCAN_TXEFS_EFPI_MASK                    0x1F0000u
#define MCAN_TXEFS_EFPI_SHIFT                   16u
#define MCAN_TXEFS_EFPI_WIDTH                   5u
#define MCAN_TXEFS_EFPI(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXEFS_EFPI_SHIFT)) \
                                                  &MCAN_TXEFS_EFPI_MASK)
#define MCAN_TXEFS_EFF_MASK                     0x1000000u
#define MCAN_TXEFS_EFF_SHIFT                    24u
#define MCAN_TXEFS_EFF_WIDTH                    1u
#define MCAN_TXEFS_EFF(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXEFS_EFF_SHIFT)) \
                                                  &MCAN_TXEFS_EFF_MASK)
#define MCAN_TXEFS_TEFL_MASK                    0x2000000u
#define MCAN_TXEFS_TEFL_SHIFT                   25u
#define MCAN_TXEFS_TEFL_WIDTH                   1u
#define MCAN_TXEFS_TEFL(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXEFS_TEFL_SHIFT)) \
                                                  &MCAN_TXEFS_TEFL_MASK)
/* TXEFA Bit Fields */
#define MCAN_TXEFA_EFAI_MASK                    0x1Fu
#define MCAN_TXEFA_EFAI_SHIFT                   0u
#define MCAN_TXEFA_EFAI_WIDTH                   5u
#define MCAN_TXEFA_EFAI(x)                      (((uint32)(((uint32)(x)) \
                                                  <<MCAN_TXEFA_EFAI_SHIFT)) \
                                                  &MCAN_TXEFA_EFAI_MASK)

/* DMUCR Bit Fields */
#define M_CAN_DMUCR_DAY_MASK                      0xFFu
#define M_CAN_DMUCR_DAY_SHIFT                     0u
#define M_CAN_DMUCR_DAY_WIDTH                     8u
#define M_CAN_DMUCR_DAY(x)                        (((uint32_t)(((uint32_t)(x))<<M_CAN_CREL_DAY_SHIFT))&M_CAN_CREL_DAY_MASK)
#define M_CAN_DMUCR_MON_MASK                      0xFF00u
#define M_CAN_DMUCR_MON_SHIFT                     8u
#define M_CAN_DMUCR_MON_WIDTH                     8u
#define M_CAN_DMUCR_MON(x)                        (((uint32_t)(((uint32_t)(x))<<M_CAN_CREL_MON_SHIFT))&M_CAN_CREL_MON_MASK)
#define M_CAN_DMUCR_YEAR_MASK                     0xF0000u
#define M_CAN_DMUCR_YEAR_SHIFT                    16u
#define M_CAN_DMUCR_YEAR_WIDTH                    4u
#define M_CAN_DMUCR_YEAR(x)                       (((uint32_t)(((uint32_t)(x))<<M_CAN_CREL_YEAR_SHIFT))&M_CAN_CREL_YEAR_MASK)
#define M_CAN_DMUCR_SUBSTEP_MASK                  0xF00000u
#define M_CAN_DMUCR_SUBSTEP_SHIFT                 20u
#define M_CAN_DMUCR_SUBSTEP_WIDTH                 4u
#define M_CAN_DMUCR_SUBSTEP(x)                    (((uint32_t)(((uint32_t)(x))<<M_CAN_CREL_SUBSTEP_SHIFT))&M_CAN_CREL_SUBSTEP_MASK)
#define M_CAN_DMUCR_STEP_MASK                     0xF000000u
#define M_CAN_DMUCR_STEP_SHIFT                    24u
#define M_CAN_DMUCR_STEP_WIDTH                    4u
#define M_CAN_DMUCR_STEP(x)                       (((uint32_t)(((uint32_t)(x))<<M_CAN_CREL_STEP_SHIFT))&M_CAN_CREL_STEP_MASK)
#define M_CAN_DMUCR_REL_MASK                      0xF0000000u
#define M_CAN_DMUCR_REL_SHIFT                     28u
#define M_CAN_DMUCR_REL_WIDTH                     4u
#define M_CAN_DMUCR_REL(x)                        (((uint32_t)(((uint32_t)(x))<<M_CAN_CREL_REL_SHIFT))&M_CAN_CREL_REL_MASK)

/* DMUI Bit Fields */
#define M_CAN_DMUI_TXR_MASK                       0x1u
#define M_CAN_DMUI_TXR_SHIFT                      0u
#define M_CAN_DMUI_TXR_WIDTH                      1u
#define M_CAN_DMUI_TXR(x)                         (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUI_TXR_SHIFT))&M_CAN_DMUI_TXR_MASK)
#define M_CAN_DMUI_RX0R_MASK                      0x2u
#define M_CAN_DMUI_RX0R_SHIFT                     1u
#define M_CAN_DMUI_RX0R_WIDTH                     1u
#define M_CAN_DMUI_RX0R(x)                        (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUI_RX0R_SHIFT))&M_CAN_DMUI_RX0R_MASK)
#define M_CAN_DMUI_RX1R_MASK                      0x4u
#define M_CAN_DMUI_RX1R_SHIFT                     2u
#define M_CAN_DMUI_RX1R_WIDTH                     1u
#define M_CAN_DMUI_RX1R(x)                        (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUI_RX1R_SHIFT))&M_CAN_DMUI_RX1R_MASK)
#define M_CAN_DMUI_TXER_MASK                      0x8u
#define M_CAN_DMUI_TXER_SHIFT                     3u
#define M_CAN_DMUI_TXER_WIDTH                     1u
#define M_CAN_DMUI_TXER(x)                        (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUI_TXER_SHIFT))&M_CAN_DMUI_TXER_MASK)
#define M_CAN_DMUI_TXQPIP_MASK                    0x1F00u
#define M_CAN_DMUI_TXQPIP_SHIFT                   8u
#define M_CAN_DMUI_TXQPIP_WIDTH                   5u
#define M_CAN_DMUI_TXQPIP(x)                      (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUI_TXQPIP_SHIFT))&M_CAN_DMUI_TXQPIP_MASK)
#define M_CAN_DMUI_ENA_MASK                       0x8000u
#define M_CAN_DMUI_ENA_SHIFT                      15u
#define M_CAN_DMUI_ENA_WIDTH                      1u
#define M_CAN_DMUI_ENA(x)                         (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUI_ENA_SHIFT))&M_CAN_DMUI_ENA_MASK)
#define M_CAN_DMUI_DEHS_MASK                      0x70000u
#define M_CAN_DMUI_DEHS_SHIFT                     16u
#define M_CAN_DMUI_DEHS_WIDTH                     3u
#define M_CAN_DMUI_DEHS(x)                        (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUI_DEHS_SHIFT))&M_CAN_DMUI_DEHS_MASK)
#define M_CAN_DMUI_DTX_MASK                       0x100000u
#define M_CAN_DMUI_DTX_SHIFT                      20u
#define M_CAN_DMUI_DTX_WIDTH                      1u
#define M_CAN_DMUI_DTX(x)                         (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUI_DTX_SHIFT))&M_CAN_DMUI_DTX_MASK)
#define M_CAN_DMUI_DRX0_MASK                      0x200000u
#define M_CAN_DMUI_DRX0_SHIFT                     21u
#define M_CAN_DMUI_DRX0_WIDTH                     1u
#define M_CAN_DMUI_DRX0(x)                        (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUI_DRX0_SHIFT))&M_CAN_DMUI_DRX0_MASK)
#define M_CAN_DMUI_DRX1_MASK                      0x400000u
#define M_CAN_DMUI_DRX1_SHIFT                     22u
#define M_CAN_DMUI_DRX1_WIDTH                     1u
#define M_CAN_DMUI_DRX1(x)                        (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUI_DRX1_SHIFT))&M_CAN_DMUI_DRX1_MASK)
#define M_CAN_DMUI_DTXE_MASK                      0x800000u
#define M_CAN_DMUI_DTXE_SHIFT                     23u
#define M_CAN_DMUI_DTXE_WIDTH                     1u
#define M_CAN_DMUI_DTXE(x)                        (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUI_DTXE_SHIFT))&M_CAN_DMUI_DTXE_MASK)
#define M_CAN_DMUI_EHS_MASK                       0x7000000u
#define M_CAN_DMUI_EHS_SHIFT                      24u
#define M_CAN_DMUI_EHS_WIDTH                      3u
#define M_CAN_DMUI_EHS(x)                         (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUI_EHS_SHIFT))&M_CAN_DMUI_EHS_MASK)
#define M_CAN_DMUI_TX_MASK                        0x10000000u
#define M_CAN_DMUI_TX_SHIFT                       28u
#define M_CAN_DMUI_TX_WIDTH                       1u
#define M_CAN_DMUI_TX(x)                          (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUI_TX_SHIFT))&M_CAN_DMUI_TX_MASK)
#define M_CAN_DMUI_RX0_MASK                       0x20000000u
#define M_CAN_DMUI_RX0_SHIFT                      29u
#define M_CAN_DMUI_RX0_WIDTH                      1u
#define M_CAN_DMUI_RX0(x)                         (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUI_RX0_SHIFT))&M_CAN_DMUI_RX0_MASK)
#define M_CAN_DMUI_RX1_MASK                       0x40000000u
#define M_CAN_DMUI_RX1_SHIFT                      30u
#define M_CAN_DMUI_RX1_WIDTH                      1u
#define M_CAN_DMUI_RX1(x)                         (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUI_RX1_SHIFT))&M_CAN_DMUI_RX1_MASK)
#define M_CAN_DMUI_TXE_MASK                       0x80000000u
#define M_CAN_DMUI_TXE_SHIFT                      31u
#define M_CAN_DMUI_TXE_WIDTH                      1u
#define M_CAN_DMUI_TXE(x)                         (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUI_TXE_SHIFT))&M_CAN_DMUI_TXE_MASK)

/* DMUQC Bit Fields */
#define M_CAN_DMUQC_TXEEC_MASK                    0xFFu
#define M_CAN_DMUQC_TXEEC_SHIFT                   0u
#define M_CAN_DMUQC_TXEEC_WIDTH                   8u
#define M_CAN_DMUQC_TXEEC(x)                      (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUQC_TXEEC_SHIFT))&M_CAN_DMUQC_TXEEC_MASK)
#define M_CAN_DMUQC_RX0EDC_MASK                   0xFF00u
#define M_CAN_DMUQC_RX0EDC_SHIFT                  8u
#define M_CAN_DMUQC_RX0EDC_WIDTH                  8u
#define M_CAN_DMUQC_RX0EDC(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUQC_RX0EDC_SHIFT))&M_CAN_DMUQC_RX0EDC_MASK)
#define M_CAN_DMUQC_RX1EDC_MASK                   0xFF0000u
#define M_CAN_DMUQC_RX1EDC_SHIFT                  16u
#define M_CAN_DMUQC_RX1EDC_WIDTH                  8u
#define M_CAN_DMUQC_RX1EDC(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUQC_RX1EDC_SHIFT))&M_CAN_DMUQC_RX1EDC_MASK)
#define M_CAN_DMUQC_TXEEDC_MASK                   0xFF000000u
#define M_CAN_DMUQC_TXEEDC_SHIFT                  24u
#define M_CAN_DMUQC_TXEEDC_WIDTH                  8u
#define M_CAN_DMUQC_TXEEDC(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUQC_TXEEDC_SHIFT))&M_CAN_DMUQC_TXEEDC_MASK)

/* DMUIR Bit Fields */
#define M_CAN_DMUIR_TXENSA_MASK                   0x1u
#define M_CAN_DMUIR_TXENSA_SHIFT                  0u
#define M_CAN_DMUIR_TXENSA_WIDTH                  1u
#define M_CAN_DMUIR_TXENSA(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_TXENSA_SHIFT))&M_CAN_DMUIR_TXENSA_MASK)
#define M_CAN_DMUIR_TXEIE_MASK                    0x2u
#define M_CAN_DMUIR_TXEIE_SHIFT                   1u
#define M_CAN_DMUIR_TXEIE_WIDTH                   1u
#define M_CAN_DMUIR_TXEIE(x)                      (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_TXEIE_SHIFT))&M_CAN_DMUIR_TXEIE_MASK)
#define M_CAN_DMUIR_TXEIAS_MASK                   0x4u
#define M_CAN_DMUIR_TXEIAS_SHIFT                  2u
#define M_CAN_DMUIR_TXEIAS_WIDTH                  1u
#define M_CAN_DMUIR_TXEIAS(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_TXEIAS_SHIFT))&M_CAN_DMUIR_TXEIAS_MASK)
#define M_CAN_DMUIR_TXEIDLC_MASK                  0x8u
#define M_CAN_DMUIR_TXEIDLC_SHIFT                 3u
#define M_CAN_DMUIR_TXEIDLC_WIDTH                 1u
#define M_CAN_DMUIR_TXEIDLC(x)                    (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_TXEIDLC_SHIFT))&M_CAN_DMUIR_TXEIDLC_MASK)
#define M_CAN_DMUIR_TXEWATA_MASK                  0x10u
#define M_CAN_DMUIR_TXEWATA_SHIFT                 4u
#define M_CAN_DMUIR_TXEWATA_WIDTH                 1u
#define M_CAN_DMUIR_TXEWATA(x)                    (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_TXEWATA_SHIFT))&M_CAN_DMUIR_TXEWATA_MASK)
#define M_CAN_DMUIR_TXEIR_MASK                    0x20u
#define M_CAN_DMUIR_TXEIR_SHIFT                   5u
#define M_CAN_DMUIR_TXEIR_WIDTH                   1u
#define M_CAN_DMUIR_TXEIR(x)                      (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_TXEIR_SHIFT))&M_CAN_DMUIR_TXEIR_MASK)
#define M_CAN_DMUIR_TXEE_MASK                     0x40u
#define M_CAN_DMUIR_TXEE_SHIFT                    6u
#define M_CAN_DMUIR_TXEE_WIDTH                    1u
#define M_CAN_DMUIR_TXEE(x)                       (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_TXEE_SHIFT))&M_CAN_DMUIR_TXEE_MASK)
#define M_CAN_DMUIR_RX0ENSA_MASK                  0x100u
#define M_CAN_DMUIR_RX0ENSA_SHIFT                 8u
#define M_CAN_DMUIR_RX0ENSA_WIDTH                 1u
#define M_CAN_DMUIR_RX0ENSA(x)                    (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_RX0ENSA_SHIFT))&M_CAN_DMUIR_RX0ENSA_MASK)
#define M_CAN_DMUIR_RX0EID_MASK                   0x200u
#define M_CAN_DMUIR_RX0EID_SHIFT                  9u
#define M_CAN_DMUIR_RX0EID_WIDTH                  1u
#define M_CAN_DMUIR_RX0EID(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_RX0EID_SHIFT))&M_CAN_DMUIR_RX0EID_MASK)
#define M_CAN_DMUIR_RX0EIAS_MASK                  0x400u
#define M_CAN_DMUIR_RX0EIAS_SHIFT                 10u
#define M_CAN_DMUIR_RX0EIAS_WIDTH                 1u
#define M_CAN_DMUIR_RX0EIAS(x)                    (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_RX0EIAS_SHIFT))&M_CAN_DMUIR_RX0EIAS_MASK)
#define M_CAN_DMUIR_RX0EIW_MASK                   0x800u
#define M_CAN_DMUIR_RX0EIW_SHIFT                  11u
#define M_CAN_DMUIR_RX0EIW_WIDTH                  1u
#define M_CAN_DMUIR_RX0EIW(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_RX0EIW_SHIFT))&M_CAN_DMUIR_RX0EIW_MASK)
#define M_CAN_DMUIR_RX0ED_MASK                    0x1000u
#define M_CAN_DMUIR_RX0ED_SHIFT                   12u
#define M_CAN_DMUIR_RX0ED_WIDTH                   1u
#define M_CAN_DMUIR_RX0ED(x)                      (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_RX0ED_SHIFT))&M_CAN_DMUIR_RX0ED_MASK)
#define M_CAN_DMUIR_RX0EIO_MASK                   0x2000u
#define M_CAN_DMUIR_RX0EIO_SHIFT                  13u
#define M_CAN_DMUIR_RX0EIO_WIDTH                  1u
#define M_CAN_DMUIR_RX0EIO(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_RX0EIO_SHIFT))&M_CAN_DMUIR_RX0EIO_MASK)
#define M_CAN_DMUIR_BEC_MASK                      0x4000u
#define M_CAN_DMUIR_BEC_SHIFT                     14u
#define M_CAN_DMUIR_BEC_WIDTH                     1u
#define M_CAN_DMUIR_BEC(x)                        (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_BEC_SHIFT))&M_CAN_DMUIR_BEC_MASK)
#define M_CAN_DMUIR_BEU_MASK                      0x8000u
#define M_CAN_DMUIR_BEU_SHIFT                     15u
#define M_CAN_DMUIR_BEU_WIDTH                     1u
#define M_CAN_DMUIR_BEU(x)                        (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_BEU_SHIFT))&M_CAN_DMUIR_BEU_MASK)
#define M_CAN_DMUIR_RX1ENSA_MASK                  0x10000u
#define M_CAN_DMUIR_RX1ENSA_SHIFT                 16u
#define M_CAN_DMUIR_RX1ENSA_WIDTH                 1u
#define M_CAN_DMUIR_RX1ENSA(x)                    (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_RX1ENSA_SHIFT))&M_CAN_DMUIR_RX1ENSA_MASK)
#define M_CAN_DMUIR_RX1EID_MASK                   0x20000u
#define M_CAN_DMUIR_RX1EID_SHIFT                  17u
#define M_CAN_DMUIR_RX1EID_WIDTH                  1u
#define M_CAN_DMUIR_RX1EID(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_RX1EID_SHIFT))&M_CAN_DMUIR_RX1EID_MASK)
#define M_CAN_DMUIR_RX1EIAS_MASK                  0x40000u
#define M_CAN_DMUIR_RX1EIAS_SHIFT                 18u
#define M_CAN_DMUIR_RX1EIAS_WIDTH                 1u
#define M_CAN_DMUIR_RX1EIAS(x)                    (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_RX1EIAS_SHIFT))&M_CAN_DMUIR_RX1EIAS_MASK)
#define M_CAN_DMUIR_RX1EIW_MASK                   0x80000u
#define M_CAN_DMUIR_RX1EIW_SHIFT                  19u
#define M_CAN_DMUIR_RX1EIW_WIDTH                  1u
#define M_CAN_DMUIR_RX1EIW(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_RX1EIW_SHIFT))&M_CAN_DMUIR_RX1EIW_MASK)
#define M_CAN_DMUIR_RX1ED_MASK                    0x100000u
#define M_CAN_DMUIR_RX1ED_SHIFT                   20u
#define M_CAN_DMUIR_RX1ED_WIDTH                   1u
#define M_CAN_DMUIR_RX1ED(x)                      (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_RX1ED_SHIFT))&M_CAN_DMUIR_RX1ED_MASK)
#define M_CAN_DMUIR_RX1EIO_MASK                   0x200000u
#define M_CAN_DMUIR_RX1EIO_SHIFT                  21u
#define M_CAN_DMUIR_RX1EIO_WIDTH                  1u
#define M_CAN_DMUIR_RX1EIO(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_RX1EIO_SHIFT))&M_CAN_DMUIR_RX1EIO_MASK)
#define M_CAN_DMUIR_TXEENSA_MASK                  0x1000000u
#define M_CAN_DMUIR_TXEENSA_SHIFT                 24u
#define M_CAN_DMUIR_TXEENSA_WIDTH                 1u
#define M_CAN_DMUIR_TXEENSA(x)                    (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_TXEENSA_SHIFT))&M_CAN_DMUIR_TXEENSA_MASK)
#define M_CAN_DMUIR_TXEEID_MASK                   0x2000000u
#define M_CAN_DMUIR_TXEEID_SHIFT                  25u
#define M_CAN_DMUIR_TXEEID_WIDTH                  1u
#define M_CAN_DMUIR_TXEEID(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_TXEEID_SHIFT))&M_CAN_DMUIR_TXEEID_MASK)
#define M_CAN_DMUIR_TXEEIAS_MASK                  0x4000000u
#define M_CAN_DMUIR_TXEEIAS_SHIFT                 26u
#define M_CAN_DMUIR_TXEEIAS_WIDTH                 1u
#define M_CAN_DMUIR_TXEEIAS(x)                    (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_TXEEIAS_SHIFT))&M_CAN_DMUIR_TXEEIAS_MASK)
#define M_CAN_DMUIR_TXEEIW_MASK                   0x8000000u
#define M_CAN_DMUIR_TXEEIW_SHIFT                  27u
#define M_CAN_DMUIR_TXEEIW_WIDTH                  1u
#define M_CAN_DMUIR_TXEEIW(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_TXEEIW_SHIFT))&M_CAN_DMUIR_TXEEIW_MASK)
#define M_CAN_DMUIR_TXEED_MASK                    0x10000000u
#define M_CAN_DMUIR_TXEED_SHIFT                   28u
#define M_CAN_DMUIR_TXEED_WIDTH                   1u
#define M_CAN_DMUIR_TXEED(x)                      (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_TXEED_SHIFT))&M_CAN_DMUIR_TXEED_MASK)
#define M_CAN_DMUIR_DT_MASK                       0x20000000u
#define M_CAN_DMUIR_DT_SHIFT                      29u
#define M_CAN_DMUIR_DT_WIDTH                      1u
#define M_CAN_DMUIR_DT(x)                         (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_DT_SHIFT))&M_CAN_DMUIR_DT_MASK)
#define M_CAN_DMUIR_IAC_MASK                      0x40000000u
#define M_CAN_DMUIR_IAC_SHIFT                     30u
#define M_CAN_DMUIR_IAC_WIDTH                     1u
#define M_CAN_DMUIR_IAC(x)                        (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIR_IAC_SHIFT))&M_CAN_DMUIR_IAC_MASK)

/* DMUIE Bit Fields */
#define M_CAN_DMUIE_TXENSAE_MASK                   0x1u
#define M_CAN_DMUIE_TXENSAE_SHIFT                  0u
#define M_CAN_DMUIE_TXENSAE_WIDTH                  1u
#define M_CAN_DMUIE_TXENSAE(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_TXENSAE_SHIFT))&M_CAN_DMUIE_TXENSAE_MASK)
#define M_CAN_DMUIE_TXEIEE_MASK                    0x2u
#define M_CAN_DMUIE_TXEIEE_SHIFT                   1u
#define M_CAN_DMUIE_TXEIEE_WIDTH                   1u
#define M_CAN_DMUIE_TXEIEE(x)                      (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_TXEIEE_SHIFT))&M_CAN_DMUIE_TXEIEE_MASK)
#define M_CAN_DMUIE_TXEIASE_MASK                   0x4u
#define M_CAN_DMUIE_TXEIASE_SHIFT                  2u
#define M_CAN_DMUIE_TXEIASE_WIDTH                  1u
#define M_CAN_DMUIE_TXEIASE(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_TXEIASE_SHIFT))&M_CAN_DMUIE_TXEIASE_MASK)
#define M_CAN_DMUIE_TXEIDLCE_MASK                  0x8u
#define M_CAN_DMUIE_TXEIDLCE_SHIFT                 3u
#define M_CAN_DMUIE_TXEIDLCE_WIDTH                 1u
#define M_CAN_DMUIE_TXEIDLCE(x)                    (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_TXEIDLCE_SHIFT))&M_CAN_DMUIE_TXEIDLCE_MASK)
#define M_CAN_DMUIE_TXEWATAE_MASK                  0x10u
#define M_CAN_DMUIE_TXEWATAE_SHIFT                 4u
#define M_CAN_DMUIE_TXEWATAE_WIDTH                 1u
#define M_CAN_DMUIE_TXEWATAE(x)                    (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_TXEWATAE_SHIFT))&M_CAN_DMUIE_TXEWATAE_MASK)
#define M_CAN_DMUIE_TXEIRE_MASK                    0x20u
#define M_CAN_DMUIE_TXEIRE_SHIFT                   5u
#define M_CAN_DMUIE_TXEIRE_WIDTH                   1u
#define M_CAN_DMUIE_TXEIRE(x)                      (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_TXEIRE_SHIFT))&M_CAN_DMUIE_TXEIRE_MASK)
#define M_CAN_DMUIE_TXEEE_MASK                     0x40u
#define M_CAN_DMUIE_TXEEE_SHIFT                    6u
#define M_CAN_DMUIE_TXEEE_WIDTH                    1u
#define M_CAN_DMUIE_TXEEE(x)                       (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_TXEEE_SHIFT))&M_CAN_DMUIE_TXEEE_MASK)
#define M_CAN_DMUIE_RX0ENSAE_MASK                  0x100u
#define M_CAN_DMUIE_RX0ENSAE_SHIFT                 8u
#define M_CAN_DMUIE_RX0ENSAE_WIDTH                 1u
#define M_CAN_DMUIE_RX0ENSAE(x)                    (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_RX0ENSAE_SHIFT))&M_CAN_DMUIE_RX0ENSAE_MASK)
#define M_CAN_DMUIE_RX0EIDE_MASK                   0x200u
#define M_CAN_DMUIE_RX0EIDE_SHIFT                  9u
#define M_CAN_DMUIE_RX0EIDE_WIDTH                  1u
#define M_CAN_DMUIE_RX0EIDE(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_RX0EIDE_SHIFT))&M_CAN_DMUIE_RX0EIDE_MASK)
#define M_CAN_DMUIE_RX0EIASE_MASK                  0x400u
#define M_CAN_DMUIE_RX0EIASE_SHIFT                 10u
#define M_CAN_DMUIE_RX0EIASE_WIDTH                 1u
#define M_CAN_DMUIE_RX0EIASE(x)                    (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_RX0EIASE_SHIFT))&M_CAN_DMUIE_RX0EIASE_MASK)
#define M_CAN_DMUIE_RX0EIWE_MASK                   0x800u
#define M_CAN_DMUIE_RX0EIWE_SHIFT                  11u
#define M_CAN_DMUIE_RX0EIWE_WIDTH                  1u
#define M_CAN_DMUIE_RX0EIWE(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_RX0EIWE_SHIFT))&M_CAN_DMUIE_RX0EIWE_MASK)
#define M_CAN_DMUIE_RX0EDE_MASK                    0x1000u
#define M_CAN_DMUIE_RX0EDE_SHIFT                   12u
#define M_CAN_DMUIE_RX0EDE_WIDTH                   1u
#define M_CAN_DMUIE_RX0EDE(x)                      (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_RX0EDE_SHIFT))&M_CAN_DMUIE_RX0EDE_MASK)
#define M_CAN_DMUIE_RX0EIOE_MASK                   0x2000u
#define M_CAN_DMUIE_RX0EIOE_SHIFT                  13u
#define M_CAN_DMUIE_RX0EIOE_WIDTH                  1u
#define M_CAN_DMUIE_RX0EIOE(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_RX0EIOE_SHIFT))&M_CAN_DMUIE_RX0EIOE_MASK)
#define M_CAN_DMUIE_BECE_MASK                      0x4000u
#define M_CAN_DMUIE_BECE_SHIFT                     14u
#define M_CAN_DMUIE_BECE_WIDTH                     1u
#define M_CAN_DMUIE_BECE(x)                        (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_BECE_SHIFT))&M_CAN_DMUIE_BECE_MASK)
#define M_CAN_DMUIE_BEUE_MASK                      0x8000u
#define M_CAN_DMUIE_BEUE_SHIFT                     15u
#define M_CAN_DMUIE_BEUE_WIDTH                     1u
#define M_CAN_DMUIE_BEUE(x)                        (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_BEUE_SHIFT))&M_CAN_DMUIE_BEUE_MASK)
#define M_CAN_DMUIE_RX1ENSAE_MASK                  0x10000u
#define M_CAN_DMUIE_RX1ENSAE_SHIFT                 16u
#define M_CAN_DMUIE_RX1ENSAE_WIDTH                 1u
#define M_CAN_DMUIE_RX1ENSAE(x)                    (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_RX1ENSAE_SHIFT))&M_CAN_DMUIE_RX1ENSAE_MASK)
#define M_CAN_DMUIE_RX1EIDE_MASK                   0x20000u
#define M_CAN_DMUIE_RX1EIDE_SHIFT                  17u
#define M_CAN_DMUIE_RX1EIDE_WIDTH                  1u
#define M_CAN_DMUIE_RX1EIDE(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_RX1EIDE_SHIFT))&M_CAN_DMUIE_RX1EIDE_MASK)
#define M_CAN_DMUIE_RX1EIASE_MASK                  0x40000u
#define M_CAN_DMUIE_RX1EIASE_SHIFT                 18u
#define M_CAN_DMUIE_RX1EIASE_WIDTH                 1u
#define M_CAN_DMUIE_RX1EIASE(x)                    (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_RX1EIASE_SHIFT))&M_CAN_DMUIE_RX1EIASE_MASK)
#define M_CAN_DMUIE_RX1EIWE_MASK                   0x80000u
#define M_CAN_DMUIE_RX1EIWE_SHIFT                  19u
#define M_CAN_DMUIE_RX1EIWE_WIDTH                  1u
#define M_CAN_DMUIE_RX1EIWE(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_RX1EIWE_SHIFT))&M_CAN_DMUIE_RX1EIWE_MASK)
#define M_CAN_DMUIE_RX1EDE_MASK                    0x100000u
#define M_CAN_DMUIE_RX1EDE_SHIFT                   20u
#define M_CAN_DMUIE_RX1EDE_WIDTH                   1u
#define M_CAN_DMUIE_RX1EDE(x)                      (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_RX1EDE_SHIFT))&M_CAN_DMUIE_RX1EDE_MASK)
#define M_CAN_DMUIE_RX1EIOE_MASK                   0x200000u
#define M_CAN_DMUIE_RX1EIOE_SHIFT                  21u
#define M_CAN_DMUIE_RX1EIOE_WIDTH                  1u
#define M_CAN_DMUIE_RX1EIOE(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_RX1EIOE_SHIFT))&M_CAN_DMUIE_RX1EIOE_MASK)
#define M_CAN_DMUIE_TXEENSAE_MASK                  0x1000000u
#define M_CAN_DMUIE_TXEENSAE_SHIFT                 24u
#define M_CAN_DMUIE_TXEENSAE_WIDTH                 1u
#define M_CAN_DMUIE_TXEENSAE(x)                    (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_TXEENSAE_SHIFT))&M_CAN_DMUIE_TXEENSAE_MASK)
#define M_CAN_DMUIE_TXEEIDE_MASK                   0x2000000u
#define M_CAN_DMUIE_TXEEIDE_SHIFT                  25u
#define M_CAN_DMUIE_TXEEIDE_WIDTH                  1u
#define M_CAN_DMUIE_TXEEIDE(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_TXEEIDE_SHIFT))&M_CAN_DMUIE_TXEEIDE_MASK)
#define M_CAN_DMUIE_TXEEIASE_MASK                  0x4000000u
#define M_CAN_DMUIE_TXEEIASE_SHIFT                 26u
#define M_CAN_DMUIE_TXEEIASE_WIDTH                 1u
#define M_CAN_DMUIE_TXEEIASE(x)                    (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_TXEEIASE_SHIFT))&M_CAN_DMUIE_TXEEIASE_MASK)
#define M_CAN_DMUIE_TXEEIWE_MASK                   0x8000000u
#define M_CAN_DMUIE_TXEEIWE_SHIFT                  27u
#define M_CAN_DMUIE_TXEEIWE_WIDTH                  1u
#define M_CAN_DMUIE_TXEEIWE(x)                     (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_TXEEIWE_SHIFT))&M_CAN_DMUIE_TXEEIWE_MASK)
#define M_CAN_DMUIE_TXEEDE_MASK                    0x10000000u
#define M_CAN_DMUIE_TXEEDE_SHIFT                   28u
#define M_CAN_DMUIE_TXEEDE_WIDTH                   1u
#define M_CAN_DMUIE_TXEEDE(x)                      (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_TXEEDE_SHIFT))&M_CAN_DMUIE_TXEEDE_MASK)
#define M_CAN_DMUIE_DTE_MASK                       0x20000000u
#define M_CAN_DMUIE_DTE_SHIFT                      29u
#define M_CAN_DMUIE_DTE_WIDTH                      1u
#define M_CAN_DMUIE_DTE(x)                         (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_DTE_SHIFT))&M_CAN_DMUIE_DTE_MASK)
#define M_CAN_DMUIE_IACE_MASK                      0x40000000u
#define M_CAN_DMUIE_IACE_SHIFT                     30u
#define M_CAN_DMUIE_IACE_WIDTH                     1u
#define M_CAN_DMUIE_IACE(x)                        (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUIE_IACE_SHIFT))&M_CAN_DMUIE_IACE_MASK)

/* DMUC Bit Fields */
#define M_CAN_DMUC_TTS_MASK                        0x1u
#define M_CAN_DMUC_TTS_SHIFT                       0u
#define M_CAN_DMUC_TTS_WIDTH                       1u
#define M_CAN_DMUC_TTS(x)                          (((uint32_t)(((uint32_t)(x))<<M_CAN_DMUC_TTS_SHIFT))&M_CAN_DMUC_TTS_MASK)

/* ----------------------------------------------------------------------------
   -- Message RAM Masks
   ---------------------------------------------------------------------------- */

/* standard message id filter element */
#define MCAN_STD_FILTER_ID_SFT_MASK              0xC0000000U
#define MCAN_STD_FILTER_ID_SFT_SHIFT             30U
#define MCAN_STD_FILTER_ID_SFT_WIDTH             2U

#define MCAN_STD_FILTER_ID_SFEC_MASK             0x38000000U
#define MCAN_STD_FILTER_ID_SFEC_SHIFT            27U
#define MCAN_STD_FILTER_ID_SFEC_WIDTH            3U

#define MCAN_STD_FILTER_ID_SFID1_MASK            0x7FF0000U
#define MCAN_STD_FILTER_ID_SFID1_SHIFT           16U
#define MCAN_STD_FILTER_ID_SFID1_WIDTH           11U

#define MCAN_STD_FILTER_ID_SSYNC_MASK            0x0008000U
#define MCAN_STD_FILTER_ID_SSYNC_SHIFT           15U
#define MCAN_STD_FILTER_ID_SSYNC_WIDTH           1U

#define MCAN_STD_FILTER_ID_SFID2_MASK            0x7FFU
#define MCAN_STD_FILTER_ID_SFID2_SHIFT           0U
#define MCAN_STD_FILTER_ID_SFID2_WIDTH           11U

/* extended message id filter element */
#define MCAN_EXT_FILTER_ID_EFEC_MASK             0xE0000000U
#define MCAN_EXT_FILTER_ID_EFEC_SHIFT            29U
#define MCAN_EXT_FILTER_ID_EFEC_WIDTH            3U

#define MCAN_EXT_FILTER_ID_EFID1_MASK            0x1FFFFFFFU
#define MCAN_EXT_FILTER_ID_EFID1_SHIFT           0U
#define MCAN_EXT_FILTER_ID_EFID1_WIDTH           29U

#define MCAN_EXT_FILTER_ID_EFT_MASK              0xC0000000U
#define MCAN_EXT_FILTER_ID_EFT_SHIFT             30U
#define MCAN_EXT_FILTER_ID_EFT_WIDTH             2U

#define MCAN_EXT_FILTER_ID_ESYNC_MASK            0x20000000U
#define MCAN_EXT_FILTER_ID_ESYNC_SHIFT           29U
#define MCAN_EXT_FILTER_ID_ESYNC_WIDTH           1U

#define MCAN_EXT_FILTER_ID_EFID2_MASK            0x1FFFFFFFU
#define MCAN_EXT_FILTER_ID_EFID2_SHIFT           0U
#define MCAN_EXT_FILTER_ID_EFID2_WIDTH           29U

/* tx Buffer Element */
#define MCAN_MSG_ID_EXT_MASK                (0x80000000U)

#define MCAN_TX_BUFFER_ESI_MASK             0x80000000U
#define MCAN_TX_BUFFER_ESI_SHIFT            31U
#define MCAN_TX_BUFFER_ESI_WIDTH            1U

#define MCAN_TX_BUFFER_XTD_MASK             0x40000000U
#define MCAN_TX_BUFFER_XTD_SHIFT            30U
#define MCAN_TX_BUFFER_XTD_WIDTH            1U

#define MCAN_TX_BUFFER_RTR_MASK             0x20000000U
#define MCAN_TX_BUFFER_RTR_SHIFT            29U
#define MCAN_TX_BUFFER_RTR_WIDTH            1U

#define MCAN_TX_BUFFER_STD_ID_MASK          0x1FFC0000U
#define MCAN_TX_BUFFER_STD_ID_SHIFT         18U
#define MCAN_TX_BUFFER_STD_ID_WIDTH         11U

#define MCAN_TX_BUFFER_EXT_ID_MASK          0x1FFFFFFFU
#define MCAN_TX_BUFFER_EXT_ID_SHIFT         0U
#define MCAN_TX_BUFFER_EXT_ID_WIDTH         29U

#define MCAN_TX_BUFFER_MM_MASK              0xFF000000U
#define MCAN_TX_BUFFER_MM_SHIFT             24U
#define MCAN_TX_BUFFER_MM_WIDTH             8U

#define MCAN_TX_BUFFER_EFC_MASK             0x800000U
#define MCAN_TX_BUFFER_EFC_SHIFT            23U
#define MCAN_TX_BUFFER_EFC_WIDTH            1U

#define MCAN_TX_BUFFER_TSCE_MASK            0x400000U
#define MCAN_TX_BUFFER_TSCE_SHIFT           22U
#define MCAN_TX_BUFFER_TSCE_WIDTH           1U

#define MCAN_TX_BUFFER_FDF_MASK            0x200000U
#define MCAN_TX_BUFFER_FDF_SHIFT           21U
#define MCAN_TX_BUFFER_FDF_WIDTH           1U

#define MCAN_TX_BUFFER_BRS_MASK            0x100000U
#define MCAN_TX_BUFFER_BRS_SHIFT           20U
#define MCAN_TX_BUFFER_BRS_WIDTH           1U

#define MCAN_TX_BUFFER_DLC_MASK            0xF0000U
#define MCAN_TX_BUFFER_DLC_SHIFT           16U
#define MCAN_TX_BUFFER_DLC_WIDTH           4U

#define MCAN_TX_BUFFER_MM_HIGHBYTE_MASK    0xFF00U
#define MCAN_TX_BUFFER_MM_HBYTE_SHIFT      8U
#define MCAN_TX_BUFFER_MM_HBYTE_WIDTH      8U

/* tx event fifo element*/
#define MCAN_TX_EVENT_FIFO_ESI_MASK             0x80000000U
#define MCAN_TX_EVENT_FIFO_ESI_SHIFT            31U
#define MCAN_TX_EVENT_FIFO_ESI_WIDTH            1U

#define MCAN_TX_EVENT_FIFO_XTD_MASK             0x40000000U
#define MCAN_TX_EVENT_FIFO_XTD_SHIFT            30U
#define MCAN_TX_EVENT_FIFO_XTD_WIDTH            1U

#define MCAN_TX_EVENT_FIFO_RTR_MASK             0x20000000U
#define MCAN_TX_EVENT_FIFO_RTR_SHIFT            29U
#define MCAN_TX_EVENT_FIFO_RTR_WIDTH            1U

#define MCAN_TX_EVENT_FIFO_STD_ID_MASK          0x1FFC0000U
#define MCAN_TX_EVENT_FIFO_STD_ID_SHIFT         18U
#define MCAN_TX_EVENT_FIFO_STD_ID_WIDTH         11U

#define MCAN_TX_EVENT_FIFO_EXT_ID_MASK          0x1FFFFFFFU
#define MCAN_TX_EVENT_FIFO_EXT_ID_SHIFT         0U
#define MCAN_TX_EVENT_FIFO_EXT_ID_WIDTH         29U

#define MCAN_TX_EVENT_FIFO_MM_MASK              0xFF000000U
#define MCAN_TX_EVENT_FIFO_MM_SHIFT             24U
#define MCAN_TX_EVENT_FIFO_MM_WIDTH             8U

#define MCAN_TX_EVENT_FIFO_ET_MASK              0xC00000U
#define MCAN_TX_EVENT_FIFO_ET_SHIFT             22U
#define MCAN_TX_EVENT_FIFO_ET_WIDTH             2U

#define MCAN_TX_EVENT_FIFO_FDF_MASK             0x200000U
#define MCAN_TX_EVENT_FIFO_FDF_SHIFT            21U
#define MCAN_TX_EVENT_FIFO_FDF_WIDTH            1U

#define MCAN_TX_EVENT_FIFO_BRS_MASK             0x100000U
#define MCAN_TX_EVENT_FIFO_BRS_SHIFT            20U
#define MCAN_TX_EVENT_FIFO_BRS_WIDTH            1U

#define MCAN_TX_EVENT_FIFO_DLC_MASK             0xF0000U
#define MCAN_TX_EVENT_FIFO_DLC_SHIFT            16U
#define MCAN_TX_EVENT_FIFO_DLC_WIDTH            4U

#define MCAN_TX_EVENT_FIFO_TXTS_MASK            0xFFFFU
#define MCAN_TX_EVENT_FIFO_TXTS_SHIFT           0U
#define MCAN_TX_EVENT_FIFO_TXTS_WIDTH           16U

/*rx Buffer and FIFO Element*/ 

#define MCAN_RX_BUFFER_ESI_MASK             0x80000000U
#define MCAN_RX_BUFFER_ESI_SHIFT            31U
#define MCAN_RX_BUFFER_ESI_WIDTH            1U

#define MCAN_RX_BUFFER_XTD_MASK             0x40000000U
#define MCAN_RX_BUFFER_XTD_SHIFT            30U
#define MCAN_RX_BUFFER_XTD_WIDTH            1U

#define MCAN_RX_BUFFER_RTR_MASK             0x20000000U
#define MCAN_RX_BUFFER_RTR_SHIFT            29U
#define MCAN_RX_BUFFER_RTR_WIDTH            1U

#define MCAN_RX_BUFFER_STD_ID_MASK          0x1FFC0000U
#define MCAN_RX_BUFFER_STD_ID_SHIFT         18U
#define MCAN_RX_BUFFER_STD_ID_WIDTH         11U

#define MCAN_RX_BUFFER_EXT_ID_MASK          0x1FFFFFFFU
#define MCAN_RX_BUFFER_EXT_ID_SHIFT         0U
#define MCAN_RX_BUFFER_EXT_ID_WIDTH         29U

#define MCAN_RX_BUFFER_ANMF_MASK            0x80000000U
#define MCAN_RX_BUFFER_ANMF_SHIFT           31U
#define MCAN_RX_BUFFER_ANMF_WIDTH           1U

#define MCAN_RX_BUFFER_FIDX_MASK            0x7F000000U
#define MCAN_RX_BUFFER_FIDX_SHIFT           24U
#define MCAN_RX_BUFFER_FIDX_WIDTH           7U

#define MCAN_RX_BUFFER_FDF_MASK            0x200000U
#define MCAN_RX_BUFFER_FDF_SHIFT           21U
#define MCAN_RX_BUFFER_FDF_WIDTH           1U

#define MCAN_RX_BUFFER_BRS_MASK            0x100000U
#define MCAN_RX_BUFFER_BRS_SHIFT           20U
#define MCAN_RX_BUFFER_BRS_WIDTH           1U

#define MCAN_RX_BUFFER_DLC_MASK            0xF0000U
#define MCAN_RX_BUFFER_DLC_SHIFT           16U
#define MCAN_RX_BUFFER_DLC_WIDTH           4U

#define MCAN_RX_BUFFER_RXTS_MASK            0xFFFFU
#define MCAN_RX_BUFFER_RXTS_SHIFT           0U
#define MCAN_RX_BUFFER_RXTS_WIDTH           16U

#endif
