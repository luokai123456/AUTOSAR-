/**
****************************************************************************************
 * @FilePath: saf_ccfc30xx.h.h
 * @Author: CCORE
 * @Date: 2024-02-28
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: ccfc3007 Head File
****************************************************************************************
*/
#ifndef SAF_CCFC3007PT_H
#define SAF_CCFC3007PT_H

/* PRQA S 1535,1536 EOF */

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_common.h"
#include "derivative.h"
#include "edma_lld.h"
#include "eDma_LLDriver.h"



/**
****************************************************************************************
 * @brief: Macros
****************************************************************************************
*/

#define SAF_SWITCH_OFF               (0U)
#define SAF_SWITCH_ON                (1U)

/* Read after write assert. */
#define READ_AFTER_WRITE_ASSERT(exprA, exprB) SAF_ReadAfterWriteAssert(exprA, exprB, __FILE__, __LINE__)
void SAF_ReadAfterWriteAssert(uint32_t exprA, uint32_t exprB, const char* file, unsigned int line);

extern FS_STATUS SAF_ReadBackCompare(uint32_t cmpValA, uint32_t cmpValB, uint32_t cmpMask);

#define CMPVALUE_UNSIGNED_INT_MASK  0xFFFFFFFFU

#define ETPU_AB_CR_ENG1	(*(volatile eTPU_Type *)  0xFFDC0400UL)
#define ETPU_AB_CR_ENG2	(*(volatile eTPU_Type *)  0xFFDC0800UL)
#define ETPU_C_CR_ENG1	(*(volatile eTPU_Type *)  0xFBF80400UL)
#define ETPU_C_CR_ENG2	(*(volatile eTPU_Type *)  0xFBF80800UL)

/* XBAR */
#define XBAR_0_PRS0          XBAR_0.PORT[0].PRS.R          /* XBAR Priority Registers Slave */
#define XBAR_0_CRS0          XBAR_0.PORT[0].CRS.R          /* XBAR Control Register */
#define XBAR_0_PRS1          XBAR_0.PORT[1].PRS.R          /* XBAR Priority Registers Slave */
#define XBAR_0_CRS1          XBAR_0.PORT[1].CRS.R          /* XBAR Control Register */
#define XBAR_0_PRS2          XBAR_0.PORT[2].PRS.R          /* XBAR Priority Registers Slave */
#define XBAR_0_CRS2          XBAR_0.PORT[2].CRS.R          /* XBAR Control Register */
#define XBAR_0_PRS3          XBAR_0.PORT[3].PRS.R          /* XBAR Priority Registers Slave */
#define XBAR_0_CRS3          XBAR_0.PORT[3].CRS.R          /* XBAR Control Register */
#define XBAR_0_PRS4          XBAR_0.PORT[4].PRS.R          /* XBAR Priority Registers Slave */
#define XBAR_0_CRS4          XBAR_0.PORT[4].CRS.R          /* XBAR Control Register */
#define XBAR_0_PRS5          XBAR_0.PORT[5].PRS.R          /* XBAR Priority Registers Slave */
#define XBAR_0_CRS5          XBAR_0.PORT[5].CRS.R          /* XBAR Control Register */
#define XBAR_0_PRS6          XBAR_0.PORT[6].PRS.R          /* XBAR Priority Registers Slave */
#define XBAR_0_CRS6          XBAR_0.PORT[6].CRS.R          /* XBAR Control Register */
#define XBAR_0_PRS7          XBAR_0.PORT[7].PRS.R          /* XBAR Priority Registers Slave */
#define XBAR_0_CRS7          XBAR_0.PORT[7].CRS.R          /* XBAR Control Register */

#define XBAR_1_PRS0          XBAR_1.PORT[0].PRS.R          /* XBAR Priority Registers Slave */
#define XBAR_1_CRS0          XBAR_1.PORT[0].CRS.R          /* XBAR Control Register */
#define XBAR_1_PRS1          XBAR_1.PORT[1].PRS.R          /* XBAR Priority Registers Slave */
#define XBAR_1_CRS1          XBAR_1.PORT[1].CRS.R          /* XBAR Control Register */
#define XBAR_1_PRS2          XBAR_1.PORT[2].PRS.R          /* XBAR Priority Registers Slave */
#define XBAR_1_CRS2          XBAR_1.PORT[2].CRS.R          /* XBAR Control Register */
#define XBAR_1_PRS3          XBAR_1.PORT[3].PRS.R          /* XBAR Priority Registers Slave */
#define XBAR_1_CRS3          XBAR_1.PORT[3].CRS.R          /* XBAR Control Register */
#define XBAR_1_PRS4          XBAR_1.PORT[4].PRS.R          /* XBAR Priority Registers Slave */
#define XBAR_1_CRS4          XBAR_1.PORT[4].CRS.R          /* XBAR Control Register */
#define XBAR_1_PRS5          XBAR_1.PORT[5].PRS.R          /* XBAR Priority Registers Slave */
#define XBAR_1_CRS5          XBAR_1.PORT[5].CRS.R          /* XBAR Control Register */
#define XBAR_1_PRS6          XBAR_1.PORT[6].PRS.R          /* XBAR Priority Registers Slave */
#define XBAR_1_CRS6          XBAR_1.PORT[6].CRS.R          /* XBAR Control Register */
#define XBAR_1_PRS7          XBAR_1.PORT[7].PRS.R          /* XBAR Priority Registers Slave */
#define XBAR_1_CRS7          XBAR_1.PORT[7].CRS.R          /* XBAR Control Register */


/* CMU */
#define CMU_ADCSAR_CSR       CMU_ADCSAR.CSR.R              /* CMU Control Status Register */
#define CMU_ADCSAR_FDR       CMU_ADCSAR.FDR.R              /* CMU Frequency Display Register */
#define CMU_ADCSAR_HFREFR    CMU_ADCSAR.HFREFR.R           /* CMU High Frequency Reference Register CLKMN1 */
#define CMU_ADCSAR_LFREFR    CMU_ADCSAR.LFREFR.R           /* CMU Low Frequency Reference Register CLKMN1 */
#define CMU_ADCSAR_ISR       CMU_ADCSAR.ISR.R              /* CMU Interrupt Status Register */
#define CMU_ADCSAR_MDR       CMU_ADCSAR.MDR.R              /* CMU Measurement Duration Register */

#define CMU_ADCSD_CSR        CMU_ADCSD.CSR.R               /* CMU Control Status Register */
#define CMU_ADCSD_FDR        CMU_ADCSD.FDR.R               /* CMU Frequency Display Register */
#define CMU_ADCSD_HFREFR     CMU_ADCSD.HFREFR.R            /* CMU High Frequency Reference Register CLKMN1 */
#define CMU_ADCSD_LFREFR     CMU_ADCSD.LFREFR.R            /* CMU Low Frequency Reference Register CLKMN1 */
#define CMU_ADCSD_ISR        CMU_ADCSD.ISR.R               /* CMU Interrupt Status Register */
#define CMU_ADCSD_MDR        CMU_ADCSD.MDR.R               /* CMU Measurement Duration Register */

#define CMU_CLKOUT_CSR       CMU_CLKOUT.CSR.R              /* CMU Control Status Register */
#define CMU_CLKOUT_FDR       CMU_CLKOUT.FDR.R              /* CMU Frequency Display Register */
#define CMU_CLKOUT_HFREFR    CMU_CLKOUT.HFREFR.R           /* CMU High Frequency Reference Register CLKMN1 */
#define CMU_CLKOUT_LFREFR    CMU_CLKOUT.LFREFR.R           /* CMU Low Frequency Reference Register CLKMN1 */
#define CMU_CLKOUT_ISR       CMU_CLKOUT.ISR.R              /* CMU Interrupt Status Register */
#define CMU_CLKOUT_MDR       CMU_CLKOUT.MDR.R              /* CMU Measurement Duration Register */

#define CMU_CORE_CSR         CMU_CORE.CSR.R                /* CMU Control Status Register */
#define CMU_CORE_FDR         CMU_CORE.FDR.R                /* CMU Frequency Display Register */
#define CMU_CORE_HFREFR      CMU_CORE.HFREFR.R             /* CMU High Frequency Reference Register CLKMN1 */
#define CMU_CORE_LFREFR      CMU_CORE.LFREFR.R             /* CMU Low Frequency Reference Register CLKMN1 */
#define CMU_CORE_ISR         CMU_CORE.ISR.R                /* CMU Interrupt Status Register */
#define CMU_CORE_MDR         CMU_CORE.MDR.R                /* CMU Measurement Duration Register */

#define CMU_FXBAR_CSR        CMU_FXBAR.CSR.R               /* CMU Control Status Register */
#define CMU_FXBAR_FDR        CMU_FXBAR.FDR.R               /* CMU Frequency Display Register */
#define CMU_FXBAR_HFREFR     CMU_FXBAR.HFREFR.R            /* CMU High Frequency Reference Register CLKMN1 */
#define CMU_FXBAR_LFREFR     CMU_FXBAR.LFREFR.R            /* CMU Low Frequency Reference Register CLKMN1 */
#define CMU_FXBAR_ISR        CMU_FXBAR.ISR.R               /* CMU Interrupt Status Register */
#define CMU_FXBAR_MDR        CMU_FXBAR.MDR.R               /* CMU Measurement Duration Register */

#define CMU_PBRIDGE_CSR      CMU_PBRIDGE.CSR.R             /* CMU Control Status Register */
#define CMU_PBRIDGE_FDR      CMU_PBRIDGE.FDR.R             /* CMU Frequency Display Register */
#define CMU_PBRIDGE_HFREFR   CMU_PBRIDGE.HFREFR.R          /* CMU High Frequency Reference Register CLKMN1 */
#define CMU_PBRIDGE_LFREFR   CMU_PBRIDGE.LFREFR.R          /* CMU Low Frequency Reference Register CLKMN1 */
#define CMU_PBRIDGE_ISR      CMU_PBRIDGE.ISR.R             /* CMU Interrupt Status Register */
#define CMU_PBRIDGE_MDR      CMU_PBRIDGE.MDR.R             /* CMU Measurement Duration Register */

#define CMU_PER_CSR          CMU_PER.CSR.R                 /* CMU Control Status Register */
#define CMU_PER_FDR          CMU_PER.FDR.R                 /* CMU Frequency Display Register */
#define CMU_PER_HFREFR       CMU_PER.HFREFR.R              /* CMU High Frequency Reference Register CLKMN1 */
#define CMU_PER_LFREFR       CMU_PER.LFREFR.R              /* CMU Low Frequency Reference Register CLKMN1 */
#define CMU_PER_ISR          CMU_PER.ISR.R                 /* CMU Interrupt Status Register */
#define CMU_PER_MDR          CMU_PER.MDR.R                 /* CMU Measurement Duration Register */

#define CMU_PLL_CSR          CMU_PLL.CSR.R                 /* CMU Control Status Register */
#define CMU_PLL_FDR          CMU_PLL.FDR.R                 /* CMU Frequency Display Register */
#define CMU_PLL_HFREFR       CMU_PLL.HFREFR.R              /* CMU High Frequency Reference Register CLKMN1 */
#define CMU_PLL_LFREFR       CMU_PLL.LFREFR.R              /* CMU Low Frequency Reference Register CLKMN1 */
#define CMU_PLL_ISR          CMU_PLL.ISR.R                 /* CMU Interrupt Status Register */
#define CMU_PLL_MDR          CMU_PLL.MDR.R                 /* CMU Measurement Duration Register */

#define CMU_PSI5_1US_CSR     CMU_PSI5_1US.CSR.R            /* CMU Control Status Register */
#define CMU_PSI5_1US_FDR     CMU_PSI5_1US.FDR.R            /* CMU Frequency Display Register */
#define CMU_PSI5_1US_HFREFR  CMU_PSI5_1US.HFREFR.R         /* CMU High Frequency Reference Register CLKMN1 */
#define CMU_PSI5_1US_LFREFR  CMU_PSI5_1US.LFREFR.R         /* CMU Low Frequency Reference Register CLKMN1 */
#define CMU_PSI5_1US_ISR     CMU_PSI5_1US.ISR.R            /* CMU Interrupt Status Register */
#define CMU_PSI5_1US_MDR     CMU_PSI5_1US.MDR.R            /* CMU Measurement Duration Register */

#define CMU_PSI5_F125_CSR    CMU_PSI5_F125.CSR.R           /* CMU Control Status Register */
#define CMU_PSI5_F125_FDR    CMU_PSI5_F125.FDR.R           /* CMU Frequency Display Register */
#define CMU_PSI5_F125_HFREFR CMU_PSI5_F125.HFREFR.R        /* CMU High Frequency Reference Register CLKMN1 */
#define CMU_PSI5_F125_LFREFR CMU_PSI5_F125.LFREFR.R        /* CMU Low Frequency Reference Register CLKMN1 */
#define CMU_PSI5_F125_ISR    CMU_PSI5_F125.ISR.R           /* CMU Interrupt Status Register */
#define CMU_PSI5_F125_MDR    CMU_PSI5_F125.MDR.R           /* CMU Measurement Duration Register */

#define CMU_PSI5_F189_CSR    CMU_PSI5_F189.CSR.R           /* CMU Control Status Register */
#define CMU_PSI5_F189_FDR    CMU_PSI5_F189.FDR.R           /* CMU Frequency Display Register */
#define CMU_PSI5_F189_HFREFR CMU_PSI5_F189.HFREFR.R        /* CMU High Frequency Reference Register CLKMN1 */
#define CMU_PSI5_F189_LFREFR CMU_PSI5_F189.LFREFR.R        /* CMU Low Frequency Reference Register CLKMN1 */
#define CMU_PSI5_F189_ISR    CMU_PSI5_F189.ISR.R           /* CMU Interrupt Status Register */
#define CMU_PSI5_F189_MDR    CMU_PSI5_F189.MDR.R           /* CMU Measurement Duration Register */

#define CMU_SENT_CSR         CMU_SENT.CSR.R                /* CMU Control Status Register */
#define CMU_SENT_FDR         CMU_SENT.FDR.R                /* CMU Frequency Display Register */
#define CMU_SENT_HFREFR      CMU_SENT.HFREFR.R             /* CMU High Frequency Reference Register CLKMN1 */
#define CMU_SENT_LFREFR      CMU_SENT.LFREFR.R             /* CMU Low Frequency Reference Register CLKMN1 */
#define CMU_SENT_ISR         CMU_SENT.ISR.R                /* CMU Interrupt Status Register */
#define CMU_SENT_MDR         CMU_SENT.MDR.R                /* CMU Measurement Duration Register */

#define CMU_SXBAR_CSR        CMU_SXBAR.CSR.R               /* CMU Control Status Register */
#define CMU_SXBAR_FDR        CMU_SXBAR.FDR.R               /* CMU Frequency Display Register */
#define CMU_SXBAR_HFREFR     CMU_SXBAR.HFREFR.R            /* CMU High Frequency Reference Register CLKMN1 */
#define CMU_SXBAR_LFREFR     CMU_SXBAR.LFREFR.R            /* CMU Low Frequency Reference Register CLKMN1 */
#define CMU_SXBAR_ISR        CMU_SXBAR.ISR.R               /* CMU Interrupt Status Register */
#define CMU_SXBAR_MDR        CMU_SXBAR.MDR.R               /* CMU Measurement Duration Register */


#define SAF_SMPU_MASTER_MAX_INDEX        (15U)
/* SMPU */
#define SAF_SMPU_MASTER_CORE0            (0U)
#define SAF_SMPU_MASTER_CORE1            (1U)
#define SAF_SMPU_MASTER_CORE2            (2U)
#define SAF_SMPU_MASTER_DMA0             (3U)
#define SAF_SMPU_MASTER_ENET             (4U)
#define SAF_SMPU_MASTER_FLEXRAY0         (5U)
#define SAF_SMPU_MASTER_SIPI1            (6U)
#define SAF_SMPU_MASTER_SIPI0_LFAST      (7U)
#define SAF_SMPU_MASTER_CORE0DEBUG       (8U)
#define SAF_SMPU_MASTER_CORE1DEBUG       (9U)
#define SAF_SMPU_MASTER_CORE2DEBUG       (10U)
#define SAF_SMPU_MASTER_DMA1             (11U)
#define SAF_SMPU_MASTER_FLEXRAY1         (13U)
#define SAF_SMPU_MASTER_HSM              (14U)
#define SAF_SMPU_MASTER_NAR              (15U)
/* 3012 SMPU */
#define SAF_SMPU_MASTER_CORE5DEBUG       (4U)
#define SAF_SMPU_MASTER_GTMGMAC          (5U)
#define SAF_SMPU_MASTER_CORE3            (6U)
#define SAF_SMPU_MASTER_CORE4            (7U)
#define SAF_SMPU_MASTER_CORE3DEBUG       (11U)
#define SAF_SMPU_MASTER_CORE4DEBUG       (12U)
#define SAF_SMPU_MASTER_CORE5            (13U)
#define SAF_SMPU_MASTER_MULTI            (15U)


/* CRC */
#define CRC_0_CFG            CRC_0.CFG.R                   /* Configuration Register */
#define CRC_0_INP            CRC_0.INP.R                   /* Input Register */
#define CRC_0_CSTAT          CRC_0.CSTAT.R                 /* Current Status Register */
#define CRC_0_OUTP           CRC_0.OUTP.R                  /* Output Register */

#define CRC_1_CFG            CRC_1.CFG.R                   /* Configuration Register */
#define CRC_1_INP            CRC_1.INP.R                   /* Input Register */
#define CRC_1_CSTAT          CRC_1.CSTAT.R                 /* Current Status Register */
#define CRC_1_OUTP           CRC_1.OUTP.R                  /* Output Register */

