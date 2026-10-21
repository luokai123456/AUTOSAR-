/*
********************************************************************************
*
*  File name: Os_Isr.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.18
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2023.4.6
* Change: Prohibit triggering time protection issues during interrupt processes.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2023.10.3
* Change: Add the relevant functions of the EnableInterruptSource and 
*         DisableInterruptSource interface.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: ZhangY/2024.01.10
* Change: Add Os_Isr_TerminateIsr function.
* Cause: Bugfix
********************************************************************************
* Version: 3.5
* Author/Date: JiangGL/2024.03.07
* Change: Added the "Os_Isr_GetInterruptStatus" interface to adapt to the issue
*          of global interrupts not being able to be closed when exiting a chip
*          with "OS_ARCH_INTMASKLEVE_SUPPORT" authorization interrupt.
* Cause: Bugfix
********************************************************************************
* Version: 3.6
* Author/Date: LiG/2023.4.15
* Change: Adapted to GCC compiler.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: LiuZB/2025.2.26
* Change: Fit for cat1 isr stack function.
* Cause: Update
********************************************************************************
*/
#ifndef OS_ISR_H_
#define OS_ISR_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Isr_Types.h"
#include "Os_Arch_Types.h"
#include "Os_Arch_Mach.h"
#include "Os_Platform_Lcfg.h"
#include "Os_Cfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Get the isr static configuration. */
#define OS_ISR_GETCFG(isrId)                  (Os_IsrCfgData[isrId])
/* Get the application id to which the isr belongs through
   the isr static configuration. */
#define OS_ISR_GETAPPID(isrCfg)               ((isrCfg)->ownerAppId)
/* Get the resource associated with the isr. */
#define OS_ISR_GETISRSOURCE(isrCfg)           ((isrCfg)->source)
/* Determine that the current processing is counter isr. */
#define OS_ISR_ISTIMER(isrId)                 (Os_IsrCfgData[isrId]->ifconterIsr == TRUE)
/* Determine that the current processing is time protection isr. */
#define OS_ISR_ISTPISR(isrId)                 (Os_IsrCfgData[isrId]->ifTpIsr == FALSE)
/* Get the counter id associated with the isr. */
#define OS_ISR_GETCNTID(isrId)                (Os_IsrCfgData[isrId]->counterId)
/* Get priority of isr configuration. */
#define OS_ISR_GETINTLEVEL(isrId)             (Os_IsrCfgData[isrId]->source->level)
/* Get the resource list head associated with the isr. */
#define OS_ISR_GETRESLISTHEAD(isrDyn)         (&((isrDyn)->resListHead))
/* Get the spinlock list head associated with the isr. */
#define OS_ISR_GETSPINLISTHEAD(isrDyn)        (&((isrDyn)->spinListHead))
/* Get the core id to which the isr belongs through
   the isr static configuration. */
#define OS_ISR_GETCOREID(isrCfg)              ((isrCfg)->coreId)
/* Get the stack start address of the isr configuration. */
#define OS_ISR_GETSTACKSTARTADDR(isrCfg)      ((isrCfg)->contextCfg->stackStartAddr)
/* Get the stack end address of the isr configuration. */
#define OS_ISR_GETSTACKENDADDR(isrCfg)        ((isrCfg)->contextCfg->stackEndAddr)
/* Get isr running appid. */
#define OS_ISR_GETCURRENTAPPID(isrCfg)        ((isrCfg)->isrDyn->currentAppId)
/* Set isr running appid. */
#define OS_ISR_SETCURRENTAPPID(isrCfg, appid) ((isrCfg)->isrDyn->currentAppId = (appid))

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
extern FUNC(void, OS_CODE) Os_Isr_Init
(
    P2CONST(Os_IsrCfgType, AUTOMATIC, OS_APPL_CONST) isrCfg
);
#if( OS_CFG_CAT1_ISR_STACK_ENABLE == STD_ON )
extern FUNC(void, OS_CODE) Os_Cat1_Isr_Init
(
    P2CONST(Os_IsrCat1CfgType, AUTOMATIC, OS_APPL_CONST) isrCfg
);
#endif /* OS_CFG_CAT1_ISR_STACK_ENABLE == STD_ON */
extern FUNC(void, OS_CODE) Os_Isr_EnableSource
(
    P2CONST(Os_Arch_IsrSourceType, AUTOMATIC, OS_APPL_CONST) isrSource
);
extern FUNC(void, OS_CODE) Os_Isr_DisableSource
(
    P2CONST(Os_Arch_IsrSourceType, AUTOMATIC, OS_APPL_CONST) isrSource
);
extern FUNC(void, OS_CODE) Os_Isr_DisableAllInterrupts(void);
extern FUNC(void, OS_CODE) Os_Isr_EnableAllInterrupts
(
#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON )
Os_IntLevelType level
#else
void
#endif
);
extern FUNC(void, OS_CODE) Os_Isr_SuspendOSInterrupts(void);
extern FUNC(void, OS_CODE) Os_Isr_ResumeOSInterrupts
(
#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_ON )
Os_IntLevelType level
#else
void
#endif
);
extern FUNC(void, OS_CODE) Os_Isr_Entry
(
    P2CONST(Os_IsrCfgType, AUTOMATIC, OS_APPL_CONST) isrCfg,
    P2VAR(Os_Arch_ContextDynType*, AUTOMATIC, OS_APPL_DATA) currentContext
);
extern FUNC(void, OS_CODE) Os_Isr_Exit(void);
extern FUNC(void, OS_CODE) Os_SysCallIsrExit(void);
extern FUNC(ISRType, OS_CODE) Os_Isr_GetISRID(void);
extern FUNC(void, OS_CODE) Os_Isr_AppTerminateIsr
(
    P2CONST(Os_IsrCfgType, AUTOMATIC, OS_APPL_CONST) isrCfg
);
extern FUNC(void, OS_CODE) Os_Isr_TerminateIsr
(
    P2CONST(Os_IsrCfgType, AUTOMATIC, OS_APPL_CONST) isrCfg
);
FUNC(StatusType, OS_CODE) Os_Isr_EnableInterruptSource
(
  ISRType isrId,
  boolean clearPending
);
FUNC(StatusType, OS_CODE) Os_Isr_DisableInterruptSource
(
  ISRType isrId
);
#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_OFF )
extern FUNC(boolean, OS_CODE) Os_Isr_GetInterruptStatus(void);
#endif /* OS_ARCH_INTMASKLEVE_SUPPORT == STD_OFF */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_ISR_H_ */
