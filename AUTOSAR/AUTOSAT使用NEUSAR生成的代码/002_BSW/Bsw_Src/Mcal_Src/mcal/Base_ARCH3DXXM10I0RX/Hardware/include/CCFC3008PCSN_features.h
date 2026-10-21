/****************************************************************************
*
* Copyright (c) 2025  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC3008PCSN
* DESCRIPTION : CCFC3008PCSN features h file
* HISTORY     : Initial version
* @file     CCFC3008PCSN_features.h
* @version  1.0
* @date     2025 - 06 - 05
* @brief    Initial version.
*
*****************************************************************************/

#ifndef CCFC3008PCSN_FEATURES_H_
#define CCFC3008PCSN_FEATURES_H_
#if defined(CCFC3008PCSN)

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

/* CCFC3008PCSN package define */
#define CCFC3008PC_S48L5_N_TQFP144  (0x38D10825UL)  /* 38D: 3008PCSN, 1: 1core , 08: 4MB, 25: TQFP144 */
#define CCFC3008PC_S64B1_N_BGA180   (0x38D108B1UL)  /* 38D: 3008PCSN, 1: 1core , 08: 4MB, B1: BGA180  */
#define CCFC3008PC_S64B1_N_BGA180A  (0x38D108C1UL)  /* 38D: 3008PCSN, 1: 1core , 08: 4MB, C1: BGA180A */

/* Chip model package selection */
#define CCFC_CHIP_MODEL_PACKAGE     CCFC3008PC_S64B1_N_BGA180

#if ((CCFC_CHIP_MODEL_PACKAGE & CHIP_TYPE_MASK) != CHIP_TYPE)
    #error "No valid CPU Type defined!"
#endif
/****************************************************************************/
/****************************************************************************/


/*===================Device resource definition start=======================*/

/*----------------------------------Cores-----------------------------------*/
#define RESOURCE_CHIP_CORE_NUM      (1u)    /* Number of chip cores. */
#define RESOURCE_SUPPORT_CORE_0     (0u)    /* Supported. Core_0 */
#define RESOURCE_SUPPORT_CHK_CORE_0 (0u)    /* Supported. Checker Core_0 */

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

#define RESOURCE_SUPPORT_MC_CGM_PREDIV_DIV16    /* Supported. PLLDIG,  up to support pll0 prediv 16 divider*/

#define RESOURCE_SUPPORT_MCU_I2S            /* Supported. */
#define RESOURCE_SUPPORT_MCU_SSI            /* Supported. */

#define RESOURCE_SUPPORT_MCU_FLASH_VARIABLE_SIZE    /* Supported. */
#define RESOURCE_SUPPORT_MCU_RESET_EMIOS    /* Supported. MC_RGM, EMIOS module reset function */
#define RESOURCE_SUPPORT_MCU_RESET_ETPU     /* Supported. MC_RGM, ETPU module reset function */

/* RESOURCE_SUPPORT_MCU_CCTL0 */       /* Unsupported. */
#define RESOURCE_SUPPORT_MCU_CCTL1       /* Supported. */
#define RESOURCE_SUPPORT_MCU_CCTL2       /* Supported. */
/* RESOURCE_SUPPORT_MCU_CCTL3 */       /* Unsupported. */
#define RESOURCE_SUPPORT_MCU_CCTL4       /* Supported. */
/* RESOURCE_SUPPORT_MCU_CCTL6 */       /* Unsupported. */
/* RESOURCE_SUPPORT_MCU_CCTL7 */       /* Unsupported. */
/* RESOURCE_SUPPORT_MCU_CCTL8 */       /* Unsupported. */
/* RESOURCE_SUPPORT_MCU_CCTL9 */       /* Unsupported. */
/* RESOURCE_SUPPORT_MCU_CCTL10 */      /* Unsupported. */
/* RESOURCE_SUPPORT_MCU_CCTL11 */      /* Unsupported. */

/*----------------------------------SMPU------------------------------------*/
#define RESOURCE_SUPPORT_SMPU_INSTANCE_COUNT    (2U)    /* Supported.   SMPU instance 0/1.                              */
#define RESOURCE_SUPPORT_SMPU_MASTER_NUM_COUNT  (5U)    /* Supported.   SMPU logical bus master number: count           */
/* SMPU logical bus master number */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_0  (0U)    /* Supported.   SMPU logical bus master number 0:  Core_0       */
/* RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_1  */           /* Unsupported. SMPU logical bus master number 1:  Reserved     */
/* RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_2  */           /* Unsupported. SMPU logical bus master number 2:  Reserved     */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_3  (3U)    /* Supported.   SMPU logical bus master number 3:  DMA_0        */
/* RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_4  */           /* Unsupported. SMPU logical bus master number 4:  Reserved     */
/* RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_5  */           /* Unsupported. SMPU logical bus master number 5:  Reserved     */
/* RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_6  */           /* Unsupported. SMPU logical bus master number 6:  Reserved     */
/* RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_7  */           /* Unsupported. SMPU logical bus master number 7:  Reserved     */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_8  (8U)    /* Supported.   SMPU logical bus master number 8:  Core_0 Debug */
/* RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_9  */           /* Unsupported. SMPU logical bus master number 9:  Reserved     */
/* RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_10 */           /* Unsupported. SMPU logical bus master number 10: Reserved     */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_11 (11U)   /* Supported.   SMPU logical bus master number 11: DMA_1        */
/* RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_12 */           /* Unsupported. SMPU logical bus master number 12: Reserved     */
/* RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_13 */           /* Unsupported. SMPU logical bus master number 13: Reserved     */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_14 (14U)   /* Supported.   SMPU logical bus master number 14: HSM          */
/* RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_15 */           /* Unsupported. SMPU logical bus master number 15: Reserved     */
#define RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_MAX (15U)  /* SMPU logical bus master number: Max                          */

/*----------------------------------PMC_dig: Power Management Controller----*/
/* RESOURCE_SUPPORT_PMC_PAD_RETENTION */    /* Unsupported. Pad Retention function. */

/*----------------------------------INTC: Interrupt Controller--------------*/
#define RESOURCE_SUPPORT_INTC_0             /* Supported. Interrupt Controller 0. */
/* RESOURCE_SUPPORT_INTC_1 */               /* Unsupported. Interrupt Controller 1. */

/*----------------------------------FLASH-----------------------------------*/

/*----------------------------------RAM-------------------------------------*/

/*----------------------------------SIULx: System Integration Unit LiteX----*/
/* Note: The Unit provides control over all the I/O ports on this device. */
/* RESOURCE_SUPPORT_SIUL_IP */              /* Unsupported. IP: SIUL */
#define RESOURCE_SUPPORT_SIUL2_IP           /* Supported. IP: SIUL2 */

/*----------------------------------EIOMUX: Enhanced IO Multiplexer---------*/
/* The RESOURCE_SUPPORT_EIOMUX_IP macro is defined by Port.*/
/* Caution: in MCAL we use EBtool to generate this Macro */
/* RESOURCE_SUPPORT_EIOMUX */               /* Unsupported. IP: EIOMUX */
/* RESOURCE_SUPPORT_EIOMUX2 */              /* Supported. IP: EIOMUX2, */

/*----------------------------------EMDA/DMAMUX-----------------------------*/
/* RESOURCE_SUPPORT_TRANS_8_32BYTES */      /* Unsupported. transport 8/32bytes unsupport transport 16bytes */
/* RESOURCE_SUPPORT_DMAMUX10 */             /* Unsupported. DMAMUX_10 */

/*----------------------------------WKPU: WakeUp Unit-----------------------*/
#define RESOURCE_SUPPORT_WKPU_NMI           /* Supported. Non-maskable interrupts. */
#define RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC /* Supported. Other multiple wake sources. */
/* RESOURCE_SUPPORT_WKPU_MUX_COMBI */       /* Unsupported. Multiplex combination. */
#ifdef RESOURCE_SUPPORT_WKPU_NMI
#define NMI_IO_MUX_REG_WKPU_NCR             (1U)    /* NMI pin multiplexing control in the WKPU module. */
#define NMI_IO_MUX_REG_SIUL2_SCR0           (2U)    /* NMI pin multiplexing control in the SIUL2 module. */
#define RESOURCE_SUPPORT_WKPU_NMI_IO_MUX    (NMI_IO_MUX_REG_WKPU_NCR)   /* Supported. NMI pins(ESR1) support multiplexing. */
#endif  /* RESOURCE_SUPPORT_WKPU_NMI */
#ifdef RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC
#define RESOURCE_SUPPORT_WKPU_WISR0_0_7     /* Supported. Wake up source WISR0 0-7. */
#define RESOURCE_SUPPORT_WKPU_WISR0_8_15    /* Supported. Wake up source WISR0 8-15. */
/* RESOURCE_SUPPORT_WKPU_WISR0_16_23 */     /* Unsupported. Wake up source WISR0 16-23. */
#define RESOURCE_SUPPORT_WKPU_WISR0_24_31   /* Supported. Wake up source WISR0 24-31. */
/* RESOURCE_SUPPORT_WKPU_WISR1_0_7  */      /* Unsupported. Wake up source WISR1 0-7. */
/* RESOURCE_SUPPORT_WKPU_WISR1_8_15 */      /* Unsupported. Wake up source WISR1 8-15. */
/* RESOURCE_SUPPORT_WKPU_WISR1_16_23*/      /* Unsupported. Wake up source WISR1 16-23. */
/* RESOURCE_SUPPORT_WKPU_WISR1_24_31*/      /* Unsupported. Wake up source WISR1 24-31. */
#endif  /* RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC */

/*----------------------------------eQADC: Enhanced Queued ADC(SARADC)------*/
/*
 * Classification: EQADC Instance Resources (EQADC Function Definition Macro) */
#define RESOURCE_SUPPORT_EQADC_INST0                /* Supported. EQADC Instance 0(EqadcHwUnit0/EqadcHwUnit1)       */
#define RESOURCE_SUPPORT_EQADC_INST1                /* Supported. EQADC Instance 1(EqadcHwUnit2/EqadcHwUnit3)       */
/* RESOURCE_SUPPORT_EQADC_INST2 */                  /* Unsupported. EQADC Instance 2(EqadcHwUnit4/EqadcHwUnit5)     */
/* RESOURCE_SUPPORT_EQADC_INST3 */                  /* Unsupported. EQADC Instance 3(EqadcHwUnit6/EqadcHwUnit7)     */
/* RESOURCE_SUPPORT_EQADC_INST4 */                  /* Unsupported. EQADC Instance 4(EqadcHwUnit8/EqadcHwUnit9)     */
/* RESOURCE_SUPPORT_EQADC_INST5 */                  /* Unsupported. EQADC Instance 5(EqadcHwUnit10/EqadcHwUnit11)   */
/* RESOURCE_SUPPORT_EQADC_INST6 */                  /* Unsupported. EQADC Instance 6(EqadcHwUnit12)                 */
/*
 * Classification: EQADC Instance Function (EQADC Function Definition Macro) */
/* RESOURCE_SUPPORT_EQADC_RED_LINE_CLIENT_CONFIG */ /* Unsupported. Red Line Client Configuration                   */
/* RESOURCE_SUPPORT_EQADC_SIUL2_TRIG_SRC_LIMIT */   /* Unsupported. eQADC CFIFO Trigger Source Limitation           */
#define RESOURCE_SUPPORT_EQADC_VREF_SW_CTRL_1       (1U)    /* The enable bit of SDADC needs to be turned on,
                                                             * SSCM module offsets the 0x38 register, bit2/3        */
#define RESOURCE_SUPPORT_EQADC_VREF_SW_CTRL_2       (2U)    /* SSCM module offsets the 0x38 register, bit2/3/4      */
#define RESOURCE_SUPPORT_EQADC_VREF_SW_CTRL_3       (3U)    /* SSCM module offsets the 0x38 register, bit2/3        */
#define RESOURCE_SUPPORT_EQADC_VREF_SW              RESOURCE_SUPPORT_EQADC_VREF_SW_CTRL_3
#define RESOURCE_SUPPORT_EQADC_TRIG_DELAY           /* Supported. Function: EQADC CFIFO delay trigger               */
#define RESOURCE_SUPPORT_EQADC_FIFO_CNT_6           (6U)    /* CFIFO_0 - CFIFO_5, RFIFO_0 - RFIFO_5                 */
#define RESOURCE_SUPPORT_EQADC_FIFO_CNT_8           (8U)    /* CFIFO_0 - CFIFO_7, RFIFO_0 - RFIFO_7                 */
#define RESOURCE_SUPPORT_EQADC_FIFO_CNT             RESOURCE_SUPPORT_EQADC_FIFO_CNT_8
#define RESOURCE_SUPPORT_EQADC_RFIFO_ENTRY_CNT_4    (4U)    /* The entry of RFIFOx: 4                               */
#define RESOURCE_SUPPORT_EQADC_RFIFO_ENTRY_CNT_8    (8U)    /* The entry of RFIFOx: 8                               */
#define RESOURCE_SUPPORT_EQADC_RFIFO_ENTRY_CNT      RESOURCE_SUPPORT_EQADC_RFIFO_ENTRY_CNT_8
#if (defined(RESOURCE_SUPPORT_EQADC_FIFO_CNT) && (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8))
#define RESOURCE_SUPPORT_EQADC_CFIFO_INJECTION      /* Supported. Injection of CFIFOx                               */
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */
#define RESOURCE_SUPPORT_EQADC_RFIFO_CLK_SWITCH     /* Supported. Clock Switch Enable for RFIFOx                    */
#define RESOURCE_SUPPORT_EQADC_RFIFO_SOFT_RESET     /* Supported. RFIFO Software Reset                              */
#define RESOURCE_SUPPORT_EQADC_FIFO_DMA_CTRL_SEL    /* Supported. CFIFOx/RFIFOx DMA ControllerSelect: DMA_0/DMA_1   */
/* RESOURCE_SUPPORT_EQADC_WAKEUP */                 /* Unsupported. eQADC Wakeup function from low power mode       */
/*
 * Classification: EQADC On-Chip ADC Configuration (EQADC Function Definition Macro) */
#define RESOURCE_SUPPORT_EQADC_CFG_OPEN_2_EMUX      /* Supported. Both EMUX switches are turned on simultaneously   */
/* RESOURCE_SUPPORT_EQADC_CFG_ALL_ADC_2MSPS */      /* Unsupported. All ADC support a rate of 2MSPS                 */
#define RESOURCE_SUPPORT_EQADC_CFG_ADC0_2MSPS       /* Supported. Only ADC0 supports a rate of 2MSPS                */
#define RESOURCE_SUPPORT_EQADC_CFG_PRECHARGE        /* Supported. Precharge clock cycles selection.                 */
/* RESOURCE_SUPPORT_EQADC_CFG_MONITOR */            /* Unsupported. ADC channel sampling and conversion monitoring  */
/* RESOURCE_SUPPORT_EQADC_CFG_AUTO_SHIFT */         /* Unsupported. Data auto >> 2bits. Default on                  */
/*
 * Classification: EQADC ADC Command (EQADC Function Definition Macro) */
#define RESOURCE_SUPPORT_EQADC_CMD_OSR              /* Supported. OverSample rate selection                         */
#define RESOURCE_SUPPORT_EQADC_CMD_LST_2BIT         (0U)    /* Long Sampling Time: 2/8/64/128 Cycles                */
#define RESOURCE_SUPPORT_EQADC_CMD_LST_3BIT         (1U)    /* Long Sampling Time: 2/4/6/8/16/32/64/128 Cycles      */
#define RESOURCE_SUPPORT_EQADC_CMD_LST              RESOURCE_SUPPORT_EQADC_CMD_LST_3BIT

/*----------------------------------SDADC: Sigma Delta ADC------------------*/
/* RESOURCE_SUPPORT_SDADC_IP */             /* Unsupported. IP: SDADC */
#ifdef RESOURCE_SUPPORT_SDADC_IP
/* RESOURCE_SUPPORT_SDADC0  */              /* Unsupported. SDADC Instance 0  */
/* RESOURCE_SUPPORT_SDADC1  */              /* Unsupported. SDADC Instance 1  */
/* RESOURCE_SUPPORT_SDADC2  */              /* Unsupported. SDADC Instance 2  */
/* RESOURCE_SUPPORT_SDADC3  */              /* Unsupported. SDADC Instance 3  */
/* RESOURCE_SUPPORT_SDADC4  */              /* Unsupported. SDADC Instance 4  */
/* RESOURCE_SUPPORT_SDADC5  */              /* Unsupported. SDADC Instance 5  */
/* RESOURCE_SUPPORT_SDADC6  */              /* Unsupported. SDADC Instance 6  */
/* RESOURCE_SUPPORT_SDADC7  */              /* Unsupported. SDADC Instance 7  */
/* RESOURCE_SUPPORT_SDADC8  */              /* Unsupported. SDADC Instance 8  */
/* RESOURCE_SUPPORT_SDADC9  */              /* Unsupported. SDADC Instance 9  */
/* RESOURCE_SUPPORT_SDADC10 */              /* Unsupported. SDADC Instance 10 */
/* RESOURCE_SUPPORT_SDADC11 */              /* Unsupported. SDADC Instance 11 */
/* RESOURCE_SUPPORT_SDADC12 */              /* Unsupported. SDADC Instance 12 */
/* RESOURCE_SUPPORT_SDADC13 */              /* Unsupported. SDADC Instance 13 */
#endif

/*----------------------------------ACMP: Analog Comparator-----------------*/
/* RESOURCE_SUPPORT_ACMP */                 /* Unsupported. IP: ACMP */

/*----------------------------------FCCU-------------------------------------*/
#define RESOURCE_SUPPORT_FCCU_EOUT_FREQ_EXT /* Supported.  FCCU EOUT frequency extend to 15.6kHz */

/*----------------------------------DAC: Digital-to-analog converter--------*/
/* RESOURCE_SUPPORT_DAC */                  /* Unsupported. IP: DAC */

/*----------------------------------STM: System Timer Module----------------*/
#define RESOURCE_STM_INSTANCE_NUM           (1U)
#define RESOURCE_SUPPORT_STM0               /* Supported. STM 0 */
/* RESOURCE_SUPPORT_STM1 */                 /* Unsupported. STM 1 */
/* RESOURCE_SUPPORT_STM2 */                 /* Unsupported. STM 2 */
/* RESOURCE_SUPPORT_STM3 */                 /* Unsupported. STM 3 */
/* RESOURCE_SUPPORT_STM4 */                 /* Unsupported. STM 4 */
/* RESOURCE_SUPPORT_STM5 */                 /* Unsupported. STM 5 */

/*----------------------------------PIT: Periodic Interrupt Timer-----------*/
#define RESOURCE_SUPPORT_CLKSRC_AC0DC0      /* Supported. Clock Source AC0DC0    */
/* RESOURCE_SUPPORT_CLKSRC_AC0DC4 */        /* Unsupported. Clock Source AC0DC4    */
#define RESOURCE_SUPPORT_PIT0               /* Supported. PIT 0 */
#define RESOURCE_SUPPORT_PIT1               /* Supported. PIT 1 */
#define RESOURCE_SUPPORT_PIT_TRIG_DMA       /* Supported. Function: PIT trigger DMA */

/*----------------------------------RTC/API: -------------------------------
 *----------------------Real Time Clock/Autonomous Periodic Interrupt-------*/
#define RESOURCE_SUPPORT_RTC_API            /* Supported. IP: RTC/API */

/*----------------------------------SWT: Software Watchdog Timer------------*/
#define RESOURCE_SUPPORT_SWT0               /* Supported. SWT 0 */
/* RESOURCE_SUPPORT_SWT1 */                 /* Unsupported. SWT 1 */
/* RESOURCE_SUPPORT_SWT2 */                 /* Unsupported. SWT 2 */
#define RESOURCE_SUPPORT_SWT3               /* Supported. SWT 3 */
/* RESOURCE_SUPPORT_SWT4 */                 /* Unsupported. SWT 4 */
/* RESOURCE_SUPPORT_SWT5 */                 /* Unsupported. SWT 5 */
/* RESOURCE_SUPPORT_SWT6 */                 /* Unsupported. SWT 6 */
#define RESOURCE_SUPPORT_SWT7_AO            /* Supported. SWT 7_AO */
#define RESOURCE_SUPPORT_WDG_ADDRMODE       /* Supported. Address feed the dog */
#ifdef RESOURCE_SUPPORT_SWT7_AO
#define RESOURCE_SUPPORT_SWT_AO_CTRL_0       0U /* SWT7 Enable Method 0  */
#define RESOURCE_SUPPORT_SWT_AO_CTRL_1       1U /* SWT7 Enable Method 1 */
#define RESOURCE_SUPPORT_SWT_AO_CTRL         RESOURCE_SUPPORT_SWT_AO_CTRL_0
#endif

/*----------------------------------eMIOS: Enhanced Modular IO Subsystem----*/
#define RESOURCE_SUPPORT_EMIOS0             /* Supported. eMIOS_0    */
#define RESOURCE_SUPPORT_EMIOS1             /* Supported. eMIOS_1    */
#define RESOURCE_SUPPORT_EMIOS0_CH0_7       /* Supported. eMIOS_0 Channel_0~7.     */
/* RESOURCE_SUPPORT_EMIOS0_CH8_15 */        /* Unsupported. eMIOS_0 Channel_8~15.  */
#define RESOURCE_SUPPORT_EMIOS0_CH16_23     /* Supported. eMIOS_0 Channel_16~23.   */
/* RESOURCE_SUPPORT_EMIOS0_CH24_31 */       /* Unsupported. eMIOS_0 Channel_24~31. */
#define RESOURCE_SUPPORT_EMIOS1_CH0_7       /* Supported. eMIOS_1 Channel_0~7.     */
/* RESOURCE_SUPPORT_EMIOS1_CH8_15 */        /* Unsupported. eMIOS_1 Channel_8~15.  */
#define RESOURCE_SUPPORT_EMIOS1_CH16_23     /* Supported. eMIOS_1 Channel_16~23.   */
/* RESOURCE_SUPPORT_EMIOS1_CH24_31 */       /* Unsupported. eMIOS_1 Channel_24~31. */
#define RESOURCE_SUPPORT_EMIOS_OPWMT        /* Supported. eMIOS Mode: OPWMT.       */
/* RESOURCE_SUPPORT_EMIOS_CH_CONTINUE */    /* Unsupported. eMIOS channel continue */

