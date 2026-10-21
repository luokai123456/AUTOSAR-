/*
********************************************************************************
*
*  File name: Os_Arch_Kernal_Lcfg.c
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: MiaoLH/2025.1.20
* Change: New create.
* Cause: New
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Types.h"
#include "Os_Arch_Kernal_Lcfg.h"
#include "Os_Arch_Context_Types.h"
#include "Os_Arch_Types.h"
#include "Os_Lcfg.h"
#include "Os_Task.h"
#include "Os_Isr.h"
#include "Os_MultiCore.h"
#include "Os_Arch_Mach_MP_Types.h"
#include "Os_Arch_Mach_Timer.h"
#include "Os_TmProtection.h"
#include "Os_MemMap.h"

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

#define OS_START_SEC_STACK_OSCORE0 
#include "Os_MemMap.h"
Os_Stack_Address OsCfg_Arch_Stack_Kernal_OsCore0 [OS_ARCH_KERNAL_OSCORE0_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Default_Init_Task_Core0[OS_ARCH_DEFAULT_INIT_TASK_CORE0_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Idle_Task_Core0[OS_ARCH_IDLE_TASK_CORE0_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_CounterIsr_SystemTimer_Core0[OS_ARCH_COUNTERISR_SYSTEMTIMER_CORE0_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_MultiCommIsr_Core0[OS_ARCH_MULTICOMMISR_CORE0_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_1ms_Core0_QM[OS_ARCH_APP1_TASK_1MS_CORE0_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_5ms_Core0_QM[OS_ARCH_APP1_TASK_5MS_CORE0_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_10ms_Core0_QM[OS_ARCH_APP1_TASK_10MS_CORE0_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_20ms_Core0_QM[OS_ARCH_APP1_TASK_20MS_CORE0_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_50ms_Core0_QM[OS_ARCH_APP1_TASK_50MS_CORE0_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_100ms_Core0_QM[OS_ARCH_APP1_TASK_100MS_CORE0_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_SWC_Init_Task_Core0[OS_ARCH_SWC_INIT_TASK_CORE0_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Bsw_Task_10ms_Core0_QM[OS_ARCH_BSW_TASK_10MS_CORE0_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Bsw_Task_5ms_Core0_QM[OS_ARCH_BSW_TASK_5MS_CORE0_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Os_ISR_37_STM0_CH1[OS_ARCH_OS_ISR_37_STM0_CH1_STACK_SIZE / OS_STACK_TYPE_WIDTH];
#define OS_STOP_SEC_STACK_OSCORE0 
#include "Os_MemMap.h"

#define OS_START_SEC_STACK_OSCORE1 
#include "Os_MemMap.h"
Os_Stack_Address OsCfg_Arch_Stack_Kernal_OsCore1 [OS_ARCH_KERNAL_OSCORE1_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Default_Init_Task_Core1[OS_ARCH_DEFAULT_INIT_TASK_CORE1_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Idle_Task_Core1[OS_ARCH_IDLE_TASK_CORE1_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_CounterIsr_SystemTimer_Core1[OS_ARCH_COUNTERISR_SYSTEMTIMER_CORE1_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_MultiCommIsr_Core1[OS_ARCH_MULTICOMMISR_CORE1_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_10ms_Core1_QM[OS_ARCH_APP1_TASK_10MS_CORE1_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_SWC_Init_Task_Core1[OS_ARCH_SWC_INIT_TASK_CORE1_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_1ms_Core1_QM[OS_ARCH_APP1_TASK_1MS_CORE1_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_5ms_Core1_QM[OS_ARCH_APP1_TASK_5MS_CORE1_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_20ms_Core1_QM[OS_ARCH_APP1_TASK_20MS_CORE1_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_50ms_Core1_QM[OS_ARCH_APP1_TASK_50MS_CORE1_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_100ms_Core1_QM[OS_ARCH_APP1_TASK_100MS_CORE1_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_UDS_Core1_QM[OS_ARCH_APP1_TASK_UDS_CORE1_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Bsw_Task_10ms_Core1_QM[OS_ARCH_BSW_TASK_10MS_CORE1_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
#define OS_STOP_SEC_STACK_OSCORE1 
#include "Os_MemMap.h"

#define OS_START_SEC_STACK_OSCORE2 
#include "Os_MemMap.h"
Os_Stack_Address OsCfg_Arch_Stack_Kernal_OsCore2 [OS_ARCH_KERNAL_OSCORE2_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Default_Init_Task_Core2[OS_ARCH_DEFAULT_INIT_TASK_CORE2_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Idle_Task_Core2[OS_ARCH_IDLE_TASK_CORE2_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_CounterIsr_SystemTimer_Core2[OS_ARCH_COUNTERISR_SYSTEMTIMER_CORE2_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_MultiCommIsr_Core2[OS_ARCH_MULTICOMMISR_CORE2_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_50ms_Core2_QM[OS_ARCH_APP1_TASK_50MS_CORE2_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_100ms_Core2_QM[OS_ARCH_APP1_TASK_100MS_CORE2_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_10ms_Core2_QM[OS_ARCH_APP1_TASK_10MS_CORE2_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_1000ms_Core2_QM[OS_ARCH_APP1_TASK_1000MS_CORE2_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_SWC_Init_Task_Core2[OS_ARCH_SWC_INIT_TASK_CORE2_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_1ms_Core2_QM[OS_ARCH_APP1_TASK_1MS_CORE2_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_5ms_Core2_QM[OS_ARCH_APP1_TASK_5MS_CORE2_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_20ms_Core2_QM[OS_ARCH_APP1_TASK_20MS_CORE2_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task0_UDS_Core2_QM[OS_ARCH_APP1_TASK0_UDS_CORE2_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task1_UDS_Core2_QM[OS_ARCH_APP1_TASK1_UDS_CORE2_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task2_UDS_Core2_QM[OS_ARCH_APP1_TASK2_UDS_CORE2_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Bsw_Task_10ms_Core2_QM[OS_ARCH_BSW_TASK_10MS_CORE2_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
#define OS_STOP_SEC_STACK_OSCORE2 
#include "Os_MemMap.h"

#define OS_START_SEC_STACK_OSCORE3 
#include "Os_MemMap.h"
Os_Stack_Address OsCfg_Arch_Stack_Kernal_OsCore3 [OS_ARCH_KERNAL_OSCORE3_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Default_Init_Task_Core3[OS_ARCH_DEFAULT_INIT_TASK_CORE3_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Idle_Task_Core3[OS_ARCH_IDLE_TASK_CORE3_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_CounterIsr_SystemTimer_Core3[OS_ARCH_COUNTERISR_SYSTEMTIMER_CORE3_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_MultiCommIsr_Core3[OS_ARCH_MULTICOMMISR_CORE3_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_SWC_Init_Task_Core3[OS_ARCH_SWC_INIT_TASK_CORE3_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_UDS_Core3_QM[OS_ARCH_APP1_TASK_UDS_CORE3_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Task_1ms_Core3_QM[OS_ARCH_TASK_1MS_CORE3_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Task_100us_Core3_QM[OS_ARCH_TASK_100US_CORE3_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Task_5ms_Core3_QM[OS_ARCH_TASK_5MS_CORE3_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
#define OS_STOP_SEC_STACK_OSCORE3 
#include "Os_MemMap.h"

#define OS_START_SEC_STACK_OSCORE4 
#include "Os_MemMap.h"
Os_Stack_Address OsCfg_Arch_Stack_Kernal_OsCore4 [OS_ARCH_KERNAL_OSCORE4_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Default_Init_Task_Core4[OS_ARCH_DEFAULT_INIT_TASK_CORE4_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Idle_Task_Core4[OS_ARCH_IDLE_TASK_CORE4_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_CounterIsr_SystemTimer_Core4[OS_ARCH_COUNTERISR_SYSTEMTIMER_CORE4_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_MultiCommIsr_Core4[OS_ARCH_MULTICOMMISR_CORE4_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_1ms_Core4_QM[OS_ARCH_APP1_TASK_1MS_CORE4_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_5ms_Core4_QM[OS_ARCH_APP1_TASK_5MS_CORE4_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_10ms_Core4_QM[OS_ARCH_APP1_TASK_10MS_CORE4_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_20ms_Core4_QM[OS_ARCH_APP1_TASK_20MS_CORE4_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_50ms_Core4_QM[OS_ARCH_APP1_TASK_50MS_CORE4_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_100ms_Core4_QM[OS_ARCH_APP1_TASK_100MS_CORE4_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_SWC_Init_Task_Core4[OS_ARCH_SWC_INIT_TASK_CORE4_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_UDS_Core4_QM[OS_ARCH_APP1_TASK_UDS_CORE4_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Bsw_Task_100ms_Core4_QM[OS_ARCH_BSW_TASK_100MS_CORE4_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Bsw_Task_50ms_Core4_QM[OS_ARCH_BSW_TASK_50MS_CORE4_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Bsw_Task_20ms_Core4_QM[OS_ARCH_BSW_TASK_20MS_CORE4_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Bsw_Task_10ms_Core4_QM[OS_ARCH_BSW_TASK_10MS_CORE4_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Bsw_Task_5ms_Core4_QM[OS_ARCH_BSW_TASK_5MS_CORE4_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Bsw_Task_1ms_Core4_QM[OS_ARCH_BSW_TASK_1MS_CORE4_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Bsw_Task_5ms_Core4_Offest_QM[OS_ARCH_BSW_TASK_5MS_CORE4_OFFEST_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Bsw_Task_10ms_Core4_Offest_QM[OS_ARCH_BSW_TASK_10MS_CORE4_OFFEST_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Os_ISR_450_MCAN11_CH1[OS_ARCH_OS_ISR_450_MCAN11_CH1_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Os_ISR_449_MCAN11_CH0[OS_ARCH_OS_ISR_449_MCAN11_CH0_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Os_ISR_699_MCAN6_CH1[OS_ARCH_OS_ISR_699_MCAN6_CH1_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Os_ISR_698_MCAN6_CH0[OS_ARCH_OS_ISR_698_MCAN6_CH0_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Os_ISR_689_MCAN1_CH1[OS_ARCH_OS_ISR_689_MCAN1_CH1_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Os_ISR_688_MCAN1_CH0[OS_ARCH_OS_ISR_688_MCAN1_CH0_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Os_ISR_446_MCAN9_CH1[OS_ARCH_OS_ISR_446_MCAN9_CH1_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Os_ISR_445_MCAN9_CH0[OS_ARCH_OS_ISR_445_MCAN9_CH0_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Os_ISR_693_MCAN3_CH1[OS_ARCH_OS_ISR_693_MCAN3_CH1_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Os_ISR_692_MCAN3_CH0[OS_ARCH_OS_ISR_692_MCAN3_CH0_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Os_ISR_691_MCAN2_CH1[OS_ARCH_OS_ISR_691_MCAN2_CH1_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Os_ISR_690_MCAN2_CH0[OS_ARCH_OS_ISR_690_MCAN2_CH0_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Os_ISR_701_MCAN7_CH1[OS_ARCH_OS_ISR_701_MCAN7_CH1_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Os_ISR_700_MCAN7_CH0[OS_ARCH_OS_ISR_700_MCAN7_CH0_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Os_ISR_698_LINTX_CH6[OS_ARCH_OS_ISR_698_LINTX_CH6_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Os_ISR_698_LINRX_CH6[OS_ARCH_OS_ISR_698_LINRX_CH6_STACK_SIZE / OS_STACK_TYPE_WIDTH];
#define OS_STOP_SEC_STACK_OSCORE4 
#include "Os_MemMap.h"

#define OS_START_SEC_STACK_OSCORE5 
#include "Os_MemMap.h"
Os_Stack_Address OsCfg_Arch_Stack_Kernal_OsCore5 [OS_ARCH_KERNAL_OSCORE5_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Default_Init_Task_Core5[OS_ARCH_DEFAULT_INIT_TASK_CORE5_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Idle_Task_Core5[OS_ARCH_IDLE_TASK_CORE5_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_CounterIsr_SystemTimer_Core5[OS_ARCH_COUNTERISR_SYSTEMTIMER_CORE5_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_MultiCommIsr_Core5[OS_ARCH_MULTICOMMISR_CORE5_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_1ms_Core5_QM[OS_ARCH_APP1_TASK_1MS_CORE5_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_5ms_Core5_QM[OS_ARCH_APP1_TASK_5MS_CORE5_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_10ms_Core5_QM[OS_ARCH_APP1_TASK_10MS_CORE5_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_20ms_Core5_QM[OS_ARCH_APP1_TASK_20MS_CORE5_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_50ms_Core5_QM[OS_ARCH_APP1_TASK_50MS_CORE5_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_100ms_Core5_QM[OS_ARCH_APP1_TASK_100MS_CORE5_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_SWC_Init_Task_Core5[OS_ARCH_SWC_INIT_TASK_CORE5_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_UDS_Core5_QM[OS_ARCH_APP1_TASK_UDS_CORE5_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_200ms_Core5_QM[OS_ARCH_APP1_TASK_200MS_CORE5_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_500ms_Core5_QM[OS_ARCH_APP1_TASK_500MS_CORE5_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_App1_Task_1000ms_Core5_QM[OS_ARCH_APP1_TASK_1000MS_CORE5_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
Os_Stack_Address OsCfg_Arch_Stack_Bsw_Task_10ms_Core5_QM[OS_ARCH_BSW_TASK_10MS_CORE5_QM_STACK_SIZE / OS_STACK_TYPE_WIDTH];
#define OS_STOP_SEC_STACK_OSCORE5 
#include "Os_MemMap.h"


#define OS_START_SEC_VAR_OSCORE0 
#include "Os_MemMap.h"
Os_Arch_ContextDynType OsCfg_Arch_Context_Kernal_OsCore0_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Default_Init_Task_Core0_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Idle_Task_Core0_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_CounterIsr_SystemTimer_Core0_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_MultiCommIsr_Core0_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_1ms_Core0_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_5ms_Core0_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_10ms_Core0_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_20ms_Core0_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_50ms_Core0_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_100ms_Core0_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_SWC_Init_Task_Core0_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Bsw_Task_10ms_Core0_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Bsw_Task_5ms_Core0_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Os_ISR_37_STM0_CH1_Dyn;
#define OS_STOP_SEC_VAR_OSCORE0 
#include "Os_MemMap.h"


#define OS_START_SEC_VAR_OSCORE1 
#include "Os_MemMap.h"
Os_Arch_ContextDynType OsCfg_Arch_Context_Kernal_OsCore1_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Default_Init_Task_Core1_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Idle_Task_Core1_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_CounterIsr_SystemTimer_Core1_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_MultiCommIsr_Core1_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_10ms_Core1_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_SWC_Init_Task_Core1_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_1ms_Core1_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_5ms_Core1_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_20ms_Core1_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_50ms_Core1_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_100ms_Core1_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_UDS_Core1_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Bsw_Task_10ms_Core1_QM_Dyn;
#define OS_STOP_SEC_VAR_OSCORE1 
#include "Os_MemMap.h"


#define OS_START_SEC_VAR_OSCORE2 
#include "Os_MemMap.h"
Os_Arch_ContextDynType OsCfg_Arch_Context_Kernal_OsCore2_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Default_Init_Task_Core2_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Idle_Task_Core2_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_CounterIsr_SystemTimer_Core2_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_MultiCommIsr_Core2_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_50ms_Core2_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_100ms_Core2_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_10ms_Core2_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_1000ms_Core2_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_SWC_Init_Task_Core2_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_1ms_Core2_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_5ms_Core2_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_20ms_Core2_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task0_UDS_Core2_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task1_UDS_Core2_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task2_UDS_Core2_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Bsw_Task_10ms_Core2_QM_Dyn;
#define OS_STOP_SEC_VAR_OSCORE2 
#include "Os_MemMap.h"


#define OS_START_SEC_VAR_OSCORE3 
#include "Os_MemMap.h"
Os_Arch_ContextDynType OsCfg_Arch_Context_Kernal_OsCore3_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Default_Init_Task_Core3_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Idle_Task_Core3_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_CounterIsr_SystemTimer_Core3_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_MultiCommIsr_Core3_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_SWC_Init_Task_Core3_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_UDS_Core3_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Task_1ms_Core3_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Task_100us_Core3_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Task_5ms_Core3_QM_Dyn;
#define OS_STOP_SEC_VAR_OSCORE3 
#include "Os_MemMap.h"


#define OS_START_SEC_VAR_OSCORE4 
#include "Os_MemMap.h"
Os_Arch_ContextDynType OsCfg_Arch_Context_Kernal_OsCore4_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Default_Init_Task_Core4_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Idle_Task_Core4_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_CounterIsr_SystemTimer_Core4_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_MultiCommIsr_Core4_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_1ms_Core4_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_5ms_Core4_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_10ms_Core4_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_20ms_Core4_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_50ms_Core4_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_100ms_Core4_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_SWC_Init_Task_Core4_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_UDS_Core4_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Bsw_Task_100ms_Core4_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Bsw_Task_50ms_Core4_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Bsw_Task_20ms_Core4_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Bsw_Task_10ms_Core4_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Bsw_Task_5ms_Core4_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Bsw_Task_1ms_Core4_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Bsw_Task_5ms_Core4_Offest_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Bsw_Task_10ms_Core4_Offest_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Os_ISR_450_MCAN11_CH1_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Os_ISR_449_MCAN11_CH0_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Os_ISR_699_MCAN6_CH1_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Os_ISR_698_MCAN6_CH0_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Os_ISR_689_MCAN1_CH1_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Os_ISR_688_MCAN1_CH0_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Os_ISR_446_MCAN9_CH1_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Os_ISR_445_MCAN9_CH0_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Os_ISR_693_MCAN3_CH1_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Os_ISR_692_MCAN3_CH0_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Os_ISR_691_MCAN2_CH1_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Os_ISR_690_MCAN2_CH0_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Os_ISR_701_MCAN7_CH1_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Os_ISR_700_MCAN7_CH0_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Os_ISR_698_LINTX_CH6_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Os_ISR_698_LINRX_CH6_Dyn;
#define OS_STOP_SEC_VAR_OSCORE4 
#include "Os_MemMap.h"


#define OS_START_SEC_VAR_OSCORE5 
#include "Os_MemMap.h"
Os_Arch_ContextDynType OsCfg_Arch_Context_Kernal_OsCore5_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Default_Init_Task_Core5_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Idle_Task_Core5_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_CounterIsr_SystemTimer_Core5_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_MultiCommIsr_Core5_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_1ms_Core5_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_5ms_Core5_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_10ms_Core5_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_20ms_Core5_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_50ms_Core5_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_100ms_Core5_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_SWC_Init_Task_Core5_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_UDS_Core5_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_200ms_Core5_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_500ms_Core5_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_App1_Task_1000ms_Core5_QM_Dyn;
Os_Arch_ContextDynType OsCfg_Arch_Context_Bsw_Task_10ms_Core5_QM_Dyn;
#define OS_STOP_SEC_VAR_OSCORE5 
#include "Os_MemMap.h"


/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
/*
********************************************************************************
*    Local Functions
********************************************************************************
*/
/*
********************************************************************************
*    Global Variable
********************************************************************************
*/
#define OS_START_SEC_CONST 
#include "Os_MemMap.h"
const CoreIdType Os_Arch_CoreMappingTable[OS_ARCH_PHYSICAL_CORE_NUM] =
{
    OS_CORE_ID_0,
    OS_CORE_ID_1,
    OS_CORE_ID_2,
    OS_CORE_ID_3,
    OS_CORE_ID_4,
    OS_CORE_ID_5
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Kernal_OsCore0 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Kernal_OsCore0_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ 0U,
    /* exitAddr       = */ 0U,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Kernal_OsCore0, OS_ARCH_KERNAL_OSCORE0_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Kernal_OsCore0)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Default_Init_Task_Core0 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Default_Init_Task_Core0_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Default_Init_Task_Core0,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Default_Init_Task_Core0, OS_ARCH_DEFAULT_INIT_TASK_CORE0_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Default_Init_Task_Core0)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Idle_Task_Core0 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Idle_Task_Core0_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Idle_Task_Core0,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Idle_Task_Core0, OS_ARCH_IDLE_TASK_CORE0_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Idle_Task_Core0)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_CounterIsr_SystemTimer_Core0 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_CounterIsr_SystemTimer_Core0_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL4,
    /* entryAddr      = */ (uint32)&OS_PIT,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_CounterIsr_SystemTimer_Core0, OS_ARCH_COUNTERISR_SYSTEMTIMER_CORE0_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_CounterIsr_SystemTimer_Core0)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_MultiCommIsr_Core0 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_MultiCommIsr_Core0_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL1,
    /* entryAddr      = */ (uint32)&Os_MultiCoreServer_Handler,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_MultiCommIsr_Core0, OS_ARCH_MULTICOMMISR_CORE0_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_MultiCommIsr_Core0)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_1ms_Core0_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_1ms_Core0_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_1ms_Core0_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_1ms_Core0_QM, OS_ARCH_APP1_TASK_1MS_CORE0_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_1ms_Core0_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_5ms_Core0_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_5ms_Core0_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_5ms_Core0_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_5ms_Core0_QM, OS_ARCH_APP1_TASK_5MS_CORE0_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_5ms_Core0_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_10ms_Core0_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_10ms_Core0_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_10ms_Core0_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_10ms_Core0_QM, OS_ARCH_APP1_TASK_10MS_CORE0_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_10ms_Core0_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_20ms_Core0_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_20ms_Core0_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_20ms_Core0_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_20ms_Core0_QM, OS_ARCH_APP1_TASK_20MS_CORE0_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_20ms_Core0_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_50ms_Core0_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_50ms_Core0_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_50ms_Core0_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_50ms_Core0_QM, OS_ARCH_APP1_TASK_50MS_CORE0_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_50ms_Core0_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_100ms_Core0_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_100ms_Core0_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_100ms_Core0_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_100ms_Core0_QM, OS_ARCH_APP1_TASK_100MS_CORE0_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_100ms_Core0_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_SWC_Init_Task_Core0 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_SWC_Init_Task_Core0_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_SWC_Init_Task_Core0,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_SWC_Init_Task_Core0, OS_ARCH_SWC_INIT_TASK_CORE0_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_SWC_Init_Task_Core0)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_10ms_Core0_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Bsw_Task_10ms_Core0_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Bsw_Task_10ms_Core0_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Bsw_Task_10ms_Core0_QM, OS_ARCH_BSW_TASK_10MS_CORE0_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Bsw_Task_10ms_Core0_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_5ms_Core0_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Bsw_Task_5ms_Core0_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Bsw_Task_5ms_Core0_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Bsw_Task_5ms_Core0_QM, OS_ARCH_BSW_TASK_5MS_CORE0_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Bsw_Task_5ms_Core0_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_37_STM0_CH1 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Os_ISR_37_STM0_CH1_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL20,
    /* entryAddr      = */ (uint32)&OS_HRT,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Os_ISR_37_STM0_CH1, OS_ARCH_OS_ISR_37_STM0_CH1_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Os_ISR_37_STM0_CH1)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Kernal_OsCore1 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Kernal_OsCore1_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ 0U,
    /* exitAddr       = */ 0U,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Kernal_OsCore1, OS_ARCH_KERNAL_OSCORE1_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Kernal_OsCore1)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Default_Init_Task_Core1 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Default_Init_Task_Core1_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Default_Init_Task_Core1,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Default_Init_Task_Core1, OS_ARCH_DEFAULT_INIT_TASK_CORE1_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Default_Init_Task_Core1)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Idle_Task_Core1 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Idle_Task_Core1_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Idle_Task_Core1,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Idle_Task_Core1, OS_ARCH_IDLE_TASK_CORE1_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Idle_Task_Core1)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_CounterIsr_SystemTimer_Core1 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_CounterIsr_SystemTimer_Core1_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL4,
    /* entryAddr      = */ (uint32)&OS_PIT,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_CounterIsr_SystemTimer_Core1, OS_ARCH_COUNTERISR_SYSTEMTIMER_CORE1_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_CounterIsr_SystemTimer_Core1)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_MultiCommIsr_Core1 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_MultiCommIsr_Core1_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL1,
    /* entryAddr      = */ (uint32)&Os_MultiCoreServer_Handler,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_MultiCommIsr_Core1, OS_ARCH_MULTICOMMISR_CORE1_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_MultiCommIsr_Core1)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_10ms_Core1_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_10ms_Core1_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_10ms_Core1_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_10ms_Core1_QM, OS_ARCH_APP1_TASK_10MS_CORE1_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_10ms_Core1_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_SWC_Init_Task_Core1 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_SWC_Init_Task_Core1_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_SWC_Init_Task_Core1,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_SWC_Init_Task_Core1, OS_ARCH_SWC_INIT_TASK_CORE1_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_SWC_Init_Task_Core1)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_1ms_Core1_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_1ms_Core1_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_1ms_Core1_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_1ms_Core1_QM, OS_ARCH_APP1_TASK_1MS_CORE1_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_1ms_Core1_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_5ms_Core1_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_5ms_Core1_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_5ms_Core1_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_5ms_Core1_QM, OS_ARCH_APP1_TASK_5MS_CORE1_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_5ms_Core1_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_20ms_Core1_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_20ms_Core1_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_20ms_Core1_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_20ms_Core1_QM, OS_ARCH_APP1_TASK_20MS_CORE1_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_20ms_Core1_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_50ms_Core1_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_50ms_Core1_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_50ms_Core1_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_50ms_Core1_QM, OS_ARCH_APP1_TASK_50MS_CORE1_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_50ms_Core1_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_100ms_Core1_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_100ms_Core1_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_100ms_Core1_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_100ms_Core1_QM, OS_ARCH_APP1_TASK_100MS_CORE1_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_100ms_Core1_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_UDS_Core1_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_UDS_Core1_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_UDS_Core1_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_UDS_Core1_QM, OS_ARCH_APP1_TASK_UDS_CORE1_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_UDS_Core1_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_10ms_Core1_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Bsw_Task_10ms_Core1_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Bsw_Task_10ms_Core1_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Bsw_Task_10ms_Core1_QM, OS_ARCH_BSW_TASK_10MS_CORE1_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Bsw_Task_10ms_Core1_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Kernal_OsCore2 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Kernal_OsCore2_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ 0U,
    /* exitAddr       = */ 0U,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Kernal_OsCore2, OS_ARCH_KERNAL_OSCORE2_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Kernal_OsCore2)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Default_Init_Task_Core2 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Default_Init_Task_Core2_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Default_Init_Task_Core2,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Default_Init_Task_Core2, OS_ARCH_DEFAULT_INIT_TASK_CORE2_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Default_Init_Task_Core2)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Idle_Task_Core2 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Idle_Task_Core2_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Idle_Task_Core2,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Idle_Task_Core2, OS_ARCH_IDLE_TASK_CORE2_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Idle_Task_Core2)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_CounterIsr_SystemTimer_Core2 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_CounterIsr_SystemTimer_Core2_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL4,
    /* entryAddr      = */ (uint32)&OS_PIT,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_CounterIsr_SystemTimer_Core2, OS_ARCH_COUNTERISR_SYSTEMTIMER_CORE2_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_CounterIsr_SystemTimer_Core2)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_MultiCommIsr_Core2 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_MultiCommIsr_Core2_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL1,
    /* entryAddr      = */ (uint32)&Os_MultiCoreServer_Handler,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_MultiCommIsr_Core2, OS_ARCH_MULTICOMMISR_CORE2_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_MultiCommIsr_Core2)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_50ms_Core2_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_50ms_Core2_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_50ms_Core2_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_50ms_Core2_QM, OS_ARCH_APP1_TASK_50MS_CORE2_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_50ms_Core2_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_100ms_Core2_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_100ms_Core2_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_100ms_Core2_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_100ms_Core2_QM, OS_ARCH_APP1_TASK_100MS_CORE2_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_100ms_Core2_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_10ms_Core2_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_10ms_Core2_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_10ms_Core2_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_10ms_Core2_QM, OS_ARCH_APP1_TASK_10MS_CORE2_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_10ms_Core2_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_1000ms_Core2_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_1000ms_Core2_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_1000ms_Core2_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_1000ms_Core2_QM, OS_ARCH_APP1_TASK_1000MS_CORE2_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_1000ms_Core2_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_SWC_Init_Task_Core2 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_SWC_Init_Task_Core2_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_SWC_Init_Task_Core2,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_SWC_Init_Task_Core2, OS_ARCH_SWC_INIT_TASK_CORE2_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_SWC_Init_Task_Core2)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_1ms_Core2_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_1ms_Core2_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_1ms_Core2_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_1ms_Core2_QM, OS_ARCH_APP1_TASK_1MS_CORE2_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_1ms_Core2_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_5ms_Core2_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_5ms_Core2_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_5ms_Core2_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_5ms_Core2_QM, OS_ARCH_APP1_TASK_5MS_CORE2_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_5ms_Core2_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_20ms_Core2_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_20ms_Core2_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_20ms_Core2_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_20ms_Core2_QM, OS_ARCH_APP1_TASK_20MS_CORE2_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_20ms_Core2_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task0_UDS_Core2_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task0_UDS_Core2_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task0_UDS_Core2_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task0_UDS_Core2_QM, OS_ARCH_APP1_TASK0_UDS_CORE2_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task0_UDS_Core2_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task1_UDS_Core2_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task1_UDS_Core2_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task1_UDS_Core2_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task1_UDS_Core2_QM, OS_ARCH_APP1_TASK1_UDS_CORE2_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task1_UDS_Core2_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task2_UDS_Core2_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task2_UDS_Core2_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task2_UDS_Core2_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task2_UDS_Core2_QM, OS_ARCH_APP1_TASK2_UDS_CORE2_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task2_UDS_Core2_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_10ms_Core2_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Bsw_Task_10ms_Core2_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Bsw_Task_10ms_Core2_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Bsw_Task_10ms_Core2_QM, OS_ARCH_BSW_TASK_10MS_CORE2_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Bsw_Task_10ms_Core2_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Kernal_OsCore3 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Kernal_OsCore3_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ 0U,
    /* exitAddr       = */ 0U,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Kernal_OsCore3, OS_ARCH_KERNAL_OSCORE3_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Kernal_OsCore3)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Default_Init_Task_Core3 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Default_Init_Task_Core3_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Default_Init_Task_Core3,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Default_Init_Task_Core3, OS_ARCH_DEFAULT_INIT_TASK_CORE3_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Default_Init_Task_Core3)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Idle_Task_Core3 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Idle_Task_Core3_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Idle_Task_Core3,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Idle_Task_Core3, OS_ARCH_IDLE_TASK_CORE3_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Idle_Task_Core3)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_CounterIsr_SystemTimer_Core3 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_CounterIsr_SystemTimer_Core3_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL4,
    /* entryAddr      = */ (uint32)&OS_PIT,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_CounterIsr_SystemTimer_Core3, OS_ARCH_COUNTERISR_SYSTEMTIMER_CORE3_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_CounterIsr_SystemTimer_Core3)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_MultiCommIsr_Core3 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_MultiCommIsr_Core3_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL1,
    /* entryAddr      = */ (uint32)&Os_MultiCoreServer_Handler,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_MultiCommIsr_Core3, OS_ARCH_MULTICOMMISR_CORE3_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_MultiCommIsr_Core3)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_SWC_Init_Task_Core3 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_SWC_Init_Task_Core3_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_SWC_Init_Task_Core3,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_SWC_Init_Task_Core3, OS_ARCH_SWC_INIT_TASK_CORE3_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_SWC_Init_Task_Core3)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_UDS_Core3_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_UDS_Core3_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_UDS_Core3_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_UDS_Core3_QM, OS_ARCH_APP1_TASK_UDS_CORE3_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_UDS_Core3_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Task_1ms_Core3_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Task_1ms_Core3_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Task_1ms_Core3_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Task_1ms_Core3_QM, OS_ARCH_TASK_1MS_CORE3_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Task_1ms_Core3_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Task_100us_Core3_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Task_100us_Core3_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Task_100us_Core3_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Task_100us_Core3_QM, OS_ARCH_TASK_100US_CORE3_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Task_100us_Core3_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Task_5ms_Core3_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Task_5ms_Core3_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Task_5ms_Core3_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Task_5ms_Core3_QM, OS_ARCH_TASK_5MS_CORE3_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Task_5ms_Core3_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Kernal_OsCore4 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Kernal_OsCore4_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ 0U,
    /* exitAddr       = */ 0U,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Kernal_OsCore4, OS_ARCH_KERNAL_OSCORE4_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Kernal_OsCore4)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Default_Init_Task_Core4 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Default_Init_Task_Core4_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Default_Init_Task_Core4,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Default_Init_Task_Core4, OS_ARCH_DEFAULT_INIT_TASK_CORE4_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Default_Init_Task_Core4)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Idle_Task_Core4 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Idle_Task_Core4_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Idle_Task_Core4,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Idle_Task_Core4, OS_ARCH_IDLE_TASK_CORE4_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Idle_Task_Core4)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_CounterIsr_SystemTimer_Core4 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_CounterIsr_SystemTimer_Core4_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL4,
    /* entryAddr      = */ (uint32)&OS_PIT,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_CounterIsr_SystemTimer_Core4, OS_ARCH_COUNTERISR_SYSTEMTIMER_CORE4_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_CounterIsr_SystemTimer_Core4)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_MultiCommIsr_Core4 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_MultiCommIsr_Core4_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL1,
    /* entryAddr      = */ (uint32)&Os_MultiCoreServer_Handler,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_MultiCommIsr_Core4, OS_ARCH_MULTICOMMISR_CORE4_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_MultiCommIsr_Core4)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_1ms_Core4_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_1ms_Core4_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_1ms_Core4_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_1ms_Core4_QM, OS_ARCH_APP1_TASK_1MS_CORE4_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_1ms_Core4_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_5ms_Core4_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_5ms_Core4_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_5ms_Core4_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_5ms_Core4_QM, OS_ARCH_APP1_TASK_5MS_CORE4_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_5ms_Core4_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_10ms_Core4_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_10ms_Core4_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_10ms_Core4_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_10ms_Core4_QM, OS_ARCH_APP1_TASK_10MS_CORE4_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_10ms_Core4_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_20ms_Core4_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_20ms_Core4_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_20ms_Core4_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_20ms_Core4_QM, OS_ARCH_APP1_TASK_20MS_CORE4_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_20ms_Core4_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_50ms_Core4_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_50ms_Core4_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_50ms_Core4_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_50ms_Core4_QM, OS_ARCH_APP1_TASK_50MS_CORE4_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_50ms_Core4_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_100ms_Core4_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_100ms_Core4_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_100ms_Core4_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_100ms_Core4_QM, OS_ARCH_APP1_TASK_100MS_CORE4_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_100ms_Core4_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_SWC_Init_Task_Core4 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_SWC_Init_Task_Core4_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_SWC_Init_Task_Core4,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_SWC_Init_Task_Core4, OS_ARCH_SWC_INIT_TASK_CORE4_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_SWC_Init_Task_Core4)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_UDS_Core4_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_UDS_Core4_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_UDS_Core4_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_UDS_Core4_QM, OS_ARCH_APP1_TASK_UDS_CORE4_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_UDS_Core4_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_100ms_Core4_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Bsw_Task_100ms_Core4_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Bsw_Task_100ms_Core4_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Bsw_Task_100ms_Core4_QM, OS_ARCH_BSW_TASK_100MS_CORE4_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Bsw_Task_100ms_Core4_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_50ms_Core4_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Bsw_Task_50ms_Core4_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Bsw_Task_50ms_Core4_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Bsw_Task_50ms_Core4_QM, OS_ARCH_BSW_TASK_50MS_CORE4_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Bsw_Task_50ms_Core4_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_20ms_Core4_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Bsw_Task_20ms_Core4_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Bsw_Task_20ms_Core4_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Bsw_Task_20ms_Core4_QM, OS_ARCH_BSW_TASK_20MS_CORE4_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Bsw_Task_20ms_Core4_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_10ms_Core4_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Bsw_Task_10ms_Core4_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Bsw_Task_10ms_Core4_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Bsw_Task_10ms_Core4_QM, OS_ARCH_BSW_TASK_10MS_CORE4_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Bsw_Task_10ms_Core4_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_5ms_Core4_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Bsw_Task_5ms_Core4_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Bsw_Task_5ms_Core4_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Bsw_Task_5ms_Core4_QM, OS_ARCH_BSW_TASK_5MS_CORE4_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Bsw_Task_5ms_Core4_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_1ms_Core4_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Bsw_Task_1ms_Core4_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Bsw_Task_1ms_Core4_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Bsw_Task_1ms_Core4_QM, OS_ARCH_BSW_TASK_1MS_CORE4_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Bsw_Task_1ms_Core4_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_5ms_Core4_Offest_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Bsw_Task_5ms_Core4_Offest_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Bsw_Task_5ms_Core4_Offest_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Bsw_Task_5ms_Core4_Offest_QM, OS_ARCH_BSW_TASK_5MS_CORE4_OFFEST_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Bsw_Task_5ms_Core4_Offest_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_10ms_Core4_Offest_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Bsw_Task_10ms_Core4_Offest_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Bsw_Task_10ms_Core4_Offest_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Bsw_Task_10ms_Core4_Offest_QM, OS_ARCH_BSW_TASK_10MS_CORE4_OFFEST_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Bsw_Task_10ms_Core4_Offest_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_450_MCAN11_CH1 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Os_ISR_450_MCAN11_CH1_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL30,
    /* entryAddr      = */ (uint32)&ISR_M_CAN11_1,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Os_ISR_450_MCAN11_CH1, OS_ARCH_OS_ISR_450_MCAN11_CH1_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Os_ISR_450_MCAN11_CH1)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_449_MCAN11_CH0 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Os_ISR_449_MCAN11_CH0_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL30,
    /* entryAddr      = */ (uint32)&ISR_M_CAN11_0,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Os_ISR_449_MCAN11_CH0, OS_ARCH_OS_ISR_449_MCAN11_CH0_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Os_ISR_449_MCAN11_CH0)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_699_MCAN6_CH1 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Os_ISR_699_MCAN6_CH1_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL30,
    /* entryAddr      = */ (uint32)&ISR_M_CAN6_1,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Os_ISR_699_MCAN6_CH1, OS_ARCH_OS_ISR_699_MCAN6_CH1_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Os_ISR_699_MCAN6_CH1)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_698_MCAN6_CH0 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Os_ISR_698_MCAN6_CH0_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL30,
    /* entryAddr      = */ (uint32)&ISR_M_CAN6_0,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Os_ISR_698_MCAN6_CH0, OS_ARCH_OS_ISR_698_MCAN6_CH0_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Os_ISR_698_MCAN6_CH0)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_689_MCAN1_CH1 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Os_ISR_689_MCAN1_CH1_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL30,
    /* entryAddr      = */ (uint32)&ISR_M_CAN1_1,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Os_ISR_689_MCAN1_CH1, OS_ARCH_OS_ISR_689_MCAN1_CH1_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Os_ISR_689_MCAN1_CH1)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_688_MCAN1_CH0 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Os_ISR_688_MCAN1_CH0_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL30,
    /* entryAddr      = */ (uint32)&ISR_M_CAN1_0,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Os_ISR_688_MCAN1_CH0, OS_ARCH_OS_ISR_688_MCAN1_CH0_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Os_ISR_688_MCAN1_CH0)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_446_MCAN9_CH1 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Os_ISR_446_MCAN9_CH1_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL30,
    /* entryAddr      = */ (uint32)&ISR_M_CAN9_1,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Os_ISR_446_MCAN9_CH1, OS_ARCH_OS_ISR_446_MCAN9_CH1_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Os_ISR_446_MCAN9_CH1)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_445_MCAN9_CH0 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Os_ISR_445_MCAN9_CH0_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL30,
    /* entryAddr      = */ (uint32)&ISR_M_CAN9_0,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Os_ISR_445_MCAN9_CH0, OS_ARCH_OS_ISR_445_MCAN9_CH0_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Os_ISR_445_MCAN9_CH0)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_693_MCAN3_CH1 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Os_ISR_693_MCAN3_CH1_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL30,
    /* entryAddr      = */ (uint32)&ISR_M_CAN3_1,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Os_ISR_693_MCAN3_CH1, OS_ARCH_OS_ISR_693_MCAN3_CH1_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Os_ISR_693_MCAN3_CH1)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_692_MCAN3_CH0 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Os_ISR_692_MCAN3_CH0_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL30,
    /* entryAddr      = */ (uint32)&ISR_M_CAN3_0,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Os_ISR_692_MCAN3_CH0, OS_ARCH_OS_ISR_692_MCAN3_CH0_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Os_ISR_692_MCAN3_CH0)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_691_MCAN2_CH1 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Os_ISR_691_MCAN2_CH1_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL30,
    /* entryAddr      = */ (uint32)&ISR_M_CAN2_1,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Os_ISR_691_MCAN2_CH1, OS_ARCH_OS_ISR_691_MCAN2_CH1_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Os_ISR_691_MCAN2_CH1)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_690_MCAN2_CH0 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Os_ISR_690_MCAN2_CH0_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL30,
    /* entryAddr      = */ (uint32)&ISR_M_CAN2_0,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Os_ISR_690_MCAN2_CH0, OS_ARCH_OS_ISR_690_MCAN2_CH0_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Os_ISR_690_MCAN2_CH0)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_701_MCAN7_CH1 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Os_ISR_701_MCAN7_CH1_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL30,
    /* entryAddr      = */ (uint32)&ISR_M_CAN7_1,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Os_ISR_701_MCAN7_CH1, OS_ARCH_OS_ISR_701_MCAN7_CH1_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Os_ISR_701_MCAN7_CH1)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_700_MCAN7_CH0 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Os_ISR_700_MCAN7_CH0_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL30,
    /* entryAddr      = */ (uint32)&ISR_M_CAN7_0,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Os_ISR_700_MCAN7_CH0, OS_ARCH_OS_ISR_700_MCAN7_CH0_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Os_ISR_700_MCAN7_CH0)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_698_LINTX_CH6 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Os_ISR_698_LINTX_CH6_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL15,
    /* entryAddr      = */ (uint32)&LINFLEX6_LLD_TXI_IRQ_HANDLER,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Os_ISR_698_LINTX_CH6, OS_ARCH_OS_ISR_698_LINTX_CH6_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Os_ISR_698_LINTX_CH6)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_698_LINRX_CH6 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Os_ISR_698_LINRX_CH6_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL15,
    /* entryAddr      = */ (uint32)&LINFLEX6_LLD_RXI_IRQ_HANDLER,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Os_ISR_698_LINRX_CH6, OS_ARCH_OS_ISR_698_LINRX_CH6_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Os_ISR_698_LINRX_CH6)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Kernal_OsCore5 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Kernal_OsCore5_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ 0U,
    /* exitAddr       = */ 0U,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Kernal_OsCore5, OS_ARCH_KERNAL_OSCORE5_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Kernal_OsCore5)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Default_Init_Task_Core5 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Default_Init_Task_Core5_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Default_Init_Task_Core5,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Default_Init_Task_Core5, OS_ARCH_DEFAULT_INIT_TASK_CORE5_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Default_Init_Task_Core5)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Idle_Task_Core5 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Idle_Task_Core5_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Idle_Task_Core5,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Idle_Task_Core5, OS_ARCH_IDLE_TASK_CORE5_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Idle_Task_Core5)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_CounterIsr_SystemTimer_Core5 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_CounterIsr_SystemTimer_Core5_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL4,
    /* entryAddr      = */ (uint32)&OS_PIT,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_CounterIsr_SystemTimer_Core5, OS_ARCH_COUNTERISR_SYSTEMTIMER_CORE5_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_CounterIsr_SystemTimer_Core5)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_MultiCommIsr_Core5 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_MultiCommIsr_Core5_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_ISR_LEVEL1,
    /* entryAddr      = */ (uint32)&Os_MultiCoreServer_Handler,
    /* exitAddr       = */ (uint32)&Os_Isr_Exit,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_MultiCommIsr_Core5, OS_ARCH_MULTICOMMISR_CORE5_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_MultiCommIsr_Core5)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_1ms_Core5_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_1ms_Core5_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_1ms_Core5_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_1ms_Core5_QM, OS_ARCH_APP1_TASK_1MS_CORE5_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_1ms_Core5_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_5ms_Core5_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_5ms_Core5_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_5ms_Core5_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_5ms_Core5_QM, OS_ARCH_APP1_TASK_5MS_CORE5_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_5ms_Core5_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_10ms_Core5_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_10ms_Core5_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_10ms_Core5_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_10ms_Core5_QM, OS_ARCH_APP1_TASK_10MS_CORE5_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_10ms_Core5_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_20ms_Core5_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_20ms_Core5_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_20ms_Core5_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_20ms_Core5_QM, OS_ARCH_APP1_TASK_20MS_CORE5_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_20ms_Core5_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_50ms_Core5_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_50ms_Core5_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_50ms_Core5_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_50ms_Core5_QM, OS_ARCH_APP1_TASK_50MS_CORE5_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_50ms_Core5_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_100ms_Core5_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_100ms_Core5_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_100ms_Core5_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_100ms_Core5_QM, OS_ARCH_APP1_TASK_100MS_CORE5_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_100ms_Core5_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_SWC_Init_Task_Core5 =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_SWC_Init_Task_Core5_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_SWC_Init_Task_Core5,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_SWC_Init_Task_Core5, OS_ARCH_SWC_INIT_TASK_CORE5_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_SWC_Init_Task_Core5)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_UDS_Core5_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_UDS_Core5_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_UDS_Core5_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_UDS_Core5_QM, OS_ARCH_APP1_TASK_UDS_CORE5_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_UDS_Core5_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_200ms_Core5_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_200ms_Core5_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_200ms_Core5_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_200ms_Core5_QM, OS_ARCH_APP1_TASK_200MS_CORE5_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_200ms_Core5_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_500ms_Core5_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_500ms_Core5_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_500ms_Core5_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_500ms_Core5_QM, OS_ARCH_APP1_TASK_500MS_CORE5_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_500ms_Core5_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_1000ms_Core5_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_App1_Task_1000ms_Core5_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_App1_Task_1000ms_Core5_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_App1_Task_1000ms_Core5_QM, OS_ARCH_APP1_TASK_1000MS_CORE5_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_App1_Task_1000ms_Core5_QM)
};

