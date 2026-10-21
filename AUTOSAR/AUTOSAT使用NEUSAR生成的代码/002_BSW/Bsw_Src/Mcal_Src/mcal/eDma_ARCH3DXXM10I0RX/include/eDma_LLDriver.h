/**************************************************************************** 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : eDma
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
*   @file    eDma_LLDriver.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of eDma MCAL driver.
*
*   @addtogroup eDma
*   @{
*/

#ifndef EDMA_LLDRIVER_H_
#define EDMA_LLDRIVER_H_

#ifdef __cplusplus
extern "C"{
#endif

#include "derivative.h"
#include "typedefs.h"
#include "status.h"
#include "eDma_Cfg.h"
#include "eDma_Irq.h"




#define EDMA_LLD_H_VENDOR_ID                     176
#define EDMA_LLD_H_AR_REL_MAJOR_VER              4
#define EDMA_LLD_H_AR_REL_MINOR_VER              4
#define EDMA_LLD_H_AR_REL_REV_VER                0
#define EDMA_LLD_H_SW_MAJOR_VER                  3
#define EDMA_LLD_H_SW_MINOR_VER                  0
#define EDMA_LLD_H_SW_PATCH_VER                  0

#if (EDMA_CFG_H_VENDOR_ID != EDMA_LLD_H_VENDOR_ID)
    #error " NON-MATCHED DATA : EDMA_LLD_H_VENDOR_ID "
#endif
#if (EDMA_CFG_H_AR_REL_MAJOR_VER != EDMA_LLD_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : EDMA_LLD_H_AR_REL_MAJOR_VER "
#endif
#if (EDMA_CFG_H_AR_REL_MINOR_VER != EDMA_LLD_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : EDMA_LLD_H_AR_REL_MINOR_VER "
#endif
#if (EDMA_CFG_H_AR_REL_REV_VER != EDMA_LLD_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : EDMA_LLD_H_AR_REL_REV_VER "
#endif
#if (EDMA_CFG_H_SW_MAJOR_VER != EDMA_LLD_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : EDMA_LLD_H_SW_MAJOR_VER "
#endif
#if (EDMA_CFG_H_SW_MINOR_VER != EDMA_LLD_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : EDMA_LLD_H_SW_MINOR_VER "
#endif
#if (EDMA_CFG_H_SW_PATCH_VER != EDMA_LLD_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : EDMA_LLD_H_SW_PATCH_VER "
#endif

#define EDMA_DEV_ERR(x)                         DEV_ASSERT(x)

#define EDMA_CH0_CH127_INT                      (1U)
#define EDMA_CH0_CH127_ERROR_INT                (1U)
#define EDMA_ERROR_INTERRUPT_LINES              (1U)

#define MODULES_EDMA_CHANNELS                   (64U)
#define EDMA_MAPPED_CHN_INTERRUPT_LINES         ((uint32)128U)

#define EDMA_TOTAL_CHANNELS                     (MODULES_EDMA_CHANNELS * EDMA_INSTANCE_COUNT)

#define TCD_SIZE_CALC(number)                   (((number) * 32U) - 1U)
#define TCD_ADDR_CALC(address)                  (((uint32)(address) + 31UL) & ~0x1FUL)

/* Physical channel number for channel configuration #0 - #127*/
#define EDMA_CHN0_NUMBER        (0U)
#define EDMA_CHN1_NUMBER        (1U)
#define EDMA_CHN2_NUMBER        (2U)
#define EDMA_CHN3_NUMBER        (3U)
#define EDMA_CHN4_NUMBER        (4U)
#define EDMA_CHN5_NUMBER        (5U)
#define EDMA_CHN6_NUMBER        (6U)
#define EDMA_CHN7_NUMBER        (7U)
#define EDMA_CHN8_NUMBER        (8U)
#define EDMA_CHN9_NUMBER        (9U)
#define EDMA_CHN10_NUMBER       (10U)
#define EDMA_CHN11_NUMBER       (11U)
#define EDMA_CHN12_NUMBER       (12U)
#define EDMA_CHN13_NUMBER       (13U)
#define EDMA_CHN14_NUMBER       (14U)
#define EDMA_CHN15_NUMBER       (15U)
#define EDMA_CHN16_NUMBER       (16U)
#define EDMA_CHN17_NUMBER       (17U)
#define EDMA_CHN18_NUMBER       (18U)
#define EDMA_CHN19_NUMBER       (19U)
#define EDMA_CHN20_NUMBER       (20U)
#define EDMA_CHN21_NUMBER       (21U)
#define EDMA_CHN22_NUMBER       (22U)
#define EDMA_CHN23_NUMBER       (23U)
#define EDMA_CHN24_NUMBER       (24U)
#define EDMA_CHN25_NUMBER       (25U)
#define EDMA_CHN26_NUMBER       (26U)
#define EDMA_CHN27_NUMBER       (27U)
#define EDMA_CHN28_NUMBER       (28U)
#define EDMA_CHN29_NUMBER       (29U)
#define EDMA_CHN30_NUMBER       (30U)
#define EDMA_CHN31_NUMBER       (31U)
#define EDMA_CHN32_NUMBER       (32U)
#define EDMA_CHN33_NUMBER       (33U)
#define EDMA_CHN34_NUMBER       (34U)
#define EDMA_CHN35_NUMBER       (35U)
#define EDMA_CHN36_NUMBER       (36U)
#define EDMA_CHN37_NUMBER       (37U)
#define EDMA_CHN38_NUMBER       (38U)
#define EDMA_CHN39_NUMBER       (39U)
#define EDMA_CHN40_NUMBER       (40U)
#define EDMA_CHN41_NUMBER       (41U)
#define EDMA_CHN42_NUMBER       (42U)
#define EDMA_CHN43_NUMBER       (43U)
#define EDMA_CHN44_NUMBER       (44U)
#define EDMA_CHN45_NUMBER       (45U)
#define EDMA_CHN46_NUMBER       (46U)
#define EDMA_CHN47_NUMBER       (47U)
#define EDMA_CHN48_NUMBER       (48U)
#define EDMA_CHN49_NUMBER       (49U)
#define EDMA_CHN50_NUMBER       (50U)
#define EDMA_CHN51_NUMBER       (51U)
#define EDMA_CHN52_NUMBER       (52U)
#define EDMA_CHN53_NUMBER       (53U)
#define EDMA_CHN54_NUMBER       (54U)
#define EDMA_CHN55_NUMBER       (55U)
#define EDMA_CHN56_NUMBER       (56U)
#define EDMA_CHN57_NUMBER       (57U)
#define EDMA_CHN58_NUMBER       (58U)
#define EDMA_CHN59_NUMBER       (59U)
#define EDMA_CHN60_NUMBER       (60U)
#define EDMA_CHN61_NUMBER       (61U)
#define EDMA_CHN62_NUMBER       (62U)
#define EDMA_CHN63_NUMBER       (63U)
#define EDMA_CHN64_NUMBER       (64U)
#define EDMA_CHN65_NUMBER       (65U)
#define EDMA_CHN66_NUMBER       (66U)
#define EDMA_CHN67_NUMBER       (67U)
#define EDMA_CHN68_NUMBER       (68U)
#define EDMA_CHN69_NUMBER       (69U)
#define EDMA_CHN70_NUMBER       (70U)
#define EDMA_CHN71_NUMBER       (71U)
#define EDMA_CHN72_NUMBER       (72U)
#define EDMA_CHN73_NUMBER       (73U)
#define EDMA_CHN74_NUMBER       (74U)
#define EDMA_CHN75_NUMBER       (75U)
#define EDMA_CHN76_NUMBER       (76U)
#define EDMA_CHN77_NUMBER       (77U)
#define EDMA_CHN78_NUMBER       (78U)
#define EDMA_CHN79_NUMBER       (79U)
#define EDMA_CHN80_NUMBER       (80U)
#define EDMA_CHN81_NUMBER       (81U)
#define EDMA_CHN82_NUMBER       (82U)
#define EDMA_CHN83_NUMBER       (83U)
#define EDMA_CHN84_NUMBER       (84U)
#define EDMA_CHN85_NUMBER       (85U)
#define EDMA_CHN86_NUMBER       (86U)
#define EDMA_CHN87_NUMBER       (87U)
#define EDMA_CHN88_NUMBER       (88U)
#define EDMA_CHN89_NUMBER       (89U)
#define EDMA_CHN90_NUMBER       (90U)
#define EDMA_CHN91_NUMBER       (91U)
#define EDMA_CHN92_NUMBER       (92U)
#define EDMA_CHN93_NUMBER       (93U)
#define EDMA_CHN94_NUMBER       (94U)
#define EDMA_CHN95_NUMBER       (95U)
#define EDMA_CHN96_NUMBER       (96U)
#define EDMA_CHN97_NUMBER       (97U)
#define EDMA_CHN98_NUMBER       (98U)
#define EDMA_CHN99_NUMBER       (99U)
#define EDMA_CHN100_NUMBER      (100U)
#define EDMA_CHN101_NUMBER      (101U)
#define EDMA_CHN102_NUMBER      (102U)
#define EDMA_CHN103_NUMBER      (103U)
#define EDMA_CHN104_NUMBER      (104U)
#define EDMA_CHN105_NUMBER      (105U)
#define EDMA_CHN106_NUMBER      (106U)
#define EDMA_CHN107_NUMBER      (107U)
#define EDMA_CHN108_NUMBER      (108U)
#define EDMA_CHN109_NUMBER      (109U)
#define EDMA_CHN110_NUMBER      (110U)
#define EDMA_CHN111_NUMBER      (111U)
#define EDMA_CHN112_NUMBER      (112U)
#define EDMA_CHN113_NUMBER      (113U)
#define EDMA_CHN114_NUMBER      (114U)
#define EDMA_CHN115_NUMBER      (115U)
#define EDMA_CHN116_NUMBER      (116U)
#define EDMA_CHN117_NUMBER      (117U)
#define EDMA_CHN118_NUMBER      (118U)
#define EDMA_CHN119_NUMBER      (119U)
#define EDMA_CHN120_NUMBER      (120U)
#define EDMA_CHN121_NUMBER      (121U)
#define EDMA_CHN122_NUMBER      (122U)
#define EDMA_CHN123_NUMBER      (123U)
#define EDMA_CHN124_NUMBER      (124U)
#define EDMA_CHN125_NUMBER      (125U)
#define EDMA_CHN126_NUMBER      (126U)
#define EDMA_CHN127_NUMBER      (127U)

#define DMAMUX_AVAILABLE
#define DMAMUX_HAS_TRIG

#define DMAMUX_CHANNELS                         (16U)
#define DMAMUX_SOURCE_NUMS                      (64UL)

#define DMAMUX_CHN_REG_INDEX(x)                 (x)
#define DMAMUX_CHCFG_ENBL(x)                    (uint8)((uint32)(x) << DMAMUX_CHCFG_ENBL_SHIFT)
#define DMAMUX_CHCFG_TRIG(x)                    (uint8)((uint32)(x) << DMAMUX_CHCFG_TRIG_SHIFT)
#define DMAMUX_CHCFG_SOURCE(x)                  ((x) << DMAMUX_CHCFG_SOURCE_SHIFT)

#define DMAMUX_CH_WIDTH                         (6UL)
#define DMAMUX_REQ_SRC_TO_INSTANCE(x)           ((x) >> (uint32)DMAMUX_CH_WIDTH)
#define DMAMUX_REQ_SRC_TO_CH(x)                 ((x) & ((uint32)DMAMUX_SOURCE_NUMS - 1UL))
#ifdef RESOURCE_SUPPORT_DMAMUX10
EDMA_INLINE FUNC(uint8, EDMA_CODE) DMAMUX_DMA_CH_TO_CH(VAR(uint8, AUTOMATIC) x)    
{
    if(x < 32U)
    {
        return (x & 0x7u);
    }
    else if(x < 112U)
    {
        return (x & 0xfu);
    }
    else
    {
        return (x & 0x7u);
    }
}
#else
#define DMAMUX_DMA_CH_TO_CH(x)                  (((x) < 32U)?((x) & (0x7U)):((x) & (15U)))
#endif

#define EDMA_CHANNELS                           (64UL)
#define EDMA_CH_WIDTH                           (6U)
#define EDMA_MCH_TO_INSTANCE(x)                 ((x) >> EDMA_CH_WIDTH)
#define EDMA_MCH_TO_CH(x)                       ((x) & ((uint32)EDMA_CHANNELS - 1UL))
#define EDMA_CHN_TO_DCHPRI_INDEX(x)             (x)
#define EDMA_INSTANCE_COUNT                     (2UL)
#define EDMA_MAPPED_CHANNELS                    (EDMA_CHANNELS * EDMA_INSTANCE_COUNT)

typedef volatile struct eDMA_tag  DMA_Type;

#define DMA_0_BASE                              (0xFC0A0000UL)
#define DMA_0_P                                 ((DMA_Type *)DMA_0_BASE)
#define DMA_1_BASE                              (0xFC0A4000UL)
#define DMA_1_P                                 ((DMA_Type *)DMA_1_BASE)
#define DMA_BASE_ADDRS                          { DMA_0_BASE, DMA_1_BASE }
#define DMA_BASE_PTRS                           { DMA_0_P, DMA_1_P }
#define DMA_CHN_IRQS                            { DMA0_CH0_IRQn,   DMA0_CH1_IRQn,   \
                                                  DMA0_CH2_IRQn,   DMA0_CH3_IRQn,   \
                                                  DMA0_CH4_IRQn,   DMA0_CH5_IRQn,   \
                                                  DMA0_CH6_IRQn,   DMA0_CH7_IRQn,   \
                                                  DMA0_CH8_IRQn,   DMA0_CH9_IRQn,   \
                                                  DMA0_CH10_IRQn,  DMA0_CH11_IRQn,  \
                                                  DMA0_CH12_IRQn,  DMA0_CH13_IRQn,  \
                                                  DMA0_CH14_IRQn,  DMA0_CH15_IRQn,  \
                                                  DMA0_CH16_IRQn,  DMA0_CH17_IRQn,  \
                                                  DMA0_CH18_IRQn,  DMA0_CH19_IRQn,  \
                                                  DMA0_CH20_IRQn,  DMA0_CH21_IRQn,  \
                                                  DMA0_CH22_IRQn,  DMA0_CH23_IRQn,  \
                                                  DMA0_CH24_IRQn,  DMA0_CH25_IRQn,  \
                                                  DMA0_CH26_IRQn,  DMA0_CH27_IRQn,  \
                                                  DMA0_CH28_IRQn,  DMA0_CH29_IRQn,  \
                                                  DMA0_CH30_IRQn,  DMA0_CH31_IRQn,  \
                                                  DMA0_CH32_IRQn,  DMA0_CH33_IRQn,  \
                                                  DMA0_CH34_IRQn,  DMA0_CH35_IRQn,  \
                                                  DMA0_CH36_IRQn,  DMA0_CH37_IRQn,  \
                                                  DMA0_CH38_IRQn,  DMA0_CH39_IRQn,  \
                                                  DMA0_CH40_IRQn,  DMA0_CH41_IRQn,  \
                                                  DMA0_CH42_IRQn,  DMA0_CH43_IRQn,  \
                                                  DMA0_CH44_IRQn,  DMA0_CH45_IRQn,  \
                                                  DMA0_CH46_IRQn,  DMA0_CH47_IRQn, \
                                                  DMA0_CH48_IRQn, DMA0_CH49_IRQn, \
                                                  DMA0_CH50_IRQn, DMA0_CH51_IRQn, \
                                                  DMA0_CH52_IRQn, DMA0_CH53_IRQn, \
                                                  DMA0_CH54_IRQn, DMA0_CH55_IRQn, \
                                                  DMA0_CH56_IRQn, DMA0_CH57_IRQn, \
                                                  DMA0_CH58_IRQn, DMA0_CH59_IRQn, \
                                                  DMA0_CH60_IRQn, DMA0_CH61_IRQn, \
                                                  DMA0_CH62_IRQn, DMA0_CH63_IRQn, \
                                                  DMA1_CH0_IRQn,  DMA1_CH1_IRQn,  \
                                                  DMA1_CH2_IRQn,  DMA1_CH3_IRQn,  \
                                                  DMA1_CH4_IRQn,  DMA1_CH5_IRQn,  \
                                                  DMA1_CH6_IRQn,  DMA1_CH7_IRQn,  \
                                                  DMA1_CH8_IRQn,  DMA1_CH9_IRQn,  \
                                                  DMA1_CH10_IRQn, DMA1_CH11_IRQn, \
                                                  DMA1_CH12_IRQn, DMA1_CH13_IRQn, \
                                                  DMA1_CH14_IRQn, DMA1_CH15_IRQn, \
                                                  DMA1_CH16_IRQn, DMA1_CH17_IRQn, \
                                                  DMA1_CH18_IRQn, DMA1_CH19_IRQn, \
                                                  DMA1_CH20_IRQn, DMA1_CH21_IRQn, \
                                                  DMA1_CH22_IRQn, DMA1_CH23_IRQn, \
                                                  DMA1_CH24_IRQn, DMA1_CH25_IRQn, \
                                                  DMA1_CH26_IRQn, DMA1_CH27_IRQn, \
                                                  DMA1_CH28_IRQn, DMA1_CH29_IRQn, \
                                                  DMA1_CH30_IRQn, DMA1_CH31_IRQn, \
                                                  DMA1_CH32_IRQn, DMA1_CH33_IRQn, \
                                                  DMA1_CH34_IRQn, DMA1_CH35_IRQn, \
                                                  DMA1_CH36_IRQn, DMA1_CH37_IRQn, \
                                                  DMA1_CH38_IRQn, DMA1_CH39_IRQn, \
                                                  DMA1_CH40_IRQn, DMA1_CH41_IRQn, \
                                                  DMA1_CH42_IRQn, DMA1_CH43_IRQn, \
                                                  DMA1_CH44_IRQn, DMA1_CH45_IRQn, \
                                                  DMA1_CH46_IRQn, DMA1_CH47_IRQn, \
                                                  DMA1_CH48_IRQn, DMA1_CH49_IRQn, \
                                                  DMA1_CH50_IRQn, DMA1_CH51_IRQn, \
                                                  DMA1_CH52_IRQn, DMA1_CH53_IRQn, \
                                                  DMA1_CH54_IRQn, DMA1_CH55_IRQn, \
                                                  DMA1_CH56_IRQn, DMA1_CH57_IRQn, \
                                                  DMA1_CH58_IRQn, DMA1_CH59_IRQn, \
                                                  DMA1_CH60_IRQn, DMA1_CH61_IRQn, \
                                                  DMA1_CH62_IRQn, DMA1_CH63_IRQn  }
