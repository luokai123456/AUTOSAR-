#ifndef SRX_REG_H_
#define SRX_REG_H_

/* ============================================================================
   =============================== Module: SRX ================================
   ============================================================================ */

typedef union SRX_GBL_CTRL_union_tag { /* Global Control Register */
  vuint32_t R;
  struct {
    vuint32_t TSPRSC:8;
    vuint32_t  :8;
    vuint32_t  :1;
    vuint32_t  :5;
    vuint32_t  :1;
    vuint32_t  :1;
    vuint32_t  :1;
    vuint32_t  :1;
    vuint32_t  :1;
    vuint32_t FAST_CLR:1;
    vuint32_t  :1;
    vuint32_t DBG_FRZ:1;
    vuint32_t  :1;
    vuint32_t SENT_EN:1;
  } B;
} SRX_GBL_CTRL_tag;

typedef union SRX_CHNL_EN_union_tag {  /* Channel Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t EN_CH:16;
  } B;
} SRX_CHNL_EN_tag;

typedef union SRX_GBL_STATUS_union_tag { /* Global Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t FMDU:1;
    vuint32_t SMDU:1;
    vuint32_t  :8;
  } B;
} SRX_GBL_STATUS_tag;

typedef union SRX_FMSG_RDY_union_tag { /* Fast Message Ready Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t F_RDY:16;
  } B;
} SRX_FMSG_RDY_tag;

typedef union SRX_SMSG_RDY_union_tag { /* Slow Serial Message Ready Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t S_RDY:16;
  } B;
} SRX_SMSG_RDY_tag;

typedef union SRX_DATA_CTRL1_union_tag { /* Data Control Register 1 */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t NIBBCH0:3;
    vuint32_t  :1;
    vuint32_t NIBBCH1:3;
    vuint32_t  :1;
    vuint32_t NIBBCH2:3;
    vuint32_t  :1;
    vuint32_t NIBBCH3:3;
    vuint32_t  :1;
    vuint32_t NIBBCH4:3;
    vuint32_t  :1;
    vuint32_t NIBBCH5:3;
    vuint32_t  :1;
    vuint32_t NIBBCH6:3;
    vuint32_t  :1;
    vuint32_t NIBBCH7:3;
  } B;
} SRX_DATA_CTRL1_tag;

typedef union SRX_DATA_CTRL2_union_tag { /* Data Control Register 2 */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t NIBBCH8:3;
    vuint32_t  :1;
    vuint32_t NIBBCH9:3;
    vuint32_t  :1;
    vuint32_t NIBBCH10:3;
    vuint32_t  :1;
    vuint32_t NIBBCH11:3;
    vuint32_t  :1;
    vuint32_t NIBBCH12:3;
    vuint32_t  :1;
    vuint32_t NIBBCH13:3;
    vuint32_t  :1;
    vuint32_t NIBBCH14:3;
    vuint32_t  :1;
    vuint32_t NIBBCH15:3;
  } B;
} SRX_DATA_CTRL2_tag;

typedef union SRX_FDMA_CTRL_union_tag { /* Fast Message DMA Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t FDMA_EN:16;
  } B;
} SRX_FDMA_CTRL_tag;

typedef union SRX_SDMA_CTRL_union_tag { /* Slow Serial Message DMA Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t SDMA_EN:16;
  } B;
} SRX_SDMA_CTRL_tag;

typedef union SRX_FRDY_IE_union_tag {  /* Fast Message Ready Interrupt Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t FRDY_IE:16;
  } B;
} SRX_FRDY_IE_tag;

typedef union SRX_SRDY_IE_union_tag {  /* Slow Serial Message Ready Interrupt Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t SRDY_IE:16;
  } B;
} SRX_SRDY_IE_tag;

typedef union SRX_DMA_FMSG_DATA_union_tag { /* DMA Fast Message Data Read Register */
  vuint32_t R;
  struct {
    vuint32_t CHNUM:4;
    vuint32_t SCNIB:4;
    vuint32_t DNIB1:4;
    vuint32_t DNIB2:4;
    vuint32_t DNIB3:4;
    vuint32_t DNIB4:4;
    vuint32_t DNIB5:4;
    vuint32_t DNIB6:4;
  } B;
} SRX_DMA_FMSG_DATA_tag;

