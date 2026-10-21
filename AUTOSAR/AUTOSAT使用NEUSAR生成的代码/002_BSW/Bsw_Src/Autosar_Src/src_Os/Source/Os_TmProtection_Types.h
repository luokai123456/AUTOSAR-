/*
********************************************************************************
*
*  File name: Os_TimingProtection_Types.h
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
* Author/Date: LiG/2023.10.24
* Change: Modification of coding specification issues.
* Cause: Bugfix
********************************************************************************
*/
#ifndef OS_TMPROTECTION_TYPES_H_
#define OS_TMPROTECTION_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_List.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Do not configure time protection. */
#define OS_TMPROTECTION_NONE            (0x00U)
/* Configure lock type time protection. */
#define OS_TMPROTECTION_LOCK            (0x01U)
/* Configure lock execution time type time protection. */
#define OS_TMPROTECTION_EXEC            (0x02U)
/* Time protection frame interval off. */
#define OS_TMPROTECTION_TIMEFRAME_OFF   (0x00U)
/* Time protection frame interval on. */
#define OS_TMPROTECTION_TIMEFRAME_ON    (0x01U)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef uint8 Os_TpBudgetKindType;
typedef uint8 Os_TpTimeFrameStateType;

typedef struct Os_TpBudgetCfg Os_TpBudgetCfgType;

struct Os_TpBudgetDyn
{
    /* Remaining amount of current budget. */
    Os_TickType tp_RemainTime;
    const Os_TpBudgetCfgType* tp_PrevBudget;
};

struct Os_TpBudgetCfg
{
    const Os_TpBudgetKindType tp_BudgetKind;
    const Os_TickType tp_InitBudge;
    /* Dynamic data of a timing protection budget. */
    struct Os_TpBudgetDyn* dyn;
};

struct Os_TpTimeFrameDyn
{
    Os_TickType tp_LastTime;
    Os_TpTimeFrameStateType tp_timeFrameState;
};

struct Os_TpTimeFrameCfg
{
    const Os_TickType tp_InitTimeFrame;
    struct Os_TpTimeFrameDyn* dyn;
};
typedef struct Os_TpTimeFrameDyn Os_TpTimeFrameDynType;
typedef struct Os_TpTimeFrameCfg Os_TpTimeFrameCfgType;
typedef struct Os_TpBudgetDyn Os_TpBudgetDynType;
typedef struct Os_TpDyn Os_TpDynType;
typedef struct Os_TpCfg Os_TpCfgType;
typedef struct Os_TpBaseDyn Os_TpBaseDynType;
typedef struct Os_TpBaseCfg Os_TpBaseCfgType;

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

#endif /* OS_TMPROTECTION_TYPES_H_ */
