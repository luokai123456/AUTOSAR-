/*
********************************************************************************
*
*  File name: PduR_Core.c
*
*  Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 2.0
* Author/Date: ZhangDX/2019.09.06
* Change: New create.
* Cause: New
********************************************************************************
* Version: 2.1
* Author/Date: ZhangDX/2019.08.29
* Change: Add standard API code.
* Cause: Update
********************************************************************************
* Version: 2.2
* Author/Date: ZhangDX/2019.09.05
* Change: 1. Increase the buffer.
*         2. Increase demand realization.
* Cause: Update
********************************************************************************
* Version: 2.3
* Author/Date: ZhangDX/2019.09.11
* Change: Add standard API code.
* Cause: Update
********************************************************************************
* Version: 2.4
* Author/Date: ZhangDX/2019.09.12
* Change: Add routing code, add requirement number.
* Cause: Update
********************************************************************************
* Version: 2.5
* Author/Date: ZhangDX/2019.10.12
* Change: Modify the code format.
* Cause: Optimize
********************************************************************************
* Version: 2.6
* Author/Date: ZhangDX/2019.10.25
* Change: Improve the code.
* Cause: Optimize
********************************************************************************
* Version: 2.7
* Author/Date: ZhangDX/2019.10.28
* Change: Add new code.
* Cause: Update
********************************************************************************
* Version: 2.8
* Author/Date: ZhangDX/2019.10.29
* Change: Increases the return value of the internal initialization function.
* Cause: Update
********************************************************************************
* Version: 2.9
* Author/Date: ZhangDX/2019.10.30
* Change: Remove redundant functions and clean up the code format.
* Cause: Update
********************************************************************************
* Version: 2.10
* Author/Date: ZhangDX/2019.10.30
* Change: Change parameter checking logic (PduR_CheckParam()).
* Cause: Update.
********************************************************************************
* Version: 2.11
* Author/Date: ZhangDX/2019.10.30
* Change: 1. Change parameter name.
*         2. Add init check pointer param.
*         3. Modify the pass - in logic for upper - level functions to call
*            lower - level functions.
* Cause: Update
********************************************************************************
* Version: 2.12
* Author/Date: ZhangDX/2019.10.31
* Change: 1. Modify the function input return value.
*         2. Modify the function processing logic CancelReceived & CancelTransmit
*            if it does not match the requirement.
*         3. Modify RxIndication function internal processing logic, remove Tp
*            processing.
* Cause: Update
********************************************************************************
* Version: 2.13
* Author/Date: ZhangDX/2019.11.11
* Change: 1. Modify the transfer protocol layer to receive the logical logic in
*            accordance with the requirements (SWS_PduR_00673).
*         2. Add requirement description.
*         3. Change PduR_Route_TxConfirmation -> PduR_Route_UpTpTxConfirmation
*         4. Add check SWS_PduR_00633 function.
*         5. Change Tp I-PDU Transmission from upper module(s).
* Cause: Update
********************************************************************************
* Version: 2.14
* Author/Date: ZhangDX/2019.11.12
* Change: 1. Add note & change function name.
*         2. Change function param.
*         3. Add check 'retry' param in PduR_LoTpCopyTxData().
*         4. Add Buffer allocation.
* Cause: Update
********************************************************************************
* Version: 2.15
* Author/Date: ZhangDX/2019.11.13
* Change: 1. Add the configuration item whether the gateway function is supported.
*         2. Change Buffer allocation.
*         3. Complete the buffer request part of the gateway function.
* Cause: Update
********************************************************************************
* Version: 2.16
* Author/Date: ZhangDX/2019.11.14
* Change: 1. Delete redundant judgment content in the gateway.
*         2. Continue to organize and modify err notes.
*         3. Added function to implement SWS_PduR_00551 requirements.
* Cause: Update
********************************************************************************
* Version: 2.17
* Author/Date: ZhangDX/2019.11.15
* Change: Change global and static Function Name.
* Cause: Update
********************************************************************************
* Version: 2.18
* Author/Date: ZhangDX/2019.12.03
* Change: Modify calling function err.
* Cause: Update
********************************************************************************
* Version: 2.19
* Author/Date: ZhangDX/2019.12.04
* Change: 1. Improve PduR_Route_LoCancelTransmit and PduR_Route_LoCancelReceive
*            functions.
*         2. Improve PduR_Route_LoTpChangeParameter functions.
*         3. Optimize pre-compilation and remove redundant pre-compilation
*            conditions.
*         4. Add separation for multicast function.
*         5. Add functions, variables, and data types for TP module multicast
*            function implementation.
*         6. Improve the content of PduR_Route_LoTransmit and
*            PduR_Route_UpTxConfirmation functions.
*         7. Separate multicast functions with pre-compiled options.
* Cause: Update
********************************************************************************
* Version: 2.20
* Author/Date: ZhangDX/2019.12.05
* Change: 1. Complete Chapter 7.1.2.3.1 Multicast transmission in the AutoSAR
*            PduR 4.2 document.
*         2. Improve PduR_Route_UpTpTxConfirmation, PduR_Route_UpTpRxIndication,
*            PduR_Route_UpRxIndication functions.
*         3. Split multicast into send multicast and receive multicast.
*         4. Complete the receiving process for the Tp module according to the
*            content of the document (if the gateway is not supported).
*         5. Improve PduR_Route_UpTpStartOfReception, PduR_Route_UpTpCopyRxData,
*            PduR_Route_UpTriggerTransmit, PduR_Route_UpTpCopyTxData functions.
*         6. Add header files specified in other documents.
*         7. Solve the code err after enabling the gateway function.
*         8. Change the function names of "IF buffer" and "Tp Buffer"
*            (Route-> If / TP).
*         9. There are duplicates of multicast and gateway functions in the
*            document, so one or relational pre-compilation option is added.
*         10. Increase the implementation of SWS_PduR_00303, SWS_PduR_00306
*             requirements.
* Cause: Update
********************************************************************************
* Version: 2.21
* Author/Date: ZhangDX/2019.12.06
* Change: 1. Complete the communication interface layer gateway sending function.
*         2. Implementation requirements: If direct data provision is used with
*            a FIFO.
*         3. The function PduR_UpTransmit () does not participate in the gateway
*            implementation.
*         4. PduR_Route_UpTransmit -> PduR_Route_LoTransmit.
*         5. 7.1.3.1.2 Error handling.
*         6. Solve the err of the function requirements of the communication
*            interface gateway.
* Cause: Update
********************************************************************************
* Version: 2.22
* Author/Date: ZhangDX/2019.12.09
* Change: 1. The Pdu router module supports the gateway function into protocol
*            layer and interface layer.
*         2. PDUR_USE_TP_BUFFER -> PDUR_SUPPORT_GETWAY
*         3. Modify the comment format.
*         4. Adjust the code so that it can support non-gateway PDUs under the
*            gateway function.
*         5. Change PduR_Rout_xxx name.
* Cause: Update
********************************************************************************
* Version: 2.23
* Author/Date: ZhangDX/2019.12.10
* Change: 1. Complete the transport protocol layer gateway function.
*         2. Requirement SWS_PduR_00551 No corresponding content was found in
*            the context, it is not implemented.
*         3. Requirement SWS_PduR_00696 is not implemented in this version because
*            the release is that the copied data is not buffer data, and there is
*            no need to implement it under this structure.
*         4. The content of 7.1.3.2.3 Forwarding to upper layers in the 4.2
*            document has not been implemented yet.
*         5. The main reason is that to implement its functions, it is necessary
*            to stay in the TpRxIndication function, and it cannot meet the
*            requirements in the timing diagram. Need to add a MainFunction
*            function, other than temporarily no workaround.
*         6. Update the rules for PduR_LoTpStartOfReception () to call the upper
*            module in the gateway function.
* Cause: Update
********************************************************************************
* Version: 2.23
* Author/Date: ZhangDX/2019.12.30
* Change: 1. add PduR_ReportError() PduR_Det_ReportRuntimeError()
*         2. Replace the function PduR_Det_ErrorReport with the PduR_ReportError
*            function.
*         3. 1, 2 in order to achieve SWS_PduR_00100 and SWS_PDUR_00816 requirements.
* Cause: Update
********************************************************************************
* Version: 2.24
* Author/Date: ZhangDX/2020.01.03
* Change: BUG resolution JIRA- CCORE-46
* Cause: Update
********************************************************************************
* Version: 2.25
* Author/Date: ZhangDX/2020.01.06
* Change: 1. Delete the PduR module reference Std_Types.h and replace it with
*            ComStack_Types.h.
*         2. Remove redundant "ComStack_Cfg.h" and "ComStack_Types.h" files.
* Cause: Update
********************************************************************************
* Version: 2.26
* Author/Date: ZhangDX/2020.01.06
* Change: Add the value of the external interface to determine the
*         initialization status.
* Cause: Update
********************************************************************************
* Version: 2.27
* Author/Date: ZhangDX/2020.01.08
* Change: 1. Removed the support of the underlying modules for the three
*            configuration items PduRCancelReceive, PduRCancelTransmit, and
*            PduRChangeParameterApi.
*         2. Modified the problem that the macros used by FrTp and J1939Tp
*            module related functions are incorrectly defined.
*         3. Article 1 log after consultation cancel, rollback original state.
*         4. Add the local PduRRoutingPathGroup data type to replace the
*            PduRRoutingPathGroup_Type type in PduR_Types.h.
*         5. Modified the situation where a null pointer is called in the
*            PduR_LoRxIndication function.
* Cause: Update
********************************************************************************
* Version: 2.28
* Author/Date: ZhangDX/2020.01.09
* Change: 1. Added relevant code about Det err.
*         2. Change the method used for parameter checking and initialization
*            checking in the previous version.
*         3. Modified the name of PDUR_MODULE_ID to MODULE_ID_PDUR, and added
*            the pre-compilation control of PDUR_DEV_ERROR_DETECT.
*         4. Modified the bug that PduR_Route_UpTpCopyTxData function does not
*            assign a value to the return value.
* Cause: Optimize
********************************************************************************
* Version: 2.29
* Author/Date: ZhangDX/2020.01.10
* Change: 1. Solved the bug that the PduR_Route_UpTpCopyRxData function did not
*            assign a value to the return value after performing copy data.
*         2. Solve the bug that the PduR_Route_UpTpStartOfReception function
*            does not assign a value to the return value after performing
*            related functions.
* Cause: Optimize
********************************************************************************
* Version: 2.30
* Author/Date: ZhangDX/2020.01.16
* Change: PduR_Det_ReportRuntimeError() call Det_ReportRuntimeError() not
*         Det_ReportError()
* Cause: Optimize
********************************************************************************
* Version: 2.31
* Author/Date: ZhangDX/2020.02.19
* Change: 1. Modify the structure definition to support the implementation of
*            API: PduR_DisableRouting.
*         2. Modify the function logic so that it can modify the default values
*            of the buffers of all the pdus in a pdu group.
* Cause: Update
********************************************************************************
* Version: 2.32
* Author/Date: ZhangDX/2020.03.18
* Change: Delete functions that do not exist in the IpduM module.
* Cause: Update
********************************************************************************
* Version: 2.33
* Author/Date: ZhangDX/2020.03.25
* Change: 1. Add notes.
*         2. Perform a QAC check and correct any errors that occur.
* Cause: Optimize
********************************************************************************
* Version: 3.0
* Author/Date: ZhangDX/2020.03.27
* Change: 1. Updated version information is 3.0.0.
*         2. Fix the type mismatch problem.
* Cause: Clear QAC warning and updata to V3.0.
********************************************************************************
* Version: 3.1
* Author/Date: ZhangDX/2020.03.30
* Change: 1. Add notes.
*         2. Clear the configuration.
* Cause: Coding specifications.
********************************************************************************
* Version: 3.2
* Author/Date: ZhangDX/2020.04.16
* Change: 1. Modify the macro to define PDRU_VALIDATE_CONFIG_PARAM as a variable
*            parameter.
*         2. Modify the brace range of the if statement inside the function.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: ZhangDX/2020.04.20
* Change: Correct the err that PduR calls the RxIndication function after
*         checking the lower module.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: ZhangDX/2020.05.15
* Change: 1. Cancel the err report that multicast and gateway cannot coexist.
*         2. Solve the problems that occur after multicast transmission is enabled.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: ZhangDX/2020.06.22
* Change: 1. Increased the empty operation of PduRDestTxBufferRef.
*         2. Modify the processing when the value of PduR_PBcfg_TxBufferTable
*            is empty, and no longer report the err.
*         3. Modify the code and comment format.
* Cause: Bugfix
********************************************************************************
* Version: 3.5
* Author/Date: ZhangDX/2020.07.13
* Change: 1. Replace "req" with "Req".
*         2. Replace "PduR_ReportError" with "PDUR_REPORT_DET_ERROR".
*         3. Add #if (STD_ON == PDUR_DEV_ERROR_DETECT) pre-compilation before the
*            declaration and implementation of the three functions
*            PduR_ReportError, PduR_Det_ErrorReport and PduR_Det_ReportRuntimeError.
*         4. Code format.
*         5. Optimize the internal implementation of PduR_MemSet and increase the
*            judgment of null pointers.
*         6. Modify the parameter name. Modify the parameter range.
*         7. Set the default function debugging after closing the routing group.
*         8. Update and test the PduR_UpCancelTransmit function, and try to cover
*            the test process.
*         9. Add the number of groups to judge.
*         10. Change the destination PDU idx type to uint16.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: ZhangDX/2020.07.14
* Change: 1. Add PduR assertion definition.
*         2. Delete PduRPathSupportGetWay.
*         3. Update the gateway function of the communication interface layer and
*            the FIFO function of the gateway.
*         4. Update the code format.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: ZhangDX/2020.07.15
* Change: 1. Resolve errors that occur during debugging.
*         2. The "serviceID" parameter of the related functions of each layer
*            was deleted and changed to a fixed "serviceID", which was defined
*            in PduR_Core.h.
*         3. PDUR_IS_UP_MODULE, PUDR_IS_IF_MODULE, and PUDR_IS_TP_MODULE no
*            longer require conditional compilation.
*         4. Modify the relevant code format of the Lo layer and optimize the
*            conditions to compile the relevant code.
*         5. Modify API PduR_UpTransmit to make it reentrant.
*         6. Delete the PduRIsModule_Type data type.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: ZhangDX/2020.07.16
* Change: 1. Add PduR_CeckCfgValid function for configuration item check.
*         2. Update the TP gateway code.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: ZhangDX/2020.07.17
* Change: 1. Delete the NEUSAR_SUPPORT_METE_DATA_LENGTH pre-compilation and add
*            relevant information.
*         2. Add function PduR_RefreshFIFO to achieve SWS_PduR_00663 requirements.
*         3. Update TP gateway function.
*         4. Optimize the TP multicast function and reduce the code.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: ZhangDX/2020.07.20
* Change: 1. Increase the check for multicast reception. The rules in the AutoSAR
*            document do not support multicast reception.
*         2. Optimize the processing method after IF layer multicast sending
*            callback TxConfirmation. Only when all callbacks are received will
*            the upper layer TxConfirmation be called.
*         3. Modify the gateway call parameter input error in the PduR_LoTxConfirmation
*            function.
*         4. Realization of requirements SWS_PduR_00666, SWS_PduR_00667.
*         5. When the Tp gateway uses the general buffer, it will not copy data
*            multiple times in the same cycle.
*         6. Re-implement the SWS_PduR_00551 requirement.
*         7. Delete the operation of calling the PduR_Route_LoTransmit function
*            in the PduR_LoTpCopyRxData function in the gateway mode.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: ZhangDX/2020.08.18
* Change: 1. Add an invalid RoutingPathGroupId so that no group reference is
*            made to the destination PDU.
*         2. Increase the judgment of invalid RoutingPathGroupId.
*         3. Check whether the generated code is correct.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: ZhangDX/2020.08.20
* Change: Support configuration items PduRTxConfirmation, PduRTriggerTransmit
*         and PduRRetransmission.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: ZhangDX/2020.08.21
* Change: Solve the bug in the PduR_LoRxIndication function.
* Cause: Bugfix
********************************************************************************
* Version: 3.14
* Author/Date: ZhangDX/2020.08.24
* Change: Solve the bug in the PduR_SetRoutingGroupTxBufferDefault function.
* Cause: Bugfix
********************************************************************************
* Version: 3.15
* Author/Date: ZhangDX/2020.08.26
* Change: In order to adapt to the current CanTp protocol implementation
*         logic, increase the size element actually applied for the buffer,
*         and use this element to calculate the remaining buffer.
* Cause: Update
********************************************************************************
* Version: 3.16
* Author/Date: ZhangDX/2020.09.25
* Change: 1. Modify the errors that occurred during the code review on 2020.09.23.
*         2. Optimizing the code review on 2020.09.23 is a suggestion item given.
*         3. Optimize the FIFO logic of TxBuffer.
*         4. Optimized the coverage area of PDUR_ZERO_COST_OPERATION.
* Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date: ZhangDX/2020.09.26
* Change: Optimize the queue release method to reduce code duplication.
* Cause: Update
********************************************************************************
* Version: 3.18
* Author/Date: ZhangDX/2020.09.27
* Change: 1. Optimize TpBuffer operation logic. Solve the bug that the general
*            TpBuffer buffer can still be obtained after using the dedicated buffer.
*         2. Complete AutoSAR code style conversion.
* Cause: Update
********************************************************************************
* Version: 3.19
* Author/Date: ZhangDX/2020.09.29
* Change: Add MemMap section.
* Cause: Update
********************************************************************************
* Version: 3.20
* Author/Date: ZhangDX/2020.09.30
* Change: Modify the error in converting AutoSAR style.
*         1. Function parameters without pointers need to be converted.
*         2. The memclass used by local variables is AUTOMATIC.
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date: ZhangDX/2020.10.06
* Change: Add PostBuild function.
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date: ZhangDX/2020.10.09
* Change: Modify the implementation of the on-the-fly gateway function, the
*         previous understanding is incorrect.
* Cause: Update
********************************************************************************
* Version: 3.23
* Author/Date: ZhangDX/2020.10.10
* Change: 1. Add the macro definition for judging the FIFO function.
*         2. Delete the semicolon at the end of the macro definition part about
*            DET, modify it to the realization of the macro definition.
*         3. Add API: Set the default bufferSizePtr value in
*            PduR_LoTpStartOfReception.
* Cause: Update
********************************************************************************
* Version: 3.24
* Author/Date: ZhangDX/2020.10.12
* Change: 1. Updated version information is 3.2.0.
*         2. Fix the type mismatch problem.
*         3. Optimize the PduR_MemCopy function.
*         4. Restore the AutoSAR style of local variables to the normal style.
* Cause: Clear QAC warning and updata to V3.2.0.
********************************************************************************
* Version: 3.25
* Author/Date: ZhangDX/2020.10.13
* Change: 1. Optimize the implementation of PduRZeroCostOperation function code.
*         2. Optimize the function in PduR_Core.c to determine the macro
*            definition of PduR status.
* Cause: Update
********************************************************************************
* Version: 3.26
* Author/Date: ZhangDX/2020.10.14
* Change: 1. Modify the function to generate indentation to make the length meet
*            the requirements as much as possible.
*         2. Modify the BUG with the return value of PduR_LoTpStartOfReception
*            as NOT_OK.
* Cause: Bugfix
********************************************************************************
* Version: 3.27
* Author/Date: ZhangDX/2020.10.19
* Change: 1. Modify the second parameter of the function PduR_MemSet&PduR_MemCopy
*            to be of const type.
*         2. Modify the problem of repeated initialization of QAC local variables.
* Cause: Update & Clear QAC warning.
********************************************************************************
* Version: 3.28
* Author/Date: ZhangDX/2020.11.02
* Change: 1. The requirement SWS_PduR_00621 is incorrectly understood, and now
*            the API is modified for this requirement: the realization of
*            PduR_LoRxIndication.
*         2. Modify the PduR_CeckCfgValid function, and now only check if the
*            source is TP, the destination does not allow multiple upper modules.
*         3. Add external interface to judge whether different PDU belongs to
*            this interface.
* Cause: Bugfix & Update.
********************************************************************************
* Version: 3.29
* Author/Date: ZhangDX/2020.11.04
* Change: Modify the wrong part of the segment definition.
* Cause: Update
********************************************************************************
* Version: 3.30
* Author/Date: ZhangDX/2020.11.05
* Change: 1. Realize the requirements SWS_PduR_00726 and SWS_PduR_00710.
*         2. Modify the problem of "judge after using routPathPtr pointer" in
*            function PduR_LoTpCopyRxData.
* Cause: Bugfix
********************************************************************************
* Version: 3.31
* Author/Date: ZhangDX/2020.11.09
* Change: API: PduR_LoTpStartOfReception not return BUFREQ_E_OVFL.
* Cause: Bugfix
********************************************************************************
* Version: 3.32
* Author/Date: ZhangDX/2020.11.11
* Change: 1. Solve the bug that the PduR_LoTpCopyTxData function cannot return
*            the remaining buffer length when using the TpBuffer buffer.
*         2. Increase the macro definition package for the PduR_PBcfgAdminPtr
*            parameter, and use it in related macros.
* Cause: Bugfix
********************************************************************************
* Version: 3.33
* Author/Date: ZhangDX/2020.11.12
* Change: 1. Solve the demand SWS_PduR_00814 implementation error.
*         2. Solve the demand SWS_PduR_00815 implementation error.
*         3. Delete TCPIP_CONST, change it PDUR_CONST.
* Cause: Bugfix.
********************************************************************************
* Version: 3.34
* Author/Date: ZhangDX/2020.11.14
* Change: Solve the demand SWS_PduR_00740 implementation error.
* Cause: Bugfix
********************************************************************************
* Version: 3.35
* Author/Date: ZhangDX/2020.11.26
* Change: 1. (PduR-BUG-No.001)
*            Solve the situation that the PduR_LoTpStartOfReception function
*            cannot return BUFREQ_E_OVFL when there is only one upper layer.
*         2. (PduR-BUG-No.002)
*            Solve the bug that the available buffer can still be obtained when
*            the Tp buffer is full.
* Cause: Bugfix
********************************************************************************
* Version: 3.36
* Author/Date: ZhangDX/2020.11.27
* Change: 1. Optimize the initialization logic and reduce the for loop.
*         2. Support not configuring routing path groups.
* Cause: Update
********************************************************************************
* Version: 3.37
* Author/Date: ZhangDX/2021.1.18
* Change: 1. Replace inline state with the standard LOCAL_INLINE.
*         2. The encapsulation standard LOCAL_INLINE is PDUR_LOCAL_INLINE, which
*            is used as a mark to optimize the execution efficiency of PduR code.
* Cause: Update
********************************************************************************
* Version: 3.38
* Author/Date: ZhangDX/2020.12.21
* Change: 1. Resolve PduR_UpTransmit warning generated by the uptransmit function.
* Cause: Update
********************************************************************************
* Version: 3.39
* Author/Date: ZhangDX/2021.1.22
* Change: 1. (PduR-BUG-No.003)
*         Solve the redundant judgment conditions found in the unit test.
* Cause: BugFix
********************************************************************************
* Version: 3.40
* Author/Date: ZhangDX/2021.1.23
* Change: 1. (PduR-BUG-No.005)
*         To delete the redundant judgment of the PduR_UpCancelReceive function,
*         we only need to judge once that routPathPtr is not empty.
*         2. (PduR-BUG-No.006)
*         To delete the redundant judgment of the PduR_LoTriggerTransmit function,
*         we only need to judge once that routPathPtr is not empty.
*         3. (PduR-BUG-No.007)
*         To delete the redundant judgment of the PduR_LoTpStartOfReception function,
*         we only need to judge once that routPathPtr is not empty.
* Cause: BugFix
********************************************************************************
* Version: 3.41
* Author/Date: ZhangDX/2021.1.26
* Change: 1. (PduR-BUG-No.008)
*         To delete the redundant judgment of the PduR_CeckCfgValid function,
*         we only need to judge once that routPathPtr is not empty.
*         2. (PduR-BUG-No.009)
*         To delete the redundant judgment of the PduR_SetRoutingGroupTxBufferDefault
*         function, we only need to judge once that routPathPtr is not empty.
*         3. (PduR-BUG-No.010)
*         To delete the redundant judgment of the PduR_RefreshFIFO function,
*         we only need to judge once that routPathPtr is not empty.
* Cause: BugFix
********************************************************************************
* Version: 3.42
* Author/Date: ZhangDX/2021.2.04
* Change: 1. (PduR-BUG-No.011)
*         Delete the PduR_LoRxIndication function to count the number of target
*         PDUs prohibited.
* Cause: BugFix
********************************************************************************
* Version: 3.43
* Author/Date: ZhangDX/2021.2.19
* Change: 1. Optimize code execution efficiency.
*            Direction: Multi-purpose logic is changed to do{}while(), local
*            variables are defined nearby.
*         2. Move PDUR_LOCAL_INLINE to the PduR_Types.h file.
* Cause: Optimization
********************************************************************************
* Version: 3.44
* Author/Date: ZhangDX/2021.2.26
* Change: 1. Delete the return value of the PduR_Route_UpRxIndication function.
*         2. After commenting Req: SWS_PduR_00306, add PDUR_UNUSED to eliminate
*            the warning.
*         3. The last assignment to retVal after deleting the PduR_LoRxIndication
*            function.
*         4. Delete the return value of the PduR_Route_UpTxConfirmation function.
*         5. Delete the return value of the PduR_Route_UpTpTxConfirmation function.
*         5. Delete the return value of the PduR_Route_UpTpRxIndication function.
* Cause: Update
********************************************************************************
********************************************************************************
* Version: 3.45
* Author/Date: ZhangDX/2021.05.31
* Change: Modify the local variable definition position in PduR_LoRxIndication(),
*         PduR_LoTpStartOfReception(), PduR_LoTpRxIndication(), local variables
*         need to be defined after "{" in greenhills.
* Cause: Update & Bugfix.
********************************************************************************
* Version: 3.46
* Author/Date: ZhangDX/2021.06.30
* Change: Adjust the code that violates the coding standards.
* Cause: Optimization
********************************************************************************
* Version: 3.47
* Author/Date: LiuHJ/2021.09.13
* Change: For compatible with 4.4, add new function PduR_LoTxConfirmation_44.
* Cause: Bugfix
********************************************************************************
* Version: 3.48
* Author/Date: SunHQ/2022.06.20
* Change: 1. Modify the logic of the PduR_MemCopy function.
*         2. Modify the logic problem in the TP gateway.
*         3. Modify the PduR_TP_BufferIsFull function that causes the previous buffer
*            to be cleared due to repeated buffer applications.
*         4. Initialize the local variables in PduR_LoTpStartOfReception &
*            PduR_LoTpCopyTxData.
*         5. Remove redundant judgment conditions in PduR_LoTpStartOfReception.
*         6. Fix the invalid do while loop problem caused by the wrong position
*            of the macro statement in PduR_UpTransmit.
* Cause: Bugfix & Clear compile warning.
********************************************************************************
* Version: 3.49
* Author/Date: SunHQ/2022.07.05
* Change: Fix the problem that the return value of the PduR_LoTpStartOfReception
*         function may be wrong in the case of multicast.
* Cause: Bugfix
********************************************************************************
* Version: 3.50
* Author/Date: SunHQ/2022.09.08
* Change: 1. Correct the section where the non-constant is located.
*         2. Initialize the local variables in PduR_TP_GatewayRouteTransmit &
*            PduR_UpCancelReceive.
*         3. Modify the alignment format.
* Cause: Optimization & Clear compile warning.
********************************************************************************
* Version: 3.51
* Author/Date: SunHQ/2022.09.09
* Change: 1. Correct the allocation and deallocation logic of TP buffer.
*         2. Correct the gatewaying logic when forwarding to upper layer.
* Cause: Bugfix
********************************************************************************
* Version: 3.52
* Author/Date: SunHQ/2022.09.13
* Change: Add caching mechanism in the implementation of TP buffer.
* Cause: Bugfix
********************************************************************************
* Version: 3.53
* Author/Date: SunHQ/2022.09.20
* Change: Multicore distribution support.
* Cause: Update
********************************************************************************
* Version: 3.54
* Author/Date: SunHQ/2022.12.29
* Change: Remove the conditional judgment from the function
*         PduR_TP_GetWayTxConfirmation.
* Cause: Bugfix
********************************************************************************
* Version: 3.55
* Author/Date: SunHQ/2023.01.05
* Change: 1. Correct the judgment error in PduR_LoTpCopyRxData function.
*         2. Fixed the warning issue when TP gateway mode was not supported.
* Cause: Bugfix
********************************************************************************
* Version: 3.56
* Author/Date: SunHQ/2023.02.10
* Change: Modify the macro that controls the code implementation.
* Cause: Clear compile warning.
********************************************************************************
* Version: 3.57
* Author/Date: SunHQ/2023.02.28
* Change: 1. Correct the implementation of Tp receive related functions.
*         2. Correct the implementation of the PduR_TP_BufferIsFull and
*            PduR_TP_GetTpBuffer functions when multi-core is enabled.
* Cause: Bugfix
********************************************************************************
********************************************************************************
* Version: 3.58
* Author/Date: YuHC/2023.05.06
* Change: 1. Set Diag request flag when function PduR_LoTpStartOfReception
*            processing is completed.
* Cause: Bugfix
********************************************************************************
* Version: 3.59
* Author/Date: SunHQ/2023.04.20
* Change: 1.Add PduR_TP_Buffer_FreeLastNode function.
*         2.If the result is not ok, PduR_LoTpRxIndication does not perform the
*           gateway route.
*         3.Modify the default return value of the PduR_TP_BufferIsFull function.
* Cause: Bugfix
********************************************************************************
* Version: 3.60
* Author/Date: SunHQ/2023.05.19
* Change: Modified the implementation of PduR_UpTransmit under multi-core.
* Cause: Bugfix
********************************************************************************
* Version: 3.61
* Author/Date: SunHQ/2023.06.01
* Change: 1.Set SduDataPtr to NULL_PTR when the destination is CanTp.
*         2.The sending status is not updated when the amount of available
*           data is queried.
* Cause: Bugfix
********************************************************************************
* Version: 3.62
* Author/Date: LuQ/2023.10.08
* Change: Modify the macro that controls the code implementation.
* Cause: Clear compile warning.
********************************************************************************
* Version: 3.63
* Author/Date: LuQ/2023.10.17
* Change: Modify the declaration definition of function PduR_GetTpMul,
*         PduR_GetIfMul and PduR_TP_GetTpBuffer.
* Cause: Bugfix
********************************************************************************
* Version: 3.64
* Author/Date: LuQ/2023.10.18
* Change: If the result is not ok, PduR_TP_GetWayTxConfirmation Clear TP buffer.
* Cause: Bugfix
********************************************************************************
* Version: 3.65
* Author/Date: LuQ/2023.12.04
* Change: 1. PduR module sends multicast query deletion.
*         2. Send confirmation multicast query using indexing method.
*         3. Multi core function optimization.
*         4. Optimize the speed of sending polling Pdu in PduR.
* Cause: Update
********************************************************************************
* Version: 3.66
* Author/Date: LuQ/2023.12.05
* Change: Modified the implementation of PduR_LoTpTxConfirmation in non
*         multi-core environment.
* Cause: Update
********************************************************************************
* Version: 3.67
* Author/Date: LuQ/2023.12.07
* Change: Add macro switch to restrict appId.
* Cause: Update
********************************************************************************
* Version: 3.68
* Author/Date: LuQ/2023.12.22
* Change: Modify the method of obtaining the application partition to which
*         the thread configuration belongs.
* Cause: Bugfix
********************************************************************************
* Version: 3.69
* Author/Date: LuQ/2024.01.11
* Change: Removed the judgment on the type of multicast. 
* Cause: Bugfix
********************************************************************************
* Version: 3.70
* Author/Date: LuQ/2024.03.18
* Change: Modify P2CONST member labels.
* Cause: Optimization
********************************************************************************
* Version: 3.71
* Author/Date: LuQ/2024.04.02
* Change: 1. Modify P2CONST member labels.
*         2. Modify the comments format.
* Cause: Optimization
********************************************************************************
* Version: 3.72
* Author/Date: LuQ/2024.05.13
* Change: Add Memmap segment definition.
* Cause: Optimization
********************************************************************************
* Version: 3.73
* Author/Date: LuQ/2024.07.09
* Change: 1. Add the function called at the start of receiving an N-SDU.
*         2. Delete the pointer validation in PduR_LoTriggerTransmit.
* Cause: Bugfix
********************************************************************************
* Version: 3.74
* Author/Date: LuQ/2024.09.03
* Change: Modify PduR_LoTpStartOfReception, PduR_LoTpStartOfReception can
*         return multi-core returnvalue.
* Cause: Bugfix
********************************************************************************
* Version: 3.75
* Author/Date: LuQ/2024.09.23
* Change: Modify the comments format.
* Cause: Optimization
********************************************************************************
* Version: 3.76
* Author/Date: LuQ/2025.03.12
* Change: PduR multicast supports 1:32.
* Cause: Optimization
********************************************************************************
* Version: 3.77
* Author/Date: LuQ/2025.03.26
* Change: Modify the validity of module parameters needs to be checked when Det
*         is off.
* Cause: Optimization
********************************************************************************
* Version: 3.78
* Author/Date: LuQ/2025.03.27
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Optimization
********************************************************************************
* Version: 3.79
* Author/Date: LuQ/2025.03.27
* Change: Remove parameter keyWorld from macro function PDUR_VALIDATE_CONFIG_PARAM.
* Cause: Optimization
********************************************************************************
* Version: 3.80
* Author/Date: LuQ/2025.06.17
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.81
* Author/Date: LuQ/2025.06.23
* Change: Modify the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************.
* Version: 3.82
* Author/Date: LuQ/2025.06.24
* Change: Modify the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
/* Req: SWS_PduR_00161. */
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "PduR_Core.h"
#include "PduR.h"
/* Req: SWS_PduR_00287 */
#if (STD_OFF == PDUR_ZERO_COST_OPERATION)

