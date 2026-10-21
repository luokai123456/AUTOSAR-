/*
********************************************************************************
*
* File name: FiM.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : Sunpengfei/2018.07.10
* Change: New Create.
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date : Liuziyang/2019.11.13
* Change: The format of code and comment.
* Cause: Modify the code according to the coding specification.
********************************************************************************
* Version: 3.0
* Author/Date: Liuziyang/2020.03.26
* Change: Add struct definition.
* Cause: Optimization and update to V3.0.
********************************************************************************
* Version: 3.1
* Author/Date: Liuziyang/2020.05.19
* Change: Modify file format.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date : Yaoxingjia/2020.06.08
* Change: Add release software number.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: Liuziyang/2020.08.18
* Change: Modify the problem of compiling when the configuration is empty.
* Cause: Bugfix.
********************************************************************************
* Version: 3.4
* Author/Date : liuziyang/2020.09.15
* Change: Add function of MemMap.
* Cause: Optimization.
********************************************************************************
* Version: 3.5
* Author/Date : liuziyang/2020.09.17
* Change: Include the file Det.h.
* Cause: Optimization.
********************************************************************************
* Version: 3.6
* Author/Date: liuziyang/2020.09.19
* Change: Modify the code format to autosar standard
* Cause: Optimization.
********************************************************************************
* Version: 3.7
* Author/Date: Liuziyang/2020.09.28
* Change: Optimize the file inclusion relationship of this file.
* Cause: Bugfix.
********************************************************************************
* Version: 3.8
* Author/Date: Liuziyang/2020.09.30
* Change: Delete some incorrect comments.
* Cause: Bugfix.
********************************************************************************
* Version: 3.9
* Author/Date : liuziyang/2020.10.15
* Change:Modify questions above QAC-4.
* Cause: Optimization.
********************************************************************************
* Version: 3.10
* Author/Date: LiuZY/2020.11.03
* Change: Modify the incorrectly defined part of the code format.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: LiuZY/2020.11.14
* Change: Modify the code review record.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date: LiuZY/2020.12.10
* Change: Modify the counter type to uint16.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: XieYN/2021.04.12
* Change: Update the Version Information.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: XieYN/2021.06.8
* Change: declare Stub FiM_DemTriggerOnComponentStatus.
* Cause: Bugfix
********************************************************************************
* Version: 3.15
* Author/Date: XieYN/2021.06.30
* Change: Separate macro definitions by category and modify the comment format.
* Cause: Optimization
********************************************************************************
* Version: 3.16
* Author/Date: XieYN/2021.08.12
* Change:Modify code specifications.
* Cause: Optimization
********************************************************************************
* Version: 3.17
* Author/Date: XieYN/2021.10.20
* Change:Nothing.
* Cause: Update to V3.3.0
********************************************************************************
* Version: 3.18
* Author/Date: XieYN/2022.01.18
* Change:Update FIM_SW_PATCH_VERSION.
* Cause: Update to V3.3.1
********************************************************************************
* Version: 3.19
* Author/Date: MengY/2022.10.25
* Change:Modify the names of the Macro according to the document.
* Cause: Bugfix
********************************************************************************
* Version: 3.20
* Author/Date: MengY/2022.11.25
* Change: Add code about the function of postbuild.
* Cause: Optimization
********************************************************************************
* Version: 3.21
* Author/Date: MengY/2022.12.02
* Change: Modify code about the function of postbuild.
* Cause: Bugfix
********************************************************************************
* Version: 3.22
* Author/Date: MengY/2023.01.12
* Change:Update the patch version.
* Cause: Bugfix
********************************************************************************
* Version: 3.23
* Author/Date: MengY/2023.05.11
* Change:Update the patch version.
* Cause: Bugfix
********************************************************************************
* Version: 3.24
* Author/Date: MengY/2023.05.17
* Change:Update the Version Information.
* Cause: Update
********************************************************************************
* Version: 3.25
* Author/Date: FanHT/2023.08.03
* Change: 1. Update the Version Information.
*         2. Add include "Dem.h" to "FiM.h".
*         3. Add FIM_SW_REVISION_VERSION.
* Cause: Update
********************************************************************************
* Version: 3.26
* Author/Date: ChenQJ/2023.12.26
* Change: 1. Re-design the data structure and code logic for performance
*         optimization.
*         2. Change version to 3.10.0.1
* Cause: Optimization
********************************************************************************
* Version: 3.27
* Author/Date: ChenQJ/2024.01.17
* Change: 1. Fix QAC, polyspace and compile warning.
*         2. Modify FiM_DemTriggerOnEventStatus() for Dem.
*         3. Change version to 3.10.0.2
* Cause: Optimization
********************************************************************************
* Version: 3.28
* Author/Date: ChenQJ/2024.01.29
* Change: 1. Do not compile FiM_DemTriggerOnEventStatus() when
*            FiMEventUpdateTriggeredByDem is not enabled.
*         2. Change version to 3.10.0.3
* Cause: Optimization
********************************************************************************
* Version: 3.29
* Author/Date: ChenQJ/2024.03.11
* Change: 1. Remove no use space from the end of each rows.
*         2. Change version to 3.10.0.4.
* Cause: Optimization
********************************************************************************
* Version: 3.30
* Author/Date: TianG/2024.05.10
* Change: 1.Add a memory-map label to function declarations.
*         2.Modify format of comment.
*         3.Change version to 3.11.0.5.
* Cause: Optimization
********************************************************************************
* Version: 3.31
* Author/Date: TianG/2024.06.28
* Change: Modify copyright.
* Cause: Optimization
********************************************************************************
* Version: 3.32
* Author/Date: TianG/2024.09.13
* Change: 1.Modify FiM_START_SEC_CODE to FIM_START_SEC_CODE.
*         2.Change version to 3.11.0.6.
* Cause: Optimization
********************************************************************************
* Version: 3.33
* Author/Date: TianG/2025.03.25
* Change: Change version to 3.13.0.7.
* Cause: Optimization
********************************************************************************
* Version: 3.34
* Author/Date: TianSL/2025.06.12
* Change: 1.Add the polyspace deviation suppression comment.
*         2.Change version to 3.14.0.8.
* Cause: Optimization
********************************************************************************
*/
#ifndef FIM_H_
#define FIM_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "FiM_Lcfg.h"
#include "Dem.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Vendor and module identification. */
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define FIM_MODULE_ID                                 (11U)
#define FIM_VENDOR_ID                                 (119U)

