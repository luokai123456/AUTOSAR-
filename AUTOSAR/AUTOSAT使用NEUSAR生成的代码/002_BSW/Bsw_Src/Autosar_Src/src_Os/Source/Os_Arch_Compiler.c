/*
********************************************************************************
*
*  File name: Os_Arch_Compiler.c
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: JiangGL/2025.1.20
* Change: New create.
* Cause: New
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Arch_Context_Types.h"
#include "Os_Arch_Types.h"
#include "Os_Arch_Compiler.h"
#include "Os_Core.h"
#include "Os_Arch_Version.h"
#include "Os.h"

#if ( OS_KERNAL_SW_MINOR_VERSION != OS_SW_MINOR_VERSION )
#error The kernal code and common code of Os do not match.
#endif
#if ( OS_KERNAL_SW_PATCH_VERSION != OS_SW_PATCH_VERSION )
#error The kernal code and common code of Os do not match.
#endif

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
* Function Name: Os_Arch_Stack_Switch
*
* Explanation: Stack switch.
*
* Param: current: Current context.
*        next: Next context.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_Stack_Switch
(
    P2VAR(Os_Arch_ContextDynType, AUTOMATIC, OS_APPL_DATA) current,
    P2VAR(Os_Arch_ContextDynType, AUTOMATIC, OS_APPL_DATA) next
)
{
    __asm(
        "e_lwz    r8,     0(r3)       "   "\n"    /* Fetch the first element on the stack. */
        "e_addi   sp,     sp,     -4  "   "\n"    /* Move stack pointer. */
        "e_stw    r8,     0(sp)       "   "\n"    /* Write the element into the stack. */
        "e_stw    sp,     0(r3)       "   "\n"    /* Save current sp. */
        "e_lwz    sp,     0(r4)       "   "\n"    /* Restore the next context sp. */
    );
}

/*
********************************************************************************
* Function Name: Os_Arch_Stack_Restore
*
* Explanation: Stack restore.
*
* Param: next: Next context.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_Stack_Restore
(
    P2VAR(Os_Arch_ContextDynType, AUTOMATIC, OS_APPL_DATA) next
)
{
    __asm(
        "e_lwz    sp,     0(r3)       "       "\n"    /* Restor current sp. */
        "e_lwz    r8,     0(sp)       "       "\n"    /* Fetch the first element on the stack. */
        "e_stw    r8,     0(r3)       "       "\n"    /* Write the element back into the variable. */
        "e_addi   sp,     sp,     4   "       "\n"    /* Move stack pointer. */
    );
}

/*
********************************************************************************
* Function Name: Os_Arch_Context_SwitchNext
*
* Explanation: Switch next context.
*
* Param: next: Next context.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_Context_SwitchNext
(
    P2VAR(Os_Arch_ContextDynType, AUTOMATIC, OS_APPL_DATA) next
)
{
    __asm(
        "wrteei     0                       "    "\n" /* Disable interrupt. */
        "e_lwz      sp,     0(r3)           "    "\n" /* Set sp. */
        "e_addi     sp,     sp,   8         "    "\n" /* Mov sp. */
        "mfspr      r3,     sprg1           "    "\n" /* Get cpr address. */
        "e_lwzu     r0,     0(sp)           "    "\n" /* Get cpr value. */
        "se_stw     r0,     0(r3)           "    "\n" /* Restoring cpr. */
        "e_lmvsrrw  4(sp)                   "    "\n" /* Restores PC, MSR (SRR0, SRR1). */
        "e_lmvsprw  12(sp)                  "    "\n" /* Restoring CR, LR, CTR, XER. */
        "e_lwzu     r0,     28(sp)          "    "\n" /* Restoring r0. */
        "e_lmw      r2,     4(sp)           "    "\n" /* R2-R31, mov sp. */
        "e_addi     sp,     sp,   124       "    "\n" /* Mov sp. */
        "se_rfi                             "    "\n" /* Return. */
    );
}

