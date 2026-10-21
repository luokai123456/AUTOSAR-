/*
********************************************************************************
*
*  File name: WdgM.h
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
* Change:New
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
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: WuZhibin/2020.09.29
* Change: 1.Add function of MemMap
*         2.Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: WuZhibin/2020.10.13
* Change: Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: WuZB/2020.11.02
* Change: Modify code format.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: WuZB/2020.11.03
* Change: Modify code format.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: WuZB/2021.04.14
* Change: Modify code version.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: WuZB/2021.11.01
* Change: Update version patch number.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: WuZB/2022.01.04
* Change: Update version patch number.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: WangXG/2022.06.20
* Change: Update version patch number.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: WangXG/2022.06.27
* Change: Update version patch number.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: WangXG/2022.09.22
* Change: Update version patch number.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: WangXG/2023.03.03
* Change: Update version patch number.
*         Initial session supporting multi-core wdg
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date : YuHC/2023.05.17
* Change: Update software version to 3.7.0.
* Cause: Optimize
********************************************************************************
* Version: 3.14
* Author/Date : WangXG/2023.05.26
* Change: Update software version to 3.7.0.0.
* Cause: Optimize
********************************************************************************
* Version: 3.15
* Author/Date: Xuyh/2023.08.08
* Change: Update software version to 3.8.0.1.
* Cause: Optimize
********************************************************************************
* Version: 3.16
* Author/Date: Xuyh/2023.11.21
* Change: Update software version to 3.9.0.1.
* Cause: Optimize
********************************************************************************
* Version: 3.17
* Author/Date: LiuY/2024.03.18
* Change: 1. Modify version number.
*         2. Update software version to 3.10.0.2.
* Cause: Update
********************************************************************************
* Version: 3.18
* Author/Date: LiuY/2024.04.01
* Change: Update software version to 3.10.0.3.
* Cause: Update
********************************************************************************
* Version: 3.19
* Author/Date: LiuY/2024.06.12
* Change: 1. Update software version to 3.11.0.4.
*         2. Modify the declaration of the function WdgM_SetMode to
*            adapt to different AUTOSAR versions.
* Cause: Update
********************************************************************************
* Version: 3.20
* Author/Date: LiuY/2024.07.26
* Change: Add Memmap segment definition.
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date: LiuY/2024.08.02
* Change: Update copyright information.
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date: LiuY/2024.10.09
* Change: 1. Modify the Memmap of multicore variables.
*         2. Update software version to 3.11.0.5.
* Cause: Update
********************************************************************************
* Version: 3.23
* Author/Date: Chixp/2025.2.12
* Change: Update software version to 3.12.0.6.
* Cause: Update
********************************************************************************
* Version: 3.24
* Author/Date: LiuY/2025.02.27
* Change: Update software version to 3.13.0.7.
* Cause: Update
********************************************************************************
* Version: 3.25
* Author/Date: LiuY/2025.03.26
* Change: Update software version to 3.13.0.8.
* Cause: Update
********************************************************************************
* Version: 3.26
* Author/Date: Chixp/2025.03.26
* Change: 1. Fix the QAC warning and add the QAC deviation suppression comment.
*         2. Update software version to 3.13.0.9.
* Cause: Update
********************************************************************************
* Version: 3.27
* Author/Date: Chixp/2025.04.03
* Change: Update software version to 3.13.0.10.
* Cause: Update
********************************************************************************
* Version: 3.28
* Author/Date: Chixp/2025.06.05
* Change: 1.Fix the polyspace warning and add the polyspace deviation suppression
*         comment.
*         2.Update the WDGM_SW_MINOR_VERSION to 14 and the WDGM_SW_REVISION_VERSION to 11.
* Cause: Update
********************************************************************************
* Version: 3.29
* Author/Date: Chixp/2025.06.16
* Change: Update software version to 3.14.0.12.
* Cause: Update
********************************************************************************
* Version: 3.30
* Author/Date: Chixp/2025.06.18
* Change: Update software version to 3.14.0.13.
* Cause: Update
********************************************************************************
* Version: 3.31
* Author/Date: Chixp/2025.06.20
* Change: Update software version to 3.14.0.14.
* Cause: Update
********************************************************************************
* Version: 3.32
* Author/Date: Chixp/2025.06.23
* Change: 1.Update the polyspace deviation suppression comment.
*         2.Update software version to 3.14.0.15.
* Cause: Update
********************************************************************************
* Version: 3.33
* Author/Date: Chixp/2025.06.25
* Change: Update software version to 3.14.0.16.
* Cause: Update
********************************************************************************
* Version: 3.34
* Author/Date: Chixp/2025.08.04
* Change: Update software version to 3.15.0.17.
* Cause: Update
********************************************************************************
*/
#ifndef WDGM_H_
#define WDGM_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "WdgM_Cfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define WDGM_VENDOR_ID           (119U)
#define WDGM_MODULE_ID           (13U)
#define WDGM_SW_MAJOR_VERSION    (3U)
#define WDGM_SW_MINOR_VERSION    (14U)
#define WDGM_SW_PATCH_VERSION    (0U)
#define WDGM_SW_REVISION_VERSION (16U)
#define WDGM_AR_RELEASE_MAJOR_VERSION    (4U)
#define WDGM_AR_RELEASE_MINOR_VERSION    (2U)
#define WDGM_AR_RELEASE_REVISION_VERSION (2U)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

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
#define WDGM_START_SEC_GLOBAL_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h"  /* PRQA S 5087 */  /* NSCA_QAC_Common_MemMap */
extern VAR(uint8, WDGM_VAR_INIT) WdgM_AllCoreInitSync;
extern VAR(uint8, WDGM_VAR_INIT) WdgM_AllCoreSetModeSync;
#define WDGM_STOP_SEC_GLOBAL_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h"  /* PRQA S 5087 */  /* NSCA_QAC_Common_MemMap */

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
#define WDGM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h"  /* PRQA S 5087 */  /* NSCA_QAC_Common_MemMap */
extern FUNC(void, WDGM_CODE) WdgM_Init
(
    P2CONST(WdgM_ConfigType, AUTOMATIC, WDGM_APPL_CONST) ConfigPtr
);
extern FUNC(void, WDGM_CODE) WdgM_DeInit(void);
#if( WDGM_VERSION_INFO_API == STD_ON )
extern FUNC(void, WDGM_CODE) WdgM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, WDGM_APPL_DATA) VersionInfo
);
#endif  /* WDGM_VERSION_INFO_API == STD_ON */
#if ( WDGM_GENERAL_VERSION == WDGM_AUTOSAR422 )
extern FUNC(Std_ReturnType, WDGM_CODE) WdgM_SetMode
(
    WdgM_ModeType Mode,
    uint16 CallerID
);
#else
extern FUNC(Std_ReturnType, WDGM_CODE) WdgM_SetMode
(
    WdgM_ModeType Mode
);
#endif  /* WDGM_GENERAL_VERSION == WDGM_AUTOSAR422 */
extern FUNC(Std_ReturnType, WDGM_CODE) WdgM_GetMode
(
    P2VAR(WdgM_ModeType, AUTOMATIC, WDGM_APPL_DATA) Mode
);
extern FUNC(Std_ReturnType, WDGM_CODE) WdgM_CheckpointReached
(
    WdgM_SupervisedEntityIdType SEID,
    WdgM_CheckpointIdType CheckpointID
);
extern FUNC(Std_ReturnType, WDGM_CODE) WdgM_UpdateAliveCounter
(
    WdgM_SupervisedEntityIdType SEID
);
extern FUNC(Std_ReturnType, WDGM_CODE) WdgM_GetLocalStatus
(
    WdgM_SupervisedEntityIdType SEID, 
    P2VAR(WdgM_LocalStatusType, AUTOMATIC, WDGM_APPL_DATA) Status
);
extern FUNC(Std_ReturnType, WDGM_CODE) WdgM_GetGlobalStatus
(
    P2VAR(WdgM_GlobalStatusType, AUTOMATIC, WDGM_APPL_DATA) Status
);
extern FUNC(void, WDGM_CODE) WdgM_PerformReset( void );
extern FUNC(Std_ReturnType, WDGM_CODE) WdgM_GetFirstExpiredSEID
(
    P2VAR(WdgM_SupervisedEntityIdType, AUTOMATIC, WDGM_APPL_DATA) SEID
);
/* polyspace +1 MISRA-C3:8.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Rule8.5" */
extern FUNC(void, WDGM_CODE) WdgM_MainFunction( void );
#define WDGM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h"  /* PRQA S 5087 */  /* NSCA_QAC_Common_MemMap */

#endif /* WDGM_H_ */
