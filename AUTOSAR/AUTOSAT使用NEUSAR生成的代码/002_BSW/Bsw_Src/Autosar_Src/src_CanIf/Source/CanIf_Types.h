/*
********************************************************************************
*
* File name: CanIf_Types.h
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
* Change: 1.Add Types: CanIf_Can_WriteFuncType
*                    CanIf_Can_SetCtrlModeFuncType
*                    CanIf_CanMultipeDrvInfoType.
*         2.Add Macros: CANIF_VALUE_THREE.
* Cause: Adding Functionality(Multiple CAN Driver support).
********************************************************************************
* Version: 3.1
* Author/Date: WangCong/2020.05.12
* Change: Modify the code specification.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: WangC/2020.09.30
* Change: Modify the type define about CANFD Tx buffer.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: WangC/2020.10.24
* Change: Modify the function name according to the AUTOSAR specification, add
*         MemMap.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: WangC/2020.10.24
* Change: Modify the code according to QAC.
* Cause: Clear QAC warning
********************************************************************************
* Version: 3.5
* Author/Date: WangC/2021.8.2
* Change: Modify some type define to be compatible with AUTOSAR version 4.3.1.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: HuangF/2022.9.3
* Change: Modify macro CANIF_SVID_CLEARTRCVWAKEFLAG and CANIF_SVID_CLRTRCVWAKEFLAGINDC .
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: LiDY/2023.4.12
* Change: Add CanID extened filtering macro definition.
* Cause: Bugfix
********************************************************************************
* Version: 3.8
* Author/Date: YanCL/2024.4.2
* Change: Modify the annotation.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: YanCL/2024.7.9
* Change: Update copyright information.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: YanCL/2024.8.14
* Change: Move application type definitions to RTE.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: YanCL/2025.06.06
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef CANIF_TYPES_H_
#define CANIF_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "ComStack_Types.h"
#include "Can_GeneralTypes.h"
#include "Rte_CanIf_Type.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CANIF_VALUE_ZERO                        (0U)
#define CANIF_VALUE_ONE                         (1U)
#define CANIF_VALUE_TWO                         (2U)
#define CANIF_VALUE_THREE                       (3U)
#define CANIF_VALUE_EIGHT                       (8U)
#define CANIF_VALUE_SIXTEEN                     (16U)
#define CANIF_VALUE_TWENTYFOUR                  (24U)
#define CANIF_VALUE_0x7FF                       (0x7FFU)
#define CANIF_VALUE_0x1FFFFFFF                  (0x1FFFFFFFU)

#define CANIF_VALUE_0x600                       (0x600U)

#define CANIF_MBSTA_IDLE                        (0x01U) /* Bit0 IDEL OR BUSY. */
#define CANIF_MBSTA_UNLOCK                      (0x02U) /* Bit1 LOCK OR UNLOCK. */

#define CANIF_METADATA_LENGTH_4BYTE             (0x04U)

/* Can_IdType The two most significant bits specify the frame type: */
#define CANIF_STANDARD_CANID_TYPE               (0x00000000UL)
#define CANIF_STANDARD_FD_CANID_TYPE            (0x40000000UL)
#define CANIF_EXTENDED_CANID_TYPE               (0x80000000UL)
#define CANIF_EXTENDED_FD_CANID_TYPE            (0xC0000000UL)
#define CANIF_FD_CANID_TYPE                     (0x40000000UL)
#define CANIF_BIT_BASE_CANID_TYPE               (0xC0000000UL)

#define CANIF_CAN20B_MAXLENGTH                  (8U)
#define CANIF_CANFD_MAXLENGTH                   (64U)

#define CANIF_TXBUF_NOPDU                       (0xFFFFU)
#define CANIF_CANIDMAPRX_NOPDU                  (0xFFFFU)
#define CANIF_CANCTRL_NOMATCH                   (0xFFU)

/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" Polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt " */
#define CANIF_DUMMY_STATEMENT(v)                (v)=(v)

