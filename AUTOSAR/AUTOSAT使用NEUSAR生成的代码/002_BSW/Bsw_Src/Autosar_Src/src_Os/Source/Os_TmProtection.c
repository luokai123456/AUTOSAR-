/*
********************************************************************************
*
*  File name: Os_TmProtection.c
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.25
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: JiangGL/2023.01.09
* Change: Solve the bug that may trigger the interrupt before setting the HRT
*         comparison value and trigger the time protection by mistake.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2023.3.28
* Change: Remove redundant parameters.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2023.4.12
* Change: Modified the resource time protection judgment criteria.
* Cause: Bugfix
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2023.4.27
* Change: Resolve the issue of time protection false positives.
* Cause: Bugfix
********************************************************************************
* Version: 3.6
* Author/Date: LiG/2023.4.27
* Change: Resolve the issue of time protection triggering errors.
* Cause: Bugfix
********************************************************************************
* Version: 3.7
* Author/Date: LiuJJ/2023.5.25
* Change: Solve Os_Tp_StartNextBudget set comparevalue bug.
* Cause: Bugfix
********************************************************************************
* Version: 3.8
* Author/Date: JiangGL/2024.1.11
* Change: Fix a bug where the time parameter of the object driven by HRT cannot
*         exceed 1/2 of the maximum count value of the HRT.
* Cause: Bugfix
********************************************************************************
* Version: 3.9
* Author/Date: LiG/2023.6.29
* Change: Change the null judgment method.
* Cause: Bugfix
********************************************************************************
* Version: 3.10
* Author/Date: ZhangY/2024.6.13
* Change: Modify Os_Tp_SaveCurrenBudget.
* Cause: Bugfix
********************************************************************************
* Version: 3.11
* Author/Date: ShiZB/2024.7.15
* Change: Modify Os_Tp_StartLockBudget, add equal sign to determine diffValue.
* Cause: Bugfix
********************************************************************************
* Version: 3.12
* Author/Date: LiuZB/2025.2.26
* Change: Add function OS_TP_Reset_Current_Budget_Hook to function 
          Os_Tp_ResetCurrentBudget.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_TmProtection.h"
#include "Os_Core.h"
#include "Os_Isr.h"
#include "Os_Hook.h"

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
#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )

static FUNC(void, OS_CODE) Os_Tp_StartLockBudget
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) tpCfg,
    P2CONST(Os_TpBudgetCfgType, AUTOMATIC, OS_APPL_CONST) lockbudget,
    CoreIdType coreId
);
static FUNC(void, OS_CODE) Os_Tp_StopLockBudget
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) tpCfg,
    P2CONST(Os_TpBudgetCfgType, AUTOMATIC, OS_APPL_CONST) lockbudget,
    CoreIdType coreId
);
static FUNC(void, OS_CODE) Os_Tp_SetMaxCompare
(
    P2CONST(Os_CounterBaseCfgType, AUTOMATIC, OS_APPL_CONST) tpCnt
);

#endif  /* (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) */

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

#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
/*
********************************************************************************
* Function Name: Os_Tp_StartLockBudget
*
* Explanation: Start lock api time budget.
*
* Param: tpCfg: Time protection configuration data.
*        lockbudget:Lock api time budget.
*        coreId: Core logical index.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_Tp_StartLockBudget
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) tpCfg,
    P2CONST(Os_TpBudgetCfgType, AUTOMATIC, OS_APPL_CONST) lockbudget,
    CoreIdType coreId
)
{
    Os_TickType nowValue;
    Os_TickType compValue;
    Os_TickType diffValue;
    const Os_TpBudgetCfgType* currentBudget;

    nowValue = Os_Counter_HrtGetCntValue(tpCfg->tpCnt);
    if( tpCfg->dyn->tp_CurrentBudget != NULL_PTR )
    {
        currentBudget = tpCfg->dyn->tp_CurrentBudget;
        compValue = Os_Counter_HrtGetCompareValue(tpCfg->tpCnt);
        /* Calculate the margin of the current monitoring budget. */
        diffValue = OS_COUNTER_TICKSUB(tpCfg->tpCnt, compValue, nowValue);
        /* Judging that the currently monitored margin is greater than the
           lock api initial budget and less than the current monitored budget. */
        if( (lockbudget->tp_InitBudge < diffValue) &&
            (diffValue <= currentBudget->dyn->tp_RemainTime) )
        {
            currentBudget->dyn->tp_RemainTime = diffValue;
            lockbudget->dyn->tp_PrevBudget = currentBudget;
            lockbudget->dyn->tp_RemainTime = lockbudget->tp_InitBudge;
            tpCfg->dyn->tp_CurrentBudget = lockbudget;
            compValue = OS_COUNTER_TICKADD(tpCfg->tpCnt, nowValue, lockbudget->tp_InitBudge);
            Os_Counter_HrtSetCompareValue(tpCfg->tpCnt, compValue, nowValue);
            OS_CORE_SETTPCURRENTBUDGET(coreId, lockbudget);
        }
    }
    else
    {
        lockbudget->dyn->tp_PrevBudget = NULL_PTR;
        lockbudget->dyn->tp_RemainTime = lockbudget->tp_InitBudge;
        tpCfg->dyn->tp_CurrentBudget = lockbudget;
        compValue = OS_COUNTER_TICKADD(tpCfg->tpCnt, nowValue, lockbudget->tp_InitBudge);
        Os_Counter_HrtSetCompareValue(tpCfg->tpCnt, compValue, nowValue);
        OS_CORE_SETTPCURRENTBUDGET(coreId, lockbudget);
    }
}

