/**
****************************************************************************************
 * @FilePath: saf_crc.h
 * @Author: CCORE
 * @Date: 2024-02-28
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: Safety crc Head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAFETY_LIB_INC_SAF_CRCTST_H_
#define SAFETY_LIB_INC_SAF_CRCTST_H_

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_common.h"
#include "saf_ccfc30xx.h"
#include "SafetyCrcTst_Cfg.h"
#include "saf_userservice_callback.h"
/*PRQA S 1536,2053,3001 EOF*/


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define CRCTST_INIT_SEEDVALUE        SAF_CRC_32_TEST_SEED
#define SAF_CRC_8_TEST_SEED          (0xffU)
#define SAF_CRC_16_TEST_SEED         (0xffffU)
#define SAF_CRC_32_TEST_SEED         (0xffffffffU)
#define PIT_TIMER_COUNT              (8U)
#define PACR_COUNT                   (8U)
#define OPACR_COUNT                  (32U)
#define ETPU_CR_COUNT                (32U)
#define SIUL2_MSCR_COUNT             (512U)
#define FLASH_PFCRD_COUNT            (32U)
#define EDMA_DCH_COUNT               (64U)
#define STM_CHANNEL_COUNT            (4U)
#define SENT_CH_COUNT                (8U)
#define FR_MBCCFR_COUNT              (128U)
#define PSI5_SFCR_COUNT              (6U)
#define SMPU_RGD_COUNT               (12U)
#define MCME_PC_COUNT                (8U)
#define MCME_RUN_COUNT               (4U)
#define SAF_CRCTST_INSTANCE_COUNT	 (2U)

#define MCME_PCTL3                   (3U)
#define MCME_PCTL9                   (9U)
#define MCME_PCTL11                  (11U)
#define MCME_PCTL15                  (15U)
#define MCME_PCTL30                  (30U)
#define MCME_PCTL31                  (31U)
#define MCME_PCTL36                  (36U)
#define MCME_PCTL38                  (38U)
#define MCME_PCTL56                  (56U)
#define MCME_PCTL57                  (57U)
#define MCME_PCTL58                  (58U)
#define MCME_PCTL59                  (59U)
#define MCME_PCTL60                  (60U)
#define MCME_PCTL67                  (67U)
#define MCME_PCTL68                  (68U)
#define MCME_PCTL69                  (69U)
#define MCME_PCTL70                  (70U)
#define MCME_PCTL72                  (72U)
#define MCME_PCTL74                  (74U)
#define MCME_PCTL84                  (84U)
#define MCME_PCTL85                  (85U)
#define MCME_PCTL91                  (91U)
#define MCME_PCTL92                  (92U)
#define MCME_PCTL93                  (93U)
#define MCME_PCTL96                  (96U)
#define MCME_PCTL97                  (97U)
#define MCME_PCTL98                  (98U)
#define MCME_PCTL99                  (99U)
#define MCME_PCTL101                 (101U)
#define MCME_PCTL104                 (104U)
#define MCME_PCTL107                 (107U)
#define MCME_PCTL111                 (111U)
#define MCME_PCTL112                 (112U)
#define MCME_PCTL123                 (123U)
#define MCME_PCTL127                 (127U)
#define MCME_PCTL128                 (128U)
#define MCME_PCTL162                 (162U)
#define MCME_PCTL166                 (166U)
#define MCME_PCTL184                 (184U)
#define MCME_PCTL185                 (185U)
#define MCME_PCTL186                 (186U)
#define MCME_PCTL187                 (187U)
#define MCME_PCTL188                 (188U)
#define MCME_PCTL213                 (213U)
#define MCME_PCTL220                 (220U)
#define MCME_PCTL225                 (225U)
#define MCME_PCTL226                 (226U)
#define MCME_PCTL227                 (227U)
#define MCME_PCTL229                 (229U)
#define MCME_PCTL232                 (232U)
#define MCME_PCTL235                 (235U)
#define MCME_PCTL239                 (239U)
#define MCME_PCTL245                 (245U)
#define MCME_PCTL246                 (246U)
#define MCME_PCTL247                 (247U)
#define MCME_PCTL248                 (248U)
#define MCME_PCTL249                 (249U)
#define MCME_PCTL250                 (250U)
#define MCME_PCTL252                 (252U)
#define MCME_PCTL253                 (253U)
#define MCME_PCTL254                 (254U)