#define DMA_ERROR_IRQS                          { DMA0_ERR0_127_IRQn }

#define DMAMUX_CHANNEL_COUNT                    (16u)

typedef struct
{
    volatile VAR(uint8, AUTOMATIC) CHCFG[DMAMUX_CHANNEL_COUNT];   /** Control Register, offset: 0x0 */
} DMAMUX_Type, *DMAMUX_MemMapPtr; /* PRQA S 1535 */

#ifdef RESOURCE_SUPPORT_DMAMUX10
#define DMAMUX_INSTANCE_COUNT                   (11u)
#else
#define DMAMUX_INSTANCE_COUNT                   (10u)
#endif

#define DMAMUX_0_BASE                           (0xFFF6C000UL)
#define DMAMUX_1_BASE                           (0xFFF6C200UL)
#define DMAMUX_2_BASE                           (0xFFF6C400UL)
#define DMAMUX_3_BASE                           (0xFFF6C600UL)
#define DMAMUX_4_BASE                           (0xFFF6C800UL)
#define DMAMUX_5_BASE                           (0xFFF6CA00UL)
#define DMAMUX_6_BASE                           (0xFFF6CC00UL)
#define DMAMUX_7_BASE                           (0xFFF6CE00UL)
#define DMAMUX_8_BASE                           (0xFFF6D000UL)
#define DMAMUX_9_BASE                           (0xFFF6D200UL)
#ifdef RESOURCE_SUPPORT_DMAMUX10
#define DMAMUX_10_BASE                          (0xFFF6D400UL)
#endif

