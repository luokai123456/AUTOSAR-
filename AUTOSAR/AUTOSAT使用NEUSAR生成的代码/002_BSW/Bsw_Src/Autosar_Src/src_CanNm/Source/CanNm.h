/*
********************************************************************************
*
*  File name: CanNm.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: yong.zhang/2018.12.13
* Change: New created.
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: jia_feng/2020.06.08
* Change: Add autosar release version.
* Cause: Update.
********************************************************************************
* Version: 3.1
* Author/Date: guoziyang/2020.10.29
* Change: Modify the code according to the AUTOSAR specification
* Cause: Optimization
********************************************************************************
*  Version: 3.2
*  Author/Date: jiaF/2021.4.12
*  Change: Update software version to 3.2.
*  Cause: Update
********************************************************************************
*  Version: 3.3
*  Author/Date: jiaF/2021.9.1
*  Change: Delete not used macro.
*  Cause: Optimization
********************************************************************************
*  Version: 3.4
*  Author/Date: jiaF/2021.10.20
*  Change: Update software version to 3.3.
*  Cause: Update
********************************************************************************
*  Version: 3.5
*  Author/Date: LiX/2023.3.2
*  Change: Update software version to 3.5.
*  Cause: Update
********************************************************************************
*  Version: 3.6
*  Author/Date: LiX/2023.5.23
*  Change: Update software version to 3.7.0.
*  Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: LiX/2023.5.26
* Change: Add REVISION version.
* Cause: Update
********************************************************************************
*  Version: 3.8
*  Author/Date: TianG/2023.8.1
*  Change: Update software version to 3.8.0.
*  Cause: Update
********************************************************************************
*  Version: 3.9
*  Author/Date: TianG/2023.8.25
*  Change: Update software version to 3.8.0.1.
*  Cause: Update
********************************************************************************
*  Version: 3.10
*  Author/Date: TianG/2023.10.9
*  Change: Update software version to 3.9.0.2.
*  Cause: Update
********************************************************************************
*  Version: 3.11
*  Author/Date: TianL/2023.10.27
*  Change: Update software version to 3.9.0.3.
*  Cause: Update
********************************************************************************
*  Version: 3.12
*  Author/Date: TianL/2024.2.21
*  Change: Update software version to 3.10.0.4.
*  Cause: Update
********************************************************************************
*  Version: 3.13
*  Author/Date: TianSL/2024.3.11
*  Change: Update software version to 3.10.0.5.
*  Cause: Update
********************************************************************************
*  Version: 3.14
*  Author/Date: TianSL/2024.4.02
*  Change: 1.Update software version to 3.10.0.6.
*          2.Modify the label of P2CONST member.
*  Cause: Update
********************************************************************************
*  Version: 3.15
*  Author/Date: TianSL/2024.5.20
*  Change: 1.Update software version to 3.11.0.7.
*          2.Add Memmap segment definition.
*  Cause: Update
********************************************************************************
*  Version: 3.16
*  Author/Date: TianSL/2024.7.1
*  Change: 1.Update software version to 3.11.0.8.
*          2.Modify copyright.
*  Cause: Update
********************************************************************************
*  Version: 3.17
*  Author/Date: TianSL/2024.9.30
*  Change: Update software version to 3.11.0.9.
*  Cause: Update
********************************************************************************
*  Version: 3.17
*  Author/Date: TianSL/2024.12.02
*  Change: Update software version to 3.12.0.10.
*  Cause: Update
********************************************************************************
*  Version: 3.18
*  Author/Date: TianSL/2024.12.16
*  Change: 1.Update software version to 3.12.0.11.
*          2.Fix compile warning.
*  Cause: Update
********************************************************************************
*  Version: 3.19
*  Author/Date: TianSL/2025.01.09
*  Change: Update software version to 3.13.0.12.
*  Cause: Update
********************************************************************************
*  Version: 3.20
*  Author/Date: TianSL/2025.03.24
*  Change: Update software version to 3.13.0.13.
*  Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date: TianSL/2025.06.04
* Change: 1.Add the polyspace deviation suppression comment.
*         2.Update software version to 3.14.0.14.
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date: TianSL/2025.06.23
* Change: Update software version to 3.14.0.15.
* Cause: Update
********************************************************************************
*/
#ifndef CANNM_H_
#define CANNM_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "CanNm_Cfg.h"
#include "ComStack_Types.h"
#include "NmStack_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CANNM_UNINIT                                  (0U)
#define CANNM_INIT                                    (1U)

/* Number in cannm module. */
#define CANNM_ZERO                                    (0U)
#define CANNM_ONE                                     (1U)
#define CANNM_TWO                                     (2U)
#define CANNM_0XFF                                    (0xFFU)
#define CANNM_0XFFFF                                  (0xFFFFU)

/* Vendor and module identification. */
#define CANNM_VENDOR_ID                               (119U)
#define CANNM_MODULE_ID                               (31U)

