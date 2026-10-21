/*
********************************************************************************
*
*  File name: Os_Ioc_Lcfg.c
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date : HanCL/2021.11.23
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date : ZhangY/2024.11.22
* Change: Modify IOC function parameters to constant to fix RTE compilation error bug.
* Cause: Bugfix
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Ioc_Lcfg.h"
#include "Os_Ioc.h"
#include "Os_Platform_Lcfg.h"
#include "Os_Lcfg.h"

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
#define OS_START_SEC_GLOBAL_NOCACHE_INITVAR 
#include "Os_MemMap.h"

#define OS_STOP_SEC_GLOBAL_NOCACHE_INITVAR 
#include "Os_MemMap.h"

#define OS_START_SEC_GLOBAL_NOCACHE_VAR 
#include "Os_MemMap.h"

#define OS_STOP_SEC_GLOBAL_NOCACHE_VAR 
#include "Os_MemMap.h"

/*
********************************************************************************
*    Local Functions
********************************************************************************
*/
#define OS_START_SEC_CODE 
#include "Os_MemMap.h"
#define OS_STOP_SEC_CODE 
#include "Os_MemMap.h"

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
#define OS_START_SEC_CONST 
#include "Os_MemMap.h"
#define OS_STOP_SEC_CONST 
#include "Os_MemMap.h"
#define OS_START_SEC_CODE 
#include "Os_MemMap.h"
#define OS_STOP_SEC_CODE 
#include "Os_MemMap.h"