/* Only in PduR_Core.c will Router related functions be used. */
#define PDUR_ROUTER_FUN
#include "PduR_Router.h"

#if (STD_ON == PDUR_SUPPORT_MULTICORE)
#include "PduR_Queue.h"
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */

#include "PduR_Diag.h"

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/* Macro definition related to PduR MemCopy function. */
/* PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_MEMCPY_ALIGN                          (uint32)(4U)

#endif /* #if (STD_OFF == PDUR_ZERO_COST_OPERATION) */

#if (STD_ON == PDUR_DEV_ERROR_DETECT)
#ifndef PDUR_INSTANCE_ID
#define PDUR_INSTANCE_ID                           (PDUR_INIT_0)
#else   /* #ifndef PDUR_INSTANCE_ID */
#error If the definition is repeated, this definition shall be used.
#endif  /* #ifndef PDUR_INSTANCE_ID */
#endif  /* #if (STD_ON == PDUR_DEV_ERROR_DETECT) */

#if (STD_OFF == PDUR_ZERO_COST_OPERATION)

/* About PduR_TpBuffer_Type->dstPduMask. */
/* Maximum mask value referenced by the destination PDU. */
/* PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_DST_PDU_MASK_MAX                      (uint32)(0x0000FFFFUL)
/* The base mask value used for shifting. */
#define PDUR_DST_PDU_MASK_BASE                     (uint32)(0x00000001UL)
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_DST_PDU_IS_VALID(_tpBuf, _pos)        (((_tpBuf)->dstPduMask & (PDUR_DST_PDU_MASK_BASE << (_pos))) != 0U)
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
#define PDUR_DST_PDU_SET_MASK(_tpBuf, _shift)      ((_tpBuf)->dstPduMask |= (PDUR_DST_PDU_MASK_BASE << (_shift)))
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
#define PDUR_DST_PDU_CLEAR_MASK(_tpBuf, _pos)      ((_tpBuf)->dstPduMask &= (~(PDUR_DST_PDU_MASK_BASE << (_pos))))
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
#define PDUR_DST_PDU_CLEAR_MASK_SAVE(_tpBuf, _pos) ((_tpBuf)->dstPduMaskSave &= (~(PDUR_DST_PDU_MASK_BASE << (_pos))))

/* Take a value on the destination list to perform pointer offset. */
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PTR_VAL(_pdu)                              (*(_pdu))

#ifndef PDUR_IS_UP_MODULE
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_IS_UP_MODULE(_pdu)                    (PDUR_MODULE_IS_UP == ((_pdu)->PduRModuleRef->PduRBswModuleRef & PDUR_MODULE_IS_UP))
#else   /* #ifndef PDUR_IS_UP_MODULE */
#error If the definition is repeated, this definition shall be used.
#endif  /* #ifndef PDUR_IS_UP_MODULE */

#ifndef PDUR_IS_IF_MODULE
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_IS_IF_MODULE(_pdu)                    (PDUR_MODULE_IS_IF == ((_pdu)->PduRModuleRef->PduRBswModuleRef & PDUR_MODULE_IS_IF))
#else   /* #ifndef PDUR_IS_IF_MODULE */
#error If the definition is repeated, this definition shall be used.
#endif  /* #ifndef PDUR_IS_IF_MODULE */
#ifndef PDUR_IS_TP_MODULE
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_IS_TP_MODULE(_pdu)                    (PDUR_MODULE_IS_TP == ((_pdu)->PduRModuleRef->PduRBswModuleRef & PDUR_MODULE_IS_TP))
#else   /* #ifndef PDUR_IS_TP_MODULE */
#error If the definition is repeated, this definition shall be used.
#endif  /* #ifndef PDUR_IS_TP_MODULE */

#ifndef PDUR_IS_IFORTP_MODULE
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_IS_IFORTP_MODULE(_pdu)                (PDUR_IS_IF_MODULE(_pdu) || PDUR_IS_TP_MODULE(_pdu))
#else   /* #ifndef PDUR_IS_IFORTP_MODULE */
#error If the definition is repeated, this definition shall be used.
#endif  /* #ifndef PDUR_IS_IFORTP_MODULE */

#define PDUR_PB_CFG_PTR                            PduR_PBcfgAdminPtr
/* Mark that the buffer is not used by any PDU. */
#define PDUR_IDLE_BUFFER_ID                        (PduIdType)(PDUR_PB_CFG_PTR->PduR_RoutingTablePtr->PduRMaxRoutingPathCnt)

#if (STD_ON == PDUR_SUPPORT_MULICAST)
/* Initial value used for TP module multicast function implementation. */
/* PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_IDLE_PDU_ID                           (PduIdType)(PDUR_PB_CFG_PTR->PduR_RoutingTablePtr->PduRMaxRoutingPathCnt)
/* The length of the buffer used to implement the multicast function of the TP module. */
/* PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_COPYTXDATA_MULICAST_CNT               (PDUR_INIT_6)
#endif  /* #if (STD_ON == PDUR_SUPPORT_MULICAST) */

/* Used for keywords in PDUR_VALIDATE_CONFIG_PARAM. */
/* PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_BREAK                                 break;
/* PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_NO_KEYWORLD
/* Used in the DET call in PDUR_VALIDATE_CONFIG_PARAM to reduce the use of useless semicolons. */
#if (STD_ON == PDUR_DEV_ERROR_DETECT)
#define PDUR_DET_REPORT_IN_PARAM(_apiId, _errorId) PDUR_REPORT_DET_ERROR(_apiId, _errorId);
#else   /* #if (STD_ON == PDUR_DEV_ERROR_DETECT) */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_DET_REPORT_IN_PARAM(_apiId, _errorId)
#endif  /* #if (STD_ON == PDUR_DEV_ERROR_DETECT) */

/* Invalid data processing. */
/* _keyworld: MISRA C:2012 Rule-20.7 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_VALIDATE_CONFIG_PARAM(_apiId, _retVal, _errorId)                   \
        if(PDUR_E_NOT_OK == (_retVal))                                          \
        {                                                                       \
            PDUR_DET_REPORT_IN_PARAM(_apiId, _errorId)                          \
        }

/* Simplify the operation of PduR_PBcfgAdminPtr-> */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_DST_LIST_SIZE()                       PDUR_PB_CFG_PTR->PduR_DstListSize

/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_ROUTING_PATH_GROUP()                  PDUR_PB_CFG_PTR->PduR_RoutingTablePtr->PduRRoutingPathGroup
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_ROUTING_PATH_CNT()                    PDUR_PB_CFG_PTR->PduR_RoutingTablePtr->PduRMaxRoutingPathCnt
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_ROUTING_PATH_GROUP_CNT()              PDUR_PB_CFG_PTR->PduR_RoutingTablePtr->PduRMaxRoutingPathGroupCnt
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_ROUTING_TABLE()                       PDUR_PB_CFG_PTR->PduR_RoutingTablePtr->PduRRoutingTable

/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_DEST_PDU_LIST()                       PDUR_PB_CFG_PTR->PduR_RoutingTablePtr->PduRDestPduList
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_DEST_PDU_PTR(_idx)                    (&PDUR_PB_CFG_PTR->PduR_RoutingTablePtr->PduRDestPduList[(_idx)])
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_ROUTING_PATH(_idx)                    (&(PDUR_PB_CFG_PTR->PduR_RoutingTablePtr->PduRRoutingTable->PduRRoutingPathRef[(_idx)]))
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_TX_BUFFER_TABLE()                     PDUR_PB_CFG_PTR->PduR_RoutingTablePtr->PduRTxBufferTable

#if ((STD_ON == PDUR_SUPPORT_GETWAY) || (defined PDUR_SUPPORT_TP_GETWAY))
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_TP_BUFFER_TABLE()                     PDUR_PB_CFG_PTR->PduR_RoutingTablePtr->PduRTpBufferTable
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_DST_PDU_THR_LIST(_idx)                PDUR_PB_CFG_PTR->PduR_RoutingTablePtr->PduRDstPduThrPtr[_idx]
#endif  /* #if ((STD_ON == PDUR_SUPPORT_GETWAY) || (defined PDUR_SUPPORT_TP_GETWAY)) */

#if (STD_ON == PDUR_SUPPORT_MULICAST)
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_TP_MUL_PTR()                          PDUR_PB_CFG_PTR->PduR_RoutingTablePtr->PduR_TpMulPtr
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_GET_TP_MUL_PTR(_idx)                  PDUR_PB_CFG_PTR->PduR_RoutingTablePtr->PduR_TpMulPtr[_idx]
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_IF_MUL_PTR()                          PDUR_PB_CFG_PTR->PduR_RoutingTablePtr->PduR_IfMulPtr
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_GET_IF_MUL_PTR(_idx)                  PDUR_PB_CFG_PTR->PduR_RoutingTablePtr->PduR_IfMulPtr[_idx]
#endif  /* #if (STD_ON == PDUR_SUPPORT_MULICAST) */

#if (STD_ON == PDUR_SUPPORT_GETWAY)
#define PDUR_TP_BUFFER_NUM                         PDUR_PB_CFG_PTR->PduR_RoutingTablePtr->PduRTpBufferTable->PduRMaxTpBufferNumber
#endif  /* #if (STD_ON == PDUR_SUPPORT_GETWAY) */

#define PDUR_TP_NODE_BASE_SIZE                     sizeof(PduLengthType)

#if (STD_ON == PDUR_SUPPORT_MULTICORE)
#define PDUR_QUEUE_PTR(_idx)                       (PDUR_PB_CFG_PTR->PduR_QueuePtr[_idx])
#define PDUR_CURRENT_PARTITION                     (PDUR_PB_CFG_PTR->PduR_ApplicationPtr[GetApplicationID()])
#define PDUR_ROUTE_NONE                            (0U)
#define PDUR_ROUTE_ALREADY                         (1U)
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */

#if (STD_ON == PDUR_DEV_ERROR_DETECT)
/* Check initialization status in PduR_Core.c and report Det error. */
#define PDUR_VALIDATE_INITIALIZED_CORE(_api, _retVal)               \
        if(PDUR_UNINIT == PduR_ModuleState)                         \
        {                                                           \
            PDUR_REPORT_DET_ERROR(_api, PDUR_E_INVALID_REQUEST)     \
            (_retVal) = PDUR_E_NOT_OK;                              \
        }
#else   /* #if (STD_ON == PDUR_DEV_ERROR_DETECT) */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_VALIDATE_INITIALIZED_CORE(_api, _retVal)
#endif  /* #if (STD_ON == PDUR_DEV_ERROR_DETECT) */
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
#endif  /* #if (STD_OFF == PDUR_ZERO_COST_OPERATION) */

/* PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_START_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"

/* Save the running state of the PDUR module. */
/* Req: SWS_PduR_00644 SWS_PduR_00325 */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_PduR_NonSharedVar" */
static VAR(PduR_StateType, PDUR_VAR_INIT) PduR_ModuleState = PDUR_UNINIT;

/* Save the PDUR module post-build configuration information. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_PduR_NonSharedVar" */
static P2CONST(PduR_PBConfigType, PDUR_VAR_INIT, PDUR_APPL_CONST) PduR_PBcfgAdminPtr = NULL_PTR;

/* PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_STOP_SEC_VAR_INIT
/* MISRA C:2012 Rule-20.1 */
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if (STD_OFF == PDUR_ZERO_COST_OPERATION)

#define PDUR_START_SEC_VAR_INIT
/* MISRA C:2012 Rule-20.1 */
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* Save routing path group information. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_PduR_NonSharedVar" */
static P2VAR(PduRRoutingPathGroup_Type, PDUR_VAR_INIT, PDUR_APPL_DATA) PduR_RoutingPathGroup = NULL_PTR;

#define PDUR_STOP_SEC_VAR_INIT
/* MISRA C:2012 Rule-20.1 */
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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
#define PDUR_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
#if (STD_ON == PDUR_SUPPORT_GETWAY)
static FUNC(void, PDUR_CODE) PduR_MemSet
(
    P2VAR(uint8, AUTOMATIC, PDUR_APPL_DATA) destPtr,
    const uint8 value,
    const uint32 len
);
static FUNC(Std_ReturnType, PDUR_CODE) PduR_MemCopy
(
    P2VAR(uint8, AUTOMATIC, PDUR_APPL_DATA) dst,
    P2CONST(uint8, AUTOMATIC, PDUR_APPL_CONST) src,
    const uint32 size
);
#endif  /* #if (STD_ON == PDUR_SUPPORT_GETWAY) */

#if (STD_ON == PDUR_SUPPORT_MULICAST)

#if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST))
static FUNC_P2VAR(PduRTpMul_Type, PDUR_APPL_DATA, PDUR_CODE) PduR_GetTpMul
(
    const uint16 pathId
);
#endif  /* #if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST)) */

#endif  /* #if (STD_ON == PDUR_SUPPORT_MULICAST) */

#if (STD_ON == PDUR_SUPPORT_GETWAY)
/* IF buffer. */
#if ((defined PDUR_SUPPORT_IF_GETWAY) && (STD_ON == PDUR_SUPPORT_IF_GETWAY))
static FUNC(uint32, PDUR_CODE) PduR_GetBytesToCopyCnt
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfo
);
static FUNC(void, PDUR_CODE) PduR_Core_AllocateBuffer
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfo
);
static FUNC(void, PDUR_CODE) PduR_Core_ReleasePduInfo
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr
);
static FUNC(Std_ReturnType, PDUR_CODE) PduR_Core_GetPduInfo
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfo
);
static FUNC(void, PDUR_CODE) PduR_Core_TxConfirmationGetWay
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr
);
static FUNC(void, PDUR_CODE) PduR_Core_RxIndicationDirect
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfo
);
static FUNC(Std_ReturnType, PDUR_CODE) PduR_Core_RxIndicationTriggerTransmit
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfo
);
#endif  /* #if ((defined PDUR_SUPPORT_IF_GETWAY) && (STD_ON == PDUR_SUPPORT_IF_GETWAY)) */

/* TP buffer. */
#if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY))
static FUNC(Std_ReturnType, PDUR_CODE) PduR_TP_BufferInit(void);
static FUNC(BufReq_ReturnType, PDUR_CODE) PduR_TP_Buffer_AllocNode
(
    P2VAR(PduR_TpBuffer_Type, AUTOMATIC, PDUR_APPL_DATA) tpBufPtr,
    PduLengthType dataLength
);
static FUNC(void, PDUR_CODE) PduR_TP_Buffer_FreeLastNode
(
    P2VAR(PduR_TpBuffer_Type, AUTOMATIC, PDUR_APPL_DATA) tpBufPtr
);
static FUNC(PduLengthType, PDUR_CODE) PduR_TP_Buffer_AvailableSize
(
    P2CONST(PduR_TpBuffer_Type, AUTOMATIC, PDUR_APPL_CONST) tpBufPtr
);
static FUNC(BufReq_ReturnType, PDUR_CODE) PduR_TP_BufferIsFull
(
    PduIdType id, PduLengthType TpSduLength,
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2VAR(boolean, AUTOMATIC, PDUR_APPL_DATA) allocNode
);
static FUNC_P2VAR(PduR_TpBuffer_Type, PDUR_APPL_DATA, PDUR_CODE) PduR_TP_GetTpBuffer
(
    PduIdType id
);
static FUNC(BufReq_ReturnType, PDUR_CODE) PduR_TP_BufferAllocation
(
    PduIdType id,
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    PduLengthType TpSduLength,
    P2VAR(boolean, AUTOMATIC, PDUR_APPL_DATA) allocNode
);
static FUNC(Std_ReturnType, PDUR_CODE) PduR_TpOnTheFly
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) sendPduInfo
);
static FUNC(void, PDUR_CODE) PduR_TP_StartOfCopyData
(
    PduIdType id, P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfo,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);
static FUNC(BufReq_ReturnType, PDUR_CODE) PduR_TP_CopyRxDataEachDest
(
    PduIdType id,
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfo,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr,
    P2VAR(boolean, AUTOMATIC, PDUR_APPL_DATA) isCopyTxData
);
static FUNC(Std_ReturnType, PDUR_CODE) PduR_TP_GatewayRouteTransmit
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr
);
static FUNC(uint16, PDUR_CODE) PduR_TP_FindDstPduPos
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr
);
static FUNC(BufReq_ReturnType, PDUR_CODE) PduR_TP_GateWayCopyTxData
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfo,
    P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_CONST) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
);
static FUNC(void, PDUR_CODE) PduR_TP_GetWayTxConfirmation
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    Std_ReturnType result
);
static FUNC(void, PDUR_CODE) PduR_TP_GatewayUp
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr
);
static FUNC(boolean, PDUR_CODE) PduR_RoutingPath_IsGateway
(
    P2CONST(PduRRoutingPath_Type, AUTOMATIC, PDUR_APPL_CONST) routPathPtr
);
#endif  /* #if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY)) */

#endif  /* #if (STD_ON == PDUR_SUPPORT_GETWAY) */

static FUNC(uint16, PDUR_CODE) PduR_GetTpDstPdusOfPartition
(
    P2CONST(PduRRoutingPath_Type, AUTOMATIC, PDUR_APPL_CONST) routPathPtr,
    const uint16 partitionId
);
#define PDUR_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
#endif /* #if (STD_OFF == PDUR_ZERO_COST_OPERATION) */

#define PDUR_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
#if (STD_ON == PDUR_DEV_ERROR_DETECT)
static FUNC(void, PDUR_CODE) PduR_Det_ErrorReport
(
    uint8 apiID,
    uint8 errorID
);
static FUNC(void, PDUR_CODE) PduR_Det_ReportRuntimeError
(
    uint8 apiID,
    uint8 errorID
);
#endif  /* #if (STD_ON == PDUR_DEV_ERROR_DETECT) */

#if (STD_OFF == PDUR_ZERO_COST_OPERATION)

#if (STD_ON == PDUR_SUPPORT_GETWAY)
static FUNC(void, PDUR_CODE) PduR_InitBuffer(void);
#endif  /* #if (STD_ON == PDUR_SUPPORT_GETWAY) */

static FUNC(Std_ReturnType, PDUR_CODE) PduR_CeckCfgValid
(
    P2CONST(PduRRoutingPath_Type, AUTOMATIC, PDUR_APPL_CONST) routingPathRef
);
#define PDUR_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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
#define PDUR_START_SEC_CODE
/* MISRA C:2012 Rule-20.1 */
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if ((STD_ON == PDUR_SUPPORT_MULICAST) || (STD_ON == PDUR_SUPPORT_GETWAY))

#if (STD_ON == PDUR_SUPPORT_GETWAY)
/*
********************************************************************************
* Function Name: PduR_MemSet
*
* Explanation: Set memory data.
*
* param: destPtr -> dstPduPtr memory address.
*        data -> set data.
*        len -> dstPduPtr length.
*
* retval: None.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC(void, PDUR_CODE) PduR_MemSet
(
    P2VAR(uint8, AUTOMATIC, PDUR_APPL_DATA) destPtr,
    const uint8 value,
    const uint32 len
)
{
    uint32 idx;

    /* No NULL_PTR. */
    if( NULL_PTR != destPtr )
    {
        /* Set the value of the memory cyclically. */
        for( idx = (uint32)PDUR_INIT_0; idx < len; idx++ )
        {
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            destPtr[idx] = value;
        }
    }
}

/*
********************************************************************************
* Function Name: PduR_MemCopy
*
* Explanation: Copy memory data.
*
* param: dstPduPtr -> dstPduPtr memory address.
*        src -> Source memory address.
*        len -> data length.
*
* retval: PDUR_E_OK -> copy success.
*         PDUR_E_NOT_OK -> pointer null.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC(Std_ReturnType, PDUR_CODE) PduR_MemCopy
(
    P2VAR(uint8, AUTOMATIC, PDUR_APPL_DATA) dst,
    P2CONST(uint8, AUTOMATIC, PDUR_APPL_CONST) src,
    const uint32 size
)
{
    Std_ReturnType retVal = PDUR_E_OK;
    uint32 idx;

    /* Cannot be a null pointer. */
    if( (dst != NULL_PTR) && (src != NULL_PTR) )
    {
        for (idx = PDUR_INIT_0; idx < size; idx++)
        {
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            dst[idx] = src[idx];
        }
    }
    else
    {
        /* Set return value. */
        retVal = PDUR_E_NOT_OK;
    }

    return retVal;
}

#endif  /* #if (STD_ON == PDUR_SUPPORT_GETWAY) */

#if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST))
/*
********************************************************************************
* Function Name: PduR_GetTpMul
*
* Explanation: Find the specified multicast structure according to the routing
*              path index ID.
*
* param: pathId -> Routing path index ID.
*
* retval: NULL_PTR: Not found.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC_P2VAR(PduRTpMul_Type, PDUR_APPL_DATA, PDUR_CODE) PduR_GetTpMul
(
    const uint16 pathId
)
{
    uint16 idx = (uint16)PDUR_INIT_0;
    PduRTpMul_Type* retValPtr = NULL_PTR;

    for( ; idx < PduR_PBcfgAdminPtr->PduR_DstTpSize; idx++ )
    {
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( pathId == PDUR_GET_TP_MUL_PTR(idx).routPathRefId )
        {
            retValPtr = &PDUR_GET_TP_MUL_PTR(idx);
            break;
        }
    }

    return retValPtr;
}
#endif  /* #if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST)) */

#endif  /* #if ((STD_ON == PDUR_SUPPORT_MULICAST) || (STD_ON == PDUR_SUPPORT_GETWAY)) */

#if (STD_ON == PDUR_SUPPORT_GETWAY)

#if ((defined PDUR_SUPPORT_IF_GETWAY) && (STD_ON == PDUR_SUPPORT_IF_GETWAY))
/*
********************************************************************************
* Function Name: PduR_GetBytesToCopyCnt
*
* Explanation: Required to implement SWS_PduR_00746.
*
* param: dstPduPtr -> Pointers to routing information.
*        pduInfo -> Length and pointer to the buffer of the I-PDU.
*
* retval: None.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC(uint32, PDUR_CODE) PduR_GetBytesToCopyCnt
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfo
)
{
    uint32 bytesToCopy;

    /* Get copy buffer length. */
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
    if( pduInfo->SduLength >= PDUR_TXBUFFER_MAXLEN(dstPduPtr) )
    {
        /* The configured maximum PduLength in the buffer (PduRPduMaxLength) */
        bytesToCopy = PDUR_TXBUFFER_MAXLEN(dstPduPtr);
    }
    else
    {
        /* The received data length (PduLength of received I-Pdu) */
        bytesToCopy = pduInfo->SduLength;
    }

    return bytesToCopy;
}

/*
********************************************************************************
* Function Name: PduR_Core_AllocateBuffer
*
* Explanation: The gateway module allocates (updates) the buffer.
*
* param: dstPduPtr -> Pointers to routing information.
*        pduInfo -> Length and pointer to the buffer of the I-PDU.
*
* retval: None.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC(void, PDUR_CODE) PduR_Core_AllocateBuffer
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfo
)
{
    Std_ReturnType err;
    uint32 bytesToCopy;

    /* Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
    if( NULL_PTR != dstPduPtr->PduRDestTxBufferRef )
    {
        /* Get copy buffer length. */
        bytesToCopy = PduR_GetBytesToCopyCnt(dstPduPtr, pduInfo);
        /* Check the buffer size configured by the configuration item. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
        if( PDUR_DEPTH_IS_VALID < PDUR_TXBUFFER_DEPTH(dstPduPtr) )
        {
            /* Enter queue. */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            err = PduR_MemCopy(PDUR_TXBUFFER_PDU_DATE(dstPduPtr, PDUR_TXBUFFER_TAIL(dstPduPtr)),
                                pduInfo->SduDataPtr, bytesToCopy);
            PDUR_ASSERT(PDUR_E_NOT_OK == err);
            /* Set pduInfo sduLength. */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            PDUR_TXBUFFER_PDU_LEN(dstPduPtr, PDUR_TXBUFFER_TAIL(dstPduPtr)) = bytesToCopy;
            /* Move the queue pointer. */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            PDUR_TXBUFFER_TAIL(dstPduPtr)++;
            /* The BUSY state will only be set once. */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            if( PDUR_TX_BUFFER_BUSY != (PDUR_TXBUFFER_STATUS(dstPduPtr) & PDUR_TX_BUFFER_BUSY) )
            {
                /* Set TxBuffer status. */
                PDUR_TXBUFFER_STATUS(dstPduPtr) |= PDUR_TX_BUFFER_BUSY;
            }
            /* FIFO is full. Flush the FIFO. */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            if( PDUR_TXBUFFER_DEPTH(dstPduPtr) <= PDUR_TXBUFFER_TAIL(dstPduPtr) )
            {
                /* Reset the queue pointer. */
                PDUR_TXBUFFER_TAIL(dstPduPtr) = (uint8)PDUR_INIT_0;
                /* Req: SWS_PduR_00670 */
                PDUR_REPORT_DET_ERROR(PDUR_SERVICE_ID_GETWAY, PDUR_E_PDU_INSTANCES_LOST)
                /* If FIFO mode? */
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
                if( PDUR_DEPTH_IS_FIFO < PDUR_TXBUFFER_DEPTH(dstPduPtr) )
                {
                    /* Set TxBuffer status is full. */
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
                    PDUR_TXBUFFER_STATUS(dstPduPtr) |= PDUR_TX_BUFFER_IS_FULL;
                }

            }
            /* Prevent the problem of sending data once more in the initial state. */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            if( (PDUR_TX_BUFFER_IS_FULL == (PDUR_TXBUFFER_STATUS(dstPduPtr) & PDUR_TX_BUFFER_IS_FULL)) &&
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
               (PDUR_TXBUFFER_TAIL(dstPduPtr) > PDUR_TXBUFFER_FRONT(dstPduPtr)) )
            {
                /*
                When the queue is full, the head pointer needs to be adjusted to point to the end of the
                queue, so that the first-come-last-out situation will not occur.
                */
                PDUR_TXBUFFER_FRONT(dstPduPtr) = PDUR_TXBUFFER_TAIL(dstPduPtr);
            }
            /* Eliminate the warning. */
            PDUR_UNUSED(err);
        }
    }
}

