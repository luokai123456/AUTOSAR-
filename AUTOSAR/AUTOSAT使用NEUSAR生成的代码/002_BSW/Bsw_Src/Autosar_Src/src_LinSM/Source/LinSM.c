/*
********************************************************************************
*
* File name: LinSM.c
*
* Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJipeng/2020.04.03
* Change: new created.
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: lizhiheng/2020.06.29
* Change: Modify function precompilation.
* Cause: Update
********************************************************************************
* Version: 1.2
* Author/Date: lizhiheng/2020.06.29
* Change: Add code comments.
* Cause: Update
********************************************************************************
* Version: 1.3
* Author/Date: lizhiheng/2020.06.30
* Change: Tabs to Spaces.
* Cause: Update
********************************************************************************
* Version: 1.4
* Author/Date: lizhiheng/2020.07.01
* Change: File log error.
* Cause: Update
********************************************************************************
* Version: 3.0
* Author/Date: lizhiheng/2020.07.01
* Change: Update to 3.0.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: lizhiheng/2020.07.16
* Change: Modify coding specification.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: lizhiheng/2020.07.20
* Change: Modify coding specification.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: lizhiheng/2020.09.25
* Change: Modified to AutoSar coding style.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: lizhiheng/2020.10.10
* Change: Optimized coding specification.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: lizhiheng/2020.10.10
* Change: 1.Optimized coding specification.
*         2.Modify QAC warning.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: lizhiheng/2020.10.16
* Change: Clears the initialization of local variables.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: LiZH/2020.10.26
* Change: Modify the service ID of LinSM_ScheduleRequest.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: LiZH/2020.10.27
* Change: Modify request status after activation.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: LiZH/2020.11.02
* Change: 1.Modify the mapmap to contain the processing of the initialization variable.
*         2.Add LinTrcv_cfg.h for precompilation.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: LiZH/2020.11.02
* Change: Optimize code structure.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: LiZH/2020.11.04
* Change: The MemMap of the modified function declaration contains.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: LiZH/2020.11.05
* Change: Optimize code structure.
* Cause: Optimize
********************************************************************************
* Version: 3.13
* Author/Date: LiZH/2020.11.05
* Change: Clear warning.
* Cause: Optimize
********************************************************************************
* Version: 3.14
* Author/Date: LiZH/2020.11.24
* Change: Clear warning.
* Cause: Optimize
********************************************************************************
* Version: 3.15
* Author/Date : Li.ZH/2021.8.16
* Change: Modification code specification.
* Cause: Optimize
********************************************************************************
* Version: 3.16
* Author/Date : LiZH/2021.10.28
* Change: Modification #include "LinTrcv.h".
* Cause: Optimize
********************************************************************************
* Version: 3.17
* Author/Date: LiuZY/2023.01.09
* Change: Add wake-up failure judgment and handling.
* Cause: Bugfix
********************************************************************************
* Version: 3.18
* Author/Date: LiuZY/2023.03.03
* Change: Supports call BswM_LinSM_CurrentState function.
* Cause: Optimize
********************************************************************************
* Version: 3.19
* Author/Date: LiuZY/2023.03.13
* Change: Supports call BswM_LinSM_CurrentSchedule function.
* Cause: Bugfix
********************************************************************************
* Version: 3.20
* Author/Date: LiXB/2023.06.29
* Change: Support slave node: 1)Due to polyspace change LinSM_SetToSleep
*                             2)Add node type judgement to function LinSM_ScheduleRequest
*                             and LinSM_ScheduleRequestConfirmation
*                             3)Due to slave com mode request change LinSM_RequestComMode
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date: LiXB/2023.07.08
* Change: Delete redundant function declaration
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date: LiXB/2023.08.02
* Change: Due to self test fix function LinSM_RequestComMode in slave node
*         CCOREDBUG-3545: Set substate of LinSM_Management_Tab in function
*         LinSM_RequestComMode.
*         Delete redundant variable definition and use networkid to call 
*         LinIf_GotoSleep in function LinSM_GotoSleepIndication.
*         CCOREDBUG-3554: Reset LinSM state of slave node when GotoSleep is 
*         completed in LinSM_GotoSleepConfirmation
* Cause: Bugfix
********************************************************************************
* Version: 3.23
* Author/Date: LiXB/2023.08.15
* Change: CCOREDBUG-3684:Fix restart wakeup process, when ComM mode is requested.
*         Fix function LinSM_RequestComMode, LinSM_GotoSleepIndication
* Cause: Bugfix
********************************************************************************
* Version: 3.24
* Author/Date: ZhangXF/2023.10.30
* Change: 1)Add NULL Schedule for MASTER Node initialization in LinSM_Init
          2)Add schedule request failure judgment and handling
          3)Add Det_ReportRuntimeError API
* Cause: Update
********************************************************************************
* Version: 3.25
* Author/Date: ZhangXF/2024.03.18
* Change: CCOREDBUG-4417:Modify LinSM_SetToSleep and LinSM_GotoSleepConfirmation
* Cause: Bugfix
********************************************************************************
* Version: 3.26
* Author/Date: TianG/2024.06.27
* Change: 1. Add a memory-map label to function.
*         2. Deletes the condition under which the network state is judged 
*            when LIN request COMM_FULL_COMMUNICATION.
*         3. Modify copyright.
*         4. Modify the comments format.
* Cause: Bugfix
********************************************************************************
* Version: 3.27
* Author/Date: TianG/2024.11.04
* Change: Optimize sleep and wake up processes for LinSM.
* Cause: Bugfix
********************************************************************************
* Version: 3.28
* Author/Date: TianG/2024.11.08
* Change: The return value is not judged when the LinIf_SetTrcvMode function is called 
*         in the LinSM_GotoSleepConfirmation function.
* Cause: Bugfix
********************************************************************************
* Version: 3.29
* Author/Date: TianG/2025.03.25
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.30
* Author/Date: YanCL/2025.06.16
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.31
* Author/Date: YanCL/2025.06.23
* Change: #include "LinSM_MemMap.h" add suppression comments.
* Cause: Update
********************************************************************************
* Version: 3.32
* Author/Date: TianG/2025.07.14
* Change: Add the QAC deviation suppression comment.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "LinSM.h"

#include "ComM_BusSM.h"

#include "SchM_LinSM.h"

#if ( LINSM_BSWMENABLED == STD_ON )
#include "BswM_LinSM.h"
#endif

#include "Lin_GeneralTypes.h"

#if ( LINIF_TRCV_DRIVER_SUPPORTED == STD_ON )
#include "LinTrcv.h"
#endif

#if ( LINSM_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/* critical section macros. */
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define LinSM_EnterCritical() SchM_Enter_LinSM_LINSM_EXCLUSIVE_AREA_0()
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define LinSM_LeaveCritical() SchM_Exit_LinSM_LINSM_EXCLUSIVE_AREA_0()

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
#define LINSM_START_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinSM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinSM_NonSharedVar" */
static VAR(boolean, LINSM_VAR_INIT) LinSM_Init_Finish = FALSE; /* LinSM init state. */