/*----------------------------------eTPU: Enhanced Time Processing Unit-----*/
/* RESOURCE_SUPPORT_ETPU */                 /* Unsupported. IP: eTPU */

/*----------------------------------GTM: Generic Timer Module---------------*/
/* RESOURCE_SUPPORT_GTM104 */               /* Unsupported. IP: GTM1.04, about 18 submodules. */
#define RESOURCE_SUPPORT_GTM410             /* Supported. IP: GTM4.10, about 26 submodules. */
#define RESOURCE_SUPPORT_GTM_TIM0           /* Supported. GTM TIM0 */
#define RESOURCE_SUPPORT_GTM_TIM1           /* Supported. GTM TIM1 */
/* RESOURCE_SUPPORT_GTM_TIM2 */             /* Unsupported. GTM TIM2 */
/* RESOURCE_SUPPORT_GTM_TIM3 */             /* Unsupported. GTM TIM3 */
/* RESOURCE_SUPPORT_GTM_TIM4 */             /* Unsupported. GTM TIM4 */
/* RESOURCE_SUPPORT_GTM_TIM5 */             /* Unsupported. GTM TIM5 */
/* RESOURCE_SUPPORT_GTM_TIM6 */             /* Unsupported. GTM TIM6 */
/* RESOURCE_SUPPORT_GTM_TIM7 */             /* Unsupported. GTM TIM7 */
#ifdef RESOURCE_SUPPORT_GTM410
/* RESOURCE_SUPPORT_GTM410_2CLS */          /* Unsupported. GTM4.10, instance number */
/* RESOURCE_SUPPORT_GTM410_8CLS */          /* Unsupported. GTM4.10, instance number */
#define RESOURCE_SUPPORT_GTM410_CLS_NUM   (3u)
#define RESOURCE_SUPPORT_GTM410_TOUT        /* Supported. GTM4.10, tout */
#define RESOURCE_SUPPORT_GTM_TRIG_EQADC     /* Supported. GTM Trigger EQADC */
#define RESOURCE_SUPPORT_GTM_TO_EQADC       /* Supported. GTM to EQADC Connections(Optional) */
#define RESOURCE_SUPPORT_GTM_TO_MSC         /* Supported. GTM Trigger MSC */
#define RESOURCE_SUPPORT_GTM_HRESPWM        /* supported. GTM High Resolution PWM */
#define RESOURCE_SUPPORT_GTM_TIMINPUTSEL    /* Supported. GTM input select */

#define RESOURCE_SUPPORT_GTM_ATOM_NUM     (3u)    /* Supported. GTM4.10, ATOM number */
#define RESOURCE_SUPPORT_GTM_TOM_NUM      (2u)    /* Supported. GTM4.10, TOM number */

#define RESOURCE_SUPPORT_GTM410_CLS0        /* Supported. GTM4.10, CLS0 */
#define RESOURCE_SUPPORT_GTM410_CLS1        /* Supported. GTM4.10, CLS1 */
#define RESOURCE_SUPPORT_GTM410_CLS2        /* Supported. GTM4.10, CLS2 */
/* RESOURCE_SUPPORT_GTM410_CLS3 */          /* Unsupported. GTM4.10, CLS3 */
/* RESOURCE_SUPPORT_GTM410_CLS4 */          /* Unsupported. GTM4.10, CLS4 */
/* RESOURCE_SUPPORT_GTM410_CLS5 */          /* Unsupported. GTM4.10, CLS5 */
/* RESOURCE_SUPPORT_GTM410_CLS6 */          /* Unsupported. GTM4.10, CLS6 */
/* RESOURCE_SUPPORT_GTM410_CLS7 */          /* Unsupported. GTM4.10, CLS7 */
#endif

#define RESOURCE_SUPPORT_GTM_TOM0               /* Supported. GTM TOM0 */
#define RESOURCE_SUPPORT_GTM_TOM1               /* Supported. GTM TOM1 */
/*#define RESOURCE_SUPPORT_GTM_TOM2 */              /* Supported. GTM TOM2 */
/*#define RESOURCE_SUPPORT_GTM_TOM3 */              /* Supported. GTM TOM3 */
/*#define RESOURCE_SUPPORT_GTM_TOM4 */              /* Supported. GTM TOM4 */
/*#define RESOURCE_SUPPORT_GTM_TOM5 */              /* Unsupported. GTM TOM5 */
/*----------------------------------CCU7: Capture/Compare Unit 7------------*/
#define RESOURCE_SUPPORT_CCU7_IP            /* Supported. IP: CCU7, Capture/Compare Unit 7. */

/*---------------------------------PWM3012----------------------------------*/
/* RESOURCE_SUPPORT_PWM3012_IP */           /* Unsupported. IP: PWM3012 */

/*----------------------------------MCAN------------------------------------*/
/* MCAN: 2 MCAN Modules, support 8 MCAN controllers */
#define RESOURCE_SUPPORT_MCAN_CONTROLLER_1      /* Supported. MCAN1 */
#define RESOURCE_SUPPORT_MCAN_CONTROLLER_2      /* Supported. MCAN2 */     
#define RESOURCE_SUPPORT_MCAN_CONTROLLER_3      /* Supported. MCAN3 */
#define RESOURCE_SUPPORT_MCAN_CONTROLLER_4      /* Supported. MCAN4 */
#define RESOURCE_SUPPORT_MCAN_CONTROLLER_5      /* Supported. MCAN5 */
#define RESOURCE_SUPPORT_MCAN_CONTROLLER_6      /* Supported. MCAN6 */
#if ((CCFC_CHIP_MODEL_PACKAGE & CHIP_PAC_MASK) != PAC_TQFP144)
#define RESOURCE_SUPPORT_MCAN_CONTROLLER_7      /* Supported. MCAN7 */
#endif
#define RESOURCE_SUPPORT_MCAN_CONTROLLER_8      /* Supported. MCAN8 */
/* RESOURCE_SUPPORT_MCAN_CONTROLLER_9  */       /* Unsupported. MCAN9 */
/* RESOURCE_SUPPORT_MCAN_CONTROLLER_10 */       /* Unsupported. MCAN10 */
/* RESOURCE_SUPPORT_MCAN_CONTROLLER_11 */       /* Unsupported. MCAN11 */
/* RESOURCE_SUPPORT_MCAN_CONTROLLER_12 */       /* Unsupported. MCAN12 */

#define RESOURCE_SUPPORT_MCAN_RAM_SIZE     (20*1024U)   /* Supported. MCAN: MCAN1~MCAN4 shared 20KB RAM */
#define RESOURCE_SUPPORT_MCAN_RAM1_SIZE    (20*1024U)   /* Supported. MCAN: MCAN5~MCAN8 shared 20KB RAM */
/* RESOURCE_SUPPORT_MCAN_RAM2_SIZE */                   /* Unsupported. MCAN: MCAN9~MCAN12 shared 20KB RAM */

#define RESOURCE_SUPPORT_MCAN_DMU           /* Supported. DMA Interface Unit */
#define RESOURCE_SUPPORT_MCAN_TSU           /* Supported. Timestamping Unit */
#define RESOURCE_SUPPORT_MCAN_CHANGE_EDIAN_CCFC3008PCSN  /* Supported. CAN RAM Hardware Endianess Conversion */
/* RESOURCE_SUPPORT_MCAN_CHANGE_EDIAN */                 /* Unsupported. CAN RAM Hardware Endianess Conversion */

/*----------------------------------MTTCAN------------------------------------*/
/* MTTCAN: 3 MCAN Modules, support 3 MTTCAN controllers */
#define RESOURCE_SUPPORT_MTTCAN_CONTROLLER_0      /* Supported. MTTCAN0 */
#define RESOURCE_SUPPORT_MTTCAN_CONTROLLER_1      /* Supported. MTTCAN1 */
/*  RESOURCE_SUPPORT_MTTCAN_CONTROLLER_2 */       /* Unsupported. MTTCAN2 */     

#define RESOURCE_SUPPORT_MTTCAN_RAM_SIZE     (20*1024U)   /* Supported. MTTCAN0 & MCAN1~MCAN4 shared 20KB RAM */
#define RESOURCE_SUPPORT_MTTCAN_RAM1_SIZE    (20*1024U)   /* Supported. MTTCAN1 & MCAN5~MCAN8 shared 20KB RAM */
/*  RESOURCE_SUPPORT_MTTCAN_RAM2_SIZE  */                 /* Unsupported. MTTCAN2 & MCAN9~MCAN12 shared 20KB RAM */


/*----------------------------------CANFD-----------------------------------*/
/* RESOURCE_SUPPORT_CANFD_IP */                 /* Unsupported. IP: CANFD */

/*----------------------------------CAN SAMPLER-----------------------------*/
#define RESOURCE_SUPPORT_CANSAMPLER_IP          /* Supported. IP: CANSAMPLER */
#define RESOURCE_SUPPORT_CANSAMPLER_27_SOURCES  /* Supported. CAN SAMPLER: support 27 input sources */
/* RESOURCE_SUPPORT_CANSAMPLER_52_SOURCES */    /* Unsupported. CAN SAMPLER: support 52 input sources */

/*----------------------------------DSPI------------------------------------*/
#define RESOURCE_SUPPORT_DSPI_0                     /* Supported. DSPI_0  */
#define RESOURCE_SUPPORT_DSPI_1                     /* Supported. DSPI_1  */
#define RESOURCE_SUPPORT_DSPI_2                     /* Supported. DSPI_2  */
#define RESOURCE_SUPPORT_DSPI_3                     /* Supported. DSPI_3  */
#define RESOURCE_SUPPORT_DSPI_4                     /* Supported. DSPI_4  */
#define RESOURCE_SUPPORT_DSPI_5                     /* Supported. DSPI_5  */
#define RESOURCE_SUPPORT_DSPI_6                     /* Supported. DSPI_6  */
/* RESOURCE_SUPPORT_DSPI_7 */                       /* Unsupported. DSPI_7  */
/* RESOURCE_SUPPORT_DSPI_8 */                       /* Unsupported. DSPI_8  */
/* RESOURCE_SUPPORT_DSPI_9 */                       /* Unsupported. DSPI_9  */
/* RESOURCE_SUPPORT_DSPI_10 */                      /* Unsupported. DSPI_10 */
/* RESOURCE_SUPPORT_DSPI_11 */                      /* Unsupported. DSPI_11 */
#define RESOURCE_SUPPORT_DSPI_12                    /* Supported. DSPI_12 */
/* RESOURCE_SUPPORT_DSPI_13 */                      /* Unsupported. DSPI_13 */
/* RESOURCE_SUPPORT_DSPI_14 */                      /* Unsupported. DSPI_14 */
/* RESOURCE_SUPPORT_DSPI_15 */                      /* Unsupported. DSPI_15 */
/* RESOURCE_SUPPORT_DSPI_16 */                      /* Unsupported. DSPI_16 */
/* RESOURCE_SUPPORT_DSPI_17 */                      /* Unsupported. DSPI_17 */
/* RESOURCE_SUPPORT_DSPI_18 */                      /* Unsupported. DSPI_18 */
/* RESOURCE_SUPPORT_DSPI_19 */                      /* Unsupported. DSPI_19 */
/* RESOURCE_SUPPORT_DSPI_20 */                      /* Unsupported. DSPI_20 */
/* RESOURCE_SUPPORT_DSPI_21 */                      /* Unsupported. DSPI_21 */
#define RESOURCE_SUPPORT_DSPI_LVDS                  /* Supported. exclude CCFC3008PT open LVDS */
/* RESOURCE_SUPPORT_DSPI_LVDS_CCFC3008PT*/          /* Unsupported. CCFC3008PT open LVDS */
#define RESOURCE_SUPPORT_DSPI_DISR                  /* Supported. DSPI Input Select function*/

/*----------------------------------SSI: Synchronous Serial Interface-------*/
/* Note: SSI = QSPI. */
/* RESOURCE_SUPPORT_SSI_IP */               /* Unsupported. IP: SSI */
#ifdef RESOURCE_SUPPORT_SSI_IP
/* RESOURCE_SUPPORT_SSI0 */                 /* Unsupported. SSI 0 */
/* RESOURCE_SUPPORT_SSI1 */                 /* Unsupported. SSI 1 */
#endif

/*----------------------------------LINFlexD--------------------------------*/
#define LINFLEXD_MAX                        (12u)
#define RESOURCE_SUPPORT_LINFLEXD_0         /* Supported. LINFlexD 0  */
#define RESOURCE_SUPPORT_LINFLEXD_1         /* Supported. LINFlexD 1  */
#define RESOURCE_SUPPORT_LINFLEXD_2         /* Supported. LINFlexD 2  */
#define RESOURCE_SUPPORT_LINFLEXD_3         /* Supported. LINFlexD 3  */
/* RESOURCE_SUPPORT_LINFLEXD_4  */          /* Unsupported. LINFlexD 4  */
#define RESOURCE_SUPPORT_LINFLEXD_5         /* Supported. LINFlexD 5  */
#define RESOURCE_SUPPORT_LINFLEXD_6         /* Supported. LINFlexD 6  */
/* RESOURCE_SUPPORT_LINFLEXD_7  */          /* Unsupported. LINFlexD 7  */
/* RESOURCE_SUPPORT_LINFLEXD_8  */          /* Unsupported. LINFlexD 8  */
#define RESOURCE_SUPPORT_LINFLEXD_9         /* Supported. LINFlexD 9  */
#define RESOURCE_SUPPORT_LINFLEXD_10        /* Supported. LINFlexD 10 */
/* RESOURCE_SUPPORT_LINFLEXD_11 */          /* Unsupported. LINFlexD 11 */
#define RESOURCE_SUPPORT_LINFLEXD_12        /* Supported. LINFlexD 12 */
#define RESOURCE_SUPPORT_LINFLEXD_14        /* Supported. LINFlexD 14 */
#define RESOURCE_SUPPORT_LINFLEXD_15        /* Supported. LINFlexD 15 */
#define RESOURCE_SUPPORT_LINFLEXD_16        /* Supported. LINFlexD 16 */

/*----------------------------------I2C-------------------------------------*/
#define RESOURCE_SUPPORT_I2C

/*----------------------------------Ethernet--------------------------------*/
/* RESOURCE_SUPPORT_ETH_EMAC_IP */          /* Unsupported. IP: EMAC, Ethernet Media Access Controller */
/* RESOURCE_SUPPORT_ETH_GMAC_IP */          /* Unsupported. IP: GMAC, Gigabit Ethernet MAC */

/*----------------------------------SENT------------------------------------*/
#define RESOURCE_SUPPORT_SENT               /* Supported. IP: SENT */

/*----------------------------------CSENT-----------------------------------*/
#define RESOURCE_SUPPORT_CSENT              /* Supported. IP: CSENT */

/*----------------------------------PSI5------------------------------------*/
#define RESOURCE_SUPPORT_PSI5_IP            /* Supported. IP: PSI5 */
#define RESOURCE_SUPPORT_PSI5_0             /* Supported. 3 channels: 0-2  */
#define RESOURCE_SUPPORT_PSI5_1             /* Supported. 2 channels: 0-1  */

/*----------------------------------PSI5-S----------------------------------*/
#define RESOURCE_SUPPORT_PSI5_S             /* Supported. IP: PSI5-S */

/*----------------------------------FlexRay---------------------------------*/
/* RESOURCE_SUPPORT_FLEXRAY */              /* Unsupported. IP: FlexRay */
#define FLEXRAY_HW_CH_MAX                   (2U)

/*----------------------------------I2S-------------------------------------*/
#define RESOURCE_SUPPORT_I2S                /* Supported. IP: I2S */

/*----------------------------------SD_EMMC_HOST----------------------------*/
/* RESOURCE_SUPPORT_SD_EMMC */              /* Unsupported. IP: SD_EMMC */

/*----------------------------------SPORT-------------------------------------*/
/* RESOURCE_SUPPORT_SPORT */                /* Unsupported. IP: SPORT */

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

/* Base pointer of flash peripheral */
#define FLS_FMC                 (C55FMC)

/* The size of  1K block. */
#define FLS_1KB_SIZE            (0x400U)
/* The size of  4K block. */
#define FLS_4KB_SIZE            (0x1000U)
/* The size of 16K block. */
#define FLS_16KB_SIZE           (0x4000U)
/* The size of 32K block. */
#define FLS_32KB_SIZE           (0x8000U)
/* The size of 64K block. */
#define FLS_64KB_SIZE           (0x10000U)
/* The size of 256K block. */
#define FLS_256KB_SIZE          (0x40000U)

/*
 * @brief Flash block number for each address space
 * */
/* Low Block Number. */
#define FLS_LOW0_4K_BLOCK       (16U)
#define FLS_LOW1_4K_BLOCK       (16U)
#define FLS_LOW_16K_BLOCK       (0U)
#define FLS_LOW_32K_BLOCK       (0U)
#define FLS_LOW_64K_BLOCK       (0U)
#define FLS_LOW_BLOCK           (FLS_LOW0_4K_BLOCK + FLS_LOW1_4K_BLOCK + FLS_LOW_16K_BLOCK + FLS_LOW_32K_BLOCK + FLS_LOW_64K_BLOCK)
#define FLS_LOW_OFFSET          (0U)

/* Mid Block Number. */
#define FLS_MID_4K_BLOCK        (32U)
#define FLS_MID_16K_BLOCK       (0U)
#define FLS_MID_32K_BLOCK       (0U)
#define FLS_MID_64K_BLOCK       (0U)
#define FLS_MID_BLOCK           (FLS_MID_4K_BLOCK + FLS_MID_16K_BLOCK + FLS_MID_32K_BLOCK + FLS_MID_64K_BLOCK)
#define FLS_MID_OFFSET          (FLS_LOW_OFFSET + FLS_LOW_BLOCK)

/* High Block Number. */
/* In order to comply with the function parameter definition, */
/* the BAF Block and HSM Data Blocks are defined as High Blocks */
#define FLS_HIGH_1K_BLOCK       (8U)
#define FLS_HIGH_16K_BLOCK      (7U)
#define FLS_HIGH_32K_BLOCK      (0U)
#define FLS_HIGH_64K_BLOCK      (0U)
#define FLS_HIGH_BLOCK          (FLS_HIGH_1K_BLOCK + FLS_HIGH_16K_BLOCK + FLS_HIGH_32K_BLOCK + FLS_HIGH_64K_BLOCK)
#define FLS_HIGH_OFFSET         (FLS_MID_OFFSET + FLS_MID_BLOCK)

/* 256K Block Number. */
#define FLS_256K_BLOCK_FIRST    (28U)
#define FLS_256K_BLOCK_SECOND   (0U)
#define FLS_256K_BLOCK          (FLS_256K_BLOCK_FIRST + FLS_256K_BLOCK_SECOND)
#define FLS_256K_FIRST_OFFSET   (FLS_HIGH_OFFSET + FLS_HIGH_BLOCK)
#define FLS_256K_SECOND_OFFSET  (FLS_256K_FIRST_OFFSET + FLS_256K_BLOCK_FIRST)

/* ALL Block Number. */
#define FLS_BLOCK_ALL           (FLS_LOW_BLOCK + FLS_MID_BLOCK + FLS_HIGH_BLOCK + FLS_256K_BLOCK)

/* Flash block offset */
#define FLS_LOCK_OFFSET_LOW       (16U)
#define FLS_LOCK_OFFSET_MID       (0U)
#define FLS_LOCK_OFFSET_MIT       (16U)
#define FLS_LOCK_OFFSET_HIGH      (8U)

/*
 * @brief Flash block mask define
 */
/* Flash block lock mask */
#define FLS_LOCK_MASK_LOW       (0xFFFFFFFFU >> (32U - FLS_LOW_BLOCK))
#define FLS_LOCK_MASK_LOW0      (0xFFFFFFFFU >> (32U - FLS_LOW0_4K_BLOCK))
#define FLS_LOCK_MASK_LOW1      (0xFFFFFFFFU >> (32U - FLS_LOW1_4K_BLOCK))
#define FLS_LOCK_MASK_MID       (0xFFFFFFFFU >> (32U - FLS_MID_BLOCK))
#define FLS_LOCK_MASK_HIGH      (0xFFFFFFFFU >> (32U - FLS_HIGH_BLOCK))
#define FLS_LOCK_MASK_HIGH0     (0xFFFFFFFFU >> (32U - FLS_HIGH_1K_BLOCK))
#define FLS_LOCK_MASK_HIGH1     (0xFFFFFFFFU >> (32U - FLS_HIGH_16K_BLOCK))
#define FLS_LOCK_MASK_FIR256K   (0xFFFFFFFFU >> (32U - FLS_256K_BLOCK_FIRST))
#define FLS_LOCK_MASK_SEC256K   (0x00000000U)

/* Flash block select mask */
#define FLS_SEL_MASK_LOW        (0xFFFFFFFFU >> (32U - FLS_LOW_BLOCK))
#define FLS_SEL_MASK_LOW0       (0xFFFFFFFFU >> (32U - FLS_LOW0_4K_BLOCK))
#define FLS_SEL_MASK_LOW1       (0xFFFFFFFFU >> (32U - FLS_LOW1_4K_BLOCK))
#define FLS_SEL_MASK_MID        (0xFFFFFFFFU >> (32U - FLS_MID_BLOCK))
#define FLS_SEL_MASK_HIGH       (0xFFFFFFFFU >> (32U - FLS_HIGH_BLOCK))
#define FLS_SEL_MASK_HIGH0      (0xFFFFFFFFU >> (32U - FLS_HIGH_1K_BLOCK))
#define FLS_SEL_MASK_HIGH1      (0xFFFFFFFFU >> (32U - FLS_HIGH_16K_BLOCK))
#define FLS_SEL_MASK_FIR256K    (0xFFFFFFFFU >> (32U - FLS_256K_BLOCK_FIRST))
#define FLS_SEL_MASK_SEC256K    (0x00000000U)

/* Flash register numbers */
#define FLS_REG_NUM             (28U)

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

