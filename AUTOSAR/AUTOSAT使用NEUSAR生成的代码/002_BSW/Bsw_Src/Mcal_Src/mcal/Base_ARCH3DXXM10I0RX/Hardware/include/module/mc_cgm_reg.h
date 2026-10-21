#ifndef MC_CGM_REG_H_
#define MC_CGM_REG_H_

/* ============================================================================
   =============================== Module: MC_CGM =============================
   ============================================================================ */

typedef union MC_CGM_AC5_CDC0_union_tag { /* Auxiliary Clock 5 Cascaded Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_CDC0_tag;

typedef union MC_CGM_AC5_CDC1_union_tag { /* Auxiliary Clock 5 Cascaded Divider 1 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_CDC1_tag;

typedef union MC_CGM_AC5_CDC2_union_tag { /* Auxiliary Clock 5 Cascaded Divider 2 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_CDC2_tag;

typedef union MC_CGM_AC5_CDC10_union_tag { /* Auxiliary Clock 5 Cascaded Divider 10 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_CDC10_tag;

typedef union MC_CGM_AC5_CDC11_union_tag { /* Auxiliary Clock 5 Cascaded Divider 11 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_CDC11_tag;

typedef union MC_CGM_AC5_CDC12_union_tag { /* Auxiliary Clock 5 Cascaded Divider 12 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_CDC12_tag;

typedef union MC_CGM_AC5_CDC13_union_tag { /* Auxiliary Clock 5 Cascaded Divider 13 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_CDC13_tag;

typedef union MC_CGM_AC5_CDC20_union_tag { /* Auxiliary Clock 5 Cascaded Divider 20 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_CDC20_tag;

typedef union MC_CGM_AC5_CDC21_union_tag { /* Auxiliary Clock 5 Cascaded Divider 21 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_CDC21_tag;

typedef union MC_CGM_AC5_CDC22_union_tag { /* Auxiliary Clock 5 Cascaded Divider 22 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_CDC22_tag;

typedef union MC_CGM_AC5_CDC23_union_tag { /* Auxiliary Clock 5 Cascaded Divider 23 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_CDC23_tag;

typedef union MC_CGM_PCS_SDUR_union_tag { /* PCS Switch Duration Register */
  vuint8_t R;
  struct {
    vuint8_t SDUR:8;
  } B;
} MC_CGM_PCS_SDUR_tag;

typedef union MC_CGM_PCS_DIVC1_union_tag { /* PCS Divider Change Register 1 */
  vuint32_t R;
  struct {
    vuint32_t INIT:16;
    vuint32_t  :8;
    vuint32_t RATE:8;
  } B;
} MC_CGM_PCS_DIVC1_tag;

typedef union MC_CGM_PCS_DIVE1_union_tag { /* PCS Divider End Register 1 */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t DIVE:20;
  } B;
} MC_CGM_PCS_DIVE1_tag;

typedef union MC_CGM_PCS_DIVS1_union_tag { /* PCS Divider Start Register 1 */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t DIVS:20;
  } B;
} MC_CGM_PCS_DIVS1_tag;

typedef union MC_CGM_PCS_DIVC2_union_tag { /* PCS Divider Change Register 2 */
  vuint32_t R;
  struct {
    vuint32_t INIT:16;
    vuint32_t  :8;
    vuint32_t RATE:8;
  } B;
} MC_CGM_PCS_DIVC2_tag;

typedef union MC_CGM_PCS_DIVE2_union_tag { /* PCS Divider End Register 2 */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t DIVE:20;
  } B;
} MC_CGM_PCS_DIVE2_tag;

typedef union MC_CGM_PCS_DIVS2_union_tag { /* PCS Divider Start Register 2 */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t DIVS:20;
  } B;
} MC_CGM_PCS_DIVS2_tag;

typedef union MC_CGM_PCS_DIVC4_union_tag { /* PCS Divider Change Register 4 */
  vuint32_t R;
  struct {
    vuint32_t INIT:16;
    vuint32_t  :8;
    vuint32_t RATE:8;
  } B;
} MC_CGM_PCS_DIVC4_tag;

typedef union MC_CGM_PCS_DIVE4_union_tag { /* PCS Divider End Register 4 */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t DIVE:20;
  } B;
} MC_CGM_PCS_DIVE4_tag;

