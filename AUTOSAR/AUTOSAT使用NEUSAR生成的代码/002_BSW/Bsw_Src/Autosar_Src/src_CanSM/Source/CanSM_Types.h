/*
********************************************************************************
*
* File name: CanSM_Types.h
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
* Cause: updata to V2.0.
********************************************************************************
* Version: 2.1
* Author/Date: WangCong/2019.10.12
* Change: Modify code format.
* Cause: Unified format.
********************************************************************************
* Version: 3.0
* Author/Date: WangCong/2020.01.19
* Change: Synchronizing code with the DF project(Debugging completed).
* Cause: updata to V3.0.
********************************************************************************
* Version: 3.1
* Author/Date: WangCong/2020.03.25
* Change: Modify header file reference.
* Cause: Clear QAC warning.
********************************************************************************
* Version: 3.2
* Author/Date: WangCong/2020.05.12
* Change: Modify the code specification.
* Cause: Optimize
********************************************************************************
* Version: 3.3
* Author/Date: WangC/2020.10.23
* Change: Modify the function name according to the AUTOSAR specification, add
*         MemMap.
* Cause: Optimize
********************************************************************************
* Version: 3.4
* Author/Date: LiuHJ/2021.2.24
* Change: Add mode request timeout in sub state of CANSM_BSM_WUVALIDATION and
*         CANSM_BSM_S_FULLCOM according to AutoSar4.4
* Cause: Optimize
********************************************************************************
* Version: 3.5
* Author/Date: LiuHJ/2021.5.28
* Change: Add service id of the interface CheckBorLevel.
* Cause: Customized requirements
********************************************************************************
* Version: 3.15
* Author/Date: LiuHJ/2021.7.15
* Change: Modify the name of function/macros/service ID which are used to provide
*         internal bus-off recovery level.
* Cause: Optimize
********************************************************************************
* Version: 3.16
* Author/Date: LiuHJ/2021.10.28
* Change: Modify header file reference.
* Cause: Optimization
********************************************************************************
* Version: 3.17
* Author/Date: XieYN/2022.10.19
* Change: Merge the addition of type related to PRE_NOCOM from Q3.
* Cause: Add Function.
********************************************************************************
* Version: 3.18
* Author/Date: XieYN/2022.10.19
* Change: 1. Merge the addition of type CanSM_BsmTrg_ClrWUFType and
*            CanSM_BsmTrg_ChkWFType.
*         2. Merge Trg_ClearWUF_Indication and Trg_CheckWF_Indication in
*            CanSM_BsmChnType.
* Cause: Bugfix
********************************************************************************
* Version: 3.19
* Author/Date: LiX/2023.5.15
* Change: Add the sub-state machine PRE_FULLCOM.
* Cause: Add Function.
********************************************************************************
* Version: 3.19
* Author/Date: TianG/2023.6.28
* Change: Change u to U.
* Cause: Optimize
********************************************************************************
* Version: 3.20
* Author/Date: TianL/2024.1.30
* Change: 1.Add the sub-state CANSM_S_CBR_STOP_CC_WAIT in CanSM_Bsm_Sub_CHANGEBRType.
*         2.Add the repeatCount in CanSM_BsmChnType.
* Cause: Optimize
********************************************************************************
* Version: 3.21
* Author/Date: TianL/2024.2.1
* Change: Add the changeBRIdRequest in CanSM_BsmChnType.
* Cause: Optimize
********************************************************************************
* Version: 3.22
* Author/Date: TianL/2024.3.20
* Change: Add the sub-state machine SILENTCOM_BOR.
* Cause: Add Function.
********************************************************************************
* Version: 3.23
* Author/Date: TianL/2024.4.1
* Change: 1.Add comments to the enum.
*         2.Modify the type of a struct member.
* Cause: Optimize
********************************************************************************
* Version: 3.24
* Author/Date: TianL/2024.05.15
* Change: Modify coding specifications.
* Cause: Optimization
********************************************************************************
* Version: 3.25
* Author/Date: TianL/2024.8.5
* Change: Modify copyright information.
* Cause: Update
********************************************************************************
* Version: 3.26
* Author/Date: TianL/2024.9.14
* Change: Add CanSM_Bsm_Sub_TXTIMEOUTEXCEPTIONtype.
* Cause: Optimize
********************************************************************************
* Version: 3.26
* Author/Date: TianL/2025.3.27
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Optimize
********************************************************************************
* Version: 3.27
* Author/Date: TianL/2025.6.8
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef CANSM_TYPES_H_
#define CANSM_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "CanIf.h"
#include "CanSM_Cfg.h"
#include "Rte_CanIf_Type.h"//DQ

/* For Type: ComM_ModeType  */
#include "ComM.h"

