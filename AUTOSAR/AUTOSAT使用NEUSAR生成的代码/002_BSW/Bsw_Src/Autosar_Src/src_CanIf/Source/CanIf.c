/*
********************************************************************************
*
* File name: CanIf.c
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 2.0
* Author/Date: WangCong/2019.05.27
* Change: Updata to V2.0
*         (1)Delete invalid function.
*         (2)Add det function.
*         (3)Add comment.
* Cause: Add Function for V2.0
********************************************************************************
* Version: 2.1
* Author/Date: dongxu_zhang/2019.10.15
* Change: 1.Modify the code format.
* Cause: Optimization
********************************************************************************
* Version: 2.2
* Author/Date: WangCong/2019.10.16
* Change: 1.Modify CanIf_Transmit.
*         2.Modify CanIf_TxConfirmation.
*         3.Modify CanIf_RxIndication.
* Cause: Optimization
********************************************************************************
* Version: 2.3
* Author/Date: WangCong/2019.10.25
* Change: 1.Add Tx buffer Functions.
*         2.Modify Service Id.
* Cause: Add Functions
********************************************************************************
* Version: 3.0
* Author/Date: WangCong/2019.12.24
* Change: Modify the function related to the Multiple CAN Driver and Add precompile.
*         Function list: CanIf_Init
*                        CanIf_SetControllerMode
*                        CanIf_Transmit
*                        CanIf_TxConfirmation
*                        CanIf_RxIndication
*                        CanIf_TxQueueProcessing
*                        CanIf_TxQueueFilling
* Cause: Adding Functionality(Multiple CAN Driver support)
********************************************************************************
* Version: 3.1
* Author/Date: WangCong/2019.01.08
* Change: 1.Modify the function related to the Multiple CAN Driver.
*         Function list: CanIf_Init
*                        CanIf_RxIndication
*                        CanIf_TxQueueProcessing
*                        CanIf_TxQueueFilling
*         2.Set the ControllerModeSta to be CANIF_CS_STARTED during initialization
*           for debugging.
* Cause: Modify Code according to Configurations.
********************************************************************************
* Version: 3.2
* Author/Date: WangCong/2020.01.10
* Change: add Macro: CANIF_CANTP_SPECIAL_HANDLE
* Cause: Adapt to CanTp of the old version.
********************************************************************************
* Version: 3.3
* Author/Date: WangCong/2020.01.19
* Change: Synchronizing code with the DF project(Debugging completed).
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: WangCong/2020.02.26
* Change: Modify the Tx FIFO queue processing:
*         1.Reduce the number of check loops.
*         2.Clear the next Tx flag.
* Cause: Bugfix
********************************************************************************
* Version: 3.5
* Author/Date: WangCong/2020.03.16
* Change: Add "return errorId" to the function CanIf_TxQueueProcessing.
* Cause: Bugfix
********************************************************************************
* Version: 3.6
* Author/Date: WangCong/2020.03.25
* Change: 1.Modify header file reference
*         2.The functions which was not implemented add dummy processing.
* Cause: Clear QAC warning
********************************************************************************
* Version: 3.7
* Author/Date: WangCong/2020.03.30
* Change: Add comment.
* Cause: Code Walkthrough
********************************************************************************
* Version: 3.8
* Author/Date: lizhiheng/2020.04.28
* Change: Add CanIf_TxQueueFilling return value.
* Cause: Bugfix
********************************************************************************
* Version: 3.9
* Author/Date: WangCong/2020.05.07
* Change: Function CanIf_TxQueueFilling Add the handling of masked interrupts.
* Cause: Bugfix
********************************************************************************
* Version: 3.10
* Author/Date: WangCong/2020.05.12
* Change: Modify the code specification.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: WangCong/2020.05.31
* Change: Function CanIf_TxQueueFilling delete the handling of masked interrupts.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date: WangCong/2020.06.22
* Change: Function CanIf_RxIndication add processing of bit mask.
* Cause: Add function of bit mask.
********************************************************************************
* Version: 3.13
* Author/Date: ZhangDongxu/2020.07.08
* Change: Add the check module initialization status code; the functions involved are:
*         CanIf_GetVersionInfo
*         CanIf_SetTrcvMode
*         CanIf_GetTrcvMode
*         CanIf_GetTrcvWakeupReason
*         CanIf_SetTrcvWakeupMode
*         CanIf_ClearTrcvWufFlag
*         CanIf_CheckTrcvWakeFlag
*         CanIf_RxIndication
* Cause: Add function of bit mask.
********************************************************************************
* Version: 3.14
* Author/Date: ZhangDongxu/2020.07.08
* Change: Add the clearing Tx buffer function.
* Cause: Fix BusOff bug.
********************************************************************************
* Version: 3.15
* Author/Date: WangC/2020.09.22
* Change: Modify the function of CanIf_SetControllerMode.
* Cause: Bugfix
********************************************************************************
* Version: 3.16
* Author/Date: WangC/2020.09.25
* Change: Add the function of INDEX CanIfPrivateSoftwareFilterType.
* Cause: Add function.
********************************************************************************
* Version: 3.17
* Author/Date: WangC/2020.10.24
* Change: Modify the function name according to the AUTOSAR specification, add
*         MemMap.
* Cause: Optimization
********************************************************************************
* Version: 3.18
* Author/Date: WangC/2020.10.24
* Change: Modify the code according to QAC.
* Cause: Clear QAC warning.
********************************************************************************
* Version: 3.19
* Author/Date: WangC/2020.11.07
* Change: Add CANIF_SWFILTER_INDEX Rx for CANFD
* Cause: Add Function.
********************************************************************************
* Version: 3.20
* Author/Date: WangC/2020.12.02
* Change: Clear the Compiler warnings
* Cause: Optimization
********************************************************************************
* Version: 3.21
* Author/Date: WangC/2020.12.30
* Change: 1.Optimization code execution speed.
*         2.Modify Tx FIFO.
* Cause: BugFix and Optimization.
********************************************************************************
* Version: 3.22
* Author/Date: WangC/2021.1.8
* Change: 1.Add special function of Dlc checking for CA.
*         2.Add special call back function of AckErr handling.
* Cause: Add special function.
********************************************************************************
* Version: 3.23
* Author/Date: WangC/2021.1.28
* Change: 1.Clear Tx buffer in the function of CanIf_SetControllerMode.
*         2.Remove the handling of Can Tx buffer in function of CanIf_TxAckErrConfirmation.
*         3.Modify CanIf_RxIndication to be compatible with AUTOSAR version 4.0.3.
* Cause: Optimization and Compatibility.
********************************************************************************
* Version: 3.24
* Author/Date: WangC/2021.1.29
* Change: 1.Modify the function of CanIf_ClearTxBufferByChn to Avoid crossing the line.
* Cause: Bugfix
********************************************************************************
* Version: 3.25
* Author/Date: WangC/2021.2.7
* Change: 1.Modify the function of CanIf_Init,CanIf_TxQueueProcessing,
*           CanIf_CheckTxBufferEmpty for UT.
* Cause: Bugfix
********************************************************************************
* Version: 3.26
* Author/Date: WangC/2021.2.26
* Change: 1.Optimization the function of CanIf_Transmit, CanIf_RxIndication.
*         2.Add precompilation.
* Cause: Optimization
********************************************************************************
* Version: 3.27
* Author/Date: WangC/2021.3.3
* Change: Modify the errorId in the function of CanIf_RxIndication, CanIf_TxConfirmation
*         CanIf_ControllerBusOff,CanIf_ControllerModeIndication.
* Cause: Bugfix
********************************************************************************
* Version: 3.28
* Author/Date: WangC/2021.7.28
* Change: Modify the process of CanIf_Transmit_Process.
* Cause: Optimization
********************************************************************************
* Version: 3.29
* Author/Date: WangC/2021.8.2
* Change: Add precompiler for CanIf_TxQueueProcessing in the function of CanIf_Transmit_Process.
* Cause: Optimization
********************************************************************************
* Version: 3.30
* Author/Date: WangC/2021.8.2
* Change: Modify some function to be compatible with AUTOSAR version 4.3.1.
* Cause: Optimization
********************************************************************************
* Version: 3.31
* Author/Date: LiuHJ/2021.9.2
* Change: Clear the Compiler warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.32
* Author/Date: LiZH/2022.5.6
* Change: Modify the range of the index in the canif_init function.
* Cause: Optimization
********************************************************************************
* Version: 3.33
* Author/Date: LiZH/2022.6.17
* Change: Modify compile warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.34
* Author/Date: HuangF/2022.9.3
* Change: 1.Function CanIf_ClearTrcvWufFlag modify macro CANIF_CONTROLLER_NUM.
*         2.Function CanIf_CheckTrcvWakeFlag modify macro CANIF_CONTROLLER_NUM
*         and CANIF_SVID_CLEARTRCVWAKEFLAG.
*         3.Function CanIf_CheckTrcvWakeFlagIndication modify macro
*         CANIF_SVID_CLRTRCVWAKEFLAGINDC.
* Cause: Optimization
********************************************************************************
* Version: 3.35
* Author/Date: HuangF/2022.9.16
* Change: 1.Clear the Compiler warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.36
* Author/Date: LiDY/2023.2.2
* Change: The Optimizationd metaDataLen can be turned on according to the incoming
*         length of the configuration when CANIF_METADATA_SUPPORT is configurated.
* Cause: Optimization
********************************************************************************
* Version: 3.37
* Author/Date: LiDY/2023.2.2
* Change: Add the CanIf_TriggerTransmit function implementation.
* Cause: Optimization
********************************************************************************
* Version: 3.38
* Author/Date: LiDY/2023.4.12
* Change: Add CanID extened filtering.
* Cause: Bugfix
********************************************************************************
* Version: 3.39
* Author/Date: LiDY/2023.4.24
* Change: Add CanID extened filtering in CanIf_RxIndication_Process.
* Cause: Bugfix
********************************************************************************
* Version: 3.40
* Author/Date: LiDY/2023.5.16
* Change: Added support for metadatalength to dynamically generate canid in
*         CanIf_Transmit function.
* Cause: Update
********************************************************************************
* Version: 3.41
* Author/Date: TianG/2023.8.10
* Change: Clear warning
* Cause: Optimization
********************************************************************************
* Version: 3.42
* Author/Date: TianG/2023.10.8
* Change: Modifying compile Warnings
* Cause: Optimization
********************************************************************************
* Version: 3.43
* Author/Date: YanCL/2023.12.4
* Change: 1.Add the CanIf_Memcpy32 function.
*         2.In the CanIf_TxQueueFilling function, change the data copy mode
*           to use the CanIf_Memcpy32 function.
* Cause: Optimization
********************************************************************************
* Version: 3.44
* Author/Date: YanCL/2023.12.4
* Change: 1.In the CanIf_TxQueueFilling function, modify the CanIf_Memcpy32
*           function parameter under the TxBufPtr condition.
*         2.Added CanIf_Memcpy32 function declaration.
* Cause: Optimization
********************************************************************************
* Version: 3.45
* Author/Date: YanCL/2023.12.25
* Change: Fix QAC&Polyspace warning.
* Cause: Optimization
********************************************************************************
* Version: 3.46
* Author/Date: YanCL/2023.12.25
* Change: Call the CanTrcv_CheckWakeFlag function in the
*         CanIf_CheckTrcvWakeFlag function.
* Cause: Bugfix
********************************************************************************
* Version: 3.47
* Author/Date: YanCL/2024.3.12
* Change: In the CanIf_TrcvModeIndication &CanIf_SetTrcvMode function,
*         modify the error mode detection function of the Can transceiver.
* Cause: Bugfix
********************************************************************************
* Version: 3.48
* Author/Date: YanCL/2024.3.14
* Change: Fix compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.49
* Author/Date: YanCL/2024.4.2
* Change: 1.Modify the P2CONST incorrect labels.
*         2.Modify the annotation.
* Cause: Optimization
********************************************************************************
* Version: 3.50
* Author/Date: YanCL/2024.5.8
* Change: CanIf provides a callback interface to the upper layer to implement
*         DLC error related detection.
* Cause: Optimization
********************************************************************************
* Version: 3.51
* Author/Date: YanCL/2024.7.9
* Change: 1.Add Memmap segment definition.
*         2.Update copyright information.
* Cause: Update
********************************************************************************
* Version: 3.52
* Author/Date: YanCL/2024.8.28
* Change: Update copyright information.
* Cause: Update
********************************************************************************
* Version: 3.52
* Author/Date: YanCL/2025.3.13
* Change: Optimize the CanIf interface to keep the const tag when assigning
*         imported parameters to prevent abnormal tampering of imported parameter
*         values.
* Cause: Update
********************************************************************************
* Version: 3.53
* Author/Date: YanCL/2025.03.24
* Change: When Det is disabled, the validity of module related parameters can
*         also be checked.
* Cause: Update
********************************************************************************
* Version: 3.54
* Author/Date: YanCL/2025.03.26
* Change: 1.Fix the QAC warning and add the QAC deviation suppression comment.
*         2.Delete CanIf_Memcpy32.
* Cause: Update
********************************************************************************
* Version: 3.55
* Author/Date: YanCL/2025.04.24
* Change: 1.Fix the QAC warning and add the QAC deviation suppression comment.
*         2.Detailed Implementation of CanIf_SetDynamicTxId Function.
* Cause: Update
********************************************************************************
* Version: 3.56
* Author/Date: YanCL/2025.06.06
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.57
* Author/Date: YanCL/2025.06.20
* Change: If CanIf sends a message with an incorrect length, when sending a
*         message with a length exceeding the upper limit, it should retain the
*         maximum length for transmission.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "CanIf.h"

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

/*FXS Add*/
extern void CanIf_CheckSumDataAdd_Callout(uint32 txPduId,uint32 SduLength, uint8 *SduDataArray,uint8 txCANNodeID);

uint8 PMS_StsSwap_0x169RollingCounter=0;

/*FXS Add*/

#define CANIF_START_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanIf_MemMap.h"

/* Module initialization status, TRUE: initialization is successful; FALSE: not initialized. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanIf_NonSharedVar" */
static VAR(uint8, CANIF_VAR_INIT) CanIf_InitFlag = FALSE;

#define CANIF_STOP_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define CANIF_START_SEC_VAR_NO_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanIf_NonSharedVar" */
static VAR(CanIf_CanChGlobalType, CANIF_VAR_NO_INIT) CanIf_CanChGlobalInfo[CANIF_CONTROLLER_NUM];

#define CANIF_STOP_SEC_VAR_NO_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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
#define CANIF_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

static FUNC(void, CANIF_CODE) CanIf_Det_ErrorReport
(
    uint8 ApiId,
    uint8 errorId
);

#if (CANIF_CANTRCV_SUPPORT == STD_ON)
CANIF_STATIC_OPTIMIZATION FUNC(Std_ReturnType, CANIF_CODE) CanIf_SearchIdxByTransceiverId
(
    uint8 TransceiverId,
    P2VAR(uint8, AUTOMATIC, CANIF_APPL_DATA) IndexPtr
);
#endif  /* CANIF_CANTRCV_SUPPORT == STD_ON */

CANIF_STATIC_OPTIMIZATION FUNC(Std_ReturnType, CANIF_CODE) CanIf_SearchIdxByControllerId
(
    uint8 ControllerId,
    P2VAR(uint8, AUTOMATIC, CANIF_APPL_DATA) IndexPtr
);

#if (CANIF_PUB_TXBUFFERING == STD_ON)
CANIF_STATIC_OPTIMIZATION FUNC(void, CANIF_CODE) CanIf_TxQueueProcessing
(
    P2CONST(CanIf_CanObjectMapType, AUTOMATIC, CANIF_APPL_CONST) hthPtr,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanIf_Dir4.5" */
    Can_HwHandleType hth,
    uint8 ctrlId
);
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

#if (CANIF_PUB_TXBUFFERING == STD_ON)
CANIF_STATIC_OPTIMIZATION FUNC(Std_ReturnType, CANIF_CODE) CanIf_TxQueueFilling
(
    P2CONST(CanIf_TxPduCfgType, AUTOMATIC, CANIF_APPL_CONST) txPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) pduInfoPtr,
    uint16 sduLen,
    Can_IdType canId
);
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

CANIF_STATIC_OPTIMIZATION FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit_Process
(
    P2CONST(CanIf_TxPduCfgType, AUTOMATIC, CANIF_APPL_CONST) txPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) pduInfoPtr
);
CANIF_STATIC_OPTIMIZATION FUNC(void, CANIF_CODE) CanIf_RxIndication_Process
(
    P2CONST(CanIf_CanObjectMapType, AUTOMATIC, CANIF_APPL_CONST) hrhPtr,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr,
    Can_IdType canId
);

