/*
********************************************************************************
*
*  File name: Os_Arch_Core.c
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
#include "Os_Arch_Context.h"
#include "Os_Core.h"

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/* Bind interrupts to the corresponding kernel. */
#define OS_HAL_INTC_PSR_MARK(coreId)    (((uint32)(coreId) < OS_HAL_INTC_SUPPORT_CORE_NUM) ? \
                                        (uint16)(0x8000U >> (coreId)) : (uint16)(0x8000U >> ((coreId) - OS_HAL_INTC_SUPPORT_CORE_NUM)))
/* Os_Arch_IntDisable disbale interrupt level mask. */
#define OS_ARCH_INTDISABLEMASK(coreId)  (OsCfg_Arch_IsrMaskLevel[(coreId)]->IntDisableMaskLevel)
/* Get the physical core Id. */
#define OS_CORE_GETCOREPHYID(coreId)    (Os_CoreCfgData[(coreId)]->corePhyId)

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
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
static FUNC(void, OS_CODE) Os_Arch_ExceptionVectorTbInit(void);
static FUNC(void, OS_CODE) Os_Arch_IntVectorTbInit(void);
static FUNC(boolean, OS_CODE) Os_Arch_LoadExclusive
(
    P2CONST(volatile uint32, AUTOMATIC, OS_APPL_CONST) addr
);
static FUNC(boolean, OS_CODE) Os_Arch_StoreExclusive
(
    P2VAR(volatile uint32, AUTOMATIC, OS_APPL_DATA) addr,
    uint32 value
);

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
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*
********************************************************************************
* Function Name: Os_Arch_IntDisable
*
* Explanation: Disable cat2 interrupts and store the current interrupt mask level.
*
* Param: intState: The state acquired.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_IntDisable
(
    P2VAR(Os_Arch_IntState, AUTOMATIC, OS_APPL_DATA) intState
)
{
    uint32 cprAddress;
    CoreIdType coreId;
    uint32 msrValue;

    /* Get coreId. */
    coreId = Os_Core_GetLogicId();
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
    *(volatile uint32*)(cprAddress) = OS_ARCH_INTDISABLEMASK(coreId);
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
* Function Name: Os_Arch_ClearPendingIRQ
*
* Explanation: Clear nvic interrupt pending flag.
*
* Param: isrSource: The number of the external interrupt to clear.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_ClearPendingIRQ
(
    P2CONST(Os_Arch_IsrSourceType, AUTOMATIC, OS_APPL_CONST) isrSource
)
{
    OS_DUMMY_STATEMENT(isrSource);
}

/*
********************************************************************************
* Function Name: Os_Arch_ExceptionVectorTbInit
*
* Explanation: Initialize the exception vector table.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_Arch_ExceptionVectorTbInit(void)
{
    /* Remap Exception Interrupt Vector Table. */
    Os_Hal_WriteSPR(OS_HAL_SPR_IVPR, (uint32)ROM_OS_EXCVEC_OSCORE_START);
}

/*
********************************************************************************
* Function Name: Os_Arch_IntVectorTbInit
*
* Explanation: Initialize the interrupt vector table.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_Arch_IntVectorTbInit(void)
{
    uint32 coreId;

    coreId = Os_Arch_GetCoreId();
    /* Remap Exception Interrupt Vector Table. */
    *((volatile uint32 *)(OS_HAL_INTC_BASE_ADDRESS(coreId) + OS_HAL_IACKR_OFFSET(coreId)))
        = (uint32)ROM_OS_IRQVEC_OSCORE_START;
}

/*
********************************************************************************
* Function Name: Os_Arch_HardwareInit
*
* Explanation: Chip hardware initialization Kernel related.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_HardwareInit(void)
{
    uint32 coreId;
    uint32 intcCprBaseAddress;

    /* Get Core id. */
    coreId = Os_Arch_GetCoreId();
    /* Anomaly vector table remapping. */
    Os_Arch_ExceptionVectorTbInit();
    /* Anomaly vector table remapping. */
    Os_Arch_IntVectorTbInit();

    /* Obtain the CPR address of coreId. */
    intcCprBaseAddress = OS_HAL_INTC_BASE_ADDRESS(coreId) + OS_HAL_CPR_OFFSET(coreId);
    /* Set interrupt operation priority to minimum. */
    *(volatile uint32 *)(intcCprBaseAddress) = OS_NAUGHT_VALUE;
    /* Save the address of (INTC_CPR) in sprg1. */
    Os_Hal_WriteSPR(OS_HAL_SPR_SPRG1, intcCprBaseAddress);
    /* FPU function initialization. */
    Os_Arch_Fpu_Init();
}

