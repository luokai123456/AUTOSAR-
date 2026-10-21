#ifndef FR_REG_H_
#define FR_REG_H_

/* ============================================================================
   =============================== Module: FR =================================
   ============================================================================ */

typedef union FR_MVR_union_tag {       /* Module Version Register */
  vuint16_t R;
  struct {
    vuint16_t CHIVER:8;
    vuint16_t PEVER:8;
  } B;
} FR_MVR_tag;

typedef union FR_MCR_union_tag {       /* Module Configuration Register */
  vuint16_t R;
  struct {
    vuint16_t MEN:1;
    vuint16_t SBFF:1;                  /* System Bus Failure Freeze */
    vuint16_t SCM:1;
    vuint16_t CHB:1;
    vuint16_t CHA:1;
    vuint16_t SFFE:1;
    vuint16_t ECCE:1;
    vuint16_t  :1;                     /* Reserved bit, will not be changed. Application must not write any value different from the reset value. */
    vuint16_t FUM:1;
    vuint16_t FAM:1;
    vuint16_t  :1;
    vuint16_t CLKSEL:1;
    vuint16_t BITRATE:3;
    vuint16_t  :1;
  } B;
} FR_MCR_tag;

typedef union FR_SYMBADHR_union_tag {  /* System Memory Base Address High Register */
  vuint16_t R;
  struct {
    vuint16_t SMBA:16;                 /* System Memory Base Address high. This is the value of the system memory base address for the individual message buffers and sync frame table. This is the value of the system memory base address for the receive FIFO if the FIFO address mode bit FR_MCR[FAM] is set to 1. It is defines as a byte address. */
  } B;
} FR_SYMBADHR_tag;

typedef union FR_SYMBADLR_union_tag {  /* System Memory Base Address Low Register */
  vuint16_t R;
  struct {
    vuint16_t SMBA:12;
    vuint16_t  :4;
  } B;
} FR_SYMBADLR_tag;

typedef union FR_STBSCR_union_tag {    /* Strobe Signal Control Register */
  vuint16_t R;
  struct {
    vuint16_t WMD:1;
    vuint16_t  :3;
    vuint16_t SEL:4;
    vuint16_t  :3;
    vuint16_t ENB:1;
    vuint16_t  :2;
    vuint16_t STBPSEL:2;
  } B;
} FR_STBSCR_tag;

typedef union FR_MBDSR_union_tag {     /* Message Buffer Data Size Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t MBSEG2DS:7;
    vuint16_t  :1;
    vuint16_t MBSEG1DS:7;
  } B;
} FR_MBDSR_tag;

typedef union FR_MBSSUTR_union_tag {   /* Message Buffer Segment Size and Utilization Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t LAST_MB_SEG1:7;
    vuint16_t  :1;
    vuint16_t LAST_MB_UTIL:7;
  } B;
} FR_MBSSUTR_tag;

typedef union FR_PEDRAR_union_tag {    /* PE DRAM Access Register */
  vuint16_t R;
  struct {
    vuint16_t INST:4;
    vuint16_t ADDR:11;
    vuint16_t DAD:1;
  } B;
} FR_PEDRAR_tag;

typedef union FR_PEDRDR_union_tag {    /* PE DRAM Data Register */
  vuint16_t R;
  struct {
    vuint16_t DATA:16;
  } B;
} FR_PEDRDR_tag;

typedef union FR_POCR_union_tag {      /* Protocol Operation Control Register */
  vuint16_t R;
  struct {
    vuint16_t WME:1;
    vuint16_t  :3;
    vuint16_t EOC_AP:2;
    vuint16_t ERC_AP:2;
    vuint16_t BSY_WMC:1;
    vuint16_t  :3;
    vuint16_t POCCMD:4;
  } B;
} FR_POCR_tag;

typedef union FR_GIFER_union_tag {     /* Global Interrupt Flag and Enable Register */
  vuint16_t R;
  struct {
    vuint16_t MIF:1;
    vuint16_t PRIF:1;
    vuint16_t CHIF:1;
    vuint16_t WUPIF:1;
    vuint16_t FAFBIF:1;
    vuint16_t FAFAIF:1;
    vuint16_t RBIF:1;
    vuint16_t TBIF:1;
    vuint16_t MIE:1;
    vuint16_t PRIE:1;
    vuint16_t CHIE:1;
    vuint16_t WUPIE:1;
    vuint16_t FAFBIE:1;
    vuint16_t FAFAIE:1;
    vuint16_t RBIE:1;
    vuint16_t TBIE:1;
  } B;
} FR_GIFER_tag;

typedef union FR_PIFR0_union_tag {     /* Protocol Interrupt Flag Register 0 */
  vuint16_t R;
  struct {
    vuint16_t FATL_IF:1;
    vuint16_t INTL_IF:1;
    vuint16_t ILCF_IF:1;
    vuint16_t CSA_IF:1;
    vuint16_t MRC_IF:1;
    vuint16_t MOC_IF:1;
    vuint16_t CCL_IF:1;
    vuint16_t MXS_IF:1;
    vuint16_t MTX_IF:1;
    vuint16_t LTXB_IF:1;
    vuint16_t LTXA_IF:1;
    vuint16_t TBVB_IF:1;
    vuint16_t TBVA_IF:1;
    vuint16_t TI2_IF:1;
    vuint16_t TI1_IF:1;
    vuint16_t CYS_IF:1;
  } B;
} FR_PIFR0_tag;

typedef union FR_PIFR1_union_tag {     /* Protocol Interrupt Flag Register 1 */
  vuint16_t R;
  struct {
    vuint16_t EMC_IF:1;
    vuint16_t IPC_IF:1;
    vuint16_t PECF_IF:1;
    vuint16_t PSC_IF:1;
    vuint16_t SSI3_IF:1;
    vuint16_t SSI2_IF:1;
    vuint16_t SSI1_IF:1;
    vuint16_t SSI0_IF:1;
    vuint16_t  :2;
    vuint16_t EVT_IF:1;
    vuint16_t ODT_IF:1;
    vuint16_t  :4;
  } B;
} FR_PIFR1_tag;

typedef union FR_PIER0_union_tag {     /* Protocol Interrupt Enable Register 0 */
  vuint16_t R;
  struct {
    vuint16_t FATL_IE:1;
    vuint16_t INTL_IE:1;
    vuint16_t ILCF_IE:1;
    vuint16_t CSA_IE:1;
    vuint16_t MRC_IE:1;
    vuint16_t MOC_IE:1;
    vuint16_t CCL_IE:1;
    vuint16_t MXS_IE:1;
    vuint16_t MTX_IE:1;
    vuint16_t LTXB_IE:1;
    vuint16_t LTXA_IE:1;
    vuint16_t TBVB_IE:1;
    vuint16_t TBVA_IE:1;
    vuint16_t TI2_IE:1;
    vuint16_t TI1_IE:1;
    vuint16_t CYS_IE:1;
  } B;
} FR_PIER0_tag;

typedef union FR_PIER1_union_tag {     /* Protocol Interrupt Enable Register 1 */
  vuint16_t R;
  struct {
    vuint16_t EMC_IE:1;
    vuint16_t IPC_IE:1;
    vuint16_t PECF_IE:1;
    vuint16_t PSC_IE:1;
    vuint16_t SSI3_IE:1;
    vuint16_t SSI2_IE:1;
    vuint16_t SSI1_IE:1;
    vuint16_t SSI0_IE:1;
    vuint16_t  :2;
    vuint16_t EVT_IE:1;
    vuint16_t ODT_IE:1;
    vuint16_t  :4;
  } B;
} FR_PIER1_tag;

typedef union FR_CHIERFR_union_tag {   /* CHI Error Flag Register */
  vuint16_t R;
  struct {
    vuint16_t FRLB_EF:1;
    vuint16_t FRLA_EF:1;
    vuint16_t PCMI_EF:1;
    vuint16_t FOVB_EF:1;
    vuint16_t FOVA_EF:1;
    vuint16_t MBS_EF:1;
    vuint16_t MBU_EF:1;
    vuint16_t LCK_EF:1;
    vuint16_t  :1;
    vuint16_t SBCF_EF:1;
    vuint16_t FID_EF:1;
    vuint16_t DPL_EF:1;
    vuint16_t SPL_EF:1;
    vuint16_t NML_EF:1;
    vuint16_t NMF_EF:1;
    vuint16_t ILSA_EF:1;
  } B;
} FR_CHIERFR_tag;

typedef union FR_MBIVEC_union_tag {    /* Message Buffer Interrupt Vector Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t TBIVEC:7;
    vuint16_t  :1;
    vuint16_t RBIVEC:7;
  } B;
} FR_MBIVEC_tag;

typedef union FR_CASERCR_union_tag {   /* Channel A Status Error Counter Register */
  vuint16_t R;
  struct {
    vuint16_t CHAERSCNT:16;
  } B;
} FR_CASERCR_tag;

typedef union FR_CBSERCR_union_tag {   /* Channel B Status Error Counter Register */
  vuint16_t R;
  struct {
    vuint16_t CHBERSCNT:16;
  } B;
} FR_CBSERCR_tag;

