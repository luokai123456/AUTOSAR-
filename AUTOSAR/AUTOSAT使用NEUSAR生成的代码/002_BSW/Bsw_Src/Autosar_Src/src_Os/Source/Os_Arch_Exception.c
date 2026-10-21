/*
********************************************************************************
*
*  File name: Os_Arch_Exception.c
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
* Version: 3.1
* Author/Date: JiangGL/2025.6.30
* Change: Fix the issue of inaccurate nested interrupt records in exception
*         handling functions.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Arch_Exception.h"
#include "Os_Arch_Kernal_Lcfg.h"
#include "Os_Arch_Core.h"
#include "Os_SysCall.h"
#include "Os_Core.h"
#include "Os_Isr.h"
#include "Os_SysCall_Types.h"
#include "Os_Hook.h"

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
#if( OS_ARCH_EXCEPTION_ERRIMFORMATION == STD_ON )
/* Obtain global interrupt enable status. */
#define OS_ARCH_GLOBAL_INT_STATUS(msrValue)                                   \
    ((((msrValue)&(~OS_INITIAL_MSR_EE)) == 0U)?FALSE:TRUE)
/* Obtaining privileged permission status. */
#define OS_ARCH_PRIVILEGED_STATUS(msrValue)                                   \
    ((((msrValue)&OS_INITIAL_MSR_UM) == 0U)?TRUE:FALSE)
/* Obtain interrupt source ID. */
#define OS_ARCH_GET_ISRSOURCE(isrFuncAddress)                                 \
    (((isrFuncAddress) - (uint32)ROM_OS_IRQVEC_OSCORE_START)>>2U)

#endif /* OS_ARCH_EXCEPTION_ERRIMFORMATION == STD_ON */

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
#if( OS_ARCH_EXCEPTION_ERRIMFORMATION == STD_ON )
#define OS_START_SEC_GLOBAL_NOCACHE_VAR
#include "Os_MemMap.h"
volatile Os_ExceptionImformationType Os_CoreExceptionImformationDyn[OS_COREID_COUNT];
#define OS_STOP_SEC_GLOBAL_NOCACHE_VAR
#include "Os_MemMap.h"
#endif /* OS_ARCH_EXCEPTION_ERRIMFORMATION == STD_ON */

OS_ARCH_CODE_SECTION(OS_EXCVEC_OSCORE)
OS_ARCH_GLOBAL_EXCINTVEC(OS_EXCVEC_OSCORE)
OS_ARCH_EXCEPTION_ENTRY(Os_Arch_Exception_CriticalInput)
OS_ARCH_EXCEPTION_ENTRY(Os_Arch_Exception_MachineCheck)
OS_ARCH_EXCEPTION_ENTRY(Os_Arch_Exception_Data)
OS_ARCH_EXCEPTION_ENTRY(Os_Arch_Exception_Instruction)
OS_ARCH_EXCEPTION_ENTRY(Os_Arch_Exception_ExternalInterrupt)
OS_ARCH_EXCEPTION_ENTRY(Os_Arch_Exception_Alignment)
OS_ARCH_EXCEPTION_ENTRY(Os_Arch_Exception_Program)
OS_ARCH_EXCEPTION_ENTRY(Os_Arch_Exception_PerformanceMonitor)
OS_ARCH_EXCEPTION_ENTRY(Os_Arch_Exception_Trap)
OS_ARCH_EXCEPTION_ENTRY(Os_Arch_Exception_Debug)
OS_ARCH_EXCEPTION_ENTRY(Os_Arch_Exception_EFPU_Data)
OS_ARCH_EXCEPTION_ENTRY(Os_Arch_Exception_EFPU_Round)
OS_ARCH_EXCEPTION_ENTRY(Os_Arch_Exception_TBD)

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"