/* Component version information (decimal version of ALM implementation package). */
#define FIM_SW_MAJOR_VERSION                          (3U)
#define FIM_SW_MINOR_VERSION                          (14U)
#define FIM_SW_PATCH_VERSION                          (0U)
#define FIM_SW_REVISION_VERSION                       (8U)

/* AUTOSAR Version. */
#define FIM_AR_RELEASE_MAJOR_VERSION                  (4U)
#define FIM_AR_RELEASE_MINOR_VERSION                  (2U)
#define FIM_AR_RELEASE_REVISION_VERSION               (2U)

/* Instance ID. */
#define FIM_INSTANCE_ID                               (0U)

/* Inhibition Counter state. */
#define FIM_FID_NOCHANGE                              (0x00U)
#define FIM_FID_INC                                   (0x01U)
#define FIM_FID_DEC                                   (0x02U)

/* FiM is in uninitialized state. */
#define FIM_UNINITIALIZED                             (0U)
/* FiM is fully initialized. */
#define FIM_INITIALIZED                               (1U)
/* FiM is in pre-initialized state (FiM_Init was executed but not FiM_DemInit). */
#define FIM_PREINITIALIZED                            (2U)

/* Number of inhibitionMode. */
#define FIM_INHCODE_NUMBER                            (4U)

/* API function called before the FiM module has been full initialized or after the FiM module has been shut down. */
#define FIM_E_UNINIT                                  (0x01U)
/* FiM_GetFunctionPermission called with wrong FID. */
#define FIM_E_FID_OUT_OF_RANGE                        (0x02U)
/* Dem calls FiM with invalid EventId. */
#define FIM_E_EVENTID_OUT_OF_RANGE                    (0x03U)
/* API is invoked with NULL Pointer. */
#define FIM_E_PARAM_POINTER                           (0x04U)
/* Invalid configuration set selection. */
#define FIM_E_INIT_FAILED                             (0x05U)