const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_10ms_Core5_QM =
{
    /* contextDyn     = */ &OsCfg_Arch_Context_Bsw_Task_10ms_Core5_QM_Dyn,
    /* msr            = */ OS_INITIAL_MSR,
    /* cpr            = */ OS_INITIAL_CPR,
    /* entryAddr      = */ (uint32)&Os_Task_Bsw_Task_10ms_Core5_QM,
    /* exitAddr       = */ (uint32)&Os_Task_WrongReturn,
    /* stackStartAddr = */ OS_GET_STACK_TOP(OsCfg_Arch_Stack_Bsw_Task_10ms_Core5_QM, OS_ARCH_BSW_TASK_10MS_CORE5_QM_STACK_SIZE),
    /* stackEndAddr   = */ OS_GET_STACK_BOTTOM(OsCfg_Arch_Stack_Bsw_Task_10ms_Core5_QM)
};

const Os_Arch_Mach_TimerPitCfgType OsCfg_Arch_TimerPit_SystemTimer_Core0 =
{
    /* TimerPitBaseAdress = */ OS_HAL_PIT0_BASE_ADDRESS,
    /* TimerPitChannel    = */ 0U,
    /* ReloadValue        = */ 100000U,
};

const Os_Arch_Mach_TimerPitCfgType OsCfg_Arch_TimerPit_SystemTimer_Core1 =
{
    /* TimerPitBaseAdress = */ OS_HAL_PIT0_BASE_ADDRESS,
    /* TimerPitChannel    = */ 1U,
    /* ReloadValue        = */ 100000U,
};

