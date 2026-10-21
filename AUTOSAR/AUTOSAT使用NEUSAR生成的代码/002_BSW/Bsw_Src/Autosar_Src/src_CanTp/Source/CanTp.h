/*
********************************************************************************
*
* File name: CanTp.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: TanLX/2018.12.10
* Change: New
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: TanLX/2019.05.01
* Change: Modify the prefix of the function and global variable.
* Cause: Modify
********************************************************************************
* Version: 1.2
* Author/Date: TanLX/2019.10.12
* Change: Modify MIRSA-C code.
* Cause: Modify
********************************************************************************
* Version: 1.3
* Author/Date: SongQW/2019.11.11
* Change: Change the value of CANTP_E_NO_ERROR from 0xFF to 0x0.
* Cause: Modify
********************************************************************************
* Version: 1.4
* Author/Date: LiuZY/2019.11.19
* Change: The format of code and comment.
* Cause: Modify the code according to the coding specification.
********************************************************************************
* Version: 3.0
* Author/Date: SongQW/2020.03.27
* Change: Update the CanTp software version.
* Cause: Update to V3.0.
********************************************************************************
* Version: 3.1
* Author/Date: SongQW/2020.05.15
* Change: Modify the coding specification.
* Cause: Optimize
********************************************************************************
* Version: 3.2
* Author/Date: LiuZY/2020.8.21
* Change: Modify function service id.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: ZhuCHY/2020.09.16
* Change: Add function of MemMap.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: ZhuCHY/2020.09.18
* Change: Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: LiuZY/2020.11.02
* Change: Modify the interface declaration position according to the document.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: LiuZY/2020.11.03
* Change: Modify static function to extern.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: LiuZY/2020.11.03
* Change: Modify the incorrectly defined part of the code format.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: SongQW/2021.06.29
* Change: Modify the method of the defined macro format.
* Cause: Bugfix
********************************************************************************
* Version: 3.9
* Author/Date: SongQW/2021.07.14
* Change: Add functions "CanTp_Make16Bit" and "CanTp_Make32Bit".
* Cause: Bugfix
********************************************************************************
* Version: 3.10
* Author/Date: SongQW/2021.08.31
* Change: When cantp channels are not configued, the following array number should
*         be "CANTP_CHANNEL_NUM + 1U", which include array "CanTp_CanRxBuffer",
*         "CanTp_CanTxBuffer", "CanTp_RxState", "CanTp_TxState" and
*         "CanTp_TxSemaphore".
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: ZhuCY/2021.10.20
* Change: Modify component version information.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: ZhuCY/2021.10.21
* Change: Modify component version information.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: ZhuCY/2021.12.23
* Change: Modify patch version information.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: ZhuCY/2021.06.21
* Change: Modify patch version information.
* Cause: Update
********************************************************************************
* Version: 3.15
* Author/Date: ZhuCY/2021.06.29
* Change: Modify patch version information.
* Cause: Update
********************************************************************************
* Version: 3.16
* Author/Date: ZhuCY/2021.07.18
* Change: Modify patch version to 3.4.4.
* Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date: ZhuCY/2021.07.18
* Change: Modify the CanTp_TxSemaphore AUTOSAR specification to "CANTP_VAR_NO_INIT".
* Cause: Bugfix
********************************************************************************
* Version: 3.18
* Author/Date: WuHW/2022.12.27
* Change: Modify version to 3.4.5.
* Cause: Update
********************************************************************************
* Version: 3.19
* Author/Date: WuHW/2023.03.01
* Change: Modify version to 3.6.0.
* Cause: Update
********************************************************************************
* Version: 3.20
* Author/Date: WuHW/2023.05.17
* Change: Modify version to 3.7.0.
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date: WuHW/2023.05.26
* Change: Modify version to 3.7.0.0.
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date: TianG/2023.6.28
* Change: Modify version to 3.8.0.1.
* Cause: Update
********************************************************************************
* Version: 3.23
* Author/Date: TianG/2023.7.24
* Change: Modify version to 3.8.0.2.
*         Add CanTp_GetHiHiByte,CanTp_GetHiLoByte,
*         CanTp_GetLoHiByte,CanTp_GetLoLoByte.
* Cause: Update
********************************************************************************
* Version: 3.24
* Author/Date: TianG/2023.9.19
* Change: Modify version to 3.9.0.3.
* Cause: Update
********************************************************************************
* Version: 3.25
* Author/Date: YanCL/2024.3.19
* Change: Modify version to 3.10.0.4.
* Cause: Update
********************************************************************************
* Version: 3.26
* Author/Date: YanCL/2024.4.2
* Change: 1.Modify version to 3.10.0.5.
*         2.Modify the P2CONST incorrect labels.
*         3.Modify the annotation.
* Cause: Optimization
********************************************************************************
* Version: 3.27
* Author/Date: YanCL/2024.7.3
* Change: 1.Modify version to 3.11.0.6.
*         2.Add Memmap segment definition.
*         3.Update copyright information.
* Cause: Update
********************************************************************************
* Version: 3.28
* Author/Date: YanCL/2024.7.16
* Change: Add macro definitions for different versions of ISO 15765-2 protocol.
* Cause: Update
********************************************************************************
* Version: 3.29
* Author/Date: YanCL/2024.8.28
* Change: Modify version to 3.11.0.7.
* Cause: Update
********************************************************************************
* Version: 3.30
* Author/Date: YanCL/2024.9/27
* Change: Modify version to 3.11.0.8.
* Cause: Update
********************************************************************************
* Version: 3.31
* Author/Date: YanCL/2024.10.22
* Change: 1.Modify version to 3.12.0.9.
*         2.Delete Dcm_Cbk.h header file containing.
*         3.Adjust the CANTP_DCM_SUPPORT macro generation position to CanTp_Cfg.h.
* Cause: Update
********************************************************************************
* Version: 3.32
* Author/Date: YanCL/2025.01.06
* Change: Modify version to 3.13.0.10.
* Cause: Update
********************************************************************************
* Version: 3.33
* Author/Date: YanCL/2025.02.08
* Change: Modify version to 3.13.0.11.
* Cause: Update
********************************************************************************
* Version: 3.34
* Author/Date: YanCL/2025.02.27
* Change: Modify version to 3.13.0.12.
* Cause: Update
********************************************************************************
* Version: 3.35
* Author/Date: YanCL/2025.03.10
* Change: Delete macro functions CANTP_STMINREMAINDER and CANTP_STMINVALUE.
* Cause: Update
********************************************************************************
* Version: 3.36
* Author/Date: YanCL/2025.03.26
* Change: Modify version to 3.13.0.13.
* Cause: Update
********************************************************************************
* Version: 3.37
* Author/Date: YanCL/2025.05.15
* Change: Modify version to 3.14.0.14.
* Cause: Update
********************************************************************************
* Version: 3.38
* Author/Date: YanCL/2025.06.03
* Change: Modify version to 3.14.0.15.
* Cause: Update
********************************************************************************
* Version: 3.39
* Author/Date: YanCL/2025.06.06
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.40
* Author/Date: YanCL/2025.06.23
* Change: Modify version to 3.14.0.16.
* Cause: Update
********************************************************************************
*/
#ifndef CANTP_H_
#define CANTP_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "ComStack_Types.h"
#include "CanIf.h"
#include "PduR_CanTp.h"
#include "CanTp_Lcfg.h"
#include "CanTp_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* SN initial and max value. */
#define CANTP_SNFIRSTCF                         (1U)
#define CANTP_MAX_SIN                           (15U)

