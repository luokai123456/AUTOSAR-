/*
********************************************************************************
*
* File name: CanIf.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangCong/2018.07.21
* Change: New
* Cause: New
********************************************************************************
* Version: 2.0
* Author/Date: WangCong/2018.05.29
* Change: Modify format.
* Cause: Updata to V2.0.
********************************************************************************
* Version: 2.1
* Author/Date: WangCong/2019.10.12
* Change: Code format.
* Cause: Optimization
********************************************************************************
* Version: 3.0
* Author/Date: WangCong/2019.12.24
* Change: Cancel #include "Can.h".
* Cause: Adding Functionality(Multiple CAN Driver support).
********************************************************************************
* Version: 3.1
* Author/Date: WangCong/2020.01.10
* Change: add Macro: CANIF_CANTP_SPECIAL_HANDLE.
* Cause: Adapt to CanTp of the old version.
********************************************************************************
* Version: 3.2
* Author/Date: WangCong/2020.03.25
* Change: Modify header file reference.
* Cause: Clear QAC warning.
********************************************************************************
* Version: 3.3
* Author/Date: WangCong/2020.03.30
* Change: 1.Add comment.
*         2.Modify the precompile.
* Cause: Code Walkthrough.
********************************************************************************
* Version: 3.4
* Author/Date: WangCong/2020.05.07
* Change: add Macro: CanIf_EnterCritical_0
*                    CanIf_LeaveCritical_0.
* Cause: Bugfix
********************************************************************************
* Version: 3.5
* Author/Date: WangCong/2020.05.12
* Change: Modify the code specification.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: lizhiheng/2020.06.08
* Change: Add release software number.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: WangC/2020.10.24
* Change: Modify the function name according to the AUTOSAR specification, add
*         MemMap.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: WangC/2020.12.30
* Change: Optimization code execution speed.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: WangC/2021.2.26
* Change: Added precompilation.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: LiZH/2021.10.20
* Change: Modified version number.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: LiuHJ/2021.10.28
* Change: Modify header file reference.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: LiZH/2021.10.28
* Change: Modifty to LOCAL_INLINE.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: LiZH/2021.11.1
* Change: Updata versions.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date: LiZH/2022.6.17
* Change: Modify compile warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: LiDY/2023.2.2
* Change: Update the patch version.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: LiDY/2023.2.21
* Change: Update the patch version.
* Cause: Update
********************************************************************************
* Version: 3.15
* Author/Date: LiDY/2023.5.17
* Change: Update the version to 3.7.0.
* Cause: Update
********************************************************************************
* Version: 3.16
* Author/Date: LiDY/2023.5.26
* Change: Add REVISION version.
* Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date: TianG/2023.8.10
* Change: Update the version to 3.8.0.
* Cause: Update
********************************************************************************
* Version: 3.18
* Author/Date: TianG/2023.10.8
* Change: Update the version to 3.9.0.1.
* Cause: Update
********************************************************************************
* Version: 3.19
* Author/Date: YanCL/2023.10.31
* Change: Update the version to 3.9.0.2.
* Cause: Update
********************************************************************************
* Version: 3.20
* Author/Date: YanCL/2023.12.4
* Change: Adds CanIf_Memcpy32 function declaration.
* Cause: Optimization
********************************************************************************
* Version: 3.21
* Author/Date: YanCL/2023.12.4
* Change: Delete the CanIf_Memcpy32 function declaration.
* Cause: Optimization
********************************************************************************
* Version: 3.22
* Author/Date: YanCL/2023.12.25
* Change: Update the version to 3.9.0.4.
* Cause: Update
********************************************************************************
* Version: 3.23
* Author/Date: YanCL/2024.3.12
* Change: Update the version to 3.10.0.5.
* Cause: Update
********************************************************************************
* Version: 3.24
* Author/Date: YanCL/2024.4.2
* Change: 1.Update the version to 3.10.0.6.
*         2.Modify the P2CONST incorrect labels.
*         3.Modify the annotation.
* Cause: Optimization
********************************************************************************
* Version: 3.25
* Author/Date: YanCL/2024.5.8
* Change: Update the version to 3.11.0.7.
* Cause: Optimization
********************************************************************************
* Version: 3.26
* Author/Date: YanCL/2024.7.9
* Change: 1.Update the version to 3.11.0.8.
*         2.Add Memmap segment definition.
*         3.Update copyright information.
* Cause: Update
********************************************************************************
* Version: 3.27
* Author/Date: YanCL/2025.03.13
* Change: Update the version to 3.13.0.9.
* Cause: Update
********************************************************************************
* Version: 3.28
* Author/Date: YanCL/2025.03.24
* Change: 1.Update the version to 3.13.0.10.
*         2.Add the NeuLib.h file and use the NeuLib_comcpy32 function.
* Cause: Update
********************************************************************************
* Version: 3.29
* Author/Date: YanCL/2025.04.24
* Change: 1.Update the version to 3.14.0.11.
*         2.CanIf add 'CANIF_CANID_GET_FD_TYPE' and 'CANIF_CHECK_FOR_INVALID_CAN_ID' macro.
* Cause: Update
********************************************************************************
* Version: 3.30
* Author/Date: YanCL/2025.06.06
* Change: 1.Add the polyspace deviation suppression comment.
*         2.Update the version to 3.14.0.12.
* Cause: Update
********************************************************************************
* Version: 3.31
* Author/Date: YanCL/2025.06.20
* Change: Update the version to 3.14.0.13.
* Cause: Update
********************************************************************************
*/
#ifndef CANIF_H_
#define CANIF_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "CanIf_Lcfg.h"
/* SWS_CANIF_00208 */
#include "SchM_CanIf.h"

