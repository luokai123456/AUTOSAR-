/*
************************************************************************************************************************
*
* File name: Rte_WdgM_Type.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
************************************************************************************************************************
*
* History
*-----------------------------------------------------------------------------------------------------------------------
************************************************************************************************************************
* Version: 3.0
* Author/Date : WangJP/2021.11.11
* Change: New created.
* Cause: New
************************************************************************************************************************
* Version: 4.0
* Author/Date: LanZG/2024.03.18
* Change: Upgrade template.
* Cause: Update
************************************************************************************************************************
*/
#ifndef RTE_WDGM_TYPE_H_
#define RTE_WDGM_TYPE_H_

/*
************************************************************************************************************************
*    Includes
************************************************************************************************************************
*/
#include "Std_Types.h"

/*
************************************************************************************************************************
*    Global Macros
************************************************************************************************************************
*/
#ifndef Rte_TypeDef_WdgM_SupervisedEntityIdType
#define Rte_TypeDef_WdgM_SupervisedEntityIdType
typedef uint16 WdgM_SupervisedEntityIdType;
#endif

#ifndef Rte_TypeDef_WdgM_CheckpointIdType
#define Rte_TypeDef_WdgM_CheckpointIdType
typedef uint16 WdgM_CheckpointIdType;
#endif

#ifndef Rte_TypeDef_WdgM_LocalStatusType
#define Rte_TypeDef_WdgM_LocalStatusType
typedef uint8 WdgM_LocalStatusType;
#endif

#ifndef Rte_TypeDef_WdgM_GlobalStatusType
#define Rte_TypeDef_WdgM_GlobalStatusType
typedef uint8 WdgM_GlobalStatusType;
#endif

#ifndef Rte_TypeDef_WdgM_ModeType
#define Rte_TypeDef_WdgM_ModeType
typedef uint8 WdgM_ModeType;
#endif

/* Global Statuses. */
#define WDGM_GLOBAL_STATUS_OK           (0U)
#define WDGM_GLOBAL_STATUS_FAILED       (1U)
#define WDGM_GLOBAL_STATUS_EXPIRED      (2U)
#define WDGM_GLOBAL_STATUS_STOPPED      (3U)
#define WDGM_GLOBAL_STATUS_DEACTIVATED  (4U)

/* Local Statuses. */
#define WDGM_LOCAL_STATUS_OK            (0U)
#define WDGM_LOCAL_STATUS_FAILED        (1U)
#define WDGM_LOCAL_STATUS_EXPIRED       (2U)
#define WDGM_LOCAL_STATUS_DEACTIVATED   (4U)



/*
************************************************************************************************************************
*    Global Types
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Global Variables
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Global Constants
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Global Functions
************************************************************************************************************************
*/

#endif /* RTE_WDGM_TYPE_H_ */

