/*
********************************************************************************
*
* File name: LinIf.c
*
* Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJipeng/2020.03.26
* Change: new created.
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: lizhiheng/2020.06.28
* Change: Modify the include file.
* Cause: Update
********************************************************************************
* Version: 1.2
* Author/Date: lizhiheng/2020.06.29
* Change: Modify encoding specification.
* Cause: Update
********************************************************************************
* Version: 1.3
* Author/Date: lizhiheng/2020.06.29
* Change: Optimize code structure.
* Cause: Update
********************************************************************************
* Version: 1.4
* Author/Date: lizhiheng/2020.06.29
* Change: Optimize code structure.
* Cause: Update
********************************************************************************
* Version: 1.5
* Author/Date: lizhiheng/2020.06.30
* Change: LinIf_ScheduleProcessing_SporadicFrame add code precompilation.
* Cause: Update
********************************************************************************
* Version: 1.6
* Author/Date: lizhiheng/2020.06.30
* Change: 1.Modifity LinIf_PduRNotificationPduId value.
*         2.Tab to Spaces.
* Cause: Bugfix
********************************************************************************
* Version: 1.7
* Author/Date: lizhiheng/2020.07.01
* Change: File name error.
* Cause: Bugfix
********************************************************************************
* Version: 3.0
* Author/Date: lizhiheng/2020.07.01
* Change: Update to 3.0.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: lizhiheng/2020.08.25
* Change: Function updates and modifies coding specifications.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: lizhiheng/2020.09.03
* Change: 1.Process of modifying the schedule.
*         2.Modify the processing of callbacks.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: lizhiheng/2020.09.04
* Change: Eliminate compilation warnings.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: lizhiheng/2020.09.22
* Change: Delay processing after adding sleep.
* Cause: Bugfix
********************************************************************************
* Version: 3.5
* Author/Date: lizhiheng/2020.09.25
* Change: In sleep processing, the callback confirmation parameter for non-sleep should be FALSE.
* Cause: Bugfix
********************************************************************************
* Version: 3.6
* Author/Date: lizhiheng/2020.09.26
* Change: 1.Modify the code to AutoSar coding style.
*         2.Add memap inclusion processing.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: LiZH/2020.09.30
* Change: Modify the code comment.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: LiZH/2020.10.09
* Change: Optimized coding specification.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: LiZH/2020.10.15
* Change: 1.Modify QAC warning.
*         2.Modify AutoSar style non-pointer type modification.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: LiZH/2020.10.16
* Change: Clears the initialization of local variables.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: LiZH/2020.10.16
* Change: Modify the LinTp_RxIndication function declaration.
* Cause: Bugfix
********************************************************************************
* Version: 3.12
* Author/Date: LiZH/2020.10.28
* Change: Add channel references to comm.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: LiZH/2020.10.30
* Change: Modify the single frame processing of LinTp.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: LiZH/2020.10.30
* Change: Modify LinIf_Chk_GetTrcvWakeupReason search channel error.
* Cause: Bugfix
********************************************************************************
* Version: 3.15
* Author/Date: LiZH/2020.11.1
* Change: Modify LinIf_ScheduleProcessing_FrameHandling precompiled error.
* Cause: Bugfix
********************************************************************************
* Version: 3.17
* Author/Date: LiZH/2020.11.02
* Change: Modify the name of the SRF frame type.
* Cause: Update
********************************************************************************
* Version: 3.18
* Author/Date: LiZH/2020.11.02
* Change: Modify the mapmap to contain the processing of the initialization variable.
* Cause: Update
********************************************************************************
* Version: 3.19
* Author/Date: LiZH/2020.11.04
* Change:  Modify the incorrectly defined part of the code format.
* Cause: Optimization
********************************************************************************
* Version: 3.20
* Author/Date: LiZH/2020.11.04
* Change: Optimized coding specification.
* Cause: Optimization
********************************************************************************
* Version: 3.21
* Author/Date: LiZH/2020.11.06
* Change: 1. Add wakeup delay time.
*         2. Modifty sleep time process.
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date: LiZH/2020.11.06
* Change: Function declaration error.
* Cause: Bugfix
********************************************************************************
* Version: 3.23
* Author/Date: LiZH/2020.11.10
* Change: Cancel adding Lin_GoToSleep to LinIf_init.
* Cause: Bugfix
********************************************************************************
* Version: 3.24
* Author/Date: LiZH/2020.11.10
* Change: Modifty Lin_GoToSleepInternal in LinIf_init.
* Cause: Bugfix
********************************************************************************
* Version: 3.25
* Author/Date: LiZH/2020.11.10
* Change: Modifty LinIf_CurrentMessageProcessing function  Lin_GetStatus process.
* Cause: Bugfix
********************************************************************************
* Version: 3.26
* Author/Date: LiZH/2020.11.10
* Change: Tab to space.
* Cause: Optimize
********************************************************************************
* Version: 3.27
* Author/Date: LiZH/2020.11.11
* Change: Modifty in the schedule where the last frame was not received.
* Cause: Bugfix
********************************************************************************
* Version: 3.28
* Author/Date: LiZH/2020.11.13
* Change: Fix compilation errors.
* Cause: Bugfix
********************************************************************************
* Version: 3.29
* Author/Date: LiZH/2020.11.13
* Change: Modifty LinTp_Transmit function channel index.
* Cause: Bugfix
********************************************************************************
* Version: 3.30
* Author/Date: LiZH/2020.11.28
* Change: Modifty LinTp_RxIndication_FF initialize valid buffer length.
* Cause: Bugfix
********************************************************************************
* Version: 3.31
* Author/Date: LiZH/2020.12.4
* Change: 1.Add PduR include.
*         2.Clear waring.
* Cause: Optimization
********************************************************************************
* Version: 3.32
* Author/Date: LiZH/2020.12.23
* Change: 1.Modifty PduR_LoRxIndication PduR_LoTxConfirmation used to
*           PduR_LinIfRxIndication PduR_LoTxConfirmation.
*         2.Modifty PduR_LinIf include.
* Cause: Optimization
********************************************************************************
* Version: 3.33
* Author/Date: LiZH/2021.3.2
* Change: 1.Add WakeupSource check in LinIf_Chk_WakeupConfirmation.
* Cause: Bugfix
********************************************************************************
* Version: 3.34
* Author/Date : Li.ZH/2021.8.16
* Change: Modification code specification.
* Cause: Optimize
********************************************************************************
* Version: 3.35
* Author/Date: LiZH/2022.2.10
* Change: MCAL API name compatible.
* Cause: Optimize
********************************************************************************
 Version: 3.36
* Author/Date: ZouST/2022.9.23
* Change: Modification code specification.
* Cause: Optimize
********************************************************************************
 Version: 3.37
* Author/Date: SunHQ/2022.12.9
* Change: 1.Remove the redundant header files.
*         2.Append the missing header files.
*         3.Fixed a bug where the file name case was inconsistent.
* Cause: Bugfix
********************************************************************************
 Version: 3.38
* Author/Date: YuHC/2023.03.31
* Change: 1.Under the function LinIf_MessageProcessing_SleepModeFrame,when a
*           wake-up request is received during processing sleep, no wake-up
*           action is performed without sleep.
*         2.Modify the function LinIf_CheckWakeup to obtain the value of
*           linChannelId.
* Cause: Bugfix
********************************************************************************
 Version: 3.39
* Author/Date: YuHC/2023.05.5
* Change: 1.CCOREDBUG-2812:Modify the second parameter of function
*           LinIf_ScheduleRequestConfirmationUL_Process to ComM channel number.
* Cause: Bugfix
********************************************************************************
 Version: 3.40
* Author/Date: LiXB/2023.06.29
* Change: 1.Fix failure of switching to null schedule:
*                               1)add parameter LinIf_LinIfChannel to function
*                               LinIf_FlushAllSchedules.
*                               2)In function LinIf_ScheduleTableHandler use nullScheTable
*                               to get null schedule table index, to replace the original
*                               macro LINIF_SCHEDULE_NULL.
*         2.Support slave node.
* Cause: Update
********************************************************************************
 Version: 3.40
* Author/Date: LiXB/2023.07.07
* Change: Fix self test related problems, delete redundant function declaration.
*         Due to polyspace and qac code check fix code.
* Cause: Update
********************************************************************************
 Version: 3.41
* Author/Date: LiXB/2023.07.20
* Change: CCOREDBUG-3473: Use parameter index to replace the original parameter 
*         Channel
* Cause: Bugfix
********************************************************************************
 Version: 3.42
* Author/Date: LiXB/2023.08.02
* Change: CCOREDBUG-3529: Delete macro judgement of function
*         LinIf_ScheduleRequestConfirmationUL_Process
*         Use channelRef to call Lin_GoToSleepInternal and call function member
*         of LinIf_LinMultipeDrvInfo in function LinIf_GotoSleep
*         Add operation when txFrameConfirmFlag is true in tx pdu processing
*         in function LinIf_HeaderIndication.
*         CCOREDBUG-3595: Reset response error in function LinIf_TxConfirmation
*         when error is cleared
*         CCOREDBUG-3604: Add judgment of lacking of error signal in function 
*         LinIf_LinErrorIndication
*         Add function LinIf_Det_ReportRuntimeError
* Cause: Bugfix
********************************************************************************
* Version: 3.43
* Author/Date: LiXB/2023.08.15
* Change: CCOREDBUG-3678: Change name of LinIf_ChannelMainFunction 
*         to LinIf_MasterMainFunction,Change name of LinIf_BusIdleMonitor to 
*         LinIf_SlaveMainFunction, Due to self test of restart wakeup process, 
*         when ComM mode is requested.
*         Fix function LinIf_RxIndication, LinIf_WakeupConfirmationUL_Process,
*         LinIf_GotoSleep, LinIf_Wakeup, LinIf_SlaveMainFunction
*         CCOREDBUG-3545: Set the goto sleep process of slave node to mainfunction.
*         CCOREDBUG-3681: Add frame id judgement in error signal clearing process
*         in function LinIf_TxConfirmation.
* Cause: Bugfix
********************************************************************************
* Version: 3.44
* Author/Date: LiXB/2023.08.18
* Change: Fix compile problem
* Cause: Update
********************************************************************************
* Version: 3.45
* Author/Date: LiXB/2023.10.25
* Change: Update version to R21-11
* Cause: Update
********************************************************************************
* Version: 3.46
* Author/Date: ZhangXF/2024.01.21
* Change: 1) Add node configuration service.
*         2) Add LinTp diagnostic requst and response.
* Cause: Update
********************************************************************************
* Version: 3.47
* Author/Date: ZhangXF/2024.01.29
* Change: Deleted LinTp_ChannelConfig.
* Cause: Update
********************************************************************************
* Version: 3.48
* Author/Date: ZhangXF/2024.01.29
* Change: Remove compile warning.
* Cause: Update
********************************************************************************
* Version: 3.49
* Author/Date: ZhangXF/2024.03.13
* Change: CCOREDBUG-4425: Modify control macro and Network of function BswM_LinTp_RequestMode.
*         CCOREDBUG-4423: Make a judgment NULL_PTR on variable LinIf_slaveChannelData.
*         CCOREDBUG-4424: When linTp_RemainingLength equals ZERO in the Slave node 
*         receiving data, PduR_LinTpRxIndication is added.
*         CCOREDBUG-4432: When there are multiple LinTpRxNSdu belonging to different channels,
*         LinTpRxNSdu belonging to the same channel is required to receive. 
*         CCOREDBUG-4448: During the processing of CAN-LIN routing diagnostics, new requests 
*         are received, new requests are processed, and old transmission are ignored.
* Cause: Bugfix
********************************************************************************
* Version: 3.50
* Author/Date: ZhangXF/2024.04.1
* Change: CCOREDBUG-4492: Add a null pointer judgment to the function of LinTp_Nc_RxIndication.
* Cause:  Bugfix
********************************************************************************
* Version: 3.51
* Author/Date: TianG/2024.06.27
* Change: 1. Add a memory-map label to function.
*         2. Fix compile warning.
*         3. Modify copyright.
*         4. Modify the comments format.
*         5. Replace LINTP_RXNSDU_NUM with LINTP_MAXRXNSDU_CNT.
* Cause: Update
********************************************************************************
* Version: 3.52
* Author/Date: TianG/2024.07.10
* Change: Modify the input parameters of Internal/External wakeup delay function.
* Cause: Bugfix
********************************************************************************
* Version: 3.53
* Author/Date: TianG/2024.07.15
* Change: Add response pending frame function.
* Cause: Update
********************************************************************************
* Version: 3.54
* Author/Date: TianG/2024.07.25
* Change: Modify asynchronous transmit of data when sending LINTP data.
* Cause: Bugfix
********************************************************************************
* Version: 3.55
* Author/Date: TianG/2024.08.09
* Change: CCOREDBUG-4518: Each frame sent or received is notified through the pdur,
*         regardless of success or failure.
* Cause: Bugfix
********************************************************************************
* Version: 3.56
* Author/Date: TianG/2024.08.27
* Change: CCOREDBUG-4906: Modify the issue that the schedule cannot be switched 
*         in a diagnostic request.
* Cause: Bugfix
********************************************************************************
* Version: 3.57
* Author/Date: TianG/2024.09.03
* Change: Modified to occasionally send two SRF frames when diagnostic request. 
* Cause: Bugfix
********************************************************************************
* Version: 3.58
* Author/Date: TianG/2024.09.19
* Change: Modify the issue that when CAN diagnosis is routed to Lin, 
*         Lin probability sends error frames. 
* Cause: Bugfix
********************************************************************************
* Version: 3.59
* Author/Date: TianG/2024.10.08
* Change: Modify the error in the judgment of the NULL schedule table 
*         for multi-channel Lin communication. 
* Cause: Bugfix
********************************************************************************
* Version: 3.60
* Author/Date: TianG/2024.10.09
* Change: Remove the judgment conditions of the LIN_RX_NO_RESPONSE and LIN_RX_BUSY 
*         of the Lin state. 
* Cause: Bugfix
********************************************************************************
* Version: 3.61
* Author/Date: TianG/2025.02.05
* Change: 1. Remove the frameMaxDelayCtn clear operation in the LinTp_Transmit function. 
*         2. Add LinIfChannel initialization in LinIf_Chk_SetTrcvMode, LinIf_Chk_GetTrcvMode, 
*            LinIf_Chk_SetTrMode and LinIf_Chk_SetTrcvWakeupMode functions.
*         3. Modify copyright.
* Cause: Bugfix
********************************************************************************
* Version: 3.62
* Author/Date: TianG/2025.02.21
* Change: Add P2Timer clear operation in the LinTp_RxIndication_FF function. 
* Cause: Bugfix
********************************************************************************
* Version: 3.63
* Author/Date: TianG/2025.02.24
* Change: Modify the judgment conditions in the LinTp_Chk_CancelTransmit and 
*         LinIf_Chk_ScheduleRequest function. 
* Cause: Bugfix
********************************************************************************
* Version: 3.64
* Author/Date: TianG/2025.03.24
* Change: Modify the validity of module parameters needs to be checked when Det is off. 
* Cause: Bugfix
********************************************************************************
* Version: 3.65
* Author/Date: TianG/2025.03.25
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.66
* Author/Date: TianG/2025.06.16
* Change: Modify the judgment condition of LinTp_Init_Finish in LinTp_Chk_Shutdown
*         and LinTp_Chk_CancelTransmit. 
* Cause: Update
********************************************************************************
* Version: 3.67
* Author/Date: TianG/2025.06.17
* Change: Modify frameMaxDelayCtn to follow the task cycle calculation and 
*         optimize the sending and receiving process of Lin. 
* Cause: Update
********************************************************************************
* Version: 3.68
* Author/Date: YanCL/2025.06.18
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.69
* Author/Date: YanCL/2025.06.23
* Change: #include "LinIf_MemMap.h" add suppression comments.
* Cause: Update
********************************************************************************
* Version: 3.70
* Author/Date: TianG/2025.07.14
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.71
* Author/Date: TianG/2025.07.16
* Change: Modify the compilation error issue when the LINIF_TP_SUPPORTED macro
* is disabled for the slave node.
* Cause: Bugfix
********************************************************************************
* Version: 3.72
* Author/Date: TianSL/2025.08.18
* Change: Fix the issue where the master node in LIN fails to send the correct 
*         3C sleep request before entering sleep mode.
* Cause: Bugfix
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#define LINIF_DISABLE_MCAL_COMPAT
#include "LinIf.h"
#undef LINIF_DISABLE_MCAL_COMPAT
#include "LinIf_Lcfg.h"
#include "LinIf_Cbk.h"
#include "LinTp.h"
#include "LinTp_Lcfg.h"
#include "LinTp_Cbk.h"
#include "PduR_LinIf.h"

#if( LINIF_SLAVE_SUPPORT != STD_ON )
#include "Lin_LLDriver.h"
#endif

#if( ((LINIF_CHANNEL_WAKEUP_SUPPORT != STD_ON) && (LINIF_TRCV_WAKEUP_SUPPORT != STD_ON)) || (LINIF_SLAVE_SUPPORT != STD_ON) )
#include "cc_printf.h"
#endif

#if( LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_OFF )
#include "Lin.h"
#endif

#if( LINTP_BSWMENABLED == STD_ON )
#include "BswM_LinTp.h"
#endif

#if( LINIF_TP_SUPPORTED == STD_ON )
#include "PduR_LinTp.h"
#endif

#if( LINIF_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
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
#define LINIF_START_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinIf_NonSharedVar" */
static VAR(boolean, LINIF_VAR_INIT) LinIf_Init_Finish = FALSE;    /* LinIf init state. */

#if( LINIF_TP_SUPPORTED == STD_ON )
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinIf_NonSharedVar" */
static VAR(boolean, LINIF_VAR_INIT) LinTp_Init_Finish = FALSE;    /* LinTp init state. */
#endif

#define LINIF_STOP_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
#define LINIF_START_SEC_CONST
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* TABLE OF VALID FRAME IDENTIFIERS. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinIf_NonSharedVar" */
static CONST(uint8, LINIF_CONST) LinIf_Pid_Convert_Table[LINIF_PIDCONVERTTABLE_SIZE] =  /* PRQA S 3218 */ /* NSCA_QAC_LinIf_Rule8.9 */
{
    0x80, 0xC1, 0x42, 0x03, 0xC4, 0x85, 0x06, 0x47,
    0x08, 0x49, 0xCA, 0x8B, 0x4C, 0x0D, 0x8E, 0xCF,
    0x50, 0x11, 0x92, 0xD3, 0x14, 0x55, 0xD6, 0x97,
    0xD8, 0x99, 0x1A, 0x5B, 0x9C, 0xDD, 0x5E, 0x1F,
    0x20, 0x61, 0xE2, 0xA3, 0x64, 0x25, 0xA6, 0xE7,
    0xA8, 0xE9, 0x6A, 0x2B, 0xEC, 0xAD, 0x2E, 0x6F,
    0xF0, 0xB1, 0x32, 0x73, 0xB4, 0xF5, 0x76, 0x37,
    0x78, 0x39, 0xBA, 0xFB, 0x3C, 0x7D, 0xFE, 0xBF
};

#define LINIF_STOP_SEC_CONST
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Local Functions
********************************************************************************
*/
#define LINIF_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
#if( LINIF_DEV_ERROR_DETECT == STD_ON )
static FUNC(void, LINIF_CODE) LinIf_Det_ErrorReport
(
    uint8 ApiId,
    uint8 ErrorId
);
static FUNC(void, LINIF_CODE) LinIf_Det_ReportRuntimeError
(
    uint8 ApiId,
    uint8 ErrorId
);
#endif

static FUNC(boolean, LINIF_CODE) LinIf_ChkInitialized
(
    void
);
static FUNC(Std_ReturnType, LINIF_CODE) LinIf_Chk_Transmit
(
    PduIdType LinTxPduId,
    P2CONST(PduInfoType, AUTOMATIC, LINIF_APPL_CONST) PduInfoPtr
);
static FUNC(uint16, LINIF_CODE) LinIf_Chk_ScheduleRequest
(
    NetworkHandleType Channel,
    LinIf_SchHandleType LinIf_Schedule
);
static FUNC(uint16, LINIF_CODE) LinIf_Chk_GotoSleep
(
    NetworkHandleType Channel
);
static FUNC(uint16, LINIF_CODE) LinIf_Chk_Wakeup
(
    NetworkHandleType Channel
);

#if( LINIF_TRCV_DRIVER_SUPPORTED == STD_ON )
static FUNC(uint16, LINIF_CODE) LinIf_Chk_SetTrcvMode
(
    NetworkHandleType Channel,
    LinTrcv_TrcvModeType TransceiverMode
);
static FUNC(uint16, LINIF_CODE) LinIf_Chk_GetTrcvMode
(
    NetworkHandleType Channel,
    P2VAR(LinTrcv_TrcvModeType, AUTOMATIC, LINIF_APPL_DATA) TransceiverModePtr
);
static FUNC(uint16, LINIF_CODE) LinIf_Chk_GetTrcvWakeupReason
(
    NetworkHandleType Channel,
    P2VAR(LinTrcv_TrcvWakeupReasonType, AUTOMATIC, LINIF_APPL_DATA) TrcvWuReasonPtr
);
static FUNC(uint16, LINIF_CODE) LinIf_Chk_SetTrcvWakeupMode
(
    NetworkHandleType Channel,
    LinTrcv_TrcvWakeupModeType LinTrcvWakeupMode
);
#endif

#if( (LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON) || (LINIF_TRCV_WAKEUP_SUPPORT == STD_ON) )
static FUNC(Std_ReturnType, LINIF_CODE) LinIf_Chk_CheckWakeup
(
    EcuM_WakeupSourceType WakeupSource
);
static FUNC(Std_ReturnType, LINIF_CODE) LinIf_Chk_WakeupConfirmation
(
    EcuM_WakeupSourceType WakeupSource
);
#endif

static FUNC(Std_ReturnType, LINIF_CODE) LinIf_Chk_MainFunction
(
    void
);
static FUNC(void, LINIF_CODE) LinIf_MasterMainFunction
(
    uint8 channelTmp
);
static FUNC(void, LINIF_CODE) LinIf_CurrentMessageProcessing
(
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_ChannelDataPtr,
    uint8 LinIf_LinIfChannel
);
static FUNC(void, LINIF_CODE) LinIf_MainFunctionPostProcessing
(
    uint8 LinIfChannel
);
static FUNC(boolean, LINIF_CODE) LinIf_ScheduleProcessing_UnconditionalFrame
(
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_ChannelDataPtr,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) LinIf_LinPduPtr,
    uint16 LinIf_FrameHandle
);
static FUNC(void, LINIF_CODE) LinIf_MessageProcessing_Unconditional
(
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_ChannelDataPtr,
    uint8 LinIf_LinIfChannel,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_CONST) LinIf_LinSduPtr,
    Lin_StatusType LinIf_LinStatus
);
static FUNC(void, LINIF_CODE) LinIf_MessageProcessing_SleepModeFrame
(
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_ChannelDataPtr,
    uint8 LinIf_LinIfChannel,
    Lin_StatusType LinIf_LinStatus
);
static FUNC(void, LINIF_CODE) LinIf_ScheduleProcessing
(
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_ChannelDataPtr,
    uint8 LinIf_LinIfChannel
);
static FUNC(void, LINIF_CODE) LinIf_FlushAllSchedules
(
    uint8 LinIf_LinIfChannel,
    P2VAR(LinIf_SchedTabDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_SchedTabDataPtr
);
static FUNC(void, LINIF_CODE) LinIf_ScheduleRequestCfr_Process
(
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) channelDataPtrTmp,
    uint8 linIfChannelTmp
);
static FUNC(void, LINIF_CODE) LinIf_MessageProcessing_SRF
(
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_ChannelDataPtr,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_CONST) linSduPtrTmp,
    uint8 LinIf_LinIfChannel,
    Lin_StatusType linStatusTmp
);

#if( LINIF_EVT_FRM_SUPPORTED == STD_ON )
static FUNC(void, LINIF_CODE) LinIf_MessageProcessing_EventTriggeredFrame
(
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_ChannelDataPtr,
    uint8 LinIf_LinIfChannel,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_CONST) LinIf_LinSduPtr,
    Lin_StatusType LinIf_LinStatus
);
#endif

#if( LINIF_SPORADIC_FRM_SUPPORTED == STD_ON )
static FUNC(boolean, LINIF_CODE) LinIf_ScheduleProcessing_SporadicFrame
(
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_ChannelDataPtr,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) LinIf_LinPduPtr,
    P2VAR(uint16, AUTOMATIC, LINIF_APPL_DATA) LinIf_NewFrameHandlePtr
);
#endif

#if( LINIF_TP_SUPPORTED == STD_ON )
static FUNC(Std_ReturnType, LINIF_CODE) LinTp_Chk_Shutdown
(
    void
);
static FUNC(Std_ReturnType, LINIF_CODE) LinTp_Chk_CancelTransmit
(
    PduIdType LinTpTxSduId
);
static FUNC(Std_ReturnType, LINIF_CODE) LinTp_Chk_ChangeParameter
(
    PduIdType id,
    TPParameterType parameter,
    uint16 value
);
static FUNC(Std_ReturnType, LINIF_CODE) LinTp_Chk_CancelReceive
(
    PduIdType id
);
static FUNC(void, LINIF_CODE) LinTp_RxIndication
(
    uint8 LinIf_LinIfChannel,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_CONST) LinTp_LinSduPtr
);
static FUNC(void, LINIF_CODE) LinTp_RxIndication_SF
(
    uint8 LinIfChannel,
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_CONST) LinTp_LinSduPtr
);
static FUNC(void, LINIF_CODE) LinTp_RxIndication_FF
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_CONST) LinTp_LinSduPtr
);
static FUNC(void, LINIF_CODE) LinTp_RxIndication_CF
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_CONST) LinTp_LinSduPtr
);
static FUNC(void, LINIF_CODE) LinTp_RxDataBufferHandling
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_CONST) LinTp_LinSduPtr
);
static FUNC(void, LINIF_CODE) LinTp_RxDataBufferHandling_StartOfReception
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr
);
static FUNC(void, LINIF_CODE) LinTp_RxDataBufferHandling_CopyRxData
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr
);
static FUNC(void, LINIF_CODE) LinTp_RxCloseConnection
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr
);
static FUNC(Std_ReturnType, LINIF_CODE) LinTp_TxDataRequest
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr
);
static FUNC(void, LINIF_CODE) LinTp_TxMessageProcessing
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    uint8 Channel,
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr,
    Lin_StatusType LinTp_LinStatus
);
static FUNC(void, LINIF_CODE) LinTp_TxCloseConnection
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr
);
static FUNC(boolean, LINIF_CODE) LinTp_TxScheduleProcessing
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr,
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinTp_IfChannelDataPtr,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) LinTp_LinPduPtr
);
static FUNC(void, LINIF_CODE) LinTp_CloseActiveConnection
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr
);
static FUNC(Std_ReturnType, LINIF_CODE) LinIf_Chk_TpTransmit
(
    PduIdType LinTpTxSduId,
    P2CONST(PduInfoType, AUTOMATIC, LINIF_APPL_CONST) pduInfoPtr
);
#endif

static FUNC(void, LINIF_CODE) LinIf_GoToSleepConfirmationUL_Process
(
    uint8 LinIf_LinIfChannel,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType channel,
    boolean success
);
static FUNC(void, LINIF_CODE) LinIf_ScheduleRequestConfirmationUL_Process
(
    uint8 LinIf_LinIfChannel,
    NetworkHandleType channel,
    LinIf_SchHandleType schedule
);
static FUNC(void, LINIF_CODE) LinIf_WakeupConfirmationUL_Process
(
    uint8 LinIf_Channel,
    NetworkHandleType ComMChannel,
    boolean Success
);
static FUNC(Std_ReturnType, LINIF_CODE) LinIf_TxTriggerTransmitUL_Process
(
    uint16 FrameCfgIdx,
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, LINIF_APPL_DATA) PduInfoPtr
);

#if( LINIF_CANCEL_TRANSMIT_SUPPORTED == STD_ON )
static FUNC(Std_ReturnType, LINIF_CODE) LinIf_Chk_CancelTransmit
(
    PduIdType LinTxPduId
);
#endif

static FUNC(boolean, LINIF_CODE) LinIf_ScheduleProcessing_FrameHandling
(
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_ChannelDataPtr,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) LinIf_LinPduPtr,
    P2VAR(uint16, AUTOMATIC, LINIF_APPL_DATA) LinIf_FrameHandlePtr
#if( LINIF_TP_SUPPORTED == STD_ON )
    ,P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr
#endif
);

#if( LINIF_SLAVE_SUPPORT == STD_ON )
static FUNC(void, LINIF_CODE) LinIf_GotoSleepIndicationUL_Process
(
    uint8 LinIfChannel,
    NetworkHandleType ComMChannel
);
#endif

static FUNC(void, LINIF_CODE) LinIf_TxConfirmationUL_Process
(
    uint16 LinIf_FrameHandle,
    PduIdType TxPduId,
    Std_ReturnType Result
);
static FUNC(void, LINIF_CODE) LinIf_RxIndicationUL_Process
(
    uint16 LinIf_FrameHandle,
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, LINIF_APPL_DATA) PduInfoPtr
);
#if( LINIF_TP_SUPPORTED == STD_ON )
static FUNC(void, LINIF_CODE) LinTp_DataBuffer_Polling
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr
);
#endif  /* LINIF_TP_SUPPORTED == STD_ON */

#if( LINIF_SLAVE_SUPPORT == STD_ON )
static FUNC(void, LINIF_CODE) LinIf_SlaveMainFunction
(
    uint8 LinIfChannel
);
static FUNC(boolean, LINIF_CODE) LinIf_EvaluatePID
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel,
    P2VAR(Lin_FrameResponseType, AUTOMATIC, LINIF_APPL_DATA) PduDirection,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    uint8 PId,
    P2VAR(uint16, AUTOMATIC, LINIF_APPL_DATA) FrameCfgIdx
);
static FUNC(void, LINIF_CODE) LinIf_SetPduPtrValues
(
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_ChannelDataPtr,
    PduInfoType PduInfo,
    uint16 FrameCfgIdx,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_VAR) PduPtr
);
#if( LINIF_TP_SUPPORTED == STD_ON )
static FUNC(boolean, LINIF_CODE) LinTp_SlaveRxIndication_SF
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_CONST) LinTp_LinSduPtr

);
static FUNC(boolean, LINIF_CODE) LinTp_SlaveRxIndication_FF
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_CONST) LinTp_LinSduPtr

);
#endif  /* LINIF_TP_SUPPORTED == STD_ON */
#if( LINTP_NC_SUPPORTED == STD_ON )
static FUNC(boolean, LINIF_CODE) LinTp_Nc_CheckSupplierIDAndFunctionID
(
    NetworkHandleType Channel,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR) Lin_SduPtr
);
static FUNC(void, LINIF_CODE) LinTp_Nc_RxIndication_ReadByIdentifier
(
    NetworkHandleType Channel,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR) Lin_SduPtr,
    P2CONST(LinIf_SlaveChannel_Nc_ConfigType, AUTOMATIC, LINIF_APPL_VAR) LinIf_SlaveChannelData
);
static FUNC(LinIf_Nc_RetType, LINIF_CODE) LinTp_Nc_RxIndication
(
    NetworkHandleType Channel,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR) Lin_SduPtr
);
#endif
#if( LINIF_TP_SUPPORTED == STD_ON )
static FUNC(void, LINIF_CODE) LinTp_SlaveRxIndication
(
    NetworkHandleType LinIf_LinIfChannel,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR) LinTp_LinSduPtr
);
#endif  /* LINIF_TP_SUPPORTED == STD_ON */
static FUNC(void, LINIF_CODE) LinIf_SlaveRxindication_DiagReq
(
    NetworkHandleType Channel,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR) Lin_SduPtr
);
#if( LINIF_TP_SUPPORTED == STD_ON )
static FUNC(boolean, LINIF_CODE) LinTp_SlaveTxHeaderIndication
(
    NetworkHandleType Channel,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR) Lin_SduPtr
);
#endif  /* LINIF_TP_SUPPORTED == STD_ON */
static FUNC(Std_ReturnType, LINIF_CODE) LinIf_HeaderIndication_DiagTx
(
    NetworkHandleType Channel,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_VAR) PduPtr,
    P2CONST(LinIf_SlaveChannel_Nc_ConfigType, AUTOMATIC, LINIF_APPL_VAR) SlaveChannelDataPtr,
    uint16 frameCfgIdx
);
#if( LINIF_TP_SUPPORTED == STD_ON )
static FUNC(void, LINIF_CODE) LinTp_SlaveTxConfirmation
(
    NetworkHandleType Channel
);
#endif  /* LINIF_TP_SUPPORTED == STD_ON */
#endif /* LINIF_SLAVE_SUPPORT == STD_ON */
#define LINIF_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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

#define LINIF_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if( LINIF_DEV_ERROR_DETECT == STD_ON )
/*
********************************************************************************
* Function Name: LinIf_Det_ErrorReport
*
* Explanation: Function to report Error to Det.
*
* param: ApiId:Unique Api ID of LinIf service.
*        ErrorId: Det Error ID of LinIf.
*
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_Det_ErrorReport
(
    uint8 ApiId,
    uint8 ErrorId
)
{
    /* Report Error to Det. */
    (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID, ApiId, ErrorId);
}

/*
********************************************************************************
* Function Name: LinIf_Det_ReportRuntimeError
*
* Explanation: Function to report run time Error to Det.
*
* param: ApiId:Unique Api ID of LinIf service.
*        ErrorId: Det Error ID of LinIf.
*
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_Det_ReportRuntimeError
(
    uint8 ApiId,
    uint8 ErrorId
)
{
    /* Report Runtime Error to Det. */
    (void)Det_ReportRuntimeError(LINIF_MODULE_ID, LINIF_INSTANCE_ID, ApiId, ErrorId);
}

#endif

/*
********************************************************************************
* Function Name: LinIf_ChkInitialized
*
* Explanation: Check init state.
*
* param: None
*
* retval: TRUE: Already initialized.
*         FALSE: Uninitialized.
********************************************************************************
*/
static FUNC(boolean, LINIF_CODE) LinIf_ChkInitialized(void)
{
    boolean flag = FALSE;
    if( (boolean)TRUE == LinIf_Init_Finish )
    {
        flag = TRUE;
    }
    return flag;
}

/*
********************************************************************************
* Function Name: LinIf_Chk_Transmit
*
* Explanation: Ckeck LinIf_Transmit parameter.
*
* param: LinTxPduId: Upper layer identification of the LIN frame to be transmitted.
*        PduInfoPtr: Pointer to a structure with frame related data.
*
* retval: chkRslt: Cause of error.
********************************************************************************
*/
static FUNC(Std_ReturnType, LINIF_CODE) LinIf_Chk_Transmit
(
    PduIdType LinTxPduId,
    P2CONST(PduInfoType, AUTOMATIC, LINIF_APPL_CONST) PduInfoPtr
)
{
    Std_ReturnType chkRslt = LINIF_E_NO_ERR;

    if( (boolean)FALSE == LinIf_ChkInitialized() ) /* Initialization not completed. */
    {
        chkRslt = LINIF_E_UNINIT;
    }
    else if( LinTxPduId >= LINIF_UNCONDITIONAL_FRM_NUMBER ) /* Invalid PduID. */
    {
        chkRslt = LINIF_E_PARAMETER;
    }
    else if( NULL_PTR == PduInfoPtr )   /* Null pointer parameter. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        chkRslt = LINIF_E_PARAM_POINTER;
    }
    else
    {
        /* Do nothing. */
    }

    return chkRslt;
}

#if( LINIF_TP_SUPPORTED == STD_ON )
/*
********************************************************************************
* Function Name: LinIf_Chk_TpTransmit
*
* Explanation: Ckeck LinIf_Transmit parameter.
*
* param: LinTpTxSduId: This parameter contains the unique identifier of the N-SDU
*                      (TP message) to be transmitted.
*        LinTpTxInfoPtr: A pointer to a structure with N-SDU related data.
* retval: chkRslt: Cause of error.
********************************************************************************
*/
static FUNC(Std_ReturnType, LINIF_CODE) LinIf_Chk_TpTransmit
(
    PduIdType LinTpTxSduId,
    P2CONST(PduInfoType, AUTOMATIC, LINIF_APPL_CONST) pduInfoPtr
)
{
    Std_ReturnType chkRslt = LINIF_E_NO_ERR;

    if( ((boolean)FALSE == LinIf_ChkInitialized()) ||
        ((boolean)FALSE == LinTp_Init_Finish) ) /* Initialization not completed. */
    {
        chkRslt = LINIF_E_UNINIT;
    }
    else if( LinTpTxSduId >= LINTP_MAXTXNSDU_CNT )  /* Invalid PduID. */
    {
        chkRslt = LINIF_E_PARAMETER;
    }
    else if( NULL_PTR == pduInfoPtr )   /* Null pointer parameter. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        chkRslt = LINIF_E_PARAM_POINTER;
    }
    else
    {
        /* Do nothing. */
    }

    return chkRslt;
}

/*
********************************************************************************
* Function Name: LinTp_Chk_Shutdown
*
* Explanation: Ckeck LinTp_Shutdown parameter.
*
* param: None.
*
* retval: LINIF_E_NO_ERR: Already initialized.
*         LINIF_E_UNINIT: Uninitialized.
********************************************************************************
*/
static FUNC(Std_ReturnType, LINIF_CODE) LinTp_Chk_Shutdown(void)
{
    Std_ReturnType chkRslt = LINIF_E_NO_ERR;

    if( (LinIf_Init_Finish != LINIF_INIT) || (LinTp_Init_Finish != TRUE))
    {
        chkRslt = LINIF_E_UNINIT;
    }

    return chkRslt;
}

/*
********************************************************************************
* Function Name: LinTp_Chk_CancelTransmit
*
* Explanation: Ckeck LinTp_Chk_CancelTransmit parameter.
*
* param: LinTpTxSduId: This parameter contains the Lin TP instance unique identifier
*                      of the Lin N-SDU which transfer has to be cancelled.
* retval: chkRslt: Cause of error.
********************************************************************************
*/
static FUNC(Std_ReturnType, LINIF_CODE) LinTp_Chk_CancelTransmit
(
    PduIdType LinTpTxSduId
)
{
    Std_ReturnType chkRslt = LINIF_E_NO_ERR;

    if( (LinIf_Init_Finish != LINIF_INIT) || (LinTp_Init_Finish != TRUE) )
    {
        chkRslt = LINIF_E_UNINIT;
    }
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    else if( LinTpTxSduId >= LINTP_MAXTXNSDU_CNT )
    {
        chkRslt = LINIF_E_PARAMETER;
    }
    else
    {
        /* Do nothing. */
    }

    return chkRslt;
}

