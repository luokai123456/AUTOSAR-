/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC
*   Peripheral           : Mcu
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    Mcu_LLDriver.h
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Mcu MCAL driver.
*
*   @addtogroup Mcu
*   @{
*/
/* PRQA S 0779 EOF */
#ifndef MCU_LLDRIVER_H
#define MCU_LLDRIVER_H


#ifdef __cplusplus
extern "C"{
#endif


#include "Mcu.h"
#include "derivative.h"
#include "status.h"

/*====================================================================================================
HEAD FILE VERSION INFORMATION
====================================================================================================*/
#define MCU_LLD_VENDOR_ID                     176
#define MCU_LLD_AR_MAJOR_VER                  4
#define MCU_LLD_AR_MINOR_VER                  4
#define MCU_LLD_AR_PATCH_VER                  0
#define MCU_LLD_SW_MAJOR_VER                  3
#define MCU_LLD_SW_MINOR_VER                  0
#define MCU_LLD_SW_PATCH_VER                  0
/*====================================================================================================
FILE VERSION CHECKS
====================================================================================================*/
/* Check if current file and MCU header file are of the same vendor */
#if (MCU_VENDOR_ID != MCU_LLD_VENDOR_ID)
#error "NON-MATCHED DATA : MCU_LLD_VENDOR_ID"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#if (MCU_AR_RELEASE_MAJOR_VERSION != MCU_LLD_AR_MAJOR_VER)
#error "NON-MATCHED DATA : MCU_LLD_AR_MAJOR_VER"
#endif
#if (MCU_AR_RELEASE_MINOR_VERSION != MCU_LLD_AR_MINOR_VER)
#error "NON-MATCHED DATA : MCU_LLD_AR_MINOR_VER"
#endif
#if (MCU_AR_PATCH_VER != MCU_LLD_AR_PATCH_VER)
#error "NON-MATCHED DATA : MCU_LLD_AR_PATCH_VER"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (MCU_SW_MAJOR_VER != MCU_LLD_SW_MAJOR_VER)
#error "NON-MATCHED DATA : MCU_LLD_SW_MAJOR_VER"
#endif
#if (MCU_SW_MINOR_VER != MCU_LLD_SW_MINOR_VER)
#error "NON-MATCHED DATA : MCU_LLD_SW_MINOR_VER"
#endif
#if (MCU_SW_PATCH_VER != MCU_LLD_SW_PATCH_VER)
#error "NON-MATCHED DATA : MCU_LLD_SW_PATCH_VER"
#endif

#define E_UNSUPPORTED                    ((uint8)0x10U)    /*!< Generic operation unsupported status */
#define FCCU_ERROR_CONFIG_TIMEOUT        ((uint8)0x21U) /*!< FCCU triggers TimeOut when try to enter in Config State */
#define FCCU_ERROR_INIT_FCCU             ((uint8)0x22U) /*!< FCCU Initializing FCCU Module */
#define FCCU_ERROR_SET_CONFIG            ((uint8)0x23U) /*!< FCCU Fail to Enter in Config Mode  */
#define FCCU_ERROR_SET_NORMAL            ((uint8)0x24U) /*!< FCCU Fail to Enter in Normal Mode  */
#define FCCU_ERROR_APPLY_NCF_CONFIG      ((uint8)0x25U) /*!< FCCU Fail to set NoCritical Faults  */
#define FCCU_ERROR_UPDATE_FREEZE         ((uint8)0x26U) /*!< FCCU Fail to update Freez Status registers */
#define FCCU_ERROR_CLEAR_FREEZE          ((uint8)0x27U) /*!< FCCU Fail to Clear Freez Status registers */
#define FCCU_ERROR_SET_EOUT              ((uint8)0x28U) /*!< FCCU Fail to Set Eout Configuration */
#define FCCU_ERROR_FAULT_DETECTED        ((uint8)0x29U) /*!< FCCU Faults Detected */
#define FCCU_ERROR_OTHER                 ((uint8)0x2AU) /*!< FCCU other Error */

/****************************************************************************/

typedef  struct MC_ME_tag                    MC_ME_Type;
typedef  struct IRCOSC_tag                   IRCOSC_Type;
typedef  struct XOSC_tag                     XOSC_Type;
typedef  struct PLLDIG_tag                   PLLDIG_Type;
typedef  struct MC_CGM_tag                   MC_CGM_Type;
typedef  struct CMU_tag                      CMU_Type;


/* MC_CGM - Peripheral instance pMcu_Base addresses */
/** Peripheral MC_CGM pMcu_Base address */
#define MC_ME_BASE                              ((uint32)0xFFFB8000UL)
/** Peripheral MC_CGM pMcu_Base pointer */
#define MC_ME_StPtr                             ((MC_ME_Type *) MC_ME_BASE)
/** Array initializer of MC_CGM peripheral pMcu_Base addresses */
#define MC_ME_BASE_ADDRS                        { MC_ME_BASE }
/** Array initializer of MC_CGM peripheral pMcu_Base pointers */
#define MC_ME_BASE_PTRS                         { MC_ME_StPtr }


#define MCU_PLLCR_CFG_MASK                       ((uint32)0x3UL)
/* IRCOSC - Peripheral instance pMcu_Base addresses */
/** Peripheral IRCOSC pMcu_Base address */
#define IRCOSC_BASE                              (0xFFFB0000UL)
/** Peripheral IRCOSC pMcu_Base pointer */
#define IRCOSC_StPtr                             ((IRCOSC_Type *)IRCOSC_BASE)
/** Array initializer of IRCOSC peripheral pMcu_Base addresses */
#define IRCOSC_BASE_ADDRS                        { IRCOSC_BASE }
/** Array initializer of IRCOSC peripheral pMcu_Base pointers */
#define IRCOSC_BASE_PTRS                         { IRCOSC_StPtr }

/* XOSC - Peripheral instance pMcu_Base addresses */
/** Peripheral XOSC pMcu_Base address */
#define XOSC_BASE                                (0xFFFB0080UL)
/** Peripheral XOSC pMcu_Base pointer */
#define XOSC_StPtr                               ((XOSC_Type *)XOSC_BASE)
/** Array initializer of XOSC peripheral pMcu_Base addresses */
#define XOSC_BASE_ADDRS                          { XOSC_BASE }
/** Array initializer of XOSC peripheral pMcu_Base pointers */
#define XOSC_BASE_PTRS                           { XOSC_StPtr }

/* PLLDIG - Peripheral instance pMcu_Base addresses */
/** Peripheral PLLDIG pMcu_Base address */
#define PLLDIG_BASE                              (0xFFFB0100UL)
/** Peripheral PLLDIG pMcu_Base pointer */
#define PLLDIG_StPtr                             ((PLLDIG_Type *)PLLDIG_BASE)
/** Array initializer of PLLDIG peripheral pMcu_Base addresses */
#define PLLDIG_BASE_ADDRS                        { PLLDIG_BASE }
/** Array initializer of PLLDIG peripheral pMcu_Base pointers */
#define PLLDIG_BASE_PTRS                         { PLLDIG_StPtr }


/* MC_CGM - Peripheral instance pMcu_Base addresses */
/** Peripheral MC_CGM pMcu_Base address */
#define MC_CGM_BASE                              (0xFFFB0000UL)
/** Peripheral MC_CGM pMcu_Base pointer */
#define MC_CGM_StPtr                             ((MC_CGM_Type *)MC_CGM_BASE)
/** Array initializer of MC_CGM peripheral pMcu_Base addresses */
#define MC_CGM_BASE_ADDRS                        { MC_CGM_BASE }
/** Array initializer of MC_CGM peripheral pMcu_Base pointers */
#define MC_CGM_BASE_PTRS                         { MC_CGM_StPtr }


/* SEMA42 - Peripheral instance pMcu_Base addresses */
/** Peripheral SEMA42 pMcu_Base address */
#define SEMA42_BASE                              (0xFC03C000UL)
/** Peripheral SEMA42 pMcu_Base pointer */
#define SEMA42_StPtr                             ((SEMA42_Type *)SEMA42_BASE)
/** Array initializer of SEMA42 peripheral pMcu_Base addresses */
#define SEMA42_BASE_ADDRS                        { SEMA42_BASE }
/** Array initializer of SEMA42 peripheral pMcu_Base pointers */
#define SEMA42_BASE_PTRS                         { SEMA42_StPtr }


/* PLL0CR Bit Fields */
#define PLLDIG_PLL0CR_CLKCFG_MASK                0x300u
#define PLLDIG_PLL0CR_CLKCFG_SHIFT               8u
#define PLLDIG_PLL0CR_CLKCFG_WIDTH               2u
#define PLLDIG_PLL0CR_CLKCFG(x)                  (((uint32)(((uint32)(x)) \
                                                  <<PLLDIG_PLL0CR_CLKCFG_SHIFT)) \
                                                  &PLLDIG_PLL0CR_CLKCFG_MASK)

