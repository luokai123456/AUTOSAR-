/*
********************************************************************************
*
*  File name: BswM_Cfg.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : yong.zhang/2018.12.13
* Change: New created
* Cause: New
********************************************************************************
*/
#ifndef BSWM_CFG_H_
#define BSWM_CFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* PolySpace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define BSWM_NO_ACTIONLIST           	(255U)   /* Default number of action list */
#define BSWM_NO_IMMEUSER        		(255U)   /* No immediate user */

#define BSWM_REQUEST_IDLE                 (0x00U)
#define BSWM_REQUEST_QUEUED               (0x01U)
#define BSWM_REQUEST_PROCESSED            (0x02U)
#define BSWM_REQUEST_PENDING              (0x03U)
#define BSWM_REQUEST_QUEUE_RELEASE        (0x04U)

#define BSWM_ACTIONLIST_IDLE              (0x00U)
#define BSWM_ACTIONLIST_PENDING           (0x01U)
#define BSWM_ACTIONLIST_BLOCKED           (0xFFU)


#define BSWM_MAINFUNCTIONPERIOD                                             (5U)
#define BSWM_CANSMENABLED                                                   (STD_ON)
#define BSWM_CANSMICOMENABLED                                               (STD_OFF)
#define BSWM_COMMENABLED                                                    (STD_ON)
#define BSWM_DCMENABLED                                                     (STD_ON)
#define BSWM_DEVERRORDETECT                                                 (STD_ON)
#define BSWM_ECUMENABLED                                                    (STD_ON)
#define BSWM_ETHSMENABLED                                                   (STD_OFF)
#define BSWM_FRSMENABLED                                                    (STD_OFF)
#define BSWM_GENERICREQUESTENABLED                                          (STD_ON)
#define BSWM_IPDU_GROUP_CONTROL                                             (STD_ON)
#define BSWM_J1939DCMENABLED                                                (STD_OFF)
#define BSWM_J1939NMENABLED                                                 (STD_OFF)
#define BSWM_J1939RMENABLED                                                 (STD_OFF)
#define BSWM_LINSMENABLED                                                   (STD_ON)
#define BSWM_LINTPENABLED                                                   (STD_OFF)
#define BSWM_NMENABLED                                                      (STD_ON)
#define BSWM_NVMENABLED                                                     (STD_ON)
#define BSWM_SCHMENABLED                                                    (STD_OFF)
#define BSWM_SDENABLED                                                      (STD_OFF)
#define BSWM_VERSIONINFOAPI                                                 (STD_OFF)
#define BSWM_WDGMENABLED                                                    (STD_OFF)

#define BSWM_GENERIC_RP_PowerState                                          (112U)
#define BSWM_GENERIC_RP_Reset                                               (113U)
#define BSWM_GENERIC_RP_SWC_Delay_PowerOffPort                              (115U)
#define BSWM_GENERIC_RP_State                                               (111U)
#define BSWM_GENERIC_RP_ValtState                                           (114U)

#define BSWM_GENERICVALUE_Cond_StatelsValtHigh                              (0x0003U)
#define BSWM_GENERICVALUE_Cond_StatelsValtLow                               (0x0002U)
#define BSWM_GENERICVALUE_Cond_StatelsValtNom                               (0x0001U)
#define BSWM_GENERICVALUE_STATE_Boot_Reset                                  (0x0003U)
#define BSWM_GENERICVALUE_STATE_Hard_Reset                                  (0x0004U)
#define BSWM_GENERICVALUE_STATE_Init                                        (0x0001U)
#define BSWM_GENERICVALUE_STATE_NO_Reset                                    (0x0001U)
#define BSWM_GENERICVALUE_STATE_POWER_OFF                                   (0x0001U)
#define BSWM_GENERICVALUE_STATE_POWER_ON                                    (0x0002U)
#define BSWM_GENERICVALUE_STATE_PostRun                                     (0x0003U)
#define BSWM_GENERICVALUE_STATE_Reset                                       (0x0005U)
#define BSWM_GENERICVALUE_STATE_Run                                         (0x0002U)
#define BSWM_GENERICVALUE_STATE_Shutdown                                    (0x0004U)
#define BSWM_GENERICVALUE_STATE_Soft_Reset                                  (0x0002U)
#define BSWM_GENERICVALUE_SWC_PwrOffDlyFlg_Mp_OFF                           (0x0001U)
#define BSWM_GENERICVALUE_SWC_PwrOffDlyFlg_Mp_ON                            (0x0000U)

