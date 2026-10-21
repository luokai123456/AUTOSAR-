#ifndef SDADC_REG_H_
#define SDADC_REG_H_

/* ============================================================================
   =============================== Module: SDADC ==============================
   ============================================================================ */

typedef union SDADC_CTRL_union_tag {    /* SDADC Control Register */
    vuint32_t R;
    struct {
        vuint32_t  :31;
        vuint32_t SDADC_EN:1;
    } B;
} SDADC_CTRL_tag;

typedef union SDADC_GAINCORR_union_tag {    /* SDADC Gain Correction Register */
    vuint32_t R;
    struct {
        vuint32_t  :11;
        vuint32_t CICSHIFT:5;
        vuint32_t  :3;
        vuint32_t GAINFACTOR:13;
    } B;
} SDADC_GAINCORR_tag;

typedef union SDADC_GAINCAL_union_tag { /* SDADC Gain Calibration Register */
    vuint32_t R;
    struct {
        vuint32_t  :19;
        vuint32_t CALFACTOR:13;
    } B;
} SDADC_GAINCAL_tag;

typedef union SDADC_FCFGC_union_tag {   /* SDADC Filter Configuration Register, CIC Filter */
    vuint32_t R;
    struct {
        vuint32_t  :7;
        vuint32_t CFMSV:9;
        vuint32_t  :7;
        vuint32_t CFMDF:9;
    } B;
} SDADC_FCFGC_tag;

typedef union SDADC_FCNTC_union_tag {   /* SDADC Filter Counter Register, CIC Filter */
    vuint32_t R;
    struct {
        vuint32_t  :23;
        vuint32_t CFMDCNT:9;
    } B;
} SDADC_FCNTC_tag;

typedef union SDADC_FCFGM_union_tag {   /* SDADC Filter Configuration Register, Main */
    vuint32_t R;
    struct {
        vuint32_t  :15;
        vuint32_t CALIB_EN:1;
        vuint32_t  :3;
        vuint32_t DIFF_EN:1;
        vuint32_t CH_WRAP_EN:1;
        vuint32_t OCEN:3;
        vuint32_t EXT_MESH_EN:1;
        vuint32_t COMPTR_EN:1;
        vuint32_t PFEN:1;
        vuint32_t CICMOD:1;
        vuint32_t FIR1DEC:1;
        vuint32_t OVCEN:1;
        vuint32_t FIR1EN:1;
        vuint32_t FIR0EN:1;
    } B;
} SDADC_FCFGM_tag;

typedef union SDADC_OFFCOMP_union_tag { /* SDADC Offset Compensation Register */
    vuint32_t R;
    struct {
        vuint32_t  :16;
        vuint32_t OFFSET:16;
    } B;
} SDADC_OFFCOMP_tag;

typedef union SDADC_IECFG_union_tag {   /* SDADC Interrupt Enable Configuration Register */
    vuint32_t R;
    struct {
        vuint32_t  :28;
        vuint32_t DMA_REQ_EN:1;
        vuint32_t DOV_INT_EN:1;
        vuint32_t FOV_INT_EN:1;
        vuint32_t FWM_INT_EN:1;
    } B;
} SDADC_IECFG_tag;

typedef union SDADC_FCFG_union_tag {    /* SDADC FIFO Configuration Register */
    vuint32_t R;
    struct {
        vuint32_t  :14;
        vuint32_t SIGNEN:1;
        vuint32_t INFOEN:1;
        vuint32_t FIFOWM:8;
        vuint32_t FIFOSIZE:8;
    } B;
} SDADC_FCFG_tag;

typedef union SDADC_FDATA_union_tag {   /* SDADC FIFO Data Register */
    vuint32_t R;
    struct {
        vuint32_t DATA:32;
    } B;
} SDADC_FDATA_tag;

typedef union SDADC_ISTAT_union_tag {   /* SDADC Integrator Status Register */
    vuint32_t R;
    struct {
        vuint32_t  :16;
        vuint32_t INTEN:1;
        vuint32_t  :3;
        vuint32_t REPCNT:4;
        vuint32_t  :2;
        vuint32_t NVALCNT:6;
    } B;
} SDADC_ISTAT_tag;

typedef union SDADC_IIVAL_union_tag {   /* SDADC Intermediate Integration Value Register */
    vuint32_t R;
    struct {
        vuint32_t  :6;
        vuint32_t IVAL:26;
    } B;
} SDADC_IIVAL_tag;

typedef union SDADC_IWCTR_union_tag {   /* SDADC Integration Window Control Register */
    vuint32_t R;
    struct {
        vuint32_t  :2;
        vuint32_t NVALINT:6;
        vuint32_t  :2;
        vuint32_t NVALDIS:6;
        vuint32_t  :4;
        vuint32_t REPVAL:4;
        vuint32_t  :2;
        vuint32_t FRC:1;
        vuint32_t IWS:1;
        vuint32_t  :1;
        vuint32_t ISC:3;
    } B;
} SDADC_IWCTR_tag;

typedef union SDADC_DICFG_union_tag {   /* SDADC Demodulator Input Configuration Register */
    vuint32_t R;
    struct {
        vuint32_t  :10;
        vuint32_t ITRMODE:2;
        vuint32_t  :20;
    } B;
} SDADC_DICFG_tag;

typedef union SDADC_BOUNDSEL_union_tag {    /* SDADC Boundary Select Register */
    vuint32_t R;
    struct {
        vuint32_t BOUNDARYU:16;
        vuint32_t BOUNDARYL:16;
    } B;
} SDADC_BOUNDSEL_tag;

typedef union SDADC_WMINTSTAT_union_tag {   /* SDADC WaterMarker Interrupt State Register */
    vuint32_t R;
    struct {
        vuint32_t  :31;
        vuint32_t FWM_INT:1;
    } B;
} SDADC_WMINTSTAT_tag;

typedef union SDADC_OVINTSTAT_union_tag {   /* SDADC OverFlow Interrupt State Register */
    vuint32_t R;
    struct {
        vuint32_t  :30;
        vuint32_t DOV_INT:1;
        vuint32_t FOV_INT:1;
    } B;
} SDADC_OVINTSTAT_tag;

typedef union SDADC_OVSCFG_union_tag {  /* SDADC Overshoot Compensation Configuration Register */
    vuint32_t R;
    struct {
        vuint32_t  :5;
        vuint32_t SDTH:11;
        vuint32_t  :11;
        vuint32_t SDM:1;
        vuint32_t SRFRT:2;
        vuint32_t SRFS:2;
    } B;
} SDADC_OVSCFG_tag;

