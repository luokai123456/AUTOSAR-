#ifndef PMCDIG_REG_H_
#define PMCDIG_REG_H_

/* ============================================================================
   =============================== Module: PMCDIG =============================
   ============================================================================ */

typedef union PMCDIG_GR_S_union_tag {  /* Supply Gauge Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :5;                     /* Reserved. */
    vuint32_t TS3:1;                   /* TS3 over temperature detect flag. */
    vuint32_t TS2:1;                   /* TS2 over temperature detect flag. */
    vuint32_t TS0:1;                   /* TS0 under temperature detect flag. */
    vuint32_t  :8;
    vuint32_t VD15:1;                  /* VD15 high-voltage detect flag. */
    vuint32_t VD14:1;                  /* VD14 low-voltage detect flag. */
    vuint32_t VD13:1;                  /* VD13 low-voltage detect flag. */
    vuint32_t VD12:1;                  /* VD12 high-voltage detect flag. */
    vuint32_t  :1;
    vuint32_t VD10:1;                  /* HVD occurrence detected on the high voltage 3.60 V supply. */
    vuint32_t VD9:1;                   /* VD9 low-voltage detect flag. */
    vuint32_t VD8:1;                   /* VD8 high-voltage detect flag. */
    vuint32_t VD7:1;                   /* VD7 high-voltage detect flag. */
    vuint32_t  :2;
    vuint32_t VD4:1;                   /* VD4 low-voltage detect flag. */
    vuint32_t VD3:1;                   /* VD3 low-voltage detect flag. */
    vuint32_t  :3;                     /* Reserved */
  } B;
} PMCDIG_GR_S_tag;

typedef union PMCDIG_GR_P_union_tag {  /* Pending Gauge Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :6;
    vuint32_t VD15_A:1;                /* VD15_A high-voltage detect flag. */
    vuint32_t VD15_C:1;                /* VD15_C high-voltage detect flag. */
    vuint32_t  :1;
    vuint32_t VD14_A:1;                /* VD14_A low-voltage detect flag. */
    vuint32_t VD14_IM:1;               /* VD14_IM low-voltage detect flag. */
    vuint32_t  :2;
    vuint32_t VD13_IM:1;               /* VD13_IM low-voltage detect flag. */
    vuint32_t VD12_F:1;                /* VD12_F high-voltage detect flag. */
    vuint32_t VD10_A:1;                /* VD10_A low-voltage detect flag. */
    vuint32_t VD10_F:1;                /* VD10_F low-voltage detect flag. */
    vuint32_t VD9_O:1;                 /* VD9_O low-voltage detect flag. */
    vuint32_t VD9_O_H:1;               /* VD9_IF2 low-voltage detect flag. */
    vuint32_t VD9_IO5V_H:1;            /* VD9_IF low-voltage detect flag. */
    vuint32_t VD9_IO5V:1;              /* VD9_IJ low-voltage detect flag. */
    vuint32_t :2;
    vuint32_t VD9_PMC_H:1;             /* VD9_EBI low-voltage detect flag. */
    vuint32_t VD9_PMC:1;               /* VD9_C low-voltage detect flag. */
    vuint32_t VD8_C:1;                 /* VD8_C high-voltage detect flag. */
    vuint32_t VD8_F:1;                 /* VD8_F high-voltage detect flag. */
    vuint32_t VD7_C:1;                 /* VD7_C high-voltage detect flag. */
    vuint32_t VD4_C:1;                 /* VD4_C low-voltage detect flag. */
    vuint32_t VD3_P:1;                 /* VD3_P low-voltage detect flag. */
    vuint32_t VD3_F:1;                 /* VD3_F low-voltage detect flag. */
    vuint32_t :1;
  } B;
} PMCDIG_GR_P_tag;

typedef union PMCDIG_IE_P_union_tag {  /* Interrupt Enable Pending Register */
  vuint32_t R;
  struct {
    vuint32_t IE_EN:1;
    vuint32_t  :5;
    vuint32_t VD15IE_A:1;              /* VD15IE_A Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
    vuint32_t VD15IE_C:1;              /* VD15IE_C Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
    vuint32_t  :1;
    vuint32_t VD14IE_A:1;              /* VD14IE_A Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
    vuint32_t VD14IE_IM:1;             /* VD14IE_IM Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
    vuint32_t  :2;
    vuint32_t VD13IE_IM:1;             /* VD13IE_IM Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
    vuint32_t VD12IE_F:1;              /* VD12IE_F Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
    vuint32_t VD10IE_A:1;              /* VD10IE_F Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
    vuint32_t VD10IE_F:1;              /* VD10IE_A Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
    vuint32_t VD9IE_O:1;               /* VD9IE_O Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
    vuint32_t VD9IE_O_H:1;             /* VD9IE_IF2 Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
    vuint32_t VD9IE_IO5V_H:1;              /* VD9IE_IF Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
    vuint32_t VD9IE_IO5V:1;              /* VD9IE_IJ Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
    vuint32_t :1;              /* VD9IE_IM Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
    vuint32_t :1;               /* VD9IE_F Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
    vuint32_t VD9IE_PMC_H:1;             /* VD9IE_EBI Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
    vuint32_t VD9IE_PMC:1;               /* VD9IE_C Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
    vuint32_t VD8IE_C:1;               /* VD8IE_C Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
    vuint32_t VD8IE_F:1;               /* VD8IE_F Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
    vuint32_t VD7IE_C:1;               /* VD7IE_C Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
    vuint32_t VD4IE_C:1;               /* VD4IE_C Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
    vuint32_t VD3IE_P:1;               /* VD3IE_P Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
    vuint32_t VD3IE_F:1;               /* VD3IE_F Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
    vuint32_t :1;               /* VD3IE_C Interrupt Enable. This bit determines whether an interrupt is seen by the system when the voltage detect event occurs. */
  } B;
} PMCDIG_IE_P_tag;

typedef union PMCDIG_EPR_VD3_union_tag { /* Event Pending Register */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t HVD3_P:1;                /* LVD3_P flag. */
    vuint32_t LVD3_F:1;                /* LVD3_F flag. */
    vuint32_t  :5;
    vuint32_t LVD3_C:1;                /* LVD3_C flag. */
  } B;
} PMCDIG_EPR_VD3_tag;

typedef union PMCDIG_REE_VD3_union_tag { /* Reset Event Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t HVD3_P:1;                /* LVD3_P reset enable. */
    vuint32_t LVD3_F:1;                /* LVD3_F reset enable. */
    vuint32_t  :5;
    vuint32_t LVD3_C:1;                /* LVD3_C reset enable. */
  } B;
} PMCDIG_REE_VD3_tag;

typedef union PMCDIG_RES_VD3_union_tag { /* Reset Event Select Register */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t HVD3_P:1;                /* LVD3_P reset event select. */
    vuint32_t LVD3_F:1;                /* LVD3_F reset event select. */
    vuint32_t  :5;
    vuint32_t LVD3_C:1;                /* LVD3_C reset event select. */
  } B;
} PMCDIG_RES_VD3_tag;

