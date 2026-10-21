/*
********************************************************************************
*
*  File name: Os_Platform_Lcfg.c
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date : HanCL/2021.11.23
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2023.9.8
* Change: Modify Structure Type.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2023.10.11
* Change: Modified the rule for Counter referencing the first element in Core.
* Cause: Bugfix
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Types_Cfg.h"
#include "Os_Platform_Lcfg.h"
#include "Os_Core_Types.h"
#include "Os_TaskQueue.h"
#include "Os_Tp_Lcfg.h"
#include "Os_MemProtection_Types.h"
#include "Os_SchdTb_Types.h"
#include "Os_Lcfg.h"
#include "Os_SchdTb_Lcfg.h"
#include "Os_Mp_Lcfg.h"
#include "Os_MultiCore_Types.h"

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/*
********************************************************************************
*    Local Types
********************************************************************************
*/
/*
********************************************************************************
*    Local Variables
********************************************************************************
*/
/*
********************************************************************************
*    Local Functions
********************************************************************************
*/
#define OS_START_SEC_VAR_OSCORE0 
#include "Os_MemMap.h"
/* Core dynamic parameters start. */
static Os_CoreDynType OsCfg_Core_OsCore0_Dyn;

static Os_CoreIntStateType OsCfg_IntState_OsCore0_Dyn;

/* Core dynamic parameters end. */ 

/* App dynamic parameters start. */
static Os_AppDynType OsCfg_Appl_SystemApplication_OsCore_Core0_Dyn;
static Os_AppDynType OsCfg_Appl_App1_Application_Core0_QM_Dyn;
static Os_AppDynType OsCfg_Appl_Bsw_Application_Core0_QM_Dyn;

/* App dynamic parameters end. */

/* Task dynamic parameters start. */
static Os_TaskDynType OsCfg_Task_Default_Init_Task_Core0_Dyn;
static Os_TaskDynType OsCfg_Task_Idle_Task_Core0_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_1ms_Core0_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_5ms_Core0_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_10ms_Core0_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_20ms_Core0_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_50ms_Core0_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_100ms_Core0_QM_Dyn;
static Os_TaskDynType OsCfg_Task_SWC_Init_Task_Core0_Dyn;
static Os_TaskDynType OsCfg_Task_Bsw_Task_10ms_Core0_QM_Dyn;
static Os_TaskDynType OsCfg_Task_Bsw_Task_5ms_Core0_QM_Dyn;

/* Task dynamic parameters end. */

/* Isr dynamic parameters start. */
static Os_IsrDynType OsCfg_Isr_CounterIsr_SystemTimer_Core0_Dyn;
static Os_IsrDynType OsCfg_Isr_MultiCommIsr_Core0_Dyn;
static Os_IsrDynType OsCfg_Isr_Os_ISR_37_STM0_CH1_Dyn;

/* Isr dynamic parameters end. */

/* Counter dynamic parameters start. */
static Os_CounterSwDynType OsCfg_Counter_SystemTimer_Core0_Dyn;
static Os_CounterSwDynType OsCfg_Counter_Os_Monitor_Counter_Dyn;

/* Counter dynamic parameters end. */

/* Alarm dynamic parameters start. */
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_1ms_Core0_QM_1ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_5ms_Core0_QM_5ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_10ms_Core0_QM_10ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_20ms_Core0_QM_20ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_50ms_Core0_QM_50ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_100ms_Core0_QM_100ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core0_QM_10ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_5ms_Core0_QM_5ms_Dyn;

/* Alarm dynamic parameters end. */

/* Resource dynamic parameters start. */
static Os_ResourceDynType Os_Resource_Core0_Task_OsResource0_Dyn;
static Os_ResourceDynType Os_Resource_Core0_Isr_OsResource0_Dyn;
/* Resource dynamic parameters end. */

/* Scheduler dynamic parameters start. */
static Os_BitMapDynType OsCfg_Scheduler_BitMap_OsCore0_Dyn;
static Os_SchedulerDynType OsCfg_Scheduler_OsCore0_Dyn;
static Os_BitMapDataType OsCfg_BitMap_L1Data_OsCore0_Dyn[OS_BITMAP_LENGTH(OS_CFG_NUM_TASKQUEUES_OSCORE0)];

Os_TaskDynType* OsCfg_TaskQueueNodes0_Data_OsCore0[OS_CFG_SIZE_TASKQUEUE0_OSCORE0];
Os_TaskDynType* OsCfg_TaskQueueNodes1_Data_OsCore0[OS_CFG_SIZE_TASKQUEUE1_OSCORE0];
Os_TaskDynType* OsCfg_TaskQueueNodes2_Data_OsCore0[OS_CFG_SIZE_TASKQUEUE2_OSCORE0];
Os_TaskDynType* OsCfg_TaskQueueNodes3_Data_OsCore0[OS_CFG_SIZE_TASKQUEUE3_OSCORE0];
Os_TaskDynType* OsCfg_TaskQueueNodes4_Data_OsCore0[OS_CFG_SIZE_TASKQUEUE4_OSCORE0];
Os_TaskDynType* OsCfg_TaskQueueNodes5_Data_OsCore0[OS_CFG_SIZE_TASKQUEUE5_OSCORE0];
Os_TaskDynType* OsCfg_TaskQueueNodes6_Data_OsCore0[OS_CFG_SIZE_TASKQUEUE6_OSCORE0];
Os_TaskDynType* OsCfg_TaskQueueNodes7_Data_OsCore0[OS_CFG_SIZE_TASKQUEUE7_OSCORE0];
Os_TaskDynType* OsCfg_TaskQueueNodes8_Data_OsCore0[OS_CFG_SIZE_TASKQUEUE8_OSCORE0];
Os_TaskDynType* OsCfg_TaskQueueNodes9_Data_OsCore0[OS_CFG_SIZE_TASKQUEUE9_OSCORE0];
Os_TaskDynType* OsCfg_TaskQueueNodes10_Data_OsCore0[OS_CFG_SIZE_TASKQUEUE10_OSCORE0];

Os_TaskQueType OsCfg_TaskQueueNodes0_OsCore0;
Os_TaskQueType OsCfg_TaskQueueNodes1_OsCore0;
Os_TaskQueType OsCfg_TaskQueueNodes2_OsCore0;
Os_TaskQueType OsCfg_TaskQueueNodes3_OsCore0;
Os_TaskQueType OsCfg_TaskQueueNodes4_OsCore0;
Os_TaskQueType OsCfg_TaskQueueNodes5_OsCore0;
Os_TaskQueType OsCfg_TaskQueueNodes6_OsCore0;
Os_TaskQueType OsCfg_TaskQueueNodes7_OsCore0;
Os_TaskQueType OsCfg_TaskQueueNodes8_OsCore0;
Os_TaskQueType OsCfg_TaskQueueNodes9_OsCore0;
Os_TaskQueType OsCfg_TaskQueueNodes10_OsCore0;

static Os_PriQueueNodeType* Os_PriQueueNode_SystemTimer_Core0_0[OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE0 + 1];
static Os_PriQueueNodeType* Os_PriQueueNode_SystemTimer_Core0_1[OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE0 + 1];

/* Scheduler dynamic parameters end. */

#define OS_STOP_SEC_VAR_OSCORE0 
#include "Os_MemMap.h"

#define OS_START_SEC_INITVAR_OSCORE0 
#include "Os_MemMap.h"
/* Scheduler init dynamic parameters start. */
Os_TaskQueType* OsCfg_Scheduler_OsCore0_TaskQueues[OS_CFG_NUM_TASKQUEUES_OSCORE0] =
{
    &OsCfg_TaskQueueNodes0_OsCore0,
    &OsCfg_TaskQueueNodes1_OsCore0,
    &OsCfg_TaskQueueNodes2_OsCore0,
    &OsCfg_TaskQueueNodes3_OsCore0,
    &OsCfg_TaskQueueNodes4_OsCore0,
    &OsCfg_TaskQueueNodes5_OsCore0,
    &OsCfg_TaskQueueNodes6_OsCore0,
    &OsCfg_TaskQueueNodes7_OsCore0,
    &OsCfg_TaskQueueNodes8_OsCore0,
    &OsCfg_TaskQueueNodes9_OsCore0,
    &OsCfg_TaskQueueNodes10_OsCore0
};


Os_CntExpListCfgType Os_CntExpList_SystemTimer_Core0 =
{
    {
        {
            /* cntExpList[0]->priQueueNode       = */ Os_PriQueueNode_SystemTimer_Core0_0,
            /* cntExpList[0]->priQueueUseCounter = */ 0U,
            /* cntExpList[0]->priQueueSize       = */ OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE0
        },
        {
            /* cntExpList[1]->priQueueNode       = */ Os_PriQueueNode_SystemTimer_Core0_1,
            /* cntExpList[1]->priQueueUseCounter = */ 0U,
            /* cntExpList[1]->priQueueSize       = */ OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE0
        }
    },
    /* cntExplistMux = */ 0U
};
/* Scheduler init dynamic parameters end. */

#define OS_STOP_SEC_INITVAR_OSCORE0 
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_OSCORE1 
#include "Os_MemMap.h"
/* Core dynamic parameters start. */
static Os_CoreDynType OsCfg_Core_OsCore1_Dyn;

static Os_CoreIntStateType OsCfg_IntState_OsCore1_Dyn;

/* Core dynamic parameters end. */ 

/* App dynamic parameters start. */
static Os_AppDynType OsCfg_Appl_SystemApplication_OsCore_Core1_Dyn;
static Os_AppDynType OsCfg_Appl_App1_Application_Core1_QM_Dyn;
static Os_AppDynType OsCfg_Appl_Bsw_Application_Core1_QM_Dyn;

/* App dynamic parameters end. */

/* Task dynamic parameters start. */
static Os_TaskDynType OsCfg_Task_Default_Init_Task_Core1_Dyn;
static Os_TaskDynType OsCfg_Task_Idle_Task_Core1_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_10ms_Core1_QM_Dyn;
static Os_TaskDynType OsCfg_Task_SWC_Init_Task_Core1_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_1ms_Core1_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_5ms_Core1_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_20ms_Core1_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_50ms_Core1_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_100ms_Core1_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_UDS_Core1_QM_Dyn;
static Os_TaskDynType OsCfg_Task_Bsw_Task_10ms_Core1_QM_Dyn;

/* Task dynamic parameters end. */

/* Isr dynamic parameters start. */
static Os_IsrDynType OsCfg_Isr_CounterIsr_SystemTimer_Core1_Dyn;
static Os_IsrDynType OsCfg_Isr_MultiCommIsr_Core1_Dyn;

/* Isr dynamic parameters end. */

/* Counter dynamic parameters start. */
static Os_CounterSwDynType OsCfg_Counter_SystemTimer_Core1_Dyn;

/* Counter dynamic parameters end. */

/* Alarm dynamic parameters start. */
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_10ms_Core1_QM_10ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_1ms_Core1_QM_1ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_5ms_Core1_QM_5ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_20ms_Core1_QM_20ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_50ms_Core1_QM_50ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_100ms_Core1_QM_100ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core1_QM_10ms_Dyn;

/* Alarm dynamic parameters end. */

/* Resource dynamic parameters start. */
static Os_ResourceDynType Os_Resource_Core1_Task_OsResource0_Dyn;
static Os_ResourceDynType Os_Resource_Core1_Isr_OsResource0_Dyn;
/* Resource dynamic parameters end. */

/* Scheduler dynamic parameters start. */
static Os_BitMapDynType OsCfg_Scheduler_BitMap_OsCore1_Dyn;
static Os_SchedulerDynType OsCfg_Scheduler_OsCore1_Dyn;
static Os_BitMapDataType OsCfg_BitMap_L1Data_OsCore1_Dyn[OS_BITMAP_LENGTH(OS_CFG_NUM_TASKQUEUES_OSCORE1)];

Os_TaskDynType* OsCfg_TaskQueueNodes0_Data_OsCore1[OS_CFG_SIZE_TASKQUEUE0_OSCORE1];
Os_TaskDynType* OsCfg_TaskQueueNodes1_Data_OsCore1[OS_CFG_SIZE_TASKQUEUE1_OSCORE1];
Os_TaskDynType* OsCfg_TaskQueueNodes2_Data_OsCore1[OS_CFG_SIZE_TASKQUEUE2_OSCORE1];
Os_TaskDynType* OsCfg_TaskQueueNodes3_Data_OsCore1[OS_CFG_SIZE_TASKQUEUE3_OSCORE1];
Os_TaskDynType* OsCfg_TaskQueueNodes4_Data_OsCore1[OS_CFG_SIZE_TASKQUEUE4_OSCORE1];
Os_TaskDynType* OsCfg_TaskQueueNodes5_Data_OsCore1[OS_CFG_SIZE_TASKQUEUE5_OSCORE1];
Os_TaskDynType* OsCfg_TaskQueueNodes6_Data_OsCore1[OS_CFG_SIZE_TASKQUEUE6_OSCORE1];
Os_TaskDynType* OsCfg_TaskQueueNodes7_Data_OsCore1[OS_CFG_SIZE_TASKQUEUE7_OSCORE1];
Os_TaskDynType* OsCfg_TaskQueueNodes8_Data_OsCore1[OS_CFG_SIZE_TASKQUEUE8_OSCORE1];
Os_TaskDynType* OsCfg_TaskQueueNodes9_Data_OsCore1[OS_CFG_SIZE_TASKQUEUE9_OSCORE1];
Os_TaskDynType* OsCfg_TaskQueueNodes10_Data_OsCore1[OS_CFG_SIZE_TASKQUEUE10_OSCORE1];

Os_TaskQueType OsCfg_TaskQueueNodes0_OsCore1;
Os_TaskQueType OsCfg_TaskQueueNodes1_OsCore1;
Os_TaskQueType OsCfg_TaskQueueNodes2_OsCore1;
Os_TaskQueType OsCfg_TaskQueueNodes3_OsCore1;
Os_TaskQueType OsCfg_TaskQueueNodes4_OsCore1;
Os_TaskQueType OsCfg_TaskQueueNodes5_OsCore1;
Os_TaskQueType OsCfg_TaskQueueNodes6_OsCore1;
Os_TaskQueType OsCfg_TaskQueueNodes7_OsCore1;
Os_TaskQueType OsCfg_TaskQueueNodes8_OsCore1;
Os_TaskQueType OsCfg_TaskQueueNodes9_OsCore1;
Os_TaskQueType OsCfg_TaskQueueNodes10_OsCore1;

static Os_PriQueueNodeType* Os_PriQueueNode_SystemTimer_Core1_0[OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE1 + 1];
static Os_PriQueueNodeType* Os_PriQueueNode_SystemTimer_Core1_1[OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE1 + 1];

/* Scheduler dynamic parameters end. */

#define OS_STOP_SEC_VAR_OSCORE1 
#include "Os_MemMap.h"

#define OS_START_SEC_INITVAR_OSCORE1 
#include "Os_MemMap.h"
/* Scheduler init dynamic parameters start. */
Os_TaskQueType* OsCfg_Scheduler_OsCore1_TaskQueues[OS_CFG_NUM_TASKQUEUES_OSCORE1] =
{
    &OsCfg_TaskQueueNodes0_OsCore1,
    &OsCfg_TaskQueueNodes1_OsCore1,
    &OsCfg_TaskQueueNodes2_OsCore1,
    &OsCfg_TaskQueueNodes3_OsCore1,
    &OsCfg_TaskQueueNodes4_OsCore1,
    &OsCfg_TaskQueueNodes5_OsCore1,
    &OsCfg_TaskQueueNodes6_OsCore1,
    &OsCfg_TaskQueueNodes7_OsCore1,
    &OsCfg_TaskQueueNodes8_OsCore1,
    &OsCfg_TaskQueueNodes9_OsCore1,
    &OsCfg_TaskQueueNodes10_OsCore1
};


Os_CntExpListCfgType Os_CntExpList_SystemTimer_Core1 =
{
    {
        {
            /* cntExpList[0]->priQueueNode       = */ Os_PriQueueNode_SystemTimer_Core1_0,
            /* cntExpList[0]->priQueueUseCounter = */ 0U,
            /* cntExpList[0]->priQueueSize       = */ OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE1
        },
        {
            /* cntExpList[1]->priQueueNode       = */ Os_PriQueueNode_SystemTimer_Core1_1,
            /* cntExpList[1]->priQueueUseCounter = */ 0U,
            /* cntExpList[1]->priQueueSize       = */ OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE1
        }
    },
    /* cntExplistMux = */ 0U
};
/* Scheduler init dynamic parameters end. */

#define OS_STOP_SEC_INITVAR_OSCORE1 
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_OSCORE2 
#include "Os_MemMap.h"
/* Core dynamic parameters start. */
static Os_CoreDynType OsCfg_Core_OsCore2_Dyn;

static Os_CoreIntStateType OsCfg_IntState_OsCore2_Dyn;

/* Core dynamic parameters end. */ 

/* App dynamic parameters start. */
static Os_AppDynType OsCfg_Appl_SystemApplication_OsCore_Core2_Dyn;
static Os_AppDynType OsCfg_Appl_App1_Application_Core2_QM_Dyn;
static Os_AppDynType OsCfg_Appl_Bsw_Application_Core2_QM_Dyn;

/* App dynamic parameters end. */

/* Task dynamic parameters start. */
static Os_TaskDynType OsCfg_Task_Default_Init_Task_Core2_Dyn;
static Os_TaskDynType OsCfg_Task_Idle_Task_Core2_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_50ms_Core2_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_100ms_Core2_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_10ms_Core2_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_1000ms_Core2_QM_Dyn;
static Os_TaskDynType OsCfg_Task_SWC_Init_Task_Core2_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_1ms_Core2_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_5ms_Core2_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_20ms_Core2_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task0_UDS_Core2_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task1_UDS_Core2_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task2_UDS_Core2_QM_Dyn;
static Os_TaskDynType OsCfg_Task_Bsw_Task_10ms_Core2_QM_Dyn;

/* Task dynamic parameters end. */

/* Isr dynamic parameters start. */
static Os_IsrDynType OsCfg_Isr_CounterIsr_SystemTimer_Core2_Dyn;
static Os_IsrDynType OsCfg_Isr_MultiCommIsr_Core2_Dyn;

/* Isr dynamic parameters end. */

/* Counter dynamic parameters start. */
static Os_CounterSwDynType OsCfg_Counter_SystemTimer_Core2_Dyn;

/* Counter dynamic parameters end. */

/* Alarm dynamic parameters start. */
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_50ms_Core2_QM_50ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_100ms_Core2_QM_100ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_10ms_Core2_QM_10ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_1000ms_Core2_QM_1000ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_1ms_Core2_QM_1ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_5ms_Core2_QM_5ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_20ms_Core2_QM_20ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core2_QM_10ms_Dyn;

/* Alarm dynamic parameters end. */

/* Resource dynamic parameters start. */
static Os_ResourceDynType Os_Resource_Core2_Task_OsResource0_Dyn;
static Os_ResourceDynType Os_Resource_Core2_Isr_OsResource0_Dyn;
/* Resource dynamic parameters end. */

/* Scheduler dynamic parameters start. */
static Os_BitMapDynType OsCfg_Scheduler_BitMap_OsCore2_Dyn;
static Os_SchedulerDynType OsCfg_Scheduler_OsCore2_Dyn;
static Os_BitMapDataType OsCfg_BitMap_L1Data_OsCore2_Dyn[OS_BITMAP_LENGTH(OS_CFG_NUM_TASKQUEUES_OSCORE2)];

Os_TaskDynType* OsCfg_TaskQueueNodes0_Data_OsCore2[OS_CFG_SIZE_TASKQUEUE0_OSCORE2];
Os_TaskDynType* OsCfg_TaskQueueNodes1_Data_OsCore2[OS_CFG_SIZE_TASKQUEUE1_OSCORE2];
Os_TaskDynType* OsCfg_TaskQueueNodes2_Data_OsCore2[OS_CFG_SIZE_TASKQUEUE2_OSCORE2];
Os_TaskDynType* OsCfg_TaskQueueNodes3_Data_OsCore2[OS_CFG_SIZE_TASKQUEUE3_OSCORE2];
Os_TaskDynType* OsCfg_TaskQueueNodes4_Data_OsCore2[OS_CFG_SIZE_TASKQUEUE4_OSCORE2];
Os_TaskDynType* OsCfg_TaskQueueNodes5_Data_OsCore2[OS_CFG_SIZE_TASKQUEUE5_OSCORE2];
Os_TaskDynType* OsCfg_TaskQueueNodes6_Data_OsCore2[OS_CFG_SIZE_TASKQUEUE6_OSCORE2];
Os_TaskDynType* OsCfg_TaskQueueNodes7_Data_OsCore2[OS_CFG_SIZE_TASKQUEUE7_OSCORE2];
Os_TaskDynType* OsCfg_TaskQueueNodes8_Data_OsCore2[OS_CFG_SIZE_TASKQUEUE8_OSCORE2];
Os_TaskDynType* OsCfg_TaskQueueNodes9_Data_OsCore2[OS_CFG_SIZE_TASKQUEUE9_OSCORE2];
Os_TaskDynType* OsCfg_TaskQueueNodes10_Data_OsCore2[OS_CFG_SIZE_TASKQUEUE10_OSCORE2];
Os_TaskDynType* OsCfg_TaskQueueNodes11_Data_OsCore2[OS_CFG_SIZE_TASKQUEUE11_OSCORE2];
Os_TaskDynType* OsCfg_TaskQueueNodes12_Data_OsCore2[OS_CFG_SIZE_TASKQUEUE12_OSCORE2];
Os_TaskDynType* OsCfg_TaskQueueNodes13_Data_OsCore2[OS_CFG_SIZE_TASKQUEUE13_OSCORE2];

Os_TaskQueType OsCfg_TaskQueueNodes0_OsCore2;
Os_TaskQueType OsCfg_TaskQueueNodes1_OsCore2;
Os_TaskQueType OsCfg_TaskQueueNodes2_OsCore2;
Os_TaskQueType OsCfg_TaskQueueNodes3_OsCore2;
Os_TaskQueType OsCfg_TaskQueueNodes4_OsCore2;
Os_TaskQueType OsCfg_TaskQueueNodes5_OsCore2;
Os_TaskQueType OsCfg_TaskQueueNodes6_OsCore2;
Os_TaskQueType OsCfg_TaskQueueNodes7_OsCore2;
Os_TaskQueType OsCfg_TaskQueueNodes8_OsCore2;
Os_TaskQueType OsCfg_TaskQueueNodes9_OsCore2;
Os_TaskQueType OsCfg_TaskQueueNodes10_OsCore2;
Os_TaskQueType OsCfg_TaskQueueNodes11_OsCore2;
Os_TaskQueType OsCfg_TaskQueueNodes12_OsCore2;
Os_TaskQueType OsCfg_TaskQueueNodes13_OsCore2;

static Os_PriQueueNodeType* Os_PriQueueNode_SystemTimer_Core2_0[OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE2 + 1];
static Os_PriQueueNodeType* Os_PriQueueNode_SystemTimer_Core2_1[OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE2 + 1];

/* Scheduler dynamic parameters end. */

#define OS_STOP_SEC_VAR_OSCORE2 
#include "Os_MemMap.h"

#define OS_START_SEC_INITVAR_OSCORE2 
#include "Os_MemMap.h"
/* Scheduler init dynamic parameters start. */
Os_TaskQueType* OsCfg_Scheduler_OsCore2_TaskQueues[OS_CFG_NUM_TASKQUEUES_OSCORE2] =
{
    &OsCfg_TaskQueueNodes0_OsCore2,
    &OsCfg_TaskQueueNodes1_OsCore2,
    &OsCfg_TaskQueueNodes2_OsCore2,
    &OsCfg_TaskQueueNodes3_OsCore2,
    &OsCfg_TaskQueueNodes4_OsCore2,
    &OsCfg_TaskQueueNodes5_OsCore2,
    &OsCfg_TaskQueueNodes6_OsCore2,
    &OsCfg_TaskQueueNodes7_OsCore2,
    &OsCfg_TaskQueueNodes8_OsCore2,
    &OsCfg_TaskQueueNodes9_OsCore2,
    &OsCfg_TaskQueueNodes10_OsCore2,
    &OsCfg_TaskQueueNodes11_OsCore2,
    &OsCfg_TaskQueueNodes12_OsCore2,
    &OsCfg_TaskQueueNodes13_OsCore2
};


Os_CntExpListCfgType Os_CntExpList_SystemTimer_Core2 =
{
    {
        {
            /* cntExpList[0]->priQueueNode       = */ Os_PriQueueNode_SystemTimer_Core2_0,
            /* cntExpList[0]->priQueueUseCounter = */ 0U,
            /* cntExpList[0]->priQueueSize       = */ OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE2
        },
        {
            /* cntExpList[1]->priQueueNode       = */ Os_PriQueueNode_SystemTimer_Core2_1,
            /* cntExpList[1]->priQueueUseCounter = */ 0U,
            /* cntExpList[1]->priQueueSize       = */ OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE2
        }
    },
    /* cntExplistMux = */ 0U
};
/* Scheduler init dynamic parameters end. */

#define OS_STOP_SEC_INITVAR_OSCORE2 
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_OSCORE3 
#include "Os_MemMap.h"
/* Core dynamic parameters start. */
static Os_CoreDynType OsCfg_Core_OsCore3_Dyn;

static Os_CoreIntStateType OsCfg_IntState_OsCore3_Dyn;

/* Core dynamic parameters end. */ 

/* App dynamic parameters start. */
static Os_AppDynType OsCfg_Appl_SystemApplication_OsCore_Core3_Dyn;
static Os_AppDynType OsCfg_Appl_App1_Application_Core3_QM_Dyn;
static Os_AppDynType OsCfg_Appl_Bsw_Application_Core3_QM_Dyn;

/* App dynamic parameters end. */

/* Task dynamic parameters start. */
static Os_TaskDynType OsCfg_Task_Default_Init_Task_Core3_Dyn;
static Os_TaskDynType OsCfg_Task_Idle_Task_Core3_Dyn;
static Os_TaskDynType OsCfg_Task_SWC_Init_Task_Core3_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_UDS_Core3_QM_Dyn;
static Os_TaskDynType OsCfg_Task_Task_1ms_Core3_QM_Dyn;
static Os_TaskDynType OsCfg_Task_Task_100us_Core3_QM_Dyn;
static Os_TaskDynType OsCfg_Task_Task_5ms_Core3_QM_Dyn;

/* Task dynamic parameters end. */

/* Isr dynamic parameters start. */
static Os_IsrDynType OsCfg_Isr_CounterIsr_SystemTimer_Core3_Dyn;
static Os_IsrDynType OsCfg_Isr_MultiCommIsr_Core3_Dyn;

/* Isr dynamic parameters end. */

/* Counter dynamic parameters start. */
static Os_CounterSwDynType OsCfg_Counter_SystemTimer_Core3_Dyn;

/* Counter dynamic parameters end. */

/* Alarm dynamic parameters start. */
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_Task_1ms_Core3_QM_1ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_Task_100us_Core3_QM_100us_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_Task_5ms_Core3_QM_5ms_Dyn;

/* Alarm dynamic parameters end. */

/* Resource dynamic parameters start. */
static Os_ResourceDynType Os_Resource_Core3_Task_OsResource0_Dyn;
static Os_ResourceDynType Os_Resource_Core3_Isr_OsResource0_Dyn;
/* Resource dynamic parameters end. */