static const flash_info_t flashInfo[FLS_BLOCK_ALL] = {
    /* Low Block */
    {0x00FC0000U, 0x00FC0FFFU, 0U,  0U, FLS_4KB_SIZE},   /* block   0 P0 (Normal Code), Low Block  0 */
    {0x00FC1000U, 0x00FC1FFFU, 0U,  1U, FLS_4KB_SIZE},   /* block   1 P0 (Normal Code), Low Block  1 */
    {0x00FC2000U, 0x00FC2FFFU, 0U,  2U, FLS_4KB_SIZE},   /* block   2 P0 (Normal Code), Low Block  2 */
    {0x00FC3000U, 0x00FC3FFFU, 0U,  3U, FLS_4KB_SIZE},   /* block   3 P0 (Normal Code), Low Block  3 */
    {0x00FC4000U, 0x00FC4FFFU, 0U,  4U, FLS_4KB_SIZE},   /* block   4 P0 (Normal Code), Low Block  4 */
    {0x00FC5000U, 0x00FC5FFFU, 0U,  5U, FLS_4KB_SIZE},   /* block   5 P0 (Normal Code), Low Block  5 */
    {0x00FC6000U, 0x00FC6FFFU, 0U,  6U, FLS_4KB_SIZE},   /* block   6 P0 (Normal Code), Low Block  6 */
    {0x00FC7000U, 0x00FC7FFFU, 0U,  7U, FLS_4KB_SIZE},   /* block   7 P0 (Normal Code), Low Block  7 */
    {0x00FC8000U, 0x00FC8FFFU, 0U,  8U, FLS_4KB_SIZE},   /* block   8 P0 (Normal Code), Low Block  8 */
    {0x00FC9000U, 0x00FC9FFFU, 0U,  9U, FLS_4KB_SIZE},   /* block   9 P0 (Normal Code), Low Block  9 */
    {0x00FCA000U, 0x00FCAFFFU, 0U, 10U, FLS_4KB_SIZE},   /* block  10 P0 (Normal Code), Low Block 10 */
    {0x00FCB000U, 0x00FCBFFFU, 0U, 11U, FLS_4KB_SIZE},   /* block  11 P0 (Normal Code), Low Block 11 */
    {0x00FCC000U, 0x00FCCFFFU, 0U, 12U, FLS_4KB_SIZE},   /* block  12 P0 (Normal Code), Low Block 12 */
    {0x00FCD000U, 0x00FCDFFFU, 0U, 13U, FLS_4KB_SIZE},   /* block  13 P0 (Normal Code), Low Block 12 */
    {0x00FCE000U, 0x00FCEFFFU, 0U, 14U, FLS_4KB_SIZE},   /* block  14 P0 (Normal Code), Low Block 14 */
    {0x00FCF000U, 0x00FCFFFFU, 0U, 15U, FLS_4KB_SIZE},   /* block  15 P0 (Normal Code), Low Block 15 */
    {0x00FD0000U, 0x00FD0FFFU, 1U,  0U, FLS_4KB_SIZE},   /* block  16 P0 (Normal Code), Low Block 16 */
    {0x00FD1000U, 0x00FD1FFFU, 1U,  1U, FLS_4KB_SIZE},   /* block  17 P0 (Normal Code), Low Block 17 */
    {0x00FD2000U, 0x00FD2FFFU, 1U,  2U, FLS_4KB_SIZE},   /* block  18 P0 (Normal Code), Low Block 18 */
    {0x00FD3000U, 0x00FD3FFFU, 1U,  3U, FLS_4KB_SIZE},   /* block  19 P0 (Normal Code), Low Block 19 */
    {0x00FD4000U, 0x00FD4FFFU, 1U,  4U, FLS_4KB_SIZE},   /* block  20 P0 (Normal Code), Low Block 20 */
    {0x00FD5000U, 0x00FD5FFFU, 1U,  5U, FLS_4KB_SIZE},   /* block  21 P0 (Normal Code), Low Block 21 */
    {0x00FD6000U, 0x00FD6FFFU, 1U,  6U, FLS_4KB_SIZE},   /* block  22 P0 (Normal Code), Low Block 22 */
    {0x00FD7000U, 0x00FD7FFFU, 1U,  7U, FLS_4KB_SIZE},   /* block  23 P0 (Normal Code), Low Block 23 */
    {0x00FD8000U, 0x00FD8FFFU, 1U,  8U, FLS_4KB_SIZE},   /* block  24 P0 (Normal Code), Low Block 24 */
    {0x00FD9000U, 0x00FD9FFFU, 1U,  9U, FLS_4KB_SIZE},   /* block  25 P0 (Normal Code), Low Block 25 */
    {0x00FDA000U, 0x00FDAFFFU, 1U, 10U, FLS_4KB_SIZE},   /* block  26 P0 (Normal Code), Low Block 26 */
    {0x00FDB000U, 0x00FDBFFFU, 1U, 11U, FLS_4KB_SIZE},   /* block  27 P0 (Normal Code), Low Block 27 */
    {0x00FDC000U, 0x00FDCFFFU, 1U, 12U, FLS_4KB_SIZE},   /* block  28 P0 (Normal Code), Low Block 28 */
    {0x00FDD000U, 0x00FDDFFFU, 1U, 13U, FLS_4KB_SIZE},   /* block  29 P0 (Normal Code), Low Block 29 */
    {0x00FDE000U, 0x00FDEFFFU, 1U, 14U, FLS_4KB_SIZE},   /* block  30 P0 (Normal Code), Low Block 30 */
    {0x00FDF000U, 0x00FDFFFFU, 1U, 15U, FLS_4KB_SIZE},   /* block  31 P0 (Normal Code), Low Block 31 */

    /* Mid Block */
    {0x00610000U, 0x00610FFFU, 4U,  0U, FLS_4KB_SIZE},   /* block  32 P1 (HSM Data), Mid Block  0 */
    {0x00611000U, 0x00611FFFU, 4U,  1U, FLS_4KB_SIZE},   /* block  33 P1 (HSM Data), Mid Block  1 */
    {0x00612000U, 0x00612FFFU, 4U,  2U, FLS_4KB_SIZE},   /* block  34 P1 (HSM Data), Mid Block  2 */
    {0x00613000U, 0x00613FFFU, 4U,  3U, FLS_4KB_SIZE},   /* block  35 P1 (HSM Data), Mid Block  3 */
    {0x00614000U, 0x00614FFFU, 4U,  4U, FLS_4KB_SIZE},   /* block  36 P1 (HSM Data), Mid Block  4 */
    {0x00615000U, 0x00615FFFU, 4U,  5U, FLS_4KB_SIZE},   /* block  37 P1 (HSM Data), Mid Block  5 */
    {0x00616000U, 0x00616FFFU, 4U,  6U, FLS_4KB_SIZE},   /* block  38 P1 (HSM Data), Mid Block  6 */
    {0x00617000U, 0x00617FFFU, 4U,  7U, FLS_4KB_SIZE},   /* block  39 P1 (HSM Data), Mid Block  7 */
    {0x00618000U, 0x00618FFFU, 4U,  8U, FLS_4KB_SIZE},   /* block  40 P1 (HSM Data), Mid Block  8 */
    {0x00619000U, 0x00619FFFU, 4U,  9U, FLS_4KB_SIZE},   /* block  41 P1 (HSM Data), Mid Block  9 */
    {0x0061A000U, 0x0061AFFFU, 4U, 10U, FLS_4KB_SIZE},   /* block  42 P1 (HSM Data), Mid Block 10 */
    {0x0061B000U, 0x0061BFFFU, 4U, 11U, FLS_4KB_SIZE},   /* block  43 P1 (HSM Data), Mid Block 11 */
    {0x0061C000U, 0x0061CFFFU, 4U, 12U, FLS_4KB_SIZE},   /* block  44 P1 (HSM Data), Mid Block 12 */
    {0x0061D000U, 0x0061DFFFU, 4U, 13U, FLS_4KB_SIZE},   /* block  45 P1 (HSM Data), Mid Block 13 */
    {0x0061E000U, 0x0061EFFFU, 4U, 14U, FLS_4KB_SIZE},   /* block  46 P1 (HSM Data), Mid Block 14 */
    {0x0061F000U, 0x0061FFFFU, 4U, 15U, FLS_4KB_SIZE},   /* block  47 P1 (HSM Data), Mid Block 15 */
    {0x00620000U, 0x00620FFFU, 4U, 16U, FLS_4KB_SIZE},   /* block  48 P1 (HSM Data), Mid Block 16 */
    {0x00621000U, 0x00621FFFU, 4U, 17U, FLS_4KB_SIZE},   /* block  49 P1 (HSM Data), Mid Block 17 */
    {0x00622000U, 0x00622FFFU, 4U, 18U, FLS_4KB_SIZE},   /* block  50 P1 (HSM Data), Mid Block 18 */
    {0x00623000U, 0x00623FFFU, 4U, 19U, FLS_4KB_SIZE},   /* block  51 P1 (HSM Data), Mid Block 19 */
    {0x00624000U, 0x00624FFFU, 4U, 20U, FLS_4KB_SIZE},   /* block  52 P1 (HSM Data), Mid Block 20 */
    {0x00625000U, 0x00625FFFU, 4U, 21U, FLS_4KB_SIZE},   /* block  53 P1 (HSM Data), Mid Block 21 */
    {0x00626000U, 0x00626FFFU, 4U, 22U, FLS_4KB_SIZE},   /* block  54 P1 (HSM Data), Mid Block 22 */
    {0x00627000U, 0x00627FFFU, 4U, 23U, FLS_4KB_SIZE},   /* block  55 P1 (HSM Data), Mid Block 23 */
    {0x00628000U, 0x00628FFFU, 4U, 24U, FLS_4KB_SIZE},   /* block  56 P1 (HSM Data), Mid Block 24 */
    {0x00629000U, 0x00629FFFU, 4U, 25U, FLS_4KB_SIZE},   /* block  57 P1 (HSM Data), Mid Block 25 */
    {0x0062A000U, 0x0062AFFFU, 4U, 26U, FLS_4KB_SIZE},   /* block  58 P1 (HSM Data), Mid Block 26 */
    {0x0062B000U, 0x0062BFFFU, 4U, 27U, FLS_4KB_SIZE},   /* block  59 P1 (HSM Data), Mid Block 27 */
    {0x0062C000U, 0x0062CFFFU, 4U, 28U, FLS_4KB_SIZE},   /* block  60 P1 (HSM Data), Mid Block 28 */
    {0x0062D000U, 0x0062DFFFU, 4U, 29U, FLS_4KB_SIZE},   /* block  61 P1 (HSM Data), Mid Block 29 */
    {0x0062E000U, 0x0062EFFFU, 4U, 30U, FLS_4KB_SIZE},   /* block  62 P1 (HSM Data), Mid Block 30 */
    {0x0062F000U, 0x0062FFFFU, 4U, 31U, FLS_4KB_SIZE},   /* block  63 P1 (HSM Data), Mid Block 31 */

    /* High Block */
    {0x00680000U, 0x006803FFU, 0U, 16U, FLS_1KB_SIZE},   /* block  64 P1 (HSM Data), High Block 0 */
    {0x00680400U, 0x006807FFU, 0U, 17U, FLS_1KB_SIZE},   /* block  65 P1 (HSM Data), High Block 1 */
    {0x00680800U, 0x00680BFFU, 0U, 18U, FLS_1KB_SIZE},   /* block  66 P1 (HSM Data), High Block 2 */
    {0x00680C00U, 0x00680FFFU, 0U, 19U, FLS_1KB_SIZE},   /* block  67 P1 (HSM Data), High Block 3 */
    {0x00681000U, 0x006813FFU, 0U, 20U, FLS_1KB_SIZE},   /* block  68 P1 (HSM Data), High Block 4 */
    {0x00681400U, 0x006817FFU, 0U, 21U, FLS_1KB_SIZE},   /* block  69 P1 (HSM Data), High Block 5 */
    {0x00681800U, 0x00681BFFU, 0U, 22U, FLS_1KB_SIZE},   /* block  70 P1 (HSM Data), High Block 6 */
    {0x00681C00U, 0x00681FFFU, 0U, 23U, FLS_1KB_SIZE},   /* block  71 P1 (HSM Data), High Block 7 */

    {0x00700000U, 0x00703FFFU, 1U, 16U, FLS_16KB_SIZE},  /* block  72 P4 (HSM Code), High Block  8 */
    {0x00708000U, 0x0070BFFFU, 1U, 17U, FLS_16KB_SIZE},  /* block  73 P4 (HSM Code), High Block  9 */
    {0x0070C000U, 0x0070FFFFU, 1U, 18U, FLS_16KB_SIZE},  /* block  74 P4 (HSM Code), High Block 10 */
    {0x00710000U, 0x00713FFFU, 1U, 19U, FLS_16KB_SIZE},  /* block  75 P5 (HSM Code), High Block 11 */
    {0x00718000U, 0x0071BFFFU, 1U, 20U, FLS_16KB_SIZE},  /* block  76 P5 (HSM Code), High Block 12 */
    {0x00404000U, 0x00407FFFU, 1U, 21U, FLS_16KB_SIZE},  /* block  77 P5 (BAF)     , High Block 13 */
    {0x0071C000U, 0x0071FFFFU, 1U, 22U, FLS_16KB_SIZE},  /* block  78 P5 (HSM Code), High Block 14 */

    /* 256K Block */
    {0x01000000U, 0x0100FFFFU, 2U,  0U, FLS_64KB_SIZE},  /* block  79 P4 (Normal Code), Large Block  0 */
    {0x01010000U, 0x0101FFFFU, 2U,  1U, FLS_64KB_SIZE},  /* block  80 P4 (Normal Code), Large Block  1 */
    {0x01020000U, 0x0102FFFFU, 2U,  2U, FLS_64KB_SIZE},  /* block  81 P4 (Normal Code), Large Block  2 */
    {0x01030000U, 0x0103FFFFU, 2U,  3U, FLS_64KB_SIZE},  /* block  82 P4 (Normal Code), Large Block  3 */
    {0x01040000U, 0x0104FFFFU, 2U,  4U, FLS_64KB_SIZE},  /* block  83 P4 (Normal Code), Large Block  4 */
    {0x01050000U, 0x0105FFFFU, 2U,  5U, FLS_64KB_SIZE},  /* block  84 P4 (Normal Code), Large Block  5 */
    {0x01060000U, 0x0106FFFFU, 2U,  6U, FLS_64KB_SIZE},  /* block  85 P4 (Normal Code), Large Block  6 */
    {0x01070000U, 0x0107FFFFU, 2U,  7U, FLS_64KB_SIZE},  /* block  86 P4 (Normal Code), Large Block  7 */
    {0x01080000U, 0x010BFFFFU, 2U,  8U, FLS_256KB_SIZE}, /* block  87 P4 (Normal Code), Large Block  8 */
    {0x010C0000U, 0x010FFFFFU, 2U,  9U, FLS_256KB_SIZE}, /* block  88 P4 (Normal Code), Large Block  9 */
    {0x01100000U, 0x0113FFFFU, 2U, 10U, FLS_256KB_SIZE}, /* block  89 P4 (Normal Code), Large Block 10 */
    {0x01140000U, 0x0117FFFFU, 2U, 11U, FLS_256KB_SIZE}, /* block  90 P4 (Normal Code), Large Block 11 */
    {0x01180000U, 0x011BFFFFU, 2U, 12U, FLS_256KB_SIZE}, /* block  91 P4 (Normal Code), Large Block 12 */
    {0x011C0000U, 0x011FFFFFU, 2U, 13U, FLS_256KB_SIZE}, /* block  92 P4 (Normal Code), Large Block 13 */
    {0x01200000U, 0x0120FFFFU, 2U, 14U, FLS_64KB_SIZE},  /* block  93 P5 (Normal Code), Large Block 14 */
    {0x01210000U, 0x0121FFFFU, 2U, 15U, FLS_64KB_SIZE},  /* block  94 P5 (Normal Code), Large Block 15 */
    {0x01220000U, 0x0122FFFFU, 2U, 16U, FLS_64KB_SIZE},  /* block  95 P5 (Normal Code), Large Block 16 */
    {0x01230000U, 0x0123FFFFU, 2U, 17U, FLS_64KB_SIZE},  /* block  96 P5 (Normal Code), Large Block 17 */
    {0x01240000U, 0x0124FFFFU, 2U, 18U, FLS_64KB_SIZE},  /* block  97 P5 (Normal Code), Large Block 18 */
    {0x01250000U, 0x0125FFFFU, 2U, 19U, FLS_64KB_SIZE},  /* block  98 P5 (Normal Code), Large Block 19 */
    {0x01260000U, 0x0126FFFFU, 2U, 20U, FLS_64KB_SIZE},  /* block  99 P5 (Normal Code), Large Block 20 */
    {0x01270000U, 0x0127FFFFU, 2U, 21U, FLS_64KB_SIZE},  /* block 100 P5 (Normal Code), Large Block 21 */
    {0x01280000U, 0x012BFFFFU, 2U, 22U, FLS_256KB_SIZE}, /* block 101 P5 (Normal Code), Large Block 22 */
    {0x012C0000U, 0x012FFFFFU, 2U, 23U, FLS_256KB_SIZE}, /* block 102 P5 (Normal Code), Large Block 23 */
    {0x01300000U, 0x0133FFFFU, 2U, 24U, FLS_256KB_SIZE}, /* block 103 P5 (Normal Code), Large Block 24 */
    {0x01340000U, 0x0137FFFFU, 2U, 25U, FLS_256KB_SIZE}, /* block 104 P5 (Normal Code), Large Block 25 */
    {0x01380000U, 0x013BFFFFU, 2U, 26U, FLS_256KB_SIZE}, /* block 105 P5 (Normal Code), Large Block 26 */
    {0x013C0000U, 0x013FFFFFU, 2U, 27U, FLS_256KB_SIZE}, /* block 106 P5 (Normal Code), Large Block 27 */
};