/* BS of the FC. */
#define CANTP_MAX_BLOCK_COUNTER                 (8U)

/* CanTp post-build configuration data. */
#define CANTP_CONFIG_PTR                        (NULL_PTR)

#define CANTP_LOW_OFFSET                        (0x0FU)

/* Tp Version */
#define CANTP_ISO15765_2_2004                   (1U)
#define CANTP_ISO15765_2_2011                   (2U)
#define CANTP_ISO15765_2_2016                   (3U)

/* Module Identification. */
#define CANTP_VENDOR_ID                         (119U)
#define CANTP_MODULE_ID                         (35U)

/* Component Version Information. */
#define CANTP_SW_MAJOR_VERSION                  (3U)
#define CANTP_SW_MINOR_VERSION                  (14U)
#define CANTP_SW_PATCH_VERSION                  (0U)
#define CANTP_SW_REVISION_VERSION               (16U)

/* AUTOSAR Version. */
#define CANTP_AR_RELEASE_MAJOR_VERSION          (4U)
#define CANTP_AR_RELEASE_MINOR_VERSION          (2U)
#define CANTP_AR_RELEASE_REVISION_VERSION       (2U)

/* CanTp module ID for Det. */
#define CANTP_INSTANCE_ID_DET                   (0x00U)

/* API Service IDs. */
#define CANTP_SID_INIT                          (0x01U)
#define CANTP_SID_SHUTDOWN                      (0x02U)
#define CANTP_SID_TRANSMIT                      (0x03U)
#define CANTP_SID_RXINDICATION                  (0x42U)
#define CANTP_SID_TXCONFIRMATION                (0x40U)
#define CANTP_SID_MAINFUNCTION                  (0x06U)
#define CANTP_SID_GETVERSIONINFO                (0x07U)
#define CANTP_SID_CANCELTRANSMIT                (0x08U)
#define CANTP_SID_CANCELRECEIVE                 (0x09U)
#define CANTP_SID_CHANGEPARAMETER               (0x0AU)
#define CANTP_SID_READPARAMETER                 (0x0BU)
#define CANTP_SID_MAINFUNCTIONRX                (0x20U)
#define CANTP_SID_MAINFUNCTIONTX                (0x21U)
#define CANTP_SID_RXGETBUFFER                   (0x30U)
#define CANTP_SID_TXGETBUFFER                   (0x31U)
#define CANTP_SID_RXTRANSMITFRAME               (0x32U)
#define CANTP_SID_TXTRANSMITFRAME               (0x33U)
#define CANTP_SID_RXINIT                        (0x34U)
#define CANTP_SID_TXINIT                        (0x35U)
#define CANTP_SID_STOPSEPARATIONTIME            (0x36U)

