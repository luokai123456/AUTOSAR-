/*
********************************************************************************
*
*  File name: Os_Arch_Kernal_Lcfg.h
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
#ifndef OS_ARCH_KERNAL_LCFG_H_
#define OS_ARCH_KERNAL_LCFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Isr_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define OS_ARCH_PHYSICAL_CORE_NUM                     (6U)

#define OS_ARCH_KERNAL_OSCORE0_STACK_SIZE             (1024U)
#define OS_ARCH_DEFAULT_INIT_TASK_CORE0_STACK_SIZE    (1024U)
#define OS_ARCH_IDLE_TASK_CORE0_STACK_SIZE            (1024U)
#define OS_ARCH_COUNTERISR_SYSTEMTIMER_CORE0_STACK_SIZE (1024U)
#define OS_ARCH_MULTICOMMISR_CORE0_STACK_SIZE         (1024U)
#define OS_ARCH_APP1_TASK_1MS_CORE0_QM_STACK_SIZE     (4096U)
#define OS_ARCH_APP1_TASK_5MS_CORE0_QM_STACK_SIZE     (4096U)
#define OS_ARCH_APP1_TASK_10MS_CORE0_QM_STACK_SIZE    (4096U)
#define OS_ARCH_APP1_TASK_20MS_CORE0_QM_STACK_SIZE    (4096U)
#define OS_ARCH_APP1_TASK_50MS_CORE0_QM_STACK_SIZE    (4096U)
#define OS_ARCH_APP1_TASK_100MS_CORE0_QM_STACK_SIZE   (4096U)
#define OS_ARCH_SWC_INIT_TASK_CORE0_STACK_SIZE        (1024U)
#define OS_ARCH_BSW_TASK_10MS_CORE0_QM_STACK_SIZE     (4096U)
#define OS_ARCH_BSW_TASK_5MS_CORE0_QM_STACK_SIZE      (4096U)
#define OS_ARCH_OS_ISR_37_STM0_CH1_STACK_SIZE         (1024U)

#define OS_ARCH_KERNAL_OSCORE1_STACK_SIZE             (1024U)
#define OS_ARCH_DEFAULT_INIT_TASK_CORE1_STACK_SIZE    (1024U)
#define OS_ARCH_IDLE_TASK_CORE1_STACK_SIZE            (1024U)
#define OS_ARCH_COUNTERISR_SYSTEMTIMER_CORE1_STACK_SIZE (1024U)
#define OS_ARCH_MULTICOMMISR_CORE1_STACK_SIZE         (1024U)
#define OS_ARCH_APP1_TASK_10MS_CORE1_QM_STACK_SIZE    (4096U)
#define OS_ARCH_SWC_INIT_TASK_CORE1_STACK_SIZE        (1024U)
#define OS_ARCH_APP1_TASK_1MS_CORE1_QM_STACK_SIZE     (4096U)
#define OS_ARCH_APP1_TASK_5MS_CORE1_QM_STACK_SIZE     (4096U)
#define OS_ARCH_APP1_TASK_20MS_CORE1_QM_STACK_SIZE    (4096U)
#define OS_ARCH_APP1_TASK_50MS_CORE1_QM_STACK_SIZE    (4096U)
#define OS_ARCH_APP1_TASK_100MS_CORE1_QM_STACK_SIZE   (4096U)
#define OS_ARCH_APP1_TASK_UDS_CORE1_QM_STACK_SIZE     (1024U)
#define OS_ARCH_BSW_TASK_10MS_CORE1_QM_STACK_SIZE     (4096U)

#define OS_ARCH_KERNAL_OSCORE2_STACK_SIZE             (1024U)
#define OS_ARCH_DEFAULT_INIT_TASK_CORE2_STACK_SIZE    (1024U)
#define OS_ARCH_IDLE_TASK_CORE2_STACK_SIZE            (1024U)
#define OS_ARCH_COUNTERISR_SYSTEMTIMER_CORE2_STACK_SIZE (1024U)
#define OS_ARCH_MULTICOMMISR_CORE2_STACK_SIZE         (1024U)
#define OS_ARCH_APP1_TASK_50MS_CORE2_QM_STACK_SIZE    (4096U)
#define OS_ARCH_APP1_TASK_100MS_CORE2_QM_STACK_SIZE   (9012U)
#define OS_ARCH_APP1_TASK_10MS_CORE2_QM_STACK_SIZE    (4096U)
#define OS_ARCH_APP1_TASK_1000MS_CORE2_QM_STACK_SIZE  (4096U)
#define OS_ARCH_SWC_INIT_TASK_CORE2_STACK_SIZE        (1024U)
#define OS_ARCH_APP1_TASK_1MS_CORE2_QM_STACK_SIZE     (4096U)
#define OS_ARCH_APP1_TASK_5MS_CORE2_QM_STACK_SIZE     (4096U)
#define OS_ARCH_APP1_TASK_20MS_CORE2_QM_STACK_SIZE    (4096U)
#define OS_ARCH_APP1_TASK0_UDS_CORE2_QM_STACK_SIZE    (1024U)
#define OS_ARCH_APP1_TASK1_UDS_CORE2_QM_STACK_SIZE    (1024U)
#define OS_ARCH_APP1_TASK2_UDS_CORE2_QM_STACK_SIZE    (1024U)
#define OS_ARCH_BSW_TASK_10MS_CORE2_QM_STACK_SIZE     (4096U)

#define OS_ARCH_KERNAL_OSCORE3_STACK_SIZE             (1024U)
#define OS_ARCH_DEFAULT_INIT_TASK_CORE3_STACK_SIZE    (1024U)
#define OS_ARCH_IDLE_TASK_CORE3_STACK_SIZE            (1024U)
#define OS_ARCH_COUNTERISR_SYSTEMTIMER_CORE3_STACK_SIZE (1024U)
#define OS_ARCH_MULTICOMMISR_CORE3_STACK_SIZE         (1024U)
#define OS_ARCH_SWC_INIT_TASK_CORE3_STACK_SIZE        (1024U)
#define OS_ARCH_APP1_TASK_UDS_CORE3_QM_STACK_SIZE     (1024U)
#define OS_ARCH_TASK_1MS_CORE3_QM_STACK_SIZE          (4096U)
#define OS_ARCH_TASK_100US_CORE3_QM_STACK_SIZE        (4096U)
#define OS_ARCH_TASK_5MS_CORE3_QM_STACK_SIZE          (1024U)

#define OS_ARCH_KERNAL_OSCORE4_STACK_SIZE             (1024U)
#define OS_ARCH_DEFAULT_INIT_TASK_CORE4_STACK_SIZE    (1024U)
#define OS_ARCH_IDLE_TASK_CORE4_STACK_SIZE            (1024U)
#define OS_ARCH_COUNTERISR_SYSTEMTIMER_CORE4_STACK_SIZE (1024U)
#define OS_ARCH_MULTICOMMISR_CORE4_STACK_SIZE         (1024U)
#define OS_ARCH_APP1_TASK_1MS_CORE4_QM_STACK_SIZE     (4096U)
#define OS_ARCH_APP1_TASK_5MS_CORE4_QM_STACK_SIZE     (4096U)
#define OS_ARCH_APP1_TASK_10MS_CORE4_QM_STACK_SIZE    (4096U)
#define OS_ARCH_APP1_TASK_20MS_CORE4_QM_STACK_SIZE    (4096U)
#define OS_ARCH_APP1_TASK_50MS_CORE4_QM_STACK_SIZE    (4096U)
#define OS_ARCH_APP1_TASK_100MS_CORE4_QM_STACK_SIZE   (4096U)
#define OS_ARCH_SWC_INIT_TASK_CORE4_STACK_SIZE        (1024U)
#define OS_ARCH_APP1_TASK_UDS_CORE4_QM_STACK_SIZE     (1024U)
#define OS_ARCH_BSW_TASK_100MS_CORE4_QM_STACK_SIZE    (1024U)
#define OS_ARCH_BSW_TASK_50MS_CORE4_QM_STACK_SIZE     (1024U)
#define OS_ARCH_BSW_TASK_20MS_CORE4_QM_STACK_SIZE     (1024U)
#define OS_ARCH_BSW_TASK_10MS_CORE4_QM_STACK_SIZE     (4096U)
#define OS_ARCH_BSW_TASK_5MS_CORE4_QM_STACK_SIZE      (2048U)
#define OS_ARCH_BSW_TASK_1MS_CORE4_QM_STACK_SIZE      (1024U)
#define OS_ARCH_BSW_TASK_5MS_CORE4_OFFEST_QM_STACK_SIZE (2048U)
#define OS_ARCH_BSW_TASK_10MS_CORE4_OFFEST_QM_STACK_SIZE (4096U)
#define OS_ARCH_OS_ISR_450_MCAN11_CH1_STACK_SIZE      (1024U)
#define OS_ARCH_OS_ISR_449_MCAN11_CH0_STACK_SIZE      (4096U)
#define OS_ARCH_OS_ISR_699_MCAN6_CH1_STACK_SIZE       (1024U)
#define OS_ARCH_OS_ISR_698_MCAN6_CH0_STACK_SIZE       (4096U)
#define OS_ARCH_OS_ISR_689_MCAN1_CH1_STACK_SIZE       (1024U)
#define OS_ARCH_OS_ISR_688_MCAN1_CH0_STACK_SIZE       (4096U)
#define OS_ARCH_OS_ISR_446_MCAN9_CH1_STACK_SIZE       (1024U)
#define OS_ARCH_OS_ISR_445_MCAN9_CH0_STACK_SIZE       (4096U)
#define OS_ARCH_OS_ISR_693_MCAN3_CH1_STACK_SIZE       (1024U)
#define OS_ARCH_OS_ISR_692_MCAN3_CH0_STACK_SIZE       (4096U)
#define OS_ARCH_OS_ISR_691_MCAN2_CH1_STACK_SIZE       (1024U)
#define OS_ARCH_OS_ISR_690_MCAN2_CH0_STACK_SIZE       (4096U)
#define OS_ARCH_OS_ISR_701_MCAN7_CH1_STACK_SIZE       (1024U)
#define OS_ARCH_OS_ISR_700_MCAN7_CH0_STACK_SIZE       (4096U)
#define OS_ARCH_OS_ISR_698_LINTX_CH6_STACK_SIZE       (2048U)
#define OS_ARCH_OS_ISR_698_LINRX_CH6_STACK_SIZE       (2048U)

#define OS_ARCH_KERNAL_OSCORE5_STACK_SIZE             (1024U)
#define OS_ARCH_DEFAULT_INIT_TASK_CORE5_STACK_SIZE    (1024U)
#define OS_ARCH_IDLE_TASK_CORE5_STACK_SIZE            (1024U)
#define OS_ARCH_COUNTERISR_SYSTEMTIMER_CORE5_STACK_SIZE (1024U)
#define OS_ARCH_MULTICOMMISR_CORE5_STACK_SIZE         (1024U)
#define OS_ARCH_APP1_TASK_1MS_CORE5_QM_STACK_SIZE     (4096U)
#define OS_ARCH_APP1_TASK_5MS_CORE5_QM_STACK_SIZE     (4096U)
#define OS_ARCH_APP1_TASK_10MS_CORE5_QM_STACK_SIZE    (4096U)
#define OS_ARCH_APP1_TASK_20MS_CORE5_QM_STACK_SIZE    (4096U)
#define OS_ARCH_APP1_TASK_50MS_CORE5_QM_STACK_SIZE    (4096U)
#define OS_ARCH_APP1_TASK_100MS_CORE5_QM_STACK_SIZE   (4096U)
#define OS_ARCH_SWC_INIT_TASK_CORE5_STACK_SIZE        (1024U)
#define OS_ARCH_APP1_TASK_UDS_CORE5_QM_STACK_SIZE     (1024U)
#define OS_ARCH_APP1_TASK_200MS_CORE5_QM_STACK_SIZE   (4096U)
#define OS_ARCH_APP1_TASK_500MS_CORE5_QM_STACK_SIZE   (4096U)
#define OS_ARCH_APP1_TASK_1000MS_CORE5_QM_STACK_SIZE  (4096U)
#define OS_ARCH_BSW_TASK_10MS_CORE5_QM_STACK_SIZE     (4096U)

#define OS_ISR_LEVEL4                                 (4U)
#define OS_ISR_LEVEL1                                 (1U)
#define OS_ISR_LEVEL20                                (20U)
#define OS_ISR_LEVEL55                                (55U)
#define OS_ISR_LEVEL53                                (53U)
#define OS_ISR_LEVEL54                                (54U)
#define OS_ISR_LEVEL56                                (56U)
#define OS_ISR_LEVEL58                                (58U)
#define OS_ISR_LEVEL59                                (59U)
#define OS_ISR_LEVEL60                                (60U)
#define OS_ISR_LEVEL61                                (61U)
#define OS_ISR_LEVEL62                                (62U)
#define OS_ISR_LEVEL57                                (57U)
#define OS_ISR_LEVEL63                                (63U)
#define OS_ISR_LEVEL49                                (49U)
#define OS_ISR_LEVEL45                                (45U)
#define OS_ISR_LEVEL30                                (30U)
#define OS_ISR_LEVEL15                                (15U)

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
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Kernal_OsCore0;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Default_Init_Task_Core0;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Idle_Task_Core0;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_CounterIsr_SystemTimer_Core0;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_MultiCommIsr_Core0;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_1ms_Core0_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_5ms_Core0_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_10ms_Core0_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_20ms_Core0_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_50ms_Core0_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_100ms_Core0_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_SWC_Init_Task_Core0;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_10ms_Core0_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_5ms_Core0_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_37_STM0_CH1;

extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Kernal_OsCore1;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Default_Init_Task_Core1;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Idle_Task_Core1;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_CounterIsr_SystemTimer_Core1;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_MultiCommIsr_Core1;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_10ms_Core1_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_SWC_Init_Task_Core1;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_1ms_Core1_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_5ms_Core1_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_20ms_Core1_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_50ms_Core1_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_100ms_Core1_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_UDS_Core1_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_10ms_Core1_QM;

extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Kernal_OsCore2;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Default_Init_Task_Core2;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Idle_Task_Core2;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_CounterIsr_SystemTimer_Core2;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_MultiCommIsr_Core2;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_50ms_Core2_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_100ms_Core2_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_10ms_Core2_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_1000ms_Core2_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_SWC_Init_Task_Core2;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_1ms_Core2_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_5ms_Core2_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_20ms_Core2_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task0_UDS_Core2_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task1_UDS_Core2_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task2_UDS_Core2_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_10ms_Core2_QM;

extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Kernal_OsCore3;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Default_Init_Task_Core3;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Idle_Task_Core3;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_CounterIsr_SystemTimer_Core3;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_MultiCommIsr_Core3;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_SWC_Init_Task_Core3;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_UDS_Core3_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Task_1ms_Core3_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Task_100us_Core3_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Task_5ms_Core3_QM;

extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Kernal_OsCore4;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Default_Init_Task_Core4;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Idle_Task_Core4;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_CounterIsr_SystemTimer_Core4;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_MultiCommIsr_Core4;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_1ms_Core4_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_5ms_Core4_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_10ms_Core4_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_20ms_Core4_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_50ms_Core4_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_100ms_Core4_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_SWC_Init_Task_Core4;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_UDS_Core4_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_100ms_Core4_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_50ms_Core4_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_20ms_Core4_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_10ms_Core4_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_5ms_Core4_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_1ms_Core4_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_5ms_Core4_Offest_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_10ms_Core4_Offest_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_450_MCAN11_CH1;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_449_MCAN11_CH0;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_699_MCAN6_CH1;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_698_MCAN6_CH0;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_689_MCAN1_CH1;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_688_MCAN1_CH0;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_446_MCAN9_CH1;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_445_MCAN9_CH0;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_693_MCAN3_CH1;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_692_MCAN3_CH0;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_691_MCAN2_CH1;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_690_MCAN2_CH0;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_701_MCAN7_CH1;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_700_MCAN7_CH0;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_698_LINTX_CH6;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Os_ISR_698_LINRX_CH6;

extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Kernal_OsCore5;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Default_Init_Task_Core5;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Idle_Task_Core5;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_CounterIsr_SystemTimer_Core5;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_MultiCommIsr_Core5;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_1ms_Core5_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_5ms_Core5_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_10ms_Core5_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_20ms_Core5_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_50ms_Core5_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_100ms_Core5_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_SWC_Init_Task_Core5;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_UDS_Core5_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_200ms_Core5_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_500ms_Core5_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_App1_Task_1000ms_Core5_QM;
extern const Os_Arch_ContextCfgType OsCfg_Arch_Context_Bsw_Task_10ms_Core5_QM;

extern const Os_Arch_Mach_TimerPitCfgType OsCfg_Arch_TimerPit_SystemTimer_Core0;
extern const Os_Arch_Mach_TimerPitCfgType OsCfg_Arch_TimerPit_SystemTimer_Core1;
extern const Os_Arch_Mach_TimerPitCfgType OsCfg_Arch_TimerPit_SystemTimer_Core2;
extern const Os_Arch_Mach_TimerPitCfgType OsCfg_Arch_TimerPit_SystemTimer_Core3;
extern const Os_Arch_Mach_TimerPitCfgType OsCfg_Arch_TimerPit_SystemTimer_Core4;
extern const Os_Arch_Mach_TimerPitCfgType OsCfg_Arch_TimerPit_SystemTimer_Core5;
extern const Os_Arch_Mach_TimerHrtCfgType OsCfg_Arch_TimerHrt_Os_Monitor_Counter;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_CounterIsr_SystemTimer_Core0;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_MultiCommIsr_Core0;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_37_STM0_CH1;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_CounterIsr_SystemTimer_Core1;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_MultiCommIsr_Core1;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_CounterIsr_SystemTimer_Core2;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_MultiCommIsr_Core2;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_CounterIsr_SystemTimer_Core3;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_MultiCommIsr_Core3;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_612_TIM6_CH6;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_777_TIM3_CH4;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_776_TIM3_CH3;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_775_TIM3_CH2;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_613_TIM6_CH5;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_614_TIM6_CH4;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_615_TIM6_CH3;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_616_TIM6_CH2;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_617_TIM6_CH1;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_618_TIM6_CH0;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_867_TIM4_CH0;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_840_ATOM0_CH3;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_874_TIM4_CH7;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_CounterIsr_SystemTimer_Core4;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_MultiCommIsr_Core4;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_450_MCAN11_CH1;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_449_MCAN11_CH0;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_699_MCAN6_CH1;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_698_MCAN6_CH0;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_689_MCAN1_CH1;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_688_MCAN1_CH0;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_446_MCAN9_CH1;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_445_MCAN9_CH0;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_693_MCAN3_CH1;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_692_MCAN3_CH0;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_691_MCAN2_CH1;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_690_MCAN2_CH0;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_701_MCAN7_CH1;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_700_MCAN7_CH0;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_698_LINTX_CH6;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_698_LINRX_CH6;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_CounterIsr_SystemTimer_Core5;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_MultiCommIsr_Core5;
extern const Os_Arch_IsrSourceType OsCfg_Arch_Source_Os_ISR_117_DMA1_CH0;
extern const CoreIdType Os_Arch_CoreMappingTable[OS_ARCH_PHYSICAL_CORE_NUM];
extern const Os_Arch_IsrMaskLevelType* const OsCfg_Arch_IsrMaskLevel[OS_COREID_COUNT + 1];

#endif /* OS_ARCH_KERNAL_LCFG_H_ */

