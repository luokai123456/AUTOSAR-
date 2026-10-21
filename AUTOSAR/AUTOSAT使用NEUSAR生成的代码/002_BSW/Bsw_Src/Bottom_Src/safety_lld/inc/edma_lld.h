/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC3007PT
* DESCRIPTION : CCFC3007PT edma&mux low level drivers h file
* HISTORY     : Initial version
* @file     edma_lld.h
* @version  1.0
* @date     2023 - 04 - 11
* @brief    Initial version.
* @MCAL 	Version: 3.0.1
* @Safety 	Version: 3.0.0
*
*****************************************************************************/
#ifndef SAF_EDMA_LLD_H_
#define SAF_EDMA_LLD_H_
#ifdef __HIGHTEC__
#include "types.h"
#elif defined(__ghs__)

#else
#include "size_t.h"
#endif
#include "derivative.h"
#include "typedefs.h"
#include "status.h"
/* PRQA S 0722 EOF */
/* PRQA S 1534 EOF */
/* PRQA S 3472 EOF */
/* PRQA S 3630 EOF */

#define SAF_EDMA_DEV_ERR(x)                         DEV_ASSERT(x)

#define SAF_EDMA_CH0_CH127_INT                      (1U)
#define SAF_EDMA_CH0_CH127_ERROR_INT                (1U)
#define SAF_EDMA_ERROR_INTERRUPT_LINES              (1U)

#define MODULES_SAF_EDMA_CHANNELS                   (64U)
#define SAF_EDMA_MAPPED_CHANNELS_INTERRUPT_LINES    ((uint32_t)128U)

#define SAF_EDMA_TOTAL_CHANNELS                     (MODULES_SAF_EDMA_CHANNELS * SAF_EDMA_INSTANCE_COUNT)

#define SAF_TCD_SIZE_CALC(number)                   (((number) * 32U) - 1U)
#define SAF_TCD_ADDR_CALC(address)                  (((uint32_t)(address) + 31UL) & ~0x1FUL)

typedef enum
{
    SAF_EDMA_INSTANCE_0 = 0U,
    SAF_EDMA_INSTANCE_1
} SafeDMAIstanceNumType;

typedef enum
{
    SAF_DMAMUX_INSTANCE_0 = 0U,
    SAF_DMAMUX_INSTANCE_1,
    SAF_DMAMUX_INSTANCE_2,
    SAF_DMAMUX_INSTANCE_3,
    SAF_DMAMUX_INSTANCE_4,
    SAF_DMAMUX_INSTANCE_5,
    SAF_DMAMUX_INSTANCE_6,
    SAF_DMAMUX_INSTANCE_7,
    SAF_DMAMUX_INSTANCE_8,
    SAF_DMAMUX_INSTANCE_9
} SAF_DMAMUXInstanceNumType;

typedef enum
{
    SAF_EDMA_CHN_STATUS_NORMAL = 0U,           /* SafeDMA channel normal state. */
    SAF_EDMA_CHN_STATUS_ERROR                  /* An error occurred in the SafeDMA channel. */
} SafeDMAChnStatusType;

typedef enum
{
    SAF_EDMA_ARBITRATION_MODE_FIXED_PRIORITY = 0U,  /* Fixed Priority */
    SAF_EDMA_ARBITRATION_MODE_ROUND_ROBIN           /* Round - Robin arbitration */
} SafeDMASelArbitrationModeType;

typedef struct
{
    uint32_t errh;
    uint32_t errl;
} SafeDMAErrorRegisterType;

typedef enum
{
    SAF_EDMA_GRP_PRIORITY0 = 0U,
    SAF_EDMA_GRP_PRIORITY1 = 1U,
    SAF_EDMA_GRP_PRIORITY2 = 2U,
    SAF_EDMA_GRP_PRIORITY3 = 3U
} SafeDMAGroupPriorityType;

typedef struct
{
    SafeDMASelArbitrationModeType setChnArbitMode;         /* SafeDMA channel arbitration. */
    SafeDMASelArbitrationModeType groupArbitration;        /* SafeDMA group arbitration. */

    SafeDMAGroupPriorityType prioGroup0;                   /* SafeDMA group 0 priority. */
    SafeDMAGroupPriorityType prioGroup1;                   /* SafeDMA group 1 priority. */
    SafeDMAGroupPriorityType prioGroup2;                   /* SafeDMA group 2 priority. */
    SafeDMAGroupPriorityType prioGroup3;                   /* SafeDMA group 3 priority. */

    boolean haltOnError;
} SafeDMAModuleConfigType;

typedef enum
{
    SAF_EDMA_TRANSFER_SIZE_1B  = 0x0U,
    SAF_EDMA_TRANSFER_SIZE_2B  = 0x1U,
    SAF_EDMA_TRANSFER_SIZE_4B  = 0x2U,
    SAF_EDMA_TRANSFER_SIZE_16B = 0x4U,
} SafeDMATransferSizeType;

typedef enum
{
    SAF_EDMA_TRANSFER_TYPE_PERIPHTOMEM = 0U,   /* Transfer from peripheral to memory */
    SAF_EDMA_TRANSFER_TYPE_MEMTOPERIPH,        /* Transfer from memory to peripheral */
    SAF_EDMA_TRANSFER_TYPE_MEMTOMEM,           /* Transfer from memory to memory */
    SAF_EDMA_TRANSFER_TYPE_PERIPHTOPERIPH      /* Transfer from peripheral to peripheral */
} SafeDMATransferType;

typedef struct
{
    uint32_t address;
    uint32_t length;
    SafeDMATransferType type;
} SafeDMAScatterGatherListType;

typedef enum
{
    SAF_EDMA_CHN_PRIORITY0 = 0U,
    SAF_EDMA_CHN_PRIORITY1 = 1U,
    SAF_EDMA_CHN_PRIORITY2 = 2U,
    SAF_EDMA_CHN_PRIORITY3 = 3U,
    SAF_EDMA_CHN_PRIORITY4 = 4U,
    SAF_EDMA_CHN_PRIORITY5 = 5U,
    SAF_EDMA_CHN_PRIORITY6 = 6U,
    SAF_EDMA_CHN_PRIORITY7 = 7U,
    SAF_EDMA_CHN_PRIORITY8 = 8U,
    SAF_EDMA_CHN_PRIORITY9 = 9U,
    SAF_EDMA_CHN_PRIORITY10 = 10U,
    SAF_EDMA_CHN_PRIORITY11 = 11U,
    SAF_EDMA_CHN_PRIORITY12 = 12U,
    SAF_EDMA_CHN_PRIORITY13 = 13U,
    SAF_EDMA_CHN_PRIORITY14 = 14U,
    SAF_EDMA_CHN_PRIORITY15 = 15U,

    SAF_EDMA_CHN_PRIORITY_DEFALUT = 255U
} SafeDMAChannelPriorityType;

typedef enum
{
    SAF_EDMA_ADDRESS_MODULO_OFF = 0U,
    SAF_EDMA_ADDRESS_MODULO_2B,
    SAF_EDMA_ADDRESS_MODULO_4B,
    SAF_EDMA_ADDRESS_MODULO_8B,
    SAF_EDMA_ADDRESS_MODULO_16B,
    SAF_EDMA_ADDRESS_MODULO_32B,
    SAF_EDMA_ADDRESS_MODULO_64B,
    SAF_EDMA_ADDRESS_MODULO_128B,
    SAF_EDMA_ADDRESS_MODULO_256B,
    SAF_EDMA_ADDRESS_MODULO_512B,
    SAF_EDMA_ADDRESS_MODULO_1KB,
    SAF_EDMA_ADDRESS_MODULO_2KB,
    SAF_EDMA_ADDRESS_MODULO_4KB,
    SAF_EDMA_ADDRESS_MODULO_8KB,
    SAF_EDMA_ADDRESS_MODULO_16KB,
    SAF_EDMA_ADDRESS_MODULO_32KB,
    SAF_EDMA_ADDRESS_MODULO_64KB,
    SAF_EDMA_ADDRESS_MODULO_128KB,
    SAF_EDMA_ADDRESS_MODULO_256KB,
    SAF_EDMA_ADDRESS_MODULO_512KB,
    SAF_EDMA_ADDRESS_MODULO_1MB,
    SAF_EDMA_ADDRESS_MODULO_2MB,
    SAF_EDMA_ADDRESS_MODULO_4MB,
    SAF_EDMA_ADDRESS_MODULO_8MB,
    SAF_EDMA_ADDRESS_MODULO_16MB,
    SAF_EDMA_ADDRESS_MODULO_32MB,
    SAF_EDMA_ADDRESS_MODULO_64MB,
    SAF_EDMA_ADDRESS_MODULO_128MB,
    SAF_EDMA_ADDRESS_MODULO_256MB,
    SAF_EDMA_ADDRESS_MODULO_512MB,
    SAF_EDMA_ADDRESS_MODULO_1GB,
    SAF_EDMA_ADDRESS_MODULO_2GB
} SafeDMAModuloType;

/* Physical channel number for channel configuration #0 - #127*/
#define SAF_EDMA_CHN0_NUMBER        (0U)
#define SAF_EDMA_CHN1_NUMBER        (1U)
#define SAF_EDMA_CHN2_NUMBER        (2U)
#define SAF_EDMA_CHN3_NUMBER        (3U)
#define SAF_EDMA_CHN4_NUMBER        (4U)
#define SAF_EDMA_CHN5_NUMBER        (5U)
#define SAF_EDMA_CHN6_NUMBER        (6U)
#define SAF_EDMA_CHN7_NUMBER        (7U)
#define SAF_EDMA_CHN8_NUMBER        (8U)
#define SAF_EDMA_CHN9_NUMBER        (9U)
#define SAF_EDMA_CHN10_NUMBER       (10U)
#define SAF_EDMA_CHN11_NUMBER       (11U)
#define SAF_EDMA_CHN12_NUMBER       (12U)
#define SAF_EDMA_CHN13_NUMBER       (13U)
#define SAF_EDMA_CHN14_NUMBER       (14U)
#define SAF_EDMA_CHN15_NUMBER       (15U)
#define SAF_EDMA_CHN16_NUMBER       (16U)
#define SAF_EDMA_CHN17_NUMBER       (17U)
#define SAF_EDMA_CHN18_NUMBER       (18U)
#define SAF_EDMA_CHN19_NUMBER       (19U)
#define SAF_EDMA_CHN20_NUMBER       (20U)
#define SAF_EDMA_CHN21_NUMBER       (21U)
#define SAF_EDMA_CHN22_NUMBER       (22U)
#define SAF_EDMA_CHN23_NUMBER       (23U)
#define SAF_EDMA_CHN24_NUMBER       (24U)
#define SAF_EDMA_CHN25_NUMBER       (25U)
#define SAF_EDMA_CHN26_NUMBER       (26U)
#define SAF_EDMA_CHN27_NUMBER       (27U)
#define SAF_EDMA_CHN28_NUMBER       (28U)
#define SAF_EDMA_CHN29_NUMBER       (29U)
#define SAF_EDMA_CHN30_NUMBER       (30U)
#define SAF_EDMA_CHN31_NUMBER       (31U)
#define SAF_EDMA_CHN32_NUMBER       (32U)
#define SAF_EDMA_CHN33_NUMBER       (33U)
#define SAF_EDMA_CHN34_NUMBER       (34U)
#define SAF_EDMA_CHN35_NUMBER       (35U)
#define SAF_EDMA_CHN36_NUMBER       (36U)
#define SAF_EDMA_CHN37_NUMBER       (37U)
#define SAF_EDMA_CHN38_NUMBER       (38U)
#define SAF_EDMA_CHN39_NUMBER       (39U)
#define SAF_EDMA_CHN40_NUMBER       (40U)
#define SAF_EDMA_CHN41_NUMBER       (41U)
#define SAF_EDMA_CHN42_NUMBER       (42U)
#define SAF_EDMA_CHN43_NUMBER       (43U)
#define SAF_EDMA_CHN44_NUMBER       (44U)
#define SAF_EDMA_CHN45_NUMBER       (45U)
#define SAF_EDMA_CHN46_NUMBER       (46U)
#define SAF_EDMA_CHN47_NUMBER       (47U)
#define SAF_EDMA_CHN48_NUMBER       (48U)
#define SAF_EDMA_CHN49_NUMBER       (49U)
#define SAF_EDMA_CHN50_NUMBER       (50U)
#define SAF_EDMA_CHN51_NUMBER       (51U)
#define SAF_EDMA_CHN52_NUMBER       (52U)
#define SAF_EDMA_CHN53_NUMBER       (53U)
#define SAF_EDMA_CHN54_NUMBER       (54U)
#define SAF_EDMA_CHN55_NUMBER       (55U)
#define SAF_EDMA_CHN56_NUMBER       (56U)
#define SAF_EDMA_CHN57_NUMBER       (57U)
#define SAF_EDMA_CHN58_NUMBER       (58U)
#define SAF_EDMA_CHN59_NUMBER       (59U)
#define SAF_EDMA_CHN60_NUMBER       (60U)
#define SAF_EDMA_CHN61_NUMBER       (61U)
#define SAF_EDMA_CHN62_NUMBER       (62U)
#define SAF_EDMA_CHN63_NUMBER       (63U)
#define SAF_EDMA_CHN64_NUMBER       (64U)
#define SAF_EDMA_CHN65_NUMBER       (65U)
#define SAF_EDMA_CHN66_NUMBER       (66U)
#define SAF_EDMA_CHN67_NUMBER       (67U)
#define SAF_EDMA_CHN68_NUMBER       (68U)
#define SAF_EDMA_CHN69_NUMBER       (69U)
#define SAF_EDMA_CHN70_NUMBER       (70U)
#define SAF_EDMA_CHN71_NUMBER       (71U)
#define SAF_EDMA_CHN72_NUMBER       (72U)
#define SAF_EDMA_CHN73_NUMBER       (73U)
#define SAF_EDMA_CHN74_NUMBER       (74U)
#define SAF_EDMA_CHN75_NUMBER       (75U)
#define SAF_EDMA_CHN76_NUMBER       (76U)
#define SAF_EDMA_CHN77_NUMBER       (77U)
#define SAF_EDMA_CHN78_NUMBER       (78U)
#define SAF_EDMA_CHN79_NUMBER       (79U)
#define SAF_EDMA_CHN80_NUMBER       (80U)
#define SAF_EDMA_CHN81_NUMBER       (81U)
#define SAF_EDMA_CHN82_NUMBER       (82U)
#define SAF_EDMA_CHN83_NUMBER       (83U)
#define SAF_EDMA_CHN84_NUMBER       (84U)
#define SAF_EDMA_CHN85_NUMBER       (85U)
#define SAF_EDMA_CHN86_NUMBER       (86U)
#define SAF_EDMA_CHN87_NUMBER       (87U)
#define SAF_EDMA_CHN88_NUMBER       (88U)
#define SAF_EDMA_CHN89_NUMBER       (89U)
#define SAF_EDMA_CHN90_NUMBER       (90U)
#define SAF_EDMA_CHN91_NUMBER       (91U)
#define SAF_EDMA_CHN92_NUMBER       (92U)
#define SAF_EDMA_CHN93_NUMBER       (93U)
#define SAF_EDMA_CHN94_NUMBER       (94U)
#define SAF_EDMA_CHN95_NUMBER       (95U)
#define SAF_EDMA_CHN96_NUMBER       (96U)
#define SAF_EDMA_CHN97_NUMBER       (97U)
#define SAF_EDMA_CHN98_NUMBER       (98U)
#define SAF_EDMA_CHN99_NUMBER       (99U)
#define SAF_EDMA_CHN100_NUMBER      (100U)
#define SAF_EDMA_CHN101_NUMBER      (101U)
#define SAF_EDMA_CHN102_NUMBER      (102U)
#define SAF_EDMA_CHN103_NUMBER      (103U)
#define SAF_EDMA_CHN104_NUMBER      (104U)
#define SAF_EDMA_CHN105_NUMBER      (105U)
#define SAF_EDMA_CHN106_NUMBER      (106U)
#define SAF_EDMA_CHN107_NUMBER      (107U)
#define SAF_EDMA_CHN108_NUMBER      (108U)
#define SAF_EDMA_CHN109_NUMBER      (109U)
#define SAF_EDMA_CHN110_NUMBER      (110U)
#define SAF_EDMA_CHN111_NUMBER      (111U)
#define SAF_EDMA_CHN112_NUMBER      (112U)
#define SAF_EDMA_CHN113_NUMBER      (113U)
#define SAF_EDMA_CHN114_NUMBER      (114U)
#define SAF_EDMA_CHN115_NUMBER      (115U)
#define SAF_EDMA_CHN116_NUMBER      (116U)
#define SAF_EDMA_CHN117_NUMBER      (117U)
#define SAF_EDMA_CHN118_NUMBER      (118U)
#define SAF_EDMA_CHN119_NUMBER      (119U)
#define SAF_EDMA_CHN120_NUMBER      (120U)
#define SAF_EDMA_CHN121_NUMBER      (121U)
#define SAF_EDMA_CHN122_NUMBER      (122U)
#define SAF_EDMA_CHN123_NUMBER      (123U)
#define SAF_EDMA_CHN124_NUMBER      (124U)
#define SAF_EDMA_CHN125_NUMBER      (125U)
#define SAF_EDMA_CHN126_NUMBER      (126U)
#define SAF_EDMA_CHN127_NUMBER      (127U)

