#ifndef XBIC_REG_H_
#define XBIC_REG_H_

/* ============================================================================
   =============================== Module: XBIC ===============================
   ============================================================================ */

typedef union XBIC_MCR_union_tag {     /* XBIC Module Control Register */
  vuint32_t R;
  struct {
    vuint32_t SE0:1;
    vuint32_t SE1:1;
    vuint32_t SE2:1;
    vuint32_t SE3:1;
    vuint32_t SE4:1;
    vuint32_t SE5:1;
    vuint32_t SE6:1;
    vuint32_t SE7:1;
    vuint32_t ME0:1;
    vuint32_t ME1:1;
    vuint32_t ME2:1;
    vuint32_t ME3:1;
    vuint32_t ME4:1;
    vuint32_t ME5:1;
    vuint32_t ME6:1;
    vuint32_t ME7:1;
    vuint32_t  :16;
  } B;
} XBIC_MCR_tag;

typedef union XBIC_EIR_union_tag {     /* XBIC Error Injection Register */
  vuint32_t R;
  struct {
    vuint32_t EIE:1;
    vuint32_t TIMEOUT_TIME:15;
    vuint32_t TIMEOUT_EN:1;
    vuint32_t SLV:3;
    vuint32_t MST:4;
    vuint32_t SYN:8;
  } B;
} XBIC_EIR_tag;

typedef union XBIC_ESR_union_tag {     /* XBIC Error Status Register */
  vuint32_t R;
  struct {
    vuint32_t VLD:1;
    vuint32_t DPSE0:1;
    vuint32_t DPSE1:1;
    vuint32_t DPSE2:1;
    vuint32_t DPSE3:1;
    vuint32_t DPSE4:1;
    vuint32_t DPSE5:1;
    vuint32_t DPSE6:1;
    vuint32_t DPSE7:1;
    vuint32_t DPME0:1;
    vuint32_t DPME1:1;
    vuint32_t DPME2:1;
    vuint32_t DPME3:1;
    vuint32_t DPME4:1;
    vuint32_t DPME5:1;
    vuint32_t DPME6:1;
    vuint32_t DPME7:1;
    vuint32_t SLV:3;
    vuint32_t MST:4;
    vuint32_t SYN:8;
  } B;
} XBIC_ESR_tag;

typedef union XBIC_EAR_union_tag {     /* XBIC Error Address Register */
  vuint32_t R;
  struct {
    vuint32_t ADDR:32;
  } B;
} XBIC_EAR_tag;

struct XBIC_tag {
  XBIC_MCR_tag MCR;                    /* XBIC Module Control Register */
  XBIC_EIR_tag EIR;                    /* XBIC Error Injection Register */
  XBIC_ESR_tag ESR;                    /* XBIC Error Status Register */
  XBIC_EAR_tag EAR;                    /* XBIC Error Address Register */
};

#endif