/*
********************************************************************************
* Function Name: LinTp_Chk_ChangeParameter
*
* Explanation: Ckeck LinTp_ChangeParameter parameter.
*
* param: id: Identifier of the received N-SDU on which the reception parameter has to be changed.
*        parameter: The selected parameter that the request shall change (STmin).
*        value: The new value of the parameter.
*
* retval: chkRslt: Cause of error.
********************************************************************************
*/
static FUNC(Std_ReturnType, LINIF_CODE) LinTp_Chk_ChangeParameter
(
    PduIdType id,
    TPParameterType parameter,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    uint16 value
)
{
    uint8 chkRslt = LINIF_E_NO_ERR;

    LINIF_DUMMY_STATEMENT(id);
    LINIF_DUMMY_STATEMENT(parameter);
    LINIF_DUMMY_STATEMENT(value);

    if( ((boolean)FALSE == LinIf_ChkInitialized()) /* Initialization not completed. */
         || ((boolean)FALSE == LinTp_Init_Finish) )
    {
        chkRslt = LINIF_E_UNINIT;
    }
    else if( id >= LINTP_MAXRXNSDU_CNT ) /* SWS_LinIf_00578 */
    {
        chkRslt = LINIF_E_PARAMETER;
    }
    /* Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_LinIf_Rule14.3" */
    else if( parameter > TP_BC ) /* SWS_LinIf_00578 */
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        chkRslt = LINIF_E_PARAMETER;
    }
    else
    {
        /* Do nothing. */
    }

    return chkRslt;
}

/*
********************************************************************************
* Function Name: LinTp_Chk_CancelReceive
*
* Explanation: Ckeck LinTp_CancelReceive parameter.
*
* param: id: This parameter contains the Lin TP instance unique identifier of the
*            Lin N-SDU reception of which has to be cancelled.
*
* retval: chkRslt: Cause of error.
********************************************************************************
*/
static FUNC(Std_ReturnType, LINIF_CODE) LinTp_Chk_CancelReceive
(
    PduIdType id
)
{
    uint8 chkRslt = LINIF_E_NO_ERR;

    LINIF_DUMMY_STATEMENT(id);

    if( ((boolean)FALSE == LinIf_ChkInitialized())   /* Initialization not completed. */
         && ((boolean)FALSE == LinTp_Init_Finish) )
    {
        chkRslt = LINIF_E_UNINIT;
    }
    else if( id >= LINTP_MAXRXNSDU_CNT ) /* SWS_LinIf_00627 */
    {
        chkRslt = LINIF_E_PARAMETER;
    }
    else
    {
        /* Do nothing. */
    }

    return chkRslt;
}
#endif

/*
********************************************************************************
* Function Name: LinIf_Chk_MainFunction
*
* Explanation: Ckeck LinIf_MainFunction parameter.
*
* param: None
*
* retval: chkRslt: LINIF_E_NO_ERR
*                  LINIF_E_UNINIT
********************************************************************************
*/
static FUNC(Std_ReturnType, LINIF_CODE) LinIf_Chk_MainFunction(void)
{
    uint8 chkRslt = LINIF_E_NO_ERR;

    if( ((boolean)FALSE == LinIf_ChkInitialized())   /* Initialization not completed. */
#if( LINIF_TP_SUPPORTED == STD_ON )
        && ((boolean)FALSE == LinTp_Init_Finish)
#endif
    )
    {
        chkRslt = LINIF_E_UNINIT;
    }

    return chkRslt;
}

/*
********************************************************************************
* Function Name: LinIf_ChkChannel
*
* Explanation: Ckeck LinIf channel parameter.
*
* param: Channel: Channel index.
*        Schedule: Identification of the new schedule to be set.
*
* retval: flag: TRUE: Search sucess.
*               FALSE: Search faild.
********************************************************************************
*/
static FUNC(boolean, LINIF_CODE) LinIf_ChkChannel
(
    NetworkHandleType ComMNetWork,
    NetworkHandleType* Channel
)
{
    NetworkHandleType index;
    boolean flag = FALSE;
    for( index = LINIF_INIT_ZERO; index < LINIF_CHANNEL_NUMTOTAL; index++ )
    {
        if( ComMNetWork == LinIf_Channl_Cfg_Tab[index].ComMChannelRef )
        {
            *Channel = index;
            flag = TRUE;
            break;
        }
    }

    return flag;
}

/*
********************************************************************************
* Function Name: LinIf_Chk_ScheduleRequest
*
* Explanation: Ckeck LinIf_ScheduleRequest parameter.
*
* param: Channel: Channel index.
*        LinIf_Schedule: Identification of the new schedule to be set.
*
* retval: rtnValue: Low 8 bit Cause of error, High 8 bit channel index.
********************************************************************************
*/
static FUNC(uint16, LINIF_CODE) LinIf_Chk_ScheduleRequest
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel,
    LinIf_SchHandleType LinIf_Schedule
)
{
    uint8 LinIfChannel = LINIF_INIT_ZERO;
    uint8 chkRslt = LINIF_E_NO_ERR;
    uint16 rtnValue;

    if( (boolean)FALSE == LinIf_ChkInitialized() )      /* Initialization not completed. */
    {
        chkRslt = LINIF_E_UNINIT;
    }
    else if( (boolean)FALSE == LinIf_ChkChannel(Channel, &LinIfChannel) )
    {
        chkRslt = LINIF_E_NONEXISTENT_CHANNEL;
    }
    /* Check if channel state is operational. */
    else if( LINIF_CHANNEL_SLEEP == LinIf_ChannelData[LinIfChannel].channelState )
    {
        chkRslt = LINIF_E_SCHEDULE_REQUEST_ERROR;
    }
    else if( LinIfChannel >= LINIF_CHANNEL_NUMTOTAL )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        chkRslt = LINIF_E_NONEXISTENT_CHANNEL;
    }
    else if( LinIf_Schedule >= LINIF_SCHEDULETABLE_NUMBER )
    {
        chkRslt = LINIF_E_PARAMETER;
    }
    else
    {
        /* Do nothing. */
    }

    rtnValue = ((uint16)LinIfChannel << LINIF_SHIFT_8BIT);
    rtnValue = ((uint16)chkRslt & LINIF_LOW_BYTE) | rtnValue;

    return rtnValue;
}

/*
********************************************************************************
* Function Name: LinIf_Chk_GotoSleep
*
* Explanation: Ckeck LinIf_GotoSleep parameter.
*
* param: Channel:Identification of the LIN channel.
*
* retval: rtnValue: Low 8 bit Cause of error, High 8 bit channel index.
********************************************************************************
*/
static FUNC(uint16, LINIF_CODE) LinIf_Chk_GotoSleep
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel
)
{
    uint8 chkRslt = LINIF_E_NO_ERR;
    NetworkHandleType LinIfChannel = LINIF_INIT_ZERO;
    uint16 rtnValue;

    if( (boolean)FALSE == LinIf_ChkInitialized() )  /* Initialization not completed. */
    {
        chkRslt = LINIF_E_UNINIT;
    }
    else if( (boolean)FALSE == LinIf_ChkChannel(Channel, &LinIfChannel) )
    {
        chkRslt = LINIF_E_NONEXISTENT_CHANNEL;
    }
    else if( LinIfChannel >= LINIF_CHANNEL_NUMTOTAL )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        chkRslt = LINIF_E_NONEXISTENT_CHANNEL;
    }
    else
    {
        /* Do nothing. */
    }

    rtnValue = ((uint16)LinIfChannel << LINIF_SHIFT_8BIT);
    rtnValue = ((uint16)chkRslt & LINIF_LOW_BYTE) | rtnValue;

    return rtnValue;
}

/*
********************************************************************************
* Function Name: LinIf_Chk_GotoSleep
*
* Explanation: Ckeck LinIf_Wakeup parameter.
*
* param: Channel:Identification of the LIN channel.
*
* retval: rtnValue: Low 8 bit Cause of error, High 8 bit channel index.
********************************************************************************
*/
static FUNC(uint16, LINIF_CODE) LinIf_Chk_Wakeup
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel
)
{
    uint8 chkRslt = LINIF_E_NO_ERR;
    NetworkHandleType LinIfChannel = LINIF_INIT_ZERO;
    uint16 rtnValue;

    if( (boolean)FALSE == LinIf_ChkInitialized() )  /* Initialization not completed. */
    {
        chkRslt = LINIF_E_UNINIT;
    }
    else if( (boolean)FALSE == LinIf_ChkChannel(Channel, &LinIfChannel) )
    {
        chkRslt = LINIF_E_NONEXISTENT_CHANNEL;
    }
    else if( LinIfChannel >= LINIF_CHANNEL_NUMTOTAL )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        chkRslt = LINIF_E_NONEXISTENT_CHANNEL;
    }
    else
    {
        /* Do nothing. */
    }

    rtnValue = ((uint16)LinIfChannel << LINIF_SHIFT_8BIT);
    rtnValue = ((uint16)chkRslt & LINIF_LOW_BYTE) | rtnValue;

    return rtnValue;
}

#if(LINIF_TRCV_DRIVER_SUPPORTED == STD_ON )
/*
********************************************************************************
* Function Name: LinIf_Chk_SetTrcvMode
*
* Explanation: Ckeck LinIf_SetTrcvMode parameter.
*
* param: Channel: Identification of the LIN channel.
*        TransceiverMode: Requested mode transition.
*
* retval: rtnValue: Low 8 bit Cause of error, High 8 bit channel index.
********************************************************************************
*/
static FUNC(uint16, LINIF_CODE) LinIf_Chk_SetTrcvMode
(
    NetworkHandleType Channel,
    LinTrcv_TrcvModeType TransceiverMode
)
{
    uint8 chkRslt = LINIF_E_NO_ERR;
    NetworkHandleType LinIfChannel = LINIF_CHANNEL_NUMTOTAL;
    uint16 rtnValue;

    if( (boolean)FALSE == LinIf_ChkInitialized() )  /* Initialization not completed. */
    {
        chkRslt = LINIF_E_UNINIT;
    }
    else if( (boolean)FALSE == LinIf_ChkChannel(Channel, &LinIfChannel) )
    {
        chkRslt = LINIF_E_NONEXISTENT_CHANNEL;
    }
    else if( LinIfChannel >= LINIF_CHANNEL_NUMTOTAL )
    {
        chkRslt = LINIF_E_NONEXISTENT_CHANNEL;
    }
    else if( TransceiverMode > LINTRCV_TRCV_MODE_SLEEP )
    {
        chkRslt = LINIF_E_TRCV_INV_MODE;
    }
    else
    {
        /* Do nothing. */
    }

    rtnValue = ((uint16)LinIfChannel << LINIF_SHIFT_8BIT);
    rtnValue = ((uint16)chkRslt & LINIF_LOW_BYTE) | rtnValue;

    return rtnValue;
}

/*
********************************************************************************
* Function Name: LinIf_Chk_GetTrcvMode
*
* Explanation: Ckeck LinIf_GetTrcvMode parameter.
*
* param: Channel: Identification of the LIN channel.
*        TransceiverMode: Requested mode transition.
*
* retval: rtnValue: Low 8 bit Cause of error, High 8 bit channel index.
********************************************************************************
*/
static FUNC(uint16, LINIF_CODE) LinIf_Chk_GetTrcvMode
(
    NetworkHandleType Channel,
    P2VAR(LinTrcv_TrcvModeType, AUTOMATIC, LINIF_APPL_DATA) TransceiverModePtr  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
)
{
    uint8 chkRslt = LINIF_E_NO_ERR;
    NetworkHandleType LinIfChannel = LINIF_CHANNEL_NUMTOTAL;
    uint16 rtnValue;

    if( (boolean)FALSE == LinIf_ChkInitialized() )  /* Initialization not completed. */
    {
        chkRslt = LINIF_E_UNINIT;
    }
    else if( (boolean)FALSE == LinIf_ChkChannel(Channel, &LinIfChannel) )
    {
        chkRslt = LINIF_E_NONEXISTENT_CHANNEL;
    }
    else if( NULL_PTR == TransceiverModePtr )
    {
        chkRslt = LINIF_E_PARAM_POINTER;
    }
    else if( LinIfChannel >= LINIF_CHANNEL_NUMTOTAL )
    {
        chkRslt = LINIF_E_NONEXISTENT_CHANNEL;
    }
    else
    {
        /* Do nothing. */
    }

    rtnValue = ((uint16)LinIfChannel << LINIF_SHIFT_8BIT);
    rtnValue = ((uint16)chkRslt & LINIF_LOW_BYTE) | rtnValue;

    return rtnValue;
}

/*
********************************************************************************
* Function Name: LinIf_Chk_GetTrcvWakeupReason
*
* Explanation: Ckeck LinIf_GetTrcvWakeupReason parameter.
*
* param: Channel: Identification of the LIN channel.
*        TrcvWuReasonPtr: Pointer to a memory location where output value will be stored.
*
* retval: rtnValue: Low 8 bit Cause of error, High 8 bit channel index.
********************************************************************************
*/
static FUNC(uint16, LINIF_CODE) LinIf_Chk_GetTrcvWakeupReason
(
    NetworkHandleType Channel,
    P2VAR(LinTrcv_TrcvWakeupReasonType, AUTOMATIC, LINIF_APPL_DATA) TrcvWuReasonPtr  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
)
{
    uint8 chkRslt = LINIF_E_NO_ERR;
    Std_ReturnType retTrcvMode = E_NOT_OK;
    LinTrcv_TrcvModeType transceiverMode = LINTRCV_TRCV_MODE_SLEEP;
    NetworkHandleType LinIfChannel = LINIF_CHANNEL_NUMTOTAL;
    uint16 rtnValue;

    if( (boolean)FALSE == LinIf_ChkInitialized() ) /* Initialization not completed. */
    {
        chkRslt = LINIF_E_UNINIT;
    }
    else if( (boolean)FALSE == LinIf_ChkChannel(Channel, &LinIfChannel) )
    {
        chkRslt = LINIF_E_NONEXISTENT_CHANNEL;
    }
    else if( NULL_PTR == TrcvWuReasonPtr )
    {
        chkRslt = LINIF_E_PARAM_POINTER;
    }
    else if( LinIfChannel >= LINIF_CHANNEL_NUMTOTAL )
    {
        chkRslt = LINIF_E_NONEXISTENT_CHANNEL;
    }
    else
    {
        retTrcvMode = LinIf_GetTrcvMode(Channel, &transceiverMode);
        if( (retTrcvMode == E_OK) && (transceiverMode != LINTRCV_TRCV_MODE_NORMAL) )
        {
            /* If the current mode is not LINTRCV_TRCV_MODE_NORMAL, report LINIF_E_TRCV_NOT_NORMAL. */
            chkRslt = LINIF_E_TRCV_NOT_NORMAL;
        }
    }

    rtnValue = ((uint16)LinIfChannel << LINIF_SHIFT_8BIT);
    rtnValue = ((uint16)chkRslt & LINIF_LOW_BYTE) | rtnValue;

    return rtnValue;
}

/*
********************************************************************************
* Function Name: LinIf_Chk_SetTrcvWakeupMode
*
* Explanation: Ckeck LinIf_SetTrcvWakeupMode parameter.
*
* param: Channel: Identification of the LIN channel.
*        LinTrcvWakeupMode: Requested transceiver wake up reason.
*
* retval: rtnValue: Low 8 bit Cause of error, High 8 bit channel index.
********************************************************************************
*/
static FUNC(uint16, LINIF_CODE) LinIf_Chk_SetTrcvWakeupMode
(
    NetworkHandleType Channel,
    LinTrcv_TrcvWakeupModeType LinTrcvWakeupMode
)
{
    uint8 chkRslt = LINIF_E_NO_ERR;

    NetworkHandleType LinIfChannel = LINIF_CHANNEL_NUMTOTAL;
    uint16 rtnValue;

    if( (boolean)FALSE == LinIf_ChkInitialized() )  /* Initialization not completed. */
    {
        chkRslt = LINIF_E_UNINIT;
    }
    else if( (boolean)FALSE == LinIf_ChkChannel(Channel, &LinIfChannel) )
    {
        chkRslt = LINIF_E_NONEXISTENT_CHANNEL;
    }
    else if( LinIfChannel >= LINIF_CHANNEL_NUMTOTAL )
    {
        chkRslt = LINIF_E_NONEXISTENT_CHANNEL;
    }
    else if( LinTrcvWakeupMode > LINTRCV_WUMODE_CLEAR )
    {
        chkRslt = LINIF_E_PARAMETER;
    }
    else
    {
        /* Do nothing. */
    }

    rtnValue = ((uint16)LinIfChannel << LINIF_SHIFT_8BIT);
    rtnValue = ((uint16)chkRslt & LINIF_LOW_BYTE) | rtnValue;

    return rtnValue;
}
#endif

#if( LINIF_CANCEL_TRANSMIT_SUPPORTED == STD_ON )
/*
********************************************************************************
* Function Name: LinIf_Chk_CancelTransmit
*
* Explanation: Ckeck LinIf_CancelTransmit parameter.
*
* param: LinTxPduId: Upper layer identification of the LIN frame for which a cancellation
*                    should be done.
* retval: chkRslt: Cause of error.
********************************************************************************
*/
static FUNC(Std_ReturnType, LINIF_CODE) LinIf_Chk_CancelTransmit
(
    PduIdType LinTxPduId
)
{
    uint8 chkRslt = LINIF_E_NO_ERR;

    if( (boolean)FALSE == LinIf_ChkInitialized() )  /* Initialization not completed. */
    {
        chkRslt = LINIF_E_UNINIT;
    }
    else if( LinTxPduId >= LINIF_SCHEDULETABLE_NUMBER )
    {
        chkRslt = LINIF_E_PARAMETER;
    }
    else
    {
        /* Do nothing. */
    }

    return chkRslt;
}
#endif

#if( (LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON) || (LINIF_TRCV_WAKEUP_SUPPORT == STD_ON) )
/*
********************************************************************************
* Function Name: LinIf_Chk_CheckWakeup
*
* Explanation: Ckeck LinIf_CheckWakeup parameter.
*
* param: WakeupSource: Source device, which initiated the wakeup event:
*                      LIN controller or LIN transceiver.
*
* retval: chkRslt: Cause of error.
********************************************************************************
*/
static FUNC(Std_ReturnType, LINIF_CODE) LinIf_Chk_CheckWakeup
(
    EcuM_WakeupSourceType WakeupSource
)
{
    boolean flag = FALSE;
    uint8 chkRslt;
    uint8 channelIdx;

    if( (boolean)FALSE == LinIf_ChkInitialized() ) /* Initialization not completed. */
    {
        chkRslt = LINIF_E_UNINIT;
    }
    else
    {
        for( channelIdx = LINIF_INIT_ZERO; channelIdx < LINIF_CHANNEL_NUMTOTAL; channelIdx++ )
        {
            if( WakeupSource == LinIf_Channel_WakeupSouceInfo[channelIdx] )
            {
                flag = TRUE;
                break;
            }
        }

        if( TRUE != flag )
        {
            chkRslt = LINIF_E_PARAM_WAKEUPSOURCE;
        }
        else
        {
            chkRslt = LINIF_E_NO_ERR;
        }
    }

    return chkRslt;
}

/*
********************************************************************************
* Function Name: LinIf_Chk_WakeupConfirmation
*
* Explanation: Ckeck LinIf_WakeupConfirmation parameter.
*
* param: WakeupSource: Source device, which initiated the wakeup event:
*                      LIN controller or LIN transceiver.
* retval: chkRslt: Cause of error.
********************************************************************************
*/
static FUNC(Std_ReturnType, LINIF_CODE) LinIf_Chk_WakeupConfirmation
(
    EcuM_WakeupSourceType WakeupSource
)
{
    boolean flag = FALSE;
    uint8 chkRslt = LINIF_E_NO_ERR;
    uint8 channelIdx;

    LINIF_DUMMY_STATEMENT(WakeupSource);

    if( (boolean)FALSE == LinIf_ChkInitialized() ) /* Initialization not completed. */
    {
        chkRslt = LINIF_E_UNINIT;
    }
    else
    {
        for( channelIdx = LINIF_INIT_ZERO; channelIdx < LINIF_CHANNEL_NUMTOTAL; channelIdx++ )
        {
            if( WakeupSource == LinIf_Channel_WakeupSouceInfo[channelIdx] )
            {
                flag = TRUE;
                break;
            }
        }

        if( TRUE != flag )
        {
            chkRslt = LINIF_E_PARAM_WAKEUPSOURCE;
        }
        else
        {
            chkRslt = LINIF_E_NO_ERR;
        }
    }

    return chkRslt;
}
#endif

/*
********************************************************************************
* Function Name: LinIf_MasterMainFunction
*
* Explanation: LinIf_MainFunction process.
*
* param: channelTmp: Channel index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_MasterMainFunction
(
    uint8 channelTmp
)
{
    LinIf_ChannelDataType* channelDataPtrTmp = NULL_PTR;

#if( LINIF_TP_SUPPORTED == STD_ON )
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    LinTp_ControlType* tpCtrlTmp = &LinTp_Ctrl.raw[channelTmp];
#endif
    channelDataPtrTmp = &LinIf_ChannelData[channelTmp];

    /* If channel state is operational. */
    if( LINIF_CHANNEL_OPERATIONAL == channelDataPtrTmp->channelState )
    {
        /* Processing of last message. */
        LinIf_CurrentMessageProcessing(channelDataPtrTmp, channelTmp);
        /* Tp timeout observation. */
#if( LINIF_TP_SUPPORTED == STD_ON )
        /* Lin Tp timeout handling. */
        if( tpCtrlTmp->linTp_Timer > LINIF_INIT_ZERO )
        {
            tpCtrlTmp->linTp_Timer--;
            if( LINIF_INIT_ZERO == tpCtrlTmp->linTp_Timer )
            { /* Timeout on running transmission / reception occurred check current state. */
                LinTp_CloseActiveConnection(tpCtrlTmp);
            }
        }
#endif
        /* If wakeup delay timer is active, update it, otherwise call main schedule table processing function. */
        if( LINIF_INIT_ZERO == channelDataPtrTmp->wakeupDelayTimer )
        {
            /* If channel is still in operation state. */
            if( LINIF_CHANNEL_OPERATIONAL == channelDataPtrTmp->channelState )
            {
                /* Normal Message processing. */
                LinIf_ScheduleProcessing(channelDataPtrTmp, channelTmp);
            }
        }
        else
        {
            /* Wait for end of wakeup delay */
            channelDataPtrTmp->wakeupDelayTimer--;
        }
    }
    /* Otherwise if channel state is sleep and an internal goto sleep request is pending. */
    else if( (LINIF_CHANNEL_SLEEP == channelDataPtrTmp->channelState )
             && (LINIF_ONSLRRPMODEFRM_ONREQINT == channelDataPtrTmp->sleepModeFrameHandle ) )
    {
        /* Process one tick of main schedule table processing function for internal sleep transition. */
        LinIf_ScheduleProcessing(channelDataPtrTmp, channelTmp);
    }
    else
    {
        /* Do nothing. */
    }
}

/*
********************************************************************************
* Function Name: LinIf_ScheduleTableHandler_RunOnceFinalization
*
* Explanation: Schedule table runonce mode process.
*
* param: LinIf_SchedTabDataPtr: Schedule table data pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_ScheduleTableHandler_RunOnceFinalization
(
    P2VAR(LinIf_SchedTabDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_SchedTabDataPtr
)
{
    uint16 scheduleTableListIdx;
    scheduleTableListIdx = LinIf_SchedTabDataPtr->currentTable;

    /* If current schedule table is of type run-once and run through. */
    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" */
    if( (LINIF_RUNMODE_RUNONCE == LinIf_ScheduleTableList[scheduleTableListIdx].runMode)
        && (LINIF_INIT_ZERO == LinIf_SchedTabDataPtr->currentSlot) )
    {
        /* Current table is run once and table is all run through. */

        /* Change to to last continuous schedule table and saved resume slot. */
        LinIf_SchedTabDataPtr->currentTable = LinIf_SchedTabDataPtr->previousContinuousTable;

        if( LINIF_CONTINUE_AT_IT_POINT == LinIf_ScheduleTableList[scheduleTableListIdx].resumePosition )
        {
            /* Start from interrupted slot. */
            LinIf_SchedTabDataPtr->currentSlot = LinIf_SchedTabDataPtr->previousContinuousSlot;
        }
        else
        {
            /* Start from beginning slot. */
            LinIf_SchedTabDataPtr->currentSlot = LINIF_INIT_ZERO;
        }

        /* If no schedule request is pending, inform about change to continuous table. */
        if( (uint8)LINIF_SCHEDULE_INVALID == LinIf_SchedTabDataPtr->requestedTable )
        {
            LinIf_SchedTabDataPtr->schedReqConfirmTable = LinIf_SchedTabDataPtr->currentTable;
        }
    }
}

/*
********************************************************************************
* Function Name: LinIf_ScheduleTableHandler_RequestedTableSwitch
*
* Explanation: ScheduleTable requset process.
*
* param: LinIf_SchedTabDataPtr: Schedule table data pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_ScheduleTableHandler_RequestedTableSwitch
(
    P2VAR(LinIf_SchedTabDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_SchedTabDataPtr
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    uint16 scheduleTableListIdx = LINIF_INIT_ZERO;
    uint16 currentIdx;
    uint16 requestIdx;

    currentIdx = LinIf_SchedTabDataPtr->currentTable;
    requestIdx = scheduleTableListIdx + LinIf_SchedTabDataPtr->requestedTable;

    /* If a new table is requested. */
    if( LinIf_SchedTabDataPtr->requestedTable != LINIF_SCHEDULE_INVALID )
    {
        /* If current active table is of type run-continuous. */
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" */
        if( LINIF_RUNMODE_RUNCONTINUOUS == LinIf_ScheduleTableList[currentIdx].runMode )
        {
            /* A normal continuous table is active, switch to requested schedule. */
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" */
            if( LINIF_RUNMODE_RUNONCE == LinIf_ScheduleTableList[requestIdx].runMode )
            {
                /* If requested table is a run-once table, save position of current table. */
                LinIf_SchedTabDataPtr->previousContinuousTable = LinIf_SchedTabDataPtr->currentTable;
                LinIf_SchedTabDataPtr->previousContinuousSlot  = LinIf_SchedTabDataPtr->currentSlot;
            }
#if( LINIF_EVT_FRM_SUPPORTED == STD_ON )
            else if( LINIF_EVTCOLLRESOLVINGSTA_DETCED == LinIf_SchedTabDataPtr->evtCollResolvingState )
            {
                /* If new table is a collision resolving schedule, save position of current table. */
                LinIf_SchedTabDataPtr->previousContinuousTable = LinIf_SchedTabDataPtr->currentTable;
                LinIf_SchedTabDataPtr->previousContinuousSlot = LinIf_SchedTabDataPtr->currentSlot;
                LinIf_SchedTabDataPtr->evtCollResolvingState = LINIF_EVTCOLLRESOLVINGSTA_ONRESOLVING;
            }
#endif
            else
            {
                /* Do nothing. */
            }
            /* Activate new schedule table and slot. */
            LinIf_SchedTabDataPtr->currentTable = LinIf_SchedTabDataPtr->requestedTable;
            LinIf_SchedTabDataPtr->currentSlot  = LINIF_INIT_ZERO;
            /* Schedule table change handled, remove request. */
            LinIf_SchedTabDataPtr->requestedTable = LINIF_SCHEDULE_INVALID;

#if( LINIF_EVT_FRM_SUPPORTED == STD_ON )
            if( LinIf_SchedTabDataPtr->evtCollResolvingState != LINIF_EVTCOLLRESOLVINGSTA_ONRESOLVING )
#endif
            { /* Inform upper layer about schedule table change. */
                LinIf_SchedTabDataPtr->schedReqConfirmTable = LinIf_SchedTabDataPtr->currentTable;
            }
        }
        else
        {
            /* Do nothing. */
        }
    }
    /* Else : currently a run once table is active which is not run through yet so wait until table end. */
}

/*
********************************************************************************
* Function Name: LinIf_ScheduleTableHandler
*
* Explanation: Scheduletable handler.
*
* param: LinIf_FrameMaxDelayPtr: Max delay pointer.
*        LinIf_FrameHandlePtr: Frame index.
*        LinIf_LinIfChannel: Channel idex.
*
* retval: retVal
********************************************************************************
*/
static FUNC(uint8, LINIF_CODE) LinIf_ScheduleTableHandler
(
    P2VAR(uint16, AUTOMATIC, LINIF_APPL_DATA) LinIf_FrameMaxDelayPtr,
    P2VAR(uint16, AUTOMATIC, LINIF_APPL_DATA) LinIf_FrameHandlePtr,
    uint8 LinIf_LinIfChannel
)
{
    uint8 retVal;
    uint8 frameLengthTmp;
    uint8 nullScheTable;
    uint16 schedTabListIdx;
    uint16 slotListIdx;
    uint16 schedRunMode;
    uint16 scheduleTableListIdx;
    uint16 nullSchIdx;
    LinIf_SchedTabDataType* schedTabDataPtrTmp = NULL_PTR;

#if( STD_ON == LINIF_TP_SUPPORTED )
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    LinTp_ControlType* tpCtrlTmp = &LinTp_Ctrl.raw[LinIf_LinIfChannel];
#endif

    schedTabDataPtrTmp = &LinIf_ChannelData[LinIf_LinIfChannel].schedTabData;
    /* For each channel, the first configured schedule table is the NULL schedule. */
    nullSchIdx = LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].ScheduleTableListStartIdxOfChannelCfg;
    nullScheTable = (uint8)LinIf_ScheduleTableListInd[nullSchIdx];

    /* If Null schedule table is active and no request is pending, do nothing and quit. */
    if( (nullScheTable == schedTabDataPtrTmp->currentTable)
        && (LINIF_SCHEDULE_INVALID == schedTabDataPtrTmp->requestedTable) )
    {
        retVal = LINIF_SCHDLHDLRRET_ONNULLSCHEDULE;
    }
    /* Otherwise: */
    else
    {
        /* If current slot not yet finished, decrease delay counter. */
        if( schedTabDataPtrTmp->currentSlotDelay > LINIF_INIT_ZERO )
        {
            schedTabDataPtrTmp->currentSlotDelay--;
        }

        /* Evaluate if handling of next schedule entry can be started: */
        retVal = LINIF_SCHDLHDLRRET_NONEWMESSAGE;
        if( LINIF_SENDFRAME_IDLE == LinIf_ChannelData[LinIf_LinIfChannel].LinIf_SendFrameStatus )
        {
#if( LINIF_TP_SUPPORTED == STD_ON )
            /* If slot delay has elapsed and no change the schedule table for diag, next slot can be started. */
            if( (tpCtrlTmp->linTp_PortNotifity == (uint8)LINTP_PORTNOTIFITY_IDLE) && 
                (LINIF_INIT_ZERO == schedTabDataPtrTmp->currentSlotDelay) )
#else
            /* If slot delay has elapsed, next slot can be started in any case. */
            if( LINIF_INIT_ZERO == schedTabDataPtrTmp->currentSlotDelay )
#endif
            {
                retVal = LINIF_SCHDLHDLRRET_NEWMESSAGE;
            }
            else
            {
                scheduleTableListIdx = schedTabDataPtrTmp->currentTable;

                /* If the schedule is requested and Lin send frame status is LINIF_SENDFRAME_IDLE, the schedule can be started. */
                if( (schedTabDataPtrTmp->requestedTable != LINIF_SCHEDULE_INVALID) &&
                    (LINIF_SENDFRAME_IDLE == LinIf_ChannelData[LinIf_LinIfChannel].LinIf_SendFrameStatus) )
                {
                    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" */
                    schedRunMode = LinIf_ScheduleTableList[scheduleTableListIdx].runMode;
                    if( ((LINIF_RUNMODE_RUNONCE == schedRunMode) && (LINIF_INIT_ZERO == schedTabDataPtrTmp->currentSlot))
                        || ( LINIF_RUNMODE_RUNCONTINUOUS == schedRunMode ) )
                    {
                         retVal = LINIF_SCHDLHDLRRET_NEWMESSAGE;
                    }
                    else
                    {
                         /* Do nothing. */
                    }
                }
                else
                {
                    /* Do nothing. */
                }
            }
        }

        /* If handling of next schedule entry can be started. */
        if( LINIF_SCHDLHDLRRET_NEWMESSAGE == retVal )
        {
            /* If NULL schedule table is requested, set it and quit, no further handling required. */
            if( nullScheTable == schedTabDataPtrTmp->requestedTable )
            {
                /* Switch to NULL schedule table. */
                LinIf_FlushAllSchedules(LinIf_LinIfChannel, schedTabDataPtrTmp);
                schedTabDataPtrTmp->schedReqConfirmTable = LINIF_INIT_ZERO;
                retVal = LINIF_SCHDLHDLRRET_ONNULLSCHEDULE;

                /* Set delay to 0, no message started. */
                *LinIf_FrameMaxDelayPtr = LINIF_INIT_ZERO;
                /* Schedule change handled, remove request. */
                schedTabDataPtrTmp->requestedTable = LINIF_SCHEDULE_INVALID;
            }
            /* Otherwise: Do actual schedule table handling. */
            else
            {
                /* Preset return value to LinIf_SchdlHdlrRet_NewMessage, maybe changed later in function. */
                retVal = LINIF_SCHDLHDLRRET_NEWMESSAGE;

                /* At first check if a RUN_ONCE schedule is finished. In this case, switch back to previous table and slot. */
                LinIf_ScheduleTableHandler_RunOnceFinalization(schedTabDataPtrTmp);

                /* If a new table is requested, perform the actual switch (if not a RUNONCE schedule is active) and notify the schedule change. */
                LinIf_ScheduleTableHandler_RequestedTableSwitch(schedTabDataPtrTmp);

                /* If new table is NULL schedule table, reset frame delay and quit. */
                if( nullScheTable == schedTabDataPtrTmp->currentTable )
                {
                    /* RUN_ONCE finished and switched back to NULL schedule table, set delay to 0, no message started. */
                    *LinIf_FrameMaxDelayPtr = LINIF_INIT_ZERO;
                    retVal                  = LINIF_SCHDLHDLRRET_ONNULLSCHEDULE;
                }
                else
                {
                    /* Retrieve current message information. */
                    /* Get index into global schedule table list for current table. */
                    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" */
                    schedTabListIdx = LinIf_ScheduleTableListInd[schedTabDataPtrTmp->currentTable];

                    /* Get index into global entry slot list for current slot. */
                    slotListIdx = LinIf_ScheduleTableList[schedTabListIdx].entryStartIdxOfScheduleTableList
                                   + schedTabDataPtrTmp->currentSlot;

                    /* Store delay in ticks of current slot. */
                    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" */
                    schedTabDataPtrTmp->currentSlotDelay = LinIf_Entry[slotListIdx].delayTime;

                    /* Get global index into LinIf_FrameList of referenced frame. */
                    *LinIf_FrameHandlePtr = (uint16)LinIf_Entry[slotListIdx].frameListIdx;

                    /* Get length of frame in bytes. */
                    frameLengthTmp = LINIf_Frame_Cfg_Tab[*LinIf_FrameHandlePtr].lengthOfFrameList;

                    if( frameLengthTmp > LINIF_INIT_TWO )
                    {
                        /* Larger than 2 bytes of data should be emitted within 10ms. */
                        *LinIf_FrameMaxDelayPtr = LINIF_SEND_CONFIRMATION_TIMEOUT_10MS / 
                                                  LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].channelFuncCallCycleCfg;
                    }
                    else
                    {
                        /* less than or equal to 2 bytes of data should be emitted within 5ms. */
                        *LinIf_FrameMaxDelayPtr = LINIF_SEND_CONFIRMATION_TIMEOUT_5MS / 
                                                  LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].channelFuncCallCycleCfg;
                    }
                    /* The timeout time for obtaining the frame status is longer than the transmission period of the frame. */
                    if(*LinIf_FrameMaxDelayPtr > LinIf_Entry[slotListIdx].delayTime)
                    {
                        /* Assign the frame transmission period to the timeout time for obtaining the frame status. */
                        *LinIf_FrameMaxDelayPtr = LinIf_Entry[slotListIdx].delayTime;
                    }

                    /* Update slot index and check if new slot is last one in table. */
                    schedTabDataPtrTmp->currentSlot++;
                    if( schedTabDataPtrTmp->currentSlot
                        >= LinIf_ScheduleTableList[schedTabListIdx].numberOfScheduleEntries )
                    {
                        schedTabDataPtrTmp->currentSlot = LINIF_INIT_ZERO;
                        /* Inform LinSM if header of last frame of current schedule table is going to be transmitted. */

#if( LINIF_SCHEDULE_END_NOTIFICATION == STD_ON )
                        schedTabDataPtrTmp->schedEndNotifyTable = schedTabDataPtrTmp->currentTable;
#endif

                        /* Switch back to previous table if collision resolving table is run through. */
#if( LINIF_EVT_FRM_SUPPORTED == STD_ON )
                        if( LINIF_EVTCOLLRESOLVINGSTA_ONRESOLVING == schedTabDataPtrTmp->evtCollResolvingState )
                        {
                            /* Collision resolving table is run through, so switch back to previous table. */
                            schedTabDataPtrTmp->currentSlot = schedTabDataPtrTmp->previousContinuousSlot;
                            schedTabDataPtrTmp->currentTable = schedTabDataPtrTmp->previousContinuousTable;
                            schedTabDataPtrTmp->evtCollResolvingState = LINIF_EVTCOLLRESOLVINGSTA_IDLE;
                        }
#endif
                    }
                }
            }
        }
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: LinIf_ScheduleProcessing_UnconditionalFrame
*
* Explanation: Scheduletable unconditional frame process.
*
* param: LinIf_ChannelDataPtr: Channel data pointer.
*        LinIf_LinPduPtr: Pdu data pointer.
*        LinIf_FrameHandle: Frame index.
*
* retval: None
********************************************************************************
*/
static FUNC(boolean, LINIF_CODE) LinIf_ScheduleProcessing_UnconditionalFrame
(
    /* Polyspace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_LinIf_Rule8.13" */
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_ChannelDataPtr,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) LinIf_LinPduPtr,
    uint16 LinIf_FrameHandle
)
{
    boolean sendFrameTmp = TRUE;
    PduIdType upPduId;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    PduInfoType pduInfo = {NULL_PTR, LINIF_INIT_ZERO};

    /* If unconditional frame has direction Tx. */
    if( LINIF_MSR_MASTER_RESPONSE == LINIf_Frame_Cfg_Tab[LinIf_FrameHandle].pduDirection )
    {
        /* Set pointer to transmit data. */
        LinIf_LinPduPtr->SduPtr  = (uint8*)(&(LinIf_ChannelDataPtr->LinIf_TxData[LINIF_INIT_ZERO]));

        /* Request data from PduR for this frame. */
        pduInfo.SduLength = LINIf_Frame_Cfg_Tab[LinIf_FrameHandle].lengthOfFrameList;
        pduInfo.SduDataPtr = LinIf_LinPduPtr->SduPtr;

        upPduId = LINIf_Frame_Cfg_Tab[LinIf_FrameHandle].pduIdOfFrameList;

        if( (Std_ReturnType)E_NOT_OK == (LinIf_TxTriggerTransmitUL_Process(LinIf_FrameHandle, upPduId, &pduInfo)) )
        {
            sendFrameTmp = FALSE;
        }
    }

    return sendFrameTmp;
}