typedef enum
{
    /* SAF_DMAMUX_0: SAF_DMAMUX Channel 0 - 7 (SafeDMA_0 Channel 0 - 7) */
    SAF_DMAMUX0_RESERVED_0_A            = 0U,   /* SAF_DMAMUX_0: Source 0  */
    SAF_DMAMUX0_ADC_SAR_0_EOC           = 1U,   /* SAF_DMAMUX_0: Source 1  */
    SAF_DMAMUX0_ADC_SAR_1_EOC           = 2U,   /* SAF_DMAMUX_0: Source 2  */
    SAF_DMAMUX0_ADC_SAR_B_EOC           = 3U,   /* SAF_DMAMUX_0: Source 3  */
    SAF_DMAMUX0_ADC_SD_0_EOC            = 4U,   /* SAF_DMAMUX_0: Source 4  */
    SAF_DMAMUX0_DSPI_0_RX               = 5U,   /* SAF_DMAMUX_0: Source 5  */
    SAF_DMAMUX0_DSPI_0_TX               = 6U,   /* SAF_DMAMUX_0: Source 6  */
    SAF_DMAMUX0_DSPI_4_RX               = 7U,   /* SAF_DMAMUX_0: Source 7  */
    SAF_DMAMUX0_DSPI_4_TX               = 8U,   /* SAF_DMAMUX_0: Source 8  */
    SAF_DMAMUX0_RESERVED_1              = 9U,   /* SAF_DMAMUX_0: Source 9  */
    SAF_DMAMUX0_ADC_SAR_4_EOC           = 10U,  /* SAF_DMAMUX_0: Source 10 */
    SAF_DMAMUX0_ADC_SD_3_EOC            = 11U,  /* SAF_DMAMUX_0: Source 11 */
    SAF_DMAMUX0_MCAN_1                  = 12U,  /* SAF_DMAMUX_0: Source 12 */
    SAF_DMAMUX0_MCAN_2                  = 13U,  /* SAF_DMAMUX_0: Source 13 */
    SAF_DMAMUX0_SENT_0_RX_FAST          = 14U,  /* SAF_DMAMUX_0: Source 14 */
    SAF_DMAMUX0_SENT_0_RX_SLOW          = 15U,  /* SAF_DMAMUX_0: Source 15 */
    SAF_DMAMUX0_LINFLEXD_0_RX           = 16U,  /* SAF_DMAMUX_0: Source 16 */
    SAF_DMAMUX0_LINFLEXD_0_TX           = 17U,  /* SAF_DMAMUX_0: Source 17 */
    SAF_DMAMUX0_LINFLEXD_14_RX          = 18U,  /* SAF_DMAMUX_0: Source 18 */
    SAF_DMAMUX0_DSPI_0_CMD              = 19U,  /* SAF_DMAMUX_0: Source 19 */
    SAF_DMAMUX0_DSPI_4_CMD              = 20U,  /* SAF_DMAMUX_0: Source 20 */
    SAF_DMAMUX0_MCAN_3                  = 21U,  /* SAF_DMAMUX_0: Source 21 */
    SAF_DMAMUX0_MCAN_4                  = 22U,  /* SAF_DMAMUX_0: Source 22 */
    SAF_DMAMUX0_MCAN_5                  = 23U,  /* SAF_DMAMUX_0: Source 23 */
    SAF_DMAMUX0_MCAN_6                  = 24U,  /* SAF_DMAMUX_0: Source 24 */
    SAF_DMAMUX0_MCAN_7                  = 25U,  /* SAF_DMAMUX_0: Source 25 */
    SAF_DMAMUX0_MCAN_8                  = 26U,  /* SAF_DMAMUX_0: Source 26 */
    SAF_DMAMUX0_ETPU_0                  = 27U,  /* SAF_DMAMUX_0: Source 27 */
    SAF_DMAMUX0_ETPU_1                  = 28U,  /* SAF_DMAMUX_0: Source 28 */
    SAF_DMAMUX0_ETPU_2                  = 29U,  /* SAF_DMAMUX_0: Source 29 */
    SAF_DMAMUX0_ETPU_12                 = 30U,  /* SAF_DMAMUX_0: Source 30 */
    SAF_DMAMUX0_ETPU_13                 = 31U,  /* SAF_DMAMUX_0: Source 31 */
    SAF_DMAMUX0_ETPU_14                 = 32U,  /* SAF_DMAMUX_0: Source 32 */
    SAF_DMAMUX0_ETPU_15                 = 33U,  /* SAF_DMAMUX_0: Source 33 */
    SAF_DMAMUX0_ETPU_28                 = 34U,  /* SAF_DMAMUX_0: Source 34 */
    SAF_DMAMUX0_ETPU_29                 = 35U,  /* SAF_DMAMUX_0: Source 35 */
    SAF_DMAMUX0_ETPUC_0                 = 36U,  /* SAF_DMAMUX_0: Source 36 */
    SAF_DMAMUX0_ETPUC_1                 = 37U,  /* SAF_DMAMUX_0: Source 37 */
    SAF_DMAMUX0_ETPUC_2                 = 38U,  /* SAF_DMAMUX_0: Source 38 */
    SAF_DMAMUX0_ETPUC_3                 = 39U,  /* SAF_DMAMUX_0: Source 39 */
    SAF_DMAMUX0_ETPUC_12                = 40U,  /* SAF_DMAMUX_0: Source 40 */
    SAF_DMAMUX0_ETPUC_13                = 41U,  /* SAF_DMAMUX_0: Source 41 */
    SAF_DMAMUX0_ETPUC_14                = 42U,  /* SAF_DMAMUX_0: Source 42 */
    SAF_DMAMUX0_ETPUC_15                = 43U,  /* SAF_DMAMUX_0: Source 43 */
    SAF_DMAMUX0_ETPUC_28                = 44U,  /* SAF_DMAMUX_0: Source 44 */
    SAF_DMAMUX0_ETPUC_29                = 45U,  /* SAF_DMAMUX_0: Source 45 */
    SAF_DMAMUX0_ETPUC_30                = 46U,  /* SAF_DMAMUX_0: Source 46 */
    SAF_DMAMUX0_ETPUC_31                = 47U,  /* SAF_DMAMUX_0: Source 47 */
    SAF_DMAMUX0_RESERVED_2              = 48U,  /* SAF_DMAMUX_0: Source 48 */
    SAF_DMAMUX0_RESERVED_3              = 49U,  /* SAF_DMAMUX_0: Source 49 */
    SAF_DMAMUX0_RESERVED_4              = 50U,  /* SAF_DMAMUX_0: Source 50 */
    SAF_DMAMUX0_EQADC0_ADC01_RFIFO0     = 51U,  /* SAF_DMAMUX_0: Source 51 */
    SAF_DMAMUX0_EQADC0_ADC01_RFIFO1     = 52U,  /* SAF_DMAMUX_0: Source 52 */
    SAF_DMAMUX0_EQADC0_ADC01_RFIFO2     = 53U,  /* SAF_DMAMUX_0: Source 53 */
    SAF_DMAMUX0_EQADC0_ADC01_RFIFO3     = 54U,  /* SAF_DMAMUX_0: Source 54 */
    SAF_DMAMUX0_EQADC0_ADC01_RFIFO4     = 55U,  /* SAF_DMAMUX_0: Source 55 */
    SAF_DMAMUX0_EQADC0_ADC01_RFIFO5     = 56U,  /* SAF_DMAMUX_0: Source 56 */
    SAF_DMAMUX0_EQADC0_ADC01_CFIFO0     = 57U,  /* SAF_DMAMUX_0: Source 57 */
    SAF_DMAMUX0_EQADC0_ADC01_CFIFO1     = 58U,  /* SAF_DMAMUX_0: Source 58 */
    SAF_DMAMUX0_EQADC0_ADC01_CFIFO2     = 59U,  /* SAF_DMAMUX_0: Source 59 */
    SAF_DMAMUX0_EQADC0_ADC01_CFIFO3     = 60U,  /* SAF_DMAMUX_0: Source 60 */
    SAF_DMAMUX0_EQADC0_ADC01_CFIFO4     = 61U,  /* SAF_DMAMUX_0: Source 61 */
    SAF_DMAMUX0_EQADC0_ADC01_CFIFO5     = 62U,  /* SAF_DMAMUX_0: Source 62 */
    SAF_DMAMUX0_ALWAYS_ON_0             = 63U,  /* SAF_DMAMUX_0: Source 63 */

    /* SAF_DMAMUX_1: SAF_DMAMUX Channel 8 - 15 (SafeDMA_0 Channel 8 - 15) */
    SAF_DMAMUX1_RESERVED_0_A            = 64U,  /* SAF_DMAMUX_1: Source 0  */
    SAF_DMAMUX1_DSPI_12_RX              = 65U,  /* SAF_DMAMUX_1: Source 1  */
    SAF_DMAMUX1_DSPI_12_TX              = 66U,  /* SAF_DMAMUX_1: Source 2  */
    SAF_DMAMUX1_LINFLEXD_0_RX           = 67U,  /* SAF_DMAMUX_1: Source 3  */
    SAF_DMAMUX1_LINFLEXD_0_TX           = 68U,  /* SAF_DMAMUX_1: Source 4  */
    SAF_DMAMUX1_LINFLEXD_1_RX           = 69U,  /* SAF_DMAMUX_1: Source 5  */
    SAF_DMAMUX1_LINFLEXD_1_TX           = 70U,  /* SAF_DMAMUX_1: Source 6  */
    SAF_DMAMUX1_LINFLEXD_14_RX          = 71U,  /* SAF_DMAMUX_1: Source 7  */
    SAF_DMAMUX1_LINFLEXD_14_TX          = 72U,  /* SAF_DMAMUX_1: Source 8  */
    SAF_DMAMUX1_SENT_0_FAST             = 73U,  /* SAF_DMAMUX_1: Source 9  */
    SAF_DMAMUX1_SENT_0_SLOW             = 74U,  /* SAF_DMAMUX_1: Source 10 */
    SAF_DMAMUX1_SIPI_CH0                = 75U,  /* SAF_DMAMUX_1: Source 11 */
    SAF_DMAMUX1_SIPI_CH1                = 76U,  /* SAF_DMAMUX_1: Source 12 */
    SAF_DMAMUX1_SIPI_CH2                = 77U,  /* SAF_DMAMUX_1: Source 13 */
    SAF_DMAMUX1_SIPI_CH3                = 78U,  /* SAF_DMAMUX_1: Source 14 */
    SAF_DMAMUX1_SIUL2_REQ0              = 79U,  /* SAF_DMAMUX_1: Source 15 */
    SAF_DMAMUX1_SIUL2_REQ1              = 80U,  /* SAF_DMAMUX_1: Source 16 */
    SAF_DMAMUX1_GTM_TIM0_IRQ0           = 81U,  /* SAF_DMAMUX_1: Source 17 */
    SAF_DMAMUX1_GTM_TIM0_IRQ1           = 82U,  /* SAF_DMAMUX_1: Source 18 */
    SAF_DMAMUX1_GTM_TIM0_IRQ2           = 83U,  /* SAF_DMAMUX_1: Source 19 */
    SAF_DMAMUX1_GTM_TIM0_IRQ3           = 84U,  /* SAF_DMAMUX_1: Source 20 */
    SAF_DMAMUX1_GTM_TIM0_IRQ4           = 85U,  /* SAF_DMAMUX_1: Source 21 */
    SAF_DMAMUX1_GTM_TIM0_IRQ5           = 86U,  /* SAF_DMAMUX_1: Source 22 */
    SAF_DMAMUX1_GTM_TIM0_IRQ6           = 87U,  /* SAF_DMAMUX_1: Source 23 */
    SAF_DMAMUX1_GTM_TIM0_IRQ7           = 88U,  /* SAF_DMAMUX_1: Source 24 */
    SAF_DMAMUX1_GTM_TOM0_IRQ0           = 89U,  /* SAF_DMAMUX_1: Source 25 */
    SAF_DMAMUX1_GTM_TOM0_IRQ1           = 90U,  /* SAF_DMAMUX_1: Source 26 */
    SAF_DMAMUX1_GTM_TOM0_IRQ2           = 91U,  /* SAF_DMAMUX_1: Source 27 */
    SAF_DMAMUX1_GTM_TOM0_IRQ3           = 92U,  /* SAF_DMAMUX_1: Source 28 */
    SAF_DMAMUX1_GTM_TOM0_IRQ4           = 93U,  /* SAF_DMAMUX_1: Source 29 */
    SAF_DMAMUX1_GTM_TOM0_IRQ5           = 94U,  /* SAF_DMAMUX_1: Source 30 */
    SAF_DMAMUX1_GTM_TOM0_IRQ6           = 95U,  /* SAF_DMAMUX_1: Source 31 */
    SAF_DMAMUX1_GTM_TOM0_IRQ7           = 96U,  /* SAF_DMAMUX_1: Source 32 */
    SAF_DMAMUX1_GTM_ATOM0_IRQ0          = 97U,  /* SAF_DMAMUX_1: Source 33 */
    SAF_DMAMUX1_GTM_ATOM0_IRQ1          = 98U,  /* SAF_DMAMUX_1: Source 34 */
    SAF_DMAMUX1_GTM_ATOM0_IRQ2          = 99U,  /* SAF_DMAMUX_1: Source 35 */
    SAF_DMAMUX1_GTM_ATOM0_IRQ3          = 100U, /* SAF_DMAMUX_1: Source 36 */
    SAF_DMAMUX1_GTM_MCS0_IRQ0           = 101U, /* SAF_DMAMUX_1: Source 37 */
    SAF_DMAMUX1_GTM_MCS0_IRQ1           = 102U, /* SAF_DMAMUX_1: Source 38 */
    SAF_DMAMUX1_GTM_MCS0_IRQ2           = 103U, /* SAF_DMAMUX_1: Source 39 */
    SAF_DMAMUX1_GTM_MCS0_IRQ3           = 104U, /* SAF_DMAMUX_1: Source 40 */
    SAF_DMAMUX1_GTM_MCS0_IRQ4           = 105U, /* SAF_DMAMUX_1: Source 41 */
    SAF_DMAMUX1_GTM_MCS0_IRQ5           = 106U, /* SAF_DMAMUX_1: Source 42 */
    SAF_DMAMUX1_GTM_MCS0_IRQ6           = 107U, /* SAF_DMAMUX_1: Source 43 */
    SAF_DMAMUX1_GTM_MCS0_IRQ7           = 108U, /* SAF_DMAMUX_1: Source 44 */
    SAF_DMAMUX1_LINFLEXD_15_RX          = 109U, /* SAF_DMAMUX_1: Source 45 */
    SAF_DMAMUX1_LINFLEXD_15_TX          = 110U, /* SAF_DMAMUX_1: Source 46 */
    SAF_DMAMUX1_DSPI_5_RX               = 111U, /* SAF_DMAMUX_1: Source 47 */
    SAF_DMAMUX1_DSPI_5_TX               = 112U, /* SAF_DMAMUX_1: Source 48 */
    SAF_DMAMUX1_DSPI_5_CMD              = 113U, /* SAF_DMAMUX_1: Source 49 */
    SAF_DMAMUX1_DSPI_12_CMD             = 114U, /* SAF_DMAMUX_1: Source 50 */
    SAF_DMAMUX1_RESERVED_1              = 115U, /* SAF_DMAMUX_1: Source 51 */
    SAF_DMAMUX1_RESERVED_2              = 116U, /* SAF_DMAMUX_1: Source 52 */
    SAF_DMAMUX1_DSPI_0_RX               = 117U, /* SAF_DMAMUX_1: Source 53 */
    SAF_DMAMUX1_DSPI_0_TX               = 118U, /* SAF_DMAMUX_1: Source 54 */
    SAF_DMAMUX1_ADC_SAR_0_EOC           = 119U, /* SAF_DMAMUX_1: Source 55 */
    SAF_DMAMUX1_ADC_SAR_4_EOC           = 120U, /* SAF_DMAMUX_1: Source 56 */
    SAF_DMAMUX1_ADC_SD_3_EOC            = 121U, /* SAF_DMAMUX_1: Source 57 */
    SAF_DMAMUX1_RESERVED_3              = 122U, /* SAF_DMAMUX_1: Source 58 */
    SAF_DMAMUX1_ALWAYS_ON_0             = 123U, /* SAF_DMAMUX_1: Source 59 */
    SAF_DMAMUX1_ALWAYS_ON_1             = 124U, /* SAF_DMAMUX_1: Source 60 */
    SAF_DMAMUX1_ALWAYS_ON_2             = 125U, /* SAF_DMAMUX_1: Source 61 */
    SAF_DMAMUX1_ALWAYS_ON_3             = 126U, /* SAF_DMAMUX_1: Source 62 */
    SAF_DMAMUX1_ALWAYS_ON_4             = 127U, /* SAF_DMAMUX_1: Source 63 */

    /* SAF_DMAMUX_2: SAF_DMAMUX Channel 16 - 23 (SafeDMA_0 Channel 16 - 23) */
    SAF_DMAMUX2_RESERVED_0_A            = 128U, /* SAF_DMAMUX_2: Source 0  */
    SAF_DMAMUX2_ADC_SAR_2_EOC           = 129U, /* SAF_DMAMUX_2: Source 1  */
    SAF_DMAMUX2_ADC_SD_1_EOC            = 130U, /* SAF_DMAMUX_2: Source 2  */
    SAF_DMAMUX2_DSPI_1_RX               = 131U, /* SAF_DMAMUX_2: Source 3  */
    SAF_DMAMUX2_DSPI_1_TX               = 132U, /* SAF_DMAMUX_2: Source 4  */
    SAF_DMAMUX2_SENT_1_FAST             = 133U, /* SAF_DMAMUX_2: Source 5  */
    SAF_DMAMUX2_SENT_1_SLOW             = 134U, /* SAF_DMAMUX_2: Source 6  */
    SAF_DMAMUX2_PSI5_0_CH0_RX_PSI5      = 135U, /* SAF_DMAMUX_2: Source 7  */
    SAF_DMAMUX2_PSI5_0_CH0_RX_SENT      = 136U, /* SAF_DMAMUX_2: Source 8  */
    SAF_DMAMUX2_SIUL2_REQ2              = 137U, /* SAF_DMAMUX_2: Source 9  */
    SAF_DMAMUX2_SIUL2_REQ4              = 138U, /* SAF_DMAMUX_2: Source 10 */
    SAF_DMAMUX2_GTM_PSM0_IRQ0           = 139U, /* SAF_DMAMUX_2: Source 11 */
    SAF_DMAMUX2_GTM_PSM0_IRQ1           = 140U, /* SAF_DMAMUX_2: Source 12 */
    SAF_DMAMUX2_GTM_PSM0_IRQ2           = 141U, /* SAF_DMAMUX_2: Source 13 */
    SAF_DMAMUX2_GTM_PSM0_IRQ3           = 142U, /* SAF_DMAMUX_2: Source 14 */
    SAF_DMAMUX2_GTM_TIM1_IRQ0           = 143U, /* SAF_DMAMUX_2: Source 15 */
    SAF_DMAMUX2_GTM_TIM1_IRQ1           = 144U, /* SAF_DMAMUX_2: Source 16 */
    SAF_DMAMUX2_GTM_TIM1_IRQ2           = 145U, /* SAF_DMAMUX_2: Source 17 */
    SAF_DMAMUX2_GTM_TIM1_IRQ3           = 146U, /* SAF_DMAMUX_2: Source 18 */
    SAF_DMAMUX2_GTM_TOM1_IRQ0           = 147U, /* SAF_DMAMUX_2: Source 19 */
    SAF_DMAMUX2_GTM_TOM1_IRQ1           = 148U, /* SAF_DMAMUX_2: Source 20 */
    SAF_DMAMUX2_GTM_TOM1_IRQ2           = 149U, /* SAF_DMAMUX_2: Source 21 */
    SAF_DMAMUX2_GTM_TOM1_IRQ3           = 150U, /* SAF_DMAMUX_2: Source 22 */
    SAF_DMAMUX2_GTM_ATOM1_IRQ0          = 151U, /* SAF_DMAMUX_2: Source 23 */
    SAF_DMAMUX2_GTM_ATOM1_IRQ1          = 152U, /* SAF_DMAMUX_2: Source 24 */
    SAF_DMAMUX2_GTM_MCS1_IRQ0           = 153U, /* SAF_DMAMUX_2: Source 25 */
    SAF_DMAMUX2_GTM_MCS1_IRQ1           = 154U, /* SAF_DMAMUX_2: Source 26 */
    SAF_DMAMUX2_GTM_MCS1_IRQ2           = 155U, /* SAF_DMAMUX_2: Source 27 */
    SAF_DMAMUX2_GTM_MCS1_IRQ3           = 156U, /* SAF_DMAMUX_2: Source 28 */
    SAF_DMAMUX2_GTM_TIM2_IRQ0           = 157U, /* SAF_DMAMUX_2: Source 29 */
    SAF_DMAMUX2_GTM_TIM2_IRQ1           = 158U, /* SAF_DMAMUX_2: Source 30 */
    SAF_DMAMUX2_GTM_TIM2_IRQ2           = 159U, /* SAF_DMAMUX_2: Source 31 */
    SAF_DMAMUX2_GTM_TIM2_IRQ3           = 160U, /* SAF_DMAMUX_2: Source 32 */
    SAF_DMAMUX2_GTM_ATOM2_IRQ0          = 161U, /* SAF_DMAMUX_2: Source 33 */
    SAF_DMAMUX2_GTM_ATOM2_IRQ1          = 162U, /* SAF_DMAMUX_2: Source 34 */
    SAF_DMAMUX2_GTM_MCS2_IRQ0           = 163U, /* SAF_DMAMUX_2: Source 35 */
    SAF_DMAMUX2_GTM_MCS2_IRQ1           = 164U, /* SAF_DMAMUX_2: Source 36 */
    SAF_DMAMUX2_GTM_MCS2_IRQ2           = 165U, /* SAF_DMAMUX_2: Source 37 */
    SAF_DMAMUX2_GTM_MCS2_IRQ3           = 166U, /* SAF_DMAMUX_2: Source 38 */
    SAF_DMAMUX2_GTM_ATOM3_IRQ0          = 167U, /* SAF_DMAMUX_2: Source 39 */
    SAF_DMAMUX2_GTM_ATOM3_IRQ1          = 168U, /* SAF_DMAMUX_2: Source 40 */
    SAF_DMAMUX2_ADC_SD_2_EOC            = 169U, /* SAF_DMAMUX_2: Source 41 */
    SAF_DMAMUX2_DSPI_1_CMD              = 170U, /* SAF_DMAMUX_2: Source 42 */
    SAF_DMAMUX2_DSPI_2_RX               = 171U, /* SAF_DMAMUX_2: Source 43 */
    SAF_DMAMUX2_DSPI_2_TX               = 172U, /* SAF_DMAMUX_2: Source 44 */
    SAF_DMAMUX2_LINFLEXD_2_RX           = 173U, /* SAF_DMAMUX_2: Source 45 */
    SAF_DMAMUX2_LINFLEXD_2_TX           = 174U, /* SAF_DMAMUX_2: Source 46 */
    SAF_DMAMUX2_GTM_SPE0                = 175U, /* SAF_DMAMUX_2: Source 47 */
    SAF_DMAMUX2_GTM_SPE1                = 176U, /* SAF_DMAMUX_2: Source 48 */
    SAF_DMAMUX2_PSI5_SPS                = 177U, /* SAF_DMAMUX_2: Source 49 */
    SAF_DMAMUX2_PSI5_SRX                = 178U, /* SAF_DMAMUX_2: Source 50 */
    SAF_DMAMUX2_EQADC1_ADC23_RFIFO0     = 179U, /* SAF_DMAMUX_2: Source 51 */
    SAF_DMAMUX2_EQADC1_ADC23_RFIFO1     = 180U, /* SAF_DMAMUX_2: Source 52 */
    SAF_DMAMUX2_EQADC1_ADC23_RFIFO2     = 181U, /* SAF_DMAMUX_2: Source 53 */
    SAF_DMAMUX2_EQADC1_ADC23_RFIFO3     = 182U, /* SAF_DMAMUX_2: Source 54 */
    SAF_DMAMUX2_EQADC1_ADC23_RFIFO4     = 183U, /* SAF_DMAMUX_2: Source 55 */
    SAF_DMAMUX2_EQADC1_ADC23_RFIFO5     = 184U, /* SAF_DMAMUX_2: Source 56 */
    SAF_DMAMUX2_EQADC1_ADC23_CFIFO0     = 185U, /* SAF_DMAMUX_2: Source 57 */
    SAF_DMAMUX2_EQADC1_ADC23_CFIFO1     = 186U, /* SAF_DMAMUX_2: Source 58 */
    SAF_DMAMUX2_EQADC1_ADC23_CFIFO2     = 187U, /* SAF_DMAMUX_2: Source 59 */
    SAF_DMAMUX2_EQADC1_ADC23_CFIFO3     = 188U, /* SAF_DMAMUX_2: Source 60 */
    SAF_DMAMUX2_EQADC1_ADC23_CFIFO4     = 189U, /* SAF_DMAMUX_2: Source 61 */
    SAF_DMAMUX2_EQADC1_ADC23_CFIFO5     = 190U, /* SAF_DMAMUX_2: Source 62 */
    SAF_DMAMUX2_ALWAYS_ON_0             = 191U, /* SAF_DMAMUX_2: Source 63 */

    /* SAF_DMAMUX_3: SAF_DMAMUX Channel 24 - 31 (SafeDMA_0 Channel 24 - 31) */
    SAF_DMAMUX3_RESERVED_0_A            = 192U, /* SAF_DMAMUX_3: Source 0  */
    SAF_DMAMUX3_ADC_SAR_3_EOC           = 193U, /* SAF_DMAMUX_3: Source 1  */
    SAF_DMAMUX3_DSPI_2_RX               = 194U, /* SAF_DMAMUX_3: Source 2  */
    SAF_DMAMUX3_DSPI_2_TX               = 195U, /* SAF_DMAMUX_3: Source 3  */
    SAF_DMAMUX3_LINFLEXD_2_RX           = 196U, /* SAF_DMAMUX_3: Source 4  */
    SAF_DMAMUX3_LINFLEXD_2_TX           = 197U, /* SAF_DMAMUX_3: Source 5  */
    SAF_DMAMUX3_I2C_0_RX                = 198U, /* SAF_DMAMUX_3: Source 6  */
    SAF_DMAMUX3_I2C_0_TX                = 199U, /* SAF_DMAMUX_3: Source 7  */
    SAF_DMAMUX3_PSI5_1_CH0_RX_PSI5      = 200U, /* SAF_DMAMUX_3: Source 8  */
    SAF_DMAMUX3_PSI5_1_CH0_RX_SENT      = 201U, /* SAF_DMAMUX_3: Source 9  */
    SAF_DMAMUX3_SIUL2_REQ5              = 202U, /* SAF_DMAMUX_3: Source 10 */

    SAF_DMAMUX3_SIUL2_REQ8              = 233U, /* SAF_DMAMUX_3: Source 41 */
    SAF_DMAMUX3_SIUL2_REQ3              = 234U, /* SAF_DMAMUX_3: Source 42 */

    SAF_DMAMUX3_EQADC2_ADC45_RFIFO0     = 243U, /* SAF_DMAMUX_3: Source 51 */
    SAF_DMAMUX3_EQADC2_ADC45_RFIFO1     = 244U, /* SAF_DMAMUX_3: Source 52 */
    SAF_DMAMUX3_EQADC2_ADC45_RFIFO2     = 245U, /* SAF_DMAMUX_3: Source 53 */
    SAF_DMAMUX3_EQADC2_ADC45_RFIFO3     = 246U, /* SAF_DMAMUX_3: Source 54 */
    SAF_DMAMUX3_EQADC2_ADC45_RFIFO4     = 247U, /* SAF_DMAMUX_3: Source 55 */
    SAF_DMAMUX3_EQADC2_ADC45_RFIFO5     = 248U, /* SAF_DMAMUX_3: Source 56 */
    SAF_DMAMUX3_EQADC2_ADC45_CFIFO0     = 249U, /* SAF_DMAMUX_3: Source 57 */
    SAF_DMAMUX3_EQADC2_ADC45_CFIFO1     = 250U, /* SAF_DMAMUX_3: Source 58 */
    SAF_DMAMUX3_EQADC2_ADC45_CFIFO2     = 251U, /* SAF_DMAMUX_3: Source 59 */
    SAF_DMAMUX3_EQADC2_ADC45_CFIFO3     = 252U, /* SAF_DMAMUX_3: Source 60 */
    SAF_DMAMUX3_EQADC2_ADC45_CFIFO4     = 253U, /* SAF_DMAMUX_3: Source 61 */
    SAF_DMAMUX3_EQADC2_ADC45_CFIFO5     = 254U, /* SAF_DMAMUX_3: Source 62 */
    SAF_DMAMUX3_ALWAYS_ON_0             = 255U, /* SAF_DMAMUX_3: Source 63 */

    /* SAF_DMAMUX_4: SAF_DMAMUX Channel 32 - 47 (SafeDMA_0 Channel 32 - 47) */
    SAF_DMAMUX4_RESERVED_0_A            = 256U, /* SAF_DMAMUX_4: Source 0  */
    SAF_DMAMUX4_ADC_SAR_4_EOC           = 257U, /* SAF_DMAMUX_4: Source 1  */
    SAF_DMAMUX4_ADC_SAR_6_EOC           = 258U, /* SAF_DMAMUX_4: Source 2  */
    SAF_DMAMUX4_ADC_SD_2_EOC            = 259U, /* SAF_DMAMUX_4: Source 3  */
    SAF_DMAMUX4_ADC_SD_3_EOC            = 260U, /* SAF_DMAMUX_4: Source 4  */
    SAF_DMAMUX4_DSPI_3_RX               = 261U, /* SAF_DMAMUX_4: Source 5  */
    SAF_DMAMUX4_DSPI_3_TX               = 262U, /* SAF_DMAMUX_4: Source 6  */
    SAF_DMAMUX4_LIN_0_RX                = 263U, /* SAF_DMAMUX_4: Source 7  */
    SAF_DMAMUX4_LIN_0_TX                = 264U, /* SAF_DMAMUX_4: Source 8  */
    SAF_DMAMUX4_LIN_14_RX               = 265U, /* SAF_DMAMUX_4: Source 9  */
    SAF_DMAMUX4_LIN_14_TX               = 266U, /* SAF_DMAMUX_4: Source 10 */
    SAF_DMAMUX4_PSI5_0_CH1_RX_PSI5      = 267U, /* SAF_DMAMUX_4: Source 11 */
    SAF_DMAMUX4_PSI5_0_CH1_RX_SENT      = 268U, /* SAF_DMAMUX_4: Source 12 */
    SAF_DMAMUX4_SIPI_CH0                = 269U, /* SAF_DMAMUX_4: Source 13 */
    SAF_DMAMUX4_SIPI_CH1                = 270U, /* SAF_DMAMUX_4: Source 14 */
    SAF_DMAMUX4_SIUL2_REQ9              = 271U, /* SAF_DMAMUX_4: Source 15 */

    SAF_DMAMUX4_MCAN_5                  = 299U, /* SAF_DMAMUX_4: Source 43 */
    SAF_DMAMUX4_MCAN_6                  = 300U, /* SAF_DMAMUX_4: Source 44 */
    SAF_DMAMUX4_SIUL2_REQ6              = 301U, /* SAF_DMAMUX_4: Source 45 */
    SAF_DMAMUX4_SIUL2_REQ7              = 302U, /* SAF_DMAMUX_4: Source 46 */
    SAF_DMAMUX4_SIUL2_REQ12             = 303U, /* SAF_DMAMUX_4: Source 47 */
    SAF_DMAMUX4_SIUL2_REQ13             = 304U, /* SAF_DMAMUX_4: Source 48 */
    SAF_DMAMUX4_SIUL2_REQ14             = 305U, /* SAF_DMAMUX_4: Source 49 */
    SAF_DMAMUX4_SIUL2_REQ15             = 306U, /* SAF_DMAMUX_4: Source 50 */
    SAF_DMAMUX4_EQADC3_ADC67_RFIFO0     = 307U, /* SAF_DMAMUX_4: Source 51 */
    SAF_DMAMUX4_EQADC3_ADC67_RFIFO1     = 308U, /* SAF_DMAMUX_4: Source 52 */
    SAF_DMAMUX4_EQADC3_ADC67_RFIFO2     = 309U, /* SAF_DMAMUX_4: Source 53 */
    SAF_DMAMUX4_EQADC3_ADC67_RFIFO3     = 310U, /* SAF_DMAMUX_4: Source 54 */
    SAF_DMAMUX4_EQADC3_ADC67_RFIFO4     = 311U, /* SAF_DMAMUX_4: Source 55 */
    SAF_DMAMUX4_EQADC3_ADC67_RFIFO5     = 312U, /* SAF_DMAMUX_4: Source 56 */
    SAF_DMAMUX4_EQADC3_ADC67_CFIFO0     = 313U, /* SAF_DMAMUX_4: Source 57 */
    SAF_DMAMUX4_EQADC3_ADC67_CFIFO1     = 314U, /* SAF_DMAMUX_4: Source 58 */
    SAF_DMAMUX4_EQADC3_ADC67_CFIFO2     = 315U, /* SAF_DMAMUX_4: Source 59 */
    SAF_DMAMUX4_EQADC3_ADC67_CFIFO3     = 316U, /* SAF_DMAMUX_4: Source 60 */
    SAF_DMAMUX4_EQADC3_ADC67_CFIFO4     = 317U, /* SAF_DMAMUX_4: Source 61 */
    SAF_DMAMUX4_EQADC3_ADC67_CFIFO5     = 318U, /* SAF_DMAMUX_4: Source 62 */
    SAF_DMAMUX4_ALWAYS_ON_0             = 319U, /* SAF_DMAMUX_4: Source 63 */

    /* SAF_DMAMUX_5: SAF_DMAMUX Channel 48 - 63 (SafeDMA_0 Channel 48 - 63) */
    SAF_DMAMUX5_RESERVED_0_A            = 320U, /* SAF_DMAMUX_5: Source 0  */
    SAF_DMAMUX5_ADC_SAR_7_EOC           = 321U, /* SAF_DMAMUX_5: Source 1  */
    SAF_DMAMUX5_ADC_SD_4_EOC            = 322U, /* SAF_DMAMUX_5: Source 2  */
    SAF_DMAMUX5_ADC_SD_5_EOC            = 323U, /* SAF_DMAMUX_5: Source 3  */
    SAF_DMAMUX5_DSPI_5_RX               = 324U, /* SAF_DMAMUX_5: Source 4  */
    SAF_DMAMUX5_DSPI_5_TX               = 325U, /* SAF_DMAMUX_5: Source 5  */
    SAF_DMAMUX5_LIN_1_RX                = 326U, /* SAF_DMAMUX_5: Source 6  */
    SAF_DMAMUX5_LIN_1_TX                = 327U, /* SAF_DMAMUX_5: Source 7  */
    SAF_DMAMUX5_LIN_15_RX               = 328U, /* SAF_DMAMUX_5: Source 8  */
    SAF_DMAMUX5_LIN_15_TX               = 329U, /* SAF_DMAMUX_5: Source 9  */
    SAF_DMAMUX5_SENT_0_FAST             = 330U, /* SAF_DMAMUX_5: Source 10 */
    SAF_DMAMUX5_SENT_0_SLOW             = 331U, /* SAF_DMAMUX_5: Source 11 */
    SAF_DMAMUX5_SIPI_CH2                = 332U, /* SAF_DMAMUX_5: Source 12 */
    SAF_DMAMUX5_SIPI_CH3                = 333U, /* SAF_DMAMUX_5: Source 13 */
    SAF_DMAMUX5_SIUL2_REQ10             = 334U, /* SAF_DMAMUX_5: Source 14 */

    SAF_DMAMUX5_MCAN_1                  = 354U, /* SAF_DMAMUX_5: Source 34 */
    SAF_DMAMUX5_MCAN_2                  = 355U, /* SAF_DMAMUX_5: Source 35 */
    SAF_DMAMUX5_DSPI3_RX                = 356U, /* SAF_DMAMUX_5: Source 36 */
    SAF_DMAMUX5_DSPI3_TX                = 357U, /* SAF_DMAMUX_5: Source 37 */

    SAF_DMAMUX5_LIN_2_RX                = 359U, /* SAF_DMAMUX_5: Source 39 */
    SAF_DMAMUX5_LIN_2_TX                = 360U, /* SAF_DMAMUX_5: Source 40 */

    SAF_DMAMUX5_MCAN_7                  = 363U, /* SAF_DMAMUX_5: Source 43 */
    SAF_DMAMUX5_MCAN_8                  = 364U, /* SAF_DMAMUX_5: Source 44 */
    SAF_DMAMUX5_MCAN_9                  = 365U, /* SAF_DMAMUX_5: Source 45 */
    SAF_DMAMUX5_MCAN_10                 = 366U, /* SAF_DMAMUX_5: Source 46 */
    SAF_DMAMUX5_MCAN_11                 = 367U, /* SAF_DMAMUX_5: Source 47 */
    SAF_DMAMUX5_MCAN_12                 = 368U, /* SAF_DMAMUX_5: Source 48 */

    SAF_DMAMUX5_EQADC4_ADC89_RFIFO0     = 371U, /* SAF_DMAMUX_5: Source 51 */
    SAF_DMAMUX5_EQADC4_ADC89_RFIFO1     = 372U, /* SAF_DMAMUX_5: Source 52 */
    SAF_DMAMUX5_EQADC4_ADC89_RFIFO2     = 373U, /* SAF_DMAMUX_5: Source 53 */
    SAF_DMAMUX5_EQADC4_ADC89_RFIFO3     = 374U, /* SAF_DMAMUX_5: Source 54 */
    SAF_DMAMUX5_EQADC4_ADC89_RFIFO4     = 375U, /* SAF_DMAMUX_5: Source 55 */
    SAF_DMAMUX5_EQADC4_ADC89_RFIFO5     = 376U, /* SAF_DMAMUX_5: Source 56 */
    SAF_DMAMUX5_EQADC4_ADC89_CFIFO0     = 377U, /* SAF_DMAMUX_5: Source 57 */
    SAF_DMAMUX5_EQADC4_ADC89_CFIFO1     = 378U, /* SAF_DMAMUX_5: Source 58 */
    SAF_DMAMUX5_EQADC4_ADC89_CFIFO2     = 379U, /* SAF_DMAMUX_5: Source 59 */
    SAF_DMAMUX5_EQADC4_ADC89_CFIFO3     = 380U, /* SAF_DMAMUX_5: Source 60 */
    SAF_DMAMUX5_EQADC4_ADC89_CFIFO4     = 381U, /* SAF_DMAMUX_5: Source 61 */
    SAF_DMAMUX5_EQADC4_ADC89_CFIFO5     = 382U, /* SAF_DMAMUX_5: Source 62 */
    SAF_DMAMUX5_ALWAYS_ON_0             = 383U, /* SAF_DMAMUX_5: Source 63 */

    /* SAF_DMAMUX_6: SAF_DMAMUX Channel 64 - 79 (SafeDMA_1 Channel 0 - 15) */
    SAF_DMAMUX6_RESERVED_0_A            = 384U, /* SAF_DMAMUX_6: Source 0  */
    SAF_DMAMUX6_ADC_SAR_8_EOC           = 385U, /* SAF_DMAMUX_6: Source 1  */
    SAF_DMAMUX6_ADC_SAR_9_EOC           = 386U, /* SAF_DMAMUX_6: Source 2  */
    SAF_DMAMUX6_ADC_SAR_10_EOC          = 387U, /* SAF_DMAMUX_6: Source 3  */
    SAF_DMAMUX6_ADC_SAR_5_EOC           = 388U, /* SAF_DMAMUX_6: Source 4  */
    SAF_DMAMUX6_ADC_SD_6_EOC            = 389U, /* SAF_DMAMUX_6: Source 5  */
    SAF_DMAMUX6_ADC_SD_7_EOC            = 390U, /* SAF_DMAMUX_6: Source 6  */
    SAF_DMAMUX6_ADC_SD_8_EOC            = 391U, /* SAF_DMAMUX_6: Source 7  */
    SAF_DMAMUX6_ADC_SD_9_EOC            = 392U, /* SAF_DMAMUX_6: Source 8  */
    SAF_DMAMUX6_PSI5_0_CH2_RX_PSI5      = 393U, /* SAF_DMAMUX_6: Source 9  */
    SAF_DMAMUX6_PSI5_0_CH2_RX_SENT      = 394U, /* SAF_DMAMUX_6: Source 10 */
    SAF_DMAMUX6_PSI5_1_CH1_RX_PSI5      = 395U, /* SAF_DMAMUX_6: Source 11 */
    SAF_DMAMUX6_PSI5_1_CH1_RX_SENT      = 396U, /* SAF_DMAMUX_6: Source 12 */
    SAF_DMAMUX6_DSPI_6_RX               = 397U, /* SAF_DMAMUX_6: Source 13 */
    SAF_DMAMUX6_DSPI_6_TX               = 398U, /* SAF_DMAMUX_6: Source 14 */
    SAF_DMAMUX6_DSPI_6_CMD              = 399U, /* SAF_DMAMUX_6: Source 15 */
    SAF_DMAMUX6_LIN_16_RX               = 400U, /* SAF_DMAMUX_6: Source 16 */
    SAF_DMAMUX6_LIN_16_TX               = 401U, /* SAF_DMAMUX_6: Source 17 */
    SAF_DMAMUX6_I2C_1_RX                = 402U, /* SAF_DMAMUX_6: Source 18 */
    SAF_DMAMUX6_I2C_1_TX                = 403U, /* SAF_DMAMUX_6: Source 19 */

    SAF_DMAMUX6_DSPI_12_RX              = 412U, /* SAF_DMAMUX_6: Source 28 */
    SAF_DMAMUX6_DSPI_12_TX              = 413U, /* SAF_DMAMUX_6: Source 29 */

    SAF_DMAMUX6_MCAN_3                  = 432U, /* SAF_DMAMUX_5: Source 48 */

#if defined(CCFC3008PT)
    SAF_DMAMUX6_RESERVED_1              = 441U, /* SAF_DMAMUX_6: Source 57 */
    SAF_DMAMUX6_RESERVED_2              = 442U, /* SAF_DMAMUX_6: Source 58 */
    SAF_DMAMUX6_RESERVED_3              = 443U, /* SAF_DMAMUX_6: Source 59 */
    SAF_DMAMUX6_RESERVED_4              = 444U, /* SAF_DMAMUX_6: Source 60 */
#endif
#if defined(CCFC3007PT)
    SAF_DMAMUX6_I2S_0_TX                = 441U, /* SAF_DMAMUX_6: Source 57 */
    SAF_DMAMUX6_I2S_0_RX                = 442U, /* SAF_DMAMUX_6: Source 58 */
    SAF_DMAMUX6_I2S_1_TX                = 443U, /* SAF_DMAMUX_6: Source 59 */
    SAF_DMAMUX6_I2S_1_RX                = 444U, /* SAF_DMAMUX_6: Source 60 */
#endif
    SAF_DMAMUX6_RESERVED_5              = 445U, /* SAF_DMAMUX_6: Source 61 */
    SAF_DMAMUX6_RESERVED_6              = 446U, /* SAF_DMAMUX_6: Source 62 */
    SAF_DMAMUX6_ALWAYS_ON_0             = 447U, /* SAF_DMAMUX_6: Source 63 */

    /* SAF_DMAMUX_7: SAF_DMAMUX Channel 80 - 95 (SafeDMA_1 Channel 16 - 31) */
    SAF_DMAMUX7_RESERVED_0_A            = 448U, /* SAF_DMAMUX_7: Source 0  */

    SAF_DMAMUX7_ADC_SD_6_EOC            = 481U, /* SAF_DMAMUX_7: Source 33 */
    SAF_DMAMUX7_ADC_SD_7_EOC            = 482U, /* SAF_DMAMUX_7: Source 34 */
    SAF_DMAMUX7_PSI5_0_CH0_RX_PSI5      = 483U, /* SAF_DMAMUX_7: Source 35 */
    SAF_DMAMUX7_PSI5_0_CH0_RX_SENT      = 484U, /* SAF_DMAMUX_7: Source 36 */
    SAF_DMAMUX7_PSI5_0_CH1_RX_PSI5      = 485U, /* SAF_DMAMUX_7: Source 37 */
    SAF_DMAMUX7_PSI5_0_CH1_RX_SENT      = 486U, /* SAF_DMAMUX_7: Source 38 */
    SAF_DMAMUX7_PSI5_0_CH2_RX_PSI5      = 487U, /* SAF_DMAMUX_7: Source 39 */
    SAF_DMAMUX7_PSI5_0_CH2_RX_SENT      = 488U, /* SAF_DMAMUX_7: Source 40 */
    SAF_DMAMUX7_ADC_SD_0_EOC            = 489U, /* SAF_DMAMUX_7: Source 41 */
    SAF_DMAMUX7_ADC_SD_1_EOC            = 490U, /* SAF_DMAMUX_7: Source 42 */
    SAF_DMAMUX7_ADC_SD_2_EOC            = 491U, /* SAF_DMAMUX_7: Source 43 */
    SAF_DMAMUX7_ADC_SD_3_EOC            = 492U, /* SAF_DMAMUX_7: Source 44 */
    SAF_DMAMUX7_DSPI_3_CMD              = 493U, /* SAF_DMAMUX_7: Source 45 */
    SAF_DMAMUX7_DSPI_3_RX               = 494U, /* SAF_DMAMUX_7: Source 46 */
    SAF_DMAMUX7_DSPI_3_TX               = 495U, /* SAF_DMAMUX_7: Source 47 */
    SAF_DMAMUX7_DSPI_5_CMD              = 496U, /* SAF_DMAMUX_7: Source 48 */
    SAF_DMAMUX7_DSPI_5_RX               = 497U, /* SAF_DMAMUX_7: Source 49 */
    SAF_DMAMUX7_DSPI_5_TX               = 498U, /* SAF_DMAMUX_7: Source 50 */
    SAF_DMAMUX7_MCAN_4                  = 499U, /* SAF_DMAMUX_7: Source 51 */
#if defined(CCFC3008PT)
    SAF_DMAMUX7_RESERVED_1              = 500U, /* SAF_DMAMUX_7: Source 52 */
    SAF_DMAMUX7_RESERVED_2              = 501U, /* SAF_DMAMUX_7: Source 53 */
    SAF_DMAMUX7_RESERVED_3              = 502U, /* SAF_DMAMUX_7: Source 54 */
    SAF_DMAMUX7_RESERVED_4              = 503U, /* SAF_DMAMUX_7: Source 55 */
#endif
#if defined(CCFC3007PT)
    SAF_DMAMUX7_SSI_0_TX                = 500U, /* SAF_DMAMUX_7: Source 52 */
	SAF_DMAMUX7_SSI_0_RX                = 501U, /* SAF_DMAMUX_7: Source 53 */
	SAF_DMAMUX7_SSI_1_TX                = 502U, /* SAF_DMAMUX_7: Source 54 */
	SAF_DMAMUX7_SSI_1_RX                = 503U, /* SAF_DMAMUX_7: Source 55 */
#endif
    SAF_DMAMUX7_RESERVED_5              = 504U, /* SAF_DMAMUX_7: Source 56 */
    SAF_DMAMUX7_RESERVED_6              = 505U, /* SAF_DMAMUX_7: Source 57 */
    SAF_DMAMUX7_RESERVED_7              = 506U, /* SAF_DMAMUX_7: Source 58 */
    SAF_DMAMUX7_RESERVED_8              = 507U, /* SAF_DMAMUX_7: Source 59 */
    SAF_DMAMUX7_RESERVED_9              = 508U, /* SAF_DMAMUX_7: Source 60 */
    SAF_DMAMUX7_RESERVED_10             = 509U, /* SAF_DMAMUX_7: Source 61 */
    SAF_DMAMUX7_RESERVED_11             = 510U, /* SAF_DMAMUX_7: Source 62 */
    SAF_DMAMUX7_ALWAYS_ON_0             = 511U, /* SAF_DMAMUX_7: Source 63 */

    /* SAF_DMAMUX_8: SAF_DMAMUX Channel 96 - 111 (SafeDMA_1 Channel 32 - 47) */
    SAF_DMAMUX8_RESERVED_0_A            = 512U, /* SAF_DMAMUX_8: Source 0  */

    SAF_DMAMUX8_ADC_SD_8_EOC            = 545U, /* SAF_DMAMUX_8: Source 33 */
    SAF_DMAMUX8_PSI5_1_CH0_RX_PSI5      = 546U, /* SAF_DMAMUX_8: Source 34 */
    SAF_DMAMUX8_PSI5_1_CH0_RX_SENT      = 547U, /* SAF_DMAMUX_8: Source 35 */
    SAF_DMAMUX8_PSI5_1_CH1_RX_PSI5      = 548U, /* SAF_DMAMUX_8: Source 36 */
    SAF_DMAMUX8_PSI5_1_CH1_RX_SENT      = 549U, /* SAF_DMAMUX_8: Source 37 */
    SAF_DMAMUX8_ADC_SAR_0_EOC           = 550U, /* SAF_DMAMUX_8: Source 38 */
    SAF_DMAMUX8_ADC_SAR_1_EOC           = 551U, /* SAF_DMAMUX_8: Source 39 */
    SAF_DMAMUX8_ADC_SAR_2_EOC           = 552U, /* SAF_DMAMUX_8: Source 40 */
    SAF_DMAMUX8_ADC_SAR_B_EOC           = 553U, /* SAF_DMAMUX_8: Source 41 */
    SAF_DMAMUX8_ADC_SD_4_EOC            = 554U, /* SAF_DMAMUX_8: Source 42 */
    SAF_DMAMUX8_DSPI_4_CMD              = 555U, /* SAF_DMAMUX_8: Source 43 */
    SAF_DMAMUX8_DSPI_4_RX               = 556U, /* SAF_DMAMUX_8: Source 44 */
    SAF_DMAMUX8_DSPI_4_TX               = 557U, /* SAF_DMAMUX_8: Source 45 */
#if defined(CCFC3008PT)
    SAF_DMAMUX8_RESERVED_1              = 558U, /* SAF_DMAMUX_8: Source 46 */
    SAF_DMAMUX8_RESERVED_2              = 559U, /* SAF_DMAMUX_8: Source 47 */
    SAF_DMAMUX8_RESERVED_3              = 560U, /* SAF_DMAMUX_8: Source 48 */
    SAF_DMAMUX8_RESERVED_4              = 561U, /* SAF_DMAMUX_8: Source 49 */
    SAF_DMAMUX8_RESERVED_5              = 562U, /* SAF_DMAMUX_8: Source 50 */
    SAF_DMAMUX8_RESERVED_6              = 563U, /* SAF_DMAMUX_8: Source 51 */
    SAF_DMAMUX8_RESERVED_7              = 564U, /* SAF_DMAMUX_8: Source 52 */
    SAF_DMAMUX8_RESERVED_8              = 565U, /* SAF_DMAMUX_8: Source 53 */
    SAF_DMAMUX8_RESERVED_9              = 566U, /* SAF_DMAMUX_8: Source 54 */
    SAF_DMAMUX8_RESERVED_10             = 567U, /* SAF_DMAMUX_8: Source 55 */
    SAF_DMAMUX8_RESERVED_11             = 568U, /* SAF_DMAMUX_8: Source 56 */
    SAF_DMAMUX8_RESERVED_12             = 569U, /* SAF_DMAMUX_8: Source 57 */
    SAF_DMAMUX8_RESERVED_13             = 570U, /* SAF_DMAMUX_8: Source 58 */
    SAF_DMAMUX8_RESERVED_14             = 571U, /* SAF_DMAMUX_8: Source 59 */
    SAF_DMAMUX8_RESERVED_15             = 572U, /* SAF_DMAMUX_8: Source 60 */
    SAF_DMAMUX8_RESERVED_16             = 573U, /* SAF_DMAMUX_8: Source 61 */
    SAF_DMAMUX8_RESERVED_17             = 574U, /* SAF_DMAMUX_8: Source 62 */
#endif
#if defined(CCFC3007PT)
    SAF_DMAMUX8_LIN_3_TX                = 558U, /* SAF_DMAMUX_8: Source 46 */
    SAF_DMAMUX8_LIN_3_RX                = 559U, /* SAF_DMAMUX_8: Source 47 */
    SAF_DMAMUX8_LIN_4_TX                = 560U, /* SAF_DMAMUX_8: Source 48 */
    SAF_DMAMUX8_LIN_4_RX                = 561U, /* SAF_DMAMUX_8: Source 49 */
    SAF_DMAMUX8_LIN_5_TX                = 562U, /* SAF_DMAMUX_8: Source 50 */
    SAF_DMAMUX8_LIN_5_RX                = 563U, /* SAF_DMAMUX_8: Source 51 */
    SAF_DMAMUX8_LIN_6_TX                = 564U, /* SAF_DMAMUX_8: Source 52 */
    SAF_DMAMUX8_LIN_6_RX                = 565U, /* SAF_DMAMUX_8: Source 53 */
    SAF_DMAMUX8_LIN_7_TX                = 566U, /* SAF_DMAMUX_8: Source 54 */
    SAF_DMAMUX8_LIN_7_RX                = 567U, /* SAF_DMAMUX_8: Source 55 */
    SAF_DMAMUX8_LIN_8_TX                = 568U, /* SAF_DMAMUX_8: Source 56 */
    SAF_DMAMUX8_LIN_8_RX                = 569U, /* SAF_DMAMUX_8: Source 57 */
    SAF_DMAMUX8_LIN_9_TX                = 570U, /* SAF_DMAMUX_8: Source 58 */
    SAF_DMAMUX8_LIN_9_RX                = 571U, /* SAF_DMAMUX_8: Source 59 */
    SAF_DMAMUX8_LIN_10_TX               = 572U, /* SAF_DMAMUX_8: Source 60 */
    SAF_DMAMUX8_LIN_10_RX               = 573U, /* SAF_DMAMUX_8: Source 61 */
    SAF_DMAMUX8_LIN_11_TX               = 574U, /* SAF_DMAMUX_8: Source 62 */
#endif
    SAF_DMAMUX8_ALWAYS_ON_0             = 575U, /* SAF_DMAMUX_8: Source 63 */

    /* SAF_DMAMUX_9: SAF_DMAMUX Channel 112 - 127 (SafeDMA_1 Channel 48 - 63) */
    SAF_DMAMUX9_RESERVED_0_A            = 576U, /* SAF_DMAMUX_9: Source 0  */

    SAF_DMAMUX9_I2C_0_RX                = 587U, /* SAF_DMAMUX_9: Source 11 */
    SAF_DMAMUX9_I2C_0_TX                = 588U, /* SAF_DMAMUX_9: Source 12 */

    SAF_DMAMUX9_MCAN_1                  = 600U, /* SAF_DMAMUX_9: Source 34 */
    SAF_DMAMUX9_MCAN_2                  = 601U, /* SAF_DMAMUX_9: Source 35 */

    SAF_DMAMUX9_DSPI2_CMD               = 617U, /* SAF_DMAMUX_9: Source 41 */
    SAF_DMAMUX9_DSPI2_RX                = 618U, /* SAF_DMAMUX_9: Source 42 */
    SAF_DMAMUX9_DSPI2_TX                = 619U, /* SAF_DMAMUX_9: Source 43 */
    SAF_DMAMUX9_SIUL2_REQ11             = 620U, /* SAF_DMAMUX_9: Source 44 */
    SAF_DMAMUX9_EMIOS_0_CH0             = 621U, /* SAF_DMAMUX_9: Source 45 */
    SAF_DMAMUX9_EMIOS_0_CH1             = 622U, /* SAF_DMAMUX_9: Source 46 */
    SAF_DMAMUX9_EMIOS_0_CH2             = 623U, /* SAF_DMAMUX_9: Source 47 */
    SAF_DMAMUX9_EMIOS_0_CH3             = 624U, /* SAF_DMAMUX_9: Source 48 */
    SAF_DMAMUX9_EMIOS_0_CH4             = 625U, /* SAF_DMAMUX_9: Source 49 */
    SAF_DMAMUX9_EMIOS_0_CH6             = 626U, /* SAF_DMAMUX_9: Source 50 */
    SAF_DMAMUX9_EMIOS_0_CH7             = 627U, /* SAF_DMAMUX_9: Source 51 */
    SAF_DMAMUX9_EMIOS_0_CH16            = 628U, /* SAF_DMAMUX_9: Source 52 */
    SAF_DMAMUX9_EMIOS_0_CH17            = 629U, /* SAF_DMAMUX_9: Source 53 */
    SAF_DMAMUX9_EMIOS_0_CH18            = 630U, /* SAF_DMAMUX_9: Source 54 */
    SAF_DMAMUX9_EMIOS_0_CH19            = 631U, /* SAF_DMAMUX_9: Source 55 */
    SAF_DMAMUX9_EMIOS_1_CH0             = 632U, /* SAF_DMAMUX_9: Source 56 */
    SAF_DMAMUX9_EMIOS_1_CH1             = 633U, /* SAF_DMAMUX_9: Source 57 */
    SAF_DMAMUX9_EMIOS_1_CH2             = 634U, /* SAF_DMAMUX_9: Source 58 */
    SAF_DMAMUX9_EMIOS_1_CH3             = 635U, /* SAF_DMAMUX_9: Source 59 */
#if defined(CCFC3008PT)
    SAF_DMAMUX9_RESERVED_1              = 636U, /* SAF_DMAMUX_9: Source 60 */
    SAF_DMAMUX9_RESERVED_2              = 637U, /* SAF_DMAMUX_9: Source 61 */
    SAF_DMAMUX9_RESERVED_3              = 638U, /* SAF_DMAMUX_9: Source 62 */
#endif
#if defined(CCFC3007PT)
    SAF_DMAMUX9_LIN_11_RX               = 636U, /* SAF_DMAMUX_9: Source 60 */
    SAF_DMAMUX9_LIN_12_TX               = 637U, /* SAF_DMAMUX_9: Source 61 */
    SAF_DMAMUX9_LIN_12_RX               = 638U, /* SAF_DMAMUX_9: Source 62 */
#endif
    SAF_DMAMUX9_ALWAYS_ON_0             = 639U  /* SAF_DMAMUX_9: Source 63 */
} SafeDMARequestSourceType;  //  todo

