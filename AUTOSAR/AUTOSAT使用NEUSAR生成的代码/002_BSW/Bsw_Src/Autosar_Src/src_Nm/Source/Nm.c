/*
********************************************************************************
*
*  File name: Nm.c
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: ZhangY/2018.12.21
* Change: New created.
* Cause: New
********************************************************************************
*Version: 1.1
* Author/Date: ZhangY/2019.06.10
* Change: Modify QAC Check Warning.
* Cause: Revision
********************************************************************************
* Version: 1.2
* Author/Date: ZhangY/2019.11.13
* Change: standardize code style.
* Cause: Optimization
********************************************************************************
* Version: 1.3
* Author/Date: JiaF/2020.03.25
* Change: Modify QAC check warning.
* Cause: Revision
********************************************************************************
* Version: 3.0
* Author/Date: JiaF/2020.03.27
* Change: Add function Nm_GetVersionInfo.
* Cause: Update to 3.0
********************************************************************************
* Version: 3.1
* Author/Date: JiaF/2020.04.17
* Change: Add unimplemented features,add configuration features.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: JiaF/2020.05.20
* Change: Modify macro switch(#if( NM_COORDINATOR_SUPPORT_ENABLED == STD_OFF ))
*         of Nm_MainFunction with STD_ON,error report SID to NM_SID_MAINFUNCTION.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: JiaF/2020.06.25
* Change: Modify QAC check warning.
* Cause: Revision
********************************************************************************
* Version: 3.4
* Author/Date: JiaF/2020.08.28
* Change: Add function Nm_StateChangeNotification and Nm_RepeatMessageIndication.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: JiaF/2020.09.29
* Change: Add NM_DEV_ERROR_REPORT for #include "Det.h".
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: JiaF/2020.11.23
* Change: Modify compile warning on IAR.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: JiaF/2020.12.3
* Change: Modify bugs about coordinator function.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: JiaF/2020.12.7
* Change: Modify the function of Nm_EnableCommunication.
* Cause: Optimization
********************************************************************************
*  Version: 3.9
*  Author/Date: JiaF/2020.03.03
*  Change: Modify the PolySpace high level warning in Nm_CancelShutdown.
*  Cause: Optimization
********************************************************************************
*  Version: 3.10
*  Author/Date: JiaF/2020.04.10
*  Change: Add Nm_SetCoordState for data consistency, modify the position of the
*          coordinator shutdown state.
*  Cause: Optimization
********************************************************************************
*  Version: 3.11
*  Author/Date: JiaF/2020.04.19
*  Change: Modify the judge of macro NM_NO_PASSIVE_COOR_CHANNEL in Nm_InitiateCoordinatorTimers.
*  Cause: Optimization
********************************************************************************
*  Version: 3.12
*  Author/Date: JiaF/2020.06.30
*  Change: Add {} in Nm_InitiateCoordinatorTimers.
*  Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: JiaF/2021.9.1
* Change: Delete the inclusion of the not used file Nm_MemMap.h.
* Cause: Optimization
********************************************************************************
* Version: 3.14
* Author/Date: LiZL/2024.3.19
* Change: Modify the parameter of P2CONST.
* Cause: Optimization
********************************************************************************
* Version: 3.15
* Author/Date: LiZL/2024.4.1
* Change: Perfect code specification.
* Cause: Optimization
********************************************************************************
* Version: 3.16
* Author/Date: TianSL/2024.6.26
* Change: 1.Add Memmap segment definition.
*         2.Modify copyright.
* Cause: Optimization
********************************************************************************
* Version: 3.17
* Author/Date: TianSL/2024.09.30
* Change: Modify the coding specification.
* Cause: Optimization
********************************************************************************
* Version: 3.18
* Author/Date: TianSL/2025.03.26
* Change: Add the QAC deviation suppression comment.
* Cause: Optimization
********************************************************************************
* Version: 3.19
* Author/Date: TianSL/2025.05.27
* Change: Add the polyspace deviation suppression comment.
* Cause: Optimization
********************************************************************************
********************************************************************************
* Version: 3.20
* Author/Date: TianSL/2025.06.04
* Change: Add the polyspace deviation suppression comment.
* Cause: Optimization
********************************************************************************
* Version: 3.21
* Author/Date: TianSL/2025.07.16
* Change: Add the polyspace deviation suppression comment.
* Cause: Optimization
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Nm.h"
#include "Nm_Cbk.h"
#include "ComM_Nm.h"
#include "SchM_Nm.h"

#if( NM_STATE_CHANGE_IND_ENABLED == STD_ON )
#include "Com.h"
#endif

#if( NM_DEV_ERROR_REPORT == STD_ON )
#include "Det.h"
#endif

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/* Get the index of channel. */
#define NM_CHANNEL_IDX            Nm_GetSysToNmChIndOfPCConfig(nmNetworkHandle)
/* Get the state of initialization. */
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define Nm_GetInitialized()       Nm_Initialized
/* Set the state of initialization. */
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define Nm_SetInitialized(value)  Nm_Initialized = (value)

/* State definition about coordinators */
#if( NM_COORDINATOR_SUPPORT_ENABLED == STD_ON )
#define NM_COOR_STA_SHUTDOWN                      (0U)
#define NM_COOR_STA_CANCEL_SHUTDOWN               (1U)
#define NM_COOR_STA_NETWORK_REQUESTED             (2U)
#define NM_COOR_STA_INITIATE_TIMERS               (3U)
#define NM_COOR_STA_WAIT_FOR_TIMERS               (4U)
#define NM_COOR_STA_WAIT_FOR_SYNC                 (5U)


#define NM_CH_STA_READY_SLEEP                     (1U)
#define NM_CH_STA_PREPARE_BUS_SLEEP               (2U)
#define NM_CH_STA_BUS_SLEEP                       (3U)
#define NM_CH_STA_BUS_WAKE_UP                     (4U)

#define NM_REQ_STA_NETWORK_REQUESTED              (0U)
#define NM_REQ_STA_WAIT_FOR_RELEASED              (1U)
#define NM_REQ_STA_NETWORK_RELEASED               (2U)
#endif

/* Macros of state change notification */
#if( NM_STATE_CHANGE_IND_ENABLED == STD_ON )
#define NM_RM_BSM                               (0x01u)
#define NM_RM_PBSM                              (0x02u)
#define NM_NO_RM                                (0x04u)
#define NM_NO_RS                                (0x08u)
#define NM_RM_RS                                (0x10u)
#define NM_RM_NO                                (0x20u)
#endif

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
#define NM_START_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Nm_MemMap.h"

/* Init state. */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Nm_UsedNonSharedVariable" */
static VAR(boolean, NM_VAR_INIT) Nm_Initialized = FALSE;

#define NM_STOP_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Nm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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
#if( NM_COORDINATOR_SUPPORT_ENABLED == STD_ON )
#define NM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Nm_MemMap.h"

static FUNC(void, NM_CODE) Nm_SetCoordState(uint8 coordinator, uint8 state);

#define NM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Nm_MemMap.h"
#endif

/*
********************************************************************************
*    Global Variable
********************************************************************************
*/
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/

#define NM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Nm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if( NM_COORDINATOR_SUPPORT_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: Nm_CancelShutdown
*
* Explanation: Judge the condition of NM_COOR_STA_CANCEL_SHUTDOWN.
*
* param: nmNetworkHandle: Local network channel.
*
* retval: None.
********************************************************************************
*/
static FUNC( void, NM_CODE ) Nm_CancelShutdown
(
    NetworkHandleType nmNetworkHandle
)
{
    uint8 coordinator = NM_ZERO;

    if( nmNetworkHandle < NM_NUMBER_OF_CHANNELS )
    {
        coordinator = Nm_ChannelConfig[nmNetworkHandle].CoordinatorStateClusterIdx;

        if( coordinator != NM_NO_COORCLUSTER )
        {
            if( (Nm_CoordinatorState[coordinator] != NM_COOR_STA_NETWORK_REQUESTED)
                && (Nm_CoordinatorState[coordinator] != NM_COOR_STA_SHUTDOWN) )
            {
                Nm_CoordinatorState[coordinator] = NM_COOR_STA_CANCEL_SHUTDOWN;
            }
        }
    }
    else
    {
        /* Do Nothing. */
    }
}

