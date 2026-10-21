#ifndef FEC_REG_H_
#define FEC_REG_H_

/* ============================================================================
   =============================== Module: FEC ================================
   ============================================================================ */

typedef union FEC_EIR_union_tag {      /* Interrupt Event Register */
  vuint32_t R;
  struct {
    vuint32_t HBERR:1;
    vuint32_t BABR:1;
    vuint32_t BABT:1;
    vuint32_t GRA:1;
    vuint32_t TXF:1;
    vuint32_t TXB:1;
    vuint32_t RXF:1;
    vuint32_t RXB:1;
    vuint32_t MII:1;
    vuint32_t EBERR:1;
    vuint32_t LC:1;
    vuint32_t RL:1;
    vuint32_t UN:1;
    vuint32_t  :19;
  } B;
} FEC_EIR_tag;

typedef union FEC_EIMR_union_tag {     /* Interrupt Mask Register */
  vuint32_t R;
  struct {
    vuint32_t HBERR:1;
    vuint32_t BABR:1;
    vuint32_t BABT:1;
    vuint32_t GRA:1;
    vuint32_t TXF:1;
    vuint32_t TXB:1;
    vuint32_t RXF:1;
    vuint32_t RXB:1;
    vuint32_t MII:1;
    vuint32_t EBERR:1;
    vuint32_t LC:1;
    vuint32_t RL:1;
    vuint32_t UN:1;
    vuint32_t  :19;
  } B;
} FEC_EIMR_tag;

typedef union FEC_RDAR_union_tag {     /* Receive Descriptor Active Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t RDAR:1;
    vuint32_t  :24;
  } B;
} FEC_RDAR_tag;

typedef union FEC_TDAR_union_tag {     /* Transmit Descriptor Active Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t TDAR:1;
    vuint32_t  :24;
  } B;
} FEC_TDAR_tag;

typedef union FEC_ECR_union_tag {      /* Ethernet Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t  :1;
    vuint32_t  :1;
    vuint32_t  :23;
    vuint32_t  :1;
    vuint32_t ETHER_EN:1;
    vuint32_t RESET:1;
  } B;
} FEC_ECR_tag;

typedef union FEC_MMFR_union_tag {     /* MII Management Frame Register */
  vuint32_t R;
  struct {
    vuint32_t ST:2;
    vuint32_t OP:2;
    vuint32_t PA:5;
    vuint32_t RA:5;
    vuint32_t TA:2;
    vuint32_t DATA:16;
  } B;
} FEC_MMFR_tag;

typedef union FEC_MSCR_union_tag {     /* MII Speed Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t DIS_PRE:1;
    vuint32_t MII_SPEED:6;
    vuint32_t  :1;
  } B;
} FEC_MSCR_tag;

typedef union FEC_MIBC_union_tag {     /* MIB Control Register */
  vuint32_t R;
  struct {
    vuint32_t MIB_DIS:1;
    vuint32_t MIB_IDLE:1;
    vuint32_t  :30;
  } B;
} FEC_MIBC_tag;

typedef union FEC_RCR_union_tag {      /* Receive Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :5;
    vuint32_t MAX_FL:11;
    vuint32_t  :4;
    vuint32_t RMII_ECHO:1;
    vuint32_t RMII_LOOP:1;
    vuint32_t RMII_10T:1;
    vuint32_t RMII_MODE:1;
    vuint32_t  :2;
    vuint32_t FCE:1;
    vuint32_t BC_REJ:1;
    vuint32_t PROM:1;
    vuint32_t MII_MODE:1;
    vuint32_t DRT:1;
    vuint32_t LOOP:1;
  } B;
} FEC_RCR_tag;

typedef union FEC_TCR_union_tag {      /* Transmit Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :27;
    vuint32_t RFC_PAUSE:1;
    vuint32_t TFC_PAUSE:1;
    vuint32_t FDEN:1;
    vuint32_t HBC:1;
    vuint32_t GTS:1;
  } B;
} FEC_TCR_tag;

typedef union FEC_PALR_union_tag {     /* Physical Address Low Register */
  vuint32_t R;
  struct {
    vuint32_t PADDR1:32;
  } B;
} FEC_PALR_tag;