#define BSWM_TMR_RP_RunTimer                                                1U
#define BSWM_TMR_RP_WriteTimer                                              0U

#define BSWM_ID_AL_AL_CANSM_IpduStart_C_CAN                                 (17U)
#define BSWM_ID_AL_AL_CANSM_IpduStart_EV_CAN                                (11U)
#define BSWM_ID_AL_AL_CANSM_IpduStart_HCM_CAN                               (15U)
#define BSWM_ID_AL_AL_CANSM_IpduStart_J1939_CAN                             (9U)
#define BSWM_ID_AL_AL_CANSM_IpduStart_PT_CAN                                (19U)
#define BSWM_ID_AL_AL_CANSM_IpduStart_XCP_CAN                               (13U)
#define BSWM_ID_AL_AL_CANSM_IpduStop_C_CAN                                  (18U)
#define BSWM_ID_AL_AL_CANSM_IpduStop_EV_CAN                                 (12U)
#define BSWM_ID_AL_AL_CANSM_IpduStop_HCM_CAN                                (16U)
#define BSWM_ID_AL_AL_CANSM_IpduStop_J1939_CAN                              (10U)
#define BSWM_ID_AL_AL_CANSM_IpduStop_PT_CAN                                 (20U)
#define BSWM_ID_AL_AL_CANSM_IpduStop_XCP_CAN                                (14U)
#define BSWM_ID_AL_AL_COMM_NM_FullCOMM                                      (23U)
#define BSWM_ID_AL_AL_COMM_NM_NoCOMM                                        (24U)
#define BSWM_ID_AL_AL_COMM_NoNM_FullCOMM                                    (25U)
#define BSWM_ID_AL_AL_COMM_NoNM_NoCOMM                                      (26U)
#define BSWM_ID_AL_AL_Empty                                                 (4U)
#define BSWM_ID_AL_AL_InitToRun                                             (0U)
#define BSWM_ID_AL_AL_LinScheduleSwitch                                     (8U)
#define BSWM_ID_AL_AL_PostRunToRun                                          (2U)
#define BSWM_ID_AL_AL_PostRunToShutdown                                     (3U)
#define BSWM_ID_AL_AL_RunToBootReset                                        (6U)
#define BSWM_ID_AL_AL_RunToHardReset                                        (7U)
#define BSWM_ID_AL_AL_RunToPostRun                                          (1U)
#define BSWM_ID_AL_AL_RunToSoftReset                                        (5U)
#define BSWM_ID_AL_AL_VOL_COM_OFF                                           (21U)
#define BSWM_ID_AL_AL_VOL_COM_ON                                            (22U)

