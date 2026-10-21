#ifndef EIOMUX_REG_H_
#define EIOMUX_REG_H_

/* ============================================================================
   =============================== Module: EIOMUX =============================
   ============================================================================ */

typedef union EIOMUX_MODE_union_tag {   /* PAD IO mode select Register */
  vuint32_t R;
  struct {
    vuint32_t  :27;
    vuint32_t PAD_IO_MODE_SEL:5;    /* PAD IO mode select */
  } B;
} EIOMUX_MODE_tag;

#ifdef FUNC_EIOMUX_ANA_EN
typedef union EIOMUX_ANA_EN_union_tag {   /* IOMUX_PAD_ANA_ENABLE Register */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t PAD_254_ANA_EN:1;     /* PAD_254 enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_237_ANA_EN:1;     /* PAD_237 enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_202_ANA_EN:1;     /* PAD_202 enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_185_ANA_EN:1;     /* PAD_185 enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_176_ANA_EN:1;     /* PAD_176 enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_168_ANA_EN:1;     /* PAD_168 enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_167_ANA_EN:1;     /* PAD_167 enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_166_ANA_EN:1;     /* PAD_166 enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_136_ANA_EN:1;     /* PAD_136 enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_133_ANA_EN:1;     /* PAD_133 enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_130_ANA_EN:1;     /* PAD_130 enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_125_ANA_EN:1;     /* PAD_125 enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_113_ANA_EN:1;     /* PAD_113 enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_104_ANA_EN:1;     /* PAD_104 enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_103_ANA_EN:1;     /* PAD_103 enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_96_ANA_EN:1;      /* PAD_96  enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_85_ANA_EN:1;      /* PAD_85  enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_77_ANA_EN:1;      /* PAD_77  enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_68_ANA_EN:1;      /* PAD_68  enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_66_ANA_EN:1;      /* PAD_66  enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_64_ANA_EN:1;      /* PAD_64  enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_60_ANA_EN:1;      /* PAD_60  enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_38_ANA_EN:1;      /* PAD_38  enable analog function, IE = 0, OE = 0 */
    vuint32_t PAD_32_ANA_EN:1;      /* PAD_32  enable analog function, IE = 0, OE = 0 */
  } B;
} EIOMUX_ANA_EN_tag;
#endif  /* FUNC_EIOMUX_ANA_EN */

typedef union EIOMUX_PAD_MCD_LVDS_union_tag {   /* IOMUX_PAD_MCD_LVDS Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t PAD_LVDS_SEL:1;   /* PAD 48/49/50/51 select (IO original/LVDS MCD) function */
  } B;
} EIOMUX_PAD_MCD_LVDS_tag;

struct EIOMUX_tag {
    EIOMUX_MODE_tag PAD_MODE[332];      /* PAD IO mode select Register, Offset: 0x000 ~ 0x52C */
    vuint8_t EIOMUX_reserved0[16];      /* Reserved, Offset: 0x530 ~ 0x53F */
#ifdef FUNC_EIOMUX_ANA_EN
    EIOMUX_ANA_EN_tag PAD_ANA_EN;       /* IOMUX_PAD_ANA_ENABLE Register, Offset: 0x540 */
#else
    vuint8_t EIOMUX_reserved1[4];
#endif
    EIOMUX_PAD_MCD_LVDS_tag PAD_MCD_LVDS_EN;    /* IOMUX_PAD_MCD_LVDS Register, Offset: 0x544 */
};

#endif /* EIOMUX_REG_H_ */
