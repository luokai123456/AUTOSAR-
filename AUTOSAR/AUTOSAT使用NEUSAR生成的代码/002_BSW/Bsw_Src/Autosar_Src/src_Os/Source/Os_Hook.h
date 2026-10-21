/*
********************************************************************************
*
*  File name: Os_Hook.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.17
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2023.4.15
* Change: Adapted to GCC compiler.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: LiuZB/2025.3.20
* Change: Add declaration of Hook function for test.
* Cause: Update
********************************************************************************
*/
#ifndef OS_HOOK_H_
#define OS_HOOK_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Types.h"
#include "Os_Hook_Types.h"
#include "Os_Core_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
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
extern FUNC(void, OS_CODE) Os_Hook_CallStartupHook
(
    CoreIdType coreId
);
extern FUNC(void, OS_CODE) Os_CallPreTaskHook
(
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_APPL_CONST) task
);
extern FUNC(void, OS_CODE) Os_CallPostTaskHook
(
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_APPL_CONST) task
);
extern FUNC(void, OS_CODE) Os_Hook_CallShutdownHook
(
    CoreIdType coreId,
    StatusType error,
    boolean sync
);
extern FUNC(StatusType, OS_CODE) Os_Hook_CallErrorHook
(
    OSServiceIdType serviceId,
    StatusType error
);
extern FUNC(void, OS_CODE) Os_Hook_CallProtectionHook
(
    StatusType error
);
#ifdef OS_TEST_ENABLE
extern FUNC(void, OS_CODE) OsPitHook(void);
extern FUNC(void, OS_CODE) OsHrtHook(void);
extern FUNC(void, OS_CODE) OS_TP_Reset_Current_Budget_Hook
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) currentTpCfg
);
extern FUNC(void, OS_CODE) OS_TP_Frame_Interval_Hook
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) tpCfg,
    Os_TickType nowValue
);
extern FUNC(void, OS_CODE) OS_TP_IsrFrame_Interval_Hook
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) tpCfg,
    Os_TickType nowValue
);
#endif

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_HOOK_H_ */