typedef union FEC_PAUR_union_tag {     /* Physical Address High Register and Type Field */
  vuint32_t R;
  struct {
    vuint32_t PADDR2:16;
    vuint32_t TYPE:16;
  } B;
} FEC_PAUR_tag;

typedef union FEC_OPD_union_tag {      /* Opcode/Pause Duration */
  vuint32_t R;
  struct {
    vuint32_t OPCODE:16;
    vuint32_t PAUSE_DUR:16;
  } B;
} FEC_OPD_tag;

typedef union FEC_IAUR_union_tag {     /* Descriptor Individual Upper Address Register */
  vuint32_t R;
  struct {
    vuint32_t IADDR1:32;
  } B;
} FEC_IAUR_tag;

typedef union FEC_IALR_union_tag {     /* Descriptor Individual Lower Address Register */
  vuint32_t R;
  struct {
    vuint32_t IADDR2:32;
  } B;
} FEC_IALR_tag;

typedef union FEC_GAUR_union_tag {     /* Descriptor Group Upper Address Register */
  vuint32_t R;
  struct {
    vuint32_t GADDR1:32;
  } B;
} FEC_GAUR_tag;

typedef union FEC_GALR_union_tag {     /* Descriptor Group Lower Address Register */
  vuint32_t R;
  struct {
    vuint32_t GADDR2:32;
  } B;
} FEC_GALR_tag;

typedef union FEC_TFWR_union_tag {     /* Transmit FIFO Watermark */
  vuint32_t R;
  struct {
    vuint32_t  :30;
    vuint32_t TFWR:2;
  } B;
} FEC_TFWR_tag;

typedef union FEC_FRBR_union_tag {     /* FIFO Receive Bound Register */
  vuint32_t R;
  struct {
    vuint32_t  :21;
    vuint32_t  :1;
    vuint32_t R_BOUND:8;
    vuint32_t  :2;
  } B;
} FEC_FRBR_tag;

typedef union FEC_FRSR_union_tag {     /* FIFO Receive Start Register */
  vuint32_t R;
  struct {
    vuint32_t  :21;
    vuint32_t  :1;
    vuint32_t R_FSTART:8;
    vuint32_t  :2;
  } B;
} FEC_FRSR_tag;

typedef union FEC_ERDSR_union_tag {    /* Receive Descriptor Ring Start Register */
  vuint32_t R;
  struct {
    vuint32_t R_DES_START:30;
    vuint32_t  :2;
  } B;
} FEC_ERDSR_tag;

typedef union FEC_ETDSR_union_tag {    /* Transmit Buffer Descriptor Ring Start Register */
  vuint32_t R;
  struct {
    vuint32_t X_DES_START:30;
    vuint32_t  :2;
  } B;
} FEC_ETDSR_tag;

typedef union FEC_EMRBR_union_tag {    /* Receive Buffer Size Register */
  vuint32_t R;
  struct {
    vuint32_t  :21;
    vuint32_t R_BUF_SIZE:7;
    vuint32_t  :4;
  } B;
} FEC_EMRBR_tag;

typedef union FEC_RMON_T_DROP_union_tag { /* Count of frames not counted correctly */
  vuint32_t R;
  struct {
    vuint32_t RMON_T_DROP:32;
  } B;
} FEC_RMON_T_DROP_tag;

typedef union FEC_RMON_T_PACKETS_union_tag { /* RMON Tx packet count */
  vuint32_t R;
  struct {
    vuint32_t RMON_T_PACKETS:32;
  } B;
} FEC_RMON_T_PACKETS_tag;

typedef union FEC_RMON_T_BC_PKT_union_tag { /* RMON Tx broadcast packets */
  vuint32_t R;
  struct {
    vuint32_t RMON_T_BC_PKT:32;
  } B;
} FEC_RMON_T_BC_PKT_tag;

