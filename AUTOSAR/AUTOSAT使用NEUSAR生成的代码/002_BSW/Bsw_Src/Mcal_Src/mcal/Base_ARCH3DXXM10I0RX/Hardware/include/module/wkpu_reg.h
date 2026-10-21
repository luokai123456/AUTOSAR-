#ifndef WKPU_REG_H_
#define WKPU_REG_H_

/* ============================================================================
   =============================== Module: WKPU ===============================
   ============================================================================ */

typedef union WKPU_NSR_union_tag {  /* NMI Status Flag Register */
    vuint32_t R;
    struct {
        vuint32_t NIF0:1;           /* NMI Status Flag 0 (core 0) */
        vuint32_t NOVF0:1;          /* NMI Overrun Status Flag 0 (core 1) */
        vuint32_t  :6;
        vuint32_t NIF1:1;           /* NMI Status Flag 1 (core 1) */
        vuint32_t NOVF1:1;          /* NMI Overrun Status Flag 1 (core 1) */
        vuint32_t  :6;
        vuint32_t NIF2:1;           /* NMI Status Flag 2 (core 2) */
        vuint32_t NOVF2:1;          /* NMI Overrun Status Flag 2 (core 2) */
        vuint32_t  :6;
        vuint32_t RIF:1;            /* Reset Status Flag */
        vuint32_t ROVF:1;           /* Reset Overrun Status Flag */
        vuint32_t  :6;
    } B;
} WKPU_NSR_tag;

typedef union WKPU_NSR1_union_tag { /* NMI Status Flag 1 Register */
    vuint32_t R;
    struct {
        vuint32_t NIF3:1;           /* NMI Status Flag 3 (core 3) */
        vuint32_t NOVF3:1;          /* NMI Overrun Status Flag 3 (core 3) */
        vuint32_t  :6;
        vuint32_t NIF4:1;           /* NMI Status Flag 4 (core 4) */
        vuint32_t NOVF4:1;          /* NMI Overrun Status Flag 4 (core 4) */
        vuint32_t  :6;
        vuint32_t NIF5:1;           /* NMI Status Flag 5 (core 5) */
        vuint32_t NOVF5:1;          /* NMI Overrun Status Flag 5 (core 5) */
        vuint32_t  :14;
    } B;
} WKPU_NSR1_tag;

typedef union WKPU_NCR_union_tag {  /* NMI Configuration Register */
    vuint32_t R;
    struct {
        vuint32_t NLOCK0:1;         /* NMI Configuration Lock Register 0 */
        vuint32_t NDSS0:2;          /* NMI Destination Source Select 0 */
        vuint32_t NWRE0:1;          /* NMI Wakeup Request Enable 0 */
        vuint32_t  :1;
        vuint32_t NREE0:1;          /* NMI Rising-edge Events Enable 0 */
        vuint32_t NFEE0:1;          /* NMI Falling-edge Events Enable 0 */
        vuint32_t NFE0:1;           /* NMI Filter Enable */
        vuint32_t NLOCK1:1;         /* NMI Configuration Lock Register 1 */
        vuint32_t NDSS1:2;          /* NMI Destination Source Select 1 */
        vuint32_t NWRE1:1;          /* NMI Wakeup Request Enable 1 */
        vuint32_t  :1;
        vuint32_t NREE1:1;          /* NMI Rising-edge Events Enable 1 */
        vuint32_t NFEE1:1;          /* NMI Falling-edge Events Enable 1 */
        vuint32_t  :1;
        vuint32_t NLOCK2:1;         /* NMI Configuration Lock Register 2 */
        vuint32_t NDSS2:2;          /* NMI Destination Source Select 2 */
        vuint32_t NWRE2:1;          /* NMI Wakeup Request Enable 2 */
        vuint32_t  :1;
        vuint32_t NREE2:1;          /* NMI Rising-edge Events Enable 2 */
        vuint32_t NFEE2:1;          /* NMI Falling-edge Events Enable 2 */
        vuint32_t  :1;
        vuint32_t RLOCK:1;          /* Reset Configuration Lock Register */
        vuint32_t RDSS:2;           /* Reset Destination Source Select */
        vuint32_t RWRE:1;           /* Reset Wakeup Request Enable */
#if defined(CCFC3008PT)
        vuint32_t  :1;
#else
        vuint32_t NMI_IO_MUX:1;     /* NMI input pad select */
#endif
        vuint32_t RREE:1;           /* Reset Rising-edge Events Enable */
        vuint32_t RFEE:1;           /* Reset Falling-edge Events Enable */
        vuint32_t  :1;
    } B;
} WKPU_NCR_tag;

typedef union WKPU_NCR1_union_tag { /* NMI Configuration 1 Register */
    vuint32_t R;
    struct {
        vuint32_t NLOCK3:1;         /* NMI Configuration Lock Register 3 */
        vuint32_t NDSS3:2;          /* NMI Destination Source Select 3 */
        vuint32_t NWRE3:1;          /* NMI Wakeup Request Enable 3 */
        vuint32_t  :1;
        vuint32_t NREE3:1;          /* NMI Rising-edge Events Enable 3 */
        vuint32_t NFEE3:1;          /* NMI Falling-edge Events Enable 3 */
        vuint32_t  :1;
        vuint32_t NLOCK4:1;         /* NMI Configuration Lock Register 4 */
        vuint32_t NDSS4:2;          /* NMI Destination Source Select 4 */
        vuint32_t NWRE4:1;          /* NMI Wakeup Request Enable 4 */
        vuint32_t  :1;
        vuint32_t NREE4:1;          /* NMI Rising-edge Events Enable 4 */
        vuint32_t NFEE4:1;          /* NMI Falling-edge Events Enable 4 */
        vuint32_t  :1;
        vuint32_t NLOCK5:1;         /* NMI Configuration Lock Register 5 */
        vuint32_t NDSS5:2;          /* NMI Destination Source Select 5 */
        vuint32_t NWRE5:1;          /* NMI Wakeup Request Enable 5 */
        vuint32_t  :1;
        vuint32_t NREE5:1;          /* NMI Rising-edge Events Enable 5 */
        vuint32_t NFEE5:1;          /* NMI Falling-edge Events Enable 5 */
        vuint32_t  :9;
    } B;
} WKPU_NCR1_tag;