typedef void (*SafeDMACallbackType)(void *parameter, SafeDMAChnStatusType status);

typedef struct
{
    SafeDMAChannelPriorityType chnPrioSet;     /* SafeDMA channel priority - only used when channel
                                                  arbitration mode is 'Fixed priority'. */
    uint8_t mappedChnConfig;                /* SafeDMA virtual channel number */

    SafeDMARequestSourceType reqSource;        /* Selects the source of the DMA request for this channel */

    SafeDMACallbackType callback;              /* Callback that will be registered for this channel */
    void * callbackParam;                   /* Parameter passed to the channel callback */
    boolean triggerEn;                      /* Enables the periodic trigger capability for the DMA channel. */

    boolean chnErrIntEn;                    /* enable/disable SafeDMA error channel interrupt. */
} SafeDMAChanConfigType;

typedef struct
{
    uint8_t mappedChn;                      /* Virtual channel number. */
    SafeDMACallbackType callback;              /* Callback function pointer for the SafeDMA channel. It will
                                              be called at the SafeDMA channel complete and SafeDMA channel error. */
    void *parameter;                        /* Parameter for the callback function pointer. */
    volatile SafeDMAChnStatusType status;      /* SafeDMA channel status. */
} SafeDMAChnStateType;

typedef struct
{
    uint32_t SADDR;
    uint16_t ATTR;
    int16_t SOFF;
    uint32_t NBYTES;
    int32_t SLAST;
    uint32_t DADDR;
    uint16_t CITER;
    int16_t DOFF;
    int32_t DLAST_SGA;
    uint16_t BITER;
    uint16_t CSR;
} SafeDMASwTcdType;

typedef struct
{
    uint32_t majorLpIterCnt;                /* Number of major loop iterations. */
    boolean srcAddrOffsetEn;                /* Selects whether the minor loop offset is applied to the
                                                 source address upon minor loop completion. */
    boolean dstAddrOffsetEn;                /* Selects whether the minor loop offset is applied to the
                                                 destination address upon minor loop completion. */
    int32_t minorLpOffset;                  /* Sign - extended offset applied to the source or destination address
                                                 to form the next - state value after the minor loop completes. */
    boolean minorLpLinkEn;                  /* Enables channel - to - channel linking on minor loop complete. */
    uint8_t minorLpLinkChn;                 /* The number of the next channel to be started by DMA
                                                 engine when minor loop completes. */
    boolean majorLpLinkEn;                  /* Enables channel - to - channel linking on major loop complete. */
    uint8_t majorLpLinkChn;                 /* The number of the next channel to be started by DMA
                                                 engine when major loop completes. */
} SafeDMALoopTransferConfigType;

typedef struct
{
    boolean minorLpMap;                             /* Configure minor loop map. */
    uint32_t srcAddr;                               /* Memory address pointing to the source data. */
    uint32_t destAddr;                              /* Memory address pointing to the destination data. */
    SafeDMATransferSizeType srcTransDataSize;          /* Source data transfer size. */
    SafeDMATransferSizeType destTransDataSize;         /* Destination data transfer size. */
    int16_t srcAddrOffset;                          /* Sign - extended offset applied to the current source address
                                                           to form the next - state value as each source read/write
                                                           is completed. */
    int16_t destAddrOffset;                         /* Sign - extended offset applied to the current destination
                                                           address to form the next - state value as each source
                                                           read/write is completed. */
    int32_t srcAddrAdjustLast;                      /* Last source address adjustment. */
    int32_t destAddrAdjustLast;                     /* Last destination address adjustment. Note here it is only
                                                           valid when scatter/gather feature is not enabled. */
    SafeDMAModuloType srcAddrModulo;                   /* Source address modulo. */
    SafeDMAModuloType destAddrModulo;                  /* Destination address modulo. */
    uint32_t minorTransByte;                        /* Number of bytes to be transferred in each service request
                                                           of the channel. */
    boolean featureScatterGatherEn;                 /* Enable scatter gather feature. */
    uint32_t featureScatterGatherNextDescriptor;    /* The address of the next descriptor to be used, when
                                                           scatter/gather feature is enabled.
                                                           Note: this value is not used when scatter/gather
                                                                 feature is disabled. */
    boolean completeIntEn;                          /* Enable the interrupt request when the major loop
                                                           count completes */
    SafeDMALoopTransferConfigType *lpTransConfigPtr;   /* Pointer to loop transfer configuration structure
                                                           (defines minor/major loop attributes)
                                                           Note: this field is only used when minor loop mapping is
                                                                 enabled from DMA configuration. */
} SafeDMATransferConfigType;

typedef enum
{
    SAF_EDMA_CHN_ENABLE_ERROR_INT = 0U,         /* Error interrupt */
    SAF_EDMA_CHN_ENABLE_HALF_MAJOR_LOOP_INT,    /* Half major loop interrupt. */
    SAF_EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT     /* Complete major loop interrupt. */
} SafeDMAChannelInterruptType;

#define SAF_DMAMUX_AVAILABLE
#define SAF_DMAMUX_HAS_TRIG

#define SAF_DMAMUX_CHANNELS                         (16U)
#define SAF_DMAMUX_SOURCE_NUMS                      (64U)

#define SAF_DMAMUX_CHN_REG_INDEX(x)                 (x)
#define SAF_DMAMUX_CHCFG_ENBL(x)                    ((x) << SAF_DMAMUX_CHCFG_ENBL_SHIFT)
#define SAF_DMAMUX_CHCFG_TRIG(x)                    ((x) << SAF_DMAMUX_CHCFG_TRIG_SHIFT)
#define SAF_DMAMUX_CHCFG_SOURCE(x)                  ((x) << SAF_DMAMUX_CHCFG_SOURCE_SHIFT)

#define SAF_DMAMUX_CH_WIDTH                         (6U)
#define SAF_DMAMUX_REQ_SRC_TO_INSTANCE(x)           ((x) >> (uint32_t)SAF_DMAMUX_CH_WIDTH)
#define SAF_DMAMUX_REQ_SRC_TO_CH(x)                 ((x) & ((uint32_t)SAF_DMAMUX_SOURCE_NUMS - 1U))
#define SAF_DMAMUX_SAF_DMA_CH_TO_CH(x)                  (((x) < 32U)?((x) & (0x7U)):((x) & (15U)))

#define SAF_EDMA_CHANNELS                           (64U)
#define SAF_EDMA_CH_WIDTH                           (6U)
#define SAF_EDMA_MCH_TO_INSTANCE(x)                 ((x) >> SAF_EDMA_CH_WIDTH)
#define SAF_EDMA_MCH_TO_CH(x)                       ((x) & ((uint32_t)SAF_EDMA_CHANNELS - 1U))
#define SAF_EDMA_CHN_TO_DCHPRI_INDEX(x)             (x)
#define SAF_EDMA_INSTANCE_COUNT                     (2U)
#define SAF_EDMA_MAPPED_CHANNELS                    (SAF_EDMA_CHANNELS * SAF_EDMA_INSTANCE_COUNT)

typedef struct
{
    SafeDMAChnStateType * volatile mapChnState[(uint32_t)SAF_EDMA_MAPPED_CHANNELS];    /* Pointer array storing channel state. */
} safedma_state_t;

typedef volatile struct eDMA_tag  SAF_DMA_Type;

#define SAF_DMA_0_BASE                              (0xFC0A0000UL)
#define SAF_DMA_0_P                                 ((SAF_DMA_Type *)SAF_DMA_0_BASE)
#define SAF_DMA_1_BASE                              (0xFC0A4000UL)
#define SAF_DMA_1_P                                 ((SAF_DMA_Type *)SAF_DMA_1_BASE)
#define SAF_DMA_BASE_ADDRS                          { SAF_DMA_0_BASE, SAF_DMA_1_BASE }
#define SAF_DMA_BASE_PTRS                           { SAF_DMA_0_P, SAF_DMA_1_P }
#define SAF_DMA_CHN_IRQS                            { DMA0_CH0_IRQn,   DMA0_CH1_IRQn,   DMA0_CH2_IRQn,   DMA0_CH3_IRQn,   DMA0_CH4_IRQn,   DMA0_CH5_IRQn,   DMA0_CH6_IRQn,   DMA0_CH7_IRQn,  \
                                                  DMA0_CH8_IRQn,   DMA0_CH9_IRQn,   DMA0_CH10_IRQn,  DMA0_CH11_IRQn,  DMA0_CH12_IRQn,  DMA0_CH13_IRQn,  DMA0_CH14_IRQn,  DMA0_CH15_IRQn, \
                                                  DMA0_CH16_IRQn,  DMA0_CH17_IRQn,  DMA0_CH18_IRQn,  DMA0_CH19_IRQn,  DMA0_CH20_IRQn,  DMA0_CH21_IRQn,  DMA0_CH22_IRQn,  DMA0_CH23_IRQn, \
                                                  DMA0_CH24_IRQn,  DMA0_CH25_IRQn,  DMA0_CH26_IRQn,  DMA0_CH27_IRQn,  DMA0_CH28_IRQn,  DMA0_CH29_IRQn,  DMA0_CH30_IRQn,  DMA0_CH31_IRQn, \
                                                  DMA0_CH32_IRQn,  DMA0_CH33_IRQn,  DMA0_CH34_IRQn,  DMA0_CH35_IRQn,  DMA0_CH36_IRQn,  DMA0_CH37_IRQn,  DMA0_CH38_IRQn,  DMA0_CH39_IRQn, \
                                                  DMA0_CH40_IRQn,  DMA0_CH41_IRQn,  DMA0_CH42_IRQn,  DMA0_CH43_IRQn,  DMA0_CH44_IRQn,  DMA0_CH45_IRQn,  DMA0_CH46_IRQn,  DMA0_CH47_IRQn, \
                                                  DMA0_CH48_IRQn,  DMA0_CH49_IRQn,  DMA0_CH50_IRQn,  DMA0_CH51_IRQn,  DMA0_CH52_IRQn,  DMA0_CH53_IRQn,  DMA0_CH54_IRQn,  DMA0_CH55_IRQn, \
                                                  DMA0_CH56_IRQn,  DMA0_CH57_IRQn,  DMA0_CH58_IRQn,  DMA0_CH59_IRQn,  DMA0_CH60_IRQn,  DMA0_CH61_IRQn,  DMA0_CH62_IRQn,  DMA0_CH63_IRQn, \
                                                  DMA1_CH0_IRQn,   DMA1_CH1_IRQn,   DMA1_CH2_IRQn,   DMA1_CH3_IRQn,   DMA1_CH4_IRQn,   DMA1_CH5_IRQn,   DMA1_CH6_IRQn,   DMA1_CH7_IRQn,  \
                                                  DMA1_CH8_IRQn,   DMA1_CH9_IRQn,   DMA1_CH10_IRQn,  DMA1_CH11_IRQn,  DMA1_CH12_IRQn,  DMA1_CH13_IRQn,  DMA1_CH14_IRQn,  DMA1_CH15_IRQn, \
                                                  DMA1_CH16_IRQn,  DMA1_CH17_IRQn,  DMA1_CH18_IRQn,  DMA1_CH19_IRQn,  DMA1_CH20_IRQn,  DMA1_CH21_IRQn,  DMA1_CH22_IRQn,  DMA1_CH23_IRQn, \
                                                  DMA1_CH24_IRQn,  DMA1_CH25_IRQn,  DMA1_CH26_IRQn,  DMA1_CH27_IRQn,  DMA1_CH28_IRQn,  DMA1_CH29_IRQn,  DMA1_CH30_IRQn,  DMA1_CH31_IRQn, \
                                                  DMA1_CH32_IRQn,  DMA1_CH33_IRQn,  DMA1_CH34_IRQn,  DMA1_CH35_IRQn,  DMA1_CH36_IRQn,  DMA1_CH37_IRQn,  DMA1_CH38_IRQn,  DMA1_CH39_IRQn, \
                                                  DMA1_CH40_IRQn,  DMA1_CH41_IRQn,  DMA1_CH42_IRQn,  DMA1_CH43_IRQn,  DMA1_CH44_IRQn,  DMA1_CH45_IRQn,  DMA1_CH46_IRQn,  DMA1_CH47_IRQn, \
                                                  DMA1_CH48_IRQn,  DMA1_CH49_IRQn,  DMA1_CH50_IRQn,  DMA1_CH51_IRQn,  DMA1_CH52_IRQn,  DMA1_CH53_IRQn,  DMA1_CH54_IRQn,  DMA1_CH55_IRQn, \
                                                  DMA1_CH56_IRQn,  DMA1_CH57_IRQn,  DMA1_CH58_IRQn,  DMA1_CH59_IRQn,  DMA1_CH60_IRQn,  DMA1_CH61_IRQn,  DMA1_CH62_IRQn,  DMA1_CH63_IRQn  }

#define SAF_DMA_ERROR_IRQS                          { DMA0_ERR0_127_IRQn }

/*----------------------------------------------------------------------------
 -- DMA  Masks
 ---------------------------------------------------------------------------- */

