/*
********************************************************************************
*
*  File name: Os_Isr_Types.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.18
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.25
* Author/Date: LiG/2023.3.15
* Change: Add an Appid to which cat1 of interrupt belongs.
* Cause: Bugfix
********************************************************************************
* Version: 3.26
* Author/Date: LiuZB/2025.2.26
* Change: Fit for cat1 isr stack function.
* Cause: Update
********************************************************************************
*/
#ifndef OS_ISR_TYPES_H_
#define OS_ISR_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Types.h"
#include "Os_Hook_Types.h"
#include "Os_Arch_Context_Types.h"
#include "Os_Arch_Types.h"
#include "Os_List.h"
#include "Os_Cfg.h"
#include "Os_MemProtection_Types.h"
#include "Os_TmProtection_Types.h"
#include "Os_Orti_Types.h"

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
/* Function pointer data type for call isr callabck. */
typedef P2FUNC(void, OS_CODE, Os_IsrCbkType )(void);

struct Os_IsrDyn
{
    /* The hardware context need saved. */
    Os_Arch_ContextDynType* context;
    /* List head of resource. */
    Os_ListNodeType resListHead;
    /* List head of spinlock. */
    Os_ListNodeType spinListHead;
    ISRType isrId;
    /* Currently running app. */
    ApplicationType currentAppId;
#if( (OS_CFG_ORTI_ENABLE == STD_ON) && (OS_CFG_ORTI_HOOK_ENABLE == STD_ON) )
    Os_OrtiIsrStateType ortiIsrState;
#endif
};

/* Configuration information of a cat2 isr. */
struct Os_IsrCfg
{
    boolean ifconterIsr;
    boolean ifTpIsr;

    /* Config context of the task. */
    const Os_Arch_ContextCfgType* contextCfg;
    /* Owner application */
    ApplicationType ownerAppId;
#if( (OS_CFG_SCALABILITY_CLASS == OS_SC2) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
    /* Timing protection configuration of the task. */
    const Os_TpCfgType* tpCfg;
#endif

#if( (OS_CFG_SCALABILITY_CLASS == OS_SC3) || (OS_CFG_SCALABILITY_CLASS == OS_SC4) )
    /* Current application memory protection settings. */
    const Os_MpCfgType* appMpCfg;
    /* Current isr memory protection settings. */
    const Os_MpCfgType* isrMpCfg;
#endif
    /* Isr dynamic configuration. */
    struct Os_IsrDyn* isrDyn;
    /* The address offset of the interrupt source register. */
    const Os_Arch_IsrSourceType* source;
    /* The core allocation of the isr. */
    CoreIdType coreId;
    /* The Id of the isr. */
    ISRType isrId;
    CounterType counterId;
};

/* Configuration information of a cat1 isr. */
struct Os_IsrCat1Cfg
{
    const Os_Arch_IsrSourceType* source;
    /* Owner application */
    ApplicationType ownerAppId;
    /* The core allocation of the isr. */
    CoreIdType   coreId;
#if( OS_CFG_CAT1_ISR_STACK_ENABLE == STD_ON )
    /* Config context of the task. */
    const Os_Arch_Cat1ContextCfgType* contextCfg;
#endif /* OS_CFG_CAT1_ISR_STACK_ENABLE == STD_ON */
};

typedef struct Os_IsrDyn Os_IsrDynType;
typedef struct Os_IsrCfg Os_IsrCfgType;
typedef struct Os_IsrCat1Cfg Os_IsrCat1CfgType;
typedef Os_IsrCfgType* Os_IsrCfgRefType;
typedef Os_IsrCat1CfgType* Os_IsrCat1CfgRefType;

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

#endif /* OS_ISR_TYPES_H_ */
