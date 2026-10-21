/*
********************************************************************************
*
*  File name: Os_TimingProtection.h
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
* Author/Date: WangJP/2022.12.10
* Change: Modification of coding standard.
* Cause: Optimize
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: JiangGL/2024.03.04
* Change: Solve the problem of still responding to interrupts after triggering
*         time interval protection for Class II interrupts.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2023.4.15
* Change: Adapted to GCC compiler.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: LiuZB/2025.2.26
* Change: 1. Add function OS_TP_Frame_Interval_Hook to function
*            Os_Tp_CheckFrameInterval.
*         2. Add function OS_TP_IsrFrame_Interval_Hook to function
*            Os_Tp_IsrCheckFrameInterval.
* Cause: Update
********************************************************************************
*/
#ifndef OS_TMPROTECTION_H_
#define OS_TMPROTECTION_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_TmProtection_Types.h"
#include "Os_TmProtection_Def.h"
#include "Os_Counter.h"
#include "Os_Hook.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
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
#define OS_START_SEC_CODE
#include "Os_MemMap.h"

#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
/*
********************************************************************************
* Function Name: Os_Tp_CheckFrameInterval
*
* Explanation: Time protection detection frame interval.
*
* Param: tpCfg: Time protection configuration data.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(boolean, OS_CODE) Os_Tp_CheckFrameInterval
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) tpCfg
)
{
    Os_TickType nowValue;
    Os_TickType timePassed;
    boolean ret = TRUE;

    /* Check the tpCfg is not NULL_PTR. */
    Os_ParamCheck(tpCfg != NULL_PTR);

    if( NULL_PTR != tpCfg->tp_TimeFrame )
    {
        nowValue = Os_Counter_HrtGetCntValue(tpCfg->tpCnt);
        if( OS_TMPROTECTION_TIMEFRAME_ON == tpCfg->tp_TimeFrame->dyn->tp_timeFrameState )
        {
            timePassed = OS_COUNTER_TICKSUB(tpCfg->tpCnt, nowValue,
                                            tpCfg->tp_TimeFrame->dyn->tp_LastTime);
#ifdef OS_TEST_ENABLE
            OS_TP_Frame_Interval_Hook(tpCfg, nowValue);
#endif
            if( timePassed < tpCfg->tp_TimeFrame->tp_InitTimeFrame )
            {
                ret = FALSE;
                Os_Hook_CallProtectionHook(E_OS_PROTECTION_ARRIVAL);
            }

        }
        else
        {
            tpCfg->tp_TimeFrame->dyn->tp_timeFrameState = OS_TMPROTECTION_TIMEFRAME_ON;
        }
        tpCfg->tp_TimeFrame->dyn->tp_LastTime = nowValue;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_Tp_IsrCheckFrameInterval
*
* Explanation: Time protection detection frame interval.
*
* Param: tpCfg: Time protection configuration data.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(boolean, OS_CODE) Os_Tp_IsrCheckFrameInterval
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) tpCfg
)
{
    Os_TickType nowValue;
    Os_TickType timePassed;
    boolean ret = TRUE;

    /* Check the tpCfg is not NULL_PTR. */
    Os_ParamCheck(tpCfg != NULL_PTR);

    if( NULL_PTR != tpCfg->tp_TimeFrame )
    {
        nowValue = Os_Counter_HrtGetCntValue(tpCfg->tpCnt);
        if( OS_TMPROTECTION_TIMEFRAME_ON == tpCfg->tp_TimeFrame->dyn->tp_timeFrameState )
        {
            timePassed = OS_COUNTER_TICKSUB(tpCfg->tpCnt, nowValue,
                                            tpCfg->tp_TimeFrame->dyn->tp_LastTime);
#ifdef OS_TEST_ENABLE
            OS_TP_IsrFrame_Interval_Hook(tpCfg, nowValue);
#endif
            if( timePassed < tpCfg->tp_TimeFrame->tp_InitTimeFrame )
            {
                ret = FALSE;
                Os_Hook_CallProtectionHook(E_OS_PROTECTION_ARRIVAL);
            }
            else
            {
                tpCfg->tp_TimeFrame->dyn->tp_LastTime = nowValue;
            }
        }
        else
        {
            tpCfg->tp_TimeFrame->dyn->tp_timeFrameState = OS_TMPROTECTION_TIMEFRAME_ON;
            tpCfg->tp_TimeFrame->dyn->tp_LastTime = nowValue;
        }
    }

    return ret;
}
#endif

extern FUNC(void, OS_CODE) Os_Tp_BaseInit
(
    P2CONST(Os_TpBaseCfgType, AUTOMATIC, OS_APPL_CONST) tpBaseCfg,
    CoreIdType coreId
);
extern FUNC(void, OS_CODE) Os_Tp_BaseStart
(
    P2CONST(Os_TpBaseCfgType, AUTOMATIC, OS_APPL_CONST) tpBaseCfg
);
extern FUNC(void, OS_CODE) Os_Tp_Init
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) tpCfg
);
FUNC(void, OS_CODE) Os_Tp_SaveCurrenBudget
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) currentTpCfg,
    CoreIdType coreId
);
FUNC(void, OS_CODE) Os_Tp_ResetCurrentBudget
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) currentTpCfg,
    CoreIdType coreId
);
extern FUNC(void, OS_CODE) Os_Tp_StartNextBudget
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) nextTpCfg,
    CoreIdType coreId
);
extern FUNC(void, OS_CODE) Os_Tp_StartAllIntBudget
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) tpCfg,
    CoreIdType coreId
);
extern FUNC(void, OS_CODE) Os_Tp_StopAllIntBudget
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) tpCfg,
    CoreIdType coreId
);
extern FUNC(void, OS_CODE) Os_Tp_StartOsIntBudget
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) tpCfg,
    CoreIdType coreId
);
extern FUNC(void, OS_CODE) Os_Tp_StopOsIntBudget
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) tpCfg,
    CoreIdType coreId
);
extern FUNC(void, OS_CODE) Os_Tp_StartResBudget
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) tpCfg,
    ResourceType resId,
    CoreIdType coreId
);
extern FUNC(void, OS_CODE) Os_Tp_StopResBudget
(
    P2CONST(Os_TpCfgType, AUTOMATIC, OS_APPL_CONST) tpCfg,
    ResourceType resId,
    CoreIdType coreId
);
extern OS_ISR(Os_Tp_Handler);

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_TMPROTECTION_H_ */