const Os_Arch_Mach_TimerPitCfgType OsCfg_Arch_TimerPit_SystemTimer_Core2 =
{
    /* TimerPitBaseAdress = */ OS_HAL_PIT0_BASE_ADDRESS,
    /* TimerPitChannel    = */ 2U,
    /* ReloadValue        = */ 100000U,
};

const Os_Arch_Mach_TimerPitCfgType OsCfg_Arch_TimerPit_SystemTimer_Core3 =
{
    /* TimerPitBaseAdress = */ OS_HAL_PIT0_BASE_ADDRESS,
    /* TimerPitChannel    = */ 3U,
    /* ReloadValue        = */ 100000U,
};

const Os_Arch_Mach_TimerPitCfgType OsCfg_Arch_TimerPit_SystemTimer_Core4 =
{
    /* TimerPitBaseAdress = */ OS_HAL_PIT0_BASE_ADDRESS,
    /* TimerPitChannel    = */ 4U,
    /* ReloadValue        = */ 100000U,
};

const Os_Arch_Mach_TimerPitCfgType OsCfg_Arch_TimerPit_SystemTimer_Core5 =
{
    /* TimerPitBaseAdress = */ OS_HAL_PIT0_BASE_ADDRESS,
    /* TimerPitChannel    = */ 5U,
    /* ReloadValue        = */ 100000U,
};

