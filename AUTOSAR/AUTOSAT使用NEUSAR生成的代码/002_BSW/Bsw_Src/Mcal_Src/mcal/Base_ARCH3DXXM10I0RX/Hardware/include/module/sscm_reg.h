#ifndef SSCM_REG_H_
#define SSCM_REG_H_

/* ============================================================================
   =============================== Module: SSCM ===============================
   ============================================================================ */

typedef union SSCM_STATUS_union_tag {  /* SSCM System Status */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t CER:1;                   /* Configuration Error */
    vuint16_t  :1;
    vuint16_t NXEN1:1;                 /* Processor 1 Nexus enable status */
    vuint16_t NXEN:1;                  /* Processor 0 Nexus enable status */
    vuint16_t  :1;
    vuint16_t  :1;
    vuint16_t  :1;
    vuint16_t BMODE:3;                 /* Device Boot Mode */
    vuint16_t VLE:1;                   /* Variable Length Instruction Mode */
    vuint16_t  :1;
    vuint16_t  :1;
    vuint16_t  :2;
  } B;
} SSCM_STATUS_tag;

typedef union SSCM_MEMCONFIG_union_tag { /* SSCM System Memory and ID Register */
  vuint16_t R;
  struct {
    vuint16_t JPIN:10;
    vuint16_t  :1;
    vuint16_t MREV:4;                  /* Minor Mask Revision */
    vuint16_t  :1;
  } B;
} SSCM_MEMCONFIG_tag;

typedef union SSCM_ERROR_union_tag {   /* SSCM Error Configuration Register */
  vuint16_t R;
  struct {
    vuint16_t  :14;
    vuint16_t PAE:1;                   /* Peripheral Bus Abort Enable. */
    vuint16_t RAE:1;                   /* Register Bus Abort Enable. */
  } B;
} SSCM_ERROR_tag;

typedef union SSCM_PWCMPH_union_tag {  /* Password comparison register low word */
  vuint32_t R;
  struct {
    vuint32_t PWD_HI:32;
  } B;
} SSCM_PWCMPH_tag;

typedef union SSCM_PWCMPL_union_tag {  /* Password comparison register low word */
  vuint32_t R;
  struct {
    vuint32_t PWD_LO:32;
  } B;
} SSCM_PWCMPL_tag;

typedef union SSCM_UOPS_union_tag {    /* SSCM HSM and User Option Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :28;
    vuint32_t HSB:3;                   /* HSM Boot Configuration */
    vuint32_t HSE:1;                   /* HSM Enabled */
  } B;
} SSCM_UOPS_tag;

typedef union SSCM_PSA_union_tag {     /* Processor Start Address Register */
  vuint32_t R;
  struct {
    vuint32_t SADR:32;                 /* Processor Start Address */
  } B;
} SSCM_PSA_tag;

typedef union SSCM_HSA_union_tag {     /* SSCM HSM Start Address Register */
  vuint32_t R;
  struct {
    vuint32_t HADR:32;                 /* HSM Start Address */
  } B;
} SSCM_HSA_tag;

typedef union SSCM_LCSTAT_union_tag {  /* Life Cycle Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t  :2;
    vuint32_t  :5;
    vuint32_t LC:3;                    /* Life Cycle */
  } B;
} SSCM_LCSTAT_tag;

#if defined(CCFC3007PT) || defined(CCFC3008PT)
typedef union SSCM_CHIP_CR_union_tag {  /* Chip Internal Configuration Register (Reset value: 0x2000_0003) */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t GMAC0_PHY_SEL:3;
    vuint32_t  :16;
    vuint32_t EN_VD33:1;    /* Increase the driving intensity of Medium IO to enable it */
    vuint32_t PRW_ISOLATE_GMAC0:1;
    vuint32_t PRW_CLAMP_GMAC0:1;
    vuint32_t PRW_DOWN_GMAC0:1;
    vuint32_t  :4;
    vuint32_t EN_TS:1;      /* Internal temperature sensor operation enable */
    vuint32_t EN_VREF:1;    /* Enable the reference power supply output of the internal ADC */
    vuint32_t EQADC_DMA_DONE_CFG:1;
    vuint32_t SDADC_DMA_DONE_CFG:1;
  } B;
} SSCM_CHIP_CR_tag;