/* For Type: Dem_EventIdType */
#if( CANSM_REPORT_DEM_ENABLE == STD_ON )
#include "Dem.h"
#endif  /* CANSM_REPORT_DEM_ENABLE ==STD_ON */

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define CANSM_VALUE_ZERO                        (0U)
#define CANSM_VALUE_ONE                         (1U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CANSM_INSTANCE_ID_DET                   (0U)

#define CANSM_E_NO_ERR                          (0x00U)

#define CANSM_E_UNINIT                          (0x01U)
#define CANSM_E_PARAM_POINTER                   (0x02U)
#define CANSM_E_INVALID_NETWORK_HANDLE          (0x03U)
#define CANSM_E_PARAM_CONTROLLER                (0x04U)
#define CANSM_E_PARAM_TRANSCEIVER               (0x05U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CANSM_E_WAIT_MODE_INDICATION            (0x07U)
#define CANSM_E_INVALID_COMM_REQUEST            (0x08U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CANSM_E_MODE_REQUEST_TIMEOUT            (0x0AU)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CANSM_E_INIT_FAILED_CTRLID              (0x10U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CANSM_E_INIT_FAILED_TRCVID              (0x11U)

/* polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_CanSM_Rule17.8" polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define CANSM_DUMMY_STATEMENT(v)                (v)=(v)

/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CANSM_SERVICEID_INIT                    (0x00U)
#define CANSM_SERVICEID_REQUESTCOMMODE          (0x02U)
#define CANSM_SERVICEID_GETCURCOMMODE           (0x03U)
#define CANSM_SERVICEID_STARTWKUPSOURCE         (0x11U)
#define CANSM_SERVICEID_STOPWKUPSOURCE          (0x12U)
#define CANSM_SERVICEID_GETVERSIONINFO          (0x01U)
#define CANSM_SERVICEID_SETBAUDRATE             (0x0DU)
#define CANSM_SERVICEID_SETICOMCFG              (0x0FU)
#define CANSM_SERVICEID_SETECUPASSIVE           (0x13U)
#define CANSM_SERVICEID_CTRLBUSOFF              (0x04U)
#define CANSM_SERVICEID_CTRLMODEINDC            (0x07U)
#define CANSM_SERVICEID_TRCVMODEINDC            (0x09U)
#define CANSM_SERVICEID_TXTIMEOUTEXC            (0x0BU)
#define CANSM_SERVICEID_CLEARTRCVWUFLAGINDC     (0x08U)
#define CANSM_SERVICEID_CLECKTRCVWKFLAGINDC     (0x0AU)
#define CANSM_SERVICEID_CFMPNAVAILABLILITY      (0x06U)
#define CANSM_SERVICEID_CURICOMCFG              (0x10U)
#define CANSM_SERVICEID_MAINFUNCTION            (0x05U)
#define CANSM_SERVICEID_GETBORLEVEL             (0x40U)

/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CANSM_NO_BUSOFFEVENTID                  (0U)
#define CANSM_NO_CHANGE_BR_REQ                  (0xFFFF)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.8" */
{
    uint8 ConfigType;                                  /* ConfigType */
}CanSM_ConfigType;