/* Scheduler dynamic parameters start. */
static Os_BitMapDynType OsCfg_Scheduler_BitMap_OsCore3_Dyn;
static Os_SchedulerDynType OsCfg_Scheduler_OsCore3_Dyn;
static Os_BitMapDataType OsCfg_BitMap_L1Data_OsCore3_Dyn[OS_BITMAP_LENGTH(OS_CFG_NUM_TASKQUEUES_OSCORE3)];

Os_TaskDynType* OsCfg_TaskQueueNodes0_Data_OsCore3[OS_CFG_SIZE_TASKQUEUE0_OSCORE3];
Os_TaskDynType* OsCfg_TaskQueueNodes1_Data_OsCore3[OS_CFG_SIZE_TASKQUEUE1_OSCORE3];
Os_TaskDynType* OsCfg_TaskQueueNodes2_Data_OsCore3[OS_CFG_SIZE_TASKQUEUE2_OSCORE3];
Os_TaskDynType* OsCfg_TaskQueueNodes3_Data_OsCore3[OS_CFG_SIZE_TASKQUEUE3_OSCORE3];
Os_TaskDynType* OsCfg_TaskQueueNodes4_Data_OsCore3[OS_CFG_SIZE_TASKQUEUE4_OSCORE3];
Os_TaskDynType* OsCfg_TaskQueueNodes5_Data_OsCore3[OS_CFG_SIZE_TASKQUEUE5_OSCORE3];
Os_TaskDynType* OsCfg_TaskQueueNodes6_Data_OsCore3[OS_CFG_SIZE_TASKQUEUE6_OSCORE3];

Os_TaskQueType OsCfg_TaskQueueNodes0_OsCore3;
Os_TaskQueType OsCfg_TaskQueueNodes1_OsCore3;
Os_TaskQueType OsCfg_TaskQueueNodes2_OsCore3;
Os_TaskQueType OsCfg_TaskQueueNodes3_OsCore3;
Os_TaskQueType OsCfg_TaskQueueNodes4_OsCore3;
Os_TaskQueType OsCfg_TaskQueueNodes5_OsCore3;
Os_TaskQueType OsCfg_TaskQueueNodes6_OsCore3;

static Os_PriQueueNodeType* Os_PriQueueNode_SystemTimer_Core3_0[OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE3 + 1];
static Os_PriQueueNodeType* Os_PriQueueNode_SystemTimer_Core3_1[OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE3 + 1];

/* Scheduler dynamic parameters end. */

#define OS_STOP_SEC_VAR_OSCORE3 
#include "Os_MemMap.h"

#define OS_START_SEC_INITVAR_OSCORE3 
#include "Os_MemMap.h"
/* Scheduler init dynamic parameters start. */
Os_TaskQueType* OsCfg_Scheduler_OsCore3_TaskQueues[OS_CFG_NUM_TASKQUEUES_OSCORE3] =
{
    &OsCfg_TaskQueueNodes0_OsCore3,
    &OsCfg_TaskQueueNodes1_OsCore3,
    &OsCfg_TaskQueueNodes2_OsCore3,
    &OsCfg_TaskQueueNodes3_OsCore3,
    &OsCfg_TaskQueueNodes4_OsCore3,
    &OsCfg_TaskQueueNodes5_OsCore3,
    &OsCfg_TaskQueueNodes6_OsCore3
};


Os_CntExpListCfgType Os_CntExpList_SystemTimer_Core3 =
{
    {
        {
            /* cntExpList[0]->priQueueNode       = */ Os_PriQueueNode_SystemTimer_Core3_0,
            /* cntExpList[0]->priQueueUseCounter = */ 0U,
            /* cntExpList[0]->priQueueSize       = */ OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE3
        },
        {
            /* cntExpList[1]->priQueueNode       = */ Os_PriQueueNode_SystemTimer_Core3_1,
            /* cntExpList[1]->priQueueUseCounter = */ 0U,
            /* cntExpList[1]->priQueueSize       = */ OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE3
        }
    },
    /* cntExplistMux = */ 0U
};
/* Scheduler init dynamic parameters end. */

#define OS_STOP_SEC_INITVAR_OSCORE3 
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_OSCORE4 
#include "Os_MemMap.h"
/* Core dynamic parameters start. */
static Os_CoreDynType OsCfg_Core_OsCore4_Dyn;

static Os_CoreIntStateType OsCfg_IntState_OsCore4_Dyn;

/* Core dynamic parameters end. */ 

/* App dynamic parameters start. */
static Os_AppDynType OsCfg_Appl_SystemApplication_OsCore_Core4_Dyn;
static Os_AppDynType OsCfg_Appl_App1_Application_Core4_QM_Dyn;
static Os_AppDynType OsCfg_Appl_Bsw_Application_Core4_QM_Dyn;

/* App dynamic parameters end. */

/* Task dynamic parameters start. */
static Os_TaskDynType OsCfg_Task_Default_Init_Task_Core4_Dyn;
static Os_TaskDynType OsCfg_Task_Idle_Task_Core4_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_1ms_Core4_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_5ms_Core4_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_10ms_Core4_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_20ms_Core4_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_50ms_Core4_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_100ms_Core4_QM_Dyn;
static Os_TaskDynType OsCfg_Task_SWC_Init_Task_Core4_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_UDS_Core4_QM_Dyn;
static Os_TaskDynType OsCfg_Task_Bsw_Task_100ms_Core4_QM_Dyn;
static Os_TaskDynType OsCfg_Task_Bsw_Task_50ms_Core4_QM_Dyn;
static Os_TaskDynType OsCfg_Task_Bsw_Task_20ms_Core4_QM_Dyn;
static Os_TaskDynType OsCfg_Task_Bsw_Task_10ms_Core4_QM_Dyn;
static Os_TaskDynType OsCfg_Task_Bsw_Task_5ms_Core4_QM_Dyn;
static Os_TaskDynType OsCfg_Task_Bsw_Task_1ms_Core4_QM_Dyn;
static Os_TaskDynType OsCfg_Task_Bsw_Task_5ms_Core4_Offest_QM_Dyn;
static Os_TaskDynType OsCfg_Task_Bsw_Task_10ms_Core4_Offest_QM_Dyn;

/* Task dynamic parameters end. */

/* Isr dynamic parameters start. */
static Os_IsrDynType OsCfg_Isr_CounterIsr_SystemTimer_Core4_Dyn;
static Os_IsrDynType OsCfg_Isr_MultiCommIsr_Core4_Dyn;
static Os_IsrDynType OsCfg_Isr_Os_ISR_450_MCAN11_CH1_Dyn;
static Os_IsrDynType OsCfg_Isr_Os_ISR_449_MCAN11_CH0_Dyn;
static Os_IsrDynType OsCfg_Isr_Os_ISR_699_MCAN6_CH1_Dyn;
static Os_IsrDynType OsCfg_Isr_Os_ISR_698_MCAN6_CH0_Dyn;
static Os_IsrDynType OsCfg_Isr_Os_ISR_689_MCAN1_CH1_Dyn;
static Os_IsrDynType OsCfg_Isr_Os_ISR_688_MCAN1_CH0_Dyn;
static Os_IsrDynType OsCfg_Isr_Os_ISR_446_MCAN9_CH1_Dyn;
static Os_IsrDynType OsCfg_Isr_Os_ISR_445_MCAN9_CH0_Dyn;
static Os_IsrDynType OsCfg_Isr_Os_ISR_693_MCAN3_CH1_Dyn;
static Os_IsrDynType OsCfg_Isr_Os_ISR_692_MCAN3_CH0_Dyn;
static Os_IsrDynType OsCfg_Isr_Os_ISR_691_MCAN2_CH1_Dyn;
static Os_IsrDynType OsCfg_Isr_Os_ISR_690_MCAN2_CH0_Dyn;
static Os_IsrDynType OsCfg_Isr_Os_ISR_701_MCAN7_CH1_Dyn;
static Os_IsrDynType OsCfg_Isr_Os_ISR_700_MCAN7_CH0_Dyn;
static Os_IsrDynType OsCfg_Isr_Os_ISR_698_LINTX_CH6_Dyn;
static Os_IsrDynType OsCfg_Isr_Os_ISR_698_LINRX_CH6_Dyn;

/* Isr dynamic parameters end. */

/* Counter dynamic parameters start. */
static Os_CounterSwDynType OsCfg_Counter_SystemTimer_Core4_Dyn;

/* Counter dynamic parameters end. */

/* Alarm dynamic parameters start. */
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_1ms_Core4_QM_1ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_5ms_Core4_QM_5ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_10ms_Core4_QM_10ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_20ms_Core4_QM_20ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_50ms_Core4_QM_50ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_100ms_Core4_QM_100ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_100ms_Core4_QM_100ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_50ms_Core4_QM_50ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_20ms_Core4_QM_20ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core4_QM_10ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_5ms_Core4_QM_5ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_1ms_Core4_QM_1ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core4_Offest_QM_10ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_5ms_Core4_Offest_QM_5ms_Dyn;

/* Alarm dynamic parameters end. */

/* Resource dynamic parameters start. */
static Os_ResourceDynType Os_Resource_Core4_Task_OsResource0_Dyn;
static Os_ResourceDynType Os_Resource_Core4_Isr_OsResource0_Dyn;
/* Resource dynamic parameters end. */

/* Scheduler dynamic parameters start. */
static Os_BitMapDynType OsCfg_Scheduler_BitMap_OsCore4_Dyn;
static Os_SchedulerDynType OsCfg_Scheduler_OsCore4_Dyn;
static Os_BitMapDataType OsCfg_BitMap_L1Data_OsCore4_Dyn[OS_BITMAP_LENGTH(OS_CFG_NUM_TASKQUEUES_OSCORE4)];

Os_TaskDynType* OsCfg_TaskQueueNodes0_Data_OsCore4[OS_CFG_SIZE_TASKQUEUE0_OSCORE4];
Os_TaskDynType* OsCfg_TaskQueueNodes1_Data_OsCore4[OS_CFG_SIZE_TASKQUEUE1_OSCORE4];
Os_TaskDynType* OsCfg_TaskQueueNodes2_Data_OsCore4[OS_CFG_SIZE_TASKQUEUE2_OSCORE4];
Os_TaskDynType* OsCfg_TaskQueueNodes3_Data_OsCore4[OS_CFG_SIZE_TASKQUEUE3_OSCORE4];
Os_TaskDynType* OsCfg_TaskQueueNodes4_Data_OsCore4[OS_CFG_SIZE_TASKQUEUE4_OSCORE4];
Os_TaskDynType* OsCfg_TaskQueueNodes5_Data_OsCore4[OS_CFG_SIZE_TASKQUEUE5_OSCORE4];
Os_TaskDynType* OsCfg_TaskQueueNodes6_Data_OsCore4[OS_CFG_SIZE_TASKQUEUE6_OSCORE4];
Os_TaskDynType* OsCfg_TaskQueueNodes7_Data_OsCore4[OS_CFG_SIZE_TASKQUEUE7_OSCORE4];
Os_TaskDynType* OsCfg_TaskQueueNodes8_Data_OsCore4[OS_CFG_SIZE_TASKQUEUE8_OSCORE4];
Os_TaskDynType* OsCfg_TaskQueueNodes9_Data_OsCore4[OS_CFG_SIZE_TASKQUEUE9_OSCORE4];
Os_TaskDynType* OsCfg_TaskQueueNodes10_Data_OsCore4[OS_CFG_SIZE_TASKQUEUE10_OSCORE4];
Os_TaskDynType* OsCfg_TaskQueueNodes11_Data_OsCore4[OS_CFG_SIZE_TASKQUEUE11_OSCORE4];
Os_TaskDynType* OsCfg_TaskQueueNodes12_Data_OsCore4[OS_CFG_SIZE_TASKQUEUE12_OSCORE4];
Os_TaskDynType* OsCfg_TaskQueueNodes13_Data_OsCore4[OS_CFG_SIZE_TASKQUEUE13_OSCORE4];
Os_TaskDynType* OsCfg_TaskQueueNodes14_Data_OsCore4[OS_CFG_SIZE_TASKQUEUE14_OSCORE4];
Os_TaskDynType* OsCfg_TaskQueueNodes15_Data_OsCore4[OS_CFG_SIZE_TASKQUEUE15_OSCORE4];
Os_TaskDynType* OsCfg_TaskQueueNodes16_Data_OsCore4[OS_CFG_SIZE_TASKQUEUE16_OSCORE4];
Os_TaskDynType* OsCfg_TaskQueueNodes17_Data_OsCore4[OS_CFG_SIZE_TASKQUEUE17_OSCORE4];

Os_TaskQueType OsCfg_TaskQueueNodes0_OsCore4;
Os_TaskQueType OsCfg_TaskQueueNodes1_OsCore4;
Os_TaskQueType OsCfg_TaskQueueNodes2_OsCore4;
Os_TaskQueType OsCfg_TaskQueueNodes3_OsCore4;
Os_TaskQueType OsCfg_TaskQueueNodes4_OsCore4;
Os_TaskQueType OsCfg_TaskQueueNodes5_OsCore4;
Os_TaskQueType OsCfg_TaskQueueNodes6_OsCore4;
Os_TaskQueType OsCfg_TaskQueueNodes7_OsCore4;
Os_TaskQueType OsCfg_TaskQueueNodes8_OsCore4;
Os_TaskQueType OsCfg_TaskQueueNodes9_OsCore4;
Os_TaskQueType OsCfg_TaskQueueNodes10_OsCore4;
Os_TaskQueType OsCfg_TaskQueueNodes11_OsCore4;
Os_TaskQueType OsCfg_TaskQueueNodes12_OsCore4;
Os_TaskQueType OsCfg_TaskQueueNodes13_OsCore4;
Os_TaskQueType OsCfg_TaskQueueNodes14_OsCore4;
Os_TaskQueType OsCfg_TaskQueueNodes15_OsCore4;
Os_TaskQueType OsCfg_TaskQueueNodes16_OsCore4;
Os_TaskQueType OsCfg_TaskQueueNodes17_OsCore4;

static Os_PriQueueNodeType* Os_PriQueueNode_SystemTimer_Core4_0[OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE4 + 1];
static Os_PriQueueNodeType* Os_PriQueueNode_SystemTimer_Core4_1[OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE4 + 1];

/* Scheduler dynamic parameters end. */

#define OS_STOP_SEC_VAR_OSCORE4 
#include "Os_MemMap.h"

#define OS_START_SEC_INITVAR_OSCORE4 
#include "Os_MemMap.h"
/* Scheduler init dynamic parameters start. */
Os_TaskQueType* OsCfg_Scheduler_OsCore4_TaskQueues[OS_CFG_NUM_TASKQUEUES_OSCORE4] =
{
    &OsCfg_TaskQueueNodes0_OsCore4,
    &OsCfg_TaskQueueNodes1_OsCore4,
    &OsCfg_TaskQueueNodes2_OsCore4,
    &OsCfg_TaskQueueNodes3_OsCore4,
    &OsCfg_TaskQueueNodes4_OsCore4,
    &OsCfg_TaskQueueNodes5_OsCore4,
    &OsCfg_TaskQueueNodes6_OsCore4,
    &OsCfg_TaskQueueNodes7_OsCore4,
    &OsCfg_TaskQueueNodes8_OsCore4,
    &OsCfg_TaskQueueNodes9_OsCore4,
    &OsCfg_TaskQueueNodes10_OsCore4,
    &OsCfg_TaskQueueNodes11_OsCore4,
    &OsCfg_TaskQueueNodes12_OsCore4,
    &OsCfg_TaskQueueNodes13_OsCore4,
    &OsCfg_TaskQueueNodes14_OsCore4,
    &OsCfg_TaskQueueNodes15_OsCore4,
    &OsCfg_TaskQueueNodes16_OsCore4,
    &OsCfg_TaskQueueNodes17_OsCore4
};


Os_CntExpListCfgType Os_CntExpList_SystemTimer_Core4 =
{
    {
        {
            /* cntExpList[0]->priQueueNode       = */ Os_PriQueueNode_SystemTimer_Core4_0,
            /* cntExpList[0]->priQueueUseCounter = */ 0U,
            /* cntExpList[0]->priQueueSize       = */ OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE4
        },
        {
            /* cntExpList[1]->priQueueNode       = */ Os_PriQueueNode_SystemTimer_Core4_1,
            /* cntExpList[1]->priQueueUseCounter = */ 0U,
            /* cntExpList[1]->priQueueSize       = */ OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE4
        }
    },
    /* cntExplistMux = */ 0U
};
/* Scheduler init dynamic parameters end. */

#define OS_STOP_SEC_INITVAR_OSCORE4 
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_OSCORE5 
#include "Os_MemMap.h"
/* Core dynamic parameters start. */
static Os_CoreDynType OsCfg_Core_OsCore5_Dyn;

static Os_CoreIntStateType OsCfg_IntState_OsCore5_Dyn;

/* Core dynamic parameters end. */ 

/* App dynamic parameters start. */
static Os_AppDynType OsCfg_Appl_SystemApplication_OsCore_Core5_Dyn;
static Os_AppDynType OsCfg_Appl_App1_Application_Core5_QM_Dyn;
static Os_AppDynType OsCfg_Appl_Bsw_Application_Core5_QM_Dyn;

/* App dynamic parameters end. */

/* Task dynamic parameters start. */
static Os_TaskDynType OsCfg_Task_Default_Init_Task_Core5_Dyn;
static Os_TaskDynType OsCfg_Task_Idle_Task_Core5_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_1ms_Core5_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_5ms_Core5_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_10ms_Core5_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_20ms_Core5_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_50ms_Core5_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_100ms_Core5_QM_Dyn;
static Os_TaskDynType OsCfg_Task_SWC_Init_Task_Core5_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_UDS_Core5_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_200ms_Core5_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_500ms_Core5_QM_Dyn;
static Os_TaskDynType OsCfg_Task_App1_Task_1000ms_Core5_QM_Dyn;
static Os_TaskDynType OsCfg_Task_Bsw_Task_10ms_Core5_QM_Dyn;

/* Task dynamic parameters end. */

/* Isr dynamic parameters start. */
static Os_IsrDynType OsCfg_Isr_CounterIsr_SystemTimer_Core5_Dyn;
static Os_IsrDynType OsCfg_Isr_MultiCommIsr_Core5_Dyn;

/* Isr dynamic parameters end. */

/* Counter dynamic parameters start. */
static Os_CounterSwDynType OsCfg_Counter_SystemTimer_Core5_Dyn;

/* Counter dynamic parameters end. */

/* Alarm dynamic parameters start. */
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_1ms_Core5_QM_1ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_5ms_Core5_QM_5ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_10ms_Core5_QM_10ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_20ms_Core5_QM_20ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_50ms_Core5_QM_50ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_100ms_Core5_QM_100ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_200ms_Core5_QM_200ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_500ms_Core5_QM_500ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_App1_Task_1000ms_Core5_QM_1000ms_Dyn;
static Os_AlarmDynType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core5_QM_10ms_Dyn;

/* Alarm dynamic parameters end. */

/* Resource dynamic parameters start. */
static Os_ResourceDynType Os_Resource_Core5_Task_OsResource0_Dyn;
static Os_ResourceDynType Os_Resource_Core5_Isr_OsResource0_Dyn;
/* Resource dynamic parameters end. */

/* Scheduler dynamic parameters start. */
static Os_BitMapDynType OsCfg_Scheduler_BitMap_OsCore5_Dyn;
static Os_SchedulerDynType OsCfg_Scheduler_OsCore5_Dyn;
static Os_BitMapDataType OsCfg_BitMap_L1Data_OsCore5_Dyn[OS_BITMAP_LENGTH(OS_CFG_NUM_TASKQUEUES_OSCORE5)];

Os_TaskDynType* OsCfg_TaskQueueNodes0_Data_OsCore5[OS_CFG_SIZE_TASKQUEUE0_OSCORE5];
Os_TaskDynType* OsCfg_TaskQueueNodes1_Data_OsCore5[OS_CFG_SIZE_TASKQUEUE1_OSCORE5];
Os_TaskDynType* OsCfg_TaskQueueNodes2_Data_OsCore5[OS_CFG_SIZE_TASKQUEUE2_OSCORE5];
Os_TaskDynType* OsCfg_TaskQueueNodes3_Data_OsCore5[OS_CFG_SIZE_TASKQUEUE3_OSCORE5];
Os_TaskDynType* OsCfg_TaskQueueNodes4_Data_OsCore5[OS_CFG_SIZE_TASKQUEUE4_OSCORE5];
Os_TaskDynType* OsCfg_TaskQueueNodes5_Data_OsCore5[OS_CFG_SIZE_TASKQUEUE5_OSCORE5];
Os_TaskDynType* OsCfg_TaskQueueNodes6_Data_OsCore5[OS_CFG_SIZE_TASKQUEUE6_OSCORE5];
Os_TaskDynType* OsCfg_TaskQueueNodes7_Data_OsCore5[OS_CFG_SIZE_TASKQUEUE7_OSCORE5];
Os_TaskDynType* OsCfg_TaskQueueNodes8_Data_OsCore5[OS_CFG_SIZE_TASKQUEUE8_OSCORE5];
Os_TaskDynType* OsCfg_TaskQueueNodes9_Data_OsCore5[OS_CFG_SIZE_TASKQUEUE9_OSCORE5];
Os_TaskDynType* OsCfg_TaskQueueNodes10_Data_OsCore5[OS_CFG_SIZE_TASKQUEUE10_OSCORE5];
Os_TaskDynType* OsCfg_TaskQueueNodes11_Data_OsCore5[OS_CFG_SIZE_TASKQUEUE11_OSCORE5];
Os_TaskDynType* OsCfg_TaskQueueNodes12_Data_OsCore5[OS_CFG_SIZE_TASKQUEUE12_OSCORE5];
Os_TaskDynType* OsCfg_TaskQueueNodes13_Data_OsCore5[OS_CFG_SIZE_TASKQUEUE13_OSCORE5];

Os_TaskQueType OsCfg_TaskQueueNodes0_OsCore5;
Os_TaskQueType OsCfg_TaskQueueNodes1_OsCore5;
Os_TaskQueType OsCfg_TaskQueueNodes2_OsCore5;
Os_TaskQueType OsCfg_TaskQueueNodes3_OsCore5;
Os_TaskQueType OsCfg_TaskQueueNodes4_OsCore5;
Os_TaskQueType OsCfg_TaskQueueNodes5_OsCore5;
Os_TaskQueType OsCfg_TaskQueueNodes6_OsCore5;
Os_TaskQueType OsCfg_TaskQueueNodes7_OsCore5;
Os_TaskQueType OsCfg_TaskQueueNodes8_OsCore5;
Os_TaskQueType OsCfg_TaskQueueNodes9_OsCore5;
Os_TaskQueType OsCfg_TaskQueueNodes10_OsCore5;
Os_TaskQueType OsCfg_TaskQueueNodes11_OsCore5;
Os_TaskQueType OsCfg_TaskQueueNodes12_OsCore5;
Os_TaskQueType OsCfg_TaskQueueNodes13_OsCore5;

static Os_PriQueueNodeType* Os_PriQueueNode_SystemTimer_Core5_0[OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE5 + 1];
static Os_PriQueueNodeType* Os_PriQueueNode_SystemTimer_Core5_1[OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE5 + 1];

/* Scheduler dynamic parameters end. */

#define OS_STOP_SEC_VAR_OSCORE5 
#include "Os_MemMap.h"

#define OS_START_SEC_INITVAR_OSCORE5 
#include "Os_MemMap.h"
/* Scheduler init dynamic parameters start. */
Os_TaskQueType* OsCfg_Scheduler_OsCore5_TaskQueues[OS_CFG_NUM_TASKQUEUES_OSCORE5] =
{
    &OsCfg_TaskQueueNodes0_OsCore5,
    &OsCfg_TaskQueueNodes1_OsCore5,
    &OsCfg_TaskQueueNodes2_OsCore5,
    &OsCfg_TaskQueueNodes3_OsCore5,
    &OsCfg_TaskQueueNodes4_OsCore5,
    &OsCfg_TaskQueueNodes5_OsCore5,
    &OsCfg_TaskQueueNodes6_OsCore5,
    &OsCfg_TaskQueueNodes7_OsCore5,
    &OsCfg_TaskQueueNodes8_OsCore5,
    &OsCfg_TaskQueueNodes9_OsCore5,
    &OsCfg_TaskQueueNodes10_OsCore5,
    &OsCfg_TaskQueueNodes11_OsCore5,
    &OsCfg_TaskQueueNodes12_OsCore5,
    &OsCfg_TaskQueueNodes13_OsCore5
};


Os_CntExpListCfgType Os_CntExpList_SystemTimer_Core5 =
{
    {
        {
            /* cntExpList[0]->priQueueNode       = */ Os_PriQueueNode_SystemTimer_Core5_0,
            /* cntExpList[0]->priQueueUseCounter = */ 0U,
            /* cntExpList[0]->priQueueSize       = */ OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE5
        },
        {
            /* cntExpList[1]->priQueueNode       = */ Os_PriQueueNode_SystemTimer_Core5_1,
            /* cntExpList[1]->priQueueUseCounter = */ 0U,
            /* cntExpList[1]->priQueueSize       = */ OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE5
        }
    },
    /* cntExplistMux = */ 0U
};
/* Scheduler init dynamic parameters end. */

#define OS_STOP_SEC_INITVAR_OSCORE5 
#include "Os_MemMap.h"

#define OS_START_SEC_GLOBAL_NOCACHE_VAR 
#include "Os_MemMap.h"

/* Spinlock dynamic parameters start. */
static Os_SpinlockDynType OsCfg_Spinlock_OsSpinlock0_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_OsSpinlock1_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_WDGMSPINLOCK_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_DTC_0x0402_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x1002_Operation_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x1003_Operation_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x11_Operation_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x14_Operation_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x22_Operation_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x27_Operation_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x28_Operation_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x2E_Operation_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x31_Operation_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x85_Operation_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMS_BattPackMatchFault1_PMS_BMS_BattPackMatchFault1_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_BattPackNum_PMS_BMSH_BattPackNum_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_BattSysNum_PMS_BMSH_BattSysNum_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatIsoAlarm3_PMS_BMSH_TBOX_BatIsoAlarm3_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatLowSOC3_PMS_BMSH_TBOX_BatLowSOC3_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatOverCharge3_PMS_BMSH_TBOX_BatOverCharge3_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatOverSOC3_PMS_BMSH_TBOX_BatOverSOC3_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatOverTemp3_PMS_BMSH_TBOX_BatOverTemp3_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatOverVoltage3_PMS_BMSH_TBOX_BatOverVoltage3_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatTempUniformity3_PMS_BMSH_TBOX_BatTempUniformity3_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatUnderVoltage3_PMS_BMSH_TBOX_BatUnderVoltage3_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatUniformity3_PMS_BMSH_TBOX_BatUniformity3_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_CellOverVoltage3_PMS_BMSH_TBOX_CellOverVoltage3_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_CellUnderVoltage3_PMS_BMSH_TBOX_CellUnderVoltage3_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_FireAlarm2_PMS_BMSH_TBOX_FireAlarm2_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_SOCHop3_PMS_BMSH_TBOX_SOCHop3_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_IPU_MCUTempHighAlarm2_PMS_IPU_MCUTempHighAlarm2_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_IPU_MotorOverCurrFlt1_PMS_IPU_MotorOverCurrFlt1_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_IPU_MotorOverSpdFlt1_PMS_IPU_MotorOverSpdFlt1_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_IPU_MotorTempHighFault2_PMS_IPU_MotorTempHighFault2_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_ODP_TBOX_DcDcStsAlm1_PMS_ODP_TBOX_DcDcStsAlm1_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_ODP_TBOX_TDcDcAlm1_PMS_ODP_TBOX_TDcDcAlm1_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_PMS_32960FltNum_PMS_PMS_32960FltNum_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_PMS_OTAInstrucStsReminder_PMS_OTAInstrucStsReminder_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_PMS_OTAInstructRxnSts_PMS_OTAInstructRxnSts_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_PMS_TBOX_BrkSysErr1_PMS_PMS_TBOX_BrkSysErr1_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_PMS_TBOX_HVILSts1_PMS_PMS_TBOX_HVILSts1_PMS_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x400F_Start_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Dyn;
static Os_SpinlockDynType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Dyn;

