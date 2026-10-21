/*
********************************************************************************
*
*  File name: Os_Alarm.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.13
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
* Author/Date: JiangGL/2023.6.9
* Change: Solve the issue of setting expiration points for error reporting.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2023.4.15
* Change: Adapted to GCC compiler.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: LiuZB/2025.02.20
* Change: Optimize space size.
* Cause: Update
********************************************************************************
*/
#ifndef OS_ALARM_H_
#define OS_ALARM_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Alarm_Types.h"
#include "Os_Platform_Lcfg.h"
#include "Os_Counter.h"
#include "Os_Arch_Lcfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Get the application id to which the alarm belongs through the alarm static
   configuration. */
#define OS_ALARM_GETAPPID(alarmCfg) ((alarmCfg)->ownerAppId)

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
extern FUNC(void, OS_CODE) Os_Alarm_Init
(
    P2CONST(Os_AlarmCfgType, AUTOMATIC, OS_APPL_CONST) alarmCfg,
    AppModeType appMode
);
extern FUNC(void, OS_CODE) Os_Alarm_AppTerminateAlarm
(
    P2CONST(Os_AlarmCfgType, AUTOMATIC, OS_APPL_CONST) alarmCfg
);
extern FUNC(Os_StatusType, OS_CODE) Os_Alarm_GetAlarm
(
    AlarmType alarmId,
    TickRefType tick
);
extern FUNC(Os_StatusType, OS_CODE) Os_Alarm_GetAlarmBase
(
    AlarmType alarmId,
    AlarmBaseRefType info
);
extern FUNC(Os_StatusType, OS_CODE) Os_Alarm_SetRelAlarm(
    AlarmType alarmId,
    Os_TickType increment,
    Os_TickType cycle
);
extern FUNC(Os_StatusType, OS_CODE) Os_Alarm_SetAbsAlarm
(
    AlarmType alarmId,
    Os_TickType start,
    Os_TickType cycle
);
extern FUNC(Os_StatusType, OS_CODE) Os_Alarm_CancelAlarm(AlarmType alarmId);
#if( OS_CFG_EVENT_ENABLE == STD_ON )
extern FUNC(uint8, OS_CODE) Os_Alarm_ActSetEvent
(
    P2VAR(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_DATA) expListNode
);
#endif /* OS_CFG_EVENT_ENABLE == STD_ON */
extern FUNC(uint8, OS_CODE) Os_Alarm_ActActivateTask
(
    P2VAR(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_DATA) expListNode
);
extern FUNC(uint8, OS_CODE) Os_Alarm_ActIcrmCnt
(
    P2VAR(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_DATA) expListNode
);
extern FUNC(uint8, OS_CODE) Os_Alarm_ActCallback
(
    P2VAR(Os_CntExpListNodeCfgType, AUTOMATIC, OS_APPL_DATA) expListNode
);

#if( OS_CFG_MULTI_CORE == STD_ON )
extern FUNC(Os_StatusType, OS_CODE) Os_Alarm_TargetGetAlarm
(
    AlarmType alarmId,
    TickRefType tick
);
extern FUNC(Os_StatusType, OS_CODE) Os_Alarm_TargetGetAlarmBase
(
    AlarmType alarmId,
    AlarmBaseRefType info
);
extern FUNC(Os_StatusType, OS_CODE) Os_Alarm_TargetSetRelAlarm(
    AlarmType alarmId,
    Os_TickType increment,
    Os_TickType cycle
);
extern FUNC(Os_StatusType, OS_CODE) Os_Alarm_TargetSetAbsAlarm
(
    AlarmType alarmId,
    Os_TickType start,
    Os_TickType cycle
);
extern FUNC(Os_StatusType, OS_CODE) Os_Alarm_TargetCancelAlarm(AlarmType alarmId);
extern FUNC(Os_StatusType, OS_CODE) Os_Alarm_TargetActActivateTask
(
    TaskType taskId
);
#if(  OS_CFG_EVENT_ENABLE == STD_ON  )
extern FUNC(Os_StatusType, OS_CODE) Os_Alarm_TargetActSetEvent
(
    TaskType taskId, EventMaskType mask
);
#endif /* OS_CFG_EVENT_ENABLE == STD_ON */
#endif /* OS_CFG_MULTI_CORE == STD_ON */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_ALARM_H_ */
