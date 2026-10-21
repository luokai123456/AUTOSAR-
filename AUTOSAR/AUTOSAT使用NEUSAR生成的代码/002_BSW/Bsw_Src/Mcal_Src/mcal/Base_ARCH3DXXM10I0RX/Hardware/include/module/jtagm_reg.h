#ifndef JTAGM_REG_H_
#define JTAGM_REG_H_

/* ============================================================================
   =============================== Module: JTAGM ==============================
   ============================================================================ */

typedef union JTAGM_MCR_union_tag {    /* Module Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t SWRESET:1;
    vuint32_t evto0_sense:2;
    vuint32_t evto1_sense:2;
    vuint32_t evto_IE:1;
    vuint32_t evti0_assert:1;
    vuint32_t evti1_assert:1;
    vuint32_t  :10;
    vuint32_t inter_jtag_frame_timer:6;
    vuint32_t  :1;
    vuint32_t SIE:1;
    vuint32_t IIE:1;
    vuint32_t TCKSEL:3;
    vuint32_t jtagm_JCOMP:1;
    vuint32_t DTM:1;
  } B;
} JTAGM_MCR_tag;

typedef union JTAGM_SR_union_tag {     /* Status Register */
  vuint32_t R;
  struct {
    vuint32_t Overrun:1;
    vuint32_t  :1;
    vuint32_t TXGOOD:1;
    vuint32_t TXERROR:1;
    vuint32_t RXOVFL:1;
    vuint32_t INVFPS:1;
    vuint32_t INVICLC:1;
    vuint32_t ILLLCT:1;
    vuint32_t  :1;
    vuint32_t LVDSEN:1;
    vuint32_t JTAGEN:1;
    vuint32_t LVDSSAFE:1;
    vuint32_t JTAGSAFE:1;
    vuint32_t LVDSESC:1;
    vuint32_t LFASTEN:1;
    vuint32_t TOOL:1;
    vuint32_t evto0_edge:1;
    vuint32_t evto1_edge:1;
    vuint32_t SPU_INT_CLR:1;
    vuint32_t SPU_INT:1;
    vuint32_t CRC_err:1;
    vuint32_t Nexus_err:1;
    vuint32_t Idle:1;
    vuint32_t NR:1;
    vuint32_t CRC:8;
  } B;
} JTAGM_SR_tag;

typedef union JTAGM_DOR0_union_tag {   /* Data Out Register 0 */
  vuint32_t R;
  struct {
    vuint32_t TMS_HIGH:32;
  } B;
} JTAGM_DOR0_tag;

typedef union JTAGM_DOR1_union_tag {   /* Data Out Register 1 */
  vuint32_t R;
  struct {
    vuint32_t TMS_LOW:28;
    vuint32_t  :4;
  } B;
} JTAGM_DOR1_tag;

typedef union JTAGM_DOR2_union_tag {   /* Data Out Register 2 */
  vuint32_t R;
  struct {
    vuint32_t TDI_HIGH:32;
  } B;
} JTAGM_DOR2_tag;

typedef union JTAGM_DOR3_union_tag {   /* Data Out Register 3 */
  vuint32_t R;
  struct {
    vuint32_t TDI_LOW:28;
    vuint32_t  :3;
    vuint32_t Send:1;
  } B;
} JTAGM_DOR3_tag;

typedef union JTAGM_RxCRC_union_tag {  /* Receive CRC Register */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t CRC:8;
  } B;
} JTAGM_RxCRC_tag;

typedef union JTAGM_DIR0_union_tag {   /* Data Input Register 0 */
  vuint32_t R;
  struct {
    vuint32_t TDO_LOW:32;
  } B;
} JTAGM_DIR0_tag;

typedef union JTAGM_DIR1_union_tag {   /* Data Input Register 1 */
  vuint32_t R;
  struct {
    vuint32_t TDO_HIGH:28;
    vuint32_t  :4;
  } B;
} JTAGM_DIR1_tag;

struct JTAGM_tag {
  JTAGM_MCR_tag MCR;                   /* Module Configuration Register */
  JTAGM_SR_tag SR;                     /* Status Register */
  JTAGM_DOR0_tag DOR0;                 /* Data Out Register 0 */
  JTAGM_DOR1_tag DOR1;                 /* Data Out Register 1 */
  JTAGM_DOR2_tag DOR2;                 /* Data Out Register 2 */
  JTAGM_DOR3_tag DOR3;                 /* Data Out Register 3 */
  JTAGM_RxCRC_tag RxCRC;               /* Receive CRC Register */
  JTAGM_DIR0_tag DIR0;                 /* Data Input Register 0 */
  JTAGM_DIR1_tag DIR1;                 /* Data Input Register 1 */
};

#endif
