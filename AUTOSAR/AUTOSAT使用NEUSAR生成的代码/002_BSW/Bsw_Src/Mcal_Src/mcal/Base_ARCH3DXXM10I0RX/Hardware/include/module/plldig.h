#ifndef PLLDIG_REG_H_
#define PLLDIG_REG_H_

/* ============================================================================
   =============================== Module: PLLDIG =============================
   ============================================================================ */

typedef union PLLDIG_PLL0CR_union_tag { /* PLLDIG PLL0 Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :21;
    vuint32_t  :1;
    vuint32_t CLKCFG:2;                /* Clock Configuration */
    vuint32_t EXPDIE:1;                /* External Power Down Cycle Complete indication interrupt enable. */
    vuint32_t  :1;
    vuint32_t  :1;
    vuint32_t  :1;
    vuint32_t LOLIE:1;                 /* Loss-of-lock interrupt enable. */
    vuint32_t  :1;
    vuint32_t  :1;
    vuint32_t  :1;
  } B;
} PLLDIG_PLL0CR_tag;

typedef union PLLDIG_PLL0SR_union_tag { /* PLLDIG PLL0 Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t EXTPDF:1;
    vuint32_t  :1;
    vuint32_t  :1;
    vuint32_t  :1;
    vuint32_t LOLF:1;                  /* Loss-of-lock flag. */
    vuint32_t LOCK:1;
    vuint32_t  :1;
    vuint32_t  :1;
  } B;
} PLLDIG_PLL0SR_tag;

typedef union PLLDIG_PLL0DV_union_tag { /* PLLDIG PLL0 Divider Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t RFDPHI1:4;               /* PHI1 reduced frequency divider. */
    vuint32_t  :5;
    vuint32_t RFDPHI:6;                /* PHI reduced frequency divider. */
    vuint32_t  :1;
    vuint32_t PREDIV:3;                /* Input clock predivider. */
    vuint32_t  :5;
    vuint32_t MFD:7;                   /* Loop multiplication factor divider. */
  } B;
} PLLDIG_PLL0DV_tag;

typedef union PLLDIG_PLL1CR_union_tag { /* PLLDIG PLL1 Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :21;
    vuint32_t  :1;
    vuint32_t CLKCFG:2;                /* Clock Configuration */
    vuint32_t EXPDIE:1;                /* External Power Down Cycle Complete indication interrupt enable. */
    vuint32_t  :1;
    vuint32_t  :1;
    vuint32_t  :1;
    vuint32_t LOLIE:1;                 /* Loss-of-lock interrupt enable. */
    vuint32_t  :1;
    vuint32_t  :1;
    vuint32_t  :1;
  } B;
} PLLDIG_PLL1CR_tag;

typedef union PLLDIG_PLL1SR_union_tag { /* PLLDIG PLL1 Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t  :1;
    vuint32_t  :1;
    vuint32_t EXTPDF:1;
    vuint32_t  :1;
    vuint32_t  :1;
    vuint32_t  :1;
    vuint32_t LOLF:1;                  /* Loss-of-lock flag. */
    vuint32_t LOCK:1;
    vuint32_t  :1;
    vuint32_t  :1;
  } B;
} PLLDIG_PLL1SR_tag;

typedef union PLLDIG_PLL1DV_union_tag { /* PLLDIG PLL1 Divider Register */
  vuint32_t R;
  struct {
    vuint32_t  :10;
    vuint32_t RFDPHI:6;                /* PHI reduced frequency divider. */
    vuint32_t  :5;
    vuint32_t  :4;
    vuint32_t MFD:7;                   /* Loop multiplication factor divider. */
  } B;
} PLLDIG_PLL1DV_tag;

typedef union PLLDIG_PLL1FM_union_tag { /* PLLDIG PLL1 Frequency Modulation Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t MODEN:1;                 /* Modulation enable. */
    vuint32_t MODSEL:1;                /* Modulation selection. */
    vuint32_t MODPRD:13;               /* Modulation period. */
    vuint32_t  :1;
    vuint32_t INCSTP:15;               /* Increment step. */
  } B;
} PLLDIG_PLL1FM_tag;

