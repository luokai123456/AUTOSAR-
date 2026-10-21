#ifndef FCCU_REG_H_
#define FCCU_REG_H_

/* ============================================================================
   =============================== Module: FCCU ===============================
   ============================================================================ */

typedef union FCCU_CTRL_union_tag {    /* Control Register */
  vuint32_t R;
  struct {
    vuint32_t FILTER_BYPASS:1;
    vuint32_t FILTER_WIDTH:2;
    vuint32_t  :19;
    vuint32_t DEBUG:1;
    vuint32_t  :1;
    vuint32_t OPS:2;
    vuint32_t  :1;
    vuint32_t OPR:5;
  } B;
} FCCU_CTRL_tag;

typedef union FCCU_CTRLK_union_tag {   /* CTRL Key Register */
  vuint32_t R;
  struct {
    vuint32_t CTRLK:32;
  } B;
} FCCU_CTRLK_tag;

typedef union FCCU_CFG_union_tag {     /* Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :5;
    vuint32_t FOPEXT:2;
    vuint32_t FCCU_SET_AFTER_RESET:1;
    vuint32_t FCCU_SET_CLEAR:2;
    vuint32_t  :2;
    vuint32_t  :4;
    vuint32_t FOP:1;
    vuint32_t  :2;
    vuint32_t OD:1;
    vuint32_t  :1;
    vuint32_t SM:1;
    vuint32_t PS:1;
    vuint32_t FOM:3;
    vuint32_t EOFS:6;
  } B;
} FCCU_CFG_tag;

typedef union FCCU_RF_CFG_union_tag {  /* RF Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t RFC31:1;
    vuint32_t RFC30:1;
    vuint32_t RFC29:1;
    vuint32_t RFC28:1;
    vuint32_t RFC27:1;
    vuint32_t RFC26:1;
    vuint32_t RFC25:1;
    vuint32_t RFC24:1;
    vuint32_t RFC23:1;
    vuint32_t RFC22:1;
    vuint32_t RFC21:1;
    vuint32_t RFC20:1;
    vuint32_t RFC19:1;
    vuint32_t RFC18:1;
    vuint32_t RFC17:1;
    vuint32_t RFC16:1;
    vuint32_t RFC15:1;
    vuint32_t RFC14:1;
    vuint32_t RFC13:1;
    vuint32_t RFC12:1;
    vuint32_t RFC11:1;
    vuint32_t RFC10:1;
    vuint32_t RFC9:1;
    vuint32_t RFC8:1;
    vuint32_t RFC7:1;
    vuint32_t RFC6:1;
    vuint32_t RFC5:1;
    vuint32_t RFC4:1;
    vuint32_t RFC3:1;
    vuint32_t RFC2:1;
    vuint32_t RFC1:1;
    vuint32_t RFC0:1;
  } B;
} FCCU_RF_CFG_tag;

typedef union FCCU_RFS_CFG_union_tag { /* RFS Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t RFSC31:1;
    vuint32_t RFSC30:1;
    vuint32_t RFSC29:1;
    vuint32_t RFSC28:1;
    vuint32_t RFSC27:1;
    vuint32_t RFSC26:1;
    vuint32_t RFSC25:1;
    vuint32_t RFSC24:1;
    vuint32_t RFSC23:1;
    vuint32_t RFSC22:1;
    vuint32_t RFSC21:1;
    vuint32_t RFSC20:1;
    vuint32_t RFSC19:1;
    vuint32_t RFSC18:1;
    vuint32_t RFSC17:1;
    vuint32_t RFSC16:1;
    vuint32_t RFSC15:1;
    vuint32_t RFSC14:1;
    vuint32_t RFSC13:1;
    vuint32_t RFSC12:1;
    vuint32_t RFSC11:1;
    vuint32_t RFSC10:1;
    vuint32_t RFSC9:1;
    vuint32_t RFSC8:1;
    vuint32_t RFSC7:1;
    vuint32_t RFSC6:1;
    vuint32_t RFSC5:1;
    vuint32_t RFSC4:1;
    vuint32_t RFSC3:1;
    vuint32_t RFSC2:1;
    vuint32_t RFSC1:1;
    vuint32_t RFSC0:1;
  } B;
} FCCU_RFS_CFG_tag;

typedef union FCCU_RF_S_union_tag {    /* UF Status Register */
  vuint32_t R;
  struct {
    vuint32_t RFS31:1;
    vuint32_t RFS30:1;
    vuint32_t RFS29:1;
    vuint32_t RFS28:1;
    vuint32_t RFS27:1;
    vuint32_t RFS26:1;
    vuint32_t RFS25:1;
    vuint32_t RFS24:1;
    vuint32_t RFS23:1;
    vuint32_t RFS22:1;
    vuint32_t RFS21:1;
    vuint32_t RFS20:1;
    vuint32_t RFS19:1;
    vuint32_t RFS18:1;
    vuint32_t RFS17:1;
    vuint32_t RFS16:1;
    vuint32_t RFS15:1;
    vuint32_t RFS14:1;
    vuint32_t RFS13:1;
    vuint32_t RFS12:1;
    vuint32_t RFS11:1;
    vuint32_t RFS10:1;
    vuint32_t RFS9:1;
    vuint32_t RFS8:1;
    vuint32_t RFS7:1;
    vuint32_t RFS6:1;
    vuint32_t RFS5:1;
    vuint32_t RFS4:1;
    vuint32_t RFS3:1;
    vuint32_t RFS2:1;
    vuint32_t RFS1:1;
    vuint32_t RFS0:1;
  } B;
} FCCU_RF_S_tag;

