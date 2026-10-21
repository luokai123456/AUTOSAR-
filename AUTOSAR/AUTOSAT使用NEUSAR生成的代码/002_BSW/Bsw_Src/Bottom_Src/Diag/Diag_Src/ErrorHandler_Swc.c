/**********************************************************************************************************************
*
* COPYRIGHT RESERVED, Tianjin Yidingfeng Power Technology, 2012. All rights reserved.
* The reproduction, distribution and utilization of this document as well as the communication of its contents to
* others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
* All rights reserved in the event of the grant of a patent, utility model or design.
*
**********************************************************************************************************************
* Administrative Information
* Namespace_:
* Class_____:C
* Name______:ErrorDiag_Swc
* Variant___:75.16.01
* Revision__:0
**********************************************************************************************************************
 * History___:
 *
 * 75.16.01; 0     10.04.2024 SH-RD  Xiangyu.Zhu
 *   N: new created
 *
 * 
 * 
 * 
***********************************************************************************************************************/


/****************************************************************************************/
/*  Includes */
/****************************************************************************************/

#include "ErrorHandler_Swc.h"
#include "ErrorDiag_Swc.h"
#include "ErrorHandler_ReactionCfg.h"
#include "ErrorHandler_ErrorReaction.h"
#if (EH_CFG_REPORT_DTC_EN == STD_ON) && (EH_CFG_NO_DEM_H == STD_OFF)
#include "Dem.h"
#endif


/****************************************************************************************/
/*  Macro */
/****************************************************************************************/
#define EH_CUST_REQ_SW_RESET ((uint32) 0x5AA55A5A)
#define EH_CUST_REQ_ERRORPIN ((uint32) 0x5A5AA55A)

/****************************************************************************************/
/*  Function */
/****************************************************************************************/
static void EH_PerformReaction(uint16 errorId, boolean isASW, boolean firstRun);
static void EH_Report_LastWill_DTC_Task(uint16 errorId, uint16 eventId, uint8 reaction);
static void EH_Report_DTC_Task(uint16 errorId, uint16 eventId, uint8 errorStatus);
static void ErrorHandler_checkCustRequest(void);

#if (EH_CFG_REPORT_DTC_EN == STD_ON) && (EH_CFG_NO_DEM_H == STD_ON) // Dem.h not available
typedef unsigned short Dem_EventIdType;
typedef unsigned char  Dem_EventStatusType;

#define DEM_EVENT_STATUS_PASSED ((Dem_EventStatusType)0x00U)
#define DEM_EVENT_STATUS_FAILED ((Dem_EventStatusType)0x01U)

extern Std_ReturnType Dem_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus);
#endif

/****************************************************************************************/
/*  Variable */
/****************************************************************************************/
extern uint8 EH_ErrStatusBitmap_ASW[];

#define ERRORDIAG_START_SEC_VAR_CLEAR_ASIL_C_8
#include "ErrorDiag_MemMap.h"

#if EH_DRIVER_SUPPRESS_CHANNEL_NUM > 0
static uint8 EH_valDisDriverChannel_MP[EH_DRIVER_SUPPRESS_CHANNEL_NUM];
#endif

#if L2_DIS_NUM_MAX > 0
static uint8 EH_valL2DisDriver[L2_DIS_NUM_MAX];
#endif

static uint8 EH_ErrStatusBitmap_BSW[(ERRORDIAG_ID_NUM_BSW + 7U) / 8U];

#define ERRORDIAG_STOP_SEC_VAR_CLEAR_ASIL_C_8
#include "ErrorDiag_MemMap.h"

#define ERRORDIAG_START_SEC_VAR_CLEAR_ASIL_C_16
#include "ErrorDiag_MemMap.h"
#if EH_DRIVER_SUPPRESS_CHANNEL_NUM > 0
static uint16 EH_valDisDriverRefCnt_MP[EH_DRIVER_SUPPRESS_CHANNEL_NUM]; // reference counter
#endif
#if L2_DIS_NUM_MAX > 0
static uint16 EH_valL2DisRefCnt_MP[L2_DIS_NUM_MAX]; // reference counter
#endif
#define ERRORDIAG_STOP_SEC_VAR_CLEAR_ASIL_C_16
#include "ErrorDiag_MemMap.h"

#define ERRORDIAG_START_SEC_VAR_INIT_ASIL_C_8
#include "ErrorDiag_MemMap.h"

static boolean EH_MainFunction_FirstRun = TRUE;

#define ERRORDIAG_STOP_SEC_VAR_INIT_ASIL_C_8
#include "ErrorDiag_MemMap.h"