/* FCCU part */
#define SAF_FCCU_INSTANCE_COUNT                              (1U)
#define SAF_FCCU_INSTANCE                                    (0U)
#define SAF_FCCU_RF_NO_RESET_STATE_0                         (0U)
#define SAF_FCCU_RF_NO_RESET_STATE_3                         (3U)

#if defined(CCFC3007PT) || defined(CCFC3008PT)
#define SAF_FCCU_RF_TEST_RESERVED_FAULT_INDEX_LIST           {6, 7, 8, 27, 28}
#define SAF_FCCU_RF_TEST_NOT_BE_INJECTED_FAULT_INDEX_LIST    {3,6,12,18,19,20,21,22,23,24,28,36,39,43,54}
#define SAF_FCCU_ALL_RF_FAULT_INDEX_LIST                     { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, \
                                                              10, 11, 12, 13, 14, 15, 16, 17, 18, 19, \
                                                              20, 21, 22, 23, 24, 25, 26, 27, 28, 29, \
                                                              30, 31, 32, 33, 34, 35, 36, 37, 38, 39, \
                                                              40, 41, 42, 43, 44, 45, 46, 47, 48, 49, \
                                                              50, 51, 52, 53, 54, 55\
                                                             }
#define SAF_FCCU_RF_FAULT_ID_INDEX_COUNT                     (56U)
#elif defined(CCFC3007BC)
#define SAF_FCCU_RF_TEST_RESERVED_FAULT_INDEX_LIST           {6, 7, 8, 27, 28, 61, 65, 69, 70, 71, 72, 73}
#define SAF_FCCU_RF_TEST_NOT_BE_INJECTED_FAULT_INDEX_LIST    {6,12,18,19,20,21,22,23,24,28,36,54}
#define SAF_FCCU_ALL_RF_FAULT_INDEX_LIST                     { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, \
                                                              10, 11, 12, 13, 14, 15, 16, 17, 18, 19, \
                                                              20, 21, 22, 23, 24, 25, 26, 27, 28, 29, \
                                                              30, 31, 32, 33, 34, 35, 36, 37, 38, 39, \
                                                              40, 41, 42, 43, 44, 45, 46, 47, 48, 49, \
                                                              50, 51, 52, 53, 54, 55, 56, 57, 58, 59, \
                                                              60, 61, 62, 63, 64, 65, 66, 67, 68, 69, \
                                                              70, 71, 72, 73, 74\
                                                             }
#define SAF_FCCU_RF_FAULT_ID_INDEX_COUNT                     (75U)
#elif defined(CCFC3008PC) | defined(CCFC3008PCSN)
#define SAF_FCCU_RF_TEST_RESERVED_FAULT_INDEX_LIST           {12, 13, 27, 28, 62, 63, 64, 65, 66, 67, \
	                                                          68, 69, 70, 71, 72, 73, 74, 75, 76, 77, \
	                                                          78, 79\
	                                                         }
#define SAF_FCCU_RF_TEST_NOT_BE_INJECTED_FAULT_INDEX_LIST    {6,12,18,19,20,21,22,23,24,28,36,54}
#define SAF_FCCU_ALL_RF_FAULT_INDEX_LIST                     { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, \
                                                              10, 11, 12, 13, 14, 15, 16, 17, 18, 19, \
                                                              20, 21, 22, 23, 24, 25, 26, 27, 28, 29, \
                                                              30, 31, 32, 33, 34, 35, 36, 37, 38, 39, \
                                                              40, 41, 42, 43, 44, 45, 46, 47, 48, 49, \
                                                              50, 51, 52, 53, 54, 55, 56, 57, 58, 59, \
                                                              60, 61\
                                                             }
#define SAF_FCCU_RF_FAULT_ID_INDEX_COUNT                     (62U)
#elif defined(CCFC3012PT)
#define SAF_FCCU_RF_TEST_RESERVED_FAULT_INDEX_LIST           {6, 7, 8, 27}
#define SAF_FCCU_RF_TEST_NOT_BE_INJECTED_FAULT_INDEX_LIST    {3,6,12,13,18,19,20,21,22,23,24,28,36,48,49,54,56,57,58,59,60,61}
#define SAF_FCCU_ALL_RF_FAULT_INDEX_LIST                     { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, \
                                                              10, 11, 12, 13, 14, 15, 16, 17, 18, 19, \
                                                              20, 21, 22, 23, 24, 25, 26, 27, 28, 29, \
                                                              30, 31, 32, 33, 34, 35, 36, 37, 38, 39, \
                                                              40, 41, 42, 43, 44, 45, 46, 47, 48, 49, \
                                                              50, 51, 52, 53, 54, 55, 56, 57, 58, 59, \
                                                              60, 61, 62, 63, 64, 65, 66, 67, 68, 69, \
                                                              70, 71, 72, 73, 74, 75, 76, 77, 78, 79, \
                                                              80, 81, 82, 83, 84, 85, 86, 87, 88, 89, \
                                                              90, 91, 92, 93, 94\
                                                             }
#define SAF_FCCU_RF_FAULT_ID_INDEX_COUNT                     (95U)
#endif



/* FLASH part*/
#define SAF_FLASH_CORRECTABLE_BIT_ERR_FCCU_NCF_INDEX         (22U)
#define SAF_FLASH_UNCORRECTABLE_BIT_ERR_FCCU_NCF_INDEX       (23U)
#define SAF_FLASH_CE_BIT_ERR_FCCU_INDEX_LIST                 {SAF_FLASH_CORRECTABLE_BIT_ERR_FCCU_NCF_INDEX}
#define SAF_FLASH_UE_BIT_ERR_FCCU_INDEX_LIST                 {SAF_FLASH_UNCORRECTABLE_BIT_ERR_FCCU_NCF_INDEX}

#define SAF_FLASH_AI_LOWBLOCK_DEFAULT_SELECT                 (0xFFFU)
#define SAF_FLASH_AI_MIDBLOCK_DEFAULT_SELECT                 (0xFFU)
#define SAF_FLASH_AI_HIGHBLOCK_DEFAULT_SELECT                (0xFFU)
#define SAF_FLASH_AI_FIRST256BKBLOCK_DEFAULT_SELECT          (0xFFFFU)
#define SAF_FLASH_AI_SECOND256KBLOCK_DEFAULT_SELECT          (0x0U)

#define SAF_FLASH_DCF_START_ADDR                             (0x00400300U)
#define SAF_FLASH_DCF_HSM_START_ADDR                         (0x00400308U)
#define SAF_FLASH_DCF_SIZE_BYTES                             (0xD00U)
#define SAF_FLASH_DCF_HSM_SIZE_BYTES                         (0x40U)
#define SAF_FLASH_UTEST_BLOCK_LOCK_STATE                     (1)
#define SAF_FLASH_UTEST_BLOCK_UNLOCK_STATE                   (0)


/* Low Block */
#define LOW_BLOCK0_ADDR    0x00404000U     // block 0    P0 (BAF)
#define LOW_BLOCK1_ADDR    0x00FC0000U     // block 1    P0 (Normal Code)
#define LOW_BLOCK2_ADDR    0x00FC4000U     // block 2    P0 (Normal Code)
#define LOW_BLOCK3_ADDR    0x00FC8000U     // block 3    P1 (Normal Code)
#define LOW_BLOCK4_ADDR    0x00FCC000U     // block 4    P1 (Normal Code)
#define LOW_BLOCK5_ADDR    0x0060C000U     // block 5    P1 (HSM Code)
#define LOW_BLOCK6_ADDR    0x00FD0000U     // block 6    P0 (Normal Code)
#define LOW_BLOCK7_ADDR    0x00FD8000U     // block 7    P1 (Normal Code)
#define LOW_BLOCK8_ADDR    0x00FE0000U     // block 8    P0 (Normal Code)
#define LOW_BLOCK9_ADDR    0x00FF0000U     // block 9    P0 (Normal Code)
#define LOW_BLOCK10_ADDR   0x00610000U     // block 10   P1 (HSM Code)
#define LOW_BLOCK11_ADDR   0x00620000U     // block 11   P1 (HSM Code)

/* Mid Block */
#if defined(CCFC3012PT)
#define MID_BLOCK0_ADDR    0x006C0000U     // block 12   P0 (HSM Data)
#define MID_BLOCK1_ADDR    0x006C4000U     // block 13   P0 (HSM Data)
#define MID_BLOCK2_ADDR    0x006C8000U     // block 14   P0 (HSM Data)
#define MID_BLOCK3_ADDR    0x006CC000U     // block 15   P1 (HSM Data)
#define MID_BLOCK4_ADDR    0x006D0000U     // block 16   P1 (HSM Data)
#define MID_BLOCK5_ADDR    0x006D4000U     // block 17   P1 (HSM Data)
#elif !defined(CCFC3007BC)
#define MID_BLOCK0_ADDR    0x00680000U     // block 12   P2 (HSM Data)
#define MID_BLOCK1_ADDR    0x00684000U     // block 13   P2 (HSM Data)
#define MID_BLOCK2_ADDR    0x00688000U     // block 14   P2 (HSM Data)
#define MID_BLOCK3_ADDR    0x0068C000U     // block 15   P2 (HSM Data)
#define MID_BLOCK4_ADDR    0x00690000U     // block 16   P2 (HSM Data)
#define MID_BLOCK5_ADDR    0x00698000U     // block 17   P2 (HSM Data)
#define MID_BLOCK6_ADDR    0x006A0000U     // block 18   P2 (HSM Data)
#define MID_BLOCK7_ADDR    0x006B0000U     // block 19   P2 (HSM Data)
#elif defined(CCFC3007BC)
#define MID_BLOCK0_ADDR    0x006C0000U     // block 12   P0 (Normal Code)
#define MID_BLOCK1_ADDR    0x006CC000U     // block 13   P1 (Normal Code)
#endif

/* High Block */
#define HIGH_BLOCK0_ADDR   0x00800000U     // block 20   P3 (EEPROM)    3007BC: block 12    3012PT: block 18
#define HIGH_BLOCK1_ADDR   0x00810000U     // block 21   P3 (EEPROM)    3007BC: block 13    3012PT: block 19
#define HIGH_BLOCK2_ADDR   0x00820000U     // block 22   P3 (EEPROM)    3007BC: block 14    3012PT: block 20
#define HIGH_BLOCK3_ADDR   0x00830000U     // block 23   P3 (EEPROM)    3007BC: block 15    3012PT: block 21
#define HIGH_BLOCK4_ADDR   0x00840000U     // block 24   P3 (EEPROM)    3007BC: block 16    3012PT: block 22
#define HIGH_BLOCK5_ADDR   0x00850000U     // block 25   P3 (EEPROM)    3007BC: block 17    3012PT: block 23
#define HIGH_BLOCK6_ADDR   0x00860000U     // block 26   P3 (EEPROM)    3007BC: block 18    3012PT: block 24
#define HIGH_BLOCK7_ADDR   0x00870000U     // block 27   P3 (EEPROM)    3007BC: block 19    3012PT: block 25
#if defined(CCFC3012PT)
#define HIGH_BLOCK8_ADDR   0x00880000U     // block 26   P3 (EEPROM)
#define HIGH_BLOCK9_ADDR   0x00890000U     // block 27   P3 (EEPROM)
#define HIGH_BLOCK10_ADDR   0x008A0000U    // block 28   P3 (EEPROM)
#define HIGH_BLOCK11_ADDR   0x008B0000U    // block 29   P3 (EEPROM)
#define HIGH_BLOCK12_ADDR   0x008C0000U    // block 30   P3 (EEPROM)
#define HIGH_BLOCK13_ADDR   0x008D0000U    // block 31   P3 (EEPROM)
#define HIGH_BLOCK14_ADDR   0x008E0000U    // block 32   P3 (EEPROM)
#define HIGH_BLOCK15_ADDR   0x008F0000U    // block 33   P3 (EEPROM)
#endif

/* 256K Block */
#define N256K_BLOCK0_ADDR  0x01000000U     // block 28   P4    3007BC: block 20    3012PT: block 34 P4
#define N256K_BLOCK1_ADDR  0x01040000U     // block 29   P4    3007BC: block 21    3012PT: block 35 P4
#define N256K_BLOCK2_ADDR  0x01080000U     // block 30   P4    3007BC: block 22    3012PT: block 36 P5
#define N256K_BLOCK3_ADDR  0x010C0000U     // block 31   P4    3007BC: block 23    3012PT: block 37 P5
#define N256K_BLOCK4_ADDR  0x01100000U     // block 32   P4    3007BC: block 24    3012PT: block 38 P5
#define N256K_BLOCK5_ADDR  0x01140000U     // block 33   P4    3007BC: block 25    3012PT: block 39 P5
#define N256K_BLOCK6_ADDR  0x01180000U     // block 34   P4    3007BC: block 26    3012PT: block 40 P5
#define N256K_BLOCK7_ADDR  0x011C0000U     // block 35   P4    3007BC: block 27    3012PT: block 41 P5
#define N256K_BLOCK8_ADDR  0x01200000U     // block 36   P5    3007BC: block 28    3012PT: block 42 P5
#define N256K_BLOCK9_ADDR  0x01240000U     // block 37   P5    3007BC: block 29    3012PT: block 43 P5
#define N256K_BLOCK10_ADDR  0x01280000U    // block 38   P5    3007BC: block 30    3012PT: block 44 P6
#define N256K_BLOCK11_ADDR  0x012C0000U    // block 39   P5    3007BC: block 31    3012PT: block 45 P6
#define N256K_BLOCK12_ADDR  0x01300000U    // block 40   P5    3007BC: block 32    3012PT: block 46 P6
#define N256K_BLOCK13_ADDR  0x01340000U    // block 41   P5    3007BC: block 33    3012PT: block 47 P6
#define N256K_BLOCK14_ADDR  0x01380000U    // block 42   P5    3007BC: block 34    3012PT: block 48 P6
#define N256K_BLOCK15_ADDR  0x013C0000U    // block 43   P5    3007BC: block 35    3012PT: block 49 P6
#if defined(CCFC3008PT) | defined(CCFC3008PC) | defined(CCFC3008PCSN)
#else
#define N256K_BLOCK16_ADDR 0x01400000U     // block 44   P6    3007BC: block 36    3012PT: block 50 P6
#define N256K_BLOCK17_ADDR 0x01440000U     // block 45   P6    3007BC: block 37    3012PT: block 51 P6
#define N256K_BLOCK18_ADDR 0x01480000U     // block 46   P6    3007BC: block 38    3012PT: block 52 P7
#define N256K_BLOCK19_ADDR 0x014C0000U     // block 47   P6    3007BC: block 39    3012PT: block 53 P7
#define N256K_BLOCK20_ADDR 0x01500000U     // block 48   P6    3007BC: block 40    3012PT: block 54 P7
#define N256K_BLOCK21_ADDR 0x01540000U     // block 49   P6    3007BC: block 41    3012PT: block 55 P7
#define N256K_BLOCK22_ADDR 0x01580000U     // block 50   P6    3007BC: block 42    3012PT: block 56 P7
#define N256K_BLOCK23_ADDR 0x015C0000U     // block 51   P6    3007BC: block 43    3012PT: block 57 P7
#define N256K_BLOCK24_ADDR 0x01600000U     // block 52   P7    3007BC: block 44    3012PT: block 58 P7
#define N256K_BLOCK25_ADDR 0x01640000U     // block 53   P7    3007BC: block 45    3012PT: block 59 P7
#define N256K_BLOCK26_ADDR 0x01680000U     // block 54   P7    3007BC: block 46    3012PT: block 60 P8
#define N256K_BLOCK27_ADDR 0x016C0000U     // block 55   P7    3007BC: block 47    3012PT: block 61 P8
#define N256K_BLOCK28_ADDR 0x01700000U     // block 56   P7    3007BC: block 48    3012PT: block 62 P8
#define N256K_BLOCK29_ADDR 0x01740000U     // block 57   P7    3007BC: block 49    3012PT: block 63 P8
#define N256K_BLOCK30_ADDR 0x01780000U     // block 58   P7    3007BC: block 50    3012PT: block 64 P8
#define N256K_BLOCK31_ADDR 0x017C0000U     // block 59   P7    3007BC: block 51    3012PT: block 65 P8
#if defined(CCFC3007PT) || defined(CCFC3012PT)
/* second */
#define N256K_BLOCK32_ADDR 0x01800000U     // block 60   P8    3012PT: block 66 P8
#define N256K_BLOCK33_ADDR 0x01840000U     // block 61   P8    3012PT: block 67 P8
#define N256K_BLOCK34_ADDR 0x01880000U     // block 62   P8    3012PT: block 68 P9
#define N256K_BLOCK35_ADDR 0x018C0000U     // block 63   P8    3012PT: block 69 P9
#define N256K_BLOCK36_ADDR 0x01900000U     // block 64   P8    3012PT: block 70 P9
#define N256K_BLOCK37_ADDR 0x01940000U     // block 65   P8    3012PT: block 71 P9
#define N256K_BLOCK38_ADDR 0x01980000U     // block 66   P8    3012PT: block 72 P9
#define N256K_BLOCK39_ADDR 0x019C0000U     // block 67   P8    3012PT: block 73 P9
#define N256K_BLOCK40_ADDR 0x01A00000U     // block 68   P9    3012PT: block 74 P9
#define N256K_BLOCK41_ADDR 0x01A40000U     // block 69   P9    3012PT: block 75 P9
#define N256K_BLOCK42_ADDR 0x01A80000U     // block 70   P9    3012PT: block 76 P9
#define N256K_BLOCK43_ADDR 0x01AC0000U     // block 71   P9    3012PT: block 77 P9
#define N256K_BLOCK44_ADDR 0x01B00000U     // block 72   P9    3012PT: block 78 P9
#define N256K_BLOCK45_ADDR 0x01B40000U     // block 73   P9    3012PT: block 79 P9
#define N256K_BLOCK46_ADDR 0x01B80000U     // block 74   P9    3012PT: block 80 P9
#define N256K_BLOCK47_ADDR 0x01BC0000U     // block 75   P9    3012PT: block 81 P9
#endif
#if defined(CCFC3012PT)
#define N256K_BLOCK48_ADDR 0x01C00000U     // block 82   P9
#define N256K_BLOCK49_ADDR 0x01C40000U     // block 83   P9
#define N256K_BLOCK50_ADDR 0x01C80000U     // block 84   P9
#define N256K_BLOCK51_ADDR 0x01CC0000U     // block 85   P9
#define N256K_BLOCK52_ADDR 0x01D00000U     // block 86   P9
#define N256K_BLOCK53_ADDR 0x01D40000U     // block 87   P9
#define N256K_BLOCK54_ADDR 0x01D80000U     // block 88   P9
#define N256K_BLOCK55_ADDR 0x01DC0000U     // block 89   P9
#define N256K_BLOCK56_ADDR 0x01E00000U     // block 90   P9
#define N256K_BLOCK57_ADDR 0x01E40000U     // block 91   P9
#define N256K_BLOCK58_ADDR 0x01E80000U     // block 92   P9
#define N256K_BLOCK59_ADDR 0x01EC0000U     // block 93   P9
#define N256K_BLOCK60_ADDR 0x01F00000U     // block 94   P9
#define N256K_BLOCK61_ADDR 0x01F40000U     // block 95   P9
#define N256K_BLOCK62_ADDR 0x01F80000U     // block 96   P9
#define N256K_BLOCK63_ADDR 0x01FC0000U     // block 97   P9
#define N256K_BLOCK64_ADDR 0x02000000U     // block 98   P9
#define N256K_BLOCK65_ADDR 0x02040000U     // block 99   P9
#endif