typedef union FEC_RMON_T_MC_PKT_union_tag { /* RMON Tx multicast packets */
  vuint32_t R;
  struct {
    vuint32_t RMON_T_MC_PKT:32;
  } B;
} FEC_RMON_T_MC_PKT_tag;

typedef union FEC_RMON_T_CRC_ALIGN_union_tag { /* RMON Tx packets with CRC/align error */
  vuint32_t R;
  struct {
    vuint32_t RMON_T_CRC_ALIGN:32;
  } B;
} FEC_RMON_T_CRC_ALIGN_tag;

typedef union FEC_RMON_T_UNDERSIZE_union_tag { /* RMON Tx packets < 64 bytes, good CRC */
  vuint32_t R;
  struct {
    vuint32_t RMON_T_UNDERSIZE:32;
  } B;
} FEC_RMON_T_UNDERSIZE_tag;

typedef union FEC_RMON_T_OVERSIZE_union_tag { /* RMON Tx packets > MAX_FL bytes, good CRC */
  vuint32_t R;
  struct {
    vuint32_t RMON_T_OVERSIZE:32;
  } B;
} FEC_RMON_T_OVERSIZE_tag;

typedef union FEC_RMON_T_FRAG_union_tag { /* RMON Tx packets < 64 bytes, bad CRC */
  vuint32_t R;
  struct {
    vuint32_t RMON_T_FRAG:32;
  } B;
} FEC_RMON_T_FRAG_tag;

typedef union FEC_RMON_T_JAB_union_tag { /* RMON Tx packets > MAX_FL bytes, bad CRC */
  vuint32_t R;
  struct {
    vuint32_t RMON_T_JAB:32;
  } B;
} FEC_RMON_T_JAB_tag;

typedef union FEC_RMON_T_COL_union_tag { /* RMON Tx collision count */
  vuint32_t R;
  struct {
    vuint32_t RMON_T_COL:32;
  } B;
} FEC_RMON_T_COL_tag;

typedef union FEC_RMON_T_P64_union_tag { /* RMON Tx 64 byte packets */
  vuint32_t R;
  struct {
    vuint32_t RMON_T_P64:32;
  } B;
} FEC_RMON_T_P64_tag;

typedef union FEC_RMON_T_P65TO127_union_tag { /* RMON Tx 65 to 127 byte packets */
  vuint32_t R;
  struct {
    vuint32_t RMON_T_P65TO127:32;
  } B;
} FEC_RMON_T_P65TO127_tag;

typedef union FEC_RMON_T_P128TO255_union_tag { /* RMON Tx 128 to 255 byte packets */
  vuint32_t R;
  struct {
    vuint32_t RMON_T_P128TO255:32;
  } B;
} FEC_RMON_T_P128TO255_tag;

typedef union FEC_RMON_T_P256TO511_union_tag { /* RMON Tx 256 to 511 byte packets */
  vuint32_t R;
  struct {
    vuint32_t RMON_T_P256TO511:32;
  } B;
} FEC_RMON_T_P256TO511_tag;

typedef union FEC_RMON_T_P512TO1023_union_tag { /* RMON Tx 512 to 1023 byte packets */
  vuint32_t R;
  struct {
    vuint32_t RMON_T_P512TO1023:32;
  } B;
} FEC_RMON_T_P512TO1023_tag;

typedef union FEC_RMON_T_P1024TO2047_union_tag { /* RMON Tx 1024 to 2047 byte packets */
  vuint32_t R;
  struct {
    vuint32_t RMON_T_P1024TO2047:32;
  } B;
} FEC_RMON_T_P1024TO2047_tag;

typedef union FEC_RMON_T_P_GTE2048_union_tag { /* RMON Tx packets with > 2048 bytes */
  vuint32_t R;
  struct {
    vuint32_t RMON_T_P_GTE2048:32;
  } B;
} FEC_RMON_T_P_GTE2048_tag;