#if( CANIF_CANTRCV_SUPPORT == STD_ON )
#include "CanTrcv.h"
#endif  /* CANIF_CANTRCV_SUPPORT == STD_ON */

#if( CANIF_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif  /* CANIF_DEV_ERROR_DETECT == STD_ON */

/* For the type: EcuM_WakeupSourceType */
#if( CANIF_WAKEUP_SUPPORT == STD_ON )
#include "EcuM.h"
#endif  /* CANIF_WAKEUP_SUPPORT == STD_ON */

#include "CanIf_Can.h"

#include "NeuLib.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CANIF_VENDOR_ID                         (119U)
#define CANIF_MODULE_ID                         (60U)
#define CANIF_SW_MAJOR_VERSION                  (3U)
#define CANIF_SW_MINOR_VERSION                  (14U)
#define CANIF_SW_PATCH_VERSION                  (0U)
#define CANIF_SW_REVISION_VERSION               (13U)

/* AUTOSAR Version. */
#define CANIF_AR_RELEASE_MAJOR_VERSION          (4U)
#define CANIF_AR_RELEASE_MINOR_VERSION          (2U)
#define CANIF_AR_RELEASE_REVISION_VERSION       (2U)

#define CANIF_CANTP_SPECIAL_HANDLE

#define CanIf_EnterCritical_0     SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_0     /* Critical:0 */
#define CanIf_LeaveCritical_0     SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_0      /* Critical:0 */

#define CANIF_OPTIMIZATION_SPEED

#ifdef CANIF_OPTIMIZATION_SPEED
#define CANIF_STATIC_OPTIMIZATION       LOCAL_INLINE
#else   /* CANIF_OPTIMIZATION_SPEED */
#define CANIF_STATIC_OPTIMIZATION       static
#endif  /* CANIF_OPTIMIZATION_SPEED */

#define CanIf_Memcpy32 NeuLib_memcpy32

/* CanFD Types */
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define CANIF_CANID_GET_FD_TYPE(canId) ( (uint32)(canId) & (uint32)CANIF_FD_CANID_TYPE )

/* CanId is valid */
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define CANIF_CHECK_FOR_INVALID_CAN_ID(CanId) ( ( ((uint32)(CanId) & 0x20000000UL) != 0U ) || \
                                              ( ( ((uint32)(CanId) & 0x80000000UL) == 0U ) && \
                                              ( ((uint32)(CanId) & 0x3FFFF800UL) != 0U ) ) )
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

#define CANIF_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanIf_MemMap.h"

extern FUNC(void, CANIF_CODE) CanIf_Init
(
    P2CONST(CanIf_ConfigType, AUTOMATIC, CANIF_APPL_CONST) ConfigPtr
);
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllerMode
(
    uint8 ControllerId,
    CanIf_ControllerModeType ControllerMode
);
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerMode
(
    uint8 ControllerId,
    P2VAR(CanIf_ControllerModeType, AUTOMATIC, CANIF_APPL_DATA) ControllerModePtr
);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanIf_Dir4.5" */
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit
(
    PduIdType CanIfTxSduId,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) CanIfTxInfoPtr
);