/* Component version information. */
#define CANNM_SW_MAJOR_VERSION                        (3U)
#define CANNM_SW_MINOR_VERSION                        (14U)
#define CANNM_SW_PATCH_VERSION                        (0U)
#define CANNM_SW_REVISION_VERSION                     (15U)

#define CANNM_AR_RELEASE_MAJOR_VERSION                (4U)
#define CANNM_AR_RELEASE_MINOR_VERSION                (2U)
#define CANNM_AR_RELEASE_REVISION_VERSION             (2U)

/* API service IDs. */
#define CANNM_SID_INIT                                (0x00U) /* Service ID: CanNm_Init() */
#define CANNM_SID_PASSIVESTARTUP                      (0x01U) /* Service ID: CanNm_PassiveStartup() */
#define CANNM_SID_NETWORKREQUEST                      (0x02U) /* Service ID: CanNm_NetworkRequest() */
#define CANNM_SID_NETWORKRELEASE                      (0x03U) /* Service ID: CanNm_NetworkRelease() */
#define CANNM_SID_SETUSERDATA                         (0x04U) /* Service ID: CanNm_SetUserData() */
#define CANNM_SID_GETUSERDATA                         (0x05U) /* Service ID: CanNm_GetUserData() */
#define CANNM_SID_GETNODEIDENTIFIER                   (0x06U) /* Service ID: CanNm_GetNodeIdentifier() */
#define CANNM_SID_GETLOCALNODEIDENTIFIER              (0x07U) /* Service ID: CanNm_GetLocalNodeIdentifier() */
#define CANNM_SID_REPEATMESSAGEREQUEST                (0x08U) /* Service ID: CanNm_RepeatMessageRequest() */
#define CANNM_SID_GETPDUDATA                          (0x0AU) /* Service ID: CanNm_GetPduData() */
#define CANNM_SID_GETSTATE                            (0x0BU) /* Service ID: CanNm_GetState() */
#define CANNM_SID_DISABLECOMMUNICATION                (0x0CU) /* Service ID: CanNm_DisableCommunication() */
#define CANNM_SID_ENABLECOMMUNICATION                 (0x0DU) /* Service ID: CanNm_EnableCommunication() */
#define CANNM_SID_MAINFUNCTION                        (0x13U) /* Service ID: CanNm_MainFunction() */
#define CANNM_SID_TRANSMIT                            (0x14U) /* Service ID: CanNm_Transmit() */
#define CANNM_SID_CONFIRMPNAVAILABILITY               (0x16U) /* Service ID: CanNm_ConfirmPnAvailibility() */
#define CANNM_SID_SETSLEEPREADYBIT                    (0x17U) /* Service ID: CanNm_SetSleepReadyBit() */
#define CANNM_SID_REQUESTBUSSYNCHRONIZATION           (0xC0U) /* Service ID: CanNm_RequestBusSynchronization() */
#define CANNM_SID_CHECKREMOTESLEEPIND                 (0xD0U) /* Service ID: CanNm_CheckRemoteSleepIndication() */
#define CANNM_SID_GETVERSIONINFO                      (0xF1U) /* Service ID: CanNm_GetVersionInfo() */
#define CANNM_SID_CANCELTRANSMIT                      (0xF2U) /* Service ID: CanNm_CancelTransmit() */
#define CANNM_SID_TIMEOUTTIMERHANDLING                (0xF3U) /* Service ID: CanNm_TimeoutTimerHandling() */

/* Error codes. */
#define CANNM_E_NO_ERROR                              (0x00U) /* used to check if no error occurred - use a value unequal to any error code */
#define CANNM_E_NO_INIT                               (0x01U) /* Error code: API service used without module initialization */
#define CANNM_E_INVALID_CHANNEL                       (0x02U) /* Error code: API service used with an invalid channel identifier or channel was not configured for the functionality of the calling API */
#define CANNM_E_INVALID_PDUID                         (0x03U) /* Error code: API service called with wrong PDU-ID */
#define CANNM_E_NET_START_IND                         (0x04U) /* Error code: Reception of NM messages in Bus-Sleep Mode */
#define CANNM_E_INIT_FAILED                           (0x05U) /* Error code: API service CanNm_Init() called with wrong parameter */
#define CANNM_E_NETWORK_TIMEOUT                       (0x11U) /* Error code: NM-Timeout Timer has abnormally expired outside of the Ready Sleep State */
#define CANNM_E_PARAM_POINTER                         (0x12U) /* Error code: API service used with invalid pointer parameter (NULL) */
#define CANNM_E_RXINDICATION_DLC_ERROR                (0x20U) /* Error code: DLC of received NM message does not match with configured PDU Length */
#define CANNM_E_PDUR_TRIGGERTX_ERROR                  (0x21U) /* Error code: Call of PduR_TriggerTransmit failed */
#define CANNM_E_ALREADY_INITIALIZED                   (0x22U) /* Error code: The service CanNm_Init() is called while the module is already initialized  */
#define CANNM_E_INVALID_GENDATA                       (0x33U) /* Error code: The value of a variable used for write accesses is out of bounds */
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
#define CANNM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanNm_MemMap.h"