#if( LINIF_SPORADIC_FRM_SUPPORTED == STD_ON )
/*
********************************************************************************
* Function Name: LinIf_ScheduleProcessing_SporadicFrame
*
* Explanation: Scheduletable unconditional frame process
*
* param: LinIf_ChannelDataPtr: Channel data pointer.
*        LinIf_LinPduPtr: Pdu data pointer.
*        LinIf_FrameHandle: Frame index.
*
* retval: None
********************************************************************************
*/
static FUNC(boolean, LINIF_CODE) LinIf_ScheduleProcessing_SporadicFrame
(
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_ChannelDataPtr,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) LinIf_LinPduPtr,
    P2VAR(uint16, AUTOMATIC, LINIF_APPL_DATA) LinIf_NewFrameHandlePtr
)
{
    boolean sporFrameRequested = FALSE;
    uint8 sporadicFrameTmp = LINIF_INIT_ZERO;
    uint8 byteMskTmp = LINIF_INIT_ZERO;
    uint8 bitMskTmp = LINIF_INIT_ZERO;
    uint16 frmHandle = LINIF_INIT_ZERO;
    uint16 handle = LINIF_INIT_ZERO;
    uint16 sporUncFrmIdx = LINIF_INIT_ZERO;
    uint16 tmp = LINIF_INIT_ZERO;
    uint16 sporadicFrmInfoIdx = LINIF_INIT_ZERO;

    handle = LinIf_ChannelDataPtr->frameHandle;
    sporadicFrmInfoIdx = LINIf_Frame_Cfg_Tab[LinIf_ChannelDataPtr->frameHandle].fixedFrameSduListIdxOfFrameList;

    /* Iterate over all sporadic unconditional frames assigned to the sporadic slot. */
    while( sporadicFrameTmp < LinIf_SporadicFrameInfo[sporadicFrmInfoIdx].uncFrameCount )
    {
        /* Get the index of the sporadic unconditional frame by LinIf_SporadicFrameInfo -> LinIf_SporUncFrameByPriorityList -> LinIf_SporUnconditionalFrame. */
        tmp = LinIf_SporadicFrameInfo[LinIf_ChannelDataPtr->frameHandle].sporUncFrmByProListStartdx + sporadicFrameTmp;
        tmp = LinIf_SporUncFrameByPriorityList[tmp];

        /* Get the index of the sporadic unconditional frame by LinIf_SporadicFrameInfo. */
        byteMskTmp = LinIf_SporUnconditionalFrame[sporUncFrmIdx].byteMskOfSporUncFrm;
        bitMskTmp  = LinIf_SporUnconditionalFrame[sporUncFrmIdx].bitMskOfSporUncFrm;

        /* If the transmission flag of the sporadic unconditional frame is set. */
        if( LINIF_INIT_ZERO != (LinIf_SporTransmitFlags[byteMskTmp] & bitMskTmp) )
        {
            /* Flag is set for the current unconditional frame - transmit this frame. No further search necessary as in order by priority */
            LinIf_ChannelDataPtr->frameHandle = LinIf_SporUnconditionalFrame[sporUncFrmIdx].frmIdxOfSporUncFrm;
            *LinIf_NewFrameHandlePtr = (uint16)LinIf_ChannelDataPtr->frameHandle;

            frmHandle = LinIf_ChannelDataPtr->frameHandle;

            /* Set sporadic frame to LinIf_FrameType_UnconditionalFrame. */
            LinIf_ChannelDataPtr->currentFrameType = LINIf_Frame_Cfg_Tab[frmHandle].frameType;

            /* Setup given LIN Pdu with new message information. */
            LinIf_LinPduPtr->Cs = LINIf_Frame_Cfg_Tab[frmHandle].chkSumType;
            LinIf_LinPduPtr->Dl = (Lin_FrameDlType)LINIf_Frame_Cfg_Tab[frmHandle].lengthOfFrameList;
            LinIf_LinPduPtr->Drc = LINIf_Frame_Cfg_Tab[frmHandle].pduDirection;
            LinIf_LinPduPtr->Pid = (Lin_FramePidType)LinIf_Pid_Convert_Table[(LINIf_Frame_Cfg_Tab[frmHandle].frameId)];

            /* Activate transmission of unconditional frame in this slot. */
            sporFrameRequested = TRUE;

            break;
        }

        sporadicFrameTmp++;
    }

    return sporFrameRequested;
}
#endif

/*
********************************************************************************
* Function Name: LinIf_ScheduleProcessing_FrameHandling
*
* Explanation: LinIf schedule frame process.
*
* param: LinIf_ChannelData: PDU data index.
*        LinIf_LinPduPtr: Pdu data pointer.
*        LinIf_FrameHandlePtr: Frame index.
*        LinTp_CtrlPtr: LinTp data pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(boolean, LINIF_CODE) LinIf_ScheduleProcessing_FrameHandling
(
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_ChannelDataPtr,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) LinIf_LinPduPtr,
    P2VAR(uint16, AUTOMATIC, LINIF_APPL_DATA) LinIf_FrameHandlePtr
#if( LINIF_TP_SUPPORTED == STD_ON )
    ,P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr
#endif
)
{
    boolean sendFrameTmp = TRUE;

#if( LINIF_FIXEDFRAMESDULIST == STD_ON )
    uint8 byteCtnTmp = LINIF_INIT_ZERO;
    uint8 fexdIdx = LINIF_INIT_ZERO;
#endif

    LINIF_DUMMY_STATEMENT(LinIf_FrameHandlePtr);

    /* Handle frame depending on frame type. */
    switch( LinIf_ChannelDataPtr->currentFrameType )
    {

#if( LINIF_SPORADIC_FRM_SUPPORTED == STD_ON )
        /* Sporadic frame */
        case LINIF_FRMTYPE_SPORADICFRAME:

            sendFrameTmp = LinIf_ScheduleProcessing_SporadicFrame(LinIf_ChannelDataPtr,
                                                LinIf_LinPduPtr, LinIf_FrameHandlePtr);

            if( FALSE == sendFrameTmp )
            {
                break;
            }
#endif

        case LINIF_FRMTYPE_UNCONDITIONALFRAME:
            sendFrameTmp = LinIf_ScheduleProcessing_UnconditionalFrame(LinIf_ChannelDataPtr,
                                                    LinIf_LinPduPtr, *LinIf_FrameHandlePtr);
            break;

        /* Master request frame: Forward to LinTp if supported, otherwise skip MRF transmission. */
        case LINIF_FRMTYPE_MRF:
#if( LINIF_TP_SUPPORTED == STD_ON )
            sendFrameTmp = LinTp_TxScheduleProcessing(LinTp_CtrlPtr,
                                                      LinIf_ChannelDataPtr, LinIf_LinPduPtr);
#else
            sendFrameTmp = FALSE;
#endif
            break;

        /* Slave response frame: */
        case LINIF_FRMTYPE_SRF:
        /* Only send SRF header if node configuration response expected and LinTp is not in pending state. */
#if( LINIF_FIXEDFRAMESDULIST == STD_ON )
        if( LINIF_NODECONFIGCMD_IDLE == LinIf_ChannelDataPtr->nodeConfigurationCmd )
#endif
        {
#if( LINIF_TP_SUPPORTED == STD_ON )
            if( (LINTP_CHANNEL_BUSY_RX_SUSPENDED == LinTp_CtrlPtr->linTp_Ch_State)
                || (LINTP_CHANNEL_BUSY_RX_WAIT_FOR_START == LinTp_CtrlPtr->linTp_Ch_State) )
            {
                /* Skip current SRF frame. */
                sendFrameTmp = FALSE;
            }
#else
            /* Header of SlaveResp is always send. Nothing to do. */
#endif
        }
#if( LINIF_FIXEDFRAMESDULIST == STD_ON )
        else if( LINIF_NODECONFIGCMD_SKIPSRF == LinIf_ChannelDataPtr->nodeConfigurationCmd )
        {
            /* Skip transmission of SRF after not successful Node Configuration Command. */
            sendFrameTmp = FALSE;
        }
        else
        {
            /* No handling required, MISRA only */
        }
#endif
            break;

#if( LINIF_FIXEDFRAMESDULIST == STD_ON )
        case LINIF_FRMTYPE_ASSIGNFRAMEID:
        case LINIF_FRMTYPE_UNASSIGNFRAMEID:
        case LINIF_FRMTYPE_ASSIGNAD:
        case LINIF_FRMTYPE_FREEFORMAT:
        case LINIF_FRMTYPE_CONDITIONALCHANGENAD:
        case LINIF_FRMTYPE_ASSIGNFRAMEIDRANGE:
        case LINIF_FRMTYPE_SAVECONFIGURATION:

            /* Abort any active TP connection if a node configuration command is going to be transmitted. */
#if( LINIF_TP_SUPPORTED == STD_ON )
            LinTp_CloseActiveConnection(LinTp_CtrlPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER */
#endif
            /* Prepare fixed transmission data. */
            /* Set pointer to transmit buffer. */
            LinIf_LinPduPtr->SduPtr = &(LinIf_ChannelDataPtr->LinIf_TxData[LINIF_INIT_ZERO]);
            /* Copy fixed data bytes to buffer. */
            for( byteCtnTmp = LINIF_INIT_ZERO; byteCtnTmp < LINIF_LINPDU_SIZE; byteCtnTmp++ )
            {
                fexdIdx = (uint8)(LINIf_Frame_Cfg_Tab[*LinIf_FrameHandlePtr].fixedFrameSduListIdxOfFrameList) + byteCtnTmp;

                LinIf_LinPduPtr->SduPtr[byteCtnTmp] = LinIf_FixedFrameSduList[fexdIdx];
            }
            LinIf_ChannelDataPtr->nodeConfigurationCmd = LINIF_NODECONFIGCMD_SENDMRF;

            break;
#endif
        /* Case LINIF_FRMTYPE_EVENTTRIGGREDFRAME: */
        /* Nothing to do, header is always sent. */
        /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        default:
            /* Do Nothing. */
            break;
    }

    return sendFrameTmp;
}

/*
********************************************************************************
* Function Name: LinIf_ScheduleProcessing_SleepHandling
*
* Explanation: LinIf schedule sleep process.
*
* param: LinIf_ChannelDataPtr: Channel data pointer.
*        LinIf_LinIfChannel: Channel index.
*
* retval: None
********************************************************************************
*/
static FUNC(boolean, LINIF_CODE) LinIf_ScheduleProcessing_SleepHandling
(
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_ChannelDataPtr,
    uint8 LinIf_LinIfChannel
)
{
    boolean sleepReqHandled = FALSE;
    Std_ReturnType retVal;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    uint8 channelRef = LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].linChannelIdRef;

    /* If a (normal) goto-sleep request is pending. */
    if( LINIF_ONSLRRPMODEFRM_ONREQ == LinIf_ChannelDataPtr->sleepModeFrameHandle )
    {
#if( LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON )
        uint8 ctrlId = LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].ctrlId;
        retVal = LinIf_LinMultipeDrvInfo[ctrlId].LinIf_Lin_GoToSleepFunc(channelRef);
#else
        /* Polyspace +1 MISRA-C3:17.3 [Justified:Unset] "NSCA_Polyspace_LinIf_Rule17.3" */
        retVal = (Std_ReturnType)Lin_GoToSleep(channelRef);
#endif  /* LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON */

        /* If sleep frame transmission request is accepted. */
        if( (Std_ReturnType)E_OK == retVal )
        {
            /* Eight bytes of data should be emitted within 10ms. */
            LinIf_ChannelDataPtr->frameMaxDelayCtn = LINIF_SEND_CONFIRMATION_TIMEOUT_10MS / 
                                                     LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].channelFuncCallCycleCfg;
            LinIf_ChannelDataPtr->LinIf_SendFrameStatus = LINIF_SENDFRAME_BUSY;
            LinIf_ChannelDataPtr->sleepModeFrameHandle = LINIF_ONSLRRPMODEFRM_ONTRANS;
            LinIf_ChannelDataPtr->currentFrameType = LINIF_FRMTYPE_SLEEPMODEFRAME;
        }
        /* Not accepted. */
        else
        {
            LinIf_ChannelDataPtr->channelState = LINIF_CHANNEL_SLEEP;
            LinIf_ChannelDataPtr->sleepModeFrameHandle = LINIF_ONSLRRPMODEFRM_IDLE;
            LinIf_FlushAllSchedules(LinIf_LinIfChannel, &(LinIf_ChannelDataPtr->schedTabData));

            LinIf_GoToSleepConfirmationUL_Process(LinIf_LinIfChannel, LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].ComMChannelRef, FALSE);
        }

#if( (LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON) || (LINIF_TRCV_WAKEUP_SUPPORT == STD_ON) )
        /* Reset wakeup flag in any case. */
        LinIf_ChannelDataPtr->wakeupFlag = LINIF_INIT_ZERO;
#endif
        sleepReqHandled = TRUE;
    }
    /* Check if an internal goto-sleep request is pending. */
    else if( LINIF_ONSLRRPMODEFRM_ONREQINT == LinIf_ChannelDataPtr->sleepModeFrameHandle )
    {
#if( LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON )
        uint8 ctrlId = LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].ctrlId;
        (void)LinIf_LinMultipeDrvInfo[ctrlId].LinIf_Lin_GoToSleepInternalFunc(channelRef);
#else
        /* Polyspace +1 MISRA-C3:17.3 [Justified:Unset] "NSCA_Polyspace_LinIf_Rule17.3" */
       (void)Lin_GoToSleepInternal(channelRef);
#endif  /* LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON */

        /* Enter sleep mode, reset wakeup flag, inform LinSM directly about sleep confirmation. */
#if( (LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON) || (LINIF_TRCV_WAKEUP_SUPPORT == STD_ON) )
        LinIf_ChannelDataPtr->wakeupFlag = LINIF_INIT_ZERO;
#endif
        LinIf_ChannelDataPtr->channelState = LINIF_CHANNEL_SLEEP;
        LinIf_ChannelDataPtr->sleepModeFrameHandle = LINIF_ONSLRRPMODEFRM_IDLE;

        LinIf_FlushAllSchedules(LinIf_LinIfChannel, &(LinIf_ChannelDataPtr->schedTabData));

        LinIf_GoToSleepConfirmationUL_Process(LinIf_LinIfChannel, LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].ComMChannelRef, TRUE);

        sleepReqHandled = TRUE;
    }
    else
    {
        /* Do nothing. */
    }

    return sleepReqHandled;
}

/*
********************************************************************************
* Function Name: LinIf_GoToSleepConfirmationUL_Process
*
* Explanation: The LinIf will call this function when the go to sleep command is
*              sent not successfully/successfully on the bus.
*
* param: LinIf_LinIfChannel: Channel index.
*        channel: Identification of the LIN channel.
*        success: True if goto sleep was successfully sent, false otherwise.
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_GoToSleepConfirmationUL_Process
(
    uint8 LinIf_LinIfChannel,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType channel,
    boolean success
)
{
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( NULL_PTR != LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].goToSleepConfirmation_p )
    {
        LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].goToSleepConfirmation_p(channel, success);
    }
}

/*
********************************************************************************
* Function Name: LinIf_ScheduleRequestConfirmationUL_Process
*
* Explanation: The LinIf will call this function when the schedule table change request has been performed.
*
* param: LinIf_LinIfChannel: Channel index.
*        channel: Identification of the LIN channel.
*        schedule: Index to newly active Schedule table.
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_ScheduleRequestConfirmationUL_Process
(
    uint8 LinIf_LinIfChannel,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType channel,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    LinIf_SchHandleType schedule
)
{
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( NULL_PTR != LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].scheduleRequestConfirmation_p )
    {
        LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].scheduleRequestConfirmation_p(channel, schedule);
    }
}

/*
********************************************************************************
* Function Name: LinIf_WakeupConfirmationUL_Process
*
* Explanation: The LinIf will call this function when the wake up signal command
*              is sent not successfully/successfully on the bus.
*
* param: LinIf_LinIfChannel: Channel index.
*        channel: Identification of the LIN channel.
*        success: True if wakeup was successfully sent, false otherwise
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_WakeupConfirmationUL_Process
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    uint8 LinIf_Channel,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType ComMChannel,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    boolean Success
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    LinIf_ChannelDataType* channelDataPtrTmp = &LinIf_ChannelData[LinIf_Channel];
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( NULL_PTR != LinIf_Channl_Cfg_Tab[LinIf_Channel].WakeupConfirmation_p )
    {
        LinIf_Channl_Cfg_Tab[LinIf_Channel].WakeupConfirmation_p(ComMChannel, Success);
    }

#if( (LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON) || (LINIF_TRCV_WAKEUP_SUPPORT == STD_ON) )
    if( LINIF_INIT_ZERO == channelDataPtrTmp->wakeupFlag )
#endif
    {
        channelDataPtrTmp->reqWakeUpFlag = FALSE;
    }
}

/*
********************************************************************************
* Function Name: LinIf_TxTriggerTransmitUL_Process
*
* Explanation: Within this API, the upper layer module (called module) shall check
*              whether the available data fits into the buffer size reported by PduInfoPtr->SduLength.
*
* param: LinIf_FrameHandle: Idx of LINIf_Frame_Cfg_Tab[];
*        TxPduId: ID of the I-PDU that has been transmitted.
*        PduInfoPtr: Contains a pointer to a buffer (SduDataPtr) to where the SDU data shall be copied,
*                    and the available buffer size in SduLengh.
* retval: E_OK: SDU has been copied and SduLength indicates the number of copied bytes.
*         E_NOT_OK: No SDU data has been copied. PduInfoPtr must not be used since
*                   it may contain a NULL pointer or point to invalid data.
********************************************************************************
*/
static FUNC(Std_ReturnType, LINIF_CODE) LinIf_TxTriggerTransmitUL_Process
(
    uint16 FrameCfgIdx,
    PduIdType TxPduId,
    /* Polyspace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_LinIf_Rule8.13" */
    P2VAR(PduInfoType, AUTOMATIC, LINIF_APPL_DATA) PduInfoPtr
)
{
    Std_ReturnType rtnVal = E_NOT_OK;

    if( NULL_PTR != LINIf_Frame_Cfg_Tab[FrameCfgIdx].txTriggerTransmit_p )
    {
        rtnVal = LINIf_Frame_Cfg_Tab[FrameCfgIdx].txTriggerTransmit_p(TxPduId, PduInfoPtr);
    }

    return rtnVal;
}

#if( LINIF_SLAVE_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: LinIf_GotoSleepIndicationUL_Process
*
* Explanation: The LinIf will call this function when the go to sleep command
*              is sent not successfully/successfully on the bus.
*
* param: LinIf_LinIfChannel: Channel index.
*        channel: Identification of the LIN channel.
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_GotoSleepIndicationUL_Process
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    uint8 LinIfChannel,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType ComMChannel
)
{
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( NULL_PTR != LinIf_Channl_Cfg_Tab[LinIfChannel].goToSleepIndication_p )
    {
        LinIf_Channl_Cfg_Tab[LinIfChannel].goToSleepIndication_p(ComMChannel);
    }
}
#endif

/*
********************************************************************************
* Function Name: LinIf_TxConfirmationUL_Process
*
* Explanation: Within this API, the upper layer module (called module) shall check
*              whether the available data fits into the buffer size reported by PduInfoPtr->SduLength.
*
* param: LinIf_FrameHandle: Idx of LINIf_Frame_Cfg_Tab[];
*        TxPduId: ID of the I-PDU that has been transmitted.
*        result: result of the confirmation process.
*
* retval: void
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_TxConfirmationUL_Process
(
    uint16 LinIf_FrameHandle,
    PduIdType TxPduId,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    Std_ReturnType Result
)
{
    if( NULL_PTR != LINIf_Frame_Cfg_Tab[LinIf_FrameHandle].txConfirmation_p )
    {
        LINIf_Frame_Cfg_Tab[LinIf_FrameHandle].txConfirmation_p(TxPduId, Result);
    }
}

/*
********************************************************************************
* Function Name: LinIf_RxIndicationUL_Process
*
* Explanation: Indication of a received PDU from a lower layer communication interface module..
*
* param: LinIf_FrameHandle: Idx of LINIf_Frame_Cfg_Tab[];
*        RxPduId: ID of the I-PDU that has been received.
*        result: Contains the length (SduLength) of the received PDU, a pointer to a 
*                buffer (SduDataPtr) containing the PDU, and the MetaData related to this PDU.
*
* retval: void
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_RxIndicationUL_Process
(
    uint16 LinIf_FrameHandle,
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, LINIF_APPL_DATA) PduInfoPtr
)
{
    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" */
    if( NULL_PTR != LINIf_Frame_Cfg_Tab[LinIf_FrameHandle].rxIndication_p )
    {
        LINIf_Frame_Cfg_Tab[LinIf_FrameHandle].rxIndication_p(RxPduId, PduInfoPtr);
    }
}


/*
********************************************************************************
* Function Name: LinIf_ScheduleProcessing
*
* Explanation: LinIf schedule process.
*
* param: LinIf_ChannelDataPtr: Channel data pointer.
*        LinIf_LinIfChannel: Channel index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_ScheduleProcessing
(
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_ChannelDataPtr,
    uint8 LinIf_LinIfChannel
)
{
    boolean boolRetTmp;
    boolean sendFrameTmp;
    Std_ReturnType retVal;
    uint8 scheduleTableHandlerRetTmp;
    uint16 frameMaxDelayTmp = LINIF_INIT_ZERO;
    uint16 frameHandleTmp = LINIF_INIT_ZERO;
    Lin_PduType linPduTmp = {LINIF_INIT_ZERO};
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    uint8 LinIfTempBuf[LINIF_LINPDU_SIZE] = {LINIF_INIT_ZERO};

#if( LINIF_TP_SUPPORTED == STD_ON )
    /* LinTp: Request periodically PduR for transmission data or reception buffer (if necessary) */
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    LinTp_ControlType* tpCtrlTmp = &LinTp_Ctrl.raw[LinIf_LinIfChannel];
    LinTp_DataBuffer_Polling(tpCtrlTmp);
#endif

    scheduleTableHandlerRetTmp = LinIf_ScheduleTableHandler(&frameMaxDelayTmp, &frameHandleTmp, LinIf_LinIfChannel);

    /* If new slot is started or NULL schedule table active (= new slot can be started). */
    if( (scheduleTableHandlerRetTmp != LINIF_SCHDLHDLRRET_NONEWMESSAGE)
     && (LinIf_ChannelDataPtr->sleepModeFrameHandle != LINIF_ONSLRRPMODEFRM_ONTRANS) )
    {
        /* Next message will be started or NULL schedule table is active. */
        boolRetTmp = LinIf_ScheduleProcessing_SleepHandling(LinIf_ChannelDataPtr, LinIf_LinIfChannel);

        if( (boolRetTmp == (boolean)FALSE) && ((uint8)LINIF_SCHDLHDLRRET_NEWMESSAGE == scheduleTableHandlerRetTmp) )
        {   
            /* New message shall be started, no sleep request was handled in this slot, null schedule table is not set */
            /* Process new slot: update slot information and setup LIN PDU for driver. */
            LinIf_ChannelDataPtr->frameHandle = frameHandleTmp;
            LinIf_ChannelDataPtr->currentFrameType = LINIf_Frame_Cfg_Tab[frameHandleTmp].frameType;

            /* Set LinPdu for driver. */
            linPduTmp.Cs = LINIf_Frame_Cfg_Tab[frameHandleTmp].chkSumType;
            linPduTmp.Dl = (Lin_FrameDlType)LINIf_Frame_Cfg_Tab[frameHandleTmp].lengthOfFrameList;
            linPduTmp.Drc = LINIf_Frame_Cfg_Tab[frameHandleTmp].pduDirection;
            linPduTmp.Pid = (Lin_FramePidType)LinIf_Pid_Convert_Table[(LINIf_Frame_Cfg_Tab[frameHandleTmp].frameId)];
            linPduTmp.SduPtr = LinIfTempBuf;

            /* Check possible skipping of slot and request transmission data for Tx frames simultaneously. */
#if( LINIF_TP_SUPPORTED == STD_ON )
            sendFrameTmp = LinIf_ScheduleProcessing_FrameHandling(LinIf_ChannelDataPtr, &linPduTmp, &frameHandleTmp, tpCtrlTmp);
#else
            sendFrameTmp = LinIf_ScheduleProcessing_FrameHandling(LinIf_ChannelDataPtr, &linPduTmp, &frameHandleTmp);
#endif

            if( (boolean)TRUE == sendFrameTmp )
            {
#if( LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON )
                uint8 ctrlId = LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].ctrlId;
                retVal = LinIf_LinMultipeDrvInfo[ctrlId].LinIf_Lin_SendFrameFunc(LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].linChannelIdRef, &linPduTmp);
#else
                /* If frame is handled in this slot, send header / message and setup transmission time. */
                /* Polyspace +1 MISRA-C3:17.3 [Justified:Unset] "NSCA_Polyspace_LinIf_Rule17.3" */
                retVal = (Std_ReturnType)Lin_SendFrame(LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].linChannelIdRef, &linPduTmp);
#endif  /* LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON */

                /* Transmission successful. */
                if( ((Std_ReturnType)E_OK == retVal)
                    && (LINIf_Frame_Cfg_Tab[frameHandleTmp].pduDirection != LINIF_MSR_SLAVE_TO_SLAVE) )
                {
                    /* Store maximum frame transmission time within current slot for rx and tx frame. */
                    LinIf_ChannelDataPtr->frameMaxDelayCtn = frameMaxDelayTmp;
                    /* If have a frame is being sent, waiting for notification. */
                    LinIf_ChannelDataPtr ->LinIf_SendFrameStatus = LINIF_SENDFRAME_BUSY;
                }
            }
        }
    }
}

/*
********************************************************************************
* Function Name: LinIf_CurrentMessageProcessing
*
* Explanation: LinIf current message process.
*
* param: LinIf_ChannelDataPtr: Channel data pointer.
*        LinIf_LinIfChannel: Channel index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_CurrentMessageProcessing
(
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_ChannelDataPtr,
    uint8 LinIf_LinIfChannel
)
{
    Lin_StatusType linStatusTmp = LIN_NOT_OK;
    uint8 channelRef;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    uint8 linSduPtrTmp[LINIF_LINPDU_SIZE] = {LINIF_INIT_ZERO};
    uint8* linSduPtr = linSduPtrTmp;
    uint8 chkRslt = LINIF_E_NO_ERR;

#if( STD_ON == LINIF_TP_SUPPORTED )
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    LinTp_ControlType* tpCtrlTmp = &LinTp_Ctrl.raw[LinIf_LinIfChannel];
#endif

#if( LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON )
    uint8 ctrlId = LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].ctrlId;
#endif

    channelRef = LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].linChannelIdRef;

    /* If send frame is OK,but not confirmed. */
    if( LINIF_SENDFRAME_BUSY == LinIf_ChannelDataPtr ->LinIf_SendFrameStatus )
    {
        /* If maximum frame duration is not zero. */
        if( LinIf_ChannelDataPtr->frameMaxDelayCtn > LINIF_INIT_ZERO )
        {
            /* The maximum frame duration decreases. */
            LinIf_ChannelDataPtr->frameMaxDelayCtn--;
        }

        /* Frame delay expired, check LIN driver for status of last frame. */
#if( LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON )
        linStatusTmp = LinIf_LinMultipeDrvInfo[ctrlId].LinIf_Lin_GetStatusFunc(channelRef, &linSduPtr);
#else
        /* Polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" Polyspace +1 MISRA-C3:17.3 [Justified:Unset] "NSCA_Polyspace_LinIf_Rule17.3" */
        linStatusTmp = Lin_GetStatus(channelRef, &linSduPtr);
#endif  /* LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON */

        switch( LinIf_ChannelDataPtr->currentFrameType )
        {
            /* On MRF: LinTp is the only user, so a MRF is never scheduled if LinTp is not activated. */
#if( LINIF_TP_SUPPORTED == STD_ON )
            case LINIF_FRMTYPE_MRF:
                /* When the LIN status is not "Tx busy" or when the process of obtaining the LIN status times out,
                handle the MRF data. */
                if( (LIN_TX_BUSY != linStatusTmp) || 
                    (LINIF_INIT_ZERO == LinIf_ChannelDataPtr->frameMaxDelayCtn) )
                {
                    /* Forward transmitted MRF to LinTp if supported. */
                    LinTp_TxMessageProcessing(LinIf_LinIfChannel, tpCtrlTmp, linStatusTmp);
                    /* If the sending confirmation is complete or times out, 
                       reset the sending status to LINIF_SENDFRAME_IDLE. */
                    LinIf_ChannelDataPtr ->LinIf_SendFrameStatus = LINIF_SENDFRAME_IDLE;
                    LinIf_ChannelDataPtr->frameMaxDelayCtn = LINIF_INIT_ZERO;
                    if( (LIN_TX_BUSY == linStatusTmp) || (LIN_TX_ERROR == linStatusTmp) )
                    {
                        chkRslt = LINIF_E_RESPONSE;
                    }
                }
                break;
#endif

            case LINIF_FRMTYPE_UNCONDITIONALFRAME:
                /* When the LIN status is not "Tx busy",Rx busy,Rx No response or when the process of obtaining the LIN status times out, 
                handle the unconditional frame. */
                if( ((LIN_RX_BUSY != linStatusTmp) && (LIN_RX_NO_RESPONSE != linStatusTmp) && (LIN_TX_BUSY != linStatusTmp)) ||
                     (LINIF_INIT_ZERO == LinIf_ChannelDataPtr->frameMaxDelayCtn) )
                {
                    /* On unconditional frame: perform handling. */
                    LinIf_MessageProcessing_Unconditional(LinIf_ChannelDataPtr, LinIf_LinIfChannel, linSduPtr, linStatusTmp);
                    /* If the sending and receiving confirmation is complete or times out, 
                       reset the sending status to LINIF_SENDFRAME_IDLE. */
                    LinIf_ChannelDataPtr ->LinIf_SendFrameStatus = LINIF_SENDFRAME_IDLE;
                    LinIf_ChannelDataPtr->frameMaxDelayCtn = LINIF_INIT_ZERO;
                }
                break;

            case LINIF_FRMTYPE_SRF:
                /* When the LIN status is not Rx busy,Rx No response or when the process of obtaining the LIN status times out, 
                handle the SRF data. */
                if( ((LIN_RX_BUSY != linStatusTmp) && (LIN_RX_NO_RESPONSE != linStatusTmp)) ||
                    (LINIF_INIT_ZERO == LinIf_ChannelDataPtr->frameMaxDelayCtn) )
                {
                    /* On SRF: perform handling. */
                    LinIf_MessageProcessing_SRF(LinIf_ChannelDataPtr, linSduPtr, LinIf_LinIfChannel, linStatusTmp);
                    /* If the sending and receiving confirmation is complete or times out, 
                       reset the sending status to LINIF_SENDFRAME_IDLE. */
                    LinIf_ChannelDataPtr ->LinIf_SendFrameStatus = LINIF_SENDFRAME_IDLE;
                    LinIf_ChannelDataPtr->frameMaxDelayCtn = LINIF_INIT_ZERO;
                }
                break;

#if( LINIF_EVT_FRM_SUPPORTED == STD_ON )
            case LINIF_FRMTYPE_EVENTTRIGGREDFRAME:
                /* When the LIN status is not "Tx busy",Rx busy,Rx No response or when the process of obtaining the LIN status times out, 
                handle the EVT frame. */
                if( ((LIN_RX_BUSY != linStatusTmp) && (LIN_RX_NO_RESPONSE != linStatusTmp) && (LIN_TX_BUSY != linStatusTmp)) ||
                     (LINIF_INIT_ZERO == LinIf_ChannelDataPtr->frameMaxDelayCtn) )
                {
                    /* On EVT frame: perform performed. */
                    LinIf_MessageProcessing_EventTriggeredFrame(LinIf_ChannelDataPtr, LinIf_LinIfChannel, linSduPtr, linStatusTmp);
                    /* If the sending and receiving confirmation is complete or times out, 
                       reset the sending status to LINIF_SENDFRAME_IDLE. */
                    LinIf_ChannelDataPtr ->LinIf_SendFrameStatus = LINIF_SENDFRAME_IDLE;
                    LinIf_ChannelDataPtr->frameMaxDelayCtn = LINIF_INIT_ZERO;
                }
                break;
#endif

#if( LINIF_FIXEDFRAMESDULIST == STD_ON )
            /* On node configuration command:
               On successful transmission, send succeeding SRF header, otherwise skip it. */
            case LINIF_FRMTYPE_ASSIGNFRAMEID:
            case LINIF_FRMTYPE_UNASSIGNFRAMEID:
            case LINIF_FRMTYPE_ASSIGNAD:
            case LINIF_FRMTYPE_FREEFORMAT:
            case LINIF_FRMTYPE_CONDITIONALCHANGENAD:
            case LINIF_FRMTYPE_ASSIGNFRAMEIDRANGE:
            case LINIF_FRMTYPE_SAVECONFIGURATION:
                /* When the LIN status is not "Tx busy",Rx busy,Rx No response or when the process of obtaining the LIN status times out, 
                handle the data. */
                if( ((LIN_RX_BUSY != linStatusTmp) && (LIN_RX_NO_RESPONSE != linStatusTmp) && (LIN_TX_BUSY != linStatusTmp)) ||
                     (LINIF_INIT_ZERO == LinIf_ChannelDataPtr->frameMaxDelayCtn) )
                {
                    /* These are schedule table commands and always tx messages, which must be processed in the LinIf. */
                    if( (Lin_StatusType)LIN_TX_OK == linStatusTmp )
                    {
                        /* Store that the frame has been send and the following SRF has to be handled without the LinTp. */
                        LinIf_ChannelDataPtr->nodeConfigurationCmd
                          = LINIF_NODECONFIGCMD_SENDSRF;
                    }
                    else
                    {
                        LinIf_ChannelDataPtr->nodeConfigurationCmd
                          = LINIF_NODECONFIGCMD_SKIPSRF;
                    }
                    /* If the sending and receiving confirmation is complete or times out, 
                       reset the sending status to LINIF_SENDFRAME_IDLE. */
                    LinIf_ChannelDataPtr ->LinIf_SendFrameStatus = LINIF_SENDFRAME_IDLE;
                    LinIf_ChannelDataPtr->frameMaxDelayCtn = LINIF_INIT_ZERO;
                }
                break;
#endif

            case LINIF_FRMTYPE_SLEEPMODEFRAME:
                /* When  the process of obtaining the LIN status times out, handle the sleep mode frame. */
                if( LINIF_INIT_ZERO == LinIf_ChannelDataPtr->frameMaxDelayCtn )
                {
                    /* Sleep Mode Frame has been send. */
                    LinIf_MessageProcessing_SleepModeFrame(LinIf_ChannelDataPtr, LinIf_LinIfChannel, linStatusTmp);
                    /* If the sending and receiving confirmation is complete or times out, 
                       reset the sending status to LINIF_SENDFRAME_IDLE. */
                    LinIf_ChannelDataPtr ->LinIf_SendFrameStatus = LINIF_SENDFRAME_IDLE;
                    LinIf_ChannelDataPtr->frameMaxDelayCtn = LINIF_INIT_ZERO;
                }
                break;

            case LINIF_FRMTYPE_WAKEUPFRAME:
                /* Wake Up Frame has been send. */
                if( LINIF_ONWAKEUPFRM_ONTRANS == LinIf_ChannelDataPtr->sleepModeFrameHandle )
                {
                    /* Only Process the wakeup frame transmission if no other request is pending. */
                    LinIf_ChannelDataPtr->sleepModeFrameHandle = LINIF_ONSLRRPMODEFRM_IDLE;
                    LinIf_WakeupConfirmationUL_Process(LinIf_LinIfChannel, LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].ComMChannelRef, TRUE);
                    /* Notification complete, reset the sending status to LINIF_SENDFRAME_IDLE. */
                    LinIf_ChannelDataPtr ->LinIf_SendFrameStatus = LINIF_SENDFRAME_IDLE;
                    LinIf_ChannelDataPtr->frameMaxDelayCtn = LINIF_INIT_ZERO;
                }
                break;
            default:
                /* On any other frame type, reset the sending status to LINIF_SENDFRAME_IDLE. */
                LinIf_ChannelDataPtr ->LinIf_SendFrameStatus = LINIF_SENDFRAME_IDLE;
                LinIf_ChannelDataPtr->frameMaxDelayCtn = LINIF_INIT_ZERO;
                break;
        }
    }
#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( chkRslt != LINIF_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinIf_Det_ErrorReport(LINIF_MAIN_FUNCTION, chkRslt);
    }
#else
    LINIF_DUMMY_STATEMENT(chkRslt);
#endif

}

/*
********************************************************************************
* Function Name: LinIf_MessageProcessing_Unconditional
*
* Explanation: Unconditional frame process.
*
* param: LinIf_ChannelDataPtr: Channel data pointer.
*        LinIf_LinIfChannel: Channel index.
*        LinIf_LinSduPtr: Message data.
*        LinIf_LinStatus: Last message state.
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_MessageProcessing_Unconditional
(
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_ChannelDataPtr,
    uint8 LinIf_LinIfChannel,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_CONST) LinIf_LinSduPtr,
    Lin_StatusType LinIf_LinStatus
)
{
#if( LINIF_SPORADIC_FRM_SUPPORTED == STD_ON )
    uint8 byteMskTmp = LINIF_INIT_ZERO;
    uint8 bitMskTmp = LINIF_INIT_ZERO;
    uint8 value = LINIF_INIT_ZERO;
    uint16 idxToSporUncFrame = LINIF_INIT_ZERO;
    uint16 getSporUncFrmIdx = LINIF_INIT_ZERO;
#endif
#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    uint8 chkRslt = LINIF_E_NO_ERR;
 #endif
    uint8 lengthByte;
    uint8 indexTmp;
    uint16 frameHandle;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    PduInfoType pduInfo = {NULL_PTR,LINIF_INIT_ZERO};
    LinIf_SchedTabDataType* schedTabDataPtrTmp = NULL_PTR;

    frameHandle = LinIf_ChannelDataPtr->frameHandle;
    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" */
    LinIf_ChannelDataPtr->pduRNotificationPduId = LINIf_Frame_Cfg_Tab[frameHandle].pduIdOfFrameList;
    schedTabDataPtrTmp = &LinIf_ChannelData[LinIf_LinIfChannel].schedTabData;
    /* If unconditional frame is Tx. */
    if( LINIF_MSR_MASTER_RESPONSE == LINIf_Frame_Cfg_Tab[frameHandle].pduDirection )
    {
        /* If transmission was successful. */
        if( (Lin_StatusType)LIN_TX_OK == LinIf_LinStatus )
        {
            /* If the current frame is not notified. */
            if( LINIF_SENDFRAME_BUSY == LinIf_ChannelDataPtr->LinIf_SendFrameStatus )
            {
                /* Inform upper layer about transmitted frame. */
                LinIf_TxConfirmationUL_Process(frameHandle, LinIf_ChannelDataPtr->pduRNotificationPduId, E_OK);
                /* Notification complete, reset status to LINIF_SENDFRAME_IDLE. */
                LinIf_ChannelDataPtr->LinIf_SendFrameStatus = LINIF_SENDFRAME_IDLE;
            }
#if( LINIF_SPORADIC_FRM_SUPPORTED == STD_ON )
            /* Clear flag of unconditional frame if sporadic slot was occupied or unconditional frame
            was transmitted regularly in schedule table. */
            indexTmp = LINIF_INIT_ZERO;

            while( indexTmp < LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].numberOfSporadicFrames )
            {
                getSporUncFrmIdx = LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].sporcUncFrmListStartOfChannelCfg + indexTmp;

                idxToSporUncFrame = LinIf_SporUnconditionalFrame[getSporUncFrmIdx].frmIdxOfSporUncFrm;

                if( LinIf_ChannelDataPtr->frameHandle == idxToSporUncFrame )
                {
                    byteMskTmp = LinIf_SporUnconditionalFrame[idxToSporUncFrame].byteMskOfSporUncFrm;
                    bitMskTmp = LinIf_SporUnconditionalFrame[idxToSporUncFrame].bitMskOfSporUncFrm;

                    value = LinIf_GetSporTransmitFlags(byteMskTmp);
                    value &= (uint8)(~bitMskTmp);
                    LinIf_SetSporTransmitFlags(byteMskTmp, value);

                    /* Frame was transmitted in sporadic slot (flag cleared afterwards) or frame handle not transmitted at all in this slot. */
                    /* In each case abort the loop as the search is finished. */
                    break;
                }
                indexTmp++;
            }
