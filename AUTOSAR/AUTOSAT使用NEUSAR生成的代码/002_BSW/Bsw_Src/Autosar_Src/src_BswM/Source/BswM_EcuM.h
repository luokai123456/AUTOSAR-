/*
********************************************************************************
*
* File name: BswM_EcuM.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: yong.zhang/2018.12.13
* Change: New created
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: yong.zhang/2020.07.02
* Change: Add release software number.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: fangtao/2020.09.15
* Change: Modify the function name according to the AUTOSAR specification, add
*         MemMap.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: FangT/2020.11.04
* Change: Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: FangT/2021.08.17
* Change: Modify the code specification.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: FangT/2021.10.15
* Change: Add BswM_EcuM_CurrentState function declaration.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: HeHao/2024.04.02
* Change: Modify comments.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: LuQ/2024.05.14
* Change: Add MemMap segment definition.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: LuQ/2024.08.28
* Change: Optimize code format.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: LuQ/2025.06.17
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: LuQ/2025.06.23
* Change: Modify the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: LuQ/2025.06.23
* Change: Modify the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef BSWM_ECUM_H_
#define BSWM_ECUM_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "EcuM.h"

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
#define BSWM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h"
extern FUNC(void, BSWM_CODE) BswM_EcuM_CurrentState(EcuM_StateType CurrentState);

extern FUNC(void, BSWM_CODE) BswM_EcuM_CurrentWakeup
(
    EcuM_WakeupSourceType source,
    EcuM_WakeupStatusType state
);
#define BSWM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h"

#endif  /* BSWM_ECUM_H_ */
