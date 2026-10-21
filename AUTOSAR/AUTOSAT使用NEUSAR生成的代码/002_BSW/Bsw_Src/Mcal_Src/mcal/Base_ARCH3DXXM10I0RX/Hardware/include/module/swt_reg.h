#ifndef SWT_REG_H_
#define SWT_REG_H_

/* ============================================================================
   =============================== Module: SWT ================================
   ============================================================================ */

typedef union SWT_CR_union_tag {       /* SWT Control Register */
  vuint32_t R;
  struct {
    vuint32_t MAP0:1;
    vuint32_t MAP1:1;
    vuint32_t MAP2:1;
    vuint32_t MAP3:1;
    vuint32_t MAP4:1;
    vuint32_t MAP5:1;
    vuint32_t MAP6:1;
    vuint32_t MAP7:1;
    vuint32_t  :13;
    vuint32_t SMD:2;                   /* Service Mode. */
    vuint32_t RIA:1;
    vuint32_t WND:1;
    vuint32_t ITR:1;
    vuint32_t HLK:1;
    vuint32_t SLK:1;
    vuint32_t  :1;                     /* Reserved */
    vuint32_t STP:1;
    vuint32_t FRZ:1;
    vuint32_t WEN:1;
  } B;
} SWT_CR_tag;

typedef union SWT_IR_union_tag {       /* SWT Interrupt Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t TIF:1;                   /* Time-out Interrupt Flag */
  } B;
} SWT_IR_tag;

typedef union SWT_TO_union_tag {       /* SWT Time-out Register */
  vuint32_t R;
  struct {
    vuint32_t WTO:32;
  } B;
} SWT_TO_tag;

typedef union SWT_WN_union_tag {       /* SWT Window Register */
  vuint32_t R;
  struct {
    vuint32_t WST:32;                  /* Window Start Value */
  } B;
} SWT_WN_tag;

typedef union SWT_SR_union_tag {       /* SWT Service Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t WSC:16;                  /* Watchdog Service Code */
  } B;
} SWT_SR_tag;

typedef union SWT_CO_union_tag {       /* SWT Counter Output Register */
  vuint32_t R;
  struct {
    vuint32_t CNT:32;
  } B;
} SWT_CO_tag;

typedef union SWT_SK_union_tag {       /* SWT Service Key Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t SK:16;                   /* Service Key */
  } B;
} SWT_SK_tag;

struct SWT_tag {
  SWT_CR_tag CR;                       /* SWT Control Register */
  SWT_IR_tag IR;                       /* SWT Interrupt Register */
  SWT_TO_tag TO;                       /* SWT Time-out Register */
  SWT_WN_tag WN;                       /* SWT Window Register */
  SWT_SR_tag SR;                       /* SWT Service Register */
  SWT_CO_tag CO;                       /* SWT Counter Output Register */
  SWT_SK_tag SK;                       /* SWT Service Key Register */
};

#endif
