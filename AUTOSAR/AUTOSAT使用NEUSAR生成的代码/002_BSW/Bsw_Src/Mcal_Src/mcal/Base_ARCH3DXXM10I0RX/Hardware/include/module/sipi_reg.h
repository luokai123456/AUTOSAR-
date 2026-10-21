#ifndef SIPI_REG_H_
#define SIPI_REG_H_

/* ============================================================================
   =============================== Module: SIPI ===============================
   ============================================================================ */

typedef union SIPI_CCR0_union_tag {    /* SIPI Channel Control Register 0 */
  vuint32_t R;
  struct {
    vuint32_t  :15;
    vuint32_t TC:1;                    /* Send Trigger Command. */
    vuint32_t  :8;
    vuint32_t WL:2;                    /* Word Length Transfer. */
    vuint32_t CHEN:1;                  /* Channel Enable. */
    vuint32_t ST:1;                    /* Streaming Transfer. */
    vuint32_t IDT:1;                   /* ID Read Request Transfer. */
    vuint32_t RRT:1;                   /* Read Request Transfer. */
    vuint32_t WRT:1;                   /* Write Request Transfer. */
    vuint32_t DEN:1;                   /* DMA Enable. */
  } B;
} SIPI_CCR0_tag;

typedef union SIPI_CSR0_union_tag {    /* SIPI Channel Status Register 0 */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t RAR:1;
    vuint32_t TID:3;                   /* Transaction ID of transmitted frame. */
    vuint32_t ACKR:1;
    vuint32_t CB:1;                    /* Channel Busy. */
    vuint32_t  :2;
  } B;
} SIPI_CSR0_tag;

typedef union SIPI_CIR0_union_tag {    /* SIPI Channel Interrupt Register 0 */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t WAIE:1;                  /* Write Acknowledge Interrupt Enable. */
    vuint32_t RAIE:1;                  /* Read Answer Interrupt Enable. */
    vuint32_t TCIE:1;                  /* Trigger Command Interrupt Enable. */
    vuint32_t TOIE:1;                  /* Timeout Error Interrupt Enabled. */
    vuint32_t TIDIE:1;                 /* Transaction ID Error Interrupt Enable. */
    vuint32_t ACKIE:1;                 /* Acknowledge Error Interrupt Enable. */
  } B;
} SIPI_CIR0_tag;

typedef union SIPI_CTOR0_union_tag {   /* SIPI Channel Timeout Register 0 */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t TOR:8;                   /* Timeout value for transmitted requests. */
  } B;
} SIPI_CTOR0_tag;

typedef union SIPI_CCRC0_union_tag {   /* SIPI Channel CRC Register 0 */
  vuint32_t R;
  struct {
    vuint32_t CRCI:16;
    vuint32_t CRCT:16;
  } B;
} SIPI_CCRC0_tag;

typedef union SIPI_CAR0_union_tag {    /* SIPI Channel Address Register 0 */
  vuint32_t R;
  struct {
    vuint32_t CAR:32;
  } B;
} SIPI_CAR0_tag;

typedef union SIPI_CDR0_union_tag {    /* SIPI Channel Data Register 0 */
  vuint32_t R;
  struct {
    vuint32_t CDR:32;
  } B;
} SIPI_CDR0_tag;

typedef union SIPI_CCR1_union_tag {    /* SIPI Channel Control Register 1 */
  vuint32_t R;
  struct {
    vuint32_t  :15;
    vuint32_t TC:1;                    /* Send Trigger Command. */
    vuint32_t  :8;
    vuint32_t WL:2;                    /* Word Length Transfer. */
    vuint32_t CHEN:1;                  /* Channel Enable. */
    vuint32_t ST:1;
    vuint32_t IDT:1;                   /* ID Read Request Transfer. */
    vuint32_t RRT:1;
    vuint32_t WRT:1;                   /* Write Request Transfer. */
    vuint32_t DEN:1;                   /* DMA Enable. */
  } B;
} SIPI_CCR1_tag;

typedef union SIPI_CSR1_union_tag {    /* SIPI Channel Status Register 1 */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t RAR:1;
    vuint32_t TID:3;
    vuint32_t ACKR:1;
    vuint32_t CB:1;                    /* Channel Busy. */
    vuint32_t  :2;
  } B;
} SIPI_CSR1_tag;

