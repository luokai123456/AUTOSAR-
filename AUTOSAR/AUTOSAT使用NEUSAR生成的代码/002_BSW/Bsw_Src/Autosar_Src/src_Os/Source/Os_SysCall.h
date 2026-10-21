/*
********************************************************************************
*
*  File name: Os_SysCall.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: BaoWL/2022.01.02
* Change: New created.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2022.11.21
* Change: Change OS_VAR_NOINIT to OS_VAR_NO_INIT.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: JiangGL/2024.03.07
* Change: Added the "Os_SysCallHandlerEnableAllInterrupts" interface to adapt to
*         the issue of global interrupts not being able to be closed when exiting
*          a chip with "OS_ARCH_INTMASKLEVE_SUPPORT" authorization interrupt.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2023.4.15
* Change: Adapted to GCC compiler.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: LiuZB/2025.02.20
* Change: Optimize space size.
* Cause: Update
********************************************************************************
*/
#ifndef OS_SYSCALL_H_
#define OS_SYSCALL_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_SysCall_Types.h"

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
#if( OS_MEMORY_PROTECTION == STD_ON )
extern FUNC(void, OS_CODE) Os_SysCall
(
    Os_Syscall_FuncId funcId,
    P2VAR(Os_SysCallParamType, AUTOMATIC, OS_APPL_DATA) parameter
);
#endif/* OS_MEMORY_PROTECTION == STD_ON */
extern FUNC(void, OS_CODE) Os_SysCallHandler
(
    P2VAR(Os_SysCallType, AUTOMATIC, OS_APPL_DATA) sysCallData
);
#if( OS_MEMORY_PROTECTION == STD_ON )
#if( OS_ARCH_INTMASKLEVE_SUPPORT == STD_OFF )
extern FUNC(boolean, OS_CODE) Os_SysCallHandlerEnableAllInterrupts
(
    P2VAR(Os_SysCallType, AUTOMATIC, OS_APPL_DATA) sysCallData
);
#endif /* OS_ARCH_INTMASKLEVE_SUPPORT == STD_OFF */
#endif/* OS_MEMORY_PROTECTION == STD_ON */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_SYSCALL_H_ */