/** Peripheral DMAMUX_0~9 base pointer */
#define DMAMUX0_P                               ((DMAMUX_Type *)DMAMUX_0_BASE)
#define DMAMUX1_P                               ((DMAMUX_Type *)DMAMUX_1_BASE)
#define DMAMUX2_P                               ((DMAMUX_Type *)DMAMUX_2_BASE)
#define DMAMUX3_P                               ((DMAMUX_Type *)DMAMUX_3_BASE)
#define DMAMUX4_P                               ((DMAMUX_Type *)DMAMUX_4_BASE)
#define DMAMUX5_P                               ((DMAMUX_Type *)DMAMUX_5_BASE)
#define DMAMUX6_P                               ((DMAMUX_Type *)DMAMUX_6_BASE)
#define DMAMUX7_P                               ((DMAMUX_Type *)DMAMUX_7_BASE)
#define DMAMUX8_P                               ((DMAMUX_Type *)DMAMUX_8_BASE)
#define DMAMUX9_P                               ((DMAMUX_Type *)DMAMUX_9_BASE)
#ifdef RESOURCE_SUPPORT_DMAMUX10
#define DMAMUX10_P                              ((DMAMUX_Type *)DMAMUX_10_BASE)
#endif

#ifdef RESOURCE_SUPPORT_DMAMUX10
#define DMAMUX_BASE_PTRS                        { DMAMUX0_P, DMAMUX1_P, DMAMUX2_P, DMAMUX3_P, \
                                                  DMAMUX4_P, DMAMUX5_P, DMAMUX6_P, DMAMUX7_P, \
                                                  DMAMUX8_P, DMAMUX9_P, DMAMUX10_P }