/* Spinlock dynamic parameters end. */

#define OS_STOP_SEC_GLOBAL_NOCACHE_VAR 
#include "Os_MemMap.h"

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
#define OS_START_SEC_CODE 
#include "Os_MemMap.h"
void OsCfg_Scheduler_InitCallback_OsCore0(void)
{
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes0_OsCore0, OsCfg_TaskQueueNodes0_Data_OsCore0, OS_CFG_SIZE_TASKQUEUE0_OSCORE0);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes1_OsCore0, OsCfg_TaskQueueNodes1_Data_OsCore0, OS_CFG_SIZE_TASKQUEUE1_OSCORE0);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes2_OsCore0, OsCfg_TaskQueueNodes2_Data_OsCore0, OS_CFG_SIZE_TASKQUEUE2_OSCORE0);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes3_OsCore0, OsCfg_TaskQueueNodes3_Data_OsCore0, OS_CFG_SIZE_TASKQUEUE3_OSCORE0);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes4_OsCore0, OsCfg_TaskQueueNodes4_Data_OsCore0, OS_CFG_SIZE_TASKQUEUE4_OSCORE0);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes5_OsCore0, OsCfg_TaskQueueNodes5_Data_OsCore0, OS_CFG_SIZE_TASKQUEUE5_OSCORE0);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes6_OsCore0, OsCfg_TaskQueueNodes6_Data_OsCore0, OS_CFG_SIZE_TASKQUEUE6_OSCORE0);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes7_OsCore0, OsCfg_TaskQueueNodes7_Data_OsCore0, OS_CFG_SIZE_TASKQUEUE7_OSCORE0);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes8_OsCore0, OsCfg_TaskQueueNodes8_Data_OsCore0, OS_CFG_SIZE_TASKQUEUE8_OSCORE0);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes9_OsCore0, OsCfg_TaskQueueNodes9_Data_OsCore0, OS_CFG_SIZE_TASKQUEUE9_OSCORE0);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes10_OsCore0, OsCfg_TaskQueueNodes10_Data_OsCore0, OS_CFG_SIZE_TASKQUEUE10_OSCORE0);
}

void OsCfg_Scheduler_InitCallback_OsCore1(void)
{
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes0_OsCore1, OsCfg_TaskQueueNodes0_Data_OsCore1, OS_CFG_SIZE_TASKQUEUE0_OSCORE1);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes1_OsCore1, OsCfg_TaskQueueNodes1_Data_OsCore1, OS_CFG_SIZE_TASKQUEUE1_OSCORE1);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes2_OsCore1, OsCfg_TaskQueueNodes2_Data_OsCore1, OS_CFG_SIZE_TASKQUEUE2_OSCORE1);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes3_OsCore1, OsCfg_TaskQueueNodes3_Data_OsCore1, OS_CFG_SIZE_TASKQUEUE3_OSCORE1);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes4_OsCore1, OsCfg_TaskQueueNodes4_Data_OsCore1, OS_CFG_SIZE_TASKQUEUE4_OSCORE1);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes5_OsCore1, OsCfg_TaskQueueNodes5_Data_OsCore1, OS_CFG_SIZE_TASKQUEUE5_OSCORE1);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes6_OsCore1, OsCfg_TaskQueueNodes6_Data_OsCore1, OS_CFG_SIZE_TASKQUEUE6_OSCORE1);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes7_OsCore1, OsCfg_TaskQueueNodes7_Data_OsCore1, OS_CFG_SIZE_TASKQUEUE7_OSCORE1);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes8_OsCore1, OsCfg_TaskQueueNodes8_Data_OsCore1, OS_CFG_SIZE_TASKQUEUE8_OSCORE1);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes9_OsCore1, OsCfg_TaskQueueNodes9_Data_OsCore1, OS_CFG_SIZE_TASKQUEUE9_OSCORE1);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes10_OsCore1, OsCfg_TaskQueueNodes10_Data_OsCore1, OS_CFG_SIZE_TASKQUEUE10_OSCORE1);
}

void OsCfg_Scheduler_InitCallback_OsCore2(void)
{
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes0_OsCore2, OsCfg_TaskQueueNodes0_Data_OsCore2, OS_CFG_SIZE_TASKQUEUE0_OSCORE2);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes1_OsCore2, OsCfg_TaskQueueNodes1_Data_OsCore2, OS_CFG_SIZE_TASKQUEUE1_OSCORE2);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes2_OsCore2, OsCfg_TaskQueueNodes2_Data_OsCore2, OS_CFG_SIZE_TASKQUEUE2_OSCORE2);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes3_OsCore2, OsCfg_TaskQueueNodes3_Data_OsCore2, OS_CFG_SIZE_TASKQUEUE3_OSCORE2);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes4_OsCore2, OsCfg_TaskQueueNodes4_Data_OsCore2, OS_CFG_SIZE_TASKQUEUE4_OSCORE2);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes5_OsCore2, OsCfg_TaskQueueNodes5_Data_OsCore2, OS_CFG_SIZE_TASKQUEUE5_OSCORE2);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes6_OsCore2, OsCfg_TaskQueueNodes6_Data_OsCore2, OS_CFG_SIZE_TASKQUEUE6_OSCORE2);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes7_OsCore2, OsCfg_TaskQueueNodes7_Data_OsCore2, OS_CFG_SIZE_TASKQUEUE7_OSCORE2);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes8_OsCore2, OsCfg_TaskQueueNodes8_Data_OsCore2, OS_CFG_SIZE_TASKQUEUE8_OSCORE2);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes9_OsCore2, OsCfg_TaskQueueNodes9_Data_OsCore2, OS_CFG_SIZE_TASKQUEUE9_OSCORE2);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes10_OsCore2, OsCfg_TaskQueueNodes10_Data_OsCore2, OS_CFG_SIZE_TASKQUEUE10_OSCORE2);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes11_OsCore2, OsCfg_TaskQueueNodes11_Data_OsCore2, OS_CFG_SIZE_TASKQUEUE11_OSCORE2);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes12_OsCore2, OsCfg_TaskQueueNodes12_Data_OsCore2, OS_CFG_SIZE_TASKQUEUE12_OSCORE2);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes13_OsCore2, OsCfg_TaskQueueNodes13_Data_OsCore2, OS_CFG_SIZE_TASKQUEUE13_OSCORE2);
}

void OsCfg_Scheduler_InitCallback_OsCore3(void)
{
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes0_OsCore3, OsCfg_TaskQueueNodes0_Data_OsCore3, OS_CFG_SIZE_TASKQUEUE0_OSCORE3);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes1_OsCore3, OsCfg_TaskQueueNodes1_Data_OsCore3, OS_CFG_SIZE_TASKQUEUE1_OSCORE3);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes2_OsCore3, OsCfg_TaskQueueNodes2_Data_OsCore3, OS_CFG_SIZE_TASKQUEUE2_OSCORE3);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes3_OsCore3, OsCfg_TaskQueueNodes3_Data_OsCore3, OS_CFG_SIZE_TASKQUEUE3_OSCORE3);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes4_OsCore3, OsCfg_TaskQueueNodes4_Data_OsCore3, OS_CFG_SIZE_TASKQUEUE4_OSCORE3);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes5_OsCore3, OsCfg_TaskQueueNodes5_Data_OsCore3, OS_CFG_SIZE_TASKQUEUE5_OSCORE3);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes6_OsCore3, OsCfg_TaskQueueNodes6_Data_OsCore3, OS_CFG_SIZE_TASKQUEUE6_OSCORE3);
}

void OsCfg_Scheduler_InitCallback_OsCore4(void)
{
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes0_OsCore4, OsCfg_TaskQueueNodes0_Data_OsCore4, OS_CFG_SIZE_TASKQUEUE0_OSCORE4);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes1_OsCore4, OsCfg_TaskQueueNodes1_Data_OsCore4, OS_CFG_SIZE_TASKQUEUE1_OSCORE4);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes2_OsCore4, OsCfg_TaskQueueNodes2_Data_OsCore4, OS_CFG_SIZE_TASKQUEUE2_OSCORE4);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes3_OsCore4, OsCfg_TaskQueueNodes3_Data_OsCore4, OS_CFG_SIZE_TASKQUEUE3_OSCORE4);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes4_OsCore4, OsCfg_TaskQueueNodes4_Data_OsCore4, OS_CFG_SIZE_TASKQUEUE4_OSCORE4);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes5_OsCore4, OsCfg_TaskQueueNodes5_Data_OsCore4, OS_CFG_SIZE_TASKQUEUE5_OSCORE4);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes6_OsCore4, OsCfg_TaskQueueNodes6_Data_OsCore4, OS_CFG_SIZE_TASKQUEUE6_OSCORE4);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes7_OsCore4, OsCfg_TaskQueueNodes7_Data_OsCore4, OS_CFG_SIZE_TASKQUEUE7_OSCORE4);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes8_OsCore4, OsCfg_TaskQueueNodes8_Data_OsCore4, OS_CFG_SIZE_TASKQUEUE8_OSCORE4);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes9_OsCore4, OsCfg_TaskQueueNodes9_Data_OsCore4, OS_CFG_SIZE_TASKQUEUE9_OSCORE4);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes10_OsCore4, OsCfg_TaskQueueNodes10_Data_OsCore4, OS_CFG_SIZE_TASKQUEUE10_OSCORE4);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes11_OsCore4, OsCfg_TaskQueueNodes11_Data_OsCore4, OS_CFG_SIZE_TASKQUEUE11_OSCORE4);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes12_OsCore4, OsCfg_TaskQueueNodes12_Data_OsCore4, OS_CFG_SIZE_TASKQUEUE12_OSCORE4);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes13_OsCore4, OsCfg_TaskQueueNodes13_Data_OsCore4, OS_CFG_SIZE_TASKQUEUE13_OSCORE4);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes14_OsCore4, OsCfg_TaskQueueNodes14_Data_OsCore4, OS_CFG_SIZE_TASKQUEUE14_OSCORE4);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes15_OsCore4, OsCfg_TaskQueueNodes15_Data_OsCore4, OS_CFG_SIZE_TASKQUEUE15_OSCORE4);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes16_OsCore4, OsCfg_TaskQueueNodes16_Data_OsCore4, OS_CFG_SIZE_TASKQUEUE16_OSCORE4);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes17_OsCore4, OsCfg_TaskQueueNodes17_Data_OsCore4, OS_CFG_SIZE_TASKQUEUE17_OSCORE4);
}

void OsCfg_Scheduler_InitCallback_OsCore5(void)
{
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes0_OsCore5, OsCfg_TaskQueueNodes0_Data_OsCore5, OS_CFG_SIZE_TASKQUEUE0_OSCORE5);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes1_OsCore5, OsCfg_TaskQueueNodes1_Data_OsCore5, OS_CFG_SIZE_TASKQUEUE1_OSCORE5);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes2_OsCore5, OsCfg_TaskQueueNodes2_Data_OsCore5, OS_CFG_SIZE_TASKQUEUE2_OSCORE5);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes3_OsCore5, OsCfg_TaskQueueNodes3_Data_OsCore5, OS_CFG_SIZE_TASKQUEUE3_OSCORE5);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes4_OsCore5, OsCfg_TaskQueueNodes4_Data_OsCore5, OS_CFG_SIZE_TASKQUEUE4_OSCORE5);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes5_OsCore5, OsCfg_TaskQueueNodes5_Data_OsCore5, OS_CFG_SIZE_TASKQUEUE5_OSCORE5);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes6_OsCore5, OsCfg_TaskQueueNodes6_Data_OsCore5, OS_CFG_SIZE_TASKQUEUE6_OSCORE5);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes7_OsCore5, OsCfg_TaskQueueNodes7_Data_OsCore5, OS_CFG_SIZE_TASKQUEUE7_OSCORE5);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes8_OsCore5, OsCfg_TaskQueueNodes8_Data_OsCore5, OS_CFG_SIZE_TASKQUEUE8_OSCORE5);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes9_OsCore5, OsCfg_TaskQueueNodes9_Data_OsCore5, OS_CFG_SIZE_TASKQUEUE9_OSCORE5);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes10_OsCore5, OsCfg_TaskQueueNodes10_Data_OsCore5, OS_CFG_SIZE_TASKQUEUE10_OSCORE5);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes11_OsCore5, OsCfg_TaskQueueNodes11_Data_OsCore5, OS_CFG_SIZE_TASKQUEUE11_OSCORE5);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes12_OsCore5, OsCfg_TaskQueueNodes12_Data_OsCore5, OS_CFG_SIZE_TASKQUEUE12_OSCORE5);
    Os_TaskQue_Init(&OsCfg_TaskQueueNodes13_OsCore5, OsCfg_TaskQueueNodes13_Data_OsCore5, OS_CFG_SIZE_TASKQUEUE13_OSCORE5);
}

#define OS_STOP_SEC_CODE 
#include "Os_MemMap.h"

#define OS_START_SEC_CONST 
#include "Os_MemMap.h"
/* System config parameters start. */
const Os_SystemCfgType Os_SystemCfgData =
{
    /* isrRefs =     */ NULL_PTR,
    /* isrCnt =      */ 0U,
    /* isrCat1Refs = */ NULL_PTR,
    /* isrCat1Cnt =  */ 0U,
    /* counterRefs = */ NULL_PTR,
    /* counterCnt =  */ 0U
};

/* System config parameters end. */

/* App config parameters start. */
const Os_AppCfgType OsCfg_Appl_SystemApplication_OsCore_Core0 =
{
    /* appDelayTimingViolation = */ FALSE,
    /* appTrust                = */ OS_APP_TRUSTED,
    /* appDyn                  = */ &OsCfg_Appl_SystemApplication_OsCore_Core0_Dyn,
    /* startupHook             = */ NULL_PTR,
    /* shutdownHook            = */ &ShutdownHook,
    /* errorHook               = */ &ErrorHook,
    /* coreId                  = */ OS_CORE_ID_0,
    /* restartTask             = */ NULL_PTR,
    /* appId                   = */ SYSTEMAPPLICATION_OSCORE_CORE0
};
const Os_AppCfgType OsCfg_Appl_App1_Application_Core0_QM =
{
    /* appDelayTimingViolation = */ FALSE,
    /* appTrust                = */ OS_APP_TRUSTED,
    /* appDyn                  = */ &OsCfg_Appl_App1_Application_Core0_QM_Dyn,
    /* startupHook             = */ NULL_PTR,
    /* shutdownHook            = */ NULL_PTR,
    /* errorHook               = */ NULL_PTR,
    /* coreId                  = */ OS_CORE_ID_0,
    /* restartTask             = */ NULL_PTR,
    /* appId                   = */ APP1_APPLICATION_CORE0_QM
};
const Os_AppCfgType OsCfg_Appl_Bsw_Application_Core0_QM =
{
    /* appDelayTimingViolation = */ FALSE,
    /* appTrust                = */ OS_APP_TRUSTED,
    /* appDyn                  = */ &OsCfg_Appl_Bsw_Application_Core0_QM_Dyn,
    /* startupHook             = */ NULL_PTR,
    /* shutdownHook            = */ NULL_PTR,
    /* errorHook               = */ NULL_PTR,
    /* coreId                  = */ OS_CORE_ID_0,
    /* restartTask             = */ NULL_PTR,
    /* appId                   = */ BSW_APPLICATION_CORE0_QM
};
const Os_AppCfgType OsCfg_Appl_SystemApplication_OsCore_Core1 =
{
    /* appDelayTimingViolation = */ FALSE,
    /* appTrust                = */ OS_APP_TRUSTED,
    /* appDyn                  = */ &OsCfg_Appl_SystemApplication_OsCore_Core1_Dyn,
    /* startupHook             = */ NULL_PTR,
    /* shutdownHook            = */ &ShutdownHook,
    /* errorHook               = */ &ErrorHook,
    /* coreId                  = */ OS_CORE_ID_1,
    /* restartTask             = */ NULL_PTR,
    /* appId                   = */ SYSTEMAPPLICATION_OSCORE_CORE1
};
const Os_AppCfgType OsCfg_Appl_App1_Application_Core1_QM =
{
    /* appDelayTimingViolation = */ FALSE,
    /* appTrust                = */ OS_APP_TRUSTED,
    /* appDyn                  = */ &OsCfg_Appl_App1_Application_Core1_QM_Dyn,
    /* startupHook             = */ NULL_PTR,
    /* shutdownHook            = */ NULL_PTR,
    /* errorHook               = */ NULL_PTR,
    /* coreId                  = */ OS_CORE_ID_1,
    /* restartTask             = */ NULL_PTR,
    /* appId                   = */ APP1_APPLICATION_CORE1_QM
};
const Os_AppCfgType OsCfg_Appl_Bsw_Application_Core1_QM =
{
    /* appDelayTimingViolation = */ FALSE,
    /* appTrust                = */ OS_APP_TRUSTED,
    /* appDyn                  = */ &OsCfg_Appl_Bsw_Application_Core1_QM_Dyn,
    /* startupHook             = */ NULL_PTR,
    /* shutdownHook            = */ NULL_PTR,
    /* errorHook               = */ NULL_PTR,
    /* coreId                  = */ OS_CORE_ID_1,
    /* restartTask             = */ NULL_PTR,
    /* appId                   = */ BSW_APPLICATION_CORE1_QM
};
const Os_AppCfgType OsCfg_Appl_SystemApplication_OsCore_Core2 =
{
    /* appDelayTimingViolation = */ FALSE,
    /* appTrust                = */ OS_APP_TRUSTED,
    /* appDyn                  = */ &OsCfg_Appl_SystemApplication_OsCore_Core2_Dyn,
    /* startupHook             = */ NULL_PTR,
    /* shutdownHook            = */ &ShutdownHook,
    /* errorHook               = */ &ErrorHook,
    /* coreId                  = */ OS_CORE_ID_2,
    /* restartTask             = */ NULL_PTR,
    /* appId                   = */ SYSTEMAPPLICATION_OSCORE_CORE2
};
const Os_AppCfgType OsCfg_Appl_App1_Application_Core2_QM =
{
    /* appDelayTimingViolation = */ FALSE,
    /* appTrust                = */ OS_APP_TRUSTED,
    /* appDyn                  = */ &OsCfg_Appl_App1_Application_Core2_QM_Dyn,
    /* startupHook             = */ NULL_PTR,
    /* shutdownHook            = */ NULL_PTR,
    /* errorHook               = */ NULL_PTR,
    /* coreId                  = */ OS_CORE_ID_2,
    /* restartTask             = */ NULL_PTR,
    /* appId                   = */ APP1_APPLICATION_CORE2_QM
};
const Os_AppCfgType OsCfg_Appl_Bsw_Application_Core2_QM =
{
    /* appDelayTimingViolation = */ FALSE,
    /* appTrust                = */ OS_APP_TRUSTED,
    /* appDyn                  = */ &OsCfg_Appl_Bsw_Application_Core2_QM_Dyn,
    /* startupHook             = */ NULL_PTR,
    /* shutdownHook            = */ NULL_PTR,
    /* errorHook               = */ NULL_PTR,
    /* coreId                  = */ OS_CORE_ID_2,
    /* restartTask             = */ NULL_PTR,
    /* appId                   = */ BSW_APPLICATION_CORE2_QM
};
const Os_AppCfgType OsCfg_Appl_SystemApplication_OsCore_Core3 =
{
    /* appDelayTimingViolation = */ FALSE,
    /* appTrust                = */ OS_APP_TRUSTED,
    /* appDyn                  = */ &OsCfg_Appl_SystemApplication_OsCore_Core3_Dyn,
    /* startupHook             = */ NULL_PTR,
    /* shutdownHook            = */ &ShutdownHook,
    /* errorHook               = */ &ErrorHook,
    /* coreId                  = */ OS_CORE_ID_3,
    /* restartTask             = */ NULL_PTR,
    /* appId                   = */ SYSTEMAPPLICATION_OSCORE_CORE3
};
const Os_AppCfgType OsCfg_Appl_App1_Application_Core3_QM =
{
    /* appDelayTimingViolation = */ FALSE,
    /* appTrust                = */ OS_APP_TRUSTED,
    /* appDyn                  = */ &OsCfg_Appl_App1_Application_Core3_QM_Dyn,
    /* startupHook             = */ NULL_PTR,
    /* shutdownHook            = */ NULL_PTR,
    /* errorHook               = */ NULL_PTR,
    /* coreId                  = */ OS_CORE_ID_3,
    /* restartTask             = */ NULL_PTR,
    /* appId                   = */ APP1_APPLICATION_CORE3_QM
};
const Os_AppCfgType OsCfg_Appl_Bsw_Application_Core3_QM =
{
    /* appDelayTimingViolation = */ FALSE,
    /* appTrust                = */ OS_APP_TRUSTED,
    /* appDyn                  = */ &OsCfg_Appl_Bsw_Application_Core3_QM_Dyn,
    /* startupHook             = */ NULL_PTR,
    /* shutdownHook            = */ NULL_PTR,
    /* errorHook               = */ NULL_PTR,
    /* coreId                  = */ OS_CORE_ID_3,
    /* restartTask             = */ NULL_PTR,
    /* appId                   = */ BSW_APPLICATION_CORE3_QM
};
const Os_AppCfgType OsCfg_Appl_SystemApplication_OsCore_Core4 =
{
    /* appDelayTimingViolation = */ FALSE,
    /* appTrust                = */ OS_APP_TRUSTED,
    /* appDyn                  = */ &OsCfg_Appl_SystemApplication_OsCore_Core4_Dyn,
    /* startupHook             = */ NULL_PTR,
    /* shutdownHook            = */ &ShutdownHook,
    /* errorHook               = */ &ErrorHook,
    /* coreId                  = */ OS_CORE_ID_4,
    /* restartTask             = */ NULL_PTR,
    /* appId                   = */ SYSTEMAPPLICATION_OSCORE_CORE4
};
const Os_AppCfgType OsCfg_Appl_App1_Application_Core4_QM =
{
    /* appDelayTimingViolation = */ FALSE,
    /* appTrust                = */ OS_APP_TRUSTED,
    /* appDyn                  = */ &OsCfg_Appl_App1_Application_Core4_QM_Dyn,
    /* startupHook             = */ NULL_PTR,
    /* shutdownHook            = */ NULL_PTR,
    /* errorHook               = */ NULL_PTR,
    /* coreId                  = */ OS_CORE_ID_4,
    /* restartTask             = */ NULL_PTR,
    /* appId                   = */ APP1_APPLICATION_CORE4_QM
};
const Os_AppCfgType OsCfg_Appl_Bsw_Application_Core4_QM =
{
    /* appDelayTimingViolation = */ FALSE,
    /* appTrust                = */ OS_APP_TRUSTED,
    /* appDyn                  = */ &OsCfg_Appl_Bsw_Application_Core4_QM_Dyn,
    /* startupHook             = */ NULL_PTR,
    /* shutdownHook            = */ NULL_PTR,
    /* errorHook               = */ NULL_PTR,
    /* coreId                  = */ OS_CORE_ID_4,
    /* restartTask             = */ NULL_PTR,
    /* appId                   = */ BSW_APPLICATION_CORE4_QM
};
const Os_AppCfgType OsCfg_Appl_SystemApplication_OsCore_Core5 =
{
    /* appDelayTimingViolation = */ FALSE,
    /* appTrust                = */ OS_APP_TRUSTED,
    /* appDyn                  = */ &OsCfg_Appl_SystemApplication_OsCore_Core5_Dyn,
    /* startupHook             = */ NULL_PTR,
    /* shutdownHook            = */ &ShutdownHook,
    /* errorHook               = */ &ErrorHook,
    /* coreId                  = */ OS_CORE_ID_5,
    /* restartTask             = */ NULL_PTR,
    /* appId                   = */ SYSTEMAPPLICATION_OSCORE_CORE5
};
const Os_AppCfgType OsCfg_Appl_App1_Application_Core5_QM =
{
    /* appDelayTimingViolation = */ FALSE,
    /* appTrust                = */ OS_APP_TRUSTED,
    /* appDyn                  = */ &OsCfg_Appl_App1_Application_Core5_QM_Dyn,
    /* startupHook             = */ NULL_PTR,
    /* shutdownHook            = */ NULL_PTR,
    /* errorHook               = */ NULL_PTR,
    /* coreId                  = */ OS_CORE_ID_5,
    /* restartTask             = */ NULL_PTR,
    /* appId                   = */ APP1_APPLICATION_CORE5_QM
};
const Os_AppCfgType OsCfg_Appl_Bsw_Application_Core5_QM =
{
    /* appDelayTimingViolation = */ FALSE,
    /* appTrust                = */ OS_APP_TRUSTED,
    /* appDyn                  = */ &OsCfg_Appl_Bsw_Application_Core5_QM_Dyn,
    /* startupHook             = */ NULL_PTR,
    /* shutdownHook            = */ NULL_PTR,
    /* errorHook               = */ NULL_PTR,
    /* coreId                  = */ OS_CORE_ID_5,
    /* restartTask             = */ NULL_PTR,
    /* appId                   = */ BSW_APPLICATION_CORE5_QM
};
/* App config parameters end. */

