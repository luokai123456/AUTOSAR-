/*
********************************************************************************
*
* File name: BswM.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: yong.zhang/2018.12.13
* Change: New created
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: yong.zhang/2020.06.08
* Change: Add release software number.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: fangtao/2020.09.15
* Change: Modify the function name according to the AUTOSAR specification, add
*         MemMap.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: FangT/2020.11.04
* Change: Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: FangT/2021.08.17
* Change: Modify the code specification.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: FangT/2021.10.20
* Change: Modified version number.
* Cause: Optimization
********************************************************************************
*  Version: 3.6
*  Author/Date: FangT/2021.11.01
*  Change: Update software version to 3.3.1.
*  Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: FangT/2021.11.3
* Change: Add FrSM related functions.
* Cause: Optimization
********************************************************************************
*  Version: 3.8
*  Author/Date: HeHao/2022.06.16
*  Change: Update software version to 3.3.2.
*  Cause: Update
********************************************************************************
*  Version: 3.9
*  Author/Date: HeHao/2022.06.20
*  Change: 1. Merge from Branch_21Q2.
*          2. Update software version to 3.3.3.
*  Cause: Update
********************************************************************************
*  Version: 3.10
*  Author/Date: FangT/2022.09.05
*  Change: Update software version to 3.3.4.
*  Cause: Update
********************************************************************************
* Version: 3.33
* Author/Date: FangT/2022.09.22
* Change: 1.Add multi-core capability.
*         2.Update software version to 3.3.5.
* Cause: Optimization
********************************************************************************
* Version: 3.34
* Author/Date: FangT/2022.11.17
* Change: 1.Resolve initialization problems.
*         2.Update software version to 3.3.6.
* Cause: Optimization
********************************************************************************
* Version: 3.35
* Author/Date: FangT/2023.01.12
* Change: 1.Resolve initialization problems.
*         2.Update software version to 3.3.7.
* Cause: Optimization
********************************************************************************
* Version: 3.36
* Author/Date: FangT/2023.05.17
* Change: Update software version to 3.7.0.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: FangT/2023.05.26
* Change: Add BSWM_REVISION_VERSION.
* Cause: Optimize.
********************************************************************************
* Version: 3.12
* Author/Date: HeHao/2023.08.01
* Change: Update software version to 3.8.0.1.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: HeHao/2023.11.02
* Change: Update software version to 3.9.0.1.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: HeHao/2023.12.04
* Change: Delete BswM_CurrentPartIdx.
*         Add RootPartitionId for BswM_ProcessingState_st struct.
*         Update software version to 3.9.0.2.
* Cause: Update
********************************************************************************
* Version: 3.15
* Author/Date: HeHao/2023.12.06
* Change: Add RootApplicationId for BswM_ProcessingState_st struct.
* Cause: Update
********************************************************************************
* Version: 3.16
* Author/Date: HeHao/2023.12.25
* Change: 1. Add prototype for BswM_MemCmp, BswM_MemCpy, BswM_MemSet functions.
*         2. Add BSWM_EQUAL, BSWM_NOT_EQUAL macros for BswM_MemCmp function.
*         3. Update software version to 3.9.0.3.
* Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date: HeHao/2023.12.25
* Change: 1. Change prototype for BswM_MemCmp, BswM_MemCpy, BswM_MemSet functions.
* Cause: Update
********************************************************************************
* Version: 3.18
* Author/Date: HeHao/2024.03.11
* Change: 1. Change P2CONST's ptrclass from XXX_APPL_CONST to XXX_APPL_DATA.
*         2. Update software version to 3.10.0.1.
* Cause: Update
********************************************************************************
* Version: 3.19
* Author/Date: HeHao/2024.04.02
* Change: 1. Change P2CONST's ptrclass.
*         2. Update software version to 3.10.0.2.
*         3. Modify comments.
* Cause: Update
********************************************************************************
* Version: 3.20
* Author/Date: LuQ/2024.07.26
* Change: 1. Update software version to 3.11.0.3.
*         2. Add MemMap segment definition.
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date: LuQ/2024.08.28
* Change: 1. Update software version to 3.11.0.4.
*         2. Modify MemMap segment definition.
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date: LuQ/2025.03.27
* Change: Update software version to 3.13.0.5.
* Cause: Update
********************************************************************************
* Version: 3.23
* Author/Date: LuQ/2025.06.17
* Change: 1. Add the polyspace deviation suppression comment.
*         2. Update software version to 3.14.0.6.
* Cause: Update
********************************************************************************
* Version: 3.24
* Author/Date: LuQ/2025.06.23
* Change: 1. Modify MemMap segment definition.
*         2. Update software version to 3.14.0.7.
* Cause: Bugfix
********************************************************************************
*/
#ifndef BSWM_H_
#define BSWM_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "BswM_Cfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* DET error codes. */
/* PolySpace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define BSWM_E_NO_ERROR                 ((uint8)0x00U)  /* used to check if no error occurred. */
#define BSWM_E_NO_INIT                  ((uint8)0x01U)  /* A service was called prior to initialization. */
#define BSWM_E_NULL_POINTER             ((uint8)0x02U)  /* A null pointer was passed as an argument. */
#define BSWM_E_PARAM_INVALID            ((uint8)0x03U)  /* A parameter was invalid (unspecific). */
#define BSWM_E_REQ_USER_OUT_OF_RANGE    ((uint8)0x04U)  /* A requesting user was out of range. */
#define BSWM_E_REQ_MODE_OUT_OF_RANGE    ((uint8)0x05U)  /* A requested mode was out of range. */
#define BSWM_E_PARAM_CONFIG             ((uint8)0x06U)  /* The provided configuration is inconsistent. */
#define BSWM_E_PARAM_POINTER            ((uint8)0x07U)  /* A parameter pointer was invalid */
#define BSWM_E_INIT_FAILED              ((uint8)0x08U)  /* Invalid configuration set selection */