#define LINSM_STOP_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinSM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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
#define LINSM_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinSM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
#if ( LINSM_DEV_ERROR_DETECT == STD_ON )
static FUNC(void, LINSM_CODE) LinSM_Det_ErrorReport
(
    uint8 ApiId,
    uint8 ErrId
);
#endif

static FUNC(boolean, LINSM_CODE) LinSM_ChkInitialized
(
    void
);
static FUNC(boolean, LINSM_CODE) LinSM_ChkNetwork
(
    NetworkHandleType network,
    P2VAR(uint8, AUTOMATIC, LINSM_APPL_DATA) channlNo
);
static FUNC(boolean, LINSM_CODE) LinSM_ChkSchdule
(
    uint8 channlIndex,
    LinIf_SchHandleType schedule
);
static FUNC(boolean, LINSM_CODE) LinSM_ChkMode
(
    ComM_ModeType mode
);
static FUNC(uint16, LINSM_CODE) LinSM_Chk_ScheduleRequest
(
    NetworkHandleType network,
    LinIf_SchHandleType schedule
);
static FUNC(uint16, LINSM_CODE) LinSM_Chk_GetCurrntComMode
(
    NetworkHandleType network,
    P2VAR(ComM_ModeType, AUTOMATIC, LINSM_APPL_DATA) mode
);
static FUNC(ComM_ModeType, LINSM_CODE) LinSM_GetNetworkState
(
    uint8 channel
);
static FUNC(void, LINSM_CODE) LinSM_StartConfirmTimer
(
    uint8 channel
);
static FUNC(void, LINSM_CODE) LinSM_StopConfirmTimer
(
    uint8 channel
);
static FUNC(Std_ReturnType, LINSM_CODE) LinSM_SetToSleep
(
    uint8 index,
    NetworkHandleType network
);
static FUNC(Std_ReturnType, LINSM_CODE) LinSM_SetToWakeup
(
    uint8 index,
    NetworkHandleType network
);
#define LINSM_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinSM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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
#define LINSM_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinSM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if ( LINSM_DEV_ERROR_DETECT == STD_ON )
/*
********************************************************************************
* Function Name: LinSM_Det_ErrorReport
*
* Explanation: Report Error to Det.(Synchronous)
*
* param: ApiId:Unique Api ID of LinSM.
*         ErrorId: Det Error ID of LinSM.
*
* retval: None
********************************************************************************
*/
static FUNC(void, LINSM_CODE) LinSM_Det_ErrorReport
(
    uint8 ApiId,
    uint8 ErrId
)
{
    /* Report Error to Det. */
    (void)Det_ReportError(LINSM_MODULE_ID, LINSM_INSTANCE_ID, ApiId, ErrId);
}

/*
********************************************************************************
* Function Name: LinSM_Det_RuntimeErrorReport
*
* Explanation: Report Runtime Error to Det.(Synchronous)
*
* param: ApiId:Unique Api ID of LinSM.
*         ErrorId: Det Error ID of LinSM.
*
* retval: None
********************************************************************************
*/
static FUNC(void, LINSM_CODE) LinSM_Det_RuntimeErrorReport
(
    uint8 ApiId,
    uint8 ErrId
)
{
    /* Report Runtime Error to Det. */
    (void)Det_ReportRuntimeError(LINSM_MODULE_ID, LINSM_INSTANCE_ID, ApiId, ErrId);
}

#endif

/*
********************************************************************************
* Function Name: LinSM_ChkInitialized
*
* Explanation: Check initialization completed.(Synchronous)
*
* param: None
*
* retval: TRUE: Initialization completed.
*         FALSE: Otherwise.
********************************************************************************
*/
static FUNC(boolean, LINSM_CODE) LinSM_ChkInitialized
(
    void
)
{
    boolean flag = FALSE;
    if( TRUE == LinSM_Init_Finish )
    {
        flag = TRUE; /* Initialization completed. */
    }
    return flag;
}

