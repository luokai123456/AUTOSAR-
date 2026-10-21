/*
********************************************************************************
*                                                                                                                                         
* File name: ComM_Lcfg.h                                                                                                 
*                                                                                                                                         
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.                                              
*                                                                                                                                         
********************************************************************************
*                                                                                                                                        
* History                                                                                                                             
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : TanLixiang/2018.07.14
* Change: New
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date : TanLixiang/2019.05.05
* Change: Modify
* Cause: Modify file structure.
********************************************************************************
* Version: 3.0
* Author/Date : jiafeng/2020.07.02
* Change: Nothing
* Cause: Update to V3.0
********************************************************************************
* Version: 3.1
* Author/Date : jiafeng/2020.09.01
* Change: Delete ComM_UserHandleType and ComM_ModeType for compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: TianL/2024.8.5
* Change: Modify copyright.
* Cause: Update
********************************************************************************
*/
#ifndef COMM_LCFG_H
#define COMM_LCFG_H

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "ComM_Cfg.h"
#include    "ComStack_Types.h" //LK
/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* polyspace-begin MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define COMM_ACTIVE_CHANNEL                                                 (7U)
#define COMM_PNC_SIZE                                                       (1U)
#define COMM_SIGNAL_NUM                                                     (0U)
#define COMM_SIGNAL_GROUP_NUM                                               (1U)
#define COMM_SIZE_OF_SIGNAL_VALUES                                          (0U)
#define COMM_PNC_SIGNAL_LENGTH                                              (0U)
#define COMM_PNC_PS_TIMER                                                   (1U)
#define COMM_SIZE_OF_USER_REQ_FULL_COM                                      (7U)
#define COMM_NUM_USER_BYTE_MASK                                             (7U)
#define COMM_NUM_USER_PNC_BYTE_MASK                                         (1U)
#define COMM_SIZE_OF_USER_PNC_REQ_FULL_COM                                  (1U)
#define COMM_NUM_PNC_PBIND                                                  (0U)
#define COMM_NUM_PNC_SIGNALIND                                              (1U)
#define COMM_NUM_PNC_CHANNEL_MAPPING                                        (1U)
#define COMM_USER_SIZE                                                      (7U)
#define COMM_FULL_NMTYPEOFCHANNEL                                           (0x01U)
#define COMM_LIGHT_NMTYPEOFCHANNEL                                          (0x02U)
#define COMM_LINSLAVE_NMTYPEOFCHANNEL                                       (0x03U)
#define COMM_NONE_NMTYPEOFCHANNEL                                           (0x04U)
#define COMM_PASSIVE_NMTYPEOFCHANNEL                                        (0x05U)
#define COMM_EIRA_RX_TYPEOFPNCSIGNAL                                        (0x00U)
#define COMM_EIRA_TX_TYPEOFPNCSIGNAL                                        (0x01U)
#define COMM_ERA_RX_TYPEOFPNCSIGNAL                                         (0x02U)
#define COMM_EXISTS_ERA_RX_TYPEOFPNCSIGNAL                                  (STD_OFF)
#define COMM_EXISTS_EIRA_RX_TYPEOFPNCSIGNAL                                 (STD_ON)
#define COMM_EXISTS_EIRA_TX_TYPEOFPNCSIGNAL                                 (STD_OFF)
#define COMM_NO_PNCPBINDENDIDXOFCHANNELPB                                   (255U)
#define COMM_NO_PNCPBINDSTARTIDXOFCHANNELPB                                 (255U)
#define COMM_NO_USERPNCBYTEMASKENDIDXOFUSER                                 (255U)
#define COMM_NO_USERPNCBYTEMASKSTARTIDXOFUSER                               (255U)
#define COMM_NO_CHANNELIDXOFPNCSIGNAL                                       (255U)
#define COMM_NO_USERBYTEMASKSTARTIDXOFUSER                                  (255U)
#define COMM_NO_USERBYTEMASKENDIDXOFUSER                                    (255U)
#define ComM_GetPncSignalInd(Index)                                         ComM_PncSignalInd[(Index)]
#define ComM_GetPncChannelMapping(Index)                                    ComM_PncChannelMapping[(Index)]  /*channel id with pnc*/
#define ComM_GetClearMaskOfUserPncByteMask(Index)                           ComM_UserPncByteMask[(Index)].ClearMaskOfUserPncByteMask
#define ComM_GetSetMaskOfUserPncByteMask(Index)                             ComM_UserPncByteMask[(Index)].SetMaskOfUserPncByteMask
#define ComM_IsSignalPncBitSet(InternalSignalId, InternalPncId)             ((ComM_PncSignalValues[ComM_PncSignal[InternalSignalId].PncSignalValuesStartIdxOfPncSignal + ComM_PncPb[InternalPncId].SignalByteIndexOfPncPb] & ComM_Pnc[InternalPncId].SetMaskOfPnc) > 0u)