/*
********************************************************************************
* Function Name: Os_Arch_IntEnableSource
*
* Explanation: Enable interrupt source.
*
* Param: isrSource: Interrupt configuration of to enable.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_IntEnableSource
(
    P2CONST(Os_Arch_IsrSourceType, AUTOMATIC, OS_APPL_CONST) isrSource
)
{
    uint16 regvalue;
    uint32 coreId = Os_Arch_GetCoreId();

    if( NULL_PTR != isrSource )
    {
        *((volatile uint32 *)(OS_HAL_INTC_BASE_ADDRESS(coreId) +
            OS_HAL_INTC_BCR_OFFSET)) = OS_NAUGHT_VALUE;
        /* Obtain the PSR2 address of coreId. */
        regvalue = OS_HAL_INTC_PSR_MARK(coreId);
        /* Calculate Priority. */
        regvalue |= isrSource->level;
        /* Configure the priority of the corresponding kernel. */
        *(volatile uint16 *)(OS_HAL_INTC_BASE_ADDRESS(coreId) +
            OS_HAL_INTC_PSR_OFFSET((uint32)(isrSource->number))) = regvalue;
    }
}

/*
********************************************************************************
* Function Name: Os_Arch_IntDisableSource
*
* Explanation: Disable interrupt source.
*
* Param: isrSource: Interrupt configuration of to disable.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_IntDisableSource
(
    P2CONST(Os_Arch_IsrSourceType, AUTOMATIC, OS_APPL_CONST) isrSource
)
{
    uint16 regvalue;
    uint32 coreId = Os_Arch_GetCoreId();

    if( NULL_PTR != isrSource )
    {
        /* Obtain the PSR2 address of coreId. */
        regvalue = OS_HAL_INTC_PSR_MARK(coreId);
        /* Configure the priority of the corresponding kernel. */
        *((volatile uint16 *)(OS_HAL_INTC_BASE_ADDRESS(coreId) +
            OS_HAL_INTC_PSR_OFFSET((uint32)(isrSource->number)))) = regvalue;
    }
}

/*
********************************************************************************
* Function Name: Os_Arch_SetIntMaskLevel
*
* Explanation: Set interrupt mask by set interrupt priority register.
*
* Param: level: interrupt mask level.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_SetIntMaskLevel(Os_IntLevelType leve)
{
    uint32 coreId = OS_NAUGHT_VALUE;
    uint32 cprAddress;
    uint32 msrValue;

    coreId = Os_Arch_GetCoreId();

    /* Get cpr address. */
    cprAddress = Os_Hal_ReadSPR(OS_HAL_SPR_SPRG1);

    /* Masking is category 1 interrupts. */
    if( OS_CAT1_MASKLEVE == leve )
    {
        leve = OsCfg_Arch_IsrMaskLevel[coreId]->Cat1MaskLevel;
    }
    /* Masked is category 2 interrupts. */
    else if( OS_CAT2_MASKLEVE == leve )
    {
        /* Obtain the current running priority. */
        Os_IntLevelType currentLevel = Os_Arch_GetIntMaskLevel();

        leve = OsCfg_Arch_IsrMaskLevel[coreId]->Cat2MaskLevel;
        /* Determine the relationship between the priority to be set and the
           current running priority. */
        if( leve < currentLevel )
        {
            leve = currentLevel;
        }
    }
    /* Mask other level interrupts. */
    else
    {
        /* Do nothing. */
    }
    /* Retrieve the value of the MSR register. */
    msrValue = __GETSR();
    /* Determine whether global interrupts are currently prohibited. */
    if( 0U != (msrValue & OS_ARCH_ISR_STATE_MASK) )
    {
        /* Disable all interrupts. */
        OS_ARCH_DISABLE();
    }
    /* Set interrupt operation priority. */
    *(volatile uint32*)(cprAddress) = leve;
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
* Function Name: Os_Arch_Trigger_Core
*
* Explanation: Trigger the given core softirq.
*
* Param: coreId: Core ID to trigger.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_Trigger_Core(CoreIdType coreId)
{
    uint32 pu1Unit;
    uint8 corePhyId = OS_CORE_GETCOREPHYID(coreId);
    const Os_Arch_IsrSourceType* isrSource = OS_CORE_GETMULTICOMMISRSOURCE(coreId);

    /* Get the interrupt. */
    pu1Unit = (uint32)(isrSource->number);
    if( OS_HAL_INTC_SOFT_INTERRUPTS_NUM > pu1Unit )
    {
        /* Trigger the softirq. */
        *(volatile uint8*)(OS_HAL_INTC_BASE_ADDRESS(corePhyId) + OS_HAL_INTC_SSCIR(pu1Unit)) =
            OS_HAL_INTC_SSCIR_TRIGGER_MSK;
    }
    else
    {
        /* Trigger the peripheral irq. */
        *(volatile uint16*)(OS_HAL_INTC_BASE_ADDRESS(corePhyId) + OS_HAL_INTC_PSR_OFFSET(pu1Unit))
            |= OS_HAL_INTC_PSR_TRIGGER_MSK;
    }

    OS_ARCH_ISYNC();
}