#endif

#if defined(CCFC3007PT)
#define FLASH_BLOCK_ADDR_DEFINE \
{                               \
    LOW_BLOCK0_ADDR,   /* block 0    P0 (BAF)             */ \
    LOW_BLOCK1_ADDR,   /* block 1    P0 (Normal Code)     */ \
    LOW_BLOCK2_ADDR,   /* block 2    P0 (Normal Code)     */ \
    LOW_BLOCK3_ADDR,   /* block 3    P1 (Normal Code)     */ \
    LOW_BLOCK4_ADDR,   /* block 4    P1 (Normal Code)     */ \
    LOW_BLOCK5_ADDR,   /* block 5    P1 (HSM Code)        */ \
    LOW_BLOCK6_ADDR,   /* block 6    P0 (Normal Code)     */ \
    LOW_BLOCK7_ADDR,   /* block 7    P1 (Normal Code)     */ \
    LOW_BLOCK8_ADDR,   /* block 8    P0 (Normal Code)     */ \
    LOW_BLOCK9_ADDR,   /* block 9    P0 (Normal Code)     */ \
    LOW_BLOCK10_ADDR,  /* block 10   P1 (HSM Code)        */ \
    LOW_BLOCK11_ADDR,  /* block 11   P1 (HSM Code)        */ \
    MID_BLOCK0_ADDR,   /* block 12   P2 (HSM Data)        */ \
    MID_BLOCK1_ADDR,   /* block 13   P2 (HSM Data)        */ \
    MID_BLOCK2_ADDR,   /* block 14   P2 (HSM Data)        */ \
    MID_BLOCK3_ADDR,   /* block 15   P2 (HSM Data)        */ \
    MID_BLOCK4_ADDR,   /* block 16   P2 (HSM Data)        */ \
    MID_BLOCK5_ADDR,   /* block 17   P2 (HSM Data)        */ \
    MID_BLOCK6_ADDR,   /* block 18   P2 (HSM Data)        */ \
    MID_BLOCK7_ADDR,   /* block 19   P2 (HSM Data)        */ \
    HIGH_BLOCK0_ADDR,  /* block 20   P3 (EEPROM)          */ \
    HIGH_BLOCK1_ADDR,  /* block 21   P3 (EEPROM)          */ \
    HIGH_BLOCK2_ADDR,  /* block 22   P3 (EEPROM)          */ \
    HIGH_BLOCK3_ADDR,  /* block 23   P3 (EEPROM)          */ \
    HIGH_BLOCK4_ADDR,  /* block 24   P3 (EEPROM)          */ \
    HIGH_BLOCK5_ADDR,  /* block 25   P3 (EEPROM)          */ \
    HIGH_BLOCK6_ADDR,  /* block 26   P3 (EEPROM)          */ \
    HIGH_BLOCK7_ADDR,  /* block 27   P3 (EEPROM)          */ \
    N256K_BLOCK0_ADDR, /* block 28   P4                   */ \
    N256K_BLOCK1_ADDR, /* block 29   P4                   */ \
    N256K_BLOCK2_ADDR, /* block 30   P4                   */ \
    N256K_BLOCK3_ADDR, /* block 31   P4                   */ \
    N256K_BLOCK4_ADDR, /* block 32   P4                   */ \
    N256K_BLOCK5_ADDR, /* block 33   P4                   */ \
    N256K_BLOCK6_ADDR, /* block 34   P4                   */ \
    N256K_BLOCK7_ADDR, /* block 35   P4                   */ \
    N256K_BLOCK8_ADDR, /* block 36   P5                   */ \
    N256K_BLOCK9_ADDR, /* block 37   P5                   */ \
    N256K_BLOCK10_ADDR, /* block 38   P5                   */ \
    N256K_BLOCK11_ADDR, /* block 39   P5                   */ \
    N256K_BLOCK12_ADDR, /* block 40   P5                   */ \
    N256K_BLOCK13_ADDR, /* block 41   P5                   */ \
    N256K_BLOCK14_ADDR, /* block 42   P5                   */ \
    N256K_BLOCK15_ADDR, /* block 43   P5                   */ \
    N256K_BLOCK16_ADDR, /* block 44   P6                   */ \
    N256K_BLOCK17_ADDR, /* block 45   P6                   */ \
    N256K_BLOCK18_ADDR, /* block 46   P6                   */ \
    N256K_BLOCK19_ADDR, /* block 47   P6                   */ \
    N256K_BLOCK20_ADDR, /* block 48   P6                   */ \
    N256K_BLOCK21_ADDR, /* block 49   P6                   */ \
    N256K_BLOCK22_ADDR, /* block 50   P6                   */ \
    N256K_BLOCK23_ADDR, /* block 51   P6                   */ \
    N256K_BLOCK24_ADDR, /* block 52   P7                   */ \
    N256K_BLOCK25_ADDR, /* block 53   P7                   */ \
    N256K_BLOCK26_ADDR, /* block 54   P7                   */ \
    N256K_BLOCK27_ADDR, /* block 55   P7                   */ \
    N256K_BLOCK28_ADDR, /* block 56   P7                   */ \
    N256K_BLOCK29_ADDR, /* block 57   P7                   */ \
    N256K_BLOCK30_ADDR, /* block 58   P7                   */ \
    N256K_BLOCK31_ADDR, /* block 59   P7                   */ \
    N256K_BLOCK32_ADDR, /* block 60   P8                   */ \
    N256K_BLOCK33_ADDR, /* block 61   P8                   */ \
    N256K_BLOCK34_ADDR, /* block 62   P8                   */ \
    N256K_BLOCK35_ADDR, /* block 63   P8                   */ \
    N256K_BLOCK36_ADDR, /* block 64   P8                   */ \
    N256K_BLOCK37_ADDR, /* block 65   P8                   */ \
    N256K_BLOCK38_ADDR, /* block 66   P8                   */ \
    N256K_BLOCK39_ADDR, /* block 67   P8                   */ \
    N256K_BLOCK40_ADDR, /* block 68   P9                   */ \
    N256K_BLOCK41_ADDR, /* block 69   P9                   */ \
    N256K_BLOCK42_ADDR, /* block 70   P9                   */ \
    N256K_BLOCK43_ADDR, /* block 71   P9                   */ \
    N256K_BLOCK44_ADDR, /* block 72   P9                   */ \
    N256K_BLOCK45_ADDR, /* block 73   P9                   */ \
    N256K_BLOCK46_ADDR, /* block 74   P9                   */ \
    N256K_BLOCK47_ADDR  /* block 75   P9                   */ \
}
#elif defined(CCFC3007BC)
#define FLASH_BLOCK_ADDR_DEFINE \
{                               \
    LOW_BLOCK0_ADDR,   /* block 0    P0 (BAF)             */ \
    LOW_BLOCK1_ADDR,   /* block 1    P0 (Normal Code)     */ \
    LOW_BLOCK2_ADDR,   /* block 2    P0 (Normal Code)     */ \
    LOW_BLOCK3_ADDR,   /* block 3    P1 (Normal Code)     */ \
    LOW_BLOCK4_ADDR,   /* block 4    P1 (Normal Code)     */ \
    LOW_BLOCK5_ADDR,   /* block 5    P1 (HSM Code)        */ \
    LOW_BLOCK6_ADDR,   /* block 6    P0 (Normal Code)     */ \
    LOW_BLOCK7_ADDR,   /* block 7    P1 (Normal Code)     */ \
    LOW_BLOCK8_ADDR,   /* block 8    P0 (Normal Code)     */ \
    LOW_BLOCK9_ADDR,   /* block 9    P0 (Normal Code)     */ \
    LOW_BLOCK10_ADDR,  /* block 10   P1 (HSM Code)        */ \
    LOW_BLOCK11_ADDR,  /* block 11   P1 (HSM Code)        */ \
	MID_BLOCK0_ADDR,   /* block 12   P0 (Normal Code)     */ \
	MID_BLOCK1_ADDR,   /* block 13   P1 (Normal Code)     */ \
    HIGH_BLOCK0_ADDR,  /* block 14   P3 (EEPROM)          */ \
    HIGH_BLOCK1_ADDR,  /* block 15   P3 (EEPROM)          */ \
    HIGH_BLOCK2_ADDR,  /* block 16   P3 (EEPROM)          */ \
    HIGH_BLOCK3_ADDR,  /* block 17   P3 (EEPROM)          */ \
    HIGH_BLOCK4_ADDR,  /* block 18   P3 (EEPROM)          */ \
    HIGH_BLOCK5_ADDR,  /* block 19   P3 (EEPROM)          */ \
    HIGH_BLOCK6_ADDR,  /* block 20   P3 (EEPROM)          */ \
    HIGH_BLOCK7_ADDR,  /* block 21   P3 (EEPROM)          */ \
    N256K_BLOCK0_ADDR, /* block 22   P4                   */ \
    N256K_BLOCK1_ADDR, /* block 23   P4                   */ \
    N256K_BLOCK2_ADDR, /* block 24   P4                   */ \
    N256K_BLOCK3_ADDR, /* block 25   P4                   */ \
    N256K_BLOCK4_ADDR, /* block 26   P4                   */ \
    N256K_BLOCK5_ADDR, /* block 27   P4                   */ \
    N256K_BLOCK6_ADDR, /* block 28   P4                   */ \
    N256K_BLOCK7_ADDR, /* block 29   P4                   */ \
    N256K_BLOCK8_ADDR, /* block 30   P4                   */ \
    N256K_BLOCK9_ADDR, /* block 31   P4                   */ \
    N256K_BLOCK10_ADDR, /* block 32   P4                   */ \
    N256K_BLOCK11_ADDR, /* block 33   P4                   */ \
    N256K_BLOCK12_ADDR, /* block 34   P4                   */ \
    N256K_BLOCK13_ADDR, /* block 35   P4                   */ \
    N256K_BLOCK14_ADDR, /* block 36   P4                   */ \
    N256K_BLOCK15_ADDR, /* block 37   P4                   */ \
    N256K_BLOCK16_ADDR, /* block 38   P5                   */ \
    N256K_BLOCK17_ADDR, /* block 39   P5                   */ \
    N256K_BLOCK18_ADDR, /* block 40   P5                   */ \
    N256K_BLOCK19_ADDR, /* block 41   P5                   */ \
    N256K_BLOCK20_ADDR, /* block 42   P5                   */ \
    N256K_BLOCK21_ADDR, /* block 43   P5                   */ \
    N256K_BLOCK22_ADDR, /* block 44   P5                   */ \
    N256K_BLOCK23_ADDR, /* block 45   P5                   */ \
    N256K_BLOCK24_ADDR, /* block 46   P5                   */ \
    N256K_BLOCK25_ADDR, /* block 47   P5                   */ \
    N256K_BLOCK26_ADDR, /* block 48   P5                   */ \
    N256K_BLOCK27_ADDR, /* block 49   P5                   */ \
    N256K_BLOCK28_ADDR, /* block 50   P5                   */ \
    N256K_BLOCK29_ADDR, /* block 51   P5                   */ \
    N256K_BLOCK30_ADDR, /* block 52   P5                   */ \
    N256K_BLOCK31_ADDR, /* block 53   P5                   */ \
}
#elif defined(CCFC3008PT)
#define FLASH_BLOCK_ADDR_DEFINE \
{                               \
    LOW_BLOCK0_ADDR,   /* block 0    P0 (BAF)             */ \
    LOW_BLOCK1_ADDR,   /* block 1    P0 (Normal Code)     */ \
    LOW_BLOCK2_ADDR,   /* block 2    P0 (Normal Code)     */ \
    LOW_BLOCK3_ADDR,   /* block 3    P1 (Normal Code)     */ \
    LOW_BLOCK4_ADDR,   /* block 4    P1 (Normal Code)     */ \
    LOW_BLOCK5_ADDR,   /* block 5    P1 (HSM Code)        */ \
    LOW_BLOCK6_ADDR,   /* block 6    P0 (Normal Code)     */ \
    LOW_BLOCK7_ADDR,   /* block 7    P1 (Normal Code)     */ \
    LOW_BLOCK8_ADDR,   /* block 8    P0 (Normal Code)     */ \
    LOW_BLOCK9_ADDR,   /* block 9    P0 (Normal Code)     */ \
    LOW_BLOCK10_ADDR,  /* block 10   P1 (HSM Code)        */ \
    LOW_BLOCK11_ADDR,  /* block 11   P1 (HSM Code)        */ \
    MID_BLOCK0_ADDR,   /* block 12   P2 (HSM Data)        */ \
    MID_BLOCK1_ADDR,   /* block 13   P2 (HSM Data)        */ \
    MID_BLOCK2_ADDR,   /* block 14   P2 (HSM Data)        */ \
    MID_BLOCK3_ADDR,   /* block 15   P2 (HSM Data)        */ \
    MID_BLOCK4_ADDR,   /* block 16   P2 (HSM Data)        */ \
    MID_BLOCK5_ADDR,   /* block 17   P2 (HSM Data)        */ \
    MID_BLOCK6_ADDR,   /* block 18   P2 (HSM Data)        */ \
    MID_BLOCK7_ADDR,   /* block 19   P2 (HSM Data)        */ \
    HIGH_BLOCK0_ADDR,  /* block 20   P3 (EEPROM)          */ \
    HIGH_BLOCK1_ADDR,  /* block 21   P3 (EEPROM)          */ \
    HIGH_BLOCK2_ADDR,  /* block 22   P3 (EEPROM)          */ \
    HIGH_BLOCK3_ADDR,  /* block 23   P3 (EEPROM)          */ \
    HIGH_BLOCK4_ADDR,  /* block 24   P3 (EEPROM)          */ \
    HIGH_BLOCK5_ADDR,  /* block 25   P3 (EEPROM)          */ \
    HIGH_BLOCK6_ADDR,  /* block 26   P3 (EEPROM)          */ \
    HIGH_BLOCK7_ADDR,  /* block 27   P3 (EEPROM)          */ \
    N256K_BLOCK0_ADDR, /* block 28   P4                   */ \
    N256K_BLOCK1_ADDR, /* block 29   P4                   */ \
    N256K_BLOCK2_ADDR, /* block 30   P4                   */ \
    N256K_BLOCK3_ADDR, /* block 31   P4                   */ \
    N256K_BLOCK4_ADDR, /* block 32   P4                   */ \
    N256K_BLOCK5_ADDR, /* block 33   P4                   */ \
    N256K_BLOCK6_ADDR, /* block 34   P4                   */ \
    N256K_BLOCK7_ADDR, /* block 35   P4                   */ \
    N256K_BLOCK8_ADDR, /* block 36   P5                   */ \
    N256K_BLOCK9_ADDR, /* block 37   P5                   */ \
    N256K_BLOCK10_ADDR,/* block 38   P5                   */ \
    N256K_BLOCK11_ADDR,/* block 39   P5                   */ \
    N256K_BLOCK12_ADDR,/* block 40   P5                   */ \
    N256K_BLOCK13_ADDR,/* block 41   P5                   */ \
    N256K_BLOCK14_ADDR,/* block 42   P5                   */ \
    N256K_BLOCK15_ADDR /* block 43   P5                   */ \
}
#elif defined(CCFC3008PC) | defined(CCFC3008PCSN)
#define FLASH_BLOCK_ADDR_DEFINE \
{                               \
    LOW_BLOCK0_ADDR,   /* block 0    P0 (BAF)             */ \
    LOW_BLOCK1_ADDR,   /* block 1    P0 (Normal Code)     */ \
    LOW_BLOCK2_ADDR,   /* block 2    P0 (Normal Code)     */ \
    LOW_BLOCK3_ADDR,   /* block 3    P1 (Normal Code)     */ \
    LOW_BLOCK4_ADDR,   /* block 4    P1 (Normal Code)     */ \
    LOW_BLOCK5_ADDR,   /* block 5    P1 (HSM Code)        */ \
    LOW_BLOCK6_ADDR,   /* block 6    P0 (Normal Code)     */ \
    LOW_BLOCK7_ADDR,   /* block 7    P1 (Normal Code)     */ \
    LOW_BLOCK8_ADDR,   /* block 8    P0 (Normal Code)     */ \
    LOW_BLOCK9_ADDR,   /* block 9    P0 (Normal Code)     */ \
    LOW_BLOCK10_ADDR,  /* block 10   P1 (HSM Code)        */ \
    LOW_BLOCK11_ADDR,  /* block 11   P1 (HSM Code)        */ \
    MID_BLOCK0_ADDR,   /* block 12   P2 (HSM Data)        */ \
    MID_BLOCK1_ADDR,   /* block 13   P2 (HSM Data)        */ \
    MID_BLOCK2_ADDR,   /* block 14   P2 (HSM Data)        */ \
    MID_BLOCK3_ADDR,   /* block 15   P2 (HSM Data)        */ \
    MID_BLOCK4_ADDR,   /* block 16   P2 (HSM Data)        */ \
    MID_BLOCK5_ADDR,   /* block 17   P2 (HSM Data)        */ \
    MID_BLOCK6_ADDR,   /* block 18   P2 (HSM Data)        */ \
    MID_BLOCK7_ADDR,   /* block 19   P2 (HSM Data)        */ \
    HIGH_BLOCK0_ADDR,  /* block 20   P3 (EEPROM)          */ \
    HIGH_BLOCK1_ADDR,  /* block 21   P3 (EEPROM)          */ \
    HIGH_BLOCK2_ADDR,  /* block 22   P3 (EEPROM)          */ \
    HIGH_BLOCK3_ADDR,  /* block 23   P3 (EEPROM)          */ \
    HIGH_BLOCK4_ADDR,  /* block 24   P3 (EEPROM)          */ \
    HIGH_BLOCK5_ADDR,  /* block 25   P3 (EEPROM)          */ \
    HIGH_BLOCK6_ADDR,  /* block 26   P3 (EEPROM)          */ \
    HIGH_BLOCK7_ADDR,  /* block 27   P3 (EEPROM)          */ \
    N256K_BLOCK0_ADDR, /* block 28   P4                   */ \
    N256K_BLOCK1_ADDR, /* block 29   P4                   */ \
    N256K_BLOCK2_ADDR, /* block 30   P4                   */ \
    N256K_BLOCK3_ADDR, /* block 31   P4                   */ \
    N256K_BLOCK4_ADDR, /* block 32   P4                   */ \
    N256K_BLOCK5_ADDR, /* block 33   P4                   */ \
    N256K_BLOCK6_ADDR, /* block 34   P4                   */ \
    N256K_BLOCK7_ADDR, /* block 35   P4                   */ \
    N256K_BLOCK8_ADDR, /* block 36   P5                   */ \
    N256K_BLOCK9_ADDR, /* block 37   P5                   */ \
    N256K_BLOCK10_ADDR,/* block 38   P5                   */ \
    N256K_BLOCK11_ADDR,/* block 39   P5                   */ \
    N256K_BLOCK12_ADDR,/* block 40   P5                   */ \
    N256K_BLOCK13_ADDR,/* block 41   P5                   */ \
    N256K_BLOCK14_ADDR,/* block 42   P5                   */ \
    N256K_BLOCK15_ADDR /* block 43   P5                   */ \
}
#elif defined(CCFC3012PT)
#define FLASH_BLOCK_ADDR_DEFINE \
{                               \
    LOW_BLOCK0_ADDR,   /* block 0    P0 (BAF)             */ \
    LOW_BLOCK1_ADDR,   /* block 1    P0 (Normal Code)     */ \
    LOW_BLOCK2_ADDR,   /* block 2    P0 (Normal Code)     */ \
    LOW_BLOCK3_ADDR,   /* block 3    P1 (Normal Code)     */ \
    LOW_BLOCK4_ADDR,   /* block 4    P1 (Normal Code)     */ \
    LOW_BLOCK5_ADDR,   /* block 5    P1 (HSM Code)        */ \
    LOW_BLOCK6_ADDR,   /* block 6    P0 (Normal Code)     */ \
    LOW_BLOCK7_ADDR,   /* block 7    P1 (Normal Code)     */ \
    LOW_BLOCK8_ADDR,   /* block 8    P0 (Normal Code)     */ \
    LOW_BLOCK9_ADDR,   /* block 9    P0 (Normal Code)     */ \
    LOW_BLOCK10_ADDR,  /* block 10   P1 (HSM Code)        */ \
    LOW_BLOCK11_ADDR,  /* block 11   P1 (HSM Code)        */ \
    MID_BLOCK0_ADDR,   /* block 12   P0 (HSM Data)        */ \
    MID_BLOCK1_ADDR,   /* block 13   P0 (HSM Data)        */ \
    MID_BLOCK2_ADDR,   /* block 14   P0 (HSM Data)        */ \
    MID_BLOCK3_ADDR,   /* block 15   P1 (HSM Data)        */ \
    MID_BLOCK4_ADDR,   /* block 16   P1 (HSM Data)        */ \
    MID_BLOCK5_ADDR,   /* block 17   P1 (HSM Data)        */ \
    HIGH_BLOCK0_ADDR,  /* block 18   P3 (EEPROM)          */ \
    HIGH_BLOCK1_ADDR,  /* block 19   P3 (EEPROM)          */ \
    HIGH_BLOCK2_ADDR,  /* block 20   P3 (EEPROM)          */ \
    HIGH_BLOCK3_ADDR,  /* block 21   P3 (EEPROM)          */ \
    HIGH_BLOCK4_ADDR,  /* block 22   P3 (EEPROM)          */ \
    HIGH_BLOCK5_ADDR,  /* block 23   P3 (EEPROM)          */ \
    HIGH_BLOCK6_ADDR,  /* block 24   P3 (EEPROM)          */ \
    HIGH_BLOCK7_ADDR,  /* block 25   P3 (EEPROM)          */ \
    HIGH_BLOCK8_ADDR,  /* block 26   P3 (EEPROM)          */ \
    HIGH_BLOCK9_ADDR,  /* block 27   P3 (EEPROM)          */ \
    HIGH_BLOCK10_ADDR,  /* block 28   P3 (EEPROM)          */ \
    HIGH_BLOCK11_ADDR,  /* block 29   P3 (EEPROM)          */ \
    HIGH_BLOCK12_ADDR,  /* block 30   P3 (EEPROM)          */ \
    HIGH_BLOCK13_ADDR,  /* block 31   P3 (EEPROM)          */ \
    HIGH_BLOCK14_ADDR,  /* block 32   P3 (EEPROM)          */ \
    HIGH_BLOCK15_ADDR,  /* block 33   P3 (EEPROM)          */ \
    N256K_BLOCK0_ADDR, /* block 34   P4                   */ \
    N256K_BLOCK1_ADDR, /* block 35   P4                   */ \
    N256K_BLOCK2_ADDR, /* block 36   P5                   */ \
    N256K_BLOCK3_ADDR, /* block 37   P5                   */ \
    N256K_BLOCK4_ADDR, /* block 38   P5                   */ \
    N256K_BLOCK5_ADDR, /* block 39   P5                   */ \
    N256K_BLOCK6_ADDR, /* block 40   P5                   */ \
    N256K_BLOCK7_ADDR, /* block 41   P5                   */ \
    N256K_BLOCK8_ADDR, /* block 42   P5                   */ \
    N256K_BLOCK9_ADDR, /* block 43   P5                   */ \
    N256K_BLOCK10_ADDR, /* block 44   P6                   */ \
    N256K_BLOCK11_ADDR, /* block 45   P6                   */ \
    N256K_BLOCK12_ADDR, /* block 46   P6                   */ \
    N256K_BLOCK13_ADDR, /* block 47   P6                   */ \
    N256K_BLOCK14_ADDR, /* block 48   P6                   */ \
    N256K_BLOCK15_ADDR, /* block 49   P6                   */ \
    N256K_BLOCK16_ADDR, /* block 50   P6                   */ \
    N256K_BLOCK17_ADDR, /* block 51   P6                   */ \
    N256K_BLOCK18_ADDR, /* block 52   P7                   */ \
    N256K_BLOCK19_ADDR, /* block 53   P7                   */ \
    N256K_BLOCK20_ADDR, /* block 54   P7                   */ \
    N256K_BLOCK21_ADDR, /* block 55   P7                   */ \
    N256K_BLOCK22_ADDR, /* block 56   P7                   */ \
    N256K_BLOCK23_ADDR, /* block 57   P7                   */ \
    N256K_BLOCK24_ADDR, /* block 58   P7                   */ \
    N256K_BLOCK25_ADDR, /* block 59   P7                   */ \
    N256K_BLOCK26_ADDR, /* block 60   P8                   */ \
    N256K_BLOCK27_ADDR, /* block 61   P8                   */ \
    N256K_BLOCK28_ADDR, /* block 62   P8                   */ \
    N256K_BLOCK29_ADDR, /* block 63   P8                   */ \
    N256K_BLOCK30_ADDR, /* block 64   P8                   */ \
    N256K_BLOCK31_ADDR, /* block 65   P8                   */ \
    N256K_BLOCK32_ADDR, /* block 66   P8                   */ \
    N256K_BLOCK33_ADDR, /* block 67   P8                   */ \
    N256K_BLOCK34_ADDR, /* block 68   P9                   */ \
    N256K_BLOCK35_ADDR, /* block 69   P9                   */ \
    N256K_BLOCK36_ADDR, /* block 70   P9                   */ \
    N256K_BLOCK37_ADDR, /* block 71   P9                   */ \
    N256K_BLOCK38_ADDR, /* block 72   P9                   */ \
    N256K_BLOCK39_ADDR, /* block 73   P9                   */ \
    N256K_BLOCK40_ADDR, /* block 74   P9                   */ \
    N256K_BLOCK41_ADDR, /* block 75   P9                   */ \
    N256K_BLOCK42_ADDR, /* block 76   P9                   */ \
    N256K_BLOCK43_ADDR, /* block 77   P9                   */ \
    N256K_BLOCK44_ADDR, /* block 78   P9                   */ \
    N256K_BLOCK45_ADDR, /* block 79   P9                   */ \
    N256K_BLOCK46_ADDR, /* block 80   P9                   */ \
    N256K_BLOCK47_ADDR, /* block 81   P9                   */ \
    N256K_BLOCK48_ADDR, /* block 82   P9                   */ \
    N256K_BLOCK49_ADDR, /* block 83   P9                   */ \
    N256K_BLOCK50_ADDR, /* block 84   P9                   */ \
    N256K_BLOCK51_ADDR, /* block 85   P9                   */ \
    N256K_BLOCK52_ADDR, /* block 86   P9                   */ \
    N256K_BLOCK53_ADDR, /* block 87   P9                   */ \
    N256K_BLOCK54_ADDR, /* block 88   P9                   */ \
    N256K_BLOCK55_ADDR, /* block 89   P9                   */ \
    N256K_BLOCK56_ADDR, /* block 90   P9                   */ \
    N256K_BLOCK57_ADDR, /* block 91   P9                   */ \
    N256K_BLOCK58_ADDR, /* block 92   P9                   */ \
    N256K_BLOCK59_ADDR, /* block 93   P9                   */ \
    N256K_BLOCK60_ADDR, /* block 94   P9                   */ \
    N256K_BLOCK61_ADDR, /* block 95   P9                   */ \
    N256K_BLOCK62_ADDR, /* block 96   P9                   */ \
    N256K_BLOCK63_ADDR, /* block 97   P9                   */ \
    N256K_BLOCK64_ADDR, /* block 98   P9                   */ \
    N256K_BLOCK65_ADDR  /* block 99   P9                   */ \
}
#endif