/* Error Codes. */
/* Error code: invalid or inconsistent configuration. */
#define CANTP_E_PARAM_CONFIG                    (0x01U)
/* Error code: API call with invalid identifier. */
#define CANTP_E_PARAM_ID                        (0x02U)
/* Error code: API call with an invalid pointer parameter. */
#define CANTP_E_PARAM_POINTER                   (0x03U)
/* Error code: API call with module initialization has failed. */
#define CANTP_E_INIT_FAILED                     (0x04U)
/* Error code: API call when CanTp is not initialized. */
#define CANTP_E_UNINIT                          (0x20U)
/* Error code: API call with invalid TxSduId / TxConfPduId. */
#define CANTP_E_INVALID_TX_ID                   (0x30U)
/* Error code: API call with invalid RxPduId. */
#define CANTP_E_INVALID_RX_ID                   (0x40U)
/* Error code: size or pointer of Tx buffer invalid. */
#define CANTP_E_INVALID_TX_BUFFER               (0x50U)
/* Error code: size or pointer of Rx buffer invalid. */
#define CANTP_E_INVALID_RX_BUFFER               (0x60U)
/* Error code: transmission request with invalid data length. */
#define CANTP_E_INVALID_TX_LENGTH               (0x70U)
/* Error code: invalid data length in a received SF or FF. */
#define CANTP_E_INVALID_RX_LENGTH               (0x80U)
/* Error code: segmented Rx / Tx for functional Sdu. */
#define CANTP_E_INVALID_TATYPE                  (0x90U)
/* Error code: requested operation is not supported. */
#define CANTP_E_OPER_NOT_SUPPORTED              (0xA0U)
/* Error code: protocol timeout or implementation specific error. */
#define CANTP_E_COM                             (0xB0U)
/* Error code: Rx state machine is in an invalid state. */
#define CANTP_E_INVALID_RX_STATE                (0xB1U)
/* Error code: Tx state machine is in an invalid state. */
#define CANTP_E_INVALID_TX_STATE                (0xB2U)
/* Error code: an invalid frame type occurred. */
#define CANTP_E_INVALID_FRAME_TYPE              (0xB3U)
/* Error code: reception error. */
#define CANTP_E_RX_COM                          (0xC0U)
/* Error code: N_Ar timeout. */
#define CANTP_E_RX_TIMEOUT_AR                   (0xC1U)
/* Error code: N_Br timeout. */
#define CANTP_E_RX_TIMEOUT_BR                   (0xC2U)
/* Error code: N_Cr timeout. */
#define CANTP_E_RX_TIMEOUT_CR                   (0xC3U)
/* Error code: CF with invalid SN received. */
#define CANTP_E_RX_INVALID_SN                   (0xC4U)
/* Error code: max number of wait frames reached. */
#define CANTP_E_RX_WFTMAX                       (0xC5U)
/* Error code: connection terminated due to new SF/FF. */
#define CANTP_E_RX_RESTART                      (0xC6U)
/* Error code: transmission of a flow control frame failed . */
#define CANTP_E_RX_TRANSMIT_ERROR               (0xC7U)
/* Error code: transmission error. */
#define CANTP_E_TX_COM                          (0xD0U)
/* Error code: N_As timeout. */
#define CANTP_E_TX_TIMEOUT_AS                   (0xD1U)
/* Error code: N_Bs timeout. */
#define CANTP_E_TX_TIMEOUT_BS                   (0xD2U)
/* Error code: N_Cs timeout. */
#define CANTP_E_TX_TIMEOUT_CS                   (0xD3U)
/* Error code: FC.OVFL received. */
#define CANTP_E_TX_FC_OVFL                      (0xD4U)
/* Error code: FC with invalid flow status received. */
#define CANTP_E_TX_INVALID_FS                   (0xD5U)
/* Error code: FC with res. STmin received but not allowed. */
#define CANTP_E_TX_RES_STMIN                    (0xD6U)
/* Error code: transmission of any frame failed. */
#define CANTP_E_TX_TRANSMIT_ERROR               (0xD7U)
/* Non AR-error code, used for channel reset. */
#define CANTP_E_NO_ERROR                        (0x0U)

