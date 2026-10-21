/*
********************************************************************************
*
* File name: NeuLib_Timer.c
*
* Copyright 2023-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: ZhangDX/2023.08.01
* Change: New
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: TianG/2024.10.12
* Change: 1.Modify memory-map label error.
*         2.Modify copyright.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: KangJH/2025.03.26
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: KangJH/2025.03.28
* Change: Fix some QAC warnings and remove comments.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: KangJH/2025.05.22
* Change: Fix the polyspace warning and add the polyspace deviation suppression
*         comment.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: KangJH/2025.06.17
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: KangJH/2025.06.23
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#include "NeuLib_Timer.h"
#include "NeuLib_Service.h"
#include "NeuLib_Def.h"
#include "NeuLib.h"

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
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NEULIB_START_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"

/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NEULIB_STOP_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"

/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NEULIB_START_SEC_CONST
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NeuLib_UsedNonSharedVariable" */
static CONST(NeuLibTick_Type, NEULIB_CONST) NeuLibTickMax = NEULIB_TICK_MAX / NEULIB_SHIFT_2;

/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NEULIB_STOP_SEC_CONST
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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
#define NEULIB_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/*
********************************************************************************
* Function Name: NeuLibTimer_Init
*
* Explanation:   Initialize the software timer.
* (Synchronous)
*
* param:         desc      Memory pool descriptor.
*                timerList Soft timer list .
*
* retval:        None
********************************************************************************
*/
FUNC(void, NEULIB_CODE) NeuLibTimer_Init(  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
    P2CONST(NeuLibMemPoolDesc_Type, AUTOMATIC, NEULIB_APPL_CONST) desc,
    P2VAR(NeuLibList_Type, AUTOMATIC, NEULIB_APPL_DATA) timerList
)
{
    NeuLibMemPool_Init(desc);
    NeuLibList_Init(timerList);
}

/*
********************************************************************************
* Function Name: NeuLibTimer_Create
*
* Explanation:   This function will create a timer
* (Synchronous)
*
* param:         name      The timer name.
*                desc      Memory pool descriptor.
*                timeout   Is the timeout function.
*                parameter Is the parameter of timeout function.
*                time      Is timeout ticks of the timer.
*                flag      The flag of timer. eg: NEULIB_TIMER_FLAG_PERIODIC.
*
* retval:        The created timer object.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:15.5 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule15.5" */
FUNC_P2VAR(NeuLibTimer_Type, NEULIB_APPL_DATA, NEULIB_CODE) NeuLibTimer_Create(  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
    P2CONST(char, AUTOMATIC, NEULIB_APPL_CONST) name,
    P2CONST(NeuLibMemPoolDesc_Type, AUTOMATIC, NEULIB_APPL_CONST) desc,
    NeuTimeOutFunc_Type timeout,
    P2VAR(void, AUTOMATIC, NEULIB_APPL_DATA) parameter,
    NeuLibTick_Type timeCount,
    uint8 flag
)
{
    NeuLibTimer_Type *timer;

    /* Allocate the timer object. */
    /* polyspace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" */
    timer = (NeuLibTimer_Type *)NeuLibMemPool_Malloc(desc);  /* PRQA S 0316 */ /* NSCA_QAC_NeuLib_Rule11.5 */
    if (NULL_PTR == timer)
    {
        return NULL_PTR;
    }

    NeuLib_memset(timer, 0u, sizeof(NeuLibTimer_Type));
    timer->timeoutFunc  = timeout;
    timer->parameter    = parameter;

    timer->flag         = flag;
    timer->initTick     = timeCount;
    timer->timeoutTick  = 0u;

    /* initialize timer list */
    NeuLibList_Init(&timer->row);

#ifdef NEU_DEBUG
    NeuLib_memcpy(timer->name, name, NeuLib_strlen(name));
#else
    NEU_UNUSED_ARG(name);
#endif  /* NEU_DEBUG */

    return timer;
}

