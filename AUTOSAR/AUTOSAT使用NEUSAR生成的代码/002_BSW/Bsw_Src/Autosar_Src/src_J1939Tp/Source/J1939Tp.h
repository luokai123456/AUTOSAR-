/*
********************************************************************************
*
* File name: J1939Tp.h
*
* Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: yong.zhang/2019.3.18
* Change: New created.
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: li.zhiheng/2020.03.30
* Change: Only version updata to 3.0.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: li.zhiheng/2020.05.20
* Change: Modification code specification.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: lizhiheng/2020.06.08
* Change: Add release software number.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: li.zhiheng/2020.09.26
* Change: Add code related to MEMAP.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: li.zhiheng/2020.10.15
* Change: 1.Modify coding standards.
*         2.Modify QAC warning.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: LiZH/2020.11.04
* Change: Delete the function declaration contained in MemMap.h.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: LiZH/2021.5.24
* Change: 1.Modifty J1939TP_E_INVALID_TMS to 0x40.
*         2.Delete function declaration.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: LiZH/2021.5.31
* Change: 1.Add J1939TP_E_INVALID_DA.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: LiZH/2021.6.29
* Change: 1.Updata version informatio to 3.2.0.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: Li.ZH/2021.8.16
* Change: Modification code specification.
* Cause: Optimize
********************************************************************************
* Version: 3.9
* Author/Date: LiZH/2021.10.20
* Change: Modified version number.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: LiZH/2021.11.1
* Change: Updata versions.
* Cause: Optimize
********************************************************************************
* Version: 3.11
* Author/Date: TongXY/2023.3.14
* Change: Fix coding specification problems.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date: TongXY/2023.4.13
* Change: Add pre-compilation for function declarations J1939Tp_CancelTransmit
*         and J1939Tp_CancelReceive.
* Cause: Bugfix
********************************************************************************
* Version: 3.13
* Author/Date: TongXY/2023.05.24
* Change: Update software version to 3.7.0.
* Cause: Optimization
********************************************************************************
* Version: 3.14
* Author/Date: LiuY/2023.08.17
* Change: Update software version to 3.8.0.
* Cause: Optimization
********************************************************************************
* Version: 3.15
* Author/Date: YanCL/2023.11.28
* Change: Update software version to 3.9.0.0.
* Cause: Optimization
********************************************************************************
* Version: 3.16
* Author/Date: YanCL/2024.3.19
* Change: Update software version to 3.10.0.1.
* Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date: YanCL/2024.4.2
* Change: 1. Update software version to 3.10.0.2.
*         2. Modify the P2CONST incorrect labels.
*         3. Modify the annotation.
* Cause: Optimization
********************************************************************************
* Version: 3.18
* Author/Date: YanCL/2024.5.23
* Change: 1.Update software version to 3.11.0.3.
*         2.Adjusting the parameter positions of function declarations.
* Cause: Update
********************************************************************************
* Version: 3.19
* Author/Date: YanCL/2024.6/25
* Change: 1.Update software version to 3.11.0.4.
*         2.Add copyright information.
*         3.Add Memmap segment definition.
* Cause: Update
********************************************************************************
* Version: 3.20
* Author/Date: YanCL/2024.10.2
* Change: 1.Update software version to 3.11.0.5.
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date: YanCL/2024.10.11
* Change: Update software version to 3.11.0.6.
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date: YanCL/2025.03.26
* Change: Update software version to 3.13.0.7.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: YanCL/2025.06.06
* Change: 1.Add the polyspace deviation suppression comment.
*         2.Update software version to 3.14.0.8.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: YanCL/2025.06.23
* Change: Update software version to 3.14.0.9.
* Cause: Update
********************************************************************************
*/
#ifndef J1939TP_H_
#define J1939TP_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "J1939Tp_Cfg.h"
#include "ComStack_Types.h"
  /* SWS_J1939Tp_00016 */

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* Vendor and module identification. */
#define J1939TP_VENDOR_ID                      (119U)
#define J1939TP_MODULE_ID                      (37U)

/* Vendor specific BSW module version information. */
#define J1939TP_SW_MAJOR_VERSION               (3U)
#define J1939TP_SW_MINOR_VERSION               (14U)
#define J1939TP_SW_PATCH_VERSION               (0U)
#define J1939TP_SW_REVISION_VERSION            (9U)

/* AUTOSAR Version. */
#define J1939TP_AR_RELEASE_MAJOR_VERSION       (4U)
#define J1939TP_AR_RELEASE_MINOR_VERSION       (2U)
#define J1939TP_AR_RELEASE_REVISION_VERSION    (2U)

/* API service IDs. */
#define J1939TP_SID_INIT                       (0x01U)   /* Service ID: J1939Tp_Init() */
#define J1939TP_SID_SHUTDOWN                   (0x02U)   /* Service ID: J1939Tp_Shutdown() */
#define J1939TP_SID_GETVERSIONINFO             (0x03U)   /* Service ID: J1939Tp_GetVersionInfo() */
#define J1939TP_SID_MAINFUNCTION               (0x04U)   /* Service ID: J1939Tp_MainFunction() */
#define J1939TP_SID_TRANSMIT                   (0x05U)   /* Service ID: J1939Tp_Transmit() */
#define J1939TP_SID_CHANGEPARAMETER            (0x08U)   /* Service ID: J1939Tp_ChangeParameter() */
#define J1939TP_SID_CANCELTRANSMIT             (0x09U)   /* Service ID: J1939Tp_CancelTransmit() */
#define J1939TP_SID_CANCELRECEIVE              (0x0AU)   /* Service ID: J1939Tp_CancelReceive() */
#define J1939TP_SID_RXINDICATION               (0x42U)   /* Service ID: J1939Tp_RxIndication() */
#define J1939TP_SID_TXCONFIRMATION             (0x40U)   /* Service ID: J1939Tp_TxConfirmation() */