/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define CanTp_GetHiByte(data)                   ((uint8)(((uint16)(data))>>8u))
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define CanTp_GetLoByte(data)                   ((uint8)(data))

/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define CanTp_GetHiHiByte(data)                 ((uint8)(((uint32)(data))>>24U))
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define CanTp_GetHiLoByte(data)                 ((uint8)(((uint32)(data))>>16U))
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define CanTp_GetLoHiByte(data)                 ((uint8)(((uint32)(data))>>8U))
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define CanTp_GetLoLoByte(data)                 ((uint8)(data))



#ifndef CANTP_DUMMY_STATEMENT  /* Dummy */
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" Polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
#define CANTP_DUMMY_STATEMENT(v) (v)=(v)
#endif

/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define CanTp_Make16Bit(hiByte,loByte)                    ((uint16)((((uint32)(hiByte))<<8U)| ((uint32)(loByte))))

/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define CanTp_Make32Bit(hiHiByte,hiLoByte,loHiByte,loLoByte)  ((uint32)((((uint32)(hiHiByte))<<24U)| \
                                                              (((uint32)(hiLoByte))<<16U)| \
                                                              (((uint32)(loHiByte))<<8U) | \
                                                              ((uint32)(loLoByte))))

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.8" Polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct sCanTp_PCConfigType
{
    uint8 ConfigNeverUsed;  /* Config */
} CanTp_PCConfigType;
typedef CanTp_PCConfigType CanTp_ConfigType;

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define CANTP_START_SEC_VAR_NO_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanTp_MemMap.h"

extern VAR(uint8, CANTP_VAR_NO_INIT) CanTp_TxSemaphore[CANTP_CHANNEL_NUM + 1U];

#define CANTP_STOP_SEC_VAR_NO_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanTp_MemMap.h"

extern VAR(uint8, CANTP_VAR_INIT) CanTp_CanRxBuffer[CANTP_CHANNEL_NUM + 1U][CANTP_REVDATALEN];
extern VAR(uint8, CANTP_VAR_INIT) CanTp_CanTxBuffer[CANTP_CHANNEL_NUM + 1U][CANTP_REVDATALEN];
extern VAR(CanTp_RxStateType_st, CANTP_VAR_INIT) CanTp_RxState[CANTP_CHANNEL_NUM + 1U];
extern VAR(CanTp_TxStateType_st, CANTP_VAR_INIT) CanTp_TxState[CANTP_CHANNEL_NUM + 1U];
extern VAR(CanTp_InitStatusType, CANTP_VAR_INIT) CanTp_InitState;

#define CANTP_STOP_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanTp_MemMap.h"

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

#define CANTP_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanTp_MemMap.h"

extern FUNC(void, CANTP_CODE) CanTp_Init
(
    P2CONST(CanTp_ConfigType, AUTOMATIC, CANTP_APPL_CONST) CfgPtr
);
/* Polyspace +1 MISRA-C3:8.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Rule8.5" */
extern FUNC(void, CANTP_CODE) CanTp_MainFunction(void);
extern FUNC(void, CANTP_CODE) CanTp_Shutdown(void);
extern FUNC(void, CANTP_CODE) CanTp_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CANTP_APPL_DATA) versionInfo
);
extern FUNC(Std_ReturnType, CANTP_CODE) CanTp_CancelTransmit(PduIdType CanTpTxSduId);
extern FUNC(Std_ReturnType, CANTP_CODE) CanTp_CancelReceive(PduIdType CanTpRxSduId);
extern FUNC(Std_ReturnType, CANTP_CODE) CanTp_Transmit
(
    PduIdType CanTpTxSduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) CanTpTxInfoPtr
);
extern FUNC(Std_ReturnType, CANTP_CODE) CanTp_ReadParameter
(
    PduIdType id,
    TPParameterType parameter,
    P2VAR(uint16, AUTOMATIC, CANTP_APPL_DATA) value
);
extern FUNC(Std_ReturnType, CANTP_CODE) CanTp_ChangeParameter
(
    PduIdType id,
    TPParameterType parameter,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanTp_Dir4.5" */
    uint16 value
);
extern FUNC(void, CANTP_CODE) CanTp_TxInitState(uint8 chnId);

#define CANTP_STOP_SEC_CODE
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanTp_MemMap.h"

#endif /* CANTP_H_ */
