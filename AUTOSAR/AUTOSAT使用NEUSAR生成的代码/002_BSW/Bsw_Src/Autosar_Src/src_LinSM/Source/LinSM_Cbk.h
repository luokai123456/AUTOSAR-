/*
********************************************************************************
*
* File name: LinSM_Cbk.h
*
* Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJipeng/2020.04.08
* Change: New created
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: lizhiheng/2020.07.01
* Change: Updata to 3.0.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: lizhiheng/2020.09.25
* Change: Modified to AutoSar coding style.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: lizhiheng/2020.10.10
* Change: 1.Optimized coding specification.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: LiZH/2020.11.04
* Change: Modify file format.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date : Li.ZH/2021.8.16
* Change: Modification code specification.
* Cause: Optimize
********************************************************************************
* Version: 3.5
* Author/Date : LiXB/2023.7.25
* Change: Add macro judgement of LinSM_ScheduleRequestConfirmation declaration.
* Cause: Optimize
********************************************************************************
* Version: 3.6
* Author/Date:TianG/2024.6.25
* Change: 1. Add a memory-map label to function.
*         2. Modify copyright.
*         3. Modify the comments format.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: TianG/2025.03.25
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: YanCL/2025.06.16
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: YanCL/2025.06.23
* Change: #include "LinSM_MemMap.h" add suppression comments.
* Cause: Update
********************************************************************************
*/
#ifndef LINSM_CBK_H_
#define LINSM_CBK_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "LinSM.h"
#include "LinIf.h"

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
#define LINSM_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinSM_MemMap.h"

/* Polyspace +1 MISRA-C3:20.9 [Justified:Unset] "NSCA_Polyspace_LinSM_Rule20.9" */
#if( LINSM_MASTER_SUPPORT == STD_ON )  /* PRQA S 3332 */ /* NSCA_QAC_LinSM_Rule20.9 */
extern FUNC(void, LINSM_CODE) LinSM_ScheduleRequestConfirmation
(
    NetworkHandleType network,
    LinIf_SchHandleType schedule
);
#endif /* LINSM_MASTER_SUPPORT == STD_ON */

extern FUNC(void, LINSM_CODE) LinSM_GotoSleepConfirmation
(
    NetworkHandleType network,
    boolean success
);
extern FUNC(void, LINSM_CODE) LinSM_WakeupConfirmation
(
    NetworkHandleType network,
    boolean success
);
#define LINSM_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinSM_MemMap.h"

#endif /* LINSM_CBK_H_ */

