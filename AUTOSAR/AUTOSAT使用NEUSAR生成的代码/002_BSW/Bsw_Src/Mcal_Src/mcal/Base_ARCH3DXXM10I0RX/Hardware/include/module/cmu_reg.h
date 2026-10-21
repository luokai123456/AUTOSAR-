#ifndef CMU_REG_H_
#define CMU_REG_H_

/* ============================================================================
   =============================== Module: CMU ================================
   ============================================================================ */

typedef union CMU_CSR_union_tag {      /* CMU Control Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t SFM:1;                   /* Start frequency measure. */
    vuint32_t  :13;
    vuint32_t CKSEL1:2;                /* Frequency measure clock selection bit. */
    vuint32_t  :5;
    vuint32_t RCDIV:2;                 /* CLKMT0_RMN division factor. */
    vuint32_t CME:1;                   /* CLKMN1 monitor enable. */
  } B;
} CMU_CSR_tag;

typedef union CMU_FDR_union_tag {      /* CMU Frequency Display Register */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t FD:20;                   /* Measured frequency bits. */
  } B;
} CMU_FDR_tag;

typedef union CMU_HFREFR_union_tag {   /* CMU High Frequency Reference Register CLKMN1 */
  vuint32_t R;
  struct {
    vuint32_t  :20;
    vuint32_t HFREF:12;                /* High Frequency reference value. */
  } B;
} CMU_HFREFR_tag;

typedef union CMU_LFREFR_union_tag {   /* CMU Low Frequency Reference Register CLKMN1 */
  vuint32_t R;
  struct {
    vuint32_t  :20;
    vuint32_t LFREF:12;                /* Low Frequency reference value. */
  } B;
} CMU_LFREFR_tag;

typedef union CMU_ISR_union_tag {      /* CMU Interrupt Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :28;
    vuint32_t  :1;
    vuint32_t FHHI:1;                  /* CLKMN1 frequency higher than high reference event status. */
    vuint32_t FLLI:1;                  /* CLKMN1 frequency less than low reference event status. */
    vuint32_t OLRI:1;                  /* Oscillator frequency less than f CLKMT0_RMN * 2RCDIVevent status. */
  } B;
} CMU_ISR_tag;

typedef union CMU_MDR_union_tag {      /* CMU Measurement Duration Register */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t MD:20;                   /* Measurement duration bits */
  } B;
} CMU_MDR_tag;

struct CMU_tag {
  CMU_CSR_tag CSR;                     /* CMU Control Status Register */
  CMU_FDR_tag FDR;                     /* CMU Frequency Display Register */
  CMU_HFREFR_tag HFREFR;               /* CMU High Frequency Reference Register CLKMN1 */
  CMU_LFREFR_tag LFREFR;               /* CMU Low Frequency Reference Register CLKMN1 */
  CMU_ISR_tag ISR;                     /* CMU Interrupt Status Register */
  uint8_t CMU_reserved0[4];
  CMU_MDR_tag MDR;                     /* CMU Measurement Duration Register */
};

#endif  /* CMU_REG_H_ */