/* PLL1CR Bit Fields */
#define PLLDIG_PLL1CR_CLKCFG_MASK                0x300u
#define PLLDIG_PLL1CR_CLKCFG_SHIFT               8u
#define PLLDIG_PLL1CR_CLKCFG_WIDTH               2u
#define PLLDIG_PLL1CR_CLKCFG(x)                  (((uint32)(((uint32)(x)) \
                                                  <<PLLDIG_PLL1CR_CLKCFG_SHIFT)) \
                                                  &PLLDIG_PLL1CR_CLKCFG_MASK)

/*!
 * @brief CGM auxiliary clock selector.
 * Implements Mcu_CgmClkSelType_Class
 */

#define CGM_SOURCE_SEL_IRCOSC           0U
#define CGM_SOURCE_SEL_XOSC             1U
#define CGM_SOURCE_SEL_PLL0_PHI0        2U
#define CGM_SOURCE_SEL_PLL1_PHI0        4U

/* @brief LFAST_SYS_PIN source selector.
   0U -  No LFAST module */
#define CGM_LFASTx_SOURCE_SYS_PIN                5U
#define CGM_LFASTx_SOURCE_LFAST_REF              5U

/* MC_ME index offsets */
#define MC_ME_RUN_PC0_INDEX                      0
#define MC_ME_RUN_PC1_INDEX                      1
#define MC_ME_RUN_PC2_INDEX                      2
#define MC_ME_RUN_PC3_INDEX                      3
#define MC_ME_RUN_PC4_INDEX                      4
#define MC_ME_RUN_PC5_INDEX                      5
#define MC_ME_RUN_PC6_INDEX                      6
#define MC_ME_RUN_PC7_INDEX                      7
#define MC_ME_LP_PC0_INDEX                       0
#define MC_ME_LP_PC1_INDEX                       1
#define MC_ME_LP_PC2_INDEX                       2
#define MC_ME_LP_PC3_INDEX                       3
#define MC_ME_LP_PC4_INDEX                       4
#define MC_ME_LP_PC5_INDEX                       5
#define MC_ME_LP_PC6_INDEX                       6
#define MC_ME_LP_PC7_INDEX                       7


#define PRAMC_PRCR1_PRI_MASK32                    ((uint32)0x00000300U)

#define PRAMC_PRCR1_P1_BO_DIS                     ((uint32)0x00000080U)
#define PRAMC_PRCR1_P1_BO_ENA                     ((uint32)0x00000000U)

#define PRAMC_PRCR1_P0_BO_DIS                     ((uint32)0x00000040U)
#define PRAMC_PRCR1_P0_BO_ENA                     ((uint32)0x00000000U)

#define PRAMC_PRCR1_P1_RB_DIS                     ((uint32)0x00000020U)
#define PRAMC_PRCR1_P1_RB_ENA                     ((uint32)0x00000000U)

#define PRAMC_PRCR1_P0_RB_DIS                     ((uint32)0x00000010U)
#define PRAMC_PRCR1_P0_RB_ENA                     ((uint32)0x00000000U)

#define PRAMC_PRCR1_FT_DIS                        ((uint32)0x00000001U)
#define PRAMC_PRCR1_FT_ENA                        ((uint32)0x00000000U)

/** MC_ME - Size of Registers Arrays */
#define MC_ME_INVALID_INDEX                      MC_ME_PCTLn_COUNT

/* MCTL Bit Fields */
#define MC_ME_MCTL_KEY_MASK                      0xFFFFu
#define MC_ME_MCTL_KEY_SHIFT                     0u
#define MC_ME_MCTL_KEY_WIDTH                     16u
#define MC_ME_MCTL_KEY(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_MCTL_KEY_SHIFT)) \
                                                  &MC_ME_MCTL_KEY_MASK)
#define MC_ME_MCTL_TARGET_MODE_MASK              0xF0000000u
#define MC_ME_MCTL_TARGET_MODE_SHIFT             28u
#define MC_ME_MCTL_TARGET_MODE_WIDTH             4u
#define MC_ME_MCTL_TARGET_MODE(x)                (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_MCTL_TARGET_MODE_SHIFT)) \
                                                  &MC_ME_MCTL_TARGET_MODE_MASK)

/* PCTLn Bit Fields */
#define MC_ME_PCTLn_RUN_CFG_MASK                 0x7u
#define MC_ME_PCTLn_RUN_CFG_SHIFT                0u
#define MC_ME_PCTLn_RUN_CFG_WIDTH                3u
#define MC_ME_PCTLn_RUN_CFG(x)                   (((uint8)(((uint8)(x)) \
                                                  <<MC_ME_PCTLn_RUN_CFG_SHIFT)) \
                                                  &MC_ME_PCTLn_RUN_CFG_MASK)
#define MC_ME_PCTLn_LP_CFG_MASK                  0x38u
#define MC_ME_PCTLn_LP_CFG_SHIFT                 3u
#define MC_ME_PCTLn_LP_CFG_WIDTH                 3u
#define MC_ME_PCTLn_LP_CFG(x)                    (((uint8)(((uint8)(x)) \
                                                  <<MC_ME_PCTLn_LP_CFG_SHIFT)) \
                                                  &MC_ME_PCTLn_LP_CFG_MASK)




/* GS Bit Fields */
#define MC_ME_GS_S_SYSCLK_MASK                   0xFu
#define MC_ME_GS_S_SYSCLK_SHIFT                  0u
#define MC_ME_GS_S_SYSCLK_WIDTH                  4u
#define MC_ME_GS_S_SYSCLK(x)                     (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_GS_S_SYSCLK_SHIFT)) \
                                                  &MC_ME_GS_S_SYSCLK_MASK)
#define MC_ME_GS_S_IRC_MASK                      0x10u
#define MC_ME_GS_S_IRC_SHIFT                     4u
#define MC_ME_GS_S_IRC_WIDTH                     1u
#define MC_ME_GS_S_IRC(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_GS_S_IRC_SHIFT)) \
                                                  &MC_ME_GS_S_IRC_MASK)
#define MC_ME_GS_S_XOSC_MASK                     0x20u
#define MC_ME_GS_S_XOSC_SHIFT                    5u
#define MC_ME_GS_S_XOSC_WIDTH                    1u
#define MC_ME_GS_S_XOSC(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_GS_S_XOSC_SHIFT)) \
                                                  &MC_ME_GS_S_XOSC_MASK)
#define MC_ME_GS_S_PLL0_MASK                     0x40u
#define MC_ME_GS_S_PLL0_SHIFT                    6u
#define MC_ME_GS_S_PLL0_WIDTH                    1u
#define MC_ME_GS_S_PLL0(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_GS_S_PLL0_SHIFT)) \
                                                  &MC_ME_GS_S_PLL0_MASK)
#define MC_ME_GS_S_PLL1_MASK                     0x80u
#define MC_ME_GS_S_PLL1_SHIFT                    7u
#define MC_ME_GS_S_PLL1_WIDTH                    1u
#define MC_ME_GS_S_PLL1(x)                       (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_GS_S_PLL1_SHIFT)) \
                                                  &MC_ME_GS_S_PLL1_MASK)