typedef enum
{
    CANSM_UNINITED = 0U,                               /* CanSM uninitialized. */
    CANSM_INITED                                       /* CanSM initialized. */
} CanSM_StateType;

typedef enum
{
    CANSM_BSM_S_NOT_INITIALIZED = 0U,                  /* Sub state machine: CANSM_BSM_S_NOT_INITIALIZED */
    CANSM_BSM_S_PRE_NOCOM,                             /* Sub state machine: CANSM_BSM_S_PRE_NOCOM */
    CANSM_BSM_WUVALIDATION,                            /* Sub state machine: CANSM_BSM_WUVALIDATION */
    CANSM_BSM_S_PRE_FULLCOM,                           /* Sub state machine: CANSM_BSM_S_PRE_FULLCOM */
    CANSM_BSM_S_FULLCOM,                               /* Sub state machine: CANSM_BSM_S_FULLCOM */
    CANSM_BSM_S_CHANGE_BAUDRATE,                       /* Sub state machine: CANSM_BSM_S_CHANGE_BAUDRATE */
    CANSM_BSM_S_SILENTCOM,                             /* Sub state machine: CANSM_BSM_S_SILENTCOM */
    CANSM_BSM_S_SILENTCOM_BOR,                         /* Sub state machine: CANSM_BSM_S_SILENTCOM_BOR */
    CANSM_BSM_S_NOCOM                                  /* Sub state machine: CANSM_BSM_S_NOCOM */
} CanSM_BsmStaType;

typedef enum
{
    CANSM_T_STOP_WAKEUP_SOURCE = 0U,                   /* Stop the wake-up source. */
    CANSM_T_START_WAKEUP_SOURCE                        /* Start the wake-up source. */
} CanSM_BsmTrg_WAKEUP_SOURCEType;

typedef enum
{
    CANSM_T_NOT_BUS_OFF = 0U,                          /* T_NOT_BUS_OFF */
    CANSM_T_BUS_OFF                                    /* T_BUS_OFF */
} CanSM_BsmTrg_BUS_OFFType;

typedef enum
{
    CANSM_T_NOT_TXTIMEOUT = 0U,                        /* T_NOT_TXTIMEOUT */
    CANSM_T_TXTIMEOUT                                  /* T_TXTIMEOUT */
} CanSM_BsmTrg_TxTimeoutType;

typedef enum
{
    CANSM_T_NOT_CHANGE_BR_REQUEST = 0U,                /* No change baudrate request. */
    CANSM_T_CHANGE_BR_REQUEST                          /* Change the baudrate request. */
} CanSM_BsmTrg_ChangeBRReqType;

typedef enum
{
    CANSM_T_TRCV_NO_IDC = 0U,                          /* T_TRCV_NO_IDC */
    CANSM_T_TRCV_NORMAL_IDC,                           /* T_TRCV_NORMAL_IDC */
    CANSM_T_TRCV_STANDBY_IDC,                          /* T_TRCV_STANDBY_IDC */
    CANSM_T_TRCV_SLEEP_IDC                             /* T_TRCV_SLEEP_IDC */
} CanSM_BsmTrg_TrcvModeType;

typedef enum
{
    CANSM_T_CLEAR_WUF_NO_IDC = 0U,                     /* T_CLEAR_WUF_NO_IDC */
    CANSM_T_CLEAR_WUF_INDICATED                        /* T_CLEAR_WUF_INDICATED */
} CanSM_BsmTrg_ClrWUFType;

typedef enum
{
    CANSM_T_CHECK_WFLAG_NO_IDC = 0U,                   /* T_CHECK_WFLAG_NO_IDC */
    CANSM_T_CHECK_WFLAG_INDICATED                      /* T_CHECK_WFLAG_INDICATED */
} CanSM_BsmTrg_ChkWFType;

