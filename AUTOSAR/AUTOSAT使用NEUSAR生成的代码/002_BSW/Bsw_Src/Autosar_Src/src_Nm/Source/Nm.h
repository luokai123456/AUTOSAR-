/*
*******************************************************************************
*
*  File name: Nm.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
*******************************************************************************
*
*  History
*------------------------------------------------------------------------------
*******************************************************************************
* Version: 1.0
* Author/Date: ZhangY/2018.12.21
* Change: New created.
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: ZhangY/2019.11.13
* Change: Standardize code style.
* Cause: Optimization
********************************************************************************
* Version: 3.0
* Author/Date: JiaF/2020.06.08
* Change: Add autosar release version.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: JiaF/2020.08.21
* Change: Modify the judge of #if( NM_COORDINATOR_SUPPORT_ENABLED == STD_ON ).
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: GuoZY/2020.10.27
* Change: Modify the code according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: JiaF/2020.11.09
* Change: Add function about coordinator.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: jiaF/2021.4.12
* Change: Update software version to 3.2.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: jiaF/2021.9.1
* Change: Modify the code specification.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: jiaF/2021.10.20
* Change: Update software version to 3.3.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: LiX/2023.3.31
* Change: Remove duplicate code and update software version to 3.3.1.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date:LiX/2023.5.23
* Change: Add external declarations of Nm_CarWakeUpIndication.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: LiX/2023.5.26
* Change: Add REVISION version.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: LiZL/2024.3.19
* Change: Update software version to 3.10.0.2.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: LiZL/2024.4.1
* Change: 1.Perfect code specification.
*         2.Update software version to 3.10.0.3.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: TianSL/2024.6.26
* Change: 1.Add Memmap segment definition.
*         2.Modify copyright.
*         3.Update software version to 3.11.0.4.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date: TianSL/2024.8.28
* Change: Update software version to 3.11.0.5.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: TianSL/2024.09.30
* Change: 1.Modify the coding specification.
*         2.Update software version to 3.11.0.6.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: TianSL/2024.09.30
* Change: Update software version to 3.13.0.7.
* Cause: Optimization
********************************************************************************
* Version: 3.14
* Author/Date: TianSL/2025.05.27
* Change: 1.Update software version to 3.14.0.8.
*         2.Add the polyspace deviation suppression comment.
* Cause: Optimization
********************************************************************************
* Version: 3.15
* Author/Date: TianSL/2025.07.16
* Change: Update software version to 3.15.0.9.
* Cause: Optimization
********************************************************************************
*/
#ifndef NM_H_
#define NM_H_

/*
*******************************************************************************
*    Includes
*******************************************************************************
*/
#include "Nm_Cfg.h"

/*
*******************************************************************************
*    Global Macros
*******************************************************************************
*/

/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NM_UNINIT                           (0U)
#define NM_INIT                             (1U)
#define NM_ZERO                             (0U)
#define NM_ONE                              (1U)

/* Vendor and module identification. */
#define NM_VENDOR_ID                        (119U)
#define NM_MODULE_ID                        (71U)

/* Component version information. */
#define NM_SW_MAJOR_VERSION                 (3U)
#define NM_SW_MINOR_VERSION                 (15U)
#define NM_SW_PATCH_VERSION                 (0U)
#define NM_SW_REVISION_VERSION              (9U)

#define NM_AR_RELEASE_MAJOR_VERSION         (4U)
#define NM_AR_RELEASE_MINOR_VERSION         (2U)
#define NM_AR_RELEASE_REVISION_VERSION      (2U)

#define NM_INSTANCE_ID                      (0x00U)

/* API service IDs. */
#define NM_SID_INIT                         (0x00U)
#define NM_SID_PASSIVESTARTUP               (0x01U)
#define NM_SID_NETWORKREQUEST               (0x02U)
#define NM_SID_NETWORKRELEASE               (0x03U)
#define NM_SID_DISABLECOMMUNICATION         (0x04U)
#define NM_SID_ENABLECOMMUNICATION          (0x05U)
#define NM_SID_SETUSERDATA                  (0x06U)
#define NM_SID_GETUSERDATA                  (0x07U)
#define NM_SID_GETPDUDATA                   (0x08U)
#define NM_SID_REPEATMESSAGEREQUEST         (0x09U)
#define NM_SID_GETNODEIDENTIFIER            (0x0AU)
#define NM_SID_GETLOCALNODEIDENTIFIER       (0x0BU)
#define NM_SID_CHECKREMOTESLEEPINDICATION   (0x0DU)
#define NM_SID_GETSTATE                     (0x0EU)
#define NM_SID_GETVERSIONINFO               (0x0FU)
#define NM_SID_MAINFUNCTION                 (0x10U)
#define NM_SID_INITMEMORY                   (0x20U)