#else
#define DMAMUX_BASE_PTRS                        { DMAMUX0_P, DMAMUX1_P, DMAMUX2_P, DMAMUX3_P, \
                                                  DMAMUX4_P, DMAMUX5_P, DMAMUX6_P, DMAMUX7_P, \
                                                  DMAMUX8_P, DMAMUX9_P }
#endif

typedef enum
{
    EDMA_INSTANCE_0 = 0U,
    EDMA_INSTANCE_1 = 1U
} eDMAIstanceNumType;

typedef enum
{
    DMAMUX_INSTANCE_0 = 0U,
    DMAMUX_INSTANCE_1 = 1U,
    DMAMUX_INSTANCE_2 = 2U,
    DMAMUX_INSTANCE_3 = 3U,
    DMAMUX_INSTANCE_4 = 4U,
    DMAMUX_INSTANCE_5 = 5U,
    DMAMUX_INSTANCE_6 = 6U,
    DMAMUX_INSTANCE_7 = 7U,
    DMAMUX_INSTANCE_8 = 8U,
    DMAMUX_INSTANCE_9 = 9U,
#ifdef RESOURCE_SUPPORT_DMAMUX10
    DMAMUX_INSTANCE_10 = 10
#endif
} DMAMUXInstanceNumType;

typedef enum
{
    EDMA_CHN_STATUS_NORMAL = 0U,    /* eDMA channel normal state. */
    EDMA_CHN_STATUS_ERR_UCE = 1U,   /*Uncorrectable ECC error*/
    EDMA_CHN_STATUS_ERR_ECX = 2U,   /*Transfer cancelled*/
    EDMA_CHN_STATUS_ERR_GPE = 3U,   /*Group priority error*/
    EDMA_CHN_STATUS_ERR_CPE = 4U,   /*Channel priority error*/
    EDMA_CHN_STATUS_ERR_CHN = 5U,   /*Error channel number or cancelled channel numbe*/
    EDMA_CHN_STATUS_ERR_SAE = 6U,   /*Source address error*/
    EDMA_CHN_STATUS_ERR_SOE = 7U,   /*Source offset error*/
    EDMA_CHN_STATUS_ERR_DAE = 8U,   /*Destination address error*/
    EDMA_CHN_STATUS_ERR_DOE = 9U,   /*Destination offset error*/
    EDMA_CHN_STATUS_ERR_NCE = 10U,  /*NBYTES/CITER configuration error*/
    EDMA_CHN_STATUS_ERR_SGE = 11U,  /*Scatter/gather configuration error*/
    EDMA_CHN_STATUS_ERR_SBE = 12U,  /*Source bus error*/ 
    EDMA_CHN_STATUS_ERR_DBE = 13U,  /*Destination bus error*/ 
} eDMAChnStatusType;