#if( OS_ARCH_EXCEPTION_ERRIMFORMATION == STD_ON )
/*
********************************************************************************
* Function Name: Os_Arch_IsrNest_Push
*
* Explanation: Record the nesting level of the current interrupt and the pointer
*              to the service function.
*
* Param: address: Pointer to store the address of the interrupt service function.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_IsrNest_Push(uint32 address)
{
    uint32 isrNestCnt;
    CoreIdType coreId = Os_Core_GetLogicId();

    isrNestCnt = Os_CoreExceptionImformationDyn[coreId].exceptionCoreStatus.isrNestCnt;
    if( OS_ARCH_ISR_MAX_NUM > isrNestCnt )
    {
        Os_CoreExceptionImformationDyn[coreId].exceptionCoreStatus.isrFuncAddress[isrNestCnt] = address;
        Os_CoreExceptionImformationDyn[coreId].exceptionCoreStatus.isrNestCnt++;
    }
}

/*
********************************************************************************
* Function Name: Os_Arch_IsrNest_Pop
*
* Explanation: Exit the number of interrupt nesting layers and obtain a pointer
*              to the next interrupt service function that needs to be entered.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_IsrNest_Pop(void)
{
    CoreIdType coreId = Os_Core_GetLogicId();

    if( 0U < Os_CoreExceptionImformationDyn[coreId].exceptionCoreStatus.isrNestCnt )
    {
        Os_CoreExceptionImformationDyn[coreId].exceptionCoreStatus.isrNestCnt--;
    }
}

/*
********************************************************************************
* Function Name: Os_Arch_CheckCat2Isr
*
* Explanation: Obtain the source id of the current running interrupt.
*
* Param: currentIsrLevel: The priority level of ISR that needs to be determined.
*
* Retval: TRUE: This priority is the priority of Class II interrupts.
*         FALSE: This priority is the priority of Class I interrupts.
********************************************************************************
*/
LOCAL_INLINE FUNC(boolean, OS_CODE) Os_Arch_CheckCat2Isr(CoreIdType coreId, uint32 isrSource)
{
    boolean ret = FALSE;
    Os_ObjIdxType index;
    const Os_IsrCfgType* const* isrCfg = Os_CoreCfgData[coreId]->isrRefs;
    Os_ObjIdxType isrCnt = Os_CoreCfgData[coreId]->isrCnt;

    for(index = 0U; index < isrCnt; index++)
    {
        if( isrSource == isrCfg[index]->source->number )
        {
            ret = TRUE;
            break;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Arch_GetCurrentIsrSource
*
* Explanation: Obtain the source id of the current running interrupt.
*
* Param: coreId: Core id.
*
* Retval: Isr source id.
********************************************************************************
*/
LOCAL_INLINE FUNC(uint32, OS_CODE) Os_Arch_GetCurrentIsrSource(CoreIdType coreId)
{
    uint32 isrSource = 0U;
    uint32 isrFuncAddress;
    uint32 isrNestCnt;

    isrNestCnt = Os_CoreExceptionImformationDyn[coreId].exceptionCoreStatus.isrNestCnt;
    if( 0U < isrNestCnt )
    {
        isrNestCnt--;
        isrFuncAddress = Os_CoreExceptionImformationDyn[coreId].exceptionCoreStatus.isrFuncAddress[isrNestCnt];
        isrSource = OS_ARCH_GET_ISRSOURCE(isrFuncAddress);
    }

    return isrSource;
}

/*
********************************************************************************
* Function Name: Os_Arch_GetExceptionCurrent
*
* Explanation: Record the OS site type when an exception occurs.
*
* Param: coreId: Core id.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_GetExceptionCurrent(CoreIdType coreId)
{
    volatile Os_ExceptionCurrentType* exceptionCurrent;
    Os_ProcType procType;
    uint32 isrSource;

    exceptionCurrent = &(Os_CoreExceptionImformationDyn[coreId].exceptionCurrent);
    /* Interrupt nesting is 0. */
    if( 0U == Os_CoreExceptionImformationDyn[coreId].exceptionCoreStatus.isrNestCnt )
    {
        /* Obtain the current site type of the OS. */
        procType = OS_CORE_GETPROTYPE(coreId);
        if( OS_TASK_TYPE_MASK == procType )
        {
            /* Record the current site type of the OS. */
            exceptionCurrent->currentProcType = OS_PROC_TASK;
            /* Record the TaskId currently running on the OS. */
            exceptionCurrent->errTargetId.taskId = OS_CORE_GETCURRENTTASKID(coreId);
        }
        else if( OS_ERRHOOK_TYPE_MASK == procType )
        {
            /* Record the current site type of the OS. */
            exceptionCurrent->currentProcType = OS_PROC_ERRORHOOK;
            /* Record the ErrorId where the OS encountered an error. */
            exceptionCurrent->errTargetId.errorId = OS_CORE_GETERRORDATA(coreId).error;
        }
        else
        {
            /* Do nothing. */
        }
    }
    else
    {
        isrSource = Os_Arch_GetCurrentIsrSource(coreId);
        /* Determine whether an exception was triggered from a Class II interrupt. */
        if( TRUE == Os_Arch_CheckCat2Isr(coreId, isrSource) )
        {
            /* Record the site type as OS_ISR_CAT2_TYPE_MASK. */
            exceptionCurrent->currentProcType = OS_PROC_ISR_CAT2;
            /* Obtain the second type interrupt ID when an exception occurs. */
            exceptionCurrent->errTargetId.cat2IsrId = OS_CORE_GETCURRENTISRID(coreId);
        }
        else
        {
            /* Record the site type as OS_ISR_CAT1_TYPE_MASK. */
            exceptionCurrent->currentProcType = OS_PROC_ISR_CAT1;
            /* Obtain a type of interrupt priority when an exception occurs. */
            exceptionCurrent->errTargetId.cat1IsrSource = isrSource;
        }
    }
}

/*
********************************************************************************
* Function Name: Os_Arch_GetExceptionImformation
*
* Explanation: Record abnormal information.
*
* Param: excepSource: Abnormal source.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_GetExceptionImformation(Os_Arch_ExceptionSourceType excepSource)
{
    volatile Os_Arch_ExceptionCoreStatusType *exceptionCoreStatus;
    volatile Os_Arch_ExceptionType* exceptionType;
    uint32 currentPc = 0;
    uint32 currentMsr = 0;
    CoreIdType coreId = Os_Core_GetLogicId();

    exceptionCoreStatus = &(Os_CoreExceptionImformationDyn[coreId].exceptionCoreStatus);

    switch( (sint32)excepSource )
    {
        case OS_ARCH_EXCEPTION_CRITICALINPUT:
            currentPc = Os_Hal_ReadSPR(OS_HAL_SPR_CSRR0);
            currentMsr = Os_Hal_ReadSPR(OS_HAL_SPR_CSRR1);
            break;
        case OS_ARCH_EXCEPTION_MACHINECHECK:
            currentPc = Os_Hal_ReadSPR(OS_HAL_SPR_MCSRR0);
            currentMsr = Os_Hal_ReadSPR(OS_HAL_SPR_MCSRR1);
            break;
        case OS_ARCH_EXCEPTION_DATA:
            currentPc = Os_Hal_ReadSPR(OS_HAL_SPR_SRR0);
            currentMsr = Os_Hal_ReadSPR(OS_HAL_SPR_SRR1);
            break;
        case OS_ARCH_EXCEPTION_INSTRUCTION:
            currentPc = Os_Hal_ReadSPR(OS_HAL_SPR_SRR0);
            currentMsr = Os_Hal_ReadSPR(OS_HAL_SPR_SRR1);
            break;
        case OS_ARCH_EXCEPTION_ALIGNMENT:
            currentPc = Os_Hal_ReadSPR(OS_HAL_SPR_SRR0);
            currentMsr = Os_Hal_ReadSPR(OS_HAL_SPR_SRR1);
            break;
        case OS_ARCH_EXCEPTION_PROGRAM:
            currentPc = Os_Hal_ReadSPR(OS_HAL_SPR_SRR0);
            currentMsr = Os_Hal_ReadSPR(OS_HAL_SPR_SRR1);
            break;
        case OS_ARCH_EXCEPTION_PERFORMANCEMONITOR:
            currentPc = Os_Hal_ReadSPR(OS_HAL_SPR_DSRR0);
            currentMsr = Os_Hal_ReadSPR(OS_HAL_SPR_DSRR1);
            break;
        case OS_ARCH_EXCEPTION_DEBUG:
            currentPc = Os_Hal_ReadSPR(OS_HAL_SPR_DSRR0);
            currentMsr = Os_Hal_ReadSPR(OS_HAL_SPR_DSRR1);
            break;
        case OS_ARCH_EXCEPTION_EFPU_DATA:
            currentPc = Os_Hal_ReadSPR(OS_HAL_SPR_SRR0);
            currentMsr = Os_Hal_ReadSPR(OS_HAL_SPR_SRR1);
            break;
        case OS_ARCH_EXCEPTION_EFPU_ROUND:
            currentPc = Os_Hal_ReadSPR(OS_HAL_SPR_SRR0);
            currentMsr = Os_Hal_ReadSPR(OS_HAL_SPR_SRR1);
            break;
        case OS_ARCH_EXCEPTION_EFPU_TBD:
            /* Do nothing. */
            break;
        default :
            /* Do nothing. */
            break;
    }

    /* PC pointer before generating an exception. */
    exceptionCoreStatus->pcAddress = currentPc;
    /* Record whether it is a privilege level before generating an exception. */
    exceptionCoreStatus->globalIntSwitch = OS_ARCH_GLOBAL_INT_STATUS(currentMsr);
    /* Record the on-site environment when anomalies occur. */
    exceptionCoreStatus->privilegesPermissions = OS_ARCH_PRIVILEGED_STATUS(currentMsr);

    /* Interrupt priority mask before exception generation. */
    exceptionCoreStatus->intPriorityMask = Os_Arch_GetIntMaskLevel();
    /* Address of the data that generated the exception. */
    exceptionCoreStatus->excDataAddress = Os_Hal_ReadSPR(OS_HAL_SPR_DEAR);

    exceptionType = &(Os_CoreExceptionImformationDyn[coreId].exceptionType);
    /* Record the type of exception that occurred. */
    exceptionType->sourceType = excepSource;

    Os_Arch_GetExceptionCurrent(coreId);
}

