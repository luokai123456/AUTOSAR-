#ifndef LIN_REG_H_
#define LIN_REG_H_

/* ============================================================================
   =============================== Module: LINFlexD ===========================
   ============================================================================ */

typedef union LINFlexD_LINCR1_union_tag { /* LIN Control Register 1 */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t CCD:1;
    vuint32_t CFD:1;
    vuint32_t LASE:1;
    vuint32_t AUTOWU:1;
    vuint32_t MBL:4;
    vuint32_t BF:1;
    vuint32_t  :1;
    vuint32_t LBKM:1;
    vuint32_t MME:1;
    vuint32_t SSBL:1;
    vuint32_t RBLM:1;
    vuint32_t SLEEP:1;
    vuint32_t INIT:1;
  } B;
} LINFlexD_LINCR1_tag;

typedef union LINFlexD_LINIER_union_tag { /* LIN Interrupt enable register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t SZIE:1;
    vuint32_t OCIE:1;
    vuint32_t BEIE:1;
    vuint32_t CEIE:1;
    vuint32_t HEIE:1;
    vuint32_t  :2;
    vuint32_t FEIE:1;
    vuint32_t BOIE:1;
    vuint32_t LSIE:1;
    vuint32_t WUIE:1;
    vuint32_t DBFIE:1;
    vuint32_t DBEIETOIE:1;
    vuint32_t DRIE:1;
    vuint32_t DTIE:1;
    vuint32_t HRIE:1;
  } B;
} LINFlexD_LINIER_tag;

typedef union LINFlexD_LINSR_union_tag { /* LIN Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t AUTOSYNC_COMP:1;
    vuint32_t RDC:3;
    vuint32_t LINS:4;                  /* LIN state */
    vuint32_t  :2;
    vuint32_t RMB:1;
    vuint32_t DRBNE:1;
    vuint32_t RXbusy:1;
    vuint32_t RDI:1;
    vuint32_t WUF:1;
    vuint32_t DBFF:1;
    vuint32_t DBEF:1;
    vuint32_t DRF:1;
    vuint32_t DTF:1;
    vuint32_t HRF:1;
  } B;
} LINFlexD_LINSR_tag;

typedef union LINFlexD_LINESR_union_tag { /* LIN Error Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t SZF:1;
    vuint32_t OCF:1;
    vuint32_t BEF:1;
    vuint32_t CEF:1;
    vuint32_t SFEF:1;
    vuint32_t SDEF:1;
    vuint32_t IDPEF:1;
    vuint32_t FEF:1;
    vuint32_t BOF:1;
    vuint32_t  :6;
    vuint32_t NF:1;
  } B;
} LINFlexD_LINESR_tag;

typedef union LINFlexD_UARTCR_union_tag { /* UART Mode Control Register */
  vuint32_t R;
  struct {
    vuint32_t MIS:1;
    vuint32_t CSP:3;
    vuint32_t OSR:4;
    vuint32_t ROSE:1;
    vuint32_t NEF:3;
    vuint32_t DTU_PCETX:1;             /* Disable Timeout in UART mode/Parity transmission and checking */
    vuint32_t SBUR:2;
    vuint32_t WLS:1;
    vuint32_t TDFL_TFC:3;
    vuint32_t RDFL_RFC:3;
    vuint32_t RFBM:1;
    vuint32_t TFBM:1;
    vuint32_t WL1:1;
    vuint32_t PC_1:1;
    vuint32_t RxEn:1;
    vuint32_t TxEn:1;
    vuint32_t PC_0:1;
    vuint32_t PCE:1;
    vuint32_t WL0:1;
    vuint32_t UART:1;
  } B;
} LINFlexD_UARTCR_tag;

typedef union LINFlexD_UARTSR_union_tag { /* UART Mode Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t SZF:1;
    vuint32_t OCF:1;
    vuint32_t PE:4;
    vuint32_t RMB:1;
    vuint32_t FEF:1;
    vuint32_t BOF:1;
    vuint32_t RDI:1;
    vuint32_t WUF:1;
    vuint32_t RFNE:1;
    vuint32_t TO:1;
    vuint32_t DRFRFE:1;
    vuint32_t DTFTFF:1;
    vuint32_t NF:1;
  } B;
} LINFlexD_UARTSR_tag;

typedef union LINFlexD_LINTCSR_union_tag { /* LIN Time-Out Control Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :21;
    vuint32_t MODE:1;
    vuint32_t IOT:1;
    vuint32_t TOCE:1;
    vuint32_t CNT:8;
  } B;
} LINFlexD_LINTCSR_tag;

typedef union LINFlexD_LINOCR_union_tag { /* LIN Output Compare Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t OC2:8;
    vuint32_t OC1:8;
  } B;
} LINFlexD_LINOCR_tag;

typedef union LINFlexD_LINTOCR_union_tag { /* LIN Time-Out Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :20;
    vuint32_t RTO:4;
    vuint32_t  :1;
    vuint32_t HTO:7;
  } B;
} LINFlexD_LINTOCR_tag;

typedef union LINFlexD_LINFBRR_union_tag { /* LIN Fractional Baud Rate Register */
  vuint32_t R;
  struct {
    vuint32_t  :28;
    vuint32_t FBR:4;
  } B;
} LINFlexD_LINFBRR_tag;