typedef union FCCU_RFK_union_tag {     /* RF Key Register */
  vuint32_t R;
  struct {
    vuint32_t RFK:32;
  } B;
} FCCU_RFK_tag;

typedef union FCCU_RF_E_union_tag {    /* RF Enable Register */
  vuint32_t R;
  struct {
    vuint32_t RFE31:1;
    vuint32_t RFE30:1;
    vuint32_t RFE29:1;
    vuint32_t RFE28:1;
    vuint32_t RFE27:1;
    vuint32_t RFE26:1;
    vuint32_t RFE25:1;
    vuint32_t RFE24:1;
    vuint32_t RFE23:1;
    vuint32_t RFE22:1;
    vuint32_t RFE21:1;
    vuint32_t RFE20:1;
    vuint32_t RFE19:1;
    vuint32_t RFE18:1;
    vuint32_t RFE17:1;
    vuint32_t RFE16:1;
    vuint32_t RFE15:1;
    vuint32_t RFE14:1;
    vuint32_t RFE13:1;
    vuint32_t RFE12:1;
    vuint32_t RFE11:1;
    vuint32_t RFE10:1;
    vuint32_t RFE9:1;
    vuint32_t RFE8:1;
    vuint32_t RFE7:1;
    vuint32_t RFE6:1;
    vuint32_t RFE5:1;
    vuint32_t RFE4:1;
    vuint32_t RFE3:1;
    vuint32_t RFE2:1;
    vuint32_t RFE1:1;
    vuint32_t RFE0:1;
  } B;
} FCCU_RF_E_tag;

typedef union FCCU_RF_TOE_union_tag {  /* RF Time-out Enable Register */
  vuint32_t R;
  struct {
    vuint32_t RFTOE31:1;
    vuint32_t RFTOE30:1;
    vuint32_t RFTOE29:1;
    vuint32_t RFTOE28:1;
    vuint32_t RFTOE27:1;
    vuint32_t RFTOE26:1;
    vuint32_t RFTOE25:1;
    vuint32_t RFTOE24:1;
    vuint32_t RFTOE23:1;
    vuint32_t RFTOE22:1;
    vuint32_t RFTOE21:1;
    vuint32_t RFTOE20:1;
    vuint32_t RFTOE19:1;
    vuint32_t RFTOE18:1;
    vuint32_t RFTOE17:1;
    vuint32_t RFTOE16:1;
    vuint32_t RFTOE15:1;
    vuint32_t RFTOE14:1;
    vuint32_t RFTOE13:1;
    vuint32_t RFTOE12:1;
    vuint32_t RFTOE11:1;
    vuint32_t RFTOE10:1;
    vuint32_t RFTOE9:1;
    vuint32_t RFTOE8:1;
    vuint32_t RFTOE7:1;
    vuint32_t RFTOE6:1;
    vuint32_t RFTOE5:1;
    vuint32_t RFTOE4:1;
    vuint32_t RFTOE3:1;
    vuint32_t RFTOE2:1;
    vuint32_t RFTOE1:1;
    vuint32_t RFTOE0:1;
  } B;
} FCCU_RF_TOE_tag;

