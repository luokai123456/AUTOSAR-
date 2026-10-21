#ifndef PIT_REG_H_
#define PIT_REG_H_

/* ============================================================================
   =============================== Module: PIT ================================
   ============================================================================ */

typedef union PIT_MCR_union_tag {      /* PIT Module Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :29;
    vuint32_t MDIS_RTI:1;
    vuint32_t MDIS:1;
    vuint32_t FRZ:1;
  } B;
} PIT_MCR_tag;

typedef union PIT_LTMR64H_union_tag {  /* PIT Upper Lifetime Timer Register */
  vuint32_t R;
  struct {
    vuint32_t LTH:32;
  } B;
} PIT_LTMR64H_tag;

typedef union PIT_LTMR64L_union_tag {  /* PIT Lower Lifetime Timer Register */
  vuint32_t R;
  struct {
    vuint32_t LTL:32;
  } B;
} PIT_LTMR64L_tag;

typedef union PIT_RTI_LDVAL_union_tag { /* PIT RTI Timer Load Value Register */
  vuint32_t R;
  struct {
    vuint32_t TSV:32;
  } B;
} PIT_RTI_LDVAL_tag;

typedef union PIT_RTI_CVAL_union_tag { /* PIT RTI Current Timer Value Register */
  vuint32_t R;
  struct {
    vuint32_t TVL:32;
  } B;
} PIT_RTI_CVAL_tag;

typedef union PIT_RTI_TCTRL_union_tag { /* PIT RTI Timer Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :29;
    vuint32_t CHN:1;
    vuint32_t TIE:1;
    vuint32_t TEN:1;
  } B;
} PIT_RTI_TCTRL_tag;

typedef union PIT_RTI_TFLG_union_tag { /* PIT RTI Timer Flag Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t TIF:1;
  } B;
} PIT_RTI_TFLG_tag;

typedef union PIT_TIMER_LDVAL_union_tag { /* PIT Timer Load Value Register n */
  vuint32_t R;
  struct {
    vuint32_t TSV:32;
  } B;
} PIT_TIMER_LDVAL_tag;

typedef union PIT_TIMER_CVAL_union_tag { /* PIT Current Timer Value Register n */
  vuint32_t R;
  struct {
    vuint32_t TVL:32;
  } B;
} PIT_TIMER_CVAL_tag;

typedef union PIT_TIMER_TCTRL_union_tag { /* PIT Timer Control Register n */
  vuint32_t R;
  struct {
    vuint32_t  :29;
    vuint32_t CHN:1;
    vuint32_t TIE:1;
    vuint32_t TEN:1;
  } B;
} PIT_TIMER_TCTRL_tag;

typedef union PIT_TIMER_TFLG_union_tag { /* PIT Timer Flag Register n */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t TIF:1;
  } B;
} PIT_TIMER_TFLG_tag;

typedef struct PIT_TIMER_struct_tag {
  PIT_TIMER_LDVAL_tag LDVAL;           /* PIT Timer Load Value Register n */
  PIT_TIMER_CVAL_tag CVAL;             /* PIT Current Timer Value Register n */
  PIT_TIMER_TCTRL_tag TCTRL;           /* PIT Timer Control Register n */
  PIT_TIMER_TFLG_tag TFLG;             /* PIT Timer Flag Register n */
} PIT_TIMER_tag;

struct PIT_tag {
  PIT_MCR_tag MCR;                     /* PIT Module Control Register */
  uint8_t PIT_reserved0[220];
  PIT_LTMR64H_tag LTMR64H;             /* PIT Upper Lifetime Timer Register */
  PIT_LTMR64L_tag LTMR64L;             /* PIT Lower Lifetime Timer Register */
  uint8_t PIT_reserved1[8];
  PIT_RTI_LDVAL_tag RTI_LDVAL;         /* PIT RTI Timer Load Value Register */
  PIT_RTI_CVAL_tag RTI_CVAL;           /* PIT RTI Current Timer Value Register */
  PIT_RTI_TCTRL_tag RTI_TCTRL;         /* PIT RTI Timer Control Register */
  PIT_RTI_TFLG_tag RTI_TFLG;           /* PIT RTI Timer Flag Register */
  PIT_TIMER_tag TIMER[8];
};

#endif