#define SAF_FLASH_SUPPORT_SECOND_LARGE_BLOCK                 (0U)
#define SAF_FLASH_C55_256KB_SIZE                             (0x40000UL)
#define SAF_FLASH_C55_64KB_SIZE                              FLS_64KB_SIZE
#define SAF_FLASH_C55_32KB_SIZE                              FLS_32KB_SIZE
#define SAF_FLASH_C55_16KB_SIZE                              FLS_16KB_SIZE
#define SAF_FLASH_BLOCK_START_ADDR_LIST                      FLASH_BLOCK_ADDR_DEFINE
#if defined(CCFC3007PT)
#define SAF_FLASH_BLOCK_MEMORY_SIZE_LIST                     { \
                                                                FLS_16KB_SIZE,    /* block 0    P0 (BAF)           */ \
                                                                FLS_16KB_SIZE,    /* block 1    P0 (Normal Code)   */ \
                                                                FLS_16KB_SIZE,    /* block 2    P0 (Normal Code)   */ \
                                                                FLS_16KB_SIZE,    /* block 3    P1 (Normal Code)   */ \
                                                                FLS_16KB_SIZE,    /* block 4    P1 (Normal Code)   */ \
                                                                FLS_16KB_SIZE,    /* block 5    P1 (HSM Code)      */ \
                                                                FLS_32KB_SIZE,    /* block 6    P0 (Normal Code)   */ \
                                                                FLS_32KB_SIZE,    /* block 7    P1 (Normal Code)   */ \
                                                                FLS_64KB_SIZE,    /* block 8    P0 (Normal Code)   */ \
                                                                FLS_64KB_SIZE,    /* block 9    P0 (Normal Code)   */ \
                                                                FLS_64KB_SIZE,    /* block 10   P1 (HSM Code)      */ \
                                                                FLS_64KB_SIZE,    /* block 11   P1 (HSM Code)      */ \
                                                                FLS_16KB_SIZE,    /* block 12   P2 (HSM Data)      */ \
                                                                FLS_16KB_SIZE,    /* block 13   P2 (HSM Data)      */ \
                                                                FLS_16KB_SIZE,    /* block 14   P2 (HSM Data)      */ \
                                                                FLS_16KB_SIZE,    /* block 15   P2 (HSM Data)      */ \
                                                                FLS_32KB_SIZE,    /* block 16   P2 (HSM Data)      */ \
                                                                FLS_32KB_SIZE,    /* block 17   P2 (HSM Data)      */ \
                                                                FLS_64KB_SIZE,    /* block 18   P2 (HSM Data)      */ \
                                                                FLS_64KB_SIZE,    /* block 19   P2 (HSM Data)      */ \
                                                                FLS_64KB_SIZE,    /* block 20   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 21   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 22   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 23   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 24   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 25   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 26   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 27   P3 (EEPROM)        */ \
                                                                FLS_256KB_SIZE,   /* block 28   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 29   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 30   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 31   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 32   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 33   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 34   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 35   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 36   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 37   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 38   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 39   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 40   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 41   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 42   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 43   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 44   P6       */ \
                                                                FLS_256KB_SIZE,   /* block 45   P6       */ \
                                                                FLS_256KB_SIZE,   /* block 46   P6       */ \
                                                                FLS_256KB_SIZE,   /* block 47   P6       */ \
                                                                FLS_256KB_SIZE,   /* block 48   P6       */ \
                                                                FLS_256KB_SIZE,   /* block 49   P6       */ \
                                                                FLS_256KB_SIZE,   /* block 50   P6       */ \
                                                                FLS_256KB_SIZE,   /* block 51   P6       */ \
                                                                FLS_256KB_SIZE,   /* block 52   P7       */ \
                                                                FLS_256KB_SIZE,   /* block 53   P7       */ \
                                                                FLS_256KB_SIZE,   /* block 54   P7       */ \
                                                                FLS_256KB_SIZE,   /* block 55   P7       */ \
                                                                FLS_256KB_SIZE,   /* block 56   P7       */ \
                                                                FLS_256KB_SIZE,   /* block 57   P7       */ \
                                                                FLS_256KB_SIZE,   /* block 58   P7       */ \
                                                                FLS_256KB_SIZE,   /* block 59   P7       */ \
                                                                FLS_256KB_SIZE,   /* block 60   P8       */ \
                                                                FLS_256KB_SIZE,   /* block 61   P8       */ \
                                                                FLS_256KB_SIZE,   /* block 62   P8       */ \
                                                                FLS_256KB_SIZE,   /* block 63   P8       */ \
                                                                FLS_256KB_SIZE,   /* block 64   P8       */ \
                                                                FLS_256KB_SIZE,   /* block 65   P8       */ \
                                                                FLS_256KB_SIZE,   /* block 66   P8       */ \
                                                                FLS_256KB_SIZE,   /* block 67   P8       */ \
                                                                FLS_256KB_SIZE,   /* block 68   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 69   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 70   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 71   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 72   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 73   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 74   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 75   P9       */ \
                                                            };
#elif defined(CCFC3007BC)
#define SAF_FLASH_BLOCK_MEMORY_SIZE_LIST                     { \
                                                                FLS_16KB_SIZE,    /* block 0    P0 (BAF)           */ \
                                                                FLS_16KB_SIZE,    /* block 1    P0 (Normal Code)   */ \
                                                                FLS_16KB_SIZE,    /* block 2    P0 (Normal Code)   */ \
                                                                FLS_16KB_SIZE,    /* block 3    P1 (Normal Code)   */ \
                                                                FLS_16KB_SIZE,    /* block 4    P1 (Normal Code)   */ \
                                                                FLS_16KB_SIZE,    /* block 5    P1 (HSM Code)      */ \
                                                                FLS_32KB_SIZE,    /* block 6    P0 (Normal Code)   */ \
                                                                FLS_32KB_SIZE,    /* block 7    P1 (Normal Code)   */ \
                                                                FLS_64KB_SIZE,    /* block 8    P0 (Normal Code)   */ \
                                                                FLS_64KB_SIZE,    /* block 9    P0 (Normal Code)   */ \
                                                                FLS_64KB_SIZE,    /* block 10   P1 (HSM Code)      */ \
                                                                FLS_64KB_SIZE,    /* block 11   P1 (HSM Code)      */ \
                                                                FLS_48KB_SIZE,    /* block 12   P3 (EEPROM)        */ \
                                                                FLS_48KB_SIZE,    /* block 13   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 14   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 15   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 16   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 17   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 18   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 19   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 20   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 21   P3 (EEPROM)        */ \
                                                                FLS_256KB_SIZE,   /* block 22   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 23   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 24   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 25   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 26   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 27   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 28   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 29   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 30   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 31   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 32   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 33   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 34   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 35   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 36   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 37   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 38   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 39   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 40   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 41   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 42   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 43   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 44   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 45   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 46   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 47   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 48   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 49   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 50   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 51   P5       */ \
                                                            };