typedef enum
{
    CANSM_S_BUS_OFF_CHECK = 0U,                        /* Sub_FULLCOM state: S_BUS_OFF_CHECK */
    CANSM_S_RESTART_CC,                                /* Sub_FULLCOM state: S_RESTART_CC */
    CANSM_S_RESTART_CC_WAIT,                           /* Sub_FULLCOM state: S_RESTART_CC_WAIT */
    CANSM_S_TX_OFF,                                    /* Sub_FULLCOM state: S_TX_OFF */
    CANSM_S_NO_BUS_OFF,                                /* Sub_FULLCOM state: S_NO_BUS_OFF */
    CANSM_S_TX_TIMEOUT_EXCEPTION                       /* Sub_FULLCOM state: S_TX_TIMEOUT_EXCEPTION */
} CanSM_Bsm_Sub_FULLCOMType;

typedef enum
{
    CANSM_S_SILENTCOM_BOR_RESTART = 0U,                /* Sub_SILENTCOM_BOR state: S_RESTART_CC */
    CANSM_S_SILENTCOM_BOR_RESTART_WAIT                 /* Sub_SILENTCOM_BOR state: S_RESTART_CC_WAIT */
}CanSM_Bsm_Sub_SILENTCOMBORType;

typedef enum
{
    CANSM_T_CC_NO_INDICATED = 0U,                      /* Trigger_ControllerMode: T_CC_NO_INDICATED */
    CANSM_T_CC_STARTED_INDICATED,                      /* Trigger_ControllerMode: T_CC_STARTED_INDICATED */
    CANSM_T_CC_STOPPED_INDICATED,                      /* Trigger_ControllerMode: T_CC_STOPPED_INDICATED */
    CANSM_T_CC_SLEEP_INDICATED                         /* Trigger_ControllerMode: T_CC_SLEEP_INDICATED */
}CanSM_BsmTrg_ControllerModeType;

typedef enum
{
    CANSM_S_WU_TRCV_NORMAL = 0U,                       /* Sub_WUVALIDATION state: S_TRCV_NORMAL */
    CANSM_S_WU_TRCV_NORMAL_WAIT,                       /* Sub_WUVALIDATION state: S_TRCV_NORMAL_WAIT */
    CANSM_S_WU_CC_STOPPED,                             /* Sub_WUVALIDATION state: S_CC_STOPPED */
    CANSM_S_WU_CC_STOPPED_WAIT,                        /* Sub_WUVALIDATION state: S_CC_STOPPED_WAIT */
    CANSM_S_WU_CC_STARTED,                             /* Sub_WUVALIDATION state: S_CC_STARTED */
    CANSM_S_WU_CC_STARTED_WAIT,                        /* Sub_WUVALIDATION state: S_CC_STARTED_WAIT */
    CANSM_S_WU_WAIT_LEAVE                              /* Sub_WUVALIDATION state: S_WAIT_LEAVE */
}CanSM_Bsm_Sub_WUType;

typedef enum
{
    CANSM_S_CBR_STOP_CC = 0U,                          /* Sub_CHANGE_BAUDRATE state: S_CC_STOPPED */
    CANSM_S_CBR_STOP_CC_WAIT,                          /* Sub_CHANGE_BAUDRATE state: S_CC_STOPPED_WAIT */
    CANSM_S_CBR_SYNC,                                  /* Sub_CHANGE_BAUDRATE state: S_CHANGE_BR_SYNC */
    CANSM_S_CBR_START_CC,                              /* Sub_CHANGE_BAUDRATE state: S_CC_STARTED */
    CANSM_S_CBR_START_CC_WAIT                          /* Sub_CHANGE_BAUDRATE state: S_CC_STARTED_WAIT */
}CanSM_Bsm_Sub_CHANGEBRType;

