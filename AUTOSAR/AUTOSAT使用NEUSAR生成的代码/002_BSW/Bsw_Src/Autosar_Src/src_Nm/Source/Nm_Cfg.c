/*
********************************************************************************
*                                                                              
* File name: Nm_Cfg.c                                
*                                                                              
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.                
*                                                                              
********************************************************************************
*                                                                              
* History                                                                      
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: yong.zhang/2018.12.21
* Change: New created
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: jia_feng/2020.04.17
* Change: Add unimplemented features and configuration
* Cause: Optimization
********************************************************************************
*/
/*
********************************************************************************
*    Include
********************************************************************************
*/
#include "Nm_Cfg.h"
#include "ComM.h"

#if( NM_STATE_CHANGE_IND_ENABLED == STD_ON )
#include "Com_Lcfg.h"
#endif

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/*
********************************************************************************
*    Local Types
********************************************************************************
*/
/*
********************************************************************************
*    Local Variables
********************************************************************************
*/
/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
/*
********************************************************************************
*    Local Functions
********************************************************************************
*/
/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define NM_START_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Nm_MemMap.h"
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Nm_UsedSharedVariable" */
P2CONST(Nm_ConfigType, NM_CONFIG_DATA, NM_APPL_CONST) Nm_ConfigPtr = NULL_PTR;

#define NM_STOP_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Nm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if( NM_COORDINATOR_SUPPORT_ENABLED == STD_ON )
#define NM_START_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Nm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

VAR(uint8, NM_VAR_NO_INIT) Nm_CoordinatorState[NM_NUMBER_OF_COOR_CLUSTER];
VAR(uint8, NM_VAR_NO_INIT) Nm_ChannelState[NM_NUMBER_OF_CHANNELS];
VAR(uint8, NM_VAR_NO_INIT) Nm_ChannelRequestState[NM_NUMBER_OF_CHANNELS];
VAR(uint16, NM_VAR_NO_INIT) Nm_ActiveChannelTimer[NM_NUMBER_OF_CHANNELS];

#define NM_STOP_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Nm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
#endif

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
/* Nm_ChannelConfig */ 
/*
	NmActiveCoordinator
	NmChannelSleepMaster
	CoordinatorStateClusterIdx
	NmChannelId
	NmFunctionTableIdx
	NmStateReportEnabledOfChannelConfig
	NmStateReportSignalRefOfChannelConfig
	PduRxIndication
*/
#define NM_START_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Nm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Nm_UsedNonSharedVariable" */
CONST(Nm_ChannelConfigType, NM_CONFIG_DATA) Nm_ChannelConfig[2] = {
    {
        1220U,
        (FALSE),
        (FALSE),
        255U,
        6U,
        0U,
        (FALSE),
        0xFFFFU,
        (FALSE),
        (FALSE),
    },
    {
        1220U,
        (FALSE),
        (FALSE),
        255U,
        2U,
        1U,
        (FALSE),
        0xFFFFU,
        (FALSE),
        (FALSE),
    },

};

/* Nm_NmFunctionTable */ 
/* Index    GetLocalNodeIdentifier
            GetNodeIdentifier
            GetPduData
            GetState
            NetworkRelease
            NetworkRequest
            PassiveStartUp
            RepeatMessageRequest
            DisableCommunication
            EnableCommunication
            SetUserData
			GetUserData
            CheckRemoteSleepIndication
*/
/* polyspace-begin MISRA-C3:11.1 [Justified:Unset] "NSCA_Polyspace_Nm_11.1" */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Nm_UsedNonSharedVariable" */
CONST(Nm_NmFunctionTableType, NM_CONFIG_DATA) Nm_NmFunctionTable[2] = {
    {
#if( NM_NODE_ID_ENABLED == STD_ON )
        CanNm_GetLocalNodeIdentifier,
        CanNm_GetNodeIdentifier,
#endif
#if( (NM_NODE_ID_ENABLED == STD_ON) || (NM_USER_DATA_ENABLED == STD_ON) )
        CanNm_GetPduData,
#endif
        CanNm_GetState,
#if( NM_PASSIVE_MODE_ENABLED == STD_OFF )
        CanNm_NetworkRelease,
        CanNm_NetworkRequest,
#endif
        CanNm_PassiveStartUp,
#if( NM_NODE_DETECTION_ENABLED == STD_ON )
        CanNm_RepeatMessageRequest,
#endif
#if( NM_COM_CONTROL_ENABLED == STD_ON )
        CanNm_DisableCommunication,
        CanNm_EnableCommunication,
#endif
#if( NM_USER_DATA_ENABLED == STD_ON )
#if( (NM_PASSIVE_MODE_ENABLED == STD_OFF) && (NM_COM_USER_DATA_SUPPORT == STD_OFF) )
        CanNm_SetUserData,
#endif
        CanNm_GetUserData,
#endif
#if( NM_REMOTE_SLEEP_IND_ENABLED == STD_ON )
        CanNm_CheckRemoteSleepIndication,
#endif
#if( NM_COORDINATOR_SYNC_SUPPORT == STD_ON )
        CanNm_SetSleepReadyBit,
#endif
#if( (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON) && (NM_BUS_SYNCHRONIZATION_ENABLED == STD_ON) )
        CanNm_RequestBusSynchronization,
#endif
    },
    {
#if( NM_NODE_ID_ENABLED == STD_ON )
        CanNm_GetLocalNodeIdentifier,
        CanNm_GetNodeIdentifier,
#endif
#if( (NM_NODE_ID_ENABLED == STD_ON) || (NM_USER_DATA_ENABLED == STD_ON) )
        CanNm_GetPduData,
#endif
        CanNm_GetState,
#if( NM_PASSIVE_MODE_ENABLED == STD_OFF )
        CanNm_NetworkRelease,
        CanNm_NetworkRequest,
#endif
        CanNm_PassiveStartUp,
#if( NM_NODE_DETECTION_ENABLED == STD_ON )
        CanNm_RepeatMessageRequest,
#endif
#if( NM_COM_CONTROL_ENABLED == STD_ON )
        CanNm_DisableCommunication,
        CanNm_EnableCommunication,
#endif
#if( NM_USER_DATA_ENABLED == STD_ON )
#if( (NM_PASSIVE_MODE_ENABLED == STD_OFF) && (NM_COM_USER_DATA_SUPPORT == STD_OFF) )
        CanNm_SetUserData,
#endif
        CanNm_GetUserData,
#endif
#if( NM_REMOTE_SLEEP_IND_ENABLED == STD_ON )
        CanNm_CheckRemoteSleepIndication,
#endif
#if( NM_COORDINATOR_SYNC_SUPPORT == STD_ON )
        CanNm_SetSleepReadyBit,
#endif
#if( (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON) && (NM_BUS_SYNCHRONIZATION_ENABLED == STD_ON) )
        CanNm_RequestBusSynchronization,
#endif
    },

};

/* polyspace-end MISRA-C3:11.1 [Justified:Unset] "NSCA_Polyspace_Nm_11.1" */

/* Channel indirection: System Channel handle to NM channel handle */ 
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Nm_UsedNonSharedVariable" */
CONST(uint8, NM_CONFIG_DATA) Nm_SysToNmChInd[7] = {
    NM_NO_SYSTONMCHIND,
    NM_NO_SYSTONMCHIND,
    1U,
    NM_NO_SYSTONMCHIND,
    NM_NO_SYSTONMCHIND,
    NM_NO_SYSTONMCHIND,
    0U,
};

#define NM_STOP_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Nm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