/*
********************************************************************************
* Function Name: Os_Arch_ClrMultiInt
*
* Explanation: Clear the given core softirq.
*
* Param: coreId: Core Id to clear softirq.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_ClrMultiInt(CoreIdType coreId)
{
    uint32 pu1Unit;
    uint8 corePhyId = OS_CORE_GETCOREPHYID(coreId);
    const Os_Arch_IsrSourceType* isrSource = OS_CORE_GETMULTICOMMISRSOURCE(coreId);

    pu1Unit = (uint32)(isrSource->number);
    if( OS_HAL_INTC_SOFT_INTERRUPTS_NUM > pu1Unit )
    {
        /* Clear generate directed core interrupt. */
        *(volatile uint8*)(OS_HAL_INTC_BASE_ADDRESS(corePhyId) + OS_HAL_INTC_SSCIR(pu1Unit)) =
            OS_HAL_INTC_SSCIR_ACK_MSK;
    }
    else
    {
        /* Do nothing. */
    }
}

/*
********************************************************************************
* Function Name: Os_Arch_SetNextContext
*
* Explanation: Set the context of the core.
*
* Param: context: Core context to be set.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_SetNextContext
(
    P2VAR(Os_Arch_ContextDynType, AUTOMATIC, OS_APPL_DATA) context
)
{
    CoreIdType coreId;
    Os_CoreDynType* coreDyn;

    /* Get the current logical core Id. */
    coreId = Os_Core_GetLogicId();
    /* Get the current core dyn. */
    coreDyn = OS_CORE_GETDYN(coreId);
    coreDyn->context = context;
}