#define SAF_DMA_CR_EDBG_MASK                        0x2u
#define SAF_DMA_CR_EDBG_SHIFT                       1u
#define SAF_DMA_CR_EDBG_WIDTH                       1u
#define SAF_DMA_CR_EDBG(x)                          (((uint32_t)(((uint32_t)(x)) << SAF_DMA_CR_EDBG_SHIFT))&SAF_DMA_CR_EDBG_MASK)
#define SAF_DMA_CR_ERCA_MASK                        0x4u
#define SAF_DMA_CR_ERCA_SHIFT                       2u
#define SAF_DMA_CR_ERCA_WIDTH                       1u
#define SAF_DMA_CR_ERCA(x)                          (((uint32_t)(((uint32_t)(x)) << SAF_DMA_CR_ERCA_SHIFT))&SAF_DMA_CR_ERCA_MASK)
#define SAF_DMA_CR_ERGA_MASK                        0x8u
#define SAF_DMA_CR_ERGA_SHIFT                       3u
#define SAF_DMA_CR_ERGA_WIDTH                       1u
#define SAF_DMA_CR_ERGA(x)                          (((uint32_t)(((uint32_t)(x)) << SAF_DMA_CR_ERGA_SHIFT))&SAF_DMA_CR_ERGA_MASK)
#define SAF_DMA_CR_HOE_MASK                         0x10u
#define SAF_DMA_CR_HOE_SHIFT                        4u
#define SAF_DMA_CR_HOE_WIDTH                        1u
#define SAF_DMA_CR_HOE(x)                           (((uint32_t)(((uint32_t)(x)) << SAF_DMA_CR_HOE_SHIFT))&SAF_DMA_CR_HOE_MASK)
#define SAF_DMA_CR_HALT_MASK                        0x20u
#define SAF_DMA_CR_HALT_SHIFT                       5u
#define SAF_DMA_CR_HALT_WIDTH                       1u
#define SAF_DMA_CR_HALT(x)                          (((uint32_t)(((uint32_t)(x)) << SAF_DMA_CR_HALT_SHIFT))&SAF_DMA_CR_HALT_MASK)
#define SAF_DMA_CR_CLM_MASK                         0x40u
#define SAF_DMA_CR_CLM_SHIFT                        6u
#define SAF_DMA_CR_CLM_WIDTH                        1u
#define SAF_DMA_CR_CLM(x)                           (((uint32_t)(((uint32_t)(x)) << SAF_DMA_CR_CLM_SHIFT))&SAF_DMA_CR_CLM_MASK)
#define SAF_DMA_CR_EMLM_MASK                        0x80u
#define SAF_DMA_CR_EMLM_SHIFT                       7u
#define SAF_DMA_CR_EMLM_WIDTH                       1u
#define SAF_DMA_CR_EMLM(x)                          (((uint32_t)(((uint32_t)(x)) << SAF_DMA_CR_EMLM_SHIFT))&SAF_DMA_CR_EMLM_MASK)
#define SAF_DMA_CR_GRP0PRI_MASK                     0x300u
#define SAF_DMA_CR_GRP0PRI_SHIFT                    8u
#define SAF_DMA_CR_GRP0PRI_WIDTH                    2u
#define SAF_DMA_CR_GRP0PRI(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_CR_GRP0PRI_SHIFT))&SAF_DMA_CR_GRP0PRI_MASK)
#define SAF_DMA_CR_GRP1PRI_MASK                     0xC00u
#define SAF_DMA_CR_GRP1PRI_SHIFT                    10u
#define SAF_DMA_CR_GRP1PRI_WIDTH                    2u
#define SAF_DMA_CR_GRP1PRI(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_CR_GRP1PRI_SHIFT))&SAF_DMA_CR_GRP1PRI_MASK)
#define SAF_DMA_CR_GRP2PRI_MASK                     0x3000u
#define SAF_DMA_CR_GRP2PRI_SHIFT                    12u
#define SAF_DMA_CR_GRP2PRI_WIDTH                    2u
#define SAF_DMA_CR_GRP2PRI(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_CR_GRP2PRI_SHIFT))&SAF_DMA_CR_GRP2PRI_MASK)
#define SAF_DMA_CR_GRP3PRI_MASK                     0xC000u
#define SAF_DMA_CR_GRP3PRI_SHIFT                    14u
#define SAF_DMA_CR_GRP3PRI_WIDTH                    2u
#define SAF_DMA_CR_GRP3PRI(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_CR_GRP3PRI_SHIFT))&SAF_DMA_CR_GRP3PRI_MASK)
#define SAF_DMA_CR_ECX_MASK                         0x10000u
#define SAF_DMA_CR_ECX_SHIFT                        16u
#define SAF_DMA_CR_ECX_WIDTH                        1u
#define SAF_DMA_CR_ECX(x)                           (((uint32_t)(((uint32_t)(x)) << SAF_DMA_CR_ECX_SHIFT))&SAF_DMA_CR_ECX_MASK)
#define SAF_DMA_CR_CX_MASK                          0x20000u
#define SAF_DMA_CR_CX_SHIFT                         17u
#define SAF_DMA_CR_CX_WIDTH                         1u
#define SAF_DMA_CR_CX(x)                            (((uint32_t)(((uint32_t)(x)) << SAF_DMA_CR_CX_SHIFT))&SAF_DMA_CR_CX_MASK)
/* ES Bit Fields */
#define SAF_DMA_ES_DBE_MASK                         0x1u
#define SAF_DMA_ES_DBE_SHIFT                        0u
#define SAF_DMA_ES_DBE_WIDTH                        1u
#define SAF_DMA_ES_DBE(x)                           (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ES_DBE_SHIFT))&SAF_DMA_ES_DBE_MASK)
#define SAF_DMA_ES_SBE_MASK                         0x2u
#define SAF_DMA_ES_SBE_SHIFT                        1u
#define SAF_DMA_ES_SBE_WIDTH                        1u
#define SAF_DMA_ES_SBE(x)                           (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ES_SBE_SHIFT))&SAF_DMA_ES_SBE_MASK)
#define SAF_DMA_ES_SGE_MASK                         0x4u
#define SAF_DMA_ES_SGE_SHIFT                        2u
#define SAF_DMA_ES_SGE_WIDTH                        1u
#define SAF_DMA_ES_SGE(x)                           (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ES_SGE_SHIFT))&SAF_DMA_ES_SGE_MASK)
#define SAF_DMA_ES_NCE_MASK                         0x8u
#define SAF_DMA_ES_NCE_SHIFT                        3u
#define SAF_DMA_ES_NCE_WIDTH                        1u
#define SAF_DMA_ES_NCE(x)                           (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ES_NCE_SHIFT))&SAF_DMA_ES_NCE_MASK)
#define SAF_DMA_ES_DOE_MASK                         0x10u
#define SAF_DMA_ES_DOE_SHIFT                        4u
#define SAF_DMA_ES_DOE_WIDTH                        1u
#define SAF_DMA_ES_DOE(x)                           (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ES_DOE_SHIFT))&SAF_DMA_ES_DOE_MASK)
#define SAF_DMA_ES_DAE_MASK                         0x20u
#define SAF_DMA_ES_DAE_SHIFT                        5u
#define SAF_DMA_ES_DAE_WIDTH                        1u
#define SAF_DMA_ES_DAE(x)                           (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ES_DAE_SHIFT))&SAF_DMA_ES_DAE_MASK)
#define SAF_DMA_ES_SOE_MASK                         0x40u
#define SAF_DMA_ES_SOE_SHIFT                        6u
#define SAF_DMA_ES_SOE_WIDTH                        1u
#define SAF_DMA_ES_SOE(x)                           (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ES_SOE_SHIFT))&SAF_DMA_ES_SOE_MASK)
#define SAF_DMA_ES_SAE_MASK                         0x80u
#define SAF_DMA_ES_SAE_SHIFT                        7u
#define SAF_DMA_ES_SAE_WIDTH                        1u
#define SAF_DMA_ES_SAE(x)                           (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ES_SAE_SHIFT))&SAF_DMA_ES_SAE_MASK)
#define SAF_DMA_ES_ERRCHN_MASK                      0x3F00u
#define SAF_DMA_ES_ERRCHN_SHIFT                     8u
#define SAF_DMA_ES_ERRCHN_WIDTH                     6u
#define SAF_DMA_ES_ERRCHN(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ES_ERRCHN_SHIFT))&SAF_DMA_ES_ERRCHN_MASK)
#define SAF_DMA_ES_CPE_MASK                         0x4000u
#define SAF_DMA_ES_CPE_SHIFT                        14u
#define SAF_DMA_ES_CPE_WIDTH                        1u
#define SAF_DMA_ES_CPE(x)                           (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ES_CPE_SHIFT))&SAF_DMA_ES_CPE_MASK)
#define SAF_DMA_ES_GPE_MASK                         0x8000u
#define SAF_DMA_ES_GPE_SHIFT                        15u
#define SAF_DMA_ES_GPE_WIDTH                        1u
#define SAF_DMA_ES_GPE(x)                           (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ES_GPE_SHIFT))&SAF_DMA_ES_GPE_MASK)
#define SAF_DMA_ES_ECX_MASK                         0x10000u
#define SAF_DMA_ES_ECX_SHIFT                        16u
#define SAF_DMA_ES_ECX_WIDTH                        1u
#define SAF_DMA_ES_ECX(x)                           (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ES_ECX_SHIFT))&SAF_DMA_ES_ECX_MASK)
#define SAF_DMA_ES_UCE_MASK                         0x20000u
#define SAF_DMA_ES_UCE_SHIFT                        17u
#define SAF_DMA_ES_UCE_WIDTH                        1u
#define SAF_DMA_ES_UCE(x)                           (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ES_UCE_SHIFT))&SAF_DMA_ES_UCE_MASK)
#define SAF_DMA_ES_VLD_MASK                         0x80000000u
#define SAF_DMA_ES_VLD_SHIFT                        31u
#define SAF_DMA_ES_VLD_WIDTH                        1u
#define SAF_DMA_ES_VLD(x)                           (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ES_VLD_SHIFT))&SAF_DMA_ES_VLD_MASK)
/* ERQH Bit Fields */
#define SAF_DMA_ERQH_ERQ32_MASK                     0x1u
#define SAF_DMA_ERQH_ERQ32_SHIFT                    0u
#define SAF_DMA_ERQH_ERQ32_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ32(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ32_SHIFT))&SAF_DMA_ERQH_ERQ32_MASK)
#define SAF_DMA_ERQH_ERQ33_MASK                     0x2u
#define SAF_DMA_ERQH_ERQ33_SHIFT                    1u
#define SAF_DMA_ERQH_ERQ33_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ33(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ33_SHIFT))&SAF_DMA_ERQH_ERQ33_MASK)
#define SAF_DMA_ERQH_ERQ34_MASK                     0x4u
#define SAF_DMA_ERQH_ERQ34_SHIFT                    2u
#define SAF_DMA_ERQH_ERQ34_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ34(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ34_SHIFT))&SAF_DMA_ERQH_ERQ34_MASK)
#define SAF_DMA_ERQH_ERQ35_MASK                     0x8u
#define SAF_DMA_ERQH_ERQ35_SHIFT                    3u
#define SAF_DMA_ERQH_ERQ35_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ35(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ35_SHIFT))&SAF_DMA_ERQH_ERQ35_MASK)
#define SAF_DMA_ERQH_ERQ36_MASK                     0x10u
#define SAF_DMA_ERQH_ERQ36_SHIFT                    4u
#define SAF_DMA_ERQH_ERQ36_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ36(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ36_SHIFT))&SAF_DMA_ERQH_ERQ36_MASK)
#define SAF_DMA_ERQH_ERQ37_MASK                     0x20u
#define SAF_DMA_ERQH_ERQ37_SHIFT                    5u
#define SAF_DMA_ERQH_ERQ37_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ37(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ37_SHIFT))&SAF_DMA_ERQH_ERQ37_MASK)
#define SAF_DMA_ERQH_ERQ38_MASK                     0x40u
#define SAF_DMA_ERQH_ERQ38_SHIFT                    6u
#define SAF_DMA_ERQH_ERQ38_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ38(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ38_SHIFT))&SAF_DMA_ERQH_ERQ38_MASK)
#define SAF_DMA_ERQH_ERQ39_MASK                     0x80u
#define SAF_DMA_ERQH_ERQ39_SHIFT                    7u
#define SAF_DMA_ERQH_ERQ39_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ39(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ39_SHIFT))&SAF_DMA_ERQH_ERQ39_MASK)
#define SAF_DMA_ERQH_ERQ40_MASK                     0x100u
#define SAF_DMA_ERQH_ERQ40_SHIFT                    8u
#define SAF_DMA_ERQH_ERQ40_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ40(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ40_SHIFT))&SAF_DMA_ERQH_ERQ40_MASK)
#define SAF_DMA_ERQH_ERQ41_MASK                     0x200u
#define SAF_DMA_ERQH_ERQ41_SHIFT                    9u
#define SAF_DMA_ERQH_ERQ41_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ41(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ41_SHIFT))&SAF_DMA_ERQH_ERQ41_MASK)
#define SAF_DMA_ERQH_ERQ42_MASK                     0x400u
#define SAF_DMA_ERQH_ERQ42_SHIFT                    10u
#define SAF_DMA_ERQH_ERQ42_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ42(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ42_SHIFT))&SAF_DMA_ERQH_ERQ42_MASK)
#define SAF_DMA_ERQH_ERQ43_MASK                     0x800u
#define SAF_DMA_ERQH_ERQ43_SHIFT                    11u
#define SAF_DMA_ERQH_ERQ43_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ43(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ43_SHIFT))&SAF_DMA_ERQH_ERQ43_MASK)
#define SAF_DMA_ERQH_ERQ44_MASK                     0x1000u
#define SAF_DMA_ERQH_ERQ44_SHIFT                    12u
#define SAF_DMA_ERQH_ERQ44_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ44(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ44_SHIFT))&SAF_DMA_ERQH_ERQ44_MASK)
#define SAF_DMA_ERQH_ERQ45_MASK                     0x2000u
#define SAF_DMA_ERQH_ERQ45_SHIFT                    13u
#define SAF_DMA_ERQH_ERQ45_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ45(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ45_SHIFT))&SAF_DMA_ERQH_ERQ45_MASK)
#define SAF_DMA_ERQH_ERQ46_MASK                     0x4000u
#define SAF_DMA_ERQH_ERQ46_SHIFT                    14u
#define SAF_DMA_ERQH_ERQ46_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ46(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ46_SHIFT))&SAF_DMA_ERQH_ERQ46_MASK)
#define SAF_DMA_ERQH_ERQ47_MASK                     0x8000u
#define SAF_DMA_ERQH_ERQ47_SHIFT                    15u
#define SAF_DMA_ERQH_ERQ47_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ47(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ47_SHIFT))&SAF_DMA_ERQH_ERQ47_MASK)
#define SAF_DMA_ERQH_ERQ48_MASK                     0x10000u
#define SAF_DMA_ERQH_ERQ48_SHIFT                    16u
#define SAF_DMA_ERQH_ERQ48_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ48(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ48_SHIFT))&SAF_DMA_ERQH_ERQ48_MASK)
#define SAF_DMA_ERQH_ERQ49_MASK                     0x20000u
#define SAF_DMA_ERQH_ERQ49_SHIFT                    17u
#define SAF_DMA_ERQH_ERQ49_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ49(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ49_SHIFT))&SAF_DMA_ERQH_ERQ49_MASK)
#define SAF_DMA_ERQH_ERQ50_MASK                     0x40000u
#define SAF_DMA_ERQH_ERQ50_SHIFT                    18u
#define SAF_DMA_ERQH_ERQ50_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ50(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ50_SHIFT))&SAF_DMA_ERQH_ERQ50_MASK)
#define SAF_DMA_ERQH_ERQ51_MASK                     0x80000u
#define SAF_DMA_ERQH_ERQ51_SHIFT                    19u
#define SAF_DMA_ERQH_ERQ51_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ51(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ51_SHIFT))&SAF_DMA_ERQH_ERQ51_MASK)
#define SAF_DMA_ERQH_ERQ52_MASK                     0x100000u
#define SAF_DMA_ERQH_ERQ52_SHIFT                    20u
#define SAF_DMA_ERQH_ERQ52_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ52(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ52_SHIFT))&SAF_DMA_ERQH_ERQ52_MASK)
#define SAF_DMA_ERQH_ERQ53_MASK                     0x200000u
#define SAF_DMA_ERQH_ERQ53_SHIFT                    21u
#define SAF_DMA_ERQH_ERQ53_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ53(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ53_SHIFT))&SAF_DMA_ERQH_ERQ53_MASK)
#define SAF_DMA_ERQH_ERQ54_MASK                     0x400000u
#define SAF_DMA_ERQH_ERQ54_SHIFT                    22u
#define SAF_DMA_ERQH_ERQ54_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ54(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ54_SHIFT))&SAF_DMA_ERQH_ERQ54_MASK)
#define SAF_DMA_ERQH_ERQ55_MASK                     0x800000u
#define SAF_DMA_ERQH_ERQ55_SHIFT                    23u
#define SAF_DMA_ERQH_ERQ55_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ55(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ55_SHIFT))&SAF_DMA_ERQH_ERQ55_MASK)
#define SAF_DMA_ERQH_ERQ56_MASK                     0x1000000u
#define SAF_DMA_ERQH_ERQ56_SHIFT                    24u
#define SAF_DMA_ERQH_ERQ56_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ56(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ56_SHIFT))&SAF_DMA_ERQH_ERQ56_MASK)
#define SAF_DMA_ERQH_ERQ57_MASK                     0x2000000u
#define SAF_DMA_ERQH_ERQ57_SHIFT                    25u
#define SAF_DMA_ERQH_ERQ57_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ57(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ57_SHIFT))&SAF_DMA_ERQH_ERQ57_MASK)
#define SAF_DMA_ERQH_ERQ58_MASK                     0x4000000u
#define SAF_DMA_ERQH_ERQ58_SHIFT                    26u
#define SAF_DMA_ERQH_ERQ58_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ58(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ58_SHIFT))&SAF_DMA_ERQH_ERQ58_MASK)
#define SAF_DMA_ERQH_ERQ59_MASK                     0x8000000u
#define SAF_DMA_ERQH_ERQ59_SHIFT                    27u
#define SAF_DMA_ERQH_ERQ59_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ59(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ59_SHIFT))&SAF_DMA_ERQH_ERQ59_MASK)
#define SAF_DMA_ERQH_ERQ60_MASK                     0x10000000u
#define SAF_DMA_ERQH_ERQ60_SHIFT                    28u
#define SAF_DMA_ERQH_ERQ60_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ60(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ60_SHIFT))&SAF_DMA_ERQH_ERQ60_MASK)
#define SAF_DMA_ERQH_ERQ61_MASK                     0x20000000u
#define SAF_DMA_ERQH_ERQ61_SHIFT                    29u
#define SAF_DMA_ERQH_ERQ61_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ61(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ61_SHIFT))&SAF_DMA_ERQH_ERQ61_MASK)
#define SAF_DMA_ERQH_ERQ62_MASK                     0x40000000u
#define SAF_DMA_ERQH_ERQ62_SHIFT                    30u
#define SAF_DMA_ERQH_ERQ62_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ62(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ62_SHIFT))&SAF_DMA_ERQH_ERQ62_MASK)
#define SAF_DMA_ERQH_ERQ63_MASK                     0x80000000u
#define SAF_DMA_ERQH_ERQ63_SHIFT                    31u
#define SAF_DMA_ERQH_ERQ63_WIDTH                    1u
#define SAF_DMA_ERQH_ERQ63(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQH_ERQ63_SHIFT))&SAF_DMA_ERQH_ERQ63_MASK)
/* ERQL Bit Fields */
#define SAF_DMA_ERQL_ERQ0_MASK                      0x1u
#define SAF_DMA_ERQL_ERQ0_SHIFT                     0u
#define SAF_DMA_ERQL_ERQ0_WIDTH                     1u
#define SAF_DMA_ERQL_ERQ0(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ0_SHIFT))&SAF_DMA_ERQL_ERQ0_MASK)
#define SAF_DMA_ERQL_ERQ1_MASK                      0x2u
#define SAF_DMA_ERQL_ERQ1_SHIFT                     1u
#define SAF_DMA_ERQL_ERQ1_WIDTH                     1u
#define SAF_DMA_ERQL_ERQ1(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ1_SHIFT))&SAF_DMA_ERQL_ERQ1_MASK)
#define SAF_DMA_ERQL_ERQ2_MASK                      0x4u
#define SAF_DMA_ERQL_ERQ2_SHIFT                     2u
#define SAF_DMA_ERQL_ERQ2_WIDTH                     1u
#define SAF_DMA_ERQL_ERQ2(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ2_SHIFT))&SAF_DMA_ERQL_ERQ2_MASK)
#define SAF_DMA_ERQL_ERQ3_MASK                      0x8u
#define SAF_DMA_ERQL_ERQ3_SHIFT                     3u
#define SAF_DMA_ERQL_ERQ3_WIDTH                     1u
#define SAF_DMA_ERQL_ERQ3(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ3_SHIFT))&SAF_DMA_ERQL_ERQ3_MASK)
#define SAF_DMA_ERQL_ERQ4_MASK                      0x10u
#define SAF_DMA_ERQL_ERQ4_SHIFT                     4u
#define SAF_DMA_ERQL_ERQ4_WIDTH                     1u
#define SAF_DMA_ERQL_ERQ4(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ4_SHIFT))&SAF_DMA_ERQL_ERQ4_MASK)
#define SAF_DMA_ERQL_ERQ5_MASK                      0x20u
#define SAF_DMA_ERQL_ERQ5_SHIFT                     5u
#define SAF_DMA_ERQL_ERQ5_WIDTH                     1u
#define SAF_DMA_ERQL_ERQ5(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ5_SHIFT))&SAF_DMA_ERQL_ERQ5_MASK)
#define SAF_DMA_ERQL_ERQ6_MASK                      0x40u
#define SAF_DMA_ERQL_ERQ6_SHIFT                     6u
#define SAF_DMA_ERQL_ERQ6_WIDTH                     1u
#define SAF_DMA_ERQL_ERQ6(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ6_SHIFT))&SAF_DMA_ERQL_ERQ6_MASK)
#define SAF_DMA_ERQL_ERQ7_MASK                      0x80u
#define SAF_DMA_ERQL_ERQ7_SHIFT                     7u
#define SAF_DMA_ERQL_ERQ7_WIDTH                     1u
#define SAF_DMA_ERQL_ERQ7(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ7_SHIFT))&SAF_DMA_ERQL_ERQ7_MASK)
#define SAF_DMA_ERQL_ERQ8_MASK                      0x100u
#define SAF_DMA_ERQL_ERQ8_SHIFT                     8u
#define SAF_DMA_ERQL_ERQ8_WIDTH                     1u
#define SAF_DMA_ERQL_ERQ8(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ8_SHIFT))&SAF_DMA_ERQL_ERQ8_MASK)
#define SAF_DMA_ERQL_ERQ9_MASK                      0x200u
#define SAF_DMA_ERQL_ERQ9_SHIFT                     9u
#define SAF_DMA_ERQL_ERQ9_WIDTH                     1u
#define SAF_DMA_ERQL_ERQ9(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ9_SHIFT))&SAF_DMA_ERQL_ERQ9_MASK)
#define SAF_DMA_ERQL_ERQ10_MASK                     0x400u
#define SAF_DMA_ERQL_ERQ10_SHIFT                    10u
#define SAF_DMA_ERQL_ERQ10_WIDTH                    1u
#define SAF_DMA_ERQL_ERQ10(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ10_SHIFT))&SAF_DMA_ERQL_ERQ10_MASK)
#define SAF_DMA_ERQL_ERQ11_MASK                     0x800u
#define SAF_DMA_ERQL_ERQ11_SHIFT                    11u
#define SAF_DMA_ERQL_ERQ11_WIDTH                    1u
#define SAF_DMA_ERQL_ERQ11(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ11_SHIFT))&SAF_DMA_ERQL_ERQ11_MASK)
#define SAF_DMA_ERQL_ERQ12_MASK                     0x1000u
#define SAF_DMA_ERQL_ERQ12_SHIFT                    12u
#define SAF_DMA_ERQL_ERQ12_WIDTH                    1u
#define SAF_DMA_ERQL_ERQ12(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ12_SHIFT))&SAF_DMA_ERQL_ERQ12_MASK)
#define SAF_DMA_ERQL_ERQ13_MASK                     0x2000u
#define SAF_DMA_ERQL_ERQ13_SHIFT                    13u
#define SAF_DMA_ERQL_ERQ13_WIDTH                    1u
#define SAF_DMA_ERQL_ERQ13(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ13_SHIFT))&SAF_DMA_ERQL_ERQ13_MASK)
#define SAF_DMA_ERQL_ERQ14_MASK                     0x4000u
#define SAF_DMA_ERQL_ERQ14_SHIFT                    14u
#define SAF_DMA_ERQL_ERQ14_WIDTH                    1u
#define SAF_DMA_ERQL_ERQ14(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ14_SHIFT))&SAF_DMA_ERQL_ERQ14_MASK)
#define SAF_DMA_ERQL_ERQ15_MASK                     0x8000u
#define SAF_DMA_ERQL_ERQ15_SHIFT                    15u
#define SAF_DMA_ERQL_ERQ15_WIDTH                    1u
#define SAF_DMA_ERQL_ERQ15(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ15_SHIFT))&SAF_DMA_ERQL_ERQ15_MASK)
#define SAF_DMA_ERQL_ERQ16_MASK                     0x10000u
#define SAF_DMA_ERQL_ERQ16_SHIFT                    16u
#define SAF_DMA_ERQL_ERQ16_WIDTH                    1u
#define SAF_DMA_ERQL_ERQ16(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ16_SHIFT))&SAF_DMA_ERQL_ERQ16_MASK)
#define SAF_DMA_ERQL_ERQ17_MASK                     0x20000u
#define SAF_DMA_ERQL_ERQ17_SHIFT                    17u
#define SAF_DMA_ERQL_ERQ17_WIDTH                    1u
#define SAF_DMA_ERQL_ERQ17(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ17_SHIFT))&SAF_DMA_ERQL_ERQ17_MASK)
#define SAF_DMA_ERQL_ERQ18_MASK                     0x40000u
#define SAF_DMA_ERQL_ERQ18_SHIFT                    18u
#define SAF_DMA_ERQL_ERQ18_WIDTH                    1u
#define SAF_DMA_ERQL_ERQ18(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ18_SHIFT))&SAF_DMA_ERQL_ERQ18_MASK)
#define SAF_DMA_ERQL_ERQ19_MASK                     0x80000u
#define SAF_DMA_ERQL_ERQ19_SHIFT                    19u
#define SAF_DMA_ERQL_ERQ19_WIDTH                    1u
#define SAF_DMA_ERQL_ERQ19(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ19_SHIFT))&SAF_DMA_ERQL_ERQ19_MASK)
#define SAF_DMA_ERQL_ERQ20_MASK                     0x100000u
#define SAF_DMA_ERQL_ERQ20_SHIFT                    20u
#define SAF_DMA_ERQL_ERQ20_WIDTH                    1u
#define SAF_DMA_ERQL_ERQ20(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ20_SHIFT))&SAF_DMA_ERQL_ERQ20_MASK)
#define SAF_DMA_ERQL_ERQ21_MASK                     0x200000u
#define SAF_DMA_ERQL_ERQ21_SHIFT                    21u
#define SAF_DMA_ERQL_ERQ21_WIDTH                    1u
#define SAF_DMA_ERQL_ERQ21(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ21_SHIFT))&SAF_DMA_ERQL_ERQ21_MASK)
#define SAF_DMA_ERQL_ERQ22_MASK                     0x400000u
#define SAF_DMA_ERQL_ERQ22_SHIFT                    22u
#define SAF_DMA_ERQL_ERQ22_WIDTH                    1u
#define SAF_DMA_ERQL_ERQ22(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ22_SHIFT))&SAF_DMA_ERQL_ERQ22_MASK)
#define SAF_DMA_ERQL_ERQ23_MASK                     0x800000u
#define SAF_DMA_ERQL_ERQ23_SHIFT                    23u
#define SAF_DMA_ERQL_ERQ23_WIDTH                    1u
#define SAF_DMA_ERQL_ERQ23(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ23_SHIFT))&SAF_DMA_ERQL_ERQ23_MASK)
#define SAF_DMA_ERQL_ERQ24_MASK                     0x1000000u
#define SAF_DMA_ERQL_ERQ24_SHIFT                    24u
#define SAF_DMA_ERQL_ERQ24_WIDTH                    1u
#define SAF_DMA_ERQL_ERQ24(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ24_SHIFT))&SAF_DMA_ERQL_ERQ24_MASK)
#define SAF_DMA_ERQL_ERQ25_MASK                     0x2000000u
#define SAF_DMA_ERQL_ERQ25_SHIFT                    25u
#define SAF_DMA_ERQL_ERQ25_WIDTH                    1u
#define SAF_DMA_ERQL_ERQ25(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ25_SHIFT))&SAF_DMA_ERQL_ERQ25_MASK)
#define SAF_DMA_ERQL_ERQ26_MASK                     0x4000000u
#define SAF_DMA_ERQL_ERQ26_SHIFT                    26u
#define SAF_DMA_ERQL_ERQ26_WIDTH                    1u
#define SAF_DMA_ERQL_ERQ26(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ26_SHIFT))&SAF_DMA_ERQL_ERQ26_MASK)
#define SAF_DMA_ERQL_ERQ27_MASK                     0x8000000u
#define SAF_DMA_ERQL_ERQ27_SHIFT                    27u
#define SAF_DMA_ERQL_ERQ27_WIDTH                    1u
#define SAF_DMA_ERQL_ERQ27(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ27_SHIFT))&SAF_DMA_ERQL_ERQ27_MASK)
#define SAF_DMA_ERQL_ERQ28_MASK                     0x10000000u
#define SAF_DMA_ERQL_ERQ28_SHIFT                    28u
#define SAF_DMA_ERQL_ERQ28_WIDTH                    1u
#define SAF_DMA_ERQL_ERQ28(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ28_SHIFT))&SAF_DMA_ERQL_ERQ28_MASK)
#define SAF_DMA_ERQL_ERQ29_MASK                     0x20000000u
#define SAF_DMA_ERQL_ERQ29_SHIFT                    29u
#define SAF_DMA_ERQL_ERQ29_WIDTH                    1u
#define SAF_DMA_ERQL_ERQ29(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ29_SHIFT))&SAF_DMA_ERQL_ERQ29_MASK)
#define SAF_DMA_ERQL_ERQ30_MASK                     0x40000000u
#define SAF_DMA_ERQL_ERQ30_SHIFT                    30u
#define SAF_DMA_ERQL_ERQ30_WIDTH                    1u
#define SAF_DMA_ERQL_ERQ30(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ30_SHIFT))&SAF_DMA_ERQL_ERQ30_MASK)
#define SAF_DMA_ERQL_ERQ31_MASK                     0x80000000u
#define SAF_DMA_ERQL_ERQ31_SHIFT                    31u
#define SAF_DMA_ERQL_ERQ31_WIDTH                    1u
#define SAF_DMA_ERQL_ERQ31(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERQL_ERQ31_SHIFT))&SAF_DMA_ERQL_ERQ31_MASK)
/* EEIH Bit Fields */
#define SAF_DMA_EEIH_EEI32_MASK                     0x1u
#define SAF_DMA_EEIH_EEI32_SHIFT                    0u
#define SAF_DMA_EEIH_EEI32_WIDTH                    1u
#define SAF_DMA_EEIH_EEI32(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI32_SHIFT))&SAF_DMA_EEIH_EEI32_MASK)
#define SAF_DMA_EEIH_EEI33_MASK                     0x2u
#define SAF_DMA_EEIH_EEI33_SHIFT                    1u
#define SAF_DMA_EEIH_EEI33_WIDTH                    1u
#define SAF_DMA_EEIH_EEI33(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI33_SHIFT))&SAF_DMA_EEIH_EEI33_MASK)
#define SAF_DMA_EEIH_EEI34_MASK                     0x4u
#define SAF_DMA_EEIH_EEI34_SHIFT                    2u
#define SAF_DMA_EEIH_EEI34_WIDTH                    1u
#define SAF_DMA_EEIH_EEI34(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI34_SHIFT))&SAF_DMA_EEIH_EEI34_MASK)
#define SAF_DMA_EEIH_EEI35_MASK                     0x8u
#define SAF_DMA_EEIH_EEI35_SHIFT                    3u
#define SAF_DMA_EEIH_EEI35_WIDTH                    1u
#define SAF_DMA_EEIH_EEI35(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI35_SHIFT))&SAF_DMA_EEIH_EEI35_MASK)
#define SAF_DMA_EEIH_EEI36_MASK                     0x10u
#define SAF_DMA_EEIH_EEI36_SHIFT                    4u
#define SAF_DMA_EEIH_EEI36_WIDTH                    1u
#define SAF_DMA_EEIH_EEI36(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI36_SHIFT))&SAF_DMA_EEIH_EEI36_MASK)
#define SAF_DMA_EEIH_EEI37_MASK                     0x20u
#define SAF_DMA_EEIH_EEI37_SHIFT                    5u
#define SAF_DMA_EEIH_EEI37_WIDTH                    1u
#define SAF_DMA_EEIH_EEI37(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI37_SHIFT))&SAF_DMA_EEIH_EEI37_MASK)
#define SAF_DMA_EEIH_EEI38_MASK                     0x40u
#define SAF_DMA_EEIH_EEI38_SHIFT                    6u
#define SAF_DMA_EEIH_EEI38_WIDTH                    1u
#define SAF_DMA_EEIH_EEI38(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI38_SHIFT))&SAF_DMA_EEIH_EEI38_MASK)
#define SAF_DMA_EEIH_EEI39_MASK                     0x80u
#define SAF_DMA_EEIH_EEI39_SHIFT                    7u
#define SAF_DMA_EEIH_EEI39_WIDTH                    1u
#define SAF_DMA_EEIH_EEI39(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI39_SHIFT))&SAF_DMA_EEIH_EEI39_MASK)
#define SAF_DMA_EEIH_EEI40_MASK                     0x100u
#define SAF_DMA_EEIH_EEI40_SHIFT                    8u
#define SAF_DMA_EEIH_EEI40_WIDTH                    1u
#define SAF_DMA_EEIH_EEI40(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI40_SHIFT))&SAF_DMA_EEIH_EEI40_MASK)
#define SAF_DMA_EEIH_EEI41_MASK                     0x200u
#define SAF_DMA_EEIH_EEI41_SHIFT                    9u
#define SAF_DMA_EEIH_EEI41_WIDTH                    1u
#define SAF_DMA_EEIH_EEI41(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI41_SHIFT))&SAF_DMA_EEIH_EEI41_MASK)
#define SAF_DMA_EEIH_EEI42_MASK                     0x400u
#define SAF_DMA_EEIH_EEI42_SHIFT                    10u
#define SAF_DMA_EEIH_EEI42_WIDTH                    1u
#define SAF_DMA_EEIH_EEI42(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI42_SHIFT))&SAF_DMA_EEIH_EEI42_MASK)
#define SAF_DMA_EEIH_EEI43_MASK                     0x800u
#define SAF_DMA_EEIH_EEI43_SHIFT                    11u
#define SAF_DMA_EEIH_EEI43_WIDTH                    1u
#define SAF_DMA_EEIH_EEI43(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI43_SHIFT))&SAF_DMA_EEIH_EEI43_MASK)
#define SAF_DMA_EEIH_EEI44_MASK                     0x1000u
#define SAF_DMA_EEIH_EEI44_SHIFT                    12u
#define SAF_DMA_EEIH_EEI44_WIDTH                    1u
#define SAF_DMA_EEIH_EEI44(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI44_SHIFT))&SAF_DMA_EEIH_EEI44_MASK)
#define SAF_DMA_EEIH_EEI45_MASK                     0x2000u
#define SAF_DMA_EEIH_EEI45_SHIFT                    13u
#define SAF_DMA_EEIH_EEI45_WIDTH                    1u
#define SAF_DMA_EEIH_EEI45(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI45_SHIFT))&SAF_DMA_EEIH_EEI45_MASK)
#define SAF_DMA_EEIH_EEI46_MASK                     0x4000u
#define SAF_DMA_EEIH_EEI46_SHIFT                    14u
#define SAF_DMA_EEIH_EEI46_WIDTH                    1u
#define SAF_DMA_EEIH_EEI46(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI46_SHIFT))&SAF_DMA_EEIH_EEI46_MASK)
#define SAF_DMA_EEIH_EEI47_MASK                     0x8000u
#define SAF_DMA_EEIH_EEI47_SHIFT                    15u
#define SAF_DMA_EEIH_EEI47_WIDTH                    1u
#define SAF_DMA_EEIH_EEI47(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI47_SHIFT))&SAF_DMA_EEIH_EEI47_MASK)
#define SAF_DMA_EEIH_EEI48_MASK                     0x10000u
#define SAF_DMA_EEIH_EEI48_SHIFT                    16u
#define SAF_DMA_EEIH_EEI48_WIDTH                    1u
#define SAF_DMA_EEIH_EEI48(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI48_SHIFT))&SAF_DMA_EEIH_EEI48_MASK)
#define SAF_DMA_EEIH_EEI49_MASK                     0x20000u
#define SAF_DMA_EEIH_EEI49_SHIFT                    17u
#define SAF_DMA_EEIH_EEI49_WIDTH                    1u
#define SAF_DMA_EEIH_EEI49(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI49_SHIFT))&SAF_DMA_EEIH_EEI49_MASK)
#define SAF_DMA_EEIH_EEI50_MASK                     0x40000u
#define SAF_DMA_EEIH_EEI50_SHIFT                    18u
#define SAF_DMA_EEIH_EEI50_WIDTH                    1u
#define SAF_DMA_EEIH_EEI50(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI50_SHIFT))&SAF_DMA_EEIH_EEI50_MASK)
#define SAF_DMA_EEIH_EEI51_MASK                     0x80000u
#define SAF_DMA_EEIH_EEI51_SHIFT                    19u
#define SAF_DMA_EEIH_EEI51_WIDTH                    1u
#define SAF_DMA_EEIH_EEI51(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI51_SHIFT))&SAF_DMA_EEIH_EEI51_MASK)
#define SAF_DMA_EEIH_EEI52_MASK                     0x100000u
#define SAF_DMA_EEIH_EEI52_SHIFT                    20u
#define SAF_DMA_EEIH_EEI52_WIDTH                    1u
#define SAF_DMA_EEIH_EEI52(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI52_SHIFT))&SAF_DMA_EEIH_EEI52_MASK)
#define SAF_DMA_EEIH_EEI53_MASK                     0x200000u
#define SAF_DMA_EEIH_EEI53_SHIFT                    21u
#define SAF_DMA_EEIH_EEI53_WIDTH                    1u
#define SAF_DMA_EEIH_EEI53(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI53_SHIFT))&SAF_DMA_EEIH_EEI53_MASK)
#define SAF_DMA_EEIH_EEI54_MASK                     0x400000u
#define SAF_DMA_EEIH_EEI54_SHIFT                    22u
#define SAF_DMA_EEIH_EEI54_WIDTH                    1u
#define SAF_DMA_EEIH_EEI54(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI54_SHIFT))&SAF_DMA_EEIH_EEI54_MASK)
#define SAF_DMA_EEIH_EEI55_MASK                     0x800000u
#define SAF_DMA_EEIH_EEI55_SHIFT                    23u
#define SAF_DMA_EEIH_EEI55_WIDTH                    1u
#define SAF_DMA_EEIH_EEI55(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI55_SHIFT))&SAF_DMA_EEIH_EEI55_MASK)
#define SAF_DMA_EEIH_EEI56_MASK                     0x1000000u
#define SAF_DMA_EEIH_EEI56_SHIFT                    24u
#define SAF_DMA_EEIH_EEI56_WIDTH                    1u
#define SAF_DMA_EEIH_EEI56(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI56_SHIFT))&SAF_DMA_EEIH_EEI56_MASK)
#define SAF_DMA_EEIH_EEI57_MASK                     0x2000000u
#define SAF_DMA_EEIH_EEI57_SHIFT                    25u
#define SAF_DMA_EEIH_EEI57_WIDTH                    1u
#define SAF_DMA_EEIH_EEI57(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI57_SHIFT))&SAF_DMA_EEIH_EEI57_MASK)
#define SAF_DMA_EEIH_EEI58_MASK                     0x4000000u
#define SAF_DMA_EEIH_EEI58_SHIFT                    26u
#define SAF_DMA_EEIH_EEI58_WIDTH                    1u
#define SAF_DMA_EEIH_EEI58(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI58_SHIFT))&SAF_DMA_EEIH_EEI58_MASK)
#define SAF_DMA_EEIH_EEI59_MASK                     0x8000000u
#define SAF_DMA_EEIH_EEI59_SHIFT                    27u
#define SAF_DMA_EEIH_EEI59_WIDTH                    1u
#define SAF_DMA_EEIH_EEI59(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI59_SHIFT))&SAF_DMA_EEIH_EEI59_MASK)
#define SAF_DMA_EEIH_EEI60_MASK                     0x10000000u
#define SAF_DMA_EEIH_EEI60_SHIFT                    28u
#define SAF_DMA_EEIH_EEI60_WIDTH                    1u
#define SAF_DMA_EEIH_EEI60(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI60_SHIFT))&SAF_DMA_EEIH_EEI60_MASK)
#define SAF_DMA_EEIH_EEI61_MASK                     0x20000000u
#define SAF_DMA_EEIH_EEI61_SHIFT                    29u
#define SAF_DMA_EEIH_EEI61_WIDTH                    1u
#define SAF_DMA_EEIH_EEI61(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI61_SHIFT))&SAF_DMA_EEIH_EEI61_MASK)
#define SAF_DMA_EEIH_EEI62_MASK                     0x40000000u
#define SAF_DMA_EEIH_EEI62_SHIFT                    30u
#define SAF_DMA_EEIH_EEI62_WIDTH                    1u
#define SAF_DMA_EEIH_EEI62(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI62_SHIFT))&SAF_DMA_EEIH_EEI62_MASK)
#define SAF_DMA_EEIH_EEI63_MASK                     0x80000000u
#define SAF_DMA_EEIH_EEI63_SHIFT                    31u
#define SAF_DMA_EEIH_EEI63_WIDTH                    1u
#define SAF_DMA_EEIH_EEI63(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIH_EEI63_SHIFT))&SAF_DMA_EEIH_EEI63_MASK)
/* EEIL Bit Fields */
#define SAF_DMA_EEIL_EEI0_MASK                      0x1u
#define SAF_DMA_EEIL_EEI0_SHIFT                     0u
#define SAF_DMA_EEIL_EEI0_WIDTH                     1u
#define SAF_DMA_EEIL_EEI0(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI0_SHIFT))&SAF_DMA_EEIL_EEI0_MASK)
#define SAF_DMA_EEIL_EEI1_MASK                      0x2u
#define SAF_DMA_EEIL_EEI1_SHIFT                     1u
#define SAF_DMA_EEIL_EEI1_WIDTH                     1u
#define SAF_DMA_EEIL_EEI1(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI1_SHIFT))&SAF_DMA_EEIL_EEI1_MASK)
#define SAF_DMA_EEIL_EEI2_MASK                      0x4u
#define SAF_DMA_EEIL_EEI2_SHIFT                     2u
#define SAF_DMA_EEIL_EEI2_WIDTH                     1u
#define SAF_DMA_EEIL_EEI2(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI2_SHIFT))&SAF_DMA_EEIL_EEI2_MASK)
#define SAF_DMA_EEIL_EEI3_MASK                      0x8u
#define SAF_DMA_EEIL_EEI3_SHIFT                     3u
#define SAF_DMA_EEIL_EEI3_WIDTH                     1u
#define SAF_DMA_EEIL_EEI3(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI3_SHIFT))&SAF_DMA_EEIL_EEI3_MASK)
#define SAF_DMA_EEIL_EEI4_MASK                      0x10u
#define SAF_DMA_EEIL_EEI4_SHIFT                     4u
#define SAF_DMA_EEIL_EEI4_WIDTH                     1u
#define SAF_DMA_EEIL_EEI4(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI4_SHIFT))&SAF_DMA_EEIL_EEI4_MASK)
#define SAF_DMA_EEIL_EEI5_MASK                      0x20u
#define SAF_DMA_EEIL_EEI5_SHIFT                     5u
#define SAF_DMA_EEIL_EEI5_WIDTH                     1u
#define SAF_DMA_EEIL_EEI5(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI5_SHIFT))&SAF_DMA_EEIL_EEI5_MASK)
#define SAF_DMA_EEIL_EEI6_MASK                      0x40u
#define SAF_DMA_EEIL_EEI6_SHIFT                     6u
#define SAF_DMA_EEIL_EEI6_WIDTH                     1u
#define SAF_DMA_EEIL_EEI6(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI6_SHIFT))&SAF_DMA_EEIL_EEI6_MASK)
#define SAF_DMA_EEIL_EEI7_MASK                      0x80u
#define SAF_DMA_EEIL_EEI7_SHIFT                     7u
#define SAF_DMA_EEIL_EEI7_WIDTH                     1u
#define SAF_DMA_EEIL_EEI7(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI7_SHIFT))&SAF_DMA_EEIL_EEI7_MASK)
#define SAF_DMA_EEIL_EEI8_MASK                      0x100u
#define SAF_DMA_EEIL_EEI8_SHIFT                     8u
#define SAF_DMA_EEIL_EEI8_WIDTH                     1u
#define SAF_DMA_EEIL_EEI8(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI8_SHIFT))&SAF_DMA_EEIL_EEI8_MASK)
#define SAF_DMA_EEIL_EEI9_MASK                      0x200u
#define SAF_DMA_EEIL_EEI9_SHIFT                     9u
#define SAF_DMA_EEIL_EEI9_WIDTH                     1u
#define SAF_DMA_EEIL_EEI9(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI9_SHIFT))&SAF_DMA_EEIL_EEI9_MASK)
#define SAF_DMA_EEIL_EEI10_MASK                     0x400u
#define SAF_DMA_EEIL_EEI10_SHIFT                    10u
#define SAF_DMA_EEIL_EEI10_WIDTH                    1u
#define SAF_DMA_EEIL_EEI10(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI10_SHIFT))&SAF_DMA_EEIL_EEI10_MASK)
#define SAF_DMA_EEIL_EEI11_MASK                     0x800u
#define SAF_DMA_EEIL_EEI11_SHIFT                    11u
#define SAF_DMA_EEIL_EEI11_WIDTH                    1u
#define SAF_DMA_EEIL_EEI11(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI11_SHIFT))&SAF_DMA_EEIL_EEI11_MASK)
#define SAF_DMA_EEIL_EEI12_MASK                     0x1000u
#define SAF_DMA_EEIL_EEI12_SHIFT                    12u
#define SAF_DMA_EEIL_EEI12_WIDTH                    1u
#define SAF_DMA_EEIL_EEI12(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI12_SHIFT))&SAF_DMA_EEIL_EEI12_MASK)
#define SAF_DMA_EEIL_EEI13_MASK                     0x2000u
#define SAF_DMA_EEIL_EEI13_SHIFT                    13u
#define SAF_DMA_EEIL_EEI13_WIDTH                    1u
#define SAF_DMA_EEIL_EEI13(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI13_SHIFT))&SAF_DMA_EEIL_EEI13_MASK)
#define SAF_DMA_EEIL_EEI14_MASK                     0x4000u
#define SAF_DMA_EEIL_EEI14_SHIFT                    14u
#define SAF_DMA_EEIL_EEI14_WIDTH                    1u
#define SAF_DMA_EEIL_EEI14(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI14_SHIFT))&SAF_DMA_EEIL_EEI14_MASK)
#define SAF_DMA_EEIL_EEI15_MASK                     0x8000u
#define SAF_DMA_EEIL_EEI15_SHIFT                    15u
#define SAF_DMA_EEIL_EEI15_WIDTH                    1u
#define SAF_DMA_EEIL_EEI15(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI15_SHIFT))&SAF_DMA_EEIL_EEI15_MASK)
#define SAF_DMA_EEIL_EEI16_MASK                     0x10000u
#define SAF_DMA_EEIL_EEI16_SHIFT                    16u
#define SAF_DMA_EEIL_EEI16_WIDTH                    1u
#define SAF_DMA_EEIL_EEI16(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI16_SHIFT))&SAF_DMA_EEIL_EEI16_MASK)
#define SAF_DMA_EEIL_EEI17_MASK                     0x20000u
#define SAF_DMA_EEIL_EEI17_SHIFT                    17u
#define SAF_DMA_EEIL_EEI17_WIDTH                    1u
#define SAF_DMA_EEIL_EEI17(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI17_SHIFT))&SAF_DMA_EEIL_EEI17_MASK)
#define SAF_DMA_EEIL_EEI18_MASK                     0x40000u
#define SAF_DMA_EEIL_EEI18_SHIFT                    18u
#define SAF_DMA_EEIL_EEI18_WIDTH                    1u
#define SAF_DMA_EEIL_EEI18(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI18_SHIFT))&SAF_DMA_EEIL_EEI18_MASK)
#define SAF_DMA_EEIL_EEI19_MASK                     0x80000u
#define SAF_DMA_EEIL_EEI19_SHIFT                    19u
#define SAF_DMA_EEIL_EEI19_WIDTH                    1u
#define SAF_DMA_EEIL_EEI19(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI19_SHIFT))&SAF_DMA_EEIL_EEI19_MASK)
#define SAF_DMA_EEIL_EEI20_MASK                     0x100000u
#define SAF_DMA_EEIL_EEI20_SHIFT                    20u
#define SAF_DMA_EEIL_EEI20_WIDTH                    1u
#define SAF_DMA_EEIL_EEI20(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI20_SHIFT))&SAF_DMA_EEIL_EEI20_MASK)
#define SAF_DMA_EEIL_EEI21_MASK                     0x200000u
#define SAF_DMA_EEIL_EEI21_SHIFT                    21u
#define SAF_DMA_EEIL_EEI21_WIDTH                    1u
#define SAF_DMA_EEIL_EEI21(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI21_SHIFT))&SAF_DMA_EEIL_EEI21_MASK)
#define SAF_DMA_EEIL_EEI22_MASK                     0x400000u
#define SAF_DMA_EEIL_EEI22_SHIFT                    22u
#define SAF_DMA_EEIL_EEI22_WIDTH                    1u
#define SAF_DMA_EEIL_EEI22(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI22_SHIFT))&SAF_DMA_EEIL_EEI22_MASK)
#define SAF_DMA_EEIL_EEI23_MASK                     0x800000u
#define SAF_DMA_EEIL_EEI23_SHIFT                    23u
#define SAF_DMA_EEIL_EEI23_WIDTH                    1u
#define SAF_DMA_EEIL_EEI23(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI23_SHIFT))&SAF_DMA_EEIL_EEI23_MASK)
#define SAF_DMA_EEIL_EEI24_MASK                     0x1000000u
#define SAF_DMA_EEIL_EEI24_SHIFT                    24u
#define SAF_DMA_EEIL_EEI24_WIDTH                    1u
#define SAF_DMA_EEIL_EEI24(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI24_SHIFT))&SAF_DMA_EEIL_EEI24_MASK)
#define SAF_DMA_EEIL_EEI25_MASK                     0x2000000u
#define SAF_DMA_EEIL_EEI25_SHIFT                    25u
#define SAF_DMA_EEIL_EEI25_WIDTH                    1u
#define SAF_DMA_EEIL_EEI25(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI25_SHIFT))&SAF_DMA_EEIL_EEI25_MASK)
#define SAF_DMA_EEIL_EEI26_MASK                     0x4000000u
#define SAF_DMA_EEIL_EEI26_SHIFT                    26u
#define SAF_DMA_EEIL_EEI26_WIDTH                    1u
#define SAF_DMA_EEIL_EEI26(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI26_SHIFT))&SAF_DMA_EEIL_EEI26_MASK)
#define SAF_DMA_EEIL_EEI27_MASK                     0x8000000u
#define SAF_DMA_EEIL_EEI27_SHIFT                    27u
#define SAF_DMA_EEIL_EEI27_WIDTH                    1u
#define SAF_DMA_EEIL_EEI27(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI27_SHIFT))&SAF_DMA_EEIL_EEI27_MASK)
#define SAF_DMA_EEIL_EEI28_MASK                     0x10000000u
#define SAF_DMA_EEIL_EEI28_SHIFT                    28u
#define SAF_DMA_EEIL_EEI28_WIDTH                    1u
#define SAF_DMA_EEIL_EEI28(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI28_SHIFT))&SAF_DMA_EEIL_EEI28_MASK)
#define SAF_DMA_EEIL_EEI29_MASK                     0x20000000u
#define SAF_DMA_EEIL_EEI29_SHIFT                    29u
#define SAF_DMA_EEIL_EEI29_WIDTH                    1u
#define SAF_DMA_EEIL_EEI29(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI29_SHIFT))&SAF_DMA_EEIL_EEI29_MASK)
#define SAF_DMA_EEIL_EEI30_MASK                     0x40000000u
#define SAF_DMA_EEIL_EEI30_SHIFT                    30u
#define SAF_DMA_EEIL_EEI30_WIDTH                    1u
#define SAF_DMA_EEIL_EEI30(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI30_SHIFT))&SAF_DMA_EEIL_EEI30_MASK)
#define SAF_DMA_EEIL_EEI31_MASK                     0x80000000u
#define SAF_DMA_EEIL_EEI31_SHIFT                    31u
#define SAF_DMA_EEIL_EEI31_WIDTH                    1u
#define SAF_DMA_EEIL_EEI31(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_EEIL_EEI31_SHIFT))&SAF_DMA_EEIL_EEI31_MASK)
/* SERQ Bit Fields */
#define SAF_DMA_SERQ_SERQ_MASK                      0x3Fu
#define SAF_DMA_SERQ_SERQ_SHIFT                     0u
#define SAF_DMA_SERQ_SERQ_WIDTH                     6u
#define SAF_DMA_SERQ_SERQ(x)                        (((uint8_t)(((uint8_t)(x)) << SAF_DMA_SERQ_SERQ_SHIFT))&SAF_DMA_SERQ_SERQ_MASK)
#define SAF_DMA_SERQ_SAER_MASK                      0x40u
#define SAF_DMA_SERQ_SAER_SHIFT                     6u
#define SAF_DMA_SERQ_SAER_WIDTH                     1u
#define SAF_DMA_SERQ_SAER(x)                        (((uint8_t)(((uint8_t)(x)) << SAF_DMA_SERQ_SAER_SHIFT))&SAF_DMA_SERQ_SAER_MASK)
#define SAF_DMA_SERQ_NOP_MASK                       0x80u
#define SAF_DMA_SERQ_NOP_SHIFT                      7u
#define SAF_DMA_SERQ_NOP_WIDTH                      1u
#define SAF_DMA_SERQ_NOP(x)                         (((uint8_t)(((uint8_t)(x)) << SAF_DMA_SERQ_NOP_SHIFT))&SAF_DMA_SERQ_NOP_MASK)
/* CERQ Bit Fields */
#define SAF_DMA_CERQ_CERQ_MASK                      0x3Fu
#define SAF_DMA_CERQ_CERQ_SHIFT                     0u
#define SAF_DMA_CERQ_CERQ_WIDTH                     6u
#define SAF_DMA_CERQ_CERQ(x)                        (((uint8_t)(((uint8_t)(x)) << SAF_DMA_CERQ_CERQ_SHIFT))&SAF_DMA_CERQ_CERQ_MASK)
#define SAF_DMA_CERQ_CAER_MASK                      0x40u
#define SAF_DMA_CERQ_CAER_SHIFT                     6u
#define SAF_DMA_CERQ_CAER_WIDTH                     1u
#define SAF_DMA_CERQ_CAER(x)                        (((uint8_t)(((uint8_t)(x)) << SAF_DMA_CERQ_CAER_SHIFT))&SAF_DMA_CERQ_CAER_MASK)
#define SAF_DMA_CERQ_NOP_MASK                       0x80u
#define SAF_DMA_CERQ_NOP_SHIFT                      7u
#define SAF_DMA_CERQ_NOP_WIDTH                      1u
#define SAF_DMA_CERQ_NOP(x)                         (((uint8_t)(((uint8_t)(x)) << SAF_DMA_CERQ_NOP_SHIFT))&SAF_DMA_CERQ_NOP_MASK)
/* SEEI Bit Fields */
#define SAF_DMA_SEEI_SEEI_MASK                      0x3Fu
#define SAF_DMA_SEEI_SEEI_SHIFT                     0u
#define SAF_DMA_SEEI_SEEI_WIDTH                     6u
#define SAF_DMA_SEEI_SEEI(x)                        (((uint8_t)(((uint8_t)(x)) << SAF_DMA_SEEI_SEEI_SHIFT))&SAF_DMA_SEEI_SEEI_MASK)
#define SAF_DMA_SEEI_SAEE_MASK                      0x40u
#define SAF_DMA_SEEI_SAEE_SHIFT                     6u
#define SAF_DMA_SEEI_SAEE_WIDTH                     1u
#define SAF_DMA_SEEI_SAEE(x)                        (((uint8_t)(((uint8_t)(x)) << SAF_DMA_SEEI_SAEE_SHIFT))&SAF_DMA_SEEI_SAEE_MASK)
#define SAF_DMA_SEEI_NOP_MASK                       0x80u
#define SAF_DMA_SEEI_NOP_SHIFT                      7u
#define SAF_DMA_SEEI_NOP_WIDTH                      1u
#define SAF_DMA_SEEI_NOP(x)                         (((uint8_t)(((uint8_t)(x)) << SAF_DMA_SEEI_NOP_SHIFT))&SAF_DMA_SEEI_NOP_MASK)
/* CEEI Bit Fields */
#define SAF_DMA_CEEI_CEEI_MASK                      0x3Fu
#define SAF_DMA_CEEI_CEEI_SHIFT                     0u
#define SAF_DMA_CEEI_CEEI_WIDTH                     6u
#define SAF_DMA_CEEI_CEEI(x)                        (((uint8_t)(((uint8_t)(x)) << SAF_DMA_CEEI_CEEI_SHIFT))&SAF_DMA_CEEI_CEEI_MASK)
#define SAF_DMA_CEEI_CAEE_MASK                      0x40u
#define SAF_DMA_CEEI_CAEE_SHIFT                     6u
#define SAF_DMA_CEEI_CAEE_WIDTH                     1u
#define SAF_DMA_CEEI_CAEE(x)                        (((uint8_t)(((uint8_t)(x)) << SAF_DMA_CEEI_CAEE_SHIFT))&SAF_DMA_CEEI_CAEE_MASK)
#define SAF_DMA_CEEI_NOP_MASK                       0x80u
#define SAF_DMA_CEEI_NOP_SHIFT                      7u
#define SAF_DMA_CEEI_NOP_WIDTH                      1u
#define SAF_DMA_CEEI_NOP(x)                         (((uint8_t)(((uint8_t)(x)) << SAF_DMA_CEEI_NOP_SHIFT))&SAF_DMA_CEEI_NOP_MASK)
/* CINT Bit Fields */
#define SAF_DMA_CINT_CINT_MASK                      0x3Fu
#define SAF_DMA_CINT_CINT_SHIFT                     0u
#define SAF_DMA_CINT_CINT_WIDTH                     6u
#define SAF_DMA_CINT_CINT(x)                        (((uint8_t)(((uint8_t)(x)) << SAF_DMA_CINT_CINT_SHIFT))&SAF_DMA_CINT_CINT_MASK)
#define SAF_DMA_CINT_CAIR_MASK                      0x40u
#define SAF_DMA_CINT_CAIR_SHIFT                     6u
#define SAF_DMA_CINT_CAIR_WIDTH                     1u
#define SAF_DMA_CINT_CAIR(x)                        (((uint8_t)(((uint8_t)(x)) << SAF_DMA_CINT_CAIR_SHIFT))&SAF_DMA_CINT_CAIR_MASK)
#define SAF_DMA_CINT_NOP_MASK                       0x80u
#define SAF_DMA_CINT_NOP_SHIFT                      7u
#define SAF_DMA_CINT_NOP_WIDTH                      1u
#define SAF_DMA_CINT_NOP(x)                         (((uint8_t)(((uint8_t)(x)) << SAF_DMA_CINT_NOP_SHIFT))&SAF_DMA_CINT_NOP_MASK)
/* CERR Bit Fields */
#define SAF_DMA_CERR_CERR_MASK                      0x3Fu
#define SAF_DMA_CERR_CERR_SHIFT                     0u
#define SAF_DMA_CERR_CERR_WIDTH                     6u
#define SAF_DMA_CERR_CERR(x)                        (((uint8_t)(((uint8_t)(x)) << SAF_DMA_CERR_CERR_SHIFT))&SAF_DMA_CERR_CERR_MASK)
#define SAF_DMA_CERR_CAEI_MASK                      0x40u
#define SAF_DMA_CERR_CAEI_SHIFT                     6u
#define SAF_DMA_CERR_CAEI_WIDTH                     1u
#define SAF_DMA_CERR_CAEI(x)                        (((uint8_t)(((uint8_t)(x)) << SAF_DMA_CERR_CAEI_SHIFT))&SAF_DMA_CERR_CAEI_MASK)
#define SAF_DMA_CERR_NOP_MASK                       0x80u
#define SAF_DMA_CERR_NOP_SHIFT                      7u
#define SAF_DMA_CERR_NOP_WIDTH                      1u
#define SAF_DMA_CERR_NOP(x)                         (((uint8_t)(((uint8_t)(x)) << SAF_DMA_CERR_NOP_SHIFT))&SAF_DMA_CERR_NOP_MASK)
/* SSRT Bit Fields */
#define SAF_DMA_SSRT_SSRT_MASK                      0x3Fu
#define SAF_DMA_SSRT_SSRT_SHIFT                     0u
#define SAF_DMA_SSRT_SSRT_WIDTH                     6u
#define SAF_DMA_SSRT_SSRT(x)                        (((uint8_t)(((uint8_t)(x)) << SAF_DMA_SSRT_SSRT_SHIFT))&SAF_DMA_SSRT_SSRT_MASK)
#define SAF_DMA_SSRT_SAST_MASK                      0x40u
#define SAF_DMA_SSRT_SAST_SHIFT                     6u
#define SAF_DMA_SSRT_SAST_WIDTH                     1u
#define SAF_DMA_SSRT_SAST(x)                        (((uint8_t)(((uint8_t)(x)) << SAF_DMA_SSRT_SAST_SHIFT))&SAF_DMA_SSRT_SAST_MASK)
#define SAF_DMA_SSRT_NOP_MASK                       0x80u
#define SAF_DMA_SSRT_NOP_SHIFT                      7u
#define SAF_DMA_SSRT_NOP_WIDTH                      1u
#define SAF_DMA_SSRT_NOP(x)                         (((uint8_t)(((uint8_t)(x)) << SAF_DMA_SSRT_NOP_SHIFT))&SAF_DMA_SSRT_NOP_MASK)
/* CDNE Bit Fields */
#define SAF_DMA_CDNE_CDNE_MASK                      0x3Fu
#define SAF_DMA_CDNE_CDNE_SHIFT                     0u
#define SAF_DMA_CDNE_CDNE_WIDTH                     6u
#define SAF_DMA_CDNE_CDNE(x)                        (((uint8_t)(((uint8_t)(x)) << SAF_DMA_CDNE_CDNE_SHIFT))&SAF_DMA_CDNE_CDNE_MASK)
#define SAF_DMA_CDNE_CADN_MASK                      0x40u
#define SAF_DMA_CDNE_CADN_SHIFT                     6u
#define SAF_DMA_CDNE_CADN_WIDTH                     1u
#define SAF_DMA_CDNE_CADN(x)                        (((uint8_t)(((uint8_t)(x)) << SAF_DMA_CDNE_CADN_SHIFT))&SAF_DMA_CDNE_CADN_MASK)
#define SAF_DMA_CDNE_NOP_MASK                       0x80u
#define SAF_DMA_CDNE_NOP_SHIFT                      7u
#define SAF_DMA_CDNE_NOP_WIDTH                      1u
#define SAF_DMA_CDNE_NOP(x)                         (((uint8_t)(((uint8_t)(x)) << SAF_DMA_CDNE_NOP_SHIFT))&SAF_DMA_CDNE_NOP_MASK)
/* INTH Bit Fields */
#define SAF_DMA_INTH_INT32_MASK                     0x1u
#define SAF_DMA_INTH_INT32_SHIFT                    0u
#define SAF_DMA_INTH_INT32_WIDTH                    1u
#define SAF_DMA_INTH_INT32(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT32_SHIFT))&SAF_DMA_INTH_INT32_MASK)
#define SAF_DMA_INTH_INT33_MASK                     0x2u
#define SAF_DMA_INTH_INT33_SHIFT                    1u
#define SAF_DMA_INTH_INT33_WIDTH                    1u
#define SAF_DMA_INTH_INT33(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT33_SHIFT))&SAF_DMA_INTH_INT33_MASK)
#define SAF_DMA_INTH_INT34_MASK                     0x4u
#define SAF_DMA_INTH_INT34_SHIFT                    2u
#define SAF_DMA_INTH_INT34_WIDTH                    1u
#define SAF_DMA_INTH_INT34(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT34_SHIFT))&SAF_DMA_INTH_INT34_MASK)
#define SAF_DMA_INTH_INT35_MASK                     0x8u
#define SAF_DMA_INTH_INT35_SHIFT                    3u
#define SAF_DMA_INTH_INT35_WIDTH                    1u
#define SAF_DMA_INTH_INT35(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT35_SHIFT))&SAF_DMA_INTH_INT35_MASK)
#define SAF_DMA_INTH_INT36_MASK                     0x10u
#define SAF_DMA_INTH_INT36_SHIFT                    4u
#define SAF_DMA_INTH_INT36_WIDTH                    1u
#define SAF_DMA_INTH_INT36(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT36_SHIFT))&SAF_DMA_INTH_INT36_MASK)
#define SAF_DMA_INTH_INT37_MASK                     0x20u
#define SAF_DMA_INTH_INT37_SHIFT                    5u
#define SAF_DMA_INTH_INT37_WIDTH                    1u
#define SAF_DMA_INTH_INT37(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT37_SHIFT))&SAF_DMA_INTH_INT37_MASK)
#define SAF_DMA_INTH_INT38_MASK                     0x40u
#define SAF_DMA_INTH_INT38_SHIFT                    6u
#define SAF_DMA_INTH_INT38_WIDTH                    1u
#define SAF_DMA_INTH_INT38(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT38_SHIFT))&SAF_DMA_INTH_INT38_MASK)
#define SAF_DMA_INTH_INT39_MASK                     0x80u
#define SAF_DMA_INTH_INT39_SHIFT                    7u
#define SAF_DMA_INTH_INT39_WIDTH                    1u
#define SAF_DMA_INTH_INT39(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT39_SHIFT))&SAF_DMA_INTH_INT39_MASK)
#define SAF_DMA_INTH_INT40_MASK                     0x100u
#define SAF_DMA_INTH_INT40_SHIFT                    8u
#define SAF_DMA_INTH_INT40_WIDTH                    1u
#define SAF_DMA_INTH_INT40(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT40_SHIFT))&SAF_DMA_INTH_INT40_MASK)
#define SAF_DMA_INTH_INT41_MASK                     0x200u
#define SAF_DMA_INTH_INT41_SHIFT                    9u
#define SAF_DMA_INTH_INT41_WIDTH                    1u
#define SAF_DMA_INTH_INT41(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT41_SHIFT))&SAF_DMA_INTH_INT41_MASK)
#define SAF_DMA_INTH_INT42_MASK                     0x400u
#define SAF_DMA_INTH_INT42_SHIFT                    10u
#define SAF_DMA_INTH_INT42_WIDTH                    1u
#define SAF_DMA_INTH_INT42(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT42_SHIFT))&SAF_DMA_INTH_INT42_MASK)
#define SAF_DMA_INTH_INT43_MASK                     0x800u
#define SAF_DMA_INTH_INT43_SHIFT                    11u
#define SAF_DMA_INTH_INT43_WIDTH                    1u
#define SAF_DMA_INTH_INT43(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT43_SHIFT))&SAF_DMA_INTH_INT43_MASK)
#define SAF_DMA_INTH_INT44_MASK                     0x1000u
#define SAF_DMA_INTH_INT44_SHIFT                    12u
#define SAF_DMA_INTH_INT44_WIDTH                    1u
#define SAF_DMA_INTH_INT44(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT44_SHIFT))&SAF_DMA_INTH_INT44_MASK)
#define SAF_DMA_INTH_INT45_MASK                     0x2000u
#define SAF_DMA_INTH_INT45_SHIFT                    13u
#define SAF_DMA_INTH_INT45_WIDTH                    1u
#define SAF_DMA_INTH_INT45(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT45_SHIFT))&SAF_DMA_INTH_INT45_MASK)
#define SAF_DMA_INTH_INT46_MASK                     0x4000u
#define SAF_DMA_INTH_INT46_SHIFT                    14u
#define SAF_DMA_INTH_INT46_WIDTH                    1u
#define SAF_DMA_INTH_INT46(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT46_SHIFT))&SAF_DMA_INTH_INT46_MASK)
#define SAF_DMA_INTH_INT47_MASK                     0x8000u
#define SAF_DMA_INTH_INT47_SHIFT                    15u
#define SAF_DMA_INTH_INT47_WIDTH                    1u
#define SAF_DMA_INTH_INT47(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT47_SHIFT))&SAF_DMA_INTH_INT47_MASK)
#define SAF_DMA_INTH_INT48_MASK                     0x10000u
#define SAF_DMA_INTH_INT48_SHIFT                    16u
#define SAF_DMA_INTH_INT48_WIDTH                    1u
#define SAF_DMA_INTH_INT48(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT48_SHIFT))&SAF_DMA_INTH_INT48_MASK)
#define SAF_DMA_INTH_INT49_MASK                     0x20000u
#define SAF_DMA_INTH_INT49_SHIFT                    17u
#define SAF_DMA_INTH_INT49_WIDTH                    1u
#define SAF_DMA_INTH_INT49(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT49_SHIFT))&SAF_DMA_INTH_INT49_MASK)
#define SAF_DMA_INTH_INT50_MASK                     0x40000u
#define SAF_DMA_INTH_INT50_SHIFT                    18u
#define SAF_DMA_INTH_INT50_WIDTH                    1u
#define SAF_DMA_INTH_INT50(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT50_SHIFT))&SAF_DMA_INTH_INT50_MASK)
#define SAF_DMA_INTH_INT51_MASK                     0x80000u
#define SAF_DMA_INTH_INT51_SHIFT                    19u
#define SAF_DMA_INTH_INT51_WIDTH                    1u
#define SAF_DMA_INTH_INT51(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT51_SHIFT))&SAF_DMA_INTH_INT51_MASK)
#define SAF_DMA_INTH_INT52_MASK                     0x100000u
#define SAF_DMA_INTH_INT52_SHIFT                    20u
#define SAF_DMA_INTH_INT52_WIDTH                    1u
#define SAF_DMA_INTH_INT52(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT52_SHIFT))&SAF_DMA_INTH_INT52_MASK)
#define SAF_DMA_INTH_INT53_MASK                     0x200000u
#define SAF_DMA_INTH_INT53_SHIFT                    21u
#define SAF_DMA_INTH_INT53_WIDTH                    1u
#define SAF_DMA_INTH_INT53(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT53_SHIFT))&SAF_DMA_INTH_INT53_MASK)
#define SAF_DMA_INTH_INT54_MASK                     0x400000u
#define SAF_DMA_INTH_INT54_SHIFT                    22u
#define SAF_DMA_INTH_INT54_WIDTH                    1u
#define SAF_DMA_INTH_INT54(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT54_SHIFT))&SAF_DMA_INTH_INT54_MASK)
#define SAF_DMA_INTH_INT55_MASK                     0x800000u
#define SAF_DMA_INTH_INT55_SHIFT                    23u
#define SAF_DMA_INTH_INT55_WIDTH                    1u
#define SAF_DMA_INTH_INT55(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT55_SHIFT))&SAF_DMA_INTH_INT55_MASK)
#define SAF_DMA_INTH_INT56_MASK                     0x1000000u
#define SAF_DMA_INTH_INT56_SHIFT                    24u
#define SAF_DMA_INTH_INT56_WIDTH                    1u
#define SAF_DMA_INTH_INT56(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT56_SHIFT))&SAF_DMA_INTH_INT56_MASK)
#define SAF_DMA_INTH_INT57_MASK                     0x2000000u
#define SAF_DMA_INTH_INT57_SHIFT                    25u
#define SAF_DMA_INTH_INT57_WIDTH                    1u
#define SAF_DMA_INTH_INT57(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT57_SHIFT))&SAF_DMA_INTH_INT57_MASK)
#define SAF_DMA_INTH_INT58_MASK                     0x4000000u
#define SAF_DMA_INTH_INT58_SHIFT                    26u
#define SAF_DMA_INTH_INT58_WIDTH                    1u
#define SAF_DMA_INTH_INT58(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT58_SHIFT))&SAF_DMA_INTH_INT58_MASK)
#define SAF_DMA_INTH_INT59_MASK                     0x8000000u
#define SAF_DMA_INTH_INT59_SHIFT                    27u
#define SAF_DMA_INTH_INT59_WIDTH                    1u
#define SAF_DMA_INTH_INT59(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT59_SHIFT))&SAF_DMA_INTH_INT59_MASK)
#define SAF_DMA_INTH_INT60_MASK                     0x10000000u
#define SAF_DMA_INTH_INT60_SHIFT                    28u
#define SAF_DMA_INTH_INT60_WIDTH                    1u
#define SAF_DMA_INTH_INT60(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT60_SHIFT))&SAF_DMA_INTH_INT60_MASK)
#define SAF_DMA_INTH_INT61_MASK                     0x20000000u
#define SAF_DMA_INTH_INT61_SHIFT                    29u
#define SAF_DMA_INTH_INT61_WIDTH                    1u
#define SAF_DMA_INTH_INT61(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT61_SHIFT))&SAF_DMA_INTH_INT61_MASK)
#define SAF_DMA_INTH_INT62_MASK                     0x40000000u
#define SAF_DMA_INTH_INT62_SHIFT                    30u
#define SAF_DMA_INTH_INT62_WIDTH                    1u
#define SAF_DMA_INTH_INT62(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT62_SHIFT))&SAF_DMA_INTH_INT62_MASK)
#define SAF_DMA_INTH_INT63_MASK                     0x80000000u
#define SAF_DMA_INTH_INT63_SHIFT                    31u
#define SAF_DMA_INTH_INT63_WIDTH                    1u
#define SAF_DMA_INTH_INT63(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTH_INT63_SHIFT))&SAF_DMA_INTH_INT63_MASK)
/* INTL Bit Fields */
#define SAF_DMA_INTL_INT0_MASK                      0x1u
#define SAF_DMA_INTL_INT0_SHIFT                     0u
#define SAF_DMA_INTL_INT0_WIDTH                     1u
#define SAF_DMA_INTL_INT0(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT0_SHIFT))&SAF_DMA_INTL_INT0_MASK)
#define SAF_DMA_INTL_INT1_MASK                      0x2u
#define SAF_DMA_INTL_INT1_SHIFT                     1u
#define SAF_DMA_INTL_INT1_WIDTH                     1u
#define SAF_DMA_INTL_INT1(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT1_SHIFT))&SAF_DMA_INTL_INT1_MASK)
#define SAF_DMA_INTL_INT2_MASK                      0x4u
#define SAF_DMA_INTL_INT2_SHIFT                     2u
#define SAF_DMA_INTL_INT2_WIDTH                     1u
#define SAF_DMA_INTL_INT2(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT2_SHIFT))&SAF_DMA_INTL_INT2_MASK)
#define SAF_DMA_INTL_INT3_MASK                      0x8u
#define SAF_DMA_INTL_INT3_SHIFT                     3u
#define SAF_DMA_INTL_INT3_WIDTH                     1u
#define SAF_DMA_INTL_INT3(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT3_SHIFT))&SAF_DMA_INTL_INT3_MASK)
#define SAF_DMA_INTL_INT4_MASK                      0x10u
#define SAF_DMA_INTL_INT4_SHIFT                     4u
#define SAF_DMA_INTL_INT4_WIDTH                     1u
#define SAF_DMA_INTL_INT4(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT4_SHIFT))&SAF_DMA_INTL_INT4_MASK)
#define SAF_DMA_INTL_INT5_MASK                      0x20u
#define SAF_DMA_INTL_INT5_SHIFT                     5u
#define SAF_DMA_INTL_INT5_WIDTH                     1u
#define SAF_DMA_INTL_INT5(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT5_SHIFT))&SAF_DMA_INTL_INT5_MASK)
#define SAF_DMA_INTL_INT6_MASK                      0x40u
#define SAF_DMA_INTL_INT6_SHIFT                     6u
#define SAF_DMA_INTL_INT6_WIDTH                     1u
#define SAF_DMA_INTL_INT6(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT6_SHIFT))&SAF_DMA_INTL_INT6_MASK)
#define SAF_DMA_INTL_INT7_MASK                      0x80u
#define SAF_DMA_INTL_INT7_SHIFT                     7u
#define SAF_DMA_INTL_INT7_WIDTH                     1u
#define SAF_DMA_INTL_INT7(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT7_SHIFT))&SAF_DMA_INTL_INT7_MASK)
#define SAF_DMA_INTL_INT8_MASK                      0x100u
#define SAF_DMA_INTL_INT8_SHIFT                     8u
#define SAF_DMA_INTL_INT8_WIDTH                     1u
#define SAF_DMA_INTL_INT8(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT8_SHIFT))&SAF_DMA_INTL_INT8_MASK)
#define SAF_DMA_INTL_INT9_MASK                      0x200u
#define SAF_DMA_INTL_INT9_SHIFT                     9u
#define SAF_DMA_INTL_INT9_WIDTH                     1u
#define SAF_DMA_INTL_INT9(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT9_SHIFT))&SAF_DMA_INTL_INT9_MASK)
#define SAF_DMA_INTL_INT10_MASK                     0x400u
#define SAF_DMA_INTL_INT10_SHIFT                    10u
#define SAF_DMA_INTL_INT10_WIDTH                    1u
#define SAF_DMA_INTL_INT10(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT10_SHIFT))&SAF_DMA_INTL_INT10_MASK)
#define SAF_DMA_INTL_INT11_MASK                     0x800u
#define SAF_DMA_INTL_INT11_SHIFT                    11u
#define SAF_DMA_INTL_INT11_WIDTH                    1u
#define SAF_DMA_INTL_INT11(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT11_SHIFT))&SAF_DMA_INTL_INT11_MASK)
#define SAF_DMA_INTL_INT12_MASK                     0x1000u
#define SAF_DMA_INTL_INT12_SHIFT                    12u
#define SAF_DMA_INTL_INT12_WIDTH                    1u
#define SAF_DMA_INTL_INT12(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT12_SHIFT))&SAF_DMA_INTL_INT12_MASK)
#define SAF_DMA_INTL_INT13_MASK                     0x2000u
#define SAF_DMA_INTL_INT13_SHIFT                    13u
#define SAF_DMA_INTL_INT13_WIDTH                    1u
#define SAF_DMA_INTL_INT13(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT13_SHIFT))&SAF_DMA_INTL_INT13_MASK)
#define SAF_DMA_INTL_INT14_MASK                     0x4000u
#define SAF_DMA_INTL_INT14_SHIFT                    14u
#define SAF_DMA_INTL_INT14_WIDTH                    1u
#define SAF_DMA_INTL_INT14(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT14_SHIFT))&SAF_DMA_INTL_INT14_MASK)
#define SAF_DMA_INTL_INT15_MASK                     0x8000u
#define SAF_DMA_INTL_INT15_SHIFT                    15u
#define SAF_DMA_INTL_INT15_WIDTH                    1u
#define SAF_DMA_INTL_INT15(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT15_SHIFT))&SAF_DMA_INTL_INT15_MASK)
#define SAF_DMA_INTL_INT16_MASK                     0x10000u
#define SAF_DMA_INTL_INT16_SHIFT                    16u
#define SAF_DMA_INTL_INT16_WIDTH                    1u
#define SAF_DMA_INTL_INT16(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT16_SHIFT))&SAF_DMA_INTL_INT16_MASK)
#define SAF_DMA_INTL_INT17_MASK                     0x20000u
#define SAF_DMA_INTL_INT17_SHIFT                    17u
#define SAF_DMA_INTL_INT17_WIDTH                    1u
#define SAF_DMA_INTL_INT17(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT17_SHIFT))&SAF_DMA_INTL_INT17_MASK)
#define SAF_DMA_INTL_INT18_MASK                     0x40000u
#define SAF_DMA_INTL_INT18_SHIFT                    18u
#define SAF_DMA_INTL_INT18_WIDTH                    1u
#define SAF_DMA_INTL_INT18(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT18_SHIFT))&SAF_DMA_INTL_INT18_MASK)
#define SAF_DMA_INTL_INT19_MASK                     0x80000u
#define SAF_DMA_INTL_INT19_SHIFT                    19u
#define SAF_DMA_INTL_INT19_WIDTH                    1u
#define SAF_DMA_INTL_INT19(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT19_SHIFT))&SAF_DMA_INTL_INT19_MASK)
#define SAF_DMA_INTL_INT20_MASK                     0x100000u
#define SAF_DMA_INTL_INT20_SHIFT                    20u
#define SAF_DMA_INTL_INT20_WIDTH                    1u
#define SAF_DMA_INTL_INT20(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT20_SHIFT))&SAF_DMA_INTL_INT20_MASK)
#define SAF_DMA_INTL_INT21_MASK                     0x200000u
#define SAF_DMA_INTL_INT21_SHIFT                    21u
#define SAF_DMA_INTL_INT21_WIDTH                    1u
#define SAF_DMA_INTL_INT21(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT21_SHIFT))&SAF_DMA_INTL_INT21_MASK)
#define SAF_DMA_INTL_INT22_MASK                     0x400000u
#define SAF_DMA_INTL_INT22_SHIFT                    22u
#define SAF_DMA_INTL_INT22_WIDTH                    1u
#define SAF_DMA_INTL_INT22(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT22_SHIFT))&SAF_DMA_INTL_INT22_MASK)
#define SAF_DMA_INTL_INT23_MASK                     0x800000u
#define SAF_DMA_INTL_INT23_SHIFT                    23u
#define SAF_DMA_INTL_INT23_WIDTH                    1u
#define SAF_DMA_INTL_INT23(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT23_SHIFT))&SAF_DMA_INTL_INT23_MASK)
#define SAF_DMA_INTL_INT24_MASK                     0x1000000u
#define SAF_DMA_INTL_INT24_SHIFT                    24u
#define SAF_DMA_INTL_INT24_WIDTH                    1u
#define SAF_DMA_INTL_INT24(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT24_SHIFT))&SAF_DMA_INTL_INT24_MASK)
#define SAF_DMA_INTL_INT25_MASK                     0x2000000u
#define SAF_DMA_INTL_INT25_SHIFT                    25u
#define SAF_DMA_INTL_INT25_WIDTH                    1u
#define SAF_DMA_INTL_INT25(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT25_SHIFT))&SAF_DMA_INTL_INT25_MASK)
#define SAF_DMA_INTL_INT26_MASK                     0x4000000u
#define SAF_DMA_INTL_INT26_SHIFT                    26u
#define SAF_DMA_INTL_INT26_WIDTH                    1u
#define SAF_DMA_INTL_INT26(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT26_SHIFT))&SAF_DMA_INTL_INT26_MASK)
#define SAF_DMA_INTL_INT27_MASK                     0x8000000u
#define SAF_DMA_INTL_INT27_SHIFT                    27u
#define SAF_DMA_INTL_INT27_WIDTH                    1u
#define SAF_DMA_INTL_INT27(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT27_SHIFT))&SAF_DMA_INTL_INT27_MASK)
#define SAF_DMA_INTL_INT28_MASK                     0x10000000u
#define SAF_DMA_INTL_INT28_SHIFT                    28u
#define SAF_DMA_INTL_INT28_WIDTH                    1u
#define SAF_DMA_INTL_INT28(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT28_SHIFT))&SAF_DMA_INTL_INT28_MASK)
#define SAF_DMA_INTL_INT29_MASK                     0x20000000u
#define SAF_DMA_INTL_INT29_SHIFT                    29u
#define SAF_DMA_INTL_INT29_WIDTH                    1u
#define SAF_DMA_INTL_INT29(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT29_SHIFT))&SAF_DMA_INTL_INT29_MASK)
#define SAF_DMA_INTL_INT30_MASK                     0x40000000u
#define SAF_DMA_INTL_INT30_SHIFT                    30u
#define SAF_DMA_INTL_INT30_WIDTH                    1u
#define SAF_DMA_INTL_INT30(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT30_SHIFT))&SAF_DMA_INTL_INT30_MASK)
#define SAF_DMA_INTL_INT31_MASK                     0x80000000u
#define SAF_DMA_INTL_INT31_SHIFT                    31u
#define SAF_DMA_INTL_INT31_WIDTH                    1u
#define SAF_DMA_INTL_INT31(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_INTL_INT31_SHIFT))&SAF_DMA_INTL_INT31_MASK)
/* ERRH Bit Fields */
#define SAF_DMA_ERRH_ERR32_MASK                     0x1u
#define SAF_DMA_ERRH_ERR32_SHIFT                    0u
#define SAF_DMA_ERRH_ERR32_WIDTH                    1u
#define SAF_DMA_ERRH_ERR32(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR32_SHIFT))&SAF_DMA_ERRH_ERR32_MASK)
#define SAF_DMA_ERRH_ERR33_MASK                     0x2u
#define SAF_DMA_ERRH_ERR33_SHIFT                    1u
#define SAF_DMA_ERRH_ERR33_WIDTH                    1u
#define SAF_DMA_ERRH_ERR33(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR33_SHIFT))&SAF_DMA_ERRH_ERR33_MASK)
#define SAF_DMA_ERRH_ERR34_MASK                     0x4u
#define SAF_DMA_ERRH_ERR34_SHIFT                    2u
#define SAF_DMA_ERRH_ERR34_WIDTH                    1u
#define SAF_DMA_ERRH_ERR34(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR34_SHIFT))&SAF_DMA_ERRH_ERR34_MASK)
#define SAF_DMA_ERRH_ERR35_MASK                     0x8u
#define SAF_DMA_ERRH_ERR35_SHIFT                    3u
#define SAF_DMA_ERRH_ERR35_WIDTH                    1u
#define SAF_DMA_ERRH_ERR35(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR35_SHIFT))&SAF_DMA_ERRH_ERR35_MASK)
#define SAF_DMA_ERRH_ERR36_MASK                     0x10u
#define SAF_DMA_ERRH_ERR36_SHIFT                    4u
#define SAF_DMA_ERRH_ERR36_WIDTH                    1u
#define SAF_DMA_ERRH_ERR36(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR36_SHIFT))&SAF_DMA_ERRH_ERR36_MASK)
#define SAF_DMA_ERRH_ERR37_MASK                     0x20u
#define SAF_DMA_ERRH_ERR37_SHIFT                    5u
#define SAF_DMA_ERRH_ERR37_WIDTH                    1u
#define SAF_DMA_ERRH_ERR37(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR37_SHIFT))&SAF_DMA_ERRH_ERR37_MASK)
#define SAF_DMA_ERRH_ERR38_MASK                     0x40u
#define SAF_DMA_ERRH_ERR38_SHIFT                    6u
#define SAF_DMA_ERRH_ERR38_WIDTH                    1u
#define SAF_DMA_ERRH_ERR38(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR38_SHIFT))&SAF_DMA_ERRH_ERR38_MASK)
#define SAF_DMA_ERRH_ERR39_MASK                     0x80u
#define SAF_DMA_ERRH_ERR39_SHIFT                    7u
#define SAF_DMA_ERRH_ERR39_WIDTH                    1u
#define SAF_DMA_ERRH_ERR39(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR39_SHIFT))&SAF_DMA_ERRH_ERR39_MASK)
#define SAF_DMA_ERRH_ERR40_MASK                     0x100u
#define SAF_DMA_ERRH_ERR40_SHIFT                    8u
#define SAF_DMA_ERRH_ERR40_WIDTH                    1u
#define SAF_DMA_ERRH_ERR40(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR40_SHIFT))&SAF_DMA_ERRH_ERR40_MASK)
#define SAF_DMA_ERRH_ERR41_MASK                     0x200u
#define SAF_DMA_ERRH_ERR41_SHIFT                    9u
#define SAF_DMA_ERRH_ERR41_WIDTH                    1u
#define SAF_DMA_ERRH_ERR41(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR41_SHIFT))&SAF_DMA_ERRH_ERR41_MASK)
#define SAF_DMA_ERRH_ERR42_MASK                     0x400u
#define SAF_DMA_ERRH_ERR42_SHIFT                    10u
#define SAF_DMA_ERRH_ERR42_WIDTH                    1u
#define SAF_DMA_ERRH_ERR42(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR42_SHIFT))&SAF_DMA_ERRH_ERR42_MASK)
#define SAF_DMA_ERRH_ERR43_MASK                     0x800u
#define SAF_DMA_ERRH_ERR43_SHIFT                    11u
#define SAF_DMA_ERRH_ERR43_WIDTH                    1u
#define SAF_DMA_ERRH_ERR43(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR43_SHIFT))&SAF_DMA_ERRH_ERR43_MASK)
#define SAF_DMA_ERRH_ERR44_MASK                     0x1000u
#define SAF_DMA_ERRH_ERR44_SHIFT                    12u
#define SAF_DMA_ERRH_ERR44_WIDTH                    1u
#define SAF_DMA_ERRH_ERR44(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR44_SHIFT))&SAF_DMA_ERRH_ERR44_MASK)
#define SAF_DMA_ERRH_ERR45_MASK                     0x2000u
#define SAF_DMA_ERRH_ERR45_SHIFT                    13u
#define SAF_DMA_ERRH_ERR45_WIDTH                    1u
#define SAF_DMA_ERRH_ERR45(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR45_SHIFT))&SAF_DMA_ERRH_ERR45_MASK)
#define SAF_DMA_ERRH_ERR46_MASK                     0x4000u
#define SAF_DMA_ERRH_ERR46_SHIFT                    14u
#define SAF_DMA_ERRH_ERR46_WIDTH                    1u
#define SAF_DMA_ERRH_ERR46(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR46_SHIFT))&SAF_DMA_ERRH_ERR46_MASK)
#define SAF_DMA_ERRH_ERR47_MASK                     0x8000u
#define SAF_DMA_ERRH_ERR47_SHIFT                    15u
#define SAF_DMA_ERRH_ERR47_WIDTH                    1u
#define SAF_DMA_ERRH_ERR47(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR47_SHIFT))&SAF_DMA_ERRH_ERR47_MASK)
#define SAF_DMA_ERRH_ERR48_MASK                     0x10000u
#define SAF_DMA_ERRH_ERR48_SHIFT                    16u
#define SAF_DMA_ERRH_ERR48_WIDTH                    1u
#define SAF_DMA_ERRH_ERR48(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR48_SHIFT))&SAF_DMA_ERRH_ERR48_MASK)
#define SAF_DMA_ERRH_ERR49_MASK                     0x20000u
#define SAF_DMA_ERRH_ERR49_SHIFT                    17u
#define SAF_DMA_ERRH_ERR49_WIDTH                    1u
#define SAF_DMA_ERRH_ERR49(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR49_SHIFT))&SAF_DMA_ERRH_ERR49_MASK)
#define SAF_DMA_ERRH_ERR50_MASK                     0x40000u
#define SAF_DMA_ERRH_ERR50_SHIFT                    18u
#define SAF_DMA_ERRH_ERR50_WIDTH                    1u
#define SAF_DMA_ERRH_ERR50(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR50_SHIFT))&SAF_DMA_ERRH_ERR50_MASK)
#define SAF_DMA_ERRH_ERR51_MASK                     0x80000u
#define SAF_DMA_ERRH_ERR51_SHIFT                    19u
#define SAF_DMA_ERRH_ERR51_WIDTH                    1u
#define SAF_DMA_ERRH_ERR51(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR51_SHIFT))&SAF_DMA_ERRH_ERR51_MASK)
#define SAF_DMA_ERRH_ERR52_MASK                     0x100000u
#define SAF_DMA_ERRH_ERR52_SHIFT                    20u
#define SAF_DMA_ERRH_ERR52_WIDTH                    1u
#define SAF_DMA_ERRH_ERR52(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR52_SHIFT))&SAF_DMA_ERRH_ERR52_MASK)
#define SAF_DMA_ERRH_ERR53_MASK                     0x200000u
#define SAF_DMA_ERRH_ERR53_SHIFT                    21u
#define SAF_DMA_ERRH_ERR53_WIDTH                    1u
#define SAF_DMA_ERRH_ERR53(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR53_SHIFT))&SAF_DMA_ERRH_ERR53_MASK)
#define SAF_DMA_ERRH_ERR54_MASK                     0x400000u
#define SAF_DMA_ERRH_ERR54_SHIFT                    22u
#define SAF_DMA_ERRH_ERR54_WIDTH                    1u
#define SAF_DMA_ERRH_ERR54(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR54_SHIFT))&SAF_DMA_ERRH_ERR54_MASK)
#define SAF_DMA_ERRH_ERR55_MASK                     0x800000u
#define SAF_DMA_ERRH_ERR55_SHIFT                    23u
#define SAF_DMA_ERRH_ERR55_WIDTH                    1u
#define SAF_DMA_ERRH_ERR55(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR55_SHIFT))&SAF_DMA_ERRH_ERR55_MASK)
#define SAF_DMA_ERRH_ERR56_MASK                     0x1000000u
#define SAF_DMA_ERRH_ERR56_SHIFT                    24u
#define SAF_DMA_ERRH_ERR56_WIDTH                    1u
#define SAF_DMA_ERRH_ERR56(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR56_SHIFT))&SAF_DMA_ERRH_ERR56_MASK)
#define SAF_DMA_ERRH_ERR57_MASK                     0x2000000u
#define SAF_DMA_ERRH_ERR57_SHIFT                    25u
#define SAF_DMA_ERRH_ERR57_WIDTH                    1u
#define SAF_DMA_ERRH_ERR57(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR57_SHIFT))&SAF_DMA_ERRH_ERR57_MASK)
#define SAF_DMA_ERRH_ERR58_MASK                     0x4000000u
#define SAF_DMA_ERRH_ERR58_SHIFT                    26u
#define SAF_DMA_ERRH_ERR58_WIDTH                    1u
#define SAF_DMA_ERRH_ERR58(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR58_SHIFT))&SAF_DMA_ERRH_ERR58_MASK)
#define SAF_DMA_ERRH_ERR59_MASK                     0x8000000u
#define SAF_DMA_ERRH_ERR59_SHIFT                    27u
#define SAF_DMA_ERRH_ERR59_WIDTH                    1u
#define SAF_DMA_ERRH_ERR59(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR59_SHIFT))&SAF_DMA_ERRH_ERR59_MASK)
#define SAF_DMA_ERRH_ERR60_MASK                     0x10000000u
#define SAF_DMA_ERRH_ERR60_SHIFT                    28u
#define SAF_DMA_ERRH_ERR60_WIDTH                    1u
#define SAF_DMA_ERRH_ERR60(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR60_SHIFT))&SAF_DMA_ERRH_ERR60_MASK)
#define SAF_DMA_ERRH_ERR61_MASK                     0x20000000u
#define SAF_DMA_ERRH_ERR61_SHIFT                    29u
#define SAF_DMA_ERRH_ERR61_WIDTH                    1u
#define SAF_DMA_ERRH_ERR61(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR61_SHIFT))&SAF_DMA_ERRH_ERR61_MASK)
#define SAF_DMA_ERRH_ERR62_MASK                     0x40000000u
#define SAF_DMA_ERRH_ERR62_SHIFT                    30u
#define SAF_DMA_ERRH_ERR62_WIDTH                    1u
#define SAF_DMA_ERRH_ERR62(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR62_SHIFT))&SAF_DMA_ERRH_ERR62_MASK)
#define SAF_DMA_ERRH_ERR63_MASK                     0x80000000u
#define SAF_DMA_ERRH_ERR63_SHIFT                    31u
#define SAF_DMA_ERRH_ERR63_WIDTH                    1u
#define SAF_DMA_ERRH_ERR63(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRH_ERR63_SHIFT))&SAF_DMA_ERRH_ERR63_MASK)
/* ERRL Bit Fields */
#define SAF_DMA_ERRL_ERR0_MASK                      0x1u
#define SAF_DMA_ERRL_ERR0_SHIFT                     0u
#define SAF_DMA_ERRL_ERR0_WIDTH                     1u
#define SAF_DMA_ERRL_ERR0(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR0_SHIFT))&SAF_DMA_ERRL_ERR0_MASK)
#define SAF_DMA_ERRL_ERR1_MASK                      0x2u
#define SAF_DMA_ERRL_ERR1_SHIFT                     1u
#define SAF_DMA_ERRL_ERR1_WIDTH                     1u
#define SAF_DMA_ERRL_ERR1(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR1_SHIFT))&SAF_DMA_ERRL_ERR1_MASK)
#define SAF_DMA_ERRL_ERR2_MASK                      0x4u
#define SAF_DMA_ERRL_ERR2_SHIFT                     2u
#define SAF_DMA_ERRL_ERR2_WIDTH                     1u
#define SAF_DMA_ERRL_ERR2(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR2_SHIFT))&SAF_DMA_ERRL_ERR2_MASK)
#define SAF_DMA_ERRL_ERR3_MASK                      0x8u
#define SAF_DMA_ERRL_ERR3_SHIFT                     3u
#define SAF_DMA_ERRL_ERR3_WIDTH                     1u
#define SAF_DMA_ERRL_ERR3(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR3_SHIFT))&SAF_DMA_ERRL_ERR3_MASK)
#define SAF_DMA_ERRL_ERR4_MASK                      0x10u
#define SAF_DMA_ERRL_ERR4_SHIFT                     4u
#define SAF_DMA_ERRL_ERR4_WIDTH                     1u
#define SAF_DMA_ERRL_ERR4(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR4_SHIFT))&SAF_DMA_ERRL_ERR4_MASK)
#define SAF_DMA_ERRL_ERR5_MASK                      0x20u
#define SAF_DMA_ERRL_ERR5_SHIFT                     5u
#define SAF_DMA_ERRL_ERR5_WIDTH                     1u
#define SAF_DMA_ERRL_ERR5(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR5_SHIFT))&SAF_DMA_ERRL_ERR5_MASK)
#define SAF_DMA_ERRL_ERR6_MASK                      0x40u
#define SAF_DMA_ERRL_ERR6_SHIFT                     6u
#define SAF_DMA_ERRL_ERR6_WIDTH                     1u
#define SAF_DMA_ERRL_ERR6(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR6_SHIFT))&SAF_DMA_ERRL_ERR6_MASK)
#define SAF_DMA_ERRL_ERR7_MASK                      0x80u
#define SAF_DMA_ERRL_ERR7_SHIFT                     7u
#define SAF_DMA_ERRL_ERR7_WIDTH                     1u
#define SAF_DMA_ERRL_ERR7(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR7_SHIFT))&SAF_DMA_ERRL_ERR7_MASK)
#define SAF_DMA_ERRL_ERR8_MASK                      0x100u
#define SAF_DMA_ERRL_ERR8_SHIFT                     8u
#define SAF_DMA_ERRL_ERR8_WIDTH                     1u
#define SAF_DMA_ERRL_ERR8(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR8_SHIFT))&SAF_DMA_ERRL_ERR8_MASK)
#define SAF_DMA_ERRL_ERR9_MASK                      0x200u
#define SAF_DMA_ERRL_ERR9_SHIFT                     9u
#define SAF_DMA_ERRL_ERR9_WIDTH                     1u
#define SAF_DMA_ERRL_ERR9(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR9_SHIFT))&SAF_DMA_ERRL_ERR9_MASK)
#define SAF_DMA_ERRL_ERR10_MASK                     0x400u
#define SAF_DMA_ERRL_ERR10_SHIFT                    10u
#define SAF_DMA_ERRL_ERR10_WIDTH                    1u
#define SAF_DMA_ERRL_ERR10(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR10_SHIFT))&SAF_DMA_ERRL_ERR10_MASK)
#define SAF_DMA_ERRL_ERR11_MASK                     0x800u
#define SAF_DMA_ERRL_ERR11_SHIFT                    11u
#define SAF_DMA_ERRL_ERR11_WIDTH                    1u
#define SAF_DMA_ERRL_ERR11(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR11_SHIFT))&SAF_DMA_ERRL_ERR11_MASK)
#define SAF_DMA_ERRL_ERR12_MASK                     0x1000u
#define SAF_DMA_ERRL_ERR12_SHIFT                    12u
#define SAF_DMA_ERRL_ERR12_WIDTH                    1u
#define SAF_DMA_ERRL_ERR12(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR12_SHIFT))&SAF_DMA_ERRL_ERR12_MASK)
#define SAF_DMA_ERRL_ERR13_MASK                     0x2000u
#define SAF_DMA_ERRL_ERR13_SHIFT                    13u
#define SAF_DMA_ERRL_ERR13_WIDTH                    1u
#define SAF_DMA_ERRL_ERR13(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR13_SHIFT))&SAF_DMA_ERRL_ERR13_MASK)
#define SAF_DMA_ERRL_ERR14_MASK                     0x4000u
#define SAF_DMA_ERRL_ERR14_SHIFT                    14u
#define SAF_DMA_ERRL_ERR14_WIDTH                    1u
#define SAF_DMA_ERRL_ERR14(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR14_SHIFT))&SAF_DMA_ERRL_ERR14_MASK)
#define SAF_DMA_ERRL_ERR15_MASK                     0x8000u
#define SAF_DMA_ERRL_ERR15_SHIFT                    15u
#define SAF_DMA_ERRL_ERR15_WIDTH                    1u
#define SAF_DMA_ERRL_ERR15(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR15_SHIFT))&SAF_DMA_ERRL_ERR15_MASK)
#define SAF_DMA_ERRL_ERR16_MASK                     0x10000u
#define SAF_DMA_ERRL_ERR16_SHIFT                    16u
#define SAF_DMA_ERRL_ERR16_WIDTH                    1u
#define SAF_DMA_ERRL_ERR16(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR16_SHIFT))&SAF_DMA_ERRL_ERR16_MASK)
#define SAF_DMA_ERRL_ERR17_MASK                     0x20000u
#define SAF_DMA_ERRL_ERR17_SHIFT                    17u
#define SAF_DMA_ERRL_ERR17_WIDTH                    1u
#define SAF_DMA_ERRL_ERR17(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR17_SHIFT))&SAF_DMA_ERRL_ERR17_MASK)
#define SAF_DMA_ERRL_ERR18_MASK                     0x40000u
#define SAF_DMA_ERRL_ERR18_SHIFT                    18u
#define SAF_DMA_ERRL_ERR18_WIDTH                    1u
#define SAF_DMA_ERRL_ERR18(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR18_SHIFT))&SAF_DMA_ERRL_ERR18_MASK)
#define SAF_DMA_ERRL_ERR19_MASK                     0x80000u
#define SAF_DMA_ERRL_ERR19_SHIFT                    19u
#define SAF_DMA_ERRL_ERR19_WIDTH                    1u
#define SAF_DMA_ERRL_ERR19(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR19_SHIFT))&SAF_DMA_ERRL_ERR19_MASK)
#define SAF_DMA_ERRL_ERR20_MASK                     0x100000u
#define SAF_DMA_ERRL_ERR20_SHIFT                    20u
#define SAF_DMA_ERRL_ERR20_WIDTH                    1u
#define SAF_DMA_ERRL_ERR20(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR20_SHIFT))&SAF_DMA_ERRL_ERR20_MASK)
#define SAF_DMA_ERRL_ERR21_MASK                     0x200000u
#define SAF_DMA_ERRL_ERR21_SHIFT                    21u
#define SAF_DMA_ERRL_ERR21_WIDTH                    1u
#define SAF_DMA_ERRL_ERR21(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR21_SHIFT))&SAF_DMA_ERRL_ERR21_MASK)
#define SAF_DMA_ERRL_ERR22_MASK                     0x400000u
#define SAF_DMA_ERRL_ERR22_SHIFT                    22u
#define SAF_DMA_ERRL_ERR22_WIDTH                    1u
#define SAF_DMA_ERRL_ERR22(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR22_SHIFT))&SAF_DMA_ERRL_ERR22_MASK)
#define SAF_DMA_ERRL_ERR23_MASK                     0x800000u
#define SAF_DMA_ERRL_ERR23_SHIFT                    23u
#define SAF_DMA_ERRL_ERR23_WIDTH                    1u
#define SAF_DMA_ERRL_ERR23(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR23_SHIFT))&SAF_DMA_ERRL_ERR23_MASK)
#define SAF_DMA_ERRL_ERR24_MASK                     0x1000000u
#define SAF_DMA_ERRL_ERR24_SHIFT                    24u
#define SAF_DMA_ERRL_ERR24_WIDTH                    1u
#define SAF_DMA_ERRL_ERR24(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR24_SHIFT))&SAF_DMA_ERRL_ERR24_MASK)
#define SAF_DMA_ERRL_ERR25_MASK                     0x2000000u
#define SAF_DMA_ERRL_ERR25_SHIFT                    25u
#define SAF_DMA_ERRL_ERR25_WIDTH                    1u
#define SAF_DMA_ERRL_ERR25(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR25_SHIFT))&SAF_DMA_ERRL_ERR25_MASK)
#define SAF_DMA_ERRL_ERR26_MASK                     0x4000000u
#define SAF_DMA_ERRL_ERR26_SHIFT                    26u
#define SAF_DMA_ERRL_ERR26_WIDTH                    1u
#define SAF_DMA_ERRL_ERR26(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR26_SHIFT))&SAF_DMA_ERRL_ERR26_MASK)
#define SAF_DMA_ERRL_ERR27_MASK                     0x8000000u
#define SAF_DMA_ERRL_ERR27_SHIFT                    27u
#define SAF_DMA_ERRL_ERR27_WIDTH                    1u
#define SAF_DMA_ERRL_ERR27(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR27_SHIFT))&SAF_DMA_ERRL_ERR27_MASK)
#define SAF_DMA_ERRL_ERR28_MASK                     0x10000000u
#define SAF_DMA_ERRL_ERR28_SHIFT                    28u
#define SAF_DMA_ERRL_ERR28_WIDTH                    1u
#define SAF_DMA_ERRL_ERR28(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR28_SHIFT))&SAF_DMA_ERRL_ERR28_MASK)
#define SAF_DMA_ERRL_ERR29_MASK                     0x20000000u
#define SAF_DMA_ERRL_ERR29_SHIFT                    29u
#define SAF_DMA_ERRL_ERR29_WIDTH                    1u
#define SAF_DMA_ERRL_ERR29(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR29_SHIFT))&SAF_DMA_ERRL_ERR29_MASK)
#define SAF_DMA_ERRL_ERR30_MASK                     0x40000000u
#define SAF_DMA_ERRL_ERR30_SHIFT                    30u
#define SAF_DMA_ERRL_ERR30_WIDTH                    1u
#define SAF_DMA_ERRL_ERR30(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR30_SHIFT))&SAF_DMA_ERRL_ERR30_MASK)
#define SAF_DMA_ERRL_ERR31_MASK                     0x80000000u
#define SAF_DMA_ERRL_ERR31_SHIFT                    31u
#define SAF_DMA_ERRL_ERR31_WIDTH                    1u
#define SAF_DMA_ERRL_ERR31(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_ERRL_ERR31_SHIFT))&SAF_DMA_ERRL_ERR31_MASK)
/* HRSH Bit Fields */
#define SAF_DMA_HRSH_HRS32_MASK                     0x1u
#define SAF_DMA_HRSH_HRS32_SHIFT                    0u
#define SAF_DMA_HRSH_HRS32_WIDTH                    1u
#define SAF_DMA_HRSH_HRS32(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS32_SHIFT))&SAF_DMA_HRSH_HRS32_MASK)
#define SAF_DMA_HRSH_HRS33_MASK                     0x2u
#define SAF_DMA_HRSH_HRS33_SHIFT                    1u
#define SAF_DMA_HRSH_HRS33_WIDTH                    1u
#define SAF_DMA_HRSH_HRS33(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS33_SHIFT))&SAF_DMA_HRSH_HRS33_MASK)
#define SAF_DMA_HRSH_HRS34_MASK                     0x4u
#define SAF_DMA_HRSH_HRS34_SHIFT                    2u
#define SAF_DMA_HRSH_HRS34_WIDTH                    1u
#define SAF_DMA_HRSH_HRS34(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS34_SHIFT))&SAF_DMA_HRSH_HRS34_MASK)
#define SAF_DMA_HRSH_HRS35_MASK                     0x8u
#define SAF_DMA_HRSH_HRS35_SHIFT                    3u
#define SAF_DMA_HRSH_HRS35_WIDTH                    1u
#define SAF_DMA_HRSH_HRS35(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS35_SHIFT))&SAF_DMA_HRSH_HRS35_MASK)
#define SAF_DMA_HRSH_HRS36_MASK                     0x10u
#define SAF_DMA_HRSH_HRS36_SHIFT                    4u
#define SAF_DMA_HRSH_HRS36_WIDTH                    1u
#define SAF_DMA_HRSH_HRS36(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS36_SHIFT))&SAF_DMA_HRSH_HRS36_MASK)
#define SAF_DMA_HRSH_HRS37_MASK                     0x20u
#define SAF_DMA_HRSH_HRS37_SHIFT                    5u
#define SAF_DMA_HRSH_HRS37_WIDTH                    1u
#define SAF_DMA_HRSH_HRS37(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS37_SHIFT))&SAF_DMA_HRSH_HRS37_MASK)
#define SAF_DMA_HRSH_HRS38_MASK                     0x40u
#define SAF_DMA_HRSH_HRS38_SHIFT                    6u
#define SAF_DMA_HRSH_HRS38_WIDTH                    1u
#define SAF_DMA_HRSH_HRS38(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS38_SHIFT))&SAF_DMA_HRSH_HRS38_MASK)
#define SAF_DMA_HRSH_HRS39_MASK                     0x80u
#define SAF_DMA_HRSH_HRS39_SHIFT                    7u
#define SAF_DMA_HRSH_HRS39_WIDTH                    1u
#define SAF_DMA_HRSH_HRS39(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS39_SHIFT))&SAF_DMA_HRSH_HRS39_MASK)
#define SAF_DMA_HRSH_HRS40_MASK                     0x100u
#define SAF_DMA_HRSH_HRS40_SHIFT                    8u
#define SAF_DMA_HRSH_HRS40_WIDTH                    1u
#define SAF_DMA_HRSH_HRS40(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS40_SHIFT))&SAF_DMA_HRSH_HRS40_MASK)
#define SAF_DMA_HRSH_HRS41_MASK                     0x200u
#define SAF_DMA_HRSH_HRS41_SHIFT                    9u
#define SAF_DMA_HRSH_HRS41_WIDTH                    1u
#define SAF_DMA_HRSH_HRS41(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS41_SHIFT))&SAF_DMA_HRSH_HRS41_MASK)
#define SAF_DMA_HRSH_HRS42_MASK                     0x400u
#define SAF_DMA_HRSH_HRS42_SHIFT                    10u
#define SAF_DMA_HRSH_HRS42_WIDTH                    1u
#define SAF_DMA_HRSH_HRS42(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS42_SHIFT))&SAF_DMA_HRSH_HRS42_MASK)
#define SAF_DMA_HRSH_HRS43_MASK                     0x800u
#define SAF_DMA_HRSH_HRS43_SHIFT                    11u
#define SAF_DMA_HRSH_HRS43_WIDTH                    1u
#define SAF_DMA_HRSH_HRS43(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS43_SHIFT))&SAF_DMA_HRSH_HRS43_MASK)
#define SAF_DMA_HRSH_HRS44_MASK                     0x1000u
#define SAF_DMA_HRSH_HRS44_SHIFT                    12u
#define SAF_DMA_HRSH_HRS44_WIDTH                    1u
#define SAF_DMA_HRSH_HRS44(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS44_SHIFT))&SAF_DMA_HRSH_HRS44_MASK)
#define SAF_DMA_HRSH_HRS45_MASK                     0x2000u
#define SAF_DMA_HRSH_HRS45_SHIFT                    13u
#define SAF_DMA_HRSH_HRS45_WIDTH                    1u
#define SAF_DMA_HRSH_HRS45(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS45_SHIFT))&SAF_DMA_HRSH_HRS45_MASK)
#define SAF_DMA_HRSH_HRS46_MASK                     0x4000u
#define SAF_DMA_HRSH_HRS46_SHIFT                    14u
#define SAF_DMA_HRSH_HRS46_WIDTH                    1u
#define SAF_DMA_HRSH_HRS46(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS46_SHIFT))&SAF_DMA_HRSH_HRS46_MASK)
#define SAF_DMA_HRSH_HRS47_MASK                     0x8000u
#define SAF_DMA_HRSH_HRS47_SHIFT                    15u
#define SAF_DMA_HRSH_HRS47_WIDTH                    1u
#define SAF_DMA_HRSH_HRS47(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS47_SHIFT))&SAF_DMA_HRSH_HRS47_MASK)
#define SAF_DMA_HRSH_HRS48_MASK                     0x10000u
#define SAF_DMA_HRSH_HRS48_SHIFT                    16u
#define SAF_DMA_HRSH_HRS48_WIDTH                    1u
#define SAF_DMA_HRSH_HRS48(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS48_SHIFT))&SAF_DMA_HRSH_HRS48_MASK)
#define SAF_DMA_HRSH_HRS49_MASK                     0x20000u
#define SAF_DMA_HRSH_HRS49_SHIFT                    17u
#define SAF_DMA_HRSH_HRS49_WIDTH                    1u
#define SAF_DMA_HRSH_HRS49(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS49_SHIFT))&SAF_DMA_HRSH_HRS49_MASK)
#define SAF_DMA_HRSH_HRS50_MASK                     0x40000u
#define SAF_DMA_HRSH_HRS50_SHIFT                    18u
#define SAF_DMA_HRSH_HRS50_WIDTH                    1u
#define SAF_DMA_HRSH_HRS50(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS50_SHIFT))&SAF_DMA_HRSH_HRS50_MASK)
#define SAF_DMA_HRSH_HRS51_MASK                     0x80000u
#define SAF_DMA_HRSH_HRS51_SHIFT                    19u
#define SAF_DMA_HRSH_HRS51_WIDTH                    1u
#define SAF_DMA_HRSH_HRS51(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS51_SHIFT))&SAF_DMA_HRSH_HRS51_MASK)
#define SAF_DMA_HRSH_HRS52_MASK                     0x100000u
#define SAF_DMA_HRSH_HRS52_SHIFT                    20u
#define SAF_DMA_HRSH_HRS52_WIDTH                    1u
#define SAF_DMA_HRSH_HRS52(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS52_SHIFT))&SAF_DMA_HRSH_HRS52_MASK)
#define SAF_DMA_HRSH_HRS53_MASK                     0x200000u
#define SAF_DMA_HRSH_HRS53_SHIFT                    21u
#define SAF_DMA_HRSH_HRS53_WIDTH                    1u
#define SAF_DMA_HRSH_HRS53(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS53_SHIFT))&SAF_DMA_HRSH_HRS53_MASK)
#define SAF_DMA_HRSH_HRS54_MASK                     0x400000u
#define SAF_DMA_HRSH_HRS54_SHIFT                    22u
#define SAF_DMA_HRSH_HRS54_WIDTH                    1u
#define SAF_DMA_HRSH_HRS54(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS54_SHIFT))&SAF_DMA_HRSH_HRS54_MASK)
#define SAF_DMA_HRSH_HRS55_MASK                     0x800000u
#define SAF_DMA_HRSH_HRS55_SHIFT                    23u
#define SAF_DMA_HRSH_HRS55_WIDTH                    1u
#define SAF_DMA_HRSH_HRS55(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS55_SHIFT))&SAF_DMA_HRSH_HRS55_MASK)
#define SAF_DMA_HRSH_HRS56_MASK                     0x1000000u
#define SAF_DMA_HRSH_HRS56_SHIFT                    24u
#define SAF_DMA_HRSH_HRS56_WIDTH                    1u
#define SAF_DMA_HRSH_HRS56(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS56_SHIFT))&SAF_DMA_HRSH_HRS56_MASK)
#define SAF_DMA_HRSH_HRS57_MASK                     0x2000000u
#define SAF_DMA_HRSH_HRS57_SHIFT                    25u
#define SAF_DMA_HRSH_HRS57_WIDTH                    1u
#define SAF_DMA_HRSH_HRS57(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS57_SHIFT))&SAF_DMA_HRSH_HRS57_MASK)
#define SAF_DMA_HRSH_HRS58_MASK                     0x4000000u
#define SAF_DMA_HRSH_HRS58_SHIFT                    26u
#define SAF_DMA_HRSH_HRS58_WIDTH                    1u
#define SAF_DMA_HRSH_HRS58(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS58_SHIFT))&SAF_DMA_HRSH_HRS58_MASK)
#define SAF_DMA_HRSH_HRS59_MASK                     0x8000000u
#define SAF_DMA_HRSH_HRS59_SHIFT                    27u
#define SAF_DMA_HRSH_HRS59_WIDTH                    1u
#define SAF_DMA_HRSH_HRS59(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS59_SHIFT))&SAF_DMA_HRSH_HRS59_MASK)
#define SAF_DMA_HRSH_HRS60_MASK                     0x10000000u
#define SAF_DMA_HRSH_HRS60_SHIFT                    28u
#define SAF_DMA_HRSH_HRS60_WIDTH                    1u
#define SAF_DMA_HRSH_HRS60(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS60_SHIFT))&SAF_DMA_HRSH_HRS60_MASK)
#define SAF_DMA_HRSH_HRS61_MASK                     0x20000000u
#define SAF_DMA_HRSH_HRS61_SHIFT                    29u
#define SAF_DMA_HRSH_HRS61_WIDTH                    1u
#define SAF_DMA_HRSH_HRS61(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS61_SHIFT))&SAF_DMA_HRSH_HRS61_MASK)
#define SAF_DMA_HRSH_HRS62_MASK                     0x40000000u
#define SAF_DMA_HRSH_HRS62_SHIFT                    30u
#define SAF_DMA_HRSH_HRS62_WIDTH                    1u
#define SAF_DMA_HRSH_HRS62(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS62_SHIFT))&SAF_DMA_HRSH_HRS62_MASK)
#define SAF_DMA_HRSH_HRS63_MASK                     0x80000000u
#define SAF_DMA_HRSH_HRS63_SHIFT                    31u
#define SAF_DMA_HRSH_HRS63_WIDTH                    1u
#define SAF_DMA_HRSH_HRS63(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSH_HRS63_SHIFT))&SAF_DMA_HRSH_HRS63_MASK)
/* HRSL Bit Fields */
#define SAF_DMA_HRSL_HRS0_MASK                      0x1u
#define SAF_DMA_HRSL_HRS0_SHIFT                     0u
#define SAF_DMA_HRSL_HRS0_WIDTH                     1u
#define SAF_DMA_HRSL_HRS0(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS0_SHIFT))&SAF_DMA_HRSL_HRS0_MASK)
#define SAF_DMA_HRSL_HRS1_MASK                      0x2u
#define SAF_DMA_HRSL_HRS1_SHIFT                     1u
#define SAF_DMA_HRSL_HRS1_WIDTH                     1u
#define SAF_DMA_HRSL_HRS1(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS1_SHIFT))&SAF_DMA_HRSL_HRS1_MASK)
#define SAF_DMA_HRSL_HRS2_MASK                      0x4u
#define SAF_DMA_HRSL_HRS2_SHIFT                     2u
#define SAF_DMA_HRSL_HRS2_WIDTH                     1u
#define SAF_DMA_HRSL_HRS2(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS2_SHIFT))&SAF_DMA_HRSL_HRS2_MASK)
#define SAF_DMA_HRSL_HRS3_MASK                      0x8u
#define SAF_DMA_HRSL_HRS3_SHIFT                     3u
#define SAF_DMA_HRSL_HRS3_WIDTH                     1u
#define SAF_DMA_HRSL_HRS3(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS3_SHIFT))&SAF_DMA_HRSL_HRS3_MASK)
#define SAF_DMA_HRSL_HRS4_MASK                      0x10u
#define SAF_DMA_HRSL_HRS4_SHIFT                     4u
#define SAF_DMA_HRSL_HRS4_WIDTH                     1u
#define SAF_DMA_HRSL_HRS4(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS4_SHIFT))&SAF_DMA_HRSL_HRS4_MASK)
#define SAF_DMA_HRSL_HRS5_MASK                      0x20u
#define SAF_DMA_HRSL_HRS5_SHIFT                     5u
#define SAF_DMA_HRSL_HRS5_WIDTH                     1u
#define SAF_DMA_HRSL_HRS5(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS5_SHIFT))&SAF_DMA_HRSL_HRS5_MASK)
#define SAF_DMA_HRSL_HRS6_MASK                      0x40u
#define SAF_DMA_HRSL_HRS6_SHIFT                     6u
#define SAF_DMA_HRSL_HRS6_WIDTH                     1u
#define SAF_DMA_HRSL_HRS6(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS6_SHIFT))&SAF_DMA_HRSL_HRS6_MASK)
#define SAF_DMA_HRSL_HRS7_MASK                      0x80u
#define SAF_DMA_HRSL_HRS7_SHIFT                     7u
#define SAF_DMA_HRSL_HRS7_WIDTH                     1u
#define SAF_DMA_HRSL_HRS7(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS7_SHIFT))&SAF_DMA_HRSL_HRS7_MASK)
#define SAF_DMA_HRSL_HRS8_MASK                      0x100u
#define SAF_DMA_HRSL_HRS8_SHIFT                     8u
#define SAF_DMA_HRSL_HRS8_WIDTH                     1u
#define SAF_DMA_HRSL_HRS8(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS8_SHIFT))&SAF_DMA_HRSL_HRS8_MASK)
#define SAF_DMA_HRSL_HRS9_MASK                      0x200u
#define SAF_DMA_HRSL_HRS9_SHIFT                     9u
#define SAF_DMA_HRSL_HRS9_WIDTH                     1u
#define SAF_DMA_HRSL_HRS9(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS9_SHIFT))&SAF_DMA_HRSL_HRS9_MASK)
#define SAF_DMA_HRSL_HRS10_MASK                     0x400u
#define SAF_DMA_HRSL_HRS10_SHIFT                    10u
#define SAF_DMA_HRSL_HRS10_WIDTH                    1u
#define SAF_DMA_HRSL_HRS10(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS10_SHIFT))&SAF_DMA_HRSL_HRS10_MASK)
#define SAF_DMA_HRSL_HRS11_MASK                     0x800u
#define SAF_DMA_HRSL_HRS11_SHIFT                    11u
#define SAF_DMA_HRSL_HRS11_WIDTH                    1u
#define SAF_DMA_HRSL_HRS11(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS11_SHIFT))&SAF_DMA_HRSL_HRS11_MASK)
#define SAF_DMA_HRSL_HRS12_MASK                     0x1000u
#define SAF_DMA_HRSL_HRS12_SHIFT                    12u
#define SAF_DMA_HRSL_HRS12_WIDTH                    1u
#define SAF_DMA_HRSL_HRS12(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS12_SHIFT))&SAF_DMA_HRSL_HRS12_MASK)
#define SAF_DMA_HRSL_HRS13_MASK                     0x2000u
#define SAF_DMA_HRSL_HRS13_SHIFT                    13u
#define SAF_DMA_HRSL_HRS13_WIDTH                    1u
#define SAF_DMA_HRSL_HRS13(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS13_SHIFT))&SAF_DMA_HRSL_HRS13_MASK)
#define SAF_DMA_HRSL_HRS14_MASK                     0x4000u
#define SAF_DMA_HRSL_HRS14_SHIFT                    14u
#define SAF_DMA_HRSL_HRS14_WIDTH                    1u
#define SAF_DMA_HRSL_HRS14(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS14_SHIFT))&SAF_DMA_HRSL_HRS14_MASK)
#define SAF_DMA_HRSL_HRS15_MASK                     0x8000u
#define SAF_DMA_HRSL_HRS15_SHIFT                    15u
#define SAF_DMA_HRSL_HRS15_WIDTH                    1u
#define SAF_DMA_HRSL_HRS15(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS15_SHIFT))&SAF_DMA_HRSL_HRS15_MASK)
#define SAF_DMA_HRSL_HRS16_MASK                     0x10000u
#define SAF_DMA_HRSL_HRS16_SHIFT                    16u
#define SAF_DMA_HRSL_HRS16_WIDTH                    1u
#define SAF_DMA_HRSL_HRS16(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS16_SHIFT))&SAF_DMA_HRSL_HRS16_MASK)
#define SAF_DMA_HRSL_HRS17_MASK                     0x20000u
#define SAF_DMA_HRSL_HRS17_SHIFT                    17u
#define SAF_DMA_HRSL_HRS17_WIDTH                    1u
#define SAF_DMA_HRSL_HRS17(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS17_SHIFT))&SAF_DMA_HRSL_HRS17_MASK)
#define SAF_DMA_HRSL_HRS18_MASK                     0x40000u
#define SAF_DMA_HRSL_HRS18_SHIFT                    18u
#define SAF_DMA_HRSL_HRS18_WIDTH                    1u
#define SAF_DMA_HRSL_HRS18(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS18_SHIFT))&SAF_DMA_HRSL_HRS18_MASK)
#define SAF_DMA_HRSL_HRS19_MASK                     0x80000u
#define SAF_DMA_HRSL_HRS19_SHIFT                    19u
#define SAF_DMA_HRSL_HRS19_WIDTH                    1u
#define SAF_DMA_HRSL_HRS19(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS19_SHIFT))&SAF_DMA_HRSL_HRS19_MASK)
#define SAF_DMA_HRSL_HRS20_MASK                     0x100000u
#define SAF_DMA_HRSL_HRS20_SHIFT                    20u
#define SAF_DMA_HRSL_HRS20_WIDTH                    1u
#define SAF_DMA_HRSL_HRS20(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS20_SHIFT))&SAF_DMA_HRSL_HRS20_MASK)
#define SAF_DMA_HRSL_HRS21_MASK                     0x200000u
#define SAF_DMA_HRSL_HRS21_SHIFT                    21u
#define SAF_DMA_HRSL_HRS21_WIDTH                    1u
#define SAF_DMA_HRSL_HRS21(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS21_SHIFT))&SAF_DMA_HRSL_HRS21_MASK)
#define SAF_DMA_HRSL_HRS22_MASK                     0x400000u
#define SAF_DMA_HRSL_HRS22_SHIFT                    22u
#define SAF_DMA_HRSL_HRS22_WIDTH                    1u
#define SAF_DMA_HRSL_HRS22(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS22_SHIFT))&SAF_DMA_HRSL_HRS22_MASK)
#define SAF_DMA_HRSL_HRS23_MASK                     0x800000u
#define SAF_DMA_HRSL_HRS23_SHIFT                    23u
#define SAF_DMA_HRSL_HRS23_WIDTH                    1u
#define SAF_DMA_HRSL_HRS23(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS23_SHIFT))&SAF_DMA_HRSL_HRS23_MASK)
#define SAF_DMA_HRSL_HRS24_MASK                     0x1000000u
#define SAF_DMA_HRSL_HRS24_SHIFT                    24u
#define SAF_DMA_HRSL_HRS24_WIDTH                    1u
#define SAF_DMA_HRSL_HRS24(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS24_SHIFT))&SAF_DMA_HRSL_HRS24_MASK)
#define SAF_DMA_HRSL_HRS25_MASK                     0x2000000u
#define SAF_DMA_HRSL_HRS25_SHIFT                    25u
#define SAF_DMA_HRSL_HRS25_WIDTH                    1u
#define SAF_DMA_HRSL_HRS25(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS25_SHIFT))&SAF_DMA_HRSL_HRS25_MASK)
#define SAF_DMA_HRSL_HRS26_MASK                     0x4000000u
#define SAF_DMA_HRSL_HRS26_SHIFT                    26u
#define SAF_DMA_HRSL_HRS26_WIDTH                    1u
#define SAF_DMA_HRSL_HRS26(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS26_SHIFT))&SAF_DMA_HRSL_HRS26_MASK)
#define SAF_DMA_HRSL_HRS27_MASK                     0x8000000u
#define SAF_DMA_HRSL_HRS27_SHIFT                    27u
#define SAF_DMA_HRSL_HRS27_WIDTH                    1u
#define SAF_DMA_HRSL_HRS27(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS27_SHIFT))&SAF_DMA_HRSL_HRS27_MASK)
#define SAF_DMA_HRSL_HRS28_MASK                     0x10000000u
#define SAF_DMA_HRSL_HRS28_SHIFT                    28u
#define SAF_DMA_HRSL_HRS28_WIDTH                    1u
#define SAF_DMA_HRSL_HRS28(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS28_SHIFT))&SAF_DMA_HRSL_HRS28_MASK)
#define SAF_DMA_HRSL_HRS29_MASK                     0x20000000u
#define SAF_DMA_HRSL_HRS29_SHIFT                    29u
#define SAF_DMA_HRSL_HRS29_WIDTH                    1u
#define SAF_DMA_HRSL_HRS29(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS29_SHIFT))&SAF_DMA_HRSL_HRS29_MASK)
#define SAF_DMA_HRSL_HRS30_MASK                     0x40000000u
#define SAF_DMA_HRSL_HRS30_SHIFT                    30u
#define SAF_DMA_HRSL_HRS30_WIDTH                    1u
#define SAF_DMA_HRSL_HRS30(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS30_SHIFT))&SAF_DMA_HRSL_HRS30_MASK)
#define SAF_DMA_HRSL_HRS31_MASK                     0x80000000u
#define SAF_DMA_HRSL_HRS31_SHIFT                    31u
#define SAF_DMA_HRSL_HRS31_WIDTH                    1u
#define SAF_DMA_HRSL_HRS31(x)                       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_HRSL_HRS31_SHIFT))&SAF_DMA_HRSL_HRS31_MASK)
/* GPOR Bit Fields */
#define SAF_DMA_GPOR_GPOR_MASK                      0xFFFFFFFFu
#define SAF_DMA_GPOR_GPOR_SHIFT                     0u
#define SAF_DMA_GPOR_GPOR_WIDTH                     32u
#define SAF_DMA_GPOR_GPOR(x)                        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_GPOR_GPOR_SHIFT))&SAF_DMA_GPOR_GPOR_MASK)
/* DCHPRI Bit Fields */
#define SAF_DMA_DCHPRI_CHPRI_MASK                   0xFu
#define SAF_DMA_DCHPRI_CHPRI_SHIFT                  0u
#define SAF_DMA_DCHPRI_CHPRI_WIDTH                  4u
#define SAF_DMA_DCHPRI_CHPRI(x)                     (((uint8_t)(((uint8_t)(x)) << SAF_DMA_DCHPRI_CHPRI_SHIFT))&SAF_DMA_DCHPRI_CHPRI_MASK)
#define SAF_DMA_DCHPRI_GRPPRI_MASK                  0x30u
#define SAF_DMA_DCHPRI_GRPPRI_SHIFT                 4u
#define SAF_DMA_DCHPRI_GRPPRI_WIDTH                 2u
#define SAF_DMA_DCHPRI_GRPPRI(x)                    (((uint8_t)(((uint8_t)(x)) << SAF_DMA_DCHPRI_GRPPRI_SHIFT))&SAF_DMA_DCHPRI_GRPPRI_MASK)
#define SAF_DMA_DCHPRI_DPA_MASK                     0x40u
#define SAF_DMA_DCHPRI_DPA_SHIFT                    6u
#define SAF_DMA_DCHPRI_DPA_WIDTH                    1u
#define SAF_DMA_DCHPRI_DPA(x)                       (((uint8_t)(((uint8_t)(x)) << SAF_DMA_DCHPRI_DPA_SHIFT))&SAF_DMA_DCHPRI_DPA_MASK)
#define SAF_DMA_DCHPRI_ECP_MASK                     0x80u
#define SAF_DMA_DCHPRI_ECP_SHIFT                    7u
#define SAF_DMA_DCHPRI_ECP_WIDTH                    1u
#define SAF_DMA_DCHPRI_ECP(x)                       (((uint8_t)(((uint8_t)(x)) << SAF_DMA_DCHPRI_ECP_SHIFT))&SAF_DMA_DCHPRI_ECP_MASK)
/* TCD_SADDR Bit Fields */
#define SAF_DMA_TCD_SADDR_SADDR_MASK                0xFFFFFFFFu
#define SAF_DMA_TCD_SADDR_SADDR_SHIFT               0u
#define SAF_DMA_TCD_SADDR_SADDR_WIDTH               32u
#define SAF_DMA_TCD_SADDR_SADDR(x)                  (((uint32_t)(((uint32_t)(x)) << SAF_DMA_TCD_SADDR_SADDR_SHIFT))&SAF_DMA_TCD_SADDR_SADDR_MASK)
/* TCD_ATTR Bit Fields */
#define SAF_DMA_TCD_ATTR_DSIZE_MASK                 0x7u
#define SAF_DMA_TCD_ATTR_DSIZE_SHIFT                0u
#define SAF_DMA_TCD_ATTR_DSIZE_WIDTH                3u
#define SAF_DMA_TCD_ATTR_DSIZE(x)                   (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_ATTR_DSIZE_SHIFT))&SAF_DMA_TCD_ATTR_DSIZE_MASK)
#define SAF_DMA_TCD_ATTR_DMOD_MASK                  0xF8u
#define SAF_DMA_TCD_ATTR_DMOD_SHIFT                 3u
#define SAF_DMA_TCD_ATTR_DMOD_WIDTH                 5u
#define SAF_DMA_TCD_ATTR_DMOD(x)                    (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_ATTR_DMOD_SHIFT))&SAF_DMA_TCD_ATTR_DMOD_MASK)
#define SAF_DMA_TCD_ATTR_SSIZE_MASK                 0x700u
#define SAF_DMA_TCD_ATTR_SSIZE_SHIFT                8u
#define SAF_DMA_TCD_ATTR_SSIZE_WIDTH                3u
#define SAF_DMA_TCD_ATTR_SSIZE(x)                   (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_ATTR_SSIZE_SHIFT))&SAF_DMA_TCD_ATTR_SSIZE_MASK)
#define SAF_DMA_TCD_ATTR_SMOD_MASK                  0xF800u
#define SAF_DMA_TCD_ATTR_SMOD_SHIFT                 11u
#define SAF_DMA_TCD_ATTR_SMOD_WIDTH                 5u
#define SAF_DMA_TCD_ATTR_SMOD(x)                    (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_ATTR_SMOD_SHIFT))&SAF_DMA_TCD_ATTR_SMOD_MASK)
/* TCD_SOFF Bit Fields */
#define SAF_DMA_TCD_SOFF_SOFF_MASK                  0xFFFFu
#define SAF_DMA_TCD_SOFF_SOFF_SHIFT                 0u
#define SAF_DMA_TCD_SOFF_SOFF_WIDTH                 16u
#define SAF_DMA_TCD_SOFF_SOFF(x)                    (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_SOFF_SOFF_SHIFT))&SAF_DMA_TCD_SOFF_SOFF_MASK)
/* TCD_NBYTES_MLNO Bit Fields */
#define SAF_DMA_TCD_NBYTES_MLNO_NBYTES_MASK         0xFFFFFFFFu
#define SAF_DMA_TCD_NBYTES_MLNO_NBYTES_SHIFT        0u
#define SAF_DMA_TCD_NBYTES_MLNO_NBYTES_WIDTH        32u
#define SAF_DMA_TCD_NBYTES_MLNO_NBYTES(x)           (((uint32_t)(((uint32_t)(x)) << SAF_DMA_TCD_NBYTES_MLNO_NBYTES_SHIFT))&SAF_DMA_TCD_NBYTES_MLNO_NBYTES_MASK)
/* TCD_NBYTES_MLOFFNO Bit Fields */
#define SAF_DMA_TCD_NBYTES_MLOFFNO_NBYTES_MASK      0x3FFFFFFFu
#define SAF_DMA_TCD_NBYTES_MLOFFNO_NBYTES_SHIFT     0u
#define SAF_DMA_TCD_NBYTES_MLOFFNO_NBYTES_WIDTH     30u
#define SAF_DMA_TCD_NBYTES_MLOFFNO_NBYTES(x)        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_TCD_NBYTES_MLOFFNO_NBYTES_SHIFT))&SAF_DMA_TCD_NBYTES_MLOFFNO_NBYTES_MASK)
#define SAF_DMA_TCD_NBYTES_MLOFFNO_DMLOE_MASK       0x40000000u
#define SAF_DMA_TCD_NBYTES_MLOFFNO_DMLOE_SHIFT      30u
#define SAF_DMA_TCD_NBYTES_MLOFFNO_DMLOE_WIDTH      1u
#define SAF_DMA_TCD_NBYTES_MLOFFNO_DMLOE(x)         (((uint32_t)(((uint32_t)(x)) << SAF_DMA_TCD_NBYTES_MLOFFNO_DMLOE_SHIFT))&SAF_DMA_TCD_NBYTES_MLOFFNO_DMLOE_MASK)
#define SAF_DMA_TCD_NBYTES_MLOFFNO_SMLOE_MASK       0x80000000u
#define SAF_DMA_TCD_NBYTES_MLOFFNO_SMLOE_SHIFT      31u
#define SAF_DMA_TCD_NBYTES_MLOFFNO_SMLOE_WIDTH      1u
#define SAF_DMA_TCD_NBYTES_MLOFFNO_SMLOE(x)         (((uint32_t)(((uint32_t)(x)) << SAF_DMA_TCD_NBYTES_MLOFFNO_SMLOE_SHIFT))&SAF_DMA_TCD_NBYTES_MLOFFNO_SMLOE_MASK)
/* TCD_NBYTES_MLOFFYES Bit Fields */
#define SAF_DMA_TCD_NBYTES_MLOFFYES_NBYTES_MASK     0x3FFu
#define SAF_DMA_TCD_NBYTES_MLOFFYES_NBYTES_SHIFT    0u  /* PRQA S 0791 */
#define SAF_DMA_TCD_NBYTES_MLOFFYES_NBYTES_WIDTH    10u /* PRQA S 0791 */
#define SAF_DMA_TCD_NBYTES_MLOFFYES_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << SAF_DMA_TCD_NBYTES_MLOFFYES_NBYTES_SHIFT))&SAF_DMA_TCD_NBYTES_MLOFFYES_NBYTES_MASK)
#define SAF_DMA_TCD_NBYTES_MLOFFYES_MLOFF_MASK      0x3FFFFC00u
#define SAF_DMA_TCD_NBYTES_MLOFFYES_MLOFF_SHIFT     10u
#define SAF_DMA_TCD_NBYTES_MLOFFYES_MLOFF_WIDTH     20u
#define SAF_DMA_TCD_NBYTES_MLOFFYES_MLOFF(x)        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_TCD_NBYTES_MLOFFYES_MLOFF_SHIFT))&SAF_DMA_TCD_NBYTES_MLOFFYES_MLOFF_MASK)
#define SAF_DMA_TCD_NBYTES_MLOFFYES_DMLOE_MASK      0x40000000u
#define SAF_DMA_TCD_NBYTES_MLOFFYES_DMLOE_SHIFT     30u
#define SAF_DMA_TCD_NBYTES_MLOFFYES_DMLOE_WIDTH     1u
#define SAF_DMA_TCD_NBYTES_MLOFFYES_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_TCD_NBYTES_MLOFFYES_DMLOE_SHIFT))&SAF_DMA_TCD_NBYTES_MLOFFYES_DMLOE_MASK)
#define SAF_DMA_TCD_NBYTES_MLOFFYES_SMLOE_MASK      0x80000000u
#define SAF_DMA_TCD_NBYTES_MLOFFYES_SMLOE_SHIFT     31u
#define SAF_DMA_TCD_NBYTES_MLOFFYES_SMLOE_WIDTH     1u
#define SAF_DMA_TCD_NBYTES_MLOFFYES_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << SAF_DMA_TCD_NBYTES_MLOFFYES_SMLOE_SHIFT))&SAF_DMA_TCD_NBYTES_MLOFFYES_SMLOE_MASK)
/* TCD_SLAST Bit Fields */
#define SAF_DMA_TCD_SLAST_SLAST_MASK                0xFFFFFFFFu
#define SAF_DMA_TCD_SLAST_SLAST_SHIFT               0u
#define SAF_DMA_TCD_SLAST_SLAST_WIDTH               32u
#define SAF_DMA_TCD_SLAST_SLAST(x)                  (((uint32_t)(((uint32_t)(x)) << SAF_DMA_TCD_SLAST_SLAST_SHIFT))&SAF_DMA_TCD_SLAST_SLAST_MASK)
/* TCD_DADDR Bit Fields */
#define SAF_DMA_TCD_DADDR_DADDR_MASK                0xFFFFFFFFu
#define SAF_DMA_TCD_DADDR_DADDR_SHIFT               0u
#define SAF_DMA_TCD_DADDR_DADDR_WIDTH               32u
#define SAF_DMA_TCD_DADDR_DADDR(x)                  (((uint32_t)(((uint32_t)(x)) << SAF_DMA_TCD_DADDR_DADDR_SHIFT))&SAF_DMA_TCD_DADDR_DADDR_MASK)
/* TCD_CITER_ELINKNO Bit Fields */
#define SAF_DMA_TCD_CITER_ELINKNO_CITER_MASK        0x7FFFu
#define SAF_DMA_TCD_CITER_ELINKNO_CITER_SHIFT       0u
#define SAF_DMA_TCD_CITER_ELINKNO_CITER_WIDTH       15u
#define SAF_DMA_TCD_CITER_ELINKNO_CITER(x)          (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_CITER_ELINKNO_CITER_SHIFT))&SAF_DMA_TCD_CITER_ELINKNO_CITER_MASK)
#define SAF_DMA_TCD_CITER_ELINKNO_ELINK_MASK        0x8000u
#define SAF_DMA_TCD_CITER_ELINKNO_ELINK_SHIFT       15u
#define SAF_DMA_TCD_CITER_ELINKNO_ELINK_WIDTH       1u
#define SAF_DMA_TCD_CITER_ELINKNO_ELINK(x)          (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_CITER_ELINKNO_ELINK_SHIFT))&SAF_DMA_TCD_CITER_ELINKNO_ELINK_MASK)
/* TCD_CITER_ELINKYES Bit Fields */
#define SAF_DMA_TCD_CITER_ELINKYES_CITER_MASK       0x1FFu
#define SAF_DMA_TCD_CITER_ELINKYES_CITER_SHIFT      0u
#define SAF_DMA_TCD_CITER_ELINKYES_CITER_WIDTH      9u
#define SAF_DMA_TCD_CITER_ELINKYES_CITER(x)         (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_CITER_ELINKYES_CITER_SHIFT))&SAF_DMA_TCD_CITER_ELINKYES_CITER_MASK)
#define SAF_DMA_TCD_CITER_ELINKYES_LINKCH_MASK      0x7E00u
#define SAF_DMA_TCD_CITER_ELINKYES_LINKCH_SHIFT     9u
#define SAF_DMA_TCD_CITER_ELINKYES_LINKCH_WIDTH     6u
#define SAF_DMA_TCD_CITER_ELINKYES_LINKCH(x)        (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_CITER_ELINKYES_LINKCH_SHIFT))&SAF_DMA_TCD_CITER_ELINKYES_LINKCH_MASK)
#define SAF_DMA_TCD_CITER_ELINKYES_ELINK_MASK       0x8000u
#define SAF_DMA_TCD_CITER_ELINKYES_ELINK_SHIFT      15u
#define SAF_DMA_TCD_CITER_ELINKYES_ELINK_WIDTH      1u
#define SAF_DMA_TCD_CITER_ELINKYES_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_CITER_ELINKYES_ELINK_SHIFT))&SAF_DMA_TCD_CITER_ELINKYES_ELINK_MASK)
/* TCD_DOFF Bit Fields */
#define SAF_DMA_TCD_DOFF_DOFF_MASK                  0xFFFFu
#define SAF_DMA_TCD_DOFF_DOFF_SHIFT                 0u
#define SAF_DMA_TCD_DOFF_DOFF_WIDTH                 16u
#define SAF_DMA_TCD_DOFF_DOFF(x)                    (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_DOFF_DOFF_SHIFT))&SAF_DMA_TCD_DOFF_DOFF_MASK)
/* TCD_DLASTSGA Bit Fields */
#define SAF_DMA_TCD_DLASTSGA_DLASTSGA_MASK          0xFFFFFFFFu
#define SAF_DMA_TCD_DLASTSGA_DLASTSGA_SHIFT         0u
#define SAF_DMA_TCD_DLASTSGA_DLASTSGA_WIDTH         32u
#define SAF_DMA_TCD_DLASTSGA_DLASTSGA(x)            (((uint32_t)(((uint32_t)(x)) << SAF_DMA_TCD_DLASTSGA_DLASTSGA_SHIFT))&SAF_DMA_TCD_DLASTSGA_DLASTSGA_MASK)
/* TCD_BITER_ELINKNO Bit Fields */
#define SAF_DMA_TCD_BITER_ELINKNO_BITER_MASK        0x7FFFu
#define SAF_DMA_TCD_BITER_ELINKNO_BITER_SHIFT       0u
#define SAF_DMA_TCD_BITER_ELINKNO_BITER_WIDTH       15u
#define SAF_DMA_TCD_BITER_ELINKNO_BITER(x)          (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_BITER_ELINKNO_BITER_SHIFT))&SAF_DMA_TCD_BITER_ELINKNO_BITER_MASK)
#define SAF_DMA_TCD_BITER_ELINKNO_ELINK_MASK        0x8000u
#define SAF_DMA_TCD_BITER_ELINKNO_ELINK_SHIFT       15u
#define SAF_DMA_TCD_BITER_ELINKNO_ELINK_WIDTH       1u
#define SAF_DMA_TCD_BITER_ELINKNO_ELINK(x)          (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_BITER_ELINKNO_ELINK_SHIFT))&SAF_DMA_TCD_BITER_ELINKNO_ELINK_MASK)
/* TCD_BITER_ELINKYES Bit Fields */
#define SAF_DMA_TCD_BITER_ELINKYES_BITER_MASK       0x1FFu
#define SAF_DMA_TCD_BITER_ELINKYES_BITER_SHIFT      0u
#define SAF_DMA_TCD_BITER_ELINKYES_BITER_WIDTH      9u
#define SAF_DMA_TCD_BITER_ELINKYES_BITER(x)         (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_BITER_ELINKYES_BITER_SHIFT))&SAF_DMA_TCD_BITER_ELINKYES_BITER_MASK)
#define SAF_DMA_TCD_BITER_ELINKYES_LINKCH_MASK      0x7E00u
#define SAF_DMA_TCD_BITER_ELINKYES_LINKCH_SHIFT     9u
#define SAF_DMA_TCD_BITER_ELINKYES_LINKCH_WIDTH     6u
#define SAF_DMA_TCD_BITER_ELINKYES_LINKCH(x)        (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_BITER_ELINKYES_LINKCH_SHIFT))&SAF_DMA_TCD_BITER_ELINKYES_LINKCH_MASK)
#define SAF_DMA_TCD_BITER_ELINKYES_ELINK_MASK       0x8000u
#define SAF_DMA_TCD_BITER_ELINKYES_ELINK_SHIFT      15u
#define SAF_DMA_TCD_BITER_ELINKYES_ELINK_WIDTH      1u
#define SAF_DMA_TCD_BITER_ELINKYES_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_BITER_ELINKYES_ELINK_SHIFT))&SAF_DMA_TCD_BITER_ELINKYES_ELINK_MASK)
/* TCD_CSR Bit Fields */
#define SAF_DMA_TCD_CSR_START_MASK                  0x1u
#define SAF_DMA_TCD_CSR_START_SHIFT                 0u
#define SAF_DMA_TCD_CSR_START_WIDTH                 1u
#define SAF_DMA_TCD_CSR_START(x)                    (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_CSR_START_SHIFT))&SAF_DMA_TCD_CSR_START_MASK)
#define SAF_DMA_TCD_CSR_INTMAJOR_MASK               0x2u
#define SAF_DMA_TCD_CSR_INTMAJOR_SHIFT              1u
#define SAF_DMA_TCD_CSR_INTMAJOR_WIDTH              1u
#define SAF_DMA_TCD_CSR_INTMAJOR(x)                 (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_CSR_INTMAJOR_SHIFT))&SAF_DMA_TCD_CSR_INTMAJOR_MASK)
#define SAF_DMA_TCD_CSR_INTHALF_MASK                0x4u
#define SAF_DMA_TCD_CSR_INTHALF_SHIFT               2u
#define SAF_DMA_TCD_CSR_INTHALF_WIDTH               1u
#define SAF_DMA_TCD_CSR_INTHALF(x)                  (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_CSR_INTHALF_SHIFT))&SAF_DMA_TCD_CSR_INTHALF_MASK)
#define SAF_DMA_TCD_CSR_DREQ_MASK                   0x8u
#define SAF_DMA_TCD_CSR_DREQ_SHIFT                  3u
#define SAF_DMA_TCD_CSR_DREQ_WIDTH                  1u
#define SAF_DMA_TCD_CSR_DREQ(x)                     (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_CSR_DREQ_SHIFT))&SAF_DMA_TCD_CSR_DREQ_MASK)
#define SAF_DMA_TCD_CSR_ESG_MASK                    0x10u
#define SAF_DMA_TCD_CSR_ESG_SHIFT                   4u
#define SAF_DMA_TCD_CSR_ESG_WIDTH                   1u
#define SAF_DMA_TCD_CSR_ESG(x)                      (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_CSR_ESG_SHIFT))&SAF_DMA_TCD_CSR_ESG_MASK)
#define SAF_DMA_TCD_CSR_MAJORELINK_MASK             0x20u
#define SAF_DMA_TCD_CSR_MAJORELINK_SHIFT            5u
#define SAF_DMA_TCD_CSR_MAJORELINK_WIDTH            1u
#define SAF_DMA_TCD_CSR_MAJORELINK(x)               (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_CSR_MAJORELINK_SHIFT))&SAF_DMA_TCD_CSR_MAJORELINK_MASK)
#define SAF_DMA_TCD_CSR_ACTIVE_MASK                 0x40u
#define SAF_DMA_TCD_CSR_ACTIVE_SHIFT                6u
#define SAF_DMA_TCD_CSR_ACTIVE_WIDTH                1u
#define SAF_DMA_TCD_CSR_ACTIVE(x)                   (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_CSR_ACTIVE_SHIFT))&SAF_DMA_TCD_CSR_ACTIVE_MASK)
#define SAF_DMA_TCD_CSR_DONE_MASK                   0x80u
#define SAF_DMA_TCD_CSR_DONE_SHIFT                  7u
#define SAF_DMA_TCD_CSR_DONE_WIDTH                  1u
#define SAF_DMA_TCD_CSR_DONE(x)                     (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_CSR_DONE_SHIFT))&SAF_DMA_TCD_CSR_DONE_MASK)
#define SAF_DMA_TCD_CSR_MAJORLINKCH_MASK            0x3F00u
#define SAF_DMA_TCD_CSR_MAJORLINKCH_SHIFT           8u
#define SAF_DMA_TCD_CSR_MAJORLINKCH_WIDTH           6u
#define SAF_DMA_TCD_CSR_MAJORLINKCH(x)              (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_CSR_MAJORLINKCH_SHIFT))&SAF_DMA_TCD_CSR_MAJORLINKCH_MASK)
#define SAF_DMA_TCD_CSR_BWC_MASK                    0xC000u
#define SAF_DMA_TCD_CSR_BWC_SHIFT                   14u
#define SAF_DMA_TCD_CSR_BWC_WIDTH                   2u
#define SAF_DMA_TCD_CSR_BWC(x)                      (((uint16_t)(((uint16_t)(x)) << SAF_DMA_TCD_CSR_BWC_SHIFT))&SAF_DMA_TCD_CSR_BWC_MASK)