#define CRCTST_MAX_INPUT_COUNT       (2048U)
#define CRCTST_SELF_TEST_BUFF_COUNT  (32U)
#define CRCTST_SELF_TEST_MODE_COUNT  (4U)

#define CRCTST_ERROR_FLAG_ON         (1U)
#define CRCTST_ERROR_FLAG_OFF        (0U)

#define CRCTST_INITIALIZED           (1U)
#define CRCTST_UNINITIALIZED         (0U)

#define CRCTST_CCITT_POLYG           (0U)
#define CRCTST_32_POLYG              (1U)
#define CRCTST_8_POLYG               (2U)
#define CRCTST_RESERVED              (3U)

#define CRCTST_INPUT_BITSWAP         (1U)

typedef  volatile struct LINFlexD_tag         LINFlexD_Type;
typedef  volatile struct DSPI_tag             DSPI_Type;
#ifndef CCFC3008PT
typedef  volatile struct CSRX_tag             CSENT_Type;
#endif

#if defined(CCFC3007PT)

#define LINFELXD_IFCR_COUNT          (16U)
#define LINFELXD_MAX_INSTANCE        (16U)
#define DSPI_MAX_INSTANCE            (8U)
#define DSPI_CTAR_COUNT              (8U)
#define CSENT_MAX_INSTANCE           (15U)

#if (SAF_CRC_LinflexRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
#define SAF_LINFELXD_BASE_PTR        {SAF_LINFlexD_0_PTR, SAF_LINFlexD_1_PTR, SAF_LINFlexD_2_PTR, SAF_LINFlexD_3_PTR, SAF_LINFlexD_4_PTR, SAF_LINFlexD_5_PTR, \
                                      SAF_LINFlexD_6_PTR, SAF_LINFlexD_7_PTR, SAF_LINFlexD_8_PTR, SAF_LINFlexD_9_PTR, SAF_LINFlexD_10_PTR, SAF_LINFlexD_11_PTR, \
                                      SAF_LINFlexD_12_PTR, SAF_LINFlexD_14_PTR, SAF_LINFlexD_15_PTR, SAF_LINFlexD_16_PTR}

#endif /* #if(SAF_CRC_LinflexRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

#if (SAF_CRC_DspiRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
#define SAF_DSPI_BASE_PTR            {SAF_DSPI_0_PTR, SAF_DSPI_1_PTR, SAF_DSPI_2_PTR, SAF_DSPI_3_PTR, SAF_DSPI_4_PTR, SAF_DSPI_5_PTR, SAF_DSPI_6_PTR, SAF_DSPI_12_PTR}
#endif /* #if(SAF_CRC_DspiRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

#if (SAF_CRC_CsentRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
#define SAF_CSENT_BASE_PTR           {SAF_CSRX_0_0_PTR, SAF_CSRX_0_1_PTR, SAF_CSRX_0_2_PTR, SAF_CSRX_0_3_PTR, SAF_CSRX_0_4_PTR, SAF_CSRX_0_5_PTR, SAF_CSRX_0_6_PTR, SAF_CSRX_0_7_PTR, \
                                      SAF_CSRX_1_0_PTR, SAF_CSRX_1_1_PTR, SAF_CSRX_1_2_PTR, SAF_CSRX_1_3_PTR, SAF_CSRX_1_4_PTR, SAF_CSRX_1_5_PTR, SAF_CSRX_1_6_PTR}
#endif /* #if(SAF_CRC_CsentRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

#elif defined(CCFC3007BC)

#define LINFELXD_IFCR_COUNT          (16U)
#define LINFELXD_MAX_INSTANCE        (16U)
#define DSPI_MAX_INSTANCE            (8U)
#define DSPI_CTAR_COUNT              (8U)
#define CSENT_MAX_INSTANCE           (2U)

#if (SAF_CRC_LinflexRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
#define SAF_LINFELXD_BASE_PTR        {SAF_LINFlexD_0_PTR, SAF_LINFlexD_1_PTR, SAF_LINFlexD_2_PTR, SAF_LINFlexD_3_PTR, SAF_LINFlexD_4_PTR, SAF_LINFlexD_5_PTR, \
                                      SAF_LINFlexD_6_PTR, SAF_LINFlexD_7_PTR, SAF_LINFlexD_8_PTR, SAF_LINFlexD_9_PTR, SAF_LINFlexD_10_PTR, SAF_LINFlexD_11_PTR, \
                                      SAF_LINFlexD_12_PTR, SAF_LINFlexD_14_PTR, SAF_LINFlexD_15_PTR, SAF_LINFlexD_16_PTR}
