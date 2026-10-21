#ifndef C55FMC_SM_BLK_REG_H_
#define C55FMC_SM_BLK_REG_H_

/* ============================================================================
   =============================== Module: C55FMC =============================
   ============================================================================ */

typedef union C55FMC_MCR_union_tag {   /* Module Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t RVE:1;                   /* Read Voltage Error */
    vuint32_t RRE:1;                   /* Read Reference Error */
    vuint32_t AEE:1;                   /* Address Encode Error */
    vuint32_t EEE:1;                   /* ECC after ECC Error */
    vuint32_t  :12;
    vuint32_t EER:1;                   /* ECC Event Error */
    vuint32_t RWE:1;                   /* Read-While-Write Event Error */
    vuint32_t SBC:1;                   /* Single Bit Correction */
    vuint32_t WIB:1;                   /* Write Invalid Bit */
    vuint32_t PEAS:1;                  /* Program Access Space */
    vuint32_t DONE:1;                  /* State Machine Status */
    vuint32_t PEG:1;                   /* Program/Erase Good */
    vuint32_t PECIE:1;                 /* Program/Erase Complete Interrupt Enable */
    vuint32_t FERS:1;                  /* Factory Erase and Program */
    vuint32_t WIBE:1;                  /* Write Invalid Bit Interrupt Enable */
    vuint32_t AWIB:1;                  /* Alternate Write Invalid Bit */
    vuint32_t PGM:1;                   /* Program */
    vuint32_t PSUS:1;                  /* Program Suspend */
    vuint32_t ERS:1;                   /* Erase */
    vuint32_t ESUS:1;                  /* Erase Suspend */
    vuint32_t EHV:1;                   /* Enable High Voltage */
  } B;
} C55FMC_MCR_tag;

typedef union C55FMC_MCRA_union_tag {  /* Alternate Module Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :20;
    vuint32_t PEASa:1;                 /* Program Access Space */
    vuint32_t DONEa:1;                 /* State Machine Status */
    vuint32_t PEGa:1;                  /* Program/Erase Good */
    vuint32_t  :4;
    vuint32_t PGMa:1;                  /* Program */
    vuint32_t PSUSa:1;                 /* Program Suspend */
    vuint32_t ERSa:1;                  /* Erase Suspend */
    vuint32_t ESUSa:1;                 /* Erase Suspend */
    vuint32_t EHVa:1;                  /* Enable High Voltage */
  } B;
} C55FMC_MCRA_tag;

typedef union C55FMC_MCRE_union_tag {  /* Extended Module Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t HT:1;                    /* High Temperature Enabled. */
    vuint32_t  :2;
    vuint32_t n256K:5;
    vuint32_t n64Kh:3;
    vuint32_t n32Kh:2;
    vuint32_t n16Kh:3;
    vuint32_t n64Km:3;
    vuint32_t n32Km:2;
    vuint32_t n1Km:3;
    vuint32_t n4Kl:8;
  } B;
} C55FMC_MCRE_tag;

typedef union C55FMC_LOCK0_union_tag { /* Lock 0 register */
  vuint32_t R;
  struct {
    vuint32_t TSLOCK:1;                /* UTest NVM Lock. */
    vuint32_t  :7;
    vuint32_t MIDLOCK:8;               /* Mid Block Lock */
    vuint32_t LOWLOCK:16;              /* Low Block Lock */
  } B;
} C55FMC_LOCK0_tag;

typedef union C55FMC_LOCK1_union_tag { /* Lock 1 register */
  vuint32_t R;
  struct {
    vuint32_t MTLOCK:16;               /* Mid Test Block Lock */
    vuint32_t LOWLOCK:16;              /* Low Block Lock */
  } B;
} C55FMC_LOCK1_tag;

typedef union C55FMC_LOCK2_union_tag { /* Lock 2 register */
  vuint32_t R;
  struct {
    vuint32_t A256KLOCK:32;            /* 256 KB Block Lock */
  } B;
} C55FMC_LOCK2_tag;

typedef union C55FMC_LOCK3_union_tag { /* Lock 3 register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t A256KLOCK:16;            /* 256 KB Block Lock */
  } B;
} C55FMC_LOCK3_tag;

typedef union C55FMC_LOCK4_union_tag { /* Lock 4 register */
  vuint32_t R;
  struct {
    vuint32_t MIDLOCK:32;              /* Mid Block Lock */
  } B;
} C55FMC_LOCK4_tag;

