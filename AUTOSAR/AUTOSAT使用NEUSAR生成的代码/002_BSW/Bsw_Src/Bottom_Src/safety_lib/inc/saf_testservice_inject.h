/**
****************************************************************************************
 * @FilePath: saf_testservice_Inject.h
 * @Author: CCORE
 * @Date: 2024-02-12
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety Test Service Inject Header File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_TESTSERVICE_INJECT_H
#define SAF_TESTSERVICE_INJECT_H

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_cache.h"
#include "saf_stack.h"
/**
****************************************************************************************
 * @brief: Function prototypes
****************************************************************************************
*/
#if SAF_CACHE_SUPPORTED
FS_STATUS SAF_UserService_CacheEdcTest(void);
#endif

FS_STATUS SAF_UserService_StackMonitorTest(void);

#if SAF_MPU_SUPPORTED
FS_STATUS SAF_UserService_MpuAccessRightTest(void);
#endif

#if SAF_SMPU_SUPPORTED
FS_STATUS SAF_UserService_SmpuAccessRightTest(void);
#endif

FS_STATUS SAF_UserService_FlashEcc_LossyTest(void);

void SAF_IrcoscFreqMonitorFaultInj(void);

void SAF_IrcoscFreqMonitorFaultRestore(void);

void SAF_CRCReadBackFaultInj(void);

#if SAF_ITCM_SUPPORTED
FS_STATUS SAF_UserService_ITCMEccTest(void);
#endif

FS_STATUS SAF_UserService_IntcMonitorTest(void);

void SAF_UserInject_StartupTest(void);

#endif /* SAFETY_LIB_INC_SAF_RUNTIME_SERVICE_H_ */