typedef union SRX_DMA_FMSG_CRC_union_tag { /* DMA Fast Message CRC Read Register */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t CRC4b:4;
    vuint32_t  :16;
  } B;
} SRX_DMA_FMSG_CRC_tag;

typedef union SRX_DMA_FMSG_TS_union_tag { /* DMA Fast Message Time Stamp Read Register */
  vuint32_t R;
  struct {
    vuint32_t TS:32;
  } B;
} SRX_DMA_FMSG_TS_tag;

typedef union SRX_DMA_SMSG_BIT3_union_tag { /* DMA Slow Serial Message Bit3 Read Register */
  vuint32_t R;
  struct {
    vuint32_t CHNUM:4;
    vuint32_t TYPE:1;
    vuint32_t  :16;
    vuint32_t CFG:1;
    vuint32_t ID7_4_ID3_0:4;
    vuint32_t  :1;
    vuint32_t ID3_0_DATA15_12:4;
    vuint32_t  :1;
  } B;
} SRX_DMA_SMSG_BIT3_tag;

typedef union SRX_DMA_SMSG_BIT2_union_tag { /* DMA Slow Serial Message Bit2 Read Register */
  vuint32_t R;
  struct {
    vuint32_t  :10;
    vuint32_t SMCRC:6;
    vuint32_t  :4;
    vuint32_t DATA:12;
  } B;
} SRX_DMA_SMSG_BIT2_tag;

typedef union SRX_DMA_SMSG_TS_union_tag { /* DMA Slow Serial Message Time Stamp Read Register */
  vuint32_t R;
  struct {
    vuint32_t TS:32;
  } B;
} SRX_DMA_SMSG_TS_tag;

typedef union SRX_CH_CLK_CTRL_union_tag { /* Channel 'n' Clock Control Register (n = 0 to (CH-1)) */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t CM_PRSC:15;
    vuint32_t COMP_EN:1;
    vuint32_t  :1;
    vuint32_t PRSC:14;
  } B;
} SRX_CH_CLK_CTRL_tag;

typedef union SRX_CH_STATUS_union_tag { /* Channel 'n' Status Register (n=0 to (CH-1)) */
  vuint32_t R;
  struct {
    vuint32_t BUS_IDLE:1;
    vuint32_t  :3;
    vuint32_t CAL_RESYNC:1;
    vuint32_t CAL_20_25:1;
    vuint32_t SMSG_OFLW:1;
    vuint32_t FMSG_OFLW:1;
    vuint32_t  :1;
    vuint32_t PP_DIAG_ERR:1;
    vuint32_t CAL_LEN_ERR:1;
    vuint32_t CAL_DIAG_ERR:1;
    vuint32_t NIB_VAL_ERR:1;
    vuint32_t SMSG_CRC_ERR:1;
    vuint32_t FMSG_CRC_ERR:1;
    vuint32_t NUM_EDGES_ERR:1;
    vuint32_t  :16;
  } B;
} SRX_CH_STATUS_tag;