#define SAF_DMAMUX_CHANNEL_COUNT                    (16u)

typedef struct
{
    volatile uint8_t CHCFG[SAF_DMAMUX_CHANNEL_COUNT];   /** Control Register, offset: 0x0 */
} SAF_DMAMUX_Type, *SAF_DMAMUX_MemMapPtr; /* PRQA S 1535 */

#define SAF_DMAMUX_INSTANCE_COUNT                   (10u)

#define SAF_DMAMUX_0_BASE                           (0xFFF6C000UL)
#define SAF_DMAMUX_1_BASE                           (0xFFF6C200UL)
#define SAF_DMAMUX_2_BASE                           (0xFFF6C400UL)
#define SAF_DMAMUX_3_BASE                           (0xFFF6C600UL)
#define SAF_DMAMUX_4_BASE                           (0xFFF6C800UL)
#define SAF_DMAMUX_5_BASE                           (0xFFF6CA00UL)
#define SAF_DMAMUX_6_BASE                           (0xFFF6CC00UL)
#define SAF_DMAMUX_7_BASE                           (0xFFF6CE00UL)
#define SAF_DMAMUX_8_BASE                           (0xFFF6D000UL)
#define SAF_DMAMUX_9_BASE                           (0xFFF6D200UL)

/** Peripheral SAF_DMAMUX_0~9 base pointer */
#define SAF_DMAMUX0_P                               ((SAF_DMAMUX_Type *)SAF_DMAMUX_0_BASE)
#define SAF_DMAMUX1_P                               ((SAF_DMAMUX_Type *)SAF_DMAMUX_1_BASE)
#define SAF_DMAMUX2_P                               ((SAF_DMAMUX_Type *)SAF_DMAMUX_2_BASE)
#define SAF_DMAMUX3_P                               ((SAF_DMAMUX_Type *)SAF_DMAMUX_3_BASE)
#define SAF_DMAMUX4_P                               ((SAF_DMAMUX_Type *)SAF_DMAMUX_4_BASE)
#define SAF_DMAMUX5_P                               ((SAF_DMAMUX_Type *)SAF_DMAMUX_5_BASE)
#define SAF_DMAMUX6_P                               ((SAF_DMAMUX_Type *)SAF_DMAMUX_6_BASE)
#define SAF_DMAMUX7_P                               ((SAF_DMAMUX_Type *)SAF_DMAMUX_7_BASE)
#define SAF_DMAMUX8_P                               ((SAF_DMAMUX_Type *)SAF_DMAMUX_8_BASE)
#define SAF_DMAMUX9_P                               ((SAF_DMAMUX_Type *)SAF_DMAMUX_9_BASE)

