#ifndef INTC_REG_H_
#define INTC_REG_H_

/* ============================================================================
   =============================== Module: INTC ===============================
   ============================================================================ */

typedef union INTC_BCR_union_tag {     /* INTC Block Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :19;
    vuint32_t HVEN3:1;
    vuint32_t  :3;
    vuint32_t HVEN2:1;
    vuint32_t  :3;
    vuint32_t HVEN1:1;
    vuint32_t  :3;
    vuint32_t HVEN0:1;
  } B;
} INTC_BCR_tag;

typedef union INTC_MPROT_union_tag {   /* INTC Master Protection Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t ID:2;
    vuint32_t  :3;
    vuint32_t MPROT:1;
  } B;
} INTC_MPROT_tag;

typedef union INTC_CPR_union_tag {     /* INTC Current Priority Register for Processor 0 */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t PRI:6;
  } B;
} INTC_CPR_tag;

typedef union INTC_IACKR_union_tag {   /* INTC Interrupt Acknowledge Register for Processor 0 */
  vuint32_t R;
  struct {
    vuint32_t VTBA:20;
    vuint32_t INTVEC:10;
    vuint32_t  :2;
  } B;
} INTC_IACKR_tag;

typedef union INTC_EOIR_union_tag {    /* INTC End Of Interrupt Register for Processor 0 */
  vuint32_t R;
  struct {
    vuint32_t EOI:32;
  } B;
} INTC_EOIR_tag;

typedef union INTC_SSCIR_union_tag {   /* INTC Software Set/Clear Interrupt Register */
  vuint8_t R;
  struct {
    vuint8_t  :6;
    vuint8_t SET:1;
    vuint8_t CLR:1;
  } B;
} INTC_SSCIR_tag;

typedef union INTC_PSR_union_tag {     /* INTC Priority Select Register */
  vuint16_t R;
  struct {
    vuint16_t PRC_SELN0:1;
    vuint16_t PRC_SELN1:1;
    vuint16_t PRC_SELN2:1;
    vuint16_t PRC_SELN3:1;
    vuint16_t  :3;
    vuint16_t SWTN:1;
    vuint16_t  :2;
    vuint16_t PRIN:6;
  } B;
} INTC_PSR_tag;

struct INTC_tag {
  INTC_BCR_tag BCR;                    /* INTC Block Configuration Register */
  INTC_MPROT_tag MPROT;                /* INTC Master Protection Register */
  uint8_t INTC_reserved0[8];
  INTC_CPR_tag CPR[4];                 /* INTC Current Priority Register for Processor 0 */
  INTC_IACKR_tag IACKR[4];             /* INTC Interrupt Acknowledge Register for Processor 0 */
  INTC_EOIR_tag EOIR[4];               /* INTC End Of Interrupt Register for Processor 0 */
  INTC_SSCIR_tag SSCIR[32];            /* INTC Software Set/Clear Interrupt Register */
  INTC_PSR_tag PSR[1024];              /* INTC Priority Select Register */
};

#endif