/* ME Bit Fields */
#define MC_ME_ME_RESET_FUNC_MASK                 0x1u
#define MC_ME_ME_RESET_FUNC_SHIFT                0u
#define MC_ME_ME_RESET_FUNC_WIDTH                1u
#define MC_ME_ME_RESET_FUNC(x)                   (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_ME_RESET_FUNC_SHIFT)) \
                                                  &MC_ME_ME_RESET_FUNC_MASK)
#define MC_ME_ME_TEST_MASK                       0x2u
#define MC_ME_ME_TEST_SHIFT                      1u
#define MC_ME_ME_TEST_WIDTH                      1u
#define MC_ME_ME_TEST(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_ME_TEST_SHIFT)) \
                                                  &MC_ME_ME_TEST_MASK)
#define MC_ME_ME_SAFE_MASK                       0x4u
#define MC_ME_ME_SAFE_SHIFT                      2u
#define MC_ME_ME_SAFE_WIDTH                      1u
#define MC_ME_ME_SAFE(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_ME_SAFE_SHIFT)) \
                                                  &MC_ME_ME_SAFE_MASK)
#define MC_ME_ME_DRUN_MASK                       0x8u
#define MC_ME_ME_DRUN_SHIFT                      3u
#define MC_ME_ME_DRUN_WIDTH                      1u
#define MC_ME_ME_DRUN(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_ME_DRUN_SHIFT)) \
                                                  &MC_ME_ME_DRUN_MASK)
#define MC_ME_ME_RUN0_MASK                       0x10u
#define MC_ME_ME_RUN0_SHIFT                      4u
#define MC_ME_ME_RUN0_WIDTH                      1u
#define MC_ME_ME_RUN0(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_ME_RUN0_SHIFT)) \
                                                  &MC_ME_ME_RUN0_MASK)
#define MC_ME_ME_RUN1_MASK                       0x20u
#define MC_ME_ME_RUN1_SHIFT                      5u
#define MC_ME_ME_RUN1_WIDTH                      1u
#define MC_ME_ME_RUN1(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_ME_RUN1_SHIFT)) \
                                                  &MC_ME_ME_RUN1_MASK)
#define MC_ME_ME_RUN2_MASK                       0x40u
#define MC_ME_ME_RUN2_SHIFT                      6u
#define MC_ME_ME_RUN2_WIDTH                      1u
#define MC_ME_ME_RUN2(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_ME_RUN2_SHIFT)) \
                                                  &MC_ME_ME_RUN2_MASK)
#define MC_ME_ME_RUN3_MASK                       0x80u
#define MC_ME_ME_RUN3_SHIFT                      7u
#define MC_ME_ME_RUN3_WIDTH                      1u
#define MC_ME_ME_RUN3(x)                         (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_ME_RUN3_SHIFT)) \
                                                  &MC_ME_ME_RUN3_MASK)

#define MC_ME_ME_HALT0_MASK                      0x100u
#define MC_ME_ME_HALT0_SHIFT                     8u
#define MC_ME_ME_HALT0_WIDTH                     1u
#define MC_ME_ME_HALT0(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_ME_HALT0_SHIFT)) \
                                                  &MC_ME_ME_HALT0_MASK)
#define MC_ME_ME_STOP0_MASK                      0x400u
#define MC_ME_ME_STOP0_SHIFT                     10u
#define MC_ME_ME_STOP0_WIDTH                     1u
#define MC_ME_ME_STOP0(x)                        (((uint32)(((uint32)(x)) \
                                                  <<MC_ME_ME_STOP0_SHIFT)) \
                                                  &MC_ME_ME_STOP0_MASK)
#if MCU_HARDVER != 3
#define MC_ME_ME_STANDBY_MASK                      0x2000u
#define MC_ME_ME_STANDBY_SHIFT                     13u
#define MC_ME_ME_STANDBY_WIDTH                     1u
#define MC_ME_ME_STANDBY(x)                        (((uint32)(((uint32)(x)) \
                                                   <<MC_ME_ME_STANDBY_SHIFT)) \
                                                   &MC_ME_ME_STANDBY_MASK)
#endif
/********************************************************/
/*          Core Control Register (ME_CCTLn)            */
/********************************************************/

#define MC_ME_CCTL_RWBITS_MASK16                ((uint16)0x00FEU)

#define MC_ME_CCTL_RUN3_MASK16                      ((uint16)0x0080U)
#define MC_ME_CCTL_RUN2_MASK16                      ((uint16)0x0040U)
#define MC_ME_CCTL_RUN1_MASK16                      ((uint16)0x0020U)
#define MC_ME_CCTL_RUN0_MASK16                      ((uint16)0x0010U)
#define MC_ME_CCTL_DRUN_MASK16                      ((uint16)0x0008U)
#define MC_ME_CCTL_SAFE_MASK16                      ((uint16)0x0004U)
#define MC_ME_CCTL_TEST_MASK16                      ((uint16)0x0002U)

#define MC_ME_CADDR_ADDR_MASK32                     ((uint32)0xFFFFFFFCU)
#define MC_ME_CADDR_RMC_MASK32                      ((uint32)0x00000001U)

#define MC_ME_CADDR_RESET_ENABLE                    (MC_ME_CADDR_RMC_MASK32)
#define MC_ME_CADDR_RESET_DISABLE                   ((uint32)0x00000000U)

#define MC_ME_CCTL_RUN3_ON                          (MC_ME_CCTL_RUN3_MASK16)
#define MC_ME_CCTL_RUN3_OFF                         ((uint16)0x0000)
        
#define MC_ME_CCTL_RUN2_ON                          (MC_ME_CCTL_RUN2_MASK16)
#define MC_ME_CCTL_RUN2_OFF                         ((uint16)0x0000)
        
#define MC_ME_CCTL_RUN1_ON                          (MC_ME_CCTL_RUN1_MASK16)
#define MC_ME_CCTL_RUN1_OFF                         ((uint16)0x0000)
        
#define MC_ME_CCTL_RUN0_ON                          (MC_ME_CCTL_RUN0_MASK16)
#define MC_ME_CCTL_RUN0_OFF                         ((uint16)0x0000)
        
#define MC_ME_CCTL_DRUN_ON                          (MC_ME_CCTL_DRUN_MASK16)
#define MC_ME_CCTL_DRUN_OFF                         ((uint16)0x0000)
        
#define MC_ME_CCTL_SAFE_ON                          (MC_ME_CCTL_SAFE_MASK16)
#define MC_ME_CCTL_SAFE_OFF                         ((uint16)0x0000)
        
#define MC_ME_CCTL_TEST_ON                          (MC_ME_CCTL_TEST_MASK16)
#define MC_ME_CCTL_TEST_OFF                         ((uint16)0x0000)


/* MC_CGM - Peripheral instance pMcu_Base addresses */
/** Peripheral MC_CGM pMcu_Base address */
#define CMU_PLL_BASE                             (0xFFFB0200u)
#define CMU_FXBAR_BASE                           (0xFBFB0200u)
#define CMU_SXBAR_BASE                           (0xFBFB0240u)
#define CMU_PBRIDGE_BASE                         (0xFBFB0280u)
#define CMU_PER_BASE                             (0xFBFB02C0u)
#define CMU_ADCSD_BASE                           (0xFBFB0300u)
#define CMU_ADCSAR_BASE                          (0xFBFB0340u)
#define CMU_SENT_BASE                            (0xFBFB0380u)
#define CMU_PSI5_F189_BASE                       (0xFBFB03C0u)
#define CMU_PSI5_F125_BASE                       (0xFBFB0400u)
#define CMU_PSI5_1uS_BASE                        (0xFBFB0440u)
#define CMU_CORE_BASE                            (0xFBFB0480u)
#define CMU_CLKOUT_BASE                          (0xFBFB04C0u)
/** Peripheral MC_CGM pMcu_Base pointer */
#define CMU_0                                    ((CMU_Type *)CMU_PLL_BASE)
#define CMU_1                                    ((CMU_Type *)CMU_FXBAR_BASE)
#define CMU_2                                    ((CMU_Type *)CMU_SXBAR_BASE)
#define CMU_3                                    ((CMU_Type *)CMU_PBRIDGE_BASE)
#define CMU_4                                    ((CMU_Type *)CMU_PER_BASE)
#define CMU_5                                    ((CMU_Type *)CMU_ADCSD_BASE)
#define CMU_6                                    ((CMU_Type *)CMU_ADCSAR_BASE)
#define CMU_7                                    ((CMU_Type *)CMU_SENT_BASE)
#define CMU_8                                    ((CMU_Type *)CMU_PSI5_F189_BASE)
#define CMU_9                                    ((CMU_Type *)CMU_PSI5_F125_BASE)
#define CMU_10                                   ((CMU_Type *)CMU_PSI5_1uS_BASE)
#define CMU_11                                   ((CMU_Type *)CMU_CORE_BASE)
#define CMU_12                                   ((CMU_Type *)CMU_CLKOUT_BASE)