#define ERRORDIAG_START_SEC_VAR_INIT_ASIL_C_32
#include "ErrorDiag_MemMap.h"
static uint32 EH_custReqType;
#define ERRORDIAG_STOP_SEC_VAR_INIT_ASIL_C_32
#include "ErrorDiag_MemMap.h"


/****************************************************************************************/
/*  code */
/****************************************************************************************/
#define ERRORDIAG_START_SEC_CODE_ASIL_C
#include "ErrorDiag_MemMap.h"


static void EH_SetErrorBitmap(uint16 errorId, uint8 errorStatus, uint8 *bitmapPtr)
{
	uint16 byte_index;
	uint8 bit_index, bit_mask;

	/* called internally, errorId < ERRORDIAG_ID_NUM_MAX is guaranteed */
	byte_index = errorId / 8U;
	bit_index = (uint8)(errorId % 8U);
	bit_mask = (uint8)(1U << bit_index);

	if (errorStatus == ((uint8) E_NOT_OK))
	{
		bitmapPtr[byte_index] |= bit_mask;
	}
	else
	{
		bitmapPtr[byte_index] &= (uint8)~bit_mask;
	}
}

/* Function to get the state of a bit in the bitmap */
static uint8 EH_GetErrorBitmap(uint16 errorId, uint8 *bitmapPtr)
{
    uint8 result = 0u;
	uint16 byte_index;
	uint8 bit_index, bit_mask;

	/* called internally, errorId < ERRORDIAG_ID_NUM_MAX is guaranteed */
	byte_index = errorId / 8U;
	bit_index = (uint8)(errorId % 8U);
	bit_mask = (uint8)(1U << bit_index);

	result = ((bitmapPtr[byte_index] & bit_mask) == bit_mask) ? ((uint8) E_NOT_OK) : ((uint8) E_OK);

    return result;
}


static const EH_ConfigReaction_TDSTR* EH_GetReactionCfg(uint16 errorId, boolean isASW) {
	if (!isASW) {
		return &EH_Reaction_Cfg[errorId];
	} else {
		return &EH_ASW_Reaction_Cfg[errorId];
	}
}


static inline uint16 EH_GetDtcByIndex(uint16 dtcIdx, boolean isAsw) {
	uint16 dtcTotalNum;
	const uint16 *dtcCfgArr;

	if (isAsw == TRUE) {
		dtcTotalNum = EH_Reaction_AswDtcNum;
		dtcCfgArr = EH_Reaction_DtcCfg_ASW;
	} else {
		dtcTotalNum = EH_Reaction_BswDtcNum;
		dtcCfgArr = EH_Reaction_DtcCfg_BSW;
	}

	if (dtcIdx >= dtcTotalNum) {
		return EH_DTC_INVALID;
	} else {
		return dtcCfgArr[dtcIdx];
	}
}


/*****************************************************************************
** Service Name       : ErrorHandler_Init                                               
** 
**  Description      :  ErrorHandler_Init,  Initial variables of diagnostic result
**                                                                               
**  Parameters (in)  :  None                         
**                                                                           
**  Parameters (in)  :  None                           
**    
**  Parameters (out) :  None                                                   
**                                                                            
**  Return value     :  None                                                    
**                                                                            
******************************************************************************/
void ErrorHandler_Init(void)
{
	/* Do nothing */
}


/*****************************************************************************
** Service Name       : ErrorHandler_MainFunction                                               
** 
**  Description      :  10ms period task. 
                        The main function of Errorhandler
                        It is used to execute Error Reaction based on diag result.
**                                                                               
**  Parameters (in)  :  None                         
**                                                                           
**  Parameters (in)  :  None                           
**    
**  Parameters (out) :  None                                                   
**                                                                            
**  Return value     :  None                                                    
**                                                                            
******************************************************************************/
void ErrorHandler_MainFunction(void)
{
	uint16 errorId;
	uint16 bswNum = ErrorDiag_GetBswNum();
	uint16 aswNum = ErrorDiag_GetAswNum();

	for (errorId = 0; errorId < bswNum; errorId++) {
		EH_PerformReaction(errorId, FALSE, EH_MainFunction_FirstRun);
	}

	for (errorId = 0; errorId < aswNum; errorId++) {
		EH_PerformReaction(errorId, TRUE, EH_MainFunction_FirstRun);
	}

	ErrorHandler_checkCustRequest();

	EH_MainFunction_FirstRun = FALSE;
}


static void EH_Report_LastWill_DTC_Task(uint16 errorId, uint16 eventId, uint8 reaction)
{
#if (EH_CFG_REPORT_DTC_EN == STD_ON)
	if (ErrorDiag_GetLastWill(errorId) == ED_LASTWILL_STATE_ISSUED)
	{
		if (reaction == EH_REACTION_RESET_SW)
		{
			(void) Dem_SetEventStatus(eventId, DEM_EVENT_STATUS_FAILED);
			ErrorDiag_FinishLastWill(errorId);
		} 
		else
		{
			/* reaction is not SW_RESRT, no lastwill */
			ErrorDiag_ClearLastWill(errorId);
		}
	}
#endif
}


