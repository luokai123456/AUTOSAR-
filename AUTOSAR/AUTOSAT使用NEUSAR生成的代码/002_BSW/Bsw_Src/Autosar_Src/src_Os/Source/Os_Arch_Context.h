/*
********************************************************************************
*
*  File name: Os_Arch_Context.h
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
#ifndef OS_ARCH_CONTEXT_H_
#define OS_ARCH_CONTEXT_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Arch_Context_Types.h"
#include "Os_Arch_Types.h"
#include "Os_Arch_Mach.h"
#include "Os_Isr_Types.h"
#include "Os_Core.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define OS_CORE_REG_NUM                             (30U)
#define Os_Arch_Context_Switch_ISR(current, next)   Os_Arch_Context_Switch(current, next)

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
/*
********************************************************************************
* Function Name: Os_Arch_Context_Init
*
* Explanation: Context initialization.
*
* Param: current: The stack pointer of the context.
*        cfg: Initialized configuration.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_Context_Init
(
    P2VAR(Os_Arch_ContextDynType, AUTOMATIC, OS_APPL_DATA) current,
    P2CONST(Os_Arch_ContextCfgType, AUTOMATIC, OS_APPL_CONST) cfg
)
{
    uint8 index;

    if( (current != NULL_PTR) && (cfg != NULL_PTR) )
    {
        /* Set current Stack pionter. */
        current->currentSp = (cfg->stackStartAddr);

        /* Leave 16 byte for system use. */
        for( index = OS_NAUGHT_VALUE; index < (OS_STACK_TOP_OFFSET / OS_STACK_TYPE_WIDTH); index++ )
        {
            *current->currentSp = OS_STACK_RESERVED;
            current->currentSp--;
        }
        /* Init stack value for R2-R31. */
        for( index = OS_NAUGHT_VALUE; index <= OS_CORE_REG_NUM; index++ )
        {
            *current->currentSp = OS_STACK_RESERVED;
            current->currentSp--;
        }
        /* Init stack value for R0. */
        *current->currentSp = OS_STACK_RESERVED;
        current->currentSp--;
        /* Init stack value for XER. */
        *current->currentSp = OS_CONTEXT_INIT;
        current->currentSp--;
        /* Init stack value for CTR. */
        *current->currentSp = OS_CONTEXT_INIT;
        current->currentSp--;
        /* Init stack value for LR. */
        *current->currentSp = cfg->exitAddr;
        current->currentSp--;
        /* Init stack value for CR. */
        *current->currentSp = OS_CONTEXT_INIT;
        current->currentSp--;
        /* Init stack value for SRR1 MSR. */
        *current->currentSp = cfg->msr;
        current->currentSp--;
        /* Init stack value for SRR0 PC. */
        *current->currentSp = cfg->entryAddr;
        current->currentSp--;
        /* Init stack value for CPR. */
        *current->currentSp = cfg->cpr;
        current->currentSp--;
        /* Leave 4 byte for system use. */
        current->currentSp--;
    }
}

extern FUNC(void, OS_CODE) Os_Arch_ResetContext_Switch
(
    P2CONST(Os_Arch_ContextCfgType, AUTOMATIC, OS_APPL_CONST) cfg,
    P2VAR(Os_Arch_ContextDynType, AUTOMATIC, OS_APPL_DATA) next
);
extern FUNC(void, OS_CODE) Os_Arch_Context_Stack_Init
(
    P2CONST(Os_Arch_ContextCfgType, AUTOMATIC, OS_APPL_CONST) cfg
);
extern FUNC(void, OS_CODE) Os_Arch_ContextSp_Init
(
    P2VAR(Os_Arch_ContextDynType, AUTOMATIC, OS_APPL_DATA) current,
    P2CONST(Os_Arch_ContextCfgType, AUTOMATIC, OS_APPL_CONST) cfg
);

#endif /* OS_ARCH_CONTEXT_H_ */