#elif defined(CCFC3008PT)
#define SAF_FLASH_BLOCK_MEMORY_SIZE_LIST                     { \
                                                                FLS_16KB_SIZE,    /* block 0    P0 (BAF)           */ \
                                                                FLS_16KB_SIZE,    /* block 1    P0 (Normal Code)   */ \
                                                                FLS_16KB_SIZE,    /* block 2    P0 (Normal Code)   */ \
                                                                FLS_16KB_SIZE,    /* block 3    P1 (Normal Code)   */ \
                                                                FLS_16KB_SIZE,    /* block 4    P1 (Normal Code)   */ \
                                                                FLS_16KB_SIZE,    /* block 5    P1 (HSM Code)      */ \
                                                                FLS_32KB_SIZE,    /* block 6    P0 (Normal Code)   */ \
                                                                FLS_32KB_SIZE,    /* block 7    P1 (Normal Code)   */ \
                                                                FLS_64KB_SIZE,    /* block 8    P0 (Normal Code)   */ \
                                                                FLS_64KB_SIZE,    /* block 9    P0 (Normal Code)   */ \
                                                                FLS_64KB_SIZE,    /* block 10   P1 (HSM Code)      */ \
                                                                FLS_64KB_SIZE,    /* block 11   P1 (HSM Code)      */ \
                                                                FLS_16KB_SIZE,    /* block 12   P2 (HSM Data)      */ \
                                                                FLS_16KB_SIZE,    /* block 13   P2 (HSM Data)      */ \
                                                                FLS_16KB_SIZE,    /* block 14   P2 (HSM Data)      */ \
                                                                FLS_16KB_SIZE,    /* block 15   P2 (HSM Data)      */ \
                                                                FLS_32KB_SIZE,    /* block 16   P2 (HSM Data)      */ \
                                                                FLS_32KB_SIZE,    /* block 17   P2 (HSM Data)      */ \
                                                                FLS_64KB_SIZE,    /* block 18   P2 (HSM Data)      */ \
                                                                FLS_64KB_SIZE,    /* block 19   P2 (HSM Data)      */ \
                                                                FLS_64KB_SIZE,    /* block 20   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 21   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 22   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 23   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 24   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 25   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 26   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 27   P3 (EEPROM)        */ \
                                                                FLS_256KB_SIZE,   /* block 28   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 29   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 30   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 31   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 32   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 33   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 34   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 35   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 36   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 37   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 38   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 39   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 40   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 41   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 42   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 43   P5       */ \
                                                            };
#elif defined(CCFC3008PC) | defined(CCFC3008PCSN)
#define SAF_FLASH_BLOCK_MEMORY_SIZE_LIST                     { \
                                                                FLS_16KB_SIZE,    /* block 0    P0 (BAF)           */ \
                                                                FLS_16KB_SIZE,    /* block 1    P0 (Normal Code)   */ \
                                                                FLS_16KB_SIZE,    /* block 2    P0 (Normal Code)   */ \
                                                                FLS_16KB_SIZE,    /* block 3    P1 (Normal Code)   */ \
                                                                FLS_16KB_SIZE,    /* block 4    P1 (Normal Code)   */ \
                                                                FLS_16KB_SIZE,    /* block 5    P1 (HSM Code)      */ \
                                                                FLS_32KB_SIZE,    /* block 6    P0 (Normal Code)   */ \
                                                                FLS_32KB_SIZE,    /* block 7    P1 (Normal Code)   */ \
                                                                FLS_64KB_SIZE,    /* block 8    P0 (Normal Code)   */ \
                                                                FLS_64KB_SIZE,    /* block 9    P0 (Normal Code)   */ \
                                                                FLS_64KB_SIZE,    /* block 10   P1 (HSM Code)      */ \
                                                                FLS_64KB_SIZE,    /* block 11   P1 (HSM Code)      */ \
                                                                FLS_16KB_SIZE,    /* block 12   P2 (HSM Data)      */ \
                                                                FLS_16KB_SIZE,    /* block 13   P2 (HSM Data)      */ \
                                                                FLS_16KB_SIZE,    /* block 14   P2 (HSM Data)      */ \
                                                                FLS_16KB_SIZE,    /* block 15   P2 (HSM Data)      */ \
                                                                FLS_32KB_SIZE,    /* block 16   P2 (HSM Data)      */ \
                                                                FLS_32KB_SIZE,    /* block 17   P2 (HSM Data)      */ \
                                                                FLS_64KB_SIZE,    /* block 18   P2 (HSM Data)      */ \
                                                                FLS_64KB_SIZE,    /* block 19   P2 (HSM Data)      */ \
                                                                FLS_64KB_SIZE,    /* block 20   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 21   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 22   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 23   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 24   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 25   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 26   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 27   P3 (EEPROM)        */ \
                                                                FLS_256KB_SIZE,   /* block 28   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 29   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 30   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 31   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 32   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 33   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 34   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 35   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 36   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 37   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 38   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 39   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 40   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 41   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 42   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 43   P5       */ \
                                                            };
#elif defined(CCFC3012PT)
#define SAF_FLASH_BLOCK_MEMORY_SIZE_LIST                     { \
                                                                FLS_16KB_SIZE,    /* block 0    P0 (BAF)           */ \
                                                                FLS_16KB_SIZE,    /* block 1    P0 (Normal Code)   */ \
                                                                FLS_16KB_SIZE,    /* block 2    P0 (Normal Code)   */ \
                                                                FLS_16KB_SIZE,    /* block 3    P1 (Normal Code)   */ \
                                                                FLS_16KB_SIZE,    /* block 4    P1 (Normal Code)   */ \
                                                                FLS_16KB_SIZE,    /* block 5    P1 (HSM Code)      */ \
                                                                FLS_32KB_SIZE,    /* block 6    P0 (Normal Code)   */ \
                                                                FLS_32KB_SIZE,    /* block 7    P1 (Normal Code)   */ \
                                                                FLS_64KB_SIZE,    /* block 8    P0 (Normal Code)   */ \
                                                                FLS_64KB_SIZE,    /* block 9    P0 (Normal Code)   */ \
                                                                FLS_64KB_SIZE,    /* block 10   P1 (HSM Code)      */ \
                                                                FLS_64KB_SIZE,    /* block 11   P1 (HSM Code)      */ \
                                                                FLS_16KB_SIZE,    /* block 12   P0 (HSM Data)      */ \
                                                                FLS_16KB_SIZE,    /* block 13   P0 (HSM Data)      */ \
                                                                FLS_16KB_SIZE,    /* block 14   P0 (HSM Data)      */ \
                                                                FLS_16KB_SIZE,    /* block 15   P1 (HSM Data)      */ \
                                                                FLS_16KB_SIZE,    /* block 16   P1 (HSM Data)      */ \
                                                                FLS_16KB_SIZE,    /* block 17   P1 (HSM Data)      */ \
                                                                FLS_64KB_SIZE,    /* block 18   P2 (HSM Data)      */ \
                                                                FLS_64KB_SIZE,    /* block 19   P2 (HSM Data)      */ \
                                                                FLS_64KB_SIZE,    /* block 20   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 21   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 22   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 23   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 24   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 25   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 26   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 27   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 28   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 29   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 30   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 31   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 32   P3 (EEPROM)        */ \
                                                                FLS_64KB_SIZE,    /* block 33   P3 (EEPROM)        */ \
                                                                FLS_256KB_SIZE,   /* block 34   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 35   P4       */ \
                                                                FLS_256KB_SIZE,   /* block 36   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 37   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 38   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 39   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 40   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 41   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 42   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 43   P5       */ \
                                                                FLS_256KB_SIZE,   /* block 44   P6       */ \
                                                                FLS_256KB_SIZE,   /* block 45   P6       */ \
                                                                FLS_256KB_SIZE,   /* block 46   P6       */ \
                                                                FLS_256KB_SIZE,   /* block 47   P6       */ \
                                                                FLS_256KB_SIZE,   /* block 48   P6       */ \
                                                                FLS_256KB_SIZE,   /* block 49   P6       */ \
                                                                FLS_256KB_SIZE,   /* block 50   P6       */ \
                                                                FLS_256KB_SIZE,   /* block 51   P6       */ \
                                                                FLS_256KB_SIZE,   /* block 52   P7       */ \
                                                                FLS_256KB_SIZE,   /* block 53   P7       */ \
                                                                FLS_256KB_SIZE,   /* block 54   P7       */ \
                                                                FLS_256KB_SIZE,   /* block 55   P7       */ \
                                                                FLS_256KB_SIZE,   /* block 56   P7       */ \
                                                                FLS_256KB_SIZE,   /* block 57   P7       */ \
                                                                FLS_256KB_SIZE,   /* block 58   P7       */ \
                                                                FLS_256KB_SIZE,   /* block 59   P7       */ \
                                                                FLS_256KB_SIZE,   /* block 60   P8       */ \
                                                                FLS_256KB_SIZE,   /* block 61   P8       */ \
                                                                FLS_256KB_SIZE,   /* block 62   P8       */ \
                                                                FLS_256KB_SIZE,   /* block 63   P8       */ \
                                                                FLS_256KB_SIZE,   /* block 64   P8       */ \
                                                                FLS_256KB_SIZE,   /* block 65   P8       */ \
                                                                FLS_256KB_SIZE,   /* block 66   P8       */ \
                                                                FLS_256KB_SIZE,   /* block 67   P8       */ \
                                                                FLS_256KB_SIZE,   /* block 68   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 69   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 70   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 71   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 72   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 73   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 74   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 75   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 76   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 77   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 78   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 79   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 80   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 81   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 82   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 83   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 84   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 85   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 86   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 87   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 88   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 89   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 90   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 91   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 92   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 93   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 94   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 95   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 96   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 97   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 98   P9       */ \
                                                                FLS_256KB_SIZE,   /* block 99   P9       */ \
                                                            };
#endif

/* RAM part */
#define SAF_RAM_PRAM_CE_BIT_FCCU_NCF_INDEX                   (19U)
#define SAF_RAM_PRAM_UE_BIT_FCCU_NCF_INDEX                   (20U)
#define SAF_RAM_PRAM_CE_BIT_FCCU_INDEX_LIST                  {SAF_RAM_PRAM_CE_BIT_FCCU_NCF_INDEX}
#define SAF_RAM_PRAM_UE_BIT_FCCU_INDEX_LIST                  {SAF_RAM_PRAM_UE_BIT_FCCU_NCF_INDEX}
#define SAF_RAM_SRAM_CE_BIT_FCCU_NCF_INDEX                   (16U)
#define SAF_RAM_SRAM_UE_BIT_FCCU_NCF_INDEX                   (17U)
#define SAF_RAM_SRAM_CE_BIT_FCCU_INDEX_LIST                  {SAF_RAM_SRAM_CE_BIT_FCCU_NCF_INDEX}
#define SAF_RAM_SRAM_UE_BIT_FCCU_INDEX_LIST                  {SAF_RAM_SRAM_UE_BIT_FCCU_NCF_INDEX}

/*ERM part*/
#define FS_ERM_PRAM_CHAN_COUNT                              (4U)
#define FS_ERM_SRAM_CHAN_COUNT                              (0U)
#define FS_ERM_FLASH_CHAN_COUNT                             (2U)
#define FS_ERM_PRAM_CHAN_LIST                               {0, 1, 2, 3}
#define FS_ERM_SRAM_CHAN_LIST                               {}
#define FS_ERM_FLASH_CHAN_LIST                              {6, 7}
#define FS_ERM_INSTANCE_COUNT                               (ERM_INSTANCE_COUNT)
#define FS_ERM_IRQS_LIST                                    {ERM_IRQn}
#define FS_ERM_SUPPORTED                                    (0U)

/* DMA part */
#define FS_DMA_MCAN_INSTANCE                                (1U)

/* eMIOS part */
#define FS_EMIOS_INSTANCE_COUNT                             eMIOS_INSTANCE_COUNT

/* eTPU part */
#define FS_ETPU_CCCR_INSTANCE_COUNT                         eTPU_CCCR_INSTANCE_COUNT
#define FS_ETPU_SCR_INSTANCE_COUNT                          eTPU_SCR_INSTANCE_COUNT

/* AIPS part */
#define FS_AIPS_INSTANCE_COUNT                              AIPS_INSTANCE_COUNT
#define FS_AIPS_MPRB_REG_READBACK_SUPPORTED                 (1U)

/* xbar part */
#define FS_XBAR_VALID_SALVE_PORT_LIST                       {7U} /*should be 8, but port 5 donot exist*/
#define FS_XBAR_MAX_VALID_SLAVE_PORT_COUNT                  (7U)
#define FS_XBAR_SLAVE_PORT_LIST                             {{0, 1, 2, 3, 4, 6, 7}}   /* port 5 do not exist */
#define FS_XBAR_INSTANCE_COUNT                              XBAR_INSTANCE_COUNT

/* pbridge part */
#define FS_PRIDGE_PACR_SUPPORT_NUM_LIST                     {{0, 1, 2, 3},{0, 1, 2, 3}}
#define PBRIDGE_A_MPRA       PBRIDGE_A.MPRA.R              /* Master Privilege Register A */
#define PBRIDGE_A_MPRB       PBRIDGE_A.MPRB.R              /* Master Privilege Register B */
#define PBRIDGE_A_PACRA      PBRIDGE_A.PACR[0].R           /* Peripheral Access Control Register */
#define PBRIDGE_A_PACRB      PBRIDGE_A.PACR[1].R           /* Peripheral Access Control Register */
#define PBRIDGE_A_PACRC      PBRIDGE_A.PACR[2].R           /* Peripheral Access Control Register */
#define PBRIDGE_A_PACRD      PBRIDGE_A.PACR[3].R           /* Peripheral Access Control Register */
#define PBRIDGE_A_PACRE      PBRIDGE_A.PACR[4].R           /* Peripheral Access Control Register */
#define PBRIDGE_A_PACRF      PBRIDGE_A.PACR[5].R           /* Peripheral Access Control Register */
#define PBRIDGE_A_PACRG      PBRIDGE_A.PACR[6].R           /* Peripheral Access Control Register */
#define PBRIDGE_A_PACRH      PBRIDGE_A.PACR[7].R           /* Peripheral Access Control Register */
#define PBRIDGE_A_OPACRA     PBRIDGE_A.OPACR[0].R          /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRB     PBRIDGE_A.OPACR[1].R          /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRC     PBRIDGE_A.OPACR[2].R          /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRD     PBRIDGE_A.OPACR[3].R          /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRE     PBRIDGE_A.OPACR[4].R          /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRF     PBRIDGE_A.OPACR[5].R          /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRG     PBRIDGE_A.OPACR[6].R          /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRH     PBRIDGE_A.OPACR[7].R          /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRI     PBRIDGE_A.OPACR[8].R          /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRJ     PBRIDGE_A.OPACR[9].R          /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRK     PBRIDGE_A.OPACR[10].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRL     PBRIDGE_A.OPACR[11].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRM     PBRIDGE_A.OPACR[12].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRN     PBRIDGE_A.OPACR[13].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRO     PBRIDGE_A.OPACR[14].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRP     PBRIDGE_A.OPACR[15].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRQ     PBRIDGE_A.OPACR[16].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRR     PBRIDGE_A.OPACR[17].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRS     PBRIDGE_A.OPACR[18].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRT     PBRIDGE_A.OPACR[19].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRU     PBRIDGE_A.OPACR[20].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRV     PBRIDGE_A.OPACR[21].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRW     PBRIDGE_A.OPACR[22].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRX     PBRIDGE_A.OPACR[23].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRY     PBRIDGE_A.OPACR[24].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRZ     PBRIDGE_A.OPACR[25].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRAA    PBRIDGE_A.OPACR[26].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRAB    PBRIDGE_A.OPACR[27].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRAC    PBRIDGE_A.OPACR[28].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRAD    PBRIDGE_A.OPACR[29].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRAE    PBRIDGE_A.OPACR[30].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_A_OPACRAF    PBRIDGE_A.OPACR[31].R         /* Off-platform Peripheral Access Control Register */