#if (CANIF_PRIVATE_SWFILTER_TYPE == CANIF_SWFILTER_INDEX)
CANIF_STATIC_OPTIMIZATION FUNC(void, CANIF_CODE) CanIf_RxIndication_Process_CanIdMap
(
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr,
    Can_IdType canId,
    P2CONST(uint16, AUTOMATIC, CANIF_APPL_CONST) canIdMapPtr
);
#endif  /* CANIF_PRIVATE_SWFILTER_TYPE == CANIF_SWFILTER_INDEX */

static FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckCanId
(
    Can_IdType canIdCode,
    Can_IdType canIdMask,
    Can_IdType canId,
    boolean canIdRang
);

#if (CANIF_PUB_TXBUFFERING == STD_ON)
static FUNC(void, CANIF_CODE) CanIf_ClearTxBufferByChn
(
    uint8 ctrlId
);
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

#if (CANIF_PUB_TXBUFFERING == STD_ON)
CANIF_STATIC_OPTIMIZATION FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckTxBufferEmpty
(
    P2CONST(CanIf_CanObjectMapType, AUTOMATIC, CANIF_APPL_CONST) hthPtr
);
#endif  /* CANIF_PUB_TXBUFFERING == STD_OFF */

#ifdef  CANIF_PRIVATE_DLC_CHECK_SPECIAL_CA
CANIF_STATIC_OPTIMIZATION FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckDlc_SpecialCA
(
    Can_IdType canId,
    PduLengthType dlc,
    PduLengthType sduLen
);
#endif  /* CANIF_PRIVATE_DLC_CHECK_SPECIAL_CA */

#ifdef  CANIF_AUTOSAR_VERSION_403_SUPPORT
CANIF_STATIC_OPTIMIZATION FUNC(Std_ReturnType, CANIF_CODE) CanIf_SearchIdxByHoh
(
    Can_HwHandleType hrh,
    P2VAR(uint8, AUTOMATIC, CANIF_APPL_DATA) IndexPtr
);
#endif  /* CANIF_AUTOSAR_VERSION_403_SUPPORT */

#define CANIF_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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

#define CANIF_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
* Function Name: CanIf_Init
*
* Explanation: CanIf module initialize.
*              (Synchronous)
*
* param: ConfigPtr: CanIf module configuration structure pointer.
*
* retval: None
********************************************************************************
*/
FUNC(void, CANIF_CODE) CanIf_Init
(
    P2CONST(CanIf_ConfigType, AUTOMATIC, CANIF_APPL_CONST) ConfigPtr
)
{
    uint16 index;
#if (CANIF_PUB_TXBUFFERING == STD_ON) 
    
#if (CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON)
    uint8 indexCtrl = CANIF_VALUE_ZERO;
    uint16 canObjectNum = CANIF_VALUE_ZERO;
#endif  /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */

    uint16 indexTxBuf;

#if (CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON)
    const CanIf_CanObjectMapType* canObjectMapPtr = NULL_PTR;
#else   /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanIf_UNMODIFIED_VAR_NOT_CONST" */
    const CanIf_CanObjectMapType* canObjectMapPtr = CanIf_Can_ObjectMap;
#endif  /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */

#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

    CANIF_DUMMY_STATEMENT(ConfigPtr);
    /* The loop initializes the global configuration table. */
    for( index = CANIF_VALUE_ZERO; index < CANIF_CONTROLLER_NUM; index++ )
    {
        /* Initialize global state. */
        CanIf_CanChGlobalInfo[index].PduModeCtrlSta = CANIF_OFFLINE;

#if (CANIF_NEUSAR_CANDRIVER == STD_ON)
        CanIf_CanChGlobalInfo[index].ControllerModeSta = CANIF_CS_STARTED;
#else   /* CANIF_NEUSAR_CANDRIVER == STD_ON. */
        CanIf_CanChGlobalInfo[index].ControllerModeSta = CANIF_CS_STOPPED;
#endif  /* CANIF_NEUSAR_CANDRIVER == STD_ON. */

        CanIf_CanChGlobalInfo[index].TxConfirmationState = CANIF_NO_NOTIFICATION;
        CanIf_CanChGlobalInfo[index].rxWakeupEvent = FALSE;
    }

#if (CANIF_PUB_TXBUFFERING == STD_ON)

#if (CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON)
    /* Initialize Tx Buffer. */
    for( indexCtrl = CANIF_VALUE_ZERO; indexCtrl < CANIF_CONTROLLER_NUM; indexCtrl++ )
    {
        canObjectMapPtr = CanIf_CanMultipeDrvInfo[indexCtrl].canObjectMapPtr;
        canObjectNum = CanIf_CanMultipeDrvInfo[indexCtrl].canObjectNum;
        for( index = CANIF_VALUE_ZERO; index < canObjectNum; index++ )
        {
            if( (CANIF_TRANSMIT == canObjectMapPtr[index].ObjectType) &&
                (NULL_PTR != canObjectMapPtr[index].read) &&
                (NULL_PTR != canObjectMapPtr[index].write) )
            {
                (*canObjectMapPtr[index].read) = CANIF_VALUE_ZERO;
                (*canObjectMapPtr[index].write) = CANIF_VALUE_ZERO;
                if( NULL_PTR != canObjectMapPtr[index].TxBufPtr )
                {
                    for( indexTxBuf = CANIF_VALUE_ZERO; indexTxBuf < canObjectMapPtr[index].TxBufSize; indexTxBuf++ )
                    {
                        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds " Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" */
                        canObjectMapPtr[index].TxBufPtr[indexTxBuf].pduId = CANIF_TXBUF_NOPDU;
                    }
                }
                else if( NULL_PTR != canObjectMapPtr[index].TxBufCANFDPtr)
                {
                    for( indexTxBuf = CANIF_VALUE_ZERO; indexTxBuf < canObjectMapPtr[index].TxBufSize; indexTxBuf++ )
                    {
                        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds " Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" */
                        canObjectMapPtr[index].TxBufCANFDPtr[indexTxBuf].pduId = CANIF_TXBUF_NOPDU;
                    }
                }
                else
                {
                    /* Do nothing. */
                }
            }
        }
    }
#else   /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */
    /* Initialize Tx Buffer. */
    for( index = CANIF_VALUE_ZERO; index < CANIF_INITHOHCFG_NUM_CAN; index++ )
    {
        if( (CANIF_TRANSMIT == canObjectMapPtr[index].ObjectType) &&
            (NULL_PTR != canObjectMapPtr[index].read) &&
            (NULL_PTR != canObjectMapPtr[index].write) )
        {
            (*canObjectMapPtr[index].read) = CANIF_VALUE_ZERO;
            (*canObjectMapPtr[index].write) = CANIF_VALUE_ZERO;
            if( NULL_PTR != canObjectMapPtr[index].TxBufPtr )
            {
                for( indexTxBuf = CANIF_VALUE_ZERO; indexTxBuf < canObjectMapPtr[index].TxBufSize; indexTxBuf++ )
                {
                    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
                    canObjectMapPtr[index].TxBufPtr[indexTxBuf].pduId = CANIF_TXBUF_NOPDU;
                }
            }
            else if( NULL_PTR != canObjectMapPtr[index].TxBufCANFDPtr)
            {
                for( indexTxBuf = CANIF_VALUE_ZERO; indexTxBuf < canObjectMapPtr[index].TxBufSize; indexTxBuf++ )
                {
                    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds " Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
                    canObjectMapPtr[index].TxBufCANFDPtr[indexTxBuf].pduId = CANIF_TXBUF_NOPDU;
                }
            }
            else
            {
                /* Do nothing. */
            }
        }
    }
#endif  /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */

#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

    /* Set CanIf init flag is TRUE. */
    CanIf_InitFlag = TRUE;

}
#ifdef CANIF_AUTOSAR_VERSION_431_SUPPORT
/*
********************************************************************************
* Function Name: CanIf_SetControllerMode
*
* Explanation: This service calls the corresponding CAN Driver service for
*               changing of the CAN controller mode.
*              (Asynchronous)
*
* param: ControllerId: CAN controller Id.
*        ControllerMode: CAN controller mode.
*
* retval: E_OK: Controller mode request has been accepted.
*         E_NOT_OK: Controller mode request has not been accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllerMode
(
    uint8 ControllerId,
    CanIf_ControllerModeType ControllerMode
)
{
    uint8 errorId = CANIF_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;
    Can_ControllerStateType transitionState = CAN_CS_STOPPED;
    uint8 canControllerId;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if( CANIF_CONTROLLER_NUM <= ControllerId )
    {
        errorId = CANIF_E_PARAM_CONTROLLERID;
    }
    else
    {
        canControllerId = CanIf_ControllerMap[ControllerId];
        /* Check that control mode is supported. */
        if( CANIF_CS_STOPPED == ControllerMode )
        {
            /* Set controllerMode Stop. */
            transitionState = CAN_CS_STOPPED;
            /* [SWS_CANIF_00866]. */
            CanIf_CanChGlobalInfo[ControllerId].PduModeCtrlSta = CANIF_TX_OFFLINE;
        }
        else if( CANIF_CS_STARTED == ControllerMode )
        {
            /* Set controllerMode Start. */
            transitionState = CAN_CS_STARTED;
            CanIf_CanChGlobalInfo[ControllerId].TxConfirmationState = CANIF_NO_NOTIFICATION;
        }
        else if( CANIF_CS_SLEEP == ControllerMode )
        {
            /* Set controllerMode Sleep. */
            transitionState = CAN_CS_SLEEP;
            CanIf_CanChGlobalInfo[ControllerId].PduModeCtrlSta = CANIF_OFFLINE;
        }
        else
        {
            /* Check that control mode is not supported. */
            errorId = CANIF_E_PARAM_CTRLMODE;
        }
        /* Check errorID. */
        if( CANIF_E_NO_ERR == errorId )
        {
            /* Call Can_SetControllerMode Set controller mode. */

#if (CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON)
            stdRet = CanIf_CanMultipeDrvInfo[ControllerId].CanIf_Can_SetCtrlModeFunc(canControllerId, transitionState);
#else   /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */
            stdRet = Can_SetControllerMode(canControllerId, transitionState);
#endif  /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */

            /* Set return value. */
            if( E_OK == stdRet )
            {
                
#if (CANIF_PUB_TXBUFFERING == STD_ON)
                CanIf_ClearTxBufferByChn(ControllerId);         
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

            }
        }
    }
    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_SETCONTROLLERMODE, errorId);

    return stdRet;
}

#else   /* CANIF_AUTOSAR_VERSION_431_SUPPORT */
/*
********************************************************************************
* Function Name: CanIf_SetControllerMode
*
* Explanation: This service calls the corresponding CAN Driver service for
*               changing of the CAN controller mode.
*              (Asynchronous)
*
* param: ControllerId: CAN controller Id.
*        ControllerMode: CAN controller mode.
*
* retval: E_OK: Controller mode request has been accepted.
*         E_NOT_OK: Controller mode request has not been accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllerMode
(
    uint8 ControllerId,
    CanIf_ControllerModeType ControllerMode
)
{
    uint8 errorId = CANIF_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;
    Can_ReturnType canRetVol;
    Can_StateTransitionType transitionState = CAN_T_STOP;
    uint8 canControllerId;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if( CANIF_CONTROLLER_NUM <= ControllerId )
    {
        errorId = CANIF_E_PARAM_CONTROLLERID;
    }
    else
    {
        canControllerId = CanIf_ControllerMap[ControllerId];
        /* Check that control mode is supported. */
        if( CANIF_CS_STOPPED == ControllerMode )
        {
            /* Set controllerMode Stop. */
            if( CANIF_CS_SLEEP == CanIf_CanChGlobalInfo[ControllerId].ControllerModeSta )
            {
                transitionState = CAN_T_WAKEUP;
            }
            else
            {
                transitionState = CAN_T_STOP;
            }
            /* [SWS_CANIF_00866]. */
            CanIf_CanChGlobalInfo[ControllerId].PduModeCtrlSta = CANIF_TX_OFFLINE;
        }
        else if( CANIF_CS_STARTED == ControllerMode )
        {
            /* Set controllerMode Start. */
            transitionState = CAN_T_START;
            CanIf_CanChGlobalInfo[ControllerId].TxConfirmationState = CANIF_NO_NOTIFICATION;
        }
        else if( CANIF_CS_SLEEP == ControllerMode )
        {
            /* Set controllerMode Sleep. */
            transitionState = CAN_T_SLEEP;
            CanIf_CanChGlobalInfo[ControllerId].PduModeCtrlSta = CANIF_OFFLINE;
        }
        else
        {
            /* Check that control mode is not supported. */
            errorId = CANIF_E_PARAM_CTRLMODE;
        }
        /* Check errorID. */
        if( CANIF_E_NO_ERR == errorId )
        {
            /* Call Can_SetControllerMode Set controller mode. */

#if (CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON)
            canRetVol = CanIf_CanMultipeDrvInfo[ControllerId].CanIf_Can_SetCtrlModeFunc(canControllerId, transitionState);
#else   /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */
            canRetVol = Can_SetControllerMode(canControllerId, transitionState);
#endif  /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */

            /* Set return value. */
            if( CAN_OK == canRetVol )
            {
                stdRet = E_OK;
                
#if (CANIF_PUB_TXBUFFERING == STD_ON)
                CanIf_ClearTxBufferByChn(ControllerId);         
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

            }
            else
            {
                stdRet = E_NOT_OK;
            }
        }
    }
    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_SETCONTROLLERMODE, errorId);

    return stdRet;
}
#endif  /* CANIF_AUTOSAR_VERSION_431_SUPPORT */

/*
********************************************************************************
* Function Name: CanIf_GetControllerMode
*
* Explanation: This service calls the corresponding CAN Driver service for
*              changing of the CAN controller mode.
*              (Synchronous)
*
* param: ControllerId: Abstracted CanIf ControllerId which is assigned to a CAN
*                      controller, which is requested for current operation mode.
*        ControllerModePtr: Pointer to a memory location, where the current mode
*                           of the CAN controller will be stored.
*
* retval: E_OK: Controller mode request has been accepted.
*         E_NOT_OK: Controller mode request has not been accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerMode
(
    uint8 ControllerId,
    P2VAR(CanIf_ControllerModeType, AUTOMATIC, CANIF_APPL_DATA) ControllerModePtr
)
{
    uint8 errorId = CANIF_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if( CANIF_CONTROLLER_NUM <= ControllerId )
    {
        errorId = CANIF_E_PARAM_CONTROLLERID;
    }
    else if( NULL_PTR == ControllerModePtr )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CANIF_E_PARAM_POINTER;
    }
    else
    {
        /* Set out param. */
        /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanIf_Dir4.14" Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanIf_TAINTED_PTR" */
        *ControllerModePtr = CanIf_CanChGlobalInfo[ControllerId].ControllerModeSta;
        /* Set return Value E_OK. */
        stdRet = E_OK;
    }
    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_GETCONTROLLERMODE, errorId);

    return stdRet;
}

/*
********************************************************************************
* Function Name: CanIf_Transmit
*
* Explanation: This service initiates a request for transmission of the
*              CAN L-PDU specified by the CanTxSduId and CAN related data
*              in the L-SDU structure.
*              (Synchronous)
*
* param: CanIfTxSduId: L-SDU handle to be transmitted.This handle specifies the
*                      corresponding CAN LSDU ID and implicitly the CAN Driver
*                      instance as well as the corresponding CAN controller device.
*        CanIfTxInfoPtr: Pointer to a structure with CAN L-SDU related data:DLC and
*                        pointer to CAN L-SDU buffer including the MetaData of dynamic
*                        L-PDUs.
*
* retval: E_OK: Transmit request has been accepted.
*         E_NOT_OK: Transmit request has not been accepted.
********************************************************************************
*/
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanIf_Dir4.5" */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit
(
    PduIdType CanIfTxSduId,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) CanIfTxInfoPtr
)
{
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanIf_UNMODIFIED_VAR_NOT_CONST" */
    uint8 errorId = CANIF_E_NO_ERR;
#endif

#if( CANIF_METADATA_SUPPORT == STD_ON )
    uint8 indexMetaData;
    uint32 dynamicIDparts = CANIF_VALUE_ZERO;
#endif

    Std_ReturnType stdRet = E_NOT_OK;
    const CanIf_TxPduCfgType* txPduPtr;
    PduInfoType txPduData = {NULL_PTR, CANIF_VALUE_ZERO};

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
        errorId = CANIF_E_UNINIT;
#endif
    }
    else if( CanIfTxSduId >= CANIF_TXPDU_NUM )
    {
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
        errorId = CANIF_E_INVALID_TXPDUID;
#endif
    }
    /* Polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_CanIf_Rule14.3" Polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
    else if( NULL_PTR == CanIfTxInfoPtr )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
        errorId = CANIF_E_PARAM_POINTER;
#endif
    }
    else
    {
        txPduPtr = &CanIf_TxPduCfg[CanIfTxSduId];

        /* Polyspace +1 DEFECT:TAINTED_PTR [JUstified:Unset] "NSCA_Polyspace_CanIf_TAINTED_PTR" Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanIf_Dir4.14" */
        if( (FALSE == txPduPtr->triggerTransmit) && (NULL_PTR == CanIfTxInfoPtr->SduDataPtr) )
        /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
            errorId = CANIF_E_PARAM_POINTER;