#define BSWM_E_ALREADY_INITIALIZED      ((uint8)0x80U)  /* The module is already initialized. */
#define BSWM_E_ALREADY_QUEUED           ((uint8)0xA0U)  /* An immediate request was made before the last request of the same port was processed. */
#define BSWM_E_REQ_USER_WRONG_PARTITION ((uint8)0xA1U)
#define BSWM_E_ACTION_LIST_QUEUE_ERROR  ((uint8)0xB0U)  /* An error occurred while manipulating the Action List Queue. */

/* Modes */
#define BSWM_FALSE                      ((uint8)0x00U)
#define BSWM_TRUE                       ((uint8)0x01U)
#define BSWM_UNDEFINED                  ((uint8)0x02U)
#define BSWM_DEACTIVATED                ((uint8)0x03U)

#define BSWM_NOT_EQUAL                  ((uint8)0x00U)
#define BSWM_EQUAL                      ((uint8)0x01U)

/* Timer Status. */
#define BSWM_TIMER_STOPPED              ((uint8)0x00U)
#define BSWM_TIMER_STARTED              ((uint8)0x01U)
#define BSWM_TIMER_EXPIRED              ((uint8)0x02U)

/* Numbers */
#define BSWM_ZERO                       (0x00U)
#define BSWM_ONE                        (0x01U)
#define BSWM_TWO                        (0x02U)
#define BSWM_INVALID_VALUE              (0xFFU)

/* Vendor and module identification. */
#define BSWM_VENDOR_ID                  (119U)
#define BSWM_MODULE_ID                  (42U)

#define BSWM_SW_MAJOR_VERSION           (3U)
#define BSWM_SW_MINOR_VERSION           (14U)
#define BSWM_SW_PATCH_VERSION           (0U)
#define BSWM_SW_REVISION_VERSION        (7U)

#define BSWM_AR_RELEASE_MAJOR_VERSION    (4U)
#define BSWM_AR_RELEASE_MINOR_VERSION    (2U)
#define BSWM_AR_RELEASE_REVISION_VERSION (2U)

#define BSWM_INSTANCE_ID_DET             (0x00U)

/* Development Error Detection. */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro"  PolySpace +1 MISRA-C3:5.4 [Justified:Unset] "NSCA_Polyspace_BswM_5.4" */
#define BswM_ReportDevError(SID, ERROR)    ((void)Det_ReportError(BSWM_MODULE_ID, BSWM_INSTANCE_ID_DET, (SID), (ERROR)))

/* Dummy statement. */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro"  PolySpace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_BswM_17.8" */
#define BSWM_DUMMY_STATEMENT(v)                  (v)=(v)

