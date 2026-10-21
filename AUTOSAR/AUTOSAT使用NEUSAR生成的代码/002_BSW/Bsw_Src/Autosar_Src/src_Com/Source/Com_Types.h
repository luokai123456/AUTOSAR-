/*
********************************************************************************
*
* File name: Com_Types.h
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
* Version: 3.0
* Author/Date: lizhiheng/2019.12.24
* Change: Modify some macro definitions and types.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: lizhiheng/2019.12.24
* Change: Change the COM_RxSignalInfo_st structure element type, acSigGrpIdx uint8 to uint16.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: lizhiheng/2020.01.11
* Change: Change the COM_TxPduInfo_st,COM_RxPduInfo_st Callout type.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: lizhiheng/2020.01.15
* Change: Add NULL macro definition judge.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: lizhiheng/2020.03.23
* Change: Add type for function of gateway.
* Cause: Add function for gateway
********************************************************************************
* Version: 3.4
* Author/Date: lizhiheng/2020.03.30
* Change: Modify Com_FilterInfoType_st struct.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: lizhiheng/2020.05.07
* Change: Delete #include "typedefs.h".
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: lizhiheng/2020.05.11
* Change: Modify code specification.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: lizhiheng/2020.06.22
* Change: Modify Com_FilterInfoType_st struct.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: lizhiheng/2020.08.11
* Change: Add OPAQUE type.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: lizhiheng/2020.08.31
* Change: Add Com_ReceptionDMControl Api uesd flag bit.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: lizhiheng/2020.09.01
* Change: Modify the data type of the structure.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: Wangcong/2020.09.17
* Change: Modify the data type of the structure.
* COM_TxSignalInfo_st, Com_TxInterMonitor_st, COM_TxPduInfo_st, COM_TxModeInfo_st,
* Com_TxMode_st, COM_RxPduInfo_st, COM_RxSignalInfo_st
* Cause: bugfix
********************************************************************************
* Version: 3.12
* Author/Date: WangC/2020.09.23
* Change: Add the function of signal gateway with description.
* Cause: Add function.
********************************************************************************
* Version: 3.13
* Author/Date: lizhiheng/2020.09.24
* Change: Modify the name of the starting end byte in the signal group.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: lizhiheng/2020.09.30
* Change: Modify the coding style of AutoSar.
* Cause: Update
********************************************************************************
* Version: 3.15
* Author/Date: LiZH/2020.10.20
* Change: Modify QAC warning.
* Cause: Update
********************************************************************************
* Version: 3.16
* Author/Date: LiZH/2020.10.28
* Change: Modify QAC warning.
* Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date: WangC/2020.10.29
* Change: Add GW function of stopping cycle msg.
* Cause: Special requirements.
********************************************************************************
* Version: 3.18
* Author/Date: LiZH/2020.11.02
* Change: Cancel AutoSar style coding.
* Cause: Update
********************************************************************************
* Version: 3.19
* Author/Date: LiZH/2020.11.20
* Change: Add a time count flag.
* Cause: Update
********************************************************************************
* Version: 3.20
* Author/Date: LiZH/2020.12.4
* Change: Add rxsignal timeout replace value.
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date: LiZH/2021.10.28
* Change: Add #include "ComStack_Types.h".
* Cause: optimize
********************************************************************************
* Version: 3.22
* Author/Date: LiZH/2021.10.28
* Change: Remove excess Spaces.
* Cause: optimize
********************************************************************************
* Version: 3.23
* Author/Date: LiXB/2022.9.22
* Change: Add two members for COM_TxPduInfo_st and COM_RxPduInfo_st, to support
*         multi-core.Add struct type Com_PduIndexInfo_st to search pdu. Add head 
*         file Com_Cfg.h and two new data types Com_MainFunctionType and
*         Com_PduIndexType.
* Cause: optimize
********************************************************************************
* Version: 3.24
* Author/Date: LiXB/2022.11.21
* Change: Add two tx mode COM_TXMODE_IF_ACTIVE and COM_TXMODE_PERIODIC_IF_ACTIVE,
*         add sigInactiveValue to COM_TxSignalInfo_st, add COM_TRANS_PASSIVE to
*         Com_SigTransferPropertyType, add acTxCycleFast to Com_TxMode_st.
* Cause: update
********************************************************************************
* Version: 3.25
* Author/Date: LiXB/2022.11.25
* Change: Add acSignalGrpEnableDeadline to Com_SignalGroupMonitor_st and acSignalEnableDeadline 
*         to Com_SignalMonitor_st to support first timeout.
*         Add COM_TRANS_TRIGGERED_ON_IF_ACTIVE to Com_SigTransferPropertyType.
*         Add sigMinimumFirstTimeout to COM_RxPduInfo_st.
* Cause: update
********************************************************************************
* Version: 3.26
* Author/Date: LiXB/2022.12.6
* Change: Add acSignalGrpUpdateEnableDeadline to Com_SignalGroupMonitor_st and acSignalUpdateEnableDeadline 
*         to Com_SignalMonitor_st to support first timeout.
* Cause: update
********************************************************************************
* Version: 3.27
* Author/Date: HeZH/2023.02.06
* Change: Add signal filtering data structure.
* Cause: update
********************************************************************************
* Version: 3.28
* Author/Date: HeZH/2023.02.14
* Change: Modify the struct element data type.
* Cause: update
********************************************************************************
* Version: 3.29
* Author/Date: HeZH/2023.03.16
* Change: 1.Modify the structure COM_TxPduInfo_st element acMetaDataIdx data type to uint16.
*         2.Added macro definition COM_PDU_NO_METADATA_DEF.
*         3.Increase the structure Com_PduMetaDataMonitorType.
* Cause: Update
********************************************************************************
* Version: 3.30
* Author/Date: TianSL/2023.09.18
* Change: Enumerations in structures that are used a lot are canceled.
* Cause: Update
********************************************************************************
* Version: 3.31
* Author/Date: TianSL/2023.10.08
* Change: Modify COM_RxSignalInfo_st, COM_TxPduInfo_st,
*         COM_RxPduInfo_st, COM_RxSigGrpInfo_st struct member order.
* Cause: Update
********************************************************************************
* Version: 3.32
* Author/Date: HeH/2023.12.04
* Change: Modify Com_PduReceiveSts,
*         Add Com_TxPduInfoTableType,
*         Add Com_GatewayInfoTableType.
* Cause: Update
********************************************************************************
* Version: 3.33
* Author/Date: ZhangF/2023.12.04
* Change: Add the Com_RxPduInfoTableType struct define.
* Cause: Update
********************************************************************************
* Version: 3.33
* Author/Date: TianG/2023.12.04
* Change: Add funcId to COM_RxSignalInfo_st and COM_TxSignalInfo_st.
* Cause: Update
********************************************************************************
* Version: 3.34
* Author/Date: TianSL/2023.12.05
* Change: 1.Add four macros define.
*         2.Add sigGrpType member to the COM_RxSigGrpInfo_st struct.
* Cause: Update
********************************************************************************
* Version: 3.35
* Author/Date: TianSL/2023.12.07
* Change: Add four macros define.
* Cause: Update
********************************************************************************
* Version: 3.36
* Author/Date: TianG/2023.12.19
* Change: Add COM_PDU_GW_SIG_DSCP_FLAG to Com_PduReceiveSts.
* Cause: Update
********************************************************************************
* Version: 3.37
* Author/Date : LuQ/2024.04.02
* Change: Modify the comments format.
* Cause: Optimization
********************************************************************************
* Version: 3.38
* Author/Date: TianG/2024.04.07
* Change: 1.Add Com_SignalBaseInfo_st structure definition.
*         2.Remove COM_TxSignalInfo_st and COM_RxSignalInfo_st some members.
*         3.Add Com_SignalBaseInfo_st member to COM_TxSignalInfo_st and COM_RxSignalInfo_st.
*         4.Remove sigType and sigEndianess,replace them with sigFuncIdx.
* Cause: Update
********************************************************************************
* Version: 3.39
* Author/Date: LuQ/2024.05.13
* Change: Add Memmap segment definition.
* Cause: Update
********************************************************************************
* Version: 3.40
* Author/Date: LuQ/2024.07.25
* Change: Optimizes infrequently used structure elements.
* Cause: Optimization
********************************************************************************
* Version: 3.41
* Author/Date: LuQ/2024.08.13
* Change: Add a macro definition(COM_INIT_ZERO).
* Cause: Update
********************************************************************************
* Version: 3.42
* Author/Date: LuQ/2024.08.14
* Change: Move application type definitions to RTE.
* Cause: Update
********************************************************************************
* Version: 3.43
* Author/Date: LuQ/2024.08.15
* Change: Add Com_IpduGroupIdType definition.
* Cause: Update
********************************************************************************
* Version: 3.44
* Author/Date: LuQ/2024.10.10
* Change: Add structure element for ComTriggeredResetPeriodicTimer.
* Cause: Bugfix
********************************************************************************
* Version: 3.45
* Author/Date: LuQ/2024.11.11
* Change: Add pdu timeout flag.
* Cause: Update
********************************************************************************
* Version: 3.46
* Author/Date: LuQ/2024.11.27
* Change: Add COM_RXREPLACESIGOFRXTIMEOUTINFO definition.
* Cause: Bugfix
********************************************************************************
* Version: 3.47
* Author/Date: LuQ/2025.02.28
* Change: Add COM_PDU_GW_DSCP_HANDLE_FLAG to Com_PduReceiveSts.
* Cause: Update
********************************************************************************
* Version: 3.48
* Author/Date: LuQ/2025.03.11
* Change: Add structure element (signal Type) for COM_TxSignalInfo_st and
*         COM_RxSignalInfo_st.
* Cause: Update
********************************************************************************
* Version: 3.49
* Author/Date: LuQ/2025.03.27
* Change: Modify the scope of influence of COM_TXPDU_CBKNOTIFTY_SUPPORT.
* Cause: Update
********************************************************************************
* Version: 3.50
* Author/Date: LuQ/2025.05.12
* Change: Add structure element(acSigGrpValue) for COM_RxSigGrpInfo_st.
* Cause: Update
********************************************************************************
* Version: 3.51
* Author/Date: LuQ/2025.06.17
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef COM_TYPES_H_
#define COM_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "ComStack_Types.h"
#include "Com_Cfg.h"
#include "Rte_Com_Type.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Com State. */
/* PolySpace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define COM_SERVICE_NOT_AVAILABLE       (0x80U)
#define COM_BUSY                        (0x81U)

#define COM_SIG_NO_UPDATEBIT_DEF        (0xFFFFU)
#define COM_SIG_NO_GROUP_DEF            (0xFFFFU)
#define COM_GW_NO_SIG_GROUP_DEF         (0xFFFFU)
#define COM_GW_NO_SIG_DEF               (0xFFFFU)
#define COM_PDU_NO_METADATA_DEF         (0xFFFFU)

#define COM_TXMODE_NONE                     (0U)     /* Pdu Tx Mode None. */
#define COM_TXMODE_PREDIOC                  (1U)     /* Pdu Tx Mode Period. */
#define COM_TXMODE_DIRECT                   (2U)     /* Pdu Tx Mode Trigger. */
#define COM_TXMODE_MIX                      (3U)     /* Pdu Tx Mode Mix(Trigger/Period). */
#define COM_TXMODE_IF_ACTIVE                (4U)     /* Pdu Tx Mode if active */
#define COM_TXMODE_PERIODIC_IF_ACTIVE       (5U)     /* Pdu Tx Mode periodic and if active */