typedef union PLLDIG_PLL1FD_union_tag { /* PLLDIG PLL1 Fractional Divide Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t FDEN:1;                  /* Fractional Divide Enable */
    vuint32_t  :12;
    vuint32_t DTHDIS:2;                /* Dither Disable. */
    vuint32_t  :4;
    vuint32_t FRCDIV:12;
  } B;
} PLLDIG_PLL1FD_tag;

struct PLLDIG_tag {
  PLLDIG_PLL0CR_tag PLL0CR;            /* PLLDIG PLL0 Control Register */
  PLLDIG_PLL0SR_tag PLL0SR;            /* PLLDIG PLL0 Status Register */
  PLLDIG_PLL0DV_tag PLL0DV;            /* PLLDIG PLL0 Divider Register */
  //  uint8_t PLLDIG_reserved0[20];
  vuint32_t PLL_CFG1;  //ccore
  vuint32_t PLL_CFG2;
  vuint32_t PLL_CFG3;
  vuint32_t PLL_CFG4;
  vuint32_t PLL_CFG5;
  PLLDIG_PLL1CR_tag PLL1CR;            /* PLLDIG PLL1 Control Register */
  PLLDIG_PLL1SR_tag PLL1SR;            /* PLLDIG PLL1 Status Register */
  PLLDIG_PLL1DV_tag PLL1DV;            /* PLLDIG PLL1 Divider Register */
  PLLDIG_PLL1FM_tag PLL1FM;            /* PLLDIG PLL1 Frequency Modulation Register */
  PLLDIG_PLL1FD_tag PLL1FD;            /* PLLDIG PLL1 Fractional Divide Register */
};

#define PLLDIG_PLL1FM_INCSTP_MASK         0x7FFFUL
#define PLLDIG_PLL1FM_MODPRD_MASK         0x1FFF0000UL
#define PLLDIG_PLL1FM_MODSEL_MSAK         0x20000000UL
#define PLLDIG_PLL1FM_MODEN_MASK          0x40000000UL

/* PLLDIG - Peripheral instance pMcu_Base addresses */
/** Peripheral PLLDIG pMcu_Base address */
#define PLLDIG_BASE                              (0xFFFB0100UL)
/** Peripheral PLLDIG pMcu_Base pointer */
#define PLLDIG_StPtr                             ((PLLDIG_Type *)PLLDIG_BASE)
/** Array initializer of PLLDIG peripheral pMcu_Base addresses */
#define PLLDIG_BASE_ADDRS                        { PLLDIG_BASE }
/** Array initializer of PLLDIG peripheral pMcu_Base pointers */
#define PLLDIG_BASE_PTRS                         { PLLDIG_StPtr }



/* PLL0CR Bit Fields */
#define PLLDIG_PLL0CR_CLKCFG_MASK                0x300u
#define PLLDIG_PLL0CR_CLKCFG_SHIFT               8u
#define PLLDIG_PLL0CR_CLKCFG_WIDTH               2u
#define PLLDIG_PLL0CR_CLKCFG(x)                  (((uint32)(((uint32)(x)) \
                                                  <<PLLDIG_PLL0CR_CLKCFG_SHIFT)) \
                                                  &PLLDIG_PLL0CR_CLKCFG_MASK)

/* PLL1CR Bit Fields */
#define PLLDIG_PLL1CR_CLKCFG_MASK                0x300u
#define PLLDIG_PLL1CR_CLKCFG_SHIFT               8u
#define PLLDIG_PLL1CR_CLKCFG_WIDTH               2u
#define PLLDIG_PLL1CR_CLKCFG(x)                  (((uint32)(((uint32)(x)) \
                                                  <<PLLDIG_PLL1CR_CLKCFG_SHIFT)) \
                                                  &PLLDIG_PLL1CR_CLKCFG_MASK)

#endif  /* PLLDIG_REG_H_ */