#endif
        }
        else
        {
            CanIf_Memcpy32(&txPduData, CanIfTxInfoPtr, sizeof(PduInfoType));

#if (CANIF_METADATA_SUPPORT == STD_ON)
            /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            if( (CANIF_TXPDU_DYNAMIC == txPduPtr->txPduType ) && (CANIF_VALUE_ZERO < txPduPtr->metaDataLen) )
            /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                for( indexMetaData = CANIF_VALUE_ZERO; indexMetaData < txPduPtr->metaDataLen; indexMetaData++ )
                {
                    /* Polyspace +1 MISRA-C3:10.7 [Justified:Unset] "NSCA_Polyspace_CanIf_TypeSubstitution" Polyspace +1 MISRA-C3:10.6 [Justified:Unset] "NSCA_Polyspace_CanIf_TypeSubstitution" Polyspace +1 DEFECT:TAINTED_PTR [JUstified:Unset] "NSCA_Polyspace_CanIf_TAINTED_PTR" Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanIf_Dir4.14" */
                    dynamicIDparts |= CanIfTxInfoPtr->SduDataPtr[indexMetaData + CanIfTxInfoPtr->SduLength - txPduPtr->metaDataLen]
                        << (CANIF_VALUE_EIGHT * indexMetaData);
                }
                txPduPtr->canId[CANIF_VALUE_ZERO] = (txPduPtr->canId[CANIF_VALUE_ZERO] & txPduPtr->canIdMask) | (dynamicIDparts & (~txPduPtr->canIdMask));
                /* Polyspace +1 DEFECT:TAINTED_PTR [JUstified:Unset] "NSCA_Polyspace_CanIf_TAINTED_PTR" Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanIf_Dir4.14" */
                txPduData.SduLength = CanIfTxInfoPtr->SduLength - txPduPtr->metaDataLen;
            }
#endif

            /* Check sdu length. [SWS CANIF 00894] Messages exceeding the maximum length should be send with the maximum length. */
            /* Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_CanIf_IDP" Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" */
            if( (CANIF_VALUE_ZERO == (CANIF_FD_CANID_TYPE & txPduPtr->canId[CANIF_VALUE_ZERO])) &&
                (CANIF_CAN20B_MAXLENGTH < txPduData.SduLength) )
            {
                txPduData.SduLength = CANIF_CAN20B_MAXLENGTH;

#if (CANIF_DEV_ERROR_DETECT == STD_ON)
                errorId = CANIF_E_DATA_LENGTH_MISMATCH;
#endif
            }
            else if( (CANIF_VALUE_ZERO != (CANIF_FD_CANID_TYPE & txPduPtr->canId[CANIF_VALUE_ZERO])) &&
                (CANIF_CANFD_MAXLENGTH < txPduData.SduLength) )
            {
                txPduData.SduLength = CANIF_CANFD_MAXLENGTH;

#if (CANIF_DEV_ERROR_DETECT == STD_ON)
                errorId = CANIF_E_DATA_LENGTH_MISMATCH;
#endif
            }
            else
            {
                /* Do nothing. */
            }

            /* Check controllerMode and pduModeCtrlState. */
            if( (CANIF_ONLINE == CanIf_CanChGlobalInfo[txPduPtr->ctrlId].PduModeCtrlSta) &&
                (CANIF_CS_STARTED == CanIf_CanChGlobalInfo[txPduPtr->ctrlId].ControllerModeSta) )
            {
                stdRet = CanIf_Transmit_Process(txPduPtr, &txPduData);
            }
        }
    }

#if (CANIF_DEV_ERROR_DETECT == STD_ON)
    CanIf_Det_ErrorReport(CANIF_SVID_TRANSMIT, errorId);
#endif

    return stdRet;
}

#if (CANIF_PUB_CANCEL_TRANSMIT_SUP == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_CancelTransmit
*
* Explanation: This is a dummy method introduced for interface compatibility.
*
* param: CanIfTxSduId: L-SDU handle to be transmitted.This handle specifies the
*                      corresponding CAN LSDU ID and implicitly the CAN Driver
*                      instance as well as the corresponding CAN controller device.
*
* retval: Always return E_OK
********************************************************************************
*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CancelTransmit
(
    PduIdType CanIfTxSduId
)
{
    uint8 errorId = CANIF_E_NO_ERR;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if( CANIF_TXPDU_NUM <= CanIfTxSduId )
    {
        errorId = CANIF_E_INVALID_TXPDUID;
    }
    else
    {
        CANIF_DUMMY_STATEMENT(CanIfTxSduId);
    }
    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_CANCELTRANSMIT, errorId);

    return E_OK;
}
#endif  /* #if (CANIF_PUBLIC_CANCEL_TRANSMIT_SUP == STD_ON) */

#if (CANIF_PUB_READRXPDU_DATA_API == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_ReadRxPduData
*
* Explanation: This service provides the CAN DLC and the received data of the
*              requested CanIfRxSduId to the calling upper layer.
*
* param: CanIfRxSduId: Receive L-SDU handle specifying the corresponding CAN L-SDU
*                      ID and implicitly the CAN Driver instance as well as the c-
*                      orresponding CAN controller device.
*        CanIfRxInfoPtr: Pointer to a structure with CAN L-SDU related data:DLC
*                        and pointer to CAN L-SDU buffer including the MetaData of
*                        dynamic L-PDUs.
*
* retval: E_OK: Request for L-SDU data has been accepted.
*         E_NOT_OK: No valid data has been received.
********************************************************************************
*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReadRxPduData
(
    PduIdType CanIfRxSduId,
    P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) CanIfRxInfoPtr
)
{
    /* This function is not implemented in the current version. */
}
#endif  /* #if (CANIF_PUB_READRXPDU_DATA_API == STD_ON) */

#if (CANIF_PUB_READTXPDU_NTF_STA_API == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_ReadTxNotifStatus
*
* Explanation: This service returns the confirmation status (confirmation
*              occurred or not) of a specific static or dynamic CAN Tx L-PDU,
*              requested by the CanIfTxSduId.
*
* param: CanIfTxSduId: L-SDU handle to be transmitted. This handle specifies the
*                      corresponding CAN LSDU ID and implicitly the CAN Driver
*                      instance as well as the corresponding CAN controller device.
*
* retval: Current confirmation status of the corresponding CAN Tx L-PDU.
********************************************************************************
*/
FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadTxNotifStatus
(
    PduIdType CanIfTxSduId
)
{
    /* This function is not implemented in the current version. */
}
#endif  /* #if (CANIF_PUB_READTXPDU_NTF_STA_API == STD_ON) */

#if (CANIF_PUB_READRXPDU_NTF_STA_API == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_ReadRxNotifStatus
*
* Explanation: This service returns the indication status (indication occurred or
*              not) of a specific CAN Rx L-PDU, requested by the CanIfRxSduId.
*
* param: CanIfRxSduId: Receive L-SDU handle specifying the corresponding CAN L-SDU
*                      ID and implicitly the CAN Driver instance as well as the
*                      corresponding CAN controller device.
*
* retval: Current indication status of the corresponding CAN Rx L-PDU.
********************************************************************************
*/
FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadRxNotifStatus
(
    PduIdType CanIfRxSduId
)
{
    /* This function is not implemented in the current version. */
}
#endif  /* #if (CANIF_PUB_READRXPDU_NTF_STA_API == STD_ON) */

/*
********************************************************************************
* Function Name: CanIf_SetPduMode
*
* Explanation: This service sets the requested mode at the L-PDUs of a predefined
*              logical PDU channel.
*
* param: ControllerId: All PDUs of the own ECU connected to the corresponding CanIf
*                      ControllerId, which is assigned to a physical CAN controller
*                      are addressed.
*        PduModeRequest: Requested PDU mode change.
*
* retval: E_OK: Request for mode transitionState has been accepted.
*         E_NOT_OK: Request for mode transitionState has not been accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPduMode
(
    uint8 ControllerId,
    CanIf_PduModeType PduModeRequest
)
{
    uint8 errorId = CANIF_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if( CANIF_CONTROLLER_NUM <= ControllerId )
    {
        errorId = CANIF_E_PARAM_CONTROLLERID;
    }
    /* Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_CanIf_Rule14.3" */
    else if( CANIF_ONLINE < PduModeRequest )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CANIF_E_PARAM_PDU_MODE;
    }
    else
    {
        /* Check controller mode state. */
        if( CANIF_CS_STARTED == CanIf_CanChGlobalInfo[ControllerId].ControllerModeSta )
        {
            /* Set config value. */
            CanIf_CanChGlobalInfo[ControllerId].PduModeCtrlSta = PduModeRequest;
            /* Set return value. */
            stdRet = E_OK;
        }
    }
    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_SETPDUMODE, errorId);

    return stdRet;
}

/*
********************************************************************************
* Function Name: CanIf_GetPduMode
*
* Explanation: This service reports the current mode of a requested PDU channel.
*
* param: ControllerId: All PDUs of the own ECU connected to the corresponding CanIf
*                      ControllerId, which is assigned to a physical CAN controller
*                      are addressed.
*        PduModePtr: Pointer to a memory location, where the current mode of the
*                    logical PDU channel will be stored.
*
* retval: E_OK: PDU mode request has been accepted.
*         E_NOT_OK: PDU mode request has not been accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetPduMode  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    uint8 ControllerId,
    P2VAR(CanIf_PduModeType, AUTOMATIC, CANIF_APPL_DATA) PduModePtr
)
{
    uint8 errorId = CANIF_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if( CANIF_CONTROLLER_NUM <= ControllerId )
    {
        errorId = CANIF_E_PARAM_CONTROLLERID;
    }
    else if( NULL_PTR == PduModePtr )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CANIF_E_PARAM_POINTER;
    }
    else
    {
        /* Set out param. */
        /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanIf_Dir4.14" Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanIf_TAINTED_PTR" */
        *PduModePtr = CanIf_CanChGlobalInfo[ControllerId].PduModeCtrlSta;
        /* Set return value. */
        stdRet = E_OK;
    }
    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_GETPDUMODE, errorId);

    return stdRet;
}

#if (CANIF_PUB_VERSION_API == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_GetVersionInfo
*
* Explanation: This service returns the version information of the called
*              CAN Interface module.
*
* param: VersionInfo:Pointer to where to store the version information of this module.
*
* retval: None.
********************************************************************************
*/
FUNC(void, CANIF_CODE) CanIf_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CANIF_APPL_DATA) VersionInfo
)
{
    uint8 errorId = CANIF_E_NO_ERR;

    /* Checking for development errors. */
    if( NULL_PTR == VersionInfo )
    {
        errorId = CANIF_E_PARAM_POINTER;
    }
    else
    {
        /* Set out param. */
        VersionInfo->vendorID = CANIF_VENDOR_ID;
        VersionInfo->moduleID = CANIF_MODULE_ID;
        VersionInfo->sw_major_version = CANIF_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = CANIF_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = CANIF_SW_PATCH_VERSION;
    }
    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_GETVERSIONINFO, errorId);
}
#endif  /* #if (CANIF_PUBLIC_VERSION_API == STD_ON) */

#if (CANIF_PUB_SETDYNAMIC_TXID_API == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_SetDynamicTxId
*
* Explanation: This service reconfigures the corresponding CAN identifier of the
*              requested CAN L-PDU.
*
* param: CanIfTxSduId: L-SDU handle to be transmitted.This handle specifies the
*                     corresponding CAN LSDU ID and implicitly the CAN Driver.
*                     instance as well as the corresponding CAN controller device.
*        CanId: Standard/Extended CAN ID of CAN L-SDU that shall be transmitted as
*               FD or conventional CAN frame.
*
* retval: None.
********************************************************************************
*/
FUNC(void, CANIF_CODE) CanIf_SetDynamicTxId
(
    PduIdType CanIfTxSduId,
    Can_IdType CanId
)
{
    uint8 errorId = CANIF_E_NO_ERR;

    CanIf_EnterCritical_0();
    /* initialization */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    /* parameter CanTxPduId */
    else if( CanIfTxSduId >= CANIF_TXPDU_NUM )
    {
        errorId = CANIF_E_INVALID_TXPDUID;
    }
    /* parameter CanId */
    else if( CANIF_CHECK_FOR_INVALID_CAN_ID(CanId) )
    {
        /* report DET error */
        errorId = CANIF_E_PARAM_CANID;
    }
    /* Can ID type changes no allowed */
    else if ( CANIF_CANID_GET_FD_TYPE(CanId) !=  CANIF_CANID_GET_FD_TYPE( CanIf_TxPduCfg[CanIfTxSduId].canId[CANIF_VALUE_ZERO] ) )
    {
        errorId = CANIF_E_PARAM_CANID;
    }
    else
    {
        /* set Tx L-PDU ID to new value */
        if( CANIF_TXPDU_DYNAMIC == CanIf_TxPduCfg[CanIfTxSduId].txPduType )
        {
            CanIf_TxPduCfg[CanIfTxSduId].canId[CANIF_VALUE_ZERO] = CanId;
        }
    }
    CanIf_LeaveCritical_0();

    /* Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_SETDYNAMICTXID, errorId);
}
#endif  /* #if (CANIF_PUBLIC_SETDYNAMIC_TXID_API == STD_ON) */

#if (CANIF_CANTRCV_SUPPORT == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_SetTrcvMode
*
* Explanation: This service changes the operation mode of the tansceiver
*              TransceiverId,via calling the corresponding CAN Transceiver
*              Driver service.
*
* param: TransceiverId:Abstracted CanIf TransceiverId, which is
*                      assigned to a CAN transceiver, which is requested for mode
*                      transitionState.
*        TransceiverMode:Requested mode transitionState.
*
* retval: E_OK: Transceiver mode request has been accepted.
*         E_NOT_OK: Transceiver mode request has notbeen accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvMode   /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    uint8 TransceiverId,
    CanTrcv_TrcvModeType TransceiverMode
)
{
    uint8 errorId = CANIF_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if( CANIF_TRCVCFG_NUM <= TransceiverId )
    {
        errorId = CANIF_E_PARAM_TRCV;
    }
    /* Check for Can transceiver mode errors. */
    else if( (TransceiverMode != CANTRCV_TRCVMODE_NORMAL) &&
             (TransceiverMode != CANTRCV_TRCVMODE_STANDBY) &&
             (TransceiverMode != CANTRCV_TRCVMODE_SLEEP) )
    {
        errorId = CANIF_E_PARAM_TRCVMODE;
    }
    else
    {
        stdRet = CanTrcv_SetOpMode(CanIf_TrcvMap[TransceiverId].CanTrcvId, TransceiverMode);
    }
    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_SETTRCVMODE, errorId);

    return stdRet;
}