#define FIRST_CMU                                CMU_0
#define FEATURE_HAS_RCDIV                        0
#define CMU_BASE_PTRS                            {CMU_0, CMU_1, CMU_2, CMU_3, CMU_4, CMU_5, CMU_6, \
                                                  CMU_7, CMU_8 ,CMU_9, CMU_10, CMU_11 , CMU_12 }
#define CMU_RESET_DIVIDER_VALUE                  0x03

#define CMU_ISR_OLRI_MASK                        0x1u
#define CMU_ISR_FLLI_MASK                        0x2u
#define CMU_ISR_FHHI_MASK                        0x4u
#define RGM_DES_RWBITS_MASK32                    ((uint32)0x0180C73BU)
#define RGM_FES_RWBITS_MASK32                    ((uint32)0x0180846FU)



#define PLLDIG_PHI_DIV_DISABLE    64U

/*!
 * @brief CGM auxiliary clock selector.
 * Implements Mcu_CgmSysClkSrcType_Class
 */

#define CGM_SYSTEM_CLOCK_SRC_IRCOSC     0U       /*!< IRCOSC. */
#define CGM_SYSTEM_CLOCK_SRC_XOSC       1U       /*!< XOSC. */
#define CGM_SYSTEM_CLOCK_SRC_PLL_PHI0   2U       /*!< PLL PHI_0. */
#define CGM_SYSTEM_CLOCK_SRC_PLL0_PHI0  2U       /*!< Primary PLL PHI_0. */
#define CGM_SYSTEM_CLOCK_SRC_PLL0_PHI1  3U       /*  */
#define CGM_SYSTEM_CLOCK_SRC_PLL1_PHI0  4U       /*!< Secondary PLL1 PHI_0. */
#define CGM_SYSTEM_CLOCK_SRC_NONE       15U      /*!< NONE. */


/* RGM_DERD[D_PORST] field value. */
#define RGM_PORST_RESET                          ((uint32)0x00000000U)
#define RGM_PORST_SAFE_INT                       ((uint32)0x00000002U)
/* RGM_DEAR[AR_TSR_DEST] field value. */
#define RGM_PORST_ALT_EVENT_SAFE                 ((uint32)0x00000000U)
#define RGM_PORST_ALT_EVENT_ISR                  ((uint32)0x00000002U)
/* RGM_FERD[D_VOR_FUNC] - A voltage out of range functional reset event triggers an interrupt/Safe mode request. */
#define RGM_VOR_FUNC_EVENT_SAFE_INT              ((uint32)0x01000000U)
#define RGM_VOR_FUNC_EVENT_RESET                 ((uint32)0x00000000U)
/* RGM_FERD[D_TSR_FUNC] - A temperature sensor functional reset event triggers an interrupt/Safe mode request. */
#define RGM_TSR_FUNC_EVENT_SAFE_INT              ((uint32)0x00800000U)
#define RGM_TSR_FUNC_EVENT_RESET                 ((uint32)0x00000000U)
/* RGM_FERD[D_ESR1] - A voltage out of range functional reset event triggers an interrupt/Safe mode request. */
#define RGM_ESR1_EVENT_SAFE_INT                  ((uint32)0x00000002U)
#define RGM_ESR1_EVENT_RESET                     ((uint32)0x00000000U)
/* RGM_FEAR[AR_VOR_FUNC] - Generate an interrupt request if the reset is disabled. */
#define RGM_VOR_FUNC_EVENT_ISR                   ((uint32)0x01000000U)
#define RGM_VOR_FUNC_EVENT_SAFE                  ((uint32)0x00000000U)
/* RGM_FEAR[AR_TSR_FUNC] - Generate an interrupt request if the reset is disabled. */
#define RGM_TSR_FUNC_EVENT_ISR                   ((uint32)0x00800000U)
#define RGM_TSR_FUNC_EVENT_SAFE                  ((uint32)0x00000000U)
/* RGM_FEAR[AR_ESR1] - Generate an interrupt request if the reset is disabled. */
#define RGM_ESR1_EVENT_ISR                       ((uint32)0x00000002U)
#define RGM_ESR1_EVENT_SAFE                      ((uint32)0x00000000U)
/* RGM_FBRE[BE_VOR_FUNC] - RESET_B is not asserted if the reset is enabled. */
#define RGM_VOR_FUNC_EXT_RESET_B_DIS             ((uint32)0x01000000U)
#define RGM_VOR_FUNC_EXT_RESET_B_EN              ((uint32)0x00000000U)
/* RGM_FBRE[BE_TSR_FUNC] - RESET_B is not asserted if the reset is enabled. */
#define RGM_TSR_FUNC_EXT_RESET_B_DIS             ((uint32)0x00800000U)
#define RGM_TSR_FUNC_EXT_RESET_B_EN              ((uint32)0x00000000U)
#define RGM_HSM_FUNC_ASSERT_ESR0_DIS             ((uint32)0x00008000U)
#define RGM_HSM_FUNC_ASSERT_ESR0_EN              ((uint32)0x00000000U)
/* RGM_FBRE[BE_JTAG_OR_DBG] - Bidirectional Reset Enable for JTAG Functional reset */
#define RGM_JTAG_OR_DBG_RESET_B_DIS              ((uint32)0x00000400U)
#define RGM_JTAG_OR_DBG_RESET_B_EN               ((uint32)0x00000000U)
/* RGM_FBRE[BE_FCCU_SOFT] - RESET_B is not asserted if the reset is enabled. */
#define RGM_FCCU_SOFT_EXT_RESET_B_DIS            ((uint32)0x00000040U)
#define RGM_FCCU_SOFT_EXT_RESET_B_EN             ((uint32)0x00000000U)
/* RGM_FBRE[BE_FCCU_HARD] - RESET_B is not asserted if the reset is enabled. */
#define RGM_FCCU_HARD_EXT_RESET_B_DIS            ((uint32)0x00000020U)
#define RGM_FCCU_HARD_EXT_RESET_B_EN             ((uint32)0x00000000U)
/* RGM_FBRE[BE_SOFT_FUNC] - RESET_B is not asserted if the reset is enabled. */
#define RGM_SOFT_FUNC_EXT_RESET_B_DIS            ((uint32)0x00000008U)
#define RGM_SOFT_FUNC_EXT_RESET_B_EN             ((uint32)0x00000000U)
/* RGM_FBRE[BE_ESR1] - RESET_B is not asserted if the reset is enabled. */
#define RGM_ESR1_ASSERT_ESR0_DIS                 ((uint32)0x00000002U)
#define RGM_ESR1_ASSERT_ESR0_EN                  ((uint32)0x00000000U)
/********** RGM_FESS Register bits values **********/
/* RGM_FESS[SS_VOR_FUNC] - The reset sequence will start from PHASE3, skipping PHASE1 and PHASE2. */
#define RGM_VOR_FUNC_RESET_PHASE3                ((uint32)0x01000000U)
#define RGM_VOR_FUNC_RESET_PHASE1                ((uint32)0x00000000U)
/* RGM_FESS[SS_TSR_FUNC] - The reset sequence will start from PHASE3, skipping PHASE1 and PHASE2. */
#define RGM_TSR_FUNC_RESET_PHASE3                ((uint32)0x00800000U)
#define RGM_TSR_FUNC_RESET_PHASE1                ((uint32)0x00000000U)
/* RGM_FESS[SS_JTAG] - The reset sequence will start from PHASE3, skipping PHASE1 and PHASE2. */
#define RGM_JTAG_FUNC_RESET_PHASE3               ((uint32)0x00000400U)
#define RGM_JTAG_FUNC_RESET_PHASE1               ((uint32)0x00000000U)
/* RGM_FESS[SS_SOFT_FUNC] - The reset sequence will start from PHASE3, skipping PHASE1 and PHASE2. */
#define RGM_SOFT_FUNC_RESET_PHASE3               ((uint32)0x00000008U)
#define RGM_SOFT_FUNC_RESET_PHASE1               ((uint32)0x00000000U)
/* RGM_FESS[SS_SOFT_FUNC] - The reset sequence will start from PHASE3, skipping PHASE1 and PHASE2. */
#define RGM_ESR1_RESET_PHASE3                    ((uint32)0x00000002U)
#define RGM_ESR1_RESET_PHASE1                    ((uint32)0x00000000U)
/* RGM_FESS[SS_SOFT_FUNC] - The reset sequence will start from PHASE3, skipping PHASE1 and PHASE2. */
#define RGM_ESR0_RESET_PHASE3                    ((uint32)0x00000001U)
#define RGM_ESR0_RESET_PHASE1                    ((uint32)0x00000000U)


