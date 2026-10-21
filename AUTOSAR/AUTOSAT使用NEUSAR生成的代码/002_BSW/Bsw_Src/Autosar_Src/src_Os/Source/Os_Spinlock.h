/*
********************************************************************************
*
*  File name: Os_Spinlock.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.23
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2022.11.21
* Change: Change OS_VAR_NOINIT to OS_VAR_NO_INIT.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2023.4.15
* Change: Adapted to GCC compiler.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: LiuZB/2025.02.20
* Change: Optimize space size.
* Cause: Update
********************************************************************************
*/
#ifndef OS_SPINLOCK_H_
#define OS_SPINLOCK_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Spinlock_Types.h"
#include "Std_Types.h"
#include "Os_Platform_Lcfg.h"
#include "Os_Task.h"
#include "Os_Isr.h"
#include "Os_App.h"

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
#if( OS_CFG_SPINLOCK_ENABLE == STD_ON )
extern FUNC(void, OS_CODE) Os_Spinlock_Init
(
    P2CONST(Os_SpinlockCfgType, AUTOMATIC, OS_APPL_CONST) spinlockCfg
);
extern FUNC(void, OS_CODE) Os_Spinlock_IntlGetSpinlock
(
    SpinlockIdType spinlockId,
    CoreIdType coreId
);
extern FUNC(void, OS_CODE) Os_Spinlock_IntlReleaseSpinlock
(
    SpinlockIdType spinlockId,
    CoreIdType coreId
);
extern FUNC(Os_StatusType, OS_CODE) Os_Spinlock_GetSpinlock(SpinlockIdType spinlockId);
extern FUNC(Os_StatusType, OS_CODE) Os_Spinlock_ReleaseSpinlock(SpinlockIdType spinlockId);
extern FUNC(Os_StatusType, OS_CODE) Os_Spinlock_TryToGetSpinlock
(
    SpinlockIdType spinlockId,
    P2VAR(TryToGetSpinlockType, AUTOMATIC, OS_APPL_DATA) success
);
extern FUNC(void, OS_CODE) Os_Spinlock_ForceReleaseAll
(
    P2VAR(Os_ListNodeType, AUTOMATIC, OS_APPL_DATA) spinListHead
);
#endif /* OS_CFG_SPINLOCK_ENABLE == STD_ON */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_SPINLOCK_H_ */
