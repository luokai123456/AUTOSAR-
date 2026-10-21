/*
********************************************************************************
*
*  File name: Os_Resource.h
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
#ifndef OS_RESOURCE_H_
#define OS_RESOURCE_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Resource_Types.h"

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
#if( OS_CFG_RESOURCE_ENABLE == STD_ON )
extern FUNC(void, OS_CODE) Os_Resource_Init
(
    P2CONST(Os_ResourceCfgType, AUTOMATIC, OS_APPL_CONST) resourceCfg
);
extern FUNC(void, OS_CODE) Os_Resource_ForceReleaseAll
(
    P2VAR(Os_ListNodeType, AUTOMATIC, OS_APPL_DATA) rsrcListHead
);
extern FUNC(Os_StatusType, OS_CODE) Os_Resource_GetResource(ResourceType resId);
extern FUNC(Os_StatusType, OS_CODE) Os_Resource_ReleaseResource(ResourceType resId);
#endif /* OS_CFG_RESOURCE_ENABLE == STD_ON */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_RESOURCE_H_ */