const Os_Arch_Mach_TimerHrtCfgType OsCfg_Arch_TimerHrt_Os_Monitor_Counter =
{
    /* TimerSmtBaseAddress = */ OS_HAL_STM0_BASE_ADDRESS,
    /* TimerSmtChannel     = */ 1U,
    /* Source              = */ &OsCfg_Arch_Source_Os_ISR_37_STM0_CH1
};

const Os_Arch_IsrSourceType OsCfg_Arch_Source_CounterIsr_SystemTimer_Core0 =
{
    /* number = */ 226U,
    /* level  = */ OS_ISR_LEVEL4
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_MultiCommIsr_Core0 =
{
    /* number = */ 0U,
    /* level  = */ OS_ISR_LEVEL1
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_37_STM0_CH1 =
{
    /* number = */ 37U,
    /* level  = */ OS_ISR_LEVEL20
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_CounterIsr_SystemTimer_Core1 =
{
    /* number = */ 227U,
    /* level  = */ OS_ISR_LEVEL4
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_MultiCommIsr_Core1 =
{
    /* number = */ 1U,
    /* level  = */ OS_ISR_LEVEL1
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_CounterIsr_SystemTimer_Core2 =
{
    /* number = */ 228U,
    /* level  = */ OS_ISR_LEVEL4
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_MultiCommIsr_Core2 =
{
    /* number = */ 2U,
    /* level  = */ OS_ISR_LEVEL1
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_CounterIsr_SystemTimer_Core3 =
{
    /* number = */ 229U,
    /* level  = */ OS_ISR_LEVEL4
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_MultiCommIsr_Core3 =
{
    /* number = */ 3U,
    /* level  = */ OS_ISR_LEVEL1
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_612_TIM6_CH6 =
{
    /* number = */ 612U,
    /* level  = */ OS_ISR_LEVEL55
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_777_TIM3_CH4 =
{
    /* number = */ 777U,
    /* level  = */ OS_ISR_LEVEL53
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_776_TIM3_CH3 =
{
    /* number = */ 776U,
    /* level  = */ OS_ISR_LEVEL54
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_775_TIM3_CH2 =
{
    /* number = */ 775U,
    /* level  = */ OS_ISR_LEVEL56
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_613_TIM6_CH5 =
{
    /* number = */ 613U,
    /* level  = */ OS_ISR_LEVEL58
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_614_TIM6_CH4 =
{
    /* number = */ 614U,
    /* level  = */ OS_ISR_LEVEL59
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_615_TIM6_CH3 =
{
    /* number = */ 615U,
    /* level  = */ OS_ISR_LEVEL60
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_616_TIM6_CH2 =
{
    /* number = */ 616U,
    /* level  = */ OS_ISR_LEVEL61
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_617_TIM6_CH1 =
{
    /* number = */ 617U,
    /* level  = */ OS_ISR_LEVEL62
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_618_TIM6_CH0 =
{
    /* number = */ 618U,
    /* level  = */ OS_ISR_LEVEL57
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_867_TIM4_CH0 =
{
    /* number = */ 867U,
    /* level  = */ OS_ISR_LEVEL63
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_840_ATOM0_CH3 =
{
    /* number = */ 840U,
    /* level  = */ OS_ISR_LEVEL49
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_874_TIM4_CH7 =
{
    /* number = */ 874U,
    /* level  = */ OS_ISR_LEVEL45
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_CounterIsr_SystemTimer_Core4 =
{
    /* number = */ 230U,
    /* level  = */ OS_ISR_LEVEL4
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_MultiCommIsr_Core4 =
{
    /* number = */ 4U,
    /* level  = */ OS_ISR_LEVEL1
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_450_MCAN11_CH1 =
{
    /* number = */ 450U,
    /* level  = */ OS_ISR_LEVEL30
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_449_MCAN11_CH0 =
{
    /* number = */ 449U,
    /* level  = */ OS_ISR_LEVEL30
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_699_MCAN6_CH1 =
{
    /* number = */ 699U,
    /* level  = */ OS_ISR_LEVEL30
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_698_MCAN6_CH0 =
{
    /* number = */ 698U,
    /* level  = */ OS_ISR_LEVEL30
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_689_MCAN1_CH1 =
{
    /* number = */ 689U,
    /* level  = */ OS_ISR_LEVEL30
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_688_MCAN1_CH0 =
{
    /* number = */ 688U,
    /* level  = */ OS_ISR_LEVEL30
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_446_MCAN9_CH1 =
{
    /* number = */ 446U,
    /* level  = */ OS_ISR_LEVEL30
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_445_MCAN9_CH0 =
{
    /* number = */ 445U,
    /* level  = */ OS_ISR_LEVEL30
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_693_MCAN3_CH1 =
{
    /* number = */ 693U,
    /* level  = */ OS_ISR_LEVEL30
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_692_MCAN3_CH0 =
{
    /* number = */ 692U,
    /* level  = */ OS_ISR_LEVEL30
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_691_MCAN2_CH1 =
{
    /* number = */ 691U,
    /* level  = */ OS_ISR_LEVEL30
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_690_MCAN2_CH0 =
{
    /* number = */ 690U,
    /* level  = */ OS_ISR_LEVEL30
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_701_MCAN7_CH1 =
{
    /* number = */ 701U,
    /* level  = */ OS_ISR_LEVEL30
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_700_MCAN7_CH0 =
{
    /* number = */ 700U,
    /* level  = */ OS_ISR_LEVEL30
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_698_LINTX_CH6 =
{
    /* number = */ 439U,
    /* level  = */ OS_ISR_LEVEL15
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_698_LINRX_CH6 =
{
    /* number = */ 435U,
    /* level  = */ OS_ISR_LEVEL15
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_CounterIsr_SystemTimer_Core5 =
{
    /* number = */ 231U,
    /* level  = */ OS_ISR_LEVEL4
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_MultiCommIsr_Core5 =
{
    /* number = */ 5U,
    /* level  = */ OS_ISR_LEVEL1
};
const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_117_DMA1_CH0 =
{
    /* number = */ 117U,
    /* level  = */ OS_ISR_LEVEL60
};
const Os_Arch_IsrMaskLevelType OsCfg_Arch_IsrMaskLevel_OsCore0 =
{
    /* Cat1MaskLevel       */ OS_ISR_LEVEL20,
    /* Cat2MaskLevel       */ OS_ISR_LEVEL20,
    /* IntDisableMaskLevel */ OS_ISR_LEVEL20
};
const Os_Arch_IsrMaskLevelType OsCfg_Arch_IsrMaskLevel_OsCore1 =
{
    /* Cat1MaskLevel       */ OS_ISR_LEVEL4,
    /* Cat2MaskLevel       */ OS_ISR_LEVEL4,
    /* IntDisableMaskLevel */ OS_ISR_LEVEL4
};
const Os_Arch_IsrMaskLevelType OsCfg_Arch_IsrMaskLevel_OsCore2 =
{
    /* Cat1MaskLevel       */ OS_ISR_LEVEL4,
    /* Cat2MaskLevel       */ OS_ISR_LEVEL4,
    /* IntDisableMaskLevel */ OS_ISR_LEVEL4
};
const Os_Arch_IsrMaskLevelType OsCfg_Arch_IsrMaskLevel_OsCore3 =
{
    /* Cat1MaskLevel       */ OS_ISR_LEVEL45,
    /* Cat2MaskLevel       */ OS_ISR_LEVEL4,
    /* IntDisableMaskLevel */ OS_ISR_LEVEL4
};
const Os_Arch_IsrMaskLevelType OsCfg_Arch_IsrMaskLevel_OsCore4 =
{
    /* Cat1MaskLevel       */ OS_ISR_LEVEL30,
    /* Cat2MaskLevel       */ OS_ISR_LEVEL30,
    /* IntDisableMaskLevel */ OS_ISR_LEVEL30
};
const Os_Arch_IsrMaskLevelType OsCfg_Arch_IsrMaskLevel_OsCore5 =
{
    /* Cat1MaskLevel       */ OS_ISR_LEVEL60,
    /* Cat2MaskLevel       */ OS_ISR_LEVEL4,
    /* IntDisableMaskLevel */ OS_ISR_LEVEL4
};
const Os_Arch_IsrMaskLevelType* const OsCfg_Arch_IsrMaskLevel[OS_COREID_COUNT + 1] =
{
    &OsCfg_Arch_IsrMaskLevel_OsCore0,
    &OsCfg_Arch_IsrMaskLevel_OsCore1,
    &OsCfg_Arch_IsrMaskLevel_OsCore2,
    &OsCfg_Arch_IsrMaskLevel_OsCore3,
    &OsCfg_Arch_IsrMaskLevel_OsCore4,
    &OsCfg_Arch_IsrMaskLevel_OsCore5,
    NULL_PTR
};
#define OS_STOP_SEC_CONST 
#include "Os_MemMap.h"