/*
********************************************************************************
* Function Name: LinSM_ChkNetwork
*
* Explanation: Check if the network exists.(Synchronous)
*
* param: network: Identification of the LIN channel.
*        channlNo: LinSM channel index.
*
* retval: TRUE: Referenced network exist.
*         FALSE: Otherwise.
********************************************************************************
*/
static FUNC(boolean, LINSM_CODE) LinSM_ChkNetwork
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    NetworkHandleType network,
    P2VAR(uint8, AUTOMATIC, LINSM_APPL_DATA) channlNo
)
{
    boolean retVal = FALSE;
    uint8 index;

    *channlNo = LINSM_INIT_ZERO;
    /* Find channel index. */
    for( index = LINSM_INIT_ZERO; index < LINSM_NETWORK_TOTAL_NUMBER; index++ )
    {
        if( network == LinSM_Channl_Cfg_Tab[index].networkId )
        {
            *channlNo = index;
            retVal = TRUE;
            break;
        }
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: LinSM_ChkSchdule
*
* Explanation: Check if the schedule exists.(Synchronous)
*
* param: channlIndex: LinSM channel index.
*        schedule: Pointer to the new Schedule table.
*
* retval: TRUE: Schedule exists
*         FALSE: Otherwise.
********************************************************************************
*/
static FUNC(boolean, LINSM_CODE) LinSM_ChkSchdule
(
    uint8 channlIndex,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    LinIf_SchHandleType schedule
)
{
    boolean retVal = FALSE;
    uint8 loopIndex;
    uint8 startIndex;
    uint8 endIndex;

    startIndex = LinSM_Channl_Cfg_Tab[channlIndex].scheduleStartIndex;
    endIndex = LinSM_Channl_Cfg_Tab[channlIndex].scheduleEndIndex;

    /* Find schedule index. */
    for( loopIndex = startIndex; loopIndex < endIndex; loopIndex++ )
    {
        if( schedule == LinSM_ScheduleIdx_Info[loopIndex] )
        {
            retVal = TRUE;
            break;
        }
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: LinSM_ChkMode
*
* Explanation: Check if the mode is in range.(Synchronous)
*
* param: mode: Request mode.
*
* retval: TRUE: Valid mode.
*         FALSE: Otherwise.
********************************************************************************
*/
static FUNC(boolean, LINSM_CODE) LinSM_ChkMode
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    ComM_ModeType mode
)
{
    boolean retVal = FALSE;

    /* If COMM_SILENT_COMMUNICATION is requested the function shall return E_NOT_OK directly without action. */
    if( (COMM_NO_COMMUNICATION == mode) || (COMM_FULL_COMMUNICATION == mode) )
    {
        retVal = TRUE;
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: LinIf_Chk_SchduleRequest
*
* Explanation: Check SchduleRequest development error.(Synchronous)
*
* param: network: Identification of the LIN channel.
*        schedule: Pointer to the new Schedule table.
*
* retval: Lower 8bit: error ID. Higher 8bit:Network cahnnel index.
********************************************************************************
*/
static FUNC(uint16, LINSM_CODE) LinSM_Chk_ScheduleRequest
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    NetworkHandleType network,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    LinIf_SchHandleType schedule
)
{
    uint8 chkRslt = LINSM_E_NO_ERR;
    uint8 channlIndex = LINSM_INIT_ZERO;
    uint16 rtnValue;

    /* Check if initialization is completed. */
    if( (boolean)FALSE == LinSM_ChkInitialized() )
    {
        chkRslt = LINSM_E_UNINIT;
    }
    else if( (boolean)FALSE == LinSM_ChkNetwork(network, &channlIndex) )
    {
        chkRslt = LINSM_E_NONEXISTENT_NETWORK;
    }
    else if( (boolean)FALSE == LinSM_ChkSchdule(channlIndex, schedule) )
    {
        chkRslt = LINSM_E_PARAMETER;
    }
    else
    {
        /* Do nothing. */
    }

    rtnValue = ((uint16)channlIndex << LINSM_SHIFT_8BIT);
    rtnValue = ((uint16)chkRslt & LINSM_LOW_BYTE) | rtnValue;

    return rtnValue;
}

/*
********************************************************************************
* Function Name: LinSM_Chk_GetCurrntComMode
*
* Explanation: Check GetCurrntComMode development error.(Synchronous)
*
* param: network: Identification of the LIN channel.
*        mode: Returns the active mode, see ComM_ModeType for descriptions of the modes.
*
* retval: Lower 8bit: error ID. Higher 8bit:Network cahnnel index.
********************************************************************************
*/
static FUNC(uint16, LINSM_CODE) LinSM_Chk_GetCurrntComMode
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    NetworkHandleType network,
    P2VAR(ComM_ModeType, AUTOMATIC, LINSM_APPL_DATA) mode
)
{
    uint8 chkRslt = LINSM_E_NO_ERR;
    uint8 channlIndex = LINSM_INIT_ZERO;
    uint16 rtnValue;

    LINSM_DUMMY_STATEMENT(mode);

    /* Check if initialization is completed. */
    if( (boolean)FALSE == LinSM_ChkInitialized() )
    {
        chkRslt = LINSM_E_UNINIT;
    }
    else if( (boolean)FALSE == LinSM_ChkNetwork(network, &channlIndex) )
    {
        chkRslt = LINSM_E_NONEXISTENT_NETWORK;
    }
    else if( NULL_PTR == mode )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        chkRslt = LINSM_E_PARAM_POINTER;
    }
    else
    {
        /* Do nothing. */
    }

    rtnValue = ((uint16)channlIndex << LINSM_SHIFT_8BIT);
    rtnValue = ((uint16)chkRslt & LINSM_LOW_BYTE) | rtnValue;

    return rtnValue;
}

/*
********************************************************************************
* Function Name: LinSM_Chk_RequestComMode
*
* Explanation: Check RequestComMode development error.(Synchronous)
*
* param: network: Identification of the LIN channel.
*        mode: Request mode.
*
* retval: Lower 8bit: error ID. Higher 8bit:Network cahnnel index.
********************************************************************************
*/
static FUNC(uint16, LINSM_CODE) LinSM_Chk_RequestComMode
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    NetworkHandleType network,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    ComM_ModeType mode
)
{
    uint8 chkRslt = LINSM_E_NO_ERR;
    uint8 channlIndex = LINSM_INIT_ZERO;
    uint16 rtnValue;

    /* Check if initialization is completed. */
    if( (boolean)FALSE == LinSM_ChkInitialized() )
    {
        chkRslt = LINSM_E_UNINIT;
    }
    else if( (boolean)FALSE == LinSM_ChkNetwork(network, &channlIndex) )
    {
        chkRslt = LINSM_E_NONEXISTENT_NETWORK;
    }
    else if( (boolean)FALSE == LinSM_ChkMode(mode) )
    {
        chkRslt = LINSM_E_PARAMETER;
    }
    else
    {
        /* Do nothing. */
    }

    rtnValue = ((uint16)channlIndex << LINSM_SHIFT_8BIT);
    rtnValue = ((uint16)chkRslt & LINSM_LOW_BYTE) | rtnValue;

    return rtnValue;
}

/*
********************************************************************************
* Function Name: LinSM_GetNetworkState
*
* Explanation: Get current network state.(Synchronous)
*
* param: channl: Network cahnnel index.
*
* retval: Current network state.
********************************************************************************
*/
static FUNC(ComM_ModeType, LINSM_CODE) LinSM_GetNetworkState
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    uint8 channel
)
{
    return ( LinSM_Management_Tab[channel].curState );
}

