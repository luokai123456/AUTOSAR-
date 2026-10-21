/*PRQA S 1535 EOF*/
/*
 * Fr_GeneralTypes.h
 *
 *  Created on: 2024��2��21��
 *      Author: zhangjingrong
 */
/*PRQA S 0722,1536 EOF*/
#ifndef LLD_INC_FR_GENERALTYPES_H_
#define LLD_INC_FR_GENERALTYPES_H_

#include "Mcal.h"
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/* FR_GENERALTYPES_H_003: FR117, SWS_Fr_00117, FR657, SWS_Fr_00657 */
/* FR_GENERALTYPES_H_004: FR110, SWS_Fr_00110, FR077, SWS_Fr_00077 */
/*******************************************************************************
**                      Type definitions                                      **
*******************************************************************************/

#define FR_LAST_MB            0xFFU  /* Used in buffer configuration structure to determine the last used MB */

#define  FR_CIDX_GDCYCLE                         0U
#define  FR_CIDX_PMICROPERCYCLE                  1U
#define  FR_CIDX_PDLISTENTIMEOUT                 2U
#define  FR_CIDX_GMACROPERCYCLE                  3U
#define  FR_CIDX_GDMACROTICK                     4U
#define  FR_CIDX_GNUMBEROFMINISLOTS              5U
#define  FR_CIDX_GNUMBEROFSTATICSLOTS            6U
#define  FR_CIDX_GDNIT                           7U
#define  FR_CIDX_GDSTATICSLOT                    8U
#define  FR_CIDX_GDWAKEUPRXWINDOW                9U
#define  FR_CIDX_PKEYSLOTID                      10U
#define  FR_CIDX_PLATESTTX                       11U
#define  FR_CIDX_POFFSETCORRECTIONOUT            12U
#define  FR_CIDX_POFFSETCORRECTIONSTART          13U
#define  FR_CIDX_PRATECORRECTIONOUT              14U
#define  FR_CIDX_PSECONDKEYSLOTID                15U
#define  FR_CIDX_PDACCEPTEDSTARTUPRANGE          16U
#define  FR_CIDX_GCOLDSTARTATTEMPTS              17U
#define  FR_CIDX_GCYCLECOUNTMAX                  18U
#define  FR_CIDX_GLISTENNOISE                    19U
#define  FR_CIDX_GMAXWITHOUTCLOCKCORRECTFATAL    20U
#define  FR_CIDX_GMAXWITHOUTCLOCKCORRECTPASSIVE  21U
#define  FR_CIDX_GNETWORKMANAGEMENTVECTORLENGTH  22U
#define  FR_CIDX_GPAYLOADLENGTHSTATIC            23U
#define  FR_CIDX_GSYNCFRAMEIDCOUNTMAX            24U
#define  FR_CIDX_GDACTIONPOINTOFFSET             25U
#define  FR_CIDX_GDBIT                           26U
#define  FR_CIDX_GDCASRXLOWMAX                   27U
#define  FR_CIDX_GDDYNAMICSLOTIDLEPHASE          28U
#define  FR_CIDX_GDMINISLOTACTIONPOINTOFFSET     29U
#define  FR_CIDX_GDMINISLOT                      30U
#define  FR_CIDX_GDSAMPLECLOCKPERIOD             31U
#define  FR_CIDX_GDSYMBOLWINDOW                  32U
#define  FR_CIDX_GDSYMBOLWINDOWACTIONPOINTOFFSET 33U
#define  FR_CIDX_GDTSSTRANSMITTER                34U
#define  FR_CIDX_GDWAKEUPRXIDLE                  35U
#define  FR_CIDX_GDWAKEUPRXLOW                   36U
#define  FR_CIDX_GDWAKEUPTXACTIVE                37U
#define  FR_CIDX_GDWAKEUPTXIDLE                  38U
#define  FR_CIDX_PALLOWPASSIVETOACTIVE           39U
#define  FR_CIDX_PCHANNELS                       40U
#define  FR_CIDX_PCLUSTERDRIFTDAMPING            41U
#define  FR_CIDX_PDECODINGCORRECTION             42U
#define  FR_CIDX_PDELAYCOMPENSATIONA             43U
#define  FR_CIDX_PDELAYCOMPENSATIONB             44U
#define  FR_CIDX_PMACROINITIALOFFSETA            45U
#define  FR_CIDX_PMACROINITIALOFFSETB            46U
#define  FR_CIDX_PMICROINITIALOFFSETA            47U
#define  FR_CIDX_PMICROINITIALOFFSETB            48U
#define  FR_CIDX_PPAYLOADLENGTHDYNMAX            49U
#define  FR_CIDX_PSAMPLESPERMICROTICK            50U
#define  FR_CIDX_PWAKEUPCHANNEL                  51U
#define  FR_CIDX_PWAKEUPPATTERN                  52U
#define  FR_CIDX_PDMICROTICK                     53U
#define  FR_CIDX_GDIGNOREAFTERTX                 54U
#define  FR_CIDX_PALLOWHALTDUETOCLOCK            55U
#define  FR_CIDX_PEXTERNALSYNC                   56U
#define  FR_CIDX_PFALLBACKINTERNAL               57U
#define  FR_CIDX_PKEYSLOTONLYENABLED             58U
#define  FR_CIDX_PKEYSLOTUSEDFORSTARTUP          59U
#define  FR_CIDX_PKEYSLOTUSEDFORSYNC             60U
#define  FR_CIDX_PNMVECTOREARLYUPDATE            61U
#define  FR_CIDX_PTWOKEYSLOTMODE                 62U