/*
********************************************************************************
* Function Name: CanIf_GetTrcvMode
*
* Explanation: This function invokes CanTrcv_GetOpMode and updates the parameter
*              TransceiverModePtr with the value OpMode provided by CanTrcv.
*
* param: TransceiverId:Abstracted CanIf TransceiverId, which is assigned to a CAN
*                      transceiver, which is requested for current operation mode.
*        TransceiverModePtr:Requested mode of requested network the
*                           Transceiver is connected to.
*
* retval: E_OK: Transceiver mode request has been accepted.
*         E_NOT_OK: Transceiver mode request has not been accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvMode  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    P2VAR(CanTrcv_TrcvModeType, AUTOMATIC, CANIF_APPL_DATA) TransceiverModePtr,
    uint8 TransceiverId
)
{
    uint8 errorId = CANIF_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if( CANIF_TRCVCFG_NUM <= TransceiverId )
    {
        errorId = CANIF_E_PARAM_TRCV;
    }
    else if( NULL_PTR == TransceiverModePtr )
    {
        errorId = CANIF_E_PARAM_POINTER;
    }
    else
    {
        stdRet = CanTrcv_GetOpMode(CanIf_TrcvMap[TransceiverId].CanTrcvId, TransceiverModePtr);
    }
    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_GETTRCVMODE, errorId);

    return stdRet;
}

/*
********************************************************************************
* Function Name: CanIf_GetTrcvWakeupReason
*
* Explanation: This service returns the reason for the wake up of the transceiver
*              TransceiverId, via calling the corresponding CAN Transceiver Driver service.
*
* param: TransceiverId:Abstracted CanIf TransceiverId, which is assigned
*                      to a CAN transceiver, which is requested for wake up reason.
*        TrcvWuReasonPtr:provided pointer to where the requested transceiver
*                        wake up reason shall be returned.
*
* retval: E_OK: Transceiver wake up reason request has been accepted.
*         E_NOT_OK: Transceiver wake up reason request has not been accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvWakeupReason  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    uint8 TransceiverId,
    P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANIF_APPL_DATA) TrcvWuReasonPtr
)
{
    uint8 errorId = CANIF_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if( CANIF_TRCVCFG_NUM <= TransceiverId )
    {
        /* [SWS_CANIF_00537]. */ 
        errorId = CANIF_E_PARAM_TRCV;
    }
    else if( NULL_PTR == TrcvWuReasonPtr )
    {
        /* [SWS_CANIF_00649]. */
        errorId = CANIF_E_PARAM_POINTER;
    }
    else
    {
        /* [SWS_CANIF_00368]. [SWS_CANIF_00371]. */
        stdRet = CanTrcv_GetBusWuReason(CanIf_TrcvMap[TransceiverId].CanTrcvId, TrcvWuReasonPtr);
    }

    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_GETTRCVWUREASON, errorId);
    
    return stdRet;
}

/*
********************************************************************************
* Function Name: CanIf_SetTrcvWakeupMode
*
* Explanation: This function shall call CanTrcv_SetTrcvWakeupMode.
*
* param: TransceiverId:Abstracted CanIf TransceiverId, which is assigned
*                      to a CAN transceiver, which is requested for wake up
*                      notification mode transitionState.
*        TrcvWakeupMode:Requested transceiver wake up notification mode.
*
* retval: E_OK: Will be returned, if the wake up notifications state has been
*               changed to the requested mode.
*         E_NOT_OK: Will be returned, if the wake up notifications state change
*                   has failed or the parameter is out of the allowed range.
*                   The previous state has not been changed.
********************************************************************************
*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvWakeupMode  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    uint8 TransceiverId,
    CanTrcv_TrcvWakeupModeType TrcvWakeupMode
)
{
    uint8 errorId = CANIF_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if( CANIF_TRCVCFG_NUM <= TransceiverId )
    {
        /* [SWS_CANIF_00535]. */
        errorId = CANIF_E_PARAM_TRCV;
    }
    else if( CANTRCV_WUMODE_DISABLE < TrcvWakeupMode )
    {
        /* [SWS_CANIF_00536]. */
        errorId = CANIF_E_PARAM_TRCVWAKEUPMODE;
    }
    else
    {
        /* [SWS_CANIF_00373]. [SWS_CANIF_00372]. */
        stdRet = CanTrcv_SetWakeupMode(CanIf_TrcvMap[TransceiverId].CanTrcvId,TrcvWakeupMode);
    }
    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_GETTRCVWUMODE, errorId);

    return stdRet;
}

#endif  /* CANIF_CANTRCV_SUPPORT == STD_ON */

#if (CANIF_WAKEUP_SUPPORT == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_CheckWakeup
*
* Explanation: This service checks, whether an underlying CAN driver or a CAN
*              transceiver driver already signals a wakeup event.
*
* param: WakeupSource: Source device, which initiated the wake up event:
*                      CAN controller or CAN transceiver.
*
* retval: E_OK: Will be returned, if the check wake up request has been accepted.
*         E_NOT_OK: Will be returned, if the check wake up request has not been accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckWakeup
(
    EcuM_WakeupSourceType WakeupSource
)
{
    Std_ReturnType rtnVal = E_OK;
    /* This function is not implemented in the current version. */
    CANIF_DUMMY_STATEMENT(WakeupSource);

    return rtnVal;
}
#endif /* CANIF_WAKEUP_SUPPORT == STD_ON */

#if (CANIF_PUB_WUCHKVAL_SUP == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_CheckValidation
*
* Explanation: This service is performed to validate a previous wakeup event.
*
* param: WakeupSource: Source device which initiated the wake-up event and
*                      which has to be validated: CAN controller or CAN transceiver.
*
* retval: E_OK: Will be returned, if the check validation request has been accepted.
*         E_NOT_OK: Will be returned, if the check validation request has not been accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckValidation
(
    EcuM_WakeupSourceType WakeupSource
)
{
    /* This function is not implemented in the current version. */
    CANIF_DUMMY_STATEMENT(WakeupSource);
}
#endif  /* CANIF_PUB_WUCHKVAL_SUP == STD_ON */

#if (CANIF_PUB_TXCONFIRM_POLLING == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_GetTxConfirmationState
*
* Explanation: This service reports, if any TX confirmation has been done for the whole
*              CAN controller since the last CAN controller start.
*
* param: ControllerId: Abstracted CanIf ControllerId which is assigned to a
*                      CAN controller.
*
* retval: Combined TX confirmation status for all TX PDUs of the CAN controller.
********************************************************************************
*/
FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_GetTxConfirmationState  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    uint8 ControllerId
)
{
    uint8 errorId = CANIF_E_NO_ERR;
    CanIf_NotifStatusType NotifRet = CANIF_NO_NOTIFICATION;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if( CANIF_CONTROLLER_NUM <= ControllerId )
    {
        errorId = CANIF_E_PARAM_CONTROLLERID;
    }
    else
    {
        /* Return the first Tx confirmation state of the network. */
        NotifRet = CanIf_CanChGlobalInfo[ControllerId].TxConfirmationState;
    }
    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_GETTXCONFIRMSTA, errorId);

    return NotifRet;
}
#endif  /* CANIF_PUB_TXCONFIRM_POLLING == STD_ON */

#if (CANIF_CANTRCV_SUPPORT == STD_ON)

#if (CANIF_PUB_PN_SUPPORT == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_ClearTrcvWufFlag
*
* Explanation: Requests the CanIf module to clear the WUF flag of the designated
*              CAN transceiver.
*
* param: TransceiverId:Abstract CanIf TransceiverId, which is assigned to the
*                      designated CAN transceiver.
*
* retval: E_OK: Request has been accepted.
*         E_NOT_OK: Request has not been accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_ClearTrcvWufFlag
(
    uint8 TransceiverId
)
{
    /* This function is not implemented in the current version. */
    uint8 errorId = CANIF_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if( CANIF_TRCVCFG_NUM <= TransceiverId )
    {
        errorId = CANIF_E_PARAM_TRCV;
    }
    else
    {
        /* [SWS_CANIF_00766]. */
        stdRet = CanTrcv_ClearTrcvWufFlag(CanIf_TrcvMap[TransceiverId].CanTrcvId);
    }
    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_CLEARTRCVWUFLAG, errorId);

    return stdRet;
}

/*
********************************************************************************
* Function Name: CanIf_CheckTrcvWakeFlag
*
* Explanation: Requests the CanIf module to check the Wake flag of the designated
*              CAN transceiver.
*
* param: TransceiverId:Abstract CanIf TransceiverId, which is assigned to
*                     the designated CAN transceiver.
*
* retval: E_OK: Request has been accepted.
*         E_NOT_OK: Request has not been accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckTrcvWakeFlag
(
    uint8 TransceiverId
)
{
    uint8 errorId = CANIF_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if( CANIF_TRCVCFG_NUM <= TransceiverId )
    {
        errorId = CANIF_E_PARAM_TRCV;
    }
    else
    {
        /* Check the Can transceiver wake flag. */
        stdRet = CanTrcv_CheckWakeFlag(CanIf_TrcvMap[TransceiverId].CanTrcvId);
    }
    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_CHECKTRCVWAKEFLAG, errorId);

    return stdRet;
}
#endif  /* CANIF_PUB_PN_SUPPORT == STD_ON */

#endif  /* CANIF_CANTRCV_SUPPORT == STD_ON */

#if (CANIF_PUB_SETBAUDRATE_API == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_SetBaudrate
*
* Explanation: This service shall set the baud rate configuration of the CAN controller.
*                   Depending on necessary baud rate modifications the controller might
*                   have to reset.
*
* param: ControllerId:Abstract CanIf ControllerId which is assigned to a
*                     CAN controller, whose baud rate shall be set.
*                     BaudRateConfigID:references a baud rate configuration by ID
*                     (see CanControllerBaudRateConfigID).
*
* retval: E_OK: Service request accepted, setting of (new) baud rate started.
*         E_NOT_OK: Service request not accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetBaudrate
(
    uint8 ControllerId,
    uint16 BaudRateConfigID
)
{
    uint8 errorId = CANIF_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if( CANIF_CONTROLLER_NUM <= ControllerId )
    {
        errorId = CANIF_E_PARAM_CONTROLLERID;
    }
    else
    {
        stdRet = Can_SetBaudrate(CanIf_ControllerMap[ControllerId],BaudRateConfigID);
    }

    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_SETBAUDRATE, errorId);

    return stdRet;
}
#endif

#if (CANIF_PUB_ICOM_SUPPORT == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_SetIcomConfiguration
*
* Explanation: This service shall change the Icom Configuration of a CAN controller to
*              the requested one.
*
* param: ControllerId:Abstracted CanIf Controller Id which is assigned to a CAN
*                     controller ConfigurationId:Requested Configuration.
*
* retval: E_OK: Request accepted.
*         E_NOT_OK: Request denied.
********************************************************************************
*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetIcomConfiguration
(
    uint8 ControllerId,
    IcomConfigIdType ConfigurationId
)
{
    uint8 errorId = CANIF_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if( CANIF_CONTROLLER_NUM <= ControllerId )
    {
        errorId = CANIF_E_PARAM_CONTROLLERID;
    }
    else
    {
        stdRet = Can_SetIcomConfiguration(CanIf_ControllerMap[ControllerId],ConfigurationId);
    }

    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_SETBAUDRATE, errorId);

    return stdRet;

}
#endif  /* CANIF_PUB_ICOM_SUPPORT == STD_ON */

#if (CANIF_TRI_TRANSMIT_SUP == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_TriggerTransmit
* Explanation: Within this API, the upper layer module (called module) shall 
*              check whether the available data fits into the buffer size 
*              reported by PduInfoPtr->SduLength. If it fits, it shall copy its 
*              data into the buffer provided by PduInfoPtr->SduDataPtr and update
*              the sduLength of the actual copied data in PduInfoPtr->SduLength.
*              If not, it returns E_NOT_OK without changing PduInfoPtr.
*
* param: TxPduId:ID of the SDU that is requested to be transmitted.
*                PduInfoPtr:Contains a pointer to a buffer (SduDataPtr) to 
*                where the SDU data shall be copied, and the available buffer 
*                size in SduLengh.On return, the service will indicate the sduLength
*               of the copied SDU data in SduLength.
*
* retval: E_OK: SDU has been copied and SduLength indicates the number of copied bytes.
*         E_NOT_OK: No SDU data has been copied. PduInfoPtr must not be used since 
*                   it may contain a NULL pointer or point to invalid data.
********************************************************************************
*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_TriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
)
{
    uint8 errorId = CANIF_E_NO_ERR;

    Std_ReturnType stdRet = E_NOT_OK;
    const CanIf_TxPduCfgType* txPduPtr;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if( TxPduId >= CANIF_TXPDU_NUM )
    {
        errorId = CANIF_E_INVALID_TXPDUID;
    }
    else if( NULL_PTR == PduInfoPtr )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CANIF_E_PARAM_POINTER;
    }
    else
    {
        txPduPtr = &CanIf_TxPduCfg[TxPduId];
        if( TRUE == txPduPtr->triggerTransmit )
        {
            if( NULL_PTR != txPduPtr->trggTransmitFunc )
            {
                stdRet = txPduPtr->trggTransmitFunc(TxPduId, PduInfoPtr);
            }
        }
    }

    CanIf_Det_ErrorReport(CANIF_SVID_TRIGGERTRANSMIT, errorId);

    return stdRet;
}
#endif  /* CANIF_TRI_TRANSMIT_SUP == STD_ON */

/*
********************************************************************************
* Function Name: CanIf_TxConfirmation
*
* Explanation: This service confirms a previously successfully processed transmission
*              of a CAN TxPDU.
*
* param: CanTxPduId: L-PDU handle of CAN L-PDU successfully transmitted.
*                    This ID specifies the corresponding CAN L-PDU ID
*                    and implicitly the CAN Driver instance as well as the
*                    corresponding CAN controller device.
*
* retval: None.
********************************************************************************
*/
FUNC(void, CANIF_CODE) CanIf_TxConfirmation
(
    PduIdType CanTxPduId
)
{

    uint8 errorId = CANIF_E_NO_ERR;

    const CanIf_TxPduCfgType* txPduPtr;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )   /* Check the initialization status of the module. */
    {
        errorId = CANIF_E_UNINIT;
    }
    else if( CANIF_TXPDU_NUM <= CanTxPduId )
    {
        errorId = CANIF_E_PARAM_LPDU;
    }
    else
    {
        txPduPtr = &CanIf_TxPduCfg[CanTxPduId];

        /* Tx confirmation call back Function. */
        if( NULL_PTR != txPduPtr->TxCfmCallback )
        {
            txPduPtr->TxCfmCallback(txPduPtr->upperLayerPduId);
        }

#if (CANIF_PUB_TXCONFIRM_POLLING == STD_ON)
        /* Set Tx Confirmation State. */
        if (CANIF_NO_NOTIFICATION == CanIf_CanChGlobalInfo[txPduPtr->ctrlId].TxConfirmationState)
        {
            CanIf_CanChGlobalInfo[txPduPtr->ctrlId].TxConfirmationState = CANIF_TX_RX_NOTIFICATION;
        }
#endif

#if (CANIF_PUB_TXBUFFERING == STD_ON)
        /* Tx Buffer process start. */
        CanIf_TxQueueProcessing(txPduPtr->hthPtr,txPduPtr->hth, txPduPtr->ctrlId);
        /* Tx Buffer process end. */
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

    }

    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_TXCONFIRMATION, errorId);

}

#ifdef  CANIF_AUTOSAR_VERSION_403_SUPPORT
/*
********************************************************************************
* Function Name: CanIf_RxIndication
*
* Explanation: This service indicates a successful reception of a received CAN Rx
*              LPDU to the CanIf after passing all filters and validation checks
*
* param: Mailbox: dentifies the HRH and its corresponding CAN Controller.
*        PduInfoPtr: Pointer to the received L-PDU.
*
* retval: None.
********************************************************************************
*/
FUNC(void, CANIF_CODE) CanIf_RxIndication
(
    Can_HwHandleType Hrh,
    Can_IdType CanId,
    uint8 CanDlc,
    P2CONST(uint8, AUTOMATIC, CANIF_APPL_DATA) CanSduPtr
)
{
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
    uint8 errorId = CANIF_E_NO_ERR;
#endif

    uint8 indexCanIfCtrl = CANIF_VALUE_ZERO;
    const CanIf_CanObjectMapType* canObjectMapPtr;
    const PduInfoType* PduInfoPtr;
    PduInfoType pduInfo;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
        errorId = CANIF_E_UNINIT;
#endif
    }
    /* Checking for development errors. */
    else if( NULL_PTR == CanSduPtr )
    {
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
        errorId = CANIF_E_PARAM_POINTER;
#endif
    }

#if (CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON)
    else if( Hrh >= CanIf_CanMultipeDrvInfo[indexCanIfCtrl].canObjectNum )
    {
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
        errorId = CANIF_E_PARAM_HRH;
#endif
    }
#else   /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */
    else if( Hrh >= CANIF_INITHOHCFG_NUM_CAN )
    {
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
        errorId = CANIF_E_PARAM_HRH;
#endif
    }