typedef union SRX_CH_CONFIG_union_tag { /* Channel 'n' Configuration Register (n=0 to (CH-1)) */
  vuint32_t R;
  struct {
    vuint32_t BUS_IDLE_CNT:4;
    vuint32_t IE_CAL_RESYNC:1;
    vuint32_t IE_CAL_20_25:1;
    vuint32_t IE_SMSG_OFLW:1;
    vuint32_t IE_FMSG_OFLW:1;
    vuint32_t FCRC_CHK_OFF:1;
    vuint32_t IE_PP_DIAG_ERR:1;
    vuint32_t IE_CAL_LEN_ERR:1;
    vuint32_t IE_CAL_DIAG_ERR:1;
    vuint32_t IE_NIB_VAL_ERR:1;
    vuint32_t IE_SMSG_CRC_ERR:1;
    vuint32_t IE_FMSG_CRC_ERR:1;
    vuint32_t IE_NUM_EDGES_ERR:1;
    vuint32_t DCHNG_INT:1;
    vuint32_t CAL_RNG:1;
    vuint32_t PP_CHKSEL:1;
    vuint32_t FCRC_TYPE:1;
    vuint32_t FCRC_SC_EN:1;
    vuint32_t SCRC_TYPE:1;
    vuint32_t PAUSE_EN:1;
    vuint32_t SUCC_CAL_CHK:1;
    vuint32_t FIL_CNT:8;
  } B;
} SRX_CH_CONFIG_tag;

typedef struct SRX_CH_struct_tag {
  SRX_CH_CLK_CTRL_tag CLK_CTRL;        /* Channel 'n' Clock Control Register (n = 0 to (CH-1)) */
  SRX_CH_STATUS_tag STATUS;            /* Channel 'n' Status Register (n=0 to (CH-1)) */
  SRX_CH_CONFIG_tag CONFIG;            /* Channel 'n' Configuration Register (n=0 to (CH-1)) */
  uint8_t CH_reserved0[4];
} SRX_CH_tag;

typedef union SRX_CHANNEL_FMSG_DATA_union_tag { /* Channel 'n' Fast Message Data Read Register (n=0 to (CH-1)) */
  vuint32_t R;
  struct {
    vuint32_t CHNUM:4;
    vuint32_t SCNIB:4;
    vuint32_t DNIB1:4;
    vuint32_t DNIB2:4;
    vuint32_t DNIB3:4;
    vuint32_t DNIB4:4;
    vuint32_t DNIB5:4;
    vuint32_t DNIB6:4;
  } B;
} SRX_CHANNEL_FMSG_DATA_tag;

typedef union SRX_CHANNEL_FMSG_CRC_union_tag { /* Channel 'n' Fast Message CRC Read Register (n=0 to (CH-1)) */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t CRC4b:4;
    vuint32_t  :16;
  } B;
} SRX_CHANNEL_FMSG_CRC_tag;

typedef union SRX_CHANNEL_FMSG_TS_union_tag { /* Channel 'n' Fast Message Time Stamp Read Register (n=0 to (CH-1)) */
  vuint32_t R;
  struct {
    vuint32_t TS:32;
  } B;
} SRX_CHANNEL_FMSG_TS_tag;

typedef union SRX_CHANNEL_SMSG_BIT3_union_tag { /* Channel 'n' Serial Message Read Register (Bit 3) (n=0 to (CH-1)) */
  vuint32_t R;
  struct {
    vuint32_t CHNUM:4;
    vuint32_t TYPE:1;
    vuint32_t  :16;
    vuint32_t CFG:1;
    vuint32_t ID7_4_ID3_0:4;
    vuint32_t  :1;
    vuint32_t ID3_0_DATA15_12:4;
    vuint32_t  :1;
  } B;
} SRX_CHANNEL_SMSG_BIT3_tag;

typedef union SRX_CHANNEL_SMSG_BIT2_union_tag { /* Channel 'n' Serial Message Read Register (Bit 2)(n=0 to (CH-1)) */
  vuint32_t R;
  struct {
    vuint32_t  :10;
    vuint32_t SMCRC:6;
    vuint32_t  :4;
    vuint32_t DATA:12;
  } B;
} SRX_CHANNEL_SMSG_BIT2_tag;

typedef union SRX_CHANNEL_SMSG_TS_union_tag { /* Channel 'n' Serial Message Time Stamp Read Register (n=0 to (CH-1)) */
  vuint32_t R;
  struct {
    vuint32_t TS:32;
  } B;
} SRX_CHANNEL_SMSG_TS_tag;

