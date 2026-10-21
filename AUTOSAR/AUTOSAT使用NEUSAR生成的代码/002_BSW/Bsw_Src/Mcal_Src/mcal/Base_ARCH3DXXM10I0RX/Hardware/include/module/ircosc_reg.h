#ifndef IRCOSC_REG_H_
#define IRCOSC_REG_H_

/* ============================================================================
   =============================== Module: IRCOSC =============================
   ============================================================================ */

typedef union IRCOSC_CTL_union_tag {   /* IRCOSC Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t  :1;                  /* Reserved */
#if defined(CCFC3008PT)
    vuint32_t  :1;
#else
    vuint32_t  FIRCOFF_STDBY:1;     /* FIRC is switched on/off in STANDBY mode */
#endif
    vuint32_t  :2;
    vuint32_t  USER_TRIM:5;         /* User trimming bits */
    vuint32_t  :3;
#if defined(CCFC3008PT)
    vuint32_t  :5;                  /* Reserved */
#else
    vuint32_t  FIRCDIV:5;           /* FIRC clock division factor */
#endif
    vuint32_t  :2;
    vuint32_t  :1;                  /* Reserved */
    vuint32_t  :5;
  } B;
} IRCOSC_CTL_tag;

typedef union SIRCOSC_CTL_union_tag {   /* SIRCOSC Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t  SIRC_ON:1;
  } B;
} SIRCOSC_CTL_tag;

struct IRCOSC_tag {
  IRCOSC_CTL_tag CTL;                  /* IRCOSC Control Register */
  vuint32_t IRC_reserved[8];
  SIRCOSC_CTL_tag SCTL;                /* SIRCOSC Control Register */
};

#endif  /* IRCOSC_REG_H_ */
