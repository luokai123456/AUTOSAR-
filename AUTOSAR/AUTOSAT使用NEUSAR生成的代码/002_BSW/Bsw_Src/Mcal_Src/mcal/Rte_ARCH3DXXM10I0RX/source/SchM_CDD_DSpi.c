/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : RTE
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : -
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/

/**
*   @file    SchM_CDD_DSpi.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Rte MCAL driver.
*
*   @addtogroup Rte
*   @{
*/

/* PRQA S 0380, 0686, 3006, 1006, 1891, 0491, 3344, 4558, 4115, 0795, 1527, 2985 EOF */
/*===================================================================================================
 *                                            INCLUDE FILES
 ====================================================================================================*/
#ifdef __cplusplus 
extern "C" {
#endif
#include "SchM_CDD_DSpi.h"
#include "devassert.h"
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SEMAPHORE)
#include "sema42_lld.h"
#endif


/*===================================================================================================
 *                                            LOCAL MACROS
 ====================================================================================================*/
#define MULTICORE_CDD_DSPI_GUARD_NUM             50U
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SEMAPHORE)
#ifndef RTE_CDD_DSPI_SEMA42_GATE_ID
#define RTE_CDD_DSPI_SEMA42_GATE_ID              (GATE_NUM)(RTE_DEFAULT_SEMA42_GATE_ID)
#endif
#endif
/*===================================================================================================
 *                                          LOCAL CONSTANTS
 ====================================================================================================*/
/*===================================================================================================
 *                               LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 ====================================================================================================*/
/*===================================================================================================
 *                                          LOCAL VARIABLES
 ====================================================================================================*/
#if(!defined(CDD_DSPI_CRITICAL_SECTION_PROTECTION_UNUSED) || (MULTICORE_CDD_DSPI_TYPE != MULTICORE_TYPE_EXCLUSIVE))
/* Guard for the module variable against overwrite */
#pragma pack (push, GUARD_TYPE_SIZE)
#define RTE_START_SEC_VAR_SHARED_INIT
#include "Rte_MemMap.h"
static guard_type multi_core_cdd_dspi_guard[50][CDD_DSPI_CORE_NUM] = {{ 0 }};
#define RTE_STOP_SEC_VAR_SHARED_INIT
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_SHARED_INIT
#include "Rte_MemMap.h"
static volatile uint32 multi_core_cdd_dspi_guard_msr[50][CDD_DSPI_CORE_NUM] = {{ 0 }};
#define RTE_STOP_SEC_VAR_SHARED_INIT
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT
#include "Rte_MemMap.h"
static guard_type *sp_guard = &multi_core_cdd_dspi_guard[0][0];
#define RTE_STOP_SEC_VAR_INIT
#include "Rte_MemMap.h"

#define RTE_START_SEC_VAR_INIT
#include "Rte_MemMap.h"
static volatile uint32 *sp_guard_msr = &multi_core_cdd_dspi_guard_msr[0][0];
#define RTE_STOP_SEC_VAR_INIT
#include "Rte_MemMap.h"
#pragma pack (pop)
#endif
/*===================================================================================================
 *                                      LOCAL FUNCTION PROTOTYPES
 ====================================================================================================*/
/* allow module to enter the specific critical region */
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(VAR(uint16, RTE_VAR) n)
{
#ifndef CDD_DSPI_CRITICAL_SECTION_PROTECTION_UNUSED
    VAR(uint32, RTE_VAR) msr = 0UL;
    VAR(uint32, RTE_VAR) u32CoreId = (uint32)GetCoreID();
    VAR(uint32, RTE_VAR) u32GuardId = (uint32)(u32CoreId + (n * CDD_DSPI_CORE_NUM));
    if ((guard_type)0UL == sp_guard[u32GuardId]) /* polyspace RTE:IDP */
    {
        msr = (uint32)MFMSR();
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            SuspendAllInterrupts(); /* suspend All Interrupts */
        }
        sp_guard_msr[u32GuardId] = msr; /* polyspace RTE:IDP */
    }
    sp_guard[u32GuardId] ++;
