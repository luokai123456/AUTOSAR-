/*
********************************************************************************
*
* File name: Dcm_Lcfg.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: Tanlx/20190501
* Change: Autosar
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: Tanlx/20190513
* Change: Autosar
* Cause: Modify format.
********************************************************************************
* Version: 1.2
* Author/Date : Liuziyang/2019.11.22
* Change: The format of code and comment.
* Cause: Modify the code according to the coding specification.
********************************************************************************
* Version: 1.3
* Author/Date : Songqingwei/2020.01.22
* Change: Change the DCM_INVALID_BLOCKID from 0xFFFFFFFF to 0xFFFF.
* Cause: Invalid NvM BlockId is error.
********************************************************************************
* Version: 3.0
* Author/Date : ZhuCY/2021.10.27
* Change: Modify header file name.
* Cause: Optimization.
********************************************************************************
* Version: 3.1
* Author/Date: ZhuCY/2021.10.28
* Change: Modify header file.
* Cause: Optimization.
********************************************************************************
* Version: 3.2
* Author/Date: LQiao/2023.02.06
* Change: Add Struct. Add 38 service. 
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: LQiao/2023.02.13
* Change: Del redundant struct.
* Cause: Optimization
********************************************************************************
*/
#ifndef DCM_LCFG_H_
#define DCM_LCFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Dcm_Cfg.h"
#include "Dcm_Cbk.h"
#include "ComM.h"
#include "ComStack_Types.h"
#include "Mcu.h"
#include "UDS_IF.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

#define DCM_NUM_ZERO                                (0x0U)
/* Polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_MAX_CAN_CHANNEL                         COMM_ACTIVE_CHANNEL
#define DCM_INVALID_BLOCKID                         (0xFFFFU)
/* Polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_NUM_CHECKCOND 	                        (5U)
#define DCM_PHY 			                        (0x01U)
#define DCM_FUN                                     (0x02U)
#define DCM_PHY_FUN                                 (0x03U)
#define DCM_SERVICE_OBD                             (0x00U)
#define DCM_SERVICE_UDS                             (0x01U)

#ifndef DCM_E_GENERALREJECT
#define DCM_E_GENERALREJECT                         (0x10U)
#endif

#ifndef DCM_E_SERVICENOTSUPPORTED
#define DCM_E_SERVICENOTSUPPORTED                   (0x11U)
#endif

#ifndef DCM_E_SUBFUNCTIONNOTSUPPORTED
#define DCM_E_SUBFUNCTIONNOTSUPPORTED               (0x12U)
#endif

#ifndef DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT
#define DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT (0x13U)
#endif

#ifndef DCM_E_RESPONSETOOLONG
#define DCM_E_RESPONSETOOLONG                       (0x14U)
#endif

#ifndef DCM_E_BUSYREPEATREQUEST
#define DCM_E_BUSYREPEATREQUEST                     (0x21U)
#endif

#ifndef DCM_E_CONDITIONSNOTCORRECT
#define DCM_E_CONDITIONSNOTCORRECT                  (0x22U)
#endif

#ifndef DCM_E_REQUESTSEQUENCEERROR
#define DCM_E_REQUESTSEQUENCEERROR                  (0x24U)
#endif

#ifndef DCM_E_NORESPONSEFROMSUBNETCOMPONENT
#define DCM_E_NORESPONSEFROMSUBNETCOMPONENT         (0x25U)
#endif

#ifndef DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION
#define DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION (0x26U)
#endif

#ifndef DCM_E_REQUESTOUTOFRANGE
#define DCM_E_REQUESTOUTOFRANGE                     (0x31U)
#endif

#ifndef DCM_E_SECURITYACCESSDENIED
#define DCM_E_SECURITYACCESSDENIED                  (0x33U)
#endif

#ifndef DCM_E_INVALIDKEY
#define DCM_E_INVALIDKEY                            (0x35U)
#endif

#ifndef DCM_E_EXCEEDNUMBEROFATTEMPTS
#define DCM_E_EXCEEDNUMBEROFATTEMPTS                (0x36U)
#endif

#ifndef DCM_E_REQUIREDTIMEDELAYNOTEXPIRED
#define DCM_E_REQUIREDTIMEDELAYNOTEXPIRED           (0x37U)
#endif

#ifndef DCM_E_UPLOADDOWNLOADNOTACCEPTED
#define DCM_E_UPLOADDOWNLOADNOTACCEPTED             (0x70U)
#endif

#ifndef DCM_E_TRANSFERDATASUSPENDED
#define DCM_E_TRANSFERDATASUSPENDED                 (0x71U)
#endif

#ifndef DCM_E_GENERALPROGRAMMINGFAILURE
#define DCM_E_GENERALPROGRAMMINGFAILURE             (0x72U)
#endif

#ifndef DCM_E_WRONGBLOCKSEQUENCECOUNTER
#define DCM_E_WRONGBLOCKSEQUENCECOUNTER             (0x73U)
#endif

#ifndef DCM_E_REQUESTCORRECTLYRECEIVED_RESPONSEPENDING
#define DCM_E_REQUESTCORRECTLYRECEIVED_RESPONSEPENDING (0x78U)
#endif

#ifndef DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION
#define DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION   (0x7EU)
#endif

#ifndef DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION
#define DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION    (0x7FU)
#endif

#ifndef DCM_E_RPMTOOHIGH
#define DCM_E_RPMTOOHIGH                            (0x81U)
#endif

#ifndef DCM_E_RPMTOOLOW
#define DCM_E_RPMTOOLOW                             (0x82U)
#endif

#ifndef DCM_E_ENGINEISRUNNING
#define DCM_E_ENGINEISRUNNING                       (0x83U)
#endif

#ifndef DCM_E_ENGINEISNOTRUNNING
#define DCM_E_ENGINEISNOTRUNNING                    (0x84U)
#endif

#ifndef DCM_E_ENGINERUNTIMETOOLOW
#define DCM_E_ENGINERUNTIMETOOLOW                   (0x85U)
#endif

#ifndef DCM_E_TEMPERATURETOOHIGH
#define DCM_E_TEMPERATURETOOHIGH                    (0x86U)
#endif

#ifndef DCM_E_TEMPERATURETOOLOW
#define DCM_E_TEMPERATURETOOLOW                     (0x87U)
#endif

#ifndef DCM_E_VEHICLESPEEDTOOHIGH
#define DCM_E_VEHICLESPEEDTOOHIGH                   (0x88U)
#endif

#ifndef DCM_E_VEHICLESPEEDTOOLOW
#define DCM_E_VEHICLESPEEDTOOLOW                    (0x89U)
#endif

#ifndef DCM_E_THROTTLE_PEDALTOOHIGH
#define DCM_E_THROTTLE_PEDALTOOHIGH                 (0x8AU)
#endif

#ifndef DCM_E_THROTTLE_PEDALTOOLOW
#define DCM_E_THROTTLE_PEDALTOOLOW                  (0x8BU)
#endif

#ifndef DCM_E_TRANSMISSIONRANGENOTINNEUTRAL
#define DCM_E_TRANSMISSIONRANGENOTINNEUTRAL         (0x8CU)
#endif

#ifndef DCM_E_TRANSMISSIONRANGENOTINGEAR
#define DCM_E_TRANSMISSIONRANGENOTINGEAR            (0x8DU)
#endif

#ifndef DCM_E_BRAKESWITCH_NOTCLOSED
#define DCM_E_BRAKESWITCH_NOTCLOSED                 (0x8FU)
#endif

#ifndef DCM_E_SHIFTERLEVERNOTINPARK
#define DCM_E_SHIFTERLEVERNOTINPARK                 (0x90U)
#endif

#ifndef DCM_E_TORQUECONVERTERCLUTCHLOCKED
#define DCM_E_TORQUECONVERTERCLUTCHLOCKED           (0x91U)
#endif

#ifndef DCM_E_VOLTAGETOOHIGH
#define DCM_E_VOLTAGETOOHIGH                        (0x92U)
#endif

#ifndef DCM_E_VOLTAGETOOLOW
#define DCM_E_VOLTAGETOOLOW                         (0x93U)
#endif

#ifndef DCM_E_KEYON
#define DCM_E_KEYON                                 (0xF0U)
#endif

#ifndef DCM_E_HVSTATE
#define DCM_E_HVSTATE                               (0xF1U)
#endif

#define DCM_SESSION_DEFAULT_LEVEL                   (0x00U)
#define DCM_SESSION_PROG_LEVEL                      (0x01U)
#define DCM_SESSION_EXTEND_LEVEL                    (0x02U)

#define DCM_DSL_BUFFERRX                            (0x00U)
#define DCM_DSL_BUFFERTX                            (0x01U)
/* Polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_DSL_BUFFERTESTERPRESENT                 (0x02U)

#define DCM_DSL_CHANNEL_NUM                          (0x01U)
#define DCM_READ_BLOCK_NUM                           (0x00U)
#define DCM_MAINTASK_CYCLE                           (10U)
//baoenfei 0x0B->0x0D
#define DCM_NUM_SERVICES                             (0x0DU)
#define DCM_TIMEOUT_S3                               (5000U / DCM_MAINTASK_CYCLE)
#define DCM_DSL_BUFFERNUM                            (0x02U)
#define DCM_DSL_BUFFERLENRX                          (0x0400U)
#define DCM_DSL_BUFFERLENTX                          (0x0400U)
#define DCM_DSL_RESPPENDDING_NUM                     (0x0000U)
#define DCM_SPT_ADDRESSANDLENGTH_FORMAT              (0x0044U)
#define DCM_NUMOFBLOCKSIZE                           (0x0200U)
#define DCM_DSL_PROTOCOL_TX_NUM                      (2U)
// baoenfei for OBD
#define DCM_DSL_PROTOCOL_NUM                         (4U)
#define DCM_DSL_PROTOCOL_TYPE1 (0x01U)
#define DCM_DSL_PROTOCOL_TYPE2 (0x02U)
#define DCM_NUMOFBLOCKSIZE_FILETRANS                 (0x0200U)
#if (STD_ON == DCM_SERVICE_10_ENABLED)
#define DCM_10_SUBID                                 (0x0006U)
#define DCM_P2_TIME_01                               (0x0032U)
#define DCM_P2EX_TIME_01                             (0x07D0U)
#define DCM_P2_TIME_02                               (0x0019U)
#define DCM_P2EX_TIME_02                             (0x07D0U)
#define DCM_P2_TIME_03                               (0x0032U)
#define DCM_P2EX_TIME_03                             (0x07D0U)
#endif
#if (STD_ON == DCM_SERVICE_11_ENABLED)
#define DCM_11_SUBID                                 (0x0004U)
#define DCM_11_BLOCKIDREF                            (0xFFFFU)
#define DCM_11_BLOCKSIZE                             (4U)
#endif
#if (STD_ON == DCM_SERVICE_14_ENABLED)
#define DCM_14_SUBID_NUM                             (0x0000U)
#endif
#if (STD_ON == DCM_SERVICE_27_ENABLED)
/* Polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_27_ATTDELAY_ENABLE                       (STD_ON)
/* Polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_27_ATTEMPT_MONITOR                       (STD_ON)
#define DCM_27_MAX_SEED_LENGTH                       (0x08U)
#define DCM_27_SUB_NUM                               (0x0002U)
#define DCM_27_LEVEL_NUM                             (0x0001U)
#define DCM_2701_MAX_SEED_LENGTH                     (0x08U)
#define DCM_2701_MAX_KEY_LENGTH                      (0x10U)
#define DCM_2701_ATTDELAY                            (0x2710U)
#define DCM_2701_ATTCOUNTER                          (0x03U)
#endif
#if (STD_ON == DCM_SERVICE_28_ENABLED)
#define DCM_28_SUBID_NUM                             (0x0008U)
#define DCM_28_CONTROL_STATE_NUM                     (0x03U)
#define DCM_28_CHANNLE_NUM                           (0x07U)
#endif
#if (STD_ON == DCM_SERVICE_31_ENABLED)
#define DCM_31_SUBID_NUM                             (0x0009U)
#endif
#if (STD_ON == DCM_SERVICE_3E_ENABLED)
#define DCM_3E_SUBID                                 (0x0002U)
#endif
#if (STD_ON == DCM_SERVICE_85_ENABLED)
#define DCM_85_SUBID_NUM                             (0x0004U)
#endif
#if ( (STD_ON == DCM_SERVICE_22_ENABLED) || (STD_ON == DCM_SERVICE_2E_ENABLED) || (STD_ON == DCM_SERVICE_2A_ENABLED) || (STD_ON == DCM_SERVICE_2C_ENABLED) )
#define DCM_22_MAX_DID_LIST_NUM                      (10U)
#define DCM_NUM_DIDS                                 (0xE5U)
#define DCM_RAED_ACESS                               (0x01U)
#define DCM_WRITE_ACESS                              (0x02U)
#define DCM_RAED_AND_WRITE_ACESS                     (0x03U)
#endif /* (STD_ON == DCM_SERVICE_22_ENABLED) || (STD_ON == DCM_SERVICE_2E_ENABLED) || (STD_ON == DCM_SERVICE_2A_ENABLED) || (STD_ON == DCM_SERVICE_2C_ENABLED) */
#define DCM_CANTP_SUPPORT                            (STD_ON)
#define DCM_DSP_READMEMORY_NUM (0x0000U)
#define DCM_DSP_WRITEMEMORY_NUM (0x0000U)

