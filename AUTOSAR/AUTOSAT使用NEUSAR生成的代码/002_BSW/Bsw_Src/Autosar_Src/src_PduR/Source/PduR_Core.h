/*
********************************************************************************
*
*  File name: PduR_Core.h
*
*  Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: ZhangDX/2019.09.06
* Change: New create.
* Cause: New
********************************************************************************
* Version: 2.1
* Author/Date: ZhangDX/2019.10.12
* Change: Modify the code format.
* Cause: Optimize
********************************************************************************
* Version: 2.2
* Author/Date: ZhangDX/2019.12.30
* Change: 1. Add PduR_ReportError() PduR_Det_ReportRuntimeError()
*         2. Replace the function PduR_Det_ErrorReport with the PduR_ReportError
*            function.
*         3. 1, 2 in order to achieve SWS_PduR_00100 and SWS_PDUR_00816 requirements.
* Cause: Update
********************************************************************************
* Version: 2.3
* Author/Date: ZhangDX/2020.01.06
* Change: 1. Delete the PduR module reference Std_Types.h and replace it with
*            ComStack_Types.h.
*         2. Remove redundant "ComStack_Cfg.h" and "ComStack_Types.h" files.
* Cause: Update
********************************************************************************
* Version: 2.4
* Author/Date: ZhangDX/2020.01.09
* Change: Added relevant code about Det error.
* Cause: Optimize
********************************************************************************
* Version: 2.5
* Author/Date: ZhangDX/2020.03.25
* Change: 1. Add notes.
*         2. Perform a QAC check and correct any errors that occur.
* Cause: Optimize
********************************************************************************
* Version: 3.0
* Author/Date: ZhangDX/2020.03.27
* Change: 1. Updated version information is 3.0.0.
*         2. Solve the problem of different names of function parameters.
* Cause: Clear QAC warning and updata to V3.0.
********************************************************************************
* Version: 3.1
* Author/Date: ZhangDX/2020.04.08
* Change: Change the file name to PduR_Core.
* Cause: Update. and BUG.
********************************************************************************
* Version: 3.2
* Author/Date: ZhangDX/2020.07.13
* Change: 1. Replace "req" with "Req".
*         2. Replace "PduR_ReportError" with "PDUR_REPORT_DET_ERROR".
*         3. Add #if (STD_ON == PDUR_DEV_ERROR_DETECT) pre-compilation before the
*            declaration and implementation of the three functions PduR_ReportError,
*            PduR_Det_ErrorReport and PduR_Det_ReportRuntimeError.
*         4. Move the pre-compiled content defined by the relevant function name
*            to the PduR_Core.h file.
*         5. Update the location of PduR Service ID pre-compiled content, defined
*            in PduR_Core.h.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: ZhangDX/2020.07.14
* Change: 1. Add PduR assertion definition.
*         2. Update the gateway function of the communication interface layer and
*            the FIFO function of the gateway.
*         3. Update the code format.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: ZhangDX/2020.07.15
* Change: The "serviceID" parameter of the related functions of each layer
*         was deleted and changed to a fixed "serviceID", which was defined
*         in PduR_Core.h.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: ZhangDX/2020.07.17
* Change: Add function PduR_RefreshFIFO to achieve SWS_PduR_00663 requirements.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: ZhangDX/2020.09.25
* Change: 1. Modify the errors that occurred during the code review on 2020.09.23.
*         2. Optimizing the code review on 2020.09.23 is a suggestion item given.
*         3. Optimized the coverage area of PDUR_ZERO_COST_OPERATION.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: ZhangDX/2020.09.27
* Change: Complete AutoSAR code style conversion.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: ZhangDX/2020.09.29
* Change: Add MemMap section.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: ZhangDX/2020.09.30
* Change: Modify the error in converting AutoSAR style.
*         1. Function parameters without pointers need to be converted.
*         2. The memclass used by local variables is AUTOMATIC.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: ZhangDX/2020.10.06
* Change: Add PostBuild function.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: ZhangDX/2020.10.10
* Change: Delete the semicolon at the end of the macro definition part about
*         DET, modify it to the realization of the macro definition.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: ZhangDX/2020.10.13
* Change: Optimize the implementation of PduRZeroCostOperation function code.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: zhangDX/2020.10.28
* Change: Solve the bug that the Det.h file is not included.
* Cause: Bugfix
********************************************************************************
* Version: 3.14
* Author/Date: ZhangDX/2020.11.03
* Change: The function declaration part does not need to increase the section
*         definition.
* Cause: Update
********************************************************************************
* Version: 3.15
* Author/Date: ZhangDX/2020.11.26
* Change: Solve the problem of using wild pointers when calling related API
*         functions when the PduR module is not initialized.
* Cause: Bugfix
********************************************************************************
* Version: 3.16
* Author/Date: ZhangDX/2020.11.27
* Change: Adjust the inclusion of Det.h to the PduR.h file.
* Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date: ZhangDX/2021.1.22
* Change: 1. (PduR-BUG-No.004)
*         Solve the BUG found in the unit test. Reason: The optimized code did
*         not pay attention to the judgment of this value, because the
*         PDUR_PB_CFG_PTR needs to pay attention to the state of the PduR_ModuleState
*         variable. If PduR_ModuleState is PDUR_ONLINE, there will be no situation
*         that the PDUR_PB_CFG_PTR is empty, but the optimized code does not judge
*         PduR_ModuleState, so it may appear When PDUR_PB_CFG_PTR is empty.
* Cause: BugFix
********************************************************************************
* Version: 3.18
* Author/Date: ZhangDX/2021.2.05
* Change: Delete the code related to debugging.
* Cause: Update
********************************************************************************
* Version: 3.19
* Author/Date: SunHQ/2022.09.20
* Change: Multicore distribution support.
* Cause: Update
********************************************************************************
* Version: 3.20
* Author/Date: SunHQ/2023.02.10
* Change: Modify the macro that controls the code implementation.
* Cause: Clear compile warning.
********************************************************************************
* Version: 3.21
* Author/Date: LuQ/2024.04.02
* Change: 1. Modify the comments format.
*         2. Modify P2CONST member labels.
* Cause: Optimization
********************************************************************************
* Version: 3.22
* Author/Date: LuQ/2024.05.13
* Change: Add Memmap segment definition.
* Cause: Optimization
********************************************************************************
* Version: 3.23
* Author/Date: LuQ/2024.09.23
* Change: Modify the comments format.
* Cause: Optimization
********************************************************************************
* Version: 3.24
* Author/Date: LuQ/2025.06.17
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef PDUR_CORE_H_
#define PDUR_CORE_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "PduR_PBcfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* Define module id. */
#define MODULE_ID_PDUR                              (51U)

