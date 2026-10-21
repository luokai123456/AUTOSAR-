/****************************************************************************
*
* Copyright (c) 2024  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC3012PT
* DESCRIPTION : CCFC3012PT features h file
* HISTORY     : Initial version
* @file     CCFC3012PT_features.h
* @version  1.0
* @date     2024 - 05 - 11
* @brief    Initial version.
*
*****************************************************************************/

#ifndef CCFC3012PT_FEATURES_H_
#define CCFC3012PT_FEATURES_H_
#if defined(CCFC3012PT)

/****************************************************************************/
/****************************************************************************/
/* Chip naming convention
 * For example, CCFC3007PT_T192B6:
 *  CC  : Company prefix
 *  FC  : PowerPC 32bit {HC: PowerPC 64bit, RC: RISC-V, D: DSP, M: ARM/MCore}
 *  3   : C3007 {1: M0, 2: C2003, 3: C3007, 4: M4, 5: HIFI5, 6: CRV4H}
 *  007 : Chip series {007, 008, 009, ...}
 *  PT  : Automotive electronic engine control, domain controller...
 *          {BC: Automotive electronic body control,
 *           BM: New energy BMS,
 *           AR: Radar signal processing, ...}
 *  T   : 3 cores {S:1, D(dual):2, T(triple):3, Q(quad):4, P(penta):5, H(hexa):6}
 *  192 : 12MB CFlash {64: 4MB(64/16), ..., 192: 12MB(192/16), 256: 16MB(256/16)}
 *  B   : BGA {L: LQFP/TQFP/HQFP, B: BGA, Q: QFN}
 *  6   : 516Pin {5: 144Pin, 7: 176Pin, 2: 292Pin, 4: 416Pin, 6: 516Pin, 9: 216Pin, D: 32Pin, 1: 180Pin}
 * */

/* Chip [Package/FlashSize/NumOfCore/ChipType] define,
 * LQFP: 1, TQFP: 2, HQFP: 3, BGA: B */
#define PAC_LQFP80                  0x18u
#define PAC_LQFP100                 0x13u
#define PAC_LQFP144                 0x15u
#define PAC_LQFP176                 0x17u
#define PAC_TQFP144                 0x25u
#define PAC_TQFP144B                0x45u   /* B, the second type of pinMux */
#define PAC_HQFP216                 0x39u
#define PAC_HQFP216B                0x59u   /* B, the second type of pinMux */
#define PAC_BGA180                  0xB1u
#define PAC_BGA180A                 0xC1u   /* The second type of pinMux */
#define PAC_BGA292                  0xB2u
#define PAC_BGA416                  0xB4u
#define PAC_BGA516                  0xB6u
#define PAC_BGA516P                 0xC6u   /* P, C3007: 300MHz -> 400MHz */
#define PAC_BGA680                  0xBAu
#define CHIP_PAC_MASK               0xFFu
#define CHIP_PAC_SHIFT              0u
#define CHIP_FLS_SIZE_MASK          0xFF00u /* FlashSize = CHIP_FLS_SIZE * 0.5MB */
#define CHIP_FLS_SIZE_SHIFT         8u
#define CHIP_NUM_CORE_MASK          0xF0000u
#define CHIP_NUM_CORE_SHIFT         16u
#define CHIP_TYPE_MASK              0xFFF00000UL
#define CHIP_TYPE_SHIFT             20u
/* All Chip [NumOfCore] Max */
#define ALL_CHIP_NUM_CORE_MAX       6u

/* CCFC3012PT package define */
#define CCFC3012PT_H264B2_BGA292    (0x3C0621B2UL)  /* 3C0: 3012PT, 6: 6cores, 0x21: 16.5MB, B2: BGA292  */
#define CCFC3012PT_H264B6_BGA516    (0x3C0621B6UL)  /* 3C0: 3012PT, 6: 6cores, 0x21: 16.5MB, B6: BGA516  */
#define CCFC3012PT_H264B6P_BGA516P  (0x3C0621C6UL)  /* 3C0: 3012PT, 6: 6cores, 0x21: 16.5MB, C6: BGA516P */

/* Chip model package selection */
#define CCFC_CHIP_MODEL_PACKAGE     CCFC3012PT_H264B6_BGA516

#if ((CCFC_CHIP_MODEL_PACKAGE & CHIP_TYPE_MASK) != CHIP_TYPE)
    #error "No valid CPU Type defined!"
#endif
/****************************************************************************/
/****************************************************************************/


/*===================Device resource definition start=======================*/

/*----------------------------------Cores-----------------------------------*/
#define RESOURCE_CHIP_CORE_NUM      (6u)    /* Number of chip cores. */
#define RESOURCE_SUPPORT_CORE_0     (0u)    /* Supported. Core_0 */
#define RESOURCE_SUPPORT_CORE_1     (1u)    /* Supported. Core_1 */
#define RESOURCE_SUPPORT_CORE_2     (2u)    /* Supported. Core_2 */
#define RESOURCE_SUPPORT_CORE_3     (3u)    /* Supported. Core_3 */
#define RESOURCE_SUPPORT_CORE_4     (4u)    /* Supported. Core_4 */
#define RESOURCE_SUPPORT_CORE_5     (5u)    /* Supported. Core_5 */
#define RESOURCE_SUPPORT_CHK_CORE_0 (0u)    /* Supported. Checker Core_0 */
#define RESOURCE_SUPPORT_CHK_CORE_1 (1u)    /* Supported. Checker Core_1 */
#define RESOURCE_SUPPORT_CHK_CORE_2 (2u)    /* Supported. Checker Core_2 */
#define RESOURCE_SUPPORT_CHK_CORE_3 (3u)    /* Supported. Checker Core_3 */

/*----------------------------------MCU-------------------------------------*/
/* Note: PLLDIG(Dual PLL Digital Interface),
 * CMU(Clock Monitor Unit),
 * MC_CGM(Clock Generation Module),
 * MC_ME(Mode Entry Module),
 * MC_RGM(Reset Generation Module)... */
#define RESOURCE_SUPPORT_MCU_MODE_STANDBY   /* Supported. MC_ME, Chip mode: standby mode. */
#define RESOURCE_SUPPORT_MCU_FIRC_DIV       /* Supported. IRCOSC, FIRC function: control on/off(StandbyMode), clock division */
#define RESOURCE_SUPPORT_MCU_AC11           /* Supported. */
#define RESOURCE_SUPPORT_MCU_AC12           /* Supported. */
#define RESOURCE_SUPPORT_MCU_AC0_DC1_FMT    /* Supported. */
#define RESOURCE_SUPPORT_MCU_AC0_DC2_FMT    /* Supported. */
#define RESOURCE_SUPPORT_MCU_AC2_DC2        /* Supported. */

#define RESOURCE_SUPPORT_MCU_I2S            /* Supported. */
#define RESOURCE_SUPPORT_MCU_SSI            /* Supported. */

#define RESOURCE_SUPPORT_MCU_FLASH_VARIABLE_SIZE    /* Supported. */

#define RESOURCE_SUPPORT_MCU_CCTL0       /* Supported. */
#define RESOURCE_SUPPORT_MCU_CCTL1       /* Supported. */
#define RESOURCE_SUPPORT_MCU_CCTL2       /* Supported. */
#define RESOURCE_SUPPORT_MCU_CCTL3       /* Supported. */
#define RESOURCE_SUPPORT_MCU_CCTL4       /* Supported. */
#define RESOURCE_SUPPORT_MCU_CCTL6       /* Supported. */
#define RESOURCE_SUPPORT_MCU_CCTL7       /* Supported. */
#define RESOURCE_SUPPORT_MCU_CCTL8       /* Supported. */
#define RESOURCE_SUPPORT_MCU_CCTL9       /* Supported. */
#define RESOURCE_SUPPORT_MCU_CCTL10      /* Supported. */
#define RESOURCE_SUPPORT_MCU_CCTL11      /* Supported. */

#define RESOURCE_SUPPORT_XBAR_0
#define RESOURCE_SUPPORT_XBAR_1
#define RESOURCE_SUPPORT_XBAR_2
#define RESOURCE_SUPPORT_XBAR_3
#define RESOURCE_SUPPORT_XBAR_0_PORT_NUM    (8U)
#define RESOURCE_SUPPORT_XBAR_1_PORT_NUM    (8U)
#define RESOURCE_SUPPORT_XBAR_2_PORT_NUM    (8U)
#define RESOURCE_SUPPORT_XBAR_3_PORT_NUM    (8U)

/*----------------------------------SMPU------------------------------------*/
#define RESOURCE_SUPPORT_SMPU_INSTANCE_COUNT    (4U)    /* Supported.   SMPU instance 0/1/2/3.                          */
#define RESOURCE_SUPPORT_SMPU_MASTER_NUM_COUNT  (16U)   /* Supported.   SMPU logical bus master number: count           */
/* SMPU logical bus master number */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_0  (0U)    /* Supported.   SMPU logical bus master number 0:  Core_0       */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_1  (1U)    /* Supported.   SMPU logical bus master number 1:  Core_1       */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_2  (2U)    /* Supported.   SMPU logical bus master number 2:  Core_2       */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_3  (3U)    /* Supported.   SMPU logical bus master number 3:  DMA_0        */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_4  (4U)    /* Supported.   SMPU logical bus master number 4:  Core_5 Debug */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_5  (5U)    /* Supported.   SMPU logical bus master number 5:  GTM/GMAC     */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_6  (6U)    /* Supported.   SMPU logical bus master number 6:  Core_3       */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_7  (7U)    /* Supported.   SMPU logical bus master number 7:  Core_4       */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_8  (8U)    /* Supported.   SMPU logical bus master number 8:  Core_0 Debug */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_9  (9U)    /* Supported.   SMPU logical bus master number 9:  Core_1 Debug */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_10 (10U)   /* Supported.   SMPU logical bus master number 10: Core_2 Debug */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_11 (11U)   /* Supported.   SMPU logical bus master number 11: Core_3 Debug */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_12 (12U)   /* Supported.   SMPU logical bus master number 12: Core_4 Debug */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_13 (13U)   /* Supported.   SMPU logical bus master number 13: Core_5       */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_14 (14U)   /* Supported.   SMPU logical bus master number 14: HSM          */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_15 (15U)   /* Supported.   SMPU logical bus master number 15: FlexRay_0/FlexRay_1/SD/eMMC/DMA_1 */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_MAX (15U)  /* SMPU logical bus master number: Max                          */

/*----------------------------------PMC_dig: Power Management Controller----*/
#define RESOURCE_SUPPORT_PMC_PAD_RETENTION  /* Supported. Pad Retention function. */

/*----------------------------------INTC: Interrupt Controller--------------*/
#define RESOURCE_SUPPORT_INTC_0             /* Supported. Interrupt Controller 0. */
#define RESOURCE_SUPPORT_INTC_1             /* Supported. Interrupt Controller 1. */

/*----------------------------------FLASH-----------------------------------*/
#define RESOURCE_SUPPORT_PFI
#ifdef RESOURCE_SUPPORT_PFI
#define RESOURCE_SUPPORT_PFI0
#define RESOURCE_SUPPORT_PFI1
#define RESOURCE_SUPPORT_PFI2
#define RESOURCE_SUPPORT_PFI3
#define RESOURCE_SUPPORT_PFI4
#define RESOURCE_SUPPORT_PFI5
#endif  /* RESOURCE_SUPPORT_PFI */

/*----------------------------------RAM-------------------------------------*/

/*----------------------------------SIULx: System Integration Unit LiteX----*/
/* Note: The Unit provides control over all the I/O ports on this device. */
#define RESOURCE_SUPPORT_SIUL_IP            /* Supported. IP: SIUL */
/* RESOURCE_SUPPORT_SIUL2_IP */             /* Unsupported. IP: SIUL2 */

/*----------------------------------EIOMUX: Enhanced IO Multiplexer---------*/
/* RESOURCE_SUPPORT_EIOMUX */               /* Unsupported. IP: EIOMUX */
/* RESOURCE_SUPPORT_EIOMUX2 */              /* Unsupported. IP: EIOMUX2 */

/*----------------------------------EMDA/DMAMUX-----------------------------*/
/* RESOURCE_SUPPORT_TRANS_8_32BYTES */      /* Unsupported. transport 8/32bytes unsupport transport 16bytes */
#define RESOURCE_SUPPORT_DMAMUX10           /* Supported. DMAMUX_10 */

/*----------------------------------WKPU: WakeUp Unit-----------------------*/
#define RESOURCE_SUPPORT_WKPU_NMI           /* Supported. Non-maskable interrupts. */
#define RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC /* Supported. Other multiple wake sources. */
#define RESOURCE_SUPPORT_WKPU_MUX_COMBI     /* Supported. Multiplex combination. */
#ifdef RESOURCE_SUPPORT_WKPU_NMI
#define NMI_IO_MUX_REG_WKPU_NCR             (1U)    /* NMI pin multiplexing control in the WKPU module. */
#define NMI_IO_MUX_REG_SIUL2_SCR0           (2U)    /* NMI pin multiplexing control in the SIUL2 module. */
/* RESOURCE_SUPPORT_WKPU_NMI_IO_MUX */              /* Unsupported. NMI pins(ESR1) support multiplexing. */
#endif  /* RESOURCE_SUPPORT_WKPU_NMI */
#ifdef RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC
#define RESOURCE_SUPPORT_WKPU_WISR0_0_7     /* Supported. Wake up source WISR0 0-7. */
#define RESOURCE_SUPPORT_WKPU_WISR0_8_15    /* Supported. Wake up source WISR0 8-15. */
#define RESOURCE_SUPPORT_WKPU_WISR0_16_23   /* Supported. Wake up source WISR0 16-23. */
#define RESOURCE_SUPPORT_WKPU_WISR0_24_31   /* Supported. Wake up source WISR0 24-31. */
#define RESOURCE_SUPPORT_WKPU_WISR1_0_7     /* Supported. Wake up source WISR1 0-7. */
#define RESOURCE_SUPPORT_WKPU_WISR1_8_15    /* Supported. Wake up source WISR1 8-15. */
#define RESOURCE_SUPPORT_WKPU_WISR1_16_23   /* Supported. Wake up source WISR1 16-23. */
#define RESOURCE_SUPPORT_WKPU_WISR1_24_31   /* Supported. Wake up source WISR1 24-31. */
#endif  /* RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC */

/*----------------------------------eQADC: Enhanced Queued ADC(SARADC)------*/
/*
 * Classification: EQADC Instance Resources (EQADC Function Definition Macro) */
#define RESOURCE_SUPPORT_EQADC_INST0                /* Supported. EQADC Instance 0(EqadcHwUnit0/EqadcHwUnit1)       */
#define RESOURCE_SUPPORT_EQADC_INST1                /* Supported. EQADC Instance 1(EqadcHwUnit2/EqadcHwUnit3)       */
#define RESOURCE_SUPPORT_EQADC_INST2                /* Supported. EQADC Instance 2(EqadcHwUnit4/EqadcHwUnit5)       */
#define RESOURCE_SUPPORT_EQADC_INST3                /* Supported. EQADC Instance 3(EqadcHwUnit6/EqadcHwUnit7)       */
#define RESOURCE_SUPPORT_EQADC_INST4                /* Supported. EQADC Instance 4(EqadcHwUnit8/EqadcHwUnit9)       */
#define RESOURCE_SUPPORT_EQADC_INST5                /* Supported. EQADC Instance 5(EqadcHwUnit10/EqadcHwUnit11)     */
#define RESOURCE_SUPPORT_EQADC_INST6                /* Supported. EQADC Instance 6(EqadcHwUnit12)                   */
/*
 * Classification: EQADC Instance Function (EQADC Function Definition Macro) */
/* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */ /* Unsupported. Red Line Client Configuration                   */
/* RESOURCE_SUPPORT_EQADC_SIUL2_TRIG_SRC_LIMIT */   /* Unsupported. eQADC CFIFO Trigger Source Limitation           */
#define RESOURCE_SUPPORT_EQADC_VREF_SW_CTRL_1       (1U)    /* The enable bit of SDADC needs to be turned on,
                                                             * SSCM module offsets the 0x38 register, bit2/3        */
#define RESOURCE_SUPPORT_EQADC_VREF_SW_CTRL_2       (2U)    /* SSCM module offsets the 0x38 register, bit2/3/4      */
#define RESOURCE_SUPPORT_EQADC_VREF_SW_CTRL_3       (3U)    /* SSCM module offsets the 0x38 register, bit2/3        */
#define RESOURCE_SUPPORT_EQADC_VREF_SW              RESOURCE_SUPPORT_EQADC_VREF_SW_CTRL_2
#define RESOURCE_SUPPORT_EQADC_TRIG_DELAY           /* Supported. Function: EQADC CFIFO delay trigger               */
#define RESOURCE_SUPPORT_EQADC_FIFO_CNT_6           (6U)    /* CFIFO_0 - CFIFO_5, RFIFO_0 - RFIFO_5                 */
#define RESOURCE_SUPPORT_EQADC_FIFO_CNT_8           (8U)    /* CFIFO_0 - CFIFO_7, RFIFO_0 - RFIFO_7                 */
#define RESOURCE_SUPPORT_EQADC_FIFO_CNT             RESOURCE_SUPPORT_EQADC_FIFO_CNT_6
#define RESOURCE_SUPPORT_EQADC_RFIFO_ENTRY_CNT_4    (4U)    /* The entry of RFIFOx: 4                               */
#define RESOURCE_SUPPORT_EQADC_RFIFO_ENTRY_CNT_8    (8U)    /* The entry of RFIFOx: 8                               */
#define RESOURCE_SUPPORT_EQADC_RFIFO_ENTRY_CNT      RESOURCE_SUPPORT_EQADC_RFIFO_ENTRY_CNT_4
#if (defined(RESOURCE_SUPPORT_EQADC_FIFO_CNT) && (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8))
/* RESOURCE_SUPPORT_EQADC_CFIFO_INJECTION */        /* Unsupported. Injection of CFIFOx                             */
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */
/* RESOURCE_SUPPORT_EQADC_RFIFO_CLK_SWITCH */       /* Unsupported. Clock Switch Enable for RFIFOx                  */
/* RESOURCE_SUPPORT_EQADC_RFIFO_SOFT_RESET */       /* Unsupported. RFIFO Software Reset                            */
/* RESOURCE_SUPPORT_EQADC_FIFO_DMA_CTRL_SEL */      /* Unsupported. CFIFOx/RFIFOx DMA ControllerSelect: DMA_0/DMA_1 */
/* RESOURCE_SUPPORT_EQADC_WAKEUP */                 /* Unsupported. eQADC Wakeup function from low power mode       */
/*
 * Classification: EQADC On-Chip ADC Configuration (EQADC Function Definition Macro) */
/* RESOURCE_SUPPORT_EQADC_CFG_OPEN_2_EMUX */        /* Unsupported. Both EMUX switches are turned on simultaneously */
/* RESOURCE_SUPPORT_EQADC_CFG_ALL_ADC_2MSPS */      /* Unsupported. All ADC support a rate of 2MSPS                 */
/* RESOURCE_SUPPORT_EQADC_CFG_ADC0_2MSPS */         /* Unsupported. Only ADC0 supports a rate of 2MSPS              */
/* RESOURCE_SUPPORT_EQADC_CFG_PRECHARGE */          /* Unsupported. Precharge clock cycles selection.               */
/* RESOURCE_SUPPORT_EQADC_CFG_MONITOR */            /* Unsupported. ADC channel sampling and conversion monitoring  */
/* RESOURCE_SUPPORT_EQADC_CFG_AUTO_SHIFT */         /* Unsupported. Data auto >> 2bits. Default on                  */
/*
 * Classification: EQADC ADC Command (EQADC Function Definition Macro) */
/* RESOURCE_SUPPORT_EQADC_CMD_OSR */                /* Unsupported. OverSample rate selection                       */
#define RESOURCE_SUPPORT_EQADC_CMD_LST_2BIT         (0U)    /* Long Sampling Time: 2/8/64/128 Cycles                */
#define RESOURCE_SUPPORT_EQADC_CMD_LST_3BIT         (1U)    /* Long Sampling Time: 2/4/6/8/16/32/64/128 Cycles      */
#define RESOURCE_SUPPORT_EQADC_CMD_LST              RESOURCE_SUPPORT_EQADC_CMD_LST_2BIT

/*----------------------------------SDADC: Sigma Delta ADC------------------*/
#define RESOURCE_SUPPORT_SDADC_IP           /* Supported. IP: SDADC */
#ifdef RESOURCE_SUPPORT_SDADC_IP
#define RESOURCE_SUPPORT_SDADC0             /* Supported. SDADC Instance 0  */
#define RESOURCE_SUPPORT_SDADC1             /* Supported. SDADC Instance 1  */
#define RESOURCE_SUPPORT_SDADC2             /* Supported. SDADC Instance 2  */
#define RESOURCE_SUPPORT_SDADC3             /* Supported. SDADC Instance 3  */
#define RESOURCE_SUPPORT_SDADC4             /* Supported. SDADC Instance 4  */
#define RESOURCE_SUPPORT_SDADC5             /* Supported. SDADC Instance 5  */
#define RESOURCE_SUPPORT_SDADC6             /* Supported. SDADC Instance 6  */
#define RESOURCE_SUPPORT_SDADC7             /* Supported. SDADC Instance 7  */
#define RESOURCE_SUPPORT_SDADC8             /* Supported. SDADC Instance 8  */
#define RESOURCE_SUPPORT_SDADC9             /* Supported. SDADC Instance 9  */
#define RESOURCE_SUPPORT_SDADC10            /* Supported. SDADC Instance 10 */
#define RESOURCE_SUPPORT_SDADC11            /* Supported. SDADC Instance 11 */
#define RESOURCE_SUPPORT_SDADC12            /* Supported. SDADC Instance 12 */
#define RESOURCE_SUPPORT_SDADC13            /* Supported. SDADC Instance 13 */
#endif

/*----------------------------------ACMP: Analog Comparator-----------------*/
#define RESOURCE_SUPPORT_ACMP               /* Supported. IP: ACMP */
#ifdef RESOURCE_SUPPORT_ACMP
#define RESOURCE_SUPPORT_ACMP0
#define RESOURCE_SUPPORT_ACMP1
#define RESOURCE_SUPPORT_ACMP2
#define RESOURCE_SUPPORT_ACMP3
#define RESOURCE_SUPPORT_ACMP4
#define RESOURCE_SUPPORT_ACMP5
#define RESOURCE_SUPPORT_ACMP6
#define RESOURCE_SUPPORT_ACMP7
#endif

/*----------------------------------FCCU-------------------------------------*/
#define RESOURCE_SUPPORT_FCCU_FREQ
#define RESOURCE_SUPPORT_FCCU_NMISEL

/*----------------------------------DAC: Digital-to-analog converter--------*/
#define RESOURCE_SUPPORT_DAC                /* Supported. IP: DAC */

/*----------------------------------STM: System Timer Module----------------*/
#define RESOURCE_STM_INSTANCE_NUM           (6U)
#define RESOURCE_SUPPORT_STM0               /* Supported. STM 0 */
#define RESOURCE_SUPPORT_STM1               /* Supported. STM 1 */
#define RESOURCE_SUPPORT_STM2               /* Supported. STM 2 */
#define RESOURCE_SUPPORT_STM3               /* Supported. STM 3 */
#define RESOURCE_SUPPORT_STM4               /* Supported. STM 4 */
#define RESOURCE_SUPPORT_STM5               /* Supported. STM 5 */

/*----------------------------------PIT: Periodic Interrupt Timer-----------*/
/* RESOURCE_SUPPORT_CLKSRC_AC0DC0 */        /* Unsupported. Clock Source AC0DC0    */
#define RESOURCE_SUPPORT_CLKSRC_AC0DC4      /* Supported. Clock Source AC0DC4    */
#define RESOURCE_SUPPORT_PIT0               /* Supported. PIT 0 */
#define RESOURCE_SUPPORT_PIT1               /* Supported. PIT 1 */
#define RESOURCE_SUPPORT_PIT_TRIG_DMA       /* Supported. Function: PIT trigger DMA */

/*----------------------------------RTC/API: -------------------------------
 *----------------------Real Time Clock/Autonomous Periodic Interrupt-------*/
#define RESOURCE_SUPPORT_RTC_API            /* Supported. IP: RTC/API */

/*----------------------------------SWT: Software Watchdog Timer------------*/
#define RESOURCE_SUPPORT_SWT0               /* Supported. SWT 0 */
#define RESOURCE_SUPPORT_SWT1               /* Supported. SWT 1 */
#define RESOURCE_SUPPORT_SWT2               /* Supported. SWT 2 */
#define RESOURCE_SUPPORT_SWT3               /* Supported. SWT 3 */
#define RESOURCE_SUPPORT_SWT4               /* Supported. SWT 4 */
#define RESOURCE_SUPPORT_SWT5               /* Supported. SWT 5 */
#define RESOURCE_SUPPORT_SWT6               /* Supported. SWT 6 */
#define RESOURCE_SUPPORT_SWT7_AO            /* Supported. SWT 7_AO */
#define RESOURCE_SUPPORT_WDG_ADDRMODE       /* Supported. Address feed the dog */
#ifdef RESOURCE_SUPPORT_SWT7_AO
#define RESOURCE_SUPPORT_SWT_AO_CTRL_0       0U /* SWT7 Enable Method 0  */
#define RESOURCE_SUPPORT_SWT_AO_CTRL_1       1U /* SWT7 Enable Method 1 */
#define RESOURCE_SUPPORT_SWT_AO_CTRL         RESOURCE_SUPPORT_SWT_AO_CTRL_1
#endif

/*----------------------------------eMIOS: Enhanced Modular IO Subsystem----*/
#define RESOURCE_SUPPORT_EMIOS0             /* Supported. eMIOS_0    */
/* RESOURCE_SUPPORT_EMIOS1 */               /* Unsupported. eMIOS_1  */
#define RESOURCE_SUPPORT_EMIOS0_CH0_7       /* Supported. eMIOS_0 Channel_0~7.     */
#define RESOURCE_SUPPORT_EMIOS0_CH8_15      /* Supported. eMIOS_0 Channel_8~15.    */
#define RESOURCE_SUPPORT_EMIOS0_CH16_23     /* Supported. eMIOS_0 Channel_16~23.   */
#define RESOURCE_SUPPORT_EMIOS0_CH24_31     /* Supported. eMIOS_0 Channel_24~31.   */
/* RESOURCE_SUPPORT_EMIOS1_CH0_7 */         /* Unsupported. eMIOS_1 Channel_0~7.   */
/* RESOURCE_SUPPORT_EMIOS1_CH8_15 */        /* Unsupported. eMIOS_1 Channel_8~15.  */
/* RESOURCE_SUPPORT_EMIOS1_CH16_23 */       /* Unsupported. eMIOS_1 Channel_16~23. */
/* RESOURCE_SUPPORT_EMIOS1_CH24_31 */       /* Unsupported. eMIOS_1 Channel_24~31. */
#define RESOURCE_SUPPORT_EMIOS_OPWMT        /* Supported. eMIOS Mode: OPWMT.       */
#define RESOURCE_SUPPORT_EMIOS_CH_CONTINUE  /* Supported. eMIOS channel continue */

/*----------------------------------eTPU: Enhanced Time Processing Unit-----*/
/* RESOURCE_SUPPORT_ETPU */                 /* Unsupported. IP: eTPU */

/*----------------------------------GTM: Generic Timer Module---------------*/
/* RESOURCE_SUPPORT_GTM104 */               /* Unsupported. IP: GTM1.04, about 18 submodules. */
#define RESOURCE_SUPPORT_GTM410             /* Supported. IP: GTM4.10, about 26 submodules. */
#ifdef RESOURCE_SUPPORT_GTM410
/* RESOURCE_SUPPORT_GTM410_2CLS */          /* Unsupported. GTM4.10, instance number */
/* RESOURCE_SUPPORT_GTM410_8CLS */          /* Unsupported. GTM4.10, instance number */
#define RESOURCE_SUPPORT_GTM410_CLS_NUM   (8u)
#define RESOURCE_SUPPORT_GTM410_TOUT        /* Supported. GTM4.10, tout */
#define RESOURCE_SUPPORT_GTM_TRIG_EQADC     /* Supported. GTM Trigger EQADC */
#define RESOURCE_SUPPORT_GTM_TRIG_SDADC     /* Supported. GTM Trigger SDADC */
#define RESOURCE_SUPPORT_GTM_TO_EQADC       /* Supported. GTM to EQADC Connections(Optional) */
#define RESOURCE_SUPPORT_GTM_HRESPWM        /* Supported. GTM High Resolution PWM */
#define RESOURCE_SUPPORT_GTM_TIMINPUTSEL    /* Supported. GTM input select */

#define RESOURCE_SUPPORT_GTM_ATOM_NUM     (8u)    /* Supported. GTM4.10, ATOM number */
#define RESOURCE_SUPPORT_GTM_TOM_NUM      (6u)    /* Supported. GTM4.10, TOM number */

#define RESOURCE_SUPPORT_GTM410_CLS0        /* Supported. GTM4.10, CLS0 */
#define RESOURCE_SUPPORT_GTM410_CLS1        /* Supported. GTM4.10, CLS1 */
#define RESOURCE_SUPPORT_GTM410_CLS2        /* Supported. GTM4.10, CLS2 */
#define RESOURCE_SUPPORT_GTM410_CLS3        /* Supported. GTM4.10, CLS3 */
#define RESOURCE_SUPPORT_GTM410_CLS4        /* Supported. GTM4.10, CLS4 */
#define RESOURCE_SUPPORT_GTM410_CLS5        /* Supported. GTM4.10, CLS5 */
#define RESOURCE_SUPPORT_GTM410_CLS6        /* Supported. GTM4.10, CLS6 */
#define RESOURCE_SUPPORT_GTM410_CLS7        /* Supported. GTM4.10, CLS7 */
#endif

#define RESOURCE_SUPPORT_GTM_TIM0               /* Supported. GTM TIM0 */
#define RESOURCE_SUPPORT_GTM_TIM1               /* Supported. GTM TIM1 */
#define RESOURCE_SUPPORT_GTM_TIM2               /* Supported. GTM TIM2 */
#define RESOURCE_SUPPORT_GTM_TIM3               /* Supported. GTM TIM3 */
#define RESOURCE_SUPPORT_GTM_TIM4               /* Supported. GTM TIM4 */
#define RESOURCE_SUPPORT_GTM_TIM5               /* Supported. GTM TIM5 */
#define RESOURCE_SUPPORT_GTM_TIM6               /* Supported. GTM TIM6 */
#define RESOURCE_SUPPORT_GTM_TIM7               /* Supported. GTM TIM7 */

#define RESOURCE_SUPPORT_GTM_TOM0               /* Supported. GTM TOM0 */
#define RESOURCE_SUPPORT_GTM_TOM1               /* Supported. GTM TOM1 */
#define RESOURCE_SUPPORT_GTM_TOM2               /* Supported. GTM TOM2 */
#define RESOURCE_SUPPORT_GTM_TOM3               /* Supported. GTM TOM3 */
#define RESOURCE_SUPPORT_GTM_TOM4               /* Supported. GTM TOM4 */
#define RESOURCE_SUPPORT_GTM_TOM5               /* Supported. GTM TOM5 */

/*----------------------------------CCU7: Capture/Compare Unit 7------------*/
/* RESOURCE_SUPPORT_CCU7_IP */              /* Unsupported. IP: CCU7, Capture/Compare Unit 7. */

/*---------------------------------PWM3012----------------------------------*/
#define RESOURCE_SUPPORT_PWM3012_IP         /* Supported. IP: PWM3012 */

/*----------------------------------MCAN------------------------------------*/
/* MCAN: 3 MCAN Modules, support 12 MCAN controllers */
#define RESOURCE_SUPPORT_MCAN_CONTROLLER_1      /* Supported. MCAN1 */
#define RESOURCE_SUPPORT_MCAN_CONTROLLER_2      /* Supported. MCAN2 */     
#define RESOURCE_SUPPORT_MCAN_CONTROLLER_3      /* Supported. MCAN3 */
#define RESOURCE_SUPPORT_MCAN_CONTROLLER_4      /* Supported. MCAN4 */
#define RESOURCE_SUPPORT_MCAN_CONTROLLER_5      /* Supported. MCAN5 */
#define RESOURCE_SUPPORT_MCAN_CONTROLLER_6      /* Supported. MCAN6 */
#define RESOURCE_SUPPORT_MCAN_CONTROLLER_7      /* Supported. MCAN7 */
#define RESOURCE_SUPPORT_MCAN_CONTROLLER_8      /* Supported. MCAN8 */
#define RESOURCE_SUPPORT_MCAN_CONTROLLER_9      /* Supported. MCAN9 */
#define RESOURCE_SUPPORT_MCAN_CONTROLLER_10     /* Supported. MCAN10 */
#define RESOURCE_SUPPORT_MCAN_CONTROLLER_11     /* Supported. MCAN11 */
#define RESOURCE_SUPPORT_MCAN_CONTROLLER_12     /* Supported. MCAN12 */

#define RESOURCE_SUPPORT_MCAN_RAM_SIZE     (64*1024U)   /* Supported. MCAN: MCAN1~MCAN4 shared 64KB RAM */
#define RESOURCE_SUPPORT_MCAN_RAM1_SIZE    (20*1024U)   /* Supported. MCAN: MCAN5~MCAN8 shared 20KB RAM */
#define RESOURCE_SUPPORT_MCAN_RAM2_SIZE    (20*1024U)   /* Supported. MCAN: MCAN9~MCAN12 shared 20KB RAM */

/* RESOURCE_SUPPORT_MCAN_DMU */                         /* Unsupported. DMA Interface Unit */
/* RESOURCE_SUPPORT_MCAN_TSU */                         /* Unsupported. Timestamping Unit */
/* RESOURCE_SUPPORT_MCAN_CHANGE_EDIAN_CCFC3008PCSN */   /* Unsupported. CAN RAM Hardware Endianess Conversion */
/* RESOURCE_SUPPORT_MCAN_CHANGE_EDIAN */                /* Unsupported. CAN RAM Hardware Endianess Conversion */

/*----------------------------------CANFD-----------------------------------*/
#define RESOURCE_SUPPORT_CANFD_IP               /* Supported. IP: CANFD */

/*----------------------------------CAN SAMPLER-----------------------------*/
#define RESOURCE_SUPPORT_CANSAMPLER_IP          /* Supported. IP: CANSAMPLER */
/* RESOURCE_SUPPORT_CANSAMPLER_27_SOURCES */    /* Unsupported. CAN SAMPLER: support 27 input sources */
#define RESOURCE_SUPPORT_CANSAMPLER_52_SOURCES  /* Supported. CAN SAMPLER: support 52 input sources */

/*----------------------------------DSPI------------------------------------*/
#define RESOURCE_SUPPORT_DSPI_0                     /* Supported. DSPI_0  */
#define RESOURCE_SUPPORT_DSPI_1                     /* Supported. DSPI_1  */
#define RESOURCE_SUPPORT_DSPI_2                     /* Supported. DSPI_2  */
#define RESOURCE_SUPPORT_DSPI_3                     /* Supported. DSPI_3  */
#define RESOURCE_SUPPORT_DSPI_4                     /* Supported. DSPI_4  */
#define RESOURCE_SUPPORT_DSPI_5                     /* Supported. DSPI_5  */
#define RESOURCE_SUPPORT_DSPI_6                     /* Supported. DSPI_6  */
#define RESOURCE_SUPPORT_DSPI_7                     /* Supported. DSPI_7  */
#define RESOURCE_SUPPORT_DSPI_8                     /* Supported. DSPI_8  */
#define RESOURCE_SUPPORT_DSPI_9                     /* Supported. DSPI_9  */
#define RESOURCE_SUPPORT_DSPI_10                    /* Supported. DSPI_10 */
#define RESOURCE_SUPPORT_DSPI_11                    /* Supported. DSPI_11 */
#define RESOURCE_SUPPORT_DSPI_12                    /* Supported. DSPI_12 */
#define RESOURCE_SUPPORT_DSPI_13                    /* Supported. DSPI_13 */
#define RESOURCE_SUPPORT_DSPI_14                    /* Supported. DSPI_14 */
#define RESOURCE_SUPPORT_DSPI_15                    /* Supported. DSPI_15 */
#define RESOURCE_SUPPORT_DSPI_16                    /* Supported. DSPI_16 */
#define RESOURCE_SUPPORT_DSPI_17                    /* Supported. DSPI_17 */
#define RESOURCE_SUPPORT_DSPI_18                    /* Supported. DSPI_18 */
#define RESOURCE_SUPPORT_DSPI_19                    /* Supported. DSPI_19 */
#define RESOURCE_SUPPORT_DSPI_20                    /* Supported. DSPI_20 */
#define RESOURCE_SUPPORT_DSPI_21                    /* Supported. DSPI_21 */
#define RESOURCE_SUPPORT_DSPI_LVDS                  /* Supported. exclude CCFC3008PT open LVDS */
/* RESOURCE_SUPPORT_DSPI_LVDS_CCFC3008PT*/          /* Unsupported. CCFC3008PT open LVDS */
#define RESOURCE_SUPPORT_DSPI_DISR                  /* Supported. DSPI Input Select function*/
#define RESOURCE_SUPPORT_GTM_TO_MSC                 /* Supported. GTM Trigger MSC */
/*----------------------------------SSI: Synchronous Serial Interface-------*/
/* Note: SSI = QSPI. */
#define RESOURCE_SUPPORT_SSI_IP             /* Supported. IP: SSI */
#ifdef RESOURCE_SUPPORT_SSI_IP
#define RESOURCE_SUPPORT_SSI0               /* Supported. SSI 0 */
#define RESOURCE_SUPPORT_SSI1               /* Supported. SSI 1 */
#endif

/*----------------------------------LINFlexD--------------------------------*/
#define LINFLEXD_MAX                        (16u)
#define RESOURCE_SUPPORT_LINFLEXD_0         /* Supported. LINFlexD 0  */
#define RESOURCE_SUPPORT_LINFLEXD_1         /* Supported. LINFlexD 1  */
#define RESOURCE_SUPPORT_LINFLEXD_2         /* Supported. LINFlexD 2  */
#define RESOURCE_SUPPORT_LINFLEXD_3         /* Supported. LINFlexD 3  */
#define RESOURCE_SUPPORT_LINFLEXD_4         /* Supported. LINFlexD 4  */
#define RESOURCE_SUPPORT_LINFLEXD_5         /* Supported. LINFlexD 5  */
#define RESOURCE_SUPPORT_LINFLEXD_6         /* Supported. LINFlexD 6  */
#define RESOURCE_SUPPORT_LINFLEXD_7         /* Supported. LINFlexD 7  */
#define RESOURCE_SUPPORT_LINFLEXD_8         /* Supported. LINFlexD 8  */
#define RESOURCE_SUPPORT_LINFLEXD_9         /* Supported. LINFlexD 9  */
#define RESOURCE_SUPPORT_LINFLEXD_10        /* Supported. LINFlexD 10 */
#define RESOURCE_SUPPORT_LINFLEXD_11        /* Supported. LINFlexD 11 */
#define RESOURCE_SUPPORT_LINFLEXD_12        /* Supported. LINFlexD 12 */
#define RESOURCE_SUPPORT_LINFLEXD_14        /* Supported. LINFlexD 14 */
#define RESOURCE_SUPPORT_LINFLEXD_15        /* Supported. LINFlexD 15 */
#define RESOURCE_SUPPORT_LINFLEXD_16        /* Supported. LINFlexD 16 */

/*----------------------------------I2C-------------------------------------*/
#define RESOURCE_SUPPORT_I2C

/*----------------------------------Ethernet--------------------------------*/
/* RESOURCE_SUPPORT_ETH_EMAC_IP */          /* Unsupported. IP: EMAC, Ethernet Media Access Controller */
#define RESOURCE_SUPPORT_ETH_GMAC_IP        /* Supported. IP: GMAC, Gigabit Ethernet MAC */

/*----------------------------------SENT------------------------------------*/
#define RESOURCE_SUPPORT_SENT               /* Supported. IP: SENT */
#define FEATURE_SRX_HAS_COMBINED_IRQ        /* Supported. srx channel has combined interrupt source */

/*----------------------------------CSENT-----------------------------------*/
#define RESOURCE_SUPPORT_CSENT              /* Supported. IP: CSENT */

/*----------------------------------PSI5------------------------------------*/
#define RESOURCE_SUPPORT_PSI5_IP            /* Supported. IP: PSI5 */
#define RESOURCE_SUPPORT_PSI5_0             /* Supported. 4 channels: 0-3  */
#define RESOURCE_SUPPORT_PSI5_CHANNEL_3     /* Supported. 4 channels: 0-3  */

/*----------------------------------PSI5-S----------------------------------*/
#define RESOURCE_SUPPORT_PSI5_S             /* Supported. IP: PSI5-S */

/*----------------------------------FlexRay---------------------------------*/
#define RESOURCE_SUPPORT_FLEXRAY            /* Supported. IP: FlexRay */
#define FLEXRAY_HW_CH_MAX                   (2U)

/*----------------------------------I2S-------------------------------------*/
/* RESOURCE_SUPPORT_I2S */                  /* Unsupported. IP: I2S */

/*----------------------------------SD_EMMC_HOST----------------------------*/
#define RESOURCE_SUPPORT_SD_EMMC            /* Supported. IP: SD_EMMC */

/*----------------------------------SPORT-------------------------------------*/
#define RESOURCE_SUPPORT_SPORT              /* Supported. IP: SPORT */

/*----------------------------------Crypto-------------------------------------*/
/*
    EB1: {3007PT, 3008PT, 3010PT, 3011PT, 3012PT, 3008PCSN}
    EB2: {3007BC}
    EB3: {3008PC}
*/
#define RESOURCE_SUPPORT_CRYPTO_EB1     (1U)

/*===================Device resource definition end=========================*/

/* PCS-progressive system clock switch  */
#define FEATURE_CGM_PCS_ENABLE  TRUE

/* MCU PLL1 clock define */
#define PLL1_CLK_600MHZ         (600UL)
#define PLL1_CLK_480MHZ         (480UL)
#define PLL1_CLK_300MHZ         (300UL)
#define MCU_PLL1_CLK            PLL1_CLK_600MHZ

/* MCU System clock ratio define */
#define MCU_SYSCLK_RATIO_2_1    (0x0201UL)
#define MCU_SYSCLK_RATIO_3_2    (0x0302UL)
#if (MCU_PLL1_CLK == PLL1_CLK_600MHZ)
#define MCU_SYSCLK_RATIO        MCU_SYSCLK_RATIO_3_2
#else
#define MCU_SYSCLK_RATIO        MCU_SYSCLK_RATIO_2_1
#endif

/* Enable checker core for z70 */
#define CHECKER_CORE_ENABLE

/* MCU(PLL,CGM,ME_MC) module features */

/* @brief Key and inverted key values so write access to MCTL register is permitted */
#define FEATURE_MC_ME_KEY       (0x5AF0U)
#define FEATURE_MC_ME_KEY_INV   (0xA50FU)

/* @brief Fast IRC trimmed clock frequency(16MHz). */
#define FEATURE_IRCOSC0_FREQ    (16000000U)

/* @brief Fast XOSC clock frequency(40MHz). */
#define XOSC_16MHZ              (16000000UL)
#define XOSC_40MHZ              (40000000UL)
#define FEATURE_XOSC0_FREQ      XOSC_40MHZ

/* FLASH module features */
#define FLS_CONTROLLER_NUM (7U)

/* Base pointer of flash peripheral */
#define     FLS_FMC                 (C55FMC)
#define     FLS_FMC_BASE            ((uint32_t)0xFFFE0000U)

#ifdef RESOURCE_SUPPORT_PFI0
    #define FLS_T40FMC0             (T40FMC0)
    #define FLS_T40FMC0_BASE        ((uint32_t)0xFFFE8000U)
#endif // RESOURCE_SUPPORT_PFI0

#ifdef RESOURCE_SUPPORT_PFI1
    #define FLS_T40FMC1             (T40FMC1)
    #define FLS_T40FMC1_BASE        ((uint32_t)0xFFFE8800U)
#endif // RESOURCE_SUPPORT_PFI1

#ifdef RESOURCE_SUPPORT_PFI2
    #define FLS_T40FMC2             (T40FMC2)
    #define FLS_T40FMC2_BASE        ((uint32_t)0xFFFE9000U)
#endif // RESOURCE_SUPPORT_PFI2

#ifdef RESOURCE_SUPPORT_PFI3
    #define FLS_T40FMC3             (T40FMC3)
    #define FLS_T40FMC3_BASE        ((uint32_t)0xFFFE9800U)
#endif // RESOURCE_SUPPORT_PFI3

#ifdef RESOURCE_SUPPORT_PFI4
    #define FLS_T40FMC4             (T40FMC4)
    #define FLS_T40FMC4_BASE        ((uint32_t)0xFFFEA000U)
#endif // RESOURCE_SUPPORT_PFI4

#ifdef RESOURCE_SUPPORT_PFI5
    #define FLS_T40FMC5             (T40FMC5)
    #define FLS_T40FMC5_BASE        ((uint32_t)0xFFFEA800U)
#endif // RESOURCE_SUPPORT_PFI5

/* The size of 16K block. */
#define FLS_16KB_SIZE           (0x4000U)
/* The size of 32K block. */
#define FLS_32KB_SIZE           (0x8000U)
/* The size of 48K block. */
#define FLS_48KB_SIZE           (0xC000U)
/* The size of 64K block. */
#define FLS_64KB_SIZE           (0x10000U)
/* The size of 256K block. */
#define FLS_256KB_SIZE          (0x40000U)

/*
 * @brief Flash block number for each address space
 * */
/* Low Block Number. */
#define FLS_LOW_16K_BLOCK       (6U)
#define FLS_LOW_32K_BLOCK       (2U)
#define FLS_LOW_64K_BLOCK       (4U)
#define FLS_LOW_BLOCK           (FLS_LOW_16K_BLOCK + FLS_LOW_32K_BLOCK + FLS_LOW_64K_BLOCK)
#define FLS_LOW_OFFSET          (0U)

/* Mid Block Number. */
#define FLS_MID_16K_BLOCK       (0U)
#define FLS_MID_32K_BLOCK       (0U)
#define FLS_MID_48K_BLOCK       (2U)
#define FLS_MID_64K_BLOCK       (0U)
#define FLS_MID_BLOCK           (FLS_MID_16K_BLOCK + FLS_MID_32K_BLOCK + FLS_MID_48K_BLOCK + FLS_MID_64K_BLOCK)
#define FLS_MID_OFFSET          (FLS_LOW_OFFSET + FLS_LOW_BLOCK)

/* High Block Number. */
#define FLS_HIGH_16K_BLOCK      (0U)
#define FLS_HIGH_32K_BLOCK      (0U)
#define FLS_HIGH_64K_BLOCK      (16U)
#define FLS_HIGH_BLOCK          (FLS_HIGH_16K_BLOCK + FLS_HIGH_32K_BLOCK + FLS_HIGH_64K_BLOCK)
#define FLS_HIGH_OFFSET         (FLS_MID_OFFSET + FLS_MID_BLOCK)

/* 256K Block Number. */
#define FLS_256K_BLOCK_LARGE0   (12U)
#define FLS_256K_BLOCK_LARGE1   (12U)
#define FLS_256K_BLOCK_LARGE2   (12U)
#define FLS_256K_BLOCK_LARGE3   (12U)
#define FLS_256K_BLOCK_LARGE4   (12U)
#define FLS_256K_BLOCK_LARGE5   (6U)
#define FLS_256K_BLOCK          (FLS_256K_BLOCK_LARGE0 + FLS_256K_BLOCK_LARGE1 + FLS_256K_BLOCK_LARGE2 + FLS_256K_BLOCK_LARGE3 + FLS_256K_BLOCK_LARGE4 + FLS_256K_BLOCK_LARGE5)
#define FLS_256K_LARGE0_OFFSET  (FLS_HIGH_OFFSET + FLS_HIGH_BLOCK)
#define FLS_256K_LARGE1_OFFSET  (FLS_256K_LARGE0_OFFSET + FLS_256K_BLOCK_LARGE0)
#define FLS_256K_LARGE2_OFFSET  (FLS_256K_LARGE1_OFFSET + FLS_256K_BLOCK_LARGE1)
#define FLS_256K_LARGE3_OFFSET  (FLS_256K_LARGE2_OFFSET + FLS_256K_BLOCK_LARGE2)
#define FLS_256K_LARGE4_OFFSET  (FLS_256K_LARGE3_OFFSET + FLS_256K_BLOCK_LARGE3)
#define FLS_256K_LARGE5_OFFSET  (FLS_256K_LARGE4_OFFSET + FLS_256K_BLOCK_LARGE4)

/* ALL Block Number. */
#define FLS_BLOCK_ALL           (FLS_LOW_BLOCK + FLS_MID_BLOCK + FLS_HIGH_BLOCK + FLS_256K_BLOCK)

/* PFIx Max Block Number */
#define FLS_PFIX_MAX_BLOCK (12U)

/* Flash block offset */
#define FLS_LOCK_OFFSET_LOW       (16U)
#define FLS_LOCK_OFFSET_MID       (8U)

/*
 * @brief Flash block mask define
 */
/* Flash block lock mask */
#define FLS_LOCK_MASK_LOW         (0xFFFFFFFFU >> (32U - FLS_LOW_BLOCK))
#define FLS_LOCK_MASK_MID         (0xFFFFFFFFU >> (32U - FLS_MID_BLOCK))
#define FLS_LOCK_MASK_HIGH        (0xFFFFFFFFU >> (32U - FLS_HIGH_BLOCK))
#define FLS_LOCK_MASK_LARGE0_256K (0xFFFFFFFFU >> (32U - FLS_256K_BLOCK_LARGE0))
#define FLS_LOCK_MASK_LARGE1_256K (0xFFFFFFFFU >> (32U - FLS_256K_BLOCK_LARGE1))
#define FLS_LOCK_MASK_LARGE2_256K (0xFFFFFFFFU >> (32U - FLS_256K_BLOCK_LARGE2))
#define FLS_LOCK_MASK_LARGE3_256K (0xFFFFFFFFU >> (32U - FLS_256K_BLOCK_LARGE3))
#define FLS_LOCK_MASK_LARGE4_256K (0xFFFFFFFFU >> (32U - FLS_256K_BLOCK_LARGE4))
#define FLS_LOCK_MASK_LARGE5_256K (0xFFFFFFFFU >> (32U - FLS_256K_BLOCK_LARGE5))

/* Flash block select mask */
#define FLS_SEL_MASK_LOW         (0xFFFFFFFFU >> (32U - FLS_LOW_BLOCK))
#define FLS_SEL_MASK_MID         (0xFFFFFFFFU >> (32U - FLS_MID_BLOCK))
#define FLS_SEL_MASK_HIGH        (0xFFFFFFFFU >> (32U - FLS_HIGH_BLOCK))
#define FLS_SEL_MASK_LARGE_256K  (0xFFFFFFFFU >> (32U - FLS_PFIX_MAX_BLOCK))
#define FLS_SEL_MASK_LARGE0_256K (0xFFFFFFFFU >> (32U - FLS_256K_BLOCK_LARGE0))
#define FLS_SEL_MASK_LARGE1_256K (0xFFFFFFFFU >> (32U - FLS_256K_BLOCK_LARGE1))
#define FLS_SEL_MASK_LARGE2_256K (0xFFFFFFFFU >> (32U - FLS_256K_BLOCK_LARGE2))
#define FLS_SEL_MASK_LARGE3_256K (0xFFFFFFFFU >> (32U - FLS_256K_BLOCK_LARGE3))
#define FLS_SEL_MASK_LARGE4_256K (0xFFFFFFFFU >> (32U - FLS_256K_BLOCK_LARGE4))
#define FLS_SEL_MASK_LARGE5_256K (0xFFFFFFFFU >> (32U - FLS_256K_BLOCK_LARGE5))

/* Flash register numbers */
#define FLS_REG_NUM             (30U)

typedef struct
{
    uint32_t addrStart;
    uint32_t addrEnd;
    uint32_t lockSelReg;
    uint32_t lockSelBit;
    uint32_t blockSize;
} flash_info_t;

typedef struct
{
    const char * regName;
    uint32_t defValue;
    uint32_t regAddr;
} flash_regs_t;

typedef struct
{
    uint32_t block;
    volatile struct C55FMC_tag *controller;
} flash_block_map_t;

typedef struct
{
    volatile struct C55FMC_tag *controller;
    volatile struct C55FMC_tag *mapped_controller;
} flash_controller_map_t;

typedef struct
{
    volatile struct C55FMC_tag *controller;
    volatile struct PFLASH_tag *mapped_pflash;
} flash_pflash_map_t;

static const flash_pflash_map_t flashPFlashMap[FLS_CONTROLLER_NUM] = {
    {&FLS_FMC,     &PFLASH},
    {&FLS_T40FMC0, &PFI0_PFLASH},
    {&FLS_T40FMC1, &PFI1_PFLASH},
    {&FLS_T40FMC2, &PFI2_PFLASH},
    {&FLS_T40FMC3, &PFI3_PFLASH},
    {&FLS_T40FMC4, &PFI4_PFLASH},
    {&FLS_T40FMC5, &PFI5_PFLASH},
};

static const flash_block_map_t flashBlockMap0[FLS_BLOCK_ALL] = {
    /* Low Block */
    {0,  &FLS_FMC},
    {1,  &FLS_FMC},
    {2,  &FLS_FMC},
    {3,  &FLS_FMC},
    {4,  &FLS_FMC},
    {5,  &FLS_FMC},
    {6,  &FLS_FMC},
    {7,  &FLS_FMC},
    {8,  &FLS_FMC},
    {9,  &FLS_FMC},
    {10, &FLS_FMC},
    {11, &FLS_FMC},

    /* Mid Block */
    {12, &FLS_FMC},
    {13, &FLS_FMC},

    /* High Block */
    {14, &FLS_FMC},
    {15, &FLS_FMC},
    {16, &FLS_FMC},
    {17, &FLS_FMC},
    {18, &FLS_FMC},
    {19, &FLS_FMC},
    {20, &FLS_FMC},
    {21, &FLS_FMC},
    {22, &FLS_FMC},
    {23, &FLS_FMC},
    {24, &FLS_FMC},
    {25, &FLS_FMC},
    {26, &FLS_FMC},
    {27, &FLS_FMC},
    {28, &FLS_FMC},
    {29, &FLS_FMC},

    /* 256K Block */
    {30, &FLS_T40FMC0},
    {31, &FLS_T40FMC0},
    {32, &FLS_T40FMC0},
    {33, &FLS_T40FMC0},
    {34, &FLS_T40FMC0},
    {35, &FLS_T40FMC0},
    {36, &FLS_T40FMC0},
    {37, &FLS_T40FMC0},
    {38, &FLS_T40FMC0},
    {39, &FLS_T40FMC0},
    {40, &FLS_T40FMC0},
    {41, &FLS_T40FMC0},
    {42, &FLS_T40FMC1},
    {43, &FLS_T40FMC1},
    {44, &FLS_T40FMC1},
    {45, &FLS_T40FMC1},
    {46, &FLS_T40FMC1},
    {47, &FLS_T40FMC1},
    {48, &FLS_T40FMC1},
    {49, &FLS_T40FMC1},
    {50, &FLS_T40FMC1},
    {51, &FLS_T40FMC1},
    {52, &FLS_T40FMC1},
    {53, &FLS_T40FMC1},
    {54, &FLS_T40FMC2},
    {55, &FLS_T40FMC2},
    {56, &FLS_T40FMC2},
    {57, &FLS_T40FMC2},
    {58, &FLS_T40FMC2},
    {59, &FLS_T40FMC2},
    {60, &FLS_T40FMC2},
    {61, &FLS_T40FMC2},
    {62, &FLS_T40FMC2},
    {63, &FLS_T40FMC2},
    {64, &FLS_T40FMC2},
    {65, &FLS_T40FMC2},
    {66, &FLS_T40FMC3},
    {67, &FLS_T40FMC3},
    {68, &FLS_T40FMC3},
    {69, &FLS_T40FMC3},
    {70, &FLS_T40FMC3},
    {71, &FLS_T40FMC3},
    {72, &FLS_T40FMC3},
    {73, &FLS_T40FMC3},
    {74, &FLS_T40FMC3},
    {75, &FLS_T40FMC3},
    {76, &FLS_T40FMC3},
    {77, &FLS_T40FMC3},
    {78, &FLS_T40FMC4},
    {79, &FLS_T40FMC4},
    {80, &FLS_T40FMC4},
    {81, &FLS_T40FMC4},
    {82, &FLS_T40FMC4},
    {83, &FLS_T40FMC4},
    {84, &FLS_T40FMC4},
    {85, &FLS_T40FMC4},
    {86, &FLS_T40FMC4},
    {87, &FLS_T40FMC4},
    {88, &FLS_T40FMC4},
    {89, &FLS_T40FMC4},
    {90, &FLS_T40FMC5},
    {91, &FLS_T40FMC5},
    {92, &FLS_T40FMC5},
    {93, &FLS_T40FMC5},
    {94, &FLS_T40FMC5},
    {95, &FLS_T40FMC5},
};

static const flash_block_map_t flashBlockMap1[FLS_BLOCK_ALL] = {
    /* Low Block */
    {0,  &FLS_FMC},
    {1,  &FLS_FMC},
    {2,  &FLS_FMC},
    {3,  &FLS_FMC},
    {4,  &FLS_FMC},
    {5,  &FLS_FMC},
    {6,  &FLS_FMC},
    {7,  &FLS_FMC},
    {8,  &FLS_FMC},
    {9,  &FLS_FMC},
    {10, &FLS_FMC},
    {11, &FLS_FMC},

    /* Mid Block */
    {12, &FLS_FMC},
    {13, &FLS_FMC},

    /* High Block */
    {14, &FLS_FMC},
    {15, &FLS_FMC},
    {16, &FLS_FMC},
    {17, &FLS_FMC},
    {18, &FLS_FMC},
    {19, &FLS_FMC},
    {20, &FLS_FMC},
    {21, &FLS_FMC},
    {22, &FLS_FMC},
    {23, &FLS_FMC},
    {24, &FLS_FMC},
    {25, &FLS_FMC},
    {26, &FLS_FMC},
    {27, &FLS_FMC},
    {28, &FLS_FMC},
    {29, &FLS_FMC},

    /* 256K Block */
    {30, &FLS_T40FMC3},
    {31, &FLS_T40FMC3},
    {32, &FLS_T40FMC3},
    {33, &FLS_T40FMC3},
    {34, &FLS_T40FMC3},
    {35, &FLS_T40FMC3},
    {36, &FLS_T40FMC3},
    {37, &FLS_T40FMC3},
    {38, &FLS_T40FMC3},
    {39, &FLS_T40FMC3},
    {40, &FLS_T40FMC3},
    {41, &FLS_T40FMC3},
    {42, &FLS_T40FMC4},
    {43, &FLS_T40FMC4},
    {44, &FLS_T40FMC4},
    {45, &FLS_T40FMC4},
    {46, &FLS_T40FMC4},
    {47, &FLS_T40FMC4},
    {48, &FLS_T40FMC4},
    {49, &FLS_T40FMC4},
    {50, &FLS_T40FMC4},
    {51, &FLS_T40FMC4},
    {52, &FLS_T40FMC4},
    {53, &FLS_T40FMC4},
    {54, &FLS_T40FMC5},
    {55, &FLS_T40FMC5},
    {56, &FLS_T40FMC5},
    {57, &FLS_T40FMC5},
    {58, &FLS_T40FMC5},
    {59, &FLS_T40FMC5},
    {60, &FLS_T40FMC5},
    {61, &FLS_T40FMC5},
    {62, &FLS_T40FMC5},
    {63, &FLS_T40FMC5},
    {64, &FLS_T40FMC5},
    {65, &FLS_T40FMC5},
    {66, &FLS_T40FMC0},
    {67, &FLS_T40FMC0},
    {68, &FLS_T40FMC0},
    {69, &FLS_T40FMC0},
    {70, &FLS_T40FMC0},
    {71, &FLS_T40FMC0},
    {72, &FLS_T40FMC0},
    {73, &FLS_T40FMC0},
    {74, &FLS_T40FMC0},
    {75, &FLS_T40FMC0},
    {76, &FLS_T40FMC0},
    {77, &FLS_T40FMC0},
    {78, &FLS_T40FMC1},
    {79, &FLS_T40FMC1},
    {80, &FLS_T40FMC1},
    {81, &FLS_T40FMC1},
    {82, &FLS_T40FMC1},
    {83, &FLS_T40FMC1},
    {84, &FLS_T40FMC1},
    {85, &FLS_T40FMC1},
    {86, &FLS_T40FMC1},
    {87, &FLS_T40FMC1},
    {88, &FLS_T40FMC1},
    {89, &FLS_T40FMC1},
    {90, &FLS_T40FMC2},
    {91, &FLS_T40FMC2},
    {92, &FLS_T40FMC2},
    {93, &FLS_T40FMC2},
    {94, &FLS_T40FMC2},
    {95, &FLS_T40FMC2},
};

static const flash_controller_map_t flashControllerMap0[FLS_CONTROLLER_NUM] = {
    {&FLS_FMC,     &FLS_FMC},
    {&FLS_T40FMC0, &FLS_T40FMC0},
    {&FLS_T40FMC1, &FLS_T40FMC1},
    {&FLS_T40FMC2, &FLS_T40FMC2},
    {&FLS_T40FMC3, &FLS_T40FMC3},
    {&FLS_T40FMC4, &FLS_T40FMC4},
    {&FLS_T40FMC5, &FLS_T40FMC5},
};

static const flash_controller_map_t flashControllerMap1[FLS_CONTROLLER_NUM] = {
    {&FLS_FMC,     &FLS_FMC},
    {&FLS_T40FMC0, &FLS_T40FMC3},
    {&FLS_T40FMC1, &FLS_T40FMC4},
    {&FLS_T40FMC2, &FLS_T40FMC5},
    {&FLS_T40FMC3, &FLS_T40FMC0},
    {&FLS_T40FMC4, &FLS_T40FMC1},
    {&FLS_T40FMC5, &FLS_T40FMC2},
};

static const flash_info_t flashInfo[FLS_BLOCK_ALL] = {
    /* Low Block */
    {0x00404000U, 0x00407FFFU, 0U, 16U, FLS_16KB_SIZE},  /* block 0    P0 (BAF)         */
    {0x00FC0000U, 0x00FC3FFFU, 0U, 17U, FLS_16KB_SIZE},  /* block 1    P0 (Normal Code) */
    {0x00FC4000U, 0x00FC7FFFU, 0U, 18U, FLS_16KB_SIZE},  /* block 2    P0 (Normal Code) */
    {0x00FC8000U, 0x00FCBFFFU, 0U, 19U, FLS_16KB_SIZE},  /* block 3    P1 (Normal Code) */
    {0x00FCC000U, 0x00FCFFFFU, 0U, 20U, FLS_16KB_SIZE},  /* block 4    P1 (Normal Code) */
    {0x0060C000U, 0x0060FFFFU, 0U, 21U, FLS_16KB_SIZE},  /* block 5    P1 (HSM Code)    */
    {0x00FD0000U, 0x00FD7FFFU, 0U, 22U, FLS_32KB_SIZE},  /* block 6    P0 (Normal Code) */
    {0x00FD8000U, 0x00FDFFFFU, 0U, 23U, FLS_32KB_SIZE},  /* block 7    P1 (Normal Code) */
    {0x00FE0000U, 0x00FEFFFFU, 0U, 24U, FLS_64KB_SIZE},  /* block 8    P0 (HSM Code)    */
    {0x00FF0000U, 0x00FFFFFFU, 0U, 25U, FLS_64KB_SIZE},  /* block 9    P0 (HSM Code)    */
    {0x00610000U, 0x0061FFFFU, 0U, 26U, FLS_64KB_SIZE},  /* block 10   P1 (HSM Code)    */
    {0x00620000U, 0x0062FFFFU, 0U, 27U, FLS_64KB_SIZE},  /* block 11   P1 (HSM Code)    */

    /* Mid Block */
    {0x006C0000U, 0x006CBFFFU, 0U, 8U, FLS_48KB_SIZE},   /* block 12   P0 (Normal Code) */
    {0x006CC000U, 0x006D7FFFU, 0U, 9U, FLS_48KB_SIZE},   /* block 13   P1 (Normal Code) */

    /* High Block */
    {0x00800000U, 0x0080FFFFU, 1U, 0U,  FLS_64KB_SIZE},  /* block 14   P3 (EEPROM) */
    {0x00810000U, 0x0081FFFFU, 1U, 1U,  FLS_64KB_SIZE},  /* block 15   P3 (EEPROM) */
    {0x00820000U, 0x0082FFFFU, 1U, 2U,  FLS_64KB_SIZE},  /* block 16   P3 (EEPROM) */
    {0x00830000U, 0x0083FFFFU, 1U, 3U,  FLS_64KB_SIZE},  /* block 17   P3 (EEPROM) */
    {0x00840000U, 0x0084FFFFU, 1U, 4U,  FLS_64KB_SIZE},  /* block 18   P3 (EEPROM) */
    {0x00850000U, 0x0085FFFFU, 1U, 5U,  FLS_64KB_SIZE},  /* block 19   P3 (EEPROM) */
    {0x00860000U, 0x0086FFFFU, 1U, 6U,  FLS_64KB_SIZE},  /* block 20   P3 (EEPROM) */
    {0x00870000U, 0x0087FFFFU, 1U, 7U,  FLS_64KB_SIZE},  /* block 21   P3 (EEPROM) */
    {0x00880000U, 0x0088FFFFU, 1U, 8U,  FLS_64KB_SIZE},  /* block 22   P3 (EEPROM) */
    {0x00890000U, 0x0089FFFFU, 1U, 9U,  FLS_64KB_SIZE},  /* block 23   P3 (EEPROM) */
    {0x008A0000U, 0x008AFFFFU, 1U, 10U, FLS_64KB_SIZE},  /* block 24   P3 (EEPROM) */
    {0x008B0000U, 0x008BFFFFU, 1U, 11U, FLS_64KB_SIZE},  /* block 25   P3 (EEPROM) */
    {0x008C0000U, 0x008CFFFFU, 1U, 12U, FLS_64KB_SIZE},  /* block 26   P3 (EEPROM) */
    {0x008D0000U, 0x008DFFFFU, 1U, 13U, FLS_64KB_SIZE},  /* block 27   P3 (EEPROM) */
    {0x008E0000U, 0x008EFFFFU, 1U, 14U, FLS_64KB_SIZE},  /* block 28   P3 (EEPROM) */
    {0x008F0000U, 0x008FFFFFU, 1U, 15U, FLS_64KB_SIZE},  /* block 29   P3 (EEPROM) */

    /* 256K Block */
    {0x01000000U, 0x0103FFFFU, 0U, 0U,  FLS_256KB_SIZE}, /* block 30   P4  */
    {0x01040000U, 0x0107FFFFU, 0U, 1U,  FLS_256KB_SIZE}, /* block 31   P4  */
    {0x01080000U, 0x010BFFFFU, 0U, 2U,  FLS_256KB_SIZE}, /* block 32   P4  */
    {0x010C0000U, 0x010FFFFFU, 0U, 3U,  FLS_256KB_SIZE}, /* block 33   P4  */
    {0x01100000U, 0x0113FFFFU, 0U, 4U,  FLS_256KB_SIZE}, /* block 34   P4  */
    {0x01140000U, 0x0117FFFFU, 0U, 5U,  FLS_256KB_SIZE}, /* block 35   P4  */
    {0x01180000U, 0x011BFFFFU, 0U, 6U,  FLS_256KB_SIZE}, /* block 36   P5  */
    {0x011C0000U, 0x011FFFFFU, 0U, 7U,  FLS_256KB_SIZE}, /* block 37   P5  */
    {0x01200000U, 0x0123FFFFU, 0U, 8U,  FLS_256KB_SIZE}, /* block 38   P5  */
    {0x01240000U, 0x0127FFFFU, 0U, 9U,  FLS_256KB_SIZE}, /* block 39   P5  */
    {0x01280000U, 0x012BFFFFU, 0U, 10U, FLS_256KB_SIZE}, /* block 40   P5  */
    {0x012C0000U, 0x012FFFFFU, 0U, 11U, FLS_256KB_SIZE}, /* block 41   P5  */
    {0x01300000U, 0x0133FFFFU, 1U, 0U,  FLS_256KB_SIZE}, /* block 42   P6  */
    {0x01340000U, 0x0137FFFFU, 1U, 1U,  FLS_256KB_SIZE}, /* block 43   P6  */
    {0x01380000U, 0x013BFFFFU, 1U, 2U,  FLS_256KB_SIZE}, /* block 44   P6  */
    {0x013C0000U, 0x013FFFFFU, 1U, 3U,  FLS_256KB_SIZE}, /* block 45   P6  */
    {0x01400000U, 0x0143FFFFU, 1U, 4U,  FLS_256KB_SIZE}, /* block 46   P6  */
    {0x01440000U, 0x0147FFFFU, 1U, 5U,  FLS_256KB_SIZE}, /* block 47   P6  */
    {0x01480000U, 0x014BFFFFU, 1U, 6U,  FLS_256KB_SIZE}, /* block 48   P7  */
    {0x014C0000U, 0x014FFFFFU, 1U, 7U,  FLS_256KB_SIZE}, /* block 49   P7  */
    {0x01500000U, 0x0153FFFFU, 1U, 8U,  FLS_256KB_SIZE}, /* block 50   P7  */
    {0x01540000U, 0x0157FFFFU, 1U, 9U,  FLS_256KB_SIZE}, /* block 51   P7  */
    {0x01580000U, 0x015BFFFFU, 1U, 10U, FLS_256KB_SIZE}, /* block 52   P7  */
    {0x015C0000U, 0x015FFFFFU, 1U, 11U, FLS_256KB_SIZE}, /* block 53   P7  */
    {0x01600000U, 0x0163FFFFU, 2U, 0U,  FLS_256KB_SIZE}, /* block 54   P8  */
    {0x01640000U, 0x0167FFFFU, 2U, 1U,  FLS_256KB_SIZE}, /* block 55   P8  */
    {0x01680000U, 0x016BFFFFU, 2U, 2U,  FLS_256KB_SIZE}, /* block 56   P8  */
    {0x016C0000U, 0x016FFFFFU, 2U, 3U,  FLS_256KB_SIZE}, /* block 57   P8  */
    {0x01700000U, 0x0173FFFFU, 2U, 4U,  FLS_256KB_SIZE}, /* block 58   P8  */
    {0x01740000U, 0x0177FFFFU, 2U, 5U,  FLS_256KB_SIZE}, /* block 59   P8  */
    {0x01780000U, 0x017BFFFFU, 2U, 6U,  FLS_256KB_SIZE}, /* block 60   P9  */
    {0x017C0000U, 0x017FFFFFU, 2U, 7U,  FLS_256KB_SIZE}, /* block 61   P9  */
    {0x01800000U, 0x0183FFFFU, 2U, 8U,  FLS_256KB_SIZE}, /* block 62   P9  */
    {0x01840000U, 0x0187FFFFU, 2U, 9U,  FLS_256KB_SIZE}, /* block 63   P9  */
    {0x01880000U, 0x018BFFFFU, 2U, 10U, FLS_256KB_SIZE}, /* block 64   P9  */
    {0x018C0000U, 0x018FFFFFU, 2U, 11U, FLS_256KB_SIZE}, /* block 65   P9  */
    {0x01900000U, 0x0193FFFFU, 3U, 0U,  FLS_256KB_SIZE}, /* block 66   P10 */
    {0x01940000U, 0x0197FFFFU, 3U, 1U,  FLS_256KB_SIZE}, /* block 67   P10 */
    {0x01980000U, 0x019BFFFFU, 3U, 2U,  FLS_256KB_SIZE}, /* block 68   P10 */
    {0x019C0000U, 0x019FFFFFU, 3U, 3U,  FLS_256KB_SIZE}, /* block 69   P10 */
    {0x01A00000U, 0x01A3FFFFU, 3U, 4U,  FLS_256KB_SIZE}, /* block 70   P10 */
    {0x01A40000U, 0x01A7FFFFU, 3U, 5U,  FLS_256KB_SIZE}, /* block 71   P10 */
    {0x01A80000U, 0x01ABFFFFU, 3U, 6U,  FLS_256KB_SIZE}, /* block 72   P11 */
    {0x01AC0000U, 0x01AFFFFFU, 3U, 7U,  FLS_256KB_SIZE}, /* block 73   P11 */
    {0x01B00000U, 0x01B3FFFFU, 3U, 8U,  FLS_256KB_SIZE}, /* block 74   P11 */
    {0x01B40000U, 0x01B7FFFFU, 3U, 9U,  FLS_256KB_SIZE}, /* block 75   P11 */
    {0x01B80000U, 0x01BBFFFFU, 3U, 10U, FLS_256KB_SIZE}, /* block 76   P11 */
    {0x01BC0000U, 0x01BFFFFFU, 3U, 11U, FLS_256KB_SIZE}, /* block 77   P11 */
    {0x01C00000U, 0x01C3FFFFU, 4U, 0U,  FLS_256KB_SIZE}, /* block 78   P12 */
    {0x01C40000U, 0x01C7FFFFU, 4U, 1U,  FLS_256KB_SIZE}, /* block 79   P12 */
    {0x01C80000U, 0x01CBFFFFU, 4U, 2U,  FLS_256KB_SIZE}, /* block 80   P12 */
    {0x01CC0000U, 0x01CFFFFFU, 4U, 3U,  FLS_256KB_SIZE}, /* block 81   P12 */
    {0x01D00000U, 0x01D3FFFFU, 4U, 4U,  FLS_256KB_SIZE}, /* block 82   P12 */
    {0x01D40000U, 0x01D7FFFFU, 4U, 5U,  FLS_256KB_SIZE}, /* block 83   P12 */
    {0x01D80000U, 0x01DBFFFFU, 4U, 6U,  FLS_256KB_SIZE}, /* block 84   P13 */
    {0x01DC0000U, 0x01DFFFFFU, 4U, 7U,  FLS_256KB_SIZE}, /* block 85   P13 */
    {0x01E00000U, 0x01E3FFFFU, 4U, 8U,  FLS_256KB_SIZE}, /* block 86   P13 */
    {0x01E40000U, 0x01E7FFFFU, 4U, 9U,  FLS_256KB_SIZE}, /* block 87   P13 */
    {0x01E80000U, 0x01EBFFFFU, 4U, 10U, FLS_256KB_SIZE}, /* block 88   P13 */
    {0x01EC0000U, 0x01EFFFFFU, 4U, 11U, FLS_256KB_SIZE}, /* block 89   P13 */
    {0x01F00000U, 0x01F3FFFFU, 5U, 0U,  FLS_256KB_SIZE}, /* block 90   P14 */
    {0x01F40000U, 0x01F7FFFFU, 5U, 1U,  FLS_256KB_SIZE}, /* block 91   P14 */
    {0x01F80000U, 0x01FBFFFFU, 5U, 2U,  FLS_256KB_SIZE}, /* block 92   P14 */
    {0x01FC0000U, 0x01FFFFFFU, 5U, 3U,  FLS_256KB_SIZE}, /* block 93   P14 */
    {0x02000000U, 0x0203FFFFU, 5U, 4U,  FLS_256KB_SIZE}, /* block 94   P14 */
    {0x02040000U, 0x0207FFFFU, 5U, 5U,  FLS_256KB_SIZE}, /* block 95   P14 */
};

static const flash_regs_t flashRegs[FLS_REG_NUM] = {
    {"MCR",    0x00000600,     0xfffe0000},
    {"MCRA",   0x00000600,     0xfffe0004},
    {"MCRE",   0x18e0054b,     0xfffe0008},
    {"LOCK0",  0xBFFFFFFF,     0xfffe0010},
    {"LOCK1",  0x0000FFFF,     0xfffe0014},
    {"LOCK2",  0xFFFFFFFF,     0xfffe0018},
    {"LOCK3",  0x0000FFFF,     0xfffe001c},
    {"LOCK0A", 0xBFFFFFFF,     0xfffe0028},
    {"LOCK1A", 0x0000FFFF,     0xfffe002c},
    {"SEL0",   0x00000000,     0xfffe0038},
    {"SEL1",   0x00000000,     0xfffe003c},
    {"SEL2",   0x00000000,     0xfffe0040},
    {"SEL3",   0x00000000,     0xfffe0044},
    {"ADR",    0x00000000,     0xfffe0050},
    {"UT0",    0x00000001,     0xfffe0054},
    {"UM0",    0x00000000,     0xfffe0058},
    {"UM1",    0x00000000,     0xfffe005c},
    {"UM2",    0x00000000,     0xfffe0060},
    {"UM3",    0x00000000,     0xfffe0064},
    {"UM4",    0x00000000,     0xfffe0068},
    {"UM5",    0x00000000,     0xfffe006c},
    {"UM6",    0x00000000,     0xfffe0070},
    {"UM7",    0x00000000,     0xfffe0074},
    {"UM8",    0x00000000,     0xfffe0078},
    {"UM9",    0x00000000,     0xfffe007c},
    {"OPP0",   0x30010000,     0xfffe0080},
    {"OPP1",   0x00000000,     0xfffe0084},
    {"OPP2",   0x00000000,     0xfffe0088},
    {"OPP3",   0x0000FFFF,     0xfffe008c},
    {"TMD",    0x00000000,     0xfffe0090},
};

/* PFLASH module features */

/* Count of Calibration Region Descriptor */
#define PFLASH_PFCRD_COUNT               (32U)
/* Count of Safe Calibration Region Descriptor */
#define PFLASH_PFCRD_SAFE_COUNT          (PFLASH_PFCRD_COUNT/2)
/*
 * Safe Calibration Control
 * 0U: normal calibration
 * 1U: safe calibration
 * */
#define PFLASH_Safe_Calibration          (0U)

/* Flash Remap Size */
typedef enum
{
    REMAP_SIZE_32B =   5U,
    REMAP_SIZE_64B =   6U,
    REMAP_SIZE_128B =  7U,
    REMAP_SIZE_256B =  8U,
    REMAP_SIZE_512B =  9U,
    REMAP_SIZE_1KB =   10U,
    REMAP_SIZE_2KB =   11U,
    REMAP_SIZE_4KB =   12U,
    REMAP_SIZE_8KB =   13U,
    REMAP_SIZE_16KB =  14U,
    REMAP_SIZE_32KB =  15U,
    REMAP_SIZE_64KB =  16U,
    REMAP_SIZE_128KB = 17U,
    REMAP_SIZE_256KB = 18U,
    REMAP_SIZE_512KB = 19U,
    REMAP_SIZE_1MB =   20U,
    REMAP_SIZE_2MB =   21U,
    REMAP_SIZE_4MB =   22U,
    REMAP_SIZE_8MB =   23U
} flash_remap_size_t;

typedef struct
{
    uint32_t flsLogicAddr;
    uint32_t ramPhyAddr;
    flash_remap_size_t remapSize;
} flash_remap_config_t;

/* MEMU module features */
/* Peripheral RAM ECC Correctable Error Detect */
#define MEMU_ERR_FLAG_PR_CE   (0x00100000U)
/* Peripheral RAM ECC Uncorrectable Error Detect */
#define MEMU_ERR_FLAG_PR_UCE  (0x00080000U)
/* Peripheral RAM ECC Correctable error Overflow */
#define MEMU_ERR_FLAG_PR_CEO  (0x00040000U)
/* Peripheral RAM ECC Uncorrectable error Overflow */
#define MEMU_ERR_FLAG_PR_UCO  (0x00020000U)
/* Peripheral RAM ECC Error buffer Overflow */
#define MEMU_ERR_FLAG_PR_EBO  (0x00010000U)
/* Flash ECC Correctable Error Detect */
#define MEMU_ERR_FLAG_F_CE    (0x00001000U)
/* Flash ECC Uncorrectable Error Detect */
#define MEMU_ERR_FLAG_F_UCE   (0x00000800U)
/* Flash ECC Correctable Error Overflow */
#define MEMU_ERR_FLAG_F_CEO   (0x00000400U)
/* Flash ECC Uncorrectable Error Overflow */
#define MEMU_ERR_FLAG_F_UCO   (0x00000200U)
/* Flash ECC Error buffer Overflow */
#define MEMU_ERR_FLAG_F_EBO   (0x00000100U)
/* System RAM ECC and MBIST Correctable Error Detect */
#define MEMU_ERR_FLAG_SR_CE   (0x00000010U)
/* System RAM ECC and MBIST Uncorrectable Error Detect */
#define MEMU_ERR_FLAG_SR_UCE  (0x00000008U)
/* System RAM ECC and MBIST Correctable error Overflow */
#define MEMU_ERR_FLAG_SR_CEO  (0x00000004U)
/* System RAM ECC and MBIST Uncorrectable error Overflow */
#define MEMU_ERR_FLAG_SR_UCO  (0x00000002U)
/* System RAM ECC and MBIST Error buffer Overflow */
#define MEMU_ERR_FLAG_SR_EBO  (0x00000001U)

/* MEMU_ERR_FLAG grouped */
#define MEMU_ERR_FLAG_PERRAM_all               (0x001F0000U)
#define MEMU_ERR_FLAG_FLASH_all                (0x00001F00U)
#define MEMU_ERR_FLAG_SYSRAM_all               (0x0000001FU)
#define MEMU_ERR_FLAG_correctable_all          (0x00101010U)
#define MEMU_ERR_FLAG_uncorrectable_all        (0x00080808U)
#define MEMU_ERR_FLAG_correctable_overflows    (0x00040404U)
#define MEMU_ERR_FLAG_uncorrectable_overflows  (0x00020202U)
#define MEMU_ERR_FLAG_buffer_overflows         (0x00010101U)
#define MEMU_ERR_FLAG_PERRAM_overflows         (0x00070000U)
#define MEMU_ERR_FLAG_FLASH_overflows          (0x00000700U)
#define MEMU_ERR_FLAG_SYSRAM_overflows         (0x00000007U)

/* Size of Registers Arrays */
#define SMPU_ERR_COUNT                           (16u)

/* SMPU0 base pointer */
#define SMPU0_PTR                               ((volatile SMPU_Type *)(0xFC010000UL))
/* SMPU1 base pointer */
#define SMPU1_PTR                               ((volatile SMPU_Type *)(0xFC014000UL))
#define SMPU2_PTR                               ((volatile SMPU_Type *)(0xFC084000UL))
#define SMPU3_PTR                               ((volatile SMPU_Type *)(0xFC094000UL))

/* SMPU protect address region */
#define SMPU_START_ADDR            (0x00000000U)
#define SMPU_END_ADDR              (0xFFFFFFFFU)

/* Core MPU module features */

typedef union
{
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t RASIZE:7;  /* Number of Bits of Real Address supported */
    vuint32_t  :6;
    vuint32_t PIDSIZE:5; /* PID Register Size */
    vuint32_t NMPUS:2;   /* Number of MPUs */
    vuint32_t NTLBS:2;   /* Number of TLBs */
    vuint32_t MAVN:2;    /* MMU Architecture Version Number */
  } B;
} MMUCFG;

typedef union  {
  vuint32_t R;
  struct {
    vuint32_t FASSOC:1;  /* Fully Associative */
    vuint32_t  :7;
    vuint32_t MINSIZE:4; /* Minimum Region Size */
    vuint32_t MAXSIZE:4; /* Maximum Region Size */
    vuint32_t IPROT:1;   /* Invalidate Protect Capability */
    vuint32_t  :1;
    vuint32_t UAMSKA:1;  /* Upper Address Masking Availability */
    vuint32_t  :4;
    vuint32_t SHENTRY:3; /* Number of Shared (configurable for I or D) Entries */
    vuint32_t DENTRY:3;  /* Number of Data Entries */
    vuint32_t IENTRY:3;  /* Number of Instruction Entries */
  } B;
} MPU0CFG;

/* Maximum region size in bytes */
#define CMPU_MAX_REGION_SIZE        (4*1024*1024*1024ULL)
/* Minimum region size in bytes */
#define CMPU_MIN_REGION_SIZE        (8U)

/* MPU0CSR0 Bit Fields */
#define CMPU_CSR_BYPS_MASK          0x0000E000u
#define CMPU_CSR_BYPS_SHIFT         13u
#define CMPU_CSR_BYPS(x)            (((uint32_t)(((uint32_t)(x))<<CMPU_CSR_BYPS_SHIFT))&CMPU_CSR_BYPS_MASK)
#define CMPU_CSR_BYPS_GET(x)        (((uint32_t)(((uint32_t)(x))&CMPU_CSR_BYPS_MASK))>>CMPU_CSR_BYPS_SHIFT)
#define CMPU_CSR_BYPU_MASK          0x00001C00u
#define CMPU_CSR_BYPU_SHIFT         10u
#define CMPU_CSR_BYPU(x)            (((uint32_t)(((uint32_t)(x))<<CMPU_CSR_BYPU_SHIFT))&CMPU_CSR_BYPU_MASK)
#define CMPU_CSR_BYPU_GET(x)        (((uint32_t)(((uint32_t)(x))&CMPU_CSR_BYPU_MASK))>>CMPU_CSR_BYPU_SHIFT)
#define CMPU_CSR_DEN_MASK           0x000000E0u
#define CMPU_CSR_DEN_SHIFT          5u
#define CMPU_CSR_DEN(x)             (((uint32_t)(((uint32_t)(x))<<CMPU_CSR_DEN_SHIFT))&CMPU_CSR_DEN_MASK)
#define CMPU_CSR_DEN_GET(x)         (((uint32_t)(((uint32_t)(x))&CMPU_CSR_DEN_MASK))>>CMPU_CSR_DEN_SHIFT)
#define CMPU_CSR_TIDCTL_MASK        0x00000008u
#define CMPU_CSR_TIDCTL_SHIFT       3u
#define CMPU_CSR_TIDCTL(x)          (((uint32_t)(((uint32_t)(x))<<CMPU_CSR_TIDCTL_SHIFT))&CMPU_CSR_TIDCTL_MASK)
#define CMPU_CSR_TIDCTL_GET(x)      (((uint32_t)(((uint32_t)(x))&CMPU_CSR_TIDCTL_MASK))>>CMPU_CSR_TIDCTL_SHIFT)
#define CMPU_CSR_MPUFI_MASK         0x00000002u
#define CMPU_CSR_MPUFI_SHIFT        1u
#define CMPU_CSR_MPUFI(x)           (((uint32_t)(((uint32_t)(x))<<CMPU_CSR_MPUFI_SHIFT))&CMPU_CSR_MPUFI_MASK)/*PRQA S 3471*/
#define CMPU_CSR_MPUFI_GET(x)       (((uint32_t)(((uint32_t)(x))&CMPU_CSR_MPUFI_MASK))>>CMPU_CSR_MPUFI_SHIFT)
#define CMPU_CSR_MPUEN_MASK         0x00000001u
#define CMPU_CSR_MPUEN_SHIFT        0u
#define CMPU_CSR_MPUEN(x)           (((uint32_t)(((uint32_t)(x))<<CMPU_CSR_MPUEN_SHIFT))&CMPU_CSR_MPUEN_MASK)
#define CMPU_CSR_MPUEN_GET(x)       (((uint32_t)(((uint32_t)(x))&CMPU_CSR_MPUEN_MASK))>>CMPU_CSR_MPUEN_SHIFT)

/* MAS0 Bit Fields */
#define CMPU_MAS0_VALID_MASK        0x80000000u
#define CMPU_MAS0_VALID_SHIFT       31u
#define CMPU_MAS0_VALID(x)          (((uint32_t)(((uint32_t)(x))<<CMPU_MAS0_VALID_SHIFT))&CMPU_MAS0_VALID_MASK)
#define CMPU_MAS0_VALID_GET(x)      (((uint32_t)(((uint32_t)(x))&CMPU_MAS0_VALID_MASK))>>CMPU_MAS0_VALID_SHIFT)
#define CMPU_MAS0_IPROT_MASK        0x40000000u
#define CMPU_MAS0_IPROT_SHIFT       30u
#define CMPU_MAS0_IPROT(x)          (((uint32_t)(((uint32_t)(x))<<CMPU_MAS0_IPROT_SHIFT))&CMPU_MAS0_IPROT_MASK)
#define CMPU_MAS0_IPROT_GET(x)      (((uint32_t)(((uint32_t)(x))&CMPU_MAS0_IPROT_MASK))>>CMPU_MAS0_IPROT_SHIFT)
#define CMPU_MAS0_SEL_MASK          0x30000000u
#define CMPU_MAS0_SEL_SHIFT         28u
#define CMPU_MAS0_SEL(x)            (((uint32_t)(((uint32_t)(x))<<CMPU_MAS0_SEL_SHIFT))&CMPU_MAS0_SEL_MASK)
#define CMPU_MAS0_SEL_GET(x)        (((uint32_t)(((uint32_t)(x))&CMPU_MAS0_SEL_MASK))>>CMPU_MAS0_SEL_SHIFT)
#define CMPU_MAS0_RO_MASK           0x04000000u
#define CMPU_MAS0_RO_SHIFT          26u
#define CMPU_MAS0_RO(x)             (((uint32_t)(((uint32_t)(x))<<CMPU_MAS0_RO_SHIFT))&CMPU_MAS0_RO_MASK)
#define CMPU_MAS0_RO_GET(x)         (((uint32_t)(((uint32_t)(x))&CMPU_MAS0_RO_MASK))>>CMPU_MAS0_RO_SHIFT)
#define CMPU_MAS0_DEBUG_MASK        0x02000000u
#define CMPU_MAS0_DEBUG_SHIFT       25u
#define CMPU_MAS0_DEBUG(x)          (((uint32_t)(((uint32_t)(x))<<CMPU_MAS0_DEBUG_SHIFT))&CMPU_MAS0_DEBUG_MASK)
#define CMPU_MAS0_DEBUG_GET(x)      (((uint32_t)(((uint32_t)(x))&CMPU_MAS0_DEBUG_MASK))>>CMPU_MAS0_DEBUG_SHIFT)
#define CMPU_MAS0_INST_MASK         0x01000000u
#define CMPU_MAS0_INST_SHIFT        24u
#define CMPU_MAS0_INST(x)           (((uint32_t)(((uint32_t)(x))<<CMPU_MAS0_INST_SHIFT))&CMPU_MAS0_INST_MASK)
#define CMPU_MAS0_INST_GET(x)       (((uint32_t)(((uint32_t)(x))&CMPU_MAS0_INST_MASK))>>CMPU_MAS0_INST_SHIFT)
#define CMPU_MAS0_SHD_MASK          0x00800000u
#define CMPU_MAS0_SHD_SHIFT         23u
#define CMPU_MAS0_SHD(x)            (((uint32_t)(((uint32_t)(x))<<CMPU_MAS0_SHD_SHIFT))&CMPU_MAS0_SHD_MASK)
#define CMPU_MAS0_SHD_GET(x)        (((uint32_t)(((uint32_t)(x))&CMPU_MAS0_SHD_MASK))>>CMPU_MAS0_SHD_SHIFT)
#define CMPU_MAS0_ESEL_MASK         0x000F0000u
#define CMPU_MAS0_ESEL_SHIFT        16u
#define CMPU_MAS0_ESEL(x)           (((uint32_t)(((uint32_t)(x))<<CMPU_MAS0_ESEL_SHIFT))&CMPU_MAS0_ESEL_MASK)
#define CMPU_MAS0_ESEL_GET(x)       (((uint32_t)(((uint32_t)(x))&CMPU_MAS0_ESEL_MASK))>>CMPU_MAS0_ESEL_SHIFT)
#define CMPU_MAS0_UAMSK_MASK        0x00007000u
#define CMPU_MAS0_UAMSK_SHIFT       12u
#define CMPU_MAS0_UAMSK(x)          (((uint32_t)(((uint32_t)(x))<<CMPU_MAS0_UAMSK_SHIFT))&CMPU_MAS0_UAMSK_MASK)
#define CMPU_MAS0_UAMSK_GET(x)      (((uint32_t)(((uint32_t)(x))&CMPU_MAS0_UAMSK_MASK))>>CMPU_MAS0_UAMSK_SHIFT)
#define CMPU_MAS0_UW_MASK           0x00000800u
#define CMPU_MAS0_UW_SHIFT          11u
#define CMPU_MAS0_UW(x)             (((uint32_t)(((uint32_t)(x))<<CMPU_MAS0_UW_SHIFT))&CMPU_MAS0_UW_MASK)
#define CMPU_MAS0_UW_GET(x)         (((uint32_t)(((uint32_t)(x))&CMPU_MAS0_UW_MASK))>>CMPU_MAS0_UW_SHIFT)
#define CMPU_MAS0_SW_MASK           0x00000400u
#define CMPU_MAS0_SW_SHIFT          10u
#define CMPU_MAS0_SW(x)             (((uint32_t)(((uint32_t)(x))<<CMPU_MAS0_SW_SHIFT))&CMPU_MAS0_SW_MASK)
#define CMPU_MAS0_SW_GET(x)         (((uint32_t)(((uint32_t)(x))&CMPU_MAS0_SW_MASK))>>CMPU_MAS0_SW_SHIFT)
#define CMPU_MAS0_UXR_MASK          0x00000200u
#define CMPU_MAS0_UXR_SHIFT         9u
#define CMPU_MAS0_UXR(x)            (((uint32_t)(((uint32_t)(x))<<CMPU_MAS0_UXR_SHIFT))&CMPU_MAS0_UXR_MASK)
#define CMPU_MAS0_UXR_GET(x)        (((uint32_t)(((uint32_t)(x))&CMPU_MAS0_UXR_MASK))>>CMPU_MAS0_UXR_SHIFT)
#define CMPU_MAS0_SXR_MASK          0x00000100u
#define CMPU_MAS0_SXR_SHIFT         8u
#define CMPU_MAS0_SXR(x)            (((uint32_t)(((uint32_t)(x))<<CMPU_MAS0_SXR_SHIFT))&CMPU_MAS0_SXR_MASK)
#define CMPU_MAS0_SXR_GET(x)        (((uint32_t)(((uint32_t)(x))&CMPU_MAS0_SXR_MASK))>>CMPU_MAS0_SXR_SHIFT)
#define CMPU_MAS0_IOVR_MASK         0x00000080u
#define CMPU_MAS0_IOVR_SHIFT        7u
#define CMPU_MAS0_IOVR(x)           (((uint32_t)(((uint32_t)(x))<<CMPU_MAS0_IOVR_SHIFT))&CMPU_MAS0_IOVR_MASK)
#define CMPU_MAS0_IOVR_GET(x)       (((uint32_t)(((uint32_t)(x))&CMPU_MAS0_IOVR_MASK))>>CMPU_MAS0_IOVR_SHIFT)
#define CMPU_MAS0_GOVR_MASK         0x00000040u
#define CMPU_MAS0_GOVR_SHIFT        6u
#define CMPU_MAS0_GOVR(x)           (((uint32_t)(((uint32_t)(x))<<CMPU_MAS0_GOVR_SHIFT))&CMPU_MAS0_GOVR_MASK)
#define CMPU_MAS0_GOVR_GET(x)       (((uint32_t)(((uint32_t)(x))&CMPU_MAS0_GOVR_MASK))>>CMPU_MAS0_GOVR_SHIFT)
#define CMPU_MAS0_I_MASK            0x00000008u
#define CMPU_MAS0_I_SHIFT           3u
#define CMPU_MAS0_I(x)              (((uint32_t)(((uint32_t)(x))<<CMPU_MAS0_I_SHIFT))&CMPU_MAS0_I_MASK)
#define CMPU_MAS0_I_GET(x)          (((uint32_t)(((uint32_t)(x))&CMPU_MAS0_I_MASK))>>CMPU_MAS0_I_SHIFT)
#define CMPU_MAS0_G_MASK            0x00000002u
#define CMPU_MAS0_G_SHIFT           1u
#define CMPU_MAS0_G(x)              (((uint32_t)(((uint32_t)(x))<<CMPU_MAS0_G_SHIFT))&CMPU_MAS0_G_MASK)
#define CMPU_MAS0_G_GET(x)          (((uint32_t)(((uint32_t)(x))&CMPU_MAS0_G_MASK))>>CMPU_MAS0_G_SHIFT)

/* MAS1 Bit Fields */
#define CMPU_MAS1_TID_MASK          0x00FF0000u
#define CMPU_MAS1_TID_SHIFT         16u
#define CMPU_MAS1_TID(x)            (((uint32_t)(((uint32_t)(x))<<CMPU_MAS1_TID_SHIFT))&CMPU_MAS1_TID_MASK)
#define CMPU_MAS1_TID_GET(x)        (((uint32_t)(((uint32_t)(x))&CMPU_MAS1_TID_MASK))>>CMPU_MAS1_TID_SHIFT)
#define CMPU_MAS1_TIDMSK_MASK       0x000000FFu
#define CMPU_MAS1_TIDMSK_SHIFT      0u
#define CMPU_MAS1_TIDMSK(x)         (((uint32_t)(((uint32_t)(x))<<CMPU_MAS1_TIDMSK_SHIFT))&CMPU_MAS1_TIDMSK_MASK)
#define CMPU_MAS1_TIDMSK_GET(x)     (((uint32_t)(((uint32_t)(x))&CMPU_MAS1_TIDMSK_MASK))>>CMPU_MAS1_TIDMSK_SHIFT)

/* EMIOS module features */
/* @brief EMIOS support all modes for each channel. */
#define FEATURE_EMIOS_ALL_MODE_ON_CHANNEL
/* @brief EMIOS support Quadrature decode mode. */
#define FEATURE_EMIOS_QD_MODE_SUPPORT
/* @brief EMIOS has channel pair in the IRQ interrupt. */
#define FEATURE_EMIOS_CHANNELS_PER_IRQ          (1U)
/* @brief EMIOS number channels maximum. */
#define FEATURE_EMIOS_CHANNEL_MAX_COUNT         (32U)
/* @brief EMIOS channels and counter buses select. */
#define FEATURE_EMIOS_BUS_A_SELECT              (1U)
#define FEATURE_EMIOS_BUS_B_SELECT              (1U)
#define FEATURE_EMIOS_BUS_C_SELECT              (0U)
#define FEATURE_EMIOS_BUS_D_SELECT              (1U)
#define FEATURE_EMIOS_BUS_E_SELECT              (0U)
#define FEATURE_EMIOS_BUS_F_SELECT              (0U)
/* @brief EMIOS channels and counter buses offset. */
#define FEATURE_EMIOS_BUS_B_SELECT_OFFSET(x)    (x)
#define FEATURE_EMIOS_BUS_C_SELECT_OFFSET(x)    (x)
#define FEATURE_EMIOS_BUS_D_SELECT_OFFSET(x)    (x)
#define FEATURE_EMIOS_BUS_E_SELECT_OFFSET(x)    (x)
/* @brief EMIOS number of channels available. */
#define FEATURE_EMIOS_CH_7_0_ENABLE             (1U)
#define FEATURE_EMIOS_CH_15_8_ENABLE            (0U)
#define FEATURE_EMIOS_CH_23_16_ENABLE           (1U)
#define FEATURE_EMIOS_CH_31_24_ENABLE           (0U)
#define FEATURE_EMIOS_CH_COUNT                  ((FEATURE_EMIOS_CH_7_0_ENABLE   * 8U) + \
                                                 (FEATURE_EMIOS_CH_15_8_ENABLE  * 8U) + \
                                                 (FEATURE_EMIOS_CH_23_16_ENABLE * 8U) + \
                                                 (FEATURE_EMIOS_CH_31_24_ENABLE * 8U))
/* @brief EMIOS channels offset. */
#define FEATURE_EMIOS_CH_7_0_SUB_OFFSET(x)      (x)
#define FEATURE_EMIOS_CH_15_8_SUB_OFFSET(x)     (x)
#define FEATURE_EMIOS_CH_23_16_SUB_OFFSET(x)    (x - 8U)
#define FEATURE_EMIOS_CH_31_24_SUB_OFFSET(x)    (x)

/* PWM_PAL module features */
#define FEATURE_PWMPAL_EMIOS_HAS_CHANNEL_MAPPING    (1)
#define PWMPAL_INDEX_2_HW_CHANNELS {0,1,2,3,4,5,6,7,16,17,18,19,20,21,22,23}

/* SIUL2 MSCR IO */
#define PA0       0
#define PA1       1
#define PA2       2
#define PA3       3
#define PA4       4
#define PA5       5
#define PA6       6
#define PA7       7
#define PA8       8
#define PA9       9
#define PA10      10
#define PA11      11
#define PA12      12
#define PA13      13
#define PA14      14
#define PA15      15
#define PB0       16
#define PB1       17
#define PB2       18
#define PB3       19
#define PB4       20
#define PB5       21
#define PB6       22
#define PB7       23
#define PB8       24
#define PB9       25
#define PB10      26
#define PB11      27
#define PB12      28
#define PB13      29
#define PB14      30
#define PB15      31
#define PC0       32
#define PC1       33
#define PC2       34
#define PC3       35
#define PC4       36
#define PC5       37
#define PC6       38
#define PC7       39
#define PC8       40
#define PC9       41
#define PC10      42
#define PC11      43
#define PC12      44
#define PC13      45
#define PC14      46
#define PC15      47
#define PD0       48
#define PD1       49
#define PD2       50
#define PD3       51
#define PD4       52
#define PD5       53
#define PD6       54
#define PD7       55
#define PD8       56
#define PD9       57
#define PD10      58
#define PD11      59
#define PD12      60
#define PD13      61
#define PD14      62
#define PD15      63
#define PE0       64
#define PE1       65
#define PE2       66
#define PE3       67
#define PE4       68
#define PE5       69
#define PE6       70
#define PE7       71
#define PE8       72
#define PE9       73
#define PE10      74
#define PE11      75
#define PE12      76
#define PE13      77
#define PE14      78
#define PE15      79
#define PF0       80
#define PF1       81
#define PF2       82
#define PF3       83
#define PF4       84
#define PF5       85
#define PF6       86
#define PF7       87
#define PF8       88
#define PF9       89
#define PF10      90
#define PF11      91
#define PF12      92
#define PF13      93
#define PF14      94
#define PF15      95
#define PG0       96
#define PG1       97
#define PG2       98
#define PG3       99
#define PG4       100
#define PG5       101
#define PG6       102
#define PG7       103
#define PG8       104
#define PG9       105
#define PG10      106
#define PG11      107
#define PG12      108
#define PG13      109
#define PG14      110
#define PG15      111
#define PH0       112
#define PH1       113
#define PH2       114
#define PH3       115
#define PH4       116
#define PH5       117
#define PH6       118
#define PH7       119
#define PH8       120
#define PH9       121
#define PH10      122
#define PH11      123
#define PH12      124
#define PH13      125
#define PH14      126
#define PH15      127
#define PI0       128
#define PI1       129
#define PI2       130
#define PI3       131
#define PI4       132
#define PI5       133
#define PI6       134
#define PI7       135
#define PI8       136
#define PI9       137
#define PI10      138
#define PI11      139
#define PI12      140
#define PI13      141
#define PI14      142
#define PI15      143
#define PJ0       144
#define PJ1       145
#define PJ2       146
#define PJ3       147
#define PJ4       148
#define PJ5       149
#define PJ6       150
#define PJ7       151
#define PJ8       152
#define PJ9       153
#define PJ10      154
#define PJ11      155
#define PJ12      156
#define PJ13      157
#define PJ14      158
#define PJ15      159
#define PK0       160
#define PK1       161
#define PK2       162
#define PK3       163
#define PK4       164
#define PK5       165
#define PK6       166
#define PK7       167
#define PK8       168
#define PK9       169
#define PK10      170
#define PK11      171
#define PK12      172
#define PK13      173
#define PK14      174
#define PK15      175
#define PL0       176
#define PL1       177
#define PL2       178
#define PL3       179
#define PL4       180
#define PL5       181
#define PL6       182
#define PL7       183
#define PL8       184
#define PL9       185
#define PL10      186
#define PL11      187
#define PL12      188
#define PL13      189
#define PL14      190
#define PL15      191
#define PM0       192
#define PM1       193
#define PM2       194
#define PM3       195
#define PM4       196
#define PM5       197
#define PM6       198
#define PM7       199
#define PM8       200
#define PM9       201
#define PM10      202
#define PM11      203
#define PM12      204
#define PM13      205
#define PM14      206
#define PM15      207
#define PN0       208
#define PN1       209
#define PN2       210
#define PN3       211
#define PN4       212
#define PN5       213
#define PN6       214
#define PN7       215
#define PN8       216
#define PN9       217
#define PN10      218
#define PN11      219
#define PN12      220
#define PN13      221
#define PN14      222
#define PN15      223
#define PO0       224
#define PO1       225
#define PO2       226
#define PO3       227
#define PO4       228
#define PO5       229
#define PO6       230
#define PO7       231
#define PO8       232
#define PO9       233
#define PO10      234
#define PO11      235
#define PO12      236
#define PO13      237
#define PO14      238
#define PO15      239
#define PP0       240
#define PP1       241
#define PP2       242
#define PP3       243
#define PP4       244
#define PP5       245
#define PP6       246
#define PP7       247
#define PP8       248
#define PP9       249
#define PP10      250
#define PP11      251
#define PP12      252
#define PP13      253
#define PP14      254
#define PP15      255
#define PQ0       256
#define PQ1       257
#define PQ2       258
#define PQ3       259
#define PQ4       260
#define PQ5       261
#define PQ6       262
#define PQ7       263
#define PQ8       264
#define PQ9       265
#define PQ10      266
#define PQ11      267
#define PQ12      268
#define PQ13      269
#define PQ14      270
#define PQ15      271
#define PR0       272
#define PR1       273
#define PR2       274
#define PR3       275
#define PR4       276
#define PR5       277
#define PR6       278
#define PR7       279
#define PR8       280
#define PR9       281
#define PR10      282
#define PR11      283
#define PR12      284
#define PR13      285
#define PR14      286
#define PR15      287
#define PS0       288
#define PS1       289
#define PS2       290
#define PS3       291
#define PS4       292
#define PS5       293
#define PS6       294
#define PS7       295
#define PS8       296
#define PS9       297
#define PS10      298
#define PS11      299
#define PS12      300
#define PS13      301
#define PS14      302
#define PS15      303
#define PT0       304
#define PT1       305
#define PT2       306
#define PT3       307
#define PT4       308
#define PT5       309
#define PT6       310
#define PT7       311
#define PT8       312
#define PT9       313
#define PT10      314
#define PT11      315
#define PT12      316
#define PT13      317
#define PT14      318
#define PT15      319
#define PU0       320
#define PU1       321
#define PU2       322
#define PU3       323
#define PU4       324
#define PU5       325
#define PU6       326
#define PU7       327
#define PU8       328
#define PU9       329
#define PU10      330
#define PU11      331
#define PU12      332
#define PU13      333
#define PU14      334
#define PU15      335

/*
 * @brief EIRQ Pin definition
 */
#define EIRQ0           (0U)
#define EIRQ1           (1U)
#define EIRQ2           (2U)
#define EIRQ3           (3U)
#define EIRQ4           (4U)
#define EIRQ5           (5U)
#define EIRQ6           (6U)
#define EIRQ7           (7U)
#define EIRQ8           (8U)
#define EIRQ9           (9U)
#define EIRQ10          (10U)
#define EIRQ11          (11U)
#define EIRQ12          (12U)
#define EIRQ13          (13U)
#define EIRQ14          (14U)
#define EIRQ15          (15U)
#define EIRQ16          (16U)
#define EIRQ17          (17U)
#define EIRQ18          (18U)
#define EIRQ19          (19U)
#define EIRQ20          (20U)
#define EIRQ21          (21U)
#define EIRQ22          (22U)
#define EIRQ23          (23U)
#define EIRQ_MAX_NUM    (24U)

/* The SIUL2 EIRQ MUX index for EIRQ0 - EIRQ6 */
#define  EIRQ0_INDEX       (779U)
#define  EIRQ1_INDEX       (780U)
#define  EIRQ2_INDEX       (781U)
#define  EIRQ3_INDEX       (782U)
#define  EIRQ4_INDEX       (783U)
#define  EIRQ5_INDEX       (784U)
#define  EIRQ6_INDEX       (785U)


typedef struct
{
    uint8_t  eirq_index;
    uint32_t mux_index;
    uint32_t pad_mux;
    uint16_t eirq_pin;
} siul_eirq_info_t;

typedef enum
{
    INTR_PRI_0 = 0U,    /* Min priority */
    INTR_PRI_1 = 1U,
    INTR_PRI_2 = 2U,
    INTR_PRI_3 = 3U,
    INTR_PRI_4 = 4U,
    INTR_PRI_5 = 5U,
    INTR_PRI_6 = 6U,
    INTR_PRI_7 = 7U,
    INTR_PRI_8 = 8U,
    INTR_PRI_9 = 9U,
    INTR_PRI_10 = 10U,
    INTR_PRI_11 = 11U,
    INTR_PRI_12 = 12U,
    INTR_PRI_13 = 13U,
    INTR_PRI_14 = 14U,
    INTR_PRI_15 = 15U,
    INTR_PRI_16 = 16U,
    INTR_PRI_17 = 17U,
    INTR_PRI_18 = 18U,
    INTR_PRI_19 = 19U,
    INTR_PRI_20 = 20U,
    INTR_PRI_21 = 21U,
    INTR_PRI_22 = 22U,
    INTR_PRI_23 = 23U,
    INTR_PRI_24 = 24U,
    INTR_PRI_25 = 25U,
    INTR_PRI_26 = 26U,
    INTR_PRI_27 = 27U,
    INTR_PRI_28 = 28U,
    INTR_PRI_29 = 29U,
    INTR_PRI_30 = 30U,
    INTR_PRI_31 = 31U,
    INTR_PRI_32 = 32U,
    INTR_PRI_33 = 33U,
    INTR_PRI_34 = 34U,
    INTR_PRI_35 = 35U,
    INTR_PRI_36 = 36U,
    INTR_PRI_37 = 37U,
    INTR_PRI_38 = 38U,
    INTR_PRI_39 = 39U,
    INTR_PRI_40 = 40U,
    INTR_PRI_41 = 41U,
    INTR_PRI_42 = 42U,
    INTR_PRI_43 = 43U,
    INTR_PRI_44 = 44U,
    INTR_PRI_45 = 45U,
    INTR_PRI_46 = 46U,
    INTR_PRI_47 = 47U,
    INTR_PRI_48 = 48U,
    INTR_PRI_49 = 49U,
    INTR_PRI_50 = 50U,
    INTR_PRI_51 = 51U,
    INTR_PRI_52 = 52U,
    INTR_PRI_53 = 53U,
    INTR_PRI_54 = 54U,
    INTR_PRI_55 = 55U,
    INTR_PRI_56 = 56U,
    INTR_PRI_57 = 57U,
    INTR_PRI_58 = 58U,
    INTR_PRI_59 = 59U,
    INTR_PRI_60 = 60U,
    INTR_PRI_61 = 61U,
    INTR_PRI_62 = 62U,
    INTR_PRI_63 = 63U,
    INTR_PRI_BUTT
} IntrPrior;

/**
 * @brief Interrupt Source ID
 */
typedef enum
{
    NotAvail_IRQn               = -128, /**< Not available device specific interrupt */
    SOFT_SET_0_IRQn             = 0u,   /* Software setable flag 0 INTC_SSCIR0[CLR0] */
    SOFT_SET_1_IRQn             = 1u,   /* Software setable flag 1 INTC_SSCIR0[CLR1] */
    SOFT_SET_2_IRQn             = 2u,   /* Software setable flag 2 INTC_SSCIR0[CLR2] */
    SOFT_SET_3_IRQn             = 3u,   /* Software setable flag 3 INTC_SSCIR0[CLR3] */
    SOFT_SET_4_IRQn             = 4u,   /* Software setable flag 4 INTC_SSCIR0[CLR4] */
    SOFT_SET_5_IRQn             = 5u,   /* Software setable flag 5 INTC_SSCIR0[CLR5] */
    SOFT_SET_6_IRQn             = 6u,   /* Software setable flag 6 INTC_SSCIR0[CLR6] */
    SOFT_SET_7_IRQn             = 7u,   /* Software setable flag 7 INTC_SSCIR0[CLR7] */
    SOFT_SET_8_IRQn             = 8u,   /* Software setable flag 8 INTC_SSCIR0[CLR8] */
    SOFT_SET_9_IRQn             = 9u,   /* Software setable flag 9 INTC_SSCIR0[CLR9] */
    SOFT_SET_10_IRQn            = 10u,  /* Software setable flag 10 INTC_SSCIR0[CLR10] */
    SOFT_SET_11_IRQn            = 11u,  /* Software setable flag 11 INTC_SSCIR0[CLR11] */
    SOFT_SET_12_IRQn            = 12u,  /* Software setable flag 12 INTC_SSCIR0[CLR12] */
    SOFT_SET_13_IRQn            = 13u,  /* Software setable flag 13 INTC_SSCIR0[CLR13] */
    SOFT_SET_14_IRQn            = 14u,  /* Software setable flag 14 INTC_SSCIR0[CLR14] */
    SOFT_SET_15_IRQn            = 15u,  /* Software setable flag 15 INTC_SSCIR0[CLR15] */
    SOFT_SET_16_IRQn            = 16u,  /* Software setable flag 16 INTC_SSCIR0[CLR16] */
    SOFT_SET_17_IRQn            = 17u,  /* Software setable flag 17 INTC_SSCIR0[CLR17] */
    SOFT_SET_18_IRQn            = 18u,  /* Software setable flag 18 INTC_SSCIR0[CLR18] */
    SOFT_SET_19_IRQn            = 19u,  /* Software setable flag 19 INTC_SSCIR0[CLR19] */
    SOFT_SET_20_IRQn            = 20u,  /* Software setable flag 20 INTC_SSCIR0[CLR20] */
    SOFT_SET_21_IRQn            = 21u,  /* Software setable flag 21 INTC_SSCIR0[CLR21] */
    SOFT_SET_22_IRQn            = 22u,  /* Software setable flag 22 INTC_SSCIR0[CLR22] */
    SOFT_SET_23_IRQn            = 23u,  /* Software setable flag 23 INTC_SSCIR0[CLR23] */
    SOFT_SET_24_IRQn            = 24u,  /* Software setable flag 24 INTC_SSCIR0[CLR24] */
    SOFT_SET_25_IRQn            = 25u,  /* Software setable flag 25 INTC_SSCIR0[CLR25] */
    SOFT_SET_26_IRQn            = 26u,  /* Software setable flag 26 INTC_SSCIR0[CLR26] */
    SOFT_SET_27_IRQn            = 27u,  /* Software setable flag 27 INTC_SSCIR0[CLR27] */
    SOFT_SET_28_IRQn            = 28u,  /* Software setable flag 28 INTC_SSCIR0[CLR28] */
    SOFT_SET_29_IRQn            = 29u,  /* Software setable flag 29 INTC_SSCIR0[CLR29] */
    SOFT_SET_30_IRQn            = 30u,  /* Software setable flag 30 INTC_SSCIR0[CLR30] */
    SOFT_SET_31_IRQn            = 31u,  /* Software setable flag 31 INTC_SSCIR0[CLR31] */
    SWT0_IRQn                   = 32u,  /* Platform watchdog timer0 SWT_0_IR[TIF] */
    SWT1_IRQn                   = 33u,  /* Platform watchdog timer1 SWT_1_IR[TIF] */
    SWT2_IRQn                   = 34u,  /* Platform watchdog timer2 SWT_2_IR[TIF] */
    SWT3_IRQn                   = 35u,  /* Platform watchdog timer3 SWT_3_IR[TIF] */
    STM0_CH0_IRQn               = 36u,  /* Platform periodic timer 0_0 (STM) STM_0_CIR0[CIF] */
    STM0_CH1_IRQn               = 37u,  /* Platform periodic timer 0_1 (STM) STM_0_CIR1[CIF] */
    STM0_CH2_IRQn               = 38u,  /* Platform periodic timer 0_2 (STM) STM_0_CIR2[CIF] */
    STM0_CH3_IRQn               = 39u,  /* Platform periodic timer 0_3 (STM) STM_0_CIR3[CIF] */
    STM1_CH0_IRQn               = 40u,  /* Platform periodic timer 1_0 (STM) STM_1_CIR0[CIF] */
    STM1_CH1_IRQn               = 41u,  /* Platform periodic timer 1_1 (STM) STM_1_CIR1[CIF] */
    STM1_CH2_IRQn               = 42u,  /* Platform periodic timer 1_2 (STM) STM_1_CIR2[CIF] */
    STM1_CH3_IRQn               = 43u,  /* Platform periodic timer 1_3 (STM) STM_1_CIR3[CIF] */
    STM2_CH0_IRQn               = 44u,  /* Platform periodic timer 2_0 (STM) STM_2_CIR0[CIF] */
    STM2_CH1_IRQn               = 45u,  /* Platform periodic timer 2_1 (STM) STM_2_CIR1[CIF] */
    STM2_CH2_IRQn               = 46u,  /* Platform periodic timer 2_2 (STM) STM_2_CIR2[CIF] */
    STM2_CH3_IRQn               = 47u,  /* Platform periodic timer 2_3 (STM) STM_2_CIR3[CIF] */
    STM3_CH0_IRQn               = 48u,  /* Platform periodic timer 3_0 (STM) STM_3_CIR0[CIF] */
    STM3_CH1_IRQn               = 49u,  /* Platform periodic timer 3_1 (STM) STM_3_CIR1[CIF] */
    STM3_CH2_IRQn               = 50u,  /* Platform periodic timer 3_2 (STM) STM_3_CIR2[CIF] */
    STM3_CH3_IRQn               = 51u,  /* Platform periodic timer 3_3 (STM) STM_3_CIR3[CIF] */
    DMA0_ERR0_127_IRQn          = 52u,  /* eDMA Combined Error 127 - 0 eDMA Channel Error Flags */
    DMA0_CH0_IRQn               = 53u,  /* eDMA Channel 0 DMA_INTL[INT0] */
    DMA0_CH1_IRQn               = 54u,  /* eDMA Channel 1 DMA_INTL[INT1] */
    DMA0_CH2_IRQn               = 55u,  /* eDMA Channel 2 DMA_INTL[INT2] */
    DMA0_CH3_IRQn               = 56u,  /* eDMA Channel 3 DMA_INTL[INT3] */
    DMA0_CH4_IRQn               = 57u,  /* eDMA Channel 4 DMA_INTL[INT4] */
    DMA0_CH5_IRQn               = 58u,  /* eDMA Channel 5 DMA_INTL[INT5] */
    DMA0_CH6_IRQn               = 59u,  /* eDMA Channel 6 DMA_INTL[INT6] */
    DMA0_CH7_IRQn               = 60u,  /* eDMA Channel 7 DMA_INTL[INT7] */
    DMA0_CH8_IRQn               = 61u,  /* eDMA Channel 8 DMA_INTL[INT8] */
    DMA0_CH9_IRQn               = 62u,  /* eDMA Channel 9 DMA_INTL[INT9] */
    DMA0_CH10_IRQn              = 63u,  /* eDMA Channel 10 DMA_INTL[INT10] */
    DMA0_CH11_IRQn              = 64u,  /* eDMA Channel 11 DMA_INTL[INT11] */
    DMA0_CH12_IRQn              = 65u,  /* eDMA Channel 12 DMA_INTL[INT12] */
    DMA0_CH13_IRQn              = 66u,  /* eDMA Channel 13 DMA_INTL[INT13] */
    DMA0_CH14_IRQn              = 67u,  /* eDMA Channel 14 DMA_INTL[INT14] */
    DMA0_CH15_IRQn              = 68u,  /* eDMA Channel 15 DMA_INTL[INT15] */
    DMA0_CH16_IRQn              = 69u,  /* eDMA Channel 16 DMA_INTL[INT16] */
    DMA0_CH17_IRQn              = 70u,  /* eDMA Channel 17 DMA_INTL[INT17] */
    DMA0_CH18_IRQn              = 71u,  /* eDMA Channel 18 DMA_INTL[INT18] */
    DMA0_CH19_IRQn              = 72u,  /* eDMA Channel 19 DMA_INTL[INT19] */
    DMA0_CH20_IRQn              = 73u,  /* eDMA Channel 20 DMA_INTL[INT20] */
    DMA0_CH21_IRQn              = 74u,  /* eDMA Channel 21 DMA_INTL[INT21] */
    DMA0_CH22_IRQn              = 75u,  /* eDMA Channel 22 DMA_INTL[INT22] */
    DMA0_CH23_IRQn              = 76u,  /* eDMA Channel 23 DMA_INTL[INT23] */
    DMA0_CH24_IRQn              = 77u,  /* eDMA Channel 24 DMA_INTL[INT24] */
    DMA0_CH25_IRQn              = 78u,  /* eDMA Channel 25 DMA_INTL[INT25] */
    DMA0_CH26_IRQn              = 79u,  /* eDMA Channel 26 DMA_INTL[INT26] */
    DMA0_CH27_IRQn              = 80u,  /* eDMA Channel 27 DMA_INTL[INT27] */
    DMA0_CH28_IRQn              = 81u,  /* eDMA Channel 28 DMA_INTL[INT28] */
    DMA0_CH29_IRQn              = 82u,  /* eDMA Channel 29 DMA_INTL[INT29] */
    DMA0_CH30_IRQn              = 83u,  /* eDMA Channel 30 DMA_INTL[INT30] */
    DMA0_CH31_IRQn              = 84u,  /* eDMA Channel 31 DMA_INTL[INT31] */
    DMA0_CH32_IRQn              = 85u,  /* eDMA Channel 32 DMA_INTH[INT32] */
    DMA0_CH33_IRQn              = 86u,  /* eDMA Channel 33 DMA_INTH[INT33] */
    DMA0_CH34_IRQn              = 87u,  /* eDMA Channel 34 DMA_INTH[INT34] */
    DMA0_CH35_IRQn              = 88u,  /* eDMA Channel 35 DMA_INTH[INT35] */
    DMA0_CH36_IRQn              = 89u,  /* eDMA Channel 36 DMA_INTH[INT36] */
    DMA0_CH37_IRQn              = 90u,  /* eDMA Channel 37 DMA_INTH[INT37] */
    DMA0_CH38_IRQn              = 91u,  /* eDMA Channel 38 DMA_INTH[INT38] */
    DMA0_CH39_IRQn              = 92u,  /* eDMA Channel 39 DMA_INTH[INT39] */
    DMA0_CH40_IRQn              = 93u,  /* eDMA Channel 40 DMA_INTH[INT40] */
    DMA0_CH41_IRQn              = 94u,  /* eDMA Channel 41 DMA_INTH[INT41] */
    DMA0_CH42_IRQn              = 95u,  /* eDMA Channel 42 DMA_INTH[INT42] */
    DMA0_CH43_IRQn              = 96u,  /* eDMA Channel 43 DMA_INTH[INT43] */
    DMA0_CH44_IRQn              = 97u,  /* eDMA Channel 44 DMA_INTH[INT44] */
    DMA0_CH45_IRQn              = 98u,  /* eDMA Channel 45 DMA_INTH[INT45] */
    DMA0_CH46_IRQn              = 99u,  /* eDMA Channel 46 DMA_INTH[INT46] */
    DMA0_CH47_IRQn              = 100u, /* eDMA Channel 47 DMA_INTH[INT47] */
    DMA0_CH48_IRQn              = 101u, /* eDMA Channel 48 DMA_INTH[INT48] */
    DMA0_CH49_IRQn              = 102u, /* eDMA Channel 49 DMA_INTH[INT49] */
    DMA0_CH50_IRQn              = 103u, /* eDMA Channel 50 DMA_INTH[INT50] */
    DMA0_CH51_IRQn              = 104u, /* eDMA Channel 51 DMA_INTH[INT51] */
    DMA0_CH52_IRQn              = 105u, /* eDMA Channel 52 DMA_INTH[INT52] */
    DMA0_CH53_IRQn              = 106u, /* eDMA Channel 53 DMA_INTH[INT53] */
    DMA0_CH54_IRQn              = 107u, /* eDMA Channel 54 DMA_INTH[INT54] */
    DMA0_CH55_IRQn              = 108u, /* eDMA Channel 55 DMA_INTH[INT55] */
    DMA0_CH56_IRQn              = 109u, /* eDMA Channel 56 DMA_INTH[INT56] */
    DMA0_CH57_IRQn              = 110u, /* eDMA Channel 57 DMA_INTH[INT57] */
    DMA0_CH58_IRQn              = 111u, /* eDMA Channel 58 DMA_INTH[INT58] */
    DMA0_CH59_IRQn              = 112u, /* eDMA Channel 59 DMA_INTH[INT59] */
    DMA0_CH60_IRQn              = 113u, /* eDMA Channel 60 DMA_INTH[INT60] */
    DMA0_CH61_IRQn              = 114u, /* eDMA Channel 61 DMA_INTH[INT61] */
    DMA0_CH62_IRQn              = 115u, /* eDMA Channel 62 DMA_INTH[INT62] */
    DMA0_CH63_IRQn              = 116u, /* eDMA Channel 63 DMA_INTH[INT63] */
    DMA1_CH0_IRQn               = 117u, /* eDMA Channel 64 DMA_INTH[INT64] */
    DMA1_CH1_IRQn               = 118u, /* eDMA Channel 65 DMA_INTH[INT65] */
    DMA1_CH2_IRQn               = 119u, /* eDMA Channel 66 DMA_INTH[INT66] */
    DMA1_CH3_IRQn               = 120u, /* eDMA Channel 67 DMA_INTH[INT67] */
    DMA1_CH4_IRQn               = 121u, /* eDMA Channel 68 DMA_INTH[INT68] */
    DMA1_CH5_IRQn               = 122u, /* eDMA Channel 69 DMA_INTH[INT69] */
    DMA1_CH6_IRQn               = 123u, /* eDMA Channel 70 DMA_INTH[INT70] */
    DMA1_CH7_IRQn               = 124u, /* eDMA Channel 71 DMA_INTH[INT71] */
    DMA1_CH8_IRQn               = 125u, /* eDMA Channel 72 DMA_INTH[INT72] */
    DMA1_CH9_IRQn               = 126u, /* eDMA Channel 73 DMA_INTH[INT73] */
    DMA1_CH10_IRQn              = 127u, /* eDMA Channel 74 DMA_INTH[INT74] */
    DMA1_CH11_IRQn              = 128u, /* eDMA Channel 75 DMA_INTH[INT75] */
    DMA1_CH12_IRQn              = 129u, /* eDMA Channel 76 DMA_INTH[INT76] */
    DMA1_CH13_IRQn              = 130u, /* eDMA Channel 77 DMA_INTH[INT77] */
    DMA1_CH14_IRQn              = 131u, /* eDMA Channel 78 DMA_INTH[INT78] */
    DMA1_CH15_IRQn              = 132u, /* eDMA Channel 79 DMA_INTH[INT79] */
    DMA1_CH16_IRQn              = 133u, /* eDMA Channel 80 DMA_INTH[INT80] */
    DMA1_CH17_IRQn              = 134u, /* eDMA Channel 81 DMA_INTH[INT81] */
    DMA1_CH18_IRQn              = 135u, /* eDMA Channel 82 DMA_INTH[INT82] */
    DMA1_CH19_IRQn              = 136u, /* eDMA Channel 83 DMA_INTH[INT83] */
    DMA1_CH20_IRQn              = 137u, /* eDMA Channel 84 DMA_INTH[INT84] */
    DMA1_CH21_IRQn              = 138u, /* eDMA Channel 85 DMA_INTH[INT85] */
    DMA1_CH22_IRQn              = 139u, /* eDMA Channel 86 DMA_INTH[INT86] */
    DMA1_CH23_IRQn              = 140u, /* eDMA Channel 87 DMA_INTH[INT87] */
    DMA1_CH24_IRQn              = 141u, /* eDMA Channel 88 DMA_INTH[INT88] */
    DMA1_CH25_IRQn              = 142u, /* eDMA Channel 89 DMA_INTH[INT89] */
    DMA1_CH26_IRQn              = 143u, /* eDMA Channel 90 DMA_INTH[INT90] */
    DMA1_CH27_IRQn              = 144u, /* eDMA Channel 91 DMA_INTH[INT91] */
    DMA1_CH28_IRQn              = 145u, /* eDMA Channel 92 DMA_INTH[INT92] */
    DMA1_CH29_IRQn              = 146u, /* eDMA Channel 93 DMA_INTH[INT93] */
    DMA1_CH30_IRQn              = 147u, /* eDMA Channel 94 DMA_INTH[INT94] */
    DMA1_CH31_IRQn              = 148u, /* eDMA Channel 95 DMA_INTH[INT95] */
    DMA1_CH32_IRQn              = 149u, /* eDMA Channel 96 DMA_INTH[INT96] */
    DMA1_CH33_IRQn              = 150u, /* eDMA Channel 97 DMA_INTH[INT97] */
    DMA1_CH34_IRQn              = 151u, /* eDMA Channel 98 DMA_INTH[INT98] */
    DMA1_CH35_IRQn              = 152u, /* eDMA Channel 99 DMA_INTH[INT99] */
    DMA1_CH36_IRQn              = 153u, /* eDMA Channel 100 DMA_INTH[INT100] */
    DMA1_CH37_IRQn              = 154u, /* eDMA Channel 101 DMA_INTH[INT101] */
    DMA1_CH38_IRQn              = 155u, /* eDMA Channel 102 DMA_INTH[INT102] */
    DMA1_CH39_IRQn              = 156u, /* eDMA Channel 103 DMA_INTH[INT103] */
    DMA1_CH40_IRQn              = 157u, /* eDMA Channel 104 DMA_INTH[INT104] */
    DMA1_CH41_IRQn              = 158u, /* eDMA Channel 105 DMA_INTH[INT105] */
    DMA1_CH42_IRQn              = 159u, /* eDMA Channel 106 DMA_INTH[INT106] */
    DMA1_CH43_IRQn              = 160u, /* eDMA Channel 107 DMA_INTH[INT107] */
    DMA1_CH44_IRQn              = 161u, /* eDMA Channel 108 DMA_INTH[INT108] */
    DMA1_CH45_IRQn              = 162u, /* eDMA Channel 109 DMA_INTH[INT109] */
    DMA1_CH46_IRQn              = 163u, /* eDMA Channel 110 DMA_INTH[INT110] */
    DMA1_CH47_IRQn              = 164u, /* eDMA Channel 111 DMA_INTH[INT111] */
    DMA1_CH48_IRQn              = 165u, /* eDMA Channel 112 DMA_INTH[INT112] */
    DMA1_CH49_IRQn              = 166u, /* eDMA Channel 113 DMA_INTH[INT113] */
    DMA1_CH50_IRQn              = 167u, /* eDMA Channel 114 DMA_INTH[INT114] */
    DMA1_CH51_IRQn              = 168u, /* eDMA Channel 115 DMA_INTH[INT115] */
    DMA1_CH52_IRQn              = 169u, /* eDMA Channel 116 DMA_INTH[INT116] */
    DMA1_CH53_IRQn              = 170u, /* eDMA Channel 117 DMA_INTH[INT117] */
    DMA1_CH54_IRQn              = 171u, /* eDMA Channel 118 DMA_INTH[INT118] */
    DMA1_CH55_IRQn              = 172u, /* eDMA Channel 119 DMA_INTH[INT119] */
    DMA1_CH56_IRQn              = 173u, /* eDMA Channel 120 DMA_INTH[INT120] */
    DMA1_CH57_IRQn              = 174u, /* eDMA Channel 121 DMA_INTH[INT121] */
    DMA1_CH58_IRQn              = 175u, /* eDMA Channel 122 DMA_INTH[INT122] */
    DMA1_CH59_IRQn              = 176u, /* eDMA Channel 123 DMA_INTH[INT123] */
    DMA1_CH60_IRQn              = 177u, /* eDMA Channel 124 DMA_INTH[INT124] */
    DMA1_CH61_IRQn              = 178u, /* eDMA Channel 125 DMA_INTH[INT125] */
    DMA1_CH62_IRQn              = 179u, /* eDMA Channel 126 DMA_INTH[INT126] */
    DMA1_CH63_IRQn              = 180u, /* eDMA Channel 127 DMA_INTH[INT127] */
    STM4_CH0_IRQn               = 181u, /* Platform periodic timer 4_0 (STM) STM_4_CIR0[CIF] */
    STM4_CH1_IRQn               = 182u, /* Platform periodic timer 4_1 (STM) STM_4_CIR1[CIF] */
    STM4_CH2_IRQn               = 183u, /* Platform periodic timer 4_2 (STM) STM_4_CIR2[CIF] */
    STM4_CH3_IRQn               = 184u, /* Platform periodic timer 4_3 (STM) STM_4_CIR3[CIF] */
    FLASH_MCR_DONE_IRQn         = 185u, /* Flash controller Prog/Erase/Suspend IRQ_0 MCR[DONE] */
    STM5_CH0_IRQn               = 186u, /* Platform periodic timer 5_0 (STM) STM_5_CIR0[CIF] */
    STM5_CH1_IRQn               = 187u, /* Platform periodic timer 5_1 (STM) STM_5_CIR1[CIF] */
    STM5_CH2_IRQn               = 188u, /* Platform periodic timer 5_2 (STM) STM_5_CIR2[CIF] */
    
    STM5_CH3_IRQn               = 195u, /* Platform periodic timer 5_3 (STM) STM_5_CIR3[CIF] */

    CSENT0_RX_ERR_IRQn          = 197u, /* CSENT0 Rx Error Interrupt */
    CSENT0_RX_VALID_IRQn        = 198u, /* CSENT0 Rx Valid Interrupt */
    CSENT0_TX_ACTIVE_IRQn       = 199u, /* CSENT0 Tx Active Interrupt */
    CSENT0_TX_DONE_IRQn         = 200u, /* CSENT0 Tx Done Interrupt */

    FEC_PMT_IRQn                = 205u, /* PMT Interrupt */
    FEC_LPI_IRQn                = 206u, /* LPI Interrupt */
    FEC_SBD_PERCH_RX_0_IRQn     = 207u, /* Channel 0 Receive Interrupt Signal to the Host System */
    FEC_SBD_PERCH_RX_1_IRQn     = 208u, /* Channel 1 Receive Interrupt Signal to the Host System */
    FEC_SBD_PERCH_RX_2_IRQn     = 209u, /* Channel 2 Receive Interrupt Signal to the Host System */
    FEC_SBD_PERCH_RX_3_IRQn     = 210u, /* Channel 3 Receive Interrupt Signal to the Host System */
    FEC_SBD_PERCH_TX_0_IRQn     = 211u, /* Channel 0 Transmit Interrupt Signal to the Host System */
    FEC_SBD_PERCH_TX_1_IRQn     = 212u, /* Channel 1 Transmit Interrupt Signal to the Host System */
    FEC_SBD_PERCH_TX_2_IRQn     = 213u, /* Channel 2 Transmit Interrupt Signal to the Host System */
    FEC_SBD_PERCH_TX_3_IRQn     = 214u, /* Channel 3 Transmit Interrupt Signal to the Host System */
    FEC_SBD_SFTY_UE_IRQn        = 215u, /* Uncorrectable Safety Interrupt */
    FEC_SBD_SFTY_CE_IRQn        = 216u, /* Correctable Safety Interrupt */ 
    FEC_SBD_INTR_IRQn           = 217u, /* Subsystem Interrupt */
    SWT6_IRQn                   = 218u, /* Platform watchdog timer6 SWT_6_IR[TIF] */
    SWT5_IRQn                   = 219u, /* Platform watchdog timer5 SWT_5_IR[TIF] */
    SWT4_IRQn                   = 220u, /* Platform watchdog timer4 SWT_4_IR[TIF] */
    WKPU_WISR1_16_23_IRQn       = 221u, /* WISR1: EIF16~23 */
    WKPU_WISR1_24_31_IRQn       = 222u, /* WISR1: EIF24~31 */
    SDADC_10_IRQn               = 223u, /* SDADC 10 Interrupt */
    CANFD9_IRQn                 = 224u, /* CANFD9 Interrupt */
    GTM_TOM5_7_IRQn             = 225u, /* GTM_TOM5_IRQ[7] gtm_icm.gtm_tom5_irq[7] */
    PIT_0_TFLG0_IRQn            = 226u, /* Periodic Interrupt Timer (PIT0) PIT_0_TFLG0[TIF] */
    PIT_0_TFLG1_IRQn            = 227u, /* Periodic Interrupt Timer (PIT1) PIT_0_TFLG1[TIF] */
    PIT_0_TFLG2_IRQn            = 228u, /* Periodic Interrupt Timer (PIT2) PIT_0_TFLG2[TIF] */
    PIT_0_TFLG3_IRQn            = 229u, /* Periodic Interrupt Timer (PIT3) PIT_0_TFLG3[TIF] */
    PIT_0_TFLG4_IRQn            = 230u, /* Periodic Interrupt Timer (PIT4) PIT_0_TFLG4[TIF] */
    PIT_0_TFLG5_IRQn            = 231u, /* Periodic Interrupt Timer (PIT5) PIT_0_TFLG5[TIF] */
    PIT_0_TFLG6_IRQn            = 232u, /* Periodic Interrupt Timer (PIT6) PIT_0_TFLG6[TIF] */
    PIT_0_TFLG7_IRQn            = 233u, /* Periodic Interrupt Timer (PIT7) PIT_0_TFLG7[TIF] */
    GTM_TOM5_6_IRQn             = 234u, /* GTM_TOM5_IRQ[6] gtm_icm.gtm_tom5_irq[6] */
    GTM_TOM5_5_IRQn             = 235u, /* GTM_TOM5_IRQ[5] gtm_icm.gtm_tom5_irq[5] */
    SPORT_INTR_FS_IRQn          = 236u, /* SPORT_INTR_FS */
    SPORT_INTR_ERR_IRQn         = 237u, /* SPORT_INTR_ERR */
    SPORT_INTR_DMA_IRQn         = 238u, /* SPORT_INTR_DMA */
    PIT_0_RTI_TFLG_IRQn         = 239u, /* PIT_RTI PIT_0_RTI_TFLG[TIF] */
    PIT_1_TFLG0_IRQn            = 240u, /* PIT_64_Upper PIT_1_TFLG0[TIF] */
    PIT_1_TFLG1_IRQn            = 241u, /* PIT_64_Lower PIT_1_TFLG1[TIF] */
    XOSC_COUNTER_IRQn           = 242u, /* XOSC counter XOSC */
    GTM_TOM5_4_IRQn             = 243u, /* GTM_TOM5_IRQ[4] gtm_icm.gtm_tom5_irq[4] */
    GTM_TOM5_3_IRQn             = 244u, /* GTM_TOM5_IRQ[3] gtm_icm.gtm_tom5_irq[3] */
    ACMP0_IRQn                  = 245u, /* ACMP0 Interrupt */
    ACMP1_IRQn                  = 246u, /* ACMP1 Interrupt */
    ACMP2_IRQn                  = 247u, /* ACMP2 Interrupt */
    ACMP3_IRQn                  = 248u, /* ACMP3 Interrupt */
    ACMP4_IRQn                  = 249u, /* ACMP4 Interrupt */
    ACMP5_IRQn                  = 250u, /* ACMP5 Interrupt */
    MC_ME_0_IRQn                = 251u, /* MC_ME 0 ME_IS[I_SAFE] */
    MC_ME_1_IRQn                = 252u, /* MC_ME 1 ME_IS[I_MTC] */
    MC_ME_2_IRQn                = 253u, /* MC_ME 2 ME_IS[I_IMODE] */
    MC_ME_3_IRQn                = 254u, /* MC_ME 3 ME_IS[I_ICONF] | ME_IS[I_ICONF_CC] | ME_IS[I_ICONF_CU] */
    MC_RGM_0_IRQn               = 255u, /* MC_RGM 0 MC_RGM Functional and destructive reset alternate event interrupt */
    ACMP6_IRQn                  = 256u, /* ACMP6 Interrupt */
    ACMP7_IRQn                  = 257u, /* ACMP7 Interrupt */
    DAC0_IRQn                   = 258u, /* DAC0 Interrupt */
    DSPI0_ERR_IRQn              = 259u, /* DSPI0_0 DSPI_0_SR[TFUF] | DSPI_0_SR[RFOF] | DSPI_0_SR[TFIWF] */
    DSPI0_EOQF_IRQn             = 260u, /* DSPI0_1 DSPI_0_SR[EOQF] */
    DSPI0_TFFF_IRQn             = 261u, /* DSPI0_2 DSPI_0_SR[TFFF] */
    DSPI0_TCF_IRQn              = 262u, /* DSPI0_3 DSPI_0_SR[TCF] */
    DSPI0_RFDF_IRQn             = 263u, /* DSPI0_4 DSPI_0_SR[RFDF] */
    DSPI0_CMD_TCF_IRQn          = 264u, /* DSPI0_5 DSPI_0_SR[CMD_TCF] */
    DSPI0_CMDFFF_IRQn           = 265u, /* DSPI0_6 DSPI_0_SR[CMD_TFFF] */
    DSPI0_SPEF_IRQn             = 266u, /* DSPI0_7 DSPI_0_SR[SPEF] */
    DAC1_IRQn                   = 267u, /* DAC1 Interrupt */
    DSPI1_ERR_IRQn              = 268u, /* DSPI1_0 DSPI_1_SR[TFUF] | DSPI_1_SR[RFOF] | DSPI_1_SR[TFIWF] */
    DSPI1_EOQF_IRQn             = 269u, /* DSPI1_1 DSPI_1_SR[EOQF] */
    DSPI1_TFFF_IRQn             = 270u, /* DSPI1_2 DSPI_1_SR[TFFF] */
    DSPI1_TCF_IRQn              = 271u, /* DSPI1_3 DSPI_1_SR[TCF] */
    DSPI1_RFDF_IRQn             = 272u, /* DSPI1_4 DSPI_1_SR[RFDF] */
    DSPI1_CMD_TCF_IRQn          = 273u, /* DSPI1_5 DSPI_1_SR[CMD_TCF] */
    DSPI1_CMDFFF_IRQn           = 274u, /* DSPI1_6 DSPI_1_SR[CMD_TFFF] */
    DSPI1_SPEF_IRQn             = 275u, /* DSPI1_7 DSPI_1_SR[SPEF] */
    GTM_TOM5_2_IRQn             = 276u, /* GTM_TOM5_IRQ[2] gtm_icm.gtm_tom5_irq[2] */
    DSPI2_ERR_IRQn              = 277u, /* DSPI2_0 DSPI_2_SR[TFUF] | DSPI_2_SR[RFOF] | DSPI_2_SR[TFIWF] */
    DSPI2_EOQF_IRQn             = 278u, /* DSPI2_1 DSPI_2_SR[EOQF] */
    DSPI2_TFFF_IRQn             = 279u, /* DSPI2_2 DSPI_2_SR[TFFF] */
    DSPI2_TCF_IRQn              = 280u, /* DSPI2_3 DSPI_2_SR[TCF] */
    DSPI2_RFDF_IRQn             = 281u, /* DSPI2_4 DSPI_2_SR[RFDF] */
    DSPI2_CMD_TCF_IRQn          = 282u, /* DSPI2_5 DSPI_2_SR[CMD_TCF] */
    DSPI2_CMDFFF_IRQn           = 283u, /* DSPI2_6 DSPI_2_SR[CMD_TFFF] */
    DSPI2_SPEF_IRQn             = 284u, /* DSPI2_7 DSPI_2_SR[SPEF] */
    GTM_TOM5_1_IRQn             = 285u, /* GTM_TOM5_IRQ[1] gtm_icm.gtm_tom5_irq[1] */
    DSPI3_ERR_IRQn              = 286u, /* DSPI3_0 DSPI_3_SR[TFUF] | DSPI_3_SR[RFOF] | DSPI_3_SR[TFIWF] */
    DSPI3_EOQF_IRQn             = 287u, /* DSPI3_1 DSPI_3_SR[EOQF] */
    DSPI3_TFFF_IRQn             = 288u, /* DSPI3_2 DSPI_3_SR[TFFF] */
    DSPI3_TCF_IRQn              = 289u, /* DSPI3_3 DSPI_3_SR[TCF] */
    DSPI3_RFDF_IRQn             = 290u, /* DSPI3_4 DSPI_3_SR[RFDF] */
    DSPI3_CMD_TCF_IRQn          = 291u, /* DSPI3_5 DSPI_3_SR[CMD_TCF] */
    DSPI3_CMDFFF_IRQn           = 292u, /* DSPI3_6 DSPI_3_SR[CMD_TFFF] */
    DSPI3_SPEF_IRQn             = 293u, /* DSPI3_7 DSPI_3_SR[SPEF] */
    GTM_TOM5_0_IRQn             = 294u, /* GTM_TOM5_IRQ[0] gtm_icm.gtm_tom5_irq[0] */
    DSPI4_ERR_IRQn              = 295u, /* DSPI4_0 DSPI_4_SR[TFUF] | DSPI_4_SR[RFOF] | DSPI_4_SR[TFIWF] */
    DSPI4_EOQF_IRQn             = 296u, /* DSPI4_1 DSPI_4_SR[EOQF] */
    DSPI4_TFFF_IRQn             = 297u, /* DSPI4_2 DSPI_4_SR[TFFF] */
    DSPI4_TCF_IRQn              = 298u, /* DSPI4_3 DSPI_4_SR[TCF] */
    DSPI4_RFDF_IRQn             = 299u, /* DSPI4_4 DSPI_4_SR[RFDF] */
    DSPI4_SPITCF_CMD_TCF_IRQn   = 300u, /* DSPI4_5 DSPI_4_SR[SPITCF] | DSPI_4_SR[CMD_TCF] */
    DSPI4_DSITCF_CMDFFF_IRQn    = 301u, /* DSPI4_6 DSPI_4_SR[DSITCF] | DSPI_4_SR[CMD_TFFF] */
    DSPI4_SPEF_DPEF_IRQn        = 302u, /* DSPI4_7 DSPI_4_SR[SPEF] | DSPI_4_SR[DPEF] */
    DSPI4_DDIF_IRQn             = 303u, /* DSPI4_8 DSPI_4_SR[DDIF] */
    DSPI5_ERR_IRQn              = 304u, /* DSPI5_0 DSPI_5_SR[TFUF] | DSPI_5_SR[RFOF] | DSPI_5_SR[TFIWF] */
    DSPI5_EOQF_IRQn             = 305u, /* DSPI5_1 DSPI_5_SR[EOQF] */
    DSPI5_TFFF_IRQn             = 306u, /* DSPI5_2 DSPI_5_SR[TFFF] */
    DSPI5_TCF_IRQn              = 307u, /* DSPI5_3 DSPI_5_SR[TCF] */
    DSPI5_RFDF_IRQn             = 308u, /* DSPI5_4 DSPI_5_SR[RFDF] */
    DSPI5_SPITCF_CMD_TCF_IRQn   = 309u, /* DSPI5_5 DSPI_5_SR[SPITCF] | DSPI_5_SR[CMD_TCF] */
    DSPI5_DSITCF_CMDFFF_IRQn    = 310u, /* DSPI5_6 DSPI_5_SR[DSITCF] | DSPI_5_SR[CMDFFF] */
    DSPI5_SPEF_DPEF_IRQn        = 311u, /* DSPI5_7 DSPI_5_SR[SPEF] | DSPI_5_SR[DPEF] */
    DSPI5_DDIF_IRQn             = 312u, /* DSPI5_8 DSPI_5_SR[DDIF] */
    DSPI6_ERR_IRQn              = 313u, /* DSPI6_0 DSPI_6_SR[TFUF] | DSPI_6_SR[RFOF] | DSPI_6_SR[TFIWF]*/
    DSPI6_EOQF_IRQn             = 314u, /* DSPI6_1 DSPI_6_SR[EOQF] */
    DSPI6_TFFF_IRQn             = 315u, /* DSPI6_2 DSPI_6_SR[TFFF] */
    DSPI6_TCF_IRQn              = 316u, /* DSPI6_3 DSPI_6_SR[TCF] */
    DSPI6_RFDF_IRQn             = 317u, /* DSPI6_4 DSPI_6_SR[RFDF] */
    DSPI6_SPITCF_CMD_TCF_IRQn   = 318u, /* DSPI6_5 DSPI_6_SR[SPITCF] | DSPI_6_SR[CMD_TCF] */
    DSPI6_DSITCF_CMDFFF_IRQn    = 319u, /* DSPI6_6 DSPI_6_SR[DSITCF] | DSPI_6_SR[CMDFFF] */
    DSPI6_SPEF_DPEF_IRQn        = 320u, /* DSPI6_7 DSPI_6_SR[SPEF] | DSPI_6_SR[DPEF] */
    DSPI6_DDIF_IRQn             = 321u, /* DSPI6_8 DSPI_6_SR[DDIF] */
    GTM_TIM7_7_IRQn             = 322u, /* GTM_TIM7_IRQ[7] gtm_icm.gtm_tim7_irq[7] */
    EQADC1213_FIFO_0_IRQn       = 323u, /* EQADC1213_FISR0 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC1213_FIFO_1_IRQn       = 324u, /* EQADC1213_FISR1 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC1213_FIFO_2_IRQn       = 325u, /* EQADC1213_FISR2 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC1213_FIFO_3_IRQn       = 326u, /* EQADC1213_FISR3 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC1213_FIFO_4_IRQn       = 327u, /* EQADC1213_FISR4 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC1213_FIFO_5_IRQn       = 328u, /* EQADC1213_FISR5 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC1011_FIFO_0_IRQn       = 329u, /* EQADC1011_FISR0 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC1011_FIFO_1_IRQn       = 330u, /* EQADC1011_FISR1 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC1011_FIFO_2_IRQn       = 331u, /* EQADC1011_FISR2 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC1011_FIFO_3_IRQn       = 332u, /* EQADC1011_FISR3 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC1011_FIFO_4_IRQn       = 333u, /* EQADC1011_FISR4 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC1011_FIFO_5_IRQn       = 334u, /* EQADC1011_FISR5 [NCF | PF | EOQF | CFFF | RFDF] */
    DSPI15_ERR_IRQn             = 335u, /* DSPI15_0 DSPI_15_SR[TFUF] | DSPI_15_SR[RFOF] | DSPI_15_SR[TFIWF] */
    DSPI15_EOQF_IRQn            = 336u, /* DSPI15_1 DSPI_15_SR[EOQF] */
    DSPI15_TFFF_IRQn            = 337u, /* DSPI15_2 DSPI_15_SR[TFFF] */
    DSPI15_TCF_IRQn             = 338u, /* DSPI15_3 DSPI_15_SR[TCF] */
    DSPI15_RFDF_IRQn            = 339u, /* DSPI15_4 DSPI_15_SR[RFDF] */
    DSPI15_CMD_TCF_IRQn         = 340u, /* DSPI15_5 DSPI_15_SR[CMD_TCF] */
    DSPI15_CMDFFF_IRQn          = 341u, /* DSPI15_6 DSPI_15_SR[CMD_TFFF] */
    DSPI15_SPEF_IRQn            = 342u, /* DSPI15_7 DSPI_15_SR[SPEF] */
    DSPI14_ERR_IRQn             = 343u, /* DSPI14_0 DSPI_14_SR[TFUF] | DSPI_14_SR[RFOF] | */
    DSPI14_EOQF_IRQn            = 344u, /* DSPI14_1 DSPI_14_SR[EOQF] */
    DSPI14_TFFF_IRQn            = 345u, /* DSPI14_2 DSPI_14_SR[TFFF] */
    DSPI14_TCF_IRQn             = 346u, /* DSPI14_3 DSPI_14_SR[TCF] */
    DSPI14_RFDF_IRQn            = 347u, /* DSPI14_4 DSPI_14_SR[RFDF] */
    DSPI14_CMD_TCF_IRQn         = 348u, /* DSPI14_5 DSPI_14_SR[CMD_TCF] */
    DSPI14_CMDFFF_IRQn          = 349u, /* DSPI14_6 DSPI_14_SR[CMD_TFFF] */
    DSPI14_SPEF_IRQn            = 350u, /* DSPI14_7 DSPI_14_SR[SPEF] */
    DSPI13_ERR_IRQn             = 351u, /* DSPI13_0 DSPI_13_SR[TFUF] | DSPI_13_SR[RFOF] | */
    DSPI13_EOQF_IRQn            = 352u, /* DSPI13_1 DSPI_13_SR[EOQF] */
    DSPI13_TFFF_IRQn            = 353u, /* DSPI13_2 DSPI_13_SR[TFFF] */
    DSPI13_TCF_IRQn             = 354u, /* DSPI13_3 DSPI_13_SR[TCF] */
    DSPI13_RFDF_IRQn            = 355u, /* DSPI13_4 DSPI_13_SR[RFDF] */
    DSPI13_CMD_TCF_IRQn         = 356u, /* DSPI13_5 DSPI_13_SR[CMD_TCF] */
    DSPI13_CMDFFF_IRQn          = 357u, /* DSPI13_6 DSPI_13_SR[CMD_TFFF] */
    DSPI13_SPEF_IRQn            = 358u, /* DSPI13_7 DSPI_13_SR[SPEF] */
    DSPI11_ERR_IRQn             = 359u, /* DSPI11_0 DSPI_11_SR[TFUF] | DSPI_11_SR[RFOF] | */
    DSPI11_EOQF_IRQn            = 360u, /* DSPI11_1 DSPI_11_SR[EOQF] */
    DSPI11_TFFF_IRQn            = 361u, /* DSPI11_2 DSPI_11_SR[TFFF] */
    DSPI11_TCF_IRQn             = 362u, /* DSPI11_3 DSPI_11_SR[TCF] */
    DSPI11_RFDF_IRQn            = 363u, /* DSPI11_4 DSPI_11_SR[RFDF] */
    DSPI11_CMD_TCF_IRQn         = 364u, /* DSPI11_5 DSPI_11_SR[CMD_TCF] */
    DSPI11_CMDFFF_IRQn          = 365u, /* DSPI11_6 DSPI_11_SR[CMD_TFFF] */
    DSPI11_SPEF_IRQn            = 366u, /* DSPI11_7 DSPI_11_SR[SPEF] */
    DSPI12_ERR_IRQn             = 367u, /* DSPI12_0 DSPI_12_SR[TFUF] | DSPI_12_SR[RFOF]| */
    DSPI12_EOQF_IRQn            = 368u, /* DSPI12_1 DSPI_12_SR[EOQF] */
    DSPI12_TFFF_IRQn            = 369u, /* DSPI12_2 DSPI_12_SR[TFFF] */
    DSPI12_TCF_IRQn             = 370u, /* DSPI12_3 DSPI_12_SR[TCF] */
    DSPI12_RFDF_IRQn            = 371u, /* DSPI12_4 DSPI_12_SR[RFDF] */
    DSPI12_CMD_TCF_IRQn         = 372u, /* DSPI12_5 DSPI_12_SR[CMD_TCF] */
    DSPI12_CMDFFF_IRQn          = 373u, /* DSPI12_6 DSPI_12_SR[CMD_TFFF] */
    DSPI12_SPEF_IRQn            = 374u, /* DSPI12_7 DSPI_12_SR[SPEF] */
    API_IRQn                    = 375U, /* RTC API Interrupt */
    LINFLEXD0_RX_IRQn           = 376u, /* Linflex/eSCI0_0 LINFlex_0_RXI */
    LINFLEXD0_TX_IRQn           = 377u, /* Linflex/eSCI0_1 LINFlex_0_TXI */
    LINFLEXD0_ERR_IRQn          = 378u, /* Linflex/eSCI0_2 LINFlex_0_ERR */
    GTM_TIM7_6_IRQn             = 379u, /* GTM_TIM7_IRQ[6] gtm_icm.gtm_tim7_irq[6] */
    LINFLEXD1_RX_IRQn           = 380u, /* Linflex/eSCI1_0 LINFlex_1_RXI */
    LINFLEXD1_TX_IRQn           = 381u, /* Linflex/eSCI1_1 LINFlex_1_TXI */
    LINFLEXD1_ERR_IRQn          = 382u, /* Linflex/eSCI1_2 LINFlex_1_ERR */
    GTM_TIM7_5_IRQn             = 383u, /* GTM_TIM7_IRQ[5] gtm_icm.gtm_tim7_irq[5] */
    LINFLEXD2_RX_IRQn           = 384u, /* Linflex/eSCI2_0 LINFlex_2_RXI */
    LINFLEXD2_TX_IRQn           = 385u, /* Linflex/eSCI2_1 LINFlex_2_TXI */
    LINFLEXD2_ERR_IRQn          = 386u, /* Linflex/eSCI2_2 LINFlex_2_ERR */
    GTM_TIM7_4_IRQn             = 387u, /* GTM_TIM7_IRQ[4] gtm_icm.gtm_tim7_irq[4] */
    GTM_TIM7_3_IRQn             = 388u, /* GTM_TIM7_IRQ[3] gtm_icm.gtm_tim7_irq[3] */
    GTM_TIM7_2_IRQn             = 389u, /* GTM_TIM7_IRQ[2] gtm_icm.gtm_tim7_irq[2] */
    DSPI10_ERR_IRQn             = 390u, /* DSPI10_0 DSPI_10_SR[TFUF] | DSPI_10_SR[RFOF] | DSPI_10_SR[TFIWF] */
    DSPI10_EOQF_IRQn            = 391u, /* DSPI10_1 DSPI_10_SR[EOQF] */
    DSPI10_TFFF_IRQn            = 392u, /* DSPI10_2 DSPI_10_SR[TFFF] */
    DSPI10_TCF_IRQn             = 393u, /* DSPI10_3 DSPI_10_SR[TCF] */
    DSPI10_RFDF_IRQn            = 394u, /* DSPI10_4 DSPI_10_SR[RFDF] */
    DSPI10_CMD_TCF_IRQn         = 395u, /* DSPI10_5 DSPI_10_SR[CMD_TCF] */
    DSPI10_CMDFFF_IRQn          = 396u, /* DSPI10_6 DSPI_10_SR[CMD_TFFF] */
    DSPI10_SPEF_IRQn            = 397u, /* DSPI10_7 DSPI_10_SR[SPEF] */
    DSPI9_ERR_IRQn              = 398u, /* DSPI9_0 DSPI_9_SR[TFUF] | DSPI_9_SR[RFOF] | DSPI_9_SR[TFIWF] */
    DSPI9_EOQF_IRQn             = 399u, /* DSPI9_1 DSPI_9_SR[EOQF] */
    DSPI9_TFFF_IRQn             = 400u, /* DSPI9_2 DSPI_9_SR[TFFF] */
    DSPI9_TCF_IRQn              = 401u, /* DSPI9_3 DSPI_9_SR[TCF] */
    DSPI9_RFDF_IRQn             = 402u, /* DSPI9_4 DSPI_9_SR[RFDF] */
    DSPI9_CMD_TCF_IRQn          = 403u, /* DSPI9_5 DSPI_9_SR[CMD_TCF] */
    DSPI9_CMDFFF_IRQn           = 404u, /* DSPI9_6 DSPI_9_SR[CMD_TFFF] */
    DSPI9_SPEF_IRQn             = 405u, /* DSPI9_7 DSPI_9_SR[SPEF] */
    DSPI8_ERR_IRQn              = 406u, /* DSPI8_0 DSPI_8_SR[TFUF] | DSPI_8_SR[RFOF] | DSPI_8_SR[TFIWF] */
    DSPI8_EOQF_IRQn             = 407u, /* DSPI8_1 DSPI_8_SR[EOQF] */
    DSPI8_TFFF_IRQn             = 408u, /* DSPI8_2 DSPI_8_SR[TFFF] */
    DSPI8_TCF_IRQn              = 409u, /* DSPI8_3 DSPI_8_SR[TCF] */
    DSPI8_RFDF_IRQn             = 410u, /* DSPI8_4 DSPI_8_SR[RFDF] */
    DSPI8_CMD_TCF_IRQn          = 411u, /* DSPI8_5 DSPI_8_SR[CMD_TCF] */
    DSPI8_CMDFFF_IRQn           = 412u, /* DSPI8_6 DSPI_8_SR[CMD_TFFF] */
    DSPI8_SPEF_IRQn             = 413u, /* DSPI8_7 DSPI_8_SR[SPEF] */
    DSPI7_ERR_IRQn              = 414u, /* DSPI7_0 DSPI_7_SR[TFUF] | DSPI_7_SR[RFOF] | DSPI_7_SR[TFIWF] */
    DSPI7_EOQF_IRQn             = 415u, /* DSPI7_1 DSPI_7_SR[EOQF] */
    LINFLEXD16_RX_IRQn          = 416u, /* Linflex/eSCI16_0 LINFlex_16_RXI */
    LINFLEXD16_TX_IRQn          = 417u, /* Linflex/eSCI16_1 LINFlex_16_TXI */
    LINFLEXD16_ERR_IRQn         = 418u, /* Linflex/eSCI16_2 LINFlex_16_ERR */
    DSPI7_TFFF_IRQn             = 419u, /* DSPI7_2 DSPI_7_SR[TFFF] */
    DSPI7_TCF_IRQn              = 420u, /* DSPI7_3 DSPI_7_SR[TCF] */
    DSPI7_RFDF_IRQn             = 421u, /* DSPI7_4 DSPI_7_SR[RFDF] */
    DSPI7_CMD_TCF_IRQn          = 422u, /* DSPI7_5 DSPI_7_SR[CMD_TCF] */
    DSPI7_CMDFFF_IRQn           = 423u, /* DSPI7_6 DSPI_7_SR[CMD_TFFF] */
    DSPI7_SPEF_IRQn             = 424u, /* DSPI7_7 DSPI_7_SR[SPEF] */
    WKPU_WISR1_0_7_IRQn         = 425u, /* WISR1: EIF0~7   */
    WKPU_WISR1_8_15_IRQn        = 426u, /* WISR1: EIF8~15  */
    WKPU_WISR0_0_7_IRQn         = 427u, /* WISR0: EIF0~7   */
    WKPU_WISR0_8_15_IRQn        = 428u, /* WISR0: EIF8~15  */
    WKPU_WISR0_16_23_IRQn       = 429u, /* WISR0: EIF16~23 */
    WKPU_WISR0_24_31_IRQn       = 430u, /* WISR0: EIF24~31 */
    CANFD1_IRQn                 = 431u, /* CANFD 1 Interrupt */
    LINFLEXD14_RX_IRQn          = 432u, /* Linflex/eSCI14_0 LINFlex_14_RXI */
    LINFLEXD14_TX_IRQn          = 433u, /* Linflex/eSCI14_1 LINFlex_14_TXI */
    LINFLEXD14_ERR_IRQn         = 434u, /* Linflex/eSCI14_2 LINFlex_14_ERR */
    LINFLEXD6_RX_IRQn           = 435u, /* Linflex/eSCI6_0 LINFlex_6_RXI */
    LINFLEXD15_RX_IRQn          = 436u, /* Linflex/eSCI15_0 LINFlex_15_RXI */
    LINFLEXD15_TX_IRQn          = 437u, /* Linflex/eSCI15_1 LINFlex_15_TXI */
    LINFLEXD15_ERR_IRQn         = 438u, /* Linflex/eSCI15_2 LINFlex_15_ERR */
    LINFLEXD6_TX_IRQn           = 439u, /* Linflex/eSCI6_1 LINFlex_6_TXI */
    IIC0_SR_IRQn                = 440u, /* IIC_0_0 I2C0_SR[IBAL] | I2C0_SR[TCF] | I2C0_SR[IAAS] */
    M_TTCAN2_TIME_MARK_IRQn     = 441u, /* TTCAN_RPT | TTCAN_INT0 | TTCAN_INT1 */
    IIC1_SR_IRQn                = 442u, /* IIC_1_0 I2C1_SR[IBAL] | I2C1_SR[TCF] | I2C1_SR[IAAS] */
    SDADC_11_IRQn               = 443u, /* SDADC 11 Interrupt */
    SDADC_12_IRQn               = 444u, /* SDADC 12 Interrupt */
    MCAN9_0_IRQn                = 445u, /* MCAN9 Interrupt Line 0 */
    MCAN9_1_IRQn                = 446u, /* MCAN9 Interrupt Line 1 */
    MCAN10_0_IRQn               = 447u, /* MCAN10 Interrupt Line 0 */
    MCAN10_1_IRQn               = 448u, /* MCAN10 Interrupt Line 1 */
    MCAN11_0_IRQn               = 449u, /* MCAN11 Interrupt Line 0 */
    MCAN11_1_IRQn               = 450u, /* MCAN11 Interrupt Line 1 */
    MCAN12_0_IRQn               = 451u, /* MCAN12 Interrupt Line 0 */
    MCAN12_1_IRQn               = 452u, /* MCAN12 Interrupt Line 1 */
    FLEXRAY0_0_IRQn             = 453u, /* FlexRay_0_0 FR_0_LRNEIF | DRNEIF */
    FLEXRAY0_1_IRQn             = 454u, /* FlexRay_0_1 FR_0_LRCEIF | DRCEIF */
    FLEXRAY0_2_IRQn             = 455u, /* FlexRay_0_2 FR_0_FNEAIF */
    FLEXRAY0_3_IRQn             = 456u, /* FlexRay_0_3 FR_0_FNEBIF */
    FLEXRAY0_4_IRQn             = 457u, /* FlexRay_0_4 FR_0_WUPIF */
    FLEXRAY0_5_IRQn             = 458u, /* FlexRay_0_5 FR_0_PRIF */
    FLEXRAY0_6_IRQn             = 459u, /* FlexRay_0_6 FR_0_CHIF */
    FLEXRAY0_7_IRQn             = 460u, /* FlexRay_0_7 FR_0_TBIF */
    FLEXRAY0_8_IRQn             = 461u, /* FlexRay_0_8 FR_0_RBIF */
    FLEXRAY0_9_IRQn             = 462u, /* FlexRay_0_9 FR_0_MIF */
    SSI0_IRQn                   = 463u, /* SSI0 Interrupt */
    SSI1_IRQn                   = 464u, /* SSI1 Interrupt */
    FLEXRAY1_0_IRQn             = 465u, /* FlexRay_1_0 FR_1_LRNEIF | DRNEIF */
    FLEXRAY1_1_IRQn             = 466u, /* FlexRay_1_1 FR_1_LRCEIF | DRCEIF */
    FLEXRAY1_2_IRQn             = 467u, /* FlexRay_1_2 FR_1_FNEAIF */
    FLEXRAY1_3_IRQn             = 468u, /* FlexRay_1_3 FR_1_FNEBIF */
    FLEXRAY1_4_IRQn             = 469u, /* FlexRay_1_4 FR_1_WUPIF */
    FLEXRAY1_5_IRQn             = 470u, /* FlexRay_1_5 FR_1_PRIF */
    FLEXRAY1_6_IRQn             = 471u, /* FlexRay_1_6 FR_1_CHIF */
    FLEXRAY1_7_IRQn             = 472u, /* FlexRay_1_7 FR_1_TBIF */
    FLEXRAY1_8_IRQn             = 473u, /* FlexRay_1_8 FR_1_RBIF */
    FLEXRAY1_9_IRQn             = 474u, /* FlexRay_1_9 FR_1_MIF */
    GTM_TIM7_1_IRQn             = 475u,  /* GTM_TIM7_IRQ[1] gtm_icm.gtm_tim7_irq[1] */
    GTM_TIM7_0_IRQn             = 476u,  /* GTM_TIM7_IRQ[0] gtm_icm.gtm_tim7_irq[0] */
    PMC_GR_S_IRQn               = 477u, /* Power Monitor Unit GR_S[VD15] | GR_S[VD14] | GR_S[VD13] | GR_S[VD12] | GR_S[VD10] | GR_S[VD9] GR_S[VD7] | GR_S[VD4] | GR_S[VD3] */
    PMC_ERP_TEMP_IRQn           = 478u, /* Power management Unit (temp sensor) EPR_TD[TEMP_3] | EPR_TD[TEMP_2] | EPR_TD[TEMP_0] */
    LINFLEXD3_RX_IRQn           = 479u, /* Linflex/eSCI3_0 LINFlex_3_RXI */
    LINFLEXD3_TX_IRQn           = 480u, /* Linflex/eSCI3_1 LINFlex_3_TXI */
    LINFLEXD3_ERR_IRQn          = 481u, /* Linflex/eSCI3_2 LINFlex_3_ERR */
    LINFLEXD4_RX_IRQn           = 482u, /* Linflex/eSCI4_0 LINFlex_4_RXI */
    LINFLEXD4_TX_IRQn           = 483u, /* Linflex/eSCI4_1 LINFlex_4_TXI */
    LINFLEXD4_ERR_IRQn          = 484u, /* Linflex/eSCI4_2 LINFlex_4_ERR */
    LINFLEXD5_RX_IRQn           = 485u, /* Linflex/eSCI5_0 LINFlex_5_RXI */
    LINFLEXD5_TX_IRQn           = 486u, /* Linflex/eSCI5_1 LINFlex_5_TXI */
    LINFLEXD5_ERR_IRQn          = 487u, /* Linflex/eSCI5_2 LINFlex_5_ERR */
    FCCU_0_IRQn                 = 488u, /* FCCU_0 FCCU_IRQ_STAT[ALRM_STAT] */
    FCCU_1_IRQn                 = 489u, /* FCCU_1 FCU_IRQ_STAT[CFG_TO_STAT] */

    LINFLEXD6_ERR_IRQn          = 492u, /* Linflex/eSCI6_2 LINFlex_6_ERR */
    LINFLEXD12_RX_IRQn          = 493u, /* Linflex/eSCI12_2 LINFlex_12_ERR */
    STCU2_0_RUNSW_LBIE_IRQn     = 494u, /* STCU2_0 STCU_RUNSW[LBIE] */
    STCU2_1_RUNSW_MBIE_IRQn     = 495u, /* STCU2_1 STCU_RUNSW[MBIE] */
    HSM2HOST_0_IRQn             = 496u, /* Hardware Security Module 0 HSM2HTIE[0] */
    HSM2HOST_1_IRQn             = 497u, /* Hardware Security Module 1 HSM2HTIE[1] */
    HSM2HOST_2_IRQn             = 498u, /* Hardware Security Module 2 HSM2HTIE[2] */
    HSM2HOST_3_IRQn             = 499u, /* Hardware Security Module 3 HSM2HTIE[3] */
    HSM2HOST_4_IRQn             = 500u, /* Hardware Security Module 4 HSM2HTIE[4] */
    HSM2HOST_5_IRQn             = 501u, /* Hardware Security Module 5 HSM2HTIE[5] */
    HSM2HOST_6_IRQn             = 502u, /* Hardware Security Module 6 HSM2HTIE[6] */
    HSM2HOST_7_IRQn             = 503u, /* Hardware Security Module 7 HSM2HTIE[7] */
    HSM2HOST_8_IRQn             = 504u, /* Hardware Security Module 8 HSM2HTIE[8] */
    HSM2HOST_9_IRQn             = 505u, /* Hardware Security Module 9 HSM2HTIE[9] */
    HSM2HOST_10_IRQn            = 506u, /* Hardware Security Module 10 HSM2HTIE[10] */
    HSM2HOST_11_IRQn            = 507u, /* Hardware Security Module 11 HSM2HTIE[11] */
    HSM2HOST_12_IRQn            = 508u, /* Hardware Security Module 12 HSM2HTIE[12] */
    HSM2HOST_13_IRQn            = 509u, /* Hardware Security Module 13 HSM2HTIE[13] */
    HSM2HOST_14_IRQn            = 510u, /* Hardware Security Module 14 HSM2HTIE[14] */
    HSM2HOST_15_IRQn            = 511u, /* Hardware Security Module 15 HSM2HTIE[15] */
    HSM2HOST_16_IRQn            = 512u, /* Hardware Security Module 16 HSM2HTIE[16] */
    HSM2HOST_17_IRQn            = 513u, /* Hardware Security Module 17 HSM2HTIE[17] */
    HSM2HOST_18_IRQn            = 514u, /* Hardware Security Module 18 HSM2HTIE[18] */
    HSM2HOST_19_IRQn            = 515u, /* Hardware Security Module 19 HSM2HTIE[19] */
    HSM2HOST_20_IRQn            = 516u, /* Hardware Security Module 20 HSM2HTIE[20] */
    HSM2HOST_21_IRQn            = 517u, /* Hardware Security Module 21 HSM2HTIE[21] */
    HSM2HOST_22_IRQn            = 518u, /* Hardware Security Module 22 HSM2HTIE[22] */
    HSM2HOST_23_IRQn            = 519u, /* Hardware Security Module 23 HSM2HTIE[23] */
    HSM2HOST_24_IRQn            = 520u, /* Hardware Security Module 24 HSM2HTIE[24] */
    HSM2HOST_25_IRQn            = 521u, /* Hardware Security Module 25 HSM2HTIE[25] */
    HSM2HOST_26_IRQn            = 522u, /* Hardware Security Module 26 HSM2HTIE[26] */
    HSM2HOST_27_IRQn            = 523u, /* Hardware Security Module 27 HSM2HTIE[27] */
    HSM2HOST_28_IRQn            = 524u, /* Hardware Security Module 28 HSM2HTIE[28] */
    HSM2HOST_29_IRQn            = 525u, /* Hardware Security Module 29 HSM2HTIE[29] */
    HSM2HOST_30_IRQn            = 526u, /* Hardware Security Module 30 HSM2HTIE[30] */
    HSM2HOST_31_IRQn            = 527u, /* Hardware Security Module 31 HSM2HTIE[31] */
    DECFILTER_0_IRQn            = 528u, /* Decimation Filter 0(Connects to EQADC01) */
    EQADC01_FIFO_OVERRUN_IRQn   = 529u, /* EQADC01_FISRx(0~5)[TORF | RFOF | CFUF] */
    DECFILTER_1_IRQn            = 530u, /* Decimation Filter 1(Connects to EQADC23) */
    EQADC23_FIFO_OVERRUN_IRQn   = 531u, /* EQADC23_FISRx(0~5)[TORF | RFOF | CFUF] */
    DECFILTER_2_IRQn            = 532u, /* Decimation Filter 2(Connects to EQADC45) */
    EQADC45_FIFO_OVERRUN_IRQn   = 533u, /* EQADC45_FISRx(0~5)[TORF | RFOF | CFUF] */
    DECFILTER_3_IRQn            = 534u, /* Decimation Filter 3(Connects to EQADC67) */
    EQADC67_FIFO_OVERRUN_IRQn   = 535u, /* EQADC67_FISRx(0~5)[TORF | RFOF | CFUF] */
    DECFILTER_4_IRQn            = 536u, /* Decimation Filter 4(Connects to EQADC89) */
    EQADC89_FIFO_OVERRUN_IRQn   = 537u, /* EQADC89_FISRx(0~5)[TORF | RFOF | CFUF] */
    GTM_TIM6_7_IRQn             = 538u, /* GTM_TIM6_IRQ[7] gtm_icm.gtm_tim6_irq[7] */
    LINFLEXD7_RX_IRQn           = 539u, /* Linflex/eSCI7_0 LINFlex_7_RXI */
    LINFLEXD7_TX_IRQn           = 540u, /* Linflex/eSCI7_1 LINFlex_7_TXI */
    LINFLEXD7_ERR_IRQn          = 541u, /* Linflex/eSCI7_2 LINFlex_7_ERR */
    LINFLEXD12_TX_IRQn          = 542u, /* Linflex/eSCI12_0 LINFlex_12_RXI */

    SDADC_0_IRQn                = 544u, /* SDADC_0 Interrupt */
    SDADC_1_IRQn                = 545u, /* SDADC_1 Interrupt */
    SDADC_2_IRQn                = 546u, /* SDADC_2 Interrupt */
    SDADC_3_IRQn                = 547u, /* SDADC_3 Interrupt */
    SDADC_4_IRQn                = 548u, /* SDADC_4 Interrupt */
    SDADC_5_IRQn                = 549u, /* SDADC_5 Interrupt */
    SDADC_6_IRQn                = 550u, /* SDADC_6 Interrupt */
    SDADC_7_IRQn                = 551u, /* SDADC_7 Interrupt */
    SDADC_8_IRQn                = 552u, /* SDADC_8 Interrupt */
    SDADC_9_IRQn                = 553u, /* SDADC_9 Interrupt */
    LINFLEXD8_RX_IRQn           = 554u, /* Linflex/eSCI8_0 LINFlex_8_RXI */
    LINFLEXD8_TX_IRQn           = 555u, /* Linflex/eSCI8_1 LINFlex_8_TXI */
    LINFLEXD8_ERR_IRQn          = 556u, /* Linflex/eSCI8_2 LINFlex_8_ERR */
    DECFILTER_5_IRQn            = 557u, /* Decimation Filter 5(Connects to EQADC1011) */
    EQADC1011_FIFO_OVERRUN_IRQn = 558u, /* EQADC1011_FISRx(0~5)[TORF | RFOF | CFUF] */
    DECFILTER_6_IRQn            = 559u, /* Decimation Filter 6(Connects to EQADC1213) */
    EQADC1213_FIFO_OVERRUN_IRQn = 560u, /* EQADC1213_FISRx(0~5)[TORF | RFOF | CFUF] */
    DSPI21_ERR_IRQn             = 561u, /* DSPI21_0 DSPI_21_SR[TFUF] | DSPI_21_SR[RFOF] | DSPI_21_SR[TFIWF] */
    DSPI21_EOQF_IRQn            = 562u, /* DSPI21_1 DSPI_21_SR[EOQF] */
    DSPI21_TFFF_IRQn            = 563u, /* DSPI21_2 DSPI_21_SR[TFFF] */
    DSPI21_TCF_IRQn             = 564u, /* DSPI21_3 DSPI_21_SR[TCF] */
    DSPI21_RFDF_IRQn            = 565u, /* DSPI21_4 DSPI_21_SR[RFDF] */
    DSPI21_CMD_TCF_IRQn         = 566u, /* DSPI21_5 DSPI_21_SR[CMD_TCF] */
    DSPI21_CMDFFF_IRQn          = 567u, /* DSPI21_6 DSPI_21_SR[CMD_TFFF] */
    DSPI21_SPEF_IRQn            = 568u, /* DSPI21_7 DSPI_21_SR[SPEF] */
    DSPI20_ERR_IRQn             = 569u, /* DSPI20_0 DSPI_20_SR[TFUF] | DSPI_20_SR[RFOF] | DSPI_20_SR[TFIWF] */
    DSPI20_EOQF_IRQn            = 570u, /* DSPI20_1 DSPI_20_SR[EOQF] */
    DSPI20_TFFF_IRQn            = 571u, /* DSPI20_2 DSPI_20_SR[TFFF] */
    DSPI20_TCF_IRQn             = 572u, /* DSPI20_3 DSPI_20_SR[TCF] */
    DSPI20_RFDF_IRQn            = 573u, /* DSPI20_4 DSPI_20_SR[RFDF] */
    DSPI20_CMD_TCF_IRQn         = 574u, /* DSPI20_5 DSPI_20_SR[CMD_TCF] */
    DSPI20_CMDFFF_IRQn          = 575u, /* DSPI20_6 DSPI_20_SR[CMD_TFFF] */
    DSPI20_SPEF_IRQn            = 576u, /* DSPI20_7 DSPI_20_SR[SPEF] */
    DSPI19_ERR_IRQn             = 577u, /* DSPI19_0 DSPI_19_SR[TFUF] | DSPI_19_SR[RFOF] | DSPI_19_SR[TFIWF] */
    DSPI19_EOQF_IRQn            = 578u, /* DSPI19_1 DSPI_19_SR[EOQF] */
    DSPI19_TFFF_IRQn            = 579u, /* DSPI19_2 DSPI_19_SR[TFFF] */
    DSPI19_TCF_IRQn             = 580u, /* DSPI19_3 DSPI_19_SR[TCF] */
    DSPI19_RFDF_IRQn            = 581u, /* DSPI19_4 DSPI_19_SR[RFDF] */
    DSPI19_CMD_TCF_IRQn         = 582u, /* DSPI19_5 DSPI_19_SR[CMD_TCF] */
    DSPI19_CMDFFF_IRQn          = 583u, /* DSPI19_6 DSPI_19_SR[CMD_TFFF] */
    DSPI19_SPEF_IRQn            = 584u, /* DSPI19_7 DSPI_19_SR[SPEF] */
    DSPI18_ERR_IRQn             = 585u, /* DSPI18_0 DSPI_18_SR[TFUF] | DSPI_18_SR[RFOF] | DSPI_18_SR[TFIWF] */
    DSPI18_EOQF_IRQn            = 586u, /* DSPI18_1 DSPI_18_SR[EOQF] */
    DSPI18_TFFF_IRQn            = 587u, /* DSPI18_2 DSPI_18_SR[TFFF] */
    DSPI18_TCF_IRQn             = 588u, /* DSPI18_3 DSPI_18_SR[TCF] */
    DSPI18_RFDF_IRQn            = 589u, /* DSPI18_4 DSPI_18_SR[RFDF] */
    DSPI18_CMD_TCF_IRQn         = 590u, /* DSPI18_5 DSPI_18_SR[CMD_TCF] */
    DSPI18_CMDFFF_IRQn          = 591u, /* DSPI18_6 DSPI_18_SR[CMD_TFFF] */
    DSPI18_SPEF_IRQn            = 592u, /* DSPI18_7 DSPI_18_SR[SPEF] */
    DSPI17_ERR_IRQn             = 593u, /* DSPI17_0 DSPI_17_SR[TFUF] | DSPI_17_SR[RFOF] | DSPI_17_SR[TFIWF] */
    DSPI17_EOQF_IRQn            = 594u, /* DSPI17_1 DSPI_17_SR[EOQF] */
    DSPI17_TFFF_IRQn            = 595u, /* DSPI17_2 DSPI_17_SR[TFFF] */
    DSPI17_TCF_IRQn             = 596u, /* DSPI17_3 DSPI_17_SR[TCF] */
    DSPI17_RFDF_IRQn            = 597u, /* DSPI17_4 DSPI_17_SR[RFDF] */
    DSPI17_CMD_TCF_IRQn         = 598u, /* DSPI17_5 DSPI_17_SR[CMD_TCF] */
    DSPI17_CMDFFF_IRQn          = 599u, /* DSPI17_6 DSPI_17_SR[CMD_TFFF] */
    DSPI17_SPEF_IRQn            = 600u, /* DSPI17_7 DSPI_17_SR[SPEF] */
    DSPI16_ERR_IRQn             = 601u, /* DSPI16_0 DSPI_16_SR[TFUF] | DSPI_16_SR[RFOF] | DSPI_16_SR[TFIWF] */
    DSPI16_EOQF_IRQn            = 602u, /* DSPI16_1 DSPI_16_SR[EOQF] */
    DSPI16_TFFF_IRQn            = 603u, /* DSPI16_2 DSPI_16_SR[TFFF] */
    DSPI16_TCF_IRQn             = 604u, /* DSPI16_3 DSPI_16_SR[TCF] */
    DSPI16_RFDF_IRQn            = 605u, /* DSPI16_4 DSPI_16_SR[RFDF] */
    DSPI16_CMD_TCF_IRQn         = 606u, /* DSPI16_5 DSPI_16_SR[CMD_TCF] */
    DSPI16_CMDFFF_IRQn          = 607u, /* DSPI16_6 DSPI_16_SR[CMD_TFFF] */
    DSPI16_SPEF_IRQn            = 608u, /* DSPI16_7 DSPI_16_SR[SPEF] */
    LINFLEXD9_RX_IRQn           = 609u, /* Linflex/eSCI9_0 LINFlex_9_RXI */
    LINFLEXD9_TX_IRQn           = 610u, /* Linflex/eSCI9_1 LINFlex_9_TXI */
    LINFLEXD9_ERR_IRQn          = 611u, /* Linflex/eSCI9_2 LINFlex_9_ERR */
    GTM_TIM6_6_IRQn             = 612u, /* GTM_TIM6_IRQ[6] gtm_icm.gtm_tim6_irq[6] */
    GTM_TIM6_5_IRQn             = 613u, /* GTM_TIM6_IRQ[5] gtm_icm.gtm_tim6_irq[5] */
    GTM_TIM6_4_IRQn             = 614u, /* GTM_TIM6_IRQ[4] gtm_icm.gtm_tim6_irq[4] */
    GTM_TIM6_3_IRQn             = 615u, /* GTM_TIM6_IRQ[3] gtm_icm.gtm_tim6_irq[3] */
    GTM_TIM6_2_IRQn             = 616u, /* GTM_TIM6_IRQ[2] gtm_icm.gtm_tim6_irq[2] */
    GTM_TIM6_1_IRQn             = 617u, /* GTM_TIM6_IRQ[1] gtm_icm.gtm_tim6_irq[1] */
    GTM_TIM6_0_IRQn             = 618u, /* GTM_TIM6_IRQ[0] gtm_icm.gtm_tim6_irq[0] */
    GTM_PSM2_7_IRQn             = 619u, /* GTM_PSM2_IRQ[7] gtm_icm.gtm_psm2_irq[7] */
    GTM_PSM2_6_IRQn             = 620u, /* GTM_PSM2_IRQ[6] gtm_icm.gtm_psm2_irq[6] */
    GTM_PSM2_5_IRQn             = 621u, /* GTM_PSM2_IRQ[5] gtm_icm.gtm_psm2_irq[5] */
    GTM_PSM2_4_IRQn             = 622u, /* GTM_PSM2_IRQ[4] gtm_icm.gtm_psm2_irq[4] */
    GTM_PSM2_3_IRQn             = 623u, /* GTM_PSM2_IRQ[3] gtm_icm.gtm_psm2_irq[3] */
    GTM_PSM2_2_IRQn             = 624u, /* GTM_PSM2_IRQ[2] gtm_icm.gtm_psm2_irq[2] */
    GTM_PSM2_1_IRQn             = 625u, /* GTM_PSM2_IRQ[1] gtm_icm.gtm_psm2_irq[1] */
    GTM_PSM2_0_IRQn             = 626u, /* GTM_PSM2_IRQ[0] gtm_icm.gtm_psm2_irq[0] */
    DSPI8_DPEF_IRQn             = 627u, /* DSPI8_7 DSPI_8_SR[SPEF] | DSPI_8_SR[DPEF] */
    CFLASH_PFI5_FGF_PECI_IRQn   = 628u, /* CFLASH Pfi5_fgf_peci */
    CFLASH_PFI4_FGF_PECI_IRQn   = 629u, /* CFLASH Pfi4_fgf_peci */
    CFLASH_PFI3_FGF_PECI_IRQn   = 630u, /* CFLASH Pfi3_fgf_peci */
    CFLASH_PFI2_FGF_PECI_IRQn   = 631u, /* CFLASH Pfi2_fgf_peci */
    CFLASH_PFI1_FGF_PECI_IRQn   = 632u, /* CFLASH Pfi1_fgf_peci */
    CFLASH_PFI0_FGF_PECI_IRQn   = 633u, /* CFLASH Pfi0_fgf_peci */
    LINFLEXD12_ERR_IRQn         = 634u, /* Linflex/eSCI12_2 LINFlex_12_ERR */
    DSPI10_DPEF_IRQn            = 635u, /* DSPI10_7 DSPI_10_SR[SPEF] | DSPI_10_SR[DPEF] */
    DSPI14_DPEF_IRQn            = 636u, /* DSPI14_7 DSPI_14_SR[SPEF] | DSPI_14_SR[DPEF] */
    PSI5_0_CH0_IRQn             = 637u, /* PSI5_0_CH0 PSI5_0_CH_0_DSR[*] | PSI5_0_CH_0_GISR[*] | PSI5_0_CH_0_NDSR[31:0] | PSI5_0_CH_0_OWSR[31:0] | PSI5_0_CH_0_EISR[31:0] */
    PSI5_0_CH1_IRQn             = 638u, /* PSI5_0_CH1 PSI5_0_CH_1_DSR[*] | PSI5_0_CH_1_GISR[*] | PSI5_0_CH_1_NDSR[31:0] | PSI5_0_CH_1_OWSR[31:0] | PSI5_0_CH_1_EISR[31:0] */
    PSI5_0_CH3_IRQn             = 639u, /* PSI5_0_CH3 PSI5_0_CH_3_DSR[*] | PSI5_0_CH_3_GISR[*] | PSI5_0_CH_3_NDSR[31:0] | PSI5_0_CH_3_OWSR[31:0] | PSI5_0_CH_3_EISR[31:0] */
    PSI5_0_CH2_IRQn             = 640u, /* PSI5_0_CH2 PSI5_0_CH_2_DSR[*] | PSI5_0_CH_2_GISR[*] | PSI5_0_CH_2_NDSR[31:0] | PSI5_0_CH_2_OWSR[31:0] | PSI5_0_CH_2_EISR[31:0] */

    LINFLEXD10_RX_IRQn          = 642u, /* Linflex/eSCI10_0 LINFlex_10_RXI */
    LINFLEXD10_TX_IRQn          = 643u, /* Linflex/eSCI10_1 LINFlex_10_TXI */
    LINFLEXD10_ERR_IRQn         = 644u, /* Linflex/eSCI10_2 LINFlex_10_ERR */
    LINFLEXD11_RX_IRQn          = 645u, /* Linflex/eSCI11_0 LINFlex_11_RXI */
    LINFLEXD11_TX_IRQn          = 646u, /* Linflex/eSCI11_1 LINFlex_11_TXI */
    LINFLEXD11_ERR_IRQn         = 647u, /* Linflex/eSCI11_2 LINFlex_11_ERR */
    RTC_IRQn                    = 648u, /* RTC Interrupt */
    DSPI15_DPEF_IRQn            = 649u, /* DSPI15_7 DSPI_15_SR[SPEF] | DSPI_15_SR[DPEF] */
    DSPI19_DPEF_IRQn            = 650u, /* DSPI19_7 DSPI_19_SR[SPEF] | DSPI_19_SR[DPEF] */
    DSPI20_DPEF_IRQn            = 651u, /* DSPI20_7 DSPI_20_SR[SPEF] | DSPI_20_SR[DPEF] */
    DSPI21_DPEF_IRQn            = 652u, /* DSPI21_7 DSPI_21_SR[SPEF] | DSPI_21_SR[DPEF] */
    DSPI8_SPI_TCF_IRQn          = 653u, /* DSPI8_5 DSPI_8_SR[SPITCF] | DSPI_8_SR[CMD_TCF] */
    DSPI10_SPI_TCF_IRQn         = 654u, /* DSPI10_5 DSPI_10_SR[SPITCF] | DSPI_10_SR[CMD_TCF] */
    DSPI14_SPI_TCF_IRQn         = 655u, /* DSPI14_5 DSPI_14_SR[SPITCF] | DSPI_14_SR[CMD_TCF] */
    DSPI15_SPI_TCF_IRQn         = 656u, /* DSPI15_5 DSPI_15_SR[SPITCF] | DSPI_15_SR[CMD_TCF] */
    DSPI19_SPI_TCF_IRQn         = 657u, /* DSPI19_5 DSPI_19_SR[SPITCF] | DSPI_19_SR[CMD_TCF] */
    DSPI20_SPI_TCF_IRQn         = 658u, /* DSPI20_5 DSPI_20_SR[SPITCF] | DSPI_20_SR[CMD_TCF] */
    DSPI21_SPI_TCF_IRQn         = 659u, /* DSPI21_5 DSPI_21_SR[SPITCF] | DSPI_21_SR[CMD_TCF] */
    DSPI8_DSI_TCF_IRQn          = 660u, /* DSPI8_6 DSPI_8_SR[DSITCF] | DSPI_8_SR[CMD_TFFF] */
    DSPI10_DSI_TCF_IRQn         = 661u, /* DSPI10_6 DSPI_10_SR[DSITCF] | DSPI_10_SR[CMD_TFFF] */
    DSPI14_DSI_TCF_IRQn         = 662u, /* DSPI14_6 DSPI_14_SR[DSITCF] | DSPI_14_SR[CMD_TFFF] */
    DSPI15_DSI_TCF_IRQn         = 663u, /* DSPI15_6 DSPI_15_SR[DSITCF] | DSPI_15_SR[CMD_TFFF] */
    DSPI19_DSI_TCF_IRQn         = 664u, /* DSPI19_6 DSPI_19_SR[DSITCF] | DSPI_19_SR[CMD_TFFF] */
    DSPI20_DSI_TCF_IRQn         = 665u, /* DSPI20_6 DSPI_20_SR[DSITCF] | DSPI_20_SR[CMD_TFFF] */
    DSPI21_DSI_TCF_IRQn         = 666u, /* DSPI21_6 DSPI_21_SR[DSITCF] | DSPI_21_SR[CMD_TFFF] */
    DSPI7_DPEF_IRQn             = 667u, /* DSPI7_7 DSPI_7_SR[SPEF] | DSPI_7_SR[DPEF] */
    DSPI9_DPEF_IRQn             = 668u, /* DSPI9_7 DSPI_9_SR[SPEF] | DSPI_9_SR[DPEF] */
    DSPI11_DPEF_IRQn            = 669u, /* DSPI11_7 DSPI_11_SR[SPEF] | DSPI_11_SR[DPEF] */
    DSPI13_DPEF_IRQn            = 670u, /* DSPI13_7 DSPI_13_SR[SPEF] | DSPI_13_SR[DPEF] */
    DSPI16_DPEF_IRQn            = 671u, /* DSPI16_7 DSPI_16_SR[SPEF] | DSPI_16_SR[DPEF] */
    DSPI17_DPEF_IRQn            = 672u, /* DSPI17_7 DSPI_17_SR[SPEF] | DSPI_17_SR[DPEF] */
    DSPI18_DPEF_IRQn            = 673u, /* DSPI18_7 DSPI_18_SR[SPEF] | DSPI_18_SR[DPEF] */
    SDADC_13_IRQn               = 674u, /* SDADC_13 Interrupt */
    JDC_MSR_IRQn                = 675u, /* JDC JDC_MSR[JIN_INT] | JDC_MSR[JOUT_INT]*/
    DSPI7_SPI_TCF_IRQn          = 676u, /* DSPI7_5 DSPI_7_SR[SPITCF] | DSPI_7_SR[CMD_TCF] */
    M_TTCAN0_LINE0_IRQn         = 677u, /* M_TTCAN0_0 M_TTCAN_0 interrupt line0 */
    M_TTCAN0_LINE1_IRQn         = 678u, /* M_TTCAN0_1 M_TTCAN_0 interrupt line1 */
    M_TTCAN0_TIME_MARK_IRQn     = 679u, /* M_TTCAN0_2 M_TTCAN_0 Register Time Mark interrupt */
    DSPI9_SPI_TCF_IRQn          = 680u, /* DSPI9_5 DSPI_9_SR[SPITCF] | DSPI_9_SR[CMD_TCF] */
    DSPI11_SPI_TCF_IRQn         = 681u, /* DSPI11_5 DSPI_11_SR[SPITCF] | DSPI_11_SR[CMD_TCF] */
    DSPI13_SPI_TCF_IRQn         = 682u, /* DSPI13_5 DSPI_13_SR[SPITCF] | DSPI_13_SR[CMD_TCF] */
    DSPI16_SPI_TCF_IRQn         = 683u, /* DSPI16_5 DSPI_16_SR[SPITCF] | DSPI_16_SR[CMD_TCF] */
    DSPI17_SPI_TCF_IRQn         = 684u, /* DSPI17_5 DSPI_17_SR[SPITCF] | DSPI_17_SR[CMD_TCF] */
    M_TTCAN1_LINE0_IRQn         = 685u, /* M_TTCAN1_0 M_TTCAN_1 interrupt line0 */
    M_TTCAN1_LINE1_IRQn         = 686u, /* M_TTCAN1_1 M_TTCAN_1 interrupt line1 */
    M_TTCAN1_TIME_MARK_IRQn     = 687u, /* M_TTCAN1_2 M_TTCAN_1 Register Time Mark interrupt */
    MCAN1_0_IRQn                = 688u, /* M_CAN1 Interrupt Line 0 */
    MCAN1_1_IRQn                = 689u, /* M_CAN1 Interrupt Line 1 */
    MCAN2_0_IRQn                = 690u, /* M_CAN2 Interrupt Line 0 */
    MCAN2_1_IRQn                = 691u, /* M_CAN2 Interrupt Line 1 */
    MCAN3_0_IRQn                = 692u, /* M_CAN3 Interrupt Line 0 */
    MCAN3_1_IRQn                = 693u, /* M_CAN3 Interrupt Line 1 */
    MCAN4_0_IRQn                = 694u, /* M_CAN4 Interrupt Line 0 */
    MCAN4_1_IRQn                = 695u, /* M_CAN4 Interrupt Line 1 */
    MCAN5_0_IRQn                = 696u, /* M_CAN5 Interrupt Line 0 */
    MCAN5_1_IRQn                = 697u, /* M_CAN5 Interrupt Line 1 */
    MCAN6_0_IRQn                = 698u, /* M_CAN6 Interrupt Line 0 */
    MCAN6_1_IRQn                = 699u, /* M_CAN6 Interrupt Line 1 */
    MCAN7_0_IRQn                = 700u, /* M_CAN7 Interrupt Line 0 */
    MCAN7_1_IRQn                = 701u, /* M_CAN7 Interrupt Line 1 */
    MCAN8_0_IRQn                = 702u, /* M_CAN8 Interrupt Line 0 */
    MCAN8_1_IRQn                = 703u, /* M_CAN8 Interrupt Line 1 */
    DSPI18_SPI_TCF_IRQn         = 704u, /* DSPI18_5 DSPI_18_SR[SPITCF] | DSPI_18_SR[CMD_TCF] */
    DSPI7_DSI_TCF_IRQn          = 705u, /* DSPI7_5 DSPI_7_SR[DSITCF] | DSPI_7_SR[CMD_FFF] */
    GTM_AEI_IRQn                = 706u, /* GTM_AEI_IRQ AEI gtm_icm.gtm_aei_irq aei */
    GTM_ARU_0_IRQn              = 707u, /* GTM_ARU_IRQ[0] gtm_icm.gtm_aru_irq[0] */
    GTM_ARU_1_IRQn              = 708u, /* GTM_ARU_IRQ[1] gtm_icm.gtm_aru_irq[1] */
    GTM_ARU_2_IRQn              = 709u, /* GTM_ARU_IRQ[2] gtm_icm.gtm_aru_irq[2] */
    GTM_BRC_IRQn                = 710u, /* GTM_BRC_IRQ gtm_icm.gtm_brc_irq */
    GTM_CMP_IRQn                = 711u, /* GTM_CMP_IRQ gtm_icm.gtm_cmp_irq */
    GTM_SPE0_IRQn               = 712u, /* GTM_SPE0_IRQ gtm_icm.gtm_spe0_irq */
    GTM_SPE1_IRQn               = 713u, /* GTM_SPE1_IRQ gtm_icm.gtm_spe1_irq */
    GTM_PSM0_0_IRQn             = 714u, /* GTM_PSM0_IRQ[0] gtm_icm.gtm_psm0_irq[0] */
    GTM_PSM0_1_IRQn             = 715u, /* GTM_PSM0_IRQ[1] gtm_icm.gtm_psm0_irq[1] */
    GTM_PSM0_2_IRQn             = 716u, /* GTM_PSM0_IRQ[2] gtm_icm.gtm_psm0_irq[2] */
    GTM_PSM0_3_IRQn             = 717u, /* GTM_PSM0_IRQ[3] gtm_icm.gtm_psm0_irq[3] */
    GTM_PSM0_4_IRQn             = 718u, /* GTM_PSM0_IRQ[4] gtm_icm.gtm_psm0_irq[4] */
    GTM_PSM0_5_IRQn             = 719u, /* GTM_PSM0_IRQ[5] gtm_icm.gtm_psm0_irq[5] */
    GTM_PSM0_6_IRQn             = 720u, /* GTM_PSM0_IRQ[6] gtm_icm.gtm_psm0_irq[6] */
    GTM_PSM0_7_IRQn             = 721u, /* GTM_PSM0_IRQ[7] gtm_icm.gtm_psm0_irq[7] */
    GTM_DPLL_0_IRQn             = 722u, /* GTM_DPLL_IRQ[0] gtm_icm.gtm_dpll_irq[0] */
    GTM_DPLL_1_IRQn             = 723u, /* GTM_DPLL_IRQ[1] gtm_icm.gtm_dpll_irq[1] */
    GTM_DPLL_2_IRQn             = 724u, /* GTM_DPLL_IRQ[2] gtm_icm.gtm_dpll_irq[2] */
    GTM_DPLL_3_IRQn             = 725u, /* GTM_DPLL_IRQ[3] gtm_icm.gtm_dpll_irq[3] */
    GTM_DPLL_4_IRQn             = 726u, /* GTM_DPLL_IRQ[4] gtm_icm.gtm_dpll_irq[4] */
    GTM_DPLL_5_IRQn             = 727u, /* GTM_DPLL_IRQ[5] gtm_icm.gtm_dpll_irq[5] */
    GTM_DPLL_6_IRQn             = 728u, /* GTM_DPLL_IRQ[6] gtm_icm.gtm_dpll_irq[6] */
    GTM_DPLL_7_IRQn             = 729u, /* GTM_DPLL_IRQ[7] gtm_icm.gtm_dpll_irq[7] */
    GTM_DPLL_8_IRQn             = 730u, /* GTM_DPLL_IRQ[8] gtm_icm.gtm_dpll_irq[8] */
    GTM_DPLL_9_IRQn             = 731u, /* GTM_DPLL_IRQ[9] gtm_icm.gtm_dpll_irq[9] */
    GTM_DPLL_10_IRQn            = 732u, /* GTM_DPLL_IRQ[10] gtm_icm.gtm_dpll_irq[10] */
    GTM_DPLL_11_IRQn            = 733u, /* GTM_DPLL_IRQ[11] gtm_icm.gtm_dpll_irq[11] */
    GTM_DPLL_12_IRQn            = 734u, /* GTM_DPLL_IRQ[12] gtm_icm.gtm_dpll_irq[12] */
    GTM_DPLL_13_IRQn            = 735u, /* GTM_DPLL_IRQ[13] gtm_icm.gtm_dpll_irq[13] */
    GTM_DPLL_14_IRQn            = 736u, /* GTM_DPLL_IRQ[14] gtm_icm.gtm_dpll_irq[14] */
    GTM_DPLL_15_IRQn            = 737u, /* GTM_DPLL_IRQ[15] gtm_icm.gtm_dpll_irq[15] */
    GTM_DPLL_16_IRQn            = 738u, /* GTM_DPLL_IRQ[16] gtm_icm.gtm_dpll_irq[16] */
    GTM_DPLL_17_IRQn            = 739u, /* GTM_DPLL_IRQ[17] gtm_icm.gtm_dpll_irq[17] */
    GTM_DPLL_18_IRQn            = 740u, /* GTM_DPLL_IRQ[18] gtm_icm.gtm_dpll_irq[18] */
    GTM_DPLL_19_IRQn            = 741u, /* GTM_DPLL_IRQ[19] gtm_icm.gtm_dpll_irq[19] */
    GTM_DPLL_20_IRQn            = 742u, /* GTM_DPLL_IRQ[20] gtm_icm.gtm_dpll_irq[20] */
    GTM_DPLL_21_IRQn            = 743u, /* GTM_DPLL_IRQ[21] gtm_icm.gtm_dpll_irq[21] */
    GTM_DPLL_22_IRQn            = 744u, /* GTM_DPLL_IRQ[22] gtm_icm.gtm_dpll_irq[22] */
    GTM_DPLL_23_IRQn            = 745u, /* GTM_DPLL_IRQ[23] gtm_icm.gtm_dpll_irq[23] */
    GTM_DPLL_24_IRQn            = 746u, /* GTM_DPLL_IRQ[24] gtm_icm.gtm_dpll_irq[24] */
    GTM_DPLL_25_IRQn            = 747u, /* GTM_DPLL_IRQ[25] gtm_icm.gtm_dpll_irq[25] */
    GTM_DPLL_26_IRQn            = 748u, /* GTM_DPLL_IRQ[26] gtm_icm.gtm_dpll_irq[26] */
    GTM_TIM0_0_IRQn             = 749u, /* GTM_TIM0_IRQ[0] gtm_icm.gtm_tim0_irq[0] */
    GTM_TIM0_1_IRQn             = 750u, /* GTM_TIM0_IRQ[1] gtm_icm.gtm_tim0_irq[1] */
    GTM_TIM0_2_IRQn             = 751u, /* GTM_TIM0_IRQ[2] gtm_icm.gtm_tim0_irq[2] */
    GTM_TIM0_3_IRQn             = 752u, /* GTM_TIM0_IRQ[3] gtm_icm.gtm_tim0_irq[3] */
    GTM_TIM0_4_IRQn             = 753u, /* GTM_TIM0_IRQ[4] gtm_icm.gtm_tim0_irq[4] */
    GTM_TIM0_5_IRQn             = 754u, /* GTM_TIM0_IRQ[5] gtm_icm.gtm_tim0_irq[5] */
    GTM_TIM0_6_IRQn             = 755u, /* GTM_TIM0_IRQ[6] gtm_icm.gtm_tim0_irq[6] */
    GTM_TIM0_7_IRQn             = 756u, /* GTM_TIM0_IRQ[7] gtm_icm.gtm_tim0_irq[7] */
    GTM_TIM1_0_IRQn             = 757u, /* GTM_TIM1_IRQ[0] gtm_icm.gtm_tim1_irq[0] */
    GTM_TIM1_1_IRQn             = 758u, /* GTM_TIM1_IRQ[1] gtm_icm.gtm_tim1_irq[1] */
    GTM_TIM1_2_IRQn             = 759u, /* GTM_TIM1_IRQ[2] gtm_icm.gtm_tim1_irq[2] */
    GTM_TIM1_3_IRQn             = 760u, /* GTM_TIM1_IRQ[3] gtm_icm.gtm_tim1_irq[3] */
    GTM_TIM1_4_IRQn             = 761u, /* GTM_TIM1_IRQ[4] gtm_icm.gtm_tim1_irq[4] */
    GTM_TIM1_5_IRQn             = 762u, /* GTM_TIM1_IRQ[5] gtm_icm.gtm_tim1_irq[5] */
    GTM_TIM1_6_IRQn             = 763u, /* GTM_TIM1_IRQ[6] gtm_icm.gtm_tim1_irq[6] */
    GTM_TIM1_7_IRQn             = 764u, /* GTM_TIM1_IRQ[7] gtm_icm.gtm_tim1_irq[7] */
    GTM_TIM2_0_IRQn             = 765u, /* GTM_TIM2_IRQ[0] gtm_icm.gtm_tim2_irq[0] */
    GTM_TIM2_1_IRQn             = 766u, /* GTM_TIM2_IRQ[1] gtm_icm.gtm_tim2_irq[1] */
    GTM_TIM2_2_IRQn             = 767u, /* GTM_TIM2_IRQ[2] gtm_icm.gtm_tim2_irq[2] */
    GTM_TIM2_3_IRQn             = 768u, /* GTM_TIM2_IRQ[3] gtm_icm.gtm_tim2_irq[3] */
    GTM_TIM2_4_IRQn             = 769u, /* GTM_TIM2_IRQ[4] gtm_icm.gtm_tim2_irq[4] */
    GTM_TIM2_5_IRQn             = 770u, /* GTM_TIM2_IRQ[5] gtm_icm.gtm_tim2_irq[5] */
    GTM_TIM2_6_IRQn             = 771u, /* GTM_TIM2_IRQ[6] gtm_icm.gtm_tim2_irq[6] */
    GTM_TIM2_7_IRQn             = 772u, /* GTM_TIM2_IRQ[7] gtm_icm.gtm_tim2_irq[7] */
    GTM_TIM3_0_IRQn             = 773u, /* GTM_TIM3_IRQ[0] gtm_icm.gtm_tim3_irq[0] */
    GTM_TIM3_1_IRQn             = 774u, /* GTM_TIM3_IRQ[1] gtm_icm.gtm_tim3_irq[1] */
    GTM_TIM3_2_IRQn             = 775u, /* GTM_TIM3_IRQ[2] gtm_icm.gtm_tim3_irq[2] */
    GTM_TIM3_3_IRQn             = 776u, /* GTM_TIM3_IRQ[3] gtm_icm.gtm_tim3_irq[3] */
    GTM_TIM3_4_IRQn             = 777u, /* GTM_TIM3_IRQ[4] gtm_icm.gtm_tim3_irq[4] */
    GTM_TIM3_5_IRQn             = 778u, /* GTM_TIM3_IRQ[5] gtm_icm.gtm_tim3_irq[5] */
    GTM_TIM3_6_IRQn             = 779u, /* GTM_TIM3_IRQ[6] gtm_icm.gtm_tim3_irq[6] */
    GTM_TIM3_7_IRQn             = 780u, /* GTM_TIM3_IRQ[7] gtm_icm.gtm_tim3_irq[7] */
    GTM_MCS0_0_IRQn             = 781u, /* GTM_MCS0_IRQ[0] gtm_icm.gtm_mcs0_irq[0] */
    GTM_MCS0_1_IRQn             = 782u, /* GTM_MCS0_IRQ[1] gtm_icm.gtm_mcs0_irq[1] */
    GTM_MCS0_2_IRQn             = 783u, /* GTM_MCS0_IRQ[2] gtm_icm.gtm_mcs0_irq[2] */
    GTM_MCS0_3_IRQn             = 784u, /* GTM_MCS0_IRQ[3] gtm_icm.gtm_mcs0_irq[3] */
    GTM_MCS0_4_IRQn             = 785u, /* GTM_MCS0_IRQ[4] gtm_icm.gtm_mcs0_irq[4] */
    GTM_MCS0_5_IRQn             = 786u, /* GTM_MCS0_IRQ[5] gtm_icm.gtm_mcs0_irq[5] */
    GTM_MCS0_6_IRQn             = 787u, /* GTM_MCS0_IRQ[6] gtm_icm.gtm_mcs0_irq[6] */
    GTM_MCS0_7_IRQn             = 788u, /* GTM_MCS0_IRQ[7] gtm_icm.gtm_mcs0_irq[7] */
    GTM_MCS1_0_IRQn             = 789u, /* GTM_MCS1_IRQ[0] gtm_icm.gtm_mcs1_irq[0] */
    GTM_MCS1_1_IRQn             = 790u, /* GTM_MCS1_IRQ[1] gtm_icm.gtm_mcs1_irq[1] */
    GTM_MCS1_2_IRQn             = 791u, /* GTM_MCS1_IRQ[2] gtm_icm.gtm_mcs1_irq[2] */
    GTM_MCS1_3_IRQn             = 792u, /* GTM_MCS1_IRQ[3] gtm_icm.gtm_mcs1_irq[3] */
    GTM_MCS1_4_IRQn             = 793u, /* GTM_MCS1_IRQ[4] gtm_icm.gtm_mcs1_irq[4] */
    GTM_MCS1_5_IRQn             = 794u, /* GTM_MCS1_IRQ[5] gtm_icm.gtm_mcs1_irq[5] */
    GTM_MCS1_6_IRQn             = 795u, /* GTM_MCS1_IRQ[6] gtm_icm.gtm_mcs1_irq[6] */
    GTM_MCS1_7_IRQn             = 796u, /* GTM_MCS1_IRQ[7] gtm_icm.gtm_mcs1_irq[7] */
    GTM_MCS2_0_IRQn             = 797u, /* GTM_MCS2_IRQ[0] gtm_icm.gtm_mcs2_irq[0] */
    GTM_MCS2_1_IRQn             = 798u, /* GTM_MCS2_IRQ[1] gtm_icm.gtm_mcs2_irq[1] */
    GTM_MCS2_2_IRQn             = 799u, /* GTM_MCS2_IRQ[2] gtm_icm.gtm_mcs2_irq[2] */
    GTM_MCS2_3_IRQn             = 800u, /* GTM_MCS2_IRQ[3] gtm_icm.gtm_mcs2_irq[3] */
    GTM_MCS2_4_IRQn             = 801u, /* GTM_MCS2_IRQ[4] gtm_icm.gtm_mcs2_irq[4] */
    GTM_MCS2_5_IRQn             = 802u, /* GTM_MCS2_IRQ[5] gtm_icm.gtm_mcs2_irq[5] */
    GTM_MCS2_6_IRQn             = 803u, /* GTM_MCS2_IRQ[6] gtm_icm.gtm_mcs2_irq[6] */
    GTM_MCS2_7_IRQn             = 804u, /* GTM_MCS2_IRQ[7] gtm_icm.gtm_mcs2_irq[7] */
    GTM_MCS3_0_IRQn             = 805u, /* GTM_MCS3_IRQ[0] gtm_icm.gtm_mcs3_irq[0] */
    GTM_MCS3_1_IRQn             = 806u, /* GTM_MCS3_IRQ[1] gtm_icm.gtm_mcs3_irq[1] */
    GTM_MCS3_2_IRQn             = 807u, /* GTM_MCS3_IRQ[2] gtm_icm.gtm_mcs3_irq[2] */
    GTM_MCS3_3_IRQn             = 808u, /* GTM_MCS3_IRQ[3] gtm_icm.gtm_mcs3_irq[3] */
    GTM_MCS3_4_IRQn             = 809u, /* GTM_MCS3_IRQ[4] gtm_icm.gtm_mcs3_irq[4] */
    GTM_MCS3_5_IRQn             = 810u, /* GTM_MCS3_IRQ[5] gtm_icm.gtm_mcs3_irq[5] */
    GTM_MCS3_6_IRQn             = 811u, /* GTM_MCS3_IRQ[6] gtm_icm.gtm_mcs3_irq[6] */
    GTM_MCS3_7_IRQn             = 812u, /* GTM_MCS3_IRQ[7] gtm_icm.gtm_mcs3_irq[7] */
    GTM_TOM0_0_IRQn             = 813u, /* GTM_TOM0_IRQ[0] gtm_icm.gtm_tom0_irq[0] */
    GTM_TOM0_1_IRQn             = 814u, /* GTM_TOM0_IRQ[1] gtm_icm.gtm_tom0_irq[1] */
    GTM_TOM0_2_IRQn             = 815u, /* GTM_TOM0_IRQ[2] gtm_icm.gtm_tom0_irq[2] */
    GTM_TOM0_3_IRQn             = 816u, /* GTM_TOM0_IRQ[3] gtm_icm.gtm_tom0_irq[3] */
    GTM_TOM0_4_IRQn             = 817u, /* GTM_TOM0_IRQ[4] gtm_icm.gtm_tom0_irq[4] */
    GTM_TOM0_5_IRQn             = 818u, /* GTM_TOM0_IRQ[5] gtm_icm.gtm_tom0_irq[5] */
    GTM_TOM0_6_IRQn             = 819u, /* GTM_TOM0_IRQ[6] gtm_icm.gtm_tom0_irq[6] */
    GTM_TOM0_7_IRQn             = 820u, /* GTM_TOM0_IRQ[7] gtm_icm.gtm_tom0_irq[7] */
    GTM_TOM1_0_IRQn             = 821u, /* GTM_TOM1_IRQ[0] gtm_icm.gtm_tom1_irq[0] */
    GTM_TOM1_1_IRQn             = 822u, /* GTM_TOM1_IRQ[1] gtm_icm.gtm_tom1_irq[1] */
    GTM_TOM1_2_IRQn             = 823u, /* GTM_TOM1_IRQ[2] gtm_icm.gtm_tom1_irq[2] */
    GTM_TOM1_3_IRQn             = 824u, /* GTM_TOM1_IRQ[3] gtm_icm.gtm_tom1_irq[3] */
    GTM_TOM1_4_IRQn             = 825u, /* GTM_TOM1_IRQ[4] gtm_icm.gtm_tom1_irq[4] */
    GTM_TOM1_5_IRQn             = 826u, /* GTM_TOM1_IRQ[5] gtm_icm.gtm_tom1_irq[5] */
    GTM_TOM1_6_IRQn             = 827u, /* GTM_TOM1_IRQ[6] gtm_icm.gtm_tom1_irq[6] */
    GTM_TOM1_7_IRQn             = 828u, /* GTM_TOM1_IRQ[7] gtm_icm.gtm_tom1_irq[7] */
    GTM_TOM2_0_IRQn             = 829u, /* GTM_TOM2_IRQ[0] gtm_icm.gtm_tom2_irq[0] */
    GTM_TOM2_1_IRQn             = 830u, /* GTM_TOM2_IRQ[1] gtm_icm.gtm_tom2_irq[1] */
    GTM_TOM2_2_IRQn             = 831u, /* GTM_TOM2_IRQ[2] gtm_icm.gtm_tom2_irq[2] */
    GTM_TOM2_3_IRQn             = 832u, /* GTM_TOM2_IRQ[3] gtm_icm.gtm_tom2_irq[3] */
    GTM_TOM2_4_IRQn             = 833u, /* GTM_TOM2_IRQ[4] gtm_icm.gtm_tom2_irq[4] */
    GTM_TOM2_5_IRQn             = 834u, /* GTM_TOM2_IRQ[5] gtm_icm.gtm_tom2_irq[5] */
    GTM_TOM2_6_IRQn             = 835u, /* GTM_TOM2_IRQ[6] gtm_icm.gtm_tom2_irq[6] */
    GTM_TOM2_7_IRQn             = 836u, /* GTM_TOM2_IRQ[7] gtm_icm.gtm_tom2_irq[7] */
    GTM_ATOM0_0_IRQn            = 837u, /* GTM_ATOM0_IRQ[0] gtm_icm.gtm_atom0_irq[0] */
    GTM_ATOM0_1_IRQn            = 838u, /* GTM_ATOM0_IRQ[1] gtm_icm.gtm_atom0_irq[1] */
    GTM_ATOM0_2_IRQn            = 839u, /* GTM_ATOM0_IRQ[2] gtm_icm.gtm_atom0_irq[2] */
    GTM_ATOM0_3_IRQn            = 840u, /* GTM_ATOM0_IRQ[3] gtm_icm.gtm_atom0_irq[3] */
    GTM_ATOM1_0_IRQn            = 841u, /* GTM_ATOM1_IRQ[0] gtm_icm.gtm_atom1_irq[0] */
    GTM_ATOM1_1_IRQn            = 842u, /* GTM_ATOM1_IRQ[1] gtm_icm.gtm_atom1_irq[1] */
    GTM_ATOM1_2_IRQn            = 843u, /* GTM_ATOM1_IRQ[2] gtm_icm.gtm_atom1_irq[2] */
    GTM_ATOM1_3_IRQn            = 844u, /* GTM_ATOM1_IRQ[3] gtm_icm.gtm_atom1_irq[3] */
    GTM_ATOM2_0_IRQn            = 845u, /* GTM_ATOM2_IRQ[0] gtm_icm.gtm_atom2_irq[0] */
    GTM_ATOM2_1_IRQn            = 846u, /* GTM_ATOM2_IRQ[1] gtm_icm.gtm_atom2_irq[1] */
    GTM_ATOM2_2_IRQn            = 847u, /* GTM_ATOM2_IRQ[2] gtm_icm.gtm_atom2_irq[2] */
    GTM_ATOM2_3_IRQn            = 848u, /* GTM_ATOM2_IRQ[3] gtm_icm.gtm_atom2_irq[3] */
    GTM_ATOM3_0_IRQn            = 849u, /* GTM_ATOM3_IRQ[0] gtm_icm.gtm_atom3_irq[0] */
    GTM_ATOM3_1_IRQn            = 850u, /* GTM_ATOM3_IRQ[1] gtm_icm.gtm_atom3_irq[1] */
    GTM_ATOM3_2_IRQn            = 851u, /* GTM_ATOM3_IRQ[2] gtm_icm.gtm_atom3_irq[2] */
    GTM_ATOM3_3_IRQn            = 852u, /* GTM_ATOM3_IRQ[3] gtm_icm.gtm_atom3_irq[3] */
    GTM_ATOM4_0_IRQn            = 853u, /* GTM_ATOM4_IRQ[0] gtm_icm.gtm_atom4_irq[0] */
    GTM_ATOM4_1_IRQn            = 854u, /* GTM_ATOM4_IRQ[1] gtm_icm.gtm_atom4_irq[1] */
    GTM_ATOM4_2_IRQn            = 855u, /* GTM_ATOM4_IRQ[2] gtm_icm.gtm_atom4_irq[2] */
    GTM_ATOM4_3_IRQn            = 856u, /* GTM_ATOM4_IRQ[3] gtm_icm.gtm_atom4_irq[3] */
    GTM_SPE2_IRQn               = 857u, /* GTM_SPE2_IRQ gtm_icm.gtm_spe2_irq */
    GTM_SPE3_IRQn               = 858u, /* GTM_SPE3_IRQ gtm_icm.gtm_spe3_irq */
    GTM_PSM1_0_IRQn             = 859u, /* GTM_PSM1_IRQ[0] gtm_icm.gtm_psm1_irq[0] */
    GTM_PSM1_1_IRQn             = 860u, /* GTM_PSM1_IRQ[1] gtm_icm.gtm_psm1_irq[1] */
    GTM_PSM1_2_IRQn             = 861u, /* GTM_PSM1_IRQ[2] gtm_icm.gtm_psm1_irq[2] */
    GTM_PSM1_3_IRQn             = 862u, /* GTM_PSM1_IRQ[3] gtm_icm.gtm_psm1_irq[3] */
    GTM_PSM1_4_IRQn             = 863u, /* GTM_PSM1_IRQ[4] gtm_icm.gtm_psm1_irq[4] */
    GTM_PSM1_5_IRQn             = 864u, /* GTM_PSM1_IRQ[5] gtm_icm.gtm_psm1_irq[5] */
    GTM_PSM1_6_IRQn             = 865u, /* GTM_PSM1_IRQ[6] gtm_icm.gtm_psm1_irq[6] */
    GTM_PSM1_7_IRQn             = 866u, /* GTM_PSM1_IRQ[7] gtm_icm.gtm_psm1_irq[7] */
    GTM_TIM4_0_IRQn             = 867u, /* GTM_TIM4_IRQ[0] gtm_icm.gtm_tim4_irq[0] */
    GTM_TIM4_1_IRQn             = 868u, /* GTM_TIM4_IRQ[1] gtm_icm.gtm_tim4_irq[1] */
    GTM_TIM4_2_IRQn             = 869u, /* GTM_TIM4_IRQ[2] gtm_icm.gtm_tim4_irq[2] */
    GTM_TIM4_3_IRQn             = 870u, /* GTM_TIM4_IRQ[3] gtm_icm.gtm_tim4_irq[3] */
    GTM_TIM4_4_IRQn             = 871u, /* GTM_TIM4_IRQ[4] gtm_icm.gtm_tim4_irq[4] */
    GTM_TIM4_5_IRQn             = 872u, /* GTM_TIM4_IRQ[5] gtm_icm.gtm_tim4_irq[5] */
    GTM_TIM4_6_IRQn             = 873u, /* GTM_TIM4_IRQ[6] gtm_icm.gtm_tim4_irq[6] */
    GTM_TIM4_7_IRQn             = 874u, /* GTM_TIM4_IRQ[7] gtm_icm.gtm_tim4_irq[7] */
    GTM_TIM5_0_IRQn             = 875u, /* GTM_TIM5_IRQ[0] gtm_icm.gtm_tim5_irq[0] */
    GTM_TIM5_1_IRQn             = 876u, /* GTM_TIM5_IRQ[1] gtm_icm.gtm_tim5_irq[1] */
    GTM_TIM5_2_IRQn             = 877u, /* GTM_TIM5_IRQ[2] gtm_icm.gtm_tim5_irq[2] */
    GTM_TIM5_3_IRQn             = 878u, /* GTM_TIM5_IRQ[3] gtm_icm.gtm_tim5_irq[3] */
    GTM_TIM5_4_IRQn             = 879u, /* GTM_TIM5_IRQ[4] gtm_icm.gtm_tim5_irq[4] */
    GTM_TIM5_5_IRQn             = 880u, /* GTM_TIM5_IRQ[5] gtm_icm.gtm_tim5_irq[5] */
    GTM_TIM5_6_IRQn             = 881u, /* GTM_TIM5_IRQ[6] gtm_icm.gtm_tim5_irq[6] */
    GTM_TIM5_7_IRQn             = 882u, /* GTM_TIM5_IRQ[7] gtm_icm.gtm_tim5_irq[7] */
    GTM_MCS4_0_IRQn             = 883u, /* GTM_MCS4_IRQ[0] gtm_icm.gtm_mcs4_irq[0] */
    GTM_MCS4_1_IRQn             = 884u, /* GTM_MCS4_IRQ[1] gtm_icm.gtm_mcs4_irq[1] */
    GTM_MCS4_2_IRQn             = 885u, /* GTM_MCS4_IRQ[2] gtm_icm.gtm_mcs4_irq[2] */
    GTM_MCS4_3_IRQn             = 886u, /* GTM_MCS4_IRQ[3] gtm_icm.gtm_mcs4_irq[3] */
    GTM_MCS4_4_IRQn             = 887u, /* GTM_MCS4_IRQ[4] gtm_icm.gtm_mcs4_irq[4] */
    GTM_MCS4_5_IRQn             = 888u, /* GTM_MCS4_IRQ[5] gtm_icm.gtm_mcs4_irq[5] */
    GTM_MCS4_6_IRQn             = 889u, /* GTM_MCS4_IRQ[6] gtm_icm.gtm_mcs4_irq[6] */
    GTM_MCS4_7_IRQn             = 890u, /* GTM_MCS4_IRQ[7] gtm_icm.gtm_mcs4_irq[7] */
    GTM_MCS5_0_IRQn             = 891u, /* GTM_MCS5_IRQ[0] gtm_icm.gtm_mcs5_irq[0] */
    GTM_MCS5_1_IRQn             = 892u, /* GTM_MCS5_IRQ[1] gtm_icm.gtm_mcs5_irq[1] */
    GTM_MCS5_2_IRQn             = 893u, /* GTM_MCS5_IRQ[2] gtm_icm.gtm_mcs5_irq[2] */
    GTM_MCS5_3_IRQn             = 894u, /* GTM_MCS5_IRQ[3] gtm_icm.gtm_mcs5_irq[3] */
    GTM_MCS5_4_IRQn             = 895u, /* GTM_MCS5_IRQ[4] gtm_icm.gtm_mcs5_irq[4] */
    GTM_MCS5_5_IRQn             = 896u, /* GTM_MCS5_IRQ[5] gtm_icm.gtm_mcs5_irq[5] */
    GTM_MCS5_6_IRQn             = 897u, /* GTM_MCS5_IRQ[6] gtm_icm.gtm_mcs5_irq[6] */
    GTM_MCS5_7_IRQn             = 898u, /* GTM_MCS5_IRQ[7] gtm_icm.gtm_mcs5_irq[7] */
    GTM_TOM3_0_IRQn             = 899u, /* GTM_TOM3_IRQ[0] gtm_icm.gtm_tom3_irq[0] */
    GTM_TOM3_1_IRQn             = 900u, /* GTM_TOM3_IRQ[1] gtm_icm.gtm_tom3_irq[1] */
    GTM_TOM3_2_IRQn             = 901u, /* GTM_TOM3_IRQ[2] gtm_icm.gtm_tom3_irq[2] */
    GTM_TOM3_3_IRQn             = 902u, /* GTM_TOM3_IRQ[3] gtm_icm.gtm_tom3_irq[3] */
    GTM_TOM3_4_IRQn             = 903u, /* GTM_TOM3_IRQ[4] gtm_icm.gtm_tom3_irq[4] */
    GTM_TOM3_5_IRQn             = 904u, /* GTM_TOM3_IRQ[5] gtm_icm.gtm_tom3_irq[5] */
    GTM_TOM3_6_IRQn             = 905u, /* GTM_TOM3_IRQ[6] gtm_icm.gtm_tom3_irq[6] */
    GTM_TOM3_7_IRQn             = 906u, /* GTM_TOM3_IRQ[7] gtm_icm.gtm_tom3_irq[7] */
    GTM_TOM4_0_IRQn             = 907u, /* GTM_TOM4_IRQ[0] gtm_icm.gtm_tom4_irq[0] */
    GTM_TOM4_1_IRQn             = 908u, /* GTM_TOM4_IRQ[1] gtm_icm.gtm_tom4_irq[1] */
    GTM_TOM4_2_IRQn             = 909u, /* GTM_TOM4_IRQ[2] gtm_icm.gtm_tom4_irq[2] */
    GTM_TOM4_3_IRQn             = 910u, /* GTM_TOM4_IRQ[3] gtm_icm.gtm_tom4_irq[3] */
    GTM_TOM4_4_IRQn             = 911u, /* GTM_TOM4_IRQ[4] gtm_icm.gtm_tom4_irq[4] */
    GTM_TOM4_5_IRQn             = 912u, /* GTM_TOM4_IRQ[5] gtm_icm.gtm_tom4_irq[5] */
    GTM_TOM4_6_IRQn             = 913u, /* GTM_TOM4_IRQ[6] gtm_icm.gtm_tom4_irq[6] */
    GTM_TOM4_7_IRQn             = 914u, /* GTM_TOM4_IRQ[7] gtm_icm.gtm_tom4_irq[7] */
    GTM_ATOM5_0_IRQn            = 915u, /* GTM_ATOM5_IRQ[0] gtm_icm.gtm_atom5_irq[0] */
    GTM_ATOM5_1_IRQn            = 916u, /* GTM_ATOM5_IRQ[1] gtm_icm.gtm_atom5_irq[1] */
    GTM_ATOM5_2_IRQn            = 917u, /* GTM_ATOM5_IRQ[2] gtm_icm.gtm_atom5_irq[2] */
    GTM_ATOM5_3_IRQn            = 918u, /* GTM_ATOM5_IRQ[3] gtm_icm.gtm_atom5_irq[3] */
    GTM_ATOM6_0_IRQn            = 919u, /* GTM_ATOM6_IRQ[0] gtm_icm.gtm_atom6_irq[0] */
    GTM_ATOM6_1_IRQn            = 920u, /* GTM_ATOM6_IRQ[1] gtm_icm.gtm_atom6_irq[1] */
    GTM_ATOM6_2_IRQn            = 921u, /* GTM_ATOM6_IRQ[2] gtm_icm.gtm_atom6_irq[2] */
    GTM_ATOM6_3_IRQn            = 922u, /* GTM_ATOM6_IRQ[3] gtm_icm.gtm_atom6_irq[3] */
    GTM_ATOM7_0_IRQn            = 923u, /* GTM_ATOM7_IRQ[0] gtm_icm.gtm_atom7_irq[0] */
    GTM_ATOM7_1_IRQn            = 924u, /* GTM_ATOM7_IRQ[1] gtm_icm.gtm_atom7_irq[1] */
    GTM_ATOM7_2_IRQn            = 925u, /* GTM_ATOM7_IRQ[2] gtm_icm.gtm_atom7_irq[2] */
    GTM_ATOM7_3_IRQn            = 926u, /* GTM_ATOM7_IRQ[3] gtm_icm.gtm_atom7_irq[3] */
    DSPI9_DSI_TCF_IRQn          = 927u, /* DSPI9_6 DSPI_9_SR[DSITCF]|DSPI_9_SR[CMD_TFFF] */
    DSPI11_DSI_TCF_IRQn         = 928u, /* DSPI11_6 DSPI_11_SR[DSITCF]|DSPI_11_SR[CMD_TFFF] */
    DSPI13_DSI_TCF_IRQn         = 929u, /* DSPI13_6 DSPI_13_SR[DSITCF]|DSPI_13_SR[CMD_TFFF] */
    DSPI16_DSI_TCF_IRQn         = 930u, /* DSPI16_6 DSPI_16_SR[DSITCF]|DSPI_16_SR[CMD_TFFF] */
    GTM_ERR_IRQn                = 931u, /* GTM_ERR_IRQ gtm_err_irq */
    SIUL_EPORT2_IRQn            = 932u, /* SIUL Eport2 */
    SIUL_EPORT1_IRQn            = 933u, /* SIUL Eport1 */
    SIUL_EPORT0_IRQn            = 934u, /* SIUL Eport0 */
    SD_EMMC_IRQn                = 935u, /* SD EMMC Interrupt */
    SENT1_COMBINED_ERR_IRQn     = 936u, /* SENT_COMBINED_ERR_1 SENT_1_GBL_STATUS[FMDU] | */
    SENT1_COMBINED_SLOW_IRQn    = 937u, /* SENT_COMBINED_SLOW_1 SENT_1_SMSG_RDY[0] | */
    SENT1_COMBINED_FAST_IRQn    = 938u, /* SENT_COMBINED_FAST_1 SENT_1_FMSG_RDY[0] | */
    SENT0_COMBINED_ERR_IRQn     = 939u, /* SENT_COMBINED_ERR_0 SENT_0_GBL_STATUS[FMDU] | */
    SENT0_COMBINED_SLOW_IRQn    = 940u, /* SENT_COMBINED_SLOW_0 SENT_0_SMSG_RDY[0] | */
    SENT0_COMBINED_FAST_IRQn    = 941u, /* SENT_COMBINED_FAST_0 SENT_0_FMSG_RDY[0] | */
    DSPI17_DSI_TCF_IRQn         = 942u, /* DSPI17_6 DSPI_17_SR[DSITCF] | DSPI_17_SR[CMD_TFFF] */
    EMIOS0_CH0_IRQn             = 943u, /* EMIOS0 emios_flag_out__wire[0] */
    EMIOS0_CH1_IRQn             = 944u, /* EMIOS1 emios_flag_out__wire[1] */
    EMIOS0_CH2_IRQn             = 945u, /* EMIOS2 emios_flag_out__wire[2] */
    PSI5_S_MBOX_ERR_SR0_IRQn    = 946u, /* PS_SR_IRQ[0] PS_MBOX_SR_IRQ[0] PS_ERR_SR_IRQ[0] */
    PSI5_S_MBOX_ERR_SR1_IRQn    = 947u, /* PS_SR_IRQ[1] PS_MBOX_SR_IRQ[1] PS_ERR_SR_IRQ[1] */
    PSI5_S_MBOX_ERR_SR2_IRQn    = 948u, /* PS_SR_IRQ[2] PS_MBOX_SR_IRQ[2] PS_ERR_SR_IRQ[2] */
    PSI5_S_MBOX_ERR_SR3_IRQn    = 949u, /* PS_SR_IRQ[3] PS_MBOX_SR_IRQ[3] PS_ERR_SR_IRQ[3] */
    PSI5_S_MBOX_ERR_SR4_IRQn    = 950u, /* PS_SR_IRQ[4] PS_MBOX_SR_IRQ[4] PS_ERR_SR_IRQ[4] */
    PSI5_S_MBOX_ERR_SR5_IRQn    = 951u, /* PS_SR_IRQ[5] PS_MBOX_SR_IRQ[5] PS_ERR_SR_IRQ[5] */
    PSI5_S_MBOX_ERR_SR6_IRQn    = 952u, /* PS_SR_IRQ[6] PS_MBOX_SR_IRQ[6] PS_ERR_SR_IRQ[6] */
    PSI5_S_MBOX_ERR_SR7_IRQn    = 953u, /* PS_SR_IRQ[7] PS_MBOX_SR_IRQ[7] PS_ERR_SR_IRQ[7] */
    PSI5_S_E2SSR1_IRQn          = 954u, /* PSI5_E2SSR[1] */
    PSI5_S_E2SSR2_IRQn          = 955u, /* PSI5_E2SSR[2] */
    PSI5_S_E2SSR3_IRQn          = 956u, /* PSI5_E2SSR[3] */
    PSI5_S_E2SSR4_IRQn          = 957u, /* PSI5_E2SSR[4] */
    PSI5_S_E2SSR5_IRQn          = 958u, /* PSI5_E2SSR[5] */
    PSI5_S_E2SSR6_IRQn          = 959u, /* PSI5_E2SSR[6] */
    PSI5_S_E2SSR7_IRQn          = 960u, /* PSI5_E2SSR[7] */
    PSI5_S_GLSR_IRQn            = 961u, /* PS_GLSR */
    GTM_SPE5_IRQn               = 962u, /* GTM_SPE5_IRQ gtm_icm.gtm_spe5_irq */
    GTM_SPE4_IRQn               = 963u, /* GTM_SPE4_IRQ gtm_icm.gtm_spe4_irq */
    PSI5_S_0_UART_ERR_IRQn      = 964u, /* PSI5_S_0_UART_ERR */
    EQADC01_FIFO_0_IRQn         = 965u, /* EQADC01_FISR0 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC01_FIFO_1_IRQn         = 966u, /* EQADC01_FISR1 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC01_FIFO_2_IRQn         = 967u, /* EQADC01_FISR2 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC01_FIFO_3_IRQn         = 968u, /* EQADC01_FISR3 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC01_FIFO_4_IRQn         = 969u, /* EQADC01_FISR4 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC01_FIFO_5_IRQn         = 970u, /* EQADC01_FISR5 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC23_FIFO_0_IRQn         = 971u, /* EQADC23_FISR0 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC23_FIFO_1_IRQn         = 972u, /* EQADC23_FISR1 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC23_FIFO_2_IRQn         = 973u, /* EQADC23_FISR2 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC23_FIFO_3_IRQn         = 974u, /* EQADC23_FISR3 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC23_FIFO_4_IRQn         = 975u, /* EQADC23_FISR4 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC23_FIFO_5_IRQn         = 976u, /* EQADC23_FISR5 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC45_FIFO_0_IRQn         = 977u, /* EQADC45_FISR0 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC45_FIFO_1_IRQn         = 978u, /* EQADC45_FISR1 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC45_FIFO_2_IRQn         = 979u, /* EQADC45_FISR2 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC45_FIFO_3_IRQn         = 980u, /* EQADC45_FISR3 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC45_FIFO_4_IRQn         = 981u, /* EQADC45_FISR4 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC45_FIFO_5_IRQn         = 982u, /* EQADC45_FISR5 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC67_FIFO_0_IRQn         = 983u, /* EQADC67_FISR0 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC67_FIFO_1_IRQn         = 984u, /* EQADC67_FISR1 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC67_FIFO_2_IRQn         = 985u, /* EQADC67_FISR2 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC67_FIFO_3_IRQn         = 986u, /* EQADC67_FISR3 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC67_FIFO_4_IRQn         = 987u, /* EQADC67_FISR4 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC67_FIFO_5_IRQn         = 988u, /* EQADC67_FISR5 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC89_FIFO_0_IRQn         = 989u, /* EQADC89_FISR0 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC89_FIFO_1_IRQn         = 990u, /* EQADC89_FISR1 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC89_FIFO_2_IRQn         = 991u, /* EQADC89_FISR2 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC89_FIFO_3_IRQn         = 992u, /* EQADC89_FISR3 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC89_FIFO_4_IRQn         = 993u, /* EQADC89_FISR4 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC89_FIFO_5_IRQn         = 994u, /* EQADC89_FISR5 [NCF | PF | EOQF | CFFF | RFDF] */
    EMIOS0_CH3_IRQn             = 995u, /* EMIOS0 emios_flag_out__wire[3] */
    EMIOS0_CH4_IRQn             = 996u, /* EMIOS0 emios_flag_out__wire[4] */
    EMIOS0_CH5_IRQn             = 997u, /* EMIOS0 emios_flag_out__wire[5] */
    EMIOS0_CH6_IRQn             = 998u, /* EMIOS0 emios_flag_out__wire[6] */
    EMIOS0_CH7_IRQn             = 999u, /* EMIOS0 emios_flag_out__wire[7] */
    EMIOS0_CH8_IRQn             = 1000u,/* EMIOS0 emios_flag_out__wire[8] */
    EMIOS0_CH9_IRQn             = 1001u,/* EMIOS0 emios_flag_out__wire[9] */
    EMIOS0_CH10_IRQn            = 1002u,/* EMIOS0 emios_flag_out__wire[10] */
    EMIOS0_CH11_IRQn            = 1003u,/* EMIOS0 emios_flag_out__wire[11] */
    EMIOS0_CH12_IRQn            = 1004u,/* EMIOS0 emios_flag_out__wire[12] */
    EMIOS0_CH13_IRQn            = 1005u,/* EMIOS0 emios_flag_out__wire[13] */
    EMIOS0_CH14_IRQn            = 1006u,/* EMIOS0 emios_flag_out__wire[14] */
    EMIOS0_CH15_IRQn            = 1007u,/* EMIOS0 emios_flag_out__wire[15] */
    EMIOS0_CH16_IRQn            = 1008u,/* EMIOS0 emios_flag_out__wire[16] */
    EMIOS0_CH17_IRQn            = 1009u,/* EMIOS0 emios_flag_out__wire[17] */
    EMIOS0_CH18_IRQn            = 1010u,/* EMIOS0 emios_flag_out__wire[18] */
    EMIOS0_CH19_IRQn            = 1011u,/* EMIOS0 emios_flag_out__wire[19] */
    EMIOS0_CH20_IRQn            = 1012u,/* EMIOS0 emios_flag_out__wire[20] */
    EMIOS0_CH21_IRQn            = 1013u,/* EMIOS0 emios_flag_out__wire[21] */
    EMIOS0_CH22_IRQn            = 1014u,/* EMIOS0 emios_flag_out__wire[22] */
    EMIOS0_CH23_IRQn            = 1015u,/* EMIOS0 emios_flag_out__wire[23] */
    EMIOS0_CH24_IRQn            = 1016u,/* EMIOS0 emios_flag_out__wire[24] */
    EMIOS0_CH25_IRQn            = 1017u,/* EMIOS0 emios_flag_out__wire[25] */
    EMIOS0_CH26_IRQn            = 1018u,/* EMIOS0 emios_flag_out__wire[26] */
    EMIOS0_CH27_IRQn            = 1019u,/* EMIOS0 emios_flag_out__wire[27] */
    EMIOS0_CH28_IRQn            = 1020u,/* EMIOS0 emios_flag_out__wire[28] */
    EMIOS0_CH29_IRQn            = 1021u,/* EMIOS0 emios_flag_out__wire[29] */
    EMIOS0_CH30_IRQn            = 1022u,/* EMIOS0 emios_flag_out__wire[30] */
    EMIOS0_CH31_IRQn            = 1023u,/* EMIOS0 emios_flag_out__wire[31] */
    INTR_ID_BUTT                = 1024u
} IntrId;

/* DSPI module features */
/* On this platform DSPI in extended mode is supported */
#define FEATURE_DSPI_HAS_EXTENDED_MODE 0U

/* Define interrupt vector for dspi */

#ifndef CCFC3012PT
#define FEATURES_DSPI_EOQ_INTERUPT_VECTOR    { DSPI0_EOQF_IRQn, DSPI1_EOQF_IRQn, DSPI2_EOQF_IRQn, DSPI3_EOQF_IRQn,\
                                               DSPI4_EOQF_IRQn, DSPI5_EOQF_IRQn, DSPI6_EOQF_IRQn,DSPI12_EOQF_IRQn}

#define FEATURES_DSPI_SEND_INTERUPT_VECTOR    { DSPI0_TFFF_IRQn, DSPI1_TFFF_IRQn, DSPI2_TFFF_IRQn, DSPI3_TFFF_IRQn,\
                                                 DSPI4_TFFF_IRQn, DSPI5_TFFF_IRQn, DSPI6_TFFF_IRQn,DSPI12_TFFF_IRQn}

#define FEATURES_DSPI_RECEIVE_INTERUPT_VECTOR { DSPI0_RFDF_IRQn, DSPI1_RFDF_IRQn, DSPI2_RFDF_IRQn, DSPI3_RFDF_IRQn, \
                                                DSPI4_RFDF_IRQn, DSPI5_RFDF_IRQn, DSPI6_RFDF_IRQn,DSPI12_RFDF_IRQn}

#define FEATURES_DSPI_FAULT_INTERUPT_VECTOR   { DSPI0_ERR_IRQn, DSPI1_ERR_IRQn, DSPI2_ERR_IRQn,DSPI3_ERR_IRQn, \
                                                 DSPI4_ERR_IRQn, DSPI5_ERR_IRQn, DSPI6_ERR_IRQn, DSPI12_ERR_IRQn}
#else
#define FEATURES_DSPI_EOQ_INTERUPT_VECTOR    { DSPI0_EOQF_IRQn, DSPI1_EOQF_IRQn, DSPI2_EOQF_IRQn, DSPI3_EOQF_IRQn,\
                                               DSPI4_EOQF_IRQn, DSPI5_EOQF_IRQn, DSPI6_EOQF_IRQn, DSPI7_EOQF_IRQn,\
                                               DSPI8_EOQF_IRQn, DSPI9_EOQF_IRQn, DSPI10_EOQF_IRQn,DSPI11_EOQF_IRQn,\
                                               DSPI12_EOQF_IRQn,DSPI13_EOQF_IRQn,DSPI14_EOQF_IRQn,DSPI15_EOQF_IRQn,\
                                               DSPI16_EOQF_IRQn,DSPI17_EOQF_IRQn,DSPI18_EOQF_IRQn,DSPI19_EOQF_IRQn,\
                                               DSPI20_EOQF_IRQn,DSPI21_EOQF_IRQn,}

#define FEATURES_DSPI_SEND_INTERUPT_VECTOR    { DSPI0_TFFF_IRQn, DSPI1_TFFF_IRQn, DSPI2_TFFF_IRQn, DSPI3_TFFF_IRQn,\
                                                DSPI4_TFFF_IRQn, DSPI5_TFFF_IRQn, DSPI6_TFFF_IRQn, DSPI7_TFFF_IRQn,\
                                                DSPI8_TFFF_IRQn, DSPI9_TFFF_IRQn, DSPI10_TFFF_IRQn, DSPI11_TFFF_IRQn,\
                                                DSPI12_TFFF_IRQn, DSPI13_TFFF_IRQn, DSPI14_TFFF_IRQn, DSPI15_TFFF_IRQn,\
                                                DSPI16_TFFF_IRQn, DSPI17_TFFF_IRQn, DSPI18_TFFF_IRQn, DSPI19_TFFF_IRQn,\
                                                DSPI20_TFFF_IRQn, DSPI21_TFFF_IRQn}

#define FEATURES_DSPI_RECEIVE_INTERUPT_VECTOR { DSPI0_RFDF_IRQn, DSPI1_RFDF_IRQn, DSPI2_RFDF_IRQn, DSPI3_RFDF_IRQn, \
                                                DSPI4_RFDF_IRQn, DSPI5_RFDF_IRQn, DSPI6_RFDF_IRQn, DSPI7_RFDF_IRQn, \
                                                DSPI8_RFDF_IRQn, DSPI9_RFDF_IRQn, DSPI10_RFDF_IRQn, DSPI11_RFDF_IRQn,\
                                                DSPI12_RFDF_IRQn, DSPI13_RFDF_IRQn, DSPI14_RFDF_IRQn, DSPI15_RFDF_IRQn,\
                                                DSPI16_RFDF_IRQn, DSPI17_RFDF_IRQn, DSPI18_RFDF_IRQn, DSPI19_RFDF_IRQn,\
                                                DSPI20_RFDF_IRQn, DSPI21_RFDF_IRQn}

#define FEATURES_DSPI_FAULT_INTERUPT_VECTOR   { DSPI0_ERR_IRQn, DSPI1_ERR_IRQn, DSPI2_ERR_IRQn, DSPI3_ERR_IRQn, \
                                                DSPI4_ERR_IRQn, DSPI5_ERR_IRQn, DSPI6_ERR_IRQn, DSPI7_ERR_IRQn, \
                                                DSPI8_ERR_IRQn, DSPI9_ERR_IRQn, DSPI10_ERR_IRQn, DSPI11_ERR_IRQn,\
                                                DSPI12_ERR_IRQn, DSPI13_ERR_IRQn, DSPI14_ERR_IRQn, DSPI15_ERR_IRQn,\
                                                DSPI16_ERR_IRQn, DSPI17_ERR_IRQn, DSPI18_ERR_IRQn, DSPI19_ERR_IRQn,\
                                                DSPI20_ERR_IRQn, DSPI21_ERR_IRQn,}
#endif

typedef enum
{
    /* DMAMUX_0: DMAMUX Channel 0 - 7 (eDMA_0 Channel 0 - 7) */
    DMAMUX0_RESERVED_0_A            = 0U,   /* DMAMUX_0: Source 0  */
    DMAMUX0_ADC01_DECFILT_IN        = 1U,   /* DMAMUX_0: Source 1  */
    DMAMUX0_ADC01_DECFILT_OUT       = 2U,   /* DMAMUX_0: Source 2  */
    DMAMUX0_LINFLEXD_16_TX          = 3U,   /* DMAMUX_0: Source 3  */
    DMAMUX0_ADC_SD_0_EOC            = 4U,   /* DMAMUX_0: Source 4  */
    DMAMUX0_DSPI_0_RX               = 5U,   /* DMAMUX_0: Source 5  */
    DMAMUX0_DSPI_0_TX               = 6U,   /* DMAMUX_0: Source 6  */
    DMAMUX0_DSPI_4_RX               = 7U,   /* DMAMUX_0: Source 7  */
    DMAMUX0_DSPI_4_TX               = 8U,   /* DMAMUX_0: Source 8  */
    DMAMUX0_LINFLEXD_16_RX          = 9U,   /* DMAMUX_0: Source 9  */
    DMAMUX0_ADC45_DECFILT_IN        = 10U,  /* DMAMUX_0: Source 10 */
    DMAMUX0_ADC_SD_3_EOC            = 11U,  /* DMAMUX_0: Source 11 */
    DMAMUX0_MCAN_1                  = 12U,  /* DMAMUX_0: Source 12 */
    DMAMUX0_MCAN_2                  = 13U,  /* DMAMUX_0: Source 13 */
    DMAMUX0_SENT_0_RX_FAST          = 14U,  /* DMAMUX_0: Source 14 */
    DMAMUX0_SENT_0_RX_SLOW          = 15U,  /* DMAMUX_0: Source 15 */
    DMAMUX0_LINFLEXD_0_RX           = 16U,  /* DMAMUX_0: Source 16 */
    DMAMUX0_LINFLEXD_0_TX           = 17U,  /* DMAMUX_0: Source 17 */
    DMAMUX0_LINFLEXD_14_RX          = 18U,  /* DMAMUX_0: Source 18 */
    DMAMUX0_DSPI_0_CMD              = 19U,  /* DMAMUX_0: Source 19 */
    DMAMUX0_DSPI_4_CMD              = 20U,  /* DMAMUX_0: Source 20 */
    DMAMUX0_MCAN_3                  = 21U,  /* DMAMUX_0: Source 21 */
    DMAMUX0_MCAN_4                  = 22U,  /* DMAMUX_0: Source 22 */
    DMAMUX0_MCAN_5                  = 23U,  /* DMAMUX_0: Source 23 */
    DMAMUX0_MCAN_6                  = 24U,  /* DMAMUX_0: Source 24 */
    DMAMUX0_MCAN_7                  = 25U,  /* DMAMUX_0: Source 25 */
    DMAMUX0_MCAN_8                  = 26U,  /* DMAMUX_0: Source 26 */
    DMAMUX0_DSPI_15_TX              = 27U,  /* DMAMUX_0: Source 27 */
    DMAMUX0_DSPI_15_RX              = 28U,  /* DMAMUX_0: Source 28 */
    DMAMUX0_DSPI_15_CMD             = 29U,  /* DMAMUX_0: Source 29 */
    DMAMUX0_DSPI_14_TX              = 30U,  /* DMAMUX_0: Source 30 */
    DMAMUX0_DSPI_14_RX              = 31U,  /* DMAMUX_0: Source 31 */
    DMAMUX0_DSPI_14_CMD             = 32U,  /* DMAMUX_0: Source 32 */
    DMAMUX0_DSPI_13_TX              = 33U,  /* DMAMUX_0: Source 33 */
    DMAMUX0_DSPI_13_RX              = 34U,  /* DMAMUX_0: Source 34 */
    DMAMUX0_DSPI_13_CMD             = 35U,  /* DMAMUX_0: Source 35 */
    DMAMUX0_DSPI_11_TX              = 36U,  /* DMAMUX_0: Source 36 */
    DMAMUX0_DSPI_11_RX              = 37U,  /* DMAMUX_0: Source 37 */
    DMAMUX0_DSPI_11_CMD             = 38U,  /* DMAMUX_0: Source 38 */
    DMAMUX0_DSPI_10_TX              = 39U,  /* DMAMUX_0: Source 39 */
    DMAMUX0_DSPI_10_RX              = 40U,  /* DMAMUX_0: Source 40 */
    DMAMUX0_DSPI_10_CMD             = 41U,  /* DMAMUX_0: Source 41 */
    DMAMUX0_DSPI_9_TX               = 42U,  /* DMAMUX_0: Source 42 */
    DMAMUX0_DSPI_9_RX               = 43U,  /* DMAMUX_0: Source 43 */
    DMAMUX0_DSPI_9_CMD              = 44U,  /* DMAMUX_0: Source 44 */
    DMAMUX0_DSPI_8_TX               = 45U,  /* DMAMUX_0: Source 45 */
    DMAMUX0_DSPI_8_RX               = 46U,  /* DMAMUX_0: Source 46 */
    DMAMUX0_DSPI_8_CMD              = 47U,  /* DMAMUX_0: Source 47 */
    DMAMUX0_DSPI_7_TX               = 48U,  /* DMAMUX_0: Source 48 */
    DMAMUX0_DSPI_7_RX               = 49U,  /* DMAMUX_0: Source 49 */
    DMAMUX0_DSPI_7_CMD              = 50U,  /* DMAMUX_0: Source 50 */
    DMAMUX0_EQADC0_ADC01_RFIFO0     = 51U,  /* DMAMUX_0: Source 51 */
    DMAMUX0_EQADC0_ADC01_RFIFO1     = 52U,  /* DMAMUX_0: Source 52 */
    DMAMUX0_EQADC0_ADC01_RFIFO2     = 53U,  /* DMAMUX_0: Source 53 */
    DMAMUX0_EQADC0_ADC01_RFIFO3     = 54U,  /* DMAMUX_0: Source 54 */
    DMAMUX0_EQADC0_ADC01_RFIFO4     = 55U,  /* DMAMUX_0: Source 55 */
    DMAMUX0_EQADC0_ADC01_RFIFO5     = 56U,  /* DMAMUX_0: Source 56 */
    DMAMUX0_EQADC0_ADC01_CFIFO0     = 57U,  /* DMAMUX_0: Source 57 */
    DMAMUX0_EQADC0_ADC01_CFIFO1     = 58U,  /* DMAMUX_0: Source 58 */
    DMAMUX0_EQADC0_ADC01_CFIFO2     = 59U,  /* DMAMUX_0: Source 59 */
    DMAMUX0_EQADC0_ADC01_CFIFO3     = 60U,  /* DMAMUX_0: Source 60 */
    DMAMUX0_EQADC0_ADC01_CFIFO4     = 61U,  /* DMAMUX_0: Source 61 */
    DMAMUX0_EQADC0_ADC01_CFIFO5     = 62U,  /* DMAMUX_0: Source 62 */
    DMAMUX0_ALWAYS_ON_0             = 63U,  /* DMAMUX_0: Source 63 */

    /* DMAMUX_1: DMAMUX Channel 8 - 15 (eDMA_0 Channel 8 - 15) */
    DMAMUX1_RESERVED_0_A            = 64U,  /* DMAMUX_1: Source 0  */
    DMAMUX1_DSPI_12_RX              = 65U,  /* DMAMUX_1: Source 1  */
    DMAMUX1_DSPI_12_TX              = 66U,  /* DMAMUX_1: Source 2  */
    DMAMUX1_LINFLEXD_0_RX           = 67U,  /* DMAMUX_1: Source 3  */
    DMAMUX1_LINFLEXD_0_TX           = 68U,  /* DMAMUX_1: Source 4  */
    DMAMUX1_LINFLEXD_1_RX           = 69U,  /* DMAMUX_1: Source 5  */
    DMAMUX1_LINFLEXD_1_TX           = 70U,  /* DMAMUX_1: Source 6  */
                                            /* DMAMUX_1: Source 7  */
    DMAMUX1_DSPI_17_TX              = 72U,  /* DMAMUX_1: Source 8  */
    DMAMUX1_SENT_0_RX_FAST          = 73U,  /* DMAMUX_1: Source 9  */
    DMAMUX1_SENT_0_RX_SLOW          = 74U,  /* DMAMUX_1: Source 10 */
                                            /* DMAMUX_1: Source 11 */
                                            /* DMAMUX_1: Source 12 */
                                            /* DMAMUX_1: Source 13 */
                                            /* DMAMUX_1: Source 14 */
                                            /* DMAMUX_1: Source 15 */
                                            /* DMAMUX_1: Source 16 */
    DMAMUX1_GTM_TIM0_IRQ0           = 81U,  /* DMAMUX_1: Source 17 */
    DMAMUX1_GTM_TIM0_IRQ1           = 82U,  /* DMAMUX_1: Source 18 */
    DMAMUX1_GTM_TIM0_IRQ2           = 83U,  /* DMAMUX_1: Source 19 */
    DMAMUX1_GTM_TIM0_IRQ3           = 84U,  /* DMAMUX_1: Source 20 */
    DMAMUX1_GTM_TIM0_IRQ4           = 85U,  /* DMAMUX_1: Source 21 */
    DMAMUX1_GTM_TIM0_IRQ5           = 86U,  /* DMAMUX_1: Source 22 */
    DMAMUX1_GTM_TIM0_IRQ6           = 87U,  /* DMAMUX_1: Source 23 */
    DMAMUX1_GTM_TIM0_IRQ7           = 88U,  /* DMAMUX_1: Source 24 */
    DMAMUX1_GTM_TOM0_IRQ0           = 89U,  /* DMAMUX_1: Source 25 */
    DMAMUX1_GTM_TOM0_IRQ1           = 90U,  /* DMAMUX_1: Source 26 */
    DMAMUX1_GTM_TOM0_IRQ2           = 91U,  /* DMAMUX_1: Source 27 */
    DMAMUX1_GTM_TOM0_IRQ3           = 92U,  /* DMAMUX_1: Source 28 */
    DMAMUX1_GTM_TOM0_IRQ4           = 93U,  /* DMAMUX_1: Source 29 */
    DMAMUX1_GTM_TOM0_IRQ5           = 94U,  /* DMAMUX_1: Source 30 */
    DMAMUX1_GTM_TOM0_IRQ6           = 95U,  /* DMAMUX_1: Source 31 */
    DMAMUX1_GTM_TOM0_IRQ7           = 96U,  /* DMAMUX_1: Source 32 */
    DMAMUX1_GTM_ATOM0_IRQ0          = 97U,  /* DMAMUX_1: Source 33 */
    DMAMUX1_GTM_ATOM0_IRQ1          = 98U,  /* DMAMUX_1: Source 34 */
    DMAMUX1_GTM_ATOM0_IRQ2          = 99U,  /* DMAMUX_1: Source 35 */
    DMAMUX1_GTM_ATOM0_IRQ3          = 100U, /* DMAMUX_1: Source 36 */
    DMAMUX1_GTM_MCS0_IRQ0           = 101U, /* DMAMUX_1: Source 37 */
    DMAMUX1_GTM_MCS0_IRQ1           = 102U, /* DMAMUX_1: Source 38 */
    DMAMUX1_GTM_MCS0_IRQ2           = 103U, /* DMAMUX_1: Source 39 */
    DMAMUX1_GTM_MCS0_IRQ3           = 104U, /* DMAMUX_1: Source 40 */
    DMAMUX1_GTM_MCS0_IRQ4           = 105U, /* DMAMUX_1: Source 41 */
    DMAMUX1_GTM_MCS0_IRQ5           = 106U, /* DMAMUX_1: Source 42 */
    DMAMUX1_GTM_MCS0_IRQ6           = 107U, /* DMAMUX_1: Source 43 */
    DMAMUX1_GTM_MCS0_IRQ7           = 108U, /* DMAMUX_1: Source 44 */
    DMAMUX1_DSPI_17_RX              = 109U, /* DMAMUX_1: Source 45 */
    DMAMUX1_DSPI_17_CMD             = 110U, /* DMAMUX_1: Source 46 */
    DMAMUX1_DSPI_5_RX               = 111U, /* DMAMUX_1: Source 47 */
    DMAMUX1_DSPI_5_TX               = 112U, /* DMAMUX_1: Source 48 */
    DMAMUX1_DSPI_5_CMD              = 113U, /* DMAMUX_1: Source 49 */
    DMAMUX1_DSPI_12_CMD             = 114U, /* DMAMUX_1: Source 50 */
    DMAMUX1_DSPI_16_TX              = 115U, /* DMAMUX_1: Source 51 */
    DMAMUX1_DSPI_16_RX              = 116U, /* DMAMUX_1: Source 52 */
    DMAMUX1_DSPI_0_RX               = 117U, /* DMAMUX_1: Source 53 */
    DMAMUX1_DSPI_0_TX               = 118U, /* DMAMUX_1: Source 54 */
    DMAMUX1_ADC01_DECFILT_IN        = 119U, /* DMAMUX_1: Source 55 */
    DMAMUX1_ADC45_DECFILT_IN        = 120U, /* DMAMUX_1: Source 56 */
    DMAMUX1_ADC_SD_3_EOC            = 121U, /* DMAMUX_1: Source 57 */
    DMAMUX1_DSPI_16_CMD             = 122U, /* DMAMUX_1: Source 58 */
    DMAMUX1_ALWAYS_ON_0             = 123U, /* DMAMUX_1: Source 59 */
    DMAMUX1_ALWAYS_ON_1             = 124U, /* DMAMUX_1: Source 60 */
    DMAMUX1_ALWAYS_ON_2             = 125U, /* DMAMUX_1: Source 61 */
    DMAMUX1_ALWAYS_ON_3             = 126U, /* DMAMUX_1: Source 62 */
    DMAMUX1_ALWAYS_ON_4             = 127U, /* DMAMUX_1: Source 63 */

    /* DMAMUX_2: DMAMUX Channel 16 - 23 (eDMA_0 Channel 16 - 23) */
    DMAMUX2_RESERVED_0_A            = 128U, /* DMAMUX_2: Source 0  */
    DMAMUX2_ADC23_DECFILT_IN        = 129U, /* DMAMUX_2: Source 1  */
    DMAMUX2_ADC_SD_1_EOC            = 130U, /* DMAMUX_2: Source 2  */
    DMAMUX2_DSPI_1_RX               = 131U, /* DMAMUX_2: Source 3  */
    DMAMUX2_DSPI_1_TX               = 132U, /* DMAMUX_2: Source 4  */
    DMAMUX2_SENT_1_RX_FAST          = 133U, /* DMAMUX_2: Source 5  */
    DMAMUX2_SENT_1_RX_SLOW          = 134U, /* DMAMUX_2: Source 6  */
    DMAMUX2_PSI5_0_CH0_RX_PSI5      = 135U, /* DMAMUX_2: Source 7  */
    DMAMUX2_PSI5_0_CH0_RX_SENT      = 136U, /* DMAMUX_2: Source 8  */
                                            /* DMAMUX_2: Source 9  */
                                            /* DMAMUX_2: Source 10 */
    DMAMUX2_GTM_PSM0_IRQ0           = 139U, /* DMAMUX_2: Source 11 */
    DMAMUX2_GTM_PSM0_IRQ1           = 140U, /* DMAMUX_2: Source 12 */
    DMAMUX2_GTM_PSM0_IRQ2           = 141U, /* DMAMUX_2: Source 13 */
    DMAMUX2_GTM_PSM0_IRQ3           = 142U, /* DMAMUX_2: Source 14 */
    DMAMUX2_GTM_TIM1_IRQ0           = 143U, /* DMAMUX_2: Source 15 */
    DMAMUX2_GTM_TIM1_IRQ1           = 144U, /* DMAMUX_2: Source 16 */
    DMAMUX2_GTM_TIM1_IRQ2           = 145U, /* DMAMUX_2: Source 17 */
    DMAMUX2_GTM_TIM1_IRQ3           = 146U, /* DMAMUX_2: Source 18 */
    DMAMUX2_GTM_TOM1_IRQ0           = 147U, /* DMAMUX_2: Source 19 */
    DMAMUX2_GTM_TOM1_IRQ1           = 148U, /* DMAMUX_2: Source 20 */
    DMAMUX2_GTM_TOM1_IRQ2           = 149U, /* DMAMUX_2: Source 21 */
    DMAMUX2_GTM_TOM1_IRQ3           = 150U, /* DMAMUX_2: Source 22 */
    DMAMUX2_GTM_ATOM1_IRQ0          = 151U, /* DMAMUX_2: Source 23 */
    DMAMUX2_GTM_ATOM1_IRQ1          = 152U, /* DMAMUX_2: Source 24 */
    DMAMUX2_GTM_MCS1_IRQ0           = 153U, /* DMAMUX_2: Source 25 */
    DMAMUX2_GTM_MCS1_IRQ1           = 154U, /* DMAMUX_2: Source 26 */
    DMAMUX2_GTM_MCS1_IRQ2           = 155U, /* DMAMUX_2: Source 27 */
    DMAMUX2_GTM_MCS1_IRQ3           = 156U, /* DMAMUX_2: Source 28 */
    DMAMUX2_GTM_TIM2_IRQ0           = 157U, /* DMAMUX_2: Source 29 */
    DMAMUX2_GTM_TIM2_IRQ1           = 158U, /* DMAMUX_2: Source 30 */
    DMAMUX2_GTM_TIM2_IRQ2           = 159U, /* DMAMUX_2: Source 31 */
    DMAMUX2_GTM_TIM2_IRQ3           = 160U, /* DMAMUX_2: Source 32 */
    DMAMUX2_GTM_ATOM2_IRQ0          = 161U, /* DMAMUX_2: Source 33 */
    DMAMUX2_GTM_ATOM2_IRQ1          = 162U, /* DMAMUX_2: Source 34 */
    DMAMUX2_GTM_MCS2_IRQ0           = 163U, /* DMAMUX_2: Source 35 */
    DMAMUX2_GTM_MCS2_IRQ1           = 164U, /* DMAMUX_2: Source 36 */
    DMAMUX2_GTM_MCS2_IRQ2           = 165U, /* DMAMUX_2: Source 37 */
    DMAMUX2_GTM_MCS2_IRQ3           = 166U, /* DMAMUX_2: Source 38 */
    DMAMUX2_GTM_ATOM3_IRQ0          = 167U, /* DMAMUX_2: Source 39 */
    DMAMUX2_GTM_ATOM3_IRQ1          = 168U, /* DMAMUX_2: Source 40 */
    DMAMUX2_ADC_SD_2_EOC            = 169U, /* DMAMUX_2: Source 41 */
    DMAMUX2_DSPI_1_CMD              = 170U, /* DMAMUX_2: Source 42 */
    DMAMUX2_DSPI_2_RX               = 171U, /* DMAMUX_2: Source 43 */
    DMAMUX2_DSPI_2_TX               = 172U, /* DMAMUX_2: Source 44 */
    DMAMUX2_LINFLEXD_2_RX           = 173U, /* DMAMUX_2: Source 45 */
    DMAMUX2_LINFLEXD_2_TX           = 174U, /* DMAMUX_2: Source 46 */
    DMAMUX2_GTM_SPE0                = 175U, /* DMAMUX_2: Source 47 */
    DMAMUX2_GTM_SPE1                = 176U, /* DMAMUX_2: Source 48 */
    DMAMUX2_PSI5_SPS                = 177U, /* DMAMUX_2: Source 49 */
    DMAMUX2_PSI5_SRX                = 178U, /* DMAMUX_2: Source 50 */
    DMAMUX2_EQADC1_ADC23_RFIFO0     = 179U, /* DMAMUX_2: Source 51 */
    DMAMUX2_EQADC1_ADC23_RFIFO1     = 180U, /* DMAMUX_2: Source 52 */
    DMAMUX2_EQADC1_ADC23_RFIFO2     = 181U, /* DMAMUX_2: Source 53 */
    DMAMUX2_EQADC1_ADC23_RFIFO3     = 182U, /* DMAMUX_2: Source 54 */
    DMAMUX2_EQADC1_ADC23_RFIFO4     = 183U, /* DMAMUX_2: Source 55 */
    DMAMUX2_EQADC1_ADC23_RFIFO5     = 184U, /* DMAMUX_2: Source 56 */
    DMAMUX2_EQADC1_ADC23_CFIFO0     = 185U, /* DMAMUX_2: Source 57 */
    DMAMUX2_EQADC1_ADC23_CFIFO1     = 186U, /* DMAMUX_2: Source 58 */
    DMAMUX2_EQADC1_ADC23_CFIFO2     = 187U, /* DMAMUX_2: Source 59 */
    DMAMUX2_EQADC1_ADC23_CFIFO3     = 188U, /* DMAMUX_2: Source 60 */
    DMAMUX2_EQADC1_ADC23_CFIFO4     = 189U, /* DMAMUX_2: Source 61 */
    DMAMUX2_EQADC1_ADC23_CFIFO5     = 190U, /* DMAMUX_2: Source 62 */
    DMAMUX2_ALWAYS_ON_0             = 191U, /* DMAMUX_2: Source 63 */

    /* DMAMUX_3: DMAMUX Channel 24 - 31 (eDMA_0 Channel 24 - 31) */
    DMAMUX3_RESERVED_0_A            = 192U, /* DMAMUX_3: Source 0  */
    DMAMUX3_ADC23_DECFILT_OUT       = 193U, /* DMAMUX_3: Source 1  */
    DMAMUX3_DSPI_2_RX               = 194U, /* DMAMUX_3: Source 2  */
    DMAMUX3_DSPI_2_TX               = 195U, /* DMAMUX_3: Source 3  */
    DMAMUX3_LINFLEXD_2_RX           = 196U, /* DMAMUX_3: Source 4  */
    DMAMUX3_LINFLEXD_2_TX           = 197U, /* DMAMUX_3: Source 5  */
    DMAMUX3_I2C_0_RX                = 198U, /* DMAMUX_3: Source 6  */
    DMAMUX3_I2C_0_TX                = 199U, /* DMAMUX_3: Source 7  */
    DMAMUX3_PSI5_1_CH0_RX_PSI5      = 200U, /* DMAMUX_3: Source 8  */
    DMAMUX3_PSI5_1_CH0_RX_SENT      = 201U, /* DMAMUX_3: Source 9  */
                                            /* DMAMUX_3: Source 10 */
    DMAMUX3_GTM_PSM0_IRQ4           = 203U, /* DMAMUX_3: Source 11 */
    DMAMUX3_GTM_PSM0_IRQ5           = 204U, /* DMAMUX_3: Source 12 */
    DMAMUX3_GTM_PSM0_IRQ6           = 205U, /* DMAMUX_3: Source 13 */
    DMAMUX3_GTM_PSM0_IRQ7           = 206U, /* DMAMUX_3: Source 14 */
    DMAMUX3_GTM_TIM1_IRQ4           = 207U, /* DMAMUX_3: Source 15 */
    DMAMUX3_GTM_TIM1_IRQ5           = 208U, /* DMAMUX_3: Source 16 */
    DMAMUX3_GTM_TIM1_IRQ6           = 209U, /* DMAMUX_3: Source 17 */
    DMAMUX3_GTM_TIM1_IRQ7           = 210U, /* DMAMUX_3: Source 18 */
    DMAMUX3_GTM_TOM1_IRQ4           = 211U, /* DMAMUX_3: Source 19 */
    DMAMUX3_GTM_TOM1_IRQ5           = 212U, /* DMAMUX_3: Source 20 */
    DMAMUX3_GTM_TOM1_IRQ6           = 213U, /* DMAMUX_3: Source 21 */
    DMAMUX3_GTM_TOM1_IRQ7           = 214U, /* DMAMUX_3: Source 22 */
    DMAMUX3_GTM_ATOM1_IRQ2          = 215U, /* DMAMUX_3: Source 23 */
    DMAMUX3_GTM_ATOM1_IRQ3          = 216U, /* DMAMUX_3: Source 24 */
    DMAMUX3_GTM_MCS1_IRQ4           = 217U, /* DMAMUX_3: Source 25 */
    DMAMUX3_GTM_MCS1_IRQ5           = 218U, /* DMAMUX_3: Source 26 */
    DMAMUX3_GTM_MCS1_IRQ6           = 219U, /* DMAMUX_3: Source 27 */
    DMAMUX3_GTM_MCS1_IRQ7           = 220U, /* DMAMUX_3: Source 28 */
    DMAMUX3_GTM_TIM2_IRQ4           = 221U, /* DMAMUX_3: Source 29 */
    DMAMUX3_GTM_TIM2_IRQ5           = 222U, /* DMAMUX_3: Source 30 */
    DMAMUX3_GTM_TIM2_IRQ6           = 223U, /* DMAMUX_3: Source 31 */
    DMAMUX3_GTM_TIM2_IRQ7           = 224U, /* DMAMUX_3: Source 32 */
    DMAMUX3_GTM_ATOM2_IRQ2          = 225U, /* DMAMUX_3: Source 33 */
    DMAMUX3_GTM_ATOM2_IRQ3          = 226U, /* DMAMUX_3: Source 34 */
    DMAMUX3_GTM_MCS2_IRQ4           = 227U, /* DMAMUX_3: Source 35 */
    DMAMUX3_GTM_MCS2_IRQ5           = 228U, /* DMAMUX_3: Source 36 */
    DMAMUX3_GTM_MCS2_IRQ6           = 229U, /* DMAMUX_3: Source 37 */
    DMAMUX3_GTM_MCS2_IRQ7           = 230U, /* DMAMUX_3: Source 38 */
    DMAMUX3_GTM_ATOM3_IRQ2          = 231U, /* DMAMUX_3: Source 39 */
    DMAMUX3_GTM_ATOM3_IRQ3          = 232U, /* DMAMUX_3: Source 40 */
                                            /* DMAMUX_3: Source 41 */
                                            /* DMAMUX_3: Source 42 */
    DMAMUX3_ADC_SD_3_EOC            = 235U, /* DMAMUX_3: Source 43 */
    DMAMUX3_ADC67_DECFILT_IN        = 236U, /* DMAMUX_3: Source 44 */
    DMAMUX3_DSPI_2_CMD              = 237U, /* DMAMUX_3: Source 45 */
    DMAMUX3_DSPI_1_RX               = 238U, /* DMAMUX_3: Source 46 */
    DMAMUX3_DSPI_1_TX               = 239U, /* DMAMUX_3: Source 47 */
    DMAMUX3_ADC23_DECFILT_IN        = 240U, /* DMAMUX_3: Source 48 */
    DMAMUX3_ADC_SD_2_EOC            = 241U, /* DMAMUX_3: Source 49 */
    DMAMUX3_PSI5_STX                = 242U, /* DMAMUX_3: Source 50 */
    DMAMUX3_EQADC2_ADC45_RFIFO0     = 243U, /* DMAMUX_3: Source 51 */
    DMAMUX3_EQADC2_ADC45_RFIFO1     = 244U, /* DMAMUX_3: Source 52 */
    DMAMUX3_EQADC2_ADC45_RFIFO2     = 245U, /* DMAMUX_3: Source 53 */
    DMAMUX3_EQADC2_ADC45_RFIFO3     = 246U, /* DMAMUX_3: Source 54 */
    DMAMUX3_EQADC2_ADC45_RFIFO4     = 247U, /* DMAMUX_3: Source 55 */
    DMAMUX3_EQADC2_ADC45_RFIFO5     = 248U, /* DMAMUX_3: Source 56 */
    DMAMUX3_EQADC2_ADC45_CFIFO0     = 249U, /* DMAMUX_3: Source 57 */
    DMAMUX3_EQADC2_ADC45_CFIFO1     = 250U, /* DMAMUX_3: Source 58 */
    DMAMUX3_EQADC2_ADC45_CFIFO2     = 251U, /* DMAMUX_3: Source 59 */
    DMAMUX3_EQADC2_ADC45_CFIFO3     = 252U, /* DMAMUX_3: Source 60 */
    DMAMUX3_EQADC2_ADC45_CFIFO4     = 253U, /* DMAMUX_3: Source 61 */
    DMAMUX3_EQADC2_ADC45_CFIFO5     = 254U, /* DMAMUX_3: Source 62 */
    DMAMUX3_ALWAYS_ON_0             = 255U, /* DMAMUX_3: Source 63 */

    /* DMAMUX_4: DMAMUX Channel 32 - 47 (eDMA_0 Channel 32 - 47) */
    DMAMUX4_RESERVED_0_A            = 256U, /* DMAMUX_4: Source 0  */
    DMAMUX4_ADC45_DECFILT_IN        = 257U, /* DMAMUX_4: Source 1  */
    DMAMUX4_ADC67_DECFILT_IN        = 258U, /* DMAMUX_4: Source 2  */
    DMAMUX4_ADC_SD_2_EOC            = 259U, /* DMAMUX_4: Source 3  */
    DMAMUX4_ADC_SD_3_EOC            = 260U, /* DMAMUX_4: Source 4  */
    DMAMUX4_DSPI_3_RX               = 261U, /* DMAMUX_4: Source 5  */
    DMAMUX4_DSPI_3_TX               = 262U, /* DMAMUX_4: Source 6  */
    DMAMUX4_LINFLEXD_0_RX           = 263U, /* DMAMUX_4: Source 7  */
    DMAMUX4_LINFLEXD_0_TX           = 264U, /* DMAMUX_4: Source 8  */
    DMAMUX4_LINFLEXD_15_TX          = 265U, /* DMAMUX_4: Source 9  */
    DMAMUX4_LINFLEXD_14_TX          = 266U, /* DMAMUX_4: Source 10 */
    DMAMUX4_PSI5_0_CH1_RX_PSI5      = 267U, /* DMAMUX_4: Source 11 */
    DMAMUX4_PSI5_0_CH1_RX_SENT      = 268U, /* DMAMUX_4: Source 12 */
                                            /* DMAMUX_4: Source 13 */
                                            /* DMAMUX_4: Source 14 */
                                            /* DMAMUX_4: Source 15 */
    DMAMUX4_GTM_TIM0_IRQ0           = 272U, /* DMAMUX_4: Source 16 */
    DMAMUX4_GTM_TIM0_IRQ1           = 273U, /* DMAMUX_4: Source 17 */
    DMAMUX4_GTM_TOM0_IRQ0           = 274U, /* DMAMUX_4: Source 18 */
    DMAMUX4_GTM_TOM0_IRQ1           = 275U, /* DMAMUX_4: Source 19 */
    DMAMUX4_GTM_PSM0_IRQ0           = 276U, /* DMAMUX_4: Source 20 */
    DMAMUX4_GTM_PSM0_IRQ1           = 277U, /* DMAMUX_4: Source 21 */
    DMAMUX4_GTM_PSM0_IRQ2           = 278U, /* DMAMUX_4: Source 22 */
    DMAMUX4_GTM_PSM0_IRQ3           = 279U, /* DMAMUX_4: Source 23 */
    DMAMUX4_GTM_TOM1_IRQ0           = 280U, /* DMAMUX_4: Source 24 */
    DMAMUX4_GTM_TOM1_IRQ1           = 281U, /* DMAMUX_4: Source 25 */
    DMAMUX4_GTM_TIM3_IRQ0           = 282U, /* DMAMUX_4: Source 26 */
    DMAMUX4_GTM_TIM3_IRQ1           = 283U, /* DMAMUX_4: Source 27 */
    DMAMUX4_GTM_TIM3_IRQ2           = 284U, /* DMAMUX_4: Source 28 */
    DMAMUX4_GTM_TIM3_IRQ3           = 285U, /* DMAMUX_4: Source 29 */
    DMAMUX4_GTM_MCS3_IRQ0           = 286U, /* DMAMUX_4: Source 30 */
    DMAMUX4_GTM_MCS3_IRQ1           = 287U, /* DMAMUX_4: Source 31 */
    DMAMUX4_GTM_MCS3_IRQ2           = 288U, /* DMAMUX_4: Source 32 */
    DMAMUX4_GTM_MCS3_IRQ3           = 289U, /* DMAMUX_4: Source 33 */
    DMAMUX4_DSPI_3_CMD              = 290U, /* DMAMUX_4: Source 34 */
    DMAMUX4_ADC_SD_1_EOC            = 291U, /* DMAMUX_4: Source 35 */
    DMAMUX4_ADC_SD_4_EOC            = 292U, /* DMAMUX_4: Source 36 */
    DMAMUX4_ADC_SD_5_EOC            = 293U, /* DMAMUX_4: Source 37 */
    DMAMUX4_ADC01_DECFILT_IN        = 294U, /* DMAMUX_4: Source 38 */
    DMAMUX4_DSPI_0_CMD              = 295U, /* DMAMUX_4: Source 39 */
    DMAMUX4_DSPI_0_RX               = 296U, /* DMAMUX_4: Source 40 */
    DMAMUX4_DSPI_0_TX               = 297U, /* DMAMUX_4: Source 41 */
    DMAMUX4_AMU_0                   = 298U, /* DMAMUX_4: Source 42 */
    DMAMUX4_MCAN_5                  = 299U, /* DMAMUX_4: Source 43 */
    DMAMUX4_MCAN_6                  = 300U, /* DMAMUX_4: Source 44 */
                                            /* DMAMUX_4: Source 45 */
                                            /* DMAMUX_4: Source 46 */
                                            /* DMAMUX_4: Source 47 */
                                            /* DMAMUX_4: Source 48 */
                                            /* DMAMUX_4: Source 49 */
                                            /* DMAMUX_4: Source 50 */
    DMAMUX4_EQADC3_ADC67_RFIFO0     = 307U, /* DMAMUX_4: Source 51 */
    DMAMUX4_EQADC3_ADC67_RFIFO1     = 308U, /* DMAMUX_4: Source 52 */
    DMAMUX4_EQADC3_ADC67_RFIFO2     = 309U, /* DMAMUX_4: Source 53 */
    DMAMUX4_EQADC3_ADC67_RFIFO3     = 310U, /* DMAMUX_4: Source 54 */
    DMAMUX4_EQADC3_ADC67_RFIFO4     = 311U, /* DMAMUX_4: Source 55 */
    DMAMUX4_EQADC3_ADC67_RFIFO5     = 312U, /* DMAMUX_4: Source 56 */
    DMAMUX4_EQADC3_ADC67_CFIFO0     = 313U, /* DMAMUX_4: Source 57 */
    DMAMUX4_EQADC3_ADC67_CFIFO1     = 314U, /* DMAMUX_4: Source 58 */
    DMAMUX4_EQADC3_ADC67_CFIFO2     = 315U, /* DMAMUX_4: Source 59 */
    DMAMUX4_EQADC3_ADC67_CFIFO3     = 316U, /* DMAMUX_4: Source 60 */
    DMAMUX4_EQADC3_ADC67_CFIFO4     = 317U, /* DMAMUX_4: Source 61 */
    DMAMUX4_EQADC3_ADC67_CFIFO5     = 318U, /* DMAMUX_4: Source 62 */
    DMAMUX4_ALWAYS_ON_0             = 319U, /* DMAMUX_4: Source 63 */

    /* DMAMUX_5: DMAMUX Channel 48 - 63 (eDMA_0 Channel 48 - 63) */
    DMAMUX5_RESERVED_0_A            = 320U, /* DMAMUX_5: Source 0  */
    DMAMUX5_ADC67_DECFILT_OUT       = 321U, /* DMAMUX_5: Source 1  */
    DMAMUX5_ADC_SD_4_EOC            = 322U, /* DMAMUX_5: Source 2  */
    DMAMUX5_ADC_SD_5_EOC            = 323U, /* DMAMUX_5: Source 3  */
    DMAMUX5_DSPI_5_RX               = 324U, /* DMAMUX_5: Source 4  */
    DMAMUX5_DSPI_5_TX               = 325U, /* DMAMUX_5: Source 5  */
    DMAMUX5_LINFLEXD_1_RX           = 326U, /* DMAMUX_5: Source 6  */
    DMAMUX5_LINFLEXD_1_TX           = 327U, /* DMAMUX_5: Source 7  */
    DMAMUX5_LINFLEXD_15_RX          = 328U, /* DMAMUX_5: Source 8  */
    DMAMUX5_DSPI_18_TX              = 329U, /* DMAMUX_5: Source 9  */
    DMAMUX5_SENT_0_RX_FAST          = 330U, /* DMAMUX_5: Source 10 */
    DMAMUX5_SENT_0_RX_SLOW          = 331U, /* DMAMUX_5: Source 11 */
                                            /* DMAMUX_5: Source 12 */
                                            /* DMAMUX_5: Source 13 */
                                            /* DMAMUX_5: Source 14 */
    DMAMUX5_GTM_TIM0_IRQ2           = 335U, /* DMAMUX_5: Source 15 */
    DMAMUX5_GTM_TIM0_IRQ3           = 336U, /* DMAMUX_5: Source 16 */
    DMAMUX5_GTM_TOM0_IRQ4           = 337U, /* DMAMUX_5: Source 17 */
    DMAMUX5_GTM_TOM0_IRQ5           = 338U, /* DMAMUX_5: Source 18 */
    DMAMUX5_GTM_PSM0_IRQ4           = 339U, /* DMAMUX_5: Source 19 */
    DMAMUX5_GTM_PSM0_IRQ5           = 340U, /* DMAMUX_5: Source 20 */
    DMAMUX5_GTM_PSM0_IRQ6           = 341U, /* DMAMUX_5: Source 21 */
    DMAMUX5_GTM_PSM0_IRQ7           = 342U, /* DMAMUX_5: Source 22 */
    DMAMUX5_GTM_TOM1_IRQ4           = 343U, /* DMAMUX_5: Source 23 */
    DMAMUX5_GTM_TOM1_IRQ5           = 344U, /* DMAMUX_5: Source 24 */
    DMAMUX5_GTM_TIM3_IRQ4           = 345U, /* DMAMUX_5: Source 25 */
    DMAMUX5_GTM_TIM3_IRQ5           = 346U, /* DMAMUX_5: Source 26 */
    DMAMUX5_GTM_TIM3_IRQ6           = 347U, /* DMAMUX_5: Source 27 */
    DMAMUX5_GTM_TIM3_IRQ7           = 348U, /* DMAMUX_5: Source 28 */
    DMAMUX5_GTM_MCS3_IRQ4           = 349U, /* DMAMUX_5: Source 29 */
    DMAMUX5_GTM_MCS3_IRQ5           = 350U, /* DMAMUX_5: Source 30 */
    DMAMUX5_GTM_MCS3_IRQ6           = 351U, /* DMAMUX_5: Source 31 */
    DMAMUX5_GTM_MCS3_IRQ7           = 352U, /* DMAMUX_5: Source 32 */
    DMAMUX5_DSPI_5_CMD              = 353U, /* DMAMUX_5: Source 33 */
    DMAMUX5_MCAN_1                  = 354U, /* DMAMUX_5: Source 34 */
    DMAMUX5_MCAN_2                  = 355U, /* DMAMUX_5: Source 35 */
    DMAMUX5_DSPI_3_RX               = 356U, /* DMAMUX_5: Source 36 */
    DMAMUX5_DSPI_3_TX               = 357U, /* DMAMUX_5: Source 37 */
    DMAMUX5_ADC23_DECFILT_OUT       = 358U, /* DMAMUX_5: Source 38 */
    DMAMUX5_LINFLEXD_2_RX           = 359U, /* DMAMUX_5: Source 39 */
    DMAMUX5_LINFLEXD_2_TX           = 360U, /* DMAMUX_5: Source 40 */
    DMAMUX5_ADC01_DECFILT_OUT       = 361U, /* DMAMUX_5: Source 41 */
    DMAMUX5_AMU_1                   = 362U, /* DMAMUX_5: Source 42 */
    DMAMUX5_MCAN_7                  = 363U, /* DMAMUX_5: Source 43 */
    DMAMUX5_MCAN_8                  = 364U, /* DMAMUX_5: Source 44 */
    DMAMUX5_MCAN_9                  = 365U, /* DMAMUX_5: Source 45 */
    DMAMUX5_MCAN_10                 = 366U, /* DMAMUX_5: Source 46 */
    DMAMUX5_MCAN_11                 = 367U, /* DMAMUX_5: Source 47 */
    DMAMUX5_MCAN_12                 = 368U, /* DMAMUX_5: Source 48 */
    DMAMUX5_DSPI_18_RX              = 369U, /* DMAMUX_5: Source 49 */
    DMAMUX5_DSPI_18_CMD             = 370U, /* DMAMUX_5: Source 50 */
    DMAMUX5_EQADC4_ADC89_RFIFO0     = 371U, /* DMAMUX_5: Source 51 */
    DMAMUX5_EQADC4_ADC89_RFIFO1     = 372U, /* DMAMUX_5: Source 52 */
    DMAMUX5_EQADC4_ADC89_RFIFO2     = 373U, /* DMAMUX_5: Source 53 */
    DMAMUX5_EQADC4_ADC89_RFIFO3     = 374U, /* DMAMUX_5: Source 54 */
    DMAMUX5_EQADC4_ADC89_RFIFO4     = 375U, /* DMAMUX_5: Source 55 */
    DMAMUX5_EQADC4_ADC89_RFIFO5     = 376U, /* DMAMUX_5: Source 56 */
    DMAMUX5_EQADC4_ADC89_CFIFO0     = 377U, /* DMAMUX_5: Source 57 */
    DMAMUX5_EQADC4_ADC89_CFIFO1     = 378U, /* DMAMUX_5: Source 58 */
    DMAMUX5_EQADC4_ADC89_CFIFO2     = 379U, /* DMAMUX_5: Source 59 */
    DMAMUX5_EQADC4_ADC89_CFIFO3     = 380U, /* DMAMUX_5: Source 60 */
    DMAMUX5_EQADC4_ADC89_CFIFO4     = 381U, /* DMAMUX_5: Source 61 */
    DMAMUX5_EQADC4_ADC89_CFIFO5     = 382U, /* DMAMUX_5: Source 62 */
    DMAMUX5_ALWAYS_ON_0             = 383U, /* DMAMUX_5: Source 63 */

    /* DMAMUX_6: DMAMUX Channel 64 - 79 (eDMA_1 Channel 0 - 15) */
    DMAMUX6_RESERVED_0_A            = 384U, /* DMAMUX_6: Source 0  */
    DMAMUX6_ADC89_DECFILT_IN        = 385U, /* DMAMUX_6: Source 1  */
    DMAMUX6_ADC89_DECFILT_OUT       = 386U, /* DMAMUX_6: Source 2  */
                                            /* DMAMUX_6: Source 3  */
    DMAMUX6_ADC45_DECFILT_OUT       = 388U, /* DMAMUX_6: Source 4  */
    DMAMUX6_ADC_SD_6_EOC            = 389U, /* DMAMUX_6: Source 5  */
    DMAMUX6_ADC_SD_7_EOC            = 390U, /* DMAMUX_6: Source 6  */
    DMAMUX6_ADC_SD_8_EOC            = 391U, /* DMAMUX_6: Source 7  */
    DMAMUX6_ADC_SD_9_EOC            = 392U, /* DMAMUX_6: Source 8  */
    DMAMUX6_PSI5_0_CH2_RX_PSI5      = 393U, /* DMAMUX_6: Source 9  */
    DMAMUX6_PSI5_0_CH2_RX_SENT      = 394U, /* DMAMUX_6: Source 10 */
                                            /* DMAMUX_6: Source 11 */
                                            /* DMAMUX_6: Source 12 */
    DMAMUX6_DSPI_6_RX               = 397U, /* DMAMUX_6: Source 13 */
    DMAMUX6_DSPI_6_TX               = 398U, /* DMAMUX_6: Source 14 */
    DMAMUX6_DSPI_6_CMD              = 399U, /* DMAMUX_6: Source 15 */
    DMAMUX6_DSPI_19_RX              = 400U, /* DMAMUX_6: Source 16 */
    DMAMUX6_DSPI_19_CMD             = 401U, /* DMAMUX_6: Source 17 */
    DMAMUX6_I2C_1_RX                = 402U, /* DMAMUX_6: Source 18 */
    DMAMUX6_I2C_1_TX                = 403U, /* DMAMUX_6: Source 19 */
    DMAMUX6_GTM_PSM1_IRQ0           = 404U, /* DMAMUX_6: Source 20 */
    DMAMUX6_GTM_PSM1_IRQ1           = 405U, /* DMAMUX_6: Source 21 */
    DMAMUX6_GTM_PSM1_IRQ2           = 406U, /* DMAMUX_6: Source 22 */
    DMAMUX6_GTM_PSM1_IRQ3           = 407U, /* DMAMUX_6: Source 23 */
    DMAMUX6_DSPI_1_CMD              = 408U, /* DMAMUX_6: Source 24 */
    DMAMUX6_DSPI_1_RX               = 409U, /* DMAMUX_6: Source 25 */
    DMAMUX6_DSPI_1_TX               = 410U, /* DMAMUX_6: Source 26 */
    DMAMUX6_DSPI_12_CMD             = 411U, /* DMAMUX_6: Source 27 */
    DMAMUX6_DSPI_12_RX              = 412U, /* DMAMUX_6: Source 28 */
    DMAMUX6_DSPI_12_TX              = 413U, /* DMAMUX_6: Source 29 */
    DMAMUX6_SENT_1_RX_FAST          = 414U, /* DMAMUX_6: Source 30 */
    DMAMUX6_SENT_1_RX_SLOW          = 415U, /* DMAMUX_6: Source 31 */
    DMAMUX6_GTM_TOM1_IRQ0           = 416U, /* DMAMUX_6: Source 32 */
    DMAMUX6_GTM_TOM1_IRQ1           = 417U, /* DMAMUX_6: Source 33 */
    DMAMUX6_GTM_TOM1_IRQ2           = 418U, /* DMAMUX_6: Source 34 */
    DMAMUX6_GTM_TOM1_IRQ3           = 419U, /* DMAMUX_6: Source 35 */
    DMAMUX6_GTM_TOM1_IRQ4           = 420U, /* DMAMUX_6: Source 36 */
    DMAMUX6_GTM_TOM1_IRQ5           = 421U, /* DMAMUX_6: Source 37 */
    DMAMUX6_GTM_TOM1_IRQ6           = 422U, /* DMAMUX_6: Source 38 */
    DMAMUX6_GTM_TOM1_IRQ7           = 423U, /* DMAMUX_6: Source 39 */
    DMAMUX6_GTM_TOM2_IRQ0           = 424U, /* DMAMUX_6: Source 40 */
    DMAMUX6_GTM_TOM2_IRQ1           = 425U, /* DMAMUX_6: Source 41 */
    DMAMUX6_GTM_TOM2_IRQ2           = 426U, /* DMAMUX_6: Source 42 */
    DMAMUX6_GTM_TOM2_IRQ3           = 427U, /* DMAMUX_6: Source 43 */
    DMAMUX6_GTM_TOM2_IRQ4           = 428U, /* DMAMUX_6: Source 44 */
    DMAMUX6_GTM_TOM2_IRQ5           = 429U, /* DMAMUX_6: Source 45 */
    DMAMUX6_GTM_TOM2_IRQ6           = 430U, /* DMAMUX_6: Source 46 */
    DMAMUX6_GTM_TOM2_IRQ7           = 431U, /* DMAMUX_6: Source 47 */
    DMAMUX6_MCAN_3                  = 432U, /* DMAMUX_6: Source 48 */
                                            /* DMAMUX_6: Source 49 */
                                            /* DMAMUX_6: Source 50 */
                                            /* DMAMUX_6: Source 51 */
                                            /* DMAMUX_6: Source 52 */
                                            /* DMAMUX_6: Source 53 */
                                            /* DMAMUX_6: Source 54 */
                                            /* DMAMUX_6: Source 55 */
                                            /* DMAMUX_6: Source 56 */
    DMAMUX6_SPORT_A                 = 441U, /* DMAMUX_6: Source 57 */
    DMAMUX6_SPORT_B                 = 442U, /* DMAMUX_6: Source 58 */
                                            /* DMAMUX_6: Source 59 */
                                            /* DMAMUX_6: Source 60 */
                                            /* DMAMUX_6: Source 61 */
    DMAMUX6_DSPI_19_TX              = 446U, /* DMAMUX_6: Source 62 */
    DMAMUX6_ALWAYS_ON_0             = 447U, /* DMAMUX_6: Source 63 */

    /* DMAMUX_7: DMAMUX Channel 80 - 95 (eDMA_1 Channel 16 - 31) */
    DMAMUX7_RESERVED_0_A            = 448U, /* DMAMUX_7: Source 0  */
    DMAMUX7_GTM_MCS4_IRQ0           = 449U, /* DMAMUX_7: Source 1  */
    DMAMUX7_GTM_MCS4_IRQ1           = 450U, /* DMAMUX_7: Source 2  */
    DMAMUX7_GTM_MCS4_IRQ2           = 451U, /* DMAMUX_7: Source 3  */
    DMAMUX7_GTM_MCS4_IRQ3           = 452U, /* DMAMUX_7: Source 4  */
    DMAMUX7_GTM_MCS4_IRQ4           = 453U, /* DMAMUX_7: Source 5  */
    DMAMUX7_GTM_MCS4_IRQ5           = 454U, /* DMAMUX_7: Source 6  */
    DMAMUX7_GTM_MCS4_IRQ6           = 455U, /* DMAMUX_7: Source 7  */
    DMAMUX7_GTM_MCS4_IRQ7           = 456U, /* DMAMUX_7: Source 8  */
    DMAMUX7_GTM_MCS5_IRQ0           = 457U, /* DMAMUX_7: Source 9  */
    DMAMUX7_GTM_MCS5_IRQ1           = 458U, /* DMAMUX_7: Source 10 */
    DMAMUX7_GTM_MCS5_IRQ2           = 459U, /* DMAMUX_7: Source 11 */
    DMAMUX7_GTM_MCS5_IRQ3           = 460U, /* DMAMUX_7: Source 12 */
    DMAMUX7_GTM_MCS5_IRQ4           = 461U, /* DMAMUX_7: Source 13 */
    DMAMUX7_GTM_MCS5_IRQ5           = 462U, /* DMAMUX_7: Source 14 */
    DMAMUX7_GTM_MCS5_IRQ6           = 463U, /* DMAMUX_7: Source 15 */
    DMAMUX7_GTM_MCS5_IRQ7           = 464U, /* DMAMUX_7: Source 16 */
    DMAMUX7_GTM_ATOM5_IRQ0          = 465U, /* DMAMUX_7: Source 17 */
    DMAMUX7_GTM_ATOM5_IRQ1          = 466U, /* DMAMUX_7: Source 18 */
    DMAMUX7_GTM_ATOM5_IRQ2          = 467U, /* DMAMUX_7: Source 19 */
    DMAMUX7_GTM_ATOM5_IRQ3          = 468U, /* DMAMUX_7: Source 20 */
    DMAMUX7_GTM_ATOM6_IRQ0          = 469U, /* DMAMUX_7: Source 21 */
    DMAMUX7_GTM_ATOM6_IRQ1          = 470U, /* DMAMUX_7: Source 22 */
    DMAMUX7_GTM_ATOM6_IRQ2          = 471U, /* DMAMUX_7: Source 23 */
    DMAMUX7_GTM_ATOM6_IRQ3          = 472U, /* DMAMUX_7: Source 24 */
    DMAMUX7_GTM_TOM3_IRQ0           = 473U, /* DMAMUX_7: Source 25 */
    DMAMUX7_GTM_TOM3_IRQ1           = 474U, /* DMAMUX_7: Source 26 */
    DMAMUX7_GTM_TOM3_IRQ2           = 475U, /* DMAMUX_7: Source 27 */
    DMAMUX7_GTM_TOM3_IRQ3           = 476U, /* DMAMUX_7: Source 28 */
    DMAMUX7_GTM_TOM3_IRQ4           = 477U, /* DMAMUX_7: Source 29 */
    DMAMUX7_GTM_TOM3_IRQ5           = 478U, /* DMAMUX_7: Source 30 */
    DMAMUX7_GTM_TOM3_IRQ6           = 479U, /* DMAMUX_7: Source 31 */
    DMAMUX7_GTM_TOM3_IRQ7           = 480U, /* DMAMUX_7: Source 32 */
    DMAMUX7_ADC_SD_6_EOC            = 481U, /* DMAMUX_7: Source 33 */
    DMAMUX7_ADC_SD_7_EOC            = 482U, /* DMAMUX_7: Source 34 */
    DMAMUX7_PSI5_0_CH0_RX_PSI5      = 483U, /* DMAMUX_7: Source 35 */
    DMAMUX7_PSI5_0_CH0_RX_SENT      = 484U, /* DMAMUX_7: Source 36 */
    DMAMUX7_PSI5_0_CH1_RX_PSI5      = 485U, /* DMAMUX_7: Source 37 */
    DMAMUX7_PSI5_0_CH1_RX_SENT      = 486U, /* DMAMUX_7: Source 38 */
    DMAMUX7_PSI5_0_CH2_RX_PSI5      = 487U, /* DMAMUX_7: Source 39 */
    DMAMUX7_PSI5_0_CH2_RX_SENT      = 488U, /* DMAMUX_7: Source 40 */
    DMAMUX7_ADC_SD_0_EOC            = 489U, /* DMAMUX_7: Source 41 */
    DMAMUX7_ADC_SD_1_EOC            = 490U, /* DMAMUX_7: Source 42 */
    DMAMUX7_ADC_SD_2_EOC            = 491U, /* DMAMUX_7: Source 43 */
    DMAMUX7_ADC_SD_3_EOC            = 492U, /* DMAMUX_7: Source 44 */
    DMAMUX7_DSPI_3_CMD              = 493U, /* DMAMUX_7: Source 45 */
    DMAMUX7_DSPI_3_RX               = 494U, /* DMAMUX_7: Source 46 */
    DMAMUX7_DSPI_3_TX               = 495U, /* DMAMUX_7: Source 47 */
    DMAMUX7_DSPI_5_CMD              = 496U, /* DMAMUX_7: Source 48 */
    DMAMUX7_DSPI_5_RX               = 497U, /* DMAMUX_7: Source 49 */
    DMAMUX7_DSPI_5_TX               = 498U, /* DMAMUX_7: Source 50 */
    DMAMUX7_MCAN_4                  = 499U, /* DMAMUX_7: Source 51 */
    DMAMUX7_SSI_0_TX                = 500U, /* DMAMUX_7: Source 52 */
    DMAMUX7_SSI_0_RX                = 501U, /* DMAMUX_7: Source 53 */
    DMAMUX7_SSI_1_TX                = 502U, /* DMAMUX_7: Source 54 */
    DMAMUX7_SSI_1_RX                = 503U, /* DMAMUX_7: Source 55 */
    DMAMUX7_DSPI_21_TX              = 504U, /* DMAMUX_7: Source 56 */
    DMAMUX7_DSPI_21_RX              = 505U, /* DMAMUX_7: Source 57 */
    DMAMUX7_DSPI_21_CMD             = 506U, /* DMAMUX_7: Source 58 */
    DMAMUX7_DSPI_20_TX              = 507U, /* DMAMUX_7: Source 59 */
    DMAMUX7_DSPI_20_RX              = 508U, /* DMAMUX_7: Source 60 */
    DMAMUX7_DSPI_20_CMD             = 509U, /* DMAMUX_7: Source 61 */
    DMAMUX7_GTM_PSM2_IRQ0           = 510U, /* DMAMUX_7: Source 62 */
    DMAMUX7_ALWAYS_ON_0             = 511U, /* DMAMUX_7: Source 63 */

    /* DMAMUX_8: DMAMUX Channel 96 - 111 (eDMA_1 Channel 32 - 47) */
    DMAMUX8_RESERVED_0_A            = 512U, /* DMAMUX_8: Source 0  */
    DMAMUX8_GTM_TIM4_IRQ0           = 513U, /* DMAMUX_8: Source 1  */
    DMAMUX8_GTM_TIM4_IRQ1           = 514U, /* DMAMUX_8: Source 2  */
    DMAMUX8_GTM_TIM4_IRQ2           = 515U, /* DMAMUX_8: Source 3  */
    DMAMUX8_GTM_TIM4_IRQ3           = 516U, /* DMAMUX_8: Source 4  */
    DMAMUX8_GTM_TIM4_IRQ4           = 517U, /* DMAMUX_8: Source 5  */
    DMAMUX8_GTM_TIM4_IRQ5           = 518U, /* DMAMUX_8: Source 6  */
    DMAMUX8_GTM_TIM4_IRQ6           = 519U, /* DMAMUX_8: Source 7  */
    DMAMUX8_GTM_TIM4_IRQ7           = 520U, /* DMAMUX_8: Source 8  */
    DMAMUX8_GTM_TIM5_IRQ0           = 521U, /* DMAMUX_8: Source 9  */
    DMAMUX8_GTM_TIM5_IRQ1           = 522U, /* DMAMUX_8: Source 10 */
    DMAMUX8_GTM_TIM5_IRQ2           = 523U, /* DMAMUX_8: Source 11 */
    DMAMUX8_GTM_TIM5_IRQ3           = 524U, /* DMAMUX_8: Source 12 */
    DMAMUX8_GTM_TIM5_IRQ4           = 525U, /* DMAMUX_8: Source 13 */
    DMAMUX8_GTM_TIM5_IRQ5           = 526U, /* DMAMUX_8: Source 14 */
    DMAMUX8_GTM_TIM5_IRQ6           = 527U, /* DMAMUX_8: Source 15 */
    DMAMUX8_GTM_TIM5_IRQ7           = 528U, /* DMAMUX_8: Source 16 */
    DMAMUX8_GTM_ATOM7_IRQ0          = 529U, /* DMAMUX_8: Source 17 */
    DMAMUX8_GTM_ATOM7_IRQ1          = 530U, /* DMAMUX_8: Source 18 */
    DMAMUX8_GTM_ATOM7_IRQ2          = 531U, /* DMAMUX_8: Source 19 */
    DMAMUX8_GTM_ATOM7_IRQ3          = 532U, /* DMAMUX_8: Source 20 */
    DMAMUX8_GTM_PSM2_IRQ2           = 533U, /* DMAMUX_8: Source 21 */
    DMAMUX8_GTM_PSM2_IRQ3           = 534U, /* DMAMUX_8: Source 22 */
    DMAMUX8_GTM_PSM2_IRQ4           = 535U, /* DMAMUX_8: Source 23 */
    DMAMUX8_GTM_PSM2_IRQ5           = 536U, /* DMAMUX_8: Source 24 */
    DMAMUX8_GTM_TOM4_IRQ0           = 537U, /* DMAMUX_8: Source 25 */
    DMAMUX8_GTM_TOM4_IRQ1           = 538U, /* DMAMUX_8: Source 26 */
    DMAMUX8_GTM_TOM4_IRQ2           = 539U, /* DMAMUX_8: Source 27 */
    DMAMUX8_GTM_TOM4_IRQ3           = 540U, /* DMAMUX_8: Source 28 */
    DMAMUX8_GTM_TOM4_IRQ4           = 541U, /* DMAMUX_8: Source 29 */
    DMAMUX8_GTM_TOM4_IRQ5           = 542U, /* DMAMUX_8: Source 30 */
    DMAMUX8_GTM_TOM4_IRQ6           = 543U, /* DMAMUX_8: Source 31 */
    DMAMUX8_GTM_TOM4_IRQ7           = 544U, /* DMAMUX_8: Source 32 */
    DMAMUX8_ADC_SD_8_EOC            = 545U, /* DMAMUX_8: Source 33 */
    DMAMUX8_PSI5_1_CH0_RX_PSI5      = 546U, /* DMAMUX_8: Source 34 */
    DMAMUX8_PSI5_1_CH0_RX_SENT      = 547U, /* DMAMUX_8: Source 35 */
                                            /* DMAMUX_8: Source 36 */
                                            /* DMAMUX_8: Source 37 */
    DMAMUX8_ADC01_DECFILT_IN        = 550U, /* DMAMUX_8: Source 38 */
    DMAMUX8_ADC01_DECFILT_OUT       = 551U, /* DMAMUX_8: Source 39 */
    DMAMUX8_ADC23_DECFILT_IN        = 552U, /* DMAMUX_8: Source 40 */
    DMAMUX8_PSM2_IRQ1               = 553U, /* DMAMUX_8: Source 41 */
    DMAMUX8_ADC_SD_4_EOC            = 554U, /* DMAMUX_8: Source 42 */
    DMAMUX8_DSPI_4_CMD              = 555U, /* DMAMUX_8: Source 43 */
    DMAMUX8_DSPI_4_RX               = 556U, /* DMAMUX_8: Source 44 */
    DMAMUX8_DSPI_4_TX               = 557U, /* DMAMUX_8: Source 45 */
    DMAMUX8_LINFLEXD_3_TX           = 558U, /* DMAMUX_8: Source 46 */
    DMAMUX8_LINFLEXD_3_RX           = 559U, /* DMAMUX_8: Source 47 */
    DMAMUX8_LINFLEXD_4_TX           = 560U, /* DMAMUX_8: Source 48 */
    DMAMUX8_LINFLEXD_4_RX           = 561U, /* DMAMUX_8: Source 49 */
    DMAMUX8_LINFLEXD_5_TX           = 562U, /* DMAMUX_8: Source 50 */
    DMAMUX8_LINFLEXD_5_RX           = 563U, /* DMAMUX_8: Source 51 */
    DMAMUX8_LINFLEXD_6_TX           = 564U, /* DMAMUX_8: Source 52 */
    DMAMUX8_LINFLEXD_6_RX           = 565U, /* DMAMUX_8: Source 53 */
    DMAMUX8_LINFLEXD_7_TX           = 566U, /* DMAMUX_8: Source 54 */
    DMAMUX8_LINFLEXD_7_RX           = 567U, /* DMAMUX_8: Source 55 */
    DMAMUX8_LINFLEXD_8_TX           = 568U, /* DMAMUX_8: Source 56 */
    DMAMUX8_LINFLEXD_8_RX           = 569U, /* DMAMUX_8: Source 57 */
    DMAMUX8_LINFLEXD_9_TX           = 570U, /* DMAMUX_8: Source 58 */
    DMAMUX8_LINFLEXD_9_RX           = 571U, /* DMAMUX_8: Source 59 */
    DMAMUX8_LINFLEXD_10_TX          = 572U, /* DMAMUX_8: Source 60 */
    DMAMUX8_LINFLEXD_10_RX          = 573U, /* DMAMUX_8: Source 61 */
    DMAMUX8_LINFLEXD_11_TX          = 574U, /* DMAMUX_8: Source 62 */
    DMAMUX8_ALWAYS_ON_0             = 575U, /* DMAMUX_8: Source 63 */

    /* DMAMUX_9: DMAMUX Channel 112 - 119 (eDMA_1 Channel 48 - 55) */
    DMAMUX9_RESERVED_0_A            = 576U, /* DMAMUX_9: Source 0  */
    DMAMUX9_GTM_PSM1_IRQ0           = 577U, /* DMAMUX_9: Source 1  */
    DMAMUX9_GTM_PSM1_IRQ1           = 578U, /* DMAMUX_9: Source 2  */
    DMAMUX9_GTM_PSM1_IRQ2           = 579U, /* DMAMUX_9: Source 3  */
    DMAMUX9_GTM_PSM1_IRQ3           = 580U, /* DMAMUX_9: Source 4  */
    DMAMUX9_GTM_PSM1_IRQ4           = 581U, /* DMAMUX_9: Source 5  */
    DMAMUX9_GTM_PSM1_IRQ5           = 582U, /* DMAMUX_9: Source 6  */
    DMAMUX9_GTM_PSM1_IRQ6           = 583U, /* DMAMUX_9: Source 7  */
    DMAMUX9_GTM_PSM1_IRQ7           = 584U, /* DMAMUX_9: Source 8  */
    DMAMUX9_GTM_SPE2                = 585U, /* DMAMUX_9: Source 9  */
    DMAMUX9_GTM_SPE3                = 586U, /* DMAMUX_9: Source 10 */
    DMAMUX9_I2C_0_RX                = 587U, /* DMAMUX_9: Source 11 */
    DMAMUX9_I2C_0_TX                = 588U, /* DMAMUX_9: Source 12 */
    DMAMUX9_GTM_ATOM5_IRQ0          = 589U, /* DMAMUX_9: Source 13 */
    DMAMUX9_GTM_ATOM5_IRQ1          = 590U, /* DMAMUX_9: Source 14 */
    DMAMUX9_GTM_ATOM7_IRQ0          = 591U, /* DMAMUX_9: Source 15 */
    DMAMUX9_GTM_ATOM7_IRQ1          = 592U, /* DMAMUX_9: Source 16 */
    DMAMUX9_GTM_TOM3_IRQ0           = 593U, /* DMAMUX_9: Source 17 */
    DMAMUX9_GTM_TOM3_IRQ1           = 594U, /* DMAMUX_9: Source 18 */
    DMAMUX9_GTM_TOM3_IRQ2           = 595U, /* DMAMUX_9: Source 19 */
    DMAMUX9_GTM_TOM3_IRQ3           = 596U, /* DMAMUX_9: Source 20 */
    DMAMUX9_GTM_TOM3_IRQ4           = 597U, /* DMAMUX_9: Source 21 */
    DMAMUX9_GTM_TOM3_IRQ5           = 598U, /* DMAMUX_9: Source 22 */
    DMAMUX9_GTM_TOM3_IRQ6           = 599U, /* DMAMUX_9: Source 23 */
    DMAMUX9_GTM_TOM3_IRQ7           = 600U, /* DMAMUX_9: Source 24 */
    DMAMUX9_GTM_TOM4_IRQ0           = 601U, /* DMAMUX_9: Source 25 */
    DMAMUX9_GTM_TOM4_IRQ1           = 602U, /* DMAMUX_9: Source 26 */
    DMAMUX9_GTM_TOM4_IRQ2           = 603U, /* DMAMUX_9: Source 27 */
    DMAMUX9_GTM_TOM4_IRQ3           = 604U, /* DMAMUX_9: Source 28 */
    DMAMUX9_GTM_TOM4_IRQ4           = 605U, /* DMAMUX_9: Source 29 */
    DMAMUX9_GTM_TOM4_IRQ5           = 606U, /* DMAMUX_9: Source 30 */
    DMAMUX9_GTM_TOM4_IRQ6           = 607U, /* DMAMUX_9: Source 31 */
    DMAMUX9_GTM_TOM4_IRQ7           = 608U, /* DMAMUX_9: Source 32 */
    DMAMUX9_ADC_SD_9_EOC            = 609U, /* DMAMUX_9: Source 33 */
    DMAMUX9_MCAN_1                  = 610U, /* DMAMUX_9: Source 34 */
    DMAMUX9_MCAN_2                  = 611U, /* DMAMUX_9: Source 35 */
    DMAMUX9_ADC23_DECFILT_OUT       = 612U, /* DMAMUX_9: Source 36 */
    DMAMUX9_ADC45_DECFILT_IN        = 613U, /* DMAMUX_9: Source 37 */
    DMAMUX9_ADC67_DECFILT_IN        = 614U, /* DMAMUX_9: Source 38 */
    DMAMUX9_ADC67_DECFILT_OUT       = 615U, /* DMAMUX_9: Source 39 */
    DMAMUX9_ADC_SD_5_EOC            = 616U, /* DMAMUX_9: Source 40 */
    DMAMUX9_DSPI_2_CMD              = 617U, /* DMAMUX_9: Source 41 */
    DMAMUX9_DSPI_2_RX               = 618U, /* DMAMUX_9: Source 42 */
    DMAMUX9_DSPI_2_TX               = 619U, /* DMAMUX_9: Source 43 */
                                            /* DMAMUX_9: Source 44 */
    DMAMUX9_EMIOS_0_CH0             = 621U, /* DMAMUX_9: Source 45 */
    DMAMUX9_EMIOS_0_CH1             = 622U, /* DMAMUX_9: Source 46 */
    DMAMUX9_EMIOS_0_CH2             = 623U, /* DMAMUX_9: Source 47 */
    DMAMUX9_EMIOS_0_CH3             = 624U, /* DMAMUX_9: Source 48 */
    DMAMUX9_EMIOS_0_CH4             = 625U, /* DMAMUX_9: Source 49 */
    DMAMUX9_EMIOS_0_CH6             = 626U, /* DMAMUX_9: Source 50 */
    DMAMUX9_EMIOS_0_CH7             = 627U, /* DMAMUX_9: Source 51 */
    DMAMUX9_EMIOS_0_CH16            = 628U, /* DMAMUX_9: Source 52 */
    DMAMUX9_EMIOS_0_CH17            = 629U, /* DMAMUX_9: Source 53 */
    DMAMUX9_EMIOS_0_CH18            = 630U, /* DMAMUX_9: Source 54 */
    DMAMUX9_EMIOS_0_CH19            = 631U, /* DMAMUX_9: Source 55 */
                                            /* DMAMUX_9: Source 56 */
                                            /* DMAMUX_9: Source 57 */
                                            /* DMAMUX_9: Source 58 */
                                            /* DMAMUX_9: Source 59 */
    DMAMUX9_LINFLEXD_11_RX          = 636U, /* DMAMUX_9: Source 60 */
    DMAMUX9_LINFLEXD_12_TX          = 637U, /* DMAMUX_9: Source 61 */
    DMAMUX9_LINFLEXD_12_RX          = 638U, /* DMAMUX_9: Source 62 */
    DMAMUX9_ALWAYS_ON_0             = 639U, /* DMAMUX_9: Source 63 */

    /* DMAMUX_10: DMAMUX Channel 120 - 127 (eDMA_1 Channel 56 - 63) */
    DMAMUX10_RESERVED_0_A           = 640U, /* DMAMUX_10: Source 0  */
    DMAMUX10_EQADC5_ADC1011_CFIFO0  = 641U, /* DMAMUX_10: Source 1  */
    DMAMUX10_EQADC5_ADC1011_CFIFO1  = 642U, /* DMAMUX_10: Source 2  */
    DMAMUX10_EQADC5_ADC1011_CFIFO2  = 643U, /* DMAMUX_10: Source 3  */
    DMAMUX10_EQADC5_ADC1011_CFIFO3  = 644U, /* DMAMUX_10: Source 4  */
    DMAMUX10_EQADC5_ADC1011_CFIFO4  = 645U, /* DMAMUX_10: Source 5  */
    DMAMUX10_EQADC5_ADC1011_CFIFO5  = 646U, /* DMAMUX_10: Source 6  */
    DMAMUX10_EQADC5_ADC1011_RFIFO0  = 647U, /* DMAMUX_10: Source 7  */
    DMAMUX10_EQADC5_ADC1011_RFIFO1  = 648U, /* DMAMUX_10: Source 8  */
    DMAMUX10_EQADC5_ADC1011_RFIFO2  = 649U, /* DMAMUX_10: Source 9  */
    DMAMUX10_EQADC5_ADC1011_RFIFO3  = 650U, /* DMAMUX_10: Source 10 */
    DMAMUX10_EQADC5_ADC1011_RFIFO4  = 651U, /* DMAMUX_10: Source 11 */
    DMAMUX10_EQADC5_ADC1011_RFIFO5  = 652U, /* DMAMUX_10: Source 12 */
    DMAMUX10_EQADC6_ADC1213_CFIFO0  = 653U, /* DMAMUX_10: Source 13 */
    DMAMUX10_EQADC6_ADC1213_CFIFO1  = 654U, /* DMAMUX_10: Source 14 */
    DMAMUX10_EQADC6_ADC1213_CFIFO2  = 655U, /* DMAMUX_10: Source 15 */
    DMAMUX10_EQADC6_ADC1213_CFIFO3  = 656U, /* DMAMUX_10: Source 16 */
    DMAMUX10_EQADC6_ADC1213_CFIFO4  = 657U, /* DMAMUX_10: Source 17 */
    DMAMUX10_EQADC6_ADC1213_CFIFO5  = 658U, /* DMAMUX_10: Source 18 */
    DMAMUX10_EQADC6_ADC1213_RFIFO0  = 659U, /* DMAMUX_10: Source 19 */
    DMAMUX10_EQADC6_ADC1213_RFIFO1  = 660U, /* DMAMUX_10: Source 20 */
    DMAMUX10_EQADC6_ADC1213_RFIFO2  = 661U, /* DMAMUX_10: Source 21 */
    DMAMUX10_EQADC6_ADC1213_RFIFO3  = 662U, /* DMAMUX_10: Source 22 */
    DMAMUX10_EQADC6_ADC1213_RFIFO4  = 663U, /* DMAMUX_10: Source 23 */
    DMAMUX10_EQADC6_ADC1213_RFIFO5  = 664U, /* DMAMUX_10: Source 24 */
    DMAMUX10_ADC_SD_10_EOC          = 665U, /* DMAMUX_10: Source 25 */
    DMAMUX10_ADC_SD_11_EOC          = 666U, /* DMAMUX_10: Source 26 */
    DMAMUX10_ADC_SD_12_EOC          = 667U, /* DMAMUX_10: Source 27 */
    DMAMUX10_ADC_SD_13_EOC          = 668U, /* DMAMUX_10: Source 28 */
    DMAMUX10_DAC_0                  = 669U, /* DMAMUX_10: Source 29 */
    DMAMUX10_DAC_1                  = 670U, /* DMAMUX_10: Source 30 */
    DMAMUX10_ADC_1011_DECFILT_OUT   = 671U, /* DMAMUX_10: Source 31 */
    DMAMUX10_ADC_1011_DECFILT_IN    = 672U, /* DMAMUX_10: Source 32 */
    DMAMUX10_ADC_1213_DECFILT_OUT   = 673U, /* DMAMUX_10: Source 33 */
    DMAMUX10_ADC_1213_DECFILT_IN    = 674U, /* DMAMUX_10: Source 34 */
    DMAMUX10_GTM_PSM2_IRQ6          = 675U, /* DMAMUX_10: Source 35 */
    DMAMUX10_GTM_PSM2_IRQ7          = 676U, /* DMAMUX_10: Source 36 */
    DMAMUX10_GTM_TOM5_IRQ0          = 677U, /* DMAMUX_10: Source 37 */
    DMAMUX10_GTM_TOM5_IRQ1          = 678U, /* DMAMUX_10: Source 38 */
    DMAMUX10_GTM_TOM5_IRQ2          = 679U, /* DMAMUX_10: Source 39 */
    DMAMUX10_GTM_TOM5_IRQ3          = 680U, /* DMAMUX_10: Source 40 */
    DMAMUX10_GTM_TOM5_IRQ4          = 681U, /* DMAMUX_10: Source 41 */
    DMAMUX10_GTM_TOM5_IRQ5          = 682U, /* DMAMUX_10: Source 42 */
    DMAMUX10_GTM_TOM5_IRQ6          = 683U, /* DMAMUX_10: Source 43 */
    DMAMUX10_GTM_TOM5_IRQ7          = 684U, /* DMAMUX_10: Source 44 */
    DMAMUX10_GTM_SPE4               = 685U, /* DMAMUX_10: Source 45 */
    DMAMUX10_GTM_SPE5               = 686U, /* DMAMUX_10: Source 46 */
    DMAMUX10_GTM_TIM6_IRQ0          = 687U, /* DMAMUX_10: Source 47 */
    DMAMUX10_GTM_TIM6_IRQ1          = 688U, /* DMAMUX_10: Source 48 */
    DMAMUX10_GTM_TIM6_IRQ2          = 689U, /* DMAMUX_10: Source 49 */
    DMAMUX10_GTM_TIM6_IRQ3          = 690U, /* DMAMUX_10: Source 50 */
    DMAMUX10_GTM_TIM6_IRQ4          = 691U, /* DMAMUX_10: Source 51 */
    DMAMUX10_GTM_TIM6_IRQ5          = 692U, /* DMAMUX_10: Source 52 */
    DMAMUX10_GTM_TIM6_IRQ6          = 693U, /* DMAMUX_10: Source 53 */
    DMAMUX10_GTM_TIM6_IRQ7          = 694U, /* DMAMUX_10: Source 54 */
    DMAMUX10_GTM_TIM7_IRQ0          = 695U, /* DMAMUX_10: Source 55 */
    DMAMUX10_GTM_TIM7_IRQ1          = 696U, /* DMAMUX_10: Source 56 */
    DMAMUX10_GTM_TIM7_IRQ2          = 697U, /* DMAMUX_10: Source 57 */
    DMAMUX10_GTM_TIM7_IRQ3          = 698U, /* DMAMUX_10: Source 58 */
    DMAMUX10_GTM_TIM7_IRQ4          = 699U, /* DMAMUX_10: Source 59 */
    DMAMUX10_GTM_TIM7_IRQ5          = 700U, /* DMAMUX_10: Source 60 */
    DMAMUX10_GTM_TIM7_IRQ6          = 701U, /* DMAMUX_10: Source 61 */
    DMAMUX10_GTM_TIM7_IRQ7          = 702U, /* DMAMUX_10: Source 62 */
    DMAMUX10_ALWAYS_ON_0            = 703U  /* DMAMUX_10: Source 63 */
} eDMARequestSourceType;

/* CONSOLE CONFIG */
/* notice the RESOURCE_CHIP_CORE_NUM is 6 */
#define CONSOLE_GPIO_CONFIG_BGA516     {     \
            /* CORE_0 uart use LIN16 TX-RX: PAD_NUM, PCR_VAL, PSMI_REG, PSMI_VAL */   \
            {{PN6,  0x069C, 0, 0}, {PN5,  0x0640, 16, 0}},   \
            /* CORE_1 uart use LIN15 TX-RX */   \
            {{PN4,  0x069C, 0, 0}, {PN3,  0x0640, 15, 0}},   \
            /* CORE_2 uart use LIN14 TX-RX */   \
            {{PN2,  0x069C, 0, 0}, {PN1,  0x0640, 14, 0}},   \
            /* CORE_3 uart use LIN12 TX-RX */   \
            {{PN0,  0x069C, 0, 0}, {PM15, 0x0640, 12, 0}},   \
            /* CORE_4 uart use LIN11 TX-RX */   \
            {{PD0,  0x0A9C, 0, 0}, {PD4,  0x0740, 11, 1}},   \
            /* CORE_5 uart use LIN10 TX-RX */   \
            {{PF1,  0x069C, 0, 0}, {PF2,  0x0540, 10, 3}},   \
            }

#define CONSOLE_GPIO_CONFIG_BGA292     {     \
            /* CORE_0 uart use LIN11 TX-RX: PAD_NUM, PCR_VAL, PSMI_REG, PSMI_VAL */   \
            {{PD0,  0x0A9C, 0, 0}, {PD4,  0x0740, 11, 1}},  \
            /* CORE_1 uart use LIN10 TX-RX */   \
            {{PF1,  0x069C, 0, 0}, {PF2,  0x0540, 10, 3}},  \
            /* CORE_2 uart use LIN9 TX-RX */   \
            {{PB7,  0x089C, 0, 0}, {PB5,  0x0640, 9,  0}},  \
            /* CORE_3 uart use LIN8 TX-RX */   \
            {{PC9,  0x0A9C, 0, 0}, {PC10, 0x0840, 8,  0}},  \
            /* CORE_4 uart use LIN7 TX-RX */   \
            {{PJ5,  0x0C9C, 0, 0}, {PJ8,  0x0240, 7,  4}},  \
            /* CORE_5 uart use LIN6 TX-RX */   \
            {{PK5,  0x059C, 0, 0}, {PK3,  0x0540, 6,  4}},  \
            }

#if(CCFC_CHIP_MODEL_PACKAGE == CCFC3012PT_H264B2_BGA292)
#define CONSOLE_GPIO_CONFIG    CONSOLE_GPIO_CONFIG_BGA292
#else
#define CONSOLE_GPIO_CONFIG    CONSOLE_GPIO_CONFIG_BGA516
#endif
/* CONSOLE CONFIG END */
/* FOR LINFLEXD MODULE */
#define LINFLEXD_GPIO_CONFIG_BGA516     {     \
            /* LINFlexD_0 TX, RX */                         \
            {{PF10, 0x079C, 0, 0}, {PF11, 0x0440, 0,  1}},  \
            /* LINFlexD_1 TX, RX*/                          \
            {{PC2,  0x079C, 0, 0}, {PC3,  0x0640, 1,  0}},  \
            /* LINFlexD_2 TX, RX */                         \
            {{PC0,  0x0A9C, 0, 0}, {PC1,  0x0440, 2,  2}},  \
            /* LINFlexD_3 TX, RX */                         \
            {{PA0,  0x0B9C, 0, 0}, {PA1,  0x0540, 3,  0}},  \
            /* LINFlexD_4 TX, RX */                         \
            {{PJ9,  0x059C, 0, 0}, {PJ10, 0x0440, 4,  1}},  \
            /* LINFlexD_5 TX, RX */                         \
            {{PA7,  0x0D9C, 0, 0}, {PA6,  0x0740, 5,  0}},  \
            /* LINFlexD_6 TX, RX */                         \
            {{PK5,  0x059C, 0, 0}, {PK3,  0x0540, 6,  4}},  \
            /* LINFlexD_7 TX, RX */                         \
            {{PJ5,  0x0C9C, 0, 0}, {PJ8,  0x0240, 7,  4}},  \
            /* LINFlexD_8 TX, RX */                         \
            {{PC9,  0x0A9C, 0, 0}, {PC10, 0x0840, 8,  0}},  \
            /* LINFlexD_9 TX, RX */                         \
            {{PB7,  0x089C, 0, 0}, {PB5,  0x0640, 9,  0}},  \
            /* LINFlexD_10 TX, RX */                        \
            {{PF1,  0x069C, 0, 0}, {PF2,  0x0540, 10, 3}},  \
            /* LINFlexD_11 TX, RX */                        \
            {{PD0,  0x0A9C, 0, 0}, {PD4,  0x0740, 11, 1}},  \
            /* LINFlexD_12 TX, RX */                        \
            {{PN0,  0x069C, 0, 0}, {PM15, 0x0640, 12, 0}},  \
            /* LINFlexD_14 TX, RX */                        \
            {{PN2,  0x069C, 0, 0}, {PN1,  0x0640, 14, 0}},  \
            /* LINFlexD_15 TX, RX */                        \
            {{PN4,  0x069C, 0, 0}, {PN3,  0x0640, 15, 0}},  \
            /* LINFlexD_16 TX, RX */                        \
            {{PN6,  0x069C, 0, 0}, {PN5,  0x0640, 16, 0}}   \
            }

#define LINFLEXD_EDMA_CONFIG_BGA516    \
        { \
            {{EDMA_CHN33_NUMBER,  DMAMUX4_LINFLEXD_0_TX,  FALSE}, {EDMA_CHN32_NUMBER,   DMAMUX4_LINFLEXD_0_RX,  FALSE}},\
            {{EDMA_CHN49_NUMBER,  DMAMUX5_LINFLEXD_1_TX,  FALSE}, {EDMA_CHN48_NUMBER,   DMAMUX5_LINFLEXD_1_RX,  FALSE}},\
            {{EDMA_CHN51_NUMBER,  DMAMUX5_LINFLEXD_2_TX,  FALSE}, {EDMA_CHN50_NUMBER,   DMAMUX5_LINFLEXD_2_RX,  FALSE}},\
            {{EDMA_CHN98_NUMBER,  DMAMUX8_LINFLEXD_3_TX,  FALSE}, {EDMA_CHN99_NUMBER,   DMAMUX8_LINFLEXD_3_RX,  FALSE}},\
            {{EDMA_CHN100_NUMBER, DMAMUX8_LINFLEXD_4_TX,  FALSE}, {EDMA_CHN101_NUMBER,  DMAMUX8_LINFLEXD_4_RX,  FALSE}},\
            {{EDMA_CHN100_NUMBER, DMAMUX8_LINFLEXD_5_TX,  FALSE}, {EDMA_CHN101_NUMBER,  DMAMUX8_LINFLEXD_5_RX,  FALSE}},\
            {{EDMA_CHN100_NUMBER, DMAMUX8_LINFLEXD_6_TX,  FALSE}, {EDMA_CHN101_NUMBER,  DMAMUX8_LINFLEXD_6_RX,  FALSE}},\
            {{EDMA_CHN100_NUMBER, DMAMUX8_LINFLEXD_7_TX,  FALSE}, {EDMA_CHN101_NUMBER,  DMAMUX8_LINFLEXD_7_RX,  FALSE}},\
            {{EDMA_CHN100_NUMBER, DMAMUX8_LINFLEXD_8_TX,  FALSE}, {EDMA_CHN101_NUMBER,  DMAMUX8_LINFLEXD_8_RX,  FALSE}},\
            {{EDMA_CHN100_NUMBER, DMAMUX8_LINFLEXD_9_TX,  FALSE}, {EDMA_CHN101_NUMBER,  DMAMUX8_LINFLEXD_9_RX,  FALSE}},\
            {{EDMA_CHN100_NUMBER, DMAMUX8_LINFLEXD_10_TX, FALSE}, {EDMA_CHN101_NUMBER,  DMAMUX8_LINFLEXD_10_RX, FALSE}},\
            {{EDMA_CHN100_NUMBER, DMAMUX8_LINFLEXD_11_TX, FALSE}, {EDMA_CHN118_NUMBER,  DMAMUX9_LINFLEXD_11_RX, FALSE}},\
            {{EDMA_CHN119_NUMBER, DMAMUX9_LINFLEXD_12_TX, FALSE}, {EDMA_CHN117_NUMBER,  DMAMUX9_LINFLEXD_12_RX, FALSE}},\
            {{EDMA_CHN35_NUMBER,  DMAMUX4_LINFLEXD_14_TX, FALSE}, {EDMA_CHN5_NUMBER,    DMAMUX0_LINFLEXD_14_RX, FALSE}},\
            {{EDMA_CHN42_NUMBER,  DMAMUX4_LINFLEXD_15_TX, FALSE}, {EDMA_CHN52_NUMBER,   DMAMUX5_LINFLEXD_15_RX, FALSE}},\
            {{EDMA_CHN0_NUMBER,   DMAMUX0_LINFLEXD_16_TX, FALSE}, {EDMA_CHN1_NUMBER,    DMAMUX0_LINFLEXD_16_RX, FALSE}},\
        }

#define LINFLEXD_GPIO_CONFIG_BGA292     {     \
            /* LINFlexD_0 TX, RX */                         \
            {{PF10, 0x079C, 0, 0}, {PF11, 0x0440, 0,  1}},  \
            /* LINFlexD_1 TX, RX*/                          \
            {{PC2,  0x079C, 0, 0}, {PC3,  0x0640, 1,  0}},  \
            /* LINFlexD_2 TX, RX */                         \
            {{PC0,  0x0A9C, 0, 0}, {PC1,  0x0440, 2,  2}},  \
            /* LINFlexD_3 TX, RX */                         \
            {{PA0,  0x0B9C, 0, 0}, {PA1,  0x0540, 3,  0}},  \
            /* LINFlexD_4 TX, RX */                         \
            {{PJ9,  0x059C, 0, 0}, {PJ10, 0x0440, 4,  1}},  \
            /* LINFlexD_5 TX, RX */                         \
            {{PA7,  0x0D9C, 0, 0}, {PA6,  0x0740, 5,  0}},  \
            /* LINFlexD_6 TX, RX */                         \
            {{PK5,  0x059C, 0, 0}, {PK3,  0x0540, 6,  4}},  \
            /* LINFlexD_7 TX, RX */                         \
            {{PJ5,  0x0C9C, 0, 0}, {PJ8,  0x0240, 7,  4}},  \
            /* LINFlexD_8 TX, RX */                         \
            {{PC9,  0x0A9C, 0, 0}, {PC10, 0x0840, 8,  0}},  \
            /* LINFlexD_9 TX, RX */                         \
            {{PB7,  0x089C, 0, 0}, {PB5,  0x0640, 9,  0}},  \
            /* LINFlexD_10 TX, RX */                        \
            {{PF1,  0x069C, 0, 0}, {PF2,  0x0540, 10, 3}},  \
            /* LINFlexD_11 TX, RX */                        \
            {{PD0,  0x0A9C, 0, 0}, {PD4,  0x0740, 11, 1}}  \
            }

#define LINFLEXD_EDMA_CONFIG_BGA292    \
        { \
            {{EDMA_CHN33_NUMBER,  DMAMUX4_LINFLEXD_0_TX,  FALSE}, {EDMA_CHN32_NUMBER,   DMAMUX4_LINFLEXD_0_RX,  FALSE}},\
            {{EDMA_CHN49_NUMBER,  DMAMUX5_LINFLEXD_1_TX,  FALSE}, {EDMA_CHN48_NUMBER,   DMAMUX5_LINFLEXD_1_RX,  FALSE}},\
            {{EDMA_CHN51_NUMBER,  DMAMUX5_LINFLEXD_2_TX,  FALSE}, {EDMA_CHN50_NUMBER,   DMAMUX5_LINFLEXD_2_RX,  FALSE}},\
            {{EDMA_CHN98_NUMBER,  DMAMUX8_LINFLEXD_3_TX,  FALSE}, {EDMA_CHN99_NUMBER,   DMAMUX8_LINFLEXD_3_RX,  FALSE}},\
            {{EDMA_CHN100_NUMBER, DMAMUX8_LINFLEXD_4_TX,  FALSE}, {EDMA_CHN101_NUMBER,  DMAMUX8_LINFLEXD_4_RX,  FALSE}},\
            {{EDMA_CHN100_NUMBER, DMAMUX8_LINFLEXD_5_TX,  FALSE}, {EDMA_CHN101_NUMBER,  DMAMUX8_LINFLEXD_5_RX,  FALSE}},\
            {{EDMA_CHN100_NUMBER, DMAMUX8_LINFLEXD_6_TX,  FALSE}, {EDMA_CHN101_NUMBER,  DMAMUX8_LINFLEXD_6_RX,  FALSE}},\
            {{EDMA_CHN100_NUMBER, DMAMUX8_LINFLEXD_7_TX,  FALSE}, {EDMA_CHN101_NUMBER,  DMAMUX8_LINFLEXD_7_RX,  FALSE}},\
            {{EDMA_CHN100_NUMBER, DMAMUX8_LINFLEXD_8_TX,  FALSE}, {EDMA_CHN101_NUMBER,  DMAMUX8_LINFLEXD_8_RX,  FALSE}},\
            {{EDMA_CHN100_NUMBER, DMAMUX8_LINFLEXD_9_TX,  FALSE}, {EDMA_CHN101_NUMBER,  DMAMUX8_LINFLEXD_9_RX,  FALSE}},\
            {{EDMA_CHN100_NUMBER, DMAMUX8_LINFLEXD_10_TX, FALSE}, {EDMA_CHN101_NUMBER,  DMAMUX8_LINFLEXD_10_RX, FALSE}},\
            {{EDMA_CHN100_NUMBER, DMAMUX8_LINFLEXD_11_TX, FALSE}, {EDMA_CHN118_NUMBER,  DMAMUX9_LINFLEXD_11_RX, FALSE}}\
        }

#if(CCFC_CHIP_MODEL_PACKAGE == CCFC3012PT_H264B2_BGA292)

#define LINFLEXD_GPIO_CONFIG    LINFLEXD_GPIO_CONFIG_BGA292
#define LINFLEXD_EDMA_CONFIG    LINFLEXD_EDMA_CONFIG_BGA292
#ifdef  LINFLEXD_MAX
#undef  LINFLEXD_MAX
#define LINFLEXD_MAX            12u
#endif
#ifdef  RESOURCE_SUPPORT_LINFLEXD_12
#undef  RESOURCE_SUPPORT_LINFLEXD_12
#endif
#ifdef  RESOURCE_SUPPORT_LINFLEXD_14
#undef  RESOURCE_SUPPORT_LINFLEXD_14
#endif
#ifdef  RESOURCE_SUPPORT_LINFLEXD_15
#undef  RESOURCE_SUPPORT_LINFLEXD_15
#endif
#ifdef  RESOURCE_SUPPORT_LINFLEXD_16
#undef  RESOURCE_SUPPORT_LINFLEXD_16
#endif

#else
#define LINFLEXD_GPIO_CONFIG    LINFLEXD_GPIO_CONFIG_BGA516
#define LINFLEXD_EDMA_CONFIG    LINFLEXD_EDMA_CONFIG_BGA516
#endif
/* FOR LINFLEXD MODULE END */

/* FOR FLEXRAY MODULE CONFIG */
#define  FLEXRAY_GPIO_CONFIG  \
        { \
            {\
                {{PG10, 0x0B9C, PG10, 0},{PG8, 0x0340, 99, 3},{PG9,  0x0C9C, PG9,  0}}, \
                {{PG5,  0x089C, PG5,  0},{PG7, 0x0440, 100, 3},{PG6,  0x089C, PG6,  0}} \
            }, \
            {\
                {{PB12, 0x099C, PB12, 0},{PB1, 0x0440, 101, 0},{PB14, 0x079C, PB14, 0}}, \
                {{PG5,  0x099C, PG5,  0},{PG7, 0x0540, 102, 1},{PG6,  0x099C, PG6,  0}} \
            } \
        }
/* FOR FLEXRAY MODULE CONFIG END*/

/* FOR SSI MODULE CONFIG */

#define SSI_MOD_MAX 2
/* default SSI0 */
#define USE_SSI_0           1

#define SSI_GPIO_CONFIG     { \
                                {{PE3,  0x0B9C}, \
                                {PE4,  0x079C}, \
                                {PE5,  0x0CDC}, \
                                {PE6,  0x06DC}, \
                                {PE7,  0x06DC}, \
                                {PE8,  0x0ADC}  \
                                },\
                                {{PE9,  0x109C}, \
                                {PE10, 0x0E9C}, \
                                {PE11, 0x0EDC}, \
                                {PE12, 0x08DC}, \
                                {PE13, 0x0ADC}, \
                                {PE14, 0x05DC}  \
                                },\
                            }

#define SSI_EDMA_CONFIG    { \
        {{EDMA_CHN80_NUMBER, DMAMUX7_SSI_0_TX, FALSE}, {EDMA_CHN81_NUMBER, DMAMUX7_SSI_0_RX, FALSE}}, \
        {{EDMA_CHN80_NUMBER, DMAMUX7_SSI_1_TX, FALSE}, {EDMA_CHN81_NUMBER, DMAMUX7_SSI_1_RX, FALSE}}, \
}

#define DMA_CHECK_ACTIVE(__dma_ch__) eDMA_1.TCD[__dma_ch__].CSR.B.ACTIVE
#define DMA_CHECK_DONE(__dma_ch__)   eDMA_1.TCD[__dma_ch__].CSR.B.DONE

#define SSI_0_CS_OUT_LOW   (SIUL.GPDO[PE4].R = 0U)
#define SSI_0_CS_OUT_HIGH  (SIUL.GPDO[PE4].R = 1U)
#define SSI_1_CS_OUT_LOW   (SIUL.GPDO[PE10].R = 0U)
#define SSI_1_CS_OUT_HIGH  (SIUL.GPDO[PE10].R = 1U)

/* FOR SSI MODULE CONFIG END*/

/* I2C MODULE CONFIG */
#define I2C_MODULE_CLK DSPI_B_CLK
#define I2C_MOD_MAX 2
#define I2C_GPIO_CONFIG    {     \
                                /* I2C 0 SCL-SDA */                           \
                                /*{{PC5,  0x04DC, 53, 0}, {PC4,  0x07DC, 52, 0}}, */ \
                                {{PF2,  0x03DF, 53, 1}, {PF3,  0x04DF, 52, 1}},  \
                                /* {{PH4,  0x0300, 53, 2}, {PH5,  0x0500, 52, 2}}, */  \
                                /* I2C 1 SCL-SDA */                            \
                                /* {{PE13, 0x06DC, 55, 0}, {PE12, 0x04DC, 54, 0}}, */\
                                {{PF9,  0x04DF, 55, 1}, {PF12, 0x06DF, 54, 1}} \
                           }

/* I2C MODULE CONFIG END */

/* FOR PSI5 MODULE CONFIG */
#define PSI5_0_CH_MAX 4U
#define PSI5_CH_MAX (PSI5_0_CH_MAX)
#define PSI5_GPIO_CONFIG     {     \
                                /* PSI5_0 TX RX */                           \
                                {{PC2,  0x0A9C, 0, 0}, {PC3,  0x0940, 56, 1}},  \
                                {{PC6,  0x109C, 0, 0}, {PC5,  0x0540, 57, 1}},  \
                                {{PC8,  0x119C, 0, 0}, {PC7,  0x0940, 58, 1}},  \
                                {{PD5,  0x0F9C, 0, 0}, {PD6,  0x0440, 59, 0}},  \
                            }
/* FOR PSI5 MODULE CONFIG END */
/* FOR PSI5_S MODULE CONFIG */
#define PSI5_S_CH_MAX 1U
#define PSI5_S_GPIO_CONFIG     {     \
                                /* PSI5_0 TCK - TX - RX */                           \
                                {{PC4,  0x0F9C, 0, 0}, {PC6,  0x0E9C, 0, 0}, {PC5,  0x0640, 60, 1}},  \
                                /*{{PP11,  0x0E9C, 0, 0}, {PP7,  0x129C, 0, 0}, {PP6,  0x0740, 60, 1}}, */\
                            }
/* FOR PSI5_S MODULE CONFIG END */

#endif  /* defined(CCFC3012PT) */
#endif /* CCFC3012PT_FEATURES_H_ */
