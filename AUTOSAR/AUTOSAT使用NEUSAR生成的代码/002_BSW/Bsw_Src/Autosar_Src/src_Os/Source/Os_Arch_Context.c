/*
********************************************************************************
*
*  File name: Os_Arch_Context.c
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: JiangGL/2025.6.25
* Change: New create.
* Cause: New
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Arch_Core.h"
#include "Os_Arch_Types.h"
#include "Os_Arch_Context_Types.h"
#include "Os_Types.h"
#include "Os_Arch_Mach.h"
#include "Os_Stack.h"
#include "Os_Core.h"
#include "Os_Task.h"
#include "Os_Isr.h"

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
* Function Name: Os_Arch_ContextSp_Init
*
* Explanation: Sp initialization.
*
* Param: current: Current context Dyn.
*        cfg: Current context configuration.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_ContextSp_Init
(
    P2VAR(Os_Arch_ContextDynType, AUTOMATIC, OS_APPL_DATA) current,
    P2CONST(Os_Arch_ContextCfgType, AUTOMATIC, OS_APPL_CONST) cfg
)
{
    uint8 index;

    if( (current != NULL_PTR) && (cfg != NULL_PTR) )
    {
        /* Set current Stack pionter. */
        current->currentSp = cfg->stackStartAddr;
        /* Leave 16 byte for system use. */
        for( index = OS_NAUGHT_VALUE; index < (OS_STACK_TOP_OFFSET / OS_STACK_TYPE_WIDTH); index++ )
        {
            *current->currentSp = OS_STACK_RESERVED;
            current->currentSp--;
        }
    }
}

/*
********************************************************************************
* Function Name: Os_Arch_Context_Stack_Init
*
* Explanation: Stack initialization.
*
* Param: cfg: Context configuration.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_Context_Stack_Init
(
    P2CONST(Os_Arch_ContextCfgType, AUTOMATIC, OS_APPL_CONST) cfg
)
{
    if( cfg != NULL_PTR )
    {
        Os_Stack_Init(cfg->stackStartAddr, cfg->stackEndAddr);
    }
}

/*
********************************************************************************
* Function Name: Os_Arch_ResetContext_Switch
*
* Explanation: Initializing the current thread, restore the next thread.
*
* Param: cfg: Context configuration.
*        next: Next context.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_ResetContext_Switch
(
    P2CONST(Os_Arch_ContextCfgType, AUTOMATIC, OS_APPL_CONST) cfg,
    P2VAR(Os_Arch_ContextDynType, AUTOMATIC, OS_APPL_DATA) next
)
{
    /* Diaable all interrupts. */
    OS_ARCH_DISABLE();
    /* Initialize the current context. */
    Os_Arch_Context_Init(cfg->contextDyn, cfg);
    /* Resume the next context. */
    Os_Arch_Context_SwitchNext(next);
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