/*
********************************************************************************
* Function Name: Nm_ReInitiationCoordinator
*
* Explanation: Re-initiation the coordinator.
*
* param: coordinator: coordinator index.
*
* retval: None.
********************************************************************************
*/
static FUNC( void, NM_CODE ) Nm_ReInitiationCoordinator
(
    uint8 coordinator
)
{
    NetworkHandleType channel = NM_ZERO;

    for( channel = NM_ZERO; channel < NM_NUMBER_OF_CHANNELS; channel ++ )
    {
        if( Nm_ChannelConfig[channel].CoordinatorStateClusterIdx == coordinator )
        {
#if( NM_COORDINATOR_SYNC_SUPPORT == STD_ON )
            Nm_GetSetSleepReadyBitOfNmFunctionTable(Nm_GetNmFunctionTableIdxOfChannelConfig(channel))(Nm_ChannelConfig[channel].NmChannelId, FALSE);
#endif
            if( Nm_ChannelRequestState[channel] != NM_REQ_STA_NETWORK_REQUESTED )
            {
                if( NM_CH_STA_BUS_SLEEP == Nm_ChannelState[channel] )
                {
                    ComM_Nm_RestartIndication(Nm_ChannelConfig[channel].NmChannelId);
                }
                else if( Nm_ChannelRequestState[channel] >= NM_REQ_STA_NETWORK_RELEASED )
                {
                    Nm_ChannelRequestState[channel] = NM_REQ_STA_WAIT_FOR_RELEASED;
                    Nm_GetNetworkRequestOfNmFunctionTable(Nm_GetNmFunctionTableIdxOfChannelConfig(channel))(Nm_ChannelConfig[channel].NmChannelId);
                }
                else
                {
                    /* Nothing. */
                }
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Nm_ShutdownHandling
*
* Explanation: Re-initiation the coordinator.
*
* param: coordinator: coordinator index.
*
* retval: None.
********************************************************************************
*/
static FUNC(void, NM_CODE) Nm_ShutdownHandling
(
    uint8 coordinator
)
{
    NetworkHandleType channel = NM_ZERO;

    for( channel = NM_ZERO; channel < NM_NUMBER_OF_CHANNELS; channel ++ )
    {
        if( Nm_ChannelConfig[channel].CoordinatorStateClusterIdx == coordinator )
        {
            if( Nm_ChannelState[channel] != NM_CH_STA_BUS_SLEEP )
            {
                Nm_CoordinatorState[coordinator] = NM_COOR_STA_NETWORK_REQUESTED;
                break;
            }
        }
    }
}

#endif  /* NM_COORDINATOR_SUPPORT_ENABLED == STD_ON */

/*
********************************************************************************
* Function Name: Nm_Init
*
* Explanation: Initializes the NM Interface.has to be called after the initialization of the respective bus interface.
*
* param: ConfigPtr: Pointer to the selected configuration set.
*
* retval: None.
********************************************************************************
*/
FUNC(void, NM_CODE) Nm_Init
(
    P2CONST(Nm_ConfigType, AUTOMATIC, NM_APPL_CONST) ConfigPtr
)
{
    /* Local variables. */
    uint8 errorId = NM_E_NO_ERROR;

#if( NM_COORDINATOR_SUPPORT_ENABLED == STD_ON )
    uint8 index = NM_ZERO;
    uint8 channel = NM_ZERO;
#endif
    /* Dummy parameter. */
    NM_DUMMY_STATEMENT(ConfigPtr);

    /* Check Nm module init. */
    if( NM_INIT == Nm_GetInitialized() )
    {
        errorId = NM_E_REINIT;
    }
    else
    {

#if( NM_COORDINATOR_SUPPORT_ENABLED == STD_ON )
        for( index = NM_ZERO; index < NM_NUMBER_OF_COOR_CLUSTER; index ++ )
        {
            Nm_CoordinatorState[index] = NM_COOR_STA_SHUTDOWN;
        }
        for( channel = NM_ZERO; channel < NM_NUMBER_OF_CHANNELS; channel ++ )
        {
            Nm_ChannelState[channel] = NM_CH_STA_BUS_SLEEP;
            Nm_ChannelRequestState[channel] = NM_REQ_STA_NETWORK_RELEASED;
            Nm_ActiveChannelTimer[channel] = NM_ZERO;
        }
#endif
        /* Init Nm moudle. */
        Nm_SetInitialized(NM_INIT);
    }

    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( NM_E_NO_ERROR != errorId )
    {
        Nm_ReportDevError(NM_SID_INIT, errorId);
    }
#else
        NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

}

#if( NM_VERSION_INFO_API == STD_ON )
/*
********************************************************************************
* Function Name: Nm_GetVersionInfo
*
* Explanation: This service returns the version information of this module.
*
* param: nmVerInfoPtr: Pointer to where to store the version information of this
*                      module.
*
* retval: None.
********************************************************************************
*/
FUNC(void, NM_CODE) Nm_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, NM_APPL_DATA) nmVerInfoPtr
)
{
    uint8 errorId = NM_E_NO_ERROR;

    /* Check Nm module init. */
    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check NULL pointer. */
    else if( NULL_PTR == nmVerInfoPtr )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = NM_E_PARAM_POINTER;
    }
    else
    {
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Nm_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Nm_RuleD4.14" */
        nmVerInfoPtr->vendorID = (uint16)NM_VENDOR_ID;
        nmVerInfoPtr->moduleID = (uint16)NM_MODULE_ID;

        nmVerInfoPtr->sw_major_version = (uint8)NM_SW_MAJOR_VERSION;
        nmVerInfoPtr->sw_minor_version = (uint8)NM_SW_MINOR_VERSION;
        nmVerInfoPtr->sw_patch_version = (uint8)NM_SW_PATCH_VERSION;
    }

#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( NM_E_NO_ERROR != errorId )
    {
        Nm_ReportDevError(NM_SID_GETVERSIONINFO, errorId);
    }
#else
        NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT. */

}
#endif  /* NM_VERSION_INFO_API == STD_ON */

/*
********************************************************************************
* Function Name: Nm_PassiveStartUp
*
* Explanation: This function calls the <BusNm>_PassiveStartUp function
*              (e.g.CanNm_PassiveStartUp function is called if channel is
*              configured as CAN).
*
* param: NetworkHandle: Identification of the NM-channel.
*
* retval: E_OK: No error.
*         E_NOT_OK: Passive start of network management has failed NetworkHandle
*                  does not exist (development only).
*                   Module not yet initialized (development only).
********************************************************************************
*/
FUNC(Std_ReturnType, NM_CODE) Nm_PassiveStartUp
(
    NetworkHandleType nmNetworkHandle
)
{
    /* Local variables. */
    Std_ReturnType  retVal = E_NOT_OK;
    uint8 errorId = NM_E_NO_ERROR;

    /* Check Nm module init. */
    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else
    {

#if( NM_COORDINATOR_SUPPORT_ENABLED == STD_ON )
        if( Nm_ChannelConfig[NM_CHANNEL_IDX].CoordinatorStateClusterIdx != NM_NO_COORCLUSTER )
        {
            Nm_ChannelRequestState[NM_CHANNEL_IDX] = NM_REQ_STA_WAIT_FOR_RELEASED;
            Nm_CancelShutdown(NM_CHANNEL_IDX);
            /* the Nm coordinator functionality shall treat this call as if the ComM had called Nm_NetworkRequest(). */
            retVal = Nm_GetNetworkRequestOfNmFunctionTable(Nm_GetNmFunctionTableIdxOfChannelConfig(NM_CHANNEL_IDX))(nmNetworkHandle);
        }
        else
#endif
        {
            retVal = Nm_GetPassiveStartUpOfNmFunctionTable(Nm_GetNmFunctionTableIdxOfChannelConfig(NM_CHANNEL_IDX))(nmNetworkHandle);
        }
    }
    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON)
    if( NM_E_NO_ERROR != errorId )
    {
        Nm_ReportDevError(NM_SID_PASSIVESTARTUP, errorId);
    }
#else
        NM_DUMMY_STATEMENT(errorId);
#endif /* NM_DEV_ERROR_REPORT */

    return retVal;

}