/* Task config parameters start. */
const Os_TaskCfgType OsCfg_Task_Default_Init_Task_Core0 =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Default_Init_Task_Core0,
    /* ownerAppId     = */ SYSTEMAPPLICATION_OSCORE_CORE0,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Default_Init_Task_Core0_Dyn,
    /* cfgPrio        = */ 0U,
    /* schdType       = */ OS_TASK_NON,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_APP1_APPLICATION_CORE0_QM_ACCESS),
    /* taskId         = */ DEFAULT_INIT_TASK_CORE0,
    /* coreId         = */ OS_CORE_ID_0,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_ANY
};
const Os_TaskCfgType OsCfg_Task_Idle_Task_Core0 =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Idle_Task_Core0,
    /* ownerAppId     = */ SYSTEMAPPLICATION_OSCORE_CORE0,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Idle_Task_Core0_Dyn,
    /* cfgPrio        = */ 10U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_APP1_APPLICATION_CORE0_QM_ACCESS),
    /* taskId         = */ IDLE_TASK_CORE0,
    /* coreId         = */ OS_CORE_ID_0,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_ANY
};
const Os_TaskCfgType OsCfg_Task_App1_Task_1ms_Core0_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_1ms_Core0_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE0_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_1ms_Core0_QM_Dyn,
    /* cfgPrio        = */ 2U,
    /* schdType       = */ OS_TASK_NON,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_APP1_APPLICATION_CORE0_QM_ACCESS),
    /* taskId         = */ APP1_TASK_1MS_CORE0_QM,
    /* coreId         = */ OS_CORE_ID_0,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_5ms_Core0_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_5ms_Core0_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE0_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_5ms_Core0_QM_Dyn,
    /* cfgPrio        = */ 4U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_APP1_APPLICATION_CORE0_QM_ACCESS),
    /* taskId         = */ APP1_TASK_5MS_CORE0_QM,
    /* coreId         = */ OS_CORE_ID_0,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_10ms_Core0_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_10ms_Core0_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE0_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_10ms_Core0_QM_Dyn,
    /* cfgPrio        = */ 6U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_APP1_APPLICATION_CORE0_QM_ACCESS),
    /* taskId         = */ APP1_TASK_10MS_CORE0_QM,
    /* coreId         = */ OS_CORE_ID_0,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_20ms_Core0_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_20ms_Core0_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE0_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_20ms_Core0_QM_Dyn,
    /* cfgPrio        = */ 7U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_APP1_APPLICATION_CORE0_QM_ACCESS),
    /* taskId         = */ APP1_TASK_20MS_CORE0_QM,
    /* coreId         = */ OS_CORE_ID_0,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_50ms_Core0_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_50ms_Core0_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE0_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_50ms_Core0_QM_Dyn,
    /* cfgPrio        = */ 8U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_APP1_APPLICATION_CORE0_QM_ACCESS),
    /* taskId         = */ APP1_TASK_50MS_CORE0_QM,
    /* coreId         = */ OS_CORE_ID_0,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_100ms_Core0_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_100ms_Core0_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE0_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_100ms_Core0_QM_Dyn,
    /* cfgPrio        = */ 9U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_APP1_APPLICATION_CORE0_QM_ACCESS),
    /* taskId         = */ APP1_TASK_100MS_CORE0_QM,
    /* coreId         = */ OS_CORE_ID_0,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_SWC_Init_Task_Core0 =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_SWC_Init_Task_Core0,
    /* ownerAppId     = */ APP1_APPLICATION_CORE0_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_SWC_Init_Task_Core0_Dyn,
    /* cfgPrio        = */ 1U,
    /* schdType       = */ OS_TASK_NON,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_APP1_APPLICATION_CORE0_QM_ACCESS),
    /* taskId         = */ SWC_INIT_TASK_CORE0,
    /* coreId         = */ OS_CORE_ID_0,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_ANY
};
const Os_TaskCfgType OsCfg_Task_Bsw_Task_10ms_Core0_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Bsw_Task_10ms_Core0_QM,
    /* ownerAppId     = */ BSW_APPLICATION_CORE0_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Bsw_Task_10ms_Core0_QM_Dyn,
    /* cfgPrio        = */ 5U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_BSW_APPLICATION_CORE0_QM_ACCESS),
    /* taskId         = */ BSW_TASK_10MS_CORE0_QM,
    /* coreId         = */ OS_CORE_ID_0,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_Bsw_Task_5ms_Core0_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Bsw_Task_5ms_Core0_QM,
    /* ownerAppId     = */ BSW_APPLICATION_CORE0_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Bsw_Task_5ms_Core0_QM_Dyn,
    /* cfgPrio        = */ 3U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_BSW_APPLICATION_CORE0_QM_ACCESS),
    /* taskId         = */ BSW_TASK_5MS_CORE0_QM,
    /* coreId         = */ OS_CORE_ID_0,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_Default_Init_Task_Core1 =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Default_Init_Task_Core1,
    /* ownerAppId     = */ SYSTEMAPPLICATION_OSCORE_CORE1,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Default_Init_Task_Core1_Dyn,
    /* cfgPrio        = */ 0U,
    /* schdType       = */ OS_TASK_NON,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* taskId         = */ DEFAULT_INIT_TASK_CORE1,
    /* coreId         = */ OS_CORE_ID_1,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_ANY
};
const Os_TaskCfgType OsCfg_Task_Idle_Task_Core1 =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Idle_Task_Core1,
    /* ownerAppId     = */ SYSTEMAPPLICATION_OSCORE_CORE1,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Idle_Task_Core1_Dyn,
    /* cfgPrio        = */ 10U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* taskId         = */ IDLE_TASK_CORE1,
    /* coreId         = */ OS_CORE_ID_1,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_ANY
};
const Os_TaskCfgType OsCfg_Task_App1_Task_10ms_Core1_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_10ms_Core1_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE1_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_10ms_Core1_QM_Dyn,
    /* cfgPrio        = */ 6U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* taskId         = */ APP1_TASK_10MS_CORE1_QM,
    /* coreId         = */ OS_CORE_ID_1,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_SWC_Init_Task_Core1 =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_SWC_Init_Task_Core1,
    /* ownerAppId     = */ APP1_APPLICATION_CORE1_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_SWC_Init_Task_Core1_Dyn,
    /* cfgPrio        = */ 1U,
    /* schdType       = */ OS_TASK_NON,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* taskId         = */ SWC_INIT_TASK_CORE1,
    /* coreId         = */ OS_CORE_ID_1,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_ANY
};
const Os_TaskCfgType OsCfg_Task_App1_Task_1ms_Core1_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_1ms_Core1_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE1_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_1ms_Core1_QM_Dyn,
    /* cfgPrio        = */ 3U,
    /* schdType       = */ OS_TASK_NON,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* taskId         = */ APP1_TASK_1MS_CORE1_QM,
    /* coreId         = */ OS_CORE_ID_1,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_5ms_Core1_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_5ms_Core1_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE1_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_5ms_Core1_QM_Dyn,
    /* cfgPrio        = */ 4U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* taskId         = */ APP1_TASK_5MS_CORE1_QM,
    /* coreId         = */ OS_CORE_ID_1,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_20ms_Core1_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_20ms_Core1_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE1_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_20ms_Core1_QM_Dyn,
    /* cfgPrio        = */ 7U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* taskId         = */ APP1_TASK_20MS_CORE1_QM,
    /* coreId         = */ OS_CORE_ID_1,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_50ms_Core1_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_50ms_Core1_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE1_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_50ms_Core1_QM_Dyn,
    /* cfgPrio        = */ 8U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* taskId         = */ APP1_TASK_50MS_CORE1_QM,
    /* coreId         = */ OS_CORE_ID_1,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_100ms_Core1_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_100ms_Core1_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE1_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_100ms_Core1_QM_Dyn,
    /* cfgPrio        = */ 9U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* taskId         = */ APP1_TASK_100MS_CORE1_QM,
    /* coreId         = */ OS_CORE_ID_1,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_UDS_Core1_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_UDS_Core1_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE1_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_UDS_Core1_QM_Dyn,
    /* cfgPrio        = */ 2U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS |
                          OS_BSW_APPLICATION_CORE1_QM_ACCESS),
    /* taskId         = */ APP1_TASK_UDS_CORE1_QM,
    /* coreId         = */ OS_CORE_ID_1,
    /* taskType       = */ OS_TASK_ET,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_Bsw_Task_10ms_Core1_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Bsw_Task_10ms_Core1_QM,
    /* ownerAppId     = */ BSW_APPLICATION_CORE1_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Bsw_Task_10ms_Core1_QM_Dyn,
    /* cfgPrio        = */ 5U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |OS_BSW_APPLICATION_CORE1_QM_ACCESS),
    /* taskId         = */ BSW_TASK_10MS_CORE1_QM,
    /* coreId         = */ OS_CORE_ID_1,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_Default_Init_Task_Core2 =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Default_Init_Task_Core2,
    /* ownerAppId     = */ SYSTEMAPPLICATION_OSCORE_CORE2,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Default_Init_Task_Core2_Dyn,
    /* cfgPrio        = */ 0U,
    /* schdType       = */ OS_TASK_NON,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* taskId         = */ DEFAULT_INIT_TASK_CORE2,
    /* coreId         = */ OS_CORE_ID_2,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_ANY
};
const Os_TaskCfgType OsCfg_Task_Idle_Task_Core2 =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Idle_Task_Core2,
    /* ownerAppId     = */ SYSTEMAPPLICATION_OSCORE_CORE2,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Idle_Task_Core2_Dyn,
    /* cfgPrio        = */ 13U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* taskId         = */ IDLE_TASK_CORE2,
    /* coreId         = */ OS_CORE_ID_2,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_ANY
};
const Os_TaskCfgType OsCfg_Task_App1_Task_50ms_Core2_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_50ms_Core2_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE2_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_50ms_Core2_QM_Dyn,
    /* cfgPrio        = */ 10U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* taskId         = */ APP1_TASK_50MS_CORE2_QM,
    /* coreId         = */ OS_CORE_ID_2,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_100ms_Core2_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_100ms_Core2_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE2_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_100ms_Core2_QM_Dyn,
    /* cfgPrio        = */ 11U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* taskId         = */ APP1_TASK_100MS_CORE2_QM,
    /* coreId         = */ OS_CORE_ID_2,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_10ms_Core2_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_10ms_Core2_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE2_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_10ms_Core2_QM_Dyn,
    /* cfgPrio        = */ 8U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* taskId         = */ APP1_TASK_10MS_CORE2_QM,
    /* coreId         = */ OS_CORE_ID_2,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_1000ms_Core2_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_1000ms_Core2_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE2_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_1000ms_Core2_QM_Dyn,
    /* cfgPrio        = */ 12U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* taskId         = */ APP1_TASK_1000MS_CORE2_QM,
    /* coreId         = */ OS_CORE_ID_2,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_SWC_Init_Task_Core2 =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_SWC_Init_Task_Core2,
    /* ownerAppId     = */ APP1_APPLICATION_CORE2_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_SWC_Init_Task_Core2_Dyn,
    /* cfgPrio        = */ 1U,
    /* schdType       = */ OS_TASK_NON,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* taskId         = */ SWC_INIT_TASK_CORE2,
    /* coreId         = */ OS_CORE_ID_2,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_ANY
};
const Os_TaskCfgType OsCfg_Task_App1_Task_1ms_Core2_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_1ms_Core2_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE2_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_1ms_Core2_QM_Dyn,
    /* cfgPrio        = */ 5U,
    /* schdType       = */ OS_TASK_NON,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* taskId         = */ APP1_TASK_1MS_CORE2_QM,
    /* coreId         = */ OS_CORE_ID_2,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_5ms_Core2_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_5ms_Core2_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE2_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_5ms_Core2_QM_Dyn,
    /* cfgPrio        = */ 6U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* taskId         = */ APP1_TASK_5MS_CORE2_QM,
    /* coreId         = */ OS_CORE_ID_2,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_20ms_Core2_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_20ms_Core2_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE2_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_20ms_Core2_QM_Dyn,
    /* cfgPrio        = */ 9U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* taskId         = */ APP1_TASK_20MS_CORE2_QM,
    /* coreId         = */ OS_CORE_ID_2,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task0_UDS_Core2_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task0_UDS_Core2_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE2_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task0_UDS_Core2_QM_Dyn,
    /* cfgPrio        = */ 4U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_APP1_APPLICATION_CORE2_QM_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |
                          OS_BSW_APPLICATION_CORE2_QM_ACCESS),
    /* taskId         = */ APP1_TASK0_UDS_CORE2_QM,
    /* coreId         = */ OS_CORE_ID_2,
    /* taskType       = */ OS_TASK_ET,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task1_UDS_Core2_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task1_UDS_Core2_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE2_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task1_UDS_Core2_QM_Dyn,
    /* cfgPrio        = */ 3U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_APP1_APPLICATION_CORE2_QM_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |
                          OS_BSW_APPLICATION_CORE2_QM_ACCESS),
    /* taskId         = */ APP1_TASK1_UDS_CORE2_QM,
    /* coreId         = */ OS_CORE_ID_2,
    /* taskType       = */ OS_TASK_ET,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task2_UDS_Core2_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task2_UDS_Core2_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE2_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task2_UDS_Core2_QM_Dyn,
    /* cfgPrio        = */ 2U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_APP1_APPLICATION_CORE2_QM_ACCESS |OS_BSW_APPLICATION_CORE2_QM_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS),
    /* taskId         = */ APP1_TASK2_UDS_CORE2_QM,
    /* coreId         = */ OS_CORE_ID_2,
    /* taskType       = */ OS_TASK_ET,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_Bsw_Task_10ms_Core2_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Bsw_Task_10ms_Core2_QM,
    /* ownerAppId     = */ BSW_APPLICATION_CORE2_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Bsw_Task_10ms_Core2_QM_Dyn,
    /* cfgPrio        = */ 7U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_BSW_APPLICATION_CORE2_QM_ACCESS),
    /* taskId         = */ BSW_TASK_10MS_CORE2_QM,
    /* coreId         = */ OS_CORE_ID_2,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_Default_Init_Task_Core3 =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Default_Init_Task_Core3,
    /* ownerAppId     = */ SYSTEMAPPLICATION_OSCORE_CORE3,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Default_Init_Task_Core3_Dyn,
    /* cfgPrio        = */ 0U,
    /* schdType       = */ OS_TASK_NON,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |OS_APP1_APPLICATION_CORE3_QM_ACCESS),
    /* taskId         = */ DEFAULT_INIT_TASK_CORE3,
    /* coreId         = */ OS_CORE_ID_3,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_ANY
};
const Os_TaskCfgType OsCfg_Task_Idle_Task_Core3 =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Idle_Task_Core3,
    /* ownerAppId     = */ SYSTEMAPPLICATION_OSCORE_CORE3,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Idle_Task_Core3_Dyn,
    /* cfgPrio        = */ 6U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |OS_APP1_APPLICATION_CORE3_QM_ACCESS),
    /* taskId         = */ IDLE_TASK_CORE3,
    /* coreId         = */ OS_CORE_ID_3,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_ANY
};
const Os_TaskCfgType OsCfg_Task_SWC_Init_Task_Core3 =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_SWC_Init_Task_Core3,
    /* ownerAppId     = */ APP1_APPLICATION_CORE3_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_SWC_Init_Task_Core3_Dyn,
    /* cfgPrio        = */ 1U,
    /* schdType       = */ OS_TASK_NON,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |OS_APP1_APPLICATION_CORE3_QM_ACCESS),
    /* taskId         = */ SWC_INIT_TASK_CORE3,
    /* coreId         = */ OS_CORE_ID_3,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_ANY
};
const Os_TaskCfgType OsCfg_Task_App1_Task_UDS_Core3_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_UDS_Core3_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE3_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_UDS_Core3_QM_Dyn,
    /* cfgPrio        = */ 2U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |OS_APP1_APPLICATION_CORE3_QM_ACCESS |
                          OS_BSW_APPLICATION_CORE3_QM_ACCESS),
    /* taskId         = */ APP1_TASK_UDS_CORE3_QM,
    /* coreId         = */ OS_CORE_ID_3,
    /* taskType       = */ OS_TASK_ET,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_Task_1ms_Core3_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Task_1ms_Core3_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE3_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Task_1ms_Core3_QM_Dyn,
    /* cfgPrio        = */ 4U,
    /* schdType       = */ OS_TASK_NON,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |OS_APP1_APPLICATION_CORE3_QM_ACCESS),
    /* taskId         = */ TASK_1MS_CORE3_QM,
    /* coreId         = */ OS_CORE_ID_3,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_Task_100us_Core3_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Task_100us_Core3_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE3_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Task_100us_Core3_QM_Dyn,
    /* cfgPrio        = */ 3U,
    /* schdType       = */ OS_TASK_NON,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |OS_APP1_APPLICATION_CORE3_QM_ACCESS),
    /* taskId         = */ TASK_100US_CORE3_QM,
    /* coreId         = */ OS_CORE_ID_3,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_Task_5ms_Core3_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Task_5ms_Core3_QM,
    /* ownerAppId     = */ BSW_APPLICATION_CORE3_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Task_5ms_Core3_QM_Dyn,
    /* cfgPrio        = */ 5U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |OS_BSW_APPLICATION_CORE3_QM_ACCESS),
    /* taskId         = */ TASK_5MS_CORE3_QM,
    /* coreId         = */ OS_CORE_ID_3,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_Default_Init_Task_Core4 =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Default_Init_Task_Core4,
    /* ownerAppId     = */ SYSTEMAPPLICATION_OSCORE_CORE4,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Default_Init_Task_Core4_Dyn,
    /* cfgPrio        = */ 0U,
    /* schdType       = */ OS_TASK_NON,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_APP1_APPLICATION_CORE4_QM_ACCESS),
    /* taskId         = */ DEFAULT_INIT_TASK_CORE4,
    /* coreId         = */ OS_CORE_ID_4,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_ANY
};
const Os_TaskCfgType OsCfg_Task_Idle_Task_Core4 =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Idle_Task_Core4,
    /* ownerAppId     = */ SYSTEMAPPLICATION_OSCORE_CORE4,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Idle_Task_Core4_Dyn,
    /* cfgPrio        = */ 17U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_APP1_APPLICATION_CORE4_QM_ACCESS),
    /* taskId         = */ IDLE_TASK_CORE4,
    /* coreId         = */ OS_CORE_ID_4,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_ANY
};
const Os_TaskCfgType OsCfg_Task_App1_Task_1ms_Core4_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_1ms_Core4_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_1ms_Core4_QM_Dyn,
    /* cfgPrio        = */ 4U,
    /* schdType       = */ OS_TASK_NON,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_APP1_APPLICATION_CORE4_QM_ACCESS),
    /* taskId         = */ APP1_TASK_1MS_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_5ms_Core4_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_5ms_Core4_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_5ms_Core4_QM_Dyn,
    /* cfgPrio        = */ 7U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_APP1_APPLICATION_CORE4_QM_ACCESS),
    /* taskId         = */ APP1_TASK_5MS_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_10ms_Core4_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_10ms_Core4_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_10ms_Core4_QM_Dyn,
    /* cfgPrio        = */ 10U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_APP1_APPLICATION_CORE4_QM_ACCESS),
    /* taskId         = */ APP1_TASK_10MS_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_20ms_Core4_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_20ms_Core4_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_20ms_Core4_QM_Dyn,
    /* cfgPrio        = */ 12U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_APP1_APPLICATION_CORE4_QM_ACCESS),
    /* taskId         = */ APP1_TASK_20MS_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_50ms_Core4_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_50ms_Core4_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_50ms_Core4_QM_Dyn,
    /* cfgPrio        = */ 14U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_APP1_APPLICATION_CORE4_QM_ACCESS),
    /* taskId         = */ APP1_TASK_50MS_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_100ms_Core4_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_100ms_Core4_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_100ms_Core4_QM_Dyn,
    /* cfgPrio        = */ 16U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_APP1_APPLICATION_CORE4_QM_ACCESS),
    /* taskId         = */ APP1_TASK_100MS_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_SWC_Init_Task_Core4 =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_SWC_Init_Task_Core4,
    /* ownerAppId     = */ APP1_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_SWC_Init_Task_Core4_Dyn,
    /* cfgPrio        = */ 1U,
    /* schdType       = */ OS_TASK_NON,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_APP1_APPLICATION_CORE4_QM_ACCESS),
    /* taskId         = */ SWC_INIT_TASK_CORE4,
    /* coreId         = */ OS_CORE_ID_4,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_ANY
};
const Os_TaskCfgType OsCfg_Task_App1_Task_UDS_Core4_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_UDS_Core4_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_UDS_Core4_QM_Dyn,
    /* cfgPrio        = */ 2U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_APP1_APPLICATION_CORE4_QM_ACCESS |
                          OS_BSW_APPLICATION_CORE4_QM_ACCESS),
    /* taskId         = */ APP1_TASK_UDS_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* taskType       = */ OS_TASK_ET,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_Bsw_Task_100ms_Core4_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Bsw_Task_100ms_Core4_QM,
    /* ownerAppId     = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Bsw_Task_100ms_Core4_QM_Dyn,
    /* cfgPrio        = */ 15U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_BSW_APPLICATION_CORE4_QM_ACCESS),
    /* taskId         = */ BSW_TASK_100MS_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_Bsw_Task_50ms_Core4_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Bsw_Task_50ms_Core4_QM,
    /* ownerAppId     = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Bsw_Task_50ms_Core4_QM_Dyn,
    /* cfgPrio        = */ 13U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_BSW_APPLICATION_CORE4_QM_ACCESS),
    /* taskId         = */ BSW_TASK_50MS_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_Bsw_Task_20ms_Core4_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Bsw_Task_20ms_Core4_QM,
    /* ownerAppId     = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Bsw_Task_20ms_Core4_QM_Dyn,
    /* cfgPrio        = */ 11U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_BSW_APPLICATION_CORE4_QM_ACCESS),
    /* taskId         = */ BSW_TASK_20MS_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_Bsw_Task_10ms_Core4_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Bsw_Task_10ms_Core4_QM,
    /* ownerAppId     = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Bsw_Task_10ms_Core4_QM_Dyn,
    /* cfgPrio        = */ 8U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_BSW_APPLICATION_CORE4_QM_ACCESS),
    /* taskId         = */ BSW_TASK_10MS_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_Bsw_Task_5ms_Core4_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Bsw_Task_5ms_Core4_QM,
    /* ownerAppId     = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Bsw_Task_5ms_Core4_QM_Dyn,
    /* cfgPrio        = */ 6U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_BSW_APPLICATION_CORE4_QM_ACCESS),
    /* taskId         = */ BSW_TASK_5MS_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_Bsw_Task_1ms_Core4_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Bsw_Task_1ms_Core4_QM,
    /* ownerAppId     = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Bsw_Task_1ms_Core4_QM_Dyn,
    /* cfgPrio        = */ 3U,
    /* schdType       = */ OS_TASK_NON,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_BSW_APPLICATION_CORE4_QM_ACCESS),
    /* taskId         = */ BSW_TASK_1MS_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_Bsw_Task_5ms_Core4_Offest_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Bsw_Task_5ms_Core4_Offest_QM,
    /* ownerAppId     = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Bsw_Task_5ms_Core4_Offest_QM_Dyn,
    /* cfgPrio        = */ 5U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_BSW_APPLICATION_CORE4_QM_ACCESS),
    /* taskId         = */ BSW_TASK_5MS_CORE4_OFFEST_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_Bsw_Task_10ms_Core4_Offest_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Bsw_Task_10ms_Core4_Offest_QM,
    /* ownerAppId     = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Bsw_Task_10ms_Core4_Offest_QM_Dyn,
    /* cfgPrio        = */ 9U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_BSW_APPLICATION_CORE4_QM_ACCESS),
    /* taskId         = */ BSW_TASK_10MS_CORE4_OFFEST_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_Default_Init_Task_Core5 =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Default_Init_Task_Core5,
    /* ownerAppId     = */ SYSTEMAPPLICATION_OSCORE_CORE5,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Default_Init_Task_Core5_Dyn,
    /* cfgPrio        = */ 0U,
    /* schdType       = */ OS_TASK_NON,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* taskId         = */ DEFAULT_INIT_TASK_CORE5,
    /* coreId         = */ OS_CORE_ID_5,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_ANY
};
const Os_TaskCfgType OsCfg_Task_Idle_Task_Core5 =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Idle_Task_Core5,
    /* ownerAppId     = */ SYSTEMAPPLICATION_OSCORE_CORE5,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Idle_Task_Core5_Dyn,
    /* cfgPrio        = */ 13U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* taskId         = */ IDLE_TASK_CORE5,
    /* coreId         = */ OS_CORE_ID_5,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_ANY
};
const Os_TaskCfgType OsCfg_Task_App1_Task_1ms_Core5_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_1ms_Core5_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE5_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_1ms_Core5_QM_Dyn,
    /* cfgPrio        = */ 3U,
    /* schdType       = */ OS_TASK_NON,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* taskId         = */ APP1_TASK_1MS_CORE5_QM,
    /* coreId         = */ OS_CORE_ID_5,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_5ms_Core5_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_5ms_Core5_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE5_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_5ms_Core5_QM_Dyn,
    /* cfgPrio        = */ 4U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* taskId         = */ APP1_TASK_5MS_CORE5_QM,
    /* coreId         = */ OS_CORE_ID_5,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_10ms_Core5_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_10ms_Core5_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE5_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_10ms_Core5_QM_Dyn,
    /* cfgPrio        = */ 6U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* taskId         = */ APP1_TASK_10MS_CORE5_QM,
    /* coreId         = */ OS_CORE_ID_5,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_20ms_Core5_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_20ms_Core5_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE5_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_20ms_Core5_QM_Dyn,
    /* cfgPrio        = */ 7U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* taskId         = */ APP1_TASK_20MS_CORE5_QM,
    /* coreId         = */ OS_CORE_ID_5,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_50ms_Core5_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_50ms_Core5_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE5_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_50ms_Core5_QM_Dyn,
    /* cfgPrio        = */ 8U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* taskId         = */ APP1_TASK_50MS_CORE5_QM,
    /* coreId         = */ OS_CORE_ID_5,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_100ms_Core5_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_100ms_Core5_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE5_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_100ms_Core5_QM_Dyn,
    /* cfgPrio        = */ 9U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* taskId         = */ APP1_TASK_100MS_CORE5_QM,
    /* coreId         = */ OS_CORE_ID_5,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_SWC_Init_Task_Core5 =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_SWC_Init_Task_Core5,
    /* ownerAppId     = */ APP1_APPLICATION_CORE5_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_SWC_Init_Task_Core5_Dyn,
    /* cfgPrio        = */ 1U,
    /* schdType       = */ OS_TASK_NON,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* taskId         = */ SWC_INIT_TASK_CORE5,
    /* coreId         = */ OS_CORE_ID_5,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_ANY
};
const Os_TaskCfgType OsCfg_Task_App1_Task_UDS_Core5_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_UDS_Core5_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE5_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_UDS_Core5_QM_Dyn,
    /* cfgPrio        = */ 2U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |OS_APP1_APPLICATION_CORE5_QM_ACCESS |
                          OS_BSW_APPLICATION_CORE5_QM_ACCESS),
    /* taskId         = */ APP1_TASK_UDS_CORE5_QM,
    /* coreId         = */ OS_CORE_ID_5,
    /* taskType       = */ OS_TASK_ET,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_200ms_Core5_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_200ms_Core5_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE5_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_200ms_Core5_QM_Dyn,
    /* cfgPrio        = */ 10U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* taskId         = */ APP1_TASK_200MS_CORE5_QM,
    /* coreId         = */ OS_CORE_ID_5,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_500ms_Core5_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_500ms_Core5_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE5_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_500ms_Core5_QM_Dyn,
    /* cfgPrio        = */ 11U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* taskId         = */ APP1_TASK_500MS_CORE5_QM,
    /* coreId         = */ OS_CORE_ID_5,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_App1_Task_1000ms_Core5_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_App1_Task_1000ms_Core5_QM,
    /* ownerAppId     = */ APP1_APPLICATION_CORE5_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_App1_Task_1000ms_Core5_QM_Dyn,
    /* cfgPrio        = */ 12U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* taskId         = */ APP1_TASK_1000MS_CORE5_QM,
    /* coreId         = */ OS_CORE_ID_5,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
