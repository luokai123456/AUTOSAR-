#ifndef I2S_REG_H_
#define I2S_REG_H_

/* ============================================================================
   =============================== Module: I2S ===========================
   ============================================================================ */

typedef union I2SM_CR_union_tag { /* I2S MASTER Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :14;
    vuint32_t ACRST:1;
    vuint32_t FIFORST:1;
    vuint32_t :1;
    vuint32_t RXFWL:3;
    vuint32_t :1;
    vuint32_t TXFWL:3;
    vuint32_t  :1;
    vuint32_t TXAUIE:1;
    vuint32_t SO_OBE:1;
    vuint32_t SCLK_OBE:1;
    vuint32_t RXIE:1;
    vuint32_t RXE:1;
    vuint32_t TXIE:1;
    vuint32_t TXE:1;
  } B;
} I2SM_CR_union_tag;

typedef union I2SM_SR_union_tag { /* I2S MASTER Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t RXBF:1;
    vuint32_t RXBE:1;
    vuint32_t TXBF:1;
    vuint32_t TXBE:1;
    vuint32_t RXBA:1;
    vuint32_t TXBA:1;
  } B;
} I2SM_SR_union_tag;

typedef union I2SM_ESR_union_tag { /* I2S MASTER ERROR Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :29;
    vuint32_t TXAU:1;
    vuint32_t RXERR:1;
    vuint32_t TXERR:1;
  } B;
} I2SM_ESR_union_tag;

typedef union I2SM_CDR_union_tag { /* I2S MASTER CLOCK DIVIDE RATIO Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t LRDIV:10;
  } B;
} I2SM_CDR_union_tag;

typedef union I2SM_TXDR_union_tag { /* I2S MASTER TX FIFO Register */
  vuint32_t R;
  struct {
    vuint32_t  LEFT_CHANNEL:16;
    vuint32_t  RIGHT_CHANNEL:16;
  } B;
} I2SM_TXDR_union_tag;

typedef union I2SM_RXDR_union_tag { /* I2S MASTER RX FIFO Register */
  vuint32_t R;
  struct {
    vuint32_t  LEFT_CHANNEL:16;
    vuint32_t  RIGHT_CHANNEL:16;
  } B;
} I2SM_RXDR_union_tag;

typedef union I2SM_DMACR_union_tag { /* I2S MASTER DMA Control Register */
  vuint32_t R;
  struct {
	vuint32_t  :13;
    vuint32_t  TXCNT:3;
    vuint32_t  :5;
    vuint32_t  RXCNT:3;
    vuint32_t  :6;
    vuint32_t  TXEABLE:1;
    vuint32_t  RXEABLE:1;
  } B;
} I2SM_DMACR_union_tag;

typedef union I2SM_ITCR_union_tag { /* I2S MASTER Integration Test Control Register */
  vuint32_t R;
  struct {
	vuint32_t  :31;
    vuint32_t  ITC:1;
  } B;
} I2SM_ITCR_union_tag;

typedef union I2SM_ITIR_union_tag { /* I2S MASTER Integration Test Input Register */
  vuint32_t R;
  struct {
	vuint32_t  :31;
    vuint32_t  ITSDIN:1;
  } B;
} I2SM_ITIR_union_tag;

typedef union I2SM_ITOR_union_tag { /* I2S MASTER Integration Test Output Register */
  vuint32_t R;
  struct {
	vuint32_t  :28;
    vuint32_t  ITIRQ:1;
    vuint32_t  ITLRCK:1;
    vuint32_t  ITSCLK:1;
    vuint32_t  ITSDOUT:1;
  } B;
} I2SM_ITOR_union_tag;

