#ifndef MC_PCU_REG_H_
#define MC_PCU_REG_H_

/* ============================================================================
   =============================== Module: MC_PCU =============================
   ============================================================================ */

typedef union MC_PCU_PSTAT_union_tag { /* Power Domain Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t PD_0:1;
  } B;
} MC_PCU_PSTAT_tag;

struct MC_PCU_tag {
  uint8_t MC_PCU_reserved0[64];
  MC_PCU_PSTAT_tag PSTAT;              /* Power Domain Status Register */
};

#endif  /* MC_PCU_REG_H_ */