#define BSWM_ID_RULE_RL_COMM_IpduStart_C_CAN                                (24U)
#define BSWM_ID_RULE_RL_COMM_IpduStart_EV_CAN                               (21U)
#define BSWM_ID_RULE_RL_COMM_IpduStart_HCM_CAN                              (23U)
#define BSWM_ID_RULE_RL_COMM_IpduStart_J1939_CAN                            (20U)
#define BSWM_ID_RULE_RL_COMM_IpduStart_PT_CAN                               (25U)
#define BSWM_ID_RULE_RL_COMM_IpduStart_XCP_CAN                              (22U)
#define BSWM_ID_RULE_RL_COMM_IpduStop_C_CAN                                 (18U)
#define BSWM_ID_RULE_RL_COMM_IpduStop_EV_CAN                                (15U)
#define BSWM_ID_RULE_RL_COMM_IpduStop_HCM_CAN                               (17U)
#define BSWM_ID_RULE_RL_COMM_IpduStop_J1939_CAN                             (14U)
#define BSWM_ID_RULE_RL_COMM_IpduStop_PT_CAN                                (19U)
#define BSWM_ID_RULE_RL_COMM_IpduStop_XCP_CAN                               (16U)
#define BSWM_ID_RULE_RL_COMM_NM_FullCOMM                                    (9U)
#define BSWM_ID_RULE_RL_COMM_NM_NoCOMM                                      (8U)
#define BSWM_ID_RULE_RL_COMM_NoNM_FullCOMM                                  (10U)
#define BSWM_ID_RULE_RL_COMM_NoNM_NoCOMM                                    (11U)
#define BSWM_ID_RULE_RL_InitToRun                                           (0U)
#define BSWM_ID_RULE_RL_LIN_StartSchedule                                   (7U)
#define BSWM_ID_RULE_RL_PostRunToRun                                        (2U)
#define BSWM_ID_RULE_RL_PostRunToShutdown                                   (3U)
#define BSWM_ID_RULE_RL_RunToBootReset                                      (5U)
#define BSWM_ID_RULE_RL_RunToHardReset                                      (6U)
#define BSWM_ID_RULE_RL_RunToPostRun                                        (1U)
#define BSWM_ID_RULE_RL_RunToSoftReset                                      (4U)
#define BSWM_ID_RULE_RL_VOL_StartCOM                                        (12U)
#define BSWM_ID_RULE_RL_VOL_StopCOM                                         (13U)

#define BSWM_BSWMCONFIG_SIZE                                                (1U)
#define BSWM_MODENOTIFICATION_FUNC                                          (STD_OFF)
#define BSWM_SIZE_ACTIONLIST                                                (27U)
#define BSWM_SIZE_CANSMICOM_CHANNEL                                         (0U)
#define BSWM_SIZE_CANSM_CHANNEL                                             (0U)
#define BSWM_SIZE_COMMPNC_CHANNEL                                           (0U)
#define BSWM_SIZE_COMM_CHANNEL                                              (7U)
#define BSWM_SIZE_CONSUMEDEVENTGROUP                                        (0U)
#define BSWM_SIZE_DCM_CHANNEL                                               (7U)
#define BSWM_SIZE_DEFERRED_RULE                                             (20U)
#define BSWM_SIZE_ECUM_CHANNEL                                              (0U)
#define BSWM_SIZE_ECUM_WAKEUP                                               (0U)
#define BSWM_SIZE_ETHSM_CHANNEL                                             (0U)
#define BSWM_SIZE_EVENTHANDLER                                              (0U)
#define BSWM_SIZE_FRSM                                                      (0U)
#define BSWM_SIZE_GENERIC                                                   (5U)
#define BSWM_SIZE_IMMEDIATE_USER                                            (4U)
#define BSWM_SIZE_J1939DCM_CHANNEL                                          (0U)
#define BSWM_SIZE_J1939NM_CHANNEL                                           (0U)
#define BSWM_SIZE_LINSMSCHEDULE                                             (1U)
#define BSWM_SIZE_LINSM_CHANNEL                                             (1U)
#define BSWM_SIZE_LINTP_CHANNEL                                             (0U)
#define BSWM_SIZE_NVM_BLOCK                                                 (0U)
#define BSWM_SIZE_NVM_JOB                                                   (0U)
#define BSWM_SIZE_RULE                                                      (26U)
#define BSWM_SIZE_RULEIND                                                   (45U)
#define BSWM_SIZE_SDCLIENTSERVICE                                           (0U)
#define BSWM_SIZE_TIMER                                                     (2U)
#define BSWM_SWCMODEREQUESTUPDATE_FUNC                                      (STD_OFF)
#define BSWM_COREIDMAPPING_SIZE                                             (6U)
#define BSWM_MULTIPARTITION                                                 (STD_OFF)
#define BSWM_SWCMODEREQUEST_DATA_INIT                                       (STD_OFF)

#define BSWM_RULEHANDLERENABLE (STD_OFF)
/* PolySpace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* It is possible to configure any user number from 0 to 65535. */
typedef uint16 BswM_UserType;
typedef uint16 BswM_ModeType;
/* PolySpace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_BswM_2.3" */
typedef uint8 BswM_HandleType;

