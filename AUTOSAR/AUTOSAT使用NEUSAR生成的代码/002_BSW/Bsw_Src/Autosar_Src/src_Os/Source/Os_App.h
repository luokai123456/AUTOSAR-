/*
********************************************************************************
*
*  File name: Os_App.h
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
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: ZhangY/2023.08.03
* Change: Add declaration of Os_App_AllowAccess.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: ZhangY/2023.12.06
* Change: Add OS_APP_GETRESTARTTASK from Os_App.c file.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: ZhangY/2024.01.10
* Change: Add macros from Os_App.c.
* Cause: Bugfix
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2023.4.15
* Change: Adapted to GCC compiler.
* Cause: Update
********************************************************************************
*/
#ifndef OS_APP_H_
#define OS_APP_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_App_Types.h"
#include "Os_Arch_Lcfg.h"
#include "Os_Cfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* App permission mask. */
#define OS_APPMATCHMASK                 (1U)
/* Determine whether the application permissions match. */
#define OS_APPMATCH(mask, appId)        (((mask) & ((uint32)OS_APPMATCHMASK << (uint8)(appId))) == 0U)
/* Get the application static configuration through id. */
#define OS_APP_GETCFG(appId)            (Os_AppCfgData[appId])
/* Determines whether the application is active and accessible. */
#define OS_APP_STATEOFF(appId)          (Os_AppCfgData[appId]->appDyn->appState != APPLICATION_ACCESSIBLE)
/* Get the application system error hook. */
#define Os_APPGETSYSERRORHOOK(coreId)   (Os_CoreCfgData[coreId]->systemApp->errorHook)
/* Get the application error hook. */
#define Os_APPGETERRORHOOK(appId)       (Os_AppCfgData[appId]->errorHook)
/* Get the application startup hook. */
#define Os_APPGETSTARTUPHOOK(appId)     (Os_AppCfgData[appId]->startupHook)
/* Get the application shutdown hook. */
#define Os_APPGETSHUDOWNHOOK(appId)     (Os_AppCfgData[appId]->shutdownHook)
/* Get the application id through static configuration. */
#define Os_APPGETAPPID(appCfg)          ((appCfg)->AppId)
/* Get the application is trust type. */
#define OS_APPGETTRUSTED(appId)         (Os_AppCfgData[appId]->appTrust)
/* Get the core id to which the alarm belongs through
   the alarm static configuration. */
#define OS_APP_GETCOREID(appCfg)        ((appCfg)->coreId)
/* Determine whether the application configures DelayTimingViolation. */
#define OS_APP_GETDELAYTIMING(appId)    (Os_AppCfgData[appId]->appDelayTimingViolation)
/* Get restart task for application configuration. */
#define OS_APP_GETRESTARTTASK(appId)    (Os_AppCfgData[appId]->RestartTask)
/* Get the application state. */
#define OS_APP_GETSTATE(appCfg)         ((appCfg)->appDyn->appState)
/* Set the application state. */
#define OS_APP_SETSTATE(appCfg, state)  ((appCfg)->appDyn->appState = (state))

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
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
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
extern FUNC(void, OS_CODE) Os_App_Init
(
    P2CONST(Os_AppCfgType, AUTOMATIC, OS_APPL_CONST) app
);
extern FUNC(Os_StatusType, OS_CODE) Os_App_AllowAccess(void);
extern FUNC(Os_StatusType, OS_CODE) Os_App_IntTerminationApp
(
    P2CONST(Os_AppCfgType, AUTOMATIC, OS_APPL_CONST) appCfg,
    RestartType restartOption
);
extern FUNC(Os_StatusType, OS_CODE) Os_App_TerminationApp
(
    ApplicationType appId,
    RestartType restartOption
);
extern FUNC(ApplicationType, OS_CODE) Os_App_GetAppId(void);
extern FUNC(ApplicationType, OS_CODE) Os_App_GetCurrentAppId(void);
extern FUNC(StatusType, OS_CODE) Os_App_GetAppState
(
    ApplicationType appId,
    ApplicationStateRefType value
);
#if( OS_CFG_MULTI_CORE == STD_ON )
extern FUNC(StatusType, OS_CODE) Os_App_TragetTerminationApp
(
    ApplicationType appId,
    RestartType restartOption
);
extern FUNC(StatusType, OS_CODE) Os_App_TragetGetAppState
(
    ApplicationType appId,
    ApplicationStateRefType value
);
#endif /* OS_CFG_MULTI_CORE == STD_ON */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_APP_H_ */