/*
********************************************************************************
* Function Name: Os_Tp_StopLockBudget
*
* Explanation: Stop lock api time budget.
*
* Param: tpCfg: Time protection configuration data.
*        lockbudget:Lock api time budget.
*        coreId: Core logical index.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_Tp_StopLockBudget
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) tpCfg,
    P2CONST(Os_TpBudgetCfgType, AUTOMATIC, OS_APPL_CONST) lockbudget,
    CoreIdType coreId
)
{
    Os_TickType nowValue;
    Os_TickType passedVlaue;
    Os_TickType diffValue;
    Os_TickType compValue;
    Os_TickType newCompValue;
    const Os_TpBudgetCfgType* prevBudget;

    if( tpCfg->dyn->tp_CurrentBudget == lockbudget )
    {
        if( NULL_PTR != lockbudget->dyn->tp_PrevBudget )
        {
            prevBudget = lockbudget->dyn->tp_PrevBudget;
            nowValue = Os_Counter_HrtGetCntValue(tpCfg->tpCnt);
            compValue = Os_Counter_HrtGetCompareValue(tpCfg->tpCnt);
            diffValue = OS_COUNTER_TICKSUB(tpCfg->tpCnt, compValue, nowValue);
            /* Calculate the actual consumption time of the currently monitored api time budget. */
            passedVlaue = lockbudget->tp_InitBudge - diffValue;
            /* Determine whether the remaining time in the current budget is greater than the actual consumption time. */
            if( prevBudget->dyn->tp_RemainTime > passedVlaue )
            {
                prevBudget->dyn->tp_RemainTime -= passedVlaue;
            }
            else
            {
                prevBudget->dyn->tp_RemainTime = 0U;
            }
            newCompValue = OS_COUNTER_TICKADD(tpCfg->tpCnt, nowValue, prevBudget->dyn->tp_RemainTime);
            Os_Counter_HrtSetCompareValue(tpCfg->tpCnt, newCompValue, nowValue);
            tpCfg->dyn->tp_CurrentBudget = prevBudget;
            OS_CORE_SETTPCURRENTBUDGET(coreId, prevBudget);
        }
        else
        {
            tpCfg->dyn->tp_CurrentBudget = NULL_PTR;
            OS_CORE_SETTPCURRENTBUDGET(coreId, NULL_PTR);
        }
    }
}

/*
********************************************************************************
* Function Name: Os_Tp_SetMaxCompare
*
* Explanation: Set max compare value.
*
* Param: tpCnt: Time protection counter.
*
* Retval: None
********************************************************************************
*/
static FUNC(void, OS_CODE) Os_Tp_SetMaxCompare
(
    P2CONST(Os_CounterBaseCfgType, AUTOMATIC, OS_APPL_CONST) tpCnt
)
{
    Os_TickType nowValue;
    Os_TickType compareValue;

    nowValue = Os_Counter_HrtGetCntValue(tpCnt);
    compareValue = OS_COUNTER_TICKADD(tpCnt, nowValue, OS_COUNTER_GET_HALF_MAXVALUE(tpCnt));
    Os_Counter_HrtSetCompareValue(tpCnt, compareValue, nowValue);
}

