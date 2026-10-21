#ifndef XOSC_REG_H_
#define XOSC_REG_H_

/* ============================================================================
   =============================== Module: XOSC ===============================
   ============================================================================ */

typedef union XOSC_CTL_union_tag {     /* XOSC Control Register */
  vuint32_t R;
  struct {
    vuint32_t OSCBYP:1;
    vuint32_t  :2;
    vuint32_t  :5;
    vuint32_t EOCV:8;                  /* End of Count Value */
    vuint32_t M_OSC:1;                 /* Crystal oscillator clock interrupt mask */
    vuint32_t  :2;
    vuint32_t  :5;
    vuint32_t I_OSC:1;
    vuint32_t  :5;
    vuint32_t  :1;
    vuint32_t  :1;
  } B;
} XOSC_CTL_tag;

struct XOSC_tag {
  XOSC_CTL_tag CTL;                    /* XOSC Control Register */
};

#endif
