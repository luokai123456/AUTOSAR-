/**
****************************************************************************************
 * @FilePath: SafetyTestHnd_Cfg.c
 * @Author: CCORE
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety test handle configuration C File
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
#include "SafetyTestHnd_Cfg.h"
#include "saf_sch.h"
#include "saf_ram.h" /*PRQA S 0380*/
#include "saf_stm.h"
#include "saf_pit.h"
#include "saf_fccu.h"
#include "saf_flash.h"
#include "saf_adc.h"
#include "saf_bist.h"
#include "saf_cmu.h"
#include "saf_core.h"
#include "saf_userservice_prestartup.h"
#include "saf_userservice_startup.h"
#include "saf_userservice_runtime.h"
#include "Saf_MemMap.h"
/*PRQA S 0310,0313,1533,3408,4304 EOF*/
/**
****************************************************************************************
 * @brief: Constants
****************************************************************************************
*/
extern saf_sch_err_container_type_t s_errContainer;

/**
****************************************************************************************
 * @brief: Structs
****************************************************************************************
*/
/* Prestartup Test Info */
SAF_SCH_SEC_VAR_INIT
saf_sch_prestartup_object_t PrestartupTestHandlerList[]=
{
/* Prestartup handle index 0 */{(saf_safety_test_func)&SAF_UserService_PrestartupTest},
};

SAF_SCH_SEC_VAR_INIT
saf_sch_prestartup_t s_libPrestartupSch =
{
    .prestartupTestInitialized = (bool)false,
    .pPrestartupTestHandlerList ={
                                   &PrestartupTestHandlerList[0],
                               },
     .pPrestartupTestErrStatus = (saf_sch_prestartup_err_t *)&s_errContainer.prestartupTestErrStatus[0],
};

/* Startup Test Info */
SAF_SCH_SEC_VAR_INIT
saf_sch_startup_object_t StartupTestHandlerList[]=
{
/* Startup handle index 0 */{(saf_safety_test_func)&SAF_UserService_DcfAndBistTest},
/* Startup handle index 1 */{(saf_safety_test_func)&SAF_UserService_OscTest},
/* Startup handle index 2 */{(saf_safety_test_func)&SAF_UserService_PllTest},
/* Startup handle index 3 */{(saf_safety_test_func)&SAF_UserService_PmcSelfTest},
/* Startup handle index 4 */{(saf_safety_test_func)&SAF_UserService_TsensPathTest},
/* Startup handle index 5 */{(saf_safety_test_func)&SAF_UserService_SwtPathTest},
/* Startup handle index 6 */{(saf_safety_test_func)&SAF_UserService_FlashTest},
/* Startup handle index 7 */{(saf_safety_test_func)&SAF_UserService_RamTest},
/* Startup handle index 8 */{(saf_safety_test_func)&SAF_UserService_CacheTest},
/* Startup handle index 9 */{(saf_safety_test_func)&SAF_UserService_StackTest},
/* Startup handle index 10 */{(saf_safety_test_func)&SAF_UserService_CmuTest},
/* Startup handle index 11 */{(saf_safety_test_func)&SAF_UserService_FccuRfTest},
/* Startup handle index 12 */{(saf_safety_test_func)&SAF_UserService_CrcSelfTest},
/* Startup handle index 13 */{(saf_safety_test_func)&SAF_UserService_StmConfigDataInit},
/* Startup handle index 14 */{(saf_safety_test_func)&SAF_UserService_PitConfigDataInit},
/* Startup handle index 15 */{(saf_safety_test_func)&SAF_UserService_AdcTest},
};

SAF_SCH_SEC_VAR_INIT
saf_sch_startup_t s_libStartupSch =
{
    .startupTestInitialized = (bool)false,
    .pStartupTestHandlerList ={
                                   &StartupTestHandlerList[0],
                                   &StartupTestHandlerList[1],
                                   &StartupTestHandlerList[2],
                                   &StartupTestHandlerList[3],
                                   &StartupTestHandlerList[4],
                                   &StartupTestHandlerList[5],
                                   &StartupTestHandlerList[6],
                                   &StartupTestHandlerList[7],
                                   &StartupTestHandlerList[8],
                                   &StartupTestHandlerList[9],
                                   &StartupTestHandlerList[10],
                                   &StartupTestHandlerList[11],
                                   &StartupTestHandlerList[12],
                                   &StartupTestHandlerList[13],
                                   &StartupTestHandlerList[14],
                                   &StartupTestHandlerList[15],
                               },
     .pstartupTestErrStatus = (saf_sch_startup_err_t *)&s_errContainer.startupTestErrStatus[0],
};

/* Runtime Test Info */
SAF_SCH_SEC_VAR_INIT
saf_sch_runtime_object_t RuntimeTestHandlerList[]=
{
/* Runtime handle index 0 */{(saf_safety_test_func)&SAF_UserService_StmMonitorTest},
/* Runtime handle index 1 */{(saf_safety_test_func)&SAF_UserService_PitMonitorTest},
/* Runtime handle index 2 */{(saf_safety_test_func)&SAF_UserService_TsensChipTempTest},
/* Runtime handle index 3 */{(saf_safety_test_func)&SAF_UserService_IntcTest},
/* Runtime handle index 4 */{(saf_safety_test_func)&SAF_UserService_CrcTest},
/* Runtime handle index 5 */{(saf_safety_test_func)&SAF_UserService_DmaTest},
};

SAF_SCH_SEC_VAR_INIT
saf_sch_runtime_t s_libRuntimeSch =
{
    .pRuntimeTestHandlerList = {
                                   &RuntimeTestHandlerList[0],
                                   &RuntimeTestHandlerList[1],
                                   &RuntimeTestHandlerList[2],
                                   &RuntimeTestHandlerList[3],
                                   &RuntimeTestHandlerList[4],
                                   &RuntimeTestHandlerList[5],
                               },
    .pruntimeTestErrStatus = (saf_sch_runtime_err_t *)&s_errContainer.runtimeTestErrStatus[0],
};

#ifdef __cplusplus
}
#endif