typedef struct SRX_CHANNEL_struct_tag {
  SRX_CHANNEL_FMSG_DATA_tag FMSG_DATA; /* Channel 'n' Fast Message Data Read Register (n=0 to (CH-1)) */
  SRX_CHANNEL_FMSG_CRC_tag FMSG_CRC;   /* Channel 'n' Fast Message CRC Read Register (n=0 to (CH-1)) */
  SRX_CHANNEL_FMSG_TS_tag FMSG_TS;     /* Channel 'n' Fast Message Time Stamp Read Register (n=0 to (CH-1)) */
  SRX_CHANNEL_SMSG_BIT3_tag SMSG_BIT3; /* Channel 'n' Serial Message Read Register (Bit 3) (n=0 to (CH-1)) */
  SRX_CHANNEL_SMSG_BIT2_tag SMSG_BIT2; /* Channel 'n' Serial Message Read Register (Bit 2)(n=0 to (CH-1)) */
  SRX_CHANNEL_SMSG_TS_tag SMSG_TS;     /* Channel 'n' Serial Message Time Stamp Read Register (n=0 to (CH-1)) */
} SRX_CHANNEL_tag;

struct SRX_tag {
  SRX_GBL_CTRL_tag GBL_CTRL;           /* Global Control Register */
  SRX_CHNL_EN_tag CHNL_EN;             /* Channel Enable Register */
  SRX_GBL_STATUS_tag GBL_STATUS;       /* Global Status Register */
  SRX_FMSG_RDY_tag FMSG_RDY;           /* Fast Message Ready Status Register */
  SRX_SMSG_RDY_tag SMSG_RDY;           /* Slow Serial Message Ready Status Register */
  uint8_t SRX_reserved0[4];
  SRX_DATA_CTRL1_tag DATA_CTRL1;       /* Data Control Register 1 */
  SRX_DATA_CTRL2_tag DATA_CTRL2;       /* Data Control Register 2 */
  uint8_t SRX_reserved1[8];
  SRX_FDMA_CTRL_tag FDMA_CTRL;         /* Fast Message DMA Control Register */
  SRX_SDMA_CTRL_tag SDMA_CTRL;         /* Slow Serial Message DMA Control Register */
  uint8_t SRX_reserved2[4];
  SRX_FRDY_IE_tag FRDY_IE;             /* Fast Message Ready Interrupt Control Register */
  SRX_SRDY_IE_tag SRDY_IE;             /* Slow Serial Message Ready Interrupt Enable Register */
  uint8_t SRX_reserved3[4];
  SRX_DMA_FMSG_DATA_tag DMA_FMSG_DATA; /* DMA Fast Message Data Read Register */
  SRX_DMA_FMSG_CRC_tag DMA_FMSG_CRC;   /* DMA Fast Message CRC Read Register */
  SRX_DMA_FMSG_TS_tag DMA_FMSG_TS;     /* DMA Fast Message Time Stamp Read Register */
  uint8_t SRX_reserved4[4];
  SRX_DMA_SMSG_BIT3_tag DMA_SMSG_BIT3; /* DMA Slow Serial Message Bit3 Read Register */
  SRX_DMA_SMSG_BIT2_tag DMA_SMSG_BIT2; /* DMA Slow Serial Message Bit2 Read Register */
  SRX_DMA_SMSG_TS_tag DMA_SMSG_TS;     /* DMA Slow Serial Message Time Stamp Read Register */
  uint8_t SRX_reserved5[4];
  SRX_CH_tag CH[16];
  SRX_CHANNEL_tag CHANNEL[16];
};

#define SRX_DATA_CTRL1_NIBBCH0_MASK              0x70000000u
#define SRX_DATA_CTRL1_NIBBCH0_SHIFT             28u
#define SRX_DATA_CTRL1_NIBBCH0_WIDTH             3u