/* PolySpace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_BswM_2.3" */
typedef void (*BswM_InitActionFuncType)(void);
typedef uint8 (*BswM_RuleTableFctPtrType)(void);
typedef Std_ReturnType (*BswM_ActionListFuncType)(void);

/* type used in BswM_ActionLists. */
/* PolySpace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_BswM_2.4" */
typedef struct sBswM_ActionListsType
{
  BswM_ActionListFuncType FctPtrOfActionLists; /* Pointer to the array list function. */
} BswM_ActionListsType;

typedef struct
{
    uint32 ExternalId;              /* External id of BswMCanSMIndication. */
    uint8 ImmediateUserEndIdx;      /* the end index of the 0:n relation pointing to BswM_ImmediateUser */
    uint8 ImmediateUserStartIdx;    /* the start index of the 0:n relation pointing to BswM_ImmediateUser */
    uint8 PartitionId;              /* This references the partition the BswM shall run inside. */
    uint8 InitValue;
} BswM_ChannelMappingType;

/* type used in BswM_CanSMIcomChannelMapping. */
typedef struct
{
    uint32 ExternalId;              /* External id of BswMCanSMIndication. */
    uint8 ErrorType;
    uint8 ImmediateUserEndIdx;      /* the end index of the 0:n relation pointing to BswM_ImmediateUser */
    uint8 ImmediateUserStartIdx;    /* the start index of the 0:n relation pointing to BswM_ImmediateUser */
    uint8 PartitionId;
    uint8 InitValue;
/* PolySpace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_BswM_2.3" */
} BswM_CanSMIcomChannelMappingType;

/* type used in BswM_CanSMIcomChannelMapping. */
typedef struct
{
    uint32 ExternalId;              /* External id of J1939NmNetwork. */
    uint8 NodeId;
    uint8 ImmediateUserEndIdx;      /* the end index of the 0:n relation pointing to BswM_ImmediateUser */
    uint8 ImmediateUserStartIdx;    /* the start index of the 0:n relation pointing to BswM_ImmediateUser */
    uint8 PartitionId;
    uint8 InitValue;
/* PolySpace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_BswM_2.3" */
} BswM_J1939NmStateChangeMappingType;
/* type used in BswM_DeferredRules. */
typedef struct
{
    uint8 PartitionId;
    uint8 RulesIdxOfDeferredRules;    /* the index of the 1:1 relation pointing to BswM_Rules. */
} BswM_DeferredRulesType;

/* type used in BswM_GenericMapping */
typedef struct
{
    uint32 ExternalId;              /* External id of BswMGenericRequest. */
    uint8 ImmediateUserEndIdx;      /* the end index of the 0:n relation pointing to BswM_ImmediateUser */
    uint8 ImmediateUserStartIdx;    /* the start index of the 0:n relation pointing to BswM_ImmediateUser */
    uint8 PartitionId;              /* the partition id */
    uint8 PartitionIdx;             /* the partition configured index */
    uint16 InitValue;               /* Initialization value of port. */
} BswM_GenericMappingType;

/* type used in BswM_ImmediateUser */
typedef struct
{
    uint8 MaskedBits;          /* contains bitcoded the boolean data of BswM_OnInitOfImmediateUser, BswM_RulesIndUsedOfImmediateUser */
    uint8 RulesIndEndIdx;      /* the end index of the 0:n relation pointing to BswM_RulesInd */
    uint8 RulesIndStartIdx;    /* the start index of the 0:n relation pointing to BswM_RulesInd */
} BswM_ImmediateUserType;

/* type used in BswM_Rules */
typedef struct
{
    BswM_RuleTableFctPtrType FctPtrOfRules; /* Pointer to the rule function which does the arbitration. */
} BswM_RulesType;

/* type to access BswM_ActionListQueue in an index and symbol based style. */
/* PolySpace +1 MISRA-C3:19.2 [Justified:Unset] "NSCA_Polyspace_BswM_19.2" */
typedef union 
{
    uint8 raw[BSWM_SIZE_ACTIONLIST];
/* PolySpace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_BswM_2.3" */
} uBswM_ActionListQueueType;