typedef union FR_PSR0_union_tag {      /* Protocol Status Register 0 */
  vuint16_t R;
  struct {
    vuint16_t ERRMODE:2;
    vuint16_t SLOTMODE:2;
    vuint16_t  :1;
    vuint16_t PROTSTATE:3;
    vuint16_t STARTUPSTATE:4;
    vuint16_t  :1;
    vuint16_t WAKEUPSTATUS:3;
  } B;
} FR_PSR0_tag;

typedef union FR_PSR1_union_tag {      /* Protocol Status Register 1 */
  vuint16_t R;
  struct {
    vuint16_t CSAA:1;
    vuint16_t CSP:1;
    vuint16_t  :1;
    vuint16_t REMCSAT:5;
    vuint16_t CPN:1;
    vuint16_t HHR:1;
    vuint16_t FRZ:1;
    vuint16_t APTAC:5;
  } B;
} FR_PSR1_tag;

typedef union FR_PSR2_union_tag {      /* Protocol Status Register 2 */
  vuint16_t R;
  struct {
    vuint16_t NBVB:1;
    vuint16_t NSEB:1;
    vuint16_t STCB:1;
    vuint16_t SBVB:1;
    vuint16_t SSEB:1;
    vuint16_t MTB:1;
    vuint16_t NBVA:1;
    vuint16_t NSEA:1;
    vuint16_t STCA:1;
    vuint16_t SBVA:1;
    vuint16_t SSEA:1;
    vuint16_t MTA:1;
    vuint16_t CKCORFCNT:4;
  } B;
} FR_PSR2_tag;

typedef union FR_PSR3_union_tag {      /* Protocol Status Register 3 */
  vuint16_t R;
  struct {
    vuint16_t  :2;
    vuint16_t WUB:1;
    vuint16_t ABVB:1;
    vuint16_t AACB:1;
    vuint16_t ACEB:1;
    vuint16_t ASEB:1;
    vuint16_t AVFB:1;
    vuint16_t  :2;
    vuint16_t WUA:1;
    vuint16_t ABVA:1;
    vuint16_t AACA:1;
    vuint16_t ACEA:1;
    vuint16_t ASEA:1;
    vuint16_t AVFA:1;
  } B;
} FR_PSR3_tag;

typedef union FR_MTCTR_union_tag {     /* Macrotick Counter Register */
  vuint16_t R;
  struct {
    vuint16_t  :2;
    vuint16_t MTCT:14;
  } B;
} FR_MTCTR_tag;

typedef union FR_CYCTR_union_tag {     /* Cycle Counter Register */
  vuint16_t R;
  struct {
    vuint16_t  :10;
    vuint16_t CYCCNT:6;
  } B;
} FR_CYCTR_tag;

typedef union FR_SLTCTAR_union_tag {   /* Slot Counter Channel A Register */
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t SLOTCNTA:11;
  } B;
} FR_SLTCTAR_tag;

typedef union FR_SLTCTBR_union_tag {   /* Slot Counter Channel B Register */
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t SLOTCNTB:11;
  } B;
} FR_SLTCTBR_tag;

typedef union FR_RTCORVR_union_tag {   /* Rate Correction Value Register */
  vuint16_t R;
  struct {
    vuint16_t RATECORR:16;
  } B;
} FR_RTCORVR_tag;

typedef union FR_OFCORVR_union_tag {   /* Offset Correction Value Register */
  vuint16_t R;
  struct {
    vuint16_t OFFSETCORR:16;
  } B;
} FR_OFCORVR_tag;

typedef union FR_CIFR_union_tag {      /* Combined Interrupt Flag Register */
  vuint16_t R;
  struct {
    vuint16_t  :8;
    vuint16_t MIF:1;
    vuint16_t PRIF:1;
    vuint16_t CHIF:1;
    vuint16_t WUPIF:1;
    vuint16_t FAFBIF:1;
    vuint16_t FAFAIF:1;
    vuint16_t RBIF:1;
    vuint16_t TBIF:1;
  } B;
} FR_CIFR_tag;

typedef union FR_SYMATOR_union_tag {   /* System Memory Access Time-Out Register */
  vuint16_t R;
  struct {
    vuint16_t  :8;
    vuint16_t TIMEOUT:8;
  } B;
} FR_SYMATOR_tag;

typedef union FR_SFCNTR_union_tag {    /* Sync Frame Counter Register */
  vuint16_t R;
  struct {
    vuint16_t SFEVB:4;
    vuint16_t SFEVA:4;
    vuint16_t SFODB:4;
    vuint16_t SFODA:4;
  } B;
} FR_SFCNTR_tag;

typedef union FR_SFTOR_union_tag {     /* Sync Frame Table Offset Register */
  vuint16_t R;
  struct {
    vuint16_t SFT_OFFSET:15;
    vuint16_t  :1;
  } B;
} FR_SFTOR_tag;

typedef union FR_SFTCCSR_union_tag {   /* Sync Frame Table Configuration, Control, Status Register */
  vuint16_t R;
  struct {
    vuint16_t ELKT:1;
    vuint16_t OLKT:1;
    vuint16_t CYCNUM:6;
    vuint16_t ELKS:1;
    vuint16_t OLKS:1;
    vuint16_t EVAL:1;
    vuint16_t OVAL:1;
    vuint16_t  :1;
    vuint16_t OPT:1;
    vuint16_t SDVEN:1;
    vuint16_t SIDEN:1;
  } B;
} FR_SFTCCSR_tag;

typedef union FR_SFIDRFR_union_tag {   /* Sync Frame ID Rejection Filter Register */
  vuint16_t R;
  struct {
    vuint16_t  :6;
    vuint16_t SYNFRID:10;
  } B;
} FR_SFIDRFR_tag;

typedef union FR_SFIDAFVR_union_tag {  /* Sync Frame ID Acceptance Filter Value Register */
  vuint16_t R;
  struct {
    vuint16_t  :6;
    vuint16_t FVAL:10;
  } B;
} FR_SFIDAFVR_tag;

typedef union FR_SFIDAFMR_union_tag {  /* Sync Frame ID Acceptance Filter Mask Register */
  vuint16_t R;
  struct {
    vuint16_t  :6;
    vuint16_t FMSK:10;
  } B;
} FR_SFIDAFMR_tag;

typedef union FR_NMVR_union_tag {      /* Network Management Vector Register */
  vuint16_t R;
  struct {
    vuint16_t NMVP:16;
  } B;
} FR_NMVR_tag;

typedef union FR_NMVLR_union_tag {     /* Network Management Vector Length Register */
  vuint16_t R;
  struct {
    vuint16_t  :12;
    vuint16_t NMVL:4;
  } B;
} FR_NMVLR_tag;

typedef union FR_TICCR_union_tag {     /* Timer Configuration and Control Register */
  vuint16_t R;
  struct {
    vuint16_t  :2;
    vuint16_t T2_CFG:1;
    vuint16_t T2_REP:1;
    vuint16_t  :1;
    vuint16_t T2SP:1;
    vuint16_t T2TR:1;
    vuint16_t T2ST:1;
    vuint16_t  :3;
    vuint16_t T1_REP:1;
    vuint16_t  :1;
    vuint16_t T1SP:1;
    vuint16_t T1TR:1;
    vuint16_t T1ST:1;
  } B;
} FR_TICCR_tag;

typedef union FR_TI1CYSR_union_tag {   /* Timer 1 Cycle Set Register */
  vuint16_t R;
  struct {
    vuint16_t  :2;
    vuint16_t T1_CYC_VAL:6;
    vuint16_t  :2;
    vuint16_t T1_CYC_MSK:6;
  } B;
} FR_TI1CYSR_tag;

typedef union FR_TI1MTOR_union_tag {   /* Timer 1 Macrotick Offset Register */
  vuint16_t R;
  struct {
    vuint16_t  :2;
    vuint16_t T1_MTOFFSET:14;
  } B;
} FR_TI1MTOR_tag;

typedef union FR_TI2CR0_ABS_union_tag { /* Timer 2 Configuration Register 0 (Absolute Timer Configuration) */
  vuint16_t R;
  struct {
    vuint16_t  :2;
    vuint16_t T2CYCVAL:6;              /* Timer T2 Cycle Filter Mask */
    vuint16_t  :2;
    vuint16_t T2CYCMSK:6;              /* Timer T2 Cycle Filter Mask */
  } B;
} FR_TI2CR0_ABS_tag;

typedef union FR_TI2CR0_REL_union_tag { /* Timer 2 Configuration Register 0 (Relative Timer Configuration) */
  vuint16_t R;
  struct {
    vuint16_t T2MTCNT:16;              /* Timer T2 Macrotick High Word */
  } B;
} FR_TI2CR0_REL_tag;

typedef union FR_TI2CR0_union_tag {
  FR_TI2CR0_ABS_tag ABS;               /* Timer 2 Configuration Register 0 (Absolute Timer Configuration) */
  FR_TI2CR0_REL_tag REL;               /* Timer 2 Configuration Register 0 (Relative Timer Configuration) */
} FR_TI2CR0_tag;

