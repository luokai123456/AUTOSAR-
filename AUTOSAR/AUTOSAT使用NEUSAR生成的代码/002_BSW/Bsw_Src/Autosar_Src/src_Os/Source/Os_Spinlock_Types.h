/*
********************************************************************************
*
*  File name: Os_Spinlock_Types.h
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
* Version: 3.1
* Author/Date: HanCL/2024.2.29
* Change: To remove numerical macros, a meaningful macro was added.
* Cause: Optimization
********************************************************************************
*/
#ifndef OS_SPINLOCK_TYPES_H_
#define OS_SPINLOCK_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Types_Cfg.h"
#include "Os_Cfg.h"
#include "Os_List.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define OS_SPINLOCK_NESTARRAY               (1U)
#define OS_SPINLOCK_LOCK_NOTHING            (0U)   /* Disable nothing, just get the lock. */
#define OS_SPINLOCK_LOCK_ALL_INTERRUPTS     (1U)   /* Disable all interrupts. */
#define OS_SPINLOCK_LOCK_CAT2_INTERRUPTS    (2U)   /* Disable up to Cat 2 interrupts. */
#define OS_SPINLOCK_LOCK_WITH_RES_SCHEDULER (3U)   /* Disable task switching. */
#define OS_SPINLOCK_INVALIDCORE             (OS_COREID_COUNT) /* Invalid core. */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef uint8 Os_SpinlockMethodType;
typedef uint32 Os_SpinlockType;
typedef uint8 Os_SpinlockOrderType;

typedef struct
{
#if( OS_CFG_SPINLOCKNEST_ENABLE == STD_ON )
    Os_SpinlockOrderType order[OS_CFG_SPINLOCKMAXNESTNUM + OS_SPINLOCK_NESTARRAY];
#endif
    uint8 nestNum;
} Os_PreSpinlockOrderType;

struct Os_SpinlockDyn
{
    /* The spinlock list node. */
    Os_ListNodeType spinListNode;
    volatile Os_SpinlockType spinlock;
    SpinlockIdType   spinId;
    CoreIdType occurredCoreId[OS_COREID_COUNT];
    Os_SpinlockOrderType order;
};

/* Configuration information of a spinlock. */
struct Os_SpinlockCfg
{
    /* The spinlock method. */
    Os_SpinlockMethodType spinMethod;
    /* The spinlock id. */
    SpinlockIdType spinId;
    /* Spinlock to applications which access this object. */
    uint32 accessingApps;
    /* The spinlock associated dyn. */
    struct Os_SpinlockDyn* spinDyn;
    Os_SpinlockOrderType order;
};

typedef struct Os_SpinlockDyn Os_SpinlockDynType;
typedef struct Os_SpinlockCfg Os_SpinlockCfgType;

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

#endif /* OS_SPINLOCKINT_H_ */