#define COM_PDU_TYPE_ACTIVE_ALWAYS          (0x00U)  /* Pdu Active Type:Always Active. */
#define COM_PDU_TYPE_ACTIVE_CONTROL         (0x01U)  /* Pdu Active Type:Active Control by Com_IpduGroupControl. */

#ifndef NULL
#define NULL  (0U)
#endif

#define COM_SIGTYPE_BOOLEAN                            (0U)
#define COM_SIGTYPE_FLOAT32                            (1U)
#define COM_SIGTYPE_FLOAT64                            (2U)
#define COM_SIGTYPE_SINT16                             (3U)
#define COM_SIGTYPE_SINT32                             (4U)
#define COM_SIGTYPE_SINT64                             (5U)
#define COM_SIGTYPE_SINT8                              (6U)
#define COM_SIGTYPE_UINT16                             (7U)
#define COM_SIGTYPE_UINT32                             (8U)
#define COM_SIGTYPE_UINT64                             (9U)
#define COM_SIGTYPE_UINT8                              (10U)
#define COM_SIGTYPE_UINT8_DYN                          (11U)
#define COM_SIGTYPE_UINT8_N                            (12U)
#define COM_SIGTYPE_INVALID                            (255U)

#define COM_BIG_ENDIAN                                 (0U)
#define COM_LITTLE_ENDIAN                              (1U)
#define COM_OPAQUE                                     (2U)

#define COM_BIG_ENDIAN_FUNCID_MAX                      (45U)    /* Big endian signal max funcid. */
#define COM_LITTLE_ENDIAN_FUNCID_MAX                   (89U)    /* Little endian signal max funcid. */

#define COM_BOOLEAN_FUNCID                             (0U)    /* bool signal funcid. */
#define COM_BIG_ENDIAN_UINT8_START_FUNCID              (1U)    /* Big endian uint8 type signal start funcid. */
#define COM_BIG_ENDIAN_UINT8_END_FUNCID                (5U)    /* Big endian uint8 type signal end funcid. */

#define COM_BIG_ENDIAN_UINT16_START_FUNCID             (6U)    /* Big endian uint16 type signal start funcid. */
#define COM_BIG_ENDIAN_UINT16_END_FUNCID               (10U)   /* Big endian uint16 type signal end funcid. */