/* FR_GENERALTYPES_H_007: FR599, SWS_Fr_00599 */
#define  FR_SLOTMODE_SINGLE     FR_SLOTMODE_KEYSLOT

/* FR_GENERALTYPES_H_005: FR505, SWS_Fr_00505, FR_ESDD_UD_069 */
/*******************************************************************************
**                      Fr_POCStateType                                       **
*******************************************************************************/


/* FR_GENERALTYPES_H_006: FR506, SWS_Fr_00506, FR_ESDD_UD_070 */
/*******************************************************************************
**                      Fr_SlotModeType                                       **
*******************************************************************************/
typedef enum ETag_Fr_SlotModeType
{
    FR_SLOTMODE_KEYSLOT = 0,
    FR_SLOTMODE_ALL_PENDING,
    FR_SLOTMODE_ALL
} Fr_SlotModeType;


/* FR_GENERALTYPES_H_008: FR507, SWS_Fr_00507, FR_ESDD_UD_071 */
/*******************************************************************************
**                      Fr_ErrorModeType                                      **
*******************************************************************************/
typedef enum ETag_Fr_ErrorModeType
{
    FR_ERRORMODE_ACTIVE = 0,
    FR_ERRORMODE_PASSIVE,
    FR_ERRORMODE_COMM_HALT
} Fr_ErrorModeType;



/* FR_GENERALTYPES_H_010: FR509, SWS_Fr_00509, FR_ESDD_UD_073 */
/*******************************************************************************
**                      Fr_StartupStateType                                   **
*******************************************************************************/
typedef enum ETag_Fr_StartupStateType
{
    FR_STARTUP_UNDEFINED = 0,
    FR_STARTUP_COLDSTART_LISTEN,
    FR_STARTUP_INTEGRATION_COLDSTART_CHECK,
    FR_STARTUP_COLDSTART_JOIN,
    FR_STARTUP_COLDSTART_COLLISION_RESOLUTION,
    FR_STARTUP_COLDSTART_CONSISTENCY_CHECK,
    FR_STARTUP_INTEGRATION_LISTEN,
    FR_STARTUP_INITIALIZE_SCHEDULE,
    FR_STARTUP_INTEGRATION_CONSISTENCY_CHECK,
    FR_STARTUP_COLDSTART_GAP,
    FR_STARTUP_EXTERNAL_STARTUP
} Fr_StartupStateType;