/*
********************************************************************************
* Function Name: NeuLibTimer_Delete
*
* Explanation:   This function will delete a timer and release timer memory.
* (Synchronous)
*
* param:         desc  Memory pool descriptor.
*                timer The timer to be deleted.
*
* retval:        Always E_OK.
********************************************************************************
*/
FUNC(Std_ReturnType, NEULIB_CODE) NeuLibTimer_Delete(  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
    P2CONST(NeuLibMemPoolDesc_Type, AUTOMATIC, NEULIB_APPL_CONST) desc,
    P2VAR(NeuLibTimer_Type, AUTOMATIC, NEULIB_APPL_DATA) timer
)
{
    NEULIB_SYS_ARCH_DECL_PROTECT(level);

    /* parameter check */
    NEULIB_ASSERT_MSG("NeuLibTimer", "", timer != NULL_PTR);

    /* disable interrupt */
    NEULIB_SYS_ARCH_PROTECT(level);

    NeuLibList_Remove(&timer->row);

    /* enable interrupt */
    NEULIB_SYS_ARCH_UNPROTECT(level);

    /* Free the timer object. */
    NeuLibMemPool_Free(desc, timer);

    return E_OK;
}

/*
********************************************************************************
* Function Name: NeuLibTimer_Start
*
* Explanation:   This function will start the timer.
* (Synchronous)
*
* param:         getTick   Retrieves the specified timer heartbeat value.
*                timer     The timer to be started
*                timerList Soft timer list.
*
* retval:        The operation status, E_OK on OK.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, NEULIB_CODE) NeuLibTimer_Start(  /* PRQA S 1505 */ /* NSCA_QAC_Common_Rule8.7 */
    NeuLibTimeGetTick_Type getTick,
    P2VAR(NeuLibTimer_Type, AUTOMATIC, NEULIB_APPL_DATA) timer,
    P2VAR(NeuLibList_Type, AUTOMATIC, NEULIB_APPL_DATA)  timerList
)
{
    NeuLibList_Type *rowHead;

    NEULIB_SYS_ARCH_DECL_PROTECT(level);

    /* parameter check */
    NEULIB_ASSERT_MSG("NeuLibTimer", "", timer != NULL_PTR);
    NEULIB_ASSERT_MSG("NeuLibTimer", "", getTick != NULL_PTR);
    NEULIB_ASSERT_MSG("NeuLibTimer", "", timerList != NULL_PTR);

    /* stop timer firstly */
    NEULIB_SYS_ARCH_PROTECT(level);

    /* Remove timer from list. */
    NeuLibList_Remove(&timer->row);
    /* change status of timer */
    /* polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_NeuLib_UINT_CONSTANT_OVFL" */
    timer->flag &= (uint8)(~NEULIB_TIMER_FLAG_ACTIVATED);

    /* polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_NeuLib_UninitializedVariable" */
    timer->timeoutTick = getTick() + timer->initTick;

    for (rowHead = timerList; rowHead != timerList->prev; rowHead = rowHead->next)
    {
        NeuLibTimer_Type *t;
        /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_NeuLib_UNMODIFIED_VAR_NOT_CONST" polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_NeuLib_UninitializedPointer" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" */
        NeuLibList_Type *p = rowHead->next;

        /* fix up the entry pointer */
        t = NeuLibList_Entry(p, NeuLibTimer_Type, row);  /* PRQA S 0306, 0310, 0488, 3305 */ /* NSCA_QAC_NeuLib_PointerCast, NSCA_QAC_NeuLib_Rule11.3, NSCA_QAC_NeuLib_Rule18.4, NSCA_QAC_NeuLib_Rule11.3 */

        /**
         * If we have two timers that timeout at the same time, it's
         * preferred that the timer inserted early get called early.
         * So insert the new timer to the end the the some-timeout timer
         * list.
         */
        /* polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_NeuLib_UninitializedVariable" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        if ((t->timeoutTick - timer->timeoutTick) == 0U)
        {
            continue;
        }
        else if ((t->timeoutTick - timer->timeoutTick) < NeuLibTickMax)
        {
            break;
        }
        else
        {
            /* Do nothing. */
        }
    }

    NeuLibList_InsertAfter(rowHead, &timer->row);

    timer->flag |= NEULIB_TIMER_FLAG_ACTIVATED;
    /* enable interrupt */
    NEULIB_SYS_ARCH_UNPROTECT(level);

    return E_OK;
}

/*
********************************************************************************
* Function Name: NeuLibTimer_Stop
*
* Explanation:   This function will stop the timer.
* (Synchronous)
*
* param:         timer The timer to be stopped.
*
* retval:        None
********************************************************************************
*/
FUNC(Std_ReturnType, NEULIB_CODE) NeuLibTimer_Stop(  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
    P2VAR(NeuLibTimer_Type, AUTOMATIC, NEULIB_APPL_DATA) timer
)
{
    NEULIB_SYS_ARCH_DECL_PROTECT(level);

    /* parameter check */
    NEULIB_ASSERT_MSG("NeuLibTimer", "", timer != NULL_PTR);

    /* disable interrupt */
    NEULIB_SYS_ARCH_PROTECT(level);

    NeuLibList_Remove(&timer->row);

    /* enable interrupt */
    NEULIB_SYS_ARCH_UNPROTECT(level);

    return E_OK;
}

