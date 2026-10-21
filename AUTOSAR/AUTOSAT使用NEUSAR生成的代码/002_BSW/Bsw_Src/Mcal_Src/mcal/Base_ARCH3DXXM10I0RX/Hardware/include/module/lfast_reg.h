#ifndef LFAST_REG_H_
#define LFAST_REG_H_

/* ============================================================================
   =============================== Module: LFAST ==============================
   ============================================================================ */

typedef union LFAST_MCR_union_tag {    /* LFAST Mode Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t MSEN:1;
    vuint32_t  :6;
    vuint32_t IPGDBG:1;
    vuint32_t  :7;
    vuint32_t LSSEL:1;
    vuint32_t DRFEN:1;
    vuint32_t RXEN:1;
    vuint32_t TXEN:1;
    vuint32_t  :8;
    vuint32_t TXARBD:1;
    vuint32_t CTSEN:1;
    vuint32_t  :1;
    vuint32_t DRFRST:1;
    vuint32_t DATAEN:1;
  } B;
} LFAST_MCR_tag;

typedef union LFAST_SCR_union_tag {    /* LFAST Speed Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :15;
    vuint32_t DRMD:1;
    vuint32_t  :7;
    vuint32_t RDR:1;
    vuint32_t  :7;
    vuint32_t TDR:1;
  } B;
} LFAST_SCR_tag;

typedef union LFAST_COCR_union_tag {   /* LFAST Correlator Control Register */
  vuint32_t R;
  struct {
    vuint32_t SMPSEL:8;
    vuint32_t  :6;
    vuint32_t  :2;
    vuint32_t  :12;
    vuint32_t CORRTH:3;
    vuint32_t PHSSEL:1;
  } B;
} LFAST_COCR_tag;

typedef union LFAST_TMCR_union_tag {   /* LFAST Test Mode Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :6;
    vuint32_t CLKTST:1;
    vuint32_t LPON:1;
    vuint32_t  :5;
    vuint32_t LPMOD:3;
    vuint32_t LPFRMTH:16;
  } B;
} LFAST_TMCR_tag;

typedef union LFAST_ALCR_union_tag {   /* LFAST Auto Loopback Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :15;
    vuint32_t LPCNTEN:1;
    vuint32_t LPFMCNT:16;
  } B;
} LFAST_ALCR_tag;

typedef union LFAST_RCDCR_union_tag {  /* LFAST Rate Change Delay Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t DRCNT:4;
    vuint32_t  :16;
  } B;
} LFAST_RCDCR_tag;

typedef union LFAST_SLCR_union_tag {   /* LFAST Wakeup Delay Control Register */
  vuint32_t R;
  struct {
    vuint32_t HSCNT:8;
    vuint32_t  :4;
    vuint32_t LSCNT:4;
    vuint32_t HWKCNT:8;
    vuint32_t  :4;
    vuint32_t LWKCNT:4;
  } B;
} LFAST_SLCR_tag;

typedef union LFAST_ICR_union_tag {    /* LFAST ICLC Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :14;
    vuint32_t ICLCSEQ:1;
    vuint32_t SNDICLC:1;
    vuint32_t  :8;
    vuint32_t ICLCPLD:8;
  } B;
} LFAST_ICR_tag;

typedef union LFAST_PICR_union_tag {   /* LFAST Ping Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :15;
    vuint32_t PNGREQ:1;
    vuint32_t PNGAUTO:1;
    vuint32_t  :7;
    vuint32_t PNGPYLD:8;
  } B;
} LFAST_PICR_tag;

typedef union LFAST_RFCR_union_tag {   /* LFAST Rx FIFO CTS Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :10;
    vuint32_t RCTSMX:6;
    vuint32_t  :10;
    vuint32_t RCTSMN:6;
  } B;
} LFAST_RFCR_tag;

typedef union LFAST_TIER_union_tag {   /* LFAST Tx Interrupt Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :14;
    vuint32_t TXIIE:1;
    vuint32_t TXOVIE:1;
    vuint32_t  :11;
    vuint32_t TXPNGIE:1;
    vuint32_t  :1;
    vuint32_t TXUNSIE:1;
    vuint32_t TXICLCIE:1;
    vuint32_t TXDTIE:1;
  } B;
} LFAST_TIER_tag;

typedef union LFAST_RIER_union_tag {   /* LFAST Rx Interrupt Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t RXUOIE:1;
    vuint32_t RXMNIE:1;
    vuint32_t RXMXIE:1;
    vuint32_t RXUFIE:1;
    vuint32_t RXOFIE:1;
    vuint32_t RXSZIE:1;
    vuint32_t RXICIE:1;
    vuint32_t RXLCEIE:1;
    vuint32_t  :12;
    vuint32_t RXCTSIE:1;
    vuint32_t RXDIE:1;
    vuint32_t RXUNSIE:1;
    vuint32_t  :1;
  } B;
} LFAST_RIER_tag;

typedef union LFAST_RIIER_union_tag {  /* LFAST Rx ICLC Interrupt Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :18;
    vuint32_t ICPFIE:1;
    vuint32_t ICPSIE:1;
    vuint32_t ICPRIE:1;
    vuint32_t ICTOIE:1;
    vuint32_t ICLPIE:1;
    vuint32_t ICCTIE:1;
    vuint32_t ICTDIE:1;
    vuint32_t ICTEIE:1;
    vuint32_t ICRFIE:1;
    vuint32_t ICRSIE:1;
    vuint32_t ICTFIE:1;
    vuint32_t ICTSIE:1;
    vuint32_t ICPOFIE:1;
    vuint32_t ICPONIE:1;
  } B;
} LFAST_RIIER_tag;

typedef union LFAST_PLLCR_union_tag {  /* LFAST PLL Control Register */
  vuint32_t R;
  struct {
    vuint32_t IPTMOD:3;
    vuint32_t  :11;
    vuint32_t SWPOFF:1;
    vuint32_t SWPON:1;
    vuint32_t REFINV:1;
    vuint32_t LPCFG:2;
    vuint32_t  :2;
    vuint32_t PLCKCW:2;
    vuint32_t FDIVEN:1;
    vuint32_t FBDIV:6;
    vuint32_t PREDIV:2;
  } B;
} LFAST_PLLCR_tag;