#if( NM_PASSIVE_MODE_ENABLED == STD_OFF )
/*
********************************************************************************
* Function Name: Nm_NetworkRequest
*
* Explanation: This function calls the <BusNm>_NetworkRequest (e.g.
*              CanNm_NetworkRequest function is called if channel is configured
*              as CAN).
*
* param: NetworkHandle: Identification of the NM-channel.
*
* retval: E_OK: No error.
*         E_NOT_OK: Passive start of network management has failed NetworkHandle
*                   does not exist (development only).
*            Module not yet initialized (development only).
********************************************************************************
*/
FUNC(Std_ReturnType, NM_CODE) Nm_NetworkRequest
(
    NetworkHandleType nmNetworkHandle
)
{
     /* Local variables. */
    Std_ReturnType  retVal = E_NOT_OK;
    uint8 errorId = NM_E_NO_ERROR;

    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else
    {

#if( NM_COORDINATOR_SUPPORT_ENABLED == STD_ON )
        /* Check if current channel is coordinator. */
        if( Nm_ChannelConfig[NM_CHANNEL_IDX].CoordinatorStateClusterIdx != NM_NO_COORCLUSTER )
        {
            /* Set channel request state. */
            Nm_ChannelRequestState[NM_CHANNEL_IDX] = NM_REQ_STA_NETWORK_REQUESTED;
            Nm_CancelShutdown(NM_CHANNEL_IDX);
        }
#endif
        /* Request network. */
        retVal = Nm_GetNetworkRequestOfNmFunctionTable(Nm_GetNmFunctionTableIdxOfChannelConfig(NM_CHANNEL_IDX))(nmNetworkHandle);
    }

    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( NM_E_NO_ERROR != errorId )
    {
        Nm_ReportDevError(NM_SID_NETWORKREQUEST, errorId);
    }
#else
        NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

    return retVal;

}

/*
********************************************************************************
* Function Name: Nm_NetworkRelease
*
* Explanation: This function calls the <BusNm>_NetworkRelease bus specific
*              function (e.g. CanNm_NetworkRelease function is called if channel
*              is configured as CAN).
*
* param: NetworkHandle: Identification of the NM-channel.
*
* retval: E_OK: No error.
*         E_NOT_OK: Passive start of network management has failed NetworkHandle
*                   does not exist (development only).
*            Module not yet initialized (development only).
********************************************************************************
*/
FUNC(Std_ReturnType, NM_CODE) Nm_NetworkRelease
(
    NetworkHandleType nmNetworkHandle
)
{
    /* Local variables. */
    Std_ReturnType  retVal = E_NOT_OK;
    uint8 errorId = NM_E_NO_ERROR;

   if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else
    {

#if( NM_COORDINATOR_SUPPORT_ENABLED == STD_ON )
        if( NM_NO_COORCLUSTER == Nm_ChannelConfig[NM_CHANNEL_IDX].CoordinatorStateClusterIdx )
#endif
        {   /* Release network. */
            retVal = Nm_GetNetworkReleaseOfNmFunctionTable(Nm_GetNmFunctionTableIdxOfChannelConfig(NM_CHANNEL_IDX))(nmNetworkHandle);
        }
#if( NM_COORDINATOR_SUPPORT_ENABLED == STD_ON )
        else
        {
            if( NM_REQ_STA_NETWORK_REQUESTED == Nm_ChannelRequestState[NM_CHANNEL_IDX] )
            {
                Nm_ChannelRequestState[NM_CHANNEL_IDX] = NM_REQ_STA_WAIT_FOR_RELEASED;
            }
            else
            {
                /* Nothing */
            }
            retVal = E_OK;
        }
#endif

    }

    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( NM_E_NO_ERROR != errorId )
    {
        Nm_ReportDevError(NM_SID_NETWORKRELEASE, errorId);
    }
#else
        NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

    return retVal;

}
#endif  /* NM_PASSIVE_MODE_ENABLED == STD_OFF */

#if( NM_COM_CONTROL_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: Nm_DisableCommunication
*
* Explanation: Disables the NM PDU transmission ability. For that purpose
*              <BusNm>_DisableCommunication shall be called (e.g.
*              CanNm_DisableCommunication function is called if channel is
*              configured as CAN).
*
* param: NetworkHandle: Identification of the NM-channel.
*
* retval: E_OK: No error.
*         E_NOT_OK: Passive start of network management has failed NetworkHandle
*                   does not exist (development only).
*            Module not yet initialized (development only).
********************************************************************************
*/
FUNC(Std_ReturnType, NM_CODE) Nm_DisableCommunication
(
    NetworkHandleType nmNetworkHandle
)
{
    Std_ReturnType  retVal = E_NOT_OK;
    uint8 errorId = NM_E_NO_ERROR;

    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        retVal = (Nm_GetDisableCommunicationOfNmFunctionTable(Nm_GetNmFunctionTableIdxOfChannelConfig(NM_CHANNEL_IDX))(nmNetworkHandle));
    }

    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON)
    if( NM_E_NO_ERROR != errorId )
    {
        Nm_ReportDevError(NM_SID_DISABLECOMMUNICATION, errorId);
    }
#else
    NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Nm_EnableCommunication
*
* Explanation: Enable the NM PDU transmission ability. For that purpose
*              <BusNm>_EnableCommunication shall be called (e.g.
*              CanNm_EnableCommunication function is called if channel is configured
*              as CAN).
*
* param: NetworkHandle: Identification of the NM-channel.
*
* retval: E_OK: No error.
*         E_NOT_OK: NetworkHandle does not exist (development only).
*            Module not yet initialized (development only).
********************************************************************************
*/
FUNC(Std_ReturnType, NM_CODE) Nm_EnableCommunication
(
    NetworkHandleType nmNetworkHandle
)
{
    Std_ReturnType  retVal = E_NOT_OK;
    uint8 errorId = NM_E_NO_ERROR;

    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        retVal = (Nm_GetEnableCommunicationOfNmFunctionTable(Nm_GetNmFunctionTableIdxOfChannelConfig(NM_CHANNEL_IDX))(nmNetworkHandle));
    }

    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON)
    if( NM_E_NO_ERROR != errorId )
    {
        Nm_ReportDevError(NM_SID_ENABLECOMMUNICATION, errorId);
    }
#else
    NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

    return retVal;
}
#endif  /* NM_COM_CONTROL_ENABLED == STD_ON */

#if( NM_USER_DATA_ENABLED == STD_ON )
#if( (NM_PASSIVE_MODE_ENABLED == STD_OFF) && (NM_COM_USER_DATA_SUPPORT == STD_OFF) )
/*
********************************************************************************
* Function Name: Nm_SetUserData
*
* Explanation: set User Data.
*
* param: NetworkHandle: Identification of the NM-channel.
*        nmUserDataPtr: Point to data value.
*
* retval: E_OK: No error.
*         E_NOT_OK: set user data failed.
********************************************************************************
*/
FUNC(Std_ReturnType, NM_CODE) Nm_SetUserData
(
    NetworkHandleType nmNetworkHandle,
    P2CONST(uint8, AUTOMATIC, NM_APPL_DATA) nmUserDataPtr
)
{
    /* Local variables. */
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorId = NM_E_NO_ERROR;


    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else if( NULL_PTR == nmUserDataPtr )
    {
        errorId = NM_E_PARAM_POINTER;
    }
    else
    {
        retVal = Nm_GetSetUserDataOfNmFunctionTable(Nm_GetNmFunctionTableIdxOfChannelConfig(NM_CHANNEL_IDX))(nmNetworkHandle,nmUserDataPtr);
    }

    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( NM_E_NO_ERROR != errorId )
    {
        Nm_ReportDevError(NM_SID_SETUSERDATA, errorId);
    }
#else
    NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

    return retVal;
}
#endif  /* ( NM_PASSIVE_MODE_ENABLED == STD_OFF ) && ( NM_COM_USER_DATA_SUPPORT == STD_OFF ) */

/*
********************************************************************************
* Function Name: Nm_GetUserData
*
* Explanation: This function calls the <BusNm>_NetworkRelease bus specific
*              function (e.g. CanNm_NetworkRelease function is called if channel
*              is configured as CAN).
*
* param: NetworkHandle: Identification of the NM-channel.
*        nmUserDataPtr: Pointer where user data out of the last successfully
*                       received NM message shall be copied to.
*
* retval: E_OK: No error.
*         E_NOT_OK: Getting of user data has failed NetworkHandle does not exist
*                  (development only).
*                    Module not yet initialized (development only).
********************************************************************************
*/
FUNC(Std_ReturnType, NM_CODE) Nm_GetUserData
(
    NetworkHandleType nmNetworkHandle,
    P2VAR(uint8, AUTOMATIC, NM_APPL_DATA) nmUserDataPtr
)
{
    /* Local variables. */
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorId = NM_E_NO_ERROR;

    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else if( NULL_PTR == nmUserDataPtr )
    {
        errorId = NM_E_PARAM_POINTER;
    }
    else
    {
        retVal = Nm_GetGetUserDataOfNmFunctionTable(Nm_GetNmFunctionTableIdxOfChannelConfig(NM_CHANNEL_IDX))(nmNetworkHandle,nmUserDataPtr);
    }

    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( NM_E_NO_ERROR != errorId )
    {
        Nm_ReportDevError(NM_SID_GETUSERDATA, errorId);
    }
#else
        NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

    return retVal;
}
#endif  /* NM_USER_DATA_ENABLED == STD_ON */