/*
********************************************************************************
* Function Name: Os_Arch_ClearPendingException
*
* Explanation: Record abnormal information.
*
* Param: excepSource: Abnormal source.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_ClearPendingException(Os_Arch_ExceptionSourceType excepSource)
{
    OS_DUMMY_STATEMENT(excepSource);
}

/*
********************************************************************************
* Function Name: Os_Arch_Exception_Entry
*
* Explanation: Exception isr entry.
*
* Param: exceptionSourceType: Reason for hardware failure.
*        currentSp: SP pointer at the scene of the problem.
*
* Retval: None
********************************************************************************
*/
#include "Evpt_InterDataWatch_Prv.h"
FUNC(void, OS_CODE) Os_Arch_Exception_Entry
(
    Os_Arch_ExceptionSourceType exceptionSourceType,
    uint32 currentSp
)
{
    CoreIdType coreId;
    StatusType error;

    /* Get coreId. */
    coreId = Os_Core_GetLogicId();
    /* Save current sp point. */
    Os_CoreExceptionImformationDyn[coreId].exceptionCurrent.currentSp = currentSp;
    /* Set the sp value to the core kernal stack start address. */
    OS_ARCH_SETSP(OS_ARCH_CORE_GETSTACKSTARTADDR(coreId));
    /* Clear exception interrupt flag. */
    Os_Arch_ClearPendingException(exceptionSourceType);
    /* Log an error information. */
    Os_Arch_GetExceptionImformation(exceptionSourceType);
    Evpt_Diagnostic_Database_ExceptionDiagData();
#if( OS_CFG_EXCEPTION_HOOK_FOR_USER == STD_ON )
    /* Call Processing function defined by user. */
    ExceptionHook((uint32)exceptionSourceType);
#endif /* OS_CFG_EXCEPTION_HOOK_FOR_USER == STD_ON */
    /* Call the protection hook. */
    if( ((uint32)OS_ARCH_EXCEPTION_DATA) == exceptionSourceType )
    {
        error = E_OS_PROTECTION_MEMORY;
    }
    else
    {
        error = E_OS_PROTECTION_EXCEPTION;
    }
    /* Disable scheduler. */
    OS_CORE_DISABLESCH(coreId);
    /* Call protection hook. */
    Os_Hook_CallProtectionHook(error);
    /* Call fatal error. */
    Os_FatalError();
}
#endif /* OS_ARCH_EXCEPTION_ERRIMFORMATION == STD_ON */