/* polyspace-end MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct ComM_InhibitionTypeTag
{
    ComM_InhibitionStatusType ComM_ECUGroupClassification;
    uint16 ComM_InhibitCnt;
    ComM_InhibitionStatusType ComM_InhibitionStatus[COMM_ACTIVE_CHANNEL];
} ComM_InhibitionType;

typedef uint8 ComM_PncIterType;
typedef uint8 ComM_SizeOfPncSignalType;
typedef uint8 ComM_SizeOfPncType;
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
typedef void (*ComM_TransitionFunctionType)(NetworkHandleType Channel);

/* Identifies the Partial Network Gateway behaviour of a ComMChannel. */
typedef enum
{
    COMM_GATEWAY_TYPE_ACTIVE,
    COMM_GATEWAY_TYPE_PASSIVE,
    COMM_GATEWAY_TYPE_NONE
} ComM_PncGatewayType;

typedef enum
{
    COMM_PNC_SIGNALTYPE_INVALID = 0U,
    COMM_PNC_SIGNALTYPE_UINT8 = 8U,
    COMM_PNC_SIGNALTYPE_UINT8_N = 9U,
    COMM_PNC_SIGNALTYPE_UINT16 = 16U,
    COMM_PNC_SIGNALTYPE_UINT32 = 32U,
    COMM_PNC_SIGNALTYPE_UINT64 = 64U
/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
} ComM_PncSignalDataType;


/* ComM/ComMConfigSet/ComMChannels */
typedef struct
{
    uint8 BusTypeOfChannel;             /* Identifies the bus type of the channel. */
    uint8 ComMCDDBusPrefix;             /* Prefix to be used for API calls to CDD. */
    uint8 ComMChannelID;                /* Channel identification number of the corresponding channel. */
    boolean ComMFullCommReqNotiEnable;  /* Defines if the optional SenderReceiver Port of Interface 
	                                       ComM_CurrentChannelRequest will be provided for this channel.*/
    uint16 ComMMainFunctionPeriod;      /* Specifies the period in seconds that the MainFunction 
	                                       has to be triggered with. */
    boolean ComMNoCom;                  /* Not allowed to change state of ComM channel to 
	                                       OMM_SILENT_COMMUNICATION or COMM_FULL_COMMUNICATION.*/
    boolean ComMNoWakeup;               /* Defines if an ECU is not allowed to wake-up the channel. */
    ComM_PncGatewayType ComMPncGatewayType; /* Identifies the Partial Network Gateway behaviour of a ComMChannel. */
    uint32 ComMNmLightTimeout;              /* Defines the timeout (in seconds) after COMM_FULL_COMMUNICATION 
	                                            sub-state COMM_FULL_COM_READY_SLEEP is left*/ 
    uint8 ComMNmVariant;           /* Defines the functionality of the networkmanagement. */
    boolean ComMPncNmRequest;      /* If this parameter equals true then every time a FULL 
	                                  Communication is requested due to a change in the PNC state machine to
                                      PNC_REQUESTED Nm shall be called using the API Nm_NetworkRequest.*/
    uint8 WakeupStateOfChannel;    /* Target channel state after a Passive Wake-up (Not standard)*/
} ComM_ChannelType;

/* Type used in ComM_ChannelPb */
typedef struct
{
    uint8 PncPbIndEndIdxOfChannelPb;            /* the end index of the 0:n relation pointing to ComM_PncPbInd */
    uint8 PncPbIndStartIdxOfChannelPb;          /* the start index of the 0:n relation pointing to ComM_PncPbInd */
    uint8 UserReqFullComEndIdxOfChannelPb;      /* the end index of the 0:n relation pointing to ComM_UserReqFullCom */
    uint8 UserReqFullComStartIdxOfChannelPb;    /* the start index of the 0:n relation pointing to ComM_UserReqFullCom */
} ComM_ChannelPbType;