/*
********************************************************************************
* Function Name: LinSM_StartConfirmTimer
*
* Explanation: Start confirmation timer.(Synchronous)
*
* param: channlNo: Lin channel index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, LINSM_CODE) LinSM_StartConfirmTimer
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    uint8 channel
)
{
    LinSM_Management_Tab[channel].timerState = LINSM_START_TIMER;
    LinSM_Management_Tab[channel].timeOutCntr = LINSM_INIT_ZERO;
}

/*
********************************************************************************
* Function Name: LinSM_StopConfirmTimer
*
* Explanation: Stop confirmation timer.(Synchronous)
*
* param: channlNo: Lin channel index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, LINSM_CODE) LinSM_StopConfirmTimer
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    uint8 channel
)
{
    LinSM_Management_Tab[channel].timerState = LINSM_STOP_TIMER;
    LinSM_Management_Tab[channel].timeOutCntr = LINSM_INIT_ZERO;
}

/*
********************************************************************************
* Function Name: LinSM_SetToSleep
*
* Explanation: Set lower layer to sleep.(Synchronous)
*
* param: index: LinSM network.
*        network: LinIf network.
*
* retval: E_OK: Request has been accepted.
*         E_NOT_OK: Request falied.
********************************************************************************
*/
static FUNC(Std_ReturnType, LINSM_CODE) LinSM_SetToSleep
(
    uint8 index,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    NetworkHandleType network
)
{
    Std_ReturnType retVal = E_NOT_OK;
    if( (LINSM_FULL_COM == LinSM_Management_Tab[index].curState)
        && (LINSM_RUN_COMMUNICATION == LinSM_Management_Tab[index].subState) )
    {
        LinSM_StartConfirmTimer(index);
        if( (Std_ReturnType)E_OK == LinIf_GotoSleep(network) )
        {
            retVal = E_OK;
            LinSM_Management_Tab[index].subState = LINSM_GOTO_SLEEP;
        }
    }
    return retVal;
}

/*
********************************************************************************
* Function Name: LinSM_SetToWakeup
*
* Explanation: Set lower layer to wakeup.(Synchronous)
*
* param: index: LinSM network.
*        network: LinIf network.
*
* retval: E_OK: Request has been accepted.
*         E_NOT_OK: Request falied.
********************************************************************************
*/
static FUNC(Std_ReturnType, LINSM_CODE) LinSM_SetToWakeup
(
    uint8 index,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    NetworkHandleType network
)
{
    Std_ReturnType retVal;

    LinSM_StartConfirmTimer(index);
    /* Set LinSM substate to LINSM_WAKEUP. */
    LinSM_Management_Tab[index].subState = LINSM_WAKEUP;
    retVal = LinIf_Wakeup(network);
    /* When entering LINSM_FULL_COM the transceiver shall be set to active by using the LinIf_SetTrcvMode. */
    /* Polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_LinSM_Rule14.3" Polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
    if( ((Std_ReturnType)E_OK == retVal) &&((boolean)STD_ON == LinSM_Channl_Cfg_Tab[index].transPassiveMode) )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
#if ( STD_ON == LINIF_TRCV_DRIVER_SUPPORTED )
        retVal = LinIf_SetTrcvMode(network, LINTRCV_TRCV_MODE_NORMAL);
#else
        retVal = E_OK;
#endif
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: LinSM_Init
*
* Explanation: This function initializes the LinSM.(Synchronous)
*
* param: ConfigPtr:Pointer to the LinSM post-build configuration data.(Unused)
*
* retval: None
********************************************************************************
*/
FUNC(void, LINSM_CODE) LinSM_Init
(
    P2CONST(LinSM_ConfigType, AUTOMATIC, LINSM_APPL_CONST) ConfigPtr
)
{
    uint8 index;

    LINSM_DUMMY_STATEMENT(ConfigPtr);
    for( index = LINSM_INIT_ZERO; index < LINSM_NETWORK_TOTAL_NUMBER; index++ )
    {
        if( LINSM_CHANNEL_MASTER == LinSM_Channl_Cfg_Tab[index].nodeChannelType )
        {
            LinSM_Management_Tab[index].curSchedule = LinSM_Channl_Cfg_Tab[index].scheduleStartIndex;
        }
        LinSM_Management_Tab[index].curState = LINSM_NO_COM;
        LinSM_Management_Tab[index].reqMode = LINSM_NO_COM;
        LinSM_Management_Tab[index].subState = LINSM_NO_COM;
        LinSM_Management_Tab[index].reqState = LINSM_NO_REQUEST;
        LinSM_Management_Tab[index].timerState = LINSM_STOP_TIMER;
        LinSM_Management_Tab[index].retryTimes= LINSM_INIT_ZERO;
        LinSM_Management_Tab[index].timeOutCntr = LINSM_INIT_ZERO;
    }
    LinSM_Init_Finish = TRUE;
}

#if( LINSM_VERSION_INFO_API == STD_ON )
/*
********************************************************************************
* Function Name: LinSM_GetVersionInfo
*
* Explanation: Service to get the version information of LinSM module.(Synchronous)
*
* param: versioninfo:Pointer to where to store the version information of this module.
*
* retval: None
********************************************************************************
*/
FUNC(void, LINSM_CODE) LinSM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, LINSM_APPL_DATA) versioninfo
)
{
    uint8 chkRslt = LINSM_E_NO_ERR;

    if( NULL_PTR == versioninfo )   /* Pointer parameter is Null. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        chkRslt = LINSM_E_PARAM_POINTER;
    }
    else
    {
        /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.14" Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_LinSM_TAINTED_PTR" */
        versioninfo->vendorID = LINSM_VENDOR_ID;
        versioninfo->moduleID = LINSM_MODULE_ID;
        versioninfo->sw_major_version = LINSM_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = LINSM_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = LINSM_SW_PATCH_VERSION;
    }

#if ( LINSM_DEV_ERROR_DETECT == STD_ON )
    if( chkRslt != LINSM_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinSM_Det_ErrorReport(LINSM_GET_VERSION_INFO, chkRslt);
    }
#else
    LINSM_DUMMY_STATEMENT(chkRslt);
#endif
}
#endif

