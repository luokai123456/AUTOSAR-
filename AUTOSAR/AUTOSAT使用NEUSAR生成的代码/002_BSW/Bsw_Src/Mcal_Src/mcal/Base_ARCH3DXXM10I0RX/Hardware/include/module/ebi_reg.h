#ifndef EBI_REG_H_
#define EBI_REG_H_

/* ============================================================================
   =============================== Module: EBI ================================
   ============================================================================ */

typedef union EBI_MCR_union_tag {      /* Module Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t ACGE:1;
    vuint32_t  :2;
    vuint32_t  :2;
    vuint32_t  :4;
    vuint32_t MDIS:1;
    vuint32_t  :3;
    vuint32_t D16_31:1;
    vuint32_t  :1;
    vuint32_t DBM:1;
  } B;
} EBI_MCR_tag;

typedef union EBI_BR0_union_tag {      /* Base Register Bank */
  vuint32_t R;
  struct {
    vuint32_t BA:17;
    vuint32_t  :2;
    vuint32_t LWRN:1;
    vuint32_t PS:1;
    vuint32_t EOE:2;
    vuint32_t SBL:1;
    vuint32_t AD_MUX:1;
    vuint32_t BL:1;
    vuint32_t WEBS:1;
    vuint32_t TBDIP:1;
    vuint32_t GCSN:1;
    vuint32_t  :1;
    vuint32_t BI:1;
    vuint32_t V:1;
  } B;
} EBI_BR0_tag;

typedef union EBI_OR0_union_tag {      /* Option Register Bank */
  vuint32_t R;
  struct {
    vuint32_t AM:17;
    vuint32_t  :2;
    vuint32_t APS:1;                   /* Address by Port Size */
    vuint32_t  :1;
    vuint32_t AWE:1;                   /* Address / Write Enable Select */
    vuint32_t  :2;
    vuint32_t SCY:4;
    vuint32_t  :1;
    vuint32_t BSCY:2;
    vuint32_t  :1;
  } B;
} EBI_OR0_tag;

typedef union EBI_BR1_union_tag {      /* Base Register Bank */
  vuint32_t R;
  struct {
    vuint32_t BA:17;
    vuint32_t  :2;
    vuint32_t LWRN:1;
    vuint32_t PS:1;
    vuint32_t EOE:2;
    vuint32_t SBL:1;
    vuint32_t AD_MUX:1;
    vuint32_t BL:1;
    vuint32_t WEBS:1;
    vuint32_t TBDIP:1;
    vuint32_t GCSN:1;
    vuint32_t  :1;
    vuint32_t BI:1;
    vuint32_t V:1;
  } B;
} EBI_BR1_tag;

typedef union EBI_OR1_union_tag {      /* Option Register Bank */
  vuint32_t R;
  struct {
    vuint32_t AM:17;
    vuint32_t  :2;
    vuint32_t APS:1;                   /* Address by Port Size */
    vuint32_t  :1;
    vuint32_t AWE:1;                   /* Address / Write Enable Select */
    vuint32_t  :2;
    vuint32_t SCY:4;
    vuint32_t  :1;
    vuint32_t BSCY:2;
    vuint32_t  :1;
  } B;
} EBI_OR1_tag;

typedef union EBI_BR2_union_tag {      /* Base Register Bank */
  vuint32_t R;
  struct {
    vuint32_t BA:17;
    vuint32_t  :2;
    vuint32_t LWRN:1;
    vuint32_t PS:1;
    vuint32_t EOE:2;
    vuint32_t SBL:1;
    vuint32_t AD_MUX:1;
    vuint32_t BL:1;
    vuint32_t WEBS:1;
    vuint32_t TBDIP:1;
    vuint32_t GCSN:1;
    vuint32_t  :1;
    vuint32_t BI:1;
    vuint32_t V:1;
  } B;
} EBI_BR2_tag;

typedef union EBI_OR2_union_tag {      /* Option Register Bank */
  vuint32_t R;
  struct {
    vuint32_t AM:17;
    vuint32_t  :2;
    vuint32_t APS:1;                   /* Address by Port Size */
    vuint32_t  :1;
    vuint32_t AWE:1;                   /* Address / Write Enable Select */
    vuint32_t  :2;
    vuint32_t SCY:4;
    vuint32_t  :1;
    vuint32_t BSCY:2;
    vuint32_t  :1;
  } B;
} EBI_OR2_tag;

struct EBI_tag {
  EBI_MCR_tag MCR;                     /* Module Configuration Register */
  uint8_t EBI_reserved0[12];
  EBI_BR0_tag BR0;                     /* Base Register Bank */
  EBI_OR0_tag OR0;                     /* Option Register Bank */
  EBI_BR1_tag BR1;                     /* Base Register Bank */
  EBI_OR1_tag OR1;                     /* Option Register Bank */
  EBI_BR2_tag BR2;                     /* Base Register Bank */
  EBI_OR2_tag OR2;                     /* Option Register Bank */
};

#endif