typedef union LFAST_LCR_union_tag {    /* LFAST LVDS Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t SWWKLD:1;
    vuint32_t SWSLPLD:1;
    vuint32_t SWWKLR:1;
    vuint32_t SWSLPLR:1;
    vuint32_t SWOFFLD:1;
    vuint32_t SWONLD:1;
    vuint32_t SWOFFLR:1;
    vuint32_t SWONLR:1;
    vuint32_t LVRXOFF:1;
    vuint32_t LVTXOE:1;
    vuint32_t TXCMUX:1;
    vuint32_t LVRFEN:1;
    vuint32_t LVLPEN:1;                /* Tx LVDS internal loopback enable */
    vuint32_t  :5;
    vuint32_t LVRXOP_TR:1;
    vuint32_t  :1;
    vuint32_t LVRXOP_BR:1;
    vuint32_t LVTXOP:1;
    vuint32_t LVCKSS:1;                /* LVDS Clock Sync Select */
    vuint32_t LVCKP:1;
  } B;
} LFAST_LCR_tag;

typedef union LFAST_UNSTCR_union_tag { /* LFAST Unsolicited Tx Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :15;
    vuint32_t USNDRQ:1;
    vuint32_t  :9;
    vuint32_t UNSHDR:7;
  } B;
} LFAST_UNSTCR_tag;

typedef union LFAST_UNSTDR_union_tag { /* LFAST Unsolicited Tx Data Registers */
  vuint32_t R;
  struct {
    vuint32_t UNTXD:32;
  } B;
} LFAST_UNSTDR_tag;

typedef union LFAST_GSR_union_tag {    /* LFAST Global Status Register */
  vuint32_t R;
  struct {
    vuint32_t DUALMD:1;
    vuint32_t  :12;
    vuint32_t LRMD:1;
    vuint32_t LDSM:1;
    vuint32_t DRSM:1;
    vuint32_t  :11;
    vuint32_t LPTXDN:1;
    vuint32_t LPFPDV:1;
    vuint32_t LPCPDV:1;
    vuint32_t LPCHDV:1;
    vuint32_t LPCSDV:1;
  } B;
} LFAST_GSR_tag;