#define COM_BIG_ENDIAN_UINT32_START_FUNCID             (11U)   /* Big endian uint32 type signal start funcid. */
#define COM_BIG_ENDIAN_UINT32_END_FUNCID               (20U)   /* Big endian uint32 type signal end funcid. */

#define COM_BIG_ENDIAN_UINT64_FUNCID                   (21U)   /* Big endian uint64 type signal funcid. */

#define COM_BIG_ENDIAN_SINT8_START_FUNCID              (22U)   /* Big endian sint8 type signal start funcid. */
#define COM_BIG_ENDIAN_SINT8_END_FUNCID                (26U)   /* Big endian sint8 type signal end funcid. */

#define COM_BIG_ENDIAN_SINT16_START_FUNCID             (27U)   /* Big endian sint16 type signal start funcid. */
#define COM_BIG_ENDIAN_SINT16_END_FUNCID               (31U)   /* Big endian sint16 type signal end funcid. */

#define COM_BIG_ENDIAN_SINT32_START_FUNCID             (32U)   /* Big endian sint32 type signal start funcid. */
#define COM_BIG_ENDIAN_SINT32_END_FUNCID               (41U)   /* Big endian sint32 type signal end funcid. */

#define COM_BIG_ENDIAN_SINT64_FUNCID                   (42U)   /* Big endian sint64 type signal funcid. */

#define COM_BIG_ENDIAN_FLOAT32_FUNCID                  (43U)   /* Big endian float32 type signal funcid. */
#define COM_BIG_ENDIAN_FLOAT64_FUNCID                  (44U)   /* Big endian float64 type signal funcid. */

#define COM_LITTLE_ENDIAN_UINT8_START_FUNCID           (45U)   /* Little endian uint8 type signal start funcid. */
#define COM_LITTLE_ENDIAN_UINT8_END_FUNCID             (49U)   /* Little endian uint8 type signal end funcid. */

#define COM_LITTLE_ENDIAN_UINT16_START_FUNCID          (50U)   /* Little endian uint16 type signal start funcid. */
#define COM_LITTLE_ENDIAN_UINT16_END_FUNCID            (54U)   /* Little endian uint16 type signal end funcid. */

#define COM_LITTLE_ENDIAN_UINT32_START_FUNCID          (55U)   /* Little endian uint32 type signal start funcid. */
#define COM_LITTLE_ENDIAN_UINT32_END_FUNCID            (64U)   /* Little endian uint32 type signal end funcid. */

#define COM_LITTLE_ENDIAN_UINT64_FUNCID                (65U)   /* Little endian uint64 type signal funcid. */

#define COM_LITTLE_ENDIAN_SINT8_START_FUNCID           (66U)   /* Little endian sint8 type signal start funcid. */
#define COM_LITTLE_ENDIAN_SINT8_END_FUNCID             (70U)   /* Little endian sint8 type signal end funcid. */

#define COM_LITTLE_ENDIAN_SINT16_START_FUNCID          (71U)   /* Little endian sint16 type signal start funcid. */
#define COM_LITTLE_ENDIAN_SINT16_END_FUNCID            (75U)   /* Little endian sint16 type signal end funcid. */

#define COM_LITTLE_ENDIAN_SINT32_START_FUNCID          (76U)   /* Little endian sint32 type signal start funcid. */
#define COM_LITTLE_ENDIAN_SINT32_END_FUNCID            (85U)   /* Little endian sint32 type signal end funcid. */

#define COM_LITTLE_ENDIAN_SINT64_FUNCID                (86U)   /* Little endian sint64 type signal funcid. */

#define COM_LITTLE_ENDIAN_FLOAT32_FUNCID               (87U)   /* Little endian float32 type signal funcid. */
#define COM_LITTLE_ENDIAN_FLOAT64_FUNCID               (88U)   /* Little endian float64 type signal funcid. */

#define COM_U8N_FUNCID                                 (89U)   /* Uint8_N type signal funcid. */
#define COM_U8DYN_FUNCID                               (90U)   /* Uint8_DYN type signal start funcid. */

#define COM_SIGNAL_INVALID_NONE                        (0U)
#define COM_SIGNAL_INVALID_NOTIFY                      (1U)
#define COM_SIGNAL_INVALID_REPLACE                     (2U)

#define COM_SIGNAL_TIMEOUT_NONE                        (0U)
#define COM_SIGNAL_TIMEOUT_REPLACE                     (1U)

#define COM_PDU_CLEARUB_TXCFM                          (0U)
#define COM_PDU_CLEARUB_TRANSMIT                       (1U)
#define COM_PDU_CLEARUB_TRIGTRANSMIT                   (2U)

#define COM_PDU_SIGPRCS_DEFERRED                       (0U)
#define COM_PDU_SIGPRCS_IMMEDIATE                      (1U)

#define COM_MAINFUNCTION_CAN                           (0U)
#define COM_MAINFUNCTION_LIN                           (1U)
#define COM_MAINFUNCTION_FR                            (2U)
#define COM_MAINFUNCTION_ETH                           (3U)

#define COM_PDU_TYPE_NORMAL                            (0U)
#define COM_PDU_TYPE_TP                                (1U)

#define COM_RXSIGGRPTYPE_NORMAL                        (0U)
#define COM_RXSIGGRPTYPE_GW                            (1U)
#define COM_RXSIGGRPTYPE_E2E                           (2U)
#define COM_RXSIGGRPTYPE_E2E_GW                        (3U)

#define COMMAINFUNCTION_CAN                            (0U)
#define COMMAINFUNCTION_LIN                            (1U)
#define COMMAINFUNCTION_FR                             (2U)
#define COMMAINFUNCTION_ETH                            (3U)

/* PolySpace +1 MISRA-C3:D1.1 [Justified:Unset] "NSCA_Polyspace_Common_Dir1.1" */
#define COM_INIT_ZERO                                  (0U)
/* PolySpace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Com_2.3" */
typedef uint32 Com_PduGrpVectorType;                          /* AUTOSAR COM PDU Group Vector identifier. */
typedef uint16 Com_IpduGroupIdType;                           /* AUTOSAR COM PDU group object identifier. */

typedef uint16 Com_SigStartBitType;
typedef uint8 Com_SigBitLengthType;
typedef uint16 Com_SigStartByteType;
typedef uint8 Com_SigByteLengthType;
typedef uint8 Com_SigFuncIdType;                               /* Com signal funcId typedef. */


typedef uint8 Com_SigType;
typedef uint8 Com_SigEndianessType;
typedef uint8 Com_SigInvalidAction;
typedef uint8 Com_SigTimeOutAction;
typedef uint8 Com_PduClearUBStaType;
typedef uint8 Com_PduSigProcessType;
/* PolySpace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Com_2.3" */
typedef uint8 Com_MainFunctionType;
typedef uint8 Com_PDUType;