typedef union C55FMC_LOCK0A_union_tag { /* Alternate Lock 0 register */
  vuint32_t R;
  struct {
    vuint32_t TSLOCKa:1;                /* Alternate UTest NVM Lock. */
    vuint32_t  :7;
    vuint32_t MIDLOCKa:8;               /* Alternate Mid Block Lock */
    vuint32_t LOWLOCKa:16;              /* Alternate Low Block Lock */
  } B;
} C55FMC_LOCK0A_tag;

typedef union C55FMC_LOCK1A_union_tag { /* Alternate Lock 1 register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t LOWLOCKa:16;              /* Alternate Low Block Lock */
  } B;
} C55FMC_LOCK1A_tag;

typedef union C55FMC_LOCK2A_union_tag { /* Alternate Lock 2 register */
  vuint32_t R;
  struct {
    vuint32_t A256LOCKa:32;             /* Alternate 256 KB Block Lock */
  } B;
} C55FMC_LOCK2A_tag;

typedef union C55FMC_LOCK3A_union_tag { /* Alternate Lock 3 register */
  vuint32_t R;
  struct {
    vuint32_t MIDLOCKa:32;              /* Alternate Mid Block Lock */
  } B;
} C55FMC_LOCK3A_tag;

typedef union C55FMC_SEL0_union_tag {  /* Select 0 register */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t MIDSEL: 8;               /* Mid Block Select. */
    vuint32_t LOWSEL:16;               /* Low Block Select. */
  } B;
} C55FMC_SEL0_tag;

typedef union C55FMC_SEL1_union_tag {  /* Select 1 register */
  vuint32_t R;
  struct {
    vuint32_t MTSEL:16;                /* Mid Test Block Select. */
    vuint32_t LOWSEL:16;               /* Low Block Select. */
  } B;
} C55FMC_SEL1_tag;

typedef union C55FMC_SEL2_union_tag {  /* Select 2 register */
  vuint32_t R;
  struct {
    vuint32_t A256KSEL:32;             /* 256 KB Block Select. */
  } B;
} C55FMC_SEL2_tag;

typedef union C55FMC_SEL3_union_tag {  /* Select 3 register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t A256KSEL:16;             /* 256 KB Block Select. */
  } B;
} C55FMC_SEL3_tag;

typedef union C55FMC_SEL4_union_tag {  /* Select 4 register */
  vuint32_t R;
  struct {
    vuint32_t MIDSEL:32;               /* 256 KB Block Select. */
  } B;
} C55FMC_SEL4_tag;

typedef union C55FMC_ADR_union_tag {   /* Address register */
  vuint32_t R;
  struct {
    vuint32_t SAD:1;
    vuint32_t aH:1;
    vuint32_t aM:1;
    vuint32_t aL:1;
    vuint32_t a256k:1;
    vuint32_t a64k:1;
    vuint32_t a32k:1;
    vuint32_t a4k:1;
    vuint32_t ADDR:21;
    vuint32_t  :3;
  } B;
} C55FMC_ADR_tag;

typedef union C55FMC_UT0_union_tag {   /* UTest 0 register */
  vuint32_t R;
  struct {
    vuint32_t UTE:1;
    vuint32_t SBCE:1;
    vuint32_t  :11;
    vuint32_t CPR:1;
    vuint32_t CPA:1;
    vuint32_t CPE:1;
    vuint32_t  :6;
    vuint32_t NAIBP:1;
    vuint32_t AIBPE:1;
    vuint32_t  :1;
    vuint32_t AISUS:1;
    vuint32_t MRE:1;
    vuint32_t MRV:1;
    vuint32_t  :1;
    vuint32_t AIS:1;
    vuint32_t AIE:1;
    vuint32_t AID:1;
  } B;
} C55FMC_UT0_tag;

typedef union C55FMC_UM_union_tag {    /* UMISR register */
  vuint32_t R;
  struct {
    vuint32_t MISR:32;
  } B;
} C55FMC_UM_tag;

typedef union C55FMC_UM9_union_tag {   /* UMISR register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t MISR:1;                  /* MISR[288]. */
  } B;
} C55FMC_UM9_tag;

typedef union C55FMC_OPP0_union_tag {  /* Over-Program Protection 0 register */
  vuint32_t R;
  struct {
    vuint32_t LOWOPP:32;               /* Low Block Over-Program Protection[31:0]. */
  } B;
} C55FMC_OPP0_tag;

typedef union C55FMC_OPP1_union_tag {  /* Over-Program Protection 1 register */
  vuint32_t R;
  struct {
    vuint32_t MIDOPP:32;               /* Mid Block Over-Program Protection[31:0]. */
  } B;
} C55FMC_OPP1_tag;