typedef union FR_TI2CR1_ABS_union_tag { /* Timer 2 Configuration Register 1 (Absolute Timer Configuration) */
  vuint16_t R;
  struct {
    vuint16_t  :2;
    vuint16_t T2MOFF:14;               /* Timer T2 Macrotick Offset */
  } B;
} FR_TI2CR1_ABS_tag;

typedef union FR_TI2CR1_REL_union_tag { /* Timer 2 Configuration Register 1 (Relative Timer Configuration) */
  vuint16_t R;
  struct {
    vuint16_t T2MTCNT:16;
  } B;
} FR_TI2CR1_REL_tag;

typedef union FR_TI2CR1_union_tag {
  FR_TI2CR1_ABS_tag ABS;               /* Timer 2 Configuration Register 1 (Absolute Timer Configuration) */
  FR_TI2CR1_REL_tag REL;               /* Timer 2 Configuration Register 1 (Relative Timer Configuration) */
} FR_TI2CR1_tag;

typedef union FR_SSSR_union_tag {      /* Slot Status Selection Register */
  vuint16_t R;
  struct {
    vuint16_t WMD:1;
    vuint16_t  :1;
    vuint16_t SEL:2;
    vuint16_t  :1;
    vuint16_t SLOTNUMBER:11;
  } B;
} FR_SSSR_tag;

typedef union FR_SSCCR_union_tag {     /* Slot Status Counter Condition Register */
  vuint16_t R;
  struct {
    vuint16_t WMD:1;
    vuint16_t  :1;
    vuint16_t SEL:2;
    vuint16_t  :1;
    vuint16_t CNTCFG:2;
    vuint16_t MCY:1;
    vuint16_t VFR:1;
    vuint16_t SYF:1;
    vuint16_t NUF:1;
    vuint16_t SUF:1;
    vuint16_t STATUSMASK:4;
  } B;
} FR_SSCCR_tag;

typedef union FR_SSR_union_tag {       /* Slot Status Register */
  vuint16_t R;
  struct {
    vuint16_t VFB:1;
    vuint16_t SYB:1;
    vuint16_t NFB:1;
    vuint16_t SUB:1;
    vuint16_t SEB:1;
    vuint16_t CEB:1;
    vuint16_t BVB:1;
    vuint16_t TCB:1;
    vuint16_t VFA:1;
    vuint16_t SYA:1;
    vuint16_t NFA:1;
    vuint16_t SUA:1;
    vuint16_t SEA:1;
    vuint16_t CEA:1;
    vuint16_t BVA:1;
    vuint16_t TCA:1;
  } B;
} FR_SSR_tag;

typedef union FR_SSCR_union_tag {      /* Slot Status Counter Register */
  vuint16_t R;
  struct {
    vuint16_t SLOTSTATUSCNT:16;
  } B;
} FR_SSCR_tag;

typedef union FR_MTSACFR_union_tag {   /* MTS A Configuration Register */
  vuint16_t R;
  struct {
    vuint16_t MTE:1;
    vuint16_t  :1;
    vuint16_t CYCCNTMSK:6;
    vuint16_t  :2;
    vuint16_t CYCCNTVAL:6;
  } B;
} FR_MTSACFR_tag;

typedef union FR_MTSBCFR_union_tag {   /* MTS B Configuration Register */
  vuint16_t R;
  struct {
    vuint16_t MTE:1;
    vuint16_t  :1;
    vuint16_t CYCCNTMSK:6;
    vuint16_t  :2;
    vuint16_t CYCCNTVAL:6;
  } B;
} FR_MTSBCFR_tag;

typedef union FR_RSBIR_union_tag {     /* Receive Shadow Buffer Index Register */
  vuint16_t R;
  struct {
    vuint16_t WMD:1;
    vuint16_t  :1;
    vuint16_t SEL:2;
    vuint16_t  :4;
    vuint16_t RSBIDX:8;                /* RSBIDXA1/RSBIDXA2/RSBIDXB1/RSBIDXB2- Receive Shadow Buffer Index */
  } B;
} FR_RSBIR_tag;

typedef union FR_RFWMSR_union_tag {    /* Receive FIFO Watermark and Selection Register */
  vuint16_t R;
  struct {
    vuint16_t WM:8;                    /* WMA/WMB - Watermark */
    vuint16_t  :7;
    vuint16_t SEL:1;
  } B;
} FR_RFWMSR_tag;

typedef union FR_RFSIR_union_tag {     /* Receive FIFO Start Index Register */
  vuint16_t R;
  struct {
    vuint16_t  :6;
    vuint16_t SIDX:10;                 /* SIDXA/SIDXB - Start Index */
  } B;
} FR_RFSIR_tag;

typedef union FR_RFDSR_union_tag {     /* Receive FIFO Depth and Size Register */
  vuint16_t R;
  struct {
    vuint16_t FIFO_DEPTH:8;            /* FIFO_DEPTHA/FIFO_DEPTHB - FIFO Depth */
    vuint16_t  :1;
    vuint16_t ENTRY_SIZE:7;            /* ENTRY_SIZEA/ENTRY_SIZEB - Entry Size */
  } B;
} FR_RFDSR_tag;

typedef union FR_RFARIR_union_tag {    /* Receive FIFO A Read Index Register */
  vuint16_t R;
  struct {
    vuint16_t  :6;
    vuint16_t RDIDX:10;
  } B;
} FR_RFARIR_tag;

typedef union FR_RFBRIR_union_tag {    /* Receive FIFO B Read Index Register */
  vuint16_t R;
  struct {
    vuint16_t  :6;
    vuint16_t RDIDX:10;
  } B;
} FR_RFBRIR_tag;

typedef union FR_RFMIDAFVR_union_tag { /* Receive FIFO Message ID Acceptance Filter Value Register */
  vuint16_t R;
  struct {
    vuint16_t MIDAFVAL:16;             /* MIDAFVALA/MIDAFVALB - Message ID Acceptance Filter Value */
  } B;
} FR_RFMIDAFVR_tag;

typedef union FR_RFMIDAFMR_union_tag { /* Receive FIFO Message ID Acceptance Filter Mask Register */
  vuint16_t R;
  struct {
    vuint16_t MIDAFMSK:16;             /* MIDAFMSKA/MIDAFMSKB - Message ID Acceptance Filter Mask */
  } B;
} FR_RFMIDAFMR_tag;

typedef union FR_RFFIDRFVR_union_tag { /* Receive FIFO Frame ID Rejection Filter Value Register */
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t FIDRFVAL:11;             /* FIDRFVALA/FIDRFVALB - Frame ID Rejection Filter Value */
  } B;
} FR_RFFIDRFVR_tag;

typedef union FR_RFFIDRFMR_union_tag { /* Receive FIFO Frame ID Rejection Filter Mask Register */
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t FIDRFMSK:11;
  } B;
} FR_RFFIDRFMR_tag;

typedef union FR_RFRFCFR_union_tag {   /* Receive FIFO Range Filter Configuration Register */
  vuint16_t R;
  struct {
    vuint16_t WMD:1;
    vuint16_t IBD:1;
    vuint16_t SEL:2;
    vuint16_t  :1;
    vuint16_t SID:11;                  /* Slot ID */
  } B;
} FR_RFRFCFR_tag;

typedef union FR_RFRFCTR_union_tag {   /* Receive FIFO Range Filter Control Register */
  vuint16_t R;
  struct {
    vuint16_t  :4;
    vuint16_t F3MD:1;
    vuint16_t F2MD:1;
    vuint16_t F1MD:1;
    vuint16_t F0MD:1;
    vuint16_t  :4;
    vuint16_t F3EN:1;
    vuint16_t F2EN:1;
    vuint16_t F1EN:1;
    vuint16_t F0EN:1;
  } B;
} FR_RFRFCTR_tag;

typedef union FR_LDTXSLAR_union_tag {  /* Last Dynamic Transmit Slot Channel A Register */
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t LDYNTXSLOTA:11;
  } B;
} FR_LDTXSLAR_tag;

typedef union FR_LDTXSLBR_union_tag {  /* Last Dynamic Transmit Slot Channel B Register */
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t LDYNTXSLOTB:11;
  } B;
} FR_LDTXSLBR_tag;

typedef union FR_PCR0_union_tag {      /* Protocol Configuration Register 0 */
  vuint16_t R;
  struct {
    vuint16_t action_point_offset:6;
    vuint16_t static_slot_length:10;
  } B;
} FR_PCR0_tag;

typedef union FR_PCR1_union_tag {      /* Protocol Configuration Register 1 */
  vuint16_t R;
  struct {
    vuint16_t  :2;
    vuint16_t macro_after_first_static_slot:14;
  } B;
} FR_PCR1_tag;

typedef union FR_PCR2_union_tag {      /* Protocol Configuration Register 2 */
  vuint16_t R;
  struct {
    vuint16_t minislot_after_action_point:6;
    vuint16_t number_of_static_slots:10; /* gNumberOfStaticSlots */
  } B;
} FR_PCR2_tag;

typedef union FR_PCR3_union_tag {      /* Protocol Configuration Register 3 */
  vuint16_t R;
  struct {
    vuint16_t wakeup_symbol_rx_low:6;
    vuint16_t minislot_action_point_offset:5;
    vuint16_t coldstart_attempts:5;
  } B;
} FR_PCR3_tag;