static const flash_regs_t flashRegs[FLS_REG_NUM] = {
    {"MCR",    0x00000600U,     0xfffe0000U},
    {"MCRA",   0x00000600U,     0xfffe0004U},
    {"MCRE",   0x0600002AU,     0xfffe0008U},
    {"LOCK0",  0xBFFFFFFFU,     0xfffe0010U},
    {"LOCK1",  0x0000FFFFU,     0xfffe0014U},
    {"LOCK2",  0xFFFFFFFFU,     0xfffe0018U},
    {"LOCK3",  0x0000FFFFU,     0xfffe001cU},
    {"LOCK0A", 0xBFFFFFFFU,     0xfffe0028U},
    {"LOCK1A", 0x0000FFFFU,     0xfffe002cU},
    {"SEL0",   0x00000000U,     0xfffe0038U},
    {"SEL1",   0x00000000U,     0xfffe003cU},
    {"SEL2",   0x00000000U,     0xfffe0040U},
    {"SEL3",   0x00000000U,     0xfffe0044U},
    {"UT0",    0x00000001U,     0xfffe0054U},
    {"UM0",    0x00000000U,     0xfffe0058U},
    {"UM1",    0x00000000U,     0xfffe005cU},
    {"UM2",    0x00000000U,     0xfffe0060U},
    {"UM3",    0x00000000U,     0xfffe0064U},
    {"UM4",    0x00000000U,     0xfffe0068U},
    {"UM5",    0x00000000U,     0xfffe006cU},
    {"UM6",    0x00000000U,     0xfffe0070U},
    {"UM7",    0x00000000U,     0xfffe0074U},
    {"UM8",    0x00000000U,     0xfffe0078U},
    {"UM9",    0x00000000U,     0xfffe007cU},
    {"OPP1",   0x0000FF00U,     0xfffe0084U},
    {"OPP2",   0x00000000U,     0xfffe0088U},
    {"OPP3",   0x00000000U,     0xfffe008cU},
    {"TMD",    0x00000000U,     0xfffe0090U},
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

/* SMPU0 protect address region */
#define SMPU0_START_ADDR            (0x00000000U)
#define SMPU0_END_ADDR              (0xEFFFFFFFU)

/* SMPU1 protect address region */
#define SMPU1_START_ADDR            (0xF0000000U)
#define SMPU1_END_ADDR              (0xFFFFFFFFU)


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
#define FEATURE_EMIOS_CH_23_16_SUB_OFFSET(x)    ((x) - 8U)
#define FEATURE_EMIOS_CH_31_24_SUB_OFFSET(x)    (x)




/*******************************************************************************
**                          Global Macro Declarations                         **
*******************************************************************************/

/** No Error */
#define ERR_LOG_SUCCESS                                              0

/** Standard Error */
#define ERR_LOG_ERROR                                                (-1)

/** Invalid user API function ID */
#define ERR_LOG_CODE_INVALID_USER_FID                                (0xFE000000U)

/** Invalid user API function ID */
#define ERR_LOG_CODE_UNPRIVILEGED                                    (0xFF000000U)

/** Mismatch in received number of bytes for the BSL command */
#define ERR_LOG_CODE_BSL_RECV_BYTES_MISMATCH                         (-2)

/** Invalid BSL parameters to NVM erase command */
#define ERR_LOG_CODE_NVM_ERASE_PARAMS_INVALID                        (-3)

/** Specified customer configured UBSL size is invalid */
#define ERR_LOG_CODE_INVALID_CUSTOMER_CONFIG_UBSL_SIZE               (-4)

/** Customer configured UBSL size or privilege already programmed or read error */
#define ERR_LOG_CODE_UBSL_CONFIG_ALREADY_SET_OR_READ_ERR             (-5)

/** Customer configured UBSL size can't be changed when code is present in NVM */
#define ERR_LOG_CODE_NVM_CODE_PROGRAMMED                             (-6)

/** BSL: Calculated NVM checksum does not match */
#define ERR_LOG_CODE_BSL_NVM_CALC_CHECKSUM_MISMATCH                  (-7)

/** Memory address range is invalid */
#define ERR_LOG_CODE_MEM_ADDR_RANGE_INVALID                          (-8)

/** Invalid baudrate parameter or current BSL interface does not support it */
#define ERR_LOG_CODE_BAUDRATE_SET_FAIL                               (-9)

/** BSL command validity failed */
#define ERR_LOG_CODE_CMD_VALIDITY_FAIL                               (-12)

/** Received unknown BSL command ID */
#define ERR_LOG_CODE_BSL_CID_INVALID                                 (-13)

/** Key write failed due to protection setting */
#define ERR_LOG_CODE_KEY_PROTECTED                                   (-14)

/** Key write failed due to invalid key version */
#define ERR_LOG_CODE_KEY_VERSION                                     (-15)

/** Key write failed due to invalid key size */
#define ERR_LOG_CODE_KEY_SIZE                                        (-16)

/**{ */
#define ERR_LOG_CODE_KEY_ERASE_FAIL                                  (-17)

/** Key slot contains mismatch data between main and backup pages */
#define ERR_LOG_CODE_KEY_SLOT_MISMATCH                               (-18)

/** Key slot contains unrecoverable error */
#define ERR_LOG_CODE_KEY_SLOT_CORRUPTED                              (-19)

/** Key slot contained unrecoverable error and was erased */
#define ERR_LOG_CODE_KEY_VERIFY_FAIL                                 (-20)

/** CMAC verification operation resulted in a mismatch */
#define ERR_LOG_CODE_CMAC_VERIFY_FAIL                                (-21)

/** AES library unsupported error */
#define ERR_LOG_CODE_AES_UNSUPPORTED_ERROR                           (-22)

/** AES library reseed required error */
#define ERR_LOG_CODE_AES_RESEED_NEEDED_ERROR                         (-23)

/** AES library buffer too small error */
#define ERR_LOG_CODE_AES_BUFFER_SMALL_ERROR                          (-24)

/** AES library error */
#define ERR_LOG_CODE_AES_ERROR                                       (-25)

/** Crypto functions are not available */
#define ERR_LOG_CODE_AES_UNAVAILABLE_ERROR                           (-26)

/** Invalid pointer address */
#define ERR_LOG_CODE_USER_POINTER_RAM_RANGE_INVALID                  (-27)

/** Access is not allowed when target segment is protected */
#define ERR_LOG_CODE_SEGMENT_PROTECTED                               (-29)

/** Nested calls are not allowed */
#define ERR_LOG_CODE_SEMAPHORE_RESERVED                              (-30)

/** Factory test BootROM signature read error */
#define ERR_LOG_CODE_FTEST_BOOTROM_SIGNATURE_READ                    (-31)

/** Factory test power module test, P0.1 was not low */
#define ERR_LOG_CODE_TEST_HTOL_PWR_LOW_TEST_FAIL                     (-32)

/** Factory test power module test, P0.1 was not high */
#define ERR_LOG_CODE_TEST_HTOL_PWR_HIGH_TEST_FAIL                    (-33)

/** Factory test HTOL functional burn-in XRAM verification failed */
#define ERR_LOG_CODE_TEST_HTOL_FBI_RAM_FAIL                          (-34)

/** SA encountered an error not possible to repair */
#define ERR_LOG_CODE_SA_UNRECOVERABLE                                (-35)

/** indicate to verification: Only set GPTRC with single mapram sector range init failure */
#define ERR_LOG_CODE_MAPRAM_SECTOR_RANGE_INIT_FAIL                   (-36)

/** Mapped page ECC2 error when trying to init mapRAM */
#define ERR_LOG_CODE_MAPRAM_INIT_PAGE_FAIL                           (-37)

/** Mapped page has double mapping error when trying to init mapRAM */
#define ERR_LOG_CODE_MAPRAM_INIT_DM_PAGE_FAIL                        (-38)

/** Error when setting the assembly buffer to mode 1 or 2 */
#define ERR_LOG_CODE_ACCESS_AB_MODE_ERROR                            (-39)

/** ECC2 data error generated while reading from a NVM page */
#define ERR_LOG_CODE_NVM_ECC2_DATA_ERROR                             (-40)

/** 2 or more bit errors detected in NVM page when verifying NVM data */
#define ERR_LOG_CODE_NVM_VER_ERROR                                   (-41)

/** Mapped page has double mapping or ECC2 error when trying to init mapRAM */
#define ERR_LOG_CODE_MAPRAM_INIT_FAIL                                (-42)

/** NVM programming and mapRAM init update failed after mapped page programming */
#define ERR_LOG_CODE_VERIFY_AND_MAPRAM_INIT_FAIL                     (-43)

/** ECC2 mapBlock error generated while reading from a NVM page */
#define ERR_LOG_CODE_NVM_ECC2_MAPBLOCK_ERROR                         (-44)

/** MAPRAM physical page number for a given logical sector/page is larger than the number of physical pages in a sector */
#define ERR_LOG_CODE_NVM_SPARE_PAGE_NOT_AVAILABLE                    (-45)

/** ECC2 mapRAM error generated while reading mapRAM */
#define ERR_LOG_CODE_NVM_ECC2_MAPRAM_ERROR                           (-46)

/** NVM page is not mapped */
#define ERR_LOG_CODE_NVM_PAGE_NOT_MAPPED                             (-47)

/** Applying of NVM protection from NVM CS failed during bootup */
#define ERR_LOG_CODE_NVM_APPLY_PROTECTION_FAIL                       (-48)

/** NVM HW is not available during startup */
#define ERR_LOG_CODE_NVM_NOT_AVAILABLE                               (-49)

/** ECC2 error, don't trust the data */
#define ERR_LOG_CODE_VIRGIN                                          (-50)

/** Attempt to access NVM 100TP page address outside of the valid range */
#define ERR_LOG_CODE_100TP_PAGE_INVALID                              (-51)

/** NVM 100TP page write count was exceeded */
#define ERR_LOG_CODE_100TP_WRITE_COUNT_EXCEEDED                      (-52)

/** Attempt to access NVM address range which is crossing NVM page boundary */
#define ERR_LOG_CODE_ADDRESS_RANGE_CROSSING_PAGE_BOUNDARY            (-53)

/** NVM config sector checksum calculation failed */
#define ERR_LOG_CODE_CS_PAGE_CHECKSUM                                (-54)

/** MBIST test detected on error */
#define ERR_LOG_CODE_MBIST_FAILED                                    (-55)

/** Boot page checksum size is larger than UBSL region */
#define ERR_LOG_CODE_CHKSUM_SIZE_INVALID                             (-56)

/** Invalid reset handler in boot page */
#define ERR_LOG_CODE_INVALID_BOOT_CONFIG                             (-57)

/** An ECC2 error occurred while reading boot page */
#define ERR_LOG_CODE_START_PAGE_ECC2READ                             (-58)

/** Analog trimming address check failed */
#define ERR_LOG_CODE_ANA_TRIM_ADDRESS                                (-59)

/** Analog trimming data block contains wrong magic field */
#define ERR_LOG_CODE_ANA_TRIM_MAGIC                                  (-60)

/** Analog trimming data block is not 32-bit aligned */
#define ERR_LOG_CODE_ANA_TRIM_NOT_ALIGNED                            (-61)

/** First phase internal analog module trimming failed */
#define ERR_LOG_CODE_AM_TRIM_INTERNAL_1                              (-62)

/** Second phase internal analog module trimming failed */
#define ERR_LOG_CODE_AM_TRIM_INTERNAL_2                              (-63)

/** Customer analog module trimming phase failed */
#define ERR_LOG_CODE_AM_TRIM_CUSTOMER                                (-64)

/** Analog module trimming data validity check failed */
#define ERR_LOG_CODE_AM_TRIM_DATA_NOT_VALID                          (-65)

/** Invalid parameter */
#define ERR_LOG_CODE_PARAM_INVALID                                   (-66)

/** Single ECC event has occurred */
#define ERR_LOG_CODE_ECC1READ_ERROR                                  (-67)

/** Double or more ECC event has occurred */
#define ERR_LOG_CODE_ECC2READ_ERROR                                  (-68)

/** Invalid passphrase or passphrase not configured */
#define ERR_LOG_CODE_USER_PROTECT_WRONG_PASSWORD                     (-69)

/** user_ram_mbist() RAM range for MBIST is invalid */
#define ERR_LOG_CODE_MBIST_RAM_RANGE_INVALID                         (-70)

/** Invalid secure container size */
#define ERR_LOG_CODE_SIZE_INVALID                                    (-72)

/** \brief Error codes definition
 * \brief ERR_LOG_SUCCESS, value 0 already defined in the error codes list from Firmware
 * \brief ERR_LOG_ERROR, value -1 already defined in the error codes list from Firmware
 */
#define ERR_LOG_CODE_MODULE_DISABLED_IN_CW  (-116)  /**< \brief One or more modules disabled in Config Wizard */
#define ERR_LOG_CODE_TIMEOUT                (-101)  /**< \brief Timeout */
#define ERR_LOG_CODE_INVALID_VALUE          (-103)  /**< \brief Invalid output value */
#define ERR_LOG_CODE_ADC1_SEQ_NOT_RUNNING   (-104)  /**< \brief ADC1 sequence not running */
#define ERR_LOG_CODE_ADC2_SEQ_NOT_RUNNING   (-105)  /**< \brief ADC2 sequence not running */
#define ERR_LOG_CODE_NO_TRIGGER             (-106)  /**< \brief No watchdog trigger */
#define ERR_LOG_CODE_SOW_DISABLED           (-107)  /**< \brief No Short Open Window activated */
#define ERR_LOG_CODE_PARAM_OUT_OF_RANGE     (-122)  /**< \brief Parameter out of range */
#define ERR_LOG_CODE_SAFE_SHUTDOWN_ACTIVE   (-118)  /**< \brief Safe Shutdown active */
#define ERR_LOG_CODE_ERR_BDRV_INIT          (-114)  /**< \brief Several errors in the BDRV initialization */

/* PWM_PAL module features */
#define FEATURE_PWMPAL_EMIOS_HAS_CHANNEL_MAPPING    (1)
#define PWMPAL_INDEX_2_HW_CHANNELS {0,1,2,3,4,5,6,7,16,17,18,19,20,21,22,23}

/* SIUL2 MSCR IO */
#define PA0     0
#define PA1     1
#define PA2     2
#define PA3     3
#define PA4     4
#define PA8     8
#define PA9     9
#define PA10    10
#define PA11    11
#define PA12    12
#define PA13    13
#define PA15    15
#define PB4     20
#define PB8     24
#define PB10    26
#define PB11    27
#define PC0     32
#define PC1     33
#define PC2     34
#define PC3     35
#define PC4     36
#define PC5     37
#define PC6     38
#define PC7     39
#define PC8     40
#define PC9     41
#define PC10    42
#define PC11    43
#define PC12    44
#define PC13    45
#define PC14    46
#define PC15    47
#define PD0     48
#define PD1     49
#define PD2     50
#define PD3     51
#define PD6     54
#define PD7     55
#define PD10    58
#define PD11    59
#define PD12    60
#define PD14    62
#define PD15    63
#define PE0     64
#define PE2     66
#define PE3     67
#define PE4     68
#define PE5     69
#define PE8     72
#define PE10    74
#define PE12    76
#define PE13    77
#define PF2     82
#define PF3     83
#define PF4     84
#define PF5     85
#define PF6     86
#define PF7     87
#define PF8     88
#define PF13    93
#define PF14    94
#define PF15    95
#define PG0     96
#define PG7     103
#define PG8     104
#define PG9     105
#define PG11    107
#define PG12    108
#define PG13    109
#define PG14    110
#define PH0     112
#define PH1     113
#define PH2     114
#define PH3     115
#define PH4     116
#define PH6     118
#define PH7     119
#define PH9     121
#define PH10    122
#define PH11    123
#define PH12    124
#define PH13    125
#define PI2     130
#define PI5     133
#define PI6     134
#define PI7     135
#define PI8     136
#define PI10    138
#define PI12    140
#define PJ0     144
#define PJ3     147
#define PJ6     150
#define PJ9     153
#define PJ11    155
#define PJ13    157
#define PJ15    159
#define PK4     164
#define PK6     166
#define PK7     167
#define PK8     168
#define PL0     176
#define PL3     179
#define PL9     185
#define PL14    190
#define PM7     199
#define PM10    202
#define PM11    203
#define PM12    204
#define PM13    205
#define PM14    206
#define PM15    207
#define PN6     214
#define PN7     215
#define PN8     216
#define PN10    218
#define PN11    219
#define PN12    220
#define PN13    221
#define PN14    222
#define PQ0     224
#define PQ1     225
#define PQ3     227
#define PQ5     229
#define PQ6     230
#define PQ7     231
#define PQ8     232
#define PQ9     233
#define PQ10    234
#define PQ11    235
#define PQ12    236
#define PQ13    237
#define PQ15    239
#define PR7     247
#define PR11    251
#define PR14    254
#define PS1     257
#define PX2     322
#define PX3     323
#define PX4     324
#define PX5     325
#define PX6     326
#define PX7     327
#define PX8     328
#define PX9     329
#define PX11    331

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
#define EIRQ_MAX_NUM    (16U)

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

/* #define MC_ME_PERIPH_INSTANCE_COUNT 67U */

/*! @brief Clock names. */
/* typedef enum {
    MC_ME_PCTL_SIUL_INDEX                    = 15u,
    MC_ME_PCTL_PIT_RTC_0_INDEX               = 30u,
    MC_ME_PCTL_PIT_RTC_1_INDEX               = 31u,
    MC_ME_PCTL_DMAMUX_INDEX                  = 36u,
    MC_ME_PCTL_CRC_0_INDEX                   = 38u,
    MC_ME_PCTL_CAM_RAM_1_INDEX               = 66u,
    MC_ME_PCTL_MCAN4_INDEX                   = 67u,
    MC_ME_PCTL_MCAN3_INDEX                   = 68u,
    MC_ME_PCTL_MCAN2_INDEX                   = 69u,
    MC_ME_PCTL_MCAN1_INDEX                   = 70u,
    MC_ME_PCTL_TTCAN_1_INDEX                 = 71u,
    MC_ME_PCTL_TTCAN_INDEX                   = 72u,
    MC_ME_PCTL_CAN_RAM_CTRL_INDEX            = 74u,
    MC_ME_PCTL_MCAN5_INDEX                   = 75u,
    MC_ME_PCTL_MCAN6_INDEX                   = 76u,
    MC_ME_PCTL_MCAN7_INDEX                   = 77u,
    MC_ME_PCTL_MCAN8_INDEX                   = 78u,
    MC_ME_PCTL_CAN_SAMPLER_INDEX             = 82u,
    MC_ME_PCTL_RTC_INDEX                     = 83u,
    MC_ME_PCTL_LINFlexD_16_INDEX             = 84u,
    MC_ME_PCTL_LINFlexD_14_INDEX             = 85u,
    MC_ME_PCTL_LINFlexD_6_INDEX              = 87u,
    MC_ME_PCTL_LINFlexD_5_INDEX              = 88u,
    MC_ME_PCTL_LINFlexD_3_INDEX              = 90u,
    MC_ME_PCTL_LINFlexD_1_INDEX              = 91u,
    MC_ME_PCTL_LINFlexD_0_INDEX              = 92u,
    MC_ME_PCTL_DSPI_12_INDEX                 = 93u,
    MC_ME_PCTL_DSPI_6_INDEX                  = 96u,
    MC_ME_PCTL_DSPI_4_INDEX                  = 97u,
    MC_ME_PCTL_DSPI_1_INDEX                  = 98u,
    MC_ME_PCTL_DSPI_0_INDEX                  = 99u,
    MC_ME_PCTL_IIC_0_INDEX                   = 101u,
    MC_ME_PCTL_SENT_INDEX                    = 104u,
    MC_ME_PCTL_PSI5_0_INDEX                  = 111u,
    MC_ME_PCTL_ADCSAR_b_INDEX                = 112u,
    MC_ME_PCTL_ADCSAR_4_INDEX                = 123u,
    MC_ME_PCTL_ADCSAR_0_INDEX                = 127u,
    MC_ME_PCTL_GTMINT_INDEX                  = 128u,
    MC_ME_PCTL_EMIOS_0_INDEX                 = 131u,
    MC_ME_PCTL_EMIOS_1_INDEX                 = 132u,
    MC_ME_PCTL_CCU_0_INDEX                   = 135u,
    MC_ME_PCTL_CCU_1_INDEX                   = 136u,
    MC_ME_PCTL_PSI5_S_0_INDEX                = 162u,
    MC_ME_PCTL_CRC_1_INDEX                   = 166u,
    MC_ME_PCTL_LINFlexD_15_INDEX             = 213u,
    MC_ME_PCTL_LINFlexD_12_INDEX             = 214u,
    MC_ME_PCTL_LINFlexD_11_INDEX             = 215u,
    MC_ME_PCTL_LINFlexD_10_INDEX             = 216u,
    MC_ME_PCTL_LINFlexD_9_INDEX              = 217u,
    MC_ME_PCTL_LINFlexD_8_INDEX              = 218u,
    MC_ME_PCTL_LINFlexD_7_INDEX              = 219u,
    MC_ME_PCTL_LINFlexD_2_INDEX              = 220u,
    MC_ME_PCTL_DSPI_5_INDEX                  = 225u,
    MC_ME_PCTL_DSPI_3_INDEX                  = 226u,
    MC_ME_PCTL_DSPI_2_INDEX                  = 227u,
    MC_ME_PCTL_IIC_1_INDEX                   = 229u,
    MC_ME_PCTL_SENT_1_INDEX                  = 232u,
    MC_ME_PCTL_PSI5_1_INDEX                  = 239u,
    MC_ME_PCTL_ADCSAR_10_INDEX               = 245u,
    MC_ME_PCTL_ADCSAR_9_INDEX                = 246u,
    MC_ME_PCTL_ADCSAR_8_INDEX                = 247u,
    MC_ME_PCTL_ADCSAR_7_INDEX                = 248u,
    MC_ME_PCTL_ADCSAR_6_INDEX                = 249u,
    MC_ME_PCTL_ADCSAR_5_INDEX                = 250u,
    MC_ME_PCTL_ADCSAR_3_INDEX                = 252u,
    MC_ME_PCTL_ADCSAR_2_INDEX                = 253u,
    MC_ME_PCTL_ADCSAR_1_INDEX                = 254u,
    MC_ME_PCTLn_COUNT                        = 256u,
} peripheral_names_t; */

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


    SWT3_IRQn                   = 35u,  /* Platform watchdog timer3 SWT_3_IR[TIF] */
    STM0_CH0_IRQn               = 36u,  /* Platform periodic timer 0_0 (STM) STM_0_CIR0[CIF] */
    STM0_CH1_IRQn               = 37u,  /* Platform periodic timer 0_1 (STM) STM_0_CIR1[CIF] */
    STM0_CH2_IRQn               = 38u,  /* Platform periodic timer 0_2 (STM) STM_0_CIR2[CIF] */
    STM0_CH3_IRQn               = 39u,  /* Platform periodic timer 0_3 (STM) STM_0_CIR3[CIF] */

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

    FLASH_MCR_DONE_IRQn         = 185u, /* Flash controller Prog/Erase/Suspend IRQ_0 MCR[DONE] */

    CSENT0_RX_ERR_IRQn          = 197u, /* CSENT0 Rx Error Interrupt */
    CSENT0_RX_VALID_IRQn        = 198u, /* CSENT0 Rx Valid Interrupt */
    CSENT0_TX_ACTIVE_IRQn       = 199u, /* CSENT0 Tx Active Interrupt */
    CSENT0_TX_DONE_IRQn         = 200u, /* CSENT0 Tx Done Interrupt */
    CSENT1_RX_ERR_IRQn          = 201u,
    CSENT1_RX_VALID_IRQn        = 202u,
    CSENT1_TX_ACTIVE_IRQn       = 203u,
    CSENT1_TX_DONE_IRQn         = 204u,

    PIT_0_TFLG0_IRQn            = 226u, /* Periodic Interrupt Timer (PIT0) PIT_0_TFLG0[TIF] */
    PIT_0_TFLG1_IRQn            = 227u, /* Periodic Interrupt Timer (PIT1) PIT_0_TFLG1[TIF] */
    PIT_0_TFLG2_IRQn            = 228u, /* Periodic Interrupt Timer (PIT2) PIT_0_TFLG2[TIF] */
    PIT_0_TFLG3_IRQn            = 229u, /* Periodic Interrupt Timer (PIT3) PIT_0_TFLG3[TIF] */
    PIT_0_TFLG4_IRQn            = 230u, /* Periodic Interrupt Timer (PIT4) PIT_0_TFLG4[TIF] */
    PIT_0_TFLG5_IRQn            = 231u, /* Periodic Interrupt Timer (PIT5) PIT_0_TFLG5[TIF] */
    PIT_0_TFLG6_IRQn            = 232u, /* Periodic Interrupt Timer (PIT6) PIT_0_TFLG6[TIF] */
    PIT_0_TFLG7_IRQn            = 233u, /* Periodic Interrupt Timer (PIT7) PIT_0_TFLG7[TIF] */

    PIT_0_RTI_TFLG_IRQn         = 239u, /* PIT_RTI PIT_0_RTI_TFLG[TIF] */
    PIT_1_TFLG0_IRQn            = 240u, /* PIT_64_Upper PIT_1_TFLG0[TIF] */
    PIT_1_TFLG1_IRQn            = 241u, /* PIT_64_Lower PIT_1_TFLG1[TIF] */
    XOSC_COUNTER_IRQn           = 242u, /* XOSC counter XOSC */
    SIU_EXT_0_7_IRQn            = 243u, /* SIU External Interrupt_0 SIU External Interrupt_0 */
    SIU_EXT_8_15_IRQn           = 244u, /* SIU External Interrupt_1 SIU External Interrupt_1 */

    MC_ME_0_IRQn                = 251u, /* MC_ME 0 ME_IS[I_SAFE] */
    MC_ME_1_IRQn                = 252u, /* MC_ME 1 ME_IS[I_MTC] */
    MC_ME_2_IRQn                = 253u, /* MC_ME 2 ME_IS[I_IMODE] */
    MC_ME_3_IRQn                = 254u, /* MC_ME 3 ME_IS[I_ICONF] */
    MC_RGM_0_IRQn               = 255u, /* MC_RGM 0 MC_RGM Functional and destructive reset alternate event interrupt */

    DSPI0_ERR_IRQn              = 259u, /* DSPI0_0 DSPI_0_SR[TFUF] | DSPI_0_SR[RFOF] | DSPI_0_SR[TFIWF] */
    DSPI0_EOQF_IRQn             = 260u, /* DSPI0_1 DSPI_0_SR[EOQF] */
    DSPI0_TFFF_IRQn             = 261u, /* DSPI0_2 DSPI_0_SR[TFFF] */
    DSPI0_TCF_IRQn              = 262u, /* DSPI0_3 DSPI_0_SR[TCF] */
    DSPI0_RFDF_IRQn             = 263u, /* DSPI0_4 DSPI_0_SR[RFDF] */
    DSPI0_CMD_TCF_IRQn          = 264u,
    DSPI0_CMDFFF_IRQn           = 265u,
    DSPI0_SPEF_IRQn             = 266u, /* DSPI0_7 DSPI_0_SR[SPEF] */

    DSPI1_ERR_IRQn              = 268u, /* DSPI1_0 DSPI_1_SR[TFUF] | DSPI_1_SR[RFOF] | */
    DSPI1_EOQF_IRQn             = 269u, /* DSPI1_1 DSPI_1_SR[EOQF] */
    DSPI1_TFFF_IRQn             = 270u, /* DSPI1_2 DSPI_1_SR[TFFF] */
    DSPI1_TCF_IRQn              = 271u, /* DSPI1_3 DSPI_1_SR[TCF] */
    DSPI1_RFDF_IRQn             = 272u, /* DSPI1_4 DSPI_1_SR[RFDF] */
    DSPI1_CMD_TCF_IRQn          = 273u,
    DSPI1_CMDFFF_IRQn           = 274u,
    DSPI1_SPEF_IRQn             = 275u, /* DSPI1_7 DSPI_1_SR[SPEF] */

    DSPI2_ERR_IRQn              = 277u, /* DSPI2_0 DSPI_2_SR[TFUF] | DSPI_2_SR[RFOF]| */
    DSPI2_EOQF_IRQn             = 278u, /* DSPI2_1 DSPI_2_SR[EOQF] */
    DSPI2_TFFF_IRQn             = 279u, /* DSPI2_2 DSPI_2_SR[TFFF] */
    DSPI2_TCF_IRQn              = 280u, /* DSPI2_3 DSPI_2_SR[TCF] */
    DSPI2_RFDF_IRQn             = 281u, /* DSPI2_4 DSPI_2_SR[RFDF] */
    DSPI2_CMD_TCF_IRQn          = 282u,
    DSPI2_CMDFFF_IRQn           = 283u,
    DSPI2_SPEF_IRQn             = 284u, /* DSPI2_7 DSPI_2_SR[SPEF] */

    DSPI3_ERR_IRQn              = 286u, /* DSPI3_0 DSPI_3_SR[TFUF] | DSPI_3_SR[RFOF]| */
    DSPI3_EOQF_IRQn             = 287u, /* DSPI3_1 DSPI_3_SR[EOQF] */
    DSPI3_TFFF_IRQn             = 288u, /* DSPI3_2 DSPI_3_SR[TFFF] */
    DSPI3_TCF_IRQn              = 289u, /* DSPI3_3 DSPI_3_SR[TCF] */
    DSPI3_RFDF_IRQn             = 290u, /* DSPI3_4 DSPI_3_SR[RFDF] */
    DSPI3_CMD_TCF_IRQn          = 291u,
    DSPI3_CMDFFF_IRQn           = 292u,
    DSPI3_SPEF_IRQn             = 293u, /* DSPI3_7 DSPI_3_SR[SPEF] */

    DSPI4_ERR_IRQn              = 295u, /* DSPI4_0 DSPI_4_SR[TFUF] | DSPI_4_SR[RFOF]| */
    DSPI4_EOQF_IRQn             = 296u, /* DSPI4_1 DSPI_4_SR[EOQF] */
    DSPI4_TFFF_IRQn             = 297u, /* DSPI4_2 DSPI_4_SR[TFFF] */
    DSPI4_TCF_IRQn              = 298u, /* DSPI4_3 DSPI_4_SR[TCF] */
    DSPI4_RFDF_IRQn             = 299u, /* DSPI4_4 DSPI_4_SR[RFDF] */
    DSPI4_SPITCF_CMD_TCF_IRQn   = 300u, /* DSPI4_5 DSPI_4_SR[SPITCF] | */
    DSPI4_DSITCF_CMDFFF_IRQn    = 301u, /* DSPI4_6 DSPI_4_SR[DSITCF] | */
    DSPI4_SPEF_DPEF_IRQn        = 302u, /* DSPI4_7 DSPI_4_SR[SPEF] | DSPI_4_SR[DPEF] */
    DSPI4_DDIF_IRQn             = 303u, /* DSPI4_8 DSPI_4_SR[DDIF] */
    DSPI5_ERR_IRQn              = 304u, /* DSPI5_0 DSPI_5_SR[TFUF] | DSPI_5_SR[RFOF]| */
    DSPI5_EOQF_IRQn             = 305u, /* DSPI5_1 DSPI_5_SR[EOQF] */
    DSPI5_TFFF_IRQn             = 306u, /* DSPI5_2 DSPI_5_SR[TFFF] */
    DSPI5_TCF_IRQn              = 307u, /* DSPI5_3 DSPI_5_SR[TCF] */
    DSPI5_RFDF_IRQn             = 308u, /* DSPI5_4 DSPI_5_SR[RFDF] */
    DSPI5_SPITCF_CMD_TCF_IRQn   = 309u, /* DSPI5_5 DSPI_5_SR[SPITCF] | DSPI_5_SR[CMD_TCF] */
    DSPI5_DSITCF_CMDFFF_IRQn    = 310u, /* DSPI5_6 DSPI_5_SR[DSITCF] | DSPI_5_SR[CMDFFF] */
    DSPI5_SPEF_DPEF_IRQn        = 311u, /* DSPI5_7 DSPI_5_SR[SPEF] | DSPI_5_SR[DPEF] */
    DSPI5_DDIF_IRQn             = 312u, /* DSPI5_8 DSPI_5_SR[DDIF] */
    DSPI6_ERR_IRQn              = 313u, /* DSPI6_0 DSPI_6_SR[TFUF] | DSPI_6_SR[RFOF]| */
    DSPI6_EOQF_IRQn             = 314u, /* DSPI6_1 DSPI_6_SR[EOQF] */
    DSPI6_TFFF_IRQn             = 315u, /* DSPI6_2 DSPI_6_SR[TFFF] */
    DSPI6_TCF_IRQn              = 316u, /* DSPI6_3 DSPI_6_SR[TCF] */
    DSPI6_RFDF_IRQn             = 317u, /* DSPI6_4 DSPI_6_SR[RFDF] */
    DSPI6_SPITCF_CMD_TCF_IRQn   = 318u, /* DSPI6_5 DSPI_6_SR[SPITCF] | DSPI_6_SR[CMD_TCF] */
    DSPI6_DSITCF_CMDFFF_IRQn    = 319u, /* DSPI6_6 DSPI_6_SR[DSITCF] | DSPI_6_SR[CMDFFF] */
    DSPI6_SPEF_DPEF_IRQn        = 320u, /* DSPI6_7 DSPI_6_SR[SPEF] | DSPI_6_SR[DPEF] */
    DSPI6_DDIF_IRQn             = 321u, /* DSPI6_8 DSPI_6_SR[DDIF] */

    DSPI12_ERR_IRQn             = 367u, /* DSPI12_0 DSPI_12_SR[TFUF] | DSPI_12_SR[RFOF]| */
    DSPI12_EOQF_IRQn            = 368u, /* DSPI12_1 DSPI_12_SR[EOQF] */
    DSPI12_TFFF_IRQn            = 369u, /* DSPI12_2 DSPI_12_SR[TFFF] */
    DSPI12_TCF_IRQn             = 370u, /* DSPI12_3 DSPI_12_SR[TCF] */
    DSPI12_RFDF_IRQn            = 371u, /* DSPI12_4 DSPI_12_SR[RFDF] */
    DSPI12_CMD_TCF_IRQn         = 372u,
    DSPI12_CMDFFF_IRQn          = 373u,
    DSPI12_SPEF_IRQn            = 374u, /* DSPI12_7 DSPI_12_SR[SPEF] */
    API_IRQn                    = 375U,
    LINFLEXD0_RX_IRQn           = 376u, /* Linflex/eSCI0_0 LINFlex_0_RXI */
    LINFLEXD0_TX_IRQn           = 377u, /* Linflex/eSCI0_1 LINFlex_0_TXI */
    LINFLEXD0_ERR_IRQn          = 378u, /* Linflex/eSCI0_2 LINFlex_0_ERR */

    LINFLEXD1_RX_IRQn           = 380u, /* Linflex/eSCI1_0 LINFlex_1_RXI */
    LINFLEXD1_TX_IRQn           = 381u, /* Linflex/eSCI1_1 LINFlex_1_TXI */
    LINFLEXD1_ERR_IRQn          = 382u, /* Linflex/eSCI1_2 LINFlex_1_ERR */

    LINFLEXD2_RX_IRQn           = 384u, /* Linflex/eSCI2_0 LINFlex_2_RXI */
    LINFLEXD2_TX_IRQn           = 385u, /* Linflex/eSCI2_1 LINFlex_2_TXI */
    LINFLEXD2_ERR_IRQn          = 386u, /* Linflex/eSCI2_2 LINFlex_2_ERR */
    CCU7_1_SR_IRQn              = 387u,
    CCU7_0_SR_IRQn              = 388u,

	MCAN3_DMU_INT_IRQn          = 390u, /* MCAN3 DMU INT */
	MCAN2_DMU_INT_IRQn          = 391u, /* MCAN2 DMU INT */
	MCAN1_DMU_INT_IRQn          = 392u, /* MCAN1 DMU INT */
	MCAN7_DMU_INT_IRQn          = 393u, /* MCAN7 DMU INT */
	MCAN6_DMU_INT_IRQn          = 394u, /* MCAN6 DMU INT */
	MCAN5_DMU_INT_IRQn          = 395u, /* MCAN5 DMU INT */

    LINFLEXD16_RX_IRQn          = 416u, /* Linflex/eSCI16_0 LINFlex_16_RXI */
    LINFLEXD16_TX_IRQn          = 417u, /* Linflex/eSCI16_1 LINFlex_16_TXI */
    LINFLEXD16_ERR_IRQn         = 418u, /* Linflex/eSCI16_2 LINFlex_16_ERR */

    WKPU_WISR0_0_7_IRQn         = 427u, /* WISR0: EIF0~7   */
    WKPU_WISR0_8_15_IRQn        = 428u, /* WISR0: EIF8~15  */

    WKPU_WISR0_24_31_IRQn       = 430u, /* WISR0: EIF24~31 */

    LINFLEXD14_RX_IRQn          = 432u, /* Linflex/eSCI14_0 LINFlex_14_RXI */
    LINFLEXD14_TX_IRQn          = 433u, /* Linflex/eSCI14_1 LINFlex_14_TXI */
    LINFLEXD14_ERR_IRQn         = 434u, /* Linflex/eSCI14_2 LINFlex_14_ERR */
    LINFLEXD6_RX_IRQn           = 435u,
    LINFLEXD15_RX_IRQn          = 436u, /* Linflex/eSCI15_0 LINFlex_15_RXI */
    LINFLEXD15_TX_IRQn          = 437u, /* Linflex/eSCI15_1 LINFlex_15_TXI */
    LINFLEXD15_ERR_IRQn         = 438u, /* Linflex/eSCI15_2 LINFlex_15_ERR */
    LINFLEXD6_TX_IRQn           = 439u,
    IIC0_SR_IRQn                = 440u, /* IIC_0_0 I2C0_SR[IBAL] | I2C0_SR[TCF] | I2C0_SR[IAAS] */

    IIC1_SR_IRQn                = 442u, /* IIC_1_0 I2C1_SR[IBAL] | I2C1_SR[TCF] | I2C1_SR[IAAS] */

    PMC_GR_S_IRQn               = 477u, /* Power Monitor Unit GR_S[VD15] | GR_S[VD14] | GR_S[VD13] | */
    PMC_ERP_TEMP_IRQn           = 478u, /* Power management Unit (temp sensor) EPR_TD[TEMP_3] | EPR_TD[TEMP_2] | */
    LINFLEXD3_RX_IRQn           = 479u,
    LINFLEXD3_TX_IRQn           = 480u,
    LINFLEXD3_ERR_IRQn          = 481u,

    LINFLEXD5_RX_IRQn           = 485u,
    LINFLEXD5_TX_IRQn           = 486u,
    LINFLEXD5_ERR_IRQn          = 487u,
    FCCU_0_IRQn                 = 488u, /* FCCU_0 FCCU_IRQ_STAT[ALRM_STAT] */
    FCCU_1_IRQn                 = 489u, /* FCCU_1 FCU_IRQ_STAT[CFG_TO_STAT] */

    LINFLEXD6_ERR_IRQn          = 492u,
    LINFLEXD12_RX_IRQn          = 493u,
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

	MCAN4_DMU_INT_IRQn          = 538u, /* MCAN4 DMU INT */

    LINFLEXD12_TX_IRQn          = 542u,
	MCAN8_DMU_INT_IRQn          = 543u, /* MCAN8 DMU INT */

    LINFLEXD12_ERR_IRQn         = 557u,
    SENT0_COMBINED_FAST_IRQn    = 558u, /* SENT_COMBINED_FAST_0 SENT_0_FMSG_RDY[0] | */
    SENT0_COMBINED_SLOW_IRQn    = 559u, /* SENT_COMBINED_SLOW_0 SENT_0_SMSG_RDY[0] | */
    SENT0_COMBINED_ERR_IRQn     = 560u, /* SENT_COMBINED_ERR_0 SENT_0_GBL_STATUS[FMDU] | */
    SENT1_COMBINED_FAST_IRQn    = 561u, /* SENT_COMBINED_FAST_1 SENT_1_FMSG_RDY[0] | */
    SENT1_COMBINED_SLOW_IRQn    = 562u, /* SENT_COMBINED_SLOW_1 SENT_1_SMSG_RDY[0] | */
    SENT1_COMBINED_ERR_IRQn     = 563u, /* SENT_COMBINED_ERR_1 SENT_1_GBL_STATUS[FMDU] | */
    SENT0_CH0_FAST_IRQn         = 564u,  /* SENT_0_CH0_FAST, SENT_0_FMSG_RDY[0] */
    SENT0_CH0_SLOW_IRQn         = 565u,  /* SENT_0_CH0_SLOW, SENT_0_SMSG_RDY[0] */
    SENT0_CH0_ERR_IRQn          = 566u,   /* SENT_0_CH0_ERR,  SENT_0_CH0_STATUS[4:7] | */
    SENT0_CH1_FAST_IRQn         = 567u,  /* SENT_0_CH1_FAST, SENT_0_FMSG_RDY[1] */
    SENT0_CH1_SLOW_IRQn         = 568u,  /* SENT_0_CH1_SLOW, SENT_0_SMSG_RDY[1] */
    SENT0_CH1_ERR_IRQn          = 569u,   /* SENT_0_CH1_ERR,  SENT_0_CH1_STATUS[4:7] | */
    SENT0_CH2_FAST_IRQn         = 570u,  /* SENT_0_CH2_FAST, SENT_0_FMSG_RDY[2] */
    SENT0_CH2_SLOW_IRQn         = 571u,  /* SENT_0_CH2_SLOW, SENT_0_SMSG_RDY[2] */
    SENT0_CH2_ERR_IRQn          = 572u,   /* SENT_0_CH2_ERR,  SENT_0_CH2_STATUS[4:7] | */
    SENT0_CH3_FAST_IRQn         = 573u,  /* SENT_0_CH3_FAST, SENT_0_FMSG_RDY[3] */
    SENT0_CH3_SLOW_IRQn         = 574u,  /* SENT_0_CH3_SLOW, SENT_0_SMSG_RDY[3] */
    SENT0_CH3_ERR_IRQn          = 575u,   /* SENT_0_CH3_ERR,  SENT_0_CH3_STATUS[4:7] | */
    SENT0_CH4_FAST_IRQn         = 576u,  /* SENT_0_CH4_FAST, SENT_0_FMSG_RDY[4] */
    SENT0_CH4_SLOW_IRQn         = 577u,  /* SENT_0_CH4_SLOW, SENT_0_SMSG_RDY[4] */
    SENT0_CH4_ERR_IRQn          = 578u,   /* SENT_0_CH4_ERR,  SENT_0_CH4_STATUS[4:7] | */
    SENT1_CH0_FAST_IRQn         = 579u,  /* SENT_1_CH0_FAST, SENT_1_FMSG_RDY[0] */
    SENT1_CH0_SLOW_IRQn         = 580u,  /* SENT_1_CH0_SLOW, SENT_1_SMSG_RDY[0] */
    SENT1_CH0_ERR_IRQn          = 581u,   /* SENT_1_CH0_ERR,  SENT_1_CH0_STATUS[4:7] | */
    SENT1_CH1_FAST_IRQn         = 582u,  /* SENT_1_CH1_FAST, SENT_1_FMSG_RDY[1] */
    SENT1_CH1_SLOW_IRQn         = 583u,  /* SENT_1_CH1_SLOW, SENT_1_SMSG_RDY[1] */
    SENT1_CH1_ERR_IRQn          = 584u,   /* SENT_1_CH1_ERR,  SENT_1_CH1_STATUS[4:7] | */
    SENT1_CH2_FAST_IRQn         = 585u,  /* SENT_1_CH2_FAST, SENT_1_FMSG_RDY[2] */
    SENT1_CH2_SLOW_IRQn         = 586u,  /* SENT_1_CH2_SLOW, SENT_1_SMSG_RDY[2] */
    SENT1_CH2_ERR_IRQn          = 587u,   /* SENT_1_CH2_ERR,  SENT_1_CH3_STATUS[4:7] | */
    SENT1_CH3_FAST_IRQn         = 588u,  /* SENT_1_CH3_FAST, SENT_1_FMSG_RDY[3] */
    SENT1_CH3_SLOW_IRQn         = 589u,  /* SENT_1_CH3_SLOW, SENT_1_SMSG_RDY[3] */
    SENT1_CH3_ERR_IRQn          = 590u,   /* SENT_1_CH3_ERR,  SENT_1_CH3_STATUS[4:7] | */
    SENT1_CH4_FAST_IRQn         = 591u,  /* SENT_1_CH4_FAST, SENT_1_FMSG_RDY[4] */
    SENT1_CH4_SLOW_IRQn         = 592u,  /* SENT_1_CH4_SLOW, SENT_1_SMSG_RDY[4] */
    SENT1_CH4_ERR_IRQn          = 593u,   /* SENT_1_CH4_ERR,  SENT_1_CH4_STATUS[4:7] | */
    SENT0_CH5_FAST_IRQn         = 594u,  /* SENT_0_CH5_FAST, SENT_0_FMSG_RDY[5] */
    SENT0_CH5_SLOW_IRQn         = 595u,  /* SENT_0_CH5_SLOW, SENT_0_SMSG_RDY[5] */
    SENT0_CH5_ERR_IRQn          = 596u,   /* SENT_0_CH5_ERR,  SENT_0_CH5_STATUS[4:7] | */
    SENT0_CH6_FAST_IRQn         = 597u,  /* SENT_0_CH6_FAST, SENT_0_FMSG_RDY[6] */
    SENT0_CH6_SLOW_IRQn         = 598u,  /* SENT_0_CH6_SLOW, SENT_0_SMSG_RDY[6] */
    SENT0_CH6_ERR_IRQn          = 599u,   /* SENT_0_CH6_ERR,  SENT_0_CH6_STATUS[4:7] | */
    SENT0_CH7_FAST_IRQn         = 600u,  /* SENT_0_CH7_FAST, SENT_0_FMSG_RDY[7] */
    SENT0_CH7_SLOW_IRQn         = 601u,  /* SENT_0_CH7_SLOW, SENT_0_SMSG_RDY[7] */
    SENT0_CH7_ERR_IRQn          = 602u,   /* SENT_0_CH7_ERR,  SENT_0_CH7_STATUS[4:7] | */
    SENT1_CH5_FAST_IRQn         = 603u,  /* SENT_1_CH5_FAST, SENT_1_FMSG_RDY[5] */
    SENT1_CH5_SLOW_IRQn         = 604u,  /* SENT_1_CH5_SLOW, SENT_1_SMSG_RDY[5] */
    SENT1_CH5_ERR_IRQn          = 605u,   /* SENT_1_CH5_ERR,  SENT_1_CH5_STATUS[4:7] | */
    SENT1_CH6_FAST_IRQn         = 606u,  /* SENT_1_CH6_FAST, SENT_1_FMSG_RDY[6] */
    SENT1_CH6_SLOW_IRQn         = 607u,  /* SENT_1_CH6_SLOW, SENT_1_SMSG_RDY[6] */
    SENT1_CH6_ERR_IRQn          = 608u,   /* SENT_1_CH6_ERR,  SENT_1_CH6_STATUS[4:7] | */
    LINFLEXD9_RX_IRQn           = 609u,
    LINFLEXD9_TX_IRQn           = 610u,
    LINFLEXD9_ERR_IRQn          = 611u,
    PSI5_0_CH0_0_IRQn           = 612u, /* PSI5_0_CH0_0 PSI5_0_CH_0_DSR[IS_DMA_TF_PM_DS] | PSI5_0_CH_0_DSR[IS_DMA_TF_SF] | */
    PSI5_0_CH0_1_IRQn           = 613u, /* PSI5_0_CH0_1 PSI5_0_CH_0_GISR[IS_CESM[6:1]] | */
    PSI5_0_CH0_2_IRQn           = 614u, /* PSI5_0_CH0_2 PSI5_0_CH_0_NDSR[NDS31] | */
    PSI5_0_CH0_3_IRQn           = 615u, /* PSI5_0_CH0_3 PSI5_0_CH_0_OWSR[NDS31] | */
    PSI5_0_CH0_4_IRQn           = 616u, /* PSI5_0_CH0_4 PSI5_0_CH_0_EISR[NDS31] | */
    PSI5_0_CH0_5_IRQn           = 617u, /* PSI5_0_CH0_5 PSI5_0_CH_0_DSR[*] | */
    PSI5_0_CH1_0_IRQn           = 618u, /* PSI5_0_CH1_0 PSI5_0_CH_1_DSR[IS_DMA_TF_PM_DS] | PSI5_0_CH_1_DSR[IS_DMA_TF_SF] | */
    PSI5_0_CH1_1_IRQn           = 619u, /* PSI5_0_CH1_1 PSI5_0_CH_1_GISR[IS_CESM[6:1]] | */
    PSI5_0_CH1_2_IRQn           = 620u, /* PSI5_0_CH1_2 PSI5_0_CH_1_NDSR[NDS31] | */
    PSI5_0_CH1_3_IRQn           = 621u, /* PSI5_0_CH1_3 PSI5_0_CH_1_OWSR[NDS31] | */
    PSI5_0_CH1_4_IRQn           = 622u, /* PSI5_0_CH1_4 PSI5_0_CH_1_EISR[NDS31] | */
    PSI5_0_CH1_5_IRQn           = 623u, /* PSI5_0_CH1_5 PSI5_0_CH_1_DSR[*] | */
    PSI5_1_CH0_0_IRQn           = 624u, /* PSI5_1_CH0_0 PSI5_1_CH_0_DSR[IS_DMA_TF_PM_DS] | PSI5_1_CH_0_DSR[IS_DMA_TF_SF] | */
    PSI5_1_CH0_1_IRQn           = 625u, /* PSI5_1_CH0_1 PSI5_1_CH_0_GISR[IS_CESM[6:1]] | */
    PSI5_1_CH0_2_IRQn           = 626u, /* PSI5_1_CH0_2 PSI5_1_CH_0_NDSR[NDS31] | */
    PSI5_1_CH0_3_IRQn           = 627u, /* PSI5_1_CH0_3 PSI5_1_CH_0_OWSR[NDS31] | */
    PSI5_1_CH0_4_IRQn           = 628u, /* PSI5_1_CH0_4 PSI5_1_CH_0_EISR[NDS31] | */
    PSI5_1_CH0_5_IRQn           = 629u, /* PSI5_1_CH0_5 PSI5_1_CH_0_DSR[*] | */
    PSI5_0_CH2_0_IRQn           = 630u, /* PSI5_0_CH2_0 PSI5_0_CH_2_DSR[IS_DMA_TF_PM_DS] | PSI5_0_CH_2_DSR[IS_DMA_TF_SF] | */
    PSI5_0_CH2_1_IRQn           = 631u, /* PSI5_0_CH2_1 PSI5_0_CH_2_GISR[IS_CESM[6:1]] | */
    PSI5_0_CH2_2_IRQn           = 632u, /* PSI5_0_CH2_2 PSI5_0_CH_2_NDSR[NDS31] | */
    PSI5_0_CH2_3_IRQn           = 633u, /* PSI5_0_CH2_3 PSI5_0_CH_2_OWSR[NDS31] | */
    PSI5_0_CH2_4_IRQn           = 634u, /* PSI5_0_CH2_4 PSI5_0_CH_2_EISR[NDS31] | */
    PSI5_0_CH2_5_IRQn           = 635u, /* PSI5_0_CH2_5 PSI5_0_CH_2_DSR[*] | */
    PSI5_1_CH1_0_IRQn           = 636u, /* PSI5_1_CH1_0 PSI5_1_CH_1_DSR[IS_DMA_TF_PM_DS] | PSI5_1_CH_1_DSR[IS_DMA_TF_SF] | */
    PSI5_1_CH1_1_IRQn           = 637u, /* PSI5_1_CH1_1 PSI5_1_CH_1_GISR[IS_CESM[6:1]] | */
    PSI5_1_CH1_2_IRQn           = 638u, /* PSI5_1_CH1_2 PSI5_1_CH_1_NDSR[NDS31] | */
    PSI5_1_CH1_3_IRQn           = 639u, /* PSI5_1_CH1_3 PSI5_1_CH_1_OWSR[NDS31] | */
    PSI5_1_CH1_4_IRQn           = 640u, /* PSI5_1_CH1_4 PSI5_1_CH_1_EISR[NDS31] | */
    PSI5_1_CH1_5_IRQn           = 641u, /* PSI5_1_CH1_5 PSI5_1_CH_1_DSR[*] | */
    LINFLEXD10_RX_IRQn          = 642u,
    LINFLEXD10_TX_IRQn          = 643u,
    LINFLEXD10_ERR_IRQn         = 644u,

    RTC_IRQn                    = 648u,
    EMIOS1_CH0_IRQn             = 649u,
    EMIOS1_CH1_IRQn             = 650u,
    EMIOS1_CH2_IRQn             = 651u,
    EMIOS1_CH3_IRQn             = 652u,
    EMIOS1_CH4_IRQn             = 653u,

    EMIOS1_CH5_IRQn             = 666u,
    EMIOS1_CH6_IRQn             = 667u,
    EMIOS1_CH7_IRQn             = 668u,
    EMIOS1_CH8_IRQn             = 669u,
    EMIOS1_CH9_IRQn             = 670u,
    EMIOS1_CH10_IRQn            = 671u,
    EMIOS1_CH11_IRQn            = 672u,
    EMIOS1_CH12_IRQn            = 673u,

    JDC_MSR_IRQn                = 675u, /* JDC JDC_MSR[JIN_INT] | */
    EMIOS1_CH13_IRQn            = 676u,
    M_TTCAN0_LINE0_IRQn         = 677u, /* M_TTCAN0_0 M_TTCAN_0 interrupt line0 */
    M_TTCAN0_LINE1_IRQn         = 678u, /* M_TTCAN0_1 M_TTCAN_0 interrupt line1 */
    M_TTCAN0_TIME_MARK_IRQn     = 679u, /* M_TTCAN0_2 M_TTCAN_0 Register Time Mark interrupt */
    EMIOS1_CH14_IRQn            = 680u,
    EMIOS1_CH15_IRQn            = 681u,
    EMIOS1_CH16_IRQn            = 682u,
    EMIOS1_CH17_IRQn            = 683u,
    EMIOS1_CH18_IRQn            = 684u,
    M_TTCAN1_LINE0_IRQn         = 685u,
    M_TTCAN1_LINE1_IRQn         = 686u,
    M_TTCAN1_TIME_MARK_IRQn     = 687u,
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
    EMIOS1_CH19_IRQn            = 704u,
    EMIOS1_CH20_IRQn            = 705u,
    GTM_AEI_IRQn                = 706u, /* GTM_AEI_IRQ AEI gtm_icm.gtm_aei_irq aei */
    GTM_ARU_0_IRQn              = 707u, /* GTM_ARU_IRQ[0] gtm_icm.gtm_aru_irq[0] */
    GTM_ARU_1_IRQn              = 708u, /* GTM_ARU_IRQ[1] gtm_icm.gtm_aru_irq[1] */
    GTM_ARU_2_IRQn              = 709u, /* GTM_ARU_IRQ[2] gtm_icm.gtm_aru_irq[2] */
    GTM_BRC_IRQn                = 710u, /* GTM_BRC_IRQ gtm_icm.gtm_brc_irq */
    GTM_CMP_IRQn                = 711u, /* GTM_CMP_IRQ gtm_icm.gtm_cmp_irq */
    GTM_SPE0_IRQn               = 712u, /* GTM_SPE0_IRQ gtm_icm.gtm_spe0_irq */
    GTM_SPE1_IRQn               = 713u, /* GTM_SPE1_IRQ gtm_icm.gtm_spe1_irq */

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

    GTM_MCS0_0_IRQn             = 781u, /* GTM_MCS0_IRQ[0] gtm_icm.gtm_mcs0_irq[0] */
    GTM_MCS0_1_IRQn             = 782u, /* GTM_MCS0_IRQ[1] gtm_icm.gtm_mcs0_irq[1] */
    GTM_MCS0_2_IRQn             = 783u, /* GTM_MCS0_IRQ[2] gtm_icm.gtm_mcs0_irq[2] */
    GTM_MCS0_3_IRQn             = 784u, /* GTM_MCS0_IRQ[3] gtm_icm.gtm_mcs0_irq[3] */
    GTM_MCS0_4_IRQn             = 785u, /* GTM_MCS0_IRQ[4] gtm_icm.gtm_mcs0_irq[4] */
    GTM_MCS0_5_IRQn             = 786u, /* GTM_MCS0_IRQ[5] gtm_icm.gtm_mcs0_irq[5] */
    GTM_MCS0_6_IRQn             = 787u, /* GTM_MCS0_IRQ[6] gtm_icm.gtm_mcs0_irq[6] */
    GTM_MCS0_7_IRQn             = 788u, /* GTM_MCS0_IRQ[7] gtm_icm.gtm_mcs0_irq[7] */

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

    GTM_ATOM0_0_IRQn            = 837u, /* GTM_ATOM0_IRQ[0] gtm_icm.gtm_atom0_irq[0] */
    GTM_ATOM0_1_IRQn            = 838u, /* GTM_ATOM0_IRQ[1] gtm_icm.gtm_atom0_irq[1] */
    GTM_ATOM0_2_IRQn            = 839u, /* GTM_ATOM0_IRQ[2] gtm_icm.gtm_atom0_irq[2] */
    GTM_ATOM0_3_IRQn            = 840u, /* GTM_ATOM0_IRQ[3] gtm_icm.gtm_atom0_irq[3] */
    GTM_ATOM1_0_IRQn            = 841u, /* GTM_ATOM1_IRQ[0] gtm_icm.gtm_atom1_irq[0] */
    GTM_ATOM1_1_IRQn            = 842u, /* GTM_ATOM1_IRQ[1] gtm_icm.gtm_atom1_irq[1] */
    GTM_ATOM1_2_IRQn            = 843u, /* GTM_ATOM1_IRQ[2] gtm_icm.gtm_atom1_irq[2] */
    GTM_ATOM1_3_IRQn            = 844u, /* GTM_ATOM1_IRQ[3] gtm_icm.gtm_atom1_irq[3] */

    GTM_ERR_IRQn                = 931u, /* GTM_ERR_IRQ gtm_err_irq */
    EMIOS1_CH21_IRQn            = 932u,
    EMIOS1_CH22_IRQn            = 933u,
    EMIOS1_CH23_IRQn            = 934u,
    EMIOS1_CH24_IRQn            = 935u,
    EMIOS1_CH25_IRQn            = 936u,
    EMIOS1_CH26_IRQn            = 937u,
    EMIOS1_CH27_IRQn            = 938u,
    EMIOS1_CH28_IRQn            = 939u,
    EMIOS1_CH29_IRQn            = 940u,
    EMIOS1_CH30_IRQn            = 941u,
    EMIOS1_CH31_IRQn            = 942u,
    EMIOS0_CH0_IRQn             = 943u,
    EMIOS0_CH1_IRQn             = 944u,
    EMIOS0_CH2_IRQn             = 945u,
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
    PSI5_S_0_UART_RX_IRQn       = 962u,
    PSI5_S_0_UART_TX_IRQn       = 963u,
    PSI5_S_0_UART_ERR_IRQn      = 964u,
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
    EQADC01_FIFO_6_IRQn         = 977u, /* EQADC01_FISR6 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC01_FIFO_7_IRQn         = 978u, /* EQADC01_FISR7 [NCF | PF | EOQF | CFFF | RFDF] */

    EQADC23_FIFO_6_IRQn         = 983u, /* EQADC23_FISR6 [NCF | PF | EOQF | CFFF | RFDF] */
    EQADC23_FIFO_7_IRQn         = 984u, /* EQADC23_FISR7 [NCF | PF | EOQF | CFFF | RFDF] */

    EMIOS0_CH3_IRQn             = 995u,
    EMIOS0_CH4_IRQn             = 996u,
    EMIOS0_CH5_IRQn             = 997u,
    EMIOS0_CH6_IRQn             = 998u,
    EMIOS0_CH7_IRQn             = 999u,
    EMIOS0_CH8_IRQn             = 1000u,
    EMIOS0_CH9_IRQn             = 1001u,
    EMIOS0_CH10_IRQn            = 1002u,
    EMIOS0_CH11_IRQn            = 1003u,
    EMIOS0_CH12_IRQn            = 1004u,
    EMIOS0_CH13_IRQn            = 1005u,
    EMIOS0_CH14_IRQn            = 1006u,
    EMIOS0_CH15_IRQn            = 1007u,
    EMIOS0_CH16_IRQn            = 1008u,
    EMIOS0_CH17_IRQn            = 1009u,
    EMIOS0_CH18_IRQn            = 1010u,
    EMIOS0_CH19_IRQn            = 1011u,
    EMIOS0_CH20_IRQn            = 1012u,
    EMIOS0_CH21_IRQn            = 1013u,
    EMIOS0_CH22_IRQn            = 1014u,
    EMIOS0_CH23_IRQn            = 1015u,
    EMIOS0_CH24_IRQn            = 1016u,
    EMIOS0_CH25_IRQn            = 1017u,
    EMIOS0_CH26_IRQn            = 1018u,
    EMIOS0_CH27_IRQn            = 1019u,
    EMIOS0_CH28_IRQn            = 1020u,
    EMIOS0_CH29_IRQn            = 1021u,
    EMIOS0_CH30_IRQn            = 1022u,
    EMIOS0_CH31_IRQn            = 1023u,
    INTR_ID_BUTT                = 1024u
} IntrId;