/*
********************************************************************************
* Function Name: PduR_Core_ReleasePduInfo
*
* Explanation: The gateway module releases the allocated buffer.
*
* param: dstPduPtr -> Pointers to routing information.
*
* retval: None.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC(void, PDUR_CODE) PduR_Core_ReleasePduInfo
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr
)
{
    /* Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
    if( NULL_PTR != dstPduPtr->PduRDestTxBufferRef )
    {
        /* Set the offset of the buffer head. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        PDUR_TXBUFFER_FRONT(dstPduPtr)++;
        /* If it is greater than 1, queue up and move forward. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( PDUR_DEPTH_IS_FIFO < PDUR_TXBUFFER_DEPTH(dstPduPtr) )
        {
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            if( PDUR_TXBUFFER_FRONT(dstPduPtr) >= PDUR_TXBUFFER_DEPTH(dstPduPtr) )
            {
                /* Reset the buffer header. */
                PDUR_TXBUFFER_FRONT(dstPduPtr) = (uint8)PDUR_INIT_0;
                /* Clear is full state. */
                /* PolySpace +1 DEFECT:UINT_CONSTANT_OVFL[Justified:Unset] "NSCA_Polyspace_PduR_UINT_CONSTANT_OVFL" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                PDUR_TXBUFFER_STATUS(dstPduPtr) &= (uint8)(~(uint32)PDUR_TX_BUFFER_IS_FULL);
            }
        }
        /* The buffer is free? */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( (PDUR_TX_BUFFER_IS_FULL != (PDUR_TXBUFFER_STATUS(dstPduPtr) & PDUR_TX_BUFFER_IS_FULL)) &&
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
            (PDUR_TXBUFFER_FRONT(dstPduPtr) >= PDUR_TXBUFFER_TAIL(dstPduPtr)) )
        {
            /* The buffer is free. */
            PDUR_TXBUFFER_STATUS(dstPduPtr) = PDUR_TX_BUFFER_IDLE;
            /* Reset the buffer header. */
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            PDUR_TXBUFFER_TAIL(dstPduPtr) = (uint8)PDUR_INIT_0;
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            PDUR_TXBUFFER_FRONT(dstPduPtr) = (uint8)PDUR_INIT_0;
        }
    }
}

/*
********************************************************************************
* Function Name: PduR_Core_GetPduInfo
*
* Explanation: The gateway module gets the content from the allocated buffer.
*
* param: dstPduPtr -> Pointers to routing information.
*        pduInfo -> Length and pointer to the buffer of the I-PDU.
*
* retval: PDUR_E_OK -> Fetching data was successful.
*         PDUR_E_NOT_OK -> The buffer is empty.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC(Std_ReturnType, PDUR_CODE) PduR_Core_GetPduInfo
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfo
)
{
    Std_ReturnType retVal;

    /* The buffer is not in use. */
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
    if( PDUR_DEPTH_IS_VALID >= PDUR_TXBUFFER_DEPTH(dstPduPtr) )
    {
        /* There must be at least one buffer. */
        retVal = PDUR_E_NOT_OK;
    }
    else if( NULL_PTR == PDUR_TXBUFFER_TXBUF(dstPduPtr) )
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Common_Unreachable " */
    {
        /* No buffer configured? */
        retVal = PDUR_E_NOT_OK;
    }
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
    else if( pduInfo->SduLength < PDUR_TXBUFFER_PDU_LEN(dstPduPtr, PDUR_IDX_0) )
    {
        /* There is not enough buffer. */
        retVal = PDUR_E_NOT_OK;
    }
    else
    {
        /* The gateway module gets the content from the allocated buffer. */
        /* Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        retVal = PduR_MemCopy(pduInfo->SduDataPtr, PDUR_TXBUFFER_PDU_DATE(dstPduPtr, PDUR_IDX_0),
                                PDUR_TXBUFFER_PDU_LEN(dstPduPtr, PDUR_IDX_0));
        PDUR_ASSERT(PDUR_E_NOT_OK == retVal);
        pduInfo->SduLength = PDUR_TXBUFFER_PDU_LEN(dstPduPtr, PDUR_IDX_0);
        /* Req: SWS_PduR_00666. */
        /* Call PduR_Route_LoTransmit. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
        retVal = PduR_Route_LoTransmit(dstPduPtr, &PDUR_TXBUFFER_PDU(dstPduPtr, PDUR_TXBUFFER_FRONT(dstPduPtr)));
        /* Req: SWS_PduR_00788 SWS_PDUR_00807 */
        PDUR_VALIDATE_CONFIG_PARAM(PDUR_SERVICE_ID_GETWAY, retVal, PDUR_E_PDU_INSTANCES_LOST);
        /* Release Buffer. */
        PduR_Core_ReleasePduInfo(dstPduPtr);
    }

    /* Returns the result value. */
    return retVal;
}

/*
********************************************************************************
* Function Name: PduR_Core_TxConfirmationGetWay
*
* Explanation: The gateway module releases the allocated buffer.
*
* param: dstPduPtr -> Pointers to routing information.
*
* retval: None.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC(void, PDUR_CODE) PduR_Core_TxConfirmationGetWay
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr
)
{
    Std_ReturnType retVal;

    /* Req: SWS_PduR_00667 */
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV"  Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
    if( (PDUR_DIRECT == dstPduPtr->PduRDestPduDataProvision) && (NULL_PTR != dstPduPtr->PduRDestTxBufferRef) )
    {
        /* Clear Tx buffer state :PDUR_TX_BUFFER_TX. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( PDUR_TX_BUFFER_TX == (PDUR_TX_BUFFER_TX & PDUR_TXBUFFER_STATUS(dstPduPtr)) )
        {
            /* PolySpace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_PduR_UINT_CONSTANT_OVFL" */
            PDUR_TXBUFFER_STATUS(dstPduPtr) &= (uint8)(~(uint32)PDUR_TX_BUFFER_TX);
        }
        /* Tx buffer is busy? */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( PDUR_TX_BUFFER_BUSY == (PDUR_TX_BUFFER_BUSY & PDUR_TXBUFFER_STATUS(dstPduPtr)) )
        {
            /* SWS_PduR_00667
               When PduR_<DstLo>TxConfirmation is called and the FIFO
               queue is not empty in case of direct data provision <DstLo>_Transmit shall be called
               with the oldest I-PDU of the FIFO. The transmitted I-PDU shall be removed afterwards.
            */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV"  Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            retVal = PduR_Route_LoTransmit(dstPduPtr, &PDUR_TXBUFFER_PDU(dstPduPtr, PDUR_TXBUFFER_FRONT(dstPduPtr)));
            PDUR_ASSERT(PDUR_E_NOT_OK == retVal);
            /* Req: SWS_PduR_00788 SWS_PDUR_00807 */
            /* Release buffer and no retry. */
            PDUR_VALIDATE_CONFIG_PARAM(PDUR_SERVICE_ID_GETWAY, retVal, PDUR_E_PDU_INSTANCES_LOST);
            /* Transmit success? */
            if( PDUR_E_OK == retVal )
            {
                /* Release Buffer. */
                PduR_Core_ReleasePduInfo(dstPduPtr);
            }
        }
    }
    else
    {
        /* Req: SWS_PduR_00640 */
        /* Do nothing. */
    }
}

/*
********************************************************************************
* Function Name: PduR_Core_RxIndicationDirect
*
* Explanation: The PDU Router module shall call the transmit function in the
*        destination module and not buffer the I-PDU.
*
* param: dstPduPtr -> Pointers to routing information.
*        pduInfo -> Pointer to the transmission of the pdu data.
*
* retval: None.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC(void, PDUR_CODE) PduR_Core_RxIndicationDirect
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfo
)
{
    Std_ReturnType retVal = PDUR_E_OK;

    /* SWS_PduR_00665
       If direct data provision is used with a FIFO: When PduR_<SrcLo>RxIndication
       is called and the FIFO queue is empty and no confirmation is outstanding for
       the same PDU, <DstLo>_Transmit shall be called directly. The FIFO stays empty.
    */
    /* Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
    if( NULL_PTR != dstPduPtr->PduRDestTxBufferRef )
    {
        /* Check whether the same PDU is confirmed.(IDEL) */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( PDUR_TX_BUFFER_IDLE == PDUR_TXBUFFER_STATUS(dstPduPtr) )
        {
            /* Call PduR_Route_LoTransmit. */
            retVal = PduR_Route_LoTransmit(dstPduPtr, pduInfo);
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            PDUR_TXBUFFER_STATUS(dstPduPtr) |= PDUR_TX_BUFFER_TX;
        }
        else
        {
            /* SWS_PduR_00793
               If direct data provision is used with a FIFO: The PduR shall enqueue new
               data in the FIFO when PduR_<SrcLo>RxIndication is called and the last
               transmission of the same PDU has not yet been confirmed via
               PduR_<DstLo>TxConfirmation.
            */
            PduR_Core_AllocateBuffer(dstPduPtr, pduInfo);
        }
    }
    else
    {
        /* Call PduR_Route_LoTransmit. */
        retVal = PduR_Route_LoTransmit(dstPduPtr, pduInfo);
    }
    /* Eliminate the warning. */
    PDUR_UNUSED(retVal);
}

/*
********************************************************************************
* Function Name: PduR_Core_RxIndicationTriggerTransmit
*
* Explanation: The PDU Router module shall call the transmit function in the
*        destination module. The destination module will request the
*        I-PDU using the triggerTransmit function. The IPDU is shall be
*        buffered.
*
* param: dstPduPtr -> Pointers to routing information.
*        pduInfo -> Pointer to the transmission of the pdu data.
*
* retval: PDUR_E_OK -> .
*         PDUR_E_NOT_OK -> .
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC(Std_ReturnType, PDUR_CODE) PduR_Core_RxIndicationTriggerTransmit
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfo
)
{
    Std_ReturnType retVal = PDUR_E_OK;

    /* Req: SWS_PduR_00746 */
    /* Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
    if( NULL_PTR != dstPduPtr->PduRDestTxBufferRef )
    {
        /* Copy buffer data. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( PDUR_TX_BUFFER_IDLE == PDUR_TXBUFFER_STATUS(dstPduPtr) )
        {
            /* Req: SWS_PduR_00786 -> Call PduR_Route_LoTransmit. */
            retVal = PduR_Route_LoTransmit(dstPduPtr, pduInfo);
        }
        /* Req: SWS_PduR_00787 */
        PduR_Core_AllocateBuffer(dstPduPtr, pduInfo);
    }
    else
    {
        retVal = PDUR_E_NOT_OK;
        PDUR_REPORT_DET_ERROR(PDUR_SERVICE_ID_GETWAY, PDUR_E_CONFIG_PARAM_ERROR)
    }

    return retVal;
}
#endif  /* #if ((defined PDUR_SUPPORT_IF_GETWAY) && (STD_ON == PDUR_SUPPORT_IF_GETWAY)) */