typedef union FR_PCR4_union_tag {      /* Protocol Configuration Register 4 */
  vuint16_t R;
  struct {
    vuint16_t cas_rx_low_max:7;
    vuint16_t wakeup_symbol_rx_window:9;
  } B;
} FR_PCR4_tag;

typedef union FR_PCR5_union_tag {      /* Protocol Configuration Register 5 */
  vuint16_t R;
  struct {
    vuint16_t tss_transmitter:4;
    vuint16_t wakeup_symbol_tx_low:6;
    vuint16_t wakeup_symbol_rx_idle:6;
  } B;
} FR_PCR5_tag;

typedef union FR_PCR6_union_tag {      /* Protocol Configuration Register 6 */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t symbol_window_after_action_point:8;
    vuint16_t macro_initial_offset_a:7;
  } B;
} FR_PCR6_tag;

typedef union FR_PCR7_union_tag {      /* Protocol Configuration Register 7 */
  vuint16_t R;
  struct {
    vuint16_t decoding_correction_b:9;
    vuint16_t micro_per_macro_nom_half:7;
  } B;
} FR_PCR7_tag;

typedef union FR_PCR8_union_tag {      /* Protocol Configuration Register 8 */
  vuint16_t R;
  struct {
    vuint16_t max_without_clock_correction_fatal:4;
    vuint16_t max_without_clock_correction_passive:4;
    vuint16_t wakeup_symbol_tx_idle:8;
  } B;
} FR_PCR8_tag;

typedef union FR_PCR9_union_tag {      /* Protocol Configuration Register 9 */
  vuint16_t R;
  struct {
    vuint16_t minislot_exists:1;
    vuint16_t symbol_window_exists:1;
    vuint16_t offset_correction_out:14;
  } B;
} FR_PCR9_tag;

typedef union FR_PCR10_union_tag {     /* Protocol Configuration Register 10 */
  vuint16_t R;
  struct {
    vuint16_t single_slot_enabled:1;
    vuint16_t wakeup_channel:1;
    vuint16_t macro_per_cycle:14;
  } B;
} FR_PCR10_tag;

typedef union FR_PCR11_union_tag {     /* Protocol Configuration Register 11 */
  vuint16_t R;
  struct {
    vuint16_t key_slot_used_for_startup:1;
    vuint16_t key_slot_used_for_sync:1;
    vuint16_t offset_correction_start:14;
  } B;
} FR_PCR11_tag;

typedef union FR_PCR12_union_tag {     /* Protocol Configuration Register 12 */
  vuint16_t R;
  struct {
    vuint16_t allow_passive_to_active:5;
    vuint16_t key_slot_header_crc:11;
  } B;
} FR_PCR12_tag;

typedef union FR_PCR13_union_tag {     /* Protocol Configuration Register 13 */
  vuint16_t R;
  struct {
    vuint16_t first_minislot_action_point_offset:6;
    vuint16_t static_slot_after_action_point:10;
  } B;
} FR_PCR13_tag;

typedef union FR_PCR14_union_tag {     /* Protocol Configuration Register 14 */
  vuint16_t R;
  struct {
    vuint16_t rate_correction_out:11;
    vuint16_t listen_timeout:5;
  } B;
} FR_PCR14_tag;

typedef union FR_PCR15_union_tag {     /* Protocol Configuration Register 15 */
  vuint16_t R;
  struct {
    vuint16_t listen_timeout:16;
  } B;
} FR_PCR15_tag;

typedef union FR_PCR16_union_tag {     /* Protocol Configuration Register 16 */
  vuint16_t R;
  struct {
    vuint16_t macro_initial_offset_b:7;
    vuint16_t noise_listen_timeout:9;
  } B;
} FR_PCR16_tag;

typedef union FR_PCR17_union_tag {     /* Protocol Configuration Register 17 */
  vuint16_t R;
  struct {
    vuint16_t noise_listen_timeout:16;
  } B;
} FR_PCR17_tag;

typedef union FR_PCR18_union_tag {     /* Protocol Configuration Register 18 */
  vuint16_t R;
  struct {
    vuint16_t wakeup_pattern:6;
    vuint16_t key_slot_id:10;
  } B;
} FR_PCR18_tag;

typedef union FR_PCR19_union_tag {     /* Protocol Configuration Register 19 */
  vuint16_t R;
  struct {
    vuint16_t decoding_correction_a:9;
    vuint16_t payload_length_static:7;
  } B;
} FR_PCR19_tag;

typedef union FR_PCR20_union_tag {     /* Protocol Configuration Register 20 */
  vuint16_t R;
  struct {
    vuint16_t micro_initial_offset_b:8;
    vuint16_t micro_initial_offset_a:8;
  } B;
} FR_PCR20_tag;

typedef union FR_PCR21_union_tag {     /* Protocol Configuration Register 21 */
  vuint16_t R;
  struct {
    vuint16_t extern_rate_correction:3;
    vuint16_t latest_tx:13;
  } B;
} FR_PCR21_tag;

typedef union FR_PCR22_union_tag {     /* Protocol Configuration Register 22 */
  vuint16_t R;
  struct {
    vuint16_t  :1;                     /* Reserved bit, will not be changed. Application must not write any value different from the reset value. */
    vuint16_t comp_accepted_startup_range_a:11;
    vuint16_t micro_per_cycle:4;
  } B;
} FR_PCR22_tag;

typedef union FR_PCR23_union_tag {     /* Protocol Configuration Register 23 */
  vuint16_t R;
  struct {
    vuint16_t micro_per_cycle:16;
  } B;
} FR_PCR23_tag;

typedef union FR_PCR24_union_tag {     /* Protocol Configuration Register 24 */
  vuint16_t R;
  struct {
    vuint16_t cluster_drift_damping:5;
    vuint16_t max_payload_length_dynamic:7;
    vuint16_t micro_per_cycle_min:4;
  } B;
} FR_PCR24_tag;

typedef union FR_PCR25_union_tag {     /* Protocol Configuration Register 25 */
  vuint16_t R;
  struct {
    vuint16_t micro_per_cycle_min:16;
  } B;
} FR_PCR25_tag;

typedef union FR_PCR26_union_tag {     /* Protocol Configuration Register 26 */
  vuint16_t R;
  struct {
    vuint16_t allow_halt_due_to_clock:1;
    vuint16_t comp_accepted_startup_range_b:11;
    vuint16_t micro_per_cycle_max:4;
  } B;
} FR_PCR26_tag;

typedef union FR_PCR27_union_tag {     /* Protocol Configuration Register 27 */
  vuint16_t R;
  struct {
    vuint16_t micro_per_cycle_max:16;
  } B;
} FR_PCR27_tag;

typedef union FR_PCR28_union_tag {     /* Protocol Configuration Register 28 */
  vuint16_t R;
  struct {
    vuint16_t dynamic_slot_idle_phase:2;
    vuint16_t macro_after_offset_correction:14;
  } B;
} FR_PCR28_tag;

typedef union FR_PCR29_union_tag {     /* Protocol Configuration Register 29 */
  vuint16_t R;
  struct {
    vuint16_t extern_offset_correction:3;
    vuint16_t minislots_max:13;
  } B;
} FR_PCR29_tag;

typedef union FR_PCR30_union_tag {     /* Protocol Configuration Register 30 */
  vuint16_t R;
  struct {
    vuint16_t  :12;
    vuint16_t sync_node_max:4;
  } B;
} FR_PCR30_tag;

typedef union FR_STPWR_union_tag {     /* StopWatch Count Register */
  vuint32_t R;
  struct {
    vuint32_t STPW:32;                 /* StopWatch Count Register */
  } B;
} FR_STPWR_tag;

typedef union FR_PEOER_union_tag {     /* Protocol Event Output Enable and StopWatch Control Register */
  vuint16_t R;
  struct {
    vuint16_t  :7;
    vuint16_t STPW_EN:1;               /* Stopwatch count Enable */
    vuint16_t  :5;
    vuint16_t TIM2_EE:1;
    vuint16_t TIM1_EE:1;
    vuint16_t CYC_EE:1;
  } B;
} FR_PEOER_tag;

typedef union FR_RFSDOR_union_tag {    /* Receive FIFO Start Data Offset Register */
  vuint16_t R;
  struct {
    vuint16_t SDO:16;                  /* SDOA/SDOB - Start Data Field Offset */
  } B;
} FR_RFSDOR_tag;

typedef union FR_RFSYMBADHR_union_tag { /* Receive FIFO System Memory Base Address High Register */
  vuint16_t R;
  struct {
    vuint16_t SMBA:16;
  } B;
} FR_RFSYMBADHR_tag;

typedef union FR_RFSYMBADLR_union_tag { /* Receive FIFO System Memory Base Address Low Register */
  vuint16_t R;
  struct {
    vuint16_t SMBA:12;
    vuint16_t  :4;
  } B;
} FR_RFSYMBADLR_tag;