typedef enum ETag_Fr_OffsetCorrectionType
{
    FR_OFFSET_INC = 0,
    FR_OFFSET_DEC,
    FR_OFFSET_NOCHANGE
} Fr_OffsetCorrectionType;
/*******************************************************************************
**                     Fr_RateCorrectionType                                  **
*******************************************************************************/
typedef enum ETag_Fr_RateCorrectionType
{
    FR_RATE_INC = 0,
    FR_RATE_DEC,
    FR_RATE_NOCHANGE
} Fr_RateCorrectionType;


/******************************************************************************
* Types
******************************************************************************/

/* The values of this enumeration are used to determine if communication stops
 immediately or at the end of current FlexRay cycle */
typedef enum
{
    FR_HALT_COMMUNICATION = 0U,
    FR_ABORT_COMMUNICATION
} Fr_stop_communication_type;

/* The values of this enumeration are used to provide information whether or not the
 local FlexRay CC is synchronous to the FR global time */
typedef enum
{
    FR_ASYNC = 0U,
    FR_SYNC
} Fr_sync_state_type;

/* The values are used to hold the protocol state */
typedef enum
{
    FR_POCSTATE_CONFIG = 0U,
    FR_POCSTATE_DEFAULT_CONFIG,
    FR_POCSTATE_HALT,
    FR_POCSTATE_NORMAL_ACTIVE,
    FR_POCSTATE_NORMAL_PASSIVE,
    FR_POCSTATE_READY,
    FR_POCSTATE_STARTUP,
    FR_POCSTATE_WAKEUP
} Fr_POCStateType;

/* These values are used to determine if a data has been transmitted
For single message buffers are used only the FR_TRANSMITTED and FR_NOT_TRANSMITTED values */
typedef enum
{
    FR_TRANSMITTED = 0U,
    FR_TRANSMITTED_CONFLICT,
    FR_NOT_TRANSMITTED
} Fr_TxLPduStatusType;


/* These values are used to determine if a message buffer has received a frame */
typedef enum
{
    FR_RECEIVED = 0U,
    FR_NOT_RECEIVED,
    FR_RECEIVED_MORE_DATA_AVAILABLE
} Fr_RxLPduStatusType;



/* The values determine the state of the wakeup mechanism */
typedef enum
{
    FR_WAKEUP_UNDEFINED = 0U,
    FR_WAKEUP_RECEIVED_HEADER,
    FR_WAKEUP_RECEIVED_WUP,
    FR_WAKEUP_COLLISION_HEADER,
    FR_WAKEUP_COLLISION_WUP,
    FR_WAKEUP_COLLISION_UNKNOWN,
    FR_WAKEUP_TRANSMITTED
} Fr_WakeupStatusType;



/* The values are used to reference a channel on a CC */
typedef enum
{
    FR_CHANNEL_A = 0U,
    FR_CHANNEL_B,
    FR_CHANNEL_AB
} Fr_ChannelType;



typedef struct
{
    /* Enable/Disable reporting of DEM messages */
    const uint32 state;
    /* ID of DEM message */
    const uint32 id;
} Fr_DemErrorType;


typedef  struct STag_Fr_SlotAssignmentType
{
    uint8                Cycle;
    uint16               SlotId;
    Fr_ChannelType       channelId;
} Fr_SlotAssignmentType;

typedef  struct STag_Fr_POCStatusType
{
    boolean                CHIHaltRequest;
    boolean                ColdstartNoise;
    Fr_ErrorModeType       ErrorMode;
    boolean                Freeze;
    Fr_SlotModeType        SlotMode;
    Fr_StartupStateType    StartupState;
    Fr_POCStateType        State;
    Fr_WakeupStatusType    WakeupStatus;
    boolean                CHIReadyRequest;
} Fr_POCStatusType;

#endif /* LLD_INC_FR_GENERALTYPES_H_ */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
