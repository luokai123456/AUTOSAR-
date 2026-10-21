/*
********************************************************************************
*
*  File name: Os_SchdTb_Lcfg.c
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
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_SchdTb_Lcfg.h"
#include "Os_Platform_Lcfg.h"

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
#define OS_START_SEC_VAR_OSCORE0 
#include "Os_MemMap.h"
#define OS_STOP_SEC_VAR_OSCORE0 
#include "Os_MemMap.h"

#define OS_START_SEC_INITVAR_OSCORE0 
#include "Os_MemMap.h"
#define OS_STOP_SEC_INITVAR_OSCORE0 
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_OSCORE1 
#include "Os_MemMap.h"
#define OS_STOP_SEC_VAR_OSCORE1 
#include "Os_MemMap.h"

#define OS_START_SEC_INITVAR_OSCORE1 
#include "Os_MemMap.h"
#define OS_STOP_SEC_INITVAR_OSCORE1 
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_OSCORE2 
#include "Os_MemMap.h"
#define OS_STOP_SEC_VAR_OSCORE2 
#include "Os_MemMap.h"

#define OS_START_SEC_INITVAR_OSCORE2 
#include "Os_MemMap.h"
#define OS_STOP_SEC_INITVAR_OSCORE2 
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_OSCORE3 
#include "Os_MemMap.h"
#define OS_STOP_SEC_VAR_OSCORE3 
#include "Os_MemMap.h"

#define OS_START_SEC_INITVAR_OSCORE3 
#include "Os_MemMap.h"
#define OS_STOP_SEC_INITVAR_OSCORE3 
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_OSCORE4 
#include "Os_MemMap.h"
#define OS_STOP_SEC_VAR_OSCORE4 
#include "Os_MemMap.h"

#define OS_START_SEC_INITVAR_OSCORE4 
#include "Os_MemMap.h"
#define OS_STOP_SEC_INITVAR_OSCORE4 
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_OSCORE5 
#include "Os_MemMap.h"
#define OS_STOP_SEC_VAR_OSCORE5 
#include "Os_MemMap.h"

#define OS_START_SEC_INITVAR_OSCORE5 
#include "Os_MemMap.h"
#define OS_STOP_SEC_INITVAR_OSCORE5 
#include "Os_MemMap.h"

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
#define OS_START_SEC_CONST 
#include "Os_MemMap.h"
const Os_SchdTbCfgType* const Os_SchdTbCfgData[OS_SCHTID_COUNT + 1] =
{
    NULL_PTR
};
#define OS_STOP_SEC_CONST 
#include "Os_MemMap.h"