#endif  /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */

    else if( E_OK != CanIf_SearchIdxByHoh(Hrh, &indexCanIfCtrl) )
    {
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
        errorId = CANIF_E_PARAM_CONTROLLERID;
#endif
    }
    else
    {

#if (CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON)
        canObjectMapPtr = CanIf_CanMultipeDrvInfo[indexCanIfCtrl].canObjectMapPtr;
#else   /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */
        canObjectMapPtr = CanIf_Can_ObjectMap;
#endif  /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */

        if( CANIF_RECEIVE != canObjectMapPtr[Hrh].ObjectType )
        {
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
            errorId = CANIF_E_INVALID_HOH;
#endif
        }
        else
        {
            pduInfo.SduDataPtr = (uint8*)CanSduPtr;
            pduInfo.SduLength = (uint32)CanDlc;
            PduInfoPtr = (const PduInfoType*)&pduInfo;

#if (CANIF_PRIVATE_SWFILTER_TYPE == CANIF_SWFILTER_INDEX)
            if( CANIF_VALUE_ZERO == (CanId & CANIF_EXTENDED_CANID_TYPE) )
            {
                if( CANIF_VALUE_ZERO != (CanId & CANIF_FD_CANID_TYPE) )
                {
                    if( NULL_PTR != CanIf_CanIdMapRxPduPtrList_CANFD[indexCanIfCtrl] )
                    {
                        CanIf_RxIndication_Process_CanIdMap(PduInfoPtr, (CanId & CANIF_VALUE_0x7FF),CanIf_CanIdMapRxPduPtrList_CANFD[indexCanIfCtrl]);
                    }
                }
                else
                {
                    if( NULL_PTR != CanIf_CanIdMapRxPduPtrList[indexCanIfCtrl] )
                    {
                        CanIf_RxIndication_Process_CanIdMap(PduInfoPtr, CanId,CanIf_CanIdMapRxPduPtrList[indexCanIfCtrl]);
                    }
                }
            }
            else
            {
                CanIf_RxIndication_Process(&canObjectMapPtr[Hrh], PduInfoPtr, CanId);
            }
#else   /* CANIF_PRIVATE_SWFILTER_TYPE == CANIF_SWFILTER_INDEX */
            CanIf_RxIndication_Process(&canObjectMapPtr[Hrh], PduInfoPtr, CanId);
#endif  /* CANIF_PRIVATE_SWFILTER_TYPE == CANIF_SWFILTER_INDEX */

        }
    }

#if (CANIF_DEV_ERROR_DETECT == STD_ON)
    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_RXINDICATION, errorId);
#endif

}
#else   /* CANIF_AUTOSAR_VERSION_403_SUPPORT */
/*
********************************************************************************
* Function Name: CanIf_RxIndication
*
* Explanation: This service indicates a successful reception of a received CAN Rx
*              LPDU to the CanIf after passing all filters and validation checks
*
* param: Mailbox: dentifies the HRH and its corresponding CAN Controller.
*        PduInfoPtr: Pointer to the received L-PDU.
*
* retval: None.
********************************************************************************
*/
FUNC(void, CANIF_CODE) CanIf_RxIndication
(
    P2CONST(Can_HwType, AUTOMATIC, CANIF_APPL_DATA) Mailbox,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
)
{
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
    uint8 errorId = CANIF_E_NO_ERR;
#endif

    uint8 indexCanIfCtrl = CANIF_VALUE_ZERO;
    const CanIf_CanObjectMapType* canObjectMapPtr;

#if (CANIF_NEUSAR_CANDRIVER == STD_ON)
    const CanIf_RxPduCfgType* rxPduPtr = &CanIf_RxPduCfg[Mailbox->Hoh];
    if( NULL_PTR != rxPduPtr->rxIndcCallback )
    {
        rxPduPtr->rxIndcCallback(rxPduPtr->upperLayerPduId, PduInfoPtr);
    }
#else   /* CANIF_NEUSAR_CANDRIVER == STD_ON */

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
        errorId = CANIF_E_UNINIT;
#endif
    }
    /* Checking for development errors. */
    else if( (NULL_PTR == Mailbox) || (NULL_PTR == PduInfoPtr) )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
        errorId = CANIF_E_PARAM_POINTER;
#endif
    }
    /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanIf_Dir4.14" Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanIf_TAINTED_PTR" */
    else if ( NULL_PTR == PduInfoPtr->SduDataPtr )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
        errorId = CANIF_E_PARAM_POINTER;
#endif
    }

#if (CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON)
    else if( Mailbox->Hoh >= CanIf_CanMultipeDrvInfo[indexCanIfCtrl].canObjectNum )
    {
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
        errorId = CANIF_E_PARAM_HRH;
#endif
    }
#else   /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */
    /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanIf_Dir4.14" Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanIf_TAINTED_PTR" */
    else if( Mailbox->Hoh >= CANIF_INITHOHCFG_NUM_CAN )
    {
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
        errorId = CANIF_E_PARAM_HRH;
#endif
    }
#endif  /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */

    else if( CANIF_CAN_CONTROLLER_NUM <= Mailbox->ControllerId )
    {
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
        errorId = CANIF_E_PARAM_CONTROLLERID;
#endif
    }
    /* Polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_CanIf_Rule14.3" Polyspace +1 DEFECT:USELESS_IF [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
    else if( CANIF_CANCTRL_NOMATCH != CanIf_CanControllerIdMap[Mailbox->ControllerId] )
    {
        indexCanIfCtrl = CanIf_CanControllerIdMap[Mailbox->ControllerId];

#if (CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON)
        canObjectMapPtr = CanIf_CanMultipeDrvInfo[indexCanIfCtrl].canObjectMapPtr;
#else   /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */
        canObjectMapPtr = CanIf_Can_ObjectMap;
#endif  /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */

        if( CANIF_RECEIVE != canObjectMapPtr[Mailbox->Hoh].ObjectType )
        {
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
            errorId = CANIF_E_INVALID_HOH;
#endif
        }
        else
        {

#if (CANIF_PRIVATE_SWFILTER_TYPE == CANIF_SWFILTER_INDEX)
            if( CANIF_VALUE_ZERO == (Mailbox->CanId & CANIF_EXTENDED_CANID_TYPE) )
            {
                if( CANIF_VALUE_ZERO != (Mailbox->CanId & CANIF_FD_CANID_TYPE) )
                {
                    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    if( NULL_PTR != CanIf_CanIdMapRxPduPtrList_CANFD[indexCanIfCtrl] )
                    {
                        CanIf_RxIndication_Process_CanIdMap(PduInfoPtr, (Mailbox->CanId & CANIF_VALUE_0x7FF),CanIf_CanIdMapRxPduPtrList_CANFD[indexCanIfCtrl]);
                    }
                }
                else
                {
                    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    if( NULL_PTR != CanIf_CanIdMapRxPduPtrList[indexCanIfCtrl] )
                    {
                        CanIf_RxIndication_Process_CanIdMap(PduInfoPtr, (Mailbox->CanId & CANIF_VALUE_0x7FF),CanIf_CanIdMapRxPduPtrList[indexCanIfCtrl]);
                    }
                }
            }
            else
            {
                CanIf_RxIndication_Process(&canObjectMapPtr[Mailbox->Hoh], PduInfoPtr, Mailbox->CanId);
            }
#else   /* CANIF_PRIVATE_SWFILTER_TYPE == CANIF_SWFILTER_INDEX */
            CanIf_RxIndication_Process(&canObjectMapPtr[Mailbox->Hoh], PduInfoPtr, Mailbox->CanId);
#endif  /* CANIF_PRIVATE_SWFILTER_TYPE == CANIF_SWFILTER_INDEX */

        }
    }
    else
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Do nothing. */
    }
#endif  /* CANIF_NEUSAR_CANDRIVER == STD_ON */
    CANIF_DUMMY_STATEMENT(indexCanIfCtrl);

#if (CANIF_DEV_ERROR_DETECT == STD_ON)
    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_RXINDICATION, errorId);
#endif

}
#endif  /* CANIF_AUTOSAR_VERSION_403_SUPPORT */

/*
********************************************************************************
* Function Name: CanIf_ControllerBusOff
*
* Explanation: This service indicates a Controller BusOff event referring to the
*              corresponding CAN Controller with the abstract CanIf ControllerId.
*
* param: ControllerId: Abstract CanIf ControllerId which is assigned to a
*                      CAN controller, where a BusOff occured.
*
* retval: None.
********************************************************************************
*/
FUNC(void, CANIF_CODE) CanIf_ControllerBusOff  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    uint8 ControllerId
)
{
    uint8 errorId = CANIF_E_NO_ERR;
    uint8 index = CANIF_VALUE_ZERO;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if( E_OK != CanIf_SearchIdxByControllerId(ControllerId, &index) )
    {
        errorId = CANIF_E_PARAM_CONTROLLER;
    }
    else
    {
        /* Set CAN controller mode to CANIF_CS_STOPPED. */
        CanIf_CanChGlobalInfo[index].ControllerModeSta = CANIF_CS_STOPPED;
        /*  Clear the information about a TxConfirmation */
        CanIf_CanChGlobalInfo[index].TxConfirmationState = CANIF_NO_NOTIFICATION;
        /*  [SWS_CANIF_00866] Set Pdu mode to CANIF_TX_OFFLINE. */
        CanIf_CanChGlobalInfo[index].PduModeCtrlSta = CANIF_TX_OFFLINE;
        /* Notification to the upper layer. */
#ifdef CanIf_User_ControllerBusOff
        CanIf_User_ControllerBusOff(index);
#endif  /* CanIf_User_ControllerBusOff */

#if (CANIF_PUB_TXBUFFERING == STD_ON)
        CanIf_ClearTxBufferByChn(index);
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

    }
    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_CONTROLLERBUSOFF, errorId);
}

#if (CANIF_CANTRCV_SUPPORT == STD_ON)

#if (CANIF_PUB_PN_SUPPORT == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_ConfirmPnAvailability
*
* Explanation: This service indicates that the transceiver is running in PN
*              communication mode referring to the corresponding CAN transceiver
*              with the abstract CanIf TransceiverId.
*
* param: TransceiverId:Abstract CanIf TransceiverId, which is assigned to a
*                      CAN transceiver, which was checked for PN availability.
*
* retval: None.
********************************************************************************
*/
FUNC(void, CANIF_CODE) CanIf_ConfirmPnAvailability
(
    uint8 TransceiverId
)
{
    uint8 errorId = CANIF_E_NO_ERR;
    uint8 index = CANIF_VALUE_ZERO;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if ( E_OK != CanIf_SearchIdxByTransceiverId(TransceiverId, &index) )
    {
        errorId = CANIF_E_PARAM_TRCV;
    }
    else
    {

#ifdef CANIF_CANSM_CBK_ENABLE
        /* Notification to the upper layer. */
        CanSM_ConfirmPnAvailability(index);
#endif  /* CANIF_CANSM_CBK_ENABLE */

    }
    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_CONFIRMPNAVAILAB, errorId);
}
#endif  /* CANIF_PUB_PN_SUPPORT == STD_ON */

#if (CANIF_PUB_PN_SUPPORT == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_ClearTrcvWufFlagIndication
*
* Explanation: This service indicates that the transceiver has cleared the WufFlag
*              referring to the corresponding CAN transceiver with the abstract CanIf
*              TransceiverId.
*
* param: TransceiverId:Abstract CanIf TransceiverId, which is assigned to a
*                      CAN transceiver, for which this function was called.
*
* retval: None.
********************************************************************************
*/
FUNC(void, CANIF_CODE) CanIf_ClearTrcvWufFlagIndication
(
    uint8 TransceiverId
)
{
    uint8 errorId = CANIF_E_NO_ERR;
    uint8 index = CANIF_VALUE_ZERO;
    
    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if ( E_OK != CanIf_SearchIdxByTransceiverId(TransceiverId, &index) )
    {
        errorId = CANIF_E_PARAM_TRCV;
    }
    else
    {
        /* Notification to the upper layer. */
#ifdef CanIf_User_ClearTrcvWufFlagIndication
        CanIf_User_ClearTrcvWufFlagIndication(index);
#endif  /* CanIf_User_CheckTransceiverWakeFlagIndication */

    }
    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_CLEARTRCVWUFLAGINDC, errorId);
}
#endif  /* CANIF_PUB_PN_SUPPORT == STD_ON */

#if (CANIF_PUB_PN_SUPPORT == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_CheckTrcvWakeFlagIndication
*
* Explanation: This service indicates that the check of the transceiver's wake-up flag
*               has been finished by the corresponding CAN transceiver with the abstract
*               CanIf TransceiverId. This indication is used to cope with the asynchronous
*               transceiver communication.
*
* param: TransceiverId: Abstract CanIf TransceiverId, which is assigned to a
*                       CAN transceiver, for which this function was called.
*
* retval: None.
********************************************************************************
*/
FUNC(void, CANIF_CODE) CanIf_CheckTrcvWakeFlagIndication
(
    uint8 TransceiverId
)
{
    uint8 errorId = CANIF_E_NO_ERR;
    uint8 index = CANIF_VALUE_ZERO;
    
    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if ( E_OK != CanIf_SearchIdxByTransceiverId(TransceiverId, &index) )
    {
        errorId = CANIF_E_PARAM_TRCV;
    }
    else
    {
        /* Notification to the upper layer. */
#ifdef CanIf_User_CheckTransceiverWakeFlagIndication
        CanIf_User_CheckTransceiverWakeFlagIndication(index);
#endif  /* CanIf_User_CheckTransceiverWakeFlagIndication */

    }
    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_CHECKTRCVWAKEFLAGINDC, errorId);
}
#endif  /* CANIF_PUB_PN_SUPPORT == STD_ON */

#endif  /* CANIF_CANTRCV_SUPPORT == STD_ON */

/*
********************************************************************************
* Function Name: CanIf_ControllerModeIndication
*
* Explanation: This service indicates a controller state transitionState referring to
*              the corresponding CAN controller with the abstract CanIf ControllerId.
*
* param: ControllerId: Abstract CanIf ControllerId which is assigned to a
*                      CAN controller, which state has been transitioned.
*        ControllerMode: Mode to which the CAN controller transitioned.
*
* retval: None.
********************************************************************************
*/
FUNC(void, CANIF_CODE) CanIf_ControllerModeIndication  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    uint8 ControllerId,
    CanIf_ControllerModeType ControllerMode
)
{
    uint8 errorId = CANIF_E_NO_ERR;
    uint8 index = CANIF_VALUE_ZERO;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if( E_OK != CanIf_SearchIdxByControllerId(ControllerId, &index) )
    {
        errorId = CANIF_E_PARAM_CONTROLLER;
    }
    else
    {
        /* Buffering the CAN controller state. */
        CanIf_CanChGlobalInfo[index].ControllerModeSta = ControllerMode;
        /* Notification to the upper layer. */

#ifdef CanIf_User_ControllerModeIndication
        CanIf_User_ControllerModeIndication(index, ControllerMode);
#endif  /* CanIf_User_ControllerModeIndication */

    }
    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_CONTROLLERMODEINDC, errorId);
}

#if (CANIF_CANTRCV_SUPPORT == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_TrcvModeIndication
*
* Explanation: This service indicates a transceiver state transitionState referring to the
*              corresponding CAN transceiver with the abstract CanIf TransceiverId.
*
* param: TransceiverId: Abstract CanIf TransceiverId, which is assigned to a
*                       CAN transceiver, which state has been transitioned.
*        TransceiverMode: Mode to which the CAN transceiver transitioned.
*
* retval: None.
********************************************************************************
*/
FUNC(void, CANIF_CODE) CanIf_TrcvModeIndication  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
(
    uint8 TransceiverId,
    CanTrcv_TrcvModeType TransceiverMode
)
{
    uint8 errorId = CANIF_E_NO_ERR;
    uint8 index = CANIF_VALUE_ZERO;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if ( E_OK != CanIf_SearchIdxByTransceiverId(TransceiverId, &index) )
    {
        errorId = CANIF_E_PARAM_TRCV;
    }
    /* Check for Can transceiver mode errors. */
    else if( (TransceiverMode != CANTRCV_TRCVMODE_NORMAL) &&
             (TransceiverMode != CANTRCV_TRCVMODE_STANDBY) &&
             (TransceiverMode != CANTRCV_TRCVMODE_SLEEP) )
    {
        errorId = CANIF_E_PARAM_TRCVMODE;
    }
    else
    {
        /* Notification to the upper layer. */

#ifdef CanIf_User_TransceiverModeIndication
        CanIf_User_TransceiverModeIndication(index, TransceiverMode);
#endif  /* CanIf_User_TransceiverModeIndication */

    }
    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_TRCVMODEINDC, errorId);
}
#endif  /* CANIF_CANTRCV_SUPPORT == STD_ON */