typedef union LFAST_PISR_union_tag {   /* LFAST Ping Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t RXPNGD:8;
  } B;
} LFAST_PISR_tag;

typedef union LFAST_DFSR_union_tag {   /* LFAST Data Frame Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t RXDCNT:6;
    vuint32_t  :5;
    vuint32_t RXFCNT:3;
    vuint32_t  :2;
    vuint32_t TXDCNT:6;
    vuint32_t  :5;
    vuint32_t TXFCNT:3;
  } B;
} LFAST_DFSR_tag;

typedef union LFAST_TISR_union_tag {   /* LFAST Tx Interrupt Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :14;
    vuint32_t TXIEF:1;
    vuint32_t TXOVF:1;
    vuint32_t  :11;
    vuint32_t TXPNGF:1;
    vuint32_t  :1;
    vuint32_t TXUNSF:1;
    vuint32_t TXICLCF:1;
    vuint32_t TXDTF:1;
  } B;
} LFAST_TISR_tag;

typedef union LFAST_RISR_union_tag {   /* LFAST Rx Interrupt Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t RXUOF:1;
    vuint32_t RXMNF:1;
    vuint32_t RXMXF:1;
    vuint32_t RXUFF:1;
    vuint32_t RXOFF:1;
    vuint32_t RXSZF:1;
    vuint32_t RXICF:1;
    vuint32_t RXLCEF:1;
    vuint32_t  :12;
    vuint32_t RXCTSF:1;
    vuint32_t RXDF:1;
    vuint32_t RXUNSF:1;
    vuint32_t  :1;
  } B;
} LFAST_RISR_tag;

typedef union LFAST_RIISR_union_tag {  /* LFAST Rx ICLC Interrupt Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :18;
    vuint32_t ICPFF:1;
    vuint32_t ICPSF:1;
    vuint32_t ICPRF:1;
    vuint32_t ICTOF:1;
    vuint32_t ICLPF:1;
    vuint32_t ICCTF:1;
    vuint32_t ICTDF:1;
    vuint32_t ICTEF:1;
    vuint32_t ICRFF:1;
    vuint32_t ICRSF:1;
    vuint32_t ICTFF:1;
    vuint32_t ICTSF:1;
    vuint32_t ICPOFF:1;
    vuint32_t ICPONF:1;
  } B;
} LFAST_RIISR_tag;

typedef union LFAST_PLLLSR_union_tag { /* LFAST PLL and LVDS Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :14;
    vuint32_t PLLDIS:1;
    vuint32_t PLDCR:1;
    vuint32_t  :12;
    vuint32_t LRSLPS:1;
    vuint32_t LDSLPS:1;
    vuint32_t LDPDS:1;
    vuint32_t LRPDS:1;
  } B;
} LFAST_PLLLSR_tag;

typedef union LFAST_UNSRSR_union_tag { /* LFAST Unsolicited Rx Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :23;
    vuint32_t URXDV:1;
    vuint32_t  :5;
    vuint32_t URPCNT:3;
  } B;
} LFAST_UNSRSR_tag;

typedef union LFAST_UNSRDR_union_tag { /* LFAST Unsolicited Rx Data Register */
  vuint32_t R;
  struct {
    vuint32_t UNRXD:32;
  } B;
} LFAST_UNSRDR_tag;

struct LFAST_tag {
  LFAST_MCR_tag MCR;                   /* LFAST Mode Configuration Register */
  LFAST_SCR_tag SCR;                   /* LFAST Speed Control Register */
  LFAST_COCR_tag COCR;                 /* LFAST Correlator Control Register */
  LFAST_TMCR_tag TMCR;                 /* LFAST Test Mode Control Register */
  LFAST_ALCR_tag ALCR;                 /* LFAST Auto Loopback Control Register */
  LFAST_RCDCR_tag RCDCR;               /* LFAST Rate Change Delay Control Register */
  LFAST_SLCR_tag SLCR;                 /* LFAST Wakeup Delay Control Register */
  LFAST_ICR_tag ICR;                   /* LFAST ICLC Control Register */
  LFAST_PICR_tag PICR;                 /* LFAST Ping Control Register */
  uint8_t LFAST_reserved0[8];
  LFAST_RFCR_tag RFCR;                 /* LFAST Rx FIFO CTS Control Register */
  LFAST_TIER_tag TIER;                 /* LFAST Tx Interrupt Enable Register */
  LFAST_RIER_tag RIER;                 /* LFAST Rx Interrupt Enable Register */
  LFAST_RIIER_tag RIIER;               /* LFAST Rx ICLC Interrupt Enable Register */
  LFAST_PLLCR_tag PLLCR;               /* LFAST PLL Control Register */
  LFAST_LCR_tag LCR;                   /* LFAST LVDS Control Register */
  LFAST_UNSTCR_tag UNSTCR;             /* LFAST Unsolicited Tx Control Register */
  LFAST_UNSTDR_tag UNSTDR[9];          /* LFAST Unsolicited Tx Data Registers */
  uint8_t LFAST_reserved1[20];
  LFAST_GSR_tag GSR;                   /* LFAST Global Status Register */
  LFAST_PISR_tag PISR;                 /* LFAST Ping Status Register */
  uint8_t LFAST_reserved2[12];
  LFAST_DFSR_tag DFSR;                 /* LFAST Data Frame Status Register */
  LFAST_TISR_tag TISR;                 /* LFAST Tx Interrupt Status Register */
  LFAST_RISR_tag RISR;                 /* LFAST Rx Interrupt Status Register */
  LFAST_RIISR_tag RIISR;               /* LFAST Rx ICLC Interrupt Status Register */
  LFAST_PLLLSR_tag PLLLSR;             /* LFAST PLL and LVDS Status Register */
  LFAST_UNSRSR_tag UNSRSR;             /* LFAST Unsolicited Rx Status Register */
  LFAST_UNSRDR_tag UNSRDR[9];          /* LFAST Unsolicited Rx Data Register */
};

#endif