typedef union FCCU_RF_TO_union_tag {   /* RF Time-out Register */
  vuint32_t R;
  struct {
    vuint32_t TO:32;
  } B;
} FCCU_RF_TO_tag;

typedef union FCCU_CFG_TO_union_tag {  /* CFG Timeout Register */
  vuint32_t R;
  struct {
    vuint32_t  :29;
    vuint32_t TO:3;
  } B;
} FCCU_CFG_TO_tag;

typedef union FCCU_EINOUT_union_tag {  /* IO Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t EIN1:1;
    vuint32_t EIN0:1;
    vuint32_t  :2;
    vuint32_t EOUT1:1;
    vuint32_t EOUT0:1;
  } B;
} FCCU_EINOUT_tag;

typedef union FCCU_STAT_union_tag {    /* Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t PhysicErrorPin:2;
    vuint32_t ESTAT:1;
    vuint32_t STATUS:3;
  } B;
} FCCU_STAT_tag;

typedef union FCCU_N2AF_STATUS_union_tag { /* NA Freeze Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t NAFS:8;
  } B;
} FCCU_N2AF_STATUS_tag;

typedef union FCCU_A2FF_STATUS_union_tag { /* AF Freeze Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t AF_SRC:2;
    vuint32_t AFFS:8;
  } B;
} FCCU_A2FF_STATUS_tag;

typedef union FCCU_N2FF_STATUS_union_tag { /* NF Freeze Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t NF_SRC:2;
    vuint32_t NFFS:8;
  } B;
} FCCU_N2FF_STATUS_tag;

typedef union FCCU_F2A_STATUS_union_tag { /* FA Freeze Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :23;
    vuint32_t FAFS:9;
  } B;
} FCCU_F2A_STATUS_tag;

typedef union FCCU_RFF_union_tag {     /* RF Fake Register */
  vuint32_t R;
  struct {
    vuint32_t  :25;
    vuint32_t FRFC:7;
  } B;
} FCCU_RFF_tag;

typedef union FCCU_IRQ_STAT_union_tag { /* IRQ Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :27;
    vuint32_t  :1;
    vuint32_t  :1;
    vuint32_t NMI_STAT:1;
    vuint32_t ALRM_STAT:1;
    vuint32_t CFG_TO_STAT:1;
  } B;
} FCCU_IRQ_STAT_tag;

typedef union FCCU_IRQ_EN_union_tag {  /* IRQ Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :28;
    vuint32_t  :1;
    vuint32_t  :2;
    vuint32_t CFG_TO_IEN:1;
  } B;
} FCCU_IRQ_EN_tag;

typedef union FCCU_XTMR_union_tag {    /* XTMR Register */
  vuint32_t R;
  struct {
    vuint32_t XTMR:32;
  } B;
} FCCU_XTMR_tag;

typedef union FCCU_MCS_union_tag {     /* MCS Register */
  vuint32_t R;
  struct {
    vuint32_t VL3:1;
    vuint32_t FS3:1;
    vuint32_t  :2;
    vuint32_t MCS3:4;
    vuint32_t VL2:1;
    vuint32_t FS2:1;
    vuint32_t  :2;
    vuint32_t MCS2:4;
    vuint32_t VL1:1;
    vuint32_t FS1:1;
    vuint32_t  :2;
    vuint32_t MCS1:4;
    vuint32_t VL0:1;
    vuint32_t FS0:1;
    vuint32_t  :2;
    vuint32_t MCS0:4;
  } B;
} FCCU_MCS_tag;

typedef union FCCU_TRANS_LOCK_union_tag { /* Transient Lock Register */
  vuint32_t R;
  struct {
    vuint32_t  :23;
    vuint32_t TRANSKEY:9;
  } B;
} FCCU_TRANS_LOCK_tag;