typedef union PMCDIG_FEE_VD3_union_tag { /* FCCU Event Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t FEE3_P:1;                /* FEE3_P FCCU event enable. */
    vuint32_t FEE3_F:1;                /* FEE3_F FCCU event enable. */
    vuint32_t  :5;
    vuint32_t FEE3_C:1;                /* FEE3_C FCCU event enable. */
  } B;
} PMCDIG_FEE_VD3_tag;

typedef union PMCDIG_EPR_VD4_union_tag { /* LVD108 Event Pending Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t LVD4_C:1;                /* LVD4_C flag. */
  } B;
} PMCDIG_EPR_VD4_tag;

typedef union PMCDIG_REE_VD4_union_tag { /* Reset Event Select Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t LVD4_C:1;                /* LVD4_C reset enable. */
  } B;
} PMCDIG_REE_VD4_tag;

typedef union PMCDIG_RES_VD4_union_tag { /* Reset Event Select Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t LVD4_C:1;                /* LVD4_H reset event select. */
  } B;
} PMCDIG_RES_VD4_tag;

typedef union PMCDIG_FEE_VD4_union_tag { /* FCCU Event Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t FEE4_C:1;                /* FEE4_C FCCU event enable. */
  } B;
} PMCDIG_FEE_VD4_tag;

typedef union PMCDIG_EPR_VD7_union_tag { /* Event Pending Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t  :9;
    vuint32_t  :1;
    vuint32_t  :5;
    vuint32_t HVD7_C:1;                /* HVD7_C flag. */
  } B;
} PMCDIG_EPR_VD7_tag;

typedef union PMCDIG_REE_VD7_union_tag { /* Reset Event Enable VD7 Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t  :9;
    vuint32_t  :1;
    vuint32_t  :5;
    vuint32_t HVD7_C:1;                /* HVD7_C reset enable. */
  } B;
} PMCDIG_REE_VD7_tag;

typedef union PMCDIG_RES_VD7_union_tag { /* Reset Event Select Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t  :9;
    vuint32_t  :1;
    vuint32_t  :5;
    vuint32_t HVD7_C:1;                /* HVD7_C reset event select. */
  } B;
} PMCDIG_RES_VD7_tag;

typedef union PMCDIG_FEE_VD7_union_tag { /* FCCU Event Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t  :9;
    vuint32_t  :1;
    vuint32_t  :5;
    vuint32_t FEE7_C:1;                /* FEE7_C FCCU event enable. This bit defines whether an HVD assertion on the supply of the cold point generates an FCCU event. */
  } B;
} PMCDIG_FEE_VD7_tag;

typedef union PMCDIG_EPR_VD8_union_tag { /* Event Pending Register */
  vuint32_t R;
  struct {
    vuint32_t  :25;
    vuint32_t LVD8_F:1;                /* HVD8_F flag. */
    vuint32_t  :5;                     /* Reserved. */
    vuint32_t HVD8_C:1;                /* HVD8_C flag. */
  } B;
} PMCDIG_EPR_VD8_tag;

typedef union PMCDIG_REE_VD8_union_tag { /* Reset Event Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :25;
    vuint32_t LVD8_F:1;                /* HVD8_F reset enable. */
    vuint32_t  :5;                     /* Reserved. */
    vuint32_t HVD8_C:1;                /* HVD8_C reset enable. */
  } B;
} PMCDIG_REE_VD8_tag;

typedef union PMCDIG_RES_VD8_union_tag { /* Reset Event Select Registerr */
  vuint32_t R;
  struct {
    vuint32_t  :25;
    vuint32_t LVD8_F:1;                /* HVD8_F reset event select */
    vuint32_t  :5;                     /* Reserved. */
    vuint32_t HVD8_C:1;                /* HVD8_C reset event select. */
  } B;
} PMCDIG_RES_VD8_tag;

typedef union PMCDIG_FEE_VD8_union_tag { /* FCCU Event Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :25;
    vuint32_t FEE8_F:1;                /* FEE8_F FCCU event enable. */
    vuint32_t  :5;
    vuint32_t FEE8_C:1;                /* FEE8_C FCCU event enable. */
  } B;
} PMCDIG_FEE_VD8_tag;

typedef union PMCDIG_EPR_VD9_union_tag { /* LVD270 Event Pending Register */
  vuint32_t R;
  struct {
    vuint32_t  :17;
    vuint32_t LVD9_O:1;                /* LVD9_O flag. */
    vuint32_t  :2;
    vuint32_t HVD9_O:1;              /* LVD9_IF2 flag. */
    vuint32_t HVD9_IO5V:1;               /* LVD9_IF flag. */
    vuint32_t LVD9_IO5V:1;               /* LVD9_IJ flag. */
    vuint32_t :1;               /* LVD9_IM flag. */
    vuint32_t  :1;
    vuint32_t :1;                /* LVD9_F flag. */
    vuint32_t  :2;
    vuint32_t HVD9_PMC:1;              /* LVD9_EBI flag. */
    vuint32_t  :2;
    vuint32_t LVD9_PMC:1;                /* LVD9_C flag. */
  } B;
} PMCDIG_EPR_VD9_tag;

typedef union PMCDIG_REE_VD9_union_tag { /* Reset Event Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :17;
    vuint32_t LVD9_O:1;                /* LVD9_O reset enable. */
    vuint32_t  :2;
    vuint32_t HVD9_O:1;              /* LVD9_IF2 reset enable. */
    vuint32_t HVD9_IO5V:1;               /* LVD9_IF reset enable. */
    vuint32_t LVD9_IO5V:1;               /* LVD9_IJ reset enable. */
    vuint32_t  :1;               /* LVD9_IM reset enable. */
    vuint32_t  :1;
    vuint32_t :1;                /* LVD9_F reset enable. */
    vuint32_t  :2;
    vuint32_t HVD9_PMC:1;              /* LVD9_EBI reset enable. */
    vuint32_t  :2;
    vuint32_t LVD9_PMC:1;                /* LVD9_C reset enable. */
  } B;
} PMCDIG_REE_VD9_tag;

typedef union PMCDIG_RES_VD9_union_tag { /* Reset Event Select Register */
  vuint32_t R;
  struct {
    vuint32_t  :20;
    vuint32_t HVD9_O:1;              /* LVD9_IF2 reset event select. */
    vuint32_t HVD9_IO5V:1;               /* LVD9_IF reset event select. */
    vuint32_t  :6;
    vuint32_t HVD9_PMC:1;              /* LVD9_EBI reset event select. */
    vuint32_t  :3;
  } B;
} PMCDIG_RES_VD9_tag;