/* CanIf Service ID. */
#define CANIF_SVID_INIT                         (0x01U)
#define CANIF_SVID_SETCONTROLLERMODE            (0x03U)
#define CANIF_SVID_GETCONTROLLERMODE            (0x04U)
#define CANIF_SVID_TRANSMIT                     (0x05U)
#define CANIF_SVID_CANCELTRANSMIT               (0x18U)
#define CANIF_SVID_READRXPDUDATA                (0x06U)
#define CANIF_SVID_READTXNOTIFSTATUS            (0x07U)
#define CANIF_SVID_READRXNOTIFSTATUS            (0x08U)
#define CANIF_SVID_SETPDUMODE                   (0x09U)
#define CANIF_SVID_GETPDUMODE                   (0x0AU)
#define CANIF_SVID_GETVERSIONINFO               (0x0BU)
#define CANIF_SVID_SETDYNAMICTXID               (0x0CU)
#define CANIF_SVID_SETTRCVMODE                  (0x0DU)
#define CANIF_SVID_GETTRCVMODE                  (0x0EU)
#define CANIF_SVID_GETTRCVWUREASON              (0x0FU)
#define CANIF_SVID_GETTRCVWUMODE                (0x10U)
#define CANIF_SVID_CHECKWAKEUP                  (0x11U)
#define CANIF_SVID_CHECKVALIDATION              (0x12U)
#define CANIF_SVID_GETTXCONFIRMSTA              (0x19U)
#define CANIF_SVID_CLEARTRCVWUFLAG              (0x1EU)
#define CANIF_SVID_CHECKTRCVWAKEFLAG            (0x1FU)
#define CANIF_SVID_SETBAUDRATE                  (0x27U)
#define CANIF_SVID_SETICOMCONFIGURATION         (0x25U)
#define CANIF_SVID_TRIGGERTRANSMIT              (0x41U)
#define CANIF_SVID_TXCONFIRMATION               (0x13U)
#define CANIF_SVID_RXINDICATION                 (0x14U)
#define CANIF_SVID_CONTROLLERBUSOFF             (0x16U)
#define CANIF_SVID_CONFIRMPNAVAILAB             (0x1AU)
#define CANIF_SVID_CLEARTRCVWUFLAGINDC          (0x20U)
#define CANIF_SVID_CHECKTRCVWAKEFLAGINDC        (0x21U)
#define CANIF_SVID_CONTROLLERMODEINDC           (0x17U)
#define CANIF_SVID_TRCVMODEINDC                 (0x22U)
#define CANIF_SVID_CURICOMCFG                   (0x26U)

#define CANIF_INSTANCE_ID_DET                   (0U)

/* Development Errors. */
#define CANIF_E_PARAM_CANID                     (10U)
#define CANIF_E_PARAM_DLC                       (11U)
#define CANIF_E_PARAM_HRH                       (12U)
#define CANIF_E_PARAM_LPDU                      (13U)
#define CANIF_E_PARAM_CONTROLLER                (14U)
#define CANIF_E_PARAM_CONTROLLERID              (15U)
#define CANIF_E_PARAM_WAKEUPSOURCE              (16U)
#define CANIF_E_PARAM_TRCV                      (17U)
#define CANIF_E_PARAM_TRCVMODE                  (18U)
#define CANIF_E_PARAM_TRCVWAKEUPMODE            (19U)
#define CANIF_E_PARAM_POINTER                   (20U)
#define CANIF_E_PARAM_CTRLMODE                  (21U)
#define CANIF_E_PARAM_PDU_MODE                  (22U)
#define CANIF_E_UNINIT                          (30U)
#define CANIF_E_INVALID_TXPDUID                 (50U)
#define CANIF_E_INVALID_RXPDUID                 (60U)
#define CANIF_E_INVALID_DLC                     (61U)
#define CANIF_E_STOPPED                         (70U)
#define CANIF_E_NOT_SLEEP                       (71U)

/* Not defined by AUTOSAR. */
#define CANIF_E_NO_ERR                          (0U)
#define CANIF_E_INVALID_PDURECEPTIONMODE        (44U)
#define CANIF_E_CONFIG                          (45U)
#define CANIF_E_FATAL                           (46U)
#define CANIF_E_INVALID_SA                      (47U)
#define CANIF_E_INVALID_DA                      (48U)
#define CANIF_E_INVALID_CANIDTYPESIZE           (49U)
#define CANIF_E_INVALID_DLC_METADATA            (50U)

#define CANIF_E_FULL_TX_BUFFER_FIFO             (51U) /* FEAT-1429. */
#define CANIF_E_INVALID_DOUBLEHASH_CALC         (52U) /* ESCAN00087755. */

#define CANIF_E_DATA_LENGTH_MISMATCH            (62U)
#define CANIF_E_INVALID_HOH                     (63U)