typedef enum
{
    CANSM_S_PNC_CC_STOPPED = 0U,                       /* CANSM_BSM_DeInitPnNotSupported state: S_CC_STOPPED */
    CANSM_S_PNC_CC_STOPPED_WAIT,                       /* CANSM_BSM_DeInitPnNotSupported state: S_CC_STOPPED_WAIT */
    CANSM_S_PNC_CC_SLEEP,                              /* CANSM_BSM_DeInitPnNotSupported state: S_CC_SLEEP */
    CANSM_S_PNC_CC_SLEEP_WAIT,                         /* CANSM_BSM_DeInitPnNotSupported state: S_CC_SLEEP_WAIT */
    CANSM_S_PNC_TRCV_NORMAL,                           /* CANSM_BSM_DeInitPnNotSupported state: S_TRCV_NORMAL */
    CANSM_S_PNC_TRCV_NORMAL_WAIT,                      /* CANSM_BSM_DeInitPnNotSupported state: S_TRCV_NORMAL_WAIT */
    CANSM_S_PNC_TRCV_STANDBY,                          /* CANSM_BSM_DeInitPnNotSupported state: S_TRCV_STANDBY */
    CANSM_S_PNC_TRCV_STANDBY_WAIT,                     /* CANSM_BSM_DeInitPnNotSupported state: S_TRCV_STANDBY_WAIT */
    /* Pn-Supported */
    CANSM_S_PNC_PN_CLEAR_WUF,                          /* CANSM_BSM_DeInitPnSupported state: S_PN_CLEAR_WUF */
    CANSM_S_PNC_PN_CLEAR_WUF_WAIT,                     /* CANSM_BSM_DeInitPnSupported state: S_PN_CLEAR_WUF_WAIT */
    CANSM_S_PNC_PN_CC_STOPPED,                         /* CANSM_BSM_DeInitPnSupported state: S_PN_CC_STOPPED */
    CANSM_S_PNC_PN_CC_STOPPED_WAIT,                    /* CANSM_BSM_DeInitPnSupported state: S_CC_STOPPED_WAIT */
    CANSM_S_PNC_PN_TRCV_NORMAL,                        /* CANSM_BSM_DeInitPnSupported state: S_TRCV_NORMAL */
    CANSM_S_PNC_PN_TRCV_NORMAL_WAIT,                   /* CANSM_BSM_DeInitPnSupported state: S_TRCV_NORMAL_WAIT */
    CANSM_S_PNC_PN_TRCV_STANDBY,                       /* CANSM_BSM_DeInitPnSupported state: S_TRCV_STANDBY */
    CANSM_S_PNC_PN_TRCV_STANDBY_WAIT,                  /* CANSM_BSM_DeInitPnSupported state: S_TRCV_STANDBY_WAIT */
    CANSM_S_PNC_PN_CC_SLEEP,                           /* CANSM_BSM_DeInitPnSupported state: S_CC_SLEEP */
    CANSM_S_PNC_PN_CC_SLEEP_WAIT,                      /* CANSM_BSM_DeInitPnSupported state: S_CC_SLEEP_WAIT */
    CANSM_S_PNC_CHECK_WFLAG_IN_CC_SLEEP,               /* CANSM_BSM_DeInitPnSupported state: S_CHECK_WFLAG_IN_CC_SLEEP */
    CANSM_S_PNC_CHECK_WUF_IN_CC_SLEEP_WAIT,            /* CANSM_BSM_DeInitPnSupported state: S_CHECK_WUF_IN_CC_SLEEP_WAIT */
    CANSM_S_PNC_CHECK_WFLAG_IN_NOT_CC_SLEEP,           /* CANSM_BSM_DeInitPnSupported state: S_CHECK_WFLAG_IN_NOT_CC_SLEEP */
    CANSM_S_PNC_CHECK_WUF_IN_NOT_CC_SLEEP_WAIT         /* CANSM_BSM_DeInitPnSupported state: S_CHECK_WUF_IN_NOT_CC_SLEEP_WAIT */
} CanSM_Bsm_Sub_PRENOCOMType;