/* PduR Service ID Define Start */
/* PduR_Init               */
#define PDUR_SERVICE_ID_PDUR_INIT                   (uint8)(0xF0U)
/* PduR_GetVersionInfo     */
#define PDUR_SERVICE_ID_GET_VERSION_INFO            (uint8)(0xF1U)
/* PduR_GetConfigurationId */
#define PDUR_SERVICE_ID_GET_CONFIGURATION_ID        (uint8)(0xF2U)
/* PduR_EnableRouting      */
#define PDUR_SERVICE_ID_ENABLE_ROUTING              (uint8)(0xF3U)
/* PduR_DisableRouting     */
#define PDUR_SERVICE_ID_DISABLE_ROUTING             (uint8)(0xF4U)

/* Req: SWS_PduR_00287. */
#if (STD_OFF == PDUR_ZERO_COST_OPERATION)
/* PduR_<User:Lo>TxConfirmation */
#define PDUR_SID_LO_TX_CONFIRMATION                 (uint8)(0x40U)
/* PduR_<User:Lo>TriggerTransmit */
#define PDUR_SID_LO_TRIGGER_TRANSMIT                (uint8)(0x41U)
/* PduR_<User:Lo>RxIndication */
#define PDUR_SID_LO_RX_INDICATION                   (uint8)(0x42U)
/* PduR_<User:Up>Transmit */
#define PDUR_SID_UP_TRANSMIT                        (uint8)(0x49U)
/* PduR_<User:Up>CancelTransmit */
#define PDUR_SID_UP_CANCEL_TRANSMIT                 (uint8)(0x4AU)
/* PduR_<User:Up>ChangeParameter */
#define PDUR_SID_UP_CHANGE_PARAMETER                (uint8)(0x4BU)
/* PduR_<User:Up>CancelReceive */
#define PDUR_SID_UP_CANCEL_RECEIVE                  (uint8)(0x4CU)
/* PduR_<User:LoTp>CopyTxData */
#define PDUR_SID_LOTP_COPY_TX_DATA                  (uint8)(0x43U)
/* PduR_<User:LoTp>CopyRxData */
#define PDUR_SID_LOTP_COPY_RX_DATA                  (uint8)(0x44U)
/* PduR_<User:LoTp>RxIndication */
#define PDUR_SID_LOTP_RX_INDICATION                 (uint8)(0x45U)
/* PduR_<User:LoTp>StartOfReception */
#define PDUR_SID_LOTP_START_OF_RECEPTION            (uint8)(0x46U)
/* PduR_<User:LoTp>TxConfirmation */
#define PDUR_SID_LOTP_TX_CONFIRMATION               (uint8)(0x48U)
/* PduR Service ID Define End   */

