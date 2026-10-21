/*
********************************************************************************
*
*  File name: Os_Scheduler.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.20
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2022.11.21
* Change: Change OS_VAR_NOINIT to OS_VAR_NO_INIT.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2023.4.15
* Change: Adapted to GCC compiler.
* Cause: Update
********************************************************************************
*/
#ifndef OS_SCHEDULER_H_
#define OS_SCHEDULER_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Scheduler_Types.h"
#include "Os_Arch_Context.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Enable scheduler. */
#define OS_SCHEDULER_ENABLESCHEDULER(schdCfg)   ((schdCfg)->schdDyn->allowSchedule = TRUE)
/* Disable scheduler. */
#define OS_SCHEDULER_DISABLESCHEDULER(schdCfg)  ((schdCfg)->schdDyn->allowSchedule = FALSE)
/* Get schedule allow scheduling status. */
#define OS_SCHEDULER_GETSCHEDULERSTATE(schdCfg) ((schdCfg)->schdDyn->allowSchedule)

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
extern FUNC(void, OS_CODE) Os_Schedler_Init
(
    P2CONST(Os_SchedulerCfgType, AUTOMATIC, OS_APPL_CONST) scheduler,
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_APPL_CONST) idleTask
);
extern FUNC(StatusType, OS_CODE) Os_Schedler_InsertTask
(
    P2CONST(Os_SchedulerCfgType, AUTOMATIC, OS_APPL_CONST) scheduler,
    P2VAR(Os_TaskDynType, AUTOMATIC, OS_APPL_DATA) taskDyn
);
extern FUNC_P2VAR(Os_TaskDynType, OS_APPL_DATA, OS_CODE) Os_Schedler_Schedle
(
    P2CONST(Os_SchedulerCfgType, AUTOMATIC, OS_APPL_CONST) scheduler
);
extern FUNC(StatusType, OS_CODE) Os_Schedler_DeleteTask
(
    P2CONST(Os_SchedulerCfgType, AUTOMATIC, OS_APPL_CONST) scheduler,
    P2CONST(Os_TaskDynType, AUTOMATIC, OS_APPL_CONST) taskDyn
);
extern FUNC(StatusType, OS_CODE) Os_Schedler_DeleteTaskAll
(
    P2CONST(Os_SchedulerCfgType, AUTOMATIC, OS_APPL_CONST) scheduler,
    P2CONST(Os_TaskDynType, AUTOMATIC, OS_APPL_CONST) taskDyn
);
extern FUNC(StatusType, OS_CODE) Os_Schedler_IncreasePriority
(
    P2CONST(Os_SchedulerCfgType, AUTOMATIC, OS_APPL_CONST) scheduler,
    Os_TaskPrioType level
);
extern FUNC(boolean, OS_CODE) Os_Schedler_NeedSchedle
(
    P2CONST(Os_SchedulerCfgType, AUTOMATIC, OS_APPL_CONST) scheduler
);

extern FUNC(StatusType, OS_CODE) Os_Schedler_DecreasePriority
(
    P2CONST(Os_SchedulerCfgType, AUTOMATIC, OS_APPL_CONST) scheduler,
    Os_TaskPrioType level
);
extern FUNC(StatusType, OS_CODE) Os_Schedler_Schedule(void);

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_SCHEDULER_H_ */
