/****************************************************************************
*
* Copyright (c) 2024  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx SIUL low level drivers code
* HISTORY     : Initial version
* @file     siul_reg.h
* @version  1.0
* @date     2024 - 05 - 11
* @brief    Initial version.
*
*****************************************************************************/

#ifndef SIUL_REG_H_
#define SIUL_REG_H_

/* ============================================================================
   =============================== Module: SIUL ===============================
   ============================================================================ */
struct SIUL_tag {

    vuint8_t SIUL_reserved0[4]; /* Reserved 4 Bytes (Offset:0x0000) */

    union { /* MCU ID Register 1(MIDR1) (Offset:0x0004) */
        vuint32_t R;
        struct {
            vuint32_t PARTNUM:16;
            vuint32_t CSP:1;
            vuint32_t PKG:5;
            vuint32_t :2;
            vuint32_t MAJOR_MASK:4;
            vuint32_t MINOR_MASK:4;
        } B;
    } MIDR1;

    union { /* MCU ID Register 2(MIDR2) (Offset:0x0008) */
        vuint32_t R;
        struct {
            vuint32_t SF:1;
            vuint32_t FLASH_SIZE_1:4;
            vuint32_t FLASH_SIZE_2:4;
            vuint32_t :7;
            vuint32_t PARTNUM:8;
            vuint32_t :3;
            vuint32_t EE:1;
            vuint32_t :4;
        } B;
    } MIDR2;

    vuint8_t SIUL_reserved1[8];     /* Reserved 8 Bytes (Offset:0x000C-0x0013) */

    union { /* Interrupt Status Flag Register(ISR) (Offset:0x0014) */
        vuint32_t R;
        struct {
            vuint32_t :8;
            vuint32_t EIF23:1;
            vuint32_t EIF22:1;
            vuint32_t EIF21:1;
            vuint32_t EIF20:1;
            vuint32_t EIF19:1;
            vuint32_t EIF18:1;
            vuint32_t EIF17:1;
            vuint32_t EIF16:1;
            vuint32_t EIF15:1;
            vuint32_t EIF14:1;
            vuint32_t EIF13:1;
            vuint32_t EIF12:1;
            vuint32_t EIF11:1;
            vuint32_t EIF10:1;
            vuint32_t EIF9:1;
            vuint32_t EIF8:1;
            vuint32_t EIF7:1;
            vuint32_t EIF6:1;
            vuint32_t EIF5:1;
            vuint32_t EIF4:1;
            vuint32_t EIF3:1;
            vuint32_t EIF2:1;
            vuint32_t EIF1:1;
            vuint32_t EIF0:1;
        } B;
    } ISR;

    union { /* Interrupt Request Enable Register(IRER) (Offset:0x0018) */
        vuint32_t R;
        struct {
            vuint32_t :8;
            vuint32_t IRE23:1;
            vuint32_t IRE22:1;
            vuint32_t IRE21:1;
            vuint32_t IRE20:1;
            vuint32_t IRE19:1;
            vuint32_t IRE18:1;
            vuint32_t IRE17:1;
            vuint32_t IRE16:1;
            vuint32_t IRE15:1;
            vuint32_t IRE14:1;
            vuint32_t IRE13:1;
            vuint32_t IRE12:1;
            vuint32_t IRE11:1;
            vuint32_t IRE10:1;
            vuint32_t IRE9:1;
            vuint32_t IRE8:1;
            vuint32_t IRE7:1;
            vuint32_t IRE6:1;
            vuint32_t IRE5:1;
            vuint32_t IRE4:1;
            vuint32_t IRE3:1;
            vuint32_t IRE2:1;
            vuint32_t IRE1:1;
            vuint32_t IRE0:1;
        } B;
    } IRER;

    vuint8_t SIUL_reserved2[12];    /* Reserved 12 Bytes (Offset:0x001C-0x0027) */

    union { /* Interrupt Rising-Edge Event Enable Register(IREER) (Offset:0x0028) */
        vuint32_t R;
        struct {
            vuint32_t :8;
            vuint32_t IREE23:1;
            vuint32_t IREE22:1;
            vuint32_t IREE21:1;
            vuint32_t IREE20:1;
            vuint32_t IREE19:1;
            vuint32_t IREE18:1;
            vuint32_t IREE17:1;
            vuint32_t IREE16:1;
            vuint32_t IREE15:1;
            vuint32_t IREE14:1;
            vuint32_t IREE13:1;
            vuint32_t IREE12:1;
            vuint32_t IREE11:1;
            vuint32_t IREE10:1;
            vuint32_t IREE9:1;
            vuint32_t IREE8:1;
            vuint32_t IREE7:1;
            vuint32_t IREE6:1;
            vuint32_t IREE5:1;
            vuint32_t IREE4:1;
            vuint32_t IREE3:1;
            vuint32_t IREE2:1;
            vuint32_t IREE1:1;
            vuint32_t IREE0:1;
        } B;
    } IREER;

    union { /* Interrupt Falling-Edge Event Enable Register(IFEER) (Offset:0x002C) */
        vuint32_t R;
        struct {
            vuint32_t :8;
            vuint32_t IFEE23:1;
            vuint32_t IFEE22:1;
            vuint32_t IFEE21:1;
            vuint32_t IFEE20:1;
            vuint32_t IFEE19:1;
            vuint32_t IFEE18:1;
            vuint32_t IFEE17:1;
            vuint32_t IFEE16:1;
            vuint32_t IFEE15:1;
            vuint32_t IFEE14:1;
            vuint32_t IFEE13:1;
            vuint32_t IFEE12:1;
            vuint32_t IFEE11:1;
            vuint32_t IFEE10:1;
            vuint32_t IFEE9:1;
            vuint32_t IFEE8:1;
            vuint32_t IFEE7:1;
            vuint32_t IFEE6:1;
            vuint32_t IFEE5:1;
            vuint32_t IFEE4:1;
            vuint32_t IFEE3:1;
            vuint32_t IFEE2:1;
            vuint32_t IFEE1:1;
            vuint32_t IFEE0:1;
        } B;
    } IFEER;

    union { /* Interrupt Filter Enable Register(IFER) (Offset:0x0030) */
        vuint32_t R;
        struct {
            vuint32_t :8;
            vuint32_t IFE23:1;
            vuint32_t IFE22:1;
            vuint32_t IFE21:1;
            vuint32_t IFE20:1;
            vuint32_t IFE19:1;
            vuint32_t IFE18:1;
            vuint32_t IFE17:1;
            vuint32_t IFE16:1;
            vuint32_t IFE15:1;
            vuint32_t IFE14:1;
            vuint32_t IFE13:1;
            vuint32_t IFE12:1;
            vuint32_t IFE11:1;
            vuint32_t IFE10:1;
            vuint32_t IFE9:1;
            vuint32_t IFE8:1;
            vuint32_t IFE7:1;
            vuint32_t IFE6:1;
            vuint32_t IFE5:1;
            vuint32_t IFE4:1;
            vuint32_t IFE3:1;
            vuint32_t IFE2:1;
            vuint32_t IFE1:1;
            vuint32_t IFE0:1;
        } B;
    } IFER;

    vuint8_t SIUL_reserved3[12];    /* Reserved 12 Bytes (Offset:0x0034-0x003F) */