#if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY))
/*
********************************************************************************
* Function Name: PduR_TP_BufferInit
*
* Explanation: PduR init TP buffer status buffer.
*
* param: None.
*
* retval: PDUR_E_OK: init successed.
*         PDUR_E_NOT_OK: init failed.
********************************************************************************
*/
static FUNC(Std_ReturnType, PDUR_CODE) PduR_TP_BufferInit(void)
{
    uint16 idx = (uint16)PDUR_INIT_0;
    Std_ReturnType retVal = PDUR_E_NOT_OK;
    P2CONST(PduRTpBuffer_Type, AUTOMATIC, PDUR_APPL_CONST) tpBufferRefPtr;

    /* Init tp buffer state bit. */
    if( NULL_PTR != PDUR_TP_BUFFER_TABLE() )
    {
        tpBufferRefPtr = PDUR_TP_BUFFER_TABLE()->PduRTpBufferRef;
        PDUR_ASSERT(NULL_PTR == tpBufferRefPtr);
        /* Loop Tp buffer status. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        for( ; idx < PDUR_TP_BUFFER_TABLE()->PduRMaxTpBufferNumber; idx++ )
        {
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            PduR_PBcfgAdminPtr->PduR_TpBufferStatusPtr[idx].allocBufLen = (uint16)PDUR_INIT_0;
            /* IDLE ID. */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            PduR_PBcfgAdminPtr->PduR_TpBufferStatusPtr[idx].usedId = PDUR_IDLE_BUFFER_ID;
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            PduR_PBcfgAdminPtr->PduR_TpBufferStatusPtr[idx].dstPduMask = (PduRMultiCastType)PDUR_INIT_0;
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            PduR_PBcfgAdminPtr->PduR_TpBufferStatusPtr[idx].dstPduMaskSave = (PduRMultiCastType)PDUR_INIT_0;
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            PduR_PBcfgAdminPtr->PduR_TpBufferStatusPtr[idx].copyRxPointer = (PduLengthType)PDUR_INIT_0;
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            PduR_PBcfgAdminPtr->PduR_TpBufferStatusPtr[idx].copyTxPointer = (PduLengthType)PDUR_INIT_0;
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            PduR_PBcfgAdminPtr->PduR_TpBufferStatusPtr[idx].firstNodePointer = (PduLengthType)PDUR_INIT_0;
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            PduR_PBcfgAdminPtr->PduR_TpBufferStatusPtr[idx].lastNodePointer = (PduLengthType)PDUR_INIT_0;
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            PduR_PBcfgAdminPtr->PduR_TpBufferStatusPtr[idx].usedBufferLength = (PduLengthType)PDUR_INIT_0;
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            PduR_PBcfgAdminPtr->PduR_TpBufferStatusPtr[idx].lastTxPduLength = (PduLengthType)PDUR_INIT_0;
            /* Buffer Free. */
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            PduR_PBcfgAdminPtr->PduR_TpBufferStatusPtr[idx].bufStatus = (uint8)PDUR_BUFFER_FREE;
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            PduR_PBcfgAdminPtr->PduR_TpBufferStatusPtr[idx].pdurTpBufPtr = &tpBufferRefPtr[idx];
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            if( NULL_PTR == PduR_PBcfgAdminPtr->PduR_TpBufferStatusPtr[idx].pdurTpBufPtr )
            {
                /* Break loop and not set return value. */
                break;
            }
        }
        /* Loading finished? */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( PDUR_TP_BUFFER_TABLE()->PduRMaxTpBufferNumber == idx )
        {
            retVal = PDUR_E_OK;
        }
    }
    /* Traverse the purpose pdu list. */
    for( idx = (uint16)PDUR_INIT_0; idx < PDUR_DST_LIST_SIZE(); idx++ )
    {
        /* Set pduRTpThrFlag. */
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        PDUR_DST_PDU_THR_LIST(idx).pduRTpThrFlag = PDUR_FALSE;
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: PduR_TP_Buffer_AllocNode
*
* Explanation: Attempt to allocate node from Tp buffer.
*
* param: tpBufPtr -> Pointers to Tp buffer.
*        dataLength -> The length of data to be stored in the node.
*
* retval: BUFREQ_OK: Node has been allocated successfully.
*         BUFREQ_E_OVFL: No node of the required length can be provided.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_TP_Buffer_AllocNode
(
    P2VAR(PduR_TpBuffer_Type, AUTOMATIC, PDUR_APPL_DATA) tpBufPtr,
    PduLengthType dataLength
)
{
    BufReq_ReturnType retVal = BUFREQ_OK;
    PduLengthType lastNodeSize = (PduLengthType)PDUR_INIT_0;
    PduLengthType freeSpace = (PduLengthType)PDUR_INIT_0;

    /* If the header is written again */
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
    if( tpBufPtr->firstNodePointer > tpBufPtr->lastNodePointer )
    {
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
        lastNodeSize = PDUR_TP_NODE_BASE_SIZE + tpBufPtr->allocBufLen;
        freeSpace = tpBufPtr->firstNodePointer - tpBufPtr->lastNodePointer - lastNodeSize;

        /* Is there enough space to store the data */
        if( (PDUR_TP_NODE_BASE_SIZE + dataLength) <= freeSpace )
        {
            /* Set the new node as the last node */
            tpBufPtr->lastNodePointer += lastNodeSize;
            /* Set the data copy pointer to the new node */
            tpBufPtr->copyRxPointer = tpBufPtr->lastNodePointer + PDUR_TP_NODE_BASE_SIZE;
            /* Set data length of the last node */
            tpBufPtr->allocBufLen = dataLength;
            /* Set buffer status to ready */
            tpBufPtr->bufStatus = (uint8)PDUR_BUFFER_RX_READY;

            /* Save the actual buffer length of this node. */
            /* PolySpace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            (void) PduR_MemCopy(&PDUR_TP_BUFFER(tpBufPtr)[tpBufPtr->lastNodePointer], (const uint8*)&dataLength, PDUR_TP_NODE_BASE_SIZE);  /* PRQA S 0310 */ /* NSCA_QAC_PduR_Rule11.3 */
        }
        else
        {
            /* SWS_PduR_00799 No free buffer. */
            retVal = BUFREQ_E_OVFL;
        }
    }
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
    else if( (PDUR_TP_NODE_BASE_SIZE + dataLength) <= (PDUR_TP_BUFFER_LEN(tpBufPtr) - tpBufPtr->usedBufferLength) )
    {
        /* Set data length of the last node */
        tpBufPtr->allocBufLen = dataLength;
        /* set the new node as the last node */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
        tpBufPtr->lastNodePointer = tpBufPtr->usedBufferLength;
        /* set the data copy pointer to the new node */
        tpBufPtr->copyRxPointer = tpBufPtr->lastNodePointer + PDUR_TP_NODE_BASE_SIZE;
        /* set the actual used buffer length */
        tpBufPtr->usedBufferLength = tpBufPtr->copyRxPointer + dataLength;
        /* Set buffer status to ready */
        tpBufPtr->bufStatus = (uint8)PDUR_BUFFER_RX_READY;

        /* Save the actual buffer length of this node. */
        /* PolySpace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        (void) PduR_MemCopy(&PDUR_TP_BUFFER(tpBufPtr)[tpBufPtr->lastNodePointer], (const uint8*)&dataLength, PDUR_TP_NODE_BASE_SIZE);  /* PRQA S 0310 */ /* NSCA_QAC_PduR_Rule11.3 */
    }
    else if( (PDUR_TP_NODE_BASE_SIZE + dataLength) <= tpBufPtr->firstNodePointer )
    {
        /* set the last node size */
        tpBufPtr->allocBufLen = dataLength;
        /* set the new node as the last node */
        tpBufPtr->lastNodePointer = (PduLengthType)PDUR_INIT_0;
        /* set the data copy pointer to the new node */
        tpBufPtr->copyRxPointer = tpBufPtr->lastNodePointer + PDUR_TP_NODE_BASE_SIZE;
        /* Set buffer status to ready */
        tpBufPtr->bufStatus = (uint8)PDUR_BUFFER_RX_READY;

        /* Save the actual buffer length of this node. */
        /* PolySpace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        (void) PduR_MemCopy(&PDUR_TP_BUFFER(tpBufPtr)[tpBufPtr->lastNodePointer], (const uint8*)&dataLength, PDUR_TP_NODE_BASE_SIZE);  /* PRQA S 0310 */ /* NSCA_QAC_PduR_Rule11.3 */
    }
    else
    {
        /* SWS_PduR_00799 No free buffer. */
        retVal = BUFREQ_E_OVFL;
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: PduR_TP_Buffer_FreeLastNode
*
* Explanation: Free the last node from Tp buffer.
*
* param: tpBufPtr -> Pointers to Tp buffer.
*
* retval: None.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC(void, PDUR_CODE) PduR_TP_Buffer_FreeLastNode
(
    P2VAR(PduR_TpBuffer_Type, AUTOMATIC, PDUR_APPL_DATA) tpBufPtr
)
{
    PduLengthType dataLength = (PduLengthType)PDUR_INIT_0;
    PduLengthType prevNodePointer = (PduLengthType)PDUR_INIT_0;
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
    PduLengthType currentNodePointer = tpBufPtr->firstNodePointer;

    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
    while( currentNodePointer != tpBufPtr->lastNodePointer )
    {
        prevNodePointer = currentNodePointer;

        /* Get data length of the current node */
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        (void) PduR_MemCopy((uint8*)&dataLength, &PDUR_TP_BUFFER(tpBufPtr)[currentNodePointer], PDUR_TP_NODE_BASE_SIZE);  /* PRQA S 0310 */ /* NSCA_QAC_PduR_Rule11.3 */

        /* Move current node pointer to the next */
        currentNodePointer += PDUR_TP_NODE_BASE_SIZE + dataLength;

        /* If the end of the buffer is reached */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
        if( currentNodePointer == tpBufPtr->usedBufferLength )
        {
            /* Move first node pointer to the head of buffer */
            currentNodePointer = (PduLengthType)PDUR_INIT_0;
        }
    }

    if( (PduLengthType)PDUR_INIT_0 == prevNodePointer )
    {
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
        tpBufPtr->usedId = PDUR_IDLE_BUFFER_ID;
        tpBufPtr->bufStatus = (uint8)PDUR_BUFFER_FREE;
        tpBufPtr->dstPduMaskSave = (PduRMultiCastType)PDUR_INIT_0;
        tpBufPtr->copyRxPointer = (PduLengthType)PDUR_INIT_0;
        tpBufPtr->copyTxPointer = (PduLengthType)PDUR_INIT_0;
        tpBufPtr->firstNodePointer = (PduLengthType)PDUR_INIT_0;
        tpBufPtr->lastNodePointer = (PduLengthType)PDUR_INIT_0;
        tpBufPtr->usedBufferLength = (PduLengthType)PDUR_INIT_0;
    }
    else
    {
        /* Get data length of the last node */
        (void) PduR_MemCopy((uint8*)&dataLength,  /* PRQA S 0310 */ /* NSCA_QAC_PduR_Rule11.3 */
                            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                            &PDUR_TP_BUFFER(tpBufPtr)[tpBufPtr->lastNodePointer],
                            PDUR_TP_NODE_BASE_SIZE);

        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
        if( (tpBufPtr->lastNodePointer + PDUR_TP_NODE_BASE_SIZE + dataLength) == tpBufPtr->usedBufferLength )
        {
            /* Reset the actual used buffer length */
            tpBufPtr->usedBufferLength = tpBufPtr->lastNodePointer;
        }

        /* Set the prev node as the last node */
        tpBufPtr->lastNodePointer = prevNodePointer;
    }
}

/*
********************************************************************************
* Function Name: PduR_TP_Buffer_AvailableSize
*
* Explanation: Get the available data size of the current node.
*
* param: tpBufPtr -> Pointers to Tp buffer.
*
* retval: Available data size.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC(PduLengthType, PDUR_CODE) PduR_TP_Buffer_AvailableSize
(
    P2CONST(PduR_TpBuffer_Type, AUTOMATIC, PDUR_APPL_CONST) tpBufPtr
)
{
    PduLengthType dataLength = (PduLengthType)PDUR_INIT_0;
    PduLengthType availableSize = (PduLengthType)PDUR_INIT_0;

    /* Whether there is only one node */
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
    if( tpBufPtr->firstNodePointer == tpBufPtr->lastNodePointer )
    {
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
        availableSize = tpBufPtr->copyRxPointer - tpBufPtr->copyTxPointer;
    }
    else
    {
        /* Get data length of the current node */
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        (void) PduR_MemCopy((uint8*)&dataLength, &PDUR_TP_BUFFER(tpBufPtr)[tpBufPtr->firstNodePointer], PDUR_TP_NODE_BASE_SIZE);  /* PRQA S 0310 */ /* NSCA_QAC_PduR_Rule11.3 */

        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
        availableSize = tpBufPtr->firstNodePointer + PDUR_TP_NODE_BASE_SIZE + dataLength - tpBufPtr->copyTxPointer;
    }

    return availableSize;
}

/*
********************************************************************************
* Function Name: PduR_TP_BufferIsFull
*
* Explanation: Check if there is enough free space in the buffer.
*
* param: id -> PduR module pdu ID.
*        TpSduLength -> Total length of the N-SDU to be received.
*        dstPduPtr -> Pointers to routing information.
*        allocNode -> Whether the node needs to be allocated if tp buffer is used.
*
* retval: BUFREQ_OK: Connection has been accepted.
*         BUFREQ_E_OVFL: No buffer of the required length can be provided.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_TP_BufferIsFull
(
    PduIdType id,
    PduLengthType TpSduLength,
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2VAR(boolean, AUTOMATIC, PDUR_APPL_DATA) allocNode
)
{
    uint16 idx = (uint16)PDUR_INIT_0;
    uint16 pos = (uint16)PDUR_INIT_0;
    BufReq_ReturnType retVal = BUFREQ_E_OVFL;
    PduR_TpBuffer_Type* tpBufPtr = PduR_TP_GetTpBuffer(id);

    /* Has the corresponding routing data been cached? */
    if( NULL_PTR == tpBufPtr )
    {
        /* Loop to find the free buffer. */
        for( ; idx < PDUR_TP_BUFFER_NUM; idx++ )
        {
            tpBufPtr = &PduR_PBcfgAdminPtr->PduR_TpBufferStatusPtr[idx];

            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            if( ((uint8)PDUR_BUFFER_FREE == tpBufPtr->bufStatus)
                 /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                 && ((PDUR_TP_NODE_BASE_SIZE + TpSduLength) <= PDUR_TP_BUFFER_LEN(tpBufPtr)) )
            {
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
                /* Save current partition id */
                tpBufPtr->partitionId = PDUR_CURRENT_PARTITION;
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
                /* Clear mask. */
                tpBufPtr->dstPduMask = (PduRMultiCastType)PDUR_INIT_0;
                /* Set the actual buffer length applied for. */
                tpBufPtr->allocBufLen = TpSduLength;
                /* Set ref routing path ID. */
                tpBufPtr->usedId = id;
                /* Book the block buffer. */
                tpBufPtr->bufStatus = (uint8)PDUR_BUFFER_RX_READY;
                tpBufPtr->copyRxPointer = PDUR_TP_NODE_BASE_SIZE + (PduLengthType)PDUR_INIT_0;
                tpBufPtr->copyTxPointer = PDUR_TP_NODE_BASE_SIZE + (PduLengthType)PDUR_INIT_0;
                /* set the actual used buffer length */
                tpBufPtr->usedBufferLength = PDUR_TP_NODE_BASE_SIZE + TpSduLength;
                /* Save the actual buffer length for this node. */
                /* PolySpace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                (void) PduR_MemCopy(&PDUR_TP_BUFFER(tpBufPtr)[tpBufPtr->lastNodePointer], (const uint8*)&TpSduLength, PDUR_TP_NODE_BASE_SIZE);  /* PRQA S 0310 */ /* NSCA_QAC_PduR_Rule11.3 */

                if( PDUR_TRUE == *allocNode )
                {
                    *allocNode = PDUR_FALSE;
                }
                /* Free buffer is found successfully*/
                retVal = BUFREQ_OK;
                break;
            }

            tpBufPtr = NULL_PTR;
        }
    }
    else
    {
        if( PDUR_TRUE == *allocNode )
        {
            /* Allocate a node from tp buffer */
            retVal = PduR_TP_Buffer_AllocNode(tpBufPtr, TpSduLength);

            if( BUFREQ_OK == retVal )
            {
                *allocNode = PDUR_FALSE;
            }
        }
    }

    /* Is there a valid buffer? */
    if( NULL_PTR != tpBufPtr )
    {
        /* If this is the first time using Tp buffer and the destination module is also Tp */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( (tpBufPtr->firstNodePointer == tpBufPtr->lastNodePointer) && (PDUR_IS_TP_MODULE(dstPduPtr)) )
        {
            pos = PduR_TP_FindDstPduPos(dstPduPtr);
            /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_PduR_SHF" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
            PDUR_DST_PDU_SET_MASK(tpBufPtr, pos);
            tpBufPtr->dstPduMaskSave = tpBufPtr->dstPduMask;
        }
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: PduR_TP_GetTpBuffer
*
* Explanation: Get the Tp buffer used.
*
* param: id -> PduR module pdu ID.
*
* retval: NULL_PTR: get Tp Buffer failed.
*         other: get Tp Buffer success.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC_P2VAR(PduR_TpBuffer_Type, PDUR_APPL_DATA, PDUR_CODE) PduR_TP_GetTpBuffer
(
    PduIdType id
)
{
    uint16 tpBufferIdx = (uint16)PDUR_INIT_0;
    PduR_TpBuffer_Type* tpBufPtr = NULL_PTR;

#if (STD_ON == PDUR_SUPPORT_MULTICORE)
    uint16 curPartitionId = PDUR_CURRENT_PARTITION;
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */

    /* Loop to find the free buffer. */
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
    for( ; tpBufferIdx < PDUR_TP_BUFFER_NUM; tpBufferIdx++ )
    {
        /* Find ID. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
        if( id == PduR_PBcfgAdminPtr->PduR_TpBufferStatusPtr[tpBufferIdx].usedId )
        {
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
            if( curPartitionId == PduR_PBcfgAdminPtr->PduR_TpBufferStatusPtr[tpBufferIdx].partitionId )
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
            {
                tpBufPtr = &PduR_PBcfgAdminPtr->PduR_TpBufferStatusPtr[tpBufferIdx];
                break;
            }
        }
    }

    return tpBufPtr;
}

/*
********************************************************************************
* Function Name: PduR_TP_BufferAllocation
*
* Explanation: PduR module buffer allocation.
*
* param: id -> PduR module pdu ID.
*        dstPduPtr -> Pointers to routing information.
*        pduInfo -> Pointer to the transmission of the pdu data.
*        TpSduLength -> Total length of the N-SDU to be received.
*        allocNode -> Whether the node needs to be allocated if tp buffer is used.
*
* retval: BUFREQ_OK: Connection has been accepted.
*         BUFREQ_E_NOT_OK: Connection has been rejected.
*         BUFREQ_E_OVFL: No buffer of the required length can be provided.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_TP_BufferAllocation
(
    PduIdType id,
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    PduLengthType TpSduLength,
    P2VAR(boolean, AUTOMATIC, PDUR_APPL_DATA) allocNode
)
{
    boolean useExBuf = PDUR_TRUE;    /* Use an exclusive buffer? */
    BufReq_ReturnType retVal = BUFREQ_OK;

    /* Check null pointer. */
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
    if( (NULL_PTR != dstPduPtr->PduRDestTxBufferRef) && (PDUR_FALSE == PDUR_TXBUFFER_USE_BUFFER(dstPduPtr)) )
    {
        PDUR_ASSERT(PDUR_TXBUFFER_DEPTH(dstPduPtr) > PDUR_DEPTH_IS_FIFO);
        /* (PduR-BUG-No.003) */
        /* Check the configuration information for errors. */
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( (NULL_PTR == &PDUR_TXBUFFER_PDU(dstPduPtr, PDUR_IDX_0)) || (NULL_PTR == PDUR_TXBUFFER_PDU_DATE(dstPduPtr, PDUR_IDX_0)) )
        {
            retVal = BUFREQ_E_OVFL;
            /* Report Det err. */
            PDUR_REPORT_DET_ERROR(PDUR_SID_TP_BUF_ALLOC, PDUR_E_CONFIG_PARAM_ERROR)
        }
        /* Req: SWS_PduR_00797 */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
        if( (BUFREQ_OK == retVal) && (TpSduLength <= PDUR_TXBUFFER_MAXLEN(dstPduPtr)) )
        {
            /* Use a dedicated buffer. */
            PDUR_TXBUFFER_USE_BUFFER(dstPduPtr) = PDUR_TRUE;
            /* Set the requested buffer length. */
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            PDUR_TXBUFFER_ALLOC_SIZE(dstPduPtr) = TpSduLength;
            /* Clear len. */
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            PDUR_TXBUFFER_PDU_LEN(dstPduPtr, PDUR_IDX_0) = (PduLengthType)PDUR_INIT_0;
            useExBuf = PDUR_FALSE;
        }
        else
        {
            /* Use global buffers. */
            useExBuf = PDUR_TRUE;
        }
    }
    /* Req: SWS_PduR_00798 */
    if( (BUFREQ_OK == retVal) && (PDUR_TRUE == useExBuf) )
    {
        /* Check if there is enough free space in the buffer. */
        retVal = PduR_TP_BufferIsFull(id, TpSduLength, dstPduPtr, allocNode);
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: PduR_TpOnTheFly
*
* Explanation: Determine whether it is an on-the-fly gateway function PDU.
*
* param: dstPduPtr -> Pointers to routing information.
*        pduInfo -> Pointer to the transmission of the pdu data.
*
* retval: None.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC(Std_ReturnType, PDUR_CODE) PduR_TpOnTheFly
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) sendPduInfo
)
{
    Std_ReturnType retVal = PDUR_E_OK;

    /* Is on-the-fly gatewaying? */
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
    if( PDUR_TP_THRESHOLD_INVALID != dstPduPtr->PduRTpThreshold )
    {
        /* SWS_PduR_00317 ;*/
        if( dstPduPtr->PduRTpThreshold <= sendPduInfo->SduLength )
        {
            /* Reset tp threshold flag. */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" PolySpace +1 MISRA-C3:20.7 [Justified:Unset] "NSCA_Polyspace_PduR_20.7" */
            PDUR_DST_PDU_THR_LIST(dstPduPtr->PduRDestPduIdx).pduRTpThrFlag = PDUR_FALSE;
            /* SWS_PduR_00317 */
            /* The PDU Router module shall start the TP transmission on the destination bus by calling
                <DstLoTp>_Transmit as soon as the Tx threshold has been reached for the specific destination.
            */
            retVal = PduR_Route_LoTransmit(dstPduPtr, sendPduInfo);
        }
        else
        {
            /* Set the start threshold calculation flag. */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" PolySpace +1 MISRA-C3:20.7 [Justified:Unset] "NSCA_Polyspace_PduR_20.7" */
            PDUR_DST_PDU_THR_LIST(dstPduPtr->PduRDestPduIdx).pduRTpThrFlag = PDUR_TRUE;
        }
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: PduR_TP_StartOfCopyData
*
* Explanation: Used for function PduR_LoTpStartOfReception () to copy data.
*
* param: id -> PduR module pdu ID.
*        dstPduPtr -> Pointers to routing information.
*        pduInfo -> Pointer to the transmission of the pdu data.
*        bufferSizePtr(out) -> Available receive buffer after data has been copied.
*
* retval: None.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC(void, PDUR_CODE) PduR_TP_StartOfCopyData
(
    PduIdType id,
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfo,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    Std_ReturnType err = PDUR_E_NOT_OK;
    PduR_TpBuffer_Type* tpBufPtr;
    PduInfoType txPduInfo;

    txPduInfo.SduDataPtr = NULL_PTR;
    txPduInfo.SduLength = (PduLengthType)PDUR_INIT_0;

    /* No meateData. */
    if( NULL_PTR != pduInfo )
    {
        /* Has an exclusive buffer been used? && Use a dedicated buffer? */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( (NULL_PTR != dstPduPtr->PduRDestTxBufferRef) && (PDUR_TRUE == PDUR_TXBUFFER_USE_BUFFER(dstPduPtr)) )
        {
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            err = PduR_MemCopy(PDUR_TXBUFFER_PDU_DATE(dstPduPtr, PDUR_IDX_0), pduInfo->SduDataPtr, pduInfo->SduLength);
            PDUR_ASSERT(PDUR_E_NOT_OK == err);
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            PDUR_TXBUFFER_PDU_LEN(dstPduPtr, PDUR_IDX_0) += pduInfo->SduLength;
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            txPduInfo.SduDataPtr = PDUR_TXBUFFER_PDU_DATE(dstPduPtr, PDUR_IDX_0);
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
            txPduInfo.SduLength = PDUR_TXBUFFER_PDU_LEN(dstPduPtr, PDUR_IDX_0);
            /* Returns the number of bytes remaining in the buffer. */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
            *bufferSizePtr = (PDUR_TXBUFFER_ALLOC_SIZE(dstPduPtr) - PDUR_TXBUFFER_PDU_LEN(dstPduPtr, PDUR_IDX_0));
        }
        else
        {
            /* Use public buffers. */
            tpBufPtr = PduR_TP_GetTpBuffer(id);
            if( NULL_PTR != tpBufPtr )
            {
                /* SduLength is valid? */
                if( pduInfo->SduLength > (PduLengthType)PDUR_INIT_0 )
                {
                    /* Copy data. */
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                    err = PduR_MemCopy(&PDUR_TP_BUFFER(tpBufPtr)[tpBufPtr->copyRxPointer], pduInfo->SduDataPtr, pduInfo->SduLength);
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                    tpBufPtr->copyRxPointer += pduInfo->SduLength;

                    /* Whether there is only one node */
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                    if( tpBufPtr->firstNodePointer == tpBufPtr->lastNodePointer )
                    {
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                        txPduInfo.SduDataPtr = &PDUR_TP_BUFFER(tpBufPtr)[tpBufPtr->lastNodePointer + PDUR_TP_NODE_BASE_SIZE];
                        txPduInfo.SduLength = tpBufPtr->copyRxPointer - tpBufPtr->lastNodePointer - PDUR_TP_NODE_BASE_SIZE;
                    }
                }
                PDUR_ASSERT(PDUR_E_NOT_OK == err);
                /* Set the buffer status to busy. */
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
                tpBufPtr->bufStatus |= (uint8)PDUR_BUFFER_RX_BUSY;
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                *bufferSizePtr = tpBufPtr->lastNodePointer + PDUR_TP_NODE_BASE_SIZE + tpBufPtr->allocBufLen - tpBufPtr->copyRxPointer;
            }
        }
        /* Check whether the threshold can be met. */
        if( PDUR_E_OK == err )
        {
            err = PduR_TpOnTheFly(dstPduPtr, (const PduInfoType* )&txPduInfo);
        }
    }
    else
    {
        /* Other modules are not yet supported. */
    }

    /* Eliminate the warning. */
    if( PDUR_E_OK == err )
    {
        PDUR_UNUSED(err);
    }
}

/*
********************************************************************************
* Function Name: PduR_TP_CopyRxDataEachDest
*
* Explanation: Implement the gateway function to copy the received data to all
*              destination buffers.
*
* param: id -> Identification of the received I-PDU.
*        dstPduPtr -> Pointers to routing information.
*        pduInfo -> Pointer to the transmission of the pdu data.
*        bufferSizePtr(out) -> Available receive buffer after data has been copied.
*        isCopyTxData(in\out) -> The data will not be copied multiple times in a cycle.
*
* retval: BUFREQ_OK: Data has been copied to the transmit buffer completely as requested.
*         BUFREQ_E_BUSY: Request could not be fulfilled, because the required
*                        amount of Tx data is not available.
*                        The lower layer module may retry this call later on.
*                        No data has been copied.
*         BUFREQ_E_NOT_OK: Data has not been copied. Request failed.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_TP_CopyRxDataEachDest
(
    PduIdType id,
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfo,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr,
    P2VAR(boolean, AUTOMATIC, PDUR_APPL_DATA) isCopyTxData
)
{
    Std_ReturnType err;
    PduLengthType pduLen;
    BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;
    PduR_TpBuffer_Type* tpBufPtr;
    PduInfoType txPduInfo;

    txPduInfo.SduDataPtr = NULL_PTR;
    txPduInfo.SduLength = (PduLengthType)PDUR_INIT_0;

    /* Use a dedicated buffer. */
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
    if( (NULL_PTR != dstPduPtr->PduRDestTxBufferRef) && (PDUR_TRUE == PDUR_TXBUFFER_USE_BUFFER(dstPduPtr)) )
    {
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        pduLen = PDUR_TXBUFFER_PDU_LEN(dstPduPtr, PDUR_IDX_0);
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
        if( (pduLen + pduInfo->SduLength) <= PDUR_TXBUFFER_ALLOC_SIZE(dstPduPtr) )
        {
            retVal = BUFREQ_OK;
        }
        /* Is there enough buffer? */
        if( BUFREQ_OK == retVal )
        {
            /* Req: SWS_PduR_00740 */
            if( pduInfo->SduLength > (PduLengthType)PDUR_INIT_0 )
            {
                /* Copy data. */
                /* Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                err = PduR_MemCopy(&PDUR_TXBUFFER_PDU_DATE(dstPduPtr, PDUR_IDX_0)[pduLen],
                                      pduInfo->SduDataPtr, pduInfo->SduLength);
                PDUR_ASSERT(PDUR_E_NOT_OK == err);
                /* No err. */
                if( PDUR_E_OK == err )
                {
                    /* Set return value. */
                    retVal = BUFREQ_OK;
                }
            }
            /* Move pointer. */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            PDUR_TXBUFFER_PDU_LEN(dstPduPtr, PDUR_IDX_0) += pduInfo->SduLength;
            /* Returns the number of bytes remaining in the buffer. */
            /* SWS_PduR_00740
               If the transport protocol module calls PduR_<LoTp>CopyTxData or PduR_<LoTp>CopyRxData with length
               zero (PduInfoType.SduLength = 0) the PDU Router module shall return the size of the current available
               buffer or the current available data respectively.
            */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            *bufferSizePtr = (PDUR_TXBUFFER_ALLOC_SIZE(dstPduPtr) - PDUR_TXBUFFER_PDU_LEN(dstPduPtr, PDUR_IDX_0));
            /* Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            txPduInfo.SduDataPtr = PDUR_TXBUFFER_PDU_DATE(dstPduPtr, PDUR_IDX_0);
            txPduInfo.SduLength = PDUR_TXBUFFER_PDU_LEN(dstPduPtr, PDUR_IDX_0);
        }
    }
    /* Use public buffers. */
    else
    {
        tpBufPtr = PduR_TP_GetTpBuffer(id);
        if( (NULL_PTR != tpBufPtr) && (PDUR_FALSE == *isCopyTxData) )
        {
            /* The data will not be copied multiple times in a cycle. */
            /* Set the flag of the copied data. */
            *isCopyTxData = PDUR_TRUE;
            /* Calculate the length of the data that has been copied. */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            pduLen = tpBufPtr->copyRxPointer;
            /* Check whether the buffer is sufficient. */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
            if( (pduLen + pduInfo->SduLength) <= (tpBufPtr->lastNodePointer + PDUR_TP_NODE_BASE_SIZE + tpBufPtr->allocBufLen) )
            {
                retVal = BUFREQ_OK;
            }
            /* Is there enough buffer? */
            if( BUFREQ_OK == retVal )
            {
                /* Req: SWS_PduR_00740 */
                if( pduInfo->SduLength > (PduLengthType)PDUR_INIT_0 )
                {
                    /* Copy data. */
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                    err = PduR_MemCopy(&PDUR_TP_BUFFER(tpBufPtr)[tpBufPtr->copyRxPointer], pduInfo->SduDataPtr, pduInfo->SduLength);
                    PDUR_ASSERT(PDUR_E_NOT_OK == err);
                    /* Move the buffer pointer. */
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                    tpBufPtr->copyRxPointer += pduInfo->SduLength;
                    /* No err. */
                    if( PDUR_E_OK == err )
                    {
                        /* Set return value. */
                        retVal = BUFREQ_OK;
                    }
                }
                /* Set the buffer status to busy. */
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                tpBufPtr->bufStatus |= (uint8)PDUR_BUFFER_RX_BUSY;
                /* Returns the number of bytes remaining in the buffer. */
                /* SWS_PduR_00740
                   If the transport protocol module calls PduR_<LoTp>CopyTxData or PduR_<LoTp>CopyRxData with length
                   zero (PduInfoType.SduLength = 0) the PDU Router module shall return the size of the current available
                   buffer or the current available data respectively.
                */
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                *bufferSizePtr = tpBufPtr->lastNodePointer + PDUR_TP_NODE_BASE_SIZE + tpBufPtr->allocBufLen - tpBufPtr->copyRxPointer;

                /* Whether there is only one node */
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                if( tpBufPtr->firstNodePointer == tpBufPtr->lastNodePointer )
                {
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                    txPduInfo.SduDataPtr = &PDUR_TP_BUFFER(tpBufPtr)[tpBufPtr->lastNodePointer + PDUR_TP_NODE_BASE_SIZE];
                    txPduInfo.SduLength = tpBufPtr->copyRxPointer - tpBufPtr->lastNodePointer - PDUR_TP_NODE_BASE_SIZE;
                }
            }
        }
    }
    /* Check whether the threshold can be met. */
    if( BUFREQ_OK == retVal )
    {
        err = PduR_TpOnTheFly(dstPduPtr, (const PduInfoType* )&txPduInfo);
        /* Set return value. */
        if( PDUR_E_OK != err )
        {
            retVal = BUFREQ_E_NOT_OK;
        }
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: PduR_TP_GatewayRouteTransmit
*
* Explanation: The direct gateway starts the sending function.
*
* param: dstPduPtr -> Pointer to the destination PDU information.
*
* retval: PDUR_E_NOT_OK -> No buffer was found or transmission failed.
*         PDUR_E_OK -> The transmission was successful.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC(Std_ReturnType, PDUR_CODE) PduR_TP_GatewayRouteTransmit
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr
)
{
    Std_ReturnType retVal = PDUR_E_OK;
    PduR_TpBuffer_Type* tpBufPtr = NULL_PTR;
    PduInfoType pduInfo = {
        NULL_PTR, (PduLengthType)PDUR_INIT_0
        /* PolySpace +1 MISRA-C3:9.3 [Justified:Unset] "NSCA_Polyspace_PduR_9.3" */
    };

    /* Use a dedicated buffer. */
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
    if( (NULL_PTR != dstPduPtr->PduRDestTxBufferRef) && (PDUR_TRUE == PDUR_TXBUFFER_USE_BUFFER(dstPduPtr)) )
    {
        /* The CanTp gateway message needs to be processed separately.
           Subsequent updates should not be handled in this way. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        pduInfo.SduLength = PDUR_TXBUFFER_PDU(dstPduPtr, PDUR_IDX_0).SduLength;
    }
    else
    {
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
        tpBufPtr = PduR_TP_GetTpBuffer(dstPduPtr->PduRRoutPathRefId);
        if( NULL_PTR != tpBufPtr )
        {
            /* Whether there is only one node */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            if( tpBufPtr->firstNodePointer == tpBufPtr->lastNodePointer )
            {
                /* The CanTp gateway message needs to be processed separately.
                   Subsequent updates should not be handled in this way. */
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                pduInfo.SduLength = tpBufPtr->copyRxPointer - tpBufPtr->firstNodePointer - PDUR_TP_NODE_BASE_SIZE;
            }
            else
            {
                /* PolySpace +1 DEFECT:UINT_CONSTANT_OVFL[Justified:Unset] "NSCA_Polyspace_PduR_UINT_CONSTANT_OVFL" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                tpBufPtr->bufStatus &= (uint8)(~(uint8)PDUR_BUFFER_RX_BUSY); 
                retVal = PDUR_E_NOT_OK;
            }
        }
        /* Can't find the buffer? */
        else
        {
            retVal = PDUR_E_NOT_OK;
        }
    }
    /* Can't find the buffer? */
    if( PDUR_E_OK == retVal )
    {
        /* The <DstLoTp>_Transmit shall be called on each destination transport protocol
           module within the PduR_<SrcLoTp>TpRxIndication, if result is E_OK.
        */
        retVal = PduR_Route_LoTransmit(dstPduPtr, &pduInfo);

        /* If the lower layer fails to send, clear the buffer usage flag and release the buffer. */
        if( (PDUR_E_NOT_OK == retVal) && (NULL_PTR != tpBufPtr) )
        {
            /* Find the position of the destination PDU in the mask */
            /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_PduR_UNMODIFIED_VAR_NOT_CONST" */
            uint16 pos = PduR_TP_FindDstPduPos(dstPduPtr);
            
            /* Clear flag at pos from the mask */
            /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_PduR_SHF" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
            PDUR_DST_PDU_CLEAR_MASK(tpBufPtr, pos);
             /* Clear flag at pos from the saved mask */
             /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
            PDUR_DST_PDU_CLEAR_MASK_SAVE(tpBufPtr, pos);
             
            if( (PduRMultiCastType)PDUR_INIT_0 == tpBufPtr->dstPduMaskSave )
            {
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
                tpBufPtr->usedId = PDUR_IDLE_BUFFER_ID;
                tpBufPtr->bufStatus = (uint8)PDUR_BUFFER_FREE;
            }
        }
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: PduR_TP_FindDstPduPos
*
* Explanation: Find the location of the specified destination PDU in the routing path.
*
* param: dstPduPtr -> Pointer to the destination PDU information.
*
* retval: position.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC(uint16, PDUR_CODE) PduR_TP_FindDstPduPos
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr
)
{
    uint16 pos = (uint16)PDUR_INIT_0;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_PduR_UNMODIFIED_VAR_NOT_CONST" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
    const PduRRoutingPath_Type* routPathPtr = PDUR_ROUTING_PATH(dstPduPtr->PduRRoutPathRefId);

    /* Loop to find the location of the destination PDU. */
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
    while( dstPduPtr != routPathPtr->PduRDestPdu[pos] )
    {
        /* Move pointer. */
        pos++;
    }

    return pos;
}

/*
********************************************************************************
* Function Name: PduR_TP_GateWayCopyTxData
*
* Explanation: Handle the gateway function of the transfer protocol function
*              PduR_LoTpCopyTxData ().
*
* param: dstPduPtr -> Pointer to the destination PDU information.
*        pduInfo -> Pointer to the transmission of the pdu data.
*        retry -> This parameter is used to acknowledge transmitted data or to
*                 retransmit data after transmission problems.
*        availableDataPtr(out) -> Indicates the remaining number of bytes that
*                          are available in the upper layer module's Tx buffer.
*
* retval: BUFREQ_OK: Data has been copied to the transmit buffer completely as requested.
*         BUFREQ_E_BUSY: Request could not be fulfilled, because the required
*                        amount of Tx data is not available.
*                        The lower layer module may retry this call later on.
*                        No data has been copied.
*         BUFREQ_E_NOT_OK: Data has not been copied. Request failed.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC(BufReq_ReturnType, PDUR_CODE) PduR_TP_GateWayCopyTxData
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfo,
    P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_CONST) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
    Std_ReturnType err = E_NOT_OK;
    uint16 pos;
    BufReq_ReturnType retVal = BUFREQ_OK;
    PduR_TpBuffer_Type* tpBufPtr;
    PduLengthType availableDataSize;

    /* Check if it is single frame data. */
    /* Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
    if( (NULL_PTR != dstPduPtr->PduRDestTxBufferRef) &&
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        (NULL_PTR != PDUR_TXBUFFER_TXBUF(dstPduPtr)) &&
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
        (PDUR_TRUE == PDUR_TXBUFFER_USE_BUFFER(dstPduPtr))
       )
    {
        /* Req: SWS_PduR_00697 */
        if( (NULL_PTR == retry) || ((TP_CONFPENDING == retry->TpDataState) || (TP_DATACONF == retry->TpDataState)) )
        {
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
            if( (dstPduPtr->PduRDestTxBufferRef->PduRPduMaxLength < pduInfo->SduLength) ||
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                (PDUR_TXBUFFER_PDU_LEN(dstPduPtr, PDUR_IDX_0) < pduInfo->SduLength) )
            {
                /*  If not enough data is avilalble, the Pdu Router shall return
                    BUFREQ_E_BUSY without copying any data. */
                retVal = BUFREQ_E_BUSY;
            }
            /* There is enough space. */
            else
            {
                /* Req: SWS_PduR_00740 */
                if( (PduLengthType)PDUR_INIT_0 < pduInfo->SduLength )
                {
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                    err = PduR_MemCopy(pduInfo->SduDataPtr, PDUR_TXBUFFER_PDU_DATE(dstPduPtr, PDUR_IDX_0), pduInfo->SduLength);
                    PDUR_ASSERT(PDUR_E_NOT_OK == err);
                    /* Eliminate the warning. */
                    PDUR_UNUSED(err);
                }
                /* Gets the number of remaining bytes available. */
                /* This situation is generally a single frame of data, the remaining length is 0. */
                /* SWS_PduR_00740
                   If the transport protocol module calls PduR_<LoTp>CopyTxData or PduR_<LoTp>CopyRxData with length
                   zero (PduInfoType.SduLength = 0) the PDU Router module shall return the size of the current available
                   buffer or the current available data respectively.
                */
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
                *availableDataPtr = PDUR_TXBUFFER_PDU_LEN(dstPduPtr, PDUR_IDX_0) - pduInfo->SduLength;
            }
        }
        /* Req: SWS_PduR_00705 */
        else if( TP_DATARETRY == retry->TpDataState )
        {
            /* If set to true this means that the destination transport protocol module will
               use the retransmission feature. This parameter might be set to false if the
               retransmission feature is not used, even though the destination transport
               protocol is supporting it. */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            if( PDUR_TRUE == PDUR_MODULE_RETRY(dstPduPtr) )
            {
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                if( (dstPduPtr->PduRDestTxBufferRef->PduRPduMaxLength - retry->TxTpDataCnt) < pduInfo->SduLength )
                {
                    /* If not enough data is avilalble, the Pdu Router shall return
                    BUFREQ_E_BUSY without copying any data. */
                    retVal = BUFREQ_E_BUSY;
                }
                /* There is enough space. */
                else
                {
                    /* Req: SWS_PduR_00740 */
                    if( (PduLengthType)PDUR_INIT_0 < pduInfo->SduLength )
                    {
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                        err = PduR_MemCopy(pduInfo->SduDataPtr, PDUR_TXBUFFER_PDU_DATE(dstPduPtr, PDUR_IDX_0), pduInfo->SduLength);
                        PDUR_ASSERT(PDUR_E_NOT_OK == err);
                        /* Eliminate the warning. */
                        PDUR_UNUSED(err);
                    }
                    /* Gets the number of remaining bytes available. */
                    /* This situation is generally a single frame of data, the remaining length is 0. */
                    /* SWS_PduR_00740
                    If the transport protocol module calls PduR_<LoTp>CopyTxData or PduR_<LoTp>CopyRxData with length
                    zero (PduInfoType.SduLength = 0) the PDU Router module shall return the size of the current available
                    buffer or the current available data respectively.
                    */
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                    *availableDataPtr = (PDUR_TXBUFFER_PDU_LEN(dstPduPtr, PDUR_IDX_0) - pduInfo->SduLength);
                }
            }
        }
        else
        /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Common_Unreachable " */
        {
            /* Req: SWS_PDUR_00814 */
            retVal = BUFREQ_E_BUSY;
        }
    }
    /* multi-frame. */
    else
    {
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
        tpBufPtr = PduR_TP_GetTpBuffer(dstPduPtr->PduRRoutPathRefId);
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
        if( (tpBufPtr != NULL_PTR) && (tpBufPtr->copyRxPointer != (tpBufPtr->firstNodePointer + PDUR_TP_NODE_BASE_SIZE)) )
        {
            if( (PduLengthType)PDUR_INIT_0 == pduInfo->SduLength )
            {
                *availableDataPtr = PduR_TP_Buffer_AvailableSize(tpBufPtr);
            }
            /* Req: SWS_PDUR_00813 */
            else if( (NULL_PTR == retry) || ((TP_CONFPENDING == retry->TpDataState) || (TP_DATACONF == retry->TpDataState)) )
            {
                /* Move the buffer pointer position. */
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                if( (PduRMultiCastType)PDUR_INIT_0 == tpBufPtr->dstPduMask )
                {
                    /* Reinitialize the number of dynamic destinations. */
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                    tpBufPtr->dstPduMask = tpBufPtr->dstPduMaskSave;
                    /* Move the buffer pointer. */
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                    tpBufPtr->copyTxPointer += tpBufPtr->lastTxPduLength;
                    /* Reset the last copied pdu length */
                    tpBufPtr->lastTxPduLength = (PduLengthType)PDUR_INIT_0;
                }

                pos = PduR_TP_FindDstPduPos(dstPduPtr);
                /* Req: SWS_PDUR_00814
                If not enough data is availalble or not all other destination transport protocoll
                modules have called PduR_<DstLoTp>CopyTxData for the previous frame, the Pdu Router
                shall return BUFREQ_E_BUSY without copying any data.
                */
                availableDataSize = PduR_TP_Buffer_AvailableSize(tpBufPtr);

                if( (availableDataSize < pduInfo->SduLength) ||
                    /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_PduR_SHF" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                    ((!PDUR_DST_PDU_IS_VALID(tpBufPtr, pos)) && (tpBufPtr->dstPduMaskSave != PDUR_INIT_0))
                )
                {
                    /* If not enough data is avilalble, the Pdu Router shall return
                    BUFREQ_E_BUSY without copying any data. */
                    retVal = BUFREQ_E_BUSY;
                }
                else
                {
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                    err = PduR_MemCopy(pduInfo->SduDataPtr, &PDUR_TP_BUFFER(tpBufPtr)[tpBufPtr->copyTxPointer], pduInfo->SduLength);
                    PDUR_ASSERT(PDUR_E_NOT_OK == err);
                    /* Eliminate the warning. */
                    PDUR_UNUSED(err);
                    /* SWS_PduR_00740
                        If the transport protocol module calls PduR_<LoTp>CopyTxData or PduR_<LoTp>CopyRxData with length
                        zero (PduInfoType.SduLength = 0) the PDU Router module shall return the size of the current available
                        buffer or the current available data respectively.
                    */
                    tpBufPtr->lastTxPduLength = pduInfo->SduLength;
                    *availableDataPtr = availableDataSize - tpBufPtr->lastTxPduLength;

                    /* Clear the mask only if the buffer is not empty */
                    if( (PduLengthType)PDUR_INIT_0 != *availableDataPtr )
                    {
                        /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_PduR_SHF" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                        PDUR_DST_PDU_CLEAR_MASK(tpBufPtr, pos);
                    }
                }
            }
            /* Req: SWS_PDUR_00815 */
            else
            {
                retVal = BUFREQ_E_NOT_OK;
            }
        }
        else
        {
            /* Set return value, The buffer is empty. */
            retVal = BUFREQ_E_NOT_OK;
        }
    }
    /* SWS_PduR_00707
       If PduR_<DstLoTp>CopyTxData is called with TpDataState TP_DATACONF or if the
       RetryInfoType pointer is NULL, the PDU Router shall copy SduLength bytes of data.
    */
    /* SWS_PduR_00696
       If PduR_<DstLoTp>CopyTxData is called and state is TP_DATACONF then the PDU
       Router may free the already copied data.
    */
    if( BUFREQ_OK == retVal )
    {
        if( (NULL_PTR != retry) && (TP_DATACONF == retry->TpDataState) )
        {
            PduR_TP_GetWayTxConfirmation(dstPduPtr, PDUR_E_OK);
        }
    }
    if( PDUR_E_OK == err )
    {
        PDUR_UNUSED(err);
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: PduR_TP_GetWayTxConfirmation
*
* Explanation: Called by the Pdu module function PduR_LoTpTxConfirmation () to
*              handle the gateway function.
*
* param: dstPduPtr -> Pointer to the destination PDU information.
*        result -> Result of the transmission of the I-PDU.
*
* retval: None.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC(void, PDUR_CODE) PduR_TP_GetWayTxConfirmation
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    Std_ReturnType result
)
{
    boolean isGateWayRouting = FALSE;
    uint16 pos;
    PduR_TpBuffer_Type* tpBufPtr;
    Std_ReturnType retVal = PDUR_E_OK;
    PduLengthType dataLength = (PduLengthType)PDUR_INIT_0;
    const PduRRoutingPath_Type* routPathPtr = NULL_PTR;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_PduR_UNMODIFIED_VAR_NOT_CONST" */
    uint16 curPartitionId = PDUR_INIT_0;
    PduInfoType pduInfo;

    PDUR_UNUSED(result);

#if (STD_ON == PDUR_SUPPORT_MULTICORE)
    curPartitionId = PDUR_CURRENT_PARTITION;
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */

    /* Check if it is single frame data. */
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
    if( (NULL_PTR != dstPduPtr->PduRDestTxBufferRef) && (PDUR_TRUE == PDUR_TXBUFFER_USE_BUFFER(dstPduPtr)) )
    {
        PDUR_TXBUFFER_USE_BUFFER(dstPduPtr) = PDUR_FALSE;
    }
    /* Multi-frame. */
    else
    {
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
        tpBufPtr = PduR_TP_GetTpBuffer(dstPduPtr->PduRRoutPathRefId);
        if( NULL_PTR != tpBufPtr )
        {
            pos = PduR_TP_FindDstPduPos(dstPduPtr);
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_PduR_SHF" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
            PDUR_DST_PDU_CLEAR_MASK(tpBufPtr, pos);
            /* When the last call is completed, the buffer is released. */
            if( (PduRMultiCastType)PDUR_INIT_0 == tpBufPtr->dstPduMask )
            {
                /* Whether there is only one node */
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                if( (tpBufPtr->firstNodePointer == tpBufPtr->lastNodePointer)
                    || (PDUR_E_NOT_OK == result) )
                {
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
                    tpBufPtr->usedId = PDUR_IDLE_BUFFER_ID;
                    tpBufPtr->bufStatus = (uint8)PDUR_BUFFER_FREE;
                    tpBufPtr->dstPduMaskSave = (PduRMultiCastType)PDUR_INIT_0;
                    tpBufPtr->copyRxPointer = (PduLengthType)PDUR_INIT_0;
                    tpBufPtr->copyTxPointer = (PduLengthType)PDUR_INIT_0;
                    tpBufPtr->firstNodePointer = (PduLengthType)PDUR_INIT_0;
                    tpBufPtr->lastNodePointer = (PduLengthType)PDUR_INIT_0;
                    tpBufPtr->usedBufferLength = (PduLengthType)PDUR_INIT_0;
                }
                else
                {
                    /* Get data length of the current node */
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                    (void) PduR_MemCopy((uint8*)&dataLength, &PDUR_TP_BUFFER(tpBufPtr)[tpBufPtr->firstNodePointer], PDUR_TP_NODE_BASE_SIZE);  /* PRQA S 0310 */ /* NSCA_QAC_PduR_Rule11.3 */

                    /* Move first node pointer to the next */
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                    tpBufPtr->firstNodePointer += PDUR_TP_NODE_BASE_SIZE + dataLength;

                    /* If the end of the buffer is reached */
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                    if( tpBufPtr->firstNodePointer == tpBufPtr->usedBufferLength )
                    {
                        /* Move first node pointer to the head of buffer */
                        tpBufPtr->firstNodePointer = (PduLengthType)PDUR_INIT_0;
                        /* Reset the actual used buffer length */
                        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                        tpBufPtr->usedBufferLength = tpBufPtr->lastNodePointer + PDUR_TP_NODE_BASE_SIZE + tpBufPtr->allocBufLen;
                    }

                    /* Move the buffer pointer. */
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                    tpBufPtr->copyTxPointer = tpBufPtr->firstNodePointer + PDUR_TP_NODE_BASE_SIZE;
                    /* Reinitialize the number of dynamic destinations for the next call. */
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                    tpBufPtr->dstPduMask = tpBufPtr->dstPduMaskSave;

                    /* If this is the last node */
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                    if( tpBufPtr->firstNodePointer == tpBufPtr->lastNodePointer )
                    {
                        /* The data to be sent is not ready */
                        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" PolySpace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" PolySpace +1 MISRA-C3:10.4 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
                        if( PDUR_BUFFER_RX_BUSY == (tpBufPtr->bufStatus & PDUR_BUFFER_RX_BUSY) )  /* PRQA S 1881, 4522 */ /* NSCA_QAC_Common_Unreachable */
                        {
                            retVal = PDUR_E_NOT_OK;
                        }

                        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                        if( (tpBufPtr->firstNodePointer + PDUR_TP_NODE_BASE_SIZE) == tpBufPtr->copyRxPointer )
                        {
                            retVal = PDUR_E_NOT_OK;
                        }
                    }

                    if( PDUR_E_OK == retVal )
                    {
                        /* Get data length of the current node */
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                        (void) PduR_MemCopy((uint8*)&dataLength, &PDUR_TP_BUFFER(tpBufPtr)[tpBufPtr->firstNodePointer], PDUR_TP_NODE_BASE_SIZE);  /* PRQA S 0310 */ /* NSCA_QAC_PduR_Rule11.3 */

                        pduInfo.SduDataPtr = NULL_PTR;
                        pduInfo.SduLength = dataLength;

                        /* Get the routing path pointed to. */
                        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                        routPathPtr = PDUR_ROUTING_PATH(dstPduPtr->PduRRoutPathRefId);
                        isGateWayRouting = PduR_RoutingPath_IsGateway(routPathPtr);

                        /* If the routing path is a gateway, the data is first forwarded to the upper-layer module */
                        if( PDUR_TRUE == isGateWayRouting )
                        {
                            const uint16 tpDstPduNum = PduR_GetTpDstPdusOfPartition(routPathPtr, curPartitionId);
                            /* Count the number of destinations in the routing path. */
                            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                            for( pos = (uint16)PDUR_IDX_0; NULL_PTR != routPathPtr->PduRDestPdu[pos]; pos++ )
                            {
                                /* PolySpace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
                                dstPduPtr = routPathPtr->PduRDestPdu[pos];
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
                                /* If the destination partition is the same as the current partition */
                                if( curPartitionId == dstPduPtr->PduRPartitionRef )
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
                                {
                                    /* Check if the destination is a upper module */
                                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                                    if( PDUR_IS_UP_MODULE(dstPduPtr) && (PDUR_INIT_0 != tpDstPduNum) )
                                    {
                                        PduR_TP_GatewayUp(dstPduPtr);
                                    }
                                }
                            }
                        }

                        /* Count the number of destinations in the routing path. */
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                        for( pos = (uint16)PDUR_IDX_0; NULL_PTR != routPathPtr->PduRDestPdu[pos]; pos++ )
                        {
                            /* PolySpace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
                            dstPduPtr = routPathPtr->PduRDestPdu[pos];
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
                            /* If the destination partition is the same as the current partition */
                            if( curPartitionId == dstPduPtr->PduRPartitionRef )
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
                            {
                                /* Check if the destination is a TP module and if the TP buffer is used */
                                /* Polyspace +1 RTE:SHF [Justified:Unset] "NSCA_Polyspace_PduR_SHF" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                                if( PDUR_IS_TP_MODULE(dstPduPtr) && PDUR_DST_PDU_IS_VALID(tpBufPtr, pos) )
                                {
                                    /* Start transmit for the current node */
                                    retVal = PduR_Route_LoTransmit(dstPduPtr, &pduInfo);
                                }
                            }
                        }
                    }
                    if( PDUR_E_OK == retVal )
                    {
                        PDUR_UNUSED(retVal);
                    }
                }
            }
        }
    }
}

/*
********************************************************************************
* Function Name: PduR_TP_GatewayUp
*
* Explanation: Implement SWS_PduR_00789 requirements.
* (Synchronous)
*
* param: dstPduPtr -> Pointer to the destination PDU information.
*
* retval: None.
********************************************************************************
*/
PDUR_LOCAL_INLINE_CORE FUNC(void, PDUR_CODE) PduR_TP_GatewayUp
(
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr
)
{
    BufReq_ReturnType err;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.5" */
    PduLengthType bufSize = (PduLengthType)PDUR_INIT_0;
    const PduR_TpBuffer_Type* tpBufPtr;
    /* PolySpace +1 MISRA-C3:9.3 [Justified:Unset] "NSCA_Polyspace_PduR_9.3" */
    PduInfoType pduInfo = {NULL_PTR, (PduLengthType)PDUR_INIT_0};
    PduLengthType dataLength = (PduLengthType)PDUR_INIT_0;

    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
    tpBufPtr = (const PduR_TpBuffer_Type* )PduR_TP_GetTpBuffer(dstPduPtr->PduRRoutPathRefId);
    if( NULL_PTR != tpBufPtr )
    {
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        (void) PduR_MemCopy((uint8*)&dataLength, &PDUR_TP_BUFFER(tpBufPtr)[tpBufPtr->firstNodePointer], PDUR_TP_NODE_BASE_SIZE);  /* PRQA S 0310 */ /* NSCA_QAC_PduR_Rule11.3 */

        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        pduInfo.SduDataPtr = &PDUR_TP_BUFFER(tpBufPtr)[tpBufPtr->firstNodePointer + PDUR_TP_NODE_BASE_SIZE];
        pduInfo.SduLength = dataLength;
        /* [SWS_PduR_00789]
           In case of gatewaying, when a successful RxIndication is received by PduR from the
           lower layer, the module shall initiate a reception session for a configured upper
           layer destination: <UpTp>_StartOfReception, <UpTp>_CopyRxData, and
           <UpTp>_RxIndication will be called in this order.
        */
        err = PduR_Route_UpTpStartOfReception(dstPduPtr, &pduInfo, dataLength, &bufSize);
        /* When <UpTp>_StartOfReception returns BUFREQ_OK, but the available buffer is too small
           to receive the whole message, the PduR shall call <UpTp>_RxIndication with result = E_NOT_OK.
        */
        if( (BUFREQ_OK == err) && (bufSize < dataLength) )
        {
            /* Req: SWS_PduR_00790 SWS_PduR_00791 */
            PduR_Route_UpTpRxIndication(dstPduPtr, PDUR_E_NOT_OK);
        }
        else if( BUFREQ_OK == err )
        {
            err = PduR_Route_UpTpCopyRxData(dstPduPtr, &pduInfo, &bufSize);
            /* Req: SWS_PduR_00792 */
            if( BUFREQ_E_NOT_OK == err )
            {
                /* When <UpTp>_CopyRxData returns an err, the PduR shall
                   call <UpTp>_RxIndication with result = E_NOT_OK.
                */
                PduR_Route_UpTpRxIndication(dstPduPtr, PDUR_E_NOT_OK);
            }
            else
            {
                PduR_Route_UpTpRxIndication(dstPduPtr, PDUR_E_OK);
            }
        }
        else
        {
            /* Do nothing. */
        }
    }
}

/*
********************************************************************************
* Function Name: PduR_RoutingPath_IsGateway
*
* Explanation: Check if the routing path is a gateway.
* (Synchronous)
*
* param: routPathPtr -> Pointer to the routing path.
*
* retval: PDUR_TRUE -> Is a gateway.
*         PDUR_FALSE -> Not a gateway.
********************************************************************************
*/
static FUNC(boolean, PDUR_CODE) PduR_RoutingPath_IsGateway
(
    P2CONST(PduRRoutingPath_Type, AUTOMATIC, PDUR_APPL_CONST) routPathPtr
)
{
    boolean retVal = PDUR_FALSE;
    uint16 pos = (uint16)PDUR_IDX_0;
    const PduRDestPdu_Type* dstPduPtr = NULL_PTR;

    /* Check if the source is a TP module */
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
    if( PDUR_IS_TP_MODULE(routPathPtr->PduRSrcPdu) )
    {
        /* Count the number of destinations in the routing path. */
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        for( pos = (uint16)PDUR_IDX_0; NULL_PTR != routPathPtr->PduRDestPdu[pos]; pos++ )
        {
            dstPduPtr = routPathPtr->PduRDestPdu[pos];

            /* Check if the destination is a TP module */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            if( PDUR_IS_TP_MODULE(dstPduPtr) )
            {
                /* SWS_PDUR_00805 Has the destination PDU been enabled? */
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                if( (PDUR_INVALID_PATHGROUP_ID == dstPduPtr->PduRRoutingPathGroupIdRef) ||
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
                    (PDUR_TRUE == PduR_RoutingPathGroup[dstPduPtr->PduRRoutingPathGroupIdRef].PduRIsEnabledAtInit) )
                {
                    retVal = PDUR_TRUE;
                    break;
                }
            }
        }
    }

    return retVal;
}
#endif  /* #if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY)) */

#endif  /* #if (STD_ON == PDUR_SUPPORT_GETWAY) */
/*
********************************************************************************
* Function Name: PduR_GetTpDstPdusOfPartition
*
* Explanation: Gets the number of destination TP PDUs belonging to the specified
*              partition in the routing path.
* (Synchronous)
*
* param: routPathPtr -> Pointer to the routing path.
*        partitionId -> Id of the EcuC partition.
*
* retval: Number of destination TP PDUs.
********************************************************************************
*/
static FUNC(uint16, PDUR_CODE) PduR_GetTpDstPdusOfPartition
(
    P2CONST(PduRRoutingPath_Type, AUTOMATIC, PDUR_APPL_CONST) routPathPtr,
    const uint16 partitionId
)
{
    uint16 number = (uint16)PDUR_INIT_0;
    uint16 idx = (uint16)PDUR_IDX_0;
    uint16 unusedId = (uint16)PDUR_IDX_0;

    unusedId = partitionId;
    /* Count the number of destinations in the routing path. */
    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
    for( idx = (uint16)PDUR_IDX_0; NULL_PTR != routPathPtr->PduRDestPdu[idx]; idx++ )
    {
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( PDUR_IS_TP_MODULE(routPathPtr->PduRDestPdu[idx]) )
        {
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
            if( routPathPtr->PduRDestPdu[idx]->PduRPartitionRef == partitionId )
#endif
            {
                number++;
            }
        }
    }
    if( unusedId != PDUR_IDX_0 )
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Common_Unreachable " */
    {
        PDUR_UNUSED(unusedId);
    }

    return number;
}

#endif /* #if (STD_OFF == PDUR_ZERO_COST_OPERATION) */

#if (STD_ON == PDUR_DEV_ERROR_DETECT)
/*
********************************************************************************
* Function Name: PduR_Det_ErrorReport
*
* Explanation: Report err.
*
* param: apiID -> app id number.
*        errorID -> err id number.
*
* retval: None.
********************************************************************************
*/
static FUNC(void, PDUR_CODE) PduR_Det_ErrorReport(uint8 apiID, uint8 errorID)
{
    /* PduR_EnableCheck errorID. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Common_Unreachable " */
    if( PDUR_E_NO_ERROR != errorID )
    {
        (void)Det_ReportError(MODULE_ID_PDUR, PDUR_INSTANCE_ID, apiID, errorID);
    }
    /* nothing. */
}

/*
********************************************************************************
* Function Name: PduR_Det_ReportRuntimeError
*
* Explanation: Report runtime err.
*
* param: apiID -> app id number.
*        errorID -> err id number.
*
* retval: None.
********************************************************************************
*/
static FUNC(void, PDUR_CODE) PduR_Det_ReportRuntimeError(uint8 apiID, uint8 errorID)
{
    /* PduR_EnableCheck errorID. */
    /* Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Common_Unreachable " */
    if( PDUR_E_NO_ERROR != errorID )
    {
        (void)Det_ReportRuntimeError(MODULE_ID_PDUR, PDUR_INSTANCE_ID, apiID, errorID);
    }
    /* nothing. */
}
#endif  /* #if (STD_ON == PDUR_DEV_ERROR_DETECT) */

#if (STD_OFF == PDUR_ZERO_COST_OPERATION)

#if (STD_ON == PDUR_SUPPORT_GETWAY)
/*
********************************************************************************
* Function Name: PduR_InitBuffer
*
* Explanation: PduR init buffer.
*
* param: None.
*
* retval: None.
********************************************************************************
*/
static FUNC(void, PDUR_CODE) PduR_InitBuffer(void)
{
    /* Save temp param. */
    uint8 pduRTxBufferDepth;
    uint16 pduDepthIdx;
    uint32 txBufferIdx = (uint16)PDUR_INIT_0;
    uint32 maxTxBufferNumber;
    uint32 pduMaxLength;
    PduInfoType* pduInfoPtr;
    const PduRTxBuffer_Type* txBufferPtr;

    /* Check pointer. */
    /* Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
    if( NULL_PTR != PDUR_TX_BUFFER_TABLE() )
    {
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        txBufferPtr = PDUR_TX_BUFFER_TABLE()->PduRTxBufferPtr;
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
        maxTxBufferNumber = PDUR_TX_BUFFER_TABLE()->PduRMaxTxBufferNumber;
        PDUR_ASSERT(NULL_PTR == txBufferPtr);
        /* Loop init PduR_TxBufferStatusTable. */
        for( ; txBufferIdx < maxTxBufferNumber; txBufferIdx++ )
        {
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            pduRTxBufferDepth = txBufferPtr[txBufferIdx].PduRTxBufferDepth;
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
            pduMaxLength = txBufferPtr[txBufferIdx].PduRPduMaxLength;
            /* Assert. */
            PDUR_ASSERT(NULL_PTR == txBufferPtr[txBufferIdx].PduRTxBuffer);
            /* Loop init PduRTxBuffer. */
            for( pduDepthIdx = (uint8)PDUR_INIT_0; pduDepthIdx < pduRTxBufferDepth; pduDepthIdx++ )
            {
                /* Save temp pointer. */
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                pduInfoPtr = &txBufferPtr[txBufferIdx].PduRTxBuffer->pduInfo[pduDepthIdx];
                PDUR_ASSERT((NULL_PTR == pduInfoPtr) || (NULL_PTR == pduInfoPtr->SduDataPtr));
                /* Clear dest buffer. */
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                PduR_MemSet(pduInfoPtr->SduDataPtr, PDUR_INIT_0, pduMaxLength);
            }
        }
    }
}
#endif  /* #if (STD_ON == PDUR_SUPPORT_GETWAY) */

/*
********************************************************************************
* Function Name: PduR_CeckCfgValid
*
* Explanation: Check the configuration validity in the routing path. Generally,
*              it is enabled after the TP gateway function is enabled.
*
* param: routingPathRef -> Pointer to the routing path.
*
* retval: PDUR_E_OK: The configuration item is invalid and initialization will not succeed.
*         PDUR_E_NOT_OK: The configuration item is valid.
********************************************************************************
*/
static FUNC(Std_ReturnType, PDUR_CODE) PduR_CeckCfgValid
(
    P2CONST(PduRRoutingPath_Type, AUTOMATIC, PDUR_APPL_CONST) routingPathRef
)
{
    boolean isThr;
    Std_ReturnType retVal = PDUR_E_OK;
    uint16 idx;
    uint16 upModlCnt;
    uint16 dstPduIdx;
    const PduRDestPdu_Type* dstPduPtr;

    /* Traverse the entire routing table. */
    for( idx = (uint16)PDUR_INIT_0; idx < PDUR_ROUTING_PATH_CNT(); idx++ )
    {
        /* Reset the flag. */
        isThr = PDUR_FALSE;
        /* Clean up the counter. */
        upModlCnt = (uint16)PDUR_INIT_0;
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
        for( dstPduIdx = (uint16)PDUR_INIT_0; NULL_PTR != routingPathRef[idx].PduRDestPdu[dstPduIdx]; dstPduIdx++ )
        {
            dstPduPtr = routingPathRef[idx].PduRDestPdu[dstPduIdx];
            /* (PduR-BUG-No.008) */
            /* Is On-the-fly? */
            if( PDUR_TP_THRESHOLD_INVALID != dstPduPtr->PduRTpThreshold )
            {
                /* PduRTpThreshold already exists under this path? */
                if( PDUR_FALSE == isThr )
                {
                    /* PduRTpThreshold exists under this path. */
                    isThr = PDUR_TRUE;
#if (STD_ON == PDUR_SUPPORT_GETWAY)
                    /* SWS_PduR_00708: Using gatewaying on-the-fly only one destination transport protocol module is allowed. */
                    if( dstPduIdx >= PDUR_IDX_1 )
#endif  /* #if (STD_ON == PDUR_SUPPORT_GETWAY) */
                    {
                        /* An err occurred in the configuration item. */
                        retVal = PDUR_E_NOT_OK;
                    }
                }
                else
                {
                    /* An err occurred in the configuration item. */
                    retVal = PDUR_E_NOT_OK;
                }
            }
            /* Must ref module. */
            if( NULL_PTR == dstPduPtr->PduRModuleRef )
            {
                /* Set return value. */
                retVal = PDUR_E_NOT_OK;
            }
            /* Must ref module. */
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            if( NULL_PTR != routingPathRef[idx].PduRSrcPdu->PduRModuleRef )
            {
                /* Note: Does not support multicast reception. */
                /* The source is the lower layer (Tp)? */
                if( PDUR_IS_TP_MODULE(routingPathRef[idx].PduRSrcPdu) )
                {
                    /* The purpose is that the upper layer records the number of upper layers. */
                    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
                    if( PDUR_IS_UP_MODULE(dstPduPtr) )
                    {
                        /* Calculate the number of upper modules. */
                        upModlCnt++;
                    }
                    /* The number of upper modules is greater than 1? */
                    if( upModlCnt > PDUR_INIT_1 )
                    {
                        /* A routing path does not allow more than one upper module. */
                        retVal = PDUR_E_NOT_OK;
                    }
                }
            }
            else
            {
                /* Must ref module. */
                retVal = PDUR_E_NOT_OK;
            }
            /* Is not ok? */
            if( PDUR_E_NOT_OK == retVal )
            {
                /* If an err occurs, the loop is exited. */
                break;
            }
        }
        if( PDUR_E_NOT_OK == retVal )
        {
            /* If an err occurs, the loop is exited. */
            break;
        }
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: PduR_InitPBConfigParam
*
* Explanation: PduR init PBConfig data.
*
* param: ConfigPtr -> PBConfig data.
*
* retval: PDUR_E_OK : init PBConfigParam success.
*         PDUR_E_NOT_OK : init PBConfigParam failed.
********************************************************************************
*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_InitPBConfigParam  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    P2CONST(PduR_PBConfigType, AUTOMATIC, PDUR_APPL_CONST) ConfigPtr
)
{
    Std_ReturnType retVal;

    /* Set local routing table management variables. */
    PduR_PBcfgAdminPtr = ConfigPtr;
    /* Req: SWS_PduR_00308 */
    /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_PduR_TAINTED_PTR" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
    if( NULL_PTR != PDUR_ROUTING_TABLE() )
    {
        /* Check the configuration validity. */
        retVal = PduR_CeckCfgValid(PDUR_ROUTING_TABLE()->PduRRoutingPathRef);
    }
    else
    {
        retVal = PDUR_E_NOT_OK;
    }
    /* Set the destination PDU table. */
    if( (PDUR_E_OK != retVal) || (NULL_PTR == PDUR_DEST_PDU_LIST()) )
    {
        retVal = PDUR_E_NOT_OK;
    }

#if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY))
    /* No err? */
    if( PDUR_E_OK == retVal )
    {
        /* Init Tp buffer status. */
        retVal = PduR_TP_BufferInit();
    }
#endif  /* #if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY)) */

    /* No err? */
    if( PDUR_E_OK == retVal )
    {
        /* Init PduR_RoutingPathGroup. */
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        PduR_RoutingPathGroup = PDUR_ROUTING_PATH_GROUP();

#if (STD_ON == PDUR_SUPPORT_GETWAY)
        /* Req SWS_PduR_00645 Clear Buffer. */
        PduR_InitBuffer();
#endif  /* #if (STD_ON == PDUR_SUPPORT_GETWAY) */
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: PduR_SetPduRIsEnabledAtInit
*
* Explanation: PduR Set PduRIsEnabledAtInit.
*
* param: states -> PduRIsEnabledAtInit state.
*        groupId -> PduR routing path group Id.
*
* retval: E_OK: Set success.
*         E_NOT_OK: Set failed.
********************************************************************************
*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_SetPduRIsEnabledAtInit  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    boolean states,
    PduR_RoutingPathGroupIdType groupId
)
{
    Std_ReturnType retVal = PDUR_E_OK;
    /* Req: SWS_PduR_00648 SWS_PduR_00647. */
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
    PDUR_VALIDATE_GROUPID(PDUR_SERVICE_ID_ENABLE_ROUTING, groupId, retVal);
    if( PDUR_E_OK == retVal )
    {
        /* Entered the correct groupID? */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
        if( PduR_RoutingPathGroup[groupId].PduRRoutingPathGroupId == groupId )
        {
            /* Set New states. */
            /* Req: SWS_PduR_00715. */
            PduR_RoutingPathGroup[groupId].PduRIsEnabledAtInit = states;
        }
    }

    return retVal;
}

#if (STD_ON == PDUR_SUPPORT_GETWAY)
/*
********************************************************************************
* Function Name: PduR_SetRoutingGroupTxBufferDefault
*
* Explanation: PduR Set PduRRoutingPathGroup default values.
*
* param: groupId -> PduR routing path group Id.
*
* retval: None.
********************************************************************************
*/
FUNC(void, PDUR_CODE) PduR_SetRoutingGroupTxBufferDefault(PduR_RoutingPathGroupIdType groupId)  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    uint8 defValue;
    uint16 dstPduIdx = (uint16)PDUR_INIT_0;
    uint16 defValueIdx;
    uint32 bytePosition;
    PduInfoType* pduInfoPtr;
    const PduRDestPdu_Type* dstPduPtr;

    /* Setting default values. */
    /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.14" PolySpace +1 DEFECT:TAINTED_LOOP_BOUNDARY [Justified:Unset] "NSCA_Polyspace_PduR_TAINTED_LOOP_BOUNDARY" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
    while( NULL_PTR != PduR_RoutingPathGroup[groupId].destPduRef[dstPduIdx] )
    {
        dstPduPtr = PduR_RoutingPathGroup[groupId].destPduRef[dstPduIdx];
        /* (PduR-BUG-No.009) */
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( NULL_PTR != dstPduPtr->PduRDestTxBufferRef )
        {
            /* Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            if( (NULL_PTR != dstPduPtr->PduRDefaultValue) &&
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                (NULL_PTR != PDUR_TXBUFFER_TXBUF(dstPduPtr)) &&
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                (PDUR_DEPTH_IS_FIFO == PDUR_TXBUFFER_DEPTH(dstPduPtr))
               )
            {
                /* Set pduInfo ptr. */
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                pduInfoPtr = &PDUR_TXBUFFER_PDU(dstPduPtr, PDUR_IDX_0);
                /* Init idx. */
                defValueIdx = (uint16)PDUR_INIT_0;
                /* Req: SWS_PDUR_00810 */
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                while( defValueIdx < dstPduPtr->PduRDefaultValue->maxDefaultValueElementSize )
                {
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                    defValue = PDUR_DEFAULT_VALUE_ELEMENT(dstPduPtr, defValueIdx).PduRDefaultValueElement;
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                    bytePosition = PDUR_DEFAULT_VALUE_ELEMENT(dstPduPtr, defValueIdx).PduRDefaultValueElementBytePosition;
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                    if( (NULL_PTR != pduInfoPtr->SduDataPtr) && (pduInfoPtr->SduLength > bytePosition) )
                    {
                        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
                        pduInfoPtr->SduDataPtr[bytePosition] = defValue;
                    }
                    else
                    {
                        PDUR_REPORT_DET_ERROR(PDUR_SID_SET_RGTB_DEF, PDUR_E_CONFIG_PARAM_ERROR)
                        break;
                    }
                    /* Move postion. */
                    defValueIdx++;
                }
            }
        }
        /* Move pointer. */
        dstPduIdx++;
    }
}

/*
********************************************************************************
* Function Name: PduR_RefreshFIFO
*
* Explanation: SWS_PduR_00663.
*
* param: groupId -> PduR routing path group Id.
*
* retval: None.
********************************************************************************
*/
FUNC(void, PDUR_CODE) PduR_RefreshFIFO(PduR_RoutingPathGroupIdType groupId)  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    uint16 dstPduIdx = (uint16)PDUR_INIT_0;
    const PduRDestPdu_Type* dstPduPtr;

    /* Setting default values. */
    /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.14" PolySpace +1 DEFECT:TAINTED_LOOP_BOUNDARY [Justified:Unset] "NSCA_Polyspace_PduR_TAINTED_LOOP_BOUNDARY" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
    while( NULL_PTR != PduR_RoutingPathGroup[groupId].destPduRef[dstPduIdx] )
    {
        dstPduPtr = PduR_RoutingPathGroup[groupId].destPduRef[dstPduIdx];
        /* The destination PDU exists and the PDU exists in the buffer. */
        /* (PduR-BUG-No.010) */
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( NULL_PTR != dstPduPtr->PduRDestTxBufferRef )
        {
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            if( (NULL_PTR != PDUR_TXBUFFER_TXBUF(dstPduPtr)) && (PDUR_DEPTH_IS_FIFO < PDUR_TXBUFFER_DEPTH(dstPduPtr)) )
            {
#if (STD_ON == PDUR_SUPPORT_GETWAY)
               /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
               PDUR_TXBUFFER_USE_BUFFER(dstPduPtr) = PDUR_TX_BUFFER_TP_NOUSE;
#endif  /* #if (STD_ON == PDUR_SUPPORT_GETWAY) */
#if (STD_ON == PDUR_SUPPORT_GETWAY)
               /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
               PDUR_TXBUFFER_TAIL(dstPduPtr) = (uint8)PDUR_INIT_0;
               /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
               PDUR_TXBUFFER_FRONT(dstPduPtr) = (uint8)PDUR_INIT_0;
#endif  /* #if (STD_ON == PDUR_SUPPORT_GETWAY) */
               /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
               PDUR_TXBUFFER_STATUS(dstPduPtr) = PDUR_TX_BUFFER_IDLE;
            }
        }
        dstPduIdx++;
    }
    /* Req: SWS_PduR_00663 */
    PDUR_REPORT_DET_ERROR(PDUR_SERVICE_ID_DISABLE_ROUTING, PDUR_E_PDU_INSTANCES_LOST)
}
#endif  /* #if (STD_ON == PDUR_SUPPORT_GETWAY) */

#endif  /* #if (STD_OFF == PDUR_ZERO_COST_OPERATION) */

/*
********************************************************************************
* Function Name: PduR_SetInitState
*
* Explanation: PduR set PduR_ModuleState.
*
* param: state -> new state.
*
* retval: None.
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.5" */
FUNC(void, PDUR_CODE) PduR_SetInitState(PduR_StateType state)  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    PduR_ModuleState = state;
}

/*
********************************************************************************
* Function Name: PduR_GetInitState
*
* Explanation: PduR get PduR_ModuleState.
*
* param: None.
*
* retval: PduR_ModuleState.
********************************************************************************
*/
FUNC(PduR_StateType, PDUR_CODE) PduR_GetInitState(void)  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    return PduR_ModuleState;
}

/*
********************************************************************************
* Function Name: PduR_GetConfigId
*
* Explanation: Returns the unique identifier of the post-build time configuration
*              of the PDU Router.
* (Synchronous)
*
* param: None.
*
* retval: Identifier of the post-build time configuration.
********************************************************************************
*/
FUNC(uint16, PDUR_CODE) PduR_GetConfigId(void)  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
#if (STD_OFF == PDUR_ZERO_COST_OPERATION)
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
    return PduR_PBcfgAdminPtr->PduR_RoutingTablePtr->PduRConfigurationId;
#else   /* #if (STD_OFF == PDUR_ZERO_COST_OPERATION) */
    return PduR_PBcfgAdminPtr->PduRConfigurationId;
#endif  /* #if (STD_OFF == PDUR_ZERO_COST_OPERATION) */
}

#if (STD_ON == PDUR_DEV_ERROR_DETECT)
/*
********************************************************************************
* Function Name: PduR_ReportError
*
* Explanation: Report runtime err or Development Errors.
*
* param: apiID -> app id number.
*        errorID -> err id number.
*
* retval: None.
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, PDUR_CODE) PduR_ReportError(uint8 apiID, uint8 errorID)
{
    /* Development Errors? */
    if( (PDUR_E_INIT_FAILED == errorID) || (PDUR_E_PARAM_POINTER == errorID) )
    {
        PduR_Det_ErrorReport(apiID, errorID);
    }
    else
    {
        /* Runtime Errors. */
        PduR_Det_ReportRuntimeError(apiID, errorID);
    }
}
#endif  /* #if (STD_ON == PDUR_DEV_ERROR_DETECT) */

#if (STD_OFF == PDUR_ZERO_COST_OPERATION)
/* Req: SWS_PduR_00629 */
/*
********************************************************************************
* Function Name: PduR_UpTransmit
*
* Explanation: Requests transmission of an I-PDU.
* (Asynchronous)
*
* param: id -> Identification of the I-PDU.
*        info -> Length and pointer to the buffer of the I-PDU.
*
* retval: E_OK -> request is accepted by the dstPduPtr module;
*                 transmission is continued.
*         E_NOT_OK -> request is not accepted by the dstPduPtr module;
*                     transmission is aborted.
********************************************************************************
*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_UpTransmit
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
)
{
    Std_ReturnType retVal = PDUR_E_OK;

#if (STD_ON == PDUR_SUPPORT_MULICAST)
    Std_ReturnType realRetVal = PDUR_E_NOT_OK;
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
        uint8 routeStatus[PDUR_PARTITION_SIZE] = { PDUR_ROUTE_NONE };
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
#endif  /* #if (STD_ON == PDUR_SUPPORT_MULICAST) */

#if (STD_ON == PDUR_SUPPORT_MULTICORE)
#if( (defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY) )
    boolean allocNode = PDUR_TRUE;
#endif /* #if( (defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY) ) */
    uint16 appId = PDUR_CURRENT_PARTITION;
    PduInfoType pduInfo =
    {
        NULL_PTR,
        info->SduLength
    };
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */

    const PduRRoutingPath_Type* routPathPtr;

    /* Check the initialization status. */
    PDUR_VALIDATE_INITIALIZED_CORE(PDUR_SID_UP_TRANSMIT, retVal);
    /* Enable constant null pointer checking. pag34-note:Note that the <Lo>_Transmit may or may not contain data. */
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
    PDUR_VALIDATE_PDU_ID(PDUR_SID_UP_TRANSMIT, id, retVal);
    /* No errors occurred. */
    if( PDUR_E_OK == retVal )
    {
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        routPathPtr = PDUR_ROUTING_PATH(id);
        /* PduR_EnableCheck PduR route table & Check whether the route dstPduPtr path is forbidden. */
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( (NULL_PTR != routPathPtr) && (NULL_PTR != routPathPtr->PduRDestPdu) )
        {
            const PduRDestPdu_Type* const* dstPduPtr = routPathPtr->PduRDestPdu;
            /* Set initial value. */
            PDUR_ASSERT(NULL_PTR == PTR_VAL(dstPduPtr));
            /* Route based on the configured route table. */
            /* SWS_PduR_00634 */
            do
            {
                /* SWS_PduR_00646 Has the destination PDU been enabled? */
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                if( (PDUR_INVALID_PATHGROUP_ID == PTR_VAL(dstPduPtr)->PduRRoutingPathGroupIdRef) ||
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
                    (PDUR_TRUE == PduR_RoutingPathGroup[PTR_VAL(dstPduPtr)->PduRRoutingPathGroupIdRef].PduRIsEnabledAtInit) )
                {
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
                    /* If the destination partition is the same as the current partition */
                    if( appId == PTR_VAL(dstPduPtr)->PduRPartitionRef )
                    {
                        /* If the source partition is different from the current partition and the source is a TP module */
                        if( (appId != routPathPtr->PduRSrcPdu->PduRPartitionRef)
                            && PDUR_IS_TP_MODULE(PTR_VAL(dstPduPtr)) )
                        {
#if( (defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY) )
                            /* Req: SWS_PduR_00860 */
                            /* PduR shall treat inter-partition Transport Protocol module interactions as gateway routings. */
                            if( BUFREQ_OK == PduR_TP_BufferAllocation(id, (PTR_VAL(dstPduPtr)), info->SduLength, &allocNode) )
                            {
                                /* Copy the data. */
                                PduLengthType bufferSize = 0;
                                /* Req: SWS_PduR_00797 SWS_PduR_00798 */
                                PduR_TP_StartOfCopyData(id, (PTR_VAL(dstPduPtr)), info, &bufferSize);
                            }
#endif /* #if( (defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY) ) */
                        }
                        else
                        {
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
                            /* SWS_PduR_00432 */
                            retVal = PduR_Route_LoTransmit(PTR_VAL(dstPduPtr), info);
#if (STD_ON == PDUR_SUPPORT_MULICAST)
                            /* Req: SWS_PDUR_00218 */
                            if( PDUR_E_OK == retVal )
                            {
                                realRetVal = PDUR_E_OK;
                            }
#endif  /* #if (STD_ON == PDUR_SUPPORT_MULICAST) */
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
                        }
                    }
                    else if( appId == routPathPtr->PduRSrcPdu->PduRPartitionRef )
                    {
#if (STD_ON == PDUR_SUPPORT_MULICAST)
                        /* If the destination partition has not been routed to */
                        if( PDUR_ROUTE_NONE == routeStatus[PTR_VAL(dstPduPtr)->PduRPartitionRef] )
                        {
#endif /* #if (STD_ON == PDUR_SUPPORT_MULICAST) */

                            /* SWS_PduR_00843 SWS_PduR_00844 */
                            retVal = PduR_Queue_UpTransmit(PDUR_QUEUE_PTR(PTR_VAL(dstPduPtr)->PduRPartitionRef), id, info);

#if (STD_ON == PDUR_SUPPORT_MULICAST)
                            if( PDUR_E_OK == retVal )
                            {
                                /* It has been successfully routed to the destination partition */
                                routeStatus[PTR_VAL(dstPduPtr)->PduRPartitionRef] = PDUR_ROUTE_ALREADY;
                            }
                        }
#endif /* #if (STD_ON == PDUR_SUPPORT_MULICAST) */
                    }
                    else
                    {
                        /* Do nothing */
                    }
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
                }
                else
                {
                    retVal = PDUR_E_NOT_OK;
                }
                ++dstPduPtr;
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            } while( PTR_VAL(dstPduPtr) != NULL_PTR );

#if (STD_ON == PDUR_SUPPORT_MULTICORE)
            if( PDUR_E_OK == retVal )
            {
                /* In multi-core communication, when the destination is a TP module,
                   the buffered data should be transmitted to the destination. */
                dstPduPtr = routPathPtr->PduRDestPdu;

                do
                {
                    if( PDUR_IS_TP_MODULE(PTR_VAL(dstPduPtr)) && (appId == PTR_VAL(dstPduPtr)->PduRPartitionRef)
                        && (appId != routPathPtr->PduRSrcPdu->PduRPartitionRef))
                    {
                        /* SWS_PduR_00432 */
                        retVal = PduR_Route_LoTransmit(PTR_VAL(dstPduPtr), &pduInfo);
#if (STD_ON == PDUR_SUPPORT_MULICAST)
                        /* Req: SWS_PDUR_00218 */
                        if( PDUR_E_OK == retVal )
                        {
                            realRetVal = PDUR_E_OK;
                        }
#endif  /* #if (STD_ON == PDUR_SUPPORT_MULICAST) */
                    }

                    ++dstPduPtr;
                } while (PTR_VAL(dstPduPtr) != NULL_PTR);
            }
#endif  /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
        }
        else
        {
            /* Req: SWS_PDUR_00805 */
            retVal = PDUR_E_NOT_OK;
        }
    }
#if (STD_ON == PDUR_SUPPORT_MULICAST)
    /* Stop check SWS_PduR_00633. Do nothing. */
    /* Req: SWS_PDUR_00218 */
    if( PDUR_E_OK == realRetVal )
    {
        retVal = PDUR_E_OK;
    }
#endif  /* #if (STD_ON == PDUR_SUPPORT_MULICAST) */

    return retVal;
}

/*
********************************************************************************
* Function Name: PduR_UpCancelTransmit
*
* Explanation: Requests cancellation of an ongoing transmission of an I-PDU in a
*              lower layer communication interface or transport protocol module.
* (Synchronous)
*
* param: id -> Identification of the I-PDU to be cancelled.
*
* retval: E_OK -> Cancellation was executed successfully by the dstPduPtr module.
*         E_NOT_OK -> Cancellation was rejected by the dstPduPtr module.
********************************************************************************
*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_UpCancelTransmit(PduIdType id)  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    Std_ReturnType retVal = PDUR_E_OK;
#if (STD_ON == PDUR_SUPPORT_MULICAST)
    Std_ReturnType lastRetVal = PDUR_E_OK;
#endif  /* #if (STD_ON == PDUR_SUPPORT_MULICAST) */
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
    uint16 appId = PDUR_CURRENT_PARTITION;
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
    const PduRRoutingPath_Type* routPathPtr;

    /* Check the initialization status. */
    PDUR_VALIDATE_INITIALIZED_CORE(PDUR_SID_UP_CANCEL_TRANSMIT, retVal);
    /* Check pduID. */
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
    PDUR_VALIDATE_PDU_ID(PDUR_SID_UP_CANCEL_TRANSMIT, id, retVal);
    /* No errors occurred. */
    if( PDUR_E_OK == retVal )
    {
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        routPathPtr = PDUR_ROUTING_PATH(id);
        /* PduR_EnableCheck PduR route table & Check whether the route dstPduPtr path is forbidden. */
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( (NULL_PTR != routPathPtr) && (NULL_PTR != routPathPtr->PduRDestPdu) )
        {
            const PduRDestPdu_Type* const* dstPduPtr = routPathPtr->PduRDestPdu;
#if (STD_ON == PDUR_SUPPORT_MULICAST)
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
            uint8 routeStatus[PDUR_PARTITION_SIZE] = { PDUR_ROUTE_NONE };
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */

            /* Route based on the configured route table. */
            do
            {
#endif  /* #if (STD_ON == PDUR_SUPPORT_MULICAST) */
                /* SWS_PduR_00710 */
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                if( (PDUR_INVALID_PATHGROUP_ID == PTR_VAL(dstPduPtr)->PduRRoutingPathGroupIdRef) ||
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
                    (PDUR_TRUE == PduR_RoutingPathGroup[PTR_VAL(dstPduPtr)->PduRRoutingPathGroupIdRef].PduRIsEnabledAtInit) )
                {
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
                    /* If the destination partition is the same as the current partition */
                    if( appId == PTR_VAL(dstPduPtr)->PduRPartitionRef )
                    {
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
                        /* Req: SWS_PduR_00700 SWS_PduR_00721 SWS_PduR_00722 SWS_PduR_00723 SWS_PduR_00724 */
                        retVal = PduR_Route_LoCancelTransmit(PTR_VAL(dstPduPtr));
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
                    }
                    else if( appId == routPathPtr->PduRSrcPdu->PduRPartitionRef )
                    {
#if (STD_ON == PDUR_SUPPORT_MULICAST)
                        /* If the destination partition has not been routed to */
                        if( PDUR_ROUTE_NONE == routeStatus[PTR_VAL(dstPduPtr)->PduRPartitionRef] )
                        {
#endif /* #if (STD_ON == PDUR_SUPPORT_MULICAST) */

                            /* Req: SWS_PduR_00845 SWS_PduR_00846 */
                            retVal = PduR_Queue_UpCancelTransmit(PDUR_QUEUE_PTR(PTR_VAL(dstPduPtr)->PduRPartitionRef), id);

#if (STD_ON == PDUR_SUPPORT_MULICAST)
                            if( PDUR_E_OK == retVal )
                            {
                                /* It has been successfully routed to the destination partition */
                                routeStatus[PTR_VAL(dstPduPtr)->PduRPartitionRef] = PDUR_ROUTE_ALREADY;
                            }
                        }
#endif /* #if (STD_ON == PDUR_SUPPORT_MULICAST) */
                    }
                    else
                    {
                        /* Do nothing */
                    }
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
                }
                else
                {
                    /*
                    SWS_PduR_00710
                    If the routing path for the requested I-PDU is disabled, then
                    PduR_<Up>CancelTransmit shall return E_NOT_OK directly without any further
                    action.
                    */
                    retVal = PDUR_E_NOT_OK;
                }
#if (STD_ON == PDUR_SUPPORT_MULICAST)
                /* PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_PduR_14.3" PolySpace +1 DEFECT:USELESS_IF [Justified:Unset] "NSCA_Polyspace_PduR_USELESS_IF" Polyspace +1 RTE:UNR [Justified:Unset] " NSCA_Polyspace_Common_Unreachable " */
                if( PDUR_E_NOT_OK == retVal )
                {
                    /* Req: SWS_PduR_00701 */
                    lastRetVal = PDUR_E_NOT_OK;
                }
                ++dstPduPtr;
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            } while( PTR_VAL(dstPduPtr) != NULL_PTR );
#endif  /* #if (STD_ON == PDUR_SUPPORT_MULICAST) */
        }
        else
        {
            /* Req: SWS_PduR_00710 */
            retVal = PDUR_E_NOT_OK;
        }
    }
#if (STD_ON == PDUR_SUPPORT_MULICAST)
    /* Req: SWS_PduR_00701 */
    if( PDUR_E_NOT_OK == lastRetVal )
    {
        retVal = PDUR_E_NOT_OK;
    }
#endif  /* #if (STD_ON == PDUR_SUPPORT_MULICAST) */

    return retVal;
}

