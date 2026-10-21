/*
********************************************************************************
*
*  File name: Os_MultiCore.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.24
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
* Author/Date: LiG/2023.4.15
* Change: Adapted to GCC compiler.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2024.6.6
* Change: The problem of unpaired segment definitions in a single core state.
* Cause: Bugfix
********************************************************************************
* Version: 3.5
* Author/Date: MiaoLH/2024.8.27
* Change: Add the Os MultiCoreStartRequest variable declaration.
* Cause: Optimize
********************************************************************************
* Version: 3.6
* Author/Date: LiG/2025.1.3
* Change: Add macro for the fifth synchronization.
* Cause: Update
********************************************************************************
*/
#ifndef OS_MULTICORE_H_
#define OS_MULTICORE_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_MultiCore_Types.h"
#include "Std_Types.h"
#include "Os_Cfg.h"

#if( OS_CFG_MULTI_CORE == STD_ON )
/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Multi-core synchronization initialization value. */
#define OS_MULTISYNCINIT                        (0xFF)
/* Multi-core synchronization for the first time. */
#define OS_MULTISYNCFIRST                       (0x01)
/* Multi-core synchronization for the second time. */
#define OS_MULTISYNCSECOND                      (0x02)
/* Multi-core synchronization for the third time. */
#define OS_MULTISYNCTHIRD                       (0x03)
/* Multi-core synchronization for the fourth time. */
#define OS_MULTISYNCFOURTH                      (0x04)
/* Multi-core synchronization for the fifth time. */
#define OS_MULTISYNCFIFTH                       (0x05)
#define OS_SETMULTISYNCCOUNTER(coreId, counter) (Os_MultiCoreSync[coreId] = (counter))

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
#define OS_START_SEC_GLOBAL_NOCACHE_VAR
#include "Os_MemMap.h"
extern volatile VAR(uint8, OS_VAR_NO_INIT) Os_MultiCoreSync[OS_COREID_COUNT];
extern VAR(uint8, OS_VAR_NO_INIT) Os_MultiCoreStartRequest[OS_COREID_COUNT];
#define OS_STOP_SEC_GLOBAL_NOCACHE_VAR
#include "Os_MemMap.h"

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
extern void Os_MultiCore_Sync
(
    CoreIdType coreId,
    uint8 syncCounter
);
extern Os_StatusType Os_MultiCore_Trigger
(
    boolean isSync,
    CoreIdType srcCore,
    CoreIdType desCore,
    Os_MCServe_FuncId funcId,
    Os_MultiCoreServeParamType* param
);
extern OS_ISR(Os_MultiCoreServer_Handler);

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_CFG_MULTI_CORE == STD_ON */

#endif /* OS_MULTICORE_H_ */