/* DSPI module features */
/* On this platform DSPI in extended mode is supported */
#define FEATURE_DSPI_HAS_EXTENDED_MODE 0U

/* Define interrupt vector for dspi */
#define FEATURES_DSPI_EOQ_INTERUPT_VECTOR    { DSPI0_EOQF_IRQn, DSPI1_EOQF_IRQn, DSPI2_EOQF_IRQn, DSPI3_EOQF_IRQn,\
                                               DSPI4_EOQF_IRQn, DSPI5_EOQF_IRQn, DSPI6_EOQF_IRQn, DSPI12_EOQF_IRQn}

#define FEATURES_DSPI_SEND_INTERUPT_VECTOR    { DSPI0_TFFF_IRQn, DSPI1_TFFF_IRQn, DSPI2_TFFF_IRQn, DSPI3_TFFF_IRQn,\
                                                DSPI4_TFFF_IRQn, DSPI5_TFFF_IRQn, DSPI6_TFFF_IRQn, DSPI12_TFFF_IRQn}

#define FEATURES_DSPI_RECEIVE_INTERUPT_VECTOR { DSPI0_RFDF_IRQn, DSPI1_RFDF_IRQn, DSPI2_RFDF_IRQn, DSPI3_RFDF_IRQn, \
                                                DSPI4_RFDF_IRQn, DSPI5_RFDF_IRQn, DSPI6_RFDF_IRQn, DSPI12_RFDF_IRQn}