typedef union PMCDIG_FEE_VD9_union_tag { /* FCCU Event Enable VD9 */
  vuint32_t R;
  struct {
    vuint32_t  :17;
    vuint32_t FEE9_O:1;                /* FEE9_O FCCU event enable. */
    vuint32_t  :2;
    vuint32_t FEE9_O_H:1;              /* FEE9_IF2 FCCU event enable. */
    vuint32_t FEE9_IO5V_H:1;               /* FEE9_IF FCCU event enable. */
    vuint32_t FEE9_IO5V:1;               /* FEE9_IJ FCCU event enable. */
    vuint32_t :1;               /* FEE9_IM FCCU event enable. */
    vuint32_t  :1;
    vuint32_t :1;                /* FEE9_F FCCU event enable. */
    vuint32_t  :2;
    vuint32_t FEE9_PMC_H:1;              /* FEE9_EBI FCCU event enable. */
    vuint32_t  :2;
    vuint32_t FEE9_PMC:1;                /* FEE9_C FCCU event enable. */
  } B;
} PMCDIG_FEE_VD9_tag;

typedef union PMCDIG_EPR_VD10_union_tag { /* LVD295 Event Pending Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t LVD10_A:1;               /* LVD10_A flag. */
    vuint32_t  :8;
    vuint32_t LVD10_F:1;               /* LVD10_F flag. */
    vuint32_t  :6;
  } B;
} PMCDIG_EPR_VD10_tag;

typedef union PMCDIG_REE_VD10_union_tag { /* Reset Event Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t LVD10_A:1;               /* LVD10_A reset enable. */
    vuint32_t  :8;
    vuint32_t LVD10_F:1;               /* LVD10_F reset enable. */
    vuint32_t  :6;
  } B;
} PMCDIG_REE_VD10_tag;

typedef union PMCDIG_FEE_VD10_union_tag { /* FCCU Event Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t FEE10_A:1;               /* FEE10_A FCCU event enable. */
    vuint32_t  :8;
    vuint32_t FEE10_F:1;               /* FEE10_F FCCU event enable. */
    vuint32_t  :6;
  } B;
} PMCDIG_FEE_VD10_tag;

typedef union PMCDIG_EPR_VD12_union_tag { /* HVD360 Event Pending Register */
  vuint32_t R;
  struct {
    vuint32_t  :25;
    vuint32_t HVD12_F:1;               /* HVD12_F flag. */
    vuint32_t  :6;
  } B;
} PMCDIG_EPR_VD12_tag;

typedef union PMCDIG_REE_VD12_union_tag { /* Reset Event Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :25;
    vuint32_t HVD12_F:1;               /* HVD12_F reset enable. */
    vuint32_t  :6;
  } B;
} PMCDIG_REE_VD12_tag;

typedef union PMCDIG_RES_VD12_union_tag { /* Reset Event Select Register */
  vuint32_t R;
  struct {
    vuint32_t  :25;
    vuint32_t HVD12_F:1;               /* HVD12_F reset event select. */
    vuint32_t  :6;
  } B;
} PMCDIG_RES_VD12_tag;

typedef union PMCDIG_FEE_VD12_union_tag { /* FCCU Event Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :25;
    vuint32_t FEE12_F:1;               /* FEE12_F FCCU event enable. */
    vuint32_t  :6;
  } B;
} PMCDIG_FEE_VD12_tag;

typedef union PMCDIG_EPR_VD13_union_tag { /* Event Pending Register */
  vuint32_t R;
  struct {
    vuint32_t  :23;
    vuint32_t LVD13_IM:1;              /* LVD13_IM flag. */
    vuint32_t  :8;
  } B;
} PMCDIG_EPR_VD13_tag;

typedef union PMCDIG_REE_VD13_union_tag { /* Reset Event Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :23;
    vuint32_t LVD13_IM:1;              /* LVD13_IM reset enable. */
    vuint32_t  :8;
  } B;
} PMCDIG_REE_VD13_tag;

typedef union PMCDIG_RES_VD13_union_tag { /* Reset Event Select Register */
  vuint32_t R;
  struct {
    vuint32_t  :23;
    vuint32_t LVD13_IM:1;              /* LVD13_IM reset event select. */
    vuint32_t  :8;
  } B;
} PMCDIG_RES_VD13_tag;

typedef union PMCDIG_FEE_VD13_union_tag { /* FCCU Event Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :23;
    vuint32_t FEE13_IM:1;              /* FEE13_IM FCCU event enable. */
    vuint32_t  :8;
  } B;
} PMCDIG_FEE_VD13_tag;

typedef union PMCDIG_EPR_VD14_union_tag { /* Event Pending Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t LVD14_A:1;               /* LVD14_A flag. */
    vuint32_t  :6;
    vuint32_t HVD14_IM:1;              /* LVD14_IM flag. */
    vuint32_t  :8;
  } B;
} PMCDIG_EPR_VD14_tag;

typedef union PMCDIG_REE_VD14_union_tag { /* Reset Event Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t LVD14_A:1;               /* LVD14_A reset enable. */
    vuint32_t  :6;
    vuint32_t HVD14_IM:1;              /* LVD14_IM reset enable. */
    vuint32_t  :8;
  } B;
} PMCDIG_REE_VD14_tag;

typedef union PMCDIG_RES_VD14_union_tag { /* Reset Event Select Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t LVD14_A:1;               /* LVD14_A reset event select. */
    vuint32_t  :6;
    vuint32_t HVD14_IM:1;              /* LVD14_IM reset event select. */
    vuint32_t  :8;
  } B;
} PMCDIG_RES_VD14_tag;

typedef union PMCDIG_FEE_VD14_union_tag { /* FCCU Event Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t FEE14_A:1;               /* FEE14_A FCCU event enable. */
    vuint32_t  :6;
    vuint32_t FEE14_IM:1;              /* FEE14_IM FCCU event enable. */
    vuint32_t  :8;
  } B;
} PMCDIG_FEE_VD14_tag;

typedef union PMCDIG_EPR_VD15_union_tag { /* Event Pending Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t HVD15_A:1;               /* HVD15_A flag. */
    vuint32_t  :14;
    vuint32_t HVD15_C:1;               /* HVD15_C flag. */
  } B;
} PMCDIG_EPR_VD15_tag;

typedef union PMCDIG_REE_VD15_union_tag { /* Reset Event Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t HVD15_A:1;               /* HVD15_A reset enable. */
    vuint32_t  :14;
    vuint32_t HVD15_C:1;
  } B;
} PMCDIG_REE_VD15_tag;

typedef union PMCDIG_RES_VD15_union_tag { /* Reset Event Select Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t HVD15_A:1;               /* HVD15_A reset event select. */
    vuint32_t  :14;
    vuint32_t HVD15_C:1;               /* HVD15_C reset event select. */
  } B;
} PMCDIG_RES_VD15_tag;

typedef union PMCDIG_FEE_VD15_union_tag { /* FCCU Event Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t FEE15_A:1;               /* FEE15_A FCCU event enable. */
    vuint32_t  :14;
    vuint32_t FEE15_C:1;               /* FEE15_C FCCU event enable. */
  } B;
} PMCDIG_FEE_VD15_tag;

typedef union PMCDIG_VSIO_union_tag {  /* Voltage Supply for I/O Segment Register */
  vuint32_t R;
  struct {
    vuint32_t  :20;
    vuint32_t VSIO_IF2:1;              /* VSIO_IF2 control. */
    vuint32_t VSIO_IF:1;               /* VSIO_IF control. */
    vuint32_t VSIO_IJ:1;               /* VSIO_IJ control. */
    vuint32_t VSIO_IM:1;               /* VSIO_IM control. */
    vuint32_t  :8;
  } B;
} PMCDIG_VSIO_tag;

