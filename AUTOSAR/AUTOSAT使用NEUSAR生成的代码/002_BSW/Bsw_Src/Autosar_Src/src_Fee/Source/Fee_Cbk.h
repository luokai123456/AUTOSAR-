/*
********************************************************************************
*
* File name: Fee_Cbk.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJipeng/2018.12.12
* Change: New created
* Cause: New
********************************************************************************
* Version: 2.0
* Author/Date: WangHe/2019.11.8
* Change: Modify callback function enable switch.
* Cause: Optimization
********************************************************************************
* Version: 2.1
* Author/Date: WangHe/2019.11.22
* Change: Local variables are defined by hump standard and format modification.
* Cause: Optimization
********************************************************************************
* Version: 3.0
* Author/Date: Baowanglong/2020.02.17
* Change: Nothing
* Cause: Update to V3.0
********************************************************************************
* Version: 3.1
* Author/Date: Hanbaiyu/2020.09.29
* Change: 1. Change the code style to AUTOSAR format.
*         2. Add definition of paragraph.
* Cause: Optimization.
********************************************************************************
* Version: 3.2
* Author/Date: HanBY/2020.11.04
* Change: Deleting memrory maps for variable or function declarations.
* Cause: Optimization.
********************************************************************************
* Version: 3.3
* Author/Date: LiDaY/2024.07.19
* Change: 1.Modify function Fee_JobEndNotification parameters for NSCPV40BUG-1849.
*         2.Add function Fee_MemAcc_GetJobResultCallBack for NSCPV40BUG-1849.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: LiDaY/2024.08.08
* Change: Change copyright information.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: LiDaY/2025.02.18
* Change: Optimize header file references.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: LiDaY/2025.03.28
* Change: 1.Add QAC, PolySpace warning analysis results.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: Chixp/2025.06.23
* Change: Update the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef FEE_CBK_H_
#define FEE_CBK_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Fee.h"

#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
#include "MemAcc.h"
#include "MemAcc_MemApi.h"
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

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
#define FEE_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Fee_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if (FEE_POLLING_MODE == STD_OFF)

#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
extern FUNC(void, FEE_CODE) Fee_JobEndNotification(MemAcc_AddressAreaIdType FeeAddressAreaId, MemAcc_JobResultType JobResult);
#else
extern FUNC(void, FEE_CODE) Fee_JobEndNotification(void);
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

extern FUNC(void, FEE_CODE) Fee_JobErrorNotification(void);

#endif /* FEE_POLLING_MODE == STD_OFF */

#define FEE_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Fee_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#endif /* FEE_CBK_H_ */