#define SRX_DATA_CTRL2_NIBBCH0_MASK              0x70000000u
#define SRX_DATA_CTRL2_NIBBCH0_SHIFT             28u
#define SRX_DATA_CTRL2_NIBBCH0_WIDTH             3u
#define SRX_DATA_CTRL2_NIBBCH0(x)                (((uint32_t)(((uint32_t)(x))<<SRX_DATA_CTRL1_NIBBCH0_SHIFT))&SRX_DATA_CTRL1_NIBBCH0_MASK)
/*
 * Masks for various events
 * These can be combined such as: events |= (EV_1 | EV_2);
 * Also used inside the configuration structure for enabling/disabling certain events
 */
#define SRX_EV_BUS_IDLE                          (uint32)((uint32)1u << (uint8)(31u)) /* Channel has been idle for more than the allowed value */
#define SRX_EV_CAL_RESYNC                        (uint32)((uint32)1u << (uint8)(27u)) /* Successive Calibration Check has failed three times */
#define SRX_EV_CAL_20_25                         ((uint32)1u << (uint32)(26u)) /* Calibration pulse received on this channel has variation in between 20% to 25% from 56 ticks */
#define SRX_EV_SMSG_OFLW                         ((uint32)1u << (uint32)(25u)) /* Slow message overflow */
#define SRX_EV_FMSG_OFLW                         ((uint32)1u << (uint32)(24u)) /* Fast message overflow */
#define SRX_EV_PP_DIAG_ERR                       ((uint32)1u << (uint32)(22u)) /* The ratio of calibration pulse length to overall message length (with pause pulse) is more than 1.5625% between two messages */
#define SRX_EV_CAL_LEN_ERR                       ((uint32)1u << (uint32)(21u)) /* Calibration pulse is more than 56 ticks 25% */
#define SRX_EV_CAL_DIAG_ERR                      ((uint32)1u << (uint32)(20u)) /* Successive Calibration pulses differ by 1.56% */
#define SRX_EV_NIB_VAL_ERR                       ((uint32)1u << (uint32)(19u)) /* Any nibble data value <0 or >15 */
#define SRX_EV_SMSG_CRC_ERR                      ((uint32)1u << (uint32)(18u)) /* Checksum error in Slow Serial Message */
#define SRX_EV_FMSG_CRC_ERR                      ((uint32)1u << (uint32)(17u)) /* Checksum error in Fast Serial Message */
#define SRX_EV_NUM_EDGES_ERR                     ((uint32)1u << (uint32)(16u)) /*  Not the expected number of negative edges between calibration pulse */

/* DMA underflow not in channel config register!  */
#define SRX_EV_FDMA_UNDERFLOW                    ((uint32)1u << (uint32)(23u)) /* Underflow in Fast message DMA registers */
#define SRX_EV_SDMA_UNDERFLOW                    ((uint32)1u << (uint32)(9u)) /* Underflow in Slow message DMA registers */
#define SRX_EV_ALL                               ((uint32)(SRX_EV_BUS_IDLE | SRX_EV_CAL_RESYNC | SRX_EV_CAL_20_25 | SRX_EV_SMSG_OFLW \
                                                | SRX_EV_FMSG_OFLW | SRX_EV_PP_DIAG_ERR | SRX_EV_CAL_LEN_ERR | SRX_EV_CAL_DIAG_ERR \
                                                | SRX_EV_NIB_VAL_ERR  | SRX_EV_SMSG_CRC_ERR | SRX_EV_FMSG_CRC_ERR | SRX_EV_NUM_EDGES_ERR)) /* All flags */
#define SRX_EV_NONE                              ((uint32)(~(SRX_EV_ALL))) /* No events */

