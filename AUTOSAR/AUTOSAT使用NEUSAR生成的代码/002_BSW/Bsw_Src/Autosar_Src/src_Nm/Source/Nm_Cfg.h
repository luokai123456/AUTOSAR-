/*
********************************************************************************
*
* File name: Nm_Cfg.h                                              
*                                                                              
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.           
*
********************************************************************************
*
* History                                                               
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : yong.zhang/2018.12.21
* Change: New created.
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date : jia_feng/2020.04.17
* Change: add configuration macros.
* Cause: Optimization
********************************************************************************
* Version: 3.1
* Author/Date : jia_feng/2020.04.26
* Change: modify the size of extern declaration arrays.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date : zhidx/2020.10.31
* Change: wrong usage of undefined macro NM_APPL_VAR, NM_APPL_DATA is correct.
* Cause: Optimization
********************************************************************************
*/
#ifndef NM_CFG_H_
#define NM_CFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "ComStack_Types.h"
#include "NmStack_Types.h"
#include "CanNm.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NM_BUS_SYNCHRONIZATION_ENABLED                                      (STD_ON)
#define NM_CAR_WAKE_UP_RX_ENABLED                                           (STD_ON)
#define NM_COM_CONTROL_ENABLED                                              (STD_ON)
#define NM_COM_USER_DATA_SUPPORT                                            (STD_ON)
#define NM_COORDINATOR_SUPPORT_ENABLED                                      (STD_OFF)
#define NM_COORDINATOR_SYNC_SUPPORT                                         (STD_OFF)
#define NM_DEV_ERROR_REPORT                                                 (STD_ON)
#define NM_GLOBAL_CORRDINATOR_TIME                                          (2000U)
#define NM_MAX_NUMBER_OF_COMM_CHANNELS                                      (7U)
#define NM_NODE_DETECTION_ENABLED                                           (STD_ON)
#define NM_NODE_ID_ENABLED                                                  (STD_ON)
#define NM_NUMBER_OF_CHANNELS                                               (2U)
#define NM_PASSIVE_MODE_ENABLED                                             (STD_OFF)
#define NM_PDU_RX_INDICATION_ENABLED                                        (STD_ON)
#define NM_REMOTE_SLEEP_IND_ENABLED                                         (STD_OFF)
#define NM_REPEAT_MSG_IND_ENABLED                                           (STD_ON)
#define NM_STATE_CHANGE_IND_ENABLED                                         (STD_OFF)
#define NM_USER_DATA_ENABLED                                                (STD_OFF)
#define NM_VERSION_INFO_API                                                 (STD_ON)
#define NM_NO_PASSIVE_COOR_CHANNEL                  (STD_OFF)
#define NM_NUMBER_OF_COOR_CLUSTER                   (1U)
#define NM_WAIT_FOR_SYNC_TIMEOUT                    (0U)
#define NM_OSEKNM_COM_CONTROL_ENABLED               (STD_OFF)

/* General Module Defines */
/* polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
#define NM_DUMMY_STATEMENT(v)       (v)=(v) 
#define NM_DUMMY_STATEMENT_CONST(v) (void)(v) 

/*  These defines are used to indicate unused indexes in data relations. */ 
#define NM_NO_COORCLUSTER           (0xFFU)
#define NM_NO_SYSTONMCHIND          (0xFFU)

/*  These macros can be used to read deduplicated by constance root data elements. */ 
#define Nm_GetChannelConfigOfPCConfig()                               (Nm_ChannelConfig)            /* the pointer to Nm_ChannelConfig */
#define Nm_GetNmFunctionTableOfPCConfig()                             (Nm_NmFunctionTable)          /* the pointer to Nm_NmFunctionTable */
#define Nm_GetSysToNmChIndOfPCConfig(index)                           (Nm_SysToNmChInd[(index)])    /* the pointer to Nm_SysToNmChInd */
#define Nm_GetSizeOfChannelConfig()                                   (NM_NUMBER_OF_CHANNELS)    /* the number of accomplishable value elements in Nm_ChannelConfig */
#define Nm_GetSizeOfNmFunctionTable()                                 (NM_NUMBER_OF_CHANNELS)    /* the number of accomplishable value elements in Nm_NmFunctionTable */
#define Nm_GetSizeOfSysToNmChInd()                                    (NM_MAX_NUMBER_OF_COMM_CHANNELS)    /* the number of accomplishable value elements in Nm_SysToNmChInd */