#if( (NM_NODE_ID_ENABLED == STD_ON) || (NM_USER_DATA_ENABLED == STD_ON) )
/*
********************************************************************************
* Function Name: Nm_GetPduData
*
* Explanation: Get the whole PDU data out of the most recently received NM
*              message. For that purpose <BusNm>_GetPduData shall be called
*              (e.g.CanNm_GetPduData function is called if channel is configured
*              as CAN).
*
* param: NetworkHandle: Identification of the NM-channel.
*        nmPduData: Pointer where NM PDU shall be copied to.
*
* retval: E_OK: No error.
*         E_NOT_OK: Getting of NM PDU data has failed NetworkHandle does not
*                   exist (development only).
*           Module not yet initialized (development only).
********************************************************************************
*/
FUNC(Std_ReturnType, NM_CODE) Nm_GetPduData
(
    NetworkHandleType nmNetworkHandle,
    P2VAR(uint8, AUTOMATIC, NM_APPL_DATA) nmPduDataPtr
)
{
    /* Local variables. */
    Std_ReturnType  retVal = E_NOT_OK;
    uint8 errorId = NM_E_NO_ERROR;

    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else if( NULL_PTR == nmPduDataPtr )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = NM_E_PARAM_POINTER;
    }
    else
    {
        retVal = (Nm_GetGetPduDataOfNmFunctionTable(Nm_GetNmFunctionTableIdxOfChannelConfig(NM_CHANNEL_IDX))(nmNetworkHandle,nmPduDataPtr));
    }

    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( NM_E_NO_ERROR != errorId )
    {
        Nm_ReportDevError(NM_SID_GETPDUDATA, errorId);
    }
#else
        NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

    return retVal;
}
#endif  /* (NM_NODE_ID_ENABLED == STD_ON) || (NM_USER_DATA_ENABLED == STD_ON) */

#if( NM_NODE_DETECTION_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: Nm_RepeatMessageRequest
*
* Explanation: Set Repeat Message Request Bit for NM messages transmitted next
*              on the bus. For that purpose <BusNm>_RepeatMessageRequest shall be
*              called (e.g. CanNm_RepeatMessageRequest function is called if
*              channel is configured as CAN). This will force all nodes on the
*              bus to transmit NM messages so that they can be identified.
*
* param: NetworkHandle: Identification of the NM-channel.
*
* retval: E_OK: No error.
*         E_NOT_OK: Setting of Repeat Message Request Bit has failed
*                   NetworkHandle does not exist (development only).
*           Module not yet initialized (development only).
********************************************************************************
*/
FUNC(Std_ReturnType, NM_CODE) Nm_RepeatMessageRequest
(
    NetworkHandleType nmNetworkHandle
)
{
    /* Local variables. */
    Std_ReturnType  retVal = E_NOT_OK;
    uint8 errorId = NM_E_NO_ERROR;

    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        retVal = (Nm_GetRepeatMessageRequestOfNmFunctionTable(Nm_GetNmFunctionTableIdxOfChannelConfig(NM_CHANNEL_IDX))(nmNetworkHandle));
    }

    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( errorId != NM_E_NO_ERROR )
    {
        Nm_ReportDevError(NM_SID_REPEATMESSAGEREQUEST, errorId);
    }
#else
        NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

    return retVal;
}
#endif  /* NM_NODE_DETECTION_ENABLED == STD_ON */

#if( NM_NODE_ID_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: Nm_GetNodeIdentifier
*
* Explanation: Get node identifier out of the last successfully received
*              NMmessage. The function <BusNm>_GetNodeIdentifier shall be called
*              (e.g.CanNm_GetNodeIdentifier function is called if channel is
*              configured as CAN).
*
* param: NetworkHandle: Identification of the NM-channel.
*
* retval: E_OK: No error.
*         E_NOT_OK: Getting of the node identifier out of the last received
*                   NM-message has failed NetworkHandle does not exist
*                   (development only).
*            Module not yet initialized (development only).
********************************************************************************
*/
FUNC(Std_ReturnType, NM_CODE) Nm_GetNodeIdentifier
(
    NetworkHandleType nmNetworkHandle,
    P2VAR(uint8, AUTOMATIC, NM_APPL_DATA) nmNodeIdPtr
)
{
    /* Local variables. */
    Std_ReturnType  retVal = E_NOT_OK;
    uint8 errorId = NM_E_NO_ERROR;

    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else if( NULL_PTR == nmNodeIdPtr )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = NM_E_PARAM_POINTER;
    }
    else
    {
        retVal = (Nm_GetGetNodeIdentifierOfNmFunctionTable(Nm_GetNmFunctionTableIdxOfChannelConfig(NM_CHANNEL_IDX))(nmNetworkHandle, nmNodeIdPtr));
    }

    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( errorId != NM_E_NO_ERROR )
    {
        Nm_ReportDevError(NM_SID_GETNODEIDENTIFIER, errorId);
    }
#else
        NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Nm_GetLocalNodeIdentifier
*
* Explanation: Get node identifier configured for the local node. For that
*              purpose <BusNm>_GetLocalNodeIdentifier shall be called (e.g.
*              CanNm_GetLocalNodeIdentifier function is called if channel is
*              configured as CAN).
*
* param: NetworkHandle: Identification of the NM-channel.
*
* retval: E_OK: No error.
*         E_NOT_OK: Getting of the node identifier of the local node has failed
*                   NetworkHandle does not exist (development only).
*            Module not yet initialized (development only).
********************************************************************************
*/
FUNC(Std_ReturnType, NM_CODE) Nm_GetLocalNodeIdentifier
(
    NetworkHandleType nmNetworkHandle,
    P2VAR(uint8, AUTOMATIC, NM_APPL_DATA) nmNodeIdPtr
)
{
    /* Local variables. */
    Std_ReturnType  retVal = E_NOT_OK;
    uint8 errorId = NM_E_NO_ERROR;

    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else if( NULL_PTR == nmNodeIdPtr )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = NM_E_PARAM_POINTER;
    }
    else
    {
        retVal = (Nm_GetGetLocalNodeIdentifierOfNmFunctionTable(Nm_GetNmFunctionTableIdxOfChannelConfig(NM_CHANNEL_IDX))(nmNetworkHandle, nmNodeIdPtr));
    }

    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON )
    if (errorId != NM_E_NO_ERROR)
    {
        Nm_ReportDevError(NM_SID_GETLOCALNODEIDENTIFIER, errorId);
    }
#else
        NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

    return retVal;
}
#endif  /* NM_NODE_ID_ENABLED == STD_ON */

#if( NM_REMOTE_SLEEP_IND_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: Nm_CheckRemoteSleepIndication
*
* Explanation: Check if remote sleep indication takes place or not. For that
*              purpose <BusNm>_CheckRemoteSleepIndication shall be called (e.g.
*              CanNm_CheckRemoteSleepIndication function is called if channel is
*              configured as CAN).
*
* param: NetworkHandle: Identification of the NM-channel.
*        nmRemoteSleepIndPtr: Pointer where check result of remote sleep indication
*                             shall be copied to.
* retval: E_OK: No error.
*         E_NOT_OK: failed NetworkHandle does not exist (development only).
*                   Module not yet initialized (development only).
********************************************************************************
*/
FUNC(Std_ReturnType, NM_CODE) Nm_CheckRemoteSleepIndication
(
    NetworkHandleType nmNetworkHandle,
    P2VAR(boolean, AUTOMATIC, NM_APPL_DATA) nmRemoteSleepIndPtr
)
{
    /* Local variables. */
    Std_ReturnType  retVal = E_NOT_OK;
    uint8 errorId = NM_E_NO_ERROR;
    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else if( NULL_PTR == nmRemoteSleepIndPtr )
    {
        errorId = NM_E_PARAM_POINTER;
    }
    else
    {
        retVal = (Nm_GetCheckRemoteSleepIndicationOfNmFunctionTable(Nm_GetNmFunctionTableIdxOfChannelConfig(NM_CHANNEL_IDX))(nmNetworkHandle,nmRemoteSleepIndPtr));
    }

    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( NM_E_NO_ERROR != errorId )
    {
        Nm_ReportDevError(NM_SID_CHECKREMOTESLEEPINDICATION, errorId);
    }
#endif  /* NM_DEV_ERROR_REPORT */

    return retVal;
}
#endif  /* NM_REMOTE_SLEEP_IND_ENABLED == STD_ON */

