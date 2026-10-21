/*
********************************************************************************
*
* File name: CanIf_Cbk.h
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
* Author/Date: WangCong/2019.05.29
* Change: modify format
* Cause: updata to V2.0.
********************************************************************************
* Version: 2.1
* Author/Date: WangCong/2019.10.12
* Change: code format.
* Cause: Optimization
********************************************************************************
* Version: 3.0
* Author/Date: WangCong/2019.12.24
* Change: None
* Cause: Updata to V3.0.
********************************************************************************
* Version: 3.1
* Author/Date: WangCong/2020.05.12
* Change: Modify the code specification.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: WangC/2020.10.24
* Change: Modify the function name according to the AUTOSAR specification, add
*         MemMap.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: WangC/2021.01.15
* Change: Modify CanIf_RxIndication to be compatible with AUTOSAR version 4.0.3.
* Cause: Compatibility
********************************************************************************
* Version: 3.4
* Author/Date: WangC/2021.2.26
* Change: Added precompilation.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: YanCL/2024.4.2
* Change: 1.Modify the P2CONST incorrect labels.
*         2.Modify the annotation.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: YanCL/2024.7.9
* Change: 1.Add Memmap segment definition.
*         2.Update copyright information.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: YanCL/2025.06.06
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef CANIF_CBK_H_
#define CANIF_CBK_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "CanIf_Lcfg.h"
#include "CanIf.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/*
********************************************************************************
*    Global variables
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

#if (CANIF_TRI_TRANSMIT_SUP == STD_ON)
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_TriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
);
#endif  /* CANIF_TRI_TRANSMIT_SUP == STD_ON */

extern FUNC(void, CANIF_CODE) CanIf_TxConfirmation
(
    PduIdType CanTxPduId
);

#ifdef  CANIF_AUTOSAR_VERSION_403_SUPPORT
extern FUNC(void, CANIF_CODE) CanIf_RxIndication
(
    Can_HwHandleType Hrh, 
    Can_IdType CanId, 
    uint8 CanDlc, 
    P2CONST(uint8, AUTOMATIC, CANIF_APPL_DATA) CanSduPtr
);
#else   /* CANIF_AUTOSAR_VERSION_403_SUPPORT */
extern FUNC(void, CANIF_CODE) CanIf_RxIndication
(
    P2CONST(Can_HwType, AUTOMATIC, CANIF_APPL_DATA) Mailbox,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
);
#endif  /* CANIF_AUTOSAR_VERSION_403_SUPPORT */

extern FUNC(void, CANIF_CODE) CanIf_ControllerBusOff
(
    uint8 ControllerId
);

#if (CANIF_CANTRCV_SUPPORT == STD_ON)
extern FUNC(void, CANIF_CODE) CanIf_ConfirmPnAvailability
(
    uint8 TransceiverId
);

#if (CANIF_PUB_ICOM_SUPPORT == STD_ON)
extern FUNC(void, CANIF_CODE) CanIf_ClearTrcvWufFlagIndication
(
    uint8 TransceiverId
);
#endif    /* CANIF_PUB_ICOM_SUPPORT == STD_ON */

#if (CANIF_PUB_ICOM_SUPPORT == STD_ON)
extern FUNC(void, CANIF_CODE) CanIf_CheckTrcvWakeFlagIndication
(
    uint8 TransceiverId
);
#endif    /* CANIF_PUB_ICOM_SUPPORT == STD_ON */

#endif  /* CANIF_CANTRCV_SUPPORT == STD_ON */

extern FUNC(void, CANIF_CODE) CanIf_ControllerModeIndication
(
    uint8 ControllerId,
    CanIf_ControllerModeType ControllerMode
);

#if (CANIF_CANTRCV_SUPPORT == STD_ON)
extern FUNC(void, CANIF_CODE) CanIf_TrcvModeIndication
(
    uint8 TransceiverId,
    CanTrcv_TrcvModeType TransceiverMode
);
#endif  /* CANIF_CANTRCV_SUPPORT == STD_ON */

#if (CANIF_PUB_ICOM_SUPPORT == STD_ON)
extern FUNC(void, CANIF_CODE) CanIf_CurrentIcomConfiguration
(
    uint8 ControllerId,
    IcomConfigIdType ConfigurationId,
    IcomSwitch_ErrorType Error
);
#endif  /* CANIF_PUB_ICOM_SUPPORT == STD_ON */

extern FUNC(void, CANIF_CODE) CanIf_CancelTxConfirmation
(
    PduIdType CanTxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
);

#ifdef CANIF_PRIVATE_ACKERR_CHECK_SPECIAL_CA
extern FUNC(void, CANIF_CODE) CanIf_TxAckErrConfirmation
(
    PduIdType CanTxPduId
);
#endif  /* CANIF_PRIVATE_ACKERR_CHECK_SPECIAL_CA */

#define CANIF_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanIf_MemMap.h"

#endif /* CANIF_CBK_H_ */

