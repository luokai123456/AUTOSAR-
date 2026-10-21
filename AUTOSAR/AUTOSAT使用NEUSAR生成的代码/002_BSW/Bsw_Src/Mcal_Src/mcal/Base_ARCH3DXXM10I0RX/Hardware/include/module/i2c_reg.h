#ifndef I2C_REG_H_
#define I2C_REG_H_

/* ============================================================================
   =============================== Module: I2C ================================
   ============================================================================ */

typedef union I2C_IBAD_union_tag {     /* I2C Bus Address Register */
  vuint8_t R;
  struct {
    vuint8_t ADR:7;
    vuint8_t  :1;
  } B;
} I2C_IBAD_tag;

typedef union I2C_IBFD_union_tag {     /* I2C Bus Frequency Divider Register */
  vuint8_t R;
  struct {
    vuint8_t IBC:8;
  } B;
} I2C_IBFD_tag;

typedef union I2C_IBCR_union_tag {     /* I2C Bus Control Register */
  vuint8_t R;
  struct {
    vuint8_t MDIS:1;
    vuint8_t IBIE:1;
    vuint8_t MSSL:1;
    vuint8_t TXRX:1;
    vuint8_t NOACK:1;
    vuint8_t RSTA:1;
    vuint8_t DMAEN:1;
    vuint8_t  :1;
  } B;
} I2C_IBCR_tag;

typedef union I2C_IBSR_union_tag {     /* I2C Bus Status Register */
  vuint8_t R;
  struct {
    vuint8_t TCF:1;
    vuint8_t IAAS:1;
    vuint8_t IBB:1;
    vuint8_t IBAL:1;
    vuint8_t  :1;
    vuint8_t SRW:1;
    vuint8_t IBIF:1;
    vuint8_t RXAK:1;
  } B;
} I2C_IBSR_tag;

typedef union I2C_IBDR_union_tag {     /* I2C Bus Data I/O Register */
  vuint8_t R;
  struct {
    vuint8_t DATA:8;
  } B;
} I2C_IBDR_tag;

typedef union I2C_IBIC_union_tag {     /* I2C Bus Interrupt Config Register */
  vuint8_t R;
  struct {
    vuint8_t BIIE:1;
    vuint8_t BYTERXIE:1;
    vuint8_t  :6;
  } B;
} I2C_IBIC_tag;

typedef union I2C_IBDBG_union_tag {    /* I2C Bus Debug Register */
  vuint8_t R;
  struct {
    vuint8_t  :6;
    vuint8_t IPG_DEBUG_HALTED:1;
    vuint8_t IPG_DEBUG_EN:1;
  } B;
} I2C_IBDBG_tag;

struct I2C_tag {
  I2C_IBAD_tag IBAD;                   /* I2C Bus Address Register */
  I2C_IBFD_tag IBFD;                   /* I2C Bus Frequency Divider Register */
  I2C_IBCR_tag IBCR;                   /* I2C Bus Control Register */
  I2C_IBSR_tag IBSR;                   /* I2C Bus Status Register */
  I2C_IBDR_tag IBDR;                   /* I2C Bus Data I/O Register */
  I2C_IBIC_tag IBIC;                   /* I2C Bus Interrupt Config Register */
  I2C_IBDBG_tag IBDBG;                 /* I2C Bus Debug Register */
};