#define PMC_CTL_TD_TRIM_ADJ_OVER                ((uint32)0x00000F00U)
#define PMC_CTL_TD_TRIM_ADJ_UNDER               ((uint32)0x0000003CU)

#define PMC_IER_IE_EN_MASK32                    ((uint32)0x80000000U)
#define PMC_IER_VD15IE_A_ENA                    ((uint32)0x02000000U)
#define PMC_IER_VD15IE_C_ENA                    ((uint32)0x01000000U)
#define PMC_IER_VD14IE_A_ENA                    ((uint32)0x00400000U)
#define PMC_IER_VD14IE_IM_ENA                   ((uint32)0x00200000U)
#define PMC_IER_VD13IE_IM_ENA                   ((uint32)0x00040000U)
#define PMC_IER_VD12IE_F_ENA                    ((uint32)0x00020000U)
#define PMC_IER_VD10IE_A_ENA                    ((uint32)0x00010000U)
#define PMC_IER_VD10IE_F_ENA                    ((uint32)0x00008000U)
#define PMC_IER_VD9IE_O_ENA                     ((uint32)0x00004000U)
#define PMC_IER_VD9IE_O_H_ENA                   ((uint32)0x00002000U)
#define PMC_IER_VD9IE_IO_5V_H_ENA               ((uint32)0x00001000U)
#define PMC_IER_VD9IE_IO_5V_ENA                 ((uint32)0x00000800U)
#define PMC_IER_VD9IE_PMC_H_ENA                 ((uint32)0x00000100U)
#define PMC_IER_VD9IE_PMC_ENA                   ((uint32)0x00000080U)
#define PMC_IER_VD8IE_C_ENA                     ((uint32)0x00000040U)
#define PMC_IER_VD8IE_F_ENA                     ((uint32)0x00000020U)
#define PMC_IER_VD7IE_C_ENA                     ((uint32)0x00000010U)
#define PMC_IER_VD4IE_C_ENA                     ((uint32)0x00000008U)
#define PMC_IER_VD3IE_P_ENA                     ((uint32)0x00000004U)
#define PMC_IER_VD3IE_F_ENA                     ((uint32)0x00000002U)

#define PMC_IER_VD15IE_A_DIS                    ((uint32)0x00000000U)
#define PMC_IER_VD15IE_C_DIS                    ((uint32)0x00000000U)
#define PMC_IER_VD14IE_A_DIS                    ((uint32)0x00000000U)
#define PMC_IER_VD14IE_IM_DIS                   ((uint32)0x00000000U)
#define PMC_IER_VD13IE_IM_DIS                   ((uint32)0x00000000U)
#define PMC_IER_VD12IE_F_DIS                    ((uint32)0x00000000U)
#define PMC_IER_VD10IE_A_DIS                    ((uint32)0x00000000U)
#define PMC_IER_VD10IE_F_DIS                    ((uint32)0x00000000U)
#define PMC_IER_VD9IE_O_DIS                     ((uint32)0x00000000U)
#define PMC_IER_VD9IE_O_H_DIS                   ((uint32)0x00000000U)
#define PMC_IER_VD9IE_IO_5V_H_DIS               ((uint32)0x00000000U)
#define PMC_IER_VD9IE_IO_5V_DIS                 ((uint32)0x00000000U)
#define PMC_IER_VD9IE_PMC_H_DIS                 ((uint32)0x00000000U)
#define PMC_IER_VD9IE_PMC_DIS                   ((uint32)0x00000000U)
#define PMC_IER_VD8IE_C_DIS                     ((uint32)0x00000000U)
#define PMC_IER_VD8IE_F_DIS                     ((uint32)0x00000000U)
#define PMC_IER_VD7IE_C_DIS                     ((uint32)0x00000000U)
#define PMC_IER_VD4IE_C_DIS                     ((uint32)0x00000000U)
#define PMC_IER_VD3IE_P_DIS                     ((uint32)0x00000000U)
#define PMC_IER_VD3IE_F_DIS                     ((uint32)0x00000000U)
/****************************************************/
/***               (REE_VD3)                      ***/
/****************************************************/

#define PMC_REE_VD3_HVD3_P_ENA                  ((uint32)0x00000080U)
#define PMC_REE_VD3_LVD3_F_ENA                  ((uint32)0x00000040U)
#define PMC_REE_VD3_LVD3_C_ENA                  ((uint32)0x00000001U)
#define PMC_REE_VD3_HVD3_P_DIS                  ((uint32)0x00000000U)
#define PMC_REE_VD3_LVD3_F_DIS                  ((uint32)0x00000000U)
#define PMC_REE_VD3_LVD3_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (RES_VD3)                      ***/
/****************************************************/