/*
********************************************************************************
* Function Name: Os_Arch_Exception_CriticalInput
*
* Explanation: Mcu critical input exception handler.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_Exception_CriticalInput(void)
{
    Os_Arch_ExceptionInterruptAsm(OS_ARCH_EXCEPTION_CRITICALINPUT);
}

/*
********************************************************************************
* Function Name: Os_Arch_Exception_MachineCheck
*
* Explanation: Mcu MachineCheck exception handler.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_Exception_MachineCheck(void)
{
    Os_Arch_ExceptionInterruptAsm(OS_ARCH_EXCEPTION_MACHINECHECK);
}

/*
********************************************************************************
* Function Name: Os_Arch_Exception_Data
*
* Explanation: Mcu data access exception handler.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_Exception_Data(void)
{
    Os_Arch_ExceptionInterruptAsm(OS_ARCH_EXCEPTION_DATA);
}

/*
********************************************************************************
* Function Name: Os_Arch_Exception_Instruction
*
* Explanation: Mcu instruction exception handler.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_Exception_Instruction(void)
{
    Os_Arch_ExceptionInterruptAsm(OS_ARCH_EXCEPTION_INSTRUCTION);
}

/*
********************************************************************************
* Function Name: Os_Arch_Exception_ExternalInterrupt
*
* Explanation: Mcu ExternalInterrupt exception handler.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_Exception_ExternalInterrupt(void)
{
    __asm (
        "wrteei      0                          " "\n"  /* Disable interrupt. */
        "e_addi      sp,       sp,      -120    " "\n"  /* Mov sp. */
        "e_stmw      r2,       0(sp)            " "\n"  /* Save r2-r31. */
        "e_stwu      r0,       -4(sp)           " "\n"  /* Save r0. */
        "e_stmvsprw  -16(sp)                    " "\n"  /* Saving CR, LR, CTR, XER. */
        "e_addi      sp,       sp,      -24     " "\n"  /* Mov sp. */
        "e_stmvsrrw  0(sp)                      " "\n"  /* Save PC, MSR (SRR0, SRR1). */
        "mfspr       r4,       sprg1            " "\n"  /* Get cpr Address. */
        "se_lwz      r3,       0(r4)            " "\n"  /* Get cpr vaule. */
        "e_stwu      r3,       -4(sp)           " "\n"  /* Save CPR. */
        "e_addi      sp,       sp,      -8      " "\n"  /* Mov sp. */
        "e_lwz       r3,       0x10(r4)         " "\n"  /* Get interrupt function point address. */
