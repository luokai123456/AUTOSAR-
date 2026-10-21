/*
********************************************************************************
*
* File name: NeuLib_Timer.h
*
* Copyright 2023-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: ZhangDX/2023.08.01
* Change: New
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: TianG/2024.10.12
* Change: 1.Add a memory-map label to function.
*         2.Modify copyright.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: KangJH/2025.02.08
* Change: Fix compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: KangJH/2025.03.26
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: KangJH/2025.03.28
* Change: Fix some QAC warnings and remove comments.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: KangJH/2025.05.22
* Change: Fix the polyspace warning and add the polyspace deviation suppression
*         comment.
* Cause: Update
********************************************************************************
*/
#ifndef NEULIB_TIMER_H_
#define NEULIB_TIMER_H_

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

/*
********************************************************************************
*    Includes
********************************************************************************
*/
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule20.1" */
#include "NeuLib_Def.h"
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule20.1" */
#include "NeuLib_MemPool.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define NEULIB_TICK_MAX                 0xFFFFFFFFUL

/* Clock & timer macros. */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NEULIB_TIMER_FLAG_DEACTIVATED   0x0U /*!< timer is deactive */
#define NEULIB_TIMER_FLAG_ACTIVATED     0x1U /*!< timer is active */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NEULIB_TIMER_FLAG_ONE_SHOT      0x0U /*!< One shot timer. */
#define NEULIB_TIMER_FLAG_PERIODIC      0x2U /*!< Periodic timer. */

/* MD_MSR_Rule20.10_0342 */
/* polyspace-begin MISRA-C3:20.10 [Justified:Unset] "NSCA_Polyspace_Common_Rule20.10" */
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NEULIB_TIMER_MEMP_VAR(_moduleName, _name, _num)                                     \
        NEULIB_MEM_POOL_DEF_VAR(_moduleName, _name##Timer, _num, sizeof(NeuLibTimer_Type))  \
        /* soft timer list */                                                               \
        static VAR(NeuLibList_Type, _moduleName##_VAR_NO_INIT) _name##_SoftTimerList;  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */

/* MD_MSR_Rule20.10_0342 */
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NEULIB_TIMER_MEMP_CONST(_moduleName, _name, _num)                           \
        NEULIB_MEM_POOL_DEF_CONST(_moduleName, _name##Timer, _num, sizeof(NeuLibTimer_Type));  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */

/* MD_MSR_Rule20.10_0342 */
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NEULIB_TIMER_INIT(_name)                                                    \
        NeuLibTimer_Init(&(NeuMemp_##_name##Timer), &(_name##_SoftTimerList))  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */

/* MD_MSR_Rule20.10_0342 */
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NEULIB_TIMER_CREATE(_name, _desc, _timeoutFunc, _parameter, _time, _flag)   \
        NeuLibTimer_Create(_name, &(NeuMemp_##_desc##Timer), _timeoutFunc, _parameter, _time, _flag)  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */

/* MD_MSR_Rule20.10_0342 */
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NEULIB_TIMER_START(_getTick, _timer, _name)                                 \
        NeuLibTimer_Start(_getTick, _timer, &_name##_SoftTimerList)  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */

/* MD_MSR_Rule20.10_0342 */
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NEULIB_TIMER_ENTRY(_getTick, _name)                                         \
        NeuLibTimer_Entry(_getTick, &_name##_SoftTimerList)  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */
/* polyspace-end MISRA-C3:20.10 [Justified:Unset] "NSCA_Polyspace_Common_Rule20.10" */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef P2FUNC(NeuLibTick_Type, TYPEDEF, NeuLibTimeGetTick_Type)(void);
typedef P2FUNC(void, TYPEDEF, NeuTimeOutFunc_Type)(void *parameter);
/**
 * timer structure
 */
struct NeuLibTimer
{
#ifdef NEU_DEBUG
    char                 name[128];
#endif  /* NEU_DEBUG */
    NeuLibList_Type        row;
    NeuTimeOutFunc_Type timeoutFunc;    /*!< timeout function.             */
    void                 *parameter;    /*!< timeout function's parameter. */
    NeuLibTick_Type        initTick;    /*!< timer timeout tick.           */
    NeuLibTick_Type        timeoutTick; /*!< timeout tick.                 */
    uint8                flag;          /*!< timeout flag.                 */
};
typedef struct NeuLibTimer NeuLibTimer_Type;

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
#define NEULIB_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
FUNC(void, NEULIB_CODE) NeuLibTimer_Init(
    P2CONST(NeuLibMemPoolDesc_Type, AUTOMATIC, NEULIB_APPL_CONST) desc,
    P2VAR(NeuLibList_Type, AUTOMATIC, NEULIB_APPL_DATA) timerList
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC_P2VAR(NeuLibTimer_Type, NEULIB_APPL_DATA, NEULIB_CODE) NeuLibTimer_Create(
    P2CONST(char, AUTOMATIC, NEULIB_APPL_CONST) name,
    P2CONST(NeuLibMemPoolDesc_Type, AUTOMATIC, NEULIB_APPL_CONST) desc,
    NeuTimeOutFunc_Type timeout,
    P2VAR(void, AUTOMATIC, NEULIB_APPL_DATA) parameter,
    NeuLibTick_Type timeCount,
    uint8 flag
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC(Std_ReturnType, NEULIB_CODE) NeuLibTimer_Delete(
    P2CONST(NeuLibMemPoolDesc_Type, AUTOMATIC, NEULIB_APPL_CONST) desc,
    P2VAR(NeuLibTimer_Type, AUTOMATIC, NEULIB_APPL_DATA) timer
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC(Std_ReturnType, NEULIB_CODE) NeuLibTimer_Start(
    NeuLibTimeGetTick_Type getTick,
    P2VAR(NeuLibTimer_Type, AUTOMATIC, NEULIB_APPL_DATA) timer,
    P2VAR(NeuLibList_Type, AUTOMATIC, NEULIB_APPL_DATA)  timerList
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC(Std_ReturnType, NEULIB_CODE) NeuLibTimer_Stop(
    P2VAR(NeuLibTimer_Type, AUTOMATIC, NEULIB_APPL_DATA) timer
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC(void, NEULIB_CODE) NeuLibTimer_Entry(
    NeuLibTimeGetTick_Type getTick,
    P2VAR(NeuLibList_Type, AUTOMATIC, NEULIB_APPL_DATA)  timerList
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
#define NEULIB_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* NEULIB_TIMER_H_ */
