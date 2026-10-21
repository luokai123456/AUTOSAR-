/*
********************************************************************************
*
*  File name: Os_Arch_Core.h
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
#ifndef OS_ARCH_CORE_H_
#define OS_ARCH_CORE_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Types.h"
#include "Os_Arch_Types.h"
#include "Os_Arch_Lcfg.h"
#include "Os_Arch_Mach.h"
#include "Os_Arch_Kernal_Lcfg.h"
#include "Os_Arch_Interrupt_Lcfg.h"
#include "Os_SysCall_Types.h"
#include "Os_Spinlock_Types.h"
#include "Os_Arch_Compiler.h"
#include "Os_SysCall.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Disable all interrupts mask. */
#define OS_ARCH_INTDISABLEALLMASK           (0xFFFFU)
/* Spinlock CAST. */
#define OS_ARCH_SPINLOCK_CAST               ((uint32)9U << 28U)
/* Spinlock SLD. */
#define OS_ARCH_SPINLOCK_SLD                ((uint32)0U << 16U)
/* Spinlock exclusive flag. */
#define OS_ARCH_SPINLOCK_FLAG               (1U)

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
extern const uint32 ROM_OS_EXCVEC_OSCORE_START[];
extern const uint32 ROM_OS_IRQVEC_OSCORE_START[];

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

/*
********************************************************************************
* Function Name: Os_Arch_GetCoreId
*
* Explanation: Get physical core id.
*
* Param: None
*
* Retval: Physical core id.
********************************************************************************
*/
LOCAL_INLINE FUNC(uint32, OS_CODE) Os_Arch_GetCoreId(void)
{
    uint32 result = OS_NAUGHT_VALUE;

    /* Get core id. */
    result = Os_Hal_ReadSPR(OS_HAL_SPR_PIR);

    return result;
}

/*
********************************************************************************
* Function Name: Os_Arch_IntDisableAll
*
* Explanation: Disable global interrupts.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_IntDisableAll(void)
{
    OS_ARCH_DISABLE();
}

/*
********************************************************************************
* Function Name: Os_Arch_IntEnableAll
*
* Explanation: Enable global interrupts.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_IntEnableAll(void)
{
    OS_ARCH_ENABLE();
}

/*
********************************************************************************
* Function Name: Os_Arch_Nop
*
* Explanation: Machine dry run once using the underlying interface.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_Nop(void)
{
    OS_ARCH_NOP();
}

/*
********************************************************************************
* Function Name: Os_Arch_Fpu_Init
*
* Explanation: Initialize the FPU.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_Fpu_Init(void)
{
    /* Do nothing. */
}

/*
********************************************************************************
* Function Name: Os_Arch_IntLevelIsHigher
*
* Explanation: Determine the current priority higher than configuring priority.
*
* Param: currentLevel: Current priority and configuring priority.
*        intLevel: Target level.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(boolean, OS_CODE) Os_Arch_IntLevelIsHigher
(
    Os_IntLevelType currentLevel,
    Os_IntLevelType intLevel
)
{
    boolean ret;

    if( OS_NAUGHT_VALUE == intLevel )
    {
        ret = TRUE;
    }
    else
    {
        if( currentLevel <= intLevel )
        {
            ret = TRUE;
        }
        else
        {
            ret = FALSE;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Arch_IntLevelIsLower
*
* Explanation: Determine the current priority lower than configuring priority.
*
* Param: currentLevel: Current priority and configuring priority.
*        intLevel: Target level.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(boolean, OS_CODE) Os_Arch_IntLevelIsLower
(
    Os_IntLevelType currentLevel,
    Os_IntLevelType intLevel
)
{
    boolean ret;

    if( (OS_NAUGHT_VALUE == currentLevel) && (OS_NAUGHT_VALUE != intLevel) )
    {
        ret = TRUE;
    }
    else
    {
        if( (intLevel <= currentLevel) && (OS_NAUGHT_VALUE != intLevel) )
        {
            ret = TRUE;
        }
        else
        {
            ret = FALSE;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Arch_SpinUnlock
*
* Explanation: Release the given spinlock.
*
* Param: spinlock: The spinlock to check. Parameter must not be NULL.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_SpinUnlock
(
    P2VAR(volatile Os_SpinlockType, AUTOMATIC, OS_APPL_DATA) spinlock
)
{
    /* Lock the spinlock. */
    *(volatile uint32*)(spinlock) = OS_SPINLOCK_UNLOCK;
}

