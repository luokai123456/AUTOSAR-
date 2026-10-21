#ifndef XBAR_REG_H_
#define XBAR_REG_H_

/* ============================================================================
   =============================== Module: XBAR ===============================
   ============================================================================ */

typedef union XBAR_PORT_PRS_union_tag { /* XBAR Priority Registers Slave */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t M7:3;
    vuint32_t  :1;
    vuint32_t M6:3;
    vuint32_t  :1;
    vuint32_t M5:3;
    vuint32_t  :1;
    vuint32_t M4:3;
    vuint32_t  :1;
    vuint32_t M3:3;
    vuint32_t  :1;
    vuint32_t M2:3;
    vuint32_t  :1;
    vuint32_t M1:3;
    vuint32_t  :1;
    vuint32_t M0:3;
  } B;
} XBAR_PORT_PRS_tag;

typedef union XBAR_PORT_CRS_union_tag { /* XBAR Control Register */
  vuint32_t R;
  struct {
    vuint32_t RO:1;
    vuint32_t HRP:1;
    vuint32_t  :6;
    vuint32_t HPE7:1;
    vuint32_t HPE6:1;
    vuint32_t HPE5:1;
    vuint32_t HPE4:1;
    vuint32_t HPE3:1;
    vuint32_t HPE2:1;
    vuint32_t HPE1:1;
    vuint32_t HPE0:1;
    vuint32_t  :6;
    vuint32_t ARB:2;
    vuint32_t  :2;
    vuint32_t PCTL:2;
    vuint32_t  :1;
    vuint32_t PARK:3;
  } B;
} XBAR_PORT_CRS_tag;

typedef struct XBAR_PORT_struct_tag {
  XBAR_PORT_PRS_tag PRS;               /* XBAR Priority Registers Slave */
  uint8_t PORT_reserved0[12];
  XBAR_PORT_CRS_tag CRS;               /* XBAR Control Register */
  uint8_t PORT_reserved1[236];
} XBAR_PORT_tag;

struct XBAR_tag {
  XBAR_PORT_tag PORT[8];
};

#endif