/* These type definitions are used for value representations in root arrays. */
/* PolySpace +2 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_BswM_2.4" */
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_BswM_Dir4.8" */
typedef struct sBswM_PCConfigType
{
  uint8 BswM_PCConfigNeverUsed;
} BswM_PCConfigType;
typedef BswM_PCConfigType BswM_ConfigType;

typedef struct
{
    uint8 PartitionId;
    boolean Initialized;
}BswM_InitState_st;

typedef struct
{
    uint8 PartitionId;
    uint8 ActionListState;
}BswM_ActionListState_st;

typedef struct
{
	uint8 PartitionId;
    uint8 Timestate;
	uint32 Timevalue;
} BswM_TimerValue_st;

typedef struct
{
	uint8 PartitionId;
    uint8 RequestMode;
} BswM_ModeRequest_st;

typedef struct
{
    uint8 PartitionId;
    CoreIdType CoreId;
}BswM_CoreIdMapping_st;

typedef struct
{
    uint8 PartitionId; 
    uint8 ApplNum;
    const uint8 *ApplId;
}BswM_ApplMapping_st;

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define BSWM_START_SEC_GLOBAL_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h"

/* PolySpace-begin MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_BswM_2.4" */
#if( BSWM_SIZE_ETHSM_CHANNEL > 0U )
/* Variable to store current mode of BswMComMIndication mode request ports. */
extern VAR(uint8, BSWM_VAR_NO_INIT) BswM_EthSMChannelState[BSWM_SIZE_ETHSM_CHANNEL];
#endif

#if( BSWM_SIZE_COMMPNC_CHANNEL > 0U )
extern VAR(uint8, BSWM_VAR_NO_INIT) BswM_ComMPncChannelState[BSWM_SIZE_COMMPNC_CHANNEL];
#endif

#if( BSWM_SIZE_CANSM_CHANNEL > 0U )
/* Variable to store current mode of BswMCanSMIndication mode request ports. */
extern VAR(uint8, BSWM_VAR_NO_INIT) BswM_CanSMChannelState[BSWM_SIZE_CANSM_CHANNEL];
#endif

#if( BSWM_SIZE_COMM_CHANNEL > 0U )
/* Variable to store current mode of BswMComMIndication mode request ports. */
extern VAR(uint8, BSWM_VAR_NO_INIT) BswM_ComMChannelState[BSWM_SIZE_COMM_CHANNEL];
#endif

#if( BSWM_SIZE_GENERIC > 0U )
/* Variable to store current mode of BswMGenericRequest mode request ports. */
/* PolySpace-begin MISRA-C3:8.6 [Justified:Unset] "NSCA_Polyspace_BswM_8.6" */
extern VAR(uint16, BSWM_VAR_NO_INIT) BswM_GenericState[BSWM_SIZE_GENERIC];
#endif

#if( BSWM_SIZE_NVM_JOB > 0U )
/* Variable to store current mode of BswMNvMJobModeIndication mode request ports. */
/* PolySpace-begin MISRA-C3:8.6 [Justified:Unset] "NSCA_Polyspace_BswM_8.6" */
extern VAR(uint8, BSWM_VAR_NO_INIT) BswM_NvMJobState[BSWM_SIZE_NVM_JOB];
#endif

#if( BSWM_SIZE_NVM_BLOCK > 0U )
/* Variable to store current mode of BswMNvMJobModeIndication mode request ports. */
extern VAR(uint8, BSWM_VAR_NO_INIT) BswM_NvMBlockState[BSWM_SIZE_NVM_BLOCK];
#endif

#if( BSWM_SIZE_ECUM_CHANNEL > 0U )
/* Variable to store current mode of BswMEcuMIndication mode request ports. */
extern VAR(uint8, BSWM_VAR_NO_INIT) BswM_EcuMChannelState[BSWM_SIZE_ECUM_CHANNEL];
#endif