/*
********************************************************************************
* Function Name: Os_Tp_BaseInit
*
* Explanation: Time protection core init.
*
* Param: tpBaseCfg: Core time protection configuration data.
*        coreId: Core logical index.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Tp_BaseInit
(
    P2CONST(Os_TpBaseCfgType, AUTOMATIC, OS_APPL_CONST) tpBaseCfg,
    CoreIdType coreId
)
{
    /* Check the tpBaseCfg is not NULL_PTR. */
    Os_ParamCheck(NULL_PTR != tpBaseCfg);
    /* Check the tp_BudgetKind is not NULL_PTR. */
    Os_ParamCheck(NULL_PTR != tpBaseCfg->dyn);

    OS_CORE_SETTPCURRENTBUDGET(coreId, NULL_PTR);
}

/*
********************************************************************************
* Function Name: Os_Tp_BaseStart
*
* Explanation: Time protection start .
*
* Param: tpBaseCfg: Core time protection configuration data.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Tp_BaseStart
(
    P2CONST(Os_TpBaseCfgType, AUTOMATIC, OS_APPL_CONST) tpBaseCfg
)
{
    /* Check the tpBaseCfg is not NULL_PTR. */
    Os_ParamCheck(NULL_PTR != tpBaseCfg);
    /* Check the tp_BudgetKind is not NULL_PTR. */
    Os_ParamCheck(NULL_PTR != tpBaseCfg->tpCnt);

    /* Initialize and start the time protection timer. */
    Os_Counter_HrtInit(tpBaseCfg->tpCnt);
    Os_Counter_HrtClearInterrupt(tpBaseCfg->tpCnt);
    Os_Tp_SetMaxCompare(tpBaseCfg->tpCnt);
    Os_Counter_Start(tpBaseCfg->tpCnt);
}

/*
********************************************************************************
* Function Name: Os_Tp_Init
*
* Explanation: Time protection init.
*
* Param: tpCfg: Time protection configuration data.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Tp_Init
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) tpCfg
)
{
    /* Check the tpCfg is not NULL_PTR. */
    Os_ParamCheck(NULL_PTR != tpCfg);
    Os_ParamCheck(NULL_PTR != tpCfg->dyn);

    if( tpCfg->tp_TimeFrame != NULL_PTR )
    {
        tpCfg->tp_TimeFrame->dyn->tp_timeFrameState = OS_TMPROTECTION_TIMEFRAME_OFF;
    }

    if( tpCfg->tp_ExecBudget != NULL_PTR )
    {
        tpCfg->tp_ExecBudget->dyn->tp_RemainTime = tpCfg->tp_ExecBudget->tp_InitBudge;
        tpCfg->dyn->tp_CurrentBudget = tpCfg->tp_ExecBudget;
    }
    else
    {
        tpCfg->dyn->tp_CurrentBudget = NULL_PTR;
    }
}

/*
********************************************************************************
* Function Name: Os_Tp_SaveCurrenBudget
*
* Explanation: Save current time protection budget.
*
* Param: currentTpCfg: Current time protection configuration data.
*        coreId: Core logical index.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Tp_SaveCurrenBudget
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) currentTpCfg,
    CoreIdType coreId
)
{
    Os_TickType nowValue;
    Os_TickType compValue;
    Os_TickType diffValue;
    const Os_TpBudgetCfgType* currentBudget;

    /* Check the TpCfg is not NULL_PTR. */
    Os_ParamCheck(NULL_PTR != currentTpCfg);

    nowValue = Os_Counter_HrtGetCntValue(currentTpCfg->tpCnt);
    currentBudget = currentTpCfg->dyn->tp_CurrentBudget;

    if( currentBudget != NULL_PTR )
    {
        compValue = Os_Counter_HrtGetCompareValue(currentTpCfg->tpCnt);
        diffValue = OS_COUNTER_TICKSUB(currentTpCfg->tpCnt, compValue, nowValue);

        if( currentBudget->dyn->tp_RemainTime >= diffValue )
        {
            currentBudget->dyn->tp_RemainTime = diffValue;
        }
        else
        {
            currentBudget->dyn->tp_RemainTime = 0U;
        }
    }
    OS_CORE_SETTPCURRENTBUDGET(coreId, NULL_PTR);
}