#define PBRIDGE_B_MPRA       PBRIDGE_B.MPRA.R              /* Master Privilege Register A */
#define PBRIDGE_B_MPRB       PBRIDGE_B.MPRB.R              /* Master Privilege Register B */
#define PBRIDGE_B_PACRA      PBRIDGE_B.PACR[0].R           /* Peripheral Access Control Register */
#define PBRIDGE_B_PACRB      PBRIDGE_B.PACR[1].R           /* Peripheral Access Control Register */
#define PBRIDGE_B_PACRC      PBRIDGE_B.PACR[2].R           /* Peripheral Access Control Register */
#define PBRIDGE_B_PACRD      PBRIDGE_B.PACR[3].R           /* Peripheral Access Control Register */
#define PBRIDGE_B_PACRE      PBRIDGE_B.PACR[4].R           /* Peripheral Access Control Register */
#define PBRIDGE_B_PACRF      PBRIDGE_B.PACR[5].R           /* Peripheral Access Control Register */
#define PBRIDGE_B_PACRG      PBRIDGE_B.PACR[6].R           /* Peripheral Access Control Register */
#define PBRIDGE_B_PACRH      PBRIDGE_B.PACR[7].R           /* Peripheral Access Control Register */
#define PBRIDGE_B_OPACRA     PBRIDGE_B.OPACR[0].R          /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRB     PBRIDGE_B.OPACR[1].R          /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRC     PBRIDGE_B.OPACR[2].R          /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRD     PBRIDGE_B.OPACR[3].R          /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRE     PBRIDGE_B.OPACR[4].R          /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRF     PBRIDGE_B.OPACR[5].R          /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRG     PBRIDGE_B.OPACR[6].R          /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRH     PBRIDGE_B.OPACR[7].R          /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRI     PBRIDGE_B.OPACR[8].R          /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRJ     PBRIDGE_B.OPACR[9].R          /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRK     PBRIDGE_B.OPACR[10].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRL     PBRIDGE_B.OPACR[11].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRM     PBRIDGE_B.OPACR[12].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRN     PBRIDGE_B.OPACR[13].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRO     PBRIDGE_B.OPACR[14].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRP     PBRIDGE_B.OPACR[15].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRQ     PBRIDGE_B.OPACR[16].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRR     PBRIDGE_B.OPACR[17].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRS     PBRIDGE_B.OPACR[18].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRT     PBRIDGE_B.OPACR[19].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRU     PBRIDGE_B.OPACR[20].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRV     PBRIDGE_B.OPACR[21].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRW     PBRIDGE_B.OPACR[22].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRX     PBRIDGE_B.OPACR[23].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRY     PBRIDGE_B.OPACR[24].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRZ     PBRIDGE_B.OPACR[25].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRAA    PBRIDGE_B.OPACR[26].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRAB    PBRIDGE_B.OPACR[27].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRAC    PBRIDGE_B.OPACR[28].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRAD    PBRIDGE_B.OPACR[29].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRAE    PBRIDGE_B.OPACR[30].R         /* Off-platform Peripheral Access Control Register */
#define PBRIDGE_B_OPACRAF    PBRIDGE_B.OPACR[31].R         /* Off-platform Peripheral Access Control Register */

/* siul2 part */
#define FS_SIUL2_REG_READBACK_SUPPORTED                     (0U)

/*ADC part*/
#if ADC /*PRQA S 3332*/
#define FS_ADC_EQADC_CFIFO_FILL_IRQ_LIST                    {{EQADC0_FIFO0_CFFF_IRQn, EQADC0_FIFO1_CFFF_IRQn, EQADC0_FIFO2_CFFF_IRQn, EQADC0_FIFO3_CFFF_IRQn, EQADC0_FIFO4_CFFF_IRQn, EQADC0_FIFO5_CFFF_IRQn}, \
                                                             {EQADC1_FIFO0_CFFF_IRQn, EQADC1_FIFO1_CFFF_IRQn, EQADC1_FIFO2_CFFF_IRQn, EQADC1_FIFO3_CFFF_IRQn, EQADC1_FIFO4_CFFF_IRQn, EQADC1_FIFO5_CFFF_IRQn}, \
                                                            }
#define FS_ADC_EQADC_RFIFO_DRAIN_IRQ_LIST                   {{EQADC0_FIFO0_RFDF_IRQn, EQADC0_FIFO1_RFDF_IRQn, EQADC0_FIFO2_RFDF_IRQn, EQADC0_FIFO3_RFDF_IRQn, EQADC0_FIFO4_RFDF_IRQn, EQADC0_FIFO5_RFDF_IRQn}, \
                                                             {EQADC1_FIFO0_RFDF_IRQn, EQADC1_FIFO1_RFDF_IRQn, EQADC1_FIFO2_RFDF_IRQn, EQADC1_FIFO3_RFDF_IRQn, EQADC1_FIFO4_RFDF_IRQn, EQADC1_FIFO5_RFDF_IRQn}, \
                                                            }
#endif

/*PIT part*/
#define FS_PIT_CHANNEL_COUNT                                PIT_CHANNEL_COUNT
#define FS_PIT_INSTANCE_COUNT                               PIT_INSTANCE_COUNT
#define FS_PIT_CHAN_COUNT_LIST                              {4}
#define FS_PIT_IRQ_HANDLER_LIST                             {FS_MCU_Pit0ChanHandler}
#define FS_PIT_RTI_SUPPORT_LIST                             {1}
#define PIT_0_MCR            PIT_0.MCR.R                   /* PIT Module Control Register */
#define PIT_0_LTMR64H        PIT_0.LTMR64H.R               /* PIT Upper Lifetime Timer Register */
#define PIT_0_LTMR64L        PIT_0.LTMR64L.R               /* PIT Lower Lifetime Timer Register */
#define PIT_0_RTI_LDVAL      PIT_0.RTI_LDVAL.R             /* PIT RTI Timer Load Value Register */
#define PIT_0_RTI_CVAL       PIT_0.RTI_CVAL.R              /* PIT RTI Current Timer Value Register */
#define PIT_0_RTI_TCTRL      PIT_0.RTI_TCTRL.R             /* PIT RTI Timer Control Register */
#define PIT_0_RTI_TFLG       PIT_0.RTI_TFLG.R              /* PIT RTI Timer Flag Register */
#define PIT_0_LDVAL0         PIT_0.TIMER[0].LDVAL.R        /* PIT Timer Load Value Register n */
#define PIT_0_CVAL0          PIT_0.TIMER[0].CVAL.R         /* PIT Current Timer Value Register n */
#define PIT_0_TCTRL0         PIT_0.TIMER[0].TCTRL.R        /* PIT Timer Control Register n */
#define PIT_0_TFLG0          PIT_0.TIMER[0].TFLG.R         /* PIT Timer Flag Register n */
#define PIT_0_LDVAL1         PIT_0.TIMER[1].LDVAL.R        /* PIT Timer Load Value Register n */
#define PIT_0_CVAL1          PIT_0.TIMER[1].CVAL.R         /* PIT Current Timer Value Register n */
#define PIT_0_TCTRL1         PIT_0.TIMER[1].TCTRL.R        /* PIT Timer Control Register n */
#define PIT_0_TFLG1          PIT_0.TIMER[1].TFLG.R         /* PIT Timer Flag Register n */
#define PIT_0_LDVAL2         PIT_0.TIMER[2].LDVAL.R        /* PIT Timer Load Value Register n */
#define PIT_0_CVAL2          PIT_0.TIMER[2].CVAL.R         /* PIT Current Timer Value Register n */
#define PIT_0_TCTRL2         PIT_0.TIMER[2].TCTRL.R        /* PIT Timer Control Register n */
#define PIT_0_TFLG2          PIT_0.TIMER[2].TFLG.R         /* PIT Timer Flag Register n */
#define PIT_0_LDVAL3         PIT_0.TIMER[3].LDVAL.R        /* PIT Timer Load Value Register n */
#define PIT_0_CVAL3          PIT_0.TIMER[3].CVAL.R         /* PIT Current Timer Value Register n */
#define PIT_0_TCTRL3         PIT_0.TIMER[3].TCTRL.R        /* PIT Timer Control Register n */
#define PIT_0_TFLG3          PIT_0.TIMER[3].TFLG.R         /* PIT Timer Flag Register n */
#define PIT_0_LDVAL4         PIT_0.TIMER[4].LDVAL.R        /* PIT Timer Load Value Register n */
#define PIT_0_CVAL4          PIT_0.TIMER[4].CVAL.R         /* PIT Current Timer Value Register n */
#define PIT_0_TCTRL4         PIT_0.TIMER[4].TCTRL.R        /* PIT Timer Control Register n */
#define PIT_0_TFLG4          PIT_0.TIMER[4].TFLG.R         /* PIT Timer Flag Register n */
#define PIT_0_LDVAL5         PIT_0.TIMER[5].LDVAL.R        /* PIT Timer Load Value Register n */
#define PIT_0_CVAL5          PIT_0.TIMER[5].CVAL.R         /* PIT Current Timer Value Register n */
#define PIT_0_TCTRL5         PIT_0.TIMER[5].TCTRL.R        /* PIT Timer Control Register n */
#define PIT_0_TFLG5          PIT_0.TIMER[5].TFLG.R         /* PIT Timer Flag Register n */
#define PIT_0_LDVAL6         PIT_0.TIMER[6].LDVAL.R        /* PIT Timer Load Value Register n */
#define PIT_0_CVAL6          PIT_0.TIMER[6].CVAL.R         /* PIT Current Timer Value Register n */
#define PIT_0_TCTRL6         PIT_0.TIMER[6].TCTRL.R        /* PIT Timer Control Register n */
#define PIT_0_TFLG6          PIT_0.TIMER[6].TFLG.R         /* PIT Timer Flag Register n */
#define PIT_0_LDVAL7         PIT_0.TIMER[7].LDVAL.R        /* PIT Timer Load Value Register n */
#define PIT_0_CVAL7          PIT_0.TIMER[7].CVAL.R         /* PIT Current Timer Value Register n */
#define PIT_0_TCTRL7         PIT_0.TIMER[7].TCTRL.R        /* PIT Timer Control Register n */
#define PIT_0_TFLG7          PIT_0.TIMER[7].TFLG.R         /* PIT Timer Flag Register n */

#define PIT_1_MCR            PIT_1.MCR.R                   /* PIT Module Control Register */
#define PIT_1_LTMR64H        PIT_1.LTMR64H.R               /* PIT Upper Lifetime Timer Register */
#define PIT_1_LTMR64L        PIT_1.LTMR64L.R               /* PIT Lower Lifetime Timer Register */
#define PIT_1_RTI_LDVAL      PIT_1.RTI_LDVAL.R             /* PIT RTI Timer Load Value Register */
#define PIT_1_RTI_CVAL       PIT_1.RTI_CVAL.R              /* PIT RTI Current Timer Value Register */
#define PIT_1_RTI_TCTRL      PIT_1.RTI_TCTRL.R             /* PIT RTI Timer Control Register */
#define PIT_1_RTI_TFLG       PIT_1.RTI_TFLG.R              /* PIT RTI Timer Flag Register */
#define PIT_1_LDVAL0         PIT_1.TIMER[0].LDVAL.R        /* PIT Timer Load Value Register n */
#define PIT_1_CVAL0          PIT_1.TIMER[0].CVAL.R         /* PIT Current Timer Value Register n */
#define PIT_1_TCTRL0         PIT_1.TIMER[0].TCTRL.R        /* PIT Timer Control Register n */
#define PIT_1_TFLG0          PIT_1.TIMER[0].TFLG.R         /* PIT Timer Flag Register n */
#define PIT_1_LDVAL1         PIT_1.TIMER[1].LDVAL.R        /* PIT Timer Load Value Register n */
#define PIT_1_CVAL1          PIT_1.TIMER[1].CVAL.R         /* PIT Current Timer Value Register n */
#define PIT_1_TCTRL1         PIT_1.TIMER[1].TCTRL.R        /* PIT Timer Control Register n */
#define PIT_1_TFLG1          PIT_1.TIMER[1].TFLG.R         /* PIT Timer Flag Register n */
#define PIT_1_LDVAL2         PIT_1.TIMER[2].LDVAL.R        /* PIT Timer Load Value Register n */
#define PIT_1_CVAL2          PIT_1.TIMER[2].CVAL.R         /* PIT Current Timer Value Register n */
#define PIT_1_TCTRL2         PIT_1.TIMER[2].TCTRL.R        /* PIT Timer Control Register n */
#define PIT_1_TFLG2          PIT_1.TIMER[2].TFLG.R         /* PIT Timer Flag Register n */
#define PIT_1_LDVAL3         PIT_1.TIMER[3].LDVAL.R        /* PIT Timer Load Value Register n */
#define PIT_1_CVAL3          PIT_1.TIMER[3].CVAL.R         /* PIT Current Timer Value Register n */
#define PIT_1_TCTRL3         PIT_1.TIMER[3].TCTRL.R        /* PIT Timer Control Register n */
#define PIT_1_TFLG3          PIT_1.TIMER[3].TFLG.R         /* PIT Timer Flag Register n */
#define PIT_1_LDVAL4         PIT_1.TIMER[4].LDVAL.R        /* PIT Timer Load Value Register n */
#define PIT_1_CVAL4          PIT_1.TIMER[4].CVAL.R         /* PIT Current Timer Value Register n */
#define PIT_1_TCTRL4         PIT_1.TIMER[4].TCTRL.R        /* PIT Timer Control Register n */
#define PIT_1_TFLG4          PIT_1.TIMER[4].TFLG.R         /* PIT Timer Flag Register n */
#define PIT_1_LDVAL5         PIT_1.TIMER[5].LDVAL.R        /* PIT Timer Load Value Register n */
#define PIT_1_CVAL5          PIT_1.TIMER[5].CVAL.R         /* PIT Current Timer Value Register n */
#define PIT_1_TCTRL5         PIT_1.TIMER[5].TCTRL.R        /* PIT Timer Control Register n */
#define PIT_1_TFLG5          PIT_1.TIMER[5].TFLG.R         /* PIT Timer Flag Register n */
#define PIT_1_LDVAL6         PIT_1.TIMER[6].LDVAL.R        /* PIT Timer Load Value Register n */
#define PIT_1_CVAL6          PIT_1.TIMER[6].CVAL.R         /* PIT Current Timer Value Register n */
#define PIT_1_TCTRL6         PIT_1.TIMER[6].TCTRL.R        /* PIT Timer Control Register n */
#define PIT_1_TFLG6          PIT_1.TIMER[6].TFLG.R         /* PIT Timer Flag Register n */
#define PIT_1_LDVAL7         PIT_1.TIMER[7].LDVAL.R        /* PIT Timer Load Value Register n */
#define PIT_1_CVAL7          PIT_1.TIMER[7].CVAL.R         /* PIT Current Timer Value Register n */
#define PIT_1_TCTRL7         PIT_1.TIMER[7].TCTRL.R        /* PIT Timer Control Register n */
#define PIT_1_TFLG7          PIT_1.TIMER[7].TFLG.R         /* PIT Timer Flag Register n */

/* intc part */
typedef union FS_INTC_MCR_union_tag {     /* INTC Monitor Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :28;
    vuint32_t SEL:2;
    vuint32_t MMR:2;
  } B;
} FS_INTC_MCR_tag;

typedef union FS_INTC_MSR_union_tag {     /* INTC Monitor Select Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t SEL:10;
  } B;
} FS_INTC_MSR_tag;

typedef union FS_INTC_MTOR_union_tag {     /* INTC Monitor Time-out Register */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t TO:24;
  } B;
} FS_INTC_MTOR_tag;

typedef union FS_INTC_MTR_union_tag {     /* INTC Monitor Timer Register */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t TIMER:24;
  } B;
} FS_INTC_MTR_tag;

struct SAF_INTC0_MONITOR_tag_t {
    FS_INTC_MCR_tag MCR0;
    FS_INTC_MSR_tag MSR0[3];
    uint32_t INTC_reserved0[1];
    FS_INTC_MTOR_tag MTOR0[3];
    uint32_t INTC_reserved1[1];
    FS_INTC_MTR_tag MTR0[3];
};

#define SAF_INTC0_MONITOR   (*(volatile struct SAF_INTC0_MONITOR_tag_t *)  0xFC041000UL)

#define SAF_INTC_IRQ_COUNT                                   (1024U)
#define SAF_INTC_MONITOR_IRQ_COUNT                           SAF_INTC_IRQ_COUNT
#define SAF_DIV_8_RIGHT_SHIFT_BIT                            (3U)
#define SAF_MOD_8_MASK                                       (0x7)
#define SAF_MAX_FREQUNCY_ERR_RANGE_HZ                        (1000000UL)
#define SAF_INTC_SYS_CLK_FREQUENCY_LIST                      {100000000, 150000000, 200000000, 260000000}    /* 150MHz, 200MHz */
#define SAF_INT_LOW_LATENCY_US_LIST                          {3.9, 2.96, 1.09, 1.05}   /* test data */

/* swt part */

#ifdef RESOURCE_SUPPORT_SWT0               /* Supported. SWT 0 */
#define SAF_RESOURCE_SUPPORT_SWT0
#endif
#define RESOURCE_SUPPORT_SWT7_AO            /* Supported. SWT 7_AO */
/** Number of instances of the SWT module. */
#if defined(CCFC3008PC) | defined(CCFC3008PCSN)
#define SWT_INSTANCE_COUNT                                  (8U) //(3U)
#elif defined(CCFC3012PT)
#define SWT_INSTANCE_COUNT                                  (8U)
#elif defined(CCFC3007BC)
#define SWT_INSTANCE_COUNT                                  (8U)
#else
#define SWT_INSTANCE_COUNT                                  (8U)
#endif
#define FS_SWT_INST_FCCU_FAULT_INDEX_LIST                   {14U, 15U}
#define FS_SWT_MONITOR_ISRS_LIST                            {FS_MCU_Swt0MonitorHandler, FS_MCU_Swt1MonitorHandler}
#define FS_SWT_INSTANCE_COUNT                               SWT_INSTANCE_COUNT
#define FS_SWT_SAFETYCORE_TIMER_MONITOR_INSTANCE            (0U)
#define FS_SWT_NON_SAFETYCORE_TIMER_MONOTOR_INSTANCE        (1U)

/* dspi part */
#define FS_DSPI_INSTANCE_COUNT                              DSPI_INSTANCE_COUNT