/* Custom implementation service ID. */
/* API: SetRoutingGroupTxBufferDefault */
#define PDUR_SID_SET_RGTB_DEF                       (uint8)(0x50U)
/* API: PduR_CheckModuleVailed */
#define PDUR_SID_CHECK_MODULE_VAILED                (uint8)(0x51U)
/* API: PduR_TP_BufferAllocation */
#define PDUR_SID_TP_BUF_ALLOC                       (uint8)(0x52U)
/* API: PduR_SetModule */
#define PDUR_SID_SET_MODULE                         (uint8)(0x53U)
/* PDUR GetWay. */
#define PDUR_SERVICE_ID_GETWAY                      (uint8)(0xFEU)

/*
The invalid value of PduRTpThreshold also indicates whether
the PDU supports on-the-fly gateway mode.
*/
#define PDUR_TP_THRESHOLD_INVALID                   (uint16)(0xFFFFU)
#define PDUR_TP_THRESHOLD_VALID                     (uint16)(0x00U)

#endif /* #if (STD_OFF == PDUR_ZERO_COST_OPERATION) */

/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* Call the PduR_ReportError function to report the Det error. */
#if (STD_ON == PDUR_DEV_ERROR_DETECT)
#define PDUR_REPORT_DET_ERROR(_api, _errorId)       PduR_ReportError(_api, _errorId);
#else   /* #if (STD_ON == PDUR_DEV_ERROR_DETECT) */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_REPORT_DET_ERROR(_api, _errorId)
#endif  /* #if (STD_ON == PDUR_DEV_ERROR_DETECT) */

/* Check initialization status and report Det error. */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_VALIDATE_INITIALIZED(_api, _retVal)                    \
        if(PDUR_UNINIT == PduR_GetInitState())                      \
        {                                                           \
            PDUR_REPORT_DET_ERROR(_api, PDUR_E_INVALID_REQUEST)     \
            (_retVal) = PDUR_E_NOT_OK;                              \
        }

/* Check if the parameter pointer is empty and report a Det error. */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define PDUR_VALIDATE_POINTER(_api, _ptr, _retVal)                  \
        if (NULL_PTR == (_ptr))                                     \
        {                                                           \
            PDUR_REPORT_DET_ERROR(_api, PDUR_E_PARAM_POINTER)       \
            (_retVal) = PDUR_E_NOT_OK;                              \
        }