const Os_TaskCfgType OsCfg_Task_Bsw_Task_10ms_Core5_QM =
{
    /* contextCfg     = */ &OsCfg_Arch_Context_Bsw_Task_10ms_Core5_QM,
    /* ownerAppId     = */ BSW_APPLICATION_CORE5_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg      = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg       = */ NULL_PTR,
    /* taskMpCfg      = */ NULL_PTR,
#endif
    /* taskDyn        = */ &OsCfg_Task_Bsw_Task_10ms_Core5_QM_Dyn,
    /* cfgPrio        = */ 5U,
    /* schdType       = */ OS_TASK_FULL,
    /* maxActivations = */ 100U,
    /* preTaskHook    = */ NULL_PTR,
    /* postTaskHook   = */ NULL_PTR,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |OS_BSW_APPLICATION_CORE5_QM_ACCESS),
    /* taskId         = */ BSW_TASK_10MS_CORE5_QM,
    /* coreId         = */ OS_CORE_ID_5,
    /* taskType       = */ OS_TASK_BT,
    /* appMode        = */ OS_APPMODE_NONE
};
/* Task config parameters end. */

/* Isr config parameters start. */
const Os_IsrCfgType OsCfg_Isr_CounterIsr_SystemTimer_Core0 =
{
    /* ifcounterIsr = */ TRUE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_CounterIsr_SystemTimer_Core0,
    /* ownerAppId  = */ SYSTEMAPPLICATION_OSCORE_CORE0,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_CounterIsr_SystemTimer_Core0_Dyn,
    /* source      = */ &OsCfg_Arch_Source_CounterIsr_SystemTimer_Core0,
    /* coreId      = */ OS_CORE_ID_0,
    /* isrId       = */ COUNTERISR_SYSTEMTIMER_CORE0,
    /* counterId   = */ SYSTEMTIMER_CORE0
};
const Os_IsrCfgType OsCfg_Isr_MultiCommIsr_Core0 =
{
    /* ifcounterIsr = */ FALSE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_MultiCommIsr_Core0,
    /* ownerAppId  = */ SYSTEMAPPLICATION_OSCORE_CORE0,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_MultiCommIsr_Core0_Dyn,
    /* source      = */ &OsCfg_Arch_Source_MultiCommIsr_Core0,
    /* coreId      = */ OS_CORE_ID_0,
    /* isrId       = */ MULTICOMMISR_CORE0,
    /* counterId   = */ ((CounterType)0U)
};
const Os_IsrCfgType OsCfg_Isr_Os_ISR_37_STM0_CH1 =
{
    /* ifcounterIsr = */ TRUE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_Os_ISR_37_STM0_CH1,
    /* ownerAppId  = */ BSW_APPLICATION_CORE0_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_Os_ISR_37_STM0_CH1_Dyn,
    /* source      = */ &OsCfg_Arch_Source_Os_ISR_37_STM0_CH1,
    /* coreId      = */ OS_CORE_ID_0,
    /* isrId       = */ OS_ISR_37_STM0_CH1,
    /* counterId   = */ OS_MONITOR_COUNTER
};
const Os_IsrCfgType OsCfg_Isr_CounterIsr_SystemTimer_Core1 =
{
    /* ifcounterIsr = */ TRUE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_CounterIsr_SystemTimer_Core1,
    /* ownerAppId  = */ SYSTEMAPPLICATION_OSCORE_CORE1,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_CounterIsr_SystemTimer_Core1_Dyn,
    /* source      = */ &OsCfg_Arch_Source_CounterIsr_SystemTimer_Core1,
    /* coreId      = */ OS_CORE_ID_1,
    /* isrId       = */ COUNTERISR_SYSTEMTIMER_CORE1,
    /* counterId   = */ SYSTEMTIMER_CORE1
};
const Os_IsrCfgType OsCfg_Isr_MultiCommIsr_Core1 =
{
    /* ifcounterIsr = */ FALSE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_MultiCommIsr_Core1,
    /* ownerAppId  = */ SYSTEMAPPLICATION_OSCORE_CORE1,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_MultiCommIsr_Core1_Dyn,
    /* source      = */ &OsCfg_Arch_Source_MultiCommIsr_Core1,
    /* coreId      = */ OS_CORE_ID_1,
    /* isrId       = */ MULTICOMMISR_CORE1,
    /* counterId   = */ ((CounterType)0U)
};
const Os_IsrCfgType OsCfg_Isr_CounterIsr_SystemTimer_Core2 =
{
    /* ifcounterIsr = */ TRUE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_CounterIsr_SystemTimer_Core2,
    /* ownerAppId  = */ SYSTEMAPPLICATION_OSCORE_CORE2,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_CounterIsr_SystemTimer_Core2_Dyn,
    /* source      = */ &OsCfg_Arch_Source_CounterIsr_SystemTimer_Core2,
    /* coreId      = */ OS_CORE_ID_2,
    /* isrId       = */ COUNTERISR_SYSTEMTIMER_CORE2,
    /* counterId   = */ SYSTEMTIMER_CORE2
};
const Os_IsrCfgType OsCfg_Isr_MultiCommIsr_Core2 =
{
    /* ifcounterIsr = */ FALSE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_MultiCommIsr_Core2,
    /* ownerAppId  = */ SYSTEMAPPLICATION_OSCORE_CORE2,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_MultiCommIsr_Core2_Dyn,
    /* source      = */ &OsCfg_Arch_Source_MultiCommIsr_Core2,
    /* coreId      = */ OS_CORE_ID_2,
    /* isrId       = */ MULTICOMMISR_CORE2,
    /* counterId   = */ ((CounterType)0U)
};
const Os_IsrCfgType OsCfg_Isr_CounterIsr_SystemTimer_Core3 =
{
    /* ifcounterIsr = */ TRUE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_CounterIsr_SystemTimer_Core3,
    /* ownerAppId  = */ SYSTEMAPPLICATION_OSCORE_CORE3,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_CounterIsr_SystemTimer_Core3_Dyn,
    /* source      = */ &OsCfg_Arch_Source_CounterIsr_SystemTimer_Core3,
    /* coreId      = */ OS_CORE_ID_3,
    /* isrId       = */ COUNTERISR_SYSTEMTIMER_CORE3,
    /* counterId   = */ SYSTEMTIMER_CORE3
};
const Os_IsrCfgType OsCfg_Isr_MultiCommIsr_Core3 =
{
    /* ifcounterIsr = */ FALSE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_MultiCommIsr_Core3,
    /* ownerAppId  = */ SYSTEMAPPLICATION_OSCORE_CORE3,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_MultiCommIsr_Core3_Dyn,
    /* source      = */ &OsCfg_Arch_Source_MultiCommIsr_Core3,
    /* coreId      = */ OS_CORE_ID_3,
    /* isrId       = */ MULTICOMMISR_CORE3,
    /* counterId   = */ ((CounterType)0U)
};
const Os_IsrCfgType OsCfg_Isr_CounterIsr_SystemTimer_Core4 =
{
    /* ifcounterIsr = */ TRUE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_CounterIsr_SystemTimer_Core4,
    /* ownerAppId  = */ SYSTEMAPPLICATION_OSCORE_CORE4,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_CounterIsr_SystemTimer_Core4_Dyn,
    /* source      = */ &OsCfg_Arch_Source_CounterIsr_SystemTimer_Core4,
    /* coreId      = */ OS_CORE_ID_4,
    /* isrId       = */ COUNTERISR_SYSTEMTIMER_CORE4,
    /* counterId   = */ SYSTEMTIMER_CORE4
};
const Os_IsrCfgType OsCfg_Isr_MultiCommIsr_Core4 =
{
    /* ifcounterIsr = */ FALSE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_MultiCommIsr_Core4,
    /* ownerAppId  = */ SYSTEMAPPLICATION_OSCORE_CORE4,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_MultiCommIsr_Core4_Dyn,
    /* source      = */ &OsCfg_Arch_Source_MultiCommIsr_Core4,
    /* coreId      = */ OS_CORE_ID_4,
    /* isrId       = */ MULTICOMMISR_CORE4,
    /* counterId   = */ ((CounterType)0U)
};
const Os_IsrCfgType OsCfg_Isr_Os_ISR_450_MCAN11_CH1 =
{
    /* ifcounterIsr = */ FALSE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_Os_ISR_450_MCAN11_CH1,
    /* ownerAppId  = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_Os_ISR_450_MCAN11_CH1_Dyn,
    /* source      = */ &OsCfg_Arch_Source_Os_ISR_450_MCAN11_CH1,
    /* coreId      = */ OS_CORE_ID_4,
    /* isrId       = */ OS_ISR_450_MCAN11_CH1,
    /* counterId   = */ ((CounterType)0U)
};
const Os_IsrCfgType OsCfg_Isr_Os_ISR_449_MCAN11_CH0 =
{
    /* ifcounterIsr = */ FALSE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_Os_ISR_449_MCAN11_CH0,
    /* ownerAppId  = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_Os_ISR_449_MCAN11_CH0_Dyn,
    /* source      = */ &OsCfg_Arch_Source_Os_ISR_449_MCAN11_CH0,
    /* coreId      = */ OS_CORE_ID_4,
    /* isrId       = */ OS_ISR_449_MCAN11_CH0,
    /* counterId   = */ ((CounterType)0U)
};
const Os_IsrCfgType OsCfg_Isr_Os_ISR_699_MCAN6_CH1 =
{
    /* ifcounterIsr = */ FALSE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_Os_ISR_699_MCAN6_CH1,
    /* ownerAppId  = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_Os_ISR_699_MCAN6_CH1_Dyn,
    /* source      = */ &OsCfg_Arch_Source_Os_ISR_699_MCAN6_CH1,
    /* coreId      = */ OS_CORE_ID_4,
    /* isrId       = */ OS_ISR_699_MCAN6_CH1,
    /* counterId   = */ ((CounterType)0U)
};
const Os_IsrCfgType OsCfg_Isr_Os_ISR_698_MCAN6_CH0 =
{
    /* ifcounterIsr = */ FALSE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_Os_ISR_698_MCAN6_CH0,
    /* ownerAppId  = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_Os_ISR_698_MCAN6_CH0_Dyn,
    /* source      = */ &OsCfg_Arch_Source_Os_ISR_698_MCAN6_CH0,
    /* coreId      = */ OS_CORE_ID_4,
    /* isrId       = */ OS_ISR_698_MCAN6_CH0,
    /* counterId   = */ ((CounterType)0U)
};
const Os_IsrCfgType OsCfg_Isr_Os_ISR_689_MCAN1_CH1 =
{
    /* ifcounterIsr = */ FALSE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_Os_ISR_689_MCAN1_CH1,
    /* ownerAppId  = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_Os_ISR_689_MCAN1_CH1_Dyn,
    /* source      = */ &OsCfg_Arch_Source_Os_ISR_689_MCAN1_CH1,
    /* coreId      = */ OS_CORE_ID_4,
    /* isrId       = */ OS_ISR_689_MCAN1_CH1,
    /* counterId   = */ ((CounterType)0U)
};
const Os_IsrCfgType OsCfg_Isr_Os_ISR_688_MCAN1_CH0 =
{
    /* ifcounterIsr = */ FALSE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_Os_ISR_688_MCAN1_CH0,
    /* ownerAppId  = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_Os_ISR_688_MCAN1_CH0_Dyn,
    /* source      = */ &OsCfg_Arch_Source_Os_ISR_688_MCAN1_CH0,
    /* coreId      = */ OS_CORE_ID_4,
    /* isrId       = */ OS_ISR_688_MCAN1_CH0,
    /* counterId   = */ ((CounterType)0U)
};
const Os_IsrCfgType OsCfg_Isr_Os_ISR_446_MCAN9_CH1 =
{
    /* ifcounterIsr = */ FALSE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_Os_ISR_446_MCAN9_CH1,
    /* ownerAppId  = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_Os_ISR_446_MCAN9_CH1_Dyn,
    /* source      = */ &OsCfg_Arch_Source_Os_ISR_446_MCAN9_CH1,
    /* coreId      = */ OS_CORE_ID_4,
    /* isrId       = */ OS_ISR_446_MCAN9_CH1,
    /* counterId   = */ ((CounterType)0U)
};
const Os_IsrCfgType OsCfg_Isr_Os_ISR_445_MCAN9_CH0 =
{
    /* ifcounterIsr = */ FALSE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_Os_ISR_445_MCAN9_CH0,
    /* ownerAppId  = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_Os_ISR_445_MCAN9_CH0_Dyn,
    /* source      = */ &OsCfg_Arch_Source_Os_ISR_445_MCAN9_CH0,
    /* coreId      = */ OS_CORE_ID_4,
    /* isrId       = */ OS_ISR_445_MCAN9_CH0,
    /* counterId   = */ ((CounterType)0U)
};
const Os_IsrCfgType OsCfg_Isr_Os_ISR_693_MCAN3_CH1 =
{
    /* ifcounterIsr = */ FALSE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_Os_ISR_693_MCAN3_CH1,
    /* ownerAppId  = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_Os_ISR_693_MCAN3_CH1_Dyn,
    /* source      = */ &OsCfg_Arch_Source_Os_ISR_693_MCAN3_CH1,
    /* coreId      = */ OS_CORE_ID_4,
    /* isrId       = */ OS_ISR_693_MCAN3_CH1,
    /* counterId   = */ ((CounterType)0U)
};
const Os_IsrCfgType OsCfg_Isr_Os_ISR_692_MCAN3_CH0 =
{
    /* ifcounterIsr = */ FALSE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_Os_ISR_692_MCAN3_CH0,
    /* ownerAppId  = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_Os_ISR_692_MCAN3_CH0_Dyn,
    /* source      = */ &OsCfg_Arch_Source_Os_ISR_692_MCAN3_CH0,
    /* coreId      = */ OS_CORE_ID_4,
    /* isrId       = */ OS_ISR_692_MCAN3_CH0,
    /* counterId   = */ ((CounterType)0U)
};
const Os_IsrCfgType OsCfg_Isr_Os_ISR_691_MCAN2_CH1 =
{
    /* ifcounterIsr = */ FALSE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_Os_ISR_691_MCAN2_CH1,
    /* ownerAppId  = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_Os_ISR_691_MCAN2_CH1_Dyn,
    /* source      = */ &OsCfg_Arch_Source_Os_ISR_691_MCAN2_CH1,
    /* coreId      = */ OS_CORE_ID_4,
    /* isrId       = */ OS_ISR_691_MCAN2_CH1,
    /* counterId   = */ ((CounterType)0U)
};
const Os_IsrCfgType OsCfg_Isr_Os_ISR_690_MCAN2_CH0 =
{
    /* ifcounterIsr = */ FALSE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_Os_ISR_690_MCAN2_CH0,
    /* ownerAppId  = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_Os_ISR_690_MCAN2_CH0_Dyn,
    /* source      = */ &OsCfg_Arch_Source_Os_ISR_690_MCAN2_CH0,
    /* coreId      = */ OS_CORE_ID_4,
    /* isrId       = */ OS_ISR_690_MCAN2_CH0,
    /* counterId   = */ ((CounterType)0U)
};
const Os_IsrCfgType OsCfg_Isr_Os_ISR_701_MCAN7_CH1 =
{
    /* ifcounterIsr = */ FALSE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_Os_ISR_701_MCAN7_CH1,
    /* ownerAppId  = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_Os_ISR_701_MCAN7_CH1_Dyn,
    /* source      = */ &OsCfg_Arch_Source_Os_ISR_701_MCAN7_CH1,
    /* coreId      = */ OS_CORE_ID_4,
    /* isrId       = */ OS_ISR_701_MCAN7_CH1,
    /* counterId   = */ ((CounterType)0U)
};
const Os_IsrCfgType OsCfg_Isr_Os_ISR_700_MCAN7_CH0 =
{
    /* ifcounterIsr = */ FALSE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_Os_ISR_700_MCAN7_CH0,
    /* ownerAppId  = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_Os_ISR_700_MCAN7_CH0_Dyn,
    /* source      = */ &OsCfg_Arch_Source_Os_ISR_700_MCAN7_CH0,
    /* coreId      = */ OS_CORE_ID_4,
    /* isrId       = */ OS_ISR_700_MCAN7_CH0,
    /* counterId   = */ ((CounterType)0U)
};
const Os_IsrCfgType OsCfg_Isr_Os_ISR_698_LINTX_CH6 =
{
    /* ifcounterIsr = */ FALSE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_Os_ISR_698_LINTX_CH6,
    /* ownerAppId  = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_Os_ISR_698_LINTX_CH6_Dyn,
    /* source      = */ &OsCfg_Arch_Source_Os_ISR_698_LINTX_CH6,
    /* coreId      = */ OS_CORE_ID_4,
    /* isrId       = */ OS_ISR_698_LINTX_CH6,
    /* counterId   = */ ((CounterType)0U)
};
const Os_IsrCfgType OsCfg_Isr_Os_ISR_698_LINRX_CH6 =
{
    /* ifcounterIsr = */ FALSE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_Os_ISR_698_LINRX_CH6,
    /* ownerAppId  = */ BSW_APPLICATION_CORE4_QM,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_Os_ISR_698_LINRX_CH6_Dyn,
    /* source      = */ &OsCfg_Arch_Source_Os_ISR_698_LINRX_CH6,
    /* coreId      = */ OS_CORE_ID_4,
    /* isrId       = */ OS_ISR_698_LINRX_CH6,
    /* counterId   = */ ((CounterType)0U)
};
const Os_IsrCfgType OsCfg_Isr_CounterIsr_SystemTimer_Core5 =
{
    /* ifcounterIsr = */ TRUE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_CounterIsr_SystemTimer_Core5,
    /* ownerAppId  = */ SYSTEMAPPLICATION_OSCORE_CORE5,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_CounterIsr_SystemTimer_Core5_Dyn,
    /* source      = */ &OsCfg_Arch_Source_CounterIsr_SystemTimer_Core5,
    /* coreId      = */ OS_CORE_ID_5,
    /* isrId       = */ COUNTERISR_SYSTEMTIMER_CORE5,
    /* counterId   = */ SYSTEMTIMER_CORE5
};
const Os_IsrCfgType OsCfg_Isr_MultiCommIsr_Core5 =
{
    /* ifcounterIsr = */ FALSE,
    /* ifTpIsr     = */ FALSE,
    /* contextCfg  = */ &OsCfg_Arch_Context_MultiCommIsr_Core5,
    /* ownerAppId  = */ SYSTEMAPPLICATION_OSCORE_CORE5,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpCfg   = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* appMpCfg    = */ NULL_PTR,
    /* isrMpCfg    = */ NULL_PTR,
#endif
    /* isrDyn      = */ &OsCfg_Isr_MultiCommIsr_Core5_Dyn,
    /* source      = */ &OsCfg_Arch_Source_MultiCommIsr_Core5,
    /* coreId      = */ OS_CORE_ID_5,
    /* isrId       = */ MULTICOMMISR_CORE5,
    /* counterId   = */ ((CounterType)0U)
};
const Os_IsrCat1CfgType OsCfg_Cat1Isr_Os_ISR_612_TIM6_CH6 =
{
    /* source     = */ &OsCfg_Arch_Source_Os_ISR_612_TIM6_CH6,
    /* ownerAppId = */ BSW_APPLICATION_CORE3_QM,
    /* coreId     = */ OS_CORE_ID_3
};
const Os_IsrCat1CfgType OsCfg_Cat1Isr_Os_ISR_777_TIM3_CH4 =
{
    /* source     = */ &OsCfg_Arch_Source_Os_ISR_777_TIM3_CH4,
    /* ownerAppId = */ BSW_APPLICATION_CORE3_QM,
    /* coreId     = */ OS_CORE_ID_3
};
const Os_IsrCat1CfgType OsCfg_Cat1Isr_Os_ISR_776_TIM3_CH3 =
{
    /* source     = */ &OsCfg_Arch_Source_Os_ISR_776_TIM3_CH3,
    /* ownerAppId = */ BSW_APPLICATION_CORE3_QM,
    /* coreId     = */ OS_CORE_ID_3
};
const Os_IsrCat1CfgType OsCfg_Cat1Isr_Os_ISR_775_TIM3_CH2 =
{
    /* source     = */ &OsCfg_Arch_Source_Os_ISR_775_TIM3_CH2,
    /* ownerAppId = */ BSW_APPLICATION_CORE3_QM,
    /* coreId     = */ OS_CORE_ID_3
};
const Os_IsrCat1CfgType OsCfg_Cat1Isr_Os_ISR_613_TIM6_CH5 =
{
    /* source     = */ &OsCfg_Arch_Source_Os_ISR_613_TIM6_CH5,
    /* ownerAppId = */ BSW_APPLICATION_CORE3_QM,
    /* coreId     = */ OS_CORE_ID_3
};
const Os_IsrCat1CfgType OsCfg_Cat1Isr_Os_ISR_614_TIM6_CH4 =
{
    /* source     = */ &OsCfg_Arch_Source_Os_ISR_614_TIM6_CH4,
    /* ownerAppId = */ BSW_APPLICATION_CORE3_QM,
    /* coreId     = */ OS_CORE_ID_3
};
const Os_IsrCat1CfgType OsCfg_Cat1Isr_Os_ISR_615_TIM6_CH3 =
{
    /* source     = */ &OsCfg_Arch_Source_Os_ISR_615_TIM6_CH3,
    /* ownerAppId = */ BSW_APPLICATION_CORE3_QM,
    /* coreId     = */ OS_CORE_ID_3
};
const Os_IsrCat1CfgType OsCfg_Cat1Isr_Os_ISR_616_TIM6_CH2 =
{
    /* source     = */ &OsCfg_Arch_Source_Os_ISR_616_TIM6_CH2,
    /* ownerAppId = */ BSW_APPLICATION_CORE3_QM,
    /* coreId     = */ OS_CORE_ID_3
};
const Os_IsrCat1CfgType OsCfg_Cat1Isr_Os_ISR_617_TIM6_CH1 =
{
    /* source     = */ &OsCfg_Arch_Source_Os_ISR_617_TIM6_CH1,
    /* ownerAppId = */ BSW_APPLICATION_CORE3_QM,
    /* coreId     = */ OS_CORE_ID_3
};
const Os_IsrCat1CfgType OsCfg_Cat1Isr_Os_ISR_618_TIM6_CH0 =
{
    /* source     = */ &OsCfg_Arch_Source_Os_ISR_618_TIM6_CH0,
    /* ownerAppId = */ BSW_APPLICATION_CORE3_QM,
    /* coreId     = */ OS_CORE_ID_3
};
const Os_IsrCat1CfgType OsCfg_Cat1Isr_Os_ISR_867_TIM4_CH0 =
{
    /* source     = */ &OsCfg_Arch_Source_Os_ISR_867_TIM4_CH0,
    /* ownerAppId = */ BSW_APPLICATION_CORE3_QM,
    /* coreId     = */ OS_CORE_ID_3
};
const Os_IsrCat1CfgType OsCfg_Cat1Isr_Os_ISR_840_ATOM0_CH3 =
{
    /* source     = */ &OsCfg_Arch_Source_Os_ISR_840_ATOM0_CH3,
    /* ownerAppId = */ BSW_APPLICATION_CORE3_QM,
    /* coreId     = */ OS_CORE_ID_3
};
const Os_IsrCat1CfgType OsCfg_Cat1Isr_Os_ISR_874_TIM4_CH7 =
{
    /* source     = */ &OsCfg_Arch_Source_Os_ISR_874_TIM4_CH7,
    /* ownerAppId = */ BSW_APPLICATION_CORE3_QM,
    /* coreId     = */ OS_CORE_ID_3
};
const Os_IsrCat1CfgType OsCfg_Cat1Isr_Os_ISR_117_DMA1_CH0 =
{
    /* source     = */ &OsCfg_Arch_Source_Os_ISR_117_DMA1_CH0,
    /* ownerAppId = */ BSW_APPLICATION_CORE5_QM,
    /* coreId     = */ OS_CORE_ID_5
};
/* Isr config parameters end. */

