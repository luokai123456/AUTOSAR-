/*
********************************************************************************
*
*  File name: Os_Error.c
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.12.03
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2022.11.21
* Change: Change OS_VAR_NOINIT to OS_VAR_NO_INIT.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: ZhangY/2023.11.27
* Change: Add OS_ISR_CAT1_TYPE_MASK case in Os_ErrorProcess function.
* Cause: Bugfix
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Error.h"
#include "Os_Cfg.h"
#include "Os_Core.h"
#include "Os_Arch_Core.h"

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
/*
********************************************************************************
* Function Name: Os_FatalError
*
* Explanation: System freeze, if the given condition is not true.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_FatalError(void)
{
    Os_Arch_IntDisableAll();
    while( TRUE )
    {
         Os_Arch_Nop();
    }
}

/*
********************************************************************************
* Function Name: Os_GetErrorInformation
*
* Explanation: Provides the service get error Information.
*
* Param: error: error id.
*
* Retval: E_OS_OK: No error.
*         E_OS_PARAM_POINTER: A null pointer was given as argument.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_GetErrorInformation
(
    P2VAR(Os_ErrorType, AUTOMATIC, OS_APPL_DATA) error
)
{
    Os_StatusType ret = E_OS_OK;
    CoreIdType coreId;

    /* Get logic core id. */
    coreId = Os_Core_GetLogicId();

    /* If error is null. */
    if( NULL_PTR == error )
    {
        ret = E_OS_PARAM_POINTER;
    }
    else
    {
        /* Get error information for core.*/
        *error = OS_CORE_GETERRORDATA(coreId);
    }

    return ret;
}

/*
********************************************************************************
* Function Name: OS_ErrorGetServiceId
*
* Explanation: Provides the service identifier where the error has been risen.
*
* Param: None
*
* Retval: error id.
********************************************************************************
*/
FUNC(OSServiceIdType, OS_CODE) OS_ErrorGetServiceId(void)
{
    OSServiceIdType ret;
    CoreIdType coreId;

    /* Get logic core id. */
    coreId = Os_Core_GetLogicId();

    /* Get error id. */
    ret = OS_CORE_GETERRORSERVICEID(coreId);

    return ret;
}

/*
********************************************************************************
* Function Name: Os_ErrorProcess
*
* Explanation: Provides the service identifier where the error has been risen.
*
* Param: coreId: Core id.
*        serviceId: The id of the service currently handling the error.
*        error: Detailed information about the current processing error.
*        caller: The caller currently handling the error.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_ErrorProcess
(
    CoreIdType coreId,
    OSServiceIdType serviceId,
    StatusType error,
    OsCallerId caller
)
{
    OsErrorProct  errorProctId;

    /* Record related error information. */
    OS_CORE_SETERRORSERVICEID(coreId, serviceId);
    OS_CORE_SETERRORSTATUS(coreId, error);
    OS_CORE_SETERRORCALLER(coreId, caller);

    switch( caller )
    {
        case OS_TASK_TYPE_MASK:
        case OS_PRETASKHOOK_TYPE_MASK:
        case OS_POSTTASKHOOK_TYPE_MASK:
            errorProctId = (OsErrorProct)OS_CORE_GETCURRENTTASKID(coreId);
            break;
        case OS_ISR_CAT2_TYPE_MASK:
            errorProctId = (OsErrorProct)OS_CORE_GETCURRENTISRID(coreId);
            break;
        case OS_ISR_CAT1_TYPE_MASK:
        case OS_ERRHOOK_TYPE_MASK:
        case OS_STARTUPHOOK_TYPE_MASK:
        case OS_SHUTDOWNHOOK_TYPE_MASK:
        case OS_PROTECTHOOK_TYPE_MASK:
            errorProctId = (OsErrorProct)OS_CORE_GETAPPID(coreId);
            break;
        default:
            Os_FatalError();
            break;
    }

    OS_CORE_SETERRORPROCTID(coreId, errorProctId);
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