#define CANIF_SWFILTER_BINARY                   (0U)
#define CANIF_SWFILTER_INDEX                    (1U)
#define CANIF_SWFILTER_LINEAR                   (2U)
#define CANIF_SWFILTER_TABLE                    (3U)

#define CANIF_CBK_TYPE_RX_NULL_PTR  (0U)
#define CANIF_CBK_TYPE_RX_CANNM     (1U)
#define CANIF_CBK_TYPE_RX_CANTP     (2U)
#define CANIF_CBK_TYPE_RX_J1939TP   (3U)
#define CANIF_CBK_TYPE_RX_XCP       (4U)
#define CANIF_CBK_TYPE_RX_PDUR      (5U)

#define CANIF_CBK_TYPE_TX_NULL_PTR  (0U)
#define CANIF_CBK_TYPE_TX_CANNM     (1U)
#define CANIF_CBK_TYPE_TX_CANTP     (2U)
#define CANIF_CBK_TYPE_TX_J1939TP   (3U)
#define CANIF_CBK_TYPE_TX_XCP       (4U)
#define CANIF_CBK_TYPE_TX_PDUR      (5U)

#define CANIF_CBK_TXCFM_NUM         (5U)
#define CANIF_CBK_RXIDC_NUM         (5U)

#define CANIF_CHANNEL_A             (0U)
#define CANIF_CHANNEL_B             (1U)
#define CANIF_CHANNEL_C             (2U)
#define CANIF_CHANNEL_D             (3U)

#define CANIF_MSG_STD               (0U)
#define CANIF_MSG_EXT               (1U)

#define CANIF_UNUSE                 (0U)
#define CANIF_TX                    (1U)
#define CANIF_RX                    (2U)

#define CANIF_LIST                  (0U)
#define CANIF_MUXM                  (1U)

#define CANIF_MSG_DISISR            (0U)
#define CANIF_MSG_ENISR             (1U)

#define CANIF_CBK_TYPE_RX_NULL_PTR  (0U)
#define CANIF_CBK_TYPE_RX_CANNM     (1U)
#define CANIF_CBK_TYPE_RX_CANTP     (2U)
#define CANIF_CBK_TYPE_RX_J1939TP   (3U)
#define CANIF_CBK_TYPE_RX_XCP       (4U)
#define CANIF_CBK_TYPE_RX_PDUR      (5U)

#define CANIF_CBK_TYPE_TX_NULL_PTR  (0U)
#define CANIF_CBK_TYPE_TX_CANNM     (1U)
#define CANIF_CBK_TYPE_TX_CANTP     (2U)
#define CANIF_CBK_TYPE_TX_J1939TP   (3U)
#define CANIF_CBK_TYPE_TX_XCP       (4U)
#define CANIF_CBK_TYPE_TX_PDUR      (5U)

#define CANIF_CBK_TXCFM_NUM         (5U)
#define CANIF_CBK_RXIDC_NUM         (5U)

#define CANIF_CHANNEL_A             (0U)
#define CANIF_CHANNEL_B             (1U)
#define CANIF_CHANNEL_C             (2U)
#define CANIF_CHANNEL_D             (3U)

#define CANIF_MSG_STD               (0U)
#define CANIF_MSG_EXT               (1U)

#define CANIF_UNUSE                 (0U)
#define CANIF_TX                    (1U)
#define CANIF_RX                    (2U)

#define CANIF_LIST                  (0U)
#define CANIF_MUXM                  (1U)

#define CANIF_MSG_DISISR            (0U)
#define CANIF_MSG_ENISR             (1U)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/

typedef uint8 CanIf_ConfigType;     /* NEUSAR not used. */

typedef enum
{
    CANIF_NO_NOTIFICATION = 0U,
    CANIF_TX_RX_NOTIFICATION
} CanIf_NotifStatusType;

/* Polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct CanIf_CanChGlobalTypeTag
{
    VAR(CanIf_PduModeType, TYPEDEF) PduModeCtrlSta;
    VAR(CanIf_ControllerModeType, TYPEDEF) ControllerModeSta;
    VAR(CanIf_NotifStatusType, TYPEDEF) TxConfirmationState;
    VAR(boolean, TYPEDEF) rxWakeupEvent;
} CanIf_CanChGlobalType;

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

#endif /* CANIF_TYPES_H_ */

