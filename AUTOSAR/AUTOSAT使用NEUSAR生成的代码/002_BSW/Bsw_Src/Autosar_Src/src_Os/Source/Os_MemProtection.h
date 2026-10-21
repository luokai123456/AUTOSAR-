/*
********************************************************************************
*
*  File name: Os_MemProtection.h
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
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2023.4.15
* Change: Adapted to GCC compiler.
* Cause: Update
********************************************************************************
*/
#ifndef OS_MEMPROTECTION_H_
#define OS_MEMPROTECTION_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Types.h"
#include "Os_MemProtection_Types.h"
#include "Os_Arch_Mach_MP.h"

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
#if( OS_SYSTEM_MPU == STD_ON )
extern FUNC(void, OS_CODE) Os_Mp_MpInit
(
    P2CONST(Os_MpCfgType, AUTOMATIC, OS_APPL_CONST) Os_MpCfg
);
#endif /* OS_SYSTEM_MPU == STD_ON */

#if( OS_CORE_MPU == STD_ON )
extern FUNC(void, OS_CODE) Os_Mp_CoreMpInit
(
    P2CONST(Os_MpCfgType, AUTOMATIC, OS_APPL_CONST) Os_MpCfg
);
#endif /* OS_CORE_MPU == STD_ON */

#if( OS_MEMORY_PROTECTION == STD_ON )
extern FUNC(void, OS_CODE) Os_Mp_Switch
(
    boolean isAppMpuCfg,
    P2CONST(Os_MpCfgType, AUTOMATIC, OS_APPL_CONST) nextMpCfg
);
#endif /* OS_MEMORY_PROTECTION == STD_ON */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_MEMPROTECTION_H_ */