/* ---------------- SSCM_CHIP_CR_tag bitfield definitions ---------------- */
#define SSCM_CHIP_CR_GMAC0_PHY_SEL_MASK                 0x70000000u
#define SSCM_CHIP_CR_GMAC0_PHY_SEL_SHIFT                28u
#define SSCM_CHIP_CR_GMAC0_PHY_SEL_WIDTH                3u
#define SSCM_CHIP_CR_GMAC0_PHY_SEL(x)                   ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_GMAC0_PHY_SEL_SHIFT))&SSCM_CHIP_CR_GMAC0_PHY_SEL_MASK))

#define SSCM_CHIP_CR_EN_VD33_MASK                       0x800u
#define SSCM_CHIP_CR_EN_VD33_SHIFT                      11u
#define SSCM_CHIP_CR_EN_VD33_WIDTH                      1u
#define SSCM_CHIP_CR_EN_VD33(x)                         ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_EN_VD33_SHIFT))&SSCM_CHIP_CR_EN_VD33_MASK))

#define SSCM_CHIP_CR_PRW_ISOLATE_GMAC0_MASK             0x400u
#define SSCM_CHIP_CR_PRW_ISOLATE_GMAC0_SHIFT            10u
#define SSCM_CHIP_CR_PRW_ISOLATE_GMAC0_WIDTH            1u
#define SSCM_CHIP_CR_PRW_ISOLATE_GMAC0(x)               ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_PRW_ISOLATE_GMAC0_SHIFT))&SSCM_CHIP_CR_PRW_ISOLATE_GMAC0_MASK))

#define SSCM_CHIP_CR_PRW_CLAMP_GMAC0_MASK               0x200u
#define SSCM_CHIP_CR_PRW_CLAMP_GMAC0_SHIFT              9u
#define SSCM_CHIP_CR_PRW_CLAMP_GMAC0_WIDTH              1u
#define SSCM_CHIP_CR_PRW_CLAMP_GMAC0(x)                 ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_PRW_CLAMP_GMAC0_SHIFT))&SSCM_CHIP_CR_PRW_CLAMP_GMAC0_MASK))

#define SSCM_CHIP_CR_PRW_DOWN_GMAC0_MASK                0x100u
#define SSCM_CHIP_CR_PRW_DOWN_GMAC0_SHIFT               8u
#define SSCM_CHIP_CR_PRW_DOWN_GMAC0_WIDTH               1u
#define SSCM_CHIP_CR_PRW_DOWN_GMAC0(x)                  ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_PRW_DOWN_GMAC0_SHIFT))&SSCM_CHIP_CR_PRW_DOWN_GMAC0_MASK))

#define SSCM_CHIP_CR_EN_TS_MASK                         0x8u
#define SSCM_CHIP_CR_EN_TS_SHIFT                        3u
#define SSCM_CHIP_CR_EN_TS_WIDTH                        1u
#define SSCM_CHIP_CR_EN_TS(x)                           ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_EN_TS_SHIFT))&SSCM_CHIP_CR_EN_TS_MASK))

#define SSCM_CHIP_CR_EN_VREF_MASK                       0x4u
#define SSCM_CHIP_CR_EN_VREF_SHIFT                      2u
#define SSCM_CHIP_CR_EN_VREF_WIDTH                      1u
#define SSCM_CHIP_CR_EN_VREF(x)                         ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_EN_VREF_SHIFT))&SSCM_CHIP_CR_EN_VREF_MASK))

#define SSCM_CHIP_CR_EQADC_DMA_DONE_CFG_MASK            0x2u
#define SSCM_CHIP_CR_EQADC_DMA_DONE_CFG_SHIFT           1u
#define SSCM_CHIP_CR_EQADC_DMA_DONE_CFG_WIDTH           1u
#define SSCM_CHIP_CR_EQADC_DMA_DONE_CFG(x)              ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_EQADC_DMA_DONE_CFG_SHIFT))&SSCM_CHIP_CR_EQADC_DMA_DONE_CFG_MASK))

