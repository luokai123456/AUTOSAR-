/*
********************************************************************************
*
* File name: BswM_LinSM.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: FangT/2022.09.05
* Change: Add release software number.
* Cause: New created
********************************************************************************
* Version: 3.1
* Author/Date: HeHao/2024.04.02
* Change: Modify comments.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: LuQ/2024.08.28
* Change: Modify copyright.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: LuQ/2025.06.17
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: LuQ/2025.06.23
* Change: Modify the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef BSWM_LINSM_H_
#define BSWM_LINSM_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "LinSM.h"

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
extern FUNC(void, BSWM_CODE) BswM_LinSM_CurrentSchedule
(
    NetworkHandleType Network,
    LinIf_SchHandleType CurrentSchedule
);

extern FUNC(void, BSWM_CODE) BswM_LinSM_CurrentState
(
    NetworkHandleType Network,
    LinSM_ModeType CurrentState
);
#define BSWM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h"
#endif  /* BSWM_LINSM_H_ */