#if( LINSM_MASTER_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: LinSM_ScheduleRequest
*
* Explanation: The upper layer requests a schedule table to be changed on one LIN network.(Asynchronous)
*
* param: network: Identification of the LIN channel.
*        schedule: Pointer to the new Schedule table.
*
* retval: E_OK: Schedule table request has been accepted.
*         E_NOT_OK: Schedule table switch request has not been accepted due to one of the following reasons:
*                   - LinSM has not been initialized referenced channel does not exist (identification is out of range)
*                   - Referenced schedule table does not exist (identification is out of range)
*                   - Sub-state is not LINSM_FULL_COM
********************************************************************************
*/
FUNC(Std_ReturnType, LINSM_CODE) LinSM_ScheduleRequest
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    NetworkHandleType network,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    LinIf_SchHandleType schedule
)
{
    uint8 index;
    uint8 errId;
    Std_ReturnType retVal = E_NOT_OK;
    uint16 chkRslt;

    chkRslt = LinSM_Chk_ScheduleRequest(network, schedule);
    index = (uint8)(chkRslt >> LINSM_SHIFT_8BIT);
    errId = (uint8)chkRslt;
    
    if( LINSM_CHANNEL_MASTER != LinSM_Channl_Cfg_Tab[index].nodeChannelType )
    {
        /* do nothing */
    }
    else if( (uint8)LINSM_E_NO_ERR == errId )
    {
        /* Enter critical area. */
        LinSM_EnterCritical();
        /* Check if LinSM is in full communication state. */
        /* Check if LinSM substate is in LINSM_RUN_COMMUNICATION state. */
        /* Check if a schedule switch is being requested. */
        if( (LINSM_FULL_COM == LinSM_Management_Tab[index].curState)
            && (LINSM_RUN_COMMUNICATION == LinSM_Management_Tab[index].subState)
            && (LINSM_NO_REQUEST == LinSM_Management_Tab[index].reqState) )
        {
            
            retVal = LinIf_ScheduleRequest(network, schedule);
            
            if( E_NOT_OK == retVal )
            {
                 LinSM_Management_Tab[index].reqState = LINSM_REQUEST_INVALID;
            }
            else
            {
                /*request success*/
                LinSM_StartConfirmTimer(index);
                LinSM_Management_Tab[index].reqState = LINSM_REQUEST_SCHEDULE; 
            }
        }
        /* Leave critical area. */
        LinSM_LeaveCritical();
    }
    else
    {
        /* Do nothing */
    }

#if ( LINSM_DEV_ERROR_DETECT == STD_ON )
    if( errId != LINSM_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinSM_Det_ErrorReport(LINSM_SCHEDULE_REQUEST, errId);
    }
#endif

    return retVal;
}

/*
********************************************************************************
* Function Name: LinSM_ScheduleRequestConfirmation
*
* Explanation: The LinIf module will call this callback when the new requested
*              schedule table is active.(Synchronous)
*
* param: network: Identification of the LIN channel.
*        schedule: Pointer to the new active Schedule table.
*
* retval: None
********************************************************************************
*/
/* Polyspace +1 MISRA-C3:8.4 [Justified:Unset] "NSCA_Polyspace_LinSM_Rule8.4" */
FUNC(void, LINSM_CODE) LinSM_ScheduleRequestConfirmation  /* PRQA S 3408 */ /* NSCA_QAC_Common_Rule8.4 */
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    NetworkHandleType network,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    LinIf_SchHandleType schedule
)
{
    uint8 chkRslt = LINSM_E_NO_ERR;
    uint8 index = LINSM_INIT_ZERO;

    LINSM_DUMMY_STATEMENT(schedule);

    if( (boolean)FALSE == LinSM_ChkInitialized() )      /* Check if initialization is completed. */
    {
        chkRslt = LINSM_E_UNINIT;
    }
    else if( (boolean)FALSE == LinSM_ChkNetwork(network, &index) )
    {
        chkRslt = LINSM_E_NONEXISTENT_NETWORK;
    }
    else if( LINSM_CHANNEL_MASTER != LinSM_Channl_Cfg_Tab[index].nodeChannelType )
    {
        /* Do nothing */
    }
    else
    {
        /* Timeout. */
        if( LINSM_CONFIRM_TO == LinSM_Management_Tab[index].timerState )
        {
            LinSM_StopConfirmTimer(index);
        }
        else
        {
            LinSM_StopConfirmTimer(index);
            LinSM_Management_Tab[index].curSchedule = schedule;
            LinSM_Management_Tab[index].reqState = LINSM_NO_REQUEST;
#if ( LINSM_BSWMENABLED == STD_ON )
            (void)BswM_LinSM_CurrentSchedule(network, schedule);
#endif
        }
    }

#if ( LINSM_DEV_ERROR_DETECT == STD_ON )
    if( chkRslt == LINSM_E_CONFIRMATION_TIMEOUT )
    { 
        LinSM_Det_RuntimeErrorReport(LINSM_SCHDULE_REQUEST_CONFIRMATION, chkRslt);
    }
    else if( chkRslt != LINSM_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinSM_Det_ErrorReport(LINSM_SCHDULE_REQUEST_CONFIRMATION, chkRslt);
    }
#else
    LINSM_DUMMY_STATEMENT(chkRslt);
#endif
}
#endif /* LINSM_MASTER_SUPPORT == STD_ON */

/*
********************************************************************************
* Function Name: LinSM_GetCurrentComMode
*
* Explanation: Function to query the current communication mode.(Synchronous)
*
* param: network: Identification of the LIN channel.
*        mode: Returns the active mode, see ComM_ModeType for descriptions of the modes.
*
* retval: E_OK: Ok.
*         E_NOT_OK: Not possible to perform the request, e.g. not initialized.
********************************************************************************
*/
FUNC(Std_ReturnType, LINSM_CODE) LinSM_GetCurrentComMode
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    NetworkHandleType network,
    P2VAR(ComM_ModeType, AUTOMATIC, LINSM_APPL_DATA) mode
)
{
    uint8 index;
    uint8 errId;
    Std_ReturnType retVal = E_NOT_OK;
    uint16 chkRslt;

    chkRslt = LinSM_Chk_GetCurrntComMode(network, mode);
    index = (uint8)(chkRslt >> LINSM_SHIFT_8BIT);
    errId = (uint8)chkRslt;

    if( LINSM_E_NO_ERR == errId )
    {
        retVal = E_OK;

        /* Query the current communication mode. */
        if( LINSM_FULL_COM == LinSM_GetNetworkState(index) )
        {
            /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.14" Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_LinSM_TAINTED_PTR" */
            *mode = COMM_FULL_COMMUNICATION;
        }
        else if( LINSM_NO_COM == LinSM_GetNetworkState(index) )
        {
            /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.14" Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_LinSM_TAINTED_PTR" */
            *mode = COMM_NO_COMMUNICATION;
        }
        else
        {
            retVal = E_NOT_OK;
        }
    }
    else
    {
        /* If active state is LINSM_UNINIT the state COMM_NO_COMMUNICATION shall be returned. */
        if( LINSM_E_UNINIT == errId ) /* SWS_LinSM_00182 */
        {
            /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.14" Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_LinSM_TAINTED_PTR" */
            *mode = COMM_NO_COMMUNICATION;
        }
    }

#if ( LINSM_DEV_ERROR_DETECT == STD_ON )
    if( errId != LINSM_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinSM_Det_ErrorReport(LINSM_GET_CURRENT_COM_MODE, errId);
    }
#endif

    return retVal;
}