/*
********************************************************************************
* Function Name: NeuLibTimer_Entry
*
* Explanation:   Software timer thread entry.
* (Synchronous)
*
* param:         getTick   Retrieves the specified timer heartbeat value.
*                timerList Is the array of time list.
*
* retval:        None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:15.5 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule15.5" */
FUNC(void, NEULIB_CODE) NeuLibTimer_Entry(  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
    NeuLibTimeGetTick_Type getTick,
    P2VAR(NeuLibList_Type, AUTOMATIC, NEULIB_APPL_DATA)  timerList
)
{
    NeuLibTick_Type currentTick;
    NeuLibTimer_Type *t;
    NeuLibList_Type list;
    NEULIB_SYS_ARCH_DECL_PROTECT(level);

    /* get the next timeout tick */
    if( NEULIB_NOT_OK == NeuLibList_IsEmpty(timerList) )
    {
        /* no software timer exist, suspend self. */
        return ;
    }

    NeuLibList_Init(&list);
        /* polyspace +1 MISRA-C3:1.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule1.3" */
    NEULIB_DEBUG_LOG("NeuLibTimer", ("software timer check enter\n"));  /* PRQA S 1035 */ /* NSCA_QAC_NeuLib_Rule1.2 */

    /* Disable interrupt. */
    NEULIB_SYS_ARCH_PROTECT(level);

    while( NEULIB_E_OK == NeuLibList_IsEmpty(timerList) )
    {
        t = NeuLibList_Entry(timerList->next, NeuLibTimer_Type, row);  /* PRQA S 0306, 0310, 0488, 3305 */ /* NSCA_QAC_NeuLib_PointerCast, NSCA_QAC_NeuLib_Rule11.3, NSCA_QAC_NeuLib_Rule18.4, NSCA_QAC_NeuLib_Rule11.3 */

        currentTick = getTick();

        /* It supposes that the new tick shall less than the half duration of tick max. */
            /* polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_NeuLib_UninitializedVariable" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        if ((currentTick - t->timeoutTick) < NeuLibTickMax)
        {

            /* Remove timer from timer list firstly. */
            NeuLibList_Remove(&t->row);

            /* Add timer to temporary list.  */
            NeuLibList_InsertAfter(&list, &t->row);

            /* Enable interrupt */
            NEULIB_SYS_ARCH_UNPROTECT(level);

            /* Call timeout function. */
                /* polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_NeuLib_UninitializedPointer" polyspace +1 RTE:COR [Justified:Unset] "NSCA_Polyspace_NeuLib_NullPointer" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" */
            t->timeoutFunc(t->parameter);
                /* polyspace +1 MISRA-C3:1.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule1.3" */
            NEULIB_DEBUG_LOG("NeuLibTimer", ("current tick: %d\n", currentTick));  /* PRQA S 1035 */ /* NSCA_QAC_NeuLib_Rule1.2 */

            /* Disable interrupt. */
            NEULIB_SYS_ARCH_PROTECT(level);

            /* Check whether the timer object is detached or started again. */
            if( NEULIB_NOT_OK == NeuLibList_IsEmpty(&list) )
            {
                continue;
            }
            NeuLibList_Remove(&t->row);

                /* polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_NeuLib_UninitializedVariable" */
            if( ((t->flag & NEULIB_TIMER_FLAG_PERIODIC) != NEULIB_CNT_0) &&
                ((t->flag & NEULIB_TIMER_FLAG_ACTIVATED) != NEULIB_CNT_0) )
            {
                /* Start it. */
                    /* polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_NeuLib_UINT_CONSTANT_OVFL" */
                t->flag &= (uint8)(~NEULIB_TIMER_FLAG_ACTIVATED);
                (void)NeuLibTimer_Start(getTick, t, timerList);
            }
        }
        else
        {
            break; /* not check anymore */
        }
    }
    /* enable interrupt */
    NEULIB_SYS_ARCH_UNPROTECT(level);

        /* polyspace +1 MISRA-C3:1.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule1.3" */
        NEULIB_DEBUG_LOG("NeuLibTimer", ("software timer check leave\n"));  /* PRQA S 1035 */ /* NSCA_QAC_NeuLib_Rule1.2 */
}

#define NEULIB_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