#if( OS_ARCH_EXCEPTION_ERRIMFORMATION == STD_ON )
        "e_stwu      r3,       -4(sp)           " "\n"  /* Save R3. */
        "e_bl        Os_Arch_IsrNest_Push       " "\n"
        "e_lwz       r3,       0(sp)            " "\n"  /* Restores R3. */
        "e_addi      sp,       sp,      4       " "\n"  /* Mov sp. */
#endif /* OS_ARCH_EXCEPTION_ERRIMFORMATION == STD_ON */
        "e_lwz       r3,       0(r3)            " "\n"  /* Get interrupt function isr address. */
        "mtspr       lr,       r3               " "\n"  /* Mov interrrupt function address to lr. */
        "se_blrl                                " "\n"  /* Jump to the interrupt entry address. */
        "wrteei      0                          " "\n"  /* Disable interrupt. */
        "mbar        0                          " "\n"  /* Memory Barrier. */
        "mfspr       r3,       sprg1            " "\n"  /* Get cpr Address. */
        "se_stw      r3,       0x20(r3)         " "\n"  /* Write EOIR. */
#if( OS_ARCH_EXCEPTION_ERRIMFORMATION == STD_ON )
        "e_stwu      r3,       -4(sp)           " "\n"  /* Save R3. */
        "e_bl        Os_Arch_IsrNest_Pop        " "\n"
        "e_lwz       r3,       0(sp)            " "\n"  /* Restores R3. */
        "e_addi      sp,       sp,      4       " "\n"  /* Mov sp. */
