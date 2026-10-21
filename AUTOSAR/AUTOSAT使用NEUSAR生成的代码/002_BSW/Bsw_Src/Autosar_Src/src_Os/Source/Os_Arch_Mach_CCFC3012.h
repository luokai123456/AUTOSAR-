/*
********************************************************************************
*
*  File name: Os_Arch_Mach_CCFC3012.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: JiangGL/2025.6.25
* Change: New create.
* Cause: New
********************************************************************************
*/

#ifndef OS_ARCH_MACH_CCFC3012_H_
#define OS_ARCH_MACH_CCFC3012_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Arch_Types.h"
#include "Os_Cfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Leading 0 hardware supports macro switches. */
#define OS_CFG_COUNT_LEAD_ZEROS_HARDWARE                (STD_ON)
/* Brief EE bit of MSR. */
#define OS_ARCH_ISR_STATE_MASK                          ((uint32)0x00008000U)
#define OS_NAUGHT_VALUE                                 (0U)
/* Assembly macro for "mtspr" operation. */
#define Os_Hal_WriteSPR(spr, val)  __MTSPR((uint32)spr, (uint32)val)
/* Abstraction of reading a core special purpose register. */
#define Os_Hal_ReadSPR(spr)                             __MFSPR((uint32)spr)
/* Define for using asm string statements in c functions. */
#define Os_Hal_Asm(x)                                   __asm(x)
/* Support software triggered interrupt macro definition. */
#define OS_SUPPORT_HARDWARE_TRIGGER_INTERRUPT
/* Core. */
/* MC_ME Register base address. */
#define OS_HAL_MC_ME_BASE_ADDRESS                       (0xFFFB8000U)
/* Interrupt Status Register. */
#define OS_HAL_MC_ME_IS_OFFSET                          (0x0000000CU)
/* Main core_1 Address Register. */
#define OS_HAL_MC_ME_CADDR2_OFFSET                      (0x00000208U)
/* Checker core_1 Address Register. */
#define OS_HAL_MC_ME_CADDR3_OFFSET                      (0x0000020CU)
/* Main core_2 Address Register. */
#define OS_HAL_MC_ME_CADDR6_OFFSET                      (0x00000218U)
/* Checker core_2 Address Register. */
#define OS_HAL_MC_ME_CADDR7_OFFSET                      (0x0000021CU)
/* Main core_3 Address Register. */
#define OS_HAL_MC_ME_CADDR8_OFFSET                      (0x00000220U)
/* Checker core_3 Address Register. */
#define OS_HAL_MC_ME_CADDR9_OFFSET                      (0x00000224U)
/* Main core_4 Address Register. */
#define OS_HAL_MC_ME_CADDR10_OFFSET                     (0x00000228U)
/* Main core_5 Address Register. */
#define OS_HAL_MC_ME_CADDR11_OFFSET                     (0x0000022CU)
/* Main core_1 Control Register. */
#define OS_HAL_MC_ME_CCTL2_OFFSET                       (0x000001C8U)
/* Checker core_1 Control Register. */
#define OS_HAL_MC_ME_CCTL3_OFFSET                       (0x000001CAU)
/* Main core_2 Control Register. */
#define OS_HAL_MC_ME_CCTL6_OFFSET                       (0x000001D0U)
/* Checker core_2 Control Register. */
#define OS_HAL_MC_ME_CCTL7_OFFSET                       (0x000001D2U)
/* Main core_3 Control Register. */
#define OS_HAL_MC_ME_CCTL8_OFFSET                       (0x000001D4U)
/* Checker core_3 Control Register. */
#define OS_HAL_MC_ME_CCTL9_OFFSET                       (0x000001D6U)
/* Main core_4 Control Register. */
#define OS_HAL_MC_ME_CCTL10_OFFSET                      (0x000001D8U)
/* Main core_5 Control Register. */
#define OS_HAL_MC_ME_CCTL11_OFFSET                      (0x000001DAU)
/* Global Status Register. */
#define OS_HAL_MC_ME_GS_OFFSET                          (0x00000000U)
/* Core Control Register. */
#define OS_HAL_MC_ME_MCTL_OFFSET                        (0x00000004U)
/* MC_ME unlock key1. */
#define OS_HAL_MC_ME_KEY1                               (0x00005AF0U)
/* MC_ME unlock key2. */
#define OS_HAL_MC_ME_KEY2                               (0x0000A50FU)
/* Core reset mask. */
#define OS_HAL_MC_ME_CORE_RESET_MASK                    (0x00000001U)
/* ME_CCTL MASK to control core. */
#define OS_HAL_MC_ME_CCTL_MASK                          (0x00FEU)
/* Current chip mode status mask. */
#define OS_HAL_CURRENT_MODE_MAKS                        (0xF0000000U)
/* Mode transition status. */
#define OS_HAL_MTRANS_MASK                              (0x08000000U)

