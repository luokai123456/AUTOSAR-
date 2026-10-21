#ifndef CSRX_REG_H_
#define CSRX_REG_H_

/* ============================================================================
   =============================== Module: CSRX ================================
   ============================================================================ */

typedef union CSRX_TCFG_union_tag { /*Transmit Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t SENTID:16;
    vuint32_t CLKDIV:4;
    vuint32_t CRCENB:1;
    vuint32_t TXENB:1;
    vuint32_t ENHSER:1;
    vuint32_t SLOW:1;
    vuint32_t PPENB:1;
    vuint32_t TXCRCTYPE:1;
    vuint32_t TXIDLEPOL:1;
    vuint32_t TXSYNC:1;
    vuint32_t SNTENB:1;
    vuint32_t DNIB:3;
  } B;
} CSRX_TCFG_tag;

typedef union CSRX_TTFT_union_tag { /*Tick Time rate & Frame Time Configuration Register */
  vuint32_t R;
  struct {
	vuint32_t TX_CRC_WITH_STATUS:1;
	vuint32_t  :5;
	vuint32_t FRMTT:10;
	vuint32_t TTSCALE:16;
  } B;
} CSRX_TTFT_tag;

typedef union CSRX_TFDATA_union_tag { /*Transmit FAST Channel Data Register */
  vuint32_t R;
  struct {
	vuint32_t STAT:4;
	vuint32_t DATA1:4;
	vuint32_t DATA2:4;
	vuint32_t DATA3:4;
	vuint32_t DATA4:4;
	vuint32_t DATA5:4;
	vuint32_t DATA6:4;
	vuint32_t CRC:4;
  } B;
} CSRX_TFDATA_tag;

typedef union CSRX_TSDATA_union_tag { /*Transmit SLOW Channel Data Register */
  vuint32_t R;
  struct {
	vuint32_t MESSAGE_ID:8;
	vuint32_t DATA:16;
	vuint32_t C:1;
	vuint32_t  :1;
	vuint32_t CRC:6;
  } B;
} CSRX_TSDATA_tag;

typedef union CSRX_TSTAT_union_tag { /*Transmit Status Register */
  vuint32_t R;
  struct {
	vuint32_t :17;
	vuint32_t SLOWDN:1;
	vuint32_t SLOWACT:1;
	vuint32_t SLOWST:5;
	vuint32_t FASTDN:1;
	vuint32_t FASTACT:1;
	vuint32_t ENHCCFG:1;
	vuint32_t ENHC:1;
	vuint32_t PP:1;
	vuint32_t NIB:3;
  } B;
} CSRX_TSTAT_tag;

typedef union CSRX_TSTG_union_tag { /*Tx Sensor's Trigger Pulse Configuration Register */
  vuint32_t R;
  struct {
	vuint32_t :15;
	vuint32_t STPENB:1;
	vuint32_t HMTP:8;
	vuint32_t LMTP:8;
  } B;
} CSRX_TSTG_tag;

typedef union CSRX_RCFG_union_tag { /*Receiver Configuration Register */
  vuint32_t R;
  struct {
	vuint32_t TTCLK_STP:13;
	vuint32_t RX_CRCTYPE:1;
	vuint32_t RX_CRC_WITH_STATUS:1;
	vuint32_t RX_SYNC_RST:1;
	vuint32_t RX_STPMTP:8;
	vuint32_t RX_DNIB:3;
	vuint32_t RX_STPENB:1;
	vuint32_t RX_PPENB:1;
	vuint32_t RX_IDLEPOL:1;
	vuint32_t RX_CRCENB:1;
	vuint32_t RX_ENB:1;
  } B;
} CSRX_RCFG_tag;


typedef union CSRX_RFDATA_union_tag { /*Receive FAST Channel Data Register */
  vuint32_t R;
  struct {
	vuint32_t STAT:4;
	vuint32_t DATA1:4;
	vuint32_t DATA2:4;
	vuint32_t DATA3:4;
	vuint32_t DATA4:4;
	vuint32_t DATA5:4;
	vuint32_t DATA6:4;
	vuint32_t CRC:4;
  } B;
} CSRX_RFDATA_tag;

typedef union CSRX_RSDATA_union_tag { /*Receive SLOW Channel Data Register */
  vuint32_t R;
  struct {
	vuint32_t MESSAGE_ID:8;
	vuint32_t DATA:16;
	vuint32_t C:1;
	vuint32_t  :1;
	vuint32_t CRC:6;
  } B;
} CSRX_RSDATA_tag;


typedef union CSRX_RSTAT_union_tag { /*Receive Status Register */
  vuint32_t R;
  struct {
	vuint32_t RX_TTCLK:16;
	vuint32_t RX_SYNC:1;
	vuint32_t RXFAST_DN:1;
	vuint32_t RXSLOW_DN:1;
	vuint32_t RXSLOW_ST:5;
	vuint32_t RXSLOW_FORMATERR:1;
	vuint32_t RXSLOW_CRCERR:1;
	vuint32_t RX_FRMERR:1;
	vuint32_t RX_CRCERR:1;
	vuint32_t PP:1;
	vuint32_t RXNIB:3;
  } B;
} CSRX_RSTAT_tag;

typedef union CSRX_RSYNC_union_tag { /*Receive Sync Register */
  vuint32_t R;
  struct {
	vuint32_t RSYNC_MAX:16;
	vuint32_t RSYNC_MIN:16;
  } B;
} CSRX_RSYNC_tag;

typedef union CSRX_REG_union_tag {
	CSRX_TCFG_tag   TCFG;
	CSRX_TTFT_tag   TTFT;
	CSRX_TFDATA_tag TFDATA;
	CSRX_TSDATA_tag TSDATA;
	CSRX_TSTAT_tag  TSTAT;
	CSRX_TSTG_tag   TSTG;
	uint32_t CSRX_reserved1[2];
	CSRX_RCFG_tag   RCFG;
	CSRX_RFDATA_tag RFDATA;
	CSRX_RSDATA_tag RSDATA;
	CSRX_RSTAT_tag  RSTAT;
	CSRX_RSYNC_tag  RSYNC;
	uint32_t CSRX_reserved2[3];
} CSRX_REG_tag;

struct CSRX_tag{
	CSRX_TCFG_tag   TCFG;
	CSRX_TTFT_tag   TTFT;
	CSRX_TFDATA_tag TFDATA;
	CSRX_TSDATA_tag TSDATA;
	CSRX_TSTAT_tag  TSTAT;
	CSRX_TSTG_tag   TSTG;
	uint32_t CSRX_reserved1[2];
	CSRX_RCFG_tag   RCFG;
	CSRX_RFDATA_tag RFDATA;
	CSRX_RSDATA_tag RSDATA;
	CSRX_RSTAT_tag  RSTAT;
	CSRX_RSYNC_tag  RSYNC;
	uint32_t CSRX_reserved2[3];
};

#endif