#if( COM_MULTICORE_SUPPORT == STD_ON )
typedef uint16 Com_PduIndexType;
#endif  /* COM_MULTICORE_SUPPORT == STD_ON */

typedef enum
{
    COM_PDU_NORECEIVE = 0x00U,
    COM_PDU_RECEIVED = 0x01U,
    COM_PDU_WAITRECEIVE = 0x02U,
    COM_PDU_RECTIMEOUT = 0x04U,
    COM_PDU_GW_SIG_FLAG = 0x10U,
    COM_PDU_GW_DSCP_FLAG = 0x20U,
    COM_PDU_GW_SIG_DSCP_FLAG = 0x30U,
    COM_PDU_GW_DSCP_HANDLE_FLAG = 0x40U,
} Com_PduReceiveSts;

typedef enum
{
    COM_RXSIG_Received = 1U,
    COM_RXSIG_WatieReceive,
    COM_RXSIG_TimeOut
} Com_SigReceiveSts;

typedef enum
{
    COM_PDU_INACTIVE = 0U,
    COM_PDU_ACTIVE,
    COM_PDU_WAITCONFIRM
} Com_RxPduActSts;

typedef enum
{
    COM_TRANS_PENDING = 0U,                                 /* Signal Transfer Type Pending. */
    COM_TRANS_TRIGGERED,                                    /* Signal Transfer Type Triggered. */
    COM_TRANS_TRIGGERED_ON_CHG,                             /* Signal Transfer Type Triggered When Data Changed. */
    COM_TRANS_TRIGGERED_ON_CHG_WR,                          /* Signal Transfer Type Triggered Without Repetition When Data Changed. */
    COM_TRANS_TRIGGERED_WR,                                 /* Signal Transfer Type Triggered Without Repetition. */
    COM_TRANS_PASSIVE,                                      /* Signal Transfer Type Passive */
    COM_TRANS_TRIGGERED_ON_IF_ACTIVE                        /* Signal Transfer Type Triggered if data active */
} Com_SigTransferPropertyType;

typedef enum
{
    COM_SIG_SENDSTA_NOSET = 0U,                             /* Signal send state:NO Set. */
    COM_SIG_SENDSTA_READY,                                  /* Signal send state:ready. */
    COM_SIG_SENDSTA_WAITGRP                                 /* Signal send state:wairt group set. */
} Com_SigSendStaType;

typedef enum
{
    COM_SIG_RECEIVESTA_NOSET = 0U,                           /* Signal send state:NO Set. */
    COM_SIG_RECEIVESTA_READY,                                /* Signal send state:ready. */
    COM_SIG_RECEIVESTA_WAITGRP                               /* Signal send state:wairt group set. */
    /* PolySpace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Com_2.3" */
} Com_SigReceiveStaType;

typedef enum
{
    COM_PDU_STA_INACTIVE = 0U,                              /* Pdu Inactive. */
    COM_PDU_STA_ACTIVE,                                     /* Pdu active. */
    COM_PDU_STA_WAITCONFIRM,                                /* Pdu wait confirmation. */
    COM_PDU_STA_CONFIRM,                                    /* Pdu confirmation. */
    COM_PDU_STA_TIMEOUT                                     /* Pdu time out for confirmation. */
} Com_PduTxStaType;

typedef enum
{
    COM_PDU_TRIG_INACTIVE = 0U,                             /* Pdu trigger Inactive. */
    COM_PDU_TRIG_ACTIVE,                                    /* Pdu trigger active. */
    COM_PDU_TRIG_ACTIVE_WP,                                 /* Pdu trigger active without repetition. */
    COM_PDU_TRIG_PROCESSING
} Com_PduTriggerStaType;

typedef enum
{
    COM_PDU_TPCONNECTION_NO = 0U,
    COM_PDU_TPCONNECTION_YES
} Com_PduTpConnectionType;

typedef enum
{
    COM_FILTER_ALWAYS  = 0U,                                 /* This filter always evaluates to TRUE. */
    COM_FILTER_NEVER ,                                       /* This filter always evaluates to FALSE. */
    COM_FILTER_MASKEDNEWDIFFERSMASKEDOLD,                    /* MaskedNewDiffersMaskedOld: ((new & mask) != (old & mask)). */
    COM_FILTER_MASKEDNEWEQUALSX,                             /* MaskedNewEqualsX:  ((new & mask) == x). */
    COM_FILTER_MASKEDNEWDIFFERSX,                            /* MaskedNewDiffersX:  ((new & mask) != x). */
    COM_FILTER_NEWISOUTSIDE,                                 /* NewIsOutside: ((new < min) || (max < new)). */
    COM_FILTER_NEWISWITHIN,                                  /* NewIsWithin: ((min <= new) && (new <= max)). */
    COM_ONE_EVERY_N                                          /* OneEveryN occurrence % period == offset occurrences. */
} Com_SignalFilterType;

typedef enum
{
    COM_SIG_ENDIANTYPE_MOTOROLA = 0U,
    COM_SIG_ENDIANTYPE_INTEL,
    COM_SIG_ENDIANTYPE_OPAQUE
    /* PolySpace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Com_2.3" */
} Com_SigEndianType;

typedef enum
{
    COM_READY_RXTPCONNECTIONSTATE = 0U,
    COM_RECEPTION_STARTED_RXTPCONNECTIONSTATE,
    COM_COPYING_RXTPCONNECTIONSTATE,
    COM_WAITING_FOR_INDICATION_RXTPCONNECTIONSTATE
} Com_RxTpPduConnectSta;

typedef enum
{
    COM_SIGGRP_VALID = 0U,
    COM_SIGGRP_INVALID,
    COM_SIGGRP_FILTERED
    /* PolySpace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Com_2.3" */
} COM_ReceiveDataSta;

#if( COM_TXPDU_MDT_SUPPORT == STD_ON )
typedef enum
{
    COM_MDTFORCYC_INIT = 0U,
    COM_MDTFORCYC_START,
    COM_MDTFORCYC_READY
} Com_MDTForCycType;                                        /* The status of periodic mode Pdu */

typedef enum
{
    COM_MDTFORTRG_INIT = 0U,
    COM_MDTFORTRG_START,
    COM_MDTFORTRG_READY
} Com_MDTForTrgType;                                        /* The status of trigger mode Pdu */
#endif

/* Signal Base Information. */
typedef struct
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.8" */
{
    Com_SigStartByteType sigStartByte;                      /* Signal start byte. */
    Com_SigByteLengthType sigByteLength;                    /* Signal byte length. */
    Com_SigStartBitType sigStartBit;                        /* Signal bit position in byte. */
    Com_SigBitLengthType sigBitLength;                      /* Signal bit length. */
    Com_SigFuncIdType sigFuncIdx;                           /* Signal function id of signal table. */
}Com_SignalBaseInfo_st;

/* Rx Tp Process State. */