#if defined(CCFC3008PT)
#else
typedef union PMCDIG_PAD_CR_union_tag {  /* PAD Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t PAD_RETENTION:1;         /* Pad retention. */
  } B;
} PMCDIG_PAD_CR_tag;

typedef union PMCDIG_STCU_CR0_union_tag {   /* STCU Configuration Register 0 */
  vuint32_t R;
  struct {
    vuint32_t  :10;
    vuint32_t PLL_CLK:1;               /* Pll_clk_1 to 1 control. */
    vuint32_t MFD:8;                   /* Loop multiplication factor divider. */
    vuint32_t RFD:6;                   /* PHI reduced frequency divider. */
    vuint32_t PREDIV:4;                /* Input clock predivider. */
    vuint32_t MFD_RFD_LOAD:1;          /* Enable RFD valid to PLL0. Active high. */
    vuint32_t PREDIV_LOAD:1;           /* Enable PREDIV valid to PLL0. Active high. */
    vuint32_t PLL0_EN:1;               /* Stcu2 Select PLL0 Enabled. */
  } B;
} PMCDIG_STCU_CR0_tag;

typedef union PMCDIG_STCU_CR1_union_tag {   /* STCU Configuration Register 1 */
  vuint32_t R;
  struct {
    vuint32_t PMC_CFG_ENABLE:1;        /* Self_test control by pmcdig when pmc_cfg_enable. */
    vuint32_t  :2;
    vuint32_t PMC_PLL_CLK_1_TO_1:1;    /* Pll_clk_1 to 1 control. */
    vuint32_t  :1;
    vuint32_t PMC_BIST_PLL_EN:1;       /* Off-Line BIST with PLL Enabled. */
    vuint32_t PMC_BYPASS_FRST:1;       /* Reset the bypass selection after Off-Line self-test completion. */
    vuint32_t PMC_BYPASS_MODE:1;       /* Bypass mode. */
    vuint32_t  :3;
    vuint32_t PMC_OFF_MBIST_RUN:1;     /* Off-Line MBIST RUN Enabled. */
    vuint32_t  :3;
    vuint32_t PMC_OFF_LBIST_RUN:1;     /* Off-Line LBIST RUN Enabled. */
    vuint32_t  :1;
    vuint32_t PMC_MTEST_PDEX:7;        /* Off-Line MBIST Test Pindex. */
    vuint32_t  :1;
    vuint32_t PMC_LTEST_PDEX:7;        /* Off-Line LBIST Test Pindex. */
  } B;
} PMCDIG_STCU_CR1_tag;
#endif

typedef union PMCDIG_EPR_TD_union_tag { /* Event Pending Register */
  vuint32_t R;
  struct {
    vuint32_t  :28;
    vuint32_t TEMP_3:1;                /* TEMP_3 flag. */
    vuint32_t TEMP_2:1;                /* TEMP_2 flag. */
    vuint32_t  :1;
    vuint32_t TEMP_0:1;                /* TEMP_0 flag. */
  } B;
} PMCDIG_EPR_TD_tag;

typedef union PMCDIG_REE_TD_union_tag { /* Reset Event Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :28;
    vuint32_t TEMP_3:1;                /* TEMP_3 reset enable. */
    vuint32_t TEMP_2:1;                /* TEMP_2 reset enable. */
    vuint32_t  :1;
    vuint32_t TEMP_0:1;                /* TEMP_0 reset enable. */
  } B;
} PMCDIG_REE_TD_tag;

typedef union PMCDIG_RES_TD_union_tag { /* Reset Event Select Register */
  vuint32_t R;
  struct {
    vuint32_t  :28;
    vuint32_t TEMP_3:1;                /* TEMP_3 reset event select. */
    vuint32_t TEMP_2:1;                /* TEMP_2 reset event select. */
    vuint32_t  :1;
    vuint32_t TEMP_0:1;                /* TEMP_0 reset event select. */
  } B;
} PMCDIG_RES_TD_tag;

typedef union PMCDIG_CTL_TD_union_tag { /* Temperature Sensor Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t TS3IE:1;                 /* TS3IE Temperature Sensor input 3 Interrupt Enable. */
    vuint32_t TS2IE:1;                 /* TS2IE Temperature Sensor input 0 Interrupt Enable. */
    vuint32_t TS0IE:1;                 /* TS0IE Temperature Sensor input 0 Interrupt Enable. */
    vuint32_t  :1;
    vuint32_t TRIM_ADJ_OVER:4;         /* Customer adjustable over trim register. */
    vuint32_t  :2;
    vuint32_t TRIM_ADJ_UNDER:4;        /* Customer adjustable trim register. */
    vuint32_t DOUT_EN:1;               /* Digital Output Enable. */
    vuint32_t AOUT_EN:1;               /* Analog Output Enable. */
  } B;
} PMCDIG_CTL_TD_tag;

typedef union PMCDIG_FEE_TD_union_tag { /* Temp Sensor FCCU Event Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :28;
    vuint32_t FEE_TS3:1;               /* FEE_TS3 Temp Sensor FCCU event enable. */
    vuint32_t FEE_TS2:1;               /* FEE_TS2 Temp Sensor FCCU event enable. */
    vuint32_t  :1;
    vuint32_t FEE_TS0:1;               /* FEE_TS0 Temp Sensor FCCU event enable. */
  } B;
} PMCDIG_FEE_TD_tag;

typedef union PMCDIG_VD_UTST_union_tag { /* Voltage Detect User Mode Test Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;                     /* Reserved. */
    vuint32_t VOLT4_EN:1;              /* VOLT4 enable. */
    vuint32_t VOLT3_EN:1;              /* VOLT3 enable. */
    vuint32_t VOLT2_EN:1;              /* VOLT2 enable. */
    vuint32_t VOLT1_EN:1;              /* VOLT1 enable. */
    vuint32_t  :4;                     /* Reserved. */
    vuint32_t VOLT4:1;                 /* VOLT4 flag. */
    vuint32_t VOLT3:1;                 /* VOLT3 flag. */
    vuint32_t VOLT2:1;                 /* VOLT2 flag. */
    vuint32_t VOLT1:1;                 /* VOLT1 flag. */
    vuint32_t  :10;
    vuint32_t VD_UTST:6;               /* Voltage Detect: User Test. */
  } B;
} PMCDIG_VD_UTST_tag;

typedef union PMCDIG_ADC_CH_union_tag { /* ADC Channel Select Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t ADC_CS:6;                /* ADC_CS Channel Select. */
  } B;
} PMCDIG_ADC_CH_tag;

typedef union PMCDIG_VREG1P2_CTRL_union_tag { /* Voltage Regulator 1.2V Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t VREG1P2_DIS:1;           /* This bit controls if the AUX Regulator (Vreg1p2) is disabled. */
  } B;
} PMCDIG_VREG1P2_CTRL_tag;