typedef union SDADC_HTCFG_union_tag {   /* SDADC Hardware Trigger Configuration Register */
    vuint32_t R;
    struct {
        vuint32_t HT15:2;
        vuint32_t HT14:2;
        vuint32_t HT13:2;
        vuint32_t HT12:2;
        vuint32_t HT11:2;
        vuint32_t HT10:2;
        vuint32_t HT9:2;
        vuint32_t HT8:2;
        vuint32_t HT7:2;
        vuint32_t HT6:2;
        vuint32_t HT5:2;
        vuint32_t HT4:2;
        vuint32_t HT3:2;
        vuint32_t HT2:2;
        vuint32_t HT1:2;
        vuint32_t HT0:2;
    } B;
} SDADC_HTCFG_tag;

typedef union SDADC_STCFG_union_tag {   /* SDADC Software Trigger Configuration Register */
    vuint32_t R;
    struct {
        vuint32_t  :29;
        vuint32_t FSRSTN:1;
        vuint32_t SH_CLR:1;
        vuint32_t SH_EN:1;
    } B;
} SDADC_STCFG_tag;

typedef union SDADC_FCDIS_union_tag {   /* SDADC Filter Chain Discard Register */
    vuint32_t R;
    struct {
        vuint32_t  :16;
        vuint32_t FCDIS_NUM:8;
        vuint32_t  :7;
        vuint32_t FCDIS_EN:1;
    } B;
} SDADC_FCDIS_tag;

typedef union SDADC_CH_WRAP_union_tag { /* SDADC Channel default & wrap Register */
    vuint32_t R;
    struct {
        vuint32_t  :12;
        vuint32_t CH_NUM:4;
        vuint32_t  :12;
        vuint32_t CH_DFLT:4;
    } B;
} SDADC_CH_WRAP_tag;

typedef union SDADC_DOV_INFO_union_tag {    /* SDADC Data OverFlow Information Register */
    vuint32_t R;
    struct {
        vuint32_t  :8;
        vuint32_t CH_INFO:4;
        vuint32_t  :2;
        vuint32_t COMPTR_OVF:1;
        vuint32_t COMPTR_UVF:1;
        vuint32_t DATA:16;
    } B;
} SDADC_DOV_INFO_tag;

typedef union SDADC_BIAS_union_tag {
    vuint32_t R;
    struct {
        vuint32_t  :28;
        vuint32_t TEST_BIAS_LV:1;
        vuint32_t BIAS_RES_TRIM_LV:3;
    } B;
} SDADC_BIAS_tag;

typedef union SDADC_RES_union_tag {
    vuint32_t R;
    struct {
        vuint32_t  :8;
        vuint32_t RES_P_LV:8;
        vuint32_t  :8;
        vuint32_t RES_N_LV:8;
    } B;
} SDADC_RES_tag;

typedef union SDADC_ATT_union_tag {
    vuint32_t R;
    struct {
        vuint32_t  :13;
        vuint32_t ADC_DIV_LV:3;
        vuint32_t  :7;
        vuint32_t VCOM_SEL_LV:1;
        vuint32_t  :3;
        vuint32_t GAIN_LV:5;
    } B;
} SDADC_ATT_tag;

struct SDADC_tag {
    SDADC_CTRL_tag CTRL;                /* SDADC Control Register */
    SDADC_GAINCORR_tag GAINCORR;        /* SDADC Gain Correction Register */
    SDADC_GAINCAL_tag GAINCAL;          /* SDADC Gain Calibration Register */
    SDADC_FCFGC_tag FCFGC;              /* SDADC Filter Configuration Register, CIC Filter */
    SDADC_FCNTC_tag FCNTC;              /* SDADC Filter Counter Register, CIC Filter */
    SDADC_FCFGM_tag FCFGM;              /* SDADC Filter Configuration Register, Main */
    SDADC_OFFCOMP_tag OFFCOMP;          /* SDADC Offset Compensation Register */
    SDADC_IECFG_tag IECFG;              /* SDADC Interrupt Enable Configuration Register */
    SDADC_FCFG_tag FCFG;                /* SDADC FIFO Configuration Register */
    SDADC_FDATA_tag FDATA;              /* SDADC FIFO Data Register */
    SDADC_ISTAT_tag ISTAT;              /* SDADC Integrator Status Register */
    SDADC_IIVAL_tag IIVAL;              /* SDADC Intermediate Integration Value Register */
    SDADC_IWCTR_tag IWCTR;              /* SDADC Integration Window Control Register */
    SDADC_DICFG_tag DICFG;              /* SDADC Demodulator Input Configuration Register */
    SDADC_BOUNDSEL_tag BOUNDSEL;        /* SDADC Boundary Select Register */
    SDADC_WMINTSTAT_tag WMINTSTAT;      /* SDADC WaterMarker Interrupt State Register */
    SDADC_OVINTSTAT_tag OVINTSTAT;      /* SDADC OverFlow Interrupt State Register */
    SDADC_OVSCFG_tag OVSCFG;            /* SDADC Overshoot Compensation Configuration Register */
    SDADC_HTCFG_tag HTCFG;              /* SDADC Hardware Trigger Configuration Register */
    SDADC_STCFG_tag STCFG;              /* SDADC Software Trigger Configuration Register */
    SDADC_FCDIS_tag FCDIS;              /* SDADC Filter Chain Discard Register */
    SDADC_CH_WRAP_tag CH_WRAP;          /* SDADC Channel default & wrap Register */
    SDADC_DOV_INFO_tag DOV_INFO;        /* SDADC Data OverFlow Information Register */
    uint8_t SDADC_reserved0[4];
    SDADC_BIAS_tag BIAS;                /* SDADC BIAS Register (Test use only) */
    SDADC_RES_tag RES;                  /* SDADC Analog Channel Resistor Select Register */
    SDADC_ATT_tag ATT;                  /* SDADC Analog Module Configuration Register */
};

typedef struct SDADC_tag SDADC_TagType;

/*******************************************************************************
 * SDADC Register Bit Fields
 *******************************************************************************/