#endif
        }
        else
        {
            if( (((Lin_StatusType)LIN_TX_BUSY == LinIf_LinStatus) &&
                  ((LINIF_INIT_ZERO == LinIf_ChannelDataPtr->frameMaxDelayCtn) ||
                   (LINIF_INIT_ONE == schedTabDataPtrTmp->currentSlotDelay))) ||
                ((Lin_StatusType)LIN_TX_ERROR == LinIf_LinStatus) )
            {
                /* If the current frame is not notified. */
                if( LINIF_SENDFRAME_BUSY == LinIf_ChannelDataPtr->LinIf_SendFrameStatus )
                {
                    /* Inform upper layer about transmitted frame fail. */
                    LinIf_TxConfirmationUL_Process(frameHandle, LinIf_ChannelDataPtr->pduRNotificationPduId, E_NOT_OK);
                    /* Notification complete, reset status to LINIF_SENDFRAME_IDLE. */
                    LinIf_ChannelDataPtr->LinIf_SendFrameStatus = LINIF_SENDFRAME_IDLE;
                }

#if( LINIF_DEV_ERROR_DETECT == STD_ON )
                /* Inform about error in transmitted frame */
                chkRslt = LINIF_E_RESPONSE;
#endif
            }
        }
    }
    /* Otherwise if unconditional frame is Rx. */
    else if( LINIF_MSR_SLAVE_RESPONSE == LINIf_Frame_Cfg_Tab[frameHandle].pduDirection )
    {
        /* If reception was successful. */
        if( (Lin_StatusType)LIN_RX_OK == LinIf_LinStatus )
        {
            /* Inform PduR about received frame and data. */
            LinIf_ChannelDataPtr->pduRNotificationPduLength = LINIf_Frame_Cfg_Tab[frameHandle].lengthOfFrameList;
            lengthByte = LINIf_Frame_Cfg_Tab[frameHandle].lengthOfFrameList;
            for( indexTmp = LINIF_INIT_ZERO; indexTmp < lengthByte; indexTmp++ )
            {
                /* Copy Lin receive data to LinIf buffer for data consistency. */
                LinIf_ChannelDataPtr->LinIf_RxData[indexTmp & LINIF_LINPDU_SIZE_MASK]
                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_LinIf_NIV" */
                = LinIf_LinSduPtr[indexTmp & LINIF_LINPDU_SIZE_MASK];
            }
            /* If the current frame is not notified. */
            if( LINIF_SENDFRAME_BUSY == LinIf_ChannelDataPtr->LinIf_SendFrameStatus )
            {
                pduInfo.SduLength = LinIf_ChannelDataPtr->pduRNotificationPduLength;
                pduInfo.SduDataPtr = &(LinIf_ChannelDataPtr->LinIf_RxData[LINIF_INIT_ZERO]);
                LinIf_RxIndicationUL_Process(frameHandle, LinIf_ChannelDataPtr->pduRNotificationPduId, &pduInfo);
                /* Notification complete, reset status to LINIF_SENDFRAME_IDLE. */
                LinIf_ChannelDataPtr->LinIf_SendFrameStatus = LINIF_SENDFRAME_IDLE;
            }
        }
        else
        {
            if( (((Lin_StatusType)LIN_RX_BUSY == LinIf_LinStatus) &&
                  ((LINIF_INIT_ZERO == LinIf_ChannelDataPtr->frameMaxDelayCtn) ||
                   (LINIF_INIT_ONE == schedTabDataPtrTmp->currentSlotDelay))) ||
                ((Lin_StatusType)LIN_RX_ERROR == LinIf_LinStatus) ||
                ((Lin_StatusType)LIN_RX_NO_RESPONSE == LinIf_LinStatus) )
            {
#if( LINIF_DEV_ERROR_DETECT == STD_ON )
                /* Inform about error in transmitted frame */
                chkRslt = LINIF_E_RESPONSE;
#endif
            }
        }
    }
    else
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Do nothing. */
    }

#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( LINIF_E_NO_ERR != chkRslt )
    {
        LinIf_Det_ReportRuntimeError(LINIF_MAIN_FUNCTION, chkRslt);
    }
#endif

}

/*
********************************************************************************
* Function Name: LinIf_MessageProcessing_SRF
*
* Explanation: SRF frame process.
*
* param: LinIf_ChannelDataPtr: Channel data pointer.
*        LinIf_LinIfChannel: Channel index.
*        linSduPtrTmp: Message data.
*        linStatusTmp: Last message state.
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_MessageProcessing_SRF
(
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_ChannelDataPtr,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_CONST) linSduPtrTmp,
    uint8 LinIf_LinIfChannel,
    Lin_StatusType linStatusTmp
)
{
    uint8 errorId = LINIF_E_NO_ERR;
    LINIF_DUMMY_STATEMENT(LinIf_ChannelDataPtr);
    LINIF_DUMMY_STATEMENT(linSduPtrTmp);
    LINIF_DUMMY_STATEMENT(LinIf_LinIfChannel);
    LINIF_DUMMY_STATEMENT(linStatusTmp);

    /* If no node configuration response is expected. */
#if( LINIF_FIXEDFRAMESDULIST == STD_ON )
    if( LINIF_NODECONFIGCMD_IDLE == LinIf_ChannelDataPtr->nodeConfigurationCmd )
#endif
    {
#if( LINIF_TP_SUPPORTED == STD_ON )
        if( (Lin_StatusType)LIN_RX_OK == linStatusTmp )
        {
            /* LinTp SRF indicated check current state. */
            LinTp_RxIndication(LinIf_LinIfChannel, linSduPtrTmp);
        }
        else if( linStatusTmp == (Lin_StatusType)LIN_RX_NO_RESPONSE )
        {
            /* No response must be handled different for SlaveResp message to error in response. */
        }
        else if( ( linStatusTmp == (Lin_StatusType)LIN_RX_BUSY ) || ( linStatusTmp == (Lin_StatusType)LIN_RX_ERROR ) )
        {
            /* Error in node configuration slave response */
            errorId = LINIF_E_RESPONSE;
        }
        else
        {
            /* No handling required, MISRA only */
        }

#endif

    }

#if( LINIF_FIXEDFRAMESDULIST == STD_ON )
    else if( LINIF_NODECONFIGCMD_SENDSRF == LinIf_ChannelDataPtr->nodeConfigurationCmd )
    {
        LinIf_ChannelDataPtr->nodeConfigurationCmd = LINIF_NODECONFIGCMD_IDLE;
    }
    else
    {
        /* Do nothing. */
    }
#endif

#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    LinIf_Det_ReportRuntimeError(LINIF_MAIN_FUNCTION, errorId);
#else
    LINIF_DUMMY_STATEMENT(errorId);
#endif

}

#if( LINIF_EVT_FRM_SUPPORTED == STD_ON )
/*
********************************************************************************
* Function Name: LinIf_MessageProcessing_EventTriggeredFrame
*
* Explanation: EventTriggered frame process.
*
* param: LinIf_ChannelDataPtr: Channel data pointer.
*        LinIf_LinIfChannel: Channel index.
*        LinIf_LinSduPtr: Message data.
*        LinIf_LinStatus: Last message state.
*
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_MessageProcessing_EventTriggeredFrame
(
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_ChannelDataPtr,
    uint8 LinIf_LinIfChannel,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_CONST) LinIf_LinSduPtr,
    Lin_StatusType LinIf_LinStatus
)
{
    uint8  frmLengthByte = LINIF_INIT_ZERO;
    uint8  pidTmp = LINIF_INIT_ZERO;
    uint16 indexTmp = LINIF_INIT_ZERO;
    uint16 fixdFrameSduList = LINIF_INIT_ZERO;
    PduInfoType pduInfo = {NULL_PTR,LINIF_INIT_ZERO};
    /* If EVT frame is successfully received without collision, handle frame as any unconditional frame. */
    if( (Lin_StatusType)LIN_RX_OK == LinIf_LinStatus )
    {
        /* Evaluate first byte of frame for received PID to assign appropriate unconditional frame. */
        pidTmp = LinIf_LinSduPtr[LINIF_INIT_ZERO];
        fixdFrameSduList = LINIf_Frame_Cfg_Tab[LinIf_ChannelDataPtr->frameHandle].fixedFrameSduListIdxOfFrameList;
        /* Get the start index of the assigned unconditional frame of current EVT slot. */
        indexTmp = LinIf_EvtFrameInfo[fixdFrameSduList].evtUncFrmInfoStartIdx;

        /* Iterate over each unconditional frame assigned to the EVT slot and search for a match with the received frame indicated by the PID. */
        while( indexTmp < LinIf_EvtFrameInfo[LinIf_LinIfChannel].evtUncFrmInfoEndIdx )
        {
            /* PID match - convert current EVT frame information to unconditional frame info. */
            if( pidTmp == LinIf_EvtUnconditionalFrameInfo[indexTmp].pidOfEvtUncFrame )
            {
                /* Replace current frame information with flagged unconditional frame. */
                LinIf_ChannelDataPtr->frameHandle = LinIf_EvtUnconditionalFrameInfo[indexTmp].frmIdxOfEvtUncFrm;
                break;
            }
            indexTmp++;
        }

        /* If corresponding unconditional frame is found, inform PduR about received frame and data. */
        if( indexTmp < LinIf_EvtFrameInfo[LinIf_LinIfChannel].evtUncFrmInfoEndIdx )
        {
            frmLengthByte = LINIf_Frame_Cfg_Tab[LinIf_ChannelDataPtr->frameHandle].lengthOfFrameList;
            LinIf_ChannelDataPtr->pduRNotificationPduId = LINIf_Frame_Cfg_Tab[LinIf_ChannelDataPtr->frameHandle].pduIdOfFrameList;
            LinIf_ChannelDataPtr->pduRNotificationPduLength = frmLengthByte;

            /* Copy Lin receive data. */
            for( indexTmp = LINIF_INIT_ZERO; indexTmp < frmLengthByte; indexTmp++  )
            {
                LinIf_ChannelDataPtr->LinIf_RxData[indexTmp] = LinIf_LinSduPtr[indexTmp];
            }
            /* If have a frame is being sent, waiting for notification. */
            if( LINIF_SENDFRAME_BUSY == LinIf_ChannelDataPtr->LinIf_SendFrameStatus )
            {
                pduInfo.SduLength = LinIf_ChannelDataPtr->pduRNotificationPduLength;
                pduInfo.SduDataPtr = &(LinIf_ChannelDataPtr->LinIf_RxData[LINIF_INIT_ZERO]);
                LinIf_RxIndicationUL_Process(LinIf_ChannelDataPtr->frameHandle, LinIf_ChannelDataPtr->pduRNotificationPduId, &pduInfo);
                /* Notification complete, reset status to LINIF_SENDFRAME_IDLE. */
                LinIf_ChannelDataPtr->LinIf_SendFrameStatus = LINIF_SENDFRAME_IDLE;
            }
        }
    }
    /* Otherwise: */
    else
    {
        /* If error occurred, treat as collision and set collision resolving schedule table as pending. */
        if( ((Lin_StatusType)LIN_RX_BUSY == LinIf_LinStatus) || ((Lin_StatusType)LIN_RX_ERROR == LinIf_LinStatus) )
        {
            /* Collision on EVT frame detected. */
            if( LINIF_SCHEDULE_INVALID == LinIf_ChannelDataPtr->schedTabData.requestedTable )
            {
                /* Collision resolving is only started, if no schedule table change has been requested. */
                LinIf_ChannelDataPtr->schedTabData.requestedTable = LinIf_EvtFrameInfo[fixdFrameSduList].collisionResolvingRef;
                LinIf_ChannelDataPtr->schedTabData.evtCollResolvingState = LINIF_EVTCOLLRESOLVINGSTA_DETCED;
            }
            /* Else: schedule table change was requested before, so collision resolving is lost. */
        }
        /* If no response received, no slave has responded, nothing to do. */
        else
        {
            if( (Lin_StatusType)LIN_RX_NO_RESPONSE == LinIf_LinStatus )
            {
                /* Silent EVT frame - no further action required. */
            }
        }
    }
}
#endif

/*
********************************************************************************
* Function Name: LinIf_FlushAllSchedules
*
* Explanation: Reset all schedule table related variables.
*
* param: LinIf_LinIfChannel: Channel index.
*        LinIf_SchedTabDataPtr: LinIf_SchedTabDataPtr data pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_FlushAllSchedules
(
    uint8 LinIf_LinIfChannel,
    P2VAR(LinIf_SchedTabDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_SchedTabDataPtr
)
{
    uint8 nullScheTable;
    uint16 nullSchIdx;

    /* For each channel, the first configured schedule table is the NULL schedule. */
    nullSchIdx = LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].ScheduleTableListStartIdxOfChannelCfg;
    nullScheTable = (uint8)LinIf_ScheduleTableListInd[nullSchIdx];
    /* Reset all schedule table related variables, set NULL schedule table, abort collision resolving table. */
    LinIf_SchedTabDataPtr->currentTable            = nullScheTable;
    LinIf_SchedTabDataPtr->currentSlot             = (uint8)LINIF_INIT_ZERO;
    LinIf_SchedTabDataPtr->previousContinuousTable = (uint8)LINIF_INIT_ZERO;
    LinIf_SchedTabDataPtr->previousContinuousSlot  = (uint8)LINIF_INIT_ZERO;
    LinIf_SchedTabDataPtr->currentSlotDelay        = (LinIf_ScheduleTableTickType)LINIF_INIT_ZERO;
    LinIf_SchedTabDataPtr->requestedTable          = LINIF_SCHEDULE_INVALID;
    LinIf_SchedTabDataPtr->schedReqConfirmTable    = LINIF_SCHEDULE_INVALID;

#if( LINIF_EVT_FRM_SUPPORTED == STD_ON )
    LinIf_SchedTabDataPtr->evtCollResolvingState   = LINIF_EVTCOLLRESOLVINGSTA_IDLE;
#endif
}

/*
********************************************************************************
* Function Name: LinIf_MessageProcessing_SleepModeFrame
*
* Explanation: Sleep frame process.
*
* param: LinIf_ChannelDataPtr: Channel data pointer.
*        LinIf_LinIfChannel: Channel index.
*        LinIf_LinStatus: Last message state.
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_MessageProcessing_SleepModeFrame
(
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_ChannelDataPtr,
    uint8 LinIf_LinIfChannel,
    Lin_StatusType LinIf_LinStatus
)
{
    uint8 channelRef;
    /* Get ref channel index. */
    channelRef = LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].linChannelIdRef;

    /* If sleep mode frame state is still on transmission. */
    if( LINIF_ONSLRRPMODEFRM_ONTRANS == LinIf_ChannelDataPtr->sleepModeFrameHandle )
    {
        LinIf_ChannelDataPtr->sleepModeFrameHandle = LINIF_ONSLRRPMODEFRM_IDLE;

        /* If driver reported sleep status. */
        if( (Lin_StatusType)LIN_CH_SLEEP == LinIf_LinStatus )
        {
            /* Enter sleep state and inform LinSM. */
            /* Reset all schedule table related variables, set NULL schedule table, abort collision resolving table. */
            LinIf_FlushAllSchedules(LinIf_LinIfChannel, &(LinIf_ChannelDataPtr->schedTabData));

            LinIf_ChannelDataPtr->channelState = LINIF_CHANNEL_SLEEP;
            LinIf_GoToSleepConfirmationUL_Process(LinIf_LinIfChannel, LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].ComMChannelRef, TRUE);
        }
        else
        {
            LinIf_ChannelDataPtr->wakeupDelayTimer = LINIF_GET_WAKEUP_DELAY_EXTER_TIME(LinIf_LinIfChannel);
            LinIf_GoToSleepConfirmationUL_Process(LinIf_LinIfChannel, LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].ComMChannelRef, FALSE);
        }
    }
    /* Otherwise if a wakeup request occured during sleep mode frame transmission. */
    else if( LINIF_ONSLRRPMODEFRM_ONREWAKEINT == LinIf_ChannelDataPtr->sleepModeFrameHandle )
    {
        /* Remain in operational state, do not inform the higher layer (sleep state not reached according to spec). */
        LinIf_ChannelDataPtr->channelState = LINIF_CHANNEL_OPERATIONAL;
        /* SWS_LinIf_00460 */
        if( (Lin_StatusType)LIN_CH_SLEEP == LinIf_LinStatus )
        {
            /* Reset frame delay to check wakeup frame in next cycle and reload wakeup delay timer. */
            LinIf_ChannelDataPtr->sleepModeFrameHandle = LINIF_ONWAKEUPFRM_ONTRANS;
            LinIf_ChannelDataPtr->currentFrameType = LINIF_FRMTYPE_WAKEUPFRAME;
            LinIf_ChannelDataPtr->frameMaxDelayCtn = (LinIf_ScheduleTableTickType)LINIF_INIT_ONE;
            /* Set Lin send frame status is LINIF_SENDFRAME_BUSY. */
            LinIf_ChannelDataPtr->LinIf_SendFrameStatus = LINIF_SENDFRAME_BUSY;
            LinIf_ChannelDataPtr->wakeupDelayTimer = LINIF_GET_WAKEUP_DELAY_INTERNAL_TIME(LinIf_LinIfChannel);

#if( LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON )
            (void)LinIf_LinMultipeDrvInfo[LinIf_Channl_Cfg_Tab[LinIf_LinIfChannel].ctrlId].LinIf_Lin_WakeupFunc(channelRef);
#else
            /* Polyspace +1 MISRA-C3:17.3 [Justified:Unset] "NSCA_Polyspace_LinIf_Rule17.3" */
            (void)Lin_Wakeup(channelRef);
#endif      /* LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON */
        }
    }
    else
    {
        /* Do nothing. */
    }
}

/*
********************************************************************************
* Function Name: LinIf_MainFunctionPostProcessing
*
* Explanation: Main function process.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_MainFunctionPostProcessing
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    uint8 LinIfChannel
)
{
    LinIf_ChannelDataType* channelDataPtrTmp = NULL_PTR;

#if( LINIF_TP_SUPPORTED == STD_ON )
    uint8 linTpChannelTmp;
    LinTp_ControlType* tpCtrlTmp = NULL_PTR;
#endif

    channelDataPtrTmp = &LinIf_ChannelData[LinIfChannel];
    if( LINIF_CHANNEL_MASTER == LinIf_Channl_Cfg_Tab[LinIfChannel].nodeChannelType )
    {
#if( LINIF_TP_SUPPORTED == STD_ON )
        /* LinTp diagnostic schedule change notification. */
        tpCtrlTmp = &LinTp_Ctrl.raw[LinIfChannel];

        linTpChannelTmp = LinTp_LinIfToLinTpChannel[LinIfChannel];

        if( tpCtrlTmp->linTp_PortNotifity != (uint8)LINTP_PORTNOTIFITY_IDLE )
        {
            if( (boolean)TRUE == LinTp_ChannelConfigData[linTpChannelTmp]->schedChangeNotifyOfChannelCfg )
            {
#if( LINTP_BSWMENABLED == STD_ON )
                /* Polyspace +1 MISRA-C3:10.5 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
                (void)BswM_LinTp_RequestMode(LinIf_Channl_Cfg_Tab[LinIfChannel].ComMChannelRef, (LinTp_Mode)(tpCtrlTmp->linTp_PortNotifity));  /* PRQA S 4342 */ /* NSCA_QAC_LinIf_Rule10.5 */
#endif
            }

            /* Clear notification. */
            tpCtrlTmp->linTp_PortNotifity = (uint8)LINTP_PORTNOTIFITY_IDLE;
        }

#endif
        /* LinSM notification and confirmations. */
        /* Inform LinSM or CDD about schedule table handling. */
        LinIf_ScheduleRequestCfr_Process(channelDataPtrTmp, LinIfChannel);

#if( LINIF_TP_SUPPORTED == STD_ON )
        /* LinTp post notification to the PduR of last transmitted/ received TP message */
        if( (tpCtrlTmp->linTp_PduRNotifity & LINTP_PDURNOTIFITY_TX) != LINTP_PDURNOTIFITY_IDLE )
        {
            /* Report transmitted frame to PduR with enabled interrupts */
            (void)PduR_LinTpTxConfirmation(tpCtrlTmp->linTp_PduRNSduIdTx, tpCtrlTmp->linTp_PduRNotifyResultTx);
        }
        if( (tpCtrlTmp->linTp_PduRNotifity & LINTP_PDURNOTIFITY_RX) != LINTP_PDURNOTIFITY_IDLE )
        {
            /* Report received frame to PduR with enabled interrupts */
            (void)PduR_LinTpRxIndication(tpCtrlTmp->linTp_PduRNSduIdRx, tpCtrlTmp->linTp_PduRNotifyResultRx);
        }
        /* LinTp post notification to the PduR of last requested TP message of LinTp_Transmit */
        if( (tpCtrlTmp->linTp_PduRNotifity & LINTP_PDURNOTIFITY_TXTM) != LINTP_PDURNOTIFITY_IDLE )
        { 
                /* report transmitted frame to PduR with enabled interrupts */
            (void)PduR_LinTpTxConfirmation(tpCtrlTmp->linTp_PduRNSduIdTm, E_NOT_OK);
        }
        /* Clear pending notification to PduR if set. */
        tpCtrlTmp->linTp_PduRNotifity = LINTP_PDURNOTIFITY_IDLE;
#endif
    }
}

/*
********************************************************************************
* Function Name: LinIf_ScheduleRequestCfr_Process
*
* Explanation: LinSM schedule request confirmation.
*
* param: channelDataPtrTmp: Channel data pointer.
*        linIfChannelTmp: Channel index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_ScheduleRequestCfr_Process
(
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) channelDataPtrTmp,
    uint8 linIfChannelTmp
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    uint8 channelRef = LinIf_Channl_Cfg_Tab[linIfChannelTmp].ComMChannelRef;

    /* Report schedule table change confirmation if notification is pending. */
    /* Delayed schedule request confirmation to LinSM. */
    if( channelDataPtrTmp->schedTabData.schedReqConfirmTable != LINIF_SCHEDULE_INVALID )
    {
        LinIf_ScheduleRequestConfirmationUL_Process(linIfChannelTmp,
            channelRef, channelDataPtrTmp->schedTabData.schedReqConfirmTable);

        /* Invalidate schedule request confirmation notification flag. */
        channelDataPtrTmp->schedTabData.schedReqConfirmTable = LINIF_SCHEDULE_INVALID;
    }
}

/*
********************************************************************************
* Function Name: LinIf_ChannelInit
*
* Explanation: Channel state init.
*
* param: linIfChannelTmp: Channel index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_ChannelInit
(
    uint8 linIfChannelTmp
)
{
    uint8 channelRef;
    LinIf_ChannelDataType* channelDataPtrTmp = &LinIf_ChannelData[linIfChannelTmp];

    channelDataPtrTmp->frameMaxDelayCtn = LINIF_INIT_ZERO;
    /* Set Lin send frame status is LINIF_SENDFRAME_IDLE. */
    channelDataPtrTmp->LinIf_SendFrameStatus = LINIF_SENDFRAME_IDLE;
    channelDataPtrTmp->frameHandle = LINIF_INIT_ZERO;
    channelDataPtrTmp->sleepModeFrameHandle = LINIF_ONSLRRPMODEFRM_IDLE;

#if( LINIF_FIXEDFRAMESDULIST == STD_ON )
    channelDataPtrTmp->nodeConfigurationCmd = LINIF_NODECONFIGCMD_IDLE;
#endif

#if( LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON ) || ( LINIF_TRCV_WAKEUP_SUPPORT == STD_ON )
    channelDataPtrTmp->wakeupFlag = LINIF_INIT_ZERO;
#endif
    channelDataPtrTmp->wakeupDelayTimer = LINIF_INIT_ZERO;
    channelDataPtrTmp->pduRNotification = LINIF_PDURNOTIFICATIONIDLE;
    channelDataPtrTmp->busMaxIdleCnt = LinIf_Channl_Cfg_Tab[linIfChannelTmp].channelIdleCnt;
    channelDataPtrTmp->reqWakeUpFlag = FALSE;

#if( LINIF_SLAVE_SUPPORT == STD_ON )
    channelDataPtrTmp->txFrameConfirmFlag = FALSE;
    channelDataPtrTmp->rxFrameReceiveFlag = FALSE;
    channelDataPtrTmp->firstReceiveHeaderFlag = LINIF_INIT_ZERO;
    channelDataPtrTmp->nodeWakeUpFlag = LINIF_INIT_ZERO;
    channelDataPtrTmp->goToSleepCommandFlag = FALSE;
#endif

    /* Clear schedule table data and set NULL schedule table. */
    LinIf_FlushAllSchedules(linIfChannelTmp, &(channelDataPtrTmp->schedTabData));

#if( LINIF_SCHEDULE_END_NOTIFICATION == STD_ON )
    channelDataPtrTmp->schedTabData.schedEndNotifyTable = LINIF_SCHEDULE_INVALID;
#endif
    channelDataPtrTmp->schedTabData.schedReqConfirmTable = LINIF_SCHEDULE_INVALID;
    channelRef = LinIf_Channl_Cfg_Tab[linIfChannelTmp].linChannelIdRef;
    /* Set channel to sleep mode */
    channelDataPtrTmp->channelState = LINIF_CHANNEL_SLEEP;

    /* Set Lin driver channel to sleep mode. */
#if( LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON )
    (void)LinIf_LinMultipeDrvInfo[(LinIf_Channl_Cfg_Tab[linIfChannelTmp].ctrlId)].LinIf_Lin_GoToSleepInternalFunc(channelRef);
#else
    /* Polyspace +1 MISRA-C3:17.3 [Justified:Unset] "NSCA_Polyspace_LinIf_Rule17.3" */
    (void)Lin_GoToSleepInternal(channelRef);
#endif

}

/*
********************************************************************************
* Function Name: LinIf_Init
*
* Explanation: Initializes the LIN Interface.(Synchronous)
*
* param: ConfigPtr:Pointer to the LIN Interface configuration.
*
* retval: None
********************************************************************************
*/
FUNC(void, LINIF_CODE) LinIf_Init
(
    P2CONST(LinIf_CongfigType, AUTOMATIC, LINIF_APPL_CONST) ConfigPtr
)
{
    uint8 indexTmp;
    uint8 errorId = LINIF_E_NO_ERR;

    LINIF_DUMMY_STATEMENT(ConfigPtr);

    if( (boolean)TRUE == LinIf_Init_Finish )
    {
        errorId = LINIF_E_ALREADY_INITIALIZED;
    }
    else
    {
        for( indexTmp = LINIF_INIT_ZERO; indexTmp < LinIf_GetSizeOfChannelData(); indexTmp++ )
        {
            LinIf_ChannelData[indexTmp].channelState = LINIF_CHANNEL_UNINIT;
            LinIf_ChannelInit(indexTmp);
        }

        /* Clear sporadic transmission flags of all sporadic slots. */
#if( LINIF_SPORADIC_FRM_SUPPORTED == STD_ON )
        for( indexTmp = LINIF_INIT_ZERO; indexTmp < LINIF_SPORADIC_FRM_NUMBER; indexTmp++ )
        {
            LinIf_SetSporTransmitFlags(indexTmp, LINIF_INIT_ZERO);
        }
#endif

        LinIf_Init_Finish = TRUE;
    }

#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( errorId != LINIF_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinIf_Det_ErrorReport(LINIF_INIT, errorId);
    }
#else
    LINIF_DUMMY_STATEMENT(errorId);
#endif
}

#if( LINIF_VERSION_INFO_API == STD_ON )
/*
********************************************************************************
* Function Name: LinIf_GetVersionInfo
*
* Explanation: Service to get the version information of LinIf module.(Synchronous)
*
* param: versioninfo:Pointer to where to store the version information of this module.
*
* retval: None
********************************************************************************
*/
FUNC(void, LINIF_CODE) LinIf_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, LINIF_APPL_DATA) versioninfo
)
{
    uint8 chkRslt = LINIF_E_NO_ERR;

    if( NULL_PTR == versioninfo )   /* Pointer parameter is Null. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        chkRslt = LINIF_E_PARAM_POINTER;
    }
    else
    {
        /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.14" Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_LinIf_TAINTED_PTR" */
        versioninfo->vendorID = LINIF_VENDOR_ID;
        versioninfo->moduleID = LINIF_MODULE_ID;
        versioninfo->sw_major_version = LINIF_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = LINIF_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = LINIF_SW_PATCH_VERSION;
    }

#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( LINIF_E_NO_ERR != chkRslt ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinIf_Det_ErrorReport(LINIF_GET_VERSION_INFO, chkRslt);
    }
#else
    LINIF_DUMMY_STATEMENT(chkRslt);
#endif
}
#endif

/*
********************************************************************************
* Function Name: LinIf_Transmit
*
* Explanation: Service to indicates a request.(Asynchronous)
*
* param: LinTxPduId: Upper layer identification of the LIN frame to be transmitted.
*        PduInfoPtr: Pointer to a structure with frame related data: DLC and pointer
*                    to frame data buffer. This parameter is not used by this call.
*
* retval: E_OK: Transmit request has been accepted.
*         E_NOT_OK: Transmit request has not been accepted due to one or more reasons:
*                   - LIN Interface has not been initialized
*                   - referenced PDU does not exist (identification is out of range)
*                   - NULL_SCHEDULE is set
********************************************************************************
*/
FUNC(Std_ReturnType, LINIF_CODE) LinIf_Transmit
(
    PduIdType LinTxPduId,
    P2CONST(PduInfoType, AUTOMATIC, LINIF_APPL_CONST) PduInfoPtr
)
{
    uint8 chkRslt;
    Std_ReturnType rtrnValu  = E_NOT_OK;

#if( LINIF_SPORADIC_FRM_SUPPORTED == STD_ON )
    uint8 indexTmp = LINIF_INIT_ZERO;
    uint8 byteMskTmp = LINIF_INIT_ZERO;
    uint8 bitMskTmp = LINIF_INIT_ZERO;
#endif

    LINIF_DUMMY_STATEMENT(PduInfoPtr);
    chkRslt = LinIf_Chk_Transmit(LinTxPduId, PduInfoPtr);   /* Error check. */
    if( LINIF_E_NO_ERR == chkRslt ) /* No error detected. */
    {
#if( LINIF_SPORADIC_FRM_SUPPORTED == STD_ON )
        if( LINIF_INIT_ZERO != LINIF_SPORADIC_FRM_NUMBER )
        {
            /* Sporadic frames exist in current configuration */
            for( indexTmp = LINIF_INIT_ZERO; indexTmp < LINIF_SPORADIC_FRM_NUMBER; indexTmp++ )
            {
                if( LinIf_SporadicFrameLookupTable[indexTmp].txPduId == LinTxPduId )
                {
                    /* LinTxPduId matches - set transmit request flag */
                    byteMskTmp = LinIf_SporadicFrameLookupTable[indexTmp].byteMskOfSporFrm;
                    bitMskTmp  = LinIf_SporadicFrameLookupTable[indexTmp].bitMskOfSporFrm;
                    LinIf_SetSporTransmitFlags(byteMskTmp, (LinIf_GetSporTransmitFlags(byteMskTmp) | bitMskTmp));
                    break;
                }
            }
        }
#endif
        rtrnValu = (Std_ReturnType)E_OK;
    }

#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( LINIF_E_NO_ERR != chkRslt ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinIf_Det_ErrorReport(LINIF_TRANSMIT, chkRslt);
    }
#else
    LINIF_DUMMY_STATEMENT(chkRslt);
#endif

    return rtrnValu;
}

#if( LINIF_MASTER_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: LinIf_ScheduleRequest
*
* Explanation: Service to requests a schedule table to be executed.(Asynchronous)
*
* param: Channel: Channel index.
*        Schedule: Identification of the new schedule to be set.
*
* retval: E_OK: Schedule table request has been accepted.
*         E_NOT_OK: Schedule table switch request has not been due to one or more reasons:
*                   - LIN Interface has not been initialized
*                   - referenced channel does not exist (identification is out of range)
*                   - referenced schedule table does not exist (identification is out of range)
*                   - State is sleep
********************************************************************************
*/
FUNC(Std_ReturnType, LINIF_CODE) LinIf_ScheduleRequest
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" Polyspace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_LinIf_IdentifierCheck" Polyspace +1 MISRA-C3:5.8 [Justified:Unset] "NSCA_Polyspace_LinIf_IdentifierCheck" */
    LinIf_SchHandleType Schedule  /* PRQA S 3334 */ /* NSCA_QAC_LinIf_Rule5.3 */
)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint8 index;
    uint8 errId;
    uint16 chkRslt;

    LinIf_ChannelDataType* channelDataPtrTmp = NULL_PTR;

    chkRslt = LinIf_Chk_ScheduleRequest(Channel, Schedule);
    index = (uint8)(chkRslt >> LINIF_SHIFT_8BIT);
    errId = (uint8)chkRslt;

    if( LINIF_E_NO_ERR == errId )
    {
        if( LINIF_CHANNEL_MASTER == LinIf_Channl_Cfg_Tab[index].nodeChannelType )
        {
            channelDataPtrTmp = &LinIf_ChannelData[index];

            /* Store the requested schedule and mark it pending (to be set after the next slot). */
            channelDataPtrTmp->schedTabData.requestedTable = Schedule;

            /* Abort a possibly ongoing event-triggered frame collision resolving handling. */
#if( LINIF_EVT_FRM_SUPPORTED == STD_ON )
            /* Collision resolving table is discontinued on a new schedule request. */
            channelDataPtrTmp->schedTabData.evtCollResolvingState
              = LINIF_EVTCOLLRESOLVINGSTA_IDLE;
#endif
            rtrnValu = (Std_ReturnType)E_OK;
        }
    }
    else
    {
        /* Do nothing */
    }

#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( errId != LINIF_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinIf_Det_ErrorReport(LINIF_SCHEDULE_REQUEST, errId);
    }
#else
    LINIF_DUMMY_STATEMENT(chkRslt);
#endif

    return rtrnValu;
}
#endif /* LINIF_MASTER_SUPPORT == STD_ON */

/*
********************************************************************************
* Function Name: LinIf_GotoSleep
*
* Explanation: Initiates a transition into the Sleep Mode on the selected channel.(Asynchronous)
*
* param: Channel: Identification of the LIN channel.
*
* retval: E_OK: Request to go to sleep has been accepted or sleep transition is
*               already in progress or controller is already in sleep state.
*         E_NOT_OK: Request to go to sleep has not been accepted due to one or more of the following reasons:
*                   - LIN Interface has not been initialized
*                   - referenced channel does not exist (identification is out of range)
********************************************************************************
*/
FUNC(Std_ReturnType, LINIF_CODE) LinIf_GotoSleep
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel
)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint8 index;
    uint8 errId;
    uint16 chkRslt;

    LinIf_ChannelDataType* channelDataPtrTmp = NULL_PTR;
    uint8 channelRef;

    chkRslt = LinIf_Chk_GotoSleep(Channel);
    index = (uint8)(chkRslt >> LINIF_SHIFT_8BIT);
    errId = (uint8)chkRslt;

    if( LINIF_E_NO_ERR == errId )
    {
        channelDataPtrTmp = &LinIf_ChannelData[index];
        channelRef = LinIf_Channl_Cfg_Tab[index].linChannelIdRef;
        if( LINIF_CHANNEL_MASTER == LinIf_Channl_Cfg_Tab[index].nodeChannelType )
        {
            /* If channel state is operational. */
            if( LINIF_CHANNEL_OPERATIONAL == channelDataPtrTmp->channelState )
            {
                if( (LINIF_ONSLRRPMODEFRM_IDLE == channelDataPtrTmp->sleepModeFrameHandle)
                    || (LINIF_ONWAKEUPFRM_ONTRANS == channelDataPtrTmp->sleepModeFrameHandle) )
                {
                    /* Only set new request if not already on processing a request. */
                    channelDataPtrTmp->sleepModeFrameHandle = LINIF_ONSLRRPMODEFRM_ONREQ;
                }
            }
            /* Otherwise if channel state is sleep. */
            else if( LINIF_CHANNEL_SLEEP == channelDataPtrTmp->channelState )
            {
                if( (LINIF_ONSLRRPMODEFRM_IDLE == channelDataPtrTmp->sleepModeFrameHandle)
                    || (LINIF_ONWAKEUPFRM_ONTRANS == channelDataPtrTmp->sleepModeFrameHandle) )
                {
                    channelDataPtrTmp->sleepModeFrameHandle = LINIF_ONSLRRPMODEFRM_ONREQINT;
                }
            }
            else
            {
                /* Do nothing */
            }
            rtrnValu = (Std_ReturnType)E_OK;
        }
        else if( LINIF_CHANNEL_SLAVE == LinIf_Channl_Cfg_Tab[index].nodeChannelType )
        {
            /* [SWS_LinIf_00757]: When the function LinIf_GotoSleep is called, the LIN Interface 
               shall call the function Lin_GotoSleepInternal directly */
            /* Set Lin driver channel to sleep mode. */
            if( LINIF_CHANNEL_OPERATIONAL == channelDataPtrTmp->channelState )
            {
#if( LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON )
                rtrnValu = LinIf_LinMultipeDrvInfo[(LinIf_Channl_Cfg_Tab[index].ctrlId)].LinIf_Lin_GoToSleepInternalFunc(channelRef);
#else
                /* Polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" Polyspace +1 MISRA-C3:17.3 [Justified:Unset] "NSCA_Polyspace_LinIf_Rule17.3" */
                rtrnValu = Lin_GoToSleepInternal(channelRef);
#endif

                if( E_OK == rtrnValu )
                {
#if( LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON ) || ( LINIF_TRCV_WAKEUP_SUPPORT == STD_ON )
                    channelDataPtrTmp->wakeupFlag = LINIF_INIT_ZERO;
#endif
                    channelDataPtrTmp->channelState = LINIF_CHANNEL_SLEEP;
                }
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            /* Do nothing */
        }
    }

#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( errId != LINIF_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinIf_Det_ErrorReport(LINIF_GO_TO_SLEEP, errId);
    }
#else
    LINIF_DUMMY_STATEMENT(errId);