typedef union FCCU_PERMNT_LOCK_union_tag { /* Permanent Lock Register */
  vuint32_t R;
  struct {
    vuint32_t  :23;
    vuint32_t PERMNTKEY:9;
  } B;
} FCCU_PERMNT_LOCK_tag;

typedef union FCCU_DELTA_T_union_tag { /* Delta T Register */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t  :14;
    vuint32_t  :2;
    vuint32_t DELTA_T:14;
  } B;
} FCCU_DELTA_T_tag;

typedef union FCCU_IRQ_ALARM_EN_union_tag { /* IRQ Alarm Enable Register */
  vuint32_t R;
  struct {
    vuint32_t IRQEN31:1;
    vuint32_t IRQEN30:1;
    vuint32_t IRQEN29:1;
    vuint32_t IRQEN28:1;
    vuint32_t IRQEN27:1;
    vuint32_t IRQEN26:1;
    vuint32_t IRQEN25:1;
    vuint32_t IRQEN24:1;
    vuint32_t IRQEN23:1;
    vuint32_t IRQEN22:1;
    vuint32_t IRQEN21:1;
    vuint32_t IRQEN20:1;
    vuint32_t IRQEN19:1;
    vuint32_t IRQEN18:1;
    vuint32_t IRQEN17:1;
    vuint32_t IRQEN16:1;
    vuint32_t IRQEN15:1;
    vuint32_t IRQEN14:1;
    vuint32_t IRQEN13:1;
    vuint32_t IRQEN12:1;
    vuint32_t IRQEN11:1;
    vuint32_t IRQEN10:1;
    vuint32_t IRQEN9:1;
    vuint32_t IRQEN8:1;
    vuint32_t IRQEN7:1;
    vuint32_t IRQEN6:1;
    vuint32_t IRQEN5:1;
    vuint32_t IRQEN4:1;
    vuint32_t IRQEN3:1;
    vuint32_t IRQEN2:1;
    vuint32_t IRQEN1:1;
    vuint32_t IRQEN0:1;
  } B;
} FCCU_IRQ_ALARM_EN_tag;

typedef union FCCU_NMI_EN_union_tag {  /* NMI Enable Register */
  vuint32_t R;
  struct {
    vuint32_t NMIEN31:1;
    vuint32_t NMIEN30:1;
    vuint32_t NMIEN29:1;
    vuint32_t NMIEN28:1;
    vuint32_t NMIEN27:1;
    vuint32_t NMIEN26:1;
    vuint32_t NMIEN25:1;
    vuint32_t NMIEN24:1;
    vuint32_t NMIEN23:1;
    vuint32_t NMIEN22:1;
    vuint32_t NMIEN21:1;
    vuint32_t NMIEN20:1;
    vuint32_t NMIEN19:1;
    vuint32_t NMIEN18:1;
    vuint32_t NMIEN17:1;
    vuint32_t NMIEN16:1;
    vuint32_t NMIEN15:1;
    vuint32_t NMIEN14:1;
    vuint32_t NMIEN13:1;
    vuint32_t NMIEN12:1;
    vuint32_t NMIEN11:1;
    vuint32_t NMIEN10:1;
    vuint32_t NMIEN9:1;
    vuint32_t NMIEN8:1;
    vuint32_t NMIEN7:1;
    vuint32_t NMIEN6:1;
    vuint32_t NMIEN5:1;
    vuint32_t NMIEN4:1;
    vuint32_t NMIEN3:1;
    vuint32_t NMIEN2:1;
    vuint32_t NMIEN1:1;
    vuint32_t NMIEN0:1;
  } B;
} FCCU_NMI_EN_tag;