typedef union PMCDIG_MCR_union_tag {   /* Module Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;                    /* Reserved. */
    vuint32_t  :1;
    vuint32_t USER_SELF_TEST_EN:1;     /* This bit allows the VD_UTST bits int he VD_UTST register to be enabled. */
    vuint32_t  :6;                     /* Reserved. */
    vuint32_t TEST_PIN:1;              /* This bit is indicates the current value of the Test Pin. */
    vuint32_t  :6;                     /* Reserved. */
    vuint32_t SBRAM_BRDET:1;           /* SBRAM_BRDET. */
  } B;
} PMCDIG_MCR_tag;

struct PMCDIG_tag {
  PMCDIG_GR_S_tag GR_S;                /* Supply Gauge Status Register */
  PMCDIG_GR_P_tag GR_P;                /* Pending Gauge Status Register */
  PMCDIG_IE_P_tag IE_P;                /* Interrupt Enable Pending Register */
  uint8_t PMCDIG_reserved0[36];
  PMCDIG_EPR_VD3_tag EPR_VD3;          /* Event Pending Register */
  PMCDIG_REE_VD3_tag REE_VD3;          /* Reset Event Enable Register */
  PMCDIG_RES_VD3_tag RES_VD3;          /* Reset Event Select Register */
  PMCDIG_FEE_VD3_tag FEE_VD3;          /* FCCU Event Enable Register */
  PMCDIG_EPR_VD4_tag EPR_VD4;          /* LVD108 Event Pending Register */
  PMCDIG_REE_VD4_tag REE_VD4;          /* Reset Event Select Register */
  PMCDIG_RES_VD4_tag RES_VD4;          /* Reset Event Select Register */
  PMCDIG_FEE_VD4_tag FEE_VD4;          /* FCCU Event Enable Register */
  uint8_t PMCDIG_reserved1[32];
  PMCDIG_EPR_VD7_tag EPR_VD7;          /* Event Pending Register */
  PMCDIG_REE_VD7_tag REE_VD7;          /* Reset Event Enable VD7 Register */
  PMCDIG_RES_VD7_tag RES_VD7;          /* Reset Event Select Register */
  PMCDIG_FEE_VD7_tag FEE_VD7;          /* FCCU Event Enable Register */
  PMCDIG_EPR_VD8_tag EPR_VD8;          /* Event Pending Register */
  PMCDIG_REE_VD8_tag REE_VD8;          /* Reset Event Enable Register */
  PMCDIG_RES_VD8_tag RES_VD8;          /* Reset Event Select Registerr */
  PMCDIG_FEE_VD8_tag FEE_VD8;          /* FCCU Event Enable Register */
  PMCDIG_EPR_VD9_tag EPR_VD9;          /* LVD270 Event Pending Register */
  PMCDIG_REE_VD9_tag REE_VD9;          /* Reset Event Enable Register */
  PMCDIG_RES_VD9_tag RES_VD9;          /* Reset Event Select Register */
  PMCDIG_FEE_VD9_tag FEE_VD9;          /* FCCU Event Enable VD9 */
  PMCDIG_EPR_VD10_tag EPR_VD10;        /* LVD295 Event Pending Register */
  PMCDIG_REE_VD10_tag REE_VD10;        /* Reset Event Enable Register */
  uint8_t PMCDIG_reserved2[4];
  PMCDIG_FEE_VD10_tag FEE_VD10;        /* FCCU Event Enable Register */
  uint8_t PMCDIG_reserved3[16];
  PMCDIG_EPR_VD12_tag EPR_VD12;        /* HVD360 Event Pending Register */
  PMCDIG_REE_VD12_tag REE_VD12;        /* Reset Event Enable Register */
  PMCDIG_RES_VD12_tag RES_VD12;        /* Reset Event Select Register */
  PMCDIG_FEE_VD12_tag FEE_VD12;        /* FCCU Event Enable Register */
  PMCDIG_EPR_VD13_tag EPR_VD13;        /* Event Pending Register */
  PMCDIG_REE_VD13_tag REE_VD13;        /* Reset Event Enable Register */
  PMCDIG_RES_VD13_tag RES_VD13;        /* Reset Event Select Register */
  PMCDIG_FEE_VD13_tag FEE_VD13;        /* FCCU Event Enable Register */
  PMCDIG_EPR_VD14_tag EPR_VD14;        /* Event Pending Register */
  PMCDIG_REE_VD14_tag REE_VD14;        /* Reset Event Enable Register */
  PMCDIG_RES_VD14_tag RES_VD14;        /* Reset Event Select Register */
  PMCDIG_FEE_VD14_tag FEE_VD14;        /* FCCU Event Enable Register */
  PMCDIG_EPR_VD15_tag EPR_VD15;        /* Event Pending Register */
  PMCDIG_REE_VD15_tag REE_VD15;        /* Reset Event Enable Register */
  PMCDIG_RES_VD15_tag RES_VD15;        /* Reset Event Select Register */
  PMCDIG_FEE_VD15_tag FEE_VD15;        /* FCCU Event Enable Register */
  uint8_t PMCDIG_reserved4[4];
  PMCDIG_VSIO_tag VSIO;                /* Voltage Supply for I/O Segment Register */
#if defined(CCFC3008PT)
  uint8_t PMCDIG_reserved5[504];
#else
  uint8_t PMCDIG_reserved5[256];
  PMCDIG_PAD_CR_tag PAD_CR;            /* PAD Configuration Register */
  PMCDIG_STCU_CR0_tag STCU_CR0;        /* STCU Configuration Register 0 */
  PMCDIG_STCU_CR1_tag STCU_CR1;        /* STCU Configuration Register 1 */
  uint8_t PMCDIG_reserved6[236];
#endif
  PMCDIG_EPR_TD_tag EPR_TD;            /* Event Pending Register */
  PMCDIG_REE_TD_tag REE_TD;            /* Reset Event Enable Register */
  PMCDIG_RES_TD_tag RES_TD;            /* Reset Event Select Register */
  PMCDIG_CTL_TD_tag CTL_TD;            /* Temperature Sensor Configuration Register */
  uint8_t PMCDIG_reserved7[8];
  PMCDIG_FEE_TD_tag FEE_TD;            /* Temp Sensor FCCU Event Enable Register */
  uint8_t PMCDIG_reserved8[36];
  PMCDIG_VD_UTST_tag VD_UTST;          /* Voltage Detect User Mode Test Register */
  PMCDIG_ADC_CH_tag ADC_CH;            /* ADC Channel Select Register */
  uint8_t PMCDIG_reserved9[4];
  PMCDIG_VREG1P2_CTRL_tag VREG1P2_CTRL; /* Voltage Regulator 1.2V Control Register */
  PMCDIG_MCR_tag MCR;                  /* Module Control Register */
};



/*******************************************************************************
 * PMC_dig Register Bit Fields
 *******************************************************************************/
#define PMC_CTL_TD_TRIM_ADJ_OVER                ((uint32)0x00000F00U)
#define PMC_CTL_TD_TRIM_ADJ_UNDER               ((uint32)0x0000003CU)

