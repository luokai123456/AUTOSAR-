#ifndef SEMA42_REG_H_
#define SEMA42_REG_H_

/* ============================================================================
   =============================== Module: SEMA42 =============================
   ============================================================================ */

typedef union SEMA42_GATE_union_tag {  /* Gate Register */
  vuint8_t R;
  struct {
    vuint8_t  :4;
    vuint8_t GTFSM:4;                  /* Gate Finite State Machine. */
  } B;
} SEMA42_GATE_tag;

typedef union SEMA42_RSTGT_R_union_tag { /* Reset Gate Read */
  vuint16_t R;
  struct {
    vuint16_t  :2;
    vuint16_t RSTGSM:2;
    vuint16_t RSTGMS:4;
    vuint16_t RSTGTN:8;
  } B;
} SEMA42_RSTGT_R_tag;

typedef union SEMA42_RSTGT_W_union_tag { /* Reset Gate Write */
  vuint16_t R;
  struct {
    vuint16_t RSTGDP:8;
    vuint16_t RSTGTN:8;
  } B;
} SEMA42_RSTGT_W_tag;

typedef union SEMA42_RSTGT_union_tag {
  SEMA42_RSTGT_R_tag R;                /* Reset Gate Read */
  SEMA42_RSTGT_W_tag W;                /* Reset Gate Write */
} SEMA42_RSTGT_tag;

struct SEMA42_tag {
  SEMA42_GATE_tag GATE[16];            /* Gate Register */
  uint8_t SEMA42_reserved0[48];
  SEMA42_RSTGT_tag RSTGT;
};

typedef struct SEMA42_tag SEMA42_Type;/* PRQA S 1508 */

/* SEMA42 - Peripheral instance pMcu_Base addresses */
/** Peripheral SEMA42 pMcu_Base address */
#define SEMA42_BASE                             (0xFC03C000UL)
/** Peripheral SEMA42 pMcu_Base pointer */
#define SEMA42_StPtr                            ((SEMA42_Type *)SEMA42_BASE)
/** Array initializer of SEMA42 peripheral pMcu_Base addresses */
#define SEMA42_BASE_ADDRS                       { SEMA42_BASE }
/** Array initializer of SEMA42 peripheral pMcu_Base pointers */
#define SEMA42_BASE_PTRS                        { SEMA42_StPtr }



#endif  /* SEMA42_REG_H_ */