    union { /* Pad Configuration Registers(PCR0-PCR335) (Offset:0x0040-0x02DE)*/
        vuint16_t R;
        struct {
                vuint16_t MS:1;
                vuint16_t SMC:1;
                vuint16_t SMT:1;
                vuint16_t PA:5;
                vuint16_t OBE:1;
                vuint16_t IBE:1;
                vuint16_t ODE:1;
                vuint16_t DS2:1;
                vuint16_t DS1:1;
                vuint16_t DS0:1;
                vuint16_t WPE:1;
                vuint16_t WPS:1;
        } B;
    } PCR[336];

    vuint8_t SIUL_reserved4[544];   /*Reserved 544 Bytes (Offset:0x02E0-0x04FF) */

    /* Pad Selection for Multiplexed Inputs Registers(PSMI0_3-PSMI144_147) (Offset:0x0500-0x0590) */
    union {
        vuint8_t R;
        struct {
            vuint8_t :4;
            vuint8_t PADSEL:4;
        } B;
    } PSMI[148];

    vuint8_t SIUL_reserved5[108];   /*Reserved 116 Bytes (Offset:0x0594-0x05FF) */

    union { /* GPIO Pad Data Output Registers(GPDO0_3-GPDO332_335) (Offset:0x0600-0x074C) */
        vuint8_t R;
        struct {
            vuint8_t :7;
            vuint8_t PDO:1;
        } B;
    } GPDO[336];

    vuint8_t SIUL_reserved6[176];   /*Reserved 176 Bytes (Offset:0x0750-0x07FF) */

    union { /* GPIO Pad Data Input Registers(GPDI0_3-GPDI332_335) (Offset:0x0800-0x094C) */
        vuint8_t R;
        struct {
            vuint8_t :7;
            vuint8_t PDI:1;
        } B;
    } GPDI[336];

    vuint8_t SIUL_reserved7[688];   /*Reserved 688 Bytes (Offset:0x0950-0x0BFF) */

    union { /* Parallel GPIO Pad Data Out Registers(PGPDO0-PGPDO10) (Offset:0x0C00-0x0C28) */
        vuint32_t R;
        struct {
            vuint32_t PPDO:32;
        } B;
    } PGPDO[11];

    vuint8_t SIUL_reserved8[20];    /* Reserved 20 Bytes (Offset:0x0C2C-0x0C3F) */

    union { /* Parallel GPIO Pad Data In Registers(PGPDI0-PGPDI10) (Offset:0x0C40-0x0C68) */
        vuint32_t R;
        struct {
            vuint32_t PPDI:32;
        } B;
    } PGPDI[11];

    vuint8_t SIUL_reserved9[20];    /* Reserved 20 Bytes (Offset:0x0C6C-0x0C7F) */

    union { /* Masked Parallel GPIO Pad Data Out Registers(MPGPDO0-MPGPDO20) (Offset:0x0C80-0x0CD0) */
        vuint32_t R;
        struct {
            vuint32_t MASK:16;
            vuint32_t MPPDO:16;
        } B;
    } MPGPDO[21];

    vuint8_t SIUL_reserved10[812];  /* Reserved 812 Bytes (Offset:0x0CD4-0x0FFF) */

    union { /* Interrupt Filter Max Counter Registers(IFMC0-IFMC23) (Offset:0x1000-0x105C) */
        vuint32_t R;
        struct {
            vuint32_t :28;
            vuint32_t MAXCNT:4;
        } B;
    } IFMC[24];

    vuint8_t SIUL_reserved11[32];   /* Reserved 32 Bytes (Offset:0x1060-0x107F) */

    union { /* Interrupt Filter Clock Prescaler Register(IFCPR) (Offset:0x1080) */
        vuint32_t R;
        struct {
            vuint32_t :28;
            vuint32_t IFCP:4;
        } B;
    } IFCPR;

    union { /* LVDS Config Register(LCR0-LCR21) (Offset:0x1084-0x1099) */
        vuint8_t R;
        struct {
            vuint8_t :3;    /* NOTE: LCR21 bit0 is used to ESR0_ASSERT */
            vuint8_t BG_EN:1;
            vuint8_t DIR_EN:1;
            vuint8_t SRC_LV:2;
            vuint8_t EN_RES:1;
        } B;
    } LCR[22];

    vuint8_t SIUL_reserved12[2];    /* Reserved 2 Bytes (Offset:0x109A-0x109B) */

    /* eQADC/SDADC Trigger Source Input Select Registers(ISEL0-16) (Offset:0x109C-10DC) */
    union { /* eQADC Trigger Source Input Select Register 0(ISEL0) (Offset:0x109C) */
        vuint32_t R;
        struct {
            vuint32_t EQADC01_ETRIG2:8;
            vuint32_t EQADC01_ETRIG1:8;
            vuint32_t EQADC01_ETRIG0:8;
            vuint32_t EQADC01_ATRIG0:8;
        } B;
    } ISEL0;

    union { /* eQADC Trigger Source Input Select Register 1(ISEL1) (Offset:0x10A0) */
        vuint32_t R;
        struct {
            vuint32_t EQADC23_ATRIG0:8;
            vuint32_t EQADC01_ETRIG5:8;
            vuint32_t EQADC01_ETRIG4:8;
            vuint32_t EQADC01_ETRIG3:8;
        } B;
    } ISEL1;

    union { /* eQADC Trigger Source Input Select Register 2(ISEL2) (Offset:0x10A4) */
        vuint32_t R;
        struct {
            vuint32_t EQADC23_ETRIG3:8;
            vuint32_t EQADC23_ETRIG2:8;
            vuint32_t EQADC23_ETRIG1:8;
            vuint32_t EQADC23_ETRIG0:8;
        } B;
    } ISEL2;

    union { /* eQADC Trigger Source Input Select Register 3(ISEL3) (Offset:0x10A8) */
        vuint32_t R;
        struct {
            vuint32_t EQADC45_ETRIG0:8;
            vuint32_t EQADC45_ATRIG0:8;
            vuint32_t EQADC23_ETRIG5:8;
            vuint32_t EQADC23_ETRIG4:8;
        } B;
    } ISEL3;

    union { /* eQADC Trigger Source Input Select Register 4(ISEL4) (Offset:0x10AC) */
        vuint32_t R;
        struct {
            vuint32_t EQADC45_ETRIG4:8;
            vuint32_t EQADC45_ETRIG3:8;
            vuint32_t EQADC45_ETRIG2:8;
            vuint32_t EQADC45_ETRIG1:8;
        } B;
    } ISEL4;

    union { /* eQADC Trigger Source Input Select Register 5(ISEL5) (Offset:0x10B0) */
        vuint32_t R;
        struct {
            vuint32_t EQADC67_ETRIG1:8;
            vuint32_t EQADC67_ETRIG0:8;
            vuint32_t EQADC67_ATRIG0:8;
            vuint32_t EQADC45_ETRIG5:8;
        } B;
    } ISEL5;

    union { /* eQADC Trigger Source Input Select Register 6(ISEL6) (Offset:0x10B4) */
        vuint32_t R;
        struct {
            vuint32_t EQADC67_ETRIG5:8;
            vuint32_t EQADC67_ETRIG4:8;
            vuint32_t EQADC67_ETRIG3:8;
            vuint32_t EQADC67_ETRIG2:8;
        } B;
    } ISEL6;

