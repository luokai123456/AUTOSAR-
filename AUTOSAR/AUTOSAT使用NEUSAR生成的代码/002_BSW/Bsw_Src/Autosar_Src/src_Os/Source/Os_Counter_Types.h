/*
********************************************************************************
*
*  File name: Os_Counter_Types.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.16
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: JiangGL/2023.6.9
* Change: Solve the issue of setting expiration points for error reporting.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2023.10.8
* Change: Shared counter direct access registers.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2024.1.25
* Change: Add a lastValue member to the Os-CounterSwDynType type.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: LiuZB/2025.02.20
* Change: Optimize space size.
* Cause: Update
********************************************************************************
*/
#ifndef OS_COUNTER_TYPES_H_
#define OS_COUNTER_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Types.h"
#include "Os_App_Types.h"
#include "Os_PriorityQueue.h"
#include "Os_Arch_Mach_Timer.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define OS_COUNTER_SW           (0x00U)  /* The software counter. */
#define OS_COUNTER_HRT          (0x01U)  /* The Hardware Counter. */
#define OS_COUNTER_PIT          (0x02U)  /* The Hardware Counter. */
#define OS_COUNTER_EXPLISTNUM   (2U)     /* Expiration point list number. */
#define OS_COUNTER_EXPLISTMAX   (1U)     /* Expiration point list mask bit. */
#define OS_COUNTER_INIT         (0U)     /* Counter initial zero value. */
#define OS_COUNTER_VALUE_ONE    (1U)     /* Counter initial one value. */
#define OS_COUNTER_HALF_VALUE   (2U)     /* Counter initial two value. */

#define OS_COUNTER_SET_POINT    (1U)     /* Counter set next point. */
#define OS_COUNTER_NOTSET_POINT (0U)     /* Counter not set next point. */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef enum
{
    OS_CNTEXP_ALRM_AT = 0U,  /* Expiry point do alarm activate task action. */
#if(  OS_CFG_EVENT_ENABLE == STD_ON  )
    OS_CNTEXP_ALRM_SE,       /* Expiry point do set eventalarm action. */
#endif /* OS_CFG_EVENT_ENABLE == STD_ON */
    OS_CNTEXP_ALRM_IC,       /* Expiry point do alarm increment counter action. */
    OS_CNTEXP_ALRM_CB,       /* Expiry point do alarm call callback action. */
#if( OS_CFG_SCHDTB_ENABLE == STD_ON )
    OS_CNTEXP_SCHET_NONE,    /* Expiry point do schedule tabel norml execution action. */
    OS_CNTEXP_SCHET_SYNC,    /* Expiry point do schedule tabel synchronous execution action. */
    OS_CNTEXP_SCHET_CYCLIC,  /* Expiry point do schedule tabel cyclic execution action. */
    OS_CNTEXP_SCHET_SINGLE,  /* Expiry point do schedule tabel single execution action. */
#endif /* OS_CFG_SCHDTB_ENABLE == STD_ON */
    OS_CNTEXP_WORKFUNCNUM    /* The number of work functions at the expiration point. */
} Os_CntExpKindType;

typedef uint8   Os_CounterKindType;
typedef uint8   Os_CntExplistDelRetType;
typedef uint32  Os_CntExpListNodeIdxType;

typedef struct
{
    /* The event id. */
    EventMaskType eventMask;
    /* The task id. */
    TaskType taskId;
} Os_EventParamType;

typedef struct
{
    TaskType* taskId;         /* The task id for schedule node. */
    Os_ObjIdxType taskCnt;    /* Number of tasks for schedule node. */
    Os_EventParamType* event; /* The event id for schedule node. */
    Os_ObjIdxType eventCnt;   /* Number of events for schedule node. */
} Os_SchdTbParamType;

/* Expiration point work parameter. */
union Os_WorkParam{
    /* The event id. */
    Os_EventParamType eventParam;
    /* The task id. */
    TaskType taskId;
    /* The counter id. */
    CounterType counterId;
    /* SchedulerTable parameter. */
    Os_SchdTbParamType* schdTbParam;
};

typedef struct
{
    /* The expriation point timestamp. */
    Os_PriQueueNodeType expTimestamp;
    /* The expriation execution action. */
    Os_CntExpKindType expKind;
    /* The parameter of expriation execution action. */
    union Os_WorkParam workParam;
} Os_CntExpListNodeCfgType;

typedef struct
{
    /* Expiration point work list to the counter. */
    Os_PriQueueType cntExpList[OS_COUNTER_EXPLISTNUM];
    /* Which list to use. */
    uint8 cntExplistMux;
} Os_CntExpListCfgType;

typedef struct
{
    /* Counter value. */
    Os_TickType value;
    /* Counter last value. */
    Os_TickType lastValue;
} Os_CounterSwDynType;

/* The configuration data Type of counter. */
struct Os_CounterBaseCfg
{
    /* Expiration point work list to the counter. */
    Os_CntExpListCfgType* Os_CntExpList;
    /* Maximum possible allowed value of the counter in ticks. */
    Os_TickType maxAllowValue;
    /* The minimum allowed cycle to the counter. */
    Os_TickType minCycle;
    /* The number of ticks corresponding to a unit of the counter. */
    Os_TickType ticksPerBase;
    /* The counter type hardware or software. */
    Os_CounterKindType counterType;
    /* The core to which the counter belongs. */
    CoreIdType coreId;
    /* The application to which the counter belongs. */
    ApplicationType ownerAppId;
    /* The counter index. */
    CounterType counterId;
    /* Reference to applications which access this object. */
    uint32 accessingApps;
    /* The shared properties of this timer. */
    uint32 share;
};

struct Os_CounterSwCfg
{
    struct Os_CounterBaseCfg counterBase;
    /* The dynamic config of counter. */
    Os_CounterSwDynType* counterDyn;
};

#if( OS_HRT_ENABLE == STD_ON )
struct Os_CounterHrtCfg
{
    struct Os_CounterBaseCfg counterBase;
    /* The dynamic config of counter. */
    Os_CounterSwDynType* counterDyn;
    /* The hardware counter driver config. */
    const Os_Arch_Mach_TimerHrtCfgType* HwConfig;
};
#endif


#if( OS_PIT_ENABLE == STD_ON )
/* The configuration data Type of counter. */
struct Os_CounterPitCfg
{
    struct Os_CounterBaseCfg counterBase;
    /* The dynamic config of counter. */
    Os_CounterSwDynType* counterDyn;
    /* The hardware counter driver config. */
    const Os_Arch_Mach_TimerPitCfgType* HwConfig;
};
#endif

typedef struct Os_CounterBaseCfg Os_CounterBaseCfgType;
#if( OS_PIT_ENABLE == STD_ON )
typedef struct Os_CounterPitCfg Os_CounterPitCfgType;
#endif

#if( OS_HRT_ENABLE == STD_ON )
typedef struct Os_CounterHrtCfg Os_CounterHrtCfgType;
#endif

typedef struct Os_CounterSwCfg Os_CounterSwCfgType;
typedef Os_CounterBaseCfgType* Os_CounterCfgRefType;
typedef union Os_WorkParam Os_WorkParamType;
typedef uint8 (*Os_CntExpWorkFuncType)(Os_CntExpListNodeCfgType* expListNode);

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

#endif /* OS_COUNTER_TYPES_H_ */
