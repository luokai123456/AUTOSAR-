/*
********************************************************************************
*
*  File name: Os_Resource_Types.h
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
#ifndef OS_RESOURCE_TYPES_H_
#define OS_RESOURCE_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_List.h"
#include "Os_Cfg.h"
/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* The resource is associated whith the task. */
#define OS_RESOURCE_TASK        (0x00U)
/* The resource is associated whith the isr. */
#define OS_RESOURCE_ISR         (0x01U)
/* The resource is locked. */
#define OS_RESOURCE_LOCKED      (0x01U)
/* The resource is unlocked. */
#define OS_RESOURCE_RELEASED    (0x00U)
/* Resource initial zero value. */
#define OS_RESOURCE_INIT        (0U)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef uint8 Os_RsrcParamType;
typedef uint8 RsrcLockStateType;

union Os_RsrcParam
{
    Os_TaskPrioType taskPrio;
    Os_IntLevelType isrLevel;
};

struct Os_ResourceDyn
{
    Os_ListNodeType rsrcListNode;
    union Os_RsrcParam  rsrcParam;
    ResourceType   rsrcId;
    RsrcLockStateType state;
    union Os_RsrcParam  preRsrcParam;
};

/* Configuration information of a resource. */
struct Os_ResourceCfg
{
    /* The reource associate object task or isr. */
    Os_RsrcParamType rsrcType;
    /* The reource associate object task level or isr level. */
    union Os_RsrcParam rsrcParam;
    /* The resource id. */
    ResourceType rsrcId;
    /* The core allocation of the resource. */
    CoreIdType coreId;
    /* Reference to applications which access this object. */
    uint32 accessingApps;
    /* The resource associated dyn. */
    struct Os_ResourceDyn* resouceDyn;
};

typedef struct Os_ResourceDyn Os_ResourceDynType;
typedef struct Os_ResourceCfg Os_ResourceCfgType;

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

#endif /* OS_RESOURCEINT_TYPES_H_ */