#define FEATURES_DSPI_FAULT_INTERUPT_VECTOR   { DSPI0_ERR_IRQn, DSPI1_ERR_IRQn, DSPI2_ERR_IRQn,DSPI3_ERR_IRQn, \
                                                DSPI4_ERR_IRQn, DSPI5_ERR_IRQn, DSPI6_ERR_IRQn, DSPI12_ERR_IRQn}

typedef enum
{
    /* DMAMUX_0: DMAMUX Channel 0 - 7 (eDMA_0 Channel 0 - 7) */
    DMAMUX0_RESERVED_0_A            = 0U,   /* DMAMUX_0: Source 0  */
    DMAMUX0_ADC01_DECFILT_IN        = 1U,   /* DMAMUX_0: Source 1  */
    DMAMUX0_ADC01_DECFILT_OUT       = 2U,   /* DMAMUX_0: Source 2  */
                                            /* DMAMUX_0: Source 3  */
                                            /* DMAMUX_0: Source 4  */
    DMAMUX0_DSPI_0_RX               = 5U,   /* DMAMUX_0: Source 5  */
    DMAMUX0_DSPI_0_TX               = 6U,   /* DMAMUX_0: Source 6  */
    DMAMUX0_DSPI_4_RX               = 7U,   /* DMAMUX_0: Source 7  */
    DMAMUX0_DSPI_4_TX               = 8U,   /* DMAMUX_0: Source 8  */
                                            /* DMAMUX_0: Source 9  */
                                            /* DMAMUX_0: Source 10 */
                                            /* DMAMUX_0: Source 11 */
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
	DMAMUX0_MCAN_5_TXR              = 27U,  /* DMAMUX_0: Source 27 */
	DMAMUX0_MCAN_5_TXER             = 28U,  /* DMAMUX_0: Source 28 */
	DMAMUX0_MCAN_5_RX1R             = 29U,  /* DMAMUX_0: Source 29 */
	DMAMUX0_MCAN_5_RX0R             = 30U,  /* DMAMUX_0: Source 30 */
	DMAMUX0_MCAN_6_TXR              = 31U,  /* DMAMUX_0: Source 31 */
	DMAMUX0_MCAN_6_TXER             = 32U,  /* DMAMUX_0: Source 32 */
	DMAMUX0_MCAN_6_RX1R             = 33U,  /* DMAMUX_0: Source 33 */
	DMAMUX0_MCAN_6_RX0R             = 34U,  /* DMAMUX_0: Source 34 */
	DMAMUX0_MCAN_7_TXR              = 35U,  /* DMAMUX_0: Source 35 */
    DMAMUX0_MCAN_7_TXER             = 36U,  /* DMAMUX_0: Source 36 */
    DMAMUX0_MCAN_7_RX1R             = 37U,  /* DMAMUX_0: Source 37 */
    DMAMUX0_MCAN_7_RX0R             = 38U,  /* DMAMUX_0: Source 38 */
    DMAMUX0_MCAN_1_TXR              = 39U,  /* DMAMUX_0: Source 39 */
    DMAMUX0_MCAN_1_TXER             = 40U,  /* DMAMUX_0: Source 40 */
    DMAMUX0_MCAN_1_RX1R             = 41U,  /* DMAMUX_0: Source 41 */
    DMAMUX0_MCAN_1_RX0R             = 42U,  /* DMAMUX_0: Source 42 */
    DMAMUX0_MCAN_2_TXR              = 43U,  /* DMAMUX_0: Source 43 */
    DMAMUX0_MCAN_2_TXER             = 44U,  /* DMAMUX_0: Source 44 */
    DMAMUX0_MCAN_2_RX1R             = 45U,  /* DMAMUX_0: Source 45 */
    DMAMUX0_MCAN_2_RX0R             = 46U,  /* DMAMUX_0: Source 46 */
    DMAMUX0_MCAN_3_TXR              = 47U,  /* DMAMUX_0: Source 47 */
    DMAMUX0_MCAN_3_TXER             = 48U,  /* DMAMUX_0: Source 48 */
    DMAMUX0_MCAN_3_RX1R             = 49U,  /* DMAMUX_0: Source 49 */
    DMAMUX0_MCAN_3_RX0R             = 50U,  /* DMAMUX_0: Source 50 */
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
    DMAMUX1_LINFLEXD_14_RX          = 71U,  /* DMAMUX_1: Source 7  */
    DMAMUX1_LINFLEXD_14_TX          = 72U,  /* DMAMUX_1: Source 8  */
    DMAMUX1_SENT_0_RX_FAST          = 73U,  /* DMAMUX_1: Source 9  */
    DMAMUX1_SENT_0_RX_SLOW          = 74U,  /* DMAMUX_1: Source 10 */
                                            /* DMAMUX_1: Source 11 */
                                            /* DMAMUX_1: Source 12 */
                                            /* DMAMUX_1: Source 13 */
                                            /* DMAMUX_1: Source 14 */
    DMAMUX1_SIUL2_REQ0              = 79U,  /* DMAMUX_1: Source 15 */
    DMAMUX1_SIUL2_REQ1              = 80U,  /* DMAMUX_1: Source 16 */
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
    DMAMUX1_LINFLEXD_15_RX          = 109U, /* DMAMUX_1: Source 45 */
    DMAMUX1_LINFLEXD_15_TX          = 110U, /* DMAMUX_1: Source 46 */
    DMAMUX1_DSPI_5_RX               = 111U, /* DMAMUX_1: Source 47 */
    DMAMUX1_DSPI_5_TX               = 112U, /* DMAMUX_1: Source 48 */
    DMAMUX1_DSPI_5_CMD              = 113U, /* DMAMUX_1: Source 49 */
    DMAMUX1_DSPI_12_CMD             = 114U, /* DMAMUX_1: Source 50 */
                                            /* DMAMUX_1: Source 51 */
                                            /* DMAMUX_1: Source 52 */
    DMAMUX1_DSPI_0_RX               = 117U, /* DMAMUX_1: Source 53 */
    DMAMUX1_DSPI_0_TX               = 118U, /* DMAMUX_1: Source 54 */
    DMAMUX1_ADC01_DECFILT_IN        = 119U, /* DMAMUX_1: Source 55 */
                                            /* DMAMUX_1: Source 56 */
                                            /* DMAMUX_1: Source 57 */
                                            /* DMAMUX_1: Source 58 */
    DMAMUX1_ALWAYS_ON_0             = 123U, /* DMAMUX_1: Source 59 */
    DMAMUX1_ALWAYS_ON_1             = 124U, /* DMAMUX_1: Source 60 */
    DMAMUX1_ALWAYS_ON_2             = 125U, /* DMAMUX_1: Source 61 */
    DMAMUX1_ALWAYS_ON_3             = 126U, /* DMAMUX_1: Source 62 */
    DMAMUX1_ALWAYS_ON_4             = 127U, /* DMAMUX_1: Source 63 */

    /* DMAMUX_2: DMAMUX Channel 16 - 23 (eDMA_0 Channel 16 - 23) */
    DMAMUX2_RESERVED_0_A            = 128U, /* DMAMUX_2: Source 0  */
    DMAMUX2_ADC23_DECFILT_IN        = 129U, /* DMAMUX_2: Source 1  */
                                            /* DMAMUX_2: Source 2  */
    DMAMUX2_DSPI_1_RX               = 131U, /* DMAMUX_2: Source 3  */
    DMAMUX2_DSPI_1_TX               = 132U, /* DMAMUX_2: Source 4  */
    DMAMUX2_SENT_1_RX_FAST          = 133U, /* DMAMUX_2: Source 5  */
    DMAMUX2_SENT_1_RX_SLOW          = 134U, /* DMAMUX_2: Source 6  */
    DMAMUX2_PSI5_0_CH0_RX_PSI5      = 135U, /* DMAMUX_2: Source 7  */
    DMAMUX2_PSI5_0_CH0_RX_SENT      = 136U, /* DMAMUX_2: Source 8  */
    DMAMUX2_SIUL2_REQ2              = 137U, /* DMAMUX_2: Source 9  */
    DMAMUX2_SIUL2_REQ4              = 138U, /* DMAMUX_2: Source 10 */
                                            /* DMAMUX_2: Source 11 */
                                            /* DMAMUX_2: Source 12 */
                                            /* DMAMUX_2: Source 13 */
                                            /* DMAMUX_2: Source 14 */
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
                                            /* DMAMUX_2: Source 25 */
                                            /* DMAMUX_2: Source 26 */
                                            /* DMAMUX_2: Source 27 */
                                            /* DMAMUX_2: Source 28 */
                                            /* DMAMUX_2: Source 29 */
                                            /* DMAMUX_2: Source 30 */
                                            /* DMAMUX_2: Source 31 */
                                            /* DMAMUX_2: Source 32 */
                                            /* DMAMUX_2: Source 33 */
                                            /* DMAMUX_2: Source 34 */
                                            /* DMAMUX_2: Source 35 */
                                            /* DMAMUX_2: Source 36 */
                                            /* DMAMUX_2: Source 37 */
                                            /* DMAMUX_2: Source 38 */
                                            /* DMAMUX_2: Source 39 */
                                            /* DMAMUX_2: Source 40 */
                                            /* DMAMUX_2: Source 41 */
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
    DMAMUX3_SIUL2_REQ5              = 202U, /* DMAMUX_3: Source 10 */
                                            /* DMAMUX_3: Source 11 */
                                            /* DMAMUX_3: Source 12 */
                                            /* DMAMUX_3: Source 13 */
                                            /* DMAMUX_3: Source 14 */
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
                                            /* DMAMUX_3: Source 25 */
                                            /* DMAMUX_3: Source 26 */
                                            /* DMAMUX_3: Source 27 */
                                            /* DMAMUX_3: Source 28 */
                                            /* DMAMUX_3: Source 29 */
                                            /* DMAMUX_3: Source 30 */
                                            /* DMAMUX_3: Source 31 */
                                            /* DMAMUX_3: Source 32 */
                                            /* DMAMUX_3: Source 33 */
                                            /* DMAMUX_3: Source 34 */
                                            /* DMAMUX_3: Source 35 */
                                            /* DMAMUX_3: Source 36 */
                                            /* DMAMUX_3: Source 37 */
                                            /* DMAMUX_3: Source 38 */
                                            /* DMAMUX_3: Source 39 */
                                            /* DMAMUX_3: Source 40 */
    DMAMUX3_SIUL2_REQ8              = 233U, /* DMAMUX_3: Source 41 */
    DMAMUX3_SIUL2_REQ3              = 234U, /* DMAMUX_3: Source 42 */
                                            /* DMAMUX_3: Source 43 */
                                            /* DMAMUX_3: Source 44 */
    DMAMUX3_DSPI_2_CMD              = 237U, /* DMAMUX_3: Source 45 */
    DMAMUX3_DSPI_1_RX               = 238U, /* DMAMUX_3: Source 46 */
    DMAMUX3_DSPI_1_TX               = 239U, /* DMAMUX_3: Source 47 */
    DMAMUX3_ADC23_DECFILT_IN        = 240U, /* DMAMUX_3: Source 48 */
                                            /* DMAMUX_3: Source 49 */
    DMAMUX3_PSI5_STX                = 242U, /* DMAMUX_3: Source 50 */
    DMAMUX3_EQADC0_ADC01_RFIFO6     = 243U, /* DMAMUX_3: Source 51 */
    DMAMUX3_EQADC0_ADC01_RFIFO7     = 244U, /* DMAMUX_3: Source 52 */
                                            /* DMAMUX_3: Source 53 */
                                            /* DMAMUX_3: Source 54 */
                                            /* DMAMUX_3: Source 55 */
                                            /* DMAMUX_3: Source 56 */
    DMAMUX3_EQADC0_ADC01_CFIFO6     = 249U, /* DMAMUX_3: Source 57 */
    DMAMUX3_EQADC0_ADC01_CFIFO7     = 250U, /* DMAMUX_3: Source 58 */
                                            /* DMAMUX_3: Source 59 */
                                            /* DMAMUX_3: Source 60 */
                                            /* DMAMUX_3: Source 61 */
                                            /* DMAMUX_3: Source 62 */
    DMAMUX3_ALWAYS_ON_0             = 255U, /* DMAMUX_3: Source 63 */

    /* DMAMUX_4: DMAMUX Channel 32 - 47 (eDMA_0 Channel 32 - 47) */
    DMAMUX4_RESERVED_0_A            = 256U, /* DMAMUX_4: Source 0  */
                                            /* DMAMUX_4: Source 1  */
                                            /* DMAMUX_4: Source 2  */
                                            /* DMAMUX_4: Source 3  */
                                            /* DMAMUX_4: Source 4  */
    DMAMUX4_DSPI_3_RX               = 261U, /* DMAMUX_4: Source 5  */
    DMAMUX4_DSPI_3_TX               = 262U, /* DMAMUX_4: Source 6  */
    DMAMUX4_LINFLEXD_0_RX           = 263U, /* DMAMUX_4: Source 7  */
    DMAMUX4_LINFLEXD_0_TX           = 264U, /* DMAMUX_4: Source 8  */
    DMAMUX4_LINFLEXD_14_RX          = 265U, /* DMAMUX_4: Source 9  */
    DMAMUX4_LINFLEXD_14_TX          = 266U, /* DMAMUX_4: Source 10 */
    DMAMUX4_PSI5_0_CH1_RX_PSI5      = 267U, /* DMAMUX_4: Source 11 */
    DMAMUX4_PSI5_0_CH1_RX_SENT      = 268U, /* DMAMUX_4: Source 12 */
                                            /* DMAMUX_4: Source 13 */
                                            /* DMAMUX_4: Source 14 */
    DMAMUX4_SIUL2_REQ9              = 271U, /* DMAMUX_4: Source 15 */
    DMAMUX4_GTM_TIM0_IRQ0           = 272U, /* DMAMUX_4: Source 16 */
    DMAMUX4_GTM_TIM0_IRQ1           = 273U, /* DMAMUX_4: Source 17 */
    DMAMUX4_GTM_TOM0_IRQ0           = 274U, /* DMAMUX_4: Source 18 */
    DMAMUX4_GTM_TOM0_IRQ1           = 275U, /* DMAMUX_4: Source 19 */
                                            /* DMAMUX_4: Source 20 */
                                            /* DMAMUX_4: Source 21 */
                                            /* DMAMUX_4: Source 22 */
                                            /* DMAMUX_4: Source 23 */
    DMAMUX4_GTM_TOM1_IRQ0           = 280U, /* DMAMUX_4: Source 24 */
    DMAMUX4_GTM_TOM1_IRQ1           = 281U, /* DMAMUX_4: Source 25 */
                                            /* DMAMUX_4: Source 26 */
                                            /* DMAMUX_4: Source 27 */
                                            /* DMAMUX_4: Source 28 */
                                            /* DMAMUX_4: Source 29 */
                                            /* DMAMUX_4: Source 30 */
                                            /* DMAMUX_4: Source 31 */
                                            /* DMAMUX_4: Source 32 */
                                            /* DMAMUX_4: Source 33 */
    DMAMUX4_DSPI_3_CMD              = 290U, /* DMAMUX_4: Source 34 */
                                            /* DMAMUX_4: Source 35 */
                                            /* DMAMUX_4: Source 36 */
                                            /* DMAMUX_4: Source 37 */
    DMAMUX4_ADC01_DECFILT_IN        = 294U, /* DMAMUX_4: Source 38 */
    DMAMUX4_DSPI_0_CMD              = 295U, /* DMAMUX_4: Source 39 */
    DMAMUX4_DSPI_0_RX               = 296U, /* DMAMUX_4: Source 40 */
    DMAMUX4_DSPI_0_TX               = 297U, /* DMAMUX_4: Source 41 */
    DMAMUX4_AMU_0                   = 298U, /* DMAMUX_4: Source 42 */
    DMAMUX4_MCAN_5                  = 299U, /* DMAMUX_4: Source 43 */
    DMAMUX4_MCAN_6                  = 300U, /* DMAMUX_4: Source 44 */
    DMAMUX4_SIUL2_REQ6              = 301U, /* DMAMUX_4: Source 45 */
    DMAMUX4_SIUL2_REQ7              = 302U, /* DMAMUX_4: Source 46 */
    DMAMUX4_SIUL2_REQ12             = 303U, /* DMAMUX_4: Source 47 */
    DMAMUX4_SIUL2_REQ13             = 304U, /* DMAMUX_4: Source 48 */
    DMAMUX4_SIUL2_REQ14             = 305U, /* DMAMUX_4: Source 49 */
    DMAMUX4_SIUL2_REQ15             = 306U, /* DMAMUX_4: Source 50 */
    DMAMUX4_EQADC1_ADC23_RFIFO6     = 307U, /* DMAMUX_4: Source 51 */
    DMAMUX4_EQADC1_ADC23_RFIFO7     = 308U, /* DMAMUX_4: Source 52 */
                                            /* DMAMUX_4: Source 53 */
                                            /* DMAMUX_4: Source 54 */
                                            /* DMAMUX_4: Source 55 */
                                            /* DMAMUX_4: Source 56 */
    DMAMUX4_EQADC1_ADC23_CFIFO6     = 313U, /* DMAMUX_4: Source 57 */
    DMAMUX4_EQADC1_ADC23_CFIFO7     = 314U, /* DMAMUX_4: Source 58 */
                                            /* DMAMUX_4: Source 59 */
                                            /* DMAMUX_4: Source 60 */
                                            /* DMAMUX_4: Source 61 */
                                            /* DMAMUX_4: Source 62 */
    DMAMUX4_ALWAYS_ON_0             = 319U, /* DMAMUX_4: Source 63 */

    /* DMAMUX_5: DMAMUX Channel 48 - 63 (eDMA_0 Channel 48 - 63) */
    DMAMUX5_RESERVED_0_A            = 320U, /* DMAMUX_5: Source 0  */
                                            /* DMAMUX_5: Source 1  */
                                            /* DMAMUX_5: Source 2  */
                                            /* DMAMUX_5: Source 3  */
    DMAMUX5_DSPI_5_RX               = 324U, /* DMAMUX_5: Source 4  */
    DMAMUX5_DSPI_5_TX               = 325U, /* DMAMUX_5: Source 5  */
    DMAMUX5_LINFLEXD_1_RX           = 326U, /* DMAMUX_5: Source 6  */
    DMAMUX5_LINFLEXD_1_TX           = 327U, /* DMAMUX_5: Source 7  */
    DMAMUX5_LINFLEXD_15_RX          = 328U, /* DMAMUX_5: Source 8  */
    DMAMUX5_LINFLEXD_15_TX          = 329U, /* DMAMUX_5: Source 9  */
    DMAMUX5_SENT_0_RX_FAST          = 330U, /* DMAMUX_5: Source 10 */
    DMAMUX5_SENT_0_RX_SLOW          = 331U, /* DMAMUX_5: Source 11 */
                                            /* DMAMUX_5: Source 12 */
                                            /* DMAMUX_5: Source 13 */
    DMAMUX5_SIUL2_REQ10             = 334U, /* DMAMUX_5: Source 14 */
    DMAMUX5_GTM_TIM0_IRQ2           = 335U, /* DMAMUX_5: Source 15 */
    DMAMUX5_GTM_TIM0_IRQ3           = 336U, /* DMAMUX_5: Source 16 */
    DMAMUX5_GTM_TOM0_IRQ4           = 337U, /* DMAMUX_5: Source 17 */
    DMAMUX5_GTM_TOM0_IRQ5           = 338U, /* DMAMUX_5: Source 18 */
                                            /* DMAMUX_5: Source 19 */
                                            /* DMAMUX_5: Source 20 */
                                            /* DMAMUX_5: Source 21 */
                                            /* DMAMUX_5: Source 22 */
    DMAMUX5_GTM_TOM1_IRQ4           = 343U, /* DMAMUX_5: Source 23 */
    DMAMUX5_GTM_TOM1_IRQ5           = 344U, /* DMAMUX_5: Source 24 */
                                            /* DMAMUX_5: Source 25 */
                                            /* DMAMUX_5: Source 26 */
                                            /* DMAMUX_5: Source 27 */
                                            /* DMAMUX_5: Source 28 */
                                            /* DMAMUX_5: Source 29 */
                                            /* DMAMUX_5: Source 30 */
                                            /* DMAMUX_5: Source 31 */
                                            /* DMAMUX_5: Source 32 */
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
                                            /* DMAMUX_5: Source 45 */
                                            /* DMAMUX_5: Source 46 */
                                            /* DMAMUX_5: Source 47 */
                                            /* DMAMUX_5: Source 48 */
                                            /* DMAMUX_5: Source 49 */
                                            /* DMAMUX_5: Source 50 */
                                            /* DMAMUX_5: Source 51 */
                                            /* DMAMUX_5: Source 52 */
                                            /* DMAMUX_5: Source 53 */
                                            /* DMAMUX_5: Source 54 */
                                            /* DMAMUX_5: Source 55 */
                                            /* DMAMUX_5: Source 56 */
                                            /* DMAMUX_5: Source 57 */
                                            /* DMAMUX_5: Source 58 */
                                            /* DMAMUX_5: Source 59 */
                                            /* DMAMUX_5: Source 60 */
                                            /* DMAMUX_5: Source 61 */
                                            /* DMAMUX_5: Source 62 */
    DMAMUX5_ALWAYS_ON_0             = 383U, /* DMAMUX_5: Source 63 */

    /* DMAMUX_6: DMAMUX Channel 64 - 79 (eDMA_1 Channel 0 - 15) */
    DMAMUX6_RESERVED_0_A            = 384U, /* DMAMUX_6: Source 0  */
                                            /* DMAMUX_6: Source 1  */
                                            /* DMAMUX_6: Source 2  */
                                            /* DMAMUX_6: Source 3  */
                                            /* DMAMUX_6: Source 4  */
                                            /* DMAMUX_6: Source 5  */
                                            /* DMAMUX_6: Source 6  */
                                            /* DMAMUX_6: Source 7  */
                                            /* DMAMUX_6: Source 8  */
    DMAMUX6_PSI5_0_CH2_RX_PSI5      = 393U, /* DMAMUX_6: Source 9  */
    DMAMUX6_PSI5_0_CH2_RX_SENT      = 394U, /* DMAMUX_6: Source 10 */
    DMAMUX6_PSI5_1_CH1_RX_PSI5      = 395U, /* DMAMUX_6: Source 11 */
    DMAMUX6_PSI5_1_CH1_RX_SENT      = 396U, /* DMAMUX_6: Source 12 */
    DMAMUX6_DSPI_6_RX               = 397U, /* DMAMUX_6: Source 13 */
    DMAMUX6_DSPI_6_TX               = 398U, /* DMAMUX_6: Source 14 */
    DMAMUX6_DSPI_6_CMD              = 399U, /* DMAMUX_6: Source 15 */
    DMAMUX6_LINFLEXD_16_RX          = 400U, /* DMAMUX_6: Source 16 */
    DMAMUX6_LINFLEXD_16_TX          = 401U, /* DMAMUX_6: Source 17 */
    DMAMUX6_I2C_1_RX                = 402U, /* DMAMUX_6: Source 18 */
    DMAMUX6_I2C_1_TX                = 403U, /* DMAMUX_6: Source 19 */
                                            /* DMAMUX_6: Source 20 */
                                            /* DMAMUX_6: Source 21 */
                                            /* DMAMUX_6: Source 22 */
                                            /* DMAMUX_6: Source 23 */
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
                                            /* DMAMUX_6: Source 40 */
                                            /* DMAMUX_6: Source 41 */
                                            /* DMAMUX_6: Source 42 */
                                            /* DMAMUX_6: Source 43 */
                                            /* DMAMUX_6: Source 44 */
                                            /* DMAMUX_6: Source 45 */
                                            /* DMAMUX_6: Source 46 */
                                            /* DMAMUX_6: Source 47 */
    DMAMUX6_MCAN_3                  = 432U, /* DMAMUX_6: Source 48 */
                                            /* DMAMUX_6: Source 49 */
                                            /* DMAMUX_6: Source 50 */
                                            /* DMAMUX_6: Source 51 */
                                            /* DMAMUX_6: Source 52 */
                                            /* DMAMUX_6: Source 53 */
                                            /* DMAMUX_6: Source 54 */
                                            /* DMAMUX_6: Source 55 */
                                            /* DMAMUX_6: Source 56 */
                                            /* DMAMUX_6: Source 57 */
                                            /* DMAMUX_6: Source 58 */
                                            /* DMAMUX_6: Source 59 */
                                            /* DMAMUX_6: Source 60 */
                                            /* DMAMUX_6: Source 61 */
                                            /* DMAMUX_6: Source 62 */
    DMAMUX6_ALWAYS_ON_0             = 447U, /* DMAMUX_6: Source 63 */

    /* DMAMUX_7: DMAMUX Channel 80 - 95 (eDMA_1 Channel 16 - 31) */
    DMAMUX7_RESERVED_0_A            = 448U, /* DMAMUX_7: Source 0  */
    DMAMUX7_EQADC1_ADC23_RFIFO0     = 449U, /* DMAMUX_7: Source 1  */
    DMAMUX7_EQADC1_ADC23_RFIFO1     = 450U, /* DMAMUX_7: Source 2  */
    DMAMUX7_EQADC1_ADC23_RFIFO2     = 451U, /* DMAMUX_7: Source 3  */
    DMAMUX7_EQADC1_ADC23_RFIFO3     = 452U, /* DMAMUX_7: Source 4  */
    DMAMUX7_EQADC1_ADC23_RFIFO4     = 453U, /* DMAMUX_7: Source 5  */
    DMAMUX7_EQADC1_ADC23_RFIFO5     = 454U, /* DMAMUX_7: Source 6  */
    DMAMUX7_EQADC1_ADC23_RFIFO6     = 455U, /* DMAMUX_7: Source 7  */
    DMAMUX7_EQADC1_ADC23_RFIFO7     = 456U, /* DMAMUX_7: Source 8  */
    DMAMUX7_EQADC1_ADC23_CFIFO0     = 457U, /* DMAMUX_7: Source 9  */
    DMAMUX7_EQADC1_ADC23_CFIFO1     = 458U, /* DMAMUX_7: Source 10 */
    DMAMUX7_EQADC1_ADC23_CFIFO2     = 459U, /* DMAMUX_7: Source 11 */
    DMAMUX7_EQADC1_ADC23_CFIFO3     = 460U, /* DMAMUX_7: Source 12 */
    DMAMUX7_EQADC1_ADC23_CFIFO4     = 461U, /* DMAMUX_7: Source 13 */
    DMAMUX7_EQADC1_ADC23_CFIFO5     = 462U, /* DMAMUX_7: Source 14 */
    DMAMUX7_EQADC1_ADC23_CFIFO6     = 463U, /* DMAMUX_7: Source 15 */
    DMAMUX7_EQADC1_ADC23_CFIFO7     = 464U, /* DMAMUX_7: Source 16 */
                                            /* DMAMUX_7: Source 17 */
                                            /* DMAMUX_7: Source 18 */
                                            /* DMAMUX_7: Source 19 */
                                            /* DMAMUX_7: Source 20 */
                                            /* DMAMUX_7: Source 21 */
                                            /* DMAMUX_7: Source 22 */
                                            /* DMAMUX_7: Source 23 */
                                            /* DMAMUX_7: Source 24 */
                                            /* DMAMUX_7: Source 25 */
                                            /* DMAMUX_7: Source 26 */
                                            /* DMAMUX_7: Source 27 */
                                            /* DMAMUX_7: Source 28 */
                                            /* DMAMUX_7: Source 29 */
                                            /* DMAMUX_7: Source 30 */
                                            /* DMAMUX_7: Source 31 */
                                            /* DMAMUX_7: Source 32 */
                                            /* DMAMUX_7: Source 33 */
                                            /* DMAMUX_7: Source 34 */
    DMAMUX7_PSI5_0_CH0_RX_PSI5      = 483U, /* DMAMUX_7: Source 35 */
    DMAMUX7_PSI5_0_CH0_RX_SENT      = 484U, /* DMAMUX_7: Source 36 */
    DMAMUX7_PSI5_0_CH1_RX_PSI5      = 485U, /* DMAMUX_7: Source 37 */
    DMAMUX7_PSI5_0_CH1_RX_SENT      = 486U, /* DMAMUX_7: Source 38 */
    DMAMUX7_PSI5_0_CH2_RX_PSI5      = 487U, /* DMAMUX_7: Source 39 */
    DMAMUX7_PSI5_0_CH2_RX_SENT      = 488U, /* DMAMUX_7: Source 40 */
                                            /* DMAMUX_7: Source 41 */
                                            /* DMAMUX_7: Source 42 */
                                            /* DMAMUX_7: Source 43 */
                                            /* DMAMUX_7: Source 44 */
    DMAMUX7_DSPI_3_CMD              = 493U, /* DMAMUX_7: Source 45 */
    DMAMUX7_DSPI_3_RX               = 494U, /* DMAMUX_7: Source 46 */
    DMAMUX7_DSPI_3_TX               = 495U, /* DMAMUX_7: Source 47 */
    DMAMUX7_DSPI_5_CMD              = 496U, /* DMAMUX_7: Source 48 */
    DMAMUX7_DSPI_5_RX               = 497U, /* DMAMUX_7: Source 49 */
    DMAMUX7_DSPI_5_TX               = 498U, /* DMAMUX_7: Source 50 */
    DMAMUX7_MCAN_4                  = 499U, /* DMAMUX_7: Source 51 */
                                            /* DMAMUX_7: Source 52 */
                                            /* DMAMUX_7: Source 53 */
                                            /* DMAMUX_7: Source 54 */
                                            /* DMAMUX_7: Source 55 */
    DMAMUX7_MCAN_4_TXR              = 504U, /* DMAMUX_7: Source 56 */
    DMAMUX7_MCAN_4_TXER             = 505U, /* DMAMUX_7: Source 57 */
    DMAMUX7_MCAN_4_RX1R             = 506U, /* DMAMUX_7: Source 58 */
    DMAMUX7_MCAN_4_RX0R             = 507U, /* DMAMUX_7: Source 59 */
    DMAMUX7_MCAN_8_TXR              = 508U, /* DMAMUX_7: Source 60 */
    DMAMUX7_MCAN_8_TXER             = 509U, /* DMAMUX_7: Source 61 */
    DMAMUX7_MCAN_8_RX1R             = 510U, /* DMAMUX_7: Source 62 */
    DMAMUX7_ALWAYS_ON_0             = 511U, /* DMAMUX_7: Source 63 */

    /* DMAMUX_8: DMAMUX Channel 96 - 111 (eDMA_1 Channel 32 - 47) */
    DMAMUX8_RESERVED_0_A            = 512U, /* DMAMUX_8: Source 0  */
                                            /* DMAMUX_8: Source 1  */
                                            /* DMAMUX_8: Source 2  */
                                            /* DMAMUX_8: Source 3  */
                                            /* DMAMUX_8: Source 4  */
                                            /* DMAMUX_8: Source 5  */
                                            /* DMAMUX_8: Source 6  */
                                            /* DMAMUX_8: Source 7  */
                                            /* DMAMUX_8: Source 8  */
                                            /* DMAMUX_8: Source 9  */
                                            /* DMAMUX_8: Source 10 */
                                            /* DMAMUX_8: Source 11 */
                                            /* DMAMUX_8: Source 12 */
                                            /* DMAMUX_8: Source 13 */
                                            /* DMAMUX_8: Source 14 */
                                            /* DMAMUX_8: Source 15 */
                                            /* DMAMUX_8: Source 16 */
                                            /* DMAMUX_8: Source 17 */
                                            /* DMAMUX_8: Source 18 */
                                            /* DMAMUX_8: Source 19 */
                                            /* DMAMUX_8: Source 20 */
                                            /* DMAMUX_8: Source 21 */
                                            /* DMAMUX_8: Source 22 */
                                            /* DMAMUX_8: Source 23 */
                                            /* DMAMUX_8: Source 24 */
                                            /* DMAMUX_8: Source 25 */
                                            /* DMAMUX_8: Source 26 */
                                            /* DMAMUX_8: Source 27 */
                                            /* DMAMUX_8: Source 28 */
                                            /* DMAMUX_8: Source 29 */
                                            /* DMAMUX_8: Source 30 */
                                            /* DMAMUX_8: Source 31 */
                                            /* DMAMUX_8: Source 32 */
                                            /* DMAMUX_8: Source 33 */
    DMAMUX8_PSI5_1_CH0_RX_PSI5      = 546U, /* DMAMUX_8: Source 34 */
    DMAMUX8_PSI5_1_CH0_RX_SENT      = 547U, /* DMAMUX_8: Source 35 */
    DMAMUX8_PSI5_1_CH1_RX_PSI5      = 548U, /* DMAMUX_8: Source 36 */
    DMAMUX8_PSI5_1_CH1_RX_SENT      = 549U, /* DMAMUX_8: Source 37 */
    DMAMUX8_ADC01_DECFILT_IN        = 550U, /* DMAMUX_8: Source 38 */
    DMAMUX8_ADC01_DECFILT_OUT       = 551U, /* DMAMUX_8: Source 39 */
    DMAMUX8_ADC23_DECFILT_IN        = 552U, /* DMAMUX_8: Source 40 */
    DMAMUX8_MCAN_8_RX0R             = 553U, /* DMAMUX_8: Source 41 */
                                            /* DMAMUX_8: Source 42 */
    DMAMUX8_DSPI_4_CMD              = 555U, /* DMAMUX_8: Source 43 */
    DMAMUX8_DSPI_4_RX               = 556U, /* DMAMUX_8: Source 44 */
    DMAMUX8_DSPI_4_TX               = 557U, /* DMAMUX_8: Source 45 */
    DMAMUX8_LINFLEXD_3_TX           = 558U, /* DMAMUX_8: Source 46 */
    DMAMUX8_LINFLEXD_3_RX           = 559U, /* DMAMUX_8: Source 47 */
                                            /* DMAMUX_8: Source 48 */
                                            /* DMAMUX_8: Source 49 */
    DMAMUX8_LINFLEXD_5_TX           = 562U, /* DMAMUX_8: Source 50 */
    DMAMUX8_LINFLEXD_5_RX           = 563U, /* DMAMUX_8: Source 51 */
    DMAMUX8_LINFLEXD_6_TX           = 564U, /* DMAMUX_8: Source 52 */
    DMAMUX8_LINFLEXD_6_RX           = 565U, /* DMAMUX_8: Source 53 */
                                            /* DMAMUX_8: Source 54 */
                                            /* DMAMUX_8: Source 55 */
                                            /* DMAMUX_8: Source 56 */
                                            /* DMAMUX_8: Source 57 */
    DMAMUX8_LINFLEXD_9_TX           = 570U, /* DMAMUX_8: Source 58 */
    DMAMUX8_LINFLEXD_9_RX           = 571U, /* DMAMUX_8: Source 59 */
    DMAMUX8_LINFLEXD_10_TX          = 572U, /* DMAMUX_8: Source 60 */
    DMAMUX8_LINFLEXD_10_RX          = 573U, /* DMAMUX_8: Source 61 */
                                            /* DMAMUX_8: Source 62 */
    DMAMUX8_ALWAYS_ON_0             = 575U, /* DMAMUX_8: Source 63 */

    /* DMAMUX_9: DMAMUX Channel 112 - 127 (eDMA_1 Channel 48 - 63) */
    DMAMUX9_RESERVED_0_A            = 576U, /* DMAMUX_9: Source 0  */
                                            /* DMAMUX_9: Source 1  */
                                            /* DMAMUX_9: Source 2  */
                                            /* DMAMUX_9: Source 3  */
                                            /* DMAMUX_9: Source 4  */
                                            /* DMAMUX_9: Source 5  */
                                            /* DMAMUX_9: Source 6  */
                                            /* DMAMUX_9: Source 7  */
                                            /* DMAMUX_9: Source 8  */
                                            /* DMAMUX_9: Source 9  */
                                            /* DMAMUX_9: Source 10 */
    DMAMUX9_I2C_0_RX                = 587U, /* DMAMUX_9: Source 11 */
    DMAMUX9_I2C_0_TX                = 588U, /* DMAMUX_9: Source 12 */
                                            /* DMAMUX_9: Source 13 */
                                            /* DMAMUX_9: Source 14 */
                                            /* DMAMUX_9: Source 15 */
                                            /* DMAMUX_9: Source 16 */
    DMAMUX9_EQADC0_ADC01_RFIFO0     = 593U, /* DMAMUX_9: Source 17 */
    DMAMUX9_EQADC0_ADC01_RFIFO1     = 594U, /* DMAMUX_9: Source 18 */
    DMAMUX9_EQADC0_ADC01_RFIFO2     = 595U, /* DMAMUX_9: Source 19 */
    DMAMUX9_EQADC0_ADC01_RFIFO3     = 596U, /* DMAMUX_9: Source 20 */
    DMAMUX9_EQADC0_ADC01_RFIFO4     = 597U, /* DMAMUX_9: Source 21 */
    DMAMUX9_EQADC0_ADC01_RFIFO5     = 598U, /* DMAMUX_9: Source 22 */
    DMAMUX9_EQADC0_ADC01_RFIFO6     = 599U, /* DMAMUX_9: Source 23 */
    DMAMUX9_EQADC0_ADC01_RFIFO7     = 600U, /* DMAMUX_9: Source 24 */
    DMAMUX9_EQADC0_ADC01_CFIFO0     = 601U, /* DMAMUX_9: Source 25 */
    DMAMUX9_EQADC0_ADC01_CFIFO1     = 602U, /* DMAMUX_9: Source 26 */
    DMAMUX9_EQADC0_ADC01_CFIFO2     = 603U, /* DMAMUX_9: Source 27 */
    DMAMUX9_EQADC0_ADC01_CFIFO3     = 604U, /* DMAMUX_9: Source 28 */
    DMAMUX9_EQADC0_ADC01_CFIFO4     = 605U, /* DMAMUX_9: Source 29 */
    DMAMUX9_EQADC0_ADC01_CFIFO5     = 606U, /* DMAMUX_9: Source 30 */
    DMAMUX9_EQADC0_ADC01_CFIFO6     = 607U, /* DMAMUX_9: Source 31 */
    DMAMUX9_EQADC0_ADC01_CFIFO7     = 608U, /* DMAMUX_9: Source 32 */
                                            /* DMAMUX_9: Source 33 */
    DMAMUX9_MCAN_1                  = 610U, /* DMAMUX_9: Source 34 */
    DMAMUX9_MCAN_2                  = 611U, /* DMAMUX_9: Source 35 */
    DMAMUX9_ADC23_DECFILT_OUT       = 612U, /* DMAMUX_9: Source 36 */
                                            /* DMAMUX_9: Source 37 */
                                            /* DMAMUX_9: Source 38 */
                                            /* DMAMUX_9: Source 39 */
                                            /* DMAMUX_9: Source 40 */
    DMAMUX9_DSPI_2_CMD              = 617U, /* DMAMUX_9: Source 41 */
    DMAMUX9_DSPI_2_RX               = 618U, /* DMAMUX_9: Source 42 */
    DMAMUX9_DSPI_2_TX               = 619U, /* DMAMUX_9: Source 43 */
    DMAMUX9_SIUL2_REQ11             = 620U, /* DMAMUX_9: Source 44 */
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
    DMAMUX9_EMIOS_1_CH0             = 632U, /* DMAMUX_9: Source 56 */
    DMAMUX9_EMIOS_1_CH1             = 633U, /* DMAMUX_9: Source 57 */
    DMAMUX9_EMIOS_1_CH2             = 634U, /* DMAMUX_9: Source 58 */
    DMAMUX9_EMIOS_1_CH3             = 635U, /* DMAMUX_9: Source 59 */
                                            /* DMAMUX_9: Source 60 */
    DMAMUX9_LINFLEXD_12_TX          = 637U, /* DMAMUX_9: Source 61 */
    DMAMUX9_LINFLEXD_12_RX          = 638U, /* DMAMUX_9: Source 62 */
    DMAMUX9_ALWAYS_ON_0             = 639U  /* DMAMUX_9: Source 63 */
} eDMARequestSourceType;

