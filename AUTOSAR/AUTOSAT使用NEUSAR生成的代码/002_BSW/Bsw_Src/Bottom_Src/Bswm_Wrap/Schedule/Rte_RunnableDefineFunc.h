/******************************************************************************
* 文件名称   : Rte_RunnableDefineFunc.h
* 作    者   : Sunxq
* 生成日期   : 2024-01-19
* 描    述   : RTE调度相关的可运行体头文件，声明各核各周期调度函数接口。
* 版    本   : V0.0
* 修改记录   :
*   2024-01-19 Sunxq 初始版本
******************************************************************************/


#ifndef RTE_RUNNABLE_H
#define RTE_RUNNABLE_H 

#include "Platform_Types.h"
#include "Std_Types.h"



#define  WdgM_Monitor0_Enable     0
#define  WdgM_Monitor1_Enable     0
#define  WdgM_Monitor2_Enable     0


FUNC(void, RTE_CODE) Core0_Runnable_InitTask(void);
FUNC(void, RTE_CODE) Core1_Runnable_InitTask(void);
FUNC(void, RTE_CODE) Core2_Runnable_InitTask(void);
FUNC(void, RTE_CODE) Core3_Runnable_InitTask(void);

FUNC(void, RTE_CODE) Core0_Runnable_IdleTask(void);
FUNC(void, RTE_CODE) Core1_Runnable_IdleTask(void);
FUNC(void, RTE_CODE) Core2_Runnable_IdleTask(void);
FUNC(void, RTE_CODE) Core3_Runnable_IdleTask(void);


FUNC(void, RTE_CODE) Core0_Runnable_App_100ms(void);
FUNC(void, RTE_CODE) Core0_Runnable_App_10ms(void);
FUNC(void, RTE_CODE) Core0_Runnable_App_20ms(void);
FUNC(void, RTE_CODE) Core0_Runnable_App_1ms(void);
FUNC(void, RTE_CODE) Core0_Runnable_App_50ms(void);
FUNC(void, RTE_CODE) Core0_Runnable_App_5ms(void);

FUNC(void, RTE_CODE) Core1_Runnable_App_100ms(void);
FUNC(void, RTE_CODE) Core1_Runnable_App_10ms(void);
FUNC(void, RTE_CODE) Core1_Runnable_App_20ms(void);
FUNC(void, RTE_CODE) Core1_Runnable_App_1ms(void);
FUNC(void, RTE_CODE) Core1_Runnable_App_50ms(void);
FUNC(void, RTE_CODE) Core1_Runnable_App_5ms(void);

FUNC(void, RTE_CODE) Core2_Runnable_App_100ms(void);
FUNC(void, RTE_CODE) Core2_Runnable_App_10ms(void);
FUNC(void, RTE_CODE) Core2_Runnable_App_20ms(void);
FUNC(void, RTE_CODE) Core2_Runnable_App_1ms(void);
FUNC(void, RTE_CODE) Core2_Runnable_App_50ms(void);
FUNC(void, RTE_CODE) Core2_Runnable_App_5ms(void);


FUNC(void, RTE_CODE) Core3_Runnable_App_100ms(void);
FUNC(void, RTE_CODE) Core3_Runnable_App_10ms(void);
FUNC(void, RTE_CODE) Core3_Runnable_App_20ms(void);
FUNC(void, RTE_CODE) Core3_Runnable_App_1ms(void);
FUNC(void, RTE_CODE) Core3_Runnable_App_50ms(void);
FUNC(void, RTE_CODE) Core3_Runnable_App_5ms(void);


FUNC(void, RTE_CODE) Core0_Runnable_Bsw_100ms(void);
FUNC(void, RTE_CODE) Core0_Runnable_Bsw_10ms(void);
FUNC(void, RTE_CODE) Core0_Runnable_Bsw_20ms(void);
FUNC(void, RTE_CODE) Core0_Runnable_Bsw_1ms(void);
FUNC(void, RTE_CODE) Core0_Runnable_Bsw_50ms(void);
FUNC(void, RTE_CODE) Core0_Runnable_Bsw_5ms(void);


FUNC(void, RTE_CODE) Core1_Runnable_Bsw_100ms(void);
FUNC(void, RTE_CODE) Core1_Runnable_Bsw_10ms(void);
FUNC(void, RTE_CODE) Core1_Runnable_Bsw_20ms(void);
FUNC(void, RTE_CODE) Core1_Runnable_Bsw_1ms(void);
FUNC(void, RTE_CODE) Core1_Runnable_Bsw_50ms(void);
FUNC(void, RTE_CODE) Core1_Runnable_Bsw_5ms(void);


FUNC(void, RTE_CODE) Core2_Runnable_Bsw_100ms(void);
FUNC(void, RTE_CODE) Core2_Runnable_Bsw_10ms(void);
FUNC(void, RTE_CODE) Core2_Runnable_Bsw_20ms(void);
FUNC(void, RTE_CODE) Core2_Runnable_Bsw_1ms(void);
FUNC(void, RTE_CODE) Core2_Runnable_Bsw_50ms(void);
FUNC(void, RTE_CODE) Core2_Runnable_Bsw_5ms(void);


FUNC(void, RTE_CODE) Core3_Runnable_Bsw_100ms(void);
FUNC(void, RTE_CODE) Core3_Runnable_Bsw_10ms(void);
FUNC(void, RTE_CODE) Core3_Runnable_Bsw_20ms(void);
FUNC(void, RTE_CODE) Core3_Runnable_Bsw_1ms(void);
FUNC(void, RTE_CODE) Core3_Runnable_Bsw_50ms(void);
FUNC(void, RTE_CODE) Core3_Runnable_Bsw_5ms(void);

extern void ErrorDiag_MainFunction(void);
extern void ErrorHandler_MainFunction(void);
extern void DetectErrDiag_Task(void);

#endif 