#endif

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: LinIf_Wakeup
*
* Explanation: Initiates the wake up process.(Asynchronous)
*
* param: Channel: Identification of the LIN channel.
*
* retval: E_OK: Request to wake up has been accepted or the controller is not in sleep state.
*         E_NOT_OK: Request to wake up has not been accepted due to one or more of the following reasons:
*                   - LIN Interface has not been initialized
*                   - referenced channel does not exist (identification is out of range)
*                   - Lin_Wakeup has returned E_NOT_OK
*                   - Lin_WakeupInternal has returned E_NOT_OK
********************************************************************************
*/
FUNC(Std_ReturnType, LINIF_CODE) LinIf_Wakeup
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel
)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint8 index;
    uint8 errId;
    uint16 chkRslt;

    LinIf_ChannelDataType* channelDataPtrTmp = NULL_PTR;

    chkRslt = LinIf_Chk_Wakeup(Channel);
    index = (uint8)(chkRslt >> LINIF_SHIFT_8BIT);
    errId = (uint8)chkRslt;

    if( LINIF_E_NO_ERR == errId )
    {
        channelDataPtrTmp = &LinIf_ChannelData[index];
#if( (LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON) || (LINIF_TRCV_WAKEUP_SUPPORT == STD_ON) )
        if( LINIF_INIT_ZERO == channelDataPtrTmp->wakeupFlag )
#endif
        {
            channelDataPtrTmp->reqWakeUpFlag = TRUE;
        }
        /* If channel state is operational */
        if( LINIF_CHANNEL_OPERATIONAL == channelDataPtrTmp->channelState )
        {
            /* If a gotosleep transition has been requested but not been started. */
            if( LINIF_ONSLRRPMODEFRM_ONREQ == channelDataPtrTmp->sleepModeFrameHandle )
            {
                channelDataPtrTmp->sleepModeFrameHandle = LINIF_ONSLRRPMODEFRM_IDLE;
                LinIf_WakeupConfirmationUL_Process(index, LinIf_Channl_Cfg_Tab[index].ComMChannelRef, FALSE);
            }
            /* If a gotosleep frame is currently transmitted. */
            else if( LINIF_ONSLRRPMODEFRM_ONTRANS == channelDataPtrTmp->sleepModeFrameHandle )
            {
                channelDataPtrTmp->sleepModeFrameHandle = LINIF_ONSLRRPMODEFRM_ONREWAKEINT;
            }
            /* Otherwise just confirm the wakeup to upper layer because the state is already operational. */
            else
            {
                LinIf_WakeupConfirmationUL_Process(index, LinIf_Channl_Cfg_Tab[index].ComMChannelRef, TRUE);
            }

            /* Channel is not in the sleep state, forward the call to the LIN driver, return E_OK . */
            rtrnValu = E_OK;
        }
        /* Otherwise if channel state is sleep. */
        else if( LINIF_CHANNEL_SLEEP == channelDataPtrTmp->channelState )
        {
            /* Only accept WakeUp in sleep state. */
            channelDataPtrTmp->channelState = LINIF_CHANNEL_OPERATIONAL;

#if( (LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON) || (LINIF_TRCV_WAKEUP_SUPPORT == STD_ON) )
            if( LINIF_INIT_ZERO == channelDataPtrTmp->wakeupFlag )
#endif
            {
                /* Wakeup frame has been started, but has not yet been checked. */
                channelDataPtrTmp->sleepModeFrameHandle = LINIF_ONWAKEUPFRM_ONTRANS;
                channelDataPtrTmp->currentFrameType     = LINIF_FRMTYPE_WAKEUPFRAME;

                /* Check status of LIN Driver in next main function call. */
                channelDataPtrTmp->frameMaxDelayCtn = (LinIf_ScheduleTableTickType)LINTP_INIT_ONE;
                /* Set Lin send frame status is LINIF_SENDFRAME_BUSY. */
                channelDataPtrTmp->LinIf_SendFrameStatus = LINIF_SENDFRAME_BUSY;

                /* No external wakeup was indicated previously */
#if( LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON )
                rtrnValu = LinIf_LinMultipeDrvInfo[LinIf_Channl_Cfg_Tab[index].ctrlId].LinIf_Lin_WakeupFunc(LinIf_Channl_Cfg_Tab[index].linChannelIdRef);
#else
                /* Polyspace +1 MISRA-C3:17.3 [Justified:Unset] "NSCA_Polyspace_LinIf_Rule17.3" */
                rtrnValu = (Std_ReturnType)Lin_Wakeup(LinIf_Channl_Cfg_Tab[index].linChannelIdRef);
#endif

                /* Start internal wakeup delay */
                channelDataPtrTmp->wakeupDelayTimer = LINIF_GET_WAKEUP_DELAY_INTERNAL_TIME(index);
            }
#if( (LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON) || (LINIF_TRCV_WAKEUP_SUPPORT == STD_ON) )
            else  /* The external wakeup flag is set. */
            {
#if( LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON )
                rtrnValu = LinIf_LinMultipeDrvInfo[LinIf_Channl_Cfg_Tab[index].ctrlId].LinIf_Lin_WakeupInternalFunc(LinIf_Channl_Cfg_Tab[index].linChannelIdRef);
#else
                rtrnValu = (Std_ReturnType)Lin_WakeupInternal(LinIf_Channl_Cfg_Tab[index].linChannelIdRef);
#endif  /* LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON */

                if( (Std_ReturnType)E_OK == rtrnValu )
                {
                    /* Clear the wakeup flag of the selected channel. */
#if( LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON ) || ( LINIF_TRCV_WAKEUP_SUPPORT == STD_ON )
                    channelDataPtrTmp->wakeupFlag = LINIF_INIT_ZERO;
#endif
                    LinIf_WakeupConfirmationUL_Process(index, LinIf_Channl_Cfg_Tab[index].ComMChannelRef, TRUE);
                }
                else
                {
                    LinIf_WakeupConfirmationUL_Process(index, LinIf_Channl_Cfg_Tab[index].ComMChannelRef, FALSE);
                }

                /* Start external wakeup delay */
                channelDataPtrTmp->wakeupDelayTimer = LINIF_GET_WAKEUP_DELAY_EXTER_TIME(index);
            }
#endif
        }
        else
        {
            /* Do nothing. */
        }
#if( LINIF_SLAVE_SUPPORT == STD_ON )
        if( (Std_ReturnType)E_OK == rtrnValu )
        {
            channelDataPtrTmp->nodeWakeUpFlag = LINIF_INIT_ONE;
            channelDataPtrTmp->firstReceiveHeaderFlag = LINIF_INIT_ZERO;
        }
#endif /* LINIF_SLAVE_SUPPORT == STD_ON */
    }

#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( errId != LINIF_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinIf_Det_ErrorReport(LINIF_WAKE_UP, errId);
    }
#else
    LINIF_DUMMY_STATEMENT(errId);
#endif

    return rtrnValu;
}

#if( LINIF_TRCV_DRIVER_SUPPORTED == STD_ON )
/*
********************************************************************************
* Function Name: LinIf_SetTrcvMode
*
* Explanation: Set the given LIN transceiver to the given mode.(Synchronous)
*
* param: Channel: Identification of the LIN channel.
*        TransceiverMode: Requested mode transition.
*
* retval: E_OK: Will be returned, if the transceiver state has been changed to the requested mode.
*         E_NOT_OK: Will be returned, if the transceiver state change has failed
*                   or the parameter is out of the allowed range. The previous
*                   state has not been changed.
********************************************************************************
*/
FUNC(Std_ReturnType, LINIF_CODE) LinIf_SetTrcvMode
(
    NetworkHandleType Channel,
    LinTrcv_TrcvModeType TransceiverMode
)
{
    Std_ReturnType rtrnValu  = E_NOT_OK;
    uint8 index;
    uint8 errId;
    uint8 LinNetwork = LINIF_INIT_ZERO;
    uint16 chkRslt = LINIF_E_NO_ERR;

    chkRslt = LinIf_Chk_SetTrcvMode(Channel,TransceiverMode);
    index = (uint8)(chkRslt >> LINIF_SHIFT_8BIT);
    errId = (uint8)chkRslt;

    if( LINIF_E_NO_ERR == errId )
    {
        LinNetwork = LinIf_Channl_Cfg_Tab[index].trcvIndexRef;
        rtrnValu = LinTrcv_SetOpMode(LinNetwork, TransceiverMode);
    }

#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( errId != LINIF_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinIf_Det_ErrorReport(LINIF_SET_TRCV_MODE, errId);
    }
#else
    LINIF_DUMMY_STATEMENT(errId);
#endif

    return rtrnValu;
}
#endif /* #if(LINIF_TRCV_HANDLING == STD_ON ) */


#if( LINIF_TRCV_DRIVER_SUPPORTED == STD_ON )
/*
********************************************************************************
* Function Name: LinIf_GetTrcvMode
*
* Explanation: Set the given LIN transceiver to the given mode.(Synchronous)
*
* param: Channel: Identification of the LIN channel.
*        TransceiverModePtr: Pointer to a memory location where output value will be stored.
*
* retval: E_OK: The call of the LIN Transceiver Driver's API service has returned E_OK.
*         E_NOT_OK: The call of the LIN Transceiver Driver's API service has returned
*                   E_NOT_OK or channel parameter is invalid or pointer is NULL.
********************************************************************************
*/
FUNC(Std_ReturnType, LINIF_CODE) LinIf_GetTrcvMode
(
    NetworkHandleType Channel,
    P2VAR(LinTrcv_TrcvModeType, AUTOMATIC, LINIF_APPL_DATA) TransceiverModePtr
)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint8 index;
    uint8 errId;
    uint16 chkRslt = LINIF_E_NO_ERR;
    uint8 LinNetwork = LINIF_INIT_ZERO;

    chkRslt = LinIf_Chk_GetTrcvMode(Channel, TransceiverModePtr);
    index = (uint8)(chkRslt >> LINIF_SHIFT_8BIT);
    errId = (uint8)chkRslt;

    if( LINIF_E_NO_ERR == errId )
    {
        LinNetwork = LinIf_Channl_Cfg_Tab[index].trcvIndexRef;
        rtrnValu = LinTrcv_GetOpMode(LinNetwork, TransceiverModePtr);
    }

#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( errId != LINIF_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinIf_Det_ErrorReport(LINIF_GET_TRCV_MODE, errId);
    }
#else
    LINIF_DUMMY_STATEMENT(errId);
#endif

    return rtrnValu;
}
#endif

#if(LINIF_TRCV_DRIVER_SUPPORTED == STD_ON )
/*
********************************************************************************
* Function Name: LinIf_GetTrcvWakeupReason
*
* Explanation: Returns the reason for the wake up that has been detected by the
*              LIN Transceiver Driver.(Synchronous)
*
* param: Channel: Identification of the LIN channel.
*        TrcvWuReasonPtr: Pointer to a memory location where output value will be stored.
*
* retval: E_OK: The call of the LIN Transceiver Driver's API service has returned E_OK.
*         E_NOT_OK: The call of the LIN Transceiver Driver's API service has returned
*                   E_NOT_OK or channel parameter is invalid or pointer is NULL.
********************************************************************************
*/
FUNC(Std_ReturnType, LINIF_CODE) LinIf_GetTrcvWakeupReason
(
    NetworkHandleType Channel,
    P2VAR(LinTrcv_TrcvWakeupReasonType, AUTOMATIC, LINIF_APPL_DATA) TrcvWuReasonPtr
)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint8 index;
    uint8 errId;
    uint8 LinNetwork = LINIF_INIT_ZERO;
    uint16 chkRslt = LINIF_E_NO_ERR;

    chkRslt = LinIf_Chk_GetTrcvWakeupReason(Channel, TrcvWuReasonPtr);
    index = (uint8)(chkRslt >> LINIF_SHIFT_8BIT);
    errId = (uint8)chkRslt;

    if( LINIF_E_NO_ERR == errId )
    {
        LinNetwork = LinIf_Channl_Cfg_Tab[index].trcvIndexRef;
        rtrnValu = LinTrcv_GetBusWuReason(LinNetwork, TrcvWuReasonPtr);
    }

#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( LINIF_E_NO_ERR != errId ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinIf_Det_ErrorReport(LINIF_GET_TRCV_WAKE_UP_REASON, errId);
    }
#else
    LINIF_DUMMY_STATEMENT(errId);
#endif

    return rtrnValu;
}
#endif

#if(LINIF_TRCV_DRIVER_SUPPORTED == STD_ON )
/*
********************************************************************************
* Function Name: LinIf_SetTrcvWakeupMode
*
* Explanation: Enables, disables and clears the notification for wakeup events on
*              the addressed network.(Synchronous)
*
* param: Channel: Identification of the LIN channel.
*        LinTrcvWakeupMode: Requested transceiver wake up reason.
*
* retval: E_OK: The call of the LIN Transceiver Driver's API service has returned E_OK.
*         E_NOT_OK: The call of the LIN Transceiver Driver's API service has returned
*                   E_NOT_OK or channel or mode parameter is invalid.
********************************************************************************
*/
FUNC(Std_ReturnType, LINIF_CODE) LinIf_SetTrcvWakeupMode
(
    NetworkHandleType Channel,
    LinTrcv_TrcvWakeupModeType LinTrcvWakeupMode
)
{
    Std_ReturnType rtrnValu  = E_NOT_OK;
    uint8 index;
    uint8 errId;
    uint8 LinNetwork = LINIF_INIT_ZERO;
    uint16 chkRslt = LINIF_E_NO_ERR;

    chkRslt = LinIf_Chk_SetTrcvWakeupMode(Channel, LinTrcvWakeupMode);
    index = (uint8)(chkRslt >> LINIF_SHIFT_8BIT);
    errId = (uint8)chkRslt;

    if( LINIF_E_NO_ERR == errId )
    {
        LinNetwork = LinIf_Channl_Cfg_Tab[index].trcvIndexRef;
        rtrnValu = LinTrcv_SetWakeupMode(LinNetwork, LinTrcvWakeupMode);
    }

#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( errId != LINIF_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinIf_Det_ErrorReport(LINIF_SET_TRCV_WAKE_UP_MODE, errId);
    }
#else
        LINIF_DUMMY_STATEMENT(errId);
#endif

    return rtrnValu;
}
#endif

#if( LINIF_CANCEL_TRANSMIT_SUPPORTED == STD_ON )
/*
********************************************************************************
* Function Name: LinIf_CancelTransmit
*
* Explanation: This is a dummy method introduced for interface compatibility.(Synchronous)
*
* param: LinTxPduId: Upper layer identification of the LIN frame for which a cancellation
*                    should be done.
*
* retval: E_NOT_OK: Cancel Transmit request has not been accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, LINIF_CODE) LinIf_CancelTransmit
(
    PduIdType LinTxPduId
)
{
    uint8 chkRslt = LINIF_E_NO_ERR;

    chkRslt = LinIf_Chk_CancelTransmit(LinTxPduId);
#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( chkRslt != LINIF_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinIf_Det_ErrorReport(LINIF_CANCEL_TRANSMIT, chkRslt);
    }
#else
    LINIF_DUMMY_STATEMENT(chkRslt);
#endif

    /* The cancellation request shall always be rejected by returning E_NOT_OK. */
    return E_NOT_OK;
}
#endif

#if( (LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON) || (LINIF_TRCV_WAKEUP_SUPPORT == STD_ON) )
/*
********************************************************************************
* Function Name: LinIf_CheckWakeup
*
* Explanation: Will be called when the EcuM has been notified about a wakeup on
*              a specific LIN channel.(Synchronous)
* param: WakeupSource: Source device, which initiated the wakeup event: LIN controller
*                      or LIN transceiver.
* retval: Std_ReturnType: E_NOT_OK: E_NOT_OK: request is not accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, LINIF_CODE) LinIf_CheckWakeup
(
    EcuM_WakeupSourceType WakeupSource
)
{
    Std_ReturnType rtrnValu  = E_NOT_OK;
    uint8 chkRslt;
    uint8 chanLoopIndex;
    uint8 LinNetwork;

    LINIF_DUMMY_STATEMENT(WakeupSource);
    chkRslt = LinIf_Chk_CheckWakeup(WakeupSource);
    if( LINIF_E_NO_ERR == chkRslt )
    {
        for( chanLoopIndex = LINIF_INIT_ZERO; chanLoopIndex < LinIf_GetSizeOfChannelData(); chanLoopIndex++ )
        {
#if( LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON )
            /* If wakeup source belongs to LIN driver module, call Lin_CheckWakeup for the identified channel. */
            if( LinIf_Channel_WakeupSouceInfo[chanLoopIndex] == WakeupSource )
            {
                LinNetwork = LinIf_Channl_Cfg_Tab[chanLoopIndex].linChannelIdRef;
#if( LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON )
                (void)LinIf_LinMultipeDrvInfo[LinIf_Channl_Cfg_Tab[chanLoopIndex].ctrlId].LinIf_Lin_CheckWakeupFunc(LinNetwork);
#else
                (void)Lin_CheckWakeup(LinNetwork);
#endif  /* LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON */

                rtrnValu = E_OK;
            }
#endif

#if( LINIF_TRCV_WAKEUP_SUPPORT == STD_ON )
            /* If wakeup source belongs to a LIN transceiver, call LinTrcv_CheckWakeup for the identified transceiver and channel. */
            if( LinIf_Channel_WakeupSouceInfo[chanLoopIndex] == WakeupSource )
            {
                LinNetwork = LinIf_Channl_Cfg_Tab[chanLoopIndex].trcvIndexRef;
                (void)LinTrcv_CheckWakeup(LinNetwork);
                rtrnValu = E_OK;
            }
#endif
        }
    }

#if( LINIF_DEV_ERROR_DETECT == STD_ON )
        if( chkRslt != LINIF_E_NO_ERR ) /* Error detected. */
        {
            /* Report ErrorId to Det. */
            LinIf_Det_ErrorReport(LINIF_CHEKCK_WAKE_UP, chkRslt);
        }
#else
        LINIF_DUMMY_STATEMENT(chkRslt);
#endif

    /* The cancellation request shall always be rejected by returning E_NOT_OK. */
    return rtrnValu;
}
#endif

#if( (LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON) || (LINIF_TRCV_WAKEUP_SUPPORT == STD_ON) )
/*
********************************************************************************
* Function Name: LinIf_WakeupConfirmation
*
* Explanation: The LIN Driver or LIN Transceiver Driver will call this function to
*              report the wake up source after the successful wakeup detection
*              during CheckWakeup or after power on by bus..(Synchronous)
*
* param: WakeupSource: Source device which initiated the wakeup event:
*                      LIN controller or LIN transceiver.
*
* retval: Std_ReturnType: E_NOT_OK: Cancellation request of the reception of
*                         the specified Lin N-SDU is rejected.
********************************************************************************
*/
FUNC(void, LINIF_CODE) LinIf_WakeupConfirmation
(
    EcuM_WakeupSourceType WakeupSource
)
{
    uint8 indexTmp;
    uint8 chkRslt;

    chkRslt = LinIf_Chk_WakeupConfirmation(WakeupSource);
    if( LINIF_E_NO_ERR == chkRslt )
    {
        /* Check for each LinIf channel if given wakeup source is configured for this channel. */
        for( indexTmp = LINIF_INIT_ZERO; indexTmp < LinIf_GetSizeOfChannelData(); indexTmp++ )
        {
#if( (LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON) || (LINIF_TRCV_WAKEUP_SUPPORT == STD_ON) )
            /* If wakeup source belongs to a Lin (driver) channel, set the external wakeup flag for the identified channel. */
            if( (LinIf_Channel_WakeupSouceInfo[indexTmp] & WakeupSource)
                  != (EcuM_WakeupSourceType)LINIF_INIT_ZERO )
            {
                LinIf_ChannelData[indexTmp].wakeupFlag = LINIF_INIT_ONE;
            }
#endif
        }
    }

#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( chkRslt != LINIF_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinIf_Det_ErrorReport(LINIF_WAKE_UP_CONFIRMATION, chkRslt);
    }
#else
    LINIF_DUMMY_STATEMENT(chkRslt);
#endif

}
#endif

#if( (LINIF_CHANNEL_WAKEUP_SUPPORT != STD_ON) && (LINIF_TRCV_WAKEUP_SUPPORT != STD_ON) )
FUNC(Std_ReturnType, LINIF_CODE) LinIf_CheckWakeup
(
    EcuM_WakeupSourceType WakeupSource
)
{
    LINIF_DUMMY_STATEMENT(WakeupSource);
    return E_OK;
}

FUNC(void, LINIF_CODE) LinIf_WakeupConfirmation
(
    EcuM_WakeupSourceType WakeupSource
)
{
    LINIF_DUMMY_STATEMENT(WakeupSource);
}

FUNC(Std_ReturnType, LINIF_CODE) Mcal_LinIf_CheckWakeup
(
    VAR(EcuM_WakeupSourceType, LINIF_VAR) WakeupSource
)
{
    LINIF_DUMMY_STATEMENT(WakeupSource);
    LINIF_PRINTF("LinIf_CheckWakeup WakeupSource: %x\r\n", WakeupSource);

    return E_OK;
}

FUNC(void, LINIF_CODE) Mcal_LinIf_WakeupConfirmation
(
    VAR(EcuM_WakeupSourceType, LINIF_VAR) WakeupSource
)
{
    LINIF_DUMMY_STATEMENT(WakeupSource);
    LINIF_PRINTF("LinIf_WakeupConfirmation chn 0x%x\r\n", WakeupSource);
}
#endif

#if( LINIF_SLAVE_SUPPORT != STD_ON )
#define LINIF_MCAL_PDU_INFO_NUM          0x4u
#define LINIF_MCAL_SEND_DATA_LEN         0x8u

extern volatile Lin_Configs g_sLin_HW_Config[LIN_HW_MAX_AVAILABLE_MODULES];

FUNC(Std_ReturnType, LINIF_CODE) Mcal_LinIf_HeaderIndication
(
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 linId = PduPtr->Pid & (uint8)0x3Fu;

    static uint8 linSlaveDataVal[LINIF_MCAL_PDU_INFO_NUM][LINIF_MCAL_SEND_DATA_LEN] = {
        {0x00u, 0x50u, 0x90u, 0xD0u, 0x10u, 0xa1u, 0x42u, 0x85u},
        {0x14u, 0x02u, 0x03u, 0x04u, 0x05u, 0x06u, 0x07u, 0x12u},
        {0x02u, 0x08u, 0x36u, 0xD0u, 0x10u, 0xa1u, 0x42u, 0x85u},
        {0x45u, 0x39u, 0x03u, 0x04u, 0x05u, 0x06u, 0x07u, 0x08u}
    };

    static Lin_PduType linSlavePduInfoTable[LINIF_MCAL_PDU_INFO_NUM] = {
        {
            .Pid = 0x17u,
#ifdef LIN_TEST_MVCC
            .Cs = LIN_CLASSIC_CS,
            .Drc = LIN_FRAMERESPONSE_RX,
#else
            .Cs = LIN_CLASSIC_CS,
            .Drc = LIN_FRAMERESPONSE_TX,
#endif
            .Dl = LINIF_MCAL_SEND_DATA_LEN,
            .SduPtr = linSlaveDataVal[0],
        },
        {
            .Pid = 0x18u,
#ifdef LIN_TEST_MVCC
            .Cs = LIN_CLASSIC_CS,
            .Drc = LIN_FRAMERESPONSE_TX,
#else
            .Cs = LIN_CLASSIC_CS,
            .Drc = LIN_FRAMERESPONSE_RX,
#endif
            .Dl = LINIF_MCAL_SEND_DATA_LEN,
            .SduPtr = linSlaveDataVal[1],
        },
        {
            .Pid = 0x19u,
#ifdef LIN_TEST_MVCC
            .Cs = LIN_ENHANCED_CS,
            .Drc = LIN_FRAMERESPONSE_RX,
#else
            .Cs = LIN_ENHANCED_CS,
            .Drc = LIN_FRAMERESPONSE_TX,
#endif
            .Dl = LINIF_MCAL_SEND_DATA_LEN,
            .SduPtr = linSlaveDataVal[2],
        },
        {
            .Pid = 0x1Au,
#ifdef LIN_TEST_MVCC
            .Cs = LIN_ENHANCED_CS,
            .Drc = LIN_FRAMERESPONSE_TX,
#else
            .Cs = LIN_ENHANCED_CS,
            .Drc = LIN_FRAMERESPONSE_RX,
#endif
            .Dl = LINIF_MCAL_SEND_DATA_LEN,
            .SduPtr = linSlaveDataVal[3],
        },
    };

    for (uint8 index = 0u; index < LINIF_MCAL_PDU_INFO_NUM; index++)
    {
        if (linId == linSlavePduInfoTable[index].Pid)
        {
            *PduPtr = linSlavePduInfoTable[index];
            ret = E_OK;
            break;
        }
    }

    return ret;
}

FUNC(void, LINIF_CODE) Mcal_LinIf_RxIndication
(
    VAR(NetworkHandleType, AUTOMATIC) Channel,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_DATA) Lin_SduPtr
)
{
    VAR(uint8, AUTOMATIC) tempDataLength = 0U;

    LINIF_PRINTF("LinIf_RxIndication chn 0x%x\r\n", Channel);
    if (Channel < LIN_HW_MAX_AVAILABLE_MODULES)
    {
        if (g_pLin_ChannelConfigPtr[Channel] != NULL_PTR)
        {
            tempDataLength = (uint8)((g_sLin_HW_Config[g_pLin_ChannelConfigPtr[Channel]->u8LinHwChannel].ldp->linflexD->BIDR.B.DFL + 1U) & 0xffU);
        }
    }
    LINIF_PRINTF("-----------Received data length: %d-----------\r\n", tempDataLength);
    for (uint8 index = 0u; index < tempDataLength; index++)
    {
        LINIF_PRINTF("%02X ", Lin_SduPtr[index]);
    }

    LINIF_PRINTF("\r\n");
}

FUNC(void, LINIF_CODE) Mcal_LinIf_TxConfirmation
(
    VAR(NetworkHandleType, AUTOMATIC) Channel
)
{
    LINIF_PRINTF("\n\t txok 0x%x\n\n", Channel);
}

FUNC(void, LINIF_CODE) Mcal_LinIf_LinErrorIndication
(
    VAR(NetworkHandleType, AUTOMATIC) Channel,
    VAR(Lin_SlaveErrorType, AUTOMATIC) ErrorStatus
)
{
    LINIF_PRINTF("chn 0x%x, err 0x%x\n", Channel, ErrorStatus);
}
#endif

/*
********************************************************************************
* Function Name: LinIf_MainFunction
*
* Explanation: The main processing function of the LIN Interface.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, LINIF_CODE) LinIf_MainFunction
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    uint8 Channel
)
{
    uint8 chkRslt;

#if( LINIF_TP_SUPPORTED == STD_ON )
    LinTp_ControlType* tpCtrlTmp = NULL_PTR;
#endif
    chkRslt = LinIf_Chk_MainFunction();
    if( LINIF_CHANNEL_MASTER == LinIf_Channl_Cfg_Tab[Channel].nodeChannelType )
    {
        LinIf_MasterMainFunction(Channel);
    }

#if( LINIF_SLAVE_SUPPORT == STD_ON )
    else if( LINIF_CHANNEL_SLAVE == LinIf_Channl_Cfg_Tab[Channel].nodeChannelType )
    {
        LinIf_SlaveMainFunction(Channel);
    }
#endif /* LINIF_SLAVE_SUPPORT == STD_ON */
    else
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Do nothing */
    }
    /* Update LinTp P2 timeout (only if LinTp is supported). */
#if( LINIF_TP_SUPPORTED == STD_ON )
        /* Polyspace +1 DEFECT:INCORRECT_INDENTATION [Justified:Unset] "NSCA_Polyspace_LinIf_INCORRECT_INDENTATION" */
        tpCtrlTmp = &LinTp_Ctrl.raw[Channel];
        if( tpCtrlTmp->linTp_P2Timer > LINTP_INIT_ZERO )
        {
            tpCtrlTmp->linTp_P2Timer--;
            if( LINTP_INIT_ZERO == tpCtrlTmp->linTp_P2Timer )
            {   
                /* Timeout occurred - indicate release. */
                tpCtrlTmp->linTp_PortNotifity = (uint8)LINTP_APPLICATIVE_SCHEDULE;
                tpCtrlTmp->linTp_ComModeRestore = (uint8)LINTP_APPLICATIVE_SCHEDULE;
                /* Clear request NAD to prevent further reception. */
                tpCtrlTmp->linTp_NAD_Requested = LINTP_INIT_ZERO;
                if( LINTP_CHANNEL_BUSY_RX == tpCtrlTmp->linTp_Ch_State )
                {
                    tpCtrlTmp->linTp_PduRNotifity |= LINTP_PDURNOTIFITY_RX;
                    tpCtrlTmp->linTp_PduRNotifyResultRx = E_NOT_OK;
                    tpCtrlTmp->linTp_PduRNSduIdRx = tpCtrlTmp->linTp_Curr_UL_NSdu_Id;
                }
            }
        }
#endif
    /* Inform upper layers after processing of all channels to reduce jitter. */
    LinIf_MainFunctionPostProcessing(Channel);

#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    /* Error detected. */
    if( LINIF_E_NO_ERR != chkRslt )
    {
        /* Report ErrorId to Det. */
        LinIf_Det_ErrorReport(LINIF_MAIN_FUNCTION, chkRslt);
    }
#else
    LINIF_DUMMY_STATEMENT(chkRslt);
#endif

}

#if( LINIF_SLAVE_SUPPORT == STD_ON )
#if( LINIF_TP_SUPPORTED == STD_ON )
/*
********************************************************************************
* Function Name: LinTp_SlaveRxIndication_SF
*
* Explanation: Slave node's SF rxindication.
*
* param: LinTp_CtrlPtr: LinTp channel pointer.
*        LinTp_LinSduPtr: Data pointer.
* 
* retval: boolean: FALSE: SF PCI length is invalid .
*                  TRUE: SF PCI length is valid .
********************************************************************************
*/
static FUNC(boolean, LINIF_CODE) LinTp_SlaveRxIndication_SF
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_CONST) LinTp_LinSduPtr

)
{
    boolean ret = FALSE;

    /* SF PCI length is valid */
    if( (LINIF_INIT_ZERO < LinTp_LinSduPtr[LINTP_INIT_ONE]) && (LinTp_LinSduPtr[LINTP_INIT_ONE] <= LINTP_LENGTH_6BYTE) )
    {
        LinTp_CloseActiveConnection(LinTp_CtrlPtr);
        /* Initialize new single frame RX connection */
        LinTp_CtrlPtr->linTp_RemainingLength = (uint32)LinTp_LinSduPtr[LINTP_INIT_ONE];
        LinTp_CtrlPtr->linTp_Tx_Rx_Buffer_Length = (uint8)LinTp_LinSduPtr[LINTP_INIT_ONE];
        LinTp_CtrlPtr ->linTp_Tx_Rx_Buffer_Idx = LINTP_INIT_TWO;
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" */
        LinTp_CtrlPtr->linTp_Curr_UL_NSdu_Id = LinTp_RxNSdu[LinTp_CtrlPtr->linTp_Curr_Rx_Id].upperLayerPduIdOfRxNSdu;
        LinTp_CtrlPtr->linTp_Ch_State = LINTP_CHANNEL_BUSY_RX_WAIT_FOR_START;
        /* Start receive buffer handling */
        LinTp_RxDataBufferHandling(LinTp_CtrlPtr,LinTp_LinSduPtr);
        ret = TRUE;
    }
    else
    {
        /* Ingnore SF with invalid PCI */
    }

    return ret;
}

/*
********************************************************************************
* Function Name: LinTp_SlaveRxIndication_FF
*
* Explanation: Slave node's FF rxindication.
*
* param: LinTp_CtrlPtr: LinTp channel pointer.
*        LinTp_LinSduPtr: Data pointer.
* 
* retval: boolean: FALSE: Length information in FF is invalid .
*                  TRUE: Length information in FF is valid.
********************************************************************************
*/
static FUNC(boolean, LINIF_CODE) LinTp_SlaveRxIndication_FF
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_CONST) LinTp_LinSduPtr

)
{
    boolean ret = FALSE;
    uint16 reqLength;
    reqLength = (uint16)LinTp_LinSduPtr[LINTP_INIT_ONE] & (uint16)LINTP_8BIT_LOW4BIT;
    reqLength = reqLength << (uint16)LINTP_LENGTH_8BYTE;
    reqLength = reqLength | (uint16)LinTp_LinSduPtr[LINTP_INIT_TWO];

    /* Check if length information in FF is valid. */
    if( (uint16)LINTP_LENGTH_6BYTE < reqLength )
    {
        LinTp_CloseActiveConnection(LinTp_CtrlPtr);
        /* Initialize new multi frame RX connection */
        /* Start/restart the N_Cr timer after reception of a MRF (FF or CF except last CF) with invocation of callback function LinIf_RxIndication */
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" */
        LinTp_CtrlPtr->linTp_Timer = LinTp_RxNSdu[LinTp_CtrlPtr->linTp_Curr_Rx_Id].ncrOfRxNSdu;
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" */
        LinTp_CtrlPtr->linTp_TimerReload = LinTp_RxNSdu[LinTp_CtrlPtr->linTp_Curr_Rx_Id].ncrOfRxNSdu;
        LinTp_CtrlPtr->linTp_RemainingLength = reqLength;
        LinTp_CtrlPtr->linTp_Tx_Rx_Buffer_Length = LINTP_INIT_FIVE;
        LinTp_CtrlPtr->linTp_Tx_Rx_Buffer_Idx = LINTP_INIT_THREE;
        LinTp_CtrlPtr->linTp_SN = LINTP_INIT_ONE;
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" */
        LinTp_CtrlPtr->linTp_Curr_UL_NSdu_Id = LinTp_RxNSdu[LinTp_CtrlPtr->linTp_Curr_Rx_Id].upperLayerPduIdOfRxNSdu;
        LinTp_CtrlPtr->linTp_Ch_State = LINTP_CHANNEL_BUSY_RX_WAIT_FOR_START;
        /* Start receive buffer handling */
        LinTp_RxDataBufferHandling(LinTp_CtrlPtr,LinTp_LinSduPtr);
        ret = TRUE;
    }
    return ret;
}
#endif  /* LINIF_TP_SUPPORTED == STD_ON */

#if( LINTP_NC_SUPPORTED == STD_ON )
/*
********************************************************************************
* Function Name: LinTp_Nc_CheckSupplierIDAndFunctionID
*
* Explanation: Slave node check SupplierID And FunctionID.
*
* param: Channel: LinTp channel.
*        Lin_SduPtr: Data pointer.
* 
* retval: boolean: FALSE: Supplier ID and function ID are invalid.
*                  TRUE: Supplier ID and function ID are valid.
********************************************************************************
*/
static FUNC(boolean, LINIF_CODE) LinTp_Nc_CheckSupplierIDAndFunctionID
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR) Lin_SduPtr
)
{
    boolean retVal = FALSE;
    uint16 supplierId;
    uint16 functionId;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    const LinIf_SlaveChannel_Nc_ConfigType* LinIf_slaveChannelData = LinIf_SlaveChannel_Nc_ConfigData[Channel];

    /* Assemble supplier ID and function ID from received data */
    supplierId = (uint16)((((uint32)Lin_SduPtr[LINTP_INIT_ONE]) << LINTP_LENGTH_8BIT) | Lin_SduPtr[LINIF_INIT_ZERO]);
    functionId = (uint16)((((uint32)Lin_SduPtr[LINTP_INIT_THREE]) << LINTP_LENGTH_8BIT) | Lin_SduPtr[LINTP_INIT_TWO]);
    /* Check if supplier ID and function ID are valid */
    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
    if( ((supplierId == LinIf_slaveChannelData ->LinIf_SupplierId) || (supplierId == LINIF_NC_WILDCARD_SUPPLIERID)) &&
        ((functionId == LinIf_slaveChannelData ->LinIf_FunctionId) || (functionId == LINIF_NC_WILDCARD_FUNCTIONID)) )
    {
        retVal = TRUE;
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: LinTp_Nc_RxIndication_ReadByIdentifier
*
* Explanation: 0xB2 Service ReadByIdentifier.
*
* param: Channel: LinTp channel.
*        Lin_SduPtr: Data pointer.
*        LinIf_ChannelData: Response data pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinTp_Nc_RxIndication_ReadByIdentifier
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR) Lin_SduPtr,
    P2CONST(LinIf_SlaveChannel_Nc_ConfigType, AUTOMATIC, LINIF_APPL_VAR) LinIf_SlaveChannelData
)
{
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    uint8 dataLen = LINTP_INIT_ZERO;
    uint8 nrcVal = LINTP_INIT_ZERO;
    Std_ReturnType retVal;

    if( TRUE == LinTp_Nc_CheckSupplierIDAndFunctionID(Channel, &Lin_SduPtr[LINTP_INIT_FOUR]) ) /* supplierId and functionId */
    {
        /* Polyspace +1 RTE:COR [Justified:Unset] "NSCA_Polyspace_LinIf_CorrectnessCondition" */
        retVal = LinIf_SlaveChannelData->LinTp_Nc_ReadByIdentifier(Lin_SduPtr[LINTP_INIT_THREE], 
                                                                   &LinIf_SlaveChannelData ->LinIf_NcRespBuffer[LINTP_INIT_FOUR], 
                                                                   &dataLen);
        if( (E_OK == retVal) && (dataLen > LINTP_INIT_ZERO) && (dataLen <= LINTP_INIT_FOUR) )
        {
            /* Byte0: NAD */
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
            LinIf_SlaveChannelData ->LinIf_NcRespBuffer[LINTP_INIT_ZERO] = LinIf_SlaveChannelData->LinIf_ConfiguredNAD;
            /* Byte1: PCI */
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
            LinIf_SlaveChannelData ->LinIf_NcRespBuffer[LINTP_INIT_ONE] = LINTP_INIT_SIX;
            /* Byte2: RSID */
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
            LinIf_SlaveChannelData ->LinIf_NcRespBuffer[LINTP_INIT_TWO] = LINTP_VALUE_0XF2;
            /* Byte3: Request SID */
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
            LinIf_SlaveChannelData ->LinIf_NcRespBuffer[LINTP_INIT_THREE] = Lin_SduPtr[LINTP_INIT_THREE];
            /* Byte4~Byte7: Data */
            while( dataLen < LINTP_INIT_FOUR )
            {
                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
                LinIf_SlaveChannelData ->LinIf_NcRespBuffer[dataLen + LINTP_INIT_FOUR] = LINTP_VALUE_0XFF;
                dataLen++;
            }
        }
        else
        {
            nrcVal = LINTP_VALUE_0X12;
        }
    }
    else
    {
        nrcVal = LINTP_VALUE_0X22;
    }
    
    /* Negative response data */
    if( nrcVal != LINTP_INIT_ZERO )
    {
        /* Byte0: NAD */
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
        LinIf_SlaveChannelData ->LinIf_NcRespBuffer[LINTP_INIT_ZERO] = LinIf_SlaveChannelData->LinIf_ConfiguredNAD;
        /* Byte1: PCI */
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
        LinIf_SlaveChannelData ->LinIf_NcRespBuffer[LINTP_INIT_ONE] = LINTP_INIT_THREE;
        /* Byte2: RSID */
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
        LinIf_SlaveChannelData ->LinIf_NcRespBuffer[LINTP_INIT_TWO] = LINTP_VALUE_0X7F;
        /* Byte3: Request SID */
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
        LinIf_SlaveChannelData ->LinIf_NcRespBuffer[LINTP_INIT_THREE] = Lin_SduPtr[LINTP_INIT_THREE];
        /* Byte4: NRC */
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
        LinIf_SlaveChannelData ->LinIf_NcRespBuffer[LINTP_INIT_FOUR] = nrcVal;
        /* Reserved Byte: */
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
        LinIf_SlaveChannelData ->LinIf_NcRespBuffer[LINTP_INIT_FIVE] = LINTP_VALUE_0XFF;
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
        LinIf_SlaveChannelData ->LinIf_NcRespBuffer[LINTP_INIT_SIX] = LINTP_VALUE_0XFF;
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
        LinIf_SlaveChannelData ->LinIf_NcRespBuffer[LINTP_INIT_SEVEN] = LINTP_VALUE_0XFF;
    }
}