#define DCM_23_WRITTIMEOUT                          (60000U / DCM_MAINTASK_CYCLE)
#define DCM_2E_WRITTIMEOUT                          (20000U / DCM_MAINTASK_CYCLE)
#define DCM_34_WRITTIMEOUT                          (60000U / DCM_MAINTASK_CYCLE)
#define DCM_3D_WRITTIMEOUT                          (60000U / DCM_MAINTASK_CYCLE)
#define DCM_2F_WRITTIMEOUT                          (60000U / DCM_MAINTASK_CYCLE)
#define DCM_31_WRITTIMEOUT                          (60000U / DCM_MAINTASK_CYCLE)
#define DCM_11_WRITTIMEOUT                          (60000U / DCM_MAINTASK_CYCLE)
#define DCM_35_WRITTIMEOUT                          (60000U / DCM_MAINTASK_CYCLE)
#define DCM_27_WRITTIMEOUT                          (1500U / DCM_MAINTASK_CYCLE)
#define DCM_86_WRITTIMEOUT                          (1500U / DCM_MAINTASK_CYCLE)
#define DCM_38_WRITTIMEOUT                          (60000U / DCM_MAINTASK_CYCLE)
#define DCM_37_WRITTIMEOUT                          (60000U / DCM_MAINTASK_CYCLE)
#define DCM_36_WRITTIMEOUT                          (60000U / DCM_MAINTASK_CYCLE)
/* Polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_PROGRM_APPEAR                           (0x01U)
/* Polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_PROGRM_DISAPPEAR                        (0x00U)

#if (STD_ON == DCM_SERVICE_36_ENABLED)
#define DCM_36_PROGRAM_FLASH_NO_FINISH              (0x00U)
#define DCM_36_PROGRAM_FLASH_WAITFINISH             (0x01U)
#endif /* STD_ON == DCM_SERVICE_36_ENABLED */

#if (STD_ON == DCM_SERVICE_37_ENABLED)
#define DCM_37_REQUEST_LENGTH                       (0x00U)
#endif /* STD_ON == DCM_SERVICE_37_ENABLED */

#if ( STD_ON == DCM_SERVICE_01_ENABLED )
#define DCM_01_SUBID                                (8U)
#define DCM_01_SUPPRORTPID (0U)
#endif /* STD_ON == DCM_SERVICE_01_ENABLED */

#if ( STD_ON == DCM_SERVICE_02_ENABLED )
#define DCM_02_SUBID                                (6U)
#define DCM_02_SUPPRORTPID (0U)
#endif /* STD_ON == DCM_SERVICE_02_ENABLED */

#if ( STD_ON == DCM_SERVICE_09_ENABLED )
#define DCM_09_SUBID                                (8U)
#define DCM_09_SUPPRORTPID (1U)
#define OBD_INFOTYPE_MAX_NUM                        (0x06U)
#endif /* STD_ON == DCM_SERVICE_09_ENABLED */

#if (STD_ON == DCM_SERVICE_2C_ENABLED)
#define DCM_2C_SUB_NUM_DIDS                         (3U)
#define DCM_2C_NUM_DIDS (0U)
#endif /* STD_ON == DCM_SERVICE_2C_ENABLED */

#if ( STD_ON == DCM_SERVICE_2A_ENABLED )
#define DCM_2A_TRANSMODE_SIZE                       (3U)
#define DCM_2A_UUDT_TXBUFFER_SIZE                   (8U)
#define DCM_2A_MAX_DID_LIST_NUM                      (1U)
#define DCM_2A_TX_CHANNEL_NUM                        (0U)
#define DCM_2A_NUM_DIDS                              (0U)
#define DCM_2A_SCHEDULER_SIZE                        (1U)
#endif /* STD_ON == DCM_SERVICE_2A_ENABLED */

#if (STD_ON == DCM_SERVICE_86_ENABLED)
#define DCM_86_EVENTTYPE_NUM                        (8U)

#define DCM_86_EVENTWINDOWTIME_NUM                  (0U)
#define DCM_ROE_CLEARED                             (0U)
#define DCM_ROE_STOPPED                             (1U)
#define DCM_ROE_EVENT_WINDOW_INFINITE               (1U)
#define DCM_ROE_EVENT_WINDOW_CURRENT_CYCLE          (2U)
#define DCM_ROE_BLOCKSIZE                           (20U)  /* Polyspace MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
#define DCM_ROE_BLOCKIDREF                          (0xFFFFU)
#define DCM_ROE_BLOCKINVALIDID                      (0xFFFFU)
#define DCM_ROE_INTERMESSAGETIME                    (1U)
#define DCM_86_EEP_EVENTNUM                         ((DCM_ROE_BLOCKSIZE - sizeof(Dcm_86_DslInfo_st))/sizeof(Dcm_86_InfoData_st))
#endif /* STD_ON == DCM_SERVICE_86_ENABLED */

#if (STD_ON == DCM_SERVICE_27_ENABLED)
#define DCM_27_BLOCKSIZE                            DCM_27_LEVEL_NUM
#define DCM_27_BLOCKIDREF                           (0xFFFFU)
#define DCM_2701_SCURITYLEVEL_INDEX                 (0x00U)
#define DCM_27_BLOCKINVALIDID                       (0xFFFFU)
#endif /* STD_ON == DCM_SERVICE_27_ENABLED */
 

#if (STD_ON == DCM_SERVICE_19_ENABLED)
#define DCM_19_SUBIDNUM                              (0x0005U)
#define DCM_STOP_DTC                                 (0x01U)
#define DCM_NO_STOP_DTC                              (0x00U)
#endif
#if (STD_ON == DCM_SERVICE_29_ENABLED)
#define DCM_29_AUT_CONN_NUM                          (0U)
#define DCM_29_AUT_ROLE_NUM                          (0U)
#define DCM_29_AUT_TRANSCERT_NUM                     (0U)
#endif /* STD_ON == DCM_SERVICE_29_ENABLED */

#if (STD_ON == DCM_SERVICE_38_ENABLED)
#endif/* STD_ON == DCM_SERVICE_38_ENABLED */

#if ( STD_ON == DCM_REQUESTMANUFACTURERNOTIFICATION_ENABLED )
#define  DCM_SERVICEREQUESTMANUFACTURERNOTIFICATION_NUM (1U)
#endif /* STD_ON == DCM_REQUESTMANUFACTURERNOTIFICATION_ENABLED */

#if ( STD_ON == DCM_REQUESTSUPPLIERNOTIFICATION_ENABLED )
#define  DCM_SERVICEREQUESTSUPPLIERNOTIFICATION_NUM (1U)
#endif /* STD_ON == DCM_REQUESTSUPPLIERNOTIFICATION_ENABLED */

#if (STD_ON == DCM_SERVICE_35_ENABLED)
#define DCM_35_UPLOAD_BLOCKLEN                       (0x0200U)
#endif /* STD_ON == DCM_SERVICE_35_ENABLED */

/* Polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef struct{
    uint16 BlockId;
    uint8 RequestResp;
    uint8 ReadResp;
    uint8 *DataPtr;
    uint8 *DataInitPtr;
    uint16 DataSize;
} Dcm_ReadBlockId_st;
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dcm_D4.8"  Polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct Dcm_PROGCONDITIONSTYPE_TAG
{
    uint16  TesterSourceAddr;     /* The client ID (source address). */
    uint8   ProtocolId;           /* The protocol ID. */
    uint8   Sid;                  /* The request SID to be responded to. */
    uint8   SubFuncId;            /* The sub-function ID to be responded to. */
    boolean ReprogrammingRequest; /* Specifies whether an ECU preprogramming is needed
                                 	 (TRUE - ECU reprogramming, FALSE - no ECU reprogramming). */
    boolean ApplUpdated;          /* Specifies whether the application has been updated
                                	 (TRUE - application updated, FALSE - no application updated). */
    boolean ResponseRequired;     /* Specifies whether a response to the SID and sub-function 
	                                 has to be sent (TRUE) or just the requested diagnostic session
          					     	 shall be entered (FALSE). */
} Dcm_ProgConditionsType;