#endif /* #if(SAF_CRC_LinflexRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

#if (SAF_CRC_DspiRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
#define SAF_DSPI_BASE_PTR            {SAF_DSPI_0_PTR, SAF_DSPI_1_PTR, SAF_DSPI_2_PTR, SAF_DSPI_3_PTR, SAF_DSPI_4_PTR, SAF_DSPI_5_PTR, SAF_DSPI_6_PTR, SAF_DSPI_12_PTR}
#endif /* #if(SAF_CRC_DspiRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

#if (SAF_CRC_CsentRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
#define SAF_CSENT_BASE_PTR           {SAF_CSRX_0_PTR, SAF_CSRX_1_PTR}
#endif /* #if(SAF_CRC_CsentRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

#elif defined(CCFC3008PT)

#define LINFELXD_IFCR_COUNT          (16U)
#define LINFELXD_MAX_INSTANCE        (6U)
#define DSPI_MAX_INSTANCE            (8U)
#define DSPI_CTAR_COUNT              (8U)
#define CSENT_MAX_INSTANCE           (0U)

#if (SAF_CRC_LinflexRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
#define SAF_LINFELXD_BASE_PTR        {SAF_LINFlexD_0_PTR, SAF_LINFlexD_1_PTR, SAF_LINFlexD_2_PTR, SAF_LINFlexD_14_PTR, SAF_LINFlexD_15_PTR, SAF_LINFlexD_16_PTR}
#endif /* #if(SAF_CRC_LinflexRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

#if (SAF_CRC_DspiRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
#define SAF_DSPI_BASE_PTR            {SAF_DSPI_0_PTR, SAF_DSPI_1_PTR, SAF_DSPI_2_PTR, SAF_DSPI_3_PTR, SAF_DSPI_4_PTR, SAF_DSPI_5_PTR, SAF_DSPI_6_PTR, SAF_DSPI_12_PTR}
#endif /* #if(SAF_CRC_DspiRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */


#elif defined(CCFC3008PC)

#define LINFELXD_IFCR_COUNT          (16U)
#define LINFELXD_MAX_INSTANCE        (12U)
#define DSPI_MAX_INSTANCE            (8U)
#define DSPI_CTAR_COUNT              (8U)
#define CSENT_MAX_INSTANCE           (15U)

#if (SAF_CRC_LinflexRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
#define SAF_LINFELXD_BASE_PTR        {SAF_LINFlexD_0_PTR, SAF_LINFlexD_1_PTR, SAF_LINFlexD_2_PTR, SAF_LINFlexD_3_PTR, SAF_LINFlexD_5_PTR, SAF_LINFlexD_6_PTR,\
		                              SAF_LINFlexD_9_PTR, SAF_LINFlexD_10_PTR, SAF_LINFlexD_12_PTR, SAF_LINFlexD_14_PTR, SAF_LINFlexD_15_PTR, SAF_LINFlexD_16_PTR}
#endif /* #if(SAF_CRC_LinflexRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

#if (SAF_CRC_DspiRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
#define SAF_DSPI_BASE_PTR        {SAF_DSPI_0_PTR, SAF_DSPI_1_PTR, SAF_DSPI_2_PTR, SAF_DSPI_3_PTR, SAF_DSPI_4_PTR, SAF_DSPI_5_PTR, SAF_DSPI_6_PTR, SAF_DSPI_12_PTR}
#endif /* #if(SAF_CRC_DspiRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

#if (SAF_CRC_CsentRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
#define SAF_CSENT_BASE_PTR       {SAF_CSRX_0_0_PTR, SAF_CSRX_0_1_PTR, SAF_CSRX_0_2_PTR, SAF_CSRX_0_3_PTR, SAF_CSRX_0_4_PTR, SAF_CSRX_0_5_PTR, SAF_CSRX_0_6_PTR, SAF_CSRX_0_7_PTR, \
		                          SAF_CSRX_1_0_PTR, SAF_CSRX_1_1_PTR, SAF_CSRX_1_2_PTR, SAF_CSRX_1_3_PTR, SAF_CSRX_1_4_PTR, SAF_CSRX_1_5_PTR, SAF_CSRX_1_6_PTR}
#endif /* #if(SAF_CRC_CsentRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