/*
********************************************************************************
* Function Name: PduR_UpCancelReceive
*
* Explanation: Requests cancellation of an ongoing reception of an I-PDU in a
*              lower layer transport protocol module.
* (Synchronous)
*
* param: id -> Identification of the I-PDU to be cancelled.
*
* retval: E_OK -> Cancellation was executed successfully by the dstPduPtr module.
*         E_NOT_OK -> Cancellation was rejected by the dstPduPtr module.
********************************************************************************
*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_UpCancelReceive(PduIdType id)  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    Std_ReturnType retVal = PDUR_E_OK;
    const PduRDestPdu_Type* dstPduPtr = NULL_PTR;
    const PduRRoutingPath_Type* routPathPtr = NULL_PTR;

    /* Check the initialization status. */
    PDUR_VALIDATE_INITIALIZED_CORE(PDUR_SID_UP_CANCEL_RECEIVE, retVal);
    /* Parameter check. */
    PDUR_VALIDATE_DEST_PDU_ID(PDUR_SID_UP_CANCEL_RECEIVE, id, retVal);
    /* No errors occurred. */
    /* PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_PduR_14.3" */
    if( PDUR_E_OK == retVal )
    {
        /* No errors occurred. */
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        dstPduPtr = PDUR_DEST_PDU_PTR(id);
        /* PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_PduR_14.3" PolySpace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
        if( NULL_PTR != dstPduPtr )
        {
            /* Get the routing path pointed to. */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            routPathPtr = PDUR_ROUTING_PATH(dstPduPtr->PduRRoutPathRefId);
            /* PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        }
        else
        {
            /* Set return value. */
            retVal = PDUR_E_NOT_OK;
        }
    }
    /* No errors occurred. */
    /* (PduR-BUG-No.005) */
    if( PDUR_E_OK == retVal )
    {
        /* PduR_EnableCheck PduR route table. */
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( (NULL_PTR != routPathPtr) && (NULL_PTR != routPathPtr->PduRSrcPdu) )
        {
            /* SWS_PduR_00726 */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
            if( (PDUR_INVALID_PATHGROUP_ID == dstPduPtr->PduRRoutingPathGroupIdRef) ||
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
                (PDUR_TRUE == PduR_RoutingPathGroup[dstPduPtr->PduRRoutingPathGroupIdRef].PduRIsEnabledAtInit) )
            {
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
                /* If the source partition is the same as the current partition */
                if( PDUR_CURRENT_PARTITION == routPathPtr->PduRSrcPdu->PduRPartitionRef )
                {
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
                    /* Req: SWS_PduR_00727 SWS_PduR_00736 */
                    retVal = PduR_Route_LoCancelReceive(routPathPtr->PduRSrcPdu);
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
                }
                else if( PDUR_CURRENT_PARTITION == dstPduPtr->PduRPartitionRef )
                {
                    /* Req: SWS_PduR_00847 SWS_PduR_00848 */
                    retVal = PduR_Queue_UpCancelReceive(PDUR_QUEUE_PTR(routPathPtr->PduRSrcPdu->PduRPartitionRef), id);
                }
                else
                {
                    /* Do nothing */
                }
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
            }
            else
            {
                /*
                SWS_PduR_00726
                If the routing path for the requested I-PDUs is disabled, then
                PduR_<Up>CancelReceive shall return E_NOT_OK directly without any further
                action.
                */
                retVal = PDUR_E_NOT_OK;
            }
        }
        else
        {
            /* Set return value. */
            retVal = PDUR_E_NOT_OK;
        }
    }

    /* Req: SWS_PduR_00732 */
    return retVal;
}