/*
********************************************************************************
* Function Name: Nm_GetState
*
* Explanation: Returns the state of the network management.
*              The function <BusNm>_GetState shall be called (e.g. CanNm_GetState
*              function is called if channel is configured as CAN).
*
* param: NetworkHandle: Identification of the NM-channel.
*        nmStatePtr: Pointer where state of the network management shall be
*                    copied to.
*        nmModePtr: Pointer to the location where the mode of the network
*                   management shall be copied to.
*
* retval: E_OK: No error.
*         E_NOT_OK: Getting of NM state has failed NetworkHandle does not exist
*                   (development only).
*           Module not yet initialized (development only).
********************************************************************************
*/
FUNC(Std_ReturnType, NM_CODE) Nm_GetState
(
    NetworkHandleType nmNetworkHandle,
    P2VAR(Nm_StateType, AUTOMATIC, NM_APPL_DATA) nmStatePtr,
    P2VAR(Nm_ModeType, AUTOMATIC, NM_APPL_DATA) nmModePtr
)
{
    /* Local variables. */
    Std_ReturnType  retVal = E_NOT_OK;
    uint8 errorId = NM_E_NO_ERROR;

    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else if( (NULL_PTR == nmStatePtr) || (NULL_PTR == nmModePtr) )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = NM_E_PARAM_POINTER;
    }
    else
    {
        retVal = (Nm_GetGetStateOfNmFunctionTable(Nm_GetNmFunctionTableIdxOfChannelConfig(NM_CHANNEL_IDX))(nmNetworkHandle,nmStatePtr,nmModePtr));
    }

    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( NM_E_NO_ERROR != errorId )
    {
        Nm_ReportDevError(NM_SID_GETSTATE, errorId);
    }
#else
        NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Nm_NetworkStartIndication
*
* Explanation: Notification that a NM-message has been received in the Bus-Sleep
*              Mode, what indicates that some nodes in the network have already
*              entered the Network Mode.
*
* param: NetworkHandle: Identification of the NM-channel.
*
* retval: None.
********************************************************************************
*/
FUNC(void, NM_CODE) Nm_NetworkStartIndication
(
    NetworkHandleType nmNetworkHandle
)
{
    /* Local variables. */
    uint8 errorId = NM_E_NO_ERROR;

    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        /* Notify a network start to the ComM Module. */
        ComM_Nm_NetworkStartIndication(nmNetworkHandle);
    }

    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( NM_E_NO_ERROR != errorId )
    {
        Nm_ReportDevError(NM_SID_NETWORKSTARTINDICATION, errorId);
    }
#else
        NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

}

/*
********************************************************************************
* Function Name: Nm_NetworkMode
*
* Explanation: Notification that a NM-message has been received in the Bus-Sleep
*               Mode, what indicates that some nodes in the network have already
*               entered the Network Mode.
*
* param: NetworkHandle: Identification of the NM-channel.
*
* retval: None.
********************************************************************************
*/
FUNC(void, NM_CODE) Nm_NetworkMode
(
    NetworkHandleType nmNetworkHandle
)
{
    /* Local variables. */
    uint8 errorId = NM_E_NO_ERROR;

    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else
    {

#if ( NM_COORDINATOR_SUPPORT_ENABLED == STD_ON )
#if ( NM_REMOTE_SLEEP_IND_ENABLED == STD_ON )
          Nm_ChannelState[NM_CHANNEL_IDX] = NM_CH_STA_BUS_WAKE_UP;
#else
          Nm_ChannelState[NM_CHANNEL_IDX] = NM_CH_STA_READY_SLEEP;
#endif
          Nm_CancelShutdown(nmNetworkHandle);
#endif
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        if( FALSE == Nm_ChannelConfig[NM_CHANNEL_IDX].NmOsekNmEnabled )
        {
          /* Notify network mode to the ComM module. */
          ComM_Nm_NetworkMode(nmNetworkHandle);
        }
    }

    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( NM_E_NO_ERROR != errorId )
    {
        Nm_ReportDevError(NM_SID_NETWORKMODE, errorId);
    }
#else
        NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

}

/*
********************************************************************************
* Function Name: Nm_BusSleepMode
*
* Explanation: Notification that the network management has entered Bus-Sleep Mode.
*
* param: NetworkHandle: Identification of the NM-channel.
*
* retval: None.
********************************************************************************
*/
FUNC(void, NM_CODE) Nm_BusSleepMode
(
    NetworkHandleType nmNetworkHandle
)
{
    /* Local variables. */
    uint8 errorId = NM_E_NO_ERROR;
#if( NM_COORDINATOR_SUPPORT_ENABLED == STD_ON )
    uint8 channel;
    boolean coordSleepFlag = TRUE;
#endif

    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else
    {

#if( NM_COORDINATOR_SUPPORT_ENABLED == STD_ON )
#if( NM_COORDINATOR_SYNC_SUPPORT == STD_ON )
        if( Nm_ChannelConfig[NM_CHANNEL_IDX].CoordinatorStateClusterIdx != NM_NO_COORCLUSTER )
        {
            Nm_GetSetSleepReadyBitOfNmFunctionTable(Nm_GetNmFunctionTableIdxOfChannelConfig(NM_CHANNEL_IDX))(nmNetworkHandle, FALSE);
        }
#endif
        Nm_ChannelState[NM_CHANNEL_IDX] = NM_CH_STA_BUS_SLEEP;
        for( channel = NM_ZERO; channel < NM_NUMBER_OF_CHANNELS; channel++ )
        {
            if( Nm_ChannelConfig[NM_CHANNEL_IDX].CoordinatorStateClusterIdx == Nm_ChannelConfig[channel].CoordinatorStateClusterIdx )
            {
                if( NM_CH_STA_BUS_SLEEP != Nm_ChannelState[channel] )
                {
                    coordSleepFlag = FALSE;
                    break;
                }
            }
        }
        if( TRUE == coordSleepFlag )
        {
            Nm_SetCoordState(Nm_ChannelConfig[NM_CHANNEL_IDX].CoordinatorStateClusterIdx, NM_COOR_STA_SHUTDOWN);
        }
#endif
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        if( FALSE == Nm_ChannelConfig[NM_CHANNEL_IDX].NmOsekNmEnabled )
        {
          ComM_Nm_BusSleepMode(nmNetworkHandle);
        }
    }

    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( NM_E_NO_ERROR != errorId )
    {
        Nm_ReportDevError(NM_SID_BUSSLEEPMODE, errorId);
    }
#else
        NM_DUMMY_STATEMENT(errorId);

#endif  /* NM_DEV_ERROR_REPORT */

}

/*
********************************************************************************
* Function Name: Nm_PrepareBusSleepMode
*
* Explanation: Notification that the network management has entered Prepare
*              BusSleep Mode.
*
* param: NetworkHandle: Identification of the NM-channel.
*
* retval: None.
********************************************************************************
*/
FUNC(void, NM_CODE) Nm_PrepareBusSleepMode
(
    NetworkHandleType nmNetworkHandle
)
{
    /* Local variables.. */
    uint8 errorId = NM_E_NO_ERROR;

    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else
    {

#if( NM_COORDINATOR_SUPPORT_ENABLED == STD_ON )
        Nm_ChannelState[NM_CHANNEL_IDX] = NM_CH_STA_PREPARE_BUS_SLEEP;
#endif
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        if( FALSE == Nm_ChannelConfig[NM_CHANNEL_IDX].NmOsekNmEnabled )
        {
          ComM_Nm_PrepareBusSleepMode(nmNetworkHandle);
        }
    }

    /* Dev error report.. */
#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( NM_E_NO_ERROR != errorId )
    {
        Nm_ReportDevError(NM_SID_PREPAREBUSSLEEPMODE, errorId);
    }
#else
        NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

}

#if( NM_REMOTE_SLEEP_IND_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: Nm_RemoteSleepIndication
*
* Explanation: Notification that the network management has detected that all
*              other nodes on the network are ready to enter Bus-Sleep Mode.
*
* param: NetworkHandle: Identification of the NM-channel.
*
* retval: None.
********************************************************************************
*/
FUNC(void, NM_CODE) Nm_RemoteSleepIndication
(
    NetworkHandleType nmNetworkHandle
)
{
    /* Local variables. */
    uint8 errorId = NM_E_NO_ERROR;

    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else
    {

        /* When NM Coordinator functionality is disabled,
         Nm_RemoteSleepIndication() can be a empty function. */
#if ( NM_COORDINATOR_SUPPORT_ENABLED == STD_ON )
        Nm_ChannelState[NM_CHANNEL_IDX] = NM_CH_STA_READY_SLEEP;
#else
        NM_DUMMY_STATEMENT(nmNetworkHandle);
#endif

        }

#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( NM_E_NO_ERROR != errorId )
    {
        Nm_ReportDevError(NM_SID_REMOTESLEEPINDICATION, errorId);
    }
#else
    NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

}