typedef union WKPU_WISR_union_tag {
    vuint32_t R;
    struct {
        vuint32_t EIF31:1;
        vuint32_t EIF30:1;
        vuint32_t EIF29:1;
        vuint32_t EIF28:1;
        vuint32_t EIF27:1;
        vuint32_t EIF26:1;
        vuint32_t EIF25:1;
        vuint32_t EIF24:1;
        vuint32_t EIF23:1;
        vuint32_t EIF22:1;
        vuint32_t EIF21:1;
        vuint32_t EIF20:1;
        vuint32_t EIF19:1;
        vuint32_t EIF18:1;
        vuint32_t EIF17:1;
        vuint32_t EIF16:1;
        vuint32_t EIF15:1;
        vuint32_t EIF14:1;
        vuint32_t EIF13:1;
        vuint32_t EIF12:1;
        vuint32_t EIF11:1;
        vuint32_t EIF10:1;
        vuint32_t EIF9:1;
        vuint32_t EIF8:1;
        vuint32_t EIF7:1;
        vuint32_t EIF6:1;
        vuint32_t EIF5:1;
        vuint32_t EIF4:1;
        vuint32_t EIF3:1;
        vuint32_t EIF2:1;
        vuint32_t EIF1:1;
        vuint32_t EIF0:1;
    } B;
} WKPU_WISR_tag;

typedef union WKPU_IRER_union_tag {
    vuint32_t R;
    struct {
        vuint32_t EIRE31:1;
        vuint32_t EIRE30:1;
        vuint32_t EIRE29:1;
        vuint32_t EIRE28:1;
        vuint32_t EIRE27:1;
        vuint32_t EIRE26:1;
        vuint32_t EIRE25:1;
        vuint32_t EIRE24:1;
        vuint32_t EIRE23:1;
        vuint32_t EIRE22:1;
        vuint32_t EIRE21:1;
        vuint32_t EIRE20:1;
        vuint32_t EIRE19:1;
        vuint32_t EIRE18:1;
        vuint32_t EIRE17:1;
        vuint32_t EIRE16:1;
        vuint32_t EIRE15:1;
        vuint32_t EIRE14:1;
        vuint32_t EIRE13:1;
        vuint32_t EIRE12:1;
        vuint32_t EIRE11:1;
        vuint32_t EIRE10:1;
        vuint32_t EIRE9:1;
        vuint32_t EIRE8:1;
        vuint32_t EIRE7:1;
        vuint32_t EIRE6:1;
        vuint32_t EIRE5:1;
        vuint32_t EIRE4:1;
        vuint32_t EIRE3:1;
        vuint32_t EIRE2:1;
        vuint32_t EIRE1:1;
        vuint32_t EIRE0:1;
    } B;
} WKPU_IRER_tag;

typedef union WKPU_WRER_union_tag {
    vuint32_t R;
    struct {
        vuint32_t WRE31:1;
        vuint32_t WRE30:1;
        vuint32_t WRE29:1;
        vuint32_t WRE28:1;
        vuint32_t WRE27:1;
        vuint32_t WRE26:1;
        vuint32_t WRE25:1;
        vuint32_t WRE24:1;
        vuint32_t WRE23:1;
        vuint32_t WRE22:1;
        vuint32_t WRE21:1;
        vuint32_t WRE20:1;
        vuint32_t WRE19:1;
        vuint32_t WRE18:1;
        vuint32_t WRE17:1;
        vuint32_t WRE16:1;
        vuint32_t WRE15:1;
        vuint32_t WRE14:1;
        vuint32_t WRE13:1;
        vuint32_t WRE12:1;
        vuint32_t WRE11:1;
        vuint32_t WRE10:1;
        vuint32_t WRE9:1;
        vuint32_t WRE8:1;
        vuint32_t WRE7:1;
        vuint32_t WRE6:1;
        vuint32_t WRE5:1;
        vuint32_t WRE4:1;
        vuint32_t WRE3:1;
        vuint32_t WRE2:1;
        vuint32_t WRE1:1;
        vuint32_t WRE0:1;
    } B;
} WKPU_WRER_tag;

typedef union WKPU_WIREER_union_tag {
    vuint32_t R;
    struct {
        vuint32_t IREE31:1;
        vuint32_t IREE30:1;
        vuint32_t IREE29:1;
        vuint32_t IREE28:1;
        vuint32_t IREE27:1;
        vuint32_t IREE26:1;
        vuint32_t IREE25:1;
        vuint32_t IREE24:1;
        vuint32_t IREE23:1;
        vuint32_t IREE22:1;
        vuint32_t IREE21:1;
        vuint32_t IREE20:1;
        vuint32_t IREE19:1;
        vuint32_t IREE18:1;
        vuint32_t IREE17:1;
        vuint32_t IREE16:1;
        vuint32_t IREE15:1;
        vuint32_t IREE14:1;
        vuint32_t IREE13:1;
        vuint32_t IREE12:1;
        vuint32_t IREE11:1;
        vuint32_t IREE10:1;
        vuint32_t IREE9:1;
        vuint32_t IREE8:1;
        vuint32_t IREE7:1;
        vuint32_t IREE6:1;
        vuint32_t IREE5:1;
        vuint32_t IREE4:1;
        vuint32_t IREE3:1;
        vuint32_t IREE2:1;
        vuint32_t IREE1:1;
        vuint32_t IREE0:1;
    } B;
} WKPU_WIREER_tag;