#if( BSWM_SIZE_ECUM_WAKEUP > 0U )
/* Variable to store current mode of BswMEcuMWakeUp mode request ports. */
extern VAR(uint8, BSWM_VAR_NO_INIT) BswM_EcuMWakeupState[BSWM_SIZE_ECUM_WAKEUP];
#endif

#if( BSWM_SIZE_DCM_CHANNEL > 0U )
/* Variable to store current mode of BswMDcm mode request ports. */
extern VAR(uint8, BSWM_VAR_NO_INIT) BswM_DcmChannelState[BSWM_SIZE_DCM_CHANNEL];
#endif

#if( BSWM_SIZE_SDCLIENTSERVICE > 0U )
extern VAR(uint8, BSWM_VAR_NO_INIT) BswM_SdClientServiceState[BSWM_SIZE_SDCLIENTSERVICE];
#endif

#if( BSWM_SIZE_CONSUMEDEVENTGROUP > 0U )
extern VAR(uint8, BSWM_VAR_NO_INIT) BswM_SdConsumedEventGroupState[BSWM_SIZE_CONSUMEDEVENTGROUP];
#endif

#if( BSWM_SIZE_EVENTHANDLER > 0U )
extern VAR(uint8, BSWM_VAR_NO_INIT) BswM_SdEventHandlerState[BSWM_SIZE_EVENTHANDLER];
#endif

#if( BSWM_SIZE_FRSM > 0U )
extern VAR(uint8, BSWM_VAR_NO_INIT) BswM_FrSMState[BSWM_SIZE_FRSM];
#endif

#if( BSWM_SIZE_LINSMSCHEDULE > 0U )
extern VAR(uint8, BSWM_VAR_NO_INIT) BswM_LinSMScheduleState[BSWM_SIZE_LINSMSCHEDULE];
#endif

#if( BSWM_SIZE_LINSM_CHANNEL > 0U )
extern VAR(uint8, BSWM_VAR_NO_INIT) BswM_LinSMChannelState[BSWM_SIZE_LINSM_CHANNEL];
#endif

#if( BSWM_SIZE_CANSMICOM_CHANNEL > 0U )
/* Variable to store current mode of BswMCanSMIcomIndication mode request ports. */
extern VAR(uint8, BSWM_VAR_NO_INIT) BswM_CanSMIcomChannelState[BSWM_SIZE_CANSMICOM_CHANNEL];
#endif

#if( BSWM_SIZE_LINTP_CHANNEL > 0U )
extern VAR(uint8, BSWM_VAR_NO_INIT) BswM_LinTpChannelState[BSWM_SIZE_LINTP_CHANNEL];
#endif

#if( BSWM_SIZE_J1939DCM_CHANNEL > 0U )
extern VAR(uint16, BSWM_VAR_NO_INIT) BswM_J1939DcmChannelState[BSWM_SIZE_J1939DCM_CHANNEL];
#endif

#if( BSWM_SIZE_J1939NM_CHANNEL > 0U )
extern VAR(uint8, BSWM_VAR_NO_INIT) BswM_J1939NmChannelState[BSWM_SIZE_J1939NM_CHANNEL];
#endif
#define BSWM_STOP_SEC_GLOBAL_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h"

#define BSWM_START_SEC_GLOBAL_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h"
#if( BSWM_BSWMCONFIG_SIZE > 0U )
extern VAR(BswM_InitState_st,BSWM_VAR_INIT) BswM_Initialized[BSWM_BSWMCONFIG_SIZE];
#endif

#if( BSWM_SIZE_ACTIONLIST > 0U )
/* Variable to store action lists which shall be executed. */
extern VAR(BswM_ActionListState_st, BSWM_VAR_INIT) BswM_ActionListQueue[BSWM_SIZE_ACTIONLIST];
#endif

#if( BSWM_SIZE_IMMEDIATE_USER > 0U )
/* Variable to store an immediate mode request which must be queued because of a current active arbitration. */
extern VAR(BswM_ModeRequest_st, BSWM_VAR_INIT) BswM_ModeRequestQueue[BSWM_SIZE_IMMEDIATE_USER];
#endif

