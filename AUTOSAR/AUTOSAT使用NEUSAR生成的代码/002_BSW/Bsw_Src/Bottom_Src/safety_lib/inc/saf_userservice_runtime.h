/**
****************************************************************************************
 * @FilePath: saf_userservice_runtime.h
 * @Author: CCORE
 * @Date: 2024-02-12
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety User Service Runtime Header File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_USERSERVICE_RUNTIME_H
#define SAF_USERSERVICE_RUNTIME_H

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_crc.h"
#include "SafetyCrcTst_Cfg.h"
#include "saf_common.h"

/**
****************************************************************************************
 * @brief: Function prototypes
****************************************************************************************
*/
FS_STATUS SAF_UserService_CrcTest(void);

FS_STATUS SAF_UserService_StmMonitorTest(void);

FS_STATUS SAF_UserService_PitMonitorTest(void);

FS_STATUS SAF_UserService_TsensChipTempTest(void);

FS_STATUS SAF_UserService_IntcTest(void);

FS_STATUS SAF_UserService_DmaTest(void);

#endif /* SAFETY_LIB_INC_SAF_RUNTIME_SERVICE_H_ */