#define SAF_DMAMUX_BASE_PTRS                        { SAF_DMAMUX0_P, SAF_DMAMUX1_P, SAF_DMAMUX2_P, SAF_DMAMUX3_P, SAF_DMAMUX4_P, SAF_DMAMUX5_P, SAF_DMAMUX6_P, SAF_DMAMUX7_P, SAF_DMAMUX8_P, SAF_DMAMUX9_P }

#define SAF_DMAMUX_CHCFG_ENBL_SHIFT                 7U
#define SAF_DMAMUX_CHCFG_ENBL_MASK                  0x80U
#define SAF_DMAMUX_CHCFG_SOURCE_SHIFT               0U
#define SAF_DMAMUX_CHCFG_SOURCE_MASK                0x3FU
#define SAF_DMAMUX_CHCFG_TRIG_SHIFT                 6U
#define SAF_DMAMUX_CHCFG_TRIG_MASK                  0x40U

status_t SAF_EDMA_LLD_SetUpCallback(uint8_t mappedChannel,
                                SafeDMACallbackType callback,
                                void *parameter);
void SAF_EDMA_HW_ClearIntStatus(uint8_t mappedChannel);
void SAF_EDMA_LLD_SwRequestTriggerEn(uint8_t mappedChannel);
status_t SAF_EDMA_LLD_SetChannelSourceConfig(uint8_t mappedChannel,
                                              uint32_t request,
                                              boolean triggerEn);
