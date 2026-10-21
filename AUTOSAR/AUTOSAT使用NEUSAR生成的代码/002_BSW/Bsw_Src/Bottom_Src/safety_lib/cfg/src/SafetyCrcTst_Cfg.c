/**
****************************************************************************************
 * @FilePath: SafetyCrcTst_Cfg.c
 * @Author: CCORE
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety test Crc configuration C File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "SafetyCrcTst_Cfg.h"
#include "saf_crc.h"/*PRQA S 0380*/
#include "Saf_MemMap.h"
/* PRQA S 0753, 1533, 3408 EOF*/

/**
****************************************************************************************
 * @brief: Structs
****************************************************************************************
*/


/* CRC readback test call back */
SAF_CRC_SEC_CONFIG_DATA
const call_config_t s_crcReadTestCallSet =
{
    /* CRC notification function */
    .callback       = NULL,
    /* CRC notification function parameter */
    .callbackParam  = NULL
};


/* CRC self test call back */
SAF_CRC_SEC_CONFIG_DATA
const call_config_t s_crcSelfTestCallSet =
{
    /* CRC notification function */
    .callback       = NULL,
    /* CRC notification function parameter */
    .callbackParam  = NULL
};

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
/* Crc Test Info */
SAF_CRC_SEC_CONFIG_DATA
const Crc_TestInfoType SAF_crc_kTestInfo[CRC_TOTAL_READBACK_TESTS] =
{
    {&SAF_CRC_XbarRegReadbackCheck,   "SAF_CRC_XbarRegReadbackCheck"},
    {&SAF_CRC_PitRegReadbackCheck,   "SAF_CRC_PitRegReadbackCheck"},
    {&SAF_CRC_CmuRegReadbackCheck,   "SAF_CRC_CmuRegReadbackCheck"},
    {&SAF_CRC_PbridgeRegReadbackCheck,   "SAF_CRC_PbridgeRegReadbackCheck"},
    {&SAF_CRC_EmiosRegReadbackCheck,   "SAF_CRC_EmiosRegReadbackCheck"},
    {&SAF_CRC_EtpuRegReadbackCheck,   "SAF_CRC_EtpuRegReadbackCheck"},
    {&SAF_CRC_EqadcRegReadbackCheck,   "SAF_CRC_EqadcRegReadbackCheck"},
    {&SAF_CRC_SdadcRegReadbackCheck,   "SAF_CRC_SdadcRegReadbackCheck"},
    {&SAF_CRC_PmcRegReadbackCheck,   "SAF_CRC_PmcRegReadbackCheck"},
    {&SAF_CRC_Siul2RegReadbackCheck,   "SAF_CRC_Siul2RegReadbackCheck"},
    {&SAF_CRC_RgmRegReadbackCheck,   "SAF_CRC_RgmRegReadbackCheck"},
    {&SAF_CRC_IntcRegReadbackCheck,   "SAF_CRC_IntcRegReadbackCheck"},
    {&SAF_CRC_RamRegReadbackCheck,   "SAF_CRC_RamRegReadbackCheck"},
    {&SAF_CRC_FlashRegReadbackCheck,   "SAF_CRC_FlashRegReadbackCheck"},
    {&SAF_CRC_DmaRegReadbackCheck,   "SAF_CRC_DmaRegReadbackCheck"},
    {&SAF_CRC_CanRegReadbackCheck,   "SAF_CRC_CanRegReadbackCheck"},
    {&SAF_CRC_LinflexRegReadbackCheck,   "SAF_CRC_LinflexRegReadbackCheck"},
    {&SAF_CRC_StmRegReadbackCheck,   "SAF_CRC_StmRegReadbackCheck"},
    {&SAF_CRC_DspiRegReadbackCheck,   "SAF_CRC_DspiRegReadbackCheck"},
    {&SAF_CRC_SentRegReadbackCheck,   "SAF_CRC_SentRegReadbackCheck"},
    {&SAF_CRC_CsentRegReadbackCheck,   "SAF_CRC_CsentRegReadbackCheck"},
    {&SAF_CRC_I2cRegReadbackCheck,   "SAF_CRC_I2cRegReadbackCheck"},
    {&SAF_CRC_EmacRegReadbackCheck,   "SAF_CRC_EmacRegReadbackCheck"},
    {&SAF_CRC_Psi5RegReadbackCheck,   "SAF_CRC_Psi5RegReadbackCheck"},
    {&SAF_CRC_I2sRegReadbackCheck,   "SAF_CRC_I2sRegReadbackCheck"},
    {&SAF_CRC_I2sslvRegReadbackCheck,   "SAF_CRC_I2sslvRegReadbackCheck"},
    {&SAF_CRC_SmpuRegReadbackCheck,   "SAF_CRC_SmpuRegReadbackCheck"},
    {&SAF_CRC_McmeRegReadbackCheck,   "SAF_CRC_McmeRegReadbackCheck"},
    {&SAF_CRC_MccgmRegReadbackCheck,   "SAF_CRC_MccgmRegReadbackCheck"},
};

#ifdef __cplusplus
}
#endif