#define PMC_RES_VD3_HVD3_P_ENA                  ((uint32)0x00000080U)
#define PMC_RES_VD3_LVD3_F_ENA                  ((uint32)0x00000040U)
#define PMC_RES_VD3_LVD3_C_ENA                  ((uint32)0x00000001U)
#define PMC_RES_VD3_HVD3_P_DIS                  ((uint32)0x00000000U)
#define PMC_RES_VD3_LVD3_F_DIS                  ((uint32)0x00000000U)
#define PMC_RES_VD3_LVD3_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (FEE_VD3)                      ***/
/****************************************************/
#define PMC_FEE_VD3_FEE3_P_ENA                  ((uint32)0x00000080U)
#define PMC_FEE_VD3_FEE3_F_ENA                  ((uint32)0x00000040U)
#define PMC_FEE_VD3_FEE3_C_ENA                  ((uint32)0x00000001U)
#define PMC_FEE_VD3_FEE3_P_DIS                  ((uint32)0x00000000U)
#define PMC_FEE_VD3_FEE3_F_DIS                  ((uint32)0x00000000U)
#define PMC_FEE_VD3_FEE3_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (REE_VD4)                      ***/
/****************************************************/
#define PMC_REE_VD4_LVD4_C_ENA                  ((uint32)0x00000001U)
#define PMC_REE_VD4_LVD4_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (RES_VD4)                      ***/
/****************************************************/
#define PMC_RES_VD4_LVD4_C_ENA                  ((uint32)0x00000001U)
#define PMC_RES_VD4_LVD4_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (FEE_VD4)                      ***/
/****************************************************/
#define PMC_FEE_VD4_FEE4_C_ENA                  ((uint32)0x00000001U)
#define PMC_FEE_VD4_FEE4_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (REE_VD7)                      ***/
/****************************************************/
#define PMC_REE_VD7_HVD7_C_ENA                  ((uint32)0x00000001U)
#define PMC_REE_VD7_HVD7_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (RES_VD7)                      ***/
/****************************************************/
#define PMC_RES_VD7_HVD7_C_ENA                  ((uint32)0x00000001U)
#define PMC_RES_VD7_HVD7_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (FEE_VD7)                      ***/
/****************************************************/
#define PMC_FEE_VD7_FEE7_C_ENA                  ((uint32)0x00000001U)
#define PMC_FEE_VD7_FEE7_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (REE_VD8)                      ***/
/****************************************************/
#define PMC_REE_VD8_LVD8_F_ENA                  ((uint32)0x00000040U)
#define PMC_REE_VD8_HVD8_C_ENA                  ((uint32)0x00000001U)
#define PMC_REE_VD8_LVD8_F_DIS                  ((uint32)0x00000000U)
#define PMC_REE_VD8_HVD8_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (RES_VD8)                      ***/
/****************************************************/
#define PMC_RES_VD8_LVD8_F_ENA                  ((uint32)0x00000040U)
#define PMC_RES_VD8_HVD8_C_ENA                  ((uint32)0x00000001U)
#define PMC_RES_VD8_LVD8_F_DIS                  ((uint32)0x00000000U)
#define PMC_RES_VD8_HVD8_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (FEE_VD8)                      ***/
/****************************************************/
#define PMC_FEE_VD8_FEE8_F_ENA                  ((uint32)0x00000040U)
#define PMC_FEE_VD8_FEE8_C_ENA                  ((uint32)0x00000001U)
#define PMC_FEE_VD8_FEE8_F_DIS                  ((uint32)0x00000000U)
#define PMC_FEE_VD8_FEE8_C_DIS                  ((uint32)0x00000000U)
/****************************************************/
/***               (REE_VD9)                      ***/
/****************************************************/
#define PMC_REE_VD9_LVD9_O_ENA                  ((uint32)0x00004000U)
#define PMC_REE_VD9_HVD9_O_ENA                  ((uint32)0x00000800U)
#define PMC_REE_VD9_HVD9_IO_5V_ENA              ((uint32)0x00000400U)
#define PMC_REE_VD9_LVD9_IO_5V_ENA              ((uint32)0x00000200U)
#define PMC_REE_VD9_HVD9_PMC_ENA                ((uint32)0x00000008U)
#define PMC_REE_VD9_LVD9_PMC_ENA                ((uint32)0x00000001U)
#define PMC_REE_VD9_LVD9_O_DIS                  ((uint32)0x00000000U)
#define PMC_REE_VD9_HVD9_O_DIS                  ((uint32)0x00000000U)
#define PMC_REE_VD9_HVD9_IO_5V_DIS              ((uint32)0x00000000U)
#define PMC_REE_VD9_LVD9_IO_5V_DIS              ((uint32)0x00000000U)
#define PMC_REE_VD9_HVD9_PMC_DIS                ((uint32)0x00000000U)
#define PMC_REE_VD9_LVD9_PMC_DIS                ((uint32)0x00000000U)
/****************************************************/
/***               (RES_VD9)                      ***/
/****************************************************/
#define PMC_RES_VD9_HVD9_O_ENA                  ((uint32)0x00000800U)
#define PMC_RES_VD9_HVD9_IO_5V_ENA              ((uint32)0x00000400U)
#define PMC_RES_VD9_HVD9_PMC_ENA                ((uint32)0x00000008U)
#define PMC_RES_VD9_HVD9_O_DIS                  ((uint32)0x00000000U)
#define PMC_RES_VD9_HVD9_IO_5V_DIS              ((uint32)0x00000000U)
#define PMC_RES_VD9_HVD9_PMC_DIS                ((uint32)0x00000000U)
/****************************************************/
/***               (FEE_VD9)                      ***/
/****************************************************/
#define PMC_FEE_VD9_FEE9_O_ENA                  ((uint32)0x00004000U)
#define PMC_FEE_VD9_FEE9_O_H_ENA                ((uint32)0x00000800U)
#define PMC_FEE_VD9_FEE9_IO_5V_H_ENA            ((uint32)0x00000400U)
#define PMC_FEE_VD9_FEE9_IO_5V_ENA              ((uint32)0x00000200U)
#define PMC_FEE_VD9_FEE9_PMC_H_ENA              ((uint32)0x00000008U)
#define PMC_FEE_VD9_FEE9_PMC_ENA                ((uint32)0x00000001U)
#define PMC_FEE_VD9_FEE9_O_DIS                  ((uint32)0x00000000U)
#define PMC_FEE_VD9_FEE9_O_H_DIS                ((uint32)0x00000000U)
#define PMC_FEE_VD9_FEE9_IO_5V_H_DIS            ((uint32)0x00000000U)
#define PMC_FEE_VD9_FEE9_IO_5V_DIS              ((uint32)0x00000000U)
#define PMC_FEE_VD9_FEE9_PMC_H_DIS              ((uint32)0x00000000U)
#define PMC_FEE_VD9_FEE9_PMC_DIS                ((uint32)0x00000000U)
/****************************************************/
/***               (REE_VD10)                     ***/
/****************************************************/
#define PMC_REE_VD10_LVD10_A_ENA                ((uint32)0x00008000U)
#define PMC_REE_VD10_LVD10_F_ENA                ((uint32)0x00000040U)
#define PMC_REE_VD10_LVD10_A_DIS                ((uint32)0x00000000U)
#define PMC_REE_VD10_LVD10_F_DIS                ((uint32)0x00000000U)
/****************************************************/
/***               (FEE_VD10)                     ***/
/****************************************************/
#define PMC_FEE_VD10_FEE10_A_ENA                ((uint32)0x00008000U)
#define PMC_FEE_VD10_FEE10_F_ENA                ((uint32)0x00000040U)
#define PMC_FEE_VD10_FEE10_A_DIS                ((uint32)0x00000000U)
#define PMC_FEE_VD10_FEE10_F_DIS                ((uint32)0x00000000U)
/****************************************************/
/***               (REE_VD12)                     ***/
/****************************************************/
#define PMC_REE_VD12_HVD12_F_ENA                ((uint32)0x00000040U)
#define PMC_REE_VD12_HVD12_F_DIS                ((uint32)0x00000000U)
/****************************************************/
/***               (RES_VD12)                     ***/
/****************************************************/
#define PMC_RES_VD12_HVD12_F_ENA                ((uint32)0x00000040U)
#define PMC_RES_VD12_HVD12_F_DIS                ((uint32)0x00000000U)
/****************************************************/
/***               (FEE_VD12)                     ***/
/****************************************************/
#define PMC_FEE_VD12_FEE12_F_ENA                ((uint32)0x00000040U)
#define PMC_FEE_VD12_FEE12_F_DIS                ((uint32)0x00000000U)
/****************************************************/
/***               (REE_VD13)                     ***/
/****************************************************/
#define PMC_REE_VD13_LVD13_IM_ENA               ((uint32)0x00000100U)
#define PMC_REE_VD13_LVD13_IM_DIS               ((uint32)0x00000000U)
/****************************************************/
/***               (RES_VD13)                     ***/
/****************************************************/
#define PMC_RES_VD13_LVD13_IM_ENA               ((uint32)0x00000100U)
#define PMC_RES_VD13_LVD13_IM_DIS               ((uint32)0x00000000U)
/****************************************************/
/***               (FEE_VD13)                     ***/
/****************************************************/
#define PMC_FEE_VD13_FEE13_IM_ENA               ((uint32)0x00000100U)
#define PMC_FEE_VD13_FEE13_IM_DIS               ((uint32)0x00000000U)
/****************************************************/
/***               (REE_VD14)                     ***/
/****************************************************/
#define PMC_REE_VD14_LVD14_A_ENA                ((uint32)0x00008000U)
#define PMC_REE_VD14_HVD14_IM_ENA               ((uint32)0x00000100U)
#define PMC_REE_VD14_LVD14_A_DIS                ((uint32)0x00000000U)
#define PMC_REE_VD14_HVD14_IM_DIS               ((uint32)0x00000000U)
/****************************************************/
/***               (RES_VD14)                      ***/
/****************************************************/
#define PMC_RES_VD14_LVD14_A_ENA                ((uint32)0x00008000U)
#define PMC_RES_VD14_HVD14_IM_ENA               ((uint32)0x00000100U)
#define PMC_RES_VD14_LVD14_A_DIS                ((uint32)0x00000000U)
#define PMC_RES_VD14_HVD14_IM_DIS               ((uint32)0x00000000U)
/****************************************************/
/***               (FEE_VD14)                      ***/
/****************************************************/
#define PMC_FEE_VD14_FEE14_A_ENA                ((uint32)0x00008000U)
#define PMC_FEE_VD14_FEE14_IM_ENA               ((uint32)0x00000100U)
#define PMC_FEE_VD14_FEE14_A_DIS                ((uint32)0x00000000U)
#define PMC_FEE_VD14_FEE14_IM_DIS               ((uint32)0x00000000U)
/****************************************************/
/***               (REE_VD15)                     ***/
/****************************************************/
#define PMC_REE_VD15_HVD15_A_ENA                ((uint32)0x00008000U)
#define PMC_REE_VD15_HVD15_C_ENA                ((uint32)0x00000001U)
#define PMC_REE_VD15_HVD15_A_DIS                ((uint32)0x00000000U)
#define PMC_REE_VD15_HVD15_C_DIS                ((uint32)0x00000000U)
/****************************************************/
/***               (RES_VD15)                     ***/
/****************************************************/
#define PMC_RES_VD15_HVD15_A_ENA                ((uint32)0x00008000U)
#define PMC_RES_VD15_HVD15_C_ENA                ((uint32)0x00000001U)
#define PMC_RES_VD15_HVD15_A_DIS                ((uint32)0x00000000U)
#define PMC_RES_VD15_HVD15_C_DIS                ((uint32)0x00000000U)
/****************************************************/
/***               (FEE_VD15)                     ***/
/****************************************************/
#define PMC_FEE_VD15_FEE15_A_ENA                ((uint32)0x00008000U)
#define PMC_FEE_VD15_FEE15_C_ENA                ((uint32)0x00000001U)
#define PMC_FEE_VD15_FEE15_A_DIS                ((uint32)0x00000000U)
#define PMC_FEE_VD15_FEE15_C_DIS                ((uint32)0x00000000U)
/****************************************************/
/***               (VSIO)                         ***/
/****************************************************/
#define PMC_VSIO_VSIO_IF2_EN                    ((uint32)0x00000800U)
#define PMC_VSIO_VSIO_IF_EN                     ((uint32)0x00000400U)
#define PMC_VSIO_VSIO_IJ_EN                     ((uint32)0x00000200U)
#define PMC_VSIO_VSIO_IM_EN                     ((uint32)0x00000100U)


