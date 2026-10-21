/*
********************************************************************************
*
*  File name: BswM_Lcfg.c
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
* Version: 3.1
* Author/Date : yong.zhang/2020.4.26
* Change: Add new configration item
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Include
********************************************************************************
*/
#include "BswM.h"

#if( BSWM_IPDU_GROUP_CONTROL == STD_ON )
#include "Com.h"
#endif

#include "BswM_Cfg.h"
#include "Rte_BswM.h"

#if( BSWM_ECUMENABLED == STD_ON )
#include "EcuM.h"
#endif

#if( BSWM_NVMENABLED == STD_ON )
#include "NvM.h"
#endif

#if( BSWM_CANSMENABLED == STD_ON )
#include "CanSM_BswM.h"
#endif

#if( BSWM_LINSMENABLED == STD_ON )
#include "LinSM.h"
#endif

#if( BSWM_LINTPENABLED == STD_ON )
#include "LinTp.h"
#endif

#if( BSWM_SDENABLED == STD_ON )
#include "Sd.h"
#endif

#if( BSWM_ETHSMENABLED == STD_ON)
#include "EthSM.h"
#endif

#if( BSWM_DCMENABLED == STD_ON)
#include "Dcm.h"
#endif

#if( BSWM_FRSMENABLED == STD_ON)
#include "FrSM.h"
#endif

#if( BSWM_NMENABLED == STD_ON )
#include "Nm.h"
#endif

#if( BSWM_J1939DCMENABLED == STD_ON)
#include "J1939Dcm.h"
#endif

#if( BSWM_J1939RMENABLED == STD_ON )
#include "J1939Rm.h"
#endif

#if( BSWM_COMMENABLED == STD_ON )
#include "ComM.h"
#endif

#if( BSWM_J1939NMENABLED == STD_ON )
#include "J1939Nm.h"
#endif

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
#if( BSWM_IPDU_GROUP_CONTROL == STD_ON )
/* PolySpace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define BSWM_GROUPCONTROL_IDLE   ((uint8)0x00U)
#define BSWM_GROUPCONTROL_NORMAL ((uint8)0x01U)
#define BSWM_GROUPCONTROL_REINIT ((uint8)0x02U)
#define BSWM_GROUPCONTROL_DM     ((uint8)0x04U)

/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define BswM_SetIpduGroup(pduId, bitVal) Com_SetIpduGroup(BswM_ComIPduGroupState, (pduId), (bitVal))
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define BswM_SetIpduDMGroup(pduId, bitVal) Com_SetIpduGroup(BswM_ComRxIPduGroupDMState, (pduId), (bitVal))

/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define BswM_MarkPduGroupControlInvocation(control) BswM_PduGroupControlInvocation |= (control)
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define BswM_MarkDmControlInvocation() BswM_PduGroupControlInvocation |= BSWM_GROUPCONTROL_DM
/* PolySpace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#endif

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
/*
********************************************************************************
*    Local Functions
********************************************************************************
*/
#define BSWM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
#if( BSWM_RULEHANDLERENABLE == STD_ON )
static FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_RuleHandler(uint8 handleId);
#endif

