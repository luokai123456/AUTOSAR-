#ifndef SMPU_REG_H_
#define SMPU_REG_H_

/* ============================================================================
   =============================== Module: SMPU ===============================
   ============================================================================ */

typedef union SMPU_CESR0_union_tag {   /* Control/Error Status Register 0 */
  vuint32_t R;
  struct {
    vuint32_t MERR:16;
    vuint32_t  :1;
    vuint32_t  :11;
    vuint32_t HRL:3;
    vuint32_t GVLD:1;
  } B;
} SMPU_CESR0_tag;

typedef union SMPU_CESR1_union_tag {   /* Control/Error Status Register 1 */
  vuint32_t R;
  struct {
    vuint32_t MEOVR:16;
    vuint32_t  :1;
    vuint32_t  :11;
    vuint32_t NRGD:4;
  } B;
} SMPU_CESR1_tag;

typedef union SMPU_ERROR_EAR_union_tag { /* Error Address Register, Bus Master n */
  vuint32_t R;
  struct {
    vuint32_t EADDR:32;
  } B;
} SMPU_ERROR_EAR_tag;

typedef union SMPU_ERROR_EDR_union_tag { /* Error Detail Register, Bus Master n */
  vuint32_t R;
  struct {
    vuint32_t EACD:24;
    vuint32_t  :1;
    vuint32_t EATTR:2;
    vuint32_t ERW:1;
    vuint32_t EMN:4;
  } B;
} SMPU_ERROR_EDR_tag;

typedef struct SMPU_ERROR_struct_tag {
  SMPU_ERROR_EAR_tag EAR;              /* Error Address Register, Bus Master n */
  SMPU_ERROR_EDR_tag EDR;              /* Error Detail Register, Bus Master n */
} SMPU_ERROR_tag;

typedef union SMPU_RGD_WORD0_union_tag { /* Region Descriptor n, Word 0 */
  vuint32_t R;
  struct {
    vuint32_t SRTADDR:32;
  } B;
} SMPU_RGD_WORD0_tag;

typedef union SMPU_RGD_WORD1_union_tag { /* Region Descriptor n, Word 1 */
  vuint32_t R;
  struct {
    vuint32_t ENDADDR:32;
  } B;
} SMPU_RGD_WORD1_tag;

typedef union SMPU_RGD_WORD2_union_tag { /* Region Descriptor n, Word 2 Format 0 */
  vuint32_t R;
  struct {
    vuint32_t M0P:2;
    vuint32_t M1P:2;
    vuint32_t M2P:2;
    vuint32_t M3P:2;
    vuint32_t M4P:2;
    vuint32_t M5P:2;
    vuint32_t M6P:2;
    vuint32_t M7P:2;
    vuint32_t M8P:2;
    vuint32_t M9P:2;
    vuint32_t M10P:2;
    vuint32_t M11P:2;
    vuint32_t M12P:2;
    vuint32_t M13P:2;
    vuint32_t M14P:2;
    vuint32_t M15P:2;
  } B;
} SMPU_RGD_WORD2_tag;

typedef union SMPU_RGD_WORD3_union_tag { /* Region Descriptor n, Word 3 */
  vuint32_t R;
  struct {
    vuint32_t  :27;
    vuint32_t FMT:1;
    vuint32_t RO:1;
    vuint32_t  :1;
    vuint32_t CI:1;
    vuint32_t VLD:1;
  } B;
} SMPU_RGD_WORD3_tag;

typedef struct SMPU_RGD_struct_tag {
  SMPU_RGD_WORD0_tag WORD0;            /* Region Descriptor n, Word 0 */
  SMPU_RGD_WORD1_tag WORD1;            /* Region Descriptor n, Word 1 */
  SMPU_RGD_WORD2_tag WORD2;            /* Region Descriptor n, Word 2 Format 0 */
  SMPU_RGD_WORD3_tag WORD3;            /* Region Descriptor n, Word 3 */
} SMPU_RGD_tag;

struct SMPU_tag {
  SMPU_CESR0_tag CESR0;                /* Control/Error Status Register 0 */
  SMPU_CESR1_tag CESR1;                /* Control/Error Status Register 1 */
  uint8_t SMPU_reserved0[248];
  SMPU_ERROR_tag ERROR_REG[16]; //wjc:ERROR[16];
  uint8_t SMPU_reserved1[640];
  SMPU_RGD_tag RGD[12];
};

typedef volatile struct SMPU_tag  SMPU_Type;

#endif  /* SMPU_REG_H_ */