/* Define mcu architecture. */
#define OS_ARCH                                         (ARCH_POWERPC)
#define OS_ARCH_PHYCOREID_1                             (1U)
#define OS_ARCH_PHYCOREID_2                             (2U)
#define OS_ARCH_PHYCOREID_3                             (3U)
#define OS_ARCH_PHYCOREID_4                             (4U)
#define OS_ARCH_PHYCOREID_5                             (5U)

/* Timer */
/* Interrupt resource. */
#define OS_ARCH_INTMASKLEVE_SUPPORT                     (STD_OFF)//关闭临界区使用

/* Stack resource. */
#define OS_STACK_TYPE_WIDTH                             (4U)
#define OS_STACK_RESERVED                               (0xAAAAAAAAU)
#define OS_GET_STACK_BOTTOM(StackArray)                 (&(StackArray)[0U])
#define OS_GET_STACK_TOP(StackArray, StackSize)         (&(StackArray)[(((StackSize)/OS_STACK_TYPE_WIDTH) - 1U)])
/* The actual stack head offset used. */
#define OS_STACK_TOP_OFFSET                             (16U)

/* Memory Protection Unit. */
/* Number of mpu's REGION. */
#define OS_CORE_CMPU_REGION_CNT                         (12U)
/* The region number of the CMPU used in the stack. */
#define OS_CORE_CMPU_STACK_REGION                       (11U)

/* INTC. */
#define OS_HAL_INTC_SUPPORT_CORE_NUM                    (4U)
#define OS_HAL_INTC0_BASE_ADDRESS                       (0xFC040000U)
#define OS_HAL_INTC1_BASE_ADDRESS                       (0xFC042000U)
#define OS_HAL_INTC_BASE_ADDRESS(coreId)                (((uint32)(coreId) < OS_HAL_INTC_SUPPORT_CORE_NUM) ? \
                                                        OS_HAL_INTC0_BASE_ADDRESS : OS_HAL_INTC1_BASE_ADDRESS)
#define OS_HAL_INTC_BCR_OFFSET                          (0x00000000U)
#define OS_HAL_INTC_MPROT_OFFSET                        (0x00000004U)
#define OS_HAL_INTC_CPR0_OFFSET                         (0x00000010U)
#define OS_HAL_INTC_CPR1_OFFSET                         (0x00000014U)
#define OS_HAL_INTC_CPR2_OFFSET                         (0x00000018U)
#define OS_HAL_INTC_CPR3_OFFSET                         (0x0000001CU)
#define OS_HAL_INTC_IACKR0_OFFSET                       (0x00000020U)
#define OS_HAL_INTC_IACKR1_OFFSET                       (0x00000024U)
#define OS_HAL_INTC_IACKR2_OFFSET                       (0x00000028U)
#define OS_HAL_INTC_IACKR3_OFFSET                       (0x0000002CU)
#define OS_HAL_INTC_EOIR0_OFFSET                        (0x00000030U)
#define OS_HAL_INTC_EOIR1_OFFSET                        (0x00000034U)
#define OS_HAL_INTC_EOIR2_OFFSET                        (0x00000038U)
#define OS_HAL_INTC_EOIR3_OFFSET                        (0x0000003CU)
#define OS_HAL_INTC_PSR_OFFSET(n)                       (0x00000060U + ((n) << 1U))
#define OS_HAL_INTC_SSCIR(n)                            (0x00000040U + (n))

