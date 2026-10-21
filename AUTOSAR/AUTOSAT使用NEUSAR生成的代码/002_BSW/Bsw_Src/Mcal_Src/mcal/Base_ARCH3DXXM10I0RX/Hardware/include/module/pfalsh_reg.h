#ifndef PFLASH_REG_H_
#define PFLASH_REG_H_

/* ============================================================================
   =============================== Module: PFLASH =============================
   ============================================================================ */

typedef union PFLASH_PFCR1_union_tag { /* Platform Flash Configuration Register 1 */
  vuint32_t R;
  struct {
    vuint32_t P0_M15PFE:1;
    vuint32_t P0_M14PFE:1;
    vuint32_t P0_M13PFE:1;
    vuint32_t P0_M12PFE:1;
    vuint32_t P0_M11PFE:1;
    vuint32_t P0_M10PFE:1;
    vuint32_t P0_M9PFE:1;
    vuint32_t P0_M8PFE:1;
    vuint32_t P0_M7PFE:1;
    vuint32_t P0_M6PFE:1;
    vuint32_t P0_M5PFE:1;
    vuint32_t P0_M4PFE:1;
    vuint32_t P0_M3PFE:1;
    vuint32_t P0_M2PFE:1;
    vuint32_t P0_M1PFE:1;
    vuint32_t P0_M0PFE:1;
    vuint32_t APC:3;
    vuint32_t RWSC:5;
    vuint32_t  :1;
    vuint32_t P0_DPFEN:1;
    vuint32_t  :1;
    vuint32_t P0_IPFEN:1;
    vuint32_t  :1;
    vuint32_t P0_PFLIM:2;
    vuint32_t P0_BFEN:1;
  } B;
} PFLASH_PFCR1_tag;

typedef union PFLASH_PFCR2_union_tag { /* Platform Flash Configuration Register 2 */
  vuint32_t R;
  struct {
    vuint32_t P1_M15PFE:1;
    vuint32_t P1_M14PFE:1;
    vuint32_t P1_M13PFE:1;
    vuint32_t P1_M12PFE:1;
    vuint32_t P1_M11PFE:1;
    vuint32_t P1_M10PFE:1;
    vuint32_t P1_M9PFE:1;
    vuint32_t P1_M8PFE:1;
    vuint32_t P1_M7PFE:1;
    vuint32_t P1_M6PFE:1;
    vuint32_t P1_M5PFE:1;
    vuint32_t P1_M4PFE:1;
    vuint32_t P1_M3PFE:1;
    vuint32_t P1_M2PFE:1;
    vuint32_t P1_M1PFE:1;
    vuint32_t P1_M0PFE:1;
    vuint32_t  :9;
    vuint32_t P1_DPFEN:1;
    vuint32_t  :1;
    vuint32_t P1_IPFEN:1;
    vuint32_t  :1;
    vuint32_t P1_PFLIM:2;
    vuint32_t P1_BFEN:1;
  } B;
} PFLASH_PFCR2_tag;

typedef union PFLASH_PFCR3_union_tag { /* Platform Flash Configuration Register 3 */
  vuint32_t R;
  struct {
    vuint32_t P0_WCFG:2;
    vuint32_t P1_WCFG:2;
    vuint32_t  :2;
    vuint32_t  :5;
    vuint32_t BDRM:1;
    vuint32_t  :3;
    vuint32_t BAF_DIS:1;
    vuint32_t ARBM:2;
    vuint32_t  :2;
    vuint32_t  :11;
    vuint32_t  :1;
  } B;
} PFLASH_PFCR3_tag;

typedef union PFLASH_PFAPR_union_tag { /* Platform Flash Access Protection Register */
  vuint32_t R;
  struct {
    vuint32_t M0AP:2;
    vuint32_t M1AP:2;
    vuint32_t M2AP:2;
    vuint32_t M3AP:2;
    vuint32_t M4AP:2;
    vuint32_t M5AP:2;
    vuint32_t M6AP:2;
    vuint32_t M7AP:2;
    vuint32_t M8AP:2;
    vuint32_t M9AP:2;
    vuint32_t M10AP:2;
    vuint32_t M11AP:2;
    vuint32_t M12AP:2;
    vuint32_t M13AP:2;
    vuint32_t M14AP:2;
    vuint32_t M15AP:2;
  } B;
} PFLASH_PFAPR_tag;