    union { /* eQADC Trigger Source Input Select Register 7(ISEL7) (Offset:0x10B8) */
        vuint32_t R;
        struct {
            vuint32_t EQADC89_ETRIG2:8;
            vuint32_t EQADC89_ETRIG1:8;
            vuint32_t EQADC89_ETRIG0:8;
            vuint32_t EQADC89_ATRIG0:8;
        } B;
    } ISEL7;

    union { /* eQADC Trigger Source Input Select Register 8(ISEL8) (Offset:0x10BC) */
        vuint32_t R;
        struct {
            vuint32_t EQADC1011_ATRIG0:8;
            vuint32_t EQADC89_ETRIG5:8;
            vuint32_t EQADC89_ETRIG4:8;
            vuint32_t EQADC89_ETRIG3:8;
        } B;
    } ISEL8;

    union { /* eQADC Trigger Source Input Select Register 9(ISEL9) (Offset:0x10C0) */
        vuint32_t R;
        struct {
            vuint32_t EQADC1011_ETRIG3:8;
            vuint32_t EQADC1011_ETRIG2:8;
            vuint32_t EQADC1011_ETRIG1:8;
            vuint32_t EQADC1011_ETRIG0:8;
        } B;
    } ISEL9;

    union { /* eQADC Trigger Source Input Select Register 10(ISEL10) (Offset:0x10C4) */
        vuint32_t R;
        struct {
            vuint32_t EQADC1213_ETRIG0:8;
            vuint32_t EQADC1213_ATRIG0:8;
            vuint32_t EQADC1011_ETRIG5:8;
            vuint32_t EQADC1011_ETRIG4:8;
        } B;
    } ISEL10;

    union { /* eQADC Trigger Source Input Select Register 11(ISEL11) (Offset:0x10C8) */
        vuint32_t R;
        struct {
            vuint32_t EQADC1213_ETRIG4:8;
            vuint32_t EQADC1213_ETRIG3:8;
            vuint32_t EQADC1213_ETRIG2:8;
            vuint32_t EQADC1213_ETRIG1:8;
        } B;
    } ISEL11;

    union { /* eQADC Trigger Source Input Select Register 12(ISEL12) (Offset:0x10CC) */
        vuint32_t R;
        struct {
            vuint32_t :24;
            vuint32_t EQADC1213_ETRIG5:8;
        } B;
    } ISEL12;

    union { /* SDADC Trigger Source Input Select Register 13(ISEL13) (Offset:0x10D0) */
        vuint32_t R;
        struct {
            vuint32_t SDADC3_GTM_TRIG:8;
            vuint32_t SDADC2_GTM_TRIG:8;
            vuint32_t SDADC1_GTM_TRIG:8;
            vuint32_t SDADC0_GTM_TRIG:8;
        } B;
    } ISEL13;

    union { /* SDADC Trigger Source Input Select Register 14(ISEL14) (Offset:0x10D4) */
        vuint32_t R;
        struct {
            vuint32_t SDADC7_GTM_TRIG:8;
            vuint32_t SDADC6_GTM_TRIG:8;
            vuint32_t SDADC5_GTM_TRIG:8;
            vuint32_t SDADC4_GTM_TRIG:8;
        } B;
    } ISEL14;

    union { /* SDADC Trigger Source Input Select Register 15(ISEL15) (Offset:0x10D8) */
        vuint32_t R;
        struct {
            vuint32_t SDADC11_GTM_TRIG:8;
            vuint32_t SDADC10_GTM_TRIG:8;
            vuint32_t SDADC9_GTM_TRIG:8;
            vuint32_t SDADC8_GTM_TRIG:8;
        } B;
    } ISEL15;

    union { /* SDADC Trigger Source Input Select Register 16(ISEL16) (Offset:0x10DC) */
        vuint32_t R;
        struct {
            vuint32_t :16;
            vuint32_t SDADC13_GTM_TRIG:8;
            vuint32_t SDADC12_GTM_TRIG:8;
        } B;
    } ISEL16;

};  /* end of SIUL_tag */

typedef struct SIUL_tag SIUL_TagType;

/* @brief SIUL base address */
#define SIUL_BASEADDR               (0xFFFC0000UL)

/* @brief SIUL base pointer */
#define SIUL_PTR                    ((SIUL_TagType *) SIUL_BASEADDR)

/* @brief SIUL Reg base address offset */
#define SIUL_ISEL0_OFFSET_ADDR      (0x109CU)



/*******************************************************************************
 * SIUL Register Bit Fields
 *******************************************************************************/