/*
********************************************************************************
* Function Name: PduR_UpChangeParameter
*
* Explanation: Request to change a specific transport protocol parameter (e.g. block size).
* (Synchronous)
*
* param: id -> Identifiaction of the I-PDU which the parameter change shall affect.
*        parameter -> The parameter that shall change.
*        value -> The new value of the parameter.
*
* retval: E_OK -> The parameter was changed successfully.
*         E_NOT_OK -> The parameter change was rejected.
********************************************************************************
*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_UpChangeParameter  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    PduIdType id,
    TPParameterType parameter,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.5" */
    uint16 value
)
{
    Std_ReturnType retVal = PDUR_E_OK;

    /* Check the initialization status. */
    PDUR_VALIDATE_INITIALIZED_CORE(PDUR_SID_UP_CHANGE_PARAMETER, retVal);
    /* Parameter check. */
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
    PDUR_VALIDATE_PDU_ID(PDUR_SID_UP_CHANGE_PARAMETER, id, retVal);
    /* No errors occurred. */
    if( PDUR_E_OK == retVal )
    {
#if (STD_ON == PDUR_SUPPORT_MULICAST)
        Std_ReturnType lastRetVal = PDUR_E_NOT_OK;
#endif  /* #if (STD_ON == PDUR_SUPPORT_MULICAST) */
        /* Req: SWS_PduR_00747 */
        /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_PduR_UNMODIFIED_VAR_NOT_CONST" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        const PduRRoutingPath_Type* routPathPtr = PDUR_ROUTING_PATH(id);
        /* PduR_EnableCheck PduR route table. */
        /* PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_PduR_14.3" PolySpace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
        if( NULL_PTR != routPathPtr )
        {
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            const PduRDestPdu_Type* const* dstPduPtr = routPathPtr->PduRDestPdu;
#if (STD_ON == PDUR_SUPPORT_MULICAST)
            /* Route based on the configured route table. */
            do
            {
                /* Req: SWS_PduR_00733 SWS_PduR_00734 */
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                retVal = PduR_Route_LoTpChangeParameter(PTR_VAL(dstPduPtr), parameter, value);
                if( lastRetVal != PDUR_E_OK )
                {
                    lastRetVal = retVal;
                }
                ++dstPduPtr;
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            } while( PTR_VAL(dstPduPtr) != NULL_PTR );

            /* If one returns E_OK, it returns E_OK. */
            if( PDUR_E_OK == lastRetVal )
            {
                retVal = PDUR_E_OK;
            }
#else  /* #if (STD_ON == PDUR_SUPPORT_MULICAST) */
            PDUR_ASSERT(NULL_PTR == dstPduPtr || NULL_PTR == PTR_VAL(dstPduPtr));
            retVal = PduR_Route_LoTpChangeParameter(PTR_VAL(dstPduPtr), parameter, value);
#endif  /* #if (STD_ON == PDUR_SUPPORT_MULICAST) */
            /* PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        }
        else
        {
            retVal = PDUR_E_NOT_OK;
        }
    }

    /* Req: SWS_PduR_00734 */
    return retVal;
}

/*
********************************************************************************
* Function Name: PduR_LoRxIndication
*
* Explanation: Indication of a received I-PDU from a lower layer communication
*              interface module.
* (Synchronous)
*
* param: RxPduId -> ID of the received I-PDU.
*        PduInfoPtr -> Contains the length (SduLength) of the received I-PDU and
*                      a pointer to a buffer (SduDataPtr) containing the I-PDU.
*
* retval: None.
********************************************************************************
*/
FUNC(void, PDUR_CODE) PduR_LoRxIndication
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.5" */
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
    Std_ReturnType retVal = PDUR_E_OK;
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
    uint16 appId = PDUR_CURRENT_PARTITION;
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
    const PduRRoutingPath_Type* routPathPtr = NULL_PTR;

    /* Check the initialization status. */
    PDUR_VALIDATE_INITIALIZED_CORE(PDUR_SID_LO_RX_INDICATION, retVal);
    /* Parameter check. */
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
    PDUR_VALIDATE_PDU_ID(PDUR_SID_LO_RX_INDICATION, RxPduId, retVal);
    /* Enable constant null pointer checking. */
    PDUR_VALIDATE_POINTER(PDUR_SID_LO_RX_INDICATION, PduInfoPtr, retVal);
    /* The check passed and did not fail. */
    if( PDUR_E_OK == retVal )
    {
        /* Set routPathPtr ptr. */
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        routPathPtr = PDUR_ROUTING_PATH(RxPduId);
    }
    /* No errors occurred. */
    if( (PDUR_E_OK == retVal) && (NULL_PTR != routPathPtr) )
    {
        /* This function only supports Pdu of IF type. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( PDUR_IS_TP_MODULE(routPathPtr->PduRSrcPdu) || PDUR_IS_UP_MODULE(routPathPtr->PduRSrcPdu) )
        {
            /* Set return value. */
            retVal = PDUR_E_NOT_OK;
        }
    }
    else
    {
        /* Set PDUR_E_NOT_OK. */
        retVal = PDUR_E_NOT_OK;
    }
    /* PduR_EnableCheck PduR route table & Check whether the route dstPduPtr path is forbidden. */
    /* No errors occurred. */
    if( PDUR_E_OK == retVal )
    {
        /* Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        const PduRDestPdu_Type* const* dstPduPtr = routPathPtr->PduRDestPdu;

#if (STD_ON == PDUR_SUPPORT_MULICAST)
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
        uint8 routeStatus[PDUR_PARTITION_SIZE] = { PDUR_ROUTE_NONE };
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
#endif /* #if (STD_ON == PDUR_SUPPORT_MULICAST) */

        /* Loop through the route destination. */
        /* Req: SWS_PduR_00164\SWS_PduR_00621. */
        do
        {
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
            /* If the destination partition is the same as the current partition */
            if( appId == PTR_VAL(dstPduPtr)->PduRPartitionRef )
            {
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
#if ((defined PDUR_SUPPORT_IF_GETWAY) && (STD_ON == PDUR_SUPPORT_IF_GETWAY))
                /* Check Dest Pdu Module Id is Up Module. */
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                if( PDUR_IS_UP_MODULE(PTR_VAL(dstPduPtr)) )
                {
#endif  /* #if ((defined PDUR_SUPPORT_IF_GETWAY) && (STD_ON == PDUR_SUPPORT_IF_GETWAY)) */

                    /* SWS_PduR_00646 Has the destination PDU been enabled? */
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                    if( (PDUR_INVALID_PATHGROUP_ID == PTR_VAL(dstPduPtr)->PduRRoutingPathGroupIdRef) ||
                        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
                        (PDUR_TRUE == PduR_RoutingPathGroup[PTR_VAL(dstPduPtr)->PduRRoutingPathGroupIdRef].PduRIsEnabledAtInit) )
                    {
                        /* Req: SWS_PduR_00621 SWS_PduR_00744 */
                        /*
                            When the PduR_<Lo>RxIndication is called the PDU Router module shall
                            call <Up>_RxIndication for each destination upper module.
                        */
                        PduR_Route_UpRxIndication(PTR_VAL(dstPduPtr), PduInfoPtr);
                    }
#if ((defined PDUR_SUPPORT_IF_GETWAY) && (STD_ON == PDUR_SUPPORT_IF_GETWAY))
                }
                else if( PDUR_IS_IF_MODULE(PTR_VAL(dstPduPtr)) )
                {
                    /* SWS_PDUR_00805 Has the destination PDU been enabled? */
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                    if( (PDUR_INVALID_PATHGROUP_ID == PTR_VAL(dstPduPtr)->PduRRoutingPathGroupIdRef) ||
                        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
                        (PDUR_TRUE == PduR_RoutingPathGroup[PTR_VAL(dstPduPtr)->PduRRoutingPathGroupIdRef].PduRIsEnabledAtInit) )
                    {
                        /* If Gateway. */
                        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                        if( PDUR_DIRECT == PTR_VAL(dstPduPtr)->PduRDestPduDataProvision )
                        {
                            /* Req: SWS_PduR_00303 */
                            PduR_Core_RxIndicationDirect(PTR_VAL(dstPduPtr), PduInfoPtr);
                        }
                        else if( PDUR_TRIGGERTRANSMIT == PTR_VAL(dstPduPtr)->PduRDestPduDataProvision )
                        {
                            /* Req: SWS_PduR_00306 */
                            retVal = PduR_Core_RxIndicationTriggerTransmit(PTR_VAL(dstPduPtr), PduInfoPtr);
                            PDUR_UNUSED(retVal);
                        }
                        else
                        {
                            /* Do nothing. */
                            /* The buffer status set in the function PduR_LoRxIndication is BUSY. */
                        }
                    }
                }
                else
                {
                    /* I-PDUs can only be gatewayed between communication interface modules or
                       TP modules, not a mix of them. For example an I-PDU cannot be received
                       from CanIf and gatewayed to LinTp.
                    */
                    PDUR_REPORT_DET_ERROR(PDUR_SID_LO_RX_INDICATION, PDUR_E_CONFIG_PARAM_ERROR)
                }
#endif  /* #if ((defined PDUR_SUPPORT_IF_GETWAY) && (STD_ON == PDUR_SUPPORT_IF_GETWAY)) */
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
            }
            else if( appId == PDUR_ROUTING_PATH(RxPduId)->PduRSrcPdu->PduRPartitionRef )
            {
#if (STD_ON == PDUR_SUPPORT_MULICAST)
                /* If the destination partition has not been routed to */
                if( PDUR_ROUTE_NONE == routeStatus[PTR_VAL(dstPduPtr)->PduRPartitionRef] )
                {
#endif /* #if (STD_ON == PDUR_SUPPORT_MULICAST) */

                    /* SWS_PduR_00849 */
                    PduR_Queue_LoRxIndication(PDUR_QUEUE_PTR(PTR_VAL(dstPduPtr)->PduRPartitionRef), RxPduId, PduInfoPtr);

#if (STD_ON == PDUR_SUPPORT_MULICAST)
                    if( PDUR_E_OK == retVal )
                    {
                        /* It has been successfully routed to the destination partition */
                        routeStatus[PTR_VAL(dstPduPtr)->PduRPartitionRef] = PDUR_ROUTE_ALREADY;
                    }
                }
#endif /* #if (STD_ON == PDUR_SUPPORT_MULICAST) */
            }
            else
            {
                /* Do nothing */
            }
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
            ++dstPduPtr;
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        } while( PTR_VAL(dstPduPtr) != NULL_PTR );
        /* (PduR-BUG-No.011) */
    }

