/*
********************************************************************************
*
*  File name: Os_SchdTb_Types.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.23
* Change: New create.
* Cause: New
********************************************************************************
*/
#ifndef OS_SCHDTB_TYPES_H_
#define OS_SCHDTB_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Types.h"
#include "Os_Types_Cfg.h"
#include "Os_Counter_Types.h"
#include "Os_Cfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* The schedule table single execution. */
#define OS_SCHDTB_CYCLE_MODE    (0x00U)
/* The schedule table cycle execution. */
#define OS_SCHDTB_SINGLE_MODE   (0x01U)

/* The schedule table configuration is absolutely auto-start. */
#define OS_SCHDTB_ABS_START     (0x00U)
/* The schedule table configuration is relatively auto-start. */
#define OS_SCHDTB_SYNC_START    (0x01U)
/* The schedule table configuration is synchronization auto-start. */
#define OS_SCHDTB_REL_START     (0x02U)
/* The schedule table configuration is no auto-start. */
#define OS_SCHDTB_NONE_START    (0x03U)

/* The schedule table configuration is out of synchronization. */
#define OS_SCHDTB_NONE_KIND     (0x00U)
/* The schedule table configuration implicit synchronization. */
#define OS_SCHDTB_IMPLICIT_KIND (0x01U)
/* The schedule table configuration explicit synchronization. */
#define OS_SCHDTB_EXPLICIT_KIND (0x02U)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* Defines whether a synchronization point has been provided or not. */
typedef enum
{
    /* No synchronization point has been provided. */
    OS_SCHTSYNCSTATUS_NOT_PROVIDED = 0U,
    /* Synchronization point has been provided and the schedule table is synchronized. */
    OS_SCHTSYNCSTATUS_SYNC,
    /* Synchronization point has been provided. the schedule table is not synchronized. */
    OS_SCHTSYNCSTATUS_ASYNC
} Os_SchTSyncStatusType;

typedef uint8 OS_SchdTbCycleType;
typedef uint8 Os_SchdTbModeType;
typedef uint8 Os_SchdTbKindType;
typedef struct Os_SchdTbCfg Os_SchdTbCfgType;
typedef struct Os_SchdTbDyn Os_SchdTbDynType;
typedef struct Os_SchdTbExpCfg Os_SchdTbExpCfgType;

struct Os_SchdTbExpCfg
{
    Os_CntExpListNodeCfgType expNode;
    /* SchedulerTable parameter. */
    Os_SchdTbParamType* schdTbParam;
    Os_SchdTbExpCfgType* nextExp;
    Os_TickType nextExpOffset;
    /* Counter configuration associated with the schedulertable. */
    const struct Os_CounterBaseCfg* counter;
    Os_SchdTbDynType* schdTbDyn;

#if( OS_CFG_SCHDTBSYNC_ENABLE == STD_ON )
    Os_TickType expSyncTimeStamp;
    Os_TickType maxLengthenDeviation;
    Os_TickType maxShortenDeviation;   /* nextExpOffset must be greater than -(maxShortenDeviation). */
#endif
};

struct Os_SchdTbDyn
{
    struct Os_SchdTbExpCfg* currentExp;
    ScheduleTableStatusType state;
    /* The schedule table which shall be started at the end of this schedule table. */
    const Os_SchdTbCfgType* next;
    /* The schedule table which has nexted this schedule table. */
    const Os_SchdTbCfgType* previous;
    ScheduleTableType schdTbId;

#if( OS_CFG_SCHDTBSYNC_ENABLE == STD_ON )
    Os_TickType driveCtrTimeStamp;
    /* The current deviation of the counter time from the synchronization time. */
    Os_TickType deviation;
    /* Defines whether a synchronization point is available. */
    Os_SchTSyncStatusType SyncState;
#endif
};

struct Os_SchdTbCfg
{
    /* Counter configuration associated with the schedulertable. */
    const struct Os_CounterBaseCfg* counter;
    ScheduleTableType schdTbId;
    /* Owner application. */
    ApplicationType ownerAppId;
    /* Expiration point init pointer. */
    struct Os_SchdTbExpCfg* initExp;
    /* Dynamic parameters. */
    struct Os_SchdTbDyn* dyn;
    /* Reference to applications which access this object. */
    uint32 accessingApps;
    /* The core id. */
    CoreIdType coreId;
    /* Autostart mode. */
    AppModeType appMode;
    /* The Config cycle the schedulertable in AutoStart mode. */
    Os_TickType autoStartTime;
    /* Schedule table start mode. */
    Os_SchdTbModeType autoStartMode;
    Os_SchdTbKindType schdTbKind;
    OS_SchdTbCycleType cycleType;
    /* The duration in ticks of this schedule table. */
    Os_TickType duration;
    Os_TickType initOffset;
#if( OS_CFG_SCHDTBSYNC_ENABLE == STD_ON )
    /* Configured precision of the schedule table. */
    Os_TickType precision;
#endif
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

#endif /* OS_SCHDTB_TYPES_H_ */
