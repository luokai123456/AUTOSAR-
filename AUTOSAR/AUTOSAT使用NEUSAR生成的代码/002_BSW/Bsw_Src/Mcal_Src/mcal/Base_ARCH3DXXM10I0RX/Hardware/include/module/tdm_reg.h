#ifndef TDM_REG_H_
#define TDM_REG_H_

/* ============================================================================
   =============================== Module: TDM ================================
   ============================================================================ */

typedef union TDM_TDRSR_union_tag {    /* TDR Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t TDRSR5:1;
    vuint32_t TDRSR4:1;
    vuint32_t TDRSR3:1;
    vuint32_t TDRSR2:1;
    vuint32_t TDRSR1:1;
    vuint32_t TDRSR0:1;
  } B;
} TDM_TDRSR_tag;

typedef union TDM_LFPAR_union_tag {    /* Last Flash Programmed Address Register */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t LFPAR:24;
  } B;
} TDM_LFPAR_tag;

typedef union TDM_DBA_union_tag {      /* Diary Base Address */
  vuint32_t R;
  struct {
    vuint32_t DBA:32;
  } B;
} TDM_DBA_tag;

typedef union TDM_STO_KEY_union_tag {  /* Software Tamper Override Key Region */
  vuint32_t R;
  struct {
    vuint32_t STO_KEY:32;
  } B;
} TDM_STO_KEY_tag;

struct TDM_tag {
  TDM_TDRSR_tag TDRSR;                 /* TDR Status Register */
  TDM_LFPAR_tag LFPAR;                 /* Last Flash Programmed Address Register */
  TDM_DBA_tag DBA;                     /* Diary Base Address */
  uint8_t TDM_reserved0[4];
  TDM_STO_KEY_tag STO_KEY[6];          /* Software Tamper Override Key Region */
};

#endif