typedef union LINFlexD_LINIBRR_union_tag { /* LIN Integer Baud Rate Register */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t IBR:20;
  } B;
} LINFlexD_LINIBRR_tag;

typedef union LINFlexD_LINCFR_union_tag { /* LIN Checksum Field Register */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t CF:8;
  } B;
} LINFlexD_LINCFR_tag;

typedef union LINFlexD_LINCR2_union_tag { /* LIN Control Register 2 */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t TBDE:1;
    vuint32_t IOBE:1;
    vuint32_t IOPE:1;
    vuint32_t WURQ:1;
    vuint32_t DDRQ:1;
    vuint32_t DTRQ:1;
    vuint32_t ABRQ:1;
    vuint32_t HTRQ:1;
    vuint32_t  :8;
  } B;
} LINFlexD_LINCR2_tag;

typedef union LINFlexD_BIDR_union_tag { /* Buffer Identifier Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t DFL:6;
    vuint32_t DIR:1;
    vuint32_t CCS:1;
    vuint32_t  :2;
    vuint32_t ID:6;
  } B;
} LINFlexD_BIDR_tag;

typedef union LINFlexD_BDRL_union_tag { /* Buffer Data Register Least Significant */
  vuint32_t R;
  struct {
    vuint32_t DATA3:8;
    vuint32_t DATA2:8;
    vuint32_t DATA1:8;
    vuint32_t DATA0:8;
  } B;
} LINFlexD_BDRL_tag;

typedef union LINFlexD_BDRM_union_tag { /* Buffer Data Register Most Significant */
  vuint32_t R;
  struct {
    vuint32_t DATA7:8;
    vuint32_t DATA6:8;
    vuint32_t DATA5:8;
    vuint32_t DATA4:8;
  } B;
} LINFlexD_BDRM_tag;

typedef union LINFlexD_IFER_union_tag { /* Identifier Filter Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t FACT:16;
  } B;
} LINFlexD_IFER_tag;

typedef union LINFlexD_IFMI_union_tag { /* Identifier Filter Match Index */
  vuint32_t R;
  struct {
    vuint32_t  :27;
    vuint32_t IFMI:5;
  } B;
} LINFlexD_IFMI_tag;

typedef union LINFlexD_IFMR_union_tag { /* Identifier Filter Mode Register */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t IFM:8;
  } B;
} LINFlexD_IFMR_tag;

typedef union LINFlexD_IFCR_union_tag { /* Identifier Filter Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t DFL:6;                   /* Data Field Length */
    vuint32_t DIR:1;                   /* Direction */
    vuint32_t CCS:1;                   /* Classic Checksum */
    vuint32_t  :2;
    vuint32_t ID:6;                    /* Identifier */
  } B;
} LINFlexD_IFCR_tag;

typedef union LINFlexD_GCR_union_tag { /* Global Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t TDFBM:1;
    vuint32_t RDFBM:1;
    vuint32_t TDLIS:1;
    vuint32_t RDLIS:1;
    vuint32_t STOP:1;
    vuint32_t SR:1;
  } B;
} LINFlexD_GCR_tag;

typedef union LINFlexD_UARTPTO_union_tag { /* UART Preset Timeout Register */
  vuint32_t R;
  struct {
    vuint32_t  :20;
    vuint32_t PTO:12;
  } B;
} LINFlexD_UARTPTO_tag;

typedef union LINFlexD_UARTCTO_union_tag { /* UART Current Timeout Register */
  vuint32_t R;
  struct {
    vuint32_t  :20;
    vuint32_t CTO:12;
  } B;
} LINFlexD_UARTCTO_tag;

typedef union LINFlexD_DMATXE_union_tag { /* DMA Tx Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t DTE:16;
  } B;
} LINFlexD_DMATXE_tag;

typedef union LINFlexD_DMARXE_union_tag { /* DMA Rx Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t DRE:16;
  } B;
} LINFlexD_DMARXE_tag;

typedef union LINFlexD_PTD_union_tag { /* PSI5-S Tx Delay register */
  vuint32_t R;
  struct {
    vuint32_t  :27;
    vuint32_t IFD:4;
    vuint32_t EN:1;
  } B;
} LINFlexD_PTD_tag;

