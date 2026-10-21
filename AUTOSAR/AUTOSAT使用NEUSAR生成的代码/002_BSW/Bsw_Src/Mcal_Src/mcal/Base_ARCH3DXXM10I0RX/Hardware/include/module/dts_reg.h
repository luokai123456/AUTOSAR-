#ifndef DTS_REG_H_
#define DTS_REG_H_

/* ============================================================================
   =============================== Module: DTS ================================
   ============================================================================ */

typedef union DTS_ENABLE_union_tag {   /* Output Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :30;
    vuint32_t DTS_EN_B:1;
    vuint32_t DTS_EN:1;
  } B;
} DTS_ENABLE_tag;

typedef union DTS_STARTUP_union_tag {  /* Startup Register */
  vuint32_t R;
  struct {
    vuint32_t AD:32;
  } B;
} DTS_STARTUP_tag;

typedef union DTS_SEMAPHORE_union_tag { /* Semaphore Register */
  vuint32_t R;
  struct {
    vuint32_t ST:32;
  } B;
} DTS_SEMAPHORE_tag;

typedef union DTS_SEMAPHORE_B_union_tag { /* Semaphore Extension */
  vuint32_t R;
  struct {
    vuint32_t ST_B:32;
  } B;
} DTS_SEMAPHORE_B_tag;

struct DTS_tag {
  DTS_ENABLE_tag ENABLE;               /* Output Enable Register */
  DTS_STARTUP_tag STARTUP;             /* Startup Register */
  DTS_SEMAPHORE_tag SEMAPHORE;         /* Semaphore Register */
  DTS_SEMAPHORE_B_tag SEMAPHORE_B;     /* Semaphore Extension */
};

#endif