#if ((defined PDUR_SUPPORT_DIAG) && (STD_ON == PDUR_SUPPORT_DIAG))
    PduR_Diag_Entry(RxPduId, PduInfoPtr);
#endif /* #if ((defined PDUR_SUPPORT_DIAG) && (STD_ON == PDUR_SUPPORT_DIAG)) */
}

/*
********************************************************************************
* Function Name: PduR_LoTxConfirmation
*
* Explanation: The lower layer communication interface module confirms the transmission of an IPDU.
* (Synchronous)
*
* param: TxPduId -> ID of the I-PDU that has been transmitted.
*
* retval: None.
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.5" PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, PDUR_CODE) PduR_LoTxConfirmation(PduIdType TxPduId)
{
    Std_ReturnType retVal = PDUR_E_OK;
    const PduRDestPdu_Type* dstPduPtr = NULL_PTR;
    const PduRRoutingPath_Type* routPathPtr = NULL_PTR;

#if ((defined PDUR_SUPPORT_IF_MULICAST) && (STD_ON == PDUR_SUPPORT_IF_MULICAST))
    PduRIfMul_Type* ifMulPtr;
#endif  /* #if ((defined PDUR_SUPPORT_IF_MULICAST) && (STD_ON == PDUR_SUPPORT_IF_MULICAST)) */

    /* Check the initialization status. */
    PDUR_VALIDATE_INITIALIZED_CORE(PDUR_SID_LO_TX_CONFIRMATION, retVal);
    /* Parameter check. */
    PDUR_VALIDATE_DEST_PDU_ID(PDUR_SID_LO_TX_CONFIRMATION, TxPduId, retVal);
    /* The check passed and did not fail. */
    if( PDUR_E_OK == retVal )
    {
        /* No errors occurred. */
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        dstPduPtr = PDUR_DEST_PDU_PTR(TxPduId);
        /* PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_PduR_14.3" PolySpace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
        if( NULL_PTR != dstPduPtr )
        {
            /* Get the routing path pointed to. */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            routPathPtr = PDUR_ROUTING_PATH(dstPduPtr->PduRRoutPathRefId);
            /* PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        }
        else
        {
            /* Set return value. */
            retVal = PDUR_E_NOT_OK;
        }
        /* Assertions about null pointers. */
        PDUR_ASSERT((NULL_PTR == routPathPtr) && (NULL_PTR == routPathPtr->PduRSrcPdu));
    }
    /* No errors occurred. */
    if( (PDUR_E_OK == retVal) && (NULL_PTR != routPathPtr) )
    {
        /* This function only supports Pdu of IF type. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( PDUR_IS_TP_MODULE(dstPduPtr) || PDUR_IS_UP_MODULE(dstPduPtr) )
        {
            /* Set return value. */
            retVal = PDUR_E_NOT_OK;
        }
    }
    else
    {
        /* Set PDUR_E_NOT_OK. */
        retVal = PDUR_E_NOT_OK;
    }
    /* No err and not null pointer. */
    if( PDUR_E_OK == retVal )
    {
        /* Does the source module and target support TxConfirmation? */
        /* Enable sending confirmation callback? */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( (PDUR_TRUE != PDUR_MODULE_TX_CONFIRMATION(routPathPtr->PduRSrcPdu)) ||
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            (PDUR_TRUE != PDUR_MODULE_TX_CONFIRMATION(dstPduPtr)) ||
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
            (PDUR_TRUE != dstPduPtr->PduRTransmissionConfirmation) )
        {
            /* Set return value. */
            retVal = PDUR_E_NOT_OK;
        }
    }
    else
    {
        /* Set return value. */
        retVal = PDUR_E_NOT_OK;
    }
    /* No errors occurred. */
    if( PDUR_E_OK == retVal )
    {
        /* When enabled, the TxConfirmation will be forwarded to the upper layer. Prerequisites: Lower layer and upper layer support TxConfirmation. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( PDUR_IS_UP_MODULE(routPathPtr->PduRSrcPdu) && (PDUR_TRUE == routPathPtr->PduRSrcPdu->PduRSrcPduUpTxConf) )
        {
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
            /* If the source partition is the same as the current partition */
            if( PDUR_CURRENT_PARTITION == routPathPtr->PduRSrcPdu->PduRPartitionRef )
            {
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
#if ((defined PDUR_SUPPORT_IF_MULICAST) && (STD_ON == PDUR_SUPPORT_IF_MULICAST))
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                if( NULL_PTR != routPathPtr->PduRDestPdu[PDUR_IDX_1] )
                {
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" PolySpace +1 MISRA-C3:20.7 [Justified:Unset] "NSCA_Polyspace_PduR_20.7" */
                    ifMulPtr = &PDUR_GET_IF_MUL_PTR(dstPduPtr->PdurMulTabIdx);
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
                    if( (NULL_PTR == ifMulPtr) || (ifMulPtr->dstPduCnt == ifMulPtr->dstPduCntDyn) )
                    {
                        /* This routing path is not multicast. */
                        retVal = PDUR_E_NOT_OK;
                    }
                    else
                    {
                        /* Move destination PDU counter. */
                        ifMulPtr->dstPduCntDyn++;
                        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                        if( ifMulPtr->dstPduCnt == ifMulPtr->dstPduCntDyn )
                        {
                            /* When the PDU Router module receives the last TxConfirmation, it will call the TxConfirmation of the UP module.  */
                            PduR_Route_UpTxConfirmation(routPathPtr->PduRSrcPdu);
                            /* Reset dstPduCntDyn. */
                            ifMulPtr->dstPduCntDyn = (uint8)PDUR_INIT_0;
                        }
                    }
                }
                else
    #endif  /* #if ((defined PDUR_SUPPORT_IF_MULICAST) && (STD_ON == PDUR_SUPPORT_IF_MULICAST)) */
                {
                    /* SWS_PduR_00627
                        When the communication interface module calls PduR_<Lo>TxConfirmation the PDU Router shall
                        call <Up>_TxConfirmation in the upper module.
                    */
                    PduR_Route_UpTxConfirmation(routPathPtr->PduRSrcPdu);
                }
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
            }
            else if( PDUR_CURRENT_PARTITION == dstPduPtr->PduRPartitionRef )
            {
                /* SWS_PduR_00850 */
                PduR_Queue_LoTxConfirmation(PDUR_QUEUE_PTR(routPathPtr->PduRSrcPdu->PduRPartitionRef), TxPduId);
            }
            else
            {
                /* Do nothing */
            }
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
        }

#if ((defined PDUR_SUPPORT_IF_GETWAY) && (STD_ON == PDUR_SUPPORT_IF_GETWAY))
        else if( PDUR_IS_IF_MODULE(routPathPtr->PduRSrcPdu) )
        {
            /* Release Buffer. */
            PDUR_ASSERT(NULL_PTR == dstPduPtr);
            PduR_Core_TxConfirmationGetWay(dstPduPtr);
        }
#endif  /* #if ((defined PDUR_SUPPORT_IF_GETWAY) && (STD_ON == PDUR_SUPPORT_IF_GETWAY)) */

        else
        {
            /* Report det. */
            PDUR_REPORT_DET_ERROR(PDUR_SID_LO_TX_CONFIRMATION, PDUR_E_CONFIG_PARAM_ERROR)
        }
    }
    /* Eliminate the warning. */
    PDUR_UNUSED(retVal);
}

/*
********************************************************************************
* Function Name: PduR_LoTxConfirmation_44
*
* Explanation: The lower layer communication interface module confirms the transmission
* of an IPDU. (Synchronous), for compatible with 4.4.
*
* param: TxPduId -> ID of the I-PDU that has been transmitted.
*        result -> E_OK: The PDU was transmitted.
*                  E_NOT_OK: Transmission of the PDU failed.
*
* retval: None.
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.5" */
FUNC(void, PDUR_CODE) PduR_LoTxConfirmation_44(PduIdType TxPduId, Std_ReturnType result)
{
    PDUR_UNUSED(result);
    PduR_LoTxConfirmation(TxPduId);
}

/*
********************************************************************************
* Function Name: PduR_LoTriggerTransmit
*
* Explanation: Within this API, the upper layer module (called module) shall
*              PduR_EnableCheck whether the available data fits into the buffer
*              size reported by PduInfoPtr->SduLength. If it fits, it shall copy
*              its data into the buffer provided by PduInfoPtr->SduDataPtr and
*              Update the length of the actual copied data in PduInfoPtr->SduLength.
*              If not, it returns E_NOT_OK without changing PduInfoPtr.
* (Synchronous)
*
* param: TxPduId -> ID of the SDU that is requested to be transmitted.
*        PduInfoPtr -> Contains a pointer to a buffer (SduDataPtr) to where the SDU
*                      data shall be copied, and the available buffer size in SduLengh.
*
* retval: E_OK -> SDU has been copied and SduLength indicates the number of copied bytes.
*         E_NOT_OK -> No SDU data has been copied. PduInfoPtr must not be used since it may
*                     contain a NULL pointer or point to invalid data.
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.5" */
FUNC(Std_ReturnType, PDUR_CODE) PduR_LoTriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
    Std_ReturnType retVal = PDUR_E_OK;
    const PduRRoutingPath_Type* routPathPtr = NULL_PTR;
    const PduRDestPdu_Type* dstPduPtr = NULL_PTR;

    /* Check the initialization status. */
    PDUR_VALIDATE_INITIALIZED_CORE(PDUR_SID_LO_TRIGGER_TRANSMIT, retVal);
    /* Enable constant null pointer checking. */
    PDUR_VALIDATE_POINTER(PDUR_SID_LO_TRIGGER_TRANSMIT, PduInfoPtr, retVal);
    /* Parameter check. */
    PDUR_VALIDATE_DEST_PDU_ID(PDUR_SID_LO_TRIGGER_TRANSMIT, TxPduId, retVal);
    /* The check passed and did not fail. */
    if( PDUR_E_OK == retVal )
    {
        /* No errors occurred. */
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        dstPduPtr = PDUR_DEST_PDU_PTR(TxPduId);
    }
    /* No errors occurred. */
    if( (PDUR_E_OK == retVal) && (NULL_PTR != dstPduPtr) )
    {
        /* This function only supports Pdu of IF type. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( PDUR_IS_TP_MODULE(dstPduPtr) || PDUR_IS_UP_MODULE(dstPduPtr) )
        {
            /* Set return value. */
            retVal = PDUR_E_NOT_OK;
        }
    }
    else
    {
        /* Set PDUR_E_NOT_OK. */
        retVal = PDUR_E_NOT_OK;
    }
    /* No errors occurred. */
    if( PDUR_E_OK == retVal )
    {
        /* SWS_PDUR_00805 Has the destination PDU been enabled? */
        /* Check if the bus is disabled  (i.e. a destination) */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
        if( (PDUR_INVALID_PATHGROUP_ID == dstPduPtr->PduRRoutingPathGroupIdRef) ||
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            (PDUR_TRUE == PduR_RoutingPathGroup[dstPduPtr->PduRRoutingPathGroupIdRef].PduRIsEnabledAtInit) )
        {
            /* Get the routing path pointed to. */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            routPathPtr = PDUR_ROUTING_PATH(dstPduPtr->PduRRoutPathRefId);
            /* Assertions about null pointers. */
            PDUR_ASSERT((NULL_PTR == routPathPtr) && (NULL_PTR == routPathPtr->PduRSrcPdu));
            /* Does the source module and target support TriggerTransmit? */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            if( (PDUR_TRUE != PDUR_MODULE_TRIGGER_TRANSMINT(routPathPtr->PduRSrcPdu)) ||
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                (PDUR_TRUE != PDUR_MODULE_TRIGGER_TRANSMINT(dstPduPtr)) )
            {
                /* I-PDUs can only be gatewayed between communication interface modules or
                TP modules, not a mix of them. For example an I-PDU cannot be received
                from CanIf and gatewayed to LinTp.
                */
                retVal = PDUR_E_NOT_OK;
                PDUR_REPORT_DET_ERROR(PDUR_SID_LO_TRIGGER_TRANSMIT, PDUR_E_CONFIG_PARAM_ERROR)
            }
        }
        else
        {
            /* Set return value. */
            retVal = PDUR_E_NOT_OK;
        }
    }
    else
    {
        /* Set return value. */
        retVal = PDUR_E_NOT_OK;
    }
    /* No errors occurred. */
    /* (PduR-BUG-No.006) */
    if( PDUR_E_OK == retVal )
    {
        /* The PDU source of the gateway function is non-upper layer. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
        if( PDUR_IS_UP_MODULE(routPathPtr->PduRSrcPdu) )
        {
            /* Req: SWS_PduR_00430 */
            retVal = PduR_Route_UpTriggerTransmit(routPathPtr->PduRSrcPdu, PduInfoPtr);
        }

#if ((defined PDUR_SUPPORT_IF_GETWAY) && (STD_ON == PDUR_SUPPORT_IF_GETWAY))
        else if(PDUR_IS_IF_MODULE(routPathPtr->PduRSrcPdu))
        /* Getway PDU. */
        {
            /* Req: SWS_PduR_00662 */
            retVal = PDUR_E_NOT_OK;
            /* Fifo? */
            /* Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            if( NULL_PTR != dstPduPtr->PduRDestTxBufferRef )
            {
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                if( PDUR_TX_BUFFER_BUSY == (PDUR_TX_BUFFER_BUSY & PDUR_TXBUFFER_STATUS(dstPduPtr)) )
                {
                    /* Gets the pduInfo in the buffer. */
                    retVal = PduR_Core_GetPduInfo(dstPduPtr, PduInfoPtr);
                }
                else
                {
                    /* Do nothing. */
                }
            }
            else
            {
                /* The parameter configuration is incorrect. */
                PDUR_REPORT_DET_ERROR(PDUR_SID_LO_TRIGGER_TRANSMIT, PDUR_E_CONFIG_PARAM_ERROR)
                PDUR_ASSERT(PDUR_E_NOT_OK == retVal);
            }
        }
#endif  /* #if ((defined PDUR_SUPPORT_IF_GETWAY) && (STD_ON == PDUR_SUPPORT_IF_GETWAY)) */

        else
        {
            /* I-PDUs can only be gatewayed between communication interface modules or
            TP modules, not a mix of them. For example an I-PDU cannot be received
            from CanIf and gatewayed to LinTp.
            */
            retVal = PDUR_E_NOT_OK;
            PDUR_REPORT_DET_ERROR(PDUR_SID_LO_TRIGGER_TRANSMIT, PDUR_E_CONFIG_PARAM_ERROR)
        }
    }

    /* Req: SWS_PduR_00661 */
    return retVal;
}

/* Req: SWS_PduR_00673 SWS_PduR_00794 */
/*
********************************************************************************
* Function Name: PduR_LoTpStartOfReception
*
* Explanation: This function is called at the start of receiving an N-SDU.
* (Synchronous)
*
* param: id -> Identification of the I-PDU.
*        pduInfo -> Pointer to a PduInfoType structure containing the
*                   payload data (without protocol information) and
*                   payload length of the first frame or single frame
*                   of a transport protocol I-PDU reception.
*                   If neither first/single frame data nor MetaData
*                   are available, this parameter is set to NULL_PTR.
*        TpSduLength -> Total length of the N-SDU to be received.
*        bufferSizePtr(out) -> Available receive buffer in the receiving module.
*
* retval: BUFREQ_OK: Connection has been accepted. bufferSizePtr indicates
*                    the available receive buffer; reception is continued.
*         BUFREQ_E_NOT_OK: Connection has been rejected; reception is aborted.
*                          bufferSizePtr remains unchanged.
*         BUFREQ_E_OVFL: No buffer of the required length can be provided;
*                        reception is aborted. bufferSizePtr remains unchanged.
********************************************************************************
*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfo,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    uint16 destPduNum = PDUR_INIT_0;
    Std_ReturnType stdRet = PDUR_E_OK;
    BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;
    BufReq_ReturnType retValFun = BUFREQ_E_NOT_OK;

    const PduRRoutingPath_Type* routPathPtr = NULL_PTR;
#if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY))
    boolean allocNode = PDUR_TRUE;
#endif /* #if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY)) */
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_PduR_UNMODIFIED_VAR_NOT_CONST" */
    uint16 curPartitionId = PDUR_INIT_0;

#if (STD_ON == PDUR_SUPPORT_MULTICORE)
    uint8 routeStatus[PDUR_PARTITION_SIZE] = { PDUR_ROUTE_NONE };
    curPartitionId = PDUR_CURRENT_PARTITION;
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */

    /* Check the initialization status. */
    PDUR_VALIDATE_INITIALIZED_CORE(PDUR_SID_LOTP_START_OF_RECEPTION, stdRet);
    /* Parameter check. */
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
    PDUR_VALIDATE_PDU_ID(PDUR_SID_LOTP_START_OF_RECEPTION, id, stdRet);
    /* Enable constant null pointer checking. */
    PDUR_VALIDATE_POINTER(PDUR_SID_LOTP_START_OF_RECEPTION, bufferSizePtr, stdRet);
    /* Set routPathPtr ptr. */
    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
    routPathPtr = PDUR_ROUTING_PATH(id);
    /* No errors occurred. */
    if( PDUR_E_OK == stdRet )
    {
        /* PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_PduR_14.3" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
        if( (NULL_PTR == routPathPtr) )
        {
            /* Set PDUR_E_NOT_OK. */
            stdRet = PDUR_E_NOT_OK;
        }
    }

    /* No errors occurred. */
    if( PDUR_E_OK == stdRet )
    {
        /* This function only supports Pdu of IF type. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( PDUR_IS_IF_MODULE(routPathPtr->PduRSrcPdu) || PDUR_IS_UP_MODULE(routPathPtr->PduRSrcPdu) )
        {
            /* Set PDUR_E_NOT_OK. */
            stdRet = PDUR_E_NOT_OK;
        }
    }
    /* No errors occurred. */
    if( PDUR_E_OK == stdRet )
    {
        /* Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        const PduRDestPdu_Type* const* dstPduPtr = routPathPtr->PduRDestPdu;

        /* For each destination in the routing path */
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        while( (NULL_PTR != dstPduPtr) && (NULL_PTR != PTR_VAL(dstPduPtr)) )
        {
            /* SWS_PduR_00646 Has the destination PDU been enabled? */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            if( (PDUR_INVALID_PATHGROUP_ID == PTR_VAL(dstPduPtr)->PduRRoutingPathGroupIdRef) ||
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
                (PDUR_TRUE == PduR_RoutingPathGroup[PTR_VAL(dstPduPtr)->PduRRoutingPathGroupIdRef].PduRIsEnabledAtInit) )
            {
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
                if( curPartitionId == PTR_VAL(dstPduPtr)->PduRPartitionRef )
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
                {
                    destPduNum = PduR_GetTpDstPdusOfPartition(routPathPtr, curPartitionId);
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                    if( PDUR_IS_UP_MODULE(PTR_VAL(dstPduPtr)) &&
                        (PDUR_INIT_0 == destPduNum) )
                    {
                        /* Req: SWS_PduR_00549 */
                        retValFun = PduR_Route_UpTpStartOfReception(PTR_VAL(dstPduPtr), pduInfo, TpSduLength, bufferSizePtr);
                    }
#if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY))
                    if( PDUR_IS_TP_MODULE(PTR_VAL(dstPduPtr)) )
                    {
                        /* Check which buffer is used and check if there is enough space in the buffer. */
                        /* Req: SWS_PduR_00799 */
                        retValFun = PduR_TP_BufferAllocation(id, (PTR_VAL(dstPduPtr)), TpSduLength, &allocNode);
                        /* Copy the data. */
                        if( BUFREQ_OK == retValFun )
                        {
                            /* Req: SWS_PduR_00797 SWS_PduR_00798 SWS_PduR_00799 */
                            /* Set default output value. */
                            *bufferSizePtr = TpSduLength;
                            /* Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                            PduR_TP_StartOfCopyData(id, (PTR_VAL(dstPduPtr)), pduInfo, bufferSizePtr);
                        }
                    }
#endif /* #if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY)) */
                }

#if (STD_ON == PDUR_SUPPORT_MULTICORE)
                if( curPartitionId == routPathPtr->PduRSrcPdu->PduRPartitionRef )
                {
                    if( curPartitionId != PTR_VAL(dstPduPtr)->PduRPartitionRef )
                    {
                        destPduNum = PduR_GetTpDstPdusOfPartition(routPathPtr, PTR_VAL(dstPduPtr)->PduRPartitionRef);
                        if( PDUR_IS_UP_MODULE(PTR_VAL(dstPduPtr)) &&
                            (PDUR_INIT_0 == destPduNum) )
                        {
                            retValFun = PduR_Queue_LoTpStartOfReceptionCheck(PDUR_QUEUE_PTR(PTR_VAL(dstPduPtr)->PduRPartitionRef),
                                                                        PTR_VAL(dstPduPtr), id, pduInfo, TpSduLength);

                            /* If the destination partition has not been routed to */
                            if( PDUR_ROUTE_NONE == routeStatus[PTR_VAL(dstPduPtr)->PduRPartitionRef] )
                            {
                                if( BUFREQ_OK == retValFun )
                                {
                                    /* SWS_PduR_00854 SWS_PduR_00855 */
                                    retValFun = PduR_Queue_LoTpStartOfReception(PDUR_QUEUE_PTR(PTR_VAL(dstPduPtr)->PduRPartitionRef),
                                                                                    id, pduInfo, TpSduLength);
                                    if( BUFREQ_OK == retValFun )
                                    {
                                        *bufferSizePtr = TpSduLength;
                                        /* It has been successfully routed to the destination partition */
                                        routeStatus[PTR_VAL(dstPduPtr)->PduRPartitionRef] = PDUR_ROUTE_ALREADY;
                                    }
                                }
                            }
                        }
                        /* If the destination partition has not been routed to */
                        else if( PDUR_ROUTE_NONE == routeStatus[PTR_VAL(dstPduPtr)->PduRPartitionRef] )
                        {
                            /* SWS_PduR_00854 SWS_PduR_00855 */
                            retValFun = PduR_Queue_LoTpStartOfReception(PDUR_QUEUE_PTR(PTR_VAL(dstPduPtr)->PduRPartitionRef),
                                                                            id, pduInfo, TpSduLength);
                            if( BUFREQ_OK == retValFun )
                            {
                                *bufferSizePtr = TpSduLength;
                                /* It has been successfully routed to the destination partition */
                                routeStatus[PTR_VAL(dstPduPtr)->PduRPartitionRef] = PDUR_ROUTE_ALREADY;
                            }
                        }
                        else
                        {
                            /* Do nothing. */
                        }
                    }
                }
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */

                if( BUFREQ_OK != retVal )
                {
                    /* Set realy return value. */
                    retVal = retValFun;
                }
            }

            ++dstPduPtr;
        }
 #if( (defined PDUR_SUPPORT_DIAG) && (STD_ON == PDUR_SUPPORT_DIAG) )
        if( BUFREQ_OK == retVal )
        {
            PduR_Diag_ReqFlgSet(id);
        }
#endif /* #if ((defined PDUR_SUPPORT_DIAG) && (STD_ON == PDUR_SUPPORT_DIAG)) */
    }

    /* Req: SWS_PduR_00623 */
    return retVal;
}

/*
********************************************************************************
* Function Name: PduR_LoTpCopyRxData
*
* Explanation: This function is called to provide the received data of an I-PDU
*              segment (N-PDU) to the upper layer.
* (Synchronous)
*
* param: id -> Identification of the received I-PDU.
*        pduInfo -> Provides the source buffer (SduDataPtr) and the number of
*                   bytes to be copied (SduLength)
*        bufferSizePtr(out) -> Available receive buffer after data has been copied.
*
* retval: BUFREQ_OK: Data copied successfully
*         BUFREQ_E_NOT_OK: Data was not copied because an err occurred.
********************************************************************************
*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpCopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfo,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
#if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY))
    boolean isCopyTxData = PDUR_FALSE;
#endif  /* #if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY)) */

    uint16 destPduNum = PDUR_INIT_0;
    Std_ReturnType stdRet = PDUR_E_OK;
    BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;
    BufReq_ReturnType retValFun = BUFREQ_E_NOT_OK;
    const PduRDestPdu_Type* const* dstPduPtr = NULL_PTR;
    const PduRRoutingPath_Type* routPathPtr = NULL_PTR;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_PduR_UNMODIFIED_VAR_NOT_CONST" */
    uint16 curPartitionId = PDUR_INIT_0;

#if (STD_ON == PDUR_SUPPORT_MULTICORE)
    uint8 routeStatus[PDUR_PARTITION_SIZE] = { PDUR_ROUTE_NONE };
    curPartitionId = PDUR_CURRENT_PARTITION;
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */

    /* Check the initialization status. */
    PDUR_VALIDATE_INITIALIZED_CORE(PDUR_SID_LOTP_COPY_RX_DATA, stdRet);

#if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY))
    /* Enable constant null pointer checking. */
    PDUR_VALIDATE_POINTER(PDUR_SID_LOTP_COPY_RX_DATA, pduInfo, stdRet);
    /* Enable constant null pointer checking. */
    PDUR_VALIDATE_POINTER(PDUR_SID_LOTP_COPY_RX_DATA, bufferSizePtr, stdRet);
    /* The check passed and did not fail. */
    if( (PDUR_E_OK == stdRet) && (pduInfo->SduLength > PDUR_INIT_0) )
    {
        PDUR_VALIDATE_POINTER(PDUR_SID_LOTP_COPY_RX_DATA, pduInfo->SduDataPtr, stdRet);
    }
#endif  /* #if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY)) */

    /* Parameter check. */
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
    PDUR_VALIDATE_PDU_ID(PDUR_SID_LOTP_COPY_RX_DATA, id, stdRet);
    /* No err. */
    if( PDUR_E_OK == stdRet )
    {
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        routPathPtr = PDUR_ROUTING_PATH(id);
        /* PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_PduR_14.3" PolySpace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
        if( NULL_PTR != routPathPtr )
        {
            /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            dstPduPtr = routPathPtr->PduRDestPdu;
            /* PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        }
        else
        {
            /* Set err. */
            stdRet = PDUR_E_NOT_OK;
        }
    }
    /* No errors occurred. */
    if( (PDUR_E_OK == stdRet) && (NULL_PTR != dstPduPtr) )
    {
        /* This function only supports Pdu of IF type. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( PDUR_IS_IF_MODULE(routPathPtr->PduRSrcPdu) || PDUR_IS_UP_MODULE(routPathPtr->PduRSrcPdu) )
        {
            /* Set PDUR_E_NOT_OK. */
            stdRet = PDUR_E_NOT_OK;
        }
    }
    else
    {
        /* Set PDUR_E_NOT_OK. */
        stdRet = PDUR_E_NOT_OK;
    }
    /* No errors occurred. */
    if( PDUR_E_OK == stdRet )
    {
        /* For each destination in the routing path */
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        while( (NULL_PTR != dstPduPtr) && (NULL_PTR != PTR_VAL(dstPduPtr)) )
        {
            /* SWS_PduR_00646 Has the destination PDU been enabled? */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            if( (PDUR_INVALID_PATHGROUP_ID == PTR_VAL(dstPduPtr)->PduRRoutingPathGroupIdRef) ||
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
                (PDUR_TRUE == PduR_RoutingPathGroup[PTR_VAL(dstPduPtr)->PduRRoutingPathGroupIdRef].PduRIsEnabledAtInit) )
            {
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
                if( curPartitionId == PTR_VAL(dstPduPtr)->PduRPartitionRef )
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
                {
                    destPduNum = PduR_GetTpDstPdusOfPartition(routPathPtr, curPartitionId);
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                    if( PDUR_IS_UP_MODULE(PTR_VAL(dstPduPtr)) &&
                        (PDUR_INIT_0 == destPduNum) )
                    {
                        /* Req: SWS_PduR_00549 */
                        retValFun = PduR_Route_UpTpCopyRxData(PTR_VAL(dstPduPtr), pduInfo, bufferSizePtr);
                    }

#if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY))
                    if( PDUR_IS_TP_MODULE(PTR_VAL(dstPduPtr)) )
                    {
                        retValFun = PduR_TP_CopyRxDataEachDest(id, (PTR_VAL(dstPduPtr)), pduInfo, bufferSizePtr, &isCopyTxData);
                    }
#endif /* #if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY)) */
                }

#if (STD_ON == PDUR_SUPPORT_MULTICORE)
                if( curPartitionId == routPathPtr->PduRSrcPdu->PduRPartitionRef )
                {
                    if( curPartitionId != PTR_VAL(dstPduPtr)->PduRPartitionRef )
                    {
                        /* If the destination partition has not been routed to */
                        if( PDUR_ROUTE_NONE == routeStatus[PTR_VAL(dstPduPtr)->PduRPartitionRef] )
                        {
                            /* SWS_PduR_00851 SWS_PduR_00852 */
                            retValFun = PduR_Queue_LoTpCopyRxData(PDUR_QUEUE_PTR(PTR_VAL(dstPduPtr)->PduRPartitionRef), id, pduInfo, bufferSizePtr);

                            if( (BUFREQ_OK == retValFun) && (PDUR_INIT_0 != pduInfo->SduLength) )
                            {
                                /* It has been successfully routed to the destination partition */
                                routeStatus[PTR_VAL(dstPduPtr)->PduRPartitionRef] = PDUR_ROUTE_ALREADY;
                            }
                        }
                    }
                }
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */

                /* SWS_PduR_00803
                   In case of gatewaying between TPs, when one destination fails (Transmit returns
                   E_NOT_OK or TpTxConfirmation is called with an err), the other destinations
                   shall continue.
                */
                if( BUFREQ_OK != retVal )
                {
                    /* Set realy return value. */
                    retVal = retValFun;
                }
            }

            ++dstPduPtr;
        }
    }