typedef union FR_RFPTR_union_tag {     /* Receive FIFO Periodic Timer Register */
  vuint16_t R;
  struct {
    vuint16_t  :2;
    vuint16_t PTD:14;
  } B;
} FR_RFPTR_tag;

typedef union FR_RFFLPCR_union_tag {   /* Receive FIFO Fill Level and POP Count Register */
  vuint16_t R;
  struct {
    vuint16_t FLB_or_PCB:8;
    vuint16_t FLA_or_PCA:8;
  } B;
} FR_RFFLPCR_tag;

typedef union FR_EEIFER_union_tag {    /* ECC Error Interrupt Flag and Enable Register */
  vuint16_t R;
  struct {
    vuint16_t LRNE_OF:1;
    vuint16_t LRCE_OF:1;
    vuint16_t DRNE_OF:1;
    vuint16_t DRCE_OF:1;
    vuint16_t LRNE_IF:1;
    vuint16_t LRCE_IF:1;
    vuint16_t DRNE_IF:1;
    vuint16_t DRCE_IF:1;
    vuint16_t  :4;
    vuint16_t LRNE_IE:1;
    vuint16_t LRCE_IE:1;
    vuint16_t DRNE_IE:1;
    vuint16_t DRCE_IE:1;
  } B;
} FR_EEIFER_tag;

typedef union FR_EERICR_union_tag {    /* ECC Error Report and Injection Control Register */
  vuint16_t R;
  struct {
    vuint16_t BSY:1;
    vuint16_t  :5;
    vuint16_t ERS:2;
    vuint16_t  :3;
    vuint16_t ERM:1;
    vuint16_t  :2;
    vuint16_t EIM:1;
    vuint16_t EIE:1;
  } B;
} FR_EERICR_tag;

typedef union FR_EERAR_union_tag {     /* ECC Error Report Address Register */
  vuint16_t R;
  struct {
    vuint16_t MID:1;
    vuint16_t BANK:3;
    vuint16_t ADDR:12;
  } B;
} FR_EERAR_tag;

typedef union FR_EERDR_union_tag {     /* ECC Error Report Data Register */
  vuint16_t R;
  struct {
    vuint16_t DATA:16;
  } B;
} FR_EERDR_tag;

typedef union FR_EERCR_union_tag {     /* ECC Error Report Code Register */
  vuint16_t R;
  struct {
    vuint16_t  :11;
    vuint16_t CODE:5;
  } B;
} FR_EERCR_tag;

typedef union FR_EEIAR_union_tag {     /* ECC Error Injection Address Register */
  vuint16_t R;
  struct {
    vuint16_t MID:1;
    vuint16_t BANK:3;
    vuint16_t ADDR:12;
  } B;
} FR_EEIAR_tag;

typedef union FR_EEIDR_union_tag {     /* ECC Error Injection Data Register */
  vuint16_t R;
  struct {
    vuint16_t DATA:16;
  } B;
} FR_EEIDR_tag;

typedef union FR_EEICR_union_tag {     /* ECC Error Injection Code Register */
  vuint16_t R;
  struct {
    vuint16_t  :11;
    vuint16_t CODE:5;
  } B;
} FR_EEICR_tag;

typedef union FR_MB_CCSR_union_tag {   /* Message Buffer Configuration, Control, Status Register */
  vuint16_t R;
  struct {
    vuint16_t  :3;
    vuint16_t MTD:1;
    vuint16_t CMT:1;
    vuint16_t EDT:1;
    vuint16_t LCKT:1;
    vuint16_t MBIE:1;
    vuint16_t  :3;
    vuint16_t DUP:1;
    vuint16_t DVAL:1;
    vuint16_t EDS:1;
    vuint16_t LCKS:1;
    vuint16_t MBIF:1;
  } B;
} FR_MB_CCSR_tag;

typedef union FR_MB_CCFR_union_tag {   /* Message Buffer Cycle Counter Filter Register */
  vuint16_t R;
  struct {
    vuint16_t MTM:1;
    vuint16_t CHA:1;
    vuint16_t CHB:1;
    vuint16_t CCFE:1;
    vuint16_t CCFMSK:6;
    vuint16_t CCFVAL:6;
  } B;
} FR_MB_CCFR_tag;

typedef union FR_MB_FIDR_union_tag {   /* Message Buffer Frame ID Register */
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t FID:11;
  } B;
} FR_MB_FIDR_tag;

typedef union FR_MB_IDXR_union_tag {   /* Message Buffer Index Register */
  vuint16_t R;
  struct {
    vuint16_t  :8;
    vuint16_t MBIDX:8;
  } B;
} FR_MB_IDXR_tag;

typedef struct FR_MB_struct_tag {
  FR_MB_CCSR_tag CCSR;                 /* Message Buffer Configuration, Control, Status Register */
  FR_MB_CCFR_tag CCFR;                 /* Message Buffer Cycle Counter Filter Register */
  FR_MB_FIDR_tag FIDR;                 /* Message Buffer Frame ID Register */
  FR_MB_IDXR_tag IDXR;                 /* Message Buffer Index Register */
} FR_MB_tag;

typedef union FR_MBDOR_union_tag {     /* Message Buffer Data Field Offset Register */
  vuint16_t R;
  struct {
    vuint16_t MBDO:16;
  } B;
} FR_MBDOR_tag;

typedef union FR_LEETR_union_tag {     /* LRAM ECC Error Test Register */
  vuint16_t R;
  struct {
    vuint16_t LEETD:16;
  } B;
} FR_LEETR_tag;