/* CTRL Bit Fields */
#define SDADC_CTRL_EN_MASK                      0x1u
#define SDADC_CTRL_EN_SHIFT                     0u
#define SDADC_CTRL_EN_WIDTH                     1u
#define SDADC_CTRL_EN(x)                        (((uint32_t)(((uint32_t)(x))<<SDADC_CTRL_EN_SHIFT))&SDADC_CTRL_EN_MASK)
/* GAINCORR Bit Fields */
#define SDADC_GAINCORR_GAINFACTOR_MASK          0x1FFFu
#define SDADC_GAINCORR_GAINFACTOR_SHIFT         0u
#define SDADC_GAINCORR_GAINFACTOR_WIDTH         13u
#define SDADC_GAINCORR_GAINFACTOR(x)            (((uint32_t)(((uint32_t)(x))<<SDADC_GAINCORR_GAINFACTOR_SHIFT))&SDADC_GAINCORR_GAINFACTOR_MASK)
#define SDADC_GAINCORR_CICSHIFT_MASK            0x1F0000u
#define SDADC_GAINCORR_CICSHIFT_SHIFT           16u
#define SDADC_GAINCORR_CICSHIFT_WIDTH           5u
#define SDADC_GAINCORR_CICSHIFT(x)              (((uint32_t)(((uint32_t)(x))<<SDADC_GAINCORR_CICSHIFT_SHIFT))&SDADC_GAINCORR_CICSHIFT_MASK)
/* GAINCAL Bit Fields */
#define SDADC_GAINCAL_CALFACTOR_MASK            0x1FFFu
#define SDADC_GAINCAL_CALFACTOR_SHIFT           0u
#define SDADC_GAINCAL_CALFACTOR_WIDTH           13u
#define SDADC_GAINCAL_CALFACTOR(x)              (((uint32_t)(((uint32_t)(x))<<SDADC_GAINCAL_CALFACTOR_SHIFT))&SDADC_GAINCAL_CALFACTOR_MASK)
/* FCFGC Bit Fields */
#define SDADC_FCFGC_CFMDF_MASK                  0x1FFu
#define SDADC_FCFGC_CFMDF_SHIFT                 0u
#define SDADC_FCFGC_CFMDF_WIDTH                 9u
#define SDADC_FCFGC_CFMDF(x)                    (((uint32_t)(((uint32_t)(x))<<SDADC_FCFGC_CFMDF_SHIFT))&SDADC_FCFGC_CFMDF_MASK)
#define SDADC_FCFGC_CFMSV_MASK                  0x1FF0000u
#define SDADC_FCFGC_CFMSV_SHIFT                 16u
#define SDADC_FCFGC_CFMSV_WIDTH                 9u
#define SDADC_FCFGC_CFMSV(x)                   (((uint32_t)(((uint32_t)(x))<<SDADC_FCFGC_CFMSV_SHIFT))&SDADC_FCFGC_CFMSV_MASK)
/* FCNTC Bit Fields */
#define SDADC_FCNTC_CFMDCNT_MASK                0x1FFu
#define SDADC_FCNTC_CFMDCNT_SHIFT               0u
#define SDADC_FCNTC_CFMDCNT_WIDTH               9u
#define SDADC_FCNTC_CFMDCNT(x)                  (((uint32_t)(((uint32_t)(x))<<SDADC_FCNTC_CFMDCNT_SHIFT))&SDADC_FCNTC_CFMDCNT_MASK)
/* FCFGM Bit Fields */
#define SDADC_FCFGM_FIR0EN_MASK                 0x1u
#define SDADC_FCFGM_FIR0EN_SHIFT                0u
#define SDADC_FCFGM_FIR0EN_WIDTH                1u
#define SDADC_FCFGM_FIR0EN(x)                   (((uint32_t)(((uint32_t)(x))<<SDADC_FCFGM_FIR0EN_SHIFT))&SDADC_FCFGM_FIR0EN_MASK)
#define SDADC_FCFGM_FIR1EN_MASK                 0x2u
#define SDADC_FCFGM_FIR1EN_SHIFT                1u
#define SDADC_FCFGM_FIR1EN_WIDTH                1u
#define SDADC_FCFGM_FIR1EN(x)                   (((uint32_t)(((uint32_t)(x))<<SDADC_FCFGM_FIR1EN_SHIFT))&SDADC_FCFGM_FIR1EN_MASK)
#define SDADC_FCFGM_OVCEN_MASK                  0x4u
#define SDADC_FCFGM_OVCEN_SHIFT                 2u
#define SDADC_FCFGM_OVCEN_WIDTH                 1u
#define SDADC_FCFGM_OVCEN(x)                    (((uint32_t)(((uint32_t)(x))<<SDADC_FCFGM_OVCEN_SHIFT))&SDADC_FCFGM_OVCEN_MASK)
#define SDADC_FCFGM_FIR1DEC_MASK                0x8u
#define SDADC_FCFGM_FIR1DEC_SHIFT               3u
#define SDADC_FCFGM_FIR1DEC_WIDTH               1u
#define SDADC_FCFGM_FIR1DEC(x)                  (((uint32_t)(((uint32_t)(x))<<SDADC_FCFGM_FIR1DEC_SHIFT))&SDADC_FCFGM_FIR1DEC_MASK)
#define SDADC_FCFGM_CICMOD_MASK                 0x10u
#define SDADC_FCFGM_CICMOD_SHIFT                4u
#define SDADC_FCFGM_CICMOD_WIDTH                1u
#define SDADC_FCFGM_CICMOD(x)                   (((uint32_t)(((uint32_t)(x))<<SDADC_FCFGM_CICMOD_SHIFT))&SDADC_FCFGM_CICMOD_MASK)
#define SDADC_FCFGM_PFEN_MASK                   0x20u
#define SDADC_FCFGM_PFEN_SHIFT                  5u
#define SDADC_FCFGM_PFEN_WIDTH                  1u
#define SDADC_FCFGM_PFEN(x)                     (((uint32_t)(((uint32_t)(x))<<SDADC_FCFGM_PFEN_SHIFT))&SDADC_FCFGM_PFEN_MASK)
#define SDADC_FCFGM_COMPTR_EN_MASK              0x40u
#define SDADC_FCFGM_COMPTR_EN_SHIFT             6u
#define SDADC_FCFGM_COMPTR_EN_WIDTH             1u
#define SDADC_FCFGM_COMPTR_EN(x)                (((uint32_t)(((uint32_t)(x))<<SDADC_FCFGM_COMPTR_EN_SHIFT))&SDADC_FCFGM_COMPTR_EN_MASK)
#define SDADC_FCFGM_EXT_MESH_EN_MASK            0x80u
#define SDADC_FCFGM_EXT_MESH_EN_SHIFT           7u
#define SDADC_FCFGM_EXT_MESH_EN_WIDTH           1u
#define SDADC_FCFGM_EXT_MESH_EN(x)              (((uint32_t)(((uint32_t)(x))<<SDADC_FCFGM_EXT_MESH_EN_SHIFT))&SDADC_FCFGM_EXT_MESH_EN_MASK)
#define SDADC_FCFGM_OCEN_MASK                   0x700u
#define SDADC_FCFGM_OCEN_SHIFT                  8u
#define SDADC_FCFGM_OCEN_WIDTH                  3u
#define SDADC_FCFGM_OCEN(x)                     (((uint32_t)(((uint32_t)(x))<<SDADC_FCFGM_OCEN_SHIFT))&SDADC_FCFGM_OCEN_MASK)
#define SDADC_FCFGM_CH_WRAP_EN_MASK             0x800u
#define SDADC_FCFGM_CH_WRAP_EN_SHIFT            11u
#define SDADC_FCFGM_CH_WRAP_EN_WIDTH            1u
#define SDADC_FCFGM_CH_WRAP_EN(x)               (((uint32_t)(((uint32_t)(x))<<SDADC_FCFGM_CH_WRAP_EN_SHIFT))&SDADC_FCFGM_CH_WRAP_EN_MASK)
#define SDADC_FCFGM_DIFF_EN_MASK                0x1000u
#define SDADC_FCFGM_DIFF_EN_SHIFT               12u
#define SDADC_FCFGM_DIFF_EN_WIDTH               1u
#define SDADC_FCFGM_DIFF_EN(x)                  (((uint32_t)(((uint32_t)(x))<<SDADC_FCFGM_DIFF_EN_SHIFT))&SDADC_FCFGM_DIFF_EN_MASK)
#define SDADC_FCFGM_CALIB_EN_MASK               0x10000u
#define SDADC_FCFGM_CALIB_EN_SHIFT              16u
#define SDADC_FCFGM_CALIB_EN_WIDTH              1u
#define SDADC_FCFGM_CALIB_EN(x)                 (((uint32_t)(((uint32_t)(x))<<SDADC_FCFGM_CALIB_EN_SHIFT))&SDADC_FCFGM_CALIB_EN_MASK)
/* OFFCOMP Bit Fields */
#define SDADC_OFFCOMP_OFFSET_MASK               0xFFFFu
#define SDADC_OFFCOMP_OFFSET_SHIFT              0u
#define SDADC_OFFCOMP_OFFSET_WIDTH              16u
#define SDADC_OFFCOMP_OFFSET(x)                 (((uint32_t)(((uint32_t)(x))<<SDADC_OFFCOMP_OFFSET_SHIFT))&SDADC_OFFCOMP_OFFSET_MASK)
/* IECFG Bit Fields */
#define SDADC_IECFG_FWM_INT_EN_MASK             0x1u
#define SDADC_IECFG_FWM_INT_EN_SHIFT            0u
#define SDADC_IECFG_FWM_INT_EN_WIDTH            1u
#define SDADC_IECFG_FWM_INT_EN(x)               (((uint32_t)(((uint32_t)(x))<<SDADC_IECFG_FWM_INT_EN_SHIFT))&SDADC_IECFG_FWM_INT_EN_MASK)
#define SDADC_IECFG_FOV_INT_EN_MASK             0x2u
#define SDADC_IECFG_FOV_INT_EN_SHIFT            1u
#define SDADC_IECFG_FOV_INT_EN_WIDTH            1u
#define SDADC_IECFG_FOV_INT_EN(x)               (((uint32_t)(((uint32_t)(x))<<SDADC_IECFG_FOV_INT_EN_SHIFT))&SDADC_IECFG_FOV_INT_EN_MASK)
#define SDADC_IECFG_DOV_INT_EN_MASK             0x4u
#define SDADC_IECFG_DOV_INT_EN_SHIFT            2u
#define SDADC_IECFG_DOV_INT_EN_WIDTH            1u
#define SDADC_IECFG_DOV_INT_EN(x)               (((uint32_t)(((uint32_t)(x))<<SDADC_IECFG_DOV_INT_EN_SHIFT))&SDADC_IECFG_DOV_INT_EN_MASK)
#define SDADC_IECFG_DMA_REQ_EN_MASK             0x8u
#define SDADC_IECFG_DMA_REQ_EN_SHIFT            3u
#define SDADC_IECFG_DMA_REQ_EN_WIDTH            1u
#define SDADC_IECFG_DMA_REQ_EN(x)               (((uint32_t)(((uint32_t)(x))<<SDADC_IECFG_DMA_REQ_EN_SHIFT))&SDADC_IECFG_DMA_REQ_EN_WIDTH)
/* FCFG Bit Fields */
#define SDADC_FCFG_FIFOSIZE_MASK                0xFFu
#define SDADC_FCFG_FIFOSIZE_SHIFT               0u
#define SDADC_FCFG_FIFOSIZE_WIDTH               8u
#define SDADC_FCFG_FIFOSIZE(x)                  (((uint32_t)(((uint32_t)(x))<<SDADC_FCFG_FIFOSIZE_SHIFT))&SDADC_FCFG_FIFOSIZE_MASK)
#define SDADC_FCFG_FIFOWM_MASK                  0xFF00u
#define SDADC_FCFG_FIFOWM_SHIFT                 8u
#define SDADC_FCFG_FIFOWM_WIDTH                 8u
#define SDADC_FCFG_FIFOWM(x)                    (((uint32_t)(((uint32_t)(x))<<SDADC_FCFG_FIFOWM_SHIFT))&SDADC_FCFG_FIFOWM_MASK)
#define SDADC_FCFG_INFOEN_MASK                  0x10000u
#define SDADC_FCFG_INFOEN_SHIFT                 16u
#define SDADC_FCFG_INFOEN_WIDTH                 1u
#define SDADC_FCFG_INFOEN(x)                    (((uint32_t)(((uint32_t)(x))<<SDADC_FCFG_INFOEN_SHIFT))&SDADC_FCFG_INFOEN_MASK)
#define SDADC_FCFG_SIGNEN_MASK                  0x20000u
#define SDADC_FCFG_SIGNEN_SHIFT                 17u
#define SDADC_FCFG_SIGNEN_WIDTH                 1u
#define SDADC_FCFG_SIGNEN(x)                    (((uint32_t)(((uint32_t)(x))<<SDADC_FCFG_SIGNEN_SHIFT))&SDADC_FCFG_SIGNEN_MASK)
/* FDATA Bit Fields */
#define SDADC_FDATA_DATA_MASK                   0xFFFFFFFFu
#define SDADC_FDATA_DATA_SHIFT                  0u
#define SDADC_FDATA_DATA_WIDTH                  32u
#define SDADC_FDATA_DATA(x)                     (((uint32_t)(((uint32_t)(x))<<SDADC_FDATA_DATA_SHIFT))&SDADC_FDATA_DATA_MASK)
/* ISTAT Bit Fields */
#define SDADC_ISTAT_NVALCNT_MASK                0x3Fu
#define SDADC_ISTAT_NVALCNT_SHIFT               0u
#define SDADC_ISTAT_NVALCNT_WIDTH               6u
#define SDADC_ISTAT_NVALCNT(x)                  (((uint32_t)(((uint32_t)(x))<<SDADC_ISTAT_NVALCNT_SHIFT))&SDADC_ISTAT_NVALCNT_MASK)
#define SDADC_ISTAT_REPCNT_MASK                 0xF00u
#define SDADC_ISTAT_REPCNT_SHIFT                8u
#define SDADC_ISTAT_REPCNT_WIDTH                4u
#define SDADC_ISTAT_REPCNT(x)                   (((uint32_t)(((uint32_t)(x))<<SDADC_ISTAT_REPCNT_SHIFT))&SDADC_ISTAT_REPCNT_MASK)
#define SDADC_ISTAT_INTEN_MASK                  0x8000u
#define SDADC_ISTAT_INTEN_SHIFT                 15u
#define SDADC_ISTAT_INTEN_WIDTH                 1u
#define SDADC_ISTAT_INTEN(x)                    (((uint32_t)(((uint32_t)(x))<<SDADC_ISTAT_INTEN_SHIFT))&SDADC_ISTAT_INTEN_MASK)
/* IIVAL Bit Fields */
#define SDADC_IIVAL_IVAL_MASK                   0x3FFFFFFu
#define SDADC_IIVAL_IVAL_SHIFT                  0u
#define SDADC_IIVAL_IVAL_WIDTH                  26u
#define SDADC_IIVAL_IVAL(x)                     (((uint32_t)(((uint32_t)(x))<<SDADC_IIVAL_IVAL_SHIFT))&SDADC_IIVAL_IVAL_MASK)
/* IWCTR Bit Fields */
#define SDADC_IWCTR_ISC_MASK                    0x7u
#define SDADC_IWCTR_ISC_SHIFT                   0u
#define SDADC_IWCTR_ISC_WIDTH                   3u
#define SDADC_IWCTR_ISC(x)                      (((uint32_t)(((uint32_t)(x))<<SDADC_IWCTR_ISC_SHIFT))&SDADC_IWCTR_ISC_MASK)
#define SDADC_IWCTR_IWS_MASK                    0x10u
#define SDADC_IWCTR_IWS_SHIFT                   4u
#define SDADC_IWCTR_IWS_WIDTH                   1u
#define SDADC_IWCTR_IWS(x)                      (((uint32_t)(((uint32_t)(x))<<SDADC_IWCTR_IWS_SHIFT))&SDADC_IWCTR_IWS_MASK)
#define SDADC_IWCTR_FRC_MASK                    0x20u
#define SDADC_IWCTR_FRC_SHIFT                   5u
#define SDADC_IWCTR_FRC_WIDTH                   1u
#define SDADC_IWCTR_FRC(x)                      (((uint32_t)(((uint32_t)(x))<<SDADC_IWCTR_FRC_SHIFT))&SDADC_IWCTR_FRC_MASK)
#define SDADC_IWCTR_REPVAL_MASK                 0xF00u
#define SDADC_IWCTR_REPVAL_SHIFT                8u
#define SDADC_IWCTR_REPVAL_WIDTH                4u
#define SDADC_IWCTR_REPVAL(x)                   (((uint32_t)(((uint32_t)(x))<<SDADC_IWCTR_REPVAL_SHIFT))&SDADC_IWCTR_REPVAL_MASK)
#define SDADC_IWCTR_NVALDIS_MASK                0x3F0000u
#define SDADC_IWCTR_NVALDIS_SHIFT               16u
#define SDADC_IWCTR_NVALDIS_WIDTH               6u
#define SDADC_IWCTR_NVALDIS(x)                  (((uint32_t)(((uint32_t)(x))<<SDADC_IWCTR_NVALDIS_SHIFT))&SDADC_IWCTR_NVALDIS_MASK)
#define SDADC_IWCTR_NVALINT_MASK                0x3F000000u
#define SDADC_IWCTR_NVALINT_SHIFT               24u
#define SDADC_IWCTR_NVALINT_WIDTH               6u
#define SDADC_IWCTR_NVALINT(x)                  (((uint32_t)(((uint32_t)(x))<<SDADC_IWCTR_NVALINT_SHIFT))&SDADC_IWCTR_NVALINT_MASK)
/* DICFG Bit Fields */
#define SDADC_DICFG_ITRMODE_MASK                0x300000u
#define SDADC_DICFG_ITRMODE_SHIFT               20u
#define SDADC_DICFG_ITRMODE_WIDTH               2u
#define SDADC_DICFG_ITRMODE(x)                  (((uint32_t)(((uint32_t)(x))<<SDADC_DICFG_ITRMODE_SHIFT))&SDADC_DICFG_ITRMODE_MASK)
/* BOUNDSEL Bit Fields */
#define SDADC_BOUNDSEL_BOUNDARYL_MASK           0xFFFFu
#define SDADC_BOUNDSEL_BOUNDARYL_SHIFT          0u
#define SDADC_BOUNDSEL_BOUNDARYL_WIDTH          16u
#define SDADC_BOUNDSEL_BOUNDARYL(x)             (((uint32_t)(((uint32_t)(x))<<SDADC_BOUNDSEL_BOUNDARYL_SHIFT))&SDADC_BOUNDSEL_BOUNDARYL_MASK)
#define SDADC_BOUNDSEL_BOUNDARYU_MASK           0xFFFF0000u
#define SDADC_BOUNDSEL_BOUNDARYU_SHIFT          16u
#define SDADC_BOUNDSEL_BOUNDARYU_WIDTH          16u
#define SDADC_BOUNDSEL_BOUNDARYU(x)             (((uint32_t)(((uint32_t)(x))<<SDADC_BOUNDSEL_BOUNDARYU_SHIFT))&SDADC_BOUNDSEL_BOUNDARYU_MASK)
/* WMINTSTAT Bit Fields */
#define SDADC_WMINTSTAT_FWM_INT_MASK            0x1u
#define SDADC_WMINTSTAT_FWM_INT_SHIFT           0u
#define SDADC_WMINTSTAT_FWM_INT_WIDTH           1u
#define SDADC_WMINTSTAT_FWM_INT(x)              (((uint32_t)(((uint32_t)(x))<<SDADC_WMINTSTAT_FWM_INT_SHIFT))&SDADC_WMINTSTAT_FWM_INT_MASK)
/* OVINTSTAT Bit Fields */
#define SDADC_OVINTSTAT_FOV_INT_MASK            0x1u
#define SDADC_OVINTSTAT_FOV_INT_SHIFT           0u
#define SDADC_OVINTSTAT_FOV_INT_WIDTH           1u
#define SDADC_OVINTSTAT_FOV_INT(x)              (((uint32_t)(((uint32_t)(x))<<SDADC_OVINTSTAT_FOV_INT_SHIFT))&SDADC_OVINTSTAT_FOV_INT_MASK)
#define SDADC_OVINTSTAT_DOV_INT_MASK            0x2u
#define SDADC_OVINTSTAT_DOV_INT_SHIFT           1u
#define SDADC_OVINTSTAT_DOV_INT_WIDTH           1u
#define SDADC_OVINTSTAT_DOV_INT(x)              (((uint32_t)(((uint32_t)(x))<<SDADC_OVINTSTAT_DOV_INT_SHIFT))&SDADC_OVINTSTAT_DOV_INT_MASK)
/* OVSCFG Bit Fields */
#define SDADC_OVSCFG_SRFS_MASK                  0x3u
#define SDADC_OVSCFG_SRFS_SHIFT                 0u
#define SDADC_OVSCFG_SRFS_WIDTH                 2u
#define SDADC_OVSCFG_SRFS(x)                    (((uint32_t)(((uint32_t)(x))<<SDADC_OVSCFG_SRFS_SHIFT))&SDADC_OVSCFG_SRFS_MASK)
#define SDADC_OVSCFG_SRFRT_MASK                 0xCu
#define SDADC_OVSCFG_SRFRT_SHIFT                2u
#define SDADC_OVSCFG_SRFRT_WIDTH                2u
#define SDADC_OVSCFG_SRFRT(x)                   (((uint32_t)(((uint32_t)(x))<<SDADC_OVSCFG_SRFRT_SHIFT))&SDADC_OVSCFG_SRFRT_MASK)
#define SDADC_OVSCFG_SDM_MASK                   0x10u
#define SDADC_OVSCFG_SDM_SHIFT                  4u
#define SDADC_OVSCFG_SDM_WIDTH                  2u
#define SDADC_OVSCFG_SDM(x)                     (((uint32_t)(((uint32_t)(x))<<SDADC_OVSCFG_SDM_SHIFT))&SDADC_OVSCFG_SDM_MASK)
#define SDADC_OVSCFG_SDTH_MASK                  0x7FF0000u
#define SDADC_OVSCFG_SDTH_SHIFT                 16u
#define SDADC_OVSCFG_SDTH_WIDTH                 11u
#define SDADC_OVSCFG_SDTH(x)                    (((uint32_t)(((uint32_t)(x))<<SDADC_OVSCFG_SDTH_SHIFT))&SDADC_OVSCFG_SDTH_MASK)
/* HTCFG Bit Fields */
#define SDADC_HTCFG_HT0_MASK                    0x3u
#define SDADC_HTCFG_HT0_SHIFT                   0u
#define SDADC_HTCFG_HT0_WIDTH                   2u
#define SDADC_HTCFG_HT0(x)                      (((uint32_t)(((uint32_t)(x))<<SDADC_HTCFG_HT0_SHIFT))&SDADC_HTCFG_HT0_MASK)
#define SDADC_HTCFG_HT1_MASK                    0xCu
#define SDADC_HTCFG_HT1_SHIFT                   2u
#define SDADC_HTCFG_HT1_WIDTH                   2u
#define SDADC_HTCFG_HT1(x)                      (((uint32_t)(((uint32_t)(x))<<SDADC_HTCFG_HT1_SHIFT))&SDADC_HTCFG_HT1_MASK)
#define SDADC_HTCFG_HT2_MASK                    0x30u
#define SDADC_HTCFG_HT2_SHIFT                   4u
#define SDADC_HTCFG_HT2_WIDTH                   2u
#define SDADC_HTCFG_HT2(x)                      (((uint32_t)(((uint32_t)(x))<<SDADC_HTCFG_HT2_SHIFT))&SDADC_HTCFG_HT2_MASK)
#define SDADC_HTCFG_HT3_MASK                    0xC0u
#define SDADC_HTCFG_HT3_SHIFT                   6u
#define SDADC_HTCFG_HT3_WIDTH                   2u
#define SDADC_HTCFG_HT3(x)                      (((uint32_t)(((uint32_t)(x))<<SDADC_HTCFG_HT3_SHIFT))&SDADC_HTCFG_HT3_MASK)
#define SDADC_HTCFG_HT4_MASK                    0x300u
#define SDADC_HTCFG_HT4_SHIFT                   8u
#define SDADC_HTCFG_HT4_WIDTH                   2u
#define SDADC_HTCFG_HT4(x)                      (((uint32_t)(((uint32_t)(x))<<SDADC_HTCFG_HT4_SHIFT))&SDADC_HTCFG_HT4_MASK)
#define SDADC_HTCFG_HT5_MASK                    0xC00u
#define SDADC_HTCFG_HT5_SHIFT                   10u
#define SDADC_HTCFG_HT5_WIDTH                   2u
#define SDADC_HTCFG_HT5(x)                      (((uint32_t)(((uint32_t)(x))<<SDADC_HTCFG_HT5_SHIFT))&SDADC_HTCFG_HT5_MASK)
#define SDADC_HTCFG_HT6_MASK                    0x3000u
#define SDADC_HTCFG_HT6_SHIFT                   12u
#define SDADC_HTCFG_HT6_WIDTH                   2u
#define SDADC_HTCFG_HT6(x)                      (((uint32_t)(((uint32_t)(x))<<SDADC_HTCFG_HT6_SHIFT))&SDADC_HTCFG_HT6_MASK)
#define SDADC_HTCFG_HT7_MASK                    0xC000u
#define SDADC_HTCFG_HT7_SHIFT                   14u
#define SDADC_HTCFG_HT7_WIDTH                   2u
#define SDADC_HTCFG_HT7(x)                      (((uint32_t)(((uint32_t)(x))<<SDADC_HTCFG_HT7_SHIFT))&SDADC_HTCFG_HT7_MASK)
#define SDADC_HTCFG_HT8_MASK                    0x30000u
#define SDADC_HTCFG_HT8_SHIFT                   16u
#define SDADC_HTCFG_HT8_WIDTH                   2u
#define SDADC_HTCFG_HT8(x)                      (((uint32_t)(((uint32_t)(x))<<SDADC_HTCFG_HT8_SHIFT))&SDADC_HTCFG_HT8_MASK)
#define SDADC_HTCFG_HT9_MASK                    0xC0000u
#define SDADC_HTCFG_HT9_SHIFT                   18u
#define SDADC_HTCFG_HT9_WIDTH                   2u
#define SDADC_HTCFG_HT9(x)                      (((uint32_t)(((uint32_t)(x))<<SDADC_HTCFG_HT9_SHIFT))&SDADC_HTCFG_HT9_MASK)
#define SDADC_HTCFG_HT10_MASK                   0x300000u
#define SDADC_HTCFG_HT10_SHIFT                  20u
#define SDADC_HTCFG_HT10_WIDTH                  2u
#define SDADC_HTCFG_HT10(x)                     (((uint32_t)(((uint32_t)(x))<<SDADC_HTCFG_HT10_SHIFT))&SDADC_HTCFG_HT10_MASK)
#define SDADC_HTCFG_HT11_MASK                   0xC00000u
#define SDADC_HTCFG_HT11_SHIFT                  22u
#define SDADC_HTCFG_HT11_WIDTH                  2u
#define SDADC_HTCFG_HT11(x)                     (((uint32_t)(((uint32_t)(x))<<SDADC_HTCFG_HT11_SHIFT))&SDADC_HTCFG_HT11_MASK)
#define SDADC_HTCFG_HT12_MASK                   0x3000000u
#define SDADC_HTCFG_HT12_SHIFT                  24u
#define SDADC_HTCFG_HT12_WIDTH                  2u
#define SDADC_HTCFG_HT12(x)                     (((uint32_t)(((uint32_t)(x))<<SDADC_HTCFG_HT12_SHIFT))&SDADC_HTCFG_HT12_MASK)
#define SDADC_HTCFG_HT13_MASK                   0xC000000u
#define SDADC_HTCFG_HT13_SHIFT                  26u
#define SDADC_HTCFG_HT13_WIDTH                  2u
#define SDADC_HTCFG_HT13(x)                     (((uint32_t)(((uint32_t)(x))<<SDADC_HTCFG_HT13_SHIFT))&SDADC_HTCFG_HT13_MASK)
#define SDADC_HTCFG_HT14_MASK                   0x30000000u
#define SDADC_HTCFG_HT14_SHIFT                  28u
#define SDADC_HTCFG_HT14_WIDTH                  2u
#define SDADC_HTCFG_HT14(x)                     (((uint32_t)(((uint32_t)(x))<<SDADC_HTCFG_HT14_SHIFT))&SDADC_HTCFG_HT14_MASK)
#define SDADC_HTCFG_HT15_MASK                   0xC0000000u
#define SDADC_HTCFG_HT15_SHIFT                  30u
#define SDADC_HTCFG_HT15_WIDTH                  2u
#define SDADC_HTCFG_HT15(x)                     (((uint32_t)(((uint32_t)(x))<<SDADC_HTCFG_HT15_SHIFT))&SDADC_HTCFG_HT15_MASK)
/* STCFG Bit Fields */
#define SDADC_STCFG_SH_EN_MASK                  0x1u
#define SDADC_STCFG_SH_EN_SHIFT                 0u
#define SDADC_STCFG_SH_EN_WIDTH                 1u
#define SDADC_STCFG_SH_EN(x)                    (((uint32_t)(((uint32_t)(x))<<SDADC_STCFG_SH_EN_SHIFT))&SDADC_STCFG_SH_EN_MASK)
#define SDADC_STCFG_SH_CLR_MASK                 0x2u
#define SDADC_STCFG_SH_CLR_SHIFT                1u
#define SDADC_STCFG_SH_CLR_WIDTH                1u
#define SDADC_STCFG_SH_CLR(x)                   (((uint32_t)(((uint32_t)(x))<<SDADC_STCFG_SH_CLR_SHIFT))&SDADC_STCFG_SH_CLR_MASK)
#define SDADC_STCFG_FSRSTN_MASK                 0x4u
#define SDADC_STCFG_FSRSTN_SHIFT                2u
#define SDADC_STCFG_FSRSTN_WIDTH                1u
#define SDADC_STCFG_FSRSTN(x)                   (((uint32_t)(((uint32_t)(x))<<SDADC_STCFG_FSRSTN_SHIFT))&SDADC_STCFG_FSRSTN_MASK)
/* FCDIS Bit Fields */
#define SDADC_FCDIS_FCDIS_EN_MASK               0x1u
#define SDADC_FCDIS_FCDIS_EN_SHIFT              0u
#define SDADC_FCDIS_FCDIS_EN_WIDTH              1u
#define SDADC_FCDIS_FCDIS_EN(x)                 (((uint32_t)(((uint32_t)(x))<<SDADC_FCDIS_FCDIS_EN_SHIFT))&SDADC_FCDIS_FCDIS_EN_MASK)
#define SDADC_FCDIS_FCDIS_NUM_MASK              0xFF00u
#define SDADC_FCDIS_FCDIS_NUM_SHIFT             8u
#define SDADC_FCDIS_FCDIS_NUM_WIDTH             8u
#define SDADC_FCDIS_FCDIS_NUM(x)                (((uint32_t)(((uint32_t)(x))<<SDADC_FCDIS_FCDIS_NUM_SHIFT))&SDADC_FCDIS_FCDIS_NUM_MASK)
/* CH_WRAP Bit Fields */
#define SDADC_CH_WRAP_CH_DFLT_MASK              0xFu
#define SDADC_CH_WRAP_CH_DFLT_SHIFT             0u
#define SDADC_CH_WRAP_CH_DFLT_WIDTH             4u
#define SDADC_CH_WRAP_CH_DFLT(x)                (((uint32_t)(((uint32_t)(x))<<SDADC_CH_WRAP_CH_DFLT_SHIFT))&SDADC_CH_WRAP_CH_DFLT_MASK)
#define SDADC_CH_WRAP_CH_NUM_MASK               0xF0000u
#define SDADC_CH_WRAP_CH_NUM_SHIFT              16u
#define SDADC_CH_WRAP_CH_NUM_WIDTH              4u
#define SDADC_CH_WRAP_CH_NUM(x)                 (((uint32_t)(((uint32_t)(x))<<SDADC_CH_WRAP_CH_NUM_SHIFT))&SDADC_CH_WRAP_CH_NUM_MASK)
/* DOV_INFO Bit Fields */
#define SDADC_DOV_INFO_DATA_MASK                0xFFFFu
#define SDADC_DOV_INFO_DATA_SHIFT               0u
#define SDADC_DOV_INFO_DATA_WIDTH               16u
#define SDADC_DOV_INFO_DATA(x)                  (((uint32_t)(((uint32_t)(x))<<SDADC_DOV_INFO_DATA_SHIFT))&SDADC_DOV_INFO_DATA_MASK)
#define SDADC_DOV_INFO_COMPTR_UVF_MASK          0x10000u
#define SDADC_DOV_INFO_COMPTR_UVF_SHIFT         16u
#define SDADC_DOV_INFO_COMPTR_UVF_WIDTH         1u
#define SDADC_DOV_INFO_COMPTR_UVF(x)            (((uint32_t)(((uint32_t)(x))<<SDADC_DOV_INFO_COMPTR_UVF_SHIFT))&SDADC_DOV_INFO_COMPTR_UVF_MASK)
#define SDADC_DOV_INFO_COMPTR_OVF_MASK          0x20000u
#define SDADC_DOV_INFO_COMPTR_OVF_SHIFT         17u
#define SDADC_DOV_INFO_COMPTR_OVF_WIDTH         1u
#define SDADC_DOV_INFO_COMPTR_OVF(x)            (((uint32_t)(((uint32_t)(x))<<SDADC_DOV_INFO_COMPTR_OVF_SHIFT))&SDADC_DOV_INFO_COMPTR_OVF_MASK)
#define SDADC_DOV_INFO_CH_INFO_MASK             0xF00000u
#define SDADC_DOV_INFO_CH_INFO_SHIFT            20u
#define SDADC_DOV_INFO_CH_INFO_WIDTH            4u
#define SDADC_DOV_INFO_CH_INFO(x)               (((uint32_t)(((uint32_t)(x))<<SDADC_DOV_INFO_CH_INFO_SHIFT))&SDADC_DOV_INFO_CH_INFO_MASK)
/* BIAS Bit Fields */
#define SDADC_BIAS_BIAS_RES_TRIM_LV_MASK        0x7u
#define SDADC_BIAS_BIAS_RES_TRIM_LV_SHIFT       0u
#define SDADC_BIAS_BIAS_RES_TRIM_LV_WIDTH       3u
#define SDADC_BIAS_BIAS_RES_TRIM_LV(x)          (((uint32_t)(((uint32_t)(x))<<SDADC_BIAS_BIAS_RES_TRIM_LV_SHIFT))&SDADC_BIAS_BIAS_RES_TRIM_LV_MASK)
#define SDADC_BIAS_TEST_BIAS_LV_MASK            0x8u
#define SDADC_BIAS_TEST_BIAS_LV_SHIFT           3u
#define SDADC_BIAS_TEST_BIAS_LV_WIDTH           1u
#define SDADC_BIAS_TEST_BIAS_LV(x)              (((uint32_t)(((uint32_t)(x))<<SDADC_BIAS_TEST_BIAS_LV_SHIFT))&SDADC_BIAS_TEST_BIAS_LV_MASK)
/* RES Bit Fields */
#define SDADC_RES_RES_N_LV_MASK                 0xFFu
#define SDADC_RES_RES_N_LV_SHIFT                0u
#define SDADC_RES_RES_N_LV_WIDTH                8u
#define SDADC_RES_RES_N_LV(x)                   (((uint32_t)(((uint32_t)(x))<<SDADC_RES_RES_N_LV_SHIFT))&SDADC_RES_RES_N_LV_MASK)
#define SDADC_RES_RES_P_LV_MASK                 0xFF0000u
#define SDADC_RES_RES_P_LV_SHIFT                16u
#define SDADC_RES_RES_P_LV_WIDTH                8u
#define SDADC_RES_RES_P_LV(x)                   (((uint32_t)(((uint32_t)(x))<<SDADC_RES_RES_P_LV_SHIFT))&SDADC_RES_RES_P_LV_MASK)
/* ATT Bit Fields */
#define SDADC_ATT_GAIN_LV_MASK                  0x1Fu
#define SDADC_ATT_GAIN_LV_SHIFT                 0u
#define SDADC_ATT_GAIN_LV_WIDTH                 5u
#define SDADC_ATT_GAIN_LV(x)                    (((uint32_t)(((uint32_t)(x))<<SDADC_ATT_GAIN_LV_SHIFT))&SDADC_ATT_GAIN_LV_MASK)
#define SDADC_ATT_VCOM_SEL_LV_MASK              0x100u
#define SDADC_ATT_VCOM_SEL_LV_SHIFT             8u
#define SDADC_ATT_VCOM_SEL_LV_WIDTH             1u
#define SDADC_ATT_VCOM_SEL_LV(x)                (((uint32_t)(((uint32_t)(x))<<SDADC_ATT_VCOM_SEL_LV_SHIFT))&SDADC_ATT_VCOM_SEL_LV_MASK)
#define SDADC_ATT_ADC_DIV_LV_MASK               0x70000u
#define SDADC_ATT_ADC_DIV_LV_SHIFT              16u
#define SDADC_ATT_ADC_DIV_LV_WIDTH              3u
#define SDADC_ATT_ADC_DIV_LV(x)                 (((uint32_t)(((uint32_t)(x))<<SDADC_ATT_ADC_DIV_LV_SHIFT))&SDADC_ATT_ADC_DIV_LV_MASK)

#endif  /* SDADC_REG_H_ */