#if (CANIF_PUB_ICOM_SUPPORT == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_CurrentIcomConfiguration
*
* Explanation: This service shall inform about the change of the Icom Configuration of
*              a CAN controller using the abstract CanIf ControllerId
*
* param: ControllerId: Abstract CanIf ControllerId which is assigned to a
*                      CAN controller, which informs about the Configuration Id.
*        ConfigurationId: Active Configuration Id.
*        Error: ICOM_SWITCH_E_OK: No Error.
*               ICOM_SWITCH_E_FAILED: Switch to requested Configuration failed. Severe Error.
*
* retval: None.
********************************************************************************
*/
FUNC(void, CANIF_CODE) CanIf_CurrentIcomConfiguration
(
    uint8 ControllerId,
    IcomConfigIdType ConfigurationId,
    IcomSwitch_ErrorType Error
)
{
    uint8 errorId = CANIF_E_NO_ERR;
    uint8 index = CANIF_VALUE_ZERO;

    /* Checking for development errors. */
    if( TRUE != CanIf_InitFlag )
    {
        errorId = CANIF_E_UNINIT;
    }
    else if( E_OK != CanIf_SearchIdxByControllerId(ControllerId, &index) )
    {
        errorId = CANIF_E_PARAM_CONTROLLERID;
    }
    else
    {
        /* Notification to the upper layer. */
#ifdef CANIF_CANSM_CBK_ENABLE
        CanSM_CurrentIcomConfiguration(index,ConfigurationId,Error);
#endif  /* CANIF_CANSM_CBK_ENABLE */

    }
    /* Check Det errorId and call Det ErrorReport. */
    CanIf_Det_ErrorReport(CANIF_SVID_CURICOMCFG, errorId);
    
}
#endif  /* CANIF_PUB_ICOM_SUPPORT == STD_ON */

#if (CANIF_PUB_CANCEL_TRANSMIT_SUP == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_CancelTxConfirmation
* Explanation: 
*
* param: CanTxPduId: L-PDU handle of CAN L-PDU successfully transmitted.
*        PduInfoPtr: Contains a pointer to a buffer (SduDataPtr) to where the SDU
*                    data shall be copied, and the available buffer size in SduLengh.
*
* retval: None.
********************************************************************************
*/
FUNC(void, CANIF_CODE) CanIf_CancelTxConfirmation
(
    PduIdType CanTxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
)
{
    /* This function is not implemented in the current version. */
    CANIF_DUMMY_STATEMENT(CanTxPduId);
    CANIF_DUMMY_STATEMENT(PduInfoPtr);
}
#endif  /* CANIF_PUB_CANCEL_TRANSMIT_SUP == STD_ON */

#ifdef CANIF_PRIVATE_ACKERR_CHECK_SPECIAL_CA
/*
********************************************************************************
* Function Name: CanIf_TxAckErrConfirmation
*
* Explanation: 
*
* param: CanTxPduId: L-PDU handle of CAN L-PDU successfully transmitted.
*
* retval: None.
********************************************************************************
*/
FUNC(void, CANIF_CODE) CanIf_TxAckErrConfirmation
(
    PduIdType CanTxPduId
)
{
    const CanIf_TxPduCfgType* txPduPtr;
        
    if( CANIF_TXPDU_NUM <= CanTxPduId )
    {
        /* Do nothing. */
    }
    else
    {
        txPduPtr = &CanIf_TxPduCfg[CanTxPduId];
        
#if (CANIF_PUB_TXBUFFERING == STD_ON)
        CanIf_ClearTxBufferByChn(txPduPtr->ctrlId);
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

    }

}
#endif  /* CANIF_PRIVATE_ACKERR_CHECK_SPECIAL_CA */

/*
********************************************************************************
* Function Name: CanIf_Det_ErrorReport
*
* Explanation: Report error to Det Module.
*
* param: ApiId: the Api Id of CanIf.
*        errorId: Error Id defined in CanIf_Types.h.
*
* retval: None.
********************************************************************************
*/
static FUNC(void, CANIF_CODE) CanIf_Det_ErrorReport
(
    uint8 ApiId,
    uint8 errorId
)
{
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
    if( errorId != CANIF_E_NO_ERR ) /* Error detected. */
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID_DET, ApiId, errorId); /* Report Error to Det. */
    }
#else   /* #if (CANIF_DEV_ERROR_DETECT == STD_ON) */
    {
        CANIF_DUMMY_STATEMENT(ApiId);
        CANIF_DUMMY_STATEMENT(errorId);
    }
#endif  /* #if (CANIF_DEV_ERROR_DETECT == STD_ON) */
}

#if (CANIF_CANTRCV_SUPPORT == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_SearchIdxByTransceiverId
*
* Explanation: Search Idx By Transceiver Id.
*
* param: TransceiverId: Transceiver Id.
*        IndexPtr: Index buf.
*
* retval: E_OK,E_NOT_OK.
********************************************************************************
*/
CANIF_STATIC_OPTIMIZATION FUNC(Std_ReturnType, CANIF_CODE) CanIf_SearchIdxByTransceiverId
(
    uint8 TransceiverId,
    P2VAR(uint8, AUTOMATIC, CANIF_APPL_DATA) IndexPtr
)
{
    Std_ReturnType stdRet = E_NOT_OK;
    uint8 index;

    if( NULL_PTR != IndexPtr )
    {
        /* Search the network index by TransceiverId. */
        for( index = CANIF_VALUE_ZERO; index < CANIF_TRCVCFG_NUM; index++ )
        {
            if( TransceiverId == CanIf_TrcvMap[index].CanTrcvId )
            {
                *IndexPtr = index;
                stdRet = E_OK;
            }
        }
    }

    return stdRet;
}
#endif  /* CANIF_CANTRCV_SUPPORT == STD_ON */

/*
********************************************************************************
* Function Name: CanIf_SearchIdxByControllerId
*
* Explanation: Search Idx By Controller Id.
*
* param: ControllerId: Controller Id.
*        IndexPtr: Index buf.
*
* retval: E_OK,E_NOT_OK.
********************************************************************************
*/
CANIF_STATIC_OPTIMIZATION FUNC(Std_ReturnType, CANIF_CODE) CanIf_SearchIdxByControllerId
(
    uint8 ControllerId,
    P2VAR(uint8, AUTOMATIC, CANIF_APPL_DATA) IndexPtr
)
{
    Std_ReturnType stdRet = E_NOT_OK;
    uint8 index;

    /* Search the network index by ControllerId. */
    for( index = CANIF_VALUE_ZERO; index < CANIF_CONTROLLER_NUM; index++ )
    {
        if( ControllerId == CanIf_ControllerMap[index] )
        {
            *IndexPtr = index;
            stdRet = E_OK;
            break;
        }
    }
    
    return stdRet;
}

#if (CANIF_PUB_TXBUFFERING == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_TxQueueProcessing
*
* Explanation: Search Idx By Transceiver Id.
*
* param: hth: Hardware object Id.
*        CanTxPduId: ID number of the sent PDU.
*
* retval: errorId defined in CanIf_Types.h.
********************************************************************************
*/
CANIF_STATIC_OPTIMIZATION FUNC(void, CANIF_CODE) CanIf_TxQueueProcessing
(
    P2CONST(CanIf_CanObjectMapType, AUTOMATIC, CANIF_APPL_CONST) hthPtr,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanIf_Dir4.5" */
    Can_HwHandleType hth,
    uint8 ctrlId
)
{

#ifdef CANIF_AUTOSAR_VERSION_431_SUPPORT
    Std_ReturnType stdRet;
#else
    Can_ReturnType canRet;
#endif  /* CANIF_AUTOSAR_VERSION_431_SUPPORT */

    Can_PduType canPduInfo = {CANIF_VALUE_ZERO};
    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanIf_UNMODIFIED_VAR_NOT_CONST" */
    CanIf_TxBufType* TxBufPtr = hthPtr->TxBufPtr;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanIf_UNMODIFIED_VAR_NOT_CONST" */
    CanIf_TxBuf_CANFDType* TxBufCANFDPtr = hthPtr->TxBufCANFDPtr;

    CANIF_DUMMY_STATEMENT(ctrlId);
    /* Check Buffer exist or not. */
    if( NULL_PTR != hthPtr->TxBufCANFDPtr )
    {
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
        if( ((*hthPtr->read) != (*hthPtr->write))
                  || (CANIF_TXBUF_NOPDU != TxBufCANFDPtr[CANIF_VALUE_ZERO].pduId) )
        {
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
            canPduInfo.swPduHandle = TxBufCANFDPtr[(*hthPtr->read)].pduId;
            canPduInfo.length = TxBufCANFDPtr[(*hthPtr->read)].txLen;
            canPduInfo.sdu = &TxBufCANFDPtr[(*hthPtr->read)].txData[CANIF_VALUE_ZERO];
            canPduInfo.id = TxBufCANFDPtr[(*hthPtr->read)].canId;

#ifdef CANIF_AUTOSAR_VERSION_431_SUPPORT

#if (CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON)
            stdRet = CanIf_CanMultipeDrvInfo[ctrlId].CanIf_Can_WriteFunc(hth, &canPduInfo);
#else   /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */
            /* Polyspace +1 DEFECT:PADDING_INFO_LEAK [Justified:Unset] "NSCA_Polyspace_CanIf_PADDING_INFO_LEAK" */
            stdRet = Can_Write(hth, &canPduInfo);
#endif  /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */

            if( E_OK == stdRet )
            {
                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
                TxBufCANFDPtr[(*hthPtr->read)].pduId = CANIF_TXBUF_NOPDU;
                (*hthPtr->read)++;
            }

#else   /* CANIF_AUTOSAR_VERSION_431_SUPPORT */

#if (CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON)
            canRet = CanIf_CanMultipeDrvInfo[ctrlId].CanIf_Can_WriteFunc(hth, &canPduInfo);
#else   /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */
            /* Polyspace +1 DEFECT:PADDING_INFO_LEAK [Justified:Unset] "NSCA_Polyspace_CanIf_PADDING_INFO_LEAK" */
            canRet = Can_Write(hth, &canPduInfo);
#endif  /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */

            if( CAN_OK == canRet )
            {
                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
                TxBufCANFDPtr[(*hthPtr->read)].pduId = CANIF_TXBUF_NOPDU;
                (*hthPtr->read)++;
            }
#endif  /* CANIF_AUTOSAR_VERSION_431_SUPPORT */

        }
    }
    else if( NULL_PTR != hthPtr->TxBufPtr )
    {
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
        if( ((*hthPtr->read) != (*hthPtr->write))
          || (CANIF_TXBUF_NOPDU != TxBufPtr[CANIF_VALUE_ZERO].pduId) )
        {
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
            canPduInfo.swPduHandle = TxBufPtr[(*hthPtr->read)].pduId;
            canPduInfo.length = TxBufPtr[(*hthPtr->read)].txLen;
            canPduInfo.sdu = &TxBufPtr[(*hthPtr->read)].txData[CANIF_VALUE_ZERO];
            canPduInfo.id = TxBufPtr[(*hthPtr->read)].canId;

#ifdef CANIF_AUTOSAR_VERSION_431_SUPPORT

#if (CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON)
            stdRet = CanIf_CanMultipeDrvInfo[ctrlId].CanIf_Can_WriteFunc(hth, &canPduInfo);
#else   /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */
            /* Polyspace +1 DEFECT:PADDING_INFO_LEAK [Justified:Unset] "NSCA_Polyspace_CanIf_PADDING_INFO_LEAK" */
            stdRet = Can_Write(hth, &canPduInfo);
#endif  /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */

            if( E_OK == stdRet )
            {
                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
                TxBufPtr[(*hthPtr->read)].pduId = CANIF_TXBUF_NOPDU;
                (*hthPtr->read)++;
            }

#else   /* CANIF_AUTOSAR_VERSION_431_SUPPORT */

#if (CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON)
            canRet = CanIf_CanMultipeDrvInfo[ctrlId].CanIf_Can_WriteFunc(hth, &canPduInfo);
#else   /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */
            /* Polyspace +1 DEFECT:PADDING_INFO_LEAK [Justified:Unset] "NSCA_Polyspace_CanIf_PADDING_INFO_LEAK" */
            canRet = Can_Write(hth, &canPduInfo);
#endif  /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */

            if( CAN_OK == canRet )
            {
                /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
                TxBufPtr[(*hthPtr->read)].pduId = CANIF_TXBUF_NOPDU;
                (*hthPtr->read)++;
            }
#endif  /* CANIF_AUTOSAR_VERSION_431_SUPPORT */

        }
    }
    else
    {
        /* No Tx buffer. */
    }

    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
    if( hthPtr->TxBufSize <= (*hthPtr->read) )
    {
        (*hthPtr->read) = CANIF_VALUE_ZERO;
    }
}
#endif  /* CANIF_PUB_TXBUFFERING == STD_OFF */

#if (CANIF_PUB_TXBUFFERING == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_TxQueueFilling
*
* Explanation: Search Idx By Transceiver Id.
*
* param: hth: Hardware object Id.
*        CanTxPduId: ID number of the sent PDU.
*        CanIfTxInfoPtr: Point to CanIf to send Pdu message.
*
* retval: E_OK: Filling success.
*         E_NOT_OK: Filling failed.
********************************************************************************
*/
CANIF_STATIC_OPTIMIZATION FUNC(Std_ReturnType, CANIF_CODE) CanIf_TxQueueFilling
(
    P2CONST(CanIf_TxPduCfgType, AUTOMATIC, CANIF_APPL_CONST) txPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) pduInfoPtr,
    uint16 sduLen,
    Can_IdType canId
)
{
    Std_ReturnType stdRet = E_NOT_OK;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanIf_UNMODIFIED_VAR_NOT_CONST" */
    const CanIf_CanObjectMapType* hthPtr = txPduPtr->hthPtr;
    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanIf_UNMODIFIED_VAR_NOT_CONST" */
    CanIf_TxBufType* TxBufPtr = hthPtr->TxBufPtr;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanIf_UNMODIFIED_VAR_NOT_CONST" */
    CanIf_TxBuf_CANFDType* TxBufCANFDPtr = hthPtr->TxBufCANFDPtr;

    /* Check Buffer exist or not. */
    if( NULL_PTR != hthPtr->TxBufCANFDPtr )
    {
        /* Check Buffer full or not. */
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
        if( ((*hthPtr->write) == (*hthPtr->read)) && (CANIF_TXBUF_NOPDU != TxBufCANFDPtr[CANIF_VALUE_ZERO].pduId) )
        {
            stdRet = E_NOT_OK;
        }
        else
        {
            /* Write Tx Buffer. */
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
            TxBufCANFDPtr[(*hthPtr->write)].txLen = (uint8)sduLen;
            TxBufCANFDPtr[(*hthPtr->write)].canId = canId;
            CanIf_Memcpy32(TxBufCANFDPtr[(*hthPtr->write)].txData, pduInfoPtr->SduDataPtr, sduLen);
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
            TxBufCANFDPtr[(*hthPtr->write)].pduId = txPduPtr->txPduId;
            (*hthPtr->write)++;
            stdRet = E_OK;
        }
    }
    else if( NULL_PTR != hthPtr->TxBufPtr )
    {
        /* Check Buffer full or not. */
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
        if( ((*hthPtr->write) == (*hthPtr->read)) && (CANIF_TXBUF_NOPDU != TxBufPtr[CANIF_VALUE_ZERO].pduId) )
        {
            stdRet = E_NOT_OK;
        }
        else
        {
            /* Write Tx Buffer. */
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
            TxBufPtr[(*hthPtr->write)].txLen = (uint8)sduLen;
            TxBufPtr[(*hthPtr->write)].canId = canId;
            CanIf_Memcpy32(TxBufPtr[(*hthPtr->write)].txData, pduInfoPtr->SduDataPtr, sduLen);
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
            TxBufPtr[(*hthPtr->write)].pduId = txPduPtr->txPduId;
            (*hthPtr->write)++;
            stdRet = E_OK;
        }
    }
    else
    {
        /* No Tx buffer. */
    }

    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
    if( hthPtr->TxBufSize <= (*hthPtr->write) )
    {
        (*hthPtr->write) = CANIF_VALUE_ZERO;
    }

    return stdRet;
}
#endif  /* CANIF_PUB_TXBUFFERING == STD_OFF */