/*
********************************************************************************
* Function Name: LinTp_Nc_RxIndication
*
* Explanation: Salve receive Node configuration service.
*
* param: Channel: LinTp channel.
*        Lin_SduPtr: Data pointer.
* retval: LinIf_Nc_RetType: LINIF_NC_RET_IGNORED: handle request.
*                           LINIF_NC_RET_IGNOREDNOFORWARD: ignore functional request.
*                           LINIF_NC_RET_IGNORED:unsupported service identifier.
********************************************************************************
*/
static FUNC(LinIf_Nc_RetType, LINIF_CODE) LinTp_Nc_RxIndication
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR) Lin_SduPtr
)
{
    LinIf_Nc_RetType LinIf_Nc_Ret = LINIF_NC_RET_IGNORED;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    const LinIf_SlaveChannel_Nc_ConfigType* LinIf_slaveChannelData = LinIf_SlaveChannel_Nc_ConfigData[Channel]; 

    if( (NULL_PTR != LinIf_slaveChannelData) && 
        ((LINIF_INIT_ONE <= Lin_SduPtr[LINIF_INIT_ONE]) && 
         (Lin_SduPtr[LINIF_INIT_ONE] <= LINTP_INIT_SIX) && 
         (LINIF_VALUE_0XB0 <= Lin_SduPtr[LINIF_INIT_TWO]) && 
         (Lin_SduPtr[LINIF_INIT_TWO] <= LINIF_VALUE_0XB8)) )
    {
        /* If NAD is valid for requested node configuration service or wildcard NAD */
        if( (LinIf_slaveChannelData->LinIf_ConfiguredNAD == Lin_SduPtr[LINIF_INIT_ZERO]) || 
            ((uint8)LINTP_VALUE_0X7F == Lin_SduPtr[LINIF_INIT_ZERO]) )
        {
            /*If PCI is valid for requested node configuration service, PCIength:B0/B7/B2 = 6  B6 = 1*/
            if( ( LINIF_INIT_ONE == Lin_SduPtr[LINIF_INIT_ONE] ) || ( LINTP_INIT_SIX == Lin_SduPtr[LINIF_INIT_ONE]) )
            {
                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
                LinIf_slaveChannelData->LinIf_NcRespBuffer[LINIF_INIT_ZERO] = LINIF_INIT_ZERO;
                LinIf_Nc_Ret = LINIF_NC_RET_ACCEPTED;
                /* Handle request */
                switch( Lin_SduPtr[LINIF_INIT_TWO] )
                {
                    /* Assign NAD , if LinIfNcOptionalRequestSupported = On */
                    case LINIF_NC_ASSIGNNAD_0xB0:
                        break;
                    /* Assign Frame ID range */
                    case LINIF_NC_ASSIGNFRAMEIDRANGE_0xB7:
                        break;
                    /* Save Configuration , if LinIfSaveConfigurationCallout*/
                    case LINIF_NC_SAVECONFIGURATION_0xB6:
                        break;
                    /* Read by Identifier */
                    case LINIF_NC_READBYIDENTIFIER_0xB2:
                        LinTp_Nc_RxIndication_ReadByIdentifier(Channel,Lin_SduPtr,LinIf_slaveChannelData);
                        break;
                    /* Unsupported service identifier */
                    default:
                        LinIf_Nc_Ret = LINIF_NC_RET_IGNORED;
                        break;
                }
            }
            else
            {
                LinIf_Nc_Ret = LINIF_NC_RET_IGNOREDNOFORWARD;
            }
        }
        else
        {
            /* Functional NAD */
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
            if( (LINTP_VALUE_0X7E == Lin_SduPtr[LINIF_INIT_ZERO]) && (LINIF_INIT_ZERO != LinIf_slaveChannelData->LinIf_NcRespBuffer[LINIF_INIT_ZERO]) )
            {
                /* Ignore functional request */
                LinIf_Nc_Ret = LINIF_NC_RET_IGNOREDNOFORWARD;
            }
            else
            {
                /* Node configuration service addressing another node, abort reponse */
                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
                LinIf_slaveChannelData->LinIf_NcRespBuffer[LINIF_INIT_ZERO] = LINIF_INIT_ZERO;
                /* Clear possibly running timer (if valid request has been received before and response was pending) */
                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
                *LinIf_slaveChannelData->LinIf_NasTimer = LINIF_INIT_ZERO;
            }
        }
    }
    /* Start N_As timeout timer if request is accepted */
    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
    if( (NULL_PTR != LinIf_slaveChannelData) && (LINIF_INIT_ZERO != LinIf_slaveChannelData->LinIf_NcRespBuffer[LINIF_INIT_ZERO]) )
    {
        /* Start the N_As timer after reception of a valid node configuration request */
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
        *LinIf_slaveChannelData->LinIf_NasTimer = LinIf_slaveChannelData->LinIf_NasTimeOut;
    }

    return LinIf_Nc_Ret;
}
#endif  /* LINTP_NC_SUPPORTED == STD_ON */

#if( LINIF_TP_SUPPORTED == STD_ON )
/*
********************************************************************************
* Function Name: LinTp_SlaveRxIndication
*
* Explanation: Salve receive Tp service.
*
* param: LinIf_LinIfChannel: LinTp channel.
*        LinTp_LinSduPtr: Data pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinTp_SlaveRxIndication
(
    NetworkHandleType LinIf_LinIfChannel,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR) LinTp_LinSduPtr
)
{
    uint16 rxNsduIdx;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    LinTp_ControlType* tpCtrlTmp = &LinTp_Ctrl.raw[LinIf_LinIfChannel];
#if( LINTP_MAXRXNSDU_CNT != LINIF_INIT_ZERO )
    boolean linTp_MatchesConfiguredNAD = FALSE;
    uint16 rxNSduIndLoopIdx;
    const LinTp_RxNSduType* rxNSduRef;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    const LinIf_SlaveChannel_Nc_ConfigType* LinIf_slaveChannelData = LinIf_SlaveChannel_Nc_ConfigData[LinIf_LinIfChannel];
#endif
    const LinTp_RxNSduType* linTp_rxNSduData;
    
#if( LINTP_MAXRXNSDU_CNT != LINIF_INIT_ZERO )
    /* If the received NAD matches the current configured NAD, also search for a configured RxNSDU with NAD zero */
    if( (NULL_PTR != LinIf_slaveChannelData) && (LinTp_LinSduPtr[LINIF_INIT_ZERO] == LinIf_slaveChannelData ->LinIf_ConfiguredNAD) )
    {
        linTp_MatchesConfiguredNAD = TRUE;
    }
#endif
    /* Retrieve RxNSduId from NAD by searching all RxNSdus configured on current channel */
    rxNsduIdx = LINTP_VALUE_0XFF;
#if( LINTP_MAXRXNSDU_CNT != LINIF_INIT_ZERO )
    for( rxNSduIndLoopIdx = LINIF_INIT_ZERO; rxNSduIndLoopIdx < LINTP_MAXRXNSDU_CNT; rxNSduIndLoopIdx++ )
    {
        rxNSduRef = &LinTp_RxNSdu[rxNSduIndLoopIdx];
        /* Note: the indirection to the relevant RxNSdus does not contain references to invalid handles, no need to check for them */
        if( (((rxNSduRef->nadOfRxNSdu == LinTp_LinSduPtr[LINIF_INIT_ZERO]) || 
              (LINTP_VALUE_0X7F == LinTp_LinSduPtr[LINIF_INIT_ZERO])) && 
             (rxNSduRef->ctrlIdxOfRxNSdu == LinIf_LinIfChannel)) || 
            (TRUE == linTp_MatchesConfiguredNAD) )
        {
            rxNsduIdx = rxNSduIndLoopIdx;
            break;
        }
    }
#endif
    if( LINTP_VALUE_0XFF != rxNsduIdx )
    {
        tpCtrlTmp ->linTp_Curr_Rx_Id = (PduIdType)rxNsduIdx;
        linTp_rxNSduData = &LinTp_RxNSdu[rxNsduIdx];
        /* Functional request */
        if( LINTP_VALUE_0X7E == linTp_rxNSduData->nadOfRxNSdu )
        {
            /* Process valid functional request and indicate it to PduR in Tp idle state, otherwise ignore frame */ 
            if( (LINTP_CHANNEL_IDLE == tpCtrlTmp ->linTp_Ch_State) &&
                ((LINIF_INIT_ZERO < LinTp_LinSduPtr[LINIF_INIT_ONE]) && (LinTp_LinSduPtr[LINIF_INIT_ONE] <= LINTP_INIT_SIX)) )
            {
                tpCtrlTmp ->linTp_Curr_UL_NSdu_Id = linTp_rxNSduData->upperLayerPduIdOfRxNSdu;
                tpCtrlTmp->linTp_RemainingLength = LinTp_LinSduPtr[LINIF_INIT_ONE];
                tpCtrlTmp ->linTp_Tx_Rx_Buffer_Length = LinTp_LinSduPtr[LINIF_INIT_ONE];
                LinTp_RxDataBufferHandling_StartOfReception(tpCtrlTmp); 
                /* LINTP_CHANNEL_BUSY_RX: valid state, provide receive data to upper layer */
                if( LINTP_CHANNEL_BUSY_RX == tpCtrlTmp ->linTp_Ch_State )
                {
                    tpCtrlTmp->linTp_PduInfoPtr.SduDataPtr = &LinTp_LinSduPtr[LINIF_INIT_TWO];
                    tpCtrlTmp->linTp_PduInfoPtr.SduLength = (uint8)LinTp_LinSduPtr[LINIF_INIT_ONE];
                    LinTp_RxDataBufferHandling_CopyRxData(tpCtrlTmp);
                }
            }
        }
        else
        {
            /* Evaluate frame type of received frame. */
            switch( LinTp_LinSduPtr[LINTP_INIT_ONE] & LINTP_8BIT_HIGH4BIT )
            {
                case LINTP_FRAMETYPE_SF:
                    (void)LinTp_SlaveRxIndication_SF(tpCtrlTmp, LinTp_LinSduPtr);
                    break;
                case LINTP_FRAMETYPE_FF:
                    (void)LinTp_SlaveRxIndication_FF(tpCtrlTmp, LinTp_LinSduPtr);
                    break;
                case LINTP_FRAMETYPE_CF:
                    /* Consecutive frame is received */
                    LinTp_RxIndication_CF(tpCtrlTmp, LinTp_LinSduPtr);
                    break;
                /* PCI types invalid */
                default:
                    /* Do Nothing. */
                    break;
            }
        }
    }
    else
    {
        /* Unknown NAD received, terminate ongoing Tp connection if frame is SF or FF, otherwise ignore it */
        if( (LINTP_FRAMETYPE_SF == (LinTp_LinSduPtr[LINIF_INIT_ONE] & LINTP_8BIT_HIGH4BIT)) || 
            (LINTP_FRAMETYPE_FF == (LinTp_LinSduPtr[LINIF_INIT_ONE] & LINTP_8BIT_HIGH4BIT)) )
         {
             LinTp_CloseActiveConnection(tpCtrlTmp); 
         }
         else
         {
            /* Frame with invalid PCI not addressing this node is ignored */
         }
    }
}
#endif  /* LINIF_TP_SUPPORTED == STD_ON */

/*
********************************************************************************
* Function Name: LinIf_SlaveRxindication_DiagReq
*
* Explanation: Salve receive diag request.
*
* param: LinIf_LinIfChannel: LinTp channel.
*        LinTp_LinSduPtr: Data pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_SlaveRxindication_DiagReq
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR) Lin_SduPtr
)
{
#if( (LINTP_NC_SUPPORTED == STD_ON) && (LINIF_TP_SUPPORTED == STD_ON) )
    LinIf_Nc_RetType ret;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    LinTp_ControlType* tpCtrlTmp = &LinTp_Ctrl.raw[Channel];
#endif

#if( LINTP_NC_SUPPORTED == STD_ON )
#if( LINIF_TP_SUPPORTED == STD_ON )
    /* Node configuration handler */
    ret = LinTp_Nc_RxIndication(Channel, Lin_SduPtr);
    /* If node configuration service received and accepted, close possibly ongoing Tp connection if transport protocol is enabled */
    if( LINIF_NC_RET_ACCEPTED == ret )
    {
        LinTp_CloseActiveConnection(tpCtrlTmp);
    }
    else if( LINIF_NC_RET_IGNOREDNOFORWARD == ret )
    {
        /* Ignore frame, do not forward to LinTp */
    }
    /* LinIf_Nc_Ret = LinIf_Nc_Ret_Ignored, transport protocol handler */
    else 
    {
        LinTp_SlaveRxIndication(Channel, Lin_SduPtr);
    }
#else
    (void)LinTp_Nc_RxIndication(Channel, Lin_SduPtr);
    
#endif
#elif( LINIF_TP_SUPPORTED == STD_ON )
    /* Slave-recepition Diag */
    LinTp_SlaveRxIndication(Channel, Lin_SduPtr);
#endif

}

/*
********************************************************************************
* Function Name: LinIf_SlaveMainFunction
*
* Explanation: Bus idle monitoring process.
*
* param: channelTmp: Channel index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_SlaveMainFunction
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    uint8 LinIfChannel
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    LinIf_ChannelDataType* channelDataPtrTmp = &LinIf_ChannelData[LinIfChannel];
#if( LINTP_NC_SUPPORTED == STD_ON )
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    const LinIf_SlaveChannel_Nc_ConfigType* LinIf_slaveChannelData = LinIf_SlaveChannel_Nc_ConfigData[LinIfChannel];
#endif
#if( LINIF_TP_SUPPORTED == STD_ON )
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    LinTp_ControlType* tpCtrlTmp = &LinTp_Ctrl.raw[LinIfChannel];
#endif

    if( LINIF_CHANNEL_OPERATIONAL == channelDataPtrTmp->channelState )
    {
        if( LINIF_FRMTYPE_WAKEUPFRAME == channelDataPtrTmp->currentFrameType )
        {
            /* Wake Up Frame has been send. */
            if( LINIF_ONWAKEUPFRM_ONTRANS == channelDataPtrTmp->sleepModeFrameHandle )
            {
                /* Only Process the wakeup frame transmission if no other request is pending. */
                channelDataPtrTmp->sleepModeFrameHandle = LINIF_ONSLRRPMODEFRM_IDLE;
                LinIf_WakeupConfirmationUL_Process(LinIfChannel, LinIf_Channl_Cfg_Tab[LinIfChannel].ComMChannelRef, TRUE);
            }
        }

        if( LINIF_INIT_ZERO < channelDataPtrTmp->busMaxIdleCnt )
        {
            channelDataPtrTmp->busMaxIdleCnt--;
            if( LINIF_INIT_ZERO == channelDataPtrTmp->busMaxIdleCnt )
            {
                /* [SWS_LinIf_00755]:In case a bus idle timeout occurs, 
                   the sleep mode transition shall be executed */
                LinIf_GotoSleepIndicationUL_Process(LinIfChannel, LinIf_Channl_Cfg_Tab[LinIfChannel].ComMChannelRef);

#if( (LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON) || (LINIF_TRCV_WAKEUP_SUPPORT == STD_ON) )
                if( LINIF_INIT_ZERO == channelDataPtrTmp->wakeupFlag )
#endif
                {
                    if( FALSE == channelDataPtrTmp->reqWakeUpFlag )
                    {
                        LinIf_GoToSleepConfirmationUL_Process(LinIfChannel, LinIf_Channl_Cfg_Tab[LinIfChannel].ComMChannelRef, TRUE);
                    }
                }
            }
        }
        if( TRUE == channelDataPtrTmp->goToSleepCommandFlag )
        {
            /* If the go to sleep command is received in LinIf_RxIndication, the transition to sleep mode shall be executed.*/
            LinIf_GotoSleepIndicationUL_Process(LinIfChannel, LinIf_Channl_Cfg_Tab[LinIfChannel].ComMChannelRef);
            channelDataPtrTmp->goToSleepCommandFlag = FALSE;

#if( (LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON) || (LINIF_TRCV_WAKEUP_SUPPORT == STD_ON) )
            if( LINIF_INIT_ZERO == channelDataPtrTmp->wakeupFlag )
#endif
            {
                if( FALSE == channelDataPtrTmp->reqWakeUpFlag )
                {
                    /* If the upper layer does not request a wake-up before, <User>_GotoSleepConfirmation shall be invoked. */
                    LinIf_GoToSleepConfirmationUL_Process(LinIfChannel, LinIf_Channl_Cfg_Tab[LinIfChannel].ComMChannelRef, TRUE);
                }

            }
        }
#if( LINTP_NC_SUPPORTED == STD_ON )
    if( NULL_PTR != LinIf_slaveChannelData )
    {
        /* Update N_As node configuration service timer (if node configuration services are enabled) */
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
        if( *LinIf_slaveChannelData->LinIf_NasTimer > LINIF_INIT_ZERO )
        {
            (*LinIf_slaveChannelData->LinIf_NasTimer)--; 
            /* If N_As node configuration service timeout has elapsed, clear pending response */
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
            if( *LinIf_slaveChannelData->LinIf_NasTimer == LINIF_INIT_ZERO )
            {
                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
                LinIf_slaveChannelData->LinIf_NcRespBuffer[LINIF_INIT_ZERO] = LINIF_INIT_ZERO;
            }
        }
    }
    else
    {
        /* Do nothing */
    }
#endif
#if( LINIF_TP_SUPPORTED == STD_ON )
    /* Lin Tp timeout handling. */
    if( tpCtrlTmp->linTp_Timer > LINIF_INIT_ZERO )
    {
        tpCtrlTmp->linTp_Timer--;
        if( LINIF_INIT_ZERO == tpCtrlTmp->linTp_Timer )
        { 
            /* Timeout on running transmission / reception occurred check current state. */
            LinTp_CloseActiveConnection(tpCtrlTmp);
        }
    }
    LinTp_DataBuffer_Polling(tpCtrlTmp);
#endif
    }
    else if( LINIF_CHANNEL_SLEEP == channelDataPtrTmp->channelState )
    {
        channelDataPtrTmp->busMaxIdleCnt = LinIf_ChannelData[LinIfChannel].busMaxIdleCnt;
    }
    else
    {
        /* Do nothing */
    }
}

/*
********************************************************************************
* Function Name: LinIf_RxIndication
*
* Explanation: The LIN Driver will call this function to report a received LIN header.
*              This function is only applicable for LIN slave nodes.
*
* param: Channel: Identification of the LIN channel.
*        Lin_SduPtr:  Pointer to pointer to a shadow buffer or memory mapped LIN 
*                     Hardware receive buffer where the current SDU is stored. This 
*                     pointer is only valid if the response is received..
*
* retval: none:
********************************************************************************
*/
FUNC(void, LINIF_CODE) LinIf_RxIndication
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR) Lin_SduPtr
)
{
    uint8 chkRslt = LINIF_E_NO_ERR;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    PduInfoType pduInfo = {NULL_PTR,LINIF_INIT_ZERO};
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    uint16 frameCfgIdx = LINIF_INIT_ZERO;
    LinIf_ChannelDataType* channelDataPtrTmp = NULL_PTR;
    channelDataPtrTmp = &LinIf_ChannelData[Channel];

    if( Channel >= LINIF_CHANNEL_NUMTOTAL )
    {
        chkRslt = LINIF_E_NONEXISTENT_CHANNEL;
    }
    else if( NULL_PTR == Lin_SduPtr )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        chkRslt = LINIF_E_PARAM_POINTER;
    }
    else
    {
        /* Slave-rx */
        if( (TRUE == channelDataPtrTmp->rxFrameReceiveFlag) && 
            (LINIF_CHANNEL_SLAVE == LinIf_Channl_Cfg_Tab[Channel].nodeChannelType) )
        {
            channelDataPtrTmp->busMaxIdleCnt = LinIf_Channl_Cfg_Tab[Channel].channelIdleCnt;
            if( LINIF_FRMTYPE_MRF == channelDataPtrTmp->currentFrameType ) 
            {
                /* Sleep frame */
                /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.14" Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_LinIf_TAINTED_PTR" */
                if( LINIF_INIT_ZERO == Lin_SduPtr[LINIF_INIT_ZERO] ) 
                {
                    /* If the go to sleep command is received, set the related flag,
                    <User>_GotoSleepConfirmation shall be invoked in next mainfunction */
                    channelDataPtrTmp->goToSleepCommandFlag = TRUE;
                }
                else
                {
                    /* Slave reception MRF request data to diag */
                    LinIf_SlaveRxindication_DiagReq(Channel,Lin_SduPtr);
                }
            }
            /* Unconditional frame */
            else
            {
                pduInfo.SduLength = channelDataPtrTmp->pduRNotificationPduLength;
                pduInfo.SduDataPtr = Lin_SduPtr;
                frameCfgIdx = channelDataPtrTmp->frameHandle;
                /* [SWS_LinIf_00734]: If the function LinIf_RxIndication is called, the LIN Interface 
                shall invoke <User_RxIndication> with the received data and payload length */
                LinIf_RxIndicationUL_Process(frameCfgIdx, channelDataPtrTmp->pduRNotificationPduId, &pduInfo);
                /* After the rx process is completed, the related flag is cleared. */
                channelDataPtrTmp->rxFrameReceiveFlag = FALSE;
            }
        }
    }
#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( chkRslt != LINIF_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinIf_Det_ErrorReport(LINIF_RXINDICATION, chkRslt);
    }
#else
    LINIF_DUMMY_STATEMENT(chkRslt);
#endif
}

#if( LINIF_TP_SUPPORTED == STD_ON )
/*
********************************************************************************
* Function Name: LinTp_SlaveTxHeaderIndication
*
* Explanation: Slave node received SRF frame, requires upper layer response.
*              This function is only applicable for LIN slave nodes.
*
* param: Channel: Identification of the LIN channel.
*        Lin_SduPtr:  Pointer to pointer to a shadow buffer.
*
* retval: boolean: FALSE: Transmission data is currently not available.
*                  TRUE: Transmission data is available.
********************************************************************************
*/
static FUNC(boolean, LINIF_CODE) LinTp_SlaveTxHeaderIndication
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR) Lin_SduPtr
)
{
    boolean sendRespRetVal = FALSE;
    uint8 id = LINIF_INIT_ZERO;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    LinTp_ControlType* tpCtrlTmp = &LinTp_Ctrl.raw[Channel];

    /* If transmission data is currently not available, request it from PduR */
    if( LINTP_CHANNEL_BUSY_TX_INVALID == tpCtrlTmp ->linTp_Ch_State )
    {
        /* Request transmission data from PduR and adapt the channel state if necessary */
        if( E_NOT_OK == LinTp_TxDataRequest(tpCtrlTmp) )
        {
            /* unable to obtain data from PduR */
            LinTp_TxCloseConnection(tpCtrlTmp);
        }
        else
        {
            /* Next timeout reload value refers to CFs. */
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" */
            tpCtrlTmp->linTp_TimerReload = LinTp_TxNSdu[tpCtrlTmp->linTp_Curr_Tx_Id].ncsOfTxNSdu;
        }
    }
    /* If transmission data is available */
    if( LINTP_CHANNEL_BUSY_TX_VALID == tpCtrlTmp ->linTp_Ch_State )
    {
        for( id = LINIF_INIT_ZERO; id < LINIF_NC_BUF_SIZE; id++ )
        {
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
            Lin_SduPtr[id] = tpCtrlTmp->linTp_Tx_Rx_Buffer[id];
        }
        /* Update timer with N_As */
        /* Slave CF: reception of a SRF header */
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" */
        tpCtrlTmp->linTp_Timer = LinTp_TxNSdu[tpCtrlTmp->linTp_Curr_Tx_Id].nasOfTxNSdu;
        sendRespRetVal = TRUE;
    }

return sendRespRetVal;
}
#endif  /* LINIF_TP_SUPPORTED == STD_ON */

/*
********************************************************************************
* Function Name: LinIf_HeaderIndication_DiagTx
*
* Explanation: Slave node received SRF frame, requires response.
*              This function is only applicable for LIN slave nodes.
*
* param: Channel: Identification of the LIN channel.
*        Lin_SduPtr:  Pointer to pointer to a shadow buffer.
*
* retval: Std_ReturnType: E_OK: Slave node received SRF frame, response Tx data.
*                         E_NOT_OK: No data need to response.
********************************************************************************
*/
static FUNC(Std_ReturnType, LINIF_CODE) LinIf_HeaderIndication_DiagTx
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_VAR) PduPtr,
    P2CONST(LinIf_SlaveChannel_Nc_ConfigType, AUTOMATIC, LINIF_APPL_VAR) SlaveChannelDataPtr,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    uint16 frameCfgIdx
)
{
    boolean sendResponseFlag;
    Std_ReturnType retValue = E_NOT_OK;
#if( LINTP_NC_SUPPORTED == STD_ON )
    uint8 bufIdx;
#endif
    sendResponseFlag = FALSE;

#if( LINTP_NC_SUPPORTED == STD_ON )
    /* Copy Tx data and notify response transmission */
    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
    if( (NULL_PTR != SlaveChannelDataPtr) && (LINIF_INIT_ZERO != SlaveChannelDataPtr->LinIf_NcRespBuffer[LINIF_INIT_ZERO]))
    {
        sendResponseFlag = TRUE;
        for(bufIdx = LINIF_INIT_ZERO; bufIdx < LINIF_NC_BUF_SIZE; bufIdx++ )
        {
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
            PduPtr ->SduPtr[bufIdx] = SlaveChannelDataPtr->LinIf_NcRespBuffer[bufIdx];
        }
    }
    else
#endif
    {
#if( LINIF_TP_SUPPORTED == STD_ON )
        /* Update pointer to Tx data and notify response transmission */
        if( TRUE == LinTp_SlaveTxHeaderIndication(Channel, PduPtr->SduPtr) )
        {
            sendResponseFlag = TRUE;
        }
#endif
    }

    if( FALSE == sendResponseFlag )
    {
        PduPtr ->Drc = (Lin_FrameResponseType)LINIF_SLV_FRAMERESPONSE_IGNORE;
    }
    else
    {
        PduPtr->Dl = LINIf_Frame_Cfg_Tab[frameCfgIdx].lengthOfFrameList;
        PduPtr->Cs = LINIf_Frame_Cfg_Tab[frameCfgIdx].chkSumType;
        /* Slave continues to transmit the rest of the frames when the master transmits a SRF header */
        retValue = (Std_ReturnType)E_OK;
    }
    LINIF_DUMMY_STATEMENT(SlaveChannelDataPtr);
    return retValue;
}

/*
********************************************************************************
* Function Name: LinIf_HeaderIndication
*
* Explanation: The LIN Driver will call this function to report a received LIN header.
*              This function is only applicable for LIN slave nodes.
*
* param: Channel: Identification of the LIN channel.
*        PduPtr:  Pointer to PDU providing the received PID and pointer to the SDU 
*                 data buffer as in parameter.
*
* retval: Std_ReturnType:  E_OK: Request has been accepted. 
*                          E_NOT_OK: Request has not been accepted, development or 
*                                    production error occurred.
********************************************************************************
*/
FUNC(Std_ReturnType, LINIF_CODE) LinIf_HeaderIndication
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_VAR) PduPtr
)
{
    uint8 chkRslt = LINIF_E_NO_ERR;
    uint8 retVal = E_NOT_OK;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    PduInfoType pduInfo = {NULL_PTR, LINIF_INIT_ZERO};
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    uint16 frameCfgIdx = LINIF_INIT_ZERO;
    PduIdType upPduId;
    Lin_FrameResponseType pduDirection;
    LinIf_ChannelDataType* channelDataPtrTmp;
    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.14" Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_LinIf_TAINTED_ARRAY_INDEX" */
    const LinIf_SlaveChannel_Nc_ConfigType* LinIf_slaveChannelData =  LinIf_SlaveChannel_Nc_ConfigData[Channel];

    if( Channel >= LINIF_CHANNEL_NUMTOTAL )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        chkRslt = LINIF_E_NONEXISTENT_CHANNEL;
    }
    else if( NULL_PTR == PduPtr )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        chkRslt = LINIF_E_PARAM_POINTER;
    }
    else if( LINIF_CHANNEL_SLAVE != LinIf_Channl_Cfg_Tab[Channel].nodeChannelType )
    {
        chkRslt = LINIF_E_PARAMETER;
    }
    else
    {
        channelDataPtrTmp = &LinIf_ChannelData[Channel];
        /* PId should be evaluated, to get the frame information */
        /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.14" Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_LinIf_TAINTED_PTR" */
        if( TRUE == LinIf_EvaluatePID(Channel, &pduDirection, PduPtr->Pid, &frameCfgIdx) )
        {
            channelDataPtrTmp->busMaxIdleCnt = LinIf_Channl_Cfg_Tab[Channel].channelIdleCnt;
            upPduId = LINIf_Frame_Cfg_Tab[frameCfgIdx].pduIdOfFrameList;
            channelDataPtrTmp->currentFrameType = LINIf_Frame_Cfg_Tab[frameCfgIdx].frameType;
            channelDataPtrTmp->frameHandle = frameCfgIdx;
            PduPtr->Drc = pduDirection;
            pduInfo.SduLength = LINIf_Frame_Cfg_Tab[frameCfgIdx].lengthOfFrameList;

            if( LINIF_SLV_SLAVE_RESPONSE == pduDirection ) 
            {
                if( LINIF_FRMTYPE_SRF == channelDataPtrTmp->currentFrameType)
                {
                    if( FALSE == channelDataPtrTmp->txFrameConfirmFlag )
                    {
                        retVal = LinIf_HeaderIndication_DiagTx(Channel, PduPtr, LinIf_slaveChannelData,frameCfgIdx);
                        if( E_OK == retVal)
                        {
                            channelDataPtrTmp->txFrameConfirmFlag = TRUE;
                        }
                        else
                        {
                            /* Do nothing */
                        }
                    }
                    /* A tx Frame is being sent, before transmitted frame as lost */
                    else 
                    {
                        retVal = LinIf_HeaderIndication_DiagTx(Channel, PduPtr, LinIf_slaveChannelData,frameCfgIdx);
                        if( E_NOT_OK == retVal)
                        {
                            channelDataPtrTmp->txFrameConfirmFlag = FALSE;
                        }
                        else
                        {
                            /* Do nothing */
                        }
                        chkRslt =  LINIF_E_RESPONSE;
                    }
                    retVal = E_OK;
                }
                else
                {
                    pduInfo.SduDataPtr = (uint8*)(&(channelDataPtrTmp->LinIf_TxData[LINIF_INIT_ZERO]));
                    if( FALSE == channelDataPtrTmp->txFrameConfirmFlag )
                    {
                        if( (Std_ReturnType)E_OK == LinIf_TxTriggerTransmitUL_Process(frameCfgIdx, upPduId, &pduInfo) )
                        {
                            channelDataPtrTmp->txFrameConfirmFlag = TRUE;
                            retVal = E_OK;
                        }
                        else
                        {
                            PduPtr->Drc = LINIF_SLV_FRAMERESPONSE_IGNORE;
                        }
                    }
                    else
                    {
                        if( (Std_ReturnType)E_OK == LinIf_TxTriggerTransmitUL_Process(frameCfgIdx, upPduId, &pduInfo) )
                        {
                            retVal = E_OK;
                        }
                        else
                        {
                            channelDataPtrTmp->txFrameConfirmFlag = FALSE;
                            PduPtr->Drc = LINIF_SLV_FRAMERESPONSE_IGNORE;
                        }
                        chkRslt =  LINIF_E_RESPONSE;
                    }
                }
            }
            else if( LINIF_SLV_MASTER_RESPONSE == pduDirection )
            {
                /* Slave reception of master request frame */
                PduPtr->Dl = LINIf_Frame_Cfg_Tab[frameCfgIdx].lengthOfFrameList;
                PduPtr->Cs = LINIf_Frame_Cfg_Tab[frameCfgIdx].chkSumType;
                if( FALSE == channelDataPtrTmp->rxFrameReceiveFlag )
                {
                    channelDataPtrTmp->rxFrameReceiveFlag = TRUE;
                }
                else
                {
                    chkRslt = LINIF_E_RESPONSE;
                }
                retVal = E_OK;
            }
            else
            /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                /* Do nothing */
            }
            
            if( (E_OK == retVal) && (LINIF_FRMTYPE_UNCONDITIONALFRAME == channelDataPtrTmp->currentFrameType) )
            {
                /* polyspace +2 MISRA-C3:9.1 [Justified:Unset] "NSCA_Polyspace_LinIf_Rule9.1" */
                /* polyspace +1 RTE:NIVL [Justified:Unset] "NSCA_Polyspace_LinIf_UninitializedLocalVariable" */
                LinIf_SetPduPtrValues(channelDataPtrTmp, pduInfo, frameCfgIdx, PduPtr);
            }
        }
        
        /* [SWS_LinIf_00761]: When the function LinIf_HeaderIndication is called the first time 
            after LinIf_Wakeup was called with return code E_OK, the LIN Interface shall issue 
            the function <User>_WakeupConfirmation with the parameter TRUE */
        if( (LINIF_INIT_ZERO == channelDataPtrTmp->firstReceiveHeaderFlag) &&
            (LINIF_INIT_ONE == LinIf_ChannelData[Channel].nodeWakeUpFlag) )
        {
            LinIf_WakeupConfirmationUL_Process(Channel, LinIf_Channl_Cfg_Tab[Channel].ComMChannelRef, TRUE);
            channelDataPtrTmp->firstReceiveHeaderFlag = LINIF_INIT_ONE;
        }
        else
        {
            /* Do nothing */
        }
    }

#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( chkRslt != LINIF_E_NO_ERR ) /* Error detected. */
    {
        if( LINIF_E_RESPONSE == chkRslt )
        {
            LinIf_Det_ReportRuntimeError(LINIF_HEADERINDICATION, chkRslt);
        }
        else
        {
            /* Report ErrorId to Det. */
            LinIf_Det_ErrorReport(LINIF_HEADERINDICATION, chkRslt);
        }
    }
#else
    LINIF_DUMMY_STATEMENT(chkRslt);
#endif

    return retVal;
}

/*
********************************************************************************
* Function Name: LinIf_LinErrorIndication
*
* Explanation: The LIN Driver will call this function to report a detected error
*              event during header or response processing. This function is only
*              applicable for LIN slave nodes (available only if the ECU has any
*              LIN slave channel).
*
* param: Channel: Identification of the LIN channel.
*        ErrorStatus:  Type of detected error.
*
* retval: None.
********************************************************************************
*/
FUNC(void, LINIF_CODE) LinIf_LinErrorIndication
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel,
    Lin_SlaveErrorType ErrorStatus
)
{
    uint8 chkRslt = LINIF_E_NO_ERR;
    uint8 errorSignalData = (uint8)LINIF_INIT_ZERO;
    uint16 frameHandleTmp = LINIF_INIT_ZERO;
    PduIdType upPduId;
    uint16 errorSignalId;
    LinIf_ChannelDataType* channelDataPtrTmp = NULL_PTR;

    if( Channel >= LINIF_CHANNEL_NUMTOTAL )
    {
        chkRslt = LINIF_E_NONEXISTENT_CHANNEL;
    }
    else
    {
        if( LINIF_CHANNEL_SLAVE == LinIf_Channl_Cfg_Tab[Channel].nodeChannelType )
        {
            errorSignalId = LinIf_Channl_Cfg_Tab[Channel].errorSignalId;
            channelDataPtrTmp = &LinIf_ChannelData[Channel];
            channelDataPtrTmp->busMaxIdleCnt = LinIf_Channl_Cfg_Tab[Channel].channelIdleCnt;
            frameHandleTmp = channelDataPtrTmp->frameHandle;
            switch(ErrorStatus)
            {
                case LIN_ERR_HEADER:
                    /* Do nothing */
                    break;
                case LIN_ERR_RESP_STOPBIT:
                case LIN_ERR_RESP_CHKSUM:
                case LIN_ERR_RESP_DATABIT:
                case LIN_ERR_INC_RESP:
                    chkRslt = LINIF_E_RESPONSE;
                    if( LINIF_INVALID_COMSIGNALID != LinIf_Channl_Cfg_Tab[Channel].errorSignalId )
                    {
                        errorSignalData = LinIf_ChannelData[Channel].errorSignalValue;
                        LinIf_ChannelData[Channel].errorSignalValue = LINIF_INIT_ONE;
                        if( errorSignalData != LinIf_ChannelData[Channel].errorSignalValue )
                        {
                            errorSignalData = LinIf_ChannelData[Channel].errorSignalValue;
                            (void)Com_SendSignal(errorSignalId, &errorSignalData);
                            if( NULL_PTR != LinIfResponseErrorSignalChangedCallout )
                            {
                                LinIfResponseErrorSignalChangedCallout(Channel, TRUE);
                            }
                        }
                    }
                    break;
                default:
                    /* Do Nothing. */
                    break;
            }
            if( frameHandleTmp < LINIF_FRAME_NUMBER )
            {
                upPduId = LINIf_Frame_Cfg_Tab[frameHandleTmp].pduIdOfFrameList;
                LinIf_TxConfirmationUL_Process(frameHandleTmp, upPduId, E_NOT_OK);
            }
        }
    }
#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( chkRslt != LINIF_E_NO_ERR ) /* Error detected. */
    {
        if( LINIF_E_RESPONSE == chkRslt )
        {
            LinIf_Det_ReportRuntimeError(LINIF_LINERRORINDICATION, chkRslt);
        }
        else
        {
            /* Report ErrorId to Det. */
            LinIf_Det_ErrorReport(LINIF_LINERRORINDICATION, chkRslt);
        }
    }
#else
    LINIF_DUMMY_STATEMENT(chkRslt);
#endif
}

#if( LINIF_TP_SUPPORTED == STD_ON )
/*
********************************************************************************
* Function Name: LinTp_SlaveTxConfirmation
*
* Explanation: If response from to tp layer，Requesting data from tp layers.
*              This function is only applicable for LIN slave nodes.
*
* param: Channel: Identification of the LIN channel. 
*
* retval: None.
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinTp_SlaveTxConfirmation
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    LinTp_ControlType* tpCtrlTmp = &LinTp_Ctrl.raw[Channel];
    uint8 retVal = E_NOT_OK;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    LinIf_ChannelDataType* channelDataPtrTmp = &LinIf_ChannelData[Channel];

    if( LINTP_INIT_ZERO == tpCtrlTmp ->linTp_RemainingLength )
    {
        /* Slave: stop the N_As timer after  the response transmission */
        tpCtrlTmp ->linTp_Timer = LINTP_INIT_ZERO;
        tpCtrlTmp ->linTp_Ch_State = LINTP_CHANNEL_IDLE;
        tpCtrlTmp->linTp_PortNotifity = (uint8)LINTP_APPLICATIVE_SCHEDULE;
        (void)PduR_LinTpTxConfirmation(tpCtrlTmp->linTp_Curr_UL_NSdu_Id, E_OK);
        /* After the tx process is completed, the related flag is cleared. */
        channelDataPtrTmp->txFrameConfirmFlag = FALSE;
    }
    else
    {
        /* Prepare buffer for next CF. */
        tpCtrlTmp->linTp_SN = (uint8)((tpCtrlTmp->linTp_SN + LINTP_INIT_ONE) & LINTP_8BIT_LOW4BIT);
        /* Set PCI. */
        tpCtrlTmp->linTp_Tx_Rx_Buffer[LINTP_INIT_ONE] = (uint8)(LINTP_FRAMETYPE_CF | tpCtrlTmp->linTp_SN);
        tpCtrlTmp->linTp_Tx_Rx_Buffer_Idx = LINTP_INIT_TWO;
        /* Prepare pdu structure for buffer request. */
        tpCtrlTmp->linTp_PduInfoPtr.SduDataPtr = &tpCtrlTmp->linTp_Tx_Rx_Buffer[LINTP_INIT_TWO];
        if( tpCtrlTmp->linTp_RemainingLength <= LINTP_LENGTH_6BYTE )
        {
            tpCtrlTmp->linTp_PduInfoPtr.SduLength = tpCtrlTmp->linTp_RemainingLength;
        }
        else
        {
            tpCtrlTmp->linTp_PduInfoPtr.SduLength = LINTP_LENGTH_6BYTE;
        }

        /* If request for new transmission data is accepted */
        retVal = LinTp_TxDataRequest(tpCtrlTmp);
        if( (Std_ReturnType)E_NOT_OK == retVal )
        {
            /* If request is denied, close connection and inform PduR - permanent failure. */
            LinTp_TxCloseConnection(tpCtrlTmp);
            channelDataPtrTmp->txFrameConfirmFlag = FALSE;
        }
        else
        {
            /* Request accepted, reload timer with CF timeout value. N_Cs timeout */
            tpCtrlTmp->linTp_Timer = tpCtrlTmp->linTp_TimerReload;
        }
    }
}
#endif  /* LINIF_TP_SUPPORTED == STD_ON */