typedef union MC_CGM_PCS_DIVS4_union_tag { /* PCS Divider Start Register 4 */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t DIVS:20;
  } B;
} MC_CGM_PCS_DIVS4_tag;

typedef union MC_CGM_SC_DIV_RC_union_tag { /* System Clock Divider Ratio Change Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t SYS_DIV_RATIO_CHNG:1;
  } B;
} MC_CGM_SC_DIV_RC_tag;

typedef union MC_CGM_DIV_UPD_TYPE_union_tag { /* Divider Update Type Register */
  vuint32_t R;
  struct {
    vuint32_t SYS_UPD_TYPE:1;
    vuint32_t  :31;
  } B;
} MC_CGM_DIV_UPD_TYPE_tag;

typedef union MC_CGM_DIV_UPD_TRIG_union_tag { /* Divider Update Trigger Register */
  vuint32_t R;
  struct {
    vuint32_t DIV_UPD_TRIGGER:32;
  } B;
} MC_CGM_DIV_UPD_TRIG_tag;

typedef union MC_CGM_DIV_UPD_STAT_union_tag { /* Divider Update Status Register */
  vuint32_t R;
  struct {
    vuint32_t SYS_UPD_STAT:1;
    vuint32_t  :31;
  } B;
} MC_CGM_DIV_UPD_STAT_tag;