typedef union WKPU_WIFEER_union_tag {
    vuint32_t R;
    struct {
        vuint32_t IFEE31:1;
        vuint32_t IFEE30:1;
        vuint32_t IFEE29:1;
        vuint32_t IFEE28:1;
        vuint32_t IFEE27:1;
        vuint32_t IFEE26:1;
        vuint32_t IFEE25:1;
        vuint32_t IFEE24:1;
        vuint32_t IFEE23:1;
        vuint32_t IFEE22:1;
        vuint32_t IFEE21:1;
        vuint32_t IFEE20:1;
        vuint32_t IFEE19:1;
        vuint32_t IFEE18:1;
        vuint32_t IFEE17:1;
        vuint32_t IFEE16:1;
        vuint32_t IFEE15:1;
        vuint32_t IFEE14:1;
        vuint32_t IFEE13:1;
        vuint32_t IFEE12:1;
        vuint32_t IFEE11:1;
        vuint32_t IFEE10:1;
        vuint32_t IFEE9:1;
        vuint32_t IFEE8:1;
        vuint32_t IFEE7:1;
        vuint32_t IFEE6:1;
        vuint32_t IFEE5:1;
        vuint32_t IFEE4:1;
        vuint32_t IFEE3:1;
        vuint32_t IFEE2:1;
        vuint32_t IFEE1:1;
        vuint32_t IFEE0:1;
    } B;
} WKPU_WIFEER_tag;

typedef union WKPU_WIFER_union_tag {
    vuint32_t R;
    struct {
        vuint32_t IFE31:1;
        vuint32_t IFE30:1;
        vuint32_t IFE29:1;
        vuint32_t IFE28:1;
        vuint32_t IFE27:1;
        vuint32_t IFE26:1;
        vuint32_t IFE25:1;
        vuint32_t IFE24:1;
        vuint32_t IFE23:1;
        vuint32_t IFE22:1;
        vuint32_t IFE21:1;
        vuint32_t IFE20:1;
        vuint32_t IFE19:1;
        vuint32_t IFE18:1;
        vuint32_t IFE17:1;
        vuint32_t IFE16:1;
        vuint32_t IFE15:1;
        vuint32_t IFE14:1;
        vuint32_t IFE13:1;
        vuint32_t IFE12:1;
        vuint32_t IFE11:1;
        vuint32_t IFE10:1;
        vuint32_t IFE9:1;
        vuint32_t IFE8:1;
        vuint32_t IFE7:1;
        vuint32_t IFE6:1;
        vuint32_t IFE5:1;
        vuint32_t IFE4:1;
        vuint32_t IFE3:1;
        vuint32_t IFE2:1;
        vuint32_t IFE1:1;
        vuint32_t IFE0:1;
    } B;
} WKPU_WIFER_tag;

typedef union WKPU_MUX_union_tag {
    vuint32_t R;
    struct {
        vuint32_t  :2;
        vuint32_t SRC_SEL2_EDGE_INV:1;  /* Wakeup source selector 2: wakeup edge is inverted */
        vuint32_t SRC_SEL2:5;           /* The selection of Wakeup source selector 2 */
        vuint32_t  :2;
        vuint32_t SRC_SEL1_EDGE_INV:1;  /* Wakeup source selector 1: wakeup edge is inverted */
        vuint32_t SRC_SEL1:5;           /* The selection of Wakeup source selector 1 */
        vuint32_t  :2;
        vuint32_t SRC_SEL0_EDGE_INV:1;  /* Wakeup source selector 0: wakeup edge is inverted */
        vuint32_t SRC_SEL0:5;           /* The selection of Wakeup source selector 0 */
        vuint32_t WKP_MUX_SEL:3;        /* Wakeup Multiplex combination: source selector 0/1/2 */
        vuint32_t WKP_MUX_EDGE_INV:1;   /* Wakeup Multiplex combination: wakeup edge is inverted */
        vuint32_t SRC_SEL2_EN:1;        /* Wakeup source selector 2, enable switch */
        vuint32_t SRC_SEL1_EN:1;        /* Wakeup source selector 1, enable switch */
        vuint32_t SRC_SEL0_EN:1;        /* Wakeup source selector 0, enable switch */
        vuint32_t WKP_MUX_EN:1;         /* Wakeup Multiplex combination, enable switch */
    } B;
} WKPU_MUX_tag;

struct WKPU_tag {
    WKPU_NSR_tag NSR;               /* NMI Status Flag Register (Offset: 0x00) */
    WKPU_NSR1_tag NSR1;             /* NMI Status Flag 1 Register (Offset: 0x04) */
    WKPU_NCR_tag NCR;               /* NMI Configuration Register (Offset: 0x08) */
    WKPU_NCR1_tag NCR1;             /* NMI Configuration 1 Register (Offset: 0x0C) */
    uint8_t WKPU_reserved0[4];
    WKPU_WISR_tag WISR0;            /* Wakeup/Interrupt Status Flag Register 0 (Offset: 0x14) */
    WKPU_IRER_tag IRER0;            /* Interrupt Request Enable Register 0 (Offset: 0x18) */
    WKPU_WRER_tag WRER0;            /* Wakeup Request Enable Register 0 (Offset: 0x1C) */
    uint8_t WKPU_reserved1[8];
    WKPU_WIREER_tag WIREER0;        /* Wakeup/Interrupt Rising-Edge Register 0 (Offset: 0x28) */
    WKPU_WIFEER_tag WIFEER0;        /* Wakeup/Interrupt Falling-Edge Register 0 (Offset: 0x2C) */
    WKPU_WIFER_tag WIFER0;          /* Wakeup/Interrupt Filter Enable Register 0 (Offset: 0x30) */
    uint8_t WKPU_reserved2[16];
    WKPU_WISR_tag WISR1;            /* Wakeup/Interrupt Status Flag Register 1 (Offset: 0x44) */
    WKPU_IRER_tag IRER1;            /* Interrupt Request Enable Register 1 (Offset: 0x48) */
    WKPU_WRER_tag WRER1;            /* Wakeup Request Enable Register 1 (Offset: 0x4C) */
    uint8_t WKPU_reserved3[8];
    WKPU_WIREER_tag WIREER1;        /* Wakeup/Interrupt Rising-Edge Register 1 (Offset: 0x58) */
    WKPU_WIFEER_tag WIFEER1;        /* Wakeup/Interrupt Falling-Edge Register 1 (Offset: 0x5C) */
    WKPU_WIFER_tag WIFER1;          /* Wakeup/Interrupt Filter Enable Register 1 (Offset: 0x60) */
    uint8_t WKPU_reserved4[4];
    WKPU_MUX_tag WKPU_MUX;          /* Wakeup Multiplex combination Register (Offset: 0x68) */
};