/*
********************************************************************************
* Function Name: LinIf_TxConfirmation
*
* Explanation: The LIN Driver will call this function to report a successfully
*              transmitted response. This function is only applicable for LIN
*              slave nodes.
*
* param: Channel: Identification of the LIN channel.
*
* retval: None.
********************************************************************************
*/
FUNC(void, LINIF_CODE) LinIf_TxConfirmation
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel
)
{
    uint8 chkRslt = LINIF_E_NO_ERR;
    uint16 frameHandleTmp = LINIF_INIT_ZERO;
    PduIdType upPduId;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    LinIf_ChannelDataType* channelDataPtrTmp = &LinIf_ChannelData[Channel];
    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.14" Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_LinIf_TAINTED_ARRAY_INDEX" */
    const LinIf_SlaveChannel_Nc_ConfigType* LinIf_slaveChannelData =  LinIf_SlaveChannel_Nc_ConfigData[Channel];
    uint8 errorSignalData = (uint8)LINIF_INIT_ZERO;
    uint16 errorSignalId;

    if( Channel >= LINIF_CHANNEL_NUMTOTAL )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        chkRslt = LINIF_E_NONEXISTENT_CHANNEL;
    }
    else
    {
        if( (TRUE == channelDataPtrTmp->txFrameConfirmFlag) && 
            (LINIF_CHANNEL_SLAVE == LinIf_Channl_Cfg_Tab[Channel].nodeChannelType) )
        {
#if( (LINIF_TP_SUPPORTED == STD_ON) || (LINTP_NC_SUPPORTED == STD_ON) )
            if( LINIF_FRMTYPE_SRF == channelDataPtrTmp->currentFrameType )
            {
                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
                if( (NULL_PTR != LinIf_slaveChannelData) && (LINTP_INIT_ZERO != LinIf_slaveChannelData->LinIf_NcRespBuffer[LINTP_INIT_ZERO]) )
                {
                    /* Clear response pending flag */
                    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
                    LinIf_slaveChannelData->LinIf_NcRespBuffer[LINTP_INIT_ZERO] = LINTP_INIT_ZERO;
                    /* Stop the timer if a pending node configuration response has been transmitted successfully */
                    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
                    *LinIf_slaveChannelData->LinIf_NasTimer = LINTP_INIT_ZERO;
                }
                else
                {
#if( LINIF_TP_SUPPORTED == STD_ON )
                    LinTp_SlaveTxConfirmation(Channel);
#endif
                }
            }
            /* Otherwise response to an unconditional Tx frame */
            else
#endif
            {
                frameHandleTmp = channelDataPtrTmp->frameHandle;
                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" */
                upPduId = LINIf_Frame_Cfg_Tab[frameHandleTmp].pduIdOfFrameList;
                LinIf_TxConfirmationUL_Process(frameHandleTmp, upPduId, E_OK);
                /* After the tx process is completed, the related flag is cleared. */
                channelDataPtrTmp->txFrameConfirmFlag = FALSE;
            }

            if( (LINIF_INVALID_COMSIGNALID != LinIf_Channl_Cfg_Tab[Channel].errorSignalId) &&
                (LINIf_Frame_Cfg_Tab[frameHandleTmp].frameId == LinIf_Channl_Cfg_Tab[Channel].frameIdOfErrorSignal) )
            {
                errorSignalId = LinIf_Channl_Cfg_Tab[Channel].errorSignalId;
                errorSignalData = LinIf_ChannelData[Channel].errorSignalValue;
                LinIf_ChannelData[Channel].errorSignalValue = LINIF_INIT_ZERO;
                if( errorSignalData != LinIf_ChannelData[Channel].errorSignalValue )
                {
                    errorSignalData = LinIf_ChannelData[Channel].errorSignalValue;
                    (void)Com_SendSignal(errorSignalId, &errorSignalData);
                    if( NULL_PTR != LinIfResponseErrorSignalChangedCallout )
                    {
                        LinIfResponseErrorSignalChangedCallout(Channel, FALSE);
                    }
                }
            }
        }
    }
#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( chkRslt != LINIF_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinIf_Det_ErrorReport(LINIF_TXCONFIRMATION, chkRslt);
    }
#else
        LINIF_DUMMY_STATEMENT(chkRslt);
#endif

}

/*
********************************************************************************
* Function Name: LinIf_EvaluatePID
*
* Explanation: The function is called in LinIf_HeaderIndication, to evaluate if 
*              the pid of received pdu is valid or not.
*
* param: Channel: Identification of the LIN channel.
*        PduDirection: Direction of pdu.
*        PId:  pid of pdu.
*
* retval: boolean
********************************************************************************
*/
static FUNC(boolean, LINIF_CODE) LinIf_EvaluatePID
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel,
    P2VAR(Lin_FrameResponseType, AUTOMATIC, LINIF_APPL_DATA) PduDirection,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    uint8 PId,
    P2VAR(uint16, AUTOMATIC, LINIF_APPL_DATA) FrameCfgIdx
)
{
    boolean retVal = FALSE;
    uint8 index = LINIF_INIT_ZERO;
    uint8 frameId = LINIF_INVALID_FRAMEID;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    uint8* frameIdInfo = LinIf_Channl_Cfg_Tab[Channel].frameIdOfChannel;

    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( NULL_PTR != frameIdInfo )
    {
        for( index = LINIF_INIT_ZERO; index < LINIF_PIDCONVERTTABLE_SIZE; index++ )
        {
            if( PId == LinIf_Pid_Convert_Table[index] )
            {
                frameId = index;
                break;
            }
        }
        /* Search in the pid array of the given channel, if the given pid exists or not */
        if( LINIF_INVALID_FRAMEID != frameId )
        {
            for( index = LINIF_INIT_ZERO; index < LinIf_Channl_Cfg_Tab[Channel].maxFrameCnt; index++ )
            {
                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
                if( frameId == frameIdInfo[index] )
                {
                    retVal = TRUE;
                    break;
                }
            }
        }
    }
    if( TRUE == retVal )
    {
        for( index = LINIF_INIT_ZERO; index < LINIF_FRAME_NUMBER; index++ )
        {
            /* Search the frame array, to get the upper pduid of the frame */
            if( (frameId == LINIf_Frame_Cfg_Tab[index].frameId) && 
                (Channel == LINIf_Frame_Cfg_Tab[index].channelId) )
            {
                *FrameCfgIdx = index;
                break;
            }
        }
        if( LINIF_FRAME_NUMBER == index )
        {
            retVal = FALSE;
            *PduDirection = LINIF_SLV_FRAMERESPONSE_IGNORE;
        }
        else
        {
            *PduDirection = LINIf_Frame_Cfg_Tab[index].pduDirection;
        }
    }
    else
    {
        *PduDirection = LINIF_SLV_FRAMERESPONSE_IGNORE;
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: LinIf_SetPduPtrValues
*
* Explanation: The function is used to set pdu pointer value
*
* param: LinIf_ChannelDataPtr: Channel data pointer
*        pduInfo: pdu info
*        LinIfFrameHandle: Frame index
*        PduPtr: pdu pointer, whose value is waiting for setting.
*
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinIf_SetPduPtrValues
(
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinIf_ChannelDataPtr,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    PduInfoType PduInfo,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    uint16 FrameCfgIdx,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_VAR) PduPtr
)
{
    uint8 byteIndex = LINIF_INIT_ZERO;

    if( LINIF_SLV_MASTER_RESPONSE == LINIf_Frame_Cfg_Tab[FrameCfgIdx].pduDirection ) 
    {
        LinIf_ChannelDataPtr->pduRNotificationPduId = LINIf_Frame_Cfg_Tab[FrameCfgIdx].pduIdOfFrameList;
        LinIf_ChannelDataPtr->pduRNotificationPduLength = LINIf_Frame_Cfg_Tab[FrameCfgIdx].lengthOfFrameList;
    }
    else if( LINIF_SLV_SLAVE_RESPONSE == LINIf_Frame_Cfg_Tab[FrameCfgIdx].pduDirection )  
    {
        if( (NULL_PTR != PduPtr->SduPtr) && (NULL_PTR != PduInfo.SduDataPtr) )
        {
            for( byteIndex = LINIF_INIT_ZERO; byteIndex < PduInfo.SduLength; byteIndex++ )
            {
                /* Polyspace +2 RTE:NIV [Justified:Unset] "NSCA_Polyspace_LinIf_NIV" */
                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
                PduPtr->SduPtr[byteIndex] = PduInfo.SduDataPtr[byteIndex];
            }
        }
    }
    else
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Do nothing */
    }
    PduPtr->Cs = LINIf_Frame_Cfg_Tab[FrameCfgIdx].chkSumType;
    PduPtr->Dl = (uint8)PduInfo.SduLength;
}
#endif /* LINIF_SLAVE_SUPPORT == STD_ON */

#if( LINIF_TP_SUPPORTED == STD_ON )
/*
********************************************************************************
* Function Name: LinTp_Init
*
* Explanation: Initializes the LIN Transport Layer.(Synchronous)
*
* param: ConfigPtr: Pointer to the LIN Transport Protocol configuration.
*
* retval: None
********************************************************************************
*/
FUNC(void, LINIF_CODE) LinTp_Init
(
    P2CONST(LinTp_ConfigType, AUTOMATIC, LINIF_APPL_CONST) ConfigPtr
)
{
    uint8 chkRslt = LINIF_E_NO_ERR;
    uint8 channelTmp;

    LINIF_DUMMY_STATEMENT(ConfigPtr);
    if( (boolean)TRUE == LinTp_Init_Finish )
    {
        chkRslt = LINIF_E_ALREADY_INITIALIZED;
    }
    else
    {
        LinTp_Init_Finish = TRUE;
        /* Initialize all channel dependent transport protocol variables for all channels. */
        for( channelTmp = LINIF_INIT_ZERO; channelTmp < LINTP_CHANNEL_NUMBER; channelTmp++ )
        {
            /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
            LinTp_ControlType* tpCtrlTmp = &LinTp_Ctrl.raw[channelTmp];
            tpCtrlTmp->linTp_Ch_State = LINTP_CHANNEL_IDLE;
            /* Clear NAD of request. */
            tpCtrlTmp->linTp_NAD_Requested = LINIF_INIT_ZERO;
            tpCtrlTmp->linTp_P2Timer = LINIF_INIT_ZERO;
            tpCtrlTmp->linTp_RespPendingCounter = LINIF_INIT_ZERO;
            tpCtrlTmp->linTp_ComModeRestore = (uint8)LINTP_APPLICATIVE_SCHEDULE;
            tpCtrlTmp->linTp_FuncRequest = LINTP_FUNC_REQUEST_IDLE;
            tpCtrlTmp->linTp_PortNotifity = (uint8)LINTP_PORTNOTIFITY_IDLE;
            tpCtrlTmp->linTp_Timer = LINIF_INIT_ZERO;
            tpCtrlTmp->linTp_SN = LINIF_INIT_ZERO;
            tpCtrlTmp->linTp_PduRNotifity = LINTP_PDURNOTIFITY_IDLE;
            tpCtrlTmp->linTp_Curr_Rx_Id = LINIF_INIT_ZERO;
            tpCtrlTmp->linTp_Curr_Tx_Id = LINIF_INIT_ZERO;
            tpCtrlTmp->LinTp_MaxBufReqCounter = LINIF_INIT_ZERO;
            tpCtrlTmp->linTp_PduInfoPtr.SduDataPtr = NULL_PTR;
            tpCtrlTmp->linTp_PduInfoPtr.SduLength = LINIF_INIT_ZERO;
            tpCtrlTmp->linTp_RemainingLength = LINIF_INIT_ZERO;
            tpCtrlTmp->linTp_Curr_UL_NSdu_Id = LINIF_INIT_ZERO;
            tpCtrlTmp->linTp_Tx_Rx_Buffer_Idx = LINIF_INIT_ZERO;
            tpCtrlTmp->linTp_Tx_Rx_Buffer_Length = LINIF_INIT_ZERO;
            tpCtrlTmp->LinTp_NodeType = LinIf_Channl_Cfg_Tab[channelTmp].nodeChannelType;
        }
    }
#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( chkRslt != LINIF_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinIf_Det_ErrorReport(LINTP_INIT, chkRslt);
    }
#else
    LINIF_DUMMY_STATEMENT(chkRslt);
#endif

}

/*
********************************************************************************
* Function Name: LinTp_Transmit
*
* Explanation: Requests the transfer of segmented data.(Asynchronous)
*
* param: LinTpTxSduId: This parameter contains the unique identifier of the N-SDU
*                      (TP message) to be transmitted.
*        LinTpTxInfoPtr: A pointer to a structure with N-SDU related data containing:
*                        - pointer to a N-SDU buffer
*                        - length of this buffer.
*
* retval: Std_ReturnType: E_OK: The request can be started successfully
*                         E_NOT_OK: The request can not be started
********************************************************************************
*/
FUNC(Std_ReturnType, LINIF_CODE) LinTp_Transmit
(
    PduIdType LinTpTxSduId,
    P2CONST(PduInfoType, AUTOMATIC, LINIF_APPL_CONST) LinTpTxInfoPtr
)
{
    uint8 chkRslt;
    Std_ReturnType retVal = E_NOT_OK;
    LinTp_ControlType* tpCtrlTmp = NULL_PTR;

    chkRslt = LinIf_Chk_TpTransmit(LinTpTxSduId, LinTpTxInfoPtr);
    if( LINIF_E_NO_ERR == chkRslt )
    {
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.14" Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_LinIf_TAINTED_ARRAY_INDEX" */
        tpCtrlTmp = &LinTp_Ctrl.raw[LinTp_TxNSdu[LinTpTxSduId].ctrlIdxOfTxNSdu];
        tpCtrlTmp->linTp_Curr_Tx_Id = LinTpTxSduId;
        /* If requested Nsdu is a valid functional request. */
        /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.14" Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_LinIf_TAINTED_ARRAY_INDEX" */
        if( (LINTP_VALUE_0X7E == LinTp_TxNSdu[LinTpTxSduId].nadOfTxNSdu)
            /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.14" Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_LinIf_TAINTED_PTR" */
            && (LinTpTxInfoPtr->SduLength > LINTP_INIT_ZERO)
            && (LinTpTxInfoPtr->SduLength <= LINTP_LENGTH_6BYTE) )
        {
            tpCtrlTmp->linTp_FuncPduInfoPtr.SduLength = LinTpTxInfoPtr->SduLength;
            /* Request appropriate schedule. */
            tpCtrlTmp->linTp_PortNotifity = (uint8)LINTP_DIAG_REQUEST;
            /* Store NSdu of functional request. */
            tpCtrlTmp->linTp_Curr_Func_NSdu_Id = LinTp_TxNSdu[LinTpTxSduId].upperLayerPduIdOfTxNSdu;
            tpCtrlTmp->linTp_FuncRequest = LINTP_FUNC_REQUEST_PENDING;
            retVal = (Std_ReturnType)E_OK;
        }
        /* Otherwise: (physical request). */
        else
        {
            /* If Tp Rx connection already active, abort it to accept new request (LIN master channel) or ignore new request (LIN slave channel) */
            if( LINTP_CHANNEL_RX_MSK == (tpCtrlTmp->linTp_Ch_State & LINTP_CHANNEL_RX_MSK) )
            {
                if( LINIF_CHANNEL_MASTER == tpCtrlTmp->LinTp_NodeType )
                {
                    /* If channel is a LIN master channel, abort Rx connection to accept the new request */
                    (void)PduR_LinTpRxIndication(tpCtrlTmp->linTp_Curr_UL_NSdu_Id, E_NOT_OK); /* Direct notification to PduR. */
                    tpCtrlTmp->linTp_Timer = LINTP_INIT_ZERO;
                    tpCtrlTmp->linTp_P2Timer = LINTP_INIT_ZERO;
                    tpCtrlTmp->linTp_Ch_State = LINTP_CHANNEL_IDLE;
                    /* Request applicative schedule here, overwritten below if request is accepted. */
                    tpCtrlTmp->linTp_PortNotifity = (uint8)LINTP_APPLICATIVE_SCHEDULE;
                    tpCtrlTmp->linTp_ComModeRestore = (uint8)LINTP_APPLICATIVE_SCHEDULE; 
                }
                else
                {
                    /* If channel is a LIN slave channel, ignore new request and keep the Rx connection */
                }
            }

            if( (LINIF_CHANNEL_MASTER == tpCtrlTmp->LinTp_NodeType) || 
                ((LINIF_CHANNEL_SLAVE == tpCtrlTmp->LinTp_NodeType) && 
                 (LINTP_CHANNEL_RX_MSK != (tpCtrlTmp->linTp_Ch_State & LINTP_CHANNEL_RX_MSK))) )
            {
                /* Channel idle, prepare frame: setup connection, init local buffer. */
                tpCtrlTmp->linTp_Curr_UL_NSdu_Id = LinTp_TxNSdu[LinTpTxSduId].upperLayerPduIdOfTxNSdu;
                /* Save internal ID of corresponding RxNSdu. */
                tpCtrlTmp->linTp_Curr_Rx_Id = LinTp_TxNSdu[LinTpTxSduId].associatedRxNSduIdOfTxNSdu;
                tpCtrlTmp->linTp_Tx_Rx_Buffer[LINTP_INIT_ZERO] = LinTp_TxNSdu[LinTpTxSduId].nadOfTxNSdu;
                /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.14" Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_LinIf_TAINTED_PTR" */
                tpCtrlTmp->linTp_RemainingLength = LinTpTxInfoPtr->SduLength;
                /* Prepare frame: Set PCI information depending in frame type. */
                if( LinTpTxInfoPtr->SduLength <= LINTP_LENGTH_6BYTE )
                {
                    /* SF request. */
                    tpCtrlTmp->linTp_Tx_Rx_Buffer[LINTP_INIT_ONE] = (uint8)(LinTpTxInfoPtr->SduLength & LINTP_INIT_SEVEN);
                    tpCtrlTmp->linTp_Tx_Rx_Buffer_Idx = LINTP_INIT_TWO;
                    tpCtrlTmp->linTp_PduInfoPtr.SduDataPtr  = &tpCtrlTmp->linTp_Tx_Rx_Buffer[LINTP_INIT_TWO];
                    tpCtrlTmp->linTp_PduInfoPtr.SduLength   = LinTpTxInfoPtr->SduLength;
                }
                else
                {
                    /* Multi frame request. */
                    /* Set FF token and upper nibble of data length. */
                    tpCtrlTmp->linTp_Tx_Rx_Buffer[LINTP_INIT_ONE]
                        = (uint8)(((LinTpTxInfoPtr->SduLength & LINTP_16BIT_HIGH4BIT) >> LINTP_LENGTH_8BYTE) | LINTP_FRAMETYPE_FF);
                    /* Set lower data length byte. */
                    tpCtrlTmp->linTp_Tx_Rx_Buffer[LINTP_INIT_TWO] = (uint8)(LinTpTxInfoPtr->SduLength & LINTP_16BIT_LOW8BIT);
                    tpCtrlTmp->linTp_SN = LINTP_INIT_ZERO;
                    tpCtrlTmp->linTp_PduInfoPtr.SduDataPtr = &tpCtrlTmp->linTp_Tx_Rx_Buffer[LINTP_INIT_THREE];
                    tpCtrlTmp->linTp_PduInfoPtr.SduLength = LINTP_INIT_FIVE;  /* FF Length */
                }

                /* Set LinTp state. */
                tpCtrlTmp->linTp_Ch_State = LINTP_CHANNEL_BUSY_TX_INVALID;
                /* Limit the number retries for copy Tx data */
                if( tpCtrlTmp->LinTp_MaxBufReqCounter <= LinTp_TxNSdu[LinTpTxSduId].LinTpMaxBufReq )
                {
                    retVal = (Std_ReturnType)E_OK;
                }
                else
                {
                    /* Abort transmission. */
                    retVal = (Std_ReturnType)E_NOT_OK;
                    tpCtrlTmp->LinTp_MaxBufReqCounter = LINTP_INIT_ZERO;
                }

                if( (Std_ReturnType)E_NOT_OK == retVal )
                {
                    (void)PduR_LinTpTxConfirmation(tpCtrlTmp->linTp_Curr_UL_NSdu_Id, E_NOT_OK);
                    tpCtrlTmp->linTp_Ch_State = LINTP_CHANNEL_IDLE;
                }
                /* Otherwise: save NAD, activate Tp timer, trigger diagnostic request schedule. */
                else
                {
                    /* Slave: Activate SF/FF confirmation timeout */
                    tpCtrlTmp->linTp_Timer = LinTp_TxNSdu[LinTpTxSduId].nasOfTxNSdu;  /* SWS_LinIf_00657 */
                    /* Next timeout reload value refers to CFs. */
                    tpCtrlTmp->linTp_TimerReload = LinTp_TxNSdu[LinTpTxSduId].ncsOfTxNSdu;  /* SWS_LinIf_00661 */
                    /* Save current NAD - only matching responses are accepted. */ /*If channel is master*/
                    tpCtrlTmp->linTp_NAD_Requested = LinTp_TxNSdu[LinTpTxSduId].nadOfTxNSdu;
                    /* Clear response pending counter. */
                    tpCtrlTmp->linTp_RespPendingCounter = LINTP_INIT_ZERO;
                    /* Clear P2 timer. */
                    tpCtrlTmp->linTp_P2Timer = LINTP_INIT_ZERO;
                    tpCtrlTmp->linTp_PortNotifity = (uint8)LINTP_DIAG_REQUEST;
                    tpCtrlTmp->linTp_ComModeRestore = (uint8)LINTP_DIAG_REQUEST;
                    
                }
            }
        }
    }
    else
    {
#if( LINIF_DEV_ERROR_DETECT == STD_ON )
        /* Report ErrorId to Det. */
        LinIf_Det_ErrorReport(LINTP_TRANSMIT, chkRslt);
#else
        LINIF_DUMMY_STATEMENT(chkRslt);
#endif
    }
    
    return retVal;
}

/*
********************************************************************************
* Function Name: LinTp_GetVersionInfo
*
* Explanation: Returns the version information of this module.(Synchronous)
*
* param: versioninfo: Pointer to where to store the version information of this module.
*
* retval: None
********************************************************************************
*/
FUNC(void, LINIF_CODE) LinTp_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, LINIF_APPL_DATA) versioninfo
)
{
    uint8 chkRslt = LINIF_E_NO_ERR;

    if( NULL_PTR == versioninfo )   /* Pointer parameter is Null. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        chkRslt = LINIF_E_PARAM_POINTER;
    }
    else
    {
        /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.14" Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_LinIf_TAINTED_PTR" */
        versioninfo->vendorID = LINIF_VENDOR_ID;
        versioninfo->moduleID = LINIF_MODULE_ID;
        versioninfo->sw_major_version = LINIF_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = LINIF_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = LINIF_SW_PATCH_VERSION;
    }
#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( chkRslt != LINIF_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinIf_Det_ErrorReport(LINTP_GET_VERSION_INFO, chkRslt);
    }
#else
    LINIF_DUMMY_STATEMENT(chkRslt);
#endif

}

/*
********************************************************************************
* Function Name: LinTp_Shutdown
*
* Explanation: Shutdowns the LIN TP.(Synchronous)
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, LINIF_CODE) LinTp_Shutdown(void)
{
    uint8 chkRslt;
    uint8 channelTmp;
    LinTp_ControlType* tpCtrlTmp = NULL_PTR;

    chkRslt = LinTp_Chk_Shutdown();
    if( LINIF_E_NO_ERR == chkRslt )
    {
        /* Clear all LIN TP resources. */
        /* Reset all transport protocol variables and connections for all LinIf channels. */
        for( channelTmp = LINIF_INIT_ZERO; channelTmp < LINTP_CHANNEL_NUMBER; channelTmp++ )
        {
            tpCtrlTmp = &LinTp_Ctrl.raw[channelTmp];
            tpCtrlTmp->linTp_Timer = LINIF_INIT_ZERO;
            tpCtrlTmp->linTp_Ch_State = LINTP_CHANNEL_IDLE;
            tpCtrlTmp->linTp_NAD_Requested = LINIF_INIT_ZERO;
            tpCtrlTmp->linTp_P2Timer = LINIF_INIT_ZERO;
        }
        LinTp_Init_Finish = FALSE;
    }
#if( LINIF_DEV_ERROR_DETECT == STD_ON )
        if( chkRslt != LINIF_E_NO_ERR ) /* Error detected. */
        {
            /* Report ErrorId to Det. */
            LinIf_Det_ErrorReport(LINTP_SHUT_DOWN, chkRslt);
        }
#else
        LINIF_DUMMY_STATEMENT(chkRslt);
#endif

}

/*
********************************************************************************
* Function Name: LinTp_CancelTransmit
*
* Explanation: This is a dummy method introduced for interface compatibility.(Synchronous)
*
* param: LinTpTxSduId: This parameter contains the Lin TP instance unique identifier
*                      of the Lin N-SDU which transfer has to be cancelled.
*
* retval: Std_ReturnType: E_NOT_OK: Cancellation request of the transfer of the specified Lin N-SDU is rejected
********************************************************************************
*/
FUNC(Std_ReturnType, LINIF_CODE) LinTp_CancelTransmit
(
    PduIdType LinTpTxSduId
)
{
    uint8 chkRslt;

    chkRslt = LinTp_Chk_CancelTransmit(LinTpTxSduId);
#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( chkRslt != LINIF_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinIf_Det_ErrorReport(LINTP_CANCEL_TRANSMIT, chkRslt);
    }
#else
    LINIF_DUMMY_STATEMENT(chkRslt);
#endif
    /* The cancellation request shall always be rejected by returning E_NOT_OK. */
    return E_NOT_OK;
}

/*
********************************************************************************
* Function Name: LinTp_ChangeParameter
*
* Explanation: This is a dummy method introduced for interface compatibility.(Synchronous)
*
* param: id: Identifier of the received N-SDU on which the reception parameter has to be changed.
*        parameter: The selected parameter that the request shall change (STmin).
*        value: The new value of the parameter.
*
* retval: Std_ReturnType: E_NOT_OK: E_NOT_OK: request is not accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, LINIF_CODE) LinTp_ChangeParameter
(
    PduIdType id,
    TPParameterType parameter,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    uint16 value
)
{
    uint8 chkRslt;

    chkRslt = LinTp_Chk_ChangeParameter(id, parameter, value);
#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( chkRslt != LINIF_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinIf_Det_ErrorReport(LINTP_CHANGE_PARAMETER, chkRslt);
    }
#else
    LINIF_DUMMY_STATEMENT(chkRslt);
#endif
    /* The change parameter request shall always be rejected by returning E_NOT_OK. */
    return E_NOT_OK;
}

/*
********************************************************************************
* Function Name: LinTp_CancelReceive
*
* Explanation: This is a dummy method introduced for interface compatibility.(Synchronous)
*
* param: LinTpRxSduId: This parameter contains the Lin TP instance unique identifier
*                      of the Lin N-SDU reception of which has to be cancelled..
*
* retval: Std_ReturnType: E_NOT_OK: Cancellation request of the reception of the
*                                   specified Lin N-SDU is rejected.
********************************************************************************
*/
FUNC(Std_ReturnType, LINIF_CODE) LinTp_CancelReceive
(
    PduIdType LinTpRxSduId
)
{
    uint8 chkRslt;

    chkRslt = LinTp_Chk_CancelReceive(LinTpRxSduId);
#if( LINIF_DEV_ERROR_DETECT == STD_ON )
    if( chkRslt != LINIF_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        LinIf_Det_ErrorReport(LINTP_CANCEL_RECEIVE, chkRslt);
    }
#else
    LINIF_DUMMY_STATEMENT(chkRslt);
#endif
    /* The cancellation request shall always be rejected by returning E_NOT_OK. */
    return E_NOT_OK;
}

/*
********************************************************************************
* Function Name: LinTp_RxIndication
*
* Explanation: The main processing function of the LIN Interface.
*
* param: RxPduId: ID of the received I-PDU.
*        PduInfoPtr: Contains the length (SduLength) of the received I-PDU and a
*                    pointer to a buffer (SduDataPtr) containing the I-PDU.
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinTp_RxIndication
(
    uint8 LinIf_LinIfChannel,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_CONST) LinTp_LinSduPtr
)
{
    uint8 linTpChannelTmp;
    PduIdType sduIdx;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    LinTp_ControlType* tpCtrlTmp = &LinTp_Ctrl.raw[LinIf_LinIfChannel];
    linTpChannelTmp = LinTp_LinIfToLinTpChannel[LinIf_LinIfChannel];

    /* Preprocess NAD: inspect if Strict-NAD check is disabled and received frame is valid SF or FF. */
    if( ((boolean)FALSE == LinTp_ChannelConfigData[linTpChannelTmp]->strictNADCheckOfChannelCfg ) &&
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_LinIf_NIV" */
         ( (LINTP_FRAMETYPE_SF == (LinTp_LinSduPtr[LINTP_INIT_ONE] & LINTP_8BIT_HIGH4BIT)) ||
           (LINTP_FRAMETYPE_FF == (LinTp_LinSduPtr[LINTP_INIT_ONE] & LINTP_8BIT_HIGH4BIT)) ) )
    {
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_LinIf_NIV" */
        tpCtrlTmp->linTp_NAD_Requested = LinTp_LinSduPtr[LINTP_INIT_ZERO];

        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" */
        if( LinTp_RxNSdu[tpCtrlTmp->linTp_Curr_Rx_Id].nadOfRxNSdu != LinTp_LinSduPtr[LINTP_INIT_ZERO] )
        {
            for( sduIdx = LINIF_INIT_ZERO; sduIdx < LINTP_MAXRXNSDU_CNT; sduIdx++ )
            {
                if( (LinTp_RxNSdu[sduIdx].nadOfRxNSdu == LinTp_LinSduPtr[LINTP_INIT_ZERO])
                    && (LinTp_RxNSdu[sduIdx].ctrlIdxOfRxNSdu == LinIf_LinIfChannel) )
                {
                    tpCtrlTmp->linTp_Curr_Rx_Id = (PduIdType)sduIdx;
                    break;
                }
            }
        }
    }

    /* If no transmission is active and received NAD is accepted (only if Strict-NAD check enabled). */
    /* A possible active Rx connection is handled below. */
    if( (LINIF_INIT_ZERO == (tpCtrlTmp->linTp_Ch_State & LINTP_CHANNEL_TX_MSK))
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_LinIf_NIV" */
          && (tpCtrlTmp->linTp_NAD_Requested == LinTp_LinSduPtr[LINTP_INIT_ZERO]) )
    {
        /* Test frame type for valid PCI. */
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_LinIf_NIV" */
        switch( (LinTp_LinSduPtr[LINTP_INIT_ONE] & LINTP_8BIT_HIGH4BIT) )
        {
            case LINTP_FRAMETYPE_SF:
                LinTp_RxIndication_SF(LinIf_LinIfChannel, tpCtrlTmp, LinTp_LinSduPtr);
                break;
            case LINTP_FRAMETYPE_FF:
                LinTp_RxIndication_FF(tpCtrlTmp, LinTp_LinSduPtr);
                break;
            case LINTP_FRAMETYPE_CF:
                LinTp_RxIndication_CF(tpCtrlTmp, LinTp_LinSduPtr);
                break;
            default:
                /* Do Nothing. */
                break;
        }
    }
    /* Otherwise if invalid NAD received and reception active, close Rx connection. */
    else
    {
        if( (tpCtrlTmp->linTp_Ch_State & LINTP_CHANNEL_RX_MSK) != LINTP_INIT_ZERO )
        {
            /* Unexpected NAD received - stop receiving Tp message. */
            LinTp_RxCloseConnection(tpCtrlTmp);
        }
    }
}

/*
********************************************************************************
* Function Name: LinTp_RxIndication_SF
*
* Explanation: SF rxindication.
*
* param: LinTp_CtrlPtr: LinTp channel pointer.
*        LinTp_LinSduPtr: Data pointer.
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinTp_RxIndication_SF
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    uint8 LinIfChannel,
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_CONST) LinTp_LinSduPtr
)
{
    boolean proceedHandlingFlag;
    PduIdType currId;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    const LinTp_ChannelConfigType* LinTP_ConfigData = LinTp_ChannelConfigData[LinIfChannel];
    currId = LinTp_CtrlPtr->linTp_Curr_Rx_Id;

    /* Check if NAD of response match the NAD of request. */
    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" */
    if( LinTp_RxNSdu[currId].nadOfRxNSdu == LinTp_LinSduPtr[LINTP_INIT_ZERO] )
    {
        /* Check if length information in SF is valid. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_LinIf_NIV" */
        if( (LinTp_LinSduPtr[LINTP_INIT_ONE] > LINTP_INIT_ZERO)
            && (LinTp_LinSduPtr[LINTP_INIT_ONE] <= LINTP_LENGTH_6BYTE) )
        {
            proceedHandlingFlag = TRUE;
            /* If RX connection already active on channel, abort it and inform PduR. */
            if( (LinTp_CtrlPtr->linTp_Ch_State & LINTP_CHANNEL_RX_MSK) != LINTP_INIT_ZERO )
            {
                /* Indicate error and restart reception with new SF. */
                LinTp_CtrlPtr->linTp_PduRNotifity |= LINTP_PDURNOTIFITY_RX; /* SBSW_LINIF_TP_CTRL_PTR */
                LinTp_CtrlPtr->linTp_PduRNotifyResultRx = E_NOT_OK; /* SBSW_LINIF_TP_CTRL_PTR */
                LinTp_CtrlPtr->linTp_PduRNSduIdRx = LinTp_CtrlPtr->linTp_Curr_UL_NSdu_Id;
            }
            /* Otherwise if received frame is a response pending frame (in this case channel state always idle). */
            else if( (LINTP_VALUE_0X03 == LinTp_LinSduPtr[LINTP_INIT_ONE]) &&
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_LinIf_NIV" */
                     (LINTP_VALUE_0X7F == LinTp_LinSduPtr[LINTP_INIT_TWO]) &&
                     /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_LinIf_NIV" */
                     (LINTP_VALUE_0X78 == LinTp_LinSduPtr[LINTP_INIT_FOUR]) )
            {
                /* Response pending frame. */
                /* Update RP counter and check if maximum allowed number of response pending frames received. */
                LinTp_CtrlPtr->linTp_RespPendingCounter++;
                if( LinTp_CtrlPtr->linTp_RespPendingCounter > LinTp_ChannelConfigData[LinIfChannel]->LinTp_MaxNumberOfRespPendingFrames )
                {
                    /* Abort reception, indication to PduR depends if forward-RP-frames-to-PduR feature activated, stop further handling. */
                    LinTp_CtrlPtr->linTp_PduRNotifity |= LINTP_PDURNOTIFITY_RX; 
                    LinTp_CtrlPtr->linTp_PduRNotifyResultRx = E_NOT_OK; 
                    LinTp_CtrlPtr->linTp_PduRNSduIdRx = LinTp_CtrlPtr->linTp_Curr_UL_NSdu_Id;
                    /* Reset requested NAD - only one response accepted for each request */
                    LinTp_CtrlPtr->linTp_NAD_Requested = LINTP_INIT_ZERO;
                    LinTp_CtrlPtr->linTp_P2Timer = LINTP_INIT_ZERO;
                    LinTp_CtrlPtr->linTp_PortNotifity = (uint8)LINTP_APPLICATIVE_SCHEDULE;
                    LinTp_CtrlPtr->linTp_ComModeRestore = (uint8)LINTP_APPLICATIVE_SCHEDULE;
                    /* No further handling required. */
                    proceedHandlingFlag = FALSE;
                }
                else
                {
                    /* After reception of a response pending frame the P2 timeout timer is reloaded with the timeout time P2*max. */
                    LinTp_CtrlPtr->linTp_P2Timer = LinTP_ConfigData->LinTp_P2MaxTimerOut;
                }
            }
            else
            {
                /* Reset RP counter to trigger schedule change request in LinTp_Rx_Fill_Buffer. */
                LinTp_CtrlPtr->linTp_RespPendingCounter = LINTP_INIT_ZERO;
            }

            if( (boolean)TRUE == proceedHandlingFlag )
            {
                /* Initialize new RX connection. */
                LinTp_CtrlPtr->linTp_RemainingLength = (PduLengthType)(LinTp_LinSduPtr[LINTP_INIT_ONE]);
                LinTp_CtrlPtr->linTp_Tx_Rx_Buffer_Length = (uint8)(LinTp_CtrlPtr->linTp_RemainingLength);
                /* Index of the buffer copied from - SF:2. */
                LinTp_CtrlPtr->linTp_Tx_Rx_Buffer_Idx = LINTP_INIT_TWO;
                LinTp_CtrlPtr->linTp_Curr_UL_NSdu_Id = LinTp_RxNSdu[currId].upperLayerPduIdOfRxNSdu;
                LinTp_CtrlPtr->linTp_Ch_State = LINTP_CHANNEL_BUSY_RX_WAIT_FOR_START;
                /* Start receive buffer handling. */
                /* Do buffer handling in any case, on suspended state data is copied to local buffer. */
                LinTp_RxDataBufferHandling(LinTp_CtrlPtr, LinTp_LinSduPtr);
            }
            else
            {
                /* do nothing */
            }
        }
    }
}