struct I2SM_tag {
  I2SM_CR_union_tag CR;          	   /* I2S MASTER Control Register */
  I2SM_SR_union_tag SR;          	   /* I2S MASTER Status Register */
  I2SM_ESR_union_tag ESR;              /* I2S MASTER ERROR Status Register */
  I2SM_CDR_union_tag CDR;              /* I2S MASTER CLOCK DIVIDE RATIO Register */
  I2SM_TXDR_union_tag TXDR;            /* I2S MASTER TX FIFO Register */
  I2SM_RXDR_union_tag RXDR;            /* I2S MASTER RX FIFO Register */
  I2SM_DMACR_union_tag DMACR;          /* I2S MASTER DMA Control Register */
  uint8_t I2SM_reserved0[744];
  I2SM_ITCR_union_tag ITCR;            /* I2S MASTER Integration Test Control Register */
  I2SM_ITIR_union_tag ITIR;        	   /* I2S MASTER Integration Test Input Register */
  I2SM_ITOR_union_tag ITOR;        	   /* I2S MASTER Integration Test Output Register */
};

typedef union I2SS_IER_union_tag { /* I2S SLAVE ENABLE Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t IEN:1;
  } B;
} I2SS_IER_union_tag;

typedef union I2SS_IRER_union_tag { /* I2S SLAVE as receiver ENABLE Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t RXEN:1;
  } B;
} I2SS_IRER_union_tag;

typedef union I2SS_ITER_union_tag { /* I2S SLAVE as receiver ENABLE Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t TXEN:1;
  } B;
} I2SS_ITER_union_tag;

typedef union I2SS_CER_union_tag { /* I2S SLAVE CLOCK generation enable */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t CLKEN:1;
  } B;
} I2SS_CER_union_tag;

typedef union I2SS_CCR_union_tag { /* I2S SLAVE CLOCK Configration Register */
  vuint32_t R;
  struct {
    vuint32_t  :27;
    vuint32_t WSS:2;
    vuint32_t SCLKG:3;
  } B;
} I2SS_CCR_union_tag;

typedef union I2SS_RXFFR_union_tag { /* I2S SLAVE FLUSH rx fifo Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t RXFFR:1;
  } B;
} I2SS_RXFFR_union_tag;

typedef union I2SS_TXFFR_union_tag { /* I2S SLAVE FLUSH tx fifo Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t TXFFR:1;
  } B;
} I2SS_TXFFR_union_tag;

typedef union I2SS_LRBR_union_tag { /* I2S SLAVE the left stereo data from receive channel Register */
  vuint32_t R;
  struct {
    vuint32_t  LRBR:32;
  } B;
} I2SS_LRBR_union_tag;

typedef union I2SS_LTHR_union_tag { /* I2S SLAVE the left stereo data to be transmitted Register */
  vuint32_t R;
  struct {
    vuint32_t  LTHR:32;
  } B;
} I2SS_LTHR_union_tag;

typedef union I2SS_LDR_union_tag {
	I2SS_LRBR_union_tag LRBR;
	I2SS_LTHR_union_tag LTHR;
}I2SS_LDR_union_tag;

typedef union I2SS_RRBR_union_tag { /* I2S SLAVE the right stereo data from receive channel Register */
  vuint32_t R;
  struct {
    vuint32_t  RRBR:32;
  } B;
} I2SS_RRBR_union_tag;

typedef union I2SS_RTHR_union_tag { /* I2S SLAVE the right stereo data to be transmitted Register */
  vuint32_t R;
  struct {
    vuint32_t  RTHR:32;
  } B;
} I2SS_RTHR_union_tag;

typedef union I2SS_RDR_union_tag {
	I2SS_RRBR_union_tag RRBR;
	I2SS_RTHR_union_tag RTHR;
}I2SS_RDR_union_tag;

typedef union I2SS_RER_union_tag { /* I2S SLAVE Receive channel Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t RXCHEN:1;
  } B;
} I2SS_RER_union_tag;

typedef union I2SS_TER_union_tag { /* I2S SLAVE trnsmitted channel Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t TXCHEN:1;
  } B;
} I2SS_TER_union_tag;

typedef union I2SS_RCR_union_tag { /* I2S SLAVE desired data resolution of receiver Register */
  vuint32_t R;
  struct {
    vuint32_t  :29;
    vuint32_t WLEN:3;
  } B;
} I2SS_RCR_union_tag;

typedef union I2SS_TCR_union_tag { /* I2S SLAVE desired data resolution of transmitter Register */
  vuint32_t R;
  struct {
    vuint32_t  :29;
    vuint32_t WLEN:3;
  } B;
} I2SS_TCR_union_tag;