#ifdef CANIF_METADATA_SUPPORT_TX
/*
********************************************************************************
* Function Name: CanIf_CalcIdByMetaData
*
* Explanation: Calculate the CANID based on MetaData.
*
* param: canId: The configured CANID of Tx Pdu.
*        canIdMask: The configured CANID mask of Tx Pdu.
*
* retval: The result of calculation.
********************************************************************************
*/
CANIF_STATIC_OPTIMIZATION FUNC(Can_IdType, CANIF_CODE) CanIf_CalcIdByMetaData
(
    Can_IdType canId,
    Can_IdType canIdMask,
    P2VAR(uint8, AUTOMATIC, CANIF_APPL_DATA) metaDataPtr,
    uint8 metaDataLen
)
{
    uint8 index = CANIF_VALUE_ZERO;
    Can_IdType metaDataId = CANIF_VALUE_ZERO;
    Can_IdType canIdRes = CANIF_VALUE_ZERO;

    /* Calculate the MetaData Id. The sequence of the CanId bytes in the MetaData is little endian. */
    for( index = CANIF_VALUE_ZERO; index < metaDataLen; index++ )
    {
        metaDataId |= ((Can_IdType)metaDataPtr[index])<<(index * CANIF_VALUE_EIGHT);
    }
    /* Calculate CANID with Mask. */
    canIdRes = (canId & canIdMask);
    /* Calculate CANID with MetaData. */
    canIdRes |= (metaDataId & (~canIdMask));

    return canIdRes;
}
#endif  /* #ifdef CANIF_METADATA_SUPPORT_TX */

#ifdef CANIF_AUTOSAR_VERSION_431_SUPPORT
/*
********************************************************************************
* Function Name: CanIf_Transmit_Process
*
* Explanation: This service initiates a request for transmission of the
*              CAN L-PDU specified by the CanTxSduId and CAN related data
*              in the L-SDU structure.
*              (Synchronous)
*
* param: CanIfTxSduId: L-SDU handle to be transmitted.This handle specifies the
*                      corresponding CAN LSDU ID and implicitly the CAN Driver
*                      instance as well as the corresponding CAN controller device.
*        CanIfTxInfoPtr: Pointer to a structure with CAN L-SDU related data:DLC and
*                        pointer to CAN L-SDU buffer including the MetaData of dynamic
*                        L-PDUs.
*
* retval: E_OK: Transmit request has been accepted.
*         E_NOT_OK: Transmit request has not been accepted.
********************************************************************************
*/
CANIF_STATIC_OPTIMIZATION FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit_Process
(
    P2CONST(CanIf_TxPduCfgType, AUTOMATIC, CANIF_APPL_CONST) txPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) pduInfoPtr
)
{

#if (CANIF_NEUSAR_CANDRIVER == STD_ON)
    uint8 index;
#endif  /* CANIF_NEUSAR_CANDRIVER == STD_ON */

    Std_ReturnType stdRet = E_NOT_OK;

#if (CANIF_NEUSAR_CANDRIVER == STD_ON)
    const Can_MsgCycles_st *canMsgCycles = &CanIf_TxPduInfo[txPduPtr->txPduId];
#endif  /* CANIF_NEUSAR_CANDRIVER == STD_ON */

    Can_PduType canPduInfo;

    canPduInfo.length = (uint8)(pduInfoPtr->SduLength);
    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
    canPduInfo.id = txPduPtr->canId[CANIF_VALUE_ZERO];
    canPduInfo.swPduHandle = txPduPtr->txPduId;

/*FXS:Add CheckSumData*/
    uint8 LocalSduDataPtr[8] = {0};
    const uint8* srcBuf = pduInfoPtr->SduDataPtr;
    uint16 dataLen = pduInfoPtr->SduLength;
    boolean copyValid = TRUE;

    if((srcBuf == NULL_PTR) || (dataLen > 8))
    {
        copyValid = FALSE;
    }
    else
    {
        for(uint16 copyIdx = 0U; copyIdx < dataLen; copyIdx++)
        {
            LocalSduDataPtr[copyIdx] = srcBuf[copyIdx];
        }
    }
    if(copyValid==TRUE)
    {
    /*FXS:Add 169RollingCounter*/
//    	if((txPduPtr->canId[CANIF_VALUE_ZERO]&0xFFF)==0x169)
//    	{
//    		if(PMS_StsSwap_0x169RollingCounter<16)
//    		{
//    			LocalSduDataPtr[6]=LocalSduDataPtr[6]+PMS_StsSwap_0x169RollingCounter;
//    			PMS_StsSwap_0x169RollingCounter++;
//    		}
//    		else
//    		{
//    			PMS_StsSwap_0x169RollingCounter=1;
//    		}
//    	}
    /*FXS:Add 169RollingCounter*/
    CanIf_CheckSumDataAdd_Callout(txPduPtr->canId[CANIF_VALUE_ZERO],pduInfoPtr->SduLength,LocalSduDataPtr,txPduPtr->ctrlId);
    canPduInfo.sdu = LocalSduDataPtr;
    }
    else
    {
    canPduInfo.sdu = LocalSduDataPtr;
//    		pduInfoPtr->SduDataPtr;
    }
/*FXS:Add CheckSumData*/

#if (CANIF_PUB_TXBUFFERING == STD_ON)
    CanIf_EnterCritical_0();
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

#if (CANIF_NEUSAR_CANDRIVER == STD_ON)
    /* Buffering. */
    for( index = CANIF_VALUE_ZERO; index < canPduInfo.length; index++ )
    {
        canMsgCycles->dataraw[index] = pduInfoPtr->SduDataPtr[index];   /* Copy data. */
    }
    /* Request Can module to transmit msg. */
    stdRet = Can_Write(canMsgCycles->hwchanlNo, &canPduInfo);
#else   /* CANIF_NEUSAR_CANDRIVER == STD_ON */

#if (CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON)

#if (CANIF_PUB_TXBUFFERING == STD_ON)
    if( E_OK == CanIf_CheckTxBufferEmpty(txPduPtr->hthPtr))
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

    {
        stdRet = CanIf_CanMultipeDrvInfo[txPduPtr->ctrlId].CanIf_Can_WriteFunc(txPduPtr->hth, &canPduInfo);
    }

#if (CANIF_PUB_TXBUFFERING == STD_ON)
    else
    {
        /* Tx Buffer process start. */
        CanIf_TxQueueProcessing(txPduPtr->hthPtr,txPduPtr->hth, txPduPtr->ctrlId);
        /* Tx Buffer process end. */
    }
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

#else   /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */

#if (CANIF_PUB_TXBUFFERING == STD_ON)
    if( E_OK == CanIf_CheckTxBufferEmpty(txPduPtr->hthPtr))
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

    {
        /* Polyspace +1 DEFECT:PADDING_INFO_LEAK [Justified:Unset] "NSCA_Polyspace_CanIf_PADDING_INFO_LEAK" */
        stdRet = Can_Write(txPduPtr->hth, &canPduInfo);
    }

#if (CANIF_PUB_TXBUFFERING == STD_ON)
    else
    {
        /* Tx Buffer process start. */
        CanIf_TxQueueProcessing(txPduPtr->hthPtr,txPduPtr->hth, txPduPtr->ctrlId);
        /* Tx Buffer process end. */
    }
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

#endif  /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */

#endif  /* CANIF_NEUSAR_CANDRIVER == STD_ON */

    if( E_OK != stdRet )
    {

#if (CANIF_PUB_TXBUFFERING == STD_ON)
        /* Tx Buffer Filling start. */
        stdRet = CanIf_TxQueueFilling(txPduPtr, pduInfoPtr, canPduInfo.length, canPduInfo.id);
        /* Tx Buffer Filling end. */
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

    }

#if (CANIF_PUB_TXBUFFERING == STD_ON)
    CanIf_LeaveCritical_0();
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

    return stdRet;
}

#else   /* CANIF_AUTOSAR_VERSION_431_SUPPORT */
/*
********************************************************************************
* Function Name: CanIf_Transmit_Process
*
* Explanation: This service initiates a request for transmission of the
*              CAN L-PDU specified by the CanTxSduId and CAN related data
*              in the L-SDU structure.
*              (Synchronous)
*
* param: CanIfTxSduId: L-SDU handle to be transmitted.This handle specifies the
*                      corresponding CAN LSDU ID and implicitly the CAN Driver
*                      instance as well as the corresponding CAN controller device.
*        CanIfTxInfoPtr: Pointer to a structure with CAN L-SDU related data:DLC and
*                        pointer to CAN L-SDU buffer including the MetaData of dynamic
*                        L-PDUs.
*
* retval: E_OK: Transmit request has been accepted.
*         E_NOT_OK: Transmit request has not been accepted.
********************************************************************************
*/
CANIF_STATIC_OPTIMIZATION FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit_Process
(
    P2CONST(CanIf_TxPduCfgType, AUTOMATIC, CANIF_APPL_CONST) txPduPtr,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) pduInfoPtr
)
{

#if (CANIF_NEUSAR_CANDRIVER == STD_ON)
    uint8 index;
#endif  /* CANIF_NEUSAR_CANDRIVER == STD_ON */

    Std_ReturnType stdRet = E_NOT_OK;
    Can_ReturnType canRet = CAN_NOT_OK;

#if (CANIF_NEUSAR_CANDRIVER == STD_ON)
    const Can_MsgCycles_st *canMsgCycles = &CanIf_TxPduInfo[txPduPtr->txPduId];
#endif  /* CANIF_NEUSAR_CANDRIVER == STD_ON */

    Can_PduType canPduInfo;

    canPduInfo.length = (uint8)(pduInfoPtr->SduLength);
    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
    canPduInfo.id = txPduPtr->canId[CANIF_VALUE_ZERO];
    canPduInfo.swPduHandle = txPduPtr->txPduId;
    canPduInfo.sdu = pduInfoPtr->SduDataPtr;

#if (CANIF_PUB_TXBUFFERING == STD_ON)
    CanIf_EnterCritical_0();
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

#if (CANIF_NEUSAR_CANDRIVER == STD_ON)
    /* Buffering. */
    for( index = CANIF_VALUE_ZERO; index < canPduInfo.length; index++ )
    {
        canMsgCycles->dataraw[index] = pduInfoPtr->SduDataPtr[index];   /* Copy data. */
    }
    /* Request Can module to transmit msg. */
    canRet = Can_Write(canMsgCycles->hwchanlNo, &canPduInfo);
#else   /* CANIF_NEUSAR_CANDRIVER == STD_ON */

#if (CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON)

#if (CANIF_PUB_TXBUFFERING == STD_ON)
    if( E_OK == CanIf_CheckTxBufferEmpty(txPduPtr->hthPtr))
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

    {
        canRet = CanIf_CanMultipeDrvInfo[txPduPtr->ctrlId].CanIf_Can_WriteFunc(txPduPtr->hth, &canPduInfo);
    }

#if (CANIF_PUB_TXBUFFERING == STD_ON)
    else
    {
        /* Tx Buffer process start. */
        CanIf_TxQueueProcessing(txPduPtr->hthPtr,txPduPtr->hth, txPduPtr->ctrlId);
        /* Tx Buffer process end. */
    }
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

#else   /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */

#if (CANIF_PUB_TXBUFFERING == STD_ON)
    if( E_OK == CanIf_CheckTxBufferEmpty(txPduPtr->hthPtr))
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

    {
        canRet = Can_Write(txPduPtr->hth, &canPduInfo);
    }

#if (CANIF_PUB_TXBUFFERING == STD_ON)
    else
    {
        /* Tx Buffer process start. */
        CanIf_TxQueueProcessing(txPduPtr->hthPtr,txPduPtr->hth, txPduPtr->ctrlId);
        /* Tx Buffer process end. */
    }
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

#endif  /* CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON */

#endif  /* CANIF_NEUSAR_CANDRIVER == STD_ON */

    if( CAN_OK == canRet )
    {
        stdRet = E_OK;
    }
    else
    {

#if (CANIF_PUB_TXBUFFERING == STD_ON)
        /* Tx Buffer Filling start. */
        stdRet = CanIf_TxQueueFilling(txPduPtr, pduInfoPtr, canPduInfo.length, canPduInfo.id);
        /* Tx Buffer Filling end. */
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

    }

#if (CANIF_PUB_TXBUFFERING == STD_ON)
    CanIf_LeaveCritical_0();
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

    return stdRet;
}
#endif  /* CANIF_AUTOSAR_VERSION_431_SUPPORT */

/*
********************************************************************************
* Function Name: CanIf_RxIndication_Process
*
* Explanation: This service indicates a successful reception of a received CAN Rx
*              LPDU to the CanIf after passing all filters and validation checks
*
* param: hrhPtr: Pointer to the HRH.
*        PduInfoPtr: Pointer to the received L-PDU.
*        canId:
*
* retval: None.
********************************************************************************
*/
CANIF_STATIC_OPTIMIZATION FUNC(void, CANIF_CODE) CanIf_RxIndication_Process
(
    P2CONST(CanIf_CanObjectMapType, AUTOMATIC, CANIF_APPL_CONST) hrhPtr,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr,
    Can_IdType canId
)
{
    Std_ReturnType stdRet;
    uint16 index;
    const CanIf_RxPduCfgType* rxPduPtr;

#if (CANIF_METADATA_SUPPORT == STD_ON)
    uint16 indexData;
    uint8 indexMetaData;
    PduInfoType pduInfoBuf;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanIf_UNMODIFIED_VAR_NOT_CONST" */
    uint8 dataBuf[CANIF_CANFD_MAXLENGTH + CANIF_METADATA_LENGTH_4BYTE];
#endif  /* CANIF_METADATA_SUPPORT == STD_ON */

    for(index = CANIF_VALUE_ZERO; index < hrhPtr->PduIdNum; index++)
    {
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
        rxPduPtr = &CanIf_RxPduCfg[hrhPtr->PduIdPtr[index]];
        if( TRUE == hrhPtr->basicCan )
        {
            /* BasicCAN, Check CANID. */
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
            stdRet = CanIf_CheckCanId(rxPduPtr->canId, rxPduPtr->canIdMask, canId, rxPduPtr->canIdRang);
        }
        else
        {
            /* FullCAN. */
            stdRet= E_OK;
        }
        if( E_OK == stdRet )
        {

#if (CANIF_PRIVATE_DLC_CHECK == STD_ON)

#ifdef  CANIF_PRIVATE_DLC_CHECK_SPECIAL_CA
            if( E_OK == CanIf_CheckDlc_SpecialCA(canId,rxPduPtr->rxPduDlc,PduInfoPtr->SduLength) )
#else   /* CANIF_PRIVATE_DLC_CHECK_SPECIAL_CA */
            /* Check DLC. */
            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
            if( PduInfoPtr->SduLength >= rxPduPtr->rxPduDlc )
#endif  /* CANIF_PRIVATE_DLC_CHECK_SPECIAL_CA */

            {
                if( NULL_PTR != rxPduPtr->rxIndcCallback )
                {

#if (CANIF_METADATA_SUPPORT == STD_ON)
                    if( CANIF_VALUE_ZERO < rxPduPtr->metaDataLen )
                    {
                        /* Polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
                        canId &= CANIF_VALUE_0x1FFFFFFF;
                        /* Set buffer Ptr. */
                        pduInfoBuf.SduDataPtr = &dataBuf[0];
                        /* Set buffer data. */
                        for(indexData = CANIF_VALUE_ZERO; indexData < PduInfoPtr->SduLength; indexData++)
                        {
                            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
                            pduInfoBuf.SduDataPtr[indexData] = PduInfoPtr->SduDataPtr[indexData];
                        }
                        /* Set buffer CANID. */
                        for( indexMetaData = CANIF_VALUE_ZERO; indexMetaData < rxPduPtr->metaDataLen; indexMetaData++ )
                        {
                            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
                            pduInfoBuf.SduDataPtr[indexData + indexMetaData] = (uint8)( (canId) >> ( CANIF_VALUE_EIGHT * indexMetaData ) );
                        }
                        /* Set pdu Length. */
                        pduInfoBuf.SduLength = PduInfoPtr->SduLength + rxPduPtr->metaDataLen;
                        rxPduPtr->rxIndcCallback( rxPduPtr->upperLayerPduId, ( const PduInfoType* )&pduInfoBuf );
                    }
                    else
                    {
                        rxPduPtr->rxIndcCallback(rxPduPtr->upperLayerPduId, PduInfoPtr);
                    }
#else   /* CANIF_METADATA_SUPPORT == STD_ON */
                    rxPduPtr->rxIndcCallback(rxPduPtr->upperLayerPduId, PduInfoPtr);
#endif  /* CANIF_METADATA_SUPPORT == STD_ON */

                }
            }
#else   /* CANIF_PRIVATE_DLC_CHECK == STD_ON */
            if( NULL_PTR != rxPduPtr->rxIndcCallback )
            {
            
#if (CANIF_METADATA_SUPPORT == STD_ON)
                if( CANIF_VALUE_ZERO < rxPduPtr->metaDataLen )
                {
                    canId &= CANIF_VALUE_0x1FFFFFFF;
                    /* Set buffer Ptr. */
                    pduInfoBuf.SduDataPtr = &dataBuf[0];
                    /* Set buffer data. */
                    for(indexData = CANIF_VALUE_ZERO; indexData < PduInfoPtr->SduLength; indexData++)
                    {
                        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
                        pduInfoBuf.SduDataPtr[indexData] = PduInfoPtr->SduDataPtr[indexData];
                    }
                    /* Set buffer CANID. */
                    for (indexMetaData = CANIF_VALUE_ZERO; indexMetaData < rxPduPtr->metaDataLen; indexMetaData++)
                    {
                        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
                        pduInfoBuf.SduDataPtr[indexData + indexMetaData] = (uint8)( (canId) >> ( CANIF_VALUE_EIGHT * indexMetaData ) );
                    }
                    /* Set pdu Length. */
                    pduInfoBuf.SduLength = PduInfoPtr->SduLength + rxPduPtr->metaDataLen;
                    rxPduPtr->rxIndcCallback( rxPduPtr->upperLayerPduId, ( const PduInfoType* )&pduInfoBuf );
                }
                else
                {
                    rxPduPtr->rxIndcCallback(rxPduPtr->upperLayerPduId, PduInfoPtr);
                }
#else   /* CANIF_METADATA_SUPPORT == STD_ON */
                rxPduPtr->rxIndcCallback(rxPduPtr->upperLayerPduId, PduInfoPtr);
#endif  /* CANIF_METADATA_SUPPORT == STD_ON */

            }
#endif  /* CANIF_PRIVATE_DLC_CHECK == STD_ON */

#ifdef CanIf_User_RxIndicationCallout
        /* Notification to the upper layer. */
        CanIf_User_RxIndicationCallout(rxPduPtr->canId & (~CANIF_EXTENDED_FD_CANID_TYPE), rxPduPtr->rxPduDlc, (const PduInfoType*)PduInfoPtr);
#endif  /* CanIf_User_RxIndicationCallout */
			
			//baoenfei neusar bug
            //break;
        }
    }
}