typedef enum
{
    EDMA_ARBITRATION_MODE_FIXED_PRIORITY = 0U,  /* Fixed Priority */
    EDMA_ARBITRATION_MODE_ROUND_ROBIN = 1U           /* Round - Robin arbitration */
} eDMASelArbitrationModeType;

typedef struct
{
    VAR(uint32, AUTOMATIC) errh;
    VAR(uint32, AUTOMATIC) errl;
} eDMAErrorRegisterType;

typedef enum
{
    EDMA_GRP_PRIORITY0 = 0U,
    EDMA_GRP_PRIORITY1 = 1U,
    EDMA_GRP_PRIORITY2 = 2U,
    EDMA_GRP_PRIORITY3 = 3U
} eDMAGroupPriorityType;

typedef struct
{
    VAR(eDMASelArbitrationModeType, AUTOMATIC) setChnArbitMode;         /* eDMA channel arbitration. */
    VAR(eDMASelArbitrationModeType, AUTOMATIC) groupArbitration;        /* eDMA group arbitration. */

    VAR(eDMAGroupPriorityType, AUTOMATIC) prioGroup0;                   /* eDMA group 0 priority. */
    VAR(eDMAGroupPriorityType, AUTOMATIC) prioGroup1;                   /* eDMA group 1 priority. */
    VAR(eDMAGroupPriorityType, AUTOMATIC) prioGroup2;                   /* eDMA group 2 priority. */
    VAR(eDMAGroupPriorityType, AUTOMATIC) prioGroup3;                   /* eDMA group 3 priority. */

    VAR(boolean, AUTOMATIC) haltOnError;
} eDMAModuleConfigType;

typedef enum
{
    EDMA_TRANSFER_SIZE_1B  = 0x0U,
    EDMA_TRANSFER_SIZE_2B  = 0x1U,
    EDMA_TRANSFER_SIZE_4B  = 0x2U,
#ifdef RESOURCE_SUPPORT_TRANS_8_32BYTES
	EDMA_TRANSFER_SIZE_8B  = 0x3U,
	EDMA_TRANSFER_SIZE_32B  = 0x5U,
#else
    EDMA_TRANSFER_SIZE_16B = 0x4U,
#endif /* RESOURCE_SUPPORT_TRANS_8_32BYTES */
} eDMATransferSizeType;

typedef enum
{
    EDMA_TRANSFER_TYPE_PERIPHTOMEM = 0U,   /* Transfer from peripheral to memory */
    EDMA_TRANSFER_TYPE_MEMTOPERIPH = 1U,        /* Transfer from memory to peripheral */
    EDMA_TRANSFER_TYPE_MEMTOMEM = 2U,           /* Transfer from memory to memory */
    EDMA_TRANSFER_TYPE_PERIPHTOPERIPH = 3U      /* Transfer from peripheral to peripheral */
} eDMATransferType;

typedef struct
{
    VAR(uint32, AUTOMATIC) address;
    VAR(uint32, AUTOMATIC) length;
    VAR(eDMATransferType, AUTOMATIC) type;
} eDMAScatterGatherListType;

typedef enum
{
    EDMA_CHN_PRIORITY0 = 0U,
    EDMA_CHN_PRIORITY1 = 1U,
    EDMA_CHN_PRIORITY2 = 2U,
    EDMA_CHN_PRIORITY3 = 3U,
    EDMA_CHN_PRIORITY4 = 4U,
    EDMA_CHN_PRIORITY5 = 5U,
    EDMA_CHN_PRIORITY6 = 6U,
    EDMA_CHN_PRIORITY7 = 7U,
    EDMA_CHN_PRIORITY8 = 8U,
    EDMA_CHN_PRIORITY9 = 9U,
    EDMA_CHN_PRIORITY10 = 10U,
    EDMA_CHN_PRIORITY11 = 11U,
    EDMA_CHN_PRIORITY12 = 12U,
    EDMA_CHN_PRIORITY13 = 13U,
    EDMA_CHN_PRIORITY14 = 14U,
    EDMA_CHN_PRIORITY15 = 15U,

    EDMA_CHN_PRIORITY_DEFALUT = 255U
} eDMAChannelPriorityType;