#define SSCM_CHIP_CR_SDADC_DMA_DONE_CFG_MASK            0x1u
#define SSCM_CHIP_CR_SDADC_DMA_DONE_CFG_SHIFT           0u
#define SSCM_CHIP_CR_SDADC_DMA_DONE_CFG_WIDTH           1u
#define SSCM_CHIP_CR_SDADC_DMA_DONE_CFG(x)              ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_SDADC_DMA_DONE_CFG_SHIFT))&SSCM_CHIP_CR_SDADC_DMA_DONE_CFG_MASK))

#elif defined(CCFC3008PC) || defined(CCFC3008PCSN) || defined(CCFC3008PCSA)
typedef union SSCM_CHIP_CR_union_tag {  /* Chip Internal Configuration Register (Reset value: 0x0000_0003) */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t GMAC0_PHY_SEL:3;
    vuint32_t  :16;
    vuint32_t EN_VD33:1;    /* Increase the driving intensity of Medium IO to enable it */
    vuint32_t  :7;
    vuint32_t EN_TS:1;      /* Internal temperature sensor operation enable */
    vuint32_t EN_VREF:1;    /* Enable the reference power supply output of the internal ADC */
    vuint32_t EQADC_DMA_DONE_CFG:1;
    vuint32_t  :1;
  } B;
} SSCM_CHIP_CR_tag;

/* ---------------- SSCM_CHIP_CR_tag bitfield definitions ---------------- */
#define SSCM_CHIP_CR_GMAC0_PHY_SEL_MASK                 0x70000000u
#define SSCM_CHIP_CR_GMAC0_PHY_SEL_SHIFT                28u
#define SSCM_CHIP_CR_GMAC0_PHY_SEL_WIDTH                3u
#define SSCM_CHIP_CR_GMAC0_PHY_SEL(x)                   ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_GMAC0_PHY_SEL_SHIFT))&SSCM_CHIP_CR_GMAC0_PHY_SEL_MASK))

#define SSCM_CHIP_CR_EN_VD33_MASK                       0x800u
#define SSCM_CHIP_CR_EN_VD33_SHIFT                      11u
#define SSCM_CHIP_CR_EN_VD33_WIDTH                      1u
#define SSCM_CHIP_CR_EN_VD33(x)                         ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_EN_VD33_SHIFT))&SSCM_CHIP_CR_EN_VD33_MASK))

#define SSCM_CHIP_CR_EN_TS_MASK                         0x8u
#define SSCM_CHIP_CR_EN_TS_SHIFT                        3u
#define SSCM_CHIP_CR_EN_TS_WIDTH                        1u
#define SSCM_CHIP_CR_EN_TS(x)                           ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_EN_TS_SHIFT))&SSCM_CHIP_CR_EN_TS_MASK))

#define SSCM_CHIP_CR_EN_VREF_MASK                       0x4u
#define SSCM_CHIP_CR_EN_VREF_SHIFT                      2u
#define SSCM_CHIP_CR_EN_VREF_WIDTH                      1u
#define SSCM_CHIP_CR_EN_VREF(x)                         ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_EN_VREF_SHIFT))&SSCM_CHIP_CR_EN_VREF_MASK))

#define SSCM_CHIP_CR_EQADC_DMA_DONE_CFG_MASK            0x2u
#define SSCM_CHIP_CR_EQADC_DMA_DONE_CFG_SHIFT           1u
#define SSCM_CHIP_CR_EQADC_DMA_DONE_CFG_WIDTH           1u
#define SSCM_CHIP_CR_EQADC_DMA_DONE_CFG(x)              ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_EQADC_DMA_DONE_CFG_SHIFT))&SSCM_CHIP_CR_EQADC_DMA_DONE_CFG_MASK))