/*
********************************************************************************
* Function Name: Nm_RemoteSleepCancellation
*
* Explanation: Notification that the network management has detected that not
*              all other nodes on the network are longer ready to enter Bus-Sleep
*              Mode.
*
* param: NetworkHandle: Identification of the NM-channel.
*
* retval: None.
********************************************************************************
*/
FUNC(void, NM_CODE) Nm_RemoteSleepCancellation
(
    NetworkHandleType nmNetworkHandle
)
{
    /* Local variables. */
    uint8 errorId = NM_E_NO_ERROR;

    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else
    {

        /* When NM Coordinator functionality is disabled,
         Nm_RemoteSleepIndication() can be a empty function. */
#if ( NM_COORDINATOR_SUPPORT_ENABLED == STD_ON )
        Nm_ChannelState[NM_CHANNEL_IDX] = NM_CH_STA_BUS_WAKE_UP;
        Nm_CancelShutdown(NM_CHANNEL_IDX);
#else
        NM_DUMMY_STATEMENT(nmNetworkHandle);
#endif

        }

#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( NM_E_NO_ERROR != errorId )
    {
        Nm_ReportDevError(NM_SID_REMOTESLEEPCANCELLATION, errorId);
    }
#else
    NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

}
#endif /* NM_REMOTE_SLEEP_IND_ENABLED ==STD_ON */

#if( NM_COORDINATOR_SYNC_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Nm_CoordReadyToSleepIndication
*
* Explanation: Sets an indication, when the NM Coordinator Sleep Ready bit in
*              the Control Bit Vector is set.
*
* param: NetworkHandle: Identification of the NM-channel.
*
* retval: None.
********************************************************************************
*/
FUNC(void, NM_CODE) Nm_CoordReadyToSleepIndication
(
    NetworkHandleType nmNetworkHandle
)
{
    /* Local variables. */
    uint8 errorId = NM_E_NO_ERROR;
    uint8 channel = NM_ZERO;
    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        if( FALSE == Nm_IsActiveCoordinatorChannel(NM_CHANNEL_IDX) )
        {
            for( channel = NM_ZERO; channel < NM_NUMBER_OF_CHANNELS; channel ++ )
            {
                if( (Nm_ChannelConfig[NM_CHANNEL_IDX].CoordinatorStateClusterIdx == Nm_ChannelConfig[channel].CoordinatorStateClusterIdx)
                    && (TRUE == Nm_IsActiveCoordinatorChannel(channel))
                    )
                {
                    Nm_GetSetSleepReadyBitOfNmFunctionTable(Nm_GetNmFunctionTableIdxOfChannelConfig(channel))(nmNetworkHandle, TRUE);
                }
            }
            Nm_ChannelState[NM_CHANNEL_IDX] = NM_CH_STA_READY_SLEEP;
        }
        else
        {
            /* Nothing */
        }
    }

#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( NM_E_NO_ERROR != errorId )
    {
        Nm_ReportDevError(NM_SID_COORDREADYTOSLEEPINDICATION, errorId);
    }
#else
    NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

}

/*
********************************************************************************
* Function Name: Nm_CoordReadyToSleepCancellation
*
* Explanation: Cancels an indication, when the NM Coordinator Sleep Ready bit in
*              the Control Bit Vector is set back to 0.
*
* param: NetworkHandle: Identification of the NM-channel.
*
* retval: None.
********************************************************************************
*/
FUNC(void, NM_CODE) Nm_CoordReadyToSleepCancellation
(
    NetworkHandleType nmNetworkHandle
)
{
    /* Local variables. */
    uint8 errorId = NM_E_NO_ERROR;
    uint8 channel = NM_ZERO;
    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        if( FALSE == Nm_IsActiveCoordinatorChannel(NM_CHANNEL_IDX) )
        {
            for( channel = NM_ZERO; channel < NM_NUMBER_OF_CHANNELS; channel ++ )
            {
                if( (Nm_ChannelConfig[NM_CHANNEL_IDX].CoordinatorStateClusterIdx == Nm_ChannelConfig[channel].CoordinatorStateClusterIdx)
                    && (TRUE == Nm_IsActiveCoordinatorChannel(channel))
                    )
                {
                    Nm_GetSetSleepReadyBitOfNmFunctionTable(Nm_GetNmFunctionTableIdxOfChannelConfig(channel))(nmNetworkHandle, FALSE);
                }
            }
            Nm_ChannelState[NM_CHANNEL_IDX] = NM_CH_STA_BUS_WAKE_UP;
            Nm_CancelShutdown(NM_CHANNEL_IDX);
        }
        else
        {
            /* Nothing */
        }
    }

#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( NM_E_NO_ERROR != errorId )
    {
        Nm_ReportDevError(NM_SID_COORDREADYTOSLEEPCANCELLATION, errorId);
    }
#else
    NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */


}
#endif  /* NM_COORDINATOR_SYNC_SUPPORT == STD_ON */

#if( NM_PDU_RX_INDICATION_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: Nm_PduRxIndication
*
* Explanation: Notification that a NM message has been received.
*
* param: NetworkHandle: Identification of the NM-channel.
*
* retval: None.
********************************************************************************
*/
FUNC(void, NM_CODE) Nm_PduRxIndication
(
    NetworkHandleType nmNetworkHandle
)
{
    /* Local variables. */
    uint8 errorId = NM_E_NO_ERROR;

    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
#ifdef NM_PDURXIND_CBK
        Nm_PduRxIndicationCbk(NM_CHANNEL_IDX);
#endif
    }

    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( errorId != NM_E_NO_ERROR )
    {
        Nm_ReportDevError(NM_SID_PDURXINDICATION, errorId);
    }
#else
        NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

}
#endif  /* NM_PDU_RX_INDICATION_ENABLED == STD_ON */

#if( NM_STATE_CHANGE_IND_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: Nm_StateChangeNotification
*
* Explanation: Notification that the state of the lower layer <BusNm> has changed.
*
* param: NetworkHandle: Identification of the NM-channel.
*        nmPreviousState: Previous state of the NM-channel.
*        nmCurrentState: Current (new) state of the NM-channel.
*
* retval: None
********************************************************************************
*/
FUNC(void, NM_CODE) Nm_StateChangeNotification
(
    NetworkHandleType nmNetworkHandle,
    Nm_StateType nmLastState,
    Nm_StateType nmCurrentState
)
{
    uint8 errorId = NM_E_NO_ERROR;
    uint8 networkManagementState = NM_ZERO;

    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        switch(nmCurrentState)
        {
            case NM_STATE_REPEAT_MESSAGE:
                switch(nmLastState)
                {
                    case NM_STATE_BUS_SLEEP:
                        networkManagementState = NM_RM_BSM;
                        break;
                    case NM_STATE_PREPARE_BUS_SLEEP:
                        networkManagementState = NM_RM_PBSM;
                        break;
                    case NM_STATE_READY_SLEEP:
                        networkManagementState = NM_RM_RS;
                        break;
                    case NM_STATE_NORMAL_OPERATION:
                        networkManagementState = NM_RM_NO;
                        break;
                    default:
                        /* Do nothing */
                        break;
                }
                break;
            case NM_STATE_NORMAL_OPERATION:
                switch(nmLastState)
                {
                    case NM_STATE_REPEAT_MESSAGE:
                        networkManagementState = NM_NO_RM;
                        break;
                    case NM_STATE_READY_SLEEP:
                        networkManagementState = NM_NO_RS;
                        break;
                    default:
                        /* Do nothing */
                        break;
                }
                break;
            default:
                /* Do nothing */
                break;
        }

        if( TRUE == Nm_ChannelConfig[NM_CHANNEL_IDX].NmStateReportEnabled )
        {
            (void)Com_SendSignal(Nm_ChannelConfig[NM_CHANNEL_IDX].NmStateReportSignalRef, &networkManagementState);
        }
    }
    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( errorId != NM_E_NO_ERROR )
    {
        Nm_ReportDevError(NM_SID_STATECHANGENOTIFICATION, errorId);
    }
#else
        NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

}
#endif /* NM_STATE_CHANGE_IND_ENABLED == STD_ON */

