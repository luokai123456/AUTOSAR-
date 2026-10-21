#ifndef EIOMUX_REG_H_
#define EIOMUX_REG_H_

/* ============================================================================
   =============================== Module: EIOMUX =============================
   ============================================================================ */
#define EIOMUX2_PAD_REG_NUM_MAX     (332U)
#define EIOMUX2_ISR_REG_NUM_MAX     (267U)
typedef union eIOMUX_PAD_union_tag {   /*PAD_X Register */
    vuint32_t R;
    struct {
        vuint32_t  :20;     /* bit[31:12] Reserved */
        vuint32_t  IBE:1;   /* bit[11] PAD Input Enable */
        vuint32_t  ODE:1;   /* bit[10] GPIO-PAD open-drain Enable */
        vuint32_t  SMOD:1;  /* bit[9] Safe Mode Obe Disable */
        vuint32_t  OINV:1;  /* bit[8] Output inverted value of the original output value */
        vuint32_t  ODC:3;   /* bit[7:5] Output Driver Control */
        vuint32_t  ISSS:5;  /* bit[4:0] Output mux input source select signal */
    } B;
} eIOMUX_PAD_tag;

typedef union eIOMUX_ICR_union_tag {   /* PAD Input Select Register */
    vuint32_t R;
    struct {
        vuint32_t  INV:1; /* bit[31] The input would be Inverterd to the target internal modules. */
        vuint32_t  :28;       /* bit[30:3] Reserved */
        vuint32_t  ISS:3;     /* bit[2:0] Output mux input source select signal */
    } B;
} eIOMUX_ICR_tag;

struct EIOMUX2_tag {
	eIOMUX_PAD_tag PAD[EIOMUX2_PAD_REG_NUM_MAX];      /* PAD IO mode select Register, Offset: 0x000 ~ 0x52C */
    vuint8_t EIOMUX_reserved0[720];         /* Reserved, Offset: 0x52D ~ 0x7FF */
    eIOMUX_ICR_tag ICR[EIOMUX2_ISR_REG_NUM_MAX];                /* Input Select Register,  Offset: 0x800~0xC28*/
};

#endif /* EIOMUX_REG_H_ */
