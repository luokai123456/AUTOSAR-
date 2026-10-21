#ifndef ACMP_REG_H
#define ACMP_REG_H
/* ============================================================================
   =============================== Module: ACMP ===============================
   ============================================================================ */

typedef union ACMP_CR_union_tag {      /* Control Register */
  vuint32_t R;
  struct {
    vuint32_t ORIG_FUNC:1;
    vuint32_t  :5;
    vuint32_t COM_HYS_TRIM_LV:2;
    vuint32_t VIP_SEL_LV:8;
    vuint32_t VIN_SEL_LV:8;
    vuint32_t  :1;
    vuint32_t ACMP_OUT_DIRECT:1;
    vuint32_t ACMP_FILTER_EN:1;
    vuint32_t ACMP_OUT_POL:1;
    vuint32_t ACMP_INTR_POL:1;
    vuint32_t EN_DAC_LV:1;
    vuint32_t EN_COMP_LV:1;
    vuint32_t LP_MODE_LV:1;
  } B;
} ACMP_CR_tag;

typedef union ACMP_SR_union_tag {      /* Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :25;
    vuint32_t SERVICE_REQ:1;
    vuint32_t OUT_LV_ORIGINAL:1;
    vuint32_t OUT_LV_FILTERED:1;
    vuint32_t ACMP_SETUP_VALID:1;
    vuint32_t OUT_LV_TOG:1;
    vuint32_t OUT_LV_NEG:1;
    vuint32_t OUT_LV_POS:1;
  } B;
} ACMP_SR_tag;

typedef union ACMP_IE_union_tag {      /* Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :25;
    vuint32_t SERVICE_REQ_IE:1;
    vuint32_t OUT_LV_ORIGINAL_IE:1;
    vuint32_t OUT_LV_FILTERED_IE:1;
    vuint32_t ACMP_SETUP_VALID_IE:1;
    vuint32_t OUT_LV_TOG_IE:1;
    vuint32_t OUT_LV_NEG_IE:1;
    vuint32_t OUT_LV_POS_IE:1;
  } B;
} ACMP_IE_tag;

typedef union ACMP_SETUP_union_tag {      /* Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t SETUP_CNT:16;
  } B;
} ACMP_SETUP_tag;

typedef union ACMP_FILTER_union_tag {      /* Control Register */
  vuint32_t R;
  struct {
    vuint32_t FILTER_CNT_H2L:16;
    vuint32_t FILTER_CNT_L2H:16;
  } B;
} ACMP_FILTER_tag;

typedef union ACMP_SOFTRST_union_tag {      /* Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t SOFT_RST:1;
  } B;
} ACMP_SOFTRST_tag;

typedef union ACMP_DAC_RAW_union_tag {      /* Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t DATA_LV:10;
  } B;
} ACMP_DAC_RAW_tag;

typedef union ACMP_FCFCCTRL_union_tag {      /* Control Register */
  vuint32_t R;
  struct {
    vuint32_t XTWC:1;
    vuint32_t FCCHNR:5;
    vuint32_t GTMODE:2;
    vuint32_t XTPOL:1;
    vuint32_t XTMODE:2;
    vuint32_t XTLVL:1;
    vuint32_t XTSEL:4;
    vuint32_t CPWC:1;
    vuint32_t DIVA:5;
    vuint32_t CHEVMODE:2;
    vuint32_t AIPF:2;
    vuint32_t STCF:6;
  } B;
} ACMP_FCFCCTRL_tag;

typedef union ACMP_FCFCM_union_tag {      /* Control Register */
  vuint32_t R;
  struct {
    vuint32_t FCREF:10;
    vuint32_t FCMWC:1;
    vuint32_t SSE:1;
    vuint32_t AUE:2;
    vuint32_t SRG:2;
    vuint32_t FCTRIV:8;
    vuint32_t ACSD:2;
    vuint32_t ANON:1;
    vuint32_t FCRDIR:1;
    vuint32_t RUNRAMP:2;
    vuint32_t RUNCOMP:2;
  } B;
} ACMP_FCFCM_tag;

typedef union ACMP_FCFCRAMP0_union_tag {      /* Control Register */
  vuint32_t R;
  struct {
    vuint32_t FSWC:1;
    vuint32_t  :7;
    vuint32_t FCRSTEP:8;
    vuint32_t :6;
    vuint32_t FCRCOMPA:10;
  } B;
} ACMP_FCFCRAMP0_tag;

typedef union ACMP_FCFCRAMP1_union_tag {      /* Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t FCRCOMPB:10;
  } B;
} ACMP_FCFCRAMP1_tag;

typedef union ACMP_FCFCHYST_union_tag {      /* Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :6;
    vuint32_t DELTAPLUS:10;
    vuint32_t  :6;
    vuint32_t DELTAMINUS:10;
  } B;
} ACMP_FCFCHYST_tag;

typedef union ACMP_FCFCBFL_union_tag {      /* Control Register */
  vuint32_t R;
  struct {
    vuint32_t VF:1;
    vuint32_t  :2;
    vuint32_t FCR:1;
    vuint32_t  :10;
    vuint32_t BFV:1;
    vuint32_t BFM:1;
    vuint32_t  :2;
    vuint32_t BFS:2;
    vuint32_t  :3;
    vuint32_t BFI:1;
    vuint32_t  :3;
    vuint32_t BFA:1;
    vuint32_t  :3;
    vuint32_t BFL:1;
  } B;
} ACMP_FCFCBFL_tag;


struct ACMP_tag {
  ACMP_CR_tag CR;                      /* Control Register */
  ACMP_SR_tag SR;                      /* Error Status */
  ACMP_IE_tag IE;                  /* Enable Request Register High */
  ACMP_SETUP_tag SETUP;                  /* Enable Request Register Low */
  ACMP_FILTER_tag FILTER;                  /* Enable Error Interrupt Register High */
  ACMP_SOFTRST_tag SOFTRST;                  /* Enable Error Interrupt Register Low */
  ACMP_DAC_RAW_tag DAC_RAW;
  uint8_t ACMP_reserved0[4];
  ACMP_FCFCCTRL_tag FCFCCTRL;
  ACMP_FCFCM_tag FCFCM;
  ACMP_FCFCRAMP0_tag FCFCRAMP0;
  ACMP_FCFCRAMP1_tag FCFCRAMP1;
  ACMP_FCFCHYST_tag FCFCHYST;
  ACMP_FCFCBFL_tag FCFCBFL;

};

#endif /*ACMP_REG_H*/