status_t SAF_EDMA_LLD_ChannelInit(SafeDMAChnStateType *eedma_channelState, const SafeDMAChanConfigType *eedma_channelConfig);
status_t SAF_EDMA_LLD_ModuleInit(safedma_state_t *edmaState,
                             const SafeDMAModuleConfigType *userConfig,
                             SafeDMAChnStateType * const chnStateArray[],
                             const SafeDMAChanConfigType * const chnConfigArray[],
                             uint32_t chnCount);
void SAF_EDMA_LLD_ClearSwTCDStruct(SafeDMASwTcdType *swtcd);

status_t SAF_EDMA_LLD_SetSingleTransferConfig(uint8_t mappedChannel,
                                          SafeDMATransferType type,
                                          uint32_t srcAddr,
                                          uint32_t destAddr,
                                          SafeDMATransferSizeType transferSize,
                                          uint32_t dataBufferSize);

status_t SAF_EDMA_LLD_SetMultiTransferConfig(uint8_t mappedChannel,
                                         SafeDMATransferType type,
                                         uint32_t srcAddr,
                                         uint32_t destAddr,
                                         SafeDMATransferSizeType transferSize,
                                         uint32_t blockSize,
                                         uint32_t blockCount,
                                         boolean disableReqOnCompletion);

status_t SAF_EDMA_LLD_SetLoopTransferConfig(uint8_t mappedChannel,
                                     const SafeDMATransferConfigType *transferConfig);