/*
********************************************************************************
* Function Name: LinSM_RequestComMode
*
* Explanation: Requesting of a communication mode.(Asynchronous)
*
* param: network: Identification of the LIN channel.
*        mode: Request mode.
*
* retval: E_OK: Request accepted.
*         E_NOT_OK: Not possible to perform the request, e.g. not initialized.
********************************************************************************
*/
FUNC(Std_ReturnType, LINSM_CODE) LinSM_RequestComMode
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    NetworkHandleType network,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    ComM_ModeType mode
)
{
    uint8 index;
    uint8 errId;
    Std_ReturnType retVal = E_NOT_OK;
    uint16 chkRslt;

    chkRslt = LinSM_Chk_RequestComMode(network, mode);
    index = (uint8)(chkRslt >> LINSM_SHIFT_8BIT);
    errId = (uint8)chkRslt;

    if( LINSM_E_NO_ERR == errId )
    {
        if( COMM_NO_COMMUNICATION == mode )
        {
            if( LINSM_NO_COM != LinSM_GetNetworkState(index) )
            {
                if( LINSM_CHANNEL_MASTER == LinSM_Channl_Cfg_Tab[index].nodeChannelType )
                {
                    retVal = LinSM_SetToSleep(index, network);
                    LinSM_Management_Tab[index].retryTimes = LINSM_INIT_ZERO;
                }
                else if( LINSM_CHANNEL_SLAVE == LinSM_Channl_Cfg_Tab[index].nodeChannelType )
                {
                    LinSM_Management_Tab[index].subState = LINSM_GOTO_SLEEP;
                    retVal = E_OK;
                }
                else
                /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    /* Do nothing */
                }
            }
            LinSM_Management_Tab[index].reqMode = LINSM_NO_COM;
        }
        else if( COMM_FULL_COMMUNICATION == mode )
        {
            /* Check if LinSM state is not LINSM_FULL_COM and LinSM substate is not LINSM_WAKEUP */
            if( (LINSM_FULL_COM != LinSM_GetNetworkState(index)) && 
                (LINSM_WAKEUP != LinSM_Management_Tab[index].subState) )
            {
                retVal = LinSM_SetToWakeup(index, network);
                LinSM_Management_Tab[index].retryTimes = LINSM_INIT_ZERO;
            }
            LinSM_Management_Tab[index].reqMode = LINSM_FULL_COM;
        }
        else
        {
            /* If COMM_SILENT_COMMUNICATION is requested,return E_NOT_OK directly without action. */
        }
    }

#if ( LINSM_DEV_ERROR_DETECT == STD_ON )
    if( errId != LINSM_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinSM_Det_ErrorReport(LINSM_REQUEST_COM_MODE, errId);
    }
#endif

    return retVal;
}