#define PMC_IER_IE_EN_MASK32                    ((uint32)0x80000000U)
#define PMC_IER_VD15IE_A_ENA                    ((uint32)0x02000000U)
#define PMC_IER_VD15IE_C_ENA                    ((uint32)0x01000000U)
#define PMC_IER_VD14IE_A_ENA                    ((uint32)0x00400000U)
#define PMC_IER_VD14IE_IM_ENA                   ((uint32)0x00200000U)
#define PMC_IER_VD13IE_IM_ENA                   ((uint32)0x00040000U)
#define PMC_IER_VD12IE_F_ENA                    ((uint32)0x00020000U)
#define PMC_IER_VD10IE_A_ENA                    ((uint32)0x00010000U)
#define PMC_IER_VD10IE_F_ENA                    ((uint32)0x00008000U)
#define PMC_IER_VD9IE_O_ENA                     ((uint32)0x00004000U)
#define PMC_IER_VD9IE_O_H_ENA                   ((uint32)0x00002000U)
#define PMC_IER_VD9IE_IO_5V_H_ENA               ((uint32)0x00001000U)
#define PMC_IER_VD9IE_IO_5V_ENA                 ((uint32)0x00000800U)
#define PMC_IER_VD9IE_PMC_H_ENA                 ((uint32)0x00000100U)
#define PMC_IER_VD9IE_PMC_ENA                   ((uint32)0x00000080U)
#define PMC_IER_VD8IE_C_ENA                     ((uint32)0x00000040U)
#define PMC_IER_VD8IE_F_ENA                     ((uint32)0x00000020U)
#define PMC_IER_VD7IE_C_ENA                     ((uint32)0x00000010U)
#define PMC_IER_VD4IE_C_ENA                     ((uint32)0x00000008U)
#define PMC_IER_VD3IE_P_ENA                     ((uint32)0x00000004U)
#define PMC_IER_VD3IE_F_ENA                     ((uint32)0x00000002U)

#define PMC_IER_VD15IE_A_DIS                    ((uint32)0x00000000U)
#define PMC_IER_VD15IE_C_DIS                    ((uint32)0x00000000U)
#define PMC_IER_VD14IE_A_DIS                    ((uint32)0x00000000U)
#define PMC_IER_VD14IE_IM_DIS                   ((uint32)0x00000000U)
#define PMC_IER_VD13IE_IM_DIS                   ((uint32)0x00000000U)
#define PMC_IER_VD12IE_F_DIS                    ((uint32)0x00000000U)
#define PMC_IER_VD10IE_A_DIS                    ((uint32)0x00000000U)
#define PMC_IER_VD10IE_F_DIS                    ((uint32)0x00000000U)
#define PMC_IER_VD9IE_O_DIS                     ((uint32)0x00000000U)
#define PMC_IER_VD9IE_O_H_DIS                   ((uint32)0x00000000U)
#define PMC_IER_VD9IE_IO_5V_H_DIS               ((uint32)0x00000000U)
#define PMC_IER_VD9IE_IO_5V_DIS                 ((uint32)0x00000000U)
#define PMC_IER_VD9IE_PMC_H_DIS                 ((uint32)0x00000000U)
#define PMC_IER_VD9IE_PMC_DIS                   ((uint32)0x00000000U)
#define PMC_IER_VD8IE_C_DIS                     ((uint32)0x00000000U)
#define PMC_IER_VD8IE_F_DIS                     ((uint32)0x00000000U)
#define PMC_IER_VD7IE_C_DIS                     ((uint32)0x00000000U)
#define PMC_IER_VD4IE_C_DIS                     ((uint32)0x00000000U)
#define PMC_IER_VD3IE_P_DIS                     ((uint32)0x00000000U)
#define PMC_IER_VD3IE_F_DIS                     ((uint32)0x00000000U)
/****************************************************/
/***               (REE_VD3)                      ***/
/****************************************************/

#define PMC_REE_VD3_HVD3_P_ENA                  ((uint32)0x00000080U)
#define PMC_REE_VD3_LVD3_F_ENA                  ((uint32)0x00000040U)
#define PMC_REE_VD3_LVD3_C_ENA                  ((uint32)0x00000001U)
#define PMC_REE_VD3_HVD3_P_DIS                  ((uint32)0x00000000U)
#define PMC_REE_VD3_LVD3_F_DIS                  ((uint32)0x00000000U)
#define PMC_REE_VD3_LVD3_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (RES_VD3)                      ***/
/****************************************************/

