/*
********************************************************************************
*
*  File name: Os_MultiCore_Types.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.24
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: HanCL/2023.1.12
* Change: New struct MultiCore_GetCounterValue.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2023.5.26
* Change: Modifying GetCounterValue to cross core without obtaining a value.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2023.05.26
* Change: Resolve compilation warnings.
* Cause: Optimize
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2024.1.5
* Change: Added IocCallback functional related code.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: ZhangY/2023.08.19
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: ZhangY/2023.10.07
* Change: Modify Os_MCServe_Func parameter data type for QAC.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: JiangGL/2023.12.06
* Change: Modify Os_MultiCoreServeParamType to fix bug of getting wrong value in
*         cross core situation.
* Cause: Bugfix
********************************************************************************
* Version: 3.9
* Author/Date: LiG/2023.3.15
* Change: Add multicore service super error reporting structure.
* Cause: Bugfix
********************************************************************************
* Version: 3.10
* Author/Date: JiangGL/2024.2.27
* Change: Optimizing cross core services may lead to inaccurate status acquisition
*         issues.
* Cause: Optimize
********************************************************************************
* Version: 3.11
* Author/Date: LiuZB/2025.02.20
* Change: Optimize space size.
* Cause: Update
********************************************************************************
*/
#ifndef OS_MULTICORE_TYPES_H_
#define OS_MULTICORE_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Cfg.h"
#include "Os_Core_Types.h"
#include "Os_App_Types.h"
#include "Os_Alarm_Types.h"
#include "Os_Task_Types.h"
#include "Os_Event_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define Os_MULTICORE_INIT            (0U)
#define Os_MULTICORE_VALU_ONE        (1U)
#define Os_MULTICORE_MESSAGE_SIZE    (6U)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef enum
{
    Os_MCServe_ActivateTask_ID = 0U,
    Os_MCServe_AlarmActivateTask_ID,
    Os_MCServe_ChainTask_ID,
    Os_MCServe_GetTaskState_ID,
    Os_MCServe_GetAlarm_ID,
    Os_MCServe_GetAlarmBase_ID,
    Os_MCServe_SetRelAlarm_ID,
    Os_MCServe_SetAbsAlarm_ID,
    Os_MCServe_CancelAlarm_ID,
    Os_MCServe_TerminateApplication_ID,
    Os_MCServe_GetApplicationState_ID,
    Os_MCServe_ShutdownAllCores_ID,
#if(  OS_CFG_EVENT_ENABLE == STD_ON  )
    Os_MCServe_SetEvent_ID,
    Os_MCServe_AlarmSetEvent_ID,
#endif /* OS_CFG_EVENT_ENABLE == STD_ON */
#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
    Os_MCServe_StartSchdTbRel_ID,
    Os_MCServe_StartSchdTbAbs_ID,
    Os_MCServe_StopSchdTb_ID,
    Os_MCServe_NextSchdTb_ID,
    Os_MCServe_GetSchdTbStatus_ID,
#endif /* OS_CFG_SCHDTB_ENABLE == STD_ON */
    Os_MCServe_GetTaskStackUsage_ID,
    Os_MCServe_GetIsrStackUsage_ID,
    Os_MCServe_GetCounterValue_ID,
#if( OS_CFG_IOC_ENABLE == STD_ON )
    Os_MCServe_IocCallBack_ID,
#endif /* OS_CFG_IOC_ENABLE == STD_ON */
    Os_MCServe_Func_Counter
} Os_MCServe_FuncId;

typedef union
{
    struct MultiCore_ActivateTask{
        TaskType taskId;
        } Os_ActivateTask;

    struct MultiCore_ChainTask{
        TaskType taskId;
        } Os_ChainTask;

    struct MultiCore_GetTaskState{
        TaskType taskId;
        TaskStateType state;
        } Os_GetTaskState;

    struct MultiCore_GetAlarm{
        AlarmType alarmId;
        TickType tick;
        } Os_GetAlarm;

    struct MultiCore_GetAlarmBase{
        AlarmType alarmId;
        AlarmBaseType info;
        } Os_GetAlarmBase;

    struct MultiCore_SetRelAlarm{
        AlarmType alarmId;
        TickType increment;
        TickType cycle;
        } Os_SetRelAlarm;

    struct MultiCore_SetAbsAlarm{
        AlarmType alarmId;
        TickType start;
        TickType cycle;
        } Os_SetAbsAlarm;

    struct MultiCore_CancelAlarm{
        AlarmType alarmId;
        } Os_CancelAlarm;

    struct MultiCore_TerminateApplication{
        ApplicationType appId;
        RestartType restartOption;
        } Os_TerminateApplication;

    struct MultiCore_GetApplicationState{
        ApplicationType appId;
        ApplicationStateType value;
        } Os_GetApplicationState;

    struct MultiCore_ShutdownAllCores{
        StatusType error;
        } Os_ShutdownAllCores;

    struct MultiCore_SetEvent{
        TaskType taskId;
        EventMaskType mask;
        } Os_SetEvent;

    struct MultiCore_StartSchdTbRel{
        ScheduleTableType scheduleTableID;
        TickType offset;
        } Os_StartSchdTbRel;

    struct MultiCore_StartSchdTbAbs{
        ScheduleTableType scheduleTableID;
        TickType start;
        } Os_StartSchdTbAbs;

    struct MultiCore_StopSchdTb{
        ScheduleTableType scheduleTableID;
        } Os_StopSchdTb;

    struct MultiCore_NextSchdTb{
        ScheduleTableType scheduleTableID_From;
        ScheduleTableType scheduleTableID_To;
        } Os_NextSchdTb;

    struct MultiCore_GetSchdTbStatus{
        ScheduleTableType scheduleTableID;
        ScheduleTableStatusType scheduleStatus;
        } Os_GetSchdTbStatus;

    struct MultiCore_GetTaskStackUsage{
        TaskType taskId;
        Os_Stack_Size taskUsage;
        } Os_GetTaskStackUsage;

    struct MultiCore_GetIsrStackUsage{
        ISRType isrId;
        Os_Stack_Size isrUsage;
        } Os_GetIsrStackUsage;

    struct MultiCore_GetCounterValue{
        CounterType counterId;
        TickType value;
        } Os_GetCounterValue;
    struct MultiCore_IocCallBack{
        Os_IocCfgType iocCfg;
        uint32 senderId;
        } Os_IocCallBack;
} Os_MultiCoreServeParamType;

struct Os_MultiTimeoutCfg
{
    /* Timer used for timeout. */
    CounterType counterId;
    /* Timed out tick. */
    uint32 TimeoutTick;
};

typedef struct{
    boolean isSync;
    boolean active;
    Os_MCServe_FuncId funcId;
    Os_MultiCoreServeParamType Os_MultiCoreServeParam;
    StatusType retVal;
} Os_CoreServeType;

typedef struct{
    uint8 writeId;
    Os_CoreServeType Os_CoreServe[Os_MULTICORE_MESSAGE_SIZE];
} Os_MultiCoreServeType;


typedef struct{
    volatile boolean active;
    Os_CoreServeType* addr;
} Os_MultiCoreCommType;

typedef StatusType (*Os_MCServe_Func)(Os_MultiCoreServeParamType* parameter);
typedef struct Os_MultiTimeoutCfg Os_MultiTimeoutCfgType;

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

#endif /* OS_MULTICORE_TYPES_H_ */
