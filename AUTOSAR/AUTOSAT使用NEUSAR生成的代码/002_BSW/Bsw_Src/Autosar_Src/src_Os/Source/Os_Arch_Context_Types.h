/*
********************************************************************************
*
*  File name: Os_Arch_Context_Types.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: MiaoLH/2025.1.20
* Change: New create.
* Cause: New
********************************************************************************
*/
#ifndef OS_ARCH_CONTEXT_TYPES_H_
#define OS_ARCH_CONTEXT_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Arch_Types.h"

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* CPR register default vlaue. */
#define OS_INITIAL_CPR                          (0x00000000U)
/* MSR register user mode bit. */
#define OS_INITIAL_MSR_UM                       (0x00004000U)
/* MSR register interrupt disable bit. */
#define OS_INITIAL_MSR_EE                       (0xFFFF7FFFU)
/* MSR register default vlaue. */
#define OS_INITIAL_MSR                          (0x02069000U)
/* Init vlaue. */
#define OS_CONTEXT_INIT                         (0U)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
struct Os_Arch_ContextDyn
{
    /* Current sp. */
    uint32* currentSp;
};

struct Os_Arch_ContextCfg
{
    struct Os_Arch_ContextDyn* contextDyn;
    /* Machine state register. */
    uint32 msr;
    /* The interrupt level of this thread. */
    uint32 cpr;
    /* Entry point of the thread. */
    uint32 entryAddr;
    /* The return address of this thread. */
    uint32 exitAddr;
    /* Associated stack start address. */
    Os_Stack_Address* stackStartAddr;
    /* Associated stack end address. */
    Os_Stack_Address* stackEndAddr;
};

typedef struct Os_Arch_ContextDyn Os_Arch_ContextDynType;
typedef struct Os_Arch_ContextCfg Os_Arch_ContextCfgType;

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

#endif /* OS_ARCH_CONTEXT_TYPES_H_ */