/*
********************************************************************************
* Function Name: Os_Tp_ResetCurrentBudget
*
* Explanation: Reset current time protection budget.
*
* Param: currentTpCfg: Current time protection configuration data.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Tp_ResetCurrentBudget
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) currentTpCfg,
    CoreIdType coreId
)
{
    /* Check the TpCfg is not NULL_PTR. */
    Os_ParamCheck(NULL_PTR != currentTpCfg);

    if( currentTpCfg->tp_ExecBudget != NULL_PTR )
    {
        currentTpCfg->tp_ExecBudget->dyn->tp_RemainTime = currentTpCfg->tp_ExecBudget->tp_InitBudge;
#ifdef OS_TEST_ENABLE
        OS_TP_Reset_Current_Budget_Hook(currentTpCfg);
#endif
        currentTpCfg->dyn->tp_CurrentBudget = currentTpCfg->tp_ExecBudget;
    }
    else
    {
        currentTpCfg->dyn->tp_CurrentBudget = NULL_PTR;
    }
    OS_CORE_SETTPCURRENTBUDGET(coreId, NULL_PTR);
}

/*
********************************************************************************
* Function Name: Os_Tp_StartNextBudget
*
* Explanation: Satrt next time protection budget.
*
* Param: nextTpCfg: Next time protection configuration data.
*        coreId: Core logical index.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Tp_StartNextBudget
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) nextTpCfg,
    CoreIdType coreId
)
{
    Os_TickType nowValue;
    Os_TickType compValue;
    const Os_TpBudgetCfgType* nextBudget;
    /* Check the TpCfg is not NULL_PTR. */
    Os_ParamCheck(NULL_PTR != nextTpCfg);

    nextBudget = nextTpCfg->dyn->tp_CurrentBudget;
    /*Start the next executive budget.*/
    if( nextBudget != NULL_PTR )
    {
        nowValue = Os_Counter_HrtGetCntValue(nextTpCfg->tpCnt);
        compValue = OS_COUNTER_TICKADD(nextTpCfg->tpCnt, nowValue, nextBudget->dyn->tp_RemainTime);
        Os_Counter_HrtSetCompareValue(nextTpCfg->tpCnt, compValue, nowValue);
    }
    else
    {
        Os_Tp_SetMaxCompare(nextTpCfg->tpCnt);
    }

    Os_Counter_HrtClearInterrupt(nextTpCfg->tpCnt);
    OS_CORE_SETTPCURRENTBUDGET(coreId, nextBudget);
}

/*
********************************************************************************
* Function Name: Os_Tp_StartAllIntBudget
*
* Explanation: Start AllInterrupts api time protection lock budget.
*
* Param: tpCfg: Time protection configuration data.
*        coreId: Core logical index.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Tp_StartAllIntBudget
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) tpCfg,
    CoreIdType coreId
)
{
    /* Check the tpCfg is not NULL_PTR. */
    if( (NULL_PTR != tpCfg) && (tpCfg->tp_AllIntLockBudget != NULL_PTR) )
    {
        Os_Tp_StartLockBudget(tpCfg, tpCfg->tp_AllIntLockBudget, coreId);
    }
}

/*
********************************************************************************
* Function Name: Os_Tp_StopAllIntBudget
*
* Explanation: Stop AllInterrupts api time protection lock budget.
*
* Param: tpCfg: Time protection configuration data.
*        coreId: Core logical index.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Tp_StopAllIntBudget
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) tpCfg,
    CoreIdType coreId
)
{
    /* Check the tpCfg is not NULL_PTR. */
    if( (NULL_PTR != tpCfg) && (tpCfg->tp_AllIntLockBudget != NULL_PTR) )
    {
        Os_Tp_StopLockBudget(tpCfg,tpCfg->tp_AllIntLockBudget, coreId);
    }
}

/*
********************************************************************************
* Function Name: Os_Tp_StartOsIntBudget
*
* Explanation: Start OsInterrupts api time protection lock budget.
*
* Param: tpCfg: Time protection configuration data.
*        coreId: Core logical index.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Tp_StartOsIntBudget
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) tpCfg,
    CoreIdType coreId
)
{
    /* Check the tpCfg is not NULL_PTR. */
    if( (NULL_PTR != tpCfg) && (tpCfg->tp_OsIntLockBudget != NULL_PTR) )
    {
        Os_Tp_StartLockBudget(tpCfg, tpCfg->tp_OsIntLockBudget, coreId);
    }
}