/* Type used in ComM_UserByteMask */
typedef struct
{
    uint8 ChannelOfUserByteMask;            /* ID of the channel which is requested by this entry. */
    uint8 ClearMaskOfUserByteMask;          /* Clear-mask for clearing the bit which corresponds to this user */
    uint8 SetMaskOfUserByteMask;            /* Set-mask for setting the bit which corresponds to this user */
    uint8 UserReqFullComIdxOfUserByteMask;  /* the index of the 1:1 relation pointing to ComM_UserReqFullCom */
} ComM_UserByteMaskType;

/* Type used in ComM_User */
typedef struct
{
    uint8 PncUserOfUser;                    /* decides if a user is a partial network user or a direct channel user */
    uint8 UserByteMaskEndIdxOfUser;         /* the end index of the 0:n relation pointing to ComM_UserByteMask */
    uint8 UserByteMaskStartIdxOfUser;       /* the start index of the 0:n relation pointing to ComM_UserByteMask */
    uint8 UserPncByteMaskEndIdxOfUser;      /* the end index of the 0:n relation pointing to ComM_UserPncByteMask */
    uint8 UserPncByteMaskStartIdxOfUser;    /* the start index of the 0:n relation pointing to ComM_UserPncByteMask */
} ComM_UserType;

/* Type used in ComM_UserPncByteMask */
typedef struct
{
    uint8 ClearMaskOfUserPncByteMask;
    uint8 PncIDOfUserPncByteMask;                   /* System Id of the partial network which is requested by this entry */
    uint8 SetMaskOfUserPncByteMask;
    uint8 UserReqPncFullComIdxOfUserPncByteMask;    /* the index of the 1:1 relation pointing to ComM_UserReqPncFullCom */
} ComM_UserPncByteMaskType;

/* Type used in ComM_PncPb */
typedef struct
{
    uint8 PncChannelMappingEndIdxOfPncPb;       /* the end index of the 0:n relation pointing to ComM_PncChannelMapping */
    uint8 PncChannelMappingStartIdxOfPncPb;     /* the start index of the 0:n relation pointing to ComM_PncChannelMapping */
    uint8 PncSignalIndEndIdxOfPncPb;            /* the end index of the 0:n relation pointing to ComM_PncSignalInd */
    uint8 PncSignalIndStartIdxOfPncPb;          /* the start index of the 0:n relation pointing to ComM_PncSignalInd */
    uint8 SignalByteIndexOfPncPb; 
    uint8 UserReqPncFullComEndIdxOfPncPb;       /* the end index of the 1:n relation pointing to ComM_UserReqPncFullCom */
    uint8 UserReqPncFullComStartIdxOfPncPb;     /* the start index of the 1:n relation pointing to ComM_UserReqPncFullCom */
} ComM_PncPbType;

typedef struct
{
    boolean CoordinatedOfPnc; /* TRUE if PNC is coordinated */
    uint8 ClearMaskOfPnc;   /* Clear mask for the partial network related signals (EIRA, ERA) */
    uint8 PncIdOfPnc;       /* System ID of the partial network */
    uint8 SetMaskOfPnc;     /* Set mask for the partial network related signals (EIRA, ERA) */
    uint8 SystemUserOfPnc;  /* system user handle generated for the PNC if it is coordinated (255 otherwise) */
} ComM_PncType;

typedef struct
{
    uint8 ChannelIdxOfPncSignal;                /* the index of the 0:1 relation pointing to ComM_Channel */
    uint8 PncSignalValuesEndIdxOfPncSignal;     /* the end index of the 0:n relation pointing to ComM_PncSignalValues */
    uint8 PncSignalValuesStartIdxOfPncSignal;   /* the start index of the 0:n relation pointing to ComM_PncSignalValues */
    uint8 TypeOfPncSignal;                      /* ERA_RX, EIRA_TX,etc. Partial network signal type */

    /* Index of ComM_PncSignalInfoType ComM_PncSignalGroup[]. */
    uint8 StartIdxOfSignalGroup;
    /* The referenced signal shoud be referenced by a ComIpdu, and
    the ComIpdu may reference several signals.
    NumberOfSignalsInGroup records the number of referenced signals by the ComIpdu. */
    uint8 NumberOfSignalsInSignalGroup; /* maximum: 8 signals in a group. */
    uint8 ReferencedSignalIdxOfSignalGroup; /* directly Referenced Signal */
    uint8 SignalMask;      /* SET: send the signal, UNSET: do not send the signal. */
} ComM_PncSignalType;