typedef union SIPI_CIR1_union_tag {    /* SIPI Channel Interrupt Register 1 */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t WAIE:1;
    vuint32_t RAIE:1;
    vuint32_t TCIE:1;
    vuint32_t TOIE:1;
    vuint32_t TIDIE:1;
    vuint32_t ACKIE:1;
  } B;
} SIPI_CIR1_tag;

typedef union SIPI_CTOR1_union_tag {   /* SIPI Channel Timeout Register 1 */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t TOR:8;                   /* Timeout value for transmitted requests. */
  } B;
} SIPI_CTOR1_tag;

typedef union SIPI_CCRC1_union_tag {   /* SIPI Channel CRC Register 1 */
  vuint32_t R;
  struct {
    vuint32_t CRCI:16;
    vuint32_t CRCT:16;
  } B;
} SIPI_CCRC1_tag;

typedef union SIPI_CAR1_union_tag {    /* SIPI Channel Address Register 1 */
  vuint32_t R;
  struct {
    vuint32_t CAR:32;
  } B;
} SIPI_CAR1_tag;

typedef union SIPI_CDR1_union_tag {    /* SIPI Channel Data Register 1 */
  vuint32_t R;
  struct {
    vuint32_t CDR:32;
  } B;
} SIPI_CDR1_tag;

typedef union SIPI_CCR2_union_tag {    /* SIPI Channel Control Register 2 */
  vuint32_t R;
  struct {
    vuint32_t  :15;
    vuint32_t TC:1;                    /* Send Trigger Command. */
    vuint32_t  :8;
    vuint32_t WL:2;                    /* Word Length Transfer. */
    vuint32_t CHEN:1;                  /* Channel Enable. */
    vuint32_t ST:1;
    vuint32_t IDT:1;                   /* ID Read Request Transfer. */
    vuint32_t RRT:1;                   /* Read Request Transfer. */
    vuint32_t WRT:1;                   /* Write Request Transfer. */
    vuint32_t DEN:1;                   /* DMA Enable. */
  } B;
} SIPI_CCR2_tag;

typedef union SIPI_CSR2_union_tag {    /* SIPI Channel Status Register 2 */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t RAR:1;
    vuint32_t TID:3;                   /* Transaction ID of transmitted frame. */
    vuint32_t ACKR:1;
    vuint32_t CB:1;                    /* Channel Busy. */
    vuint32_t  :2;
  } B;
} SIPI_CSR2_tag;

typedef union SIPI_CIR2_union_tag {    /* SIPI Channel Interrupt Register 2 */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t WAIE:1;
    vuint32_t RAIE:1;
    vuint32_t TCIE:1;
    vuint32_t TOIE:1;
    vuint32_t TIDIE:1;
    vuint32_t ACKIE:1;
  } B;
} SIPI_CIR2_tag;

typedef union SIPI_CTOR2_union_tag {   /* SIPI Channel Timeout Register 2 */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t TOR:8;
  } B;
} SIPI_CTOR2_tag;

typedef union SIPI_CCRC2_union_tag {   /* SIPI Channel CRC Register 2 */
  vuint32_t R;
  struct {
    vuint32_t CRCI:16;
    vuint32_t CRCT:16;
  } B;
} SIPI_CCRC2_tag;

typedef union SIPI_CAR2_union_tag {    /* SIPI Channel Address Register 2 */
  vuint32_t R;
  struct {
    vuint32_t CAR:32;
  } B;
} SIPI_CAR2_tag;

typedef union SIPI_CDR2_union_tag {    /* SIPI Channel Data Register 2 */
  vuint32_t R;
  struct {
    vuint32_t CDR2:32;
  } B;
} SIPI_CDR2_tag;

typedef union SIPI_CCR3_union_tag {    /* SIPI Channel Control Register 3 */
  vuint32_t R;
  struct {
    vuint32_t  :15;
    vuint32_t TC:1;                    /* Send Trigger Command. */
    vuint32_t  :8;
    vuint32_t WL:2;                    /* Word Length Transfer. */
    vuint32_t CHEN:1;                  /* Channel Enable. */
    vuint32_t ST:1;                    /* Streaming Transfer. */
    vuint32_t IDT:1;                   /* ID Read Request Transfer. */
    vuint32_t RRT:1;                   /* Read Request Transfer. */
    vuint32_t WRT:1;                   /* Write Request Transfer. */
    vuint32_t DEN:1;                   /* DMA Enable. */
  } B;
} SIPI_CCR3_tag;

