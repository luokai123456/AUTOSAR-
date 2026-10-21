/*
********************************************************************************
*
* File name: NvM_Cbk.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJipeng/2018.12.13
* Change: Add
* Cause: New
********************************************************************************
* Version: 2.0
* Author/Date: Baowanglong/2019.11.12
* Change: Modify the code format
* Cause: Coding Standards.
********************************************************************************
* Version: 3.0
* Author/Date: Baowanglong/2020.02.17
* Change: Nothing
* Cause: Update to V3.0.
********************************************************************************
* Version: 3.1
* Author/Date: Hanbaiyu/2020.03.27
* Change: Add include the NvM_Cfg.h file.
* Cause: QAC
********************************************************************************
* Version: 3.2
* Author/Date: Hanbaiyu/2020.09.29
* Change: 1. Change the code style to AUTOSAR format.
*         2. Add definition of paragraph.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: HanBY/2020.11.04
* Change: Deleting memrory maps for variable or function declarations.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: HanBY/2020.01.28
* Change: In order to prevent compilation errors caused by incorrect configuration
*         of the callback functions, remove macro switch for callback functions
*         declaration.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: WangLX/2024.04.25
* Change: Add a memory-map label to function and variable declarations.
* Cause: Bugfix
********************************************************************************
* Version: 3.6
* Author/Date: WangLX/2024.08.08
* Change: Change copyright information.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: WangLX/2025.03.31
* Change: Fix QAC and Polyspace warnings and add analysis results.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: ZengJX/2025.06.04
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: ZengJX/2025.06.09
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: ZengJX/2025.06.23
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
*/
#ifndef NVM_CBK_H_
#define NVM_CBK_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "NvM_Cfg.h"

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
#define NVM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* Function to be used by the underlying memory abstraction to signal end of job without error. */
extern FUNC(void, NVM_CODE) NvM_JobEndNotification(void);
/* Function to be used by the underlying memory abstraction to signal end of job with error. */
extern FUNC(void, NVM_CODE) NvM_JobErrorNotification(void);

#define NVM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#endif /* NVM_CBK_H_ */