#elif defined(CCFC3007BC)
typedef union SSCM_CHIP_CR_union_tag {  /* Chip Internal Configuration Register (Reset value: 0x2000_0003) */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t GMAC0_PHY_SEL:3;
    vuint32_t  :16;
    vuint32_t EN_VD33:1;    /* Increase the driving intensity of Medium IO to enable it */
    vuint32_t PRW_ISOLATE_GMAC0:1;
    vuint32_t PRW_CLAMP_GMAC0:1;
    vuint32_t PRW_DOWN_GMAC0:1;
    vuint32_t  :4;
    vuint32_t EN_TS:1;      /* Internal temperature sensor operation enable */
    vuint32_t EN_VREF:1;    /* Enable the reference power supply output of the internal ADC */
    vuint32_t EQADC_DMA_DONE_CFG:1;
    vuint32_t  :1;
  } B;
} SSCM_CHIP_CR_tag;

/* ---------------- SSCM_CHIP_CR_tag bitfield definitions ---------------- */
#define SSCM_CHIP_CR_GMAC0_PHY_SEL_MASK                 0x70000000u
#define SSCM_CHIP_CR_GMAC0_PHY_SEL_SHIFT                28u
#define SSCM_CHIP_CR_GMAC0_PHY_SEL_WIDTH                3u
#define SSCM_CHIP_CR_GMAC0_PHY_SEL(x)                   ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_GMAC0_PHY_SEL_SHIFT))&SSCM_CHIP_CR_GMAC0_PHY_SEL_MASK))

#define SSCM_CHIP_CR_EN_VD33_MASK                       0x800u
#define SSCM_CHIP_CR_EN_VD33_SHIFT                      11u
#define SSCM_CHIP_CR_EN_VD33_WIDTH                      1u
#define SSCM_CHIP_CR_EN_VD33(x)                         ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_EN_VD33_SHIFT))&SSCM_CHIP_CR_EN_VD33_MASK))

#define SSCM_CHIP_CR_PRW_ISOLATE_GMAC0_MASK             0x400u
#define SSCM_CHIP_CR_PRW_ISOLATE_GMAC0_SHIFT            10u
#define SSCM_CHIP_CR_PRW_ISOLATE_GMAC0_WIDTH            1u
#define SSCM_CHIP_CR_PRW_ISOLATE_GMAC0(x)               ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_PRW_ISOLATE_GMAC0_SHIFT))&SSCM_CHIP_CR_PRW_ISOLATE_GMAC0_MASK))

#define SSCM_CHIP_CR_PRW_CLAMP_GMAC0_MASK               0x200u
#define SSCM_CHIP_CR_PRW_CLAMP_GMAC0_SHIFT              9u
#define SSCM_CHIP_CR_PRW_CLAMP_GMAC0_WIDTH              1u
#define SSCM_CHIP_CR_PRW_CLAMP_GMAC0(x)                 ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_PRW_CLAMP_GMAC0_SHIFT))&SSCM_CHIP_CR_PRW_CLAMP_GMAC0_MASK))

#define SSCM_CHIP_CR_PRW_DOWN_GMAC0_MASK                0x100u
#define SSCM_CHIP_CR_PRW_DOWN_GMAC0_SHIFT               8u
#define SSCM_CHIP_CR_PRW_DOWN_GMAC0_WIDTH               1u
#define SSCM_CHIP_CR_PRW_DOWN_GMAC0(x)                  ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_PRW_DOWN_GMAC0_SHIFT))&SSCM_CHIP_CR_PRW_DOWN_GMAC0_MASK))

#define SSCM_CHIP_CR_EN_TS_MASK                         0x8u
#define SSCM_CHIP_CR_EN_TS_SHIFT                        3u
#define SSCM_CHIP_CR_EN_TS_WIDTH                        1u
#define SSCM_CHIP_CR_EN_TS(x)                           ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_EN_TS_SHIFT))&SSCM_CHIP_CR_EN_TS_MASK))

#define SSCM_CHIP_CR_EN_VREF_MASK                       0x4u
#define SSCM_CHIP_CR_EN_VREF_SHIFT                      2u
#define SSCM_CHIP_CR_EN_VREF_WIDTH                      1u
#define SSCM_CHIP_CR_EN_VREF(x)                         ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_EN_VREF_SHIFT))&SSCM_CHIP_CR_EN_VREF_MASK))