typedef union FEC_RMON_T_OCTETS_union_tag { /* RMON Tx Octets */
  vuint32_t R;
  struct {
    vuint32_t RMON_T_OCTETS:32;
  } B;
} FEC_RMON_T_OCTETS_tag;

typedef union FEC_IEEE_T_DROP_union_tag { /* Count of transmitted frames not counted correctly */
  vuint32_t R;
  struct {
    vuint32_t IEEE_T_DROP:32;
  } B;
} FEC_IEEE_T_DROP_tag;

typedef union FEC_IEEE_T_FRAME_OK_union_tag { /* Frames transmitted OK */
  vuint32_t R;
  struct {
    vuint32_t IEEE_T_FRAME_OK:32;
  } B;
} FEC_IEEE_T_FRAME_OK_tag;

typedef union FEC_IEEE_T_1COL_union_tag { /* Frames transmitted with single collision */
  vuint32_t R;
  struct {
    vuint32_t IEEE_T_1COL:32;
  } B;
} FEC_IEEE_T_1COL_tag;

typedef union FEC_IEEE_T_MCOL_union_tag { /* Frames transmitted with multiple collisions */
  vuint32_t R;
  struct {
    vuint32_t IEEE_T_MCOL:32;
  } B;
} FEC_IEEE_T_MCOL_tag;

typedef union FEC_IEEE_T_DEF_union_tag { /* Frames transmitted after deferral delay */
  vuint32_t R;
  struct {
    vuint32_t IEEE_T_DEF:32;
  } B;
} FEC_IEEE_T_DEF_tag;

typedef union FEC_IEEE_T_LCOL_union_tag { /* Frames transmitted with late collision */
  vuint32_t R;
  struct {
    vuint32_t IEEE_T_LCOL:32;
  } B;
} FEC_IEEE_T_LCOL_tag;

typedef union FEC_IEEE_T_EXCOL_union_tag { /* Frames transmitted with excessive collisions */
  vuint32_t R;
  struct {
    vuint32_t IEEE_T_EXCOL:32;
  } B;
} FEC_IEEE_T_EXCOL_tag;

typedef union FEC_IEEE_T_MACERR_union_tag { /* Frames transmitted with Tx FIFO underrun */
  vuint32_t R;
  struct {
    vuint32_t IEEE_T_MACERR:32;
  } B;
} FEC_IEEE_T_MACERR_tag;

typedef union FEC_IEEE_T_CSERR_union_tag { /* Frames transmitted with carrier sense error */
  vuint32_t R;
  struct {
    vuint32_t IEEE_T_CSERR:32;
  } B;
} FEC_IEEE_T_CSERR_tag;

typedef union FEC_IEEE_T_SQE_union_tag { /* Frames transmitted with SQE error */
  vuint32_t R;
  struct {
    vuint32_t IEEE_T_SQE:32;
  } B;
} FEC_IEEE_T_SQE_tag;

typedef union FEC_IEEE_T_FDXFC_union_tag { /* Flow control pause frames transmitted */
  vuint32_t R;
  struct {
    vuint32_t IEEE_T_FDXFC:32;
  } B;
} FEC_IEEE_T_FDXFC_tag;

typedef union FEC_IEEE_T_OCTETS_OK_union_tag { /* Octet count for frames transmitted without error */
  vuint32_t R;
  struct {
    vuint32_t IEEE_T_OCTETS_OK:32;
  } B;
} FEC_IEEE_T_OCTETS_OK_tag;

typedef union FEC_RMON_R_DROP_union_tag { /* Count of received frames not counted correctly */
  vuint32_t R;
  struct {
    vuint32_t RMON_R_DROP:32;
  } B;
} FEC_RMON_R_DROP_tag;

typedef union FEC_RMON_R_PACKETS_union_tag { /* RMON Rx packet count */
  vuint32_t R;
  struct {
    vuint32_t RMON_R_PACKETS:32;
  } B;
} FEC_RMON_R_PACKETS_tag;

