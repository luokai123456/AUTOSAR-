#ifndef PROT_REG_H_
#define PROT_REG_H_

/* ============================================================================
   =============================== Module: REG_PROT ===========================
   ============================================================================ */

typedef union REG_PROT_SLBRn_union_tag { /* Soft Lock Bit Register n */
  vuint8_t R;
  struct {
    vuint8_t WE0:1;                    /* Write Enable Bits for Soft Lock Bits (SLB) */
    vuint8_t WE1:1;                    /* Write Enable Bits for Soft Lock Bits (SLB) */
    vuint8_t WE2:1;                    /* Write Enable Bits for Soft Lock Bits (SLB) */
    vuint8_t WE3:1;                    /* Write Enable Bits for Soft Lock Bits (SLB) */
    vuint8_t SLB0:1;                   /* Soft Lock Bits for one MRn register */
    vuint8_t SLB1:1;                   /* Soft Lock Bits for one MRn register */
    vuint8_t SLB2:1;                   /* Soft Lock Bits for one MRn register */
    vuint8_t SLB3:1;                   /* Soft Lock Bits for one MRn register */
  } B;
} REG_PROT_SLBRn_tag;

typedef union REG_PROT_GCR_union_tag { /* Global Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t HLB:1;                   /* Hard Lock Bit */
    vuint32_t  :7;
    vuint32_t UAA:1;                   /* User Access Allowed. */
    vuint32_t  :23;
  } B;
} REG_PROT_GCR_tag;

struct REG_PROT_tag {
  uint8_t REG_PROT_reserved0[14336];
  REG_PROT_SLBRn_tag SLBRn;            /* Soft Lock Bit Register n */
  uint8_t REG_PROT_reserved1[2043];
  REG_PROT_GCR_tag GCR;                /* Global Configuration Register */
};

#endif