/****************************************************/
/***               (REE_TD)                       ***/
/****************************************************/
#define PMC_REE_TD_TEMP_3_ENA                   ((uint32)0x00000008U)
#define PMC_REE_TD_TEMP_2_ENA                   ((uint32)0x00000004U)
#define PMC_REE_TD_TEMP_0_ENA                   ((uint32)0x00000001U)
#define PMC_REE_TD_TEMP_3_DIS                   ((uint32)0x00000000U)
#define PMC_REE_TD_TEMP_2_DIS                   ((uint32)0x00000000U)
#define PMC_REE_TD_TEMP_0_DIS                   ((uint32)0x00000000U)

/****************************************************/
/***               (RES_TD)                       ***/
/****************************************************/

#define PMC_RES_TD_TEMP_3_ENA                   ((uint32)0x00000008U)
#define PMC_RES_TD_TEMP_2_ENA                   ((uint32)0x00000004U)
#define PMC_RES_TD_TEMP_0_ENA                   ((uint32)0x00000001U)
#define PMC_RES_TD_TEMP_3_DIS                   ((uint32)0x00000000U)
#define PMC_RES_TD_TEMP_2_DIS                   ((uint32)0x00000000U)
#define PMC_RES_TD_TEMP_0_DIS                   ((uint32)0x00000000U)

/****************************************************/
/***               (CTL_TD)                       ***/
/****************************************************/

#define PMC_CTL_TD_TS3IE_ENA                    ((uint32)0x00008000U)
#define PMC_CTL_TD_TS2IE_ENA                    ((uint32)0x00004000U)
#define PMC_CTL_TD_TS0IE_ENA                    ((uint32)0x00002000U)
#define PMC_CTL_TD_DOUT_ENA                     ((uint32)0x00000002U)
#define PMC_CTL_TD_AOUT_ENA                     ((uint32)0x00000001U)
#define PMC_CTL_TD_TS3IE_DIS                    ((uint32)0x00000000U)
#define PMC_CTL_TD_TS2IE_DIS                    ((uint32)0x00000000U)
#define PMC_CTL_TD_TS0IE_DIS                    ((uint32)0x00000000U)
#define PMC_CTL_TD_DOUT_DIS                     ((uint32)0x00000000U)
#define PMC_CTL_TD_AOUT_DIS                     ((uint32)0x00000000U)

/****************************************************/
/***               (FEE_TD)                       ***/
/****************************************************/

#define PMC_FEE_TD_FEE_TS3_ENA                  ((uint32)0x00000008U)
#define PMC_FEE_TD_FEE_TS2_ENA                  ((uint32)0x00000004U)
#define PMC_FEE_TD_FEE_TS0_ENA                  ((uint32)0x00000001U)
#define PMC_FEE_TD_FEE_TS3_DIS                  ((uint32)0x00000000U)
#define PMC_FEE_TD_FEE_TS2_DIS                  ((uint32)0x00000000U)
#define PMC_FEE_TD_FEE_TS0_DIS                  ((uint32)0x00000000U)

/****************************************************/
/***               (VSIO)                         ***/
/****************************************************/
#define PMC_VSIO_VSIO_IF2_ENA                   ((uint32)0x00000800U)
#define PMC_VSIO_VSIO_IF_ENA                    ((uint32)0x00000400U)
#define PMC_VSIO_VSIO_IJ_ENA                    ((uint32)0x00000200U)
#define PMC_VSIO_VSIO_IM_ENA                    ((uint32)0x00000100U)
#define PMC_VSIO_VSIO_IF2_DIS                   ((uint32)0x00000000U)
#define PMC_VSIO_VSIO_IF_DIS                    ((uint32)0x00000000U)
#define PMC_VSIO_VSIO_IJ_DIS                    ((uint32)0x00000000U)
#define PMC_VSIO_VSIO_IM_DIS                    ((uint32)0x00000000U)


#define FLASHC_PFCR1_APC_MASK32                 ((uint32)0x0000E000U)
#define FLASHC_PFCR1_RWSC_MASK32                ((uint32)0x00001F00U)
#define FLASHC_PFCR1_P0_DPFEN_MASK32            ((uint32)0x00000040U)
#define FLASHC_PFCR1_P0_IFPFEN_MASK32           ((uint32)0x00000010U)
#define FLASHC_PFCR1_P0_PFLIM_MASK32            ((uint32)0x00000006U)
#define FLASHC_PFCR1_P0_BFEN_MASK32             ((uint32)0x00000001U)



#if MCU_FCCU_ENABLE == STD_ON
/*
 * @brief FCCU operation run definition
 */