/* Signal Filter Monitor Information. */
typedef struct
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.8" */
{
    boolean sigFilterNew;                                   /* A new signal has been received. */
    boolean sigFilterTmc;                                   /* Filter TMC value. */
    uint64 sigFilterOccurrence;                             /* Filter occurrence numbers. */
    void* sigFilterOldValue;                                /* Filter old value. */
} Com_TxSigFilterMonitor_st;

/* Filter Info. */
typedef struct
{
    Com_SignalFilterType  acFilterAlgorithm;                /* Rx Tp Information. */
    sint64 alFilterMask;                                    /* Filter Mask Value. */
    sint64 alFilterMax;                                     /* Filter Max Value. */
    sint64 alFilterMin;                                     /* Filter Min Value. */
    uint64 alFilterOffest;                                  /* Filter Offest. */
    uint64 alFilterPeriod;                                  /* Filter Period. */
    sint64 alFilterX;                                       /* Filter X Value. */
    Com_TxSigFilterMonitor_st *TxSigFilterMonitor;          /* Filter Monitor.  */
    /* PolySpace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Com_2.3" */
} Com_FilterInfoType_st;

typedef struct
{
    uint16 acPduId;                                         /* Signal ID Located Pdu ID. */
    uint16 acSigGrpIdx;                                     /* Signal Group Index. */
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
    Com_SigType sigType;                                    /* Signal Type. */
#endif
#if( COM_TXSIG_NOTIFICATION_SUPPORT == STD_ON )
    void (*Notification_p)(void);                           /* Signal Notification. */
#endif  /* COM_TXSIG_NOTIFICATION_SUPPORT == STD_ON */
#if( COM_TXSIG_ERRNOTIFICATION_SUPPORT == STD_ON )
    void (*ErrorNotification_p)(void);                      /* Error Notification. */
#endif  /* COM_TXSIG_ERRNOTIFICATION_SUPPORT == STD_ON */
#if( COM_TXSIG_TIMEOUTNOTIFICATION_SUPPORT == STD_ON )
    void (*ToNotification_p)(void);                         /* Pdu Timeout Notification. */
#endif  /* COM_TXSIG_TIMEOUTNOTIFICATION_SUPPORT == STD_ON */
    const void* sigInitValue;                               /* Signal Init Value. */
    Com_SigTransferPropertyType sigTransferProperty;        /* Signal Transfer Property. */
#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
    uint16 updateBitSigIndex;                               /* updateBit Sig Index. */
#endif  /* COM_TXUPDATEBITCFG_SUPPORT == STD_ON */
#if( COM_TXSIGNALFILTER_SUPPORTED == STD_ON )
    Com_FilterInfoType_st* sigFilterInfo;                   /* signal fliter monitor. */
#endif  /* COM_TXSIGNALFILTER_SUPPORTED == STD_ON */
    Com_SigSendStaType* sigSendSta;                         /* Signal Send State. */
    void* sigValShadowBufPtr;                               /* Signal Value Shadow Buffer Pointer. */
    void* sigValInvalidBufPtr;
    const void* sigInactiveValue;                           /* Signal inactive value. */
    Com_SignalBaseInfo_st* sigBaseInfo;                     /* Signal Base Information */
} COM_TxSignalInfo_st;

/* Tx Signal Group Information */
typedef struct
{

    uint16 awPduId;                                         /* Pdu Id. */
    Com_SigTransferPropertyType sigTransferProperty;        /* Signal Group Transfer Property. */
#if( COM_SIGNALGROUPARRAY_SUPPORT == STD_ON )
    boolean sigGrpArrayAccess;                              /* Signal Group Array Access Used. */
    uint16 sigGrpStartByte;                                 /* Signal Group Start Byte. */
    uint16 sigGrpEndByte;                                   /* Signal Group End Byte. */
#endif  /* COM_SIGNALGROUPARRAY_SUPPORT == STD_ON */
#if( (COM_TXSIGGROUPINFO == STD_ON) && (COM_TXSIGGRP_ERRNOTIFICATION_SUPPORT == STD_ON) )
    void (*ErrorNotification_p)(void);                      /* Error Notification. */
#endif  /* (COM_TXSIGGROUPINFO == STD_ON) && (COM_TXSIGGRP_ERRNOTIFICATION_SUPPORT == STD_ON) */
#if( (COM_TXSIGGROUPINFO == STD_ON) && (COM_TXSIGGRP_NOTIFICATION_SUPPORT == STD_ON) )
    void  (*Notification_p)(void);                          /* Signal Notification. */
#endif  /* (COM_TXSIGGROUPINFO == STD_ON) && (COM_TXSIGGRP_NOTIFICATION_SUPPORT == STD_ON) */
    uint16 acSigIdxStart;                                   /* Signal Index Start. */
    uint16 acSigIdxdEnd;                                    /* Signal Index End. */
#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
    uint16 updateBitSigIndex;                               /* updateBit Sig Index. */
#endif  /* COM_TXUPDATEBITCFG_SUPPORT == STD_ON */
#if( (COM_TXSIGGROUPINFO == STD_ON) && (COM_TXSIGGRP_TIMEOUT_NOTIFICATION_SUPPORT== STD_ON) )
    void (*ToNotification_p)(void);                         /* Pdu Timeout Notification. */
#endif  /* (COM_TXSIGGROUPINFO == STD_ON) && (COM_TXSIGGRP_TIMEOUT_NOTIFICATION_SUPPORT== STD_ON) */
} COM_TxSigGrpInfo_st;

typedef struct
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.8" */
{
    Com_PduTxStaType pduSta;                                /* Pdu state. */
    boolean pduTxMode;                                      /* Pdu Current Tx Mode. */
    uint16 pduCycCounter;                                   /* Pdu Cycle Time Count. */
    uint16 awPduTxTimeoutCounter;                           /* Pdu Tx Timeout Counter. */
#if( COM_TXPDU_MDT_SUPPORT == STD_ON )
    uint16 pduCycCntForMDT;                                 /* Pdu Cycle Time Counter for MDT. */
    Com_MDTForCycType pduCycMDTState;                       /* Pdu Cycle MDT*/
    boolean CycSendFlag;                                    /* Pdu Cycle Send Flag for MDT */
    boolean pduCycDelayFlag;                                /* Periodic Delayed Transmission Flag */
#endif
    boolean pduGwSendFlag;                                  /* Pdu Gw send Flag. */
    boolean pduGwFlag;                                      /* Pdu Gw Flag for Tx mode ctrl. */
} Com_TxInterMonitor_st;