#define OS_HAL_CPR_OFFSET(coreId)                       (((uint32)(coreId) < OS_HAL_INTC_SUPPORT_CORE_NUM) ? \
                                                        (OS_HAL_INTC_CPR0_OFFSET + ((uint32)(coreId) << 2U)) : \
                                                        (OS_HAL_INTC_CPR0_OFFSET + ((uint32)(coreId - OS_HAL_INTC_SUPPORT_CORE_NUM) << 2U)))

#define OS_HAL_IACKR_OFFSET(coreId)                     (((uint32)(coreId) < OS_HAL_INTC_SUPPORT_CORE_NUM) ? \
                                                        (OS_HAL_INTC_IACKR0_OFFSET + ((uint32)(coreId) << 2U)) : \
                                                        (OS_HAL_INTC_IACKR0_OFFSET + ((uint32)(coreId - OS_HAL_INTC_SUPPORT_CORE_NUM) << 2U)))

#define OS_CAT1_MASKLEVE                                (0x80U)
#define OS_CAT2_MASKLEVE                                (0x40U)

/* Software interrupts numbers. */
#define OS_HAL_INTC_SOFT_INTERRUPTS_NUM                 (32U)
/* Mask to trigger software Interrupt by SSCRI. */
#define OS_HAL_INTC_SSCIR_TRIGGER_MSK                   (0x02U)
/* Mask to trigger software Interrupt by PSR. */
#define OS_HAL_INTC_PSR_TRIGGER_MSK                     (0x0100U)
/* Mask to acknowledge software Interrupt. */
#define OS_HAL_INTC_SSCIR_ACK_MSK                       (0x01U)

/* Semaphores2. */
/* Semaphores2 base address. */
#define OS_HAL_SEMA4_BASE_ADDRESS                       (0xFC03C000U)
/* Semaphores2 gate address. */
#define OS_HAL_SEMA4_GATE_ADDRESS(gateId)               (OS_HAL_SEMA4_BASE_ADDRESS + (gateId))
/* The gate is unlocked. */
#define OS_HAL_SEMA4_GATE_FREE                          (0U)
/* The gate lock value. */
#define OS_HAL_SEMA4_GATE_LOCK(coreId)                  ((uint8)(coreId) + 1U)

/* PIT Timer. */
/* PIT_0 Base address. */
#define OS_HAL_PIT0_BASE_ADDRESS                        (0xFFF84000U)
/* PIT_1 Base address. */
#define OS_HAL_PIT1_BASE_ADDRESS                        (0xFFF80000U)
#define OS_HAL_PIT_MCR_OFFSET                           (0x00000000U)
#define OS_HAL_PIT_LDVAL_OFFSET(n)                      (0x0100U + ((n) << 4U))
#define OS_HAL_PIT_CVAL_OFFSET(n)                       (0x0104U + ((n) << 4U))
#define OS_HAL_PIT_TCTRL_OFFSET(n)                      (0x0108U + ((n) << 4U))
#define OS_HAL_PIT_TFLG_OFFSET(n)                       (0x010CU + ((n) << 4U))

/* STM Timer. */
#define OS_HAL_STM0_BASE_ADDRESS                        (0xFC068000U)
#define OS_HAL_STM1_BASE_ADDRESS                        (0xFC06C000U)
#define OS_HAL_STM2_BASE_ADDRESS                        (0xFC070000U)
#define OS_HAL_STM3_BASE_ADDRESS                        (0xFC074000U)
#define OS_HAL_STM4_BASE_ADDRESS                        (0xFC078000U)
#define OS_HAL_STM5_BASE_ADDRESS                        (0xFC07C000U)
#define OS_HAL_STM_CR_OFFSET                            (0x00000000U)
#define OS_HAL_STM_CNT_OFFSET                           (0x00000004U)
#define OS_HAL_STM_CCR_OFFSET(n)                        (0x0010U + ((n) << 4U))
#define OS_HAL_STM_CIR_OFFSET(n)                        (0x0014U + ((n) << 4U))
#define OS_HAL_STM_CMP_OFFSET(n)                        (0x0018U + ((n) << 4U))