struct LINFlexD_tag {
  LINFlexD_LINCR1_tag LINCR1;          /* LIN Control Register 1 */
  LINFlexD_LINIER_tag LINIER;          /* LIN Interrupt enable register */
  LINFlexD_LINSR_tag LINSR;            /* LIN Status Register */
  LINFlexD_LINESR_tag LINESR;          /* LIN Error Status Register */
  LINFlexD_UARTCR_tag UARTCR;          /* UART Mode Control Register */
  LINFlexD_UARTSR_tag UARTSR;          /* UART Mode Status Register */
  LINFlexD_LINTCSR_tag LINTCSR;        /* LIN Time-Out Control Status Register */
  LINFlexD_LINOCR_tag LINOCR;          /* LIN Output Compare Register */
  LINFlexD_LINTOCR_tag LINTOCR;        /* LIN Time-Out Control Register */
  LINFlexD_LINFBRR_tag LINFBRR;        /* LIN Fractional Baud Rate Register */
  LINFlexD_LINIBRR_tag LINIBRR;        /* LIN Integer Baud Rate Register */
  LINFlexD_LINCFR_tag LINCFR;          /* LIN Checksum Field Register */
  LINFlexD_LINCR2_tag LINCR2;          /* LIN Control Register 2 */
  LINFlexD_BIDR_tag BIDR;              /* Buffer Identifier Register */
  LINFlexD_BDRL_tag BDRL;              /* Buffer Data Register Least Significant */
  LINFlexD_BDRM_tag BDRM;              /* Buffer Data Register Most Significant */
  LINFlexD_IFER_tag IFER;              /* Identifier Filter Enable Register */
  LINFlexD_IFMI_tag IFMI;              /* Identifier Filter Match Index */
  LINFlexD_IFMR_tag IFMR;              /* Identifier Filter Mode Register */
  LINFlexD_IFCR_tag IFCR[16];          /* Identifier Filter Control Register */
  LINFlexD_GCR_tag GCR;                /* Global Control Register */
  LINFlexD_UARTPTO_tag UARTPTO;        /* UART Preset Timeout Register */
  LINFlexD_UARTCTO_tag UARTCTO;        /* UART Current Timeout Register */
  LINFlexD_DMATXE_tag DMATXE;          /* DMA Tx Enable Register */
  LINFlexD_DMARXE_tag DMARXE;          /* DMA Rx Enable Register */
  LINFlexD_PTD_tag PTD;                /* PSI5-S Tx Delay register */
};

/**
 * @brief    LINFLEX Registers bits.
 * @details  LINIER register bit masks.
 */
#define LINFLEX_LINIER_SZIE_MASK_U32    ((uint32)0x00008000UL)
#define LINFLEX_LINIER_OCIE_MASK_U32    ((uint32)0x00004000UL)
#define LINFLEX_LINIER_BEIE_MASK_U32    ((uint32)0x00002000UL)
#define LINFLEX_LINIER_CEIE_MASK_U32    ((uint32)0x00001000UL)
#define LINFLEX_LINIER_HEIE_MASK_U32    ((uint32)0x00000800UL)
#define LINFLEX_LINIER_FEIE_MASK_U32    ((uint32)0x00000100UL)
#define LINFLEX_LINIER_BOIE_MASK_U32    ((uint32)0x00000080UL)
#define LINFLEX_LINIER_LSIE_MASK_U32    ((uint32)0x00000040UL)
#define LINFLEX_LINIER_WUIE_MASK_U32    ((uint32)0x00000020UL)
#define LINFLEX_LINIER_DBFIE_MASK_U32    ((uint32)0x00000010UL)
#define LINFLEX_LINIER_DBEIETOIE_MASK_U32    ((uint32)0x00000008UL)
#define LINFLEX_LINIER_DRIE_MASK_U32    ((uint32)0x00000004UL)
#define LINFLEX_LINIER_DTIE_MASK_U32    ((uint32)0x00000002UL)
#define LINFLEX_LINIER_HRIE_MASK_U32    ((uint32)0x00000001UL)
/**
 * @brief    LINFLEX Registers bits.
 * @details  LINBIDR register bit masks.
 */
#define LINFLEX_BIDR_DFL_EXT_MASK_U32  ((uint32)0x0000FC00UL)
#define LINFLEX_BIDR_DFL_MASK_U32      ((uint32)0x00000007UL)
/**
 * @brief    LINFLEX Registers bits.
 * @details  LINCR2 register bit masks.
 */