/* IBAD Bit Fields */
#define I2C_IBAD_ADR_MASK                        0xFEu
#define I2C_IBAD_ADR_SHIFT                       1u
#define I2C_IBAD_ADR_WIDTH                       7u
#define I2C_IBAD_ADR(x)                          (((uint8_t)(((uint8_t)(x)) << I2C_IBAD_ADR_SHIFT))&I2C_IBAD_ADR_MASK)
/* IBFD Bit Fields */
#define I2C_IBFD_IBC_MASK                        0xFFu
#define I2C_IBFD_IBC_SHIFT                       0u
#define I2C_IBFD_IBC_WIDTH                       8u
#define I2C_IBFD_IBC(x)                          (((uint8_t)(((uint8_t)(x)) << I2C_IBFD_IBC_SHIFT))&I2C_IBFD_IBC_MASK)
/* IBCR Bit Fields */
#define I2C_IBCR_DMAEN_MASK                      0x2u
#define I2C_IBCR_DMAEN_SHIFT                     1u
#define I2C_IBCR_DMAEN_WIDTH                     1u
#define I2C_IBCR_DMAEN(x)                        (((uint8_t)(((uint8_t)(x)) << I2C_IBCR_DMAEN_SHIFT))&I2C_IBCR_DMAEN_MASK)
#define I2C_IBCR_RSTA_MASK                       0x4u
#define I2C_IBCR_RSTA_SHIFT                      2u
#define I2C_IBCR_RSTA_WIDTH                      1u
#define I2C_IBCR_RSTA(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBCR_RSTA_SHIFT))&I2C_IBCR_RSTA_MASK)
#define I2C_IBCR_NOACK_MASK                      0x8u
#define I2C_IBCR_NOACK_SHIFT                     3u
#define I2C_IBCR_NOACK_WIDTH                     1u
#define I2C_IBCR_NOACK(x)                        (((uint8_t)(((uint8_t)(x)) << I2C_IBCR_NOACK_SHIFT))&I2C_IBCR_NOACK_MASK)
#define I2C_IBCR_TXRX_MASK                       0x10u
#define I2C_IBCR_TXRX_SHIFT                      4u
#define I2C_IBCR_TXRX_WIDTH                      1u
#define I2C_IBCR_TXRX(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBCR_TXRX_SHIFT))&I2C_IBCR_TXRX_MASK)
#define I2C_IBCR_MSSL_MASK                       0x20u
#define I2C_IBCR_MSSL_SHIFT                      5u
#define I2C_IBCR_MSSL_WIDTH                      1u
#define I2C_IBCR_MSSL(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBCR_MSSL_SHIFT))&I2C_IBCR_MSSL_MASK)
#define I2C_IBCR_IBIE_MASK                       0x40u
#define I2C_IBCR_IBIE_SHIFT                      6u
#define I2C_IBCR_IBIE_WIDTH                      1u
#define I2C_IBCR_IBIE(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBCR_IBIE_SHIFT))&I2C_IBCR_IBIE_MASK)
#define I2C_IBCR_MDIS_MASK                       0x80u
#define I2C_IBCR_MDIS_SHIFT                      7u
#define I2C_IBCR_MDIS_WIDTH                      1u
#define I2C_IBCR_MDIS(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBCR_MDIS_SHIFT))&I2C_IBCR_MDIS_MASK)
/* IBSR Bit Fields */
#define I2C_IBSR_RXAK_MASK                       0x1u
#define I2C_IBSR_RXAK_SHIFT                      0u
#define I2C_IBSR_RXAK_WIDTH                      1u
#define I2C_IBSR_RXAK(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBSR_RXAK_SHIFT))&I2C_IBSR_RXAK_MASK)
#define I2C_IBSR_IBIF_MASK                       0x2u
#define I2C_IBSR_IBIF_SHIFT                      1u
#define I2C_IBSR_IBIF_WIDTH                      1u
#define I2C_IBSR_IBIF(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBSR_IBIF_SHIFT))&I2C_IBSR_IBIF_MASK)
#define I2C_IBSR_SRW_MASK                        0x4u
#define I2C_IBSR_SRW_SHIFT                       2u
#define I2C_IBSR_SRW_WIDTH                       1u
#define I2C_IBSR_SRW(x)                          (((uint8_t)(((uint8_t)(x)) << I2C_IBSR_SRW_SHIFT))&I2C_IBSR_SRW_MASK)
#define I2C_IBSR_IBB_MASK                        0x20u
#define I2C_IBSR_IBB_SHIFT                       5u
#define I2C_IBSR_IBB_WIDTH                       1u
#define I2C_IBSR_IBB(x)                          (((uint8_t)(((uint8_t)(x)) << I2C_IBSR_IBB_SHIFT))&I2C_IBSR_IBB_MASK)
#define I2C_IBSR_IAAS_MASK                       0x40u
#define I2C_IBSR_IAAS_SHIFT                      6u
#define I2C_IBSR_IAAS_WIDTH                      1u
#define I2C_IBSR_IAAS(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBSR_IAAS_SHIFT))&I2C_IBSR_IAAS_MASK)
#define I2C_IBSR_TCF_MASK                        0x80u
#define I2C_IBSR_TCF_SHIFT                       7u
#define I2C_IBSR_TCF_WIDTH                       1u
#define I2C_IBSR_TCF(x)                          (((uint8_t)(((uint8_t)(x)) << I2C_IBSR_TCF_SHIFT))&I2C_IBSR_TCF_MASK)
/* IBDR Bit Fields */
#define I2C_IBDR_DATA_MASK                       0xFFu
#define I2C_IBDR_DATA_SHIFT                      0u
#define I2C_IBDR_DATA_WIDTH                      8u
#define I2C_IBDR_DATA(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBDR_DATA_SHIFT))&I2C_IBDR_DATA_MASK)
/* IBIC Bit Fields */
#define I2C_IBIC_BIIE_MASK                       0x80u
#define I2C_IBIC_BIIE_SHIFT                      7u
#define I2C_IBIC_BIIE_WIDTH                      1u
#define I2C_IBIC_BIIE(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBIC_BIIE_SHIFT))&I2C_IBIC_BIIE_MASK)

#define I2C_IBSR_IBAL_MASK                       0x10u
#define I2C_IBSR_IBAL_SHIFT                      4u
#define I2C_IBSR_IBAL(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBSR_IBAL_SHIFT))&I2C_IBSR_IBAL_MASK)

#define I2C_IBSR_IBIF(x)                         (((uint8_t)(((uint8_t)(x)) << I2C_IBSR_IBIF_SHIFT))&I2C_IBSR_IBIF_MASK)

#endif