#if (STD_OFF == PDUR_ZERO_COST_OPERATION)

/* Check pdu ID and report Det error. */
/* (PduR-BUG-No.004) */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_VALIDATE_PDU_ID(_api, _pduId, _retVal)                 \
        if((NULL_PTR == PDUR_PB_CFG_PTR) || (PDUR_ROUTING_PATH_CNT() <= (_pduId)))  \
        {                                                           \
            PDUR_REPORT_DET_ERROR(_api, PDUR_E_PDU_ID_INVALID)      \
            (_retVal) = PDUR_E_NOT_OK;                              \
        }

/* Check pdu ID and report Det error. */
/* (PduR-BUG-No.004) */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_VALIDATE_DEST_PDU_ID(_api, _pduId, _retVal)            \
        if((NULL_PTR == PDUR_PB_CFG_PTR) || (PDUR_DST_LIST_SIZE() <= (_pduId))) \
        {                                                           \
            PDUR_REPORT_DET_ERROR(_api, PDUR_E_PDU_ID_INVALID)      \
            (_retVal) = PDUR_E_NOT_OK;                              \
        }

/* Check pdu group ID and report Det error. */
/* (PduR-BUG-No.004) */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_VALIDATE_GROUPID(_api, _groupId, _retVal)              \
        if((NULL_PTR == PDUR_PB_CFG_PTR) || (PDUR_ROUTING_PATH_GROUP_CNT() <= (_groupId)))  \
        {                                                           \
            PDUR_REPORT_DET_ERROR(_api, PDUR_E_ROUTING_PATH_GROUP_ID_INVALID)    \
            (_retVal) = PDUR_E_NOT_OK;                              \
        }

/* PduR assert. */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_ASSERT(_expression)

/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_DEFAULT_VALUE_ELEMENT(_pdurDestPtr, _idx) (_pdurDestPtr)->PduRDefaultValue->PduRDefaultValueElement[(_idx)]
#endif /* #if (STD_OFF == PDUR_ZERO_COST_OPERATION) */

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
/* PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"
extern FUNC(uint16, PDUR_CODE) PduR_GetConfigId(void);
extern FUNC(PduR_StateType, PDUR_CODE) PduR_GetInitState(void);
extern FUNC(void, PDUR_CODE) PduR_SetInitState
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.5" */
    PduR_StateType state
);
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_InitPBConfigParam
(
    P2CONST(PduR_PBConfigType, AUTOMATIC, PDUR_APPL_CONST) ConfigPtr
);

#if (STD_ON == PDUR_DEV_ERROR_DETECT)
extern FUNC(void, PDUR_CODE) PduR_ReportError
(
    uint8 apiID,
    uint8 errorID
);
#endif  /* #if (STD_ON == PDUR_DEV_ERROR_DETECT) */

#if (STD_OFF == PDUR_ZERO_COST_OPERATION)

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_SetPduRIsEnabledAtInit
(
    boolean states,
    PduR_RoutingPathGroupIdType groupId
);

#if (STD_ON == PDUR_SUPPORT_GETWAY)
extern FUNC(void, PDUR_CODE) PduR_RefreshFIFO
(
    PduR_RoutingPathGroupIdType groupId
);
extern FUNC(void, PDUR_CODE) PduR_SetRoutingGroupTxBufferDefault
(
    PduR_RoutingPathGroupIdType groupId
);
#endif  /* #if (STD_ON == PDUR_SUPPORT_GETWAY) */

#if (STD_ON == PDUR_SUPPORT_MULTICORE)
extern FUNC(void, PDUR_CODE) PduR_InitQueue(void);
extern FUNC(void, PDUR_CODE) PduR_MainLoop(void);
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */

#endif /* #if (STD_OFF == PDUR_ZERO_COST_OPERATION) */
/* PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"

#endif /* #define PDUR_CORE_H_ */