typedef struct
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.8" */
{
    Com_PduTriggerStaType pduTriggerSta;                    /* Pdu trigger state. */
    uint16 pduTrgCycCounter;                                /* Pdu Cycle Time Counter. */
    uint16 pduSendRemainCnt;                                /* Pdu Send Remain Counter. */
#if( COM_TRIGRESETCYCTIMER_SUPPORT == STD_ON )
    boolean Com_ResetCycTimerFlag;                          /* Pdu cycle time counter reset flag */
#endif
#if( COM_TXPDU_MDT_SUPPORT == STD_ON )
    uint16 pduTrgCycCntForMDT;                              /* Pdu Trigger Cycle Time Counter for MDT. */
    Com_MDTForTrgType pduTrgMDTState;                       /* Pdu Trigger MDT */
    boolean TriggerSendFlag;                                /* Pdu Trigger Send Flag for MDT */
    boolean pduTriggerDelayFlag;                            /* Trigger Delayed Transmission Flag */
#endif
} Com_PduTriggerMonitorType;

typedef struct
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.8" */
{
    uint16 pduRemainLen;                                    /* Pdu Remain length. */
    Com_PduTpConnectionType pduTpConnection;                /* Pdu trigger state. */
    Com_RxTpPduConnectSta TpConnectStatus;                  /* pdu rx tp connectstatus. */
    PduLengthType tpLength;                                 /* Rx Tp Received Length. */
    PduLengthType writtenBytesCounter;                      /* Written Bytes Counter. */
} Com_PduTpMonitorType;

typedef struct
{
    boolean triggerMetaDataEnable;                          /* MetaData  */
    boolean tpBusy;                                         /* TP busy or idle. */
    const uint8 *defaultMetaData;                           /* ComMetaDataDefault. */
    uint8 *tpMetaData;                                      /* The Tp of I-PDU is currently locked, store the given MetaData. */
    /* PolySpace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Com_2.3" */
} Com_PduMetaDataMonitorType;

/* Tx Pdu Information */
typedef struct
{
#if( (COM_TXPDU_TRIGGERCALLOUT_SUPPORT == STD_ON) || (COM_TXUPDATEBITCFG_SUPPORT == STD_ON) )
    uint16 acPduID;                                         /* Pdu ID. */
#endif  /* (COM_TXPDU_TRIGGERCALLOUT_SUPPORT == STD_ON) || (COM_TXUPDATEBITCFG_SUPPORT == STD_ON) */
#if( (COM_METADATA_SUPPORT == STD_ON) && (COM_TXMETADATA_NUM > COM_INIT_ZERO) )
    uint8 acMetaDataLength;                                 /* Meta Data Length. */
    uint16 acMetaDataIdx;                                   /* Meta Data Index. */
#endif  /* (COM_METADATA_SUPPORT == STD_ON) && (COM_TXMETADATA_NUM > COM_INIT_ZERO) */
    uint16 acPduLenth;                                      /* Pdu Length. */
#if( COM_TXPDU_MDT_SUPPORT== STD_ON )
    uint16 acMinimumDelayTime;                              /* MDT */
#endif  /* COM_TXPDU_MDT_SUPPORT == STD_ON */
#if( COM_TXUPDATEBITCFG_SUPPORT == STD_ON )
    Com_PduClearUBStaType acPduClearUpdateBit;              /* Clear UpdateBit Type. */
#endif  /* COM_TXUPDATEBITCFG_SUPPORT == STD_ON */
    uint8 acPduActiveType;                                  /* Pdu is always active or active by Com_IpduGroupControl. */
    Com_TxInterMonitor_st* astPduInterMonitor;              /* Pdu Inter Moniter Use data. */
    Com_PduTriggerMonitorType* pduTriggerMonitor;           /* Pdu trigger Moniter Use data. */
    Com_PduTpMonitorType* pduTpMonitor;                     /* Pdu Tp Moniter Use data. */
    uint16 acTxModeIndex;                                   /* Pdu MsgTxModeIndex. */
    uint16 acPduGrpVectorStartIdx;                          /* Pdu Located in Pdu Group Vector Start Index. */
    uint16 acpduGrpVectorEndIdx;                            /* Pdu Located in Pdu Group Vector End Index. */
    uint16 acSigGrpStartIndex;                              /* Pdu Signal Group Start Index. */
    uint16 acSigGrpEndIndex;                                /* Pdu Signal Group End Index. */
    uint16 awSigStartIndex;                                 /* Pdu Signal Start Index. */
    uint16 awSigEndIndex;                                   /* Pdu Signal End Index. */
    Com_PduSigProcessType acSignalProcessType;              /* Signal Defer Process Type. */
    uint8 *dataRaw;                                         /* pointer to dataraw. */
#if( COM_TXPDU_TRIGGERCALLOUT_SUPPORT == STD_ON )
    boolean (*TriggerCallout)(PduIdType PduId, PduInfoType* PduInfoPtr); /* Call out Function. */
#endif  /* COM_TXPDU_TRIGGERCALLOUT_SUPPORT == STD_ON */
    uint16 lowLayerPduID;                                   /* low layer Pdu ID */
    uint16 pduTimeoutCnt;                                   /* Pdu timeout counter. */
#if( COM_MULTICORE_SUPPORT == STD_ON )
    uint32 coreId;                                          /* Core corresponding to pdu. */
    Com_MainFunctionType mainFunction;                      /* Core corresponding to main Function.*/
#endif  /* COM_MULTICORE_SUPPORT == STD_ON */
} COM_TxPduInfo_st;

/* Tx Mode Information */
typedef struct
{
    boolean acTxModeUsed;                                   /* Tx Mode Used True or False. */
    uint16 acTxModeFalseIdx;                                /* Tx Mode False Behavior Index. */
    uint16 acTxModeTrueIdx;                                 /* Tx Mode True Behavior Index. */
    uint8 unusedAreasDefault;
} COM_TxModeInfo_st;

/* Tx Mode Mode Information */
typedef struct
{
    uint8 acTxMode;                                         /* Tx Mode (Direct/Periodic/Mix/None). */
    uint8 acTxModeRepet;                                    /* Tx Mode Number Of Repetitions. */
    uint16 acTxModeRepetPeriod;                             /* Tx Mode Repetition Period. */
    uint16 acTxModeOffset;                                  /* Tx Mode Time Offset. */
    uint16 acTxCycle;                                       /* Tx Mode Time Period. */
    uint16 acTxCycleFast;                                   /* Tx Mode Time Period Fast. */
} Com_TxMode_st;

/* Rx Pdu Information */
typedef struct
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.8" */
{
    uint8 acPduLength;                                    /* Pdu Received Length. */
    Com_RxPduActSts pduSta;                               /* Pdu Inter ActiveSts. */
    Com_PduReceiveSts acPduRecSts;                         /* Pdu Receive Status. */
    uint16 acPduCycCounter;                               /* Pdu Cycle Time Count. */
    uint16 acPduCycCounterForGw;                          /* Pdu Cycle Time Counter for Gw. */
    uint16 acPduCycCounterForGwInit;                      /* Pdu Cycle Time Counter for Gw. */
    boolean enableDeadline;                               /* Enable I-PDU group Deadline Monitoring. */
    boolean rxTimeout;                                    /* Timeout flag. */
} Com_RxInterMonitor_st;