#define PMC_RES_VD3_HVD3_P_ENA                  ((uint32)0x00000080U)
#define PMC_RES_VD3_LVD3_F_ENA                  ((uint32)0x00000040U)
#define PMC_RES_VD3_LVD3_C_ENA                  ((uint32)0x00000001U)
#define PMC_RES_VD3_HVD3_P_DIS                  ((uint32)0x00000000U)
#define PMC_RES_VD3_LVD3_F_DIS                  ((uint32)0x00000000U)
#define PMC_RES_VD3_LVD3_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (FEE_VD3)                      ***/
/****************************************************/
#define PMC_FEE_VD3_FEE3_P_ENA                  ((uint32)0x00000080U)
#define PMC_FEE_VD3_FEE3_F_ENA                  ((uint32)0x00000040U)
#define PMC_FEE_VD3_FEE3_C_ENA                  ((uint32)0x00000001U)
#define PMC_FEE_VD3_FEE3_P_DIS                  ((uint32)0x00000000U)
#define PMC_FEE_VD3_FEE3_F_DIS                  ((uint32)0x00000000U)
#define PMC_FEE_VD3_FEE3_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (REE_VD4)                      ***/
/****************************************************/
#define PMC_REE_VD4_LVD4_C_ENA                  ((uint32)0x00000001U)
#define PMC_REE_VD4_LVD4_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (RES_VD4)                      ***/
/****************************************************/
#define PMC_RES_VD4_LVD4_C_ENA                  ((uint32)0x00000001U)
#define PMC_RES_VD4_LVD4_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (FEE_VD4)                      ***/
/****************************************************/
#define PMC_FEE_VD4_FEE4_C_ENA                  ((uint32)0x00000001U)
#define PMC_FEE_VD4_FEE4_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (REE_VD7)                      ***/
/****************************************************/
#define PMC_REE_VD7_HVD7_C_ENA                  ((uint32)0x00000001U)
#define PMC_REE_VD7_HVD7_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (RES_VD7)                      ***/
/****************************************************/
#define PMC_RES_VD7_HVD7_C_ENA                  ((uint32)0x00000001U)
#define PMC_RES_VD7_HVD7_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (FEE_VD7)                      ***/
/****************************************************/
#define PMC_FEE_VD7_FEE7_C_ENA                  ((uint32)0x00000001U)
#define PMC_FEE_VD7_FEE7_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (REE_VD8)                      ***/
/****************************************************/
#define PMC_REE_VD8_LVD8_F_ENA                  ((uint32)0x00000040U)
#define PMC_REE_VD8_HVD8_C_ENA                  ((uint32)0x00000001U)
#define PMC_REE_VD8_LVD8_F_DIS                  ((uint32)0x00000000U)
#define PMC_REE_VD8_HVD8_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (RES_VD8)                      ***/
/****************************************************/
#define PMC_RES_VD8_LVD8_F_ENA                  ((uint32)0x00000040U)
#define PMC_RES_VD8_HVD8_C_ENA                  ((uint32)0x00000001U)
#define PMC_RES_VD8_LVD8_F_DIS                  ((uint32)0x00000000U)
#define PMC_RES_VD8_HVD8_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (FEE_VD8)                      ***/
/****************************************************/
#define PMC_FEE_VD8_FEE8_F_ENA                  ((uint32)0x00000040U)
#define PMC_FEE_VD8_FEE8_C_ENA                  ((uint32)0x00000001U)
#define PMC_FEE_VD8_FEE8_F_DIS                  ((uint32)0x00000000U)
#define PMC_FEE_VD8_FEE8_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (REE_VD9)                      ***/
/****************************************************/
#define PMC_REE_VD9_LVD9_O_ENA                  ((uint32)0x00004000U)
#define PMC_REE_VD9_HVD9_O_ENA                  ((uint32)0x00000800U)
#define PMC_REE_VD9_HVD9_IO_5V_ENA              ((uint32)0x00000400U)
#define PMC_REE_VD9_LVD9_IO_5V_ENA              ((uint32)0x00000200U)
#define PMC_REE_VD9_HVD9_PMC_ENA                ((uint32)0x00000008U)
#define PMC_REE_VD9_LVD9_PMC_ENA                ((uint32)0x00000001U)
#define PMC_REE_VD9_LVD9_O_DIS                  ((uint32)0x00000000U)
#define PMC_REE_VD9_HVD9_O_DIS                  ((uint32)0x00000000U)
#define PMC_REE_VD9_HVD9_IO_5V_DIS              ((uint32)0x00000000U)
#define PMC_REE_VD9_LVD9_IO_5V_DIS              ((uint32)0x00000000U)
#define PMC_REE_VD9_HVD9_PMC_DIS                ((uint32)0x00000000U)
#define PMC_REE_VD9_LVD9_PMC_DIS                ((uint32)0x00000000U)
/****************************************************/
/***               (RES_VD9)                      ***/
/****************************************************/
#define PMC_RES_VD9_HVD9_O_ENA                  ((uint32)0x00000800U)
#define PMC_RES_VD9_HVD9_IO_5V_ENA              ((uint32)0x00000400U)
#define PMC_RES_VD9_HVD9_PMC_ENA                ((uint32)0x00000008U)
#define PMC_RES_VD9_HVD9_O_DIS                  ((uint32)0x00000000U)
#define PMC_RES_VD9_HVD9_IO_5V_DIS              ((uint32)0x00000000U)
#define PMC_RES_VD9_HVD9_PMC_DIS                ((uint32)0x00000000U)
/****************************************************/
/***               (FEE_VD9)                      ***/
/****************************************************/
#define PMC_FEE_VD9_FEE9_O_ENA                  ((uint32)0x00004000U)
#define PMC_FEE_VD9_FEE9_O_H_ENA                ((uint32)0x00000800U)
#define PMC_FEE_VD9_FEE9_IO_5V_H_ENA            ((uint32)0x00000400U)
#define PMC_FEE_VD9_FEE9_IO_5V_ENA              ((uint32)0x00000200U)
#define PMC_FEE_VD9_FEE9_PMC_H_ENA              ((uint32)0x00000008U)
#define PMC_FEE_VD9_FEE9_PMC_ENA                ((uint32)0x00000001U)
#define PMC_FEE_VD9_FEE9_O_DIS                  ((uint32)0x00000000U)
#define PMC_FEE_VD9_FEE9_O_H_DIS                ((uint32)0x00000000U)
#define PMC_FEE_VD9_FEE9_IO_5V_H_DIS            ((uint32)0x00000000U)
#define PMC_FEE_VD9_FEE9_IO_5V_DIS              ((uint32)0x00000000U)
#define PMC_FEE_VD9_FEE9_PMC_H_DIS              ((uint32)0x00000000U)
#define PMC_FEE_VD9_FEE9_PMC_DIS                ((uint32)0x00000000U)
/****************************************************/
/***               (REE_VD10)                     ***/
/****************************************************/
#define PMC_REE_VD10_LVD10_A_ENA                ((uint32)0x00008000U)
#define PMC_REE_VD10_LVD10_F_ENA                ((uint32)0x00000040U)
#define PMC_REE_VD10_LVD10_A_DIS                ((uint32)0x00000000U)
#define PMC_REE_VD10_LVD10_F_DIS                ((uint32)0x00000000U)
/****************************************************/
/***               (FEE_VD10)                     ***/
/****************************************************/
#define PMC_FEE_VD10_FEE10_A_ENA                ((uint32)0x00008000U)
#define PMC_FEE_VD10_FEE10_F_ENA                ((uint32)0x00000040U)
#define PMC_FEE_VD10_FEE10_A_DIS                ((uint32)0x00000000U)
#define PMC_FEE_VD10_FEE10_F_DIS                ((uint32)0x00000000U)
/****************************************************/
/***               (REE_VD12)                     ***/
/****************************************************/
#define PMC_REE_VD12_HVD12_F_ENA                ((uint32)0x00000040U)
#define PMC_REE_VD12_HVD12_F_DIS                ((uint32)0x00000000U)
/****************************************************/
/***               (RES_VD12)                     ***/
/****************************************************/
#define PMC_RES_VD12_HVD12_F_ENA                ((uint32)0x00000040U)
#define PMC_RES_VD12_HVD12_F_DIS                ((uint32)0x00000000U)
/****************************************************/
/***               (FEE_VD12)                     ***/
/****************************************************/
#define PMC_FEE_VD12_FEE12_F_ENA                ((uint32)0x00000040U)
#define PMC_FEE_VD12_FEE12_F_DIS                ((uint32)0x00000000U)
/****************************************************/
/***               (REE_VD13)                     ***/
/****************************************************/
#define PMC_REE_VD13_LVD13_IM_ENA               ((uint32)0x00000100U)
#define PMC_REE_VD13_LVD13_IM_DIS               ((uint32)0x00000000U)
/****************************************************/
/***               (RES_VD13)                     ***/
/****************************************************/
#define PMC_RES_VD13_LVD13_IM_ENA               ((uint32)0x00000100U)
#define PMC_RES_VD13_LVD13_IM_DIS               ((uint32)0x00000000U)
/****************************************************/
/***               (FEE_VD13)                     ***/
/****************************************************/
#define PMC_FEE_VD13_FEE13_IM_ENA               ((uint32)0x00000100U)
#define PMC_FEE_VD13_FEE13_IM_DIS               ((uint32)0x00000000U)
/****************************************************/
/***               (REE_VD14)                     ***/
/****************************************************/
#define PMC_REE_VD14_LVD14_A_ENA                ((uint32)0x00008000U)
#define PMC_REE_VD14_HVD14_IM_ENA               ((uint32)0x00000100U)
#define PMC_REE_VD14_LVD14_A_DIS                ((uint32)0x00000000U)
#define PMC_REE_VD14_HVD14_IM_DIS               ((uint32)0x00000000U)
/****************************************************/
/***               (RES_VD14)                      ***/
/****************************************************/
#define PMC_RES_VD14_LVD14_A_ENA                ((uint32)0x00008000U)
#define PMC_RES_VD14_HVD14_IM_ENA               ((uint32)0x00000100U)
#define PMC_RES_VD14_LVD14_A_DIS                ((uint32)0x00000000U)
#define PMC_RES_VD14_HVD14_IM_DIS               ((uint32)0x00000000U)
/****************************************************/
/***               (FEE_VD14)                      ***/
/****************************************************/
#define PMC_FEE_VD14_FEE14_A_ENA                ((uint32)0x00008000U)
#define PMC_FEE_VD14_FEE14_IM_ENA               ((uint32)0x00000100U)
#define PMC_FEE_VD14_FEE14_A_DIS                ((uint32)0x00000000U)
#define PMC_FEE_VD14_FEE14_IM_DIS               ((uint32)0x00000000U)
/****************************************************/
/***               (REE_VD15)                     ***/
/****************************************************/
#define PMC_REE_VD15_HVD15_A_ENA                ((uint32)0x00008000U)
#define PMC_REE_VD15_HVD15_C_ENA                ((uint32)0x00000001U)
#define PMC_REE_VD15_HVD15_A_DIS                ((uint32)0x00000000U)
#define PMC_REE_VD15_HVD15_C_DIS                ((uint32)0x00000000U)
/****************************************************/
/***               (RES_VD15)                     ***/
/****************************************************/
#define PMC_RES_VD15_HVD15_A_ENA                ((uint32)0x00008000U)
#define PMC_RES_VD15_HVD15_C_ENA                ((uint32)0x00000001U)
#define PMC_RES_VD15_HVD15_A_DIS                ((uint32)0x00000000U)
#define PMC_RES_VD15_HVD15_C_DIS                ((uint32)0x00000000U)
/****************************************************/
/***               (FEE_VD15)                     ***/
/****************************************************/
#define PMC_FEE_VD15_FEE15_A_ENA                ((uint32)0x00008000U)
#define PMC_FEE_VD15_FEE15_C_ENA                ((uint32)0x00000001U)
#define PMC_FEE_VD15_FEE15_A_DIS                ((uint32)0x00000000U)
#define PMC_FEE_VD15_FEE15_C_DIS                ((uint32)0x00000000U)
/****************************************************/
/***               (VSIO)                         ***/
/****************************************************/
#define PMC_VSIO_VSIO_IF2_EN                    ((uint32)0x00000800U)
#define PMC_VSIO_VSIO_IF_EN                     ((uint32)0x00000400U)
#define PMC_VSIO_VSIO_IJ_EN                     ((uint32)0x00000200U)
#define PMC_VSIO_VSIO_IM_EN                     ((uint32)0x00000100U)