#if( NM_REPEAT_MSG_IND_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: Nm_RepeatMessageIndication
*
* Explanation: Service to indicate that an NM message with set Repeat Message
*              Request Bit has been received.
*
* param: NetworkHandle: Identification of the NM-channel.
*
* retval: None.
********************************************************************************
*/
FUNC(void, NM_CODE) Nm_RepeatMessageIndication
(
    NetworkHandleType nmNetworkHandle
)
{
    uint8 errorId = NM_E_NO_ERROR;

    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
#ifdef NM_REPMSGIND_CBK
        Nm_RepeatMessageIndicationCbk(NM_CHANNEL_IDX);
#endif
    }

    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( errorId != NM_E_NO_ERROR )
    {
        Nm_ReportDevError(NM_SID_REPEATMESSAGEINDICATION, errorId);
    }
#else
        NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

}
#endif  /* NM_REPEAT_MSG_IND_ENABLED == STD_ON */
/*
********************************************************************************
* Function Name: Nm_TxTimeoutException
*
* Explanation: Service to indicate that an attempt to send an NM message failed.
*
* param: NetworkHandle: Identification of the NM-channel.
*
* retval: None.
********************************************************************************
*/
FUNC(void, NM_CODE) Nm_TxTimeoutException
(
    NetworkHandleType nmNetworkHandle
)
{
    /* Local variables. */
    uint8 errorId = NM_E_NO_ERROR;

    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        Nm_TxTimeoutExceptionCbk(NM_CHANNEL_IDX);
    }

    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( errorId != NM_E_NO_ERROR )
    {
        Nm_ReportDevError(NM_SID_TXTIMEOUTEXCEPTION, errorId);
    }
#else
        NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

}

#if( NM_COORDINATOR_SUPPORT_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: Nm_SynchronizationPoint
*
* Explanation: Notification to the NM Coordinator functionality that this is a
*              suitable point in time to initiate the coordinated shutdown on.
*
* param: NetworkHandle: Identification of the NM-channel.
*
* retval: None.
********************************************************************************
*/
FUNC( void, NM_CODE ) Nm_SynchronizationPoint
(
    NetworkHandleType nmNetworkHandle
)
{
    /* Local variables. */
    uint8    errorId = NM_E_NO_ERROR;

    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        if( (TRUE == Nm_ChannelConfig[NM_CHANNEL_IDX].NmSynchronizingNetwork)
            && (Nm_ChannelConfig[NM_CHANNEL_IDX].CoordinatorStateClusterIdx != NM_NO_COORCLUSTER) )
        {
            if( NM_COOR_STA_WAIT_FOR_SYNC == Nm_CoordinatorState[Nm_ChannelConfig[NM_CHANNEL_IDX].CoordinatorStateClusterIdx] )
            {
                Nm_SetCoordState(Nm_ChannelConfig[NM_CHANNEL_IDX].CoordinatorStateClusterIdx, NM_COOR_STA_INITIATE_TIMERS);
            }
        }
    }

    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( NM_E_NO_ERROR != errorId )
    {
        Nm_ReportDevError(NM_SID_SYNCHRONIZATIONPOINT, errorId);
    }
#else
    NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

}
#endif  /* NM_COORDINATOR_SUPPORT_ENABLED == STD_ON */

#if( NM_CAR_WAKE_UP_RX_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: Nm_CarWakeUpIndication
*
* Explanation: This function is called by a <Bus>Nm to indicate reception of a
*              CWU request.
*
* param: NetworkHandle: Identification of the NM-channel.
*
* retval: None.
********************************************************************************
*/
FUNC(void, NM_CODE) Nm_CarWakeUpIndication
(
    NetworkHandleType nmNetworkHandle
)
{
    /* Local variables. */
    uint8 errorId = NM_E_NO_ERROR;

    if( (boolean)FALSE == Nm_GetInitialized() )
    {
        errorId = NM_E_UNINIT;
    }
    /* Check the range of parameters. */
    else if( (nmNetworkHandle >= Nm_GetSizeOfSysToNmChInd()) || (NM_CHANNEL_IDX >= Nm_GetSizeOfChannelConfig()) )
    {
        errorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
#ifdef NM_CARWURX_CBK
        Nm_CarWakeupRxIndicationCbk(NM_CHANNEL_IDX);
#else
        /*
        BswM_NmIf_CarWakeUpIndication(NM_CHANNEL_IDX);
        */
#endif
    }

    /* Dev error report. */
#if( NM_DEV_ERROR_REPORT == STD_ON )
    if( NM_E_NO_ERROR != errorId )
    {
        Nm_ReportDevError(NM_SID_TXTIMEOUTEXCEPTION, errorId);
    }
#else
    NM_DUMMY_STATEMENT(errorId);
#endif  /* NM_DEV_ERROR_REPORT */

}
#endif /* NM_CAR_WAKE_UP_RX_ENABLED == STD_ON */

#if( NM_COORDINATOR_SUPPORT_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: Nm_SetCoordState
*
* Explanation: Set the state of current coordinator.
*
* param: coordinator: coordinator index.
*        state: state to be set.
*
* retval: None.
********************************************************************************
*/
static FUNC(void, NM_CODE) Nm_SetCoordState
(
    uint8 coordinator,
    uint8 state
)
{
    SchM_Enter_Nm_NM_EXCLUSIVE_AREA_0();
    if( NM_COOR_STA_CANCEL_SHUTDOWN != Nm_CoordinatorState[coordinator] )
    {
        Nm_CoordinatorState[coordinator] = state;
    }
    SchM_Exit_Nm_NM_EXCLUSIVE_AREA_0();
}

#if( NM_NO_PASSIVE_COOR_CHANNEL == STD_OFF )
/*
********************************************************************************
* Function Name: Nm_ReleasePassiveCoordCh
*
* Explanation: Release the passive coordinator channel.
*
* param: clusterIdx: The index of cluster.
*
* retval: None.
********************************************************************************
*/
static FUNC(void, NM_CODE) Nm_ReleasePassiveCoordCh
(
    uint8 clusterIdx
)
{
    uint8 channel = NM_ZERO;
    uint8 retVal = E_NOT_OK;

    for( channel = NM_ZERO; channel < NM_NUMBER_OF_CHANNELS; channel ++ )
    {
        if( Nm_ChannelConfig[channel].CoordinatorStateClusterIdx == clusterIdx )
        {
            if( (Nm_ChannelRequestState[channel] != NM_REQ_STA_NETWORK_REQUESTED)
                 && (!Nm_IsActiveCoordinatorChannel(channel)) )
            {
                retVal = Nm_GetNetworkReleaseOfNmFunctionTable(Nm_GetNmFunctionTableIdxOfChannelConfig(channel))(Nm_ChannelConfig[channel].NmChannelId);
                if( E_OK == retVal )
                {
                    Nm_ChannelRequestState[channel] = NM_REQ_STA_NETWORK_RELEASED;
                }
            }
        }
    }
}
#endif

