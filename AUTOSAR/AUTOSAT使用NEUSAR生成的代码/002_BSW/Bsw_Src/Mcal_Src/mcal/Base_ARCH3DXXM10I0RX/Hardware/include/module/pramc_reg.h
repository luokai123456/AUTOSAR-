#ifndef PRAMC_REG_H_
#define PRAMC_REG_H_
/* ============================================================================
   =============================== Module: PRAMC ==============================
   ============================================================================ */

typedef union PRAMC_PRCR1_union_tag {  /* Platform RAM Configuration Register 1 */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t PRI:2;                   /* AHB port arbitration mode. */
    vuint32_t P1_BO_DIS:1;             /* Port p1 read burst optimization disable. */
    vuint32_t P0_BO_DIS:1;             /* Port p0 read burst optimization disable. */
    vuint32_t P1_RB_DIS:1;             /* Port p1 read buffer disable. */
    vuint32_t P0_RB_DIS:1;             /* Port p0 read buffer disable. */
    vuint32_t  :3;
    vuint32_t FT_DIS:1;                /* Flow through disabled. */
  } B;
} PRAMC_PRCR1_tag;

struct PRAMC_tag {
  PRAMC_PRCR1_tag PRCR1;               /* Platform RAM Configuration Register 1 */
};

#endif