/* CONSOLE CONFIG */
/* notice the RESOURCE_CHIP_CORE_NUM is 1 */
#if defined RESOURCE_SUPPORT_EIOMUX
#define CONSOLE_GPIO_CONFIG    {     \
                                    /* CORE_0 uart TX-RX: PAD_NUM, MSCR_IO_VAL, MUX_REG, MUX_REG_VAL, IO_MODE */   \
                                    {{PR6,  0x32840000, 0, 0, 16}, {PR10, 0x308C0000,  0, 0, 7}}  \
                               }
#else
#define CONSOLE_GPIO_CONFIG    {     \
                                    /* CORE_0 uart TX-RX: PAD_NUM, MSCR_IO_VAL, MUX_REG, MUX_REG_VAL */             \
                                    {{PQ13, 0x32840002, PQ13, 0}, {PQ15, 0x308C0000, 352, 2}}   \
                               }
#endif
/* CONSOLE CONFIG END */
/* LIN MODULE CONFIG */
#ifdef RESOURCE_SUPPORT_EIOMUX
#define LINFLEXD_GPIO_CONFIG    {     \
                                    /* LINFlexD_0 TX, RX: PAD_NUM, MSCR_IO_VAL, MUX_REG, MUX_REG_VAL, IO_MODE */  \
                                    {{PJ6, 0x32840000, 0, 0, 15}, {PJ9, 0x308C0000,  0, 0, 2}},  \
                                    /* LINFlexD_1 TX, RX, NOT support for 144-B package */                                \
                                    {{PC9,  0x32840000, 0, 0, 0}, {PC8,  0x308C0000, 0, 0, 0}},  \
                                    /* LINFlexD_2 TX, RX */                               \
                                    {{PA13, 0x32840000, 0, 0, 15}, {PH10, 0x308C0000, 0, 0, 5}},  \
                                    /* LINFlexD_3 TX, RX */                               \
                                    {{PA11, 0x32840000, 0, 0, 15}, {PA1,  0x308C0000, 0, 0, 5}},  \
                                    /* Unsupported. LINFlexD 4  */ \
                                    /* LINFlexD_5 TX, RX */                               \
                                    {{PC4,  0x32840000, 0, 0, 18}, {PC2,  0x308C0000, 0, 0, 5}},  \
                                    /* LINFlexD_6 TX, RX */                               \
                                    {{PD10, 0x32840000, 0, 0, 18}, {PC9,  0x308C0000, 0, 0, 5}},  \
                                    /* Unsupported. LINFlexD 7  */ \
                                    /* Unsupported. LINFlexD 8  */ \
                                    /* LINFlexD_9 TX, RX */                               \
                                    {{PN7,  0x32840000, 0, 0, 18}, {PX9,  0x308C0000, 0, 0, 5}},  \
                                    /* LINFlexD_10 TX, RX */                              \
                                    {{PD1,  0x32840000, 0, 0, 17}, {PL3,  0x308C0000, 0, 0, 5}},  \
                                    /* Unsupported. LINFlexD 11 */ \
                                    /* LINFlexD_12 TX, RX */                              \
                                    {{PC13, 0x32840000, 0, 0, 14}, {PC14, 0x308C0000, 0, 0, 1}},  \
                                    /* LINFlexD_14 TX, RX */                              \
                                    {{PA15, 0x32840000, 0, 0, 16}, {PB8,  0x308C0000, 0, 0, 5}},  \
                                    /* LINFlexD_15 TX, RX */                              \
                                    {{PQ5, 0x32840000, 0, 0, 14}, {PC7,  0x308C0000, 0, 0, 5}},  \
                                    /* LINFlexD_16 TX, RX */                              \
                                    {{PR6,  0x32840000, 0, 0, 16}, {PR10, 0x308C0000,  0, 0, 7}}   \
                                }
