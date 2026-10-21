/*
 * pwm3012_reg.h
 *
 *  Created on: 2024��6��20��
 *      Author: 69405
 */

#ifndef COMMON_INC_CHIPSET_MODULE_PWM3012_REG_H_
#define COMMON_INC_CHIPSET_MODULE_PWM3012_REG_H_

/* ============================================================================
   =============================== Module: PWM3012 ===============================
   ============================================================================ */

struct PWM3012_tag{

    union { /* Module Configuration (Base+0x0000) */
        vuint32_t R;
        struct {
            vuint32_t DZI1:8;
            vuint32_t DZI0:8;
            vuint32_t CP1:8;
            vuint32_t CP0:8;
        } B;
    } PPR;
    union { /* Module Configuration (Base+0x0004) */
        vuint32_t R;
        struct {
            vuint32_t :17;
            vuint32_t CSR3:3;
            vuint32_t :1;
            vuint32_t CSR2:3;
            vuint32_t :1;
            vuint32_t CSR1:3;
            vuint32_t :1;
            vuint32_t CSR0:3;
        } B;
    } PCSR;
    union { /* Module Configuration (Base+0x0008) */
        vuint32_t R;
        struct {
            vuint32_t :4;
            vuint32_t CH3MOD:1;
            vuint32_t CH3INV:1;
            vuint32_t :1;
            vuint32_t CH3EN:1;
            vuint32_t :4;
            vuint32_t CH2MOD:1;
            vuint32_t CH2INV:1;
            vuint32_t :1;
            vuint32_t CH2EN:1;
            vuint32_t :4;
            vuint32_t CH1MOD:1;
            vuint32_t CH1INV:1;
            vuint32_t :1;
            vuint32_t CH1EN:1;
            vuint32_t :2;
            vuint32_t DZEN1:1;
            vuint32_t DZEN0:1;
            vuint32_t CH0MOD:1;
            vuint32_t CH0INV:1;
            vuint32_t :1;
            vuint32_t CH0EN:1;
        } B;
    } PCR;
    union { /* Module Configuration (Base+0x000C) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t CNR:16;
        } B;
    } PCNR0;
    union { /* Module Configuration (Base+0x0010) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t CMR:16;
        } B;
    } PCMR0;
    union { /* Module Configuration (Base+0x0014) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t PTR:16;
        } B;
    } PTR0;

    union { /* Module Configuration (Base+0x0018) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t CNR:16;
        } B;
    } PCNR1;
    union { /* Module Configuration (Base+0x001C) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t CMR:16;
        } B;
    } PCMR1;
    union { /* Module Configuration (Base+0x0020) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t PTR:16;
        } B;
    } PTR1;

    union { /* Module Configuration (Base+0x0024) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t CNR:16;
        } B;
    } PCNR2;
    union { /* Module Configuration (Base+0x0028) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t CMR:16;
        } B;
    } PCMR2;
    union { /* Module Configuration (Base+0x002C) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t PTR:16;
        } B;
    } PTR2;

    union { /* Module Configuration (Base+0x0030) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t CNR:16;
        } B;
    } PCNR3;
    union { /* Module Configuration (Base+0x0034) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t CMR:16;
        } B;
    } PCMR3;
    union { /* Module Configuration (Base+0x0038) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t PTR:16;
        } B;
    } PTR3;

    union { /* Module Configuration (Base+0x003C) */
        vuint32_t R;
        struct {
            vuint32_t :28;
            vuint32_t PIER3:1;
            vuint32_t PIER2:1;
            vuint32_t PIER1:1;
            vuint32_t PIER0:1;
        } B;
    } PIER;
    union { /* Module Configuration (Base+0x0040) */
        vuint32_t R;
        struct {
            vuint32_t :28;
            vuint32_t PIFR3:1;
            vuint32_t PIFR2:1;
            vuint32_t PIFR1:1;
            vuint32_t PIFR0:1;
        } B;
    } PIFR;
    union { /* Module Configuration (Base+0x0044) */
        vuint32_t R;
        struct {
            vuint32_t :8;
            vuint32_t CFLRD1:1;
            vuint32_t CRLRD1:1;
            vuint32_t :1;
            vuint32_t CAPIF1:1;
            vuint32_t CAPCH1EN:1;
            vuint32_t FL_IE1:1;
            vuint32_t RL_IE1:1;
            vuint32_t INV1:1;
            vuint32_t :8;
            vuint32_t CFLRD0:1;
            vuint32_t CRLRD0:1;
            vuint32_t :1;
            vuint32_t CAPIF0:1;
            vuint32_t CAPCH0EN:1;
            vuint32_t FL_IE0:1;
            vuint32_t RL_IE0:1;
            vuint32_t INV0:1;
        } B;
    } PCCR0;
    union { /* Module Configuration (Base+0x0048) */
        vuint32_t R;
        struct {
            vuint32_t :8;
            vuint32_t CFLRD3:1;
            vuint32_t CRLRD3:1;
            vuint32_t :1;
            vuint32_t CAPIF3:1;
            vuint32_t CAPCH3EN:1;
            vuint32_t FL_IE3:1;
            vuint32_t RL_IE3:1;
            vuint32_t INV3:1;
            vuint32_t :8;
            vuint32_t CFLRD2:1;
            vuint32_t CRLRD2:1;
            vuint32_t :1;
            vuint32_t CAPIF2:1;
            vuint32_t CAPCH2EN:1;
            vuint32_t FL_IE2:1;
            vuint32_t RL_IE2:1;
            vuint32_t INV2:1;
        } B;
    } PCCR1;
    union { /* Module Configuration (Base+0x004C) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t CRLR:16;
        } B;
    } PCRLR0;
    union { /* Module Configuration (Base+0x0050) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t CFLR:16;
        } B;
    } PCFLR0;
    union { /* Module Configuration (Base+0x0054) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t CRLR:16;
        } B;
    } PCRLR1;
    union { /* Module Configuration (Base+0x0058) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t CFLR:16;
        } B;
    } PCFLR1;
    union { /* Module Configuration (Base+0x005C) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t CRLR:16;
        } B;
    } PCRLR2;
    union { /* Module Configuration (Base+0x0060) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t CFLR:16;
        } B;
    } PCFLR2;
    union { /* Module Configuration (Base+0x0064) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t CRLR:16;
        } B;
    } PCRLR3;
    union { /* Module Configuration (Base+0x0068) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t CFLR:16;
        } B;
    } PCFLR3;
    union { /* Module Configuration (Base+0x0004) */
        vuint32_t R;
        struct {
            vuint32_t :12;
            vuint32_t PDDR:4;
            vuint32_t :4;
            vuint32_t PULLUP_EN:4;
            vuint32_t :4;
            vuint32_t PDR:4;
        } B;
    } PPCR;
};

#endif /* COMMON_INC_CHIPSET_MODULE_PWM3012_REG_H_ */