#if( BSWM_SIZE_TIMER > 0U )
/* Variable to store current state of BswMTimer (STARTED, STOPPER OR EXPIRED). */
extern VAR(BswM_TimerValue_st, BSWM_VAR_INIT) BswM_TimerState[BSWM_SIZE_TIMER];
#endif
/* PolySpace-end MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_BswM_2.4" */

#define BSWM_STOP_SEC_GLOBAL_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h"

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define BSWM_START_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h"
#if( BSWM_SIZE_ACTIONLIST > 0U )
extern CONST(BswM_ActionListsType, BSWM_CONFIG_DATA) BswM_ActionLists[BSWM_SIZE_ACTIONLIST];
#endif

#if( BSWM_SIZE_DEFERRED_RULE > 0U )
extern CONST(BswM_DeferredRulesType, BSWM_CONFIG_DATA) BswM_DeferredRules[BSWM_SIZE_DEFERRED_RULE];
#endif

#if( BSWM_SIZE_IMMEDIATE_USER > 0U )
/* Contains all immediate request ports. */
extern CONST(BswM_ImmediateUserType, BSWM_CONFIG_DATA) BswM_ImmediateUser[BSWM_SIZE_IMMEDIATE_USER];
#endif

#if( BSWM_SIZE_RULE > 0U )
/* Pointer to the rule function which does the arbitration. */
extern CONST(BswM_RulesType, BSWM_CONFIG_DATA) BswM_Rules[BSWM_SIZE_RULE];
#endif

#if( BSWM_SIZE_RULEIND > 0U )
/* the indexes of the 1:1 sorted relation pointing to BswM_Rules. */
extern CONST(uint8, BSWM_CONFIG_DATA) BswM_RulesInd[BSWM_SIZE_RULEIND];
#endif

#if( BSWM_SIZE_CANSM_CHANNEL > 0U )
/* Maps the external id of BswMCanSMIndication to an internal id and references immediate request ports. */
extern CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_CanSMChannelMapping[BSWM_SIZE_CANSM_CHANNEL];
#endif

#if( BSWM_SIZE_CANSMICOM_CHANNEL > 0U )
extern CONST(BswM_CanSMIcomChannelMappingType, BSWM_CONFIG_DATA) BswM_CanSMIcomChannelMapping[BSWM_SIZE_CANSMICOM_CHANNEL];
#endif

#if( BSWM_SIZE_COMM_CHANNEL > 0U )
/* Maps the external id of BswMComMIndication to an internal id and references immediate request ports. */
extern CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_ComMChannelMapping[BSWM_SIZE_COMM_CHANNEL];
#endif

#if( BSWM_SIZE_ETHSM_CHANNEL > 0U )
extern CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_EthSMChannelMapping[BSWM_SIZE_ETHSM_CHANNEL];
#endif

#if( BSWM_SIZE_COMMPNC_CHANNEL > 0U )
extern CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_ComMPncChannelMapping[BSWM_SIZE_COMMPNC_CHANNEL];
#endif

#if( BSWM_SIZE_ECUM_CHANNEL > 0U )
/* Maps the external id of BswMEcuMIndication to an internal id and references immediate request ports. */
extern CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_EcuMChannelMapping[BSWM_SIZE_ECUM_CHANNEL];
#endif

#if( BSWM_SIZE_ECUM_WAKEUP > 0U )
extern CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_EcuMWakeUpMapping[BSWM_SIZE_ECUM_WAKEUP];
#endif

#if( BSWM_SIZE_GENERIC > 0U )
/* Maps the external id of BswMGenericRequest to an internal id and references immediate request ports. */
extern CONST(BswM_GenericMappingType, BSWM_CONFIG_DATA) BswM_GenericMapping[BSWM_SIZE_GENERIC];
#endif

#if( BSWM_SIZE_NVM_JOB > 0U )
extern CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_NvMJobMapping[BSWM_SIZE_NVM_JOB];
#endif

#if( BSWM_SIZE_NVM_BLOCK > 0U )
extern CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_NvMBlockMapping[BSWM_SIZE_NVM_BLOCK];
#endif