typedef struct
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.8" */
{
    Com_SigReceiveSts acSignalRecOrSendSts;               /* Signal Received Or Send Sts. */
    uint16 acDynSignalLength;                             /* Dynamic Signal Length. */
    boolean acSignalEnableDeadline;                       /* Enable Signal without update bit Deadline Monitoring */
    boolean acSignalUpdateEnableDeadline;                 /* Enable Signal with update bit Deadline Monitoring */
} Com_RxSignalMonitor_st;

typedef struct
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.8" */
{
    uint16 acSignalGrpCycleCounter;                       /* SignalGroup Cycle Counter. */
    uint8 acSignalGrpRecOrSendSts;                        /* Signal Group Received Sts. */
    uint8 acSignalGrpOldDifferNewFlag;                    /* Signal Group Old Differ New Flag. */
    uint8 acSignalGrpFirstToutSts;
    boolean acSignalGrpEnableDeadline;                    /* Enable Signal group without update bit Deadline Monitoring */
    boolean acSignalGrpUpdateEnableDeadline;              /* Enable Signal group with update bit Deadline Monitoring */
} Com_SignalGroupMonitor_st;

typedef struct
{

    Com_PDUType acPduType;                                /* Pdu Type. */
    uint8 acPduActiveType;                                /* Pdu is always active or active by Com_IpduGroupControl. */
    PduLengthType acPduLenth;                             /* Pdu Length. */
    Com_RxInterMonitor_st* astPduInterMonitor;            /* Pdu Inter Moniter Use data. */
    uint16 acPduGrpVectorStartIdx;                        /* Pdu Located in Pdu Group Vector Start Index. */
    uint16 acpduGrpVectorEndIdx;                          /* Pdu Located in Pdu Group Vector End Index. */
    uint16 acSigGrpStartIndex;                            /* Signal Group StartIndex. */
    uint16 acSigGrpEndIndex;                              /* Signal Group EndIndex. */
    uint16 awSigStartIndex;                               /* Signal StartIndex. */
    uint16 awSigEndIndex;                                 /* Signal EndIndex. */
    uint8 *datavalid;                                     /* Pointer to datavalid.  */
    Com_PduTpMonitorType* pduTpMonitor;                   /* Pdu Tp Moniter Use data. */
#if( COM_RXPDUCALLOUTINFO == STD_ON )
    boolean (*Callout)(PduIdType PduId, const PduInfoType* PduInfoPtr ); /* Call out Function. */
#endif  /* COM_RXPDUCALLOUTINFO == STD_ON */
    Com_PduSigProcessType acSignalProcessType;            /* Signal Defer Process Type. */
    uint16 sigMinimumTimeout;                             /* signal minimum timeout counter. */
    uint16 sigMinimumFirstTimeout;                        /* signal minimum first timeout counter. */
#if( COM_MULTICORE_SUPPORT == STD_ON )
    Com_MainFunctionType mainFunction;                    /* Core corresponding to main Function.*/
    uint32 coreId;                                        /* Core corresponding to pdu. */
#endif  /* COM_MULTICORE_SUPPORT == STD_ON */
} COM_RxPduInfo_st;

/* Rx Signal Group Information. */
typedef struct
{

    uint16 awPduId;                                       /* SignalGroup Located Pdu Id. */

#if( COM_INVALIDACTION_SUPPORT == STD_ON )
    Com_SigInvalidAction acDataInvalidAction;             /* Data Invalid Action. */
#endif  /* COM_INVALIDACTION_SUPPORT == STD_ON */
    Com_SigTimeOutAction acRxDataTimeoutAction;           /* Rx Data Timeout Action. */
/* PolySpace +1 MISRA-C3:20.9 [Justified:Unset] "NSCA_Polyspace_Com_20.9" */
#if( COM_SIGGRP_RTEGROUP_OPERATE == STD_ON )
    void* acSigGrpValue;                                  /* Pointer to Signal Group data. */
#endif  /* COM_SIGGRP_RTEGROUP_OPERATE == STD_ON */
#if( COM_RXSIGGRP_ERRORNOTIFICATION_SUPPORT == STD_ON )
    void (*ErrorNotification)(void);                      /* Error Notification. */
#endif  /* COM_RXSIGGRP_ERRORNOTIFICATION_SUPPORT == STD_ON */
#if( COM_RXSIGGRP_NOTIFICATION_SUPPORT == STD_ON )
    void (*Notification_p)(void);                         /* Notification. */
#endif  /* COM_RXSIGGRP_NOTIFICATION_SUPPORT == STD_ON */
#if( COM_RXSIGGRP_INVALIDNOTIFICATION_SUPPORT == STD_ON )
    void (*InvalidNotification_p)(void);                  /* Invalid Notification. */
#endif  /* COM_RXSIGGRP_INVALIDNOTIFICATION_SUPPORT == STD_ON */
#if( COM_RXSIGGRP_TIMEOUTNOTIFICATION_SUPPORT == STD_ON )
    void (*TimeoutNotification_p)(void);                  /* Timeout Notification. */
#endif  /* COM_RXSIGGRP_TIMEOUTNOTIFICATION_SUPPORT == STD_ON */
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint16 acFirstTimeout;                                /* First Timeout. */
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */
    uint16 acSigIndStart;                                 /* Signal Index Start. */
    uint16 acSigIndEnd;                                   /* Signal Index End. */
    Com_SignalGroupMonitor_st* astSignalGrpInterMonitor;  /* Signal Group Inter Moniter Use data. */
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint16 updateBitPosition;                             /* Update bit Position. */
    uint16 rxTimeOut;                                     /* Timeout. */
    void* updateCnt;                                      /* update counter.  */
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */
#if( COM_SIGNALGROUPARRAY_SUPPORT == STD_ON )
    uint16 sigGrpStartByte;                               /* Signal Group Start Byte. */
    uint16 sigGrpEndByte;                                 /* Signal Group End Byte. */
      boolean sigGrpArrayAccess;                            /* Signal Group Array Access Used. */
#endif  /* COM_SIGNALGROUPARRAY_SUPPORT == STD_ON */
#if (COM_PERFOPTMZ_SUPPORT == STD_ON)
    uint8 sigGrpType;
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */
    uint8* receiveDataSta;                                 /* Signal Group Array Access Used. */
} COM_RxSigGrpInfo_st;