typedef enum
{
    CANSM_S_TRCV_NORMAL = 0U,                          /* Sub_PRE_FULLCOM state: S_TRCV_NORMAL */
    CANSM_S_TRCV_NORMAL_WAIT,                          /* Sub_PRE_FULLCOM state: S_TRCV_NORMAL_WAIT */
    CANSM_S_CC_STOPPED,                                /* Sub_PRE_FULLCOM state: S_CC_STOPPED */
    CANSM_S_CC_STOPPED_WAIT,                           /* Sub_PRE_FULLCOM state: S_CC_STOPPED_WAIT */
    CANSM_S_CC_STARTED,                                /* Sub_PRE_FULLCOM state: S_CC_STARTED */
    CANSM_S_CC_STARTED_WAIT                            /* Sub_PRE_FULLCOM state: S_CC_STARTED_WAIT */
} CanSM_Bsm_Sub_PREFULLCOMType;

typedef enum
{
    CANSM_TX_TIMEOUT_EXCEPTION_S_CC_STOPPED = 0U,      /* Sub_TX_TIMEOUT_EXCEPTION state: S_CC_STOPPED */
    CANSM_TX_TIMEOUT_EXCEPTION_S_CC_STOPPED_WAIT,      /* Sub_TX_TIMEOUT_EXCEPTION state: S_CC_STOPPED_WAIT */  /* PRQA S 779 */ /* NSCA_QAC_Common_IdentifierLength */
    CANSM_TX_TIMEOUT_EXCEPTION_S_CC_STARTED,           /* Sub_TX_TIMEOUT_EXCEPTION state: S_CC_STARTED */  /* PRQA S 779 */ /* NSCA_QAC_Common_IdentifierLength */
    CANSM_TX_TIMEOUT_EXCEPTION_S_CC_STARTED_WAIT       /* Sub_TX_TIMEOUT_EXCEPTION state: S_CC_STARTED_WAIT */  /* PRQA S 779 */ /* NSCA_QAC_Common_IdentifierLength */
}CanSM_Bsm_Sub_TXTIMEOUTEXCEPTIONtype;

/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct CanSM_ManagerNetworkTypeTag
{
    uint8 ControllerId;                                                  /* CAN Controller Id. */
    boolean TransceiverEnable;                                           /* Define if the CanSMTransceiverId exist. */
    uint8 TransceiverId;                                                 /* CanSMTransceiverId */
    uint8 ComMNetworkHandle;                                             /* CanSMComMNetworkHandleRef */
    boolean BorTxCfmPolling;                                             /* CanSMBorTxConfirmationPolling */
    boolean EnableBusOffDelay;                                           /* CanSMEnableBusOffDelay */
    uint8 BorCounterL1ToL2;                                              /* CanSMBorCounterL1ToL2 */
    uint16 BorTimeL1;                                                    /* CanSMBorTimeL1 */
    uint16 BorTimeL2;                                                    /* CanSMBorTimeL2 */
    uint16 EventId_BUS_OFF;                                              /* CANSM_E_BUS_OFF */
    uint16 borTimeTxEnsured;                                             /* CanSMBorTimeTxEnsured */
    boolean trcvPnEnable;                                                /* ref the configuration parameter CanTrcvPnEnabled in module CanTrcv */
} CanSM_ManagerNetworkType;

