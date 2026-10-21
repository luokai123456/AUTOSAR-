/*
********************************************************************************
*
*  File name: Os_Monitor_Cfg.c
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date : lixing/2022.07.14
* Change: New create.
* Cause: New
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Monitor_Cfg.h"
#include "Os_Monitor.h"
#include "Os_Platform_Lcfg.h"
#include "Os.h"
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
const TaskType Os_Monitor_CoreidleTaskMapping[OS_COREID_COUNT] =
{
    IDLE_TASK_CORE0,
    IDLE_TASK_CORE1,
    IDLE_TASK_CORE2,
    IDLE_TASK_CORE3,
    IDLE_TASK_CORE4,
    IDLE_TASK_CORE5
};
#if(OS_MONITOR_EXTENDTASKCOUNT > 0)
const Os_Monitor_ExtendTaskSubTimeType_st Os_Monitor_ExtendTaskSubTimeNumber[OS_MONITOR_EXTENDTASKCOUNT] =
{
    {APP1_TASK0_UDS_CORE2_QM, 51},
    {APP1_TASK1_UDS_CORE2_QM, 64},
    {APP1_TASK2_UDS_CORE2_QM, 24},
    {APP1_TASK_UDS_CORE1_QM, 48},
    {APP1_TASK_UDS_CORE3_QM, 13},
    {APP1_TASK_UDS_CORE4_QM, 1},
    {APP1_TASK_UDS_CORE5_QM, 1}
};
#endif
const CounterType Os_Monitor_CoreUseCounterIndex[OS_COREID_COUNT] =
{
    OS_MONITOR_COUNTER,
    OS_MONITOR_COUNTER,
    OS_MONITOR_COUNTER,
    OS_MONITOR_COUNTER,
    OS_MONITOR_COUNTER,
    OS_MONITOR_COUNTER
};

/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

