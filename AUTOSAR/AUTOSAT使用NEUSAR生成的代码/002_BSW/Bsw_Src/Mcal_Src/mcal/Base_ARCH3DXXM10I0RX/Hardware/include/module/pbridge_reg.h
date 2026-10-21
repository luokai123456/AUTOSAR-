#ifndef PBRIDGE_REG_H_
#define PBRIDGE_REG_H_

/* ============================================================================
   =============================== Module: PBRIDGE ============================
   ============================================================================ */

typedef union PBRIDGE_MPRA_union_tag { /* Master Privilege Register A */
  vuint32_t R;
  struct {
    vuint32_t MPROT0:4;
    vuint32_t MPROT1:4;
    vuint32_t MPROT2:4;
    vuint32_t MPROT3:4;
    vuint32_t MPROT4:4;
    vuint32_t MPROT5:4;
    vuint32_t MPROT6:4;
    vuint32_t MPROT7:4;
  } B;
} PBRIDGE_MPRA_tag;

typedef union PBRIDGE_MPRB_union_tag { /* Master Privilege Register B */
  vuint32_t R;
  struct {
    vuint32_t MPROT8:4;
    vuint32_t MPROT9:4;
    vuint32_t MPROT10:4;
    vuint32_t MPROT11:4;
    vuint32_t MPROT12:4;
    vuint32_t MPROT13:4;
    vuint32_t MPROT14:4;
    vuint32_t MPROT15:4;
  } B;
} PBRIDGE_MPRB_tag;

typedef union PBRIDGE_PACR_union_tag { /* Peripheral Access Control Register */
  vuint32_t R;
  struct {
    vuint32_t PACRa:4;
    vuint32_t PACRb:4;
    vuint32_t PACRc:4;
    vuint32_t PACRd:4;
    vuint32_t PACRe:4;
    vuint32_t PACRf:4;
    vuint32_t PACRg:4;
    vuint32_t PACRh:4;
  } B;
} PBRIDGE_PACR_tag;

typedef union PBRIDGE_OPACR_union_tag { /* Off-platform Peripheral Access Control Register */
  vuint32_t R;
  struct {
    vuint32_t OPACRa:4;
    vuint32_t OPACRb:4;
    vuint32_t OPACRc:4;
    vuint32_t OPACRd:4;
    vuint32_t OPACRe:4;
    vuint32_t OPACRf:4;
    vuint32_t OPACRg:4;
    vuint32_t OPACRh:4;
  } B;
} PBRIDGE_OPACR_tag;

struct PBRIDGE_tag {
  PBRIDGE_MPRA_tag MPRA;               /* Master Privilege Register A */
  PBRIDGE_MPRB_tag MPRB;               /* Master Privilege Register B */
  uint8_t PBRIDGE_reserved0[248];
  PBRIDGE_PACR_tag PACR[8];            /* Peripheral Access Control Register */
  uint8_t PBRIDGE_reserved1[32];
  PBRIDGE_OPACR_tag OPACR[32];         /* Off-platform Peripheral Access Control Register */
};

#endif
