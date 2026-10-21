#ifndef PCM_REG_H_
#define PCM_REG_H_

/* ============================================================================
   =============================== Module: PCM ================================
   ============================================================================ */

typedef union PCM_FBOMCR_union_tag {   /* FEC Burst Optimization Master Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :21;
    vuint32_t ACCERR:1;
    vuint32_t WBEN:1;
    vuint32_t RBEN:1;
    vuint32_t FXSBE:8;
  } B;
} PCM_FBOMCR_tag;

typedef union PCM_IAHB_BE1_union_tag { /* IAHB Burst Enable 1 Register */
  vuint32_t R;
  struct {
    vuint32_t  :5;
    vuint32_t RSV:3;
    vuint32_t  :5;
    vuint32_t PRE_DMA:1;
    vuint32_t BRE_DMA:1;
    vuint32_t BWE_DMA:1;
    vuint32_t  :5;
    vuint32_t PRE_S0:1;
    vuint32_t BRE_S0:1;
    vuint32_t BWE_S0:1;
    vuint32_t  :5;
    vuint32_t PRE_M3:1;
    vuint32_t BRE_M3:1;
    vuint32_t BWE_M3:1;
  } B;
} PCM_IAHB_BE1_tag;

typedef union PCM_IAHB_BE2_union_tag { /* IAHB Burst Enable 2 Register */
  vuint32_t R;
  struct {
    vuint32_t  :5;
    vuint32_t RSV:3;
    vuint32_t  :5;
    vuint32_t PRE_SIPI:1;
    vuint32_t BRE_SIPI:1;
    vuint32_t BWE_SIPI:1;
    vuint32_t  :5;
    vuint32_t PRE_FlexRay:1;
    vuint32_t BRE_FlexRay:1;
    vuint32_t BWE_FlexRay:1;
    vuint32_t  :5;
    vuint32_t PRE_FEC:1;
    vuint32_t BRE_FEC:1;
    vuint32_t BWE_FEC:1;
  } B;
} PCM_IAHB_BE2_tag;

struct PCM_tag {
  PCM_FBOMCR_tag FBOMCR;               /* FEC Burst Optimization Master Control Register */
  PCM_IAHB_BE1_tag IAHB_BE1;           /* IAHB Burst Enable 1 Register */
  PCM_IAHB_BE2_tag IAHB_BE2;           /* IAHB Burst Enable 2 Register */
};

#endif
