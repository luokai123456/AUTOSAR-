#ifndef STM_REG_H_
#define STM_REG_H_

/* ============================================================================
   =============================== Module: STM ================================
   ============================================================================ */

typedef union STM_CR_union_tag {       /* STM Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t CPS:8;                   /* Counter Prescaler. */
    vuint32_t  :6;
    vuint32_t FRZ:1;                   /* Freeze. */
    vuint32_t TEN:1;                   /* Timer counter Enabled. */
  } B;
} STM_CR_tag;

typedef union STM_CNT_union_tag {      /* STM Count Register */
  vuint32_t R;
  struct {
    vuint32_t CNT:32;                  /* Timer count value used as the time base for all channels. */
  } B;
} STM_CNT_tag;

typedef union STM_CHANNEL_CCR_union_tag { /* STM Channel Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t CEN:1;                   /* Channel Enable */
  } B;
} STM_CHANNEL_CCR_tag;

typedef union STM_CHANNEL_CIR_union_tag { /* STM Channel Interrupt Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t CIF:1;                   /* Channel Interrupt Flag */
  } B;
} STM_CHANNEL_CIR_tag;

typedef union STM_CHANNEL_CMP_union_tag { /* STM Channel Compare Register */
  vuint32_t R;
  struct {
    vuint32_t CMP:32;                  /* Compare value for channel n. */
  } B;
} STM_CHANNEL_CMP_tag;

typedef struct STM_CHANNEL_struct_tag {
  STM_CHANNEL_CCR_tag CCR;             /* STM Channel Control Register */
  STM_CHANNEL_CIR_tag CIR;             /* STM Channel Interrupt Register */
  STM_CHANNEL_CMP_tag CMP;             /* STM Channel Compare Register */
  uint8_t CHANNEL_reserved0[4];
} STM_CHANNEL_tag;

struct STM_tag {
  STM_CR_tag CR;                       /* STM Control Register */
  STM_CNT_tag CNT;                     /* STM Count Register */
  uint8_t STM_reserved0[8];
  STM_CHANNEL_tag CHANNEL[4];
};

#endif