static void EH_Report_DTC_Task(uint16 errorId, uint16 eventId, uint8 errorStatus)
{
#if (EH_CFG_REPORT_DTC_EN == STD_ON)
	if(ErrorDiag_GetLastWill(errorId) == ED_LASTWILL_STATE_NONE)
	{
		if(errorStatus == ED_Status_NOK)
		{
			/* relay on Autosar DEM Interface*/
			(void) Dem_SetEventStatus(eventId, DEM_EVENT_STATUS_FAILED);
		}
		else
		{
			/* relay on Autosar DEM Interface*/
			(void) Dem_SetEventStatus(eventId, DEM_EVENT_STATUS_PASSED);
		}
	}
	else
	{
	  /* Do Nothing */ 
	}
#endif
}


uint8 EH_GetOutputDisFlag(uint8 numDIsDriverCh_LO)
{
#if EH_DRIVER_SUPPRESS_CHANNEL_NUM > 0
	if(numDIsDriverCh_LO >= EH_DRIVER_SUPPRESS_CHANNEL_NUM)
	{
		return 0; /* Return 0 if index is out of bounds */
	}
	return EH_valDisDriverChannel_MP[numDIsDriverCh_LO];
#else
	return 0;
#endif
}


void EH_SetOutputDisFlag(uint8 numDIsDriverCh_LO, uint8 fgDisOutput_LO)
{
#if EH_DRIVER_SUPPRESS_CHANNEL_NUM > 0
	if(numDIsDriverCh_LO >= EH_DRIVER_SUPPRESS_CHANNEL_NUM)
	{
		return;
	}
	EH_valDisDriverChannel_MP[numDIsDriverCh_LO] = fgDisOutput_LO;
#else
	return;
#endif
}


/**
 * 函数名称: EH_PerformReaction
 * 参数In: errorId
 * 参数Out: args
 * 返回值: 
 * 描述: description
 */
static void EH_PerformReaction(uint16 errorId, boolean isAsw, boolean firstRun) {
	uint8 lastStatus, curStatus;
	const EH_ConfigReaction_TDSTR *reactionCfg = EH_GetReactionCfg(errorId, isAsw);
	uint8 *bitmapPtr;
	uint8 reaction = reactionCfg->Reactions;
	uint16 packedErrId = errorId;
	uint16 eventId = EH_GetDtcByIndex(reactionCfg->DtcIdx, isAsw);
	void (*reactionFunc)(uint16) = NULL_PTR;

	if (reaction != EH_REACTION_NONE || eventId != EH_DTC_INVALID) {
		if (isAsw) {
			bitmapPtr = EH_ErrStatusBitmap_ASW;
			packedErrId = ED_PACK(errorId);
		} else {
			bitmapPtr = EH_ErrStatusBitmap_BSW;
		}

		lastStatus = EH_GetErrorBitmap(errorId, bitmapPtr);
		curStatus = ErrorDiag_Receive_ErrorStatus(packedErrId);

		if ((lastStatus == ((uint8) E_OK)) && (curStatus == ((uint8) E_NOT_OK))) {
			// E_OK => E_NOT_OK, report
			reactionFunc = EH_Reaction_Func[reaction].EH_Error_Detect_Action_Func;
		} else if ((lastStatus == ((uint8) E_NOT_OK)) && (curStatus == ((uint8) E_OK))) {
			// E_NOT_OK => E_OK, recover
			reactionFunc = EH_Reaction_Func[reaction].EH_Error_Recover_Action_Func;
		} else {
			/* Do nothing */
		}

		if (reactionFunc != NULL_PTR) {
			reactionFunc(packedErrId);
		}
	
		if (eventId != EH_DTC_INVALID) {
			if (firstRun == TRUE) {
				EH_Report_LastWill_DTC_Task(packedErrId, eventId, reaction);
			}
			EH_Report_DTC_Task(packedErrId, eventId, curStatus);
		}
		
		/* update error status after compare */
		EH_SetErrorBitmap(errorId, curStatus, bitmapPtr);
	}
}


void ErrorHandler_ResetAndReport(uint16 ErrorId) {
	ED_Update_ReportId_Variable(ErrorId);
	ErrorHandler_Callback_PerformSwReset(ED_ERRORID_INVALID);
}