/* API service IDs. */
#define BSWM_INIT_ID                             ((uint8)0x00U)
#define BSWM_GETVERSIONINFO_ID                   ((uint8)0x01U)
#define BSWM_REQUESTMODE_ID                      ((uint8)0x02U)
#define BSWM_MAINFUNCTION_ID                     ((uint8)0x03U)
#define BSWM_DEINIT_ID                           ((uint8)0x04U)
#define BSWM_CANSM_CURRENTSTATE_ID               ((uint8)0x05U)
#define BSWM_DCM_COMMUNICATION_STATE_ID          ((uint8)0x06U)
#define BSWM_LINSM_CURRENTSTATE_ID               ((uint8)0x09U)
#define BSWM_LINSM_CURRENTSCHEDULE_ID            ((uint8)0x0AU)
#define BSWM_LINTP_REQUESTMODE_ID                ((uint8)0x0BU)
#define BSWM_FRSM_CURRENTSTATE_ID                ((uint8)0x0CU)
#define BSWM_ETHSM_CURRENTSTATE_ID               ((uint8)0x0DU)
#define BSWM_COMM_CURRENTMODE_ID                 ((uint8)0x0EU)
#define BSWM_ECUM_CURRENTSTATE_ID                ((uint8)0x0FU)
#define BSWM_ECUM_CURRENTWAKEUP_ID               ((uint8)0x10U)
#define BSWM_WDGM_REQUESTPARTITIONRESET_ID       ((uint8)0x11U)
#define BSWM_DCM_APPLICATION_UPDATED_ID          ((uint8)0x14U)
#define BSWM_COMM_PNC_CURRENTMODE_ID             ((uint8)0x15U)
#define BSWM_NVM_CURRENTBLOCKMODE_ID             ((uint8)0x16U)
#define BSWM_NVM_CURRENTJOBMODE_ID               ((uint8)0x17U)
#define BSWM_J1939NM_STATE_ID                    ((uint8)0x18U)
#define BSWM_J1939DCM_BROADCASTSTATUS_ID         ((uint8)0x1bU)
#define BSWM_SD_CLIENTSERVICE_CURRENT_ID         ((uint8)0x1fU)
#define BSWM_SD_EVENTHANDLER_CURRENT_ID          ((uint8)0x20U)
#define BSWM_SD_CONSUMEDEVENTGROUP_ID            ((uint8)0x21U)
#define BSWM_COMM_INITIATERESET_ID               ((uint8)0x22U)
#define BSWM_ECUM_REQUESTEDSTATE_ID              ((uint8)0x23U)
#define BswM_CANSM_CURRENTICOMCONFIGURATION_ID   ((uint8)0x1aU)
/* PolySpace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* Neusar Service IDs. */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_BswM_2.4" */
typedef struct sBswM_ProcessingState_st
{
    /* To mark if current partition's BswM is in init mode or in normal mode. */
    uint8 ProcessingState;

    /* To store the BswM's own partition id. */
    uint8 PartitionId;

    /* To store from which partition the BswM instance is initialized. */
    uint8 RootPartitionId;

    /* To store from which application the BswM instance is initialized. */
    uint8 RootApplicationId;
} BswM_ProcessingState_st;
/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define BSWM_START_SEC_GLOBAL_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h"
extern VAR(uint8, BSWM_VAR_NO_INIT)BswM_QueueSemaphore[BSWM_BSWMCONFIG_SIZE];
extern VAR(boolean, BSWM_VAR_NO_INIT)BswM_QueueWritten[BSWM_BSWMCONFIG_SIZE];

#if( BSWM_MULTIPARTITION == STD_ON )
extern VAR(BswM_ProcessingState_st, BSWM_VAR_NO_INIT)BswM_ProcessingState[BSWM_BSWMCONFIG_SIZE];
#endif
#define BSWM_STOP_SEC_GLOBAL_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h"

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
#define BSWM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h"
extern FUNC(void, BSWM_CODE) BswM_Init
(
    P2CONST(BswM_ConfigType, AUTOMATIC, BSWM_APPL_CONST)ConfigPtr
);
extern FUNC(void, BSWM_CODE) BswM_Deinit(void);
extern FUNC(void, BSWM_CODE) BswM_RequestMode
(
    BswM_UserType requesting_user,
    BswM_ModeType requested_mode
);
extern FUNC(void, BSWM_CODE) BswM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, BSWM_APPL_DATA)versioninfo
);
extern FUNC(void, BSWM_CODE) BswM_MainFunction(void);
extern FUNC(void, BSWM_CODE) BswM_ImmediateModeRequest
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.5" */
    uint8 start,
    uint8 end,
    uint8 partitionIdx,
    uint8 partitionId
);

/* Functions for BswM module internal use only. */
#if( BSWM_SWCMODEREQUEST_DATA_INIT == STD_ON )
extern FUNC(uint8, BSWM_CODE) BswM_MemCmp
(
    P2CONST(void, AUTOMATIC, BSWM_APPL_DATA) dstPtr,
    P2CONST(void, AUTOMATIC, BSWM_APPL_DATA) srcPtr,
    uint32 size
);
extern FUNC(void, BSWM_CODE) BswM_MemCpy
(
    P2VAR(void, AUTOMATIC, BSWM_APPL_DATA) dstPtr,
    P2CONST(void, AUTOMATIC, BSWM_APPL_DATA) srcPtr,
    uint32 size
);
extern FUNC(void, BSWM_CODE) BswM_MemSet
(
    P2VAR(void, AUTOMATIC, BSWM_APPL_DATA) dstPtr,
    uint8 value,
    uint32 size
);
#endif  /* BSWM_SWCMODEREQUEST_DATA_INIT == STD_ON */
#define BSWM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h"

#endif  /* BSWM_H_ */