#if (CANIF_PRIVATE_SWFILTER_TYPE == CANIF_SWFILTER_INDEX)
/*
********************************************************************************
* Function Name: CanIf_RxIndication_Process_CanIdMap
*
* Explanation: This service indicates a successful reception of a received CAN Rx
*              LPDU to the CanIf after passing all filters and validation checks
*
* param: Mailbox: dentifies the HRH and its corresponding CAN Controller.
*        PduInfoPtr: Pointer to the received L-PDU.
*
* retval: None.
********************************************************************************
*/
CANIF_STATIC_OPTIMIZATION FUNC(void, CANIF_CODE) CanIf_RxIndication_Process_CanIdMap
(
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr,
    Can_IdType canId,
    P2CONST(uint16, AUTOMATIC, CANIF_APPL_CONST) canIdMapPtr
)
{
    const CanIf_RxPduCfgType* rxPduPtr;

#if (CANIF_METADATA_SUPPORT == STD_ON)
    uint16 indexData;
    PduInfoType pduInfoBuf;
    uint8 indexMetaData;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanIf_UNMODIFIED_VAR_NOT_CONST" */
    uint8 dataBuf[CANIF_CANFD_MAXLENGTH + CANIF_METADATA_LENGTH_4BYTE];
#endif  /* CANIF_METADATA_SUPPORT == STD_ON */

    if( CANIF_CANIDMAPRX_NOPDU != canIdMapPtr[canId] )
    {
        rxPduPtr = &CanIf_RxPduCfg[canIdMapPtr[canId]];

#if (CANIF_PRIVATE_DLC_CHECK == STD_ON)

#ifdef  CANIF_PRIVATE_DLC_CHECK_SPECIAL_CA
        if( E_OK == CanIf_CheckDlc_SpecialCA(canId,rxPduPtr->rxPduDlc,PduInfoPtr->SduLength) )
#else   /* CANIF_PRIVATE_DLC_CHECK_SPECIAL_CA */
        /* Check DLC. */
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
        if( PduInfoPtr->SduLength >= rxPduPtr->rxPduDlc )
#endif  /* CANIF_PRIVATE_DLC_CHECK_SPECIAL_CA */

        {
            if( NULL_PTR != rxPduPtr->rxIndcCallback )
            {
            
#if (CANIF_METADATA_SUPPORT == STD_ON)
                if( CANIF_VALUE_ZERO < rxPduPtr->metaDataLen )
                {
                    /* Set buffer Ptr. */
                    pduInfoBuf.SduDataPtr = &dataBuf[0];
                    /* Set buffer data. */
                    for(indexData = CANIF_VALUE_ZERO; indexData < PduInfoPtr->SduLength; indexData++)
                    {
                        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
                        pduInfoBuf.SduDataPtr[indexData] = PduInfoPtr->SduDataPtr[indexData];
                    }
                    /* Set buffer CANID. */
                    for( indexMetaData = CANIF_VALUE_ZERO; indexMetaData < rxPduPtr->metaDataLen; indexMetaData++ )
                    {
                        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
                        pduInfoBuf.SduDataPtr[indexData + indexMetaData] = (uint8)( (canId) >> ( CANIF_VALUE_EIGHT * indexMetaData ) );
                    }
                    /* Set pdu Length. */
                    pduInfoBuf.SduLength = PduInfoPtr->SduLength + rxPduPtr->metaDataLen;
                    rxPduPtr->rxIndcCallback( rxPduPtr->upperLayerPduId, ( const PduInfoType* )&pduInfoBuf );
                }
                else
                {
                    rxPduPtr->rxIndcCallback(rxPduPtr->upperLayerPduId, PduInfoPtr);
                }
#else   /* CANIF_METADATA_SUPPORT == STD_ON */
                rxPduPtr->rxIndcCallback(rxPduPtr->upperLayerPduId, PduInfoPtr);
#endif  /* CANIF_METADATA_SUPPORT == STD_ON */

            }
        }
#else   /* CANIF_PRIVATE_DLC_CHECK == STD_ON */
        if( NULL_PTR != rxPduPtr->rxIndcCallback )
        {
        
#if (CANIF_METADATA_SUPPORT == STD_ON)
            if( CANIF_VALUE_ZERO < rxPduPtr->metaDataLen )
            {
                /* Set buffer Ptr. */
                pduInfoBuf.SduDataPtr = &dataBuf[0];
                /* Set buffer data. */
                for(indexData = CANIF_VALUE_ZERO; indexData < PduInfoPtr->SduLength; indexData++)
                {
                    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
                    pduInfoBuf.SduDataPtr[indexData] = PduInfoPtr->SduDataPtr[indexData];
                }
                /* Set buffer CANID. */
                for( indexMetaData = CANIF_VALUE_ZERO; indexMetaData < rxPduPtr->metaDataLen; indexMetaData++ )
                {
                    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
                    pduInfoBuf.SduDataPtr[indexData + indexMetaData] = (uint8)( (canId) >> ( CANIF_VALUE_EIGHT * indexMetaData ) );
                }
                /* Set pdu Length. */
                pduInfoBuf.SduLength = PduInfoPtr->SduLength + rxPduPtr->metaDataLen;
                rxPduPtr->rxIndcCallback( rxPduPtr->upperLayerPduId, ( const PduInfoType* )&pduInfoBuf );
            }
            else
            {
                rxPduPtr->rxIndcCallback(rxPduPtr->upperLayerPduId, PduInfoPtr);
            }
#else   /* CANIF_METADATA_SUPPORT == STD_ON */
            rxPduPtr->rxIndcCallback(rxPduPtr->upperLayerPduId, PduInfoPtr);
#endif  /* CANIF_METADATA_SUPPORT == STD_ON */

        }
#endif  /* CANIF_PRIVATE_DLC_CHECK == STD_ON */

#ifdef CanIf_User_RxIndicationCallout
        /* Notification to the upper layer. */
        CanIf_User_RxIndicationCallout(rxPduPtr->canId & (~CANIF_EXTENDED_FD_CANID_TYPE), rxPduPtr->rxPduDlc, (const PduInfoType*)PduInfoPtr);
#endif  /* CanIf_User_RxIndicationCallout */
    }

}
#endif  /* CANIF_PRIVATE_SWFILTER_TYPE == CANIF_SWFILTER_INDEX */

/*
********************************************************************************
* Function Name: CanIf_CheckCanId
*
* Explanation: This service indicates a successful reception of a received CAN Rx
*              LPDU to the CanIf after passing all filters and validation checks
*
* param: Mailbox: dentifies the HRH and its corresponding CAN Controller.
*        PduInfoPtr: Pointer to the received L-PDU.
*
* retval: None.
********************************************************************************
*/
CANIF_STATIC_OPTIMIZATION FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckCanId
(
    Can_IdType canIdCode,
    Can_IdType canIdMask,
    Can_IdType canId,
    boolean canIdRang
)
{
    Std_ReturnType stdRet = E_NOT_OK;

    if( FALSE == canIdRang )
    {
        /* Check CANID mask. */
        if( (canIdCode & (CANIF_BIT_BASE_CANID_TYPE | canIdMask)) == (canId & (CANIF_BIT_BASE_CANID_TYPE | canIdMask)) )
        {
            stdRet = E_OK;
        }
    }
    else
    {
        /* Check CANID Range. */
        if( (canId >= canIdCode) && (canId <= canIdMask) )
        {
            stdRet = E_OK;
        }
    }

    return stdRet;
}

#if (CANIF_PUB_TXBUFFERING == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_ClearTxBufferByChn
*
* Explanation: This service indicates a successful reception of a received CAN Rx
*              LPDU to the CanIf after passing all filters and validation checks
*
* param: crtlId: CanIf controller Id.
*
* retval: None.
********************************************************************************
*/
static FUNC(void, CANIF_CODE) CanIf_ClearTxBufferByChn
(
    uint8 ctrlId
)
{
    uint16 hthIndex;
    uint16 txBufIndex;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanIf_UNMODIFIED_VAR_NOT_CONST" */
    const CanIf_CanObjectMapType* hthPtr = CanIf_Can_ObjectMap;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanIf_UNMODIFIED_VAR_NOT_CONST" */
    const CanIf_TxPduCfgType* txPduPtr = CanIf_TxPduCfg;

    for( hthIndex = CANIF_VALUE_ZERO; hthIndex < CANIF_INITHOHCFG_NUM_CAN; hthIndex++ )
    {
        /* Check out Tx Buffer. */
        if( (CANIF_TRANSMIT == hthPtr[hthIndex].ObjectType) &&
            (NULL_PTR != hthPtr[hthIndex].read) &&
            (NULL_PTR != hthPtr[hthIndex].write) )
        {
            /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            if( CANIF_TXBUF_NOPDU != hthPtr[hthIndex].PduIdPtr[CANIF_VALUE_ZERO] )
            {
                if( txPduPtr[hthPtr[hthIndex].PduIdPtr[CANIF_VALUE_ZERO]].ctrlId == ctrlId )
                {
                    /* Clear the FIFO Tx buffer. */
                    if( NULL_PTR != hthPtr[hthIndex].TxBufPtr )
                    {
                        for(txBufIndex = CANIF_VALUE_ZERO; txBufIndex < hthPtr[hthIndex].TxBufSize; txBufIndex++ )
                        {
                            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
                            hthPtr[hthIndex].TxBufPtr[txBufIndex].pduId = CANIF_TXBUF_NOPDU;
                        }
                    }
                    else if( NULL_PTR != hthPtr[hthIndex].TxBufCANFDPtr )
                    {
                        for(txBufIndex = CANIF_VALUE_ZERO; txBufIndex < hthPtr[hthIndex].TxBufSize; txBufIndex++ )
                        {
                            /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
                            hthPtr[hthIndex].TxBufCANFDPtr[txBufIndex].pduId = CANIF_TXBUF_NOPDU;
                        }
                    }
                    else
                    {
                        /* Do nothing. */
                    }
                    *(hthPtr[hthIndex].read) = CANIF_VALUE_ZERO;
                    *(hthPtr[hthIndex].write) = CANIF_VALUE_ZERO;
                }
            }
        }
    }
}
#endif  /* CANIF_PUB_TXBUFFERING == STD_ON */

#if (CANIF_PUB_TXBUFFERING == STD_ON)
/*
********************************************************************************
* Function Name: CanIf_CheckTxBufferEmpty
*
* Explanation: This service indicates a successful reception of a received CAN Rx
*              LPDU to the CanIf after passing all filters and validation checks
*
* param: hthPtr: HTH pointer.
*
* retval: None.
********************************************************************************
*/
CANIF_STATIC_OPTIMIZATION FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckTxBufferEmpty
(
    P2CONST(CanIf_CanObjectMapType, AUTOMATIC, CANIF_APPL_CONST) hthPtr
)
{
    Std_ReturnType stdRet = E_OK;

    /* Check Buffer exist or not. */
    /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
    if( NULL_PTR != hthPtr->TxBufCANFDPtr )
    {
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
        if( ((*hthPtr->read) != (*hthPtr->write))
                  || (CANIF_TXBUF_NOPDU != hthPtr->TxBufCANFDPtr[CANIF_VALUE_ZERO].pduId) )
        {
            stdRet = E_NOT_OK;
        }
    }
    else if( NULL_PTR != hthPtr->TxBufPtr )
    {
        /* Polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanIf_PointerBounds" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_CanIf_IDP" */
        if( ((*hthPtr->read) != (*hthPtr->write))
          || (CANIF_TXBUF_NOPDU != hthPtr->TxBufPtr[CANIF_VALUE_ZERO].pduId) )
        {
            stdRet = E_NOT_OK;
        }
    }
    else
    {
        /* Do nothing. */
    }

    return stdRet;
}
#endif  /* CANIF_PUB_TXBUFFERING == STD_OFF */


#ifdef  CANIF_PRIVATE_DLC_CHECK_SPECIAL_CA
/*
********************************************************************************
* Function Name: CanIf_CheckDlc_SpecialCA
*
* Explanation: This service indicates a successful reception of a received CAN Rx
*              LPDU to the CanIf after passing all filters and validation checks
*
* param: canId: dentifies the HRH and its corresponding CAN Controller.
*        dlc: Pointer to the received L-PDU.
*        sduLen:  
*
* retval: None.
********************************************************************************
*/
CANIF_STATIC_OPTIMIZATION FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckDlc_SpecialCA
(
    Can_IdType canId,
    PduLengthType dlc,
    PduLengthType sduLen
)
{
    Std_ReturnType stdRet = E_OK;

    //if( CANIF_VALUE_0x600 > (CANIF_VALUE_0x7FF & canId) )//liubolin Remove the restriction that CanID must be less than 0x600
    {
        /* Check Dlc. */
        if( sduLen != dlc )
        {
            stdRet = E_NOT_OK;
        }
    }
    
    return stdRet;
}
#endif  /* CANIF_PRIVATE_DLC_CHECK_SPECIAL_CA */

#ifdef  CANIF_AUTOSAR_VERSION_403_SUPPORT
/*
********************************************************************************
* Function Name: CanIf_SearchIdxByControllerId
*
* Explanation: Search Idx By Controller Id.
*
* param: ControllerId: Controller Id.
*        IndexPtr: Index buf.
*
* retval: E_OK,E_NOT_OK.
********************************************************************************
*/
CANIF_STATIC_OPTIMIZATION FUNC(Std_ReturnType, CANIF_CODE) CanIf_SearchIdxByHoh
(
    Can_HwHandleType hrh,
    P2VAR(uint8, AUTOMATIC, CANIF_APPL_DATA) IndexPtr
)
{
    *IndexPtr = CanIf_RxPduCfg[CanIf_Can_ObjectMap[hrh].PduIdPtr[CANIF_VALUE_ZERO]].ctrlId;

    return E_OK;
}
#endif  /* CANIF_AUTOSAR_VERSION_403_SUPPORT */

#define CANIF_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