typedef enum
{
    EDMA_ADDRESS_MODULO_OFF = 0U,
    EDMA_ADDRESS_MODULO_2B = 1U,
    EDMA_ADDRESS_MODULO_4B = 2U,
    EDMA_ADDRESS_MODULO_8B = 3U,
    EDMA_ADDRESS_MODULO_16B = 4U,
    EDMA_ADDRESS_MODULO_32B = 5U,
    EDMA_ADDRESS_MODULO_64B = 6U,
    EDMA_ADDRESS_MODULO_128B = 7U,
    EDMA_ADDRESS_MODULO_256B = 8U,
    EDMA_ADDRESS_MODULO_512B = 9U,
    EDMA_ADDRESS_MODULO_1KB = 10U,
    EDMA_ADDRESS_MODULO_2KB = 11U,
    EDMA_ADDRESS_MODULO_4KB = 12U,
    EDMA_ADDRESS_MODULO_8KB = 13U,
    EDMA_ADDRESS_MODULO_16KB = 14U,
    EDMA_ADDRESS_MODULO_32KB = 15U,
    EDMA_ADDRESS_MODULO_64KB = 16U,
    EDMA_ADDRESS_MODULO_128KB = 17U,
    EDMA_ADDRESS_MODULO_256KB = 18U,
    EDMA_ADDRESS_MODULO_512KB = 19U,
    EDMA_ADDRESS_MODULO_1MB = 20U,
    EDMA_ADDRESS_MODULO_2MB = 21U,
    EDMA_ADDRESS_MODULO_4MB = 22U,
    EDMA_ADDRESS_MODULO_8MB = 23U,
    EDMA_ADDRESS_MODULO_16MB = 24U,
    EDMA_ADDRESS_MODULO_32MB = 25U,
    EDMA_ADDRESS_MODULO_64MB = 26U,
    EDMA_ADDRESS_MODULO_128MB = 27U,
    EDMA_ADDRESS_MODULO_256MB = 28U,
    EDMA_ADDRESS_MODULO_512MB = 29U,
    EDMA_ADDRESS_MODULO_1GB = 30U,
    EDMA_ADDRESS_MODULO_2GB = 31U
} eDMAModuloType;

typedef void (*eDMACallbackType) \
( \
	P2CONST(void, AUTOMATIC, EDMA_APPL_DATA) parameter, \
    VAR(eDMAChnStatusType, AUTOMATIC) status, \
    VAR(uint8, AUTOMATIC) mappedChannel \
);

typedef struct
{
    VAR(eDMAChannelPriorityType, AUTOMATIC) chnPrioSet;     /* eDMA channel priority - only used when channel
                                                               arbitration mode is 'Fixed priority'. */
    VAR(uint8, AUTOMATIC) mappedChnConfig;                  /* eDMA virtual channel number */

    VAR(eDMARequestSourceType, AUTOMATIC) reqSource;        /* Selects the source of the DMA request for this channel */

    VAR(eDMACallbackType, AUTOMATIC) callback;              /* Callback that will be registered for this channel */
    P2VAR(void, AUTOMATIC, EDMA_APPL_DATA) callbackParam;   /* Parameter passed to the channel callback */
    VAR(eDMACallbackType, AUTOMATIC) errCallback;              /* Callback that will be registered for this channel */
    P2VAR(void, AUTOMATIC, EDMA_APPL_DATA) errCallbackParam;   /* Parameter passed to the channel error callback */
    VAR(boolean, AUTOMATIC) triggerEn;                      /* Enables the periodic trigger capability for the DMA channel. */

    VAR(boolean, AUTOMATIC) chnErrIntEn;                    /* enable/disable eDMA error channel interrupt. */
    VAR(boolean, AUTOMATIC) preemptionEn;                   /* Channel n can be temporarily suspended by the service request of a higher priority channel */
    VAR(boolean, AUTOMATIC) preemptAbilityDisable;          /* Channel n cannot suspend any channel, regardless of channel priority */
    VAR(boolean, AUTOMATIC) MasterIdReplicationEn;          /* Enable Master ID replication */
} eDMAChanConfigType;

typedef struct
{
    VAR(uint8, AUTOMATIC) channel;                          /* eDMA virtual channel number */    
    VAR(boolean, AUTOMATIC) isUsed;                         /* Mark whether the channel is in use */ 
    VAR(eDMAChannelPriorityType, AUTOMATIC) chPriority;     /* Channel priority. Unused channels are assigned a default priority */ 
} eDMAChPriorityCfg;

typedef struct
{
    VAR(uint8, AUTOMATIC) mappedChn;                        /* Virtual channel number. */
    VAR(eDMACallbackType, AUTOMATIC) callback;              /* Callback function pointer for the eDMA channel. It will
                                                               be called at the eDMA channel complete and eDMA channel error. */
    VAR(eDMACallbackType, AUTOMATIC) errcallback;              /* Callback function pointer for the eDMA channel. It will
                                                               be called at the eDMA channel complete and eDMA channel error. */                                                          
    P2VAR(void, AUTOMATIC, EDMA_APPL_DATA) parameter;       /* Parameter for the callback function pointer. */
    P2VAR(void, AUTOMATIC, EDMA_APPL_DATA) errparameter;       /* Parameter for the callback function pointer. */
    volatile VAR(eDMAChnStatusType, AUTOMATIC) status;      /* eDMA channel status. */
} eDMAChnStateType;

typedef struct
{
    VAR(uint32, AUTOMATIC) SADDR;
    VAR(uint16, AUTOMATIC) ATTR;
    VAR(sint16, AUTOMATIC) SOFF;
    VAR(uint32, AUTOMATIC) NBYTES;
    VAR(sint32, AUTOMATIC) SLAST;
    VAR(uint32, AUTOMATIC) DADDR;
    VAR(uint16, AUTOMATIC) CITER;
    VAR(sint16, AUTOMATIC) DOFF;
    VAR(sint32, AUTOMATIC) DLAST_SGA;
    VAR(uint16, AUTOMATIC) BITER;
    VAR(uint16, AUTOMATIC) CSR;
} eDMASwTcdType;

