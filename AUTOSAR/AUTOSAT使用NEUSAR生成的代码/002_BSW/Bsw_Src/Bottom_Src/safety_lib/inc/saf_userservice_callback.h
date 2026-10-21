/**
****************************************************************************************
 * @FilePath: saf_userservice_callback.h
 * @Author: CCORE
 * @Date: 2024-03-12
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety User Service call back Header File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_USERSERVICE_CALLBACK_H
#define SAF_USERSERVICE_CALLBACK_H
/*PRQA S 0779 EOF*/
/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/

/**
****************************************************************************************
* @brief: Structures
****************************************************************************************
*/
/*
 * @brief safety callback configurations
 */

typedef struct
{
    void                (*callback)(void *param);
    void                *callbackParam;
} call_config_t;

/**
****************************************************************************************
 * @brief: Global Variable
****************************************************************************************
*/

extern const call_config_t s_pllPeriphClkCallSet;
extern const call_config_t s_stackCallSet;
extern const call_config_t s_pmcSelfTestCallSet;
extern const call_config_t s_cacheCallSet;
extern const call_config_t s_mpuCallSet;
extern const call_config_t s_smpuCallSet;
extern const call_config_t s_coreCallSet;
extern const call_config_t s_TsensChipTempHtdPathCallSet;
extern const call_config_t s_TsensChipTempLtdPathCallSet;
extern const call_config_t s_crcSelfTestCallSet;
extern const call_config_t s_SwtPathCallSet;
extern const call_config_t s_StmTimerConfigDataInitCallSet;
extern const call_config_t s_PitTimerConfigDataInitCallSet;
extern const call_config_t s_crcReadTestCallSet;

/**
****************************************************************************************
 * @brief: Function prototypes
****************************************************************************************
*/
void SAF_UserService_FlashEccCallBack(void *param);
void SAF_UserService_StmTimerMonitorCallBack(void *param);
void SAF_UserService_PitTimerMonitorcCallBack(void *param);
void SAF_UserService_TsensChipTempCallBack(void *param);

void SAF_UserService_OSCCallBack(void *param);
void SAF_UserService_PLLSysClkCallBack(void *param);
void SAF_UserService_PLLMcanClkCallBack(void *param);
void SAF_UserService_CrcCallBack(void *param);
void SAF_UserService_Fccu31CmuDisableCallback(void *param);
void SAF_UserService_Fccu31CmuDisableCallback_test(void *param);
void SAF_UserService_Fccu32CmuDisableCallback(void *param);
void SAF_UserService_Fccu32CmuDisableCallback_test(void *param);
void SAF_UserService_Fccu33CmuDisableCallback(void *param);
void SAF_UserService_Fccu33CmuDisableCallback_test(void *param);
void SAF_UserService_Fccu34CmuDisableCallback(void *param);
void SAF_UserService_Fccu34CmuDisableCallback_Injecttest(void *param);
void SAF_UserService_CmuConfigcheckCallBack(void *param);
void SAF_UserService_CmuMonitorTestFreqOverHighCallBack(void *param);
void SAF_UserService_CmuMonitorTestFreqOverLowCallBack(void *param);
void SAF_UserService_CmuMonitorTestOscFreqOverLowCallBack(void *param);
void SAF_UserService_CmuUserServiceTestCallBack(void *param);
void SAF_UserService_AdcCallBack(void *param);
void SAF_UserService_IntcCallBack(void *param);
void SAF_UserService_DmaCallBack(void *param);
void SAF_UserService_PmcSelfCallBack(void *param);
void SAF_UserService_SwtMonitorTimerCallBack(void *param);

void Saf_RamCEInject_Callback(void *param);
void Saf_FlashCEInject_Callback(void *param);

#endif /* SAF_USERSERVICE_CALLBACK_H */