typedef union FEC_RMON_R_BC_PKT_union_tag { /* RMON Rx broadcast packets */
  vuint32_t R;
  struct {
    vuint32_t RMON_R_BC_PKT:32;
  } B;
} FEC_RMON_R_BC_PKT_tag;

typedef union FEC_RMON_R_MC_PKT_union_tag { /* RMON Rx multicast packets */
  vuint32_t R;
  struct {
    vuint32_t RMON_R_MC_PKT:32;
  } B;
} FEC_RMON_R_MC_PKT_tag;

typedef union FEC_RMON_R_CRC_ALIGN_union_tag { /* RMON Rx packets with CRC/Align error */
  vuint32_t R;
  struct {
    vuint32_t RMON_R_CRC_ALIGN:32;
  } B;
} FEC_RMON_R_CRC_ALIGN_tag;

typedef union FEC_RMON_R_UNDERSIZE_union_tag { /* RMON Rx packets < 64 bytes, good CRC */
  vuint32_t R;
  struct {
    vuint32_t RMON_R_UNDERSIZE:32;
  } B;
} FEC_RMON_R_UNDERSIZE_tag;

typedef union FEC_RMON_R_OVERSIZE_union_tag { /* RMON Rx packets > MAX_FL bytes, good CRC */
  vuint32_t R;
  struct {
    vuint32_t RMON_R_OVERSIZE:32;
  } B;
} FEC_RMON_R_OVERSIZE_tag;

typedef union FEC_RMON_R_FRAG_union_tag { /* RMON Rx packets < 64 bytes, bad CRC */
  vuint32_t R;
  struct {
    vuint32_t RMON_R_FRAG:32;
  } B;
} FEC_RMON_R_FRAG_tag;

typedef union FEC_RMON_R_JAB_union_tag { /* RMON Rx packets > MAX_FL bytes, bad CRC */
  vuint32_t R;
  struct {
    vuint32_t RMON_R_JAB:32;
  } B;
} FEC_RMON_R_JAB_tag;

typedef union FEC_RMON_R_RESVD_0_union_tag { /* Reserved */
  vuint32_t R;
  struct {
    vuint32_t RMON_R_RESVD_0:32;
  } B;
} FEC_RMON_R_RESVD_0_tag;

typedef union FEC_RMON_R_P64_union_tag { /* RMON Rx 64 byte packets */
  vuint32_t R;
  struct {
    vuint32_t RMON_R_P64:32;
  } B;
} FEC_RMON_R_P64_tag;

typedef union FEC_RMON_R_P65TO127_union_tag { /* RMON Rx 65 to 127 byte packets */
  vuint32_t R;
  struct {
    vuint32_t RMON_R_P65TO127:32;
  } B;
} FEC_RMON_R_P65TO127_tag;

typedef union FEC_RMON_R_P128TO255_union_tag { /* RMON Rx 128 to 255 byte packets */
  vuint32_t R;
  struct {
    vuint32_t RMON_R_P128TO255:32;
  } B;
} FEC_RMON_R_P128TO255_tag;

typedef union FEC_RMON_R_P256TO511_union_tag { /* RMON Rx 256 to 511 byte packets */
  vuint32_t R;
  struct {
    vuint32_t RMON_R_P256TO511:32;
  } B;
} FEC_RMON_R_P256TO511_tag;

typedef union FEC_RMON_R_P512TO1023_union_tag { /* RMON Rx 512 to 1023 byte packets */
  vuint32_t R;
  struct {
    vuint32_t RMON_R_P512TO1023:32;
  } B;
} FEC_RMON_R_P512TO1023_tag;

typedef union FEC_RMON_R_P1024TO2047_union_tag { /* RMON Rx 1024 to 2047 byte packets */
  vuint32_t R;
  struct {
    vuint32_t RMON_R_P1024TO2047:32;
  } B;
} FEC_RMON_R_P1024TO2047_tag;

