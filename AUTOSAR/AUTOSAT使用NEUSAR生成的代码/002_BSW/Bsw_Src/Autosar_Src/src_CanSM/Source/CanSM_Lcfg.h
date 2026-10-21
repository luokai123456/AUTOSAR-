/*
********************************************************************************
*
* File name: CanSM_Lcfg.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangCong/2018.07.21
* Change: New
* Cause: New
********************************************************************************
********************************************************************************
* Version: 2.0
* Author/Date: WangCong/2018.05.29
* Change: Modify format.
* Cause: updata to V2.0.
********************************************************************************
* Version: 3.0
* Author/Date: WangCong/2020.01.19
* Change: Synchronizing code with the DF project(Debugging completed).
* Cause: updata to V3.0.
********************************************************************************
* Version: 3.1
* Author/Date : WangCong/2020.05.12
* Change: Modify the code specification.
* Cause: Optimize.
********************************************************************************
* Version: 3.2
* Author/Date: TianL/2024.8.5
* Change: Modify copyright.
* Cause: Update
********************************************************************************
*/
#ifndef CANSM_LCFG_H_
#define CANSM_LCFG_H_

/*
*******************************************************************************
*    Includes
*******************************************************************************
*/
#include "CanSM_Cfg.h"
#include "CanSM_Types.h"

/*
*******************************************************************************
*    Global Macros
*******************************************************************************
*/
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
#define CANSM_START_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

extern CONST(CanSM_ManagerNetworkType, CANSM_CONFIG_DATA) CanSM_ManagerNetworkCfg[CANSM_MANAGER_NW_NUM];

#define CANSM_STOP_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
*******************************************************************************
*    Global Functions
*******************************************************************************
*/

#endif /* CANSM_LCFG_H_ */