/* API error IDs. */
#define NM_E_UNINIT                         (0x00U)      /* API service used without module initialization. */
#define NM_E_HANDLE_UNDEF                   (0x01U)      /* API service used with wrong channel handle. */
#define NM_E_PARAM_POINTER                  (0x02U)      /* API service called with a NULL pointer. */
#define NM_E_REINIT                         (0x03U)      /* API service called with a reinit. */
#define NM_E_NO_ERROR                       (0xFFU)      /* No error. */

/* Development Error Detection. */
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" polyspace +1 MISRA-C3:5.4 [Justified:Unset] "NSCA_Polyspace_Nm_Rule5.4" */
#define Nm_ReportDevError(SID, ERROR)     ((void)Det_ReportError(NM_MODULE_ID, NM_INSTANCE_ID, (SID), (ERROR)))
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/*
*******************************************************************************
*    Global Types
*******************************************************************************
*/
/*
*******************************************************************************
*    Global variables
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

#define NM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Nm_MemMap.h"

extern FUNC(void, NM_CODE) Nm_Init
(
    P2CONST(Nm_ConfigType, AUTOMATIC, NM_APPL_CONST) ConfigPtr
);

#if( NM_VERSION_INFO_API == STD_ON )
extern FUNC(void, NM_CODE) Nm_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, NM_APPL_DATA) nmVerInfoPtr
);
#endif

extern FUNC(Std_ReturnType, NM_CODE) Nm_PassiveStartUp
(
    NetworkHandleType nmNetworkHandle
);

#if( NM_PASSIVE_MODE_ENABLED == STD_OFF )
extern FUNC(Std_ReturnType, NM_CODE) Nm_NetworkRequest
(
    NetworkHandleType nmNetworkHandle
);
extern FUNC(Std_ReturnType, NM_CODE) Nm_NetworkRelease
(
    NetworkHandleType nmNetworkHandle
);
#endif

#if( NM_COM_CONTROL_ENABLED == STD_ON )
extern FUNC(Std_ReturnType, NM_CODE) Nm_DisableCommunication
(
    NetworkHandleType nmNetworkHandle
);
extern FUNC(Std_ReturnType, NM_CODE) Nm_EnableCommunication
(
    NetworkHandleType nmNetworkHandle
);
#endif

#if( NM_USER_DATA_ENABLED == STD_ON )

#if( (NM_PASSIVE_MODE_ENABLED == STD_OFF) && (NM_COM_USER_DATA_SUPPORT == STD_OFF) )
extern FUNC(Std_ReturnType, NM_CODE) Nm_SetUserData
(
    NetworkHandleType nmNetworkHandle,
    P2CONST(uint8, AUTOMATIC, NM_APPL_CONST) nmUserDataPtr
);
#endif  /* ( NM_PASSIVE_MODE_ENABLED == STD_OFF ) && ( NM_COM_USER_DATA_SUPPORT == STD_OFF ) */

extern FUNC(Std_ReturnType, NM_CODE) Nm_GetUserData
(
    NetworkHandleType nmNetworkHandle,
    P2VAR(uint8, AUTOMATIC, NM_APPL_DATA) nmUserDataPtr
);
#endif  /* NM_USER_DATA_ENABLED == STD_ON */

#if( (NM_NODE_ID_ENABLED == STD_ON) || (NM_USER_DATA_ENABLED == STD_ON) )
extern FUNC(Std_ReturnType, NM_CODE) Nm_GetPduData
(
    NetworkHandleType nmNetworkHandle,
    P2VAR(uint8, AUTOMATIC, NM_APPL_DATA) nmPduDataPtr
);
#endif  /* (NM_NODE_ID_ENABLED == STD_ON) || (NM_USER_DATA_ENABLED == STD_ON) */

#if( NM_NODE_DETECTION_ENABLED == STD_ON )
extern FUNC(Std_ReturnType, NM_CODE) Nm_RepeatMessageRequest
(
    NetworkHandleType nmNetworkHandle
);
#endif  /* NM_NODE_DETECTION_ENABLED == STD_ON */