typedef union FCCU_EOUT_SIG_EN_union_tag { /* EOUT Signaling Enable Register */
  vuint32_t R;
  struct {
    vuint32_t EOUTEN31:1;
    vuint32_t EOUTEN30:1;
    vuint32_t EOUTEN29:1;
    vuint32_t EOUTEN28:1;
    vuint32_t EOUTEN27:1;
    vuint32_t EOUTEN26:1;
    vuint32_t EOUTEN25:1;
    vuint32_t EOUTEN24:1;
    vuint32_t EOUTEN23:1;
    vuint32_t EOUTEN22:1;
    vuint32_t EOUTEN21:1;
    vuint32_t EOUTEN20:1;
    vuint32_t EOUTEN19:1;
    vuint32_t EOUTEN18:1;
    vuint32_t EOUTEN17:1;
    vuint32_t EOUTEN16:1;
    vuint32_t EOUTEN15:1;
    vuint32_t EOUTEN14:1;
    vuint32_t EOUTEN13:1;
    vuint32_t EOUTEN12:1;
    vuint32_t EOUTEN11:1;
    vuint32_t EOUTEN10:1;
    vuint32_t EOUTEN9:1;
    vuint32_t EOUTEN8:1;
    vuint32_t EOUTEN7:1;
    vuint32_t EOUTEN6:1;
    vuint32_t EOUTEN5:1;
    vuint32_t EOUTEN4:1;
    vuint32_t EOUTEN3:1;
    vuint32_t EOUTEN2:1;
    vuint32_t EOUTEN1:1;
    vuint32_t EOUTEN0:1;
  } B;
} FCCU_EOUT_SIG_EN_tag;

typedef union FCCU_NMI_CORE_SEL_union_tag {  /* NMI To COREx Enable Register */
  vuint32_t R;
  struct {
    vuint32_t :28;
    vuint32_t NMI_CORE_S:4;
  } B;
} FCCU_NMI_CORE_SEL_tag;

struct FCCU_tag {
    FCCU_CTRL_tag CTRL;                  /* Control Register */
    FCCU_CTRLK_tag CTRLK;                /* CTRL Key Register */
    FCCU_CFG_tag CFG;                    /* Configuration Register */
    uint8_t FCCU_reserved0[16];
    FCCU_RF_CFG_tag RF_CFG[4];           /* RF Configuration Register */
    uint8_t FCCU_reserved1[32];
    FCCU_RFS_CFG_tag RFS_CFG[8];         /* RFS Configuration Register */
    uint8_t FCCU_reserved2[20];
    FCCU_RF_S_tag RF_S[4];               /* UF Status Register */
    FCCU_RFK_tag RFK;                    /* RF Key Register */
    FCCU_RF_E_tag RF_E[4];               /* RF Enable Register */
    FCCU_RF_TOE_tag RF_TOE[4];           /* RF Time-out Enable Register */
    FCCU_RF_TO_tag RF_TO;                /* RF Time-out Register */
    FCCU_CFG_TO_tag CFG_TO;              /* CFG Timeout Register */
    FCCU_EINOUT_tag EINOUT;              /* IO Control Register */
    FCCU_STAT_tag STAT;                  /* Status Register */
    FCCU_N2AF_STATUS_tag N2AF_STATUS;    /* NA Freeze Status Register */
    FCCU_A2FF_STATUS_tag A2FF_STATUS;    /* AF Freeze Status Register */
    FCCU_N2FF_STATUS_tag N2FF_STATUS;    /* NF Freeze Status Register */
    FCCU_F2A_STATUS_tag F2A_STATUS;      /* FA Freeze Status Register */
    uint8_t FCCU_reserved3[8];
    FCCU_RFF_tag RFF;                    /* RF Fake Register */
    FCCU_IRQ_STAT_tag IRQ_STAT;          /* IRQ Status Register */
    FCCU_IRQ_EN_tag IRQ_EN;              /* IRQ Enable Register */
    FCCU_XTMR_tag XTMR;                  /* XTMR Register */
    FCCU_MCS_tag MCS;                    /* MCS Register */
    FCCU_TRANS_LOCK_tag TRANS_LOCK;      /* Transient Lock Register */
    FCCU_PERMNT_LOCK_tag PERMNT_LOCK;    /* Permanent Lock Register */
    FCCU_DELTA_T_tag DELTA_T;            /* Delta T Register */
    FCCU_IRQ_ALARM_EN_tag IRQ_ALARM_EN[4]; /* IRQ Alarm Enable Register */
    FCCU_NMI_EN_tag NMI_EN[4];           /* NMI Enable Register */
    FCCU_EOUT_SIG_EN_tag EOUT_SIG_EN[4]; /* EOUT Signaling Enable Register */
    FCCU_NMI_CORE_SEL_tag NMI_CORE_SEL;  /*  NMI To COREx Enable Register */
};

#endif
