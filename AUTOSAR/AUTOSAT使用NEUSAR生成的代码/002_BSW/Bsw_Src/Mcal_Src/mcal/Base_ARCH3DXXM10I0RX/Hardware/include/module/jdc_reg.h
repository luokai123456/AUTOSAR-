#ifndef JDC_REG_H_
#define JDC_REG_H_

/* ============================================================================
   =============================== Module: JDC ================================
   ============================================================================ */

typedef union JDC_MCR_union_tag {      /* Module Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :15;
    vuint32_t JIN_IEN:1;
    vuint32_t  :15;
    vuint32_t JOUT_IEN:1;
  } B;
} JDC_MCR_tag;

typedef union JDC_MSR_union_tag {      /* Module Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :13;
    vuint32_t JIN_RDY:1;
    vuint32_t  :1;
    vuint32_t JIN_INT:1;
    vuint32_t  :13;
    vuint32_t JOUT_RDY:1;
    vuint32_t  :1;
    vuint32_t JOUT_INT:1;
  } B;
} JDC_MSR_tag;

typedef union JDC_JOUT_IPS_union_tag { /* JTAG Output Data Register */
  vuint32_t R;
  struct {
    vuint32_t Data:32;
  } B;
} JDC_JOUT_IPS_tag;

typedef union JDC_JIN_IPS_union_tag {  /* JTAG Input Data Register */
  vuint32_t R;
  struct {
    vuint32_t Data:32;
  } B;
} JDC_JIN_IPS_tag;

struct JDC_tag {
  JDC_MCR_tag MCR;                     /* Module Configuration Register */
  JDC_MSR_tag MSR;                     /* Module Status Register */
  JDC_JOUT_IPS_tag JOUT_IPS;           /* JTAG Output Data Register */
  JDC_JIN_IPS_tag JIN_IPS;             /* JTAG Input Data Register */
};

#endif
