#ifndef RTC_REG_H_
#define RTC_REG_H_

/* ============================================================================
   =============================== Module: RTCAPI ================================
   ============================================================================ */

typedef union RTCAPI_SUPV_union_tag {
  vuint32_t R;
  struct {
    vuint32_t SUPV:1;
    vuint32_t :31;
  } B;
} RTCAPI_SUPV_tag;

typedef union RTCAPI_CR_union_tag {
  vuint32_t R;
  struct {
    vuint32_t CNTEN:1;
    vuint32_t RTCIE:1;
    vuint32_t FRZEN:1;
    vuint32_t ROVREN:1;
    vuint32_t RTCVAL:12;
    vuint32_t APIEN:1;
    vuint32_t APIIE:1;
    vuint32_t CLKSEL:2;
    vuint32_t DIV512EN:1;
    vuint32_t DIV32EN:1;
    vuint32_t APIVAL:10;
  } B;
} RTCAPI_CR_tag;

typedef union RTCAPI_SR_union_tag {
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t RTCF:1;
    vuint32_t  :15;
    vuint32_t APIF:1;
    vuint32_t  :2;
    vuint32_t ROVRF:1;
    vuint32_t  :10;
  } B;
} RTCAPI_SR_tag;

typedef union RTCAPI_RTCCNT_union_tag {
  vuint32_t R;
  struct {
    vuint32_t RTCCNT:32;
  } B;
} RTCAPI_RTCCNT_tag;

struct RTCAPI_tag {
  RTCAPI_SUPV_tag SUPV;                   /* RTCAPI Supervisor Control Register */
  RTCAPI_CR_tag CR;                       /* RTCAPI Control Register */
  RTCAPI_SR_tag SR;                       /* RTCAPI Status Register */
  RTCAPI_RTCCNT_tag RTCCNT;                     /* RTCAPI Count Register */
};

#endif