typedef union SIPI_CSR3_union_tag {    /* SIPI Channel Status Register 3 */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t RAR:1;
    vuint32_t TID:3;                   /* Transaction ID of transmitted frame. */
    vuint32_t ACKR:1;
    vuint32_t CB:1;                    /* Channel Busy. */
    vuint32_t  :2;
  } B;
} SIPI_CSR3_tag;

typedef union SIPI_CIR3_union_tag {    /* SIPI Channel Interrupt Register 3 */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t WAIE:1;
    vuint32_t RAIE:1;
    vuint32_t TCIE:1;
    vuint32_t TOIE:1;
    vuint32_t TIDIE:1;
    vuint32_t ACKIE:1;
  } B;
} SIPI_CIR3_tag;

typedef union SIPI_CTOR3_union_tag {   /* SIPI Channel Timeout Register 3 */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t TOR:8;                   /* Timeout value for transmitted requests. */
  } B;
} SIPI_CTOR3_tag;

typedef union SIPI_CCRC3_union_tag {   /* SIPI Channel CRC Register 3 */
  vuint32_t R;
  struct {
    vuint32_t CRCI:16;
    vuint32_t CRCT:16;
  } B;
} SIPI_CCRC3_tag;

typedef union SIPI_CAR3_union_tag {    /* SIPI Channel Address Register 3 */
  vuint32_t R;
  struct {
    vuint32_t CAR:32;
  } B;
} SIPI_CAR3_tag;

typedef union SIPI_CDR3_union_tag {    /* SIPI Channel Data Register 3 */
  vuint32_t R;
  struct {
    vuint32_t CDR:32;
  } B;
} SIPI_CDR3_tag;

typedef union SIPI_MCR_union_tag {     /* SIPI Module Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t FRZ:1;                   /* Freeze Enable */
    vuint32_t  :1;
    vuint32_t HALT:1;                  /* Halt Mode Enable */
    vuint32_t  :2;
    vuint32_t PRSCLR:11;               /* Timeout counter prescaler */
    vuint32_t AID:2;                   /* Address Increment/Decrement */
    vuint32_t  :3;
    vuint32_t CRCIE:1;                 /* CRC Error Interrupt Enable */
    vuint32_t MCRIE:1;                 /* Max Count Reached Interrupt Enable */
    vuint32_t  :4;
    vuint32_t CHNSB:1;                 /* Channel coding select bit. */
    vuint32_t TEN:1;                   /* Target Enable */
    vuint32_t INIT:1;                  /* Initialization Mode */
    vuint32_t MOEN:1;                  /* Module Enable */
    vuint32_t SR:1;                    /* Soft Reset */
  } B;
} SIPI_MCR_tag;

typedef union SIPI_SR_union_tag {      /* SIPI Status Register */
  vuint32_t R;
  struct {
    vuint32_t FRZACK:1;
    vuint32_t LPMACK:1;                /* Low Power Mode Acknowledge. */
    vuint32_t  :19;
    vuint32_t GCRCE:1;
    vuint32_t MCR:1;                   /* Maximum Count Reached. */
    vuint32_t  :1;
    vuint32_t TE:4;
    vuint32_t STATE:4;
  } B;
} SIPI_SR_tag;

typedef union SIPI_MAXCR_union_tag {   /* SIPI Max Count Register */
  vuint32_t R;
  struct {
    vuint32_t MXCNT:30;
    vuint32_t  :2;
  } B;
} SIPI_MAXCR_tag;

typedef union SIPI_ARR_union_tag {     /* SIPI Address Reload Register */
  vuint32_t R;
  struct {
    vuint32_t ADRLD:30;
    vuint32_t  :2;
  } B;
} SIPI_ARR_tag;

typedef union SIPI_ACR_union_tag {     /* SIPI Address Count Register */
  vuint32_t R;
  struct {
    vuint32_t ADCNT:30;                /* Feflects the count value of address counter at target node. */
    vuint32_t  :2;
  } B;
} SIPI_ACR_tag;