typedef struct
{
    uint16 acPduID;                                       /* Signal ID Located PDU ID. */
    uint16 acSigGrpIdx;                                   /* Signal Group Index. */
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
    Com_SigType  acSigType;                               /* Signal Type. */
#endif
#if( COM_RXSIG_INVALIDNOTIFICATION_SUPPORT == STD_ON )
    void (*InvalidNotification_p)(void);                  /* Signal Invalid Notification. */
#endif  /* COM_RXSIG_INVALIDNOTIFICATION_SUPPORT == STD_ON */
#if( COM_RXSIG_ERRNOTIFICATION_SUPPORT == STD_ON )
    void (*ErrorNotification)(void);                      /* Signal Error Notification. */
#endif  /* COM_RXSIG_ERRNOTIFICATION_SUPPORT == STD_ON */
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint16 rxTimeOut;                                     /* Signal Timeout. */
    uint16 acRxFirstTimeout;                              /* Signal First Timeout. */
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */
#if( COM_RXSIG_TIMEOUTNOTIFICATION_SUPPORT  == STD_ON )
    void (*TimeOutNotification_p)(void);                  /* Signal TimeOutNotification. */
#endif  /* COM_RXSIG_TIMEOUTNOTIFICATION_SUPPORT == STD_ON */
#if( COM_RXSIG_NOTIFICATION_SUPPORT == STD_ON )
    void (*Notification_p)(void);                         /* Signal Notification. */
#endif  /* COM_RXSIG_NOTIFICATION_SUPPORT == STD_ON */
    void* initvalue;                                      /* Signal Init Value. */
#if( (COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON) || (COM_INVALIDACTION_SUPPORT == STD_ON) )
    void* invalidValue;                                   /* Signal Invalid Value. */
#endif  /* (COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON) || (COM_INVALIDACTION_SUPPORT == STD_ON) */
    Com_RxSignalMonitor_st* astSignalInterMonitor;        /* Pdu Inter Moniter Use data. */
#if( COM_RXSIGFILTERINFO == STD_ON )
    Com_FilterInfoType_st* signalFilterMonitor;           /* signal fliter monitor. */
#endif  /* COM_RXSIGFILTERINFO == STD_ON */
#if( COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON )
    Com_SigInvalidAction acInvalidAction;                 /* Signal Invalid Action Type. */
#endif  /* COM_RXSIGINVLAIDACTION_SUPPORT == STD_ON */
#if( (COM_RXREPLACESIGOFRXTIMEOUTINFO == STD_ON) || (COM_RXUPDATEBITCFG_SUPPORT == STD_ON) )
    Com_SigTimeOutAction acRxTimeOutAction;               /* Signal TimeOut Action Type. */
#endif  /* (COM_RXREPLACESIGOFRXTIMEOUTINFO == STD_ON) || (COM_RXUPDATEBITCFG_SUPPORT == STD_ON) */
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    uint16 updateBitPosition;
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */
    void* sigRTEValue;
    void* sigShadowValue;
#if( COM_RXUPDATEBITCFG_SUPPORT == STD_ON )
    void* updateCnt;
#endif  /* COM_RXUPDATEBITCFG_SUPPORT == STD_ON */
#if( (COM_RXREPLACESIGGROUPOFRXTIMEOUTINFO == STD_ON) || (COM_RXUPDATEBITCFG_SUPPORT == STD_ON) || \
     (COM_RXREPLACESIGOFRXTIMEOUTINFO == STD_ON) )
    void* rxToReplaceValue;
#endif  /* (COM_RXREPLACESIGGROUPOFRXTIMEOUTINFO == STD_ON) || (COM_RXUPDATEBITCFG_SUPPORT == STD_ON) */
    Com_SignalBaseInfo_st* sigBaseInfo;                   /* Signal Base Information */
} COM_RxSignalInfo_st;

typedef struct
{
    uint16 srcSigId;                                      /* source signal Id. */
    uint16 srcSigGrpId;                                   /* source signal group Id */
    uint16 destSigOrGrpNum;                               /* destination signal or signal group Num. */
    const uint16* destSigIdPtr;                           /* destination signal Id array pointer. */
    const uint16* destSigGrpIdPtr;                        /* destination signal group Id array pointer. */
} Com_GwMappingSigType;

typedef struct
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.8" */
{
    uint16 destPduId;                                     /* destination pdu Id. */
    Com_SigStartBitType destBitPos;                       /* Signal Bit Position. */
    Com_SigBitLengthType destBitSize;                     /* Signal Bit Size. */
    Com_SigStartByteType destSigStartByte;                /* Signal Start Byte. */
    Com_SigByteLengthType destSigByteLength;              /* Signal Byte Length. */
    Com_SigFuncIdType destSigFuncIdx;                            /* Signal function id of signal table. */
    Com_SigTransferPropertyType sigTransferProperty;      /* Signal Transfer Property. */
    uint16 updateBitPosition;                             /* ComUpdateBitPosition */
    void* sigInitValue;                                   /* ComSignalInitValue */
} Com_GwSigDscpDestType;

typedef struct
{
    uint16 srcPduId;                                      /* source pdu Id. */
    Com_SigStartBitType srcBitPos;                        /* Signal Bit Position. */
    Com_SigBitLengthType srcBitSize;                      /* Signal Bit Size. */
    Com_SigStartByteType srcSigStartByte;                 /* Signal Start Byte. */
    Com_SigByteLengthType srcSigByteLength;               /* Signal Byte Length. */
    Com_SigFuncIdType srcSigFuncIdx;                      /* Signal function id of signal table. */
    uint16 sigLength;                                     /* Signal Length for UINT8_N and UINT8_DYN. */
    uint16 updateBitPosition;                             /* ComUpdateBitPosition */
    uint16 destSigDscpNum;                                /* destination signal Num. */
    const Com_GwSigDscpDestType* destSigDscpPtr;
    uint16 srcTimeOut;                                    /* src pdu timeout. */
} Com_GwMappingSigDscpType;

#if( COM_MULTICORE_SUPPORT == STD_ON )
typedef struct
{
    uint16 pduNum;                                        /* pdu number which belongs to core and sub mainfunction*/
    Com_PduIndexType* pduIndex;                           /* pdu index */
}Com_PduIndexInfo_st;
#endif  /* COM_MULTICORE_SUPPORT == STD_ON */

/* The Rx Pdu Information Table. */
typedef struct
{
    const uint16* pduRxInfo;                              /* Index of Com_RxPduInfo */
    uint16 pduNum;                                        /* Total number of Rx Pdus with the same time period. */
}Com_RxPduInfoTableType;

/* PolySpace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Com_2.4" */
typedef struct Com_TxPduInfoTableType_st
{
    const uint16* pduTxInfo;                              /* index of Com_TxPduInfo */
    uint16 pduNum;                                        /* total number of tx Pdus which have the same Tx time period. */
} Com_TxPduInfoTableType;

/* PolySpace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Com_2.4" */
typedef struct Com_GatewayInfoTableType_st
{
    const uint16* gwInfoIndexTable;                       /* index of Com_GwInfo */
    const uint16* gwDscpInfoIndexTable;                   /* index of Com_GwDscpInfo */
    uint16 gwInfoNum;                                     /* total number of gwInfoIndex */
    uint16 gwDscpInfoNum;                                 /* total number of gwDscpInfo */
} Com_GatewayInfoTableType;

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

#endif  /* COM_TYPES_H_ */