typedef uint8 (*Dcm_CheckRuleRef_p) (void);
typedef uint8 (*Dcm_CheckPreCondition_p) (void);
typedef void (*Dcm_ClearCallBackType_p) (void);
typedef uint8 (*Dcm_PrepareResetRef_p) (void);

typedef struct
{
    uint32 Dcm_Session;
    uint32 Dcm_Security;
} Dcm_ServiceFilter_st;

typedef struct
{
    uint32 Dcm_AutVal;
    uint8* Dcm_CurrAutState;
} Dcm_AutFilter_st;

typedef struct
{
    uint8* BufferPtr;
    uint16 BufferLength;
}Dcm_DslBufferType;

typedef struct
{
    PduIdType RxPduId;
    PduIdType TxPduId;
    uint8 RxAdrTyp;
    Dcm_ProtocolType ActiveProtocol;
    uint8 Priority;
    uint8 ServiceTbl;
    uint16 AuthConnId;
    uint32 ClientSrcAdr;
    boolean SendRcrrpOnTransBoot;
    uint8 ComMChannel;
}Dcm_DslProtocol_st;

typedef struct
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dcm_D4.8" */
{
    uint8 Dcm_ID;
    uint8 Dcm_ServiceType;
    uint16 Dcm_MinReqLength;
    Dcm_ServiceFilter_st Dcm_Filter;
    uint16 Dcm_ProtocolFilter;
    uint8 Dcm_Phy_FuncAddrFilter;
    Dcm_AutFilter_st Dcm_AutFilter;
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
    void (*Dcm_ServiceProcessorType_p)(void);
    void (*Dcm_ServiceInitType_p)(void);
    void (*Dcm_ServicePostProcessorType_p)(uint8 acParm);
} Dcm_ServiceTableType_st;

typedef struct
{
    const Dcm_ServiceTableType_st *Dcm_DspServiceInfoTable;
} Dcm_DSDInfo_st;

typedef struct
{
    uint16 Dcm_TimeOutP2;
    uint32 Dcm_TimeOutP2Ex;
} Dcm_TimerSettingType_st;

#if ( STD_ON == DCM_SERVICE_01_ENABLED )
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dcm_D4.8" */
typedef struct{
    uint8 Dcm_ID;
    uint8 Dcm_MResp;
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
    uint32 Dcm_Data_ABCD;
} Dcm_01_ServiceInfoType_st;
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dcm_D4.8" */
typedef struct{
    uint8 Dcm_ID;
    uint8 Dcm_RespLen;
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
    uint8 (*Dcm_PidProcessorType_p)(uint8*, uint16*, uint8);  /* Polyspace MISRA-C3:8.2 [Justified:Unset] "NSCA_Polyspace_Dcm_8.2" */
} Dcm_01_PidType_st;

typedef struct{
    const Dcm_01_ServiceInfoType_st* Dcm_ServiceInfoTable;
    const Dcm_01_PidType_st* Dcm_SupportPidTable;
} Dcm_01_DispatherInfo_st;

typedef enum
{
  DCM_01_NO_MRESQ = DCM_NUM_ZERO,
  DCM_01_MRESQ,
} Service01RESPType_e;  /* Polyspace MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#endif /* STD_ON == DCM_SERVICE_01_ENABLED */

#if ( STD_ON == DCM_SERVICE_02_ENABLED )
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dcm_D4.8" */
typedef struct{
    uint8 Dcm_ID;
    uint8 Dcm_MResp;
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
    uint32 Dcm_Data_ABCD;
} Dcm_02_ServiceInfoType_st;

typedef struct{
    uint8 Dcm_ID;
    uint8 Dcm_RespLen;
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
    uint8 (*Dcm_PidProcessorType_p)(uint8*, uint16*, uint8);  /* Polyspace MISRA-C3:8.2 [Justified:Unset] "NSCA_Polyspace_Dcm_8.2" */
    uint8 Dcm_PidDataElement;
} Dcm_02_PidType_st;

typedef struct{
    const Dcm_02_ServiceInfoType_st* Dcm_ServiceInfoTable;
    const Dcm_02_PidType_st* Dcm_SupportPidTable;
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Dcm_02_PidList;
} Dcm_02_DispatherInfo_st;

typedef enum
{
  DCM_02_NO_MRESQ = DCM_NUM_ZERO,
  DCM_02_MRESQ,
} Service02RESPType_e;  /* Polyspace MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#endif /* STD_ON == DCM_SERVICE_02_ENABLED */

#if ( STD_ON == DCM_SERVICE_09_ENABLED )
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dcm_D4.8" */
typedef struct{
    uint8 Dcm_ID;
    uint8 Dcm_MResp;
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
    uint32 Dcm_Data_ABCD;
} Dcm_09_ServiceInfoType_st;

typedef struct{
    uint8 Dcm_ID;
    uint8 Dcm_RespLen;
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
    void (*Dcm_PidProcessorType_p)(uint8, uint8*, uint16*, uint8);  /* Polyspace MISRA-C3:8.2 [Justified:Unset] "NSCA_Polyspace_Dcm_8.2" */
} Dcm_09_PidType_st;

typedef struct{
    const Dcm_09_ServiceInfoType_st* Dcm_ServiceInfoTable;
    const Dcm_09_PidType_st* Dcm_SupportPidTable;
} Dcm_09_DispatherInfo_st;

typedef enum
{
  DCM_09_NO_MRESQ = DCM_NUM_ZERO,
  DCM_09_MRESQ,
} Service09RESPType_e;  /* Polyspace MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#endif /* STD_ON == DCM_SERVICE_09_ENABLED */

#if (STD_ON == DCM_SERVICE_10_ENABLED)
typedef struct
{
    uint8 Dcm_IsBoot;
    uint8 Dcm_BootPos;
} Dcm_BootSettingType_st;  /* Polyspace MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

typedef struct
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dcm_D4.8" */
{
    uint8 Dcm_ID;
    uint8 Dcm_Phy_FuncAddrFilter;
    Dcm_ServiceFilter_st Dcm_Filter;
    Dcm_AutFilter_st Dcm_AutFilter;
    Dcm_TimerSettingType_st Dcm_RespTime;
    uint8 Dcm_DspSessionForBoot;
    uint8 Dcm_CurSession;
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
} Dcm_10_ServiceInfoType_st;
typedef struct
{
    const Dcm_10_ServiceInfoType_st *Dcm_ServiceInfoTable;
} Dcm_10_DispatherInfo_st;
/* This parameter defines whether this diagnostic session allows to jump to
  Bootloader (OEM Bootloader or System Supplier Bootloader) and determines, 
  from which unit the final response will be sent. */
enum
{
  DCM_NO_BOOT = DCM_NUM_ZERO,  /* This diagnostic session doesn't allow to jump to Bootloader. */
  DCM_OEM_BOOT ,  /* This diagnostic session allows to jump to OEM Bootloader and bootloader sends final response. */
  DCM_OEM_BOOT_RESPAPP,  /* This diagnostic session allows to jump to OEM Bootloader and application sends final response. */
  DCM_SYS_BOOT,  /* This diagnostic session allows to jump to System Supplier Bootloader and bootloader sends final response. */
  DCM_SYS_BOOT_RESPAPP,  /* This diagnostic session allows to jump to System Supplier Bootloader and application sends final response. */
  DCM_OTA_BOOT,
  DCM_OTA_BOOT_RESPAPP
};
#endif /* STD_ON == DCM_SERVICE_10_ENABLED */

#if (STD_ON == DCM_SERVICE_11_ENABLED)

typedef struct
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dcm_D4.8" */
{
    uint8 Dcm_ID;
    uint8 Dcm_Phy_FuncAddrFilter;
    uint8 Dcm_RespToEcuRst;
    Dcm_ServiceFilter_st Dcm_Filter;
    Dcm_AutFilter_st Dcm_AutFilter;
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
    Dcm_PrepareResetRef_p Dcm_PrepareResetRef;
}Dcm_11_ServiceInfoType_st;
typedef struct
{
    const Dcm_11_ServiceInfoType_st *Dcm_ServiceInfoTable;
} Dcm_11_DispatherInfo_st;
#endif/* STD_ON == DCM_SERVICE_11_ENABLED */

#if (STD_ON == DCM_SERVICE_14_ENABLED)

typedef struct
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dcm_D4.8" */
{
    Dcm_ServiceFilter_st Dcm_Filter;
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
    Dcm_ClearCallBackType_p Dcm_CallBackRef;
} Dcm_14_ServiceInfoType_st;
typedef struct
{
    const Dcm_14_ServiceInfoType_st *Dcm_ServiceInfoTable;
} Dcm_g14DispatherInfo_st;
#endif/* STD_ON == DCM_SERVICE_14_ENABLED */

#if (STD_ON == DCM_SERVICE_19_ENABLED)