#elif defined(CCFC3008PCSN)

#define LINFELXD_IFCR_COUNT          (16U)
#define LINFELXD_MAX_INSTANCE        (12U)
#define DSPI_MAX_INSTANCE            (8U)
#define DSPI_CTAR_COUNT              (8U)
#define CSENT_MAX_INSTANCE           (15U)

#if (SAF_CRC_LinflexRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
#define SAF_LINFELXD_BASE_PTR        {SAF_LINFlexD_0_PTR, SAF_LINFlexD_1_PTR, SAF_LINFlexD_2_PTR, SAF_LINFlexD_3_PTR, SAF_LINFlexD_5_PTR, SAF_LINFlexD_6_PTR, \
                                      SAF_LINFlexD_9_PTR, SAF_LINFlexD_10_PTR, SAF_LINFlexD_12_PTR, SAF_LINFlexD_14_PTR, SAF_LINFlexD_15_PTR, SAF_LINFlexD_16_PTR}
#endif /* #if(SAF_CRC_LinflexRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

#if (SAF_CRC_DspiRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
#define SAF_DSPI_BASE_PTR            {SAF_DSPI_0_PTR, SAF_DSPI_1_PTR, SAF_DSPI_2_PTR, SAF_DSPI_3_PTR, SAF_DSPI_4_PTR, SAF_DSPI_5_PTR, SAF_DSPI_6_PTR, SAF_DSPI_12_PTR}
#endif /* #if(SAF_CRC_DspiRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

#if (SAF_CRC_CsentRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
#define SAF_CSENT_BASE_PTR           {SAF_CSRX_0_0_PTR, SAF_CSRX_0_1_PTR, SAF_CSRX_0_2_PTR, SAF_CSRX_0_3_PTR, SAF_CSRX_0_4_PTR, SAF_CSRX_0_5_PTR, SAF_CSRX_0_6_PTR, SAF_CSRX_0_7_PTR, \
                                      SAF_CSRX_1_0_PTR, SAF_CSRX_1_1_PTR, SAF_CSRX_1_2_PTR, SAF_CSRX_1_3_PTR, SAF_CSRX_1_4_PTR, SAF_CSRX_1_5_PTR, SAF_CSRX_1_6_PTR}
#endif /* #if(SAF_CRC_CsentRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

#elif defined(CCFC3012PT)

#define LINFELXD_IFCR_COUNT          (16U)
#define LINFELXD_MAX_INSTANCE        (16U)
#define DSPI_MAX_INSTANCE            (22U)
#define DSPI_CTAR_COUNT              (8U)
#define CSENT_MAX_INSTANCE           (1U)

#if (SAF_CRC_LinflexRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
#define SAF_LINFELXD_BASE_PTR        {SAF_LINFlexD_0_PTR, SAF_LINFlexD_1_PTR, SAF_LINFlexD_2_PTR, SAF_LINFlexD_3_PTR, SAF_LINFlexD_4_PTR, SAF_LINFlexD_5_PTR, SAF_LINFlexD_6_PTR, SAF_LINFlexD_7_PTR, \
                                      SAF_LINFlexD_8_PTR, SAF_LINFlexD_9_PTR, SAF_LINFlexD_10_PTR, SAF_LINFlexD_11_PTR, SAF_LINFlexD_12_PTR, SAF_LINFlexD_14_PTR, SAF_LINFlexD_15_PTR, SAF_LINFlexD_16_PTR}
#endif /* #if(SAF_CRC_LinflexRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

#if (SAF_CRC_DspiRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
#define SAF_DSPI_BASE_PTR            {SAF_DSPI_0_PTR, SAF_DSPI_1_PTR, SAF_DSPI_2_PTR, SAF_DSPI_3_PTR, SAF_DSPI_4_PTR, SAF_DSPI_5_PTR, SAF_DSPI_6_PTR, SAF_DSPI_7_PTR, \
                                      SAF_DSPI_8_PTR, SAF_DSPI_9_PTR, SAF_DSPI_10_PTR, SAF_DSPI_11_PTR, SAF_DSPI_12_PTR, SAF_DSPI_13_PTR, SAF_DSPI_14_PTR, SAF_DSPI_15_PTR, \
                                      SAF_DSPI_16_PTR, SAF_DSPI_17_PTR, SAF_DSPI_18_PTR, SAF_DSPI_19_PTR, SAF_DSPI_20_PTR, SAF_DSPI_21_PTR}