struct FR_tag {
  FR_MVR_tag MVR;                      /* Module Version Register */
  FR_MCR_tag MCR;                      /* Module Configuration Register */
  FR_SYMBADHR_tag SYMBADHR;            /* System Memory Base Address High Register */
  FR_SYMBADLR_tag SYMBADLR;            /* System Memory Base Address Low Register */
  FR_STBSCR_tag STBSCR;                /* Strobe Signal Control Register */
  uint8_t FR_reserved0[2];
  FR_MBDSR_tag MBDSR;                  /* Message Buffer Data Size Register */
  FR_MBSSUTR_tag MBSSUTR;              /* Message Buffer Segment Size and Utilization Register */
  FR_PEDRAR_tag PEDRAR;                /* PE DRAM Access Register */
  FR_PEDRDR_tag PEDRDR;                /* PE DRAM Data Register */
  FR_POCR_tag POCR;                    /* Protocol Operation Control Register */
  FR_GIFER_tag GIFER;                  /* Global Interrupt Flag and Enable Register */
  FR_PIFR0_tag PIFR0;                  /* Protocol Interrupt Flag Register 0 */
  FR_PIFR1_tag PIFR1;                  /* Protocol Interrupt Flag Register 1 */
  FR_PIER0_tag PIER0;                  /* Protocol Interrupt Enable Register 0 */
  FR_PIER1_tag PIER1;                  /* Protocol Interrupt Enable Register 1 */
  FR_CHIERFR_tag CHIERFR;              /* CHI Error Flag Register */
  FR_MBIVEC_tag MBIVEC;                /* Message Buffer Interrupt Vector Register */
  FR_CASERCR_tag CASERCR;              /* Channel A Status Error Counter Register */
  FR_CBSERCR_tag CBSERCR;              /* Channel B Status Error Counter Register */
  FR_PSR0_tag PSR0;                    /* Protocol Status Register 0 */
  FR_PSR1_tag PSR1;                    /* Protocol Status Register 1 */
  FR_PSR2_tag PSR2;                    /* Protocol Status Register 2 */
  FR_PSR3_tag PSR3;                    /* Protocol Status Register 3 */
  FR_MTCTR_tag MTCTR;                  /* Macrotick Counter Register */
  FR_CYCTR_tag CYCTR;                  /* Cycle Counter Register */
  FR_SLTCTAR_tag SLTCTAR;              /* Slot Counter Channel A Register */
  FR_SLTCTBR_tag SLTCTBR;              /* Slot Counter Channel B Register */
  FR_RTCORVR_tag RTCORVR;              /* Rate Correction Value Register */
  FR_OFCORVR_tag OFCORVR;              /* Offset Correction Value Register */
  FR_CIFR_tag CIFR;                    /* Combined Interrupt Flag Register */
  FR_SYMATOR_tag SYMATOR;              /* System Memory Access Time-Out Register */
  FR_SFCNTR_tag SFCNTR;                /* Sync Frame Counter Register */
  FR_SFTOR_tag SFTOR;                  /* Sync Frame Table Offset Register */
  FR_SFTCCSR_tag SFTCCSR;              /* Sync Frame Table Configuration, Control, Status Register */
  FR_SFIDRFR_tag SFIDRFR;              /* Sync Frame ID Rejection Filter Register */
  FR_SFIDAFVR_tag SFIDAFVR;            /* Sync Frame ID Acceptance Filter Value Register */
  FR_SFIDAFMR_tag SFIDAFMR;            /* Sync Frame ID Acceptance Filter Mask Register */
  FR_NMVR_tag NMVR[6];                 /* Network Management Vector Register */
  FR_NMVLR_tag NMVLR;                  /* Network Management Vector Length Register */
  FR_TICCR_tag TICCR;                  /* Timer Configuration and Control Register */
  FR_TI1CYSR_tag TI1CYSR;              /* Timer 1 Cycle Set Register */
  FR_TI1MTOR_tag TI1MTOR;              /* Timer 1 Macrotick Offset Register */
  FR_TI2CR0_tag TI2CR0;
  FR_TI2CR1_tag TI2CR1;
  FR_SSSR_tag SSSR;                    /* Slot Status Selection Register */
  FR_SSCCR_tag SSCCR;                  /* Slot Status Counter Condition Register */
  FR_SSR_tag SSR[8];                   /* Slot Status Register */
  FR_SSCR_tag SSCR[4];                 /* Slot Status Counter Register */
  FR_MTSACFR_tag MTSACFR;              /* MTS A Configuration Register */
  FR_MTSBCFR_tag MTSBCFR;              /* MTS B Configuration Register */
  FR_RSBIR_tag RSBIR;                  /* Receive Shadow Buffer Index Register */
  FR_RFWMSR_tag RFWMSR;                /* Receive FIFO Watermark and Selection Register */
  FR_RFSIR_tag RFSIR;                  /* Receive FIFO Start Index Register */
  FR_RFDSR_tag RFDSR;                  /* Receive FIFO Depth and Size Register */
  FR_RFARIR_tag RFARIR;                /* Receive FIFO A Read Index Register */
  FR_RFBRIR_tag RFBRIR;                /* Receive FIFO B Read Index Register */
  FR_RFMIDAFVR_tag RFMIDAFVR;          /* Receive FIFO Message ID Acceptance Filter Value Register */
  FR_RFMIDAFMR_tag RFMIDAFMR;          /* Receive FIFO Message ID Acceptance Filter Mask Register */
  FR_RFFIDRFVR_tag RFFIDRFVR;          /* Receive FIFO Frame ID Rejection Filter Value Register */
  FR_RFFIDRFMR_tag RFFIDRFMR;          /* Receive FIFO Frame ID Rejection Filter Mask Register */
  FR_RFRFCFR_tag RFRFCFR;              /* Receive FIFO Range Filter Configuration Register */
  FR_RFRFCTR_tag RFRFCTR;              /* Receive FIFO Range Filter Control Register */
  FR_LDTXSLAR_tag LDTXSLAR;            /* Last Dynamic Transmit Slot Channel A Register */
  FR_LDTXSLBR_tag LDTXSLBR;            /* Last Dynamic Transmit Slot Channel B Register */
  FR_PCR0_tag PCR0;                    /* Protocol Configuration Register 0 */
  FR_PCR1_tag PCR1;                    /* Protocol Configuration Register 1 */
  FR_PCR2_tag PCR2;                    /* Protocol Configuration Register 2 */
  FR_PCR3_tag PCR3;                    /* Protocol Configuration Register 3 */
  FR_PCR4_tag PCR4;                    /* Protocol Configuration Register 4 */
  FR_PCR5_tag PCR5;                    /* Protocol Configuration Register 5 */
  FR_PCR6_tag PCR6;                    /* Protocol Configuration Register 6 */
  FR_PCR7_tag PCR7;                    /* Protocol Configuration Register 7 */
  FR_PCR8_tag PCR8;                    /* Protocol Configuration Register 8 */
  FR_PCR9_tag PCR9;                    /* Protocol Configuration Register 9 */
  FR_PCR10_tag PCR10;                  /* Protocol Configuration Register 10 */
  FR_PCR11_tag PCR11;                  /* Protocol Configuration Register 11 */
  FR_PCR12_tag PCR12;                  /* Protocol Configuration Register 12 */
  FR_PCR13_tag PCR13;                  /* Protocol Configuration Register 13 */
  FR_PCR14_tag PCR14;                  /* Protocol Configuration Register 14 */
  FR_PCR15_tag PCR15;                  /* Protocol Configuration Register 15 */
  FR_PCR16_tag PCR16;                  /* Protocol Configuration Register 16 */
  FR_PCR17_tag PCR17;                  /* Protocol Configuration Register 17 */
  FR_PCR18_tag PCR18;                  /* Protocol Configuration Register 18 */
  FR_PCR19_tag PCR19;                  /* Protocol Configuration Register 19 */
  FR_PCR20_tag PCR20;                  /* Protocol Configuration Register 20 */
  FR_PCR21_tag PCR21;                  /* Protocol Configuration Register 21 */
  FR_PCR22_tag PCR22;                  /* Protocol Configuration Register 22 */
  FR_PCR23_tag PCR23;                  /* Protocol Configuration Register 23 */
  FR_PCR24_tag PCR24;                  /* Protocol Configuration Register 24 */
  FR_PCR25_tag PCR25;                  /* Protocol Configuration Register 25 */
  FR_PCR26_tag PCR26;                  /* Protocol Configuration Register 26 */
  FR_PCR27_tag PCR27;                  /* Protocol Configuration Register 27 */
  FR_PCR28_tag PCR28;                  /* Protocol Configuration Register 28 */
  FR_PCR29_tag PCR29;                  /* Protocol Configuration Register 29 */
  FR_PCR30_tag PCR30;                  /* Protocol Configuration Register 30 */
  FR_STPWR_tag STPWR;                  /* StopWatch Count Register */
  FR_PEOER_tag PEOER;                  /* Protocol Event Output Enable and StopWatch Control Register */
  uint8_t FR_reserved1[2];
  FR_RFSDOR_tag RFSDOR;                /* Receive FIFO Start Data Offset Register */
  FR_RFSYMBADHR_tag RFSYMBADHR;        /* Receive FIFO System Memory Base Address High Register */
  FR_RFSYMBADLR_tag RFSYMBADLR;        /* Receive FIFO System Memory Base Address Low Register */
  FR_RFPTR_tag RFPTR;                  /* Receive FIFO Periodic Timer Register */
  FR_RFFLPCR_tag RFFLPCR;              /* Receive FIFO Fill Level and POP Count Register */
  FR_EEIFER_tag EEIFER;                /* ECC Error Interrupt Flag and Enable Register */
  FR_EERICR_tag EERICR;                /* ECC Error Report and Injection Control Register */
  FR_EERAR_tag EERAR;                  /* ECC Error Report Address Register */
  FR_EERDR_tag EERDR;                  /* ECC Error Report Data Register */
  FR_EERCR_tag EERCR;                  /* ECC Error Report Code Register */
  FR_EEIAR_tag EEIAR;                  /* ECC Error Injection Address Register */
  FR_EEIDR_tag EEIDR;                  /* ECC Error Injection Data Register */
  FR_EEICR_tag EEICR;                  /* ECC Error Injection Code Register */
  uint8_t FR_reserved2[1792];
  FR_MB_tag MB[128];
  uint8_t FR_reserved3[1024];
  FR_MBDOR_tag MBDOR[132];             /* Message Buffer Data Field Offset Register */
  FR_LEETR_tag LEETR[6];               /* LRAM ECC Error Test Register */
};

#define FrMVR                 0x0000U
#define FrMCR                 0x0001U
#define FrSYMBADHR            0x0002U
#define FrSYMBADLR            0x0003U
#define FrSTBSCR              0x0004U
#define FrSTBPCR              0x0005U
#define FrMBDSR               0x0006U
#define FrMBSSUTR             0x0007U

#define FrPOCR                0x000AU
#define FrGIFER               0x000BU
#define FrPIFR0               0x000CU
#define FrPIFR1               0x000DU
#define FrPIER0               0x000EU
#define FrPIER1               0x000FU
#define FrCHIERFR             0x0010U
#define FrMBIVEC              0x0011U
#define FrCASERCR             0x0012U
#define FrCBSERCR             0x0013U
#define FrPSR0                0x0014U
#define FrPSR1                0x0015U
#define FrPSR2                0x0016U
#define FrPSR3                0x0017U
#define FrMTCTR               0x0018U
#define FrCYCTR               0x0019U
#define FrSLTCTAR             0x001AU
#define FrSLTCTBR             0x001BU
#define FrRTCORVR             0x001CU
#define FrOFCORVR             0x001DU
#define FrCIFRR               0x001EU
#define FrSYMATOR             0x001FU