/* Counter config parameters start. */
const Os_CounterPitCfgType OsCfg_Counter_SystemTimer_Core0 =
{
    {
        /* counterBase->Os_CntExpList = */ &Os_CntExpList_SystemTimer_Core0,
        /* counterBase->maxAllowValue = */ 0xFFFFFFFFU,
        /* counterBase->minCycle      = */ 1U,
        /* counterBase->ticksPerBase  = */ 1U,
        /* counterBase->counterType   = */ OS_COUNTER_PIT,
        /* counterBase->coreId        = */ OS_CORE_ID_0,
        /* counterBase->ownerAppId    = */ SYSTEMAPPLICATION_OSCORE_CORE0,
        /* counterBase->counterId     = */ SYSTEMTIMER_CORE0,
        /* counterBase->accessingApps = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_APP1_APPLICATION_CORE0_QM_ACCESS |
                          OS_BSW_APPLICATION_CORE0_QM_ACCESS),
        /* counterBase->share = */ 0U
    },
    /* counterDyn                     = */ &OsCfg_Counter_SystemTimer_Core0_Dyn,
    /* HwConfig                       = */ &OsCfg_Arch_TimerPit_SystemTimer_Core0
};
const Os_CounterPitCfgType OsCfg_Counter_SystemTimer_Core1 =
{
    {
        /* counterBase->Os_CntExpList = */ &Os_CntExpList_SystemTimer_Core1,
        /* counterBase->maxAllowValue = */ 0xFFFFFFFFU,
        /* counterBase->minCycle      = */ 1U,
        /* counterBase->ticksPerBase  = */ 1U,
        /* counterBase->counterType   = */ OS_COUNTER_PIT,
        /* counterBase->coreId        = */ OS_CORE_ID_1,
        /* counterBase->ownerAppId    = */ SYSTEMAPPLICATION_OSCORE_CORE1,
        /* counterBase->counterId     = */ SYSTEMTIMER_CORE1,
        /* counterBase->accessingApps = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS |
                          OS_BSW_APPLICATION_CORE1_QM_ACCESS),
        /* counterBase->share = */ 0U
    },
    /* counterDyn                     = */ &OsCfg_Counter_SystemTimer_Core1_Dyn,
    /* HwConfig                       = */ &OsCfg_Arch_TimerPit_SystemTimer_Core1
};
const Os_CounterPitCfgType OsCfg_Counter_SystemTimer_Core2 =
{
    {
        /* counterBase->Os_CntExpList = */ &Os_CntExpList_SystemTimer_Core2,
        /* counterBase->maxAllowValue = */ 0xFFFFFFFFU,
        /* counterBase->minCycle      = */ 1U,
        /* counterBase->ticksPerBase  = */ 1U,
        /* counterBase->counterType   = */ OS_COUNTER_PIT,
        /* counterBase->coreId        = */ OS_CORE_ID_2,
        /* counterBase->ownerAppId    = */ SYSTEMAPPLICATION_OSCORE_CORE2,
        /* counterBase->counterId     = */ SYSTEMTIMER_CORE2,
        /* counterBase->accessingApps = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS |
                          OS_BSW_APPLICATION_CORE2_QM_ACCESS),
        /* counterBase->share = */ 0U
    },
    /* counterDyn                     = */ &OsCfg_Counter_SystemTimer_Core2_Dyn,
    /* HwConfig                       = */ &OsCfg_Arch_TimerPit_SystemTimer_Core2
};
const Os_CounterPitCfgType OsCfg_Counter_SystemTimer_Core3 =
{
    {
        /* counterBase->Os_CntExpList = */ &Os_CntExpList_SystemTimer_Core3,
        /* counterBase->maxAllowValue = */ 0xFFFFFFFFU,
        /* counterBase->minCycle      = */ 1U,
        /* counterBase->ticksPerBase  = */ 1U,
        /* counterBase->counterType   = */ OS_COUNTER_PIT,
        /* counterBase->coreId        = */ OS_CORE_ID_3,
        /* counterBase->ownerAppId    = */ SYSTEMAPPLICATION_OSCORE_CORE3,
        /* counterBase->counterId     = */ SYSTEMTIMER_CORE3,
        /* counterBase->accessingApps = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |OS_APP1_APPLICATION_CORE3_QM_ACCESS |
                          OS_BSW_APPLICATION_CORE3_QM_ACCESS),
        /* counterBase->share = */ 0U
    },
    /* counterDyn                     = */ &OsCfg_Counter_SystemTimer_Core3_Dyn,
    /* HwConfig                       = */ &OsCfg_Arch_TimerPit_SystemTimer_Core3
};
const Os_CounterPitCfgType OsCfg_Counter_SystemTimer_Core4 =
{
    {
        /* counterBase->Os_CntExpList = */ &Os_CntExpList_SystemTimer_Core4,
        /* counterBase->maxAllowValue = */ 0xFFFFFFFFU,
        /* counterBase->minCycle      = */ 1U,
        /* counterBase->ticksPerBase  = */ 1U,
        /* counterBase->counterType   = */ OS_COUNTER_PIT,
        /* counterBase->coreId        = */ OS_CORE_ID_4,
        /* counterBase->ownerAppId    = */ SYSTEMAPPLICATION_OSCORE_CORE4,
        /* counterBase->counterId     = */ SYSTEMTIMER_CORE4,
        /* counterBase->accessingApps = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_BSW_APPLICATION_CORE4_QM_ACCESS |
                          OS_APP1_APPLICATION_CORE4_QM_ACCESS),
        /* counterBase->share = */ 0U
    },
    /* counterDyn                     = */ &OsCfg_Counter_SystemTimer_Core4_Dyn,
    /* HwConfig                       = */ &OsCfg_Arch_TimerPit_SystemTimer_Core4
};
const Os_CounterPitCfgType OsCfg_Counter_SystemTimer_Core5 =
{
    {
        /* counterBase->Os_CntExpList = */ &Os_CntExpList_SystemTimer_Core5,
        /* counterBase->maxAllowValue = */ 0xFFFFFFFFU,
        /* counterBase->minCycle      = */ 1U,
        /* counterBase->ticksPerBase  = */ 1U,
        /* counterBase->counterType   = */ OS_COUNTER_PIT,
        /* counterBase->coreId        = */ OS_CORE_ID_5,
        /* counterBase->ownerAppId    = */ SYSTEMAPPLICATION_OSCORE_CORE5,
        /* counterBase->counterId     = */ SYSTEMTIMER_CORE5,
        /* counterBase->accessingApps = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |OS_BSW_APPLICATION_CORE5_QM_ACCESS |
                          OS_APP1_APPLICATION_CORE5_QM_ACCESS),
        /* counterBase->share = */ 0U
    },
    /* counterDyn                     = */ &OsCfg_Counter_SystemTimer_Core5_Dyn,
    /* HwConfig                       = */ &OsCfg_Arch_TimerPit_SystemTimer_Core5
};
const Os_CounterHrtCfgType OsCfg_Counter_Os_Monitor_Counter =
{
    {
        /* counterBase->Os_CntExpList = */ NULL_PTR,
        /* counterBase->maxAllowValue = */ 0xFFFFFFFFU,
        /* counterBase->minCycle      = */ 1U,
        /* counterBase->ticksPerBase  = */ 1U,
        /* counterBase->counterType   = */ OS_COUNTER_HRT,
        /* counterBase->coreId        = */ OS_CORE_ID_0,
        /* counterBase->ownerAppId    = */ SYSTEMAPPLICATION_OSCORE_CORE0,
        /* counterBase->counterId     = */ OS_MONITOR_COUNTER,
        /* counterBase->accessingApps = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_APP1_APPLICATION_CORE0_QM_ACCESS |
                          OS_BSW_APPLICATION_CORE0_QM_ACCESS),
        /* counterBase->share = */ 0U
    },
    /* counterDyn                     = */ &OsCfg_Counter_Os_Monitor_Counter_Dyn,
    /* HwConfig                       = */ &OsCfg_Arch_TimerHrt_Os_Monitor_Counter
};
/* Counter config parameters end. */

/* Alarm config parameters start. */
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_1ms_Core0_QM_1ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core0,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_1MS_CORE0_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_1ms_Core0_QM_1ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE0_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE0_QM,
    /* coreId         = */ OS_CORE_ID_0,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 1U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_1MS_CORE0_QM_1MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_5ms_Core0_QM_5ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core0,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_5MS_CORE0_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_5ms_Core0_QM_5ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE0_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE0_QM,
    /* coreId         = */ OS_CORE_ID_0,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 5U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_5MS_CORE0_QM_5MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_10ms_Core0_QM_10ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core0,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_10MS_CORE0_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_10ms_Core0_QM_10ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE0_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE0_QM,
    /* coreId         = */ OS_CORE_ID_0,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 10U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_10MS_CORE0_QM_10MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_20ms_Core0_QM_20ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core0,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_20MS_CORE0_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_20ms_Core0_QM_20ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE0_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE0_QM,
    /* coreId         = */ OS_CORE_ID_0,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 20U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_20MS_CORE0_QM_20MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_50ms_Core0_QM_50ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core0,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_50MS_CORE0_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_50ms_Core0_QM_50ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE0_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE0_QM,
    /* coreId         = */ OS_CORE_ID_0,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 50U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_50MS_CORE0_QM_50MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_100ms_Core0_QM_100ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core0,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_100MS_CORE0_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_100ms_Core0_QM_100ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE0_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE0_QM,
    /* coreId         = */ OS_CORE_ID_0,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 100U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_100MS_CORE0_QM_100MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core0_QM_10ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core0,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = BSW_TASK_10MS_CORE0_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core0_QM_10ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_BSW_APPLICATION_CORE0_QM_ACCESS),
    /* ownerAppId     = */ BSW_APPLICATION_CORE0_QM,
    /* coreId         = */ OS_CORE_ID_0,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 10U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_BSW_TASK_10MS_CORE0_QM_10MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_5ms_Core0_QM_5ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core0,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = BSW_TASK_5MS_CORE0_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_5ms_Core0_QM_5ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_BSW_APPLICATION_CORE0_QM_ACCESS),
    /* ownerAppId     = */ BSW_APPLICATION_CORE0_QM,
    /* coreId         = */ OS_CORE_ID_0,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 5U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_BSW_TASK_5MS_CORE0_QM_5MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_10ms_Core1_QM_10ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core1,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_10MS_CORE1_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_10ms_Core1_QM_10ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE1_QM,
    /* coreId         = */ OS_CORE_ID_1,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 10U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_10MS_CORE1_QM_10MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_1ms_Core1_QM_1ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core1,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_1MS_CORE1_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_1ms_Core1_QM_1ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE1_QM,
    /* coreId         = */ OS_CORE_ID_1,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 1U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_1MS_CORE1_QM_1MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_5ms_Core1_QM_5ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core1,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_5MS_CORE1_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_5ms_Core1_QM_5ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE1_QM,
    /* coreId         = */ OS_CORE_ID_1,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 5U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_5MS_CORE1_QM_5MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_20ms_Core1_QM_20ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core1,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_20MS_CORE1_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_20ms_Core1_QM_20ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE1_QM,
    /* coreId         = */ OS_CORE_ID_1,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 20U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_20MS_CORE1_QM_20MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_50ms_Core1_QM_50ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core1,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_50MS_CORE1_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_50ms_Core1_QM_50ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE1_QM,
    /* coreId         = */ OS_CORE_ID_1,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 50U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_50MS_CORE1_QM_50MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_100ms_Core1_QM_100ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core1,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_100MS_CORE1_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_100ms_Core1_QM_100ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE1_QM,
    /* coreId         = */ OS_CORE_ID_1,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 100U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_100MS_CORE1_QM_100MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core1_QM_10ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core1,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = BSW_TASK_10MS_CORE1_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core1_QM_10ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_BSW_APPLICATION_CORE1_QM_ACCESS),
    /* ownerAppId     = */ BSW_APPLICATION_CORE1_QM,
    /* coreId         = */ OS_CORE_ID_1,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 10U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_BSW_TASK_10MS_CORE1_QM_10MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_50ms_Core2_QM_50ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core2,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_50MS_CORE2_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_50ms_Core2_QM_50ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE2_QM,
    /* coreId         = */ OS_CORE_ID_2,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 50U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_50MS_CORE2_QM_50MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_100ms_Core2_QM_100ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core2,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_100MS_CORE2_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_100ms_Core2_QM_100ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE2_QM,
    /* coreId         = */ OS_CORE_ID_2,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 100U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_100MS_CORE2_QM_100MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_10ms_Core2_QM_10ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core2,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_10MS_CORE2_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_10ms_Core2_QM_10ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE2_QM,
    /* coreId         = */ OS_CORE_ID_2,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 10U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_10MS_CORE2_QM_10MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_1000ms_Core2_QM_1000ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core2,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_1000MS_CORE2_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_1000ms_Core2_QM_1000ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE2_QM,
    /* coreId         = */ OS_CORE_ID_2,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 1000U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_1000MS_CORE2_QM_1000MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_1ms_Core2_QM_1ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core2,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_1MS_CORE2_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_1ms_Core2_QM_1ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE2_QM,
    /* coreId         = */ OS_CORE_ID_2,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 1U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_1MS_CORE2_QM_1MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_5ms_Core2_QM_5ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core2,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_5MS_CORE2_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_5ms_Core2_QM_5ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE2_QM,
    /* coreId         = */ OS_CORE_ID_2,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 5U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_5MS_CORE2_QM_5MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_20ms_Core2_QM_20ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core2,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_20MS_CORE2_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_20ms_Core2_QM_20ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE2_QM,
    /* coreId         = */ OS_CORE_ID_2,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 20U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_20MS_CORE2_QM_20MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core2_QM_10ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core2,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = BSW_TASK_10MS_CORE2_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core2_QM_10ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_BSW_APPLICATION_CORE2_QM_ACCESS),
    /* ownerAppId     = */ BSW_APPLICATION_CORE2_QM,
    /* coreId         = */ OS_CORE_ID_2,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 10U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_BSW_TASK_10MS_CORE2_QM_10MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_Task_1ms_Core3_QM_1ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core3,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = TASK_1MS_CORE3_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_Task_1ms_Core3_QM_1ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE3_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE3_QM,
    /* coreId         = */ OS_CORE_ID_3,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 1U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_TASK_1MS_CORE3_QM_1MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_Task_100us_Core3_QM_100us =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_NONE,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core3,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = TASK_100US_CORE3_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_Task_100us_Core3_QM_100us_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE3_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE3_QM,
    /* coreId         = */ OS_CORE_ID_3,
    /* alarmTime      = */ 1U,
    /* autoCycle      = */ 1U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_TASK_100US_CORE3_QM_100US
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_Task_5ms_Core3_QM_5ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core3,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = TASK_5MS_CORE3_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_Task_5ms_Core3_QM_5ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_BSW_APPLICATION_CORE3_QM_ACCESS),
    /* ownerAppId     = */ BSW_APPLICATION_CORE3_QM,
    /* coreId         = */ OS_CORE_ID_3,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 5U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_TASK_5MS_CORE3_QM_5MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_1ms_Core4_QM_1ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core4,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_1MS_CORE4_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_1ms_Core4_QM_1ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE4_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 1U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_1MS_CORE4_QM_1MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_5ms_Core4_QM_5ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core4,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_5MS_CORE4_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_5ms_Core4_QM_5ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE4_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 5U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_5MS_CORE4_QM_5MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_10ms_Core4_QM_10ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core4,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_10MS_CORE4_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_10ms_Core4_QM_10ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE4_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 10U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_10MS_CORE4_QM_10MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_20ms_Core4_QM_20ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core4,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_20MS_CORE4_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_20ms_Core4_QM_20ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE4_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 20U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_20MS_CORE4_QM_20MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_50ms_Core4_QM_50ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core4,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_50MS_CORE4_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_50ms_Core4_QM_50ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE4_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 50U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_50MS_CORE4_QM_50MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_100ms_Core4_QM_100ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core4,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_100MS_CORE4_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_100ms_Core4_QM_100ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE4_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 100U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_100MS_CORE4_QM_100MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_100ms_Core4_QM_100ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core4,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = BSW_TASK_100MS_CORE4_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_100ms_Core4_QM_100ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_BSW_APPLICATION_CORE4_QM_ACCESS),
    /* ownerAppId     = */ BSW_APPLICATION_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 100U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_BSW_TASK_100MS_CORE4_QM_100MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_50ms_Core4_QM_50ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core4,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = BSW_TASK_50MS_CORE4_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_50ms_Core4_QM_50ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_BSW_APPLICATION_CORE4_QM_ACCESS),
    /* ownerAppId     = */ BSW_APPLICATION_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 50U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_BSW_TASK_50MS_CORE4_QM_50MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_20ms_Core4_QM_20ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core4,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = BSW_TASK_20MS_CORE4_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_20ms_Core4_QM_20ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_BSW_APPLICATION_CORE4_QM_ACCESS),
    /* ownerAppId     = */ BSW_APPLICATION_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 20U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_BSW_TASK_20MS_CORE4_QM_20MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core4_QM_10ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core4,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = BSW_TASK_10MS_CORE4_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core4_QM_10ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_BSW_APPLICATION_CORE4_QM_ACCESS),
    /* ownerAppId     = */ BSW_APPLICATION_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 10U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_BSW_TASK_10MS_CORE4_QM_10MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_5ms_Core4_QM_5ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core4,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = BSW_TASK_5MS_CORE4_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_5ms_Core4_QM_5ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_BSW_APPLICATION_CORE4_QM_ACCESS),
    /* ownerAppId     = */ BSW_APPLICATION_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 5U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_BSW_TASK_5MS_CORE4_QM_5MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_1ms_Core4_QM_1ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core4,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = BSW_TASK_1MS_CORE4_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_1ms_Core4_QM_1ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_BSW_APPLICATION_CORE4_QM_ACCESS),
    /* ownerAppId     = */ BSW_APPLICATION_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 1U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_BSW_TASK_1MS_CORE4_QM_1MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core4_Offest_QM_10ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core4,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = BSW_TASK_10MS_CORE4_OFFEST_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core4_Offest_QM_10ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_BSW_APPLICATION_CORE4_QM_ACCESS),
    /* ownerAppId     = */ BSW_APPLICATION_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* alarmTime      = */ 35U,
    /* autoCycle      = */ 10U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_BSW_TASK_10MS_CORE4_OFFEST_QM_10MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_5ms_Core4_Offest_QM_5ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core4,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = BSW_TASK_5MS_CORE4_OFFEST_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_5ms_Core4_Offest_QM_5ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_BSW_APPLICATION_CORE4_QM_ACCESS),
    /* ownerAppId     = */ BSW_APPLICATION_CORE4_QM,
    /* coreId         = */ OS_CORE_ID_4,
    /* alarmTime      = */ 35U,
    /* autoCycle      = */ 5U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_BSW_TASK_5MS_CORE4_OFFEST_QM_5MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_1ms_Core5_QM_1ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core5,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_1MS_CORE5_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_1ms_Core5_QM_1ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE5_QM,
    /* coreId         = */ OS_CORE_ID_5,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 1U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_1MS_CORE5_QM_1MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_5ms_Core5_QM_5ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core5,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_5MS_CORE5_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_5ms_Core5_QM_5ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE5_QM,
    /* coreId         = */ OS_CORE_ID_5,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 5U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_5MS_CORE5_QM_5MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_10ms_Core5_QM_10ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core5,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_10MS_CORE5_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_10ms_Core5_QM_10ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE5_QM,
    /* coreId         = */ OS_CORE_ID_5,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 10U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_10MS_CORE5_QM_10MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_20ms_Core5_QM_20ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core5,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_20MS_CORE5_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_20ms_Core5_QM_20ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE5_QM,
    /* coreId         = */ OS_CORE_ID_5,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 20U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_20MS_CORE5_QM_20MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_50ms_Core5_QM_50ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core5,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_50MS_CORE5_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_50ms_Core5_QM_50ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE5_QM,
    /* coreId         = */ OS_CORE_ID_5,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 50U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_50MS_CORE5_QM_50MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_100ms_Core5_QM_100ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core5,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_100MS_CORE5_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_100ms_Core5_QM_100ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE5_QM,
    /* coreId         = */ OS_CORE_ID_5,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 100U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_100MS_CORE5_QM_100MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_200ms_Core5_QM_200ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core5,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_200MS_CORE5_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_200ms_Core5_QM_200ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE5_QM,
    /* coreId         = */ OS_CORE_ID_5,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 200U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_200MS_CORE5_QM_200MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_500ms_Core5_QM_500ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core5,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_500MS_CORE5_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_500ms_Core5_QM_500ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE5_QM,
    /* coreId         = */ OS_CORE_ID_5,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 500U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_500MS_CORE5_QM_500MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_App1_Task_1000ms_Core5_QM_1000ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core5,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = APP1_TASK_1000MS_CORE5_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_App1_Task_1000ms_Core5_QM_1000ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* ownerAppId     = */ APP1_APPLICATION_CORE5_QM,
    /* coreId         = */ OS_CORE_ID_5,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 1000U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_APP1_TASK_1000MS_CORE5_QM_1000MS
};
const Os_AlarmCfgType OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core5_QM_10ms =
{
    /* alarmMode      = */ OS_ALARM_REL,
    /* appMode        = */ OS_APPMODE_ANY,
    /* counter        = */ (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core5,
    /* cntExpKind     = */ OS_CNTEXP_ALRM_AT,
    {
        /* workParam  = */ .taskId = BSW_TASK_10MS_CORE5_QM
    },
    /* alarmDyn       = */ &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core5_QM_10ms_Dyn,
    /* accessingApps  = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |
                          OS_BSW_APPLICATION_CORE5_QM_ACCESS),
    /* ownerAppId     = */ BSW_APPLICATION_CORE5_QM,
    /* coreId         = */ OS_CORE_ID_5,
    /* alarmTime      = */ 32U,
    /* autoCycle      = */ 10U,
    /* alarm_CallBack = */ NULL_PTR,
    /* alarmId        = */ RTE_AL_TE_BSW_TASK_10MS_CORE5_QM_10MS
};
/* Alarm config parameters end. */

/* Spinlock config parameters start. */
const Os_SpinlockCfgType OsCfg_Spinlock_OsSpinlock0 =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_NOTHING,
    /* spinId        = */ OSSPINLOCK0,
    /* accessingApps = */ (OS_APP1_APPLICATION_CORE0_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS |
                          OS_APP1_APPLICATION_CORE2_QM_ACCESS |OS_APP1_APPLICATION_CORE3_QM_ACCESS |
                          OS_APP1_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_OsSpinlock0_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_OsSpinlock1 =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_NOTHING,
    /* spinId        = */ OSSPINLOCK1,
    /* accessingApps = */ (OS_APP1_APPLICATION_CORE0_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS |
                          OS_APP1_APPLICATION_CORE2_QM_ACCESS |OS_APP1_APPLICATION_CORE3_QM_ACCESS |
                          OS_APP1_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE5_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_OsSpinlock1_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_MCU_UDS_INTERFACE_DATASERVICES_DSPDATA_0X0400_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE3_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_WDGMSPINLOCK =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_CAT2_INTERRUPTS,
    /* spinId        = */ WDGMSPINLOCK,
    /* accessingApps = */ (OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS |OS_APP1_APPLICATION_CORE0_QM_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS |OS_APP1_APPLICATION_CORE3_QM_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS |OS_APP1_APPLICATION_CORE4_QM_ACCESS |
                          OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS |OS_APP1_APPLICATION_CORE5_QM_ACCESS |
                          OS_BSW_APPLICATION_CORE0_QM_ACCESS |OS_BSW_APPLICATION_CORE1_QM_ACCESS |
                          OS_BSW_APPLICATION_CORE2_QM_ACCESS |OS_BSW_APPLICATION_CORE3_QM_ACCESS |
                          OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_BSW_APPLICATION_CORE5_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_WDGMSPINLOCK_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_AC_ACCM_ACTPOWER_0X0328_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_BMSH_CCM_THERMALMANAGEREQ_0X0329_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_BMSH_SELFCHECKFAULT_0X032B_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_CSM_V2XDCHASWTINVALID_0X0324_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_DCDC_SELFCHKSTS_0X032C_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_EHB_EPBSTATUS_0X0312_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_IPU_SELFCHKSTS_0X032A_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PEPS_POWERMODE_0X0319_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_ACCMENABLE_0X031D_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_BATTERYVOL_0X0331_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_BRAKE1SWITCH_0X0311_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_BRAKE2SWITCH_0X0333_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_CPSREN_0X0313_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_COOLINGFANPWMSPD_0X031C_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_DCDCCUTOFFLV_0X032E_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_DCDCACTVDREQ_0X032D_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_DRIVEMODEIND_0X0317_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_EDCPPWMCTRL_0X031A_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_ENGRECMODE_FB_0X0325_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_FUNLOCKVEHACTIVE_0X0318_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_HBCPPWMCTRL_0X031B_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_HVIL1STS_0X0322_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_HVIL2STS_0X0323_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_IPKTOTALODOMETER_0X0334_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_IGNONSTS_0X0332_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_ISGMODREQ_0X032F_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_ISGTQREQ_0X0314_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_MODEGEARDISPLAYSTS_0X0316_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_PTC2ENABLE_0X031F_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_PTC3ENABLE_0X0320_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_PTCENABLE_0X031E_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_PTRESIDUEPWRIND_0X0315_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_REAL_PEDALPOSITION_0X0310_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_SELFCHECKSTS_0X0321_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_PMS_VEHICLESPEED_0X0327_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_VCU_BMSH_STSMODEREQ_0X0330_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0501_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0502_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0503_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0504_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0505_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0507_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X050A_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0525_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0526_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0527_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0528_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0529_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X052B_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X052D_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X052E_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0530_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0531_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0532_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0533_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0534_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0535_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0536_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0537_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0538_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0539_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X053B_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X053C_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X053D_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X053E_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0542_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0543_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0544_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0545_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0547_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0552_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X055A_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X055C_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X055D_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0585_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0586_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0587_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0588_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0589_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058A_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058B_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058C_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058D_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058E_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058F_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0590_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0591_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0592_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0593_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0594_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0595_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0596_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0597_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0598_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0599_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059A_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059B_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059C_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059D_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059E_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059F_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A1_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A2_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A3_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A4_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A5_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A6_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A7_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A8_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A9_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AA_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AB_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AC_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AD_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AE_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AF_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B0_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B1_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B2_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B3_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B4_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B5_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B6_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B7_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B8_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B9_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BA_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BB_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BC_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BD_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BE_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BF_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C0_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C1_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C2_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C3_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C4_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C5_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C6_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C7_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C8_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C9_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CA_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CB_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CC_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CD_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CE_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CF_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D0_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D1_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D2_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D3_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D4_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XCF00_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XCF05_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XCF06_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XCF07_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDD00_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF00_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF01_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF02_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF03_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF04_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF06_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF09_0_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_VCU_ODOMETERBACKUP_0X0326_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_DTC_0x0402_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_MCU_DID_IPU_DTC_0X0402_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE3_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_DTC_0x0402_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_MCU_DID_IPU_DISCHGSTATE_0X04CF_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE3_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_MCU_DID_IPU_HVBUSCUR_0X0409_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE3_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_MCU_DID_IPU_HVBUSVOLT_500_0X0408_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE3_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_MCU_DID_IPU_ISGMOTT_0X040B_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE3_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_MCU_DID_IPU_ISGSPDACTSGN_0X0403_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE3_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_MCU_DID_IPU_ISGTQACTISGTQACT_0X0404_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE3_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_MCU_DID_IPU_MOTORTEMP_0X040D_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE3_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_MCU_DID_IPU_TQAVLISGMAX_0X0406_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE3_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_MCU_DID_IPU_TQAVLISGMIN_0X0407_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE3_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_MCU_DID_PMS_DRIVERDEMANDTORQUE_0X0405_CS_READDATA,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE3_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x1002_Operation =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X1002_OPERATION,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x1002_Operation_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x1003_Operation =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X1003_OPERATION,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x1003_Operation_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x11_Operation =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X11_OPERATION,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x11_Operation_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x14_Operation =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X14_OPERATION,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x14_Operation_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x22_Operation =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X22_OPERATION,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x22_Operation_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x27_Operation =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X27_OPERATION,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x27_Operation_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x28_Operation =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X28_OPERATION,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x28_Operation_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x2E_Operation =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X2E_OPERATION,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x2E_Operation_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x31_Operation =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X31_OPERATION,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x31_Operation_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x85_Operation =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X85_OPERATION,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x85_Operation_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMS_BattPackMatchFault1_PMS_BMS_BattPackMatchFault1_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_BMS_BATTPACKMATCHFAULT1_PMS_BMS_BATTPACKMATCHFAULT1_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMS_BattPackMatchFault1_PMS_BMS_BattPackMatchFault1_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_BattPackNum_PMS_BMSH_BattPackNum_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_BMSH_BATTPACKNUM_PMS_BMSH_BATTPACKNUM_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_BattPackNum_PMS_BMSH_BattPackNum_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_BattSysNum_PMS_BMSH_BattSysNum_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_BMSH_BATTSYSNUM_PMS_BMSH_BATTSYSNUM_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_BattSysNum_PMS_BMSH_BattSysNum_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatIsoAlarm3_PMS_BMSH_TBOX_BatIsoAlarm3_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATISOALARM3_PMS_BMSH_TBOX_BATISOALARM3_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatIsoAlarm3_PMS_BMSH_TBOX_BatIsoAlarm3_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatLowSOC3_PMS_BMSH_TBOX_BatLowSOC3_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATLOWSOC3_PMS_BMSH_TBOX_BATLOWSOC3_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatLowSOC3_PMS_BMSH_TBOX_BatLowSOC3_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatOverCharge3_PMS_BMSH_TBOX_BatOverCharge3_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATOVERCHARGE3_PMS_BMSH_TBOX_BATOVERCHARGE3_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatOverCharge3_PMS_BMSH_TBOX_BatOverCharge3_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatOverSOC3_PMS_BMSH_TBOX_BatOverSOC3_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATOVERSOC3_PMS_BMSH_TBOX_BATOVERSOC3_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatOverSOC3_PMS_BMSH_TBOX_BatOverSOC3_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatOverTemp3_PMS_BMSH_TBOX_BatOverTemp3_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATOVERTEMP3_PMS_BMSH_TBOX_BATOVERTEMP3_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatOverTemp3_PMS_BMSH_TBOX_BatOverTemp3_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatOverVoltage3_PMS_BMSH_TBOX_BatOverVoltage3_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATOVERVOLTAGE3_PMS_BMSH_TBOX_BATOVERVOLTAGE3_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatOverVoltage3_PMS_BMSH_TBOX_BatOverVoltage3_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatTempUniformity3_PMS_BMSH_TBOX_BatTempUniformity3_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATTEMPUNIFORMITY3_PMS_BMSH_TBOX_BATTEMPUNIFORMITY3_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatTempUniformity3_PMS_BMSH_TBOX_BatTempUniformity3_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatUnderVoltage3_PMS_BMSH_TBOX_BatUnderVoltage3_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATUNDERVOLTAGE3_PMS_BMSH_TBOX_BATUNDERVOLTAGE3_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatUnderVoltage3_PMS_BMSH_TBOX_BatUnderVoltage3_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatUniformity3_PMS_BMSH_TBOX_BatUniformity3_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_BATUNIFORMITY3_PMS_BMSH_TBOX_BATUNIFORMITY3_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatUniformity3_PMS_BMSH_TBOX_BatUniformity3_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_CellOverVoltage3_PMS_BMSH_TBOX_CellOverVoltage3_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_CELLOVERVOLTAGE3_PMS_BMSH_TBOX_CELLOVERVOLTAGE3_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_CellOverVoltage3_PMS_BMSH_TBOX_CellOverVoltage3_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_CellUnderVoltage3_PMS_BMSH_TBOX_CellUnderVoltage3_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_CELLUNDERVOLTAGE3_PMS_BMSH_TBOX_CELLUNDERVOLTAGE3_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_CellUnderVoltage3_PMS_BMSH_TBOX_CellUnderVoltage3_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_FireAlarm2_PMS_BMSH_TBOX_FireAlarm2_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_FIREALARM2_PMS_BMSH_TBOX_FIREALARM2_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_FireAlarm2_PMS_BMSH_TBOX_FireAlarm2_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_SOCHop3_PMS_BMSH_TBOX_SOCHop3_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_BMSH_TBOX_SOCHOP3_PMS_BMSH_TBOX_SOCHOP3_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_SOCHop3_PMS_BMSH_TBOX_SOCHop3_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_IPU_MCUTempHighAlarm2_PMS_IPU_MCUTempHighAlarm2_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_IPU_MCUTEMPHIGHALARM2_PMS_IPU_MCUTEMPHIGHALARM2_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_IPU_MCUTempHighAlarm2_PMS_IPU_MCUTempHighAlarm2_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_IPU_MotorOverCurrFlt1_PMS_IPU_MotorOverCurrFlt1_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_IPU_MOTOROVERCURRFLT1_PMS_IPU_MOTOROVERCURRFLT1_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_IPU_MotorOverCurrFlt1_PMS_IPU_MotorOverCurrFlt1_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_IPU_MotorOverSpdFlt1_PMS_IPU_MotorOverSpdFlt1_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_IPU_MOTOROVERSPDFLT1_PMS_IPU_MOTOROVERSPDFLT1_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_IPU_MotorOverSpdFlt1_PMS_IPU_MotorOverSpdFlt1_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_IPU_MotorTempHighFault2_PMS_IPU_MotorTempHighFault2_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_IPU_MOTORTEMPHIGHFAULT2_PMS_IPU_MOTORTEMPHIGHFAULT2_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_IPU_MotorTempHighFault2_PMS_IPU_MotorTempHighFault2_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_ODP_TBOX_DcDcStsAlm1_PMS_ODP_TBOX_DcDcStsAlm1_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_ODP_TBOX_DCDCSTSALM1_PMS_ODP_TBOX_DCDCSTSALM1_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_ODP_TBOX_DcDcStsAlm1_PMS_ODP_TBOX_DcDcStsAlm1_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_ODP_TBOX_TDcDcAlm1_PMS_ODP_TBOX_TDcDcAlm1_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_ODP_TBOX_TDCDCALM1_PMS_ODP_TBOX_TDCDCALM1_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_ODP_TBOX_TDcDcAlm1_PMS_ODP_TBOX_TDcDcAlm1_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_PMS_32960FltNum_PMS_PMS_32960FltNum_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_PMS_32960FLTNUM_PMS_PMS_32960FLTNUM_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_PMS_32960FltNum_PMS_PMS_32960FltNum_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_PMS_OTAInstrucStsReminder_PMS_OTAInstrucStsReminder =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_PMS_OTAINSTRUCSTSREMINDER_PMS_OTAINSTRUCSTSREMINDER,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_PMS_OTAInstrucStsReminder_PMS_OTAInstrucStsReminder_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_PMS_OTAInstructRxnSts_PMS_OTAInstructRxnSts =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_PMS_OTAINSTRUCTRXNSTS_PMS_OTAINSTRUCTRXNSTS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_PMS_OTAInstructRxnSts_PMS_OTAInstructRxnSts_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_PMS_TBOX_BrkSysErr1_PMS_PMS_TBOX_BrkSysErr1_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_PMS_TBOX_BRKSYSERR1_PMS_PMS_TBOX_BRKSYSERR1_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_PMS_TBOX_BrkSysErr1_PMS_PMS_TBOX_BrkSysErr1_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_PMS_TBOX_HVILSts1_PMS_PMS_TBOX_HVILSts1_PMS =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_COM_SWC_VCOP_PMS_TBOX_HVILSTS1_PMS_PMS_TBOX_HVILSTS1_PMS,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_PMS_TBOX_HVILSts1_PMS_PMS_TBOX_HVILSts1_PMS_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X03E2_START,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X03E2_STOP,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x4000_Start =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X4000_START,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x400F_Start =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X400F_START,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x400F_Start_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X4F02_START,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X4F03_START,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Dyn,
    /* order         = */ 0U
};
const Os_SpinlockCfgType OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start =
{
    /* spinMethod    = */ OS_SPINLOCK_LOCK_ALL_INTERRUPTS,
    /* spinId        = */ SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X4F04_START,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE2_QM_ACCESS),
    /* spinDyn       = */ &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Dyn,
    /* order         = */ 0U
};
/* Spinlock config parameters end. */

/* Resource config parameters start. */
const Os_ResourceCfgType OsCfg_Resource_Core0_Task_OsResource0 =
{
    /* rsrcType      = */ OS_RESOURCE_TASK,
    {
        /* rsrcParam = */ .taskPrio = 0U
    },
    /* rsrcId        = */ CORE0_TASK_OSRESOURCE0,
    /* coreId        = */ OS_CORE_ID_0,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE0_QM_ACCESS |OS_APP1_APPLICATION_CORE0_QM_ACCESS),
    /* resouceDyn    = */ &Os_Resource_Core0_Task_OsResource0_Dyn
};
const Os_ResourceCfgType OsCfg_Resource_Core0_Isr_OsResource0 =
{
    /* rsrcType      = */ OS_RESOURCE_TASK,
    {
        /* rsrcParam = */ .taskPrio = 0U
    },
    /* rsrcId        = */ CORE0_ISR_OSRESOURCE0,
    /* coreId        = */ OS_CORE_ID_0,
    /* accessingApps = */ (OS_APP1_APPLICATION_CORE0_QM_ACCESS |OS_BSW_APPLICATION_CORE0_QM_ACCESS),
    /* resouceDyn    = */ &Os_Resource_Core0_Isr_OsResource0_Dyn
};
const Os_ResourceCfgType OsCfg_Resource_Core1_Task_OsResource0 =
{
    /* rsrcType      = */ OS_RESOURCE_TASK,
    {
        /* rsrcParam = */ .taskPrio = 0U
    },
    /* rsrcId        = */ CORE1_TASK_OSRESOURCE0,
    /* coreId        = */ OS_CORE_ID_1,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE1_QM_ACCESS |OS_APP1_APPLICATION_CORE1_QM_ACCESS),
    /* resouceDyn    = */ &Os_Resource_Core1_Task_OsResource0_Dyn
};
const Os_ResourceCfgType OsCfg_Resource_Core1_Isr_OsResource0 =
{
    /* rsrcType      = */ OS_RESOURCE_TASK,
    {
        /* rsrcParam = */ .taskPrio = 0U
    },
    /* rsrcId        = */ CORE1_ISR_OSRESOURCE0,
    /* coreId        = */ OS_CORE_ID_1,
    /* accessingApps = */ (OS_APP1_APPLICATION_CORE1_QM_ACCESS |OS_BSW_APPLICATION_CORE1_QM_ACCESS),
    /* resouceDyn    = */ &Os_Resource_Core1_Isr_OsResource0_Dyn
};
const Os_ResourceCfgType OsCfg_Resource_Core2_Task_OsResource0 =
{
    /* rsrcType      = */ OS_RESOURCE_TASK,
    {
        /* rsrcParam = */ .taskPrio = 0U
    },
    /* rsrcId        = */ CORE2_TASK_OSRESOURCE0,
    /* coreId        = */ OS_CORE_ID_2,
    /* accessingApps = */ (OS_APP1_APPLICATION_CORE2_QM_ACCESS |OS_BSW_APPLICATION_CORE2_QM_ACCESS),
    /* resouceDyn    = */ &Os_Resource_Core2_Task_OsResource0_Dyn
};
const Os_ResourceCfgType OsCfg_Resource_Core2_Isr_OsResource0 =
{
    /* rsrcType      = */ OS_RESOURCE_TASK,
    {
        /* rsrcParam = */ .taskPrio = 0U
    },
    /* rsrcId        = */ CORE2_ISR_OSRESOURCE0,
    /* coreId        = */ OS_CORE_ID_2,
    /* accessingApps = */ (OS_APP1_APPLICATION_CORE2_QM_ACCESS |OS_BSW_APPLICATION_CORE2_QM_ACCESS),
    /* resouceDyn    = */ &Os_Resource_Core2_Isr_OsResource0_Dyn
};
const Os_ResourceCfgType OsCfg_Resource_Core3_Task_OsResource0 =
{
    /* rsrcType      = */ OS_RESOURCE_TASK,
    {
        /* rsrcParam = */ .taskPrio = 3U
    },
    /* rsrcId        = */ CORE3_TASK_OSRESOURCE0,
    /* coreId        = */ OS_CORE_ID_3,
    /* accessingApps = */ (OS_APP1_APPLICATION_CORE3_QM_ACCESS |OS_BSW_APPLICATION_CORE3_QM_ACCESS),
    /* resouceDyn    = */ &Os_Resource_Core3_Task_OsResource0_Dyn
};
const Os_ResourceCfgType OsCfg_Resource_Core3_Isr_OsResource0 =
{
    /* rsrcType      = */ OS_RESOURCE_TASK,
    {
        /* rsrcParam = */ .taskPrio = 0U
    },
    /* rsrcId        = */ CORE3_ISR_OSRESOURCE0,
    /* coreId        = */ OS_CORE_ID_3,
    /* accessingApps = */ (OS_APP1_APPLICATION_CORE3_QM_ACCESS |OS_BSW_APPLICATION_CORE3_QM_ACCESS),
    /* resouceDyn    = */ &Os_Resource_Core3_Isr_OsResource0_Dyn
};
const Os_ResourceCfgType OsCfg_Resource_Core4_Task_OsResource0 =
{
    /* rsrcType      = */ OS_RESOURCE_TASK,
    {
        /* rsrcParam = */ .taskPrio = 0U
    },
    /* rsrcId        = */ CORE4_TASK_OSRESOURCE0,
    /* coreId        = */ OS_CORE_ID_4,
    /* accessingApps = */ (OS_APP1_APPLICATION_CORE4_QM_ACCESS |OS_BSW_APPLICATION_CORE4_QM_ACCESS),
    /* resouceDyn    = */ &Os_Resource_Core4_Task_OsResource0_Dyn
};
const Os_ResourceCfgType OsCfg_Resource_Core4_Isr_OsResource0 =
{
    /* rsrcType      = */ OS_RESOURCE_TASK,
    {
        /* rsrcParam = */ .taskPrio = 0U
    },
    /* rsrcId        = */ CORE4_ISR_OSRESOURCE0,
    /* coreId        = */ OS_CORE_ID_4,
    /* accessingApps = */ (OS_BSW_APPLICATION_CORE4_QM_ACCESS |OS_APP1_APPLICATION_CORE4_QM_ACCESS),
    /* resouceDyn    = */ &Os_Resource_Core4_Isr_OsResource0_Dyn
};
const Os_ResourceCfgType OsCfg_Resource_Core5_Task_OsResource0 =
{
    /* rsrcType      = */ OS_RESOURCE_TASK,
    {
        /* rsrcParam = */ .taskPrio = 0U
    },
    /* rsrcId        = */ CORE5_TASK_OSRESOURCE0,
    /* coreId        = */ OS_CORE_ID_5,
    /* accessingApps = */ (OS_APP1_APPLICATION_CORE5_QM_ACCESS |OS_BSW_APPLICATION_CORE5_QM_ACCESS),
    /* resouceDyn    = */ &Os_Resource_Core5_Task_OsResource0_Dyn
};
const Os_ResourceCfgType OsCfg_Resource_Core5_Isr_OsResource0 =
{
    /* rsrcType      = */ OS_RESOURCE_TASK,
    {
        /* rsrcParam = */ .taskPrio = 0U
    },
    /* rsrcId        = */ CORE5_ISR_OSRESOURCE0,
    /* coreId        = */ OS_CORE_ID_5,
    /* accessingApps = */ (OS_APP1_APPLICATION_CORE5_QM_ACCESS |OS_BSW_APPLICATION_CORE5_QM_ACCESS),
    /* resouceDyn    = */ &Os_Resource_Core5_Isr_OsResource0_Dyn
};
/* Resource config parameters end. */