typedef struct
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dcm_D4.8" */
{
    uint8 Dcm_ID;
    uint8 Dcm_Phy_FuncAddrFilter;
    uint8 Dcm_NeedStopDtc;
    Dcm_ServiceFilter_st Dcm_Filter;
    Dcm_AutFilter_st Dcm_AutFilter;
    uint16 Dcm_ReqDataLength;
    void (*Dcm_ServiceProcessorType_p)(void);
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
} Dcm_19_ServiceInfoType_st;
typedef struct
{
    const Dcm_19_ServiceInfoType_st *Dcm_ServiceInfoTable;
} Dcm_19_DispatherInfo_st;
#endif/* STD_ON == DCM_SERVICE_19_ENABLED */
#if ( (STD_ON == DCM_SERVICE_22_ENABLED) || (STD_ON == DCM_SERVICE_2E_ENABLED) || (STD_ON == DCM_SERVICE_2A_ENABLED) || (STD_ON == DCM_SERVICE_2C_ENABLED) )
typedef struct {
	uint8 Dcm_DidF199Buffer[4U];
} Dcm_Did_Block0090_Cfg;
typedef struct {
	uint8 Dcm_DidF190Buffer[17U];
} Dcm_Did_Block0091_Cfg;
typedef struct {
	uint8 Dcm_DidF1A2Buffer[4U];
} Dcm_Did_Block0092_Cfg;
typedef struct {
	uint8 Dcm_DidF112Buffer[8U];
} Dcm_Did_Block0093_Cfg;
typedef struct {
	uint8 Dcm_DidF198Buffer[16U];
} Dcm_Did_Block0094_Cfg;
typedef struct {
	uint8 Dcm_DidF197Buffer[8U];
} Dcm_Did_Block0095_Cfg;
typedef struct {
	uint8 Dcm_DidDFECBuffer[64U];
} Dcm_Did_Block0096_Cfg;
typedef struct {
	uint8 Dcm_DidDFEDBuffer[64U];
} Dcm_Did_Block0097_Cfg;
typedef struct {
	uint8 Dcm_DidDFEEBuffer[64U];
} Dcm_Did_Block0098_Cfg;
typedef struct {
	uint8 Dcm_DidDFEFBuffer[64U];
} Dcm_Did_Block0099_Cfg;
typedef struct {
	uint8 Dcm_DidF101Buffer[8U];
} Dcm_Did_Block009A_Cfg;
typedef struct {
	uint8 Dcm_DidF110Buffer[8U];
} Dcm_Did_Block009B_Cfg;
typedef struct {
	uint8 Dcm_DidD135Buffer[16U];
} Dcm_Did_Block009C_Cfg;
typedef struct {
	uint8 Dcm_DidD136Buffer[16U];
} Dcm_Did_Block009D_Cfg;
typedef struct {
	uint8 Dcm_Did0280Buffer[16U];
} Dcm_Did_Block009E_Cfg;
typedef struct {
	uint8 Dcm_Did05D5Buffer[4U];
} Dcm_Did_Block009F_Cfg;
typedef struct {
	uint8 Dcm_Did05D6Buffer[4U];
} Dcm_Did_Block00A0_Cfg;
typedef struct {
	uint8 Dcm_Did05D7Buffer[3U];
} Dcm_Did_Block00A1_Cfg;
typedef struct {
	uint8 Dcm_Did05D8Buffer[2U];
} Dcm_Did_Block00A2_Cfg;
typedef struct {
	uint8 Dcm_Did05D9Buffer[1U];
} Dcm_Did_Block00A3_Cfg;
typedef struct {
	uint8 Dcm_Did05DABuffer[1U];
} Dcm_Did_Block00A4_Cfg;
typedef struct {
	uint8 Dcm_Did05DBBuffer[24U];
} Dcm_Did_Block00A5_Cfg;
typedef struct {
	uint8 Dcm_DidF187Buffer[21U];
} Dcm_Did_Block00A6_Cfg;
typedef struct {
	uint8 Dcm_DidF18CBuffer[24U];
} Dcm_Did_Block00A7_Cfg;
typedef struct {
	uint8 Dcm_DidF18ABuffer[6U];
} Dcm_Did_Block00A8_Cfg;
typedef struct {
	uint8 Dcm_DidF191Buffer[10U];
} Dcm_Did_Block00A9_Cfg;
typedef struct {
	uint8 Dcm_DidF189Buffer[10U];
} Dcm_Did_Block00AA_Cfg;
typedef struct {
	uint8 Dcm_DidF193Buffer[16U];
} Dcm_Did_Block00AB_Cfg;
typedef struct {
	uint8 Dcm_DidF195Buffer[16U];
} Dcm_Did_Block00AC_Cfg;
typedef struct {
	uint8 Dcm_DidF180Buffer[16U];
} Dcm_Did_Block00AD_Cfg;
typedef struct {
	uint8 Dcm_DidF113Buffer[4U];
} Dcm_Did_Block00AE_Cfg;
typedef struct {
	uint8 Dcm_DidF182Buffer[16U];
} Dcm_Did_Block00AF_Cfg;
typedef struct {
	uint8 Dcm_DidF186Buffer[1U];
} Dcm_Did_Block00B0_Cfg;
typedef struct {
	uint8 Dcm_DidF18BBuffer[4U];
} Dcm_Did_Block00B1_Cfg;
typedef struct {
	uint8 Dcm_Did0200Buffer[1U];
} Dcm_Did_Block00B2_Cfg;
typedef struct {
	uint8 Dcm_Did0201Buffer[1U];
} Dcm_Did_Block00B3_Cfg;
typedef struct {
	uint8 Dcm_DidF1A3Buffer[16U];
} Dcm_Did_Block00B4_Cfg;
typedef struct {
	uint8 Dcm_DidF1A4Buffer[16U];
} Dcm_Did_Block00B5_Cfg;
typedef struct {
	uint8 Dcm_DidF1A5Buffer[16U];
} Dcm_Did_Block00B6_Cfg;
typedef struct {
	uint8 Dcm_DidF800Buffer[4U];
} Dcm_Did_Block00B7_Cfg;
typedef struct {
	uint8 Dcm_DidF802Buffer[17U];
} Dcm_Did_Block00B8_Cfg;
//baoenfei
typedef struct {
	uint8 Dcm_Service0x14CountBuffer[1U];
} Dcm_Did_Block00B9_Cfg;
/* Polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef uint8 (*Dcm_CheckValueCallBackType_p) (void);
typedef Std_ReturnType (*Dcm_DidReadData_sync)(uint8* Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
typedef Std_ReturnType (*Dcm_DidReadData_async)(Dcm_OpStatusType OpStatus, uint8* Data, Dcm_NegativeResponseCodeType* ErrorCode);
typedef Std_ReturnType (*Dcm_DidWriteData_sync)(uint8* Data, Dcm_NegativeResponseCodeType* ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
typedef Std_ReturnType (*Dcm_DidWriteData_async)(Dcm_OpStatusType OpStatus, uint8* Data, Dcm_NegativeResponseCodeType* ErrorCode);
typedef Std_ReturnType (*Dcm_DidReadDataLength)(uint16* DataLength);
typedef Std_ReturnType (*Dcm_DidConditionCheckRead_sync)(Dcm_NegativeResponseCodeType* ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
typedef Std_ReturnType (*Dcm_DidConditionCheckRead_async)(Dcm_OpStatusType OpStatus,Dcm_NegativeResponseCodeType* ErrorCode);
typedef Std_ReturnType (*Dcm_DidConditionCheckWrite)(Dcm_NegativeResponseCodeType* ErrorCode);

typedef struct
{
	Dcm_DidReadData_sync Dcm_DidReadData_sync;  /* Polyspace MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dcm_5.6" */
	Dcm_DidReadData_async Dcm_DidReadData_async;  /* Polyspace MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dcm_5.6" */
}Dcm_DidReadData_st;

typedef struct
{
	Dcm_DidWriteData_sync Dcm_DidWriteData_sync;  /* Polyspace MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dcm_5.6" */
	Dcm_DidWriteData_async Dcm_DidWriteData_async;  /* Polyspace MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dcm_5.6" */
}Dcm_DidWriteData_st;

typedef struct
{
	Dcm_DidConditionCheckRead_sync Dcm_DidConditionCheckRead_sync;  /* Polyspace MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dcm_5.6" */
	Dcm_DidConditionCheckRead_async Dcm_DidConditionCheckRead_async;  /* Polyspace MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dcm_5.6" */
}Dcm_DidConditionCheckRead_st;

typedef enum
{
	USE_BLOCK_ID = 0u,
	USE_DATA_ASYNCH_CLIENT_SERVER,
	USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
	USE_DATA_ASYNCH_FNC,
	USE_DATA_ASYNCH_FNC_ERROR,
	USE_DATA_ASYNCH_FNC_PROXY,
	USE_DATA_SENDER_RECEIVER,
	USE_DATA_SENDER_RECEIVER_AS_SERVICE,
	USE_DATA_SYNCH_CLIENT_SERVER,
	USE_DATA_SYNCH_FNC,
	USE_DATA_SYNCH_FNC_PROXY
}Dcm_DataUsedPort_e;

typedef struct
{
    uint16 Dcm_ID;
    uint8 Dcm_Used;
    uint16 Dcm_Length;
    uint16 Dcm_BlockIdRef;
    uint8 *Dcm_BlockStarAdr;
    uint8 *Dcm_BlockDataPtr;
    uint8 Dcm_RorW;
    Dcm_DataUsedPort_e Dcm_DataUsedPort;
    Dcm_ServiceFilter_st Dcm_ReadFilter;
    Dcm_AutFilter_st Dcm_ReadAutFilter;
    Dcm_ServiceFilter_st Dcm_WriteFilter;
    Dcm_AutFilter_st Dcm_WriteAutFilter;
    Dcm_DidReadData_st Dcm_DidReadData;    
    Dcm_DidReadDataLength Dcm_DidReadDataLength;  /* Polyspace MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dcm_5.6" */
    Dcm_DidConditionCheckRead_st Dcm_DidCondCheckRead;
    Dcm_DidWriteData_st Dcm_DidWriteData;
	Dcm_DidConditionCheckWrite Dcm_DidCondCheckWrite;
	Dcm_CheckPreCondition_p Dcm_PreCondition;
}Dcm_22_2E_ServiceInfoType_st;

typedef struct
{
    uint16 *Dcm_22_DidList;
    uint16 *Dcm_22_DidResLen;
    const Dcm_22_2E_ServiceInfoType_st *Dcm_ServiceInfoTable;
} Dcm_22_2E_DispatherInfo_st;
#endif

#if (STD_ON == DCM_SERVICE_27_ENABLED)
typedef struct
{
    uint8 AttemptCounter;
} Dcm_27_Security_cfg;