#define SSCM_CHIP_CR_EQADC_DMA_DONE_CFG_MASK            0x2u
#define SSCM_CHIP_CR_EQADC_DMA_DONE_CFG_SHIFT           1u
#define SSCM_CHIP_CR_EQADC_DMA_DONE_CFG_WIDTH           1u
#define SSCM_CHIP_CR_EQADC_DMA_DONE_CFG(x)              ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_EQADC_DMA_DONE_CFG_SHIFT))&SSCM_CHIP_CR_EQADC_DMA_DONE_CFG_MASK))

#elif defined(CCFC3012PT) || defined(CCFC3011PT) || defined(CCFC3010PT) || defined(CCFC3010PTD)
typedef union SSCM_CHIP_CR_union_tag {  /* Chip Internal Configuration Register (Reset value: 0x2000_0003) */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t GMAC0_PHY_SEL:3;
    vuint32_t  :17;
    vuint32_t PRW_ISOLATE_GMAC0:1;
    vuint32_t PRW_CLAMP_GMAC0:1;
    vuint32_t PRW_DOWN_GMAC0:1;
    vuint32_t  :3;
    vuint32_t EN_SDADC_BIAS:1;
    vuint32_t EN_TS:1;      /* Internal temperature sensor operation enable */
    vuint32_t EN_VREF:1;    /* Enable the reference power supply output of the internal ADC */
    vuint32_t EQADC_DMA_DONE_CFG:1;
    vuint32_t SDADC_DMA_DONE_CFG:1;
  } B;
} SSCM_CHIP_CR_tag;

/* ---------------- SSCM_CHIP_CR_tag bitfield definitions ---------------- */
#define SSCM_CHIP_CR_GMAC0_PHY_SEL_MASK                 0x70000000u
#define SSCM_CHIP_CR_GMAC0_PHY_SEL_SHIFT                28u
#define SSCM_CHIP_CR_GMAC0_PHY_SEL_WIDTH                3u
#define SSCM_CHIP_CR_GMAC0_PHY_SEL(x)                   ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_GMAC0_PHY_SEL_SHIFT))&SSCM_CHIP_CR_GMAC0_PHY_SEL_MASK))

#define SSCM_CHIP_CR_EN_VD33_MASK                       0x800u
#define SSCM_CHIP_CR_EN_VD33_SHIFT                      11u
#define SSCM_CHIP_CR_EN_VD33_WIDTH                      1u
#define SSCM_CHIP_CR_EN_VD33(x)                         ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_EN_VD33_SHIFT))&SSCM_CHIP_CR_EN_VD33_MASK))

#define SSCM_CHIP_CR_PRW_ISOLATE_GMAC0_MASK             0x400u
#define SSCM_CHIP_CR_PRW_ISOLATE_GMAC0_SHIFT            10u
#define SSCM_CHIP_CR_PRW_ISOLATE_GMAC0_WIDTH            1u
#define SSCM_CHIP_CR_PRW_ISOLATE_GMAC0(x)               ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_PRW_ISOLATE_GMAC0_SHIFT))&SSCM_CHIP_CR_PRW_ISOLATE_GMAC0_MASK))

#define SSCM_CHIP_CR_PRW_CLAMP_GMAC0_MASK               0x200u
#define SSCM_CHIP_CR_PRW_CLAMP_GMAC0_SHIFT              9u
#define SSCM_CHIP_CR_PRW_CLAMP_GMAC0_WIDTH              1u
#define SSCM_CHIP_CR_PRW_CLAMP_GMAC0(x)                 ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_PRW_CLAMP_GMAC0_SHIFT))&SSCM_CHIP_CR_PRW_CLAMP_GMAC0_MASK))

#define SSCM_CHIP_CR_PRW_DOWN_GMAC0_MASK                0x100u
#define SSCM_CHIP_CR_PRW_DOWN_GMAC0_SHIFT               8u
#define SSCM_CHIP_CR_PRW_DOWN_GMAC0_WIDTH               1u
#define SSCM_CHIP_CR_PRW_DOWN_GMAC0(x)                  ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_PRW_DOWN_GMAC0_SHIFT))&SSCM_CHIP_CR_PRW_DOWN_GMAC0_MASK))