/*
********************************************************************************
* Function Name: Os_Tp_StopOsIntBudget
*
* Explanation: Stop OsInterrupts api time protection lock budget.
*
* Param: tpCfg: Time protection configuration data.
*        coreId: Core logical index.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Tp_StopOsIntBudget
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) tpCfg,
    CoreIdType coreId
)
{
    /* Check the tpCfg is not NULL_PTR. */
    if( (NULL_PTR != tpCfg) && (tpCfg->tp_OsIntLockBudget != NULL_PTR) )
    {
        Os_Tp_StopLockBudget(tpCfg, tpCfg->tp_OsIntLockBudget, coreId);
    }
}

/*
********************************************************************************
* Function Name: Os_Tp_StartResBudget
*
* Explanation: Start resource api time protection lock budget.
*
* Param: tpCfg: Time protection configuration data.
*        resId: Resource index.
*        coreId: Core logical index.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Tp_StartResBudget
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) tpCfg,
    ResourceType resId,
    CoreIdType coreId
)
{
    /* Check the tpCfg is not NULL_PTR. */
    Os_ParamCheck(NULL_PTR != tpCfg);

    if( NULL_PTR != tpCfg->tp_ResLockBudgetRefs )
    {
        if( tpCfg->tp_ResLockBudgetRefs[resId] != NULL_PTR )
        {
            Os_Tp_StartLockBudget(tpCfg, tpCfg->tp_ResLockBudgetRefs[resId], coreId);
        }
    }
}

/*
********************************************************************************
* Function Name: Os_Tp_StopResBudget
*
* Explanation: Stop resource api time protection lock budget.
*
* Param: tpCfg: Time protection configuration data.
*        resId: Resource index.
*        coreId: Core logical index.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Tp_StopResBudget
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) tpCfg,
    ResourceType resId,
    CoreIdType coreId
)
{
    /* Check the tpCfg is not NULL_PTR. */
    Os_ParamCheck(NULL_PTR != tpCfg);

    if( NULL_PTR != tpCfg->tp_ResLockBudgetRefs )
    {
        if( tpCfg->tp_ResLockBudgetRefs[resId] != NULL_PTR )
        {
            Os_Tp_StopLockBudget(tpCfg, tpCfg->tp_ResLockBudgetRefs[resId], coreId);
        }
    }
}

/*
********************************************************************************
* Function Name: Os_Tp_Handler
*
* Explanation: Time protection timer interrupt handler.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
OS_ISR(Os_Tp_Handler)
{
    CoreIdType coreId;
    ISRType isrId;
    CounterType cntId;
    const Os_CounterBaseCfgType* counterBaseCfg;
    const Os_TpBudgetCfgType* tp_CurrentBudget;

    /* Get logic core id */
    coreId = Os_Core_GetLogicId();
    /* Get isr id */
    isrId = OS_CORE_GETCURRENTISRID(coreId);
    /* If it is a timer interrupter */
    if( OS_ISR_ISTIMER(isrId) )
    {
        /* Get counter id. */
        cntId = OS_ISR_GETCNTID(isrId);
        counterBaseCfg = OS_COUNTER_GETCFG(cntId);
        tp_CurrentBudget = OS_CORE_GETTPCURRENTBUDGET(coreId);

        if( tp_CurrentBudget != NULL_PTR )
        {
            switch( tp_CurrentBudget->tp_BudgetKind )
            {
                case OS_TMPROTECTION_NONE:
                     Os_Tp_SetMaxCompare(counterBaseCfg);
                     break;
                case OS_TMPROTECTION_EXEC:
                     Os_Hook_CallProtectionHook(E_OS_PROTECTION_TIME);
                     break;
                case OS_TMPROTECTION_LOCK:
                     Os_Hook_CallProtectionHook(E_OS_PROTECTION_LOCKED);
                     break;
                default:
                     Os_FatalError();
                     break;
            }
        }
        else
        {
            Os_Tp_SetMaxCompare(counterBaseCfg);
        }
        Os_Counter_HrtClearInterrupt(counterBaseCfg);
    }

}
#endif /* #if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) ) */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