typedef union FEC_RMON_R_P_GTE2048_union_tag { /* RMON Rx packets with > 2048 bytes */
  vuint32_t R;
  struct {
    vuint32_t RMON_R_P_GTE2048:32;
  } B;
} FEC_RMON_R_P_GTE2048_tag;

typedef union FEC_RMON_R_OCTETS_union_tag { /* RMON Rx octets */
  vuint32_t R;
  struct {
    vuint32_t RMON_R_OCTETS:32;
  } B;
} FEC_RMON_R_OCTETS_tag;

typedef union FEC_IEEE_R_DROP_union_tag { /* Count of received frames not counted correctly */
  vuint32_t R;
  struct {
    vuint32_t IEEE_R_DROP:32;
  } B;
} FEC_IEEE_R_DROP_tag;

typedef union FEC_IEEE_R_FRAME_OK_union_tag { /* Frames received OK */
  vuint32_t R;
  struct {
    vuint32_t IEEE_R_FRAME_OK:32;
  } B;
} FEC_IEEE_R_FRAME_OK_tag;

typedef union FEC_IEEE_R_CRC_union_tag { /* Frames received with CRC error */
  vuint32_t R;
  struct {
    vuint32_t IEEE_R_CRC:32;
  } B;
} FEC_IEEE_R_CRC_tag;

typedef union FEC_IEEE_R_ALIGN_union_tag { /* Frames received with alignment error */
  vuint32_t R;
  struct {
    vuint32_t IEEE_R_ALIGN:32;
  } B;
} FEC_IEEE_R_ALIGN_tag;

typedef union FEC_IEEE_R_MACERR_union_tag { /* Receive FIFO overflow count */
  vuint32_t R;
  struct {
    vuint32_t IEEE_R_MACERR:32;
  } B;
} FEC_IEEE_R_MACERR_tag;

typedef union FEC_IEEE_R_FDXFC_union_tag { /* Flow control pause frames received */
  vuint32_t R;
  struct {
    vuint32_t IEEE_R_FDXFC:32;
  } B;
} FEC_IEEE_R_FDXFC_tag;

typedef union FEC_IEEE_R_OCTETS_OK_union_tag { /* Octet count for frames received without error */
  vuint32_t R;
  struct {
    vuint32_t IEEE_R_OCTETS_OK:32;
  } B;
} FEC_IEEE_R_OCTETS_OK_tag;