#else
    (void)n;
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#endif

#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_SPINLOCK_AREA(VAR(uint16, RTE_VAR) n)
{
    VAR(uint32, RTE_VAR) u32GuardId = (uint32)(n * CDD_DSPI_CORE_NUM);
    while((guard_type)0UL != sp_guard[u32GuardId]);
    sp_guard[u32GuardId] = (guard_type)1UL; 
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#endif

#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SEMAPHORE)
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(VAR(uint16, RTE_VAR) n)
{
    VAR(uint32, RTE_VAR) msr = 0UL;
    VAR(status_t, RTE_VAR) status = STATUS_ERROR;
    VAR(uint32, RTE_VAR) u32GuardId = (uint32)(n * CDD_DSPI_CORE_NUM);
    VAR(uint32,   RTE_VAR) u32TimeOut = (uint32)RTE_SEM42_GATE_TIMEOUT;
    VAR(uint8,    RTE_VAR) u8CoreID = (uint8)GetCoreID();
    do {
        if (STATUS_SUCCESS == SEMA42_LockGate((SEMA42_Type *)SEMA42_BASE, (GATE_NUM)RTE_CDD_DSPI_SEMA42_GATE_ID, u8CoreID))
        {
            if (STATUS_SUCCESS == SEMA42_CheckLock((SEMA42_Type *)SEMA42_BASE, (GATE_NUM)RTE_CDD_DSPI_SEMA42_GATE_ID, u8CoreID, RTE_SEM42_GATE_TIMEOUT))
            {
                if ((guard_type)0UL == sp_guard[u32GuardId])
                {
                    msr = (uint32)MFMSR();
                    if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
                    {
                        SuspendAllInterrupts(); /* suspend All Interrupts */
                    }
                    sp_guard_msr[u32GuardId] = msr;
                    sp_guard[u32GuardId] = (guard_type)1UL;
                }
                status = STATUS_SUCCESS;
            }
            else
            {
                /* Check lock failed */
#if (RTE_SEM42_TIMEOUT_ENABLE == STD_ON) 
                if (RTE_SEM42GATE_TIMEOUT_HOOK != NULL_PTR) 
                {
                    RTE_SEM42GATE_TIMEOUT_HOOK((uint8)RTE_CDD_DSPI_SEMA42_GATE_ID);
                }
#endif
                break;
            }
            (void)SEMA42_UnlockGate((SEMA42_Type *)SEMA42_BASE, (GATE_NUM)RTE_CDD_DSPI_SEMA42_GATE_ID, u8CoreID);
        }
        else
        {
            /* Get lock failed */
            u32TimeOut--;
            if (u32TimeOut == 0U)
            {
#if (RTE_SEM42_TIMEOUT_ENABLE == STD_ON) 
                if (RTE_SEM42GATE_TIMEOUT_HOOK != NULL_PTR) 
                {
                    RTE_SEM42GATE_TIMEOUT_HOOK((uint8)RTE_CDD_DSPI_SEMA42_GATE_ID);
                }
#endif
                break;
            }
        }
    } while (status != STATUS_SUCCESS);
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#endif


/* allow module to exit the specific critical region */
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(VAR(uint16, RTE_VAR) n)
{
#ifndef CDD_DSPI_CRITICAL_SECTION_PROTECTION_UNUSED
    VAR(uint32, RTE_VAR) u32CoreId = (uint32)GetCoreID();
    VAR(uint32, RTE_VAR) u32GuardId = (uint32)(u32CoreId + (n * CDD_DSPI_CORE_NUM));
    sp_guard[u32GuardId] --; /* polyspace RTE:IDP */
    if ((ISR_ON(sp_guard_msr[u32GuardId])) && (sp_guard[u32GuardId] == (guard_type)0UL)) /* if interrupts were enabled */
    {
        ResumeAllInterrupts(); /* resume All Interrupts */
    }
#else
    (void)n;
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#endif

#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_SPINLOCK_AREA(VAR(uint16, RTE_VAR) n)
{
    sp_guard[n * CDD_DSPI_CORE_NUM] = (guard_type)0UL;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#endif

#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SEMAPHORE)
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(VAR(uint16, RTE_VAR) n)
{
    VAR(status_t, RTE_VAR) status = STATUS_ERROR;
    VAR(uint32,   RTE_VAR) u32GuardId = (uint32)(n * CDD_DSPI_CORE_NUM);
    VAR(uint32,   RTE_VAR) u32TimeOut = (uint32)RTE_SEM42_GATE_TIMEOUT;
    VAR(uint8,    RTE_VAR) u8CoreID = (uint8)GetCoreID();
    do {
        if (STATUS_SUCCESS == SEMA42_LockGate((SEMA42_Type *)SEMA42_BASE, (GATE_NUM)RTE_CDD_DSPI_SEMA42_GATE_ID, u8CoreID))
        {
            if (STATUS_SUCCESS == SEMA42_CheckLock((SEMA42_Type *)SEMA42_BASE, (GATE_NUM)RTE_CDD_DSPI_SEMA42_GATE_ID, u8CoreID, RTE_SEM42_GATE_TIMEOUT))
            {
                sp_guard[u32GuardId] = (guard_type)0UL;
                if (ISR_ON(sp_guard_msr[u32GuardId])) /* if interrupts were enabled */
                {
                    ResumeAllInterrupts(); /* resume All Interrupts */
                }
                status = STATUS_SUCCESS;
            }
            else
            {
                /* Check lock failed */
#if (RTE_SEM42_TIMEOUT_ENABLE == STD_ON) 
                if (RTE_SEM42GATE_TIMEOUT_HOOK != NULL_PTR) 
                {
                    RTE_SEM42GATE_TIMEOUT_HOOK((uint8)RTE_CDD_DSPI_SEMA42_GATE_ID);
                }
#endif
                break;
            }
            (void)SEMA42_UnlockGate((SEMA42_Type *)SEMA42_BASE, (GATE_NUM)RTE_CDD_DSPI_SEMA42_GATE_ID, u8CoreID);
        }
        else
        {
            /* Get lock failed */
            u32TimeOut--;
            if (u32TimeOut == 0U)
            {
#if (RTE_SEM42_TIMEOUT_ENABLE == STD_ON) 
                if (RTE_SEM42GATE_TIMEOUT_HOOK != NULL_PTR) 
                {
                    RTE_SEM42GATE_TIMEOUT_HOOK((uint8)RTE_CDD_DSPI_SEMA42_GATE_ID);
                }
#endif
                break;
            }
        }
    } while (status != STATUS_SUCCESS);
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#endif

/*===================================================================================================
 *                                       FUNCTION PROTOTYPES
 ====================================================================================================*/
/*================================================================================================*/
 /**
 * @brief   This function is called to allow cdd_dspi to enter the specific critical region.
 * @details All critical region define.
 *
 * @param[in]     void     No input parameters
 * @return        void     No return
 *
 * @pre  None
 * @post None
 *
 *================================================================================================*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_x(VAR(uint8, RTE_VAR) n)
{
    DEV_ASSERT(n < MULTICORE_CDD_DSPI_GUARD_NUM);
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(n);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(n);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(n);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_00(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(0);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(0);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(0);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_01(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(1);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(1);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(1);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_02(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(2);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(2);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(2);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_03(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(3);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(3);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(3);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_04(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(4);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(4);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(4);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_05(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(5);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(5);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(5);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_06(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(6);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(6);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(6);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_07(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(7);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(7);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(7);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_08(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(8);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(8);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(8);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_09(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(9);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(9);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(9);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_10(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(10);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(10);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(10);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_11(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(11);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(11);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(11);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_12(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(12);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(12);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(12);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_13(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(13);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(13);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(13);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_14(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(14);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(14);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(14);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_15(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(15);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(15);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(15);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_16(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(16);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(16);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(16);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_17(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(17);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(17);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(17);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_18(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(18);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(18);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(18);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_19(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(19);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(19);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(19);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_20(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(20);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(20);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(20);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_21(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(21);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(21);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(21);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_22(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(22);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(22);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(22);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_23(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(23);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(23);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(23);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_24(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(24);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(24);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(24);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_25(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(25);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(25);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(25);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_26(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(26);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(26);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(26);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_27(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(27);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(27);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(27);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_28(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(28);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(28);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(28);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_29(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(29);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(29);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(29);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_30(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(30);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(30);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(30);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_31(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(31);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(31);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(31);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_32(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(32);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(32);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(32);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_33(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(33);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(33);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(33);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_34(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(34);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(34);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(34);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_35(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(35);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(35);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(35);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_36(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(36);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(36);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(36);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_37(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(37);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(37);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(37);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_38(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(38);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(38);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(38);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_39(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(39);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(39);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(39);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_40(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(40);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(40);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(40);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_41(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(41);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(41);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(41);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_42(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(42);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(42);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(42);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_43(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(43);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(43);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(43);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_44(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(44);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(44);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(44);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_45(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(45);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(45);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(45);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_46(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(46);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(46);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(46);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_47(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(47);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(47);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(47);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_48(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(48);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(48);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(48);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_49(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_CDD_DSpi_SPINLOCK_AREA(49);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA(49);
#else
    SchM_Enter_CDD_DSpi_SEMAPHORE_AREA(49);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*================================================================================================*/
 /**
 * @brief   This function is called to allow cdd_dspi to exit the specific critical region.
 * @details All critical region define.
 *
 * @param[in]     void     No input parameters
 * @return        void     No return
 *
 * @pre  None
 * @post None
 *
 *================================================================================================*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_x(VAR(uint8, RTE_VAR) n)
{
    DEV_ASSERT(n < MULTICORE_CDD_DSPI_GUARD_NUM);
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(n);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(n);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(n);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_00(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(0);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(0);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(0);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_01(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(1);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(1);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(1);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_02(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(2);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(2);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(2);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_03(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(3);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(3);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(3);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_04(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(4);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(4);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(4);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_05(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(5);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(5);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(5);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_06(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(6);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(6);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(6);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_07(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(7);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(7);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(7);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_08(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(8);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(8);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(8);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_09(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(9);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(9);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(9);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_10(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(10);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(10);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(10);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_11(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(11);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(11);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(11);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_12(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(12);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(12);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(12);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_13(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(13);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(13);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(13);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_14(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(14);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(14);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(14);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_15(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(15);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(15);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(15);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_16(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(16);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(16);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(16);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_17(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(17);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(17);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(17);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_18(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(18);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(18);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(18);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_19(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(19);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(19);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(19);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_20(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(20);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(20);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(20);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_21(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(21);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(21);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(21);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_22(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(22);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(22);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(22);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_23(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(23);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(23);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(23);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_24(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(24);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(24);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(24);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_25(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(25);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(25);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(25);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_26(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(26);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(26);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(26);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_27(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(27);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(27);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(27);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_28(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(28);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(28);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(28);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_29(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(29);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(29);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(29);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_30(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(30);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(30);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(30);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_31(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(31);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(31);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(31);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_32(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(32);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(32);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(32);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_33(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(33);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(33);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(33);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_34(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(34);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(34);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(34);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_35(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(35);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(35);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(35);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_36(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(36);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(36);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(36);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_37(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(37);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(37);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(37);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_38(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(38);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(38);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(38);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_39(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(39);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(39);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(39);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_40(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(40);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(40);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(40);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_41(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(41);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(41);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(41);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_42(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(42);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(42);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(42);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_43(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(43);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(43);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(43);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_44(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(44);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(44);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(44);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_45(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(45);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(45);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(45);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_46(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(46);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(46);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(46);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_47(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(47);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(47);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(47);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_48(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(48);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(48);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(48);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_49(void)
{
#if (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_CDD_DSpi_SPINLOCK_AREA(49);
#elif (MULTICORE_CDD_DSPI_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA(49);
#else
    SchM_Exit_CDD_DSpi_SEMAPHORE_AREA(49);
#endif
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifdef __cplusplus
}
#endif

