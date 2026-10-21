/*
********************************************************************************
*
*  File name: Os_App_Types.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.19
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: ZhangY/2023.11.14
* Change: Modify RestartTask member types in Os_AppCfg struct.
* Cause: Bugfix
********************************************************************************
*/
#ifndef OS_APP_TYPES_H_
#define OS_APP_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Types.h"
#include "Os_Types_Cfg.h"
#include "Os_Hook_Types.h"
#include "Os_Task_Types.h"
#include "Os_TrustFun_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define OS_APP_TRUSTED   (0x01U)  /* App is trusted. */
#define OS_APP_NOTRUSTED (0x00U)  /* App is non-trusted. */

#define OS_APP_INIT      (0U)     /* App initial zero value. */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
struct Os_AppDyn
{
    ApplicationStateType appState;
};

struct Os_AppCfg
{
    boolean appDelayTimingViolation; /* Whether to delay processing time violation. */
    uint8 appTrust;  /* Tells whether the application is trusted. */
    struct Os_AppDyn* appDyn;                /* App's dynamic configration. */
    const Os_StartupHookType startupHook;    /* App's own startup hook. */
    const Os_ShutdownHookType shutdownHook;  /* App's own Shutdown hook. */
    const Os_ErrorHookType errorHook;        /* App's own Error hook. */
    CoreIdType coreId;  /* The core to which this application belongs. */
    const struct Os_TaskCfg* const* RestartTask;   /* Restart Task parameter. */
    ApplicationType AppId;                   /* Application Id. */
};

typedef struct Os_AppDyn Os_AppDynType;
typedef struct Os_AppCfg Os_AppCfgType;
typedef Os_AppCfgType* Os_AppCfgRefType;

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#endif /* OS_APP_TYPES_H_ */
