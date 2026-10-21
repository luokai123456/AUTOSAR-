#ifndef DMA_MUX_REG_H_
#define DMA_MUX_REG_H_

/* ============================================================================
   =============================== Module: DMAMUX =============================
   ============================================================================ */

typedef union DMAMUX_CHCFG_union_tag { /* Channel Configuration register */
  vuint8_t R;
  struct {
    vuint8_t ENBL:1;                   /* DMA Channel Enable */
    vuint8_t TRIG:1;                   /* DMA Channel Trigger Enable */
    vuint8_t SOURCE:6;                 /* DMA Channel Source (Slot) */
  } B;
} DMAMUX_CHCFG_tag;

struct DMAMUX_tag {
  DMAMUX_CHCFG_tag CHCFG[16];          /* Channel Configuration register */
};

#endif
