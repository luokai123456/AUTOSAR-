/*
********************************************************************************
*
*  File name: Os_Hook_Types.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.17
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2023.10.3
* Change: Add ControlIdle Hook Type.
* Cause: Update
********************************************************************************
*/
#ifndef OS_HOOK_TYPES_H_
#define OS_HOOK_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Types.h"

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
/* Function pointer data type for hook user functions with status parameter. */
typedef void (*Os_ErrorHookType)(StatusType Error);

/* Function pointer data type for hook user functions with status parameter. */
typedef void (*Os_ShutdownHookType)(StatusType Fatalerror);

/* Function pointer data type for startup hook user functions. */
typedef void (*Os_StartupHookType)(void);

/* Function pointer data type for hook user functions with status parameter. */
typedef ProtectionReturnType (*Os_ProtectionHookType)(StatusType Fatalerror);

typedef void (*Os_PreTaskHookType)(void);
typedef void (*Os_PostTaskHookType)(void);
typedef void (*Os_ControlIdleHookType)(IdleModeType IdleMode);

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

#endif /* OS_HOOK_TYPES_H_ */
