#ifndef T40FMC_REG_H_
#define T40FMC_REG_H_
/* ============================================================================
   =============================== Module: T40FMC =============================
   ============================================================================ */

typedef union T40FMC_MCR_union_tag {   /* Module Configuration Register */
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
    vuint32_t  :1;
    vuint32_t PEAS:1;                  /* Program Access Space */
    vuint32_t DONE:1;                  /* State Machine Status */
    vuint32_t PEG:1;                   /* Program/Erase Good */
    vuint32_t PECIE:1;                 /* Program/Erase Complete Interrupt Enable */
    vuint32_t FERS:1;                  /* Factory Erase and Program */
    vuint32_t  :2;
    vuint32_t PGM:1;                   /* Program */
    vuint32_t PSUS:1;                  /* Program Suspend */
    vuint32_t ERS:1;                   /* Erase */
    vuint32_t ESUS:1;                  /* Erase Suspend */
    vuint32_t EHV:1;                   /* Enable High Voltage */
  } B;
} T40FMC_MCR_tag;

typedef union T40FMC_MCRA_union_tag {  /* Alternate Module Configuration Register */
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
} T40FMC_MCRA_tag;

typedef union T40FMC_MCRE_union_tag {  /* Extended Module Configuration Register */
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
    vuint32_t n16Km:3;
    vuint32_t n64Kl:3;
    vuint32_t n32Kl:2;
    vuint32_t n16Kl:3;
  } B;
} T40FMC_MCRE_tag;

typedef union T40FMC_LOCK0_union_tag { /* Lock 0 register */
  vuint32_t R;
  struct {
    vuint32_t TSLOCK:1;                /* UTest NVM Lock. */
    vuint32_t  :1;
    vuint32_t LOWLOCK:14;              /* Low Block Lock */
    vuint32_t MIDLOCK:16;              /* Mid Block Lock */
  } B;
} T40FMC_LOCK0_tag;

typedef union T40FMC_LOCK1_union_tag { /* Lock 1 register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t HIGHLOCK:16;             /* High Block Lock */
  } B;
} T40FMC_LOCK1_tag;

typedef union T40FMC_LOCK2_union_tag { /* Lock 2 register */
  vuint32_t R;
  struct {
    vuint32_t A256KLOCK:32;            /* 256 KB Block Lock */
  } B;
} T40FMC_LOCK2_tag;

typedef union T40FMC_LOCK3_union_tag { /* Lock 3 register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t A256KLOCK:16;            /* 256 KB Block Lock */
  } B;
} T40FMC_LOCK3_tag;

typedef union T40FMC_LOCK0A_union_tag { /* Alternate Lock 0 register */
  vuint32_t R;
  struct {
    vuint32_t TSLOCKa:1;               /* Alternate UTest NVM Lock. */
    vuint32_t  :1;
    vuint32_t LOWLOCKa:14;             /* Alternate Low Block Lock */
    vuint32_t MIDLOCKa:16;             /* Alternate Mid Block Lock */
  } B;
} T40FMC_LOCK0A_tag;

typedef union T40FMC_LOCK1A_union_tag { /* Alternate Lock 1 register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t HIGHLOCKa:16;            /* Alternate High Block Lock */
  } B;
} T40FMC_LOCK1A_tag;

typedef union T40FMC_SEL0_union_tag {  /* Select 0 register */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t LOWSEL:14;               /* LOW Block Select. */
    vuint32_t MIDSEL:16;               /* Mid Block Select. */
  } B;
} T40FMC_SEL0_tag;

typedef union T40FMC_SEL1_union_tag {  /* Select 1 register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t HIGHSEL:16;              /* High Block Select. */
  } B;
} T40FMC_SEL1_tag;

typedef union T40FMC_SEL2_union_tag {  /* Select 2 register */
  vuint32_t R;
  struct {
    vuint32_t A256KSEL:32;             /* 256 KB Block Select. */
  } B;
} T40FMC_SEL2_tag;

typedef union T40FMC_SEL3_union_tag {  /* Select 3 register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t A256KSEL:16;             /* 256 KB Block Select. */
  } B;
} T40FMC_SEL3_tag;