/*
********************************************************************************
* Function Name: Os_Arch_LoadExclusive
*
* Explanation: Uses a load exclusive synchronization instruction for the address,
*              which attempts to mark the address for exclusive access by the
*              current processor, and return the result.
*
* Param: addr: Address value to read from. Parameter must not be NULL.
*
* Retval: 0  Success.
*         1  No success.
********************************************************************************
*/
static FUNC(boolean, OS_CODE) Os_Arch_LoadExclusive
(
    P2CONST(volatile uint32, AUTOMATIC, OS_APPL_CONST) addr
)
{
    uint32 spinlockValue;
    boolean ret;

    /* Attempt to obtain spinlock status. */
    spinlockValue = *(const volatile uint32*)(addr);
    if( OS_NAUGHT_VALUE != spinlockValue )
    {
        ret = OS_SPINLOCK_LOCK;
    }
    else
    {
        ret = OS_SPINLOCK_UNLOCK;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Arch_StoreExclusive
*
* Explanation: Tries to get the lock.
*
* Param: addr: Address of spinlock variable.
*        value: Write the value of spinlock variable.
*
* Retval: Lock state.
*         OS_SPINLOCK_UNLOCK: Get failed.
*         OS_SPINLOCK_LOCK: Get success.
********************************************************************************
*/
static FUNC(boolean, OS_CODE) Os_Arch_StoreExclusive
(
    P2VAR(volatile uint32, AUTOMATIC, OS_APPL_DATA) addr,
    uint32 value
)
{
    volatile uint32 decoration;
    volatile uint32 lock_Value;
    volatile uint8  lock;

    lock = OS_SPINLOCK_UNLOCK;
    /* When using this instruction, it is necessary to input the original
       value of the manipulated variable into the second parameter. */
    decoration = (OS_ARCH_SPINLOCK_CAST | OS_SPINLOCK_UNLOCK);
    __STWDCBX((void*)addr, decoration, value);
    /* Read out the variable to confirm it is locked. */
    decoration = OS_ARCH_SPINLOCK_SLD;
    lock_Value = __LWDCBX((void*)addr, decoration);

    if( lock_Value == value )
    {
        lock = OS_SPINLOCK_LOCK;
    }

    return lock;
}

/*
********************************************************************************
* Function Name: Os_Arch_SpinTryLock
*
* Explanation: Tries to get the lock.
*
* Param: spinlock: The spinlock to lock. Parameter must not be NULL.
*
* Retval: Lock state.
********************************************************************************
*/
FUNC(Os_SpinlockType, OS_CODE) Os_Arch_SpinTryLock
(
    P2VAR(volatile Os_SpinlockType, AUTOMATIC, OS_APPL_DATA) spinlock
)
{
    uint32 lock_Value;
    Os_SpinlockType result = OS_SPINLOCK_UNLOCK;
    uint32 core_Id = (uint32)Os_Core_GetLogicId();

    lock_Value = (core_Id + OS_ARCH_SPINLOCK_FLAG);

    /* If spinlock is free (use load exclusive instruction here). */
    if( OS_SPINLOCK_UNLOCK == Os_Arch_LoadExclusive(spinlock) )
    {
        /* Try to get the spinlock (use store exclusive instruction here). */
        if( OS_SPINLOCK_LOCK == Os_Arch_StoreExclusive(spinlock, lock_Value) )
        {
            result = OS_SPINLOCK_LOCK;
            /* Memory barrier. */
            OS_ARCH_MSYNC();
        }
    }

    return result;
}

#if( OS_CFG_MULTI_CORE == STD_ON )
/*
********************************************************************************
* Function Name: Os_Arch_StartCore
*
* Explanation: Start the core at the passed address.
*
* Param: coreId: The core Id that was started.
*        startAddr: Core start address.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_StartCore
(
    CoreIdType coreId,
    uint32 startAddr
)
{
    uint32 mode;
    boolean bol;
    uint8 corePhyId = OS_CORE_GETCOREPHYID(coreId);

    switch( corePhyId )
    {
        case OS_ARCH_PHYCOREID_1:
            *(volatile uint32*)(OS_HAL_MC_ME_BASE_ADDRESS + OS_HAL_MC_ME_CADDR2_OFFSET) = (startAddr | OS_HAL_MC_ME_CORE_RESET_MASK);
            *(volatile uint16*)(OS_HAL_MC_ME_BASE_ADDRESS + OS_HAL_MC_ME_CCTL2_OFFSET) = OS_HAL_MC_ME_CCTL_MASK;
            *(volatile uint32*)(OS_HAL_MC_ME_BASE_ADDRESS + OS_HAL_MC_ME_CADDR3_OFFSET) = OS_HAL_MC_ME_CORE_RESET_MASK;
            *(volatile uint16*)(OS_HAL_MC_ME_BASE_ADDRESS + OS_HAL_MC_ME_CCTL3_OFFSET) = OS_HAL_MC_ME_CCTL_MASK;
            break;
        case OS_ARCH_PHYCOREID_2:
            *(volatile uint32*)(OS_HAL_MC_ME_BASE_ADDRESS + OS_HAL_MC_ME_CADDR6_OFFSET) = (startAddr | OS_HAL_MC_ME_CORE_RESET_MASK);
            *(volatile uint16*)(OS_HAL_MC_ME_BASE_ADDRESS + OS_HAL_MC_ME_CCTL6_OFFSET) = OS_HAL_MC_ME_CCTL_MASK;
            *(volatile uint32*)(OS_HAL_MC_ME_BASE_ADDRESS + OS_HAL_MC_ME_CADDR7_OFFSET) = OS_HAL_MC_ME_CORE_RESET_MASK;
            *(volatile uint16*)(OS_HAL_MC_ME_BASE_ADDRESS + OS_HAL_MC_ME_CCTL7_OFFSET) = OS_HAL_MC_ME_CCTL_MASK;
            break;
        case OS_ARCH_PHYCOREID_3:
            *(volatile uint32*)(OS_HAL_MC_ME_BASE_ADDRESS + OS_HAL_MC_ME_CADDR8_OFFSET) = (startAddr | OS_HAL_MC_ME_CORE_RESET_MASK);
            *(volatile uint16*)(OS_HAL_MC_ME_BASE_ADDRESS + OS_HAL_MC_ME_CCTL8_OFFSET) = OS_HAL_MC_ME_CCTL_MASK;
            *(volatile uint32*)(OS_HAL_MC_ME_BASE_ADDRESS + OS_HAL_MC_ME_CADDR9_OFFSET) = OS_HAL_MC_ME_CORE_RESET_MASK;
            *(volatile uint16*)(OS_HAL_MC_ME_BASE_ADDRESS + OS_HAL_MC_ME_CCTL9_OFFSET) = OS_HAL_MC_ME_CCTL_MASK;
            break;
        case OS_ARCH_PHYCOREID_4:
            *(volatile uint32*)(OS_HAL_MC_ME_BASE_ADDRESS + OS_HAL_MC_ME_CADDR10_OFFSET) = (startAddr | OS_HAL_MC_ME_CORE_RESET_MASK);
            *(volatile uint16*)(OS_HAL_MC_ME_BASE_ADDRESS + OS_HAL_MC_ME_CCTL10_OFFSET) = OS_HAL_MC_ME_CCTL_MASK;
            break;
        case OS_ARCH_PHYCOREID_5:
            *(volatile uint32*)(OS_HAL_MC_ME_BASE_ADDRESS + OS_HAL_MC_ME_CADDR11_OFFSET) = (startAddr | OS_HAL_MC_ME_CORE_RESET_MASK);
            *(volatile uint16*)(OS_HAL_MC_ME_BASE_ADDRESS + OS_HAL_MC_ME_CCTL11_OFFSET) = OS_HAL_MC_ME_CCTL_MASK;
            break;
        default:
            break;
    }
    /* Get current mode. */
    mode = *(volatile uint32*)(OS_HAL_MC_ME_BASE_ADDRESS + OS_HAL_MC_ME_GS_OFFSET) & OS_HAL_CURRENT_MODE_MAKS;
    /* Enter key1 to unlock. */
    *(volatile uint32*)(OS_HAL_MC_ME_BASE_ADDRESS + OS_HAL_MC_ME_MCTL_OFFSET) = mode | OS_HAL_MC_ME_KEY1;
    /* Enter key2 to unlock. */
    *(volatile uint32*)(OS_HAL_MC_ME_BASE_ADDRESS + OS_HAL_MC_ME_MCTL_OFFSET) = mode | OS_HAL_MC_ME_KEY2;
    /* Waiting for end of transaction. */
    do
    {
        if( OS_NAUGHT_VALUE != (*(volatile uint32*)(OS_HAL_MC_ME_BASE_ADDRESS + OS_HAL_MC_ME_GS_OFFSET) & OS_HAL_MTRANS_MASK) )
        {
            bol = TRUE;
        }
        else
        {
            bol = FALSE;
        }
    } while( TRUE == bol );

    /* Check mode has successfully been entered. */
    do
    {
        if( mode != (*(volatile uint32*)(OS_HAL_MC_ME_BASE_ADDRESS + OS_HAL_MC_ME_GS_OFFSET) & OS_HAL_CURRENT_MODE_MAKS) )
        {
            bol = TRUE;
        }
        else
        {
            bol = FALSE;
        }
    } while( TRUE == bol );
}
#endif /* OS_CFG_MULTI_CORE == STD_ON */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