#define SSCM_CHIP_CR_EN_SDADC_BIAS_MASK                 0x10u
#define SSCM_CHIP_CR_EN_SDADC_BIAS_SHIFT                4u
#define SSCM_CHIP_CR_EN_SDADC_BIAS_WIDTH                1u
#define SSCM_CHIP_CR_EN_SDADC_BIAS(x)                   ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_EN_SDADC_BIAS_SHIFT))&SSCM_CHIP_CR_EN_SDADC_BIAS_MASK))

#define SSCM_CHIP_CR_EN_TS_MASK                         0x8u
#define SSCM_CHIP_CR_EN_TS_SHIFT                        3u
#define SSCM_CHIP_CR_EN_TS_WIDTH                        1u
#define SSCM_CHIP_CR_EN_TS(x)                           ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_EN_TS_SHIFT))&SSCM_CHIP_CR_EN_TS_MASK))

#define SSCM_CHIP_CR_EN_VREF_MASK                       0x4u
#define SSCM_CHIP_CR_EN_VREF_SHIFT                      2u
#define SSCM_CHIP_CR_EN_VREF_WIDTH                      1u
#define SSCM_CHIP_CR_EN_VREF(x)                         ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_EN_VREF_SHIFT))&SSCM_CHIP_CR_EN_VREF_MASK))

#define SSCM_CHIP_CR_EQADC_DMA_DONE_CFG_MASK            0x2u
#define SSCM_CHIP_CR_EQADC_DMA_DONE_CFG_SHIFT           1u
#define SSCM_CHIP_CR_EQADC_DMA_DONE_CFG_WIDTH           1u
#define SSCM_CHIP_CR_EQADC_DMA_DONE_CFG(x)              ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_EQADC_DMA_DONE_CFG_SHIFT))&SSCM_CHIP_CR_EQADC_DMA_DONE_CFG_MASK))

#define SSCM_CHIP_CR_SDADC_DMA_DONE_CFG_MASK            0x1u
#define SSCM_CHIP_CR_SDADC_DMA_DONE_CFG_SHIFT           0u
#define SSCM_CHIP_CR_SDADC_DMA_DONE_CFG_WIDTH           1u
#define SSCM_CHIP_CR_SDADC_DMA_DONE_CFG(x)              ((uint32_t)(((uint32_t)(((uint32_t)(x))<<SSCM_CHIP_CR_SDADC_DMA_DONE_CFG_SHIFT))&SSCM_CHIP_CR_SDADC_DMA_DONE_CFG_MASK))

#else
    #error "Chip selection: error!"
#endif  /* SSCM_CHIP_CR_tag */

struct SSCM_tag {
  SSCM_STATUS_tag STATUS;              /* SSCM System Status */
  SSCM_MEMCONFIG_tag MEMCONFIG;        /* SSCM System Memory and ID Register */
  uint8_t SSCM_reserved0[2];
  SSCM_ERROR_tag ERROR;                /* SSCM Error Configuration Register */
  uint8_t SSCM_reserved1[4];
  SSCM_PWCMPH_tag PWCMPH;              /* Password comparison register low word */
  SSCM_PWCMPL_tag PWCMPL;              /* Password comparison register low word */
  uint8_t SSCM_reserved2[12];
  SSCM_UOPS_tag UOPS;                  /* SSCM HSM and User Option Status Register */
  uint8_t SSCM_reserved3[4];
  SSCM_PSA_tag PSA;                    /* Processor Start Address Register */
  uint8_t SSCM_reserved4[4];
  SSCM_HSA_tag HSA;                    /* SSCM HSM Start Address Register */
  SSCM_LCSTAT_tag LCSTAT;              /* Life Cycle Status Register */
  SSCM_CHIP_CR_tag CHIP_CR;            /* Chip Internal Configuration Register (Offset: 0x38) */
};

#endif  /* SSCM_REG_H_ */