/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct CanSM_stBsmSubChnTypeTag
{
    CanSM_Bsm_Sub_WUType BsmSta_Sub_WUVALIDATION;                        /* Sub_WUVALIDATION state machine of the CanSM module */
    CanSM_Bsm_Sub_PRENOCOMType BsmSta_Sub_PRE_NOCOM;                     /* Sub_PRE_NOCOM  state machine of the CanSM module */
    CanSM_Bsm_Sub_PREFULLCOMType BsmSta_Sub_PRE_FULLCOM;                 /* Sub_PRE_FULLCOM state machine of the CanSM module */
    CanSM_Bsm_Sub_FULLCOMType BsmSta_Sub_FULLCOM;                        /* Sub_FULLCOM state machine of the CanSM module */
    CanSM_Bsm_Sub_CHANGEBRType BsmSta_Sub_CHANGE_BAUDRATE;               /* Sub_CHANGE_BAUDRATE state machine of the CanSM module */
    CanSM_Bsm_Sub_SILENTCOMBORType BsmSta_Sub_SILENTCOM_BOR;             /* Sub_SILENTCOM_BOR state machine of the CanSM module */
    CanSM_Bsm_Sub_TXTIMEOUTEXCEPTIONtype BsmSta_Sub_TXTIMEOUTEXCEPTION;  /* Sub state machine of the CANSM_BSM_S_TX_TIMEOUT_EXCEPTION. */
} CanSM_BsmSubChnType;

/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct CanSM_BsmChnTypeTag
{
    CanSM_BsmStaType BsmSta;                                             /* state machine of the CanSM module. */
    CanSM_BsmTrg_WAKEUP_SOURCEType BsmTrg_WAKEUP_SOURCE;                 /* Trigger: T_START_WAKEUP_SOURCE & T_STOP_WAKEUP_SOURCE. */
    ComM_ModeType BsmTrg_MODE_REQUEST;                                   /* Trigger: T_FULL_COM_MODE_REQUEST  & T_NO_COM_MODE_REQUEST. */
    CanSM_BsmTrg_BUS_OFFType BsmTrg_BUS_OFF;                             /* Trigger: T_BUS_OFF. */
    CanIf_PduModeType Bsm_E_CanIfMode;                                   /* Effect: E_PRE_NOCOM & E_NOCOM & E_FULL_COM & E_FULL_TO_SILENT_COM & E_SILENT_TO_FULL_COM. */
    CanSM_BsmTrg_ControllerModeType BsmTrg_ControllerMode;               /* Trigger: T_CC_STOPPED_INDICATED & T_CC_STARTED_INDICATED. */
    CanSM_BsmTrg_TrcvModeType BsmTrg_TransceiverMode;                    /* Trigger: T_TRCV_NORMAL_INDICATED. */
    CanSM_BsmTrg_TxTimeoutType BsmTrg_TxTimeout;                         /* 0:  1: TxTimeout. */
    CanSM_BsmTrg_ChangeBRReqType changeBRIdRequest;                      /* Baudrate modification request. */
    uint16 changeBRId;                                                   /* Trigger: T_CHANGE_BR_REQUEST. */
    CanSM_BsmTrg_ClrWUFType Trg_ClearWUF_Indication;                     /* Trigger: Trg_ClearWUF_Indication. */
    CanSM_BsmTrg_ChkWFType Trg_CheckWF_Indication;                       /* Trigger: Trg_CheckWF_Indication. */
    uint16 Bsm_TaskCycCnt_BUSOFF;                                        /* TaskCyc cnt. */
    uint16 Bsm_RecCnt_BUS_OFF;                                           /* BUS_OFF recovery cnt. */
    uint16 Bsm_RecEnsureCnt_BUS_OFF;                                     /* BUS_OFF recovery ensure cnt. */
    uint16 modeRequestTimeout;                                           /* Timeout of mode request using the API of the CanIf. */
    uint16 repeatCount;                                                  /* Count of repeat the API of the CanIf. */
    CanSM_BsmSubChnType BsmSub;                                          /* Sub state machine of the CanSM module. */
    const CanSM_ManagerNetworkType* ManagerNetworkPtr;                   /* Pointer to CanSM_ManagerNetwork. */
} CanSM_BsmChnType;

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

#endif  /* CANSM_TYPES_H_ */