/* Scheduler config parameters start. */
const Os_SchedulerCfgType OsCfg_Scheduler_OsCore0 =
{
    {
        /* bitMap->bitMapDyn = */ &OsCfg_Scheduler_BitMap_OsCore0_Dyn,
        /* bitMap->l1Data    = */ OsCfg_BitMap_L1Data_OsCore0_Dyn,
        /* bitMap->length    = */ OS_BITMAP_LENGTH(OS_CFG_NUM_TASKQUEUES_OSCORE0),
        /* bitMap->bitNum    = */ OS_BITMAP_NUM(OS_CFG_NUM_TASKQUEUES_OSCORE0)
    },
    /* schdDyn               = */ &OsCfg_Scheduler_OsCore0_Dyn,
    /* taskQueues            = */ OsCfg_Scheduler_OsCore0_TaskQueues,
    /* queuesNumber          = */ OS_CFG_NUM_TASKQUEUES_OSCORE0,
    /* taskQueInit           = */ OsCfg_Scheduler_InitCallback_OsCore0
};

const Os_SchedulerCfgType OsCfg_Scheduler_OsCore1 =
{
    {
        /* bitMap->bitMapDyn = */ &OsCfg_Scheduler_BitMap_OsCore1_Dyn,
        /* bitMap->l1Data    = */ OsCfg_BitMap_L1Data_OsCore1_Dyn,
        /* bitMap->length    = */ OS_BITMAP_LENGTH(OS_CFG_NUM_TASKQUEUES_OSCORE1),
        /* bitMap->bitNum    = */ OS_BITMAP_NUM(OS_CFG_NUM_TASKQUEUES_OSCORE1)
    },
    /* schdDyn               = */ &OsCfg_Scheduler_OsCore1_Dyn,
    /* taskQueues            = */ OsCfg_Scheduler_OsCore1_TaskQueues,
    /* queuesNumber          = */ OS_CFG_NUM_TASKQUEUES_OSCORE1,
    /* taskQueInit           = */ OsCfg_Scheduler_InitCallback_OsCore1
};

const Os_SchedulerCfgType OsCfg_Scheduler_OsCore2 =
{
    {
        /* bitMap->bitMapDyn = */ &OsCfg_Scheduler_BitMap_OsCore2_Dyn,
        /* bitMap->l1Data    = */ OsCfg_BitMap_L1Data_OsCore2_Dyn,
        /* bitMap->length    = */ OS_BITMAP_LENGTH(OS_CFG_NUM_TASKQUEUES_OSCORE2),
        /* bitMap->bitNum    = */ OS_BITMAP_NUM(OS_CFG_NUM_TASKQUEUES_OSCORE2)
    },
    /* schdDyn               = */ &OsCfg_Scheduler_OsCore2_Dyn,
    /* taskQueues            = */ OsCfg_Scheduler_OsCore2_TaskQueues,
    /* queuesNumber          = */ OS_CFG_NUM_TASKQUEUES_OSCORE2,
    /* taskQueInit           = */ OsCfg_Scheduler_InitCallback_OsCore2
};

const Os_SchedulerCfgType OsCfg_Scheduler_OsCore3 =
{
    {
        /* bitMap->bitMapDyn = */ &OsCfg_Scheduler_BitMap_OsCore3_Dyn,
        /* bitMap->l1Data    = */ OsCfg_BitMap_L1Data_OsCore3_Dyn,
        /* bitMap->length    = */ OS_BITMAP_LENGTH(OS_CFG_NUM_TASKQUEUES_OSCORE3),
        /* bitMap->bitNum    = */ OS_BITMAP_NUM(OS_CFG_NUM_TASKQUEUES_OSCORE3)
    },
    /* schdDyn               = */ &OsCfg_Scheduler_OsCore3_Dyn,
    /* taskQueues            = */ OsCfg_Scheduler_OsCore3_TaskQueues,
    /* queuesNumber          = */ OS_CFG_NUM_TASKQUEUES_OSCORE3,
    /* taskQueInit           = */ OsCfg_Scheduler_InitCallback_OsCore3
};

const Os_SchedulerCfgType OsCfg_Scheduler_OsCore4 =
{
    {
        /* bitMap->bitMapDyn = */ &OsCfg_Scheduler_BitMap_OsCore4_Dyn,
        /* bitMap->l1Data    = */ OsCfg_BitMap_L1Data_OsCore4_Dyn,
        /* bitMap->length    = */ OS_BITMAP_LENGTH(OS_CFG_NUM_TASKQUEUES_OSCORE4),
        /* bitMap->bitNum    = */ OS_BITMAP_NUM(OS_CFG_NUM_TASKQUEUES_OSCORE4)
    },
    /* schdDyn               = */ &OsCfg_Scheduler_OsCore4_Dyn,
    /* taskQueues            = */ OsCfg_Scheduler_OsCore4_TaskQueues,
    /* queuesNumber          = */ OS_CFG_NUM_TASKQUEUES_OSCORE4,
    /* taskQueInit           = */ OsCfg_Scheduler_InitCallback_OsCore4
};

const Os_SchedulerCfgType OsCfg_Scheduler_OsCore5 =
{
    {
        /* bitMap->bitMapDyn = */ &OsCfg_Scheduler_BitMap_OsCore5_Dyn,
        /* bitMap->l1Data    = */ OsCfg_BitMap_L1Data_OsCore5_Dyn,
        /* bitMap->length    = */ OS_BITMAP_LENGTH(OS_CFG_NUM_TASKQUEUES_OSCORE5),
        /* bitMap->bitNum    = */ OS_BITMAP_NUM(OS_CFG_NUM_TASKQUEUES_OSCORE5)
    },
    /* schdDyn               = */ &OsCfg_Scheduler_OsCore5_Dyn,
    /* taskQueues            = */ OsCfg_Scheduler_OsCore5_TaskQueues,
    /* queuesNumber          = */ OS_CFG_NUM_TASKQUEUES_OSCORE5,
    /* taskQueInit           = */ OsCfg_Scheduler_InitCallback_OsCore5
};

/* Scheduler config parameters end. */