/*
********************************************************************************
* Function Name: LinSM_MainFunction
*
* Explanation: Periodic function that runs the timers of different request timeouts.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, LINSM_CODE) LinSM_MainFunction
(
    void
)
{
    uint8 index;
    uint8 networkId;
    uint8 errId = LINSM_E_NO_ERR;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinSM_UNMODIFIED_VAR_NOT_CONST" */
    ComM_ModeType modeReq = COMM_NO_COMMUNICATION;
    uint16 timeOutVal;

    for( index = LINSM_INIT_ZERO; index < LINSM_NETWORK_TOTAL_NUMBER; index++ )
    {
        if( LINSM_START_TIMER == LinSM_Management_Tab[index].timerState )   /* Timeout detection. */
        {
            timeOutVal = LinSM_Channl_Cfg_Tab[index].confirmTimeout / LINSM_MAIN_PROCESSING_PERIOD;
            if( LinSM_Management_Tab[index].timeOutCntr >= timeOutVal )
            {
                /* Timeout counter clear */
                LinSM_Management_Tab[index].timeOutCntr = LINSM_INIT_ZERO;
                /* Request mode is LINSM_FULL_COM,but current state is not LINSM_FULL_COM. */
                if( (LINSM_FULL_COM == LinSM_Management_Tab[index].reqMode) &&
                    (LINSM_FULL_COM != LinSM_Management_Tab[index].curState) )
                {
                    if( LinSM_Management_Tab[index].retryTimes < LINSM_MODE_REQUEST_REPETITION_MAX )
                    {
                        (void)LinSM_SetToWakeup(index, LinSM_Channl_Cfg_Tab[index].networkId);
                        LinSM_Management_Tab[index].retryTimes++;
                    }
                    else
                    {
                        LinSM_Management_Tab[index].timerState = LINSM_CONFIRM_TO;
                        LinSM_Management_Tab[index].reqState = LINSM_NO_REQUEST;
                        LinSM_Management_Tab[index].retryTimes = LINSM_INIT_ZERO;

                        networkId = LinSM_Channl_Cfg_Tab[index].networkId;
                        ComM_BusSM_ModeIndication(networkId, &modeReq);
#if ( LINSM_BSWMENABLED == STD_ON )
                        BswM_LinSM_CurrentState(networkId, LinSM_Management_Tab[index].curState);
#endif
                        errId = LINSM_E_CONFIRMATION_TIMEOUT;
#if ( LINSM_DEV_ERROR_DETECT == STD_ON )
                        /* Report ErrorId to Det. */
                        LinSM_Det_RuntimeErrorReport(LINSM_REQUEST_COM_MODE, errId);
#else
                        LINSM_DUMMY_STATEMENT(errId);
#endif
                    }
                }
                /* Request mode is LINSM_NO_COM,but current state is not LINSM_NO_COM. */
                else if( (LINSM_NO_COM == LinSM_Management_Tab[index].reqMode) &&
                    (LINSM_NO_COM != LinSM_Management_Tab[index].curState) )
                {
                    /* Channel node type is LINSM_CHANNEL_MASTER */
                    if( LINSM_CHANNEL_MASTER == LinSM_Channl_Cfg_Tab[index].nodeChannelType )
                    {
                        /* Set Lin to sleep */
                        (void)LinSM_SetToSleep(index, LinSM_Channl_Cfg_Tab[index].networkId);
                        LinSM_Management_Tab[index].retryTimes = LINSM_INIT_ZERO;
                    }
                    /* Channel node type is LINSM_CHANNEL_SLAVE */
                    /* Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_LinSM_Rule14.3" Polyspace +1 DEFECT:USELESS_IF [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
                    else if( LINSM_CHANNEL_SLAVE == LinSM_Channl_Cfg_Tab[index].nodeChannelType )
                    {
                        /* The substate is LINSM_GOTOSLEEP */
                        LinSM_Management_Tab[index].subState = LINSM_GOTO_SLEEP;
                    }
                    else
                    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    {
                        /* Do nothing */
                    }
                }
                else if( LINSM_REQUEST_SCHEDULE == LinSM_Management_Tab[index].reqState )
                {
                    /* schedule request success */
                    LinSM_Management_Tab[index].timerState = LINSM_CONFIRM_TO;
                    LinSM_Management_Tab[index].reqState = LINSM_NO_REQUEST;
#if ( LINSM_BSWMENABLED == STD_ON )
                    networkId = LinSM_Channl_Cfg_Tab[index].networkId;
                    (void)BswM_LinSM_CurrentSchedule(networkId, LinSM_Management_Tab[index].curSchedule);
#endif
                    errId = LINSM_E_CONFIRMATION_TIMEOUT;
#if ( LINSM_DEV_ERROR_DETECT == STD_ON )
                    /* Report ErrorId to Det. */
                    LinSM_Det_RuntimeErrorReport(LINSM_SCHEDULE_REQUEST, errId);
#else
                    LINSM_DUMMY_STATEMENT(errId);
#endif
                }
                else
                {
                    LinSM_Management_Tab[index].timerState = LINSM_CONFIRM_TO;
                    LinSM_Management_Tab[index].reqState = LINSM_NO_REQUEST;
                    LinSM_Management_Tab[index].retryTimes = LINSM_INIT_ZERO;
                }
            }
            else
            {
                LinSM_Management_Tab[index].timeOutCntr++;  /* Waiting for confirmation result. */
            }
        }
        else
        {
            /* If request mode is not equal current state, the confirmation timer is started */
            if( LinSM_Management_Tab[index].reqMode != LinSM_GetNetworkState(index) )
            {
                /* Set timer state to LINSM_START_TIMER. */
                LinSM_Management_Tab[index].timerState = LINSM_START_TIMER;
                /* Set time out counter to timeout. */
                timeOutVal = LinSM_Channl_Cfg_Tab[index].confirmTimeout / LINSM_MAIN_PROCESSING_PERIOD;
                LinSM_Management_Tab[index].timeOutCntr = timeOutVal;
            }
        }

        if( LINSM_CHANNEL_MASTER == LinSM_Channl_Cfg_Tab[index].nodeChannelType )
        {
            if( LINSM_REQUEST_INVALID == LinSM_Management_Tab[index].reqState )
            {
#if ( LINSM_BSWMENABLED == STD_ON )
                networkId = LinSM_Channl_Cfg_Tab[index].networkId;
                (void)BswM_LinSM_CurrentSchedule(networkId, LinSM_Management_Tab[index].curSchedule);
#endif
                LinSM_Management_Tab[index].reqState = LINSM_NO_REQUEST;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: LinSM_GotoSleepConfirmation
*
* Explanation: The LinIf will call this callback when the go to sleep command is
*              sent successfully or not sent successfully on the network.(Synchronous)
*
* param: network: Identification of the LIN channel.
*        success: True if goto sleep was successfully sent, false otherwise.
*
* retval: None
********************************************************************************
*/
FUNC(void, LINSM_CODE) LinSM_GotoSleepConfirmation
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    NetworkHandleType network,
    boolean success
)
{
    uint8 chkRslt = LINSM_E_NO_ERR;
    uint8 index = LINSM_INIT_ZERO;
    uint8 networkId;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinSM_UNMODIFIED_VAR_NOT_CONST" */
    ComM_ModeType modeReq = COMM_NO_COMMUNICATION;
#if( STD_ON == LINIF_TRCV_DRIVER_SUPPORTED )
        LinTrcv_TrcvModeType TransceiverMode;
#endif

    LINSM_DUMMY_STATEMENT(success);         /* Regardless of the "success" parameter. */
    if( (boolean)FALSE == LinSM_ChkInitialized() )  /* Check if initialization is completed. */
    {
        chkRslt = LINSM_E_UNINIT;
    }
    /* Check the network range,confirm the network channel. */
    else if( (boolean)FALSE == LinSM_ChkNetwork(network, &index) )
    {
        chkRslt = LINSM_E_NONEXISTENT_NETWORK;
    }
    else
    {
        /* Timeout. */
        if( LINSM_CONFIRM_TO == LinSM_Management_Tab[index].timerState )
        {
            LinSM_StopConfirmTimer(index);
        }
        else
        {
            /* Enter critical area. */
            LinSM_EnterCritical();
            /* The current state/substate is LINSM_FULL_COM/LINSM_GOTOSLEEP,
               the LinSM shall set the state to LINSM_NO_COM, regardless of the "success" parameter. */
            if( (LINSM_FULL_COM == LinSM_Management_Tab[index].curState)
                && (LINSM_GOTO_SLEEP == LinSM_Management_Tab[index].subState) )
            {
                LinSM_Management_Tab[index].curState = LINSM_NO_COM;
                LinSM_Management_Tab[index].subState = LINSM_NO_STATE;
                LinSM_Management_Tab[index].reqState = LINSM_NO_REQUEST;
                LinSM_Management_Tab[index].curSchedule = LinSM_Channl_Cfg_Tab[index].scheduleStartIndex;
                LinSM_StopConfirmTimer(index);
                /* Leave critical area. */
                LinSM_LeaveCritical();
#if( STD_ON == LINIF_TRCV_DRIVER_SUPPORTED )
                /* When entering LINSM_NO_COM the transceiver shall be set to STANDBY
                if LinSMTransceiverPassiveMode is true and SLEEP otherwise by using the LinIf_SetTrcvMode. */
                if( (boolean)STD_ON == LinSM_Channl_Cfg_Tab[index].transPassiveMode )
                {
                    TransceiverMode = LINTRCV_TRCV_MODE_STANDBY;
                }
                else
                {
                    TransceiverMode = LINTRCV_TRCV_MODE_SLEEP;
                }
                (void)LinIf_SetTrcvMode(network, TransceiverMode);
#endif
                networkId = LinSM_Channl_Cfg_Tab[index].networkId;
                ComM_BusSM_ModeIndication(networkId, &modeReq);
#if( LINSM_BSWMENABLED == STD_ON )
                BswM_LinSM_CurrentState(networkId, LinSM_Management_Tab[index].curState);
#endif
            }
            else
            {
                /* Leave critical area. */
                LinSM_LeaveCritical();
            }
        }
    }

#if( LINSM_DEV_ERROR_DETECT == STD_ON )
    if( chkRslt != LINSM_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinSM_Det_ErrorReport(LINSM_GOTO_SLEEP_CONFIRMATION, chkRslt);
    }
#else
    LINSM_DUMMY_STATEMENT(chkRslt);
#endif
}

/*
********************************************************************************
* Function Name: LinSM_WakeupConfirmation
*
* Explanation: The LinIf will call this callback when the wake up signal command
*              is sent not successfully/successfully on the network.(Synchronous)
*
* param: network: Identification of the LIN channel.
*        success: True if wakeup was successfully sent, false otherwise.
*
* retval: None
********************************************************************************
*/
FUNC(void, LINSM_CODE) LinSM_WakeupConfirmation
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    NetworkHandleType network,
    boolean success
)
{
    uint8 chkRslt = LINSM_E_NO_ERR;
    uint8 index = LINSM_INIT_ZERO;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinSM_UNMODIFIED_VAR_NOT_CONST" */
    ComM_ModeType modeReq = COMM_FULL_COMMUNICATION;
    uint8 networkId;

    /* Check if initialization is completed. */
    if( (boolean)FALSE == LinSM_ChkInitialized() )
    {
        chkRslt = LINSM_E_UNINIT;
    }
    /* Check the network range,confirm the network channel. */
    else if( (boolean)FALSE == LinSM_ChkNetwork(network, &index) )
    {
        chkRslt = LINSM_E_NONEXISTENT_NETWORK;
    }
    else
    {
        /* Timeout. */
        if( LINSM_CONFIRM_TO == LinSM_Management_Tab[index].timerState )
        {
            LinSM_StopConfirmTimer(index);
        }
        else
        {
            if( (boolean)TRUE == success ) /* If wakeup was successfully sent. */
            {
                /* Enter critical area. */
                LinSM_EnterCritical();
                LinSM_Management_Tab[index].curState = LINSM_FULL_COM;
                LinSM_Management_Tab[index].subState = LINSM_RUN_COMMUNICATION;
                LinSM_Management_Tab[index].reqState = LINSM_NO_REQUEST;
                LinSM_StopConfirmTimer(index);
                /* Leave critical area. */
                LinSM_LeaveCritical();
                networkId = LinSM_Channl_Cfg_Tab[index].networkId;

                ComM_BusSM_ModeIndication(networkId, &modeReq);
#if ( LINSM_BSWMENABLED == STD_ON )
                BswM_LinSM_CurrentState(networkId, LinSM_Management_Tab[index].curState);
#endif
            }
        }
    }

#if ( LINSM_DEV_ERROR_DETECT == STD_ON )
    if( chkRslt != LINSM_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinSM_Det_ErrorReport(LINSM_WAKEUP_CONFIRMATION, chkRslt);
    }
#else
    LINSM_DUMMY_STATEMENT(chkRslt);
#endif
}