void SAF_EDMA_LLD_CopyConfigToSwTCD(const SafeDMATransferConfigType *config,
                                SafeDMASwTcdType *stcd);
status_t SAF_EDMA_LLD_SetScatterGatherTransferConfig(uint8_t mappedChannel,
                                                 const SafeDMASwTcdType *stcd,
                                                 SafeDMATransferSizeType transferSize,
                                                 uint32_t bytesOnEachRequest,
                                                 const SafeDMAScatterGatherListType *srcList,
                                                 const SafeDMAScatterGatherListType *destList,
                                                 uint8_t tcdCount);
status_t SAF_EDMA_LLD_SetChannelRequest(uint8_t mappedChannel);
status_t SAF_EDMA_LLD_ClearChannelRequest(uint8_t mappedChannel);
void SAF_EDMA_LLD_ClearHwTCD(uint8_t mappedChannel);
void SAF_EDMA_LLD_SetChnSrcAddr(uint8_t mappedChannel,
                            uint32_t address);
void SAF_EDMA_LLD_SetChnSrcAddrOffset(uint8_t mappedChannel,
                                  int16_t offset);
void SAF_EDMA_LLD_SetChnSrcAddrReadTransferSize(uint8_t mappedChannel,
                                            SafeDMATransferSizeType size);
void SAF_EDMA_LLD_SetChnSrcAddrLastAdjustment(uint8_t mappedChannel,
                                          int32_t adjust);
void SAF_EDMA_LLD_SetChnDestAddrLastAdjustment(uint8_t mappedChannel,
                                           int32_t adjust);
void SAF_EDMA_LLD_SetChnDestAddr(uint8_t mappedChannel,
                             uint32_t address);
void SAF_EDMA_LLD_SetChnDestAddrOffset(uint8_t mappedChannel,
                                   int16_t offset);
void SAF_EDMA_LLD_SetChnDestdrWriteTransferSize(uint8_t mappedChannel,
                                            SafeDMATransferSizeType size);
void SAF_EDMA_LLD_SetChnMinorLpTransferByte(uint8_t mappedChannel,
                                        uint32_t nbytes);
void SAF_EDMA_LLD_SetChnMajorLpIterationCount(uint8_t mappedChannel,
                                          uint32_t majorLoopCount);
uint32_t SAF_EDMA_LLD_GetChnRemainingIterationsCount(uint8_t mappedChannel);
void SAF_EDMA_LLD_SetChnScatterGatherLinkMode(uint8_t mappedChannel,
                                          uint32_t nextTCDAddr);
void SAF_EDMA_LLD_SetChnDisRequestsOnTransferComplete(uint8_t mappedChannel,
                                                  boolean disable);
void SAF_EDMA_LLD_SetInterruptConfig(uint8_t mappedChannel,
                                 SafeDMAChannelInterruptType intSrc,
                                 boolean enable);
void SAF_EDMA_LLD_CancelExcutingChnTransfer(boolean error);
void SAF_EDMA_LLD_WaitChnTransferDone(uint8_t mappedChannel);
SafeDMAChnStatusType SAF_EDMA_LLD_GetChnConfigStatus(uint8_t mappedChannel);
void SAF_EDMA_LLD_ErrorIRQHandler(uint8_t mappedChannel);

void SAF_EDMA_Ch0_Ch127_Error_IRQHandler(void);
void SAF_EDMA_Ch0_IRQHandler(void);
void SAF_EDMA_Ch1_IRQHandler(void);
void SAF_EDMA_Ch2_IRQHandler(void);
void SAF_EDMA_Ch3_IRQHandler(void);
void SAF_EDMA_Ch4_IRQHandler(void);
void SAF_EDMA_Ch5_IRQHandler(void);
void SAF_EDMA_Ch6_IRQHandler(void);
void SAF_EDMA_Ch7_IRQHandler(void);
void SAF_EDMA_Ch8_IRQHandler(void);
void SAF_EDMA_Ch9_IRQHandler(void);
void SAF_EDMA_Ch10_IRQHandler(void);
void SAF_EDMA_Ch11_IRQHandler(void);
void SAF_EDMA_Ch12_IRQHandler(void);
void SAF_EDMA_Ch13_IRQHandler(void);
void SAF_EDMA_Ch14_IRQHandler(void);
void SAF_EDMA_Ch15_IRQHandler(void);
void SAF_EDMA_Ch16_IRQHandler(void);
void SAF_EDMA_Ch17_IRQHandler(void);
void SAF_EDMA_Ch18_IRQHandler(void);
void SAF_EDMA_Ch19_IRQHandler(void);
void SAF_EDMA_Ch20_IRQHandler(void);
void SAF_EDMA_Ch21_IRQHandler(void);
void SAF_EDMA_Ch22_IRQHandler(void);
void SAF_EDMA_Ch23_IRQHandler(void);
void SAF_EDMA_Ch24_IRQHandler(void);
void SAF_EDMA_Ch25_IRQHandler(void);
void SAF_EDMA_Ch26_IRQHandler(void);
void SAF_EDMA_Ch27_IRQHandler(void);
void SAF_EDMA_Ch28_IRQHandler(void);
void SAF_EDMA_Ch29_IRQHandler(void);
void SAF_EDMA_Ch30_IRQHandler(void);
void SAF_EDMA_Ch31_IRQHandler(void);
void SAF_EDMA_Ch32_IRQHandler(void);
void SAF_EDMA_Ch33_IRQHandler(void);
void SAF_EDMA_Ch34_IRQHandler(void);
void SAF_EDMA_Ch35_IRQHandler(void);
void SAF_EDMA_Ch36_IRQHandler(void);
void SAF_EDMA_Ch37_IRQHandler(void);
void SAF_EDMA_Ch38_IRQHandler(void);
void SAF_EDMA_Ch39_IRQHandler(void);
void SAF_EDMA_Ch40_IRQHandler(void);
void SAF_EDMA_Ch41_IRQHandler(void);
void SAF_EDMA_Ch42_IRQHandler(void);
void SAF_EDMA_Ch43_IRQHandler(void);
void SAF_EDMA_Ch44_IRQHandler(void);
void SAF_EDMA_Ch45_IRQHandler(void);
void SAF_EDMA_Ch46_IRQHandler(void);
void SAF_EDMA_Ch47_IRQHandler(void);
void SAF_EDMA_Ch48_IRQHandler(void);
void SAF_EDMA_Ch49_IRQHandler(void);
void SAF_EDMA_Ch50_IRQHandler(void);
void SAF_EDMA_Ch51_IRQHandler(void);
void SAF_EDMA_Ch52_IRQHandler(void);
void SAF_EDMA_Ch53_IRQHandler(void);
void SAF_EDMA_Ch54_IRQHandler(void);
void SAF_EDMA_Ch55_IRQHandler(void);
void SAF_EDMA_Ch56_IRQHandler(void);
void SAF_EDMA_Ch57_IRQHandler(void);
void SAF_EDMA_Ch58_IRQHandler(void);
void SAF_EDMA_Ch59_IRQHandler(void);
void SAF_EDMA_Ch60_IRQHandler(void);
void SAF_EDMA_Ch61_IRQHandler(void);
void SAF_EDMA_Ch62_IRQHandler(void);
void SAF_EDMA_Ch63_IRQHandler(void);
void SAF_EDMA_Ch64_IRQHandler(void);
void SAF_EDMA_Ch65_IRQHandler(void);
void SAF_EDMA_Ch66_IRQHandler(void);
void SAF_EDMA_Ch67_IRQHandler(void);
void SAF_EDMA_Ch68_IRQHandler(void);
void SAF_EDMA_Ch69_IRQHandler(void);
void SAF_EDMA_Ch70_IRQHandler(void);
void SAF_EDMA_Ch71_IRQHandler(void);
void SAF_EDMA_Ch72_IRQHandler(void);
void SAF_EDMA_Ch73_IRQHandler(void);
void SAF_EDMA_Ch74_IRQHandler(void);
void SAF_EDMA_Ch75_IRQHandler(void);
void SAF_EDMA_Ch76_IRQHandler(void);
void SAF_EDMA_Ch77_IRQHandler(void);
void SAF_EDMA_Ch78_IRQHandler(void);
void SAF_EDMA_Ch79_IRQHandler(void);
void SAF_EDMA_Ch80_IRQHandler(void);
void SAF_EDMA_Ch81_IRQHandler(void);
void SAF_EDMA_Ch82_IRQHandler(void);
void SAF_EDMA_Ch83_IRQHandler(void);
void SAF_EDMA_Ch84_IRQHandler(void);
void SAF_EDMA_Ch85_IRQHandler(void);
void SAF_EDMA_Ch86_IRQHandler(void);
void SAF_EDMA_Ch87_IRQHandler(void);
void SAF_EDMA_Ch88_IRQHandler(void);
void SAF_EDMA_Ch89_IRQHandler(void);
void SAF_EDMA_Ch90_IRQHandler(void);
void SAF_EDMA_Ch91_IRQHandler(void);
void SAF_EDMA_Ch92_IRQHandler(void);
void SAF_EDMA_Ch93_IRQHandler(void);
void SAF_EDMA_Ch94_IRQHandler(void);
void SAF_EDMA_Ch95_IRQHandler(void);
void SAF_EDMA_Ch96_IRQHandler(void);
void SAF_EDMA_Ch97_IRQHandler(void);
void SAF_EDMA_Ch98_IRQHandler(void);
void SAF_EDMA_Ch99_IRQHandler(void);
void SAF_EDMA_Ch100_IRQHandler(void);
void SAF_EDMA_Ch101_IRQHandler(void);
void SAF_EDMA_Ch102_IRQHandler(void);
void SAF_EDMA_Ch103_IRQHandler(void);
void SAF_EDMA_Ch104_IRQHandler(void);
void SAF_EDMA_Ch105_IRQHandler(void);
void SAF_EDMA_Ch106_IRQHandler(void);
void SAF_EDMA_Ch107_IRQHandler(void);
void SAF_EDMA_Ch108_IRQHandler(void);
void SAF_EDMA_Ch109_IRQHandler(void);
void SAF_EDMA_Ch110_IRQHandler(void);
void SAF_EDMA_Ch111_IRQHandler(void);
void SAF_EDMA_Ch112_IRQHandler(void);
void SAF_EDMA_Ch113_IRQHandler(void);
void SAF_EDMA_Ch114_IRQHandler(void);
void SAF_EDMA_Ch115_IRQHandler(void);
void SAF_EDMA_Ch116_IRQHandler(void);
void SAF_EDMA_Ch117_IRQHandler(void);
void SAF_EDMA_Ch118_IRQHandler(void);
void SAF_EDMA_Ch119_IRQHandler(void);
void SAF_EDMA_Ch120_IRQHandler(void);
void SAF_EDMA_Ch121_IRQHandler(void);
void SAF_EDMA_Ch122_IRQHandler(void);
void SAF_EDMA_Ch123_IRQHandler(void);
void SAF_EDMA_Ch124_IRQHandler(void);
void SAF_EDMA_Ch125_IRQHandler(void);
void SAF_EDMA_Ch126_IRQHandler(void);
void SAF_EDMA_Ch127_IRQHandler(void);

#endif /* SAF_EDMA_LLD__H_ */