/* Core config parameters start. */
const Os_CoreCfgType OsCfg_Core_OsCore0 =
{
    /* corePhyId          = */ 0U,
    /* coreIfAutoStart    = */ TRUE,
    /* coreIfAutoSarOs    = */ TRUE,
    /* coreIfMaster       = */ TRUE,
    /* coreCoreLogicId    = */ OS_CORE_ID_0,
    /* coreStartAddr      = */ 0U,
    /* idleTask           = */ &OsCfg_Task_Idle_Task_Core0,
    /* initTask           = */ &OsCfg_Task_Default_Init_Task_Core0,
    /* intStateCfg        = */ &OsCfg_IntState_OsCore0_Dyn,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpBaseCfg          = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* memoryProtection   = */ NULL_PTR,
#endif
    /* scheduler          = */ &OsCfg_Scheduler_OsCore0,
    /* contextCfg         = */ &OsCfg_Arch_Context_Kernal_OsCore0,
    /* systemApp          = */ &OsCfg_Appl_SystemApplication_OsCore_Core0,
    /* appRefs            = */ &Os_AppCfgData[SYSTEMAPPLICATION_OSCORE_CORE0],
    /* appCnt             = */ 3U,
    /* taskRefs           = */ &Os_TaskCfgData[DEFAULT_INIT_TASK_CORE0],
    /* taskCnt            = */ 11U,
    /* isrRefs            = */ &Os_IsrCfgData[COUNTERISR_SYSTEMTIMER_CORE0],
    /* isrCnt             = */ 3U,
    /* isrCat1Refs        = */ &Os_Cat1IsrCfgData_OsCore0[0],
    /* isrCat1Cnt         = */ 0U,
    /* counterRefs        = */ &Os_CounterCfgData[SYSTEMTIMER_CORE0],
    /* counterCnt         = */ 2U,
    /* alarmRefs          = */ &Os_AlarmCfgData[RTE_AL_TE_APP1_TASK_1MS_CORE0_QM_1MS],
    /* alarmCnt           = */ 8U,
#if ( OS_CFG_RESOURCE_ENABLE == STD_ON )
    /* resourceRefs       = */ &Os_ResourceCfgData[CORE0_TASK_OSRESOURCE0],
    /* resourceCnt        = */ 2U,
#endif
#if ( OS_CFG_SCHDTB_ENABLE == STD_ON )
    /* schTbRefs          = */ NULL_PTR,
    /* schdTbCount        = */ 0U,
#endif
#if ( OS_CFG_IOC_ENABLE== STD_ON )
    /* iocRefs            = */ NULL_PTR,
    /* iocCnt             = */ 0U,
#endif
    /* protectionHook     = */ NULL_PTR,
    /* controlIdleHook    = */ NULL_PTR,
    /* coreDyn            = */ &OsCfg_Core_OsCore0_Dyn,
    /* multiCommIsrSource = */ &OsCfg_Arch_Source_MultiCommIsr_Core0
};
const Os_CoreCfgType OsCfg_Core_OsCore1 =
{
    /* corePhyId          = */ 1U,
    /* coreIfAutoStart    = */ FALSE,
    /* coreIfAutoSarOs    = */ TRUE,
    /* coreIfMaster       = */ FALSE,
    /* coreCoreLogicId    = */ OS_CORE_ID_1,
    /* coreStartAddr      = */ (uint32)(&_start),
    /* idleTask           = */ &OsCfg_Task_Idle_Task_Core1,
    /* initTask           = */ &OsCfg_Task_Default_Init_Task_Core1,
    /* intStateCfg        = */ &OsCfg_IntState_OsCore1_Dyn,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpBaseCfg          = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* memoryProtection   = */ NULL_PTR,
#endif
    /* scheduler          = */ &OsCfg_Scheduler_OsCore1,
    /* contextCfg         = */ &OsCfg_Arch_Context_Kernal_OsCore1,
    /* systemApp          = */ &OsCfg_Appl_SystemApplication_OsCore_Core1,
    /* appRefs            = */ &Os_AppCfgData[SYSTEMAPPLICATION_OSCORE_CORE1],
    /* appCnt             = */ 3U,
    /* taskRefs           = */ &Os_TaskCfgData[DEFAULT_INIT_TASK_CORE1],
    /* taskCnt            = */ 11U,
    /* isrRefs            = */ &Os_IsrCfgData[COUNTERISR_SYSTEMTIMER_CORE1],
    /* isrCnt             = */ 2U,
    /* isrCat1Refs        = */ &Os_Cat1IsrCfgData_OsCore1[0],
    /* isrCat1Cnt         = */ 0U,
    /* counterRefs        = */ &Os_CounterCfgData[SYSTEMTIMER_CORE1],
    /* counterCnt         = */ 1U,
    /* alarmRefs          = */ &Os_AlarmCfgData[RTE_AL_TE_APP1_TASK_10MS_CORE1_QM_10MS],
    /* alarmCnt           = */ 7U,
#if ( OS_CFG_RESOURCE_ENABLE == STD_ON )
    /* resourceRefs       = */ &Os_ResourceCfgData[CORE1_TASK_OSRESOURCE0],
    /* resourceCnt        = */ 2U,
#endif
#if ( OS_CFG_SCHDTB_ENABLE == STD_ON )
    /* schTbRefs          = */ NULL_PTR,
    /* schdTbCount        = */ 0U,
#endif
#if ( OS_CFG_IOC_ENABLE== STD_ON )
    /* iocRefs            = */ NULL_PTR,
    /* iocCnt             = */ 0U,
#endif
    /* protectionHook     = */ NULL_PTR,
    /* controlIdleHook    = */ NULL_PTR,
    /* coreDyn            = */ &OsCfg_Core_OsCore1_Dyn,
    /* multiCommIsrSource = */ &OsCfg_Arch_Source_MultiCommIsr_Core1
};
const Os_CoreCfgType OsCfg_Core_OsCore2 =
{
    /* corePhyId          = */ 2U,
    /* coreIfAutoStart    = */ FALSE,
    /* coreIfAutoSarOs    = */ TRUE,
    /* coreIfMaster       = */ FALSE,
    /* coreCoreLogicId    = */ OS_CORE_ID_2,
    /* coreStartAddr      = */ (uint32)(&_start),
    /* idleTask           = */ &OsCfg_Task_Idle_Task_Core2,
    /* initTask           = */ &OsCfg_Task_Default_Init_Task_Core2,
    /* intStateCfg        = */ &OsCfg_IntState_OsCore2_Dyn,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpBaseCfg          = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* memoryProtection   = */ NULL_PTR,
#endif
    /* scheduler          = */ &OsCfg_Scheduler_OsCore2,
    /* contextCfg         = */ &OsCfg_Arch_Context_Kernal_OsCore2,
    /* systemApp          = */ &OsCfg_Appl_SystemApplication_OsCore_Core2,
    /* appRefs            = */ &Os_AppCfgData[SYSTEMAPPLICATION_OSCORE_CORE2],
    /* appCnt             = */ 3U,
    /* taskRefs           = */ &Os_TaskCfgData[DEFAULT_INIT_TASK_CORE2],
    /* taskCnt            = */ 14U,
    /* isrRefs            = */ &Os_IsrCfgData[COUNTERISR_SYSTEMTIMER_CORE2],
    /* isrCnt             = */ 2U,
    /* isrCat1Refs        = */ &Os_Cat1IsrCfgData_OsCore2[0],
    /* isrCat1Cnt         = */ 0U,
    /* counterRefs        = */ &Os_CounterCfgData[SYSTEMTIMER_CORE2],
    /* counterCnt         = */ 1U,
    /* alarmRefs          = */ &Os_AlarmCfgData[RTE_AL_TE_APP1_TASK_50MS_CORE2_QM_50MS],
    /* alarmCnt           = */ 8U,
#if ( OS_CFG_RESOURCE_ENABLE == STD_ON )
    /* resourceRefs       = */ &Os_ResourceCfgData[CORE2_TASK_OSRESOURCE0],
    /* resourceCnt        = */ 2U,
#endif
#if ( OS_CFG_SCHDTB_ENABLE == STD_ON )
    /* schTbRefs          = */ NULL_PTR,
    /* schdTbCount        = */ 0U,
#endif
#if ( OS_CFG_IOC_ENABLE== STD_ON )
    /* iocRefs            = */ NULL_PTR,
    /* iocCnt             = */ 0U,
#endif
    /* protectionHook     = */ NULL_PTR,
    /* controlIdleHook    = */ NULL_PTR,
    /* coreDyn            = */ &OsCfg_Core_OsCore2_Dyn,
    /* multiCommIsrSource = */ &OsCfg_Arch_Source_MultiCommIsr_Core2
};
const Os_CoreCfgType OsCfg_Core_OsCore3 =
{
    /* corePhyId          = */ 3U,
    /* coreIfAutoStart    = */ FALSE,
    /* coreIfAutoSarOs    = */ TRUE,
    /* coreIfMaster       = */ FALSE,
    /* coreCoreLogicId    = */ OS_CORE_ID_3,
    /* coreStartAddr      = */ (uint32)(&_start),
    /* idleTask           = */ &OsCfg_Task_Idle_Task_Core3,
    /* initTask           = */ &OsCfg_Task_Default_Init_Task_Core3,
    /* intStateCfg        = */ &OsCfg_IntState_OsCore3_Dyn,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpBaseCfg          = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* memoryProtection   = */ NULL_PTR,
#endif
    /* scheduler          = */ &OsCfg_Scheduler_OsCore3,
    /* contextCfg         = */ &OsCfg_Arch_Context_Kernal_OsCore3,
    /* systemApp          = */ &OsCfg_Appl_SystemApplication_OsCore_Core3,
    /* appRefs            = */ &Os_AppCfgData[SYSTEMAPPLICATION_OSCORE_CORE3],
    /* appCnt             = */ 3U,
    /* taskRefs           = */ &Os_TaskCfgData[DEFAULT_INIT_TASK_CORE3],
    /* taskCnt            = */ 7U,
    /* isrRefs            = */ &Os_IsrCfgData[COUNTERISR_SYSTEMTIMER_CORE3],
    /* isrCnt             = */ 2U,
    /* isrCat1Refs        = */ &Os_Cat1IsrCfgData_OsCore3[0],
    /* isrCat1Cnt         = */ 13U,
    /* counterRefs        = */ &Os_CounterCfgData[SYSTEMTIMER_CORE3],
    /* counterCnt         = */ 1U,
    /* alarmRefs          = */ &Os_AlarmCfgData[RTE_AL_TE_TASK_1MS_CORE3_QM_1MS],
    /* alarmCnt           = */ 3U,
#if ( OS_CFG_RESOURCE_ENABLE == STD_ON )
    /* resourceRefs       = */ &Os_ResourceCfgData[CORE3_TASK_OSRESOURCE0],
    /* resourceCnt        = */ 2U,
#endif
#if ( OS_CFG_SCHDTB_ENABLE == STD_ON )
    /* schTbRefs          = */ NULL_PTR,
    /* schdTbCount        = */ 0U,
#endif
#if ( OS_CFG_IOC_ENABLE== STD_ON )
    /* iocRefs            = */ NULL_PTR,
    /* iocCnt             = */ 0U,
#endif
    /* protectionHook     = */ NULL_PTR,
    /* controlIdleHook    = */ NULL_PTR,
    /* coreDyn            = */ &OsCfg_Core_OsCore3_Dyn,
    /* multiCommIsrSource = */ &OsCfg_Arch_Source_MultiCommIsr_Core3
};
const Os_CoreCfgType OsCfg_Core_OsCore4 =
{
    /* corePhyId          = */ 4U,
    /* coreIfAutoStart    = */ FALSE,
    /* coreIfAutoSarOs    = */ TRUE,
    /* coreIfMaster       = */ FALSE,
    /* coreCoreLogicId    = */ OS_CORE_ID_4,
    /* coreStartAddr      = */ (uint32)(&_start),
    /* idleTask           = */ &OsCfg_Task_Idle_Task_Core4,
    /* initTask           = */ &OsCfg_Task_Default_Init_Task_Core4,
    /* intStateCfg        = */ &OsCfg_IntState_OsCore4_Dyn,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpBaseCfg          = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* memoryProtection   = */ NULL_PTR,
#endif
    /* scheduler          = */ &OsCfg_Scheduler_OsCore4,
    /* contextCfg         = */ &OsCfg_Arch_Context_Kernal_OsCore4,
    /* systemApp          = */ &OsCfg_Appl_SystemApplication_OsCore_Core4,
    /* appRefs            = */ &Os_AppCfgData[SYSTEMAPPLICATION_OSCORE_CORE4],
    /* appCnt             = */ 3U,
    /* taskRefs           = */ &Os_TaskCfgData[DEFAULT_INIT_TASK_CORE4],
    /* taskCnt            = */ 18U,
    /* isrRefs            = */ &Os_IsrCfgData[COUNTERISR_SYSTEMTIMER_CORE4],
    /* isrCnt             = */ 18U,
    /* isrCat1Refs        = */ &Os_Cat1IsrCfgData_OsCore4[0],
    /* isrCat1Cnt         = */ 0U,
    /* counterRefs        = */ &Os_CounterCfgData[SYSTEMTIMER_CORE4],
    /* counterCnt         = */ 1U,
    /* alarmRefs          = */ &Os_AlarmCfgData[RTE_AL_TE_APP1_TASK_1MS_CORE4_QM_1MS],
    /* alarmCnt           = */ 14U,
#if ( OS_CFG_RESOURCE_ENABLE == STD_ON )
    /* resourceRefs       = */ &Os_ResourceCfgData[CORE4_TASK_OSRESOURCE0],
    /* resourceCnt        = */ 2U,
#endif
#if ( OS_CFG_SCHDTB_ENABLE == STD_ON )
    /* schTbRefs          = */ NULL_PTR,
    /* schdTbCount        = */ 0U,
#endif
#if ( OS_CFG_IOC_ENABLE== STD_ON )
    /* iocRefs            = */ NULL_PTR,
    /* iocCnt             = */ 0U,
#endif
    /* protectionHook     = */ NULL_PTR,
    /* controlIdleHook    = */ NULL_PTR,
    /* coreDyn            = */ &OsCfg_Core_OsCore4_Dyn,
    /* multiCommIsrSource = */ NULL_PTR
};
const Os_CoreCfgType OsCfg_Core_OsCore5 =
{
    /* corePhyId          = */ 5U,
    /* coreIfAutoStart    = */ FALSE,
    /* coreIfAutoSarOs    = */ TRUE,
    /* coreIfMaster       = */ FALSE,
    /* coreCoreLogicId    = */ OS_CORE_ID_5,
    /* coreStartAddr      = */ (uint32)(&_start),
    /* idleTask           = */ &OsCfg_Task_Idle_Task_Core5,
    /* initTask           = */ &OsCfg_Task_Default_Init_Task_Core5,
    /* intStateCfg        = */ &OsCfg_IntState_OsCore5_Dyn,
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* tpBaseCfg          = */ NULL_PTR,
#endif
#if ((OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4))
    /* memoryProtection   = */ NULL_PTR,
#endif
    /* scheduler          = */ &OsCfg_Scheduler_OsCore5,
    /* contextCfg         = */ &OsCfg_Arch_Context_Kernal_OsCore5,
    /* systemApp          = */ &OsCfg_Appl_SystemApplication_OsCore_Core5,
    /* appRefs            = */ &Os_AppCfgData[SYSTEMAPPLICATION_OSCORE_CORE5],
    /* appCnt             = */ 3U,
    /* taskRefs           = */ &Os_TaskCfgData[DEFAULT_INIT_TASK_CORE5],
    /* taskCnt            = */ 14U,
    /* isrRefs            = */ &Os_IsrCfgData[COUNTERISR_SYSTEMTIMER_CORE5],
    /* isrCnt             = */ 2U,
    /* isrCat1Refs        = */ &Os_Cat1IsrCfgData_OsCore5[0],
    /* isrCat1Cnt         = */ 1U,
    /* counterRefs        = */ &Os_CounterCfgData[SYSTEMTIMER_CORE5],
    /* counterCnt         = */ 1U,
    /* alarmRefs          = */ &Os_AlarmCfgData[RTE_AL_TE_APP1_TASK_1MS_CORE5_QM_1MS],
    /* alarmCnt           = */ 10U,
#if ( OS_CFG_RESOURCE_ENABLE == STD_ON )
    /* resourceRefs       = */ &Os_ResourceCfgData[CORE5_TASK_OSRESOURCE0],
    /* resourceCnt        = */ 2U,
#endif
#if ( OS_CFG_SCHDTB_ENABLE == STD_ON )
    /* schTbRefs          = */ NULL_PTR,
    /* schdTbCount        = */ 0U,
#endif
#if ( OS_CFG_IOC_ENABLE== STD_ON )
    /* iocRefs            = */ NULL_PTR,
    /* iocCnt             = */ 0U,
#endif
    /* protectionHook     = */ NULL_PTR,
    /* controlIdleHook    = */ NULL_PTR,
    /* coreDyn            = */ &OsCfg_Core_OsCore5_Dyn,
    /* multiCommIsrSource = */ NULL_PTR
};
/* Core config parameters end. */

const Os_CoreCfgType* const Os_CoreCfgData[OS_COREID_COUNT + 1] = 
{
    &OsCfg_Core_OsCore0,
    &OsCfg_Core_OsCore1,
    &OsCfg_Core_OsCore2,
    &OsCfg_Core_OsCore3,
    &OsCfg_Core_OsCore4,
    &OsCfg_Core_OsCore5,
    NULL_PTR
};
const Os_AppCfgType* const Os_AppCfgData[OS_APPID_COUNT + 1] = 
{
    &OsCfg_Appl_SystemApplication_OsCore_Core0,
    &OsCfg_Appl_App1_Application_Core0_QM,
    &OsCfg_Appl_Bsw_Application_Core0_QM,
    &OsCfg_Appl_SystemApplication_OsCore_Core1,
    &OsCfg_Appl_App1_Application_Core1_QM,
    &OsCfg_Appl_Bsw_Application_Core1_QM,
    &OsCfg_Appl_SystemApplication_OsCore_Core2,
    &OsCfg_Appl_App1_Application_Core2_QM,
    &OsCfg_Appl_Bsw_Application_Core2_QM,
    &OsCfg_Appl_SystemApplication_OsCore_Core3,
    &OsCfg_Appl_App1_Application_Core3_QM,
    &OsCfg_Appl_Bsw_Application_Core3_QM,
    &OsCfg_Appl_SystemApplication_OsCore_Core4,
    &OsCfg_Appl_App1_Application_Core4_QM,
    &OsCfg_Appl_Bsw_Application_Core4_QM,
    &OsCfg_Appl_SystemApplication_OsCore_Core5,
    &OsCfg_Appl_App1_Application_Core5_QM,
    &OsCfg_Appl_Bsw_Application_Core5_QM,
    NULL_PTR
};
const Os_TaskCfgType* const Os_TaskCfgData[OS_TASKID_COUNT + 1] = 
{
    &OsCfg_Task_Default_Init_Task_Core0,
    &OsCfg_Task_Idle_Task_Core0,
    &OsCfg_Task_App1_Task_1ms_Core0_QM,
    &OsCfg_Task_App1_Task_5ms_Core0_QM,
    &OsCfg_Task_App1_Task_10ms_Core0_QM,
    &OsCfg_Task_App1_Task_20ms_Core0_QM,
    &OsCfg_Task_App1_Task_50ms_Core0_QM,
    &OsCfg_Task_App1_Task_100ms_Core0_QM,
    &OsCfg_Task_SWC_Init_Task_Core0,
    &OsCfg_Task_Bsw_Task_10ms_Core0_QM,
    &OsCfg_Task_Bsw_Task_5ms_Core0_QM,
    &OsCfg_Task_Default_Init_Task_Core1,
    &OsCfg_Task_Idle_Task_Core1,
    &OsCfg_Task_App1_Task_10ms_Core1_QM,
    &OsCfg_Task_SWC_Init_Task_Core1,
    &OsCfg_Task_App1_Task_1ms_Core1_QM,
    &OsCfg_Task_App1_Task_5ms_Core1_QM,
    &OsCfg_Task_App1_Task_20ms_Core1_QM,
    &OsCfg_Task_App1_Task_50ms_Core1_QM,
    &OsCfg_Task_App1_Task_100ms_Core1_QM,
    &OsCfg_Task_App1_Task_UDS_Core1_QM,
    &OsCfg_Task_Bsw_Task_10ms_Core1_QM,
    &OsCfg_Task_Default_Init_Task_Core2,
    &OsCfg_Task_Idle_Task_Core2,
    &OsCfg_Task_App1_Task_50ms_Core2_QM,
    &OsCfg_Task_App1_Task_100ms_Core2_QM,
    &OsCfg_Task_App1_Task_10ms_Core2_QM,
    &OsCfg_Task_App1_Task_1000ms_Core2_QM,
    &OsCfg_Task_SWC_Init_Task_Core2,
    &OsCfg_Task_App1_Task_1ms_Core2_QM,
    &OsCfg_Task_App1_Task_5ms_Core2_QM,
    &OsCfg_Task_App1_Task_20ms_Core2_QM,
    &OsCfg_Task_App1_Task0_UDS_Core2_QM,
    &OsCfg_Task_App1_Task1_UDS_Core2_QM,
    &OsCfg_Task_App1_Task2_UDS_Core2_QM,
    &OsCfg_Task_Bsw_Task_10ms_Core2_QM,
    &OsCfg_Task_Default_Init_Task_Core3,
    &OsCfg_Task_Idle_Task_Core3,
    &OsCfg_Task_SWC_Init_Task_Core3,
    &OsCfg_Task_App1_Task_UDS_Core3_QM,
    &OsCfg_Task_Task_1ms_Core3_QM,
    &OsCfg_Task_Task_100us_Core3_QM,
    &OsCfg_Task_Task_5ms_Core3_QM,
    &OsCfg_Task_Default_Init_Task_Core4,
    &OsCfg_Task_Idle_Task_Core4,
    &OsCfg_Task_App1_Task_1ms_Core4_QM,
    &OsCfg_Task_App1_Task_5ms_Core4_QM,
    &OsCfg_Task_App1_Task_10ms_Core4_QM,
    &OsCfg_Task_App1_Task_20ms_Core4_QM,
    &OsCfg_Task_App1_Task_50ms_Core4_QM,
    &OsCfg_Task_App1_Task_100ms_Core4_QM,
    &OsCfg_Task_SWC_Init_Task_Core4,
    &OsCfg_Task_App1_Task_UDS_Core4_QM,
    &OsCfg_Task_Bsw_Task_100ms_Core4_QM,
    &OsCfg_Task_Bsw_Task_50ms_Core4_QM,
    &OsCfg_Task_Bsw_Task_20ms_Core4_QM,
    &OsCfg_Task_Bsw_Task_10ms_Core4_QM,
    &OsCfg_Task_Bsw_Task_5ms_Core4_QM,
    &OsCfg_Task_Bsw_Task_1ms_Core4_QM,
    &OsCfg_Task_Bsw_Task_5ms_Core4_Offest_QM,
    &OsCfg_Task_Bsw_Task_10ms_Core4_Offest_QM,
    &OsCfg_Task_Default_Init_Task_Core5,
    &OsCfg_Task_Idle_Task_Core5,
    &OsCfg_Task_App1_Task_1ms_Core5_QM,
    &OsCfg_Task_App1_Task_5ms_Core5_QM,
    &OsCfg_Task_App1_Task_10ms_Core5_QM,
    &OsCfg_Task_App1_Task_20ms_Core5_QM,
    &OsCfg_Task_App1_Task_50ms_Core5_QM,
    &OsCfg_Task_App1_Task_100ms_Core5_QM,
    &OsCfg_Task_SWC_Init_Task_Core5,
    &OsCfg_Task_App1_Task_UDS_Core5_QM,
    &OsCfg_Task_App1_Task_200ms_Core5_QM,
    &OsCfg_Task_App1_Task_500ms_Core5_QM,
    &OsCfg_Task_App1_Task_1000ms_Core5_QM,
    &OsCfg_Task_Bsw_Task_10ms_Core5_QM,
    NULL_PTR
};
const Os_IsrCfgType* const Os_IsrCfgData[OS_ISRID_COUNT + 1] = 
{
    &OsCfg_Isr_CounterIsr_SystemTimer_Core0,
    &OsCfg_Isr_MultiCommIsr_Core0,
    &OsCfg_Isr_Os_ISR_37_STM0_CH1,
    &OsCfg_Isr_CounterIsr_SystemTimer_Core1,
    &OsCfg_Isr_MultiCommIsr_Core1,
    &OsCfg_Isr_CounterIsr_SystemTimer_Core2,
    &OsCfg_Isr_MultiCommIsr_Core2,
    &OsCfg_Isr_CounterIsr_SystemTimer_Core3,
    &OsCfg_Isr_MultiCommIsr_Core3,
    &OsCfg_Isr_CounterIsr_SystemTimer_Core4,
    &OsCfg_Isr_MultiCommIsr_Core4,
    &OsCfg_Isr_Os_ISR_450_MCAN11_CH1,
    &OsCfg_Isr_Os_ISR_449_MCAN11_CH0,
    &OsCfg_Isr_Os_ISR_699_MCAN6_CH1,
    &OsCfg_Isr_Os_ISR_698_MCAN6_CH0,
    &OsCfg_Isr_Os_ISR_689_MCAN1_CH1,
    &OsCfg_Isr_Os_ISR_688_MCAN1_CH0,
    &OsCfg_Isr_Os_ISR_446_MCAN9_CH1,
    &OsCfg_Isr_Os_ISR_445_MCAN9_CH0,
    &OsCfg_Isr_Os_ISR_693_MCAN3_CH1,
    &OsCfg_Isr_Os_ISR_692_MCAN3_CH0,
    &OsCfg_Isr_Os_ISR_691_MCAN2_CH1,
    &OsCfg_Isr_Os_ISR_690_MCAN2_CH0,
    &OsCfg_Isr_Os_ISR_701_MCAN7_CH1,
    &OsCfg_Isr_Os_ISR_700_MCAN7_CH0,
    &OsCfg_Isr_Os_ISR_698_LINTX_CH6,
    &OsCfg_Isr_Os_ISR_698_LINRX_CH6,
    &OsCfg_Isr_CounterIsr_SystemTimer_Core5,
    &OsCfg_Isr_MultiCommIsr_Core5,
    NULL_PTR
};
const Os_IsrCat1CfgType* const Os_Cat1IsrCfgData_OsCore0[OS_CFG_NUM_CAT1ISR_OSCORE0 + 1] = 
{
    NULL_PTR
};
const Os_IsrCat1CfgType* const Os_Cat1IsrCfgData_OsCore1[OS_CFG_NUM_CAT1ISR_OSCORE1 + 1] = 
{
    NULL_PTR
};
const Os_IsrCat1CfgType* const Os_Cat1IsrCfgData_OsCore2[OS_CFG_NUM_CAT1ISR_OSCORE2 + 1] = 
{
    NULL_PTR
};
const Os_IsrCat1CfgType* const Os_Cat1IsrCfgData_OsCore3[OS_CFG_NUM_CAT1ISR_OSCORE3 + 1] = 
{
    &OsCfg_Cat1Isr_Os_ISR_612_TIM6_CH6,
    &OsCfg_Cat1Isr_Os_ISR_777_TIM3_CH4,
    &OsCfg_Cat1Isr_Os_ISR_776_TIM3_CH3,
    &OsCfg_Cat1Isr_Os_ISR_775_TIM3_CH2,
    &OsCfg_Cat1Isr_Os_ISR_613_TIM6_CH5,
    &OsCfg_Cat1Isr_Os_ISR_614_TIM6_CH4,
    &OsCfg_Cat1Isr_Os_ISR_615_TIM6_CH3,
    &OsCfg_Cat1Isr_Os_ISR_616_TIM6_CH2,
    &OsCfg_Cat1Isr_Os_ISR_617_TIM6_CH1,
    &OsCfg_Cat1Isr_Os_ISR_618_TIM6_CH0,
    &OsCfg_Cat1Isr_Os_ISR_867_TIM4_CH0,
    &OsCfg_Cat1Isr_Os_ISR_840_ATOM0_CH3,
    &OsCfg_Cat1Isr_Os_ISR_874_TIM4_CH7,
    NULL_PTR
};
const Os_IsrCat1CfgType* const Os_Cat1IsrCfgData_OsCore4[OS_CFG_NUM_CAT1ISR_OSCORE4 + 1] = 
{
    NULL_PTR
};
const Os_IsrCat1CfgType* const Os_Cat1IsrCfgData_OsCore5[OS_CFG_NUM_CAT1ISR_OSCORE5 + 1] = 
{
    &OsCfg_Cat1Isr_Os_ISR_117_DMA1_CH0,
    NULL_PTR
};
const Os_CounterBaseCfgType* const Os_CounterCfgData[OS_COUNTERID_COUNT + 1] = 
{
    (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core0,
    (const Os_CounterBaseCfgType*)&OsCfg_Counter_Os_Monitor_Counter,
    (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core1,
    (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core2,
    (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core3,
    (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core4,
    (const Os_CounterBaseCfgType*)&OsCfg_Counter_SystemTimer_Core5,
    NULL_PTR
};
const Os_AlarmCfgType* const Os_AlarmCfgData[OS_ALARMID_COUNT + 1] = 
{
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_1ms_Core0_QM_1ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_5ms_Core0_QM_5ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_10ms_Core0_QM_10ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_20ms_Core0_QM_20ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_50ms_Core0_QM_50ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_100ms_Core0_QM_100ms,
    &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core0_QM_10ms,
    &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_5ms_Core0_QM_5ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_10ms_Core1_QM_10ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_1ms_Core1_QM_1ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_5ms_Core1_QM_5ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_20ms_Core1_QM_20ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_50ms_Core1_QM_50ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_100ms_Core1_QM_100ms,
    &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core1_QM_10ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_50ms_Core2_QM_50ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_100ms_Core2_QM_100ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_10ms_Core2_QM_10ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_1000ms_Core2_QM_1000ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_1ms_Core2_QM_1ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_5ms_Core2_QM_5ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_20ms_Core2_QM_20ms,
    &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core2_QM_10ms,
    &OsCfg_Alarm_Rte_Al_TE_Task_1ms_Core3_QM_1ms,
    &OsCfg_Alarm_Rte_Al_TE_Task_100us_Core3_QM_100us,
    &OsCfg_Alarm_Rte_Al_TE_Task_5ms_Core3_QM_5ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_1ms_Core4_QM_1ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_5ms_Core4_QM_5ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_10ms_Core4_QM_10ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_20ms_Core4_QM_20ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_50ms_Core4_QM_50ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_100ms_Core4_QM_100ms,
    &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_100ms_Core4_QM_100ms,
    &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_50ms_Core4_QM_50ms,
    &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_20ms_Core4_QM_20ms,
    &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core4_QM_10ms,
    &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_5ms_Core4_QM_5ms,
    &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_1ms_Core4_QM_1ms,
    &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core4_Offest_QM_10ms,
    &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_5ms_Core4_Offest_QM_5ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_1ms_Core5_QM_1ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_5ms_Core5_QM_5ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_10ms_Core5_QM_10ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_20ms_Core5_QM_20ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_50ms_Core5_QM_50ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_100ms_Core5_QM_100ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_200ms_Core5_QM_200ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_500ms_Core5_QM_500ms,
    &OsCfg_Alarm_Rte_Al_TE_App1_Task_1000ms_Core5_QM_1000ms,
    &OsCfg_Alarm_Rte_Al_TE_Bsw_Task_10ms_Core5_QM_10ms,
    NULL_PTR
};
const Os_SpinlockCfgType* const Os_SpinlockCfgData[OS_SPINLOCKID_COUNT + 1] = 
{
    &OsCfg_Spinlock_OsSpinlock0,
    &OsCfg_Spinlock_OsSpinlock1,
    &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData,
    &OsCfg_Spinlock_WDGMSPINLOCK,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_DTC_0x0402_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x1002_Operation,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x1003_Operation,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x11_Operation,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x14_Operation,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x22_Operation,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x27_Operation,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x28_Operation,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x2E_Operation,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x31_Operation,
    &OsCfg_Spinlock_Spinlock_Rte_CS_PMS_DID_ServiceCheckRule_0x85_Operation,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMS_BattPackMatchFault1_PMS_BMS_BattPackMatchFault1_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_BattPackNum_PMS_BMSH_BattPackNum_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_BattSysNum_PMS_BMSH_BattSysNum_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatIsoAlarm3_PMS_BMSH_TBOX_BatIsoAlarm3_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatLowSOC3_PMS_BMSH_TBOX_BatLowSOC3_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatOverCharge3_PMS_BMSH_TBOX_BatOverCharge3_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatOverSOC3_PMS_BMSH_TBOX_BatOverSOC3_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatOverTemp3_PMS_BMSH_TBOX_BatOverTemp3_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatOverVoltage3_PMS_BMSH_TBOX_BatOverVoltage3_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatTempUniformity3_PMS_BMSH_TBOX_BatTempUniformity3_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatUnderVoltage3_PMS_BMSH_TBOX_BatUnderVoltage3_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_BatUniformity3_PMS_BMSH_TBOX_BatUniformity3_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_CellOverVoltage3_PMS_BMSH_TBOX_CellOverVoltage3_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_CellUnderVoltage3_PMS_BMSH_TBOX_CellUnderVoltage3_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_FireAlarm2_PMS_BMSH_TBOX_FireAlarm2_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_BMSH_TBOX_SOCHop3_PMS_BMSH_TBOX_SOCHop3_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_IPU_MCUTempHighAlarm2_PMS_IPU_MCUTempHighAlarm2_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_IPU_MotorOverCurrFlt1_PMS_IPU_MotorOverCurrFlt1_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_IPU_MotorOverSpdFlt1_PMS_IPU_MotorOverSpdFlt1_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_IPU_MotorTempHighFault2_PMS_IPU_MotorTempHighFault2_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_ODP_TBOX_DcDcStsAlm1_PMS_ODP_TBOX_DcDcStsAlm1_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_ODP_TBOX_TDcDcAlm1_PMS_ODP_TBOX_TDcDcAlm1_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_PMS_32960FltNum_PMS_PMS_32960FltNum_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_PMS_OTAInstrucStsReminder_PMS_OTAInstrucStsReminder,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_PMS_OTAInstructRxnSts_PMS_OTAInstructRxnSts,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_PMS_TBOX_BrkSysErr1_PMS_PMS_TBOX_BrkSysErr1_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_Com_swc_VCOP_PMS_TBOX_HVILSts1_PMS_PMS_TBOX_HVILSts1_PMS,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x4000_Start,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x400F_Start,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start,
    &OsCfg_Spinlock_Spinlock_Rte_CS_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start,
    NULL_PTR
};
const Os_ResourceCfgType* const Os_ResourceCfgData[OS_RESOURCEID_COUNT + 1] = 
{
    &OsCfg_Resource_Core0_Task_OsResource0,
    &OsCfg_Resource_Core0_Isr_OsResource0,
    &OsCfg_Resource_Core1_Task_OsResource0,
    &OsCfg_Resource_Core1_Isr_OsResource0,
    &OsCfg_Resource_Core2_Task_OsResource0,
    &OsCfg_Resource_Core2_Isr_OsResource0,
    &OsCfg_Resource_Core3_Task_OsResource0,
    &OsCfg_Resource_Core3_Isr_OsResource0,
    &OsCfg_Resource_Core4_Task_OsResource0,
    &OsCfg_Resource_Core4_Isr_OsResource0,
    &OsCfg_Resource_Core5_Task_OsResource0,
    &OsCfg_Resource_Core5_Isr_OsResource0,
    NULL_PTR
};
#define OS_STOP_SEC_CONST 
#include "Os_MemMap.h"