typedef union PFLASH_PFCRCR_union_tag { /* Platform Flash Remap Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :23;
    vuint32_t SAFE_CAL:1;
    vuint32_t  :3;
    vuint32_t IRMEN:1;
    vuint32_t  :3;
    vuint32_t GRMEN:1;
  } B;
} PFLASH_PFCRCR_tag;

typedef union PFLASH_PFCRDE_union_tag { /* Platform Flash Remap Descriptor Enable Register */
  vuint32_t R;
  struct {
    vuint32_t CRD0EN:1;
    vuint32_t CRD1EN:1;
    vuint32_t CRD2EN:1;
    vuint32_t CRD3EN:1;
    vuint32_t CRD4EN:1;
    vuint32_t CRD5EN:1;
    vuint32_t CRD6EN:1;
    vuint32_t CRD7EN:1;
    vuint32_t CRD8EN:1;
    vuint32_t CRD9EN:1;
    vuint32_t CRD10EN:1;
    vuint32_t CRD11EN:1;
    vuint32_t CRD12EN:1;
    vuint32_t CRD13EN:1;
    vuint32_t CRD14EN:1;
    vuint32_t CRD15EN:1;
    vuint32_t CRD16EN:1;
    vuint32_t CRD17EN:1;
    vuint32_t CRD18EN:1;
    vuint32_t CRD19EN:1;
    vuint32_t CRD20EN:1;
    vuint32_t CRD21EN:1;
    vuint32_t CRD22EN:1;
    vuint32_t CRD23EN:1;
    vuint32_t CRD24EN:1;
    vuint32_t CRD25EN:1;
    vuint32_t CRD26EN:1;
    vuint32_t CRD27EN:1;
    vuint32_t CRD28EN:1;
    vuint32_t CRD29EN:1;
    vuint32_t CRD30EN:1;
    vuint32_t CRD31EN:1;
  } B;
} PFLASH_PFCRDE_tag;

typedef union PFLASH_PFCRD_Word0_union_tag { /* Platform Flash Calibration Region Descriptor n Word0 */
  vuint32_t R;
  struct {
    vuint32_t LSTARTADDR:28;
    vuint32_t  :4;
  } B;
} PFLASH_PFCRD_Word0_tag;

typedef union PFLASH_PFCRD_Word1_union_tag { /* Platform Flash Calibration Region Descriptor n Word1 */
  vuint32_t R;
  struct {
    vuint32_t PSTARTADDR:28;
    vuint32_t  :4;
  } B;
} PFLASH_PFCRD_Word1_tag;

typedef union PFLASH_PFCRD_Word2_union_tag { /* Platform Flash Calibration Region Descriptor n Word2 */
  vuint32_t R;
  struct {
    vuint32_t M0EN:1;
    vuint32_t M1EN:1;
    vuint32_t M2EN:1;
    vuint32_t M3EN:1;
    vuint32_t M4EN:1;
    vuint32_t M5EN:1;
    vuint32_t M6EN:1;
    vuint32_t M7EN:1;
    vuint32_t M8EN:1;
    vuint32_t M9EN:1;
    vuint32_t M10EN:1;
    vuint32_t M11EN:1;
    vuint32_t M12EN:1;
    vuint32_t M13EN:1;
    vuint32_t M14EN:1;
    vuint32_t M15EN:1;
    vuint32_t  :11;
    vuint32_t CRDSize:5;
  } B;
} PFLASH_PFCRD_Word2_tag;

typedef struct PFLASH_PFCRD_struct_tag {
  PFLASH_PFCRD_Word0_tag Word0;        /* Platform Flash Calibration Region Descriptor n Word0 */
  PFLASH_PFCRD_Word1_tag Word1;        /* Platform Flash Calibration Region Descriptor n Word1 */
  PFLASH_PFCRD_Word2_tag Word2;        /* Platform Flash Calibration Region Descriptor n Word2 */
  uint8_t PFCRD_reserved0[4];
} PFLASH_PFCRD_tag;

struct PFLASH_tag {
  PFLASH_PFCR1_tag PFCR1;              /* Platform Flash Configuration Register 1 */
  PFLASH_PFCR2_tag PFCR2;              /* Platform Flash Configuration Register 2 */
  PFLASH_PFCR3_tag PFCR3;              /* Platform Flash Configuration Register 3 */
  PFLASH_PFAPR_tag PFAPR;              /* Platform Flash Access Protection Register */
  PFLASH_PFCRCR_tag PFCRCR;            /* Platform Flash Remap Control Register */
  PFLASH_PFCRDE_tag PFCRDE;            /* Platform Flash Remap Descriptor Enable Register */
  uint8_t PFLASH_reserved0[232];
  PFLASH_PFCRD_tag PFCRD[32];
};

#endif
