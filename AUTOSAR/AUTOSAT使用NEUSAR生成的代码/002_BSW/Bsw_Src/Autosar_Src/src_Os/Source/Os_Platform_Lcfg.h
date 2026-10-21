/*
********************************************************************************
*
*  File name: Os_Platform_Lcfg.h
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
* Change: Increase the const attribute of the structure.
* Cause: Bugfix
********************************************************************************
*/
#ifndef OS_PLATFORM_LCFG_H_
#define OS_PLATFORM_LCFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Types_Cfg.h"
#include "Os_Core_Types.h"
#include "Os_Cfg.h"
#include "Os_Arch_Kernal_Lcfg.h"
#include "Os_Alarm_Types.h"
#include "Os_Counter_Types.h"
#include "Os_App_Types.h"
#include "Os_Task_Types.h"
#include "Os_Isr_Types.h"
#include "Os_Resource_Types.h"
#include "Os_TrustFun_Types.h"
#include "Os_MultiCore_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define OS_SYSTEMAPPLICATION_OSCORE_CORE0_ACCESS      ((uint32)(1U << (SYSTEMAPPLICATION_OSCORE_CORE0)))
#define OS_APP1_APPLICATION_CORE0_QM_ACCESS           ((uint32)(1U << (APP1_APPLICATION_CORE0_QM)))
#define OS_BSW_APPLICATION_CORE0_QM_ACCESS            ((uint32)(1U << (BSW_APPLICATION_CORE0_QM)))
#define OS_SYSTEMAPPLICATION_OSCORE_CORE1_ACCESS      ((uint32)(1U << (SYSTEMAPPLICATION_OSCORE_CORE1)))
#define OS_APP1_APPLICATION_CORE1_QM_ACCESS           ((uint32)(1U << (APP1_APPLICATION_CORE1_QM)))
#define OS_BSW_APPLICATION_CORE1_QM_ACCESS            ((uint32)(1U << (BSW_APPLICATION_CORE1_QM)))
#define OS_SYSTEMAPPLICATION_OSCORE_CORE2_ACCESS      ((uint32)(1U << (SYSTEMAPPLICATION_OSCORE_CORE2)))
#define OS_APP1_APPLICATION_CORE2_QM_ACCESS           ((uint32)(1U << (APP1_APPLICATION_CORE2_QM)))
#define OS_BSW_APPLICATION_CORE2_QM_ACCESS            ((uint32)(1U << (BSW_APPLICATION_CORE2_QM)))
#define OS_SYSTEMAPPLICATION_OSCORE_CORE3_ACCESS      ((uint32)(1U << (SYSTEMAPPLICATION_OSCORE_CORE3)))
#define OS_APP1_APPLICATION_CORE3_QM_ACCESS           ((uint32)(1U << (APP1_APPLICATION_CORE3_QM)))
#define OS_BSW_APPLICATION_CORE3_QM_ACCESS            ((uint32)(1U << (BSW_APPLICATION_CORE3_QM)))
#define OS_SYSTEMAPPLICATION_OSCORE_CORE4_ACCESS      ((uint32)(1U << (SYSTEMAPPLICATION_OSCORE_CORE4)))
#define OS_APP1_APPLICATION_CORE4_QM_ACCESS           ((uint32)(1U << (APP1_APPLICATION_CORE4_QM)))
#define OS_BSW_APPLICATION_CORE4_QM_ACCESS            ((uint32)(1U << (BSW_APPLICATION_CORE4_QM)))
#define OS_SYSTEMAPPLICATION_OSCORE_CORE5_ACCESS      ((uint32)(1U << (SYSTEMAPPLICATION_OSCORE_CORE5)))
#define OS_APP1_APPLICATION_CORE5_QM_ACCESS           ((uint32)(1U << (APP1_APPLICATION_CORE5_QM)))
#define OS_BSW_APPLICATION_CORE5_QM_ACCESS            ((uint32)(1U << (BSW_APPLICATION_CORE5_QM)))
#define OS_CFG_NUM_CAT1ISR_OSCORE0 (0U)
#define OS_CFG_NUM_CAT1ISR_OSCORE1 (0U)
#define OS_CFG_NUM_CAT1ISR_OSCORE2 (0U)
#define OS_CFG_NUM_CAT1ISR_OSCORE3 (13U)
#define OS_CFG_NUM_CAT1ISR_OSCORE4 (0U)
#define OS_CFG_NUM_CAT1ISR_OSCORE5 (1U)
#define OS_CFG_NUM_TASKQUEUES_OSCORE0                 (11U)
#define OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE0       (8U)
#define OS_CFG_SIZE_TASKQUEUE0_OSCORE0                (100U)
#define OS_CFG_SIZE_TASKQUEUE1_OSCORE0                (100U)
#define OS_CFG_SIZE_TASKQUEUE2_OSCORE0                (100U)
#define OS_CFG_SIZE_TASKQUEUE3_OSCORE0                (100U)
#define OS_CFG_SIZE_TASKQUEUE4_OSCORE0                (100U)
#define OS_CFG_SIZE_TASKQUEUE5_OSCORE0                (100U)
#define OS_CFG_SIZE_TASKQUEUE6_OSCORE0                (100U)
#define OS_CFG_SIZE_TASKQUEUE7_OSCORE0                (100U)
#define OS_CFG_SIZE_TASKQUEUE8_OSCORE0                (100U)
#define OS_CFG_SIZE_TASKQUEUE9_OSCORE0                (100U)
#define OS_CFG_SIZE_TASKQUEUE10_OSCORE0               (100U)
#define OS_CFG_NUM_TASKQUEUES_OSCORE1                 (11U)
#define OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE1       (7U)
#define OS_CFG_SIZE_TASKQUEUE0_OSCORE1                (100U)
#define OS_CFG_SIZE_TASKQUEUE1_OSCORE1                (100U)
#define OS_CFG_SIZE_TASKQUEUE2_OSCORE1                (100U)
#define OS_CFG_SIZE_TASKQUEUE3_OSCORE1                (100U)
#define OS_CFG_SIZE_TASKQUEUE4_OSCORE1                (100U)
#define OS_CFG_SIZE_TASKQUEUE5_OSCORE1                (100U)
#define OS_CFG_SIZE_TASKQUEUE6_OSCORE1                (100U)
#define OS_CFG_SIZE_TASKQUEUE7_OSCORE1                (100U)
#define OS_CFG_SIZE_TASKQUEUE8_OSCORE1                (100U)
#define OS_CFG_SIZE_TASKQUEUE9_OSCORE1                (100U)
#define OS_CFG_SIZE_TASKQUEUE10_OSCORE1               (100U)
#define OS_CFG_NUM_TASKQUEUES_OSCORE2                 (14U)
#define OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE2       (8U)
#define OS_CFG_SIZE_TASKQUEUE0_OSCORE2                (100U)
#define OS_CFG_SIZE_TASKQUEUE1_OSCORE2                (100U)
#define OS_CFG_SIZE_TASKQUEUE2_OSCORE2                (100U)
#define OS_CFG_SIZE_TASKQUEUE3_OSCORE2                (100U)
#define OS_CFG_SIZE_TASKQUEUE4_OSCORE2                (100U)
#define OS_CFG_SIZE_TASKQUEUE5_OSCORE2                (100U)
#define OS_CFG_SIZE_TASKQUEUE6_OSCORE2                (100U)
#define OS_CFG_SIZE_TASKQUEUE7_OSCORE2                (100U)
#define OS_CFG_SIZE_TASKQUEUE8_OSCORE2                (100U)
#define OS_CFG_SIZE_TASKQUEUE9_OSCORE2                (100U)
#define OS_CFG_SIZE_TASKQUEUE10_OSCORE2               (100U)
#define OS_CFG_SIZE_TASKQUEUE11_OSCORE2               (100U)
#define OS_CFG_SIZE_TASKQUEUE12_OSCORE2               (100U)
#define OS_CFG_SIZE_TASKQUEUE13_OSCORE2               (100U)
#define OS_CFG_NUM_TASKQUEUES_OSCORE3                 (7U)
#define OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE3       (3U)
#define OS_CFG_SIZE_TASKQUEUE0_OSCORE3                (100U)
#define OS_CFG_SIZE_TASKQUEUE1_OSCORE3                (100U)
#define OS_CFG_SIZE_TASKQUEUE2_OSCORE3                (100U)
#define OS_CFG_SIZE_TASKQUEUE3_OSCORE3                (100U)
#define OS_CFG_SIZE_TASKQUEUE4_OSCORE3                (100U)
#define OS_CFG_SIZE_TASKQUEUE5_OSCORE3                (100U)
#define OS_CFG_SIZE_TASKQUEUE6_OSCORE3                (100U)
#define OS_CFG_NUM_TASKQUEUES_OSCORE4                 (18U)
#define OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE4       (14U)
#define OS_CFG_SIZE_TASKQUEUE0_OSCORE4                (100U)
#define OS_CFG_SIZE_TASKQUEUE1_OSCORE4                (100U)
#define OS_CFG_SIZE_TASKQUEUE2_OSCORE4                (100U)
#define OS_CFG_SIZE_TASKQUEUE3_OSCORE4                (100U)
#define OS_CFG_SIZE_TASKQUEUE4_OSCORE4                (100U)
#define OS_CFG_SIZE_TASKQUEUE5_OSCORE4                (100U)
#define OS_CFG_SIZE_TASKQUEUE6_OSCORE4                (100U)
#define OS_CFG_SIZE_TASKQUEUE7_OSCORE4                (100U)
#define OS_CFG_SIZE_TASKQUEUE8_OSCORE4                (100U)
#define OS_CFG_SIZE_TASKQUEUE9_OSCORE4                (100U)
#define OS_CFG_SIZE_TASKQUEUE10_OSCORE4               (100U)
#define OS_CFG_SIZE_TASKQUEUE11_OSCORE4               (100U)
#define OS_CFG_SIZE_TASKQUEUE12_OSCORE4               (100U)
#define OS_CFG_SIZE_TASKQUEUE13_OSCORE4               (100U)
#define OS_CFG_SIZE_TASKQUEUE14_OSCORE4               (100U)
#define OS_CFG_SIZE_TASKQUEUE15_OSCORE4               (100U)
#define OS_CFG_SIZE_TASKQUEUE16_OSCORE4               (100U)
#define OS_CFG_SIZE_TASKQUEUE17_OSCORE4               (100U)
#define OS_CFG_NUM_TASKQUEUES_OSCORE5                 (14U)
#define OS_CFG_NUM_TASKQUEUES_SYSTEMTIMER_CORE5       (10U)
#define OS_CFG_SIZE_TASKQUEUE0_OSCORE5                (100U)
#define OS_CFG_SIZE_TASKQUEUE1_OSCORE5                (100U)
#define OS_CFG_SIZE_TASKQUEUE2_OSCORE5                (100U)
#define OS_CFG_SIZE_TASKQUEUE3_OSCORE5                (100U)
#define OS_CFG_SIZE_TASKQUEUE4_OSCORE5                (100U)
#define OS_CFG_SIZE_TASKQUEUE5_OSCORE5                (100U)
#define OS_CFG_SIZE_TASKQUEUE6_OSCORE5                (100U)
#define OS_CFG_SIZE_TASKQUEUE7_OSCORE5                (100U)
#define OS_CFG_SIZE_TASKQUEUE8_OSCORE5                (100U)
#define OS_CFG_SIZE_TASKQUEUE9_OSCORE5                (100U)
#define OS_CFG_SIZE_TASKQUEUE10_OSCORE5               (100U)
#define OS_CFG_SIZE_TASKQUEUE11_OSCORE5               (100U)
#define OS_CFG_SIZE_TASKQUEUE12_OSCORE5               (100U)
#define OS_CFG_SIZE_TASKQUEUE13_OSCORE5               (100U)
#define OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE0     (1)
#define OS_TICKS2NS_SYSTEMTIMER_CORE0(x)              ((PhysicalTimeType) (((uint64)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE0* 1000000))
#define OS_TICKS2US_SYSTEMTIMER_CORE0(x)              ((PhysicalTimeType) (((uint64)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE0 * 1000))
#define OS_TICKS2MS_SYSTEMTIMER_CORE0(x)              ((PhysicalTimeType) (((uint32)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE0 * 1))
#define OS_TICKS2SEC_SYSTEMTIMER_CORE0(x)             ((PhysicalTimeType) (((uint32)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE0 / 1000.0))
#define OS_OSSECONDSPERTICK_HRT_OS_MONITOR_COUNTER    (1000)
#define OS_TICKS2NS_OS_MONITOR_COUNTER(x)             ((PhysicalTimeType) (((uint64)(x)) * 1000000000.0 / OS_OSSECONDSPERTICK_HRT_OS_MONITOR_COUNTER))
#define OS_TICKS2US_OS_MONITOR_COUNTER(x)             ((PhysicalTimeType) (((uint64)(x)) * 1000000.0 / OS_OSSECONDSPERTICK_HRT_OS_MONITOR_COUNTER))
#define OS_TICKS2MS_OS_MONITOR_COUNTER(x)             ((PhysicalTimeType) (((uint64)(x)) * 1000.0 / OS_OSSECONDSPERTICK_HRT_OS_MONITOR_COUNTER))
#define OS_TICKS2SEC_OS_MONITOR_COUNTER(x)            ((PhysicalTimeType) (((uint32)(x)) * 1.0 / OS_OSSECONDSPERTICK_HRT_OS_MONITOR_COUNTER))
#define OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE1     (1)
#define OS_TICKS2NS_SYSTEMTIMER_CORE1(x)              ((PhysicalTimeType) (((uint64)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE1* 1000000))
#define OS_TICKS2US_SYSTEMTIMER_CORE1(x)              ((PhysicalTimeType) (((uint64)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE1 * 1000))
#define OS_TICKS2MS_SYSTEMTIMER_CORE1(x)              ((PhysicalTimeType) (((uint32)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE1 * 1))
#define OS_TICKS2SEC_SYSTEMTIMER_CORE1(x)             ((PhysicalTimeType) (((uint32)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE1 / 1000.0))
#define OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE2     (1)
#define OS_TICKS2NS_SYSTEMTIMER_CORE2(x)              ((PhysicalTimeType) (((uint64)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE2* 1000000))
#define OS_TICKS2US_SYSTEMTIMER_CORE2(x)              ((PhysicalTimeType) (((uint64)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE2 * 1000))
#define OS_TICKS2MS_SYSTEMTIMER_CORE2(x)              ((PhysicalTimeType) (((uint32)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE2 * 1))
#define OS_TICKS2SEC_SYSTEMTIMER_CORE2(x)             ((PhysicalTimeType) (((uint32)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE2 / 1000.0))
#define OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE3     (1)
#define OS_TICKS2NS_SYSTEMTIMER_CORE3(x)              ((PhysicalTimeType) (((uint64)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE3* 1000000))
#define OS_TICKS2US_SYSTEMTIMER_CORE3(x)              ((PhysicalTimeType) (((uint64)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE3 * 1000))
#define OS_TICKS2MS_SYSTEMTIMER_CORE3(x)              ((PhysicalTimeType) (((uint32)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE3 * 1))
#define OS_TICKS2SEC_SYSTEMTIMER_CORE3(x)             ((PhysicalTimeType) (((uint32)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE3 / 1000.0))
#define OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE4     (1)
#define OS_TICKS2NS_SYSTEMTIMER_CORE4(x)              ((PhysicalTimeType) (((uint64)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE4* 1000000))
#define OS_TICKS2US_SYSTEMTIMER_CORE4(x)              ((PhysicalTimeType) (((uint64)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE4 * 1000))
#define OS_TICKS2MS_SYSTEMTIMER_CORE4(x)              ((PhysicalTimeType) (((uint32)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE4 * 1))
#define OS_TICKS2SEC_SYSTEMTIMER_CORE4(x)             ((PhysicalTimeType) (((uint32)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE4 / 1000.0))
#define OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE5     (1)
#define OS_TICKS2NS_SYSTEMTIMER_CORE5(x)              ((PhysicalTimeType) (((uint64)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE5* 1000000))
#define OS_TICKS2US_SYSTEMTIMER_CORE5(x)              ((PhysicalTimeType) (((uint64)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE5 * 1000))
#define OS_TICKS2MS_SYSTEMTIMER_CORE5(x)              ((PhysicalTimeType) (((uint32)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE5 * 1))
#define OS_TICKS2SEC_SYSTEMTIMER_CORE5(x)             ((PhysicalTimeType) (((uint32)(x)) * OS_OSSECONDSPERTICK_PIT_SYSTEMTIMER_CORE5 / 1000.0))
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/*
********************************************************************************
*    Global Variable
********************************************************************************
*/
#define OS_START_SEC_CONST 
#include "Os_MemMap.h"
extern const Os_IsrCfgType OsCfg_Isr_CounterIsr_SystemTimer_Core0;
extern const Os_IsrCfgType OsCfg_Isr_MultiCommIsr_Core0;
extern const Os_IsrCfgType OsCfg_Isr_Os_ISR_37_STM0_CH1;
extern const Os_IsrCfgType OsCfg_Isr_CounterIsr_SystemTimer_Core1;
extern const Os_IsrCfgType OsCfg_Isr_MultiCommIsr_Core1;
extern const Os_IsrCfgType OsCfg_Isr_CounterIsr_SystemTimer_Core2;
extern const Os_IsrCfgType OsCfg_Isr_MultiCommIsr_Core2;
extern const Os_IsrCfgType OsCfg_Isr_CounterIsr_SystemTimer_Core3;
extern const Os_IsrCfgType OsCfg_Isr_MultiCommIsr_Core3;
extern const Os_IsrCfgType OsCfg_Isr_CounterIsr_SystemTimer_Core4;
extern const Os_IsrCfgType OsCfg_Isr_MultiCommIsr_Core4;
extern const Os_IsrCfgType OsCfg_Isr_Os_ISR_450_MCAN11_CH1;
extern const Os_IsrCfgType OsCfg_Isr_Os_ISR_449_MCAN11_CH0;
extern const Os_IsrCfgType OsCfg_Isr_Os_ISR_699_MCAN6_CH1;
extern const Os_IsrCfgType OsCfg_Isr_Os_ISR_698_MCAN6_CH0;
extern const Os_IsrCfgType OsCfg_Isr_Os_ISR_689_MCAN1_CH1;
extern const Os_IsrCfgType OsCfg_Isr_Os_ISR_688_MCAN1_CH0;
extern const Os_IsrCfgType OsCfg_Isr_Os_ISR_446_MCAN9_CH1;
extern const Os_IsrCfgType OsCfg_Isr_Os_ISR_445_MCAN9_CH0;
extern const Os_IsrCfgType OsCfg_Isr_Os_ISR_693_MCAN3_CH1;
extern const Os_IsrCfgType OsCfg_Isr_Os_ISR_692_MCAN3_CH0;
extern const Os_IsrCfgType OsCfg_Isr_Os_ISR_691_MCAN2_CH1;
extern const Os_IsrCfgType OsCfg_Isr_Os_ISR_690_MCAN2_CH0;
extern const Os_IsrCfgType OsCfg_Isr_Os_ISR_701_MCAN7_CH1;
extern const Os_IsrCfgType OsCfg_Isr_Os_ISR_700_MCAN7_CH0;
extern const Os_IsrCfgType OsCfg_Isr_Os_ISR_698_LINTX_CH6;
extern const Os_IsrCfgType OsCfg_Isr_Os_ISR_698_LINRX_CH6;
extern const Os_IsrCfgType OsCfg_Isr_CounterIsr_SystemTimer_Core5;
extern const Os_IsrCfgType OsCfg_Isr_MultiCommIsr_Core5;
extern const Os_SchedulerCfgType OsCfg_Scheduler_OsCore0;
extern const Os_SchedulerCfgType OsCfg_Scheduler_OsCore1;
extern const Os_SchedulerCfgType OsCfg_Scheduler_OsCore2;
extern const Os_SchedulerCfgType OsCfg_Scheduler_OsCore3;
extern const Os_SchedulerCfgType OsCfg_Scheduler_OsCore4;
extern const Os_SchedulerCfgType OsCfg_Scheduler_OsCore5;
extern const Os_SystemCfgType Os_SystemCfgData;
extern const Os_CoreCfgType* const Os_CoreCfgData[OS_COREID_COUNT + 1];
extern const Os_AppCfgType* const Os_AppCfgData[OS_APPID_COUNT + 1];
extern const Os_TaskCfgType* const Os_TaskCfgData[OS_TASKID_COUNT + 1];
extern const Os_IsrCfgType* const Os_IsrCfgData[OS_ISRID_COUNT + 1];
extern const Os_AlarmCfgType* const Os_AlarmCfgData[OS_ALARMID_COUNT + 1];
extern const Os_CounterBaseCfgType* const Os_CounterCfgData[OS_COUNTERID_COUNT + 1];
extern const Os_SpinlockCfgType* const Os_SpinlockCfgData[OS_SPINLOCKID_COUNT + 1];
extern const Os_ResourceCfgType* const Os_ResourceCfgData[OS_RESOURCEID_COUNT + 1];
extern const Os_IsrCat1CfgType* const Os_Cat1IsrCfgData_OsCore0[OS_CFG_NUM_CAT1ISR_OSCORE0 + 1];
extern const Os_IsrCat1CfgType* const Os_Cat1IsrCfgData_OsCore1[OS_CFG_NUM_CAT1ISR_OSCORE1 + 1];
extern const Os_IsrCat1CfgType* const Os_Cat1IsrCfgData_OsCore2[OS_CFG_NUM_CAT1ISR_OSCORE2 + 1];
extern const Os_IsrCat1CfgType* const Os_Cat1IsrCfgData_OsCore3[OS_CFG_NUM_CAT1ISR_OSCORE3 + 1];
extern const Os_IsrCat1CfgType* const Os_Cat1IsrCfgData_OsCore4[OS_CFG_NUM_CAT1ISR_OSCORE4 + 1];
extern const Os_IsrCat1CfgType* const Os_Cat1IsrCfgData_OsCore5[OS_CFG_NUM_CAT1ISR_OSCORE5 + 1];
extern const uint32 _start;
#define OS_STOP_SEC_CONST 
#include "Os_MemMap.h"
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

#if(OS_CFG_STARTUPHOOK_SYSTEM == STD_ON)
extern void StartupHook(void);
#endif

#if(OS_CFG_ERRORHOOK_SYSTEM == STD_ON)
extern void ErrorHook(StatusType Error);
#endif

#if(OS_CFG_SHUTDOWNHOOK_SYSTEM == STD_ON)
extern void ShutdownHook(StatusType Fatalerror);
#endif

#if(OS_CFG_PROTECTIONHOOK_SYSTEM == STD_ON)
extern ProtectionReturnType ProtectionHook(StatusType Fatalerror);
#endif




#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* OS_PLATFORM_LCFG_H_ */


