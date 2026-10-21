/*
********************************************************************************
*
*  File name: WdgM_Cfg.h
*
*  Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : WangCong/2019.04.12
* Change: New
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date : Baowanglong/2020.03.27
* Change: Only version update to V3.0.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date : Baowanglong/2020.05.25
* Change: Modify the file according to the code specification.
* Cause: Optimization.
********************************************************************************
* Version: 3.2
* Author/Date : WuZB/2020.12.1
* Change: Add macro definition WDGM_DEM_ENABLE.
* Cause: Optimization.
********************************************************************************
* Version: 3.3
* Author/Date : WuZB/2021.04.21
* Change: Modify the name of the macro definition.
* Cause: Optimization.
********************************************************************************
*/
#ifndef WDGM_CFG_H_
#define WDGM_CFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "WdgM_Lcfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define WDGM_DEV_ERROR_DETECT               (STD_ON)
#define WDGM_OFFMODE_ENABLE                 (STD_OFF)
#define WDGM_IMMEDIATE_RESET                (STD_OFF)
#define WDGM_VERSION_INFO_API               (STD_OFF)
#define WDGM_INITIAL_MODE                   (0U)
#define WDGM_MULTICORE_SUPPORT              (STD_ON)
#define MASTER_CORE_ID                      (0U)
#define WDGM_GENERAL_VERSION                (WDGM_AUTOSAR422)
#define WDGM_STATUSCHANGENOTIFICATION_SUPPORT (STD_OFF)
#define WDGM_STATECOMBINER_SUPPORT          (STD_OFF)
#define WDGM_STATECOMBINERUSERPORT_SUPPORT  (STD_OFF)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

#if( defined(WDGM_E_SET_MODE_EVENTID) || defined(WDGM_E_SUPERVISION_EVENTID) ) 
#define WDGM_DEM_ENABLE
#endif

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

#endif /* WDGM_CFG_H_ */

