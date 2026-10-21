/*
********************************************************************************
*
*  File name: Os_Error.h
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
* Author/Date: LiG/2023.4.15
* Change: Adapted to GCC compiler.
* Cause: Update
********************************************************************************
*/
#ifndef OS_ERROR_H_
#define OS_ERROR_H_

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
#define Os_ParamCheck(x) do {                                   \
                                if(!(x))                        \
                                {                               \
                                    while(TRUE)                 \
                                    {                           \
                                                                \
                                    }                           \
                                }                               \
                            }while(0)

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
extern FUNC(void, OS_CODE) Os_FatalError(void);
extern FUNC(OSServiceIdType, OS_CODE) OS_ErrorGetServiceId(void);
extern FUNC(Os_StatusType, OS_CODE) Os_GetErrorInformation
(
    P2VAR(Os_ErrorType, AUTOMATIC, OS_APPL_DATA) error
);
extern FUNC(void, OS_CODE) Os_ErrorProcess
(
    CoreIdType coreId,
    OSServiceIdType serviceId,
    StatusType error,
    OsCallerId caller
);

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_ERROR_H_ */
