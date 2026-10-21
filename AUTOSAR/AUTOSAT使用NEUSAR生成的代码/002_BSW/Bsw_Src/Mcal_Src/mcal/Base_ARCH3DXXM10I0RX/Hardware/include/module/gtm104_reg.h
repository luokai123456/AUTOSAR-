#ifndef GTM104_REG_H_
#define GTM104_REG_H_

/* ============================================================================
   =============================== Module: GTM ================================
   ============================================================================ */

struct GTM_tag {
  union {                              /* GTM Revision Register */
    vuint32_t R;
    struct {
      vuint32_t DEV_CODE2:4;           /* Device encoding digit 2. */
      vuint32_t DEV_CODE1:4;           /* Device encoding digit 1. */
      vuint32_t DEV_CODE0:4;           /* Device encoding digit 0. */
      vuint32_t MAJOR:4;               /* Major version number */
      vuint32_t MINOR:4;               /* Minor version number */
      vuint32_t NO:4;                  /* Delivery number. */
      vuint32_t STEP:8;                /* Release step. */
    } B;
  } REV;

  union {                              /* GTM Reset Register */
    vuint32_t R;
    struct {
      vuint32_t  :31;
      vuint32_t RST:1;                 /* GTM Reset. */
    } B;
  } RST;

  union {                              /* GTM Control Register */
    vuint32_t R;
    struct {
      vuint32_t  :23;                  /* Read as zero, should be written as zero. */
      vuint32_t TO_VAL:5;              /* AEI Timeout value. */
      vuint32_t  :2;                   /* Read as zero, should be written as zero. */
      vuint32_t TO_MODE:1;             /* AEI Timeout mode. */
      vuint32_t RF_PROT:1;             /* RST and FORCINT protection. */
    } B;
  } CTRL;

  union {                              /* GTM AEI Address Pointer Register */
    vuint32_t R;
    struct {
      vuint32_t  :11;
      vuint32_t TO_W1R0:1;             /* AEI Timeout Read/Write flag. */
      vuint32_t TO_ADDR:20;            /* AEI Timeout address. */
    } B;
  } AEI_ADDR_XPT;

  union {                              /* GTM Interrupt Request Notification Register */
    vuint32_t R;
    struct {
      vuint32_t  :28;
      vuint32_t AEI_USP_BE:1;          /* AEI Unsupported byte enable interrupt. */
      vuint32_t AEI_IM_ADDR:1;         /* AEI Illegal Module address interrupt. */
      vuint32_t AEI_USP_ADDR:1;        /* AEI Unsupported address interrupt. */
      vuint32_t AEI_TO_XPT:1;          /* AEI Timeout exception occurred. */
    } B;
  } IRQ_NOTIFY;

  union {                              /* GTM Interrupt Request Enable Register */
    vuint32_t R;
    struct {
      vuint32_t  :28;
      vuint32_t AEI_USP_BE_IRQ_EN:1;   /* AEI Unsupported Byte Enable Interrupt Enable. */
      vuint32_t AEI_IM_ADDR_IRQ_EN:1;  /* AEI Illegal Module Address Interrupt Enable. */
      vuint32_t AEI_USP_ADDR_IRQ_EN:1; /* AEI Unsupported Address Interrupt Enable. */
      vuint32_t AEI_TO_XPT_IRQ_EN:1;   /* AEI Timeout Exception Interrupt Enable. */
    } B;
  } IRQ_EN;

  union {                              /* GTM Force Interrupt Request Register */
    vuint32_t R;
    struct {
      vuint32_t  :28;
      vuint32_t TRG_AEI_USP_BE:1;      /* Trigger AEI_USP_BE_IRQ interrupt by software. */
      vuint32_t TRG_AEI_IM_ADDR:1;     /* Trigger AEI_IM_ADDR_IRQ interrupt by software. */
      vuint32_t TRG_AEI_USP_ADDR:1;    /* Trigger AEI_USP_ADDR_IRQ interrupt by software. */
      vuint32_t TRG_AEI_TO_XPT:1;      /* Trigger AEI_TO_XPT_IRQ interrupt by software. */
    } B;
  } IRQ_FORCINT;

  union {                              /* GTM Interrupt Request Mode Register */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Read as zero, should be written as zero. */
      vuint32_t IRQ_MODE:2;            /* Interrupt strategy mode selection for the AEI timeout and address monitoring interrupts. */
    } B;
  } IRQ_MODE;

  union {                              /* GTM Error Interrupt Request Enable register */
    vuint32_t R;
    struct {
      vuint32_t  :28;
      vuint32_t AEI_USP_BE_EIRQ_EN:1;  /* AEI_USP_BE_EIRQ error interrupt enable. */
      vuint32_t AEI_IM_ADDR_EIRQ_EN:1; /* AEI_IM_ADDR_EIRQ error interrupt enable. */
      vuint32_t AEI_USP_ADDR_EIRQ_EN:1; /* AEI_USP_ADDR_EIRQ error interrupt enable. */
      vuint32_t AEI_TO_XPT_EIRQ_EN:1;  /* AEI_TO_XPT_EIRQ error interrupt enable. */
    } B;
  } EIRQ_EN;

  uint8_t GTM_reserved0[12];
  union {                              /* GTM Bridge Mode Register */
    vuint32_t R;
    struct {
      vuint32_t BUFF_DPT:8;            /* Buffer depth of AEI bridge. */
      vuint32_t  :7;
      vuint32_t BRG_RST:1;             /* Bridge software reset. */
      vuint32_t  :3;
      vuint32_t SYNC_INPUT_REG:1;      /* Additional pipelined stage in synchronous bridge mode. */
      vuint32_t  :2;
      vuint32_t BUFF_OVL:1;            /* Buffer overflow register. */
      vuint32_t MODE_UP_PGR:1;         /* Mode update in progress. */
      vuint32_t  :6;
      vuint32_t MSK_WR_RSP:1;          /* Mask write response. */
      vuint32_t BRG_MODE:1;            /* Defines the operation mode for the AEI bridge. */
    } B;
  } BRIDGE_MODE;

  union {                              /* GTM Bridge Pointer 1 Register */
    vuint32_t R;
    struct {
      vuint32_t RSP_TRAN_RDY:6;        /* Response transactions ready. */
      vuint32_t FBC:6;                 /* Free buffer count. */
      vuint32_t ABT_TRAN_PGR:5;        /* Aborted transaction in progress pointer. */
      vuint32_t TRAN_IN_PGR:5;         /* Transaction in progress pointer (acquire). */
      vuint32_t FIRST_RSP_PTR:5;       /* First response pointer. */
      vuint32_t NEW_TRAN_PTR:5;        /* New transaction pointer. */
    } B;
  } BRIDGE_PTR1;

  union {                              /* GTM Bridge Pointer 2 Register */
    vuint32_t R;
    struct {
      vuint32_t  :27;
      vuint32_t TRAN_IN_PGR2:5;        /* Transaction in progress pointer (aquire2). */
    } B;
  } BRIDGE_PTR2;

  uint8_t GTM_reserved1[4];
  union {                              /* GTM TIM0 Auxiliary Input Source register */
    vuint32_t R;
    struct {
      vuint32_t  :24;
      vuint32_t SRC_CH7:1;             /* Defines AUX_IN source of TIM[i] channel 7. */
      vuint32_t SRC_CH6:1;             /* Defines AUX_IN source of TIM[i] channel 6. */
      vuint32_t SRC_CH5:1;             /* Defines AUX_IN source of TIM[i] channel 5. */
      vuint32_t SRC_CH4:1;             /* Defines AUX_IN source of TIM[i] channel 4. */
      vuint32_t SRC_CH3:1;             /* Defines AUX_IN source of TIM[i] channel 3. */
      vuint32_t SRC_CH2:1;             /* Defines AUX_IN source of TIM[i] channel 2. */
      vuint32_t SRC_CH1:1;             /* Defines AUX_IN source of TIM[i] channel 1. */
      vuint32_t SRC_CH0:1;             /* Defines AUX_IN source of TIM[i] channel 0. */
    } B;
  } TIM0_AUX_IN_SRC;

  union {                              /* GTM TIM1 Auxiliary Input Source register */
    vuint32_t R;
    struct {
      vuint32_t  :24;
      vuint32_t SRC_CH7:1;             /* Defines AUX_IN source of TIM[i] channel 7. */
      vuint32_t SRC_CH6:1;             /* Defines AUX_IN source of TIM[i] channel 6. */
      vuint32_t SRC_CH5:1;             /* Defines AUX_IN source of TIM[i] channel 5. */
      vuint32_t SRC_CH4:1;             /* Defines AUX_IN source of TIM[i] channel 4. */
      vuint32_t SRC_CH3:1;             /* Defines AUX_IN source of TIM[i] channel 3. */
      vuint32_t SRC_CH2:1;             /* Defines AUX_IN source of TIM[i] channel 2. */
      vuint32_t SRC_CH1:1;             /* Defines AUX_IN source of TIM[i] channel 1. */
      vuint32_t SRC_CH0:1;             /* Defines AUX_IN source of TIM[i] channel 0. */
    } B;
  } TIM1_AUX_IN_SRC;

  union {                              /* GTM TIM2 Auxiliary Input Source register */
    vuint32_t R;
    struct {
      vuint32_t  :24;
      vuint32_t SRC_CH7:1;             /* Defines AUX_IN source of TIM[i] channel 7. */
      vuint32_t SRC_CH6:1;             /* Defines AUX_IN source of TIM[i] channel 6. */
      vuint32_t SRC_CH5:1;             /* Defines AUX_IN source of TIM[i] channel 5. */
      vuint32_t SRC_CH4:1;             /* Defines AUX_IN source of TIM[i] channel 4. */
      vuint32_t SRC_CH3:1;             /* Defines AUX_IN source of TIM[i] channel 3. */
      vuint32_t SRC_CH2:1;             /* Defines AUX_IN source of TIM[i] channel 2. */
      vuint32_t SRC_CH1:1;             /* Defines AUX_IN source of TIM[i] channel 1. */
      vuint32_t SRC_CH0:1;             /* Defines AUX_IN source of TIM[i] channel 0. */
    } B;
  } TIM2_AUX_IN_SRC;

  union {                              /* GTM TIM3 Auxiliary Input Source register */
    vuint32_t R;
    struct {
      vuint32_t  :24;
      vuint32_t SRC_CH7:1;             /* Defines AUX_IN source of TIM[i] channel 7. */
      vuint32_t SRC_CH6:1;             /* Defines AUX_IN source of TIM[i] channel 6. */
      vuint32_t SRC_CH5:1;             /* Defines AUX_IN source of TIM[i] channel 5. */
      vuint32_t SRC_CH4:1;             /* Defines AUX_IN source of TIM[i] channel 4. */
      vuint32_t SRC_CH3:1;             /* Defines AUX_IN source of TIM[i] channel 3. */
      vuint32_t SRC_CH2:1;             /* Defines AUX_IN source of TIM[i] channel 2. */
      vuint32_t SRC_CH1:1;             /* Defines AUX_IN source of TIM[i] channel 1. */
      vuint32_t SRC_CH0:1;             /* Defines AUX_IN source of TIM[i] channel 0. */
    } B;
  } TIM3_AUX_IN_SRC;

  union {                              /* GTM TIM4 Auxiliary Input Source register */
    vuint32_t R;
    struct {
      vuint32_t  :24;
      vuint32_t SRC_CH7:1;             /* Defines AUX_IN source of TIM[i] channel 7. */
      vuint32_t SRC_CH6:1;             /* Defines AUX_IN source of TIM[i] channel 6. */
      vuint32_t SRC_CH5:1;             /* Defines AUX_IN source of TIM[i] channel 5. */
      vuint32_t SRC_CH4:1;             /* Defines AUX_IN source of TIM[i] channel 4. */
      vuint32_t SRC_CH3:1;             /* Defines AUX_IN source of TIM[i] channel 3. */
      vuint32_t SRC_CH2:1;             /* Defines AUX_IN source of TIM[i] channel 2. */
      vuint32_t SRC_CH1:1;             /* Defines AUX_IN source of TIM[i] channel 1. */
      vuint32_t SRC_CH0:1;             /* Defines AUX_IN source of TIM[i] channel 0. */
    } B;
  } TIM4_AUX_IN_SRC;

  union {                              /* GTM TIM5 Auxiliary Input Source register */
    vuint32_t R;
    struct {
      vuint32_t  :24;
      vuint32_t SRC_CH7:1;             /* Defines AUX_IN source of TIM[i] channel 7. */
      vuint32_t SRC_CH6:1;             /* Defines AUX_IN source of TIM[i] channel 6. */
      vuint32_t SRC_CH5:1;             /* Defines AUX_IN source of TIM[i] channel 5. */
      vuint32_t SRC_CH4:1;             /* Defines AUX_IN source of TIM[i] channel 4. */
      vuint32_t SRC_CH3:1;             /* Defines AUX_IN source of TIM[i] channel 3. */
      vuint32_t SRC_CH2:1;             /* Defines AUX_IN source of TIM[i] channel 2. */
      vuint32_t SRC_CH1:1;             /* Defines AUX_IN source of TIM[i] channel 1. */
      vuint32_t SRC_CH0:1;             /* Defines AUX_IN source of TIM[i] channel 0. */
    } B;
  } TIM5_AUX_IN_SRC;
};


/* ============================================================================
   =============================== Module: GTMINT =============================
   ============================================================================ */

typedef union GTMINT_GTMMCR_union_tag { /* GTM Module Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t MDIS:1;                  /* [Covers: Saf1461] MDIS Module Disable. */
    vuint32_t  :13;
    vuint32_t AEISREN:1;               /* Saf1276 - Safety-critical AEISREN AEI interface soft-reset control enable. */
    vuint32_t  :1;
    vuint32_t STPS:1;                  /* [Covers: Saf1461] STPS Stop Mode Status. */
    vuint32_t  :14;
  } B;
} GTMINT_GTMMCR_tag;

typedef union GTMINT_GTMINTCLR_union_tag { /* GTM Interrupts Clear Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t INTCLR_PTR:10;           /* [Covers: Saf1461] INTCLR_PTR Interrupt Clear Pointer. */
  } B;
} GTMINT_GTMINTCLR_tag;

typedef union GTMINT_GTMAEICR_union_tag { /* GTM AEI Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t AEISRST:1;               /* [Covers: Saf1461] AEISRST AEI interface soft-reset control. */
  } B;
} GTMINT_GTMAEICR_tag;

struct GTMINT_tag {
  uint8_t GTMINT_reserved0[192];
  GTMINT_GTMMCR_tag GTMMCR;            /* GTM Module Configuration Register */
  uint8_t GTMINT_reserved1[4];
  GTMINT_GTMINTCLR_tag GTMINTCLR;      /* GTM Interrupts Clear Register */
  GTMINT_GTMAEICR_tag GTMAEICR;        /* GTM AEI Control Register */
};


/* ============================================================================
   =============================== Module: GTM_AFD ============================
   ============================================================================ */

struct GTM_AFD_tag {
  struct {
    union {                            /* AFD FIFO Channel n Buffer Access Register, n=0:7 */
      vuint32_t R;
      struct {
        vuint32_t  :3;
        vuint32_t DATA:29;             /* Read/write data from/to FIFO. */
      } B;
    } BUF_ACC;
    uint8_t CH_reserved0[12];
  } CH[8];
};


/* ============================================================================
   =============================== Module: GTM_ARU ============================
   ============================================================================ */

struct GTM_ARU_tag {
  union {                              /* ARU Access Register */
    vuint32_t R;
    struct {
      vuint32_t  :18;
      vuint32_t WREQ:1;                /* Initiate write request. */
      vuint32_t RREQ:1;                /* Initiate read request. */
      vuint32_t  :3;
      vuint32_t ADDR:9;                /* ARU address. */
    } B;
  } ACCESS;

  union {                              /* ARU Data High Register */
    vuint32_t R;
    struct {
      vuint32_t  :3;
      vuint32_t DATA:29;               /* Upper ARU data word. */
    } B;
  } DATA_H;

  union {                              /* ARU Data Low Register */
    vuint32_t R;
    struct {
      vuint32_t  :3;
      vuint32_t DATA:29;               /* Lower ARU data word. */
    } B;
  } DATA_L;

  union {                              /* ARU Debug Access 0 Register */
    vuint32_t R;
    struct {
      vuint32_t  :23;
      vuint32_t ADDR:9;                /* ARU debugging address. */
    } B;
  } DBG_ACCESS0;

  union {                              /* ARU Debug Data 0 High Register */
    vuint32_t R;
    struct {
      vuint32_t  :3;
      vuint32_t DATA:29;               /* Upper debug data word. */
    } B;
  } DBG_DATA0_H;

  union {                              /* ARU Debug Data 0 Low Register */
    vuint32_t R;
    struct {
      vuint32_t  :3;
      vuint32_t DATA:29;               /* Lower debug data word. */
    } B;
  } DBG_DATA0_L;

  union {                              /* ARU Debug Access 1 Register */
    vuint32_t R;
    struct {
      vuint32_t  :23;
      vuint32_t ADDR:9;                /* ARU debugging address. */
    } B;
  } DBG_ACCESS1;

  union {                              /* ARU Debug Data 1 High */
    vuint32_t R;
    struct {
      vuint32_t  :3;
      vuint32_t DATA:29;               /* Upper debug data word */
    } B;
  } DBG_DATA1_H;

  union {                              /* ARU Debug Data 1 Low Register */
    vuint32_t R;
    struct {
      vuint32_t  :3;
      vuint32_t DATA:29;               /* Lower debug data word. */
    } B;
  } DBG_DATA1_L;

  union {                              /* ARU Interrupt Request Notification Register */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t ACC_ACK:1;             /* On read access data valid, AEI to ARU access is complete. */
      vuint32_t NEW_DATA1:1;           /* Data was transferred for address ARU_DBG_ACCESS1. */
      vuint32_t NEW_DATA0:1;           /* Data was transferred for address ARU_DBG_ACCESS0. */
    } B;
  } IRQ_NOTIFY;

  union {                              /* ARU Interrupt Request Enable Register */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t ACC_ACK_IRQ_EN:1;      /* ACC_ACK_IRQ interrupt enable. */
      vuint32_t NEW_DATA1_IRQ_EN:1;    /* ARU_NEW_DATA1_IRQ interrupt enable. */
      vuint32_t NEW_DATA0_IRQ_EN:1;    /* ARU_NEW_DATA0_IRQ interrupt enable. */
    } B;
  } IRQ_EN;

  union {                              /* ARU Force Interrupt Request Register */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t TRG_ACC_ACK:1;         /* Trigger ACC_ACK interrupt. */
      vuint32_t TRG_NEW_DATA1:1;       /* Trigger new data 1 interrupt. */
      vuint32_t TRG_NEW_DATA0:1;       /* Trigger new data 0 interrupt. */
    } B;
  } IRQ_FORCINT;

  union {                              /* ARU Interrupt Request Mode Register */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t IRQ_MODE:2;            /* IRQ mode select. */
    } B;
  } IRQ_MODE;
};


/* ============================================================================
   =============================== Module: GTM_ATOM ===========================
   ============================================================================ */

struct GTM_ATOM_tag {
  union {                              /* ATOM Channel n Read Address Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :7;
      vuint32_t RDADDR1:9;             /* ARU Read address 1. */
      vuint32_t  :7;
      vuint32_t RDADDR0:9;             /* ARU Read address 0. */
    } B;
  } CH0_RDADDR;

  union {                              /* ATOM Channel n Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :4;
      vuint32_t ABM:1;                 /* ARU blocking mode. */
      vuint32_t OSM:1;                 /* One-shot mode. */
      vuint32_t SLA:1;                 /* Serve last ARU communication strategy */
      vuint32_t TRIGOUT:1;             /* NTrigger output selection (output signal TRIG_CHn) of module ATOM_CHn. */
      vuint32_t  :3;                   /* Reads as zero, should be written as zero. */
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :3;
      vuint32_t WR_REQ:1;              /* CPU Write request bit for late compare register update. */
      vuint32_t  :1;
      vuint32_t CLK_SRC_SR:3;          /* Actual CMU clock source (SOMS) / shadow register for CMU clock source (SOMP). */
      vuint32_t SL:1;                  /* Initial signal level after channel enable. */
      vuint32_t  :1;
      vuint32_t CMP_CTRL:1;            /* CCUn compare strategy select.. */
      vuint32_t ACB:5;                 /* ATOM Mode control bits. */
      vuint32_t ARU_EN:1;              /* ARU Input stream enable. */
      vuint32_t TB12_SEL:1;            /* Select time base value TBU_TS1 or TBU_TS2. */
      vuint32_t MODE:2;                /* ATOM channel mode select. */
    } B;
  } CH0_CTRL;

  union {                              /* ATOM Channel n Shadow 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t SR0:24;                /* ATOM channel n shadow register SR0. */
    } B;
  } CH0_SR0;

  union {                              /* ATOM Channel n Shadow 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t SR1:24;                /* ATOM channel n shadow register SR1. */
    } B;
  } CH0_SR1;

  union {                              /* ATOM Channel n Compare Match 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CM0:24;                /* ATOM CCU0 compare register. */
    } B;
  } CH0_CM0;

  union {                              /* ATOM Channel n Compare Match 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CM1:24;                /* ATOM CCU1 compare register. */
    } B;
  } CH0_CM1;

  union {                              /* ATOM Channel n Counter 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CN0:24;                /* ATOM CCU0 counter register. */
    } B;
  } CH0_CN0;

  union {                              /* ATOM Channel n Status Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :3;
      vuint32_t ACBO:5;                /* ATOM Internal status bits. */
      vuint32_t  :1;
      vuint32_t WRF:1;                 /* Write request of CPU failed for late update. */
      vuint32_t DV:1;                  /* Valid ARU Data stored in compare registers. */
      vuint32_t ACBI:5;                /* ATOM Mode control bits received through ARU. */
      vuint32_t  :15;
      vuint32_t OL:1;                  /* Actual output signal level of ATOM_CHn_OUT. */
    } B;
  } CH0_STAT;

  union {                              /* ATOM Channel n Interrupt Request Notification Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH0_IRQ_NOTIFY;

  union {                              /* ATOM Channel n Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t CCU1TC_IRQ_EN:1;       /* ATOM_CCU1TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* ATOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH0_IRQ_EN;

  union {                              /* ATOM Channel n Force Interrupt Request Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t TRG_CCU1TC:1;          /* Trigger ATOM_CCU1TC_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC:1;          /* Trigger ATOM_CCU0TC_IRQ interrupt by software. */
    } B;
  } CH0_IRQ_FORCINT;

  union {                              /* ATOM Channel n Interrupt Request Mode Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH0_IRQ_MODE;

  uint8_t ATOM_reserved0[16];
  union {                              /* ATOM AGC Global Control Register */
    vuint32_t R;
    struct {
      vuint32_t UPEN_CTRL7:2;          /* For channel 7, ATOM channel enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t UPEN_CTRL6:2;          /* For channel 6, ATOM channel enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t UPEN_CTRL5:2;          /* For channel 5, ATOM channel enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t UPEN_CTRL4:2;          /* For channel 4, ATOM channel enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t UPEN_CTRL3:2;          /* For channel 3, ATOM channel enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t UPEN_CTRL2:2;          /* For channel 2, ATOM channel enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t UPEN_CTRL1:2;          /* For channel 1, ATOM channel enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t UPEN_CTRL0:2;          /* For channel 0, ATOM channel enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t RST_CH7:1;             /* See RST_CH0 */
      vuint32_t RST_CH6:1;             /* See RST_CH0 */
      vuint32_t RST_CH5:1;             /* See RST_CH0 */
      vuint32_t RST_CH4:1;             /* See RST_CH0 */
      vuint32_t RST_CH3:1;             /* See RST_CH0 */
      vuint32_t RST_CH2:1;             /* See RST_CH0 */
      vuint32_t RST_CH1:1;             /* See RST_CH0 */
      vuint32_t RST_CH0:1;             /* Software reset of corresponding channel 0. */
      vuint32_t  :7;
      vuint32_t HOST_TRIG:1;           /* Trigger request signal (see AGC) to update the register ENDIS_STAT and OUTEN_STAT. */
    } B;
  } AGC_GLB_CTRL;

  union {                              /* ATOM TGC0 Enable/Disable Control Register */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t ENDIS_CTRL7:2;         /* Channel 7 enable/disable update value. */
      vuint32_t ENDIS_CTRL6:2;         /* Channel 6 enable/disable update value. */
      vuint32_t ENDIS_CTRL5:2;         /* Channel 5 enable/disable update value. */
      vuint32_t ENDIS_CTRL4:2;         /* TOM channel 4 enable/disable update value. */
      vuint32_t ENDIS_CTRL3:2;         /* TOM channel 3 enable/disable update value. */
      vuint32_t ENDIS_CTRL2:2;         /* TOM channel 2 enable/disable update value. */
      vuint32_t ENDIS_CTRL1:2;         /* TOM channel 1 enable/disable update value. */
      vuint32_t ENDIS_CTRL0:2;         /* TOM channel 0 enable/disable update value. */
    } B;
  } AGC_ENDIS_CTRL;

  union {                              /* ATOM TGC0 Enable/Disable Status Register */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t ENDIS_STAT7:2;         /* TOM channel 7 enable/disable. */
      vuint32_t ENDIS_STAT6:2;         /* TOM channel 6 enable/disable. */
      vuint32_t ENDIS_STAT5:2;         /* TOM channel 5 enable/disable. */
      vuint32_t ENDIS_STAT4:2;         /* TOM channel 4 enable/disable. */
      vuint32_t ENDIS_STAT3:2;         /* TOM channel 3 enable/disable. */
      vuint32_t ENDIS_STAT2:2;         /* TOM channel 2 enable/disable. */
      vuint32_t ENDIS_STAT1:2;         /* TOM channel 1 enable/disable. */
      vuint32_t ENDIS_STAT0:2;         /* TOM channel 0 enable/disable. */
    } B;
  } AGC_ENDIS_STAT;

  union {                              /* ATOM TGC0 Action Time Base Register */
    vuint32_t R;
    struct {
      vuint32_t  :5;
      vuint32_t TBU_SEL:2;             /* Selection of time base used for comparison. */
      vuint32_t TB_TRIG:1;             /* Set trigger request. */
      vuint32_t ACT_TB:24;             /* Specifies the signed compare value with selected signal TBU_TS[n], x=0..2. */
    } B;
  } AGC_ACT_TB;

  union {                              /* ATOM TGC0 Out Enable Control Register */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t OUTEN_CTRL7:2;         /* Output TOM_OUT(7) enable/disable update value. */
      vuint32_t OUTEN_CTRL6:2;         /* Output TOM_OUT(6) enable/disable update value. */
      vuint32_t OUTEN_CTRL5:2;         /* Output TOM_OUT(5) enable/disable update value. */
      vuint32_t OUTEN_CTRL4:2;         /* Output TOM_OUT(4) enable/disable update value. */
      vuint32_t OUTEN_CTRL3:2;         /* Output TOM_OUT(3) enable/disable update value. */
      vuint32_t OUTEN_CTRL2:2;         /* Output TOM_OUT(2) enable/disable update value. */
      vuint32_t OUTEN_CTRL1:2;         /* Output TOM_OUT(1) enable/disable update value. */
      vuint32_t OUTEN_CTRL0:2;         /* Output TOM_OUT(0) enable/disable update value. */
    } B;
  } AGC_OUTEN_CTRL;

  union {                              /* ATOM TGC0 Out Enable Control/Status Register */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t OUTEN_STAT7:2;         /* Control/status of output TOM_OUT(7). */
      vuint32_t OUTEN_STAT6:2;         /* Control/status of output TOM_OUT(6). */
      vuint32_t OUTEN_STAT5:2;         /* Control/status of output TOM_OUT(5). */
      vuint32_t OUTEN_STAT4:2;         /* Control/status of output TOM_OUT(4) */
      vuint32_t OUTEN_STAT3:2;         /* Control/status of output TOM_OUT(3). */
      vuint32_t OUTEN_STAT2:2;         /* Control/status of output TOM_OUT(2). */
      vuint32_t OUTEN_STAT1:2;         /* Control/status of output TOM_OUT(1). */
      vuint32_t OUTEN_STAT0:2;         /* Control/status of output TOM_OUT(0). */
    } B;
  } AGC_OUTEN_STAT;

  union {                              /* ATOM TGC0 Force Update Control Register */
    vuint32_t R;
    struct {
      vuint32_t RSTCN0_CH7:2;          /* Reset CN0 of channel 7 on force update event. */
      vuint32_t RSTCN0_CH6:2;          /* Reset CN0 of channel 6 on force update event. */
      vuint32_t RSTCN0_CH5:2;          /* Reset CN0 of channel 5 on force update event. */
      vuint32_t RSTCN0_CH4:2;          /* Reset CN0 of channel 4 on force update event. */
      vuint32_t RSTCN0_CH3:2;          /* Reset CN0 of channel 3 on force update event. */
      vuint32_t RSTCN0_CH2:2;          /* Reset CN0 of channel 2 on force update event. */
      vuint32_t RSTCN0_CH1:2;          /* Reset CN0 of channel 1 on force update event. */
      vuint32_t RSTCN0_CH0:2;          /* Reset CN0 of channel 0 on force update event. */
      vuint32_t FUPD_CTRL7:2;          /* Force update of TOM channel 7 operation registers. */
      vuint32_t FUPD_CTRL6:2;          /* Force update of TOM channel 6 operation registers, */
      vuint32_t FUPD_CTRL5:2;          /* Force update of TOM channel 5 operation registers. */
      vuint32_t FUPD_CTRL4:2;          /* Force update of TOM channel 4 operation registers. */
      vuint32_t FUPD_CTRL3:2;          /* Force update of TOM channel 3 operation registers. */
      vuint32_t FUPD_CTRL2:2;          /* ce update of TOM channel 2 operation registers. */
      vuint32_t FUPD_CTRL1:2;          /* Force update of TOM channel 1 operation registers. */
      vuint32_t FUPD_CTRL0:2;          /* Force update of TOM channel 0 operation registers. */
    } B;
  } AGC_FUPD_CTRL;

  union {                              /* ATOM TGC0 Interrupt Trigger Register */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t INT_TRIG7:2;           /* Select input signal TRIG_7 as a trigger source. */
      vuint32_t INT_TRIG6:2;           /* Select input signal TRIG_6 as a trigger source. */
      vuint32_t INT_TRIG5:2;           /* Select input signal TRIG_5 as a trigger source. */
      vuint32_t INT_TRIG4:2;           /* Select input signal TRIG_4 as a trigger source. */
      vuint32_t INT_TRIG3:2;           /* Select input signal TRIG_3 as a trigger source. */
      vuint32_t INT_TRIG2:2;           /* Select input signal TRIG_2 as a trigger source. */
      vuint32_t INT_TRIG1:2;           /* Select input signal TRIG_1 as a trigger source. */
      vuint32_t INT_TRIG0:2;           /* Select input signal TRIG_0 as a trigger source. */
    } B;
  } AGC_INT_TRIG;

  uint8_t ATOM_reserved1[32];
  union {                              /* ATOM Channel n Read Address Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :7;
      vuint32_t RDADDR1:9;             /* ARU Read address 1. */
      vuint32_t  :7;
      vuint32_t RDADDR0:9;             /* ARU Read address 0. */
    } B;
  } CH1_RDADDR;

  union {                              /* ATOM Channel n Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :4;
      vuint32_t ABM:1;                 /* ARU blocking mode. */
      vuint32_t OSM:1;                 /* One-shot mode. */
      vuint32_t SLA:1;                 /* Serve last ARU communication strategy */
      vuint32_t TRIGOUT:1;             /* NTrigger output selection (output signal TRIG_CHn) of module ATOM_CHn. */
      vuint32_t  :3;                   /* Reads as zero, should be written as zero. */
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :3;
      vuint32_t WR_REQ:1;              /* CPU Write request bit for late compare register update. */
      vuint32_t  :1;
      vuint32_t CLK_SRC_SR:3;          /* Actual CMU clock source (SOMS) / shadow register for CMU clock source (SOMP). */
      vuint32_t SL:1;                  /* Initial signal level after channel enable. */
      vuint32_t  :1;
      vuint32_t CMP_CTRL:1;            /* CCUn compare strategy select.. */
      vuint32_t ACB:5;                 /* ATOM Mode control bits. */
      vuint32_t ARU_EN:1;              /* ARU Input stream enable. */
      vuint32_t TB12_SEL:1;            /* Select time base value TBU_TS1 or TBU_TS2. */
      vuint32_t MODE:2;                /* ATOM channel mode select. */
    } B;
  } CH1_CTRL;

  union {                              /* ATOM Channel n Shadow 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t SR0:24;                /* ATOM channel n shadow register SR0. */
    } B;
  } CH1_SR0;

  union {                              /* ATOM Channel n Shadow 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t SR1:24;                /* ATOM channel n shadow register SR1. */
    } B;
  } CH1_SR1;

  union {                              /* ATOM Channel n Compare Match 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CM0:24;                /* ATOM CCU0 compare register. */
    } B;
  } CH1_CM0;

  union {                              /* ATOM Channel n Compare Match 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CM1:24;                /* ATOM CCU1 compare register. */
    } B;
  } CH1_CM1;

  union {                              /* ATOM Channel n Counter 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CN0:24;                /* ATOM CCU0 counter register. */
    } B;
  } CH1_CN0;

  union {                              /* ATOM Channel n Status Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :3;
      vuint32_t ACBO:5;                /* ATOM Internal status bits. */
      vuint32_t  :1;
      vuint32_t WRF:1;                 /* Write request of CPU failed for late update. */
      vuint32_t DV:1;                  /* Valid ARU Data stored in compare registers. */
      vuint32_t ACBI:5;                /* ATOM Mode control bits received through ARU. */
      vuint32_t  :15;
      vuint32_t OL:1;                  /* Actual output signal level of ATOM_CHn_OUT. */
    } B;
  } CH1_STAT;

  union {                              /* ATOM Channel n Interrupt Request Notification Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH1_IRQ_NOTIFY;

  union {                              /* ATOM Channel n Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t CCU1TC_IRQ_EN:1;       /* ATOM_CCU1TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* ATOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH1_IRQ_EN;

  union {                              /* ATOM Channel n Force Interrupt Request Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t TRG_CCU1TC:1;          /* Trigger ATOM_CCU1TC_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC:1;          /* Trigger ATOM_CCU0TC_IRQ interrupt by software. */
    } B;
  } CH1_IRQ_FORCINT;

  union {                              /* ATOM Channel n Interrupt Request Mode Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH1_IRQ_MODE;

  uint8_t ATOM_reserved2[80];
  union {                              /* ATOM Channel n Read Address Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :7;
      vuint32_t RDADDR1:9;             /* ARU Read address 1. */
      vuint32_t  :7;
      vuint32_t RDADDR0:9;             /* ARU Read address 0. */
    } B;
  } CH2_RDADDR;

  union {                              /* ATOM Channel n Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :4;
      vuint32_t ABM:1;                 /* ARU blocking mode. */
      vuint32_t OSM:1;                 /* One-shot mode. */
      vuint32_t SLA:1;                 /* Serve last ARU communication strategy */
      vuint32_t TRIGOUT:1;             /* NTrigger output selection (output signal TRIG_CHn) of module ATOM_CHn. */
      vuint32_t  :3;                   /* Reads as zero, should be written as zero. */
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :3;
      vuint32_t WR_REQ:1;              /* CPU Write request bit for late compare register update. */
      vuint32_t  :1;
      vuint32_t CLK_SRC_SR:3;          /* Actual CMU clock source (SOMS) / shadow register for CMU clock source (SOMP). */
      vuint32_t SL:1;                  /* Initial signal level after channel enable. */
      vuint32_t  :1;
      vuint32_t CMP_CTRL:1;            /* CCUn compare strategy select.. */
      vuint32_t ACB:5;                 /* ATOM Mode control bits. */
      vuint32_t ARU_EN:1;              /* ARU Input stream enable. */
      vuint32_t TB12_SEL:1;            /* Select time base value TBU_TS1 or TBU_TS2. */
      vuint32_t MODE:2;                /* ATOM channel mode select. */
    } B;
  } CH2_CTRL;

  union {                              /* ATOM Channel n Shadow 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t SR0:24;                /* ATOM channel n shadow register SR0. */
    } B;
  } CH2_SR0;

  union {                              /* ATOM Channel n Shadow 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t SR1:24;                /* ATOM channel n shadow register SR1. */
    } B;
  } CH2_SR1;

  union {                              /* ATOM Channel n Compare Match 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CM0:24;                /* ATOM CCU0 compare register. */
    } B;
  } CH2_CM0;

  union {                              /* ATOM Channel n Compare Match 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CM1:24;                /* ATOM CCU1 compare register. */
    } B;
  } CH2_CM1;

  union {                              /* ATOM Channel n Counter 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CN0:24;                /* ATOM CCU0 counter register. */
    } B;
  } CH2_CN0;

  union {                              /* ATOM Channel n Status Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :3;
      vuint32_t ACBO:5;                /* ATOM Internal status bits. */
      vuint32_t  :1;
      vuint32_t WRF:1;                 /* Write request of CPU failed for late update. */
      vuint32_t DV:1;                  /* Valid ARU Data stored in compare registers. */
      vuint32_t ACBI:5;                /* ATOM Mode control bits received through ARU. */
      vuint32_t  :15;
      vuint32_t OL:1;                  /* Actual output signal level of ATOM_CHn_OUT. */
    } B;
  } CH2_STAT;

  union {                              /* ATOM Channel n Interrupt Request Notification Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH2_IRQ_NOTIFY;

  union {                              /* ATOM Channel n Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t CCU1TC_IRQ_EN:1;       /* ATOM_CCU1TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* ATOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH2_IRQ_EN;

  union {                              /* ATOM Channel n Force Interrupt Request Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t TRG_CCU1TC:1;          /* Trigger ATOM_CCU1TC_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC:1;          /* Trigger ATOM_CCU0TC_IRQ interrupt by software. */
    } B;
  } CH2_IRQ_FORCINT;

  union {                              /* ATOM Channel n Interrupt Request Mode Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH2_IRQ_MODE;

  uint8_t ATOM_reserved3[80];
  union {                              /* ATOM Channel n Read Address Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :7;
      vuint32_t RDADDR1:9;             /* ARU Read address 1. */
      vuint32_t  :7;
      vuint32_t RDADDR0:9;             /* ARU Read address 0. */
    } B;
  } CH3_RDADDR;

  union {                              /* ATOM Channel n Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :4;
      vuint32_t ABM:1;                 /* ARU blocking mode. */
      vuint32_t OSM:1;                 /* One-shot mode. */
      vuint32_t SLA:1;                 /* Serve last ARU communication strategy */
      vuint32_t TRIGOUT:1;             /* NTrigger output selection (output signal TRIG_CHn) of module ATOM_CHn. */
      vuint32_t  :3;                   /* Reads as zero, should be written as zero. */
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :3;
      vuint32_t WR_REQ:1;              /* CPU Write request bit for late compare register update. */
      vuint32_t  :1;
      vuint32_t CLK_SRC_SR:3;          /* Actual CMU clock source (SOMS) / shadow register for CMU clock source (SOMP). */
      vuint32_t SL:1;                  /* Initial signal level after channel enable. */
      vuint32_t  :1;
      vuint32_t CMP_CTRL:1;            /* CCUn compare strategy select.. */
      vuint32_t ACB:5;                 /* ATOM Mode control bits. */
      vuint32_t ARU_EN:1;              /* ARU Input stream enable. */
      vuint32_t TB12_SEL:1;            /* Select time base value TBU_TS1 or TBU_TS2. */
      vuint32_t MODE:2;                /* ATOM channel mode select. */
    } B;
  } CH3_CTRL;

  union {                              /* ATOM Channel n Shadow 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t SR0:24;                /* ATOM channel n shadow register SR0. */
    } B;
  } CH3_SR0;

  union {                              /* ATOM Channel n Shadow 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t SR1:24;                /* ATOM channel n shadow register SR1. */
    } B;
  } CH3_SR1;

  union {                              /* ATOM Channel n Compare Match 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CM0:24;                /* ATOM CCU0 compare register. */
    } B;
  } CH3_CM0;

  union {                              /* ATOM Channel n Compare Match 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CM1:24;                /* ATOM CCU1 compare register. */
    } B;
  } CH3_CM1;

  union {                              /* ATOM Channel n Counter 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CN0:24;                /* ATOM CCU0 counter register. */
    } B;
  } CH3_CN0;

  union {                              /* ATOM Channel n Status Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :3;
      vuint32_t ACBO:5;                /* ATOM Internal status bits. */
      vuint32_t  :1;
      vuint32_t WRF:1;                 /* Write request of CPU failed for late update. */
      vuint32_t DV:1;                  /* Valid ARU Data stored in compare registers. */
      vuint32_t ACBI:5;                /* ATOM Mode control bits received through ARU. */
      vuint32_t  :15;
      vuint32_t OL:1;                  /* Actual output signal level of ATOM_CHn_OUT. */
    } B;
  } CH3_STAT;

  union {                              /* ATOM Channel n Interrupt Request Notification Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH3_IRQ_NOTIFY;

  union {                              /* ATOM Channel n Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t CCU1TC_IRQ_EN:1;       /* ATOM_CCU1TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* ATOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH3_IRQ_EN;

  union {                              /* ATOM Channel n Force Interrupt Request Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t TRG_CCU1TC:1;          /* Trigger ATOM_CCU1TC_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC:1;          /* Trigger ATOM_CCU0TC_IRQ interrupt by software. */
    } B;
  } CH3_IRQ_FORCINT;

  union {                              /* ATOM Channel n Interrupt Request Mode Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH3_IRQ_MODE;

  uint8_t ATOM_reserved4[80];
  union {                              /* ATOM Channel n Read Address Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :7;
      vuint32_t RDADDR1:9;             /* ARU Read address 1. */
      vuint32_t  :7;
      vuint32_t RDADDR0:9;             /* ARU Read address 0. */
    } B;
  } CH4_RDADDR;

  union {                              /* ATOM Channel n Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :4;
      vuint32_t ABM:1;                 /* ARU blocking mode. */
      vuint32_t OSM:1;                 /* One-shot mode. */
      vuint32_t SLA:1;                 /* Serve last ARU communication strategy */
      vuint32_t TRIGOUT:1;             /* NTrigger output selection (output signal TRIG_CHn) of module ATOM_CHn. */
      vuint32_t  :3;                   /* Reads as zero, should be written as zero. */
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :3;
      vuint32_t WR_REQ:1;              /* CPU Write request bit for late compare register update. */
      vuint32_t  :1;
      vuint32_t CLK_SRC_SR:3;          /* Actual CMU clock source (SOMS) / shadow register for CMU clock source (SOMP). */
      vuint32_t SL:1;                  /* Initial signal level after channel enable. */
      vuint32_t  :1;
      vuint32_t CMP_CTRL:1;            /* CCUn compare strategy select.. */
      vuint32_t ACB:5;                 /* ATOM Mode control bits. */
      vuint32_t ARU_EN:1;              /* ARU Input stream enable. */
      vuint32_t TB12_SEL:1;            /* Select time base value TBU_TS1 or TBU_TS2. */
      vuint32_t MODE:2;                /* ATOM channel mode select. */
    } B;
  } CH4_CTRL;

  union {                              /* ATOM Channel n Shadow 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t SR0:24;                /* ATOM channel n shadow register SR0. */
    } B;
  } CH4_SR0;

  union {                              /* ATOM Channel n Shadow 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t SR1:24;                /* ATOM channel n shadow register SR1. */
    } B;
  } CH4_SR1;

  union {                              /* ATOM Channel n Compare Match 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CM0:24;                /* ATOM CCU0 compare register. */
    } B;
  } CH4_CM0;

  union {                              /* ATOM Channel n Compare Match 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CM1:24;                /* ATOM CCU1 compare register. */
    } B;
  } CH4_CM1;

  union {                              /* ATOM Channel n Counter 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CN0:24;                /* ATOM CCU0 counter register. */
    } B;
  } CH4_CN0;

  union {                              /* ATOM Channel n Status Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :3;
      vuint32_t ACBO:5;                /* ATOM Internal status bits. */
      vuint32_t  :1;
      vuint32_t WRF:1;                 /* Write request of CPU failed for late update. */
      vuint32_t DV:1;                  /* Valid ARU Data stored in compare registers. */
      vuint32_t ACBI:5;                /* ATOM Mode control bits received through ARU. */
      vuint32_t  :15;
      vuint32_t OL:1;                  /* Actual output signal level of ATOM_CHn_OUT. */
    } B;
  } CH4_STAT;

  union {                              /* ATOM Channel n Interrupt Request Notification Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH4_IRQ_NOTIFY;

  union {                              /* ATOM Channel n Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t CCU1TC_IRQ_EN:1;       /* ATOM_CCU1TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* ATOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH4_IRQ_EN;

  union {                              /* ATOM Channel n Force Interrupt Request Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t TRG_CCU1TC:1;          /* Trigger ATOM_CCU1TC_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC:1;          /* Trigger ATOM_CCU0TC_IRQ interrupt by software. */
    } B;
  } CH4_IRQ_FORCINT;

  union {                              /* ATOM Channel n Interrupt Request Mode Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH4_IRQ_MODE;

  uint8_t ATOM_reserved5[80];
  union {                              /* ATOM Channel n Read Address Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :7;
      vuint32_t RDADDR1:9;             /* ARU Read address 1. */
      vuint32_t  :7;
      vuint32_t RDADDR0:9;             /* ARU Read address 0. */
    } B;
  } CH5_RDADDR;

  union {                              /* ATOM Channel n Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :4;
      vuint32_t ABM:1;                 /* ARU blocking mode. */
      vuint32_t OSM:1;                 /* One-shot mode. */
      vuint32_t SLA:1;                 /* Serve last ARU communication strategy */
      vuint32_t TRIGOUT:1;             /* NTrigger output selection (output signal TRIG_CHn) of module ATOM_CHn. */
      vuint32_t  :3;                   /* Reads as zero, should be written as zero. */
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :3;
      vuint32_t WR_REQ:1;              /* CPU Write request bit for late compare register update. */
      vuint32_t  :1;
      vuint32_t CLK_SRC_SR:3;          /* Actual CMU clock source (SOMS) / shadow register for CMU clock source (SOMP). */
      vuint32_t SL:1;                  /* Initial signal level after channel enable. */
      vuint32_t  :1;
      vuint32_t CMP_CTRL:1;            /* CCUn compare strategy select.. */
      vuint32_t ACB:5;                 /* ATOM Mode control bits. */
      vuint32_t ARU_EN:1;              /* ARU Input stream enable. */
      vuint32_t TB12_SEL:1;            /* Select time base value TBU_TS1 or TBU_TS2. */
      vuint32_t MODE:2;                /* ATOM channel mode select. */
    } B;
  } CH5_CTRL;

  union {                              /* ATOM Channel n Shadow 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t SR0:24;                /* ATOM channel n shadow register SR0. */
    } B;
  } CH5_SR0;

  union {                              /* ATOM Channel n Shadow 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t SR1:24;                /* ATOM channel n shadow register SR1. */
    } B;
  } CH5_SR1;

  union {                              /* ATOM Channel n Compare Match 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CM0:24;                /* ATOM CCU0 compare register. */
    } B;
  } CH5_CM0;

  union {                              /* ATOM Channel n Compare Match 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CM1:24;                /* ATOM CCU1 compare register. */
    } B;
  } CH5_CM1;

  union {                              /* ATOM Channel n Counter 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CN0:24;                /* ATOM CCU0 counter register. */
    } B;
  } CH5_CN0;

  union {                              /* ATOM Channel n Status Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :3;
      vuint32_t ACBO:5;                /* ATOM Internal status bits. */
      vuint32_t  :1;
      vuint32_t WRF:1;                 /* Write request of CPU failed for late update. */
      vuint32_t DV:1;                  /* Valid ARU Data stored in compare registers. */
      vuint32_t ACBI:5;                /* ATOM Mode control bits received through ARU. */
      vuint32_t  :15;
      vuint32_t OL:1;                  /* Actual output signal level of ATOM_CHn_OUT. */
    } B;
  } CH5_STAT;

  union {                              /* ATOM Channel n Interrupt Request Notification Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH5_IRQ_NOTIFY;

  union {                              /* ATOM Channel n Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t CCU1TC_IRQ_EN:1;       /* ATOM_CCU1TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* ATOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH5_IRQ_EN;

  union {                              /* ATOM Channel n Force Interrupt Request Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t TRG_CCU1TC:1;          /* Trigger ATOM_CCU1TC_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC:1;          /* Trigger ATOM_CCU0TC_IRQ interrupt by software. */
    } B;
  } CH5_IRQ_FORCINT;

  union {                              /* ATOM Channel n Interrupt Request Mode Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH5_IRQ_MODE;

  uint8_t ATOM_reserved6[80];
  union {                              /* ATOM Channel n Read Address Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :7;
      vuint32_t RDADDR1:9;             /* ARU Read address 1. */
      vuint32_t  :7;
      vuint32_t RDADDR0:9;             /* ARU Read address 0. */
    } B;
  } CH6_RDADDR;

  union {                              /* ATOM Channel n Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :4;
      vuint32_t ABM:1;                 /* ARU blocking mode. */
      vuint32_t OSM:1;                 /* One-shot mode. */
      vuint32_t SLA:1;                 /* Serve last ARU communication strategy */
      vuint32_t TRIGOUT:1;             /* NTrigger output selection (output signal TRIG_CHn) of module ATOM_CHn. */
      vuint32_t  :3;                   /* Reads as zero, should be written as zero. */
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :3;
      vuint32_t WR_REQ:1;              /* CPU Write request bit for late compare register update. */
      vuint32_t  :1;
      vuint32_t CLK_SRC_SR:3;          /* Actual CMU clock source (SOMS) / shadow register for CMU clock source (SOMP). */
      vuint32_t SL:1;                  /* Initial signal level after channel enable. */
      vuint32_t  :1;
      vuint32_t CMP_CTRL:1;            /* CCUn compare strategy select.. */
      vuint32_t ACB:5;                 /* ATOM Mode control bits. */
      vuint32_t ARU_EN:1;              /* ARU Input stream enable. */
      vuint32_t TB12_SEL:1;            /* Select time base value TBU_TS1 or TBU_TS2. */
      vuint32_t MODE:2;                /* ATOM channel mode select. */
    } B;
  } CH6_CTRL;

  union {                              /* ATOM Channel n Shadow 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t SR0:24;                /* ATOM channel n shadow register SR0. */
    } B;
  } CH6_SR0;

  union {                              /* ATOM Channel n Shadow 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t SR1:24;                /* ATOM channel n shadow register SR1. */
    } B;
  } CH6_SR1;

  union {                              /* ATOM Channel n Compare Match 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CM0:24;                /* ATOM CCU0 compare register. */
    } B;
  } CH6_CM0;

  union {                              /* ATOM Channel n Compare Match 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CM1:24;                /* ATOM CCU1 compare register. */
    } B;
  } CH6_CM1;

  union {                              /* ATOM Channel n Counter 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CN0:24;                /* ATOM CCU0 counter register. */
    } B;
  } CH6_CN0;

  union {                              /* ATOM Channel n Status Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :3;
      vuint32_t ACBO:5;                /* ATOM Internal status bits. */
      vuint32_t  :1;
      vuint32_t WRF:1;                 /* Write request of CPU failed for late update. */
      vuint32_t DV:1;                  /* Valid ARU Data stored in compare registers. */
      vuint32_t ACBI:5;                /* ATOM Mode control bits received through ARU. */
      vuint32_t  :15;
      vuint32_t OL:1;                  /* Actual output signal level of ATOM_CHn_OUT. */
    } B;
  } CH6_STAT;

  union {                              /* ATOM Channel n Interrupt Request Notification Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH6_IRQ_NOTIFY;

  union {                              /* ATOM Channel n Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t CCU1TC_IRQ_EN:1;       /* ATOM_CCU1TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* ATOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH6_IRQ_EN;

  union {                              /* ATOM Channel n Force Interrupt Request Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t TRG_CCU1TC:1;          /* Trigger ATOM_CCU1TC_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC:1;          /* Trigger ATOM_CCU0TC_IRQ interrupt by software. */
    } B;
  } CH6_IRQ_FORCINT;

  union {                              /* ATOM Channel n Interrupt Request Mode Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH6_IRQ_MODE;

  uint8_t ATOM_reserved7[80];
  union {                              /* ATOM Channel n Read Address Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :7;
      vuint32_t RDADDR1:9;             /* ARU Read address 1. */
      vuint32_t  :7;
      vuint32_t RDADDR0:9;             /* ARU Read address 0. */
    } B;
  } CH7_RDADDR;

  union {                              /* ATOM Channel n Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :4;
      vuint32_t ABM:1;                 /* ARU blocking mode. */
      vuint32_t OSM:1;                 /* One-shot mode. */
      vuint32_t SLA:1;                 /* Serve last ARU communication strategy */
      vuint32_t TRIGOUT:1;             /* NTrigger output selection (output signal TRIG_CHn) of module ATOM_CHn. */
      vuint32_t  :3;                   /* Reads as zero, should be written as zero. */
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :3;
      vuint32_t WR_REQ:1;              /* CPU Write request bit for late compare register update. */
      vuint32_t  :1;
      vuint32_t CLK_SRC_SR:3;          /* Actual CMU clock source (SOMS) / shadow register for CMU clock source (SOMP). */
      vuint32_t SL:1;                  /* Initial signal level after channel enable. */
      vuint32_t  :1;
      vuint32_t CMP_CTRL:1;            /* CCUn compare strategy select.. */
      vuint32_t ACB:5;                 /* ATOM Mode control bits. */
      vuint32_t ARU_EN:1;              /* ARU Input stream enable. */
      vuint32_t TB12_SEL:1;            /* Select time base value TBU_TS1 or TBU_TS2. */
      vuint32_t MODE:2;                /* ATOM channel mode select. */
    } B;
  } CH7_CTRL;

  union {                              /* ATOM Channel n Shadow 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t SR0:24;                /* ATOM channel n shadow register SR0. */
    } B;
  } CH7_SR0;

  union {                              /* ATOM Channel n Shadow 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t SR1:24;                /* ATOM channel n shadow register SR1. */
    } B;
  } CH7_SR1;

  union {                              /* ATOM Channel n Compare Match 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CM0:24;                /* ATOM CCU0 compare register. */
    } B;
  } CH7_CM0;

  union {                              /* ATOM Channel n Compare Match 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CM1:24;                /* ATOM CCU1 compare register. */
    } B;
  } CH7_CM1;

  union {                              /* ATOM Channel n Counter 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CN0:24;                /* ATOM CCU0 counter register. */
    } B;
  } CH7_CN0;

  union {                              /* ATOM Channel n Status Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :3;
      vuint32_t ACBO:5;                /* ATOM Internal status bits. */
      vuint32_t  :1;
      vuint32_t WRF:1;                 /* Write request of CPU failed for late update. */
      vuint32_t DV:1;                  /* Valid ARU Data stored in compare registers. */
      vuint32_t ACBI:5;                /* ATOM Mode control bits received through ARU. */
      vuint32_t  :15;
      vuint32_t OL:1;                  /* Actual output signal level of ATOM_CHn_OUT. */
    } B;
  } CH7_STAT;

  union {                              /* ATOM Channel n Interrupt Request Notification Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH7_IRQ_NOTIFY;

  union {                              /* ATOM Channel n Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t CCU1TC_IRQ_EN:1;       /* ATOM_CCU1TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* ATOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH7_IRQ_EN;

  union {                              /* ATOM Channel n Force Interrupt Request Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t TRG_CCU1TC:1;          /* Trigger ATOM_CCU1TC_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC:1;          /* Trigger ATOM_CCU0TC_IRQ interrupt by software. */
    } B;
  } CH7_IRQ_FORCINT;

  union {                              /* ATOM Channel n Interrupt Request Mode Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH7_IRQ_MODE;
};

typedef volatile struct GTM_ATOM_tag GTM_ATOM_TagType;

/* ============================================================================
   =============================== Module: GTM_BRC ============================
   ============================================================================ */

struct GTM_BRC_tag {
  struct {
    union {                            /* BRC Source n Address Register, n[0:11] */
      vuint32_t R;
      struct {
        vuint32_t  :19;
        vuint32_t BRC_MODE:1;          /* BRC Operation mode select. */
        vuint32_t  :3;
        vuint32_t ADDR:9;              /* Source ARU address. */
      } B;
    } ADDR;
    union {                            /* BRC Source n to Destination Register, n[0:11] */
      vuint32_t R;
      struct {
        vuint32_t  :9;
        vuint32_t EN_TRASHBIN:1;       /* Control trash bin functionality. */
        vuint32_t EN_DEST21:1;         /* See EN_DEST0. */
        vuint32_t EN_DEST20:1;         /* See EN_DEST0. */
        vuint32_t EN_DEST19:1;         /* See EN_DEST0. */
        vuint32_t EN_DEST18:1;         /* See EN_DEST0. */
        vuint32_t EN_DEST17:1;         /* See EN_DEST0. */
        vuint32_t EN_DEST16:1;         /* See EN_DEST0. */
        vuint32_t EN_DEST15:1;         /* See EN_DEST0. */
        vuint32_t EN_DEST14:1;         /* See EN_DEST0. */
        vuint32_t EN_DEST13:1;         /* See EN_DEST0. */
        vuint32_t EN_DEST12:1;         /* See EN_DEST0. */
        vuint32_t EN_DEST11:1;         /* See EN_DEST0. */
        vuint32_t EN_DEST10:1;         /* See EN_DEST0. */
        vuint32_t EN_DEST9:1;          /* See EN_DEST0. */
        vuint32_t EN_DEST8:1;          /* See EN_DEST0. */
        vuint32_t EN_DEST7:1;          /* See EN_DEST0. */
        vuint32_t EN_DEST6:1;          /* See EN_DEST0. */
        vuint32_t EN_DEST5:1;          /* See EN_DEST0. */
        vuint32_t EN_DEST4:1;          /* See EN_DEST0. */
        vuint32_t EN_DEST3:1;          /* See EN_DEST0. */
        vuint32_t EN_DEST2:1;          /* See EN_DEST0. */
        vuint32_t EN_DEST1:1;          /* See EN_DEST0. */
        vuint32_t EN_DEST0:1;          /* Enable BRC destination address. */
      } B;
    } DEST;
  } SRC[12];

  union {                              /* BRC Interrupt Request Notification Register */
    vuint32_t R;
    struct {
      vuint32_t  :19;
      vuint32_t DID0:1;                /* Data inconsistency occurred in MTM mode. */
      vuint32_t DID1:1;                /* Data inconsistency occurred in MTM mode. */
      vuint32_t DID2:1;                /* Data inconsistency occurred in MTM mode. */
      vuint32_t DID3:1;                /* Data inconsistency occurred in MTM mode. */
      vuint32_t DID4:1;                /* Data inconsistency occurred in MTM mode. */
      vuint32_t DID5:1;                /* Data inconsistency occurred in MTM mode. */
      vuint32_t DID6:1;                /* Data inconsistency occurred in MTM mode. */
      vuint32_t DID7:1;                /* Data inconsistency occurred in MTM mode. */
      vuint32_t DID8:1;                /* Data inconsistency occurred in MTM mode. */
      vuint32_t DID9:1;                /* Data inconsistency occurred in MTM mode. */
      vuint32_t DID10:1;               /* Data inconsistency occurred in MTM mode. */
      vuint32_t DID11:1;               /* Data inconsistency occurred in MTM mode. */
      vuint32_t DEST_ERR:1;            /* Configuration error interrupt for BRC submodule. */
    } B;
  } IRQ_NOTIFY;

  union {                              /* BRC Interrupt Request Enable Register */
    vuint32_t R;
    struct {
      vuint32_t  :19;
      vuint32_t DID_IRQ_EN0:1;         /* BRC_DID_IRQ interrupt enable. */
      vuint32_t DID_IRQ_EN1:1;         /* BRC_DID_IRQ interrupt enable. */
      vuint32_t DID_IRQ_EN2:1;         /* BRC_DID_IRQ interrupt enable. */
      vuint32_t DID_IRQ_EN3:1;         /* BRC_DID_IRQ interrupt enable. */
      vuint32_t DID_IRQ_EN4:1;         /* BRC_DID_IRQ interrupt enable. */
      vuint32_t DID_IRQ_EN5:1;         /* BRC_DID_IRQ interrupt enable. */
      vuint32_t DID_IRQ_EN6:1;         /* BRC_DID_IRQ interrupt enable. */
      vuint32_t DID_IRQ_EN7:1;         /* BRC_DID_IRQ interrupt enable. */
      vuint32_t DID_IRQ_EN8:1;         /* BRC_DID_IRQ interrupt enable. */
      vuint32_t DID_IRQ_EN9:1;         /* BRC_DID_IRQ interrupt enable. */
      vuint32_t DID_IRQ_EN10:1;        /* BRC_DID_IRQ interrupt enable. */
      vuint32_t DID_IRQ_EN11:1;        /* BRC_DID_IRQ interrupt enable. */
      vuint32_t DEST_ERR_EN:1;         /* BRC_DEST_ERR_IRQ interrupt enable. */
    } B;
  } IRQ_EN;

  union {                              /* BRC Force Interrupt Request Register */
    vuint32_t R;
    struct {
      vuint32_t  :19;
      vuint32_t TRG_DID0:1;            /* Trigger data inconsistency error interrupt. */
      vuint32_t TRG_DID1:1;            /* Trigger data inconsistency error interrupt. */
      vuint32_t TRG_DID2:1;            /* Trigger data inconsistency error interrupt. */
      vuint32_t TRG_DID3:1;            /* Trigger data inconsistency error interrupt. */
      vuint32_t TRG_DID4:1;            /* Trigger data inconsistency error interrupt. */
      vuint32_t TRG_DID5:1;            /* Trigger data inconsistency error interrupt. */
      vuint32_t TRG_DID6:1;            /* Trigger data inconsistency error interrupt. */
      vuint32_t TRG_DID7:1;            /* Trigger data inconsistency error interrupt. */
      vuint32_t TRG_DID8:1;            /* Trigger data inconsistency error interrupt. */
      vuint32_t TRG_DID9:1;            /* Trigger data inconsistency error interrupt. */
      vuint32_t TRG_DID10:1;           /* Trigger data inconsistency error interrupt. */
      vuint32_t TRG_DID11:1;           /* Trigger data inconsistency error interrupt. */
      vuint32_t TRG_DEST_ERR:1;        /* Trigger destination error interrupt. */
    } B;
  } IRQ_FORCINT;

  union {                              /* BRC Interrupt Request Mode Register */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode select */
    } B;
  } IRQ_MODE;

  union {                              /* BRC Software Reset Register */
    vuint32_t R;
    struct {
      vuint32_t  :31;
      vuint32_t RST:1;                 /* Software reset. */
    } B;
  } RST;

  union {                              /* BRC Error Interrupt Request Enable Register */
    vuint32_t R;
    struct {
      vuint32_t  :19;
      vuint32_t DID_EIRQ_EN0:1;        /* BRC_DID_EIRQ error interrupt enable. */
      vuint32_t DID_EIRQ_EN1:1;        /* BRC_DID_EIRQ error interrupt enable. */
      vuint32_t DID_EIRQ_EN2:1;        /* BRC_DID_EIRQ error interrupt enable. */
      vuint32_t DID_EIRQ_EN3:1;        /* BRC_DID_EIRQ error interrupt enable. */
      vuint32_t DID_EIRQ_EN4:1;        /* BRC_DID_EIRQ error interrupt enable. */
      vuint32_t DID_EIRQ_EN5:1;        /* BRC_DID_EIRQ error interrupt enable. */
      vuint32_t DID_EIRQ_EN6:1;        /* BRC_DID_EIRQ error interrupt enable. */
      vuint32_t DID_EIRQ_EN7:1;        /* BRC_DID_EIRQ error interrupt enable. */
      vuint32_t DID_EIRQ_EN8:1;        /* BRC_DID_EIRQ error interrupt enable. */
      vuint32_t DID_EIRQ_EN9:1;        /* BRC_DID_EIRQ error interrupt enable. */
      vuint32_t DID_EIRQ_EN10:1;       /* BRC_DID_EIRQ error interrupt enable. */
      vuint32_t DID_EIRQ_EN11:1;       /* BRC_DID_EIRQ error interrupt enable. */
      vuint32_t DEST_ERR_EIRQ_EN:1;    /* BRC_DEST_ERR_EIRQ error interrupt enable. */
    } B;
  } EIRQ_EN;
};


/* ============================================================================
   =============================== Module: GTM_CMP ============================
   ============================================================================ */

struct GTM_CMP_tag {
  union {                              /* Compare Enable Register */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t TBWC11_EN:1;           /* See TBWC0_EN. */
      vuint32_t TBWC10_EN:1;           /* See TBWC0_EN. */
      vuint32_t TBWC9_EN:1;            /* See TBWC0_EN. */
      vuint32_t TBWC8_EN:1;            /* See TBWC0_EN. */
      vuint32_t TBWC7_EN:1;            /* See TBWC0_EN. */
      vuint32_t TBWC6_EN:1;            /* See TBWC0_EN. */
      vuint32_t TBWC5_EN:1;            /* See TBWC0_EN. */
      vuint32_t TBWC4_EN:1;            /* See TBWC0_EN. */
      vuint32_t TBWC3_EN:1;            /* See TBWC0_EN. */
      vuint32_t TBWC2_EN:1;            /* See TBWC0_EN. */
      vuint32_t TBWC1_EN:1;            /* See TBWC0_EN. */
      vuint32_t TBWC0_EN:1;            /* Enable corresponding comparator in TBWC. */
      vuint32_t ABWC11_EN:1;           /* See ABWC0_EN. */
      vuint32_t ABWC10_EN:1;           /* See ABWC0_EN. */
      vuint32_t ABWC9_EN:1;            /* See ABWC0_EN. */
      vuint32_t ABWC8_EN:1;            /* See ABWC0_EN. */
      vuint32_t ABWC7_EN:1;            /* See ABWC0_EN. */
      vuint32_t ABWC6_EN:1;            /* See ABWC0_EN. */
      vuint32_t ABWC5_EN:1;            /* See ABWC0_EN. */
      vuint32_t ABWC4_EN:1;            /* See ABWC0_EN. */
      vuint32_t ABWC3_EN:1;            /* See ABWC0_EN. */
      vuint32_t ABWC2_EN:1;            /* See ABWC0_EN. */
      vuint32_t ABWC1_EN:1;            /* See ABWC0_EN. */
      vuint32_t ABWC0_EN:1;            /* Enable corresponding comparator in ABWC. */
    } B;
  } EN;

  union {                              /* Compare Interrupt Request Notification Register */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t TBWC11:1;              /* See TBWC0. */
      vuint32_t TBWC10:1;              /* See TBWC0. */
      vuint32_t TBWC9:1;               /* See TBWC0. */
      vuint32_t TBWC8:1;               /* See TBWC0. */
      vuint32_t TBCW7:1;               /* See TBWC0. */
      vuint32_t TBWC6:1;               /* See TBWC0. */
      vuint32_t TBWC5:1;               /* See TBWC0. */
      vuint32_t TBWC4:1;               /* See TBWC0. */
      vuint32_t TBWC3:1;               /* See TBWC0. */
      vuint32_t TBWC2:1;               /* See TBWC0. */
      vuint32_t TBWC1:1;               /* See TBWC0. */
      vuint32_t TBWC0:1;               /* TOM sub modules outputs bitwise comparator 0 error indication. */
      vuint32_t ABWC11:1;              /* See ABWC0. */
      vuint32_t ABWC10:1;              /* See ABWC0. */
      vuint32_t ABWC9:1;               /* See ABWC0. */
      vuint32_t ABWC8:1;               /* See ABWC0. */
      vuint32_t ABWC7:1;               /* See ABWC0. */
      vuint32_t ABWC6:1;               /* See ABWC0. */
      vuint32_t ABWC5:1;               /* See ABWC0. */
      vuint32_t ABWC4:1;               /* See ABWC0. */
      vuint32_t ABWC3:1;               /* See ABWC0. */
      vuint32_t ABWC2:1;               /* See ABWC0. */
      vuint32_t ABWC1:1;               /* See ABWC0. */
      vuint32_t ABWC0:1;               /* ATOM sub modules outputs bitwise comparator error indication. */
    } B;
  } IRQ_NOTIFY;

  union {                              /* Compare Interrupt Request Enable Register */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t TBWC11_EN_IRQ:1;       /* See TBWC0_EN_IRQ. */
      vuint32_t TBWC10_EN_IRQ:1;       /* See TBWC0_EN_IRQ. */
      vuint32_t TBWC9_EN_IRQ:1;        /* See TBWC0_EN_IRQ. */
      vuint32_t TBWC8_EN_IRQ:1;        /* See TBWC0_EN_IRQ. */
      vuint32_t TBWC7_EN_IRQ:1;        /* See TBWC0_EN_IRQ. */
      vuint32_t TBWC6_EN_IRQ:1;        /* See TBWC0_EN_IRQ. */
      vuint32_t TBWC5_EN_IRQ:1;        /* See TBWC0_EN_IRQ. */
      vuint32_t TBWC4_EN_IRQ:1;        /* See TBWC0_EN_IRQ. */
      vuint32_t TBWC3_EN_IRQ:1;        /* See TBWC0_EN_IRQ. */
      vuint32_t TBWC2_EN_IRQ:1;        /* See TBWC0_EN_IRQ. */
      vuint32_t TBWC1_EN_IRQ:1;        /* See TBWC0_EN_IRQ. */
      vuint32_t TBWC0_EN_IRQ:1;        /* Enable corresponding TBWC interrupt source for CMP_IRQ line. */
      vuint32_t ABWC11_EN_IRQ:1;       /* See ABWC0_EN_IRQ. */
      vuint32_t ABWC10_EN_IRQ:1;       /* See ABWC0_EN_IRQ. */
      vuint32_t ABWC9_EN_IRQ:1;        /* See ABWC0_EN_IRQ. */
      vuint32_t ABWC8_EN_IRQ:1;        /* See ABWC0_EN_IRQ. */
      vuint32_t ABWC7_EN_IRQ:1;        /* See ABWC0_EN_IRQ. */
      vuint32_t ABWC6_EN_IRQ:1;        /* See ABWC0_EN_IRQ. */
      vuint32_t ABWC5_EN_IRQ:1;        /* See ABWC0_EN_IRQ. */
      vuint32_t ABWC4_EN_IRQ:1;        /* See ABWC0_EN_IRQ. */
      vuint32_t ABWC3_EN_IRQ:1;        /* See ABWC0_EN_IRQ. */
      vuint32_t ABWC2_EN_IRQ:1;        /* See ABWC0_EN_IRQ. */
      vuint32_t ABWC1_EN_IRQ:1;        /* See ABWC0_EN_IRQ. */
      vuint32_t ABWC0_EN_IRQ:1;        /* Enable corresponding ABWC interrupt source for CMP_IRQ line. */
    } B;
  } IRQ_EN;

  union {                              /* Compare Force Interrupt Request Register */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t TRG_TBWC11:1;          /* See TRG_TBWC0. */
      vuint32_t TRG_TBWC10:1;          /* See TRG_TBWC0. */
      vuint32_t TRG_TBWC9:1;           /* See TRG_TBWC0. */
      vuint32_t TRG_TBWC8:1;           /* See TRG_TBWC0. */
      vuint32_t TRG_TBWC7:1;           /* See TRG_TBWC0. */
      vuint32_t TRG_TBWC6:1;           /* See TRG_TBWC0. */
      vuint32_t TRG_TBWC5:1;           /* See TRG_TBWC0. */
      vuint32_t TRG_TBWC4:1;           /* See TRG_TBWC0. */
      vuint32_t TRG_TBWC3:1;           /* See TRG_TBWC0. */
      vuint32_t TRG_TBWC2:1;           /* See TRG_TBWC0. */
      vuint32_t TRG_TBWC1:1;           /* See TRG_TBWC0. */
      vuint32_t TRG_TBWC0:1;           /* Trigger corresponding TBWC bit in CMP_IRQ_NOTIFY register by software. */
      vuint32_t TRG_ABWC11:1;          /* See TRG_ABWC0. */
      vuint32_t TRG_ABWC10:1;          /* See TRG_ABWC0. */
      vuint32_t TRG_ABWC9:1;           /* See TRG_ABWC0. */
      vuint32_t TRG_ABWC8:1;           /* See TRG_ABWC0. */
      vuint32_t TRG_ABWC7:1;           /* See TRG_ABWC0. */
      vuint32_t TRG_ABWC6:1;           /* See TRG_ABWC0. */
      vuint32_t TRG_ABWC5:1;           /* See TRG_ABWC0. */
      vuint32_t TRG_ABWC4:1;           /* See TRG_ABWC0. */
      vuint32_t TRG_ABWC3:1;           /* See TRG_ABWC0. */
      vuint32_t TRG_ABWC2:1;           /* See TRG_ABWC0. */
      vuint32_t TRG_ABWC1:1;           /* See TRG_ABWC0. */
      vuint32_t TRG_ABWC0:1;           /* Trigger corresponding ABWC bit in CMP_IRQ_NOTIFY register by software. */
    } B;
  } IRQ_FORCINT;

  union {                              /* Compare Interrupt Request Mode Register */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } IRQ_MODE;

  union {                              /* Compare Error Interrupt Request Enable register */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t TBWC11_EN_EIRQ:1;      /* See TBWC0_EN_EIRQ. */
      vuint32_t TBWC10_EN_EIRQ:1;      /* See TBWC0_EN_EIRQ. */
      vuint32_t TBWC9_EN_EIRQ:1;       /* See TBWC0_EN_EIRQ. */
      vuint32_t TBWC8_EN_EIRQ:1;       /* See TBWC0_EN_EIRQ. */
      vuint32_t TBWC7_EN_EIRQ:1;       /* See TBWC0_EN_EIRQ. */
      vuint32_t TBWC6_EN_EIRQ:1;       /* See TBWC0_EN_EIRQ. */
      vuint32_t TBWC5_EN_EIRQ:1;       /* See TBWC0_EN_EIRQ. */
      vuint32_t TBWC4_EN_EIRQ:1;       /* See TBWC0_EN_EIRQ. */
      vuint32_t TBWC3_EN_EIRQ:1;       /* See TBWC0_EN_EIRQ. */
      vuint32_t TBWC2_EN_EIRQ:1;       /* See TBWC0_EN_EIRQ. */
      vuint32_t TBWC1_EN_EIRQ:1;       /* See TBWC0_EN_EIRQ. */
      vuint32_t TBWC0_EN_EIRQ:1;       /* Enable comparator 0-11 in TBWC. */
      vuint32_t ABWC11_EN_EIRQ:1;      /* ABWC0_EN_EIRQ */
      vuint32_t ABWC10_EN_EIRQ:1;      /* ABWC0_EN_EIRQ */
      vuint32_t ABWC9_EN_EIRQ:1;       /* ABWC0_EN_EIRQ */
      vuint32_t ABWC8_EN_EIRQ:1;       /* ABWC0_EN_EIRQ */
      vuint32_t ABWC7_EN_EIRQ:1;       /* ABWC0_EN_EIRQ */
      vuint32_t ABWC6_EN_EIRQ:1;       /* ABWC0_EN_EIRQ */
      vuint32_t ABWC5_EN_EIRQ:1;       /* ABWC0_EN_EIRQ */
      vuint32_t ABWC4_EN_EIRQ:1;       /* ABWC0_EN_EIRQ */
      vuint32_t ABWC3_EN_EIRQ:1;       /* ABWC0_EN_EIRQ */
      vuint32_t ABWC2_EN_EIRQ:1;       /* ABWC0_EN_EIRQ */
      vuint32_t ABWC1_EN_EIRQ:1;       /* ABWC0_EN_EIRQ */
      vuint32_t ABWC0_EN_EIRQ:1;       /* Enable comparator 0-11 in ABWC. */
    } B;
  } EIRQ_EN;
};


/* ============================================================================
   =============================== Module: GTM_CMU ============================
   ============================================================================ */

struct GTM_CMU_tag {
  union {                              /* CMU Clock Enable Register */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t EN_FXCLK:2;            /* Enable all CMU_FXCLK. */
      vuint32_t EN_ECLK2:2;            /* Enable ECLK 2 generation subunit. */
      vuint32_t EN_ECLK1:2;            /* Enable ECLK 1 generation subunit */
      vuint32_t EN_ECLK0:2;            /* Enable ECLK 0 generation subunit. */
      vuint32_t EN_CLK7:2;             /* Enable clock source 7. */
      vuint32_t EN_CLK6:2;             /* Enable clock source 6. */
      vuint32_t EN_CLK5:2;             /* Enable clock source 5. */
      vuint32_t EN_CLK4:2;             /* Enable clock source 4. */
      vuint32_t EN_CLK3:2;             /* Enable clock source 3 */
      vuint32_t EN_CLK2:2;             /* Enable clock source 2. */
      vuint32_t EN_CLK1:2;             /* Enable clock source 1 */
      vuint32_t EN_CLK0:2;             /* Enable clock source 0. */
    } B;
  } CLK_EN;

  union {                              /* Global Clock Control Numerator Register */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t GCLK_NUM:24;           /* Numerator for global clock divider. */
    } B;
  } GCLK_NUM;

  union {                              /* Global Clock Control Denominator Register */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t GCLK_DEN:24;           /* Denominator for global clock divider. */
    } B;
  } GCLK_DEN;

  union {                              /* Control for Clock Source n register */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CLK_CNT:24;            /* Clock count. */
    } B;
  } CLK_CTRL[6];

  union {                              /* Control for Clock Source 6 register */
    vuint32_t R;
    struct {
      vuint32_t  :7;
      vuint32_t CLK6_SEL:1;            /* Clock source selection for CMU_CLK6. */
      vuint32_t CLK_CNT:24;            /* Clock count. */
    } B;
  } CLK_6_CTRL;

  union {                              /* Control for Clock Source 7 register */
    vuint32_t R;
    struct {
      vuint32_t  :7;
      vuint32_t CLK7_SEL:1;            /* Clock source selection for CMU_CLK7. */
      vuint32_t CLK_CNT:24;            /* Clock count. */
    } B;
  } CLK_7_CTRL;

  struct {
    union {                            /* CMU External Clock n Numerator Register */
      vuint32_t R;
      struct {
        vuint32_t  :8;
        vuint32_t ECLK_NUM:24;         /* Numerator for external clock divider. */
      } B;
    } NUM;
    union {                            /* CMU External Clock n Denominator Register */
      vuint32_t R;
      struct {
        vuint32_t  :8;
        vuint32_t ECLK_DEN:24;         /* Denominator for external clock divider. */
      } B;
    } DEN;
  } ECLK[3];

  union {                              /* CMU FX Clock Control register */
    vuint32_t R;
    struct {
      vuint32_t  :28;
      vuint32_t FXCLK_SEL:4;           /* Input clock selection for EN_FXCLK line. */
    } B;
  } FXCLK_CTRL;
};


/* ============================================================================
   =============================== Module: GTM_DPLL ===========================
   ============================================================================ */

struct GTM_DPLL_tag {
  union {                              /* Control Register 0 */
    vuint32_t R;
    struct {
      vuint32_t RMO:1;                 /* Reference mode. */
      vuint32_t TEN:1;                 /* TRIGGER enable. */
      vuint32_t SEN:1;                 /* STATE enable. */
      vuint32_t IDT:1;                 /* Input delay TRIGGER. */
      vuint32_t IDS:1;                 /* Input delay STATE. */
      vuint32_t AMT:1;                 /* Adapt mode TRIGGER */
      vuint32_t AMS:1;                 /* Addapt mode STATE. */
      vuint32_t TNU:9;                 /* TRIGGER number. */
      vuint32_t SNU:5;                 /* STATE number. */
      vuint32_t IFP:1;                 /* Input filter position. */
      vuint32_t MLT:10;                /* Multiplier for TRIGGER. */
    } B;
  } CTRL_0;

  union {                              /* Control Register 1 */
    vuint32_t R;
    struct {
      vuint32_t TSL:2;                 /* TRIGGER slope select. */
      vuint32_t SSL:2;                 /* STATE slope select. */
      vuint32_t SMC:1;                 /* Synchronous Motor Control */
      vuint32_t TS0_HRT:1;             /* Time stamp high resolution TRIGGER */
      vuint32_t TS0_HRS:1;             /* Time stamp high resolution STATE. */
      vuint32_t SYSF:1;                /* SYN_NS for FULL_SCALE. */
      vuint32_t SWR:1;                 /* Software reset */
      vuint32_t LCD:1;                 /* Locking Condition Definition. */
      vuint32_t SYN_NT:6;              /* Synchronization number of TRIGGER. */
      vuint32_t SYN_NS:5;              /* Synchronization number of STATE. */
      vuint32_t PCM2:1;                /* Pulse Correction Mode. */
      vuint32_t DLM2:1;                /* Direct Load Mode. */
      vuint32_t SGE2:1;                /* SUB_INC2 generator enable. */
      vuint32_t PCM1:1;                /* Pulse Correction Mode. */
      vuint32_t DLM1:1;                /* Direct Load Mode. */
      vuint32_t SGE1:1;                /* SUB_INC1 generator enable. */
      vuint32_t PIT:1;                 /* Plausibility. */
      vuint32_t COA:1;                 /* Correction strategy in automatic end mode (DMO=0). */
      vuint32_t IDDS:1;                /* Input Direction Detection Strategy in the case of SMC=0. */
      vuint32_t DEN:1;                 /* DPLL enable. */
      vuint32_t DMO:1;                 /* DPLL mode select. */
    } B;
  } CTRL_1;

  union {                              /* Action Enable Register */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t WAD7:1;                /* Write control bit of Action_7. */
      vuint32_t WAD6:1;                /* Write control bit of Action_6. */
      vuint32_t WAD5:1;                /* Write control bit of Action_5. */
      vuint32_t WAD4:1;                /* Write control bit of Action_4. */
      vuint32_t WAD3:1;                /* Write control bit of Action_3. */
      vuint32_t WAD2:1;                /* Write control bit of Action_2. */
      vuint32_t WAD1:1;                /* Write control bit of Action_1. */
      vuint32_t WAD0:1;                /* Write control bit of Action_0. */
      vuint32_t AEN7:1;                /* ACTION_7 enable. */
      vuint32_t AEN6:1;                /* ACTION_6 enable. */
      vuint32_t AEN5:1;                /* ACTION_5 enable. */
      vuint32_t AEN4:1;                /* ACTION_4 enable. */
      vuint32_t AEN3:1;                /* ACTION_3 enable. */
      vuint32_t AEN2:1;                /* ACTION_2 enable. */
      vuint32_t AEN1:1;                /* ACTION_1 enable. */
      vuint32_t AEN0:1;                /* ACTION_0 enable. */
      vuint32_t  :8;                   /* Reserved. */
    } B;
  } CTRL_2;

  union {                              /* Action Enable Register */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t WAD15:1;               /* Write control bit of Action_15. */
      vuint32_t WAD14:1;               /* Write control bit of Action_14. */
      vuint32_t WAD13:1;               /* Write control bit of Action_13. */
      vuint32_t WAD12:1;               /* Write control bit of Action_12. */
      vuint32_t WAD11:1;               /* Write control bit of Action_11. */
      vuint32_t WAD10:1;               /* Write control bit of Action_10. */
      vuint32_t WAD9:1;                /* Write control bit of Action_9. */
      vuint32_t WAD8:1;                /* Write control bit of Action_8. */
      vuint32_t AEN15:1;               /* ACTION_15 enable. */
      vuint32_t AEN14:1;               /* ACTION_14 enable. */
      vuint32_t AEN13:1;               /* ACTION_13 enable. */
      vuint32_t AEN12:1;               /* ACTION_12 enable. */
      vuint32_t AEN11:1;               /* ACTION_11 enable. */
      vuint32_t AEN10:1;               /* ACTION_10 enable. */
      vuint32_t AEN9:1;                /* ACTION_9 enable. */
      vuint32_t AEN8:1;                /* ACTION_8 enable. */
      vuint32_t  :8;
    } B;
  } CTRL_3;

  union {                              /* Action Enable Register */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t WAD23:1;               /* Write control bit of Action_23. */
      vuint32_t WAD22:1;               /* Write control bit of Action_22. */
      vuint32_t WAD21:1;               /* Write control bit of Action_21. */
      vuint32_t WAD20:1;               /* Write control bit of Action_20. */
      vuint32_t WAD19:1;               /* Write control bit of Action_19. */
      vuint32_t WAD18:1;               /* Write control bit of Action_18. */
      vuint32_t WAD17:1;               /* Write control bit of Action_17. */
      vuint32_t WAD16:1;               /* Write control bit of Action_16. */
      vuint32_t AEN23:1;               /* ACTION_23 enable. */
      vuint32_t AEN22:1;               /* ACTION_22 enable. */
      vuint32_t AEN21:1;               /* ACTION_21 enable. */
      vuint32_t AEN20:1;               /* ACTION_20 enable. */
      vuint32_t AEN19:1;               /* ACTION_19 enable. */
      vuint32_t AEN18:1;               /* ACTION_18 enable. */
      vuint32_t AEN17:1;               /* ACTION_17 enable. */
      vuint32_t AEN16:1;               /* ACTION_16 enable. */
      vuint32_t  :8;
    } B;
  } CTRL_4;

  union {                              /* Action Enable Register */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t WAD31:1;               /* Write control bit of Action_31. */
      vuint32_t WAD30:1;               /* Write control bit of Action_30. */
      vuint32_t WAD29:1;               /* Write control bit of Action_29. */
      vuint32_t WAD28:1;               /* Write control bit of Action_28. */
      vuint32_t WAD27:1;               /* Write control bit of Action_27. */
      vuint32_t WAD26:1;               /* Write control bit of Action_26. */
      vuint32_t WAD25:1;               /* Write control bit of Action_25. */
      vuint32_t WAD24:1;               /* Write control bit of Action_24. */
      vuint32_t AEN31:1;               /* ACTION_31 enable. */
      vuint32_t AEN30:1;               /* ACTION_30 enable. */
      vuint32_t AEN29:1;               /* ACTION_29 enable. */
      vuint32_t AEN28:1;               /* ACTION_28 enable. */
      vuint32_t AEN27:1;               /* ACTION_27 enable. */
      vuint32_t AEN26:1;               /* ACTION_26 enable. */
      vuint32_t AEN25:1;               /* ACTION_25 enable. */
      vuint32_t AEN24:1;               /* ACTION_24 enable. */
      vuint32_t  :8;
    } B;
  } CTRL_5;

  union {                              /* Action Status Register including Shadow Register */
    vuint32_t R;
    struct {
      vuint32_t ACT_N:32;              /* New output data values concerning to action i provided. */
    } B;
  } ACT_STA;

  union {                              /* Offset and Switch Old/New Address Register */
    vuint32_t R;
    struct {
      vuint32_t  :22;
      vuint32_t OSS:2;                 /* Offset size of RAM region 2. */
      vuint32_t  :6;
      vuint32_t SWON_T:1;              /* Switch of new TRIGGER. */
      vuint32_t SWON_S:1;              /* Switch of new STATE. */
    } B;
  } OSW;

  union {                              /* Address Offset Register of RAM2 Regions */
    vuint32_t R;
    struct {
      vuint32_t AOSV_2D:8;             /* Address offset value of the RAM 2d region. */
      vuint32_t AOSV_2C:8;             /* Address offset value of the RAM 2c region. */
      vuint32_t AOSV_2B:8;             /* Address offset value of the RAM 2b region. */
      vuint32_t AOSV_2A:8;             /* Address offset value of the RAM 2a region. */
    } B;
  } AOSV_2;

  union {                              /* Actual RAM Pointer Address for Trigger */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t APT_2B:10;             /* Address pointer TRIGGER for RAM region 2b. */
      vuint32_t WAPT_2B:1;             /* Write bit for address pointer APT_2b, read as zero. */
      vuint32_t  :1;
      vuint32_t APT:10;                /* Address pointer TRIGGER. */
      vuint32_t WAPT:1;                /* Write bit for address pointer APT, reads as zero. */
      vuint32_t  :1;
    } B;
  } APT;

  union {                              /* Actual RAM Pointer Address for STATE */
    vuint32_t R;
    struct {
      vuint32_t  :12;
      vuint32_t APS_1C2:6;             /* Address pointer STATE for RAM regoin 1c2. */
      vuint32_t WAPS_1C2:1;            /* Write bit for address pointer APS_1c2, reads as zero. */
      vuint32_t  :5;
      vuint32_t APS:6;                 /* Address pointer STATE. */
      vuint32_t WAPS:1;                /* Write bit for address pointer APS, reads as zero. */
      vuint32_t  :1;
    } B;
  } APS;

  union {                              /* Actual RAM Pointer Address for Region 2C */
    vuint32_t R;
    struct {
      vuint32_t  :20;
      vuint32_t APT_2C:10;             /* Address pointer TRIGGER for RAM region 2c. */
      vuint32_t  :2;
    } B;
  } APT_2C;

  union {                              /* Actual RAM Pointer Address for Region 1C3 */
    vuint32_t R;
    struct {
      vuint32_t  :24;
      vuint32_t APS_1C3:6;             /* Address pointer STATE for RAM region 1c3. */
      vuint32_t  :2;
    } B;
  } APS_1C3;

  union {                              /* Number of Recent TRIGGER Events used for Calculations */
    vuint32_t R;
    struct {
      vuint32_t WVTN:1;                /* Write control bit for VTN; reads as zero. */
      vuint32_t WSYN:1;                /* Write control bit for SYN_T and SYN_T_old; reads as zero. */
      vuint32_t WNUT:1;                /* Write control bit for NUTE and FST; reads as zero. */
      vuint32_t  :4;
      vuint32_t VTN:6;                 /* Virtual TRIGGER number. */
      vuint32_t SYN_T_old:3;           /* Number of real and virtual events to be considered for the last increment. */
      vuint32_t SYN_T:3;               /* Number of real and virtual events to be considered for the current increment. */
      vuint32_t  :2;
      vuint32_t FST:1;                 /* FULL_SCALE of TRIGGER. */
      vuint32_t NUTE:10;               /* Number of recent TRIGGER events used for SUB_INC1 and action calculations modulo 2 * (TNU max +1). */
    } B;
  } NUTC;

  union {                              /* Number of Recent STATE Events used for Calculations */
    vuint32_t R;
    struct {
      vuint32_t WVSN:1;                /* Write control bit for VSN; reads as zero. */
      vuint32_t WSYN:1;                /* Write control bit for SYN_S and SYN_S_old; reads as zero. */
      vuint32_t WNUS:1;                /* Write control bit for NUSE; reads as zero. */
      vuint32_t  :4;
      vuint32_t VSN:6;                 /* Virtual STATE number. */
      vuint32_t SYN_S_OLD:6;           /* Number of real and virtual events to be considered for the last increment. */
      vuint32_t SYN_S:6;               /* Number of real and virtual events to be considered for the current increment. */
      vuint32_t FSS:1;                 /* FULL_SCALE of STATE. */
      vuint32_t NUSE:6;                /* Number of recent STATE events used for SUB_INCx calculations modulo 2*(SNU max +1). */
    } B;
  } NUSC;

  union {                              /* Number of Active TRIGGER Events to Interrupt */
    vuint32_t R;
    struct {
      vuint32_t  :22;
      vuint32_t NTI_CNT:10;            /* Number of TRIGGERs to interrupt. */
    } B;
  } NTI_CNT;

  union {                              /* Interrupt Register */
    vuint32_t R;
    struct {
      vuint32_t  :4;
      vuint32_t DCGI:1;                /* Direction change interrupt. */
      vuint32_t SORI:1;                /* STATE out of range. */
      vuint32_t TORI:1;                /* TRIGGER out of range interrupt. */
      vuint32_t CDSI:1;                /* Calculation of STATE duration done. */
      vuint32_t CDTI:1;                /* Calculation of TRIGGER duration done, only while NTI_CNT is zero. */
      vuint32_t TE4I:1;                /* TRIGGER event interrupt 4. */
      vuint32_t TE3I:1;                /* TRIGGER event interrupt 3. */
      vuint32_t TE2I:1;                /* TRIGGER event interrupt 2. */
      vuint32_t TE1I:1;                /* TRIGGER event interrupt 1. */
      vuint32_t TE0I:1;                /* TRIGGER event interrupt 0. */
      vuint32_t LL2I:1;                /* Loss of lock interrupt for SUB_INC2. */
      vuint32_t GL2I:1;                /* Get of lock interrupt, for SUB_INC2. */
      vuint32_t EI:1;                  /* Error interrupt (see status register bit 31). */
      vuint32_t LL1I:1;                /* Loss of lock interrupt for SUB_INC1. */
      vuint32_t GL1I:1;                /* Get of lock interrupt, for SUB_INC1. */
      vuint32_t W1I:1;                 /* Write access to RAM region 1b or 1c interrupt. */
      vuint32_t W2I:1;                 /* RAM write access to RAM region 2 interrupt. */
      vuint32_t PWI:1;                 /* Plausibility window (PVT) violation interrupt of TRIGGER. */
      vuint32_t TASI:1;                /* TRIGGER active slope interrupt. */
      vuint32_t SASI:1;                /* STATE active slope interrupt. */
      vuint32_t MTI:1;                 /* Missing TRIGGER interrupt. */
      vuint32_t MSI:1;                 /* Missing STATE interrupt. */
      vuint32_t TISI:1;                /* TRIGGER inactive slope interrupt. */
      vuint32_t SISI:1;                /* STATE inactive slope interrupt. */
      vuint32_t TAXI:1;                /* TRIGGER maximum hold time violation interrupt (dt > THMA > 0). */
      vuint32_t TINI:1;
      vuint32_t PEI:1;                 /* DPLL enable interrupt; announces the switch on of the DEN bit. */
      vuint32_t PDI:1;                 /* DPLL disable interrupt; announces the switch off of the DEN bit. */
    } B;
  } IRQ_NOTIFY;

  union {                              /* Interrupt Enable Register */
    vuint32_t R;
    struct {
      vuint32_t  :4;
      vuint32_t DCGI_IRQ_EN:1;         /* Direction change interrupt. */
      vuint32_t SORI_IRQ_EN:1;         /* STATE out of range. */
      vuint32_t TORI_IRQ_EN:1;         /* TRIGGER out of range interrupt. */
      vuint32_t CDSI_IRQ_EN:1;         /* Enable interrupt when calculation of TRIGGER duration done. */
      vuint32_t CDTI_IRQ_EN:1;         /* Enable interrupt when calculation of TRIGGER duration done. */
      vuint32_t TE4I_IRQ_EN:1;         /* TRIGGER event interrupt 4 enable. */
      vuint32_t TE3I_IRQ_EN:1;         /* TRIGGER event interrupt 3 enable. */
      vuint32_t TE2I_IRQ_EN:1;         /* TRIGGER event interrupt 2 enable. */
      vuint32_t TE1I_IRQ_EN:1;         /* TRIGGER event interrupt 1 enable. */
      vuint32_t TE0I_IRQ_EN:1;         /* TRIGGER event interrupt 0 enable. */
      vuint32_t LL2I_IRQ_EN:1;         /* Loss of lock interrupt enable for SUB_INC2. */
      vuint32_t GL2I_IRQ_EN:1;         /* Get of lock interrupt enable for SUB_INC2. */
      vuint32_t EI_IRQ_EN:1;           /* Error interrupt enable (see status register). */
      vuint32_t LL1I_IRQ_EN:1;         /* Loss of lock interrupt enable. */
      vuint32_t GL1I_IRQ_EN:1;         /* Get of lock interrupt enable, when lock arises. */
      vuint32_t W1I_IRQ_EN:1;          /* Write access to RAM region 1b or 1c interrupt. */
      vuint32_t W2I_IRQ_EN:1;          /* RAM write access to RAM region 2 interrupt enable. */
      vuint32_t PWI_IRQ_EN:1;          /* Plausibility window (PVT) violation interrupt of TRIGGER enable. */
      vuint32_t TASI_IRQ_EN:1;         /* TRIGGER active slope interrupt enable. */
      vuint32_t SASI_IRQ_EN:1;         /* STATE active slope interrupt enable. */
      vuint32_t MTI_IRQ_EN:1;          /* Missing TRIGGER interrupt enable. */
      vuint32_t MSI_IRQ_EN:1;          /* Missing STATE interrupt enable. */
      vuint32_t TISI_IRQ_EN:1;         /* TRIGGER inactive slope interrupt enable bit. */
      vuint32_t SISI_IRQ_EN:1;         /* STATE inactive slope interrupt enable bit. */
      vuint32_t TAXI_IRQ_EN:1;         /* TRIGGER maximum hold time violation interrupt enable bit. */
      vuint32_t TINI_IRQ_EN:1;         /* TRIGGER minimum hold time violation interrupt enable bit. */
      vuint32_t PEI_IRQ_EN:1;          /* DPLL enable interrupt enable, when switch on of the DEN bit. */
      vuint32_t PDI_IRQ_EN:1;          /* DPLL disable interrupt enable, when switch off of the DEN bit. */
    } B;
  } IRQ_EN;

  union {                              /* Force Interrupt Register */
    vuint32_t R;
    struct {
      vuint32_t  :4;                   /* Reserved. */
      vuint32_t TRG_DCGI:1;            /* Force interrupt DCGI. */
      vuint32_t TRG_SORI:1;            /* Force Interrupt SORI. */
      vuint32_t TRG_TORI:1;            /* Force Interrupt TORI. */
      vuint32_t TRG_CDSI:1;            /* Force Interrupt CDSI. */
      vuint32_t TRG_CDTI:1;            /* Force Interrupt CDTI. */
      vuint32_t TRG_TE4I:1;            /* Force Interrupt TE4I. */
      vuint32_t TRG_TE3I:1;            /* Force Interrupt TE3I. */
      vuint32_t TRG_TE2I:1;            /* Force Interrupt TE2I. */
      vuint32_t TRG_TE1I:1;            /* Force Interrupt TE1I. */
      vuint32_t TRG_TE0I:1;            /* Force Interrupt TE0I. */
      vuint32_t TRG_LL2I:1;            /* Force Interrupt LL2I. */
      vuint32_t TRG_GL2I:1;            /* Force Interrupt GL2I. */
      vuint32_t TRG_EI:1;              /* Force Interrupt EI. */
      vuint32_t TRG_LL1I:1;            /* Force Interrupt LL1I. */
      vuint32_t TRG_GL1I:1;            /* Force Interrupt GL1I. */
      vuint32_t TRG_W1I:1;             /* Force Interrupt W1I. */
      vuint32_t TRG_W2I:1;             /* Force Interrupt W2I. */
      vuint32_t TRG_PWI:1;             /* Force Interrupt PWI. */
      vuint32_t TRG_TASI:1;            /* Force Interrupt TASI. */
      vuint32_t TRG_SASI:1;            /* Force Interrupt SASI. */
      vuint32_t TRG_MTI:1;
      vuint32_t TRG_MSI:1;             /* Force Interrupt MSI. */
      vuint32_t TRG_TISI:1;            /* Force Interrupt TISI. */
      vuint32_t TRG_SISI:1;            /* Force Interrupt SISI. */
      vuint32_t TRG_TAXI:1;            /* Force Interrupt TAXI. */
      vuint32_t TRG_TINI:1;            /* Force Interrupt TINI. */
      vuint32_t TRG_PEI:1;             /* Force Interrupt PEI. */
      vuint32_t TRG_PDI:1;             /* Force Interrupt PDI. */
    } B;
  } IRQ_FORCINT;

  union {                              /* Interrupt Request Mode */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } IRQ_MODE;

  union {                              /* Error Interrupt Enable Register */
    vuint32_t R;
    struct {
      vuint32_t  :4;
      vuint32_t DCGI_EIRQ_EN:1;        /* Direction Change Interrupt. */
      vuint32_t SORI_EIRQ_EN:1;        /* STATE Out of Range Interrupt. */
      vuint32_t TORI_EIRQ_EN:1;        /* TRIGGER Out of Range Interrupt */
      vuint32_t CDSI_EIRQ_EN:1;        /* Enable interrupt when calculation of STATE duration done. */
      vuint32_t CDTI_EIRQ_EN:1;        /* Enable interrupt when calculation of TRIGGER duration done */
      vuint32_t TE4I_EIRQ_EN:1;        /* TRIGGER event interrupt 4 enable. */
      vuint32_t TE3I_EIRQ_EN:1;        /* TRIGGER event interrupt 3 enable. */
      vuint32_t TE2I_EIRQ_EN:1;        /* TRIGGER event interrupt 2 enable. */
      vuint32_t TE1I_EIRQ_EN:1;        /* TRIGGER event interrupt 1 enable. */
      vuint32_t TE0I_EIRQ_EN:1;        /* TRIGGER event interrupt 0 enable. */
      vuint32_t LL2I_EIRQ_EN:1;        /* Loss of lock interrupt enable for SUB_INC2. */
      vuint32_t GL2I_EIRQ_EN:1;        /* Get of lock interrupt enable for SUB_INC2. */
      vuint32_t EI_EIRQ_EN:1;          /* Error interrupt enable (see status register). */
      vuint32_t LL1I_EIRQ_EN:1;        /* Loss of lock interrupt enable. */
      vuint32_t GL1I_EIRQ_EN:1;        /* Get of lock interrupt enable, when lock arises. */
      vuint32_t W1I_EIRQ_EN:1;         /* Write access to RAM region 1b or 1c interrupt. */
      vuint32_t W2I_EIRQ_EN:1;         /* RAM write access to RAM region 2 interrupt enable. */
      vuint32_t PWI_EIRQ_EN:1;         /* Plausibility window (PVT) violation interrupt of TRIGGER enable. */
      vuint32_t TASI_EIRQ_EN:1;        /* TRIGGER active slope interrupt enable. */
      vuint32_t SASI_EIRQ_EN:1;        /* STATE active slope interrupt enable. */
      vuint32_t MTI_EIRQ_EN:1;         /* Missing TRIGGER interrupt enable. */
      vuint32_t MSI_EIRQ_EN:1;         /* Missing STATE interrupt enable. */
      vuint32_t TISI_EIRQ_EN:1;        /* TRIGGER inactive slope interrupt enable bit. */
      vuint32_t SISI_EIRQ_EN:1;        /* STATE inactive slope interrupt enable bit. */
      vuint32_t TAXI_EIRQ_EN:1;        /* TRIGGER maximum hold time violation interrupt enable bit. */
      vuint32_t TINI_EIRQ_EN:1;        /* TRIGGER minimum hold time violation interrupt enable bit. */
      vuint32_t PEI_EIRQ_EN:1;         /* DPLL enable interrupt enable, when switch on of the DEN bit. */
      vuint32_t PDI_EIRQ_EN:1;         /* DPLL disable interrupt enable, when switch off of the DEN bit. */
    } B;
  } EIRQ_EN;

  uint8_t DPLL_reserved0[92];
  union {                              /* Counter Value of Sent SUB_INC1 Pulses */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t INC_CNT1:24;           /* Actual number of pulses to be still sent out at the current increment until the next valid input signal in automatic end mode. */
    } B;
  } INC_CNT1;

  union {                              /* Counter Value of sent SUB_INC2 values (for SMC=1 and RMO=1) */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t INC_CNT2:24;           /* Actual number of pulses to be still sent out at the current increment until the next valid input signal in automatic end mode. */
    } B;
  } INC_CNT2;

  union {                              /* TRIGGER Time Stamp Field Offset at Synchronization Time */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t APT_2B_OLD:10;         /* Address pointer TRIGGER for RAM region 2B at synchronization time. */
      vuint32_t  :7;
      vuint32_t APT_2B_STATUS:1;       /* Address pointer 2B status. */
      vuint32_t APT_2B_EXT:6;          /* Address pointer 2B extension. */
    } B;
  } APT_SYNC;

  union {                              /* STATE Time Stamp Field Offset at Synchronization Time */
    vuint32_t R;
    struct {
      vuint32_t  :12;
      vuint32_t APS_1C2_OLD:6;         /* Address pointer STATE for RAM regoin 1C2 at synchronization time. */
      vuint32_t  :7;
      vuint32_t APS_1C2_STATUS:1;      /* Address pointer 1C2 status. */
      vuint32_t APS_1C2_EXT:6;         /* Address pointer 1C2 extension. */
    } B;
  } APS_SYNC;

  union {                              /* Time Stamp Value for the last valid TRIGGER */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t TBU_TS0_T:24;          /* Value of TBU_TS0 at the last TRIGGER event. */
    } B;
  } TBU_TS0_T;

  union {                              /* Time Stamp Value for the last valid STATE */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t TBU_TS0_S:24;          /* Value of TBU_TS0 at the last STATE event. */
    } B;
  } TBU_TS0_S;

  union {                              /* ADD_IN Value in Direct Load Mode for TRIGGER */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t ADD_IN_LD1:24;         /* Input value for SUB_INC1 generation. */
    } B;
  } ADD_IN_LD1;

  union {                              /* ADD_IN Value in Direct Load Mode for STATE */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t ADD_IN_LD2:24;         /* Input value for SUB_INC2 generation. */
    } B;
  } ADD_IN_LD2;

  uint8_t DPLL_reserved1[44];
  union {                              /* Status Register */
    vuint32_t R;
    struct {
      vuint32_t ERR:1;                 /* Error. */
      vuint32_t LOCK1:1;               /* DPLL Lock status concerning SUB_INC1. */
      vuint32_t FTD:1;                 /* First TRIGGER detected. */
      vuint32_t FSD:1;                 /* First STATE detected. */
      vuint32_t SYT:1;                 /* Synchronization condition of TRIGGER fixed. */
      vuint32_t SYS:1;                 /* Synchronization condition of STATE fixed. */
      vuint32_t LOCK2:1;               /* DPLL Lock status concerning SUB_INC2. */
      vuint32_t  :1;
      vuint32_t BWD1:1;                /* Backwards drive of SUB_INC1. */
      vuint32_t BWD2:1;                /* Backwards drive of SUB_INC2. */
      vuint32_t ITN:1;                 /* Increment number of TRIGGER is not plausible. */
      vuint32_t ISN:1;                 /* Increment number of STATE is not plausible. */
      vuint32_t CAIP1:1;               /* Calculation of actions 0 to 11 in progress (1st part). */
      vuint32_t CAIP2:1;               /* Calculation of actions 12 to 23 in progress (2nd part). */
      vuint32_t CSVT:1;                /* Current signal value TRIGGER. */
      vuint32_t CSVS:1;                /* Current signal value STATE. */
      vuint32_t LOW_RES:1;             /* Low resolution of TBU_TS0. */
      vuint32_t  :2;
      vuint32_t RAM2_ERR:1;            /* DPLL internal access to not configured RAM2 memory space. */
      vuint32_t MT:1;                  /* Missing TRIGGER detected according to TOV. */
      vuint32_t TOR:1;                 /* TRIGGER out of range. */
      vuint32_t MS:1;                  /* Missing STATE detected according to TOV_S. */
      vuint32_t SOR:1;                 /* STATE out of range. */
      vuint32_t PSE:1;                 /* Prediction space configuration error. */
      vuint32_t RCT:1;                 /* Resolution conflict TRIGGER. */
      vuint32_t RCS:1;                 /* Resolution conflict STATE. */
      vuint32_t CRO:1;                 /* Calculated Reciprocal value overflow. */
      vuint32_t CTO:1;                 /* Calculated TRIGGER duration overflow. */
      vuint32_t  :1;
      vuint32_t CSO:1;                 /* Calculated STATE duration overflow. */
      vuint32_t  :1;
    } B;
  } STATUS;

  union {                              /* ID Information for In ut Signal PTR x (Position minus Time Request) */
    vuint32_t R;
    struct {
      vuint32_t  :23;
      vuint32_t ID_PMTR_n:9;           /* ID information to the input signal PMTR_n from the ARU. */
    } B;
  } ID_PMTR[32];

  uint8_t DPLL_reserved2[96];
  union {                              /* Shadow Register of DPLL_CTRL_0 controlled by a valid TRIGGER Slope */
    vuint32_t R;
    struct {
      vuint32_t RMO:1;                 /* Reference mode. */
      vuint32_t  :3;
      vuint32_t IDT:1;                 /* Input delay TRIGGER; */
      vuint32_t  :1;
      vuint32_t AMT:1;                 /* Adapt mode TRIGGER */
      vuint32_t  :14;
      vuint32_t IFP:1;                 /* Input filter position. */
      vuint32_t MLT:10;                /* Multiplier for TRIGGER. */
    } B;
  } CTRL_0_SHADOW_TRIGGER;

  union {                              /* Shadow Register of DPLL_CTRL_0 controlled by a valid STATE Slope */
    vuint32_t R;
    struct {
      vuint32_t RMO:1;                 /* Reference mode. */
      vuint32_t  :3;
      vuint32_t IDS:1;                 /* Input delay STATE. */
      vuint32_t  :1;
      vuint32_t AMS:1;                 /* Addapt mode STATE. */
      vuint32_t  :14;
      vuint32_t IFP:1;                 /* Input filter position. */
      vuint32_t  :10;
    } B;
  } CTRL_0_SHADOW_STATE;

  union {                              /* Shadow Register of DPLL_CTRL_1 controlled by a valid TRIGGER Slope */
    vuint32_t R;
    struct {
      vuint32_t  :24;
      vuint32_t PCM1:1;                /* Pulse Correction Mode. */
      vuint32_t DLM1:1;                /* Direct Load Mode. */
      vuint32_t SGE1:1;                /* SUB_INC1 generator enable. */
      vuint32_t PIT:1;                 /* Plausibility. */
      vuint32_t COA:1;                 /* Correction strategy in automatic end mode (DMO=0). */
      vuint32_t  :2;
      vuint32_t DMO:1;                 /* DPLL mode select.. */
    } B;
  } CTRL_1_SHADOW_TRIGGER;

  union {                              /* Shadow Register of DPLL_CTRL_1 controlled by a valid STATE Slope */
    vuint32_t R;
    struct {
      vuint32_t SYN_NS:21;             /* Synchronization number of STATE. */
      vuint32_t PCM2:1;                /* Pulse Correction Mode for SUB_INC2 generation. */
      vuint32_t DLM2:1;                /* Direct Load Mode for SUB_INC2 generation. */
      vuint32_t SGE2:1;                /* SUB_INC2 generator enable. */
      vuint32_t PCM1:1;                /* Pulse Correction Mode for SUB_INC1 generation. */
      vuint32_t DLM1:1;                /* Direct Load Mode for SUB_INC1 generation. */
      vuint32_t SGE1:1;                /* SUB_INC1 generator enable. */
      vuint32_t PIT:1;                 /* Plausibility value PVT to next valid TRIGGER is time related. */
      vuint32_t COA:1;                 /* Correction strategy in automatic end mode (DMO=0). */
      vuint32_t  :1;
      vuint32_t DEN:1;                 /* DPLL enable. */
      vuint32_t DMO:1;                 /* DPLL mode select. */
    } B;
  } CTRL_1_SHADOW_STATE;

  uint8_t DPLL_reserved3[12];
  union {                              /* Register to control the RAM Initialization */
    vuint32_t R;
    struct {
      vuint32_t  :27;
      vuint32_t INIT_RAM:1;            /* RAM regions 1A, 1B and 2 are to be initialized. */
      vuint32_t  :1;
      vuint32_t INIT_2:1;              /* RAM region 2 initialization in progress. */
      vuint32_t INIT_1B:1;             /* RAM region 1B initialization in progress. */
      vuint32_t INIT_1A:1;             /* RAM region 1A initialization in progress. */
    } B;
  } RAM_INI;

  uint8_t DPLL_reserved4[3072];
  union {                              /* Calculated Time Value to start Action i */
    vuint32_t R;
    struct {
      vuint32_t TSAC:32;               /* Calculated time stamp for ACTION_i. */
    } B;
  } TSAC[32];

  union {                              /* DPLL Calculated Position Value ACTION i */
    vuint32_t R;
    struct {
      vuint32_t PSAC:32;               /* Calculated position value for the start of ACTION_i . */
    } B;
  } PSAC[32];

  union {                              /* Control Bits for up to 32 Actions */
    vuint32_t R;
    struct {
      vuint32_t  :3;
      vuint32_t ACB_3:5;               /* Action Control Bits of ACTION_(i + 3), reflects ACT_D[i+3](52:48), i=4*j. */
      vuint32_t  :3;
      vuint32_t ACB_2:5;               /* Action Control Bits of ACTION_(i + 2), reflects ACT_D[i+2](52:48), i=4*j. */
      vuint32_t  :3;
      vuint32_t ACB_1:5;               /* Action Control Bits of ACTION_(i + 1) , reflects ACT_D[i+1](52:48), i=4*j. */
      vuint32_t  :3;
      vuint32_t ACB_0:5;               /* Control Bits of ACTION_i, reflects ACT_D[i](52:48), i=4*j. */
    } B;
  } ACB[8];
};


/* ============================================================================
   =============================== Module: GTM_F2A ============================
   ============================================================================ */

struct GTM_F2A_tag {
  union {                              /* F2A Read Channel n Address Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :23;
      vuint32_t ADDR:9;                /* ARU Read address. */
    } B;
  } CH_ARU_RD_FIFO[8];

  union {                              /* F2A Channel n Stream Configuration Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :13;
      vuint32_t DIR:1;                 /* Data transfer direction. */
      vuint32_t TMODE:2;               /* Transfer mode for 53 bit ARU data from/to FIFO. */
      vuint32_t  :16;
    } B;
  } CH_STR_CFG[8];

  union {                              /* F2A Stream Activation Register */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t STR7_EN:2;             /* Enable/disable stream 7. */
      vuint32_t STR6_EN:2;             /* Enable/disable stream 6. */
      vuint32_t STR5_EN:2;             /* Enable/disable stream 5. */
      vuint32_t STR4_EN:2;             /* Enable/disable stream 4. */
      vuint32_t STR3_EN:2;             /* Enable/disable stream 3. */
      vuint32_t STR2_EN:2;             /* Enable/disable stream 2. */
      vuint32_t STR1_EN:2;             /* Enable/disable stream 1. */
      vuint32_t STR0_EN:2;             /* STR0_EN */
    } B;
  } ENABLE;
};


/* ============================================================================
   =============================== Module: GTM_FIFO ===========================
   ============================================================================ */

struct GTM_FIFO_tag {
  struct {
    union {                            /* FIFO Channel Control Register */
      vuint32_t R;
      struct {
        vuint32_t  :28;                /* Reserved. */
        vuint32_t WULOCK:1;            /* RAM write unlock. */
        vuint32_t FLUSH:1;             /* FIFO Flush control. */
        vuint32_t RAP:1;               /* RAM access priority. */
        vuint32_t RBM:1;               /* Ring buffer mode enable. */
      } B;
    } CTRL;
    union {                            /* FIFO Channel End Address Register */
      vuint32_t R;
      struct {
        vuint32_t  :22;                /* Reserved. */
        vuint32_t ADDR:10;             /* End address for FIFO channel n. */
      } B;
    } END_ADDR;
    union {                            /* FIFO Channel Start Address Register */
      vuint32_t R;
      struct {
        vuint32_t  :22;                /* Reserved. */
        vuint32_t ADDR:10;             /* Start address for FIFO channel n. */
      } B;
    } START_ADDR;
    union {                            /* FIFO Channel Upper Watermark Register */
      vuint32_t R;
      struct {
        vuint32_t  :22;                /* Reserved. */
        vuint32_t ADDR:10;             /* Upper watermark. */
      } B;
    } UPPER_WM;
    union {                            /* FIFO Channel Lower Watermark Register */
      vuint32_t R;
      struct {
        vuint32_t  :22;                /* Reserved. */
        vuint32_t ADDR:10;             /* Normal Operation mode: Lower watermark. Ring buffer operation mode: Gate pointer from LWU to UWE. */
      } B;
    } LOWER_WM;
    union {                            /* FIFO Channel Status Register */
      vuint32_t R;
      struct {
        vuint32_t  :28;                /* Reserved. */
        vuint32_t UP_WM:1;             /* Upper watermark reached. */
        vuint32_t LOW_WM:1;            /* Lower watermark reached. */
        vuint32_t FULL:1;              /* FIFO fill level status. */
        vuint32_t EMPTY:1;             /* FIFO fill level status. */
      } B;
    } STATUS;
    union {                            /* FIFO Channel Fill Level Register */
      vuint32_t R;
      struct {
        vuint32_t  :21;                /* Reserved. */
        vuint32_t LEVEL:11;            /* Fill level of the current FIFO. */
      } B;
    } FILL_LEVEL;
    union {                            /* FIFO Channel Write Pointer Register */
      vuint32_t R;
      struct {
        vuint32_t  :22;                /* Reserved. */
        vuint32_t ADDR:10;             /* Position of the write pointer. */
      } B;
    } WR_PTR;
    union {                            /* FIFO Channel Read Pointer */
      vuint32_t R;
      struct {
        vuint32_t  :22;                /* Reserved. */
        vuint32_t ADDR:10;             /* Position of the read pointer. */
      } B;
    } RD_PTR;
    union {                            /* FIFO Channel IRQ Notification Register */
      vuint32_t R;
      struct {
        vuint32_t  :28;                /* Reserved. */
        vuint32_t FIFO_UWM:1;          /* FIFO Upper watermark was over-run. */
        vuint32_t FIFO_LWM:1;          /* FIFO Lower watermark was under-run. */
        vuint32_t FIFO_FULL:1;         /* FIFO is full. */
        vuint32_t FIFO_EMPTY:1;        /* FIFO is empty. */
      } B;
    } IRQ_NOTIFY;
    union {                            /* FIFO Channel IRQ Enable Register */
      vuint32_t R;
      struct {
        vuint32_t  :28;                /* Reserved. */
        vuint32_t FIFO_UWM_IRQ_EN:1;   /* FIFO Upper Water Mark Interrupt Enable. */
        vuint32_t FIFO_LWM_IRQ_EN:1;   /* FIFO Lower Watermark Interrupt Enable. */
        vuint32_t FIFO_FULL_IRQ_EN:1;  /* FIFO Full Interrupt Enable. */
        vuint32_t FIFO_EMPTY_IRQ_EN:1; /* FIFO Empty Interrupt Enable. */
      } B;
    } IRQ_EN;
    union {                            /* FIFO Channel Force Interrupt Register */
      vuint32_t R;
      struct {
        vuint32_t  :28;                /* Reserved. */
        vuint32_t TRG_FIFO_UWM:1;      /* Force interrupt of upper watermark. */
        vuint32_t TRG_FIFO_LWM:1;      /* Force interrupt of lower watermark. */
        vuint32_t TRG_FIFO_FULL:1;     /* Force interrupt of FIFO full status. */
        vuint32_t TRG_FIFO_EMPTY:1;    /* Force interrupt of FIFO empty status. */
      } B;
    } IRQ_FORCINT;
    union {                            /* FIFO Channel IRQ Mode Register */
      vuint32_t R;
      struct {
        vuint32_t  :28;                /* Reserved. */
        vuint32_t DMA_HYST_DIR:1;      /* DMA direction in hysteresis mode. */
        vuint32_t DMA_HYSTERESIS:1;    /* Enable DMA hysteresis mode. */
        vuint32_t IRQ_MODE:2;          /* IRQ mode select. */
      } B;
    } IRQ_MODE;
    union {                            /* FIFO Channel Error Interrupt Request Register */
      vuint32_t R;
      struct {
        vuint32_t  :28;
        vuint32_t FIFO_UWM_EIRQ_EN:1;  /* FIFO Upper Water Mark Error Interrupt Request Enable. */
        vuint32_t FIFO_LWM_EIRQ_EN:1;  /* FIFO Lower Water Mark Error Interrupt Request Enable. */
        vuint32_t FIFO_FULL_EIRQ_EN:1; /* FIFO Full Error Interrupt Request Enable. */
        vuint32_t FIFO_EMPTY_EIRQ_EN:1; /* FIFO Empty Error Interrupt Request Enable. */
      } B;
    } EIRQ_EN;
    uint8_t CHANNEL_reserved0[8];
  } CHANNEL[8];
};


/* ============================================================================
   =============================== Module: GTM_ICM ============================
   ============================================================================ */

struct GTM_ICM_tag {
  union {                              /* GTM Infrastructure Interrupt Group Register */
    vuint32_t R;
    struct {
      vuint32_t PSM1_CH7_IRQ:1;        /* PSM1 shared submodule channel 7 interrupt. */
      vuint32_t PSM1_CH6_IRQ:1;        /* PSM1 shared submodule channel 6 interrupt. */
      vuint32_t PSM1_CH5_IRQ:1;        /* PSM1 shared submodule channel 5 interrupt. */
      vuint32_t PSM1_CH4_IRQ:1;        /* PSM1 shared submodule channel 4 interrupt. */
      vuint32_t PSM1_CH3_IRQ:1;        /* PSM1 shared submodule channel 3 interrupt. */
      vuint32_t PSM1_CH2_IRQ:1;        /* PSM1 shared submodule channel 2 interrupt. */
      vuint32_t PSM1_CH1_IRQ:1;        /* PSM1 shared submodule channel 1 interrupt. */
      vuint32_t PSM1_CH0_IRQ:1;        /* PSM1 shared submodule channel 0 interrupt. */
      vuint32_t PSM0_CH7_IRQ:1;        /* PSM0 shared submodule channel 7 interrupt. */
      vuint32_t PSM0_CH6_IRQ:1;        /* PSM0 shared submodule channel 6 interrupt. */
      vuint32_t PSM0_CH5_IRQ:1;        /* PSM0 shared submodule channel 5 interrupt. */
      vuint32_t PSM0_CH4_IRQ:1;        /* PSM0 shared submodule channel 4 interrupt. */
      vuint32_t PSM0_CH3_IRQ:1;        /* PSM0 shared submodule channel 3 interrupt. */
      vuint32_t PSM0_CH2_IRQ:1;        /* PSM0 shared submodule channel 2 interrupt. */
      vuint32_t PSM0_CH1_IRQ:1;        /* PSM0 shared submodule channel 1 interrupt. */
      vuint32_t PSM0_CH0_IRQ:1;        /* PSM0 shared submodule channel 0 interrupt. */
      vuint32_t  :6;
      vuint32_t SPE3_IRQ:1;            /* SPE3 shared submodule interrupt. */
      vuint32_t SPE2_IRQ:1;            /* SPE2 shared submodule interrupt. */
      vuint32_t SPE1_IRQ:1;            /* SPE1 shared submodule interrupt. */
      vuint32_t SPE0_IRQ:1;            /* SPE0 shared submodule interrupt. */
      vuint32_t CMP_IRQ:1;             /* CMP shared submodule interrupt. */
      vuint32_t AEI_IRQ:1;             /* AEI_IRQ interrupt. */
      vuint32_t BRC_IRQ:1;             /* BRC shared submodule interrupt. */
      vuint32_t ARU_ACC_ACK_IRQ:1;     /* ARU_ACC_ACK interrupt. */
      vuint32_t ARU_NEW_DATA1_IRQ:1;   /* ARU_NEW_DATA1 interrupt. */
      vuint32_t ARU_NEW_DATA0_IRQ:1;   /* ARU_NEW_DATA0 interrupt. */
    } B;
  } IRQG_0;

  union {                              /* DPLL Interrupt Group Register */
    vuint32_t R;
    struct {
      vuint32_t  :5;
      vuint32_t DPLL_SORI_IRQ:1;       /* DPLL calculated duration interrupt for STATE. */
      vuint32_t DPLL_TORI_IRQ:1;       /* DPLL calculated duration interrupt for TRIGGER. */
      vuint32_t DPLL_CDSI_IRQ:1;       /* DPLL calculated duration interrupt for STATE. */
      vuint32_t DPLL_CDTI_IRQ:1;       /* DPLL calculated duration interrupt for TRIGGER. */
      vuint32_t DPLL_TE4I_IRQ:1;       /* TRIGGER event interrupt 4. */
      vuint32_t DPLL_TE3I_IRQ:1;       /* TRIGGER event interrupt 3. */
      vuint32_t DPLL_TE2I_IRQ:1;       /* TRIGGER event interrupt 2. */
      vuint32_t DPLL_TE1I_IRQ:1;       /* TRIGGER event interrupt 1. */
      vuint32_t DPLL_TE0I_IRQ:1;       /* TRIGGER event interrupt 0. */
      vuint32_t DPLL_LL2I_IRQ:1;       /* Lost of lock interrupt for SUB_INC2. */
      vuint32_t DPLL_GL2I_IRQ:1;       /* Get of lock interrupt for SUB_INC2. */
      vuint32_t DPLL_EI_IRQ:1;         /* Error interrupt. */
      vuint32_t DPLL_LLI_IRQ:1;        /* Lost of lock interrupt for SUB_INC1. */
      vuint32_t DPLL_GLI_IRQ:1;        /* Get of lock interrupt for SUB_INC1. */
      vuint32_t DPLL_W1I_IRQ:1;        /* Write access to RAM region 1b or 1c interrupt. */
      vuint32_t DPLL_W2I_IRQ:1;        /* Write access to RAM region 2 interrupt. */
      vuint32_t DPLL_PWI_IRQ:1;        /* Plausibility window (PVT) violation interrupt of TRIGGER. */
      vuint32_t DPLL_TASI_IRQ:1;       /* TRIGGER active slope detected while NTI_CNT is zero. */
      vuint32_t DPLL_SASI_IRQ:1;       /* STATE active slope detected. */
      vuint32_t DPLL_MTI_IRQ:1;        /* Missing TRIGGER interrupt. */
      vuint32_t DPLL_MSI_IRQ:1;        /* Missing STATE interrupt. */
      vuint32_t DPLL_TISI_IRQ:1;       /* TRIGGER inactive slope detected interrupt. */
      vuint32_t DPLL_SISI_IRQ:1;       /* STATE inactive slope detected interrupt. */
      vuint32_t DPLL_TAXI_IRQ:1;       /* TRIGGER maximum hold time (THMA) violation detected interrupt. */
      vuint32_t DPLL_TINI_IRQ:1;       /* TRIGGER minimum hold time (THMI) violation detected interrupt. */
      vuint32_t DPLL_EDI_IRQ:1;        /* DPLL enable/disable interrupt. */
      vuint32_t DPLL_DCGI_IRQ:1;       /* TRIGGER direction change detected. */
    } B;
  } IRQG_1;

  union {                              /* TIM Interrupt Group 0 Register */
    vuint32_t R;
    struct {
      vuint32_t TIM3_CH7_IRQ:1;        /* TIM3 shared interrupt channel 7. */
      vuint32_t TIM3_CH6_IRQ:1;        /* TIM3 shared interrupt channel 6. */
      vuint32_t TIM3_CH5_IRQ:1;        /* TIM3 shared interrupt channel 5. */
      vuint32_t TIM3_CH4_IRQ:1;        /* TIM3 shared interrupt channel 4. */
      vuint32_t TIM3_CH3_IRQ:1;        /* TIM3 shared interrupt channel 3. */
      vuint32_t TIM3_CH2_IRQ:1;        /* TIM3 shared interrupt channel 2. */
      vuint32_t TIM3_CH1_IRQ:1;        /* TIM3 shared interrupt channel 1. */
      vuint32_t TIM3_CH0_IRQ:1;        /* TIM3 shared interrupt channel 0. */
      vuint32_t TIM2_CH7_IRQ:1;        /* TIM2 shared interrupt channel 7. */
      vuint32_t TIM2_CH6_IRQ:1;        /* TIM2 shared interrupt channel 6. */
      vuint32_t TIM2_CH5_IRQ:1;        /* TIM2 shared interrupt channel 5. */
      vuint32_t TIM2_CH4_IRQ:1;        /* TIM2 shared interrupt channel 4. */
      vuint32_t TIM2_CH3_IRQ:1;        /* TIM2 shared interrupt channel 3. */
      vuint32_t TIM2_CH2_IRQ:1;        /* TIM2 shared interrupt channel 2. */
      vuint32_t TIM2_CH1_IRQ:1;        /* TIM2 shared interrupt channel 1. */
      vuint32_t TIM2_CH0_IRQ:1;        /* TIM2 shared interrupt channel 0. */
      vuint32_t TIM1_CH7_IRQ:1;        /* TIM1 shared interrupt channel 7. */
      vuint32_t TIM1_CH6_IRQ:1;        /* TIM1 shared interrupt channel 6. */
      vuint32_t TIM1_CH5_IRQ:1;        /* TIM1 shared interrupt channel 5. */
      vuint32_t TIM1_CH4_IRQ:1;        /* TIM1 shared interrupt channel 4. */
      vuint32_t TIM1_CH3_IRQ:1;        /* TIM1 shared interrupt channel 3. */
      vuint32_t TIM1_CH2_IRQ:1;        /* TIM1 shared interrupt channel 2. */
      vuint32_t TIM1_CH1_IRQ:1;        /* TIM1 shared interrupt channel 1. */
      vuint32_t TIM1_CH0_IRQ:1;        /* TIM1 shared interrupt channel 0. */
      vuint32_t TIM0_CH7_IRQ:1;        /* TIM0 shared interrupt channel 7. */
      vuint32_t TIM0_CH6_IRQ:1;        /* TIM0 shared interrupt channel 6. */
      vuint32_t TIM0_CH5_IRQ:1;        /* TIM0 shared interrupt channel 5. */
      vuint32_t TIM0_CH4_IRQ:1;        /* TIM0 shared interrupt channel 4. */
      vuint32_t TIM0_CH3_IRQ:1;        /* TIM0 shared interrupt channel 3. */
      vuint32_t TIM0_CH2_IRQ:1;        /* TIM0 shared interrupt channel 2. */
      vuint32_t TIM0_CH1_IRQ:1;        /* TIM0 shared interrupt channel 1. */
      vuint32_t TIM0_CH0_IRQ:1;        /* TIM0 shared interrupt channel 0. */
    } B;
  } IRQG_2;

  union {                              /* TIM Interrupt Group 1 Register */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t TIM6_CH7_IRQ:1;        /* TIM6 shared interrupt channel 7. */
      vuint32_t TIM6_CH6_IRQ:1;        /* TIM6 shared interrupt channel 6. */
      vuint32_t TIM6_CH5_IRQ:1;        /* TIM6 shared interrupt channel 5. */
      vuint32_t TIM6_CH4_IRQ:1;        /* TIM6 shared interrupt channel 4. */
      vuint32_t TIM6_CH3_IRQ:1;        /* TIM6 shared interrupt channel 3. */
      vuint32_t TIM6_CH2_IRQ:1;        /* TIM6 shared interrupt channel 2. */
      vuint32_t TIM6_CH1_IRQ:1;        /* TIM6 shared interrupt channel 1. */
      vuint32_t TIM6_CH0_IRQ:1;        /* TIM6 shared interrupt channel 0. */
      vuint32_t TIM5_CH7_IRQ:1;        /* TIM5 shared interrupt channel 7. */
      vuint32_t TIM5_CH6_IRQ:1;        /* TIM5 shared interrupt channel 6. */
      vuint32_t TIM5_CH5_IRQ:1;        /* TIM5 shared interrupt channel 5. */
      vuint32_t TIM5_CH4_IRQ:1;        /* TIM5 shared interrupt channel 4. */
      vuint32_t TIM5_CH3_IRQ:1;        /* TIM5 shared interrupt channel 3. */
      vuint32_t TIM5_CH2_IRQ:1;        /* TIM5 shared interrupt channel 2. */
      vuint32_t TIM5_CH1_IRQ:1;        /* TIM5 shared interrupt channel 1. */
      vuint32_t TIM5_CH0_IRQ:1;        /* TIM5 shared interrupt channel 0. */
      vuint32_t TIM4_CH7_IRQ:1;        /* TIM4 shared interrupt channel 7. */
      vuint32_t TIM4_CH6_IRQ:1;        /* TIM4 shared interrupt channel 6. */
      vuint32_t TIM4_CH5_IRQ:1;        /* TIM4 shared interrupt channel 5. */
      vuint32_t TIM4_CH4_IRQ:1;        /* TIM4 shared interrupt channel 4. */
      vuint32_t TIM4_CH3_IRQ:1;        /* TIM4 shared interrupt channel 3. */
      vuint32_t TIM4_CH2_IRQ:1;        /* TIM4 shared interrupt channel 2. */
      vuint32_t TIM4_CH1_IRQ:1;        /* TIM4 shared interrupt channel 1. */
      vuint32_t TIM4_CH0_IRQ:1;        /* TIM4 shared interrupt channel 0. */
    } B;
  } IRQG_3;

  union {                              /* MCS Interrupt Group 0 Register */
    vuint32_t R;
    struct {
      vuint32_t MCS3_CH7_IRQ:1;        /* MCS3 channel 7 interrupt. */
      vuint32_t MCS3_CH6_IRQ:1;        /* MCS3 channel 6 interrupt. */
      vuint32_t MCS3_CH5_IRQ:1;        /* MCS3 channel 5 interrupt. */
      vuint32_t MCS3_CH4_IRQ:1;        /* MCS3 channel 4 interrupt. */
      vuint32_t MCS3_CH3_IRQ:1;        /* MCS3 channel 3 interrupt. */
      vuint32_t MCS3_CH2_IRQ:1;        /* MCS3 channel 2 interrupt. */
      vuint32_t MCS3_CH1_IRQ:1;        /* MCS3 channel 1 interrupt. */
      vuint32_t MCS3_CH0_IRQ:1;        /* MCS3 channel 0 interrupt. */
      vuint32_t MCS2_CH7_IRQ:1;        /* MCS2 channel 7 interrupt. */
      vuint32_t MCS2_CH6_IRQ:1;        /* MCS2 channel 6 interrupt. */
      vuint32_t MCS2_CH5_IRQ:1;        /* MCS2 channel 5 interrupt. */
      vuint32_t MCS2_CH4_IRQ:1;        /* MCS2 channel 4 interrupt. */
      vuint32_t MCS2_CH3_IRQ:1;        /* MCS2 channel 3 interrupt. */
      vuint32_t MCS2_CH2_IRQ:1;        /* MCS2 channel 2 interrupt. */
      vuint32_t MCS2_CH1_IRQ:1;        /* MCS2 channel 1 interrupt. */
      vuint32_t MCS2_CH0_IRQ:1;        /* MCS2 channel 0 interrupt. */
      vuint32_t MCS1_CH7_IRQ:1;        /* MCS1 channel 7 interrupt. */
      vuint32_t MCS1_CH6_IRQ:1;        /* MCS1 channel 6 interrupt. */
      vuint32_t MCS1_CH5_IRQ:1;        /* MCS1 channel 5 interrupt. */
      vuint32_t MCS1_CH4_IRQ:1;        /* MCS1 channel 4 interrupt. */
      vuint32_t MCS1_CH3_IRQ:1;        /* MCS1 channel 3 interrupt. */
      vuint32_t MCS1_CH2_IRQ:1;        /* MCS1 channel 2 interrupt. */
      vuint32_t MCS1_CH1_IRQ:1;        /* MCS1 channel 1 interrupt. */
      vuint32_t MCS1_CH0_IRQ:1;        /* MCS1 channel 0 interrupt. */
      vuint32_t MCS0_CH7_IRQ:1;        /* MCS0 channel 7 interrupt. */
      vuint32_t MCS0_CH6_IRQ:1;        /* MCS0 channel 6 interrupt. */
      vuint32_t MCS0_CH5_IRQ:1;        /* MCS0 channel 5 interrupt. */
      vuint32_t MCS0_CH4_IRQ:1;        /* MCS0 channel 4 interrupt. */
      vuint32_t MCS0_CH3_IRQ:1;        /* MCS0 channel 3 interrupt. */
      vuint32_t MCS0_CH2_IRQ:1;        /* MCS0 channel 2 interrupt. */
      vuint32_t MCS0_CH1_IRQ:1;        /* MCS0 channel 1 interrupt. */
      vuint32_t MCS0_CH0_IRQ:1;        /* MCS0 channel 0 interrupt. */
    } B;
  } IRQG_4;

  union {                              /* MCS Interrupt Group 1 Register */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t MCS6_CH7_IRQ:1;        /* MCS6 channel 7 interrupt. */
      vuint32_t MCS6_CH6_IRQ:1;        /* MCS6 channel 6 interrupt. */
      vuint32_t MCS6_CH5_IRQ:1;        /* MCS6 channel 5 interrupt. */
      vuint32_t MCS6_CH4_IRQ:1;        /* MCS6 channel 4 interrupt. */
      vuint32_t MCS6_CH3_IRQ:1;        /* MCS6 channel 3 interrupt. */
      vuint32_t MCS6_CH2_IRQ:1;        /* MCS6 channel 2 interrupt. */
      vuint32_t MCS6_CH1_IRQ:1;        /* MCS6 channel 1 interrupt. */
      vuint32_t MCS6_CH0_IRQ:1;        /* MCS6 channel 0 interrupt. */
      vuint32_t MCS5_CH7_IRQ:1;        /* MCS5 channel 7 interrupt. */
      vuint32_t MCS5_CH6_IRQ:1;        /* MCS5 channel 6 interrupt. */
      vuint32_t MCS5_CH5_IRQ:1;        /* MCS5 channel 5 interrupt. */
      vuint32_t MCS5_CH4_IRQ:1;        /* MCS5 channel 4 interrupt. */
      vuint32_t MCS5_CH3_IRQ:1;        /* MCS5 channel 3 interrupt. */
      vuint32_t MCS5_CH2_IRQ:1;        /* MCS5 channel 2 interrupt. */
      vuint32_t MCS5_CH1_IRQ:1;        /* MCS5 channel 1 interrupt. */
      vuint32_t MCS5_CH0_IRQ:1;        /* MCS5 channel 0 interrupt. */
      vuint32_t MCS4_CH7_IRQ:1;        /* MCS4 channel 7 interrupt. */
      vuint32_t MCS4_CH6_IRQ:1;        /* MCS4 channel 6 interrupt. */
      vuint32_t MCS4_CH5_IRQ:1;        /* MCS4 channel 5 interrupt. */
      vuint32_t MCS4_CH4_IRQ:1;        /* MCS4 channel 4 interrupt. */
      vuint32_t MCS4_CH3_IRQ:1;        /* MCS4 channel 3 interrupt. */
      vuint32_t MCS4_CH2_IRQ:1;        /* MCS4 channel 2 interrupt. */
      vuint32_t MCS4_CH1_IRQ:1;        /* MCS4 channel 1 interrupt. */
      vuint32_t MCS4_CH0_IRQ:1;        /* MCS4 channel 0 interrupt. */
    } B;
  } IRQG_5;

  union {                              /* TOM Interrupt Group 0 Register */
    vuint32_t R;
    struct {
      vuint32_t TOM1_CH15_IRQ:1;       /* TOM1 channel 15 shared interrupt. */
      vuint32_t TOM1_CH14_IRQ:1;       /* TOM1 channel 14 shared interrupt. */
      vuint32_t TOM1_CH13_IRQ:1;       /* TOM1 channel 13 shared interrupt. */
      vuint32_t TOM1_CH12_IRQ:1;       /* TOM1 channel 12 shared interrupt. */
      vuint32_t TOM1_CH11_IRQ:1;       /* TOM1 channel 11 shared interrupt. */
      vuint32_t TOM1_CH10_IRQ:1;       /* TOM1 channel 10 shared interrupt. */
      vuint32_t TOM1_CH9_IRQ:1;        /* TOM1 channel 9 shared interrupt. */
      vuint32_t TOM1_CH8_IRQ:1;        /* TOM1 channel 8 shared interrupt. */
      vuint32_t TOM1_CH7_IRQ:1;        /* TOM1 channel 7 shared interrupt. */
      vuint32_t TOM1_CH6_IRQ:1;        /* TOM1 channel 6 shared interrupt. */
      vuint32_t TOM1_CH5_IRQ:1;        /* TOM1 channel 5 shared interrupt. */
      vuint32_t TOM1_CH4_IRQ:1;        /* TOM1 channel 4 shared interrupt. */
      vuint32_t TOM1_CH3_IRQ:1;        /* TOM1 channel 3 shared interrupt. */
      vuint32_t TOM1_CH2_IRQ:1;        /* TOM1 channel 2 shared interrupt. */
      vuint32_t TOM1_CH1_IRQ:1;        /* TOM1 channel 1 shared interrupt. */
      vuint32_t TOM1_CH0_IRQ:1;        /* TOM1 channel 0 shared interrupt. */
      vuint32_t TOM0_CH15_IRQ:1;       /* TOM0 channel 15 shared interrupt. */
      vuint32_t TOM0_CH14_IRQ:1;       /* TOM0 channel 14 shared interrupt. */
      vuint32_t TOM0_CH13_IRQ:1;       /* TOM0 channel 13 shared interrupt. */
      vuint32_t TOM0_CH12_IRQ:1;       /* TOM0 channel 12 shared interrupt. */
      vuint32_t TOM0_CH11_IRQ:1;       /* TOM0 channel 11 shared interrupt. */
      vuint32_t TOM0_CH10_IRQ:1;       /* TOM0 channel 10 shared interrupt. */
      vuint32_t TOM0_CH9_IRQ:1;        /* TOM0 channel 9 shared interrupt. */
      vuint32_t TOM0_CH8_IRQ:1;        /* TOM0 channel 8 shared interrupt. */
      vuint32_t TOM0_CH7_IRQ:1;        /* TOM0 channel 7 shared interrupt. */
      vuint32_t TOM0_CH6_IRQ:1;        /* TOM0 channel 6 shared interrupt. */
      vuint32_t TOM0_CH5_IRQ:1;        /* TOM0 channel 5 shared interrupt. */
      vuint32_t TOM0_CH4_IRQ:1;        /* TOM0 channel 4 shared interrupt. */
      vuint32_t TOM0_CH3_IRQ:1;        /* TOM0 channel 3 shared interrupt. */
      vuint32_t TOM0_CH2_IRQ:1;        /* TOM0 channel 2 shared interrupt. */
      vuint32_t TOM0_CH1_IRQ:1;        /* TOM0 channel 1 shared interrupt */
      vuint32_t TOM0_CH0_IRQ:1;        /* TOM0 channel 0 shared interrupt. */
    } B;
  } IRQG_6;

  union {                              /* TOM Interrupt Group 1 Register */
    vuint32_t R;
    struct {
      vuint32_t TOM3_CH15_IRQ:1;       /* TOM3 channel 15 shared interrupt. */
      vuint32_t TOM3_CH14_IRQ:1;       /* TOM3 channel 14 shared interrupt. */
      vuint32_t TOM3_CH13_IRQ:1;       /* TOM3 channel 13 shared interrupt. */
      vuint32_t TOM3_CH12_IRQ:1;       /* TOM3 channel 12 shared interrupt. */
      vuint32_t TOM3_CH11_IRQ:1;       /* TOM3 channel 11 shared interrupt. */
      vuint32_t TOM3_CH10_IRQ:1;       /* TOM3 channel 10 shared interrupt. */
      vuint32_t TOM3_CH9_IRQ:1;        /* TOM3 channel 9 shared interrupt. */
      vuint32_t TOM3_CH8_IRQ:1;        /* TOM3 channel 8 shared interrupt. */
      vuint32_t TOM3_CH7_IRQ:1;        /* TOM3 channel 7 shared interrupt. */
      vuint32_t TOM3_CH6_IRQ:1;        /* TOM3 channel 7 shared interrupt. */
      vuint32_t TOM3_CH5_IRQ:1;        /* TOM3 channel 5 shared interrupt. */
      vuint32_t TOM3_CH4_IRQ:1;        /* TOM3 channel 4 shared interrupt. */
      vuint32_t TOM3_CH3_IRQ:1;        /* TOM3 channel 3 shared interrupt. */
      vuint32_t TOM3_CH2_IRQ:1;        /* TOM3 channel 2 shared interrupt. */
      vuint32_t TOM3_CH1_IRQ:1;        /* TOM3 channel 1 shared interrupt. */
      vuint32_t TOM3_CH0_IRQ:1;        /* TOM3 channel 0 shared interrupt. */
      vuint32_t TOM2_CH15_IRQ:1;       /* TOM2 channel 15 shared interrupt. */
      vuint32_t TOM2_CH14_IRQ:1;       /* TOM2 channel 14 shared interrupt. */
      vuint32_t TOM2_CH13_IRQ:1;       /* TOM2 channel 13 shared interrupt. */
      vuint32_t TOM2_CH12_IRQ:1;       /* TOM2 channel 12 shared interrupt. */
      vuint32_t TOM2_CH11_IRQ:1;       /* TOM2 channel 11 shared interrupt. */
      vuint32_t TOM2_CH10_IRQ:1;       /* TOM2 channel 10 shared interrupt. */
      vuint32_t TOM2_CH9_IRQ:1;        /* TOM2 channel 9 shared interrupt. */
      vuint32_t TOM2_CH8_IRQ:1;        /* TOM2 channel 8 shared interrupt. */
      vuint32_t TOM2_CH7_IRQ:1;        /* TOM2 channel 7 shared interrupt. */
      vuint32_t TOM2_CH6_IRQ:1;        /* TOM2 channel 6 shared interrupt. */
      vuint32_t TOM2_CH5_IRQ:1;        /* TOM2 channel 5 shared interrupt. */
      vuint32_t TOM2_CH4_IRQ:1;        /* TOM2 channel 4 shared interrupt. */
      vuint32_t TOM2_CH3_IRQ:1;        /* TOM2 channel 3 shared interrupt. */
      vuint32_t TOM2_CH2_IRQ:1;        /* TOM2 channel 2 shared interrupt. */
      vuint32_t TOM2_CH1_IRQ:1;        /* TOM2 channel 1 shared interrupt */
      vuint32_t TOM2_CH0_IRQ:1;        /* TOM2 channel 0 shared interrupt. */
    } B;
  } IRQG_7;

  union {                              /* TOM Interrupt Group 2 Register */
    vuint32_t R;
    struct {
      vuint32_t TOM5_CH15_IRQ:1;       /* TOM5 channel 15 shared interrupt. */
      vuint32_t TOM5_CH14_IRQ:1;       /* TOM5 channel 14 shared interrupt. */
      vuint32_t TOM5_CH13_IRQ:1;       /* TOM5 channel 13 shared interrupt. */
      vuint32_t TOM5_CH12_IRQ:1;       /* TOM5 channel 12 shared interrupt. */
      vuint32_t TOM5_CH11_IRQ:1;       /* TOM5 channel 11 shared interrupt. */
      vuint32_t TOM5_CH10_IRQ:1;       /* TOM5 channel 10 shared interrupt. */
      vuint32_t TOM5_CH9_IRQ:1;        /* TOM5 channel 9 shared interrupt. */
      vuint32_t TOM5_CH8_IRQ:1;        /* TOM5 channel 8 shared interrupt. */
      vuint32_t TOM5_CH7_IRQ:1;        /* TOM5 channel 7 shared interrupt. */
      vuint32_t TOM5_CH6_IRQ:1;        /* TOM5 channel 6 shared interrupt. */
      vuint32_t TOM5_CH5_IRQ:1;        /* TOM5 channel 5 shared interrupt. */
      vuint32_t TOM5_CH4_IRQ:1;        /* TOM5 channel 4 shared interrupt. */
      vuint32_t TOM5_CH3_IRQ:1;        /* TOM5 channel 3 shared interrupt. */
      vuint32_t TOM5_CH2_IRQ:1;        /* TOM5 channel 2 shared interrupt. */
      vuint32_t TOM5_CH1_IRQ:1;        /* TOM5 channel 1 shared interrupt. */
      vuint32_t TOM5_CH0_IRQ:1;        /* TOM5 channel 0 shared interrupt. */
      vuint32_t TOM4_CH15_IRQ:1;       /* TOM4 channel 15 shared interrupt. */
      vuint32_t TOM4_CH14_IRQ:1;       /* TOM4 channel 14 shared interrupt. */
      vuint32_t TOM4_CH13_IRQ:1;       /* TOM4 channel 13 shared interrupt. */
      vuint32_t TOM4_CH12_IRQ:1;       /* TOM4 channel 12 shared interrupt. */
      vuint32_t TOM4_CH11_IRQ:1;       /* TOM4 channel 11 shared interrupt. */
      vuint32_t TOM4_CH10_IRQ:1;       /* TOM4 channel 10 shared interrupt. */
      vuint32_t TOM4_CH9_IRQ:1;        /* TOM4 channel 9 shared interrupt. */
      vuint32_t TOM4_CH8_IRQ:1;        /* TOM4 channel 8 shared interrupt. */
      vuint32_t TOM4_CH7_IRQ:1;        /* TOM4 channel 7 shared interrupt. */
      vuint32_t TOM4_CH6_IRQ:1;        /* TOM4 channel 6 shared interrupt. */
      vuint32_t TOM4_CH5_IRQ:1;        /* TOM4 channel 5 shared interrupt. */
      vuint32_t TOM4_CH4_IRQ:1;        /* TOM4 channel 4 shared interrupt. */
      vuint32_t TOM4_CH3_IRQ:1;        /* TOM4 channel 3 shared interrupt. */
      vuint32_t TOM4_CH2_IRQ:1;        /* TOM4 channel 2 shared interrupt. */
      vuint32_t TOM4_CH1_IRQ:1;        /* TOM4 channel 1 shared interrupt */
      vuint32_t TOM4_CH0_IRQ:1;        /* TOM4 channel 0 shared interrupt. */
    } B;
  } IRQG_8;

  union {                              /* ATOM Interrupt Group 0 Register */
    vuint32_t R;
    struct {
      vuint32_t ATOM3_CH7_IRQ:1;       /* ATOM3 channel 7 interrupt. */
      vuint32_t ATOM3_CH6_IRQ:1;       /* ATOM3 channel 6 interrupt. */
      vuint32_t ATOM3_CH5_IRQ:1;       /* ATOM3 channel 5 interrupt. */
      vuint32_t ATOM3_CH4_IRQ:1;       /* ATOM3 channel 4 interrupt. */
      vuint32_t ATOM3_CH3_IRQ:1;       /* ATOM3 channel 3 interrupt. */
      vuint32_t ATOM3_CH2_IRQ:1;       /* ATOM3 channel 2 interrupt. */
      vuint32_t ATOM3_CH1_IRQ:1;       /* ATOM3 channel 1 interrupt. */
      vuint32_t ATOM3_CH0_IRQ:1;       /* ATOM3 channel 0 interrupt. */
      vuint32_t ATOM2_CH7_IRQ:1;       /* ATOM2 channel 7 interrupt. */
      vuint32_t ATOM2_CH6_IRQ:1;       /* ATOM2 channel 6 interrupt. */
      vuint32_t ATOM2_CH5_IRQ:1;       /* ATOM2 channel 5 interrupt. */
      vuint32_t ATOM2_CH4_IRQ:1;       /* ATOM2 channel 4 interrupt. */
      vuint32_t ATOM2_CH3_IRQ:1;       /* ATOM2 channel 3 interrupt. */
      vuint32_t ATOM2_CH2_IRQ:1;       /* ATOM2 channel 2 interrupt. */
      vuint32_t ATOM2_CH1_IRQ:1;       /* ATOM2 channel 1 interrupt. */
      vuint32_t ATOM2_CH0_IRQ:1;       /* ATOM2 channel 0 interrupt. */
      vuint32_t ATOM1_CH7_IRQ:1;       /* ATOM1 channel 7 interrupt. */
      vuint32_t ATOM1_CH6_IRQ:1;       /* ATOM1 channel 6 interrupt. */
      vuint32_t ATOM1_CH5_IRQ:1;       /* ATOM1 channel 5 interrupt. */
      vuint32_t ATOM1_CH4_IRQ:1;       /* ATOM1 channel 4 interrupt. */
      vuint32_t ATOM1_CH3_IRQ:1;       /* ATOM1 channel 3 interrupt. */
      vuint32_t ATOM1_CH2_IRQ:1;       /* ATOM1 channel 2 interrupt. */
      vuint32_t ATOM1_CH1_IRQ:1;       /* ATOM1 channel 1 interrupt. */
      vuint32_t ATOM1_CH0_IRQ:1;       /* ATOM1 channel 0 interrupt. */
      vuint32_t ATOM0_CH7_IRQ:1;       /* ATOM0 channel 7 interrupt. */
      vuint32_t ATOM0_CH6_IRQ:1;       /* ATOM0 channel 6 interrupt. */
      vuint32_t ATOM0_CH5_IRQ:1;       /* ATOM0 channel 5 interrupt. */
      vuint32_t ATOM0_CH4_IRQ:1;       /* ATOM0 channel 4 interrupt. */
      vuint32_t ATOM0_CH3_IRQ:1;       /* ATOM0 channel 3 interrupt. */
      vuint32_t ATOM0_CH2_IRQ:1;       /* ATOM0 channel 2 interrupt. */
      vuint32_t ATOM0_CH1_IRQ:1;       /* ATOM0 channel 1 interrupt. */
      vuint32_t ATOM0_CH0_IRQ:1;       /* ATOM0 channel 0 interrupt. */
    } B;
  } IRQG_9;

  union {                              /* ATOM Interrupt Group 1 Register */
    vuint32_t R;
    struct {
      vuint32_t ATOM7_CH7_IRQ:1;       /* ATOM7 channel 7 interrupt. */
      vuint32_t ATOM7_CH6_IRQ:1;       /* ATOM7 channel 6 interrupt. */
      vuint32_t ATOM7_CH5_IRQ:1;       /* ATOM7 channel 5 interrupt. */
      vuint32_t ATOM7_CH4_IRQ:1;       /* ATOM7 channel 4 interrupt. */
      vuint32_t ATOM7_CH3_IRQ:1;       /* ATOM7 channel 3 interrupt. */
      vuint32_t ATOM7_CH2_IRQ:1;       /* ATOM7 channel 2 interrupt. */
      vuint32_t ATOM7_CH1_IRQ:1;       /* ATOM7 channel 1 interrupt. */
      vuint32_t ATOM7_CH0_IRQ:1;       /* ATOM7 channel 0 interrupt. */
      vuint32_t ATOM6_CH7_IRQ:1;       /* ATOM6 channel 7 interrupt. */
      vuint32_t ATOM6_CH6_IRQ:1;       /* ATOM6 channel 6 interrupt. */
      vuint32_t ATOM6_CH5_IRQ:1;       /* ATOM6 channel 5 interrupt. */
      vuint32_t ATOM6_CH4_IRQ:1;       /* ATOM channel 4 interrupt. */
      vuint32_t ATOM6_CH3_IRQ:1;       /* ATOM6 channel 3 interrupt. */
      vuint32_t ATOM6_CH2_IRQ:1;       /* ATOM6 channel 2 interrupt. */
      vuint32_t ATOM6_CH1_IRQ:1;       /* ATOM6 channel 1 interrupt. */
      vuint32_t ATOM6_CH0_IRQ:1;       /* ATOM6 channel 0 interrupt. */
      vuint32_t ATOM5_CH7_IRQ:1;       /* ATOM5 channel 7 interrupt. */
      vuint32_t ATOM5_CH6_IRQ:1;       /* ATOM5 channel 6 interrupt. */
      vuint32_t ATOM5_CH5_IRQ:1;       /* ATOM5 channel 5 interrupt. */
      vuint32_t ATOM5_CH4_IRQ:1;       /* ATOM5 channel 4 interrupt. */
      vuint32_t ATOM5_CH3_IRQ:1;       /* ATOM5 channel 3 interrupt. */
      vuint32_t ATOM5_CH2_IRQ:1;       /* ATOM5 channel 2 interrupt. */
      vuint32_t ATOM5_CH1_IRQ:1;       /* ATOM5 channel 1 interrupt. */
      vuint32_t ATOM5_CH0_IRQ:1;       /* ATOM5 channel 0 interrupt. */
      vuint32_t ATOM4_CH7_IRQ:1;       /* ATOM4 channel 7 interrupt. */
      vuint32_t ATOM4_CH6_IRQ:1;       /* ATOM4 channel 6 interrupt. */
      vuint32_t ATOM4_CH5_IRQ:1;       /* ATOM4 channel 5 interrupt. */
      vuint32_t ATOM4_CH4_IRQ:1;       /* ATOM4 channel 4 interrupt. */
      vuint32_t ATOM4_CH3_IRQ:1;       /* ATOM4 channel 3 interrupt. */
      vuint32_t ATOM4_CH2_IRQ:1;       /* ATOM4 channel 2 interrupt. */
      vuint32_t ATOM4_CH1_IRQ:1;       /* ATOM4 channel 1 interrupt. */
      vuint32_t ATOM4_CH0_IRQ:1;       /* ATOM4 channel 0 interrupt. */
    } B;
  } IRQG_10;

  union {                              /* ATOM Interrupt Group 2 Register */
    vuint32_t R;
    struct {
      vuint32_t ATOM11_CH7_IRQ:1;      /* ATOM11 channel 7 interrupt. */
      vuint32_t ATOM11_CH6_IRQ:1;      /* ATOM11 channel 6 interrupt. */
      vuint32_t ATOM11_CH5_IRQ:1;      /* ATOM11 channel 5 interrupt. */
      vuint32_t ATOM11_CH4_IRQ:1;      /* ATOM11 channel 4 interrupt. */
      vuint32_t ATOM11_CH3_IRQ:1;      /* ATOM11 channel 3 interrupt. */
      vuint32_t ATOM11_CH2_IRQ:1;      /* ATOM11 channel 2 interrupt. */
      vuint32_t ATOM11_CH1_IRQ:1;      /* ATOM11 channel 1 interrupt. */
      vuint32_t ATOM11_CH0_IRQ:1;      /* ATOM11 channel 0 interrupt. */
      vuint32_t ATOM10_CH7_IRQ:1;      /* ATOM10 channel 7 interrupt. */
      vuint32_t ATOM10_CH6_IRQ:1;      /* ATOM10 channel 6 interrupt. */
      vuint32_t ATOM10_CH5_IRQ:1;      /* ATOM10 channel 5 interrupt. */
      vuint32_t ATOM10_CH4_IRQ:1;      /* ATOM10 channel 4 interrupt. */
      vuint32_t ATOM10_CH3_IRQ:1;      /* ATOM10 channel 3 interrupt. */
      vuint32_t ATOM10_CH2_IRQ:1;      /* ATOM10 channel 2 interrupt. */
      vuint32_t ATOM10_CH1_IRQ:1;      /* ATOM10 channel 1 interrupt. */
      vuint32_t ATOM10_CH0_IRQ:1;      /* ATOM10 channel 0 interrupt. */
      vuint32_t ATOM9_CH7_IRQ:1;       /* ATOM9 channel 7 interrupt. */
      vuint32_t ATOM9_CH6_IRQ:1;       /* ATOM9 channel 6 interrupt. */
      vuint32_t ATOM9_CH5_IRQ:1;       /* ATOM9 channel 5 interrupt. */
      vuint32_t ATOM9_CH4_IRQ:1;       /* ATOM9 channel 4 interrupt. */
      vuint32_t ATOM9_CH3_IRQ:1;       /* ATOM9 channel 3 interrupt. */
      vuint32_t ATOM9_CH2_IRQ:1;       /* ATOM9 channel 2 interrupt. */
      vuint32_t ATOM9_CH1_IRQ:1;       /* ATOM9 channel 1 interrupt. */
      vuint32_t ATOM9_CH0_IRQ:1;       /* ATOM9 channel 0 interrupt. */
      vuint32_t ATOM8_CH7_IRQ:1;       /* ATOM8 channel 7 interrupt. */
      vuint32_t ATOM8_CH6_IRQ:1;       /* ATOM8 channel 6 interrupt. */
      vuint32_t ATOM8_CH5_IRQ:1;       /* ATOM8 channel 5 interrupt. */
      vuint32_t ATOM8_CH4_IRQ:1;       /* ATOM8 channel 4 interrupt. */
      vuint32_t ATOM4_CH3_IR8:1;       /* ATOM8 channel 3 interrupt. */
      vuint32_t ATOM8_CH2_IRQ:1;       /* ATOM8 channel 2 interrupt. */
      vuint32_t ATOM8_CH1_IRQ:1;       /* ATOM8 channel 1 interrupt. */
      vuint32_t ATOM8_CH0_IRQ:1;       /* ATOM8 channel 0 interrupt. */
    } B;
  } IRQG_11;

  union {                              /* ICM IRQG Module Error Interrupt register */
    vuint32_t R;
    struct {
      vuint32_t  :6;
      vuint32_t DPLL_EIRQ:1;           /* DPLL error interrupt. */
      vuint32_t CMP_EIRQ:1;            /* CMP error interrupt. */
      vuint32_t SPE3_EIRQ:1;           /* SPE3 error interrupt. */
      vuint32_t SPE2_EIRQ:1;           /* SPE2 error interrupt. */
      vuint32_t SPE1_EIRQ:1;           /* SPE1 error interrupt. */
      vuint32_t SPE0_EIRQ:1;           /* SPE0 error interrupt. */
      vuint32_t  :1;
      vuint32_t MCS6_EIRQ:1;           /* MCS6 error interrupt. */
      vuint32_t MCS5_EIRQ:1;           /* MCS5 error interrupt. */
      vuint32_t MCS4_EIRQ:1;           /* MCS4 error interrupt. */
      vuint32_t MCS3_EIRQ:1;           /* MCS3 error interrupt. */
      vuint32_t MCS2_EIRQ:1;           /* MCS2 error interrupt. */
      vuint32_t MCS1_EIRQ:1;           /* MCS1 error interrupt */
      vuint32_t MCS0_EIRQ:1;           /* MCS0 error interrupt. */
      vuint32_t  :1;
      vuint32_t TIM6_EIRQ:1;           /* TIM6 error interrupt. */
      vuint32_t TIM5_EIRQ:1;           /* TIM5 error interrupt. */
      vuint32_t TIM4_EIRQ:1;           /* TIM4 error interrupt. */
      vuint32_t TIM3_EIRQ:1;           /* TIM3 error interrupt. */
      vuint32_t TIM2_EIRQ:1;           /* TIM2 error interrupt. */
      vuint32_t TIM1_EIRQ:1;           /* TIM1 error interrupt. */
      vuint32_t TIM0_EIRQ:1;           /* TIM0 error interrupt. */
      vuint32_t FIFO1_EIRQ:1;          /* FIFO1 error interrupt. */
      vuint32_t FIFO0_EIRQ:1;          /* FIFO0 error interrupt. */
      vuint32_t BRC_EIRQ:1;            /* BRC error interrupt. */
      vuint32_t GTM_EIRQ:1;            /* GTM Error interrupt request. */
    } B;
  } IRQG_MEI;

  union {                              /* ICM Channel Error Interrupt Request Group 0 register */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t FIFO1_CH7_EIRQ:1;      /* FIFO1 channel 7 error interrupt */
      vuint32_t FIFO1_CH6_EIRQ:1;      /* FIFO1 channel 6 error interrupt */
      vuint32_t FIFO1_CH5_EIRQ:1;      /* FIFO1 channel 5 error interrupt */
      vuint32_t FIFO1_CH4_EIRQ:1;      /* FIFO1 channel 4 error interrupt */
      vuint32_t FIFO1_CH3_EIRQ:1;      /* FIFO1 channel 3 error interrupt */
      vuint32_t FIFO1_CH2_EIRQ:1;      /* FIFO1 channel 2 error interrupt */
      vuint32_t FIFO1_CH1_EIRQ:1;      /* FIFO1 channel 1 error interrupt */
      vuint32_t FIFO1_CH0_EIRQ:1;      /* FIFO1 channel 0 error interrupt */
      vuint32_t FIFO0_CH7_EIRQ:1;      /* FIFO0 channel 7 error interrupt */
      vuint32_t FIFO0_CH6_EIRQ:1;      /* FIFO0 channel 6 error interrupt */
      vuint32_t FIFO0_CH5_EIRQ:1;      /* FIFO0 channel 5 error interrupt */
      vuint32_t FIFO0_CH4_EIRQ:1;      /* FIFO0 channel 4 error interrupt */
      vuint32_t FIFO0_CH3_EIRQ:1;      /* FIFO0 channel 3 error interrupt */
      vuint32_t FIFO0_CH2_EIRQ:1;      /* FIFO0 channel 2 error interrupt */
      vuint32_t FIFO0_CH1_EIRQ:1;      /* FIFO0 channel 1 error interrupt */
      vuint32_t FIFO0_CH0_EIRQ:1;      /* FIFO0 channel 0 error interrupt */
    } B;
  } IRQG_CEI0;

  union {                              /* Channel Error Interrupt Request Group 1 register */
    vuint32_t R;
    struct {
      vuint32_t TIM3_CH7_EIRQ:1;       /* TIM3 Channel 7 Error interrupt */
      vuint32_t TIM3_CH6_EIRQ:1;       /* TIM3 Channel 6 Error interrupt */
      vuint32_t TIM3_CH5_EIRQ:1;       /* TIM3 Channel 5 Error interrupt */
      vuint32_t TIM3_CH4_EIRQ:1;       /* TIM3 Channel 4 Error interrupt */
      vuint32_t TIM3_CH3_EIRQ:1;       /* TIM3 Channel 3 Error interrupt */
      vuint32_t TIM3_CH2_EIRQ:1;       /* TIM3 Channel 2 Error interrupt */
      vuint32_t TIM3_CH1_EIRQ:1;       /* TIM3 Channel 1 Error interrupt */
      vuint32_t TIM3_CH0_EIRQ:1;       /* TIM3 Channel 0 Error interrupt */
      vuint32_t TIM2_CH7_EIRQ:1;       /* TIM2 Channel 7 Error interrupt */
      vuint32_t TIM2_CH6_EIRQ:1;       /* TIM2 Channel 6 Error interrupt */
      vuint32_t TIM2_CH5_EIRQ:1;       /* TIM2 Channel 5 Error interrupt */
      vuint32_t TIM2_CH4_EIRQ:1;       /* TIM2 Channel 4 Error interrupt */
      vuint32_t TIM2_CH3_EIRQ:1;       /* TIM2 Channel 3 Error interrupt */
      vuint32_t TIM2_CH2_EIRQ:1;       /* TIM2 Channel 2 Error interrupt */
      vuint32_t TIM2_CH1_EIRQ:1;       /* TIM2 Channel 1 Error interrupt */
      vuint32_t TIM2_CH0_EIRQ:1;       /* TIM2 Channel 0 Error interrupt */
      vuint32_t TIM1_CH7_EIRQ:1;       /* TIM1 Channel 7 Error interrupt */
      vuint32_t TIM1_CH6_EIRQ:1;       /* TIM1 Channel 6 Error interrupt */
      vuint32_t TIM1_CH5_EIRQ:1;       /* TIM1 Channel 5 Error interrupt */
      vuint32_t TIM1_CH4_EIRQ:1;       /* TIM1 Channel 4 Error interrupt */
      vuint32_t TIM1_CH3_EIRQ:1;       /* TIM1 Channel 3 Error interrupt */
      vuint32_t TIM1_CH2_EIRQ:1;       /* TIM1 Channel 2 Error interrupt */
      vuint32_t TIM1_CH1_EIRQ:1;       /* TIM1 Channel 1 Error interrupt */
      vuint32_t TIM1_CH0_EIRQ:1;       /* TIM1 Channel 0 Error interrupt */
      vuint32_t TIM0_CH7_EIRQ:1;       /* TIM0 Channel 7 Error interrupt */
      vuint32_t TIM0_CH6_EIRQ:1;       /* TIM0 Channel 6 Error interrupt */
      vuint32_t TIM0_CH5_EIRQ:1;       /* TIM0 Channel 5 Error interrupt */
      vuint32_t TIM0_CH4_EIRQ:1;       /* TIM0 Channel 4 Error interrupt */
      vuint32_t TIM0_CH3_EIRQ:1;       /* TIM0 Channel 3 Error interrupt */
      vuint32_t TIM0_CH2_EIRQ:1;       /* TIM0 Channel 2 Error interrupt */
      vuint32_t TIM0_CH1_EIRQ:1;       /* TIM0 Channel 1 Error interrupt */
      vuint32_t TIM0_CH0_EIRQ:1;       /* TIM0 Channel 0 Error interrupt */
    } B;
  } IRQG_CEI1;

  union {                              /* Channel Error Interrupt Request Group 2 register */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t TIM6_CH7_EIRQ:1;       /* TIM6 Channel 7 Error interrupt */
      vuint32_t TIM6_CH6_EIRQ:1;       /* TIM6 Channel 6 Error interrupt */
      vuint32_t TIM6_CH5_EIRQ:1;       /* TIM6 Channel 5 Error interrupt */
      vuint32_t TIM6_CH4_EIRQ:1;       /* TIM6 Channel 4 Error interrupt */
      vuint32_t TIM6_CH3_EIRQ:1;       /* TIM6 Channel 3 Error interrupt */
      vuint32_t TIM6_CH2_EIRQ:1;       /* TIM6 Channel 2 Error interrupt */
      vuint32_t TIM6_CH1_EIRQ:1;       /* TIM6 Channel 1 Error interrupt */
      vuint32_t TIM6_CH0_EIRQ:1;       /* TIM6 Channel 0 Error interrupt */
      vuint32_t TIM5_CH7_EIRQ:1;       /* TIM5 Channel 7 Error interrupt */
      vuint32_t TIM5_CH6_EIRQ:1;       /* TIM5 Channel 6 Error interrupt */
      vuint32_t TIM5_CH5_EIRQ:1;       /* TIM5 Channel 5 Error interrupt */
      vuint32_t TIM5_CH4_EIRQ:1;       /* TIM5 Channel 4 Error interrupt */
      vuint32_t TIM5_CH3_EIRQ:1;       /* TIM5 Channel 3 Error interrupt */
      vuint32_t TIM5_CH2_EIRQ:1;       /* TIM5 Channel 2 Error interrupt */
      vuint32_t TIM5_CH1_EIRQ:1;       /* TIM5 Channel 1 Error interrupt */
      vuint32_t TIM5_CH0_EIRQ:1;       /* TIM5 Channel 0 Error interrupt */
      vuint32_t TIM4_CH7_EIRQ:1;       /* TIM4 Channel 7 Error interrupt */
      vuint32_t TIM4_CH6_EIRQ:1;       /* TIM4 Channel 6 Error interrupt */
      vuint32_t TIM4_CH5_EIRQ:1;       /* TIM4 Channel 5 Error interrupt */
      vuint32_t TIM4_CH4_EIRQ:1;       /* TIM4 Channel 4 Error interrupt */
      vuint32_t TIM4_CH3_EIRQ:1;       /* TIM4 Channel 3 Error interrupt */
      vuint32_t TIM4_CH2_EIRQ:1;       /* TIM4 Channel 2 Error interrupt */
      vuint32_t TIM4_CH1_EIRQ:1;       /* TIM4 Channel 1 Error interrupt */
      vuint32_t TIM4_CH0_EIRQ:1;       /* TIM4 Channel 0 Error interrupt */
    } B;
  } IRQG_CEI2;

  union {                              /* Channel Error Interrupt Request Group 3 register */
    vuint32_t R;
    struct {
      vuint32_t MCS3_CH7_EIRQ:1;       /* MCS3 Channel 7 error interrupt */
      vuint32_t MCS3_CH6_EIRQ:1;       /* MCS3 Channel 6 error interrupt */
      vuint32_t MCS3_CH5_EIRQ:1;       /* MCS3 Channel 5 error interrupt */
      vuint32_t MCS3_CH4_EIRQ:1;       /* MCS3 Channel 4 error interrupt */
      vuint32_t MCS3_CH3_EIRQ:1;       /* MCS3 Channel 3 error interrupt */
      vuint32_t MCS3_CH2_EIRQ:1;       /* MCS3 Channel 2 error interrupt */
      vuint32_t MCS3_CH1_EIRQ:1;       /* MCS3 Channel 1 error interrupt */
      vuint32_t MCS3_CH0_EIRQ:1;       /* MCS3 Channel 0 error interrupt */
      vuint32_t MCS2_CH7_EIRQ:1;       /* MCS2 Channel 7 error interrupt */
      vuint32_t MCS2_CH6_EIRQ:1;       /* MCS2 Channel 6 error interrupt */
      vuint32_t MCS2_CH5_EIRQ:1;       /* MCS2 Channel 5 error interrupt */
      vuint32_t MCS2_CH4_EIRQ:1;       /* MCS2 Channel 4 error interrupt */
      vuint32_t MCS2_CH3_EIRQ:1;       /* MCS2 Channel 3 error interrupt */
      vuint32_t MCS2_CH2_EIRQ:1;       /* MCS2 Channel 2 error interrupt */
      vuint32_t MCS2_CH1_EIRQ:1;       /* MCS2 Channel 1 error interrupt */
      vuint32_t MCS2_CH0_EIRQ:1;       /* MCS2 Channel 0 error interrupt */
      vuint32_t MCS1_CH7_EIRQ:1;       /* MCS1 Channel 7 error interrupt */
      vuint32_t MCS1_CH6_EIRQ:1;       /* MCS1 Channel 6 error interrupt */
      vuint32_t MCS1_CH5_EIRQ:1;       /* MCS1 Channel 5 error interrupt */
      vuint32_t MCS1_CH4_EIRQ:1;       /* MCS1 Channel 4 error interrupt */
      vuint32_t MCS1_CH3_EIRQ:1;       /* MCS1 Channel 3 error interrupt */
      vuint32_t MCS1_CH2_EIRQ:1;       /* MCS1 Channel 2 error interrupt */
      vuint32_t MCS1_CH1_EIRQ:1;       /* MCS1 Channel 1 error interrupt */
      vuint32_t MCS1_CH0_EIRQ:1;       /* MCS1 Channel 0 error interrupt */
      vuint32_t MCS0_CH7_EIRQ:1;       /* MCS0 Channel 7 error interrupt */
      vuint32_t MCS0_CH6_EIRQ:1;       /* MCS0 Channel 6 error interrupt */
      vuint32_t MCS0_CH5_EIRQ:1;       /* MCS0 Channel 5 error interrupt */
      vuint32_t MCS0_CH4_EIRQ:1;       /* MCS0 Channel 4 error interrupt */
      vuint32_t MCS0_CH3_EIRQ:1;       /* MCS0 Channel 3 error interrupt */
      vuint32_t MCS0_CH2_EIRQ:1;       /* MCS0 Channel 2 error interrupt */
      vuint32_t MCS0_CH1_EIRQ:1;       /* MCS0 Channel 1 error interrupt */
      vuint32_t MCS0_CH0_EIRQ:1;       /* MCS0 Channel 0 error interrupt */
    } B;
  } IRQG_CEI3;

  union {                              /* Channel Error Interrupt Request Group 4 register */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t MCS6_CH7_EIRQ:1;       /* MCS6 Channel 7 error interrupt */
      vuint32_t MCS6_CH6_EIRQ:1;       /* MCS6 Channel 6 error interrupt */
      vuint32_t MCS6_CH5_EIRQ:1;       /* MCS6 Channel 5 error interrupt */
      vuint32_t MCS6_CH4_EIRQ:1;       /* MCS6 Channel 4 error interrupt */
      vuint32_t MCS6_CH3_EIRQ:1;       /* MCS6 Channel 3 error interrupt */
      vuint32_t MCS6_CH2_EIRQ:1;       /* MCS6 Channel 2 error interrupt */
      vuint32_t MCS6_CH1_EIRQ:1;       /* MCS6 Channel 1 error interrupt */
      vuint32_t MCS6_CH0_EIRQ:1;       /* MCS6 Channel 0 error interrupt */
      vuint32_t MCS5_CH7_EIRQ:1;       /* MCS5 Channel 7 error interrupt */
      vuint32_t MCS5_CH6_EIRQ:1;       /* MCS5 Channel 6 error interrupt */
      vuint32_t MCS5_CH5_EIRQ:1;       /* MCS5 Channel 5 error interrupt */
      vuint32_t MCS5_CH4_EIRQ:1;       /* MCS5 Channel 4 error interrupt */
      vuint32_t MCS5_CH3_EIRQ:1;       /* MCS5 Channel 3 error interrupt */
      vuint32_t MCS5_CH2_EIRQ:1;       /* MCS5 Channel 2 error interrupt */
      vuint32_t MCS5_CH1_EIRQ:1;       /* MCS5 Channel 1 error interrupt */
      vuint32_t MCS5_CH0_EIRQ:1;       /* MCS5 Channel 0 error interrupt */
      vuint32_t MCS4_CH7_EIRQ:1;       /* MCS4 Channel 7 error interrupt */
      vuint32_t MCS4_CH6_EIRQ:1;       /* MCS4 Channel 6 error interrupt */
      vuint32_t MCS4_CH5_EIRQ:1;       /* MCS4 Channel 5 error interrupt */
      vuint32_t MCS4_CH4_EIRQ:1;       /* MCS4 Channel 4 error interrupt */
      vuint32_t MCS4_CH3_EIRQ:1;       /* MCS4 Channel 3 error interrupt */
      vuint32_t MCS4_CH2_EIRQ:1;       /* MCS4 Channel 2 error interrupt */
      vuint32_t MCS4_CH1_EIRQ:1;       /* MCS4 Channel 1 error interrupt */
      vuint32_t MCS4_CH0_EIRQ:1;       /* MCS4 Channel 0 error interrupt */
    } B;
  } IRQG_CEI4;
};


/* ============================================================================
   =============================== Module: GTM_MAP ============================
   ============================================================================ */

struct GTM_MAP_tag {
  union {                              /* TIM0 Input MAP Control Register */
    vuint32_t R;
    struct {
      vuint32_t  :1;
      vuint32_t TSPP1_I2V:1;           /* Disable of TSPP1 TIM0_CHz(48) input line. */
      vuint32_t TSPP1_I1V:1;           /* Disable of TSPP1 TIM0_CHy(48) input line. */
      vuint32_t TSPP1_I0V:1;           /* Disable of TSPP1 TIM0_CHx(48) input line. */
      vuint32_t  :2;
      vuint32_t TSPP1_DLD:1;           /* DIR level definition bit. */
      vuint32_t TSPP1_EN:1;            /* Enable of TSPP1 subunit. */
      vuint32_t  :1;
      vuint32_t TSPP0_I2V:1;           /* Disable of TSPP0 TIM0_CHz(48) input line. */
      vuint32_t TSPP0_I1V:1;           /* Disable of TSPP0 TIM0_CHy(48) input line. */
      vuint32_t TSPP0_I0V:1;           /* Disable of TSPP0 TIM0_CHx(48) input line. */
      vuint32_t  :2;
      vuint32_t TSPP0_DLD:1;           /* DIR level definition bit. */
      vuint32_t TSPP0_EN:1;            /* Enable of TSPP0 subunit. */
      vuint32_t  :11;
      vuint32_t LSEL:1;                /* TIM0_IN6 input level selection. */
      vuint32_t SSL:3;                 /* STATE signal output select. */
      vuint32_t TSEL:1;                /* TRIGGER signal output select. */
    } B;
  } CTRL;
};


/* ============================================================================
   =============================== Module: GTM_MCFG ===========================
   ============================================================================ */

struct GTM_MCFG_tag {
  union {                              /* Memory Configuration Register */
    vuint32_t R;
    struct {
      vuint32_t  :18;
      vuint32_t MEM6:2;                /* Configure Memory pages for MCS-instance MCS6. */
      vuint32_t MEM5:2;                /* Configure Memory pages for MCS-instance MCS5. */
      vuint32_t MEM4:2;                /* Configure Memory pages for MCS-instance MCS4. */
      vuint32_t MEM3:2;                /* Configure Memory pages for MCS-instance MCS3 */
      vuint32_t MEM2:2;                /* Configure Memory pages for MCS-instance MCS2 */
      vuint32_t MEM1:2;                /* Configure Memory pages for MCS-instance MCS1. */
      vuint32_t MEM0:2;                /* Configure Memory pages for MCS-instance MCS0. */
    } B;
  } CTRL;
};


/* ============================================================================
   =============================== Module: GTM_MCS ============================
   ============================================================================ */

struct GTM_MCS_tag {
  union {                              /* MCS Channel n General Purpose 0 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R0. */
    } B;
  } CH0_R0;

  union {                              /* MCS Channel n General Purpose 1 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R1. */
    } B;
  } CH0_R1;

  union {                              /* MCS Channel n General Purpose 2 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R2. */
    } B;
  } CH0_R2;

  union {                              /* MCS Channel n General Purpose 3 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R3. */
    } B;
  } CH0_R3;

  union {                              /* MCS Channel n General Purpose 4 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R4. */
    } B;
  } CH0_R4;

  union {                              /* MCS Channel n General Purpose 5 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R5. */
    } B;
  } CH0_R5;

  union {                              /* MCS Channel n General Purpose 6 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R6. */
    } B;
  } CH0_R6;

  union {                              /* MCS Channel n General Purpose 7 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R7. */
    } B;
  } CH0_R7;

  union {                              /* MCS Channel n Control Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :13;
      vuint32_t SP_CNT:3;              /* Stack pointer counter value. */
      vuint32_t  :5;
      vuint32_t SAT:1;                 /* Successful ARU transfer bit. */
      vuint32_t CWT:1;                 /* Cancel WURM instruction state. */
      vuint32_t CAT:1;                 /* Cancel ARU transfer state. */
      vuint32_t N:1;                   /* Negative bit state. */
      vuint32_t V:1;                   /* Overflow bit state. */
      vuint32_t Z:1;                   /* Zero bit state. */
      vuint32_t CY:1;                  /* Carry bit state. */
      vuint32_t  :1;
      vuint32_t ERR:1;                 /* Error state. */
      vuint32_t IRQ:1;                 /* Interrupt state. */
      vuint32_t EN:1;                  /* Enable MCS-channel. */
    } B;
  } CH0_CTRL;

  union {                              /* MCS Channel n ARU Control Bit Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :27;
      vuint32_t ACB4:1;                /* See ACB0. */
      vuint32_t ACB3:1;                /* See ACB0. */
      vuint32_t ACB2:1;                /* See ACB0. */
      vuint32_t ACB1:1;                /* See ACB0. */
      vuint32_t ACB0:1;                /* ARU Control bit[4:0]. */
    } B;
  } CH0_ACB;

  union {                              /* MCS Clear Trigger Control Register */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t TRG15:1;               /* Trigger bit. */
      vuint32_t TRG14:1;               /* Trigger bit. */
      vuint32_t TRG13:1;               /* Trigger bit. */
      vuint32_t TRG12:1;               /* Trigger bit. */
      vuint32_t TRG11:1;               /* Trigger bit. */
      vuint32_t TRG10:1;               /* Trigger bit. */
      vuint32_t TRG9:1;                /* Trigger bit. */
      vuint32_t TRG8:1;                /* Trigger bit. */
      vuint32_t TRG7:1;                /* Trigger bit. */
      vuint32_t TRG6:1;                /* Trigger bit. */
      vuint32_t TRG5:1;                /* Trigger bit. */
      vuint32_t TRG4:1;                /* Trigger bit. */
      vuint32_t TRG3:1;                /* Trigger bit. */
      vuint32_t TRG2:1;                /* Trigger bit. */
      vuint32_t TRG1:1;                /* Trigger bit. */
      vuint32_t TRG0:1;                /* Trigger bit. */
    } B;
  } CTRG;

  union {                              /* MCS Set Trigger Control Register */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t TRG15:1;               /* Trigger bit. */
      vuint32_t TRG14:1;               /* Trigger bit. */
      vuint32_t TRG13:1;               /* Trigger bit. */
      vuint32_t TRG12:1;               /* Trigger bit. */
      vuint32_t TRG11:1;               /* Trigger bit. */
      vuint32_t TRG10:1;               /* Trigger bit. */
      vuint32_t TRG9:1;                /* Trigger bit. */
      vuint32_t TRG8:1;                /* Trigger bit. */
      vuint32_t TRG7:1;                /* Trigger bit. */
      vuint32_t TRG6:1;                /* Trigger bit. */
      vuint32_t TRG5:1;                /* Trigger bit. */
      vuint32_t TRG4:1;                /* Trigger bit. */
      vuint32_t TRG3:1;                /* Trigger bit. */
      vuint32_t TRG2:1;                /* Trigger bit. */
      vuint32_t TRG1:1;                /* Trigger bit. */
      vuint32_t TRG0:1;                /* Trigger bit. */
    } B;
  } STRG;

  uint8_t MCS_reserved0[16];
  union {                              /* MCS Channel n Program Counter Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :18;
      vuint32_t PC:14;                 /* Current Program Counter. */
    } B;
  } CH0_PC;

  union {                              /* MCS Channel n Interrupt Request Notification Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_IRQ:1;         /* Memory access out of range in channel n. */
      vuint32_t STK_ERR_IRQ:1;         /* Stack counter overflow/underflow of channel n. */
      vuint32_t MCS_IRQ:1;             /* Interrupt request by MCS-channel n. */
    } B;
  } CH0_IRQ_NOTIFY;

  union {                              /* MCS Channel n Interrupt Request Enable Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_IRQ_EN:1;      /* MCS channel n MEM_ERR_IRQ interrupt enable. */
      vuint32_t STK_ERR_IRQ_EN:1;      /* MCS channel n STK_ERR_IRQ interrupt enable. */
      vuint32_t MCS_IRQ_EN:1;          /* MCS channel n MCS_IRQ interrupt enable. */
    } B;
  } CH0_IRQ_EN;

  union {                              /* MCS Channel n Force Interrupt Request Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t TRG_MEM_ERR_IRQ:1;     /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register by software. */
      vuint32_t TRG_STK_ERR_IRQ:1;     /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register by software. */
      vuint32_t TRG_MCS_IRQ:1;         /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register */
    } B;
  } CH0_IRQ_FORCINT;

  union {                              /* MCS Channel n Interrupt Request Mode Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH0_IRQ_MODE;

  union {                              /* MCS Channel n Error Interrupt Request Enable register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_EIRQ_EN:1;     /* MCS[i] channel n MEM_ERR_EIRQ error interrupt enable. */
      vuint32_t STK_ERR_EIRQ_EN:1;     /* MCS[i] channel n STK_ERR_IRQ error interrupt enable. */
      vuint32_t MCS_EIRQ_EN:1;         /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register */
    } B;
  } CH0_EIRQ_EN;

  uint8_t MCS_reserved1[28];
  union {                              /* MCS Control Register */
    vuint32_t R;
    struct {
      vuint32_t  :15;
      vuint32_t RAM_RST:1;             /* RAM reset bit. */
      vuint32_t  :14;
      vuint32_t HLT_SP_OFL:1;          /* Halt on stack pointer overflow. */
      vuint32_t SCHED:1;               /* MCS submodule scheduling scheme. */
    } B;
  } CTRL;

  union {                              /* MCS Reset Register */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CWT7:1;                /* Cancel WURM instruction for channel. */
      vuint32_t CWT6:1;                /* Cancel WURM instruction for channel. */
      vuint32_t CWT5:1;                /* Cancel WURM instruction for channel. */
      vuint32_t CWT4:1;                /* Cancel WURM instruction for channel. */
      vuint32_t CWT3:1;                /* Cancel WURM instruction for channel. */
      vuint32_t CWT2:1;                /* Cancel WURM instruction for channel. */
      vuint32_t CWT1:1;                /* Cancel WURM instruction for channel. */
      vuint32_t CWT0:1;                /* Cancel WURM instruction for channel. */
      vuint32_t CAT7:1;                /* Cancel ARU transfer for channel. */
      vuint32_t CAT6:1;                /* Cancel ARU transfer for channel. */
      vuint32_t CAT5:1;                /* Cancel ARU transfer for channel. */
      vuint32_t CAT4:1;                /* Cancel ARU transfer for channel. */
      vuint32_t CAT3:1;                /* Cancel ARU transfer for channel. */
      vuint32_t CAT2:1;                /* Cancel ARU transfer for channel. */
      vuint32_t CAT1:1;                /* Cancel ARU transfer for channel. */
      vuint32_t CAT0:1;                /* Cancel ARU transfer for channel. */
      vuint32_t RST7:1;                /* Software reset of channel. */
      vuint32_t RST6:1;                /* Software reset of channel. */
      vuint32_t RST5:1;                /* Software reset of channel. */
      vuint32_t RST4:1;                /* Software reset of channel. */
      vuint32_t RST3:1;                /* Software reset of channel. */
      vuint32_t RST2:1;                /* Software reset of channel. */
      vuint32_t RST1:1;                /* Software reset of channel. */
      vuint32_t RST0:1;                /* Software reset of channel. */
    } B;
  } RST;

  union {                              /* MCS Error Register */
    vuint32_t R;
    struct {
      vuint32_t  :24;
      vuint32_t ERR7:1;                /* Error State of MCS-channel. */
      vuint32_t ERR6:1;                /* Error State of MCS-channel. */
      vuint32_t ERR5:1;                /* Error State of MCS-channel. */
      vuint32_t ERR4:1;                /* Error State of MCS-channel. */
      vuint32_t ERR3:1;                /* Error State of MCS-channel. */
      vuint32_t ERR2:1;                /* Error State of MCS-channel. */
      vuint32_t ERR1:1;                /* Error State of MCS-channel. */
      vuint32_t ERR0:1;                /* Error State of MCS-channel. */
    } B;
  } ERR;

  union {                              /* MCS Channel n General Purpose 0 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R0. */
    } B;
  } CH1_R0;

  union {                              /* MCS Channel n General Purpose 1 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R1. */
    } B;
  } CH1_R1;

  union {                              /* MCS Channel n General Purpose 2 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R2. */
    } B;
  } CH1_R2;

  union {                              /* MCS Channel n General Purpose 3 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R3. */
    } B;
  } CH1_R3;

  union {                              /* MCS Channel n General Purpose 4 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R4. */
    } B;
  } CH1_R4;

  union {                              /* MCS Channel n General Purpose 5 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R5. */
    } B;
  } CH1_R5;

  union {                              /* MCS Channel n General Purpose 6 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R6. */
    } B;
  } CH1_R6;

  union {                              /* MCS Channel n General Purpose 7 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R7. */
    } B;
  } CH1_R7;

  union {                              /* MCS Channel n Control Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :13;
      vuint32_t SP_CNT:3;              /* Stack pointer counter value. */
      vuint32_t  :5;
      vuint32_t SAT:1;                 /* Successful ARU transfer bit. */
      vuint32_t CWT:1;                 /* Cancel WURM instruction state. */
      vuint32_t CAT:1;                 /* Cancel ARU transfer state. */
      vuint32_t N:1;                   /* Negative bit state. */
      vuint32_t V:1;                   /* Overflow bit state. */
      vuint32_t Z:1;                   /* Zero bit state. */
      vuint32_t CY:1;                  /* Carry bit state. */
      vuint32_t  :1;
      vuint32_t ERR:1;                 /* Error state. */
      vuint32_t IRQ:1;                 /* Interrupt state. */
      vuint32_t EN:1;                  /* Enable MCS-channel. */
    } B;
  } CH1_CTRL;

  union {                              /* MCS Channel n ARU Control Bit Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :27;
      vuint32_t ACB4:1;                /* See ACB0. */
      vuint32_t ACB3:1;                /* See ACB0. */
      vuint32_t ACB2:1;                /* See ACB0. */
      vuint32_t ACB1:1;                /* See ACB0. */
      vuint32_t ACB0:1;                /* ARU Control bit[4:0]. */
    } B;
  } CH1_ACB;

  uint8_t MCS_reserved2[24];
  union {                              /* MCS Channel n Program Counter Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :18;
      vuint32_t PC:14;                 /* Current Program Counter. */
    } B;
  } CH1_PC;

  union {                              /* MCS Channel n Interrupt Request Notification Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_IRQ:1;         /* Memory access out of range in channel n. */
      vuint32_t STK_ERR_IRQ:1;         /* Stack counter overflow/underflow of channel n. */
      vuint32_t MCS_IRQ:1;             /* Interrupt request by MCS-channel n. */
    } B;
  } CH1_IRQ_NOTIFY;

  union {                              /* MCS Channel n Interrupt Request Enable Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_IRQ_EN:1;      /* MCS channel n MEM_ERR_IRQ interrupt enable. */
      vuint32_t STK_ERR_IRQ_EN:1;      /* MCS channel n STK_ERR_IRQ interrupt enable. */
      vuint32_t MCS_IRQ_EN:1;          /* MCS channel n MCS_IRQ interrupt enable. */
    } B;
  } CH1_IRQ_EN;

  union {                              /* MCS Channel n Force Interrupt Request Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t TRG_MEM_ERR_IRQ:1;     /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register by software. */
      vuint32_t TRG_STK_ERR_IRQ:1;     /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register by software. */
      vuint32_t TRG_MCS_IRQ:1;         /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register */
    } B;
  } CH1_IRQ_FORCINT;

  union {                              /* MCS Channel n Interrupt Request Mode Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH1_IRQ_MODE;

  union {                              /* MCS Channel n Error Interrupt Request Enable register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_EIRQ_EN:1;     /* MCS[i] channel n MEM_ERR_EIRQ error interrupt enable. */
      vuint32_t STK_ERR_EIRQ_EN:1;     /* MCS[i] channel n STK_ERR_IRQ error interrupt enable. */
      vuint32_t MCS_EIRQ_EN:1;         /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register */
    } B;
  } CH1_EIRQ_EN;

  uint8_t MCS_reserved3[40];
  union {                              /* MCS Channel n General Purpose 0 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R0. */
    } B;
  } CH2_R0;

  union {                              /* MCS Channel n General Purpose 1 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R1. */
    } B;
  } CH2_R1;

  union {                              /* MCS Channel n General Purpose 2 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R2. */
    } B;
  } CH2_R2;

  union {                              /* MCS Channel n General Purpose 3 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R3. */
    } B;
  } CH2_R3;

  union {                              /* MCS Channel n General Purpose 4 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R4. */
    } B;
  } CH2_R4;

  union {                              /* MCS Channel n General Purpose 5 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R5. */
    } B;
  } CH2_R5;

  union {                              /* MCS Channel n General Purpose 6 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R6. */
    } B;
  } CH2_R6;

  union {                              /* MCS Channel n General Purpose 7 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R7. */
    } B;
  } CH2_R7;

  union {                              /* MCS Channel n Control Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :13;
      vuint32_t SP_CNT:3;              /* Stack pointer counter value. */
      vuint32_t  :5;
      vuint32_t SAT:1;                 /* Successful ARU transfer bit. */
      vuint32_t CWT:1;                 /* Cancel WURM instruction state. */
      vuint32_t CAT:1;                 /* Cancel ARU transfer state. */
      vuint32_t N:1;                   /* Negative bit state. */
      vuint32_t V:1;                   /* Overflow bit state. */
      vuint32_t Z:1;                   /* Zero bit state. */
      vuint32_t CY:1;                  /* Carry bit state. */
      vuint32_t  :1;
      vuint32_t ERR:1;                 /* Error state. */
      vuint32_t IRQ:1;                 /* Interrupt state. */
      vuint32_t EN:1;                  /* Enable MCS-channel. */
    } B;
  } CH2_CTRL;

  union {                              /* MCS Channel n ARU Control Bit Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :27;
      vuint32_t ACB4:1;                /* See ACB0. */
      vuint32_t ACB3:1;                /* See ACB0. */
      vuint32_t ACB2:1;                /* See ACB0. */
      vuint32_t ACB1:1;                /* See ACB0. */
      vuint32_t ACB0:1;                /* ARU Control bit[4:0]. */
    } B;
  } CH2_ACB;

  uint8_t MCS_reserved4[24];
  union {                              /* MCS Channel n Program Counter Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :18;
      vuint32_t PC:14;                 /* Current Program Counter. */
    } B;
  } CH2_PC;

  union {                              /* MCS Channel n Interrupt Request Notification Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_IRQ:1;         /* Memory access out of range in channel n. */
      vuint32_t STK_ERR_IRQ:1;         /* Stack counter overflow/underflow of channel n. */
      vuint32_t MCS_IRQ:1;             /* Interrupt request by MCS-channel n. */
    } B;
  } CH2_IRQ_NOTIFY;

  union {                              /* MCS Channel n Interrupt Request Enable Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_IRQ_EN:1;      /* MCS channel n MEM_ERR_IRQ interrupt enable. */
      vuint32_t STK_ERR_IRQ_EN:1;      /* MCS channel n STK_ERR_IRQ interrupt enable. */
      vuint32_t MCS_IRQ_EN:1;          /* MCS channel n MCS_IRQ interrupt enable. */
    } B;
  } CH2_IRQ_EN;

  union {                              /* MCS Channel n Force Interrupt Request Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t TRG_MEM_ERR_IRQ:1;     /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register by software. */
      vuint32_t TRG_STK_ERR_IRQ:1;     /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register by software. */
      vuint32_t TRG_MCS_IRQ:1;         /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register */
    } B;
  } CH2_IRQ_FORCINT;

  union {                              /* MCS Channel n Interrupt Request Mode Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH2_IRQ_MODE;

  union {                              /* MCS Channel n Error Interrupt Request Enable register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_EIRQ_EN:1;     /* MCS[i] channel n MEM_ERR_EIRQ error interrupt enable. */
      vuint32_t STK_ERR_EIRQ_EN:1;     /* MCS[i] channel n STK_ERR_IRQ error interrupt enable. */
      vuint32_t MCS_EIRQ_EN:1;         /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register */
    } B;
  } CH2_EIRQ_EN;

  uint8_t MCS_reserved5[40];
  union {                              /* MCS Channel n General Purpose 0 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R0. */
    } B;
  } CH3_R0;

  union {                              /* MCS Channel n General Purpose 1 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R1. */
    } B;
  } CH3_R1;

  union {                              /* MCS Channel n General Purpose 2 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R2. */
    } B;
  } CH3_R2;

  union {                              /* MCS Channel n General Purpose 3 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R3. */
    } B;
  } CH3_R3;

  union {                              /* MCS Channel n General Purpose 4 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R4. */
    } B;
  } CH3_R4;

  union {                              /* MCS Channel n General Purpose 5 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R5. */
    } B;
  } CH3_R5;

  union {                              /* MCS Channel n General Purpose 6 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R6. */
    } B;
  } CH3_R6;

  union {                              /* MCS Channel n General Purpose 7 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R7. */
    } B;
  } CH3_R7;

  union {                              /* MCS Channel n Control Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :13;
      vuint32_t SP_CNT:3;              /* Stack pointer counter value. */
      vuint32_t  :5;
      vuint32_t SAT:1;                 /* Successful ARU transfer bit. */
      vuint32_t CWT:1;                 /* Cancel WURM instruction state. */
      vuint32_t CAT:1;                 /* Cancel ARU transfer state. */
      vuint32_t N:1;                   /* Negative bit state. */
      vuint32_t V:1;                   /* Overflow bit state. */
      vuint32_t Z:1;                   /* Zero bit state. */
      vuint32_t CY:1;                  /* Carry bit state. */
      vuint32_t  :1;
      vuint32_t ERR:1;                 /* Error state. */
      vuint32_t IRQ:1;                 /* Interrupt state. */
      vuint32_t EN:1;                  /* Enable MCS-channel. */
    } B;
  } CH3_CTRL;

  union {                              /* MCS Channel n ARU Control Bit Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :27;
      vuint32_t ACB4:1;                /* See ACB0. */
      vuint32_t ACB3:1;                /* See ACB0. */
      vuint32_t ACB2:1;                /* See ACB0. */
      vuint32_t ACB1:1;                /* See ACB0. */
      vuint32_t ACB0:1;                /* ARU Control bit[4:0]. */
    } B;
  } CH3_ACB;

  uint8_t MCS_reserved6[24];
  union {                              /* MCS Channel n Program Counter Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :18;
      vuint32_t PC:14;                 /* Current Program Counter. */
    } B;
  } CH3_PC;

  union {                              /* MCS Channel n Interrupt Request Notification Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_IRQ:1;         /* Memory access out of range in channel n. */
      vuint32_t STK_ERR_IRQ:1;         /* Stack counter overflow/underflow of channel n. */
      vuint32_t MCS_IRQ:1;             /* Interrupt request by MCS-channel n. */
    } B;
  } CH3_IRQ_NOTIFY;

  union {                              /* MCS Channel n Interrupt Request Enable Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_IRQ_EN:1;      /* MCS channel n MEM_ERR_IRQ interrupt enable. */
      vuint32_t STK_ERR_IRQ_EN:1;      /* MCS channel n STK_ERR_IRQ interrupt enable. */
      vuint32_t MCS_IRQ_EN:1;          /* MCS channel n MCS_IRQ interrupt enable. */
    } B;
  } CH3_IRQ_EN;

  union {                              /* MCS Channel n Force Interrupt Request Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t TRG_MEM_ERR_IRQ:1;     /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register by software. */
      vuint32_t TRG_STK_ERR_IRQ:1;     /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register by software. */
      vuint32_t TRG_MCS_IRQ:1;         /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register */
    } B;
  } CH3_IRQ_FORCINT;

  union {                              /* MCS Channel n Interrupt Request Mode Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH3_IRQ_MODE;

  union {                              /* MCS Channel n Error Interrupt Request Enable register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_EIRQ_EN:1;     /* MCS[i] channel n MEM_ERR_EIRQ error interrupt enable. */
      vuint32_t STK_ERR_EIRQ_EN:1;     /* MCS[i] channel n STK_ERR_IRQ error interrupt enable. */
      vuint32_t MCS_EIRQ_EN:1;         /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register */
    } B;
  } CH3_EIRQ_EN;

  uint8_t MCS_reserved7[40];
  union {                              /* MCS Channel n General Purpose 0 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R0. */
    } B;
  } CH4_R0;

  union {                              /* MCS Channel n General Purpose 1 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R1. */
    } B;
  } CH4_R1;

  union {                              /* MCS Channel n General Purpose 2 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R2. */
    } B;
  } CH4_R2;

  union {                              /* MCS Channel n General Purpose 3 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R3. */
    } B;
  } CH4_R3;

  union {                              /* MCS Channel n General Purpose 4 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R4. */
    } B;
  } CH4_R4;

  union {                              /* MCS Channel n General Purpose 5 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R5. */
    } B;
  } CH4_R5;

  union {                              /* MCS Channel n General Purpose 6 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R6. */
    } B;
  } CH4_R6;

  union {                              /* MCS Channel n General Purpose 7 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R7. */
    } B;
  } CH4_R7;

  union {                              /* MCS Channel n Control Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :13;
      vuint32_t SP_CNT:3;              /* Stack pointer counter value. */
      vuint32_t  :5;
      vuint32_t SAT:1;                 /* Successful ARU transfer bit. */
      vuint32_t CWT:1;                 /* Cancel WURM instruction state. */
      vuint32_t CAT:1;                 /* Cancel ARU transfer state. */
      vuint32_t N:1;                   /* Negative bit state. */
      vuint32_t V:1;                   /* Overflow bit state. */
      vuint32_t Z:1;                   /* Zero bit state. */
      vuint32_t CY:1;                  /* Carry bit state. */
      vuint32_t  :1;
      vuint32_t ERR:1;                 /* Error state. */
      vuint32_t IRQ:1;                 /* Interrupt state. */
      vuint32_t EN:1;                  /* Enable MCS-channel. */
    } B;
  } CH4_CTRL;

  union {                              /* MCS Channel n ARU Control Bit Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :27;
      vuint32_t ACB4:1;                /* See ACB0. */
      vuint32_t ACB3:1;                /* See ACB0. */
      vuint32_t ACB2:1;                /* See ACB0. */
      vuint32_t ACB1:1;                /* See ACB0. */
      vuint32_t ACB0:1;                /* ARU Control bit[4:0]. */
    } B;
  } CH4_ACB;

  uint8_t MCS_reserved8[24];
  union {                              /* MCS Channel n Program Counter Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :18;
      vuint32_t PC:14;                 /* Current Program Counter. */
    } B;
  } CH4_PC;

  union {                              /* MCS Channel n Interrupt Request Notification Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_IRQ:1;         /* Memory access out of range in channel n. */
      vuint32_t STK_ERR_IRQ:1;         /* Stack counter overflow/underflow of channel n. */
      vuint32_t MCS_IRQ:1;             /* Interrupt request by MCS-channel n. */
    } B;
  } CH4_IRQ_NOTIFY;

  union {                              /* MCS Channel n Interrupt Request Enable Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_IRQ_EN:1;      /* MCS channel n MEM_ERR_IRQ interrupt enable. */
      vuint32_t STK_ERR_IRQ_EN:1;      /* MCS channel n STK_ERR_IRQ interrupt enable. */
      vuint32_t MCS_IRQ_EN:1;          /* MCS channel n MCS_IRQ interrupt enable. */
    } B;
  } CH4_IRQ_EN;

  union {                              /* MCS Channel n Force Interrupt Request Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t TRG_MEM_ERR_IRQ:1;     /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register by software. */
      vuint32_t TRG_STK_ERR_IRQ:1;     /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register by software. */
      vuint32_t TRG_MCS_IRQ:1;         /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register */
    } B;
  } CH4_IRQ_FORCINT;

  union {                              /* MCS Channel n Interrupt Request Mode Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH4_IRQ_MODE;

  union {                              /* MCS Channel n Error Interrupt Request Enable register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_EIRQ_EN:1;     /* MCS[i] channel n MEM_ERR_EIRQ error interrupt enable. */
      vuint32_t STK_ERR_EIRQ_EN:1;     /* MCS[i] channel n STK_ERR_IRQ error interrupt enable. */
      vuint32_t MCS_EIRQ_EN:1;         /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register */
    } B;
  } CH4_EIRQ_EN;

  uint8_t MCS_reserved9[40];
  union {                              /* MCS Channel n General Purpose 0 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R0. */
    } B;
  } CH5_R0;

  union {                              /* MCS Channel n General Purpose 1 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R1. */
    } B;
  } CH5_R1;

  union {                              /* MCS Channel n General Purpose 2 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R2. */
    } B;
  } CH5_R2;

  union {                              /* MCS Channel n General Purpose 3 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R3. */
    } B;
  } CH5_R3;

  union {                              /* MCS Channel n General Purpose 4 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R4. */
    } B;
  } CH5_R4;

  union {                              /* MCS Channel n General Purpose 5 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R5. */
    } B;
  } CH5_R5;

  union {                              /* MCS Channel n General Purpose 6 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R6. */
    } B;
  } CH5_R6;

  union {                              /* MCS Channel n General Purpose 7 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R7. */
    } B;
  } CH5_R7;

  union {                              /* MCS Channel n Control Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :13;
      vuint32_t SP_CNT:3;              /* Stack pointer counter value. */
      vuint32_t  :5;
      vuint32_t SAT:1;                 /* Successful ARU transfer bit. */
      vuint32_t CWT:1;                 /* Cancel WURM instruction state. */
      vuint32_t CAT:1;                 /* Cancel ARU transfer state. */
      vuint32_t N:1;                   /* Negative bit state. */
      vuint32_t V:1;                   /* Overflow bit state. */
      vuint32_t Z:1;                   /* Zero bit state. */
      vuint32_t CY:1;                  /* Carry bit state. */
      vuint32_t  :1;
      vuint32_t ERR:1;                 /* Error state. */
      vuint32_t IRQ:1;                 /* Interrupt state. */
      vuint32_t EN:1;                  /* Enable MCS-channel. */
    } B;
  } CH5_CTRL;

  union {                              /* MCS Channel n ARU Control Bit Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :27;
      vuint32_t ACB4:1;                /* See ACB0. */
      vuint32_t ACB3:1;                /* See ACB0. */
      vuint32_t ACB2:1;                /* See ACB0. */
      vuint32_t ACB1:1;                /* See ACB0. */
      vuint32_t ACB0:1;                /* ARU Control bit[4:0]. */
    } B;
  } CH5_ACB;

  uint8_t MCS_reserved10[24];
  union {                              /* MCS Channel n Program Counter Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :18;
      vuint32_t PC:14;                 /* Current Program Counter. */
    } B;
  } CH5_PC;

  union {                              /* MCS Channel n Interrupt Request Notification Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_IRQ:1;         /* Memory access out of range in channel n. */
      vuint32_t STK_ERR_IRQ:1;         /* Stack counter overflow/underflow of channel n. */
      vuint32_t MCS_IRQ:1;             /* Interrupt request by MCS-channel n. */
    } B;
  } CH5_IRQ_NOTIFY;

  union {                              /* MCS Channel n Interrupt Request Enable Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_IRQ_EN:1;      /* MCS channel n MEM_ERR_IRQ interrupt enable. */
      vuint32_t STK_ERR_IRQ_EN:1;      /* MCS channel n STK_ERR_IRQ interrupt enable. */
      vuint32_t MCS_IRQ_EN:1;          /* MCS channel n MCS_IRQ interrupt enable. */
    } B;
  } CH5_IRQ_EN;

  union {                              /* MCS Channel n Force Interrupt Request Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t TRG_MEM_ERR_IRQ:1;     /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register by software. */
      vuint32_t TRG_STK_ERR_IRQ:1;     /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register by software. */
      vuint32_t TRG_MCS_IRQ:1;         /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register */
    } B;
  } CH5_IRQ_FORCINT;

  union {                              /* MCS Channel n Interrupt Request Mode Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH5_IRQ_MODE;

  union {                              /* MCS Channel n Error Interrupt Request Enable register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_EIRQ_EN:1;     /* MCS[i] channel n MEM_ERR_EIRQ error interrupt enable. */
      vuint32_t STK_ERR_EIRQ_EN:1;     /* MCS[i] channel n STK_ERR_IRQ error interrupt enable. */
      vuint32_t MCS_EIRQ_EN:1;         /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register */
    } B;
  } CH5_EIRQ_EN;

  uint8_t MCS_reserved11[40];
  union {                              /* MCS Channel n General Purpose 0 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R0. */
    } B;
  } CH6_R0;

  union {                              /* MCS Channel n General Purpose 1 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R1. */
    } B;
  } CH6_R1;

  union {                              /* MCS Channel n General Purpose 2 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R2. */
    } B;
  } CH6_R2;

  union {                              /* MCS Channel n General Purpose 3 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R3. */
    } B;
  } CH6_R3;

  union {                              /* MCS Channel n General Purpose 4 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R4. */
    } B;
  } CH6_R4;

  union {                              /* MCS Channel n General Purpose 5 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R5. */
    } B;
  } CH6_R5;

  union {                              /* MCS Channel n General Purpose 6 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R6. */
    } B;
  } CH6_R6;

  union {                              /* MCS Channel n General Purpose 7 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R7. */
    } B;
  } CH6_R7;

  union {                              /* MCS Channel n Control Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :13;
      vuint32_t SP_CNT:3;              /* Stack pointer counter value. */
      vuint32_t  :5;
      vuint32_t SAT:1;                 /* Successful ARU transfer bit. */
      vuint32_t CWT:1;                 /* Cancel WURM instruction state. */
      vuint32_t CAT:1;                 /* Cancel ARU transfer state. */
      vuint32_t N:1;                   /* Negative bit state. */
      vuint32_t V:1;                   /* Overflow bit state. */
      vuint32_t Z:1;                   /* Zero bit state. */
      vuint32_t CY:1;                  /* Carry bit state. */
      vuint32_t  :1;
      vuint32_t ERR:1;                 /* Error state. */
      vuint32_t IRQ:1;                 /* Interrupt state. */
      vuint32_t EN:1;                  /* Enable MCS-channel. */
    } B;
  } CH6_CTRL;

  union {                              /* MCS Channel n ARU Control Bit Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :27;
      vuint32_t ACB4:1;                /* See ACB0. */
      vuint32_t ACB3:1;                /* See ACB0. */
      vuint32_t ACB2:1;                /* See ACB0. */
      vuint32_t ACB1:1;                /* See ACB0. */
      vuint32_t ACB0:1;                /* ARU Control bit[4:0]. */
    } B;
  } CH6_ACB;

  uint8_t MCS_reserved12[24];
  union {                              /* MCS Channel n Program Counter Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :18;
      vuint32_t PC:14;                 /* Current Program Counter. */
    } B;
  } CH6_PC;

  union {                              /* MCS Channel n Interrupt Request Notification Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_IRQ:1;         /* Memory access out of range in channel n. */
      vuint32_t STK_ERR_IRQ:1;         /* Stack counter overflow/underflow of channel n. */
      vuint32_t MCS_IRQ:1;             /* Interrupt request by MCS-channel n. */
    } B;
  } CH6_IRQ_NOTIFY;

  union {                              /* MCS Channel n Interrupt Request Enable Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_IRQ_EN:1;      /* MCS channel n MEM_ERR_IRQ interrupt enable. */
      vuint32_t STK_ERR_IRQ_EN:1;      /* MCS channel n STK_ERR_IRQ interrupt enable. */
      vuint32_t MCS_IRQ_EN:1;          /* MCS channel n MCS_IRQ interrupt enable. */
    } B;
  } CH6_IRQ_EN;

  union {                              /* MCS Channel n Force Interrupt Request Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t TRG_MEM_ERR_IRQ:1;     /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register by software. */
      vuint32_t TRG_STK_ERR_IRQ:1;     /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register by software. */
      vuint32_t TRG_MCS_IRQ:1;         /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register */
    } B;
  } CH6_IRQ_FORCINT;

  union {                              /* MCS Channel n Interrupt Request Mode Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH6_IRQ_MODE;

  union {                              /* MCS Channel n Error Interrupt Request Enable register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_EIRQ_EN:1;     /* MCS[i] channel n MEM_ERR_EIRQ error interrupt enable. */
      vuint32_t STK_ERR_EIRQ_EN:1;     /* MCS[i] channel n STK_ERR_IRQ error interrupt enable. */
      vuint32_t MCS_EIRQ_EN:1;         /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register */
    } B;
  } CH6_EIRQ_EN;

  uint8_t MCS_reserved13[40];
  union {                              /* MCS Channel n General Purpose 0 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R0. */
    } B;
  } CH7_R0;

  union {                              /* MCS Channel n General Purpose 1 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R1. */
    } B;
  } CH7_R1;

  union {                              /* MCS Channel n General Purpose 2 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R2. */
    } B;
  } CH7_R2;

  union {                              /* MCS Channel n General Purpose 3 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R3. */
    } B;
  } CH7_R3;

  union {                              /* MCS Channel n General Purpose 4 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R4. */
    } B;
  } CH7_R4;

  union {                              /* MCS Channel n General Purpose 5 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R5. */
    } B;
  } CH7_R5;

  union {                              /* MCS Channel n General Purpose 6 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R6. */
    } B;
  } CH7_R6;

  union {                              /* MCS Channel n General Purpose 7 Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t DATA:24;               /* Data of MCS general purpose register R7. */
    } B;
  } CH7_R7;

  union {                              /* MCS Channel n Control Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :13;
      vuint32_t SP_CNT:3;              /* Stack pointer counter value. */
      vuint32_t  :5;
      vuint32_t SAT:1;                 /* Successful ARU transfer bit. */
      vuint32_t CWT:1;                 /* Cancel WURM instruction state. */
      vuint32_t CAT:1;                 /* Cancel ARU transfer state. */
      vuint32_t N:1;                   /* Negative bit state. */
      vuint32_t V:1;                   /* Overflow bit state. */
      vuint32_t Z:1;                   /* Zero bit state. */
      vuint32_t CY:1;                  /* Carry bit state. */
      vuint32_t  :1;
      vuint32_t ERR:1;                 /* Error state. */
      vuint32_t IRQ:1;                 /* Interrupt state. */
      vuint32_t EN:1;                  /* Enable MCS-channel. */
    } B;
  } CH7_CTRL;

  union {                              /* MCS Channel n ARU Control Bit Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :27;
      vuint32_t ACB4:1;                /* See ACB0. */
      vuint32_t ACB3:1;                /* See ACB0. */
      vuint32_t ACB2:1;                /* See ACB0. */
      vuint32_t ACB1:1;                /* See ACB0. */
      vuint32_t ACB0:1;                /* ARU Control bit[4:0]. */
    } B;
  } CH7_ACB;

  uint8_t MCS_reserved14[24];
  union {                              /* MCS Channel n Program Counter Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :18;
      vuint32_t PC:14;                 /* Current Program Counter. */
    } B;
  } CH7_PC;

  union {                              /* MCS Channel n Interrupt Request Notification Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_IRQ:1;         /* Memory access out of range in channel n. */
      vuint32_t STK_ERR_IRQ:1;         /* Stack counter overflow/underflow of channel n. */
      vuint32_t MCS_IRQ:1;             /* Interrupt request by MCS-channel n. */
    } B;
  } CH7_IRQ_NOTIFY;

  union {                              /* MCS Channel n Interrupt Request Enable Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_IRQ_EN:1;      /* MCS channel n MEM_ERR_IRQ interrupt enable. */
      vuint32_t STK_ERR_IRQ_EN:1;      /* MCS channel n STK_ERR_IRQ interrupt enable. */
      vuint32_t MCS_IRQ_EN:1;          /* MCS channel n MCS_IRQ interrupt enable. */
    } B;
  } CH7_IRQ_EN;

  union {                              /* MCS Channel n Force Interrupt Request Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t TRG_MEM_ERR_IRQ:1;     /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register by software. */
      vuint32_t TRG_STK_ERR_IRQ:1;     /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register by software. */
      vuint32_t TRG_MCS_IRQ:1;         /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register */
    } B;
  } CH7_IRQ_FORCINT;

  union {                              /* MCS Channel n Interrupt Request Mode Register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH7_IRQ_MODE;

  union {                              /* MCS Channel n Error Interrupt Request Enable register, n=0:8 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t MEM_ERR_EIRQ_EN:1;     /* MCS[i] channel n MEM_ERR_EIRQ error interrupt enable. */
      vuint32_t STK_ERR_EIRQ_EN:1;     /* MCS[i] channel n STK_ERR_IRQ error interrupt enable. */
      vuint32_t MCS_EIRQ_EN:1;         /* Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register */
    } B;
  } CH7_EIRQ_EN;
};


/* ============================================================================
   =============================== Module: GTM_MON ============================
   ============================================================================ */

struct GTM_MON_tag {
  union {                              /* Monitor Status Register */
    vuint32_t R;
    struct {
      vuint32_t  :5;
      vuint32_t MCS6_ERR:1;            /* See MCS0_ERR. */
      vuint32_t MCS5_ERR:1;            /* See MCS0_ERR. */
      vuint32_t MCS4_ERR:1;            /* See MCS0_ERR. */
      vuint32_t MCS3_ERR:1;            /* See MCS0_ERR. */
      vuint32_t MCS2_ERR:1;            /* See MCS0_ERR. */
      vuint32_t MCS1_ERR:1;            /* See MCS0_ERR. */
      vuint32_t MCS0_ERR:1;            /* Error detected at corresponding MCS. */
      vuint32_t  :3;
      vuint32_t CMP_ERR:1;             /* Error detected at CMP. */
      vuint32_t  :3;
      vuint32_t ACT_CMUFX4:1;          /* See ACT_CMUFX0. */
      vuint32_t ACT_CMUFX3:1;          /* See ACT_CMUFX0. */
      vuint32_t ACT_CMUFX2:1;          /* See ACT_CMUFX0. */
      vuint32_t ACT_CMUFX1:1;          /* See ACT_CMUFX0. */
      vuint32_t ACT_CMUFX0:1;          /* Corresponding CMU_CLKFX activity. */
      vuint32_t ACT_CMU7:1;            /* See ACT_CMU0. */
      vuint32_t ACT_CMU6:1;            /* See ACT_CMU0. */
      vuint32_t ACT_CMU5:1;            /* See ACT_CMU0. */
      vuint32_t ACT_CMU4:1;            /* See ACT_CMU0. */
      vuint32_t ACT_CMU3:1;            /* See ACT_CMU0. */
      vuint32_t ACT_CMU2:1;            /* See ACT_CMU0. */
      vuint32_t ACT_CMU1:1;            /* See ACT_CMU0. */
      vuint32_t ACT_CMU0:1;            /* Corresponding CMU_CLK activity. */
    } B;
  } STATUS;

  union {                              /* Monitor Acitivity 0 */
    vuint32_t R;
    struct {
      vuint32_t MCA_3_7:1;             /* See MCA_3_0. */
      vuint32_t MCA_3_6:1;             /* See MCA_3_0. */
      vuint32_t MCA_3_5:1;             /* See MCA_3_0. */
      vuint32_t MCA_3_4:1;             /* See MCA_3_0. */
      vuint32_t MCA_3_3:1;             /* See MCA_3_0. */
      vuint32_t MCA_3_2:1;             /* See MCA_3_0. */
      vuint32_t MCA_3_1:1;             /* See MCA_3_0. */
      vuint32_t MCA_3_0:1;             /* Activity of check performed in module MCS[3] at corresponding channel. */
      vuint32_t MCA_2_7:1;             /* See MCA_2_0. */
      vuint32_t MCA_2_6:1;             /* See MCA_2_0. */
      vuint32_t MCA_2_5:1;             /* See MCA_2_0. */
      vuint32_t MCA_2_4:1;             /* See MCA_2_0. */
      vuint32_t MCA_2_3:1;             /* See MCA_2_0. */
      vuint32_t MCA_2_2:1;             /* See MCA_2_0. */
      vuint32_t MCA_2_1:1;             /* See MCA_2_0. */
      vuint32_t MCA_2_0:1;             /* Activity of check performed in module MCS[2] at corresponding channel. */
      vuint32_t MCA_1_7:1;             /* See MCA_1_0. */
      vuint32_t MCA_1_6:1;             /* See MCA_1_0. */
      vuint32_t MCA_1_5:1;             /* See MCA_1_0. */
      vuint32_t MCA_1_4:1;             /* See MCA_1_0. */
      vuint32_t MCA_1_3:1;             /* See MCA_1_0. */
      vuint32_t MCA_1_2:1;             /* See MCA_1_0. */
      vuint32_t MCA_1_1:1;             /* See MCA_1_0. */
      vuint32_t MCA_1_0:1;             /* Activity of check performed in module MCS[1] at corresponding channel. */
      vuint32_t MCA_0_7:1;             /* See MCA_0_0. */
      vuint32_t MCA_0_6:1;             /* See MCA_0_0. */
      vuint32_t MCA_0_5:1;             /* See MCA_0_0. */
      vuint32_t MCA_0_4:1;             /* See MCA_0_0. */
      vuint32_t MCA_0_3:1;             /* See MCA_0_0. */
      vuint32_t MCA_0_2:1;             /* See MCA_0_0. */
      vuint32_t MCA_0_1:1;             /* See MCA_0_0. */
      vuint32_t MCA_0_0:1;             /* Activity of check performed in module MCS[0] at corresponding channel. */
    } B;
  } ACTIVITY_0;

  union {                              /* Monitor Acitivity 1 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t MCA_6_7:1;             /* See MCA_6_0. */
      vuint32_t MCA_6_6:1;             /* See MCA_6_0. */
      vuint32_t MCA_6_5:1;             /* See MCA_6_0. */
      vuint32_t MCA_6_4:1;             /* See MCA_6_0. */
      vuint32_t MCA_6_3:1;             /* See MCA_6_0. */
      vuint32_t MCA_6_2:1;             /* See MCA_6_0. */
      vuint32_t MCA_6_1:1;             /* See MCA_6_0. */
      vuint32_t MCA_6_0:1;             /* Activity of check performed in module MCS[6] at corresponding channel. */
      vuint32_t MCA_5_7:1;             /* See MCA_5_0. */
      vuint32_t MCA_5_6:1;             /* See MCA_5_0. */
      vuint32_t MCA_5_5:1;             /* See MCA_5_0. */
      vuint32_t MCA_5_4:1;             /* See MCA_5_0. */
      vuint32_t MCA_5_3:1;             /* See MCA_5_0. */
      vuint32_t MCA_5_2:1;             /* See MCA_5_0. */
      vuint32_t MCA_5_1:1;             /* See MCA_5_0. */
      vuint32_t MCA_5_0:1;             /* Activity of check performed in module MCS[5] at corresponding channel. */
      vuint32_t MCA_4_7:1;             /* See MCA_4_0. */
      vuint32_t MCA_4_6:1;             /* See MCA_4_0. */
      vuint32_t MCA_4_5:1;             /* See MCA_4_0. */
      vuint32_t MCA_4_4:1;             /* See MCA_4_0. */
      vuint32_t MCA_4_3:1;             /* See MCA_4_0. */
      vuint32_t MCA_4_2:1;             /* See MCA_4_0. */
      vuint32_t MCA_4_1:1;             /* See MCA_4_0. */
      vuint32_t MCA_4_0:1;             /* Activity of check performed in module MCS[4] at corresponding channel. */
    } B;
  } ACTIVITY_1;
};


/* ============================================================================
   =============================== Module: GTM_SPE ============================
   ============================================================================ */

struct GTM_SPE_tag {
  union {                              /* SPE Control Status Register */
    vuint32_t R;
    struct {
      vuint32_t FSOL:8;                /* Fast Shut-Off Level for TOM[i] channel 0 to 7. */
      vuint32_t  :1;
      vuint32_t NIP:3;                 /* New input pattern that was detected. */
      vuint32_t PDIR:1;                /* Previous rotation direction. */
      vuint32_t PIP:3;                 /* Previous input pattern that was detected by a regular input pattern change. */
      vuint32_t ADIR:1;                /* Actual rotation direction. */
      vuint32_t AIP:3;                 /* Actual input pattern that was detected by a regular input pattern change. */
      vuint32_t  :1;
      vuint32_t SPE_PAT_PTR:3;         /* Pattern selector for TOM output signals. */
      vuint32_t FSOM:1;                /* Fast Shut-Off Mode. */
      vuint32_t TIM_SEL:1;             /* Select TIM input signal. */
      vuint32_t TRIG_SEL:2;            /* Select trigger input signal. */
      vuint32_t SIE2:1;                /* SPE Input enable for TIM_CHz(48). */
      vuint32_t SIE1:1;                /* SPE Input enable for TIM_CHy(48). */
      vuint32_t SIE0:1;                /* SPE Input enable for TIM_CHx(48). */
      vuint32_t EN:1;                  /* SPE Submodule enable. */
    } B;
  } CTRL_STAT;

  union {                              /* SPE Input Pattern Register */
    vuint32_t R;
    struct {
      vuint32_t IP7_PAT:3;             /* Input pattern 7. */
      vuint32_t IP7_VAL:1;             /* Input pattern 7 is a valid pattern. */
      vuint32_t IP6_PAT:3;             /* Input pattern 6. */
      vuint32_t IP6_VAL:1;             /* Input pattern 6 is a valid pattern. */
      vuint32_t IP5_PAT:3;             /* Input pattern 5. */
      vuint32_t IP5_VAL:1;             /* Input pattern 5 is a valid pattern. */
      vuint32_t IP4_PAT:3;             /* Input pattern 4. */
      vuint32_t IP4_VAL:1;             /* Input pattern 4 is a valid pattern. */
      vuint32_t IP3_PAT:3;             /* Input pattern 3. */
      vuint32_t IP3_VAL:1;             /* Input pattern 3 is a valid pattern. */
      vuint32_t IP2_PAT:3;             /* Input pattern 2. */
      vuint32_t IP2_VAL:1;             /* Input pattern 2 is a valid pattern. */
      vuint32_t IP1_PAT:3;
      vuint32_t IP1_VAL:1;             /* Input pattern 1 is a valid pattern. */
      vuint32_t IP0_PAT:3;             /* Input pattern 0. */
      vuint32_t IP0_VAL:1;             /* Input pattern 0 is a valid pattern. */
    } B;
  } PAT;

  union {                              /* SPE Output Pattern n Register */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SPE_OUT_PAT:16;        /* SPE output control value for TOM_CH0 to TOM_CH7 SPE_OUT_PAT[n+1:n] defines output select signal of TOM[i]_CH[n]. */
    } B;
  } OUT_PAT[8];

  union {                              /* SPE Output Control Register */
    vuint32_t R;
    struct {
      vuint32_t  :16;                  /* Reserved. */
      vuint32_t SPE_OUT_CTRL:16;       /* SPE output control value for TOM_CH0 to TOM_CH7. */
    } B;
  } OUT_CTRL;

  union {                              /* SPE Interrupt Request Notify Register */
    vuint32_t R;
    struct {
      vuint32_t  :27;
      vuint32_t SPE_RCMP:1;            /* SPE revolution counter match event. */
      vuint32_t SPE_BIS:1;             /* Bouncing input signal detected. */
      vuint32_t SPE_PERR:1;            /* Wrong or invalid pattern detected at input. */
      vuint32_t SPE_DCHG:1;            /* SPE_DIR bit changed on behalf of new input pattern. */
      vuint32_t SPE_NIPD:1;            /* New input pattern interrupt occurred. */
    } B;
  } IRQ_NOTIFY;

  union {                              /* SPE Interrupt Request Enable Register */
    vuint32_t R;
    struct {
      vuint32_t  :27;                  /* Reserved. */
      vuint32_t SPE_RCMP_IRQ_EN:1;     /* SPE_RCMP_IRQ interrupt enable. */
      vuint32_t SPE_BIS_IRQ_EN:1;      /* SPE_BIS_IRQ interrupt enable. */
      vuint32_t SPE_PERR_IRQ_EN:1;     /* SPE_PERR_IRQ interrupt enable. */
      vuint32_t SPE_DCHG_IRQ_EN:1;     /* SPE_DCHG_IRQ interrupt enable. */
      vuint32_t SPE_NIPD_IRQ_EN:1;     /* SPE_NIPD_IRQ interrupt enable. */
    } B;
  } IRQ_EN;

  union {                              /* SPE Interrupt Request Force Interrupt Register */
    vuint32_t R;
    struct {
      vuint32_t  :27;                  /* Reserved. */
      vuint32_t TRG_SPE_RCMP:1;        /* Force interrupt of SPE_RCMP. */
      vuint32_t TRG_SPE_BIS:1;         /* Force interrupt of SPE_BIS. */
      vuint32_t TRG_SPE_PERR:1;        /* Force interrupt of SPE_PERR. */
      vuint32_t TRG_SPE_DCHG:1;        /* Force interrupt of SPE_DCHG. */
      vuint32_t TRG_SPE_NIPD:1;        /* Force interrupt of SPE_NIPD. */
    } B;
  } IRQ_FORCINT;

  union {                              /* SPE Interrupt Request Mode Register */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } IRQ_MODE;

  union {                              /* SPE Error Interrupt Request Enable register */
    vuint32_t R;
    struct {
      vuint32_t  :27;
      vuint32_t SPE_RCMP_EIRQ_EN:1;    /* SPE_BIS_EIRQ error interrupt enable. */
      vuint32_t SPE_BIS_EIRQ_EN:1;     /* SPE_BIS_EIRQ error interrupt enable. */
      vuint32_t SPE_PERR_EIRQ_EN:1;    /* SPE_PERR_EIRQ interrupt enable. */
      vuint32_t SPE_DCHG_EIRQ_EN:1;
      vuint32_t SPE_NIPD_EIRQ_EN:1;    /* SPE_NIPD_EIRQ interrupt enable. */
    } B;
  } EIRQ_EN;

  union {                              /* SPE Revolution Counter register */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t REV_CNT:24;            /* Input signal revolution counter. */
    } B;
  } REV_CNT;

  union {                              /* SPE Revolution Counter Compare register */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t REV_CMP:24;            /* Input signal revolution counter compare value. */
    } B;
  } REV_CMP;
};


/* ============================================================================
   =============================== Module: GTM_TBU ============================
   ============================================================================ */

struct GTM_TBU_tag {
  union {                              /* TBU Global Channel Enable Register */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t ENDIS_CH2:2;           /* TBU channel 2 enable/disable control. */
      vuint32_t ENDIS_CH1:2;           /* TBU channel 1 enable/disable control. */
      vuint32_t ENDIS_CH0:2;           /* TBU channel 0 enable/disable control. */
    } B;
  } CHEN;

  union {                              /* TBU Channel 0 Control Register */
    vuint32_t R;
    struct {
      vuint32_t  :28;
      vuint32_t CH_CLK_SRC:3;          /* Clock source for channel 0. */
      vuint32_t LOW_RES:1;             /* TBU_CH0_BASE register resolution. */
    } B;
  } CH0_CTRL;

  union {                              /* TBU Channel 0 Base Register */
    vuint32_t R;
    struct {
      vuint32_t  :5;
      vuint32_t BASE:27;               /* Time base value for channel 0. */
    } B;
  } CH0_BASE;

  union {                              /* TBU Channel 1 Control Register */
    vuint32_t R;
    struct {
      vuint32_t  :28;
      vuint32_t CH_CLK_SRC:3;          /* Clock source for channel time base counter. */
      vuint32_t CH_MODE:1;             /* Channel mode. */
    } B;
  } CH1_CTRL;

  union {                              /* TBU Channel 1 Base Register */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t BASE:24;               /* Time base value for the channel. */
    } B;
  } CH1_BASE;

  union {                              /* TBU Channel 2 Control Register */
    vuint32_t R;
    struct {
      vuint32_t  :28;
      vuint32_t CH_CLK_SRC:3;          /* Clock source for channel time base counter. */
      vuint32_t CH_MODE:1;             /* Channel mode. */
    } B;
  } CH2_CTRL;

  union {                              /* TBU Channel 2 Base Register */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t BASE:24;               /* Time base value for the channel. */
    } B;
  } CH2_BASE;
};


/* ============================================================================
   =============================== Module: GTM_TIM ============================
   ============================================================================ */

struct GTM_TIM_tag {
  union {                              /* TIM Channel n General Purpose Register 0, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t GPR0:24;               /* Input signal characteristic parameter 0. */
    } B;
  } CH0_GPR0;

  union {                              /* TIM Channel n General Purpose Register 1, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t GPR1:24;               /* Input signal characteristic parameter 1. */
    } B;
  } CH0_GPR1;

  union {                              /* TIM Channel n Count Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CNT:24;                /* Actual SMU counter value. */
    } B;
  } CH0_CNT;

  union {                              /* TIM Channel n Edge Counter Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t ECNT:16;               /* Edge counter. */
    } B;
  } CH0_ECNT;

  union {                              /* TIM Channel n Counter Shadow Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t CNTS:24;               /* Counter shadow register. */
    } B;
  } CH0_CNTS;

  union {                              /* TIM Channel n TDUC Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :24;
      vuint32_t TO_CNT:8;              /* Current Timeout value for channel n (n:0...m-1). */
    } B;
  } CH0_TDUC;

  union {                              /* TIM Channel n TDUV Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :1;
      vuint32_t TCS:3;                 /* Timeout Clock selection. */
      vuint32_t  :20;
      vuint32_t TOV:8;                 /* Time out duration for channel n (n:0...m-1). */
    } B;
  } CH0_TDUV;

  union {                              /* TIM Channel n Filter Parameter 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t FLT_RE:24;             /* Filter parameter for rising edge. */
    } B;
  } CH0_FLT_RE;

  union {                              /* TIM Channel n Filter Parameter 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t FLT_FE:24;             /* Filter parameter for falling edge. */
    } B;
  } CH0_FLT_FE;

  union {                              /* TIM Channel n Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t TOCTRL:2;              /* Timeout control */
      vuint32_t EGPR1_SEL:1;           /* Extension of GPR1_SEL bit field. */
      vuint32_t EGPR0_SEL:1;           /* Extension of GPR0_SEL bit field. */
      vuint32_t FR_ECNT_OFL:1;         /* Extended Edge counter overflow behavior. */
      vuint32_t CLK_SEL:3;             /* CMU clock source select for channel. */
      vuint32_t FLT_CTR_FE:1;          /* Filter counter mode for falling edge. */
      vuint32_t FLT_MODE_FE:1;         /* Filter mode for falling edge. */
      vuint32_t FLT_CTR_RE:1;          /* Filter counter mode for rising edge. */
      vuint32_t FLT_MODE_RE:1;         /* Filter mode for rising edge. */
      vuint32_t EXT_CAP_EN:1;          /* Enables external capture mode. The selected TIM mode is only sensitive to external capture pulses, the input event changes are ignored. */
      vuint32_t FLT_CNT_FRQ:2;         /* Filter counter frequency select. */
      vuint32_t FLT_EN:1;              /* Filter enable for channel n. */
      vuint32_t ECNT_RESET:1;          /* Enables resetting the ECNT counter in periodic sampling mode. */
      vuint32_t ISL:1;                 /* Ignore Signal Level. */
      vuint32_t DSL:1;                 /* Signal level control. */
      vuint32_t CNTS_SEL:1;            /* Selection for CNTS register. */
      vuint32_t GPR1_SEL:2;            /* Selection for GPR1 register. */
      vuint32_t GPR0_SEL:2;            /* Selection for GPR0 register. */
      vuint32_t TBU0_SEL:1;            /* TBU_TS0 bits input select for TIM_CHn_GPRz (z: 0, 1) */
      vuint32_t CICTRL:1;              /* Channel Input Control. */
      vuint32_t ARU_EN:1;              /* GPR0 and GPR1 register values routed to ARU. */
      vuint32_t OSM:1;                 /* One-shot mode. */
      vuint32_t TIM_MODE:3;            /* TIM channel n mode. */
      vuint32_t TIM_EN:1;              /* TIM channel n enable. */
    } B;
  } CH0_CTRL;

  union {                              /* TIM Channel n External Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t EXT_CAP_SRC:3;         /* Defines selected source for triggering the EXT_CAPTURE functionality. */
    } B;
  } CH0_ECTRL;

  union {                              /* TIM Channel n Interrupt Request Notification Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET:1;           /* Glitch detected on channel n. */
      vuint32_t TODET:1;               /* Timeout reached for input signal of channel n. */
      vuint32_t GPROFL:1;              /* GPR0 and GPR1 data overflow, old data not read out before new data has arrived at input pin. */
      vuint32_t CNTOFL:1;              /* SMU CNT counter overflow of channel n. */
      vuint32_t ECNTOFL:1;             /* ECNT counter overflow of channel n. */
      vuint32_t NEWVAL:1;              /* New measurement value detected by in channel n */
    } B;
  } CH0_IRQ_NOTIFY;

  union {                              /* TIM Channel n Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET_IRQ_EN:1;    /* TIM_GLITCHDETx_IRQ interrupt enable. */
      vuint32_t TODET_IRQ_EN:1;        /* TIM_TODETn_IRQ interrupt enable. */
      vuint32_t GPROFL_IRQ_EN:1;       /* TIM_GPROFL_IRQ interrupt enable. */
      vuint32_t CNTOFL_IRQ_EN:1;       /* TIM_CNTOFLn_IRQ interrupt enable. */
      vuint32_t ECNTOFL_IRQ_EN:1;      /* TIM_ECNTOFLn_IRQ interrupt enable. */
      vuint32_t NEWVAL_IRQ_EN:1;       /* TIM_NEWVALn_IRQ interrupt enable. */
    } B;
  } CH0_IRQ_EN;

  union {                              /* TIM Channel n Force Interrupt Request Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t TRG_GLITCHDET:1;       /* Trigger bit TIM_CHn_IRQ_NOTIFY[GLITCHDET] by software. */
      vuint32_t TRG_TODET:1;           /* Trigger bit TIM_CHn_IRQ_NOTIFY[TODET] by software. */
      vuint32_t TRG_GPROFL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[GPROFL] by software. */
      vuint32_t TRG_CNTOFL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[CNTOFL] by software. */
      vuint32_t TRG_ECNTOFL:1;         /* Trigger bit TIM_CHn_IRQ_NOTIFY[ECNTOFL] by software. */
      vuint32_t TRG_NEWVAL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[NEWVAL] by software. */
    } B;
  } CH0_IRQ_FORCINT;

  union {                              /* TIM Channel n Interrupt Request Mode Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH0_IRQ_MODE;

  union {                              /* TIM Channel Error Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET_EIRQ_EN:1;   /* TIM_GLITCHDETx_IRQ interrupt enable. */
      vuint32_t TODET_EIRQ_EN:1;       /* TIM_TODETx_IRQ interrupt enable. */
      vuint32_t GPROFL_EIRQ_EN:1;      /* TIM_GPROFL_IRQ interrupt enable. */
      vuint32_t CNTOFL_EIRQ_EN:1;      /* TIM_CNTOFLx_IRQ interrupt enable. */
      vuint32_t ECNTOFL_EIRQ_EN:1;     /* TIM_ECNTOFLx_IRQ interrupt enable. */
      vuint32_t NEWVAL_EIRQ_EN:1;      /* TIM_NEWVALx_EIRQ error interrupt enable. */
    } B;
  } CH0_EIRQ_EN;

  uint8_t TIM_reserved0[56];
  union {                              /* TIM Input Source Register */
    vuint32_t R;
    struct {
      vuint32_t MODE_7:2;              /* Input source to Channel 7 */
      vuint32_t VAL_7:2;               /* Value to be fed to Channel 7 */
      vuint32_t MODE_6:2;              /* Input source to Channel 6 */
      vuint32_t VAL_6:2;               /* Value to be fed to Channel 6 */
      vuint32_t MODE_5:2;              /* Input source to Channel 5 */
      vuint32_t VAL_5:2;               /* Value to be fed to Channel 5 */
      vuint32_t MODE_4:2;              /* Input source to Channel 4 */
      vuint32_t VAL_4:2;               /* Value to be fed to Channel 4 */
      vuint32_t MODE_3:2;              /* Input source to Channel 3 */
      vuint32_t VAL_3:2;               /* Value to be fed to Channel 3 */
      vuint32_t MODE_2:2;              /* Input source to Channel 2 */
      vuint32_t VAL_2:2;               /* Value to be fed to Channel 2 */
      vuint32_t MODE_1:2;              /* Input source to Channel 1 */
      vuint32_t VAL_1:2;               /* Value to be fed to Channel 1 */
      vuint32_t MODE_0:2;              /* Input source to Channel 0 */
      vuint32_t VAL_0:2;               /* Value to be fed to Channel 0 */
    } B;
  } IN_SRC;

  union {                              /* TIM Channel Reset Register */
    vuint32_t R;
    struct {
      vuint32_t  :24;
      vuint32_t RST_CH7:1;             /* Software reset of channel 7. */
      vuint32_t RST_CH6:1;             /* Software reset of channel 6. */
      vuint32_t RST_CH5:1;             /* Software reset of channel 5. */
      vuint32_t RST_CH4:1;             /* Software reset of channel 4. */
      vuint32_t RST_CH3:1;             /* Software reset of channel 3. */
      vuint32_t RST_CH2:1;             /* Software reset of channel 2. */
      vuint32_t RST_CH1:1;             /* Software reset of channel 1. */
      vuint32_t RST_CH0:1;             /* Software reset of channel 0. */
    } B;
  } RST;

  union {                              /* TIM Channel n General Purpose Register 0, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t GPR0:24;               /* Input signal characteristic parameter 0. */
    } B;
  } CH1_GPR0;

  union {                              /* TIM Channel n General Purpose Register 1, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t GPR1:24;               /* Input signal characteristic parameter 1. */
    } B;
  } CH1_GPR1;

  union {                              /* TIM Channel n Count Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CNT:24;                /* Actual SMU counter value. */
    } B;
  } CH1_CNT;

  union {                              /* TIM Channel n Edge Counter Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t ECNT:16;               /* Edge counter. */
    } B;
  } CH1_ECNT;

  union {                              /* TIM Channel n Counter Shadow Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t CNTS:24;               /* Counter shadow register. */
    } B;
  } CH1_CNTS;

  union {                              /* TIM Channel n TDUC Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :24;
      vuint32_t TO_CNT:8;              /* Current Timeout value for channel n (n:0...m-1). */
    } B;
  } CH1_TDUC;

  union {                              /* TIM Channel n TDUV Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :1;
      vuint32_t TCS:3;                 /* Timeout Clock selection. */
      vuint32_t  :20;
      vuint32_t TOV:8;                 /* Time out duration for channel n (n:0...m-1). */
    } B;
  } CH1_TDUV;

  union {                              /* TIM Channel n Filter Parameter 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t FLT_RE:24;             /* Filter parameter for rising edge. */
    } B;
  } CH1_FLT_RE;

  union {                              /* TIM Channel n Filter Parameter 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t FLT_FE:24;             /* Filter parameter for falling edge. */
    } B;
  } CH1_FLT_FE;

  union {                              /* TIM Channel n Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t TOCTRL:2;              /* Timeout control */
      vuint32_t EGPR1_SEL:1;           /* Extension of GPR1_SEL bit field. */
      vuint32_t EGPR0_SEL:1;           /* Extension of GPR0_SEL bit field. */
      vuint32_t FR_ECNT_OFL:1;         /* Extended Edge counter overflow behavior. */
      vuint32_t CLK_SEL:3;             /* CMU clock source select for channel. */
      vuint32_t FLT_CTR_FE:1;          /* Filter counter mode for falling edge. */
      vuint32_t FLT_MODE_FE:1;         /* Filter mode for falling edge. */
      vuint32_t FLT_CTR_RE:1;          /* Filter counter mode for rising edge. */
      vuint32_t FLT_MODE_RE:1;         /* Filter mode for rising edge. */
      vuint32_t EXT_CAP_EN:1;          /* Enables external capture mode. The selected TIM mode is only sensitive to external capture pulses, the input event changes are ignored. */
      vuint32_t FLT_CNT_FRQ:2;         /* Filter counter frequency select. */
      vuint32_t FLT_EN:1;              /* Filter enable for channel n. */
      vuint32_t ECNT_RESET:1;          /* Enables resetting the ECNT counter in periodic sampling mode. */
      vuint32_t ISL:1;                 /* Ignore Signal Level. */
      vuint32_t DSL:1;                 /* Signal level control. */
      vuint32_t CNTS_SEL:1;            /* Selection for CNTS register. */
      vuint32_t GPR1_SEL:2;            /* Selection for GPR1 register. */
      vuint32_t GPR0_SEL:2;            /* Selection for GPR0 register. */
      vuint32_t TBU0_SEL:1;            /* TBU_TS0 bits input select for TIM_CHn_GPRz (z: 0, 1) */
      vuint32_t CICTRL:1;              /* Channel Input Control. */
      vuint32_t ARU_EN:1;              /* GPR0 and GPR1 register values routed to ARU. */
      vuint32_t OSM:1;                 /* One-shot mode. */
      vuint32_t TIM_MODE:3;            /* TIM channel n mode. */
      vuint32_t TIM_EN:1;              /* TIM channel n enable. */
    } B;
  } CH1_CTRL;

  union {                              /* TIM Channel n External Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t EXT_CAP_SRC:3;         /* Defines selected source for triggering the EXT_CAPTURE functionality. */
    } B;
  } CH1_ECTRL;

  union {                              /* TIM Channel n Interrupt Request Notification Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET:1;           /* Glitch detected on channel n. */
      vuint32_t TODET:1;               /* Timeout reached for input signal of channel n. */
      vuint32_t GPROFL:1;              /* GPR0 and GPR1 data overflow, old data not read out before new data has arrived at input pin. */
      vuint32_t CNTOFL:1;              /* SMU CNT counter overflow of channel n. */
      vuint32_t ECNTOFL:1;             /* ECNT counter overflow of channel n. */
      vuint32_t NEWVAL:1;              /* New measurement value detected by in channel n */
    } B;
  } CH1_IRQ_NOTIFY;

  union {                              /* TIM Channel n Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET_IRQ_EN:1;    /* TIM_GLITCHDETx_IRQ interrupt enable. */
      vuint32_t TODET_IRQ_EN:1;        /* TIM_TODETn_IRQ interrupt enable. */
      vuint32_t GPROFL_IRQ_EN:1;       /* TIM_GPROFL_IRQ interrupt enable. */
      vuint32_t CNTOFL_IRQ_EN:1;       /* TIM_CNTOFLn_IRQ interrupt enable. */
      vuint32_t ECNTOFL_IRQ_EN:1;      /* TIM_ECNTOFLn_IRQ interrupt enable. */
      vuint32_t NEWVAL_IRQ_EN:1;       /* TIM_NEWVALn_IRQ interrupt enable. */
    } B;
  } CH1_IRQ_EN;

  union {                              /* TIM Channel n Force Interrupt Request Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t TRG_GLITCHDET:1;       /* Trigger bit TIM_CHn_IRQ_NOTIFY[GLITCHDET] by software. */
      vuint32_t TRG_TODET:1;           /* Trigger bit TIM_CHn_IRQ_NOTIFY[TODET] by software. */
      vuint32_t TRG_GPROFL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[GPROFL] by software. */
      vuint32_t TRG_CNTOFL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[CNTOFL] by software. */
      vuint32_t TRG_ECNTOFL:1;         /* Trigger bit TIM_CHn_IRQ_NOTIFY[ECNTOFL] by software. */
      vuint32_t TRG_NEWVAL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[NEWVAL] by software. */
    } B;
  } CH1_IRQ_FORCINT;

  union {                              /* TIM Channel n Interrupt Request Mode Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH1_IRQ_MODE;

  union {                              /* TIM Channel Error Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET_EIRQ_EN:1;   /* TIM_GLITCHDETx_IRQ interrupt enable. */
      vuint32_t TODET_EIRQ_EN:1;       /* TIM_TODETx_IRQ interrupt enable. */
      vuint32_t GPROFL_EIRQ_EN:1;      /* TIM_GPROFL_IRQ interrupt enable. */
      vuint32_t CNTOFL_EIRQ_EN:1;      /* TIM_CNTOFLx_IRQ interrupt enable. */
      vuint32_t ECNTOFL_EIRQ_EN:1;     /* TIM_ECNTOFLx_IRQ interrupt enable. */
      vuint32_t NEWVAL_EIRQ_EN:1;      /* TIM_NEWVALx_EIRQ error interrupt enable. */
    } B;
  } CH1_EIRQ_EN;

  uint8_t TIM_reserved1[64];
  union {                              /* TIM Channel n General Purpose Register 0, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t GPR0:24;               /* Input signal characteristic parameter 0. */
    } B;
  } CH2_GPR0;

  union {                              /* TIM Channel n General Purpose Register 1, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t GPR1:24;               /* Input signal characteristic parameter 1. */
    } B;
  } CH2_GPR1;

  union {                              /* TIM Channel n Count Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CNT:24;                /* Actual SMU counter value. */
    } B;
  } CH2_CNT;

  union {                              /* TIM Channel n Edge Counter Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t ECNT:16;               /* Edge counter. */
    } B;
  } CH2_ECNT;

  union {                              /* TIM Channel n Counter Shadow Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t CNTS:24;               /* Counter shadow register. */
    } B;
  } CH2_CNTS;

  union {                              /* TIM Channel n TDUC Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :24;
      vuint32_t TO_CNT:8;              /* Current Timeout value for channel n (n:0...m-1). */
    } B;
  } CH2_TDUC;

  union {                              /* TIM Channel n TDUV Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :1;
      vuint32_t TCS:3;                 /* Timeout Clock selection. */
      vuint32_t  :20;
      vuint32_t TOV:8;                 /* Time out duration for channel n (n:0...m-1). */
    } B;
  } CH2_TDUV;

  union {                              /* TIM Channel n Filter Parameter 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t FLT_RE:24;             /* Filter parameter for rising edge. */
    } B;
  } CH2_FLT_RE;

  union {                              /* TIM Channel n Filter Parameter 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t FLT_FE:24;             /* Filter parameter for falling edge. */
    } B;
  } CH2_FLT_FE;

  union {                              /* TIM Channel n Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t TOCTRL:2;              /* Timeout control */
      vuint32_t EGPR1_SEL:1;           /* Extension of GPR1_SEL bit field. */
      vuint32_t EGPR0_SEL:1;           /* Extension of GPR0_SEL bit field. */
      vuint32_t FR_ECNT_OFL:1;         /* Extended Edge counter overflow behavior. */
      vuint32_t CLK_SEL:3;             /* CMU clock source select for channel. */
      vuint32_t FLT_CTR_FE:1;          /* Filter counter mode for falling edge. */
      vuint32_t FLT_MODE_FE:1;         /* Filter mode for falling edge. */
      vuint32_t FLT_CTR_RE:1;          /* Filter counter mode for rising edge. */
      vuint32_t FLT_MODE_RE:1;         /* Filter mode for rising edge. */
      vuint32_t EXT_CAP_EN:1;          /* Enables external capture mode. The selected TIM mode is only sensitive to external capture pulses, the input event changes are ignored. */
      vuint32_t FLT_CNT_FRQ:2;         /* Filter counter frequency select. */
      vuint32_t FLT_EN:1;              /* Filter enable for channel n. */
      vuint32_t ECNT_RESET:1;          /* Enables resetting the ECNT counter in periodic sampling mode. */
      vuint32_t ISL:1;                 /* Ignore Signal Level. */
      vuint32_t DSL:1;                 /* Signal level control. */
      vuint32_t CNTS_SEL:1;            /* Selection for CNTS register. */
      vuint32_t GPR1_SEL:2;            /* Selection for GPR1 register. */
      vuint32_t GPR0_SEL:2;            /* Selection for GPR0 register. */
      vuint32_t TBU0_SEL:1;            /* TBU_TS0 bits input select for TIM_CHn_GPRz (z: 0, 1) */
      vuint32_t CICTRL:1;              /* Channel Input Control. */
      vuint32_t ARU_EN:1;              /* GPR0 and GPR1 register values routed to ARU. */
      vuint32_t OSM:1;                 /* One-shot mode. */
      vuint32_t TIM_MODE:3;            /* TIM channel n mode. */
      vuint32_t TIM_EN:1;              /* TIM channel n enable. */
    } B;
  } CH2_CTRL;

  union {                              /* TIM Channel n External Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t EXT_CAP_SRC:3;         /* Defines selected source for triggering the EXT_CAPTURE functionality. */
    } B;
  } CH2_ECTRL;

  union {                              /* TIM Channel n Interrupt Request Notification Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET:1;           /* Glitch detected on channel n. */
      vuint32_t TODET:1;               /* Timeout reached for input signal of channel n. */
      vuint32_t GPROFL:1;              /* GPR0 and GPR1 data overflow, old data not read out before new data has arrived at input pin. */
      vuint32_t CNTOFL:1;              /* SMU CNT counter overflow of channel n. */
      vuint32_t ECNTOFL:1;             /* ECNT counter overflow of channel n. */
      vuint32_t NEWVAL:1;              /* New measurement value detected by in channel n */
    } B;
  } CH2_IRQ_NOTIFY;

  union {                              /* TIM Channel n Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET_IRQ_EN:1;    /* TIM_GLITCHDETx_IRQ interrupt enable. */
      vuint32_t TODET_IRQ_EN:1;        /* TIM_TODETn_IRQ interrupt enable. */
      vuint32_t GPROFL_IRQ_EN:1;       /* TIM_GPROFL_IRQ interrupt enable. */
      vuint32_t CNTOFL_IRQ_EN:1;       /* TIM_CNTOFLn_IRQ interrupt enable. */
      vuint32_t ECNTOFL_IRQ_EN:1;      /* TIM_ECNTOFLn_IRQ interrupt enable. */
      vuint32_t NEWVAL_IRQ_EN:1;       /* TIM_NEWVALn_IRQ interrupt enable. */
    } B;
  } CH2_IRQ_EN;

  union {                              /* TIM Channel n Force Interrupt Request Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t TRG_GLITCHDET:1;       /* Trigger bit TIM_CHn_IRQ_NOTIFY[GLITCHDET] by software. */
      vuint32_t TRG_TODET:1;           /* Trigger bit TIM_CHn_IRQ_NOTIFY[TODET] by software. */
      vuint32_t TRG_GPROFL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[GPROFL] by software. */
      vuint32_t TRG_CNTOFL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[CNTOFL] by software. */
      vuint32_t TRG_ECNTOFL:1;         /* Trigger bit TIM_CHn_IRQ_NOTIFY[ECNTOFL] by software. */
      vuint32_t TRG_NEWVAL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[NEWVAL] by software. */
    } B;
  } CH2_IRQ_FORCINT;

  union {                              /* TIM Channel n Interrupt Request Mode Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH2_IRQ_MODE;

  union {                              /* TIM Channel Error Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET_EIRQ_EN:1;   /* TIM_GLITCHDETx_IRQ interrupt enable. */
      vuint32_t TODET_EIRQ_EN:1;       /* TIM_TODETx_IRQ interrupt enable. */
      vuint32_t GPROFL_EIRQ_EN:1;      /* TIM_GPROFL_IRQ interrupt enable. */
      vuint32_t CNTOFL_EIRQ_EN:1;      /* TIM_CNTOFLx_IRQ interrupt enable. */
      vuint32_t ECNTOFL_EIRQ_EN:1;     /* TIM_ECNTOFLx_IRQ interrupt enable. */
      vuint32_t NEWVAL_EIRQ_EN:1;      /* TIM_NEWVALx_EIRQ error interrupt enable. */
    } B;
  } CH2_EIRQ_EN;

  uint8_t TIM_reserved2[64];
  union {                              /* TIM Channel n General Purpose Register 0, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t GPR0:24;               /* Input signal characteristic parameter 0. */
    } B;
  } CH3_GPR0;

  union {                              /* TIM Channel n General Purpose Register 1, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t GPR1:24;               /* Input signal characteristic parameter 1. */
    } B;
  } CH3_GPR1;

  union {                              /* TIM Channel n Count Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CNT:24;                /* Actual SMU counter value. */
    } B;
  } CH3_CNT;

  union {                              /* TIM Channel n Edge Counter Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t ECNT:16;               /* Edge counter. */
    } B;
  } CH3_ECNT;

  union {                              /* TIM Channel n Counter Shadow Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t CNTS:24;               /* Counter shadow register. */
    } B;
  } CH3_CNTS;

  union {                              /* TIM Channel n TDUC Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :24;
      vuint32_t TO_CNT:8;              /* Current Timeout value for channel n (n:0...m-1). */
    } B;
  } CH3_TDUC;

  union {                              /* TIM Channel n TDUV Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :1;
      vuint32_t TCS:3;                 /* Timeout Clock selection. */
      vuint32_t  :20;
      vuint32_t TOV:8;                 /* Time out duration for channel n (n:0...m-1). */
    } B;
  } CH3_TDUV;

  union {                              /* TIM Channel n Filter Parameter 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t FLT_RE:24;             /* Filter parameter for rising edge. */
    } B;
  } CH3_FLT_RE;

  union {                              /* TIM Channel n Filter Parameter 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t FLT_FE:24;             /* Filter parameter for falling edge. */
    } B;
  } CH3_FLT_FE;

  union {                              /* TIM Channel n Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t TOCTRL:2;              /* Timeout control */
      vuint32_t EGPR1_SEL:1;           /* Extension of GPR1_SEL bit field. */
      vuint32_t EGPR0_SEL:1;           /* Extension of GPR0_SEL bit field. */
      vuint32_t FR_ECNT_OFL:1;         /* Extended Edge counter overflow behavior. */
      vuint32_t CLK_SEL:3;             /* CMU clock source select for channel. */
      vuint32_t FLT_CTR_FE:1;          /* Filter counter mode for falling edge. */
      vuint32_t FLT_MODE_FE:1;         /* Filter mode for falling edge. */
      vuint32_t FLT_CTR_RE:1;          /* Filter counter mode for rising edge. */
      vuint32_t FLT_MODE_RE:1;         /* Filter mode for rising edge. */
      vuint32_t EXT_CAP_EN:1;          /* Enables external capture mode. The selected TIM mode is only sensitive to external capture pulses, the input event changes are ignored. */
      vuint32_t FLT_CNT_FRQ:2;         /* Filter counter frequency select. */
      vuint32_t FLT_EN:1;              /* Filter enable for channel n. */
      vuint32_t ECNT_RESET:1;          /* Enables resetting the ECNT counter in periodic sampling mode. */
      vuint32_t ISL:1;                 /* Ignore Signal Level. */
      vuint32_t DSL:1;                 /* Signal level control. */
      vuint32_t CNTS_SEL:1;            /* Selection for CNTS register. */
      vuint32_t GPR1_SEL:2;            /* Selection for GPR1 register. */
      vuint32_t GPR0_SEL:2;            /* Selection for GPR0 register. */
      vuint32_t TBU0_SEL:1;            /* TBU_TS0 bits input select for TIM_CHn_GPRz (z: 0, 1) */
      vuint32_t CICTRL:1;              /* Channel Input Control. */
      vuint32_t ARU_EN:1;              /* GPR0 and GPR1 register values routed to ARU. */
      vuint32_t OSM:1;                 /* One-shot mode. */
      vuint32_t TIM_MODE:3;            /* TIM channel n mode. */
      vuint32_t TIM_EN:1;              /* TIM channel n enable. */
    } B;
  } CH3_CTRL;

  union {                              /* TIM Channel n External Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t EXT_CAP_SRC:3;         /* Defines selected source for triggering the EXT_CAPTURE functionality. */
    } B;
  } CH3_ECTRL;

  union {                              /* TIM Channel n Interrupt Request Notification Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET:1;           /* Glitch detected on channel n. */
      vuint32_t TODET:1;               /* Timeout reached for input signal of channel n. */
      vuint32_t GPROFL:1;              /* GPR0 and GPR1 data overflow, old data not read out before new data has arrived at input pin. */
      vuint32_t CNTOFL:1;              /* SMU CNT counter overflow of channel n. */
      vuint32_t ECNTOFL:1;             /* ECNT counter overflow of channel n. */
      vuint32_t NEWVAL:1;              /* New measurement value detected by in channel n */
    } B;
  } CH3_IRQ_NOTIFY;

  union {                              /* TIM Channel n Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET_IRQ_EN:1;    /* TIM_GLITCHDETx_IRQ interrupt enable. */
      vuint32_t TODET_IRQ_EN:1;        /* TIM_TODETn_IRQ interrupt enable. */
      vuint32_t GPROFL_IRQ_EN:1;       /* TIM_GPROFL_IRQ interrupt enable. */
      vuint32_t CNTOFL_IRQ_EN:1;       /* TIM_CNTOFLn_IRQ interrupt enable. */
      vuint32_t ECNTOFL_IRQ_EN:1;      /* TIM_ECNTOFLn_IRQ interrupt enable. */
      vuint32_t NEWVAL_IRQ_EN:1;       /* TIM_NEWVALn_IRQ interrupt enable. */
    } B;
  } CH3_IRQ_EN;

  union {                              /* TIM Channel n Force Interrupt Request Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t TRG_GLITCHDET:1;       /* Trigger bit TIM_CHn_IRQ_NOTIFY[GLITCHDET] by software. */
      vuint32_t TRG_TODET:1;           /* Trigger bit TIM_CHn_IRQ_NOTIFY[TODET] by software. */
      vuint32_t TRG_GPROFL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[GPROFL] by software. */
      vuint32_t TRG_CNTOFL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[CNTOFL] by software. */
      vuint32_t TRG_ECNTOFL:1;         /* Trigger bit TIM_CHn_IRQ_NOTIFY[ECNTOFL] by software. */
      vuint32_t TRG_NEWVAL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[NEWVAL] by software. */
    } B;
  } CH3_IRQ_FORCINT;

  union {                              /* TIM Channel n Interrupt Request Mode Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH3_IRQ_MODE;

  union {                              /* TIM Channel Error Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET_EIRQ_EN:1;   /* TIM_GLITCHDETx_IRQ interrupt enable. */
      vuint32_t TODET_EIRQ_EN:1;       /* TIM_TODETx_IRQ interrupt enable. */
      vuint32_t GPROFL_EIRQ_EN:1;      /* TIM_GPROFL_IRQ interrupt enable. */
      vuint32_t CNTOFL_EIRQ_EN:1;      /* TIM_CNTOFLx_IRQ interrupt enable. */
      vuint32_t ECNTOFL_EIRQ_EN:1;     /* TIM_ECNTOFLx_IRQ interrupt enable. */
      vuint32_t NEWVAL_EIRQ_EN:1;      /* TIM_NEWVALx_EIRQ error interrupt enable. */
    } B;
  } CH3_EIRQ_EN;

  uint8_t TIM_reserved3[64];
  union {                              /* TIM Channel n General Purpose Register 0, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t GPR0:24;               /* Input signal characteristic parameter 0. */
    } B;
  } CH4_GPR0;

  union {                              /* TIM Channel n General Purpose Register 1, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t GPR1:24;               /* Input signal characteristic parameter 1. */
    } B;
  } CH4_GPR1;

  union {                              /* TIM Channel n Count Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CNT:24;                /* Actual SMU counter value. */
    } B;
  } CH4_CNT;

  union {                              /* TIM Channel n Edge Counter Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t ECNT:16;               /* Edge counter. */
    } B;
  } CH4_ECNT;

  union {                              /* TIM Channel n Counter Shadow Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t CNTS:24;               /* Counter shadow register. */
    } B;
  } CH4_CNTS;

  union {                              /* TIM Channel n TDUC Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :24;
      vuint32_t TO_CNT:8;              /* Current Timeout value for channel n (n:0...m-1). */
    } B;
  } CH4_TDUC;

  union {                              /* TIM Channel n TDUV Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :1;
      vuint32_t TCS:3;                 /* Timeout Clock selection. */
      vuint32_t  :20;
      vuint32_t TOV:8;                 /* Time out duration for channel n (n:0...m-1). */
    } B;
  } CH4_TDUV;

  union {                              /* TIM Channel n Filter Parameter 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t FLT_RE:24;             /* Filter parameter for rising edge. */
    } B;
  } CH4_FLT_RE;

  union {                              /* TIM Channel n Filter Parameter 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t FLT_FE:24;             /* Filter parameter for falling edge. */
    } B;
  } CH4_FLT_FE;

  union {                              /* TIM Channel n Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t TOCTRL:2;              /* Timeout control */
      vuint32_t EGPR1_SEL:1;           /* Extension of GPR1_SEL bit field. */
      vuint32_t EGPR0_SEL:1;           /* Extension of GPR0_SEL bit field. */
      vuint32_t FR_ECNT_OFL:1;         /* Extended Edge counter overflow behavior. */
      vuint32_t CLK_SEL:3;             /* CMU clock source select for channel. */
      vuint32_t FLT_CTR_FE:1;          /* Filter counter mode for falling edge. */
      vuint32_t FLT_MODE_FE:1;         /* Filter mode for falling edge. */
      vuint32_t FLT_CTR_RE:1;          /* Filter counter mode for rising edge. */
      vuint32_t FLT_MODE_RE:1;         /* Filter mode for rising edge. */
      vuint32_t EXT_CAP_EN:1;          /* Enables external capture mode. The selected TIM mode is only sensitive to external capture pulses, the input event changes are ignored. */
      vuint32_t FLT_CNT_FRQ:2;         /* Filter counter frequency select. */
      vuint32_t FLT_EN:1;              /* Filter enable for channel n. */
      vuint32_t ECNT_RESET:1;          /* Enables resetting the ECNT counter in periodic sampling mode. */
      vuint32_t ISL:1;                 /* Ignore Signal Level. */
      vuint32_t DSL:1;                 /* Signal level control. */
      vuint32_t CNTS_SEL:1;            /* Selection for CNTS register. */
      vuint32_t GPR1_SEL:2;            /* Selection for GPR1 register. */
      vuint32_t GPR0_SEL:2;            /* Selection for GPR0 register. */
      vuint32_t TBU0_SEL:1;            /* TBU_TS0 bits input select for TIM_CHn_GPRz (z: 0, 1) */
      vuint32_t CICTRL:1;              /* Channel Input Control. */
      vuint32_t ARU_EN:1;              /* GPR0 and GPR1 register values routed to ARU. */
      vuint32_t OSM:1;                 /* One-shot mode. */
      vuint32_t TIM_MODE:3;            /* TIM channel n mode. */
      vuint32_t TIM_EN:1;              /* TIM channel n enable. */
    } B;
  } CH4_CTRL;

  union {                              /* TIM Channel n External Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t EXT_CAP_SRC:3;         /* Defines selected source for triggering the EXT_CAPTURE functionality. */
    } B;
  } CH4_ECTRL;

  union {                              /* TIM Channel n Interrupt Request Notification Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET:1;           /* Glitch detected on channel n. */
      vuint32_t TODET:1;               /* Timeout reached for input signal of channel n. */
      vuint32_t GPROFL:1;              /* GPR0 and GPR1 data overflow, old data not read out before new data has arrived at input pin. */
      vuint32_t CNTOFL:1;              /* SMU CNT counter overflow of channel n. */
      vuint32_t ECNTOFL:1;             /* ECNT counter overflow of channel n. */
      vuint32_t NEWVAL:1;              /* New measurement value detected by in channel n */
    } B;
  } CH4_IRQ_NOTIFY;

  union {                              /* TIM Channel n Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET_IRQ_EN:1;    /* TIM_GLITCHDETx_IRQ interrupt enable. */
      vuint32_t TODET_IRQ_EN:1;        /* TIM_TODETn_IRQ interrupt enable. */
      vuint32_t GPROFL_IRQ_EN:1;       /* TIM_GPROFL_IRQ interrupt enable. */
      vuint32_t CNTOFL_IRQ_EN:1;       /* TIM_CNTOFLn_IRQ interrupt enable. */
      vuint32_t ECNTOFL_IRQ_EN:1;      /* TIM_ECNTOFLn_IRQ interrupt enable. */
      vuint32_t NEWVAL_IRQ_EN:1;       /* TIM_NEWVALn_IRQ interrupt enable. */
    } B;
  } CH4_IRQ_EN;

  union {                              /* TIM Channel n Force Interrupt Request Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t TRG_GLITCHDET:1;       /* Trigger bit TIM_CHn_IRQ_NOTIFY[GLITCHDET] by software. */
      vuint32_t TRG_TODET:1;           /* Trigger bit TIM_CHn_IRQ_NOTIFY[TODET] by software. */
      vuint32_t TRG_GPROFL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[GPROFL] by software. */
      vuint32_t TRG_CNTOFL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[CNTOFL] by software. */
      vuint32_t TRG_ECNTOFL:1;         /* Trigger bit TIM_CHn_IRQ_NOTIFY[ECNTOFL] by software. */
      vuint32_t TRG_NEWVAL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[NEWVAL] by software. */
    } B;
  } CH4_IRQ_FORCINT;

  union {                              /* TIM Channel n Interrupt Request Mode Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH4_IRQ_MODE;

  union {                              /* TIM Channel Error Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET_EIRQ_EN:1;   /* TIM_GLITCHDETx_IRQ interrupt enable. */
      vuint32_t TODET_EIRQ_EN:1;       /* TIM_TODETx_IRQ interrupt enable. */
      vuint32_t GPROFL_EIRQ_EN:1;      /* TIM_GPROFL_IRQ interrupt enable. */
      vuint32_t CNTOFL_EIRQ_EN:1;      /* TIM_CNTOFLx_IRQ interrupt enable. */
      vuint32_t ECNTOFL_EIRQ_EN:1;     /* TIM_ECNTOFLx_IRQ interrupt enable. */
      vuint32_t NEWVAL_EIRQ_EN:1;      /* TIM_NEWVALx_EIRQ error interrupt enable. */
    } B;
  } CH4_EIRQ_EN;

  uint8_t TIM_reserved4[64];
  union {                              /* TIM Channel n General Purpose Register 0, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t GPR0:24;               /* Input signal characteristic parameter 0. */
    } B;
  } CH5_GPR0;

  union {                              /* TIM Channel n General Purpose Register 1, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t GPR1:24;               /* Input signal characteristic parameter 1. */
    } B;
  } CH5_GPR1;

  union {                              /* TIM Channel n Count Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CNT:24;                /* Actual SMU counter value. */
    } B;
  } CH5_CNT;

  union {                              /* TIM Channel n Edge Counter Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t ECNT:16;               /* Edge counter. */
    } B;
  } CH5_ECNT;

  union {                              /* TIM Channel n Counter Shadow Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t CNTS:24;               /* Counter shadow register. */
    } B;
  } CH5_CNTS;

  union {                              /* TIM Channel n TDUC Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :24;
      vuint32_t TO_CNT:8;              /* Current Timeout value for channel n (n:0...m-1). */
    } B;
  } CH5_TDUC;

  union {                              /* TIM Channel n TDUV Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :1;
      vuint32_t TCS:3;                 /* Timeout Clock selection. */
      vuint32_t  :20;
      vuint32_t TOV:8;                 /* Time out duration for channel n (n:0...m-1). */
    } B;
  } CH5_TDUV;

  union {                              /* TIM Channel n Filter Parameter 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t FLT_RE:24;             /* Filter parameter for rising edge. */
    } B;
  } CH5_FLT_RE;

  union {                              /* TIM Channel n Filter Parameter 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t FLT_FE:24;             /* Filter parameter for falling edge. */
    } B;
  } CH5_FLT_FE;

  union {                              /* TIM Channel n Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t TOCTRL:2;              /* Timeout control */
      vuint32_t EGPR1_SEL:1;           /* Extension of GPR1_SEL bit field. */
      vuint32_t EGPR0_SEL:1;           /* Extension of GPR0_SEL bit field. */
      vuint32_t FR_ECNT_OFL:1;         /* Extended Edge counter overflow behavior. */
      vuint32_t CLK_SEL:3;             /* CMU clock source select for channel. */
      vuint32_t FLT_CTR_FE:1;          /* Filter counter mode for falling edge. */
      vuint32_t FLT_MODE_FE:1;         /* Filter mode for falling edge. */
      vuint32_t FLT_CTR_RE:1;          /* Filter counter mode for rising edge. */
      vuint32_t FLT_MODE_RE:1;         /* Filter mode for rising edge. */
      vuint32_t EXT_CAP_EN:1;          /* Enables external capture mode. The selected TIM mode is only sensitive to external capture pulses, the input event changes are ignored. */
      vuint32_t FLT_CNT_FRQ:2;         /* Filter counter frequency select. */
      vuint32_t FLT_EN:1;              /* Filter enable for channel n. */
      vuint32_t ECNT_RESET:1;          /* Enables resetting the ECNT counter in periodic sampling mode. */
      vuint32_t ISL:1;                 /* Ignore Signal Level. */
      vuint32_t DSL:1;                 /* Signal level control. */
      vuint32_t CNTS_SEL:1;            /* Selection for CNTS register. */
      vuint32_t GPR1_SEL:2;            /* Selection for GPR1 register. */
      vuint32_t GPR0_SEL:2;            /* Selection for GPR0 register. */
      vuint32_t TBU0_SEL:1;            /* TBU_TS0 bits input select for TIM_CHn_GPRz (z: 0, 1) */
      vuint32_t CICTRL:1;              /* Channel Input Control. */
      vuint32_t ARU_EN:1;              /* GPR0 and GPR1 register values routed to ARU. */
      vuint32_t OSM:1;                 /* One-shot mode. */
      vuint32_t TIM_MODE:3;            /* TIM channel n mode. */
      vuint32_t TIM_EN:1;              /* TIM channel n enable. */
    } B;
  } CH5_CTRL;

  union {                              /* TIM Channel n External Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t EXT_CAP_SRC:3;         /* Defines selected source for triggering the EXT_CAPTURE functionality. */
    } B;
  } CH5_ECTRL;

  union {                              /* TIM Channel n Interrupt Request Notification Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET:1;           /* Glitch detected on channel n. */
      vuint32_t TODET:1;               /* Timeout reached for input signal of channel n. */
      vuint32_t GPROFL:1;              /* GPR0 and GPR1 data overflow, old data not read out before new data has arrived at input pin. */
      vuint32_t CNTOFL:1;              /* SMU CNT counter overflow of channel n. */
      vuint32_t ECNTOFL:1;             /* ECNT counter overflow of channel n. */
      vuint32_t NEWVAL:1;              /* New measurement value detected by in channel n */
    } B;
  } CH5_IRQ_NOTIFY;

  union {                              /* TIM Channel n Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET_IRQ_EN:1;    /* TIM_GLITCHDETx_IRQ interrupt enable. */
      vuint32_t TODET_IRQ_EN:1;        /* TIM_TODETn_IRQ interrupt enable. */
      vuint32_t GPROFL_IRQ_EN:1;       /* TIM_GPROFL_IRQ interrupt enable. */
      vuint32_t CNTOFL_IRQ_EN:1;       /* TIM_CNTOFLn_IRQ interrupt enable. */
      vuint32_t ECNTOFL_IRQ_EN:1;      /* TIM_ECNTOFLn_IRQ interrupt enable. */
      vuint32_t NEWVAL_IRQ_EN:1;       /* TIM_NEWVALn_IRQ interrupt enable. */
    } B;
  } CH5_IRQ_EN;

  union {                              /* TIM Channel n Force Interrupt Request Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t TRG_GLITCHDET:1;       /* Trigger bit TIM_CHn_IRQ_NOTIFY[GLITCHDET] by software. */
      vuint32_t TRG_TODET:1;           /* Trigger bit TIM_CHn_IRQ_NOTIFY[TODET] by software. */
      vuint32_t TRG_GPROFL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[GPROFL] by software. */
      vuint32_t TRG_CNTOFL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[CNTOFL] by software. */
      vuint32_t TRG_ECNTOFL:1;         /* Trigger bit TIM_CHn_IRQ_NOTIFY[ECNTOFL] by software. */
      vuint32_t TRG_NEWVAL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[NEWVAL] by software. */
    } B;
  } CH5_IRQ_FORCINT;

  union {                              /* TIM Channel n Interrupt Request Mode Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH5_IRQ_MODE;

  union {                              /* TIM Channel Error Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET_EIRQ_EN:1;   /* TIM_GLITCHDETx_IRQ interrupt enable. */
      vuint32_t TODET_EIRQ_EN:1;       /* TIM_TODETx_IRQ interrupt enable. */
      vuint32_t GPROFL_EIRQ_EN:1;      /* TIM_GPROFL_IRQ interrupt enable. */
      vuint32_t CNTOFL_EIRQ_EN:1;      /* TIM_CNTOFLx_IRQ interrupt enable. */
      vuint32_t ECNTOFL_EIRQ_EN:1;     /* TIM_ECNTOFLx_IRQ interrupt enable. */
      vuint32_t NEWVAL_EIRQ_EN:1;      /* TIM_NEWVALx_EIRQ error interrupt enable. */
    } B;
  } CH5_EIRQ_EN;

  uint8_t TIM_reserved5[64];
  union {                              /* TIM Channel n General Purpose Register 0, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t GPR0:24;               /* Input signal characteristic parameter 0. */
    } B;
  } CH6_GPR0;

  union {                              /* TIM Channel n General Purpose Register 1, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t GPR1:24;               /* Input signal characteristic parameter 1. */
    } B;
  } CH6_GPR1;

  union {                              /* TIM Channel n Count Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CNT:24;                /* Actual SMU counter value. */
    } B;
  } CH6_CNT;

  union {                              /* TIM Channel n Edge Counter Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t ECNT:16;               /* Edge counter. */
    } B;
  } CH6_ECNT;

  union {                              /* TIM Channel n Counter Shadow Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t CNTS:24;               /* Counter shadow register. */
    } B;
  } CH6_CNTS;

  union {                              /* TIM Channel n TDUC Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :24;
      vuint32_t TO_CNT:8;              /* Current Timeout value for channel n (n:0...m-1). */
    } B;
  } CH6_TDUC;

  union {                              /* TIM Channel n TDUV Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :1;
      vuint32_t TCS:3;                 /* Timeout Clock selection. */
      vuint32_t  :20;
      vuint32_t TOV:8;                 /* Time out duration for channel n (n:0...m-1). */
    } B;
  } CH6_TDUV;

  union {                              /* TIM Channel n Filter Parameter 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t FLT_RE:24;             /* Filter parameter for rising edge. */
    } B;
  } CH6_FLT_RE;

  union {                              /* TIM Channel n Filter Parameter 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t FLT_FE:24;             /* Filter parameter for falling edge. */
    } B;
  } CH6_FLT_FE;

  union {                              /* TIM Channel n Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t TOCTRL:2;              /* Timeout control */
      vuint32_t EGPR1_SEL:1;           /* Extension of GPR1_SEL bit field. */
      vuint32_t EGPR0_SEL:1;           /* Extension of GPR0_SEL bit field. */
      vuint32_t FR_ECNT_OFL:1;         /* Extended Edge counter overflow behavior. */
      vuint32_t CLK_SEL:3;             /* CMU clock source select for channel. */
      vuint32_t FLT_CTR_FE:1;          /* Filter counter mode for falling edge. */
      vuint32_t FLT_MODE_FE:1;         /* Filter mode for falling edge. */
      vuint32_t FLT_CTR_RE:1;          /* Filter counter mode for rising edge. */
      vuint32_t FLT_MODE_RE:1;         /* Filter mode for rising edge. */
      vuint32_t EXT_CAP_EN:1;          /* Enables external capture mode. The selected TIM mode is only sensitive to external capture pulses, the input event changes are ignored. */
      vuint32_t FLT_CNT_FRQ:2;         /* Filter counter frequency select. */
      vuint32_t FLT_EN:1;              /* Filter enable for channel n. */
      vuint32_t ECNT_RESET:1;          /* Enables resetting the ECNT counter in periodic sampling mode. */
      vuint32_t ISL:1;                 /* Ignore Signal Level. */
      vuint32_t DSL:1;                 /* Signal level control. */
      vuint32_t CNTS_SEL:1;            /* Selection for CNTS register. */
      vuint32_t GPR1_SEL:2;            /* Selection for GPR1 register. */
      vuint32_t GPR0_SEL:2;            /* Selection for GPR0 register. */
      vuint32_t TBU0_SEL:1;            /* TBU_TS0 bits input select for TIM_CHn_GPRz (z: 0, 1) */
      vuint32_t CICTRL:1;              /* Channel Input Control. */
      vuint32_t ARU_EN:1;              /* GPR0 and GPR1 register values routed to ARU. */
      vuint32_t OSM:1;                 /* One-shot mode. */
      vuint32_t TIM_MODE:3;            /* TIM channel n mode. */
      vuint32_t TIM_EN:1;              /* TIM channel n enable. */
    } B;
  } CH6_CTRL;

  union {                              /* TIM Channel n External Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t EXT_CAP_SRC:3;         /* Defines selected source for triggering the EXT_CAPTURE functionality. */
    } B;
  } CH6_ECTRL;

  union {                              /* TIM Channel n Interrupt Request Notification Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET:1;           /* Glitch detected on channel n. */
      vuint32_t TODET:1;               /* Timeout reached for input signal of channel n. */
      vuint32_t GPROFL:1;              /* GPR0 and GPR1 data overflow, old data not read out before new data has arrived at input pin. */
      vuint32_t CNTOFL:1;              /* SMU CNT counter overflow of channel n. */
      vuint32_t ECNTOFL:1;             /* ECNT counter overflow of channel n. */
      vuint32_t NEWVAL:1;              /* New measurement value detected by in channel n */
    } B;
  } CH6_IRQ_NOTIFY;

  union {                              /* TIM Channel n Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET_IRQ_EN:1;    /* TIM_GLITCHDETx_IRQ interrupt enable. */
      vuint32_t TODET_IRQ_EN:1;        /* TIM_TODETn_IRQ interrupt enable. */
      vuint32_t GPROFL_IRQ_EN:1;       /* TIM_GPROFL_IRQ interrupt enable. */
      vuint32_t CNTOFL_IRQ_EN:1;       /* TIM_CNTOFLn_IRQ interrupt enable. */
      vuint32_t ECNTOFL_IRQ_EN:1;      /* TIM_ECNTOFLn_IRQ interrupt enable. */
      vuint32_t NEWVAL_IRQ_EN:1;       /* TIM_NEWVALn_IRQ interrupt enable. */
    } B;
  } CH6_IRQ_EN;

  union {                              /* TIM Channel n Force Interrupt Request Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t TRG_GLITCHDET:1;       /* Trigger bit TIM_CHn_IRQ_NOTIFY[GLITCHDET] by software. */
      vuint32_t TRG_TODET:1;           /* Trigger bit TIM_CHn_IRQ_NOTIFY[TODET] by software. */
      vuint32_t TRG_GPROFL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[GPROFL] by software. */
      vuint32_t TRG_CNTOFL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[CNTOFL] by software. */
      vuint32_t TRG_ECNTOFL:1;         /* Trigger bit TIM_CHn_IRQ_NOTIFY[ECNTOFL] by software. */
      vuint32_t TRG_NEWVAL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[NEWVAL] by software. */
    } B;
  } CH6_IRQ_FORCINT;

  union {                              /* TIM Channel n Interrupt Request Mode Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH6_IRQ_MODE;

  union {                              /* TIM Channel Error Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET_EIRQ_EN:1;   /* TIM_GLITCHDETx_IRQ interrupt enable. */
      vuint32_t TODET_EIRQ_EN:1;       /* TIM_TODETx_IRQ interrupt enable. */
      vuint32_t GPROFL_EIRQ_EN:1;      /* TIM_GPROFL_IRQ interrupt enable. */
      vuint32_t CNTOFL_EIRQ_EN:1;      /* TIM_CNTOFLx_IRQ interrupt enable. */
      vuint32_t ECNTOFL_EIRQ_EN:1;     /* TIM_ECNTOFLx_IRQ interrupt enable. */
      vuint32_t NEWVAL_EIRQ_EN:1;      /* TIM_NEWVALx_EIRQ error interrupt enable. */
    } B;
  } CH6_EIRQ_EN;

  uint8_t TIM_reserved6[64];
  union {                              /* TIM Channel n General Purpose Register 0, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t GPR0:24;               /* Input signal characteristic parameter 0. */
    } B;
  } CH7_GPR0;

  union {                              /* TIM Channel n General Purpose Register 1, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t GPR1:24;               /* Input signal characteristic parameter 1. */
    } B;
  } CH7_GPR1;

  union {                              /* TIM Channel n Count Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t CNT:24;                /* Actual SMU counter value. */
    } B;
  } CH7_CNT;

  union {                              /* TIM Channel n Edge Counter Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t ECNT:16;               /* Edge counter. */
    } B;
  } CH7_ECNT;

  union {                              /* TIM Channel n Counter Shadow Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t ECNT:8;                /* Edge counter. */
      vuint32_t CNTS:24;               /* Counter shadow register. */
    } B;
  } CH7_CNTS;

  union {                              /* TIM Channel n TDUC Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :24;
      vuint32_t TO_CNT:8;              /* Current Timeout value for channel n (n:0...m-1). */
    } B;
  } CH7_TDUC;

  union {                              /* TIM Channel n TDUV Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :1;
      vuint32_t TCS:3;                 /* Timeout Clock selection. */
      vuint32_t  :20;
      vuint32_t TOV:8;                 /* Time out duration for channel n (n:0...m-1). */
    } B;
  } CH7_TDUV;

  union {                              /* TIM Channel n Filter Parameter 0 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t FLT_RE:24;             /* Filter parameter for rising edge. */
    } B;
  } CH7_FLT_RE;

  union {                              /* TIM Channel n Filter Parameter 1 Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :8;
      vuint32_t FLT_FE:24;             /* Filter parameter for falling edge. */
    } B;
  } CH7_FLT_FE;

  union {                              /* TIM Channel n Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t TOCTRL:2;              /* Timeout control */
      vuint32_t EGPR1_SEL:1;           /* Extension of GPR1_SEL bit field. */
      vuint32_t EGPR0_SEL:1;           /* Extension of GPR0_SEL bit field. */
      vuint32_t FR_ECNT_OFL:1;         /* Extended Edge counter overflow behavior. */
      vuint32_t CLK_SEL:3;             /* CMU clock source select for channel. */
      vuint32_t FLT_CTR_FE:1;          /* Filter counter mode for falling edge. */
      vuint32_t FLT_MODE_FE:1;         /* Filter mode for falling edge. */
      vuint32_t FLT_CTR_RE:1;          /* Filter counter mode for rising edge. */
      vuint32_t FLT_MODE_RE:1;         /* Filter mode for rising edge. */
      vuint32_t EXT_CAP_EN:1;          /* Enables external capture mode. The selected TIM mode is only sensitive to external capture pulses, the input event changes are ignored. */
      vuint32_t FLT_CNT_FRQ:2;         /* Filter counter frequency select. */
      vuint32_t FLT_EN:1;              /* Filter enable for channel n. */
      vuint32_t ECNT_RESET:1;          /* Enables resetting the ECNT counter in periodic sampling mode. */
      vuint32_t ISL:1;                 /* Ignore Signal Level. */
      vuint32_t DSL:1;                 /* Signal level control. */
      vuint32_t CNTS_SEL:1;            /* Selection for CNTS register. */
      vuint32_t GPR1_SEL:2;            /* Selection for GPR1 register. */
      vuint32_t GPR0_SEL:2;            /* Selection for GPR0 register. */
      vuint32_t TBU0_SEL:1;            /* TBU_TS0 bits input select for TIM_CHn_GPRz (z: 0, 1) */
      vuint32_t CICTRL:1;              /* Channel Input Control. */
      vuint32_t ARU_EN:1;              /* GPR0 and GPR1 register values routed to ARU. */
      vuint32_t OSM:1;                 /* One-shot mode. */
      vuint32_t TIM_MODE:3;            /* TIM channel n mode. */
      vuint32_t TIM_EN:1;              /* TIM channel n enable. */
    } B;
  } CH7_CTRL;

  union {                              /* TIM Channel n External Control Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :29;
      vuint32_t EXT_CAP_SRC:3;         /* Defines selected source for triggering the EXT_CAPTURE functionality. */
    } B;
  } CH7_ECTRL;

  union {                              /* TIM Channel n Interrupt Request Notification Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET:1;           /* Glitch detected on channel n. */
      vuint32_t TODET:1;               /* Timeout reached for input signal of channel n. */
      vuint32_t GPROFL:1;              /* GPR0 and GPR1 data overflow, old data not read out before new data has arrived at input pin. */
      vuint32_t CNTOFL:1;              /* SMU CNT counter overflow of channel n. */
      vuint32_t ECNTOFL:1;             /* ECNT counter overflow of channel n. */
      vuint32_t NEWVAL:1;              /* New measurement value detected by in channel n */
    } B;
  } CH7_IRQ_NOTIFY;

  union {                              /* TIM Channel n Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET_IRQ_EN:1;    /* TIM_GLITCHDETx_IRQ interrupt enable. */
      vuint32_t TODET_IRQ_EN:1;        /* TIM_TODETn_IRQ interrupt enable. */
      vuint32_t GPROFL_IRQ_EN:1;       /* TIM_GPROFL_IRQ interrupt enable. */
      vuint32_t CNTOFL_IRQ_EN:1;       /* TIM_CNTOFLn_IRQ interrupt enable. */
      vuint32_t ECNTOFL_IRQ_EN:1;      /* TIM_ECNTOFLn_IRQ interrupt enable. */
      vuint32_t NEWVAL_IRQ_EN:1;       /* TIM_NEWVALn_IRQ interrupt enable. */
    } B;
  } CH7_IRQ_EN;

  union {                              /* TIM Channel n Force Interrupt Request Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t TRG_GLITCHDET:1;       /* Trigger bit TIM_CHn_IRQ_NOTIFY[GLITCHDET] by software. */
      vuint32_t TRG_TODET:1;           /* Trigger bit TIM_CHn_IRQ_NOTIFY[TODET] by software. */
      vuint32_t TRG_GPROFL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[GPROFL] by software. */
      vuint32_t TRG_CNTOFL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[CNTOFL] by software. */
      vuint32_t TRG_ECNTOFL:1;         /* Trigger bit TIM_CHn_IRQ_NOTIFY[ECNTOFL] by software. */
      vuint32_t TRG_NEWVAL:1;          /* Trigger bit TIM_CHn_IRQ_NOTIFY[NEWVAL] by software. */
    } B;
  } CH7_IRQ_FORCINT;

  union {                              /* TIM Channel n Interrupt Request Mode Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH7_IRQ_MODE;

  union {                              /* TIM Channel Error Interrupt Request Enable Register, n=0:7 */
    vuint32_t R;
    struct {
      vuint32_t  :26;
      vuint32_t GLITCHDET_EIRQ_EN:1;   /* TIM_GLITCHDETx_IRQ interrupt enable. */
      vuint32_t TODET_EIRQ_EN:1;       /* TIM_TODETx_IRQ interrupt enable. */
      vuint32_t GPROFL_EIRQ_EN:1;      /* TIM_GPROFL_IRQ interrupt enable. */
      vuint32_t CNTOFL_EIRQ_EN:1;      /* TIM_CNTOFLx_IRQ interrupt enable. */
      vuint32_t ECNTOFL_EIRQ_EN:1;     /* TIM_ECNTOFLx_IRQ interrupt enable. */
      vuint32_t NEWVAL_EIRQ_EN:1;      /* TIM_NEWVALx_EIRQ error interrupt enable. */
    } B;
  } CH7_EIRQ_EN;
};


/* ============================================================================
   =============================== Module: GTM_TOM ============================
   ============================================================================ */

struct GTM_TOM_tag {
  union {                              /* TOM Channel n Control Register, n[0:14] */
    vuint32_t R;
    struct {
      vuint32_t  :2;
      vuint32_t GCM:1;                 /* Gated Counter Mode enable. */
      vuint32_t SPEM:1;                /* SPE mode enable for channel. */
      vuint32_t  :1;
      vuint32_t OSM:1;                 /* One-shot mode.. */
      vuint32_t  :1;
      vuint32_t TRIGOUT:1;             /* Trigger output selection (output signal TRIG_[n]) of module TOM_CH[n]. */
      vuint32_t  :3;
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :5;
      vuint32_t CLK_SRC_SR:3;          /* Clock source select for channel. */
      vuint32_t SL:1;                  /* Signal level for duty cycle. */
      vuint32_t  :11;
    } B;
  } CH0_CTRL;

  union {                              /* TOM Channel n Shadow 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR0:16;                /* TOM channel n shadow register SR0 for update of compare register CM0. */
    } B;
  } CH0_SR0;

  union {                              /* TOM Channel n Shadow 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR1:16;                /* TOM channel n shadow register SR1 for update of compare register CM1. */
    } B;
  } CH0_SR1;

  union {                              /* TOM Channel n Compare 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM0:16;                /* TOM CCU0 compare register. */
    } B;
  } CH0_CM0;

  union {                              /* TOM Channel n Compare 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM1:16;                /* TOM CCU1 compare register. */
    } B;
  } CH0_CM1;

  union {                              /* TOM Channel n CN0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CN0:16;                /* TOM CCU0 counter register. */
    } B;
  } CH0_CN0;

  union {                              /* TOM Channel n Status Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :31;                  /* Reserved. */
      vuint32_t OL:1;                  /* Output level of output TOM_OUT(n). */
    } B;
  } CH0_STAT;

  union {                              /* TOM Channel n Interrupt Request Notification Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH0_IRQ_NOTIFY;

  union {                              /* TOM Channel n Interrupt Request Enable Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH0_IRQ_EN;

  union {                              /* TOM Channel n Force Interrupt Request Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t TRG_CCU1TC0:1;         /* Trigger TOM_CCU1TC0_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC0:1;         /* Trigger TOM_CCU0TC0_IRQ interrupt by software. */
    } B;
  } CH0_IRQ_FORCINT;

  union {                              /* TOM Channel n Interrupt Request Mode Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH0_IRQ_MODE;

  uint8_t TOM_reserved0[4];
  union {                              /* TOM TGC0 Global Control Register */
    vuint32_t R;
    struct {
      vuint32_t UPEN_CTRL7:2;          /* TOM channel 7 enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t UPEN_CTRL6:2;          /* TOM channel 6 enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t UPEN_CTRL5:2;          /* TOM channel 5 enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t UPEN_CTRL4:2;          /* TOM channel 4 enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t UPEN_CTRL3:2;          /* TOM channel 3 enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t UPEN_CTRL2:2;          /* TOM channel 2 enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t UPEN_CTRL1:2;          /* TOM channel 1 enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t UPEN_CTRL0:2;          /* TOM channel 0 enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t RST_CH7:1;             /* Software reset of channel 7. */
      vuint32_t RST_CH6:1;             /* Software reset of channel 6. */
      vuint32_t RST_CH5:1;             /* Software reset of channel 5. */
      vuint32_t RST_CH4:1;             /* Software reset of channel 4. */
      vuint32_t RST_CH3:1;             /* Software reset of channel 3. */
      vuint32_t RST_CH2:1;             /* Software reset of channel 2. */
      vuint32_t RST_CH1:1;             /* Software reset of channel 1. */
      vuint32_t RST_CH0:1;             /* Software reset of channel 0. */
      vuint32_t  :7;
      vuint32_t HOST_TRIG:1;           /* Trigger request signal (see TGC0, TGC1) to update the register ENDIS_STAT and OUTEN_STAT. */
    } B;
  } TGC0_GLB_CTRL;

  union {                              /* TOM TGC0 Action Time Base Register */
    vuint32_t R;
    struct {
      vuint32_t  :5;
      vuint32_t TBU_SEL:2;             /* Selection of time base used for comparison. */
      vuint32_t TB_TRIG:1;             /* Set trigger request. */
      vuint32_t ACT_TB:24;             /* Specifies the signed compare value with selected signal TBU_TS[n], x=0..2. */
    } B;
  } TGC0_ACT_TB;

  union {                              /* TOM TGC0 Force Update Control Register */
    vuint32_t R;
    struct {
      vuint32_t RSTCN0_CH7:2;          /* Reset CN0 of channel 7 on force update event. */
      vuint32_t RSTCN0_CH6:2;          /* Reset CN0 of channel 6 on force update event. */
      vuint32_t RSTCN0_CH5:2;          /* Reset CN0 of channel 5 on force update event. */
      vuint32_t RSTCN0_CH4:2;          /* Reset CN0 of channel 4 on force update event. */
      vuint32_t RSTCN0_CH3:2;          /* Reset CN0 of channel 3 on force update event. */
      vuint32_t RSTCN0_CH2:2;          /* Reset CN0 of channel 2 on force update event. */
      vuint32_t RSTCN0_CH1:2;          /* Reset CN0 of channel 1 on force update event. */
      vuint32_t RSTCN0_CH0:2;          /* Reset CN0 of channel 0 on force update event. */
      vuint32_t FUPD_CTRL7:2;          /* Force update of TOM channel 7 operation registers. */
      vuint32_t FUPD_CTRL6:2;          /* Force update of TOM channel 6 operation registers, */
      vuint32_t FUPD_CTRL5:2;          /* Force update of TOM channel 5 operation registers. */
      vuint32_t FUPD_CTRL4:2;          /* Force update of TOM channel 4 operation registers. */
      vuint32_t FUPD_CTRL3:2;          /* Force update of TOM channel 3 operation registers. */
      vuint32_t FUPD_CTRL2:2;          /* ce update of TOM channel 2 operation registers. */
      vuint32_t FUPD_CTRL1:2;          /* Force update of TOM channel 1 operation registers. */
      vuint32_t FUPD_CTRL0:2;          /* Force update of TOM channel 0 operation registers. */
    } B;
  } TGC0_FUPD_CTRL;

  union {                              /* TOM TGC0 Interrupt Trigger Register */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t INT_TRIG7:2;           /* Select input signal TRIG_7 as a trigger source. */
      vuint32_t INT_TRIG6:2;           /* Select input signal TRIG_6 as a trigger source. */
      vuint32_t INT_TRIG5:2;           /* Select input signal TRIG_5 as a trigger source. */
      vuint32_t INT_TRIG4:2;           /* Select input signal TRIG_4 as a trigger source. */
      vuint32_t INT_TRIG3:2;           /* Select input signal TRIG_3 as a trigger source. */
      vuint32_t INT_TRIG2:2;           /* Select input signal TRIG_2 as a trigger source. */
      vuint32_t INT_TRIG1:2;           /* Select input signal TRIG_1 as a trigger source. */
      vuint32_t INT_TRIG0:2;           /* Select input signal TRIG_0 as a trigger source. */
    } B;
  } TGC0_INT_TRIG;

  union {                              /* TOM Channel n Control Register, n[0:14] */
    vuint32_t R;
    struct {
      vuint32_t  :2;
      vuint32_t GCM:1;                 /* Gated Counter Mode enable. */
      vuint32_t SPEM:1;                /* SPE mode enable for channel. */
      vuint32_t  :1;
      vuint32_t OSM:1;                 /* One-shot mode.. */
      vuint32_t  :1;
      vuint32_t TRIGOUT:1;             /* Trigger output selection (output signal TRIG_[n]) of module TOM_CH[n]. */
      vuint32_t  :3;
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :5;
      vuint32_t CLK_SRC_SR:3;          /* Clock source select for channel. */
      vuint32_t SL:1;                  /* Signal level for duty cycle. */
      vuint32_t  :11;
    } B;
  } CH1_CTRL;

  union {                              /* TOM Channel n Shadow 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR0:16;                /* TOM channel n shadow register SR0 for update of compare register CM0. */
    } B;
  } CH1_SR0;

  union {                              /* TOM Channel n Shadow 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR1:16;                /* TOM channel n shadow register SR1 for update of compare register CM1. */
    } B;
  } CH1_SR1;

  union {                              /* TOM Channel n Compare 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM0:16;                /* TOM CCU0 compare register. */
    } B;
  } CH1_CM0;

  union {                              /* TOM Channel n Compare 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM1:16;                /* TOM CCU1 compare register. */
    } B;
  } CH1_CM1;

  union {                              /* TOM Channel n CN0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CN0:16;                /* TOM CCU0 counter register. */
    } B;
  } CH1_CN0;

  union {                              /* TOM Channel n Status Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :31;                  /* Reserved. */
      vuint32_t OL:1;                  /* Output level of output TOM_OUT(n). */
    } B;
  } CH1_STAT;

  union {                              /* TOM Channel n Interrupt Request Notification Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH1_IRQ_NOTIFY;

  union {                              /* TOM Channel n Interrupt Request Enable Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH1_IRQ_EN;

  union {                              /* TOM Channel n Force Interrupt Request Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t TRG_CCU1TC0:1;         /* Trigger TOM_CCU1TC0_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC0:1;         /* Trigger TOM_CCU0TC0_IRQ interrupt by software. */
    } B;
  } CH1_IRQ_FORCINT;

  union {                              /* TOM Channel n Interrupt Request Mode Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH1_IRQ_MODE;

  uint8_t TOM_reserved1[4];
  union {                              /* TOM TGC0 Enable/Disable Control Register */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t ENDIS_CTRL7:2;         /* Channel 7 enable/disable update value. */
      vuint32_t ENDIS_CTRL6:2;         /* Channel 6 enable/disable update value. */
      vuint32_t ENDIS_CTRL5:2;         /* Channel 5 enable/disable update value. */
      vuint32_t ENDIS_CTRL4:2;         /* TOM channel 4 enable/disable update value. */
      vuint32_t ENDIS_CTRL3:2;         /* TOM channel 3 enable/disable update value. */
      vuint32_t ENDIS_CTRL2:2;         /* TOM channel 2 enable/disable update value. */
      vuint32_t ENDIS_CTRL1:2;         /* TOM channel 1 enable/disable update value. */
      vuint32_t ENDIS_CTRL0:2;         /* TOM channel 0 enable/disable update value. */
    } B;
  } TGC0_ENDIS_CTRL;

  union {                              /* TOM TGC0 Enable/Disable Status Register */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t ENDIS_STAT7:2;         /* TOM channel 7 enable/disable. */
      vuint32_t ENDIS_STAT6:2;         /* TOM channel 6 enable/disable. */
      vuint32_t ENDIS_STAT5:2;         /* TOM channel 5 enable/disable. */
      vuint32_t ENDIS_STAT4:2;         /* TOM channel 4 enable/disable. */
      vuint32_t ENDIS_STAT3:2;         /* TOM channel 3 enable/disable. */
      vuint32_t ENDIS_STAT2:2;         /* TOM channel 2 enable/disable. */
      vuint32_t ENDIS_STAT1:2;         /* TOM channel 1 enable/disable. */
      vuint32_t ENDIS_STAT0:2;         /* TOM channel 0 enable/disable. */
    } B;
  } TGC0_ENDIS_STAT;

  union {                              /* TOM TGC0 Out Enable Control Register */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t OUTEN_CTRL7:2;         /* Output TOM_OUT(7) enable/disable update value. */
      vuint32_t OUTEN_CTRL6:2;         /* Output TOM_OUT(6) enable/disable update value. */
      vuint32_t OUTEN_CTRL5:2;         /* Output TOM_OUT(5) enable/disable update value. */
      vuint32_t OUTEN_CTRL4:2;         /* Output TOM_OUT(4) enable/disable update value. */
      vuint32_t OUTEN_CTRL3:2;         /* Output TOM_OUT(3) enable/disable update value. */
      vuint32_t OUTEN_CTRL2:2;         /* Output TOM_OUT(2) enable/disable update value. */
      vuint32_t OUTEN_CTRL1:2;         /* Output TOM_OUT(1) enable/disable update value. */
      vuint32_t OUTEN_CTRL0:2;         /* Output TOM_OUT(0) enable/disable update value. */
    } B;
  } TGC0_OUTEN_CTRL;

  union {                              /* TOM TGC0 Out Enable Control/Status Register */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t OUTEN_STAT7:2;         /* Control/status of output TOM_OUT(7). */
      vuint32_t OUTEN_STAT6:2;         /* Control/status of output TOM_OUT(6). */
      vuint32_t OUTEN_STAT5:2;         /* Control/status of output TOM_OUT(5). */
      vuint32_t OUTEN_STAT4:2;         /* Control/status of output TOM_OUT(4) */
      vuint32_t OUTEN_STAT3:2;         /* Control/status of output TOM_OUT(3). */
      vuint32_t OUTEN_STAT2:2;         /* Control/status of output TOM_OUT(2). */
      vuint32_t OUTEN_STAT1:2;         /* Control/status of output TOM_OUT(1). */
      vuint32_t OUTEN_STAT0:2;         /* Control/status of output TOM_OUT(0). */
    } B;
  } TGC0_OUTEN_STAT;

  union {                              /* TOM Channel n Control Register, n[0:14] */
    vuint32_t R;
    struct {
      vuint32_t  :2;
      vuint32_t GCM:1;                 /* Gated Counter Mode enable. */
      vuint32_t SPEM:1;                /* SPE mode enable for channel. */
      vuint32_t  :1;
      vuint32_t OSM:1;                 /* One-shot mode.. */
      vuint32_t  :1;
      vuint32_t TRIGOUT:1;             /* Trigger output selection (output signal TRIG_[n]) of module TOM_CH[n]. */
      vuint32_t  :3;
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :5;
      vuint32_t CLK_SRC_SR:3;          /* Clock source select for channel. */
      vuint32_t SL:1;                  /* Signal level for duty cycle. */
      vuint32_t  :11;
    } B;
  } CH2_CTRL;

  union {                              /* TOM Channel n Shadow 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR0:16;                /* TOM channel n shadow register SR0 for update of compare register CM0. */
    } B;
  } CH2_SR0;

  union {                              /* TOM Channel n Shadow 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR1:16;                /* TOM channel n shadow register SR1 for update of compare register CM1. */
    } B;
  } CH2_SR1;

  union {                              /* TOM Channel n Compare 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM0:16;                /* TOM CCU0 compare register. */
    } B;
  } CH2_CM0;

  union {                              /* TOM Channel n Compare 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM1:16;                /* TOM CCU1 compare register. */
    } B;
  } CH2_CM1;

  union {                              /* TOM Channel n CN0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CN0:16;                /* TOM CCU0 counter register. */
    } B;
  } CH2_CN0;

  union {                              /* TOM Channel n Status Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :31;                  /* Reserved. */
      vuint32_t OL:1;                  /* Output level of output TOM_OUT(n). */
    } B;
  } CH2_STAT;

  union {                              /* TOM Channel n Interrupt Request Notification Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH2_IRQ_NOTIFY;

  union {                              /* TOM Channel n Interrupt Request Enable Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH2_IRQ_EN;

  union {                              /* TOM Channel n Force Interrupt Request Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t TRG_CCU1TC0:1;         /* Trigger TOM_CCU1TC0_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC0:1;         /* Trigger TOM_CCU0TC0_IRQ interrupt by software. */
    } B;
  } CH2_IRQ_FORCINT;

  union {                              /* TOM Channel n Interrupt Request Mode Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH2_IRQ_MODE;

  uint8_t TOM_reserved2[20];
  union {                              /* TOM Channel n Control Register, n[0:14] */
    vuint32_t R;
    struct {
      vuint32_t  :2;
      vuint32_t GCM:1;                 /* Gated Counter Mode enable. */
      vuint32_t SPEM:1;                /* SPE mode enable for channel. */
      vuint32_t  :1;
      vuint32_t OSM:1;                 /* One-shot mode.. */
      vuint32_t  :1;
      vuint32_t TRIGOUT:1;             /* Trigger output selection (output signal TRIG_[n]) of module TOM_CH[n]. */
      vuint32_t  :3;
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :5;
      vuint32_t CLK_SRC_SR:3;          /* Clock source select for channel. */
      vuint32_t SL:1;                  /* Signal level for duty cycle. */
      vuint32_t  :11;
    } B;
  } CH3_CTRL;

  union {                              /* TOM Channel n Shadow 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR0:16;                /* TOM channel n shadow register SR0 for update of compare register CM0. */
    } B;
  } CH3_SR0;

  union {                              /* TOM Channel n Shadow 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR1:16;                /* TOM channel n shadow register SR1 for update of compare register CM1. */
    } B;
  } CH3_SR1;

  union {                              /* TOM Channel n Compare 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM0:16;                /* TOM CCU0 compare register. */
    } B;
  } CH3_CM0;

  union {                              /* TOM Channel n Compare 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM1:16;                /* TOM CCU1 compare register. */
    } B;
  } CH3_CM1;

  union {                              /* TOM Channel n CN0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CN0:16;                /* TOM CCU0 counter register. */
    } B;
  } CH3_CN0;

  union {                              /* TOM Channel n Status Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :31;                  /* Reserved. */
      vuint32_t OL:1;                  /* Output level of output TOM_OUT(n). */
    } B;
  } CH3_STAT;

  union {                              /* TOM Channel n Interrupt Request Notification Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH3_IRQ_NOTIFY;

  union {                              /* TOM Channel n Interrupt Request Enable Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH3_IRQ_EN;

  union {                              /* TOM Channel n Force Interrupt Request Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t TRG_CCU1TC0:1;         /* Trigger TOM_CCU1TC0_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC0:1;         /* Trigger TOM_CCU0TC0_IRQ interrupt by software. */
    } B;
  } CH3_IRQ_FORCINT;

  union {                              /* TOM Channel n Interrupt Request Mode Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH3_IRQ_MODE;

  uint8_t TOM_reserved3[20];
  union {                              /* TOM Channel n Control Register, n[0:14] */
    vuint32_t R;
    struct {
      vuint32_t  :2;
      vuint32_t GCM:1;                 /* Gated Counter Mode enable. */
      vuint32_t SPEM:1;                /* SPE mode enable for channel. */
      vuint32_t  :1;
      vuint32_t OSM:1;                 /* One-shot mode.. */
      vuint32_t  :1;
      vuint32_t TRIGOUT:1;             /* Trigger output selection (output signal TRIG_[n]) of module TOM_CH[n]. */
      vuint32_t  :3;
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :5;
      vuint32_t CLK_SRC_SR:3;          /* Clock source select for channel. */
      vuint32_t SL:1;                  /* Signal level for duty cycle. */
      vuint32_t  :11;
    } B;
  } CH4_CTRL;

  union {                              /* TOM Channel n Shadow 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR0:16;                /* TOM channel n shadow register SR0 for update of compare register CM0. */
    } B;
  } CH4_SR0;

  union {                              /* TOM Channel n Shadow 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR1:16;                /* TOM channel n shadow register SR1 for update of compare register CM1. */
    } B;
  } CH4_SR1;

  union {                              /* TOM Channel n Compare 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM0:16;                /* TOM CCU0 compare register. */
    } B;
  } CH4_CM0;

  union {                              /* TOM Channel n Compare 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM1:16;                /* TOM CCU1 compare register. */
    } B;
  } CH4_CM1;

  union {                              /* TOM Channel n CN0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CN0:16;                /* TOM CCU0 counter register. */
    } B;
  } CH4_CN0;

  union {                              /* TOM Channel n Status Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :31;                  /* Reserved. */
      vuint32_t OL:1;                  /* Output level of output TOM_OUT(n). */
    } B;
  } CH4_STAT;

  union {                              /* TOM Channel n Interrupt Request Notification Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH4_IRQ_NOTIFY;

  union {                              /* TOM Channel n Interrupt Request Enable Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH4_IRQ_EN;

  union {                              /* TOM Channel n Force Interrupt Request Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t TRG_CCU1TC0:1;         /* Trigger TOM_CCU1TC0_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC0:1;         /* Trigger TOM_CCU0TC0_IRQ interrupt by software. */
    } B;
  } CH4_IRQ_FORCINT;

  union {                              /* TOM Channel n Interrupt Request Mode Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH4_IRQ_MODE;

  uint8_t TOM_reserved4[20];
  union {                              /* TOM Channel n Control Register, n[0:14] */
    vuint32_t R;
    struct {
      vuint32_t  :2;
      vuint32_t GCM:1;                 /* Gated Counter Mode enable. */
      vuint32_t SPEM:1;                /* SPE mode enable for channel. */
      vuint32_t  :1;
      vuint32_t OSM:1;                 /* One-shot mode.. */
      vuint32_t  :1;
      vuint32_t TRIGOUT:1;             /* Trigger output selection (output signal TRIG_[n]) of module TOM_CH[n]. */
      vuint32_t  :3;
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :5;
      vuint32_t CLK_SRC_SR:3;          /* Clock source select for channel. */
      vuint32_t SL:1;                  /* Signal level for duty cycle. */
      vuint32_t  :11;
    } B;
  } CH5_CTRL;

  union {                              /* TOM Channel n Shadow 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR0:16;                /* TOM channel n shadow register SR0 for update of compare register CM0. */
    } B;
  } CH5_SR0;

  union {                              /* TOM Channel n Shadow 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR1:16;                /* TOM channel n shadow register SR1 for update of compare register CM1. */
    } B;
  } CH5_SR1;

  union {                              /* TOM Channel n Compare 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM0:16;                /* TOM CCU0 compare register. */
    } B;
  } CH5_CM0;

  union {                              /* TOM Channel n Compare 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM1:16;                /* TOM CCU1 compare register. */
    } B;
  } CH5_CM1;

  union {                              /* TOM Channel n CN0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CN0:16;                /* TOM CCU0 counter register. */
    } B;
  } CH5_CN0;

  union {                              /* TOM Channel n Status Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :31;                  /* Reserved. */
      vuint32_t OL:1;                  /* Output level of output TOM_OUT(n). */
    } B;
  } CH5_STAT;

  union {                              /* TOM Channel n Interrupt Request Notification Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH5_IRQ_NOTIFY;

  union {                              /* TOM Channel n Interrupt Request Enable Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH5_IRQ_EN;

  union {                              /* TOM Channel n Force Interrupt Request Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t TRG_CCU1TC0:1;         /* Trigger TOM_CCU1TC0_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC0:1;         /* Trigger TOM_CCU0TC0_IRQ interrupt by software. */
    } B;
  } CH5_IRQ_FORCINT;

  union {                              /* TOM Channel n Interrupt Request Mode Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH5_IRQ_MODE;

  uint8_t TOM_reserved5[20];
  union {                              /* TOM Channel n Control Register, n[0:14] */
    vuint32_t R;
    struct {
      vuint32_t  :2;
      vuint32_t GCM:1;                 /* Gated Counter Mode enable. */
      vuint32_t SPEM:1;                /* SPE mode enable for channel. */
      vuint32_t  :1;
      vuint32_t OSM:1;                 /* One-shot mode.. */
      vuint32_t  :1;
      vuint32_t TRIGOUT:1;             /* Trigger output selection (output signal TRIG_[n]) of module TOM_CH[n]. */
      vuint32_t  :3;
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :5;
      vuint32_t CLK_SRC_SR:3;          /* Clock source select for channel. */
      vuint32_t SL:1;                  /* Signal level for duty cycle. */
      vuint32_t  :11;
    } B;
  } CH6_CTRL;

  union {                              /* TOM Channel n Shadow 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR0:16;                /* TOM channel n shadow register SR0 for update of compare register CM0. */
    } B;
  } CH6_SR0;

  union {                              /* TOM Channel n Shadow 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR1:16;                /* TOM channel n shadow register SR1 for update of compare register CM1. */
    } B;
  } CH6_SR1;

  union {                              /* TOM Channel n Compare 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM0:16;                /* TOM CCU0 compare register. */
    } B;
  } CH6_CM0;

  union {                              /* TOM Channel n Compare 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM1:16;                /* TOM CCU1 compare register. */
    } B;
  } CH6_CM1;

  union {                              /* TOM Channel n CN0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CN0:16;                /* TOM CCU0 counter register. */
    } B;
  } CH6_CN0;

  union {                              /* TOM Channel n Status Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :31;                  /* Reserved. */
      vuint32_t OL:1;                  /* Output level of output TOM_OUT(n). */
    } B;
  } CH6_STAT;

  union {                              /* TOM Channel n Interrupt Request Notification Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH6_IRQ_NOTIFY;

  union {                              /* TOM Channel n Interrupt Request Enable Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH6_IRQ_EN;

  union {                              /* TOM Channel n Force Interrupt Request Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t TRG_CCU1TC0:1;         /* Trigger TOM_CCU1TC0_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC0:1;         /* Trigger TOM_CCU0TC0_IRQ interrupt by software. */
    } B;
  } CH6_IRQ_FORCINT;

  union {                              /* TOM Channel n Interrupt Request Mode Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH6_IRQ_MODE;

  uint8_t TOM_reserved6[20];
  union {                              /* TOM Channel n Control Register, n[0:14] */
    vuint32_t R;
    struct {
      vuint32_t  :2;
      vuint32_t GCM:1;                 /* Gated Counter Mode enable. */
      vuint32_t SPEM:1;                /* SPE mode enable for channel. */
      vuint32_t  :1;
      vuint32_t OSM:1;                 /* One-shot mode.. */
      vuint32_t  :1;
      vuint32_t TRIGOUT:1;             /* Trigger output selection (output signal TRIG_[n]) of module TOM_CH[n]. */
      vuint32_t  :3;
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :5;
      vuint32_t CLK_SRC_SR:3;          /* Clock source select for channel. */
      vuint32_t SL:1;                  /* Signal level for duty cycle. */
      vuint32_t  :11;
    } B;
  } CH7_CTRL;

  union {                              /* TOM Channel n Shadow 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR0:16;                /* TOM channel n shadow register SR0 for update of compare register CM0. */
    } B;
  } CH7_SR0;

  union {                              /* TOM Channel n Shadow 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR1:16;                /* TOM channel n shadow register SR1 for update of compare register CM1. */
    } B;
  } CH7_SR1;

  union {                              /* TOM Channel n Compare 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM0:16;                /* TOM CCU0 compare register. */
    } B;
  } CH7_CM0;

  union {                              /* TOM Channel n Compare 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM1:16;                /* TOM CCU1 compare register. */
    } B;
  } CH7_CM1;

  union {                              /* TOM Channel n CN0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CN0:16;                /* TOM CCU0 counter register. */
    } B;
  } CH7_CN0;

  union {                              /* TOM Channel n Status Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :31;                  /* Reserved. */
      vuint32_t OL:1;                  /* Output level of output TOM_OUT(n). */
    } B;
  } CH7_STAT;

  union {                              /* TOM Channel n Interrupt Request Notification Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH7_IRQ_NOTIFY;

  union {                              /* TOM Channel n Interrupt Request Enable Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH7_IRQ_EN;

  union {                              /* TOM Channel n Force Interrupt Request Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t TRG_CCU1TC0:1;         /* Trigger TOM_CCU1TC0_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC0:1;         /* Trigger TOM_CCU0TC0_IRQ interrupt by software. */
    } B;
  } CH7_IRQ_FORCINT;

  union {                              /* TOM Channel n Interrupt Request Mode Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH7_IRQ_MODE;

  uint8_t TOM_reserved7[20];
  union {                              /* TOM Channel n Control Register, n[0:14] */
    vuint32_t R;
    struct {
      vuint32_t  :2;
      vuint32_t GCM:1;                 /* Gated Counter Mode enable. */
      vuint32_t SPEM:1;                /* SPE mode enable for channel. */
      vuint32_t  :1;
      vuint32_t OSM:1;                 /* One-shot mode.. */
      vuint32_t  :1;
      vuint32_t TRIGOUT:1;             /* Trigger output selection (output signal TRIG_[n]) of module TOM_CH[n]. */
      vuint32_t  :3;
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :5;
      vuint32_t CLK_SRC_SR:3;          /* Clock source select for channel. */
      vuint32_t SL:1;                  /* Signal level for duty cycle. */
      vuint32_t  :11;
    } B;
  } CH8_CTRL;

  union {                              /* TOM Channel n Shadow 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR0:16;                /* TOM channel n shadow register SR0 for update of compare register CM0. */
    } B;
  } CH8_SR0;

  union {                              /* TOM Channel n Shadow 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR1:16;                /* TOM channel n shadow register SR1 for update of compare register CM1. */
    } B;
  } CH8_SR1;

  union {                              /* TOM Channel n Compare 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM0:16;                /* TOM CCU0 compare register. */
    } B;
  } CH8_CM0;

  union {                              /* TOM Channel n Compare 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM1:16;                /* TOM CCU1 compare register. */
    } B;
  } CH8_CM1;

  union {                              /* TOM Channel n CN0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CN0:16;                /* TOM CCU0 counter register. */
    } B;
  } CH8_CN0;

  union {                              /* TOM Channel n Status Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :31;                  /* Reserved. */
      vuint32_t OL:1;                  /* Output level of output TOM_OUT(n). */
    } B;
  } CH8_STAT;

  union {                              /* TOM Channel n Interrupt Request Notification Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH8_IRQ_NOTIFY;

  union {                              /* TOM Channel n Interrupt Request Enable Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH8_IRQ_EN;

  union {                              /* TOM Channel n Force Interrupt Request Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t TRG_CCU1TC0:1;         /* Trigger TOM_CCU1TC0_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC0:1;         /* Trigger TOM_CCU0TC0_IRQ interrupt by software. */
    } B;
  } CH8_IRQ_FORCINT;

  union {                              /* TOM Channel n Interrupt Request Mode Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH8_IRQ_MODE;

  uint8_t TOM_reserved8[4];
  union {                              /* TOM TGC1 Global Control Register */
    vuint32_t R;
    struct {
      vuint32_t UPEN_CTRL15:2;         /* TOM channel 15 enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t UPEN_CTRL14:2;         /* TOM channel 14 enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t UPEN_CTRL13:2;         /* TOM channel 13 enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t UPEN_CTRL12:2;         /* TOM channel 12 enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t UPEN_CTRL11:2;         /* TOM channel 11 enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t UPEN_CTRL10:2;         /* TOM channel 10 enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t UPEN_CTRL9:2;          /* TOM channel 9 enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t UPEN_CTRL8:2;          /* TOM channel 8 enable update of register CM0, CM1 and CLK_SRC_STAT from SR0, SR1 and CLK_SRC. */
      vuint32_t RST_CH15:1;            /* Software reset of channel 15. */
      vuint32_t RST_CH14:1;            /* Software reset of channel 14. */
      vuint32_t RST_CH13:1;            /* Software reset of channel 13. */
      vuint32_t RST_CH12:1;            /* Software reset of channel 12. */
      vuint32_t RST_CH11:1;            /* Software reset of channel 11. */
      vuint32_t RST_CH10:1;            /* Software reset of channel 10. */
      vuint32_t RST_CH9:1;             /* Software reset of channel 9. */
      vuint32_t RST_CH8:1;             /* Software reset of channel 8. */
      vuint32_t  :7;
      vuint32_t HOST_TRIG:1;           /* Trigger request signal (see TGC0, TGC1) to update the register ENDIS_STAT and OUTEN_STAT. */
    } B;
  } TGC1_GLB_CTRL;

  union {                              /* TOM TGC1 Action Time Base Register */
    vuint32_t R;
    struct {
      vuint32_t  :5;
      vuint32_t TBU_SEL:2;             /* Selection of time base used for comparison. */
      vuint32_t TB_TRIG:1;             /* Set trigger request. */
      vuint32_t ACT_TB:24;             /* Specifies the signed compare value with selected signal TBU_TS[n], x=0..2. */
    } B;
  } TGC1_ACT_TB;

  union {                              /* TOM TGC1 Force Update Control Register */
    vuint32_t R;
    struct {
      vuint32_t RSTCN0_CH15:2;         /* Reset CN0 of channel 15 on force update event. */
      vuint32_t RSTCN0_CH14:2;         /* Reset CN0 of channel 14 on force update event. */
      vuint32_t RSTCN0_CH13:2;         /* Reset CN0 of channel 13 on force update event. */
      vuint32_t RSTCN0_CH12:2;         /* Reset CN0 of channel 12 on force update event. */
      vuint32_t RSTCN0_CH11:2;         /* Reset CN0 of channel 11 on force update event. */
      vuint32_t RSTCN0_CH10:2;         /* Reset CN0 of channel 10 on force update event. */
      vuint32_t RSTCN0_CH9:2;          /* Reset CN0 of channel 9 on force update event. */
      vuint32_t RSTCN0_CH8:2;          /* Reset CN0 of channel 8 on force update event. */
      vuint32_t FUPD_CTRL15:2;         /* Force update of TOM channel 15 operation registers. */
      vuint32_t FUPD_CTRL14:2;         /* Force update of TOM channel 14 operation registers, */
      vuint32_t FUPD_CTRL13:2;         /* Force update of TOM channel 13 operation registers. */
      vuint32_t FUPD_CTRL12:2;         /* Force update of TOM channel 12 operation registers. */
      vuint32_t FUPD_CTRL11:2;         /* Force update of TOM channel 11 operation registers. */
      vuint32_t FUPD_CTRL10:2;         /* ce update of TOM channel 10 operation registers. */
      vuint32_t FUPD_CTRL9:2;          /* Force update of TOM channel 9 operation registers. */
      vuint32_t FUPD_CTRL8:2;          /* Force update of TOM channel 8 operation registers. */
    } B;
  } TGC1_FUPD_CTRL;

  union {                              /* TOM TGC1 Interrupt Trigger Register */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t INT_TRIG15:2;          /* Select input signal TRIG_15 as a trigger source. */
      vuint32_t INT_TRIG14:2;          /* Select input signal TRIG_14 as a trigger source. */
      vuint32_t INT_TRIG13:2;          /* Select input signal TRIG_13as a trigger source. */
      vuint32_t INT_TRIG12:2;          /* Select input signal TRIG_12 as a trigger source. */
      vuint32_t INT_TRIG11:2;          /* Select input signal TRIG_1 as a trigger source. */
      vuint32_t INT_TRIG10:2;          /* Select input signal TRIG_10 as a trigger source. */
      vuint32_t INT_TRIG9:2;           /* Select input signal TRIG_9 as a trigger source. */
      vuint32_t INT_TRIG8:2;           /* Select input signal TRIG_8 as a trigger source. */
    } B;
  } TGC1_INT_TRIG;

  union {                              /* TOM Channel n Control Register, n[0:14] */
    vuint32_t R;
    struct {
      vuint32_t  :2;
      vuint32_t GCM:1;                 /* Gated Counter Mode enable. */
      vuint32_t SPEM:1;                /* SPE mode enable for channel. */
      vuint32_t  :1;
      vuint32_t OSM:1;                 /* One-shot mode.. */
      vuint32_t  :1;
      vuint32_t TRIGOUT:1;             /* Trigger output selection (output signal TRIG_[n]) of module TOM_CH[n]. */
      vuint32_t  :3;
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :5;
      vuint32_t CLK_SRC_SR:3;          /* Clock source select for channel. */
      vuint32_t SL:1;                  /* Signal level for duty cycle. */
      vuint32_t  :11;
    } B;
  } CH9_CTRL;

  union {                              /* TOM Channel n Shadow 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR0:16;                /* TOM channel n shadow register SR0 for update of compare register CM0. */
    } B;
  } CH9_SR0;

  union {                              /* TOM Channel n Shadow 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR1:16;                /* TOM channel n shadow register SR1 for update of compare register CM1. */
    } B;
  } CH9_SR1;

  union {                              /* TOM Channel n Compare 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM0:16;                /* TOM CCU0 compare register. */
    } B;
  } CH9_CM0;

  union {                              /* TOM Channel n Compare 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM1:16;                /* TOM CCU1 compare register. */
    } B;
  } CH9_CM1;

  union {                              /* TOM Channel n CN0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CN0:16;                /* TOM CCU0 counter register. */
    } B;
  } CH9_CN0;

  union {                              /* TOM Channel n Status Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :31;                  /* Reserved. */
      vuint32_t OL:1;                  /* Output level of output TOM_OUT(n). */
    } B;
  } CH9_STAT;

  union {                              /* TOM Channel n Interrupt Request Notification Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH9_IRQ_NOTIFY;

  union {                              /* TOM Channel n Interrupt Request Enable Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH9_IRQ_EN;

  union {                              /* TOM Channel n Force Interrupt Request Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t TRG_CCU1TC0:1;         /* Trigger TOM_CCU1TC0_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC0:1;         /* Trigger TOM_CCU0TC0_IRQ interrupt by software. */
    } B;
  } CH9_IRQ_FORCINT;

  union {                              /* TOM Channel n Interrupt Request Mode Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH9_IRQ_MODE;

  uint8_t TOM_reserved9[4];
  union {                              /* TOM TGC1 Enable/Disable Control Register */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t ENDIS_CTRL15:2;        /* Channel 15 enable/disable update value. */
      vuint32_t ENDIS_CTRL14:2;        /* Channel 14 enable/disable update value. */
      vuint32_t ENDIS_CTRL13:2;        /* Channel 13 enable/disable update value. */
      vuint32_t ENDIS_CTRL12:2;        /* TOM channel 12 enable/disable update value. */
      vuint32_t ENDIS_CTRL11:2;        /* TOM channel 11 enable/disable update value. */
      vuint32_t ENDIS_CTRL10:2;        /* TOM channel 10 enable/disable update value. */
      vuint32_t ENDIS_CTRL9:2;         /* TOM channel 9 enable/disable update value. */
      vuint32_t ENDIS_CTRL8:2;         /* TOM channel 8 enable/disable update value. */
    } B;
  } TGC1_ENDIS_CTRL;

  union {                              /* TOM TGC1 Enable/Disable Status Register */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t ENDIS_STAT15:2;        /* TOM channel 15 enable/disable. */
      vuint32_t ENDIS_STAT14:2;        /* TOM channel 14 enable/disable. */
      vuint32_t ENDIS_STAT13:2;        /* TOM channel 13 enable/disable. */
      vuint32_t ENDIS_STAT12:2;        /* TOM channel 12 enable/disable. */
      vuint32_t ENDIS_STAT11:2;        /* TOM channel 11 enable/disable. */
      vuint32_t ENDIS_STAT10:2;        /* TOM channel 10 enable/disable. */
      vuint32_t ENDIS_STAT9:2;         /* TOM channel 9 enable/disable. */
      vuint32_t ENDIS_STAT8:2;         /* TOM channel 8 enable/disable. */
    } B;
  } TGC1_ENDIS_STAT;

  union {                              /* TOM TGC1 Out Enable Control Register */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t OUTEN_CTRL15:2;        /* Output TOM_OUT(15) enable/disable update value. */
      vuint32_t OUTEN_CTRL14:2;        /* Output TOM_OUT(14) enable/disable update value. */
      vuint32_t OUTEN_CTRL13:2;        /* Output TOM_OUT(13) enable/disable update value. */
      vuint32_t OUTEN_CTRL12:2;        /* Output TOM_OUT(12) enable/disable update value. */
      vuint32_t OUTEN_CTRL11:2;        /* Output TOM_OUT(11) enable/disable update value. */
      vuint32_t OUTEN_CTRL10:2;        /* Output TOM_OUT(10) enable/disable update value. */
      vuint32_t OUTEN_CTRL9:2;         /* Output TOM_OUT(9) enable/disable update value. */
      vuint32_t OUTEN_CTRL8:2;         /* Output TOM_OUT(8) enable/disable update value. */
    } B;
  } TGC1_OUTEN_CTRL;

  union {                              /* TOM TGC1 Out Enable Control/Status Register */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t OUTEN_STAT15:2;        /* Control/status of output TOM_OUT(15). */
      vuint32_t OUTEN_STAT14:2;        /* Control/status of output TOM_OUT(14). */
      vuint32_t OUTEN_STAT13:2;        /* Control/status of output TOM_OUT(13). */
      vuint32_t OUTEN_STAT12:2;        /* Control/status of output TOM_OUT(12) */
      vuint32_t OUTEN_STAT11:2;        /* Control/status of output TOM_OUT(11). */
      vuint32_t OUTEN_STAT10:2;        /* Control/status of output TOM_OUT(10). */
      vuint32_t OUTEN_STAT9:2;         /* Control/status of output TOM_OUT(9). */
      vuint32_t OUTEN_STAT8:2;         /* Control/status of output TOM_OUT(8). */
    } B;
  } TGC1_OUTEN_STAT;

  union {                              /* TOM Channel n Control Register, n[0:14] */
    vuint32_t R;
    struct {
      vuint32_t  :2;
      vuint32_t GCM:1;                 /* Gated Counter Mode enable. */
      vuint32_t SPEM:1;                /* SPE mode enable for channel. */
      vuint32_t  :1;
      vuint32_t OSM:1;                 /* One-shot mode.. */
      vuint32_t  :1;
      vuint32_t TRIGOUT:1;             /* Trigger output selection (output signal TRIG_[n]) of module TOM_CH[n]. */
      vuint32_t  :3;
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :5;
      vuint32_t CLK_SRC_SR:3;          /* Clock source select for channel. */
      vuint32_t SL:1;                  /* Signal level for duty cycle. */
      vuint32_t  :11;
    } B;
  } CH10_CTRL;

  union {                              /* TOM Channel n Shadow 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR0:16;                /* TOM channel n shadow register SR0 for update of compare register CM0. */
    } B;
  } CH10_SR0;

  union {                              /* TOM Channel n Shadow 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR1:16;                /* TOM channel n shadow register SR1 for update of compare register CM1. */
    } B;
  } CH10_SR1;

  union {                              /* TOM Channel n Compare 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM0:16;                /* TOM CCU0 compare register. */
    } B;
  } CH10_CM0;

  union {                              /* TOM Channel n Compare 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM1:16;                /* TOM CCU1 compare register. */
    } B;
  } CH10_CM1;

  union {                              /* TOM Channel n CN0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CN0:16;                /* TOM CCU0 counter register. */
    } B;
  } CH10_CN0;

  union {                              /* TOM Channel n Status Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :31;                  /* Reserved. */
      vuint32_t OL:1;                  /* Output level of output TOM_OUT(n). */
    } B;
  } CH10_STAT;

  union {                              /* TOM Channel n Interrupt Request Notification Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH10_IRQ_NOTIFY;

  union {                              /* TOM Channel n Interrupt Request Enable Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH10_IRQ_EN;

  union {                              /* TOM Channel n Force Interrupt Request Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t TRG_CCU1TC0:1;         /* Trigger TOM_CCU1TC0_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC0:1;         /* Trigger TOM_CCU0TC0_IRQ interrupt by software. */
    } B;
  } CH10_IRQ_FORCINT;

  union {                              /* TOM Channel n Interrupt Request Mode Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH10_IRQ_MODE;

  uint8_t TOM_reserved10[20];
  union {                              /* TOM Channel n Control Register, n[0:14] */
    vuint32_t R;
    struct {
      vuint32_t  :2;
      vuint32_t GCM:1;                 /* Gated Counter Mode enable. */
      vuint32_t SPEM:1;                /* SPE mode enable for channel. */
      vuint32_t  :1;
      vuint32_t OSM:1;                 /* One-shot mode.. */
      vuint32_t  :1;
      vuint32_t TRIGOUT:1;             /* Trigger output selection (output signal TRIG_[n]) of module TOM_CH[n]. */
      vuint32_t  :3;
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :5;
      vuint32_t CLK_SRC_SR:3;          /* Clock source select for channel. */
      vuint32_t SL:1;                  /* Signal level for duty cycle. */
      vuint32_t  :11;
    } B;
  } CH11_CTRL;

  union {                              /* TOM Channel n Shadow 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR0:16;                /* TOM channel n shadow register SR0 for update of compare register CM0. */
    } B;
  } CH11_SR0;

  union {                              /* TOM Channel n Shadow 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR1:16;                /* TOM channel n shadow register SR1 for update of compare register CM1. */
    } B;
  } CH11_SR1;

  union {                              /* TOM Channel n Compare 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM0:16;                /* TOM CCU0 compare register. */
    } B;
  } CH11_CM0;

  union {                              /* TOM Channel n Compare 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM1:16;                /* TOM CCU1 compare register. */
    } B;
  } CH11_CM1;

  union {                              /* TOM Channel n CN0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CN0:16;                /* TOM CCU0 counter register. */
    } B;
  } CH11_CN0;

  union {                              /* TOM Channel n Status Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :31;                  /* Reserved. */
      vuint32_t OL:1;                  /* Output level of output TOM_OUT(n). */
    } B;
  } CH11_STAT;

  union {                              /* TOM Channel n Interrupt Request Notification Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH11_IRQ_NOTIFY;

  union {                              /* TOM Channel n Interrupt Request Enable Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH11_IRQ_EN;

  union {                              /* TOM Channel n Force Interrupt Request Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t TRG_CCU1TC0:1;         /* Trigger TOM_CCU1TC0_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC0:1;         /* Trigger TOM_CCU0TC0_IRQ interrupt by software. */
    } B;
  } CH11_IRQ_FORCINT;

  union {                              /* TOM Channel n Interrupt Request Mode Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH11_IRQ_MODE;

  uint8_t TOM_reserved11[20];
  union {                              /* TOM Channel n Control Register, n[0:14] */
    vuint32_t R;
    struct {
      vuint32_t  :2;
      vuint32_t GCM:1;                 /* Gated Counter Mode enable. */
      vuint32_t SPEM:1;                /* SPE mode enable for channel. */
      vuint32_t  :1;
      vuint32_t OSM:1;                 /* One-shot mode.. */
      vuint32_t  :1;
      vuint32_t TRIGOUT:1;             /* Trigger output selection (output signal TRIG_[n]) of module TOM_CH[n]. */
      vuint32_t  :3;
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :5;
      vuint32_t CLK_SRC_SR:3;          /* Clock source select for channel. */
      vuint32_t SL:1;                  /* Signal level for duty cycle. */
      vuint32_t  :11;
    } B;
  } CH12_CTRL;

  union {                              /* TOM Channel n Shadow 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR0:16;                /* TOM channel n shadow register SR0 for update of compare register CM0. */
    } B;
  } CH12_SR0;

  union {                              /* TOM Channel n Shadow 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR1:16;                /* TOM channel n shadow register SR1 for update of compare register CM1. */
    } B;
  } CH12_SR1;

  union {                              /* TOM Channel n Compare 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM0:16;                /* TOM CCU0 compare register. */
    } B;
  } CH12_CM0;

  union {                              /* TOM Channel n Compare 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM1:16;                /* TOM CCU1 compare register. */
    } B;
  } CH12_CM1;

  union {                              /* TOM Channel n CN0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CN0:16;                /* TOM CCU0 counter register. */
    } B;
  } CH12_CN0;

  union {                              /* TOM Channel n Status Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :31;                  /* Reserved. */
      vuint32_t OL:1;                  /* Output level of output TOM_OUT(n). */
    } B;
  } CH12_STAT;

  union {                              /* TOM Channel n Interrupt Request Notification Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH12_IRQ_NOTIFY;

  union {                              /* TOM Channel n Interrupt Request Enable Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH12_IRQ_EN;

  union {                              /* TOM Channel n Force Interrupt Request Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t TRG_CCU1TC0:1;         /* Trigger TOM_CCU1TC0_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC0:1;         /* Trigger TOM_CCU0TC0_IRQ interrupt by software. */
    } B;
  } CH12_IRQ_FORCINT;

  union {                              /* TOM Channel n Interrupt Request Mode Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH12_IRQ_MODE;

  uint8_t TOM_reserved12[20];
  union {                              /* TOM Channel n Control Register, n[0:14] */
    vuint32_t R;
    struct {
      vuint32_t  :2;
      vuint32_t GCM:1;                 /* Gated Counter Mode enable. */
      vuint32_t SPEM:1;                /* SPE mode enable for channel. */
      vuint32_t  :1;
      vuint32_t OSM:1;                 /* One-shot mode.. */
      vuint32_t  :1;
      vuint32_t TRIGOUT:1;             /* Trigger output selection (output signal TRIG_[n]) of module TOM_CH[n]. */
      vuint32_t  :3;
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :5;
      vuint32_t CLK_SRC_SR:3;          /* Clock source select for channel. */
      vuint32_t SL:1;                  /* Signal level for duty cycle. */
      vuint32_t  :11;
    } B;
  } CH13_CTRL;

  union {                              /* TOM Channel n Shadow 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR0:16;                /* TOM channel n shadow register SR0 for update of compare register CM0. */
    } B;
  } CH13_SR0;

  union {                              /* TOM Channel n Shadow 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR1:16;                /* TOM channel n shadow register SR1 for update of compare register CM1. */
    } B;
  } CH13_SR1;

  union {                              /* TOM Channel n Compare 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM0:16;                /* TOM CCU0 compare register. */
    } B;
  } CH13_CM0;

  union {                              /* TOM Channel n Compare 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM1:16;                /* TOM CCU1 compare register. */
    } B;
  } CH13_CM1;

  union {                              /* TOM Channel n CN0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CN0:16;                /* TOM CCU0 counter register. */
    } B;
  } CH13_CN0;

  union {                              /* TOM Channel n Status Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :31;                  /* Reserved. */
      vuint32_t OL:1;                  /* Output level of output TOM_OUT(n). */
    } B;
  } CH13_STAT;

  union {                              /* TOM Channel n Interrupt Request Notification Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH13_IRQ_NOTIFY;

  union {                              /* TOM Channel n Interrupt Request Enable Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH13_IRQ_EN;

  union {                              /* TOM Channel n Force Interrupt Request Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t TRG_CCU1TC0:1;         /* Trigger TOM_CCU1TC0_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC0:1;         /* Trigger TOM_CCU0TC0_IRQ interrupt by software. */
    } B;
  } CH13_IRQ_FORCINT;

  union {                              /* TOM Channel n Interrupt Request Mode Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH13_IRQ_MODE;

  uint8_t TOM_reserved13[20];
  union {                              /* TOM Channel n Control Register, n[0:14] */
    vuint32_t R;
    struct {
      vuint32_t  :2;
      vuint32_t GCM:1;                 /* Gated Counter Mode enable. */
      vuint32_t SPEM:1;                /* SPE mode enable for channel. */
      vuint32_t  :1;
      vuint32_t OSM:1;                 /* One-shot mode.. */
      vuint32_t  :1;
      vuint32_t TRIGOUT:1;             /* Trigger output selection (output signal TRIG_[n]) of module TOM_CH[n]. */
      vuint32_t  :3;
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :5;
      vuint32_t CLK_SRC_SR:3;          /* Clock source select for channel. */
      vuint32_t SL:1;                  /* Signal level for duty cycle. */
      vuint32_t  :11;
    } B;
  } CH14_CTRL;

  union {                              /* TOM Channel n Shadow 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR0:16;                /* TOM channel n shadow register SR0 for update of compare register CM0. */
    } B;
  } CH14_SR0;

  union {                              /* TOM Channel n Shadow 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR1:16;                /* TOM channel n shadow register SR1 for update of compare register CM1. */
    } B;
  } CH14_SR1;

  union {                              /* TOM Channel n Compare 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM0:16;                /* TOM CCU0 compare register. */
    } B;
  } CH14_CM0;

  union {                              /* TOM Channel n Compare 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM1:16;                /* TOM CCU1 compare register. */
    } B;
  } CH14_CM1;

  union {                              /* TOM Channel n CN0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CN0:16;                /* TOM CCU0 counter register. */
    } B;
  } CH14_CN0;

  union {                              /* TOM Channel n Status Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :31;                  /* Reserved. */
      vuint32_t OL:1;                  /* Output level of output TOM_OUT(n). */
    } B;
  } CH14_STAT;

  union {                              /* TOM Channel n Interrupt Request Notification Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH14_IRQ_NOTIFY;

  union {                              /* TOM Channel n Interrupt Request Enable Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH14_IRQ_EN;

  union {                              /* TOM Channel n Force Interrupt Request Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t TRG_CCU1TC0:1;         /* Trigger TOM_CCU1TC0_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC0:1;         /* Trigger TOM_CCU0TC0_IRQ interrupt by software. */
    } B;
  } CH14_IRQ_FORCINT;

  union {                              /* TOM Channel n Interrupt Request Mode Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH14_IRQ_MODE;

  uint8_t TOM_reserved14[20];
  union {                              /* TOM Channel 15 Control register */
    vuint32_t R;
    struct {
      vuint32_t  :4;
      vuint32_t BITREV:1;              /* Bit-reversing of output of counter register CN0.. */
      vuint32_t OSM:1;                 /* One-shot mode. */
      vuint32_t  :1;
      vuint32_t TRIGOUT:1;             /* Trigger output selection (output signal TRIG_15) of module TOM_CH15. */
      vuint32_t  :3;
      vuint32_t RST_CCU0:1;            /* Reset source of CCU0. */
      vuint32_t  :5;
      vuint32_t CLK_SRC_SR:3;          /* Clock source select for channel. */
      vuint32_t SL:1;                  /* Signal level for duty cycle. */
      vuint32_t  :11;
    } B;
  } CH15_CTRL;

  union {                              /* TOM Channel n Shadow 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR0:16;                /* TOM channel n shadow register SR0 for update of compare register CM0. */
    } B;
  } CH15_SR0;

  union {                              /* TOM Channel n Shadow 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t SR1:16;                /* TOM channel n shadow register SR1 for update of compare register CM1. */
    } B;
  } CH15_SR1;

  union {                              /* TOM Channel n Compare 0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM0:16;                /* TOM CCU0 compare register. */
    } B;
  } CH15_CM0;

  union {                              /* TOM Channel n Compare 1 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CM1:16;                /* TOM CCU1 compare register. */
    } B;
  } CH15_CM1;

  union {                              /* TOM Channel n CN0 Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :16;
      vuint32_t CN0:16;                /* TOM CCU0 counter register. */
    } B;
  } CH15_CN0;

  union {                              /* TOM Channel n Status Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :31;                  /* Reserved. */
      vuint32_t OL:1;                  /* Output level of output TOM_OUT(n). */
    } B;
  } CH15_STAT;

  union {                              /* TOM Channel n Interrupt Request Notification Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC:1;              /* CCU1 Trigger condition interrupt for channel n. */
      vuint32_t CCU0TC:1;              /* CCU0 Trigger condition interrupt for channel n. */
    } B;
  } CH15_IRQ_NOTIFY;

  union {                              /* TOM Channel n Interrupt Request Enable Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t CCU1TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
      vuint32_t CCU0TC_IRQ_EN:1;       /* TOM_CCU0TC_IRQ interrupt enable. */
    } B;
  } CH15_IRQ_EN;

  union {                              /* TOM Channel n Force Interrupt Request Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;                  /* Reserved. */
      vuint32_t TRG_CCU1TC0:1;         /* Trigger TOM_CCU1TC0_IRQ interrupt by software. */
      vuint32_t TRG_CCU0TC0:1;         /* Trigger TOM_CCU0TC0_IRQ interrupt by software. */
    } B;
  } CH15_IRQ_FORCINT;

  union {                              /* TOM Channel n Interrupt Request Mode Register, n[0:15] */
    vuint32_t R;
    struct {
      vuint32_t  :30;
      vuint32_t IRQ_MODE:2;            /* IRQ mode selection. */
    } B;
  } CH15_IRQ_MODE;
};

typedef volatile struct GTM_TOM_tag GTM_TOM_TagType;

#endif