typedef struct
{
    VAR(uint32, AUTOMATIC) majorLpIterCnt;                  /* Number of major loop iterations. */
    VAR(boolean, AUTOMATIC) srcAddrOffsetEn;                /* Selects whether the minor loop offset is applied to the
                                                               source address upon minor loop completion. */
    VAR(boolean, AUTOMATIC) dstAddrOffsetEn;                /* Selects whether the minor loop offset is applied to the
                                                               destination address upon minor loop completion. */
    VAR(sint32, AUTOMATIC) minorLpOffset;                   /* Sign - extended offset applied to the source or destination address
                                                               to form the next - state value after the minor loop completes. */
    VAR(boolean, AUTOMATIC) minorLpLinkEn;                  /* Enables channel - to - channel linking on minor loop complete. */
    VAR(uint8, AUTOMATIC) minorLpLinkChn;                   /* The number of the next channel to be started by DMA
                                                               engine when minor loop completes. */
    VAR(boolean, AUTOMATIC) majorLpLinkEn;                  /* Enables channel - to - channel linking on major loop complete. */
    VAR(uint8, AUTOMATIC) majorLpLinkChn;                   /* The number of the next channel to be started by DMA
                                                               engine when major loop completes. */
} eDMALoopTransferConfigType;

typedef struct
{
    VAR(boolean, AUTOMATIC) minorLpMap;                             /* Configure minor loop map. */
    VAR(uint32, AUTOMATIC) srcAddr;                                 /* Memory address pointing to the source data. */
    VAR(uint32, AUTOMATIC) destAddr;                                /* Memory address pointing to the destination data. */
    VAR(eDMATransferSizeType, AUTOMATIC) srcTransDataSize;          /* Source data transfer size. */
    VAR(eDMATransferSizeType, AUTOMATIC) destTransDataSize;         /* Destination data transfer size. */
    VAR(sint16, AUTOMATIC) srcAddrOffset;                           /* Sign - extended offset applied to the current source address
                                                                       to form the next - state value as each source read/write
                                                                       is completed. */
    VAR(sint16, AUTOMATIC) destAddrOffset;                          /* Sign - extended offset applied to the current destination
                                                                       address to form the next - state value as each source
                                                                       read/write is completed. */
    VAR(sint32, AUTOMATIC) srcAddrAdjustLast;                       /* Last source address adjustment. */
    VAR(sint32, AUTOMATIC) destAddrAdjustLast;                      /* Last destination address adjustment. Note here it is only
                                                                       valid when scatter/gather feature is not enabled. */
    VAR(eDMAModuloType, AUTOMATIC) srcAddrModulo;                   /* Source address modulo. */
    VAR(eDMAModuloType, AUTOMATIC) destAddrModulo;                  /* Destination address modulo. */
    VAR(uint32, AUTOMATIC) minorTransByte;                          /* Number of bytes to be transferred in each service request
                                                                       of the channel. */
    VAR(boolean, AUTOMATIC) featureScatterGatherEn;                 /* Enable scatter gather feature. */
    VAR(uint32, AUTOMATIC) featureScatterGatherNextDescriptor;      /* The address of the next descriptor to be used, when
                                                                       scatter/gather feature is enabled.
                                                                       Note: this value is not used when scatter/gather
                                                                       feature is disabled. */
    VAR(boolean, AUTOMATIC) completeIntEn;                          /* Enable the interrupt request when the major loop
                                                                       count completes */
    P2VAR(eDMALoopTransferConfigType, AUTOMATIC, EDMA_APPL_DATA) lpTransConfigPtr;   /* Pointer to loop transfer configuration structure
                                                                                        (defines minor/major loop attributes)
                                                                                        Note: this field is only used when minor loop mapping is
                                                                                        enabled from DMA configuration. */
} eDMATransferConfigType;

typedef enum
{
    EDMA_CHN_ENABLE_ERROR_INT = 0U,         /* Error interrupt */
    EDMA_CHN_ENABLE_HALF_MAJOR_LOOP_INT = 1U,    /* Half major loop interrupt. */
    EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT = 2U     /* Complete major loop interrupt. */
} eDMAChannelInterruptType;

typedef struct
{
    P2VAR(eDMAChnStateType, AUTOMATIC, EDMA_APPL_DATA) volatile mapChnState[(uint32)EDMA_MAPPED_CHANNELS]; /* Pointer array storing channel state. */
} edma_state_t;