#endif /* OS_ARCH_EXCEPTION_ERRIMFORMATION == STD_ON */
        "e_addi      sp,       sp,      8       " "\n"  /* Mov sp. */
        "e_lwzu      r0,       0(sp)            " "\n"  /* Get restores cpr value. */
        "se_stw      r0,       0(r3)            " "\n"  /* Restores cpr. */
        "e_lmvsrrw   4(sp)                      " "\n"  /* Restores PC, MSR (SRR0, SRR1). */
        "e_lmvsprw   12(sp)                     " "\n"  /* Restore CR, LR, CTR, XER. */
        "e_lwzu      r0,       28(sp)           " "\n"  /* Restore r0. */
        "e_lmw       r2,       4(sp)            " "\n"  /* Restore r2-r31. */
        "e_addi      sp,       sp,      124     " "\n"  /* Mov sp. */
        "se_rfi                                 " "\n"  /* Return. */
    );
}

/*
********************************************************************************
* Function Name: Os_Arch_Exception_Alignment
*
* Explanation: Mcu Alignment exception handler.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_Exception_Alignment(void)
{
    Os_Arch_ExceptionInterruptAsm(OS_ARCH_EXCEPTION_ALIGNMENT);
}

/*
********************************************************************************
* Function Name: Os_Arch_Exception_Program
*
* Explanation: Mcu program exception handler.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_Exception_Program(void)
{
    Os_Arch_ExceptionInterruptAsm(OS_ARCH_EXCEPTION_PROGRAM);
}

/*
********************************************************************************
* Function Name: Os_Arch_Exception_PerformanceMonitor
*
* Explanation: Mcu performance monitor exception handler.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_Exception_PerformanceMonitor(void)
{
    Os_Arch_ExceptionInterruptAsm(OS_ARCH_EXCEPTION_PERFORMANCEMONITOR);
}

/*
********************************************************************************
* Function Name: Os_Arch_Exception_Trap
*
* Explanation: Mcu Syscall exception handler.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_Exception_Trap(void)
{
    __asm (
        "e_addi      sp,       sp,      -120    " "\n"  /* Mov sp. */
        "e_stmw      r2,       0(sp)            " "\n"  /* Save r2-r31. */
        "e_stwu      r0,       -4(sp)           " "\n"  /* Save r0. */
        "e_stmvsprw  -16(sp)                    " "\n"  /* Saving CR, LR, CTR, XER. */
        "e_addi      sp,       sp,      -24     " "\n"  /* Mov sp. */
        "e_stmvsrrw  0(sp)                      " "\n"  /* Save PC, MSR (SRR0, SRR1). */
        "e_addi      sp,       sp,      -8      " "\n"  /* Mov sp. */

        "mfspr       r0,       srr1             " "\n"  /* Get MSR. */
        "e_andi.     r0,       r0,      0x8000  " "\n"  /* Determine whether to enable interrupt before entering SVC. */
        "e_beq       enterTrap                  " "\n"  /* Skip enable interrupt. */
        "wrteei      1                          " "\n"  /* Enable Interrupts. */
        "enterTrap:                             " "\n"

        "e_bl        Os_SysCallHandler          " "\n"  /* Call Os_SysCallHandler. */
        "wrteei      0                          " "\n"  /* Disable Interrupts. */
        "mbar        0                          " "\n"  /* Memory Barrier. */
        "e_addi      sp,       sp,      8       " "\n"  /* Mov sp. */
        "e_lmvsrrw   0(sp)                      " "\n"  /* Restores PC, MSR (SRR0, SRR1). */
        "e_lmvsprw   8(sp)                      " "\n"  /* Restore CR, LR, CTR, XER. */
        "e_lwzu      r0,       24(sp)           " "\n"  /* Restore r0. */
        "e_lmw       r2,       4(sp)            " "\n"  /* Restore r2-r31. */
        "e_addi      sp,       sp,      124     " "\n"  /* Mov sp. */
        "se_rfi                                 " "\n"  /* Return. */
    );
}