#if( BSWM_SIZE_TIMER > BSWM_ZERO )
LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateTimer(uint8 timerId, uint32 value);
#endif

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_InitToRun(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_RunToPostRun(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_PostRunToRun(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_PostRunToShutdown(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Empty(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_RunToSoftReset(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_RunToBootReset(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_RunToHardReset(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_LinScheduleSwitch(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStart_J1939_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStop_J1939_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStart_EV_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStop_EV_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStart_XCP_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStop_XCP_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStart_HCM_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStop_HCM_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStart_C_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStop_C_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStart_PT_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStop_PT_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_VOL_COM_OFF(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_VOL_COM_ON(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_COMM_NM_FullCOMM(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_COMM_NM_NoCOMM(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_COMM_NoNM_FullCOMM(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_COMM_NoNM_NoCOMM(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_InitToRun(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_RunToPostRun(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_PostRunToRun(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_PostRunToShutdown(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_RunToSoftReset(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_RunToBootReset(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_RunToHardReset(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_LIN_StartSchedule(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_NM_NoCOMM(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_NM_FullCOMM(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_NoNM_FullCOMM(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_NoNM_NoCOMM(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_VOL_StartCOM(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_VOL_StopCOM(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStop_J1939_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStop_EV_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStop_XCP_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStop_HCM_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStop_C_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStop_PT_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStart_J1939_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStart_EV_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStart_XCP_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStart_HCM_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStart_C_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStart_PT_CAN(void); /* PRQA S 0779, 0779 */ /* NSCA_QAC_BswM_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define BSWM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define BSWM_START_SEC_GLOBAL_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if( BSWM_SIZE_CANSM_CHANNEL > 0U )
/* Variable to store current mode of BswMCanSMIndication mode request ports. */
VAR(uint8, BSWM_VAR_NO_INIT) BswM_CanSMChannelState[BSWM_SIZE_CANSM_CHANNEL]; /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
#endif

#if( BSWM_SIZE_CANSMICOM_CHANNEL > 0U )
/* Variable to store current mode of BswMCanSMIcomIndication mode request ports. */
VAR(uint8, BSWM_VAR_NO_INIT) BswM_CanSMIcomChannelState[BSWM_SIZE_CANSMICOM_CHANNEL]; /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
#endif

#if( BSWM_SIZE_COMM_CHANNEL > 0U )
/* Variable to store current mode of BswMComMIndication mode request ports. */
VAR(uint8, BSWM_VAR_NO_INIT) BswM_ComMChannelState[BSWM_SIZE_COMM_CHANNEL]; /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
#endif

#if( BSWM_SIZE_ETHSM_CHANNEL > 0U )
VAR(uint8, BSWM_VAR_NO_INIT) BswM_EthSMChannelState[BSWM_SIZE_ETHSM_CHANNEL];   /* Variable to store current mode of BswMComMIndication mode request ports. */
#endif

#if( BSWM_SIZE_COMMPNC_CHANNEL > 0U )
/* Variable to store current mode of BswMComMPncRequest mode request ports. */
VAR(uint8, BSWM_VAR_NO_INIT) BswM_ComMPncChannelState[BSWM_SIZE_COMMPNC_CHANNEL]; /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
#endif

#if( BSWM_SIZE_GENERIC > 0U )
/* Variable to store current mode of BswMGenericRequest mode request ports. */
VAR(uint16, BSWM_VAR_NO_INIT) BswM_GenericState[BSWM_SIZE_GENERIC]; /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
#endif

#if( BSWM_SIZE_NVM_JOB > 0U )
VAR(uint8, BSWM_VAR_NO_INIT) BswM_NvMJobState[BSWM_SIZE_NVM_JOB];               /* Variable to store current mode of BswMNvMJobModeIndication mode request ports. */
#endif

#if( BSWM_SIZE_NVM_BLOCK > 0U )
/* Variable to store current mode of BswMNvMJobModeIndication mode request ports. */
VAR(uint8, BSWM_VAR_NO_INIT) BswM_NvMBlockState[BSWM_SIZE_NVM_BLOCK]; /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
#endif

#if( BSWM_SIZE_ECUM_CHANNEL > 0U )
/* Variable to store current mode of BswMEcuMIndication mode request ports. */
VAR(uint8, BSWM_VAR_NO_INIT) BswM_EcuMChannelState[BSWM_SIZE_ECUM_CHANNEL]; /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
#endif

#if( BSWM_SIZE_ECUM_WAKEUP > 0U )
/* Variable to store current mode of EcuMwakeupindication mode request ports. */
VAR(uint8, BSWM_VAR_NO_INIT) BswM_EcuMWakeupState[BSWM_SIZE_ECUM_WAKEUP]; /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
#endif

#if( BSWM_SIZE_DCM_CHANNEL > 0U )
/* Variable to store current mode of BswMDcmIndication mode request ports. */
VAR(uint8, BSWM_VAR_NO_INIT) BswM_DcmChannelState[BSWM_SIZE_DCM_CHANNEL]; /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
#endif

#if( BSWM_SIZE_SDCLIENTSERVICE > 0U )
VAR(uint8, BSWM_VAR_NO_INIT) BswM_SdClientServiceState[BSWM_SIZE_SDCLIENTSERVICE];
#endif

#if( BSWM_SIZE_CONSUMEDEVENTGROUP > 0U )
VAR(uint8, BSWM_VAR_NO_INIT) BswM_SdConsumedEventGroupState[BSWM_SIZE_CONSUMEDEVENTGROUP];
#endif

#if( BSWM_SIZE_EVENTHANDLER > 0U )
VAR(uint8, BSWM_VAR_NO_INIT) BswM_SdEventHandlerState[BSWM_SIZE_EVENTHANDLER];
#endif

#if( BSWM_SIZE_FRSM > 0U )
VAR(uint8, BSWM_VAR_NO_INIT) BswM_FrSMState[BSWM_SIZE_FRSM]; /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
#endif

#if( BSWM_SIZE_LINSMSCHEDULE > 0U )
VAR(uint8, BSWM_VAR_NO_INIT) BswM_LinSMScheduleState[BSWM_SIZE_LINSMSCHEDULE]; /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
#endif

#if( BSWM_SIZE_LINSM_CHANNEL > 0U )
VAR(uint8, BSWM_VAR_NO_INIT) BswM_LinSMChannelState[BSWM_SIZE_LINSM_CHANNEL]; /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
#endif

#if( BSWM_SIZE_LINTP_CHANNEL > 0U )
VAR(uint8, BSWM_VAR_NO_INIT) BswM_LinTpChannelState[BSWM_SIZE_LINTP_CHANNEL]; /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
#endif

#if( BSWM_SIZE_J1939DCM_CHANNEL > 0U )
VAR(uint16, BSWM_VAR_NO_INIT) BswM_J1939DcmChannelState[BSWM_SIZE_J1939DCM_CHANNEL]; /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
#endif

#if( BSWM_SIZE_J1939NM_CHANNEL > 0U )
VAR(uint8, BSWM_VAR_NO_INIT) BswM_J1939NmChannelState[BSWM_SIZE_J1939NM_CHANNEL]; /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
#endif

#if( BSWM_IPDU_GROUP_CONTROL == STD_ON )
static VAR(Com_IpduGroupVector, BSWM_VAR_NO_INIT) BswM_ComIPduGroupState;
static VAR(Com_IpduGroupVector, BSWM_VAR_NO_INIT) BswM_ComRxIPduGroupDMState;  /* PRQA S 3218 */ /* NSCA_QAC_BswM_Rule8.9 */
static VAR(uint8, BSWM_VAR_NO_INIT) BswM_PduGroupControlInvocation;
#endif

#define BSWM_STOP_SEC_GLOBAL_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define BSWM_START_SEC_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


#define BSWM_STOP_SEC_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define BSWM_START_SEC_GLOBAL_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


#if( BSWM_SIZE_RULE > 0U )
static VAR(uint8, BSWM_VAR_INIT) BswM_RuleStates[BSWM_SIZE_RULE] = /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
{
	FALSE,
	FALSE,
	FALSE,
	FALSE,
	FALSE,
	FALSE,
	FALSE,
	FALSE,
	FALSE,
	FALSE,
	FALSE,
	FALSE,
	FALSE,
	FALSE,
	FALSE,
	FALSE,
	FALSE,
	FALSE,
	FALSE,
	FALSE,
	FALSE,
	FALSE,
	FALSE,
	FALSE,
	FALSE,
	FALSE,
};
#endif

#if( BSWM_SIZE_ACTIONLIST > 0U )
VAR(BswM_ActionListState_st, BSWM_VAR_INIT) BswM_ActionListQueue[BSWM_SIZE_ACTIONLIST] = 
{
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
	{ 0U, BSWM_ACTIONLIST_IDLE },
};
#endif

#if( BSWM_SIZE_IMMEDIATE_USER > 0U )
VAR(BswM_ModeRequest_st, BSWM_VAR_INIT) BswM_ModeRequestQueue[BSWM_SIZE_IMMEDIATE_USER] = 
{
	{ 0U, BSWM_REQUEST_IDLE },
	{ 0U, BSWM_REQUEST_IDLE },
	{ 0U, BSWM_REQUEST_IDLE },
	{ 0U, BSWM_REQUEST_IDLE },
};
#endif

#if( BSWM_SIZE_TIMER > 0U )
VAR(BswM_TimerValue_st, BSWM_VAR_INIT) BswM_TimerState[BSWM_SIZE_TIMER] = /* PRQA S 1504 */ /* NSCA_QAC_Common_Rule8.7 */
{
	{ 0U, BSWM_TIMER_STOPPED,  0U},
	{ 0U, BSWM_TIMER_STOPPED,  0U},
};
#endif

#if( BSWM_BSWMCONFIG_SIZE > 0U)
VAR(BswM_InitState_st, BSWM_VAR_INIT) BswM_Initialized[BSWM_BSWMCONFIG_SIZE] = 
{
	{ 0U, FALSE},
};
#endif

#define BSWM_STOP_SEC_GLOBAL_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define BSWM_START_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


#define BSWM_STOP_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define BSWM_START_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* BswM/BswMConfigs/BswMConfig/BswMModeControl/BswMActionLists */
CONST(BswM_ActionListsType, BSWM_CONFIG_DATA) BswM_ActionLists[BSWM_SIZE_ACTIONLIST] = 
{
	{ BswM_ActionList_AL_InitToRun },
	{ BswM_ActionList_AL_RunToPostRun },
	{ BswM_ActionList_AL_PostRunToRun },
	{ BswM_ActionList_AL_PostRunToShutdown },
	{ BswM_ActionList_AL_Empty },
	{ BswM_ActionList_AL_RunToSoftReset },
	{ BswM_ActionList_AL_RunToBootReset },
	{ BswM_ActionList_AL_RunToHardReset },
	{ BswM_ActionList_AL_LinScheduleSwitch },
	{ BswM_ActionList_AL_CANSM_IpduStart_J1939_CAN },
	{ BswM_ActionList_AL_CANSM_IpduStop_J1939_CAN },
	{ BswM_ActionList_AL_CANSM_IpduStart_EV_CAN },
	{ BswM_ActionList_AL_CANSM_IpduStop_EV_CAN },
	{ BswM_ActionList_AL_CANSM_IpduStart_XCP_CAN },
	{ BswM_ActionList_AL_CANSM_IpduStop_XCP_CAN },
	{ BswM_ActionList_AL_CANSM_IpduStart_HCM_CAN },
	{ BswM_ActionList_AL_CANSM_IpduStop_HCM_CAN },
	{ BswM_ActionList_AL_CANSM_IpduStart_C_CAN },
	{ BswM_ActionList_AL_CANSM_IpduStop_C_CAN },
	{ BswM_ActionList_AL_CANSM_IpduStart_PT_CAN },
	{ BswM_ActionList_AL_CANSM_IpduStop_PT_CAN },
	{ BswM_ActionList_AL_VOL_COM_OFF },
	{ BswM_ActionList_AL_VOL_COM_ON },
	{ BswM_ActionList_AL_COMM_NM_FullCOMM },
	{ BswM_ActionList_AL_COMM_NM_NoCOMM },
	{ BswM_ActionList_AL_COMM_NoNM_FullCOMM },
	{ BswM_ActionList_AL_COMM_NoNM_NoCOMM },
};

/* /AUTOSAR/EcucDefs/BswM/BswMConfig/BswMArbitration/BswMRule */
CONST(BswM_RulesType, BSWM_CONFIG_DATA) BswM_Rules[BSWM_SIZE_RULE] = 
{
	{ BswM_Rule_RL_InitToRun },
	{ BswM_Rule_RL_RunToPostRun },
	{ BswM_Rule_RL_PostRunToRun },
	{ BswM_Rule_RL_PostRunToShutdown },
	{ BswM_Rule_RL_RunToSoftReset },
	{ BswM_Rule_RL_RunToBootReset },
	{ BswM_Rule_RL_RunToHardReset },
	{ BswM_Rule_RL_LIN_StartSchedule },
	{ BswM_Rule_RL_COMM_NM_NoCOMM },
	{ BswM_Rule_RL_COMM_NM_FullCOMM },
	{ BswM_Rule_RL_COMM_NoNM_FullCOMM },
	{ BswM_Rule_RL_COMM_NoNM_NoCOMM },
	{ BswM_Rule_RL_VOL_StartCOM },
	{ BswM_Rule_RL_VOL_StopCOM },
	{ BswM_Rule_RL_COMM_IpduStop_J1939_CAN },
	{ BswM_Rule_RL_COMM_IpduStop_EV_CAN },
	{ BswM_Rule_RL_COMM_IpduStop_XCP_CAN },
	{ BswM_Rule_RL_COMM_IpduStop_HCM_CAN },
	{ BswM_Rule_RL_COMM_IpduStop_C_CAN },
	{ BswM_Rule_RL_COMM_IpduStop_PT_CAN },
	{ BswM_Rule_RL_COMM_IpduStart_J1939_CAN },
	{ BswM_Rule_RL_COMM_IpduStart_EV_CAN },
	{ BswM_Rule_RL_COMM_IpduStart_XCP_CAN },
	{ BswM_Rule_RL_COMM_IpduStart_HCM_CAN },
	{ BswM_Rule_RL_COMM_IpduStart_C_CAN },
	{ BswM_Rule_RL_COMM_IpduStart_PT_CAN },
};

/* /AUTOSAR/EcucDefs/BswM/BswMConfig/BswMArbitration/BswMRule Not BswMNestedExecutionOnly */
CONST(uint8, BSWM_CONFIG_DATA) BswM_RulesInd[BSWM_SIZE_RULEIND] = 
{
	0U,
	1U,
	2U,
	3U,
	4U,
	5U,
	6U,
	8U,
	9U,
	10U,
	11U,
	12U,
	13U,
	14U,
	15U,
	16U,
	17U,
	18U,
	19U,
	20U,
	21U,
	22U,
	23U,
	24U,
	25U,
	1U,
	2U,
	3U,
	4U,
	5U,
	6U,
	8U,
	9U,
	4U,
	5U,
	6U,
	12U,
	13U,
	14U,
	20U,
	21U,
	22U,
	23U,
	24U,
	25U,
};

/* Contains all immediate request ports. */
CONST(BswM_ImmediateUserType, BSWM_CONFIG_DATA) BswM_ImmediateUser[BSWM_SIZE_IMMEDIATE_USER] = 
{
	{ 0x03U, 24U, 0U },
	{ 0x03U, 32U, 25U },
	{ 0x03U, 35U, 33U },
	{ 0x03U, 44U, 36U },
};

/* Maps the external id of BswMCanSMIndication to an internal id and references immediate request ports. */
#if( BSWM_SIZE_CANSM_CHANNEL > 0U )
CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_CanSMChannelMapping[BSWM_SIZE_CANSM_CHANNEL] =
{
};
#endif

#if( BSWM_SIZE_ECUM_WAKEUP > 0U )
CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_EcuMWakeUpMapping[BSWM_SIZE_ECUM_WAKEUP] = 
{
};
#endif

#if( BSWM_SIZE_ECUM_CHANNEL > 0U )
CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_EcuMChannelMapping[BSWM_SIZE_ECUM_CHANNEL] =
{
};
#endif

#if( BSWM_SIZE_DCM_CHANNEL > 0U )
CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_DcmChannelMapping[BSWM_SIZE_DCM_CHANNEL] = 
{
	{ 0U, BSWM_NO_IMMEUSER, BSWM_NO_IMMEUSER, 0U, 0 }, /* PRQA S 4424 */ /* NSCA_QAC_BswM_Rule10.3 */
	{ 2U, BSWM_NO_IMMEUSER, BSWM_NO_IMMEUSER, 0U, 0 }, /* PRQA S 4424 */ /* NSCA_QAC_BswM_Rule10.3 */
	{ 6U, BSWM_NO_IMMEUSER, BSWM_NO_IMMEUSER, 0U, 0 }, /* PRQA S 4424 */ /* NSCA_QAC_BswM_Rule10.3 */
	{ 1U, BSWM_NO_IMMEUSER, BSWM_NO_IMMEUSER, 0U, 0 }, /* PRQA S 4424 */ /* NSCA_QAC_BswM_Rule10.3 */
	{ 4U, BSWM_NO_IMMEUSER, BSWM_NO_IMMEUSER, 0U, 0 }, /* PRQA S 4424 */ /* NSCA_QAC_BswM_Rule10.3 */
	{ 5U, BSWM_NO_IMMEUSER, BSWM_NO_IMMEUSER, 0U, 0 }, /* PRQA S 4424 */ /* NSCA_QAC_BswM_Rule10.3 */
	{ 3U, BSWM_NO_IMMEUSER, BSWM_NO_IMMEUSER, 0U, 0 }, /* PRQA S 4424 */ /* NSCA_QAC_BswM_Rule10.3 */
};
#endif

/* /AUTOSAR/EcucDefs/BswM/BswMConfig/BswMArbitration/BswMModeRequestPort/BswMModeRequestSource */
#if( BSWM_SIZE_SDCLIENTSERVICE > 0U )
CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_SdClientServiceMapping[BSWM_SIZE_SDCLIENTSERVICE] =
{
};
#endif

/* /AUTOSAR/EcucDefs/BswM/BswMConfig/BswMArbitration/BswMModeRequestPort/BswMModeRequestSource */
#if( BSWM_SIZE_CONSUMEDEVENTGROUP > 0U )
CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_SdConsumedEventGroupMapping[BSWM_SIZE_CONSUMEDEVENTGROUP] =
{
};
#endif
/* /AUTOSAR/EcucDefs/BswM/BswMConfig/BswMArbitration/BswMModeRequestPort/BswMModeRequestSource/BswMSdEventHandlerCurrentState */
#if( BSWM_SIZE_EVENTHANDLER > 0U )
CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_SdEventHandlerMapping[BSWM_SIZE_EVENTHANDLER] =
{
};
#endif
/* Maps the external id of BswMComMIndication to an internal id and references immediate request ports. */
#if( BSWM_SIZE_COMM_CHANNEL > 0U )
CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_ComMChannelMapping[BSWM_SIZE_COMM_CHANNEL] = 
{
	{ 0, BSWM_NO_IMMEUSER, BSWM_NO_IMMEUSER, 0U, COMM_NO_COMMUNICATION }, /* PRQA S 4424 */ /* NSCA_QAC_BswM_Rule10.3 */
	{ 1, BSWM_NO_IMMEUSER, BSWM_NO_IMMEUSER, 0U, COMM_NO_COMMUNICATION }, /* PRQA S 4424 */ /* NSCA_QAC_BswM_Rule10.3 */
	{ 2, BSWM_NO_IMMEUSER, BSWM_NO_IMMEUSER, 0U, COMM_NO_COMMUNICATION }, /* PRQA S 4424 */ /* NSCA_QAC_BswM_Rule10.3 */
	{ 3, BSWM_NO_IMMEUSER, BSWM_NO_IMMEUSER, 0U, COMM_NO_COMMUNICATION }, /* PRQA S 4424 */ /* NSCA_QAC_BswM_Rule10.3 */
	{ 4, BSWM_NO_IMMEUSER, BSWM_NO_IMMEUSER, 0U, COMM_NO_COMMUNICATION }, /* PRQA S 4424 */ /* NSCA_QAC_BswM_Rule10.3 */
	{ 5, BSWM_NO_IMMEUSER, BSWM_NO_IMMEUSER, 0U, COMM_NO_COMMUNICATION }, /* PRQA S 4424 */ /* NSCA_QAC_BswM_Rule10.3 */
	{ 6, BSWM_NO_IMMEUSER, BSWM_NO_IMMEUSER, 0U, COMM_NO_COMMUNICATION }, /* PRQA S 4424 */ /* NSCA_QAC_BswM_Rule10.3 */
};
#endif

/* Maps the external id of BswMComMPncRequest to an internal id and references immediate request ports. */
#if( BSWM_SIZE_COMMPNC_CHANNEL > 0U )
CONST( BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_ComMPncChannelMapping[BSWM_SIZE_COMMPNC_CHANNEL] =
{
};
#endif

/* Maps the external id of BswMEthSMIndication to an internal id and references immediate request ports. */
#if( BSWM_SIZE_ETHSM_CHANNEL > 0U )
CONST( BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_EthSMChannelMapping[BSWM_SIZE_ETHSM_CHANNEL] =
{
};
#endif

#if( BSWM_SIZE_FRSM > 0U )
CONST( BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_FrSMMapping[BSWM_SIZE_FRSM] =
{
};
#endif

#if( BSWM_SIZE_LINSMSCHEDULE > 0U )
CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_LinSMScheduleMapping[BSWM_SIZE_LINSMSCHEDULE] =
{
	{ 0, BSWM_NO_IMMEUSER, BSWM_NO_IMMEUSER, 0U, LINIF_SCEDULE_NULL_SCHEDULE_T34TDkIDX }, /* PRQA S 4424 */ /* NSCA_QAC_BswM_Rule10.3 */
};
#endif

#if( BSWM_SIZE_LINSM_CHANNEL > 0U )
CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_LinSMChannelMapping[BSWM_SIZE_LINSM_CHANNEL] =
{
	{ 0, BSWM_NO_IMMEUSER, BSWM_NO_IMMEUSER, 0U, LINSM_NO_COM }, /* PRQA S 4424 */ /* NSCA_QAC_BswM_Rule10.3 */
};
#endif

#if( BSWM_SIZE_CANSMICOM_CHANNEL > 0U )
CONST(BswM_CanSMIcomChannelMappingType, BSWM_CONFIG_DATA) BswM_CanSMIcomChannelMapping[BSWM_SIZE_CANSMICOM_CHANNEL] =
{
};
#endif

#if( BSWM_SIZE_LINTP_CHANNEL > 0U )
CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_LinTpChannelMapping[BSWM_SIZE_LINTP_CHANNEL] =
{
};
#endif

#if( BSWM_SIZE_NVM_BLOCK > 0U )
CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_NvMBlockMapping[BSWM_SIZE_NVM_BLOCK] =
{
};
#endif

#if( BSWM_SIZE_NVM_JOB > 0U )
CONST(BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_NvMJobMapping[BSWM_SIZE_NVM_JOB] =
{
};
#endif

#if( BSWM_SIZE_J1939DCM_CHANNEL > 0U )
CONST( BswM_ChannelMappingType, BSWM_CONFIG_DATA) BswM_J1939DcmChannelMapping[BSWM_SIZE_J1939DCM_CHANNEL] = 
{
};
#endif

#if( BSWM_SIZE_J1939NM_CHANNEL > 0U )
CONST( BswM_J1939NmStateChangeMappingType, BSWM_CONFIG_DATA) BswM_J1939NmChannelMapping[BSWM_SIZE_J1939NM_CHANNEL] =
{
};
#endif

#if( BSWM_SIZE_DEFERRED_RULE > 0U )
/* BswM_DeferredRules */
CONST(BswM_DeferredRulesType, BSWM_CONFIG_DATA) BswM_DeferredRules[BSWM_SIZE_DEFERRED_RULE] = 
{
	{ 0U, 1U },
	{ 0U, 3U },
	{ 0U, 4U },
	{ 0U, 5U },
	{ 0U, 6U },
	{ 0U, 7U },
	{ 0U, 10U },
	{ 0U, 11U },
	{ 0U, 14U },
	{ 0U, 15U },
	{ 0U, 16U },
	{ 0U, 17U },
	{ 0U, 18U },
	{ 0U, 19U },
	{ 0U, 20U },
	{ 0U, 21U },
	{ 0U, 22U },
	{ 0U, 23U },
	{ 0U, 24U },
	{ 0U, 25U },
};
#endif
#if( BSWM_SIZE_GENERIC > 0U )
/* Maps the external id of BswMGenericRequest to an internal id and references immediate request ports. */
CONST(BswM_GenericMappingType, BSWM_CONFIG_DATA) BswM_GenericMapping[BSWM_SIZE_GENERIC] = 
{
	{ 111, 1U, 0U, 0U, 0U, BSWM_GENERICVALUE_STATE_Init },
	{ 112, 2U, 1U, 0U, 0U, BSWM_GENERICVALUE_STATE_POWER_ON },
	{ 113, 3U, 2U, 0U, 0U, BSWM_GENERICVALUE_STATE_NO_Reset },
	{ 114, 4U, 3U, 0U, 0U, BSWM_GENERICVALUE_Cond_StatelsValtNom },
	{ 115, BSWM_NO_IMMEUSER, BSWM_NO_IMMEUSER, 0U, 0U, BSWM_GENERICVALUE_SWC_PwrOffDlyFlg_Mp_ON },
};
#endif

#if( BSWM_MULTIPARTITION == STD_ON )
CONST(BswM_ApplMapping_st, BSWM_CONFIG_DATA) BswM_ApplMapping[BSWM_BSWMCONFIG_SIZE] = 
{
    {0U, 1U, &BswM_PartApplMapping0[0]}
};
CONST(BswM_CoreIdMapping_st, BSWM_CONFIG_DATA) BswM_CoreIdMapping[BSWM_COREIDMAPPING_SIZE] = /* PRQA S 4342 */ /* NSCA_QAC_BswM_Rule10.5 */
{
    {0U, (CoreIdType)0U}, /* PRQA S 4342 */ /* NSCA_QAC_BswM_Rule10.5 */
    {0U, (CoreIdType)2U}, /* PRQA S 4342 */ /* NSCA_QAC_BswM_Rule10.5 */
    {0U, (CoreIdType)3U}, /* PRQA S 4342 */ /* NSCA_QAC_BswM_Rule10.5 */
    {0U, (CoreIdType)4U}, /* PRQA S 4342 */ /* NSCA_QAC_BswM_Rule10.5 */
    {0U, (CoreIdType)5U}, /* PRQA S 4342 */ /* NSCA_QAC_BswM_Rule10.5 */
    {0U, (CoreIdType)1U} /* PRQA S 4342 */ /* NSCA_QAC_BswM_Rule10.5 */
};
CONST(uint8, BSWM_CONFIG_DATA) BswM_PartApplMapping0[1] = {0U}; /* PRQA S 0627 */ /* NSCA_QAC_BswM_Rule1.1 */
#endif

#define BSWM_STOP_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define BSWM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
#if( BSWM_RULEHANDLERENABLE == STD_ON )
/*
********************************************************************************
* Function Name:   BswM_Action_RuleHandler
*
* Explanation: BswM_Action_RuleHandler
*
* param:    handleId: id of rule
*
* retval:   void
********************************************************************************
*/
static FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_RuleHandler(uint8 handleId)
{
    uint8 actionListIndex;
    Std_ReturnType retVal = E_NOT_OK;

    actionListIndex = BswM_Rules[handleId].FctPtrOfRules();
    if( actionListIndex < BSWM_SIZE_ACTIONLIST )
    {
        retVal = BswM_ActionLists[actionListIndex].FctPtrOfActionLists();
    }
    else
    {
        retVal = E_OK;
    }

    return retVal;
}
#endif
/*
********************************************************************************
* Function Name:   BswM_UpdateTimer
*
* Explanation: BswM_UpdateTimer
*
* param:    timerId: id of timer
*           value: value of timer
*
* retval:   void
********************************************************************************
*/
#if( BSWM_SIZE_TIMER > BSWM_ZERO )
LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateTimer
(
    uint8 timerId,
    uint32 value
)
{
    if( timerId < BSWM_SIZE_TIMER )
    {
        BswM_TimerState[timerId].Timevalue = value;

        if( BSWM_ZERO == value )
        {
            BswM_TimerState[timerId].Timestate = BSWM_TIMER_STOPPED;
        }
        else
        {
            BswM_TimerState[timerId].Timestate = BSWM_TIMER_STARTED;
        }
    }

    return;
}
#endif

#if( BSWM_IPDU_GROUP_CONTROL == STD_ON )
/*
********************************************************************************
* Function Name: BswM_ExecuteIpduGroupControl
*
* Explanation: BswM_ExecuteIpduGroupControl
*
* param: void
*
* retval: void
********************************************************************************
*/
FUNC(void, BSWM_CODE) BswM_ExecuteIpduGroupControl(void)  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
{
    Com_IpduGroupVector ipduGroupState;
    Com_IpduGroupVector dmState;
    uint16 iCnt;
    uint8 controlInvocation = BSWM_GROUPCONTROL_IDLE;
    
    if(BswM_PduGroupControlInvocation != BSWM_GROUPCONTROL_IDLE)
    {
        if((BswM_PduGroupControlInvocation & BSWM_GROUPCONTROL_NORMAL) != 0u)
        {
            iCnt = COM_PDUGRP_VECTOR_SIZE;
            while(iCnt > (uint16)0x0000U)
            {
                iCnt--;
                ipduGroupState[iCnt] = BswM_ComIPduGroupState[iCnt];
            }
        }

        if((BswM_PduGroupControlInvocation & BSWM_GROUPCONTROL_DM) != 0u)
        {
            iCnt = COM_PDUGRP_VECTOR_SIZE;
            while(iCnt > (uint16)0x0000U)
            {
                iCnt--;
                dmState[iCnt] = BswM_ComRxIPduGroupDMState[iCnt];
            }
        }

        controlInvocation = BswM_PduGroupControlInvocation;
        BswM_PduGroupControlInvocation = BSWM_GROUPCONTROL_IDLE;
    }

    if(controlInvocation != BSWM_GROUPCONTROL_IDLE)
    {
        if((controlInvocation & BSWM_GROUPCONTROL_NORMAL) != 0u)
        {
            Com_IpduGroupControl(ipduGroupState, FALSE);
        }
        if((controlInvocation & BSWM_GROUPCONTROL_DM) != 0u)
        {
            Com_ReceptionDMControl(dmState);
        }
    }

}
#endif /* BSWM_IPDU_GROUP_CONTROL == STD_ON */

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_InitToRun(void)
{
	 BswM_InitToRun_Action();
	ComM_CommunicationAllowed(0, (TRUE));
	ComM_CommunicationAllowed(1, (TRUE));
	ComM_CommunicationAllowed(2, (TRUE));
	ComM_CommunicationAllowed(3, (TRUE));
	ComM_CommunicationAllowed(4, (TRUE));
	ComM_CommunicationAllowed(5, (TRUE));
	ComM_CommunicationAllowed(6, (TRUE));
	BswM_SetIpduGroup(0, TRUE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(1, TRUE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(2, TRUE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(3, TRUE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(4, TRUE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(5, TRUE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(6, TRUE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(7, TRUE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(8, TRUE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(9, TRUE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(10, TRUE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(11, TRUE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(12, TRUE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(13, TRUE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_RequestMode(BSWM_GENERIC_RP_State, BSWM_GENERICVALUE_STATE_Run);
	BswM_UpdateTimer(BSWM_TMR_RP_RunTimer, 100);

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_RunToPostRun(void)
{
	BswM_SetIpduGroup(0, FALSE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(1, FALSE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(2, FALSE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(3, FALSE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(4, FALSE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(5, FALSE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(6, FALSE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(7, FALSE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(8, FALSE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(9, FALSE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(10, FALSE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(11, FALSE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(12, FALSE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	BswM_SetIpduGroup(13, FALSE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
	 BswM_Dem_Shutdown();
	BswM_UpdateTimer(BSWM_TMR_RP_WriteTimer, 100);
	 BswM_RunToPostRun_Action();
	BswM_RequestMode(BSWM_GENERIC_RP_State, BSWM_GENERICVALUE_STATE_PostRun);

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_PostRunToRun(void)
{
	 BswM_PostRunToRun_Action();
	BswM_RequestMode(BSWM_GENERIC_RP_State, BSWM_GENERICVALUE_STATE_Run);
	BswM_UpdateTimer(BSWM_TMR_RP_RunTimer, 100);

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_PostRunToShutdown(void)
{
	 BswM_PostRunToShutdown_Action();
    (void) EcuM_SelectShutdownTarget(ECUM_SHUTDOWN_TARGET_OFF, 0U);
	BswM_RequestMode(BSWM_GENERIC_RP_State, BSWM_GENERICVALUE_STATE_Shutdown);
    (void)EcuM_GoDown(42U);

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Empty(void)
{

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_RunToSoftReset(void)
{
	 BswM_SoftReset_Action();

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_RunToBootReset(void)
{
	 BswM_BootReset_Action();

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_RunToHardReset(void)
{
	 BswM_HardReset_Action();

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_LinScheduleSwitch(void)
{
    (void)LinSM_ScheduleRequest(0, 1);

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStart_J1939_CAN(void)
{
	BswM_SetIpduGroup(2, TRUE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStop_J1939_CAN(void)
{
	BswM_SetIpduGroup(2, FALSE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStart_EV_CAN(void)
{
	BswM_SetIpduGroup(4, TRUE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStop_EV_CAN(void)
{
	BswM_SetIpduGroup(4, FALSE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStart_XCP_CAN(void)
{
	BswM_SetIpduGroup(6, TRUE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStop_XCP_CAN(void)
{
	BswM_SetIpduGroup(6, FALSE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStart_HCM_CAN(void)
{
	BswM_SetIpduGroup(8, TRUE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStop_HCM_CAN(void)
{
	BswM_SetIpduGroup(8, FALSE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStart_C_CAN(void)
{
	BswM_SetIpduGroup(10, TRUE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStop_C_CAN(void)
{
	BswM_SetIpduGroup(10, FALSE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStart_PT_CAN(void)
{
	BswM_SetIpduGroup(12, TRUE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_CANSM_IpduStop_PT_CAN(void)
{
	BswM_SetIpduGroup(12, FALSE);
	BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_VOL_COM_OFF(void)
{
	 BswM_CANDriver_OFF();

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_VOL_COM_ON(void)
{
	 BswM_CANDriver_ON();

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_COMM_NM_FullCOMM(void)
{
    (void)ComM_RequestComMode(2, COMM_FULL_COMMUNICATION);
    (void)ComM_RequestComMode(6, COMM_FULL_COMMUNICATION);

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_COMM_NM_NoCOMM(void)
{
    (void)ComM_RequestComMode(2, COMM_NO_COMMUNICATION);
    (void)ComM_RequestComMode(6, COMM_NO_COMMUNICATION);

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_COMM_NoNM_FullCOMM(void)
{
    (void)ComM_RequestComMode(1, COMM_FULL_COMMUNICATION);
    (void)ComM_RequestComMode(3, COMM_FULL_COMMUNICATION);
    (void)ComM_RequestComMode(4, COMM_FULL_COMMUNICATION);
    (void)ComM_RequestComMode(5, COMM_FULL_COMMUNICATION);
    (void)ComM_RequestComMode(0, COMM_FULL_COMMUNICATION);

    return E_OK;
}

static FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_COMM_NoNM_NoCOMM(void)
{
    (void)ComM_RequestComMode(1, COMM_NO_COMMUNICATION);
    (void)ComM_RequestComMode(3, COMM_NO_COMMUNICATION);
    (void)ComM_RequestComMode(4, COMM_NO_COMMUNICATION);
    (void)ComM_RequestComMode(5, COMM_NO_COMMUNICATION);
    (void)ComM_RequestComMode(0, COMM_NO_COMMUNICATION);

    return E_OK;
}


static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_InitToRun(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if (BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Init /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
		retVal = BSWM_ID_AL_AL_InitToRun;
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_RunToPostRun(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Run) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_TimerState[1].Timestate == BSWM_TIMER_EXPIRED) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_GenericState[4] == BSWM_GENERICVALUE_SWC_PwrOffDlyFlg_Mp_OFF) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	((BswM_ComMChannelState[3] == COMM_NO_COMMUNICATION) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_ComMChannelState[2] == COMM_NO_COMMUNICATION) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_ComMChannelState[6] == COMM_NO_COMMUNICATION) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_ComMChannelState[1] == COMM_NO_COMMUNICATION) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_ComMChannelState[4] == COMM_NO_COMMUNICATION) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_ComMChannelState[5] == COMM_NO_COMMUNICATION)) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_GenericState[1] == BSWM_GENERICVALUE_STATE_POWER_OFF) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
		retVal = BSWM_ID_AL_AL_RunToPostRun;
	}
	else
	{
		retVal = BSWM_ID_AL_AL_Empty;
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_PostRunToRun(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_PostRun) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_GenericState[1] == BSWM_GENERICVALUE_STATE_POWER_ON) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
		retVal = BSWM_ID_AL_AL_PostRunToRun;
	}
	else
	{
		retVal = BSWM_ID_AL_AL_Empty;
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_PostRunToShutdown(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_PostRun) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_GenericState[1] == BSWM_GENERICVALUE_STATE_POWER_OFF) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_TimerState[0].Timestate == BSWM_TIMER_EXPIRED) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
		retVal = BSWM_ID_AL_AL_PostRunToShutdown;
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_RunToSoftReset(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Run) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_TimerState[1].Timestate == BSWM_TIMER_EXPIRED) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_GenericState[2] == BSWM_GENERICVALUE_STATE_Soft_Reset) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_GenericState[1] == BSWM_GENERICVALUE_STATE_POWER_ON) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
		retVal = BSWM_ID_AL_AL_RunToSoftReset;
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_RunToBootReset(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Run) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_TimerState[1].Timestate == BSWM_TIMER_EXPIRED) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_GenericState[2] == BSWM_GENERICVALUE_STATE_Boot_Reset) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_GenericState[1] == BSWM_GENERICVALUE_STATE_POWER_ON) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
		retVal = BSWM_ID_AL_AL_RunToBootReset;
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_RunToHardReset(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Run) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_TimerState[1].Timestate == BSWM_TIMER_EXPIRED) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_GenericState[1] == BSWM_GENERICVALUE_STATE_POWER_ON) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_GenericState[2] == BSWM_GENERICVALUE_STATE_Hard_Reset) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
		retVal = BSWM_ID_AL_AL_RunToHardReset;
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_LIN_StartSchedule(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_LinSMChannelState[0] == LINSM_FULL_COM) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_LinSMScheduleState[0] == LINIF_SCEDULE_NULL_SCHEDULE_T34TDkIDX) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
		retVal = BSWM_ID_AL_AL_LinScheduleSwitch;
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_NM_NoCOMM(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Run) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_GenericState[1] == BSWM_GENERICVALUE_STATE_POWER_OFF) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
		retVal = BSWM_ID_AL_AL_COMM_NM_NoCOMM;
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_NM_FullCOMM(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Run) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_GenericState[1] == BSWM_GENERICVALUE_STATE_POWER_ON) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
		retVal = BSWM_ID_AL_AL_COMM_NM_FullCOMM;
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_NoNM_FullCOMM(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Run) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	((BswM_ComMChannelState[2] == COMM_FULL_COMMUNICATION) || /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_ComMChannelState[6] == COMM_FULL_COMMUNICATION)) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
		retVal = BSWM_ID_AL_AL_COMM_NoNM_FullCOMM;
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_NoNM_NoCOMM(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Run) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_ComMChannelState[2] == COMM_NO_COMMUNICATION) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_ComMChannelState[6] == COMM_NO_COMMUNICATION) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
		retVal = BSWM_ID_AL_AL_COMM_NoNM_NoCOMM;
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_VOL_StartCOM(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Run) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_GenericState[3] == BSWM_GENERICVALUE_Cond_StatelsValtNom) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_VOL_StartCOM] != BSWM_TRUE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_VOL_StartCOM]=BSWM_TRUE;
            retVal = BSWM_ID_AL_AL_VOL_COM_ON;
        }
	}
	else
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_VOL_StartCOM] != BSWM_FALSE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_VOL_StartCOM]=BSWM_FALSE;
        }
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_VOL_StopCOM(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if (((BswM_GenericState[3] == BSWM_GENERICVALUE_Cond_StatelsValtLow) || /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_GenericState[3] == BSWM_GENERICVALUE_Cond_StatelsValtHigh)) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Run) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_VOL_StopCOM] != BSWM_TRUE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_VOL_StopCOM]=BSWM_TRUE;
            retVal = BSWM_ID_AL_AL_VOL_COM_OFF;
        }
	}
	else
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_VOL_StopCOM] != BSWM_FALSE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_VOL_StopCOM]=BSWM_FALSE;
        }
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStop_J1939_CAN(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Run) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(((BswM_GenericState[3] == BSWM_GENERICVALUE_Cond_StatelsValtLow) || /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_GenericState[3] == BSWM_GENERICVALUE_Cond_StatelsValtHigh)) || /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_ComMChannelState[1] != COMM_FULL_COMMUNICATION)) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_J1939_CAN] != BSWM_TRUE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_J1939_CAN]=BSWM_TRUE;
            retVal = BSWM_ID_AL_AL_CANSM_IpduStop_J1939_CAN;
        }
	}
	else
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_J1939_CAN] != BSWM_FALSE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_J1939_CAN]=BSWM_FALSE;
        }
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStop_EV_CAN(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Run) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_ComMChannelState[2] != COMM_FULL_COMMUNICATION) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_EV_CAN] != BSWM_TRUE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_EV_CAN]=BSWM_TRUE;
            retVal = BSWM_ID_AL_AL_CANSM_IpduStop_EV_CAN;
        }
	}
	else
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_EV_CAN] != BSWM_FALSE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_EV_CAN]=BSWM_FALSE;
        }
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStop_XCP_CAN(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Run) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_ComMChannelState[3] != COMM_FULL_COMMUNICATION) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_XCP_CAN] != BSWM_TRUE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_XCP_CAN]=BSWM_TRUE;
            retVal = BSWM_ID_AL_AL_CANSM_IpduStop_XCP_CAN;
        }
	}
	else
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_XCP_CAN] != BSWM_FALSE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_XCP_CAN]=BSWM_FALSE;
        }
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStop_HCM_CAN(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Run) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_ComMChannelState[4] != COMM_FULL_COMMUNICATION) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_HCM_CAN] != BSWM_TRUE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_HCM_CAN]=BSWM_TRUE;
            retVal = BSWM_ID_AL_AL_CANSM_IpduStop_HCM_CAN;
        }
	}
	else
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_HCM_CAN] != BSWM_FALSE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_HCM_CAN]=BSWM_FALSE;
        }
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStop_C_CAN(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Run) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_ComMChannelState[5] != COMM_FULL_COMMUNICATION) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_C_CAN] != BSWM_TRUE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_C_CAN]=BSWM_TRUE;
            retVal = BSWM_ID_AL_AL_CANSM_IpduStop_C_CAN;
        }
	}
	else
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_C_CAN] != BSWM_FALSE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_C_CAN]=BSWM_FALSE;
        }
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStop_PT_CAN(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Run) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_ComMChannelState[6] != COMM_FULL_COMMUNICATION) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_PT_CAN] != BSWM_TRUE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_PT_CAN]=BSWM_TRUE;
            retVal = BSWM_ID_AL_AL_CANSM_IpduStop_PT_CAN;
        }
	}
	else
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_PT_CAN] != BSWM_FALSE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStop_PT_CAN]=BSWM_FALSE;
        }
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStart_J1939_CAN(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Run) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_GenericState[3] == BSWM_GENERICVALUE_Cond_StatelsValtNom) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_ComMChannelState[1] == COMM_FULL_COMMUNICATION) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_J1939_CAN] != BSWM_TRUE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_J1939_CAN]=BSWM_TRUE;
            retVal = BSWM_ID_AL_AL_CANSM_IpduStart_J1939_CAN;
        }
	}
	else
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_J1939_CAN] != BSWM_FALSE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_J1939_CAN]=BSWM_FALSE;
        }
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStart_EV_CAN(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Run) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_GenericState[3] == BSWM_GENERICVALUE_Cond_StatelsValtNom) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_ComMChannelState[2] == COMM_FULL_COMMUNICATION) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_EV_CAN] != BSWM_TRUE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_EV_CAN]=BSWM_TRUE;
            retVal = BSWM_ID_AL_AL_CANSM_IpduStart_EV_CAN;
        }
	}
	else
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_EV_CAN] != BSWM_FALSE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_EV_CAN]=BSWM_FALSE;
        }
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStart_XCP_CAN(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Run) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_GenericState[3] == BSWM_GENERICVALUE_Cond_StatelsValtNom) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_ComMChannelState[3] == COMM_FULL_COMMUNICATION) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_XCP_CAN] != BSWM_TRUE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_XCP_CAN]=BSWM_TRUE;
            retVal = BSWM_ID_AL_AL_CANSM_IpduStart_XCP_CAN;
        }
	}
	else
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_XCP_CAN] != BSWM_FALSE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_XCP_CAN]=BSWM_FALSE;
        }
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStart_HCM_CAN(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Run) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_GenericState[3] == BSWM_GENERICVALUE_Cond_StatelsValtNom) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_ComMChannelState[4] == COMM_FULL_COMMUNICATION) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_HCM_CAN] != BSWM_TRUE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_HCM_CAN]=BSWM_TRUE;
            retVal = BSWM_ID_AL_AL_CANSM_IpduStart_HCM_CAN;
        }
	}
	else
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_HCM_CAN] != BSWM_FALSE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_HCM_CAN]=BSWM_FALSE;
        }
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStart_C_CAN(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Run) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_GenericState[3] == BSWM_GENERICVALUE_Cond_StatelsValtNom) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_ComMChannelState[5] == COMM_FULL_COMMUNICATION) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_C_CAN] != BSWM_TRUE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_C_CAN]=BSWM_TRUE;
            retVal = BSWM_ID_AL_AL_CANSM_IpduStart_C_CAN;
        }
	}
	else
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_C_CAN] != BSWM_FALSE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_C_CAN]=BSWM_FALSE;
        }
	}
	return retVal;
}