/* These macros can be used to read CONST and VAR data. */ 
#define Nm_GetNmFunctionTableIdxOfChannelConfig(Index)                (Nm_GetChannelConfigOfPCConfig()[(Index)].NmFunctionTableIdx)
#define Nm_GetPduRxIndicationOfChannelConfig(Index)                   (Nm_GetChannelConfigOfPCConfig()[(Index)].PduRxIndication)
#define Nm_GetGetLocalNodeIdentifierOfNmFunctionTable(Index)          (Nm_GetNmFunctionTableOfPCConfig()[(Index)].GetLocalNodeIdentifierOfNmFunctionTable)
#define Nm_GetGetNodeIdentifierOfNmFunctionTable(Index)               (Nm_GetNmFunctionTableOfPCConfig()[(Index)].GetNodeIdentifierOfNmFunctionTable)
#define Nm_GetGetPduDataOfNmFunctionTable(Index)                      (Nm_GetNmFunctionTableOfPCConfig()[(Index)]. GetPduDataOfNmFunctionTable)
#define Nm_GetGetStateOfNmFunctionTable(Index)                        (Nm_GetNmFunctionTableOfPCConfig()[(Index)].GetStateOfNmFunctionTable)
#define Nm_GetGetUserDataOfNmFunctionTable(Index)                     (Nm_GetNmFunctionTableOfPCConfig()[(Index)].GetUserDataOfNmFunctionTable)
#define Nm_GetNetworkReleaseOfNmFunctionTable(Index)                  (Nm_GetNmFunctionTableOfPCConfig()[(Index)].NetworkReleaseOfNmFunctionTable)
#define Nm_GetNetworkRequestOfNmFunctionTable(Index)                  (Nm_GetNmFunctionTableOfPCConfig()[(Index)].NetworkRequestOfNmFunctionTable)
#define Nm_GetPassiveStartUpOfNmFunctionTable(Index)                  (Nm_GetNmFunctionTableOfPCConfig()[(Index)].PassiveStartUpOfNmFunctionTable)
#define Nm_GetRepeatMessageRequestOfNmFunctionTable(Index)            (Nm_GetNmFunctionTableOfPCConfig()[(Index)].RepeatMessageRequestOfNmFunctionTable)
#define Nm_GetSetUserDataOfNmFunctionTable(Index)                     (Nm_GetNmFunctionTableOfPCConfig()[(Index)].SetUserDataOfNmFunctionTable)
#define Nm_GetDisableCommunicationOfNmFunctionTable(Index)            (Nm_GetNmFunctionTableOfPCConfig()[(Index)].DisableCommunicationOfNmFunctionTable)
#define Nm_GetEnableCommunicationOfNmFunctionTable(Index)             (Nm_GetNmFunctionTableOfPCConfig()[(Index)].EnableCommunicationOfNmFunctionTable)
#define Nm_GetCheckRemoteSleepIndicationOfNmFunctionTable(Index)      (Nm_GetNmFunctionTableOfPCConfig()[(Index)].CheckRemoteSleepIndicationOfNmFunctionTable)
#define Nm_GetSetSleepReadyBitOfNmFunctionTable(Index)                (Nm_GetNmFunctionTableOfPCConfig()[(Index)].SetSleepReadyBitOfNmFunctionTable)
#define Nm_GetRequestBusSynchronization(Index)                        (Nm_GetNmFunctionTableOfPCConfig()[(Index)].RequestBusSynchronization)
#define Nm_IsActiveCoordinatorChannel(Index)                          (TRUE == Nm_ChannelConfig[Index].NmActiveCoordinator)