extern P2VAR(edma_state_t, AUTOMATIC, EDMA_APPL_DATA) s_mapEdmaState ;

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(status_t, EDMA_CODE) EDMA_LLD_SetUpCallback \
( \
    VAR(uint8, AUTOMATIC) mappedChannel,
    VAR(eDMACallbackType, AUTOMATIC) callback,
    P2VAR(void, AUTOMATIC, EDMA_APPL_DATA) parameter \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(status_t, EDMA_CODE) EDMA_LLD_SetErrCallback \
( \
    VAR(uint8, AUTOMATIC) mappedChannel,
    VAR(eDMACallbackType, AUTOMATIC) callback,
    P2VAR(void, AUTOMATIC, EDMA_APPL_DATA) parameter \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_HW_ClearIntStatus(VAR(uint8, AUTOMATIC) mappedChannel);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SwRequestTriggerEn(VAR(uint8, AUTOMATIC) mappedChannel);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(status_t, EDMA_CODE) EDMA_LLD_SetChannelSourceConfig \
( \
    VAR(uint8, AUTOMATIC) mappedChannel,
    VAR(uint32, AUTOMATIC) request,
    VAR(boolean, AUTOMATIC) triggerEn \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(status_t, EDMA_CODE) EDMA_LLD_ChannelInit \
( \
    P2VAR(eDMAChnStateType, AUTOMATIC, EDMA_APPL_DATA) eedma_channelState, \
    P2CONST(eDMAChanConfigType, EDMA_CONST, EDMA_APPL_CONST) eedma_channelConfig \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(status_t, EDMA_CODE) EDMA_LLD_ModuleInit \
( \
    P2VAR(edma_state_t, AUTOMATIC, EDMA_APPL_DATA) edmaState, \
    P2CONST(eDMAModuleConfigType, EDMA_CONST, EDMA_APPL_CONST) userConfig, \
    CONSTP2VAR(eDMAChnStateType, EDMA_CONST, EDMA_APPL_CONST) chnStateArray[], \
    CONSTP2CONST(eDMAChanConfigType, EDMA_CONST, EDMA_APPL_CONST) chnConfigArray[], \
    VAR(uint32, AUTOMATIC) chnCount \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_NoUsedChInit \
( \
    CONSTP2CONST(eDMAChPriorityCfg, EDMA_CONST, EDMA_APPL_CONST) chPriorityCfgs \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_ClearSwTCDStruct \
( \
    P2VAR(eDMASwTcdType, AUTOMATIC, EDMA_APPL_DATA) swtcd \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(status_t, EDMA_CODE) EDMA_LLD_SetSglTransferConfig \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(eDMATransferType, AUTOMATIC) type, \
    VAR(uint32, AUTOMATIC) srcAddr, \
    VAR(uint32, AUTOMATIC) destAddr, \
    VAR(eDMATransferSizeType, AUTOMATIC) transferSize, \
    VAR(uint32, AUTOMATIC) dataBufferSize \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(status_t, EDMA_CODE) EDMA_LLD_SetMultiTransferConfig \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(eDMATransferType, AUTOMATIC) type, \
    VAR(uint32, AUTOMATIC) srcAddr, \
    VAR(uint32, AUTOMATIC) destAddr, \
    VAR(eDMATransferSizeType, AUTOMATIC) transferSize, \
    VAR(uint32, AUTOMATIC) blockSize, \
    VAR(uint32, AUTOMATIC) blockCount, \
    VAR(boolean, AUTOMATIC) disableReqOnCompletion \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(status_t, EDMA_CODE) EDMA_LLD_SetLoopTransferConfig \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    P2CONST(eDMATransferConfigType, EDMA_CONST, EDMA_APPL_CONST) transferConfig \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_CopyConfigToSwTCD \
( \
    P2CONST(eDMATransferConfigType, EDMA_CONST, EDMA_APPL_CONST) config,
    P2VAR(eDMASwTcdType, AUTOMATIC, EDMA_APPL_DATA)stcd \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(status_t, EDMA_CODE) EDMA_LLD_SetScatterGatherTrfCfg \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    P2CONST(eDMASwTcdType, EDMA_CONST, EDMA_APPL_CONST) stcd, \
    VAR(eDMATransferSizeType, AUTOMATIC) transferSize, \
    VAR(uint32, AUTOMATIC) bytesOnEachRequest, \
    P2CONST(eDMAScatterGatherListType, EDMA_CONST, EDMA_APPL_CONST) srcList, \
    P2CONST(eDMAScatterGatherListType, EDMA_CONST, EDMA_APPL_CONST) destList, \
    VAR(uint8, AUTOMATIC) tcdCount \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(status_t, EDMA_CODE) EDMA_LLD_SetChannelRequest(VAR(uint8, AUTOMATIC) mappedChannel);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(status_t, EDMA_CODE) EDMA_LLD_ClearChannelRequest(VAR(uint8, AUTOMATIC) mappedChannel);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_ClearHwTCD(VAR(uint8, AUTOMATIC) mappedChannel);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnSrcAddr \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(uint32, AUTOMATIC) address \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnSrcAddrOffset \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(sint16, AUTOMATIC) offset \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnSrcAddrRdTrfSize \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(eDMATransferSizeType, AUTOMATIC) size \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnSrcAddrLastAdj \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(sint32, AUTOMATIC) adjust \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnDestAddrLastAdj \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(sint32, AUTOMATIC) adjust \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnDestAddr \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(uint32, AUTOMATIC) address \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnDestAddrOffset \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(sint16, AUTOMATIC) offset \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnDestdrWrTrfSize \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(eDMATransferSizeType, AUTOMATIC) size \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnMinorLpTrfByte \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(uint32, AUTOMATIC) nbytes \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnMajorLpIterCount \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(uint32, AUTOMATIC) majorLoopCount \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(uint32, EDMA_CODE) EDMA_LLD_GetChnRemainingIterCnt \
( \
    VAR(uint8, AUTOMATIC) mappedChannel \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnSctGthLinkMode \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(uint32, AUTOMATIC) nextTCDAddr \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnDisReqOnTrfComp \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(boolean, AUTOMATIC) disable \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_SetInterruptConfig \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(eDMAChannelInterruptType, AUTOMATIC) intSrc, \
    VAR(boolean, AUTOMATIC) enable \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_CancelExcutingChnTrf(VAR(boolean, AUTOMATIC) error);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_WaitChnTransferDone(VAR(uint8, AUTOMATIC) mappedChannel);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(eDMAChnStatusType, EDMA_CODE) EDMA_LLD_GetChnConfigStatus \
( \
    VAR(uint8, AUTOMATIC) mappedChannel \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_IRQHandler(VAR(uint8, AUTOMATIC) mappedChannel);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_ErrorIRQHandler(VAR(uint8, AUTOMATIC) mappedChannel);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_Ch0_Ch127_Error_IRQHandler(void);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(boolean, EDMA_CODE) EDMA_LLD_GetMasterID_PAL \
(\
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"
#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(uint8, EDMA_CODE) EDMA_LLD_GetMasterID_MID \
(\
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel \
);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(eDMAChnStatusType, EDMA_CODE) EDMA_LLD_GetErrInfo(VAR(uint8, AUTOMATIC) mappedChannel);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CODE
#include "eDma_MemMap.h"
FUNC(void, EDMA_CODE) EDMA_LLD_ClearErrStatus(VAR(uint8, AUTOMATIC) mappedChannel);
#define EDMA_STOP_SEC_CODE
#include "eDma_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* EDMA_LLD__H_ */