/* SPR */
#define OS_HAL_SPR_XER      (1U)    /* Integer Exception Register. */
#define OS_HAL_SPR_LR       (8U)    /* Link Register. */
#define OS_HAL_SPR_CTR      (9U)    /* Count Register. */
#define OS_HAL_SPR_SRR0     (26U)   /* Save/Restore Register. */
#define OS_HAL_SPR_SRR1     (27U)   /* Save/Restore Register. */
#define OS_HAL_SPR_PID0     (48U)   /* Process ID Register. */
#define OS_HAL_SPR_CSRR0    (58U)   /* Critical Save/Restore Register 0. */
#define OS_HAL_SPR_CSRR1    (59U)   /* Critical Save/Restore Register 1. */
#define OS_HAL_SPR_DEAR     (61U)   /* Data Exception Address Register. */
#define OS_HAL_SPR_ESR      (62U)   /* Exception Syndrome Register. */
#define OS_HAL_SPR_IVPR     (63U)   /* Interrupt Vector Prefix Register. */
#define OS_HAL_SPR_SPRG0    (272U)  /* SPR General 0. */
#define OS_HAL_SPR_SPRG1    (273U)  /* SPR General 1. */
#define OS_HAL_SPR_SPRG2    (274U)  /* SPR General 2. */
#define OS_HAL_SPR_SPRG3    (275U)  /* SPR General 3. */
#define OS_HAL_SPR_PIR      (286U)  /* Processor ID Register. */
#define OS_HAL_SPR_PVR      (287U)  /* Processor Version Register. */
#define OS_HAL_SPR_DBSR     (304U)  /* Debug Status Register. */
#define OS_HAL_SPR_DBCR0    (308U)  /* Debug Control Register 0. */
#define OS_HAL_SPR_DBCR1    (309U)  /* Debug Control Register 1. */
#define OS_HAL_SPR_DBCR2    (310U)  /* Debug Control Register 2. */
#define OS_HAL_SPR_IAC1     (312U)  /* Instruction Address Compare 1. */
#define OS_HAL_SPR_IAC2     (313U)  /* Instruction Address Compare 2. */
#define OS_HAL_SPR_IAC3     (314U)  /* Instruction Address Compare 3. */
#define OS_HAL_SPR_IAC4     (315U)  /* Instruction Address Compare 4. */
#define OS_HAL_SPR_DAC1     (316U)  /* Data Address Compare 1. */
#define OS_HAL_SPR_DAC2     (317U)  /* Data Address Compare 2. */
#define OS_HAL_SPR_DVC1     (318U)  /* Data Value Compare 1. */
#define OS_HAL_SPR_DVC2     (319U)  /* Data Value Compare 2. */
#define OS_HAL_SPR_SPEFSCR  (512U)  /* LSP/EFP APU status and control register. */
#define OS_HAL_SPR_L1CFG0   (515U)  /* L1 cache config register 0. */
#define OS_HAL_SPR_L1CFG1   (516U)  /* L1 cache config register 1. */
#define OS_HAL_SPR_NPIDR    (517U)  /* Nexus 3 Process ID register. */
#define OS_HAL_SPR_DBCR3    (561U)  /* Debug control register. */
#define OS_HAL_SPR_DBCNT    (562U)  /* Debug Counter register. */
#define OS_HAL_SPR_DBCR4    (563U)  /* Debug control register. */
#define OS_HAL_SPR_DBCR5    (564U)  /* Debug control register. */
#define OS_HAL_SPR_IAC5     (565U)  /* Instruction Address Compare. */
#define OS_HAL_SPR_IAC6     (566U)  /* Instruction Address Compare. */
#define OS_HAL_SPR_IAC7     (567U)  /* Instruction Address Compare. */
#define OS_HAL_SPR_IAC8     (568U)  /* Instruction Address Compare. */
#define OS_HAL_SPR_MCSRR0   (570U)  /* Machine Check Save/Restore Register. */
#define OS_HAL_SPR_MCSRR1   (571U)  /* Machine Check Save/Restore Register. */
#define OS_HAL_SPR_MCSR     (572U)  /* Machine Check Syndrome Register Read. */
#define OS_HAL_SPR_MCAR     (573U)  /* Machine Check Address Register. */
#define OS_HAL_SPR_DSRR0    (574U)  /* Debug save/restore register 0. */
#define OS_HAL_SPR_DSRR1    (575U)  /* Debug save/restore register 1. */
#define OS_HAL_SPR_DDAM     (576U)  /* Debug Data Acquisition Messaging register. */
#define OS_HAL_SPR_DAC3     (592U)  /* Data Address Compare. */
#define OS_HAL_SPR_DAC4     (593U)  /* Data Address Compare. */
#define OS_HAL_SPR_DBCR7    (596U)  /* Debug control register. */
#define OS_HAL_SPR_DBCR8    (597U)  /* Debug control register. */
#define OS_HAL_SPR_DDEAR    (600U)  /* Debug Data Effective Address register. */
#define OS_HAL_SPR_DVC1U4   (601U)  /* Data Value Compare 1 Upper. */
#define OS_HAL_SPR_DVC2U4   (602U)  /* Data Value Compare 2 Upper. */
#define OS_HAL_SPR_DBCR6    (603U)  /* Debug control register. */
#define OS_HAL_SPR_MAS0     (624U)  /* MPU assist register 0. */
#define OS_HAL_SPR_MAS1     (625U)  /* MPU assist register 1. */
#define OS_HAL_SPR_MAS2     (626U)  /* MPU assist register 2. */
#define OS_HAL_SPR_MAS3     (627U)  /* MPU assist register 3. */
#define OS_HAL_SPR_EDBRAC0  (638U)  /* External debug resource allocation control register. */
#define OS_HAL_SPR_MPU0CFG  (692U)  /* MPU0 configuration register. */
#define OS_HAL_SPR_L1FINV1  (959U)  /* L1 cache flush and invalidate control register. */
#define OS_HAL_SPR_DEVENT   (975U)  /* Debug Event register. */
#define OS_HAL_SPR_HID0     (1008U) /* Hardware implementation dependent reg 0. */
#define OS_HAL_SPR_HID1     (1009U) /* Hardware implementation dependent reg 1. */
#define OS_HAL_SPR_L1CSR0   (1010U) /* L1 cache control and status register 0. */
#define OS_HAL_SPR_L1CSR1   (1011U) /* L1 cache control and status register 1. */
#define OS_HAL_SPR_BUCSR    (1013U) /* Branch Unit Control and Status Register. */
#define OS_HAL_SPR_MPU0CSR0 (1014U) /* MPU0 configuration register. */
#define OS_HAL_SPR_MMUCFG   (1015U) /* MMU/MPU configuration register. */
#define OS_HAL_SPR_L1FINV0  (1016U) /* L1 cache flush and invalidate control register 0. */
#define OS_HAL_SPR_SVR      (1023U) /* System Version Register. .*/

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"