typedef struct
{
    /* Bit size of the referenced signal.
 (/AUTOSAR/EcucDefs/Com/ComConfig/ComSignal/ComBitSize) */
    uint8 SignalBitSize;
    uint8 SignalByteSize;
    /* SignalType of the referenced signal.
 (/AUTOSAR/EcucDefs/Com/ComConfig/ComSignal/ComSignalType)
 UINT8, UINT16, UINT32, etc. Refer to ComM_PncSignalDataType. */
    uint8 SignalDataType; 
 /* Com_SignalIdType of the the referenced signal. */
    uint16 SignalId;
} ComM_PncSignalInfoType;

/*
*******************************************************************************
*    Global variable
*******************************************************************************
*/
#define COMM_START_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "ComM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

extern CONST(ComM_UserByteMaskType, COMM_CONFIG_DATA) ComM_UserByteMask[COMM_NUM_USER_BYTE_MASK];
extern CONST(ComM_ChannelType, COMM_CONFIG_DATA) ComM_Channel[COMM_ACTIVE_CHANNEL];
extern CONST(ComM_ChannelPbType, COMM_CONFIG_DATA) ComM_ChannelPb[COMM_ACTIVE_CHANNEL];
extern CONST(ComM_UserType, COMM_CONFIG_DATA) ComM_User[COMM_USER_SIZE];

#if (COMM_PNCSUPPORT == STD_ON)
extern CONST(ComM_UserPncByteMaskType, COMM_CONFIG_DATA) ComM_UserPncByteMask[COMM_NUM_USER_PNC_BYTE_MASK];
extern CONST(ComM_PncPbType, COMM_CONFIG_DATA) ComM_PncPb[COMM_PNC_SIZE];
extern CONST(uint8, COMM_CONFIG_DATA) ComM_PncPbInd[COMM_NUM_PNC_PBIND];
extern CONST(uint8, COMM_CONFIG_DATA) ComM_PncSignalInd[COMM_NUM_PNC_SIGNALIND];
extern CONST(uint8, COMM_CONFIG_DATA) ComM_PncChannelMapping[COMM_NUM_PNC_CHANNEL_MAPPING];
extern CONST(ComM_PncSignalType, COMM_CONFIG_DATA) ComM_PncSignal[COMM_SIGNAL_NUM];
extern CONST(ComM_PncType, COMM_CONFIG_DATA) ComM_Pnc[COMM_PNC_SIZE];
#endif

#define COMM_STOP_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "ComM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
*******************************************************************************
*    Global Constants
*******************************************************************************
*/
/*
*******************************************************************************
*    Global Functions
*******************************************************************************
*/
/* polyspace-begin MISRA-C3:8.5 [Justified:Unset] "NSCA_Polyspace_ComM_Rule8.5" */
#define COMM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "ComM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

extern FUNC(void, COMM_CODE) ComM_MainFunction_0(void);

extern FUNC(void, COMM_CODE) ComM_MainFunction_1(void);

extern FUNC(void, COMM_CODE) ComM_MainFunction_2(void);

extern FUNC(void, COMM_CODE) ComM_MainFunction_3(void);

extern FUNC(void, COMM_CODE) ComM_MainFunction_4(void);

extern FUNC(void, COMM_CODE) ComM_MainFunction_5(void);

extern FUNC(void, COMM_CODE) ComM_MainFunction_6(void);

#if (COMM_PNCSUPPORT == STD_ON)
extern FUNC(void, COMM_CODE) ComM_ExecuteComSendSignal(ComM_SizeOfPncSignalType InternalSignalId, P2CONST(uint8, AUTOMATIC, COMM_APPL_DATA) SignalDataTx);
#endif

#define COMM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "ComM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/* polyspace-end MISRA-C3:8.5 [Justified:Unset] "NSCA_Polyspace_ComM_Rule8.5" */
#endif  /* COMM_LCFG_H_ */

