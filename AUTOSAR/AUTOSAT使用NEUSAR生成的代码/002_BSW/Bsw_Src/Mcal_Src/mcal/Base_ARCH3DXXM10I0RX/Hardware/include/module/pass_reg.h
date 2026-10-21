#ifndef PASS_REG_H_
#define PASS_REG_H_

/* ============================================================================
   =============================== Module: PASS ===============================
   ============================================================================ */

typedef union PASS_LCSTAT_union_tag {  /* Life Cycle Status Register */
  vuint32_t R;
  struct {
    vuint32_t CNS:1;
    vuint32_t JUN:1;
    vuint32_t  :1;
    vuint32_t  :21;
    vuint32_t LIFE:8;
  } B;
} PASS_LCSTAT_tag;

typedef union PASS_CHSEL_union_tag {   /* Challenge Selector Register */
  vuint32_t R;
  struct {
    vuint32_t  :29;
    vuint32_t GRP:3;
  } B;
} PASS_CHSEL_tag;

typedef union PASS_CSTAT_union_tag {   /* Challenge Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :28;
    vuint32_t CMST:4;
  } B;
} PASS_CSTAT_tag;

typedef union PASS_CIN_union_tag {     /* Challenge Input Register */
  vuint32_t R;
  struct {
    vuint32_t PW32:32;
  } B;
} PASS_CIN_tag;

typedef union PASS_CJE_union_tag {     /* Clock Jitter Enable */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t CJE:1;
  } B;
} PASS_CJE_tag;

typedef union PASS_PG_LOCK0_union_tag { /* Password Group n - Lock 0 Status Register */
  vuint32_t R;
  struct {
    vuint32_t TSLOCK:1;
    vuint32_t ATSL:1;
    vuint32_t LOWLOCK:14;
    vuint32_t MIDLOCK:16;
  } B;
} PASS_PG_LOCK0_tag;

typedef union PASS_PG_LOCK1_union_tag { /* Password Group n - Lock 1 Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t HIGHLOCK:16;
  } B;
} PASS_PG_LOCK1_tag;

typedef union PASS_PG_LOCK2_union_tag { /* Password Group n - Lock 2 Status Register */
  vuint32_t R;
  struct {
    vuint32_t L_256LCK:32;
  } B;
} PASS_PG_LOCK2_tag;

typedef union PASS_PG_LOCK3_union_tag { /* Password Group n - Lock 3 Status Register */
  vuint32_t R;
  struct {
    vuint32_t PGL:1;
    vuint32_t DBL:1;
    vuint32_t MO:1;
    vuint32_t  :1;
    vuint32_t MSTR:4;
    vuint32_t  :3;
    vuint32_t RL4:1;
    vuint32_t RL3:1;
    vuint32_t RL2:1;
    vuint32_t RL1:1;
    vuint32_t RL0:1;
    vuint32_t U_256LCK:16;
  } B;
} PASS_PG_LOCK3_tag;

typedef union PASS_PG_LOCK4_union_tag { /* Password Group n - Lock 2 Status Register */
  vuint32_t R;
  struct {
    vuint32_t U_256LCK:32;
  } B;
} PASS_PG_LOCK4_tag;

typedef struct PASS_PG_struct_tag {
  PASS_PG_LOCK0_tag LOCK0;             /* Password Group n - Lock 0 Status Register */
  PASS_PG_LOCK1_tag LOCK1;             /* Password Group n - Lock 1 Status Register */
  PASS_PG_LOCK2_tag LOCK2;             /* Password Group n - Lock 2 Status Register */
  PASS_PG_LOCK3_tag LOCK3;             /* Password Group n - Lock 3 Status Register */

#if (defined(CCFC3012PT) || defined(CCFC3011PT) || defined(CCFC3010PT))
  PASS_PG_LOCK4_tag LOCK4;             /* Password Group n - Lock 4 Status Register */
#endif
} PASS_PG_tag;

struct PASS_tag {
  PASS_LCSTAT_tag LCSTAT;              /* Life Cycle Status Register */
  uint8_t PASS_reserved0[4];
  PASS_CHSEL_tag CHSEL;                /* Challenge Selector Register */
  uint8_t PASS_reserved1[4];
  PASS_CSTAT_tag CSTAT;                /* Challenge Status Register */
  uint8_t PASS_reserved2[12];
  PASS_CIN_tag CIN[8];                 /* Challenge Input Register */
  uint8_t PASS_reserved3[144];
  PASS_CJE_tag CJE;                    /* Clock Jitter Enable */
  uint8_t PASS_reserved4[44];
  PASS_PG_tag PG[4];
};

#endif