struct FEC_tag {
  uint8_t FEC_reserved0[4];
  FEC_EIR_tag EIR;                     /* Interrupt Event Register */
  FEC_EIMR_tag EIMR;                   /* Interrupt Mask Register */
  uint8_t FEC_reserved1[4];
  FEC_RDAR_tag RDAR;                   /* Receive Descriptor Active Register */
  FEC_TDAR_tag TDAR;                   /* Transmit Descriptor Active Register */
  uint8_t FEC_reserved2[12];
  FEC_ECR_tag ECR;                     /* Ethernet Control Register */
  uint8_t FEC_reserved3[24];
  FEC_MMFR_tag MMFR;                   /* MII Management Frame Register */
  FEC_MSCR_tag MSCR;                   /* MII Speed Control Register */
  uint8_t FEC_reserved4[28];
  FEC_MIBC_tag MIBC;                   /* MIB Control Register */
  uint8_t FEC_reserved5[28];
  FEC_RCR_tag RCR;                     /* Receive Control Register */
  uint8_t FEC_reserved6[60];
  FEC_TCR_tag TCR;                     /* Transmit Control Register */
  uint8_t FEC_reserved7[28];
  FEC_PALR_tag PALR;                   /* Physical Address Low Register */
  FEC_PAUR_tag PAUR;                   /* Physical Address High Register and Type Field */
  FEC_OPD_tag OPD;                     /* Opcode/Pause Duration */
  uint8_t FEC_reserved8[40];
  FEC_IAUR_tag IAUR;                   /* Descriptor Individual Upper Address Register */
  FEC_IALR_tag IALR;                   /* Descriptor Individual Lower Address Register */
  FEC_GAUR_tag GAUR;                   /* Descriptor Group Upper Address Register */
  FEC_GALR_tag GALR;                   /* Descriptor Group Lower Address Register */
  uint8_t FEC_reserved9[28];
  FEC_TFWR_tag TFWR;                   /* Transmit FIFO Watermark */
  uint8_t FEC_reserved10[4];
  FEC_FRBR_tag FRBR;                   /* FIFO Receive Bound Register */
  FEC_FRSR_tag FRSR;                   /* FIFO Receive Start Register */
  uint8_t FEC_reserved11[44];
  FEC_ERDSR_tag ERDSR;                 /* Receive Descriptor Ring Start Register */
  FEC_ETDSR_tag ETDSR;                 /* Transmit Buffer Descriptor Ring Start Register */
  FEC_EMRBR_tag EMRBR;                 /* Receive Buffer Size Register */
  uint8_t FEC_reserved12[116];
  FEC_RMON_T_DROP_tag RMON_T_DROP;     /* Count of frames not counted correctly */
  FEC_RMON_T_PACKETS_tag RMON_T_PACKETS; /* RMON Tx packet count */
  FEC_RMON_T_BC_PKT_tag RMON_T_BC_PKT; /* RMON Tx broadcast packets */
  FEC_RMON_T_MC_PKT_tag RMON_T_MC_PKT; /* RMON Tx multicast packets */
  FEC_RMON_T_CRC_ALIGN_tag RMON_T_CRC_ALIGN; /* RMON Tx packets with CRC/align error */
  FEC_RMON_T_UNDERSIZE_tag RMON_T_UNDERSIZE; /* RMON Tx packets < 64 bytes, good CRC */
  FEC_RMON_T_OVERSIZE_tag RMON_T_OVERSIZE; /* RMON Tx packets > MAX_FL bytes, good CRC */
  FEC_RMON_T_FRAG_tag RMON_T_FRAG;     /* RMON Tx packets < 64 bytes, bad CRC */
  FEC_RMON_T_JAB_tag RMON_T_JAB;       /* RMON Tx packets > MAX_FL bytes, bad CRC */
  FEC_RMON_T_COL_tag RMON_T_COL;       /* RMON Tx collision count */
  FEC_RMON_T_P64_tag RMON_T_P64;       /* RMON Tx 64 byte packets */
  FEC_RMON_T_P65TO127_tag RMON_T_P65TO127; /* RMON Tx 65 to 127 byte packets */
  FEC_RMON_T_P128TO255_tag RMON_T_P128TO255; /* RMON Tx 128 to 255 byte packets */
  FEC_RMON_T_P256TO511_tag RMON_T_P256TO511; /* RMON Tx 256 to 511 byte packets */
  FEC_RMON_T_P512TO1023_tag RMON_T_P512TO1023; /* RMON Tx 512 to 1023 byte packets */
  FEC_RMON_T_P1024TO2047_tag RMON_T_P1024TO2047; /* RMON Tx 1024 to 2047 byte packets */
  FEC_RMON_T_P_GTE2048_tag RMON_T_P_GTE2048; /* RMON Tx packets with > 2048 bytes */
  FEC_RMON_T_OCTETS_tag RMON_T_OCTETS; /* RMON Tx Octets */
  FEC_IEEE_T_DROP_tag IEEE_T_DROP;     /* Count of transmitted frames not counted correctly */
  FEC_IEEE_T_FRAME_OK_tag IEEE_T_FRAME_OK; /* Frames transmitted OK */
  FEC_IEEE_T_1COL_tag IEEE_T_1COL;     /* Frames transmitted with single collision */
  FEC_IEEE_T_MCOL_tag IEEE_T_MCOL;     /* Frames transmitted with multiple collisions */
  FEC_IEEE_T_DEF_tag IEEE_T_DEF;       /* Frames transmitted after deferral delay */
  FEC_IEEE_T_LCOL_tag IEEE_T_LCOL;     /* Frames transmitted with late collision */
  FEC_IEEE_T_EXCOL_tag IEEE_T_EXCOL;   /* Frames transmitted with excessive collisions */
  FEC_IEEE_T_MACERR_tag IEEE_T_MACERR; /* Frames transmitted with Tx FIFO underrun */
  FEC_IEEE_T_CSERR_tag IEEE_T_CSERR;   /* Frames transmitted with carrier sense error */
  FEC_IEEE_T_SQE_tag IEEE_T_SQE;       /* Frames transmitted with SQE error */
  FEC_IEEE_T_FDXFC_tag IEEE_T_FDXFC;   /* Flow control pause frames transmitted */
  FEC_IEEE_T_OCTETS_OK_tag IEEE_T_OCTETS_OK; /* Octet count for frames transmitted without error */
  uint8_t FEC_reserved13[8];
  FEC_RMON_R_DROP_tag RMON_R_DROP;     /* Count of received frames not counted correctly */
  FEC_RMON_R_PACKETS_tag RMON_R_PACKETS; /* RMON Rx packet count */
  FEC_RMON_R_BC_PKT_tag RMON_R_BC_PKT; /* RMON Rx broadcast packets */
  FEC_RMON_R_MC_PKT_tag RMON_R_MC_PKT; /* RMON Rx multicast packets */
  FEC_RMON_R_CRC_ALIGN_tag RMON_R_CRC_ALIGN; /* RMON Rx packets with CRC/Align error */
  FEC_RMON_R_UNDERSIZE_tag RMON_R_UNDERSIZE; /* RMON Rx packets < 64 bytes, good CRC */
  FEC_RMON_R_OVERSIZE_tag RMON_R_OVERSIZE; /* RMON Rx packets > MAX_FL bytes, good CRC */
  FEC_RMON_R_FRAG_tag RMON_R_FRAG;     /* RMON Rx packets < 64 bytes, bad CRC */
  FEC_RMON_R_JAB_tag RMON_R_JAB;       /* RMON Rx packets > MAX_FL bytes, bad CRC */
  FEC_RMON_R_RESVD_0_tag RMON_R_RESVD_0; /* Reserved */
  FEC_RMON_R_P64_tag RMON_R_P64;       /* RMON Rx 64 byte packets */
  FEC_RMON_R_P65TO127_tag RMON_R_P65TO127; /* RMON Rx 65 to 127 byte packets */
  FEC_RMON_R_P128TO255_tag RMON_R_P128TO255; /* RMON Rx 128 to 255 byte packets */
  FEC_RMON_R_P256TO511_tag RMON_R_P256TO511; /* RMON Rx 256 to 511 byte packets */
  FEC_RMON_R_P512TO1023_tag RMON_R_P512TO1023; /* RMON Rx 512 to 1023 byte packets */
  FEC_RMON_R_P1024TO2047_tag RMON_R_P1024TO2047; /* RMON Rx 1024 to 2047 byte packets */
  FEC_RMON_R_P_GTE2048_tag RMON_R_P_GTE2048; /* RMON Rx packets with > 2048 bytes */
  FEC_RMON_R_OCTETS_tag RMON_R_OCTETS; /* RMON Rx octets */
  FEC_IEEE_R_DROP_tag IEEE_R_DROP;     /* Count of received frames not counted correctly */
  FEC_IEEE_R_FRAME_OK_tag IEEE_R_FRAME_OK; /* Frames received OK */
  FEC_IEEE_R_CRC_tag IEEE_R_CRC;       /* Frames received with CRC error */
  FEC_IEEE_R_ALIGN_tag IEEE_R_ALIGN;   /* Frames received with alignment error */
  FEC_IEEE_R_MACERR_tag IEEE_R_MACERR; /* Receive FIFO overflow count */
  FEC_IEEE_R_FDXFC_tag IEEE_R_FDXFC;   /* Flow control pause frames received */
  FEC_IEEE_R_OCTETS_OK_tag IEEE_R_OCTETS_OK; /* Octet count for frames received without error */
};

#endif