#endif /* #if(SAF_CRC_DspiRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

#if (SAF_CRC_CsentRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
#define SAF_CSENT_BASE_PTR           {SAF_CSRX_0_PTR}
#endif /* #if(SAF_CRC_CsentRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */


#else
      #error
#endif

/* CRC - Peripheral instance base addresses */
/** Peripheral CRC_0 base address */
#define CRC_0_BASE                               (0xFFF64000UL)
/** Peripheral CRC_0 base pointer */
#define SAF_CRC_0                                 ((CRC_Type *)CRC_0_BASE)
/** Peripheral CRC_1 base address */
#define CRC_1_BASE                               (0xFBF64000UL)
/** Peripheral CRC_1 base pointer */
#define SAF_CRC_1                                 ((CRC_Type *)CRC_1_BASE)
/** Array initializer of CRC peripheral base addresses */
#define CRC_BASE_ADDRS                           { CRC_0_BASE, CRC_1_BASE }
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                            { SAF_CRC_0, SAF_CRC_1 }

/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/


/*!
 * @brief The CRC module Test information structure.
 *
 * This is the config information of CRC test.
 * Implements : Crc_TestInfoType_Class
 */
typedef struct Crc_TestInfoType
{
	FS_STATUS (*TestFuncPtr)(const uint8_t ParamSetIndex);
	char * funcName;
} Crc_TestInfoType;

/**
* @brief The CRC read back Test Result structure.
*/
typedef struct Crc_TestRstType
{
    /* CRC read back test name */
    char * funcName;
    /* CRC read back test expected result */
    uint32_t crcExpectedResult;
    /* CRC read back test calculated result */
    uint32_t crcCalculatedResult;
    /* CRC read back test initialized flag */
    uint8_t crcInitialized;
    /* CRC read back test result */
    FS_STATUS crcTstRslt;
    /* CRC read back test error flag */
    uint8_t crcErrorFlag;
}saf_crc_readback_test_result_t;

/**
* @brief The CRC Self Test Result structure.
*/
typedef struct
{
    /* CRC self test result */
    FS_STATUS crcSelfTstRslt;
}saf_crc_self_test_result_t;

typedef struct {
   uint32_t CFG;                               /**< Configuration Register, offset: 0x0 */
   uint32_t INP;                               /**< Input Register, offset: 0x4 */
   uint32_t CSTAT;                             /**< Current Status Register, offset: 0x8 */
   uint32_t OUTP;                              /**< Output Register, offset: 0xC */
} CRC_Type;

extern const Crc_TestInfoType SAF_crc_kTestInfo[CRC_TOTAL_READBACK_TESTS];

/**
****************************************************************************************
 * @brief: Function prototypes
****************************************************************************************
*/
FS_STATUS SAF_CRC_RegisterReadbackTest(const uint8_t index);

FS_STATUS SAF_CRC_SelfTest(void);

#if (SAF_CRC_XbarRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_XbarRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_PitRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_PitRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_CmuRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_CmuRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_PbridgeRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_PbridgeRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_EmiosRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_EmiosRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_EtpuRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_EtpuRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_EqadcRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_EqadcRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_SdadcRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_SdadcRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_PmcRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_PmcRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_Siul2RegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_Siul2RegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_RgmRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_RgmRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_IntcRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_IntcRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_RamRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_RamRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_FlashRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_FlashRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_DmaRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_DmaRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_CanfdRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_CanfdRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_CanRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_CanRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_LinflexRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_LinflexRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_StmRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_StmRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_DspiRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_DspiRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_SsiRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_SsiRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_SentRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_SentRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_CsentRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_CsentRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_FlexrayRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_FlexrayRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_I2cRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_I2cRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_EmacRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_EmacRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_Psi5RegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_Psi5RegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_I2sRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_I2sRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_I2sslvRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_I2sslvRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_SmpuRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_SmpuRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_McmeRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_McmeRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

#if (SAF_CRC_MccgmRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_MccgmRegReadbackCheck(const uint8_t ParamSetIndex);
#endif

FS_STATUS SAF_CRC_GetReadbackResult(saf_crc_readback_test_result_t *pTestResult);

FS_STATUS SAF_CRC_GetSelfTestResult(saf_crc_self_test_result_t *pTestResult);

#endif /* SAFETY_LIB_INC_SAF_CRCTST_H_ */