/* J1939Tp following development errors. SWS_J1939Tp_00115 */
#define J1939TP_E_NO_ERROR                 (0x00U)   /* No error. */
#define J1939TP_E_UNINIT                   (0x01U)   /* API service used in state J1939TP_OFF. */
#define J1939TP_E_REINIT                   (0x02U)   /* J1939Tp_Init() called in state J1939TP_ON. */
#define J1939TP_E_INIT_FAILED              (0x03U)   /* J1939Nm_Init was called with an invalid configuration pointer */
#define J1939TP_E_PARAM_POINTER            (0x10U)   /* API service called with null pointer. */
#define J1939TP_E_INVALID_PDU_SDU_ID       (0x11U)   /* API service called with wrong ID. */
#define J1939TP_E_TIMEOUT_T1               (0x30U)   /* Timeout occurred on receiver side after reception of an intermediate TP.DT frame of a block. */
#define J1939TP_E_TIMEOUT_T2               (0x31U)   /* Timeout occurred on receiver side after transmission of a TP.CM/CTS frame. */
#define J1939TP_E_TIMEOUT_T3               (0x32U)   /* Timeout occurred on transmitter side after transmission of the last TP.DT frame of a block. */
#define J1939TP_E_TIMEOUT_T4               (0x33U)   /* Timeout occurred on transmitter side after reception of a TP.CM/CTS(0) frame. */
#define J1939TP_E_TIMEOUT_TR               (0x34U)   /* Timeout occurred on transmitter or receiver side while trying to send the next TP.DT or TP.CM frame. */
#define J1939TP_E_TIMEOUT_TH               (0x35U)   /* Timeout occurred on receiver side while trying to send the next TP.CM/CTS frame after a TP.CM/CTS(0) frame. */
#define J1939TP_E_INVALID_TMS              (0x40U)   /* Invalid value for "total message size" in received TP.CM/RTS frame. */
#define J1939TP_E_INVALID_TNOP             (0x41U)   /* Value for "total number of packets" in received TP.CM/RTS frame does not match the "total message size". */
#define J1939TP_E_INVALID_MNOP             (0x42U)   /* Invalid value for "maximum number of packets" in received TP.CM/RTS frame. */
#define J1939TP_E_INVALID_PGN              (0x43U)   /* Unexpected PGN in received TP.CM frame. */
#define J1939TP_E_INVALID_NOP              (0x44U)   /* Invalid value for "number of packets" in received TP.CM/CTS frame. */
#define J1939TP_E_INVALID_NPN              (0x45U)   /* Invalid value for "next packet number" in received TP.CM/CTS frame. */
#define J1939TP_E_INVALID_CAR              (0x46U)   /* Invalid value for "connection abort reason" in received TP.Conn_Abort frame. */
#define J1939TP_E_INVALID_SN               (0x47U)   /* Unexpected serial number in received TP.DT frame. */

#define J1939TP_E_INTERNAL_ERROR           (0x48U)
#define J1939TP_E_INVALID_CHANGE_PARAM     (0x49U)
#define J1939TP_E_INVALID_CHANGE_VALUE     (0x50U)
#define J1939TP_E_INVALID_LENGTH           (0x52U)
#define J1939TP_E_INVALID_SA               (0x53U)
#define J1939TP_E_INVALID_PARAM            (0x54U)
#define J1939TP_E_INVALID_DA               (0x55U)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* Data structure containing post-build configuration data of J1939-TP. SWS_J1939Tp_00175 */
/* Polyspace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Rule4.8" Polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct sJ1939Tp_PCConfigType
{
    uint8 J1939Tp_PCConfigNeverUsed;
} J1939Tp_ConfigType;

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

#define J1939TP_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"

extern FUNC(void, J1939TP_CODE) J1939Tp_Init
(
    P2CONST(J1939Tp_ConfigType, AUTOMATIC, J1939TP_APPL_CONST) ConfigPtr
);
extern FUNC(void, J1939TP_CODE) J1939Tp_Shutdown(void);
extern FUNC(void, J1939TP_CODE) J1939Tp_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, J1939TP_APPL_DATA) VersionInfo
);
extern FUNC(Std_ReturnType, J1939TP_CODE) J1939Tp_Transmit
(
    PduIdType TxSduId,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) TxInfoPtr
);
#if( J1939TP_CANCELLATION_SUPPORT == STD_ON )
extern FUNC(Std_ReturnType, J1939TP_CODE) J1939Tp_CancelTransmit(PduIdType TxSduId);
extern FUNC(Std_ReturnType, J1939TP_CODE) J1939Tp_CancelReceive(PduIdType RxSduId);
#endif
extern FUNC(Std_ReturnType, J1939TP_CODE) J1939Tp_ChangeParameter
(
    PduIdType RxSduId,
    TPParameterType parameter,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_J1939Dcm_Dir4.5" */
    uint16 value
);
extern FUNC(void, J1939TP_CODE) J1939Tp_MainFunction(void);

#define J1939TP_STOP_SEC_CODE
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"

#endif /* J1939TP_H_ */