/*
********************************************************************************
* Function Name: Os_Arch_Exception_Debug
*
* Explanation: Mcu debug monitor exception handler.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_Exception_Debug(void)
{
    Os_Arch_ExceptionInterruptAsm(OS_ARCH_EXCEPTION_DEBUG);
}

/*
********************************************************************************
* Function Name: Os_Arch_Exception_EFPU_Data
*
* Explanation: Mcu Embedded Floating-point Data exception handler.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_Exception_EFPU_Data(void)
{
    Os_Arch_ExceptionInterruptAsm(OS_ARCH_EXCEPTION_EFPU_DATA);
}

/*
********************************************************************************
* Function Name: Os_Arch_Exception_EFPU_Round
*
* Explanation: Mcu Embedded Floating-point Round exception handler.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_Exception_EFPU_Round(void)
{
    Os_Arch_ExceptionInterruptAsm(OS_ARCH_EXCEPTION_EFPU_ROUND);
}

/*
********************************************************************************
* Function Name: Os_Arch_Exception_TBD
*
* Explanation: Mcu TBD exception handler.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_Exception_TBD(void)
{
    Os_Arch_ExceptionInterruptAsm(OS_ARCH_EXCEPTION_EFPU_TBD);
}

/*
********************************************************************************
* Function Name: Os_Arch_Irq_Unhandled
*
* Explanation: Mcu undefined irq handler.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_Irq_Unhandled(void)
{
    Os_FatalError();
}

/*
********************************************************************************
* Function Name: Os_Arch_Cat1InterruptAsm
*
* Explanation: The second type of interrupt service function processing entry.
*
* Param: isrHandle: Type 1 Interrupt Handler
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_Cat1InterruptAsm(Os_Arch_Cat1HandlerType isrHandle)
{
    Os_ProcType currentProcType;
    CoreIdType coreId = Os_Core_GetLogicId();

    /* Get the current context type. */
    currentProcType = OS_CORE_GETPROTYPE(coreId);
    /* Get the cat1 isr type. */
    OS_CORE_SETPROTYPE(coreId, OS_ISR_CAT1_TYPE_MASK);
    /* Enable interrupt. */
    OS_ARCH_ENABLE();
    /* Go to cat1 isr handler. */
    isrHandle();
    OS_CORE_SETPROTYPE(coreId, currentProcType);
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