#define SAF_DSPI_0_PTR          ((volatile struct DSPI_tag *)     0xFFE70000UL)
#define SAF_DSPI_1_PTR          ((volatile struct DSPI_tag *)     0xFFE74000UL)
#define SAF_DSPI_2_PTR          ((volatile struct DSPI_tag *)     0xFBE70000UL)
#define SAF_DSPI_3_PTR          ((volatile struct DSPI_tag *)     0xFBE74000UL)
#define SAF_DSPI_4_PTR          ((volatile struct DSPI_tag *)     0xFFE78000UL)
#define SAF_DSPI_5_PTR          ((volatile struct DSPI_tag *)     0xFBE78000UL)
#define SAF_DSPI_6_PTR          ((volatile struct DSPI_tag *)     0xFFE7C000UL)
#define SAF_DSPI_7_PTR          ((volatile struct DSPI_tag *)     0xFBE7C000UL)
#define SAF_DSPI_8_PTR          ((volatile struct DSPI_tag *)     0xFFE80000UL)
#define SAF_DSPI_9_PTR          ((volatile struct DSPI_tag *)     0xFBE80000UL)
#define SAF_DSPI_10_PTR         ((volatile struct DSPI_tag *)     0xFFE84000UL)
#define SAF_DSPI_11_PTR         ((volatile struct DSPI_tag *)     0xFBE84000UL)
#define SAF_DSPI_12_PTR         ((volatile struct DSPI_tag *)     0xFFE88000UL)
#define SAF_DSPI_13_PTR         ((volatile struct DSPI_tag *)     0xFBE88000UL)
#define SAF_DSPI_14_PTR         ((volatile struct DSPI_tag *)     0xFFE60000UL)
#define SAF_DSPI_15_PTR         ((volatile struct DSPI_tag *)     0xFFE64000UL)
#define SAF_DSPI_16_PTR         ((volatile struct DSPI_tag *)     0xFBE44000UL)
#define SAF_DSPI_17_PTR         ((volatile struct DSPI_tag *)     0xFBE48000UL)
#define SAF_DSPI_18_PTR         ((volatile struct DSPI_tag *)     0xFBE4C000UL)
#define SAF_DSPI_19_PTR         ((volatile struct DSPI_tag *)     0xFFE44000UL)
#define SAF_DSPI_20_PTR         ((volatile struct DSPI_tag *)     0xFFE48000UL)
#define SAF_DSPI_21_PTR         ((volatile struct DSPI_tag *)     0xFFE4C000UL)

/* sipi part */
#define FS_SIPI_INSTANCE_COUNT                              SIPI_INSTANCE_COUNT

/* reacm2 part */
#define FS_REACM2_INSTANCE_COUNT                            REACM2_INSTANCE_COUNT

/* igf part */
#define FS_IGF_INSTANCE_COUNT                               IGF_INSTANCE_COUNT

/* CAN part */
#define FS_CAN_INSTANCE_COUNT                               CAN_INSTANCE_COUNT

/* srx part */
#define FS_SRX_INSTANCE_COUNT                               SRX_INSTANCE_COUNT

#if STM /*PRQA S 3332*/
/* STM module */
#define FS_STM_INSTANCE_COUNT                               STM_INSTANCE_COUNT
#define FS_STM_CHANNEL_COUNT                                STM_CHANNEL_COUNT
#define FS_STM_CHAN_COUNT_LIST                              {FS_STM_CHANNEL_COUNT}
#define FS_STM_IRQ_HANDLER_LIST                             {FS_MCU_Stm0ChanHandler}
#define FS_STM_IRQS_ARRAY_LIST                              {{STM_Ch0_IRQn, STM_Ch123_IRQn, STM_Ch123_IRQn, STM_Ch123_IRQn}}
#endif
/* CMU part */

#define SAF_CMU_IRQ_SUPPORTED                                (0U)
#define SAF_CMU_MEASURE_IRCOSC_CMU_BASE_ADDR                 CMU_0
#define SAF_CMU_FCCU_RF_INDEX_CMU_OLR                        (31U)
#define SAF_CMU_FCCU_RF_INDEX_CMU_PLL                        (32U)
#define SAF_CMU_FCCU_RF_INDEX_CMU_COMP                       (33U)
#define SAF_CMU_FCCU_RF_INDEX_CMU_OTHER                      (34U)
#define SAF_CMU_SYS_CLK_MAX_INSTANCE                         (4U)
#define SAF_CMU_PLL_CLK_INSTANCE                             (0U)
#define SAF_CMU_Z7_CLK_INSTANCE                              (11U)
#define SAF_CMU_MAX_INSTANCE                                 (13U)
#define SAF_CMU_BASE_PTRS                                    CMU_BASE_PTRS
#define SAF_CMU_FCCU_INDEX_LIST                              {SAF_CMU_FCCU_RF_INDEX_CMU_PLL,   SAF_CMU_FCCU_RF_INDEX_CMU_COMP,  SAF_CMU_FCCU_RF_INDEX_CMU_COMP,  SAF_CMU_FCCU_RF_INDEX_CMU_COMP, \
                                                              SAF_CMU_FCCU_RF_INDEX_CMU_OTHER, SAF_CMU_FCCU_RF_INDEX_CMU_OTHER, SAF_CMU_FCCU_RF_INDEX_CMU_OTHER, SAF_CMU_FCCU_RF_INDEX_CMU_OTHER, \
                                                              SAF_CMU_FCCU_RF_INDEX_CMU_OTHER, SAF_CMU_FCCU_RF_INDEX_CMU_OTHER, SAF_CMU_FCCU_RF_INDEX_CMU_OTHER, SAF_CMU_FCCU_RF_INDEX_CMU_COMP, \
                                                              SAF_CMU_FCCU_RF_INDEX_CMU_OTHER}
#define SAF_CMU_INSTANCE_COUNT                                CMU_INSTANCE_COUNT

#define CMU_CSR_CME_MASK                         0x1u
#define CMU_CSR_CME_SHIFT                        0u
#define CMU_CSR_CME_WIDTH                        1u
#define CMU_CSR_CME(x)                           (((uint32_t)(((uint32_t)(x))<<CMU_CSR_CME_SHIFT))&CMU_CSR_CME_MASK)
#define CMU_CSR_RCDIV_MASK                       0x6u
#define CMU_CSR_RCDIV_SHIFT                      1u
#define CMU_CSR_RCDIV_WIDTH                      2u
#define CMU_CSR_RCDIV(x)                         (((uint32_t)(((uint32_t)(x))<<CMU_CSR_RCDIV_SHIFT))&CMU_CSR_RCDIV_MASK)
#define CMU_CSR_CKSEL1_MASK                      0x300u
#define CMU_CSR_CKSEL1_SHIFT                     8u
#define CMU_CSR_CKSEL1_WIDTH                     2u
#define CMU_CSR_CKSEL1(x)                        (((uint32_t)(((uint32_t)(x))<<CMU_CSR_CKSEL1_SHIFT))&CMU_CSR_CKSEL1_MASK)
#define CMU_CSR_SFM_MASK                         0x800000u
#define CMU_CSR_SFM_SHIFT                        23u
#define CMU_CSR_SFM_WIDTH                        1u
#define CMU_CSR_SFM(x)                           (((uint32_t)(((uint32_t)(x))<<CMU_CSR_SFM_SHIFT))&CMU_CSR_SFM_MASK)
/* FDR Bit Fields */
#define CMU_FDR_FD_MASK                          0xFFFFFu
#define CMU_FDR_FD_SHIFT                         0u
#define CMU_FDR_FD_WIDTH                         20u
#define CMU_FDR_FD(x)                            (((uint32_t)(((uint32_t)(x))<<CMU_FDR_FD_SHIFT))&CMU_FDR_FD_MASK)
/* HFREFR Bit Fields */
#define CMU_HFREFR_HFREF_MASK                    0xFFFu
#define CMU_HFREFR_HFREF_SHIFT                   0u
#define CMU_HFREFR_HFREF_WIDTH                   12u
#define CMU_HFREFR_HFREF(x)                      (((uint32_t)(((uint32_t)(x))<<CMU_HFREFR_HFREF_SHIFT))&CMU_HFREFR_HFREF_MASK)
/* LFREFR Bit Fields */
#define CMU_LFREFR_LFREF_MASK                    0xFFFu
#define CMU_LFREFR_LFREF_SHIFT                   0u
#define CMU_LFREFR_LFREF_WIDTH                   12u
#define CMU_LFREFR_LFREF(x)                      (((uint32_t)(((uint32_t)(x))<<CMU_LFREFR_LFREF_SHIFT))&CMU_LFREFR_LFREF_MASK)
/* ISR Bit Fields */
#define CMU_ISR_OLRI_MASK                        0x1u
#define CMU_ISR_OLRI_SHIFT                       0u
#define CMU_ISR_OLRI_WIDTH                       1u
#define CMU_ISR_OLRI(x)                          (((uint32_t)(((uint32_t)(x))<<CMU_ISR_OLRI_SHIFT))&CMU_ISR_OLRI_MASK)
#define CMU_ISR_FLLI_MASK                        0x2u
#define CMU_ISR_FLLI_SHIFT                       1u
#define CMU_ISR_FLLI_WIDTH                       1u
#define CMU_ISR_FLLI(x)                          (((uint32_t)(((uint32_t)(x))<<CMU_ISR_FLLI_SHIFT))&CMU_ISR_FLLI_MASK)
#define CMU_ISR_FHHI_MASK                        0x4u
#define CMU_ISR_FHHI_SHIFT                       2u
#define CMU_ISR_FHHI_WIDTH                       1u
#define CMU_ISR_FHHI(x)                          (((uint32_t)(((uint32_t)(x))<<CMU_ISR_FHHI_SHIFT))&CMU_ISR_FHHI_MASK)
#define CMU_ISR_FLCI_MASK                        0x8u
#define CMU_ISR_FLCI_SHIFT                       3u
#define CMU_ISR_FLCI_WIDTH                       1u
#define CMU_ISR_FLCI(x)                          (((uint32_t)(((uint32_t)(x))<<CMU_ISR_FLCI_SHIFT))&CMU_ISR_FLCI_MASK)
/* MDR Bit Fields */
#define CMU_MDR_MD_MASK                          0xFFFFFu
#define CMU_MDR_MD_SHIFT                         0u
#define CMU_MDR_MD_WIDTH                         20u
#define CMU_MDR_MD(x)                            (((uint32_t)(((uint32_t)(x))<<CMU_MDR_MD_SHIFT))&CMU_MDR_MD_MASK)

/*PLL part*/
/*!
 * @brief Sets system clock source
 */
#define FS_PLL_NONFMPLL_CLOCK_SOURCE_IS_IRCOSC              (1U)
#define FS_PLL_NONFMPLL_CLOCK_SOURCE_IS_XOSC                (0U)

/* OSC part */
#define SAF_OSC_CLOCK_SOURCE_IS_IRCOSC                       (0U)
#define SAF_OSC_CLOCK_SOURCE_IS_XOSC                         (1U)
#define SAF_OSC_CLOCK_SOURCE_IS_NON_FMPLL                    (2U)
#define SAF_OSC_CLOCK_SOURCE_IS_FMPLL                        (4U)
#define SAF_OSC_CLOCK_SOURCE_IS_DISABLED                     (0xFU)
#define SAF_OSC_MCAN_CLOCK_SOURCE_IS_XOSC                    (0U)
#define SAF_OSC_MCAN_CLOCK_SOURCE_IS_NONFMPLL                (1U)
#define SAF_OSC_FLEXCAN_CLOCK_SOURCE_IS_XOSC                 (0U)
#define SAF_OSC_FLEXCAN_CLOCK_SOURCE_IS_NON_FMPLL            (1U)
#define SAF_OSC_UTEST_XOSC_CNT_MASK                          (0x7F000000U)
#define SAF_OSC_UTEST_XOSC_CNT_SHIFT                         (24U)
#define SAF_OSC_XOSC_NEED_READ_DCF                           (1U)
#define SAF_OSC_XOSC_DCF_RECORE_MISCE_CS                     (0x80U)
#define SAF_OSC_XOSC_DCF_RECORE_MISCE_ADDR                   (0x00U)

/* CORE PART */
#define FS_CORE_SAFETY_CORE_ID                              (0U)
#define FS_CORE_MCSR_SPR_ID                                 (572U)

/* CORE-debug */
#define FS_DEBUG_SDADC_SUPPORT_FREEZE                       (1U)
#define FS_DEBUG_STM_SUPPORT_FREEZE                         (1U)
#define FS_DEBUG_SWT_SUPPORT_FREEZE                         (1U)
#define FS_DEBUG_PIT_SUPPORT_FREEZE                         (1U)
#define FS_DEBUG_DSPI_SUPPORT_FREEZE                        (1U)
#define FS_DEBUG_SIPI_SUPPORT_FREEZE                        (1U)
#define FS_DEBUG_EMIOS_SUPPORT_FREEZE                       (1U)
#define FS_DEBUG_IGF_SUPPORT_FREEZE                         (1U)
#define FS_DEBUG_FLEXCAN_SUPPORT_FREEZE                     (1U)
#define FS_DEBUG_REACM2_SUPPORT_FREEZE                      (1U)
#define FS_DEBUG_SRX_SUPPORT_FREEZE                         (1U)
#define FS_DEBUG_BCTU_SUPPORT_FREEZE                        (0U)

/* STACK part */
#define FS_STACK_UNDER_OVER_FLOW_DISCERN                    (0U)

typedef union FS_CORE_MSR_union_tag
{
    uint32_t R;
    struct
    {
        uint32_t :6;
        uint32_t SPV:1;
        uint32_t :6;
        uint32_t WE:1;
        uint32_t CE:1;
        uint32_t :1;
        uint32_t EE:1;
        uint32_t PR:1;
        uint32_t FP:1;
        uint32_t ME:1;
        uint32_t FE0:1;
        uint32_t :1;
        uint32_t DE:1;
        uint32_t FE1:1;
        uint32_t :2;
        uint32_t IS:1;
        uint32_t DS:1;
        uint32_t :1;
        uint32_t PWM:1;
        uint32_t RI:1;
        uint32_t :1;
    }B;
} FS_CORE_MSR_tag;

typedef union FS_CORE_MCSR_union_tag
{
    vuint32_t R;
    struct
    {
        vuint32_t MCP:1;
        vuint32_t IC_DPERR:1;
        vuint32_t :1;
        vuint32_t DC_DPERR:1;
        vuint32_t EXCP_ERR:1;
        vuint32_t IC_TPERR:1;
        vuint32_t DC_TPERR:1;
        vuint32_t IC_LKERR:1;
        vuint32_t DC_LKERR:1;
        vuint32_t :2;
        vuint32_t NMI:1;
        vuint32_t MAV:1;
        vuint32_t MEA:1;
        vuint32_t U:1;
        vuint32_t IF:1;
        vuint32_t LD:1;
        vuint32_t ST:1;
        vuint32_t G:1;
        vuint32_t :2;
        vuint32_t STACK_ERR:1;
        vuint32_t IMEM_PERR:1;
        vuint32_t DMEM_RDPERR:1;
        vuint32_t DMEM_WRPERR:1;
        vuint32_t :2;
        vuint32_t BUS_IRERR:1;
        vuint32_t BUS_DRERR:1;
        vuint32_t BUS_WRERR:1;
        vuint32_t BUS_WRDSI:1;
        vuint32_t :1;
    }B;
} FS_CORE_MCSR_tag;

typedef union FS_CORE_L1CSR0_union_tag
{
    vuint32_t R;
    struct
    {
        vuint32_t WID:2;
        vuint32_t :2;
        vuint32_t WDD:2;
        vuint32_t :6;
        vuint32_t DCWA:1;
        vuint32_t :2;
        vuint32_t DCECE:1;
        vuint32_t DCEI:1;
        vuint32_t DCLOC:2;
        vuint32_t :6;
        vuint32_t DCEA:2;
        vuint32_t DCLOINV:1;
        vuint32_t :1;
        vuint32_t DCABT:1;
        vuint32_t DCINV:1;
        vuint32_t DCE:1;
    }B;
} FS_CORE_L1CSR0_tag;

typedef union FS_CORE_L1CSR1_union_tag
{
    vuint32_t R;
    struct
    {
        vuint32_t :15;
        vuint32_t ICECE:1;
        vuint32_t ICEI:1;
        vuint32_t ICLOC:2;
        vuint32_t :6;
        vuint32_t ICEA:2;
        vuint32_t ICLOINV:1;
        vuint32_t :1;
        vuint32_t ICABT:1;
        vuint32_t ICINV:1;
        vuint32_t ICE:1;
    }B;
} FS_CORE_L1CSR1_tag;

typedef union FS_CORE_L1FINV0_union_tag
{
    vuint32_t R;
    struct
    {
        vuint32_t :7;
        vuint32_t CWAY:1;
        vuint32_t :13;
        vuint32_t CSET:6;
        vuint32_t :2;
        vuint32_t CCMD:3;
    }B;
} FS_CORE_L1FINV0_tag;

typedef union FS_CORE_L1FINV1_union_tag
{
    vuint32_t R;
    struct
    {
        vuint32_t :7;
        vuint32_t CWAY:1;
        vuint32_t :11;
        vuint32_t CSET:8;
        vuint32_t :2;
        vuint32_t CCMD:3;
    }B;
} FS_CORE_L1FINV1_tag;


/* CORE-debug-register */
typedef union FS_CORE_DBCR0_union_tag
{
    uint32_t R;
    struct
    {
        uint32_t EDM:1;
        uint32_t IDM:1;
        uint32_t RST:2;
        uint32_t ICMP:1;
        uint32_t BRT:1;
        uint32_t IRPT:1;
        uint32_t TRAP:1;
        uint32_t IAC1:1;
        uint32_t IAC2:1;
        uint32_t IAC3:1;
        uint32_t IAC4:1;
        uint32_t DAC1:2;
        uint32_t DAC2:2;
        uint32_t RET:1;
        uint32_t IAC5:1;
        uint32_t IAC6:1;
        uint32_t IAC7:1;
        uint32_t IAC8:1;
        uint32_t DEVT1:1;
        uint32_t DEVT2:1;
        uint32_t DCNT1:1;
        uint32_t DCNT2:1;
        uint32_t CIRPT:1;
        uint32_t CRET:1;
        uint32_t :4;
        uint32_t FT:1;
    }B;
} FS_CORE_DBCR0_tag;

typedef union FS_CORE_DBCR2_union_tag
{
    uint32_t R;
    struct
    {
        uint32_t DAC1US:2;
        uint32_t DAC1ER:2;
        uint32_t DAC2US:2;
        uint32_t DAC2ER:2;
        uint32_t DAC12M:2;
        uint32_t DAC1LNK:1;
        uint32_t DAC2LNK:1;
        uint32_t DVC1M:2;
        uint32_t DVC2M:2;
        uint32_t DVC1BE:8;
        uint32_t DVC2BE:8;
    }B;
} FS_CORE_DBCR2_tag;

