#ifndef CRC_REG_H_
#define CRC_REG_H_

/* ============================================================================
   =============================== Module: CRC ================================
   ============================================================================ */

typedef union CRC_CFG_union_tag {      /* Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t  :18;
    vuint32_t SWAP_BYTEWISE:1;         /* Swap CRC_INP byte-wise */
    vuint32_t SWAP_BITWISE:1;          /* Swap CRC_INP bit-wise */
    vuint32_t POLYG:2;                 /* Polynomial selection */
    vuint32_t SWAP:1;                  /* Swap selection */
    vuint32_t INV:1;                   /* Inversion selection */
  } B;
} CRC_CFG_tag;

typedef union CRC_INP_union_tag {      /* Input Register */
  vuint32_t R;
  struct {
    vuint32_t INP:32;                  /* Input data for the CRC computation */
  } B;
} CRC_INP_tag;

typedef union CRC_CSTAT_union_tag {    /* Current Status Register */
  vuint32_t R;
  struct {
    vuint32_t CSTAT:32;                /* CRC signature status */
  } B;
} CRC_CSTAT_tag;

typedef union CRC_OUTP_union_tag {     /* Output Register */
  vuint32_t R;
  struct {
    vuint32_t OUTP:32;                 /* Final CRC signature */
  } B;
} CRC_OUTP_tag;

struct CRC_tag {
  CRC_CFG_tag CFG;                     /* Configuration Register */
  CRC_INP_tag INP;                     /* Input Register */
  CRC_CSTAT_tag CSTAT;                 /* Current Status Register */
  CRC_OUTP_tag OUTP;                   /* Output Register */
};

#endif
