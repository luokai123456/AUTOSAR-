/**
****************************************************************************************
 * @FilePath: saf_userservice_startup1.h
 * @Author: CCORE
 * @Date: 2024-02-12
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety User Service Startup1 Header File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_USERSERVICE_STARTUP1_H
#define SAF_USERSERVICE_STARTUP1_H

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_common.h"

/**
****************************************************************************************
 * @brief: Function prototypes
****************************************************************************************
*/
FS_STATUS SAF_UserService_OscTest(void);
FS_STATUS SAF_UserService_PllTest(void);
FS_STATUS SAF_UserService_FlashTest(void);
FS_STATUS SAF_UserService_RamTest(void);
FS_STATUS SAF_UserService_CacheTest(void);
FS_STATUS SAF_UserService_StackTest(void);
FS_STATUS SAF_UserService_FccuRfTest(void);
FS_STATUS SAF_UserService_CmuTest(void);
FS_STATUS SAF_UserService_DcfAndBistTest(void);
FS_STATUS SAF_UserService_AdcTest(void);
FS_STATUS SAF_UserService_PmcSelfTest(void);
FS_STATUS SAF_UserService_TsensPathTest(void);
FS_STATUS SAF_UserService_CrcSelfTest(void);
FS_STATUS SAF_UserService_SwtPathTest(void);
FS_STATUS SAF_UserService_StmConfigDataInit(void);
FS_STATUS SAF_UserService_PitConfigDataInit(void);
FS_STATUS SAF_UserService_MPUInit(void);
FS_STATUS SAF_UserService_SMPUInit(void);

#endif