#else
#define LINFLEXD_GPIO_CONFIG    {     \
                                    /* LINFlexD_0 TX, RX: PAD_NUM, MSCR_IO_VAL, MUX_REG, MUX_REG_VAL */ \
                                    {{PA12, 0x32840002, PA12, 0}, {PA13, 0x308C0000,  336, 1}},  \
                                    /* LINFlexD_1 TX, RX*/                            \
                                    {{PC9,  0x32840004, PC9,  0}, {PC8,  0x308C0000,  337, 6}},  \
                                    /* LINFlexD_2 TX, RX */                               \
                                    {{PD14, 0x32840002, PD14, 0}, {PD15, 0x308C0000,  338, 1}},  \
                                    /* LINFlexD_3 TX, RX */                               \
                                    {{PI8,  0x3284000C, PI8, 0}, {PI4,  0x308C0000,  339, 2}},  \
                                    /* Unsupported. LINFlexD 4  */ \
                                    /* LINFlexD_5 TX, RX */                               \
                                    {{PC5,  0x3284000D, PC5, 0}, {PC6,  0x308C0000,  341, 0}},  \
                                    /* LINFlexD_6 TX, RX */                               \
                                    {{PM11,  0x3284000D, PM11, 0}, {PM12,  0x308C0000,  342, 1}},  \
                                    /* Unsupported. LINFlexD 7  */ \
                                    /* Unsupported. LINFlexD 8  */ \
                                    /* LINFlexD_9 TX, RX */                               \
                                    {{PN6,  0x3284000E, PN6, 0}, {PD10, 0x308C0000,  345, 0}},  \
                                    /* LINFlexD_10 TX, RX */                              \
                                    {{PN12, 0x3284000E, PN12, 0}, {PN14, 0x308C0000, 346, 1}},  \
                                    /* Unsupported. LINFlexD 11 */ \
                                    /* LINFlexD_12 TX, RX */                              \
                                    {{PQ1,  0x3284000D, PQ1, 0}, {PF4,  0x308C0000,  348, 0}},  \
                                    /* LINFlexD_14 TX, RX */                              \
                                    {{PC10, 0x32840002, PC10, 0}, {PC12, 0x308C0000, 350, 2}},  \
                                    /* LINFlexD_15 TX, RX */                              \
                                    {{PC2,  0x32840006, PC2, 0}, {PC1,  0x308C0000,  351, 6}},  \
                                    /* LINFlexD_16 TX, RX */                              \
                                    {{PQ13, 0x32840002, PQ13, 0}, {PQ15, 0x308C0000, 352, 2}}   \
                                }
#endif
#define LINFLEXD_EDMA_CONFIG    { \
                                    {{EDMA_CHN33_NUMBER,  DMAMUX4_LINFLEXD_0_TX,  FALSE}, {EDMA_CHN32_NUMBER,  DMAMUX4_LINFLEXD_0_RX,  FALSE}}, \
                                    {{EDMA_CHN49_NUMBER,  DMAMUX5_LINFLEXD_1_TX,  FALSE}, {EDMA_CHN48_NUMBER,  DMAMUX5_LINFLEXD_1_RX,  FALSE}}, \
                                    {{EDMA_CHN51_NUMBER,  DMAMUX5_LINFLEXD_2_TX,  FALSE}, {EDMA_CHN50_NUMBER,  DMAMUX5_LINFLEXD_2_RX,  FALSE}}, \
                                    {{EDMA_CHN98_NUMBER,  DMAMUX8_LINFLEXD_3_TX,  FALSE}, {EDMA_CHN99_NUMBER,  DMAMUX8_LINFLEXD_3_RX,  FALSE}}, \
                                    /* Unsupported. LINFlexD 4  */ \
                                    {{EDMA_CHN100_NUMBER, DMAMUX8_LINFLEXD_5_TX,  FALSE}, {EDMA_CHN101_NUMBER, DMAMUX8_LINFLEXD_5_RX,  FALSE}}, \
                                    {{EDMA_CHN100_NUMBER, DMAMUX8_LINFLEXD_6_TX,  FALSE}, {EDMA_CHN101_NUMBER, DMAMUX8_LINFLEXD_6_RX,  FALSE}}, \
                                    /* Unsupported. LINFlexD 7  */ \
                                    /* Unsupported. LINFlexD 8  */ \
                                    {{EDMA_CHN100_NUMBER, DMAMUX8_LINFLEXD_9_TX,  FALSE}, {EDMA_CHN101_NUMBER, DMAMUX8_LINFLEXD_9_RX,  FALSE}}, \
                                    {{EDMA_CHN100_NUMBER, DMAMUX8_LINFLEXD_10_TX, FALSE}, {EDMA_CHN101_NUMBER, DMAMUX8_LINFLEXD_10_RX, FALSE}}, \
                                    /* Unsupported. LINFlexD 11 */ \
                                    {{EDMA_CHN119_NUMBER, DMAMUX9_LINFLEXD_12_TX, FALSE}, {EDMA_CHN120_NUMBER, DMAMUX9_LINFLEXD_12_RX, FALSE}}, \
                                    {{EDMA_CHN35_NUMBER,  DMAMUX4_LINFLEXD_14_TX, FALSE}, {EDMA_CHN34_NUMBER,  DMAMUX4_LINFLEXD_14_RX, FALSE}}, \
                                    {{EDMA_CHN53_NUMBER,  DMAMUX5_LINFLEXD_15_TX, FALSE}, {EDMA_CHN54_NUMBER,  DMAMUX5_LINFLEXD_15_RX, FALSE}}, \
                                    {{EDMA_CHN65_NUMBER,  DMAMUX6_LINFLEXD_16_TX, FALSE}, {EDMA_CHN64_NUMBER,  DMAMUX6_LINFLEXD_16_RX, FALSE}} \
                                }
/* LIN MODULE CONFIG END */
/* I2C MODULE CONFIG */
#define I2C_MODULE_CLK PER_CLK
#define I2C_MOD_MAX 2
#ifdef RESOURCE_SUPPORT_EIOMUX
#define I2C_GPIO_CONFIG    {     \
                                /* I2C 0 SCL-SDA: PAD_NUM, MSCR_IO_VAL, MUX_REG, MUX_REG_VAL, IO_MODE */   \
                                {{PC11, 0x318D0000, 0, 0, 6}, {PC14, 0x318D0000, 0, 0, 6}},  \
                                /* I2C 1 SCL-SDA */                     \
                                {{PQ9,  0x318D0000, 0, 0, 4}, {PQ8,  0x318D0000, 0, 0, 4}},  \
                           }
#else
#ifdef RESOURCE_SUPPORT_EIOMUX2
#define I2C_GPIO_CONFIG    {     \
                                /* I2C 0 SCL-SDA: PAD_NUM, MSCR_IO, MUX_REG, MUX_REG_VAL*/                   \
                                {{PK4,  0x0647, 47, 2}, {PJ6,  0x0641, 46, 3}},  \
                                /* I2C 1 SCL-SDA */                            \
                                {{PD0, 0x0641, 45, 2}, {PD1, 0x0641, 44, 1}},  \
                           }
#else
#define I2C_GPIO_CONFIG    {     \
                                /* I2C 0 SCL-SDA: PAD_NUM, MSCR_IO, MUX_REG, MUX_REG_VAL*/                   \
                                {{PC6,  0x318D0001, 297, 1}, {PC7,  0x318D0001, 296, 1}},  \
                                /* {{PD1,  0x318D0001, 297, 2}, {PD2,  0x318D0001, 296, 2}}, */  \
                                /* I2C 1 SCL-SDA */                            \
                                {{PQ13, 0x318D0004, 299, 2}, {PQ15, 0x318D0001, 298, 2}},  \
                           }
#endif

#endif
/* I2C MODULE CONFIG END */
/* FOR PSI5 MODULE CONFIG */
#define PSI5_0_CH_MAX 3U
#define PSI5_1_CH_MAX 2U
#define PSI5_CH_MAX (PSI5_0_CH_MAX + PSI5_1_CH_MAX)
#ifdef RESOURCE_SUPPORT_EIOMUX
#define PSI5_GPIO_CONFIG     {     \
                                /* PSI_0 TX RX */                           \
                                {{PH7,  0x32840000, 0, 18}, {PQ11,  0x308C0000, 0, 7}},  \
                                {{PH0,  0x32840000, 0, 18}, {PF13,  0x308C0000, 0, 7}},  \
                                {{PJ13,  0x32840000, 0, 16}, {PJ9,  0x308C0000, 0, 8}},  \
                                /* PSI_1 TX RX */                            \
                                {{PJ9,     0x32840000, 0, 16}, {PJ6,     0x308C0000, 0, 7}},  \
                                {{PL3, 0x32840000, 0,16}, {PJ15, 0x308C0000, 0, 7}} \
                            }
#else
#define PSI5_GPIO_CONFIG    {     \
                                /* PSI_0 TX RX */                           \
                                {{PC0,  0x32840005, PC0, 0}, {PC1,  0x308C0000, 304, 2}},  \
                                {{PC5,  0x32840005, PC5, 0}, {PC6,  0x308C0000, 308, 1}},  \
                                {{PF3,  0x32840005, PF3, 0}, {PF2,  0x308C0000, 316, 1}},  \
                                /* PSI_1 TX RX */                            \
                                {{PC3,     0x32840005, PC3, 0}, {PC4,     0x308C0000, 312, 1}},  \
                                {{PJ10, 0x32840005, PJ10,0}, {PJ11, 0x308C0000, 320, 1}} \
                            }
#endif
/* FOR PSI5 MODULE CONFIG END */
/* FOR PSI5_S MODULE CONFIG */
#define PSI5_S_CH_MAX 1U
#define PSI5_S_GPIO_CONFIG  {     \
                                /* PSI5_0 TCK - TX - RX */                           \
                                {{PC4,  0x32840002, 0, 0}, {PC5,  0x32840002, 0, 0}, {PC6,  0x308C0000, 843-512, 2}},  \
                            }
/* FOR PSI5_S MODULE CONFIG END */

#endif  /* defined(CCFC3008PCSN) */
#endif /* CCFC3008PCSN_FEATURES_H_ */