#if( NM_PDU_RX_INDICATION_ENABLED == STD_ON )

#define  NM_PDURXIND_CBK         Nm_PduRxIndcationCallback
#endif

#if( NM_REPEAT_MSG_IND_ENABLED == STD_ON )

#define  NM_REPMSGIND_CBK        Nm_RepeatMessageIndCallback
#endif

#if( NM_CAR_WAKE_UP_RX_ENABLED == STD_ON )

#define  NM_CARWURX_CBK        Nm_CarWakeUpCallout
#endif


#define  NM_TXTIMEOUT_CBK        Nm_TxTimeoutCallback
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* polyspace-end MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* Function Table Types */
typedef Std_ReturnType (*Nm_CallBusFuncTypeStandard)(const NetworkHandleType nmChannelHandle);
typedef Std_ReturnType (*Nm_CallBusFuncTypeGetData)(const NetworkHandleType nmChannelHandle, uint8* numPtr);
typedef Std_ReturnType (*Nm_CallBusFuncTypeGetState)(const NetworkHandleType nmChannelHandle, Nm_StateType* nmStatePtr, Nm_ModeType* nmModePtr);
typedef void (*Nm_CallbackFunctionWithPduInfoType)(const NetworkHandleType nmChannelHandle, const PduInfoType*  PduInfoPtr);

typedef P2FUNC ( Std_ReturnType, NM_CODE, Nm_CallBusFuncTypeSetUserData )(CONST( NetworkHandleType, AUTOMATIC ) nmChannelHandle, P2CONST( uint8, AUTOMATIC, NM_APPL_DATA ) numPtr);
typedef P2FUNC ( Std_ReturnType, NM_CODE, Nm_CallBusFuncTypeSetSleepReady )(CONST( NetworkHandleType, AUTOMATIC ) nmChannelHandle, CONST( boolean, AUTOMATIC) nmSleepReadyBit);
typedef P2FUNC ( void, NM_CODE, Nm_CallbackFunction )(CONST( NetworkHandleType, AUTOMATIC ) nmChannelHandle);
/* polyspace-end MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/* Type used in Nm_ChannelConfig */
/* PolySpace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Nm_2.4" */
typedef struct sNm_ChannelConfigType
{
  uint16 NmShutDownDelayTime;
  boolean NmActiveCoordinator;
  boolean NmChannelSleepMaster;
  uint8 CoordinatorStateClusterIdx;  /* the index of the 0:1 relation pointing to Nm_CoordinatorState */
  uint8 NmChannelId;
  uint8 NmFunctionTableIdx;  /* the index of the 1:1 relation pointing to Nm_NmFunctionTable */
  boolean NmStateReportEnabled;
  uint16 NmStateReportSignalRef;
  boolean NmSynchronizingNetwork;
  boolean NmOsekNmEnabled;

} Nm_ChannelConfigType;