typedef union MC_CGM_SC_SS_union_tag { /* System Clock Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :4;
    vuint32_t SWTRG:3;
    vuint32_t SWIP:1;
    vuint32_t  :16;
  } B;
} MC_CGM_SC_SS_tag;

typedef union MC_CGM_SC_DC0_union_tag { /* System Clock Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :9;
    vuint32_t DIV:6;
    vuint32_t  :16;
  } B;
} MC_CGM_SC_DC0_tag;

typedef union MC_CGM_SC_DC1_union_tag { /* System Clock Divider 1 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :9;
    vuint32_t DIV:6;
    vuint32_t  :16;
  } B;
} MC_CGM_SC_DC1_tag;

typedef union MC_CGM_SC_DC2_union_tag { /* System Clock Divider 2 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :9;
    vuint32_t DIV:6;
    vuint32_t  :16;
  } B;
} MC_CGM_SC_DC2_tag;

typedef union MC_CGM_SC_DC3_union_tag { /* System Clock Divider 3 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :9;
    vuint32_t DIV:6;
    vuint32_t  :16;
  } B;
} MC_CGM_SC_DC3_tag;

typedef union MC_CGM_SC_DC4_union_tag { /* System Clock Divider 4 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :9;
    vuint32_t DIV:6;
    vuint32_t  :16;
  } B;
} MC_CGM_SC_DC4_tag;

typedef union MC_CGM_AC0_SC_union_tag { /* Auxiliary Clock 0 Select Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELCTL:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC0_SC_tag;

typedef union MC_CGM_AC0_SS_union_tag { /* Auxiliary Clock 0 Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC0_SS_tag;

typedef union MC_CGM_AC0_DC0_union_tag { /* Auxiliary Clock 0 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :11;
    vuint32_t DIV:4;
    vuint32_t  :16;
  } B;
} MC_CGM_AC0_DC0_tag;

typedef union MC_CGM_AC0_DC1_union_tag { /* Auxiliary Clock 0 Divider 1 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :8;
    vuint32_t DIV:7;
    vuint32_t  :16;
  } B;
} MC_CGM_AC0_DC1_tag;

typedef union MC_CGM_AC0_DC2_union_tag { /* Auxiliary Clock 0 Divider 2 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :8;
    vuint32_t DIV:7;
    vuint32_t  :16;
  } B;
} MC_CGM_AC0_DC2_tag;

typedef union MC_CGM_AC0_DC3_union_tag { /* Auxiliary Clock 0 Divider 3 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :6;
    vuint32_t DIV:9;
    vuint32_t  :14;
    vuint32_t DIV_FMT:2;
  } B;
} MC_CGM_AC0_DC3_tag;

typedef union MC_CGM_AC0_DC4_union_tag { /* Auxiliary Clock 0 Divider 4 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :11;
    vuint32_t DIV:4;
    vuint32_t  :16;
  } B;
} MC_CGM_AC0_DC4_tag;

typedef union MC_CGM_AC1_SC_union_tag { /* Auxiliary Clock 1 Select Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELCTL:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC1_SC_tag;

typedef union MC_CGM_AC1_SS_union_tag { /* Auxiliary Clock 1 Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC1_SS_tag;

typedef union MC_CGM_AC1_DC0_union_tag { /* Auxiliary Clock 1 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :8;
    vuint32_t DIV:7;
    vuint32_t  :16;
  } B;
} MC_CGM_AC1_DC0_tag;

typedef union MC_CGM_AC2_DC0_union_tag { /* Auxiliary Clock 2 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :9;
    vuint32_t DIV:6;
    vuint32_t  :16;
  } B;
} MC_CGM_AC2_DC0_tag;

typedef union MC_CGM_AC2_DC1_union_tag { /* Auxiliary Clock 2 Divider 1 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :9;
    vuint32_t DIV:6;
    vuint32_t  :16;
  } B;
} MC_CGM_AC2_DC1_tag;

typedef union MC_CGM_AC2_DC2_union_tag { /* Auxiliary Clock 2 Divider 2 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :9;
    vuint32_t DIV:6;
    vuint32_t  :16;
  } B;
} MC_CGM_AC2_DC2_tag;

typedef union MC_CGM_AC3_SC_union_tag { /* Auxiliary Clock 3 Select Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELCTL:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC3_SC_tag;

typedef union MC_CGM_AC3_SS_union_tag { /* Auxiliary Clock 3 Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC3_SS_tag;

typedef union MC_CGM_AC4_SC_union_tag { /* Auxiliary Clock 4 Select Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELCTL:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC4_SC_tag;

typedef union MC_CGM_AC4_SS_union_tag { /* Auxiliary Clock 4 Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC4_SS_tag;

typedef union MC_CGM_AC5_DC0_union_tag { /* Auxiliary Clock 5 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :2;
    vuint32_t DIV:13;
    vuint32_t  :14;
    vuint32_t DIV_FMT:2;
  } B;
} MC_CGM_AC5_DC0_tag;

typedef union MC_CGM_AC5_DC1_union_tag { /* Auxiliary Clock 5 Divider 1 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :7;
    vuint32_t DIV:8;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_DC1_tag;

typedef union MC_CGM_AC5_DC2_union_tag { /* Auxiliary Clock 5 Divider 2 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_DC2_tag;

typedef union MC_CGM_AC6_SC_union_tag { /* Auxiliary Clock 6 Select Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELCTL:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC6_SC_tag;

typedef union MC_CGM_AC6_SS_union_tag { /* Auxiliary Clock 6 Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC6_SS_tag;

typedef union MC_CGM_AC6_DC0_union_tag { /* Auxiliary Clock 6 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :6;
    vuint32_t DIV:9;
    vuint32_t  :16;
  } B;
} MC_CGM_AC6_DC0_tag;

typedef union MC_CGM_AC7_SC_union_tag { /* Auxiliary Clock 7 Select Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELCTL:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC7_SC_tag;

typedef union MC_CGM_AC7_SS_union_tag { /* Auxiliary Clock 7 Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC7_SS_tag;

typedef union MC_CGM_AC7_DC0_union_tag { /* Auxiliary Clock 7 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :6;
    vuint32_t DIV:9;
    vuint32_t  :16;
  } B;
} MC_CGM_AC7_DC0_tag;

typedef union MC_CGM_AC8_SC_union_tag { /* Auxiliary Clock 8 Select Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELCTL:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC8_SC_tag;

typedef union MC_CGM_AC8_SS_union_tag { /* Auxiliary Clock 8 Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC8_SS_tag;

typedef union MC_CGM_AC8_DC0_union_tag { /* Auxiliary Clock 8 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :9;
    vuint32_t DIV:6;
    vuint32_t  :16;
  } B;
} MC_CGM_AC8_DC0_tag;

typedef union MC_CGM_AC9_SC_union_tag { /* Auxiliary Clock 9 Select Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELCTL:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC9_SC_tag;

typedef union MC_CGM_AC9_SS_union_tag { /* Auxiliary Clock 9 Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC9_SS_tag;

typedef union MC_CGM_AC9_DC0_union_tag { /* Auxiliary Clock 9 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :9;
    vuint32_t DIV:6;
    vuint32_t  :16;
  } B;
} MC_CGM_AC9_DC0_tag;

typedef union MC_CGM_AC10_SC_union_tag { /* Auxiliary Clock 10 Select Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELCTL:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC10_SC_tag;

typedef union MC_CGM_AC10_SS_union_tag { /* Auxiliary Clock 10 Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC10_SS_tag;

typedef union MC_CGM_AC10_DC0_union_tag { /* Auxiliary Clock 10 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :11;
    vuint32_t DIV:4;
    vuint32_t  :16;
  } B;
} MC_CGM_AC10_DC0_tag;

#if defined(CCFC3008PT)
/* CCFC3008PT unsupported. */
#else
typedef union MC_CGM_AC11_SC_union_tag { /* Auxiliary Clock 11 Select Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELCTL:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC11_SC_tag;

typedef union MC_CGM_AC11_SS_union_tag { /* Auxiliary Clock 11 Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC11_SS_tag;

typedef union MC_CGM_AC11_DC0_union_tag { /* Auxiliary Clock 11 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :11;
    vuint32_t DIV:4;
    vuint32_t  :16;
  } B;
} MC_CGM_AC11_DC0_tag;

typedef union MC_CGM_AC12_SC_union_tag { /* Auxiliary Clock 11 Select Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELCTL:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC12_SC_tag;

typedef union MC_CGM_AC12_SS_union_tag { /* Auxiliary Clock 11 Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC12_SS_tag;

typedef union MC_CGM_AC12_DC0_union_tag { /* Auxiliary Clock 11 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :2;
    vuint32_t DIV:13;
    vuint32_t  :16;
  } B;
} MC_CGM_AC12_DC0_tag;

typedef union MC_CGM_AC12_DC1_union_tag { /* Auxiliary Clock 11 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :2;
    vuint32_t DIV:13;
    vuint32_t  :16;
  } B;
} MC_CGM_AC12_DC1_tag;

typedef union MC_CGM_AC12_DC2_union_tag { /* Auxiliary Clock 11 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :2;
    vuint32_t DIV:13;
    vuint32_t  :16;
  } B;
} MC_CGM_AC12_DC2_tag;
#endif

struct MC_CGM_tag {
  uint8_t MC_CGM_reserved0[1664];
  MC_CGM_AC5_CDC0_tag AC5_CDC0;        /* Auxiliary Clock 5 Cascaded Divider 0 Configuration Register */
  MC_CGM_AC5_CDC1_tag AC5_CDC1;        /* Auxiliary Clock 5 Cascaded Divider 1 Configuration Register */
  MC_CGM_AC5_CDC2_tag AC5_CDC2;        /* Auxiliary Clock 5 Cascaded Divider 2 Configuration Register */
  uint8_t MC_CGM_reserved1[4];
  MC_CGM_AC5_CDC10_tag AC5_CDC10;      /* Auxiliary Clock 5 Cascaded Divider 10 Configuration Register */
  MC_CGM_AC5_CDC11_tag AC5_CDC11;      /* Auxiliary Clock 5 Cascaded Divider 11 Configuration Register */
  MC_CGM_AC5_CDC12_tag AC5_CDC12;      /* Auxiliary Clock 5 Cascaded Divider 12 Configuration Register */
  MC_CGM_AC5_CDC13_tag AC5_CDC13;      /* Auxiliary Clock 5 Cascaded Divider 13 Configuration Register */
  MC_CGM_AC5_CDC20_tag AC5_CDC20;      /* Auxiliary Clock 5 Cascaded Divider 20 Configuration Register */
  MC_CGM_AC5_CDC21_tag AC5_CDC21;      /* Auxiliary Clock 5 Cascaded Divider 21 Configuration Register */
  MC_CGM_AC5_CDC22_tag AC5_CDC22;      /* Auxiliary Clock 5 Cascaded Divider 22 Configuration Register */
  MC_CGM_AC5_CDC23_tag AC5_CDC23;      /* Auxiliary Clock 5 Cascaded Divider 23 Configuration Register */
  uint8_t MC_CGM_reserved2[80];
  MC_CGM_PCS_SDUR_tag PCS_SDUR;        /* PCS Switch Duration Register */
  uint8_t MC_CGM_reserved3[3];
  MC_CGM_PCS_DIVC1_tag PCS_DIVC1;      /* PCS Divider Change Register 1 */
  MC_CGM_PCS_DIVE1_tag PCS_DIVE1;      /* PCS Divider End Register 1 */
  MC_CGM_PCS_DIVS1_tag PCS_DIVS1;      /* PCS Divider Start Register 1 */
  MC_CGM_PCS_DIVC2_tag PCS_DIVC2;      /* PCS Divider Change Register 2 */
  MC_CGM_PCS_DIVE2_tag PCS_DIVE2;      /* PCS Divider End Register 2 */
  MC_CGM_PCS_DIVS2_tag PCS_DIVS2;      /* PCS Divider Start Register 2 */
  uint8_t MC_CGM_reserved4[12];
  MC_CGM_PCS_DIVC4_tag PCS_DIVC4;      /* PCS Divider Change Register 4 */
  MC_CGM_PCS_DIVE4_tag PCS_DIVE4;      /* PCS Divider End Register 4 */
  MC_CGM_PCS_DIVS4_tag PCS_DIVS4;      /* PCS Divider Start Register 4 */
  uint8_t MC_CGM_reserved5[156];
  MC_CGM_SC_DIV_RC_tag SC_DIV_RC;      /* System Clock Divider Ratio Change Register */
  MC_CGM_DIV_UPD_TYPE_tag DIV_UPD_TYPE; /* Divider Update Type Register */
  MC_CGM_DIV_UPD_TRIG_tag DIV_UPD_TRIG; /* Divider Update Trigger Register */
  MC_CGM_DIV_UPD_STAT_tag DIV_UPD_STAT; /* Divider Update Status Register */
  uint8_t MC_CGM_reserved6[4];
  MC_CGM_SC_SS_tag SC_SS;              /* System Clock Select Status Register */
  MC_CGM_SC_DC0_tag SC_DC0;            /* System Clock Divider 0 Configuration Register */
  MC_CGM_SC_DC1_tag SC_DC1;            /* System Clock Divider 1 Configuration Register */
  MC_CGM_SC_DC2_tag SC_DC2;            /* System Clock Divider 2 Configuration Register */
  MC_CGM_SC_DC3_tag SC_DC3;            /* System Clock Divider 3 Configuration Register */
  MC_CGM_SC_DC4_tag SC_DC4;            /* System Clock Divider 4 Configuration Register */
  uint8_t MC_CGM_reserved7[4];
  MC_CGM_AC0_SC_tag AC0_SC;            /* Auxiliary Clock 0 Select Control Register */
  MC_CGM_AC0_SS_tag AC0_SS;            /* Auxiliary Clock 0 Select Status Register */
  MC_CGM_AC0_DC0_tag AC0_DC0;          /* Auxiliary Clock 0 Divider 0 Configuration Register */
  MC_CGM_AC0_DC1_tag AC0_DC1;          /* Auxiliary Clock 0 Divider 1 Configuration Register */
  MC_CGM_AC0_DC2_tag AC0_DC2;          /* Auxiliary Clock 0 Divider 2 Configuration Register */
  MC_CGM_AC0_DC3_tag AC0_DC3;          /* Auxiliary Clock 0 Divider 3 Configuration Register */
  MC_CGM_AC0_DC4_tag AC0_DC4;          /* Auxiliary Clock 0 Divider 4 Configuration Register */
  uint8_t MC_CGM_reserved8[4];
  MC_CGM_AC1_SC_tag AC1_SC;            /* Auxiliary Clock 1 Select Control Register */
  MC_CGM_AC1_SS_tag AC1_SS;            /* Auxiliary Clock 1 Select Status Register */
  MC_CGM_AC1_DC0_tag AC1_DC0;          /* Auxiliary Clock 1 Divider 0 Configuration Register */
  uint8_t MC_CGM_reserved9[28];
  MC_CGM_AC2_DC0_tag AC2_DC0;          /* Auxiliary Clock 2 Divider 0 Configuration Register */
  MC_CGM_AC2_DC1_tag AC2_DC1;          /* Auxiliary Clock 2 Divider 1 Configuration Register */
  MC_CGM_AC2_DC2_tag AC2_DC2;          /* Auxiliary Clock 2 Divider 2 Configuration Register */
  uint8_t MC_CGM_reserved10[12];
  MC_CGM_AC3_SC_tag AC3_SC;            /* Auxiliary Clock 3 Select Control Register */
  MC_CGM_AC3_SS_tag AC3_SS;            /* Auxiliary Clock 3 Select Status Register */
  uint8_t MC_CGM_reserved11[24];
  MC_CGM_AC4_SC_tag AC4_SC;            /* Auxiliary Clock 4 Select Control Register */
  MC_CGM_AC4_SS_tag AC4_SS;            /* Auxiliary Clock 4 Select Status Register */
  uint8_t MC_CGM_reserved12[32];
  MC_CGM_AC5_DC0_tag AC5_DC0;          /* Auxiliary Clock 5 Divider 0 Configuration Register */
  MC_CGM_AC5_DC1_tag AC5_DC1;          /* Auxiliary Clock 5 Divider 1 Configuration Register */
  MC_CGM_AC5_DC2_tag AC5_DC2;          /* Auxiliary Clock 5 Divider 2 Configuration Register */
  uint8_t MC_CGM_reserved13[12];
  MC_CGM_AC6_SC_tag AC6_SC;            /* Auxiliary Clock 6 Select Control Register */
  MC_CGM_AC6_SS_tag AC6_SS;            /* Auxiliary Clock 6 Select Status Register */
  MC_CGM_AC6_DC0_tag AC6_DC0;          /* Auxiliary Clock 6 Divider 0 Configuration Register */
  uint8_t MC_CGM_reserved14[20];
  MC_CGM_AC7_SC_tag AC7_SC;            /* Auxiliary Clock 7 Select Control Register */
  MC_CGM_AC7_SS_tag AC7_SS;            /* Auxiliary Clock 7 Select Status Register */
  MC_CGM_AC7_DC0_tag AC7_DC0;          /* Auxiliary Clock 7 Divider 0 Configuration Register */
  uint8_t MC_CGM_reserved15[20];
  MC_CGM_AC8_SC_tag AC8_SC;            /* Auxiliary Clock 8 Select Control Register */
  MC_CGM_AC8_SS_tag AC8_SS;            /* Auxiliary Clock 8 Select Status Register */
  MC_CGM_AC8_DC0_tag AC8_DC0;          /* Auxiliary Clock 8 Divider 0 Configuration Register */
  uint8_t MC_CGM_reserved16[20];
  MC_CGM_AC9_SC_tag AC9_SC;            /* Auxiliary Clock 9 Select Control Register */
  MC_CGM_AC9_SS_tag AC9_SS;            /* Auxiliary Clock 9 Select Status Register */
  MC_CGM_AC9_DC0_tag AC9_DC0;          /* Auxiliary Clock 9 Divider 0 Configuration Register */
  uint8_t MC_CGM_reserved17[20];
  MC_CGM_AC10_SC_tag AC10_SC;          /* Auxiliary Clock 10 Select Control Register */
  MC_CGM_AC10_SS_tag AC10_SS;          /* Auxiliary Clock 10 Select Status Register */
  MC_CGM_AC10_DC0_tag AC10_DC0;        /* Auxiliary Clock 10 Divider 0 Configuration Register */
#if defined(CCFC3008PT)
/* CCFC3008PT unsupported. */
#else
  uint8_t MC_CGM_reserved18[20];
  MC_CGM_AC11_SC_tag AC11_SC;          /* Auxiliary Clock 11 Select Control Register */
  MC_CGM_AC11_SS_tag AC11_SS;          /* Auxiliary Clock 11 Select Status Register */
  MC_CGM_AC11_DC0_tag AC11_DC0;        /* Auxiliary Clock 11 Divider 0 Configuration Register */
  uint8_t MC_CGM_reserved19[20];
  MC_CGM_AC12_SC_tag AC12_SC;          /* Auxiliary Clock 12 Select Control Register */
  MC_CGM_AC12_SS_tag AC12_SS;          /* Auxiliary Clock 12 Select Status Register */
  MC_CGM_AC12_DC0_tag AC12_DC0;        /* Auxiliary Clock 12 Divider 0 Configuration Register */
  MC_CGM_AC12_DC1_tag AC12_DC1;        /* Auxiliary Clock 12 Divider 1 Configuration Register */
  MC_CGM_AC12_DC2_tag AC12_DC2;        /* Auxiliary Clock 12 Divider 2 Configuration Register */
#endif
};



/*******************************************************************************
 * MC_CGM Register Bit Fields
 *******************************************************************************/
#define MC_CGM_AC0_DC1_DE_MASK               0x80000000u

#endif  /* MC_CGM_REG_H_ */