#if (EH_L2_ENABLE_NUM > 0 && EH_CFG_NO_L2_SHUTDOWN == STD_OFF)
uint8 EH_GetL2DriverOff(uint8 numDIsDriverCh_LO) {
	if (numDIsDriverCh_LO < L2_DIS_NUM_MAX) {
		return EH_valL2DisDriver[numDIsDriverCh_LO];
	}

	return 0u;
}
#endif


#if (EH_L2_ENABLE_NUM > 0 && EH_CFG_NO_L2_SHUTDOWN == STD_OFF)
void EH_SetL2DriverOff(uint8 numDIsDriverCh_LO, uint8 fgDisOutput_LO) {
	if (numDIsDriverCh_LO < L2_DIS_NUM_MAX) {
		EH_valL2DisDriver[numDIsDriverCh_LO] = fgDisOutput_LO;
	}
}
#endif


#if (EH_CFG_CUST_RESET_EN == STD_ON)
void ErrorHandler_RequestReset(void) {
	EH_custReqType = EH_CUST_REQ_SW_RESET;
}
#endif


#if (EH_CFG_CUST_ERRPIN_EN == STD_ON)
void ErrorHandler_RequestSetErrorPin(void) {
	EH_custReqType = EH_CUST_REQ_ERRORPIN;
}
#endif


static void ErrorHandler_checkCustRequest(void) {
	if (EH_custReqType != 0u) {
#if (EH_CFG_CUST_RESET_EN == STD_ON)
		if (EH_custReqType == EH_CUST_REQ_SW_RESET) {
			EH_custReqType = 0;
			ED_Update_ReportId_Variable(ERRORID_MCU_APP_Request_Reset);
			ErrorHandler_Callback_PerformSwReset(0u);
		}
#endif /* (EH_CFG_CUST_RESET_EN == STD_ON) */
#if (EH_CFG_CUST_ERRPIN_EN == STD_ON)
		if (EH_custReqType == EH_CUST_REQ_ERRORPIN) {
			EH_custReqType = 0;
			ED_Update_ReportId_Variable(ERRORID_MCU_APP_Request_FCCU);
			ErrorHandler_Callback_SetErrorPin(0u);
		}
#endif /* (EH_CFG_CUST_ERRPIN_EN == STD_ON) */
	}
}


#if (EH_L2_ENABLE_NUM > 0)
void EH_L2RefCounterInc(uint8 numDIsDriverCh_LO) {
	if (numDIsDriverCh_LO < L2_DIS_NUM_MAX) {
		if (EH_valL2DisRefCnt_MP[numDIsDriverCh_LO] < 0xFFFFu) {
			EH_valL2DisRefCnt_MP[numDIsDriverCh_LO]++;
		}
	}
}


void EH_L2RefCounterDec(uint8 numDIsDriverCh_LO) {
	if (numDIsDriverCh_LO < L2_DIS_NUM_MAX) {
		if (EH_valL2DisRefCnt_MP[numDIsDriverCh_LO] > 0) {
			EH_valL2DisRefCnt_MP[numDIsDriverCh_LO]--;
		}
	}
}


uint16 EH_GetL2RefCounter(uint8 numDIsDriverCh_LO) {
	if (numDIsDriverCh_LO < L2_DIS_NUM_MAX) {
		return EH_valL2DisRefCnt_MP[numDIsDriverCh_LO];
	}

	return 0xFFFFu;
}
#endif /* EH_L2_ENABLE_NUM > 0 */


#if (EH_DRIVER_SUPPRESS_NUM > 0)
void EH_DrvRefCounterInc(uint8 numDIsDriverCh_LO) {
	if (numDIsDriverCh_LO < EH_DRIVER_SUPPRESS_CHANNEL_NUM) {
		if (EH_valDisDriverRefCnt_MP[numDIsDriverCh_LO] < 0xFFFFu) {
			EH_valDisDriverRefCnt_MP[numDIsDriverCh_LO]++;
		}
	}
}


void EH_DrvRefCounterDec(uint8 numDIsDriverCh_LO) {
	if (numDIsDriverCh_LO < EH_DRIVER_SUPPRESS_CHANNEL_NUM) {
		if (EH_valDisDriverRefCnt_MP[numDIsDriverCh_LO] > 0u) {
			EH_valDisDriverRefCnt_MP[numDIsDriverCh_LO]--;
		}
	}
}


uint16 EH_GetDrvRefCounter(uint8 numDIsDriverCh_LO) {
	if (numDIsDriverCh_LO < EH_DRIVER_SUPPRESS_CHANNEL_NUM) {
		return EH_valDisDriverRefCnt_MP[numDIsDriverCh_LO];
	}

	return 0xFFFFu;
}
#endif /* EH_DRIVER_SUPPRESS_NUM > 0 */


#define ERRORDIAG_STOP_SEC_CODE_ASIL_C
#include "ErrorDiag_MemMap.h"