/* NSR Bit Fields */
#define WKPU_NSR_ROVF_MASK                       0x40u
#define WKPU_NSR_ROVF_SHIFT                      6u
#define WKPU_NSR_ROVF_WIDTH                      1u
#define WKPU_NSR_ROVF(x)                         (((uint32_t)(((uint32_t)(x))<<WKPU_NSR_ROVF_SHIFT))&WKPU_NSR_ROVF_MASK)
#define WKPU_NSR_RIF_MASK                        0x80u
#define WKPU_NSR_RIF_SHIFT                       7u
#define WKPU_NSR_RIF_WIDTH                       1u
#define WKPU_NSR_RIF(x)                          (((uint32_t)(((uint32_t)(x))<<WKPU_NSR_RIF_SHIFT))&WKPU_NSR_RIF_MASK)
#define WKPU_NSR_NOVF2_MASK                      0x4000u
#define WKPU_NSR_NOVF2_SHIFT                     14u
#define WKPU_NSR_NOVF2_WIDTH                     1u
#define WKPU_NSR_NOVF2(x)                        (((uint32_t)(((uint32_t)(x))<<WKPU_NSR_NOVF2_SHIFT))&WKPU_NSR_NOVF2_MASK)
#define WKPU_NSR_NIF2_MASK                       0x8000u
#define WKPU_NSR_NIF2_SHIFT                      15u
#define WKPU_NSR_NIF2_WIDTH                      1u
#define WKPU_NSR_NIF2(x)                         (((uint32_t)(((uint32_t)(x))<<WKPU_NSR_NIF2_SHIFT))&WKPU_NSR_NIF2_MASK)
#define WKPU_NSR_NOVF1_MASK                      0x400000u
#define WKPU_NSR_NOVF1_SHIFT                     22u
#define WKPU_NSR_NOVF1_WIDTH                     1u
#define WKPU_NSR_NOVF1(x)                        (((uint32_t)(((uint32_t)(x))<<WKPU_NSR_NOVF1_SHIFT))&WKPU_NSR_NOVF1_MASK)
#define WKPU_NSR_NIF1_MASK                       0x800000u
#define WKPU_NSR_NIF1_SHIFT                      23u
#define WKPU_NSR_NIF1_WIDTH                      1u
#define WKPU_NSR_NIF1(x)                         (((uint32_t)(((uint32_t)(x))<<WKPU_NSR_NIF1_SHIFT))&WKPU_NSR_NIF1_MASK)
#define WKPU_NSR_NOVF0_MASK                      0x40000000u
#define WKPU_NSR_NOVF0_SHIFT                     30u
#define WKPU_NSR_NOVF0_WIDTH                     1u
#define WKPU_NSR_NOVF0(x)                        (((uint32_t)(((uint32_t)(x))<<WKPU_NSR_NOVF0_SHIFT))&WKPU_NSR_NOVF0_MASK)
#define WKPU_NSR_NIF0_MASK                       0x80000000u
#define WKPU_NSR_NIF0_SHIFT                      31u
#define WKPU_NSR_NIF0_WIDTH                      1u
#define WKPU_NSR_NIF0(x)                         (((uint32_t)(((uint32_t)(x))<<WKPU_NSR_NIF0_SHIFT))&WKPU_NSR_NIF0_MASK)
/* NSR1 Bit Fields */
#define WKPU_NSR1_NOVF5_MASK                     0x4000u
#define WKPU_NSR1_NOVF5_SHIFT                    14u
#define WKPU_NSR1_NOVF5_WIDTH                    1u
#define WKPU_NSR1_NOVF5(x)                       (((uint32_t)(((uint32_t)(x))<<WKPU_NSR1_NOVF5_SHIFT))&WKPU_NSR1_NOVF5_MASK)
#define WKPU_NSR1_NIF5_MASK                      0x8000u
#define WKPU_NSR1_NIF5_SHIFT                     15u
#define WKPU_NSR1_NIF5_WIDTH                     1u
#define WKPU_NSR1_NIF5(x)                        (((uint32_t)(((uint32_t)(x))<<WKPU_NSR1_NIF5_SHIFT))&WKPU_NSR1_NIF5_MASK)
#define WKPU_NSR1_NOVF4_MASK                     0x400000u
#define WKPU_NSR1_NOVF4_SHIFT                    22u
#define WKPU_NSR1_NOVF4_WIDTH                    1u
#define WKPU_NSR1_NOVF4(x)                       (((uint32_t)(((uint32_t)(x))<<WKPU_NSR1_NOVF4_SHIFT))&WKPU_NSR1_NOVF4_MASK)
#define WKPU_NSR1_NIF4_MASK                      0x800000u
#define WKPU_NSR1_NIF4_SHIFT                     23u
#define WKPU_NSR1_NIF4_WIDTH                     1u
#define WKPU_NSR1_NIF4(x)                        (((uint32_t)(((uint32_t)(x))<<WKPU_NSR1_NIF4_SHIFT))&WKPU_NSR1_NIF4_MASK)
#define WKPU_NSR1_NOVF3_MASK                     0x40000000u
#define WKPU_NSR1_NOVF3_SHIFT                    30u
#define WKPU_NSR1_NOVF3_WIDTH                    1u
#define WKPU_NSR1_NOVF3(x)                       (((uint32_t)(((uint32_t)(x))<<WKPU_NSR1_NOVF3_SHIFT))&WKPU_NSR1_NOVF3_MASK)
#define WKPU_NSR1_NIF3_MASK                      0x80000000u
#define WKPU_NSR1_NIF3_SHIFT                     31u
#define WKPU_NSR1_NIF3_WIDTH                     1u
#define WKPU_NSR1_NIF3(x)                        (((uint32_t)(((uint32_t)(x))<<WKPU_NSR1_NIF3_SHIFT))&WKPU_NSR1_NIF3_MASK)
/* NCR Bit Fields */
#define WKPU_NCR_RFEE_MASK                       0x2u
#define WKPU_NCR_RFEE_SHIFT                      1u
#define WKPU_NCR_RFEE_WIDTH                      1u
#define WKPU_NCR_RFEE(x)                         (((uint32_t)(((uint32_t)(x))<<WKPU_NCR_RFEE_SHIFT))&WKPU_NCR_RFEE_MASK)
#define WKPU_NCR_RREE_MASK                       0x4u
#define WKPU_NCR_RREE_SHIFT                      2u
#define WKPU_NCR_RREE_WIDTH                      1u
#define WKPU_NCR_RREE(x)                         (((uint32_t)(((uint32_t)(x))<<WKPU_NCR_RREE_SHIFT))&WKPU_NCR_RREE_MASK)
#if defined(CCFC3008PT)
#else
#define WKPU_NCR_NMI_IO_MUX_MASK                 0x8u
#define WKPU_NCR_NMI_IO_MUX_SHIFT                3u
#define WKPU_NCR_NMI_IO_MUX_WIDTH                1u
#define WKPU_NCR_NMI_IO_MUX(x)                  (((uint32_t)(((uint32_t)(x))<<WKPU_NCR_NMI_IO_MUX_SHIFT))&WKPU_NCR_NMI_IO_MUX_MASK)
#endif
#define WKPU_NCR_RWRE_MASK                       0x10u
#define WKPU_NCR_RWRE_SHIFT                      4u
#define WKPU_NCR_RWRE_WIDTH                      1u
#define WKPU_NCR_RWRE(x)                         (((uint32_t)(((uint32_t)(x))<<WKPU_NCR_RWRE_SHIFT))&WKPU_NCR_RWRE_MASK)
#define WKPU_NCR_RDSS_MASK                       0x60u
#define WKPU_NCR_RDSS_SHIFT                      5u
#define WKPU_NCR_RDSS_WIDTH                      2u
#define WKPU_NCR_RDSS(x)                         (((uint32_t)(((uint32_t)(x))<<WKPU_NCR_RDSS_SHIFT))&WKPU_NCR_RDSS_MASK)
#define WKPU_NCR_RLOCK_MASK                      0x80u
#define WKPU_NCR_RLOCK_SHIFT                     7u
#define WKPU_NCR_RLOCK_WIDTH                     1u
#define WKPU_NCR_RLOCK(x)                        (((uint32_t)(((uint32_t)(x))<<WKPU_NCR_RLOCK_SHIFT))&WKPU_NCR_RLOCK_MASK)
#define WKPU_NCR_NFEE2_MASK                      0x200u
#define WKPU_NCR_NFEE2_SHIFT                     9u
#define WKPU_NCR_NFEE2_WIDTH                     1u
#define WKPU_NCR_NFEE2(x)                        (((uint32_t)(((uint32_t)(x))<<WKPU_NCR_NFEE2_SHIFT))&WKPU_NCR_NFEE2_MASK)
#define WKPU_NCR_NREE2_MASK                      0x400u
#define WKPU_NCR_NREE2_SHIFT                     10u
#define WKPU_NCR_NREE2_WIDTH                     1u
#define WKPU_NCR_NREE2(x)                        (((uint32_t)(((uint32_t)(x))<<WKPU_NCR_NREE2_SHIFT))&WKPU_NCR_NREE2_MASK)
#define WKPU_NCR_NWRE2_MASK                      0x1000u
#define WKPU_NCR_NWRE2_SHIFT                     12u
#define WKPU_NCR_NWRE2_WIDTH                     1u
#define WKPU_NCR_NWRE2(x)                        (((uint32_t)(((uint32_t)(x))<<WKPU_NCR_NWRE2_SHIFT))&WKPU_NCR_NWRE2_MASK)
#define WKPU_NCR_NDSS2_MASK                      0x6000u
#define WKPU_NCR_NDSS2_SHIFT                     13u
#define WKPU_NCR_NDSS2_WIDTH                     2u
#define WKPU_NCR_NDSS2(x)                        (((uint32_t)(((uint32_t)(x))<<WKPU_NCR_NDSS2_SHIFT))&WKPU_NCR_NDSS2_MASK)
#define WKPU_NCR_NLOCK2_MASK                     0x8000u
#define WKPU_NCR_NLOCK2_SHIFT                    15u
#define WKPU_NCR_NLOCK2_WIDTH                    1u
#define WKPU_NCR_NLOCK2(x)                       (((uint32_t)(((uint32_t)(x))<<WKPU_NCR_NLOCK2_SHIFT))&WKPU_NCR_NLOCK2_MASK)
#define WKPU_NCR_NFEE1_MASK                      0x20000u
#define WKPU_NCR_NFEE1_SHIFT                     17u
#define WKPU_NCR_NFEE1_WIDTH                     1u
#define WKPU_NCR_NFEE1(x)                        (((uint32_t)(((uint32_t)(x))<<WKPU_NCR_NFEE1_SHIFT))&WKPU_NCR_NFEE1_MASK)
#define WKPU_NCR_NREE1_MASK                      0x40000u
#define WKPU_NCR_NREE1_SHIFT                     18u
#define WKPU_NCR_NREE1_WIDTH                     1u
#define WKPU_NCR_NREE1(x)                        (((uint32_t)(((uint32_t)(x))<<WKPU_NCR_NREE1_SHIFT))&WKPU_NCR_NREE1_MASK)
#define WKPU_NCR_NWRE1_MASK                      0x100000u
#define WKPU_NCR_NWRE1_SHIFT                     20u
#define WKPU_NCR_NWRE1_WIDTH                     1u
#define WKPU_NCR_NWRE1(x)                        (((uint32_t)(((uint32_t)(x))<<WKPU_NCR_NWRE1_SHIFT))&WKPU_NCR_NWRE1_MASK)
#define WKPU_NCR_NDSS1_MASK                      0x600000u
#define WKPU_NCR_NDSS1_SHIFT                     21u
#define WKPU_NCR_NDSS1_WIDTH                     2u
#define WKPU_NCR_NDSS1(x)                        (((uint32_t)(((uint32_t)(x))<<WKPU_NCR_NDSS1_SHIFT))&WKPU_NCR_NDSS1_MASK)
#define WKPU_NCR_NLOCK1_MASK                     0x800000u
#define WKPU_NCR_NLOCK1_SHIFT                    23u
#define WKPU_NCR_NLOCK1_WIDTH                    1u
#define WKPU_NCR_NLOCK1(x)                       (((uint32_t)(((uint32_t)(x))<<WKPU_NCR_NLOCK1_SHIFT))&WKPU_NCR_NLOCK1_MASK)
#define WKPU_NCR_NFE0_MASK                       0x1000000u
#define WKPU_NCR_NFE0_SHIFT                      24u
#define WKPU_NCR_NFE0_WIDTH                      1u
#define WKPU_NCR_NFE0(x)                         (((uint32_t)(((uint32_t)(x))<<WKPU_NCR_NFE0_SHIFT))&WKPU_NCR_NFE0_MASK)
#define WKPU_NCR_NFEE0_MASK                      0x2000000u
#define WKPU_NCR_NFEE0_SHIFT                     25u
#define WKPU_NCR_NFEE0_WIDTH                     1u
#define WKPU_NCR_NFEE0(x)                        (((uint32_t)(((uint32_t)(x))<<WKPU_NCR_NFEE0_SHIFT))&WKPU_NCR_NFEE0_MASK)
#define WKPU_NCR_NREE0_MASK                      0x4000000u
#define WKPU_NCR_NREE0_SHIFT                     26u
#define WKPU_NCR_NREE0_WIDTH                     1u
#define WKPU_NCR_NREE0(x)                        (((uint32_t)(((uint32_t)(x))<<WKPU_NCR_NREE0_SHIFT))&WKPU_NCR_NREE0_MASK)
#define WKPU_NCR_NWRE0_MASK                      0x10000000u
#define WKPU_NCR_NWRE0_SHIFT                     28u
#define WKPU_NCR_NWRE0_WIDTH                     1u
#define WKPU_NCR_NWRE0(x)                        (((uint32_t)(((uint32_t)(x))<<WKPU_NCR_NWRE0_SHIFT))&WKPU_NCR_NWRE0_MASK)
#define WKPU_NCR_NDSS0_MASK                      0x60000000u
#define WKPU_NCR_NDSS0_SHIFT                     29u
#define WKPU_NCR_NDSS0_WIDTH                     2u
#define WKPU_NCR_NDSS0(x)                        (((uint32_t)(((uint32_t)(x))<<WKPU_NCR_NDSS0_SHIFT))&WKPU_NCR_NDSS0_MASK)
#define WKPU_NCR_NLOCK0_MASK                     0x80000000u
#define WKPU_NCR_NLOCK0_SHIFT                    31u
#define WKPU_NCR_NLOCK0_WIDTH                    1u
#define WKPU_NCR_NLOCK0(x)                       (((uint32_t)(((uint32_t)(x))<<WKPU_NCR_NLOCK0_SHIFT))&WKPU_NCR_NLOCK0_MASK)
/* NCR1 Bit Fields */
#define WKPU_NCR1_NFEE5_MASK                     0x200u
#define WKPU_NCR1_NFEE5_SHIFT                    9u
#define WKPU_NCR1_NFEE5_WIDTH                    1u
#define WKPU_NCR1_NFEE5(x)                       (((uint35_t)(((uint35_t)(x))<<WKPU_NCR1_NFEE5_SHIFT))&WKPU_NCR1_NFEE5_MASK)
#define WKPU_NCR1_NREE5_MASK                     0x400u
#define WKPU_NCR1_NREE5_SHIFT                    10u
#define WKPU_NCR1_NREE5_WIDTH                    1u
#define WKPU_NCR1_NREE5(x)                       (((uint35_t)(((uint35_t)(x))<<WKPU_NCR1_NREE5_SHIFT))&WKPU_NCR1_NREE5_MASK)
#define WKPU_NCR1_NWRE5_MASK                     0x1000u
#define WKPU_NCR1_NWRE5_SHIFT                    12u
#define WKPU_NCR1_NWRE5_WIDTH                    1u
#define WKPU_NCR1_NWRE5(x)                       (((uint35_t)(((uint35_t)(x))<<WKPU_NCR1_NWRE5_SHIFT))&WKPU_NCR1_NWRE5_MASK)
#define WKPU_NCR1_NDSS5_MASK                     0x6000u
#define WKPU_NCR1_NDSS5_SHIFT                    13u
#define WKPU_NCR1_NDSS5_WIDTH                    2u
#define WKPU_NCR1_NDSS5(x)                       (((uint35_t)(((uint35_t)(x))<<WKPU_NCR1_NDSS5_SHIFT))&WKPU_NCR1_NDSS5_MASK)
#define WKPU_NCR1_NLOCK5_MASK                    0x8000u
#define WKPU_NCR1_NLOCK5_SHIFT                   15u
#define WKPU_NCR1_NLOCK5_WIDTH                   1u
#define WKPU_NCR1_NLOCK5(x)                      (((uint35_t)(((uint35_t)(x))<<WKPU_NCR1_NLOCK5_SHIFT))&WKPU_NCR1_NLOCK5_MASK)
#define WKPU_NCR1_NFEE4_MASK                     0x20000u
#define WKPU_NCR1_NFEE4_SHIFT                    17u
#define WKPU_NCR1_NFEE4_WIDTH                    1u
#define WKPU_NCR1_NFEE4(x)                       (((uint32_t)(((uint32_t)(x))<<WKPU_NCR1_NFEE4_SHIFT))&WKPU_NCR1_NFEE4_MASK)
#define WKPU_NCR1_NREE4_MASK                     0x40000u
#define WKPU_NCR1_NREE4_SHIFT                    18u
#define WKPU_NCR1_NREE4_WIDTH                    1u
#define WKPU_NCR1_NREE4(x)                       (((uint32_t)(((uint32_t)(x))<<WKPU_NCR1_NREE4_SHIFT))&WKPU_NCR1_NREE4_MASK)
#define WKPU_NCR1_NWRE4_MASK                     0x100000u
#define WKPU_NCR1_NWRE4_SHIFT                    20u
#define WKPU_NCR1_NWRE4_WIDTH                    1u
#define WKPU_NCR1_NWRE4(x)                       (((uint32_t)(((uint32_t)(x))<<WKPU_NCR1_NWRE4_SHIFT))&WKPU_NCR1_NWRE4_MASK)
#define WKPU_NCR1_NDSS4_MASK                     0x600000u
#define WKPU_NCR1_NDSS4_SHIFT                    21u
#define WKPU_NCR1_NDSS4_WIDTH                    2u
#define WKPU_NCR1_NDSS4(x)                       (((uint32_t)(((uint32_t)(x))<<WKPU_NCR1_NDSS4_SHIFT))&WKPU_NCR1_NDSS4_MASK)
#define WKPU_NCR1_NLOCK4_MASK                    0x800000u
#define WKPU_NCR1_NLOCK4_SHIFT                   23u
#define WKPU_NCR1_NLOCK4_WIDTH                   1u
#define WKPU_NCR1_NLOCK4(x)                      (((uint32_t)(((uint32_t)(x))<<WKPU_NCR1_NLOCK4_SHIFT))&WKPU_NCR1_NLOCK4_MASK)
#define WKPU_NCR1_NFEE3_MASK                     0x2000000u
#define WKPU_NCR1_NFEE3_SHIFT                    25u
#define WKPU_NCR1_NFEE3_WIDTH                    1u
#define WKPU_NCR1_NFEE3(x)                       (((uint32_t)(((uint32_t)(x))<<WKPU_NCR1_NFEE3_SHIFT))&WKPU_NCR1_NFEE3_MASK)
#define WKPU_NCR1_NREE3_MASK                     0x4000000u
#define WKPU_NCR1_NREE3_SHIFT                    26u
#define WKPU_NCR1_NREE3_WIDTH                    1u
#define WKPU_NCR1_NREE3(x)                       (((uint32_t)(((uint32_t)(x))<<WKPU_NCR1_NREE3_SHIFT))&WKPU_NCR1_NREE3_MASK)
#define WKPU_NCR1_NWRE3_MASK                     0x10000000u
#define WKPU_NCR1_NWRE3_SHIFT                    28u
#define WKPU_NCR1_NWRE3_WIDTH                    1u
#define WKPU_NCR1_NWRE3(x)                       (((uint32_t)(((uint32_t)(x))<<WKPU_NCR1_NWRE3_SHIFT))&WKPU_NCR1_NWRE3_MASK)
#define WKPU_NCR1_NDSS3_MASK                     0x60000000u
#define WKPU_NCR1_NDSS3_SHIFT                    29u
#define WKPU_NCR1_NDSS3_WIDTH                    2u
#define WKPU_NCR1_NDSS3(x)                       (((uint32_t)(((uint32_t)(x))<<WKPU_NCR1_NDSS3_SHIFT))&WKPU_NCR1_NDSS3_MASK)
#define WKPU_NCR1_NLOCK3_MASK                    0x80000000u
#define WKPU_NCR1_NLOCK3_SHIFT                   31u
#define WKPU_NCR1_NLOCK3_WIDTH                   1u
#define WKPU_NCR1_NLOCK3(x)                      (((uint32_t)(((uint32_t)(x))<<WKPU_NCR1_NLOCK3_SHIFT))&WKPU_NCR1_NLOCK3_MASK)
/* WISR Bit Fields */
#define WKPU_WISR_EIF_MASK                       0xFFFFFFFFu
#define WKPU_WISR_EIF_SHIFT                      0u
#define WKPU_WISR_EIF_WIDTH                      32u
#define WKPU_WISR_EIF(x)                         (((uint32_t)(((uint32_t)(x))<<WKPU_WISR_EIF_SHIFT))&WKPU_WISR_EIF_MASK)
/* IRER Bit Fields */
#define WKPU_IRER_EIRE_MASK                      0xFFFFFFFFu
#define WKPU_IRER_EIRE_SHIFT                     0u
#define WKPU_IRER_EIRE_WIDTH                     32u
#define WKPU_IRER_EIRE(x)                        (((uint32_t)(((uint32_t)(x))<<WKPU_IRER_EIRE_SHIFT))&WKPU_IRER_EIRE_MASK)
/* WRER Bit Fields */
#define WKPU_WRER_WRE_MASK                       0xFFFFFFFFu
#define WKPU_WRER_WRE_SHIFT                      0u
#define WKPU_WRER_WRE_WIDTH                      32u
#define WKPU_WRER_WRE(x)                         (((uint32_t)(((uint32_t)(x))<<WKPU_WRER_WRE_SHIFT))&WKPU_WRER_WRE_MASK)
/* WIREER Bit Fields */
#define WKPU_WIREER_IREE_MASK                    0xFFFFFFFFu
#define WKPU_WIREER_IREE_SHIFT                   0u
#define WKPU_WIREER_IREE_WIDTH                   32u
#define WKPU_WIREER_IREE(x)                      (((uint32_t)(((uint32_t)(x))<<WKPU_WIREER_IREE_SHIFT))&WKPU_WIREER_IREE_MASK)
/* WIFEER Bit Fields */
#define WKPU_WIFEER_IFEEx_MASK                   0xFFFFFFFFu
#define WKPU_WIFEER_IFEEx_SHIFT                  0u
#define WKPU_WIFEER_IFEEx_WIDTH                  32u
#define WKPU_WIFEER_IFEEx(x)                     (((uint32_t)(((uint32_t)(x))<<WKPU_WIFEER_IFEEx_SHIFT))&WKPU_WIFEER_IFEEx_MASK)
/* WIFER Bit Fields */
#define WKPU_WIFER_IFE_MASK                      0xFFFFFFFFu
#define WKPU_WIFER_IFE_SHIFT                     0u
#define WKPU_WIFER_IFE_WIDTH                     32u
#define WKPU_WIFER_IFE(x)                        (((uint32_t)(((uint32_t)(x))<<WKPU_WIFER_IFE_SHIFT))&WKPU_WIFER_IFE_MASK)
#ifdef WKPU_WIPER_REG
/* WIPER Bit Fields */
#define WKPU_WIPER_IPUE_MASK                     0xFFFFFFFFu
#define WKPU_WIPER_IPUE_SHIFT                    0u
#define WKPU_WIPER_IPUE_WIDTH                    32u
#define WKPU_WIPER_IPUE(x)                       (((uint32_t)(((uint32_t)(x))<<WKPU_WIPER_IPUE_SHIFT))&WKPU_WIPER_IPUE_MASK)
#endif
/* MUX Bit Fields */
#define WKPU_MUX_WKP_MUX_EN_MASK                0x1u
#define WKPU_MUX_WKP_MUX_EN_SHIFT               0u
#define WKPU_MUX_WKP_MUX_EN_WIDTH               1u
#define WKPU_MUX_WKP_MUX_EN(x)                  (((uint32_t)(((uint32_t)(x))<<WKPU_MUX_WKP_MUX_EN_SHIFT))&WKPU_MUX_WKP_MUX_EN_MASK)
#define WKPU_MUX_SRC_SEL0_EN_MASK               0x2u
#define WKPU_MUX_SRC_SEL0_EN_SHIFT              1u
#define WKPU_MUX_SRC_SEL0_EN_WIDTH              1u
#define WKPU_MUX_SRC_SEL0_EN(x)                 (((uint32_t)(((uint32_t)(x))<<WKPU_MUX_SRC_SEL0_EN_SHIFT))&WKPU_MUX_SRC_SEL0_EN_MASK)
#define WKPU_MUX_SRC_SEL1_EN_MASK               0x4u
#define WKPU_MUX_SRC_SEL1_EN_SHIFT              2u
#define WKPU_MUX_SRC_SEL1_EN_WIDTH              1u
#define WKPU_MUX_SRC_SEL1_EN(x)                 (((uint32_t)(((uint32_t)(x))<<WKPU_MUX_SRC_SEL1_EN_SHIFT))&WKPU_MUX_SRC_SEL1_EN_MASK)
#define WKPU_MUX_SRC_SEL2_EN_MASK               0x5u
#define WKPU_MUX_SRC_SEL2_EN_SHIFT              3u
#define WKPU_MUX_SRC_SEL2_EN_WIDTH              1u
#define WKPU_MUX_SRC_SEL2_EN(x)                 (((uint32_t)(((uint32_t)(x))<<WKPU_MUX_SRC_SEL2_EN_SHIFT))&WKPU_MUX_SRC_SEL2_EN_MASK)
#define WKPU_MUX_WKP_MUX_EDGE_INV_MASK          0x10u
#define WKPU_MUX_WKP_MUX_EDGE_INV_SHIFT         4u
#define WKPU_MUX_WKP_MUX_EDGE_INV_WIDTH         1u
#define WKPU_MUX_WKP_MUX_EDGE_INV(x)            (((uint32_t)(((uint32_t)(x))<<WKPU_MUX_WKP_MUX_EDGE_INV_SHIFT))&WKPU_MUX_WKP_MUX_EDGE_INV_MASK)
#define WKPU_MUX_WKP_MUX_SEL_MASK               0xE0u
#define WKPU_MUX_WKP_MUX_SEL_SHIFT              5u
#define WKPU_MUX_WKP_MUX_SEL_WIDTH              3u
#define WKPU_MUX_WKP_MUX_SEL(x)                 (((uint32_t)(((uint32_t)(x))<<WKPU_MUX_WKP_MUX_SEL_SHIFT))&WKPU_MUX_WKP_MUX_SEL_MASK)
#define WKPU_MUX_SRC_SEL0_MASK                  0x1F00u
#define WKPU_MUX_SRC_SEL0_SHIFT                 8u
#define WKPU_MUX_SRC_SEL0_WIDTH                 5u
#define WKPU_MUX_SRC_SEL0(x)                    (((uint32_t)(((uint32_t)(x))<<WKPU_MUX_SRC_SEL0_SHIFT))&WKPU_MUX_SRC_SEL0_MASK)
#define WKPU_MUX_SRC_SEL0_EDGE_INV_MASK         0x2000u
#define WKPU_MUX_SRC_SEL0_EDGE_INV_SHIFT        13u
#define WKPU_MUX_SRC_SEL0_EDGE_INV_WIDTH        1u
#define WKPU_MUX_SRC_SEL0_EDGE_INV(x)           (((uint32_t)(((uint32_t)(x))<<WKPU_MUX_SRC_SEL0_EDGE_INV_SHIFT))&WKPU_MUX_SRC_SEL0_EDGE_INV_MASK)
#define WKPU_MUX_SRC_SEL1_MASK                  0x1F0000u
#define WKPU_MUX_SRC_SEL1_SHIFT                 16u
#define WKPU_MUX_SRC_SEL1_WIDTH                 5u
#define WKPU_MUX_SRC_SEL1(x)                    (((uint32_t)(((uint32_t)(x))<<WKPU_MUX_SRC_SEL1_SHIFT))&WKPU_MUX_SRC_SEL1_MASK)
#define WKPU_MUX_SRC_SEL1_EDGE_INV_MASK         0x200000u
#define WKPU_MUX_SRC_SEL1_EDGE_INV_SHIFT        21u
#define WKPU_MUX_SRC_SEL1_EDGE_INV_WIDTH        1u
#define WKPU_MUX_SRC_SEL1_EDGE_INV(x)           (((uint32_t)(((uint32_t)(x))<<WKPU_MUX_SRC_SEL1_EDGE_INV_SHIFT))&WKPU_MUX_SRC_SEL1_EDGE_INV_MASK)
#define WKPU_MUX_SRC_SEL2_MASK                  0x1F000000u
#define WKPU_MUX_SRC_SEL2_SHIFT                 24u
#define WKPU_MUX_SRC_SEL2_WIDTH                 5u
#define WKPU_MUX_SRC_SEL2(x)                    (((uint32_t)(((uint32_t)(x))<<WKPU_MUX_SRC_SEL2_SHIFT))&WKPU_MUX_SRC_SEL2_MASK)
#define WKPU_MUX_SRC_SEL2_EDGE_INV_MASK         0x20000000u
#define WKPU_MUX_SRC_SEL2_EDGE_INV_SHIFT        29u
#define WKPU_MUX_SRC_SEL2_EDGE_INV_WIDTH        1u
#define WKPU_MUX_SRC_SEL2_EDGE_INV(x)           (((uint32_t)(((uint32_t)(x))<<WKPU_MUX_SRC_SEL2_EDGE_INV_SHIFT))&WKPU_MUX_SRC_SEL2_EDGE_INV_MASK)

#endif  /* WKPU_REG_H_ */