/* Type used in Nm_NmFunctionTable */
/* PolySpace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Nm_2.4" */
typedef struct sNm_NmFunctionTableType
{
#if( NM_NODE_ID_ENABLED == STD_ON )
    Nm_CallBusFuncTypeGetData GetLocalNodeIdentifierOfNmFunctionTable;
    Nm_CallBusFuncTypeGetData GetNodeIdentifierOfNmFunctionTable;
#endif

#if( (NM_NODE_ID_ENABLED == STD_ON) || (NM_USER_DATA_ENABLED == STD_ON) )
    Nm_CallBusFuncTypeGetData GetPduDataOfNmFunctionTable;
#endif

    Nm_CallBusFuncTypeGetState GetStateOfNmFunctionTable;

#if( NM_PASSIVE_MODE_ENABLED == STD_OFF )
    Nm_CallBusFuncTypeStandard NetworkReleaseOfNmFunctionTable;
    Nm_CallBusFuncTypeStandard NetworkRequestOfNmFunctionTable;
#endif

    Nm_CallBusFuncTypeStandard PassiveStartUpOfNmFunctionTable;

#if( NM_NODE_DETECTION_ENABLED == STD_ON )
    Nm_CallBusFuncTypeStandard RepeatMessageRequestOfNmFunctionTable;
#endif

#if( NM_COM_CONTROL_ENABLED == STD_ON )
    Nm_CallBusFuncTypeStandard DisableCommunicationOfNmFunctionTable;
    Nm_CallBusFuncTypeStandard EnableCommunicationOfNmFunctionTable;
#endif

#if( NM_USER_DATA_ENABLED == STD_ON )
#if( (NM_PASSIVE_MODE_ENABLED == STD_OFF) && (NM_COM_USER_DATA_SUPPORT == STD_OFF) )
    Nm_CallBusFuncTypeSetUserData SetUserDataOfNmFunctionTable;
#endif
    Nm_CallBusFuncTypeGetData GetUserDataOfNmFunctionTable;
#endif

#if( NM_REMOTE_SLEEP_IND_ENABLED == STD_ON )
    Nm_CallBusFuncTypeGetData CheckRemoteSleepIndicationOfNmFunctionTable;
#endif

#if( NM_COORDINATOR_SYNC_SUPPORT == STD_ON )
    Nm_CallBusFuncTypeSetSleepReady SetSleepReadyBitOfNmFunctionTable;
#endif

#if( (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON) && (NM_BUS_SYNCHRONIZATION_ENABLED == STD_ON) )
    Nm_CallBusFuncTypeStandard RequestBusSynchronization;
#endif
} Nm_NmFunctionTableType;

/* type used in Nm_PCConfig */
/* PolySpace +2 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Nm_2.4" */
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Nm_RuleD4.8" */
typedef struct sNm_PCConfigType
{
  uint8 Nm_PCConfigNeverUsed;  
} Nm_PCConfigType;

typedef Nm_PCConfigType Nm_ConfigType;

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#if( NM_COORDINATOR_SUPPORT_ENABLED == STD_ON )
#define NM_START_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Nm_MemMap.h"
extern VAR(uint8, NM_VAR_NO_INIT) Nm_CoordinatorState[NM_NUMBER_OF_COOR_CLUSTER];
extern VAR(uint8, NM_VAR_NO_INIT) Nm_ChannelState[NM_NUMBER_OF_CHANNELS];
extern VAR(uint8, NM_VAR_NO_INIT) Nm_ChannelRequestState[NM_NUMBER_OF_CHANNELS];
extern VAR(uint16, NM_VAR_NO_INIT) Nm_ActiveChannelTimer[NM_NUMBER_OF_CHANNELS];
#define NM_STOP_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Nm_MemMap.h"

#endif

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define NM_START_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Nm_MemMap.h"

extern P2CONST(Nm_ConfigType, NM_CONFIG_DATA, NVM_APPL_CONST) Nm_ConfigPtr;

#define NM_STOP_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Nm_MemMap.h"

#define NM_START_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Nm_MemMap.h"
/* Structure for channel specific configuration parameters */ 
extern CONST(Nm_ChannelConfigType, NM_CONFIG_DATA) Nm_ChannelConfig[NM_NUMBER_OF_CHANNELS];
/* Nm_NmFunctionTable */ 
extern CONST(Nm_NmFunctionTableType, NM_CONFIG_DATA) Nm_NmFunctionTable[NM_NUMBER_OF_CHANNELS];
/* Channel indirection: System Channel handle to NM channel handle */ 
extern CONST(uint8, NM_CONFIG_DATA) Nm_SysToNmChInd[NM_MAX_NUMBER_OF_COMM_CHANNELS];

#define NM_STOP_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Nm_MemMap.h"

/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#endif /* NM_CFG_H_ */