/****************************************************/
/***               (REE_TD)                       ***/
/****************************************************/
#define PMC_REE_TD_TEMP_3_ENA                   ((uint32)0x00000008U)
#define PMC_REE_TD_TEMP_2_ENA                   ((uint32)0x00000004U)
#define PMC_REE_TD_TEMP_0_ENA                   ((uint32)0x00000001U)
#define PMC_REE_TD_TEMP_3_DIS                   ((uint32)0x00000000U)
#define PMC_REE_TD_TEMP_2_DIS                   ((uint32)0x00000000U)
#define PMC_REE_TD_TEMP_0_DIS                   ((uint32)0x00000000U)

/****************************************************/
/***               (RES_TD)                       ***/
/****************************************************/

#define PMC_RES_TD_TEMP_3_ENA                   ((uint32)0x00000008U)
#define PMC_RES_TD_TEMP_2_ENA                   ((uint32)0x00000004U)
#define PMC_RES_TD_TEMP_0_ENA                   ((uint32)0x00000001U)
#define PMC_RES_TD_TEMP_3_DIS                   ((uint32)0x00000000U)
#define PMC_RES_TD_TEMP_2_DIS                   ((uint32)0x00000000U)
#define PMC_RES_TD_TEMP_0_DIS                   ((uint32)0x00000000U)

/****************************************************/
/***               (CTL_TD)                       ***/
/****************************************************/

#define PMC_CTL_TD_TS3IE_ENA                    ((uint32)0x00008000U)
#define PMC_CTL_TD_TS2IE_ENA                    ((uint32)0x00004000U)
#define PMC_CTL_TD_TS0IE_ENA                    ((uint32)0x00002000U)
#define PMC_CTL_TD_DOUT_ENA                     ((uint32)0x00000002U)
#define PMC_CTL_TD_AOUT_ENA                     ((uint32)0x00000001U)
#define PMC_CTL_TD_TS3IE_DIS                    ((uint32)0x00000000U)
#define PMC_CTL_TD_TS2IE_DIS                    ((uint32)0x00000000U)
#define PMC_CTL_TD_TS0IE_DIS                    ((uint32)0x00000000U)
#define PMC_CTL_TD_DOUT_DIS                     ((uint32)0x00000000U)
#define PMC_CTL_TD_AOUT_DIS                     ((uint32)0x00000000U)

/****************************************************/
/***               (FEE_TD)                       ***/
/****************************************************/

#define PMC_FEE_TD_FEE_TS3_ENA                  ((uint32)0x00000008U)
#define PMC_FEE_TD_FEE_TS2_ENA                  ((uint32)0x00000004U)
#define PMC_FEE_TD_FEE_TS0_ENA                  ((uint32)0x00000001U)
#define PMC_FEE_TD_FEE_TS3_DIS                  ((uint32)0x00000000U)
#define PMC_FEE_TD_FEE_TS2_DIS                  ((uint32)0x00000000U)
#define PMC_FEE_TD_FEE_TS0_DIS                  ((uint32)0x00000000U)

/****************************************************/
/***               (VSIO)                         ***/
/****************************************************/
#define PMC_VSIO_VSIO_IF2_ENA                   ((uint32)0x00000800U)
#define PMC_VSIO_VSIO_IF_ENA                    ((uint32)0x00000400U)
#define PMC_VSIO_VSIO_IJ_ENA                    ((uint32)0x00000200U)
#define PMC_VSIO_VSIO_IM_ENA                    ((uint32)0x00000100U)
#define PMC_VSIO_VSIO_IF2_DIS                   ((uint32)0x00000000U)
#define PMC_VSIO_VSIO_IF_DIS                    ((uint32)0x00000000U)
#define PMC_VSIO_VSIO_IJ_DIS                    ((uint32)0x00000000U)
#define PMC_VSIO_VSIO_IM_DIS                    ((uint32)0x00000000U)

#endif  /* PMCDIG_REG_H_ */