/*
********************************************************************************
* Function Name: Nm_InitiateCoordinatorTimers
*
* Explanation: Initiate the coordinator timers.
*
* param: clusterIdx: The index of cluster.
*
* retval: None.
********************************************************************************
*/
static FUNC(void, NM_CODE) Nm_InitiateCoordinatorTimers
(
    uint8 clusterIdx
)
{
    uint8 channel = NM_ZERO;

    for( channel = NM_ZERO; channel < NM_NUMBER_OF_CHANNELS; channel ++ )
    {
        if( Nm_ChannelConfig[channel].CoordinatorStateClusterIdx == clusterIdx )
        {
            if( Nm_ChannelRequestState[channel] < NM_REQ_STA_NETWORK_RELEASED )
            {

#if( NM_COORDINATOR_SYNC_SUPPORT == STD_ON )
#if( NM_NO_PASSIVE_COOR_CHANNEL == STD_OFF )
                if( Nm_IsActiveCoordinatorChannel(channel) )
#endif
                {
                    Nm_GetSetSleepReadyBitOfNmFunctionTable(Nm_GetNmFunctionTableIdxOfChannelConfig(channel))(Nm_ChannelConfig[channel].NmChannelId, TRUE);
                }
#endif

                Nm_ActiveChannelTimer[channel] = Nm_ChannelConfig[channel].NmShutDownDelayTime;
            }
            else
            {
                Nm_ActiveChannelTimer[channel] = NM_ZERO;
            }
        }
    }
    Nm_SetCoordState(clusterIdx, NM_COOR_STA_WAIT_FOR_TIMERS);
}
/*
********************************************************************************
* Function Name: Nm_CheckCoordinatorTimers
*
* Explanation: Check the coordinator timers.
*
* param: clusterIdx: The index of cluster.
*
* retval: None.
********************************************************************************
*/
static FUNC(void, NM_CODE) Nm_CheckCoordinatorTimers
(
    uint8 clusterIdx
)
{
    uint8 channel = NM_ZERO;
    Std_ReturnType retVal = E_NOT_OK;
    for( channel = NM_ZERO; channel < NM_NUMBER_OF_CHANNELS; channel ++ )
    {
        if( Nm_ChannelConfig[channel].CoordinatorStateClusterIdx == clusterIdx )
        {
            if( Nm_ActiveChannelTimer[channel] > NM_ZERO )
            {
                Nm_ActiveChannelTimer[channel] --;
                if( Nm_ActiveChannelTimer[channel] == NM_ZERO )
                {
                    if( Nm_CoordinatorState[clusterIdx] != NM_COOR_STA_CANCEL_SHUTDOWN )
                    {
                        Nm_GetRequestBusSynchronization(Nm_GetNmFunctionTableIdxOfChannelConfig(channel))(Nm_ChannelConfig[channel].NmChannelId);
                        SchM_Enter_Nm_NM_EXCLUSIVE_AREA_0();
                        if( Nm_CoordinatorState[clusterIdx] != NM_COOR_STA_CANCEL_SHUTDOWN )
                        {
                            retVal = Nm_GetNetworkReleaseOfNmFunctionTable(Nm_GetNmFunctionTableIdxOfChannelConfig(channel))(Nm_ChannelConfig[channel].NmChannelId);
                            if( E_OK == retVal )
                            {
                                Nm_ChannelRequestState[channel] = NM_REQ_STA_NETWORK_RELEASED;
                            }
                            else
                            {
                                Nm_ReInitiationCoordinator(clusterIdx);
                                Nm_CoordinatorState[clusterIdx] = NM_COOR_STA_NETWORK_REQUESTED;
                            }
                        }
                        SchM_Exit_Nm_NM_EXCLUSIVE_AREA_0();
                    }
                }
            }
            else
            {
                /* Do nothing. */
            }
        }
    }

}
/*
********************************************************************************
* Function Name: Nm_CheckCoordinatorSYNC
*
* Explanation: Check the coordinator sync sign.
*
* param: clusterIdx: The index of cluster.
*
* retval: None.
********************************************************************************
*/
static FUNC(void, NM_CODE) Nm_CheckCoordinatorSYNC
(
    uint8 clusterIdx
)
{
    uint8 channel = NM_ZERO;

    for( channel = NM_ZERO; channel < NM_NUMBER_OF_CHANNELS; channel ++ )
    {
        if( (Nm_ChannelConfig[channel].CoordinatorStateClusterIdx == clusterIdx)
             && Nm_ActiveChannelTimer[channel] > NM_ZERO )
        {
            Nm_ActiveChannelTimer[channel] --;
            if( NM_ZERO == Nm_ActiveChannelTimer[channel] )
            {
                Nm_SetCoordState(clusterIdx, NM_COOR_STA_INITIATE_TIMERS);
                break;
            }
        }
    }
}
/*
********************************************************************************
* Function Name: Nm_CheckCoordinatorRelease
*
* Explanation: Check the passive release command.
*
* param: clusterIdx: The index of cluster.
*
* retval: None.
********************************************************************************
*/
static FUNC(void, NM_CODE) Nm_CheckCoordinatorRelease
(
    uint8 clusterIdx
)
{

#if( NM_NO_PASSIVE_COOR_CHANNEL == STD_OFF )
    uint8 pChannelsReadySleep = NM_ONE;
#endif
    uint8 aChannelsReadySleep = NM_ONE;
    uint8 channel = NM_ZERO;
    uint8 syncNetwork = NM_ZERO;

    for( channel = NM_ZERO; channel < NM_NUMBER_OF_CHANNELS; channel ++ )
    {
        if( Nm_ChannelConfig[channel].CoordinatorStateClusterIdx == clusterIdx )
        {

#if( NM_NO_PASSIVE_COOR_CHANNEL == STD_OFF )
            if( Nm_IsActiveCoordinatorChannel(channel) )
#endif
            {
                if( (Nm_ChannelRequestState[channel] != NM_REQ_STA_NETWORK_REQUESTED)
                     && ((Nm_ChannelState[channel] != NM_CH_STA_BUS_WAKE_UP) || (TRUE == Nm_ChannelConfig[channel].NmChannelSleepMaster)) )
                {
                    aChannelsReadySleep &= NM_ONE;
                }
                else
                {
                    aChannelsReadySleep &= NM_ZERO;
                }
                if( (Nm_ChannelRequestState[channel] != NM_REQ_STA_NETWORK_REQUESTED)
                     && (TRUE == Nm_ChannelConfig[channel].NmSynchronizingNetwork) )
                {
                    syncNetwork |= NM_ONE;
                }
            }
#if( NM_NO_PASSIVE_COOR_CHANNEL == STD_OFF )
            else
            {
                if( (Nm_ChannelRequestState[channel] != NM_REQ_STA_NETWORK_REQUESTED)
                     && (Nm_ChannelState[channel] != NM_CH_STA_BUS_WAKE_UP) )
                {
                    pChannelsReadySleep &= NM_ONE;
                }
                else
                {
                    pChannelsReadySleep &= NM_ZERO;
                }
            }
#endif

        }
    }

    if( aChannelsReadySleep != NM_ZERO )
    {

#if( NM_NO_PASSIVE_COOR_CHANNEL == STD_OFF )
        if( NM_ZERO == pChannelsReadySleep )
        {
            if( Nm_CoordinatorState[clusterIdx] != NM_COOR_STA_CANCEL_SHUTDOWN )
            {
                Nm_ReleasePassiveCoordCh(clusterIdx);
            }
        }
        else
#endif
        {
            if( syncNetwork )
            {
                for( channel = NM_ZERO; channel < NM_NUMBER_OF_CHANNELS; channel ++ )
                {
                    if( Nm_ChannelConfig[channel].CoordinatorStateClusterIdx == clusterIdx )
                    {
                        if( TRUE == Nm_ChannelConfig[channel].NmSynchronizingNetwork )
                        {
                            Nm_ActiveChannelTimer[channel] = NM_WAIT_FOR_SYNC_TIMEOUT;
                        }
                        else
                        {
                            Nm_ActiveChannelTimer[channel] = NM_ZERO;
                        }
                    }
                }
                Nm_SetCoordState(clusterIdx, NM_COOR_STA_WAIT_FOR_SYNC);
            }
            else
            {
                Nm_SetCoordState(clusterIdx, NM_COOR_STA_INITIATE_TIMERS);
            }
        }
    }
    else
    {
        /* Do nothing */
    }

}

/*
********************************************************************************
* Function Name: Nm_CoordinatorHandling
*
* Explanation: Handle the corrdinator for current cluster.
*
* param: clusterIdx: The index of cluster.
*
* retval: None.
********************************************************************************
*/
static FUNC(void, NM_CODE) Nm_CoordinatorHandling
(
    uint8 clusterIdx
)
{
    uint8 coordSta = Nm_CoordinatorState[clusterIdx];

    if( NM_COOR_STA_SHUTDOWN == coordSta )
    {
        Nm_ShutdownHandling(clusterIdx);
    }
    else if( NM_COOR_STA_CANCEL_SHUTDOWN == coordSta )
    {
        Nm_ReInitiationCoordinator(clusterIdx);
        Nm_CoordinatorState[clusterIdx] = NM_COOR_STA_NETWORK_REQUESTED;
    }
    else
    {
        if( NM_COOR_STA_NETWORK_REQUESTED == coordSta )
        {
            Nm_CheckCoordinatorRelease(clusterIdx);
        }

        if( NM_COOR_STA_INITIATE_TIMERS == coordSta )
        {
            Nm_InitiateCoordinatorTimers(clusterIdx);
        }

        if( NM_COOR_STA_WAIT_FOR_TIMERS == coordSta )
        {
            Nm_CheckCoordinatorTimers(clusterIdx);
        }

        if( NM_COOR_STA_WAIT_FOR_SYNC == coordSta )
        {
            Nm_CheckCoordinatorSYNC(clusterIdx);
        }
    }

}

/*
********************************************************************************
* Function Name: Nm_MainFunction
*
* Explanation: This function implements the processes of the NM Interface, which
*              need a fix cyclic scheduling.
*
* param: None.
*
* retval: None.
********************************************************************************
*/
FUNC(void, NM_CODE) Nm_MainFunction(void)
{
    uint8    coorCluster = NM_ZERO;
    if( (boolean)FALSE != Nm_GetInitialized() )
    {
        for( coorCluster = NM_ZERO; coorCluster < NM_NUMBER_OF_COOR_CLUSTER; coorCluster++ )
        {
            Nm_CoordinatorHandling(coorCluster);
        }
    }
}
#endif  /* NM_COORDINATOR_SUPPORT_ENABLED == STD_ON */

#define NM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Nm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