#define FrSFTOR               0x0021U
#define FrSFCNTR              0x0020U
#define FrSFTCCSR             0x0022U
#define FrSFIDRFR             0x0023U
#define FrSFIDAFVR            0x0024U
#define FrSFIDAFMR            0x0025U
#define FrNMVR0               0x0026U
#define FrNMVR1               0x0027U
#define FrNMVR2               0x0028U
#define FrNMVR3               0x0029U
#define FrNMVR4               0x002AU
#define FrNMVR5               0x002BU
#define FrNMVLR               0x002CU
#define FrTICCR               0x002DU
#define FrTI1CYSR             0x002EU
#define FrTI1MTOR             0x002FU
#define FrTI2CR0              0x0030U
#define FrTI2CR1              0x0031U
#define FrSSSR                0x0032U
#define FrSSCCR               0x0033U
#define FrSSR0                0x0034U
#define FrSSR1                0x0035U
#define FrSSR2                0x0036U
#define FrSSR3                0x0037U
#define FrSSR4                0x0038U
#define FrSSR5                0x0039U
#define FrSSR6                0x003AU
#define FrSSR7                0x003BU
#define FrSSCR0               0x003CU
#define FrSSCR1               0x003DU
#define FrSSCR2               0x003EU
#define FrSSCR3               0x003FU
#define FrMTSACFR             0x0040U
#define FrMTSBCFR             0x0041U
#define FrRSBIR               0x0042U
#define FrRFSR                0x0043U
#define FrRFSIR               0x0044U
#define FrRFDSR               0x0045U
#define FrRFARIR              0x0046U
#define FrRFBRIR              0x0047U
#define FrRFMIDAFVR           0x0048U
#define FrRFMIAFMR            0x0049U
#define FrRFFIDRFVR           0x004AU
#define FrRFFIDRFMR           0x004BU
#define FrRFRFCFR             0x004CU
#define FrRFRFCTR             0x004DU
#define FrLDTXSLAR            0x004EU
#define FrLDTXSLBR            0x004FU
#define FrPCR0                0x0050U
#define FrPCR1                0x0051U
#define FrPCR2                0x0052U
#define FrPCR3                0x0053U
#define FrPCR4                0x0054U
#define FrPCR5                0x0055U
#define FrPCR6                0x0056U
#define FrPCR7                0x0057U
#define FrPCR8                0x0058U
#define FrPCR9                0x0059U
#define FrPCR10               0x005AU
#define FrPCR11               0x005BU
#define FrPCR12               0x005CU
#define FrPCR13               0x005DU
#define FrPCR14               0x005EU
#define FrPCR15               0x005FU
#define FrPCR16               0x0060U
#define FrPCR17               0x0061U
#define FrPCR18               0x0062U
#define FrPCR19               0x0063U
#define FrPCR20               0x0064U
#define FrPCR21               0x0065U
#define FrPCR22               0x0066U
#define FrPCR23               0x0067U
#define FrPCR24               0x0068U
#define FrPCR25               0x0069U
#define FrPCR26               0x006AU
#define FrPCR27               0x006BU
#define FrPCR28               0x006CU
#define FrPCR29               0x006DU
#define FrPCR30               0x006EU

#define FrDER                 0x0070U
#define FrCRSR                0x0071U
#define FrRFSDOR              0x0073U

#define FrRFSYMBADHR          0x0074U
#define FrRFSYMBADLR          0x0075U
#define FrRFPTR               0x0076U
#define FrRFFLPCR             0x0077U


#define FrPIDR                0x0078U
#define FrAVNR                0x0079U
#define FrHIPDSR              0x007AU
#define FrPLPDSR              0x007BU
#define FrHIPPER              0x007CU
#define FrHIPPCR              0x007DU
#define FrPLPPER              0x007EU
#define FrPLPPCR              0x007FU


#define FrMBCCSR0             0x0400U
#define FrMBCCFR0             0x0401U
#define FrMBFIDR0             0x0402U
#define FrMBIDXR0             0x0403U
#define FrMBDOR0              0x0800U

#define FrMCR_MEN             0x8000U
#define FrMCR_SCM             0x2000U
#define FrMCR_CHB             0x1000U
#define FrMCR_CHA             0x0800U
#define FrMCR_SFFE            0x0400U
#define FrMCR_CLKSEL          0x0010U

#define FrPOCR_WME            0x8000U
#define FrPOCR_BSY            0x0080U
#define FrPOCR_WMC            0x0080U

#define FrGIFER_TBIE            0x0001U
#define FrGIFER_RBIE            0x0002U
#define FrGIFER_FNEAIE          0x0004U
#define FrGIFER_FNEBIE          0x0008U
#define FrGIFER_WUPIE           0x0010U
#define FrGIFER_CHIE            0x0020U
#define FrGIFER_PRIE            0x0040U
#define FrGIFER_MIE             0x0080U
#define FrGIFER_TBIF            0x0100U
#define FrGIFER_RBIF            0x0200U
#define FrGIFER_FNEAIF          0x0400U
#define FrGIFER_FNEBIF          0x0800U
#define FrGIFER_WUPIF           0x1000U
#define FrGIFER_CHIF            0x2000U
#define FrGIFER_PRIF            0x4000U
#define FrGIFER_MIF             0x8000U

#define FrPIFR0_CYS_IF          0x0001U
#define FrPIFR0_TI1_IF          0x0002U
#define FrPIFR0_TI2_IF          0x0004U
#define FrPIFR0_TBVA_IF         0x0008U
#define FrPIFR0_TBVB_IF         0x0010U
#define FrPIFR0_LTXA_IF         0x0020U
#define FrPIFR0_LTXB_IF         0x0040U
#define FrPIFR0_MTX_IF          0x0080U
#define FrPIFR0_MXS_IF          0x0100U
#define FrPIFR0_CCL_IF          0x0200U
#define FrPIFR0_MOC_IF          0x0400U
#define FrPIFR0_MRC_IF          0x0800U
#define FrPIFR0_CSA_IF          0x1000U
#define FrPIFR0_ILCF_IF         0x2000U
#define FrPIFR0_INTL_IF         0x4000U
#define FrPIFR0_FATL_IF         0x8000U

#define FrPIER0_CYS_IE          0x0001U
#define FrPIER0_TI1_IE          0x0002U
#define FrPIER0_TI2_IE          0x0004U
#define FrPIER0_TBVA_IE         0x0008U
#define FrPIER0_TBVB_IE         0x0010U
#define FrPIER0_LTXA_IE         0x0020U
#define FrPIER0_LTXB_IE         0x0040U
#define FrPIER0_MTX_IE          0x0080U
#define FrPIER0_MXS_IE          0x0100U
#define FrPIER0_CCL_IE          0x0200U
#define FrPIER0_MOC_IE          0x0400U
#define FrPIER0_MRC_IE          0x0800U
#define FrPIER0_CSA_IE          0x1000U
#define FrPIER0_ILCF_IE         0x2000U
#define FrPIER0_INTL_IE         0x4000U
#define FrPIER0_FATL_IE         0x8000U

#define FrPSR1_FRZ              0x0020U
#define FrPSR1_CSAA             0x8000U
#define FrPSR1_CPN              0x0080U
#define FrPSR1_HHR              0x0040U

#define FrPSR2_NBVB                     0x8000U
#define FrPSR2_NSEB                     0x4000U
#define FrPSR2_STCB                     0x2000U
#define FrPSR2_SBVB                     0x1000U
#define FrPSR2_SSEB                     0x0800U
#define FrPSR2_MTB                      0x0400U
#define FrPSR2_NBVA                     0x0200U
#define FrPSR2_NSEA                     0x0100U
#define FrPSR2_STCA                     0x0080U
#define FrPSR2_SBVA                     0x0040U
#define FrPSR2_SSEA                     0x0020U
#define FrPSR2_MTA                      0x0010U

#define FrPSR2_MTSB_RCV                   0x0400U
#define FrPSR2_MTSB_RCV_SYNERR            0x0C00U
#define FrPSR2_MTSB_RCV_BVIO              0x1400U
#define FrPSR2_MTSB_RCV_SYNERR_BVIO       0x1C00U
#define FrPSR2_MTSB_NOT_RCV               0x0000U
#define FrPSR2_MTSB_NOT_RCV_SYNERR        0x0800U
#define FrPSR2_MTSB_NOT_RCV_BVIO          0x1000U
#define FrPSR2_MTSB_NOT_RCV_SYNERR_BVIO   0x1800U

#define FrPSR2_MTSA_RCV                   0x0010U
#define FrPSR2_MTSA_RCV_SYNERR            0x0030U
#define FrPSR2_MTSA_RCV_BVIO              0x0050U
#define FrPSR2_MTSA_RCV_SYNERR_BVIO       0x0070U
#define FrPSR2_MTSA_NOT_RCV               0x0000U
#define FrPSR2_MTSA_NOT_RCV_SYNERR        0x0020U
#define FrPSR2_MTSA_NOT_RCV_BVIO          0x0040U
#define FrPSR2_MTSA_NOT_RCV_SYNERR_BVIO   0x0060U

#define FrPSR3_WUB              0x2000U
#define FrPSR3_WUA              0x0020U

#define FrSSCCR_MCY             0x0100U
#define FrSSCCR_WMD             0x8000U

#define FrTICCR_T1ST            0x0001U
#define FrTICCR_T1TR            0x0002U
#define FrTICCR_T1SP            0x0004U
#define FrTICCR_T1_REP          0x0010U
#define FrTICCR_T2ST            0x0100U
#define FrTICCR_T2TR            0x0200U
#define FrTICCR_T2SP            0x0400U
#define FrTICCR_T2_REP          0x1000U
#define FrTICCR_T2_CFG          0x2000U

#define FrMTSACFR_MTE           0x8000U
#define FrMTSBCFR_MTE           0x8000U