static FUNC(uint8, BSWM_CODE) BswM_Rule_RL_COMM_IpduStart_PT_CAN(void)
{
	uint8 retVal = BSWM_NO_ACTIONLIST;

	if ((BswM_GenericState[0] == BSWM_GENERICVALUE_STATE_Run) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_GenericState[3] == BSWM_GENERICVALUE_Cond_StatelsValtNom) && /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */
	(BswM_ComMChannelState[6] == COMM_FULL_COMMUNICATION) /* PRQA S 1881 */ /* NSCA_QAC_Common_Rule10.4 */)
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_PT_CAN] != BSWM_TRUE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_PT_CAN]=BSWM_TRUE;
            retVal = BSWM_ID_AL_AL_CANSM_IpduStart_PT_CAN;
        }
	}
	else
	{
        if(BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_PT_CAN] != BSWM_FALSE)
        {
            BswM_RuleStates[BSWM_ID_RULE_RL_COMM_IpduStart_PT_CAN]=BSWM_FALSE;
        }
	}
	return retVal;
}



#if( BSWM_SWCMODEREQUEST_DATA_INIT == STD_ON )
FUNC(void, BSWM_CODE) BswM_SwcModeRequestDataInit
(
    uint8 partitionId
)
{
    BSWM_DUMMY_STATEMENT(partitionId);
}
#endif

#define BSWM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