#if (CANIF_PUB_CANCEL_TRANSMIT_SUP == STD_ON)
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CancelTransmit
(
    PduIdType CanIfTxSduId
);
#endif  /* CANIF_PUB_CANCEL_TRANSMIT_SUP == STD_ON */

#if (CANIF_PUB_READRXPDU_DATA_API == STD_ON)
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReadRxPduData
(
    PduIdType CanIfRxSduId,
    P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) CanIfRxInfoPtr
);
#endif  /* CANIF_PUB_READRXPDU_DATA_API == STD_ON */

#if (CANIF_PUB_READTXPDU_NTF_STA_API == STD_ON)
extern FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadTxNotifStatus
(
    PduIdType CanIfTxSduId
);
#endif  /* CANIF_PUB_READTXPDU_NTF_STA_API == STD_ON */

#if (CANIF_PUB_READRXPDU_NTF_STA_API == STD_ON)
extern FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadRxNotifStatus
(
    PduIdType CanIfRxSduId
);
#endif  /* CANIF_PUB_READRXPDU_NTF_STA_API == STD_ON */

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPduMode
(
    uint8 ControllerId,
    CanIf_PduModeType PduModeRequest
);
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetPduMode
(
    uint8 ControllerId,
    P2VAR(CanIf_PduModeType, AUTOMATIC, CANIF_APPL_DATA) PduModePtr
);
extern FUNC(void, CANIF_CODE) CanIf_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CANIF_APPL_DATA) VersionInfo
);

#if (CANIF_PUB_SETDYNAMIC_TXID_API == STD_ON)
extern FUNC(void, CANIF_CODE) CanIf_SetDynamicTxId
(
    PduIdType CanIfTxSduId,
    Can_IdType CanId
);
#endif  /* CANIF_PUB_SETDYNAMIC_TXID_API == STD_ON */

#if (CANIF_CANTRCV_SUPPORT == STD_ON)
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvMode
(
    uint8 TransceiverId,
    CanTrcv_TrcvModeType TransceiverMode
);
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvMode
(
    P2VAR(CanTrcv_TrcvModeType, AUTOMATIC, CANIF_APPL_DATA) TransceiverModePtr,
    uint8 TransceiverId
);
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvWakeupReason
(
    uint8 TransceiverId,
    P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANIF_APPL_DATA) TrcvWuReasonPtr
);
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvWakeupMode
(
    uint8 TransceiverId,
    CanTrcv_TrcvWakeupModeType TrcvWakeupMode
);
#endif  /* CANIF_CANTRCV_SUPPORT == STD_ON */

#if (CANIF_WAKEUP_SUPPORT == STD_ON)
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckWakeup
(
    EcuM_WakeupSourceType WakeupSource
);
#endif  /* CANIF_WAKEUP_SUPPORT == STD_ON */

#if (CANIF_PUB_WUCHKVAL_SUP == STD_ON)
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckValidation
(
    EcuM_WakeupSourceType WakeupSource
);
#endif  /* CANIF_PUB_WUCHKVAL_SUP == STD_ON */

#if (CANIF_PUB_TXCONFIRM_POLLING == STD_ON)
extern FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_GetTxConfirmationState
(
    uint8 ControllerId
);
#endif  /* CANIF_PUB_TXCONFIRM_POLLING == STD_ON */

#if (CANIF_CANTRCV_SUPPORT == STD_ON)

#if (CANIF_PUB_PN_SUPPORT == STD_ON)
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ClearTrcvWufFlag
(
    uint8 TransceiverId
);
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckTrcvWakeFlag
(
    uint8 TransceiverId
);
#endif  /* CANIF_PUB_PN_SUPPORT == STD_ON */

#endif  /* CANIF_CANTRCV_SUPPORT == STD_ON */

#if (CANIF_PUB_SETBAUDRATE_API == STD_ON)
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetBaudrate
(
    uint8 ControllerId,
    uint16 BaudRateConfigID
);
#endif  /* CANIF_PUB_SETBAUDRATE_API == STD_ON */

#if (CANIF_PUB_ICOM_SUPPORT == STD_ON)
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetIcomConfiguration
(
    uint8 ControllerId,
    IcomConfigIdType ConfigurationId
);
#endif  /* CANIF_PUB_ICOM_SUPPORT == STD_ON */

#define CANIF_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanIf_MemMap.h"

#endif /* CANIF_H_ */