/* FMSG_DATA Bit Fields */
#define SRX_FMSG_DATA_DNIB6_MASK                 0xFu
#define SRX_FMSG_DATA_DNIB6_SHIFT                0u
#define SRX_FMSG_DATA_DNIB6_WIDTH                4u
#define SRX_FMSG_DATA_DNIB5_MASK                 0xF0u
#define SRX_FMSG_DATA_DNIB5_SHIFT                4u
#define SRX_FMSG_DATA_DNIB5_WIDTH                4u
#define SRX_FMSG_DATA_DNIB4_MASK                 0xF00u
#define SRX_FMSG_DATA_DNIB4_SHIFT                8u
#define SRX_FMSG_DATA_DNIB4_WIDTH                4u
#define SRX_FMSG_DATA_DNIB3_MASK                 0xF000u
#define SRX_FMSG_DATA_DNIB3_SHIFT                12u
#define SRX_FMSG_DATA_DNIB3_WIDTH                4u
#define SRX_FMSG_DATA_DNIB2_MASK                 0xF0000u
#define SRX_FMSG_DATA_DNIB2_SHIFT                16u
#define SRX_FMSG_DATA_DNIB2_WIDTH                4u
#define SRX_FMSG_DATA_DNIB1_MASK                 0xF00000u
#define SRX_FMSG_DATA_DNIB1_SHIFT                20u
#define SRX_FMSG_DATA_DNIB1_WIDTH                4u
#define SRX_FMSG_DATA_SCNIB_MASK                 0xF000000u
#define SRX_FMSG_DATA_SCNIB_SHIFT                24u
#define SRX_FMSG_DATA_SCNIB_WIDTH                4u
#define SRX_FMSG_DATA_CHNUM_MASK                 0xF0000000u
#define SRX_FMSG_DATA_CHNUM_SHIFT                28u
#define SRX_FMSG_DATA_CHNUM_WIDTH                4u
/* FMSG_CRC Bit Fields */
#define SRX_FMSG_CRC_CRC4b_MASK                  0xF0000u
#define SRX_FMSG_CRC_CRC4b_SHIFT                 16u
#define SRX_FMSG_CRC_CRC4b_WIDTH                 4u
/* FMSG_TS Bit Fields */
#define SRX_FMSG_TS_TS_MASK                      0xFFFFFFFFu
#define SRX_FMSG_TS_TS_SHIFT                     0u
#define SRX_FMSG_TS_TS_WIDTH                     32u
/* SMSG_BIT3 Bit Fields */
#define SRX_SMSG_BIT3_ID3_0_DATA15_12_MASK       0x1Eu
#define SRX_SMSG_BIT3_ID3_0_DATA15_12_SHIFT      1u
#define SRX_SMSG_BIT3_ID3_0_DATA15_12_WIDTH      4u
#define SRX_SMSG_BIT3_ID7_4_ID3_0_MASK           0x3C0u
#define SRX_SMSG_BIT3_ID7_4_ID3_0_SHIFT          6u
#define SRX_SMSG_BIT3_ID7_4_ID3_0_WIDTH          4u
#define SRX_SMSG_BIT3_CFG_MASK                   0x400u
#define SRX_SMSG_BIT3_CFG_SHIFT                  10u
#define SRX_SMSG_BIT3_CFG_WIDTH                  1u
#define SRX_SMSG_BIT3_TYPE_MASK                  0x8000000u
#define SRX_SMSG_BIT3_TYPE_SHIFT                 27u
#define SRX_SMSG_BIT3_TYPE_WIDTH                 1u
#define SRX_SMSG_BIT3_CHNUM_MASK                 0xF0000000u
#define SRX_SMSG_BIT3_CHNUM_SHIFT                28u
#define SRX_SMSG_BIT3_CHNUM_WIDTH                4u
/* SMSG_BIT2 Bit Fields */
#define SRX_SMSG_BIT2_DATA_MASK                  0xFFFu
#define SRX_SMSG_BIT2_DATA_SHIFT                 0u
#define SRX_SMSG_BIT2_DATA_WIDTH                 12u
#define SRX_SMSG_BIT2_SMCRC_MASK                 0x3F0000u
#define SRX_SMSG_BIT2_SMCRC_SHIFT                16u
#define SRX_SMSG_BIT2_SMCRC_WIDTH                6u
/* SMSG_TS Bit Fields */
#define SRX_SMSG_TS_TS_MASK                      0xFFFFFFFFu
#define SRX_SMSG_TS_TS_SHIFT                     0u
#define SRX_SMSG_TS_TS_WIDTH                     32u

#endif