#ifdef __ghs__
extern FUNC(unsigned int, OS_CODE) __GETSR(void);
extern FUNC(void, OS_CODE) __MTSPR(unsigned int spr, unsigned int val);
extern FUNC(unsigned int, OS_CODE) __MFSPR(unsigned int spr);
extern FUNC(unsigned int, OS_CODE) __CLZ32(unsigned int a);
extern FUNC(void, OS_CODE) __SETREG(unsigned int reg, unsigned int value);
extern FUNC(unsigned int, OS_CODE) __LWDCBX(const unsigned int *, unsigned long);
extern FUNC(void, OS_CODE) __STWDCBX(unsigned int*, unsigned long, unsigned int);
#endif /* __ghs__ */

#if( OS_CFG_COUNT_LEAD_ZEROS_HARDWARE == STD_ON )
/*
********************************************************************************
* Function Name: Os_Arch_CntLeadZeros
*
* Explanation: Count leading zeros.
*
* Param: sdata: Value to calculate.
*
* Retval: Value of Calculated.
********************************************************************************
*/
LOCAL_INLINE FUNC(uint32, OS_CODE) Os_Arch_CntLeadZeros(uint32 sdata)
{
    uint32 result = OS_NAUGHT_VALUE;

    result = __CLZ32(sdata);

    return result;
}
#endif /* OS_CFG_COUNT_LEAD_ZEROS_HARDWARE == STD_ON */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_ARCH_MACH_CCFC3012_H_ */
