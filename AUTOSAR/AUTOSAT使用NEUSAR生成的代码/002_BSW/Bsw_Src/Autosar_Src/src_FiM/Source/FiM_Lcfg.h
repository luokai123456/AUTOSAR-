/*
********************************************************************************
*
*  File name:   FiM_Lcfg.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : yaoxingjia/2019.08.28
* Change: New create.
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date : Liuziyang/2019.11.13
* Change: The format of code and comment.
* Cause: Modify the code according to the coding specification.
********************************************************************************
* Version: 3.0
* Author/Date: Liuziyang/2020.03.26
* Change: Optimizing data structure.
* Cause: Optimization and update to V3.0
********************************************************************************
* Version: 3.1
* Author/Date: Liuziyang/2020.03.30
* Change: Sync tool generates code
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: Liuziyang/2020.05.19
* Change: Modify file format.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: Liuziyang/2020.09.15
* Change: Remove the 1-byte alignment rule.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: liuziyang/2020.09.19
* Change: Modify the code format.
* Cause: Optimization.
********************************************************************************
* Version: 3.5
* Author/Date: LiuZY/2020.11.03
* Change: Modify the incorrectly defined part of the code format.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: LiuZY/2020.11.14
* Change: Modify the code review record.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: LiuZY/2020.03.10
* Change: Modify the Fim_gstaEventTable type.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: LiuZY/2020.03.10
* Change: Modify the eventTable type of FIM_Cfg_FidInfo_st.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: XieYN/2021.08.12
* Change:Modify code specifications.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: MengY/2022.11.25
* Change: Add code about the function of postbuild.
* Cause: Optimization
********************************************************************************
*/
#ifndef FIM_LCFG_H_
#define FIM_LCFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "FiM_Cfg.h"
#include "FiM_Types.h"

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
typedef struct
{
    Dem_EventIdType                 eventId;            /* Event ID defined by Dem. */
    FiM_FunctionIdType const        *FIDTableRef;       /* Associated FID table of Event ID. */
    uint8 const                     *maskTableRef;      /* Inhibit mask table of each FID. */
    uint8                           tableLength;        /* Number of elements in table. */
} FiM_EventTableType;

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
#define FIM_START_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "FiM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

extern CONST(FiM_EventTableType, FIM_CONFIG_DATA) FiM_EventTable[FIM_EVENT_NUM];

#define FIM_STOP_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "FiM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#endif /* FIM_LCFG_H_ */


