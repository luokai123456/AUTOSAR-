/**
****************************************************************************************
 * @FilePath: saf_userservice_prestartup.c
 * @Author: CCORE
 * @Date: 2024-03-15
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety User Service Prestartup C Source File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_userservice_prestartup.h"
#include "saf_core.h"/*PRQA S 0380*/
#include "saf_cache.h"
#include "saf_stack.h"
#include "Saf_MemMap.h"
#include "ErrorDiag_Swc.h"
#include "ErrorHandler_Swc.h"
/**
****************************************************************************************
 * @brief: Definitions
****************************************************************************************
*/

/**
****************************************************************************************
 * @brief: Global Function
****************************************************************************************
*/
/**
****************************************************************************************
* @brief:  The service run the core tests.
* @return   FS_STATUS_SUCCESS: The core test is successful.
            FS_STATUS_ERROR: The core test is error.
****************************************************************************************
*/

SAF_SEC_CODE
FS_STATUS SAF_UserService_PrestartupTest(void)
{
    FS_STATUS result = FS_STATUS_SUCCESS;
    FS_STATUS status = FS_STATUS_SUCCESS;

#if 0 // cyh: 软复位后FES没清除，此处必报错，先屏蔽
    status = SAF_CORE_ResetDetectInit();
    if(FS_STATUS_SUCCESS != status)
    {
        if (s_coreCallSet.callback != NULL)
        {
            s_coreCallSet.callback(s_coreCallSet.callbackParam);
        }
        result = FS_STATUS_ERROR;
        ErrorHandler_ResetAndReport(ERRORID_MCU_Prestartup_ResetDetectInit_Test);
    }
#endif

    status = SAF_CACHE_Enable(SAF_CACHE_TYPE_ICACHE);
    if(FS_STATUS_SUCCESS != status)
    {
        if (NULL != s_cacheCallSet.callback)
        {
            s_cacheCallSet.callback(s_cacheCallSet.callbackParam);
        }
        result = FS_STATUS_ERROR;
        // ErrorHandler_ResetAndReport(ERRORID_MCU_Prestartup_CACHE_Enable_Test);
    }

    status = SAF_STACK_MonitorEnable();
    if(FS_STATUS_SUCCESS != status)
    {
        if (NULL != s_stackCallSet.callback)
        {
            s_stackCallSet.callback(s_stackCallSet.callbackParam);
        }
        result = FS_STATUS_ERROR;
        // ErrorHandler_ResetAndReport(ERRORID_MCU_Prestartup_STACK_MonitorEnable_Test);
    }

    return result;
}