/* DEM_UDS_STATUS_TF */
#define FIM_LAST_FAILED_MASK                          (Dem_EventStatusExtendedType)0x01U
/* DEM_UDS_STATUS_TF set. */
#define FIM_LAST_FAILED_PATTERN                       (Dem_EventStatusExtendedType)0x01U
/* DEM_UDS_STATUS_TNCTOC */
#define FIM_TESTED_MASK                               (Dem_EventStatusExtendedType)0x40U
/* DEM_UDS_STATUS_TNCTOC not set. */
#define FIM_TESTED_PATTERN                            (Dem_EventStatusExtendedType)0x00U
/* DEM_UDS_STATUS_TNCTOC */
#define FIM_NOT_TESTED_MASK                           (Dem_EventStatusExtendedType)0x40U
/* DEM_UDS_STATUS_TNCTOC set. */
#define FIM_NOT_TESTED_PATTERN                        (Dem_EventStatusExtendedType)0x40U
/* DEM_UDS_STATUS_TNCTOC | DEM_UDS_STATUS_TF */
#define FIM_TESTED_AND_FAILED_MASK                    (Dem_EventStatusExtendedType)0x41U
/* DEM_UDS_STATUS_TNCTOC not set, DEM_UDS_STATUS_TF set. */
#define FIM_TESTED_AND_FAILED_PATTERN                 (Dem_EventStatusExtendedType)0x01U
/* DEM_UDS_STATUS_TNCTOC | DEM_UDS_STATUS_TF */
#define FIM_NOT_TESTED_OR_FAILED_MASK                 (Dem_EventStatusExtendedType)0x41U
/* DEM_UDS_STATUS_TNCTOC not set, DEM_UDS_STATUS_TF not set. */
#define FIM_NOT_TESTED_OR_FAILED_PATTERN              (Dem_EventStatusExtendedType)0x00U

/* Prevent magic number in static code. */
#define FIM_FF_VALUE                                  (0xFFU)
#define FIM_SIGN_VALUE_0                              (0U)
#define FIM_SIGN_VALUE_1                              (1U)
#define FIM_SIGN_VALUE_2                              (2U)

/* FiM should poll all event per period(Only use in polling mode). */
#define FIM_POLL_ALL_EVENT                            (0xFFFFU)

/* The bitmap size of FID available array. */
#define FIM_FIDAVAILABLE_BITMAP_SIZE                  ((FIM_MAX_FID_NUM >> 3U) + 1U)

/* API service IDs. */
#define FIM_SID_INIT                                  (0x00U)
#define FIM_SID_GETFUNCTIONPERMISSION                 (0x01U)
#define FIM_SID_SETFUNCTIONAVAILABLE                  (0x07U)
#define FIM_SID_DEMTRIGGERONEVENTSTATUS               (0x02U)
#define FIM_SID_DEMINIT                               (0x03U)
#define FIM_SID_GETVERSIONINFO                        (0x04U)
#define FIM_SID_MAINFUNCTION                          (0x05U)

#ifndef FIM_DUMMY_STATEMENT
/* polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_FiM_Rule17.8" polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_FiM_RuleD4.9" */
#define FIM_DUMMY_STATEMENT(v)                        (v)=(v)
#endif
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
#define FIM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "FiM_MemMap.h"
extern FUNC(void, FIM_CODE) FiM_Init
(
    P2CONST(FiM_ConfigType, AUTOMATIC, FIM_APPL_CONST) FiMConfigPtr
);

extern FUNC(void, FIM_CODE) FiM_DemInit(void);

extern FUNC(Std_ReturnType, FIM_CODE) FiM_GetFunctionPermission
(
    FiM_FunctionIdType FID,
    P2VAR(boolean, AUTOMATIC, FIM_APPL_DATA) Permission
);

#if( FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_ON )
extern FUNC(void, FIM_CODE) FiM_DemTriggerOnEventStatus
(
    Dem_EventIdType EventId,
    Dem_UdsStatusByteType EventStatusByteOld,
    Dem_UdsStatusByteType EventStatusByteNew
);

extern FUNC(void, FIM_CODE) FiM_DemTriggerOnComponentStatus
(
    Dem_ComponentIdType ComponentId,
    boolean ComponentFailedStatus
);
#endif  /* FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_ON */

#if( FIM_SUPPORT_AVAILABLE == STD_ON )
extern FUNC(Std_ReturnType, FIM_CODE) FiM_SetFunctionAvailable
(
    FiM_FunctionIdType FID,
    boolean Availability
);
#endif  /* FIM_SUPPORT_AVAILABLE == STD_ON */

#if( FIM_VERSION_INFO_API == STD_ON )
extern FUNC(void, FIM_CODE) FiM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, FIM_APPL_DATA) versioninfo
);
#endif  /* FIM_VERSION_INFO_API == STD_ON */

#define FIM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "FiM_MemMap.h"

#endif  /* FIM_H_ */