#if ((defined PDUR_SUPPORT_DIAG) && (STD_ON == PDUR_SUPPORT_DIAG))
    PduR_Diag_Entry(id, pduInfo);
#endif /* #if ((defined PDUR_SUPPORT_DIAG) && (STD_ON == PDUR_SUPPORT_DIAG)) */

    /* SWS_PduR_00804
       In case of gatewaying between TPs, when all destinations fail, the reception side shall
       be stopped by returning BUFREQ_E_NOT_OK for the current call of CopyRxData or StartOfReception.
    */
    return retVal;
}

/*
********************************************************************************
* Function Name: PduR_LoTpRxIndication
*
* Explanation: Called after an I-PDU has been received via the TP API, the result
*              indicates whether the transmission was successful or not.
* (Synchronous)
*
* param: id -> Identification of the received I-PDU.
*        result -> Result of the reception.
*
* retval: None.
********************************************************************************
*/
FUNC(void, PDUR_CODE) PduR_LoTpRxIndication(PduIdType id, Std_ReturnType result)
{
#if ( (defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY) )
    boolean isGateWayRouting = FALSE;
#endif
    Std_ReturnType retVal = PDUR_E_OK;
    const PduRRoutingPath_Type* routPathPtr = NULL_PTR;
    /* PolySpace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_PduR_UNMODIFIED_VAR_NOT_CONST" */
    uint16 curPartitionId = PDUR_INIT_0;
    uint16 destPduNum = PDUR_INIT_0;

#if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY))
    PduR_TpBuffer_Type* tpBufPtr = NULL_PTR;
#endif /* #if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY)) */

#if (STD_ON == PDUR_SUPPORT_MULTICORE)
    uint8 routeStatus[PDUR_PARTITION_SIZE] = { PDUR_ROUTE_NONE };
    curPartitionId = PDUR_CURRENT_PARTITION;
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */

    /* Check the initialization status. */
    PDUR_VALIDATE_INITIALIZED_CORE(PDUR_SID_LOTP_RX_INDICATION, retVal);
    /* Parameter check. */
    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
    PDUR_VALIDATE_PDU_ID(PDUR_SID_LOTP_RX_INDICATION, id, retVal);
    /* The check passed and did not fail. */
    if( PDUR_E_OK == retVal )
    {
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        routPathPtr = PDUR_ROUTING_PATH(id);
    }
    /* No errors occurred. */
    if( (PDUR_E_OK == retVal) && (NULL_PTR != routPathPtr) )
    {
        /* This function only supports Pdu of IF type. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( PDUR_IS_IF_MODULE(routPathPtr->PduRSrcPdu) || PDUR_IS_UP_MODULE(routPathPtr->PduRSrcPdu) )
        {
            /* Set PDUR_E_NOT_OK. */
            retVal = PDUR_E_NOT_OK;
        }
    }
    else
    {
        /* Set PDUR_E_NOT_OK. */
        retVal = PDUR_E_NOT_OK;
    }
    /* No errors occurred. */
    if( PDUR_E_OK == retVal )
    {
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        const PduRDestPdu_Type* const* dstPduPtr = routPathPtr->PduRDestPdu;
#if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY))
        tpBufPtr = PduR_TP_GetTpBuffer(id);

        if( (PDUR_E_OK != result) && (NULL_PTR != tpBufPtr) )
        {
            /* Release the last node because the result is incorrect */
            PduR_TP_Buffer_FreeLastNode(tpBufPtr);
        }
        isGateWayRouting = PduR_RoutingPath_IsGateway(routPathPtr);
        /* If the routing path is a gateway */
        if( (PDUR_E_OK == result) && (PDUR_TRUE == isGateWayRouting) )
        {
            const uint16 tpDstPduNum = PduR_GetTpDstPdusOfPartition(routPathPtr, curPartitionId);

            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            if( (NULL_PTR != tpBufPtr) && (tpBufPtr->firstNodePointer == tpBufPtr->lastNodePointer) )
            {
                /* For each destination in the routing path */
                /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                while( (NULL_PTR != dstPduPtr) && (NULL_PTR != PTR_VAL(dstPduPtr)) )
                {
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
                    /* If the destination partition is the same as the current partition */
                    if( curPartitionId == PTR_VAL(dstPduPtr)->PduRPartitionRef )
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
                    {
                        /* The data is first forwarded to the upper-layer module */
                        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                        if( PDUR_IS_UP_MODULE(PTR_VAL(dstPduPtr)) && (PDUR_INIT_0 != tpDstPduNum) )
                        {
                            /* If TP buffer is not used or there is only one node, forward to the upper layer */
                            PduR_TP_GatewayUp(PTR_VAL(dstPduPtr));
                        }
                    }

                    ++dstPduPtr;
                }

                /* Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                dstPduPtr = routPathPtr->PduRDestPdu;
            }
        }
#endif /* #if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY)) */

        /* For each destination in the routing path */
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        while( (NULL_PTR != dstPduPtr) && (NULL_PTR != PTR_VAL(dstPduPtr)) )
        {
            /* SWS_PduR_00646 Has the destination PDU been enabled? */
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            if( (PDUR_INVALID_PATHGROUP_ID == PTR_VAL(dstPduPtr)->PduRRoutingPathGroupIdRef) ||
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
                (PDUR_TRUE == PduR_RoutingPathGroup[PTR_VAL(dstPduPtr)->PduRRoutingPathGroupIdRef].PduRIsEnabledAtInit) )
            {
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
                if( curPartitionId == PTR_VAL(dstPduPtr)->PduRPartitionRef )
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
                {
                    destPduNum = PduR_GetTpDstPdusOfPartition(routPathPtr, curPartitionId);
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                    if( PDUR_IS_UP_MODULE(PTR_VAL(dstPduPtr)) &&
                        (PDUR_INIT_0 == destPduNum) )
                    {
                        /* Req: SWS_PduR_00207 */
                        PduR_Route_UpTpRxIndication(PTR_VAL(dstPduPtr), result);
                    }

#if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY))
                    if( (PDUR_E_OK == result) && (PDUR_IS_TP_MODULE(PTR_VAL(dstPduPtr))) )
                    {
                        /* SWS_PDUR_00808 */
                        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                        if( PDUR_TP_THRESHOLD_INVALID != PTR_VAL(dstPduPtr)->PduRTpThreshold )
                        {
                            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                            if( PDUR_TRUE == PDUR_DST_PDU_THR_LIST(PTR_VAL(dstPduPtr)->PduRDestPduIdx).pduRTpThrFlag )
                            {
                                /*
                                The PDU Router module shall start the TP transmission on the destination bus by
                                calling <DstLoTp>_Transmit if result value is E_OK in the
                                PduR_<SrcLoTp>RxIndication even if the TP threshold was not reached.
                                */
                                retVal = PduR_TP_GatewayRouteTransmit(PTR_VAL(dstPduPtr));
                                /* Reset tp threshold flag. */
                                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
                                PDUR_DST_PDU_THR_LIST(PTR_VAL(dstPduPtr)->PduRDestPduIdx).pduRTpThrFlag = PDUR_FALSE;
                            }
                        }
                        /* Direct gatewaying? */
                        else
                        {
                            /* Req: SWS_PduR_00551
                            The <DstLoTp>_Transmit shall be called on each destination transport
                            protocol module within the PduR_<SrcLoTp>TpRxIndication, if result
                            is E_OK.
                            */
                            retVal = PduR_TP_GatewayRouteTransmit(PTR_VAL(dstPduPtr));
                        }
                    }
#endif /* #if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY)) */
                }
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
                else if( curPartitionId == routPathPtr->PduRSrcPdu->PduRPartitionRef )
                {
                    /* If the destination partition has not been routed to */
                    if( PDUR_ROUTE_NONE == routeStatus[PTR_VAL(dstPduPtr)->PduRPartitionRef] )
                    {
                        /* SWS_PduR_00853 */
                        PduR_Queue_LoTpRxIndication(PDUR_QUEUE_PTR(PTR_VAL(dstPduPtr)->PduRPartitionRef), id, result);

                        /* It has been successfully routed to the destination partition */
                        routeStatus[PTR_VAL(dstPduPtr)->PduRPartitionRef] = PDUR_ROUTE_ALREADY;
                    }
                }
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
            }

            ++dstPduPtr;
        }

#if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY))
        if( NULL_PTR != tpBufPtr )
        {
            /* PolySpace +1 DEFECT:UINT_CONSTANT_OVFL[Justified:Unset] "NSCA_Polyspace_PduR_UINT_CONSTANT_OVFL" Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            tpBufPtr->bufStatus &= (uint8)(~(uint8)PDUR_BUFFER_RX_BUSY);
        }
#endif /* #if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY)) */
    }

    /* Eliminate the warning. */
    if( PDUR_E_OK == retVal )
    {
        PDUR_UNUSED(retVal);
    }
}

/*
********************************************************************************
* Function Name: PduR_LoTpCopyTxData
*
* Explanation: This function is called to acquire the transmit data of an I-PDU
*              segment (N-PDU).
* (Synchronous)
*
* param: id -> Identification of the transmitted I-PDU.
*        pduInfo -> Provides the dstPduPtr buffer (SduDataPtr) and the number of
*                   bytes to be copied (SduLength).
*        retry -> This parameter is used to acknowledge transmitted data or to
*                 retransmit data after transmission problems.
*        availableDataPtr(out) -> Indicates the remaining number of bytes that
*                          are available in the upper layer module's Tx buffer.
*
* retval: BUFREQ_OK: Data has been copied to the transmit buffer completely as requested.
*         BUFREQ_E_BUSY: Request could not be fulfilled, because the required amount
*                        of Tx data is not available. The lower layer module may retry
*                        this call later on. No data has been copied.
*         BUFREQ_E_NOT_OK: Data has not been copied. Request failed.
********************************************************************************
*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfo,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
    Std_ReturnType stdRet = PDUR_E_OK;
    BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;
    const PduRDestPdu_Type* dstPduPtr = NULL_PTR;
    const PduRRoutingPath_Type* routPathPtr = NULL_PTR;

#if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST))
    PduRTpMul_Type* tpMulPtr;
#endif  /* #if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST)) */

    /* Check the initialization status. */
    PDUR_VALIDATE_INITIALIZED_CORE(PDUR_SID_LOTP_COPY_TX_DATA, stdRet);
    /* Enable constant null pointer checking. */
    PDUR_VALIDATE_POINTER(PDUR_SID_LOTP_COPY_TX_DATA, pduInfo, stdRet);
    /* Enable constant null pointer checking. */
    PDUR_VALIDATE_POINTER(PDUR_SID_LOTP_COPY_TX_DATA, availableDataPtr, stdRet);

    /* Parameter check. */
    PDUR_VALIDATE_DEST_PDU_ID(PDUR_SID_LOTP_COPY_TX_DATA, id, stdRet);
    /* The check passed and did not fail. */
    if( PDUR_E_OK == stdRet )
    {
        /* Set param. */
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        dstPduPtr = PDUR_DEST_PDU_PTR(id);
    }

    /* No errors occurred. */
    if( (PDUR_E_OK == stdRet) && (NULL_PTR != dstPduPtr) )
    {
        /* Get the routing path pointed to. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        routPathPtr = PDUR_ROUTING_PATH(dstPduPtr->PduRRoutPathRefId);
        /* Assertions about null pointers. */
        PDUR_ASSERT((NULL_PTR == routPathPtr) && (NULL_PTR == routPathPtr->PduRSrcPdu));

        /* This function only supports Pdu of IF type. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( PDUR_IS_IF_MODULE(dstPduPtr) || PDUR_IS_UP_MODULE(dstPduPtr) )
        {
            /* Set PDUR_E_NOT_OK. */
            stdRet = PDUR_E_NOT_OK;
        }
    }
    else
    {
        /* Set PDUR_E_NOT_OK. */
        stdRet = PDUR_E_NOT_OK;
    }

    /* No errors occurred. */
    if( PDUR_E_OK == stdRet )
    {
        /* SWS_PDUR_00805 Has the destination PDU been enabled? */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
        if( (PDUR_INVALID_PATHGROUP_ID == dstPduPtr->PduRRoutingPathGroupIdRef) ||
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
            (PDUR_TRUE == PduR_RoutingPathGroup[dstPduPtr->PduRRoutingPathGroupIdRef].PduRIsEnabledAtInit) )
        {
#if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY))
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            if( PDUR_IS_TP_MODULE(routPathPtr->PduRSrcPdu) )
            {
                /* Processing gateway. */
                retVal = PduR_TP_GateWayCopyTxData(dstPduPtr, pduInfo, retry, availableDataPtr);
            }
            else
#endif  /* #if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY)) */
            if( PDUR_IS_UP_MODULE(routPathPtr->PduRSrcPdu) )
            {
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
                /* If the source partition is different from the current partition */
                if( PDUR_CURRENT_PARTITION != routPathPtr->PduRSrcPdu->PduRPartitionRef )
                {
#if( (defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY) )
                    retVal = PduR_TP_GateWayCopyTxData(dstPduPtr, pduInfo, retry, availableDataPtr);
#endif /* #if( (defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY) ) */
                }
                else
                {
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
#if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST))
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                    tpMulPtr = PduR_GetTpMul(dstPduPtr->PduRRoutPathRefId);
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
                    if( (NULL_PTR == tpMulPtr) || (tpMulPtr->dstPduCnt == tpMulPtr->dstPduCntDyn) )
                    {
                        /* This routing path is not multicast. */
                        stdRet = PDUR_E_NOT_OK;
                    }
                    else
                    {
                        if( (uint8)PDUR_INIT_0 == tpMulPtr->dstPduCntDyn )
                        {
                            /* SWS_PduR_00631
                               For each position in the transmission, the request of PduR_<LoTP>CopyTxData
                               of the first destination lower layer module shall be forwarded with TpDataState
                               set to TP_CONFPENDING.
                            */
                            tpMulPtr->retryInfo.TpDataState = TP_CONFPENDING;
                            /* Count the number of forwarding destinations. */
                            tpMulPtr->dstPduCntDyn = (uint8)PDUR_INIT_1;
                        }
                        else
                            /* if( tpMulPtr->dstPduCntDyn > (uint8)PDUR_INIT_0 ) */
                        {
                            /* SWS_PduR_00632
                               All following calls of PduR_<LoTp>CopyTxData requests shall be forwarded
                               with TP_DATARETRY to allow the same data to be copied.
                            */
                            tpMulPtr->retryInfo.TpDataState = TP_DATARETRY;
                            /* Count the number of forwarding destinations. */
                            tpMulPtr->dstPduCntDyn++;
                            if( tpMulPtr->dstPduCnt == tpMulPtr->dstPduCntDyn )
                            {
                                /* SWS_PDUR_00812
                                   After all transport protocols have received their data the PDU Router
                                   module may confirm the data to the upper layer module.
                                */
                                tpMulPtr->retryInfo.TpDataState = TP_DATACONF;
                            }
                        }
                    }
#endif  /* #if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST)) */
                    /* There are no errors or non-multicast paths. */
#if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST))
                    if( (PDUR_E_OK == stdRet) || (NULL_PTR == tpMulPtr) )
                    {
#endif  /* #if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST)) */

#if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST))
                        /* Does this routing path belong to multicast? */
                        if( tpMulPtr != NULL_PTR )
                        {
                            /* Req: SWS_PduR_00549 Handle non-gateway functions. */
                            retVal = PduR_Route_UpTpCopyTxData(routPathPtr->PduRSrcPdu, pduInfo, &tpMulPtr->retryInfo, availableDataPtr);
                        }
                        else
#endif  /* #if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST)) */
                        {
                            /* Req: SWS_PduR_00549 Handle non-gateway functions. */
                            retVal = PduR_Route_UpTpCopyTxData(routPathPtr->PduRSrcPdu, pduInfo, retry, availableDataPtr);
                        }
#if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST))
                    }
#endif  /* #if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST)) */
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
                }
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
            }
            else
            {
                /* Do nothing. */
            }
        }
#if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY))
        else
        {
            /* The APIs listed above with Std_ReturnType shall return E_NOT_OK if the affected
                routing path group is disabled, and APIs with BufReq_ReturnType shall return
                BUFREQ_E_NOT_OK in the same situation.
            */
            retVal = BUFREQ_E_NOT_OK;
        }
#endif  /* #if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY)) */
    }
    /* SWS_PduR_00299 SWS_PduR_00676 */
    return retVal;
}

/*
********************************************************************************
* Function Name: PduR_LoTpTxConfirmation
*
* Explanation: This function is called after the I-PDU has been transmitted on
*              its network, the result indicates whether the transmission was
*              successful or not.
* (Synchronous)
*
* param: id -> Identification of the transmitted I-PDU.
*        result -> Result of the transmission of the I-PDU.
*
* retval: None.
********************************************************************************
*/
FUNC(void, PDUR_CODE) PduR_LoTpTxConfirmation(PduIdType id, Std_ReturnType result)
{
    Std_ReturnType retVal = PDUR_E_OK;
    const PduRDestPdu_Type* dstPduPtr = NULL_PTR;
    const PduRRoutingPath_Type* routPathPtr = NULL_PTR;

#if (STD_ON == PDUR_SUPPORT_MULTICORE)
    uint16 appId = PDUR_CURRENT_PARTITION;
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
#if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST))
    PduRTpMul_Type* tpMulPtr;
#endif  /* #if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST)) */

    /* Check the initialization status. */
    PDUR_VALIDATE_INITIALIZED_CORE(PDUR_SID_LOTP_TX_CONFIRMATION, retVal);
    /* Parameter check. */
    PDUR_VALIDATE_DEST_PDU_ID(PDUR_SID_LOTP_TX_CONFIRMATION, id, retVal);
    /* The check passed and did not fail. */
    if( PDUR_E_OK == retVal )
    {
        /* Set param. */
        /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        dstPduPtr = PDUR_DEST_PDU_PTR(id);
        /* Get the routing path pointed to. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        routPathPtr = PDUR_ROUTING_PATH(dstPduPtr->PduRRoutPathRefId);
        /* Assertions about null pointers. */
        PDUR_ASSERT((NULL_PTR == routPathPtr) && (NULL_PTR == routPathPtr->PduRSrcPdu));
    }
    /* No err and not null pointer. */
    if( (PDUR_E_OK == retVal) && (NULL_PTR != dstPduPtr) && (NULL_PTR != routPathPtr) )
    {
        /* This function only supports Pdu of IF type. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( PDUR_IS_IF_MODULE(dstPduPtr) || PDUR_IS_UP_MODULE(dstPduPtr) )
        {
            /* Set PDUR_E_NOT_OK. */
            retVal = PDUR_E_NOT_OK;
        }
    }
    else
    {
        /* Set PDUR_E_NOT_OK. */
        retVal = PDUR_E_NOT_OK;
    }
    /* No err and not null pointer. */
    if( PDUR_E_OK == retVal )
    {
        /* Does the source module and target support TxConfirmation? */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( (PDUR_TRUE != PDUR_MODULE_TX_CONFIRMATION(routPathPtr->PduRSrcPdu)) ||
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
            (PDUR_TRUE != PDUR_MODULE_TX_CONFIRMATION(dstPduPtr)) )
        {
            /* Set return value. */
            retVal = PDUR_E_NOT_OK;
        }
    }
    /* No errors occurred. */
    if( PDUR_E_OK == retVal )
    {
#if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY))
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" Polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_PduR_NIP" */
        if( PDUR_IS_TP_MODULE(routPathPtr->PduRSrcPdu) )
        {
            /* Release buffer. */
            PduR_TP_GetWayTxConfirmation(dstPduPtr, result);
        }
        /* Check whether the upper module is not the TP layer. */
        else
#endif  /* #if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY)) */

        /* When enabled, the TxConfirmation will be forwarded to the upper layer. Prerequisites: Lower layer and upper layer support TxConfirmation. */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
        if( PDUR_IS_UP_MODULE(routPathPtr->PduRSrcPdu) && (PDUR_TRUE == routPathPtr->PduRSrcPdu->PduRSrcPduUpTxConf) )
        {
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
            /* If both the source and destination partitions are the same as the current partition */
            if( (appId == routPathPtr->PduRSrcPdu->PduRPartitionRef)
                && (appId == dstPduPtr->PduRPartitionRef) )
            {
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
#if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST))
                tpMulPtr = PduR_GetTpMul(dstPduPtr->PduRRoutPathRefId);
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
                if( (NULL_PTR == tpMulPtr) || ((uint8)PDUR_INIT_0 == tpMulPtr->dstPduCntDyn) )
                {
                    retVal = PDUR_E_NOT_OK;
                }
                else
                {
                    /* SWS_PduR_00765
                        In case of multi cast transmission, the PDU Router module shall call the upper layer module using
                        <Up>_TpTxConfirmation after receiving the last PduR_<LoTp>TxConfirmation from the lower layer
                        transport protocol modules. The 'result' parameter shall be E_OK if at least one PduR_<LoTp>TxConfirmation
                        reported E_OK.
                    */
                    tpMulPtr->dstPduCntDyn--;
                    if( PDUR_E_OK == result )
                    {
                        /* The 'result' parameter shall be E_OK if at least one PduR_<LoTp>TxConfirmation reported E_OK. */
                        tpMulPtr->result = PDUR_E_OK;
                    }
                    /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                    if( (uint8)PDUR_INIT_0 == tpMulPtr->dstPduCntDyn )
                    {
                        /* Only the arrival of the confirmation of the last destination PDU will be called. */
                        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_PduR_NIV" */
                        PduR_Route_UpTpTxConfirmation(routPathPtr->PduRSrcPdu, tpMulPtr->result);
                    }
                }
                if( NULL_PTR == tpMulPtr )
#endif  /* #if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST)) */
                {
                    /* SWS_PduR_00301 */
                    PduR_Route_UpTpTxConfirmation(routPathPtr->PduRSrcPdu, result);
                }
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
            }
            else if( appId == dstPduPtr->PduRPartitionRef )
            {
#if( (defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY) )
                /* Release buffer. */
                PduR_TP_GetWayTxConfirmation(dstPduPtr, result);
#endif /* #if( (defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY) ) */

#if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST))
                tpMulPtr = PduR_GetTpMul(dstPduPtr->PduRRoutPathRefId);
                if( (NULL_PTR == tpMulPtr) || (tpMulPtr->dstPduCnt == (++tpMulPtr->dstPduCntDyn)) )
                {
#endif /* #if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST)) */
                    /* SWS_PduR_00858 */
                    PduR_Queue_LoTpTxConfirmation(PDUR_QUEUE_PTR(routPathPtr->PduRSrcPdu->PduRPartitionRef), id, result);
#if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST))
                }
#endif /* #if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST)) */
            }
            else if( appId == routPathPtr->PduRSrcPdu->PduRPartitionRef )
            {
                PduR_Route_UpTpTxConfirmation(routPathPtr->PduRSrcPdu, result);
            }
            else
            {
                /* Do nothing */
            }
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
        }
        else
        {
            /* Do nothing. */
        }
    }
    /* Eliminate the warning. */
    PDUR_UNUSED(retVal);
}

#if (STD_ON == PDUR_SUPPORT_MULTICORE)
/*
********************************************************************************
* Function Name: PduR_InitQueue
*
* Explanation: This function is called in the PduR_Init function to initialize
*              the queue associated with current ECUC partition.
* (Synchronous)
*
* param: None.
*
* retval: None.
********************************************************************************
*/
FUNC(void, PDUR_CODE) PduR_InitQueue(void)
{
    PduR_Queue_Init(PDUR_QUEUE_PTR(PDUR_CURRENT_PARTITION));
}

/*
********************************************************************************
* Function Name: PduR_MainLoop
*
* Explanation: This function is called periodically in the PduR_MainFunction function.
* (Synchronous)
*
* param: None.
*
* retval: None.
********************************************************************************
*/
FUNC(void, PDUR_CODE) PduR_MainLoop(void)
{
    /* process requests received in the queue */
    PduR_Queue_Process(PDUR_QUEUE_PTR(PDUR_CURRENT_PARTITION));
}
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */

#else   /* #if (STD_OFF == PDUR_ZERO_COST_OPERATION) */

/*
********************************************************************************
* Function Name: PduR_InitPBConfigParam
*
* Explanation: PduR init PBConfig data.
*
* param: ConfigPtr -> PBConfig data.
*
* retval: PDUR_E_OK : init PBConfigParam success.
*         PDUR_E_NOT_OK : init PBConfigParam failed.
********************************************************************************
*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_InitPBConfigParam  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    P2CONST(PduR_PBConfigType, AUTOMATIC, PDUR_APPL_CONST) ConfigPtr
)
{
    Std_ReturnType retVal = PDUR_E_OK;

    /* Set local routing table management variables. */
    PduR_PBcfgAdminPtr = ConfigPtr;

    return retVal;
}

#endif  /* #if (STD_OFF == PDUR_ZERO_COST_OPERATION) */

#define PDUR_STOP_SEC_CODE
/* MISRA C:2012 Rule-20.1 */
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