/* Definition for Fr_enable_interrupts() function */
/* Definition of flags in the GIFER register */
#define FR_MODULE_IRQ                               0x0080U
#define FR_PROTOCOL_IRQ                             0x0040U
#define FR_CHI_IRQ                                  0x0020U
#define FR_WAKEUP_IRQ                               0x0010U
#define FR_FIFO_B_IRQ                               0x0008U
#define FR_FIFO_A_IRQ                               0x0004U
#define FR_RECEIVE_IRQ                              0x0002U
#define FR_TRANSMIT_IRQ                             0x0001U
/* Definition of flags in the PIER0/PIFR0 register */
#define FR_FATAL_PROTOCOL_ERROR_IRQ                 0x8000U
#define FR_INTERNAL_PROTOCOL_ERROR_IRQ              0x4000U
#define FR_ILLEGAL_PROTOCOL_CONFIGURATION_IRQ       0x2000U
#define FR_COLDSTART_ABORT_IRQ                      0x1000U
#define FR_MISSING_RATE_CORRECTION_IRQ              0x0800U
#define FR_MISSING_OFFSET_CORRECTION_IRQ            0x0400U
#define FR_CLOCK_CORRECTION_LIMIT_IRQ               0x0200U
#define FR_MAX_SYNC_FRAMES_DETECTED_IRQ             0x0100U
#define FR_MEDIA_ACCESS_TEST_SYMBOL_RECEIVED_IRQ    0x0080U
#define FR_VIOLATION_CHB_IRQ                        0x0040U
#define FR_VIOLATION_CHA_IRQ                        0x0020U
#define FR_TRANSMISSION_ACROSS_BOUNDARY_CHB_IRQ     0x0010U
/* PRQA S 0791*/
#define FR_TRANSMISSION_ACROSS_BOUNDARY_CHA_IRQ     0x0008U 
#define FR_TIMER_2_EXPIRED_IRQ                      0x0004U
#define FR_TIMER_1_EXPIRED_IRQ                      0x0002U
#define FR_CYCLE_START_IRQ                          0x0001U
/* Definition of flags in the PIER1/PIFR0 register */
#define FR_ERROR_MODE_CHANGED_IRQ                   0x8000U
#define FR_ILLEGAL_PROTOCOL_COMMAND_IRQ             0x4000U
#define FR_PROTOCOL_ENGINE_COM_FAILURE              0x2000U
#define FR_PROTOCOL_STATE_CHANGED_IRQ               0x1000U
#define FR_SLOT_STATUS_COUNTER_3_INCREMENTED_IRQ    0x0800U
#define FR_SLOT_STATUS_COUNTER_2_INCREMENTED_IRQ    0x0400U
#define FR_SLOT_STATUS_COUNTER_1_INCREMENTED_IRQ    0x0200U
#define FR_SLOT_STATUS_COUNTER_0_INCREMENTED_IRQ    0x0100U
#define FR_EVEN_CYCLE_TABLE_WRITTEN_IRQ             0x0020U
#define FR_ODD_CYCLE_TABLE_WRITTEN_IRQ              0x0010U

/* Definition of slot status register */
#define FrSSRn_VFB	                                0x8000U
#define FrSSRn_SYB	                                0x4000U
#define FrSSRn_NFB                                  0x2000U
#define FrSSRn_SUB	                                0x1000U
#define FrSSRn_SEB	                                0x0800U
#define FrSSRn_CEB	                                0x0400U
#define FrSSRn_BVB	                                0x0200U
#define FrSSRn_TCB	                                0x0100U
#define FrSSRn_VFA	                                0x0080U
#define FrSSRn_SYA	                                0x0040U
#define FrSSRn_NFA                                  0x0020U
#define FrSSRn_SUA	                                0x0010U
#define FrSSRn_SEA	                                0x0008U
#define FrSSRn_CEA	                                0x0004U
#define FrSSRn_BVA	                                0x0002U
#define FrSSRn_TCA	                                0x0001U

#define FrRFRFCFR_IBD           0x4000U
#define FrRFRFCFR_WMD           0x8000U

#define FrRFRFCTR_F0EN          0x0001U
#define FrRFRFCTR_F1EN          0x0002U
#define FrRFRFCTR_F2EN          0x0004U
#define FrRFRFCTR_F3EN          0x0008U
#define FrRFRFCTR_F0MD          0x0100U
#define FrRFRFCTR_F1MD          0x0200U
#define FrRFRFCTR_F2MD          0x0400U
#define FrRFRFCTR_F3MD          0x0800U

#define FrPOCR_POCCMD_ALLOW_COLDSTART   0x0000U
#define FrPOCR_POCCMD_ALL_SLOTS         0x0001U
#define FrPOCR_POCCMD_CONFIG            0x0002U
#define FrPOCR_POCCMD_FREEZE            0x0003U
#define FrPOCR_POCCMD_READY             0x0004U
#define FrPOCR_POCCMD_CONFIG_COMPLETE   0x0004U
#define FrPOCR_POCCMD_RUN               0x0005U
#define FrPOCR_POCCMD_DEFAULT_CONFIG    0x0006U
#define FrPOCR_POCCMD_HALT              0x0007U
#define FrPOCR_POCCMD_WAKEUP            0x0008U
#define FrPOCR_POCCMD_RESET             0x000CU

#define FrPSR0_ERRMODE_ACTIVE           0x0000U
#define FrPSR0_ERRMODE_PASSIVE          0x4000U
#define FrPSR0_ERRMODE_COMM_HALT        0x8000U
#define FrPSR0_SLOTMODE_SINGLE          0x0000U
#define FrPSR0_SLOTMODE_ALL_PENDING     0x1000U
#define FrPSR0_SLOTMODE_ALL             0x2000U

#define FrPSR0_PROTSTATE_DEFAULT_CONFIG 0x0000U
#define FrPSR0_PROTSTATE_CONFIG         0x0100U
#define FrPSR0_PROTSTATE_WAKEUP         0x0200U
#define FrPSR0_PROTSTATE_READY          0x0300U
#define FrPSR0_PROTSTATE_NORMAL_PASSIVE 0x0400U
#define FrPSR0_PROTSTATE_NORMAL_ACTIVE  0x0500U
#define FrPSR0_PROTSTATE_HALT           0x0600U
#define FrPSR0_PROTSTATE_STARTUP        0x0700U

#define FrPSR0_STARTUPSTATE_COLDSTART_COLLISION_RESOLUTION  0x0020U
#define FrPSR0_STARTUPSTATE_COLDSTART_LISTEN                0x0030U
#define FrPSR0_STARTUPSTATE_INTEGRATION_CONSISTENCY_CHECK   0x0040U
#define FrPSR0_STARTUPSTATE_INTEGRATION_LISTEN              0x0050U
#define FrPSR0_STARTUPSTATE_INITIALIZE_SCHEDULE             0x0070U
#define FrPSR0_STARTUPSTATE_COLDSTART_CONSISTENCY_CHECK     0x00A0U
#define FrPSR0_STARTUPSTATE_INTEGRATION_COLDSTART_CHECK     0x00D0U
#define FrPSR0_STARTUPSTATE_COLDSTART_GAP                   0x00E0U
#define FrPSR0_STARTUPSTATE_COLDSTART_JOIN                  0x00F0U

#define FrPSR0_WAKEUPSTATUS_RECEIVED_HEADER                 0x0001U
#define FrPSR0_WAKEUPSTATUS_RECEIVED_WUP                    0x0002U
#define FrPSR0_WAKEUPSTATUS_COLLISION_HEADER                0x0003U
#define FrPSR0_WAKEUPSTATUS_COLLISION_WUP                   0x0004U
#define FrPSR0_WAKEUPSTATUS_COLLISION_UNKNOWN               0x0005U
#define FrPSR0_WAKEUPSTATUS_TRANSMITTED                     0x0006U

#define FrRSBIR_WMD                     0x8000U
#define FrRSBIR_SEL_RSBIR_A1            0x0000U
#define FrRSBIR_SEL_RSBIR_A2            0x1000U
#define FrRSBIR_SEL_RSBIR_B1            0x2000U
#define FrRSBIR_SEL_RSBIR_B2            0x3000U

#define FrMBCCSR_MCM                    0x4000U
#define FrMBCCSR_MBT                    0x2000U
#define FrMBCCSR_MTD                    0x1000U
#define FrMBCCSR_CMT                    0x0800U
#define FrMBCCSR_EDT                    0x0400U
#define FrMBCCSR_LCKT                   0x0200U
#define FrMBCCSR_MBIE                   0x0100U
#define FrMBCCSR_DUP                    0x0010U
#define FrMBCCSR_DVAL                   0x0008U
#define FrMBCCSR_EDS                    0x0004U
#define FrMBCCSR_LCKS                   0x0002U
#define FrMBCCSR_MBIF                   0x0001U

#define FrMBCCFR_MTM                    0x8000U
#define FrMBCCFR_CHA                    0x4000U
#define FrMBCCFR_CHB                    0x2000U
#define FrMBCCFR_CCFE                   0x1000U

#define FrF_HEADER_PPI                  0x4000U
#define FrF_HEADER_NUF                  0x2000U
#define FrF_HEADER_VFB                  0x8000U
#define FrF_HEADER_VFA                  0x0080U
#define FrPcr9_bit                      0x005AU
#define FrPcr14_bit                     0x3FFFU

#endif
