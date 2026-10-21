/*
********************************************************************************
*
* File name: Dem_PBcfg.h
*
* Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: FanHT/2023.01.01 
* Change: New
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: ZengJX/2024.07.18
* Change: 1.Modify copyright information.
*         2.Fix Dem memmap issue.
* Cause: Optimization
********************************************************************************
* Version: 1.2
* Author/Date: ZengJX/2024.08.22
* Change: Modify copyright information.
* Cause: Bugfix
********************************************************************************
* Version: 1.3
* Author/Date: ZengJX/2025.05.06
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Optimization
********************************************************************************
*/
#ifndef DEM_PBCFG_H_
#define DEM_PBCFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Dem_Types.h"

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
*    Global Constants
********************************************************************************
*/
#define DEM_START_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
extern CONST(uint32, DEM_CONFIG_DATA) Dem_CfgUdsDtcValue[DEM_CFG_DTC_NUM + 1U];


extern CONST(boolean, DEM_CONFIG_DATA) Dem_CfgEvtAvail[DEM_CFG_EVENT_NUM + 1U];


extern CONST(uint16, DEM_CONFIG_DATA) Dem_CfgDebCntFailThrs[DEM_CFG_DEBOUNCE_COUNTER_NUM + 1U];


extern CONST(sint16, DEM_CONFIG_DATA) Dem_CfgDebCntPassThrs[DEM_CFG_DEBOUNCE_COUNTER_NUM + 1U];


extern CONST(uint16, DEM_CONFIG_DATA) Dem_CfgDebCntIncStepSize[DEM_CFG_DEBOUNCE_COUNTER_NUM + 1U];


extern CONST(uint16, DEM_CONFIG_DATA) Dem_CfgDebCntDecStepSize[DEM_CFG_DEBOUNCE_COUNTER_NUM + 1U];


extern CONST(boolean, DEM_CONFIG_DATA) Dem_CfgDebCntJuEn[DEM_CFG_DEBOUNCE_COUNTER_NUM + 1U];


extern CONST(boolean, DEM_CONFIG_DATA) Dem_CfgDebCntJdEn[DEM_CFG_DEBOUNCE_COUNTER_NUM + 1U];


extern CONST(sint16, DEM_CONFIG_DATA) Dem_CfgDebCntJuVal[DEM_CFG_DEBOUNCE_COUNTER_NUM + 1U];


extern CONST(sint16, DEM_CONFIG_DATA) Dem_CfgDebCntJdVal[DEM_CFG_DEBOUNCE_COUNTER_NUM + 1U];


extern CONST(boolean, DEM_CONFIG_DATA) Dem_CfgEnableCond[DEM_CFG_ENCOND_NUM + 1U];
#define DEM_STOP_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/*
*********************************************************************************
*    Global Functions
*********************************************************************************
*/


#endif /* DEM_PBCFG_H_ */