#if( NM_NODE_ID_ENABLED == STD_ON )
extern FUNC(Std_ReturnType, NM_CODE) Nm_GetNodeIdentifier
(
    NetworkHandleType nmNetworkHandle,
    P2VAR(uint8, AUTOMATIC, NM_APPL_DATA) nmNodeIdPtr
);
extern FUNC(Std_ReturnType, NM_CODE) Nm_GetLocalNodeIdentifier
(
    NetworkHandleType nmNetworkHandle,
    P2VAR(uint8, AUTOMATIC, NM_APPL_DATA) nmNodeIdPtr
);
#endif  /* NM_NODE_ID_ENABLED == STD_ON */

#if( NM_REMOTE_SLEEP_IND_ENABLED == STD_ON )
extern FUNC(Std_ReturnType, NM_CODE) Nm_CheckRemoteSleepIndication
(
    NetworkHandleType nmNetworkHandle,
    P2VAR(boolean, AUTOMATIC, NM_APPL_DATA) nmRemoteSleepIndPtr
);
#endif

#if( NM_COORDINATOR_SYNC_SUPPORT == STD_ON )
extern FUNC(void, NM_CODE) Nm_CoordReadyToSleepIndication
(
    NetworkHandleType nmNetworkHandle
);
extern FUNC(void, NM_CODE) Nm_CoordReadyToSleepCancellation
(
    NetworkHandleType nmNetworkHandle
);
#endif

extern FUNC(Std_ReturnType, NM_CODE) Nm_GetState
(
    NetworkHandleType nmNetworkHandle,
    P2VAR(Nm_StateType, AUTOMATIC, NM_APPL_DATA) nmStatePtr,
    P2VAR(Nm_ModeType, AUTOMATIC, NM_APPL_DATA) nmModePtr
);
extern FUNC(void, NM_CODE) Nm_NetworkStartIndication
(
    NetworkHandleType nmNetworkHandle
);
extern FUNC(void, NM_CODE) Nm_NetworkMode
(
    NetworkHandleType nmNetworkHandle
);
extern FUNC(void, NM_CODE) Nm_BusSleepMode
(
    NetworkHandleType nmNetworkHandle
);
extern FUNC(void, NM_CODE) Nm_PrepareBusSleepMode
(
    NetworkHandleType nmNetworkHandle
);

#if( NM_CAR_WAKE_UP_RX_ENABLED == STD_ON )
extern FUNC(void,NM_CODE) Nm_CarWakeUpIndication
(
    NetworkHandleType nmNetworkHandle
);
#endif

#if( NM_REMOTE_SLEEP_IND_ENABLED == STD_ON )
extern FUNC(void, NM_CODE) Nm_RemoteSleepIndication
(
    NetworkHandleType nmNetworkHandle
);
extern FUNC(void, NM_CODE) Nm_RemoteSleepCancellation
(
    NetworkHandleType nmNetworkHandle
);
#endif  /* NM_REMOTE_SLEEP_IND_ENABLED == STD_ON */

#if( NM_PDU_RX_INDICATION_ENABLED == STD_ON )
extern FUNC(void, NM_CODE) Nm_PduRxIndication
(
    NetworkHandleType nmNetworkHandle
);
#endif

#if( NM_STATE_CHANGE_IND_ENABLED == STD_ON )
extern FUNC(void, NM_CODE) Nm_StateChangeNotification
(
    NetworkHandleType nmNetworkHandle,
    Nm_StateType nmLastState,
    Nm_StateType nmCurrentState
);
#endif

#if( NM_REPEAT_MSG_IND_ENABLED == STD_ON )
extern FUNC(void, NM_CODE) Nm_RepeatMessageIndication
(
    NetworkHandleType nmNetworkHandle
);
#endif

#if( NM_COORDINATOR_SUPPORT_ENABLED == STD_ON )
extern FUNC( void, NM_CODE ) Nm_SynchronizationPoint
(
    NetworkHandleType nmNetworkHandle
);
extern FUNC(void, NM_CODE) Nm_MainFunction(void);
#endif

extern FUNC(void, NM_CODE) Nm_TxTimeoutException
(
    NetworkHandleType nmNetworkHandle
);

#define NM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Nm_MemMap.h"
#endif  /* NM_H_ */