typedef union I2SS_ISR_union_tag { /* I2S SLAVE status of interrupt Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t TXFO:1;
    vuint32_t TXFE:1;
    vuint32_t :1;
    vuint32_t RXFO:1;
    vuint32_t RXDA:1;
  } B;
} I2SS_ISR_union_tag;

typedef union I2SS_IMR_union_tag { /* I2S SLAVE mask of interrupt Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t TXFOM:1;
    vuint32_t TXFEM:1;
    vuint32_t :1;
    vuint32_t RXFOM:1;
    vuint32_t RXDAM:1;
  } B;
} I2SS_IMR_union_tag;

typedef union I2SS_ROR_union_tag { /* I2S SLAVE RX FIFO writte overrun Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t RXCHO:1;
  } B;
} I2SS_ROR_union_tag;

typedef union I2SS_TOR_union_tag { /* I2S SLAVE TX FIFO writte overrun Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t TXCHO:1;
  } B;
} I2SS_TOR_union_tag;

typedef union I2SS_RFCR_union_tag { /* I2S SLAVE trriger level in RX FIFO Register */
  vuint32_t R;
  struct {
    vuint32_t  :28;
    vuint32_t RXCHDT:4;
  } B;
} I2SS_RFCR_union_tag;

typedef union I2SS_TFCR_union_tag { /* I2S SLAVE trriger level in TX FIFO Register */
  vuint32_t R;
  struct {
    vuint32_t  :28;
    vuint32_t TXCHDT:4;
  } B;
} I2SS_TFCR_union_tag;

typedef union I2SS_RFF_union_tag { /* I2S SLAVE flush an indivial RX FIFO  Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t RXCHFR:1;
  } B;
} I2SS_RFF_union_tag;

typedef union I2SS_TFF_union_tag { /* I2S SLAVE flush an indivial TX FIFO  Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t TXCHFR:1;
  } B;
} I2SS_TFF_union_tag;

struct I2SS_tag {
  I2SS_IER_union_tag IER;          	   /* I2S SLAVE ENABLE Register */
  I2SS_IRER_union_tag IRER;            /* I2S SLAVE as receiver ENABLE Register */
  I2SS_ITER_union_tag ITER;            /* I2S SLAVE as receiver ENABLE Register */
  I2SS_CER_union_tag CER;			   /* I2S SLAVE CLOCK generation enable Register */
  I2SS_CCR_union_tag CCR;			   /* I2S SLAVE CLOCK Configration Register */
  I2SS_RXFFR_union_tag RXFFR;          /* I2S SLAVE FLUSH rx fifo Register */
  I2SS_TXFFR_union_tag TXFFR;          /* I2S SLAVE FLUSH tx fifo Register */
  uint8_t I2SS_reserved0[8];
  I2SS_LDR_union_tag LDR;
  I2SS_RDR_union_tag RDR;
  I2SS_RER_union_tag RER;			   /* I2S SLAVE Receive channel Enable Register */
  I2SS_TER_union_tag TER;			   /* I2S SLAVE trnsmitted channel Enable Register */
  I2SS_RCR_union_tag RCR;			   /* I2S SLAVE desired data resolution of receiver Register */
  I2SS_TCR_union_tag TCR;			   /* I2S SLAVE desired data resolution of transmitter Register */
  I2SS_ISR_union_tag ISR;			   /* I2S SLAVE status of interrupt Register */
  I2SS_IMR_union_tag IMR;			   /* I2S SLAVE mask of interrupt Register */
  I2SS_ROR_union_tag ROR;			   /* I2S SLAVE RX FIFO writte overrun Register */
  I2SS_TOR_union_tag TOR;			   /* I2S SLAVE TX FIFO writte overrun Register */
  I2SS_RFCR_union_tag RFCR;			   /* I2S SLAVE trriger level in RX FIFO Register */
  I2SS_TFCR_union_tag TFCR;			   /* I2S SLAVE trriger level in TX FIFO Register */
  I2SS_RFF_union_tag RFF;			   /* I2S SLAVE flush an indivial RX FIFO  Register */
  I2SS_TFF_union_tag TFF;			   /* I2S SLAVE flush an indivial TX FIFO  Register */
};

#endif