typedef struct
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dcm_D4.8" */
{
    uint8 Dcm_ID;
    uint8 Dcm_Phy_FuncAddrFilter;
    Dcm_ServiceFilter_st Dcm_SeedFilter;
    Dcm_ServiceFilter_st Dcm_KeyFilter;
    Dcm_AutFilter_st Dcm_ReadAutFilter;
    uint8 Dcm_NumMaxAttDelay;
    uint16 Dcm_SeedLength;
    uint16 Dcm_KeyLength;
    uint32 Dcm_DelayInvKey;
    Std_ReturnType (*Dcm_GetSeedCallBackType_p)(Dcm_OpStatusType OpStatus, uint8 *Seed, Dcm_NegativeResponseCodeType *ErrorCode);  /* Polyspace MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
    Std_ReturnType (*Dcm_SendKeyCallBackType_p)(uint8* Key, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);  /* Polyspace MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
    Dcm_27_Security_cfg* Dcm_27_SecurityData;
    Std_ReturnType (*Dcm_GetAttemptCounterCallBackType_p)(Dcm_OpStatusType OpStatus, uint8* AttemptCounter);  /* Polyspace MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
    Std_ReturnType (*Dcm_SetAttemptCounterCallBackType_p)(Dcm_OpStatusType OpStatus, uint8 AttemptCounter);  /* Polyspace MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
}Dcm_27_ServiceInfoType_st;
typedef struct
{
    const Dcm_27_ServiceInfoType_st *Dcm_ServiceInfoTable;
} Dcm_27_DispatherInfo_st;
#endif /* STD_ON == DCM_SERVICE_27_ENABLED */
#if (STD_ON == DCM_SERVICE_28_ENABLED)

typedef struct
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dcm_D4.8" */
{
    uint8 Dcm_ID;
    uint8 Dcm_Phy_FuncAddrFilter;
    Dcm_ServiceFilter_st Dcm_Filter;
    Dcm_AutFilter_st Dcm_AutFilter;
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
} Dcm_28_ServiceInfoType_st;

typedef struct
{
    const uint8* Dcm_ControlStete;
    const Dcm_28_ServiceInfoType_st* Dcm_ServiceInfoTable;
} Dcm_28_DispatherInfo_st;
#endif /* STD_ON == DCM_SERVICE_28_ENABLED */

#if (STD_ON == DCM_SERVICE_29_ENABLED)
typedef struct
{
    uint8 Dcm_CertVerfCallNotifyRef;
    uint8 Dcm_RandSeedCallNotifyRef;
    uint8 Dcm_SignatureGenerateNotifyRef;
    uint8 Dcm_SignatureVerifyNotifyRef;
    uint16 Dcm_EcuChallengeLength;
    uint16 Dcm_ClientCertIdx;
    uint16 Dcm_ConnectionCertIdx;
    uint16 Dcm_ConnectionMainConnectionIdx;
    uint16 Dcm_ECUCertificateKeyElmtIdx;
    uint16 Dcm_ECUCertificateIdx;
    uint16 Dcm_PublicKeyElmtIdx;
    uint16 Dcm_RoleElmtIdx;
    uint16 Dcm_WLDIDElmtIdx;
    uint16 Dcm_WLMemorySelectionElmtIdx;
    uint16 Dcm_WLRIDElementIdx;
    uint16 Dcm_WLServicesElementIdx;
    uint32 Dcm_CertPublicKeyStoreJobIdx;
    uint32 Dcm_ClientChallengeSignJobIdx;
    uint32 Dcm_RandomJobIdx;
    uint32 Dcm_VerifyPOWNJobIdx;
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
} Dcm_29_AutConn_st;

typedef struct
{
    uint16 Dcm_AutTransCertEvalId;
    uint16 KeyMCertId;
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
}Dcm_29_AutTransCert_st;

typedef struct
{
    uint8 Dcm_ID;
    uint8 Dcm_Used;
    uint16 Dcm_Length;
    Dcm_ServiceFilter_st Dcm_Filter;
    void (*Dcm_ServiceProcessorType_p)(void);
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
} Dcm_29_ServiceInfoType_st;

typedef struct
{
    const Dcm_29_ServiceInfoType_st *Dcm_ServiceInfoTable;
} Dcm_29_DispatherInfo_st;
#endif /* STD_ON == DCM_SERVICE_29_ENABLED */

#if (STD_ON == DCM_SERVICE_38_ENABLED)
typedef struct
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dcm_D4.8" */
{
    uint8 Dcm_ID;
    uint8 Dcm_Phy_FuncAddrFilter;
    Dcm_ServiceFilter_st Dcm_Filter;
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
    Dcm_AutFilter_st Dcm_AutFilter;
    Std_ReturnType (*Dcm_38_Info_Trans)(const Dcm_38_ServiceInfoType_Req* DataInVar, Dcm_NegativeResponseCodeType* ErrorPtr);
    Std_ReturnType (*Dcm_38_Info_Capture)(Dcm_38_ServiceInfoType_Res* DataOutVar, Dcm_NegativeResponseCodeType* ErrorPtr);
} Dcm_38_ServiceInfoType_st;

typedef struct
{
    const Dcm_38_ServiceInfoType_st *Dcm_ServiceInfoTable;
} Dcm_38_DispatherInfo_st;
#endif/* STD_ON == DCM_SERVICE_38_ENABLED */

#if ( (STD_ON == DCM_REQUESTMANUFACTURERNOTIFICATION_ENABLED) || (STD_ON == DCM_REQUESTSUPPLIERNOTIFICATION_ENABLED) )
typedef Std_ReturnType (*Dcm_ServiceRequestNotification_Indication)
(
    uint8 SID,
    P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) RequestData,
    uint16 DataSize,
    uint8 ReqType,
    uint16 SourceAddress,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode
);

typedef Std_ReturnType (*Dcm_ServiceRequestNotification_Confirmation)
(
    uint8 SID,
    uint8 ReqType,
    uint16 SourceAddress,
    Std_ReturnType ConfirmationStatus  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
);
#endif/* (STD_ON == DCM_REQUESTMANUFACTURERNOTIFICATION_ENABLED) || (STD_ON == DCM_REQUESTSUPPLIERNOTIFICATION_ENABLED) */

#if ( STD_ON == DCM_REQUESTMANUFACTURERNOTIFICATION_ENABLED )
typedef struct
{
    Dcm_ServiceRequestNotification_Indication indication[DCM_SERVICEREQUESTMANUFACTURERNOTIFICATION_NUM  + 1U];
    Dcm_ServiceRequestNotification_Confirmation confirmation[DCM_SERVICEREQUESTMANUFACTURERNOTIFICATION_NUM  + 1U];
} Dcm_ServiceRequestManufacturerNotification_st;
#endif /* STD_ON == DCM_REQUESTMANUFACTURERNOTIFICATION_ENABLED */

#if ( STD_ON == DCM_REQUESTSUPPLIERNOTIFICATION_ENABLED )
typedef struct
{
    Dcm_ServiceRequestNotification_Indication indication[DCM_SERVICEREQUESTSUPPLIERNOTIFICATION_NUM + 1U];
    Dcm_ServiceRequestNotification_Confirmation confirmation[DCM_SERVICEREQUESTSUPPLIERNOTIFICATION_NUM + 1U];
} Dcm_ServiceRequestSupplierNotification_st;
#endif /* STD_ON == DCM_REQUESTSUPPLIERNOTIFICATION_ENABLED */

#if (STD_ON == DCM_SERVICE_2F_ENABLED)
enum
{
    DCM_2F_SIGNAL_TYPE_FIXED = 0x00U,
    DCM_2F_SIGNAL_TYPE_VARIABLE
};

typedef struct
{
    uint8 Dcm_length_Sub00_Sub01_Sub02;
    uint8 Dcm_length_Sub03;
    uint8 Dcm_length_Mask;
} Dcm_2F_RequestDataLen_st;