#if( BSWM_SIZE_ECUM_WAKEUP > 0U )
extern CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_EcuMWakeUpMapping[BSWM_SIZE_ECUM_WAKEUP];
#endif

#if( BSWM_SIZE_DCM_CHANNEL > 0U )
extern CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_DcmChannelMapping[BSWM_SIZE_DCM_CHANNEL];
#endif

#if( BSWM_SIZE_SDCLIENTSERVICE > 0U )
extern CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_SdClientServiceMapping[BSWM_SIZE_SDCLIENTSERVICE];
#endif

#if( BSWM_SIZE_CONSUMEDEVENTGROUP > 0U )
extern CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_SdConsumedEventGroupMapping[BSWM_SIZE_CONSUMEDEVENTGROUP];
#endif

#if( BSWM_SIZE_EVENTHANDLER > 0U )
extern CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_SdEventHandlerMapping[BSWM_SIZE_EVENTHANDLER];
#endif

#if( BSWM_SIZE_FRSM > 0U )
extern CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_FrSMMapping[BSWM_SIZE_FRSM];
#endif

#if( BSWM_SIZE_LINSMSCHEDULE > 0U )
extern CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_LinSMScheduleMapping[BSWM_SIZE_LINSMSCHEDULE];
#endif

#if( BSWM_SIZE_LINSM_CHANNEL > 0U )
extern CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_LinSMChannelMapping[BSWM_SIZE_LINSM_CHANNEL];
#endif

#if( BSWM_SIZE_LINTP_CHANNEL > 0U )
extern CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_LinTpChannelMapping[BSWM_SIZE_LINTP_CHANNEL];
#endif

#if( BSWM_SIZE_J1939DCM_CHANNEL > 0U )
extern CONST( BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_J1939DcmChannelMapping[BSWM_SIZE_J1939DCM_CHANNEL];
#endif

#if( BSWM_SIZE_J1939NM_CHANNEL > 0U )
extern CONST( BswM_J1939NmStateChangeMappingType, BSWM_CONFIG_DATA) BswM_J1939NmChannelMapping[BSWM_SIZE_J1939NM_CHANNEL];
#endif

#if( BSWM_MULTIPARTITION == STD_ON )
extern CONST(BswM_CoreIdMapping_st, BSWM_CONFIG_DATA) BswM_CoreIdMapping[BSWM_COREIDMAPPING_SIZE];
extern CONST(uint8, BSWM_CONFIG_DATA) BswM_PartApplMapping0[1];
extern CONST(BswM_ApplMapping_st, BSWM_CONFIG_DATA) BswM_ApplMapping[BSWM_BSWMCONFIG_SIZE];
#endif

#define BSWM_STOP_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h"
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/
#define BSWM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h"
#if( BSWM_IPDU_GROUP_CONTROL==STD_ON )
extern void BswM_ExecuteIpduGroupControl(void);
#endif

#if ( BSWM_SWCMODEREQUEST_DATA_INIT == STD_ON )
extern FUNC(void, BSWM_CODE) BswM_SwcModeRequestDataInit
(
    uint8 partitionId
);
#endif

extern FUNC(void, BSWM_CODE)BswM_BootReset_Action(void);
extern FUNC(void, BSWM_CODE)BswM_CANDriver_OFF(void);
extern FUNC(void, BSWM_CODE)BswM_CANDriver_ON(void);
extern FUNC(void, BSWM_CODE)BswM_Dem_Shutdown(void);
extern FUNC(void, BSWM_CODE)BswM_HardReset_Action(void);
extern FUNC(void, BSWM_CODE)BswM_InitToRun_Action(void);
extern FUNC(void, BSWM_CODE)BswM_PostRunToRun_Action(void);
extern FUNC(void, BSWM_CODE)BswM_PostRunToShutdown_Action(void);
extern FUNC(void, BSWM_CODE)BswM_RunToPostRun_Action(void);
extern FUNC(void, BSWM_CODE)BswUserCallout_SWC_Delay_PowerOffPort(void);
extern FUNC(void, BSWM_CODE)BswM_SoftReset_Action(void);
#define BSWM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h"
#endif /* BSWM_CFG_H_ */

