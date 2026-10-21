/*
********************************************************************************
*
* File name: Com.c
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: Sunpengfei/2018.09.25
* Change: Add
* Cause: New
********************************************************************************
* Version: 2.0
* Author/Date: Sunpengfei/2019.04.15
* Change: V2.0 release.
* Cause: Update
********************************************************************************
* Version: 2.1
* Author/Date: Sunpengfei/2019.05.31
* Change: Reviewd Issues Modify
* Cause: Update
********************************************************************************
* Version: 2.2
* Author/Date: lizhiheng/2019.07.22
* Change: SignalGroup acSigGrpIdx Size
* Cause: Update
********************************************************************************
* Version: 2.3
* Author/Date: lizhiheng/2019.08.22
* Change: Add
* Cause: synchronization A26_V3834
********************************************************************************
* Version: 2.4
* Author/Date: lizhiheng/2019.10.17
* Change: Change format.
* Cause: Optimization
********************************************************************************
* Version: 2.5
* Author/Date: lizhiheng/2019.10.25
* Change: Com_CopyTxData parameter judge.
*         initialize a variable.
* Cause: Optimization
********************************************************************************
* Version: 2.6
* Author/Date: lizhiheng/2019.11.11
* Change: Com_Memcpy NULL_PTR replace NULL_POINT.
* Cause: Optimization
********************************************************************************
* Version: 2.7
* Author/Date: lizhiheng/2019.11.11
* Change: synchronization DC Charge compatibility.
* Cause: Optimization
********************************************************************************
* Version: 2.8
* Author/Date: lizhiheng/2019.11.25
* Change: trigger assignment err.
* Cause: Optimization
********************************************************************************
* Version: 3.0
* Author/Date: lizhiheng/2019.11.31
* Change: Reviewd Issues Modify
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: lizhiheng/2019.12.10
* Change: Reviewd Issues Modify
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: lizhiheng/2019.12.24
* Change: signal, signalgroup support normal send, receive, invalid,filter, update_bit, timeout.
*         1.Modify function, configured.
*         2.Partial API no realize.
*         The following is not completed:
*         1.Code format review.
*         2.In step of initialization should add NULL_PTR judge.
*         3.MDT.
*         4.Should add relate configured check.
*         5.signal Gateway.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: lizhiheng/2020.1.07
* Change: signal, signalgroup support normal send, receive, invalid,filter, update_bit, timeout.
*         1.Modify macro definition, configured.
*         2.Partial API realize.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: lizhiheng/2020.1.08
* Change: Fix code logic error
*         1.Modify Com_PointerNullPtr_judge.
*         2.Modify Com_RxFilterData_Handle_Normal case uint16.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: lizhiheng/2020.1.08
* Change: Fix code logic error
*         1.Modify Com_InitOneIPdu_Rx updatebit judge.
*         2.Modify Com_CopyTxData parameter retry judege NULL_PTR.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: lizhiheng/2020.1.15
* Change: Fix code logic error
*         1.Modify Com_PointerNullPtr_judge judgement condition.
*         2.Add Com_RxIndicationProcess copy data length length judge.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: lizhiheng/2020.1.15
* Change: Fix code logic error
*         1.Modify Com_Memcpy, change NULL_POINT to NULL_PTR.
*         2.Modifty Com_PduTriggerSend pdurTriggersta.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: lizhiheng/2020.2.17
* Change: In Com_OnePduSend Add callout process.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: WangCong/2020.2.17
* Change: Modify callout functiuon name In function of Com_OnePduSend.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: lizhiheng/2020.2.26
* Change: Add check NULL_PTR in Com_RxDlMon_MainFunctionRx function.
*          fix code Com_ClearIpduGroupVector.
* Cause: bugfix
********************************************************************************
* Version: 3.11
* Author/Date: lizhiheng/202.03.16
* Change: 1.Modify Com_PointerNullPtr_judge judging condition error.
*          2.Com_MainFunctionRouteSignals modify macro definition.
*          3.referred uint64,sint64,float64 make conditional compilation judgments.
* Cause: bugfix
********************************************************************************
* Version: 3.12
* Author/Date: lizhiheng/2020.03.23
* Change: Modify the process of function Com_MainFunctionRouteSignals.
* Cause: Add function for gateway.
********************************************************************************
* Version: 3.13
* Author/Date: lizhiheng/2020.03.23
* Change: Add code comments,Modify Com_Memcpy two return values.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: lizhiheng/2020.03.24
* Change: 1.Add code comments
*         2.Modify Com_RxSigGrpInvalid_Process,Com_InitRxBuffer defult keyword error.
* Cause: Update
********************************************************************************
* Version: 3.15
* Author/Date: lizhiheng/2020.03.24
* Change: 1.Modify warnings in compilation.
*         2.Modify data type mismatch.
* Cause: Update
********************************************************************************
* Version: 3.16
* Author/Date: lizhiheng/2020.03.25
* Change: 1.Modify the code according to QAC.
* Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date: lizhiheng/2020.03.25
* Change: 1.Modify the code according to QAC.
* Cause: Update
********************************************************************************
* Version: 3.18
* Author/Date: lizhiheng/2020.03.26
* Change: 1.Modify the code according to QAC.
* Cause: Update
********************************************************************************
* Version: 3.19
* Author/Date: lizhiheng/2020.03.29
* Change: 1.Modify the code according to QAC.
*         2.Modify GW function.
*         3.Add signal group related functions.
*         4.Change all spaces to .... .
* Cause: Update
********************************************************************************
* Version: 3.20
* Author/Date: lizhiheng/2020.03.30
* Change: Add sint64 macro translation.
* Cause: Bugfix
********************************************************************************
* Version: 3.21
* Author/Date: lizhiheng/2020.04.14
* Change: 1.Modify Com_SendSigGrp_Process functiuon.
*         2.Add invalid process condition.
*         3.Modify Com_GwSig_Process signal group.
* Cause: Bugfix
********************************************************************************
* Version: 3.22
* Author/Date: lizhiheng/2020.04.14
* Change: 1.Modify uint8_N signal invalid process.
* Cause: Bugfix
********************************************************************************
* Version: 3.23
* Author/Date: lizhiheng/2020.04.17
* Change: 1.Modify uint8_N uint8_DYN signalgroup receive process.
* Cause: Bugfix
********************************************************************************
* Version: 3.24
* Author/Date: lizhiheng/2020.04.17
* Change: Modify Rx signal invalid process.
* Cause: Bugfix
********************************************************************************
* Version: 3.25
* Author/Date: lizhiheng/2020.04.17
* Change: Modify Rx uint8N signal invalid process.
* Cause: Bugfix
********************************************************************************
* Version: 3.26
* Author/Date: lizhiheng/2020.04.21
* Change: Modify Devil number in Com_TxSigWrite_Large_64,Com_TxSigWrite_Normal function.
* Cause: Optimize
********************************************************************************
* Version: 3.27
* Author/Date: lizhiheng/2020.05.11
* Change: Modify the code specification.
* Cause: Optimize
********************************************************************************
* Version: 3.28
* Author/Date: lizhiheng/2020.05.11
* Change: Modify redundant . .
* Cause: Bugfix
********************************************************************************
* Version: 3.29
* Author/Date: lizhiheng/2020.05.18
* Change: Modify Com_SendSignal_Process Judge whether or not signalgroup.
* Cause: Bugfix
********************************************************************************
* Version: 3.30
* Author/Date: lizhiheng/2020.05.25
* Change: Modify Com_SendSignal_Process,Com_SendDynSignal_Process Judge whether or not signalgroup.
* Cause: Bugfix
********************************************************************************
* Version: 3.31
* Author/Date: lizhiheng/2020.06.22
* Change: 1. Rx signal configed updatebit timeout process.
*         2. Tx signal process updatebit mode change.
*         3. Signal type Macros translate cancel.
*         4. Add Com_TriggerTransmit function implementations.
* Cause: Bugfix
********************************************************************************
* Version: 3.32
* Author/Date: lizhiheng/2020.06.28
* Change: Com_ReceiveSignalGroup_Process pointer uesd error.
* Cause: Bugfix
********************************************************************************
* Version: 3.33
* Author/Date: lizhiheng/2020.06.29
* Change: Optimize code structure.
* Cause: Update
********************************************************************************
* Version: 3.34
* Author/Date: lizhiheng/2020.06.30
* Change: 1.Modifitt Com_TriggerTransmit clear updatebit process.
*         2.Tabs tp Spaces.
* Cause: Update
********************************************************************************
* Version: 3.35
* Author/Date: lizhiheng/2020.06.30
* Change: Modifying the devil.
* Cause: Update
********************************************************************************
* Version: 3.36
* Author/Date: lizhiheng/2020.07.01
* Change: Upgrade to 3.1.0.
* Cause: Update
********************************************************************************
* Version: 3.37
* Author/Date: lizhiheng/2020.07.20
* Change: Modifity signalgroup timeout notifity in Com_RxSigGrpTimeoutProcess.
* Cause: Bugfix
********************************************************************************
* Version: 3.38
* Author/Date: lizhiheng/2020.07.20
* Change: Modifity updatebit counter in Com_RxDlMon_MainFunctionRx.
* Cause: Bugfix
********************************************************************************
* Version: 3.39
* Author/Date: lizhiheng/2020.07.20
* Change: Modifity updatebit counter in Com_RxDlMon_MainFunctionRx.
* Cause: Bugfix
********************************************************************************
* Version: 3.40
* Author/Date: lizhiheng/2020.07.27
* Change: Modify the criteria for determining whether a signal group type is a signal
*         in Com_RxSigGrpInvalid_Process.
* Cause: Bugfix
********************************************************************************
* Version: 3.41
* Author/Date: lizhiheng/2020.08.11
* Change: Modify rx signal uint8_N received process.
* Cause: Bugfix
********************************************************************************
* Version: 3.42
* Author/Date: lizhiheng/2020.08.18
* Change: Modify Com_SendSignalGroupArray function code implementation error.
* Cause: Bugfix
********************************************************************************
* Version: 3.43
* Author/Date: lizhiheng/2020.08.18
* Change: Modify Com_InvalidateSignal function code implementation error.
* Cause: Bugfix
********************************************************************************
* Version: 3.44
* Author/Date: lizhiheng/2020.08.18
* Change: Modify Com_ReceiveSignalGroupArray function code implementation error.
* Cause: Bugfix
********************************************************************************
* Version: 3.45
* Author/Date: lizhiheng/2020.08.24
* Change: Add the update bit configuration judgment.
* Cause: Bugfix
********************************************************************************
* Version: 3.46
* Author/Date: lizhiheng/2020.08.26
* Change: Add Com_MainFunctionRouteSignals Initialization judgment.
* Cause: Update
********************************************************************************
* Version: 3.47
* Author/Date: lizhiheng/2020.08.31
* Change: Modify Com_ReceptionDMControl enable listening function.
* Cause: Update
********************************************************************************
* Version: 3.48
* Author/Date: lizhiheng/2020.08.31
* Change: Modify Com_RxSigGrpInvalid_Process error using array parameter.
* Cause: Bugfix
********************************************************************************
* Version: 3.49
* Author/Date: lizhiheng/2020.09.4
* Change: Com_TriggerTransmit add return value.
* Cause: Bugfix
********************************************************************************
* Version: 3.50
* Author/Date: lizhiheng/2020.09.10
* Change: Fixed group channel error.
* Cause: Bugfix
********************************************************************************
* Version: 3.51
* Author/Date: lizhiheng/2020.09.10
* Change: Fix compilation errors.
* Cause: Bugfix
********************************************************************************
* Version: 3.52
* Author/Date: lizhiheng/2020.09.17
* Change: 1.Com_ReceptionDMControl monitor function enable error.
*         2.Modulate the range of structure variables.
* Cause: Bugfix
********************************************************************************
* Version: 3.53
* Author/Date: Wangcong/2020.09.17
* Change: Modify the type of the local variable.
* Cause: Bugfix
********************************************************************************
* Version: 3.54
* Author/Date: Wangcong/2020.09.18
* Change: Modify the type of the local variable. - Com_TxSigWrite_Uint8N - sigLengthIndex
* Cause: Bugfix
********************************************************************************
* Version: 3.55
* Author/Date: lizhiheng/2020.09.22
* Change: Modify the processing of Com_ReceiveSignal function in inactive state.
* Cause: Bugfix
********************************************************************************
* Version: 3.56
* Author/Date: WangC/2020.09.23
* Change: Add the function of signal gateway with description.
* Cause: Add function.
********************************************************************************
* Version: 3.57
* Author/Date: lizhiheng/2020.09.24
* Change: 1. Add transmit clear updatebit.
*         2. Modifty Com_SendSignalGroupArray, Com_ReceiveSignalGroupArray the name
*            of the structure variable.
*         3. Modifty tx signal float32, float64 type process.
* Cause: Update
********************************************************************************
* Version: 3.58
* Author/Date: lizhiheng/2020.09.24
* Change: Modifty Com_PduTxSetVal pointer errors.
* Cause: Bugfix
********************************************************************************
* Version: 3.59
* Author/Date: lizhiheng/2020.09.26
* Change: Modify the processing of the received signal of float32 and float64.
* Cause: Bugfix
********************************************************************************
* Version: 3.60
* Author/Date: lizhiheng/2020.09.27
* Change: Modify the processing of the received signal of float32 in Com_RxSigGrpInvalid_Process function.
* Cause: Bugfix
********************************************************************************
* Version: 3.61
* Author/Date: lizhiheng/2020.09.27
* Change: Modify Com_InvalidateSignalGroup,Com_InvalidateSignal the code implementation of the function.
* Cause: Bugfix
********************************************************************************
* Version: 3.62
* Author/Date: lizhiheng/2020.09.28
* Change: 1.Com_ReceiveSignalGroup,Com_ReceiveSignalGroupArray modify the processing of the return value of the function.
*         2.Modifty Com_TriggerTransmit Length Check.
*         3.Com_TriggerIPDUSend add code implementation.
* Cause: Update
********************************************************************************
* Version: 3.63
* Author/Date: lizhiheng/2020.09.28
* Change: 1.Add ErrCbk.
*         2.Add Tx timeout Cbk.
*         3.Do not receive an invalid value notification.
*         4.Add Memap process.
*         5.Modify the coding style of AutoSar.
* Cause: Update
********************************************************************************
* Version: 3.64
* Author/Date: LiZH/2020.10.10
* Change: Optimized coding specification.
* Cause: Update
********************************************************************************
* Version: 3.65
* Author/Date: LiZH/2020.10.20
* Change: 1.Optimized coding specification.
*         2.Modify QAC warning.
* Cause: Update
********************************************************************************
* Version: 3.66
* Author/Date: LiZH/2020.10.28
* Change: Modify QAC warning.
* Cause: Update
********************************************************************************
* Version: 3.67
* Author/Date: WangC/2020.10.29
* Change: Add GW function of stopping cycle msg.
* Cause: Special requirements.
********************************************************************************
* Version: 3.68
* Author/Date: LiZH/2020.11.02
* Change: Modify the initialization process of MemMap.
* Cause: Update
********************************************************************************
* Version: 3.67
* Author/Date: LiZH/2020.11.05
* Change: Modify the incorrectly defined part of the code format.
* Cause: Optimization
********************************************************************************
* Version: 3.68
* Author/Date: LiZH/2020.11.06
* Change: Add pdu callout in Com_TriggerTransmit function.
* Cause: Update
********************************************************************************
* Version: 3.69
* Author/Date: LiZH/2020.11.20
* Change: New gateway timeout stop function.
* Cause: Update
********************************************************************************
* Version: 3.70
* Author/Date: LiZH/2020.11.20
* Change: 1.Add boolrean timeout repalce process.
* 2.Add Com_InvalidateSignalGroup signal invalid config check.
* 3.Add Com_RxSigGrpInvalid_Process signal invalid not config process.
* Cause: Update
********************************************************************************
* Version: 3.71
* Author/Date: LiZH/2020.11.25
* Change: Modifty Com_GwInfoInit function.
* Cause: Update
********************************************************************************
* Version: 3.72
* Author/Date: LiZH/2020.12.4
* Change: Modifty Com_GwInfoInit function.
* Cause: Update
********************************************************************************
* Version: 3.73
* Author/Date: LiZH/2020.12.4
* Change: 1.Inited rxsignal value in Com_init().
* 2.Add rx timeout replace value.
* Cause: Update
********************************************************************************
* Version: 3.74
* Author/Date: ZhangDX/2020.12.7
* Change: 1. Add a pre-compilation option before the function Com_GwInfoInit. The
* definition and use of this function are prohibited when the gateway
* message is not configured.
* 2. Fix the problem that some blank lines have spaces.
* Cause: Update
********************************************************************************
* Version: 3.75
* Author/Date: LiZH/2021.01.05
* Change: Add code optimization.
* Cause: Update
********************************************************************************
* Version: 3.76
* Author/Date: LiZH/2021.01.09
* Change: Modifty Com_RxSigUbInvFilterProcessU64 function declaration error.
* Cause: Bugfix
********************************************************************************
* Version: 3.77
* Author/Date: LiZH/2021.01.20
* Change: 1.Add Com_GwInfoInit macro switch judgment.
*         2.Add retry failed transmission requests.
* Cause: Update
********************************************************************************
* Version: 3.78
* Author/Date: LiZH/2021.01.30
* Change: 1.Modifty file log.
*         2.Add rx timeout replace process.
* Cause: Bugfix
********************************************************************************
* Version: 3.79
* Author/Date: LiZH/2021.01.31
* Change: Modifty handling of data types float32 and float64 in the signalgroup.
* Cause: Bugfix
********************************************************************************
* Version: 3.80
* Author/Date: LiZH/2021.02.05
* Change: 1.Add Com_TxPduInfo[PduId].pduTriggerMonito check NULL_PTR in Com_TriggerIPDUSend.
*         2.Add Com_RxPduInfo[id].pduTpMonitor check NULL_PTR in Com_TpRxIndication.
*         3.Modifty callout return value in Com_RxIndicationProcess.
* Cause: Optimize
********************************************************************************
* Version: 3.81
* Author/Date: LiZH/2021.02.26
* Change: Modifty uint64,uint8_Dyn,uint8_N type signal assignment process in
*         Com_RxPrcessing_ReadSignalGroup.
* Cause: Bugfix
********************************************************************************
* Version: 3.82
* Author/Date: LiZH/2021.03.4
* Change: 1.Add rx signal group received state process when exit invalid or filter failed.
*         2.Modifty Com_RxInv_SigGrp function should check invlid first, judge invalidAction section
* Cause: Bugfix
********************************************************************************
* Version: 3.83
* Author/Date: LiZH/2021.03.22
* Change: 1.Rx timeout counter add one.
*         2.Com_PduTxCheckTimeOut tx timeout conter Add / Timebase.
*         3.Com_TriggerTransmit pdu not active return E_NOT_OK.
*         4.Add not config update process in Com_GwSigRxReadUb.
*         5.Modifty COM_SIGTYPE_UINT8_N, COM_SIGTYPE_UINT8_DYN in Com_RxSigGrpTimeout_ReplaceProcess.
* Cause: Bugfix
********************************************************************************
* Version: 3.84
* Author/Date: LiZH/2021.04.12
* Change: 1.Add Com_ClearIpduGroupVector,Com_ClearIpduGroupVector check NULL_PTR.
*         2.Add Com_ReceiveDynSignal pdu active status check.
* Cause: Bugfix
********************************************************************************
* Version: 3.85
* Author/Date: LiZH/2021.06.15
* Change: 1.Modifty Com_IpduGroupControl init process.
*         2.Modifty tp remain length set value in initprocess.
* Cause: Bugfix
********************************************************************************
* Version: 3.86
* Author/Date: LiZH/2021.06.28
* Change: 1.Add reset tp length in Com_TpTxConfirmation.
* Cause: Bugfix
********************************************************************************
* Version: 3.87
* Author/Date: LiZH/2021.10.28
* Change: Modifty to LOCAL_INLINE.
* Cause: Optimize
********************************************************************************
* Version: 3.88
* Author/Date: LiZH/2021.10.29
* Change: Modifty Com_RxIndicationProcess received data process.
* Cause: Bugfix
********************************************************************************
* Version: 3.89
* Author/Date: LiK/2021.11.26
* Change: 1.Modifty Com_RxSignalAnalysis_Process float32 received signal process.
*         2.Modifty Com_InitAllIPdus_Rx type conversion.
* Cause: Bugfix
********************************************************************************
* Version: 3.90
* Author/Date: LiZH/2021.12.06
* Change: 1.Modifty Com_TpTxConfirmation result process.
* Cause: Bugfix
********************************************************************************
* Version: 3.91
* Author/Date: TongXY/2022.06.16
* Change: 1.Modifty ComErrorNotification.
*         2.Modifty check Com_TxIpduCallout function return value.
* Cause: Bugfix
********************************************************************************
* Version: 3.92
* Author/Date: TongXY/2022.06.16
* Change: Add Com_TxIpduCallout function return default value.
* Cause: Bugfix
********************************************************************************
* Version: 3.93
* Author/Date: TongXY/2022.06.16
* Change: Modifty CCOREDBUG-718.
*         1.Add pduRemainLen update in Com_TpRxIndication, when transfer failed.
*         2.Cancel pduTpConnection check in Com_CopyTxData.
*         3.Modifty pduTpConnection init in Com_InitAllIPdus_Rx.
* Cause: Bugfix
********************************************************************************
* Version: 3.94
* Author/Date: LiXB/2022.08.10
* Change: Modifty Com_GwSig_Process to add the gw process of signal of signal group
* Cause: Bugfix
********************************************************************************
* Version: 3.95
* Author/Date: LiXB/2022.09.15
* Change: Fix compiling warning of implicit conversion and unused static function
*         "Com_TxCfrmNotifition_Process".
* Cause: Optimization
********************************************************************************
* Version: 3.96
* Author/Date: LiXB/2022.09.22
* Change: Add multicore scene
          1. Split Com_MainFunctionRx and Com_MainFunctionTx into four sub mainfuntion,
             which can be used to support Multi-core deployment.
          2. Add funtion Com_InterCore_Process and Com_GwSigDscp_InterProcess, to protect
             signal inter core routing process.
          3. Add function Com_GetPduIndex, to search for pdu.
* Cause: Update
********************************************************************************
* Version: 3.97
* Author/Date: LiXB/2022.10.17
* Change: Modifty CCOREDBUG-1409
*         Add a parameter initialize to function Com_InitOneIPdu_TxMode and
*         Com_InitOneIPdu_Tx, to decide whether tx pdu mode should be initialized
*         or not.
* Cause: Bugfix
********************************************************************************
* Version: 3.98
* Author/Date: LiXB/2022.10.24
* Change: Modifty CCOREDBUG-1572, CCOREDBUG-1573
*         Modify gateway process of signals of signal group.
*         Modify judgement condition of gateway process of signal group in Com_GwSig_Process.
*         Add nonzero judgment of pduTimeoutCnt in Com_PduTxCheckTimeOut.
* Cause: Bugfix
********************************************************************************
* Version: 3.99
* Author/Date: LiXB/2022.11.1
* Change: Modifty CCOREDBUG-1573
*         Modify gateway process of signals of signal group.
*         Add  signal group signal gateway process for single core process.
* Cause: Bugfix
********************************************************************************
* Version: 3.100
* Author/Date: LiXB/2022.11.16
* Change: Add update bit clear process in com_init
* Cause: Update.
********************************************************************************
* Version: 3.101
* Author/Date: LiXB/2022.11.21
* Change: Add two pdu transmission mode, if active and periodic if active in
*         Com_PduTxProcess. Add Com_PduIfActiveTxProcess, Com_PduPeriodicIfActiveTxProcess
*         Com_PduIfActiveSend, Com_PduPeriodicIfActiveSend to support this two new
*         transmission mode.
* Cause: Update
********************************************************************************
* Version: 3.102
* Author/Date: LiXB/2022.11.25
* Change: Add First timeout for DM control: add function Com_InitRxSignalCnt to
*         give rxSignal first timeout value. Com_InitRxSignalCnt is used in
*         Com_InitOneIPdu_Rx to initialize rxSignal and in reset process of pdu
*         in Com_IpduGrpCtrl_UpRxIPduSts to initialize rxSignal.
*         sigMinimumFirstTimeout should also be assigned to pdu rx monitor counter in
*         this two processes.
*         Fix Com_PduIfActiveSend and Com_PduPeriodicIfActiveSend,change the
*         name of signal transfer property.
*         Repair QAC warning
* Cause: Update
********************************************************************************
* Version: 3.103
* Author/Date: LiXB/2022.12.5
* Change: Refactor function Com_ReceptionDMControl, for Com_ReceptionDMControl
*         is also related to first timeout.
*         Seperate the signal monitor enable flag in first timeout process.
*         Add the assignment of acSignalUpdateEnableDeadline and acSignalEnableDeadline
*         in function Com_InitRxSignalCnt.
* Cause: Update
********************************************************************************
* Version: 3.104
* Author/Date: LiXB/2022.12.16
* Change: Delete the assignment of enableDeadline when receive deadline control
*         is open in function Com_ReceptionDMControl
* Cause: Update
********************************************************************************
* Version: 3.105
* Author/Date: HeZH/2023.01.13
* Change: Modify the receive or transmit signal group array data copy address offset.
* Cause: Bugfix
********************************************************************************
* Version: 3.106
* Author/Date: HeZH/2023.01.30
* Change: The number of IPduGroups is supported to 65535.
* Cause: Update
********************************************************************************
* Version: 3.107
* Author/Date: HeZH/2023.02.06
* Change: Add initialization (oldValue, occurrences) of the sending signal or
*       group signal filtering monitoring data in function Com_SigTxInit.
* Cause: Update
********************************************************************************
* Version: 3.108
* Author/Date: HeZH/2023.02.07
* Change: Added filtering TMC algorithm function.
* Cause: Update
********************************************************************************
* Version: 3.109
* Author/Date: HeZH/2023.02.08
* Change: Added TMS switching and post-switching processing mechanism.
* Cause: Update
********************************************************************************
* Version: 3.110
* Author/Date: HeZH/2023.02.14
* Change: Increase judgment of null pointers and cast a qualified data type.
* Cause: Update
********************************************************************************
* Version: 3.111
* Author/Date: HeZH/2023.02.27
* Change: 1.When the sending filtering method is COM_FILTER_MASKEDNEWDIFFERSMASKEDOLD,
*        modify the calculation method for the least significant bit interception length.
*        2.When calling the Com_SendSignal or Com_SendSignalGroup,
*        calculate the TMS of the IPDU to which the signal/group signal belongs.
* Cause: Bugfix
********************************************************************************
* Version: 3.112
* Author/Date: HeZH/2023.03.07
* Change: When calculating TMS, remove the judgment of whether the signal is a group signal.
* Cause: Bugfix
********************************************************************************
* Version: 3.113
* Author/Date: HeZH/2023.03.17
* Change: 1.Added support for interface Com_TriggerIPDUSendWithMetaData.
*         2.Fixed compilation warning issue.
* Cause: Update
********************************************************************************
* Version: 3.114
* Author/Date: ChiXP/2023.08.10
* Change: Fixed compilation warning issue.
* Cause: Update
********************************************************************************
* Version: 3.115
* Author/Date: TianSL/2023.10.10
* Change: Modifying compile Warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.116
* Author/Date: TianSL/2023.10.27
* Change: 1.Fix compile warning.
*         2.Add function Com_CompareFloat32Values.
*         3.Add function Com_CompareFloat64Values.
* Cause: Optimization
********************************************************************************
* Version: 3.117
* Author/Date: TianSL/2023.11.01
* Change: Add the signal group transmission mode judgment in the
*         Com_SendSignalGroupArray function.
* Cause: Bugfix
********************************************************************************
* Version: 3.118
* Author/Date: TianSL/2023.11.01
* Change: Modify the Com_ReceiveSignalGroup_Process function,make it transfer the
*         sigShadowValue value to RTE correctly.
* Cause: Bugfix
********************************************************************************
* Version: 3.119
* Author/Date: HeH/2023.12.04
* Change: Modify Com_MainFunction_Tx and Com_MainFunction_RouteSignals for
*         optimization.
* Cause: Optimization
********************************************************************************
* Version: 3.120
* Author/Date: ZhangF/2023.12.04
* Change: 1.Modify Com_MainFunction_Rx for performance optimization.
*         2.Remove the COM_RX_TIMEBASE for Deadline monitor optimization.
*         3.Change data copy methods in Com_RxIndication for performance optimization.
* Cause: Optimization
********************************************************************************
* Version: 3.121
* Author/Date: TianG/2023.12.04
* Change: COM signal parsing algorithm optimization.
* Cause: Optimization
********************************************************************************
* Version: 3.122
* Author/Date: TianG/2023.12.06
* Change: Optimized the judgment of the length of the received DYN signal.
* Cause: Optimization
********************************************************************************
* Version: 3.123
* Author/Date: HeH/2023.12.06
* Change: Change Com_RxIndicationProcess function, set RxPDU's acPduRecSts to:
*         (COM_PDU_GW_SIG_FLAG | COM_PDU_GW_DSCP_FLAG).
* Cause: Optimization
********************************************************************************
* Version: 3.124
* Author/Date: HeH/2023.12.20
* Change: Bug fix for CCOREDBUG-4263:
*         1. Delete the code of clearing received flag in Com_GwSig_Process,
*         Com_GwSigDscp_InterProcess and Com_GwSigDscp_Process functions because
*         it's wrong to clear the flags during that time.
*         2. Add Com_GwSig_ClearRecvFlag, Com_GwSigDscp_ClearRecvFlag functions.
*         And clear the received flag after all related Rx Pdus are processed.
* Cause: BugFix
********************************************************************************
* Version: 3.125
* Author/Date: TianG/2023.12.21
* Change: Modify compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.126
* Author/Date: LuQ/2023.12.22
* Change: Modify the method which parse the float message data to signal.
* Cause: BugFix
********************************************************************************
* Version: 3.127
* Author/Date: LuQ/2023.12.25
* Change: Correct the coding specifications.
* Cause: Optimization
********************************************************************************
* Version: 3.128
* Author/Date: ZhangF/2023.12.25
* Change: Do not parse the signal group in MainFunctionRx if it is a E2E group.
* Cause: Optimization
********************************************************************************
* Version: 3.129
* Author/Date: LuQ/2024.02.20
* Change: Modify the position of the signal's timeout setting.
* Cause: Bugfix
********************************************************************************
* Version: 3.130
* Author/Date: LuQ/2024.02.27
* Change: Fix compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.131
* Author/Date: LuQ/2024.03.12
* Change: 1.Modify the assignment method of gateway routing flag.
*         2.Fix compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.132
* Author/Date: LuQ/2024.03.22
* Change: Modify the method to remove the receiving pdu flag.
* Cause: Optimization
********************************************************************************
* Version: 3.133
* Author/Date: LuQ/2024.04.02
* Change: 1. Modify P2CONST member labels.
*         2. Modify the comments format.
* Cause: Optimization
********************************************************************************
* Version: 3.134
* Author/Date: TianG/2024.04.07
* Change: 1.Modify Rx parsesignal algorithm.
*         2.Modify Tx back-resolution signal algorithm.
*         3.Modify some member variables of Com_RxSignalInfo related.
*         4.Modify some member variables of Com_TxSignalInfo related.
*         5.Modify sigType and sigdianess functionality.
* Cause: Optimization
********************************************************************************
* Version: 3.135
* Author/Date: LuQ/2024.05.13
* Change: 1.Add Com_MDTCounter.
*         2.Modify Com_TxConfirmation, Com_InitOneTxIPdu_CommonCnt,
*           Com_PduTriggerSend and Com_PduCycleSend, add MDT function.
* Cause: Optimization
********************************************************************************
* Version: 3.136
* Author/Date: LuQ/2024.07.09
* Change: 1.Modify the function of activating pdu state.
*         2.Modify the function of deactivating pdu state.
*         3.Fix compile warning.
* Cause: Bugfix
********************************************************************************
* Version: 3.137
* Author/Date: LuQ/2024.07.25
* Change: Modify the function Com_SendSigGrp_Process.When the value of
*         a signal configured as pending in the group changes, it does not
*         trigger transmission.
* Cause: Optimization
********************************************************************************
* Version: 3.138
* Author/Date: LuQ/2024.07.25
* Change: Add macros to prevent unused features from participating in 
*         code compilation.
* Cause: Optimization
********************************************************************************
* Version: 3.139
* Author/Date: LuQ/2024.07.26
* Change: Delete the determination of Pdu status.The signal value can be updated
*         even the Pdu status is INACTIVE
* Cause: Optimization
********************************************************************************
* Version: 3.140
* Author/Date: LuQ/2024.08.12
* Change: 1.Support the interface Com_SendSignalWithMetaData.
*         2.Support the interface Com_SendSignalGroupWithMetaData.
* Cause: Update
********************************************************************************
* Version: 3.141
* Author/Date: LuQ/2024.08.13
* Change: Modify the function Com_SendSigGrp_Process.Just the value of
*         the signal configured as pending in the group changes, it does not
*         trigger transmission.
* Cause: Update
********************************************************************************
* Version: 3.142
* Author/Date: LuQ/2024.08.26
* Change: Add macros to prevent unused features from participating in
*         code compilation.
* Cause: Bugfix
********************************************************************************
* Version: 3.143
* Author/Date: LuQ/2024.08.28
* Change: Add signalBaseInfo initialization operation in gateway routing.
* Cause: Bugfix
********************************************************************************
* Version: 3.144
* Author/Date: LuQ/2024.08.30
* Change: Modify the sduDataPtr and sduLength  of the sender pdu.
* Cause: Bugfix
********************************************************************************
* Version: 3.145
* Author/Date: LuQ/2024.09.19
* Change: 1. Modify Memmap segment definition.
*         2. Add the function that event pdu can reset the periodic pdu's timer.
* Cause: Optimization
********************************************************************************
* Version: 3.146
* Author/Date: LuQ/2024.09.30
* Change: Add initialization of Written bytes Counter.
* Cause: Bugfix
********************************************************************************
* Version: 3.147
* Author/Date: LuQ/2024.09.30
* Change: Modify the position of the structure.
* Cause: Bugfix
********************************************************************************
* Version: 3.148
* Author/Date: LuQ/2024.10.09
* Change: Add macros to prevent unused features from participating in
*         code compilation.
* Cause: Bugfix
********************************************************************************
* Version: 3.149
* Author/Date: LuQ/2024.10.10
* Change: Use structure element for ComTriggeredResetPeriodicTimer Flag.
* Cause: Bugfix
********************************************************************************
* Version: 3.150
* Author/Date: LuQ/2024.10.10
* Change: Delete the judgment of null pointer in Com_PduMixTxProcess.
* Cause: Optimization
********************************************************************************
* Version: 3.151
* Author/Date: LuQ/2024.11.11
* Change: Add pdu timeout flag.
* Cause: Optimization
********************************************************************************
* Version: 3.152
* Author/Date: LuQ/2024.11.21
* Change: Modify the clearing position of the pdu timeout state.
* Cause: Bugfix
********************************************************************************
* Version: 3.153
* Author/Date: LuQ/2024.12.26
* Change: Add judgment on pduTpMonitor.
* Cause: Bugfix
********************************************************************************
* Version: 3.154
* Author/Date: LuQ/2025.02.11
* Change: Add null-pointer check to fix QAC warning.
* Cause: Bugfix
********************************************************************************
* Version: 3.155
* Author/Date: LuQ/2025.02.28
* Change: 1.Modify null-pointer check to fix QAC warning.
*         2.Add gateway routing reception flag.
* Cause: Bugfix
********************************************************************************
* Version: 3.156
* Author/Date: LuQ/2025.03.11
* Change: 1.Add sigType to obtain signal types.
*         2.Support disabling the shadowvalue function to optimizing the
*           copying process.
* Cause: Optimization
********************************************************************************
* Version: 3.157
* Author/Date: LuQ/2025.03.12
* Change: Fix compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.158
* Author/Date: LuQ/2025.03.13
* Change: Optimize the Com interface to keep the const tag when assigning
*         imported parameters to prevent abnormal tampering of imported parameter
*         values.
* Cause: Optimization
********************************************************************************
********************************************************************************
* Version: 3.159
* Author/Date: LuQ/2025.03.26
* Change: Modify the validity of module parameters needs to be checked when Det
*         is off.
* Cause: Optimization
********************************************************************************
* Version: 3.159
* Author/Date: LuQ/2025.03.26
* Change: When Com_TpTxConfirmation returns NOT_OK, modify pduSta.
* Cause: Bugfix
********************************************************************************
* Version: 3.160
* Author/Date: LuQ/2025.03.26
* Change: Modify the scope of influence of COM_TXPDU_CBKNOTIFTY_SUPPORT.
* Cause: Bugfix
********************************************************************************
* Version: 3.161
* Author/Date: LuQ/2025.03.26
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Optimization
********************************************************************************
* Version: 3.162
* Author/Date: LuQ/2025.03.27
* Change: Modify the position of variable-dynSignalLength's definition.
* Cause: Optimization
********************************************************************************
* Version: 3.163
* Author/Date: LuQ/2025.04.22
* Change: 1.Add COM_GWONLYTXMODETURE to manage the switching of GW parameters.
*         2.Add COM_GWROUTETIMEOUTVALUE_SUPORT to manage the routing of
*           gateway-signal timeout value.
* Cause: Optimization
********************************************************************************
* Version: 3.164
* Author/Date: LuQ/2025.04.23
* Change: Modify the comparison logic of floating-point variables.
* Cause: Bugfix
********************************************************************************
* Version: 3.165
* Author/Date: LuQ/2025.05.12
* Change: Optimized memory copy performance.
* Cause: Update
********************************************************************************
* Version: 3.166
* Author/Date: LuQ/2025.06.17
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.167
* Author/Date: LuQ/2025.06.23
* Change: Modify the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.168
* Author/Date: LuQ/2025.07.07
* Change: Modify the assignment position of the route status for the gateway
*         timeout replacement value.
* Cause: Bugfix
********************************************************************************
* Version: 3.169
* Author/Date: LuQ/2025.07.08
* Change: Modify the timeout monitoring mechanism to not monitor Pdus that
*         have not configured ComTimeout.
* Cause: Bugfix
********************************************************************************
* Version: 3.170
* Author/Date: LuQ/2025.07.15
* Change: Modify the macro for switching the TxPduMode.
* Cause: Bugfix
********************************************************************************
* Version: 3.171
* Author/Date: LuQ/2025.07.23
* Change: Fix the problem that there was no initial value before use of the
*         timeout counter of the signal gateway
* Cause: Bugfix
********************************************************************************
*/
/*
********************************************************************************
*    Include
********************************************************************************
*/
#include "Com.h"
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
#include "Com_Write.h"
#include "Com_Read.h"
#endif

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
#ifdef  COM_LOCAL_INLINE
#define COM_LOCAL_INLINE  LOCAL_INLINE
#else
#define COM_LOCAL_INLINE  static
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
#define COM_START_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"

/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Com_NonSharedVar" */
static VAR(Com_StatusType, COM_VAR_INIT) Com_Initialized = COM_UNINIT; /* Init state. */

#define COM_STOP_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Local Functions
********************************************************************************
*/
#define COM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
#if( COM_DEV_ERROR_REPORT == STD_ON )
static FUNC(void, COM_CODE) Com_Det_ErrorReport
(
    uint8 ApiId,
    uint8 ErrorId
);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

static FUNC(void, COM_CODE) Com_IpduGrpCtrl_UpRxIPduSts
(
    Com_IpduGroupVector ipduGroupVector,
    boolean initialize
);
static FUNC(void, COM_CODE) Com_ReceiveSignal_Process
(
    uint16 SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);
static FUNC(void, COM_CODE) Com_PduRxProcess
(
    P2CONST(COM_RxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
);
static FUNC(void, COM_CODE) Com_ActivateRxComIPdus
(
    void
);
static FUNC(void, COM_CODE) Com_ActivateTxComIPdus
(
    void
);
static FUNC(void, COM_CODE) Com_DeActivateRxComIPdus
(
    void
);
static FUNC(void, COM_CODE) Com_DeActivateTxComIPdus
(
    void
);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_RxDlMon_MainFunctionRx
(
    P2CONST(COM_RxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_RxIndicationProcess
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);

static FUNC(void, COM_CODE) Com_InitRxSignalCnt
(
    P2CONST(COM_RxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
);
static FUNC(void, COM_CODE) Com_InitRxBuffer
(
    P2CONST(COM_RxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
);
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
static FUNC(void, COM_CODE) Com_RxSigTimeoutProcess
(
    uint16 sigIdx
);
#endif
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
static FUNC(void, COM_CODE) Com_RxUpdateCntProcess
(
    P2CONST(COM_RxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
);
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */
#if( (COM_RXREPLACESIGOFRXTIMEOUTINFO == STD_ON) || (COM_RXUPDATEBITCFG_SUPPORT == STD_ON) )
static FUNC(void, COM_CODE) Com_RxSigTimeout_ReplaceProcess
(
    uint16 sigIdx
);
#endif

static FUNC(void, COM_CODE) Com_RxSigNotification_Handle
(
    uint16 sigIdx
);
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
static FUNC(uint8, COM_CODE) Com_SigRxReadUb
(
    uint16 sigIdx
);
#endif  /* (COM_RXUPDATEBITCFG_SUPPORT == STD_ON) */


#if( (COM_RXSIGGROUPINFO == STD_ON) && (COM_RXUPDATEBITCFG_SUPPORT == STD_ON) )
static FUNC(uint8, COM_CODE) Com_SigGrpRxReadUb
(
    uint16 sigGrpIdx
);
#endif  /* ((COM_RXSIGGROUPINFO == STD_ON) && (COM_RXUPDATEBITCFG_SUPPORT == STD_ON))  */

#if( COM_RXSIGGROUPINFO == STD_ON )
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
static FUNC(void, COM_CODE) Com_RxSigGrpTimeoutProcess
(
    uint16 sigGrpIdx,
    uint16 pduTimeCouter
);
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */

#if( (COM_RXREPLACESIGGROUPOFRXTIMEOUTINFO == STD_ON) || (COM_RXUPDATEBITCFG_SUPPORT == STD_ON) )
static FUNC(void, COM_CODE) Com_RxSigGrpTimeout_ReplaceProcess
(
    uint16 sigGrpIdx
);
#endif  /* (COM_RXREPLACESIGGROUPOFRXTIMEOUTINFO == STD_ON) || (COM_RXUPDATEBITCFG_SUPPORT == STD_ON) */
static FUNC(void, COM_CODE) Com_RxProcessing_ProcessSigGrpEvent
(
    uint16 sigGrpIdx,
    P2CONST(COM_RxPduInfo_st, AUTOMATIC, COM_APPL_CONST) astPduInfo
);
static FUNC(void, COM_CODE) Com_RxPrcessing_ReadSignalGroup
(
    uint16 sigGrpIdx,
    P2CONST(COM_RxPduInfo_st, AUTOMATIC, COM_APPL_CONST) astPduInfo
);
#if( COM_INVALIDACTION_SUPPORT == STD_ON )
static FUNC(boolean, COM_CODE) Com_RxInv_SigGrp
(
    uint16 sigGrpIdx
);
static FUNC(void, COM_CODE) Com_SigGrp_InvReplace
(
    uint16 grpSigIdx
);
#endif  /* COM_INVALIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )
static FUNC(boolean, COM_CODE) Com_RxProcessing_RxSignalGroupFilterChk
(
    uint16 sigGrpIdx
);
#endif  /* COM_RXSIGFILTERINFO == STD_ON */

#endif  /* COM_RXSIGGROUPINFO == STD_ON */

static FUNC(void, COM_CODE) Com_SigTxInit
(
    uint16 sigIndex
);

#if( COM_TXSIGGROUPINFO == STD_ON )
static FUNC(void, COM_CODE) Com_SigGrpTxInit
(
    uint16 sigGrpIndex
);
#endif

static FUNC(void, COM_CODE) Com_InitOneIPdu_Tx
(
    uint16 pduIdx,
    boolean initialize
);
static FUNC(void, COM_CODE) Com_InitOneIPdu_TxMode
(
    uint16 pduIdx,
    boolean initialize
);
static FUNC(void, COM_CODE) Com_InitOneTxIPdu_CommonCnt
(
    uint16 pduIdx
);
static FUNC(void, COM_CODE) Com_InitOneTxIPdu_FillUnuseArea
(
    uint16 pduIdx
);
static FUNC(void, COM_CODE) Com_InitOneTxIPdu_Allsig
(
    uint16 pduIdx
);
static FUNC(void, COM_CODE) Com_InitAllIPdus_Tx
(
    void
);
static FUNC(void, COM_CODE) Com_SendSignal_Process
(
    uint16 sigId,
    P2CONST(void, AUTOMATIC, COM_APPL_CONST) sigDataPtr
);
static FUNC(void, COM_CODE) Com_SendDynSignal_Process
(
    uint16 sigId,
    P2CONST(void, AUTOMATIC, COM_APPL_CONST) sigDataPtr,
    uint16 Length
);
#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
static FUNC(void, COM_CODE) Com_SigTxSetUb
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.5" */
(
    uint16 bitPos,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.5" */
    PduIdType pduId
);
#endif  /* COM_TXUPDATEBITCFG_SUPPORT == STD_ON */
static FUNC(void, COM_CODE) Com_SendPduStaProcess
(
    P2CONST(COM_TxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) txSigInfo,
    boolean sigValChangeFlag
);

#if( COM_TXSIGGROUPINFO == STD_ON )
static FUNC(uint8, COM_CODE) Com_SendSigGrp_Process
(
    Com_SignalGroupIdType sigGrpId
);
#endif

COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_PduTxProcess
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) astPduInfo
);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_PduTxSetVal
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
);

#if( COM_TXPDU_TPTYPE_SUPPORT == STD_ON )
static FUNC(void, COM_CODE) Com_PduTxTpProcess
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
);
#endif
static FUNC(void, COM_CODE) Com_PduTxCheckTimeOut
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
);
COM_LOCAL_INLINE FUNC(Std_ReturnType, COM_CODE) Com_OnePduSend
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
);
static FUNC(void, COM_CODE) Com_PduTriggerSend
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo,
    uint16 numberofRepetion,
    uint16 RepetionPeriod
);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_PduCycleSend
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo,
    uint16 PduCycle
);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_PduIfActiveSend
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo,
    uint16 PduCycleFast,
    uint16 numberofRepetion,
    uint16 RepetionPeriod
);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_PduPeriodicIfActiveSend
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo,
    uint16 PduCycle,
    uint16 PduCycleFast,
    uint16 numberofRepetion,
    uint16 RepetionPeriod
);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_PduPeriodicTxProcess
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo,
    uint16 PduCycle
);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_PduDirectTxProcess
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo,
    uint16 numberofRepetion,
    uint16 RepetionPeriod
);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_PduMixTxProcess
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo,
    uint16 PduCycle,
    uint16 numberofRepetion,
    uint16 RepetionPeriod
);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_PduIfActiveTxProcess
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo,
    uint16 PduCycleFast,
    uint16 numberofRepetion,
    uint16 RepetionPeriod
);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_PduPeriodicIfActiveTxProcess
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo,
    uint16 PduCycle,
    uint16 PduCycleFast,
    uint16 numberofRepetion,
    uint16 RepetionPeriod
);

#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
static FUNC(void, COM_CODE) Com_TxPduClearUb_Process
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
);
static FUNC(void, COM_CODE) Com_SigTxClearUb
(
    uint16 bitPos,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.5" */
    PduIdType pduId
);
#endif

static FUNC(void, COM_CODE) Com_TxConfirmationProcess
(
    PduIdType TxPduId
);

#if( COM_TXPDU_CBKNOTIFTY_SUPPORT == STD_ON )
static FUNC(void, COM_CODE) Com_TxDeferredProcess
(
    PduIdType PduId
);
#endif

#if( COM_TXPDU_CBKNOTIFTY_SUPPORT == STD_ON )
static FUNC(void, COM_CODE) Com_TxCfrmNotifition_Process
(
    PduIdType TxPduId
);
#endif

static FUNC(void, COM_CODE) Com_IpduGrpCtrl_UpTxIPduSts
(
    Com_IpduGroupVector ipduGrpVector,
    boolean initialize
);
static FUNC(void, COM_CODE) Com_TxSigWrite_Normal
(
    P2CONST(COM_TxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) txSigInfoPtr,
    uint32 sigValueBuf
);
static FUNC(void, COM_CODE) Com_TxSigWrite_Uint8N
(
    P2CONST(COM_TxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) txSigInfoPtr,
    P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) sigValueBufPtr
);
#if( (COM_PERFOPTMZ_SUPPORT != STD_ON) ||\
     (COM_MULTICORE_SUPPORT == STD_ON) ||\
     ((COM_GWSIGNALDSCP_NUM > COM_INIT_ZERO) && (COM_MULTICORE_SUPPORT != STD_ON)) )
static FUNC(uint32, COM_CODE) Com_RxSigRead_Normal
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) pduDataPtr,
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr
);
#endif
static FUNC(void, COM_CODE) Com_Memcpy
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) acpDest,
    P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) acpSrc,
    uint16 awCnt
);
static FUNC(void, COM_CODE) Com_InitAllIPdus_Rx
(
    void
);
static FUNC(void, COM_CODE) Com_InitOneIPdu_Rx
(
    uint16 pduIdx
);
static FUNC(void, COM_CODE) Com_RxSignalAnalysis_Process
(
    uint16 sigIdx,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) pduDataPtr,
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr
);

static FUNC(void, COM_CODE) Com_TxSigWrite_Large_64
(
    P2CONST(COM_TxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) txSigInfoPtr,
    uint64 sigValueBuf
);
#if( (COM_PERFOPTMZ_SUPPORT != STD_ON) ||\
     (COM_MULTICORE_SUPPORT == STD_ON) ||\
     ((COM_GWSIGNALDSCP_NUM > COM_INIT_ZERO) && (COM_MULTICORE_SUPPORT != STD_ON)) )
static FUNC(uint64, COM_CODE) Com_RxSigRead_Large_64
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) pduDataPtr,
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr
);
#endif

#if( COM_GWSIGNAL_NUM > COM_INIT_ZERO )
static FUNC(void, COM_CODE) Com_GwSig_ClearRecvFlag
(
    P2CONST(Com_GwMappingSigType, AUTOMATIC, COM_APPL_CONST) gwMappingSigPtr
);
static FUNC(void, COM_CODE) Com_GwSig_Process
(
    P2CONST(Com_GwMappingSigType, AUTOMATIC, COM_APPL_CONST) gwMappingSigPtr
);
#endif

#if( (COM_MULTICORE_SUPPORT == STD_ON) || ((COM_GWSIGNALDSCP_NUM > COM_INIT_ZERO) && (COM_MULTICORE_SUPPORT != STD_ON)) )
static FUNC(boolean, COM_CODE) Com_GwSigRxReadUb
(
    uint16 updateBitPosit,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr
);
#endif

#if( COM_MULTICORE_SUPPORT == STD_ON )
static FUNC(void, COM_CODE)Com_GwSigDscp_InterProcess
(
    P2CONST(Com_GwMappingSigDscpType, AUTOMATIC, COM_APPL_CONST) gwMappingSigDscpPtr
);
#elif( (COM_GWSIGNALDSCP_NUM > COM_INIT_ZERO) && (COM_MULTICORE_SUPPORT != STD_ON) )
static FUNC(void, COM_CODE) Com_GwSigDscp_Process
(
    P2CONST(Com_GwMappingSigDscpType, AUTOMATIC, COM_APPL_CONST) gwMappingSigDscpPtr
);
#endif  /* COM_MULTICORE_SUPPORT == STD_ON */

static FUNC(void, COM_CODE) Com_TxErrorNotification
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) txPduInfo
);
static FUNC(void, COM_CODE) Com_PduTxTimeOut_Cbk
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
);
#if( (COM_GWSIGNAL_NUM > COM_INIT_ZERO) && (COM_GWONLYTXMODETRUE != STD_ON) )
static FUNC(void, COM_CODE) Com_GwRefStopCycleDest
(
    P2CONST(Com_GwMappingSigType, AUTOMATIC, COM_APPL_CONST) gwMappingSigPtr
);
#endif  /* (COM_GWSIGNAL_NUM > COM_INIT_ZERO) && (COM_GWONLYTXMODETRUE != STD_ON) */

#if( COM_GWSIGNALDSCP_NUM > COM_INIT_ZERO )
static FUNC(void, COM_CODE)Com_GwSigDscp_ClearRecvFlag
(
    P2CONST(Com_GwMappingSigDscpType, AUTOMATIC, COM_APPL_CONST) gwMappingSigDscpPtr
);
static FUNC(void, COM_CODE) Com_GwDscpStopCycleDest
(
    P2CONST(Com_GwMappingSigDscpType, AUTOMATIC, COM_APPL_CONST) gwMappingSigDscpPtr
);
#endif

#if( COM_GWSIGNAL_SUPPORT == STD_ON )
static FUNC(void, COM_CODE) Com_GwInfoInit( void );
#endif

#if( COM_RXSIGGROUPINFO == STD_ON )
static FUNC(uint8, COM_CODE) Com_ReceiveSignalGroup_Process
(
    Com_SignalGroupIdType SignalGroupId
);
#endif

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
static FUNC(boolean, COM_CODE) Com_RxSigInvalidData_Handle_Boolean
(
    boolean tmpNewValue,
    uint16 sigIdx
);
static FUNC(boolean, COM_CODE) Com_RxSigInvalidData_Handle_uint8
(
    uint8 tmpNewValue,
    uint16 sigIdx
);
static FUNC(boolean, COM_CODE) Com_RxSigInvalidData_Handle_uint16
(
    uint16 tmpNewValue,
    uint16 sigIdx
);
static FUNC(boolean, COM_CODE) Com_RxSigInvalidData_Handle_uint32
(
    uint32 tmpNewValue,
    uint16 sigIdx
);
static FUNC(boolean, COM_CODE) Com_RxSigInvalidData_Handle_uint64
(
    uint64 tmpNewValue,
    uint16 sigIdx
);
static FUNC(boolean, COM_CODE) Com_RxSigInvalidData_Handle_sint8
(
    sint8 tmpNewValue,
    uint16 sigIdx
);
static FUNC(boolean, COM_CODE) Com_RxSigInvalidData_Handle_sint16
(
    sint16 tmpNewValue,
    uint16 sigIdx
);
static FUNC(boolean, COM_CODE) Com_RxSigInvalidData_Handle_sint32
(
    sint32 tmpNewValue,
    uint16 sigIdx
);
static FUNC(boolean, COM_CODE) Com_RxSigInvalidData_Handle_sint64
(
    sint64 tmpNewValue,
    uint16 sigIdx
);
static FUNC(boolean, COM_CODE) Com_RxSigInvalidData_Handle_uint8N
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) pduDataPtr,
    uint16 sigIdx,
    uint16 byteLenth
);
static FUNC(boolean, COM_CODE) Com_RxSigInvalidData_Handle_float32
(
    float32 tmpNewValue,
    uint16 sigIdx
);
static FUNC(boolean, COM_CODE) Com_RxSigInvalidData_Handle_float64
(
    float64 tmpNewValue,
    uint16 sigIdx
);
static FUNC(void, COM_CODE) Com_RxSigInvalidNotification_Handle
(
    uint16 sigIdx
);
#endif  /* (COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON) */

#if( COM_RXSIGFILTERINFO == STD_ON )
static FUNC(boolean, COM_CODE) Com_Signal_uint8_EvaluateFilter
(
    uint8 newValue,
    uint16 sigIdx
);
static FUNC(boolean, COM_CODE) Com_Signal_uint16_EvaluateFilter
(
    uint16 newValue,
    uint16 sigIdx
);
static FUNC(boolean, COM_CODE) Com_Signal_uint32_EvaluateFilter
(
    uint32 newValue,
    uint16 sigIdx
);
static FUNC(boolean, COM_CODE) Com_Signal_sint8_EvaluateFilter
(
    sint8 newValue,
    uint16 sigIdx
);
static FUNC(boolean, COM_CODE) Com_Signal_sint16_EvaluateFilter
(
    sint16 newValue,
    uint16 sigIdx
);
static FUNC(boolean, COM_CODE) Com_Signal_sint32_EvaluateFilter
(
    sint32 newValue,
    uint16 sigIdx
);
static FUNC(boolean, COM_CODE) Com_Signal_Boolean_EvaluateFilter
(
    boolean newValue,
    uint16 sigIdx
);
static FUNC(boolean, COM_CODE) Com_Signal_uint64_EvaluateFilter
(
    uint64 newValue,
    uint16 sigIdx
);
static FUNC(boolean, COM_CODE) Com_Signal_sint64_EvaluateFilter
(
    sint64 newValue,
    uint16 sigIdx
);
#endif  /* COM_RXSIGFILTERINFO == STD_ON */

#if( (COM_RXREPLACESIGOFRXTIMEOUTINFO == STD_ON) || (COM_RXUPDATEBITCFG_SUPPORT == STD_ON) )
static FUNC(void, COM_CODE) Com_RxSigTimeout_Replace_ToValue
(
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfo
);
#endif  /* (COM_RXREPLACESIGOFRXTIMEOUTINFO == STD_ON) || (COM_RXUPDATEBITCFG_SUPPORT == STD_ON) */

#if( COM_RXSIGGROUPINFO == STD_ON )
#if( (COM_RXREPLACESIGGROUPOFRXTIMEOUTINFO == STD_ON) || (COM_RXUPDATEBITCFG_SUPPORT == STD_ON) )
static FUNC(void, COM_CODE) Com_RxSigGrpTimeout_Replace_ToValue
(
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfo
);
#endif  /* (COM_RXREPLACESIGGROUPOFRXTIMEOUTINFO == STD_ON) || (COM_RXUPDATEBITCFG_SUPPORT == STD_ON) */
#endif  /* COM_RXSIGGROUPINFO == STD_ON */

#if( COM_TXPDU_MDT_SUPPORT == STD_ON )
static FUNC(void, COM_CODE)Com_MDTCounter
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
);
#endif /* COM_TXPDU_MDT_SUPPORT == STD_ON */

#if( COM_MULTICORE_SUPPORT == STD_ON )
static FUNC(void, COM_CODE) Com_InterCore_Process
(
    uint16 sigId,
    P2CONST(void, AUTOMATIC, COM_APPL_CONST) sigDataPtr
);
static FUNC(uint8, COM_CODE) Com_GetPduIndex
(
    Com_MainFunctionType mainFunction,
    uint8 direction,
    uint32 coreId,
    const Com_PduIndexInfo_st** PduIndexPtr
);
#endif  /* COM_MULTICORE_SUPPORT == STD_ON */

#if( COM_TXSIGNALFILTER_SUPPORTED == STD_ON )
static FUNC(void, COM_CODE) Com_TxSignalU8TMC_EvaluateFilter
(
    uint16 sigIdx,
    uint8 sigValue
);
static FUNC(void, COM_CODE) Com_TxSignalU16TMC_EvaluateFilter
(
    uint16 sigIdx,
    uint16 sigValue
);
static FUNC(void, COM_CODE) Com_TxSignalU32TMC_EvaluateFilter
(
    uint16 sigIdx,
    uint32 sigValue
);
static FUNC(void, COM_CODE) Com_TxSignalU64TMC_EvaluateFilter
(
    uint16 sigIdx,
    uint64 sigValue
);
static FUNC(void, COM_CODE) Com_TxSignalS8TMC_EvaluateFilter
(
    uint16 sigIdx,
    sint8 sigValue
);
static FUNC(void, COM_CODE) Com_TxSignalS16TMC_EvaluateFilter
(
    uint16 sigIdx,
    sint16 sigValue
);
static FUNC(void, COM_CODE) Com_TxSignalS32TMC_EvaluateFilter
(
    uint16 sigIdx,
    sint32 sigValue
);
static FUNC(void, COM_CODE) Com_TxSignalS64TMC_EvaluateFilter
(
    uint16 sigIdx,
    sint64 sigValue
);
static FUNC(void, COM_CODE) Com_TxSignalBOOLEANTMC_EvaluateFilter
(
    uint16 sigIdx,
    boolean sigValue
);
static FUNC(void, COM_CODE) Com_TxSignalUINT8N_UINT8DYNTMC_EvaluateFilter
(
    uint16 sigIdx
);
static FUNC(void, COM_CODE) Com_TxSigFilterUpdateIpduTxMode
(
    PduIdType PduId
);
static FUNC(boolean, COM_CODE) Com_TxSignalTypeFilter_Process
(
    uint16 sigId,
    P2CONST(void, AUTOMATIC, COM_APPL_CONST) sigDataPtr
);
static FUNC(void, COM_CODE) Com_TxSignalFilter_Process
(
    uint16 sigId,
    P2CONST(void, AUTOMATIC, COM_APPL_CONST) sigDataPtr
);
#if( COM_TXSIGGROUPINFO == STD_ON )
static FUNC(void, COM_CODE) Com_TxGroupSignalFilter_Process
(
    Com_SignalGroupIdType SignalGroupId
);
#endif  /* COM_TXSIGGROUPINFO == STD_ON */
#endif  /* COM_TXSIGNALFILTER_SUPPORTED == STD_ON */

#if( (COM_METADATA_SUPPORT == STD_ON) && (COM_TXMETADATA_NUM > COM_INIT_ZERO) )
COM_LOCAL_INLINE FUNC(Std_ReturnType, COM_CODE) Com_OnePduSendByMetaDataTrigger
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
);
#endif  /* ( (COM_METADATA_SUPPORT == STD_ON) && (COM_TXMETADATA_NUM > COM_INIT_ZERO) ) */

static FUNC(boolean, COM_CODE) Com_CompareFloat32Values
(
    float32 firstValue,
    float32 scndValue
);
static FUNC(boolean, COM_CODE) Com_CompareFloat64Values
(
    float64 firstValue,
    float64 scndValue
);

#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessU8
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
);

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessU16
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
);

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessU32
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
);

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessI8
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
);

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessI16
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
);

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessI32
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
);

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessUint8N
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
);

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessBoolean
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
);

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessFloat32
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
);

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessFloat64
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
);  /* PRQA S 0779  */ /* NSCA_QAC_Common_Rule5.1 */

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessU64
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
);

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessI64
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
);

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessUint8DYN
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
);  /* PRQA S 0779  */ /* NSCA_QAC_Common_Rule5.1 */

static FUNC(void, COM_CODE) Com_ReadSign_G_U8DYN
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) signData,
    P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) dataPtr,
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr
);

static FUNC(void, COM_CODE) Com_WriteSignU8DYN
(
    P2VAR(uint8, AUTOMATIC,COM_APPL_DATA) dataPtr,
    P2CONST(COM_TxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) txSigInfoPtr
);

#else  /* COM_PERFOPTMZ_SUPPORT != STD_ON */
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessU8
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) uintValue08,
    uint16 sigIdx
);

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessU16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) uintValue16,
    uint16 sigIdx
);

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessU32
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) uintValue32,
    uint16 sigIdx
);

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessI8
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) intValue08,
    uint16 sigIdx
);

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessI16
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) intValue16,
    uint16 sigIdx
);

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessI32
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) intValue32,
    uint16 sigIdx
);

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessUint8N
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) pduDataPtr,
    uint16 sigIdx,
    uint16 bytelenth
);

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessBoolean
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) booleanValue, 
    uint16 sigIdx
);

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessFloat32
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) floatValue32,
    uint16 sigIdx
);

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessFloat64
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) floatValue64, 
    uint16 sigIdx
);  /* PRQA S 0779  */ /* NSCA_QAC_Common_Rule5.1 */

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessU64
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) uintValue64,
    uint16 sigIdx
);

static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessI64
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) intValue64, 
    uint16 sigIdx
);
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */

static FUNC(void, COM_CODE) Com_RxDynSignalLengthEvlateProcess
(
    uint16 sigIdx
);

#define COM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
#define COM_START_SEC_CONST
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/* receive signal updatebit/invalid/filter process function list. */
CONST(Com_RxSigUbInVFilterFunc, COM_APPL_CONST) Com_RxSigUbInvFilterFuncTable[COM_RXPARSESIGNAL_FUNC_NUM + COM_ONE] =  /* PRQA S 1514 */ /* NSCA_QAC_Com_Rule8.9 */
{
    Com_RxSigUbInvFilterProcessBoolean,  /* bool type signal updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU8,       /* uint8 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU8,       /* uint8 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU8,       /* uint8 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU8,       /* uint8 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU8,       /* uint8 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU16,      /* uint8 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU16,      /* uint16 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU16,      /* uint16 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU16,      /* uint16 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU16,      /* uint16 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU32,      /* uint32 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU32,      /* uint32 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU32,      /* uint32 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU32,      /* uint32 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU32,      /* uint32 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU32,      /* uint32 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU32,      /* uint32 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU32,      /* uint32 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU32,      /* uint32 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU32,      /* uint32 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU64,      /* uint64 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI8,       /* sint8 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI8,       /* sint8 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI8,       /* sint8 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI8,       /* sint8 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI8,       /* sint8 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI16,      /* sint16 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI16,      /* sint16 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI16,      /* sint16 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI16,      /* sint16 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI16,      /* sint16 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI32,      /* sint32 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI32,      /* sint32 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI32,      /* sint32 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI32,      /* sint32 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI32,      /* sint32 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI32,      /* sint32 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI32,      /* sint32 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI32,      /* sint32 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI32,      /* sint32 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI32,      /* sint32 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI64,      /* sint64 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessFloat32,  /* float32 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessFloat64,  /* float64 type signal big endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU8,       /* uint8 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU8,       /* uint8 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU8,       /* uint8 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU8,       /* uint8 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU8,       /* uint8 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU16,      /* uint16 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU16,      /* uint16 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU16,      /* uint16 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU16,      /* uint16 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU16,      /* uint16 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU32,      /* uint32 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU32,      /* uint32 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU32,      /* uint32 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU32,      /* uint32 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU32,      /* uint32 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU32,      /* uint32 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU32,      /* uint32 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU32,      /* uint32 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU32,      /* uint32 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU32,      /* uint32 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessU64,      /* uint64 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI8,       /* sint8 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI8,       /* sint8 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI8,       /* sint8 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI8,       /* sint8 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI8,       /* sint8 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI16,      /* sint16 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI16,      /* sint16 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI16,      /* sint16 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI16,      /* sint16 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI16,      /* sint16 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI32,      /* sint32 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI32,      /* sint32 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI32,      /* sint32 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI32,      /* sint32 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI32,      /* sint32 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI32,      /* sint32 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI32,      /* sint32 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI32,      /* sint32 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI32,      /* sint32 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI32,      /* sint32 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessI64,      /* sint64 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessFloat32,  /* float32 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessFloat64,  /* float64 type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessUint8N,   /* uint8_N type signal little endian updatebit/invalid/filter process. */
    Com_RxSigUbInvFilterProcessUint8DYN  /* uint8_DYN type signal little endian updatebit/invalid/filter process. */
};
#define COM_STOP_SEC_CONST
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
#endif

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define COM_START_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Com_UnusedVariable" */
P2VAR(Com_ConfigType, COM_VAR_INIT, COM_APPL_DATA) Com_ConfigDataPtr = NULL_PTR;

#define COM_STOP_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define COM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if( COM_TXPDU_MDT_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Com_MDTCounter
*
* Explanation: Update MDT status and count for Tx Pdus.
*
* param: PduInfo: Tx Pdu Info
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE)Com_MDTCounter
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
)
{
    /* Periodic MDT */
    if( NULL_PTR != PduInfo->astPduInterMonitor )
    {
        if( COM_MDTFORCYC_START == PduInfo->astPduInterMonitor->pduCycMDTState )
        {
            if( COM_INIT_ZERO != PduInfo->astPduInterMonitor->pduCycCntForMDT )
            {
                /* The minimum delay time has passed one task cycle */
                PduInfo->astPduInterMonitor->pduCycCntForMDT--;
            }
            if( COM_INIT_ZERO == PduInfo->astPduInterMonitor->pduCycCntForMDT )
            {
                /* Periodic MDT is ready*/
                PduInfo->astPduInterMonitor->pduCycMDTState = COM_MDTFORCYC_READY;
            }
        }
    }
    /* Triggered MDT */
    if( NULL_PTR != PduInfo->pduTriggerMonitor )
    {
        if( COM_MDTFORTRG_START == PduInfo->pduTriggerMonitor->pduTrgMDTState )
        {
            /* The minimum delay time has passed one task cycle */
            if( COM_INIT_ZERO != PduInfo->pduTriggerMonitor->pduTrgCycCntForMDT )
            {
                PduInfo->pduTriggerMonitor->pduTrgCycCntForMDT--;
            }
            if( COM_INIT_ZERO == PduInfo->pduTriggerMonitor->pduTrgCycCntForMDT )
            {
                /* Triggered MDT is ready*/
                PduInfo->pduTriggerMonitor->pduTrgMDTState = COM_MDTFORTRG_READY;
            }
        }
    }
}
#endif

#if( COM_DEV_ERROR_REPORT == STD_ON )
/*
********************************************************************************
* Function Name: Com_Det_ErrorReport
*
* Explanation: Com Det Error Report
*
* param: ApiId:Api Service Id
*        ErrorId: Error Id
*
* retval: void
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_Det_ErrorReport
(
    uint8 ApiId,
    uint8 ErrorId
)
{
    if( ErrorId != COM_E_NO_ERROR )  /* Error detected. */
    {
        /* Report Error to Det. */
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, ApiId, ErrorId);
    }
}
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

/*
********************************************************************************
* Function Name: Com_IpduGrpCtrl_UpRxIPduSts
*
* Explanation: This service starts or stop Rx I-PDU groups.
*
* param: ipduGroupVector: I-PDU group vector containing the activation state
*                         (stopped = 0/ started = 1) for all I-PDU groups.
*        initialize: Flag to request initialization of the I-PDUs which are newly started.
*
* retval: void
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_IpduGrpCtrl_UpRxIPduSts
(
    /* PolySpace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.13" */
    Com_IpduGroupVector ipduGroupVector,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    boolean initialize
)
{
    Com_RxPduActSts abReqActiveState;
    uint8 vectorBitOffset = COM_INIT_ZERO;
    uint8 vectorBitShift = COM_INIT_ZERO;
    uint16 vectorBytePos;
    uint16 vectorMatchPos;
    uint16 awPduIdx;
    uint16 pduGrpVectorIdx;
    const COM_RxPduInfo_st* com_astPdu = Com_RxPduInfo;

    for( awPduIdx = COM_INIT_ZERO; awPduIdx < COM_RXPDU_NUM; awPduIdx++)
    {
        com_astPdu = &Com_RxPduInfo[awPduIdx];

        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        if( COM_PDU_TYPE_ACTIVE_CONTROL == com_astPdu->acPduActiveType )
        {
            abReqActiveState = COM_PDU_INACTIVE;  /* Init local Variable abRequestedActiveState is False. */

            for( pduGrpVectorIdx = com_astPdu->acPduGrpVectorStartIdx;
                ((pduGrpVectorIdx < com_astPdu->acpduGrpVectorEndIdx)
                    && (COM_PDU_INACTIVE == abReqActiveState)); pduGrpVectorIdx++ )
            {
                /* get matched actual IPdu Group Vector Mask. */
                vectorMatchPos = Com_PduGrpVectorMatch[pduGrpVectorIdx];
                vectorBytePos = vectorMatchPos / COM_1BYTE_BITLENGTH;
                vectorBitOffset = (uint8)(vectorMatchPos % COM_1BYTE_BITLENGTH);

                vectorBitShift = COM_OPERAND_ONE;
                vectorBitShift <<= vectorBitOffset;
                /* If at least one related ComIPduGroup is active the requested state is active. */
                /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" */
                if( COM_INIT_ZERO != ((uint8)ipduGroupVector[vectorBytePos] & vectorBitShift) )
                {
                    /* An I-PDU is active if and only if at least one I-PDU group is active it belongs to. */
                    abReqActiveState = COM_PDU_ACTIVE;
                }
            }

            if( (COM_PDU_INACTIVE == com_astPdu->astPduInterMonitor->pduSta)
                 && (COM_PDU_ACTIVE == abReqActiveState) )
            {
                /* Set the state of the Rx ComIPdu to active. */
                com_astPdu->astPduInterMonitor->pduSta = COM_PDU_ACTIVE;

                /* Wative receive. */
                com_astPdu->astPduInterMonitor->acPduRecSts = COM_PDU_NORECEIVE;

                /* Counter reset. */
                com_astPdu->astPduInterMonitor->acPduCycCounter = com_astPdu->sigMinimumFirstTimeout;

                /* Reset signal deadline counter and set the signal monitor flag. */
                Com_InitRxSignalCnt(com_astPdu);
            }
            else if( (com_astPdu->astPduInterMonitor->pduSta != COM_PDU_INACTIVE )
                && (COM_PDU_INACTIVE == abReqActiveState) )
            {
                 /* Inactive Ipdu process. */
                com_astPdu->astPduInterMonitor->pduSta = COM_PDU_INACTIVE;
            }
            else
            {
                /* Do nothing. */
            }

            if( (boolean)TRUE == initialize )
            {
                /* Init RxPdu DataBuffer. */
                Com_InitRxBuffer(com_astPdu);
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Com_ReceiveSignal_Process
*
* Explanation: copies the data of the signal identified by SignalId to the location
*              specified by SignalDataPtr.
* param: SignalId: Id of signal to be received.
*        SignalDataPtr: Reference to the location where the received signal data shall be stored.
* retval: acRecRet: E_OK: service has been accepted.
*                   COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped
*                       (or service failed due to development error).
*                   COM_BUSY: in case the TP-Buffer is locked for large data types handling.
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_ReceiveSignal_Process
(
    uint16 SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
    Com_SigType receiveSignalType;
    uint16 aryByteLength;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSignalInfo_st* rxSigInfo = &Com_RxSignalInfo[SignalId];
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
    uint8* receiveDataPtr = (uint8*)Com_RxSignalInfo[SignalId].sigRTEValue;  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */

    /* Obtain signal type. */
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
    receiveSignalType = Com_RxSignalInfo[SignalId].acSigType;
#else  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
    receiveSignalType = Com_GetSignalType(Com_RxSignalInfo[SignalId].sigBaseInfo->sigFuncIdx);
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
    /* Judge signal type. */
    /* PolySpace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_Com_16.1" */
    switch( receiveSignalType )
    {
        /* Assign the value of RTE to SignalDataPtr. */
        case COM_SIGTYPE_BOOLEAN:
            /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
            Com_SIGNAL_GETRTETODATAPTR(SignalDataPtr, boolean, rxSigInfo);  /* PRQA S 0311, 0316 */ /* NSCA_QAC_Com_Rule11.8, NSCA_QAC_Com_Rule11.5 */
            break;
        case COM_SIGTYPE_UINT8:
            /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
            Com_SIGNAL_GETRTETODATAPTR(SignalDataPtr, uint8, rxSigInfo);  /* PRQA S 0311, 0316 */ /* NSCA_QAC_Com_Rule11.8, NSCA_QAC_Com_Rule11.5 */
            break;
        case COM_SIGTYPE_UINT16:
            /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            Com_SIGNAL_GETRTETODATAPTR(SignalDataPtr, uint16, rxSigInfo);  /* PRQA S 0311, 0316 */ /* NSCA_QAC_Com_Rule11.8, NSCA_QAC_Com_Rule11.5 */
            break;
        case COM_SIGTYPE_UINT32:
            /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            Com_SIGNAL_GETRTETODATAPTR(SignalDataPtr, uint32, rxSigInfo);  /* PRQA S 0311, 0316 */ /* NSCA_QAC_Com_Rule11.8, NSCA_QAC_Com_Rule11.5 */
            break;
        case COM_SIGTYPE_UINT64:
            /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            Com_SIGNAL_GETRTETODATAPTR(SignalDataPtr, uint64, rxSigInfo);  /* PRQA S 0311, 0316 */ /* NSCA_QAC_Com_Rule11.8, NSCA_QAC_Com_Rule11.5 */
            break;
        case COM_SIGTYPE_SINT8:
            /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
            Com_SIGNAL_GETRTETODATAPTR(SignalDataPtr, sint8, rxSigInfo);  /* PRQA S 0311, 0316 */ /* NSCA_QAC_Com_Rule11.8, NSCA_QAC_Com_Rule11.5 */
            break;
        case COM_SIGTYPE_SINT16:
            /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            Com_SIGNAL_GETRTETODATAPTR(SignalDataPtr, sint16, rxSigInfo);  /* PRQA S 0311, 0316 */ /* NSCA_QAC_Com_Rule11.8, NSCA_QAC_Com_Rule11.5 */
            break;
        case COM_SIGTYPE_SINT32:
            /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            Com_SIGNAL_GETRTETODATAPTR(SignalDataPtr, sint32, rxSigInfo);  /* PRQA S 0311, 0316 */ /* NSCA_QAC_Com_Rule11.8, NSCA_QAC_Com_Rule11.5 */
            break;
        case COM_SIGTYPE_SINT64:
            /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            Com_SIGNAL_GETRTETODATAPTR(SignalDataPtr, sint64, rxSigInfo);  /* PRQA S 0311, 0316 */ /* NSCA_QAC_Com_Rule11.8, NSCA_QAC_Com_Rule11.5 */
            break;
        case COM_SIGTYPE_UINT8_DYN:
            /* Get dynamic signal length. */
            aryByteLength = Com_RxSignalInfo[SignalId].astSignalInterMonitor->acDynSignalLength;
            /* PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
            Com_Memcpy((uint8*)SignalDataPtr, (uint8*)receiveDataPtr, aryByteLength);  /* PRQA S 0311, 0316 */ /* NSCA_QAC_Com_Rule11.8, NSCA_QAC_Com_Rule11.5 */
            break;
        case COM_SIGTYPE_UINT8_N:
            /* Get byte length of uint8_N signal. */
            aryByteLength = Com_RxSignalInfo[SignalId].sigBaseInfo->sigByteLength;
            /* PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
            Com_Memcpy((uint8*)SignalDataPtr, (uint8*)receiveDataPtr, aryByteLength);  /* PRQA S 0311, 0316 */ /* NSCA_QAC_Com_Rule11.8, NSCA_QAC_Com_Rule11.5 */
            break;
        case COM_SIGTYPE_FLOAT32:
            /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            Com_SIGNAL_GETRTETODATAPTR(SignalDataPtr, uint32, rxSigInfo);  /* PRQA S 0311, 0316 */ /* NSCA_QAC_Com_Rule11.8, NSCA_QAC_Com_Rule11.5 */
            break;
        case COM_SIGTYPE_FLOAT64:
            /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            Com_SIGNAL_GETRTETODATAPTR(SignalDataPtr, uint64, rxSigInfo);  /* PRQA S 0311, 0316 */ /* NSCA_QAC_Com_Rule11.8, NSCA_QAC_Com_Rule11.5 */
            break;
        /* PolySpace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_Com_16.4" */
        default:
            break;
    }
}

#if( COM_RXSIGGROUPINFO == STD_ON )
/*
********************************************************************************
* Function Name: Com_ReceiveSignalGroup_Process
*
* Explanation: The service Com_ReceiveSignalGroup_Process copies the received
*              signal group from the I-PDU to the shadow buffer.
* param: SignalGroupId :Id of signal group to be received.
* retval: checkRet : E_OK: service has been accepted.
*                    COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                       stopped (or service failed due to development error).
*                    COM_BUSY: in case the TP-Buffer is locked for large data types handling.
********************************************************************************
*/
static FUNC(uint8, COM_CODE) Com_ReceiveSignalGroup_Process  /* PRQA S 3219 */ /* NSCA_QAC_Common_Unreachable */
(
    Com_SignalGroupIdType SignalGroupId  /* PRQA S 3206 */ /* NSCA_QAC_Com_Rule2.7 */
)
{
#if(COM_RXWITHOUTSHADOWVALUE == STD_ON)
    uint8 checkRet = E_OK;
#else
    uint8 checkRet = COM_SERVICE_NOT_AVAILABLE;
    Com_SigType receiveSignalType;
    uint16 sigIdx = COM_INIT_ZERO;
    uint16 sigStart;
    uint16 sigEnd;
    uint16 aryByteLength;

    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSigGrpInfo_st* rxSigGrpInfo = Com_RxSigGrpInfo;
    const COM_RxSignalInfo_st* rxSigInfo = NULL_PTR;

    sigStart = rxSigGrpInfo[SignalGroupId].acSigIndStart;
    sigEnd = rxSigGrpInfo[SignalGroupId].acSigIndEnd;

    /* received data. */
    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
    if( (uint8)COM_SIGGRP_VALID == *(rxSigGrpInfo[SignalGroupId].receiveDataSta) )
    {
        /* Poll all signal in corresponding signalGroup. */
        for( sigIdx = sigStart; sigIdx < sigEnd; sigIdx++ )
        {
            rxSigInfo = &Com_RxSignalInfo[sigIdx];
            /* Obtain signal type. */
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
            receiveSignalType = Com_RxSignalInfo[sigIdx].acSigType;
#else  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
            receiveSignalType = Com_GetSignalType(Com_RxSignalInfo[sigIdx].sigBaseInfo->sigFuncIdx);
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */

            /* Judge signal type. */
            switch( receiveSignalType )
            {
                /* Assign to RteVale from ShadowValue. */
                case COM_SIGTYPE_BOOLEAN:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNALGRP_ASSIGNMENT(boolean, rxSigInfo);  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_UINT8:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNALGRP_ASSIGNMENT(uint8, rxSigInfo);  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_UINT16:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNALGRP_ASSIGNMENT(uint16, rxSigInfo);  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_UINT32:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNALGRP_ASSIGNMENT(uint32, rxSigInfo);  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_UINT64:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNALGRP_ASSIGNMENT(uint64, rxSigInfo);  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_SINT8:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNALGRP_ASSIGNMENT(sint8, rxSigInfo);  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_SINT16:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNALGRP_ASSIGNMENT(sint16, rxSigInfo);  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_SINT32:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNALGRP_ASSIGNMENT(sint32, rxSigInfo);  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_SINT64:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNALGRP_ASSIGNMENT(sint64, rxSigInfo);  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_UINT8_DYN:
                    /* Get dynamic signal length. */
                    aryByteLength = Com_RxSignalInfo[sigIdx].astSignalInterMonitor->acDynSignalLength;
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_Memcpy((uint8*)(rxSigInfo->sigRTEValue), (uint8*)(rxSigInfo->sigShadowValue), aryByteLength);  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_UINT8_N:
                    /* Get uint8_N signal length. */
                    aryByteLength = Com_RxSignalInfo[sigIdx].sigBaseInfo->sigByteLength;
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_Memcpy((uint8*)(rxSigInfo->sigRTEValue), (uint8*)(rxSigInfo->sigShadowValue), aryByteLength);  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_FLOAT32:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNALGRP_ASSIGNMENT(uint32, rxSigInfo);  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_FLOAT64:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNALGRP_ASSIGNMENT(uint64, rxSigInfo);  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                default:   /* COV_COM_MISRA */
                    break;
            }
        }
        checkRet = E_OK;
    }
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
    return checkRet;
}
#endif  /* COM_RXSIGGROUPINFO == STD_ON  */

/*
********************************************************************************
* Function Name: Com_PduRxProcess
*
* Explanation: performs the processing of the AUTOSAR COM module's receive processing.
*
* param: PduInfo: Rx Pdu Info.
*
* retval: void
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_PduRxProcess
(
    P2CONST(COM_RxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
)
{
    uint16 sigIdx;

#if( COM_RXSIGGROUPINFO == STD_ON )
    uint16 GrpIdx;
#endif
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxPduInfo_st* astPduInfo = PduInfo;
    const COM_RxSignalInfo_st* rxSigInfo = NULL_PTR;

    /* Determine if the message is received. */
    /* PolySpace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_Com_10.4" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
    if( COM_PDU_RECEIVED == (astPduInfo->astPduInterMonitor->acPduRecSts & COM_PDU_RECEIVED) )  /* PRQA S 1881, 4522 */ /* NSCA_QAC_Com_Rule10.4, NSCA_QAC_Com_Rule10.1 */
    {
        /* Clear pdu timeout flag */
        /* PolySpace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
        astPduInfo->astPduInterMonitor->acPduRecSts &= (~COM_PDU_RECTIMEOUT);  /* PRQA S 4432, 4522, 4532 */ /* NSCA_QAC_Com_Rule10.3, NSCA_QAC_Com_Rule10.1, NSCA_QAC_Com_Rule10.1 */
        /* Clear pdu received flag and set GW flags. (COM_PDU_WAITRECEIVE) */
        /* PolySpace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
        astPduInfo->astPduInterMonitor->acPduRecSts &= (~COM_PDU_RECEIVED);  /* PRQA S 4432, 4522, 4532 */ /* NSCA_QAC_Com_Rule10.3, NSCA_QAC_Com_Rule10.1, NSCA_QAC_Com_Rule10.1 */
        /* PolySpace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
        astPduInfo->astPduInterMonitor->acPduRecSts |= COM_PDU_GW_SIG_FLAG;  /* PRQA S 4432, 4522 */ /* NSCA_QAC_Com_Rule10.3, NSCA_QAC_Com_Rule10.1 */
        /* Clear the timeout flag. */
        astPduInfo->astPduInterMonitor->rxTimeout = FALSE;

        /* Polling all signals on the pdu. */
        for( sigIdx = astPduInfo->awSigStartIndex; sigIdx < astPduInfo->awSigEndIndex; sigIdx++ )
        {
            /* Is not a signal group type. */
            if( COM_SIG_NO_GROUP_DEF == Com_RxSignalInfo[sigIdx].acSigGrpIdx )
            {
                rxSigInfo = &Com_RxSignalInfo[sigIdx];
                /* Analytic signal. */
                Com_RxSignalAnalysis_Process(sigIdx, (astPduInfo->datavalid), rxSigInfo);
                if( FALSE == rxSigInfo->astSignalInterMonitor->acSignalEnableDeadline )
                {
                    rxSigInfo->astSignalInterMonitor->acSignalEnableDeadline = TRUE;
                }
                if( FALSE == rxSigInfo->astSignalInterMonitor->acSignalUpdateEnableDeadline )
                {
                    rxSigInfo->astSignalInterMonitor->acSignalUpdateEnableDeadline = TRUE;
                }
            }
        }

#if( COM_RXSIGGROUPINFO == STD_ON )
         /* Signalgroup process. */
        for( GrpIdx = astPduInfo->acSigGrpStartIndex; GrpIdx < astPduInfo->acSigGrpEndIndex; GrpIdx++ )
        {
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
            if( (uint8)TRUE == Com_SigGrpRxReadUb(GrpIdx) )
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */
            {
                /* Do Rx ComSignalGroup processing. */
                Com_RxProcessing_ProcessSigGrpEvent(GrpIdx, astPduInfo);
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                if( FALSE == Com_RxSigGrpInfo[GrpIdx].astSignalGrpInterMonitor->acSignalGrpEnableDeadline )
                {
                    Com_RxSigGrpInfo[GrpIdx].astSignalGrpInterMonitor->acSignalGrpEnableDeadline = TRUE;
                }
                if( FALSE == Com_RxSigGrpInfo[GrpIdx].astSignalGrpInterMonitor->acSignalGrpUpdateEnableDeadline )
                {
                    Com_RxSigGrpInfo[GrpIdx].astSignalGrpInterMonitor->acSignalGrpUpdateEnableDeadline = TRUE;
                }
            }
        }
#endif  /* (COM_RXSIGGROUPINFO == STD_ON) */

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
        Com_RxUpdateCntProcess(astPduInfo);
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */

        /* Pdu counter redo set. */
        astPduInfo->astPduInterMonitor->acPduCycCounter = astPduInfo->sigMinimumTimeout + COM_OPERAND_ONE;
    }
}

#if( COM_RXSIGGROUPINFO == STD_ON )
/*
********************************************************************************
* Function Name: Com_RxProcessing_ProcessSigGrpEvent
*
* Explanation: Do Rx ComSignalGroup processing.
*
* param: sigGrpIdx: Rx signal group index.
*        astPduInfo: Rx Pdu Info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxProcessing_ProcessSigGrpEvent
(
    uint16 sigGrpIdx,
    P2CONST(COM_RxPduInfo_st, AUTOMATIC, COM_APPL_CONST) astPduInfo
)
{
#if( COM_INVALIDACTION_SUPPORT == STD_ON )
    boolean exitInvalidSta = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterSta;
#endif

#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
    /* Need not to parse the signal group if it is a E2E group. */
    if( COM_RXSIGGRPTYPE_E2E != Com_RxSigGrpInfo[sigGrpIdx].sigGrpType )
#endif
    {
        /* Read the passed ComSignalGroup values from the passed ComIPdu. */
        Com_RxPrcessing_ReadSignalGroup(sigGrpIdx, astPduInfo);
    }

#if( COM_INVALIDACTION_SUPPORT == STD_ON )
    exitInvalidSta = Com_RxInv_SigGrp(sigGrpIdx);

    if( TRUE == exitInvalidSta )
    {
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        *(Com_RxSigGrpInfo[sigGrpIdx].receiveDataSta) = (uint8)COM_SIGGRP_INVALID;
    }
    else  /* FALSE == exitInvalidSta */
#endif  /* COM_INVALIDACTION_SUPPORT == STD_ON */
    {
#if( COM_RXSIGFILTERINFO == STD_ON )
        filterSta = Com_RxProcessing_RxSignalGroupFilterChk(sigGrpIdx);

        if( FALSE == filterSta )
        {
            *(Com_RxSigGrpInfo[sigGrpIdx].receiveDataSta) = (uint8)COM_SIGGRP_FILTERED;
        }
        else /*( TRUE == filterSta ) */
#endif  /* COM_RXSIGFILTERINFO == STD_ON */
        {
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            *(Com_RxSigGrpInfo[sigGrpIdx].receiveDataSta) = (uint8)COM_SIGGRP_VALID;
#if( COM_RXSIGGRP_NOTIFICATION_SUPPORT == STD_ON )
             /* Normal received. */
            if( NULL_PTR != Com_RxSigGrpInfo[sigGrpIdx].Notification_p )
            {
                Com_RxSigGrpInfo[sigGrpIdx].Notification_p();
            }
#endif  /* COM_RXSIGGRP_NOTIFICATION_SUPPORT == STD_ON */
        }
    }
}

/*
********************************************************************************
* Function Name: Com_RxPrcessing_ReadSignalGroup
*
* Explanation: Read the passed ComSignalGroup values from the passed ComIPdu.
*
* param: sigGrpIdx: Rx signal group index.
*        astPduInfo: Rx Pdu Info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxPrcessing_ReadSignalGroup
(
    uint16 sigGrpIdx,
    P2CONST(COM_RxPduInfo_st, AUTOMATIC, COM_APPL_CONST) astPduInfo
)
{
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    uint16 grpSigStartIdx = Com_RxSigGrpInfo[sigGrpIdx].acSigIndStart;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    uint16 grpSigEndIdx = Com_RxSigGrpInfo[sigGrpIdx].acSigIndEnd;
    const COM_RxSignalInfo_st* rxSignalInfo = NULL_PTR;
    uint16 grpSigIdx;
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
    uint8 sigFuncIdx;
#else
    Com_SigBitLengthType bitSize;
    sint8 receiveValueI8;
    uint16 dynSignalLength;
    sint16 receiveValueI16;
    uint16 sigLengthIndex;
    uint16 sigStartByte;
    sint32 receiveValueI32;
    uint32 sigValue;
    uint32 tempValue;
    uint64 sigValuelarge;
    sint64 receiveValueI64;
#endif
    for( grpSigIdx = grpSigStartIdx; grpSigIdx < grpSigEndIdx; grpSigIdx++ )
    {
        rxSignalInfo = &Com_RxSignalInfo[grpSigIdx];
        if( (rxSignalInfo != NULL_PTR) && (COM_SIG_NO_GROUP_DEF != rxSignalInfo->acSigGrpIdx) )
        {
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
            /* Get signal sigFuncIdx. */
            sigFuncIdx = rxSignalInfo->sigBaseInfo->sigFuncIdx;
            if( COM_RXPARSESIGNAL_FUNC_NUM > sigFuncIdx ) /* Judeg validity of sigFuncIdx. */
            {
                /* Parse received message data to signal. */
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
                Com_RxParseSignalFuncTable[sigFuncIdx]((const uint8*)(astPduInfo->datavalid), rxSignalInfo->sigRTEValue,  /* PRQA S 0317*/ /* NSCA_QAC_Com_Rule11.5 */
                                                                    rxSignalInfo->sigBaseInfo);
#else  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                Com_RxParseSignalFuncTable[sigFuncIdx]((const uint8*)(astPduInfo->datavalid), rxSignalInfo->sigShadowValue,  /* PRQA S 0317*/ /* NSCA_QAC_Com_Rule11.5 */
                                                                    rxSignalInfo->sigBaseInfo);
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
            }
            else if( COM_RXPARSESIGNAL_FUNC_NUM == sigFuncIdx ) /* sigFuncIdx is U8DYN signal sigFuncIdx. */
            {
                /* Parse received message data to U8DYN signal. */
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
                Com_ReadSign_G_U8DYN(rxSignalInfo->sigRTEValue, (const uint8*)(astPduInfo->datavalid), rxSignalInfo);
#else  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                Com_ReadSign_G_U8DYN(rxSignalInfo->sigShadowValue, (const uint8*)(astPduInfo->datavalid), rxSignalInfo);
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
            }
            else
            {
                /* Do nothing. */
            }
#else
            /* Get bit size. */
            bitSize = rxSignalInfo->sigBaseInfo->sigBitLength;
            /* Judge signal type. */
            /* PolySpace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_Com_16.1" */
            switch( Com_GetSignalType(rxSignalInfo->sigBaseInfo->sigFuncIdx) )
            {
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
                case COM_SIGTYPE_BOOLEAN:
                    sigValue = Com_RxSigRead_Normal((const uint8*)(astPduInfo->datavalid), rxSignalInfo);
                    *(boolean*)rxSignalInfo->sigRTEValue = (boolean)sigValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_UINT8:
                    sigValue = Com_RxSigRead_Normal((const uint8*)(astPduInfo->datavalid), rxSignalInfo);
                    *(uint8*)rxSignalInfo->sigRTEValue = (uint8)sigValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_UINT16:
                    sigValue = Com_RxSigRead_Normal((const uint8*)(astPduInfo->datavalid), rxSignalInfo);
                    *(uint16*)rxSignalInfo->sigRTEValue = (uint16)sigValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_UINT32:
                    sigValue = Com_RxSigRead_Normal((const uint8*)(astPduInfo->datavalid), rxSignalInfo);
                    *(uint32*)rxSignalInfo->sigRTEValue = (uint32)sigValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_UINT64:
                    sigValuelarge = Com_RxSigRead_Large_64((const uint8*)(astPduInfo->datavalid), rxSignalInfo);
                    *(uint64*)rxSignalInfo->sigRTEValue = sigValuelarge;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_SINT8:
                    sigValue = Com_RxSigRead_Normal((const uint8*)(astPduInfo->datavalid), rxSignalInfo);

                    if( COM_OPERAND_ONE == (sigValue >> (bitSize - COM_OPERAND_ONE)) ) /* sigValue < 0. */
                    {
                        tempValue = (sigValue | ((uint32)COM_INIT_FF << bitSize));
                        receiveValueI8 = (sint8)((uint8)tempValue); /* high-order position complement 1 */
                    }
                    else
                    {
                        receiveValueI8 = (sint8)((uint8)sigValue);
                    }
                    *(sint8*)rxSignalInfo->sigRTEValue = receiveValueI8;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_SINT16:
                    sigValue = Com_RxSigRead_Normal((const uint8*)(astPduInfo->datavalid), rxSignalInfo);

                    if( COM_OPERAND_ONE == (sigValue >> (bitSize - COM_OPERAND_ONE)) ) /* sigValue < 0 */
                    {
                        tempValue = (sigValue | ((uint32)COM_INIT_U16FF << bitSize));
                        receiveValueI16 = (sint16)((uint16)tempValue); /* high-order position complement 1 */
                    }
                    else
                    {
                        receiveValueI16 = (sint16)((uint16)sigValue);
                    }
                    *(sint16*)rxSignalInfo->sigRTEValue = receiveValueI16;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_SINT32:
                    sigValue = Com_RxSigRead_Normal((const uint8*)(astPduInfo->datavalid), rxSignalInfo);

                    if( COM_OPERAND_ONE == (sigValue >> (bitSize - COM_OPERAND_ONE)) ) /* sigValue < 0 */
                    {
                        tempValue = (sigValue | ((uint32)COM_INIT_U32FF << bitSize));
                        receiveValueI32 = (sint32)tempValue; /* high-order position  complement 1 */
                    }
                    else
                    {
                        receiveValueI32 = (sint32)sigValue;
                    }
                    *(sint32*)rxSignalInfo->sigRTEValue = receiveValueI32;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_SINT64:
                    sigValuelarge = Com_RxSigRead_Large_64((const uint8*)(astPduInfo->datavalid), rxSignalInfo);

                    if( COM_OPERAND_ONE == (sigValuelarge >> (bitSize - COM_OPERAND_ONE)) ) /* sigValue < 0 */
                    {
                        /* high-order position   complement 1 */
                        receiveValueI64 = (sint64)(sigValuelarge | (uint64)(COM_INIT_U64FF << bitSize));  /* PRQA S 4394*/ /* NSCA_QAC_Com_Rule10.8 */
                    }
                    else
                    {
                        receiveValueI64 = (sint64)sigValuelarge;
                    }
                    *(sint64*)rxSignalInfo->sigRTEValue = receiveValueI64;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_UINT8_DYN:
                    dynSignalLength = rxSignalInfo->astSignalInterMonitor->acDynSignalLength;
                    /* Get start byte position of signal. */
                    sigStartByte = rxSignalInfo->sigBaseInfo->sigStartByte;

                    for( sigLengthIndex = sigStartByte;
                    sigLengthIndex < (sigStartByte + dynSignalLength); sigLengthIndex++ )
                    {
                        ((uint8*)rxSignalInfo->sigRTEValue)[sigLengthIndex - sigStartByte]  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                            = astPduInfo->datavalid[sigLengthIndex];
                    }
                    break;
                case COM_SIGTYPE_UINT8_N:
                    /* Get start byte position of signal. */
                    sigStartByte = rxSignalInfo->sigBaseInfo->sigStartByte;
                    for( sigLengthIndex = sigStartByte;
                      sigLengthIndex < (sigStartByte + (rxSignalInfo->sigBaseInfo->sigByteLength) ); sigLengthIndex++ )
                    {
                         ((uint8*)rxSignalInfo->sigRTEValue)[sigLengthIndex - sigStartByte]  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                             = astPduInfo->datavalid[sigLengthIndex];
                    }
                    break;
                case COM_SIGTYPE_FLOAT32:
                    sigValue = Com_RxSigRead_Normal((const uint8*)(astPduInfo->datavalid), rxSignalInfo);
                    *(uint32*)rxSignalInfo->sigRTEValue = sigValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_FLOAT64:
                    sigValuelarge = Com_RxSigRead_Large_64((const uint8*)(astPduInfo->datavalid), rxSignalInfo);
                    *(uint64*)rxSignalInfo->sigRTEValue = sigValuelarge;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
#else  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                case COM_SIGTYPE_BOOLEAN:
                    sigValue = Com_RxSigRead_Normal((const uint8*)(astPduInfo->datavalid), rxSignalInfo);
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_Com_16.1" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    *(boolean*)rxSignalInfo->sigShadowValue = (boolean)sigValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_UINT8:
                    sigValue = Com_RxSigRead_Normal((const uint8*)(astPduInfo->datavalid), rxSignalInfo);
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    *(uint8*)rxSignalInfo->sigShadowValue = (uint8)sigValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_UINT16:
                    sigValue = Com_RxSigRead_Normal((const uint8*)(astPduInfo->datavalid), rxSignalInfo);
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    *(uint16*)rxSignalInfo->sigShadowValue = (uint16)sigValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_UINT32:
                    sigValue = Com_RxSigRead_Normal((const uint8*)(astPduInfo->datavalid), rxSignalInfo);
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    *(uint32*)rxSignalInfo->sigShadowValue = (uint32)sigValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_UINT64:
                    sigValuelarge = Com_RxSigRead_Large_64((const uint8*)(astPduInfo->datavalid), rxSignalInfo);
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    *(uint64*)rxSignalInfo->sigShadowValue = sigValuelarge;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_SINT8:
                    sigValue = Com_RxSigRead_Normal((const uint8*)(astPduInfo->datavalid), rxSignalInfo);

                    /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_Com_SHF" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" */
                    if( COM_OPERAND_ONE == (sigValue >> (bitSize - COM_OPERAND_ONE)) ) /* sigValue < 0. */
                    {
                        /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_Com_SHF" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" */
                        tempValue = (sigValue | ((uint32)COM_INIT_FF << bitSize));
                        receiveValueI8 = (sint8)((uint8)tempValue); /* high-order position complement 1 */
                    }
                    else
                    {
                        receiveValueI8 = (sint8)((uint8)sigValue);
                    }

                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    *(sint8*)rxSignalInfo->sigShadowValue = receiveValueI8;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_SINT16:
                    sigValue = Com_RxSigRead_Normal((const uint8*)(astPduInfo->datavalid), rxSignalInfo);

                    /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_Com_SHF" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" */
                    if( COM_OPERAND_ONE == (sigValue >> (bitSize - COM_OPERAND_ONE)) ) /* sigValue < 0 */
                    {
                        /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_Com_SHF" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" */
                        tempValue = (sigValue | ((uint32)COM_INIT_U16FF << bitSize));
                        receiveValueI16 = (sint16)((uint16)tempValue); /* high-order position complement 1 */
                    }
                    else
                    {
                        receiveValueI16 = (sint16)((uint16)sigValue);
                    }

                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    *(sint16*)rxSignalInfo->sigShadowValue = receiveValueI16;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_SINT32:
                    sigValue = Com_RxSigRead_Normal((const uint8*)(astPduInfo->datavalid), rxSignalInfo);

                    /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_Com_SHF" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" */
                    if( COM_OPERAND_ONE == (sigValue >> (bitSize - COM_OPERAND_ONE)) ) /* sigValue < 0 */
                    {
                        /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_Com_SHF" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" */
                        tempValue = (sigValue | ((uint32)COM_INIT_U32FF << bitSize));
                        receiveValueI32 = (sint32)tempValue; /* high-order position  complement 1 */
                    }
                    else
                    {
                        receiveValueI32 = (sint32)sigValue;
                    }

                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    *(sint32*)rxSignalInfo->sigShadowValue = receiveValueI32;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_SINT64:
                    sigValuelarge = Com_RxSigRead_Large_64((const uint8*)(astPduInfo->datavalid), rxSignalInfo);

                    /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_Com_SHF" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" */
                    if( COM_OPERAND_ONE == (sigValuelarge >> (bitSize - COM_OPERAND_ONE)) ) /* sigValue < 0 */
                    {
                        /* high-order position   complement 1 */
                        /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_Com_SHF" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:10.8 [Justified:Unset] "NSCA_Polyspace_Com_10.8" */
                        receiveValueI64 = (sint64)(sigValuelarge | (uint64)(COM_INIT_U64FF << bitSize));  /* PRQA S 4394*/ /* NSCA_QAC_Com_Rule10.8 */
                    }
                    else
                    {
                        receiveValueI64 = (sint64)sigValuelarge;
                    }

                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    *(sint64*)rxSignalInfo->sigShadowValue = receiveValueI64;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_UINT8_DYN:
                    dynSignalLength = rxSignalInfo->astSignalInterMonitor->acDynSignalLength;
                    /* Get start byte position of signal. */
                    sigStartByte = rxSignalInfo->sigBaseInfo->sigStartByte;

                    for( sigLengthIndex = sigStartByte;
                    sigLengthIndex < (sigStartByte + dynSignalLength); sigLengthIndex++ )
                    {
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        ((uint8*)rxSignalInfo->sigShadowValue)[sigLengthIndex - sigStartByte]  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                            = astPduInfo->datavalid[sigLengthIndex];
                    }
                    break;
                case COM_SIGTYPE_UINT8_N:
                    /* Get start byte position of signal. */
                    sigStartByte = rxSignalInfo->sigBaseInfo->sigStartByte;
                    for( sigLengthIndex = sigStartByte;
                    sigLengthIndex < (sigStartByte + (rxSignalInfo->sigBaseInfo->sigByteLength) ); sigLengthIndex++ )
                    {
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        ((uint8*)rxSignalInfo->sigShadowValue)[sigLengthIndex - sigStartByte]  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                            = astPduInfo->datavalid[sigLengthIndex];
                    }
                    break;
                case COM_SIGTYPE_FLOAT32:
                    sigValue = Com_RxSigRead_Normal((const uint8*)(astPduInfo->datavalid), rxSignalInfo);
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    *(uint32*)rxSignalInfo->sigShadowValue = sigValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_FLOAT64:
                    sigValuelarge = Com_RxSigRead_Large_64((const uint8*)(astPduInfo->datavalid), rxSignalInfo);
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    *(uint64*)rxSignalInfo->sigShadowValue = sigValuelarge;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                /* PolySpace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_Com_16.4" */
                default :
                    break;
            }
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
        }
    }
}

#if( COM_INVALIDACTION_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Com_RxInv_SigGrp
*
* Explanation: Com rx signal group invalid process.
*
* param: sigGrpIdx: Rx signal group index.
*
* retval: rtnValue: FALSE: normal value; TRUE: Exit invalid value.
********************************************************************************
*/
static FUNC(boolean, COM_CODE) Com_RxInv_SigGrp
(
    uint16 sigGrpIdx
)
{
    boolean rtnValue = FALSE;
    boolean invalidSta = FALSE;
    Com_SigType receiveSignalType;
    uint16 sigLengthIndex;
    uint16 byteCtn = COM_INIT_ZERO;
    uint16 byteLenth;
    uint16 grpSigIdx;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    uint16 grpSigStartIdx = Com_RxSigGrpInfo[sigGrpIdx].acSigIndStart;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    uint16 grpSigEndIdx = Com_RxSigGrpInfo[sigGrpIdx].acSigIndEnd;
    const COM_RxSignalInfo_st* rxSignalInfo = NULL_PTR;

    for( grpSigIdx = grpSigStartIdx; grpSigIdx < grpSigEndIdx; grpSigIdx++ )
    {
        rxSignalInfo = &Com_RxSignalInfo[grpSigIdx];
        if( (rxSignalInfo != NULL_PTR)
            && (COM_SIG_NO_GROUP_DEF != rxSignalInfo->acSigGrpIdx)
            && (NULL_PTR != rxSignalInfo->invalidValue) )
        {
            /* Obtain signal type. */
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
            receiveSignalType = Com_RxSignalInfo[grpSigIdx].acSigType;
#else  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
            receiveSignalType = Com_GetSignalType(rxSignalInfo->sigBaseInfo->sigFuncIdx);
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
            /* Judge signal type. */
            /* PolySpace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir16.1" */
            switch( receiveSignalType )
            {
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
                case COM_SIGTYPE_BOOLEAN:
                    if( (*(boolean*)rxSignalInfo->invalidValue)
                        == (*(boolean*)rxSignalInfo->sigRTEValue) )
                    {
                        invalidSta = TRUE;
                    }
                    break;
                case COM_SIGTYPE_UINT8:
                    if( (*(uint8*)rxSignalInfo->invalidValue)
                        == (*(uint8*)rxSignalInfo->sigRTEValue) )
                    {
                        invalidSta = TRUE;
                    }
                    break;
                case COM_SIGTYPE_UINT16:
                    if( (*(uint16*)rxSignalInfo->invalidValue)
                        == (*(uint16*)rxSignalInfo->sigRTEValue) )
                    {
                        invalidSta = TRUE;
                    }
                    break;
                case COM_SIGTYPE_UINT32:
                    if( (*(uint32*)rxSignalInfo->invalidValue)
                        == (*(uint32*)rxSignalInfo->sigRTEValue) )
                    {
                        invalidSta = TRUE;
                    }
                    break;
                case COM_SIGTYPE_UINT64:
                    if( (*(uint64*)rxSignalInfo->invalidValue)
                        == (*(uint64*)rxSignalInfo->sigRTEValue) )
                    {
                        invalidSta = TRUE;
                    }
                    break;
                    case COM_SIGTYPE_SINT8:
                    if( (*(sint8*)rxSignalInfo->invalidValue)
                        == (*(sint8*)rxSignalInfo->sigRTEValue) )
                    {
                        invalidSta = TRUE;
                    }
                    break;
                case COM_SIGTYPE_SINT16:
                    if( (*(sint16*)rxSignalInfo->invalidValue)
                        == (*(sint16*)rxSignalInfo->sigRTEValue) )
                    {
                        invalidSta = TRUE;
                    }
                    break;
                case COM_SIGTYPE_SINT32:
                    if( (*(sint32*)rxSignalInfo->invalidValue)
                        == (*(sint32*)rxSignalInfo->sigRTEValue) )
                    {
                        invalidSta = TRUE;
                    }
                    break;
                case COM_SIGTYPE_SINT64:
                    if( (*(sint64*)rxSignalInfo->invalidValue)
                        == (*(sint64*)rxSignalInfo->sigRTEValue) )
                    {
                        invalidSta = TRUE;
                    }
                    break;
                case COM_SIGTYPE_UINT8_DYN:
                    byteLenth = rxSignalInfo->astSignalInterMonitor->acDynSignalLength;
                    for( sigLengthIndex = COM_INIT_ZERO;
                     sigLengthIndex < byteLenth; sigLengthIndex++ )
                    {
                        if( ((uint8*)rxSignalInfo->invalidValue)[sigLengthIndex]
                            == ((uint8*)rxSignalInfo->sigRTEValue)[sigLengthIndex] )
                        {
                            byteCtn++;
                        }
                    }

                    if( byteCtn == byteLenth )
                    {
                        byteCtn = COM_INIT_ZERO;   /* Clear counter. */
                        invalidSta = TRUE;
                    }

                    break;
                case COM_SIGTYPE_UINT8_N:
                    /* Get byte length of UINT8_N signal. */
                    byteLenth = rxSignalInfo->sigBaseInfo->sigByteLength;
                    for( sigLengthIndex = COM_INIT_ZERO;
                     sigLengthIndex < byteLenth; sigLengthIndex++ )
                    {
                        if( ((uint8*)rxSignalInfo->invalidValue)[sigLengthIndex]
                            == ((uint8*)rxSignalInfo->sigRTEValue)[sigLengthIndex] )
                        {
                            byteCtn++;
                        }
                    }

                    if( byteCtn == byteLenth )
                    {
                        byteCtn = COM_INIT_ZERO;   /* Clear counter. */
                        invalidSta = TRUE;
                    }
                    break;
                case COM_SIGTYPE_FLOAT32:
                    if( TRUE == Com_CompareFloat32Values((*(float32*)rxSignalInfo->invalidValue),(*(float32*)rxSignalInfo->sigRTEValue)) )
                    {
                        invalidSta = TRUE;
                    }
                    break;
                case COM_SIGTYPE_FLOAT64:
                    if( TRUE == Com_CompareFloat64Values((*(float64*)rxSignalInfo->invalidValue),(*(float64*)rxSignalInfo->sigRTEValue)) )
                    {
                        invalidSta = TRUE;
                    }
                    break;
#else  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                case COM_SIGTYPE_BOOLEAN:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                    if( (*(boolean*)rxSignalInfo->invalidValue)
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        == (*(boolean*)rxSignalInfo->sigShadowValue) )
                    {
                        invalidSta = TRUE;
                    }
                    break;
                case COM_SIGTYPE_UINT8:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                    if( (*(uint8*)rxSignalInfo->invalidValue)
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        == (*(uint8*)rxSignalInfo->sigShadowValue) )
                    {
                        invalidSta = TRUE;
                    }
                    break;
                case COM_SIGTYPE_UINT16:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    if( (*(uint16*)rxSignalInfo->invalidValue)
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        == (*(uint16*)rxSignalInfo->sigShadowValue) )
                    {
                        invalidSta = TRUE;
                    }
                    break;
                case COM_SIGTYPE_UINT32:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    if( (*(uint32*)rxSignalInfo->invalidValue)
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        == (*(uint32*)rxSignalInfo->sigShadowValue) )
                    {
                        invalidSta = TRUE;
                    }
                    break;
                case COM_SIGTYPE_UINT64:
                    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    if( (*(uint64*)rxSignalInfo->invalidValue)
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                        == (*(uint64*)rxSignalInfo->sigShadowValue) )
                    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                    {
                        invalidSta = TRUE;
                    }
                    break;
                case COM_SIGTYPE_SINT8:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                    if( (*(sint8*)rxSignalInfo->invalidValue)
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        == (*(sint8*)rxSignalInfo->sigShadowValue) )
                    {
                        invalidSta = TRUE;
                    }
                    break;
                case COM_SIGTYPE_SINT16:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    if( (*(sint16*)rxSignalInfo->invalidValue)
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        == (*(sint16*)rxSignalInfo->sigShadowValue) )
                    {
                        invalidSta = TRUE;
                    }
                    break;
                case COM_SIGTYPE_SINT32:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    if( (*(sint32*)rxSignalInfo->invalidValue)
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        == (*(sint32*)rxSignalInfo->sigShadowValue) )
                    {
                        invalidSta = TRUE;
                    }
                    break;
                case COM_SIGTYPE_SINT64:
                    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    if( (*(sint64*)rxSignalInfo->invalidValue)
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                        == (*(sint64*)rxSignalInfo->sigShadowValue) )
                    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                    {
                        invalidSta = TRUE;
                    }
                    break;
                case COM_SIGTYPE_UINT8_DYN:
                    byteLenth = rxSignalInfo->astSignalInterMonitor->acDynSignalLength;
                    for( sigLengthIndex = COM_INIT_ZERO;
                    sigLengthIndex < byteLenth; sigLengthIndex++ )
                    {
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        if( ((uint8*)rxSignalInfo->invalidValue)[sigLengthIndex]
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                            == ((uint8*)rxSignalInfo->sigShadowValue)[sigLengthIndex] )
                        {
                            byteCtn++;
                        }
                    }

                    if( byteCtn == byteLenth )
                    {
                        byteCtn = COM_INIT_ZERO;   /* Clear counter. */
                        invalidSta = TRUE;
                    }

                    break;
                case COM_SIGTYPE_UINT8_N:
                    /* Get byte length of UINT8_N signal. */
                    byteLenth = rxSignalInfo->sigBaseInfo->sigByteLength;
                    for( sigLengthIndex = COM_INIT_ZERO;
                    sigLengthIndex < byteLenth; sigLengthIndex++ )
                    {
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        if( ((uint8*)rxSignalInfo->invalidValue)[sigLengthIndex]
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                            == ((uint8*)rxSignalInfo->sigShadowValue)[sigLengthIndex] )
                        {
                            byteCtn++;
                        }
                    }

                    if( byteCtn == byteLenth )
                    {
                        byteCtn = COM_INIT_ZERO;   /* Clear counter. */
                        invalidSta = TRUE;
                    }
                    break;
                case COM_SIGTYPE_FLOAT32:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    if( TRUE == Com_CompareFloat32Values((*(float32*)rxSignalInfo->invalidValue),(*(float32*)rxSignalInfo->sigShadowValue)) )
                    {
                        invalidSta = TRUE;
                    }
                    break;
                case COM_SIGTYPE_FLOAT64:
                    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    if( TRUE == Com_CompareFloat64Values((*(float64*)rxSignalInfo->invalidValue),(*(float64*)rxSignalInfo->sigShadowValue)) )
                    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                    {
                        invalidSta = TRUE;
                    }
                    break;
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                default :
                    /* PolySpace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_Com_16.4" */
                    break;
            }

            if( TRUE == invalidSta )
            {
                break;
            }
        }
    }

    if( TRUE == invalidSta )
    {
        if( COM_SIGNAL_INVALID_NOTIFY == Com_RxSigGrpInfo[sigGrpIdx].acDataInvalidAction )
        {
#if( COM_RXSIGGRP_INVALIDNOTIFICATION_SUPPORT == STD_ON )
            /* Invalid notifity. */
            if( NULL_PTR != Com_RxSigGrpInfo[sigGrpIdx].InvalidNotification_p )
            {
                Com_RxSigGrpInfo[sigGrpIdx].InvalidNotification_p();
            }
#endif  /* COM_RXSIGGRP_INVALIDNOTIFICATION_SUPPORT == STD_ON */
            rtnValue = TRUE;
        }
        else if( COM_SIGNAL_INVALID_REPLACE == Com_RxSigGrpInfo[sigGrpIdx].acDataInvalidAction )
        {
            for( grpSigIdx = grpSigStartIdx; grpSigIdx < grpSigEndIdx; grpSigIdx++ )
            {
                Com_SigGrp_InvReplace(grpSigIdx);
            }
        }
        else
        {
            /* Do nothing. */
        }
    }

    return rtnValue;
}
#endif  /* COM_INVALIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )
/*
********************************************************************************
* Function Name: Com_RxProcessing_RxSignalGroupFilterChk
*
* Explanation: Com rx signal group filter process.
*
* param: sigGrpIdx: Rx signal group index.
*
* retval: None
********************************************************************************
*/

static FUNC(boolean, COM_CODE) Com_RxProcessing_RxSignalGroupFilterChk
(
    uint16 sigGrpIdx
)
{
    boolean filterSta = FALSE;
    boolean rtnValue = TRUE;
    Com_SigType receiveSignalType;
    uint16 grpSigIdx;
    uint16 grpSigStartIdx = Com_RxSigGrpInfo[sigGrpIdx].acSigIndStart;
    uint16 grpSigEndIdx = Com_RxSigGrpInfo[sigGrpIdx].acSigIndEnd;
    const COM_RxSignalInfo_st* rxSignalInfo = NULL_PTR;

    for( grpSigIdx = grpSigStartIdx; grpSigIdx < grpSigEndIdx; grpSigIdx++ )
    {
        rxSignalInfo = &Com_RxSignalInfo[grpSigIdx];
        if( (rxSignalInfo != NULL_PTR)
            && (COM_SIG_NO_GROUP_DEF != rxSignalInfo->acSigGrpIdx)
            && (NULL_PTR != rxSignalInfo->signalFilterMonitor) )
        {
            /* Obtain signal type. */
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
            receiveSignalType = rxSignalInfo.acSigType;
#else  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
            receiveSignalType = Com_GetSignalType(rxSignalInfo->sigBaseInfo->sigFuncIdx);
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
            /* Judge signal type. */
            switch( receiveSignalType )
            {
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
                case COM_SIGTYPE_BOOLEAN:
                    filterSta = Com_Signal_Boolean_EvaluateFilter((*(boolean*)rxSignalInfo->sigRTEValue), grpSigIdx);
                    break;
                case COM_SIGTYPE_UINT8:
                    filterSta = Com_Signal_uint8_EvaluateFilter((*(uint8*)rxSignalInfo->sigRTEValue), grpSigIdx);
                    break;
                case COM_SIGTYPE_UINT16:
                    filterSta = Com_Signal_uint16_EvaluateFilter((*(uint16*)rxSignalInfo->sigRTEValue), grpSigIdx);
                    break;
                case COM_SIGTYPE_UINT32:
                    filterSta = Com_Signal_uint32_EvaluateFilter((*(uint32*)rxSignalInfo->sigRTEValue), grpSigIdx);
                    break;
                case COM_SIGTYPE_UINT64:
                    filterSta = Com_Signal_uint64_EvaluateFilter((*(uint64*)rxSignalInfo->sigRTEValue), grpSigIdx);
                    break;
                case COM_SIGTYPE_SINT8:
                    filterSta = Com_Signal_sint8_EvaluateFilter((*(sint8*)rxSignalInfo->sigRTEValue), grpSigIdx);
                    break;
                case COM_SIGTYPE_SINT16:
                    filterSta = Com_Signal_sint16_EvaluateFilter((*(sint16*)rxSignalInfo->sigRTEValue), grpSigIdx);
                    break;
                case COM_SIGTYPE_SINT32:
                    filterSta = Com_Signal_sint32_EvaluateFilter((*(sint32*)rxSignalInfo->sigRTEValue), grpSigIdx);
                    break;
                case COM_SIGTYPE_SINT64:
                    filterSta = Com_Signal_sint64_EvaluateFilter((*(sint64*)rxSignalInfo->sigRTEValue), grpSigIdx);
                    break;
                case COM_SIGTYPE_UINT8_DYN:
                case COM_SIGTYPE_UINT8_N:
                case COM_SIGTYPE_FLOAT32:
                case COM_SIGTYPE_FLOAT64:
                    if( COM_FILTER_ALWAYS
                        == rxSignalInfo->signalFilterMonitor->acFilterAlgorithm )
                    {
                        filterSta = TRUE;
                    }
                    else if( COM_FILTER_NEVER
                        == rxSignalInfo->signalFilterMonitor->acFilterAlgorithm )
                    {
                        filterSta = FALSE;
                    }
                    else
                    {
                        /* Do nothing. */
                    }
                    break;
#else  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                case COM_SIGTYPE_BOOLEAN:
                    filterSta = Com_Signal_Boolean_EvaluateFilter((*(boolean*)rxSignalInfo->sigShadowValue), grpSigIdx);
                    break;
                case COM_SIGTYPE_UINT8:
                    filterSta = Com_Signal_uint8_EvaluateFilter((*(uint8*)rxSignalInfo->sigShadowValue), grpSigIdx);
                    break;
                case COM_SIGTYPE_UINT16:
                    filterSta = Com_Signal_uint16_EvaluateFilter((*(uint16*)rxSignalInfo->sigShadowValue), grpSigIdx);
                    break;
                case COM_SIGTYPE_UINT32:
                    filterSta = Com_Signal_uint32_EvaluateFilter((*(uint32*)rxSignalInfo->sigShadowValue), grpSigIdx);
                    break;
                case COM_SIGTYPE_UINT64:
                    filterSta = Com_Signal_uint64_EvaluateFilter((*(uint64*)rxSignalInfo->sigShadowValue), grpSigIdx);
                    break;
                case COM_SIGTYPE_SINT8:
                    filterSta = Com_Signal_sint8_EvaluateFilter((*(sint8*)rxSignalInfo->sigShadowValue), grpSigIdx);
                    break;
                case COM_SIGTYPE_SINT16:
                    filterSta = Com_Signal_sint16_EvaluateFilter((*(sint16*)rxSignalInfo->sigShadowValue), grpSigIdx);
                    break;
                case COM_SIGTYPE_SINT32:
                    filterSta = Com_Signal_sint32_EvaluateFilter((*(sint32*)rxSignalInfo->sigShadowValue), grpSigIdx);
                    break;
                case COM_SIGTYPE_SINT64:
                    filterSta = Com_Signal_sint64_EvaluateFilter((*(sint64*)rxSignalInfo->sigShadowValue), grpSigIdx);
                    break;
                case COM_SIGTYPE_UINT8_DYN:
                case COM_SIGTYPE_UINT8_N:
                case COM_SIGTYPE_FLOAT32:
                case COM_SIGTYPE_FLOAT64:
                    if( COM_FILTER_ALWAYS
                        == rxSignalInfo->signalFilterMonitor->acFilterAlgorithm )
                    {
                        filterSta = TRUE;
                    }
                    else if( COM_FILTER_NEVER
                        == rxSignalInfo->signalFilterMonitor->acFilterAlgorithm )
                    {
                        filterSta = FALSE;
                    }
                    else
                    {
                        /* Do nothing. */
                    }
                    break;
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                default :
                    break;
            }
        }

        if( FALSE == filterSta )
        {
            rtnValue = FALSE;
            break;
        }
    }

    return rtnValue;
}
#endif  /* COM_RXSIGFILTERINFO == STD_ON */

#endif  /* COM_RXSIGGROUPINFO == STD_ON */

/*
********************************************************************************
* Function Name: Com_ActivateRxComIPdus
*
* Explanation: Activate Rx Pdus.
*
* param: void
*
* retval: void
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_ActivateRxComIPdus(void)
{
    uint16 pduIndex;
    const COM_RxPduInfo_st* com_astPdu = Com_RxPduInfo;

    /* Poll all pdu's. */
    for( pduIndex = COM_INIT_ZERO; pduIndex < COM_RXPDU_NUM; pduIndex++ )
    {
        /* Pdu Active Type is always. */
        if( COM_PDU_TYPE_ACTIVE_ALWAYS == com_astPdu->acPduActiveType )
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        {
            /* check NULL_PTR. */
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            if( NULL_PTR != com_astPdu->astPduInterMonitor )
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                /* Set Pdu state is ACTIVE. */
                com_astPdu->astPduInterMonitor->pduSta = COM_PDU_ACTIVE;
            }
        }
        else
        {
            /* check NULL_PTR. */
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            if( NULL_PTR != com_astPdu->astPduInterMonitor )
            {
                /* Set Pdu state is INACTIVE. */
                com_astPdu->astPduInterMonitor->pduSta = COM_PDU_INACTIVE;
            }
        }
        com_astPdu++;
    }
}

/*
********************************************************************************
* Function Name: Com_ActivateTxComIPdus
*
* Explanation: Activate Tx Pdus.
*
* param: void
*
* retval: void
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_ActivateTxComIPdus(void)
{
    uint16 pduIndex;
    const COM_TxPduInfo_st* com_astPdu = Com_TxPduInfo;

    /* Poll all pdu's. */
    for( pduIndex = COM_INIT_ZERO; pduIndex < COM_TXPDU_NUM; pduIndex++ )
    {
        /* Pdu Active Type is not in any pdu group. */
        if( COM_PDU_TYPE_ACTIVE_ALWAYS == com_astPdu->acPduActiveType )
        {
            /* check NULL_PTR. */
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            if( NULL_PTR != com_astPdu->astPduInterMonitor )
            {
                /* Set Pdu state is ACTIVE. */
                com_astPdu->astPduInterMonitor->pduSta = COM_PDU_STA_ACTIVE;
            }
        }
        else
        {
            /* check NULL_PTR. */
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            if( NULL_PTR != com_astPdu->astPduInterMonitor )
            {
                /* Set Pdu state is INACTIVE. */
                com_astPdu->astPduInterMonitor->pduSta = COM_PDU_STA_INACTIVE;
            }
        }
        com_astPdu++;
    }
}

/*
********************************************************************************
* Function Name: Com_PointerNullPtr_judge
*
* Explanation: Configuration item judgment.
*
* param: None
*
* retval: errorId: exist error.
********************************************************************************
*/
static FUNC(uint8, COM_CODE) Com_PointerNullPtr_judge(void)
{
    uint8 errorId = COM_E_NO_ERROR;
    uint16 index;

    /* Rx signal judge. */
    for( index = COM_INIT_ZERO; index < COM_RXSIG_NUM; index++ )
    {
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        if( (NULL_PTR != Com_RxSignalInfo[index].sigRTEValue)
            && (NULL_PTR != Com_RxSignalInfo[index].astSignalInterMonitor) )
        {
            /* Rte, shadow. */
            if( COM_SIG_NO_GROUP_DEF != Com_RxSignalInfo[index].acSigGrpIdx )
            {
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
                if( NULL_PTR == Com_RxSignalInfo[index].sigRTEValue )
                {
                    errorId = COM_E_PARAM_POINTER;
                }
#else  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                if( NULL_PTR == Com_RxSignalInfo[index].sigShadowValue )
                {
                    errorId = COM_E_PARAM_POINTER;
                }
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
            }
        }
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
        /* Updatebit counter. */
        if( COM_SIG_NO_UPDATEBIT_DEF != Com_RxSignalInfo[index].updateBitPosition )
        {
            if( NULL_PTR == Com_RxSignalInfo[index].updateCnt )
            {
                errorId = COM_E_PARAM_POINTER;
            }
        }
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */
        /* Init value. */
        if( NULL_PTR == Com_RxSignalInfo[index].initvalue )
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        {
            errorId = COM_E_PARAM_POINTER;
        }

        if( COM_E_PARAM_POINTER == errorId )
        {
            break;
        }
    }
    /* Tx signal judge. */
    if( errorId != COM_E_PARAM_POINTER )
    {
        for( index = COM_INIT_ZERO; index < COM_TXSIG_NUM; index++ )
        {
            if( (NULL_PTR == Com_TxSignalInfo[index].sigValShadowBufPtr)
                || (NULL_PTR == Com_TxSignalInfo[index].sigSendSta)
                || (NULL_PTR == Com_TxSignalInfo[index].sigInitValue) )
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                errorId = COM_E_PARAM_POINTER;
                break;
            }
        }
    }

    /* Rx pdu judge. */
    if( errorId != COM_E_PARAM_POINTER )
    {
        for( index = COM_INIT_ZERO; index < COM_RXPDU_NUM; index++ )
        {
            if( (NULL_PTR == Com_RxPduInfo[index].astPduInterMonitor)
                || (NULL_PTR == Com_RxPduInfo[index].datavalid) )
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                errorId = COM_E_PARAM_POINTER;
            }
            if( COM_PDU_TYPE_TP == Com_RxPduInfo[index].acPduType )
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                if( NULL_PTR == Com_RxPduInfo[index].pduTpMonitor )
                /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                {
                    errorId = COM_E_PARAM_POINTER;
                }
            }
            if( COM_E_PARAM_POINTER == errorId )
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                break;
            }
        }
    }
    /* Tx pdu judge. */
    if( errorId != COM_E_PARAM_POINTER )
    {
        for( index = COM_INIT_ZERO; index < COM_TXPDU_NUM; index++ )
        {
            if( (NULL_PTR == Com_TxPduInfo[index].astPduInterMonitor)
                || (NULL_PTR == Com_TxPduInfo[index].dataRaw) )
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                errorId = COM_E_PARAM_POINTER;
                break;
            }
        }
    }

    return errorId;
}

/*
********************************************************************************
* Function Name: Com_DeActivateRxComIPdus
*
* Explanation: DeActive Rx Pdus.
*
* param: void
*
* retval: void
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_DeActivateRxComIPdus(void)
{
    uint16 pduIndex;
    const COM_RxPduInfo_st* com_astPdu = Com_RxPduInfo;

    /* Poll all pdu's. */
    for( pduIndex = COM_INIT_ZERO; pduIndex < COM_RXPDU_NUM; pduIndex++ )
    {
        /* check NULL_PTR. */
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        if( NULL_PTR != com_astPdu->astPduInterMonitor )
        {
            /* Set Pdu state is COM_PDU_INACTIVE. */
            com_astPdu->astPduInterMonitor->pduSta = COM_PDU_INACTIVE;
        }
        com_astPdu++;
    }
}

/*
********************************************************************************
* Function Name: Com_DeActivateTxComIPdus
*
* Explanation: DeActivate Tx Pdus.
*
* param: void
*
* retval: void
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_DeActivateTxComIPdus(void)
{
    uint16 pduIndex;
    const COM_TxPduInfo_st* com_astPdu = Com_TxPduInfo;

    /* Poll all pdu's. */
    for( pduIndex = COM_INIT_ZERO; pduIndex < COM_TXPDU_NUM; pduIndex++ )
    {
        /* check NULL_PTR. */
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        if( NULL_PTR != com_astPdu->astPduInterMonitor )
        {
            /* Set Pdu state is COM_PDU_STA_INACTIVE. */
            com_astPdu->astPduInterMonitor->pduSta = COM_PDU_STA_INACTIVE;
        }
        com_astPdu++;
    }
}

/*
********************************************************************************
* Function Name: Com_RxDynSignalLengthEvlateProcess
*
* Explanation: Judge Received Dyn Signal Length.
*
* param: RxPduId: Rx Pdu Id.
*
* retval: void
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxDynSignalLengthEvlateProcess
(
    uint16 sigIdx
)
{
    uint16 pduRecLength;
    uint16 sigByteLen;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    uint16 RxPduId = Com_RxSignalInfo[sigIdx].acPduID;

    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    if( NULL_PTR != Com_RxSignalInfo[sigIdx].astSignalInterMonitor )
    {
        pduRecLength = Com_RxPduInfo[RxPduId].astPduInterMonitor->acPduLength;
        /* Get byte length of signal. */
        sigByteLen = Com_RxSignalInfo[sigIdx].sigBaseInfo->sigByteLength;

        /* Determine whether the real length is less than the configured length. */
        if( pduRecLength < sigByteLen )
        {
            /* Length error. */
            Com_RxSignalInfo[sigIdx].astSignalInterMonitor->acDynSignalLength = COM_INIT_ZERO;
        }
        else
        {
            /* <dynamic signal length in bytes> = <received I-PDU length in bytes> - <ComBitPosition of dynamic length signal> / 8. */
            Com_RxSignalInfo[sigIdx].astSignalInterMonitor->acDynSignalLength = sigByteLen;
        }
    }
}

/*
********************************************************************************
* Function Name: Com_Memcpy
*
* Explanation: Com Memcpy Function.
*
* param: acpDest: Dest Ptr.
*        acpSrc: Source Ptr.
*        awCnt: Byte Counter.
* retval: void
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_Memcpy
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) acpDest,
    P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) acpSrc,
    uint16 awCnt
)
{
    uint8 errorFlag = FALSE;

    /* Judge Null Pointer. */
    if( (NULL_PTR == acpDest) || (NULL_PTR == acpSrc) || (COM_INIT_ZERO == awCnt) )
    {
        /* Parameter error. */
        errorFlag = TRUE;
    }

    if( (uint8)TRUE != errorFlag )
    {
        /* Determine the length of the copy. */
        while( awCnt > COM_INIT_ZERO )
        {
            /* PolySpace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
            awCnt--;
            /* Data assignment. */
            /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            acpDest[awCnt] = acpSrc[awCnt];
        }
    }

    return;
}

/*
********************************************************************************
* Function Name: Com_InitRxBuffer
*
* Explanation: Init Rx Buffer.
*
* param: PduInfo: Rx Pdu Info.
*
* retval: void
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_InitRxBuffer
(
    P2CONST(COM_RxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
)
{
    Com_SigType receiveSignalType;
    uint16 sigGrpRef;
    uint16 sigIdx;
    uint16 aryLength;
    uint16 byteIdx;
    const COM_RxSignalInfo_st* rxSigInfo = Com_RxSignalInfo;

    /* Polling signals in message. */
    for( sigIdx = PduInfo->awSigStartIndex; sigIdx < PduInfo->awSigEndIndex; sigIdx++ )
    {
        rxSigInfo = &Com_RxSignalInfo[sigIdx];

        sigGrpRef = rxSigInfo->acSigGrpIdx;

        /* Obtain signal type. */
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
        receiveSignalType = Com_RxSignalInfo[sigIdx].acSigType;
#else  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
        receiveSignalType = Com_GetSignalType(rxSigInfo->sigBaseInfo->sigFuncIdx);
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
        /* Judge signal type. */
        /* PolySpace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_Com_16.1" */
        switch( receiveSignalType )
        {
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
            case COM_SIGTYPE_BOOLEAN:
                /* Assign value to RTE from init value. */
                Com_SIGNAL_INITREPLACE(boolean,rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                /* Determine whether the signal group type. */
                if( (COM_SIG_NO_GROUP_DEF != sigGrpRef)
                    && (NULL_PTR != rxSigInfo->sigRTEValue) )
                {
                    Com_SIGNAL_INITREPLACESHADOW(boolean,rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                }
                break;
            case COM_SIGTYPE_UINT8:
                Com_SIGNAL_INITREPLACE(uint8, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                if( (COM_SIG_NO_GROUP_DEF != sigGrpRef)
                    && (NULL_PTR != rxSigInfo->sigRTEValue) )
                {
                    Com_SIGNAL_INITREPLACESHADOW(uint8, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                }
                break;
            case COM_SIGTYPE_UINT16:
                Com_SIGNAL_INITREPLACE(uint16, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                if( (COM_SIG_NO_GROUP_DEF != sigGrpRef)
                    && (NULL_PTR != rxSigInfo->sigRTEValue) )
                {
                    Com_SIGNAL_INITREPLACESHADOW(uint16, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                }
                break;
            case COM_SIGTYPE_UINT32:
                Com_SIGNAL_INITREPLACE(uint32, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                if( (COM_SIG_NO_GROUP_DEF != sigGrpRef)
                    && (NULL_PTR != rxSigInfo->sigRTEValue) )
                {
                    Com_SIGNAL_INITREPLACESHADOW(uint32, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                }
                break;
            case COM_SIGTYPE_UINT64:
                Com_SIGNAL_INITREPLACE(uint64, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                if( (COM_SIG_NO_GROUP_DEF != sigGrpRef)
                    && (NULL_PTR != rxSigInfo->sigRTEValue) )
                {
                    Com_SIGNAL_INITREPLACESHADOW(uint64, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                }
                break;
            case COM_SIGTYPE_SINT8:
                /* Assign value to RTE from init value. */
                Com_SIGNAL_INITREPLACE(sint8, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

                /* Determine whether the signal group type. */
                if( (COM_SIG_NO_GROUP_DEF != sigGrpRef)
                    && (NULL_PTR != rxSigInfo->sigRTEValue) )
                {
                    /* Assign an initial value to the buffer. */
                    Com_SIGNAL_INITREPLACESHADOW(sint8, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                }
                break;
            case COM_SIGTYPE_SINT16:
                Com_SIGNAL_INITREPLACE(sint16, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                if( (COM_SIG_NO_GROUP_DEF != sigGrpRef)
                    && (NULL_PTR != rxSigInfo->sigRTEValue) )
                {
                    Com_SIGNAL_INITREPLACESHADOW(sint16, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                }
                break;
            case COM_SIGTYPE_SINT32:
                Com_SIGNAL_INITREPLACE(sint32, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                if( (COM_SIG_NO_GROUP_DEF != sigGrpRef)
                    && (NULL_PTR != rxSigInfo->sigRTEValue) )
                {
                    Com_SIGNAL_INITREPLACESHADOW(sint32, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                }
                break;
            case COM_SIGTYPE_SINT64:
                Com_SIGNAL_INITREPLACE(sint64, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                if( (COM_SIG_NO_GROUP_DEF != sigGrpRef)
                    && (NULL_PTR != rxSigInfo->sigRTEValue) )
                {
                    Com_SIGNAL_INITREPLACESHADOW(sint64, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                }
                break;
            case COM_SIGTYPE_UINT8_DYN:
                /* Get ary length. */
                aryLength = Com_RxSignalInfo[sigIdx].astSignalInterMonitor->acDynSignalLength;

                for( byteIdx = COM_INIT_ZERO; byteIdx < aryLength; byteIdx++ )
                {
                    ((uint8*)rxSigInfo->sigRTEValue)[byteIdx] = ((uint8*)rxSigInfo->initvalue)[byteIdx];  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

                    if( COM_SIG_NO_GROUP_DEF != sigGrpRef )
                    {
                        ((uint8*)rxSigInfo->sigRTEValue)[byteIdx] = ((uint8*)rxSigInfo->initvalue)[byteIdx];  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    }
                }
                break;
            case COM_SIGTYPE_UINT8_N:
                /* Get ary length */
                aryLength = Com_RxSignalInfo[sigIdx].sigBaseInfo->sigByteLength;

                for( byteIdx = COM_INIT_ZERO; byteIdx < aryLength; byteIdx++ )
                {
                    ((uint8*)rxSigInfo->sigRTEValue)[byteIdx] = ((uint8*)rxSigInfo->initvalue)[byteIdx];  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

                    if( COM_SIG_NO_GROUP_DEF != sigGrpRef )
                    {
                        ((uint8*)rxSigInfo->sigRTEValue)[byteIdx] = ((uint8*)rxSigInfo->initvalue)[byteIdx];  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    }
                }
                break;
            case COM_SIGTYPE_FLOAT32:
                Com_SIGNAL_INITREPLACE(uint32,rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                if( (COM_SIG_NO_GROUP_DEF != sigGrpRef)
                    && (NULL_PTR != rxSigInfo->sigRTEValue) )
                {
                    Com_SIGNAL_INITREPLACESHADOW(uint32,rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                }
                break;
            case COM_SIGTYPE_FLOAT64:
                Com_SIGNAL_INITREPLACE(uint64,rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                if( (COM_SIG_NO_GROUP_DEF != sigGrpRef)
                    && (NULL_PTR != rxSigInfo->sigRTEValue) )
                {
                    Com_SIGNAL_INITREPLACESHADOW(uint64,rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                }
                break;
#else  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
            case COM_SIGTYPE_BOOLEAN:
                /* Assign value to RTE from init value. */
                Com_SIGNAL_INITREPLACE(boolean,rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                /* Determine whether the signal group type. */
                if( (COM_SIG_NO_GROUP_DEF != sigGrpRef)
                    && (NULL_PTR != rxSigInfo->sigShadowValue) )
                {
                    Com_SIGNAL_INITREPLACESHADOW(boolean,rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                }
                break;
            case COM_SIGTYPE_UINT8:
                Com_SIGNAL_INITREPLACE(uint8, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                if( (COM_SIG_NO_GROUP_DEF != sigGrpRef)
                    && (NULL_PTR != rxSigInfo->sigShadowValue) )
                {
                    Com_SIGNAL_INITREPLACESHADOW(uint8, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                }
                break;
            case COM_SIGTYPE_UINT16:
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                Com_SIGNAL_INITREPLACE(uint16, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                if( (COM_SIG_NO_GROUP_DEF != sigGrpRef)
                    && (NULL_PTR != rxSigInfo->sigShadowValue) )
                {
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNAL_INITREPLACESHADOW(uint16, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                }
                break;
            case COM_SIGTYPE_UINT32:
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                Com_SIGNAL_INITREPLACE(uint32, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                if( (COM_SIG_NO_GROUP_DEF != sigGrpRef)
                    && (NULL_PTR != rxSigInfo->sigShadowValue) )
                {
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNAL_INITREPLACESHADOW(uint32, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                }
                break;
            case COM_SIGTYPE_UINT64:
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                Com_SIGNAL_INITREPLACE(uint64, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                if( (COM_SIG_NO_GROUP_DEF != sigGrpRef)
                    && (NULL_PTR != rxSigInfo->sigShadowValue) )
                {
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNAL_INITREPLACESHADOW(uint64, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                }
                break;
            case COM_SIGTYPE_SINT8:
                /* Assign value to RTE from init value. */
                Com_SIGNAL_INITREPLACE(sint8, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

                /* Determine whether the signal group type. */
                if( (COM_SIG_NO_GROUP_DEF != sigGrpRef)
                    && (NULL_PTR != rxSigInfo->sigShadowValue) )
                {
                    /* Assign an initial value to the buffer. */
                    Com_SIGNAL_INITREPLACESHADOW(sint8, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                }
                break;
            case COM_SIGTYPE_SINT16:
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                Com_SIGNAL_INITREPLACE(sint16, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                if( (COM_SIG_NO_GROUP_DEF != sigGrpRef)
                    && (NULL_PTR != rxSigInfo->sigShadowValue) )
                {
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNAL_INITREPLACESHADOW(sint16, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                }
                break;
            case COM_SIGTYPE_SINT32:
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                Com_SIGNAL_INITREPLACE(sint32, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                if( (COM_SIG_NO_GROUP_DEF != sigGrpRef)
                    && (NULL_PTR != rxSigInfo->sigShadowValue) )
                {
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNAL_INITREPLACESHADOW(sint32, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                }
                break;
            case COM_SIGTYPE_SINT64:
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                Com_SIGNAL_INITREPLACE(sint64, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                if( (COM_SIG_NO_GROUP_DEF != sigGrpRef)
                    && (NULL_PTR != rxSigInfo->sigShadowValue) )
                {
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNAL_INITREPLACESHADOW(sint64, rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                }
                break;
            case COM_SIGTYPE_UINT8_DYN:
                /* Get ary length. */
                aryLength = Com_RxSignalInfo[sigIdx].astSignalInterMonitor->acDynSignalLength;

                for( byteIdx = COM_INIT_ZERO; byteIdx < aryLength; byteIdx++ )
                {
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    ((uint8*)rxSigInfo->sigRTEValue)[byteIdx] = ((uint8*)rxSigInfo->initvalue)[byteIdx];  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

                    if( COM_SIG_NO_GROUP_DEF != sigGrpRef )
                    {
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        ((uint8*)rxSigInfo->sigShadowValue)[byteIdx] = ((uint8*)rxSigInfo->initvalue)[byteIdx];  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    }
                }
                break;
            case COM_SIGTYPE_UINT8_N:
                /* Get ary length */
                aryLength = Com_RxSignalInfo[sigIdx].sigBaseInfo->sigByteLength;

                for( byteIdx = COM_INIT_ZERO; byteIdx < aryLength; byteIdx++ )
                {
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    ((uint8*)rxSigInfo->sigRTEValue)[byteIdx] = ((uint8*)rxSigInfo->initvalue)[byteIdx];  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

                    if( COM_SIG_NO_GROUP_DEF != sigGrpRef )
                    {
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        ((uint8*)rxSigInfo->sigShadowValue)[byteIdx] = ((uint8*)rxSigInfo->initvalue)[byteIdx];  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    }
                }
                break;
            case COM_SIGTYPE_FLOAT32:
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                Com_SIGNAL_INITREPLACE(uint32,rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                if( (COM_SIG_NO_GROUP_DEF != sigGrpRef)
                    && (NULL_PTR != rxSigInfo->sigShadowValue) )
                {
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNAL_INITREPLACESHADOW(uint32,rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                }
                break;
            case COM_SIGTYPE_FLOAT64:
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                Com_SIGNAL_INITREPLACE(uint64,rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                if( (COM_SIG_NO_GROUP_DEF != sigGrpRef)
                    && (NULL_PTR != rxSigInfo->sigShadowValue) )
                {
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNAL_INITREPLACESHADOW(uint64,rxSigInfo);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                }
                break;
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
            /* PolySpace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_Com_16.4" */
            default :
                break;
        }
    }
}

/*
********************************************************************************
* Function Name: Com_InitRxSignalCnt
*
* Explanation: Initialize the rx signal with first timeout value and set the
*              receive signal deadline monitor flag.
*
* param: PduInfo: Rx Pdu Info.
*
* retval: void
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_InitRxSignalCnt
(
    P2CONST(COM_RxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
)
{
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    if( NULL_PTR != PduInfo )
    {
        uint16 sigIdx;
        uint16 sigStartIdx;
        uint16 sigEndIdx;
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
        uint32 updatePos;
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */

#if( COM_RXSIGGROUPINFO == STD_ON )
        uint16 grpIdx;
        /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
        uint16 grpStartIdx = PduInfo->acSigGrpStartIndex;
        /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
        uint16 grpEndIdx = PduInfo->acSigGrpEndIndex;
#endif

        sigStartIdx = PduInfo->awSigStartIndex;
        sigEndIdx = PduInfo->awSigEndIndex;
        /* sig with updatebit cyccounter init. */
        for( sigIdx = sigStartIdx; sigIdx < sigEndIdx; sigIdx++ )
        {
            /* Signal not in Signal Group. */
            if( COM_SIG_NO_GROUP_DEF == Com_RxSignalInfo[sigIdx].acSigGrpIdx )
            {
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
                updatePos = Com_RxSignalInfo[sigIdx].updateBitPosition;

                if( COM_SIG_NO_UPDATEBIT_DEF != updatePos )
                {
                    if( COM_INIT_ZERO < Com_RxSignalInfo[sigIdx].acRxFirstTimeout )
                    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                    {
                        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                        if( NULL_PTR != Com_RxSignalInfo[sigIdx].updateCnt )
                        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                        {
                            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                            (*((uint16*)Com_RxSignalInfo[sigIdx].updateCnt)) = Com_RxSignalInfo[sigIdx].acRxFirstTimeout;
                        }
                        Com_RxSignalInfo[sigIdx].astSignalInterMonitor->acSignalUpdateEnableDeadline = TRUE;
                    }
                    else
                    {
                        Com_RxSignalInfo[sigIdx].astSignalInterMonitor->acSignalUpdateEnableDeadline = FALSE;
                    }
                }
                else
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */
                {
                    if( COM_INIT_ZERO < (PduInfo->sigMinimumFirstTimeout) )
                    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                    {
                        Com_RxSignalInfo[sigIdx].astSignalInterMonitor->acSignalEnableDeadline = TRUE;
                    }
                    else
                    {
                        Com_RxSignalInfo[sigIdx].astSignalInterMonitor->acSignalEnableDeadline = FALSE;
                    }
                }
            }
        }

#if( COM_RXSIGGROUPINFO == STD_ON )
        /* SigGrp with updatebit cyccounter init. */
        for( grpIdx = grpStartIdx; grpIdx < grpEndIdx; grpIdx++ )
        {
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
            updatePos = Com_RxSigGrpInfo[grpIdx].updateBitPosition;

            if( COM_SIG_NO_UPDATEBIT_DEF != updatePos )
            {
                if( COM_INIT_ZERO < Com_RxSigGrpInfo[grpIdx].acFirstTimeout )
                /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                {
                    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                    if( NULL_PTR != Com_RxSignalInfo[sigIdx].updateCnt )
                    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                    {
                        /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                        (*((uint16*)Com_RxSigGrpInfo[grpIdx].updateCnt)) = Com_RxSigGrpInfo[grpIdx].acFirstTimeout;
                    }
                    Com_RxSigGrpInfo[grpIdx].astSignalGrpInterMonitor->acSignalGrpUpdateEnableDeadline = TRUE;
                }
                else
                {
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_RxSigGrpInfo[grpIdx].astSignalGrpInterMonitor->acSignalGrpUpdateEnableDeadline = FALSE;
                }
            }
            else
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */
            {
                if( COM_INIT_ZERO < (PduInfo->sigMinimumFirstTimeout) )
                /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                {
                    Com_RxSigGrpInfo[grpIdx].astSignalGrpInterMonitor->acSignalGrpEnableDeadline = TRUE;
                }
                else
                {
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_RxSigGrpInfo[grpIdx].astSignalGrpInterMonitor->acSignalGrpEnableDeadline = FALSE;
                }
            }
        }
#endif  /* COM_RXSIGGROUPINFO == STD_ON */
    }
}


#if( COM_MULTICORE_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Com_InterCore_Process
*
* Explanation: The service updates the signal object identified by SignalId with
*              the signal referenced by the SignalDataPtr parameter.
*
* param: sigId : Id of signal to be sent.
*        sigDataPtr:  Reference to the signal data to be transmitted.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_InterCore_Process
(
    uint16 sigId,
    P2CONST(void, AUTOMATIC, COM_APPL_CONST) sigDataPtr
)
{
    boolean sigValChangeFlag = FALSE;
    Com_SigType txSignalType;
    uint16 sigLengthIndex;
    const COM_TxSignalInfo_st* txSigInfo = Com_TxSignalInfo;
    /* Obtain signal type. */
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
    txSignalType = txSigInfo[sigId].sigType;
#else  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
    txSignalType = Com_GetSignalType(txSigInfo[sigId].sigBaseInfo->sigFuncIdx);
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */

    if(E_OK == GetSpinlock(COM_SPINLOCK_ID_GW_INTERCORE_SENDSIGNAL))
    {
        /* Judge signal type. */
        switch( txSignalType )
        {
            /* Assign values according to different types of signals. */
            case COM_SIGTYPE_BOOLEAN:
                if( (*(boolean*)txSigInfo[sigId].sigValShadowBufPtr) != (*(boolean*)sigDataPtr) )
                {
                    sigValChangeFlag = TRUE;
                    *(boolean*)txSigInfo[sigId].sigValShadowBufPtr = (*(boolean*)sigDataPtr)&(COM_OPERAND_ONE);
                }
                break;
            case COM_SIGTYPE_UINT8:
                if( (*(uint8*)txSigInfo[sigId].sigValShadowBufPtr) != (*(uint8*)sigDataPtr) )
                {
                    sigValChangeFlag = TRUE;
                    *(uint8*)txSigInfo[sigId].sigValShadowBufPtr = *(uint8*)sigDataPtr;
                }
                break;
            case COM_SIGTYPE_UINT16:
                if( (*(uint16*)txSigInfo[sigId].sigValShadowBufPtr) != (*(uint16*)sigDataPtr) )
                {
                    sigValChangeFlag = TRUE;
                    *(uint16*)txSigInfo[sigId].sigValShadowBufPtr = *(uint16*)sigDataPtr;
                }
                break;
            case COM_SIGTYPE_UINT32:
                if( (*(uint32*)txSigInfo[sigId].sigValShadowBufPtr) != (*(uint32*)sigDataPtr) )
                {
                    sigValChangeFlag = TRUE;
                    *(uint32*)txSigInfo[sigId].sigValShadowBufPtr = *(uint32*)sigDataPtr;
                }
                break;
            case COM_SIGTYPE_UINT64:
                if( (*(uint64*)txSigInfo[sigId].sigValShadowBufPtr) != (*(uint64*)sigDataPtr) )
                {
                    sigValChangeFlag = TRUE;
                    *(uint64*)txSigInfo[sigId].sigValShadowBufPtr = *(uint64*)sigDataPtr;
                }
                break;
            case COM_SIGTYPE_FLOAT32:
                if( FALSE == Com_CompareFloat32Values((*(float32*)txSigInfo[sigId].sigValShadowBufPtr),(*(float32*)sigDataPtr)) )
                {
                    sigValChangeFlag = TRUE;
                    *(float32*)txSigInfo[sigId].sigValShadowBufPtr = *(float32*)sigDataPtr;
                }
                break;
            case COM_SIGTYPE_FLOAT64:
                if( FALSE == Com_CompareFloat64Values((*(float64*)txSigInfo[sigId].sigValShadowBufPtr),(*(float64*)sigDataPtr)) )
                {
                    sigValChangeFlag = TRUE;
                    *(float64*)txSigInfo[sigId].sigValShadowBufPtr = *(float64*)sigDataPtr;
                }
                break;
            case COM_SIGTYPE_SINT16:
                if( (*(sint16*)txSigInfo[sigId].sigValShadowBufPtr) != (*(sint16*)sigDataPtr) )
                {
                    sigValChangeFlag = TRUE;
                    *(sint16*)txSigInfo[sigId].sigValShadowBufPtr = *(sint16*)sigDataPtr;
                }
                break;
            case COM_SIGTYPE_SINT32:
                if( (*(sint32*)txSigInfo[sigId].sigValShadowBufPtr) != (*(sint32*)sigDataPtr) )
                {
                    sigValChangeFlag = TRUE;
                    *(sint32*)txSigInfo[sigId].sigValShadowBufPtr = *(sint32*)sigDataPtr;
                }
                break;
            case COM_SIGTYPE_SINT64:
                if( (*(sint64*)txSigInfo[sigId].sigValShadowBufPtr) != (*(sint64*)sigDataPtr) )
                {
                    sigValChangeFlag = TRUE;
                    *(sint64*)txSigInfo[sigId].sigValShadowBufPtr = *(sint64*)sigDataPtr;
                }
                break;
            case COM_SIGTYPE_SINT8:
                if( (*(sint8*)txSigInfo[sigId].sigValShadowBufPtr) != (*(sint8*)sigDataPtr) )
                {
                    sigValChangeFlag = TRUE;
                    *(sint8*)txSigInfo[sigId].sigValShadowBufPtr = *(sint8*)sigDataPtr;
                }
                break;
            case COM_SIGTYPE_UINT8_DYN:

                break;
            case COM_SIGTYPE_UINT8_N:
                for( sigLengthIndex = COM_INIT_ZERO; sigLengthIndex < txSigInfo[sigId].sigBaseInfo->sigByteLength; sigLengthIndex++ )
                {
                    if( ((uint8*)txSigInfo[sigId].sigValShadowBufPtr)[sigLengthIndex] != ((uint8*)sigDataPtr)[sigLengthIndex] )
                    {
                        sigValChangeFlag = TRUE;
                        ((uint8*)txSigInfo[sigId].sigValShadowBufPtr)[sigLengthIndex] = ((uint8*)sigDataPtr)[sigLengthIndex];
                    }
                }
                break;
            default:
                break;
        }

        if( (boolean)TRUE == sigValChangeFlag)
        {
            if( COM_SIG_NO_GROUP_DEF == txSigInfo[sigId].acSigGrpIdx )
            {
                *(txSigInfo[sigId].sigSendSta) = COM_SIG_SENDSTA_READY;
            }
            else
            {
                *(txSigInfo[sigId].sigSendSta) = COM_SIG_SENDSTA_WAITGRP;
            }
        }

        if( COM_SIG_NO_GROUP_DEF == txSigInfo[sigId].acSigGrpIdx )
        {
             Com_SendPduStaProcess(&txSigInfo[sigId], sigValChangeFlag);
        }
#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
        if( COM_SIG_NO_UPDATEBIT_DEF != txSigInfo[sigId].updateBitSigIndex )
        {
            /* Process updateBit signal. */
            Com_SigTxSetUb(txSigInfo[sigId].updateBitSigIndex, txSigInfo[sigId].acPduId);
        }
#endif  /* COM_TXUPDATEBITCFG_SUPPORT == STD_ON */
        (void)ReleaseSpinlock(COM_SPINLOCK_ID_GW_INTERCORE_SENDSIGNAL);
    }
}

/*
********************************************************************************
* Function Name: Com_GetPduIndex
*
* Explanation: Get the pdu index.
*
* param: mainFunction : Type of sub mainfunction.
*        direction: Transmit or receive.
         coreId: Core id
         PduIndexPtr: Pointer of pdu index.
*
* retval : None
********************************************************************************
*/
static FUNC(uint8, COM_CODE) Com_GetPduIndex
(
    Com_MainFunctionType mainFunction,
    uint8 direction,
    uint32 coreId,
    const Com_PduIndexInfo_st** PduIndexPtr
)
{
    uint8 retVal = COM_E_NOK;
    if( COM_TRANSMIT == direction )
    {
        switch(mainFunction)
        {
            case COM_MAINFUNCTION_CAN:
                *PduIndexPtr = Com_TxPduIndex_Can + coreId;
                retVal = COM_E_OK;
                break;
            case COM_MAINFUNCTION_LIN:
                *PduIndexPtr = Com_TxPduIndex_Lin + coreId;
                retVal = COM_E_OK;
                break;
            case COM_MAINFUNCTION_FR:
                *PduIndexPtr = Com_TxPduIndex_Fr + coreId;
                retVal = COM_E_OK;
                break;
            case COM_MAINFUNCTION_ETH:
                *PduIndexPtr = Com_TxPduIndex_Eth + coreId;
                retVal = COM_E_OK;
                break;
            default:
                break;
        }
    }
    else if( COM_RECEIVE == direction )
    {
        switch(mainFunction)
        {
            case COM_MAINFUNCTION_CAN:
                *PduIndexPtr = Com_RxPduIndex_Can + coreId;
                retVal = COM_E_OK;
                break;
            case COM_MAINFUNCTION_LIN:
                *PduIndexPtr = Com_RxPduIndex_Lin + coreId;
                retVal = COM_E_OK;
                break;
            case COM_MAINFUNCTION_FR:
                *PduIndexPtr = Com_RxPduIndex_Fr + coreId;
                retVal = COM_E_OK;
                break;
            case COM_MAINFUNCTION_ETH:
                *PduIndexPtr = Com_RxPduIndex_Eth + coreId;
                retVal = COM_E_OK;
                break;
            default:
                break;
        }
    }
    else
    {
        /* do nothing*/
    }
    return retVal;
}

#endif  /* COM_MULTICORE_SUPPORT == STD_ON */

/*
********************************************************************************
* Function Name: Com_RxIndicationProcess
*
* Explanation: Indication of a received I-PDU from a lower layer communication interface module.
*
* param: RxPduId: Receive Pdu Id.
*        PduInfoPtr: Pdu Information Pointer.
*
* retval: None
********************************************************************************
*/
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_RxIndicationProcess
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
)
{
#if( COM_RXPDUCALLOUTINFO == STD_ON )
    boolean calloutResult = TRUE;
#endif
    uint8 acSduLength;

#if( COM_RXPDU_SIGPRCS_IMMEDIATE_SUPPORT == STD_ON )
    uint16 sigIdx;
    uint16 sigIdxStart;
    uint16 sigIdxEnd;

 #if( COM_RXSIGGROUPINFO == STD_ON )
    uint16 grpIdx;
    uint16 grpIdxStart;
    uint16 grpIdxEnd;
#endif  /* COM_RXSIGGROUPINFO == STD_ON */

    const COM_RxSignalInfo_st* rxSigInfo = Com_RxSignalInfo;

#endif  /* COM_RXPDU_SIGPRCS_IMMEDIATE_SUPPORT == STD_ON */

    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxPduInfo_st* astRxPduInfo = Com_RxPduInfo;

    /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" */
    acSduLength = (uint8)PduInfoPtr->SduLength;

    /* If Rx Pdu is Active. */
    if( COM_PDU_ACTIVE == astRxPduInfo[RxPduId].astPduInterMonitor->pduSta )
    {
        /* The length of the assignment. */
        astRxPduInfo[RxPduId].astPduInterMonitor->acPduLength = acSduLength;

#if( COM_RXPDUCALLOUTINFO == STD_ON )
        /* if pdu has call out function ,call it. */
        if( NULL_PTR != astRxPduInfo[RxPduId].Callout )
        {
            /* Callback. */
            /* PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
            calloutResult = astRxPduInfo[RxPduId].Callout(RxPduId, (PduInfoType*)PduInfoPtr);  /* PRQA S 0311 */ /* NSCA_QAC_Com_Rule11.8 */
        }

        /* If call out function result is true,do the data process. */
        if( (boolean)TRUE == calloutResult )
#endif  /* COM_RXPDUCALLOUTINFO == STD_ON */
        {
             /* If signal process type is deferred.set flag,and copy sdu data to the raw data. */
            if( COM_PDU_SIGPRCS_DEFERRED == astRxPduInfo[RxPduId].acSignalProcessType )
            {
                /* Clear COM_PDU_GW_DSCP_HANDLE_FLAG. */
                /* PolySpace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
                astRxPduInfo[RxPduId].astPduInterMonitor->acPduRecSts &= ~(COM_PDU_GW_DSCP_HANDLE_FLAG);  /* PRQA S 4432,4522,4532,4522 */ /* NSCA_QAC_Com_Rule10.3, NSCA_QAC_Com_Rule10.1, NSCA_QAC_Com_Rule10.1, NSCA_QAC_Com_Rule10.1 */
                /* Update received message flags. */
                /* PolySpace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" PolySpace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_Com_10.1" PolySpace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_Com_10.4" */
                astRxPduInfo[RxPduId].astPduInterMonitor->acPduRecSts |= (COM_PDU_RECEIVED | COM_PDU_GW_DSCP_FLAG);  /* PRQA S 4432,4522,4542 */ /* NSCA_QAC_Com_Rule10.3, NSCA_QAC_Com_Rule10.1, NSCA_QAC_Com_Rule10.1 */
                /* Judge length range. */
                if( acSduLength <= astRxPduInfo[RxPduId].acPduLenth )
                {
                    /* Data assignment. */
                    Com_Memcpy32(astRxPduInfo[RxPduId].datavalid, PduInfoPtr->SduDataPtr, acSduLength);
                }
                else
                {
                    /* Data assignment. */
                    Com_Memcpy32(astRxPduInfo[RxPduId].datavalid, PduInfoPtr->SduDataPtr, astRxPduInfo[RxPduId].acPduLenth);
                }
            }

#if( COM_RXPDU_SIGPRCS_IMMEDIATE_SUPPORT == STD_ON )
            /* if signal process type is immediate ,do the data process include invalid updatebit evaluate. */
            if(COM_PDU_SIGPRCS_IMMEDIATE == astRxPduInfo[RxPduId].acSignalProcessType)
            {
                /* Update received message flags.(COM_PDU_WAITRECEIVE) */
                astRxPduInfo[RxPduId].astPduInterMonitor->acPduRecSts = COM_PDU_GW_SIG_DSCP_FLAG;
                /* Clear the timeout flag. */
                astRxPduInfo[RxPduId].astPduInterMonitor->rxTimeout = FALSE;
                /* Clear pdu timeout flag */
                /* PolySpace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
                astRxPduInfo[RxPduId].astPduInterMonitor->acPduRecSts &= (~COM_PDU_RECTIMEOUT);
                /* Judge length range. */
                if( acSduLength <= astRxPduInfo[RxPduId].acPduLenth )
                {
                    /* Data assignment. */
                    Com_Memcpy32(astRxPduInfo[RxPduId].datavalid, PduInfoPtr->SduDataPtr, acSduLength);
                }
                else
                {
                    /* Data assignment. */
                    Com_Memcpy32(astRxPduInfo[RxPduId].datavalid, PduInfoPtr->SduDataPtr, astRxPduInfo[RxPduId].acPduLenth);
                }
                sigIdxStart = Com_RxPduInfo[RxPduId].awSigStartIndex;
                sigIdxEnd = Com_RxPduInfo[RxPduId].awSigEndIndex;

                /* Signal process. */
                for( sigIdx = sigIdxStart; sigIdx < sigIdxEnd; sigIdx++ )
                {
                    /* Whether signal type. */
                    if( COM_SIG_NO_GROUP_DEF == Com_RxSignalInfo[sigIdx].acSigGrpIdx )
                    {
                        rxSigInfo = &Com_RxSignalInfo[sigIdx];
                        /* Analytic signal */
                        Com_RxSignalAnalysis_Process(sigIdx,(astRxPduInfo[RxPduId].datavalid),rxSigInfo);
                        if( FALSE == rxSigInfo->astSignalInterMonitor->acSignalEnableDeadline )
                        {
                            rxSigInfo->astSignalInterMonitor->acSignalEnableDeadline = TRUE;
                        }
                        if( FALSE == rxSigInfo->astSignalInterMonitor->acSignalUpdateEnableDeadline )
                        {
                            rxSigInfo->astSignalInterMonitor->acSignalUpdateEnableDeadline = TRUE;
                        }
                    }
                }

#if( COM_RXSIGGROUPINFO == STD_ON )
                grpIdxStart = Com_RxPduInfo[RxPduId].acSigGrpStartIndex;
                grpIdxEnd = Com_RxPduInfo[RxPduId].acSigGrpEndIndex;
                /* Signalgroup process. */
                for( grpIdx = grpIdxStart; grpIdx < grpIdxEnd; grpIdx++ )
                {
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
                    if( (uint8)TRUE == Com_SigGrpRxReadUb(grpIdx) )
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */
                    {
                        /* Do Rx ComSignalGroup processing. */
                        Com_RxProcessing_ProcessSigGrpEvent(grpIdx, &astRxPduInfo[RxPduId]);
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        if( FALSE == Com_RxSigGrpInfo[grpIdx].astSignalGrpInterMonitor->acSignalGrpEnableDeadline )
                        {
                            Com_RxSigGrpInfo[grpIdx].astSignalGrpInterMonitor->acSignalGrpEnableDeadline = TRUE;
                        }
                        if( FALSE == Com_RxSigGrpInfo[grpIdx].astSignalGrpInterMonitor->acSignalGrpUpdateEnableDeadline )
                        {
                            Com_RxSigGrpInfo[grpIdx].astSignalGrpInterMonitor->acSignalGrpUpdateEnableDeadline = TRUE;
                        }
                    }
                }
#endif  /* (COM_RXSIGGROUPINFO == STD_ON) */

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
                /* receive update_bit counter percess. */
                Com_RxUpdateCntProcess(&astRxPduInfo[RxPduId]);
#endif
                /* pdu counter redo set. */
                astRxPduInfo[RxPduId].astPduInterMonitor->acPduCycCounter
                  = astRxPduInfo[RxPduId].sigMinimumTimeout + COM_OPERAND_ONE;
            }
#endif  /* COM_RXPDU_SIGPRCS_IMMEDIATE_SUPPORT == STD_ON */
        }
        astRxPduInfo[RxPduId].astPduInterMonitor->acPduCycCounterForGw =
            astRxPduInfo[RxPduId].astPduInterMonitor->acPduCycCounterForGwInit;
    }
}
/*
********************************************************************************
* Function Name: Com_Init
*
* Explanation: This service initializes internal and external interfaces and
*              variables of the AUTO-SAR COM module layer for the further processing.
* param: config:
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.5" */
FUNC(void, COM_CODE) Com_Init  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    P2CONST(Com_ConfigType, AUTOMATIC, COM_APPL_CONST) config
)
{
    uint8 errorId = COM_E_NO_ERROR;
    COM_DUMMY_STATEMENT(config);

    if( COM_INIT == Com_Initialized )
    {
        /* Set Det errorId COM_E_INIT_FAILED. */
        errorId = COM_E_INIT_FAILED;
    }
    else
    {
        /* Initializes the sending message. */
        Com_InitAllIPdus_Tx();
        /* Initializes the receive message. */
        Com_InitAllIPdus_Rx();
        /* Active Rx Pdus. */
        Com_ActivateRxComIPdus();
        /* Active Tx Pdus. */
        Com_ActivateTxComIPdus();
        /* Add NULL_PTR judge. */
        errorId = Com_PointerNullPtr_judge();

#if( COM_GWSIGNAL_SUPPORT == STD_ON )
        Com_GwInfoInit();
#endif

        if( COM_E_NO_ERROR == errorId )
        {
            /* Com Initalize Flag Set. */
            Com_Initialized = COM_INIT;
        }
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_INIT, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

}

/*
********************************************************************************
* Function Name: Com_DeInit
*
* Explanation: This service stops the inter-ECU communication.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, COM_CODE) Com_DeInit( void )  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    uint8 acIpduGroupVector[COM_PDUGRP_VECTOR_SIZE] = {COM_INIT_ZERO};

    uint8 errorId = COM_E_NO_ERROR;

    if( COM_INIT != Com_Initialized )
    {
        errorId = COM_E_UNINIT;
    }
    else
    {
        /* Deactive Rx Pdus. */
        Com_DeActivateRxComIPdus();
        /* Deactive Tx Pdus . */
        Com_DeActivateTxComIPdus();
        /*  Update the states of all related Rx ComIPdus. */
        Com_IpduGrpCtrl_UpRxIPduSts(acIpduGroupVector, FALSE);
         /*  Update the states of all related Tx ComIPdus. */
        Com_IpduGrpCtrl_UpTxIPduSts(acIpduGroupVector, FALSE);
        Com_Initialized = COM_UNINIT;
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_DEINIT, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

}

/*
********************************************************************************
* Function Name: Com_IpduGroupControl
*
* Explanation: This service starts I-PDU groups.
*
* param: ipduGroupVector: I-PDU group vector containing the activation state
*                         (stopped = 0/ started = 1) for all I-PDU groups.
*        initialize: flag to request initialization of the I-PDUs which are newly started
*
* retval: None
********************************************************************************
*/
FUNC(void, COM_CODE) Com_IpduGroupControl  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    Com_IpduGroupVector ipduGroupVector,
    boolean initialize
)
{
    uint8 errorId = COM_E_NO_ERROR;

    /* If Com is not initialize. */
    if( COM_INIT != Com_Initialized )
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
    else if( NULL_PTR == ipduGroupVector )  /* Check NULL_PTR. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        /* Set Det errorId COM_E_INIT_FAILED. */
        errorId = COM_E_PARAM_POINTER;
    }
    else
    {
        /*  Update the states of all related Rx ComIPdus. */
        Com_IpduGrpCtrl_UpRxIPduSts(ipduGroupVector, initialize);

        /* Update the states of all related Tx ComIPdus. */
        Com_IpduGrpCtrl_UpTxIPduSts(ipduGroupVector, initialize);
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_IPDUGROUPCONTROL, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */
}

/*
********************************************************************************
* Function Name: Com_ReceptionDMControl
*
* Explanation: This service enables or disables I-PDU group Deadline Monitoring.
*
* param: ipduGroupVector:I-PDU group vector containing the requested deadline
*                        monitoring state (disabled = 0/ enabled = 1) for all I-PDU groups.
* retval: None
********************************************************************************
*/
FUNC(void, COM_CODE) Com_ReceptionDMControl  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    Com_IpduGroupVector ipduGroupVector  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
)
{
    uint8 vectorBitOffset = COM_INIT_ZERO;
    uint8 vectorBitShift = COM_INIT_ZERO;
    uint16 vectorMatchPos;
    uint16 vectorBytePos;
    uint16 pduIdx;
    uint16 pduGrpVectorIdx;
    boolean pduEnableState;

    uint8 errorId = COM_E_NO_ERROR;

    if( COM_INIT != Com_Initialized )
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
    else if( NULL_PTR == ipduGroupVector )
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        /* Set Det errorId COM_E_PARAM_POINTER. */
        errorId = COM_E_PARAM_POINTER;
    }
    else
    {
        /* process all Rx Pdu. */
        for( pduIdx = COM_INIT_ZERO; pduIdx < COM_RXPDU_NUM; pduIdx++ )
        {
            pduEnableState = FALSE;
            /* The pdu state is active. */
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            if( COM_PDU_TYPE_ACTIVE_CONTROL == Com_RxPduInfo[pduIdx].acPduActiveType )
            {
                for( pduGrpVectorIdx = Com_RxPduInfo[pduIdx].acPduGrpVectorStartIdx;
                     pduGrpVectorIdx < Com_RxPduInfo[pduIdx].acpduGrpVectorEndIdx; pduGrpVectorIdx++ )
                {
                    /* Get matched actual IPdu Group Vector Mask. */
                    vectorMatchPos = Com_PduGrpVectorMatch[pduGrpVectorIdx];
                    vectorBytePos = vectorMatchPos / COM_1BYTE_BITLENGTH;
                    vectorBitOffset = (uint8)(vectorMatchPos % COM_1BYTE_BITLENGTH);

                    vectorBitShift = COM_OPERAND_ONE;
                    vectorBitShift <<= vectorBitOffset;
                    /* If at least one related ComIPduGroup is active the requested state is active. */
                    /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" */
                    if( COM_INIT_ZERO != ((uint8)ipduGroupVector[vectorBytePos] & vectorBitShift) )
                    {
                        pduEnableState = TRUE;
                    }
                }
                /* Check whether the timeout monitor needs to be enabled. */
                if( (TRUE == pduEnableState) && (FALSE == Com_RxPduInfo[pduIdx].astPduInterMonitor->enableDeadline) &&
                    (COM_INIT_ZERO < Com_RxPduInfo[pduIdx].sigMinimumTimeout) )
                {
                    Com_RxPduInfo[pduIdx].astPduInterMonitor->enableDeadline = TRUE;
                    Com_RxPduInfo[pduIdx].astPduInterMonitor->acPduCycCounter = Com_RxPduInfo[pduIdx].sigMinimumFirstTimeout;
                    Com_InitRxSignalCnt(&Com_RxPduInfo[pduIdx]);
                }
                else if( (FALSE == pduEnableState) && (TRUE == Com_RxPduInfo[pduIdx].astPduInterMonitor->enableDeadline) )
                {
                    Com_RxPduInfo[pduIdx].astPduInterMonitor->enableDeadline = FALSE;
                }
                else
                {
                    /* Do Nothing*/
                }
            }
        }
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
   /* Development Error Report. */
   Com_Det_ErrorReport(COM_SERVICEID_RECEPTIONDMCONTROL, errorId);
#else
   COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

}

/*
********************************************************************************
* Function Name: Com_GetStatus
*
* Explanation: Returns the status of the AUTOSAR COM module.
*
* param: None
*
* retval: Com_Initialized: COM_UNINIT
*                          COM_INIT
********************************************************************************
*/
FUNC(Com_StatusType, COM_CODE) Com_GetStatus( void )  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    uint8 errorId = COM_E_NO_ERROR;

    if( COM_INIT != Com_Initialized )
    {
         /* Set Det errorId COM_E_UNINIT. */
         errorId = COM_E_UNINIT;
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_GETSTATUS, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

    /* Return Com Module Current Status, Initialize or not Initialize. */
    return Com_Initialized;
}

#if( COM_VERSIONINFOAPI_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Com_GetVersionInfo
*
* Explanation: Returns the version information of this module.
*
* param: Pointer to where to store the version information of this module.
*
* retval: None
********************************************************************************
*/
FUNC(void, COM_CODE) Com_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, COM_APPL_DATA) versioninfo
)
{
    uint8 errorId = COM_E_NO_ERROR;

    if( NULL_PTR == versioninfo ) /* Check NULL_PTR. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        /* Set Det errorId COM_E_PARAM_POINTER. */
        errorId = COM_E_PARAM_POINTER;
    }
    else
    {
        /* Write component data to versioninfo. */
        /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" */
        versioninfo->moduleID = COM_MODULE_ID;
        versioninfo->vendorID = COM_VENDOR_ID;
        versioninfo->sw_major_version = COM_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = COM_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = COM_SW_PATCH_VERSION;
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_GETVERSIONINFO, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

}
#endif  /* COM_VERSIONINFOAPI_SUPPORT == STD_ON */

/*
********************************************************************************
* Function Name: Com_ClearIpduGroupVector
*
* Explanation: This service sets all bits of the given Com_IpduGroupVector to 0.
*
* param: pduGroupVector: I-PDU group vector to be cleared.
*
* retval: void
*
********************************************************************************
*/
FUNC(void, COM_CODE) Com_ClearIpduGroupVector  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    Com_IpduGroupVector ipduGroupVector
)
{
    uint8 pduGrpIdx;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    uint8 datazero[COM_PDUGRP_VECTOR_SIZE] = { COM_INIT_ZERO };
    uint8 errorId = COM_E_NO_ERROR;

    if( COM_INIT != Com_Initialized )
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
    else if( NULL_PTR == ipduGroupVector )
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        errorId = COM_E_PARAM_POINTER;
    }
    else
    {
        /* I-PDU group vector to be cleared. */
        for( pduGrpIdx = COM_INIT_ZERO; pduGrpIdx < COM_PDUGRP_VECTOR_SIZE; pduGrpIdx++ )
        {
            /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" */
            ipduGroupVector[pduGrpIdx] = datazero[pduGrpIdx];
        }
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_CLEARIPDUGROUPVECTOR, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

}

/*
********************************************************************************
* Function Name: Com_SetIpduGroup
*
* Explanation: This service sets the value of a bit in an I-PDU group vector.
*
* param: ipduGroupVector: I-PDU group vector to be modified.
*        ipduGroupId: ipduGroup used to identify the corresponding bit in the I-PDU
*                     group vector.
*        bitval: New value of the corresponding bit.
*
* retval: None
********************************************************************************
*/
FUNC(void, COM_CODE) Com_SetIpduGroup  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    Com_IpduGroupVector ipduGroupVector,
    Com_IpduGroupIdType ipduGroupId,
    boolean bitval
)
{
    uint8 pduGrpIdBytePos;
    uint8 pduGrpOffest;
    uint8 tempData;

    uint8 errorId = COM_E_NO_ERROR;

    if( COM_INIT != Com_Initialized )
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
    else if( ipduGroupId >= COM_PDUGRP_SIZE ) /* Check parameter range. */
    {
        /* Set Det errorId COM_E_PARAM. */
        errorId = COM_E_PARAM;
    }
    else if( NULL_PTR == ipduGroupVector )
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        errorId = COM_E_PARAM_POINTER;
    }
    else
    {
        pduGrpIdBytePos = (uint8)ipduGroupId / COM_1BYTE_BITLENGTH;
        pduGrpOffest = (uint8)ipduGroupId % COM_1BYTE_BITLENGTH;

        if( TRUE == bitval )
        {
            tempData =  (uint8)((uint32)COM_OPERAND_ONE << pduGrpOffest);
            /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" */
            ipduGroupVector[pduGrpIdBytePos] = (ipduGroupVector[pduGrpIdBytePos] | tempData);
        }
        else
        {
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_4.1" PolySpace +1 DEFECT:UINT_CONV_OVFL [Justified:Unset] "NSCA_Polyspace_Com_UINT_CONV_OVFL" */
            tempData =  (uint8)(~((uint32)COM_OPERAND_ONE << pduGrpOffest));
            /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" */
            ipduGroupVector[pduGrpIdBytePos] = ipduGroupVector[pduGrpIdBytePos] & tempData;
        }
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_SETIPDUGROUP, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

}

/*
********************************************************************************
* Function Name: Com_SendSignal
* Explanation: The service Com_SendSignal updates the signal object identified
*              by SignalId with the signal referenced by the SignalDataPtr parameter.
*
* param: SignalId: Id of signal to be sent.
*        SignalDataPtr: Reference to the signal data to be transmitted.
*
* retval: checkRet : E_OK: service has been accepted
*                    COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped
*                                              (or service failed due to development error).
*                    COM_BUSY: in case the TP-Buffer is locked for large data types handling.
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint8, COM_CODE) Com_SendSignal  /* PRQA S 1505 */ /* NSCA_QAC_Common_Rule8.7 */
(
    Com_SignalIdType SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr
)
{
    uint8 checkRet = COM_SERVICE_NOT_AVAILABLE;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxSignalInfo_st* txSigInfo = Com_TxSignalInfo;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxPduInfo_st* PduInfo = Com_TxPduInfo;

    uint8 errorId = COM_E_NO_ERROR;

    if( COM_INIT != Com_Initialized ) /* Com module not initial. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
    else if( COM_TXSIG_NUM <= SignalId ) /* Signal Id overflow. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        /* Set Det errorId COM_E_PARAM. */
        errorId = COM_E_PARAM;
    }
    else if( NULL_PTR == SignalDataPtr ) /* Null Pointer. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        /* Set Det errorId COM_E_PARAM_POINTER. */
        errorId = COM_E_PARAM_POINTER;
    }
    else
    {
        if( (NULL_PTR != PduInfo[txSigInfo[SignalId].acPduId].pduTpMonitor)
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            && (COM_PDU_TPCONNECTION_YES == PduInfo[txSigInfo[SignalId].acPduId].pduTpMonitor->pduTpConnection) )
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        {
            /* In case the TP-Buffer is locked for large data types handling. */
            checkRet = COM_BUSY;
        }
        else
        {
            /* Send signal process.*/
            Com_SendSignal_Process(SignalId, SignalDataPtr);
#if( COM_TXSIGNALFILTER_SUPPORTED == STD_ON )
            /* Send signal filter process. */
            if( NULL_PTR != txSigInfo[SignalId].sigFilterInfo )
            {
                /* [SWS_Com_00245] */
                Com_TxSignalFilter_Process(SignalId, SignalDataPtr);
            }
#endif  /* COM_TXSIGNALFILTER_SUPPORTED == STD_ON */
            checkRet = E_OK;
        }

        if( COM_PDU_STA_INACTIVE == PduInfo[txSigInfo[SignalId].acPduId].astPduInterMonitor->pduSta )
        {
            checkRet = COM_SERVICE_NOT_AVAILABLE;
        }
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_SENDSIGNAL, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

    return checkRet;
}

#if( (COM_METADATA_SUPPORT == STD_ON) && (COM_TXMETADATA_NUM > COM_INIT_ZERO) )
/*
********************************************************************************
* Function Name: Com_SendSignalWithMetaData
* Explanation: The service Com_SendSignalWithMetaData updates the signal object identified by 
*              SignalId with the signal referenced by the SignalDataPtr parameter. The meta 
*              data is provided via the MetaDataPtr parameter. 
*
* param: SignalId: Id of signal to be sent.
*        SignalDataPtr: Reference to the signal data to be transmitted.
*        MetaDataPtr: Pointer to the meta data of the signal. 
*
* retval: checkRet : E_OK: service has been accepted
*                    COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped
*                                              (or service failed due to development error).
*                    COM_BUSY: in case the TP-Buffer is locked for large data types handling.
********************************************************************************
*/
FUNC(uint8, COM_CODE) Com_SendSignalWithMetaData
(
    Com_SignalIdType SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr,
    P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) MetaDataPtr
)
{
    uint8 checkRet = COM_SERVICE_NOT_AVAILABLE;
    const COM_TxSignalInfo_st* txSigInfo = Com_TxSignalInfo;
    const COM_TxPduInfo_st* PduInfo = Com_TxPduInfo;
    uint8 metaDataLength = PduInfo[txSigInfo[SignalId].acPduId].acMetaDataLength;
    uint8 *tMetaDataPtr = NULL_PTR;
    uint16 metaDataPduIdx = PduInfo[txSigInfo[SignalId].acPduId].acMetaDataIdx;

    uint8 errorId = COM_E_NO_ERROR;

    /* Com module not initial. */
    if( COM_INIT != Com_Initialized )
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
    /* Signal Id overflow. */
    else if( COM_TXSIG_NUM <= SignalId )
    {
        /* Set Det errorId COM_E_PARAM. */
        errorId = COM_E_PARAM;
    }
    /* Null Pointer. */
    else if( NULL_PTR == SignalDataPtr )
    {
        /* Set Det errorId COM_E_PARAM_POINTER. */
        errorId = COM_E_PARAM_POINTER;
    }
    else if( NULL_PTR == MetaDataPtr )
    {
        /* Set Det errorId COM_E_PARAM_POINTER. */
        errorId = COM_E_PARAM_POINTER;
    }
    else
    {
        /* in case the TP-Buffer is locked for large data types handling */
        if( (NULL_PTR != PduInfo[txSigInfo[SignalId].acPduId].pduTpMonitor) &&
            (COM_PDU_TPCONNECTION_YES == PduInfo[txSigInfo[SignalId].acPduId].pduTpMonitor->pduTpConnection) )
        {
            checkRet = COM_BUSY;
        }
        else
        {
            if( (NULL_PTR != MetaDataPtr) && (COM_METADATA_LEN_ZERO < metaDataLength) && (COM_PDU_NO_METADATA_DEF != metaDataPduIdx) )
            {
#if( COM_TXPDU_TPTYPE_SUPPORT == STD_ON )
                if( NULL_PTR != PduInfo[txSigInfo[SignalId].acPduId].pduTpMonitor )
                {
                    tMetaDataPtr = Com_TxPduMonMetaData[metaDataPduIdx].tpMetaData;
                    Com_TxPduMonMetaData[metaDataPduIdx].tpBusy = TRUE;
                    checkRet = E_OK;
                }
                else
#endif  /* ( COM_TXPDU_TPTYPE_SUPPORT == STD_ON ) */
                {
                    if( NULL_PTR != PduInfo[txSigInfo[SignalId].acPduId].dataRaw )
                    {
                        tMetaDataPtr = &(PduInfo[txSigInfo[SignalId].acPduId].dataRaw[PduInfo[txSigInfo[SignalId].acPduId].acPduLenth]);
                        checkRet = E_OK;
                    }
                }
                if( NULL_PTR != tMetaDataPtr )
                {

                    /* Copy the passed meta data to the Tx ComIPdu buffer and trigger a deferred transmission */
                    Com_Memcpy(tMetaDataPtr, MetaDataPtr, (uint16)metaDataLength);
                    Com_TxPduMonMetaData[metaDataPduIdx].triggerMetaDataEnable = TRUE;
                    /* Send signal process.*/
                    Com_SendSignal_Process(SignalId, SignalDataPtr);
                
#if( COM_TXSIGNALFILTER_SUPPORTED == STD_ON )
                    /* Send signal filter process. */
                    if( NULL_PTR != txSigInfo[SignalId].sigFilterInfo )
                    {
                        /* [SWS_Com_00245] */
                        Com_TxSignalFilter_Process(SignalId, SignalDataPtr);
                    }
#endif  /* COM_TXSIGNALFILTER_SUPPORTED == STD_ON */
                }
            }
        }

        if( COM_PDU_STA_INACTIVE == PduInfo[txSigInfo[SignalId].acPduId].astPduInterMonitor->pduSta )
        {
            checkRet = COM_SERVICE_NOT_AVAILABLE;
        }
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_SENDSIGNAL, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

    return checkRet;
}

/*
********************************************************************************
* Function Name: Com_SendSignalGroupWithMetaData
*
* Explanation: The service Com_SendSignalGroupWithMetaData copies the content of the
*              associated shadow buffer to the associated I-PDU. The meta data is
*              provided via the MetaDataPtr parameter. 
*
* param: SignalGroupId: Id of signal group to be sent.
*
* retval: RtrnValu: E_OK: service has been accepted
*                   COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped
*                                          (or service failed due to development error).
*                   COM_BUSY: in case the TP-Buffer is locked for large data types handling.
********************************************************************************
*/
FUNC(uint8, COM_CODE) Com_SendSignalGroupWithMetaData
(
    Com_SignalGroupIdType SignalGroupId,
    P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) MetaDataPtr
)
{
    uint8 RtrnValu = COM_SERVICE_NOT_AVAILABLE;
    uint8 errorId = COM_E_NO_ERROR;

    /* Com module not initial. */
    if( COM_INIT != Com_Initialized )
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
#if( COM_TXSIGGROUPINFO == STD_ON )
    /* Signal Group Id overflow. */
    else if( COM_TXGRP_NUM <= SignalGroupId )
    {
        /* Set Det errorId COM_E_PARAM. */
        errorId = COM_E_PARAM;
    }
#endif  /*  #if( COM_TXSIGGROUPINFO == STD_ON ) */
    else
    {
        /* in case the TP-Buffer is locked for large data types handling */
        if( (NULL_PTR != Com_TxPduInfo[Com_TxSigGrpInfo[SignalGroupId].awPduId].pduTpMonitor) &&
            (COM_PDU_TPCONNECTION_YES == Com_TxPduInfo[Com_TxSigGrpInfo[SignalGroupId].awPduId].pduTpMonitor->pduTpConnection) )
        {
            RtrnValu = COM_BUSY;
        }
        else
        {
#if( COM_TXSIGGROUPINFO == STD_ON )
            /* Send signal Group process. */
            RtrnValu = Com_SendSigGrp_Process(SignalGroupId);
#if( COM_TXSIGNALFILTER_SUPPORTED == STD_ON )
            /* Send Group signal filter process. */
            Com_TxGroupSignalFilter_Process(SignalGroupId);
#endif  /* COM_TXSIGNALFILTER_SUPPORTED == STD_ON */
            if( COM_PDU_STA_INACTIVE
                == Com_TxPduInfo[Com_TxSigGrpInfo[SignalGroupId].awPduId].astPduInterMonitor->pduSta )
            {
                RtrnValu = COM_SERVICE_NOT_AVAILABLE;
            }
#endif  /* COM_TXSIGGROUPINFO == STD_ON */
        }
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_SENDSIGNALGROUP, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */
    COM_DUMMY_STATEMENT(MetaDataPtr);

    return RtrnValu;
}
#endif  /* ( (COM_METADATA_SUPPORT == STD_ON) && (COM_TXMETADATA_NUM > COM_INIT_ZERO) ) */

/*
********************************************************************************
* Function Name: Com_SendDynSignal
*
* Explanation: The service Com_SendDynSignal updates the signal object identified
*              by SignalId with the signal referenced by the SignalDataPtr parameter.
*
* param: SignalId: Id of signal to be sent.
*        SignalDataPtr: Reference to the signal data to be transmitted.
*        Length: Length of the dynamic length signal.
*
* retval: RtrnValu : E_OK: service has been accepted.
*                E_NOT_OK: in case the Length is greater than the configured
*                          ComSignalLength of this sent signal.
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped
*                                           (or service failed due to development error).
*                COM_BUSY: in case the TP-Buffer is locked.
********************************************************************************
*/
FUNC(uint8, COM_CODE) Com_SendDynSignal  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    Com_SignalIdType SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr,
    uint16 Length
)
{
    uint8 RtrnValu = COM_SERVICE_NOT_AVAILABLE;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxSignalInfo_st* txSigInfo = Com_TxSignalInfo;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxPduInfo_st* PduInfo = Com_TxPduInfo;

    uint8 errorId = COM_E_NO_ERROR;

    if( COM_INIT != Com_Initialized ) /* Com module not initial. */
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
    else if( COM_TXSIG_NUM <= SignalId )/* Signal Id overflow. */
    {
        /* Set Det errorId COM_E_PARAM. */
        errorId = COM_E_PARAM;
    }
    else if( NULL_PTR == SignalDataPtr ) /* Null Pointer. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        /* Set Det errorId COM_E_PARAM_POINTER. */
        errorId = COM_E_PARAM_POINTER;
    }
    else if( Length > Com_TxSignalInfo[SignalId].sigBaseInfo->sigByteLength )
    {
        /* Signal length error. */
        RtrnValu = E_NOT_OK;
    }
    else if( COM_SIGTYPE_UINT8_DYN != Com_GetSignalType(Com_TxSignalInfo[SignalId].sigBaseInfo->sigFuncIdx) )
    {
        /* Signal type error. */
        errorId = COM_E_PARAM;
    }
    else
    {
        /* Pdu state is ACTIVE. */
        if( COM_PDU_STA_INACTIVE != PduInfo[txSigInfo[SignalId].acPduId].astPduInterMonitor->pduSta )
        {
            if( (NULL_PTR != PduInfo[txSigInfo[SignalId].acPduId].pduTpMonitor)
                /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                && (COM_PDU_TPCONNECTION_YES == PduInfo[txSigInfo[SignalId].acPduId].pduTpMonitor->pduTpConnection) )
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                /* In case the TP-Buffer is locked. */
                RtrnValu = COM_BUSY;
            }
            else
            {
                /* Send signal process. */
                Com_SendDynSignal_Process(SignalId, SignalDataPtr, Length);
                RtrnValu = E_OK;
            }
        }
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_SENDDYNSIGNAL, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */
    return RtrnValu;
}

/*
********************************************************************************
* Function Name: Com_ReceiveSignal
*
* Explanation: Com_ReceiveSignal copies the data of the signal identified by SignalId
*              to the location specified by SignalDataPtr.
*
* param: SignalId: Id of signal to be received.
*        SignalDataPtr: Reference to the location where the received signal data shall be stored.
* retval: checkRet: E_OK: service has been accepted.
*                   COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped
*                                           (or service failed due to development error).
*                   COM_BUSY: in case the TP-Buffer is locked for large data types handling.
********************************************************************************
*/
FUNC(uint8, COM_CODE) Com_ReceiveSignal  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    Com_SignalIdType SignalId,
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
)
{
    uint8 checkRet = COM_SERVICE_NOT_AVAILABLE;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSignalInfo_st* rxSigInfo = Com_RxSignalInfo;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxPduInfo_st* PduInfo = Com_RxPduInfo;

    uint8 errorId = COM_E_NO_ERROR;

    if( COM_INIT != Com_Initialized ) /* Com module not initial. */
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
    else if( COM_RXSIG_NUM <= SignalId ) /* Signal Id overflow. */
    {
        /* Set Det errorId COM_E_PARAM. */
        errorId = COM_E_PARAM;
    }
    else if( NULL_PTR == SignalDataPtr )  /* Null Pointer. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        /* Set Det errorId COM_E_PARAM_POINTER. */
        errorId = COM_E_PARAM_POINTER;
    }
    else
    {
        if( (NULL_PTR != PduInfo[rxSigInfo[SignalId].acPduID].pduTpMonitor)
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            && (COM_PDU_TPCONNECTION_YES == PduInfo[rxSigInfo[SignalId].acPduID].pduTpMonitor->pduTpConnection) )
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        {
            /* in case the TP-Buffer is locked for large data types handling. */
            checkRet = COM_BUSY;
        }
        else
        {
            /* Receive signal process */
            Com_ReceiveSignal_Process(SignalId, (const void*)SignalDataPtr);
            checkRet = E_OK;
        }

        if( COM_PDU_INACTIVE == PduInfo[rxSigInfo[SignalId].acPduID].astPduInterMonitor->pduSta )
        {
            checkRet = COM_SERVICE_NOT_AVAILABLE;
        }
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_RECEIVESIGNAL, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

    return checkRet;
}

/*
********************************************************************************
* Function Name: Com_ReceiveDynSignal
*
* Explanation: Com_ReceiveDynSignal copies the data of the signal identified by
*              SignalId to the location specified by SignalDataPtr and stores the
*              length of the dynamical length signal at the position given by the Length parameter.
*
* param: SignalId : Id of signal to be received.
*        SignalDataPtr:reference to the location where the received signal data shall be stored.
*        Length: in: maximum length that could be received out: length of the dynamic length signal.
*
* retval: retVal: E_OK: service has been accepted.
*                 E_NOT_OK: in case the Length is greater than the configured
*                   ComSignalLength of this sent signal.
*                 COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped
*                   (or service failed due to development error).
*                 COM_BUSY: in case the TP-Buffer is locked.
********************************************************************************
*/
FUNC(uint8, COM_CODE) Com_ReceiveDynSignal  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    Com_SignalIdType SignalId,
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
    P2VAR(uint16, AUTOMATIC, COM_APPL_DATA) Length
)
{
    uint8 retVal = COM_SERVICE_NOT_AVAILABLE;
    uint16 dynSignalLength;

    uint8 errorId = COM_E_NO_ERROR;

    if( COM_INIT != Com_Initialized ) /* Com module not initial. */
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
    else if( COM_RXSIG_NUM <= SignalId )/* Signal Id overflow. */
    {
        /* Set Det errorId COM_E_PARAM. */
        errorId = COM_E_PARAM;
    }
    else if( NULL_PTR == SignalDataPtr ) /* Null Pointer. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        /* Set Det errorId COM_E_PARAM_POINTER. */
        errorId = COM_E_PARAM_POINTER;
    }
    else if( NULL_PTR == Length ) /* Null Pointer. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        /* Set Det errorId COM_E_PARAM_POINTER. */
        errorId = COM_E_PARAM_POINTER;
    }
    else
    {
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        if( NULL_PTR != Com_RxSignalInfo[SignalId].astSignalInterMonitor )
        {
            dynSignalLength = Com_RxSignalInfo[SignalId].astSignalInterMonitor->acDynSignalLength;
            /* Check the length */
            /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" */
            if( *Length >= dynSignalLength )
            {
                /* Copy the dynamic ComSignal value to the passed signal data location and
                   set the passed Length pointer to the current dynamic ComSignal length. */
                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                Com_Memcpy((uint8*)SignalDataPtr, (uint8*)(Com_RxSignalInfo[SignalId].sigRTEValue), dynSignalLength);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                *Length = (uint16) dynSignalLength;
                retVal = E_OK;
            }
            else
            {
                /* the Length is smaller than the received length of the dynamic length signal,
                   shall not copy any data. */
                errorId = COM_E_PARAM;
                /* length of the dynamic length signal. */
                *Length = (uint16) dynSignalLength;
                retVal = E_NOT_OK;
            }

            /* SWS_Com_00690 */
            if( COM_PDU_INACTIVE == Com_RxPduInfo[Com_RxSignalInfo[SignalId].acPduID].astPduInterMonitor->pduSta )
            {
                retVal = COM_SERVICE_NOT_AVAILABLE;
            }
        }
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_RECEIVEDYNSIGNAL, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

    return retVal;
}

/*
********************************************************************************
* Function Name: Com_SendSignalGroup
*
* Explanation: The service Com_SendSignalGroup copies the content of the associated
*              shadow buffer to the associated I-PDU.
*
* param: SignalGroupId: Id of signal group to be sent.
*
* retval: RtrnValu: E_OK: service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped
*                                          (or service failed due to development error).
*                COM_BUSY: in case the TP-Buffer is locked for large data types handling.
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint8, COM_CODE) Com_SendSignalGroup( Com_SignalGroupIdType SignalGroupId )  /* PRQA S 1505 */ /* NSCA_QAC_Common_Rule8.7 */
{
    uint8 RtrnValu = COM_SERVICE_NOT_AVAILABLE;
    uint8 errorId = COM_E_NO_ERROR;

    if( COM_INIT != Com_Initialized ) /* Com module not initial. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
#if( COM_TXSIGGROUPINFO == STD_ON )
    else if( COM_TXGRP_NUM <= SignalGroupId )/* Signal Group Id overflow. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        /* Set Det errorId COM_E_PARAM. */
        errorId = COM_E_PARAM;
    }
#endif  /*  #if( COM_TXSIGGROUPINFO == STD_ON ) */
    else
    {
        COM_DUMMY_STATEMENT(SignalGroupId);
#if( COM_TXSIGGROUPINFO == STD_ON )
        /* Send signal Group process. */
        RtrnValu = Com_SendSigGrp_Process(SignalGroupId);
#if( COM_TXSIGNALFILTER_SUPPORTED == STD_ON )
        /* Send Group signal filter process. */
        Com_TxGroupSignalFilter_Process(SignalGroupId);
#endif  /* COM_TXSIGNALFILTER_SUPPORTED == STD_ON */
        if( COM_PDU_STA_INACTIVE
            == Com_TxPduInfo[Com_TxSigGrpInfo[SignalGroupId].awPduId].astPduInterMonitor->pduSta )
        {
            RtrnValu = COM_SERVICE_NOT_AVAILABLE;
        }
#endif  /* COM_TXSIGGROUPINFO == STD_ON */
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_SENDSIGNALGROUP, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

    return RtrnValu;

}

/* PolySpace +1 MISRA-C3:20.9 [Justified:Unset] "NSCA_Polyspace_Com_20.9" */
#if( COM_SIGGRP_RTEGROUP_OPERATE == STD_ON )
/*
********************************************************************************
* Function Name: Com_ReceiveSignalGroupOpt
*
* Explanation: Com_ReceiveSignalGroupOpt copies the data of the signal group
*              identified by SignalGroupId to the location specified by dataPtr.
*
* param: SignalGroupId: Id of signal group to be received.
*        dataPtr: Reference to the location where the received data shall be stored.
*        length: Received data length.
*
* retval: checkRet: E_OK: service has been accepted.
*                   COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped
*                                              (or service failed due to development error).
*                   COM_BUSY: in case the TP-Buffer is locked for large data types handling.
********************************************************************************
*/
FUNC(uint8, COM_CODE) Com_ReceiveSignalGroupOpt
(
    Com_SignalGroupIdType signalGroupId,
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) dataPtr,
    uint32 length
)
{
#if( COM_DEV_ERROR_REPORT == STD_ON )
    uint8 errorId = COM_E_NO_ERROR;
#endif

    uint8 checkRet = COM_SERVICE_NOT_AVAILABLE;
#if( COM_RXSIGGROUPINFO == STD_ON )
    uint16 pduId = COM_INIT_ZERO;
    const COM_RxPduInfo_st* PduInfo = Com_RxPduInfo;
#endif  /* COM_RXSIGGROUPINFO == STD_ON */

#if( COM_DEV_ERROR_REPORT == STD_ON )
    if( COM_INIT != Com_Initialized ) /* Com module not initial. */
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
    else if( COM_RXGRP_NUM <= signalGroupId ) /* Signal Id overflow. */
    {
        /* Set Det errorId COM_E_PARAM. */
        errorId = COM_E_PARAM;
    }
    else if( NULL_PTR == dataPtr )  /* Null Pointer. */
    {
        /* Set Det errorId COM_E_PARAM_POINTER. */
        errorId = COM_E_PARAM_POINTER;
    }
    else
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */
    {
#if( COM_RXSIGGROUPINFO == STD_ON )
        /* Get pduId for the signal group. */
        pduId = Com_RxSigGrpInfo[signalGroupId].awPduId;
        /* Determine whether this signal group has received valid data. */
        if( (uint8)COM_SIGGRP_VALID == *(Com_RxSigGrpInfo[signalGroupId].receiveDataSta) )
        {
            if( (NULL_PTR != PduInfo[pduId].pduTpMonitor)
                && (COM_PDU_TPCONNECTION_YES == PduInfo[pduId].pduTpMonitor->pduTpConnection) )
            {
                /* in case the TP-Buffer is locked for large data types handling. */
                checkRet = COM_BUSY;
            }
            else
            {
                /* receive signal group process. */
                Com_Memcpy32((uint8*)dataPtr, (uint8*)(Com_RxSigGrpInfo[signalGroupId].acSigGrpValue), length);
                checkRet = E_OK;
            }
        }
        /* Pdu state is INACTIVE. */
        if( COM_PDU_INACTIVE == PduInfo[pduId].astPduInterMonitor->pduSta )
        {
            checkRet = COM_SERVICE_NOT_AVAILABLE;
        }
#else  /* COM_RXSIGGROUPINFO == STD_ON */
        COM_DUMMY_STATEMENT(signalGroupId);
        COM_DUMMY_STATEMENT(length);
        COM_DUMMY_STATEMENT(dataPtr);
#endif  /* COM_RXSIGGROUPINFO == STD_ON */
    }
    return checkRet;
}
#endif  /* COM_SIGGRP_RTEGROUP_OPERATE == STD_ON */

/*
********************************************************************************
* Function Name: Com_ReceiveSignalGroup
*
* Explanation: The service Com_ReceiveSignalGroup copies the received signal group
*              from the I-PDU to the shadow buffer.
*
* param: SignalGroupId :Id of signal group to be received.
*
* retval: checkRet: E_OK: service has been accepted.
*                   COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped
*                                              (or service failed due to development error).
*                   COM_BUSY: in case the TP-Buffer is locked for large data types handling.
********************************************************************************
*/
FUNC(uint8, COM_CODE) Com_ReceiveSignalGroup( Com_SignalGroupIdType SignalGroupId )  /* PRQA S 3206, 1503*/ /* NSCA_QAC_Com_Rule2.7, NSCA_QAC_Common_Unreachable */
{
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
    uint8 checkRet = E_OK;
#else  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
    uint8 errorId = COM_E_NO_ERROR;
    uint8 checkRet = COM_SERVICE_NOT_AVAILABLE;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.5" */
    uint16 pduId = COM_INIT_ZERO;
    const COM_RxPduInfo_st* PduInfo = Com_RxPduInfo;

    COM_DUMMY_STATEMENT(SignalGroupId);
    COM_DUMMY_STATEMENT(pduId);
    COM_DUMMY_STATEMENT(PduInfo);

    if( COM_INIT != Com_Initialized ) /* Com module not initial. */
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
#if( COM_RXSIGGROUPINFO == STD_ON )
    else if( COM_RXGRP_NUM <= SignalGroupId ) /* Signal Group Id overflow. */
    {
        /* Set Det errorId COM_E_PARAM. */
        errorId = COM_E_PARAM;
    }
#endif  /* COM_RXSIGGROUPINFO == STD_ON */
    else
    {
#if( COM_RXSIGGROUPINFO == STD_ON )
        /* Gets the ID for the signal group. */
        pduId = Com_RxSigGrpInfo[SignalGroupId].awPduId;

        if( (NULL_PTR != PduInfo[pduId].pduTpMonitor)
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            && (COM_PDU_TPCONNECTION_YES == PduInfo[pduId].pduTpMonitor->pduTpConnection) )
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        {
            /* in case the TP-Buffer is locked for large data types handling. */
            checkRet = COM_BUSY;
        }
        else
        {
            /* receive signal group process. */
            checkRet = Com_ReceiveSignalGroup_Process(SignalGroupId);
        }

        /* Pdu state is INACTIVE. */
        if( COM_PDU_INACTIVE == PduInfo[pduId].astPduInterMonitor->pduSta )
        {
            checkRet = COM_SERVICE_NOT_AVAILABLE;
        }
#endif  /* COM_RXSIGGROUPINFO == STD_ON */

    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_RECEIVESIGNALGROUP, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
    return checkRet;
}

#if( COM_SIGNALGROUPARRAY_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Com_SendSignalGroupArray
*
* Explanation: The service Com_SendSignalGroupArray copies the content of the provided
*              Sig-nalGroupArrayPtr to the associated I-PDU. The provided data shall
*              correspond to the array representation of the signal group.
*
* param: SignalGroupId: Id of signal group to be sent.
*        SignalGroupArrayPtr: Reference to the signal group array.
*
* retval: RtrnValu: E_OK: service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group is stop-ped, no
*                                    ComSignalDataInvalidValue is configured for
*                                    the given signalId or service fails due to
*                                    development error.
*                COM_BUSY: in case the TP-Buffer is locked.
********************************************************************************
*/
FUNC(uint8, COM_CODE) Com_SendSignalGroupArray  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    Com_SignalGroupIdType SignalGroupId,
    P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) SignalGroupArrayPtr
)
{
    boolean sigValChangeFlag = FALSE;
    uint8 RtrnValu = COM_SERVICE_NOT_AVAILABLE;
    uint16 index = COM_INIT_ZERO;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxSigGrpInfo_st* sigGrpInfoPtr = Com_TxSigGrpInfo;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxPduInfo_st* PduInfo = Com_TxPduInfo;
    uint8 errorId = COM_E_NO_ERROR;

    if( COM_INIT != Com_Initialized ) /* Com module not initial. */
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
#if( COM_TXSIGGROUPINFO == STD_ON )
    else if( SignalGroupId >= COM_TXGRP_NUM ) /* Signal Group Number overflow. */
    {
        /* Set Det errorId COM_E_PARAM. */
        errorId = COM_E_PARAM;
    }
#endif
    else if( NULL_PTR == SignalGroupArrayPtr ) /* Null Pointer. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        /* Set Det errorId COM_E_PARAM_POINTER. */
        errorId = COM_E_PARAM_POINTER;
    }
    else if( FALSE == sigGrpInfoPtr[SignalGroupId].sigGrpArrayAccess )
    {
        /* Set Det errorId COM_E_PARAM. */
        errorId = COM_E_PARAM;
    }
    else
    {
#if( COM_TXSIGGROUPINFO == STD_ON )
        if( (NULL_PTR != PduInfo[sigGrpInfoPtr[SignalGroupId].awPduId].pduTpMonitor)
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            && (COM_PDU_TPCONNECTION_YES == PduInfo[sigGrpInfoPtr[SignalGroupId].awPduId].pduTpMonitor->pduTpConnection) )
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        {
            /* In case the TP-Buffer is locked for large data types handling. */
            RtrnValu = COM_BUSY;
        }
        else
        {
            for( index = sigGrpInfoPtr[SignalGroupId].sigGrpStartByte;
                index < sigGrpInfoPtr[SignalGroupId].sigGrpEndByte; index++ )
            {
                /* copies the content of the provided Sig-nalGroupArrayPtr to the associated I-PDU. */
                /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                if( PduInfo[sigGrpInfoPtr[SignalGroupId].awPduId].dataRaw[index] != SignalGroupArrayPtr[index - sigGrpInfoPtr[SignalGroupId].sigGrpStartByte] )
                {
                    PduInfo[sigGrpInfoPtr[SignalGroupId].awPduId].dataRaw[index] = SignalGroupArrayPtr[index - sigGrpInfoPtr[SignalGroupId].sigGrpStartByte];
                    sigValChangeFlag = TRUE;
                }
            }
#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
            /* Set updatebit. */
            if( COM_SIG_NO_UPDATEBIT_DEF != sigGrpInfoPtr[SignalGroupId].updateBitSigIndex )
            {
                Com_SigTxSetUb(sigGrpInfoPtr[SignalGroupId].updateBitSigIndex, sigGrpInfoPtr[SignalGroupId].awPduId);
            }
#endif  /* COM_TXUPDATEBITCFG_SUPPORT == STD_ON */
                if( NULL_PTR != PduInfo[sigGrpInfoPtr[SignalGroupId].awPduId].pduTriggerMonitor )
            {
                /* Set the sending state of the message. */
                /* PolySpace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_Com_16.1" */
                switch( sigGrpInfoPtr[SignalGroupId].sigTransferProperty )
                {
                    case COM_TRANS_PENDING:
                        break;
                    case COM_TRANS_TRIGGERED:
                        PduInfo[sigGrpInfoPtr[SignalGroupId].awPduId].pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_ACTIVE;
                        break;
                    case COM_TRANS_TRIGGERED_ON_CHG:
                        if( (boolean)TRUE == sigValChangeFlag )
                        {
                            PduInfo[sigGrpInfoPtr[SignalGroupId].awPduId].pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_ACTIVE;
                        }
                        break;
                    case COM_TRANS_TRIGGERED_ON_CHG_WR:
                        if( (boolean)TRUE == sigValChangeFlag )
                        {
                            PduInfo[sigGrpInfoPtr[SignalGroupId].awPduId].pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_ACTIVE_WP;
                        }
                        break;
                    case COM_TRANS_TRIGGERED_WR:
                        PduInfo[sigGrpInfoPtr[SignalGroupId].awPduId].pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_ACTIVE_WP;
                        break;
                    /* PolySpace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Com_DEAD_CODE" Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " PolySpace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_Com_16.4" */
                    default:
                        break;
                }
            }
            RtrnValu = E_OK;
        }
#endif  /* COM_TXSIGGROUPINFO == STD_ON */
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_SENDSIGNALGROUPARRAY, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

    return RtrnValu;

}
#endif  /* (COM_SIGNALGROUPARRAY_SUPPORT == STD_OFF) */

#if( COM_SIGNALGROUPARRAY_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Com_ReceiveSignalGroupArray
*
* Explanation: The service Com_ReceiveSignalGroupArray copies the received signal
*              group array representation from the PDU to the location designated
*              by SignalGroupAr-rayPtr.
*
* param: SignalGroupId: Id of signal group to be sent.
*        SignalGroupArrayPtr: Reference to the signal group array.
*
* retval: RtrnValu:  E_OK: Service has been accepted
*                    COM_SERVICE_NOT_AVAILABLE: Corresponding I-PDU group is stopped,
*                        no ComSignalDataInvalidValue is configured for the given
*                        signalId or service fails due to development error.
*                    COM_BUSY: In case the TP-Buffer is locked.
********************************************************************************
*/
FUNC(uint8, COM_CODE) Com_ReceiveSignalGroupArray  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    Com_SignalGroupIdType SignalGroupId,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) SignalGroupArrayPtr
)
{
    uint8 RtrnValu = COM_SERVICE_NOT_AVAILABLE;
    uint16 index = COM_INIT_ZERO;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSigGrpInfo_st* sigGrpInfoPtr = Com_RxSigGrpInfo;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxPduInfo_st* PduInfo = Com_RxPduInfo;
    uint8 errorId = COM_E_NO_ERROR;

    if( COM_INIT != Com_Initialized ) /* Com module not initial. */
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
#if( COM_RXSIGGROUPINFO == STD_ON )
    else if( SignalGroupId >= COM_RXGRP_NUM ) /* Signal Group Number overflow. */
    {
        /* Set Det errorId COM_E_PARAM. */
        errorId = COM_E_PARAM;
    }
#endif
    else if( NULL_PTR == SignalGroupArrayPtr ) /* Null Pointer. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        /* Set Det errorId COM_E_PARAM_POINTER. */
        errorId = COM_E_PARAM_POINTER;
    }
    else if( FALSE == sigGrpInfoPtr[SignalGroupId].sigGrpArrayAccess )
    {
        /* Set Det errorId COM_E_PARAM. */
        errorId = COM_E_PARAM;
    }
    else
    {
#if( COM_RXSIGGROUPINFO == STD_ON )
        if( (NULL_PTR != PduInfo[sigGrpInfoPtr[SignalGroupId].awPduId].pduTpMonitor)
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            && (COM_PDU_TPCONNECTION_YES == PduInfo[sigGrpInfoPtr[SignalGroupId].awPduId].pduTpMonitor->pduTpConnection) )
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        {
            /* in case the TP-Buffer is locked for large data types handling. */
            RtrnValu = COM_BUSY;
        }
        else
        {
            for( index = sigGrpInfoPtr[SignalGroupId].sigGrpStartByte;
                index < sigGrpInfoPtr[SignalGroupId].sigGrpEndByte; index++ )
            {
                /* Copy the array to the location designated by SignalGroupArrayPtr. */
                /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                SignalGroupArrayPtr[index - sigGrpInfoPtr[SignalGroupId].sigGrpStartByte] = PduInfo[sigGrpInfoPtr[SignalGroupId].awPduId].datavalid[index];
            }
            RtrnValu = E_OK;
        }

        if( COM_PDU_INACTIVE == PduInfo[sigGrpInfoPtr[SignalGroupId].awPduId].astPduInterMonitor->pduSta )
        {
            RtrnValu = COM_SERVICE_NOT_AVAILABLE;
        }
#endif  /* COM_RXSIGGROUPINFO == STD_ON */

    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_RECEIVESIGNALGRPARRAY, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

    return RtrnValu;
}
#endif

/*
********************************************************************************
* Function Name: Com_InvalidateSignal
*
* Explanation: The service Com_InvalidateSignal invalidates the signal with the
*              given SignalId by setting its value to its configured ComSignalDataInvalidValue.
*
* param: SignalId: Tx signal index.
*
* retval: acRet: E_OK: Service has been accepted.
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group is stop-ped,
*                                           no ComSignalDataInvalidValue is configured
*                                           for the given signalId or service fails
*                                           due to development error.
*                COM_BUSY: In case the TP-Buffer is locked.
********************************************************************************
*/
FUNC(uint8, COM_CODE) Com_InvalidateSignal( Com_SignalIdType SignalId )  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    uint8 retVal = COM_SERVICE_NOT_AVAILABLE;
    Com_PduTxStaType activeSta;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.5" */
    uint16 pduId;
    uint8 errorId = COM_E_NO_ERROR;

    if( COM_INIT != Com_Initialized )/* Com module not initial. */
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
    else if( COM_TXSIG_NUM <= SignalId )/* Tx Signal Id overflow. */
    {
        /* Set Det errorId COM_E_PARAM. */
        errorId = COM_E_PARAM;
    }
    else
    {
        /* Com_InvalidateSignal shall return COM_SERVICE_NOT_AVAILABLE in
           case no ComSignalDataInvalidValue (ECUC_Com_00391) is configured for the signal with the given SignalId. */
        if( NULL_PTR == Com_TxSignalInfo[SignalId].sigValInvalidBufPtr )
        {
            retVal = COM_SERVICE_NOT_AVAILABLE;
        }
        else
        {
            pduId = Com_TxSignalInfo[SignalId].acPduId;

            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            if( NULL_PTR != Com_TxPduInfo[pduId].astPduInterMonitor )
            {
                activeSta = Com_TxPduInfo[pduId].astPduInterMonitor->pduSta;

                /* After invaliding the signal data, the function Com_Invalidate-Signal
                   shall perform a call of Com_SendSignal internally. */
                retVal = Com_SendSignal(SignalId, Com_TxSignalInfo[SignalId].sigValInvalidBufPtr);

                /* If pdu is inactive. */
                if( COM_PDU_STA_INACTIVE == activeSta )
                {
                    retVal = COM_SERVICE_NOT_AVAILABLE;
                }
            }
        }
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_INVALIDATESIGNAL, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

    return retVal;
}

/*
********************************************************************************
* Function Name: Com_InvalidateSignalGroup
*
* Explanation: The service Com_InvalidateSignalGroup invalidates all group signals
*              of the signal group with the given SignalGroupId by setting their
*              values to their configured ComSignalDataInvalidValues.

* param: SignalGroupId: Id of signal group to be sent.
*
* retval: RtrnValu: E_OK: Service has been accepted.
*                   COM_SERVICE_NOT_AVAILABLE: Corresponding I-PDU group is stopped,
*                                              no ComSignalDataInvalidValue is
*                                              configured for the given signalId
*                                              or service fails due to development error.
*                   COM_BUSY: In case the TP-Buffer is locked
********************************************************************************
*/
FUNC(uint8, COM_CODE) Com_InvalidateSignalGroup  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    Com_SignalGroupIdType SignalGroupId
)
{
    boolean flag = FALSE;
    Com_PduTxStaType activeSta = COM_PDU_STA_INACTIVE;
    uint8 retVal = COM_SERVICE_NOT_AVAILABLE;
    uint8 errorId = COM_E_NO_ERROR;

#if( COM_TXSIGGROUPINFO == STD_ON )
    uint16 signalIdx;
    uint16 signalStartIdx;
    uint16 signalEndIdx;
#endif

    COM_DUMMY_STATEMENT(SignalGroupId);
    COM_DUMMY_STATEMENT(flag);
    COM_DUMMY_STATEMENT(activeSta);

    if( COM_INIT != Com_Initialized ) /* Com module not initial. */
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
 #if( COM_TXSIGGROUPINFO == STD_ON )
    else if( COM_TXGRP_NUM <= SignalGroupId )/* Com module not initial. */
    {
        /* Set Det errorId COM_E_PARAM. */
        errorId = COM_E_PARAM;
    }
#endif  /*  #if( COM_TXSIGGROUPINFO == STD_ON ) */
    else
    {
#if( COM_TXSIGGROUPINFO == STD_ON )

        signalStartIdx = Com_TxSigGrpInfo[SignalGroupId].acSigIdxStart;
        signalEndIdx = Com_TxSigGrpInfo[SignalGroupId].acSigIdxdEnd;

        for( signalIdx = signalStartIdx; signalIdx < signalEndIdx; signalIdx++ )
        {
            /* No ComSignalDataInvalidValue is configured for the given signalId. */
            if( NULL_PTR == Com_TxSignalInfo[signalIdx].sigValInvalidBufPtr )
            {
                flag = TRUE;
                break;
            }
        }
        /* All group signals of the signal group config invalidValue. */
        if( FALSE == flag )
        {
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            if( NULL_PTR != Com_TxPduInfo[Com_TxSigGrpInfo[SignalGroupId].awPduId].astPduInterMonitor )
            {
                activeSta = Com_TxPduInfo[Com_TxSigGrpInfo[SignalGroupId].awPduId].astPduInterMonitor->pduSta;

                /* if pdu is inactive. */
                if( COM_PDU_STA_INACTIVE == activeSta )
                {
                    retVal = COM_SERVICE_NOT_AVAILABLE;
                }
                else
                {
                    /* After invaliding the signal group data, the function Com_InvalidateSignalGroup
                       shall perform a call of Com_SendSignalGroup internally. */
                    retVal = Com_SendSignalGroup(SignalGroupId);
                }
            }
        }
#endif  /* COM_TXSIGGROUPINFO == STD_ON */
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_INVALIDATESIGNALGROUP, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

    return retVal;
}

/*
********************************************************************************
* Function Name: Com_TriggerIPDUSend
*
* Explanation: By a call to Com_TriggerIPDUSend the I-PDU with the given ID is triggered for transmission.
*
* param: PduId: The I-PDU-ID of the I-PDU that shall be triggered for sending.
*
* retval: checkRet: E_OK: I-PDU was triggered for transmission.
*                    E_NOT_OK: I-PDU is stopped, the transmission could not be triggered.
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.5" */
FUNC(Std_ReturnType, COM_CODE) Com_TriggerIPDUSend( PduIdType PduId )  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    Std_ReturnType checkRet = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:9.3 [Justified:Unset] "NSCA_Polyspace_Com_9.3" */
    PduInfoType pduData = {NULL_PTR, COM_INIT_ZERO};
    uint8 errorId = COM_E_NO_ERROR;

    if( COM_INIT != Com_Initialized )/* Com module not initial. */
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
    else if( PduId >= COM_TXPDU_NUM )/* Tx Pdu Number overflow. */
    {
        errorId = COM_E_PARAM;
    }
    else
    {
        COM_DUMMY_STATEMENT(pduData);
        /* Check trigger config. */
        if( NULL_PTR != Com_TxPduInfo[PduId].pduTriggerMonitor )
        {
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            if( NULL_PTR != Com_TxPduInfo[PduId].astPduInterMonitor )
            {
                /* In case a stopped I-PDU is triggered for transmission, just E_NOT_OK is returned. */
                if( COM_PDU_STA_INACTIVE == Com_TxPduInfo[PduId].astPduInterMonitor->pduSta )
                {
                    checkRet = E_NOT_OK;
                }
                else if( (NULL_PTR != Com_TxPduInfo[PduId].pduTpMonitor)
                        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                        && (COM_PDU_TPCONNECTION_YES == Com_TxPduInfo[PduId].pduTpMonitor->pduTpConnection) )
                /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                {
                    /* In case the TP-Buffer is locked for large data types handling. */
                    checkRet = COM_BUSY;
                }
                else
                {
                    /* Shall not take into account all other transmission mode related parameters like ComTxMode-NumberOfRepetitions. */
                    Com_TxPduInfo[PduId].pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_ACTIVE_WP;

                    pduData.SduDataPtr = Com_TxPduInfo[PduId].dataRaw;
                    pduData.SduLength = Com_TxPduInfo[PduId].acPduLenth;

#if( COM_TXPDU_TRIGGERCALLOUT_SUPPORT == STD_ON )
                    /* Then the function Com_TriggerIPDUSend or Com_Trigger-IPDUSendWithMetaData repectively shall also call this I-PDU-Callout. */
                    if( NULL_PTR != Com_TxPduInfo[PduId].TriggerCallout )
                    {
                        (void)Com_TxPduInfo[PduId].TriggerCallout(PduId, &pduData);
                    }
#endif
                    checkRet = E_OK;
                }
            }
        }
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_TRIGGERIPDUSEND, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

    return checkRet;
}

#if( (COM_METADATA_SUPPORT == STD_ON) && (COM_TXMETADATA_NUM > COM_INIT_ZERO) )
/*
********************************************************************************
* Function Name: Com_TriggerIPDUSendWithMetaData
*
* Explanation: By a call to Com_TriggerIPDUSendWithMetaData the AUTOSAR COM module updates
*              its internal metadata for the I-PDU with the given ID by copying the metadata from
*              the given position and with respect to the globally configured metadata length of the I-PDU.
*
* param: PduId: The I-PDU-ID of the I-PDU that shall be triggered for sending.
*        MetaData: A pointer to the metadata for the triggered send-request.
*
* retval: retVal: E_OK: I-PDU was triggered for transmission.
*                 E_NOT_OK: I-PDU is stopped, the transmission could not be triggered.
********************************************************************************
*/
FUNC(Std_ReturnType, COM_CODE) Com_TriggerIPDUSendWithMetaData
(
    PduIdType PduId,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) MetaData
)
{
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorId = COM_E_NO_ERROR;

    if( COM_INIT != Com_Initialized )
    {
        errorId = COM_E_UNINIT;
    }
    else if( NULL_PTR == MetaData )
    {
        errorId = COM_E_PARAM_POINTER;
    }
#if( COM_TXPDU_NUM > COM_INIT_ZERO )
    else if( PduId >= COM_TXPDU_NUM )
    {
        errorId = COM_E_PARAM;
    }
    else if( COM_INIT_ZERO == Com_TxPduInfo[PduId].acMetaDataLength )
    {
        errorId = COM_E_PARAM;
    }
#endif  /* ( COM_TXPDU_NUM > COM_INIT_ZERO ) */
    else
    {
        /* [SWS_Com_00862] By a call to Com_TriggerIPDUSendWithMetaData, the AUTOSAR COM shall trigger
        the I-PDU with the given ID for transmission only if the IPDU is started. */
        if( (NULL_PTR != Com_TxPduInfo[PduId].astPduInterMonitor)
            && (COM_PDU_STA_INACTIVE == Com_TxPduInfo[PduId].astPduInterMonitor->pduSta) )
        {
            retVal = E_NOT_OK;
        }
        else
        {
            uint8 metaDataLength = Com_TxPduInfo[PduId].acMetaDataLength;
            uint16 metaDataPduIdx = Com_TxPduInfo[PduId].acMetaDataIdx;
            if( (COM_INIT_ZERO != metaDataLength) && (COM_PDU_NO_METADATA_DEF != metaDataPduIdx) )
            {
                uint8 *PtrMetaData = NULL_PTR;
#if( COM_TXPDU_TPTYPE_SUPPORT == STD_ON )
                /* [SWS_Com_00868] */
                if( (NULL_PTR != Com_TxPduInfo[PduId].pduTpMonitor)
                        && (COM_PDU_TPCONNECTION_YES == Com_TxPduInfo[PduId].pduTpMonitor->pduTpConnection) )
                {
                    /* In case the TP-Buffer is locked for large data types handling. */
                    /* [SWS_Com_00868] In case a large I-PDU is triggered for transmission by
                    Com_TriggerIPDUSendWithMetaData and the buffer of the large I-PDU is currently
                    locked, the AUTOSAR COM shall store the transmit request with the given MetaData
                    and transmit the I-PDU when the buffer is available again. */
                    PtrMetaData = Com_TxPduMonMetaData[metaDataPduIdx].tpMetaData;
                    Com_TxPduMonMetaData[metaDataPduIdx].tpBusy = TRUE;
                    retVal = E_OK;
                }
                else
#endif  /* ( COM_TXPDU_TPTYPE_SUPPORT == STD_ON ) */
                {
                    if( NULL_PTR != Com_TxPduInfo[PduId].dataRaw )
                    {
                        PtrMetaData = &Com_TxPduInfo[PduId].dataRaw[Com_TxPduInfo[PduId].acPduLenth];
                        retVal = E_OK;
                    }
                }
                if( NULL_PTR != PtrMetaData )
                {
                    /* Copy the passed meta data to the Tx ComIPdu buffer and trigger a deferred transmission */
                    uint8 metaDataIdx;
                    for( metaDataIdx = COM_INIT_ZERO; metaDataIdx < metaDataLength; metaDataIdx++ )
                    {
                        PtrMetaData[metaDataIdx] = MetaData[metaDataIdx];
                    }
                    Com_TxPduMonMetaData[metaDataPduIdx].triggerMetaDataEnable = TRUE;
                }
#if( COM_TXPDU_TRIGGERCALLOUT_SUPPORT == STD_ON )
                /* [SWS_Com_00492] If an I-PDU triggered by Com_TriggerIPDUSend or Com_TriggerIPDUSendWithMetaData
                has a configured I-PDU-callout, see ECUC_Com_00387, then the function Com_TriggerIPDUSend or
                Com_TriggerIPDUSendWithMetaData repectively shall also call this I-PDU-Callout. */
                if( NULL_PTR != Com_TxPduInfo[PduId].TriggerCallout )
                {
                    PduInfoType pduInfo;

                    pduInfo.SduDataPtr = Com_TxPduInfo[PduId].dataRaw;
                    pduInfo.SduLength = Com_TxPduInfo[PduId].acPduLenth;
                    (void)Com_TxPduInfo[PduId].TriggerCallout(PduId, &pduInfo);
                }
#endif  /* ( COM_TXPDU_TRIGGERCALLOUT_SUPPORT == STD_ON ) */
                 /* Check trigger config. */
                if( NULL_PTR != Com_TxPduInfo[PduId].pduTriggerMonitor )
                {
                    /* Shall not take into account all other transmission mode related parameters like ComTxMode-NumberOfRepetitions. */
                    Com_TxPduInfo[PduId].pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_ACTIVE_WP;
                }
            }
        }
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_TRIGGERIPDUSENDWITHMETADATA, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

    return retVal;
}
#endif  /* ( (COM_METADATA_SUPPORT == STD_ON) && (COM_TXMETADATA_NUM > COM_INIT_ZERO) ) */

/*
********************************************************************************
* Function Name: Com_SwitchIpduTxMode
*
* Explanation: The service Com_SwitchIpduTxMode sets the transmission mode of the
*              I-PDU referenced by PduId to Mode.
*
* param: PduId:Id of the I-PDU of which the transmission mode shall be changed.
*        Mode:the transmission mode that shall be set.
*
* retval: none
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.5" */
FUNC(void, COM_CODE) Com_SwitchIpduTxMode( PduIdType PduId, boolean Mode )  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    boolean lastMode;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxPduInfo_st* com_astPdu = Com_TxPduInfo;
    uint8 errorId = COM_E_NO_ERROR;

    if( COM_INIT != Com_Initialized ) /* Com module not initial. */
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
    else if( PduId >= COM_TXPDU_NUM ) /* Tx Pdu Number overflow. */
    {
        /* Set Det errorId COM_E_PARAM. */
        errorId = COM_E_PARAM;
    }
    else
    {
        /* Cehck point. */
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        if( NULL_PTR != com_astPdu[PduId].astPduInterMonitor )
        {
            /* Last send mode. */
            lastMode = com_astPdu[PduId].astPduInterMonitor->pduTxMode;

            if( lastMode != Mode )  /* Need to update. */
            {
                /* Set current tx mode. */
                com_astPdu[PduId].astPduInterMonitor->pduTxMode = Mode;
                /* Init tx mode. */
                Com_InitOneIPdu_Tx(PduId, FALSE);
            }
        }
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_SWITCHIPDUTXMODE, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

}

/*
********************************************************************************
* Function Name: Com_TriggerTransmit
*
* Explanation: Within this API, the upper layer module (called module) shall check whether the available data
*              fits into the buffer size reported by PduInfoPtr->SduLength. If it fits, it shall copy its data into
*              the buffer provided by PduInfoPtr->SduDataPtr and update the length of the actual copied data
*              in PduInfoPtr->SduLength. If not, it returns E_NOT_OK without changing PduInfoPtr.
*
* param: TxPduId: ID of the SDU that is requested to be transmitted.
*        PduInfoPtr: Contains a pointer to a buffer (SduDataPtr) to where the SDU data shall be copied,
*                    and the available buffer size in SduLengh. On return, the service will indicate the
*                    length of the copied SDU data in SduLength.
*
* retval: E_OK: SDU has been copied and SduLength indicates the number of copied bytes.
*         E_NOT_OK: No SDU data has been copied. PduInfoPtr must not be used since
*                   it may contain a NULL pointer or point to invalid data.
********************************************************************************
*/
FUNC(Std_ReturnType, COM_CODE) Com_TriggerTransmit  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
)
{
    Std_ReturnType retValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:9.3 [Justified:Unset] "NSCA_Polyspace_Com_9.3" */
    PduInfoType PduInfo = {NULL_PTR, COM_INIT_ZERO};
    uint8 errorId = COM_E_NO_ERROR;

    if( COM_INIT != Com_Initialized )/* Com module not initial. */
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
    else if( TxPduId >= COM_TXPDU_NUM ) /* Rx Pdu Number Overflow. */
    {
        /* Set Det errorId COM_E_PARAM. */
        errorId = COM_E_PARAM;
    }
    else if( NULL_PTR == PduInfoPtr ) /* Null Pointer. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        /* Set Det errorId COM_E_PARAM_POINTER. */
        errorId = COM_E_PARAM_POINTER;
    }
    else
    {
        /* In case the given PduInfoPtr->SduLength is smaller than the  actual PDU-length,
           Com_TriggerTransmit shall not copy any data and return E_NOT_OK. */
        /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" */
        if( PduInfoPtr->SduLength < Com_TxPduInfo[TxPduId].acPduLenth )
        {
            retValue = E_NOT_OK;
        }
        /* SWS_Com_00800 */
        else if( COM_PDU_STA_INACTIVE == Com_TxPduInfo[TxPduId].astPduInterMonitor->pduSta )
        {
            retValue = E_NOT_OK;
        }
        else
        {
            Com_PduTxSetVal(&Com_TxPduInfo[TxPduId]);

            PduInfo.SduDataPtr = Com_TxPduInfo[TxPduId].dataRaw;
            PduInfo.SduLength = Com_TxPduInfo[TxPduId].acPduLenth;

#if( COM_TXPDU_TRIGGERCALLOUT_SUPPORT == STD_ON )
            /* SWS_Com_00766 Invoke this I-PDU callout. */
            if( NULL_PTR != Com_TxPduInfo[TxPduId].TriggerCallout )
            {
                /* SWS_Com_00395 ignore the return value. */
                (void)Com_TxPduInfo[TxPduId].TriggerCallout(TxPduId, &PduInfo);
            }
#endif

            Com_Memcpy(PduInfoPtr->SduDataPtr, PduInfo.SduDataPtr, (uint16)PduInfo.SduLength);
            PduInfoPtr->SduLength = PduInfo.SduLength;

#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
            if( COM_PDU_CLEARUB_TRIGTRANSMIT == Com_TxPduInfo[TxPduId].acPduClearUpdateBit )
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                Com_TxPduClearUb_Process(&Com_TxPduInfo[TxPduId]);
            }
#endif

            retValue = E_OK;
        }
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_TRIGGERTRANSMIT, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

    return retValue;
}

/*
********************************************************************************
* Function Name: Com_RxIndication
*
* Explanation: Indication of a received I-PDU from a lower layer communication interface module.
*
* param: RxPduId: ID of the received I-PDU.
*        PduInfoPtr: Contains the length (SduLength) of the received I-PDU an
*                   a pointer to a buffer (SduDataPtr) containing the I-PDU.
* retval: None
********************************************************************************
*/
FUNC(void, COM_CODE) Com_RxIndication  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
)
{
    uint8 errorId = COM_E_NO_ERROR;

    if( COM_INIT != Com_Initialized )/* Com module not initial. */
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
    else if( COM_RXPDU_NUM <= RxPduId ) /* Rx Pdu Number Overflow. */
    {
        /* Set Det errorId COM_E_PARAM. */
        errorId = COM_E_PARAM;
    }
    else if( NULL_PTR == PduInfoPtr ) /* Null Pointer. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        /* Set Det errorId COM_E_PARAM_POINTER. */
        errorId = COM_E_PARAM_POINTER;
    }
    else
    {
        /* receive indication process. */
        Com_RxIndicationProcess(RxPduId,PduInfoPtr);
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_RXINDICATION, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

}

/*
********************************************************************************
* Function Name: Com_TpRxIndication
*
* Explanation: Called after an I-PDU has been received via the TP API, the result
*              indicates whe-ther the transmission was successful or not.
*
* param: id: Identification of the received I-PDU.
*        result: Result of the reception.
* retval: none

********************************************************************************
*/
FUNC(void, COM_CODE) Com_TpRxIndication( PduIdType id, Std_ReturnType result )  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    uint8 judgeResult = E_OK;
    /* PolySpace +1 MISRA-C3:9.3 [Justified:Unset] "NSCA_Polyspace_Com_9.3" */
    PduInfoType rxPduInfo = { NULL_PTR, COM_INIT_ZERO };
    uint8 errorId = COM_E_NO_ERROR;

    if( COM_INIT != Com_Initialized )    /* Com module not initial. */
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
    else if( id >= COM_RXPDU_NUM )    /*Rx Pdu Number Overflow. */
    {
        errorId = COM_E_PARAM;
    }
    else if( COM_PDU_TYPE_NORMAL == Com_RxPduInfo[id].acPduType ) /*Rx Pdu type is not TP. */
    {
        errorId = COM_E_PARAM;
    }
    else
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        if( NULL_PTR != Com_RxPduInfo[id].pduTpMonitor )
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        {
            /* Judge result of the reception. */
            if( (Std_ReturnType)E_OK != result )
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                judgeResult = E_NOT_OK;
            }
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            else if( Com_RxPduInfo[id].pduTpMonitor->tpLength != Com_RxPduInfo[id].pduTpMonitor->writtenBytesCounter )
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                judgeResult = E_NOT_OK;
            }
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            else if( (COM_WAITING_FOR_INDICATION_RXTPCONNECTIONSTATE != Com_RxPduInfo[id].pduTpMonitor->TpConnectStatus)
                /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                &&(COM_RECEPTION_STARTED_RXTPCONNECTIONSTATE != Com_RxPduInfo[id].pduTpMonitor->TpConnectStatus) )
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                judgeResult = E_NOT_OK;
            }
            else
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                /* Update received data and length. */
                rxPduInfo.SduLength = Com_RxPduInfo[id].acPduLenth;
                rxPduInfo.SduDataPtr =  Com_RxPduInfo[id].datavalid;
                /* Receiving data processing. */
                Com_RxIndicationProcess(id, &rxPduInfo);
            }

            if( (Std_ReturnType)E_OK != judgeResult ) /* Transmission failed, count 0 before. */
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                Com_RxPduInfo[id].pduTpMonitor->tpLength = COM_LENGTH_ZERO;
                Com_RxPduInfo[id].pduTpMonitor->TpConnectStatus = COM_READY_RXTPCONNECTIONSTATE;
                Com_RxPduInfo[id].pduTpMonitor->writtenBytesCounter = COM_IMCOUNTER_ZERO;
                Com_RxPduInfo[id].pduTpMonitor->pduRemainLen = (uint16)Com_RxPduInfo[id].acPduLenth;
            }
            else
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                Com_RxPduInfo[id].pduTpMonitor->TpConnectStatus = COM_READY_RXTPCONNECTIONSTATE;
                Com_RxPduInfo[id].pduTpMonitor->pduRemainLen = (uint16)Com_RxPduInfo[id].acPduLenth;
            }
        }
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_TPRXINDICATION, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

}

/*
********************************************************************************
* Function Name: Com_TxConfirmation
*
* Explanation: The lower layer communication interface module confirms the
*              transmission of an I-PDU.
*
* param: TxPduId: ID of the I-PDU that has been transmitted.
*
* retval: None
********************************************************************************
*/
FUNC(void, COM_CODE) Com_TxConfirmation( PduIdType TxPduId )  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    uint8 errorId = COM_E_NO_ERROR;

#if( COM_TXPDU_MDT_SUPPORT == STD_ON )
    const COM_TxPduInfo_st* astPduInfo = &Com_TxPduInfo[TxPduId];
#endif

    if( COM_INIT != Com_Initialized )     /* Com module not initial. */
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
    else if( TxPduId >= COM_TXPDU_NUM ) /* Tx Pdu Id overflow. */
    {
        errorId = COM_E_PARAM;
    }
    else
    {
#if( COM_TXPDU_MDT_SUPPORT == STD_ON )
        if( COM_MDTCOUNTER_ZERO != astPduInfo->acMinimumDelayTime )
        {
            /* SWS_Com_00469 (re-)load the already running minimum  delay time counter with ComMinimumDelayTime for that I-PDU. */
            /* Count MDT based on the sending mode of the PDU */
            if( (NULL_PTR != astPduInfo->astPduInterMonitor) && (TRUE == astPduInfo->astPduInterMonitor->CycSendFlag) )
            {
                /* Last transmitting mode was periodic transmitting, Enable the MDT. */
                astPduInfo->astPduInterMonitor->pduCycCntForMDT = astPduInfo->acMinimumDelayTime;
                /* MDT start. */
                astPduInfo->astPduInterMonitor->pduCycMDTState = COM_MDTFORCYC_START;
                /* Reset transmission mode flag. */
                astPduInfo->astPduInterMonitor->CycSendFlag = FALSE;
            }
            else if( (NULL_PTR != astPduInfo->pduTriggerMonitor) && (TRUE == astPduInfo->pduTriggerMonitor->TriggerSendFlag) )
            {
                /* Last transmitting mode was trigger transmitting, Enable the MDT. */
                astPduInfo->pduTriggerMonitor->pduTrgCycCntForMDT = astPduInfo->acMinimumDelayTime;
                /* MDT start. */
                astPduInfo->pduTriggerMonitor->pduTrgMDTState = COM_MDTFORTRG_START;
                /* Reset transmission mode flag. */
                astPduInfo->pduTriggerMonitor->TriggerSendFlag = FALSE;
            }
            else
            {
                /*Do nothing.*/
            }
        }
#endif
        /* Tx confirmation. */
        Com_TxConfirmationProcess(TxPduId);
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_TXCONFIRMATION, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */
    COM_DUMMY_STATEMENT(TxPduId);
}

/*
********************************************************************************
* Function Name: Com_TpTxConfirmation
* Explanation: This function is called after the I-PDU has been transmitted
*              on its network, the result indicates whether the transmission was
*              successful or not.
*
* param: id: Identification of the transmitted I-PDU.
*        result: Result of the transmission of the I-PDU.
*
* retval: None
********************************************************************************
*/
FUNC(void, COM_CODE) Com_TpTxConfirmation( PduIdType id, Std_ReturnType result )  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    uint8 errorId = COM_E_NO_ERROR;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxPduInfo_st* astPduInfo = &Com_TxPduInfo[id];

    if( COM_INIT != Com_Initialized )     /* Com module not initial. */
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
    else if( id >= COM_TXPDU_NUM ) /* Tx Pdu Id overflow. */
    {
        errorId = COM_E_PARAM;
    }
    else
    {
        if( NULL_PTR != Com_TxPduInfo[id].pduTpMonitor )
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        {
#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
            /* Clearing the update bit is done by sending txconfirmation. */
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            if( COM_PDU_CLEARUB_TXCFM == astPduInfo->acPduClearUpdateBit )
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                Com_TxPduClearUb_Process(astPduInfo);
            }
#endif
            /* if Pdu Signal Process is Immedaite ,call notification. */
            if( COM_PDU_SIGPRCS_IMMEDIATE == astPduInfo->acSignalProcessType )
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                /* if pdu active, process the continued */
                /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                if( COM_PDU_STA_INACTIVE != astPduInfo->astPduInterMonitor->pduSta )
                /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                {
                    /* Set the state of the Tx ComIPdu to active. */
                    astPduInfo->astPduInterMonitor->pduSta = COM_PDU_STA_ACTIVE;
                }
                /* If result indicates the transmission was successful. */
#if( COM_TXPDU_CBKNOTIFTY_SUPPORT == STD_ON )
                if( (Std_ReturnType)E_OK == result )
                {
                    Com_TxCfrmNotifition_Process(id);
                }
#endif
            }
            else
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                /* if pdu active, process the continued */
                /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                if( COM_PDU_STA_INACTIVE != astPduInfo->astPduInterMonitor->pduSta )
                /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                {
                    if( (Std_ReturnType)E_OK == result )
                    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                    {
                        /* Set the state of the Tx ComIPdu to confirm. */
                        astPduInfo->astPduInterMonitor->pduSta = COM_PDU_STA_CONFIRM;
                    }
                    else
                    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                    {
                        /* Set the state of the Tx ComIPdu to active. */
                        astPduInfo->astPduInterMonitor->pduSta = COM_PDU_STA_ACTIVE;
                    }
                }
            }
        

            Com_TxPduInfo[id].pduTpMonitor->pduTpConnection = COM_PDU_TPCONNECTION_NO;
            Com_TxPduInfo[id].pduTpMonitor->pduRemainLen = Com_TxPduInfo[id].acPduLenth;
        }
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_TPTXCONFIRMATION, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

}

/*
********************************************************************************
* Function Name: Com_StartOfReception
*
* Explanation: This function is called at the start of receiving an N-SDU.
*              The N-SDU might be fragmented into multiple N-PDUs or might consist of a single N-PDU.
*
* param: id: Identification of the I-PDU.
*        info: Pdu Information.
*        TpSduLength: Total length of the N-SDU to be received.
*        bufferSizePtr:Buffer Size Pointer.
*
* retval: bufReq_status: BUFREQ_OK: Connection has been accepted.
*                        BUFREQ_E_NOT_OK: Connection has been rejected;
*                                         reception is aborted. bufferSizePtr remains unchanged.
*                        BUFREQ_E_OVFL: No buffer of the required length can be provided.
*                                       reception is aborted. bufferSizePtr remains unchanged.
********************************************************************************
*/
FUNC(BufReq_ReturnType, COM_CODE) Com_StartOfReception  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;
    uint8 errorId = COM_E_NO_ERROR;

    if( COM_INIT != Com_Initialized )/* Com module not initial. */
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
    else if( NULL_PTR == info )   /* Null Pointer. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        errorId = COM_E_PARAM_POINTER;
    }
    else if( NULL_PTR == bufferSizePtr ) /* Null Pointer. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        errorId = COM_E_PARAM_POINTER;
    }
    /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_ARRAY_INDEX" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_Com_OBAI" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
    else if( COM_PDU_TYPE_NORMAL == Com_RxPduInfo[id].acPduType ) /* Pdu type is not Tp Type. */
    {
        errorId = COM_E_PARAM;
    }
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    else if( COM_PDU_INACTIVE == Com_RxPduInfo[id].astPduInterMonitor->pduSta )
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        errorId = COM_E_PARAM;
    }
    else
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        if( NULL_PTR != Com_RxPduInfo[id].pduTpMonitor )
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        {
            /* If the current state of the passed Rx Tp ComIPdu is READY. */
            if( COM_READY_RXTPCONNECTIONSTATE == Com_RxPduInfo[id].pduTpMonitor->TpConnectStatus )
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" */
                if( TpSduLength <= (Com_RxPduInfo[id].acPduLenth - info->SduLength) )
                /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                {
                    /* Connection has been accepted. bufferSizePtr indicates the available receive buffer;
                       reception is continued. */
                    Com_RxPduInfo[id].pduTpMonitor->tpLength = TpSduLength;
                    Com_RxPduInfo[id].pduTpMonitor->writtenBytesCounter = COM_IMCOUNTER_ZERO;
                    Com_RxPduInfo[id].pduTpMonitor->TpConnectStatus = COM_RECEPTION_STARTED_RXTPCONNECTIONSTATE;
                    /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" */
                    *bufferSizePtr = Com_RxPduInfo[id].pduTpMonitor->pduRemainLen;
                    retVal = BUFREQ_OK;
                }
                else
                /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                {
                    /* No buffer of the required length can be provided;
                       reception is aborted. bufferSizePtr remains unchanged. */
                    /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" */
                    *bufferSizePtr = Com_RxPduInfo[id].acPduLenth;
                    errorId = COM_E_PARAM;
                    retVal = BUFREQ_E_OVFL;
                }
            }
            else    /* Otherwise set the Rx Tp ComIPdu state to READY. */
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                Com_RxPduInfo[id].pduTpMonitor->TpConnectStatus = COM_READY_RXTPCONNECTIONSTATE;
                errorId = COM_E_PARAM;
            }
        }
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_STARTOFRECEPTION, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

    return retVal;
}

/*
********************************************************************************
* Function Name: Com_CopyRxData
*
* Explanation: This function is called to provide the received data of an I-PDU
*              segment (N-PDU) to the upper layer.
* param: id: Identification of the received I-PDU.
*        info: Provides the source buffer (SduDataPtr) and the number of bytes to be copied (SduLength).
*              An SduLength of 0 can be used to query the current amount of
*              available buffer in the upper layer module. In this case, the
*              SduDataPtr may be a NULL_PTR.
*        bufferSizePtr: Available receive buffer after data has been copied.
*
* retval: bufReq_status: BUFREQ_OK: Connection has been accepted. bufferSizePtr
*                          indicates the available receive buffer; reception is continued.
*                          If no buffer of the requested size is available, a receive
*                          buffer size of 0 shall be indicated by bufferSizePtr.
*                        BUFREQ_E_NOT_OK: Connection has been rejected; reception
*                          is aborted. bufferSizePtr remains unchanged.
*                        BUFREQ_E_OVFL: No buffer of the required length can be
*                          provided; reception is aborted. bufferSizePtr remains unchanged
********************************************************************************
*/
FUNC(BufReq_ReturnType, COM_CODE) Com_CopyRxData  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;
    uint16 index;
    uint16 pduRemainLen;
    uint16 writeLen;
    PduLengthType writeAllLen;
    const COM_RxPduInfo_st* PduInfo = NULL_PTR;
    uint8 errorId = COM_E_NO_ERROR;

    if( COM_INIT != Com_Initialized ) /* Com module not initial. */
    {
        errorId = COM_E_UNINIT;
    }
    else if( NULL_PTR == info ) /* Null pointer. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        errorId = COM_E_PARAM_POINTER;
    }
    else if( NULL_PTR == bufferSizePtr ) /* Null pointer. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        errorId = COM_E_PARAM_POINTER;
    }
    /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_ARRAY_INDEX" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_Com_OBAI" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
    else if( COM_PDU_TYPE_NORMAL == Com_RxPduInfo[id].acPduType ) /* Pdu type is not Tp Type. */
    {
        errorId = COM_E_PARAM;
    }
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    else if( COM_PDU_INACTIVE == Com_RxPduInfo[id].astPduInterMonitor->pduSta )
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        errorId = COM_E_PARAM;
    }
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    else if( NULL_PTR == Com_RxPduInfo[id].pduTpMonitor ) /* Null pointer. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        errorId = COM_E_PARAM;
    }
    else
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        PduInfo = &Com_RxPduInfo[id];
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        if( (PduInfo->acPduLenth == PduInfo->pduTpMonitor->pduRemainLen)&&
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            (COM_RECEPTION_STARTED_RXTPCONNECTIONSTATE == PduInfo->pduTpMonitor->TpConnectStatus) )
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        {
            PduInfo->pduTpMonitor->TpConnectStatus = COM_COPYING_RXTPCONNECTIONSTATE;
        }

        if( COM_COPYING_RXTPCONNECTIONSTATE == PduInfo->pduTpMonitor->TpConnectStatus )
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        {
            /* This function might be called in interrupt context.
               Therefore, data consistency must be ensured. */
            pduRemainLen = PduInfo->pduTpMonitor->pduRemainLen;
            writeLen = (uint16)info->SduLength;
            writeAllLen = PduInfo->acPduLenth;
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            if( (writeAllLen >= pduRemainLen) && (pduRemainLen >= writeLen) )
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                for( index = COM_INIT_ZERO; index < writeLen; index++ )
                /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                {
                    PduInfo->datavalid[writeAllLen - pduRemainLen + index] = info->SduDataPtr[index];
                }
                PduInfo->pduTpMonitor->pduRemainLen = pduRemainLen - writeLen;
                /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" */
                *bufferSizePtr = (PduLengthType)(PduInfo->pduTpMonitor->pduRemainLen);
                PduInfo->pduTpMonitor->writtenBytesCounter += info->SduLength;

                /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                if( PduInfo->pduTpMonitor->writtenBytesCounter
                    == Com_RxPduInfo[id].pduTpMonitor->tpLength )
                /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                {
                    PduInfo->pduTpMonitor->TpConnectStatus = COM_WAITING_FOR_INDICATION_RXTPCONNECTIONSTATE;
                }
                retVal = BUFREQ_OK;
            }
        }
        else
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        {
            PduInfo->pduTpMonitor->TpConnectStatus = COM_READY_RXTPCONNECTIONSTATE;
        }
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_COPYRXDATA, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

    return retVal;
}

/*
********************************************************************************
* Function Name: Com_CopyTxData
*
* Explanation: This function is called to acquire the transmit data of an
*              I-PDU segment (N-PDU).
*
* param: id: Tp Pdu Id.
*        info: Tp Pdu Info.
*        retry: retry information.
*        availableDataPtr: available Length.
*
* retval: bufReq_status: BUFREQ_OK: Connection has been accepted. bufferSizePtr
*                          indicates the available receive buffer; reception is continued.
*                          If no buffer of the requested size is available, a receive
*                          buffer size of 0 shall be indicated by bufferSizePtr.
*                        BUFREQ_E_NOT_OK: Connection has been rejected; reception
*                          is aborted. bufferSizePtr remains unchanged.
*                        BUFREQ_E_OVFL: No buffer of the required length can be
*                          provided; reception is aborted. bufferSizePtr remains unchanged.
********************************************************************************
*/
FUNC(BufReq_ReturnType, COM_CODE) Com_CopyTxData  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) info,
    P2VAR(RetryInfoType, AUTOMATIC, COM_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) availableDataPtr
)
{
    BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;
    uint8 errorId = COM_E_NO_ERROR;
    uint16 pduRemainLen;
    uint16 index;
    uint16 writeLen;
    uint16 writeAllLen;
    const COM_TxPduInfo_st* PduInfo = NULL_PTR;

    COM_DUMMY_STATEMENT(retry);
    if( COM_INIT != Com_Initialized ) /* Com module not initial. */
    {
        /* Set Det errorId COM_E_UNINIT. */
        errorId = COM_E_UNINIT;
    }
    else if( id >= COM_TXPDU_NUM ) /* Null pointer. */
    {
        errorId = COM_E_PARAM;
    }
    else if( NULL_PTR == Com_TxPduInfo[id].pduTpMonitor ) /* Null pointer. */
    {
        errorId = COM_E_PARAM;
    }
    /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    else if( (NULL_PTR == info) || (NULL_PTR == info->SduDataPtr) ) /* Null pointer. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        errorId = COM_E_PARAM_POINTER;
    }
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    else if( NULL_PTR == availableDataPtr ) /* Null pointer. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        errorId = COM_E_PARAM_POINTER;
    }
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    else if( COM_PDU_STA_INACTIVE == Com_TxPduInfo[id].astPduInterMonitor->pduSta )
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        errorId = COM_E_PARAM;
    }
    else
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        PduInfo = &Com_TxPduInfo[id];
        pduRemainLen = PduInfo->pduTpMonitor->pduRemainLen;
        writeLen = (uint16)info->SduLength;
        writeAllLen = PduInfo->acPduLenth;
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        if( (writeAllLen >= pduRemainLen) && (pduRemainLen >= writeLen) )
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        {
            for( index = COM_INIT_ZERO; index < writeLen; index++ )
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
               info->SduDataPtr[index] = PduInfo->dataRaw[writeAllLen - pduRemainLen + index];
            }
            PduInfo->pduTpMonitor->pduRemainLen = pduRemainLen - writeLen;
            /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" */
            *availableDataPtr = (PduLengthType)(PduInfo->pduTpMonitor->pduRemainLen);
            retVal = BUFREQ_OK;
        }
    }

#if( COM_DEV_ERROR_REPORT == STD_ON )
    /* Development Error Report. */
    Com_Det_ErrorReport(COM_SERVICEID_COPYTXDATA, errorId);
#else
    COM_DUMMY_STATEMENT(errorId);
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

    return retVal;
}

#if( COM_MULTICORE_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Com_MainFunctionRx_Can
*
* Explanation: This function performs the processing of the AUTOSAR COM module's
*              receive processing that are not directly handled within the COM's functions
*              invoked by the PDU-R, for example Com_RxIndication.
               This function handles the I-Pdu, which is related to Can
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, COM_CODE) Com_MainFunctionRx_Can(void)
{
    uint16 pduIdx = COM_INIT_ZERO;
    uint16 com_RxPdu_Num = COM_INIT_ZERO;
    const COM_RxPduInfo_st* com_astPdu = NULL_PTR;
    uint32 coreId = GetCoreID();
    Com_PduIndexType* com_pduIdx = NULL_PTR;
    const Com_PduIndexInfo_st* com_astPduIndex = NULL_PTR;

    if( COM_INIT == Com_Initialized )
    {
        com_astPdu = Com_RxPduInfo;
        if(COM_E_OK == Com_GetPduIndex(COM_MAINFUNCTION_CAN, COM_RECEIVE, coreId, &com_astPduIndex))
        {
            com_RxPdu_Num = com_astPduIndex->pduNum;
            com_pduIdx = com_astPduIndex->pduIndex;
            /* Process all Rx Pdu. */
            for( pduIdx = COM_INIT_ZERO; pduIdx < com_RxPdu_Num; pduIdx++ )
            {
                com_astPdu += com_pduIdx[pduIdx];
                Com_PduRxProcess(com_astPdu);
                /* Do Rx deadline monitoring. */
                Com_RxDlMon_MainFunctionRx(com_astPdu);
                com_astPdu = Com_RxPduInfo;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Com_MainFunctionRx_Lin
*
* Explanation: This function performs the processing of the AUTOSAR COM module's
*              receive processing that are not directly handled within the COM's functions
*              invoked by the PDU-R, for example Com_RxIndication.
               This function handles the I-Pdu, which is related to Lin
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, COM_CODE) Com_MainFunctionRx_Lin(void)
{
    uint16 pduIdx = COM_INIT_ZERO;
    uint16 com_RxPdu_Num = COM_INIT_ZERO;
    const COM_RxPduInfo_st* com_astPdu = NULL_PTR;
    uint32 coreId = GetCoreID();
    Com_PduIndexType* com_pduIdx = NULL_PTR;
    const Com_PduIndexInfo_st* com_astPduIndex = NULL_PTR;

    if( COM_INIT == Com_Initialized )
    {
        com_astPdu = Com_RxPduInfo;
        if(COM_E_OK == Com_GetPduIndex(COM_MAINFUNCTION_LIN, COM_RECEIVE, coreId, &com_astPduIndex))
        {
            com_RxPdu_Num = com_astPduIndex->pduNum;
            com_pduIdx = com_astPduIndex->pduIndex;
            /* Process all Rx Pdu. */
            for( pduIdx = COM_INIT_ZERO; pduIdx < com_RxPdu_Num; pduIdx++ )
            {
                com_astPdu += com_pduIdx[pduIdx];
                Com_PduRxProcess(com_astPdu);
                /* Do Rx deadline monitoring. */
                Com_RxDlMon_MainFunctionRx(com_astPdu);
                com_astPdu = Com_RxPduInfo;
            }
        }
    }
}


/*
********************************************************************************
* Function Name: Com_MainFunctionTx_Fr
*
* Explanation: This function performs the processing of the AUTOSAR COM module's
*              receive processing that are not directly handled within the COM's functions
*              invoked by the PDU-R, for example Com_RxIndication.
               This function handles the I-Pdu, which is related to FlexRay
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, COM_CODE) Com_MainFunctionRx_Fr(void)
{
    uint16 pduIdx = COM_INIT_ZERO;
    uint16 com_RxPdu_Num = COM_INIT_ZERO;
    const COM_RxPduInfo_st* com_astPdu = NULL_PTR;
    uint32 coreId = GetCoreID();
    Com_PduIndexType* com_pduIdx = NULL_PTR;
    const Com_PduIndexInfo_st* com_astPduIndex = NULL_PTR;

    if( COM_INIT == Com_Initialized )
    {
        com_astPdu = Com_RxPduInfo;
        if(COM_E_OK == Com_GetPduIndex(COM_MAINFUNCTION_FR, COM_RECEIVE, coreId, &com_astPduIndex))
        {
            com_RxPdu_Num = com_astPduIndex->pduNum;
            com_pduIdx = com_astPduIndex->pduIndex;
            /* Process all Rx Pdu. */
            for( pduIdx = COM_INIT_ZERO; pduIdx < com_RxPdu_Num; pduIdx++ )
            {
                com_astPdu += com_pduIdx[pduIdx];
                Com_PduRxProcess(com_astPdu);
                /* Do Rx deadline monitoring. */
                Com_RxDlMon_MainFunctionRx(com_astPdu);
                com_astPdu = Com_RxPduInfo;
            }
        }
    }
}


/*
********************************************************************************
* Function Name: Com_MainFunctionTx_Eth
*
* Explanation: This function performs the processing of the AUTOSAR COM module's
*              receive processing that are not directly handled within the COM's functions
*              invoked by the PDU-R, for example Com_RxIndication.
               This function handles the I-Pdu, which is related to Ethernet
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, COM_CODE) Com_MainFunctionRx_Eth(void)
{
    uint16 pduIdx = COM_INIT_ZERO;
    uint16 com_RxPdu_Num = COM_INIT_ZERO;
    const COM_RxPduInfo_st* com_astPdu = NULL_PTR;
    uint32 coreId = GetCoreID();
    Com_PduIndexType* com_pduIdx = NULL_PTR;
    const Com_PduIndexInfo_st* com_astPduIndex = NULL_PTR;

    if( COM_INIT == Com_Initialized )
    {
        com_astPdu = Com_RxPduInfo;
        if(COM_E_OK == Com_GetPduIndex(COM_MAINFUNCTION_ETH, COM_RECEIVE, coreId, &com_astPduIndex))
        {
            com_RxPdu_Num = com_astPduIndex->pduNum;
            com_pduIdx = com_astPduIndex->pduIndex;
            /* Process all Rx Pdu. */
            for( pduIdx = COM_INIT_ZERO; pduIdx < com_RxPdu_Num; pduIdx++ )
            {
                com_astPdu += com_pduIdx[pduIdx];
                Com_PduRxProcess(com_astPdu);
                /* Do Rx deadline monitoring. */
                Com_RxDlMon_MainFunctionRx(com_astPdu);
                com_astPdu = Com_RxPduInfo;
            }
        }
    }
}


/*
********************************************************************************
* Function Name: Com_MainFunctionTx_Can
*
* Explanation: This function performs the processing of the AUTOSAR COM module's
*              receive processing that are not directly handled within the COM's functions
*              invoked by the PDU-R, for example Com_RxIndication.
               This function handles the I-Pdu, which is related to Can
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, COM_CODE) Com_MainFunctionTx_Can(void)
{
    uint16 pduIdx = COM_INIT_ZERO;
    uint16 com_TxPdu_Num = COM_INIT_ZERO;
    const COM_TxPduInfo_st* com_astPdu = NULL_PTR;
    uint32 coreId = GetCoreID();
    Com_PduIndexType* com_pduIdx = NULL_PTR;
    const Com_PduIndexInfo_st* com_astPduIndex = NULL_PTR;

    if( COM_INIT == Com_Initialized )
    {
        com_astPdu = Com_TxPduInfo;
        if(COM_E_OK == Com_GetPduIndex(COM_MAINFUNCTION_CAN, COM_TRANSMIT, coreId, &com_astPduIndex))
        {
            com_TxPdu_Num = com_astPduIndex->pduNum;
            com_pduIdx = com_astPduIndex->pduIndex;
            /* Process all Tx Pdu corresponding to the core id and mainfunction. */
            for( pduIdx = COM_INIT_ZERO; pduIdx < com_TxPdu_Num; pduIdx++ )
            {
                com_astPdu += com_pduIdx[pduIdx];

#if( COM_TXPDU_CBKNOTIFTY_SUPPORT == STD_ON )
                Com_TxDeferredProcess(com_pduIdx[pduIdx]);
#endif

                Com_PduTxProcess(com_astPdu);
                com_astPdu = Com_TxPduInfo;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Com_MainFunctionTx_Lin
*
* Explanation: This function performs the processing of the AUTOSAR COM module's
*              receive processing that are not directly handled within the COM's functions
*              invoked by the PDU-R, for example Com_RxIndication.
               This function handles the I-Pdu, which is related to Lin
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, COM_CODE) Com_MainFunctionTx_Lin(void)
{
    uint16 pduIdx = COM_INIT_ZERO;
    uint16 com_TxPdu_Num = COM_INIT_ZERO;
    const COM_TxPduInfo_st* com_astPdu = NULL_PTR;
    uint32 coreId = GetCoreID();
    Com_PduIndexType* com_pduIdx = NULL_PTR;
    const Com_PduIndexInfo_st* com_astPduIndex = NULL_PTR;

    if( COM_INIT == Com_Initialized )
    {
        com_astPdu = Com_TxPduInfo;
        if(COM_E_OK == Com_GetPduIndex(COM_MAINFUNCTION_LIN, COM_TRANSMIT, coreId, &com_astPduIndex))
        {
            com_TxPdu_Num = com_astPduIndex->pduNum;
            com_pduIdx = com_astPduIndex->pduIndex;
            /* Process all Tx Pdu corresponding to the core id and mainfunction. */
            for( pduIdx = COM_INIT_ZERO; pduIdx < com_TxPdu_Num; pduIdx++ )
            {
                com_astPdu += com_pduIdx[pduIdx];

#if( COM_TXPDU_CBKNOTIFTY_SUPPORT == STD_ON )
                Com_TxDeferredProcess(com_pduIdx[pduIdx]);
#endif

                Com_PduTxProcess(com_astPdu);
                com_astPdu = Com_TxPduInfo;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Com_MainFunctionTx_Fr
*
* Explanation: This function performs the processing of the AUTOSAR COM module's
*              receive processing that are not directly handled within the COM's functions
*              invoked by the PDU-R, for example Com_RxIndication.
               This function handles the I-Pdu, which is related to Flexray
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, COM_CODE) Com_MainFunctionTx_Fr(void)
{
    uint16 pduIdx = COM_INIT_ZERO;
    uint16 com_TxPdu_Num = COM_INIT_ZERO;
    const COM_TxPduInfo_st* com_astPdu = NULL_PTR;
    uint32 coreId = GetCoreID();
    Com_PduIndexType* com_pduIdx = NULL_PTR;
    const Com_PduIndexInfo_st* com_astPduIndex = NULL_PTR;

    if( COM_INIT == Com_Initialized )
    {
        com_astPdu = Com_TxPduInfo;
        if(COM_E_OK == Com_GetPduIndex(COM_MAINFUNCTION_FR, COM_TRANSMIT, coreId, &com_astPduIndex))
        {
            com_TxPdu_Num = com_astPduIndex->pduNum;
            com_pduIdx = com_astPduIndex->pduIndex;
            /* Process all Tx Pdu corresponding to the core id and mainfunction. */
            for( pduIdx = COM_INIT_ZERO; pduIdx < com_TxPdu_Num; pduIdx++ )
            {
                com_astPdu += com_pduIdx[pduIdx];

#if( COM_TXPDU_CBKNOTIFTY_SUPPORT == STD_ON )
                Com_TxDeferredProcess(com_pduIdx[pduIdx]);
#endif

                Com_PduTxProcess(com_astPdu);
                com_astPdu = Com_TxPduInfo;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Com_MainFunctionTx_Eth
*
* Explanation: This function performs the processing of the AUTOSAR COM module's
*              receive processing that are not directly handled within the COM's functions
*              invoked by the PDU-R, for example Com_RxIndication.
               This function handles the I-Pdu, which is related to Ethernet
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, COM_CODE) Com_MainFunctionTx_Eth(void)
{
    uint16 pduIdx = COM_INIT_ZERO;
    uint16 com_TxPdu_Num = COM_INIT_ZERO;
    const COM_TxPduInfo_st* com_astPdu = NULL_PTR;
    uint32 coreId = GetCoreID();
    Com_PduIndexType* com_pduIdx = NULL_PTR;
    const Com_PduIndexInfo_st* com_astPduIndex = NULL_PTR;

    if( COM_INIT == Com_Initialized )
    {
        com_astPdu = Com_TxPduInfo;
        if(COM_E_OK == Com_GetPduIndex(COM_MAINFUNCTION_ETH, COM_TRANSMIT, coreId, &com_astPduIndex))
        {
            com_TxPdu_Num = com_astPduIndex->pduNum;
            com_pduIdx = com_astPduIndex->pduIndex;
            /* Process all Tx Pdu corresponding to the core id and mainfunction. */
            for( pduIdx = COM_INIT_ZERO; pduIdx < com_TxPdu_Num; pduIdx++ )
            {
                com_astPdu += com_pduIdx[pduIdx];

#if( COM_TXPDU_CBKNOTIFTY_SUPPORT == STD_ON )
                Com_TxDeferredProcess(com_pduIdx[pduIdx]);
#endif

                Com_PduTxProcess(com_astPdu);
                com_astPdu = Com_TxPduInfo;
            }
        }
    }
}
#else
/*
********************************************************************************
* Function Name: Com_MainFunctionRx
*
* Explanation: This function performs the processing of the AUTOSAR COM module's
*              receive processing that are not directly handled within the COM's functions
*              invoked by the PDU-R, for example Com_RxIndication.
*
* param: None
*
* retval: None
********************************************************************************
*/

FUNC(void, COM_CODE) Com_MainFunction_Rx  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    uint16 ComRxPduInfoTableIndex
)
{
    uint16 pduIdx;
    uint16 pduNum;
    const COM_RxPduInfo_st* com_astPdu = NULL_PTR;
    const uint16* com_pduIdx = NULL_PTR;

    if( COM_INIT == Com_Initialized )
    {
        /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_ARRAY_INDEX" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_Com_OBAI" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        pduNum = Com_RxPduInfoTable[ComRxPduInfoTableIndex].pduNum;
        com_pduIdx = Com_RxPduInfoTable[ComRxPduInfoTableIndex].pduRxInfo;
        /* Process all Rx Pdu. */
        for( pduIdx = COM_INIT_ZERO; pduIdx < pduNum; pduIdx++ )
        {
            com_astPdu = &Com_RxPduInfo[com_pduIdx[pduIdx]];
            Com_PduRxProcess(com_astPdu);
            /* Do Rx deadline monitoring. */
            Com_RxDlMon_MainFunctionRx(com_astPdu);
        }
    }
}

/*
********************************************************************************
* Function Name: Com_MainFunction_Tx
*
* Explanation: This function performs the processing of the AUTOSAR COM module's
*              transmission activities that are not directly handled within the COM's
*              function invoked by the RTE, for example Com_SendSignal.
*
* param: ComTxPduInfoTableIndex: index of the Com_TxPduInfoTable.
*
* retval: None
********************************************************************************
*/
FUNC(void, COM_CODE) Com_MainFunction_Tx  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    uint16 ComTxPduInfoTableIndex
)
{
    uint16 pduIdx;
    uint16 index;
    uint16 pduNum;
    const COM_TxPduInfo_st* com_astPdu = NULL_PTR;

    if( COM_INIT == Com_Initialized )
    {
        /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_ARRAY_INDEX" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_Com_OBAI" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        pduNum = Com_TxPduInfoTable[ComTxPduInfoTableIndex].pduNum;
        /* Process all Tx Pdu. */
        for( index = COM_INIT_ZERO; index < pduNum; index++ )
        {
            /* get index of Com_TxPduInfo. */
            pduIdx = Com_TxPduInfoTable[ComTxPduInfoTableIndex].pduTxInfo[index];
            /* get the actual pdu pointer. */
            com_astPdu = &Com_TxPduInfo[pduIdx];

#if( COM_TXPDU_CBKNOTIFTY_SUPPORT == STD_ON )
            Com_TxDeferredProcess(pduIdx);
#endif
            Com_PduTxProcess(com_astPdu);
        }
    }
}
#endif  /* COM_MULTICORE_SUPPORT == STD_ON */

#if( COM_GWSIGNAL_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Com_MainFunction_RouteSignals
*
* Explanation: This function performs the processing of the AUTOSAR COM module's
*              receive processing that are not directly handled within the COM's
*              functions invoked by the PDU-R, for example Com_RxIndication.
* param: ComGatewayInfoTableIndex: index of Com_GatewayInfoTable.
*
* retval: void
********************************************************************************
*/
FUNC(void, COM_CODE) Com_MainFunction_RouteSignals  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    uint16 ComGatewayInfoTableIndex
)
{
#if( ( COM_GWSIGNAL_NUM > COM_INIT_ZERO ) || ( COM_GWSIGNALDSCP_NUM > COM_INIT_ZERO ) )
    uint16 mapIdx = COM_INIT_ZERO;
    uint16 actualIdx = COM_INIT_ZERO;
#endif
#if( COM_GWSIGNAL_NUM > COM_INIT_ZERO )
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const Com_GwMappingSigType* gwInfo = Com_GwInfo;
    uint16 gwInfoNum = COM_INIT_ZERO;
#endif
#if( COM_GWSIGNALDSCP_NUM > COM_INIT_ZERO )
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const Com_GwMappingSigDscpType* gwDscpInfo = Com_GwDscpInfo;
    uint16 gwDscpInfoNum = COM_INIT_ZERO;
#endif
    if( COM_INIT == Com_Initialized ) 
    {
#if( COM_GWSIGNAL_NUM > COM_INIT_ZERO )
        /* Process all Gw Pdu. */
        /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_ARRAY_INDEX" Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_Com_OBAI" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        gwInfoNum = Com_GatewayInfoTable[ComGatewayInfoTableIndex].gwInfoNum;
        for( mapIdx = COM_INIT_ZERO; mapIdx < gwInfoNum; mapIdx++ )
        {
            /* get the actual index of Com_GwInfo. */
            actualIdx = Com_GatewayInfoTable[ComGatewayInfoTableIndex].gwInfoIndexTable[mapIdx];
            Com_GwSig_Process(&gwInfo[actualIdx]);
#if( COM_GWONLYTXMODETRUE != STD_ON )
            Com_GwRefStopCycleDest(&gwInfo[actualIdx]);
#endif  /* COM_GWONLYTXMODETRUE != STD_ON */
        }
#endif
#if( COM_GWSIGNALDSCP_NUM > COM_INIT_ZERO )
        /* Process all Gw Dscp Pdu. */
        gwDscpInfoNum = Com_GatewayInfoTable[ComGatewayInfoTableIndex].gwDscpInfoNum;
        for( mapIdx = COM_INIT_ZERO; mapIdx < gwDscpInfoNum; mapIdx++ )
        {
            actualIdx = Com_GatewayInfoTable[ComGatewayInfoTableIndex].gwDscpInfoIndexTable[mapIdx];
#if( COM_MULTICORE_SUPPORT == STD_ON )
            Com_GwSigDscp_InterProcess(&gwDscpInfo[actualIdx]);
#else
            Com_GwSigDscp_Process(&gwDscpInfo[actualIdx]);
#endif  /* COM_MULTICORE_SUPPORT == STD_ON */
            Com_GwDscpStopCycleDest(&gwDscpInfo[actualIdx]);
        }
#endif  /* COM_GWSIGNALDSCP_NUM > COM_INIT_ZERO */

#if( COM_GWSIGNAL_NUM > COM_INIT_ZERO )
        /* Loop to clear COM_PDU_GW_SIG_FLAG flag of the related RX PDUs. */
        for( mapIdx = COM_INIT_ZERO; mapIdx < gwInfoNum; mapIdx++ )
        {
            actualIdx = Com_GatewayInfoTable[ComGatewayInfoTableIndex].gwInfoIndexTable[mapIdx];
            Com_GwSig_ClearRecvFlag(&gwInfo[actualIdx]);
        }
#endif  /* COM_GWSIGNAL_NUM > COM_INIT_ZERO */

#if( COM_GWSIGNALDSCP_NUM > COM_INIT_ZERO )
        /* Loop to clear COM_PDU_GW_DSCP_FLAG flag of the related RX PDUs. */
        for( mapIdx = COM_INIT_ZERO; mapIdx < gwDscpInfoNum; mapIdx++ )
        {
            actualIdx = Com_GatewayInfoTable[ComGatewayInfoTableIndex].gwDscpInfoIndexTable[mapIdx];
            Com_GwSigDscp_ClearRecvFlag(&gwDscpInfo[actualIdx]);
        }
#endif  /* COM_GWSIGNALDSCP_NUM > COM_INIT_ZERO */
    }
    COM_DUMMY_STATEMENT(ComGatewayInfoTableIndex);
}
#endif  /* COM_GWSIGNAL_SUPPORT == STD_ON */

/*
********************************************************************************
* Function Name: Com_SigTxInit
*
* Explanation: Send signal initialization.
*
* param: sigIndex: Tx signal index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_SigTxInit(uint16 sigIndex)
{
    Com_SigType txSignalType;
    uint16 sigLengthIndex;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxSignalInfo_st* txSigInfo = Com_TxSignalInfo;

    /* Obtain signal type. */
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
    txSignalType = txSigInfo[sigIndex].sigType;
#else  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
    txSignalType = Com_GetSignalType(txSigInfo[sigIndex].sigBaseInfo->sigFuncIdx);
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
    /* Judge signal type. */
    /* PolySpace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_Com_16.1" */
    switch( txSignalType )
    {
        /* Replace the value of the shaow buffer with the initial value of the signal. */
        case COM_SIGTYPE_BOOLEAN:
        /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
            *(boolean*)txSigInfo[sigIndex].sigValShadowBufPtr = *(boolean*)txSigInfo[sigIndex].sigInitValue;  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            Com_TxSigWrite_Normal(&txSigInfo[sigIndex], (uint32)(*(boolean*)txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
#if( COM_TXSIGNALFILTER_SUPPORTED == STD_ON )
            /* [SWS_Com_00603] The AUTOSAR COM module shall set the old_value of the
            filtering mechanisms for each signal to the ComSignalInitValue (ECUC_Com_00170)
            during start-up. */
            if( NULL_PTR != txSigInfo[sigIndex].sigFilterInfo )
            {
                if( NULL_PTR != txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor )
                {
                    *(boolean*)txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue
                    = *(boolean*)(txSigInfo[sigIndex].sigInitValue);
                    /* [SWS_Com_00787] If an I-PDU is started as result of a call Com_IpduGroupControl,
                       the AUTOSAR COM module shall always initialize the following attributes of this I-PDU:
                       4) reset OCCURRENCE of filter with ComFilterAlgorithm ONE_EVERY_N.
                    */
                    if( COM_ONE_EVERY_N == txSigInfo[sigIndex].sigFilterInfo->acFilterAlgorithm )
                    {
                        txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence = COM_INIT_ZERO;
                    }
                }
            }
#endif  /* (COM_TXSIGNALFILTER_SUPPORTED == STD_ON) */
            break;
        case COM_SIGTYPE_UINT8:
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
            *(uint8*)txSigInfo[sigIndex].sigValShadowBufPtr = *(uint8*)txSigInfo[sigIndex].sigInitValue;  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            Com_TxSigWrite_Normal(&txSigInfo[sigIndex], (uint32)(*(uint8*)txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
#if( COM_TXSIGNALFILTER_SUPPORTED == STD_ON )
            /* [SWS_Com_00603] The AUTOSAR COM module shall set the old_value of the
            filtering mechanisms for each signal to the ComSignalInitValue (ECUC_Com_00170)
            during start-up. */
            if( NULL_PTR != txSigInfo[sigIndex].sigFilterInfo )
            {
                if( NULL_PTR != txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor )
                {
                    *(uint8*)txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue
                    = *(uint8*)txSigInfo[sigIndex].sigInitValue;
                    /* [SWS_Com_00787] If an I-PDU is started as result of a call Com_IpduGroupControl,
                       the AUTOSAR COM module shall always initialize the following attributes of this I-PDU:
                       4) reset OCCURRENCE of filter with ComFilterAlgorithm ONE_EVERY_N.
                    */
                    if( COM_ONE_EVERY_N == txSigInfo[sigIndex].sigFilterInfo->acFilterAlgorithm )
                    {
                        txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence = COM_INIT_ZERO;
                    }
                }
            }
#endif  /* (COM_TXSIGNALFILTER_SUPPORTED == STD_ON) */
            break;
        case COM_SIGTYPE_UINT16:
            /* PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            *(uint16*)txSigInfo[sigIndex].sigValShadowBufPtr = *(uint16*)txSigInfo[sigIndex].sigInitValue;  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            Com_TxSigWrite_Normal(&txSigInfo[sigIndex], (uint32)(*(uint16*)txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
#if( COM_TXSIGNALFILTER_SUPPORTED == STD_ON )
            /* [SWS_Com_00603] The AUTOSAR COM module shall set the old_value of the
            filtering mechanisms for each signal to the ComSignalInitValue (ECUC_Com_00170)
            during start-up. */
            if( NULL_PTR != txSigInfo[sigIndex].sigFilterInfo )
            {
                if( NULL_PTR != txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor )
                {
                    *(uint16*)txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue
                    = *(uint16*)txSigInfo[sigIndex].sigInitValue;
                    /* [SWS_Com_00787] If an I-PDU is started as result of a call Com_IpduGroupControl,
                       the AUTOSAR COM module shall always initialize the following attributes of this I-PDU:
                       4) reset OCCURRENCE of filter with ComFilterAlgorithm ONE_EVERY_N.
                    */
                    if( COM_ONE_EVERY_N == txSigInfo[sigIndex].sigFilterInfo->acFilterAlgorithm )
                    {
                        txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence = COM_INIT_ZERO;
                    }
                }
            }
#endif  /* (COM_TXSIGNALFILTER_SUPPORTED == STD_ON) */
            break;
        case COM_SIGTYPE_UINT32:
            /* PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            *(uint32*)txSigInfo[sigIndex].sigValShadowBufPtr = *(uint32*)txSigInfo[sigIndex].sigInitValue;  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            Com_TxSigWrite_Normal(&txSigInfo[sigIndex], (uint32)(*(uint32*)txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
#if( COM_TXSIGNALFILTER_SUPPORTED == STD_ON )
            /* [SWS_Com_00603] The AUTOSAR COM module shall set the old_value of the
            filtering mechanisms for each signal to the ComSignalInitValue (ECUC_Com_00170)
            during start-up. */
            if( NULL_PTR != txSigInfo[sigIndex].sigFilterInfo )
            {
                if( NULL_PTR != txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor )
                {
                    *(uint32*)txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue
                    = *(uint32*)txSigInfo[sigIndex].sigInitValue;
                    /* [SWS_Com_00787] If an I-PDU is started as result of a call Com_IpduGroupControl,
                       the AUTOSAR COM module shall always initialize the following attributes of this I-PDU:
                       4) reset OCCURRENCE of filter with ComFilterAlgorithm ONE_EVERY_N.
                    */
                    if( COM_ONE_EVERY_N == txSigInfo[sigIndex].sigFilterInfo->acFilterAlgorithm )
                    {
                        txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence = COM_INIT_ZERO;
                    }
                }
            }
#endif  /* (COM_TXSIGNALFILTER_SUPPORTED == STD_ON) */
            break;
        case COM_SIGTYPE_UINT64:
            /* PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            *(uint64*)txSigInfo[sigIndex].sigValShadowBufPtr = *(uint64*)txSigInfo[sigIndex].sigInitValue;  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            Com_TxSigWrite_Large_64(&txSigInfo[sigIndex], (uint64)(*(uint64*)txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
#if( COM_TXSIGNALFILTER_SUPPORTED == STD_ON )
            /* [SWS_Com_00603] The AUTOSAR COM module shall set the old_value of the
            filtering mechanisms for each signal to the ComSignalInitValue (ECUC_Com_00170)
            during start-up. */
            if( NULL_PTR != txSigInfo[sigIndex].sigFilterInfo )
            {
                if( NULL_PTR != txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor )
                {
                    *(uint64*)txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue
                    = *(uint64*)txSigInfo[sigIndex].sigInitValue;
                }
                /* [SWS_Com_00787] If an I-PDU is started as result of a call Com_IpduGroupControl,
                       the AUTOSAR COM module shall always initialize the following attributes of this I-PDU:
                       4) reset OCCURRENCE of filter with ComFilterAlgorithm ONE_EVERY_N.
                */
                if( COM_ONE_EVERY_N == txSigInfo[sigIndex].sigFilterInfo->acFilterAlgorithm )
                {
                    txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence = COM_INIT_ZERO;
                }
            }
#endif  /* (COM_TXSIGNALFILTER_SUPPORTED == STD_ON) */
            break;
        /* Float type signals require special processing. */
        case COM_SIGTYPE_FLOAT32:
            /* PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            *(float32*)txSigInfo[sigIndex].sigValShadowBufPtr = *(float32*)txSigInfo[sigIndex].sigInitValue;  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            Com_TxSigWrite_Normal(&txSigInfo[sigIndex], (uint32)(*(uint32*)txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
            break;
        case COM_SIGTYPE_FLOAT64:
            /* PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            *(float64*)txSigInfo[sigIndex].sigValShadowBufPtr = *(float64*)txSigInfo[sigIndex].sigInitValue;  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            Com_TxSigWrite_Large_64(&txSigInfo[sigIndex], (uint64)(*(uint64*)txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
            break;
        case COM_SIGTYPE_SINT8:
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
            *(sint8*)txSigInfo[sigIndex].sigValShadowBufPtr = *(sint8*)txSigInfo[sigIndex].sigInitValue;  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            Com_TxSigWrite_Normal(&txSigInfo[sigIndex], (uint32)(*(sint8*)txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
#if( COM_TXSIGNALFILTER_SUPPORTED == STD_ON )
            /* [SWS_Com_00603] The AUTOSAR COM module shall set the old_value of the
            filtering mechanisms for each signal to the ComSignalInitValue (ECUC_Com_00170)
            during start-up. */
            if( NULL_PTR != txSigInfo[sigIndex].sigFilterInfo )
            {
                if( NULL_PTR != txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor )
                {
                    *(sint8*)txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue
                    = *(sint8*)txSigInfo[sigIndex].sigInitValue;
                    /* [SWS_Com_00787] If an I-PDU is started as result of a call Com_IpduGroupControl,
                       the AUTOSAR COM module shall always initialize the following attributes of this I-PDU:
                       4) reset OCCURRENCE of filter with ComFilterAlgorithm ONE_EVERY_N.
                    */
                    if( COM_ONE_EVERY_N == txSigInfo[sigIndex].sigFilterInfo->acFilterAlgorithm )
                    {
                        txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence = COM_INIT_ZERO;
                    }
                }
            }
#endif  /* (COM_TXSIGNALFILTER_SUPPORTED == STD_ON) */
            break;
        case COM_SIGTYPE_SINT16:
            /* PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            *(sint16*)txSigInfo[sigIndex].sigValShadowBufPtr = *(sint16*)txSigInfo[sigIndex].sigInitValue;  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            Com_TxSigWrite_Normal(&txSigInfo[sigIndex], (uint32)(*(sint16*)txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
#if( COM_TXSIGNALFILTER_SUPPORTED == STD_ON )
            /* [SWS_Com_00603] The AUTOSAR COM module shall set the old_value of the
            filtering mechanisms for each signal to the ComSignalInitValue (ECUC_Com_00170)
            during start-up. */
            if( NULL_PTR != txSigInfo[sigIndex].sigFilterInfo )
            {
                if( NULL_PTR != txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor )
                {
                    *(sint16*)txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue
                    = *(sint16*)txSigInfo[sigIndex].sigInitValue;
                    /* [SWS_Com_00787] If an I-PDU is started as result of a call Com_IpduGroupControl,
                       the AUTOSAR COM module shall always initialize the following attributes of this I-PDU:
                       4) reset OCCURRENCE of filter with ComFilterAlgorithm ONE_EVERY_N.
                    */
                    if( COM_ONE_EVERY_N == txSigInfo[sigIndex].sigFilterInfo->acFilterAlgorithm )
                    {
                        txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence = COM_INIT_ZERO;
                    }
                }
            }
#endif  /* (COM_TXSIGNALFILTER_SUPPORTED == STD_ON) */
            break;
        case COM_SIGTYPE_SINT32:
            /* PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            *(sint32*)txSigInfo[sigIndex].sigValShadowBufPtr = *(sint32*)txSigInfo[sigIndex].sigInitValue;  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            Com_TxSigWrite_Normal(&txSigInfo[sigIndex], (uint32)(*(sint32*)txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
#if( COM_TXSIGNALFILTER_SUPPORTED == STD_ON )
            /* [SWS_Com_00603] The AUTOSAR COM module shall set the old_value of the
            filtering mechanisms for each signal to the ComSignalInitValue (ECUC_Com_00170)
            during start-up. */
            if( NULL_PTR != txSigInfo[sigIndex].sigFilterInfo )
            {
                if( NULL_PTR != txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor )
                {
                    *(sint32*)txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue
                    = *(sint32*)txSigInfo[sigIndex].sigInitValue;
                    /* [SWS_Com_00787] If an I-PDU is started as result of a call Com_IpduGroupControl,
                       the AUTOSAR COM module shall always initialize the following attributes of this I-PDU:
                       4) reset OCCURRENCE of filter with ComFilterAlgorithm ONE_EVERY_N.
                    */
                    if( COM_ONE_EVERY_N == txSigInfo[sigIndex].sigFilterInfo->acFilterAlgorithm )
                    {
                        txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence = COM_INIT_ZERO;
                    }
                }
            }
#endif  /* (COM_TXSIGNALFILTER_SUPPORTED == STD_ON) */
            break;
        case COM_SIGTYPE_SINT64:
            /* PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            *(sint64*)txSigInfo[sigIndex].sigValShadowBufPtr = *(sint64*)txSigInfo[sigIndex].sigInitValue;  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            Com_TxSigWrite_Large_64(&txSigInfo[sigIndex], (uint64)(*(sint64*)txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
#if( COM_TXSIGNALFILTER_SUPPORTED == STD_ON )
            /* [SWS_Com_00603] The AUTOSAR COM module shall set the old_value of the
            filtering mechanisms for each signal to the ComSignalInitValue (ECUC_Com_00170)
            during start-up. */
            if( NULL_PTR != txSigInfo[sigIndex].sigFilterInfo )
            {
                if( NULL_PTR != txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor )
                {
                    *(sint64*)txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue
                    = *(sint64*)txSigInfo[sigIndex].sigInitValue;
                    /* [SWS_Com_00787] If an I-PDU is started as result of a call Com_IpduGroupControl,
                       the AUTOSAR COM module shall always initialize the following attributes of this I-PDU:
                       4) reset OCCURRENCE of filter with ComFilterAlgorithm ONE_EVERY_N.
                    */
                    if( COM_ONE_EVERY_N == txSigInfo[sigIndex].sigFilterInfo->acFilterAlgorithm )
                    {
                        txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence = COM_INIT_ZERO;
                    }
                }
            }
#endif  /* (COM_TXSIGNALFILTER_SUPPORTED == STD_ON) */
            break;
        case COM_SIGTYPE_UINT8_DYN:
            for( sigLengthIndex = COM_INIT_ZERO; sigLengthIndex < txSigInfo[sigIndex].sigBaseInfo->sigByteLength; sigLengthIndex++ )
            {
                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_11.5" */
                ((uint8*)txSigInfo[sigIndex].sigValShadowBufPtr)[sigLengthIndex]  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    = ((uint8*)txSigInfo[sigIndex].sigInitValue)[sigLengthIndex];  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            }
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            Com_TxSigWrite_Uint8N(&txSigInfo[sigIndex], (const uint8*)(txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            break;
        case COM_SIGTYPE_UINT8_N:
            for( sigLengthIndex = COM_INIT_ZERO; sigLengthIndex < txSigInfo[sigIndex].sigBaseInfo->sigByteLength; sigLengthIndex++ )
            {
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                ((uint8*)txSigInfo[sigIndex].sigValShadowBufPtr)[sigLengthIndex]  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    = ((uint8*)txSigInfo[sigIndex].sigInitValue)[sigLengthIndex];  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            }
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            Com_TxSigWrite_Uint8N(&txSigInfo[sigIndex], (const uint8*)(txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316 */ /* NSCA_QAC_Com_Rule11.5 */
            break;
        /* PolySpace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_Com_16.4" */
        default:
            break;
    }
    *(txSigInfo[sigIndex].sigSendSta) = COM_SIG_SENDSTA_NOSET;
#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
    if(COM_SIG_NO_UPDATEBIT_DEF != txSigInfo[sigIndex].updateBitSigIndex)
    {
        /* clear updateBit signal, in com initialization process, the update bit of signals in pdu must be zero. */
        Com_SigTxClearUb(txSigInfo[sigIndex].updateBitSigIndex, txSigInfo[sigIndex].acPduId);
    }
#endif  /* COM_TXUPDATEBITCFG_SUPPORT == STD_ON */
}

 #if( COM_TXSIGGROUPINFO == STD_ON )
/*
********************************************************************************
* Function Name: Com_SigGrpTxInit
*
* Explanation: Initialize all signal in the signal grou.
*
* param: sigGrpIndex: Index of the signal group.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_SigGrpTxInit(uint16 sigGrpIndex)
{
    uint16 sigIndex;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxSigGrpInfo_st* sigGrpInfoPtr = Com_TxSigGrpInfo;

    /* Initialize all signal in the signal group. */
    for( sigIndex = sigGrpInfoPtr[sigGrpIndex].acSigIdxStart; sigIndex < sigGrpInfoPtr[sigGrpIndex].acSigIdxdEnd; sigIndex++ )
    {
        Com_SigTxInit(sigIndex);
    }
}
#endif

/*
********************************************************************************
* Function Name: Com_InitOneIPdu_Tx
*
* Explanation: Initialize a Tx PDU.
*
* param: pduIdx: Index od Tx Pdu.
*        initialize: initialize the tx mode or not
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_InitOneIPdu_Tx(uint16 pduIdx, boolean initialize)
{
    Com_InitOneIPdu_TxMode(pduIdx, initialize);
    Com_InitOneTxIPdu_CommonCnt(pduIdx);
    Com_InitOneTxIPdu_FillUnuseArea(pduIdx);
    Com_InitOneTxIPdu_Allsig(pduIdx);
#if( (COM_METADATA_SUPPORT == STD_ON) && (COM_TXMETADATA_NUM > COM_INIT_ZERO) )
    if( COM_PDU_NO_METADATA_DEF != Com_TxPduInfo[pduIdx].acMetaDataIdx )
    {
        Com_TxPduMonMetaData[Com_TxPduInfo[pduIdx].acMetaDataIdx].triggerMetaDataEnable = FALSE;
    }
#endif  /* ( (COM_METADATA_SUPPORT == STD_ON) && (COM_TXMETADATA_NUM > COM_INIT_ZERO) ) */
}

/*
********************************************************************************
* Function Name: Com_InitOneIPdu_Rx
*
* Explanation: Initialize a Rx PDU.
*
* param: pduIdx: Index od Rx Pdu.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_InitOneIPdu_Rx(uint16 pduIdx)
{
    Com_SigType receiveSignalType;
    uint16 sigIdx;
    uint16 sigStartIdx;
    uint16 sigEndIdx;

    sigStartIdx = Com_RxPduInfo[pduIdx].awSigStartIndex;
    sigEndIdx = Com_RxPduInfo[pduIdx].awSigEndIndex;

    /* Check whether ComTimeout is configured. */
    if( COM_INIT_ZERO < Com_RxPduInfo[pduIdx].sigMinimumTimeout )
    {
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        if( NULL_PTR != Com_RxPduInfo[pduIdx].astPduInterMonitor )
        {
            /* Rx pdu cyctime couter init. */
            Com_RxPduInfo[pduIdx].astPduInterMonitor->acPduCycCounter
            = Com_RxPduInfo[pduIdx].sigMinimumFirstTimeout + COM_OPERAND_ONE;
            /* The current default listening timeout. */
            Com_RxPduInfo[pduIdx].astPduInterMonitor->enableDeadline = TRUE;
        }
    }

    /* sig with updatebit cyccounter init. */
    for( sigIdx = sigStartIdx; sigIdx < sigEndIdx; sigIdx++ )
    {
        /* Obtain signal type. */
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
        receiveSignalType = Com_RxSignalInfo[sigIdx].acSigType;
#else  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
        receiveSignalType = Com_GetSignalType(Com_RxSignalInfo[sigIdx].sigBaseInfo->sigFuncIdx);
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
        /* Evaluate Dynamic Signal. */
        if( COM_SIGTYPE_UINT8_DYN == receiveSignalType )
        {
            Com_RxSignalInfo[sigIdx].astSignalInterMonitor->acDynSignalLength
              = Com_RxSignalInfo[sigIdx].sigBaseInfo->sigByteLength;
        }
    }
    if( NULL_PTR != Com_RxPduInfo[pduIdx].astPduInterMonitor )
    {
        /* Gw cycle time couter init. */
        Com_RxPduInfo[pduIdx].astPduInterMonitor->acPduCycCounterForGw = COM_INIT_ZERO;
        Com_RxPduInfo[pduIdx].astPduInterMonitor->acPduCycCounterForGwInit = COM_INIT_ZERO;
    }
    /* Reset signal deadline counter and set the signal monitor flag. */
    Com_InitRxSignalCnt(&(Com_RxPduInfo[pduIdx]));
    /* Init Rx Buffer */
    Com_InitRxBuffer(&(Com_RxPduInfo[pduIdx]));
}

/*
********************************************************************************
* Function Name: Com_InitOneIPdu_TxMode
*
* Explanation: Initializes the sending mode of the message.
*
* param: pduIdx: Index od Tx Pdu
*        initialize: initialize the tx mode or not
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_InitOneIPdu_TxMode(uint16 pduIdx, boolean initialize)
{
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo = Com_TxPduInfo;

    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    if( NULL_PTR != PduInfo[pduIdx].astPduInterMonitor )
    {
        /* Gets the sending mode of the message. */
        if(( TRUE != PduInfo[pduIdx].astPduInterMonitor->pduGwFlag )&&((boolean)TRUE == initialize))
        {
            PduInfo[pduIdx].astPduInterMonitor->pduTxMode = Com_TxModeInfo[PduInfo[pduIdx].acTxModeIndex].acTxModeUsed;
        }

        /* Gets the corresponding message cycle. */
        if( TRUE == PduInfo[pduIdx].astPduInterMonitor->pduTxMode )
        {
            PduInfo[pduIdx].astPduInterMonitor->pduCycCounter =
                Com_TxModeTrue[Com_TxModeInfo[PduInfo[pduIdx].acTxModeIndex].acTxModeTrueIdx].acTxModeOffset + COM_OPERAND_ONE;
        }
        else
        {
            PduInfo[pduIdx].astPduInterMonitor->pduCycCounter =
                Com_TxModeFalse[Com_TxModeInfo[PduInfo[pduIdx].acTxModeIndex].acTxModeFalseIdx].acTxModeOffset + COM_OPERAND_ONE;
        }
    }
}

/*
********************************************************************************
* Function Name: Com_InitOneTxIPdu_CommonCnt
*
* Explanation: Initializes the message count.
*
* param: pduIdx: Index od Tx Pdu.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_InitOneTxIPdu_CommonCnt(uint16 pduIdx)
{
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxPduInfo_st* PduInfo = Com_TxPduInfo;

    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    if( NULL_PTR != PduInfo[pduIdx].astPduInterMonitor )
    {
        PduInfo[pduIdx].astPduInterMonitor->awPduTxTimeoutCounter = COM_INIT_ZERO;
#if( COM_TXPDU_MDT_SUPPORT == STD_ON )
        PduInfo[pduIdx].astPduInterMonitor->CycSendFlag = FALSE;
        PduInfo[pduIdx].astPduInterMonitor->pduCycDelayFlag = FALSE;
        PduInfo[pduIdx].astPduInterMonitor->pduCycCntForMDT = COM_INIT_ZERO;
        PduInfo[pduIdx].astPduInterMonitor->pduCycMDTState = COM_MDTFORCYC_INIT;
#endif
    }
    if( NULL_PTR != PduInfo[pduIdx].pduTriggerMonitor )
    {
        PduInfo[pduIdx].pduTriggerMonitor->pduSendRemainCnt = COM_INIT_ZERO;
        /* Polyspace +1 RTE:IDP [Justified:Unset] " NSCA_Polyspace_Com_IDP " */
        PduInfo[pduIdx].pduTriggerMonitor->pduTrgCycCounter = COM_INIT_ZERO;
        PduInfo[pduIdx].pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_INACTIVE;
#if( COM_TRIGRESETCYCTIMER_SUPPORT == STD_ON )
        PduInfo[pduIdx].pduTriggerMonitor->Com_ResetCycTimerFlag = FALSE;
#endif
#if( COM_TXPDU_MDT_SUPPORT == STD_ON )
        PduInfo[pduIdx].pduTriggerMonitor->pduTrgMDTState = COM_MDTFORTRG_INIT;
        PduInfo[pduIdx].pduTriggerMonitor->TriggerSendFlag = FALSE;
        PduInfo[pduIdx].pduTriggerMonitor->pduTriggerDelayFlag = FALSE;
        PduInfo[pduIdx].pduTriggerMonitor->pduTrgCycCntForMDT = COM_INIT_ZERO;
#endif
    }
    if( NULL_PTR != PduInfo[pduIdx].pduTpMonitor )
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        PduInfo[pduIdx].pduTpMonitor->pduTpConnection = COM_PDU_TPCONNECTION_NO;
        PduInfo[pduIdx].pduTpMonitor->pduRemainLen = PduInfo[pduIdx].acPduLenth;
    }
}

/*
********************************************************************************
* Function Name: Com_InitOneTxIPdu_FillUnuseArea
*
* Explanation: Fill not used areas within an I-PDU with ComTxIPduUnusedAreasDefault.
*
* param: pduIdx: Index od Tx Pdu.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_InitOneTxIPdu_FillUnuseArea(uint16 pduIdx)
{
    uint16 acPduLenthIndex;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxPduInfo_st* PduInfo = Com_TxPduInfo;

    /* The AUTOSAR COM module shall fill not used areas within an I-PDU with ComTxIPduUnusedAreasDefault. */
    for( acPduLenthIndex = COM_INIT_ZERO; acPduLenthIndex < PduInfo[pduIdx].acPduLenth; acPduLenthIndex++ )
    {
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        PduInfo[pduIdx].dataRaw[acPduLenthIndex] =
            Com_TxModeInfo[PduInfo[pduIdx].acTxModeIndex].unusedAreasDefault;
    }
}

/*
********************************************************************************
* Function Name: Com_InitOneTxIPdu_Allsig
*
* Explanation: Initializes the send signal.
*
* param: pduIdx: Index od Tx Pdu.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_InitOneTxIPdu_Allsig(uint16 pduIdx)
{
    uint16 sigIndex = COM_INIT_ZERO;

 #if( COM_TXSIGGROUPINFO == STD_ON )
    uint16 sigGrpIndex = COM_INIT_ZERO;
#endif

    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxPduInfo_st* PduInfo = Com_TxPduInfo;

    /* Initializes all signals. */
    for( sigIndex = PduInfo[pduIdx].awSigStartIndex; sigIndex < PduInfo[pduIdx].awSigEndIndex; sigIndex++ )
    {
        Com_SigTxInit(sigIndex);
    }

 #if( COM_TXSIGGROUPINFO == STD_ON )
    /* Initializes all signal groups. */
    for( sigGrpIndex = PduInfo[pduIdx].acSigGrpStartIndex; sigGrpIndex < PduInfo[pduIdx].acSigGrpEndIndex; sigGrpIndex++ )
    {
        Com_SigGrpTxInit(sigGrpIndex);
    }
#endif
}

/*
********************************************************************************
* Function Name: Com_InitIPdus_Tx
*
* Explanation: Init IPdu InterMonitor.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_InitAllIPdus_Tx(void)
{
    uint16 pduIdx;

    /* Iterate all Tx Pdu  variables. */
    for( pduIdx = COM_INIT_ZERO; pduIdx < COM_TXPDU_NUM; pduIdx++ )
    {
        Com_InitOneIPdu_Tx(pduIdx, TRUE);
    }
}

/*
********************************************************************************
* Function Name: Com_InitAllIPdus_Rx
*
* Explanation: Init IPdu InterMonitor.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_InitAllIPdus_Rx(void)
{
    uint16 pduIdx;

    /* Iterate all Rx Pdu  variables. */
    for( pduIdx = COM_INIT_ZERO; pduIdx < COM_RXPDU_NUM; pduIdx++ )
    {
        Com_InitOneIPdu_Rx(pduIdx);

        if( NULL_PTR != Com_RxPduInfo[pduIdx].pduTpMonitor )
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        {
            Com_RxPduInfo[pduIdx].pduTpMonitor->pduTpConnection = COM_PDU_TPCONNECTION_NO;
            Com_RxPduInfo[pduIdx].pduTpMonitor->pduRemainLen = (uint16)Com_RxPduInfo[pduIdx].acPduLenth;
        }
    }
}

#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Com_SigTxSetUb
*
* Explanation: Set update bit value.
*
* param: bitPos: Bit position.
*        pduId: The ID of Pdu which the signal belong to.
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.5" */
static FUNC(void, COM_CODE) Com_SigTxSetUb(uint16 bitPos, PduIdType pduId)
{
    uint16 bytePos;
    uint16 bitPosInByte;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxPduInfo_st* txPduPtr = &Com_TxPduInfo[pduId];

    /* Calculate the position of the updatebit in the array. */
    bytePos = (bitPos / COM_1BYTE_BITLENGTH);
    bitPosInByte = (bitPos % COM_1BYTE_BITLENGTH);
    /* Sets the value of the update bit. */
    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
    txPduPtr->dataRaw[bytePos] |= (uint8)(COM_OPERAND_ONE << bitPosInByte);
}
#endif  /* COM_TXUPDATEBITCFG_SUPPORT == STD_ON */

/*
********************************************************************************
* Function Name: Com_SendSignal_Process
*
* Explanation: The service updates the signal object identified by SignalId with
*              the signal referenced by the SignalDataPtr parameter.
*
* param: sigId : Id of signal to be sent.
*        sigDataPtr:  Reference to the signal data to be transmitted.
*
* retval: acRet : None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_SendSignal_Process
(
    uint16 sigId,
    P2CONST(void, AUTOMATIC, COM_APPL_CONST) sigDataPtr
)
{
    Com_SigType txSignalType;
    boolean sigValChangeFlag = FALSE;
    uint16 sigLengthIndex;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxSignalInfo_st* txSigInfo = Com_TxSignalInfo;

    /* Obtain signal type. */
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
    txSignalType = txSigInfo[sigId].sigType;
#else  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
    txSignalType = Com_GetSignalType(txSigInfo[sigId].sigBaseInfo->sigFuncIdx);
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
    /* Judge signal type. */
    /* PolySpace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_Com_16.1" */
    switch( txSignalType )
    {
        /* Assign values according to different types of signals. */
        case COM_SIGTYPE_BOOLEAN:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
            if( (*(boolean*)txSigInfo[sigId].sigValShadowBufPtr) != (*(boolean*)sigDataPtr) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            {
                sigValChangeFlag = TRUE;
                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                *(boolean*)txSigInfo[sigId].sigValShadowBufPtr = (*(boolean*)sigDataPtr)&(COM_OPERAND_ONE);  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            }
            break;
        case COM_SIGTYPE_UINT8:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
            if( (*(uint8*)txSigInfo[sigId].sigValShadowBufPtr) != (*(uint8*)sigDataPtr) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            {
                sigValChangeFlag = TRUE;
                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                *(uint8*)txSigInfo[sigId].sigValShadowBufPtr = *(uint8*)sigDataPtr;  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            }
            break;
        case COM_SIGTYPE_UINT16:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
            if( (*(uint16*)txSigInfo[sigId].sigValShadowBufPtr) != (*(uint16*)sigDataPtr) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            {
                sigValChangeFlag = TRUE;
                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                *(uint16*)txSigInfo[sigId].sigValShadowBufPtr = *(uint16*)sigDataPtr;  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            }
            break;
        case COM_SIGTYPE_UINT32:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
            if( (*(uint32*)txSigInfo[sigId].sigValShadowBufPtr) != (*(uint32*)sigDataPtr) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            {
                sigValChangeFlag = TRUE;
                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                *(uint32*)txSigInfo[sigId].sigValShadowBufPtr = *(uint32*)sigDataPtr;  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            }
            break;
        case COM_SIGTYPE_UINT64:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
            if( (*(uint64*)txSigInfo[sigId].sigValShadowBufPtr) != (*(uint64*)sigDataPtr) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            {
                sigValChangeFlag = TRUE;
                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                *(uint64*)txSigInfo[sigId].sigValShadowBufPtr = *(uint64*)sigDataPtr;  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            }
            break;
        case COM_SIGTYPE_SINT8:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
            if( (*(sint8*)txSigInfo[sigId].sigValShadowBufPtr) != (*(sint8*)sigDataPtr) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            {
                sigValChangeFlag = TRUE;
                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                *(sint8*)txSigInfo[sigId].sigValShadowBufPtr = *(sint8*)sigDataPtr;  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            }
            break;
        case COM_SIGTYPE_SINT16:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
            if( (*(sint16*)txSigInfo[sigId].sigValShadowBufPtr) != (*(sint16*)sigDataPtr) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            {
                sigValChangeFlag = TRUE;
                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                *(sint16*)txSigInfo[sigId].sigValShadowBufPtr = *(sint16*)sigDataPtr;  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            }
            break;
        case COM_SIGTYPE_SINT32:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
            if( (*(sint32*)txSigInfo[sigId].sigValShadowBufPtr) != (*(sint32*)sigDataPtr) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            {
                sigValChangeFlag = TRUE;
                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                *(sint32*)txSigInfo[sigId].sigValShadowBufPtr = *(sint32*)sigDataPtr;  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            }
            break;
        case COM_SIGTYPE_SINT64:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
            if( (*(sint64*)txSigInfo[sigId].sigValShadowBufPtr) != (*(sint64*)sigDataPtr) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            {
                sigValChangeFlag = TRUE;
                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                *(sint64*)txSigInfo[sigId].sigValShadowBufPtr = *(sint64*)sigDataPtr;  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            }
            break;
        case COM_SIGTYPE_FLOAT32:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
            if( FALSE == Com_CompareFloat32Values((*(float32*)txSigInfo[sigId].sigValShadowBufPtr),(*(float32*)sigDataPtr)) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            {
                sigValChangeFlag = TRUE;
                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                *(float32*)txSigInfo[sigId].sigValShadowBufPtr = *(float32*)sigDataPtr;  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            }
            break;
        case COM_SIGTYPE_FLOAT64:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
            if( FALSE == Com_CompareFloat64Values((*(float64*)txSigInfo[sigId].sigValShadowBufPtr),(*(float64*)sigDataPtr)) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            {
                sigValChangeFlag = TRUE;
                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                *(float64*)txSigInfo[sigId].sigValShadowBufPtr = *(float64*)sigDataPtr;  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
            }
            break;
        case COM_SIGTYPE_UINT8_DYN:

            break;
        case COM_SIGTYPE_UINT8_N:
            for( sigLengthIndex = COM_INIT_ZERO; sigLengthIndex < txSigInfo[sigId].sigBaseInfo->sigByteLength; sigLengthIndex++ )
            {
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                if( ((uint8*)txSigInfo[sigId].sigValShadowBufPtr)[sigLengthIndex] != ((uint8*)sigDataPtr)[sigLengthIndex] )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                {
                    sigValChangeFlag = TRUE;
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    ((uint8*)txSigInfo[sigId].sigValShadowBufPtr)[sigLengthIndex] = ((uint8*)sigDataPtr)[sigLengthIndex];  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                }
            }
            break;
        /* PolySpace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_Com_16.4" */
        default:
            break;
    }

    if( (boolean)TRUE == sigValChangeFlag )
    {
        if( COM_SIG_NO_GROUP_DEF == txSigInfo[sigId].acSigGrpIdx )
        {
            *(txSigInfo[sigId].sigSendSta) = COM_SIG_SENDSTA_READY;
        }
        else
        {
            *(txSigInfo[sigId].sigSendSta) = COM_SIG_SENDSTA_WAITGRP;
        }
    }

    if( COM_SIG_NO_GROUP_DEF == txSigInfo[sigId].acSigGrpIdx )
    {
         Com_SendPduStaProcess(&txSigInfo[sigId], sigValChangeFlag);
    }
#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
    /* PolySpace +1 DEFECT:TAINTED_LOOP_BOUNDARY [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_LOOP_BOUNDARY" */
    if( COM_SIG_NO_UPDATEBIT_DEF != txSigInfo[sigId].updateBitSigIndex )
    {
        /* Process updateBit signal. */
        Com_SigTxSetUb(txSigInfo[sigId].updateBitSigIndex, txSigInfo[sigId].acPduId);
    }
#endif  /* COM_TXUPDATEBITCFG_SUPPORT == STD_ON */
}

/*
********************************************************************************
* Function Name: Com_SendDynSignal_Process
*
* Explanation: The service updates the signal object identified by SignalId with
*              the signal referenced by the SignalDataPtr parameter.
*
* param: sigId : Id of signal to be sent.
*        sigDataPtr:  Reference to the signal data to be transmitted.
*        Length: Dynalic signal length.
*
* retval: acRet: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_SendDynSignal_Process
(
    uint16 sigId,
    P2CONST(void, AUTOMATIC, COM_APPL_CONST) sigDataPtr,
    uint16 Length
)
{
    boolean sigValChangeFlag = FALSE;
    uint16 sigLengthIndex;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxSignalInfo_st* txSigInfo = Com_TxSignalInfo;

    /* Determine if the data has been updated. */
    /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_LOOP_BOUNDARY [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_LOOP_BOUNDARY" */
    for( sigLengthIndex = COM_INIT_ZERO; sigLengthIndex < Length; sigLengthIndex++ )
    {
        /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
        if( ((uint8*)txSigInfo[sigId].sigValShadowBufPtr)[sigLengthIndex] != ((uint8*)sigDataPtr)[sigLengthIndex] )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
        {
            sigValChangeFlag = TRUE;
            /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
            ((uint8*)txSigInfo[sigId].sigValShadowBufPtr)[sigLengthIndex] = ((uint8*)sigDataPtr)[sigLengthIndex];  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
        }
    }
    if( (boolean)TRUE == sigValChangeFlag ) /* If changed. */
    {
        if( COM_SIG_NO_GROUP_DEF == txSigInfo[sigId].acSigGrpIdx ) /* sig. */
        {
            *(txSigInfo[sigId].sigSendSta) = COM_SIG_SENDSTA_READY;
        }
        else /* SigGrp. */
        {
            *(txSigInfo[sigId].sigSendSta) = COM_SIG_SENDSTA_WAITGRP;
        }
    }
    /* Set the sending state of the message. */
    Com_SendPduStaProcess(&txSigInfo[sigId], sigValChangeFlag);

#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
    if( COM_SIG_NO_UPDATEBIT_DEF != txSigInfo[sigId].updateBitSigIndex )
    {
        /* Process updateBit signal. */
        Com_SigTxSetUb(txSigInfo[sigId].updateBitSigIndex, txSigInfo[sigId].acPduId);
    }
#endif  /* COM_TXUPDATEBITCFG_SUPPORT == STD_ON */
}

/*
********************************************************************************
* Function Name: Com_SendPduStaProcess
*
* Explanation: Pdu send status processing.
*
* param: txSigInfo: COM_TxSignalInfo_st Info.
*        sigValChangeFlag: Whether the value is updated or not.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_SendPduStaProcess
(
    P2CONST(COM_TxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) txSigInfo,
    boolean sigValChangeFlag
)
{
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxPduInfo_st* PduInfo = Com_TxPduInfo;

    if( NULL_PTR != PduInfo[txSigInfo->acPduId].pduTriggerMonitor )
    {
        /* Set the sending state of the message. */
        /* PolySpace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_Com_16.1" */
        switch(txSigInfo->sigTransferProperty)
        {
            case COM_TRANS_PENDING:
                break;
            case COM_TRANS_TRIGGERED:
                PduInfo[txSigInfo->acPduId].pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_ACTIVE;
                break;
            case COM_TRANS_TRIGGERED_ON_CHG:
                if( (boolean)TRUE == sigValChangeFlag )
                {
                    PduInfo[txSigInfo->acPduId].pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_ACTIVE;
                }
                break;
            case COM_TRANS_TRIGGERED_ON_CHG_WR:
                if( (boolean)TRUE == sigValChangeFlag )
                {
                    PduInfo[txSigInfo->acPduId].pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_ACTIVE_WP;
                }
                break;
            case COM_TRANS_TRIGGERED_WR:
                PduInfo[txSigInfo->acPduId].pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_ACTIVE_WP;
                break;
            /*  Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " PolySpace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_Com_16.4" */
            default:
                break;
        }
    }
}

 #if( COM_TXSIGGROUPINFO == STD_ON )
/*
********************************************************************************
* Function Name: Com_SendSigGrp_Process
*
* Explanation: copies the content of the associated shadow buffer to the associated I-PDU.
*
* param: sigGrpId: Id of signal group to be sent.
*
* retval: acRet: E_OK: service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped
*                                          (or service failed due to development error).
*                COM_BUSY: in case the TP-Buffer is locked for large data types handling.
********************************************************************************
*/
static FUNC(uint8, COM_CODE) Com_SendSigGrp_Process(Com_SignalGroupIdType sigGrpId)
{
    boolean sigValChangeFlag = FALSE;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    uint8 RtrnValu = E_OK;
    uint16 index;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxSigGrpInfo_st* sigGrpInfoPtr = &Com_TxSigGrpInfo[sigGrpId];
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxSignalInfo_st* txSigInfo = Com_TxSignalInfo;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxPduInfo_st* PduInfo = Com_TxPduInfo;

    /* The sending state of a new group of signals. */
    for( index = sigGrpInfoPtr->acSigIdxStart; index < sigGrpInfoPtr->acSigIdxdEnd; index++ )
    {
        if( COM_SIG_SENDSTA_WAITGRP == *(txSigInfo[index].sigSendSta) )
        {
            *(txSigInfo[index].sigSendSta) = COM_SIG_SENDSTA_READY;
        }
    }

#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
    /* Set updatebit. */
    if( COM_SIG_NO_UPDATEBIT_DEF != sigGrpInfoPtr->updateBitSigIndex )
    {
        Com_SigTxSetUb(sigGrpInfoPtr->updateBitSigIndex, sigGrpInfoPtr->awPduId);
    }
#endif  /* COM_TXUPDATEBITCFG_SUPPORT == STD_ON */

    if( NULL_PTR != PduInfo[sigGrpInfoPtr->awPduId].pduTriggerMonitor )
    {
        /* Set the sending state of the message. */
        /* PolySpace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_Com_16.1" */
        switch( sigGrpInfoPtr->sigTransferProperty )
        {
            case COM_TRANS_PENDING:
                break;
            case COM_TRANS_TRIGGERED:
                PduInfo[sigGrpInfoPtr->awPduId].pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_ACTIVE;
                break;
            case COM_TRANS_TRIGGERED_ON_CHG:
                for( index = sigGrpInfoPtr->acSigIdxStart; index < sigGrpInfoPtr->acSigIdxdEnd; index++ )
                {
                    /* When the value of a signal configured as pending or passive in the group changes, it does not trigger transmission. */
                    if( (COM_SIG_SENDSTA_READY == *(txSigInfo[index].sigSendSta)) &&
                        (COM_TRANS_PENDING != txSigInfo[index].sigTransferProperty) )
                    {
                        sigValChangeFlag = TRUE;
                    }
                }
                if( (boolean)TRUE == sigValChangeFlag )
                {
                    PduInfo[sigGrpInfoPtr->awPduId].pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_ACTIVE;
                }
                break;
            case COM_TRANS_TRIGGERED_ON_CHG_WR:
                for( index = sigGrpInfoPtr->acSigIdxStart; index < sigGrpInfoPtr->acSigIdxdEnd; index++ )
                {
                    /* When the value of a signal configured as pending or passive in the group changes, it does not trigger transmission. */
                    if( (COM_SIG_SENDSTA_READY == *(txSigInfo[index].sigSendSta)) &&
                        (COM_TRANS_PENDING != txSigInfo[index].sigTransferProperty) )
                    {
                        sigValChangeFlag = TRUE;
                    }
                }
                if( (boolean)TRUE == sigValChangeFlag )
                {
                    PduInfo[sigGrpInfoPtr->awPduId].pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_ACTIVE_WP;
                }
                break;
            case COM_TRANS_TRIGGERED_WR:
                PduInfo[sigGrpInfoPtr->awPduId].pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_ACTIVE_WP;
                break;
            /* PolySpace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Com_DEAD_CODE" Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " PolySpace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_Com_16.4" */
            default:
                break;
        }
    }

    return RtrnValu;
}
#endif

/*
********************************************************************************
* Function Name: Com_PduTxProcess
*
* Explanation: performs the processing of the AUTOSAR COM module's transmis-sion activities.
*
* param: PduInfo: Tx Pdu Info.
*
* retval: None
********************************************************************************
*/
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_PduTxProcess
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) astPduInfo
)
{
    const Com_TxMode_st* txModePtr;

    /* if pdu active, process the continued. */
    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
    if( COM_PDU_STA_INACTIVE != astPduInfo->astPduInterMonitor->pduSta )
    {
        if( TRUE == astPduInfo->astPduInterMonitor->pduTxMode )
        {
            txModePtr = &Com_TxModeTrue[astPduInfo->acTxModeIndex];
        }
        else
        {
            txModePtr = &Com_TxModeFalse[astPduInfo->acTxModeIndex];
        }
        Com_PduTxCheckTimeOut(astPduInfo);
        /* PolySpace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_Com_16.1" */
        switch(txModePtr->acTxMode)
        {
            case COM_TXMODE_PREDIOC: /* Tx mode mode Predioc Process. */
                Com_PduPeriodicTxProcess(astPduInfo, txModePtr->acTxCycle);
                break;
            case COM_TXMODE_DIRECT: /* Tx mode mode Direct Process. */
                Com_PduDirectTxProcess(astPduInfo, txModePtr->acTxModeRepet, txModePtr->acTxModeRepetPeriod);
                break;
            case COM_TXMODE_MIX: /* Tx mode mode Mix Process. */
                Com_PduMixTxProcess(astPduInfo, txModePtr->acTxCycle, txModePtr->acTxModeRepet, txModePtr->acTxModeRepetPeriod);
                break;
            /* PolySpace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Com_DEAD_CODE" Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            case COM_TXMODE_IF_ACTIVE:
                Com_PduIfActiveTxProcess(astPduInfo, txModePtr->acTxCycleFast, txModePtr->acTxModeRepet, txModePtr->acTxModeRepetPeriod);
                break;
            /* PolySpace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Com_DEAD_CODE" Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            case COM_TXMODE_PERIODIC_IF_ACTIVE:
                Com_PduPeriodicIfActiveTxProcess(astPduInfo, txModePtr->acTxCycle, txModePtr->acTxCycleFast, txModePtr->acTxModeRepet, txModePtr->acTxModeRepetPeriod);
                break;
            /* PolySpace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_Com_16.4" */
            default:
                break;
        }
    }
}

/*
********************************************************************************
* Function Name: Com_PduTxSetVal
*
* Explanation: To put a signal value into a message.
*
* param: PduInfo: COM_TxPduInfo_st info.
*
* retval: None
*
********************************************************************************
*/
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_PduTxSetVal
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
)
{
    uint16 sigIndex;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxSignalInfo_st* txSigInfo = Com_TxSignalInfo;
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
    uint8* pduDataPtr = NULL_PTR;
    uint8 sigFuncIdx;
#endif
    /* To put a signal value into a message. */
    for( sigIndex = PduInfo->awSigStartIndex; sigIndex < PduInfo->awSigEndIndex; sigIndex++ )
    {
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        if( COM_SIG_SENDSTA_READY == *(txSigInfo[sigIndex].sigSendSta) )
        {
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
            /* Get signal sigFuncIdx. */
            sigFuncIdx = txSigInfo[sigIndex].sigBaseInfo->sigFuncIdx;
            if( COM_TXASSIGNSIGNAL_FUNC_NUM > sigFuncIdx ) /* Judge signal funId. */
            {
                pduDataPtr = Com_TxPduInfo[txSigInfo[sigIndex].acPduId].dataRaw;
                /* Assign signal to pdu. */
                Com_TxAssignSignal_FuncTable[sigFuncIdx](txSigInfo[sigIndex].sigValShadowBufPtr, pduDataPtr, txSigInfo[sigIndex].sigBaseInfo);  /* PRQA S 0317*/ /* NSCA_QAC_Com_Rule11.5 */
            }
            else if( COM_TXASSIGNSIGNAL_FUNC_NUM == sigFuncIdx ) /*sigFuncIdx is U8DYN signal sigFuncIdx. */
            {
                /* Assign U8DYN signal to pdu. */
                Com_WriteSignU8DYN(pduDataPtr, &txSigInfo[sigIndex]);
            }
            else
            {
                /* Do nothing. */
            }
#else
            /* Judge signal type. */
            /* PolySpace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_Com_16.1" */
            switch( Com_GetSignalType(txSigInfo[sigIndex].sigBaseInfo->sigFuncIdx) )
            {
                case COM_SIGTYPE_BOOLEAN:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                    Com_TxSigWrite_Normal(&txSigInfo[sigIndex], (uint32)(*(boolean*)txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_UINT8:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                    Com_TxSigWrite_Normal(&txSigInfo[sigIndex], (uint32)(*(uint8*)txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_UINT16:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_TxSigWrite_Normal(&txSigInfo[sigIndex], (uint32)(*(uint16*)txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_UINT32:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_TxSigWrite_Normal(&txSigInfo[sigIndex], (uint32)(*(uint32*)txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_UINT64:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_TxSigWrite_Large_64(&txSigInfo[sigIndex], (uint64)(*(uint64*)txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_SINT8:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                    Com_TxSigWrite_Normal(&txSigInfo[sigIndex], (uint32)(*(sint8*)txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_SINT16:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_TxSigWrite_Normal(&txSigInfo[sigIndex], (uint32)(*(sint16*)txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_SINT32:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_TxSigWrite_Normal(&txSigInfo[sigIndex], (uint32)(*(sint32*)txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_SINT64:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_TxSigWrite_Large_64(&txSigInfo[sigIndex], (uint64)(*(sint64*)txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_FLOAT32:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_TxSigWrite_Normal(&txSigInfo[sigIndex], (uint32)(*(uint32*)txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_FLOAT64:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_TxSigWrite_Large_64(&txSigInfo[sigIndex], (uint64)(*(uint64*)txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_UINT8_DYN:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                    Com_TxSigWrite_Uint8N(&txSigInfo[sigIndex], (const uint8*)(txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                case COM_SIGTYPE_UINT8_N:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                    Com_TxSigWrite_Uint8N(&txSigInfo[sigIndex], (const uint8*)(txSigInfo[sigIndex].sigValShadowBufPtr));  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    break;
                /* PolySpace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_Com_16.4" */
                default:
                    break;
            }
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
            *(txSigInfo[sigIndex].sigSendSta) = COM_SIG_SENDSTA_NOSET;
        }
    }
}

/*
********************************************************************************
* Function Name: Com_PduTxTpProcess
*
* Explanation: Tx pdu Tp type process.
*
* param: PduInfo: Tx Pdu Info.
*
* retval: None
*
********************************************************************************
*/
#if( COM_TXPDU_TPTYPE_SUPPORT == STD_ON )
static FUNC(void, COM_CODE) Com_PduTxTpProcess
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
)
{
    /* Tp Type Processing. */
    if( NULL_PTR != PduInfo->pduTpMonitor )
    {
        PduInfo->pduTpMonitor->pduRemainLen = PduInfo->acPduLenth;
        PduInfo->pduTpMonitor->pduTpConnection = COM_PDU_TPCONNECTION_YES;
    }
}
#endif

/*
********************************************************************************
* Function Name: Com_PduTxCheckTimeOut
*
* Explanation: Determine whether to timeout.
*
* param: PduInfo: Tx Pdu Info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_PduTxCheckTimeOut
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
)
{
    if( COM_PDU_TYPE_ACTIVE_CONTROL == PduInfo->acPduActiveType )
    {
      if(( COM_PDU_STA_WAITCONFIRM == PduInfo->astPduInterMonitor->pduSta )&&(COM_INIT_ZERO != PduInfo->pduTimeoutCnt))
        {
            PduInfo->astPduInterMonitor->awPduTxTimeoutCounter++;
            /* COM_TX_TIMEBASE removed. */
            if( PduInfo->pduTimeoutCnt < PduInfo->astPduInterMonitor->awPduTxTimeoutCounter )
            {
                /* Cbk process. */
                /* PolySpace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
                Com_PduTxTimeOut_Cbk(PduInfo);
                /* Time out. */
                PduInfo->astPduInterMonitor->pduSta = COM_PDU_STA_TIMEOUT;
            }
        }
        else
        {
            /* Clear counter. */
            PduInfo->astPduInterMonitor->awPduTxTimeoutCounter = COM_INIT_ZERO;
        }
    }
}

/*
********************************************************************************
* Function Name: Com_PduTxTimeOut_Cbk
*
* Explanation: Execute the callback of the sending timeout.
*
* param: PduInfo: Tx Pdu Info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_PduTxTimeOut_Cbk
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo  /* PRQA S 3206 */ /* NSCA_QAC_Com_Rule2.7 */
)
{
#if( (COM_TXSIGGROUPINFO == STD_ON) && (COM_TXSIGGRP_TIMEOUT_NOTIFICATION_SUPPORT == STD_ON) )
    uint16 grpIndex;
#endif  /* (COM_TXSIGGROUPINFO == STD_ON) && (COM_TXSIGGRP_TIMEOUT_NOTIFICATION_SUPPORT == STD_ON) */
#if( COM_TXSIG_TIMEOUTNOTIFICATION_SUPPORT == STD_ON )
    uint16 sigIndex;
    /* TimeOut signal cbk. */
    for( sigIndex = PduInfo->awSigStartIndex; sigIndex < PduInfo->awSigEndIndex; sigIndex++ )
    {
        if( COM_SIG_NO_GROUP_DEF == Com_TxSignalInfo[sigIndex].acSigGrpIdx )
        {
            /* Check NULL_PTR. */
            if( NULL_PTR != Com_TxSignalInfo[sigIndex].ToNotification_p )
            {
                Com_TxSignalInfo[sigIndex].ToNotification_p();
            }
        }
    }
#endif  /* COM_TXSIG_TIMEOUTNOTIFICATION_SUPPORT == STD_ON */

#if( (COM_TXSIGGROUPINFO == STD_ON) && (COM_TXSIGGRP_TIMEOUT_NOTIFICATION_SUPPORT == STD_ON) )
    /* TimeOut signal group cbk. */
    for( grpIndex = PduInfo->acSigGrpStartIndex; grpIndex < PduInfo->acSigGrpEndIndex; grpIndex++ )
    {
        /* Check NULL_PTR. */
        if( NULL_PTR != Com_TxSigGrpInfo[grpIndex].ToNotification_p )
        {
            Com_TxSigGrpInfo[grpIndex].ToNotification_p();
        }
    }
#endif  /* (COM_TXSIGGROUPINFO == STD_ON) && (COM_TXSIGGRP_TIMEOUT_NOTIFICATION_SUPPORT == STD_ON) */
}

/*
********************************************************************************
* Function Name: Com_OnePduSend
*
* Explanation: Sending message processing.
*
* param: PduInfo: Tx Pdu Info.
*
* retval: None
********************************************************************************
*/
COM_LOCAL_INLINE FUNC(Std_ReturnType, COM_CODE) Com_OnePduSend
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
)
{
    boolean rtnValue = TRUE;
    Std_ReturnType stdRet = E_NOT_OK;
    PduInfoType astSenderPdu;

    Com_PduTxSetVal(PduInfo);
    COM_DUMMY_STATEMENT(rtnValue);
    astSenderPdu.SduLength = PduInfo->acPduLenth;
    astSenderPdu.SduDataPtr = PduInfo->dataRaw;

#if( COM_TXPDU_TRIGGERCALLOUT_SUPPORT == STD_ON )
    if( NULL_PTR != PduInfo->TriggerCallout )  /* Configed Callout. */
    {
        /* Polyspace +1 RTE:COR [Justified:Unset] "NSCA_Polyspace_Com_COR" Polyspace +1 RTE:IDP [Justified:Unset] " NSCA_Polyspace_Com_IDP " */
        rtnValue = PduInfo->TriggerCallout(PduInfo->acPduID, &astSenderPdu);
    }
    /* true: I-PDU will be processed normal false: I-PDU will not be processed any further */
    if( TRUE == rtnValue )  /* SWS_Com_00346 */
#endif
    {
        stdRet = PduR_ComTransmit(PduInfo->lowLayerPduID,&astSenderPdu);

#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
        /* The update-bits are cleared directly after the invocation of PduR_ComTransmit. */
        /* Polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_Com_OBAI" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        if( COM_PDU_CLEARUB_TRANSMIT == Com_TxPduInfo[PduInfo->acPduID].acPduClearUpdateBit )
        {
            Com_TxPduClearUb_Process(&Com_TxPduInfo[PduInfo->acPduID]);
        }
#endif
    }

    return stdRet;
}

#if( (COM_METADATA_SUPPORT == STD_ON) && (COM_TXMETADATA_NUM > COM_INIT_ZERO) )
/*
********************************************************************************
* Function Name: Com_OnePduSendByMetaDataTrigger
*
* Explanation: Send MetaData message processing.
*
* param: PduInfo: Tx Pdu Info.
*
* stdRet: E_OK: request is accepted by the dstPduPtr module;
*                 transmission is continued.
*         E_NOT_OK: request is not accepted by the PduR module;
*                     transmission is aborted.
********************************************************************************
*/
COM_LOCAL_INLINE FUNC(Std_ReturnType, COM_CODE) Com_OnePduSendByMetaDataTrigger
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
)
{
#if( COM_TXPDU_TRIGGERCALLOUT_SUPPORT == STD_ON )
    boolean retVal = TRUE;
#endif  /* ( COM_TXPDU_TRIGGERCALLOUT_SUPPORT == STD_ON ) */
    Std_ReturnType stdRet = E_NOT_OK;
    PduInfoType astSenderPdu;

    Com_PduTxSetVal(PduInfo);

#if( COM_TXPDU_TRIGGERCALLOUT_SUPPORT == STD_ON )
    if( NULL_PTR != PduInfo->TriggerCallout ) /* Configed Callout. */
    {
        astSenderPdu.SduLength = PduInfo->acPduLenth;
        astSenderPdu.SduDataPtr = PduInfo->dataRaw;
        retVal = PduInfo->TriggerCallout(PduInfo->acPduID, &astSenderPdu);
    }
    /* true: I-PDU will be processed normal false: I-PDU will not be processed any further */
    if( TRUE == retVal )  /* SWS_Com_00346 */
#endif  /* ( COM_TXPDU_TRIGGERCALLOUT_SUPPORT == STD_ON ) */
    {
#if( COM_TXPDU_TPTYPE_SUPPORT == STD_ON )
        if( NULL_PTR != PduInfo->pduTpMonitor )
        {
            /* Copy MetaData to Pdu, which is temporarily stored when TP type I-PDU is busy. */
            if( TRUE == Com_TxPduMonMetaData[PduInfo->acMetaDataIdx].tpBusy )
            {
                uint8 metaDataIdx;
                for( metaDataIdx = COM_INIT_ZERO; metaDataIdx < PduInfo->acMetaDataLength; metaDataIdx++ )
                {
                    PduInfo->dataRaw[PduInfo->acPduLenth + metaDataIdx] =
                        Com_TxPduMonMetaData[PduInfo->acMetaDataIdx].tpMetaData[metaDataIdx];
                }
                Com_TxPduMonMetaData[PduInfo->acMetaDataIdx].tpBusy = FALSE;
            }
            /* TP type I-PDU sends MetaData. */
            astSenderPdu.SduLength = PduInfo->acPduLenth + PduInfo->acMetaDataLength;
            astSenderPdu.SduDataPtr = PduInfo->dataRaw;
        }
        else
#endif  /* ( COM_TXPDU_TPTYPE_SUPPORT == STD_ON ) */
        {
            astSenderPdu.SduLength = PduInfo->acPduLenth + PduInfo->acMetaDataLength;
            astSenderPdu.SduDataPtr = PduInfo->dataRaw;
        }

        stdRet = PduR_ComTransmit(PduInfo->lowLayerPduID,&astSenderPdu);

#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
        /* The update-bits are cleared directly after the invocation of PduR_ComTransmit. */
        if( COM_PDU_CLEARUB_TRANSMIT == Com_TxPduInfo[PduInfo->acPduID].acPduClearUpdateBit )
        {
            Com_TxPduClearUb_Process(&Com_TxPduInfo[PduInfo->acPduID]);
        }
#endif  /* ( COM_TXUPDATEBITCFG_SUPPORT == STD_ON ) */
    }

    return stdRet;
}
#endif  /* ( (COM_METADATA_SUPPORT == STD_ON) && (COM_TXMETADATA_NUM > COM_INIT_ZERO) ) */

/*
********************************************************************************
* Function Name: Com_PduTriggerSend
*
* Explanation: Trigger type message sending processing.
*
* param: PduInfo: Tx Pdu Info.
*        numberofRepetion: Number of repetitions
*        RepetionPeriod: Repeated period
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_PduTriggerSend
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo,
    uint16 numberofRepetion,
    uint16 RepetionPeriod
)
{
    Std_ReturnType stdRet = E_NOT_OK;

#if( COM_TXPDU_MDT_SUPPORT == STD_ON )
    if( COM_MDTCOUNTER_ZERO != PduInfo->acMinimumDelayTime )
    {
        /* MDT Function. */
        /* Pdu delayed flag. */
        boolean pduDelaySendFlag = FALSE;

        /* Has the pdu been delayed in the past? */
        if( ((COM_MDTFORCYC_READY == PduInfo->astPduInterMonitor->pduCycMDTState) &&(TRUE == PduInfo->pduTriggerMonitor->pduTriggerDelayFlag)) ||
            ((COM_MDTFORTRG_READY == PduInfo->pduTriggerMonitor->pduTrgMDTState) && (TRUE == PduInfo->pduTriggerMonitor->pduTriggerDelayFlag)))
        {
            /*This represents a delayed transmission.*/
            pduDelaySendFlag = TRUE;
        }
        /* Count of sending cycles. */
        if( COM_INIT_ZERO != PduInfo->pduTriggerMonitor->pduTrgCycCounter )
        {
            PduInfo->pduTriggerMonitor->pduTrgCycCounter--;
        }
        /* Start the Pdu triggered transmission. */
        if( COM_PDU_TRIG_ACTIVE == PduInfo->pduTriggerMonitor->pduTriggerSta )
        {
#if( COM_TRIGRESETCYCTIMER_SUPPORT == STD_ON )
            PduInfo->pduTriggerMonitor->Com_ResetCycTimerFlag = TRUE;
#endif
            /* Determine if the time interval requirements for MDT are met. */
            if( (COM_MDTCOUNTER_ZERO == PduInfo->astPduInterMonitor->pduCycCntForMDT) &&
                (COM_MDTCOUNTER_ZERO == PduInfo->pduTriggerMonitor->pduTrgCycCntForMDT) )
            {
                stdRet = Com_OnePduSend(PduInfo);
                /* Transmission ok? */
                if( (Std_ReturnType)E_OK == stdRet )
                {
                    /* Wait Com_TxConfirmation. */
                    PduInfo->astPduInterMonitor->pduSta = COM_PDU_STA_WAITCONFIRM;
                    PduInfo->pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_PROCESSING;
                    /* The PDU sent this time is in Trigger mode. */
                    PduInfo->pduTriggerMonitor->TriggerSendFlag = TRUE;
                    /* There is no delayed PDU. */
                    PduInfo->pduTriggerMonitor->pduTriggerDelayFlag = FALSE;
                    /* Is this a delayed transmission? */
                    if( TRUE == pduDelaySendFlag )
                    {
                        /* Set Number Of Repetitions and Repetition Period. */
                        if( COM_OPERAND_ONE <= numberofRepetion )
                        {
                            PduInfo->pduTriggerMonitor->pduSendRemainCnt = numberofRepetion - COM_OPERAND_ONE;
                            PduInfo->pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_PROCESSING;
                        }
                        else
                        {
                            PduInfo->pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_INACTIVE;
                        }
                    }
                    else
                    {
                        /* Set Number Of Repetitions and Repetition Period. */
                        if( COM_OPERAND_ONE <= numberofRepetion )
                        {
                            PduInfo->pduTriggerMonitor->pduSendRemainCnt = numberofRepetion - COM_OPERAND_ONE;
                            /* Reset sending cycle. */
                            PduInfo->pduTriggerMonitor->pduTrgCycCounter = RepetionPeriod;
                            PduInfo->pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_PROCESSING;
                        }
                        else
                        {
                            PduInfo->pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_INACTIVE;
                        }
                    }
#if( COM_TXPDU_TPTYPE_SUPPORT == STD_ON )
                    /* Tp Type Processing. */
                    Com_PduTxTpProcess(PduInfo);
#endif /* COM_TXPDU_TPTYPE_SUPPORT == STD_ON */
#if( COM_RETRY_FAILED_TRANSMIT_REQUESTS == STD_ON )
                    /* SWS_Com_00828,start the minimum delay time counter upon transmission of that I-PDU
                    to the PDU Router via PduR_ComTransmit only in case PduR_ComTransmit returns E_OK. */
                    if( COM_MDTCOUNTER_ZERO != PduInfo->acMinimumDelayTime )
                    {
                        /* MDT start. */
                        PduInfo->pduTriggerMonitor->pduTrgCycCntForMDT = PduInfo->acMinimumDelayTime;
                        PduInfo->pduTriggerMonitor->pduTrgMDTState = COM_MDTFORTRG_START;
                    }
#endif /* COM_TXPDU_TPTYPE_SUPPORT == STD_ON */
                }
#if( COM_RETRY_FAILED_TRANSMIT_REQUESTS != STD_ON )
                    /* SWS_Com_00698,and start the minimum delay time counter upon transmission of
                    that I-PDU to the PDU Router via PduR_ComTransmit. */
                    if( COM_MDTCOUNTER_ZERO != PduInfo->acMinimumDelayTime )
                    {
                        PduInfo->pduTriggerMonitor->pduTrgCycCntForMDT = PduInfo->acMinimumDelayTime;
                        PduInfo->pduTriggerMonitor->pduTrgMDTState = COM_MDTFORTRG_START;
                    }
#endif /* COM_RETRY_FAILED_TRANSMIT_REQUESTS != STD_ON */
            }
            else
            {
                if( TRUE != PduInfo->pduTriggerMonitor->pduTriggerDelayFlag )
                {
                    /* It's a continuous request with delayed transmission. */
                    PduInfo->pduTriggerMonitor->pduTriggerDelayFlag = TRUE;
                    if( COM_OPERAND_ONE <= numberofRepetion )
                    {
                        /* Reset sending cycle. */
                        PduInfo->pduTriggerMonitor->pduTrgCycCounter = RepetionPeriod;
                    }
                }
            }
        }
        else if( COM_PDU_TRIG_ACTIVE_WP == PduInfo->pduTriggerMonitor->pduTriggerSta )
        {
#if( COM_TRIGRESETCYCTIMER_SUPPORT == STD_ON )
            PduInfo->pduTriggerMonitor->Com_ResetCycTimerFlag = TRUE;
#endif
            /* Determine if the time interval requirements for MDT are met. */
            if( (COM_MDTCOUNTER_ZERO == PduInfo->astPduInterMonitor->pduCycCntForMDT) && (COM_MDTCOUNTER_ZERO == PduInfo->pduTriggerMonitor->pduTrgCycCntForMDT) )
            {
#if( (COM_METADATA_SUPPORT == STD_ON) && (COM_TXMETADATA_NUM > COM_INIT_ZERO) )
                /* The PduInfo sending is triggered by Com_TriggerIPDUSendWithMetaData. */
                if( (COM_PDU_NO_METADATA_DEF != PduInfo->acMetaDataIdx)
                    && (TRUE == Com_TxPduMonMetaData[PduInfo->acMetaDataIdx].triggerMetaDataEnable) )
                {
                    stdRet = Com_OnePduSendByMetaDataTrigger(PduInfo);
                    Com_TxPduMonMetaData[PduInfo->acMetaDataIdx].triggerMetaDataEnable = FALSE;
                }
                else
#endif /* ( (COM_METADATA_SUPPORT == STD_ON) && (COM_TXMETADATA_NUM > COM_INIT_ZERO) ) */
                {
                    stdRet = Com_OnePduSend(PduInfo);
                }
                if( (Std_ReturnType)E_OK == stdRet )
                {
                    /* Wait Com_TxConfirmation. */
                    PduInfo->astPduInterMonitor->pduSta = COM_PDU_STA_WAITCONFIRM;
                    PduInfo->pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_INACTIVE;
                    /* The PDU sent this time is in Trigger mode. */
                    PduInfo->pduTriggerMonitor->TriggerSendFlag = TRUE;
                    /* There is no delayed PDU. */
                    PduInfo->pduTriggerMonitor->pduTriggerDelayFlag = FALSE;
                    /* Set Number Of Repetitions and Repetition Period to 0. */
                    PduInfo->pduTriggerMonitor->pduTrgCycCounter = COM_INIT_ZERO;
                    PduInfo->pduTriggerMonitor->pduSendRemainCnt = COM_INIT_ZERO;

#if( COM_TXPDU_TPTYPE_SUPPORT == STD_ON )
                    /* Tp Type Processing. */
                    Com_PduTxTpProcess(PduInfo);
#endif /* COM_TXPDU_TPTYPE_SUPPORT == STD_ON */
#if( COM_RETRY_FAILED_TRANSMIT_REQUESTS == STD_ON )
                    /* SWS_Com_00828,start the minimum delay time counter upon transmission of that I-PDU
                        to the PDU Router via PduR_ComTransmit only in case PduR_ComTransmit returns E_OK. */
                    if( COM_MDTCOUNTER_ZERO != PduInfo->acMinimumDelayTime )
                    {
                        /* MDT start. */
                        PduInfo->pduTriggerMonitor->pduTrgCycCntForMDT = PduInfo->acMinimumDelayTime;
                        PduInfo->pduTriggerMonitor->pduTrgMDTState = COM_MDTFORTRG_START;
                    }
#endif /* COM_RETRY_FAILED_TRANSMIT_REQUESTS == STD_ON */
                }
#if( COM_RETRY_FAILED_TRANSMIT_REQUESTS != STD_ON )
                    /* SWS_Com_00698,and start the minimum delay time counter upon transmission of
                        that I-PDU to the PDU Router via PduR_ComTransmit. */
                    if( COM_MDTCOUNTER_ZERO != PduInfo->acMinimumDelayTime )
                    {
                        /* MDT start. */
                        PduInfo->pduTriggerMonitor->pduTrgCycCntForMDT = PduInfo->acMinimumDelayTime;
                        PduInfo->pduTriggerMonitor->pduTrgMDTState = COM_MDTFORTRG_START;
                    }
#endif /* COM_RETRY_FAILED_TRANSMIT_REQUESTS != STD_ON */
            }
            else
            {
                /* The minimum delay time interval has not arrived */
                PduInfo->pduTriggerMonitor->pduTriggerDelayFlag = TRUE;
            }
        }
        else if( COM_PDU_TRIG_PROCESSING == PduInfo->pduTriggerMonitor->pduTriggerSta )
        {
#if( COM_TRIGRESETCYCTIMER_SUPPORT == STD_ON )
            PduInfo->pduTriggerMonitor->Com_ResetCycTimerFlag = TRUE;
#endif
            /* Processing Unfinished triggered transmission. */
            if( (COM_INIT_ZERO == PduInfo->pduTriggerMonitor->pduTrgCycCounter) || (TRUE == pduDelaySendFlag) )
            {
                /* Determine if the time interval requirements for MDT are met. */
                if( (COM_MDTCOUNTER_ZERO == PduInfo->astPduInterMonitor->pduCycCntForMDT) && (COM_MDTCOUNTER_ZERO == PduInfo->pduTriggerMonitor->pduTrgCycCntForMDT) )
                {
                    /* Pdu Tx. */
                    stdRet = Com_OnePduSend(PduInfo);
                    /* Transmission ok? */
                    if( (Std_ReturnType)E_OK == stdRet )
                    {
                        /* Wait Com_TxConfirmation. */
                        PduInfo->astPduInterMonitor->pduSta = COM_PDU_STA_WAITCONFIRM;
                        /* The PDU sent this time is in Trigger mode. */
                        PduInfo->pduTriggerMonitor->TriggerSendFlag = TRUE;
                        /* There is no delayed PDU. */
                        PduInfo->pduTriggerMonitor->pduTriggerDelayFlag = FALSE;
                        /* Repeated sending completed. */
                        if( COM_INIT_ZERO == PduInfo->pduTriggerMonitor->pduSendRemainCnt )
                        {
                            PduInfo->pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_INACTIVE;
                        }
                        else
                        {
                            PduInfo->pduTriggerMonitor->pduSendRemainCnt--;
                            /* Is this a delayed transmission? */
                            if( FALSE == pduDelaySendFlag )
                            {
                                /* Reset sending cycle. */
                                PduInfo->pduTriggerMonitor->pduTrgCycCounter = RepetionPeriod;
                            }
                        }
#if( COM_RETRY_FAILED_TRANSMIT_REQUESTS == STD_ON )
                        /* SWS_Com_00828,start the minimum delay time counter upon transmission of that I-PDU
                            to the PDU Router via PduR_ComTransmit only in case PduR_ComTransmit returns E_OK. */
                        if( COM_MDTCOUNTER_ZERO != PduInfo->acMinimumDelayTime )
                        {
                            /* MDT start. */
                            PduInfo->pduTriggerMonitor->pduTrgCycCntForMDT = PduInfo->acMinimumDelayTime;
                            PduInfo->pduTriggerMonitor->pduTrgMDTState = COM_MDTFORTRG_START;
                        }
#endif /* COM_RETRY_FAILED_TRANSMIT_REQUESTS == STD_ON */
                    }
#if( COM_RETRY_FAILED_TRANSMIT_REQUESTS != STD_ON )
                        /* SWS_Com_00698,and start the minimum delay time counter upon transmission of
                            that I-PDU to the PDU Router via PduR_ComTransmit. */
                    if( COM_MDTCOUNTER_ZERO != PduInfo->acMinimumDelayTime )
                    {
                        PduInfo->pduTriggerMonitor->pduTrgCycCntForMDT = PduInfo->acMinimumDelayTime;
                        PduInfo->pduTriggerMonitor->pduTrgMDTState = COM_MDTFORTRG_START;
                    }
#endif /* COM_RETRY_FAILED_TRANSMIT_REQUESTS != STD_ON */
                }
                else  /* The minimum delay time interval has not arrived */
                {
                    /* Is this a delayed transmission? */
                    if( TRUE != PduInfo->pduTriggerMonitor->pduTriggerDelayFlag )
                    {
                        /* Reset sending cycle. */
                        PduInfo->pduTriggerMonitor->pduTrgCycCounter = RepetionPeriod;
                        /* This transmission was delayed due to MDT. */
                        PduInfo->pduTriggerMonitor->pduTriggerDelayFlag = TRUE;
                    }
                    else
                    {
                        if( COM_INIT_ZERO == PduInfo->pduTriggerMonitor->pduTrgCycCounter )
                        {
                            /* Reset sending cycle. */
                            PduInfo->pduTriggerMonitor->pduTrgCycCounter = RepetionPeriod;
                        }
                    }
                }
            }
        }
        else
        {
            /* Do nothing. */
        }
    }
    else
    {
        /* No MDT Function. */
        /* Start the Pdu triggered transmission. */
        if( COM_PDU_TRIG_ACTIVE == PduInfo->pduTriggerMonitor->pduTriggerSta )
        {
#if( COM_TRIGRESETCYCTIMER_SUPPORT == STD_ON )
            PduInfo->pduTriggerMonitor->Com_ResetCycTimerFlag = TRUE;
#endif
            stdRet = Com_OnePduSend(PduInfo);
            if( (Std_ReturnType)E_OK == stdRet )
            {
                PduInfo->astPduInterMonitor->pduSta = COM_PDU_STA_WAITCONFIRM;
                PduInfo->pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_PROCESSING;
                /* Set Number Of Repetitions and Repetition Period. */
                if( COM_OPERAND_ONE <= numberofRepetion )
                {
                    PduInfo->pduTriggerMonitor->pduSendRemainCnt = numberofRepetion - COM_OPERAND_ONE;
                    PduInfo->pduTriggerMonitor->pduTrgCycCounter = RepetionPeriod;
                    PduInfo->pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_PROCESSING;
                    PduInfo->pduTriggerMonitor->pduTrgCycCntForMDT = PduInfo->pduTriggerMonitor->pduTrgCycCounter;
                    PduInfo->astPduInterMonitor->pduCycCntForMDT = PduInfo->astPduInterMonitor->pduCycCounter;
                }
                else
                {
                    PduInfo->pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_INACTIVE;
                }

#if( COM_TXPDU_TPTYPE_SUPPORT == STD_ON )
                /* Tp Type Processing. */
                Com_PduTxTpProcess(PduInfo);
#endif /* COM_TXPDU_TPTYPE_SUPPORT == STD_ON */
            }
        }
        else if( COM_PDU_TRIG_ACTIVE_WP == PduInfo->pduTriggerMonitor->pduTriggerSta )
        {
#if( COM_TRIGRESETCYCTIMER_SUPPORT == STD_ON )
            PduInfo->pduTriggerMonitor->Com_ResetCycTimerFlag = TRUE;
#endif
#if( (COM_METADATA_SUPPORT == STD_ON) && (COM_TXMETADATA_NUM > COM_INIT_ZERO) )
            /* The PduInfo sending is triggered by Com_TriggerIPDUSendWithMetaData. */
            if( (COM_PDU_NO_METADATA_DEF != PduInfo->acMetaDataIdx)
                && (TRUE == Com_TxPduMonMetaData[PduInfo->acMetaDataIdx].triggerMetaDataEnable) )
            {
                stdRet = Com_OnePduSendByMetaDataTrigger(PduInfo);
                Com_TxPduMonMetaData[PduInfo->acMetaDataIdx].triggerMetaDataEnable = FALSE;
            }
            else
#endif /* ( (COM_METADATA_SUPPORT == STD_ON) && (COM_TXMETADATA_NUM > COM_INIT_ZERO) ) */
            {
                stdRet = Com_OnePduSend(PduInfo);
            }
            if( (Std_ReturnType)E_OK == stdRet )
            {
                PduInfo->astPduInterMonitor->pduSta = COM_PDU_STA_WAITCONFIRM;
                PduInfo->pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_INACTIVE;
                /* Set Number Of Repetitions and Repetition Period to 0. */
                PduInfo->pduTriggerMonitor->pduTrgCycCounter = COM_INIT_ZERO;
                PduInfo->pduTriggerMonitor->pduSendRemainCnt = COM_INIT_ZERO;

#if( COM_TXPDU_TPTYPE_SUPPORT == STD_ON )
                /* Tp Type Processing. */
                Com_PduTxTpProcess(PduInfo);
#endif /* COM_TXPDU_TPTYPE_SUPPORT == STD_ON */
            }
        }
        else if( COM_PDU_TRIG_PROCESSING == PduInfo->pduTriggerMonitor->pduTriggerSta )
        {
#if( COM_TRIGRESETCYCTIMER_SUPPORT == STD_ON )
            PduInfo->pduTriggerMonitor->Com_ResetCycTimerFlag = TRUE;
#endif
            /* Processing Unfinished triggered transmission. */
            if( COM_INIT_ZERO != PduInfo->pduTriggerMonitor->pduTrgCycCounter )
            {
                PduInfo->pduTriggerMonitor->pduTrgCycCounter--;
            }
            if( COM_INIT_ZERO == PduInfo->pduTriggerMonitor->pduTrgCycCounter )
            {
                stdRet = Com_OnePduSend(PduInfo);
                if( (Std_ReturnType)E_OK == stdRet )
                {
                    PduInfo->astPduInterMonitor->pduSta = COM_PDU_STA_WAITCONFIRM;
                    if( COM_INIT_ZERO == PduInfo->pduTriggerMonitor->pduSendRemainCnt )
                    {
                        PduInfo->pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_INACTIVE;
                    }
                    else
                    {
                        PduInfo->pduTriggerMonitor->pduSendRemainCnt--;
                        PduInfo->pduTriggerMonitor->pduTrgCycCounter = RepetionPeriod;
                    }
                }
            }
        }
        else
        {
            /* Do nothing. */
        }
    }
#else  /* No MDT Function. */
    /* Start the Pdu triggered transmission. */
    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
    if( COM_PDU_TRIG_ACTIVE == PduInfo->pduTriggerMonitor->pduTriggerSta )
    {
#if( COM_TRIGRESETCYCTIMER_SUPPORT == STD_ON )
        PduInfo->pduTriggerMonitor->Com_ResetCycTimerFlag = TRUE;
#endif
        stdRet = Com_OnePduSend(PduInfo);
        if( (Std_ReturnType)E_OK == stdRet )
        {
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            PduInfo->astPduInterMonitor->pduSta = COM_PDU_STA_WAITCONFIRM;
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            PduInfo->pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_PROCESSING;
            /* Set Number Of Repetitions and Repetition Period. */
            if( COM_OPERAND_ONE <= numberofRepetion )
            {
                PduInfo->pduTriggerMonitor->pduSendRemainCnt = numberofRepetion - COM_OPERAND_ONE;
                PduInfo->pduTriggerMonitor->pduTrgCycCounter = RepetionPeriod;
                PduInfo->pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_PROCESSING;
            }
            else
            {
                PduInfo->pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_INACTIVE;
            }

#if( COM_TXPDU_TPTYPE_SUPPORT == STD_ON )
            /* Tp Type Processing. */
            Com_PduTxTpProcess(PduInfo);
#endif /* COM_TXPDU_TPTYPE_SUPPORT == STD_ON */
        }
    }
    else if( COM_PDU_TRIG_ACTIVE_WP == PduInfo->pduTriggerMonitor->pduTriggerSta )
    {
#if( COM_TRIGRESETCYCTIMER_SUPPORT == STD_ON )
        PduInfo->pduTriggerMonitor->Com_ResetCycTimerFlag = TRUE;
#endif
#if( (COM_METADATA_SUPPORT == STD_ON) && (COM_TXMETADATA_NUM > COM_INIT_ZERO) )
        /* The PduInfo sending is triggered by Com_TriggerIPDUSendWithMetaData. */
        if( (COM_PDU_NO_METADATA_DEF != PduInfo->acMetaDataIdx)
            && (TRUE == Com_TxPduMonMetaData[PduInfo->acMetaDataIdx].triggerMetaDataEnable) )
        {
            stdRet = Com_OnePduSendByMetaDataTrigger(PduInfo);
            Com_TxPduMonMetaData[PduInfo->acMetaDataIdx].triggerMetaDataEnable = FALSE;
        }
        else
#endif  /* ( (COM_METADATA_SUPPORT == STD_ON) && (COM_TXMETADATA_NUM > COM_INIT_ZERO) ) */
        {
            stdRet = Com_OnePduSend(PduInfo);
        }
        if( (Std_ReturnType)E_OK == stdRet )
        {
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            PduInfo->astPduInterMonitor->pduSta = COM_PDU_STA_WAITCONFIRM;
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            PduInfo->pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_INACTIVE;
            /* Set Number Of Repetitions and Repetition Period to 0. */
            PduInfo->pduTriggerMonitor->pduTrgCycCounter = COM_INIT_ZERO;
            PduInfo->pduTriggerMonitor->pduSendRemainCnt = COM_INIT_ZERO;

#if( COM_TXPDU_TPTYPE_SUPPORT == STD_ON )
            /* Tp Type Processing. */
            Com_PduTxTpProcess(PduInfo);
#endif /* COM_TXPDU_TPTYPE_SUPPORT == STD_ON */
        }
    }
    else if( COM_PDU_TRIG_PROCESSING == PduInfo->pduTriggerMonitor->pduTriggerSta )
    {
#if( COM_TRIGRESETCYCTIMER_SUPPORT == STD_ON )
        PduInfo->pduTriggerMonitor->Com_ResetCycTimerFlag = TRUE;
#endif
        /* Processing Unfinished triggered transmission. */
        if( COM_INIT_ZERO != PduInfo->pduTriggerMonitor->pduTrgCycCounter )
        {
            PduInfo->pduTriggerMonitor->pduTrgCycCounter--;
        }
        if( COM_INIT_ZERO == PduInfo->pduTriggerMonitor->pduTrgCycCounter )
        {
            stdRet = Com_OnePduSend(PduInfo);
            if( (Std_ReturnType)E_OK == stdRet )
            {
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                PduInfo->astPduInterMonitor->pduSta = COM_PDU_STA_WAITCONFIRM;
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                if( COM_INIT_ZERO == PduInfo->pduTriggerMonitor->pduSendRemainCnt )
                {
                    PduInfo->pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_INACTIVE;
                }
                else
                {
                    PduInfo->pduTriggerMonitor->pduSendRemainCnt--;
                    PduInfo->pduTriggerMonitor->pduTrgCycCounter = RepetionPeriod;
                }
            }
        }
    }
    else
    {
        /* Do nothing. */
    }
#endif  /* COM_TXPDU_MDT_SUPPORT == STD_ON */
}

/*
********************************************************************************
* Function Name: Com_PduCycleSend
*
* Explanation: Periodic message sending processing.
*
* param: PduInfo: Tx Pdu Info.
*        PduCycle: Message cycle.
*
* retval: None
********************************************************************************
*/
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_PduCycleSend
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo,
    uint16 PduCycle
)
{
    Std_ReturnType stdRet;

#if( COM_TXPDU_MDT_SUPPORT == STD_ON )
    if( COM_MDTCOUNTER_ZERO != PduInfo->acMinimumDelayTime )
    {
        /* MDT Function. */
        boolean pduDelaySendFlag = FALSE;

        /* Count of sending cycles. */
        if( COM_INIT_ZERO != PduInfo->astPduInterMonitor->pduCycCounter )
        {
            PduInfo->astPduInterMonitor->pduCycCounter--;
        }
        if(NULL_PTR != PduInfo->pduTriggerMonitor)
        {
            /* Has the pdu been delayed in the past? */
            if( ((COM_MDTFORTRG_READY == PduInfo->pduTriggerMonitor->pduTrgMDTState) && (TRUE == PduInfo->astPduInterMonitor->pduCycDelayFlag)) ||
               ((COM_MDTFORCYC_READY == PduInfo->astPduInterMonitor->pduCycMDTState) && (TRUE == PduInfo->astPduInterMonitor->pduCycDelayFlag)) )
            {
                /*It's a delayed transmission.*/
                pduDelaySendFlag = TRUE;
            }
            /* The timeout time reached or the Pdu that have been delayed in transmitting. */
            if( (COM_INIT_ZERO == PduInfo->astPduInterMonitor->pduCycCounter) || (TRUE == pduDelaySendFlag) )
            {
                /* Determine if the time interval requirements for MDT are met. */
                if( (COM_MDTCOUNTER_ZERO == PduInfo->pduTriggerMonitor->pduTrgCycCntForMDT) &&
                    (COM_MDTCOUNTER_ZERO == PduInfo->astPduInterMonitor->pduCycCntForMDT) )
                {
                    /* Pdu Tx. */
                    stdRet = Com_OnePduSend(PduInfo);
                    /* Transmission ok? */
                    if( (Std_ReturnType)E_OK == stdRet )
                    {
                        /* Wait Com_TxConfirmation. */
                        PduInfo->astPduInterMonitor->pduSta = COM_PDU_STA_WAITCONFIRM;
                        PduInfo->astPduInterMonitor->pduGwSendFlag = TRUE;
                        /* The PDU sent this time is in Cycle mode. */
                        PduInfo->astPduInterMonitor->CycSendFlag = TRUE;
                        /* There is no delayed PDU. */
                        PduInfo->astPduInterMonitor->pduCycDelayFlag = FALSE;
#if( COM_TXPDU_TPTYPE_SUPPORT == STD_ON )
                        /* Tp Type Processing. */
                        Com_PduTxTpProcess(PduInfo);
#endif /* COM_TXPDU_TPTYPE_SUPPORT == STD_ON */
#if( COM_RETRY_FAILED_TRANSMIT_REQUESTS == STD_ON )
                        /* SWS_Com_00828,start the minimum delay time counter upon transmission of that I-PDU
                                to the PDU Router via PduR_ComTransmit only in case PduR_ComTransmit returns E_OK. */
                        if( COM_MDTCOUNTER_ZERO != PduInfo->acMinimumDelayTime )
                        {
                                /* MDT start. */
                            PduInfo->astPduInterMonitor->pduCycCntForMDT = PduInfo->acMinimumDelayTime;
                            PduInfo->astPduInterMonitor->pduCycMDTState = COM_MDTFORCYC_START;
                        }
#endif /* COM_RETRY_FAILED_TRANSMIT_REQUESTS == STD_ON */
                    }
#if( COM_RETRY_FAILED_TRANSMIT_REQUESTS != STD_ON )
                    /* SWS_Com_00698,and start the minimum delay time counter upon transmission of
                        that I-PDU to the PDU Router via PduR_ComTransmit. */
                    if( COM_MDTCOUNTER_ZERO != PduInfo->acMinimumDelayTime )
                    {
                        /* MDT start. */
                        PduInfo->astPduInterMonitor->pduCycCntForMDT = PduInfo->acMinimumDelayTime;
                        PduInfo->astPduInterMonitor->pduCycMDTState = COM_MDTFORCYC_START;
                    }
#endif /* COM_RETRY_FAILED_TRANSMIT_REQUESTS != STD_ON */
                    /* Is this a delayed transmission? */
                    if( FALSE == pduDelaySendFlag )
                    {
                        /*Perform cycle counting normally*/
                        PduInfo->astPduInterMonitor->pduCycCounter = PduCycle;
#if( COM_RETRY_FAILED_TRANSMIT_REQUESTS == STD_ON )
                        if( (Std_ReturnType)E_NOT_OK == stdRet )
                        {
                            /* Next Com_MainFunctionTx send again. SWS_Com_00773 */
                            PduInfo->astPduInterMonitor->pduCycCounter = COM_INIT_ZERO;
                        }
#endif  /* COM_RETRY_FAILED_TRANSMIT_REQUESTS == STD_ON */
                    }
                    else
                    {
#if( COM_RETRY_FAILED_TRANSMIT_REQUESTS == STD_ON )
                        if( (Std_ReturnType)E_NOT_OK == stdRet )
                        {
                            /* Next Com_MainFunctionTx send again. SWS_Com_00773 */
                            PduInfo->astPduInterMonitor->pduCycDelayFlag = TRUE;
                        }
#endif  /* COM_RETRY_FAILED_TRANSMIT_REQUESTS == STD_ON */
                    }
                }
                else
                {
                    if( TRUE != PduInfo->astPduInterMonitor->pduCycDelayFlag )
                    {
                        /* Reset sending cycle. */
                        PduInfo->astPduInterMonitor->pduCycCounter = PduCycle;
                        /* This transmission was delayed due to MDT. */
                        PduInfo->astPduInterMonitor->pduCycDelayFlag = TRUE;
                    }
                    else
                    {
                        if( COM_INIT_ZERO == PduInfo->astPduInterMonitor->pduCycCounter )
                        {
                            PduInfo->astPduInterMonitor->pduCycCounter = PduCycle;
                        }
                    }
                }
            }
        }
        else  /* Pdu periodic tx process without MDT. */
        {
                /* The timeout time reached. */
                if( COM_INIT_ZERO == PduInfo->astPduInterMonitor->pduCycCounter )
                {
                    /* Pdu Tx. */
                    stdRet = Com_OnePduSend(PduInfo);
                    if( (Std_ReturnType)E_OK == stdRet )
                    {
                        /* Wait Com_TxConfirmation. */
                        PduInfo->astPduInterMonitor->pduSta = COM_PDU_STA_WAITCONFIRM;
                        PduInfo->astPduInterMonitor->pduGwSendFlag = TRUE;
                        PduInfo->astPduInterMonitor->CycSendFlag = TRUE;
#if( COM_TXPDU_TPTYPE_SUPPORT == STD_ON )
                    /* Tp Type Processing. */
                        Com_PduTxTpProcess(PduInfo);
#endif /* COM_TXPDU_TPTYPE_SUPPORT == STD_ON */
                    }
                    PduInfo->astPduInterMonitor->pduCycCounter = PduCycle;

#if( COM_RETRY_FAILED_TRANSMIT_REQUESTS == STD_ON )
                    if( (Std_ReturnType)E_NOT_OK == stdRet )
                    {
                        /* Next Com_MainFunctionTx send again. SWS_Com_00773 */
                        PduInfo->astPduInterMonitor->pduCycCounter = COM_INIT_ZERO;
                    }
#endif /* COM_RETRY_FAILED_TRANSMIT_REQUESTS == STD_ON */
                }
        }
    }
    else
    {
        if( COM_INIT_ZERO != PduInfo->astPduInterMonitor->pduCycCounter )
        {
            PduInfo->astPduInterMonitor->pduCycCounter--;
        }

        /* The timeout time reached. */
        if( COM_INIT_ZERO == PduInfo->astPduInterMonitor->pduCycCounter )
        {
            /* Pud Tx. */
            stdRet = Com_OnePduSend(PduInfo);
            if( (Std_ReturnType)E_OK == stdRet )
            {
                PduInfo->astPduInterMonitor->pduSta = COM_PDU_STA_WAITCONFIRM;
                PduInfo->astPduInterMonitor->pduGwSendFlag = TRUE;

#if( COM_TXPDU_TPTYPE_SUPPORT == STD_ON )
                /* Tp Type Processing. */
                Com_PduTxTpProcess(PduInfo);
#endif /* COM_TXPDU_TPTYPE_SUPPORT == STD_ON */
            }
            PduInfo->astPduInterMonitor->pduCycCounter = PduCycle;

#if( COM_RETRY_FAILED_TRANSMIT_REQUESTS == STD_ON )
            if( (Std_ReturnType)E_NOT_OK == stdRet )
            {
                /* Next Com_MainFunctionTx send again. SWS_Com_00773 */
                PduInfo->astPduInterMonitor->pduCycCounter = COM_INIT_ZERO;
            }
#endif  /* COM_RETRY_FAILED_TRANSMIT_REQUESTS == STD_ON */
        }
    }
#else   /* No MDT Function. */
    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
    if( COM_INIT_ZERO != PduInfo->astPduInterMonitor->pduCycCounter )
    {
        PduInfo->astPduInterMonitor->pduCycCounter--;
    }

    /* The timeout time reached. */
    if( COM_INIT_ZERO == PduInfo->astPduInterMonitor->pduCycCounter )
    {
        /* Pud Tx. */
        stdRet = Com_OnePduSend(PduInfo);
        if( (Std_ReturnType)E_OK == stdRet )
        {
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            PduInfo->astPduInterMonitor->pduSta = COM_PDU_STA_WAITCONFIRM;
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            PduInfo->astPduInterMonitor->pduGwSendFlag = TRUE;

#if( COM_TXPDU_TPTYPE_SUPPORT == STD_ON )
            /* Tp Type Processing. */
            Com_PduTxTpProcess(PduInfo);
#endif /* COM_TXPDU_TPTYPE_SUPPORT == STD_ON */
        }
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        PduInfo->astPduInterMonitor->pduCycCounter = PduCycle;

#if( COM_RETRY_FAILED_TRANSMIT_REQUESTS == STD_ON )
        if( (Std_ReturnType)E_NOT_OK == stdRet )
        {
            /* Next Com_MainFunctionTx send again. SWS_Com_00773 */
            PduInfo->astPduInterMonitor->pduCycCounter = COM_INIT_ZERO;
        }
#endif  /* COM_RETRY_FAILED_TRANSMIT_REQUESTS == STD_ON */

    }
#endif  /* COM_TXPDU_MDT_SUPPORT == STD_ON */
}

/*
********************************************************************************
* Function Name: Com_PduIfActiveSend
*
* Explanation: If active message sending process.
*
* param: PduInfo: Tx Pdu Info
*        PduCycleFast: Tx Pdu transmission period fast
*        numberofRepetion: Number of tx Pdu transmission repetition
*        RepetionPeriod: Period of tx Pdu transmission repetition
* retval: None
********************************************************************************
*/
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_PduIfActiveSend
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo,
    uint16 PduCycleFast,
    uint16 numberofRepetion,
    uint16 RepetionPeriod
)
{
    Com_SigType txSignalType;
    uint16 sigIndex = COM_INIT_ZERO;
    uint16 sigLengthIndex;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxSignalInfo_st* txSigInfo = Com_TxSignalInfo;
    uint8 pduSendFlag = FALSE;
    for( sigIndex = PduInfo->awSigStartIndex; sigIndex < PduInfo->awSigEndIndex; sigIndex++ )
    {
        if( COM_TRANS_TRIGGERED_ON_IF_ACTIVE == txSigInfo[sigIndex].sigTransferProperty )
        {
            /* Obtain signal type. */
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
            txSignalType = txSigInfo[sigIndex].sigType;
#else  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
            txSignalType = Com_GetSignalType(txSigInfo[sigIndex].sigBaseInfo->sigFuncIdx);
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
            /* Judge signal type. */
            /* PolySpace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_Com_16.1" */
            switch( txSignalType )
            {
                case COM_SIGTYPE_BOOLEAN:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    if( (*(boolean*)txSigInfo[sigIndex].sigValShadowBufPtr) != (*(boolean*)txSigInfo[sigIndex].sigInactiveValue) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                    {
                        pduSendFlag = TRUE;
                    }
                    break;
                case COM_SIGTYPE_UINT8:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    if( (*(uint8*)txSigInfo[sigIndex].sigValShadowBufPtr) != (*(uint8*)txSigInfo[sigIndex].sigInactiveValue) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                    {
                        pduSendFlag = TRUE;
                    }
                    break;
                case COM_SIGTYPE_UINT16:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    if( (*(uint16*)txSigInfo[sigIndex].sigValShadowBufPtr) != (*(uint16*)txSigInfo[sigIndex].sigInactiveValue) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                    {
                        pduSendFlag = TRUE;
                    }
                    break;
                case COM_SIGTYPE_UINT32:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    if( (*(uint32*)txSigInfo[sigIndex].sigValShadowBufPtr) != (*(uint32*)txSigInfo[sigIndex].sigInactiveValue) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                    {
                        pduSendFlag = TRUE;
                    }
                    break;
                case COM_SIGTYPE_UINT64:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    if( (*(uint64*)txSigInfo[sigIndex].sigValShadowBufPtr) != (*(uint64*)txSigInfo[sigIndex].sigInactiveValue) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                    {
                        pduSendFlag = TRUE;
                    }
                    break;
                case COM_SIGTYPE_SINT8:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    if( (*(sint8*)txSigInfo[sigIndex].sigValShadowBufPtr) != (*(sint8*)txSigInfo[sigIndex].sigInactiveValue) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                    {
                        pduSendFlag = TRUE;
                    }
                    break;
                case COM_SIGTYPE_SINT16:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    if( (*(sint16*)txSigInfo[sigIndex].sigValShadowBufPtr) != (*(sint16*)txSigInfo[sigIndex].sigInactiveValue) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                    {
                        pduSendFlag = TRUE;
                    }
                    break;
                case COM_SIGTYPE_SINT32:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    if( (*(sint32*)txSigInfo[sigIndex].sigValShadowBufPtr) != (*(sint32*)txSigInfo[sigIndex].sigInactiveValue) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                    {
                        pduSendFlag = TRUE;
                    }
                    break;
                case COM_SIGTYPE_SINT64:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    if( (*(sint64*)txSigInfo[sigIndex].sigValShadowBufPtr) != (*(sint64*)txSigInfo[sigIndex].sigInactiveValue) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                    {
                        pduSendFlag = TRUE;
                    }
                    break;
                case COM_SIGTYPE_FLOAT32:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    if( FALSE == Com_CompareFloat32Values((*(float32*)txSigInfo[sigIndex].sigValShadowBufPtr),(*(float32*)txSigInfo[sigIndex].sigInactiveValue)) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                    {
                        pduSendFlag = TRUE;
                    }
                    break;
                case COM_SIGTYPE_FLOAT64:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    if( FALSE == Com_CompareFloat64Values((*(float64*)txSigInfo[sigIndex].sigValShadowBufPtr),(*(float64*)txSigInfo[sigIndex].sigInactiveValue)) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                    {
                        pduSendFlag = TRUE;
                    }
                    break;
                case COM_SIGTYPE_UINT8_DYN:

                    break;
                case COM_SIGTYPE_UINT8_N:
                    for( sigLengthIndex = COM_INIT_ZERO; sigLengthIndex < txSigInfo[sigIndex].sigBaseInfo->sigByteLength; sigLengthIndex++ )
                    {
                        /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                        if( ((uint8*)txSigInfo[sigIndex].sigValShadowBufPtr)[sigLengthIndex] != ((uint8*)txSigInfo[sigIndex].sigInactiveValue)[sigLengthIndex] )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                        {
                            pduSendFlag = TRUE;
                            break;
                        }
                    }
                    break;
                /* PolySpace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_Com_16.4" */
                default:
                    break;
            }
            if( TRUE == pduSendFlag )
            {
                /* Set the trigger state to active, triggers the next sending in case the next pduSendFlag is false. */
                PduInfo->pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_ACTIVE;
                break;
            }
        }
    }
    if( TRUE == pduSendFlag )
    {
        /* If the signal value is not equal to the inactive value, and the periodic sending of message is triggered. */
        Com_PduCycleSend(PduInfo, PduCycleFast);
    }
    else
    {
        if( COM_PDU_TRIG_INACTIVE != PduInfo->pduTriggerMonitor->pduTriggerSta )
        {
            /* Sending flag is false, leads to several repetion message sending with a faster sending cycle. */
            Com_PduTriggerSend(PduInfo, numberofRepetion, RepetionPeriod);
        }
    }
}

/*
********************************************************************************
* Function Name: Com_PduPeriodicIfActiveSend
*
* Explanation: Periodic if active message sending process.
*
* param: PduInfo: Tx Pdu Info
*        PduCycle: Tx Pdu transmission period
*        PduCycleFast: Tx Pdu fast transmission period
*        numberofRepetion: Number of tx Pdu transmission repetition
*        RepetionPeriod: Period of tx Pdu transmission repetition
*
* retval: None
********************************************************************************
*/
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_PduPeriodicIfActiveSend
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo,
    uint16 PduCycle,
    uint16 PduCycleFast,
    uint16 numberofRepetion,
    uint16 RepetionPeriod
)
{
    Com_SigType txSignalType;
    uint16 sigIndex = COM_INIT_ZERO;
    uint16 sigLengthIndex;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxSignalInfo_st* txSigInfo = Com_TxSignalInfo;
    uint8 pduSendFlag = FALSE;
    for( sigIndex = PduInfo->awSigStartIndex; sigIndex < PduInfo->awSigEndIndex; sigIndex++ )
    {
        if( COM_TRANS_TRIGGERED_ON_IF_ACTIVE == txSigInfo[sigIndex].sigTransferProperty )
        {
            /* Obtain signal type. */
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
            txSignalType = txSigInfo[sigIndex].sigType;
#else  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
            txSignalType = Com_GetSignalType(txSigInfo[sigIndex].sigBaseInfo->sigFuncIdx);
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
            /* Judge signal type. */
            /* PolySpace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_Com_16.1" */
            switch( txSignalType )
            {
                case COM_SIGTYPE_BOOLEAN:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    if( (*(boolean*)txSigInfo[sigIndex].sigValShadowBufPtr) != (*(boolean*)txSigInfo[sigIndex].sigInactiveValue) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                    {
                        pduSendFlag = TRUE;
                    }
                    break;
                case COM_SIGTYPE_UINT8:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    if( (*(uint8*)txSigInfo[sigIndex].sigValShadowBufPtr) != (*(uint8*)txSigInfo[sigIndex].sigInactiveValue) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                    {
                        pduSendFlag = TRUE;
                    }
                    break;
                case COM_SIGTYPE_UINT16:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    if( (*(uint16*)txSigInfo[sigIndex].sigValShadowBufPtr) != (*(uint16*)txSigInfo[sigIndex].sigInactiveValue) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                    {
                        pduSendFlag = TRUE;
                    }
                    break;
                case COM_SIGTYPE_UINT32:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    if( (*(uint32*)txSigInfo[sigIndex].sigValShadowBufPtr) != (*(uint32*)txSigInfo[sigIndex].sigInactiveValue) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                    {
                        pduSendFlag = TRUE;
                    }
                    break;
                case COM_SIGTYPE_UINT64:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    if( (*(uint64*)txSigInfo[sigIndex].sigValShadowBufPtr) != (*(uint64*)txSigInfo[sigIndex].sigInactiveValue) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                    {
                        pduSendFlag = TRUE;
                    }
                    break;
                case COM_SIGTYPE_SINT8:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    if( (*(sint8*)txSigInfo[sigIndex].sigValShadowBufPtr) != (*(sint8*)txSigInfo[sigIndex].sigInactiveValue) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                    {
                        pduSendFlag = TRUE;
                    }
                    break;
                case COM_SIGTYPE_SINT16:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    if( (*(sint16*)txSigInfo[sigIndex].sigValShadowBufPtr) != (*(sint16*)txSigInfo[sigIndex].sigInactiveValue) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                    {
                        pduSendFlag = TRUE;
                    }
                    break;
                case COM_SIGTYPE_SINT32:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    if( (*(sint32*)txSigInfo[sigIndex].sigValShadowBufPtr) != (*(sint32*)txSigInfo[sigIndex].sigInactiveValue) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                    {
                        pduSendFlag = TRUE;
                    }
                    break;
                case COM_SIGTYPE_SINT64:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    if( (*(sint64*)txSigInfo[sigIndex].sigValShadowBufPtr) != (*(sint64*)txSigInfo[sigIndex].sigInactiveValue) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                    {
                        pduSendFlag = TRUE;
                    }
                    break;
                case COM_SIGTYPE_FLOAT32:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    if( FALSE == Com_CompareFloat32Values((*(float32*)txSigInfo[sigIndex].sigValShadowBufPtr),(*(float32*)txSigInfo[sigIndex].sigInactiveValue)) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                    {
                        pduSendFlag = TRUE;
                    }
                    break;
                case COM_SIGTYPE_FLOAT64:
                    /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                    if( FALSE == Com_CompareFloat64Values((*(float64*)txSigInfo[sigIndex].sigValShadowBufPtr),(*(float64*)txSigInfo[sigIndex].sigInactiveValue)) )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                    {
                        pduSendFlag = TRUE;
                    }
                    break;
                case COM_SIGTYPE_UINT8_DYN:

                    break;
                case COM_SIGTYPE_UINT8_N:
                    for( sigLengthIndex = COM_INIT_ZERO; sigLengthIndex < txSigInfo[sigIndex].sigBaseInfo->sigByteLength; sigLengthIndex++ )
                    {
                        /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
                        if( ((uint8*)txSigInfo[sigIndex].sigValShadowBufPtr)[sigLengthIndex] != ((uint8*)txSigInfo[sigIndex].sigInactiveValue)[sigLengthIndex] )  /* PRQA S 0316, 0311 */ /* NSCA_QAC_Com_Rule11.5, NSCA_QAC_Com_Rule11.8 */
                        {
                            pduSendFlag = TRUE;
                            break;
                        }
                    }
                    break;
                /* PolySpace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_Com_16.4" */
                default:
                    break;
            }
            if( TRUE == pduSendFlag )
            {
                /* Set the trigger state to active, triggers the next sending in case the next pduSendFlag is false. */
                PduInfo->pduTriggerMonitor->pduTriggerSta = COM_PDU_TRIG_ACTIVE;
                break;
            }
        }
    }
    if( TRUE == pduSendFlag )
    {
        /* If the signal value is not equal to the inactive value, and the faster message sending is triggered. */
        Com_PduCycleSend(PduInfo, PduCycleFast);
    }
    else
    {
        if( COM_PDU_TRIG_INACTIVE != PduInfo->pduTriggerMonitor->pduTriggerSta )
        {
            /* Repetition message sending */
            Com_PduTriggerSend(PduInfo, numberofRepetion, RepetionPeriod);
        }
        else
        {
            /* Message sending with the normal sending cycle. */
            Com_PduCycleSend(PduInfo, PduCycle);
        }
    }
}

/*
********************************************************************************
* Function Name: Com_PduPrediocTxProcess
*
* Explanation: Periodic Tx Pdu Process.
*
* param: PduInfo: Tx Pdu Info.
*        PduCycle:Tx Pdu Cycle.
*        PduDelayThreshold:Tx Pdu Delay Threshold.
*
* retval: None
********************************************************************************
*/
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_PduPeriodicTxProcess
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo,
    uint16 PduCycle
)
{
#if( COM_TXPDU_MDT_SUPPORT == STD_ON )
    /* Update MDT count for all Tx Pdu. */
    if( COM_MDTCOUNTER_ZERO != PduInfo->acMinimumDelayTime )
    {
        Com_MDTCounter(PduInfo);
    }
#endif
    Com_PduCycleSend(PduInfo, PduCycle);
}

/*
********************************************************************************
* Function Name: Com_PduDirectTxProcess
*
* Explanation: Tx Pdu Mode Mode Direct Type Process.
*
* param: PduInfo: Tx Pdu Info.
*
* retval: None
********************************************************************************
*/
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_PduDirectTxProcess
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo,
    uint16 numberofRepetion,
    uint16 RepetionPeriod
)
{
#if( COM_TXPDU_MDT_SUPPORT == STD_ON )
    /* Update MDT count for all Tx Pdu. */
    if( COM_MDTCOUNTER_ZERO != PduInfo->acMinimumDelayTime )
    {
        Com_MDTCounter(PduInfo);
    }
#endif
    Com_PduTriggerSend(PduInfo, numberofRepetion, RepetionPeriod);
}

/*
********************************************************************************
* Function Name: Com_PduMixTxProcess
*
* Explanation: Tx Pdu Mode Mode Mix Type Process.
*
* param: PduInfo: Tx Pdu Info.
*
* retval: None
********************************************************************************
*/
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_PduMixTxProcess
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo,
    uint16 PduCycle,
    uint16 numberofRepetion,
    uint16 RepetionPeriod
)
{
#if( COM_TXPDU_MDT_SUPPORT == STD_ON )
    /* Update MDT count for all Tx Pdu. */
    if( COM_MDTCOUNTER_ZERO != PduInfo->acMinimumDelayTime )
    {
        Com_MDTCounter(PduInfo);
    }
#endif
    Com_PduTriggerSend(PduInfo, numberofRepetion, RepetionPeriod);
#if( COM_TRIGRESETCYCTIMER_SUPPORT == STD_ON )
    if( TRUE == PduInfo->pduTriggerMonitor->Com_ResetCycTimerFlag )
    {
        PduInfo->astPduInterMonitor->pduCycCounter = PduCycle;
        PduInfo->pduTriggerMonitor->Com_ResetCycTimerFlag = FALSE;
    }
    else
#endif
    {
        Com_PduCycleSend(PduInfo, PduCycle);
    }
}

/*
********************************************************************************
* Function Name: Com_PduIfActiveTxProcess
*
* Explanation: Tx Pdu Mode If active Type Process.
*
* param: PduInfo: Tx Pdu Info
*        PduCycleFast: Tx Pdu transmission period fast
*        numberofRepetion: Number of tx Pdu transmission repetition
*        RepetionPeriod: Period of tx Pdu transmission repetition
* retval: None
********************************************************************************
*/
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_PduIfActiveTxProcess
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo,
    uint16 PduCycleFast,
    uint16 numberofRepetion,
    uint16 RepetionPeriod
)
{
#if( COM_TXPDU_MDT_SUPPORT == STD_ON )
    /* Update MDT count for all Tx Pdu. */
    if( COM_MDTCOUNTER_ZERO != PduInfo->acMinimumDelayTime )
    {
        Com_MDTCounter(PduInfo);
    }
#endif
    Com_PduIfActiveSend(PduInfo, PduCycleFast, numberofRepetion, RepetionPeriod);
}

/*
********************************************************************************
* Function Name: Com_PduPeriodicIfActiveTxProcess
*
* Explanation: Tx Pdu Mode Periodic If active Type Process.
*
* param: PduInfo: Tx Pdu Info
*        PduCycle: Tx Pdu transmission period
*        PduCycleFast: Tx Pdu fast transmission period
*        numberofRepetion: Number of tx Pdu transmission repetition
*        RepetionPeriod: Period of tx Pdu transmission repetition
* retval: None
********************************************************************************
*/
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_PduPeriodicIfActiveTxProcess
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo,
    uint16 PduCycle,
    uint16 PduCycleFast,
    uint16 numberofRepetion,
    uint16 RepetionPeriod
)
{
#if( COM_TXPDU_MDT_SUPPORT == STD_ON )
    /* Update MDT count for all Tx Pdu. */
    if( COM_MDTCOUNTER_ZERO != PduInfo->acMinimumDelayTime )
    {
        Com_MDTCounter(PduInfo);
    }
#endif
    Com_PduPeriodicIfActiveSend(PduInfo, PduCycle, PduCycleFast, numberofRepetion, RepetionPeriod);
}

#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Com_SigTxClearUb
*
* Explanation: Clear signal update bit.
*
* param: bitPos: Bit position.
*        pduId: The ID of Pdu which the signal belong to.
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.5" */
static FUNC(void, COM_CODE) Com_SigTxClearUb(uint16 bitPos, PduIdType pduId)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.5" */
    uint8 value;
    uint16 bytePos;
    uint16 bitPosInByte;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxPduInfo_st* txPduPtr = &Com_TxPduInfo[pduId];

    /* Calculate the position of the updatebit in the array. */
    bytePos = (bitPos / COM_1BYTE_BITLENGTH);
    bitPosInByte = (bitPos % COM_1BYTE_BITLENGTH);
    /* Clear the value of the update bit. */
    value = (~(uint8)(COM_OPERAND_ONE << bitPosInByte));
    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
    txPduPtr->dataRaw[bytePos] &= value;
}
#endif

#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Com_TxPduClearUb_Process
*
* Explanation: Tx Pdu Clear Update Bit.
*
* param: PduInfo: Tx Pdu Info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxPduClearUb_Process
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
)
{
    uint16 sigIndex;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxSignalInfo_st* txSigInfo = Com_TxSignalInfo;

 #if( COM_TXSIGGROUPINFO == STD_ON )
    uint16 sigGrpIndex;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxSigGrpInfo_st* txSIgGrpPtr = Com_TxSigGrpInfo;
#endif

    /* Clear all update bits of the signal in the message. */
    for( sigIndex = PduInfo->awSigStartIndex; sigIndex < PduInfo->awSigEndIndex; sigIndex++ )
    {
        if( COM_SIG_NO_UPDATEBIT_DEF != txSigInfo[sigIndex].updateBitSigIndex )
        {
            Com_SigTxClearUb(txSigInfo[sigIndex].updateBitSigIndex, txSigInfo[sigIndex].acPduId);
        }
    }

 #if( COM_TXSIGGROUPINFO == STD_ON )
    /* Clear all update bits of the signal group in the message. */
    for( sigGrpIndex = PduInfo->acSigGrpStartIndex; sigGrpIndex < PduInfo->acSigGrpEndIndex; sigGrpIndex++ )
    {
#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
        if( COM_SIG_NO_UPDATEBIT_DEF != txSIgGrpPtr[sigGrpIndex].updateBitSigIndex )
        {
            Com_SigTxClearUb(txSIgGrpPtr[sigGrpIndex].updateBitSigIndex, txSIgGrpPtr[sigGrpIndex].awPduId);
        }
#endif  /* COM_TXUPDATEBITCFG_SUPPORT == STD_ON */
    }
#endif

}
#endif  /* COM_TXUPDATEBITCFG_SUPPORT == STD_ON */

/*
********************************************************************************
* Function Name: Com_TxConfirmationProcess
*
* Explanation: Tx Pdu Confirmation Process.
*
* param: TxPduId: Tx Pdu Id.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxConfirmationProcess( PduIdType TxPduId )
{
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxPduInfo_st* astPduInfo = &Com_TxPduInfo[TxPduId];

#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
    /* Clearing the update bit is done by sending txconfirmation. */
    if( COM_PDU_CLEARUB_TXCFM == astPduInfo->acPduClearUpdateBit )
    {
        Com_TxPduClearUb_Process(astPduInfo);
    }
#endif

    /* if Pdu Signal Process is Immedaite ,call notification. */
    if( COM_PDU_SIGPRCS_IMMEDIATE == astPduInfo->acSignalProcessType )
    {
        if( COM_PDU_STA_INACTIVE != astPduInfo->astPduInterMonitor->pduSta )
        {
            astPduInfo->astPduInterMonitor->pduSta = COM_PDU_STA_ACTIVE;
        }
#if( COM_TXPDU_CBKNOTIFTY_SUPPORT == STD_ON )
        Com_TxCfrmNotifition_Process(TxPduId);
#endif
    }
    else
    {
        if( COM_PDU_STA_INACTIVE != astPduInfo->astPduInterMonitor->pduSta )
        {
            astPduInfo->astPduInterMonitor->pduSta = COM_PDU_STA_CONFIRM;
        }
    }
}

#if( COM_TXPDU_CBKNOTIFTY_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Com_TxDeferredProcess
*
* Explanation: Pdu delayed time processing.
*
* param: PduId: tx pdu index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxDeferredProcess(PduIdType PduId)
{
    const COM_TxPduInfo_st* astPduInfo = &Com_TxPduInfo[PduId];

    if( NULL_PTR != astPduInfo->astPduInterMonitor )
    {
        if( COM_PDU_STA_CONFIRM == astPduInfo->astPduInterMonitor->pduSta )
        {
            astPduInfo->astPduInterMonitor->pduSta = COM_PDU_STA_ACTIVE;
#if( COM_TXPDU_CBKNOTIFTY_SUPPORT == STD_ON )
            Com_TxCfrmNotifition_Process(PduId);
#endif
        }
    }
}

/*
********************************************************************************
* Function Name: Com_TxCfrmNotifition_Process
*
* Explanation: Tx Confirmation Notify Process.
*
* param: TxPduId: Tx Pdu Id.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxCfrmNotifition_Process(PduIdType TxPduId)
{
#if( (COM_TXSIGGROUPINFO == STD_ON) && (COM_TXSIGGRP_NOTIFICATION_SUPPORT == STD_ON) )
    uint16 SigGrpIdx;
#endif  /* (COM_TXSIGGROUPINFO == STD_ON) && (COM_TXSIGGRP_NOTIFICATION_SUPPORT == STD_ON) */
#if( COM_TXSIG_NOTIFICATION_SUPPORT == STD_ON )
    uint16 sigIdx;

    /* Find the pdu all related not in signal group's signals. */
    for( sigIdx = Com_TxPduInfo[TxPduId].awSigStartIndex; sigIdx < Com_TxPduInfo[TxPduId].awSigEndIndex; sigIdx++ )
    {
        if( COM_SIG_NO_GROUP_DEF == Com_TxSignalInfo[sigIdx].acSigGrpIdx )
        {
            if( NULL_PTR != Com_TxSignalInfo[sigIdx].Notification_p )
            {
                Com_TxSignalInfo[sigIdx].Notification_p();
            }
        }
    }
#endif  /* COM_TXSIG_NOTIFICATION_SUPPORT == STD_ON */

#if( (COM_TXSIGGROUPINFO == STD_ON) && (COM_TXSIGGRP_NOTIFICATION_SUPPORT == STD_ON) )
    /* Find the pdu all related signal group's signals. */
    for( SigGrpIdx = Com_TxPduInfo[TxPduId].acSigGrpStartIndex; SigGrpIdx < Com_TxPduInfo[TxPduId].acSigGrpEndIndex; SigGrpIdx++ )
    {
        if( NULL_PTR != Com_TxSigGrpInfo[SigGrpIdx].Notification_p )
        {
            Com_TxSigGrpInfo[SigGrpIdx].Notification_p();
        }
    }
#endif  /* (COM_TXSIGGROUPINFO == STD_ON) && (COM_TXSIGGRP_NOTIFICATION_SUPPORT == STD_ON) */

}
#endif  /* COM_TXPDU_CBKNOTIFTY_SUPPORT == STD_ON */

/*
********************************************************************************
* Function Name: Com_IpduGrpCtrl_UpTxIPduSts
*
* Explanation: This service starts or stop Tx I-PDU groups.
*
* param: ipduGrpVector: I-PDU group vector containing the activation state
*                          (stopped = 0/ started = 1) for all I-PDU groups.
*        initialize: Flag to request initialization of the I-PDUs which are newly started.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_IpduGrpCtrl_UpTxIPduSts
(
    /* PolySpace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.13" */
    Com_IpduGroupVector ipduGrpVector,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    boolean initialize
)
{
    Com_PduTxStaType abReqActiveState;
    uint8 vectorBitOffset = COM_INIT_ZERO;
    uint8 vectorBitShift = COM_INIT_ZERO;
    uint16 vectorBytePos;
    uint16 vectorMatchPos;
    uint16 acPduIdx;
    uint16 pduGrpVectorIdx;
    const COM_TxPduInfo_st* com_astPdu = Com_TxPduInfo;

    for( acPduIdx = COM_INIT_ZERO; acPduIdx < COM_TXPDU_NUM; acPduIdx++ )
    {
        com_astPdu = &Com_TxPduInfo[acPduIdx];

        if( COM_PDU_TYPE_ACTIVE_CONTROL == com_astPdu->acPduActiveType )
        {
            abReqActiveState = COM_PDU_STA_INACTIVE;
            for( pduGrpVectorIdx = com_astPdu->acPduGrpVectorStartIdx;
              ((pduGrpVectorIdx < com_astPdu->acpduGrpVectorEndIdx )
                && (COM_PDU_STA_INACTIVE == abReqActiveState)); pduGrpVectorIdx++ )
            {
                vectorMatchPos = Com_PduGrpVectorMatch[pduGrpVectorIdx];
                vectorBytePos = vectorMatchPos / COM_1BYTE_BITLENGTH;
                vectorBitOffset = (uint8)(vectorMatchPos % COM_1BYTE_BITLENGTH);

                vectorBitShift = COM_OPERAND_ONE;
                vectorBitShift <<= vectorBitOffset;
                /* If at least one related ComIPduGroup is active the requested state is active. */
                /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Com_TAINTED_PTR" */
                if( COM_INIT_ZERO != ((uint8)ipduGrpVector[vectorBytePos] & vectorBitShift) )
                {
                    /* An I-PDU is active if and only if at least one I-PDU group is active it belongs to. */
                    abReqActiveState = COM_PDU_STA_ACTIVE;
                }
            }
            if( (COM_PDU_STA_INACTIVE == com_astPdu->astPduInterMonitor->pduSta)
                && (COM_PDU_STA_ACTIVE == abReqActiveState) )
            {
                /* Active Ipdu process. */
                Com_InitOneTxIPdu_CommonCnt(acPduIdx);
#if( (COM_METADATA_SUPPORT == STD_ON) && (COM_TXMETADATA_NUM > COM_INIT_ZERO) )
                if( COM_PDU_NO_METADATA_DEF != Com_TxPduInfo[acPduIdx].acMetaDataIdx )
                {
                    Com_TxPduMonMetaData[Com_TxPduInfo[acPduIdx].acMetaDataIdx].triggerMetaDataEnable = FALSE;
                }
#endif  /* ( (COM_METADATA_SUPPORT == STD_ON) && (COM_TXMETADATA_NUM > COM_INIT_ZERO) ) */
                /* Set the state of the Tx ComIPdu to active. */
                com_astPdu->astPduInterMonitor->pduSta = COM_PDU_STA_ACTIVE;
                /* all included Signal-Group update-bits shall be cleared. */
            }
            else if( (com_astPdu->astPduInterMonitor->pduSta != COM_PDU_STA_INACTIVE )
                && (COM_PDU_STA_INACTIVE == abReqActiveState) )
            {
                /* ComErrorNotification for outstanding not confirmed transmitted
                signals/ signal groups of the stopped I-PDU. */
                if( COM_PDU_STA_WAITCONFIRM == com_astPdu->astPduInterMonitor->pduSta )
                {
                    /* Call ComErrorNotification, if config. */
                    Com_TxErrorNotification(com_astPdu);
                }

                /* Inactive Ipdu process. */
                com_astPdu->astPduInterMonitor->pduSta = COM_PDU_STA_INACTIVE;
            }
            else
            {
                /* Do Nothing. */
            }

            if( (boolean)TRUE == initialize )
            {
                /* initialize Tx buffer */
                Com_InitOneTxIPdu_Allsig(acPduIdx);
                Com_InitOneIPdu_TxMode(acPduIdx, TRUE);
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Com_TxErrorNotification
*
* Explanation: Only valid on sender side: Name of Com_CbkTxErr callback function to be called..
*
* param: txPduInfo: Tx Pdu info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxErrorNotification
(
    P2CONST(COM_TxPduInfo_st, AUTOMATIC, COM_APPL_CONST) txPduInfo
)
{
#if( (COM_TXSIGGROUPINFO == STD_ON) && (COM_TXSIGGRP_ERRNOTIFICATION_SUPPORT == STD_ON) )
    uint16 grpIndex;
#endif  /* (COM_TXSIGGROUPINFO == STD_ON) && (COM_TXSIGGRP_ERRNOTIFICATION_SUPPORT == STD_ON) */

#if( COM_TXSIG_ERRNOTIFICATION_SUPPORT == STD_ON )
    uint16 sigIndex;
    /* Tx signal error cbk. */
    for( sigIndex = txPduInfo->awSigStartIndex; sigIndex < txPduInfo->awSigEndIndex; sigIndex++ )
    {
        if( COM_SIG_NO_GROUP_DEF == Com_TxSignalInfo[sigIndex].acSigGrpIdx )
        {
            if( NULL_PTR != Com_TxSignalInfo[sigIndex].ErrorNotification_p )
            {
                Com_TxSignalInfo[sigIndex].ErrorNotification_p();
            }
        }
    }
#endif  /* COM_TXSIG_ERRNOTIFICATION_SUPPORT == STD_ON */

#if( (COM_TXSIGGROUPINFO == STD_ON) && (COM_TXSIGGRP_ERRNOTIFICATION_SUPPORT == STD_ON) )
    /* Tx signal group error cbk. */
    for( grpIndex = txPduInfo->acSigGrpStartIndex; grpIndex < txPduInfo->acSigGrpEndIndex; grpIndex++ )
    {
        if( NULL_PTR != Com_TxSigGrpInfo[grpIndex].ErrorNotification_p )
        {
            Com_TxSigGrpInfo[grpIndex].ErrorNotification_p();
        }
    }
#endif  /* (COM_TXSIGGROUPINFO == STD_ON) && (COM_TXSIGGRP_ERRNOTIFICATION_SUPPORT == STD_ON) */
    COM_DUMMY_STATEMENT(txPduInfo);
}

/*
********************************************************************************
* Function Name: Com_TxSigWrite_Normal
*
* Explanation: Assign a value to a pdu.
*
* param: txSigInfoPtr: Tx signal info.
*        sigValueBuf: The value of the signal to be assigned.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxSigWrite_Normal
(
    P2CONST(COM_TxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) txSigInfoPtr,
    uint32 sigValueBuf
)
{
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    Com_SigEndianessType sigEndianess = Com_GetSignalEndianess(txSigInfoPtr->sigBaseInfo->sigFuncIdx);    /* Get endianess of signal. */
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    Com_SigBitLengthType sigBitLength = txSigInfoPtr->sigBaseInfo->sigBitLength;    /* Get bit length of signal. */
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    Com_SigByteLengthType sigByteLength = txSigInfoPtr->sigBaseInfo->sigByteLength; /* Get byte length of signal. */
    Com_SigByteLengthType sigByteLengthIndex;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    Com_SigStartBitType sigStartBit = txSigInfoPtr->sigBaseInfo->sigStartBit;       /* Get bit position in byte of signal. */
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    Com_SigStartByteType sigStartByte = txSigInfoPtr->sigBaseInfo->sigStartByte;    /* Get start byte position of signal. */
    uint32 sigValue = sigValueBuf;
    uint32 clearBit = COM_INIT_U32FF;
    uint32 clearBitLow =  COM_INIT_U32FF;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    uint8* pduDataPtr = Com_TxPduInfo[txSigInfoPtr->acPduId].dataRaw;

    /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_Com_SHF" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" */
    sigValue = (sigValue & (COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigBitLength)));

    if( COM_4BYTELENGTH < sigByteLength )
    {
        /* High 4 Byte Data. */
        sigValue = sigValue >> (COM_1BYTE_BITLENGTH - (sigStartBit % COM_1BYTE_BITLENGTH));
        /* High 4 Byte clearBit. */
        clearBit = ~((COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigBitLength)) >> (COM_1BYTE_BITLENGTH - (sigStartBit % COM_1BYTE_BITLENGTH)));
        /* Low 1 Byte Data. */
        /* PolySpace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
        sigValueBuf = sigValueBuf << (sigStartBit % COM_1BYTE_BITLENGTH);
        /* Low 1 Byte clearBit. */
        clearBitLow = ~( (uint32)COM_INIT_FF  << ((uint32 )sigStartBit % COM_1BYTE_BITLENGTH));
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < COM_4BYTELENGTH; sigByteLengthIndex++ )
        {
            if( COM_BIG_ENDIAN == sigEndianess )
            {
                pduDataPtr[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] =
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    (uint8)((uint32)pduDataPtr[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
                pduDataPtr[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] =
                    (uint8)((uint32)pduDataPtr[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            }
            else
            {
                pduDataPtr[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] =
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    (uint8)((uint32)pduDataPtr[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
                pduDataPtr[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] =
                    (uint8)((uint32)pduDataPtr[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            }
        }
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        pduDataPtr[sigStartByte] = (uint8)((uint32)pduDataPtr[sigStartByte] & clearBitLow);
        pduDataPtr[sigStartByte] = (uint8)((uint32)pduDataPtr[sigStartByte] | sigValueBuf);
    }
    else
    {
        sigValue = sigValue << (sigStartBit % COM_1BYTE_BITLENGTH);
        clearBit = ~((COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigBitLength)) << (sigStartBit % COM_1BYTE_BITLENGTH));
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < sigByteLength; sigByteLengthIndex++ )
        {
            if( COM_BIG_ENDIAN == sigEndianess )
            {
                pduDataPtr[sigStartByte - sigByteLengthIndex] =
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    (uint8)((uint32)pduDataPtr[sigStartByte - sigByteLengthIndex] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
                pduDataPtr[sigStartByte - sigByteLengthIndex] =
                    (uint8)((uint32)pduDataPtr[sigStartByte - sigByteLengthIndex] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            }
            else
            {
                pduDataPtr[sigStartByte + sigByteLengthIndex] =
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    (uint8)((uint32)pduDataPtr[sigStartByte + sigByteLengthIndex] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
                pduDataPtr[sigStartByte + sigByteLengthIndex] =
                    (uint8)((uint32)pduDataPtr[sigStartByte + sigByteLengthIndex] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Com_TxSigWrite_Large_64
*
* Explanation: The size exceeds 32 bits assign a value to a pdu.
*
* param: txSigInfoPtr: Tx signal info.
*        sigValueBuf: The value of the signal to be assigned.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxSigWrite_Large_64
(
    P2CONST(COM_TxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) txSigInfoPtr,
    uint64 sigValueBuf
)
{
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    Com_SigEndianessType sigEndianess = Com_GetSignalEndianess(txSigInfoPtr->sigBaseInfo->sigFuncIdx); /* Get endianess of signal. */
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    Com_SigBitLengthType sigBitLength = txSigInfoPtr->sigBaseInfo->sigBitLength;    /* Get bit length of signal. */
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    Com_SigByteLengthType sigByteLength = txSigInfoPtr->sigBaseInfo->sigByteLength; /* Get byte length of signal. */
    Com_SigByteLengthType sigByteLengthIndex;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    Com_SigStartBitType sigStartBit = txSigInfoPtr->sigBaseInfo->sigStartBit;       /* Get bit position in byte of signal. */
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    Com_SigStartByteType sigStartByte = txSigInfoPtr->sigBaseInfo->sigStartByte;    /* Get start byte position of signal. */
    uint64 sigValue = sigValueBuf;
    uint64 clearBit = COM_INIT_U64FF;
    uint64 clearBitLow =  COM_INIT_U64FF;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    uint8* pduDataPtr = Com_TxPduInfo[txSigInfoPtr->acPduId].dataRaw;

    /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_Com_SHF" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" */
    sigValue = (sigValue & (COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigBitLength)));

    if( COM_8BYTELENGTH < sigByteLength )
    {
        /* High 4 Byte Data. */
        sigValue = sigValue >> (COM_1BYTE_BITLENGTH - (sigStartBit % COM_1BYTE_BITLENGTH));
        /* High 4 Byte clearBit. */
        clearBit = ~((COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigBitLength)) >> (COM_1BYTE_BITLENGTH - (sigStartBit % COM_1BYTE_BITLENGTH)));
        /* Low 1 Byte Data. */
        /* PolySpace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
        sigValueBuf = sigValueBuf << (sigStartBit % COM_1BYTE_BITLENGTH);
        /* Low 1 Byte clearBit. */
        clearBitLow = ~( (uint64)COM_INIT_FF  << (sigStartBit % COM_1BYTE_BITLENGTH));
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < COM_8BYTELENGTH; sigByteLengthIndex++ )
        {
            if( COM_BIG_ENDIAN == sigEndianess )
            {
                pduDataPtr[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] =
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    (uint8)((uint32)pduDataPtr[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
                pduDataPtr[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] =
                    (uint8)((uint32)pduDataPtr[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            }
            else
            {
                pduDataPtr[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] =
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    (uint8)((uint32)pduDataPtr[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
                pduDataPtr[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] =
                    (uint8)((uint32)pduDataPtr[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            }
        }
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        pduDataPtr[sigStartByte] = (uint8)((uint32)pduDataPtr[sigStartByte] & clearBitLow);
        pduDataPtr[sigStartByte] = (uint8)((uint32)pduDataPtr[sigStartByte] | sigValueBuf);
    }
    else
    {
        sigValue = sigValue << (sigStartBit % COM_1BYTE_BITLENGTH);
        clearBit = ~((COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigBitLength)) << (sigStartBit % COM_1BYTE_BITLENGTH));
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < sigByteLength; sigByteLengthIndex++ )
        {
            if( COM_BIG_ENDIAN == sigEndianess )
            {
                pduDataPtr[sigStartByte - sigByteLengthIndex] =
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    (uint8)((uint32)pduDataPtr[sigStartByte - sigByteLengthIndex] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
                pduDataPtr[sigStartByte - sigByteLengthIndex] =
                    (uint8)((uint32)pduDataPtr[sigStartByte - sigByteLengthIndex] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            }
            else
            {
                pduDataPtr[sigStartByte + sigByteLengthIndex] =
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    (uint8)((uint32)pduDataPtr[sigStartByte + sigByteLengthIndex] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
                pduDataPtr[sigStartByte + sigByteLengthIndex] =
                    (uint8)((uint32)pduDataPtr[sigStartByte + sigByteLengthIndex] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Com_TxSigWrite_Uint8N
*
* Explanation: The uint8_N type signal assign a value to a pdu.
*
* param: txSigInfoPtr: Tx signal info.
*        sigValueBufPtr: The value of the signal to be assigned.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxSigWrite_Uint8N
(
    P2CONST(COM_TxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) txSigInfoPtr,
    P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) sigValueBufPtr
)
{
    uint8 index = COM_INIT_ZERO;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    uint16 sigLength = txSigInfoPtr->sigBaseInfo->sigByteLength; /* Get byte length of signal. */
    uint16 sigLengthIndex;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    Com_SigStartByteType sigStartByte = txSigInfoPtr->sigBaseInfo->sigStartByte; /* Get start byte position of signal. */
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    uint8* pduDataPtr = Com_TxPduInfo[txSigInfoPtr->acPduId].dataRaw;

    /* uint8_N signal write data to a message. */
    for( sigLengthIndex = (uint8)sigStartByte; sigLengthIndex < ((uint8)sigStartByte + sigLength); sigLengthIndex++ )
    {
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        pduDataPtr[sigLengthIndex] = sigValueBufPtr[index];
        index++;
    }
}

#if( (COM_RXSIGGROUPINFO == STD_ON) && (COM_INVALIDACTION_SUPPORT == STD_ON) )
/*
********************************************************************************
* Function Name: Com_SigGrp_InvReplace
*
* Explanation: receive signal group invalid replace process.
*
* param: grpSigIdx: Signal index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_SigGrp_InvReplace(uint16 grpSigIdx)
{
    Com_SigType receiveSignalType;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.5" */
    uint16 bytelenth;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSignalInfo_st* rxSigInfo = &Com_RxSignalInfo[grpSigIdx];
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
    uint8* shdowDataPtr = (uint8*)Com_RxSignalInfo[grpSigIdx].invalidValue;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
    uint8* initDataPtr =  (uint8*)Com_RxSignalInfo[grpSigIdx].initvalue;

    /* Obtain signal type. */
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
    receiveSignalType = Com_RxSignalInfo[grpSigIdx].acSigType;
#else  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
    receiveSignalType = Com_GetSignalType(rxSigInfo->sigBaseInfo->sigFuncIdx);
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
    /* Judge signal type. */
    /* PolySpace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_Com_16.1" */
    switch( receiveSignalType )
    {
        /* Invalid signal group replacement processing. */
        case COM_SIGTYPE_BOOLEAN:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            Com_SIGNAL_INITREPLACESHADOW(boolean, rxSigInfo);
            break;
        case COM_SIGTYPE_UINT8:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            Com_SIGNAL_INITREPLACESHADOW(uint8, rxSigInfo);
            break;
        case COM_SIGTYPE_UINT16:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            Com_SIGNAL_INITREPLACESHADOW(uint16, rxSigInfo);
            break;
        case COM_SIGTYPE_UINT32:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            Com_SIGNAL_INITREPLACESHADOW(uint32, rxSigInfo);
            break;
        case COM_SIGTYPE_UINT64:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            Com_SIGNAL_INITREPLACESHADOW(uint64, rxSigInfo);
            break;
        case COM_SIGTYPE_SINT8:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            Com_SIGNAL_INITREPLACESHADOW(sint8, rxSigInfo);
            break;
        case COM_SIGTYPE_SINT16:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            Com_SIGNAL_INITREPLACESHADOW(sint16, rxSigInfo);
            break;
        case COM_SIGTYPE_SINT32:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            Com_SIGNAL_INITREPLACESHADOW(sint32, rxSigInfo);
            break;
        case COM_SIGTYPE_SINT64:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            Com_SIGNAL_INITREPLACESHADOW(sint64, rxSigInfo);
            break;
        case COM_SIGTYPE_FLOAT32:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            Com_SIGNAL_INITREPLACESHADOW(uint32, rxSigInfo);
            break;
        case COM_SIGTYPE_FLOAT64:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            Com_SIGNAL_INITREPLACESHADOW(uint64, rxSigInfo);
            break;
        case COM_SIGTYPE_UINT8_DYN:
            bytelenth = Com_RxSignalInfo[grpSigIdx].astSignalInterMonitor->acDynSignalLength;
            Com_Memcpy(((uint8*)shdowDataPtr), ((uint8*)initDataPtr), bytelenth);
            break;
        case COM_SIGTYPE_UINT8_N:
            /* Get byte length of signal. */
            bytelenth = Com_RxSignalInfo[grpSigIdx].sigBaseInfo->sigByteLength;
            Com_Memcpy(((uint8*)shdowDataPtr), ((uint8*)initDataPtr), bytelenth);
            break;
        /* PolySpace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_Com_16.4" */
        default:
            break;
    }
}
#endif  /* (COM_RXSIGGROUPINFO == STD_ON) && (COM_INVALIDACTION_SUPPORT == STD_ON) */

#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessU8
*
* Explanation: uint8 type receive signal updatebit/invalid/filter process.
*
* param: dataPtr: Received message data.
*        rxSigInfoPtr: Rx signal info.
*        sigIdx: Rx signal index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessU8
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    uint8 dataValue;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
        /* Determine whether the SigFuncIdx of the signal conforms to the signal type. */
        if( (COM_BIG_ENDIAN_UINT8_END_FUNCID >= rxSigInfoPtr->sigBaseInfo->sigFuncIdx)
             || ((COM_LITTLE_ENDIAN_UINT8_START_FUNCID <= rxSigInfoPtr->sigBaseInfo->sigFuncIdx) && 
                (COM_LITTLE_ENDIAN_UINT8_END_FUNCID >= rxSigInfoPtr->sigBaseInfo->sigFuncIdx)) )
        {
            /* Parse received message data to uint8 signal. */
            Com_RxParseSignalFuncTable[rxSigInfoPtr->sigBaseInfo->sigFuncIdx](dataPtr, (uint8*)&dataValue, rxSigInfoPtr->sigBaseInfo);
        }

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_uint8(dataValue, sigIdx);
        if( TRUE == invDiscardflag )
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            {
                dataValue = *(uint8*)Com_RxSignalInfo[sigIdx].initvalue;
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
             filterDiscardflag = Com_Signal_uint8_EvaluateFilter(dataValue, sigIdx);
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Signal received. */
            (*(uint8*)Com_RxSignalInfo[sigIdx].sigRTEValue) = dataValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
}

/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessU16
*
* Explanation: uint16 type receive signal updatebit/invalid/filter process.
*
* param: dataPtr: Received message data.
*        rxSigInfoPtr: Rx signal info.
*        sigIdx: Rx signal index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessU16
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    uint16 dataValue;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
        /* Determine whether the SigFuncIdx of the signal conforms to the signal type. */
        if( (COM_BIG_ENDIAN_UINT16_END_FUNCID >= rxSigInfoPtr->sigBaseInfo->sigFuncIdx)
             || ((COM_LITTLE_ENDIAN_UINT16_START_FUNCID <= rxSigInfoPtr->sigBaseInfo->sigFuncIdx) && 
                (COM_LITTLE_ENDIAN_UINT16_END_FUNCID >= rxSigInfoPtr->sigBaseInfo->sigFuncIdx)) )
        {
            /* Parse received message data to uint16 signal. */
            Com_RxParseSignalFuncTable[rxSigInfoPtr->sigBaseInfo->sigFuncIdx](dataPtr, (uint8*)&dataValue,  /* PRQA S 0310 */ /* NSCA_QAC_Com_Rule11.3 */
                                                                        rxSigInfoPtr->sigBaseInfo);
        }

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_uint16(dataValue, sigIdx);
        if( TRUE == invDiscardflag )
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            {
                dataValue = *(uint16*)Com_RxSignalInfo[sigIdx].initvalue;
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
             filterDiscardflag = Com_Signal_uint16_EvaluateFilter(dataValue, sigIdx);
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Signal received. */
            *(uint16*)Com_RxSignalInfo[sigIdx].sigRTEValue = dataValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
}

/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessU32
*
* Explanation: uint32 type receive signal updatebit/invalid/filter process.
*
* param: dataPtr: Received message data.
*        rxSigInfoPtr: Rx signal info.
*        sigIdx: Rx signal index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessU32
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    uint32 dataValue;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
        /* Determine whether the SigFuncIdx of the signal conforms to the signal type. */
        if( (COM_BIG_ENDIAN_UINT32_END_FUNCID >= rxSigInfoPtr->sigBaseInfo->sigFuncIdx) ||
             ((COM_LITTLE_ENDIAN_UINT32_START_FUNCID <= rxSigInfoPtr->sigBaseInfo->sigFuncIdx) && 
                (COM_LITTLE_ENDIAN_UINT32_END_FUNCID >= rxSigInfoPtr->sigBaseInfo->sigFuncIdx)) )
        {
            /* Parse received message data to uint32 signal. */
            Com_RxParseSignalFuncTable[rxSigInfoPtr->sigBaseInfo->sigFuncIdx](dataPtr, (uint8*)&dataValue,  /* PRQA S 0310 */ /* NSCA_QAC_Com_Rule11.3 */
                                                                        rxSigInfoPtr->sigBaseInfo);
        }

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_uint32(dataValue, sigIdx);
        if( TRUE == invDiscardflag )
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            {
                dataValue = *(uint32*)Com_RxSignalInfo[sigIdx].initvalue;
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
             filterDiscardflag = Com_Signal_uint32_EvaluateFilter(dataValue, sigIdx);
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Signal received. */
            *(uint32*)Com_RxSignalInfo[sigIdx].sigRTEValue = dataValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
}

/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessI8
*
* Explanation: sint8 type receive signal updatebit/invalid/filter process.
*
* param: dataPtr: Received message data.
*        rxSigInfoPtr: Rx signal info.
*        sigIdx: Rx signal index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessI8
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    sint8 dataValue;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
        /* Determine whether the SigFuncIdx of the signal conforms to the signal type. */
        if( ((COM_BIG_ENDIAN_SINT8_START_FUNCID <= rxSigInfoPtr->sigBaseInfo->sigFuncIdx) && 
            (COM_BIG_ENDIAN_SINT8_END_FUNCID >= rxSigInfoPtr->sigBaseInfo->sigFuncIdx)) ||
            ((COM_LITTLE_ENDIAN_SINT8_START_FUNCID <= rxSigInfoPtr->sigBaseInfo->sigFuncIdx) && 
             (COM_LITTLE_ENDIAN_SINT8_END_FUNCID >= rxSigInfoPtr->sigBaseInfo->sigFuncIdx)) )
        {
            /* Parse received message data to sint8 signal. */
            Com_RxParseSignalFuncTable[rxSigInfoPtr->sigBaseInfo->sigFuncIdx](dataPtr, (uint8*)&dataValue,  /* PRQA S 0310 */ /* NSCA_QAC_Com_Rule11.3 */
                                                                        rxSigInfoPtr->sigBaseInfo);
        }

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_sint8(dataValue, sigIdx);
        if( TRUE == invDiscardflag )
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            {
                dataValue = *(sint8*)Com_RxSignalInfo[sigIdx].initvalue;
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
             filterDiscardflag = Com_Signal_sint8_EvaluateFilter(dataValue, sigIdx);
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Signal received. */
            *(sint8*)Com_RxSignalInfo[sigIdx].sigRTEValue = dataValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
}

/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessI16
*
* Explanation: sint16 type receive signal updatebit/invalid/filter process.
*
* param: dataPtr: Received message data.
*        rxSigInfoPtr: Rx signal info.
*        sigIdx: Rx signal index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessI16
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    sint16 dataValue;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
        /* Determine whether the SigFuncIdx of the signal conforms to the signal type. */
        if( ((COM_BIG_ENDIAN_SINT16_START_FUNCID <= rxSigInfoPtr->sigBaseInfo->sigFuncIdx) && 
            (COM_BIG_ENDIAN_SINT16_END_FUNCID >= rxSigInfoPtr->sigBaseInfo->sigFuncIdx)) ||
            ((COM_LITTLE_ENDIAN_SINT16_START_FUNCID <= rxSigInfoPtr->sigBaseInfo->sigFuncIdx) && 
            (COM_LITTLE_ENDIAN_SINT16_END_FUNCID >= rxSigInfoPtr->sigBaseInfo->sigFuncIdx)) )
        {
            /* Parse received message data to sint16 signal. */
            Com_RxParseSignalFuncTable[rxSigInfoPtr->sigBaseInfo->sigFuncIdx](dataPtr, (uint8*)&dataValue,  /* PRQA S 0310 */ /* NSCA_QAC_Com_Rule11.3 */
                                                                        rxSigInfoPtr->sigBaseInfo);
        }

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_sint16(dataValue, sigIdx);
        if( TRUE == invDiscardflag )
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            {
                dataValue = *(sint16*)Com_RxSignalInfo[sigIdx].initvalue;
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
             filterDiscardflag = Com_Signal_sint16_EvaluateFilter(dataValue, sigIdx);
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Signal received. */
            *(sint16*)Com_RxSignalInfo[sigIdx].sigRTEValue = dataValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }

}

/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessI32
*
* Explanation: sint32 type receive signal updatebit/invalid/filter process.
*
* param: dataPtr: Received message data.
*        rxSigInfoPtr: Rx signal info.
*        sigIdx: Rx signal index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessI32
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    sint32 dataValue;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
        /* Determine whether the SigFuncIdx of the signal conforms to the signal type. */
        if( ((COM_BIG_ENDIAN_SINT32_START_FUNCID <= rxSigInfoPtr->sigBaseInfo->sigFuncIdx) && 
            (COM_BIG_ENDIAN_SINT32_END_FUNCID >= rxSigInfoPtr->sigBaseInfo->sigFuncIdx)) ||
            ((COM_LITTLE_ENDIAN_SINT32_START_FUNCID <= rxSigInfoPtr->sigBaseInfo->sigFuncIdx) && 
            (COM_LITTLE_ENDIAN_SINT32_END_FUNCID >= rxSigInfoPtr->sigBaseInfo->sigFuncIdx)) )
        {
            /* Parse received message data to sint32 signal. */
            Com_RxParseSignalFuncTable[rxSigInfoPtr->sigBaseInfo->sigFuncIdx](dataPtr, (uint8*)&dataValue,  /* PRQA S 0310 */ /* NSCA_QAC_Com_Rule11.3 */
                                                                        rxSigInfoPtr->sigBaseInfo);
        }

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_sint32(dataValue, sigIdx);
        if( TRUE == invDiscardflag )
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            {
                dataValue = *(sint32*)Com_RxSignalInfo[sigIdx].initvalue;
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
            filterDiscardflag = Com_Signal_sint32_EvaluateFilter(dataValue, sigIdx);
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Signal received. */
            *(sint32*)Com_RxSignalInfo[sigIdx].sigRTEValue = dataValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
}

/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessUint8N
*
* Explanation: uint8_N type receive signal updatebit/invalid/filter process.
*
* param: pduDataPtr: received value.
*        sigIdx: Rx signal index.
*        bytelenth: Data length.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessUint8N
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    uint16 sigLengthIndex;
    uint16 bytelenth;
    Com_SigStartByteType sigStartByte = rxSigInfoPtr->sigBaseInfo->sigStartByte;
    /* get byte lenth */
    bytelenth = rxSigInfoPtr->sigBaseInfo->sigByteLength;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_uint8N(dataPtr, sigIdx, bytelenth);
        if( TRUE == invDiscardflag )
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            {
                for( sigLengthIndex = COM_INIT_ZERO;
                  sigLengthIndex < Com_RxSignalInfo[sigIdx].sigBaseInfo->sigByteLength; sigLengthIndex++ )
                {
                    dataPtr[sigStartByte + sigLengthIndex] =
                         ((uint8*)Com_RxSignalInfo[sigIdx].initvalue)[sigLengthIndex];
                }
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
            if( NULL_PTR != Com_RxSignalInfo[sigIdx].signalFilterMonitor )
            {
                if( COM_FILTER_ALWAYS
                    == Com_RxSignalInfo[sigIdx].signalFilterMonitor->acFilterAlgorithm )
                {
                    filterDiscardflag = TRUE;
                }
                else if( COM_FILTER_NEVER
                    == Com_RxSignalInfo[sigIdx].signalFilterMonitor->acFilterAlgorithm )
                {
                    filterDiscardflag = FALSE;
                }
                else
                {
                    /* Do nothing. */
                }
            }
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            for( sigLengthIndex = COM_INIT_ZERO;
             sigLengthIndex < Com_RxSignalInfo[sigIdx].sigBaseInfo->sigByteLength; sigLengthIndex++ )
            {
               ((uint8*)Com_RxSignalInfo[sigIdx].sigRTEValue)[sigLengthIndex] =  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    dataPtr[sigStartByte + sigLengthIndex];
            }
            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
    COM_DUMMY_STATEMENT(bytelenth);
}

/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessBoolean
*
* Explanation: Boolean type receive signal updatebit/invalid/filter process.
*
* param: pduDataPtr: received value.
*        sigIdx: Rx signal index.
*        bytelenth: Data length.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessBoolean
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    boolean dataValue;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
        /* Determine whether the SigFuncIdx of the signal conforms to the signal type. */
        if( COM_BOOLEAN_FUNCID == rxSigInfoPtr->sigBaseInfo->sigFuncIdx )
        {
            /* Parse received message data to boolean signal. */
            Com_RxParseSignalFuncTable[rxSigInfoPtr->sigBaseInfo->sigFuncIdx](dataPtr, (uint8*)&dataValue,
                                                                        rxSigInfoPtr->sigBaseInfo);
        }

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_Boolean(dataValue, sigIdx);
        if( TRUE == invDiscardflag )
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            {
                dataValue = *(boolean*)Com_RxSignalInfo[sigIdx].initvalue;
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
            filterDiscardflag = Com_Signal_Boolean_EvaluateFilter(dataValue, sigIdx);
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Signal received. */
            *(boolean*)Com_RxSignalInfo[sigIdx].sigRTEValue = dataValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
}

/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessFloat32
*
* Explanation: Float32 type receive signal updatebit/invalid/filter process.
*
* param: pduDataPtr: received value.
*        sigIdx: Rx signal index.
*        bytelenth: Data length.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessFloat32
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    float32 dataValue;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
        /* Determine whether the SigFuncIdx of the signal conforms to the signal type. */
        if( (COM_BIG_ENDIAN_FLOAT32_FUNCID == rxSigInfoPtr->sigBaseInfo->sigFuncIdx) || 
            (COM_LITTLE_ENDIAN_FLOAT32_FUNCID == rxSigInfoPtr->sigBaseInfo->sigFuncIdx) )
        {
            /* Parse received message data to float32 signal. */
            Com_RxParseSignalFuncTable[rxSigInfoPtr->sigBaseInfo->sigFuncIdx](dataPtr, (uint8*)&dataValue,  /* PRQA S 0310 */ /* NSCA_QAC_Com_Rule11.3 */
                                                                        rxSigInfoPtr->sigBaseInfo);
        }

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_float32(dataValue, sigIdx);
        if( TRUE == invDiscardflag )
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            {
                dataValue = *(float32*)Com_RxSignalInfo[sigIdx].initvalue;
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else  /* Notifty */
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
            if( COM_FILTER_ALWAYS
                == Com_RxSignalInfo[sigIdx].signalFilterMonitor->acFilterAlgorithm )
            {
                filterDiscardflag = TRUE;
            }
            else if( COM_FILTER_NEVER
                == Com_RxSignalInfo[sigIdx].signalFilterMonitor->acFilterAlgorithm )
            {
                filterDiscardflag = FALSE;
            }
            else
            {
                /* Do nothing. */
            }
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Signal received. */
            *(float32*)Com_RxSignalInfo[sigIdx].sigRTEValue = dataValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
}

/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessFloat64
*
* Explanation: Float64 type receive signal updatebit/invalid/filter process.
*
* param: pduDataPtr: received value.
*        sigIdx: Rx signal index.
*        bytelenth: Data length.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessFloat64
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    float64 dataValue;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
        /* Parse received message data to float64 signal. */
        Com_RxParseSignalFuncTable[rxSigInfoPtr->sigBaseInfo->sigFuncIdx](dataPtr, (uint8*)&dataValue,  /* PRQA S 0310 */ /* NSCA_QAC_Com_Rule11.3 */
                                                                        rxSigInfoPtr->sigBaseInfo);

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_float64(dataValue, sigIdx);
        if( TRUE == invDiscardflag )
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            {
                dataValue = *(float64*)Com_RxSignalInfo[sigIdx].initvalue;
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
            if( COM_FILTER_ALWAYS
                == Com_RxSignalInfo[sigIdx].signalFilterMonitor->acFilterAlgorithm )
            {
                filterDiscardflag = TRUE;
            }
            else if( COM_FILTER_NEVER
                == Com_RxSignalInfo[sigIdx].signalFilterMonitor->acFilterAlgorithm )
            {
                filterDiscardflag = FALSE;
            }
            else
            {
                /* Do nothing. */
            }
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Signal received. */
            *(float64*)Com_RxSignalInfo[sigIdx].sigRTEValue = dataValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
}

/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessU64
*
* Explanation: uint64 type receive signal updatebit/invalid/filter process.
*
* param: pduDataPtr: received value.
*        sigIdx: Rx signal index.
*        bytelenth: Data length.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessU64
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    uint64 dataValue;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
        /* Parse received message data to uint64 signal. */
        Com_RxParseSignalFuncTable[rxSigInfoPtr->sigBaseInfo->sigFuncIdx](dataPtr, (uint8*)&dataValue,  /* PRQA S 0310 */ /* NSCA_QAC_Com_Rule11.3 */
                                                                        rxSigInfoPtr->sigBaseInfo);

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_uint64(dataValue, sigIdx);
        if( TRUE == invDiscardflag )
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            {
                dataValue = *(uint64*)Com_RxSignalInfo[sigIdx].initvalue;
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
            filterDiscardflag = Com_Signal_uint64_EvaluateFilter(dataValue, sigIdx);
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Signal received. */
            *(uint64*)Com_RxSignalInfo[sigIdx].sigRTEValue = dataValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
}

/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessI64
*
* Explanation: int64 type receive signal updatebit/invalid/filter process.
*
* param: pduDataPtr: received value.
*        sigIdx: Rx signal index.
*        bytelenth: Data length.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessI64
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    sint64 dataValue;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
        /* Parse received message data to sint64 signal. */
        Com_RxParseSignalFuncTable[rxSigInfoPtr->sigBaseInfo->sigFuncIdx](dataPtr, (uint8*)&dataValue,  /* PRQA S 0310 */ /* NSCA_QAC_Com_Rule11.3 */
                                                                        rxSigInfoPtr->sigBaseInfo);

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_sint64(dataValue, sigIdx);
        if( TRUE == invDiscardflag )
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            {
                dataValue = *(sint64*)Com_RxSignalInfo[sigIdx].initvalue;
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
            filterDiscardflag = Com_Signal_sint64_EvaluateFilter(dataValue, sigIdx);
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Signal received. */
            *(sint64*)Com_RxSignalInfo[sigIdx].sigRTEValue = dataValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
}

/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessUint8DYN
*
* Explanation: uint8_DYN type receive signal updatebit/invalid/filter process.
*
* param: pduDataPtr: received value.
*        sigIdx: Rx signal index.
*        bytelenth: Data length.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessUint8DYN
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr,
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    uint16 sigLengthIndex;
    uint16 bytelenth;
    Com_SigStartByteType sigStartByte = rxSigInfoPtr->sigBaseInfo->sigStartByte;

    Com_RxDynSignalLengthEvlateProcess(sigIdx);
    /* get byte lenth */
    bytelenth = rxSigInfoPtr->sigBaseInfo->sigByteLength;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_uint8N(dataPtr, sigIdx, bytelenth);
        if( TRUE == invDiscardflag )
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            {
                for( sigLengthIndex = COM_INIT_ZERO;
                  sigLengthIndex < Com_RxSignalInfo[sigIdx].sigBaseInfo->sigByteLength; sigLengthIndex++ )
                {
                    dataPtr[sigStartByte + sigLengthIndex] =
                         ((uint8*)Com_RxSignalInfo[sigIdx].initvalue)[sigLengthIndex];
                }
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
            if( NULL_PTR != Com_RxSignalInfo[sigIdx].signalFilterMonitor )
            {
                if( COM_FILTER_ALWAYS
                    == Com_RxSignalInfo[sigIdx].signalFilterMonitor->acFilterAlgorithm )
                {
                    filterDiscardflag = TRUE;
                }
                else if( COM_FILTER_NEVER
                    == Com_RxSignalInfo[sigIdx].signalFilterMonitor->acFilterAlgorithm )
                {
                    filterDiscardflag = FALSE;
                }
                else
                {
                    /* Do nothing. */
                }
            }
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            for( sigLengthIndex = COM_INIT_ZERO;
             sigLengthIndex < Com_RxSignalInfo[sigIdx].sigBaseInfo->sigByteLength; sigLengthIndex++ )
            {
               ((uint8*)Com_RxSignalInfo[sigIdx].sigRTEValue)[sigLengthIndex] =  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                    dataPtr[sigStartByte + sigLengthIndex];
            }
            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
    COM_DUMMY_STATEMENT(bytelenth);
}

/*
********************************************************************************
* Function Name: Com_ReadSign_G_U8DYN
*
* Explanation: Parse received message data to U8DYN signal.
*
* param: signData: signal data.
*        dataPtr: Received message data.
*        rxSigInfoPtr: Rx signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_ReadSign_G_U8DYN
(
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) signData,
    P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) dataPtr,
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr
)
{
    uint16 dynSignalLength = rxSigInfoPtr->astSignalInterMonitor->acDynSignalLength;
    uint16 sigStartByte = rxSigInfoPtr->sigBaseInfo->sigStartByte;
    uint16 sigLengthIndex;

    /* Parse received message data to uint8_N signal. */
    for( sigLengthIndex = sigStartByte;
            sigLengthIndex < (sigStartByte + dynSignalLength); sigLengthIndex++ )
    {
         ((uint8*)signData)[sigLengthIndex - sigStartByte]  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                   = dataPtr[sigLengthIndex];
    }
}

/*
********************************************************************************
* Function Name: Com_WriteSignU8DYN
*
* Explanation: Assign a U8DYN value to a pdu.
*
* param: dataPtr: The pdu to be assigned.
*        txSigInfoPtr: Tx signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_WriteSignU8DYN
(
    P2VAR(uint8, AUTOMATIC,COM_APPL_DATA) dataPtr,
    P2CONST(COM_TxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) txSigInfoPtr
)
{
    uint8 index = COM_INIT_ZERO;
    uint16 sigLength = txSigInfoPtr->sigBaseInfo->sigByteLength;
    uint16 sigLengthIndex;
    Com_SigStartByteType sigStartByte = txSigInfoPtr->sigBaseInfo->sigStartByte;
    uint8* sigValueBufPtr = (uint8*)(txSigInfoPtr->sigValShadowBufPtr);  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

    /* uint8_N signal write data to a message. */
    for( sigLengthIndex = (uint8)sigStartByte; sigLengthIndex < ((uint8)sigStartByte + sigLength); sigLengthIndex++ )
    {
        dataPtr[sigLengthIndex] = sigValueBufPtr[index];
        index++;
    }
}

#else
/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessU8
*
* Explanation: uint8 type receive signal updatebit/invalid/filter process.
*
* param: uintValue08: Newreceived value.
*        sigIdx: Rx signal index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessU8
(
    /* PolySpace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.13" */
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) uintValue08,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    uint8 dataValue;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
        /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
        dataValue = *(uint8*)uintValue08;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_uint8(dataValue, sigIdx);
        if( TRUE == invDiscardflag )
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            {
                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                dataValue = *(uint8*)Com_RxSignalInfo[sigIdx].initvalue;
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
             filterDiscardflag = Com_Signal_uint8_EvaluateFilter(dataValue, sigIdx);
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Signal received. */
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            (*(uint8*)Com_RxSignalInfo[sigIdx].sigRTEValue) = dataValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
}

/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessU16
*
* Explanation: uint16 type receive signal updatebit/invalid/filter process.
*
* param: uintValue16: Newreceived value.
*        sigIdx: Rx signal index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessU16
(
    /* PolySpace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.13" */
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) uintValue16,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    uint16 dataValue;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
        /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */ 
        dataValue = *(uint16*)uintValue16;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_uint16(dataValue, sigIdx);
        if( TRUE == invDiscardflag )
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            {
                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                dataValue = *(uint16*)Com_RxSignalInfo[sigIdx].initvalue;
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
             filterDiscardflag = Com_Signal_uint16_EvaluateFilter(dataValue, sigIdx);
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Signal received. */
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            *(uint16*)Com_RxSignalInfo[sigIdx].sigRTEValue = dataValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
}

/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessU32
*
* Explanation: uint32 type receive signal updatebit/invalid/filter process.
*
* param: uintValue32: newreceived value.
*        sigIdx: Rx signal index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessU32
(
    /* PolySpace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.13" */
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) uintValue32,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    uint32 dataValue;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
        /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
        dataValue = *(uint32*)uintValue32;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_uint32(dataValue, sigIdx);
        if( TRUE == invDiscardflag )
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            {
                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                dataValue = *(uint32*)Com_RxSignalInfo[sigIdx].initvalue;
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
             filterDiscardflag = Com_Signal_uint32_EvaluateFilter(dataValue, sigIdx);
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Signal received. */
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            *(uint32*)Com_RxSignalInfo[sigIdx].sigRTEValue = dataValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
}

/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessI8
*
* Explanation: sint8 type receive signal updatebit/invalid/filter process.
*
* param: intValue08: newreceived value.
*        sigIdx: Rx signal index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessI8
(
    /* PolySpace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.13" */
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) intValue08,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    sint8 dataValue;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
        /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
        dataValue = *(sint8*)intValue08;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_sint8(dataValue, sigIdx);
        if( TRUE == invDiscardflag )
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            {
                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                dataValue = *(sint8*)Com_RxSignalInfo[sigIdx].initvalue;
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
             filterDiscardflag = Com_Signal_sint8_EvaluateFilter(dataValue, sigIdx);
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Signal received. */
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            *(sint8*)Com_RxSignalInfo[sigIdx].sigRTEValue = dataValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
}

/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessI16
*
* Explanation: sint16 type receive signal updatebit/invalid/filter process.
*
* param: intValue16: newreceived value.
*        sigIdx: Rx signal index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessI16
(
    /* PolySpace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.13" */
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) intValue16,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    sint16 dataValue;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
        /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
        dataValue = *(sint16*)intValue16;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_sint16(dataValue, sigIdx);
        if( TRUE == invDiscardflag )
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            {
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                dataValue = *(sint16*)Com_RxSignalInfo[sigIdx].initvalue;
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
             filterDiscardflag = Com_Signal_sint16_EvaluateFilter(dataValue, sigIdx);
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Signal received. */
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            *(sint16*)Com_RxSignalInfo[sigIdx].sigRTEValue = dataValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }

}

/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessI32
*
* Explanation: sint32 type receive signal updatebit/invalid/filter process.
*
* param: intValue32: newreceived value.
*        sigIdx: rx signal index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessI32
(
    /* PolySpace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.13" */
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) intValue32,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    sint32 dataValue;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
        /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
        dataValue = *(sint32*)intValue32;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_sint32(dataValue, sigIdx);
        if( TRUE == invDiscardflag )
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            {
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                dataValue = *(sint32*)Com_RxSignalInfo[sigIdx].initvalue;
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
            filterDiscardflag = Com_Signal_sint32_EvaluateFilter(dataValue, sigIdx);
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Signal received. */
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" */
            *(sint32*)Com_RxSignalInfo[sigIdx].sigRTEValue = dataValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
}

/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessUint8N
*
* Explanation: uint8_N type receive signal updatebit/invalid/filter process.
*
* param: pduDataPtr: received value.
*        sigIdx: Rx signal index.
*        bytelenth: Data length.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessUint8N
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) pduDataPtr,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    uint16 sigIdx,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.5" */
    uint16 bytelenth
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    uint16 sigLengthIndex;
    /* Get start byte position of signal. */
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    Com_SigStartByteType sigStartByte = Com_RxSignalInfo[sigIdx].sigBaseInfo->sigStartByte;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_uint8N(pduDataPtr, sigIdx, bytelenth);
        if( TRUE == invDiscardflag )
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            {
                /* uint8_N signal initvalue write data to a message. */
                for( sigLengthIndex = COM_INIT_ZERO;
                  sigLengthIndex < Com_RxSignalInfo[sigIdx].sigBaseInfo->sigByteLength; sigLengthIndex++ )
                {
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    pduDataPtr[sigStartByte + sigLengthIndex] =
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                         ((uint8*)Com_RxSignalInfo[sigIdx].initvalue)[sigLengthIndex];
                }
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
            if( NULL_PTR != Com_RxSignalInfo[sigIdx].signalFilterMonitor )
            {
                if( COM_FILTER_ALWAYS
                    == Com_RxSignalInfo[sigIdx].signalFilterMonitor->acFilterAlgorithm )
                {
                    filterDiscardflag = TRUE;
                }
                else if( COM_FILTER_NEVER
                    == Com_RxSignalInfo[sigIdx].signalFilterMonitor->acFilterAlgorithm )
                {
                    filterDiscardflag = FALSE;
                }
                else
                {
                    /* Do nothing. */
                }
            }
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Parse received message data to uint8_N signal. */
            for( sigLengthIndex = COM_INIT_ZERO;
                sigLengthIndex < Com_RxSignalInfo[sigIdx].sigBaseInfo->sigByteLength; sigLengthIndex++ )
            {
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                ((uint8*)Com_RxSignalInfo[sigIdx].sigRTEValue)[sigLengthIndex] =  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        pduDataPtr[sigStartByte + sigLengthIndex];
            }
            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
    COM_DUMMY_STATEMENT(bytelenth);
}

/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessBoolean
*
* Explanation: Boolean type receive signal updatebit/invalid/filter process.
*
* param: booleanValue: received value.
*        sigIdx: Rx signal index.
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.13" */
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessBoolean(P2VAR(void, AUTOMATIC, COM_APPL_DATA) booleanValue, uint16 sigIdx)  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    boolean dataValue;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
        /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
        dataValue = *(boolean*)booleanValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_Boolean(dataValue, sigIdx);
        if( TRUE == invDiscardflag )
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            {
                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                dataValue = *(boolean*)Com_RxSignalInfo[sigIdx].initvalue;
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
            filterDiscardflag = Com_Signal_Boolean_EvaluateFilter(dataValue, sigIdx);
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Signal received. */
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            *(boolean*)Com_RxSignalInfo[sigIdx].sigRTEValue = dataValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
}
/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessFloat32
*
* Explanation: Float32 type receive signal updatebit/invalid/filter process.
*
* param: floatValue32: received value.
*        sigIdx: Rx signal index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessFloat32
(
    /* PolySpace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.13" */
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) floatValue32,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    float32 dataValue;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
        /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
        dataValue = *(float32*)floatValue32;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_float32(dataValue, sigIdx);
        if( TRUE == invDiscardflag )
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            {
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                dataValue = *(float32*)Com_RxSignalInfo[sigIdx].initvalue;
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else  /* Notifty */
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
            if( COM_FILTER_ALWAYS
                == Com_RxSignalInfo[sigIdx].signalFilterMonitor->acFilterAlgorithm )
            {
                filterDiscardflag = TRUE;
            }
            else if( COM_FILTER_NEVER
                == Com_RxSignalInfo[sigIdx].signalFilterMonitor->acFilterAlgorithm )
            {
                filterDiscardflag = FALSE;
            }
            else
            {
                /* Do nothing. */
            }
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Signal received. */
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            *(float32*)Com_RxSignalInfo[sigIdx].sigRTEValue = dataValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
}

/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessFloat64
*
* Explanation: Float64 type receive signal updatebit/invalid/filter process.
*
* param: floatValue64: received value.
*        sigIdx: Rx signal index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessFloat64
(
    /* PolySpace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.13" */
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) floatValue64,   /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    float64 dataValue;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
        /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
        dataValue = *(float64*)floatValue64;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_float64(dataValue, sigIdx);
        if( TRUE == invDiscardflag )
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                dataValue = *(float64*)Com_RxSignalInfo[sigIdx].initvalue;
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
            if( COM_FILTER_ALWAYS
                == Com_RxSignalInfo[sigIdx].signalFilterMonitor->acFilterAlgorithm )
            {
                filterDiscardflag = TRUE;
            }
            else if( COM_FILTER_NEVER
                == Com_RxSignalInfo[sigIdx].signalFilterMonitor->acFilterAlgorithm )
            {
                filterDiscardflag = FALSE;
            }
            else
            {
                /* Do nothing. */
            }
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Signal received. */
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            *(float64*)Com_RxSignalInfo[sigIdx].sigRTEValue = dataValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
}

/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessU64
*
* Explanation: uint64 type receive signal updatebit/invalid/filter process.
*
* param: intValue64: received value.
*        sigIdx: Rx signal index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessU64
(
    /* PolySpace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.13" */
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) uintValue64,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    uint64 dataValue;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
        /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
        dataValue = *(uint64*)uintValue64;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_uint64(dataValue, sigIdx);
        if( TRUE == invDiscardflag )
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                dataValue = *(uint64*)Com_RxSignalInfo[sigIdx].initvalue;
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
            filterDiscardflag = Com_Signal_uint64_EvaluateFilter(dataValue, sigIdx);
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Signal received. */
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            *(uint64*)Com_RxSignalInfo[sigIdx].sigRTEValue = dataValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
}

/*
********************************************************************************
* Function Name: Com_RxSigUbInvFilterProcessI64
*
* Explanation: int64 type receive signal updatebit/invalid/filter process.
*
* param: intValue64: received value.
*        sigIdx: Rx signal index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigUbInvFilterProcessI64
(
    /* PolySpace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.13" */
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) intValue64,  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
    uint16 sigIdx
)
{
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    boolean invDiscardflag = FALSE;
#endif

#if( COM_RXSIGFILTERINFO == STD_ON )
    boolean filterDiscardflag;
#endif
    sint64 dataValue;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 action;
    action = Com_SigRxReadUb(sigIdx);
    if( (uint8)TRUE == action )
#endif
    {
        /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
        dataValue = *(sint64*)intValue64;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )  /* Rx invalid process. */
        /* Process Invalid value. */
        invDiscardflag = Com_RxSigInvalidData_Handle_sint64(dataValue, sigIdx);
        if( TRUE == invDiscardflag )
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        {
            if( COM_SIGNAL_INVALID_REPLACE == Com_RxSignalInfo[sigIdx].acInvalidAction )
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                dataValue = *(sint64*)Com_RxSignalInfo[sigIdx].initvalue;
                invDiscardflag = FALSE;  /* Replace should received. */
            }
            else
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                Com_RxSigInvalidNotification_Handle(sigIdx);
            }
        }

        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        if( FALSE == invDiscardflag )
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( COM_RXSIGFILTERINFO == STD_ON )  /* Rx filter process */
        {
            filterDiscardflag = Com_Signal_sint64_EvaluateFilter(dataValue, sigIdx);
        }

        if( TRUE == filterDiscardflag )  /* TRUE received. */
#endif
        {
            /* Signal received. */
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            *(sint64*)Com_RxSignalInfo[sigIdx].sigRTEValue = dataValue;  /* PRQA S 0316*/ /* NSCA_QAC_Com_Rule11.5 */

            /* Notification Detection. */
            Com_RxSigNotification_Handle(sigIdx);
        }
    }
}
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Com_RxsignalUB_Handle
*
* Explanation: Rx Singal judge update_bit value.
*
* param: sigIdx: Rx Pdu Signal Index.
*
* retval: action: Determine whether the data is updated.
********************************************************************************
*/
static FUNC(uint8, COM_CODE) Com_SigRxReadUb(uint16 sigIdx)
{
    uint8 action = FALSE;
    uint8 updatevalue;
    uint16 updateBitPosit;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSignalInfo_st* rxSigInfo = &Com_RxSignalInfo[sigIdx];
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxPduInfo_st* PduInfo = &Com_RxPduInfo[Com_RxSignalInfo[sigIdx].acPduID];

    /* Configed updetabit. */
    if( COM_SIG_NO_UPDATEBIT_DEF != rxSigInfo->updateBitPosition )
    {
        updateBitPosit = rxSigInfo->updateBitPosition;
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        updatevalue = PduInfo->datavalid[updateBitPosit / COM_1BYTE_BITLENGTH];
        updatevalue = updatevalue >> (updateBitPosit % COM_1BYTE_BITLENGTH);
        updatevalue = updatevalue & COM_OPERAND_ONE;
        /* Determines whether the value of the update bit is updated. */
        if( COM_OPERAND_ONE == updatevalue )
        {
            action = TRUE;
        }
    }
    else  /* No cfg updatebit. */
    {
        action = TRUE;
    }

    return action;
}
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */

#if( (COM_RXSIGGROUPINFO == STD_ON) && (COM_RXUPDATEBITCFG_SUPPORT == STD_ON) )
/*
********************************************************************************
* Function Name: Com_SigGrpRxReadUb
*
* Explanation: Rx Singal judge update_bit value.
*
* param: sigIdx: Rx Pdu Signal Index.
*
* retval: action: Determine whether the data is updated.
********************************************************************************
*/
static FUNC(uint8, COM_CODE) Com_SigGrpRxReadUb(uint16 sigGrpIdx)
{
    uint8 action = FALSE;
    uint8 updatevalue;
    uint16 updateBitPosit;

    /* Configed updatebit. */
    if( COM_SIG_NO_UPDATEBIT_DEF != Com_RxSigGrpInfo[sigGrpIdx].updateBitPosition )
    {
        updateBitPosit = Com_RxSigGrpInfo[sigGrpIdx].updateBitPosition;
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        updatevalue = Com_RxPduInfo[Com_RxSigGrpInfo[sigGrpIdx].awPduId].datavalid[updateBitPosit / COM_1BYTE_BITLENGTH];
        updatevalue = updatevalue >> (updateBitPosit % COM_1BYTE_BITLENGTH);
        updatevalue = updatevalue & COM_OPERAND_ONE;
        /* Determines whether the value of the update bit is updated. */
        if( COM_OPERAND_ONE == updatevalue )
        {
            action = TRUE;
        }
    }
    else
    {
        action = TRUE;
    }

    return action;
}
#endif  /* COM_RXSIGGROUPINFO == STD_ON */

/*
********************************************************************************
* Function Name: Com_RxSigNotification_Handle
*
* Explanation: Rx Singal Notification process.
*
* param: sigIdx: Rx Pdu Signal Index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigNotification_Handle(uint16 sigIdx)
{
#if( COM_RXSIG_NOTIFICATION_SUPPORT == STD_ON )
    if( NULL_PTR != Com_RxSignalInfo[sigIdx].Notification_p )
    {
        /* Configured notification. */
        Com_RxSignalInfo[sigIdx].Notification_p();
    }
#endif  /* COM_RXSIG_NOTIFICATION_SUPPORT == STD_ON */
    /* signal received status change. */
    Com_RxSignalInfo[sigIdx].astSignalInterMonitor->acSignalRecOrSendSts = COM_RXSIG_WatieReceive;
}

#if( COM_RXSIGFILTERINFO == STD_ON )
/*
********************************************************************************
* Function Name: Com_Signal_uint8_EvaluateFilter
*
* Explanation: uint8 type rx signal filter process.
*
* param: sigIdx: Rx Pdu Signal Index.
*
* retval: filterState: TRUE: received new value.
********************************************************************************
*/
static FUNC(boolean, COM_CODE) Com_Signal_uint8_EvaluateFilter
(
    uint8 newValue,
    uint16 sigIdx
)
{
    boolean filterState = TRUE;
    uint8 filterMask;
    uint8 filterX;
    uint8 oldVlaue;
    uint8 filterMin;
    uint8 filterMax;

    if( NULL_PTR != Com_RxSignalInfo[sigIdx].signalFilterMonitor ) /* Cfg filter. */
    {
        switch( COM_GETFILTER_ALGOOFFILTERINFO(sigIdx) )  /* Filter type. */
        {
            case COM_FILTER_ALWAYS:
                filterState = TRUE;
                break;
              case COM_FILTER_NEVER:
                filterState = FALSE;
                break;
            case COM_FILTER_MASKEDNEWDIFFERSMASKEDOLD:
                filterMask = (uint8)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (uint8)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);
                oldVlaue = *(uint8*)Com_RxSignalInfo[sigIdx].sigRTEValue;

                if( (filterMask & oldVlaue) != (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_MASKEDNEWEQUALSX:
                filterMask = (uint8)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (uint8)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);

                if( filterX == (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_MASKEDNEWDIFFERSX:
                filterMask = (uint8)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (uint8)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);

                if( filterX != (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_NEWISOUTSIDE:
                filterMin = (uint8)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMin);
                filterMax = (uint8)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMax);

                if( (filterMin <= newValue) && (newValue <= filterMax) )
                {
                    filterState = TRUE;
                }

                if( FALSE == filterState )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_NEWISWITHIN:
                filterMin = (uint8)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMin);
                filterMax = (uint8)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMax);

                if( (filterMin <= newValue) && (newValue <= filterMax))
                {
                    filterState = TRUE;
                }
                break;
            case COM_ONE_EVERY_N:
                /* unrealized */
                break;
            default:
                break;
        }
    }

    return filterState;

}

/*
********************************************************************************
* Function Name: Com_Signal_uint16_EvaluateFilter
*
* Explanation: uint16 type rx signal filter process.
*
* param: sigIdx: Rx Pdu Signal Index.
*
* retval: filterState: TRUE: received new value.
********************************************************************************
*/
static FUNC(boolean, COM_CODE) Com_Signal_uint16_EvaluateFilter
(
    uint16 newValue,
    uint16 sigIdx
)
{
    boolean filterState = TRUE;
    uint16 filterMask;
    uint16 filterX;
    uint16 oldVlaue;
    uint16 filterMin;
    uint16 filterMax;

    if( NULL_PTR != Com_RxSignalInfo[sigIdx].signalFilterMonitor ) /* Cfg filter. */
    {
        switch( COM_GETFILTER_ALGOOFFILTERINFO(sigIdx) )  /* Filter type. */
        {
            case COM_FILTER_ALWAYS:
                filterState = TRUE;
                break;
            case COM_FILTER_NEVER:
                filterState = FALSE;
                break;
            case COM_FILTER_MASKEDNEWDIFFERSMASKEDOLD:
                filterMask = (uint16)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (uint16)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);
                oldVlaue = *(uint16*)Com_RxSignalInfo[sigIdx].sigRTEValue;

                if( (filterMask & oldVlaue) != (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_MASKEDNEWEQUALSX:
                filterMask = (uint16)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (uint16)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);

                if( filterX == (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_MASKEDNEWDIFFERSX:
                filterMask = (uint16)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (uint16)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);

                if( filterX != (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_NEWISOUTSIDE:
                filterMin = (uint16)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMin);
                filterMax = (uint16)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMax);

                if( (filterMin <= newValue) && (newValue <= filterMax) )
                {
                    filterState = TRUE;
                }

                if( FALSE == filterState )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_NEWISWITHIN:
                filterMin = (uint16)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMin);
                filterMax = (uint16)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMax);

                if( (filterMin <= newValue) && (newValue <= filterMax))
                {
                    filterState = TRUE;
                }
                break;
            case COM_ONE_EVERY_N:
                /* unrealized */
                break;
            default:
                break;
        }
    }

    return filterState;

}

/*
********************************************************************************
* Function Name: Com_Signal_uint32_EvaluateFilter
*
* Explanation: uint32 type rx signal filter process.
*
* param: sigIdx: Rx Pdu Signal Index.
*
* retval: filterState: TRUE: received new value.
********************************************************************************
*/
static FUNC(boolean, COM_CODE) Com_Signal_uint32_EvaluateFilter
(
    uint32 newValue,
    uint16 sigIdx
)
{
    boolean filterState = TRUE;
    uint32 filterMask;
    uint32 filterX;
    uint32 oldVlaue;
    uint32 filterMin;
    uint32 filterMax;

    if( NULL_PTR != Com_RxSignalInfo[sigIdx].signalFilterMonitor ) /* Cfg filter. */
    {
        switch( COM_GETFILTER_ALGOOFFILTERINFO(sigIdx) )  /* Filter type. */
        {
            case COM_FILTER_ALWAYS:
                filterState = TRUE;
                break;
            case COM_FILTER_NEVER:
                filterState = FALSE;
                break;
            case COM_FILTER_MASKEDNEWDIFFERSMASKEDOLD:
                filterMask = (uint32)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (uint32)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);
                oldVlaue = *(uint32*)Com_RxSignalInfo[sigIdx].sigRTEValue;

                if( (filterMask & oldVlaue) != (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_MASKEDNEWEQUALSX:
                filterMask = (uint32)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (uint32)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);

                if( filterX == (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_MASKEDNEWDIFFERSX:
                filterMask = (uint16)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (uint16)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);

                if( filterX != (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_NEWISOUTSIDE:
                filterMin = (uint32)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMin);
                filterMax = (uint32)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMax);

                if( (filterMin <= newValue) && (newValue <= filterMax) )
                {
                    filterState = TRUE;
                }

                if( FALSE == filterState )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_NEWISWITHIN:
                filterMin = (uint32)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMin);
                filterMax = (uint32)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMax);

                if( (filterMin <= newValue) && (newValue <= filterMax))
                {
                    filterState = TRUE;
                }
                break;
            case COM_ONE_EVERY_N:
                /* unrealized */
                break;
            default:
                break;
        }
    }

    return filterState;

}

/*
********************************************************************************
* Function Name: Com_Signal_sint8_EvaluateFilter
*
* Explanation: sint8 type rx signal filter process.
*
* param: sigIdx: Rx Pdu Signal Index.
*
* retval: filterState: TRUE: received new value.
********************************************************************************
*/
static FUNC(boolean, COM_CODE) Com_Signal_sint8_EvaluateFilter
(
    sint8 newValue,
    uint16 sigIdx
)
{
    boolean filterState = TRUE;
    sint8 filterMask;
    sint8 filterX;
    sint8 oldVlaue;
    sint8 filterMin;
    sint8 filterMax;

    if( NULL_PTR != Com_RxSignalInfo[sigIdx].signalFilterMonitor ) /* Cfg filter. */
    {
        switch( COM_GETFILTER_ALGOOFFILTERINFO(sigIdx) )  /* Filter type. */
        {
            case COM_FILTER_ALWAYS:
                filterState = TRUE;
                break;
            case COM_FILTER_NEVER:
                filterState = FALSE;
                break;
            case COM_FILTER_MASKEDNEWDIFFERSMASKEDOLD:
                filterMask = (sint8)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (sint8)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);
                oldVlaue = *(sint8*)Com_RxSignalInfo[sigIdx].sigRTEValue;

                if( (filterMask & oldVlaue) != (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_MASKEDNEWEQUALSX:
                filterMask = (sint8)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (sint8)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);

                if( filterX == (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_MASKEDNEWDIFFERSX:
                filterMask = (sint8)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (sint8)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);

                if( filterX != (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_NEWISOUTSIDE:
                filterMin = (sint8)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMin);
                filterMax = (sint8)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMax);

                if( (filterMin <= newValue) && (newValue <= filterMax) )
                {
                    filterState = TRUE;
                }

                if( FALSE == filterState )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_NEWISWITHIN:
                filterMin = (sint8)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMin);
                filterMax = (sint8)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMax);

                if( (filterMin <= newValue) && (newValue <= filterMax))
                {
                    filterState = TRUE;
                }
                break;
            case COM_ONE_EVERY_N:
                /* unrealized */
                break;
            default:
                break;
        }
    }

    return filterState;

}

/*
********************************************************************************
* Function Name: Com_Signal_sint16_EvaluateFilter
*
* Explanation: sint16 type rx signal filter process.
*
* param: sigIdx: Rx Pdu Signal Index.
*
* retval: filterState: TRUE: received new value.
********************************************************************************
*/
static FUNC(boolean, COM_CODE) Com_Signal_sint16_EvaluateFilter
(
    sint16 newValue,
    uint16 sigIdx
)
{
    boolean filterState = TRUE;
    sint16 filterMask;
    sint16 filterX;
    sint16 oldVlaue;
    sint16 filterMin;
    sint16 filterMax;

    if( NULL_PTR != Com_RxSignalInfo[sigIdx].signalFilterMonitor ) /* Cfg filter. */
    {
        switch( COM_GETFILTER_ALGOOFFILTERINFO(sigIdx) )  /* Filter type. */
        {
            case COM_FILTER_ALWAYS:
                filterState = TRUE;
                break;
            case COM_FILTER_NEVER:
                filterState = FALSE;
                break;
            case COM_FILTER_MASKEDNEWDIFFERSMASKEDOLD:
                filterMask = (sint16)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (sint16)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);
                oldVlaue = *(sint16*)Com_RxSignalInfo[sigIdx].sigRTEValue;

                if( (filterMask & oldVlaue) != (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_MASKEDNEWEQUALSX:
                filterMask = (sint16)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (sint16)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);

                if( filterX == (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_MASKEDNEWDIFFERSX:
                filterMask = (sint16)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (sint16)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);

                if( filterX != (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_NEWISOUTSIDE:
                filterMin = (sint16)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMin);
                filterMax = (sint16)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMax);

                if( (filterMin <= newValue) && (newValue <= filterMax) )
                {
                    filterState = TRUE;
                }

                if( FALSE == filterState )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_NEWISWITHIN:
                filterMin = (sint16)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMin);
                filterMax = (sint16)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMax);

                if( (filterMin <= newValue) && (newValue <= filterMax))
                {
                    filterState = TRUE;
                }
                break;
            case COM_ONE_EVERY_N:
                /* unrealized */
                break;
            default:
                break;
        }
    }

    return filterState;
}

/*
********************************************************************************
* Function Name: Com_Signal_sint32_EvaluateFilter
*
* Explanation: sint32 type rx signal filter process.
*
* param: sigIdx: Rx Pdu Signal Index.
*
* retval: filterState: TRUE: received new value.
********************************************************************************
*/
static FUNC(boolean, COM_CODE) Com_Signal_sint32_EvaluateFilter
(
    sint32 newValue,
    uint16 sigIdx
)
{
    boolean filterState = TRUE;
    sint32 filterMask;
    sint32 filterX;
    sint32 oldVlaue;
    sint32 filterMin;
    sint32 filterMax;

    if( NULL_PTR != Com_RxSignalInfo[sigIdx].signalFilterMonitor ) /* Cfg filter. */
    {
        switch( COM_GETFILTER_ALGOOFFILTERINFO(sigIdx) )  /* Filter type. */
        {
            case COM_FILTER_ALWAYS:
                filterState = TRUE;
                break;
            case COM_FILTER_NEVER:
                filterState = FALSE;
                break;
            case COM_FILTER_MASKEDNEWDIFFERSMASKEDOLD:
                filterMask = (sint32)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (sint32)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);
                oldVlaue = *(sint32*)Com_RxSignalInfo[sigIdx].sigRTEValue;

                if( (filterMask & oldVlaue) != (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_MASKEDNEWEQUALSX:
                filterMask = (sint32)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (sint32)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);

                if( filterX == (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_MASKEDNEWDIFFERSX:
                filterMask = (sint32)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (sint32)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);

                if( filterX != (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_NEWISOUTSIDE:
                filterMin = (sint32)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMin);
                filterMax = (sint32)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMax);

                if( (filterMin <= newValue) && (newValue <= filterMax) )
                {
                    filterState = TRUE;
                }

                if( FALSE == filterState )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_NEWISWITHIN:
                filterMin = (sint32)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMin);
                filterMax = (sint32)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMax);

                if( (filterMin <= newValue) && (newValue <= filterMax))
                {
                    filterState = TRUE;
                }
                break;
            case COM_ONE_EVERY_N:
                /* unrealized */
                break;
            default:
                break;
        }
    }

    return filterState;
}

/*
********************************************************************************
* Function Name: Com_Signal_Boolean_EvaluateFilter
*
* Explanation: boolean type rx signal filter process.
*
* param: sigIdx: Rx Pdu Signal Index.
*
* retval: filterState: TRUE: received new value.
********************************************************************************
*/
static FUNC(boolean, COM_CODE) Com_Signal_Boolean_EvaluateFilter
(
    boolean newValue,
    uint16 sigIdx
)
{
    boolean filterState = TRUE;
    boolean filterMask;
    boolean filterX;
    boolean oldVlaue;

    if( NULL_PTR != Com_RxSignalInfo[sigIdx].signalFilterMonitor ) /* Cfg filter. */
    {
        switch( COM_GETFILTER_ALGOOFFILTERINFO(sigIdx) )  /* Filter type. */
        {
            case COM_FILTER_ALWAYS:
                filterState = TRUE;
                break;
            case COM_FILTER_NEVER:
                filterState = FALSE;
                break;
            case COM_FILTER_MASKEDNEWDIFFERSMASKEDOLD:
                filterMask = (boolean)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (boolean)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);
                oldVlaue = *(boolean*)Com_RxSignalInfo[sigIdx].sigRTEValue;

                if( (filterMask & oldVlaue) != (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_MASKEDNEWEQUALSX:
                filterMask = (boolean)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (boolean)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);

                if( filterX == (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_MASKEDNEWDIFFERSX:
                filterMask = (boolean)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (boolean)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);

                if( filterX != (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_ONE_EVERY_N:
                /* unrealized */
                break;
            default:
                break;
        }
    }

    return filterState;
}

/*
********************************************************************************
* Function Name: Com_Signal_uint64_EvaluateFilter
*
* Explanation: uint64 type rx signal filter process.
*
* param: sigIdx: Rx Pdu Signal Index.
*
* retval: filterState: TRUE: received new value.
********************************************************************************
*/
static FUNC(boolean, COM_CODE) Com_Signal_uint64_EvaluateFilter
(
    uint64 newValue,
    uint16 sigIdx
)
{
    boolean filterState = TRUE;
    uint64 filterMask;
    uint64 filterX;
    uint64 oldVlaue;
    uint64 filterMin;
    uint64 filterMax;

    if( NULL_PTR != Com_RxSignalInfo[sigIdx].signalFilterMonitor ) /* Cfg filter. */
    {
        switch( COM_GETFILTER_ALGOOFFILTERINFO(sigIdx) )  /* Filter type. */
        {
            case COM_FILTER_ALWAYS:
                filterState = TRUE;
                break;
            case COM_FILTER_NEVER:
                filterState = FALSE;
                break;
            case COM_FILTER_MASKEDNEWDIFFERSMASKEDOLD:
                filterMask = (uint64)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (uint64)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);
                oldVlaue = *(uint64*)Com_RxSignalInfo[sigIdx].sigRTEValue;

                if( (filterMask & oldVlaue) != (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_MASKEDNEWEQUALSX:
                filterMask = (uint64)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (uint64)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);

                if( filterX == (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_MASKEDNEWDIFFERSX:
                filterMask = (uint64)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (uint64)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);

                if( filterX != (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_NEWISOUTSIDE:
                filterMin = (uint64)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMin);
                filterMax = (uint64)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMax);

                if( (filterMin <= newValue) && (newValue <= filterMax) )
                {
                    filterState = TRUE;
                }

                if( FALSE == filterState )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_NEWISWITHIN:
                filterMin = (uint64)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMin);
                filterMax = (uint64)(Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMax);

                if( (filterMin <= newValue) && (newValue <= filterMax))
                {
                    filterState = TRUE;
                }
                break;
            case COM_ONE_EVERY_N:
                /* unrealized */
                break;
            default:
                break;
        }
    }

    return filterState;

}

/*
********************************************************************************
* Function Name: Com_Signal_sint64_EvaluateFilter
*
* Explanation: sint64 type rx signal filter process.
*
* param: sigIdx: Rx Pdu Signal Index.
*
* retval: filterState: TRUE: received new value.
********************************************************************************
*/
static FUNC(boolean, COM_CODE) Com_Signal_sint64_EvaluateFilter
(
    sint64 newValue,
    uint16 sigIdx
)
{
    boolean filterState = TRUE;
    sint64 filterMask;
    sint64 filterX;
    sint64 oldVlaue;
    sint64 filterMin;
    sint64 filterMax;

    if( NULL_PTR != Com_RxSignalInfo[sigIdx].signalFilterMonitor ) /* Cfg filter. */
    {
        switch( COM_GETFILTER_ALGOOFFILTERINFO(sigIdx) )  /* Filter type. */
        {
            case COM_FILTER_ALWAYS:
                filterState = TRUE;
                break;
            case COM_FILTER_NEVER:
                filterState = FALSE;
                break;
            case COM_FILTER_MASKEDNEWDIFFERSMASKEDOLD:
                filterMask = (Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);
                oldVlaue = *(sint64*)Com_RxSignalInfo[sigIdx].sigRTEValue;

                if( (filterMask & oldVlaue) != (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_MASKEDNEWEQUALSX:
                filterMask = (Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);

                if( filterX == (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_MASKEDNEWDIFFERSX:
                filterMask = (Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMask);
                filterX = (Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterX);

                if( filterX != (filterMask & newValue) )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_NEWISOUTSIDE:
                filterMin = (Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMin);
                filterMax = (Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMax);

                if( (filterMin <= newValue) && (newValue <= filterMax) )
                {
                    filterState = TRUE;
                }

                if( FALSE == filterState )
                {
                    filterState = TRUE;
                }
                break;
            case COM_FILTER_NEWISWITHIN:
                filterMin = (Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMin);
                filterMax = (Com_RxSignalInfo[sigIdx].signalFilterMonitor->alFilterMax);

                if( (filterMin <= newValue) && (newValue <= filterMax))
                {
                    filterState = TRUE;
                }
                break;
            case COM_ONE_EVERY_N:
                /* unrealized */
                break;
            default:
                break;
        }
    }

    return filterState;
}
#endif  /* COM_RXSIGFILTERINFO == STD_ON */

#if( COM_TXSIGNALFILTER_SUPPORTED == STD_ON )
/*
********************************************************************************
* Function Name: Com_TxSignalU8TMC_EvaluateFilter
*
* Explanation: TMC calculation for UINT8 type sending signal filtering.
*
* param: sigIdx: tx Signal Index.
*        sigValue: Signal value.
*
* retval: TRUE: The filter result is valid.
*         FALSE: The filter result is invalid.
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxSignalU8TMC_EvaluateFilter
(
    uint16 sigIdx,
    uint8 sigValue
)
{
    uint8 filterMask = COM_INIT_ZERO;
    uint8 filterX = COM_INIT_ZERO;
    uint8 oldValue = COM_INIT_ZERO;
    uint8 filterMin = COM_INIT_ZERO;
    uint8 filterMax = COM_INIT_ZERO;
    uint32 filterOffest = COM_INIT_ZERO;
    uint32 filterPeriod = COM_INIT_ZERO;
    uint32 filterOccurrence = COM_INIT_ZERO;

    /* Cfg filter. */
    if( NULL_PTR != Com_TxSignalInfo[sigIdx].sigFilterInfo )
    {
        /* Filter type. */
        switch( Com_TxSignalInfo[sigIdx].sigFilterInfo->acFilterAlgorithm )
        {
            /* No filtering is performed so that the message always passes. */
            case COM_FILTER_ALWAYS:
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                break;
            /* The filter removes all messages. */
            case COM_FILTER_NEVER:
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                break;
            /* Pass messages where the masked value hasnot changed. (new_value&mask) ==(old_value&mask) */
            case COM_FILTER_MASKEDNEWDIFFERSMASKEDOLD:
                filterMask = (uint8)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                oldValue = *(uint8*)Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue;
                /* [SWS_Com_00763] For the calculation of the transmission mode with the configured condition
                MASKED_NEW_DIFFERS_MASKED_OLD, the AUTOSAR COM module shall use the least significant ComBitSize bits only. */
                filterMask &= (COM_INIT_FF >> (COM_U8S8_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                oldValue &= (COM_INIT_FF >> (COM_U8S8_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                sigValue &= (COM_INIT_FF >> (COM_U8S8_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                if( (filterMask & oldValue) != (filterMask & (sigValue)) )
                {
                    /* [SWS_Com_00302] If the AUTOSAR COM module evaluates a filter for a signal to
                      true, (value is not filtered out) then the AUTOSAR COM module shall place the value
                      of that signal into old_value.
                    */
                    *(uint8*)Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue = sigValue;
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    /* [SWS_Com_00303] */
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass messages whose masked value is equal to a specific value. (new_value&mask) == x */
            case COM_FILTER_MASKEDNEWEQUALSX:
                filterMask = (uint8)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                filterX = (uint8)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterX);
                /* [SWS_COM_00813] */
                if( filterX == (filterMask & sigValue) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass messages whose masked value is not equal to a specific value. (new_value&mask) != x  */
            case COM_FILTER_MASKEDNEWDIFFERSX:
                filterMask = (uint8)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                filterX = (uint8)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterX);
                /* [SWS_COM_00813] */
                if( filterX != (filterMask & sigValue) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message if its value is outside a predefined boundary. (min > new_value) OR (new_value > max) */
            case COM_FILTER_NEWISOUTSIDE:
                filterMin = (uint8)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMin);
                filterMax = (uint8)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMax);
                /* [SWS_COM_00813] */
                if( (filterMin > sigValue) || (sigValue > filterMax) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message if its value is within a predefined boundary. (min <= new_value <=max) */
            case COM_FILTER_NEWISWITHIN:
                filterMin = (uint8)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMin);
                filterMax = (uint8)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMax);
                /* [SWS_COM_00813] */
                if( (filterMin <= sigValue) && (sigValue <= filterMax))
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message once every N message occurrences. (occurrence % period ==offset) */
            case COM_ONE_EVERY_N:
                filterOffest = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterOffest);
                filterPeriod = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterPeriod);
                filterOccurrence = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence);
                /* [SWS_Com_00231] 1.set OCCURRENCE to zero when OCCURRENCE == PERIOD. */
                if( filterPeriod == filterOccurrence )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence = COM_INIT_ZERO;
                    filterOccurrence = COM_INIT_ZERO;
                }
                /* [SWS_Com_00231] 2.set FILTER to true, when OCCURRENCE == OFFSET. */
                if( filterOffest == (filterOccurrence % filterPeriod) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                /* [SWS_Com_00231] 3.increment OCCURRENCE after filter processing. */
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence++;
                break;
            default:
                break;
        }
    }
}

/*
********************************************************************************
* Function Name: Com_TxSignalU16TMC_EvaluateFilter
*
* Explanation: TMC calculation for UINT8 type sending signal filtering.
*
* param: sigIdx: tx Signal Index.
*        sigValue: Signal value.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxSignalU16TMC_EvaluateFilter
(
    uint16 sigIdx,
    uint16 sigValue
)
{
    uint16 filterMask = COM_INIT_ZERO;
    uint16 filterX = COM_INIT_ZERO;
    uint16 oldValue = COM_INIT_ZERO;
    uint16 filterMin = COM_INIT_ZERO;
    uint16 filterMax = COM_INIT_ZERO;
    uint32 filterOffest = COM_INIT_ZERO;
    uint32 filterPeriod = COM_INIT_ZERO;
    uint32 filterOccurrence = COM_INIT_ZERO;

    /* Cfg filter. */
    if( NULL_PTR != Com_TxSignalInfo[sigIdx].sigFilterInfo )
    {
        /* Filter type. */
        switch( Com_TxSignalInfo[sigIdx].sigFilterInfo->acFilterAlgorithm )
        {
            /* No filtering is performed so that the message always passes. */
            case COM_FILTER_ALWAYS:
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                break;
            /* The filter removes all messages. */
            case COM_FILTER_NEVER:
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                break;
            /* Pass messages where the masked value hasnot changed. (new_value&mask) ==(old_value&mask) */
            case COM_FILTER_MASKEDNEWDIFFERSMASKEDOLD:
                filterMask = (uint16)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                oldValue = *(uint16*)Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue;
                /* [SWS_Com_00763] For the calculation of the transmission mode with the configured condition
                MASKED_NEW_DIFFERS_MASKED_OLD, the AUTOSAR COM module shall use the least significant ComBitSize bits only. */
                filterMask &= (COM_INIT_U16FF >> (COM_U16S16_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                oldValue &= (COM_INIT_U16FF >> (COM_U16S16_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                sigValue &= (COM_INIT_U16FF >> (COM_U16S16_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                if( (filterMask & oldValue) != (filterMask & (sigValue)) )
                {
                    /* [SWS_Com_00302] If the AUTOSAR COM module evaluates a filter for a signal to
                      true, (value is not filtered out) then the AUTOSAR COM module shall place the value
                      of that signal into old_value.
                    */
                    *(uint16*)Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue = sigValue;
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    /* [SWS_Com_00303] */
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass messages whose masked value is equal to a specific value. (new_value&mask) == x */
            case COM_FILTER_MASKEDNEWEQUALSX:
                filterMask = (uint16)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                filterX = (uint16)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterX);
                /* [SWS_COM_00813] */
                if( filterX == (filterMask & sigValue) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass messages whose masked value is not equal to a specific value. (new_value&mask) != x  */
            case COM_FILTER_MASKEDNEWDIFFERSX:
                filterMask = (uint16)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                filterX = (uint16)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterX);
                /* [SWS_COM_00813] */
                if( filterX != (filterMask & sigValue) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message if its value is outside a predefined boundary. (min > new_value) OR (new_value > max) */
            case COM_FILTER_NEWISOUTSIDE:
                filterMin = (uint16)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMin);
                filterMax = (uint16)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMax);
                /* [SWS_COM_00813] */
                if( (filterMin > sigValue) || (sigValue > filterMax) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message if its value is within a predefined boundary. (min <= new_value <=max) */
            case COM_FILTER_NEWISWITHIN:
                filterMin = (uint16)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMin);
                filterMax = (uint16)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMax);
                /* [SWS_COM_00813] */
                if( (filterMin <= sigValue) && (sigValue <= filterMax))
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message once every N message occurrences. (occurrence % period ==offset) */
            case COM_ONE_EVERY_N:
                filterOffest = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterOffest);
                filterPeriod = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterPeriod);
                filterOccurrence = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence);
                /* [SWS_Com_00231] 1.set OCCURRENCE to zero when OCCURRENCE == PERIOD. */
                if( filterPeriod == filterOccurrence )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence = COM_INIT_ZERO;
                    filterOccurrence = COM_INIT_ZERO;
                }
                /* [SWS_Com_00231] 2.set FILTER to true, when OCCURRENCE == OFFSET. */
                if( filterOffest == (filterOccurrence % filterPeriod) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                /* [SWS_Com_00231] 3.increment OCCURRENCE after filter processing. */
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence++;
                break;
            default:
                break;
        }
    }
}

/*
********************************************************************************
* Function Name: Com_TxSignalU32TMC_EvaluateFilter
*
* Explanation: TMC calculation for UINT32 type sending signal filtering.
*
* param: sigIdx: tx Signal Index.
*        sigValue: Signal value.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxSignalU32TMC_EvaluateFilter
(
    uint16 sigIdx,
    uint32 sigValue
)
{
    uint32 filterMask = COM_INIT_ZERO;
    uint32 filterX = COM_INIT_ZERO;
    uint32 oldValue = COM_INIT_ZERO;
    uint32 filterMin = COM_INIT_ZERO;
    uint32 filterMax = COM_INIT_ZERO;
    uint32 filterOffest = COM_INIT_ZERO;
    uint32 filterPeriod = COM_INIT_ZERO;
    uint32 filterOccurrence = COM_INIT_ZERO;

    /* Cfg filter. */
    if( NULL_PTR != Com_TxSignalInfo[sigIdx].sigFilterInfo )
    {
        /* Filter type. */
        switch( Com_TxSignalInfo[sigIdx].sigFilterInfo->acFilterAlgorithm )
        {
            /* No filtering is performed so that the message always passes. */
            case COM_FILTER_ALWAYS:
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                break;
            /* The filter removes all messages. */
            case COM_FILTER_NEVER:
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                break;
            /* Pass messages where the masked value hasnot changed. (new_value&mask) ==(old_value&mask) */
            case COM_FILTER_MASKEDNEWDIFFERSMASKEDOLD:
                filterMask = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                oldValue = *(uint32*)Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue;
                /* [SWS_Com_00763] For the calculation of the transmission mode with the configured condition
                MASKED_NEW_DIFFERS_MASKED_OLD, the AUTOSAR COM module shall use the least significant ComBitSize bits only. */
                filterMask &= (COM_INIT_U32FF >> (COM_U32S32_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                oldValue &= (COM_INIT_U32FF >> (COM_U32S32_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                sigValue &= (COM_INIT_U32FF >> (COM_U32S32_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                if( (filterMask & oldValue) != (filterMask & (sigValue)) )
                {
                    /* [SWS_Com_00302] If the AUTOSAR COM module evaluates a filter for a signal to
                      true, (value is not filtered out) then the AUTOSAR COM module shall place the value
                      of that signal into old_value.
                    */
                    *(uint32*)Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue = sigValue;
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    /* [SWS_Com_00303] */
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass messages whose masked value is equal to a specific value. (new_value&mask) == x */
            case COM_FILTER_MASKEDNEWEQUALSX:
                filterMask = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                filterX = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterX);
                /* [SWS_COM_00813] */
                if( filterX == (filterMask & sigValue) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass messages whose masked value is not equal to a specific value. (new_value&mask) != x  */
            case COM_FILTER_MASKEDNEWDIFFERSX:
                filterMask = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                filterX = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterX);
                /* [SWS_COM_00813] */
                if( filterX != (filterMask & sigValue) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message if its value is outside a predefined boundary. (min > new_value) OR (new_value > max) */
            case COM_FILTER_NEWISOUTSIDE:
                filterMin = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMin);
                filterMax = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMax);
                /* [SWS_COM_00813] */
                if( (filterMin > sigValue) || (sigValue > filterMax) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message if its value is within a predefined boundary. (min <= new_value <=max) */
            case COM_FILTER_NEWISWITHIN:
                filterMin = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMin);
                filterMax = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMax);
                /* [SWS_COM_00813] */
                if( (filterMin <= sigValue) && (sigValue <= filterMax))
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message once every N message occurrences. (occurrence % period ==offset) */
            case COM_ONE_EVERY_N:
                filterOffest = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterOffest);
                filterPeriod = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterPeriod);
                filterOccurrence = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence);
                /* [SWS_Com_00231] 1.set OCCURRENCE to zero when OCCURRENCE == PERIOD. */
                if( filterPeriod == filterOccurrence )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence = COM_INIT_ZERO;
                    filterOccurrence = COM_INIT_ZERO;
                }
                /* [SWS_Com_00231] 2.set FILTER to true, when OCCURRENCE == OFFSET. */
                if( filterOffest == (filterOccurrence % filterPeriod) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                /* [SWS_Com_00231] 3.increment OCCURRENCE after filter processing. */
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence++;
                break;
            default:
                break;
        }
    }
}

/*
********************************************************************************
* Function Name: Com_TxSignalU64TMC_EvaluateFilter
*
* Explanation: TMC calculation for UINT64 type sending signal filtering.
*
* param: sigIdx: tx Signal Index.
*        sigValue: Signal value.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxSignalU64TMC_EvaluateFilter
(
    uint16 sigIdx,
    uint64 sigValue
)
{
    uint32 filterOffest = COM_INIT_ZERO;
    uint32 filterPeriod = COM_INIT_ZERO;
    uint32 filterOccurrence = COM_INIT_ZERO;
    uint64 filterMask = COM_INIT_ZERO;
    uint64 filterX = COM_INIT_ZERO;
    uint64 oldValue = COM_INIT_ZERO;
    uint64 filterMin = COM_INIT_ZERO;
    uint64 filterMax = COM_INIT_ZERO;

    /* Cfg filter. */
    if( NULL_PTR != Com_TxSignalInfo[sigIdx].sigFilterInfo )
    {
        /* Filter type. */
        switch( Com_TxSignalInfo[sigIdx].sigFilterInfo->acFilterAlgorithm )
        {
            /* No filtering is performed so that the message always passes. */
            case COM_FILTER_ALWAYS:
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                break;
            /* The filter removes all messages. */
            case COM_FILTER_NEVER:
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                break;
            /* Pass messages where the masked value hasnot changed. (new_value&mask) ==(old_value&mask) */
            case COM_FILTER_MASKEDNEWDIFFERSMASKEDOLD:
                filterMask = (uint64)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                oldValue = *(uint64*)Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue;
                /* [SWS_Com_00763] For the calculation of the transmission mode with the configured condition
                MASKED_NEW_DIFFERS_MASKED_OLD, the AUTOSAR COM module shall use the least significant ComBitSize bits only. */
                filterMask &= (COM_INIT_U64FF >> (COM_U64S64_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                oldValue &= (COM_INIT_U64FF >> (COM_U64S64_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                sigValue &= (COM_INIT_U64FF >> (COM_U64S64_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                if( (filterMask & oldValue) != (filterMask & (sigValue)) )
                {
                    /* [SWS_Com_00302] If the AUTOSAR COM module evaluates a filter for a signal to
                      true, (value is not filtered out) then the AUTOSAR COM module shall place the value
                      of that signal into old_value.
                    */
                    *(uint64*)Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue = sigValue;
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    /* [SWS_Com_00303] */
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass messages whose masked value is equal to a specific value. (new_value&mask) == x */
            case COM_FILTER_MASKEDNEWEQUALSX:
                filterMask = (uint64)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                filterX = (uint64)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterX);
                /* [SWS_COM_00813] */
                if( filterX == (filterMask & sigValue) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass messages whose masked value is not equal to a specific value. (new_value&mask) != x  */
            case COM_FILTER_MASKEDNEWDIFFERSX:
                filterMask = (uint64)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                filterX = (uint64)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterX);
                /* [SWS_COM_00813] */
                if( filterX != (filterMask & sigValue) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message if its value is outside a predefined boundary. (min > new_value) OR (new_value > max) */
            case COM_FILTER_NEWISOUTSIDE:
                filterMin = (uint64)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMin);
                filterMax = (uint64)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMax);
                /* [SWS_COM_00813] */
                if( (filterMin > sigValue) || (sigValue > filterMax) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message if its value is within a predefined boundary. (min <= new_value <=max) */
            case COM_FILTER_NEWISWITHIN:
                filterMin = (uint64)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMin);
                filterMax = (uint64)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMax);
                /* [SWS_COM_00813] */
                if( (filterMin <= sigValue) && (sigValue <= filterMax))
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message once every N message occurrences. (occurrence % period ==offset) */
            case COM_ONE_EVERY_N:
                filterOffest = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterOffest);
                filterPeriod = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterPeriod);
                filterOccurrence = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence);
                /* [SWS_Com_00231] 1.set OCCURRENCE to zero when OCCURRENCE == PERIOD. */
                if( filterPeriod == filterOccurrence )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence = COM_INIT_ZERO;
                    filterOccurrence = COM_INIT_ZERO;
                }
                /* [SWS_Com_00231] 2.set FILTER to true, when OCCURRENCE == OFFSET. */
                if( filterOffest == (filterOccurrence % filterPeriod) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                /* [SWS_Com_00231] 3.increment OCCURRENCE after filter processing. */
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence++;
                break;
            default:
                break;
        }
    }
}

/*
********************************************************************************
* Function Name: Com_TxSignalS8TMC_EvaluateFilter
*
* Explanation: TMC calculation for SINT8 type sending signal filtering.
*
* param: sigIdx: tx Signal Index.
*        sigValue: Signal value.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxSignalS8TMC_EvaluateFilter
(
    uint16 sigIdx,
    sint8 sigValue
)
{
    sint8 filterMask = COM_INIT_ZERO;
    sint8 filterX = COM_INIT_ZERO;
    sint8 oldValue = COM_INIT_ZERO;
    sint8 filterMin = COM_INIT_ZERO;
    sint8 filterMax = COM_INIT_ZERO;
    uint32 filterOffest = COM_INIT_ZERO;
    uint32 filterPeriod = COM_INIT_ZERO;
    uint32 filterOccurrence = COM_INIT_ZERO;

    /* Cfg filter. */
    if( NULL_PTR != Com_TxSignalInfo[sigIdx].sigFilterInfo )
    {
        /* Filter type. */
        switch( Com_TxSignalInfo[sigIdx].sigFilterInfo->acFilterAlgorithm )
        {
            /* No filtering is performed so that the message always passes. */
            case COM_FILTER_ALWAYS:
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                break;
            /* The filter removes all messages. */
            case COM_FILTER_NEVER:
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                break;
            /* Pass messages where the masked value hasnot changed. (new_value&mask) ==(old_value&mask) */
            case COM_FILTER_MASKEDNEWDIFFERSMASKEDOLD:
                filterMask = (sint8)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                oldValue = *(sint8*)Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue;
                /* [SWS_Com_00763] For the calculation of the transmission mode with the configured condition
                MASKED_NEW_DIFFERS_MASKED_OLD, the AUTOSAR COM module shall use the least significant ComBitSize bits only. */
                filterMask &= (COM_INIT_FF >> (COM_U8S8_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                oldValue &= (COM_INIT_FF >> (COM_U8S8_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                sigValue &= (COM_INIT_FF >> (COM_U8S8_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                if( (filterMask & oldValue) != (filterMask & (sigValue)) )
                {
                    /* [SWS_Com_00302] If the AUTOSAR COM module evaluates a filter for a signal to
                      true, (value is not filtered out) then the AUTOSAR COM module shall place the value
                      of that signal into old_value.
                    */
                    *(sint8*)Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue = sigValue;
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    /* [SWS_Com_00303] */
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass messages whose masked value is equal to a specific value. (new_value&mask) == x */
            case COM_FILTER_MASKEDNEWEQUALSX:
                filterMask = (sint8)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                filterX = (sint8)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterX);
                /* [SWS_COM_00813] */
                if( filterX == (filterMask & sigValue) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass messages whose masked value is not equal to a specific value. (new_value&mask) != x  */
            case COM_FILTER_MASKEDNEWDIFFERSX:
                filterMask = (sint8)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                filterX = (sint8)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterX);
                /* [SWS_COM_00813] */
                if( filterX != (filterMask & sigValue) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message if its value is outside a predefined boundary. (min > new_value) OR (new_value > max) */
            case COM_FILTER_NEWISOUTSIDE:
                filterMin = (sint8)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMin);
                filterMax = (sint8)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMax);
                /* [SWS_COM_00813] */
                if( (filterMin > sigValue) || (sigValue > filterMax) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message if its value is within a predefined boundary. (min <= new_value <=max) */
            case COM_FILTER_NEWISWITHIN:
                filterMin = (sint8)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMin);
                filterMax = (sint8)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMax);
                /* [SWS_COM_00813] */
                if( (filterMin <= sigValue) && (sigValue <= filterMax))
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message once every N message occurrences. (occurrence % period ==offset) */
            case COM_ONE_EVERY_N:
                filterOffest = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterOffest);
                filterPeriod = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterPeriod);
                filterOccurrence = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence);
                /* [SWS_Com_00231] 1.set OCCURRENCE to zero when OCCURRENCE == PERIOD. */
                if( filterPeriod == filterOccurrence )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence = COM_INIT_ZERO;
                    filterOccurrence = COM_INIT_ZERO;
                }
                /* [SWS_Com_00231] 2.set FILTER to true, when OCCURRENCE == OFFSET. */
                if( filterOffest == (filterOccurrence % filterPeriod) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                /* [SWS_Com_00231] 3.increment OCCURRENCE after filter processing. */
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence++;
                break;
            default:
                break;
        }
    }
}

/*
********************************************************************************
* Function Name: Com_TxSignalS16TMC_EvaluateFilter
*
* Explanation: TMC calculation for SINT16 type sending signal filtering.
*
* param: sigIdx: tx Signal Index.
*        sigValue: Signal value.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxSignalS16TMC_EvaluateFilter
(
    uint16 sigIdx,
    sint16 sigValue
)
{
    sint16 filterMask = COM_INIT_ZERO;
    sint16 filterX = COM_INIT_ZERO;
    sint16 oldValue = COM_INIT_ZERO;
    sint16 filterMin = COM_INIT_ZERO;
    sint16 filterMax = COM_INIT_ZERO;
    uint32 filterOffest = COM_INIT_ZERO;
    uint32 filterPeriod = COM_INIT_ZERO;
    uint32 filterOccurrence = COM_INIT_ZERO;

    /* Cfg filter. */
    if( NULL_PTR != Com_TxSignalInfo[sigIdx].sigFilterInfo )
    {
        /* Filter type. */
        switch( Com_TxSignalInfo[sigIdx].sigFilterInfo->acFilterAlgorithm )
        {
            /* No filtering is performed so that the message always passes. */
            case COM_FILTER_ALWAYS:
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                break;
            /* The filter removes all messages. */
            case COM_FILTER_NEVER:
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                break;
            /* Pass messages where the masked value hasnot changed. (new_value&mask) ==(old_value&mask) */
            case COM_FILTER_MASKEDNEWDIFFERSMASKEDOLD:
                filterMask = (sint16)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                oldValue = *(sint16*)Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue;
                /* [SWS_Com_00763] For the calculation of the transmission mode with the configured condition
                MASKED_NEW_DIFFERS_MASKED_OLD, the AUTOSAR COM module shall use the least significant ComBitSize bits only. */
                filterMask &= (COM_INIT_U16FF >> (COM_U16S16_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                oldValue &= (COM_INIT_U16FF >> (COM_U16S16_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                sigValue &= (COM_INIT_U16FF >> (COM_U16S16_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                if( (filterMask & oldValue) != (filterMask & (sigValue)) )
                {
                    /* [SWS_Com_00302] If the AUTOSAR COM module evaluates a filter for a signal to
                      true, (value is not filtered out) then the AUTOSAR COM module shall place the value
                      of that signal into old_value.
                    */
                    *(sint16*)Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue = sigValue;
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    /* [SWS_Com_00303] */
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass messages whose masked value is equal to a specific value. (new_value&mask) == x */
            case COM_FILTER_MASKEDNEWEQUALSX:
                filterMask = (sint16)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                filterX = (sint16)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterX);
                /* [SWS_COM_00813] */
                if( filterX == (filterMask & sigValue) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass messages whose masked value is not equal to a specific value. (new_value&mask) != x  */
            case COM_FILTER_MASKEDNEWDIFFERSX:
                filterMask = (sint16)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                filterX = (sint16)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterX);
                /* [SWS_COM_00813] */
                if( filterX != (filterMask & sigValue) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message if its value is outside a predefined boundary. (min > new_value) OR (new_value > max) */
            case COM_FILTER_NEWISOUTSIDE:
                filterMin = (sint16)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMin);
                filterMax = (sint16)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMax);
                /* [SWS_COM_00813] */
                if( (filterMin > sigValue) || (sigValue > filterMax) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message if its value is within a predefined boundary. (min <= new_value <=max) */
            case COM_FILTER_NEWISWITHIN:
                filterMin = (sint16)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMin);
                filterMax = (sint16)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMax);
                /* [SWS_COM_00813] */
                if( (filterMin <= sigValue) && (sigValue <= filterMax))
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message once every N message occurrences. (occurrence % period ==offset) */
            case COM_ONE_EVERY_N:
                filterOffest = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterOffest);
                filterPeriod = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterPeriod);
                filterOccurrence = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence);
                /* [SWS_Com_00231] 1.set OCCURRENCE to zero when OCCURRENCE == PERIOD. */
                if( filterPeriod == filterOccurrence )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence = COM_INIT_ZERO;
                    filterOccurrence = COM_INIT_ZERO;
                }
                /* [SWS_Com_00231] 2.set FILTER to true, when OCCURRENCE == OFFSET. */
                if( filterOffest == (filterOccurrence % filterPeriod) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                /* [SWS_Com_00231] 3.increment OCCURRENCE after filter processing. */
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence++;
                break;
            default:
                break;
        }
    }
}

/*
********************************************************************************
* Function Name: Com_TxSignalS32TMC_EvaluateFilter
*
* Explanation: TMC calculation for SINT32 type sending signal filtering.
*
* param: sigIdx: tx Signal Index.
*        sigValue: Signal value.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxSignalS32TMC_EvaluateFilter
(
    uint16 sigIdx,
    sint32 sigValue
)
{
    sint32 filterMask = COM_INIT_ZERO;
    sint32 filterX = COM_INIT_ZERO;
    sint32 oldValue = COM_INIT_ZERO;
    sint32 filterMin = COM_INIT_ZERO;
    sint32 filterMax = COM_INIT_ZERO;
    uint32 filterOffest = COM_INIT_ZERO;
    uint32 filterPeriod = COM_INIT_ZERO;
    uint32 filterOccurrence = COM_INIT_ZERO;

    /* Cfg filter. */
    if( NULL_PTR != Com_TxSignalInfo[sigIdx].sigFilterInfo )
    {
        /* Filter type. */
        switch( Com_TxSignalInfo[sigIdx].sigFilterInfo->acFilterAlgorithm )
        {
            /* No filtering is performed so that the message always passes. */
            case COM_FILTER_ALWAYS:
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                break;
            /* The filter removes all messages. */
            case COM_FILTER_NEVER:
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                break;
            /* Pass messages where the masked value hasnot changed. (new_value&mask) ==(old_value&mask) */
            case COM_FILTER_MASKEDNEWDIFFERSMASKEDOLD:
                filterMask = (sint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                oldValue = *(sint32*)Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue;
                /* [SWS_Com_00763] For the calculation of the transmission mode with the configured condition
                MASKED_NEW_DIFFERS_MASKED_OLD, the AUTOSAR COM module shall use the least significant ComBitSize bits only. */
                filterMask &= (COM_INIT_U32FF >> (COM_U32S32_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                oldValue &= (COM_INIT_U32FF >> (COM_U32S32_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                sigValue &= (COM_INIT_U32FF >> (COM_U32S32_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                if( (filterMask & oldValue) != (filterMask & (sigValue)) )
                {
                    /* [SWS_Com_00302] If the AUTOSAR COM module evaluates a filter for a signal to
                      true, (value is not filtered out) then the AUTOSAR COM module shall place the value
                      of that signal into old_value.
                    */
                    *(sint32*)Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue = sigValue;
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    /* [SWS_Com_00303] */
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass messages whose masked value is equal to a specific value. (new_value&mask) == x */
            case COM_FILTER_MASKEDNEWEQUALSX:
                filterMask = (sint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                filterX = (sint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterX);
                /* [SWS_COM_00813] */
                if( filterX == (filterMask & sigValue) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass messages whose masked value is not equal to a specific value. (new_value&mask) != x  */
            case COM_FILTER_MASKEDNEWDIFFERSX:
                filterMask = (sint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                filterX = (sint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterX);
                /* [SWS_COM_00813] */
                if( filterX != (filterMask & sigValue) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message if its value is outside a predefined boundary. (min > new_value) OR (new_value > max) */
            case COM_FILTER_NEWISOUTSIDE:
                filterMin = (sint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMin);
                filterMax = (sint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMax);
                /* [SWS_COM_00813] */
                if( (filterMin > sigValue) || (sigValue > filterMax) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message if its value is within a predefined boundary. (min <= new_value <=max) */
            case COM_FILTER_NEWISWITHIN:
                filterMin = (sint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMin);
                filterMax = (sint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMax);
                /* [SWS_COM_00813] */
                if( (filterMin <= sigValue) && (sigValue <= filterMax))
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message once every N message occurrences. (occurrence % period ==offset) */
            case COM_ONE_EVERY_N:
                filterOffest = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterOffest);
                filterPeriod = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterPeriod);
                filterOccurrence = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence);
                /* [SWS_Com_00231] 1.set OCCURRENCE to zero when OCCURRENCE == PERIOD. */
                if( filterPeriod == filterOccurrence )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence = COM_INIT_ZERO;
                    filterOccurrence = COM_INIT_ZERO;
                }
                /* [SWS_Com_00231] 2.set FILTER to true, when OCCURRENCE == OFFSET. */
                if( filterOffest == (filterOccurrence % filterPeriod) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                /* [SWS_Com_00231] 3.increment OCCURRENCE after filter processing. */
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence++;
                break;
            default:
                break;
        }
    }
}

/*
********************************************************************************
* Function Name: Com_TxSignalS64TMC_EvaluateFilter
*
* Explanation: TMC calculation for SINT32 type sending signal filtering.
*
* param: sigIdx: tx Signal Index.
*        sigValue: Signal value.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxSignalS64TMC_EvaluateFilter
(
    uint16 sigIdx,
    sint64 sigValue
)
{
    uint32 filterOffest = COM_INIT_ZERO;
    uint32 filterPeriod = COM_INIT_ZERO;
    uint32 filterOccurrence = COM_INIT_ZERO;
    sint64 filterMask = COM_INIT_ZERO;
    sint64 filterX = COM_INIT_ZERO;
    sint64 oldValue = COM_INIT_ZERO;
    sint64 filterMin = COM_INIT_ZERO;
    sint64 filterMax = COM_INIT_ZERO;

    /* Cfg filter. */
    if( NULL_PTR != Com_TxSignalInfo[sigIdx].sigFilterInfo )
    {
        /* Filter type. */
        switch( Com_TxSignalInfo[sigIdx].sigFilterInfo->acFilterAlgorithm )
        {
            /* No filtering is performed so that the message always passes. */
            case COM_FILTER_ALWAYS:
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                break;
            /* The filter removes all messages. */
            case COM_FILTER_NEVER:
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                break;
            /* Pass messages where the masked value hasnot changed. (new_value&mask) ==(old_value&mask) */
            case COM_FILTER_MASKEDNEWDIFFERSMASKEDOLD:
                filterMask = (sint64)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                oldValue = *(sint64*)Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue;
                /* [SWS_Com_00763] For the calculation of the transmission mode with the configured condition
                MASKED_NEW_DIFFERS_MASKED_OLD, the AUTOSAR COM module shall use the least significant ComBitSize bits only. */
                filterMask &= (COM_INIT_U64FF >> (COM_U64S64_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                oldValue &= (COM_INIT_U64FF >> (COM_U64S64_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                sigValue &= (COM_INIT_U64FF >> (COM_U64S64_BITS - Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength));
                if( (filterMask & oldValue) != (filterMask & (sigValue)) )
                {
                    /* [SWS_Com_00302] If the AUTOSAR COM module evaluates a filter for a signal to
                      true, (value is not filtered out) then the AUTOSAR COM module shall place the value
                      of that signal into old_value.
                    */
                    *(sint64*)Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue = sigValue;
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    /* [SWS_Com_00303] */
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass messages whose masked value is equal to a specific value. (new_value&mask) == x */
            case COM_FILTER_MASKEDNEWEQUALSX:
                filterMask = (sint64)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                filterX = (sint64)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterX);
                /* [SWS_COM_00813] */
                if( filterX == (filterMask & sigValue) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass messages whose masked value is not equal to a specific value. (new_value&mask) != x  */
            case COM_FILTER_MASKEDNEWDIFFERSX:
                filterMask = (sint64)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                filterX = (sint64)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterX);
                /* [SWS_COM_00813] */
                if( filterX != (filterMask & sigValue) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message if its value is outside a predefined boundary. (min > new_value) OR (new_value > max) */
            case COM_FILTER_NEWISOUTSIDE:
                filterMin = (sint64)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMin);
                filterMax = (sint64)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMax);
                /* [SWS_COM_00813] */
                if( (filterMin > sigValue) || (sigValue > filterMax) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message if its value is within a predefined boundary. (min <= new_value <=max) */
            case COM_FILTER_NEWISWITHIN:
                filterMin = (sint64)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMin);
                filterMax = (sint64)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMax);
                /* [SWS_COM_00813] */
                if( (filterMin <= sigValue) && (sigValue <= filterMax))
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass a message once every N message occurrences. (occurrence % period ==offset) */
            case COM_ONE_EVERY_N:
                filterOffest = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterOffest);
                filterPeriod = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterPeriod);
                filterOccurrence = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence);
                /* [SWS_Com_00231] 1.set OCCURRENCE to zero when OCCURRENCE == PERIOD. */
                if( filterPeriod == filterOccurrence )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence = COM_INIT_ZERO;
                    filterOccurrence = COM_INIT_ZERO;
                }
                /* [SWS_Com_00231] 2.set FILTER to true, when OCCURRENCE == OFFSET. */
                if( filterOffest == (filterOccurrence % filterPeriod) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                /* [SWS_Com_00231] 3.increment OCCURRENCE after filter processing. */
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence++;
                break;
            default:
                break;
        }
    }
}

/*
********************************************************************************
* Function Name: Com_TxSignalBOOLEANTMC_EvaluateFilter
*
* Explanation: TMC calculation for BOOLEAN type sending signal filtering.
*
* param: sigIdx: tx Signal Index.
*        sigValue: Signal value.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxSignalBOOLEANTMC_EvaluateFilter
(
    uint16 sigIdx,
    boolean sigValue
)
{
    boolean filterMask = COM_INIT_ZERO;
    boolean filterX = COM_INIT_ZERO;
    boolean oldValue = COM_INIT_ZERO;
    uint32 filterOffest = COM_INIT_ZERO;
    uint32 filterPeriod = COM_INIT_ZERO;
    uint32 filterOccurrence = COM_INIT_ZERO;

    /* [SWS_Com_00676] For the evalutation of a TMS, the AUTOSAR COM module shall take
        all those (group) signals into account which configuration include
        a configured ComFilter container. See included containers of ComSignal
        and ComGroupSignal. */
    if( NULL_PTR != Com_TxSignalInfo[sigIdx].sigFilterInfo )
    {
        /* Filter type. */
        switch( Com_TxSignalInfo[sigIdx].sigFilterInfo->acFilterAlgorithm )
        {
            /* No filtering is performed so that the message always passes. */
            case COM_FILTER_ALWAYS:
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                break;
            /* The filter removes all messages. */
            case COM_FILTER_NEVER:
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                break;
            /* Pass messages where the masked value hasnot changed. (new_value&mask) ==(old_value&mask) */
            case COM_FILTER_MASKEDNEWDIFFERSMASKEDOLD:
                filterMask = (boolean)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                oldValue = *(boolean*)Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue;
                /* [SWS_Com_00763] For the calculation of the transmission mode with the configured condition
                MASKED_NEW_DIFFERS_MASKED_OLD, the AUTOSAR COM module shall use the least significant ComBitSize bits only. */
                filterMask &= (COM_INIT_FF >> Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength);
                oldValue &= (COM_INIT_FF >> Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength);
                sigValue &= (COM_INIT_FF >> Com_TxSignalInfo[sigIdx].sigBaseInfo->sigBitLength);
                if( (filterMask & oldValue) != (filterMask & (sigValue)) )
                {
                    /* [SWS_Com_00302] If the AUTOSAR COM module evaluates a filter for a signal to
                      true, (value is not filtered out) then the AUTOSAR COM module shall place the value
                      of that signal into old_value.
                    */
                    *(boolean*)Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOldValue = sigValue;
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    /* [SWS_Com_00303] */
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass messages whose masked value is equal to a specific value. (new_value&mask) == x */
            case COM_FILTER_MASKEDNEWEQUALSX:
                filterMask = (boolean)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                filterX = (boolean)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterX);
                /* [SWS_COM_00813] */
                if( filterX == (filterMask & sigValue) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* Pass messages whose masked value is not equal to a specific value. (new_value&mask) != x  */
            case COM_FILTER_MASKEDNEWDIFFERSX:
                filterMask = (boolean)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterMask);
                filterX = (boolean)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterX);
                /* [SWS_COM_00813] */
                if( filterX != (filterMask & sigValue) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                break;
            /* [SWS_Com_00439]  */
            case COM_FILTER_NEWISOUTSIDE:
            case COM_FILTER_NEWISWITHIN:
                break;
            /* Pass a message once every N message occurrences. (occurrence % period ==offset) */
            case COM_ONE_EVERY_N:
                filterOffest = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterOffest);
                filterPeriod = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->alFilterPeriod);
                filterOccurrence = (uint32)(Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence);
                /* [SWS_Com_00231] 1.set OCCURRENCE to zero when OCCURRENCE == PERIOD. */
                if( filterPeriod == filterOccurrence )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence = COM_INIT_ZERO;
                    filterOccurrence = COM_INIT_ZERO;
                }
                /* [SWS_Com_00231] 2.set FILTER to true, when OCCURRENCE == OFFSET. */
                if( filterOffest == (filterOccurrence % filterPeriod) )
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                }
                else
                {
                    Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                }
                /* [SWS_Com_00231] 3.increment OCCURRENCE after filter processing. */
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterOccurrence++;
                break;
            default:
                break;
        }
    }
}

/*
********************************************************************************
* Function Name: Com_TxSignalUINT8N_UINT8DYNTMC_EvaluateFilter
*
* Explanation: TMC calculation for UINT8_N or UINT8DYN type sending signal filtering.
*
* param: sigIdx: tx Signal Index.
*        sigValue: Signal value.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxSignalUINT8N_UINT8DYNTMC_EvaluateFilter
(
    uint16 sigIdx
)
{
    /* Cfg filter. */
    if( NULL_PTR != Com_TxSignalInfo[sigIdx].sigFilterInfo )
    {
        /* Filter type. */
        switch( Com_TxSignalInfo[sigIdx].sigFilterInfo->acFilterAlgorithm )
        {
            /* No filtering is performed so that the message always passes. */
            case COM_FILTER_ALWAYS:
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = TRUE;
                break;
            /* The filter removes all messages. */
            case COM_FILTER_NEVER:
                Com_TxSignalInfo[sigIdx].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc = FALSE;
                break;
            default:
                break;
        }
    }
}

/*
********************************************************************************
* Function Name: Com_TxSigFilterUpdateIpduTxMode
*
* Explanation: The service Com_TxSigFilterUpdateIpduTxMode sets the transmission mode of the
*              I-PDU referenced by PduId to Mode.
*
* param: PduId:Id of the I-PDU of which the transmission mode shall be changed.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxSigFilterUpdateIpduTxMode
(
    PduIdType PduId
)
{
    const COM_TxPduInfo_st* PduInfo = Com_TxPduInfo;
    const Com_TxMode_st* txModePtr;

    /* [SWS_Com_00032] If the TMS of an I-PDU evaluates to true, then the AUTOSAR
        COM module shall use the ComTxModeMode defined in configuration container
        ComTxModeTrue (ECUC_Com_00455) for that I-PDU. */
    if( TRUE == PduInfo[PduId].astPduInterMonitor->pduTxMode )
    {
        txModePtr = &Com_TxModeTrue[PduInfo[PduId].acTxModeIndex];
    }
    /* [SWS_Com_00799] If the TMS for an I-PDU evaluates to false, then the AUTOSAR
        COM module shall use the ComTxModeMode defined in configuration container
        ComTxModeFalse (ECUC_Com_00454) for that I-PDU. */
    else
    {
        txModePtr = &Com_TxModeFalse[PduInfo[PduId].acTxModeIndex];
    }
    /* [SWS_Com_00495] When a call to Com_SendSignal or Com_SendSignalGroup
        results into a change of the transmission mode of a started I-PDU to the transmission
        mode PERIODIC or MIXED.then the AUTOSAR COM module shall start the new
        transmission cycle with a call to PduR_ComTransmit within the next main function at
        the latest. The transmission shall be initiated regardless of the transfer property of
        the signal or signal group that caused the transmission mode switch. The minimum
        delay time and ComTxModeTimeOffset shall still be respected. */
    if( (COM_TXMODE_PREDIOC == txModePtr->acTxMode) || (COM_TXMODE_MIX == txModePtr->acTxMode) )
    {
        PduInfo[PduId].astPduInterMonitor->pduCycCounter = txModePtr->acTxModeOffset + COM_OPERAND_ONE;
    }
    /* [SWS_Com_00244] If a change of the TMS causes a change of the transmission
    mode for an I-PDU, then the AUTOSAR COM module shall restart the timer for the
    cycle time of the transmission mode PERIODIC and MIXED. */
    PduInfo[PduId].astPduInterMonitor->awPduTxTimeoutCounter = COM_INIT_ZERO;
}

/*
********************************************************************************
* Function Name: Com_TxSignalTypeFilter_Process
*
* Explanation: The TMC value is calculated based on the signal type and filtering algorithm.
*
* param: sigId : Id of signal to be sent.
*        sigDataPtr:  Reference to the signal data to be transmitted.
*
* retval: TRUE: TMC changed. FALSE: TMC not changed.
********************************************************************************
*/
static FUNC(boolean, COM_CODE) Com_TxSignalTypeFilter_Process
(
    uint16 sigId,
    P2CONST(void, AUTOMATIC, COM_APPL_CONST) sigDataPtr
)
{
    boolean filterOldState = FALSE;
    boolean filterChgState = FALSE;
    Com_SigType txSignalType;
    const COM_TxSignalInfo_st* txSigInfo = Com_TxSignalInfo;

    filterOldState = Com_TxSignalInfo[sigId].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc;
    /* Obtain signal type. */
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
    txSignalType = txSigInfo[sigId].sigType;
#else  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
    txSignalType = Com_GetSignalType(txSigInfo[sigId].sigBaseInfo->sigFuncIdx);
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
    /* Judge signal type. */
    switch( txSignalType )
    {
        /* Assign values according to different types of signals. */
        case COM_SIGTYPE_BOOLEAN:
            Com_TxSignalBOOLEANTMC_EvaluateFilter(sigId, *(boolean*)sigDataPtr);
            break;
        case COM_SIGTYPE_UINT8:
            Com_TxSignalU8TMC_EvaluateFilter(sigId, *(uint8*)sigDataPtr);
            break;
        case COM_SIGTYPE_UINT16:
            Com_TxSignalU16TMC_EvaluateFilter(sigId, *(uint16*)sigDataPtr);
            break;
        case COM_SIGTYPE_UINT32:
            Com_TxSignalU32TMC_EvaluateFilter(sigId, *(uint32*)sigDataPtr);
            break;
        case COM_SIGTYPE_UINT64:
            Com_TxSignalU64TMC_EvaluateFilter(sigId, *(uint64*)sigDataPtr);
            break;
        case COM_SIGTYPE_SINT8:
            Com_TxSignalS8TMC_EvaluateFilter(sigId, *(sint8*)sigDataPtr);
            break;
        case COM_SIGTYPE_SINT16:
            Com_TxSignalS16TMC_EvaluateFilter(sigId, *(sint16*)sigDataPtr);
            break;
        case COM_SIGTYPE_SINT32:
            Com_TxSignalS32TMC_EvaluateFilter(sigId, *(sint32*)sigDataPtr);
            break;
        case COM_SIGTYPE_SINT64:
            Com_TxSignalS64TMC_EvaluateFilter(sigId, *(sint64*)sigDataPtr);
            break;
        case COM_SIGTYPE_FLOAT32:
            break;
        case COM_SIGTYPE_FLOAT64:
            break;
        case COM_SIGTYPE_UINT8_DYN:
        case COM_SIGTYPE_UINT8_N:
            Com_TxSignalUINT8N_UINT8DYNTMC_EvaluateFilter(sigId);
            break;
        default:
            break;
    }

    if( filterOldState != Com_TxSignalInfo[sigId].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc )
    {
        filterChgState = TRUE;
    }
    return filterChgState;
}

/*
********************************************************************************
* Function Name: Com_TxSignalFilter_Process
*
* Explanation: The service updates the signal object identified by SignalId with
*              the signal referenced by the SignalDataPtr parameter.
*
* param: sigId : Id of signal to be sent.
*        sigDataPtr:  Reference to the signal data to be transmitted.
*
* retval: acRet : None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxSignalFilter_Process
(
    uint16 sigId,
    P2CONST(void, AUTOMATIC, COM_APPL_CONST) sigDataPtr
)
{
    /* TMC change flag. */
    boolean sigFilterChangeFlag = FALSE;
    const COM_TxSignalInfo_st* txSigInfo = Com_TxSignalInfo;
    const COM_TxPduInfo_st* PduInfo = Com_TxPduInfo;

    /* The TMC value is calculated based on the signal type and filtering algorithm. */
    sigFilterChangeFlag = Com_TxSignalTypeFilter_Process(sigId, sigDataPtr);
    /* The TMC value of signal changed. */
    if( TRUE == sigFilterChangeFlag )
    {
        PduIdType PduId = txSigInfo[sigId].acPduId;
        /* Check point. */
        if( NULL_PTR != PduInfo[PduId].astPduInterMonitor )
        {
            boolean lastTxMode = FALSE;
            /* SWS_Com_00679 */
            boolean newTxMode = FALSE;
            boolean filterDeal = FALSE;
            uint16 sigIndex = COM_INIT_ZERO;

            /* Determine TMS of signals of IPdu. */
            for( sigIndex = PduInfo[PduId].awSigStartIndex; sigIndex < PduInfo[PduId].awSigEndIndex; sigIndex++ )
            {
                if( NULL_PTR != txSigInfo[sigIndex].sigFilterInfo )
                {
                    filterDeal = TRUE;
                    if( TRUE == txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc )
                    {
                        /* SWS_Com_00678  */
                        newTxMode = TRUE;
                        break;
                    }
                }
            }
 #if( COM_TXSIGGROUPINFO == STD_ON )
            /* [SWS_Com_00676] */
            if ( (TRUE != newTxMode) && (PduInfo[PduId].acSigGrpEndIndex > PduInfo[PduId].acSigGrpStartIndex) )
            {
                /* Signalgroup process. */
                uint16 grpIndex = COM_INIT_ZERO;
                uint16 grpSigIndex = COM_INIT_ZERO;
                for( grpIndex = PduInfo[PduId].acSigGrpStartIndex; grpIndex < PduInfo[PduId].acSigGrpEndIndex; grpIndex++ )
                {
                    for( grpSigIndex = Com_TxSigGrpInfo[grpIndex].acSigIdxStart; grpSigIndex < Com_TxSigGrpInfo[grpIndex].acSigIdxdEnd; grpSigIndex++)
                    {
                        if( NULL_PTR != txSigInfo[grpSigIndex].sigFilterInfo )
                        {
                            filterDeal = TRUE;
                            if( TRUE == txSigInfo[grpSigIndex].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc )
                            {
                                /* SWS_Com_00678  */
                                newTxMode = TRUE;
                                break;
                            }
                        }
                    }
                    if( TRUE == newTxMode )
                    {
                        break;
                    }
                }
            }
#endif  /* (COM_TXSIGGROUPINFO == STD_ON) */

            if( TRUE == filterDeal )
            {
                /* Last send mode. */
                lastTxMode = PduInfo[PduId].astPduInterMonitor->pduTxMode;
                /* If the passed signal is not a group signal and the passed filter state is different to the current filter state,
                update the transition mode state. */
                if( lastTxMode != newTxMode )
                {
                    /* Update the current Tx Mode with the new Tx Mode. */
                    PduInfo[PduId].astPduInterMonitor->pduTxMode = newTxMode;
                    /* Signal TMS switching processing. */
                    Com_TxSigFilterUpdateIpduTxMode(PduId);
                }
            }
        }
    }
}

 #if( COM_TXSIGGROUPINFO == STD_ON )
/*
********************************************************************************
* Function Name: Com_TxGroupSignalFilter_Process
*
* Explanation: The service updates the signal object identified by SignalId with
*              the signal referenced by the SignalDataPtr parameter.
*
* param: sigId : Id of signal to be sent.
*        sigDataPtr:  Reference to the signal data to be transmitted.
*
* retval: acRet : None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxGroupSignalFilter_Process
(
    Com_SignalGroupIdType SignalGroupId
)
{
    boolean lastTxMode = FALSE;
    /* SWS_Com_00679 */
    boolean newTxMode = FALSE;
    boolean filterDeal = FALSE;
    uint16 sigIndex = COM_INIT_ZERO;
    PduIdType PduId = COM_INIT_ZERO;
    const COM_TxSigGrpInfo_st* sigGrpInfoPtr = &Com_TxSigGrpInfo[SignalGroupId];
    const COM_TxSignalInfo_st* txSigInfo = Com_TxSignalInfo;
    const COM_TxPduInfo_st* PduInfo = Com_TxPduInfo;

    /* Determine TMS of group signals of IPdu. */
    for( sigIndex = sigGrpInfoPtr->acSigIdxStart; sigIndex < sigGrpInfoPtr->acSigIdxdEnd; sigIndex++ )
    {
        if( NULL_PTR != txSigInfo[sigIndex].sigFilterInfo )
        {
            filterDeal = TRUE;
            if( TRUE == txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc )
            {
                /* SWS_Com_00678  */
                newTxMode = TRUE;
                break;
            }
        }
    }

    PduId = sigGrpInfoPtr->awPduId;
    /* [SWS_Com_00676] */
    if ( (TRUE != newTxMode) && (PduInfo[PduId].awSigEndIndex > PduInfo[PduId].awSigStartIndex) )
    {
        /* Signal process. */
        for( sigIndex = PduInfo[PduId].awSigStartIndex; sigIndex < PduInfo[PduId].awSigEndIndex; sigIndex++)
        {
            if( NULL_PTR != txSigInfo[sigIndex].sigFilterInfo )
            {
                filterDeal = TRUE;
                if( TRUE == txSigInfo[sigIndex].sigFilterInfo->TxSigFilterMonitor->sigFilterTmc )
                {
                    /* SWS_Com_00678  */
                    newTxMode = TRUE;
                    break;
                }
            }
        }
    }

    /* Check point. */
    if( NULL_PTR != PduInfo[PduId].astPduInterMonitor )
    {
        if( TRUE == filterDeal )
        {
            /* Last send mode. */
            lastTxMode = PduInfo[PduId].astPduInterMonitor->pduTxMode;
            /* If the passed signal is not a group signal and the passed filter state is different to the current filter state,
            update the transition mode state. */
            if( lastTxMode != newTxMode )
            {
                /* Update the current Tx Mode with the new Tx Mode. */
                PduInfo[PduId].astPduInterMonitor->pduTxMode = newTxMode;
                /* Signal TMS switching processing. */
                Com_TxSigFilterUpdateIpduTxMode(PduId);
            }
        }
    }
}
#endif  /* COM_TXSIGGROUPINFO == STD_ON */
#endif  /* COM_TXSIGNALFILTER_SUPPORTED == STD_ON */

#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Com_RxSigInvalidData_Handle_Boolean
*
* Explanation: Boolean stype rx signal invalid process.
*
* param: tmpNewValue: New received value.
*        sigIdx: Rx signal index.
*
* retval: exitInvalidFlag: TRUE: Cfg invalidcation and new value euqal invalid value.
*                          FALSE: New value should revied.
********************************************************************************
*/
static FUNC(boolean, COM_CODE) Com_RxSigInvalidData_Handle_Boolean
(
    boolean tmpNewValue,
    uint16 sigIdx
)
{
    boolean exitInvalidFlag = FALSE;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSignalInfo_st* rxSigInfo = &Com_RxSignalInfo[sigIdx];

    if( (NULL_PTR != rxSigInfo->invalidValue)
       && (COM_SIGNAL_INVALID_NONE != rxSigInfo->acInvalidAction) )
    {
        /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
        if( tmpNewValue == (*(boolean*)rxSigInfo->invalidValue) )
        {
            exitInvalidFlag = TRUE;
        }
    }

    return exitInvalidFlag;

}

/*
********************************************************************************
* Function Name: Com_RxSigInvalidData_Handle_uint8
*
* Explanation: uint8 stype rx signal invalid process.
*
* param: tmpNewValue: New received value.
*        sigIdx: Rx signal index.
*
* retval: exitInvalidFlag: TRUE: Cfg invalidcation and new value euqal invalid value.
*                          FALSE: New value should revied.
********************************************************************************
*/
static FUNC(boolean, COM_CODE) Com_RxSigInvalidData_Handle_uint8
(
    uint8 tmpNewValue,
    uint16 sigIdx
)
{
    boolean exitInvalidFlag = FALSE;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSignalInfo_st* rxSigInfo = &Com_RxSignalInfo[sigIdx];

    if( (NULL_PTR != rxSigInfo->invalidValue)
       && (COM_SIGNAL_INVALID_NONE != rxSigInfo->acInvalidAction) )
    {
        /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
        if( tmpNewValue == (*(uint8*)rxSigInfo->invalidValue) )
        {
            exitInvalidFlag = TRUE;
        }
    }

    return exitInvalidFlag;
}

/*
********************************************************************************
* Function Name: Com_RxSigInvalidData_Handle_uint16
*
* Explanation: uint16 stype rx signal invalid process.
*
* param: tmpNewValue: New received value.
*        sigIdx: Rx signal index.
*
* retval: exitInvalidFlag: TRUE: Cfg invalidcation and new value euqal invalid value.
*                          FALSE: New value should revied.
********************************************************************************
*/
static FUNC(boolean, COM_CODE) Com_RxSigInvalidData_Handle_uint16
(
    uint16 tmpNewValue,
    uint16 sigIdx
)
{
    boolean exitInvalidFlag = FALSE;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSignalInfo_st* rxSigInfo = &Com_RxSignalInfo[sigIdx];

    if( (NULL_PTR != rxSigInfo->invalidValue)
       && (COM_SIGNAL_INVALID_NONE != rxSigInfo->acInvalidAction) )
    {
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        if( tmpNewValue == (*(uint16*)rxSigInfo->invalidValue) )
        {
            exitInvalidFlag = TRUE;
        }
    }

    return exitInvalidFlag;
}

/*
********************************************************************************
* Function Name: Com_RxSigInvalidData_Handle_uint32
*
* Explanation: uint32 stype rx signal invalid process.
*
* param: tmpNewValue: New received value.
*        sigIdx: Rx signal index.
*
* retval: exitInvalidFlag: TRUE: Cfg invalidcation and new value euqal invalid value.
*                          FALSE: New value should revied.
********************************************************************************
*/
static FUNC(boolean, COM_CODE) Com_RxSigInvalidData_Handle_uint32
(
    uint32 tmpNewValue,
    uint16 sigIdx
)
{
    boolean exitInvalidFlag = FALSE;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSignalInfo_st* rxSigInfo = &Com_RxSignalInfo[sigIdx];

    if( (NULL_PTR != rxSigInfo->invalidValue)
       && (COM_SIGNAL_INVALID_NONE != rxSigInfo->acInvalidAction) )
    {
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        if( tmpNewValue == (*(uint32*)rxSigInfo->invalidValue) )
        {
            exitInvalidFlag = TRUE;
        }
    }

    return exitInvalidFlag;

}

/*
********************************************************************************
* Function Name: Com_RxSigInvalidData_Handle_uint64
*
* Explanation: uint64 stype rx signal invalid process.
*
* param: tmpNewValue: New received value.
*        sigIdx: Rx signal index.
*
* retval: exitInvalidFlag: TRUE: Cfg invalidcation and new value euqal invalid value.
*                          FALSE: New value should revied.
********************************************************************************
*/
static FUNC(boolean, COM_CODE)  Com_RxSigInvalidData_Handle_uint64
(
    uint64 tmpNewValue,
    uint16 sigIdx
)
{
    boolean exitInvalidFlag = FALSE;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSignalInfo_st* rxSigInfo = &Com_RxSignalInfo[sigIdx];

    if( (NULL_PTR != rxSigInfo->invalidValue)
       && (COM_SIGNAL_INVALID_NONE != rxSigInfo->acInvalidAction) )
    {
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        if( tmpNewValue == (*(uint64*)rxSigInfo->invalidValue) )
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        {
            exitInvalidFlag = TRUE;
        }
    }

    return exitInvalidFlag;

}

/*
********************************************************************************
* Function Name: Com_RxSigInvalidData_Handle_sint64
*
* Explanation: sint64 stype rx signal invalid process.
*
* param: tmpNewValue: New received value.
*        sigIdx: Rx signal index.
*
* retval: exitInvalidFlag: TRUE: Cfg invalidcation and new value euqal invalid value.
*                          FALSE: New value should revied.
********************************************************************************
*/
static FUNC(boolean, COM_CODE)  Com_RxSigInvalidData_Handle_sint64
(
    sint64 tmpNewValue,
    uint16 sigIdx
)
{
    boolean exitInvalidFlag = FALSE;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSignalInfo_st* rxSigInfo = &Com_RxSignalInfo[sigIdx];

    if( (NULL_PTR != rxSigInfo->invalidValue)
       && (COM_SIGNAL_INVALID_NONE != rxSigInfo->acInvalidAction) )
    {
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        if( tmpNewValue == (*(sint64*)rxSigInfo->invalidValue) )
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        {
            exitInvalidFlag = TRUE;
        }
    }

    return exitInvalidFlag;

}

/*
********************************************************************************
* Function Name: Com_RxSigInvalidData_Handle_sint8
*
* Explanation: sint8 stype rx signal invalid process.
*
* param: tmpNewValue: New received value.
*        sigIdx: Rx signal index.
*
* retval: exitInvalidFlag: TRUE: Cfg invalidcation and new value euqal invalid value.
*                          FALSE: New value should revied.
********************************************************************************
*/
static FUNC(boolean, COM_CODE)     Com_RxSigInvalidData_Handle_sint8
(
    sint8 tmpNewValue,
    uint16 sigIdx
)
{
    boolean exitInvalidFlag = FALSE;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSignalInfo_st* rxSigInfo = &Com_RxSignalInfo[sigIdx];

    if( (NULL_PTR != rxSigInfo->invalidValue)
       && (COM_SIGNAL_INVALID_NONE != rxSigInfo->acInvalidAction) )
    {
        /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
        if( tmpNewValue == (*(sint8*)rxSigInfo->invalidValue) )
        {
            exitInvalidFlag = TRUE;
        }
    }

    return exitInvalidFlag;

}

/*
********************************************************************************
* Function Name: Com_RxSigInvalidData_Handle_sint16
*
* Explanation: sint16 stype rx signal invalid process.
*
* param: tmpNewValue: New received value.
*        sigIdx: Rx signal index.
*
* retval: exitInvalidFlag: TRUE: Cfg invalidcation and new value euqal invalid value.
*                          FALSE: New value should revied.
********************************************************************************
*/
static FUNC(boolean, COM_CODE)     Com_RxSigInvalidData_Handle_sint16
(
    sint16 tmpNewValue,
    uint16 sigIdx
)
{
    boolean exitInvalidFlag = FALSE;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSignalInfo_st* rxSigInfo = &Com_RxSignalInfo[sigIdx];

    if( (NULL_PTR != rxSigInfo->invalidValue)
       && (COM_SIGNAL_INVALID_NONE != rxSigInfo->acInvalidAction) )
    {
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        if( tmpNewValue == (*(sint16*)rxSigInfo->invalidValue) )
        {
            exitInvalidFlag = TRUE;
        }
    }

    return exitInvalidFlag;

}

/*
********************************************************************************
* Function Name: Com_RxSigInvalidData_Handle_sint32
*
* Explanation: sint32 stype rx signal invalid process.
*
* param: tmpNewValue: New received value.
*        sigIdx: Rx signal index.
*
* retval: exitInvalidFlag: TRUE: Cfg invalidcation and new value euqal invalid value.
*                          FALSE: New value should revied.
********************************************************************************
*/
static FUNC(boolean, COM_CODE) Com_RxSigInvalidData_Handle_sint32
(
    sint32 tmpNewValue,
    uint16 sigIdx
)
{
    boolean exitInvalidFlag = FALSE;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSignalInfo_st* rxSigInfo = &Com_RxSignalInfo[sigIdx];

    if( (NULL_PTR != rxSigInfo->invalidValue)
       && (COM_SIGNAL_INVALID_NONE != rxSigInfo->acInvalidAction) )
    {
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        if( tmpNewValue == (*(sint32*)rxSigInfo->invalidValue) )
        {
            exitInvalidFlag = TRUE;
        }
    }

    return exitInvalidFlag;

}

/*
********************************************************************************
* Function Name: Com_RxSigInvalidData_Handle_uint8N
*
* Explanation: uint8_N stype rx signal invalid process.
*
* param: tmpNewValue: New received value.
*        sigIdx: Rx signal index.
*
* retval: exitInvalidFlag: TRUE: Cfg invalidcation and new value euqal invalid value.
*                          FALSE: New value should revied.
********************************************************************************
*/
static FUNC(boolean, COM_CODE) Com_RxSigInvalidData_Handle_uint8N
(
    /* PolySpace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.13" */
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) pduDataPtr,
    uint16 sigIdx,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.5" */
    uint16 byteLenth
)
{
    boolean exitInvalidFlag = FALSE;
    uint16 byteCtn = COM_INIT_ZERO;
    uint16 sigStartByte;
    uint16 sigLengthIndex;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSignalInfo_st* rxSigInfo = &Com_RxSignalInfo[sigIdx];

    if( (NULL_PTR != rxSigInfo->invalidValue)
       && (COM_SIGNAL_INVALID_NONE != rxSigInfo->acInvalidAction) )
    {
        /* Get start byte position of signal. */
        sigStartByte = rxSigInfo->sigBaseInfo->sigStartByte;
        for( sigLengthIndex = sigStartByte;
         sigLengthIndex < (sigStartByte + byteLenth); sigLengthIndex++ )
        {
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            if( ((uint8*)Com_RxSignalInfo[sigIdx].invalidValue)[sigLengthIndex]
                == pduDataPtr[sigLengthIndex])
            {
                byteCtn++;
            }
        }

        if( byteCtn == byteLenth )
        {
            exitInvalidFlag = TRUE;
        }
    }

    return exitInvalidFlag;

}

/*
********************************************************************************
* Function Name: Com_RxSigInvalidData_Handle_float32
*
* Explanation: float32 stype rx signal invalid process.
*
* param: tmpNewValue: New received value.
*        sigIdx: Rx signal index.
*
* retval: exitInvalidFlag: TRUE: Cfg invalidcation and new value euqal invalid value.
*                          FALSE: New value should revied.
********************************************************************************
*/
static FUNC(boolean, COM_CODE)    Com_RxSigInvalidData_Handle_float32
(
    float32 tmpNewValue,
    uint16 sigIdx
)
{
    boolean exitInvalidFlag = FALSE;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSignalInfo_st* rxSigInfo = &Com_RxSignalInfo[sigIdx];

    if( (NULL_PTR != rxSigInfo->invalidValue)
       && (COM_SIGNAL_INVALID_NONE != rxSigInfo->acInvalidAction) )
    {
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        if( TRUE == Com_CompareFloat32Values(tmpNewValue,(*(float32*)rxSigInfo->invalidValue)) )
        {
            exitInvalidFlag = TRUE;
        }
    }

    return exitInvalidFlag;

}

/*
********************************************************************************
* Function Name: Com_RxSigInvalidData_Handle_float64
*
* Explanation: float64 stype rx signal invalid process.
*
* param: tmpNewValue: New received value.
*        sigIdx: Rx signal index.
*
* retval: exitInvalidFlag: TRUE: Cfg invalidcation and new value euqal invalid value.
*                          FALSE: New value should revied.
********************************************************************************
*/
static FUNC(boolean, COM_CODE) Com_RxSigInvalidData_Handle_float64
(
    float64 tmpNewValue,
    uint16 sigIdx
)
{
    boolean exitInvalidFlag = FALSE;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSignalInfo_st* rxSigInfo = &Com_RxSignalInfo[sigIdx];

    if( (NULL_PTR != rxSigInfo->invalidValue)
       && (COM_SIGNAL_INVALID_NONE != rxSigInfo->acInvalidAction) )
    {
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        if( TRUE == Com_CompareFloat64Values(tmpNewValue,(*(float64*)rxSigInfo->invalidValue)) )
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        {
            exitInvalidFlag = TRUE;
        }
    }

    return exitInvalidFlag;

}

/*
********************************************************************************
* Function Name: Com_RxSigInvalidNotification_Handle
*
* Explanation: Rx Singal invliad Notification process.
*
* param: sigIdx: Rx Pdu Signal Index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigInvalidNotification_Handle
(
    uint16 sigIdx
)
{
#if( COM_RXSIG_INVALIDNOTIFICATION_SUPPORT == STD_ON )
    if( NULL_PTR != Com_RxSignalInfo[sigIdx].InvalidNotification_p )
    {
        Com_RxSignalInfo[sigIdx].InvalidNotification_p();
    }
#else  /* COM_RXSIG_INVALIDNOTIFICATION_SUPPORT == STD_ON */
    COM_DUMMY_STATEMENT(sigIdx);
#endif  /* COM_RXSIG_INVALIDNOTIFICATION_SUPPORT == STD_ON */
}
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */

#if( (COM_RXREPLACESIGOFRXTIMEOUTINFO == STD_ON) || (COM_RXUPDATEBITCFG_SUPPORT == STD_ON) )
/*
********************************************************************************
* Function Name: Com_RxSigTimeout_ReplaceProcess
*
* Explanation: Rx signal timeout process.
*
* param: sigIdx: Rx signal index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigTimeout_ReplaceProcess(uint16 sigIdx)
{
    Com_SigType receiveSignalType;
    uint16 byteIdx;
    uint16 sigAryTypeLen;

    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSignalInfo_st* rxSigInfo = &Com_RxSignalInfo[sigIdx];

    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    if( (NULL_PTR != rxSigInfo->sigRTEValue) && (NULL_PTR != rxSigInfo->initvalue) )
    {
        if( NULL_PTR != rxSigInfo->rxToReplaceValue )   /* Replace config value. */
        {
            Com_RxSigTimeout_Replace_ToValue(rxSigInfo);
        }
        else   /* Replace initvalue. */
        {
            /* Obtain signal type. */
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
            receiveSignalType = Com_RxSignalInfo[sigIdx].acSigType;
#else  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
            receiveSignalType = Com_GetSignalType(Com_RxSignalInfo[sigIdx].sigBaseInfo->sigFuncIdx);
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
            /* Different types of signal receive timeout replace process. */
            /* Judge signal type. */
            /* PolySpace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_Com_16.1" */
            switch( receiveSignalType )
            {
                case COM_SIGTYPE_BOOLEAN:
                    Com_SIGNAL_INITREPLACE(boolean, rxSigInfo);
                    break;
                case COM_SIGTYPE_UINT8:
                    Com_SIGNAL_INITREPLACE(uint8, rxSigInfo);
                    break;
                case COM_SIGTYPE_UINT16:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNAL_INITREPLACE(uint16, rxSigInfo);
                    break;
                case COM_SIGTYPE_UINT32:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNAL_INITREPLACE(uint32,rxSigInfo);
                    break;
                case COM_SIGTYPE_UINT64:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNAL_INITREPLACE(uint64, rxSigInfo);
                    break;
                case COM_SIGTYPE_SINT8:
                    Com_SIGNAL_INITREPLACE(sint8,rxSigInfo);
                    break;
                case COM_SIGTYPE_SINT16:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNAL_INITREPLACE(sint16,rxSigInfo);
                    break;
                case COM_SIGTYPE_SINT32:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNAL_INITREPLACE(sint32,rxSigInfo);
                    break;
                case COM_SIGTYPE_SINT64:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNAL_INITREPLACE(sint64, rxSigInfo);
                    break;
                case COM_SIGTYPE_FLOAT32:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNAL_INITREPLACE(float32, rxSigInfo);
                    break;
                case COM_SIGTYPE_FLOAT64:
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    Com_SIGNAL_INITREPLACE(float64, rxSigInfo);
                    break;
                case COM_SIGTYPE_UINT8_DYN:
                    sigAryTypeLen = Com_RxSignalInfo[sigIdx].astSignalInterMonitor->acDynSignalLength;

                    /* For ComSignalType UINT8_DYN it specifies the maximum length in bytes. */
                    if( sigAryTypeLen > Com_RxSignalInfo[sigIdx].sigBaseInfo->sigByteLength )
                    {
                        sigAryTypeLen = Com_RxSignalInfo[sigIdx].sigBaseInfo->sigByteLength;
                    }

                    /* In case of UINT8_DYN the initial size shall be 0. */

                    for( byteIdx = COM_INIT_ZERO; byteIdx < sigAryTypeLen; byteIdx++ )
                    {
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        ((uint8*)(rxSigInfo->sigRTEValue))[byteIdx] = COM_INIT_ZERO;   /* ECUC_Com_00170 */
                    }
                    break;
                case COM_SIGTYPE_UINT8_N:
                    /* Get byte length of signal. */
                    sigAryTypeLen = Com_RxSignalInfo[sigIdx].sigBaseInfo->sigByteLength;
                    /* In case of UINT8_N the default value is a string of length ComSignalLength
                    with all bytes set to 0x00. */
                    for( byteIdx = COM_INIT_ZERO; byteIdx < sigAryTypeLen; byteIdx++ )
                    {
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        ((uint8*)(rxSigInfo->sigRTEValue))[byteIdx] = COM_INIT_ZERO;   /* ECUC_Com_00170 */
                    }
                    break;
                /* PolySpace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_Com_16.4" */
                default :
                    break;
            }
        }
    }
}
#endif  /* (COM_RXREPLACESIGOFRXTIMEOUTINFO == STD_ON) || (COM_RXUPDATEBITCFG_SUPPORT == STD_ON) */

#if( COM_RXSIGGROUPINFO == STD_ON )
#if( (COM_RXREPLACESIGGROUPOFRXTIMEOUTINFO == STD_ON) || (COM_RXUPDATEBITCFG_SUPPORT == STD_ON) )
/*
********************************************************************************
* Function Name: Com_RxSigGrpTimeout_ReplaceProcess
*
* Explanation: Rx signal Group timeout process.
*
* param: sigGrpIdx: Rx signalgroup index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigGrpTimeout_ReplaceProcess(uint16 sigGrpIdx)
{
    Com_SigType receiveSignalType;
    uint16 sigAryTypeLen;
    uint16 byteIdx;
    uint16 signalIdx;
    uint16 sigGrpStart;
    uint16 sigGrpEnd;
    const COM_RxSignalInfo_st* rxSigInfo = NULL_PTR;

    sigGrpStart = Com_RxPduInfo[Com_RxSigGrpInfo[sigGrpIdx].awPduId].awSigStartIndex;
    sigGrpEnd   = Com_RxPduInfo[Com_RxSigGrpInfo[sigGrpIdx].awPduId].awSigEndIndex;

    for( signalIdx = sigGrpStart; signalIdx < sigGrpEnd; signalIdx++ )
    {
        rxSigInfo = &Com_RxSignalInfo[signalIdx];
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
        if( (NULL_PTR != rxSigInfo->sigRTEValue) && (NULL_PTR != rxSigInfo->initvalue) )
        {
            if( NULL_PTR != rxSigInfo->rxToReplaceValue )  /* Repalce config value.  */
            {
                Com_RxSigGrpTimeout_Replace_ToValue(rxSigInfo);
            }
            else
            {
                /* Obtain signal type. */
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
                receiveSignalType = Com_RxSignalInfo[signalIdx].acSigType;
#else  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
                receiveSignalType = Com_GetSignalType(rxSigInfo->sigBaseInfo->sigFuncIdx);
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
                /* Judge signal type. */
                switch( receiveSignalType )
                {
                    /* Different types of signal group receive timeout replacement. */
                    case COM_SIGTYPE_BOOLEAN:
                        Com_SIGNAL_INITREPLACESHADOW(boolean, rxSigInfo);
                        break;
                    case COM_SIGTYPE_UINT8:
                        Com_SIGNAL_INITREPLACESHADOW(uint8, rxSigInfo);
                        break;
                    case COM_SIGTYPE_UINT16:
                        Com_SIGNAL_INITREPLACESHADOW(uint16, rxSigInfo);
                        break;
                    case COM_SIGTYPE_UINT32:
                        Com_SIGNAL_INITREPLACESHADOW(uint32, rxSigInfo);
                        break;
                    case COM_SIGTYPE_UINT64:
                        Com_SIGNAL_INITREPLACESHADOW(uint64, rxSigInfo);
                        break;
                    case COM_SIGTYPE_SINT8:
                        Com_SIGNAL_INITREPLACESHADOW(sint8, rxSigInfo);
                        break;
                    case COM_SIGTYPE_SINT16:
                        Com_SIGNAL_INITREPLACESHADOW(sint16, rxSigInfo);
                        break;
                    case COM_SIGTYPE_SINT32:
                        Com_SIGNAL_INITREPLACESHADOW(sint32, rxSigInfo);
                        break;
                    case COM_SIGTYPE_SINT64:
                        Com_SIGNAL_INITREPLACESHADOW(sint64, rxSigInfo);
                        break;
                    case COM_SIGTYPE_UINT8_DYN:
                        if(NULL_PTR != Com_RxSignalInfo[signalIdx].astSignalInterMonitor)
                        {
                            sigAryTypeLen = Com_RxSignalInfo[signalIdx].astSignalInterMonitor->acDynSignalLength;
                            /* For ComSignalType UINT8_DYN it specifies the maximum length in bytes. */
                            if( sigAryTypeLen > Com_RxSignalInfo[signalIdx].sigBaseInfo->sigStartByte )
                            {
                                sigAryTypeLen = Com_RxSignalInfo[signalIdx].sigBaseInfo->sigStartByte;
                            }
                            /* In case of UINT8_DYN the initial size shall be 0. */
                            for( byteIdx = COM_INIT_ZERO; byteIdx < sigAryTypeLen; byteIdx++ )
                            {
                                ((uint8*)(rxSigInfo->sigRTEValue))[signalIdx] = COM_INIT_ZERO; /* ECUC_Com_00170 */
                            }
                        }
                        break;
                    case COM_SIGTYPE_UINT8_N:
                        sigAryTypeLen = Com_RxSignalInfo[signalIdx].sigBaseInfo->sigStartByte;
                        /* In case of UINT8_N the default value is a string of length ComSignalLength
                        with all bytes set to 0x00. */
                        for( byteIdx = COM_INIT_ZERO; byteIdx < sigAryTypeLen; byteIdx++ )
                        {
                            ((uint8*)(rxSigInfo->sigRTEValue))[byteIdx] = COM_INIT_ZERO;   /* ECUC_Com_00170 */
                        }
                        break;
                    case COM_SIGTYPE_FLOAT32:
                        Com_SIGNAL_INITREPLACESHADOW(uint32, rxSigInfo);
                        break;
                    case COM_SIGTYPE_FLOAT64:
                        Com_SIGNAL_INITREPLACESHADOW(uint64, rxSigInfo);
                        break;
                    default:
                        break;
                }
            }
        }
#else  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
        if( (NULL_PTR != rxSigInfo->sigShadowValue) && (NULL_PTR != rxSigInfo->initvalue) )
        {
            if( NULL_PTR != rxSigInfo->rxToReplaceValue )  /* Repalce config value.  */
            {
                Com_RxSigGrpTimeout_Replace_ToValue(rxSigInfo);
            }
            else
            {
                /* Obtain signal type. */
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
                receiveSignalType = Com_RxSignalInfo[signalIdx].acSigType;
#else  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
                receiveSignalType = Com_GetSignalType(rxSigInfo->sigBaseInfo->sigFuncIdx);
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
                /* Judge signal type. */
                /* PolySpace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_Com_16.1" */
                switch( receiveSignalType )
                {
                    /* Different types of signal group receive timeout replacement. */
                    case COM_SIGTYPE_BOOLEAN:
                        Com_SIGNAL_INITREPLACESHADOW(boolean, rxSigInfo);
                        break;
                    case COM_SIGTYPE_UINT8:
                        Com_SIGNAL_INITREPLACESHADOW(uint8, rxSigInfo);
                        break;
                    case COM_SIGTYPE_UINT16:
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        Com_SIGNAL_INITREPLACESHADOW(uint16, rxSigInfo);
                        break;
                    case COM_SIGTYPE_UINT32:
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        Com_SIGNAL_INITREPLACESHADOW(uint32, rxSigInfo);
                        break;
                    case COM_SIGTYPE_UINT64:
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        Com_SIGNAL_INITREPLACESHADOW(uint64, rxSigInfo);
                        break;
                    case COM_SIGTYPE_SINT8:
                        Com_SIGNAL_INITREPLACESHADOW(sint8, rxSigInfo);
                        break;
                    case COM_SIGTYPE_SINT16:
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        Com_SIGNAL_INITREPLACESHADOW(sint16, rxSigInfo);
                        break;
                    case COM_SIGTYPE_SINT32:
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        Com_SIGNAL_INITREPLACESHADOW(sint32, rxSigInfo);
                        break;
                    case COM_SIGTYPE_SINT64:
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        Com_SIGNAL_INITREPLACESHADOW(sint64, rxSigInfo);
                        break;
                    case COM_SIGTYPE_UINT8_DYN:
                        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                        if(NULL_PTR != Com_RxSignalInfo[signalIdx].astSignalInterMonitor)
                        {
                            sigAryTypeLen = Com_RxSignalInfo[signalIdx].astSignalInterMonitor->acDynSignalLength;
                            /* For ComSignalType UINT8_DYN it specifies the maximum length in bytes. */
                            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                            if( sigAryTypeLen > Com_RxSignalInfo[signalIdx].sigBaseInfo->sigStartByte )
                            {
                                sigAryTypeLen = Com_RxSignalInfo[signalIdx].sigBaseInfo->sigStartByte;
                            }
                            /* In case of UINT8_DYN the initial size shall be 0. */
                            for( byteIdx = COM_INIT_ZERO; byteIdx < sigAryTypeLen; byteIdx++ )
                            {
                                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                                ((uint8*)(rxSigInfo->sigShadowValue))[signalIdx] = COM_INIT_ZERO; /* ECUC_Com_00170 */
                            }
                        }
                        break;
                    case COM_SIGTYPE_UINT8_N:
                        sigAryTypeLen = Com_RxSignalInfo[signalIdx].sigBaseInfo->sigStartByte;
                        /* In case of UINT8_N the default value is a string of length ComSignalLength
                        with all bytes set to 0x00. */
                        for( byteIdx = COM_INIT_ZERO; byteIdx < sigAryTypeLen; byteIdx++ )
                        {
                            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_Com_11.8" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                            ((uint8*)(rxSigInfo->sigShadowValue))[byteIdx] = COM_INIT_ZERO;   /* ECUC_Com_00170 */
                        }
                        break;
                    case COM_SIGTYPE_FLOAT32:
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        Com_SIGNAL_INITREPLACESHADOW(uint32, rxSigInfo);
                        break;
                    case COM_SIGTYPE_FLOAT64:
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        Com_SIGNAL_INITREPLACESHADOW(uint64, rxSigInfo);
                        break;
                    /* PolySpace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_Com_16.4" */
                    default:
                        break;
                }
            }
        }
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
    }
}
#endif  /* (COM_RXREPLACESIGGROUPOFRXTIMEOUTINFO == STD_ON) || (COM_RXUPDATEBITCFG_SUPPORT) */
#endif  /* COM_RXSIGGROUPINFO == STD_ON */

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Com_RxUpdateCntProcess
*
* Explanation: Receive update_bit counter percess.
*
* param: PduInfo: Rx pdu index.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxUpdateCntProcess
(
    P2CONST(COM_RxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
)
{
    uint8 updatevalue;
    uint16 sigIdx;
    uint16 grpIdx;
    uint32 updateBitPosit;
    const COM_RxSignalInfo_st* rxSigInfo = NULL_PTR;

    for( sigIdx = PduInfo->awSigStartIndex; sigIdx < PduInfo->awSigEndIndex; sigIdx++ )
    {
        /* Not signal group. */
        if( COM_SIG_NO_GROUP_DEF == Com_RxSignalInfo[sigIdx].acSigGrpIdx )
        {
            rxSigInfo = &Com_RxSignalInfo[sigIdx];
            /* PolySpace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" PolySpace +1 DEFECT:USELESS_WRITE [Justified:Unset] "NSCA_Polyspace_Com_USELESS_WRITE" */
            updateBitPosit = Com_RxSignalInfo[sigIdx].updateBitPosition;
            /* Configured updatebit. */
            if( COM_SIG_NO_UPDATEBIT_DEF != Com_RxSignalInfo[sigIdx].updateBitPosition )
            {
                /* Get updatebit value. */
                updateBitPosit = rxSigInfo->updateBitPosition;
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                updatevalue = PduInfo->datavalid[updateBitPosit / COM_1BYTE_BITLENGTH];
                updatevalue = updatevalue >> (updateBitPosit % COM_1BYTE_BITLENGTH);
                updatevalue = updatevalue & COM_OPERAND_ONE;
                /* If the update bit is updated. */
                /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                if( COM_OPERAND_ONE == updatevalue )
                {
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                    (*((uint16*)rxSigInfo->updateCnt)) = Com_RxSignalInfo[sigIdx].rxTimeOut;
                }
            }
        }
    }

    /* SignalGroup type. */
    for( grpIdx = PduInfo->acSigGrpStartIndex; grpIdx < PduInfo->acSigGrpEndIndex; grpIdx++ )
    {
        /* PolySpace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" PolySpace +1 DEFECT:USELESS_WRITE [Justified:Unset] "NSCA_Polyspace_Com_USELESS_WRITE" */
        updateBitPosit = Com_RxSigGrpInfo[grpIdx].updateBitPosition;
        /* Configured updatebit. */
        if( COM_SIG_NO_UPDATEBIT_DEF != Com_RxSigGrpInfo[grpIdx].updateBitPosition )
        {
            /* Get updatebit value. */
            updateBitPosit = Com_RxSigGrpInfo[grpIdx].updateBitPosition;
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            updatevalue = PduInfo->datavalid[updateBitPosit / COM_1BYTE_BITLENGTH];
            updatevalue = updatevalue >> (updateBitPosit % COM_1BYTE_BITLENGTH);
            updatevalue = updatevalue & COM_OPERAND_ONE;
            /* If the update bit is updated. */
            if( COM_OPERAND_ONE == updatevalue )
            {
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                (*((uint16*)Com_RxSigGrpInfo[grpIdx].updateCnt)) = Com_RxSigGrpInfo[grpIdx].rxTimeOut;
            }
        }
    }
}
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */

/*
********************************************************************************
* Function Name: Com_RxDlMon_MainFunctionRx
*
* Explanation: Rx signal or signalgroup timeout process.
*
* param: PduInfo: Rx pdu info.
*
* retval: None
********************************************************************************
*/
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_RxDlMon_MainFunctionRx
(
    P2CONST(COM_RxPduInfo_st, AUTOMATIC, COM_APPL_CONST) PduInfo
)
{
    uint16 sigIdx;
#if( COM_RXSIGGROUPINFO == STD_ON )
    uint16 grpIdx;
#endif  /* COM_RXSIGGROUPINFO == STD_ON */
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxPduInfo_st* rxPduInfo = PduInfo;

    /* pdu state id active. */
    if( (COM_PDU_ACTIVE == rxPduInfo->astPduInterMonitor->pduSta)
        && (TRUE == rxPduInfo->astPduInterMonitor->enableDeadline) )
    {
        if( COM_INIT_ZERO < rxPduInfo->astPduInterMonitor->acPduCycCounter )
        {
            rxPduInfo->astPduInterMonitor->acPduCycCounter--;
        }
        if( COM_INIT_ZERO < rxPduInfo->astPduInterMonitor->acPduCycCounterForGw)
        {
            rxPduInfo->astPduInterMonitor->acPduCycCounterForGw--;
        }
        if( (COM_INIT_ZERO == rxPduInfo->astPduInterMonitor->acPduCycCounterForGw) &&
            (COM_INIT_ZERO != rxPduInfo->astPduInterMonitor->acPduCycCounterForGwInit) )
        {
            rxPduInfo->astPduInterMonitor->rxTimeout = TRUE;
        }

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
        for( sigIdx = rxPduInfo->awSigStartIndex; sigIdx < rxPduInfo->awSigEndIndex; sigIdx++ )
        {
            if( COM_INIT_ZERO < Com_RxSignalInfo[sigIdx].rxTimeOut )  /* Configured timeout. */
            {
                if( (COM_SIG_NO_UPDATEBIT_DEF != Com_RxSignalInfo[sigIdx].updateBitPosition)
                   && (COM_SIG_NO_GROUP_DEF == Com_RxSignalInfo[sigIdx].acSigGrpIdx)
                   && (TRUE == Com_RxSignalInfo[sigIdx].astSignalInterMonitor->acSignalUpdateEnableDeadline) )
                {
                    if( NULL_PTR != Com_RxSignalInfo[sigIdx].updateCnt )   /* Check NULL_PTR. */
                    {
                        /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                        if( *((uint16*)Com_RxSignalInfo[sigIdx].updateCnt) != COM_INIT_ZERO )
                        {
                            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                            (*((uint16*)Com_RxSignalInfo[sigIdx].updateCnt))--;
                        }
                        else   /* Time out. */
                        {
                            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                            *((uint16*)Com_RxSignalInfo[sigIdx].updateCnt)
                                  = Com_RxSignalInfo[sigIdx].rxTimeOut;
                             Com_RxSigTimeoutProcess(sigIdx);
                        }
                    }
                }
            }
        }

#if( COM_RXSIGGROUPINFO == STD_ON )
        for( grpIdx = rxPduInfo->acSigGrpStartIndex; grpIdx < rxPduInfo->acSigGrpEndIndex; grpIdx++ )
        {
            if( COM_INIT_ZERO < Com_RxSigGrpInfo[grpIdx].rxTimeOut )
            {
                /* Configured with updatebit. */
                if(( COM_SIG_NO_UPDATEBIT_DEF != Com_RxSigGrpInfo[grpIdx].updateBitPosition )
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    && (TRUE == Com_RxSigGrpInfo[grpIdx].astSignalGrpInterMonitor->acSignalGrpUpdateEnableDeadline) )
                {
                    if( NULL_PTR != Com_RxSigGrpInfo[grpIdx].updateCnt )    /* Check NULL_PTR. */
                    {
                        /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                        Com_RxSigGrpTimeoutProcess(grpIdx, (*((uint16*)Com_RxSigGrpInfo[grpIdx].updateCnt)));
                    }
                }
            }
        }
#endif  /* COM_RXSIGGROUPINFO == STD_ON */

#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */

        if( COM_INIT_ZERO == rxPduInfo->astPduInterMonitor->acPduCycCounter )  /* Time Out */
        {
            /* Set pdu timeout flag. */
            rxPduInfo->astPduInterMonitor->rxTimeout = TRUE;
            /* PolySpace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
            rxPduInfo->astPduInterMonitor->acPduRecSts |= COM_PDU_RECTIMEOUT;  /* PRQA S 4432, 4522 */ /* NSCA_QAC_Com_Rule10.3, NSCA_QAC_Com_Rule10.1 */
            /* Reset timeout counter. */
            rxPduInfo->astPduInterMonitor->acPduCycCounter
              = rxPduInfo->sigMinimumTimeout;
#if( COM_GWROUTETIMEOUTVALUE_SUPPORT == STD_ON )
            /* Route the timeout-value of the GW signal. */
            rxPduInfo->astPduInterMonitor->acPduRecSts |= COM_PDU_GW_SIG_DSCP_FLAG;
#endif  /* COM_GWROUTETIMEOUTVALUE_SUPPORT == STD_ON */

            for( sigIdx = rxPduInfo->awSigStartIndex; sigIdx < rxPduInfo->awSigEndIndex; sigIdx++ )
            {
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
                if( COM_INIT_ZERO < Com_RxSignalInfo[sigIdx].rxTimeOut )
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */
                {
                    if( (COM_SIG_NO_GROUP_DEF == Com_RxSignalInfo[sigIdx].acSigGrpIdx)
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
                       && (COM_SIG_NO_UPDATEBIT_DEF == Com_RxSignalInfo[sigIdx].updateBitPosition)
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */
                       && (TRUE == Com_RxSignalInfo[sigIdx].astSignalInterMonitor->acSignalEnableDeadline) )
                    {
#if( COM_RXREPLACESIGOFRXTIMEOUTINFO == STD_ON )
                        if( COM_SIGNAL_TIMEOUT_REPLACE == Com_RxSignalInfo[sigIdx].acRxTimeOutAction )
                        {
                            Com_RxSigTimeout_ReplaceProcess(sigIdx);
                        }
#endif  /* COM_RXREPLACEOFRXTIMEOUTINFO == STD_ON */
#if( COM_RXSIG_TIMEOUTNOTIFICATION_SUPPORT == STD_ON )
                        if( NULL_PTR != Com_RxSignalInfo[sigIdx].TimeOutNotification_p )
                        {
                            Com_RxSignalInfo[sigIdx].TimeOutNotification_p();
                        }
#endif  /* COM_RXSIG_TIMEOUTNOTIFICATION_SUPPORT == STD_ON */
                    }
                }
            }

#if( COM_RXSIGGROUPINFO == STD_ON )
            for( grpIdx = rxPduInfo->acSigGrpStartIndex; grpIdx < rxPduInfo->acSigGrpEndIndex; grpIdx++ )
            {
                if( 
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
                    (COM_SIG_NO_UPDATEBIT_DEF == Com_RxSigGrpInfo[grpIdx].updateBitPosition) && 
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */
                     /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    (TRUE == Com_RxSigGrpInfo[grpIdx].astSignalGrpInterMonitor->acSignalGrpEnableDeadline) )
                {
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
                    if( COM_INIT_ZERO < Com_RxSigGrpInfo[grpIdx].rxTimeOut )
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */
                    {
#if( COM_RXREPLACESIGGROUPOFRXTIMEOUTINFO == STD_ON )
                        if( COM_SIGNAL_TIMEOUT_REPLACE == Com_RxSigGrpInfo[grpIdx].acRxDataTimeoutAction )
                        {
                            Com_RxSigGrpTimeout_ReplaceProcess(grpIdx);
                        }
#endif  /* COM_RXREPLACESIGGROUPOFRXTIMEOUTINFO == STD_ON  */
#if( COM_RXSIGGRP_TIMEOUTNOTIFICATION_SUPPORT == STD_ON )
                        if( NULL_PTR != Com_RxSigGrpInfo[grpIdx].TimeoutNotification_p )
                        {
                            Com_RxSigGrpInfo[grpIdx].TimeoutNotification_p();
                        }
#endif  /* COM_RXSIGGRP_TIMEOUTNOTIFICATION_SUPPORT == STD_ON */
                    }
                }
            }
#endif  /* COM_RXSIGGROUPINFO == STD_ON */
        }
    }
}

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Com_RxTimeOut_Process
*
* Explanation: Rx signal timeout process.
*
* param: sigIdx: Rx signal index.
*        pduTimeCouter: Rx signal time counter.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigTimeoutProcess(uint16 sigIdx)
{
    COM_DUMMY_STATEMENT(sigIdx);
    /* Timeout Type is Replace. */
    if( COM_SIGNAL_TIMEOUT_REPLACE == Com_RxSignalInfo[sigIdx].acRxTimeOutAction )
    {
        Com_RxSigTimeout_ReplaceProcess(sigIdx);
    }

#if( COM_RXSIG_TIMEOUTNOTIFICATION_SUPPORT == STD_ON )
    /* Rx signal configured time out notification. */
    if( NULL_PTR != Com_RxSignalInfo[sigIdx].TimeOutNotification_p )
    {
        Com_RxSignalInfo[sigIdx].TimeOutNotification_p();
    }
#endif  /* COM_RXSIG_TIMEOUTNOTIFICATION_SUPPORT == STD_ON */
}
#endif

#if( (COM_RXUPDATEBITCFG_SUPPORT == STD_ON) && (COM_RXSIGGROUPINFO == STD_ON) )
/*
********************************************************************************
* Function Name: Com_RxSigGrpTimeoutProcess
*
* Explanation: Rx signal timeout process.
*
* param: sigIdx: Rx signal index.
*        pduTimeCouter: Rx signal time counter.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigGrpTimeoutProcess(uint16 sigGrpIdx, uint16 pduTimeCouter)
{
    if( COM_INIT_ZERO == pduTimeCouter ) /* Timeout reached. */
    {
        if( COM_SIG_NO_UPDATEBIT_DEF != Com_RxSigGrpInfo[sigGrpIdx].updateBitPosition )
        {
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            *((uint16*)Com_RxSigGrpInfo[sigGrpIdx].updateCnt)
              = Com_RxSigGrpInfo[sigGrpIdx].rxTimeOut;
        }
        else
        {
            Com_RxPduInfo[Com_RxSigGrpInfo[sigGrpIdx].awPduId].astPduInterMonitor->acPduCycCounter
              = Com_RxSigGrpInfo[sigGrpIdx].rxTimeOut;
        }

        /* Timeout Type is Replace. */
        if( COM_SIGNAL_TIMEOUT_REPLACE == Com_RxSigGrpInfo[sigGrpIdx].acRxDataTimeoutAction )
        {
            Com_RxSigGrpTimeout_ReplaceProcess(sigGrpIdx);
        }
#if( COM_RXSIGGRP_TIMEOUTNOTIFICATION_SUPPORT == STD_ON )
        /* Rx signal group configured time out notification. */
        if( NULL_PTR != Com_RxSigGrpInfo[sigGrpIdx].TimeoutNotification_p )
        {
            Com_RxSigGrpInfo[sigGrpIdx].TimeoutNotification_p();
        }
#endif  /* COM_RXSIGGRP_TIMEOUTNOTIFICATION_SUPPORT == STD_ON */
    }
    else
    {
        if( COM_SIG_NO_UPDATEBIT_DEF != Com_RxSigGrpInfo[sigGrpIdx].updateBitPosition )
        {
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            (*((uint16*)Com_RxSigGrpInfo[sigGrpIdx].updateCnt))--;
        }
    }
}
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON && COM_RXSIGGROUPINFO == STD_ON */

#if( (COM_PERFOPTMZ_SUPPORT != STD_ON) ||\
     (COM_MULTICORE_SUPPORT == STD_ON) ||\
     ((COM_GWSIGNALDSCP_NUM > COM_INIT_ZERO) && (COM_MULTICORE_SUPPORT != STD_ON)) )
/*
********************************************************************************
* Function Name: Com_RxSigRead_Normal
*
* Explanation: Parse received message data to signal.
*
* param: pduDataPtr: Received message data.
*        rxSigInfoPtr: Rx signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(uint32, COM_CODE) Com_RxSigRead_Normal
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) pduDataPtr,
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr
)
{
    Com_SigEndianessType sigEndianess;
    Com_SigBitLengthType sigBitSize;
    Com_SigByteLengthType sigByteLength;
    Com_SigByteLengthType sigByteLengthIndex;
    Com_SigStartBitType sigStartBit;
    Com_SigStartByteType sigStartByte;
    uint32 sigValue = COM_INIT_ZERO;

    sigStartBit =  rxSigInfoPtr->sigBaseInfo->sigStartBit;    /* Get start bit position in byte of signal. */
    sigBitSize = rxSigInfoPtr->sigBaseInfo->sigBitLength;     /* Get bit length of signal. */
    sigStartByte = rxSigInfoPtr->sigBaseInfo->sigStartByte;   /* Get start byte position of signal. */
    sigEndianess = Com_GetSignalEndianess(rxSigInfoPtr->sigBaseInfo->sigFuncIdx);   /* Get endianess of signal. */
    sigByteLength = rxSigInfoPtr->sigBaseInfo->sigByteLength; /* Get byte length of signal. */

    if( COM_4BYTELENGTH < sigByteLength )
    {
        /* High 4 Byte Data. */
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < COM_4BYTELENGTH;sigByteLengthIndex++ )
        {
            if( COM_BIG_ENDIAN == sigEndianess )
            {
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                sigValue |= ((uint32)pduDataPtr[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
            }
            else
            {
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                sigValue |= ((uint32)pduDataPtr[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
            }
        }
        sigValue = sigValue << (COM_1BYTE_BITLENGTH - ((uint32)sigStartBit % COM_1BYTE_BITLENGTH));
        /* Low 4 Byte Data. */
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        sigValue = sigValue | ((uint32)pduDataPtr[sigStartByte] >> ((uint32)sigStartBit % COM_1BYTE_BITLENGTH));
    }
    else
    {
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < sigByteLength;sigByteLengthIndex++ )
        {
            if( COM_BIG_ENDIAN == sigEndianess )
            {
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                sigValue |= ((uint32)pduDataPtr[sigStartByte - sigByteLengthIndex]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
            }
            else
            {
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                sigValue |= ((uint32)pduDataPtr[sigStartByte + sigByteLengthIndex]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
            }
        }
        sigValue = sigValue >> (sigStartBit % COM_1BYTE_BITLENGTH);
    }

    /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_Com_SHF" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" */
    sigValue = (sigValue & (COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigBitSize)));

    return sigValue;
}

/*
********************************************************************************
* Function Name: Com_RxSigRead_Large_64
*
* Explanation: Parse received message data to large signal.
*
* param: pduDataPtr: Received message data.
*        rxSigInfoPtr: Rx signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(uint64, COM_CODE) Com_RxSigRead_Large_64
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) pduDataPtr,
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr
)
{
    Com_SigEndianessType sigEndianess;
    Com_SigBitLengthType sigBitSize;
    Com_SigByteLengthType sigByteLength;
    Com_SigByteLengthType sigByteLengthIndex;
    Com_SigStartBitType sigStartBit;
    Com_SigStartByteType sigStartByte;
    uint64 sigValue = COM_INIT_ZERO;

    sigStartBit =  rxSigInfoPtr->sigBaseInfo->sigStartBit;    /* Get start bit position in byte of signal. */
    sigBitSize = rxSigInfoPtr->sigBaseInfo->sigBitLength;     /* Get bit length of signal. */
    sigStartByte = rxSigInfoPtr->sigBaseInfo->sigStartByte;   /* Get start byte position of signal. */
    sigEndianess = Com_GetSignalEndianess(rxSigInfoPtr->sigBaseInfo->sigFuncIdx); /* Get endianess of signal. */
    sigByteLength = rxSigInfoPtr->sigBaseInfo->sigByteLength; /* Get byte length of signal. */

    if( COM_8BYTELENGTH < sigByteLength )
    {
        /* High 4 Byte Data. */
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < COM_8BYTELENGTH;sigByteLengthIndex++ )
        {
            if( COM_BIG_ENDIAN == sigEndianess )
            {
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                sigValue |= ((uint64)pduDataPtr[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
            }
            else
            {
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                sigValue |= ((uint64)pduDataPtr[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
            }
        }
        sigValue = sigValue << (COM_1BYTE_BITLENGTH - (sigStartBit % COM_1BYTE_BITLENGTH));
        /* Low 4 Byte Data. */
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
        sigValue = sigValue | ((uint64)pduDataPtr[sigStartByte] >> (sigStartBit % COM_1BYTE_BITLENGTH));
    }
    else
    {
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < sigByteLength;sigByteLengthIndex++ )
        {
            if( COM_BIG_ENDIAN == sigEndianess )
            {
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                sigValue |= ((uint64)pduDataPtr[sigStartByte - sigByteLengthIndex]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
            }
            else
            {
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                sigValue |= ((uint64)pduDataPtr[sigStartByte + sigByteLengthIndex]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
            }
        }
        sigValue = sigValue >> (sigStartBit % COM_1BYTE_BITLENGTH);
    }

    /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_Com_SHF" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" */
    sigValue = (sigValue & (COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigBitSize)));

    return sigValue;
}
#endif /* (COM_PERFOPTMZ_SUPPORT != STD_ON) ||\
          (COM_MULTICORE_SUPPORT == STD_ON) ||\
         ((COM_GWSIGNALDSCP_NUM > COM_INIT_ZERO) && (COM_MULTICORE_SUPPORT != STD_ON)) */

/*
********************************************************************************
* Function Name: Com_RxSigRead_Normal
*
* Explanation: Parse received message data to signal.
*
* param: sigIdx: Rx signal index.
*        pduDataPtr: Received message data.
*        rxSigInfoPtr: Rx signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSignalAnalysis_Process
(
    uint16 sigIdx,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) pduDataPtr,
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfoPtr
)
{
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
    /* Get sigFuncIdx of signal. */
    uint8 sigFuncIdx = rxSigInfoPtr->sigBaseInfo->sigFuncIdx;

    /* Judge funId of signal. */
    if( (COM_RXPARSESIGNAL_FUNC_NUM + COM_ONE) > sigFuncIdx )
    {
        /* receive signal updatebit/invalid/filter process. */
        Com_RxSigUbInvFilterFuncTable[sigFuncIdx](pduDataPtr, rxSigInfoPtr, sigIdx);
    }
#else
    boolean valueBoolean;
    /* Get bit length of signal. */
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    Com_SigBitLengthType bitSize = rxSigInfoPtr->sigBaseInfo->sigBitLength;
    uint8 uintValue08;
    sint8 intValue08;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.5" */
    uint16 bytelenth;
    uint16 uintValue16;
    sint16 intValue16;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.5" */
    uint32 value;
    uint32 uintValue32;
    sint32 intValue32;
    float32 valuef32;
    uint64 valueLarge;
    sint64 intValue64;
    float64 floatValue64;

    /* Judge signal type. */
    /* PolySpace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_Com_16.1" */
    switch( Com_GetSignalType(rxSigInfoPtr->sigBaseInfo->sigFuncIdx) )
    {
        case COM_SIGTYPE_BOOLEAN:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:10.6 [Justified:Unset] "NSCA_Polyspace_Com_10.6" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            value = pduDataPtr[rxSigInfoPtr->sigBaseInfo->sigStartByte] >> (rxSigInfoPtr->sigBaseInfo->sigStartBit % COM_1BYTE_BITLENGTH);  /* PRQA S 4491*/ /* NSCA_QAC_Com_Rule10.6 */
            valueBoolean = (boolean)(value & COM_OPERAND_ONE);
            /* Boolean type receive signal updatebit/invalid/filter process. */
            Com_RxSigUbInvFilterProcessBoolean(&valueBoolean, sigIdx);
            break;
        case COM_SIGTYPE_UINT8:
            value = Com_RxSigRead_Normal((const uint8*)pduDataPtr, rxSigInfoPtr);
            uintValue08 = (uint8)value;
            /* Uint8 type receive signal updatebit/invalid/filter process. */
            Com_RxSigUbInvFilterProcessU8(&uintValue08, sigIdx);
            break;
        case COM_SIGTYPE_UINT16:
            value = Com_RxSigRead_Normal((const uint8*)pduDataPtr, rxSigInfoPtr);
            uintValue16 = (uint16)value;
            /* Uint16 type receive signal updatebit/invalid/filter process. */
            Com_RxSigUbInvFilterProcessU16(&uintValue16, sigIdx);
            break;
        case COM_SIGTYPE_UINT32:
            value = Com_RxSigRead_Normal((const uint8*)pduDataPtr, rxSigInfoPtr);
            /* Uint32 type receive signal updatebit/invalid/filter process. */
            Com_RxSigUbInvFilterProcessU32(&value, sigIdx);
            break;
        case COM_SIGTYPE_UINT64:
            valueLarge = Com_RxSigRead_Large_64((const uint8*)pduDataPtr, rxSigInfoPtr);
            /* Uint64 type receive signal updatebit/invalid/filter process. */
            Com_RxSigUbInvFilterProcessU64(&valueLarge, sigIdx);
            break;
        case COM_SIGTYPE_SINT8:
            value = Com_RxSigRead_Normal((const uint8*)pduDataPtr, rxSigInfoPtr);
            /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_Com_SHF" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" */
            if( COM_OPERAND_ONE == (value >> (bitSize - COM_OPERAND_ONE)) ) /* sigValue < 0 */
            {
                /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_Com_SHF" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" */
                uintValue32 = (value | ((uint32)COM_INIT_FF << bitSize)); /* high-order position   complement 1 */
                intValue08 = (sint8)((uint8)uintValue32);
            }
            else
            {
                intValue08 = (sint8)((uint8)value);
            }
            /* Sint8 type receive signal updatebit/invalid/filter process. */
            Com_RxSigUbInvFilterProcessI8(&intValue08, sigIdx);
            break;
        case COM_SIGTYPE_SINT16:
            value = Com_RxSigRead_Normal((const uint8*)pduDataPtr, rxSigInfoPtr);
            /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_Com_SHF" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" */
            if( COM_OPERAND_ONE == (value >> (bitSize - COM_OPERAND_ONE)) )
            {
                /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_Com_SHF" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" */
                uintValue32 = (value | ((uint32)COM_INIT_U16FF << bitSize));
                intValue16 = (sint16)((uint16)uintValue32);
            }
            else
            {
                intValue16 = (sint16)((uint16)value);
            }
            /* Sint16 type receive signal updatebit/invalid/filter process. */
            Com_RxSigUbInvFilterProcessI16(&intValue16, sigIdx);
            break;
        case COM_SIGTYPE_SINT32:
            value = Com_RxSigRead_Normal((const uint8*)pduDataPtr, rxSigInfoPtr);
            /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_Com_SHF" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" */
            if( COM_OPERAND_ONE == (value >> (bitSize - COM_OPERAND_ONE)) )
            {
                /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_Com_SHF" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" */
                uintValue32 = (value | ((uint32)COM_INIT_U32FF << bitSize));
                intValue32 = (sint32)uintValue32;
            }
            else
            {
                intValue32 = (sint32)value;
            }
            /* Sint32 type receive signal updatebit/invalid/filter process. */
            Com_RxSigUbInvFilterProcessI32(&intValue32, sigIdx);
            break;
        case COM_SIGTYPE_SINT64:
            valueLarge = Com_RxSigRead_Large_64((const uint8*)pduDataPtr, rxSigInfoPtr);
            /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_Com_SHF" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" */
            if( COM_OPERAND_ONE == (valueLarge >> (bitSize - COM_OPERAND_ONE)) ) /* sigValue < 0 */
            {
                /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_Com_SHF" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:10.8 [Justified:Unset] "NSCA_Polyspace_Com_10.8" */
                intValue64 = (sint64)(valueLarge | (uint64)(COM_INIT_U64FF << bitSize)); /* high-order position   complement 1 */
            }
            else
            {
                intValue64 = (sint64)valueLarge;
            }
            /* Sint64 type receive signal updatebit/invalid/filter process. */
            Com_RxSigUbInvFilterProcessI64(&intValue64, sigIdx);
            break;
        case COM_SIGTYPE_UINT8_DYN:
            /* Get dyn signal length. */
            Com_RxDynSignalLengthEvlateProcess(sigIdx);
            bytelenth = Com_RxSignalInfo[sigIdx].astSignalInterMonitor->acDynSignalLength;
            /* Uint8_N type receive signal updatebit/invalid/filter process. */
            Com_RxSigUbInvFilterProcessUint8N(pduDataPtr, sigIdx, bytelenth);
            break;
        case COM_SIGTYPE_UINT8_N:
            bytelenth = Com_RxSignalInfo[sigIdx].sigBaseInfo->sigStartByte;
            /* Uint8_N type receive signal updatebit/invalid/filter process. */
            Com_RxSigUbInvFilterProcessUint8N(pduDataPtr, sigIdx, bytelenth);
            break;
        case COM_SIGTYPE_FLOAT32:
            value = Com_RxSigRead_Normal((const uint8*)pduDataPtr, rxSigInfoPtr);
            /* PolySpace +1 MISRA-C3:11.3 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            valuef32 = *(float32*)((uint8*)(&value));  /* PRQA S 0310, 3305 */ /* NSCA_QAC_Com_Rule11.3 */
            /* Float32 type receive signal updatebit/invalid/filter process. */
            Com_RxSigUbInvFilterProcessFloat32(&valuef32, sigIdx);
            break;
        case COM_SIGTYPE_FLOAT64:
            valueLarge = Com_RxSigRead_Large_64((const uint8*)pduDataPtr, rxSigInfoPtr);
            /* PolySpace +1 MISRA-C3:11.3 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            floatValue64 = *(float64*)((uint8*)(&valueLarge));  /* PRQA S 0310, 3305 */ /* NSCA_QAC_Com_Rule11.3 */
            /* Float64 type receive signal updatebit/invalid/filter process. */
            Com_RxSigUbInvFilterProcessFloat64(&floatValue64, sigIdx);
            break;
        /* PolySpace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_Com_16.4" */
        default :
            break;
    }
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
}

#if( COM_GWSIGNAL_NUM > COM_INIT_ZERO )
/*
********************************************************************************
* Function Name: Com_GwSig_ClearRecvFlag
*
* Explanation: Clear the received GwSig flag of the related RxPdu.
*
* param: gwMappingSigPtr: Gw signal info pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_GwSig_ClearRecvFlag
(
    P2CONST(Com_GwMappingSigType, AUTOMATIC, COM_APPL_CONST) gwMappingSigPtr
)
{
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    uint16 srcSigId = gwMappingSigPtr->srcSigId;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    uint16 srcSigGrpId = gwMappingSigPtr->srcSigGrpId;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSignalInfo_st* rxSigInfo = Com_RxSignalInfo;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxPduInfo_st* RxPduInfo = Com_RxPduInfo;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSigGrpInfo_st* rxSigGrpInfo = Com_RxSigGrpInfo;

    if( COM_GW_NO_SIG_DEF != srcSigId )
    {
        /* clear Signal flag.(COM_PDU_WAITRECEIVE) */
        /* PolySpace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
        RxPduInfo[rxSigInfo[srcSigId].acPduID].astPduInterMonitor->acPduRecSts &= ~COM_PDU_GW_SIG_FLAG;  /* PRQA S 4432, 4532, 4522*/ /* NSCA_QAC_Com_Rule10.3, NSCA_QAC_Com_Rule10.1 */
    }
    else
    {
        /* clear Signal group flag.(COM_PDU_WAITRECEIVE) */
        /* PolySpace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
        RxPduInfo[rxSigGrpInfo[srcSigGrpId].awPduId].astPduInterMonitor->acPduRecSts &= ~COM_PDU_GW_SIG_FLAG;  /* PRQA S 4432, 4532, 4522*/ /* NSCA_QAC_Com_Rule10.3, NSCA_QAC_Com_Rule10.1 */
    }
}

/*
********************************************************************************
* Function Name: Com_GwSig_Process
*
* Explanation: Gateway signal processing
*
* param: gwMappingSigPtr: Gw signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_GwSig_Process
(
    P2CONST(Com_GwMappingSigType, AUTOMATIC, COM_APPL_CONST) gwMappingSigPtr
)
{
    uint16 index = COM_INIT_ZERO;
    uint16 sigIndex = COM_INIT_ZERO;
    uint16 txSigIdxStart = COM_INIT_ZERO;
    uint16 txSigIdxEnd = COM_INIT_ZERO;
    uint16 rxSigIdxStart = COM_INIT_ZERO;
    uint16 rxSigIdxEnd = COM_INIT_ZERO;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    uint16 srcSigId = gwMappingSigPtr->srcSigId;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    uint16 srcSigGrpId = gwMappingSigPtr->srcSigGrpId;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    uint16 destSigOrGrpNum = gwMappingSigPtr->destSigOrGrpNum;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const uint16* destSigIdPtr = gwMappingSigPtr->destSigIdPtr;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const uint16* destSigGrpIdPtr = gwMappingSigPtr->destSigGrpIdPtr;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSignalInfo_st* rxSigInfo = Com_RxSignalInfo;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxSigGrpInfo_st* txSigGrpInfo = Com_TxSigGrpInfo;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxSigGrpInfo_st* rxSigGrpInfo = Com_RxSigGrpInfo;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxPduInfo_st* RxPduInfo = Com_RxPduInfo;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxSignalInfo_st* txSigInfo = Com_TxSignalInfo;
#if( COM_MULTICORE_SUPPORT == STD_ON )
    const COM_TxPduInfo_st* TxPduInfo = Com_TxPduInfo;
#endif  /* COM_MULTICORE_SUPPORT == STD_ON */

    if( COM_GW_NO_SIG_DEF != srcSigId )
    {
        /* Signal process.(COM_PDU_WAITRECEIVE) */
        /* PolySpace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" PolySpace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_Com_10.1" */
        if( COM_PDU_GW_SIG_FLAG == (RxPduInfo[rxSigInfo[srcSigId].acPduID].astPduInterMonitor->acPduRecSts & COM_PDU_GW_SIG_FLAG) )  /* PRQA S 1881, 4522 */ /* NSCA_QAC_Com_Rule10.4, NSCA_QAC_Com_Rule10.1 */
        {
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
            if( COM_SIG_NO_UPDATEBIT_DEF == rxSigInfo[srcSigId].updateBitPosition )
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */
            {
                for( index = COM_INIT_ZERO; index < destSigOrGrpNum; index++ )
                {
#if( COM_MULTICORE_SUPPORT == STD_ON )
                    if(RxPduInfo[rxSigInfo[srcSigId].acPduID].coreId != TxPduInfo[txSigInfo[destSigIdPtr[index]].acPduId].coreId)
                    {
                        if(COM_SIG_NO_GROUP_DEF == rxSigInfo[srcSigId].acSigGrpIdx)
                        {
                            (void)Com_InterCore_Process(destSigIdPtr[index], (const void*)rxSigInfo[srcSigId].sigRTEValue);
                        }
                        else
                        {
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
                            (void)Com_InterCore_Process(destSigIdPtr[index], (const void*)rxSigInfo[srcSigId].sigRTEValue);
#else  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                            (void)Com_InterCore_Process(destSigIdPtr[index], (const void*)rxSigInfo[srcSigId].sigShadowValue);
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                        }
                    }
                    else
                    {
                        if(COM_SIG_NO_GROUP_DEF == rxSigInfo[srcSigId].acSigGrpIdx)
                        {
                            (void)Com_SendSignal_Process(destSigIdPtr[index], (const void*)rxSigInfo[srcSigId].sigRTEValue);
                        }
                        else
                        {
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
                            (void)Com_SendSignal_Process(destSigIdPtr[index], (const void*)rxSigInfo[srcSigId].sigRTEValue);
#else  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                            (void)Com_SendSignal_Process(destSigIdPtr[index], (const void*)rxSigInfo[srcSigId].sigShadowValue);
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                        }
                    }
#else  /* COM_MULTICORE_SUPPORT == STD_ON */
                    /* Single core process */
                    if(COM_SIG_NO_GROUP_DEF == rxSigInfo[srcSigId].acSigGrpIdx)
                    {
                        (void)Com_SendSignal_Process(destSigIdPtr[index], (const void*)rxSigInfo[srcSigId].sigRTEValue);
                    }
                    else
                    {
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
                        (void)Com_SendSignal_Process(destSigIdPtr[index], (const void*)rxSigInfo[srcSigId].sigRTEValue);
#else  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                        (void)Com_SendSignal_Process(destSigIdPtr[index], (const void*)rxSigInfo[srcSigId].sigShadowValue);
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                    }
#endif  /* COM_MULTICORE_SUPPORT == STD_ON */
                    /* Signal groups process. */
                    if(COM_SIG_NO_GROUP_DEF != txSigInfo[destSigIdPtr[index]].acSigGrpIdx)
                    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                    {
#if( COM_TXSIGGROUPINFO ==STD_ON )
                        (void)Com_SendSigGrp_Process(txSigInfo[destSigIdPtr[index]].acSigGrpIdx);
#endif  /* COM_TXSIGGROUPINFO ==STD_ON */
                    }
                }
            }
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
            else
            {
                /* Calculate updateBit for the signal. */
                if( (uint8)TRUE == Com_SigRxReadUb(srcSigId) )
                {
                    for( index = COM_INIT_ZERO; index < destSigOrGrpNum; index++ )
                    {
#if( COM_MULTICORE_SUPPORT == STD_ON )
                        if(RxPduInfo[rxSigInfo[srcSigId].acPduID].coreId != TxPduInfo[txSigInfo[destSigIdPtr[index]].acPduId].coreId)
                        {
                            if(COM_SIG_NO_GROUP_DEF == rxSigInfo[srcSigId].acSigGrpIdx)
                            {
                                (void)Com_InterCore_Process(destSigIdPtr[index], (const void*)rxSigInfo[srcSigId].sigRTEValue);
                            }
                            else
                            {
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
                                (void)Com_InterCore_Process(destSigIdPtr[index], (const void*)rxSigInfo[srcSigId].sigRTEValue);
#else  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                                (void)Com_InterCore_Process(destSigIdPtr[index], (const void*)rxSigInfo[srcSigId].sigShadowValue);
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                            }
                        }
                        else
                        {
                            if(COM_SIG_NO_GROUP_DEF == rxSigInfo[srcSigId].acSigGrpIdx)
                            {
                                (void)Com_SendSignal_Process(destSigIdPtr[index], (const void*)rxSigInfo[srcSigId].sigRTEValue);
                            }
                            else
                            {
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
                                (void)Com_SendSignal_Process(destSigIdPtr[index], (const void*)rxSigInfo[srcSigId].sigRTEValue);
#else  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                                (void)Com_SendSignal_Process(destSigIdPtr[index], (const void*)rxSigInfo[srcSigId].sigShadowValue);
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                            }
                        }
#else
                        /* Single core process */
                        if(COM_SIG_NO_GROUP_DEF == rxSigInfo[srcSigId].acSigGrpIdx)
                        {
                            (void)Com_SendSignal_Process(destSigIdPtr[index], (const void*)rxSigInfo[srcSigId].sigRTEValue);
                        }
                        else
                        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                        {
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
                            (void)Com_SendSignal_Process(destSigIdPtr[index], (const void*)rxSigInfo[srcSigId].sigRTEValue);
#else  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                            (void)Com_SendSignal_Process(destSigIdPtr[index], (const void*)rxSigInfo[srcSigId].sigShadowValue);
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                        }
#endif  /* COM_MULTICORE_SUPPORT == STD_ON */
                        /* Signal groups process. */
                        if(COM_SIG_NO_GROUP_DEF != txSigInfo[destSigIdPtr[index]].acSigGrpIdx)
                        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                        {
#if( COM_TXSIGGROUPINFO ==STD_ON )
                            (void)Com_SendSigGrp_Process(txSigInfo[destSigIdPtr[index]].acSigGrpIdx);
#endif  /* COM_TXSIGGROUPINFO ==STD_ON */
                        }
                    }
                }
            }
            /* Do not clear the COM_PDU_GW_SIG_FLAG here,
               because other signals on this RX PDU may need it for routing. */
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */
        }
    }
    else
    {
        /* Signal group process.(COM_PDU_WAITRECEIVE) */
        /* PolySpace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" PolySpace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_Com_10.1" */
        if( COM_PDU_GW_SIG_FLAG == (RxPduInfo[rxSigGrpInfo[srcSigGrpId].awPduId].astPduInterMonitor->acPduRecSts & COM_PDU_GW_SIG_FLAG) )  /* PRQA S 1881, 4522 */ /* NSCA_QAC_Com_Rule10.4, NSCA_QAC_Com_Rule10.1 */
        {
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
            if( COM_SIG_NO_UPDATEBIT_DEF == rxSigGrpInfo[srcSigGrpId].updateBitPosition )
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */
            {
                rxSigIdxStart = rxSigGrpInfo[srcSigGrpId].acSigIndStart;
                rxSigIdxEnd = rxSigGrpInfo[srcSigGrpId].acSigIndEnd;
                for( index = COM_INIT_ZERO; index < destSigOrGrpNum; index++ )
                {
                    txSigIdxStart = txSigGrpInfo[destSigGrpIdPtr[index]].acSigIdxStart;
                    txSigIdxEnd = txSigGrpInfo[destSigGrpIdPtr[index]].acSigIdxdEnd;
                    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                    if( (txSigIdxEnd - txSigIdxStart) == (rxSigIdxEnd- rxSigIdxStart))
                    {
                        for(sigIndex = COM_INIT_ZERO; sigIndex < (txSigIdxEnd- txSigIdxStart); sigIndex++ )
                        {
#if( COM_MULTICORE_SUPPORT == STD_ON )
                            if(RxPduInfo[rxSigGrpInfo[srcSigGrpId].awPduId].coreId != TxPduInfo[txSigGrpInfo[destSigGrpIdPtr[index]].awPduId].coreId)
                            {
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
                                (void)Com_InterCore_Process((sigIndex + txSigIdxStart),
                                (const void*)rxSigInfo[sigIndex + rxSigIdxStart].sigRTEValue);
#else  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                                (void)Com_InterCore_Process((sigIndex + txSigIdxStart),
                                (const void*)rxSigInfo[sigIndex + rxSigIdxStart].sigShadowValue);
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                            }
                            else
                            {
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
                                (void)Com_SendSignal_Process((sigIndex + txSigIdxStart),
                                (const void*)rxSigInfo[sigIndex + rxSigIdxStart].sigRTEValue);
#else  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                                (void)Com_SendSignal_Process((sigIndex + txSigIdxStart),
                                (const void*)rxSigInfo[sigIndex + rxSigIdxStart].sigShadowValue);
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                            }
#else
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
                            (void)Com_SendSignal_Process((sigIndex + txSigIdxStart),
                                (const void*)rxSigInfo[sigIndex + rxSigIdxStart].sigRTEValue);
#else  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                            (void)Com_SendSignal_Process((sigIndex + txSigIdxStart),
                                (const void*)rxSigInfo[sigIndex + rxSigIdxStart].sigShadowValue);
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
#endif  /*COM_MULTICORE_SUPPORT == STD_ON*/
                        }
 #if( COM_TXSIGGROUPINFO == STD_ON )
                        (void)Com_SendSigGrp_Process(destSigGrpIdPtr[index]);
#endif  /* COM_TXSIGGROUPINFO == STD_ON */
                    }
                }
            }
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
            else
            {
                /* Calculate updateBit for any signal belong to the group. */
                if( (uint8)TRUE == Com_SigRxReadUb(rxSigGrpInfo[srcSigGrpId].acSigIndStart) )
                {
                    rxSigIdxStart = rxSigGrpInfo[srcSigGrpId].acSigIndStart;
                    rxSigIdxEnd = rxSigGrpInfo[srcSigGrpId].acSigIndEnd;
                    for( index = COM_INIT_ZERO; index < destSigOrGrpNum; index++ )
                    {
                        txSigIdxStart = txSigGrpInfo[destSigGrpIdPtr[index]].acSigIdxStart;
                        txSigIdxEnd = txSigGrpInfo[destSigGrpIdPtr[index]].acSigIdxdEnd;
                        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                        if( (txSigIdxEnd - txSigIdxStart) == (rxSigIdxEnd- rxSigIdxStart))
                        {
                            for(sigIndex = COM_INIT_ZERO; sigIndex < (txSigIdxEnd- txSigIdxStart); sigIndex++ )
                            {
#if( COM_MULTICORE_SUPPORT == STD_ON )
                                if(RxPduInfo[rxSigGrpInfo[srcSigGrpId].awPduId].coreId != TxPduInfo[txSigGrpInfo[destSigGrpIdPtr[index]].awPduId].coreId)
                                {
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
                                    (void)Com_InterCore_Process((sigIndex + txSigIdxStart),
                                    (const void*)rxSigInfo[sigIndex + rxSigIdxStart].sigRTEValue);
#else  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                                    (void)Com_InterCore_Process((sigIndex + txSigIdxStart),
                                    (const void*)rxSigInfo[sigIndex + rxSigIdxStart].sigShadowValue);
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                                }
                                else
                                {
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
                                    (void)Com_SendSignal_Process((sigIndex + txSigIdxStart),
                                    (const void*)rxSigInfo[sigIndex + rxSigIdxStart].sigRTEValue);
#else  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                                    (void)Com_SendSignal_Process((sigIndex + txSigIdxStart),
                                    (const void*)rxSigInfo[sigIndex + rxSigIdxStart].sigShadowValue);
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                                }
#else
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
                                (void)Com_SendSignal_Process((sigIndex + txSigIdxStart),
                                        (const void*)rxSigInfo[sigIndex + rxSigIdxStart].sigRTEValue);
#else  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
                                (void)Com_SendSignal_Process((sigIndex + txSigIdxStart),
                                        (const void*)rxSigInfo[sigIndex + rxSigIdxStart].sigShadowValue);
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
#endif  /*COM_MULTICORE_SUPPORT == STD_ON*/
                            }
  #if( COM_TXSIGGROUPINFO == STD_ON )
                            (void)Com_SendSigGrp_Process(destSigGrpIdPtr[index]);
 #endif  /* COM_TXSIGGROUPINFO == STD_ON */
                        }
                    }
                }
            }
            /* Do not clear the COM_PDU_GW_SIG_FLAG here,
               because other signals on this RX PDU may need it for routing. */
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */
        }
    }
}
#endif  /* COM_GWSIGNAL_NUM > COM_INIT_ZERO */

#if( (COM_MULTICORE_SUPPORT == STD_ON) || ((COM_GWSIGNALDSCP_NUM > COM_INIT_ZERO) && (COM_MULTICORE_SUPPORT != STD_ON)) )
/*
********************************************************************************
* Function Name: Com_RxsignalUB_Handle
*
* Explanation: Rx Singal judge update_bit value.
*
* param: sigIdx: Rx Pdu Signal Index.
*
* retval: action: Determine whether the data is updated.
********************************************************************************
*/
static FUNC(boolean, COM_CODE) Com_GwSigRxReadUb
(
    uint16 updateBitPosit,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr
)
{
    boolean action = FALSE;

#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint8 updatevalue;

    /* Configed updatebit. */
    if( COM_SIG_NO_UPDATEBIT_DEF != updateBitPosit )
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
    {
        updatevalue = dataPtr[updateBitPosit / COM_1BYTE_BITLENGTH];
        updatevalue = updatevalue >> (updateBitPosit % COM_1BYTE_BITLENGTH);
        updatevalue = updatevalue & COM_OPERAND_ONE;
        /* Determines whether the value of the update bit is updated. */
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        if( COM_OPERAND_ONE == updatevalue )
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        {
            action = TRUE;
        }
    }
    else  /* Gw sig not config updatebit. */
    {
        action = TRUE;
    }
#else
    {
        action = TRUE;
    }
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON  */
    COM_DUMMY_STATEMENT(updateBitPosit);
    COM_DUMMY_STATEMENT(dataPtr);
    return action;
}
#endif

#if( COM_MULTICORE_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Com_GwSigDscp_InterProcess
*
* Explanation: Gateway signal processing
*
* param: gwMappingSigPtr: Gw signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE)Com_GwSigDscp_InterProcess
(
    P2CONST(Com_GwMappingSigDscpType, AUTOMATIC, COM_APPL_CONST) gwMappingSigDscpPtr
)
{
    boolean sigValChangeFlag = FALSE;
    boolean sigRecvFlag;
    uint16 index;
    uint16 byteIndex;
    uint32 rxSigVal;
    uint64 rxSigVal64;
    Com_SigType sigType;
    const COM_RxPduInfo_st* RxPduInfo = &Com_RxPduInfo[gwMappingSigDscpPtr->srcPduId];
    const COM_TxPduInfo_st* TxPduInfo = Com_TxPduInfo;
    const Com_GwSigDscpDestType* destSigDscpPtr = gwMappingSigDscpPtr->destSigDscpPtr;
    COM_RxSignalInfo_st rxSigInfo;
    COM_TxSignalInfo_st txSigInfo;
    Com_SignalBaseInfo_st tSigBaseInfo_Rx;
    Com_SignalBaseInfo_st tSigBaseInfo_Tx;

    /* COM_PDU_WAITRECEIVE */
    if( COM_PDU_GW_DSCP_FLAG == (RxPduInfo->astPduInterMonitor->acPduRecSts & COM_PDU_GW_DSCP_FLAG) )
    {
        RxPduInfo->astPduInterMonitor->acPduRecSts |= COM_PDU_GW_DSCP_HANDLE_FLAG;
        txSigInfo.sigBaseInfo = &tSigBaseInfo_Tx;
        rxSigInfo.sigBaseInfo = &tSigBaseInfo_Rx;
        rxSigInfo.sigBaseInfo->sigStartBit = gwMappingSigDscpPtr->srcBitPos;          /* Set bit position in byte. */
        rxSigInfo.sigBaseInfo->sigBitLength = gwMappingSigDscpPtr->srcBitSize;        /* Set bit length. */
        rxSigInfo.sigBaseInfo->sigStartByte = gwMappingSigDscpPtr->srcSigStartByte;   /* Set byte position. */
        rxSigInfo.sigBaseInfo->sigByteLength = gwMappingSigDscpPtr->srcSigByteLength; /* Set byte length. */
        rxSigInfo.sigBaseInfo->sigFuncIdx = gwMappingSigDscpPtr->srcSigFuncIdx;       /* Set signal function id. */

        sigType = Com_GetSignalType(gwMappingSigDscpPtr->srcSigFuncIdx);              /* Get signal type */
        sigRecvFlag = Com_GwSigRxReadUb(gwMappingSigDscpPtr->updateBitPosition, RxPduInfo->datavalid);

        if( (boolean)TRUE == sigRecvFlag )
        {
            /* UINT8_N or UINT8_DYN process. */
            if( (COM_SIGTYPE_UINT8_N == sigType) || (COM_SIGTYPE_UINT8_DYN == sigType) )
            {
                for( index = COM_INIT_ZERO; index < gwMappingSigDscpPtr->destSigDscpNum; index++ )
                {
                    if(TxPduInfo[destSigDscpPtr[index].destPduId].coreId == RxPduInfo->coreId)
                    {
                        for( byteIndex = COM_INIT_ZERO; byteIndex < gwMappingSigDscpPtr->sigLength; byteIndex++ )
                        {
                            TxPduInfo[destSigDscpPtr[index].destPduId].dataRaw[byteIndex + destSigDscpPtr[index].destSigStartByte] =
                                RxPduInfo->datavalid[byteIndex + gwMappingSigDscpPtr->srcSigStartByte];
                        }
#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
                        if( COM_SIG_NO_UPDATEBIT_DEF != destSigDscpPtr[index].updateBitPosition )
                        {
                            /* Process updateBit signal. */
                            Com_SigTxSetUb(destSigDscpPtr[index].updateBitPosition, destSigDscpPtr[index].destPduId);
                        }
#endif
                        txSigInfo.acPduId = destSigDscpPtr[index].destPduId;
                        txSigInfo.sigTransferProperty = destSigDscpPtr[index].sigTransferProperty;
                        Com_SendPduStaProcess(&txSigInfo, sigValChangeFlag);

                        /* Set Gw ready to Send Flag. */
                        TxPduInfo[destSigDscpPtr[index].destPduId].astPduInterMonitor->pduGwSendFlag = FALSE;
                    }
                    else
                    {
                        if(E_OK == GetSpinlock(COM_SPINLOCK_ID_GWSP_UINT8))
                        {
                            for( byteIndex = COM_INIT_ZERO; byteIndex < gwMappingSigDscpPtr->sigLength; byteIndex++ )
                            {
                                TxPduInfo[destSigDscpPtr[index].destPduId].dataRaw[byteIndex + destSigDscpPtr[index].destSigStartByte] =
                                    RxPduInfo->datavalid[byteIndex + gwMappingSigDscpPtr->srcSigStartByte];
                            }
#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
                            if( COM_SIG_NO_UPDATEBIT_DEF != destSigDscpPtr[index].updateBitPosition )
                            {
                                /* Process updateBit signal. */
                                Com_SigTxSetUb(destSigDscpPtr[index].updateBitPosition, destSigDscpPtr[index].destPduId);
                            }
#endif
                            txSigInfo.acPduId = destSigDscpPtr[index].destPduId;
                            txSigInfo.sigTransferProperty = destSigDscpPtr[index].sigTransferProperty;
                            Com_SendPduStaProcess(&txSigInfo, sigValChangeFlag);

                            /* Set Gw ready to Send Flag. */
                            TxPduInfo[destSigDscpPtr[index].destPduId].astPduInterMonitor->pduGwSendFlag = FALSE;
                            (void)ReleaseSpinlock(COM_SPINLOCK_ID_GWSP_UINT8);
                        }
                    }
                }
            }
            /* Large type process. */
            else if( (COM_SIGTYPE_UINT64 == sigType) || (COM_SIGTYPE_SINT64 == sigType) || (COM_SIGTYPE_FLOAT64 == sigType) )
            {
                /* Read value from GW source. */
                rxSigVal64 = Com_RxSigRead_Large_64((const uint8*)RxPduInfo->datavalid, &rxSigInfo);
                for( index = COM_INIT_ZERO; index < gwMappingSigDscpPtr->destSigDscpNum; index++ )
                {
                    /* Set value for GW destination. */
                    txSigInfo.sigBaseInfo->sigStartBit = destSigDscpPtr[index].destBitPos;          /* Set bit position in byte. */
                    txSigInfo.sigBaseInfo->sigBitLength = destSigDscpPtr[index].destBitSize;        /* Set bit length. */
                    txSigInfo.sigBaseInfo->sigStartByte = destSigDscpPtr[index].destSigStartByte;   /* Set byte position. */
                    txSigInfo.sigBaseInfo->sigByteLength = destSigDscpPtr[index].destSigByteLength; /* Set byte length. */
                    txSigInfo.sigBaseInfo->sigFuncIdx = destSigDscpPtr[index].destSigFuncIdx;       /* Set signal function id. */
                    txSigInfo.acPduId = destSigDscpPtr[index].destPduId;
                    if(TxPduInfo[destSigDscpPtr[index].destPduId].coreId == RxPduInfo->coreId)
                    {
                        Com_TxSigWrite_Large_64((const COM_TxSignalInfo_st*)&txSigInfo, rxSigVal64);
#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
                        if( COM_SIG_NO_UPDATEBIT_DEF != destSigDscpPtr[index].updateBitPosition )
                        {
                            /* Process updateBit signal. */
                            Com_SigTxSetUb(destSigDscpPtr[index].updateBitPosition, destSigDscpPtr[index].destPduId);
                        }
#endif
                        txSigInfo.sigTransferProperty = destSigDscpPtr[index].sigTransferProperty;
                        Com_SendPduStaProcess(&txSigInfo, sigValChangeFlag);

                        /* Set Gw ready to Send Flag. */
                        TxPduInfo[destSigDscpPtr[index].destPduId].astPduInterMonitor->pduGwSendFlag = FALSE;
                    }
                    else
                    {
                        if(E_OK == GetSpinlock(COM_SPINLOCK_ID_GWSP_LARGETYPE))
                        {
                            Com_TxSigWrite_Large_64((const COM_TxSignalInfo_st*)&txSigInfo, rxSigVal64);
#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
                            if( COM_SIG_NO_UPDATEBIT_DEF != destSigDscpPtr[index].updateBitPosition )
                            {
                                /* Process updateBit signal. */
                                Com_SigTxSetUb(destSigDscpPtr[index].updateBitPosition, destSigDscpPtr[index].destPduId);
                            }
#endif
                            txSigInfo.sigTransferProperty = destSigDscpPtr[index].sigTransferProperty;
                            Com_SendPduStaProcess(&txSigInfo, sigValChangeFlag);

                            /* Set Gw ready to Send Flag. */
                            TxPduInfo[destSigDscpPtr[index].destPduId].astPduInterMonitor->pduGwSendFlag = FALSE;
                            (void)ReleaseSpinlock(COM_SPINLOCK_ID_GWSP_LARGETYPE);
                        }
                    }
                }
            }
            /* Normal type process. */
            else
            {
                /* Read value from GW source. */
                rxSigVal = Com_RxSigRead_Normal(RxPduInfo->datavalid, &rxSigInfo);
                for( index = COM_INIT_ZERO; index < gwMappingSigDscpPtr->destSigDscpNum; index++ )
                {
                    /* Set value for GW destination. */
                    txSigInfo.sigBaseInfo->sigStartBit = destSigDscpPtr[index].destBitPos;          /* Set bit position in byte. */
                    txSigInfo.sigBaseInfo->sigBitLength = destSigDscpPtr[index].destBitSize;        /* Set bit length. */
                    txSigInfo.sigBaseInfo->sigStartByte = destSigDscpPtr[index].destSigStartByte;   /* Set byte position. */
                    txSigInfo.sigBaseInfo->sigByteLength = destSigDscpPtr[index].destSigByteLength; /* Set byte length. */
                    txSigInfo.sigBaseInfo->sigFuncIdx = destSigDscpPtr[index].destSigFuncIdx;       /* Set signal function id. */
                    txSigInfo.acPduId = destSigDscpPtr[index].destPduId;
                    if(TxPduInfo[destSigDscpPtr[index].destPduId].coreId == RxPduInfo->coreId)
                    {
                        Com_TxSigWrite_Normal((const COM_TxSignalInfo_st*)&txSigInfo, rxSigVal);
#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
                        if( COM_SIG_NO_UPDATEBIT_DEF != destSigDscpPtr[index].updateBitPosition )
                        {
                            /* Process updateBit signal. */
                            Com_SigTxSetUb(destSigDscpPtr[index].updateBitPosition, destSigDscpPtr[index].destPduId);
                        }
#endif
                        txSigInfo.sigTransferProperty = destSigDscpPtr[index].sigTransferProperty;
                        Com_SendPduStaProcess(&txSigInfo, sigValChangeFlag);

                        /* Set Gw ready to Send Flag. */
                        TxPduInfo[destSigDscpPtr[index].destPduId].astPduInterMonitor->pduGwSendFlag = FALSE;
                    }
                    else
                    {
                        if(E_OK == GetSpinlock(COM_SPINLOCK_ID_GWSP_NORMALTYPE))
                        {
                            Com_TxSigWrite_Normal((const COM_TxSignalInfo_st*)&txSigInfo, rxSigVal);
#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
                            if( COM_SIG_NO_UPDATEBIT_DEF != destSigDscpPtr[index].updateBitPosition )
                            {
                                /* Process updateBit signal. */
                                Com_SigTxSetUb(destSigDscpPtr[index].updateBitPosition, destSigDscpPtr[index].destPduId);
                            }
#endif
                            txSigInfo.sigTransferProperty = destSigDscpPtr[index].sigTransferProperty;
                            Com_SendPduStaProcess(&txSigInfo, sigValChangeFlag);

                            /* Set Gw ready to Send Flag. */
                            TxPduInfo[destSigDscpPtr[index].destPduId].astPduInterMonitor->pduGwSendFlag = FALSE;
                            (void)ReleaseSpinlock(COM_SPINLOCK_ID_GWSP_NORMALTYPE);
                        }
                    }
                }
            }
        }
        /* Do not clear the COM_PDU_GW_DSCP_FLAG here,
           because other signals on this RX PDU may need it for routing. */
    }
}
#elif( (COM_GWSIGNALDSCP_NUM > COM_INIT_ZERO) && (COM_MULTICORE_SUPPORT != STD_ON) )
/*
********************************************************************************
* Function Name: Com_GwSigDscp_Process
*
* Explanation: Gateway signal processing
*
* param: gwMappingSigPtr: Gw signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE)Com_GwSigDscp_Process
(
    P2CONST(Com_GwMappingSigDscpType, AUTOMATIC, COM_APPL_CONST) gwMappingSigDscpPtr
)
{
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    boolean sigValChangeFlag = FALSE;
    boolean sigRecvFlag;
    uint16 index;
    uint16 byteIndex;
    uint32 rxSigVal;
    uint64 rxSigVal64;
    Com_SigType sigType;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxPduInfo_st* RxPduInfo = &Com_RxPduInfo[gwMappingSigDscpPtr->srcPduId];
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxPduInfo_st* TxPduInfo = Com_TxPduInfo;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const Com_GwSigDscpDestType* destSigDscpPtr = gwMappingSigDscpPtr->destSigDscpPtr;
    COM_RxSignalInfo_st rxSigInfo;
    COM_TxSignalInfo_st txSigInfo;
    Com_SignalBaseInfo_st tSigBaseInfo_Rx;
    Com_SignalBaseInfo_st tSigBaseInfo_Tx;

    /* COM_PDU_WAITRECEIVE */
    /* PolySpace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" PolySpace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_Com_10.1" */
    if( COM_PDU_GW_DSCP_FLAG == (RxPduInfo->astPduInterMonitor->acPduRecSts & COM_PDU_GW_DSCP_FLAG) )  /* PRQA S 1881, 4522 */ /* NSCA_QAC_Com_Rule10.4, NSCA_QAC_Com_Rule10.1 */
    {
        /* PolySpace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
        RxPduInfo->astPduInterMonitor->acPduRecSts |= COM_PDU_GW_DSCP_HANDLE_FLAG;  /* PRQA S 4432, 4522, 4522*/ /* NSCA_QAC_Com_Rule10.3, NSCA_QAC_Com_Rule10.1 */
        txSigInfo.sigBaseInfo = &tSigBaseInfo_Tx;
        rxSigInfo.sigBaseInfo = &tSigBaseInfo_Rx;
        rxSigInfo.sigBaseInfo->sigStartBit = gwMappingSigDscpPtr->srcBitPos;          /* Set bit position. */
        rxSigInfo.sigBaseInfo->sigBitLength = gwMappingSigDscpPtr->srcBitSize;        /* Set bit length. */
        rxSigInfo.sigBaseInfo->sigStartByte = gwMappingSigDscpPtr->srcSigStartByte;   /* Set byte position. */
        rxSigInfo.sigBaseInfo->sigByteLength = gwMappingSigDscpPtr->srcSigByteLength; /* Set byte length. */
        rxSigInfo.sigBaseInfo->sigFuncIdx = gwMappingSigDscpPtr->srcSigFuncIdx;       /* Set signal function id. */

        sigType = Com_GetSignalType(gwMappingSigDscpPtr->srcSigFuncIdx);              /* Get signal type */
        sigRecvFlag = Com_GwSigRxReadUb(gwMappingSigDscpPtr->updateBitPosition, RxPduInfo->datavalid);

        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
        if( (boolean)TRUE == sigRecvFlag )
        {
            /* UINT8_N or UINT8_DYN process. */
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            if( (COM_SIGTYPE_UINT8_N == sigType) || (COM_SIGTYPE_UINT8_DYN == sigType) )
            {
                for( index = COM_INIT_ZERO; index < gwMappingSigDscpPtr->destSigDscpNum; index++ )
                {
                    /* Polyspace +1 RTE:NTL [Justified:Unset] " NSCA_Polyspace_Com_NTL " */
                    for( byteIndex = COM_INIT_ZERO; byteIndex < gwMappingSigDscpPtr->sigLength; byteIndex++ )
                    {
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        TxPduInfo[destSigDscpPtr[index].destPduId].dataRaw[byteIndex + destSigDscpPtr[index].destSigStartByte] =
                            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                            RxPduInfo->datavalid[byteIndex + gwMappingSigDscpPtr->srcSigStartByte];
                    }
#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
                    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                    if( COM_SIG_NO_UPDATEBIT_DEF != destSigDscpPtr[index].updateBitPosition )
                    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                    {
                        /* Process updateBit signal. */
                        Com_SigTxSetUb(destSigDscpPtr[index].updateBitPosition, destSigDscpPtr[index].destPduId);
                    }
#endif
                    txSigInfo.acPduId = destSigDscpPtr[index].destPduId;
                    txSigInfo.sigTransferProperty = destSigDscpPtr[index].sigTransferProperty;
                    Com_SendPduStaProcess(&txSigInfo, sigValChangeFlag);

                    /* Set Gw ready to Send Flag. */
                    TxPduInfo[destSigDscpPtr[index].destPduId].astPduInterMonitor->pduGwSendFlag = FALSE;
                }
            }
            /* Large type process. */
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            else if( (COM_SIGTYPE_UINT64 == sigType) || (COM_SIGTYPE_SINT64 == sigType) || (COM_SIGTYPE_FLOAT64 == sigType) )
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                /* Read value from GW source. */
                rxSigVal64 = Com_RxSigRead_Large_64((const uint8*)RxPduInfo->datavalid, &rxSigInfo);
                for( index = COM_INIT_ZERO; index < gwMappingSigDscpPtr->destSigDscpNum; index++ )
                /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                {
                    /* Set value for GW destination. */
                    txSigInfo.sigBaseInfo->sigStartBit = destSigDscpPtr[index].destBitPos;          /* Set bit position in byte. */
                    txSigInfo.sigBaseInfo->sigBitLength = destSigDscpPtr[index].destBitSize;        /* Set bit length. */
                    txSigInfo.sigBaseInfo->sigStartByte = destSigDscpPtr[index].destSigStartByte;   /* Set byte position. */
                    txSigInfo.sigBaseInfo->sigByteLength = destSigDscpPtr[index].destSigByteLength; /* Set byte length. */
                    txSigInfo.sigBaseInfo->sigFuncIdx = destSigDscpPtr[index].destSigFuncIdx;       /* Set signal function id. */
                    txSigInfo.acPduId = destSigDscpPtr[index].destPduId;
                    Com_TxSigWrite_Large_64((const COM_TxSignalInfo_st*)&txSigInfo, rxSigVal64);
#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
                    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                    if( COM_SIG_NO_UPDATEBIT_DEF != destSigDscpPtr[index].updateBitPosition )
                    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                    {
                        /* Process updateBit signal. */
                        Com_SigTxSetUb(destSigDscpPtr[index].updateBitPosition, destSigDscpPtr[index].destPduId);
                    }
#endif
                    txSigInfo.sigTransferProperty = destSigDscpPtr[index].sigTransferProperty;
                    Com_SendPduStaProcess(&txSigInfo, sigValChangeFlag);

                    /* Set Gw ready to Send Flag. */
                    TxPduInfo[destSigDscpPtr[index].destPduId].astPduInterMonitor->pduGwSendFlag = FALSE;
                }
            }
            /* Normal type process. */
            else
            /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
            {
                /* Read value from GW source. */
                rxSigVal = Com_RxSigRead_Normal(RxPduInfo->datavalid, &rxSigInfo);
                for( index = COM_INIT_ZERO; index < gwMappingSigDscpPtr->destSigDscpNum; index++ )
                /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                {
                    /* Set value for GW destination. */
                    txSigInfo.sigBaseInfo->sigStartBit = destSigDscpPtr[index].destBitPos;          /* Set bit position in byte. */
                    txSigInfo.sigBaseInfo->sigBitLength = destSigDscpPtr[index].destBitSize;        /* Set bit length. */
                    txSigInfo.sigBaseInfo->sigStartByte = destSigDscpPtr[index].destSigStartByte;   /* Set byte position. */
                    txSigInfo.sigBaseInfo->sigByteLength = destSigDscpPtr[index].destSigByteLength; /* Set byte length. */
                    txSigInfo.sigBaseInfo->sigFuncIdx = destSigDscpPtr[index].destSigFuncIdx;       /* Set signal function id. */
                    txSigInfo.acPduId = destSigDscpPtr[index].destPduId;
                    Com_TxSigWrite_Normal((const COM_TxSignalInfo_st*)&txSigInfo, rxSigVal);
#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
                    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                    if( COM_SIG_NO_UPDATEBIT_DEF != destSigDscpPtr[index].updateBitPosition )
                    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Com_UNR " */
                    {
                        /* Process updateBit signal. */
                        Com_SigTxSetUb(destSigDscpPtr[index].updateBitPosition, destSigDscpPtr[index].destPduId);
                    }
#endif
                    txSigInfo.sigTransferProperty = destSigDscpPtr[index].sigTransferProperty;
                    Com_SendPduStaProcess(&txSigInfo, sigValChangeFlag);

                    /* Set Gw ready to Send Flag. */
                    TxPduInfo[destSigDscpPtr[index].destPduId].astPduInterMonitor->pduGwSendFlag = FALSE;
                }
            }
        }
        /* Do not clear the COM_PDU_GW_DSCP_FLAG here,
           because other signals on this RX PDU may need it for routing. */
    }
}
#endif  /* COM_MULTICORE_SUPPORT == STD_ON */

#if( (COM_GWSIGNAL_NUM > COM_INIT_ZERO) && (COM_GWONLYTXMODETRUE != STD_ON) )
/*
********************************************************************************
* Function Name: Com_GwStopCycleDest
*
* Explanation: Gateway Tx processing
*
* param: gwMappingSigPtr: Gw signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_GwRefStopCycleDest
(
    P2CONST(Com_GwMappingSigType, AUTOMATIC, COM_APPL_CONST) gwMappingSigPtr
)
{
    uint16 index = COM_INIT_ZERO;
    uint16 srcSigId = gwMappingSigPtr->srcSigId;
    uint16 srcSigGrpId = gwMappingSigPtr->srcSigGrpId;
    uint16 destSigOrGrpNum = gwMappingSigPtr->destSigOrGrpNum;
    const uint16* destSigIdPtr = gwMappingSigPtr->destSigIdPtr;
    const uint16* destSigGrpIdPtr = gwMappingSigPtr->destSigGrpIdPtr;
    const COM_RxSignalInfo_st* rxSigInfo = Com_RxSignalInfo;
    const COM_TxSignalInfo_st* txSigInfo = Com_TxSignalInfo;
    const COM_TxSigGrpInfo_st* txSigGrpInfo = Com_TxSigGrpInfo;
    const COM_RxSigGrpInfo_st* rxSigGrpInfo = Com_RxSigGrpInfo;
    const COM_RxPduInfo_st* rxPduInfo = Com_RxPduInfo;
    const COM_TxPduInfo_st* txPduInfo = Com_TxPduInfo;


    if( COM_GW_NO_SIG_DEF != srcSigId )
    {
        /* Signal process. */
        if( TRUE == rxPduInfo[rxSigInfo[srcSigId].acPduID].astPduInterMonitor->rxTimeout )
        {
            for( index = COM_INIT_ZERO; index < destSigOrGrpNum; index++ )
            {
                if( TRUE == txPduInfo[txSigInfo[destSigIdPtr[index]].acPduId].astPduInterMonitor->pduGwSendFlag )
                {
                    txPduInfo[txSigInfo[destSigIdPtr[index]].acPduId].astPduInterMonitor->pduTxMode = FALSE;
                }
            }
        }
        else
        {
            for( index = COM_INIT_ZERO; index < destSigOrGrpNum; index++ )
            {
                txPduInfo[txSigInfo[destSigIdPtr[index]].acPduId].astPduInterMonitor->pduTxMode = TRUE;
            }
        }
    }
    else
    {
        /* Signal group process. */
        if( TRUE == rxPduInfo[rxSigGrpInfo[srcSigGrpId].awPduId].astPduInterMonitor->rxTimeout )
        {
            for( index = COM_INIT_ZERO; index < destSigOrGrpNum; index++ )
            {
                if( TRUE == txPduInfo[txSigGrpInfo[destSigGrpIdPtr[index]].awPduId].astPduInterMonitor->pduGwSendFlag )
                {
                    txPduInfo[txSigGrpInfo[destSigGrpIdPtr[index]].awPduId].astPduInterMonitor->pduTxMode = FALSE;
                }
            }
        }
        else
        {
            for( index = COM_INIT_ZERO; index < destSigOrGrpNum; index++ )
            {
                txPduInfo[txSigGrpInfo[destSigGrpIdPtr[index]].awPduId].astPduInterMonitor->pduTxMode = TRUE;
            }
        }
    }
}
#endif  /*(COM_GWSIGNAL_NUM > COM_INIT_ZERO) && (COM_GWONLYTXMODETRUE != STD_ON) */

#if( COM_GWSIGNALDSCP_NUM > COM_INIT_ZERO )
/*
********************************************************************************
* Function Name: Com_GwSigDscp_ClearRecvFlag
*
* Explanation: Clear the received GwSigDscp flag of the related RxPdu.
*
* param: gwMappingSigDscpPtr: Gw signal Dscp info pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE)Com_GwSigDscp_ClearRecvFlag
(
    P2CONST(Com_GwMappingSigDscpType, AUTOMATIC, COM_APPL_CONST) gwMappingSigDscpPtr
)
{
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxPduInfo_st* RxPduInfo = &Com_RxPduInfo[gwMappingSigDscpPtr->srcPduId];

    /* Check whether the Pdu is processed. */
    /* PolySpace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" PolySpace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_Com_10.1" */
    if( COM_PDU_GW_DSCP_HANDLE_FLAG == (RxPduInfo->astPduInterMonitor->acPduRecSts & COM_PDU_GW_DSCP_HANDLE_FLAG) )  /* PRQA S 1881, 4522 */ /* NSCA_QAC_Com_Rule10.4, NSCA_QAC_Com_Rule10.1 */
    {
        /* Clear the received GwSigDscp flag of the related RxPdu. */
        /* PolySpace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
        RxPduInfo->astPduInterMonitor->acPduRecSts &= ~COM_PDU_GW_DSCP_FLAG;  /* PRQA S 4432, 4532, 4522*/ /* NSCA_QAC_Com_Rule10.3, NSCA_QAC_Com_Rule10.1 */
        /* PolySpace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
        RxPduInfo->astPduInterMonitor->acPduRecSts &= ~COM_PDU_GW_DSCP_HANDLE_FLAG;  /* PRQA S 4432, 4532, 4522*/ /* NSCA_QAC_Com_Rule10.3, NSCA_QAC_Com_Rule10.1 */
    }
}

/*
********************************************************************************
* Function Name: Com_GwStopCycleDest
*
* Explanation: Gateway Tx processing
*
* param: gwMappingSigPtr: Gw signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_GwDscpStopCycleDest
(
    P2CONST(Com_GwMappingSigDscpType, AUTOMATIC, COM_APPL_CONST) gwMappingSigDscpPtr
)
{
    uint16 index;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_RxPduInfo_st* RxPduInfo = &Com_RxPduInfo[gwMappingSigDscpPtr->srcPduId];
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const COM_TxPduInfo_st* TxPduInfo = Com_TxPduInfo;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const Com_GwSigDscpDestType* destSigDscpPtr = gwMappingSigDscpPtr->destSigDscpPtr;

    if( TRUE == RxPduInfo->astPduInterMonitor->rxTimeout )
    {
        for( index = COM_INIT_ZERO; index < gwMappingSigDscpPtr->destSigDscpNum; index++ )
        {
            if( TRUE == TxPduInfo[destSigDscpPtr[index].destPduId].astPduInterMonitor->pduGwSendFlag )
            {
                TxPduInfo[destSigDscpPtr[index].destPduId].astPduInterMonitor->pduTxMode = FALSE;
            }
        }
    }
    else
    {
        for( index = COM_INIT_ZERO; index < gwMappingSigDscpPtr->destSigDscpNum; index++ )
        {
            TxPduInfo[destSigDscpPtr[index].destPduId].astPduInterMonitor->pduTxMode = TRUE;
        }
    }
}
#endif  /* COM_GWSIGNALDSCP_NUM > COM_INIT_ZERO */

#if( COM_GWSIGNAL_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Com_GwInfoInit
*
* Explanation: Gw Init.
*
* param: void
*
* retval: void
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_GwInfoInit( void )
{
    uint16 mapIdx = COM_INIT_ZERO;
    uint16 index = COM_INIT_ZERO;

#if( COM_GWSIGNALDSCP_NUM > COM_INIT_ZERO )
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Com_UNMODIFIED_VAR_NOT_CONST" */
    const Com_GwMappingSigDscpType* gwDscpInfo = Com_GwDscpInfo;
#endif

    COM_DUMMY_STATEMENT(mapIdx);
    COM_DUMMY_STATEMENT(index);
#if( COM_GWSIGNALDSCP_NUM > COM_INIT_ZERO )
    /* Process all Gw Dscp Pdu. */
    for( mapIdx = COM_INIT_ZERO; mapIdx < COM_GWSIGNALDSCP_NUM; mapIdx++ )
    {
        Com_RxPduInfo[gwDscpInfo[mapIdx].srcPduId].astPduInterMonitor->acPduCycCounterForGwInit = gwDscpInfo[mapIdx].srcTimeOut;
        Com_RxPduInfo[gwDscpInfo[mapIdx].srcPduId].astPduInterMonitor->rxTimeout = TRUE;
        for( index = COM_INIT_ZERO; index < gwDscpInfo[mapIdx].destSigDscpNum; index++ )
        {
            Com_TxPduInfo[gwDscpInfo[mapIdx].destSigDscpPtr[index].destPduId].astPduInterMonitor->pduTxMode = FALSE;
            Com_TxPduInfo[gwDscpInfo[mapIdx].destSigDscpPtr[index].destPduId].astPduInterMonitor->pduGwFlag = TRUE;
        }
    }
#endif  /* COM_GWSIGNALDSCP_NUM > COM_INIT_ZERO */
}
#endif  /* COM_GWSIGNAL_SUPPORT == STD_ON */

#if( (COM_RXREPLACESIGOFRXTIMEOUTINFO == STD_ON) || (COM_RXUPDATEBITCFG_SUPPORT == STD_ON) )
/*
********************************************************************************
* Function Name: Com_RxSigTimeout_Replace_ToValue
*
* Explanation: Rx signal time out replace value.
*
* param: rxSigInfo: RxSignal info.
*
* retval: void
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigTimeout_Replace_ToValue
(
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfo
)
{
    uint16 sigAryTypeLen = COM_INIT_ZERO;
    uint16 byteIdx = COM_INIT_ZERO;
    
    /* Judge signal type. */
    /* PolySpace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_Com_16.1" */
    switch( Com_GetSignalType(rxSigInfo->sigBaseInfo->sigFuncIdx) )
    {
        case COM_SIGTYPE_BOOLEAN:
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            (*((boolean*)rxSigInfo->sigRTEValue)) = (*((boolean*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_UINT8:
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            (*((uint8*)rxSigInfo->sigRTEValue)) = (*((uint8*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_UINT16:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            (*((uint16*)rxSigInfo->sigRTEValue)) = (*((uint16*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_UINT32:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            (*((uint32*)rxSigInfo->sigRTEValue)) = (*((uint32*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_UINT64:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            (*((uint64*)rxSigInfo->sigRTEValue)) = (*((uint64*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_SINT8:
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            (*((sint8*)rxSigInfo->sigRTEValue)) = (*((sint8*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_SINT16:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            (*((sint16*)rxSigInfo->sigRTEValue)) = (*((sint16*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_SINT32:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            (*((sint32*)rxSigInfo->sigRTEValue)) = (*((sint32*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_SINT64:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            (*((sint64*)rxSigInfo->sigRTEValue)) = (*((sint64*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_UINT8_DYN:
            sigAryTypeLen = rxSigInfo->astSignalInterMonitor->acDynSignalLength;
            /* For ComSignalType UINT8_DYN it specifies the maximum length in bytes. */
            if( sigAryTypeLen > rxSigInfo->sigBaseInfo->sigByteLength )
            {
                /* Set byte length of UINT8_DYN signal. */
                sigAryTypeLen = rxSigInfo->sigBaseInfo->sigByteLength;
            }
            for( byteIdx = COM_INIT_ZERO; byteIdx < sigAryTypeLen; byteIdx++ )
            {
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                ((uint8*)(rxSigInfo->sigRTEValue))[byteIdx]
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        = ((uint8*)(rxSigInfo->rxToReplaceValue))[byteIdx];
            }
            break;
        case COM_SIGTYPE_UINT8_N:
            /* Get byte length of UINT8_N signal. */
            sigAryTypeLen = rxSigInfo->sigBaseInfo->sigByteLength;
            for( byteIdx = COM_INIT_ZERO; byteIdx < sigAryTypeLen; byteIdx++ )
            {
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                ((uint8*)(rxSigInfo->sigRTEValue))[byteIdx]
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                        = ((uint8*)(rxSigInfo->rxToReplaceValue))[byteIdx];
            }
            break;
        case COM_SIGTYPE_FLOAT32:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            (*((float32*)rxSigInfo->sigRTEValue)) = (*((float32*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_FLOAT64:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            (*((float64*)rxSigInfo->sigRTEValue)) = (*((float64*)rxSigInfo->rxToReplaceValue));
            break;
        /* PolySpace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_Com_16.4" */
        default :
                break;
    }
}
#endif  /* (COM_RXREPLACESIGOFRXTIMEOUTINFO == STD_ON) || (COM_RXUPDATEBITCFG_SUPPORT == STD_ON) */

#if( COM_RXSIGGROUPINFO == STD_ON )
#if( (COM_RXREPLACESIGGROUPOFRXTIMEOUTINFO == STD_ON) || (COM_RXUPDATEBITCFG_SUPPORT == STD_ON) )
/*
********************************************************************************
* Function Name: Com_RxSigGrpTimeout_Replace_ToValue
*
* Explanation: Rx signal group time out replace value.
*
* param: rxSigInfo: RxSignal info.
*
* retval: void
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxSigGrpTimeout_Replace_ToValue
(
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigInfo
)
{
    uint16 sigAryTypeLen = COM_INIT_ZERO;
    uint16 byteIdx = COM_INIT_ZERO;
    
    /* Judge signal type. */
    /* PolySpace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_Com_16.1" */
    switch( Com_GetSignalType(rxSigInfo->sigBaseInfo->sigFuncIdx) )
    {
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
        case COM_SIGTYPE_BOOLEAN:
            (*((boolean*)rxSigInfo->sigRTEValue)) = (*((boolean*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_UINT8:
            (*((uint8*)rxSigInfo->sigRTEValue)) = (*((uint8*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_UINT16:
            (*((uint16*)rxSigInfo->sigRTEValue)) = (*((uint16*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_UINT32:
            (*((uint32*)rxSigInfo->sigRTEValue)) = (*((uint32*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_UINT64:
            (*((uint64*)rxSigInfo->sigRTEValue)) = (*((uint64*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_SINT8:
            (*((sint8*)rxSigInfo->sigRTEValue)) = (*((sint8*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_SINT16:
            (*((sint16*)rxSigInfo->sigRTEValue)) = (*((sint16*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_SINT32:
            (*((sint32*)rxSigInfo->sigRTEValue)) = (*((sint32*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_SINT64:
            (*((sint64*)rxSigInfo->sigRTEValue)) = (*((sint64*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_UINT8_DYN:
            sigAryTypeLen = rxSigInfo->astSignalInterMonitor->acDynSignalLength;
            /* For ComSignalType UINT8_DYN it specifies the maximum length in bytes. */
            if( sigAryTypeLen > rxSigInfo->sigBaseInfo->sigByteLength )
            {
                /* Set byte length of UINT8_DYN signal. */
                sigAryTypeLen = rxSigInfo->sigBaseInfo->sigByteLength;
            }
            for( byteIdx = COM_INIT_ZERO; byteIdx < sigAryTypeLen; byteIdx++ )
            {
                ((uint8*)(rxSigInfo->sigRTEValue))[byteIdx]
                    = ((uint8*)(rxSigInfo->rxToReplaceValue))[byteIdx];
            }
            break;
        case COM_SIGTYPE_UINT8_N:
            /* Get byte length of UINT8_N signal. */
            sigAryTypeLen = rxSigInfo->sigBaseInfo->sigByteLength;
            for( byteIdx = COM_INIT_ZERO; byteIdx < sigAryTypeLen; byteIdx++ )
            {
                ((uint8*)(rxSigInfo->sigRTEValue))[byteIdx]
                    = ((uint8*)(rxSigInfo->rxToReplaceValue))[byteIdx];
            }
            break;
        case COM_SIGTYPE_FLOAT32:
            (*((float32*)rxSigInfo->sigRTEValue)) = (*((float32*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_FLOAT64:
            (*((float64*)rxSigInfo->sigRTEValue)) = (*((float64*)rxSigInfo->rxToReplaceValue));
            break;
#else  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
        case COM_SIGTYPE_BOOLEAN:
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            (*((boolean*)rxSigInfo->sigShadowValue)) = (*((boolean*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_UINT8:
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            (*((uint8*)rxSigInfo->sigShadowValue)) = (*((uint8*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_UINT16:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            (*((uint16*)rxSigInfo->sigShadowValue)) = (*((uint16*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_UINT32:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            (*((uint32*)rxSigInfo->sigShadowValue)) = (*((uint32*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_UINT64:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            (*((uint64*)rxSigInfo->sigShadowValue)) = (*((uint64*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_SINT8:
            /* PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
            (*((sint8*)rxSigInfo->sigShadowValue)) = (*((sint8*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_SINT16:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            (*((sint16*)rxSigInfo->sigShadowValue)) = (*((sint16*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_SINT32:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            (*((sint32*)rxSigInfo->sigShadowValue)) = (*((sint32*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_SINT64:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            (*((sint64*)rxSigInfo->sigShadowValue)) = (*((sint64*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_UINT8_DYN:
            sigAryTypeLen = rxSigInfo->astSignalInterMonitor->acDynSignalLength;
            /* For ComSignalType UINT8_DYN it specifies the maximum length in bytes. */
            if( sigAryTypeLen > rxSigInfo->sigBaseInfo->sigByteLength )
            {
                /* Set byte length of UINT8_DYN signal. */
                sigAryTypeLen = rxSigInfo->sigBaseInfo->sigByteLength;
            }
            for( byteIdx = COM_INIT_ZERO; byteIdx < sigAryTypeLen; byteIdx++ )
            {
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                ((uint8*)(rxSigInfo->sigShadowValue))[byteIdx]
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    = ((uint8*)(rxSigInfo->rxToReplaceValue))[byteIdx];
            }
            break;
        case COM_SIGTYPE_UINT8_N:
            /* Get byte length of UINT8_N signal. */
            sigAryTypeLen = rxSigInfo->sigBaseInfo->sigByteLength;
            for( byteIdx = COM_INIT_ZERO; byteIdx < sigAryTypeLen; byteIdx++ )
            {
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                ((uint8*)(rxSigInfo->sigShadowValue))[byteIdx]
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
                    = ((uint8*)(rxSigInfo->rxToReplaceValue))[byteIdx];
            }
            break;
        case COM_SIGTYPE_FLOAT32:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            (*((float32*)rxSigInfo->sigShadowValue)) = (*((float32*)rxSigInfo->rxToReplaceValue));
            break;
        case COM_SIGTYPE_FLOAT64:
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Com_IDP" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Com_18.1" */
            (*((float64*)rxSigInfo->sigShadowValue)) = (*((float64*)rxSigInfo->rxToReplaceValue));
            break;
#endif  /* COM_RXWITHOUTSHADOWVALUE == STD_ON */
        /* PolySpace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_Com_16.4" */
        default :
            break;
    }
}
#endif  /* (COM_RXREPLACESIGGROUPOFRXTIMEOUTINFO == STD_ON) || (COM_RXUPDATEBITCFG_SUPPORT) */
#endif  /* COM_RXSIGGROUPINFO == STD_ON */

/*
********************************************************************************
* Function Name: Com_CompareFloat32Values
*
* Explanation: Compare the values of two numbers.
*
* param: firstValue: float32 value.
*        scndValue: float32 value.
*
* retval: TRUE:Equal
*         FALSE:Not equal
********************************************************************************
*/
static FUNC(boolean, COM_CODE) Com_CompareFloat32Values
(
    float32 firstValue,
    float32 scndValue
)
{
    boolean retVal = FALSE;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.5" */
    float32 value;
    /* Determine whether two variables are both positive or both negative. */
    /* PolySpace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
    if( ((COM_INIT_ZERO < firstValue) && (COM_INIT_ZERO < scndValue)) ||
        /* PolySpace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
        ((COM_INIT_ZERO > firstValue) && (COM_INIT_ZERO < scndValue)) ||
        (((COM_FLT_EPSILON_NEGATIVE <= firstValue) && (COM_FLT_EPSILON >= firstValue)) &&
        ((COM_FLT_EPSILON_NEGATIVE <= scndValue) && (COM_FLT_EPSILON >= scndValue))) )
    {
        if( firstValue < scndValue )
        {
            /* Polyspace +1 RTE:OVFL [Justified:Unset] "NSCA_Polyspace_Com_OVFL" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.1" */
            value = scndValue - firstValue;
        }
        else
        {
            value = firstValue - scndValue;
        }
        if( COM_FLT_EPSILON > value )
        {
            retVal = TRUE;
        }
    }
    else
    {
        /* Do Nothing. */
    }
    return retVal;
}

/*
********************************************************************************
* Function Name: Com_CompareFloat64Values
*
* Explanation: Compare the values of two numbers.
*
* param: firstValue: float64 value.
*        scndValue: float64 value.
*
* retval: TRUE:Equal
*         FALSE:Not equal
********************************************************************************
*/
static FUNC(boolean, COM_CODE) Com_CompareFloat64Values
(
    float64 firstValue,
    float64 scndValue
)
{
    boolean retVal = FALSE;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.5" */
    float64 value;
    /* Determine whether two variables are both positive or both negative. */
    /* PolySpace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
    if( (((COM_INIT_ZERO < firstValue) && (COM_INIT_ZERO < scndValue)) ||
    /* PolySpace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
        ((COM_INIT_ZERO > firstValue) && (COM_INIT_ZERO > scndValue))) ||
        (((COM_DBL_EPSILON_NEGATIVE <= firstValue) && (COM_DBL_EPSILON >= firstValue)) &&
        ((COM_DBL_EPSILON_NEGATIVE <= scndValue) && (COM_DBL_EPSILON >= scndValue))) )
    {
        if( firstValue < scndValue )
        {
            value = scndValue - firstValue;
        }
        else
        {
            value = firstValue - scndValue;
        }
        if( COM_DBL_EPSILON > value )
        {
            retVal = TRUE;
        }
    }
    else
    {
        /* Do Nothing. */
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: Com_GetSignalEndianess
*
* Explanation: Get singnal endianess.
*
* param: sigFuncIdx: Signal function id of signal table.
*
* retval: Singnal endianess.
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Com_SigEndianessType, COM_CODE) Com_GetSignalEndianess(Com_SigFuncIdType sigFuncIdx)  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    Com_SigEndianessType sigEndianess;
    if( COM_BIG_ENDIAN_FUNCID_MAX > sigFuncIdx ) /* Big endian. */
    {
        sigEndianess = COM_BIG_ENDIAN;
    }
    else if( COM_LITTLE_ENDIAN_FUNCID_MAX > sigFuncIdx ) /* Little endian. */
    {
        sigEndianess = COM_LITTLE_ENDIAN;
    }
    else /* Opaque */
    {
        sigEndianess = COM_OPAQUE;
    }

    return sigEndianess;
}

/*
********************************************************************************
* Function Name: Com_GetSignalType
*
* Explanation: Get singnal type.
*
* param: sigFuncIdx: Signal function id of signal table.
*
* retval: Singnal type.
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Com_SigType, COM_CODE) Com_GetSignalType(Com_SigFuncIdType sigFuncIdx)  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    Com_SigType sigType;
    if( COM_BOOLEAN_FUNCID == sigFuncIdx )
    {
        sigType = COM_SIGTYPE_BOOLEAN; /* Bool type. */
    }
    else if( ((COM_BIG_ENDIAN_UINT8_START_FUNCID <= sigFuncIdx) && (COM_BIG_ENDIAN_UINT8_END_FUNCID >= sigFuncIdx))
             || ((COM_LITTLE_ENDIAN_UINT8_START_FUNCID <= sigFuncIdx) && (COM_LITTLE_ENDIAN_UINT8_END_FUNCID >= sigFuncIdx)) )
    {
        sigType = COM_SIGTYPE_UINT8; /* Uint8 type. */
    }
    else if( ((COM_BIG_ENDIAN_UINT16_START_FUNCID <= sigFuncIdx) && (COM_BIG_ENDIAN_UINT16_END_FUNCID >= sigFuncIdx))
             || ((COM_LITTLE_ENDIAN_UINT16_START_FUNCID <= sigFuncIdx) && (COM_LITTLE_ENDIAN_UINT16_END_FUNCID >= sigFuncIdx)) )
    {
        sigType = COM_SIGTYPE_UINT16; /* Uint16 type. */
    }
    else if( ((COM_BIG_ENDIAN_UINT32_START_FUNCID <= sigFuncIdx) && (COM_BIG_ENDIAN_UINT32_END_FUNCID >= sigFuncIdx))
             || ((COM_LITTLE_ENDIAN_UINT32_START_FUNCID <= sigFuncIdx) && (COM_LITTLE_ENDIAN_UINT32_END_FUNCID >= sigFuncIdx)) )
    {
        sigType = COM_SIGTYPE_UINT32; /* Uint32 type. */
    }
    else if( (COM_BIG_ENDIAN_UINT64_FUNCID == sigFuncIdx) || (COM_LITTLE_ENDIAN_UINT64_FUNCID == sigFuncIdx) )
    {
        sigType = COM_SIGTYPE_UINT64; /* Uint64 type. */
    }
    else if( ((COM_BIG_ENDIAN_SINT8_START_FUNCID <= sigFuncIdx) && (COM_BIG_ENDIAN_SINT8_END_FUNCID >= sigFuncIdx))
             || ((COM_LITTLE_ENDIAN_SINT8_START_FUNCID <= sigFuncIdx) && (COM_LITTLE_ENDIAN_SINT8_END_FUNCID >= sigFuncIdx)) )
    {
        sigType = COM_SIGTYPE_SINT8; /* Sint8 type. */
    }
    else if( ((COM_BIG_ENDIAN_SINT16_START_FUNCID <= sigFuncIdx) && (COM_BIG_ENDIAN_SINT16_END_FUNCID >= sigFuncIdx))
             || ((COM_LITTLE_ENDIAN_SINT16_START_FUNCID <= sigFuncIdx) && (COM_LITTLE_ENDIAN_SINT16_END_FUNCID >= sigFuncIdx)) )
    {
        sigType = COM_SIGTYPE_SINT16; /* Sint16 type. */
    }
    else if( ((COM_BIG_ENDIAN_SINT32_START_FUNCID <= sigFuncIdx) && (COM_BIG_ENDIAN_SINT32_END_FUNCID >= sigFuncIdx))
             || ((COM_LITTLE_ENDIAN_SINT32_START_FUNCID <= sigFuncIdx) && (COM_LITTLE_ENDIAN_SINT32_END_FUNCID >= sigFuncIdx)) )
    {
        sigType = COM_SIGTYPE_SINT32; /* Sint32 type. */
    }
    else if( (COM_BIG_ENDIAN_SINT64_FUNCID == sigFuncIdx) || (COM_LITTLE_ENDIAN_SINT64_FUNCID == sigFuncIdx) )
    {
        sigType = COM_SIGTYPE_SINT64; /* Sint64 type. */
    }
    else if( (COM_BIG_ENDIAN_FLOAT32_FUNCID == sigFuncIdx) || (COM_LITTLE_ENDIAN_FLOAT32_FUNCID == sigFuncIdx) )
    {
        sigType = COM_SIGTYPE_FLOAT32; /* Float32 type. */
    }
    else if( (COM_BIG_ENDIAN_FLOAT64_FUNCID == sigFuncIdx) || (COM_LITTLE_ENDIAN_FLOAT64_FUNCID == sigFuncIdx) )
    {
        sigType = COM_SIGTYPE_FLOAT64; /* Float64 type. */
    }
    else if( COM_U8N_FUNCID == sigFuncIdx )
    {
        sigType = COM_SIGTYPE_UINT8_N; /* Uint8_N type. */
    }
    else if( COM_U8DYN_FUNCID == sigFuncIdx )
    {
        sigType = COM_SIGTYPE_UINT8_DYN; /* Uint8_DYN type. */
    }
    else
    {
        sigType = COM_SIGTYPE_INVALID; /* Invalid type. */
    }
    return sigType;
}

#define COM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

