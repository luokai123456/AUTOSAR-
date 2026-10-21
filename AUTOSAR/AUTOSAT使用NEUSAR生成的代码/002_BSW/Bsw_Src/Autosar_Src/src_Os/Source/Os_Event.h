/*
********************************************************************************
*
*  File name: Os_Event.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: YAOXJ/2021.11.22
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: YAOXJ/2021.12.31
* Change: Delet redundant code.
* Cause: Updata
********************************************************************************
* Version: 3.2
* Author/Date: WangJP/2022.12.10
* Change: Modification of coding standard.
* Cause: Optimize
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: ZhangY/2023.10.07
* Change: Modify incorrect return value in API description of Os_Event_SetEventSimp.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2023.4.15
* Change: Adapted to GCC compiler.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: LiuZB/2025.02.20
* Change: Optimize space size.
* Cause: Update
********************************************************************************
*/
#ifndef OS_EVENT_H_
#define OS_EVENT_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Event_Types.h"
#include "Os_Task.h"
#include "Os_App.h"
#include "Os_Arch_Lcfg.h"

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
#if(  OS_CFG_EVENT_ENABLE == STD_ON  )
/*
********************************************************************************
* Function Name: Os_Event_SetEventSimp
*
* Explanation: Internal function to set event.
*
* Param: task: Reference to an task.
*        mask: Mask of the events to be set.
*
* Retval: E_OS_OK: No error.
*         E_OS_ACCESS: Called from invalid context.
********************************************************************************
*/
LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_Event_SetEventSimp
(
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_APPL_CONST) task,
    EventMaskType mask
)
{
    Os_StatusType ret = E_OS_OK;
    EventMaskType eventTrigger;

    if( OS_APP_STATEOFF(task->ownerAppId) )
    {
        ret = E_OS_ACCESS;
    }
    else
    {
        eventTrigger = OS_TASK_GETEVENTTRIGGER(task);
        eventTrigger |= mask;
        OS_TASK_SETEVENTTRIGGER(task, eventTrigger);
    }

    return ret;
}

extern FUNC(Os_StatusType, OS_CODE) Os_Event_SetEvent(TaskType taskId, EventMaskType mask);
extern FUNC(Os_StatusType, OS_CODE) Os_Event_ClearEvent(EventMaskType mask);
extern FUNC(Os_StatusType, OS_CODE) Os_Event_GetEvent(TaskType taskId, EventMaskRefType mask);
extern FUNC(Os_StatusType, OS_CODE) Os_Event_WaitEvent(EventMaskType mask);
#if( OS_CFG_MULTI_CORE == STD_ON )
extern FUNC(Os_StatusType, OS_CODE) Os_TargetSetEvent(TaskType taskId, EventMaskType mask);
#endif /* OS_CFG_MULTI_CORE == STD_ON */
#endif /* OS_CFG_EVENT_ENABLE == STD_ON */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_EVENT_H_ */