/*
********************************************************************************
* Function Name: Os_Arch_Context_SwitchFirst
*
* Explanation: Context switch first, Used to start the first task.
*
* Param: next: Next context.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_Context_SwitchFirst
(
    P2VAR(Os_Arch_ContextDynType, AUTOMATIC, OS_APPL_DATA) next
)
{
    __asm(
        "wrteei     0                       "    "\n" /* Disable interrupt. */
        "e_lwz      sp,     0(r3)           "    "\n" /* Set sp. */
        "e_addi     sp,     sp,         8   "    "\n" /* Mov sp. */
        "mfspr      r3,     sprg1           "    "\n" /* Get cpr address. */
        "e_lwz      r0,     0(sp)           "    "\n" /* Get cpr value. */
        "se_stw     r0,     0(r3)           "    "\n" /* Restoring cpr. */
        "e_lmvsrrw  4(sp)                   "    "\n" /* Restores PC, MSR (SRR0, SRR1). */
        "e_lmvsprw  12(sp)                  "    "\n" /* Restoring CR, LR, CTR, XER. */
        "e_lwzu     r0,     28(sp)          "    "\n" /* Restoring r0. */
        "e_lmw      r2,     4(sp)           "    "\n" /* R2-R31, mov sp. */
        "e_addi     sp,     sp,         124 "    "\n" /* Mov sp. */
        "se_rfi                             "    "\n" /* Return. */
    );
}

/*
********************************************************************************
* Function Name: Os_Arch_Context_Switch
*
* Explanation: Context switch.
*
* Param: current: Current context.
*        next: Next context.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_Context_Switch
(
    P2VAR(Os_Arch_ContextDynType, AUTOMATIC, OS_APPL_DATA) current,
    P2VAR(Os_Arch_ContextDynType, AUTOMATIC, OS_APPL_DATA) next
)
{
    __asm(
        /* Save Current. */
        "e_addi      sp,       sp,     -120    "   "\n" /* Mov sp. */
        "e_stmw      r2,       0(sp)           "   "\n" /* Save r2-r31. */
        "e_stwu      r0,       -4(sp)          "   "\n" /* Save r0. */
        "e_stmvsprw  -16(sp)                   "   "\n" /* Saving CR, LR, CTR, XER. */
        "e_addi      sp,       sp,     -24     "   "\n" /* Mov sp. */
        "mfmsr       r0                        "   "\n" /* Get MSR. */
        "wrteei      0                         "   "\n" /* Disable interrupt. */
        "mtspr       srr1,     r0              "   "\n" /* Set MSR to SRR1. */
        "se_mflr     r0                        "   "\n" /* Get lr. */
        "mtspr       srr0,     r0              "   "\n" /* Set lr to srr0. */
        "e_stmvsrrw  0(sp)                     "   "\n" /* Save PC, MSR (SRR0, SRR1). */
        "mfspr       r2,       sprg1           "   "\n" /* Get cpr address. */
        "se_lwz      r0,       0(r2)           "   "\n" /* Get CPR Value. */
        "e_stwu      r0,       -4(sp)          "   "\n" /* Save CPR. */
        "e_addi      sp,       sp,     -8      "   "\n" /* Mov sp. */
        "e_stw       sp,       0(r3)           "   "\n" /* Save sp. */
        /* Restore Current. */
        "wrteei      0                         "   "\n" /* Disable interrupt. */
        "e_lwz       sp,       0(r4)           "   "\n" /* Restore sp. */
        "e_addi      sp,       sp,     8       "   "\n" /* Mov sp. */
        "e_lwz       r0,       0(sp)           "   "\n" /* Get CPR value. */
        "se_stw      r0,       0(r2)           "   "\n" /* Restoring CPR. */
        "e_lmvsrrw   4(sp)                     "   "\n" /* Restores PC, MSR (SRR0, SRR1). */
        "e_lmvsprw   12(sp)                    "   "\n" /* Restore CR, LR, CTR, XER. */
        "e_lwzu      r0,       28(sp)          "   "\n" /* Restore r0. */
        "e_lmw       r2,       4(sp)           "   "\n" /* Restore r2-r31. */
        "e_addi      sp,       sp,     124     "   "\n" /* Mov sp. */
        "se_rfi                                "   "\n" /* Return. */
    );
}

/*
********************************************************************************
* Function Name: Os_Arch_SysCall
*
* Explanation: System call, Raise the trap0 interrupt.
*
* Param: callData: Systemcall required parameters.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_SysCall
(
    P2VAR(volatile Os_SysCallType, AUTOMATIC, OS_APPL_DATA) callData
)
{
    /* Trigger SysCall. */
    __asm("se_sc        " "\n");
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