/*
********************************************************************************
* Function Name: Os_Arch_GetIntMaskLevel
*
* Explanation: Get interrupt mask from interrupt priority register.
*
* Param: None
*
* Retval: interrupt mask level.
********************************************************************************
*/
LOCAL_INLINE FUNC(Os_IntLevelType, OS_CODE) Os_Arch_GetIntMaskLevel(void)
{
    uint32 result = OS_NAUGHT_VALUE;
    uint32 cprAddress;

    /* Get cpr address. */
    cprAddress = Os_Hal_ReadSPR(OS_HAL_SPR_SPRG1);
    /* Get cpr. */
    result = *(volatile uint32*)(cprAddress);

    return (Os_IntLevelType)result;
}

/*
********************************************************************************
* Function Name: Os_Arch_IntAllDisable
*
* Explanation: Disable all interrupts using low-level interfaces.
*
* Param: intState: The state acquired.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_IntAllDisable
(
    P2VAR(Os_Arch_IntState, AUTOMATIC, OS_APPL_DATA) intState
)
{
    uint32 cprAddress;
    uint32 msrValue;

    /* Get cpr address. */
    cprAddress = Os_Hal_ReadSPR(OS_HAL_SPR_SPRG1);
    /* Get cpr. */
    *intState = *(volatile uint32*)(cprAddress);
    /* Retrieve the value of the MSR register. */
    msrValue = __GETSR();
    /* Determine whether global interrupts are currently prohibited. */
    if( 0U != (msrValue & OS_ARCH_ISR_STATE_MASK) )
    {
        /* Disable all interrupts. */
        OS_ARCH_DISABLE();
    }
    /* Set interrupt operation priority. */
    *(volatile uint32*)(cprAddress) = OS_ARCH_INTDISABLEALLMASK;
    /* Memory Barrier. */
    Os_Hal_Asm("mbar   0" "\n");
    /* Determine whether global interrupts are currently prohibited. */
    if( 0U != (msrValue & OS_ARCH_ISR_STATE_MASK) )
    {
        /* Restore the interrupted state before the ban. */
        OS_ARCH_ENABLE();
    }
}

/*
********************************************************************************
* Function Name: Os_Arch_IntEnable
*
* Explanation: Enable interrupts using interrupt mask level.
*
* Param: intState: The state to set.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_IntEnable(Os_Arch_IntState intState)
{
    uint32 cprAddress;

    /* Get cpr address. */
    cprAddress = Os_Hal_ReadSPR(OS_HAL_SPR_SPRG1);
    /* Set cpr. */
    *(volatile uint32*)(cprAddress) = intState;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
extern FUNC(void, OS_CODE) Os_Arch_IntDisable
(
    P2VAR(Os_Arch_IntState, AUTOMATIC, OS_APPL_DATA) intState
);
extern FUNC(void, OS_CODE) Os_Arch_SetIntMaskLevel(Os_IntLevelType leve);
extern FUNC(void, OS_CODE) Os_Arch_IntEnableSource
(
    P2CONST(Os_Arch_IsrSourceType, AUTOMATIC, OS_APPL_CONST) isrSource
);
extern FUNC(void, OS_CODE) Os_Arch_IntDisableSource
(
    P2CONST(Os_Arch_IsrSourceType, AUTOMATIC, OS_APPL_CONST) isrSource
);
extern FUNC(void, OS_CODE) Os_Arch_ClearPendingIRQ
(
    P2CONST(Os_Arch_IsrSourceType, AUTOMATIC, OS_APPL_CONST) isrSource
);
extern FUNC(void, OS_CODE) Os_Arch_Trigger_Core(CoreIdType coreId);
extern FUNC(void, OS_CODE) Os_Arch_ClrMultiInt(CoreIdType coreId);
extern FUNC(void, OS_CODE) Os_Arch_SetNextContext
(
    P2VAR(Os_Arch_ContextDynType, AUTOMATIC, OS_APPL_DATA) context
);
extern FUNC(Os_SpinlockType, OS_CODE) Os_Arch_SpinTryLock
(
    P2VAR(volatile Os_SpinlockType, AUTOMATIC, OS_APPL_DATA) spinlock
);
extern FUNC(void, OS_CODE) Os_Arch_HardwareInit(void);
#if( OS_CFG_MULTI_CORE == STD_ON )
extern FUNC(void, OS_CODE) Os_Arch_StartCore
(
    CoreIdType coreId,
    uint32 startAddr
);
#endif /* OS_CFG_MULTI_CORE == STD_ON */

#endif /* OS_ARCH_CORE_H_ */