#define LINFLEX_LINCR2_TBDE_MASK_U32   ((uint32)0x00008000UL)
#define LINFLEX_LINCR2_IOBE_MASK_U32   ((uint32)0x00004000UL)
#define LINFLEX_LINCR2_IOPE_MASK_U32   ((uint32)0x00004000UL)
#define LINFLEX_LINCR2_WURQ_MASK_U32   ((uint32)0x00001000UL)
#define LINFLEX_LINCR2_DDRQ_MASK_U32   ((uint32)0x00000800UL)
#define LINFLEX_LINCR2_HTRQ_MASK_U32   ((uint32)0x00000100UL)
#define LINFLEX_LINCR2_ABRQ_MASK_U32   ((uint32)0x00000200UL)
#define LINFLEX_LINCR2_DTRQ_MASK_U32   ((uint32)0x00000400UL)
#define LINFLEX_LINCR2_REQUEST_MASK_U32    ((uint32)(LINFLEX_LINCR2_DTRQ_MASK_U32 | LINFLEX_LINCR2_ABRQ_MASK_U32 | LINFLEX_LINCR2_HTRQ_MASK_U32))
#define LINFLEX_LINFBRR_FBR_MASK_U32   ((uint32)0x0000000FUL)
#define LINFLEX_LINFBRR_DIV_F_MASK_U32 ((uint32)0x000000FFUL)
#define LINFLEX_LINIBRR_DIV_M_MASK_U32 ((uint32)0xFFFFFF00UL)
#define LIN_NUM_FILTER                                  16U   /** LIN driver number of filters **/

/**
 * @brief    LINFLEX Registers bits.
 * @details  LINSR register bit masks.
 */
#define LINFLEX_LINSR_HRF_MASK_U32     ((uint32)0x00000001UL)
#define LINFLEX_LINSR_DTF_MASK_U32     ((uint32)0x00000002UL)
#define LINFLEX_LINSR_DRF_MASK_U32     ((uint32)0x00000004UL)
#define LINFLEX_LINSR_WUF_MASK_U32     ((uint32)0x00000020UL)
#define LINFLEX_LINSR_DRBNE_MASK_U32   ((uint32)0x00000100UL)
#define LINFLEX_LINSR_RXBUSY_MASK_U32  ((uint32)0x00000080UL)
#define LINFLEX_LINSR_RMB_MASK_U32     ((uint32)0x00000200UL)
#define LINFLEX_LINSR_LINS_MASK_U32    ((uint32)0x0000F000UL)
#define LINFLEX_LINSR_FLAGS_MASK_U32   ((uint32)0x0000033FUL)

/**
 * @brief    LINFLEX Registers bits.
 * @details  LINESR register bit masks.
 */
#define LINFLEX_LINESR_NF_MASK_U32     ((uint32)0x00000001UL)
#define LINFLEX_LINESR_BOF_MASK_U32    ((uint32)0x00000080UL)
#define LINFLEX_LINESR_FEF_MASK_U32    ((uint32)0x00000100UL)
#define LINFLEX_LINESR_IDPEF_MASK_U32  ((uint32)0x00000200UL)
#define LINFLEX_LINESR_SDEF_MASK_U32   ((uint32)0x00000400UL)
#define LINFLEX_LINESR_SFEF_MASK_U32   ((uint32)0x00000800UL)
#define LINFLEX_LINESR_CEF_MASK_U32    ((uint32)0x00001000UL)
#define LINFLEX_LINESR_BEF_MASK_U32    ((uint32)0x00002000UL)
#define LINFLEX_LINESR_OCF_MASK_U32    ((uint32)0x00004000UL)
#define LINFLEX_LINESR_SZF_MASK_U32    ((uint32)0x00008000UL)
#define LINFLEX_LINESR_FLAGS_MASK_U32  ((uint32)0x0000FF81UL)

#define LINSR_LINS_IDLE_MASK                     (0x2U) /* PRQA S 1534 */
#define LINFlexD_LINTCSR_MODE_MASK               0x400u
#define LINFlexD_LINTCSR_MODE_SHIFT              10u
#define LINFlexD_LINTCSR_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINTCSR_MODE_SHIFT))&LINFlexD_LINTCSR_MODE_MASK)
#define LINFlexD_LINCR1_INIT_SHIFT               0u
#define LINFlexD_LINCR1_INIT_MASK                0x1u
#define LINFlexD_LINCR1_INIT(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINCR1_INIT_SHIFT))&LINFlexD_LINCR1_INIT_MASK)
#define LINFlexD_LINCR1_SLEEP_MASK               0x2u
#define LINFlexD_LINOCR_OC2_MASK                 0xFF00u
#define LINFlexD_LINOCR_OC1_MASK                 0xFFu
#define LINFLEX_BIDR_ID_MASK                     0x3FU

#endif