typedef union T40FMC_ADR_union_tag {   /* Address register */
  vuint32_t R;
  struct {
    vuint32_t SAD:1;
    vuint32_t aH:1;
    vuint32_t aM:1;
    vuint32_t aL:1;
    vuint32_t a256k:1;
    vuint32_t a64k:1;
    vuint32_t a32k:1;
    vuint32_t a16k:1;
    vuint32_t ADDR:21;
    vuint32_t  :3;
  } B;
} T40FMC_ADR_tag;

typedef union T40FMC_UT0_union_tag {   /* UTest 0 register */
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
} T40FMC_UT0_tag;

typedef union T40FMC_UM_union_tag {    /* UMISR register */
  vuint32_t R;
  struct {
    vuint32_t MISR:32;
  } B;
} T40FMC_UM_tag;

typedef union T40FMC_UM9_union_tag {   /* UMISR register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t MISR:1;                  /* MISR[288]. */
  } B;
} T40FMC_UM9_tag;

typedef union T40FMC_OPP0_union_tag {  /* Over-Program Protection 0 register */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t LOWOPP:14;               /* Low Block Over-Program Protection[13:0]. */
    vuint32_t MIDOPP:16;               /* Mid Block Over-Program Protection[15:0]. */
  } B;
} T40FMC_OPP0_tag;

typedef union T40FMC_OPP1_union_tag {  /* Over-Program Protection 1 register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t HIGHOPP:16;              /* High Block Over-Program Protection[15:0]. */
  } B;
} T40FMC_OPP1_tag;

typedef union T40FMC_OPP2_union_tag {  /* Over-Program Protection 2 register */
  vuint32_t R;
  struct {
    vuint32_t A256KOPP:32;             /* 256K Block Over-Program Protection[31:0]. */
  } B;
} T40FMC_OPP2_tag;

typedef union T40FMC_OPP3_union_tag {  /* Over-Program Protection 3 register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t A256KOPP:16;             /* 256K Block Over-Program Protection[47:32]. */
  } B;
} T40FMC_OPP3_tag;

typedef union T40FMC_TMD_union_tag {   /* Test Mode Disable Password Check register */
  vuint32_t R;
  struct {
    vuint32_t PWD:32;                  /* Password challenge */
  } B;
} T40FMC_TMD_tag;

struct T40FMC_tag {
  T40FMC_MCR_tag MCR;                  /* Module Configuration Register */
  T40FMC_MCRA_tag MCRA;                /* Alternate Module Configuration Register */
  T40FMC_MCRE_tag MCRE;                /* Extended Module Configuration Register */
  uint8_t T40FMC_reserved0[4];
  T40FMC_LOCK0_tag LOCK0;              /* Lock 0 register */
  T40FMC_LOCK1_tag LOCK1;              /* Lock 1 register */
  T40FMC_LOCK2_tag LOCK2;              /* Lock 2 register */
  T40FMC_LOCK3_tag LOCK3;              /* Lock 3 register */
  uint8_t T40FMC_reserved1[8];
  T40FMC_LOCK0A_tag LOCK0A;            /* Alternate Lock 0 register */
  T40FMC_LOCK1A_tag LOCK1A;            /* Alternate Lock 1 register */
  uint8_t T40FMC_reserved2[8];
  T40FMC_SEL0_tag SEL0;                /* Select 0 register */
  T40FMC_SEL1_tag SEL1;                /* Select 1 register */
  T40FMC_SEL2_tag SEL2;                /* Select 2 register */
  T40FMC_SEL3_tag SEL3;                /* Select 3 register */
  uint8_t T40FMC_reserved3[8];
  T40FMC_ADR_tag ADR;                  /* Address register */
  T40FMC_UT0_tag UT0;                  /* UTest 0 register */
  T40FMC_UM_tag UM[9];                 /* UMISR register */
  T40FMC_UM9_tag UM9;                  /* UMISR register */
  T40FMC_OPP0_tag OPP0;                /* Over-Program Protection 0 register */
  T40FMC_OPP1_tag OPP1;                /* Over-Program Protection 1 register */
  T40FMC_OPP2_tag OPP2;                /* Over-Program Protection 2 register */
  T40FMC_OPP3_tag OPP3;                /* Over-Program Protection 3 register */
  T40FMC_TMD_tag TMD;                  /* Test Mode Disable Password Check register */
};

#endif