typedef union FS_CORE_DBCR4_union_tag
{
    uint32_t R;
    struct
    {
        uint32_t :1;
        uint32_t DVC1C:1;
        uint32_t :1;
        uint32_t DVC2C:1;
        uint32_t :12;
        uint32_t DAC1XM:4;
        uint32_t DAC2XM:4;
        uint32_t :8;
    }B;
} FS_CORE_DBCR4_tag;

typedef union FS_CORE_DBSR_union_tag
{
    uint32_t R;
    struct
    {
        uint32_t IDE:1;
        uint32_t UDE:1;
        uint32_t MRR:2;
        uint32_t ICMP:1;
        uint32_t BRT:1;
        uint32_t IRPT:1;
        uint32_t TRAP:1;
        uint32_t IAC:1;
        uint32_t :3;
        uint32_t DACR:1;
        uint32_t DACW:1;
        uint32_t :1;
        uint32_t DNI:1;
        uint32_t RET:1;
        uint32_t :4;
        uint32_t DEVT1:1;
        uint32_t DEVT2:1;
        uint32_t PMI:1;
        uint32_t MPU:1;
        uint32_t CIRPT:1;
        uint32_t CRET:1;
        uint32_t VLES:1;
        uint32_t DAC_OFST:3;
        uint32_t :1;
    }B;
} FS_CORE_DBSR_tag;

/* ESCI part */
#define FS_ESCI_MONITOER_TIMER_INT_PRIORITY                 (1)

/* FLEXCAN */
#define FS_MCAN_NAME_LIST                                {SAF_MCAN_0, SAF_MCAN_1, SAF_MCAN_2, SAF_MCAN_3,SAF_MCAN_4,SAF_MCAN_5,SAF_MCAN_6,SAF_MCAN_7}

/* MC_CGM */
#define MC_CGM_SC_SS_SELSTAT_MASK 0xf000000
#define MC_CGM_SC_SS_SELSTAT_SHIFT 24

#define MC_CGM_AC8_SC_SELSTAT_MASK 0xf000000
#define MC_CGM_AC8_SC_SELCTL_SHIFT_SAF 24

#define MC_CGM_AC3_SC_SELSTAT_MASK 0xf000000
#define MC_CGM_AC3_SC_SELCTL_SHIFT 24

#define MC_CGM_AC4_SC_SELSTAT_MASK 0xf000000
#define MC_CGM_AC4_SC_SELCTL_SHIFT 24

/*PMC & TSENS part*/
#if defined(CCFC3008PCSN) | defined(CCFC3008PC)
#define PMC_PBIST_SUPPORTED                                 (1U)
#endif

#define FS_PMCDIG_PBIST_BASE_ADDR                           (0xFFFA05ACU)
#define FS_PMCDIG_PBIST                                     (*(volatile uint32_t *) FS_PMCDIG_PBIST_BASE_ADDR)
#define FS_BIST_EN_OFFSET                                   (2U)
#define FS_PBIST_SEL                                        (0x3U)
#define FS_PBIST_EN                                         (0x1U)
#define FS_PBIST_RESET                                      (0x0U)

#if defined(CCFC3008PCSN)
#define FS_STBY_BIST_SEL_OFFSET                             (28U)
#define FS_IO_BIST_SEL_OFFSET                               (25U)
#define FS_PMC_BIST_SEL_OFFSET                              (12U)
#define FS_FLA_BIST_SEL_OFFSET                              (9U)
#define FS_ADC_BIST_SEL_OFFSET                              (6U)
#define FS_VDDC_BIST_SEL_OFFSET                             (3U)
#define FS_VDDCBKP_BIST_SEL_OFFSET                          (0U)
#elif defined(CCFC3008PC)
#define FS_IO_BIST_SEL_OFFSET                               (12U)
#define FS_FLA_BIST_SEL_OFFSET                              (9U)
#define FS_ADC_BIST_SEL_OFFSET                              (6U)
#define FS_VDDC_BIST_SEL_OFFSET                             (3U)
#define FS_VDDCBKP_BIST_SEL_OFFSET                          (0U)
#endif

#if defined(CCFC3008PCSN)
#define FS_STBY_BIST_SEL                                    (FS_PBIST_SEL << FS_STBY_BIST_SEL_OFFSET)
#define FS_PMC_BIST_SEL                                     (FS_PBIST_SEL << FS_PMC_BIST_SEL_OFFSET)
#endif
#define FS_IO_BIST_SEL                                      (FS_PBIST_SEL << FS_IO_BIST_SEL_OFFSET)
#define FS_FLA_BIST_SEL                                     (FS_PBIST_SEL << FS_FLA_BIST_SEL_OFFSET)
#define FS_ADC_BIST_SEL                                     (FS_PBIST_SEL << FS_ADC_BIST_SEL_OFFSET)
#define FS_VDDC_BIST_SEL                                    (FS_PBIST_SEL << FS_VDDC_BIST_SEL_OFFSET)
#define FS_VDDCBKP_BIST_SEL                                 (FS_PBIST_SEL << FS_VDDCBKP_BIST_SEL_OFFSET)
#if defined(CCFC3008PCSN)
#define FS_ALL_BIST_SEL                                     (FS_STBY_BIST_SEL | FS_IO_BIST_SEL | FS_PMC_BIST_SEL | FS_FLA_BIST_SEL | FS_ADC_BIST_SEL | FS_VDDC_BIST_SEL | FS_VDDCBKP_BIST_SEL)
#elif defined(CCFC3008PC)
#define FS_ALL_BIST_SEL                                     (FS_IO_BIST_SEL| FS_FLA_BIST_SEL | FS_ADC_BIST_SEL | FS_VDDC_BIST_SEL | FS_VDDCBKP_BIST_SEL)
#endif

#if defined(CCFC3008PCSN)
#define FS_STBY_BIST_EN                                     (FS_PBIST_EN  << (FS_STBY_BIST_SEL_OFFSET + FS_BIST_EN_OFFSET))
#define FS_PMC_BIST_EN                                      (FS_PBIST_EN  << (FS_PMC_BIST_SEL_OFFSET + FS_BIST_EN_OFFSET))
#endif
#define FS_IO_BIST_EN                                       (FS_PBIST_EN  << (FS_IO_BIST_SEL_OFFSET + FS_BIST_EN_OFFSET))
#define FS_FLA_BIST_EN                                      (FS_PBIST_EN  << (FS_FLA_BIST_SEL_OFFSET + FS_BIST_EN_OFFSET))
#define FS_ADC_BIST_EN                                      (FS_PBIST_EN  << (FS_ADC_BIST_SEL_OFFSET + FS_BIST_EN_OFFSET))
#define FS_VDDC_BIST_EN                                     (FS_PBIST_EN  << (FS_VDDC_BIST_SEL_OFFSET + FS_BIST_EN_OFFSET))
#define FS_VDDCBKP_BIST_EN                                  (FS_PBIST_EN  << (FS_VDDCBKP_BIST_SEL_OFFSET + FS_BIST_EN_OFFSET))
#if defined(CCFC3008PCSN)
#define FS_ALL_BIST_EN                                      (FS_STBY_BIST_EN | FS_IO_BIST_EN | FS_PMC_BIST_EN | FS_FLA_BIST_EN | FS_ADC_BIST_EN | FS_VDDC_BIST_EN | FS_VDDCBKP_BIST_EN)
#define FS_PMCDIG_VD_UTEST_ALLEVENT_MASK                    (0x0000FFFCU)
#elif defined(CCFC3008PC)
#define FS_ALL_BIST_EN                                      (FS_IO_BIST_EN | FS_FLA_BIST_EN | FS_ADC_BIST_EN | FS_VDDC_BIST_EN | FS_VDDCBKP_BIST_EN)
#define FS_PMCDIG_VD_UTEST_ALLEVENT_MASK                    (0x0000FFC0U)
#endif

#define FS_ADC_BANDGAP_CHANNEL                              (45U)
#define FS_TSENS_SENSOR0_ADC_CHANNEL                        (128U)
#define FS_TSENS_SENSOR1_ADC_CHANNEL                        (129U)
#define FS_PMC_BANDGAP_TEST_CHANNEL                         (0xFU)
#define FS_PMC_RESET_TYPE_SELECT_SUPPORT                    (0U)
#define FS_TSENS_RESET_TYPE_SELECT_SUPPORT                  (0U)
#define FS_TSENS_SENS_INDEX_VALUE_A                         (16U)
#define FS_TSENS_SENS_INDEX_VALUE_B                         (64U)
#define FS_TSENS_ERR_RANGE_DEGREE                           (10U) /* +- 5 degree */
#define FS_TSENS_RANGE_DEGREE_MAX                           (150U)
#define FS_TSENS_RANGE_DEGREE_MIN                           (-40U)
#define FS_PMC_SELF_TEST_SUPPORT                            (0U)
#define FS_PMC_INSTANCE_COUNT                               PMC_INSTANCE_COUNT

/* CACHE part*/
#define SAF_CACHE_SUPPORTED                                  (1U)
#define SAF_ICACHE_SUPPORTED                                 (1U)
#define SAF_DCACHE_SUPPORTED                                 (1U)

/* SIU */
#define FS_SIU_SUPPORTED                                    (0U)
#define FS_SIU_REG_READBACK_SUPPORTED                       (1U)
#define FS_SIU_INSTANCE_COUNT                               SIU_INSTANCE_COUNT

/* RGM */
#define SAF_RGM_SUPPORTED                                    (1U)

/* MEMU */
#define MEMU_INSTANCE_COUNT                                 (1U)
/** MEMU - Size of Registers Arrays */
#define MEMU_SYS_RAM_CERR_COUNT                  10u
#define MEMU_SYS_RAM_OFLW_COUNT                  1u
#define MEMU_PERIPH_RAM_CERR_COUNT               2u
#define MEMU_FLASH_CERR_COUNT                    20u

#define SAF_MEMU_SUPPORTED                                   (1U)
#define SAF_MEMU_INSTANCE_COUNT                              (MEMU_INSTANCE_COUNT)

/* MPU part */
#define SAF_SMPU_SUPPORTED                                   (1U)
#define SAF_MPU_SUPPORTED                                    (1U)

/* Register Protect */
#define FS_REGPROT_SUPPORTED                                (0U)

/* ITCM */
#if defined(CCFC3008PCSN)
#define SAF_ITCM_SUPPORTED                                  (1U)
#else
#define SAF_ITCM_SUPPORTED                                  (0U)
#endif

/* Linflex */
#define SAF_LINFlexD_0_PTR      ((volatile struct LINFlexD_tag *) 0xFFE8C000UL)
#define SAF_LINFlexD_1_PTR      ((volatile struct LINFlexD_tag *) 0xFFE90000UL)
#define SAF_LINFlexD_2_PTR      ((volatile struct LINFlexD_tag *) 0xFBE8C000UL)
#define SAF_LINFlexD_3_PTR      ((volatile struct LINFlexD_tag *) 0xFFE94000UL)
#define SAF_LINFlexD_4_PTR      ((volatile struct LINFlexD_tag *) 0xFFE98000UL)
#define SAF_LINFlexD_5_PTR      ((volatile struct LINFlexD_tag *) 0xFFE9C000UL)
#define SAF_LINFlexD_6_PTR      ((volatile struct LINFlexD_tag *) 0xFFEA0000UL)
#define SAF_LINFlexD_7_PTR      ((volatile struct LINFlexD_tag *) 0xFBE90000UL)
#define SAF_LINFlexD_8_PTR      ((volatile struct LINFlexD_tag *) 0xFBE94000UL)
#define SAF_LINFlexD_9_PTR      ((volatile struct LINFlexD_tag *) 0xFBE98000UL)
#define SAF_LINFlexD_10_PTR     ((volatile struct LINFlexD_tag *) 0xFBE9C000UL)
#define SAF_LINFlexD_11_PTR     ((volatile struct LINFlexD_tag *) 0xFBEA0000UL)
#define SAF_LINFlexD_12_PTR     ((volatile struct LINFlexD_tag *) 0xFBEA4000UL)
#define SAF_LINFlexD_14_PTR     ((volatile struct LINFlexD_tag *) 0xFFEA8000UL)
#define SAF_LINFlexD_15_PTR     ((volatile struct LINFlexD_tag *) 0xFBEA8000UL)
#define SAF_LINFlexD_16_PTR     ((volatile struct LINFlexD_tag *) 0xFFEAC000UL)
/*FlexRay part*/
#ifdef RESOURCE_SUPPORT_FLEXRAY
#define SAF_FlexRay_SUPPORTED                                (1U)
/* FLEXRAY part*/
#define SAF_FLEXRAY_CLOCK_SOURCE_IS_OSC                       (0U)
#define SAF_FLEXRAY_CLOCK_SOURCE_IS_PLL                       (1U)
#else
#define SAF_FlexRay_SUPPORTED                                (0U)
#endif

/* Csent part */
#define SAF_CSRX_0_0_PTR        ((volatile struct CSRX_tag *)    (0xFFE58000UL + 0U*64U))
#define SAF_CSRX_0_1_PTR        ((volatile struct CSRX_tag *)    (0xFFE58000UL + 1U*64U))
#define SAF_CSRX_0_2_PTR        ((volatile struct CSRX_tag *)    (0xFFE58000UL + 2U*64U))
#define SAF_CSRX_0_3_PTR        ((volatile struct CSRX_tag *)    (0xFFE58000UL + 3U*64U))
#define SAF_CSRX_0_4_PTR        ((volatile struct CSRX_tag *)    (0xFFE58000UL + 4U*64U))
#define SAF_CSRX_0_5_PTR        ((volatile struct CSRX_tag *)    (0xFFE58000UL + 5U*64U))
#define SAF_CSRX_0_6_PTR        ((volatile struct CSRX_tag *)    (0xFFE58000UL + 6U*64U))
#define SAF_CSRX_0_7_PTR        ((volatile struct CSRX_tag *)    (0xFFE58000UL + 7U*64U))
#define SAF_CSRX_1_0_PTR        ((volatile struct CSRX_tag *)    (0xFBE58000UL + 0U*64U))
#define SAF_CSRX_1_1_PTR        ((volatile struct CSRX_tag *)    (0xFBE58000UL + 1U*64U))
#define SAF_CSRX_1_2_PTR        ((volatile struct CSRX_tag *)    (0xFBE58000UL + 2U*64U))
#define SAF_CSRX_1_3_PTR        ((volatile struct CSRX_tag *)    (0xFBE58000UL + 3U*64U))
#define SAF_CSRX_1_4_PTR        ((volatile struct CSRX_tag *)    (0xFBE58000UL + 4U*64U))
#define SAF_CSRX_1_5_PTR        ((volatile struct CSRX_tag *)    (0xFBE58000UL + 5U*64U))
#define SAF_CSRX_1_6_PTR        ((volatile struct CSRX_tag *)    (0xFBE58000UL + 6U*64U))

#define SAF_CSRX_0_PTR          ((volatile struct CSRX_tag *)     0xFFE58000UL)
#define SAF_CSRX_1_PTR          ((volatile struct CSRX_tag *)     0xFBE58000UL)
/* MCME */
#define SAF_MCME_SUPPORTED                                   (1U)

/*CRC*/
/* CRC module features */
#define CRC_INSTANCE_COUNT                                  (2U)

#define FS_CRC_INSTANCE_COUNT                               CRC_INSTANCE_COUNT

/* PLL0SR Bit Fields */
#define PLLDIG_PLL0SR_LOCK_MASK                  0x4u
#define PLLDIG_PLL0SR_LOCK_SHIFT                 2u
#define PLLDIG_PLL0SR_LOCK_WIDTH                 1u
#define PLLDIG_PLL0SR_LOCK(x)                    (((uint32_t)(((uint32_t)(x))<<PLLDIG_PLL0SR_LOCK_SHIFT))&PLLDIG_PLL0SR_LOCK_MASK)
#define PLLDIG_PLL0SR_LOLF_MASK                  0x8u
#define PLLDIG_PLL0SR_LOLF_SHIFT                 3u
#define PLLDIG_PLL0SR_LOLF_WIDTH                 1u
#define PLLDIG_PLL0SR_LOLF(x)                    (((uint32_t)(((uint32_t)(x))<<PLLDIG_PLL0SR_LOLF_SHIFT))&PLLDIG_PLL0SR_LOLF_MASK)

/* PLL1SR Bit Fields */
#define PLLDIG_PLL1SR_LOCK_MASK                  0x4u
#define PLLDIG_PLL1SR_LOCK_SHIFT                 2u
#define PLLDIG_PLL1SR_LOCK_WIDTH                 1u
#define PLLDIG_PLL1SR_LOCK(x)                    (((uint32_t)(((uint32_t)(x))<<PLLDIG_PLL1SR_LOCK_SHIFT))&PLLDIG_PLL1SR_LOCK_MASK)
#define PLLDIG_PLL1SR_LOLF_MASK                  0x8u
#define PLLDIG_PLL1SR_LOLF_SHIFT                 3u
#define PLLDIG_PLL1SR_LOLF_WIDTH                 1u
#define PLLDIG_PLL1SR_LOLF(x)                    (((uint32_t)(((uint32_t)(x))<<PLLDIG_PLL1SR_LOLF_SHIFT))&PLLDIG_PLL1SR_LOLF_MASK)

/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/


/**
****************************************************************************************
 * @brief: Function prototypes
****************************************************************************************
*/
SAF_CLOCK_SOURCE_TYPE SAF_MCU_ClkGetClkSrc(const SAF_CLOCK_NAME clkName);
bool SAF_MCU_OscXoscIsStable(void);
void saf_delay(volatile uint32_t x);
#ifdef __cplusplus
}
#endif

#endif