/* MIDR1 Bit Fields */
#define SIUL_MIDR1_MINOR_MASK           0xFu
#define SIUL_MIDR1_MINOR_SHIFT          0u
#define SIUL_MIDR1_MINOR_WIDTH          4u
#define SIUL_MIDR1_MINOR(x)             (((uint32_t)(((uint32_t)(x))<<SIUL_MIDR1_MINOR_SHIFT))&SIUL_MIDR1_MINOR_MASK)
#define SIUL_MIDR1_MAJOR_MASK           0xF0u
#define SIUL_MIDR1_MAJOR_SHIFT          4u
#define SIUL_MIDR1_MAJOR_WIDTH          4u
#define SIUL_MIDR1_MAJOR(x)             (((uint32_t)(((uint32_t)(x))<<SIUL_MIDR1_MAJOR_SHIFT))&SIUL_MIDR1_MAJOR_MASK)
#define SIUL_MIDR1_PKG_MASK             0x7C00u
#define SIUL_MIDR1_PKG_SHIFT            10u
#define SIUL_MIDR1_PKG_WIDTH            5u
#define SIUL_MIDR1_PKG(x)               (((uint32_t)(((uint32_t)(x))<<SIUL_MIDR1_PKG_SHIFT))&SIUL_MIDR1_PKG_MASK)
#define SIUL_MIDR1_CSP_MASK             0x8000u
#define SIUL_MIDR1_CSP_SHIFT            15u
#define SIUL_MIDR1_CSP_WIDTH            1u
#define SIUL_MIDR1_CSP(x)               (((uint32_t)(((uint32_t)(x))<<SIUL_MIDR1_CSP_SHIFT))&SIUL_MIDR1_CSP_MASK)
#define SIUL_MIDR1_PARTNUM_MASK         0xFFFF0000u
#define SIUL_MIDR1_PARTNUM_SHIFT        16u
#define SIUL_MIDR1_PARTNUM_WIDTH        16u
#define SIUL_MIDR1_PARTNUM(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_MIDR1_PARTNUM_SHIFT))&SIUL_MIDR1_PARTNUM_MASK)
/* MIDR2 Bit Fields */
#define SIUL_MIDR2_EE_MASK              0x10u
#define SIUL_MIDR2_EE_SHIFT             4u
#define SIUL_MIDR2_EE_WIDTH             1u
#define SIUL_MIDR2_EE(x)                (((uint32_t)(((uint32_t)(x))<<SIUL_MIDR2_EE_SHIFT))&SIUL_MIDR2_EE_MASK)
#define SIUL_MIDR2_PARTNUM_MASK         0xFF00u
#define SIUL_MIDR2_PARTNUM_SHIFT        8u
#define SIUL_MIDR2_PARTNUM_WIDTH        8u
#define SIUL_MIDR2_PARTNUM(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_MIDR2_PARTNUM_SHIFT))&SIUL_MIDR2_PARTNUM_MASK)
#define SIUL_MIDR2_FLASHSIZE2_MASK      0x7800000u
#define SIUL_MIDR2_FLASHSIZE2_SHIFT     23u
#define SIUL_MIDR2_FLASHSIZE2_WIDTH     4u
#define SIUL_MIDR2_FLASHSIZE2(x)        (((uint32_t)(((uint32_t)(x))<<SIUL_MIDR2_FLASHSIZE2_SHIFT))&SIUL_MIDR2_FLASHSIZE2_MASK)
#define SIUL_MIDR2_FLASHSIZE1_MASK      0x78000000u
#define SIUL_MIDR2_FLASHSIZE1_SHIFT     27u
#define SIUL_MIDR2_FLASHSIZE1_WIDTH     4u
#define SIUL_MIDR2_FLASHSIZE1(x)        (((uint32_t)(((uint32_t)(x))<<SIUL_MIDR2_FLASHSIZE1_SHIFT))&SIUL_MIDR2_FLASHSIZE1_MASK)
#define SIUL_MIDR2_SF_MASK              0x80000000u
#define SIUL_MIDR2_SF_SHIFT             31u
#define SIUL_MIDR2_SF_WIDTH             1u
#define SIUL_MIDR2_SF(x)                (((uint32_t)(((uint32_t)(x))<<SIUL_MIDR2_SF_SHIFT))&SIUL_MIDR2_SF_MASK)
/* ISR Bit Fields */
#define SIUL_ISR_EIF_MASK               0xFFFFFFu
#define SIUL_ISR_EIF_SHIFT              0u
#define SIUL_ISR_EIF_WIDTH              24u
#define SIUL_ISR_EIF(x)                 (((uint32_t)(((uint32_t)(x))<<SIUL_ISR_EIF_SHIFT))&SIUL_ISR_EIF_MASK)
/* IRER Bit Fields */
#define SIUL_IRER_IRE_MASK              0xFFFFFFu
#define SIUL_IRER_IRE_SHIFT             0u
#define SIUL_IRER_IRE_WIDTH             24u
#define SIUL_IRER_IRE(x)                (((uint32_t)(((uint32_t)(x))<<SIUL_IRER_IRE_SHIFT))&SIUL_IRER_IRE_MASK)
/* IREER Bit Fields */
#define SIUL_IREER_IREE_MASK            0xFFFFFFu
#define SIUL_IREER_IREE_SHIFT           0u
#define SIUL_IREER_IREE_WIDTH           24u
#define SIUL_IREER_IREE(x)              (((uint32_t)(((uint32_t)(x))<<SIUL_IREER_IREE_SHIFT))&SIUL_IREER_IREE_MASK)
/* IFEER Bit Fields */
#define SIUL_IFEER_IFEE_MASK            0xFFFFFFu
#define SIUL_IFEER_IFEE_SHIFT           0u
#define SIUL_IFEER_IFEE_WIDTH           24u
#define SIUL_IFEER_IFEE(x)              (((uint32_t)(((uint32_t)(x))<<SIUL_IFEER_IFEE_SHIFT))&SIUL_IFEER_IFEE_MASK)
/* IFER Bit Fields */
#define SIUL_IFER_IFE_MASK              0xFFFFFFu
#define SIUL_IFER_IFE_SHIFT             0u
#define SIUL_IFER_IFE_WIDTH             24u
#define SIUL_IFER_IFE(x)                (((uint32_t)(((uint32_t)(x))<<SIUL_IFER_IFE_SHIFT))&SIUL_IFER_IFE_MASK)
/* PCR Bit Fields */
#define SIUL_PCR_WPS_MASK               0x1u
#define SIUL_PCR_WPS_SHIFT              0u
#define SIUL_PCR_WPS_WIDTH              1u
#define SIUL_PCR_WPS(x)                 (((uint16_t)(((uint16_t)(x))<<SIUL_PCR_WPS_SHIFT))&SIUL_PCR_WPS_MASK)
#define SIUL_PCR_WPE_MASK               0x2u
#define SIUL_PCR_WPE_SHIFT              1u
#define SIUL_PCR_WPE_WIDTH              1u
#define SIUL_PCR_WPE(x)                 (((uint16_t)(((uint16_t)(x))<<SIUL_PCR_WPE_SHIFT))&SIUL_PCR_WPE_MASK)
#define SIUL_PCR_DS_MASK                0x1Cu
#define SIUL_PCR_DS_SHIFT               2u
#define SIUL_PCR_DS_WIDTH               3u
#define SIUL_PCR_DS(x)                  (((uint16_t)(((uint16_t)(x))<<SIUL_PCR_DS_SHIFT))&SIUL_PCR_DS_MASK)
#define SIUL_PCR_DS0_MASK               0x4u
#define SIUL_PCR_DS0_SHIFT              2u
#define SIUL_PCR_DS0_WIDTH              1u
#define SIUL_PCR_DS0(x)                 (((uint16_t)(((uint16_t)(x))<<SIUL_PCR_DS0_SHIFT))&SIUL_PCR_DS0_MASK)
#define SIUL_PCR_DS1_MASK               0x8u
#define SIUL_PCR_DS1_SHIFT              3u
#define SIUL_PCR_DS1_WIDTH              1u
#define SIUL_PCR_DS1(x)                 (((uint16_t)(((uint16_t)(x))<<SIUL_PCR_DS1_SHIFT))&SIUL_PCR_DS1_MASK)
#define SIUL_PCR_DS2_MASK               0x10u
#define SIUL_PCR_DS2_SHIFT              4u
#define SIUL_PCR_DS2_WIDTH              1u
#define SIUL_PCR_DS2(x)                 (((uint16_t)(((uint16_t)(x))<<SIUL_PCR_DS2_SHIFT))&SIUL_PCR_DS2_MASK)
#define SIUL_PCR_ODE_MASK               0x20u
#define SIUL_PCR_ODE_SHIFT              5u
#define SIUL_PCR_ODE_WIDTH              1u
#define SIUL_PCR_ODE(x)                 (((uint16_t)(((uint16_t)(x))<<SIUL_PCR_ODE_SHIFT))&SIUL_PCR_ODE_MASK)
#define SIUL_PCR_IBE_MASK               0x40u
#define SIUL_PCR_IBE_SHIFT              6u
#define SIUL_PCR_IBE_WIDTH              1u
#define SIUL_PCR_IBE(x)                 (((uint16_t)(((uint16_t)(x))<<SIUL_PCR_IBE_SHIFT))&SIUL_PCR_IBE_MASK)
#define SIUL_PCR_OBE_MASK               0x80u
#define SIUL_PCR_OBE_SHIFT              7u
#define SIUL_PCR_OBE_WIDTH              1u
#define SIUL_PCR_OBE(x)                 (((uint16_t)(((uint16_t)(x))<<SIUL_PCR_OBE_SHIFT))&SIUL_PCR_OBE_MASK)
#define SIUL_PCR_PA_MASK                0x1F00u
#define SIUL_PCR_PA_SHIFT               8u
#define SIUL_PCR_PA_WIDTH               5u
#define SIUL_PCR_PA(x)                  (((uint16_t)(((uint16_t)(x))<<SIUL_PCR_PA_SHIFT))&SIUL_PCR_PA_MASK)
#define SIUL_PCR_SMT_MASK               0x2000u
#define SIUL_PCR_SMT_SHIFT              13u
#define SIUL_PCR_SMT_WIDTH              1u
#define SIUL_PCR_SMT(x)                 (((uint16_t)(((uint16_t)(x))<<SIUL_PCR_SMT_SHIFT))&SIUL_PCR_SMT_MASK)
#define SIUL_PCR_SMC_MASK               0x4000u
#define SIUL_PCR_SMC_SHIFT              14u
#define SIUL_PCR_SMC_WIDTH              1u
#define SIUL_PCR_SMC(x)                 (((uint16_t)(((uint16_t)(x))<<SIUL_PCR_SMC_SHIFT))&SIUL_PCR_SMC_MASK)
#define SIUL_PCR_MS_MASK                0x8000u
#define SIUL_PCR_MS_SHIFT               15u
#define SIUL_PCR_MS_WIDTH               1u
#define SIUL_PCR_MS(x)                  (((uint16_t)(((uint16_t)(x))<<SIUL_PCR_MS_SHIFT))&SIUL_PCR_MS_MASK)
/* PSMI Bit Fields */
#define SIUL_PSMI_U8_PADSEL_MASK        0xFu
#define SIUL_PSMI_U8_PADSEL_SHIFT       0u
#define SIUL_PSMI_U8_PADSEL_WIDTH       4u
#define SIUL_PSMI_U8_PADSEL(x)          (((uint8_t)(((uint8_t)(x))<<SIUL_PSMI_U8_PADSEL_SHIFT))&SIUL_PSMI_U8_PADSEL_MASK)
#define SIUL_PSMI_U32_PADSEL_0_7_MASK   0xF000000u
#define SIUL_PSMI_U32_PADSEL_0_7_SHIFT  24u
#define SIUL_PSMI_U32_PADSEL_0_7_WIDTH  4u
#define SIUL_PSMI_U32_PADSEL_0_7(x)     (((uint32_t)(((uint32_t)(x))<<SIUL_PSMI_U32_PADSEL_0_7_SHIFT))&SIUL_PSMI_U32_PADSEL_0_7_MASK)
#define SIUL_PSMI_U32_PADSEL_8_15_MASK  0xF0000u
#define SIUL_PSMI_U32_PADSEL_8_15_SHIFT 16u
#define SIUL_PSMI_U32_PADSEL_8_15_WIDTH 4u
#define SIUL_PSMI_U32_PADSEL_8_15(x)    (((uint32_t)(((uint32_t)(x))<<SIUL_PSMI_U32_PADSEL_8_15_SHIFT))&SIUL_PSMI_U32_PADSEL_8_15_MASK)
#define SIUL_PSMI_U32_PADSEL_16_23_MASK 0xF00u
#define SIUL_PSMI_U32_PADSEL_16_23_SHIFT 8u
#define SIUL_PSMI_U32_PADSEL_16_23_WIDTH 4u
#define SIUL_PSMI_U32_PADSEL_16_23(x)   (((uint32_t)(((uint32_t)(x))<<SIUL_PSMI_U32_PADSEL_16_23_SHIFT))&SIUL_PSMI_U32_PADSEL_16_23_MASK)
#define SIUL_PSMI_U32_PADSEL_24_31_MASK 0xFu
#define SIUL_PSMI_U32_PADSEL_24_31_SHIFT 0u
#define SIUL_PSMI_U32_PADSEL_24_31_WIDTH 4u
#define SIUL_PSMI_U32_PADSEL_24_31(x)   (((uint32_t)(((uint32_t)(x))<<SIUL_PSMI_U32_PADSEL_24_31_SHIFT))&SIUL_PSMI_U32_PADSEL_24_31_MASK)
/* GPDO Bit Fields */
#define SIUL_GPDO_U8_PDO_MASK           0x1u
#define SIUL_GPDO_U8_PDO_SHIFT          0u
#define SIUL_GPDO_U8_PDO_WIDTH          1u
#define SIUL_GPDO_U8_PDO(x)             (((uint8_t)(((uint8_t)(x))<<SIUL_GPDO_U8_PDO_SHIFT))&SIUL_GPDO_U8_PDO_MASK)
#define SIUL_GPDO_U32_PDO_0_7_MASK      0x1000000u
#define SIUL_GPDO_U32_PDO_0_7_SHIFT     24u
#define SIUL_GPDO_U32_PDO_0_7_WIDTH     1u
#define SIUL_GPDO_U32_PDO_0_7(x)        (((uint32_t)(((uint32_t)(x))<<SIUL_GPDO_U32_PDO_0_7_SHIFT))&SIUL_GPDO_U32_PDO_0_7_MASK)
#define SIUL_GPDO_U32_PDO_8_15_MASK     0x10000u
#define SIUL_GPDO_U32_PDO_8_15_SHIFT    16u
#define SIUL_GPDO_U32_PDO_8_15_WIDTH    1u
#define SIUL_GPDO_U32_PDO_8_15(x)       (((uint32_t)(((uint32_t)(x))<<SIUL_GPDO_U32_PDO_8_15_SHIFT))&SIUL_GPDO_U32_PDO_8_15_MASK)
#define SIUL_GPDO_U32_PDO_16_23_MASK    0x100u
#define SIUL_GPDO_U32_PDO_16_23_SHIFT   8u
#define SIUL_GPDO_U32_PDO_16_23_WIDTH   1u
#define SIUL_GPDO_U32_PDO_16_23(x)      (((uint32_t)(((uint32_t)(x))<<SIUL_GPDO_U32_PDO_16_23_SHIFT))&SIUL_GPDO_U32_PDO_16_23_MASK)
#define SIUL_GPDO_U32_PDO_24_31_MASK    0x1u
#define SIUL_GPDO_U32_PDO_24_31_SHIFT   0u
#define SIUL_GPDO_U32_PDO_24_31_WIDTH   1u
#define SIUL_GPDO_U32_PDO_24_31(x)      (((uint32_t)(((uint32_t)(x))<<SIUL_GPDO_U32_PDO_24_31_SHIFT))&SIUL_GPDO_U32_PDO_24_31_MASK)
/* GPDI Bit Fields */
#define SIUL_GPDI_U8_PDI_MASK           0x1u
#define SIUL_GPDI_U8_PDI_SHIFT          0u
#define SIUL_GPDI_U8_PDI_WIDTH          1u
#define SIUL_GPDI_U8_PDI(x)             (((uint8_t)(((uint8_t)(x))<<SIUL_GPDI_U8_PDI_SHIFT))&SIUL_GPDI_U8_PDI_MASK)
#define SIUL_GPDI_U32_PDI_0_7_MASK      0x1000000u
#define SIUL_GPDI_U32_PDI_0_7_SHIFT     24u
#define SIUL_GPDI_U32_PDI_0_7_WIDTH     1u
#define SIUL_GPDI_U32_PDI_0_7(x)        (((uint32_t)(((uint32_t)(x))<<SIUL_GPDI_U32_PDI_0_7_SHIFT))&SIUL_GPDI_U32_PDI_0_7_MASK)
#define SIUL_GPDI_U32_PDI_8_15_MASK     0x10000u
#define SIUL_GPDI_U32_PDI_8_15_SHIFT    16u
#define SIUL_GPDI_U32_PDI_8_15_WIDTH    1u
#define SIUL_GPDI_U32_PDI_8_15(x)       (((uint32_t)(((uint32_t)(x))<<SIUL_GPDI_U32_PDI_8_15_SHIFT))&SIUL_GPDI_U32_PDI_8_15_MASK)
#define SIUL_GPDI_U32_PDI_16_23_MASK    0x100u
#define SIUL_GPDI_U32_PDI_16_23_SHIFT   8u
#define SIUL_GPDI_U32_PDI_16_23_WIDTH   1u
#define SIUL_GPDI_U32_PDI_16_23(x)      (((uint32_t)(((uint32_t)(x))<<SIUL_GPDI_U32_PDI_16_23_SHIFT))&SIUL_GPDI_U32_PDI_16_23_MASK)
#define SIUL_GPDI_U32_PDI_24_31_MASK    0x1u
#define SIUL_GPDI_U32_PDI_24_31_SHIFT   0u
#define SIUL_GPDI_U32_PDI_24_31_WIDTH   1u
#define SIUL_GPDI_U32_PDI_24_31(x)      (((uint32_t)(((uint32_t)(x))<<SIUL_GPDI_U32_PDI_24_31_SHIFT))&SIUL_GPDI_U32_PDI_24_31_MASK)
/* PGPDO Bit Fields */
#define SIUL_PGPDO0_PORT_A_MASK         0xFFFF0000u
#define SIUL_PGPDO0_PORT_A_SHIFT        16u
#define SIUL_PGPDO0_PORT_A_WIDTH        16u
#define SIUL_PGPDO0_PORT_A(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDO0_PORT_A_SHIFT))&SIUL_PGPDO0_PORT_A_MASK)
#define SIUL_PGPDO0_PORT_B_MASK         0xFFFFu
#define SIUL_PGPDO0_PORT_B_SHIFT        0u
#define SIUL_PGPDO0_PORT_B_WIDTH        16u
#define SIUL_PGPDO0_PORT_B(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDO0_PORT_B_SHIFT))&SIUL_PGPDO0_PORT_B_MASK)
#define SIUL_PGPDO1_PORT_C_MASK         0xFFFF0000u
#define SIUL_PGPDO1_PORT_C_SHIFT        16u
#define SIUL_PGPDO1_PORT_C_WIDTH        16u
#define SIUL_PGPDO1_PORT_C(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDO1_PORT_C_SHIFT))&SIUL_PGPDO1_PORT_C_MASK)
#define SIUL_PGPDO1_PORT_D_MASK         0xFFFFu
#define SIUL_PGPDO1_PORT_D_SHIFT        0u
#define SIUL_PGPDO1_PORT_D_WIDTH        16u
#define SIUL_PGPDO1_PORT_D(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDO1_PORT_D_SHIFT))&SIUL_PGPDO1_PORT_D_MASK)
#define SIUL_PGPDO2_PORT_E_MASK         0xFFFF0000u
#define SIUL_PGPDO2_PORT_E_SHIFT        16u
#define SIUL_PGPDO2_PORT_E_WIDTH        16u
#define SIUL_PGPDO2_PORT_E(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDO2_PORT_E_SHIFT))&SIUL_PGPDO2_PORT_E_MASK)
#define SIUL_PGPDO2_PORT_F_MASK         0xFFFFu
#define SIUL_PGPDO2_PORT_F_SHIFT        0u
#define SIUL_PGPDO2_PORT_F_WIDTH        16u
#define SIUL_PGPDO2_PORT_F(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDO2_PORT_F_SHIFT))&SIUL_PGPDO2_PORT_F_MASK)
#define SIUL_PGPDO3_PORT_G_MASK         0xFFFF0000u
#define SIUL_PGPDO3_PORT_G_SHIFT        16u
#define SIUL_PGPDO3_PORT_G_WIDTH        16u
#define SIUL_PGPDO3_PORT_G(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDO3_PORT_G_SHIFT))&SIUL_PGPDO3_PORT_G_MASK)
#define SIUL_PGPDO3_PORT_H_MASK         0xFFFFu
#define SIUL_PGPDO3_PORT_H_SHIFT        0u
#define SIUL_PGPDO3_PORT_H_WIDTH        16u
#define SIUL_PGPDO3_PORT_H(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDO3_PORT_H_SHIFT))&SIUL_PGPDO3_PORT_H_MASK)
#define SIUL_PGPDO4_PORT_I_MASK         0xFFFF0000u
#define SIUL_PGPDO4_PORT_I_SHIFT        16u
#define SIUL_PGPDO4_PORT_I_WIDTH        16u
#define SIUL_PGPDO4_PORT_I(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDO4_PORT_I_SHIFT))&SIUL_PGPDO4_PORT_I_MASK)
#define SIUL_PGPDO4_PORT_J_MASK         0xFFFFu
#define SIUL_PGPDO4_PORT_J_SHIFT        0u
#define SIUL_PGPDO4_PORT_J_WIDTH        16u
#define SIUL_PGPDO4_PORT_J(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDO4_PORT_J_SHIFT))&SIUL_PGPDO4_PORT_J_MASK)
#define SIUL_PGPDO5_PORT_K_MASK         0xFFFF0000u
#define SIUL_PGPDO5_PORT_K_SHIFT        16u
#define SIUL_PGPDO5_PORT_K_WIDTH        16u
#define SIUL_PGPDO5_PORT_K(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDO5_PORT_K_SHIFT))&SIUL_PGPDO5_PORT_K_MASK)
#define SIUL_PGPDO5_PORT_L_MASK         0xFFFFu
#define SIUL_PGPDO5_PORT_L_SHIFT        0u
#define SIUL_PGPDO5_PORT_L_WIDTH        16u
#define SIUL_PGPDO5_PORT_L(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDO5_PORT_L_SHIFT))&SIUL_PGPDO5_PORT_L_MASK)
#define SIUL_PGPDO6_PORT_M_MASK         0xFFFF0000u
#define SIUL_PGPDO6_PORT_M_SHIFT        16u
#define SIUL_PGPDO6_PORT_M_WIDTH        16u
#define SIUL_PGPDO6_PORT_M(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDO6_PORT_M_SHIFT))&SIUL_PGPDO6_PORT_M_MASK)
#define SIUL_PGPDO6_PORT_N_MASK         0xFFFFu
#define SIUL_PGPDO6_PORT_N_SHIFT        0u
#define SIUL_PGPDO6_PORT_N_WIDTH        16u
#define SIUL_PGPDO6_PORT_N(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDO6_PORT_N_SHIFT))&SIUL_PGPDO6_PORT_N_MASK)
#define SIUL_PGPDO7_PORT_O_MASK         0xFFFF0000u
#define SIUL_PGPDO7_PORT_O_SHIFT        16u
#define SIUL_PGPDO7_PORT_O_WIDTH        16u
#define SIUL_PGPDO7_PORT_O(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDO7_PORT_O_SHIFT))&SIUL_PGPDO7_PORT_O_MASK)
#define SIUL_PGPDO7_PORT_P_MASK         0xFFFFu
#define SIUL_PGPDO7_PORT_P_SHIFT        0u
#define SIUL_PGPDO7_PORT_P_WIDTH        16u
#define SIUL_PGPDO7_PORT_P(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDO7_PORT_P_SHIFT))&SIUL_PGPDO7_PORT_P_MASK)
#define SIUL_PGPDO8_PORT_Q_MASK         0xFFFF0000u
#define SIUL_PGPDO8_PORT_Q_SHIFT        16u
#define SIUL_PGPDO8_PORT_Q_WIDTH        16u
#define SIUL_PGPDO8_PORT_Q(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDO8_PORT_Q_SHIFT))&SIUL_PGPDO8_PORT_Q_MASK)
#define SIUL_PGPDO8_PORT_R_MASK         0xFFFFu
#define SIUL_PGPDO8_PORT_R_SHIFT        0u
#define SIUL_PGPDO8_PORT_R_WIDTH        16u
#define SIUL_PGPDO8_PORT_R(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDO8_PORT_R_SHIFT))&SIUL_PGPDO8_PORT_R_MASK)
#define SIUL_PGPDO9_PORT_S_MASK         0xFFFF0000u
#define SIUL_PGPDO9_PORT_S_SHIFT        16u
#define SIUL_PGPDO9_PORT_S_WIDTH        16u
#define SIUL_PGPDO9_PORT_S(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDO9_PORT_S_SHIFT))&SIUL_PGPDO9_PORT_S_MASK)
#define SIUL_PGPDO9_PORT_T_MASK         0xFFFFu
#define SIUL_PGPDO9_PORT_T_SHIFT        0u
#define SIUL_PGPDO9_PORT_T_WIDTH        16u
#define SIUL_PGPDO9_PORT_T(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDO9_PORT_T_SHIFT))&SIUL_PGPDO9_PORT_T_MASK)
#define SIUL_PGPDO10_PORT_U_MASK        0xFFFF0000u
#define SIUL_PGPDO10_PORT_U_SHIFT       16u
#define SIUL_PGPDO10_PORT_U_WIDTH       16u
#define SIUL_PGPDO10_PORT_U(x)          (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDO10_PORT_U_SHIFT))&SIUL_PGPDO10_PORT_U_MASK)
/* PGPDI Bit Fields */
#define SIUL_PGPDI0_PORT_A_MASK         0xFFFF0000u
#define SIUL_PGPDI0_PORT_A_SHIFT        16u
#define SIUL_PGPDI0_PORT_A_WIDTH        16u
#define SIUL_PGPDI0_PORT_A(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDI0_PORT_A_SHIFT))&SIUL_PGPDI0_PORT_A_MASK)
#define SIUL_PGPDI0_PORT_B_MASK         0xFFFFu
#define SIUL_PGPDI0_PORT_B_SHIFT        0u
#define SIUL_PGPDI0_PORT_B_WIDTH        16u
#define SIUL_PGPDI0_PORT_B(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDI0_PORT_B_SHIFT))&SIUL_PGPDI0_PORT_B_MASK)
#define SIUL_PGPDI1_PORT_C_MASK         0xFFFF0000u
#define SIUL_PGPDI1_PORT_C_SHIFT        16u
#define SIUL_PGPDI1_PORT_C_WIDTH        16u
#define SIUL_PGPDI1_PORT_C(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDI1_PORT_C_SHIFT))&SIUL_PGPDI1_PORT_C_MASK)
#define SIUL_PGPDI1_PORT_D_MASK         0xFFFFu
#define SIUL_PGPDI1_PORT_D_SHIFT        0u
#define SIUL_PGPDI1_PORT_D_WIDTH        16u
#define SIUL_PGPDI1_PORT_D(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDI1_PORT_D_SHIFT))&SIUL_PGPDI1_PORT_D_MASK)
#define SIUL_PGPDI2_PORT_E_MASK         0xFFFF0000u
#define SIUL_PGPDI2_PORT_E_SHIFT        16u
#define SIUL_PGPDI2_PORT_E_WIDTH        16u
#define SIUL_PGPDI2_PORT_E(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDI2_PORT_E_SHIFT))&SIUL_PGPDI2_PORT_E_MASK)
#define SIUL_PGPDI2_PORT_F_MASK         0xFFFFu
#define SIUL_PGPDI2_PORT_F_SHIFT        0u
#define SIUL_PGPDI2_PORT_F_WIDTH        16u
#define SIUL_PGPDI2_PORT_F(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDI2_PORT_F_SHIFT))&SIUL_PGPDI2_PORT_F_MASK)
#define SIUL_PGPDI3_PORT_G_MASK         0xFFFF0000u
#define SIUL_PGPDI3_PORT_G_SHIFT        16u
#define SIUL_PGPDI3_PORT_G_WIDTH        16u
#define SIUL_PGPDI3_PORT_G(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDI3_PORT_G_SHIFT))&SIUL_PGPDI3_PORT_G_MASK)
#define SIUL_PGPDI3_PORT_H_MASK         0xFFFFu
#define SIUL_PGPDI3_PORT_H_SHIFT        0u
#define SIUL_PGPDI3_PORT_H_WIDTH        16u
#define SIUL_PGPDI3_PORT_H(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDI3_PORT_H_SHIFT))&SIUL_PGPDI3_PORT_H_MASK)
#define SIUL_PGPDI4_PORT_I_MASK         0xFFFF0000u
#define SIUL_PGPDI4_PORT_I_SHIFT        16u
#define SIUL_PGPDI4_PORT_I_WIDTH        16u
#define SIUL_PGPDI4_PORT_I(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDI4_PORT_I_SHIFT))&SIUL_PGPDI4_PORT_I_MASK)
#define SIUL_PGPDI4_PORT_J_MASK         0xFFFFu
#define SIUL_PGPDI4_PORT_J_SHIFT        0u
#define SIUL_PGPDI4_PORT_J_WIDTH        16u
#define SIUL_PGPDI4_PORT_J(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDI4_PORT_J_SHIFT))&SIUL_PGPDI4_PORT_J_MASK)
#define SIUL_PGPDI5_PORT_K_MASK         0xFFFF0000u
#define SIUL_PGPDI5_PORT_K_SHIFT        16u
#define SIUL_PGPDI5_PORT_K_WIDTH        16u
#define SIUL_PGPDI5_PORT_K(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDI5_PORT_K_SHIFT))&SIUL_PGPDI5_PORT_K_MASK)
#define SIUL_PGPDI5_PORT_L_MASK         0xFFFFu
#define SIUL_PGPDI5_PORT_L_SHIFT        0u
#define SIUL_PGPDI5_PORT_L_WIDTH        16u
#define SIUL_PGPDI5_PORT_L(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDI5_PORT_L_SHIFT))&SIUL_PGPDI5_PORT_L_MASK)
#define SIUL_PGPDI6_PORT_M_MASK         0xFFFF0000u
#define SIUL_PGPDI6_PORT_M_SHIFT        16u
#define SIUL_PGPDI6_PORT_M_WIDTH        16u
#define SIUL_PGPDI6_PORT_M(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDI6_PORT_M_SHIFT))&SIUL_PGPDI6_PORT_M_MASK)
#define SIUL_PGPDI6_PORT_N_MASK         0xFFFFu
#define SIUL_PGPDI6_PORT_N_SHIFT        0u
#define SIUL_PGPDI6_PORT_N_WIDTH        16u
#define SIUL_PGPDI6_PORT_N(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDI6_PORT_N_SHIFT))&SIUL_PGPDI6_PORT_N_MASK)
#define SIUL_PGPDI7_PORT_O_MASK         0xFFFF0000u
#define SIUL_PGPDI7_PORT_O_SHIFT        16u
#define SIUL_PGPDI7_PORT_O_WIDTH        16u
#define SIUL_PGPDI7_PORT_O(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDI7_PORT_O_SHIFT))&SIUL_PGPDI7_PORT_O_MASK)
#define SIUL_PGPDI7_PORT_P_MASK         0xFFFFu
#define SIUL_PGPDI7_PORT_P_SHIFT        0u
#define SIUL_PGPDI7_PORT_P_WIDTH        16u
#define SIUL_PGPDI7_PORT_P(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDI7_PORT_P_SHIFT))&SIUL_PGPDI7_PORT_P_MASK)
#define SIUL_PGPDI8_PORT_Q_MASK         0xFFFF0000u
#define SIUL_PGPDI8_PORT_Q_SHIFT        16u
#define SIUL_PGPDI8_PORT_Q_WIDTH        16u
#define SIUL_PGPDI8_PORT_Q(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDI8_PORT_Q_SHIFT))&SIUL_PGPDI8_PORT_Q_MASK)
#define SIUL_PGPDI8_PORT_R_MASK         0xFFFFu
#define SIUL_PGPDI8_PORT_R_SHIFT        0u
#define SIUL_PGPDI8_PORT_R_WIDTH        16u
#define SIUL_PGPDI8_PORT_R(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDI8_PORT_R_SHIFT))&SIUL_PGPDI8_PORT_R_MASK)
#define SIUL_PGPDI9_PORT_S_MASK         0xFFFF0000u
#define SIUL_PGPDI9_PORT_S_SHIFT        16u
#define SIUL_PGPDI9_PORT_S_WIDTH        16u
#define SIUL_PGPDI9_PORT_S(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDI9_PORT_S_SHIFT))&SIUL_PGPDI9_PORT_S_MASK)
#define SIUL_PGPDI9_PORT_T_MASK         0xFFFFu
#define SIUL_PGPDI9_PORT_T_SHIFT        0u
#define SIUL_PGPDI9_PORT_T_WIDTH        16u
#define SIUL_PGPDI9_PORT_T(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDI9_PORT_T_SHIFT))&SIUL_PGPDI9_PORT_T_MASK)
#define SIUL_PGPDI10_PORT_U_MASK        0xFFFF0000u
#define SIUL_PGPDI10_PORT_U_SHIFT       16u
#define SIUL_PGPDI10_PORT_U_WIDTH       16u
#define SIUL_PGPDI10_PORT_U(x)          (((uint32_t)(((uint32_t)(x))<<SIUL_PGPDI10_PORT_U_SHIFT))&SIUL_PGPDI10_PORT_U_MASK)
/* MPGPDO Bit Fields */
#define SIUL_MPGPDO_MPPDO_MASK          0xFFFFu
#define SIUL_MPGPDO_MPPDO_SHIFT         0u
#define SIUL_MPGPDO_MPPDO_WIDTH         16u
#define SIUL_MPGPDO_MPPDO(x)            (((uint32_t)(((uint32_t)(x))<<SIUL_MPGPDO_MPPDO_SHIFT))&SIUL_MPGPDO_MPPDO_MASK)
#define SIUL_MPGPDO_MASK_MASK           0xFFFF0000u
#define SIUL_MPGPDO_MASK_SHIFT          16u
#define SIUL_MPGPDO_MASK_WIDTH          16u
#define SIUL_MPGPDO_MASK(x)             (((uint32_t)(((uint32_t)(x))<<SIUL_MPGPDO_MASK_SHIFT))&SIUL_MPGPDO_MASK_MASK)
/* IFMC Bit Fields */
#define SIUL_IFMC_MAXCNT_MASK           0xFu
#define SIUL_IFMC_MAXCNT_SHIFT          0u
#define SIUL_IFMC_MAXCNT_WIDTH          4u
#define SIUL_IFMC_MAXCNT(x)             (((uint32_t)(((uint32_t)(x))<<SIUL_IFMC_MAXCNT_SHIFT))&SIUL_IFMC_MAXCNT_MASK)
/* IFCPR Bit Fields */
#define SIUL_IFCPR_IFCP_MASK            0xFu
#define SIUL_IFCPR_IFCP_SHIFT           0u
#define SIUL_IFCPR_IFCP_WIDTH           4u
#define SIUL_IFCPR_IFCP(x)              (((uint32_t)(((uint32_t)(x))<<SIUL_IFCPR_IFCP_SHIFT))&SIUL_IFCPR_IFCP_MASK)
/* LCR Bit Fields */
#define SIUL_LCR_EN_RES_MASK            0x1u
#define SIUL_LCR_EN_RES_SHIFT           0u
#define SIUL_LCR_EN_RES_WIDTH           1u
#define SIUL_LCR_EN_RES(x)              (((uint8_t)(((uint8_t)(x))<<SIUL_LCR_EN_RES_SHIFT))&SIUL_LCR_EN_RES_MASK)
#define SIUL_LCR_SRC_LV_MASK            0x6u
#define SIUL_LCR_SRC_LV_SHIFT           1u
#define SIUL_LCR_SRC_LV_WIDTH           2u
#define SIUL_LCR_SRC_LV(x)              (((uint8_t)(((uint8_t)(x))<<SIUL_LCR_SRC_LV_SHIFT))&SIUL_LCR_SRC_LV_MASK)
#define SIUL_LCR_DIR_EN_MASK            0x8u
#define SIUL_LCR_DIR_EN_SHIFT           3u
#define SIUL_LCR_DIR_EN_WIDTH           1u
#define SIUL_LCR_DIR_EN(x)              (((uint8_t)(((uint8_t)(x))<<SIUL_LCR_DIR_EN_SHIFT))&SIUL_LCR_DIR_EN_MASK)
#define SIUL_LCR_BG_EN_MASK             0x10u
#define SIUL_LCR_BG_EN_SHIFT            4u
#define SIUL_LCR_BG_EN_WIDTH            1u
#define SIUL_LCR_BG_EN(x)               (((uint8_t)(((uint8_t)(x))<<SIUL_LCR_BG_EN_SHIFT))&SIUL_LCR_BG_EN_MASK)
/* ISEL Bit Fields */
#define SIUL_ISEL_U32_0_7_MASK          0xFF000000u
#define SIUL_ISEL_U32_0_7_SHIFT         24u
#define SIUL_ISEL_U32_0_7_WIDTH         8u
#define SIUL_ISEL_U32_0_7(x)            (((uint32_t)(((uint32_t)(x))<<SIUL_ISEL_U32_0_7_SHIFT))&SIUL_ISEL_U32_0_7_MASK)
#define SIUL_ISEL_U32_8_15_MASK         0xFF0000u
#define SIUL_ISEL_U32_8_15_SHIFT        16u
#define SIUL_ISEL_U32_8_15_WIDTH        8u
#define SIUL_ISEL_U32_8_15(x)           (((uint32_t)(((uint32_t)(x))<<SIUL_ISEL_U32_8_15_SHIFT))&SIUL_ISEL_U32_8_15_MASK)
#define SIUL_ISEL_U32_16_23_MASK        0xFF00u
#define SIUL_ISEL_U32_16_23_SHIFT       8u
#define SIUL_ISEL_U32_16_23_WIDTH       8u
#define SIUL_ISEL_U32_16_23(x)          (((uint32_t)(((uint32_t)(x))<<SIUL_ISEL_U32_16_23_SHIFT))&SIUL_ISEL_U32_16_23_MASK)
#define SIUL_ISEL_U32_24_31_MASK        0xFFu
#define SIUL_ISEL_U32_24_31_SHIFT       0u
#define SIUL_ISEL_U32_24_31_WIDTH       8u
#define SIUL_ISEL_U32_24_31(x)          (((uint32_t)(((uint32_t)(x))<<SIUL_ISEL_U32_24_31_SHIFT))&SIUL_ISEL_U32_24_31_MASK)


#endif /* SIUL_REG_H_ */
