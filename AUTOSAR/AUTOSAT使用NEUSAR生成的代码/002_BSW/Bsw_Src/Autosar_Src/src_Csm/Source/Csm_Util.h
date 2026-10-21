/*
********************************************************************************
*
*  File name: Csm_Util.h
*
*  Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
*  Version: 1.0
*  Author/Date: jia_feng/2020.03.11
*  Change: New
*  Cause: New
********************************************************************************
*  Version: 3.0
*  Author/Date: jia_feng/2020.07.02
*  Change: Nothing
*  Cause: Update
********************************************************************************
*  Version: 3.1
*  Author/Date: NiXM/2023.01.31
*  Change: Update software version to 1.0.1 about the coding standards.
*  Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: MengY/2024.05.08
* Change: Add memmap section for function declaration.
* Cause: Optimization.
********************************************************************************
* Version: 3.3
* Author/Date: WangLX/2025.03.31
* Change: Fix QAC and Polyspace warnings and add analysis results.
* Cause: Update
********************************************************************************
*/
#ifndef CSM_UTIL_H_
#define CSM_UTIL_H_

/*
********************************************************************************
* Includes
********************************************************************************
*/
#include "Csm_Types.h"
#include "Csm_Cfg.h"

/*
*******************************************************************************
*    Global Macros
*******************************************************************************
*/
#define CSM_UTIL_VENDOR_ID_C                     119U
#define CSM_UTIL_MODULE_ID                       110U
#define CSM_UTIL_AR_RELEASE_MAJOR_VERSION_C      4U
#define CSM_UTIL_AR_RELEASE_MINOR_VERSION_C      4U
#define CSM_UTIL_AR_RELEASE_REVISION_VERSION_C   0U
#define CSM_UTIL_SW_MAJOR_VERSION_C              1U
#define CSM_UTIL_SW_MINOR_VERSION_C              0U
#define CSM_UTIL_SW_PATCH_VERSION_C              1U

/*
*******************************************************************************
*    Global Types
*******************************************************************************
*/
/*
*******************************************************************************
*    Global Variables
*******************************************************************************
*/
/*
*******************************************************************************
*    Global Constants
*******************************************************************************
*/
/*
*******************************************************************************
*    Global Functions
*******************************************************************************
*/
#define CSM_START_SEC_CODE
#include "Csm_MemMap.h"     /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

FUNC(void, CSM_CODE) Csm_Util_JobTypeMemcpy
(
    P2CONST(Crypto_JobType, AUTOMATIC, CSM_APPL_CONST)pSource,
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_DATA)pDest
);
FUNC(void, CSM_CODE) Csm_Util_InitJobQueues(void);
FUNC(boolean, CSM_CODE) Csm_Util_QueueJob
(
    uint32 u32QueueIdx,
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_DATA)pJob
);
FUNC(void, CSM_CODE) Csm_Util_DequeueHeadJob(uint32 u32QueueIdx);
FUNC(Std_ReturnType, CSM_CODE) Csm_Util_DequeueJob
(
    uint32 u32QueueIdx,
    P2CONST(Crypto_JobInfoType, AUTOMATIC, CSM_APPL_CONST)pJobInfo
);

#define CSM_STOP_SEC_CODE
#include "Csm_MemMap.h"     /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#endif