/*
********************************************************************************
* Function Name: LinTp_RxIndication_FF
*
* Explanation: FF rxindication.
*
* param: LinTp_CtrlPtr: LinTp channel pointer.
*        LinTp_LinSduPtr: Data pointer.
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinTp_RxIndication_FF
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_CONST) LinTp_LinSduPtr
)
{
    PduIdType currId;
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    uint16 value;
    uint16 remainLength;
    currId = LinTp_CtrlPtr->linTp_Curr_Rx_Id;

    /* Check if NAD of response match the NAD of request */
    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" */
    if( LinTp_LinSduPtr[LINTP_INIT_ZERO] == LinTp_RxNSdu[currId].nadOfRxNSdu )
    {
        /* Check if length information in FF is valid. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_LinIf_NIV" */
        value = (uint16)LinTp_LinSduPtr[LINTP_INIT_ONE] & (uint16)LINTP_8BIT_LOW4BIT;
        value = value << (uint16)LINTP_LENGTH_8BYTE;
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_LinIf_NIV" */
        value = value | (uint16)LinTp_LinSduPtr[LINTP_INIT_TWO];

        if( value > (uint16)LINTP_LENGTH_6BYTE )
        {    
            /* Valid FF length. */
            if( (LinTp_CtrlPtr->linTp_Ch_State & LINTP_CHANNEL_RX_MSK) != LINTP_INIT_ZERO )
            {
                /* Indicate error and postpone actual reception handling of FF to next cycle. */
                LinTp_CtrlPtr->linTp_PduRNotifity |= LINTP_PDURNOTIFITY_RX;
                LinTp_CtrlPtr->linTp_PduRNotifyResultRx = E_NOT_OK;
                LinTp_CtrlPtr->linTp_PduRNSduIdRx = LinTp_CtrlPtr->linTp_Curr_UL_NSdu_Id;
            }

            /* Initialize new RX connection. */
            /* Master: start the N_Cr timer after receiving SRF (FF or CF except last CF) */
            LinTp_CtrlPtr->linTp_Timer = LinTp_RxNSdu[currId].ncrOfRxNSdu;
            /* Master: stop after receiving  SRF (next CF) */
            LinTp_CtrlPtr->linTp_TimerReload = LinTp_RxNSdu[currId].ncrOfRxNSdu;
            /* Clear P2 timer. */
            LinTp_CtrlPtr->linTp_P2Timer = LINTP_INIT_ZERO;

            remainLength = ((uint16)LinTp_LinSduPtr[LINTP_INIT_ONE] & (uint16)LINTP_8BIT_LOW4BIT);
            remainLength = remainLength << (uint16)LINTP_LENGTH_8BYTE;
            remainLength = remainLength | (uint16)LinTp_LinSduPtr[LINTP_INIT_TWO];

            LinTp_CtrlPtr->linTp_RemainingLength = remainLength;
            LinTp_CtrlPtr->linTp_Tx_Rx_Buffer_Length = LINTP_INIT_FIVE;
            LinTp_CtrlPtr->linTp_Tx_Rx_Buffer_Idx = LINTP_INIT_THREE; /* Index of the buffer copied from - FF:3 */
            LinTp_CtrlPtr->linTp_SN = LINTP_INIT_ONE;
            LinTp_CtrlPtr->linTp_Curr_UL_NSdu_Id = LinTp_RxNSdu[currId].upperLayerPduIdOfRxNSdu;
            /* Reset RP counter after receiving start of response to trigger schedule change request */
            LinTp_CtrlPtr->linTp_RespPendingCounter = LINTP_INIT_ZERO;
            LinTp_CtrlPtr->linTp_Ch_State = LINTP_CHANNEL_BUSY_RX_WAIT_FOR_START;
            /* Start receive buffer handling. */
            LinTp_RxDataBufferHandling(LinTp_CtrlPtr, LinTp_LinSduPtr);
        }
    }
}

/*
********************************************************************************
* Function Name: LinTp_RxIndication_CF
*
* Explanation: CF rxindication.
*
* param: LinTp_CtrlPtr: LinTp channel pointer.
*        LinTp_LinSduPtr: Data pointer.
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinTp_RxIndication_CF
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_CONST) LinTp_LinSduPtr
)
{
    /* Check if consecutive frame is expected. */
    if( LinTp_CtrlPtr->linTp_RemainingLength > LINTP_INIT_ZERO )
    {
        /* CF awaited, note that NAD is already checked. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_LinIf_NIV" */
        if( LinTp_CtrlPtr->linTp_SN == (uint8)(LinTp_LinSduPtr[LINTP_INIT_ONE] & LINTP_8BIT_LOW4BIT) )
        {
            /* Update sequence number and Tp timeout counter. */
            LinTp_CtrlPtr->linTp_SN
              = (uint8)((LinTp_CtrlPtr->linTp_SN + LINTP_INIT_ONE) & LINTP_8BIT_LOW4BIT);
            /* Master: stop after receiving  SRF (next CF), and restart timer */
            LinTp_CtrlPtr->linTp_Timer = LinTp_CtrlPtr->linTp_TimerReload;

            /* Continue with receive buffer handling. */
            if( LinTp_CtrlPtr->linTp_RemainingLength < LINTP_LENGTH_6BYTE )
            {
                LinTp_CtrlPtr->linTp_Tx_Rx_Buffer_Length = (uint8)(LinTp_CtrlPtr->linTp_RemainingLength);
            }
            else
            {
                LinTp_CtrlPtr->linTp_Tx_Rx_Buffer_Length = LINTP_LENGTH_6BYTE;
            }

            LinTp_CtrlPtr->linTp_Tx_Rx_Buffer_Idx = LINTP_INIT_TWO; /* Index of the buffer copied from - CF:2. */
            LinTp_RxDataBufferHandling(LinTp_CtrlPtr, LinTp_LinSduPtr);
        }
        /* Otherwise: Invalid sequence number in CF. */
        else
        {
            /* Abort connection and inform PduR. */
            LinTp_RxCloseConnection(LinTp_CtrlPtr);
        }
    }
}

/*
********************************************************************************
* Function Name: LinTp_RxDataBufferHandling
*
* Explanation: Receive buffer handling.
*
* param: LinTp_CtrlPtr: LinTp channel pointer.
*        LinTp_LinSduPtr: Data pointer.
*
* retval: None.
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinTp_RxDataBufferHandling
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_CONST) LinTp_LinSduPtr
)
{
    uint8 byteIndex;
    BufReq_ReturnType bufferReqRetVal;
    PduLengthType remainingPduRBufferSize = LINIF_INIT_ZERO;

    /* Check if a PduR notification is already pending in this cycle. */
    if( ((LINIF_CHANNEL_MASTER == LinTp_CtrlPtr->LinTp_NodeType) && 
         (LINTP_PDURNOTIFITY_IDLE == (LinTp_CtrlPtr->linTp_PduRNotifity & LINTP_PDURNOTIFITY_RX))) || 
        (LINIF_CHANNEL_SLAVE == LinTp_CtrlPtr->LinTp_NodeType) )
    {
        /* If reception handling to PduR not yet started, initiate connection. */
        if( LINTP_CHANNEL_BUSY_RX_WAIT_FOR_START == LinTp_CtrlPtr->linTp_Ch_State )
        {
            /* Actual start of PduR reception handling. */
            LinTp_RxDataBufferHandling_StartOfReception(LinTp_CtrlPtr);
        }

        /* If start of reception handling succeeded or connection already established, update local buffer. */
        if( ( NULL_PTR == LinTp_LinSduPtr) || (LINTP_CHANNEL_IDLE == LinTp_CtrlPtr->linTp_Ch_State) )
        {
            /* Repeated call or StartOfReception call failed, thus SduDataPtr already point to local buffer or receive data not needed. */
            /* If on retry handling, provide the local buffer with Tp data */
            LinTp_CtrlPtr->linTp_PduInfoPtr.SduDataPtr = LinTp_CtrlPtr->linTp_Tx_Rx_Buffer;
        }
        else
        {
            /* Otherwise provide the data of the newly received frame */ 
            LinTp_CtrlPtr->linTp_PduInfoPtr.SduLength = LinTp_CtrlPtr->linTp_Tx_Rx_Buffer_Length;
            /* Copy data to local buffer in any case for data consistency. */
            for( byteIndex = LINTP_INIT_ZERO; byteIndex < LinTp_CtrlPtr->linTp_Tx_Rx_Buffer_Length; byteIndex++ )
            {
                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" */
                LinTp_CtrlPtr->linTp_Tx_Rx_Buffer[byteIndex]
                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_LinIf_NIV" */
                 = LinTp_LinSduPtr[(LinTp_CtrlPtr->linTp_Tx_Rx_Buffer_Idx + byteIndex) & LINTP_LOCAL_BUFFER_SIZE_MASK];
            }
            LinTp_CtrlPtr->linTp_PduInfoPtr.SduDataPtr = &LinTp_CtrlPtr->linTp_Tx_Rx_Buffer[LINTP_INIT_ZERO];
        }

        /* Delayed reception buffer handling. */
        /* If temporarily no sufficient receive buffer is available. */
        if( (LINTP_CHANNEL_BUSY_RX_SUSPENDED == LinTp_CtrlPtr->linTp_Ch_State)
              || (LINTP_CHANNEL_BUSY_RX_POLLBUFFER == LinTp_CtrlPtr->linTp_Ch_State) )
        {
            LinTp_CtrlPtr->linTp_PduInfoPtr.SduLength = LINTP_INIT_ZERO;
            bufferReqRetVal = PduR_LinTpCopyRxData(LinTp_CtrlPtr->linTp_Curr_UL_NSdu_Id,
                                                   &LinTp_CtrlPtr->linTp_PduInfoPtr, &remainingPduRBufferSize);
            LinTp_CtrlPtr->linTp_PduInfoPtr.SduLength = LinTp_CtrlPtr->linTp_Tx_Rx_Buffer_Length;

            if( (BUFREQ_OK == bufferReqRetVal)
                && (remainingPduRBufferSize >= LinTp_CtrlPtr->linTp_Tx_Rx_Buffer_Length) )
            {
                /* Buffer available, provide below the received data to PduR. */
                LinTp_CtrlPtr->linTp_Ch_State = LINTP_CHANNEL_BUSY_RX;
            }
            /* If PduR indicates failure, abort reception */
            else if( BUFREQ_E_NOT_OK == bufferReqRetVal )
            {
                LinTp_RxCloseConnection(LinTp_CtrlPtr); 
            }
            else
            {
                LinTp_CtrlPtr->linTp_Ch_State = LINTP_CHANNEL_BUSY_RX_SUSPENDED;
            }
        }

        /* If receive buffer available, provide recevied data to PduR. */
        if( LINTP_CHANNEL_BUSY_RX == LinTp_CtrlPtr->linTp_Ch_State )
        {
            LinTp_RxDataBufferHandling_CopyRxData(LinTp_CtrlPtr);
        }
    }
    /* Otherwise: PduR notification pending, postpone buffer handling till next cycle. */
    else
    {
        if( NULL_PTR != LinTp_LinSduPtr )
        {
            /* Prepare pdu info structure. */
            LinTp_CtrlPtr->linTp_PduInfoPtr.SduLength = LinTp_CtrlPtr->linTp_Tx_Rx_Buffer_Length;
            LinTp_CtrlPtr->linTp_PduInfoPtr.SduDataPtr = &LinTp_CtrlPtr->linTp_Tx_Rx_Buffer[LINTP_INIT_ZERO];

            for( byteIndex = LINTP_INIT_ZERO; byteIndex < LinTp_CtrlPtr->linTp_Tx_Rx_Buffer_Length; byteIndex++ )
            {
                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" */
                LinTp_CtrlPtr->linTp_Tx_Rx_Buffer[byteIndex]
                     /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_LinIf_NIV" */
                    = LinTp_LinSduPtr[(LinTp_CtrlPtr->linTp_Tx_Rx_Buffer_Idx + byteIndex) & LINTP_LOCAL_BUFFER_SIZE_MASK];
            }
        }
    }
}

/*
********************************************************************************
* Function Name: LinTp_RxDataBufferHandling_StartOfReception
*
* Explanation: Actual start of PduR reception handling.
*
* param: LinTp_CtrlPtr: LinTp channel pointer.
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinTp_RxDataBufferHandling_StartOfReception
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr
)
{
    BufReq_ReturnType bufferReqRetVal;
    PduLengthType remainingPduRBufferSize = LINIF_INIT_ZERO;

    /* Start actual reception handling with PduR */
    bufferReqRetVal = PduR_LinTpStartOfReception(LinTp_CtrlPtr->linTp_Curr_UL_NSdu_Id,
                                                 NULL_PTR, LinTp_CtrlPtr->linTp_RemainingLength, &remainingPduRBufferSize);
    if( ((BufReq_ReturnType)BUFREQ_OK == bufferReqRetVal)
          && (remainingPduRBufferSize >= LinTp_CtrlPtr->linTp_Tx_Rx_Buffer_Length ) )
    {
        /* Sufficient buffer can be provided for first frame, just proceed. */
        LinTp_CtrlPtr->linTp_Ch_State = LINTP_CHANNEL_BUSY_RX;
    }
    else
    {
        LinTp_CtrlPtr->linTp_Timer = LINTP_INIT_ZERO;
        LinTp_CtrlPtr->linTp_Ch_State = LINTP_CHANNEL_IDLE;
        if( LINIF_CHANNEL_MASTER == LinTp_CtrlPtr->LinTp_NodeType )
        {
            /* Reset TP connection. */
            LinTp_CtrlPtr->linTp_NAD_Requested = LINTP_INIT_ZERO;
            if( (uint8)LINTP_PORTNOTIFITY_IDLE == LinTp_CtrlPtr->linTp_PortNotifity )
            {   
                /* No new functional request pending. */
                LinTp_CtrlPtr->linTp_PortNotifity = (uint8)LINTP_APPLICATIVE_SCHEDULE;
            }
            LinTp_CtrlPtr->linTp_ComModeRestore = (uint8)LINTP_APPLICATIVE_SCHEDULE;
            /* Clear P2 timer. */
            LinTp_CtrlPtr->linTp_P2Timer = LINTP_INIT_ZERO;
            /* Master: Report termination of reception if request was not rejected but provided buffer is too small. */
            if( ((BufReq_ReturnType)BUFREQ_OK == bufferReqRetVal) ||
                ((BufReq_ReturnType)BUFREQ_E_BUSY == bufferReqRetVal) )
            {
                LinTp_CtrlPtr->linTp_PduRNotifity |= LINTP_PDURNOTIFITY_RX;
                LinTp_CtrlPtr->linTp_PduRNotifyResultRx = E_NOT_OK;
                LinTp_CtrlPtr->linTp_PduRNSduIdRx = LinTp_CtrlPtr->linTp_Curr_UL_NSdu_Id;
            }
        }
        else
        {
            /* Slave: Buffer is too small.*/
            if( ((BufReq_ReturnType)BUFREQ_OK == bufferReqRetVal) ||
                ((BufReq_ReturnType)BUFREQ_E_BUSY == bufferReqRetVal) )
            {
                PduR_LinTpRxIndication(LinTp_CtrlPtr->linTp_Curr_UL_NSdu_Id, E_NOT_OK);
            }
        }
    }
}

/*
********************************************************************************
* Function Name: LinTp_RxDataBufferHandling_CopyRxData
*
* Explanation: Provide received data to PduR.
*
* param: LinTp_CtrlPtr: LinTp channel pointer.
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinTp_RxDataBufferHandling_CopyRxData
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr
)
{
    BufReq_ReturnType bufferReqRetVal;
    PduLengthType remainingPduRBufferSize = LINIF_INIT_ZERO;
    PduLengthType succFramePayloadSize;

    bufferReqRetVal = PduR_LinTpCopyRxData(LinTp_CtrlPtr->linTp_Curr_UL_NSdu_Id,
                                           &LinTp_CtrlPtr->linTp_PduInfoPtr,
                                           &remainingPduRBufferSize);
    if( BUFREQ_OK == bufferReqRetVal )
    {
        LinTp_CtrlPtr->linTp_RemainingLength
            = LinTp_CtrlPtr->linTp_RemainingLength - LinTp_CtrlPtr->linTp_PduInfoPtr.SduLength;
        if( LINIF_INIT_ZERO == LinTp_CtrlPtr->linTp_RemainingLength )
        {
            /* Stop N_Cr after reception of a MRF (last CF) with invocation of callback function LinIf_RxIndication */
            LinTp_CtrlPtr->linTp_Timer = LINIF_INIT_ZERO;
            LinTp_CtrlPtr->linTp_Ch_State = LINTP_CHANNEL_IDLE;
            if( LINIF_CHANNEL_MASTER == LinTp_CtrlPtr ->LinTp_NodeType )
            {
                LinTp_CtrlPtr->linTp_PduRNotifity |= LINTP_PDURNOTIFITY_RX;
                LinTp_CtrlPtr->linTp_PduRNotifyResultRx = E_OK;
                LinTp_CtrlPtr->linTp_PduRNSduIdRx = LinTp_CtrlPtr->linTp_Curr_UL_NSdu_Id;

                if(LinTp_CtrlPtr->linTp_RespPendingCounter == LINTP_INIT_ZERO)
                {
                    /* No response pending frame */
                    LinTp_CtrlPtr->linTp_NAD_Requested = LINTP_INIT_ZERO; 
                    if( LinTp_CtrlPtr->linTp_PortNotifity == LINTP_PORTNOTIFITY_IDLE ) 
                    {
                        /* No new functional request pending */
                        LinTp_CtrlPtr->linTp_PortNotifity = (uint8)LINTP_APPLICATIVE_SCHEDULE; 
                    }
                    LinTp_CtrlPtr->linTp_ComModeRestore = (uint8)LINTP_APPLICATIVE_SCHEDULE; 
                    /* Clear P2 timer */
                    LinTp_CtrlPtr->linTp_P2Timer = LINIF_INIT_ZERO; 
                }
            }
            else
            {
                /* Slave channel */
                PduR_LinTpRxIndication(LinTp_CtrlPtr->linTp_Curr_UL_NSdu_Id, E_OK);
            }
        }
        /* Otherwise: more frames expected. */
        else
        {
            /* Calculate payload size of next frame. */
            if( LinTp_CtrlPtr->linTp_RemainingLength < LINTP_LENGTH_6BYTE )
            {
                succFramePayloadSize = LinTp_CtrlPtr->linTp_RemainingLength;
            }
            else
            {
                succFramePayloadSize = LINTP_LENGTH_6BYTE;
            }

            if( remainingPduRBufferSize >= succFramePayloadSize )
            {
                /* Next frame can be stored, just proceed. */
                LinTp_CtrlPtr->linTp_Ch_State = LINTP_CHANNEL_BUSY_RX;
            }
            else
            {
                LinTp_CtrlPtr->linTp_Ch_State = LINTP_CHANNEL_BUSY_RX_POLLBUFFER;
            }
        }
    }
    else
    {
        /* Quit reception and report abortion to PduR. */
        LinTp_RxCloseConnection(LinTp_CtrlPtr);
    }
}

/*
********************************************************************************
* Function Name: LinTp_RxCloseConnection
*
* Explanation: Quit reception and report abortion to PduR.
*
* param: LinTp_CtrlPtr: LinTp channel pointer.
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinTp_RxCloseConnection
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr
)
{
    /* Disable TP and P2 Timer, reset NAD, set channel state to idle. */
    LinTp_CtrlPtr->linTp_Timer = LINTP_INIT_ZERO;
    LinTp_CtrlPtr->linTp_Ch_State = LINTP_CHANNEL_IDLE;
    LinTp_CtrlPtr->linTp_RemainingLength = LINTP_INIT_ZERO;

    if( LINIF_CHANNEL_MASTER == LinTp_CtrlPtr->LinTp_NodeType )
    {
        /* Clear P2 timer. */
        LinTp_CtrlPtr->linTp_P2Timer = LINTP_INIT_ZERO;
        LinTp_CtrlPtr->linTp_NAD_Requested = LINTP_INIT_ZERO;
        /* Inform PduR about connection abortion, request applicative schedule from BswM. */
        LinTp_CtrlPtr->linTp_PduRNotifity |= (uint8)LINTP_PDURNOTIFITY_RX;
        LinTp_CtrlPtr->linTp_PduRNotifyResultRx = E_NOT_OK;
        LinTp_CtrlPtr->linTp_PduRNSduIdRx = LinTp_CtrlPtr->linTp_Curr_UL_NSdu_Id;
        if( LINTP_PORTNOTIFITY_IDLE == LinTp_CtrlPtr->linTp_PortNotifity )
        { 
            /* No new functional request pending. */
            LinTp_CtrlPtr->linTp_PortNotifity  = (uint8)LINTP_APPLICATIVE_SCHEDULE;
        }
        LinTp_CtrlPtr->linTp_ComModeRestore = (uint8)LINTP_APPLICATIVE_SCHEDULE;
    }
    else
    {
        /* Inform PduR about connection abortion */
        PduR_LinTpRxIndication(LinTp_CtrlPtr->linTp_Curr_UL_NSdu_Id, E_NOT_OK);
    }
}

/*
********************************************************************************
* Function Name: LinTp_TxDataRequest
*
* Explanation: Request PduR to provide transmission data.
*
* param: LinTp_CtrlPtr: LinTp channel pointer.
* retval: None
********************************************************************************
*/
static FUNC(Std_ReturnType, LINIF_CODE) LinTp_TxDataRequest
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr
)
{
    uint8 stuffIdx;
    Std_ReturnType retVal = E_OK;
    BufReq_ReturnType bufferReqRetVal;
    uint8 byteIndex;
    PduLengthType remainingPduRBufferSize = LINIF_INIT_ZERO;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    PduIdType LinTpTxSduId = LinTp_CtrlPtr->linTp_Curr_Tx_Id;

    LinTp_CtrlPtr->linTp_Ch_State = LINTP_CHANNEL_BUSY_TX_INVALID;
    stuffIdx = LinTp_CtrlPtr->linTp_Tx_Rx_Buffer_Idx + (uint8)(LinTp_CtrlPtr->linTp_PduInfoPtr.SduLength);
    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_LinIf_OBAI" */
    if( LinTp_CtrlPtr->LinTp_MaxBufReqCounter <= LinTp_TxNSdu[LinTpTxSduId].LinTpMaxBufReq )
    {
        /* Request PduR to copy transmission data into provided local Tp buffer. */
        bufferReqRetVal = PduR_LinTpCopyTxData(LinTp_CtrlPtr->linTp_Curr_UL_NSdu_Id,
                                               &(LinTp_CtrlPtr->linTp_PduInfoPtr),
                                               NULL_PTR,
                                               &remainingPduRBufferSize);
        /* If transmission data is successfully provided. */
        if( (BufReq_ReturnType)BUFREQ_OK == bufferReqRetVal )
        {
            LinTp_CtrlPtr->linTp_RemainingLength
              = LinTp_CtrlPtr->linTp_RemainingLength - LinTp_CtrlPtr->linTp_PduInfoPtr.SduLength;

            if( LINTP_INIT_ZERO == LinTp_CtrlPtr->linTp_RemainingLength )
            {
                /* SF or last CF - check if stuffing is necessary. */
                if( stuffIdx < LINTP_LENGTH_8BYTE )
                {
                    /* Stuff with fill bytes. */
                    for( byteIndex = stuffIdx; byteIndex < LINTP_LENGTH_8BYTE; byteIndex++ )
                    {
                        LinTp_CtrlPtr->linTp_Tx_Rx_Buffer[byteIndex] = LINTP_VALUE_0XFF;
                    }
                }
                LinTp_CtrlPtr->linTp_RemainingLength = LINTP_INIT_ZERO;
                LinTp_CtrlPtr->LinTp_MaxBufReqCounter = LINTP_INIT_ZERO;
            }
            
            LinTp_CtrlPtr->linTp_Ch_State = LINTP_CHANNEL_BUSY_TX_VALID;
        }
        /* Otherwise if PduR does not accept request, abort or delay transmission. */
        else 
        {
            if( (BufReq_ReturnType)BUFREQ_E_BUSY == bufferReqRetVal )
            {
                if( LINTP_VALUE_0XFF > LinTp_CtrlPtr->LinTp_MaxBufReqCounter )
                {
                    LinTp_CtrlPtr->LinTp_MaxBufReqCounter++;
                }
                else
                {
                    /* Abort transmission. */
                    retVal = (Std_ReturnType)E_NOT_OK;
                    LinTp_CtrlPtr->LinTp_MaxBufReqCounter = LINTP_INIT_ZERO;
                }
            }
            else 
            {
                /* Abort transmission. */
                retVal = (Std_ReturnType)E_NOT_OK;
                LinTp_CtrlPtr->LinTp_MaxBufReqCounter = LINTP_INIT_ZERO;
            }
        }
    }
    else
    {
        /* Abort transmission. */
        retVal = (Std_ReturnType)E_NOT_OK;
        LinTp_CtrlPtr->LinTp_MaxBufReqCounter = LINTP_INIT_ZERO;
    }
    
   return retVal;
}

/*
********************************************************************************
* Function Name: LinTp_DataBuffer_Polling
*
* Explanation: Poll PduR for transmission data or reception buffer if necessary (if transport protocol is enabled).
*
* param: LinTp_CtrlPtr: LinTp channel pointer.
*
* retval: none.
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinTp_DataBuffer_Polling
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr
)
{
    Std_ReturnType retVal;
    /* If TX connection active but not sufficient data for transmission available */
    if( LinTp_CtrlPtr->linTp_Ch_State == LINTP_CHANNEL_BUSY_TX_INVALID)
     {
        /* Request transmission data from PduR */
        retVal = LinTp_TxDataRequest(LinTp_CtrlPtr);
        if( retVal == E_NOT_OK )
        { 
            /* unable to obtain data from PduR ,permanent failure */
            LinTp_TxCloseConnection(LinTp_CtrlPtr);
        }
    }
    if( ((LINIF_CHANNEL_MASTER == LinTp_CtrlPtr->LinTp_NodeType) && 
          ((LINTP_CHANNEL_BUSY_RX_SUSPENDED == LinTp_CtrlPtr->linTp_Ch_State ) || 
           (LINTP_CHANNEL_BUSY_RX_WAIT_FOR_START == LinTp_CtrlPtr->linTp_Ch_State))) || 
         ((LINIF_CHANNEL_SLAVE == LinTp_CtrlPtr->LinTp_NodeType)&&
          ((LINTP_CHANNEL_BUSY_RX_SUSPENDED == LinTp_CtrlPtr->linTp_Ch_State) ||
           (LINTP_CHANNEL_BUSY_RX_POLLBUFFER == LinTp_CtrlPtr->linTp_Ch_State))) )
    {
        /* Poll PduR again if receive buffer is available */
        LinTp_RxDataBufferHandling(LinTp_CtrlPtr, NULL_PTR);
    }
}

/*
********************************************************************************
* Function Name: LinTp_TxMessageProcessing
*
* Explanation: LinTp tx message process.
*
* param: LinTp_CtrlPtr: LinTp channel pointer.
*        LinTp_LinStatus: LinTp status.
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinTp_TxMessageProcessing
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    uint8 Channel,
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr,
    Lin_StatusType LinTp_LinStatus
)
{
    Std_ReturnType retVal;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_LinIf_UNMODIFIED_VAR_NOT_CONST" */
    const LinTp_ChannelConfigType* LinTP_ConfigData = LinTp_ChannelConfigData[Channel];

    /* If MRF is successfully transmitted. */
    if( (Lin_StatusType)LIN_TX_OK == LinTp_LinStatus )
    {
        /* Functional request transmitted - reset schedule request to previous schedule */
        if(LinTp_CtrlPtr->linTp_FuncRequest == LINTP_FUNC_REQUEST_TRANSMITTED)
        { 
            LinTp_CtrlPtr->linTp_FuncRequest = LINTP_FUNC_REQUEST_IDLE; 
            LinTp_CtrlPtr->linTp_PortNotifity = LinTp_CtrlPtr->linTp_ComModeRestore; 
            LinTp_CtrlPtr->linTp_PduRNotifity |= LINTP_PDURNOTIFITY_TX; 
            LinTp_CtrlPtr->linTp_PduRNotifyResultTx = E_OK; 
            LinTp_CtrlPtr->linTp_PduRNSduIdTx = LinTp_CtrlPtr->linTp_Curr_Func_NSdu_Id; 
        }
        else
        {
            /* If complete Tp message is finished. */
            if( LINIF_INIT_ZERO == LinTp_CtrlPtr->linTp_RemainingLength )
            {
                LinTp_CtrlPtr->linTp_Timer = LINTP_INIT_ZERO;   /* SWS_LinIf_00657 */
                LinTp_CtrlPtr->linTp_PduRNotifity |= (uint8)LINTP_PDURNOTIFITY_TX;
                LinTp_CtrlPtr->linTp_PduRNotifyResultTx = E_OK;
                LinTp_CtrlPtr->linTp_PduRNSduIdTx = LinTp_CtrlPtr->linTp_Curr_UL_NSdu_Id;
                LinTp_CtrlPtr->linTp_Ch_State = LINTP_CHANNEL_IDLE;

                /* If request is a broadcast request. */
                if( LINTP_VALUE_0X7F == LinTp_CtrlPtr->linTp_NAD_Requested )
                {
                    /* Broadcast request transmitted, switch directly back to applicative schedule. */
                    LinTp_CtrlPtr->linTp_NAD_Requested = LINTP_INIT_ZERO;
                    LinTp_CtrlPtr->linTp_PortNotifity = (uint8)LINTP_APPLICATIVE_SCHEDULE;
                    LinTp_CtrlPtr->linTp_ComModeRestore = (uint8)LINTP_APPLICATIVE_SCHEDULE; 
                }
                else
                {
                    /* Normal physical request transmitted, switch to response schedule and activate P2 timeout observation. */
                    LinTp_CtrlPtr->linTp_PortNotifity = (uint8)LINTP_DIAG_RESPONSE;
                    LinTp_CtrlPtr->linTp_ComModeRestore = (uint8)LINTP_DIAG_RESPONSE; 
                    /* Set up P2 time. */
                    LinTp_CtrlPtr->linTp_P2Timer = LinTP_ConfigData->linTp_P2TimerOut;
                }
            }
            /* Otherwise: more frames to be transmitted for current request. */
            else
            {
                /* Prepare buffer for next CF. */
                LinTp_CtrlPtr->linTp_SN = (uint8)((LinTp_CtrlPtr->linTp_SN + LINTP_INIT_ONE) & LINTP_8BIT_LOW4BIT);
                /* Set PCI. */
                LinTp_CtrlPtr->linTp_Tx_Rx_Buffer[LINTP_INIT_ONE] = (uint8)(LINTP_FRAMETYPE_CF | LinTp_CtrlPtr->linTp_SN);
                LinTp_CtrlPtr->linTp_Tx_Rx_Buffer_Idx = LINTP_INIT_TWO;
                /* Prepare pdu structure for buffer request. */
                LinTp_CtrlPtr->linTp_PduInfoPtr.SduDataPtr = &LinTp_CtrlPtr->linTp_Tx_Rx_Buffer[LINTP_INIT_TWO];
                if( LinTp_CtrlPtr->linTp_RemainingLength <= LINTP_LENGTH_6BYTE )
                {
                    LinTp_CtrlPtr->linTp_PduInfoPtr.SduLength = LinTp_CtrlPtr->linTp_RemainingLength;
                }
                else
                {
                    LinTp_CtrlPtr->linTp_PduInfoPtr.SduLength = LINTP_LENGTH_6BYTE;
                }

                retVal = LinTp_TxDataRequest(LinTp_CtrlPtr);
                if( (Std_ReturnType)E_NOT_OK == retVal )
                {
                    /* If request is denied, close connection and inform PduR - permanent failure. */
                    LinTp_TxCloseConnection(LinTp_CtrlPtr);
                }
                else
                {
                    /* Request accepted, reload timer with CF timeout value.  N_Cs*/
                    LinTp_CtrlPtr->linTp_Timer = LinTp_CtrlPtr->linTp_TimerReload;
                }
            }
        }     
    }
    /* Otherwise: MRF transmission failed. */
    else if(LIN_TX_BUSY != LinTp_LinStatus)
    {
        if(LinTp_CtrlPtr->linTp_FuncRequest == LINTP_FUNC_REQUEST_TRANSMITTED)
        { 
            LinTp_CtrlPtr->linTp_FuncRequest = LINTP_FUNC_REQUEST_IDLE; 
            LinTp_CtrlPtr->linTp_PortNotifity = LinTp_CtrlPtr->linTp_ComModeRestore; 
            LinTp_CtrlPtr->linTp_PduRNotifity |= LINTP_PDURNOTIFITY_TX; 
            LinTp_CtrlPtr->linTp_PduRNotifyResultTx = E_NOT_OK; 
            LinTp_CtrlPtr->linTp_PduRNSduIdTx = LinTp_CtrlPtr->linTp_Curr_Func_NSdu_Id; 
        }
        else
        {
            LinTp_TxCloseConnection(LinTp_CtrlPtr);
        }
    }
    /* MRF transmission busy. */
    else
    {
        /* Do nothing. */
    }
}

/*
********************************************************************************
* Function Name: LinTp_TxCloseConnection
*
* Explanation: Close tx connection.
*
* param: LinTp_CtrlPtr: LinTp channel pointer.
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinTp_TxCloseConnection
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr
)
{
    /* Disable TP timer and set channel state to idle. */
    LinTp_CtrlPtr->linTp_Timer = LINTP_INIT_ZERO;
    LinTp_CtrlPtr->linTp_Ch_State  = LINTP_CHANNEL_IDLE;
    if( LINIF_CHANNEL_MASTER == LinTp_CtrlPtr->LinTp_NodeType )
    {
        /* Inform PduR about connection abortion and request applicative schedule from BswM */
        LinTp_CtrlPtr->linTp_PduRNotifity |= (uint8)LINTP_PDURNOTIFITY_TX;
        LinTp_CtrlPtr->linTp_PduRNotifyResultTx = E_NOT_OK;
        LinTp_CtrlPtr->linTp_PduRNSduIdTx  = LinTp_CtrlPtr->linTp_Curr_UL_NSdu_Id;
        LinTp_CtrlPtr->linTp_PortNotifity = (uint8)LINTP_APPLICATIVE_SCHEDULE;
        LinTp_CtrlPtr->linTp_ComModeRestore = (uint8)LINTP_APPLICATIVE_SCHEDULE;
    }
    else
    {
        /* Slave channel */
        (void)PduR_LinTpTxConfirmation(LinTp_CtrlPtr->linTp_Curr_UL_NSdu_Id, E_NOT_OK);
    }
}

/*
********************************************************************************
* Function Name: LinTp_TxScheduleProcessing
*
* Explanation: LinTp tx schedule process.
*
* param: LinTp_CtrlPtr: LinTp data pointer.
*        LinTp_IfChannelDataPtr: Channel data pointer.
*        LinTp_LinPduPtr: PDU pointer.
* retval: None
********************************************************************************
*/
static FUNC(boolean, LINIF_CODE) LinTp_TxScheduleProcessing
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr,
    P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_APPL_DATA) LinTp_IfChannelDataPtr,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) LinTp_LinPduPtr
)
{
    boolean sendHeaderFlag = TRUE;
    uint8 index = LINIF_INIT_ZERO;
    BufReq_ReturnType bufferReqRetVal = BUFREQ_E_NOT_OK;
    PduLengthType remainingPduRBufferSize = LINIF_INIT_ZERO;
    LINIF_DUMMY_STATEMENT(LinTp_IfChannelDataPtr);

    if( LINTP_FUNC_REQUEST_PENDING == LinTp_CtrlPtr->linTp_FuncRequest )
    {
        /* Initialize local buffer for functional request (always SF). */
#if( LINIF_FIXEDFRAMESDULIST == STD_ON )
        LinTp_IfChannelDataPtr->nodeConfigurationCmd = LINIF_NODECONFIGCMD_IDLE;
#endif

        /* Abuse the LinIf buffer for a functional MRF because this is handled in one cycle. */
        LinTp_LinPduPtr->SduPtr = &(LinTp_IfChannelDataPtr->LinIf_TxData[LINTP_INIT_ZERO]);
        /* Prepare buffer. */
        LinTp_LinPduPtr->SduPtr[LINTP_INIT_ZERO] = LINTP_VALUE_0X7E;
        /* polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
        /* Polyspace +2 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" */
        /* Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" */
        LinTp_LinPduPtr->SduPtr[LINTP_INIT_ONE] = (uint8)LinTp_CtrlPtr->linTp_FuncPduInfoPtr.SduLength;
        LinTp_CtrlPtr->linTp_FuncPduInfoPtr.SduDataPtr = &(LinTp_LinPduPtr->SduPtr[LINTP_INIT_TWO]);
        /* Request PduR to copy transmission data into provided local Tp buffer. */
        bufferReqRetVal = PduR_LinTpCopyTxData(LinTp_CtrlPtr->linTp_Curr_Func_NSdu_Id,
                                               &(LinTp_CtrlPtr->linTp_FuncPduInfoPtr),
                                               NULL_PTR,
                                               &remainingPduRBufferSize);

        if( (BufReq_ReturnType)BUFREQ_OK == bufferReqRetVal )
        {
            /* Stuff unused payload bytes with fill value if necessary. */
            /* Polyspace +4 RTE:NIV [Justified:Unset] "NSCA_Polyspace_LinIf_NIV" */
            /* polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
            /* Polyspace +2 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" */
            /* Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" */
            for( index = (uint8)(LinTp_LinPduPtr->SduPtr[LINTP_INIT_ONE] + LINTP_INIT_TWO); index < LINIF_LINPDU_SIZE; index++ )
            {
                /* polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_LinIf_IDP" */
                /* Polyspace +2 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" */
                /* Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_LinIf_PointerBounds" */
                LinTp_LinPduPtr->SduPtr[index] = LINTP_VALUE_0XFF;
            }
            LinTp_CtrlPtr->linTp_FuncRequest = LINTP_FUNC_REQUEST_TRANSMITTED;
        }
        /* Otherwise: request for transmission data not successful. */
        else
        {
            /* Abort functional request if data cannot be provided at this point. */
            sendHeaderFlag                                = FALSE;
            /* Reject attempt and free buffer. */
            LinTp_CtrlPtr->linTp_FuncRequest              = LINTP_FUNC_REQUEST_IDLE;
            /* Result is always E_NOT_OK for TxTm notification. */
            LinTp_CtrlPtr->linTp_PduRNotifity |= LINTP_PDURNOTIFITY_TXTM;
            LinTp_CtrlPtr->linTp_PduRNSduIdTm = LinTp_CtrlPtr->linTp_Curr_Func_NSdu_Id;
            LinTp_CtrlPtr->linTp_PortNotifity = LinTp_CtrlPtr->linTp_ComModeRestore;
        }
    }
    /* Otherwise if transmission data for physical request already available in local buffer, transmit MRF. */
    else if( LINTP_CHANNEL_BUSY_TX_VALID == LinTp_CtrlPtr->linTp_Ch_State )
    {
        /* Update provided Lin Pdu with transmission data. */
        LinTp_LinPduPtr->SduPtr = (uint8*)(&(LinTp_CtrlPtr->linTp_Tx_Rx_Buffer[LINTP_INIT_ZERO]));
    }
    else
    {
        sendHeaderFlag = FALSE;
    }

    return sendHeaderFlag;
}

/*
********************************************************************************
* Function Name: LinTp_CloseActiveConnection
*
* Explanation: Close Tp connnection.
*
* param: LinTp_CtrlPtr: LinTp data pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, LINIF_CODE) LinTp_CloseActiveConnection
(
    P2VAR(LinTp_ControlType, AUTOMATIC, LINIF_APPL_DATA) LinTp_CtrlPtr
)
{
    if( LinTp_CtrlPtr->linTp_Ch_State != LINTP_CHANNEL_IDLE )
    {
        if( LINTP_CHANNEL_TX_MSK == (LinTp_CtrlPtr->linTp_Ch_State & LINTP_CHANNEL_TX_MSK ) )
        {
            LinTp_TxCloseConnection(LinTp_CtrlPtr);
        }
        /* If Rx connection is active, abort Tp connection and inform PduR. */
        else
        { 
            /* Not idle and no Tx connection implies Rx connection. */
            LinTp_RxCloseConnection(LinTp_CtrlPtr);
        }
    }
}
#endif

#define LINIF_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