typedef union C55FMC_OPP2_union_tag {  /* Over-Program Protection 2 register */
  vuint32_t R;
  struct {
    vuint32_t A256KOPP:32;             /* 256K Block Over-Program Protection[31:0]. */
  } B;
} C55FMC_OPP2_tag;

typedef union C55FMC_OPP3_union_tag {  /* Over-Program Protection 3 register */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t MIDOPP:8;                /* Mid Block Over-Program Protection[39:32]. */
  } B;
} C55FMC_OPP3_tag;

typedef union C55FMC_TMD_union_tag {   /* Test Mode Disable Password Check register */
  vuint32_t R;
  struct {
    vuint32_t PWD:32;                  /* Password challenge */
  } B;
} C55FMC_TMD_tag;

typedef union C55FMC_EXT_union_tag {   /* Extra Function register */
  vuint32_t R;
  struct {
    vuint32_t :11;
    vuint32_t retry_number:5;          /* Retry erase max number */
    vuint32_t :10;
    vuint32_t sread1:1;                /* Flash cell sread1 function */
    vuint32_t sread0:1;                /* Flash cell sread0 function */
    vuint32_t vread1:1;                /* Flash cell vread1 function */
    vuint32_t vread0:1;                /* Flash cell vread0 function */
    vuint32_t :1;
    vuint32_t retry:1;                 /* Flash cell retry erase function */
  } B;
} C55FMC_EXT_tag;

typedef union C55FMC_ECC_EER_INV_union_tag {
  vuint32_t R;
  struct {
    vuint32_t data_inv_bit2:8;
    vuint32_t ecc_inv_bit2:4;
    vuint32_t :2;
    vuint32_t data_inv_bit2_en:1;
    vuint32_t ecc_inv_bit2_en:1;
    vuint32_t data_inv_bit1:8;
    vuint32_t ecc_inv_bit1:4;
    vuint32_t :2;
    vuint32_t data_inv_bit1_en:1;
    vuint32_t ecc_inv_bit1_en:1;
  } B;
} C55FMC_ECC_EER_INV_tag;

struct C55FMC_tag {
  C55FMC_MCR_tag MCR;                  /* Module Configuration Register */
  C55FMC_MCRA_tag MCRA;                /* Alternate Module Configuration Register */
  C55FMC_MCRE_tag MCRE;                /* Extended Module Configuration Register */
  uint8_t C55FMC_reserved0[4];
  C55FMC_LOCK0_tag LOCK0;              /* Lock 0 register */
  C55FMC_LOCK1_tag LOCK1;              /* Lock 1 register */
  C55FMC_LOCK2_tag LOCK2;              /* Lock 2 register */
  C55FMC_LOCK3_tag LOCK3;              /* Lock 3 register */
  C55FMC_LOCK4_tag LOCK4;              /* Lock 4 register */
  uint8_t C55FMC_reserved1[4];
  C55FMC_LOCK0A_tag LOCK0A;            /* Alternate Lock 0 register */
  C55FMC_LOCK1A_tag LOCK1A;            /* Alternate Lock 1 register */
  C55FMC_LOCK2A_tag LOCK2A;            /* Alternate Lock 2 register */
  C55FMC_LOCK3A_tag LOCK3A;            /* Alternate Lock 3 register */
  C55FMC_SEL0_tag SEL0;                /* Select 0 register */
  C55FMC_SEL1_tag SEL1;                /* Select 1 register */
  C55FMC_SEL2_tag SEL2;                /* Select 2 register */
  C55FMC_SEL3_tag SEL3;                /* Select 3 register */
  C55FMC_SEL4_tag SEL4;                /* Select 4 register */
  uint8_t C55FMC_reserved3[4];
  C55FMC_ADR_tag ADR;                  /* Address register */
  C55FMC_UT0_tag UT0;                  /* UTest 0 register */
  C55FMC_UM_tag UM[9];                 /* UMISR register */
  C55FMC_UM9_tag UM9;                  /* UMISR register */
  C55FMC_OPP0_tag OPP0;                /* Over-Program Protection 0 register */
  C55FMC_OPP1_tag OPP1;                /* Over-Program Protection 1 register */
  C55FMC_OPP2_tag OPP2;                /* Over-Program Protection 2 register */
  C55FMC_OPP3_tag OPP3;                /* Over-Program Protection 3 register */
  C55FMC_TMD_tag TMD;                  /* Test Mode Disable Password Check register */
  uint8_t C55FMC_reserved4[12];
  C55FMC_EXT_tag EXT[4];               /* Extra Function register */
  C55FMC_ECC_EER_INV_tag ECC_EER_INV;  /* Ecc Error Invertor */
};
#endif