typedef union SIPI_ERR_union_tag {     /* SIPI Error Register */
  vuint32_t R;
  struct {
    vuint32_t  :5;
    vuint32_t TOE3:1;
    vuint32_t TIDE3:1;
    vuint32_t ACKE3:1;
    vuint32_t  :5;
    vuint32_t TOE2:1;
    vuint32_t TIDE2:1;
    vuint32_t ACKE2:1;
    vuint32_t  :5;
    vuint32_t TOE1:1;
    vuint32_t TIDE1:1;
    vuint32_t ACKE1:1;
    vuint32_t  :5;
    vuint32_t TOE0:1;
    vuint32_t TIDE0:1;
    vuint32_t ACKE0:1;
  } B;
} SIPI_ERR_tag;

struct SIPI_tag {
  SIPI_CCR0_tag CCR0;                  /* SIPI Channel Control Register 0 */
  SIPI_CSR0_tag CSR0;                  /* SIPI Channel Status Register 0 */
  uint8_t SIPI_reserved0[4];
  SIPI_CIR0_tag CIR0;                  /* SIPI Channel Interrupt Register 0 */
  SIPI_CTOR0_tag CTOR0;                /* SIPI Channel Timeout Register 0 */
  SIPI_CCRC0_tag CCRC0;                /* SIPI Channel CRC Register 0 */
  SIPI_CAR0_tag CAR0;                  /* SIPI Channel Address Register 0 */
  SIPI_CDR0_tag CDR0;                  /* SIPI Channel Data Register 0 */
  SIPI_CCR1_tag CCR1;                  /* SIPI Channel Control Register 1 */
  SIPI_CSR1_tag CSR1;                  /* SIPI Channel Status Register 1 */
  uint8_t SIPI_reserved1[4];
  SIPI_CIR1_tag CIR1;                  /* SIPI Channel Interrupt Register 1 */
  SIPI_CTOR1_tag CTOR1;                /* SIPI Channel Timeout Register 1 */
  SIPI_CCRC1_tag CCRC1;                /* SIPI Channel CRC Register 1 */
  SIPI_CAR1_tag CAR1;                  /* SIPI Channel Address Register 1 */
  SIPI_CDR1_tag CDR1;                  /* SIPI Channel Data Register 1 */
  SIPI_CCR2_tag CCR2;                  /* SIPI Channel Control Register 2 */
  SIPI_CSR2_tag CSR2;                  /* SIPI Channel Status Register 2 */
  uint8_t SIPI_reserved2[4];
  SIPI_CIR2_tag CIR2;                  /* SIPI Channel Interrupt Register 2 */
  SIPI_CTOR2_tag CTOR2;                /* SIPI Channel Timeout Register 2 */
  SIPI_CCRC2_tag CCRC2;                /* SIPI Channel CRC Register 2 */
  SIPI_CAR2_tag CAR2;                  /* SIPI Channel Address Register 2 */
  SIPI_CDR2_tag CDR2[8];               /* SIPI Channel Data Register 2 */
  SIPI_CCR3_tag CCR3;                  /* SIPI Channel Control Register 3 */
  SIPI_CSR3_tag CSR3;                  /* SIPI Channel Status Register 3 */
  uint8_t SIPI_reserved3[4];
  SIPI_CIR3_tag CIR3;                  /* SIPI Channel Interrupt Register 3 */
  SIPI_CTOR3_tag CTOR3;                /* SIPI Channel Timeout Register 3 */
  SIPI_CCRC3_tag CCRC3;                /* SIPI Channel CRC Register 3 */
  SIPI_CAR3_tag CAR3;                  /* SIPI Channel Address Register 3 */
  SIPI_CDR3_tag CDR3;                  /* SIPI Channel Data Register 3 */
  SIPI_MCR_tag MCR;                    /* SIPI Module Configuration Register */
  SIPI_SR_tag SR;                      /* SIPI Status Register */
  SIPI_MAXCR_tag MAXCR;                /* SIPI Max Count Register */
  SIPI_ARR_tag ARR;                    /* SIPI Address Reload Register */
  SIPI_ACR_tag ACR;                    /* SIPI Address Count Register */
  SIPI_ERR_tag ERR;                    /* SIPI Error Register */
};

#endif