typedef enum {
    FCCU_RUN_OP0  = 0U,     /* No operation */
    FCCU_RUN_OP1  = 1U,     /* Set the FCCU into the CONFIG state */
    FCCU_RUN_OP2  = 2U,     /* Set the ECCU into the NORMAL state */
    FCCU_RUN_OP3  = 3U,     /* Read the FCCU state */
    FCCU_RUN_OP4  = 4U,     /* Read the FCCU frozen status flags - N2AF_STATUS */
    FCCU_RUN_OP5  = 5U,     /* Read the FCCU frozen status flags - A2FF_STATUS */
    FCCU_RUN_OP6  = 6U,     /* Read the FCCU frozen status flags - N2FF_STATUS */
    FCCU_RUN_OP7  = 7U,     /* Read the FCCU frozen status flags - F2AF_STATUS */
    FCCU_RUN_OP10 = 10U,    /* Read the RF status register */
    FCCU_RUN_OP12 = 12U,    /* RF status clear operation in progress */
    FCCU_RUN_OP13 = 13U,    /* Clear the freeze status register */
    FCCU_RUN_OP14 = 14U,    /* CONFIG to NORMAL FCCU state (configuration timeout) in progress */
    FCCU_RUN_OP15 = 15U,    /* Clear the operation status (OPS=idle) */
    FCCU_RUN_OP17 = 17U,    /* Read the ALARM timer */
    FCCU_RUN_OP19 = 19U,    /* Read the CFG timer */
    FCCU_RUN_OP20 = 20U,    /* Read the Error Pin low counter value */
} fccu_op_run_t;

/*
 * @brief FCCU operation status definition
 */
typedef enum
{
    FCCU_OPS_IDLE        = 0U,    /* idle */
    FCCU_OPS_IN_PROGRESS = 1U,    /* in progress */
    FCCU_OPS_ABORTED     = 2U,    /* aborted */
    FCCU_OPS_SUCCESSFUL  = 3U     /* successful */
} fccu_op_status_t; /* PRQA S 1535 */

/*
 * @brief FCCU status definitions
 */
typedef enum {
    FCCU_NORMAL_STATE  = 0U,
    FCCU_CONFIG_STATE  = 1U,
    FCCU_ALARM_STATE   = 2U,
    FCCU_FAULT_STATE   = 3U,
    FCCU_UNKNOWN_STATE = 4U,
} fccu_status_t;


/*
 * @brief FCCU frozen status definitions
 */
typedef enum {
    FCCU_FROZEN_N2AF_STATUS = 0U,
    FCCU_FROZEN_A2FF_STATUS = 1U,
    FCCU_FROZEN_N2FF_STATUS = 2U,
    FCCU_FROZEN_F2AF_STATUS = 3U
} fccu_frozen_type_t;


/*
 * @brief FCCU XTMR type definitions
 */
typedef enum {
    FCCU_XTMR_ALARM = 0U,
    FCCU_XTMR_CFG   = 1U,
    FCCU_XTMR_ETMR  = 2U
} fccu_xtmr_type_t;

/*
 * @brief FCCU INT source definitions
 */
typedef enum {
    FCCU_INT_TIMEOUT = 0U,
    FCCU_INT_ALARM   = 1U,
    FCCU_INT_NMI     = 2U,
} fccu_int_status_t;


/*
 * @brief Fault State Flags for Recoverable Faults
 */
typedef struct /* PRQA S 3630 */
{
    uint32 faultsFlags[FCCU_RF_MAX_GROUP]; /*!< Faults Flags */
} fccu_faults_flags_t;

#endif

#if ((MCU_HARDVER == 4) || (MCU_HARDVER == 5) || (MCU_HARDVER == 7) || (MCU_HARDVER == 8))

typedef uint32_t mcuHsmSrvCmd_t;

typedef struct
{
    /** @brief   INPUT: Specifies the HSM attribute ID.*/
    uint16_t   attrId;
    uint8_t    reserved[2];
    /** @brief   INPUT: Specifies the attribute length (in bytes). The size of the memory location
     *                   must be equal to the length of attribute structure */
    uint32_t      attrLen;
    /** @brief   INPUT: The address of the attribute. */
    uint32_t     pAttr;
} mcuHsmSetAttrSrv_t;

typedef struct
{
    mcuHsmSrvCmd_t srvCmd;

    union
    {
        mcuHsmSetAttrSrv_t         	setAttr;
    } srvReq;
} mcuHsmSrvDescriptor_t;
#define MCU_HSM_SRV_CMD_SET_ATTR        ((mcuHsmSrvCmd_t)0x00010002)
#define MCU_HSE_OPERATION_TIMEOUT     	((uint32_t)0x1FFFFFFUL)

#define MCU_HSM_STATUS_MASK           	(0x1UL << 0)
#define MCU_HSM_STATUS_BUSY           	(0x1UL)
#define MCU_HSM_STATUS_READY          	(0x0UL)

#define MCU_HSM_ERC_OFFSET            	0x400U

#endif

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Mcu_CoreType, MCU_CODE) Mcu_LLD_Get_Core_Id(void);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#if MCU_FCCU_ENABLE == STD_ON
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) FCCU_LLD_SetCfgTimeout(uint8 to);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(uint8, MCU_CODE)FCCU_LLD_CheckIntStatus(fccu_int_status_t intStatus);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) FCCU_LLD_GetFrozenStatus(fccu_frozen_type_t frozenType, uint16 *frozenStatus);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) FCCU_LLD_ClearFreezeStatus(void);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(uint32, MCU_CODE) FCCU_LLD_GetXtmrValue(fccu_xtmr_type_t xtmrType);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE)FCCU_LLD_SetRfFake(fccu_failure_inputs_t fakeCode);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
#endif

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_Init(P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_DATA) pMcu_ConfigPtr);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_SysCLockCheck(
    P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_DATA) pMcu_ClockConfigPtr );
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_PeriCLockCheck(
    P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_DATA) pMcu_ClockConfigPtr );
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Clock_Init \
( \
    P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_DATA) pMcu_ClockConfigPtr \
);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_GetPllStatus(void);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_DistributePllClock(void);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Set_Chip_Mode \
( \
    P2CONST(Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) pMcu_ModeConfigPtr \
);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_SetMode \
( \
    P2CONST(Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) pMcu_ModeConfigPtr
);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE)Mcu_LLD_PerformReset(Mcu_Rgm_ResetType ResetType);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Mcu_ResetType, MCU_CODE) Mcu_LLD_GetResetReason(void);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Mcu_RawResetType, MCU_CODE) Mcu_LLD_GetResetRaw(void);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Mcu_RamStateType, MCU_CODE) Mcu_LLD_GetRamState(void);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#if MCU_FCCU_ENABLE == STD_ON
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_FccuInit( \
    P2CONST( Mcu_FccuConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_FccuConfigPtr \
);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
Std_ReturnType FCCU_LLD_ClearFaults(uint8 faultIndex);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
#endif

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_PeriModeSet
    (P2CONST(Mcu_PeriConfigType, AUTOMATIC, MCU_APPL_CONST) PeriConfigPtr);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_PeriResetPend 
    (P2CONST(Mcu_PeripheralResetType, AUTOMATIC, MCU_APPL_CONST) ResetConfigPtr);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_PeriResetClose (VAR(void, AUTOMATIC));
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_CoreSynchronise (VAR(void, AUTOMATIC));
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_InternalVrefEn (VAR(void, AUTOMATIC));
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_XoscISR(void);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_InvalidConfig_ISR(void);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_InvalidMode_ISR(void);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_SafeMode_ISR(void);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_ModeComplete_ISR(void);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_VoltageError_ISR(void);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_TemperatureErrorError_ISR(void);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_Fccu_ISR(void);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_ClockFailureCmu_ISR(void);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
#include "Cache_H.h"

#if ((MCU_HARDVER == 4 || MCU_HARDVER == 5) || (MCU_HARDVER == 7) || (MCU_HARDVER == 8))
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(status_t, MCU_CODE) MCU_HSM_SetClkDiv
(
	VAR(uint32, AUTOMATIC) divider
);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
#endif


#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_PctlPeriRunSet
( \
    VAR(Mcu_McMePeriNameType, AUTOMATIC) Mcu_McMePeriName, \
    VAR(Mcu_McMeLPModeType, AUTOMATIC) Mcu_McMeLPMode, \
    VAR(Mcu_McMeRunModeType, AUTOMATIC) Mcu_McMeRunMode \
);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_RgmlPeriRstSet
( \
    VAR(Mcu_RgmPeriRstType, AUTOMATIC) Mcu_McRgmPeriName
);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#include "Cache_H.h"


#ifdef __cplusplus
}
#endif

#endif
