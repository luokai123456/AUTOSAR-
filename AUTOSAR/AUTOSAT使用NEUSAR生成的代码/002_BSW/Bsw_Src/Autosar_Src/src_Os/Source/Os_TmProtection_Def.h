/*
********************************************************************************
*
*  File name: Os_TimingProtection_Def.h
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
*/
#ifndef OS_TMPROTECTION_DEF_H_
#define OS_TMPROTECTION_DEF_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Types.h"
#include "Os_Counter_Types.h"
#include "Os_TmProtection_Types.h"

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
struct Os_TpDyn
{
    const struct Os_TpBudgetCfg* tp_CurrentBudget;
};

struct Os_TpCfg
{
    const Os_CounterBaseCfgType* tpCnt;
    const struct Os_TpTimeFrameCfg* tp_TimeFrame;
    const struct Os_TpBudgetCfg* tp_ExecBudget;
    const struct Os_TpBudgetCfg* tp_AllIntLockBudget;
    const struct Os_TpBudgetCfg* tp_OsIntLockBudget;
    const struct Os_TpBudgetCfg** tp_ResLockBudgetRefs;
    struct Os_TpDyn* dyn;
};

struct Os_TpBaseDyn
{
    const struct Os_TpBudgetCfg* tp_CurrentBudget;
};

struct Os_TpBaseCfg
{
    const struct Os_CounterBaseCfg* tpCnt;
    struct Os_TpBaseDyn* dyn;
};

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

#endif /* OS_TMPROTECTION_DEF_H_ */