extern FUNC(void, CANNM_CODE) CanNm_Init
(
    P2CONST(CanNm_ConfigType, AUTOMATIC, CANNM_APPL_CONST) cannmConfigPtr
);
extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_PassiveStartUp
(
    NetworkHandleType nmChannelHandle
);

#if( CANNM_PASSIVE_MODE_ENABLED == STD_OFF )
extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_NetworkRequest
(
    NetworkHandleType nmChannelHandle
);
extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_NetworkRelease
(
    NetworkHandleType nmChannelHandle
);
#endif  /* ( CANNM_PASSIVE_MODE_ENABLED == STD_OFF ) */

#if( CANNM_COM_CONTROL_ENABLED == STD_ON )
extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_DisableCommunication
(
    NetworkHandleType nmChannelHandle
);
extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_EnableCommunication
(
    NetworkHandleType nmChannelHandle
);
#endif  /* ( CANNM_COM_CONTROL_ENABLED == STD_ON ) */

#if(CANNM_USER_DATA_ENABLED == STD_ON)
#if( (CANNM_COM_USER_DATA_SUPPORT == STD_OFF)&&(CANNM_PASSIVE_MODE_ENABLED == STD_OFF) )
extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_SetUserData
(
    NetworkHandleType nmChannelHandle,
    P2CONST(uint8, AUTOMATIC, CANNM_APPL_CONST) nmUserDataPtr
);
#endif
extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_GetUserData
(
    NetworkHandleType nmChannelHandle,
    P2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) nmUserDataPtr
);
#endif

#if( (CANNM_COM_USER_DATA_SUPPORT == STD_ON) || (CANNM_PN_FEATURE_ENABLED == STD_ON) )
extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_Transmit
(
    PduIdType CanNmTxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANNM_APPL_DATA) PduInfoPtr
);
#endif  /* (CANNM_COM_USER_DATA_SUPPORT == STD_ON) || (CANNM_PN_FEATURE_ENABLED == STD_ON) */

#if( CANNM_NODE_ID_ENABLED == STD_ON )
extern Std_ReturnType CanNm_GetNodeIdentifier
(
    NetworkHandleType nmChannelHandle,
    P2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) nmNodeIdPtr
);
extern Std_ReturnType CanNm_GetLocalNodeIdentifier
(
    NetworkHandleType nmChannelHandle,
    P2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) nmNodeIdPtr
);
#endif  /* ( CANNM_NODE_ID_ENABLED == STD_ON ) */

#if( CANNM_NODE_DETECTION_ENABLED == STD_ON )
extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_RepeatMessageRequest
(
    NetworkHandleType nmChannelHandle
);
#endif

#if( (CANNM_NODE_DETECTION_ENABLED == STD_ON) || (CANNM_USER_DATA_ENABLED == STD_ON) || (CANNM_NODE_ID_ENABLED == STD_ON) )
extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_GetPduData
(
    NetworkHandleType nmChannelHandle,
    P2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) nmPduDataPtr
);
#endif

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_GetState
(
    NetworkHandleType nmChannelHandle,
    P2VAR(Nm_StateType, AUTOMATIC, CANNM_APPL_DATA) nmStatePtr,
    P2VAR(Nm_ModeType, AUTOMATIC, CANNM_APPL_DATA) nmModePtr
);

#if( CANNM_VERSION_INFO_API == STD_ON )
extern FUNC(void, CANNM_CODE) CanNm_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CANNM_APPL_DATA) versioninfo
);
#endif

#if( (CANNM_BUS_SYNCHRONIZATION_ENABLED == STD_ON) && (CANNM_PASSIVE_MODE_ENABLED == STD_OFF) )
extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_RequestBusSynchronization
(
    NetworkHandleType nmChannelHandle
);
#endif

#if( CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON )
extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_CheckRemoteSleepIndication
(
    NetworkHandleType nmChannelHandle,
    P2VAR(boolean, AUTOMATIC, CANNM_APPL_DATA) nmRemoteSleepIndPtr
);
#endif

#if( CANNM_COORDINATOR_SYNC_SUPPORT == STD_ON )
extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_SetSleepReadyBit
(
    NetworkHandleType nmChannelHandle,
    boolean nmSleepReadyBit
);
#endif  /* ( CANNM_COORDINATOR_SYNC_SUPPORT == STD_ON ) */

#if( CANNM_PN_FEATURE_ENABLED == STD_ON )
extern FUNC(void, CANNM_CODE) CanNm_ConfirmPnAvailability
(
    NetworkHandleType nmChannelHandle
);
#endif
/* polyspace +1 MISRA-C3:8.5 [Justified:Unset] "NSCA_Polyspace_CanNm_Rule8.5" */
extern FUNC(void, CANNM_CODE) CanNm_MainFunction(void);
extern FUNC(boolean, CANNM_CODE) CanNm_GetMessageReceive(void);

#define CANNM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanNm_MemMap.h"

#endif  /* CANNM_H_ */
