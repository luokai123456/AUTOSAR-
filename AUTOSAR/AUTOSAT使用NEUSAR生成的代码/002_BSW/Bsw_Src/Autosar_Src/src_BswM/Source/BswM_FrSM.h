/*
********************************************************************************
*
* File name: BswM_FrSM.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: FangT/2021.11.03
* Change: New created.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: FangT/2021.12.29
* Change: Supplementary function function declaration is missing semicolon.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: HeHao/2024.04.02
* Change: Modify comments.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: LuQ/2024.05.14
* Change: Add MemMap segment definition.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: LuQ/2024.08.28
* Change: Modify copyright.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: LuQ/2025.06.17
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: LuQ/2025.06.23
* Change: Modify the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef BSWM_FRSM_H_
#define BSWM_FRSM_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "FrSM.h"

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
extern FUNC(void, BSWM_CODE) BswM_FrSM_CurrentState
(
    NetworkHandleType Network,
    FrSM_BswM_StateType CurrentState
);
#define BSWM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h"

#endif /* BSWM_SD_H_ */
