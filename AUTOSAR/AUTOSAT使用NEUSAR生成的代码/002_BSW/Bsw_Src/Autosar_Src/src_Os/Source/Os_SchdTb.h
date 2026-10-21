/*
********************************************************************************
*
*  File name: Os_SchdTb.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.23
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2022.11.21
* Change: Change OS_VAR_NOINIT to OS_VAR_NO_INIT.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: JiangGL/2022.11.23
* Change: Added Os_ SchdTb_ AppTerminateSchdTb interface is used to end ShcTb.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2023.6.9
* Change: Scheduling Table Deviation Movement Problem.
* Cause: Bugfix
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2024.2.29
* Change: To remove numerical macros, a meaningful macro was added.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: LiG/2023.4.15
* Change: Adapted to GCC compiler.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: LiuZB/2025.02.20
* Change: Optimize space size.
* Cause: Update
********************************************************************************
*/
#ifndef OS_SCHDTB_H_
#define OS_SCHDTB_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_SchdTb_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define OS_SCHDTB_GETAPPID(schdTbCfg) ((schdTbCfg)->ownerAppId)
#define OS_SCHDTB_MAXSHORTEN_DEVIATION_CONVERT(value) ((~(value)) + 1U)
#define OS_SCHDTB_FLIPDEV (1U)

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
#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
extern FUNC(void, OS_CODE) Os_SchdTb_Init
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg,
    AppModeType appMode
);
extern FUNC(uint8, OS_CODE) Os_SchdTb_ActStandardExe
(
    P2VAR(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_DATA) expListNode
);

extern FUNC(uint8, OS_CODE) Os_SchdTb_ActSyncExe
(
    P2VAR(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_DATA) expListNode
);

extern FUNC(uint8, OS_CODE) Os_SchdTb_ActCyclicExe
(
    P2VAR(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_DATA) expListNode
);
extern FUNC(uint8, OS_CODE) Os_SchdTb_ActSingleExe
(
    P2VAR(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_DATA) expListNode
);
extern FUNC(void, OS_CODE) Os_SchdTb_AppTerminateSchdTb
(
    P2CONST(Os_SchdTbCfgType, AUTOMATIC, OS_APPL_CONST) schdTbCfg
);
extern FUNC(StatusType, OS_CODE) Os_SchdTb_StartScheduleTableRel
(
    ScheduleTableType scheduleTableID,
    TickType offset
);
extern FUNC(StatusType, OS_CODE) Os_SchdTb_StartScheduleTableAbs
(
    ScheduleTableType scheduleTableID,
    TickType start
);
extern FUNC(StatusType, OS_CODE) Os_SchdTb_StopScheduleTable
(
    ScheduleTableType scheduleTableID
);
extern FUNC(StatusType, OS_CODE) Os_SchdTb_NextScheduleTable
(
    ScheduleTableType scheduleTableID_From,
    ScheduleTableType scheduleTableID_To
);
extern FUNC(StatusType, OS_CODE) Os_SchdTb_StartScheduleTableSynchron
(
    ScheduleTableType scheduleTableID
);
extern FUNC(StatusType, OS_CODE) Os_SchdTb_SyncScheduleTable
(
    ScheduleTableType scheduleTableID,
    TickType syncValue
);
extern FUNC(StatusType, OS_CODE) Os_SchdTb_SetScheduleTableAsync
(
    ScheduleTableType scheduleTableID
);
extern FUNC(StatusType, OS_CODE) Os_SchdTb_GetScheduleTableStatus
(
    ScheduleTableType scheduleTableID,
    ScheduleTableStatusRefType scheduleStatus
);
#if( OS_CFG_MULTI_CORE == STD_ON )
extern FUNC(StatusType, OS_CODE) Os_SchdTb_TargetStartScheduleTableRel
(
    ScheduleTableType scheduleTableID,
    TickType offset
);
extern FUNC(StatusType, OS_CODE) Os_SchdTb_TargetStartScheduleTableAbs
(
    ScheduleTableType scheduleTableID,
    TickType start
);
extern FUNC(StatusType, OS_CODE) Os_SchdTb_TargetStopScheduleTable
(
    ScheduleTableType scheduleTableID
);
extern FUNC(StatusType, OS_CODE) Os_SchdTb_TargetNextScheduleTable
(
    ScheduleTableType scheduleTableID_From,
    ScheduleTableType scheduleTableID_To
);
extern FUNC(StatusType, OS_CODE) Os_SchdTb_TargetGetScheduleTableStatus
(
    ScheduleTableType scheduleTableID,
    ScheduleTableStatusRefType scheduleStatus
);
#endif /* OS_CFG_MULTI_CORE == STD_ON */
#endif /* OS_CFG_SCHDTB_ENABLE == STD_ON */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_SCHDTB_H_ */