typedef struct
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dcm_D4.8" */
{
    uint16 Dcm_ID;
    uint8 Dcm_DspDidUsed;
    uint8 Dcm_FixedLength;
    Dcm_ServiceFilter_st Dcm_Filter;
    Dcm_AutFilter_st Dcm_AutFilter;
    Dcm_2F_RequestDataLen_st Dcm_Length;
    uint8 (*Dcm_00_IOControlCallBackType_p)(const uint8* DataInVar, uint16 ReqLength, uint8* DataOutVar, uint16* RespLength, Dcm_NegativeResponseCodeType* ErrorCode);
    uint8 (*Dcm_01_IOControlCallBackType_p)(const uint8* DataInVar, uint16 ReqLength, Dcm_OpStatusType OpStatus, uint8* DataOutVar, uint16* RespLength, Dcm_NegativeResponseCodeType* ErrorCode);  /* Polyspace MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
    uint8 (*Dcm_02_IOControlCallBackType_p)(const uint8* DataInVar, uint16 ReqLength, Dcm_OpStatusType OpStatus, uint8* DataOutVar, uint16* RespLength, Dcm_NegativeResponseCodeType* ErrorCode);  /* Polyspace MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
    uint8 (*Dcm_03_IOControlCallBackType_p)(const uint8* DataInVar, uint16 ReqLength, Dcm_OpStatusType OpStatus, uint8* DataOutVar, uint16* RespLength, Dcm_NegativeResponseCodeType* ErrorCode);  /* Polyspace MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
} Dcm_2F_ServiceInfoType_st;
typedef struct
{
    const Dcm_2F_ServiceInfoType_st *Dcm_ServiceInfoTable;
} Dcm_2F_DispatherInfo_st;
#endif/* STD_ON == DCM_SERVICE_2F_ENABLED */
#if (STD_ON == DCM_SERVICE_31_ENABLED)
enum
{
    DCM_31_SIGNAL_TYPE_FIXED = 0x00U,
    DCM_31_SIGNAL_TYPE_VARIABLE
};

typedef struct
{
    uint16 Dcm_ReqLen;
    uint16 Dcm_ResLen;
} Dcm_ReqResLen_st;

typedef struct
{
    uint8 Dcm_StartLenType;
    uint8 Dcm_StopLenType;
    uint8 Dcm_ReqResultLenType;
} Dcm_RouteCtrlDataLenType;

typedef struct
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dcm_D4.8" */
{
    uint16 Dcm_ID;
    uint8 Dcm_Phy_FuncAddrFilter;
    uint8 Dcm_DspRoutineUsed; 
    Dcm_RouteCtrlDataLenType Dcm_DataInLenType;
    Dcm_RouteCtrlDataLenType Dcm_DataOutLenType;
    Dcm_ServiceFilter_st Dcm_Filter;
    Dcm_AutFilter_st Dcm_StarAutFilter;
    Dcm_AutFilter_st Dcm_StopAutFilter;
    Dcm_AutFilter_st Dcm_ReqResultAutFilter;
    Dcm_ReqResLen_st Dcm_StartLen;
    Dcm_ReqResLen_st Dcm_StopLen;
    Dcm_ReqResLen_st Dcm_ReqResultLen;
    Std_ReturnType  (*Dcm_RouteControl_01_p)(const uint8* DataInVar, Dcm_OpStatusType OpStatus, uint8* DataOutVar, uint16 CurrentLengthDataInVar, uint16* CurrentLengthDataOutVar, Dcm_NegativeResponseCodeType* ErrorPtr);  /* Polyspace MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
    Std_ReturnType  (*Dcm_RouteControl_02_p)(const uint8* DataInVar, Dcm_OpStatusType OpStatus, uint8* DataOutVar, uint16 CurrentLengthDataInVar, uint16* CurrentLengthDataOutVar, Dcm_NegativeResponseCodeType* ErrorPtr);  /* Polyspace MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
    Std_ReturnType  (*Dcm_RouteControl_03_p)(const uint8* DataInVar, Dcm_OpStatusType OpStatus, uint8* DataOutVar, uint16 CurrentLengthDataInVar, uint16* CurrentLengthDataOutVar, Dcm_NegativeResponseCodeType* ErrorPtr);  /* Polyspace MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
}Dcm_31_ServiceInfoType_st;

typedef struct
{
    const Dcm_31_ServiceInfoType_st *Dcm_ServiceInfoTable;
} Dcm_31_DispatherInfo_st;
#endif/* STD_ON == DCM_SERVICE_31_ENABLED */

#if (STD_ON == DCM_SERVICE_3E_ENABLED)
typedef struct
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dcm_D4.8" */
{
    uint8 Dcm_ID;
    uint8 Dcm_Phy_FuncAddrFilter;
    uint8 Dcm_ReqLen;
    Dcm_ServiceFilter_st Dcm_Filter;
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
} Dcm_3E_ServiceInfoType_st;

typedef struct
{
    const Dcm_3E_ServiceInfoType_st *Dcm_ServiceInfoTable;
} Dcm_3E_DispatherInfo_st;
#endif/* STD_ON == DCM_SERVICE_3E_ENABLED */

#if (STD_ON == DCM_SERVICE_85_ENABLED)
typedef struct
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dcm_D4.8" */
{
    uint8 Dcm_ID;
    uint8 Dcm_Phy_FuncAddrFilter;
    Dcm_ServiceFilter_st Dcm_Filter;
    Dcm_AutFilter_st Dcm_AutFilter;
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
} Dcm_85_ServiceInfoType_st;

typedef struct
{
    const Dcm_85_ServiceInfoType_st *Dcm_ServiceInfoTable;
} Dcm_85_DispatherInfo_st;
#endif  /* STD_ON == DCM_SERVICE_85_ENABLED */
#if ( STD_ON == DCM_SERVICE_34_ENABLED )
typedef struct
{
    uint8 Dcm_DataFormatId;
    uint8 Dcm_AddrAndLenFmtId;
    uint32 Dcm_MemoryAddress;
    uint32 Dcm_MemorySize;
    uint8* Dcm_ReqBuffer;
    uint16* Dcm_ReqBufferLen;
} Dcm_34_RepeaterProxyContextType_st;

#endif /* STD_ON == DCM_SERVICE_34_ENABLED */

#if (STD_ON == DCM_SERVICE_35_ENABLED)
typedef struct
{
    uint8 Dcm_DataFormatId;
    uint8 Dcm_AddrAndLenFmtId;
    uint32 Dcm_MemoryAddress;
    uint32 Dcm_MemorySize;
} Dcm_35_RepeaterProxyContextType_st;
#endif /* STD_ON == DCM_SERVICE_35_ENABLED */

typedef struct
{
    uint32 Dcm_MemoryAddress_Low;
    uint32 Dcm_MemoryAddress_High;
    Dcm_ServiceFilter_st Dcm_Filter;
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
} Dcm_DspMemoryInfoType_st;

#if (STD_ON == DCM_SERVICE_2C_ENABLED)
typedef struct
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dcm_D4.8" */
{
    uint32 Dcm_MemAddr;
    uint32 Dcm_MemSize;
    Dcm_ServiceFilter_st Dcm_ReadFilter;
	Dcm_AutFilter_st Dcm_AutFilter;
} Dcm_2C_DDDid_Info_st;
typedef struct
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dcm_D4.8" */
{
    uint16 Dcm_ID;
    uint8 Dcm_DDDidMaxElmt;
    Dcm_ServiceFilter_st Dcm_ReadFilter;
	Dcm_AutFilter_st Dcm_AutFilter;
    Dcm_2C_DDDid_Info_st* Dcm_2C_DDDid_Info;
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
} Dcm_2C_ServiceInfoType_st;
typedef struct
{
    const uint8* Dcm_SubServiceInfoTable;
    const Dcm_2C_ServiceInfoType_st *Dcm_ServiceInfoTable;
} Dcm_2C_DispatherInfo_st;
#endif /* STD_ON == DCM_SERVICE_2C_ENABLED */

#if (STD_ON == DCM_SERVICE_2A_ENABLED)
typedef struct
{
    uint16 Dcm_LocPduIdx;
    uint16 Dcm_TxPduId;
} Dcm_2A_Channel_st;

typedef struct
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dcm_D4.8" */
{
    uint16 Dcm_ID;
    uint8 Dcm_Used;
    uint16 Dcm_Length;
    Dcm_DataUsedPort_e Dcm_DataUsedPort;
    Dcm_ServiceFilter_st Dcm_ReadFilter;
    Dcm_AutFilter_st Dcm_AutFilter;
    Dcm_DidReadData_st Dcm_DidReadData;
    Dcm_DidReadDataLength Dcm_DidReadDataLength;  /* Polyspace MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dcm_5.6" */
    Dcm_DidConditionCheckRead_st Dcm_DidCondCheckRead;
    Dcm_CheckRuleRef_p Dcm_CheckRuleRef;
} Dcm_2A_ServiceInfoType_st;

typedef struct
{
    const Dcm_2A_ServiceInfoType_st *Dcm_ServiceInfoTable;
} Dcm_2A_DispatherInfo_st;
#endif /* STD_ON == DCM_SERVICE_2A_ENABLED */

#if (STD_ON == DCM_SERVICE_86_ENABLED)
typedef struct
{
    PduIdType RxPduId;
    PduIdType TxPduId;
    uint32 ClientSrcAddr;
} Dcm_86_DslInfo_st;

typedef struct
{
    uint8 Dcm_EventId;
    uint8 Dcm_EventState; /* EventState: Start, Stop, Clear. */
    uint8 Dcm_EventWndTime;
    uint8 Dcm_StorageStatus;
    uint8 Dcm_EventMask; /* EventType = onDTCStatusChange */
    uint16 Dcm_DidValue; /* EventType = onChangeOfDataIdentifier */
} Dcm_86_InfoData_st;

typedef struct
{
    Dcm_86_DslInfo_st Dcm_DslInfo;
    Dcm_86_InfoData_st Dcm_InfoData[DCM_86_EEP_EVENTNUM];
} Dcm_86_NvMInfo_st;

typedef struct {
	union  /* Polyspace MISRA-C3:19.2 [Justified:Unset] "NSCA_Polyspace_Dcm_19.2" */
	{
		uint8 NvMRamData[DCM_ROE_BLOCKSIZE];
		Dcm_86_NvMInfo_st NvMInfoData;
	}NvmInfo;
}Dcm_86_NvMEventInfo_st;

typedef struct
{
	uint8 Dcm_TransType; /* DcmDslProtocolTransType. */
    uint8 Dcm_Priority;
    PduIdType Dcm_RxPduId;
    PduIdType Dcm_TxPduId;
} Dcm_86_DslProtocol_st;

typedef struct
{
    uint8 Dcm_EventType;
    uint8 Dcm_MsgLength; /* Request message length except the service ID( one byte). */
} Dcm_86_RequestMsg_st;
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dcm_D4.8" */
typedef struct
/* Polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dcm_D4.8" */
{
    uint8 Dcm_EventID;
    uint8 Dcm_EventInitStatus;
	uint8 Dcm_DidValid;
    uint16 Dcm_DidValue;
} Dcm_86_ServiceInfoType_st;

typedef struct
{
    const Dcm_86_ServiceInfoType_st* Dcm_ServiceInfoTable;
} Dcm_86_DispatherInfo_st;
#endif /* STD_ON == DCM_SERVICE_86_ENABLED */

#if (STD_ON == DCM_SERVICE_87_ENABLED)
typedef struct
{
    uint8 Dcm_ID;
    uint8 Dcm_Phy_FuncAddrFilter;
    uint16 Dcm_ReqDataLength;
    Dcm_ServiceFilter_st Dcm_Filter;
    Dcm_AutFilter_st Dcm_AutFilter;
    void (*Dcm_ServiceProcessorType_p)(void);
    Std_ReturnType  (*Dcm_LinkControl_01_02_03)(Dcm_OpStatusType OpStatus, uint8 ID, uint8 LinkControlModeId, uint32* LinkRecord, Dcm_NegativeResponseCodeType* ErrorCode);
} Dcm_87_ServiceInfoType_st;

typedef struct
{
    const Dcm_87_ServiceInfoType_st *Dcm_ServiceInfoTable;
} Dcm_87_DispatherInfo_st;
#endif /* STD_ON == DCM_SERVICE_87_ENABLED */

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define DCM_START_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dcm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
extern VAR(uint8, DCM_VAR_INIT) Dcm_DslBufferRx[DCM_DSL_BUFFERLENRX];
extern VAR(Dcm_ReadBlockId_st, DCM_VAR_INIT) Dcm_ReadBlockId[DCM_READ_BLOCK_NUM + 1];
extern VAR(uint32, DCM_VAR_INIT) Dcm_ProgrammingLength;

#if ( (STD_ON == DCM_SERVICE_22_ENABLED) || (STD_ON == DCM_SERVICE_2E_ENABLED) )
extern VAR(uint16, DCM_VAR_INIT) Dcm_22_DidList[DCM_22_MAX_DID_LIST_NUM];
extern VAR(uint16, DCM_VAR_INIT) Dcm_22_DidResLen[DCM_22_MAX_DID_LIST_NUM];
 
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0310Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0311Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0312Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0313Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0314Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0315Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0316Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0317Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0318Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0319Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did031ABuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did031BBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did031CBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did031DBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did031EBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did031FBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0320Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0321Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0322Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0323Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0324Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0325Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0326Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0327Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0328Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0329Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did032ABuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did032BBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did032CBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did032DBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did032EBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did032FBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0330Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0331Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0332Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0333Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0334Buffer[3U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0335Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_DidDF00Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0501Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0502Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0503Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0504Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0507Buffer[255U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did050ABuffer[54U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_DidCF00Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_DidCF05Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_DidDF09Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0525Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0526Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0527Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0528Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0529Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_DidCF06Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did052BBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_DidCF07Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did052DBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0530Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0531Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0532Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0533Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0534Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0535Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0536Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0537Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0538Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0539Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0505Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did053BBuffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did053CBuffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did053DBuffer[4U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did053EBuffer[4U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0542Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0543Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0544Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0545Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0547Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0552Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did055ABuffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did055CBuffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did055DBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0585Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0586Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0587Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0588Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0589Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did058ABuffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did058BBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did058CBuffer[3U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did058DBuffer[3U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did058EBuffer[3U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did058FBuffer[3U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0590Buffer[3U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0591Buffer[3U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0592Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0593Buffer[48U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0594Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0595Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0596Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0597Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0598Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0599Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did059ABuffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did059BBuffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did059DBuffer[8U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did059EBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did059FBuffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_DidDD00Buffer[6U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05A1Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05A2Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05A3Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05A4Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05A5Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05A6Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05A7Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05A8Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05A9Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05AABuffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05ABBuffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05ACBuffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05ADBuffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05AEBuffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05AFBuffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05B0Buffer[48U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05B1Buffer[48U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05B2Buffer[288U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05B3Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05B4Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05B5Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05B6Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05B7Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05B8Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05B9Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05BABuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05BBBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05BCBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05BDBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05BEBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05BFBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05C0Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05C1Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05C2Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05C3Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05C4Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05C5Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05C6Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05C7Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05C8Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05C9Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05CABuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05CBBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05CCBuffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05CDBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05CEBuffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05CFBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05D0Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05D1Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05D2Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05D3Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did05D4Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_DidDF01Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_DidDF02Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_DidDF03Buffer[4U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_DidDF04Buffer[4U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_DidDF06Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did059CBuffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did052EBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_DidDF0ABuffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_DidDF0BBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_DidDF0CBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_DidDF0DBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_DidDF0EBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0402Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0403Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0404Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0405Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0406Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0407Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0408Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0409Buffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did040BBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did040CBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did040DBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did04CFBuffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did0400Buffer[1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did04DCBuffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did04DDBuffer[2U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Did04DEBuffer[2U];
extern VAR(Dcm_Did_Block0090_Cfg, DCM_VAR_INIT) Dcm_Did_Block0090_Data;
extern VAR(Dcm_Did_Block0091_Cfg, DCM_VAR_INIT) Dcm_Did_Block0091_Data;
extern VAR(Dcm_Did_Block0092_Cfg, DCM_VAR_INIT) Dcm_Did_Block0092_Data;
extern VAR(Dcm_Did_Block0093_Cfg, DCM_VAR_INIT) Dcm_Did_Block0093_Data;
extern VAR(Dcm_Did_Block0094_Cfg, DCM_VAR_INIT) Dcm_Did_Block0094_Data;
extern VAR(Dcm_Did_Block0095_Cfg, DCM_VAR_INIT) Dcm_Did_Block0095_Data;
extern VAR(Dcm_Did_Block0096_Cfg, DCM_VAR_INIT) Dcm_Did_Block0096_Data;
extern VAR(Dcm_Did_Block0097_Cfg, DCM_VAR_INIT) Dcm_Did_Block0097_Data;
extern VAR(Dcm_Did_Block0098_Cfg, DCM_VAR_INIT) Dcm_Did_Block0098_Data;
extern VAR(Dcm_Did_Block0099_Cfg, DCM_VAR_INIT) Dcm_Did_Block0099_Data;
extern VAR(Dcm_Did_Block009A_Cfg, DCM_VAR_INIT) Dcm_Did_Block009A_Data;
extern VAR(Dcm_Did_Block009B_Cfg, DCM_VAR_INIT) Dcm_Did_Block009B_Data;
extern VAR(Dcm_Did_Block009C_Cfg, DCM_VAR_INIT) Dcm_Did_Block009C_Data;
extern VAR(Dcm_Did_Block009D_Cfg, DCM_VAR_INIT) Dcm_Did_Block009D_Data;
extern VAR(Dcm_Did_Block009E_Cfg, DCM_VAR_INIT) Dcm_Did_Block009E_Data;
extern VAR(Dcm_Did_Block009F_Cfg, DCM_VAR_INIT) Dcm_Did_Block009F_Data;
extern VAR(Dcm_Did_Block00A0_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A0_Data;
extern VAR(Dcm_Did_Block00A1_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A1_Data;
extern VAR(Dcm_Did_Block00A2_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A2_Data;
extern VAR(Dcm_Did_Block00A3_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A3_Data;
extern VAR(Dcm_Did_Block00A4_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A4_Data;
extern VAR(Dcm_Did_Block00A5_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A5_Data;
extern VAR(Dcm_Did_Block00A6_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A6_Data;
extern VAR(Dcm_Did_Block00A7_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A7_Data;
extern VAR(Dcm_Did_Block00A8_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A8_Data;
extern VAR(Dcm_Did_Block00A9_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A9_Data;
extern VAR(Dcm_Did_Block00AA_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AA_Data;
extern VAR(Dcm_Did_Block00AB_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AB_Data;
extern VAR(Dcm_Did_Block00AC_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AC_Data;
extern VAR(Dcm_Did_Block00AD_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AD_Data;
extern VAR(Dcm_Did_Block00AE_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AE_Data;
extern VAR(Dcm_Did_Block00AF_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AF_Data;
extern VAR(Dcm_Did_Block00B0_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B0_Data;
extern VAR(Dcm_Did_Block00B1_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B1_Data;
extern VAR(Dcm_Did_Block00B2_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B2_Data;
extern VAR(Dcm_Did_Block00B3_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B3_Data;
extern VAR(Dcm_Did_Block00B4_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B4_Data;
extern VAR(Dcm_Did_Block00B5_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B5_Data;
extern VAR(Dcm_Did_Block00B6_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B6_Data;
extern VAR(Dcm_Did_Block00B7_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B7_Data;
extern VAR(Dcm_Did_Block00B8_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B8_Data;
//baoenfei
extern VAR(Dcm_Did_Block00B9_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B9_Data;
extern VAR(Dcm_Did_Block0090_Cfg, DCM_VAR_INIT) Dcm_Did_Block0090_INIT_Data;
extern VAR(Dcm_Did_Block0091_Cfg, DCM_VAR_INIT) Dcm_Did_Block0091_INIT_Data;
extern VAR(Dcm_Did_Block0092_Cfg, DCM_VAR_INIT) Dcm_Did_Block0092_INIT_Data;
extern VAR(Dcm_Did_Block0093_Cfg, DCM_VAR_INIT) Dcm_Did_Block0093_INIT_Data;
extern VAR(Dcm_Did_Block0094_Cfg, DCM_VAR_INIT) Dcm_Did_Block0094_INIT_Data;
extern VAR(Dcm_Did_Block0095_Cfg, DCM_VAR_INIT) Dcm_Did_Block0095_INIT_Data;
extern VAR(Dcm_Did_Block0096_Cfg, DCM_VAR_INIT) Dcm_Did_Block0096_INIT_Data;
extern VAR(Dcm_Did_Block0097_Cfg, DCM_VAR_INIT) Dcm_Did_Block0097_INIT_Data;
extern VAR(Dcm_Did_Block0098_Cfg, DCM_VAR_INIT) Dcm_Did_Block0098_INIT_Data;
extern VAR(Dcm_Did_Block0099_Cfg, DCM_VAR_INIT) Dcm_Did_Block0099_INIT_Data;
extern VAR(Dcm_Did_Block009A_Cfg, DCM_VAR_INIT) Dcm_Did_Block009A_INIT_Data;
extern VAR(Dcm_Did_Block009B_Cfg, DCM_VAR_INIT) Dcm_Did_Block009B_INIT_Data;
extern VAR(Dcm_Did_Block009C_Cfg, DCM_VAR_INIT) Dcm_Did_Block009C_INIT_Data;
extern VAR(Dcm_Did_Block009D_Cfg, DCM_VAR_INIT) Dcm_Did_Block009D_INIT_Data;
extern VAR(Dcm_Did_Block009E_Cfg, DCM_VAR_INIT) Dcm_Did_Block009E_INIT_Data;
extern VAR(Dcm_Did_Block009F_Cfg, DCM_VAR_INIT) Dcm_Did_Block009F_INIT_Data;
extern VAR(Dcm_Did_Block00A0_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A0_INIT_Data;
extern VAR(Dcm_Did_Block00A1_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A1_INIT_Data;
extern VAR(Dcm_Did_Block00A2_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A2_INIT_Data;
extern VAR(Dcm_Did_Block00A3_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A3_INIT_Data;
extern VAR(Dcm_Did_Block00A4_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A4_INIT_Data;
extern VAR(Dcm_Did_Block00A5_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A5_INIT_Data;
extern VAR(Dcm_Did_Block00A6_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A6_INIT_Data;
extern VAR(Dcm_Did_Block00A7_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A7_INIT_Data;
extern VAR(Dcm_Did_Block00A8_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A8_INIT_Data;
extern VAR(Dcm_Did_Block00A9_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A9_INIT_Data;
extern VAR(Dcm_Did_Block00AA_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AA_INIT_Data;
extern VAR(Dcm_Did_Block00AB_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AB_INIT_Data;
extern VAR(Dcm_Did_Block00AC_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AC_INIT_Data;
extern VAR(Dcm_Did_Block00AD_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AD_INIT_Data;
extern VAR(Dcm_Did_Block00AE_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AE_INIT_Data;
extern VAR(Dcm_Did_Block00AF_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AF_INIT_Data;
extern VAR(Dcm_Did_Block00B0_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B0_INIT_Data;
extern VAR(Dcm_Did_Block00B1_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B1_INIT_Data;
extern VAR(Dcm_Did_Block00B2_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B2_INIT_Data;
extern VAR(Dcm_Did_Block00B3_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B3_INIT_Data;
extern VAR(Dcm_Did_Block00B4_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B4_INIT_Data;
extern VAR(Dcm_Did_Block00B5_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B5_INIT_Data;
extern VAR(Dcm_Did_Block00B6_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B6_INIT_Data;
extern VAR(Dcm_Did_Block00B7_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B7_INIT_Data;
extern VAR(Dcm_Did_Block00B8_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B8_INIT_Data;
#endif /* (STD_ON == DCM_SERVICE_22_ENABLED) || (STD_ON == DCM_SERVICE_2E_ENABLED) */

#if ( STD_ON == DCM_SERVICE_11_ENABLED )
/* polyspace +1 DEFECT:HARD_CODED_BUFFER_SIZE [Justified:Unset] "NSCA_Polyspace_Dcm_HARD_CODED_BUFFER_SIZE" */
extern VAR(uint8, DCM_VAR_INIT) Dcm_11_NvMBuf[4];
#endif /* STD_ON == DCM_SERVICE_11_ENABLED */

#if (STD_ON == DCM_SERVICE_27_ENABLED)
extern VAR(uint32, DCM_VAR_INIT) Dcm_27_TimerEngine[DCM_27_LEVEL_NUM + 1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_security_key[DCM_27_MAX_SEED_LENGTH + 1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_security_seed[DCM_27_MAX_SEED_LENGTH + 1U];
extern VAR(Dcm_27_Security_cfg, DCM_VAR_INIT) Dcm_27_Security_Data[DCM_27_LEVEL_NUM + 1U];
extern VAR(Dcm_27_Security_cfg, DCM_VAR_INIT) Dcm_27_Security_INIT_Data[DCM_27_LEVEL_NUM + 1U];
#endif/* STD_ON == DCM_SERVICE_27_ENABLED */

#if (STD_ON == DCM_SERVICE_29_ENABLED)
extern VAR(uint8, DCM_VAR_INIT) Dcm_AuthenticationState[DCM_29_AUT_ROLE_NUM + 1U][DCM_29_AUT_CONN_NUM + 1U];
#endif /* STD_ON == DCM_SERVICE_29_ENABLED */

#if (STD_ON == DCM_SERVICE_2C_ENABLED)
#endif /* STD_ON == DCM_SERVICE_2C_ENABLED */

#if (STD_ON == DCM_SERVICE_86_ENABLED)

extern VAR(Dcm_86_NvMEventInfo_st, DCM_VAR_INIT) Dcm_86_NvMInfo;
#endif /* STD_ON == DCM_SERVICE_86_ENABLED */

#define DCM_STOP_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dcm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define DCM_START_SEC_CONFIG_DATA
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dcm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
#if (STD_ON == DCM_SERVICE_29_ENABLED)
extern CONST(Dcm_29_AutConn_st, DCM_CONFIG_DATA) Dcm_29_AutConn[DCM_29_AUT_CONN_NUM + 1U];
extern CONST(Dcm_29_AutTransCert_st, DCM_CONFIG_DATA) Dcm_29_AutTransCert[DCM_29_AUT_TRANSCERT_NUM + 1U];
extern CONST(Dcm_29_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_29_ServiceInfo[DCM_29_SUBID_NUM + 1U];
extern CONST(Dcm_29_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_29_Dispatcher;
#endif /* STD_ON == DCM_SERVICE_29_ENABLED */

#if (STD_ON == DCM_SERVICE_38_ENABLED)
extern CONST(Dcm_38_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_38_ServiceInfo[DCM_38_SUBID_NUM + 1];
extern CONST(Dcm_38_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_38_Dispatcher;
#endif/* STD_ON == DCM_SERVICE_38_ENABLED */

#if ( STD_ON == DCM_REQUESTMANUFACTURERNOTIFICATION_ENABLED )
extern CONST(Dcm_ServiceRequestManufacturerNotification_st, DCM_CONFIG_DATA) Dcm_ServiceRequestManufacturerNotification;  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#endif /* STD_ON == DCM_REQUESTMANUFACTURERNOTIFICATION_ENABLED */

#if ( STD_ON == DCM_REQUESTSUPPLIERNOTIFICATION_ENABLED )
extern CONST(Dcm_ServiceRequestSupplierNotification_st, DCM_CONFIG_DATA) Dcm_ServiceRequestSupplierNotification;
#endif /* STD_ON == DCM_REQUESTSUPPLIERNOTIFICATION_ENABLED */

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
extern CONST(Dcm_ServiceTableType_st, DCM_CONFIG_DATA) Dcm_DspServiceInfoTable[DCM_NUM_SERVICES + 1];
extern CONST(Dcm_DslBufferType, DCM_CONFIG_DATA) Dcm_DslBuffer[DCM_DSL_BUFFERNUM + 1];
extern CONST(Dcm_DslProtocol_st, DCM_CONFIG_DATA) Dcm_DslProtocol[DCM_DSL_PROTOCOL_NUM + 1];
extern CONST(uint8, DCM_CONFIG_DATA) Dcm_CfgNetConnComMChannelMap[DCM_DSL_CHANNEL_NUM + 1];
extern CONST(Dcm_DSDInfo_st, DCM_CONFIG_DATA) Dcm_gcaDSDInfo;

#if ( STD_ON == DCM_SERVICE_01_ENABLED )
extern CONST(Dcm_01_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_01_PIDInfo[DCM_01_SUBID + 1U];
extern CONST(Dcm_01_PidType_st, DCM_CONFIG_DATA) Dcm_01_SupportPID[DCM_01_SUPPRORTPID + 1U];
extern CONST(Dcm_01_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_01_Dispatcher;
#endif /* STD_ON == DCM_SERVICE_01_ENABLED */

#if ( STD_ON == DCM_SERVICE_02_ENABLED )
extern CONST(Dcm_02_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_02_PIDInfo[DCM_02_SUBID + 1U];
extern CONST(Dcm_02_PidType_st, DCM_CONFIG_DATA) Dcm_02_SupportPID[DCM_02_SUPPRORTPID + 1U];
extern CONST(Dcm_02_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_02_Dispatcher;
#endif /* STD_ON == DCM_SERVICE_02_ENABLED */

#if ( STD_ON == DCM_SERVICE_09_ENABLED )
extern CONST(Dcm_09_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_09_PIDInfo[DCM_09_SUBID + 1U];
extern CONST(Dcm_09_PidType_st, DCM_CONFIG_DATA) Dcm_09_SupportPID[DCM_09_SUPPRORTPID + 1U];
extern CONST(Dcm_09_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_09_Dispatcher;
#endif /* STD_ON == DCM_SERVICE_09_ENABLED */

#if ( STD_ON == DCM_SERVICE_10_ENABLED )
extern CONST(Dcm_10_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_10_ServiceInfo[DCM_10_SUBID + 1U];
extern CONST(Dcm_10_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_10_Dispatcher;

#endif /* STD_ON == DCM_SERVICE_10_ENABLED */

#if ( STD_ON == DCM_SERVICE_11_ENABLED )
extern CONST(Dcm_11_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_11_ServiceInfo[DCM_11_SUBID + 1U];
extern CONST(Dcm_11_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_11_Dispatcher;
#endif /* STD_ON == DCM_SERVICE_11_ENABLED */

#if ( STD_ON == DCM_SERVICE_14_ENABLED )
extern CONST(Dcm_14_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_14_ServiceInfo[DCM_14_SUBID_NUM + 1U];
extern CONST(Dcm_g14DispatherInfo_st, DCM_CONFIG_DATA) Dcm_14_Dispatcher;
#endif /* STD_ON == DCM_SERVICE_14_ENABLED */

#if ( STD_ON == DCM_SERVICE_19_ENABLED )
extern CONST(Dcm_19_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_19_ServiceInfo[DCM_19_SUBIDNUM + 1U];
extern CONST(Dcm_19_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_19_Dispatcher;
#endif /* STD_ON == DCM_SERVICE_19_ENABLED */

#if ( (STD_ON == DCM_SERVICE_22_ENABLED) || (STD_ON == DCM_SERVICE_2E_ENABLED) )
extern CONST(Dcm_22_2E_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_22_2E_ServiceInfo[DCM_NUM_DIDS + 1U];
extern CONST(Dcm_22_2E_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_22_2E_Dispatcher;
#endif /* (STD_ON == DCM_SERVICE_22_ENABLED) || (STD_ON == DCM_SERVICE_2E_ENABLED) */

#if (STD_ON == DCM_SERVICE_27_ENABLED)
extern CONST(Dcm_27_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_27_ServiceInfo[DCM_27_SUB_NUM + 1U];
extern CONST(Dcm_27_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_27_Dispatcher;
#endif/* STD_ON == DCM_SERVICE_27_ENABLED */

#if (STD_ON == DCM_SERVICE_28_ENABLED)
extern CONST(uint8, DCM_CONFIG_DATA) Dcm_28_ChannelId[DCM_28_CHANNLE_NUM + 1U];
extern CONST(Dcm_28_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_28_ServiceInfoTable[DCM_28_SUBID_NUM + 1U];
extern CONST(uint8, DCM_CONFIG_DATA) Dcm_28_ControlState[DCM_28_CONTROL_STATE_NUM];
extern CONST(Dcm_28_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_28_Dispatcher;
#endif/* STD_ON == DCM_SERVICE_28_ENABLED */

#if (STD_ON == DCM_SERVICE_2F_ENABLED)
extern CONST(Dcm_2F_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_2F_ServiceInfo[DCM_2F_MAX_SUB_DID_NUM + 1U];
extern CONST(Dcm_2F_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_2F_Dispatcher;
#endif/* STD_ON == DCM_SERVICE_2F_ENABLED */

#if (STD_ON == DCM_SERVICE_31_ENABLED)
extern CONST(Dcm_31_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_31_ServiceInfo[DCM_31_SUBID_NUM + 1U];
extern CONST(Dcm_31_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_31_Dispatcher;
#endif/* STD_ON == DCM_SERVICE_31_ENABLED */

#if (STD_ON == DCM_SERVICE_3E_ENABLED)
extern CONST(Dcm_3E_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_3E_ServiceInfo[DCM_3E_SUBID + 1U];
extern CONST(Dcm_3E_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_3E_Dispatcher;
#endif/* STD_ON == DCM_SERVICE_3E_ENABLED */

#if ( STD_ON == DCM_SERVICE_85_ENABLED )
extern CONST(Dcm_85_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_85_ServiceInfo[DCM_85_SUBID_NUM + 1U];
extern CONST(Dcm_85_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_85_Dispatcher;
#endif /* STD_ON == DCM_SERVICE_85_ENABLED */

#if (STD_ON == DCM_SERVICE_87_ENABLED)
extern CONST(Dcm_87_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_87_ServiceInfo[DCM_87_SUBID_NUM + 1U];
extern CONST(Dcm_87_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_87_Dispatcher;
#endif /* STD_ON == DCM_SERVICE_87_ENABLED */

extern CONST(Dcm_DspMemoryInfoType_st, DCM_CONFIG_DATA) Dcm_DspReadMemoryInfo[DCM_DSP_READMEMORY_NUM + 1U];
extern CONST(Dcm_DspMemoryInfoType_st, DCM_CONFIG_DATA) Dcm_DspWriteMemoryInfo[DCM_DSP_WRITEMEMORY_NUM + 1U];

#if (STD_ON == DCM_SERVICE_2A_ENABLED)
extern CONST(Dcm_2A_Channel_st, DCM_CONFIG_DATA) Dcm_2A_Channel[DCM_2A_TX_CHANNEL_NUM + 1U];
extern CONST(uint16, DCM_CONFIG_DATA) Dcm_2A_TransmissionRate[DCM_2A_TRANSMODE_SIZE + 1U];
extern CONST(Dcm_2A_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_2A_ServiceInfo[DCM_2A_NUM_DIDS + 1U];
extern CONST(Dcm_2A_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_2A_Dispatcher;
#endif /* STD_ON == DCM_SERVICE_2A_ENABLED */

#if (STD_ON == DCM_SERVICE_2C_ENABLED)
extern CONST(uint8, DCM_CONFIG_DATA) Dcm_2C_SubFunc[DCM_2C_SUB_NUM_DIDS];
extern CONST(Dcm_2C_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_2C_ServiceInfo[DCM_2C_NUM_DIDS + 1U];
extern CONST(Dcm_2C_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_2C_Dispatcher;


#endif /* STD_ON == DCM_SERVICE_2C_ENABLED */

#if (STD_ON == DCM_SERVICE_86_ENABLED)
extern CONST(Dcm_86_DslProtocol_st, DCM_CONFIG_DATA) Dcm_86_DslProtocol[DCM_86_ROE_DSL_NUM + 1U];
extern CONST(Dcm_86_RequestMsg_st, DCM_CONFIG_DATA) Dcm_86_RequestMsg[DCM_86_EVENTTYPE_NUM];
extern CONST(uint8, DCM_CONFIG_DATA) Dcm_86_WindowTime[DCM_86_EVENTWINDOWTIME_NUM + 1U];
extern CONST(Dcm_86_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_86_ServiceInfo[DCM_86_EVENT_NUM + 1U];
extern CONST(Dcm_86_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_86_Dispatcher;
#endif /* STD_ON == DCM_SERVICE_86_ENABLED */



#define DCM_STOP_SEC_CONFIG_DATA
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dcm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/
#define DCM_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dcm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if ( (STD_ON == DCM_SERVICE_10_ENABLED) || (STD_ON == DCM_SERVICE_28_ENABLED) )
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_ControlCommunication(uint8 subfunc, uint8 comtype);  /* PRQA S 3451 */ /* NSCA_QAC_Dcm_Rule8.5 */
#endif

#define DCM_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dcm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#endif /* DCM_LCFG_H_ */