#if( LINSM_SLAVE_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: LinSM_GotoSleepIndication
*
* Explanation: The LinIf will call this callback when the go to sleep command is 
*              received on the network or a bus idle timeout occurs.Only applicable 
*              for LIN slave nodes.
*
* param: channel: Identification of the LIN 
*
* retval: None
********************************************************************************
*/
FUNC(void, LINSM_CODE) LinSM_GotoSleepIndication
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    NetworkHandleType Channel
)
{
    uint8 chkRslt = LINSM_E_NO_ERR;
    uint8 index = LINSM_INIT_ZERO;
    uint8 networkId;

    /* Check if initialization is completed. */
    if( (boolean)FALSE == LinSM_ChkInitialized() )
    {
        chkRslt = LINSM_E_UNINIT;
    }
    /* Check the network range,confirm the network channel. */
    else if( (boolean)FALSE == LinSM_ChkNetwork(Channel, &index) )
    {
        chkRslt = LINSM_E_NONEXISTENT_NETWORK;
    }
    
    else if( LINSM_CHANNEL_SLAVE != LinSM_Channl_Cfg_Tab[index].nodeChannelType )
    {
        /* Do nothing */
    }
    else
    {
        if( LINSM_FULL_COM == LinSM_Management_Tab[index].curState )
        {
            networkId = LinSM_Channl_Cfg_Tab[index].networkId;
            if( (E_OK == LinIf_GotoSleep(networkId))
                &&(LINSM_NO_COM == LinSM_Management_Tab[index].reqMode) )
            {
                /* If the LinIf_GotoSleep is successfully called and no com is REQUESTED,
                   call ComM_BusSM_BusSleepMode. */
                ComM_BusSM_BusSleepMode(networkId);
            }
            /* If full com is requested, restart the wake up process */
            if( LINSM_FULL_COM == LinSM_Management_Tab[index].reqMode )
            {
                (void)LinSM_SetToWakeup(index, LinSM_Channl_Cfg_Tab[index].networkId);
            }
        }
    }
#if ( LINSM_DEV_ERROR_DETECT == STD_ON )
    if( chkRslt != LINSM_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinSM_Det_ErrorReport(LINSM_GOTO_SLEEP_INDICATION, chkRslt);
    }
#else
    LINSM_DUMMY_STATEMENT(chkRslt);
#endif /* LINSM_DEV_ERROR_DETECT == STD_ON */
}
#endif /* LINSM_SLAVE_SUPPORT == STD_ON */

#define LINSM_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinSM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

