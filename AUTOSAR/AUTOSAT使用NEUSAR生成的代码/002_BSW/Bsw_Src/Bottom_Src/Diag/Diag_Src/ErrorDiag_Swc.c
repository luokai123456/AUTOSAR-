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


#include "ErrorDiag_Swc.h"
#include "ErrorDiag_Cfg.h"
#include "ErrorDiag_DriverCtrl_Diag.h"
#include "ErrorDiag_MCU_Diag.h"
#if (ED_CFG_LATEST_ERROR_RECORD == STD_ON)
#include "ResetCause.h"
#endif

/*********************************** Macro *****************************************************/
#define EH_REPORT_ERRORID_NUM_MAX (20u)


/*********************************** Function *****************************************************/
static void ErrorDiag_checkLastWill(void);



/*********************************** variable *****************************************************/
// Error status in ASW
extern ErrorDiag_Status_params_t ErrorDiag_ErrorStatus_ASW[];
/* Total number of all errors, value assigned by asw */
extern const uint16 ErrorDiag_Id_Num_Asw;
/* Number of ASW suppressions, value assigned by asw */
extern const uint16 ErrorDiag_Asw_AswSupNum;


#define ERRORDIAG_START_SEC_VAR_CLEAR_ASIL_C_8
#include "ErrorDiag_MemMap.h"
static uint8 ErrorDiag_LastWillNumBak;
#define ERRORDIAG_STOP_SEC_VAR_CLEAR_ASIL_C_8
#include "ErrorDiag_MemMap.h"


#define ERRORDIAG_START_SEC_VAR_CLEAR_ASIL_C_UNSPECIFIED
#include "ErrorDiag_MemMap.h"
static ErrorDiag_Status_params_t ErrorDiag_ErrorStatus_BSW[ERRORDIAG_ID_NUM_BSW];
#define ERRORDIAG_STOP_SEC_VAR_CLEAR_ASIL_C_UNSPECIFIED
#include "ErrorDiag_MemMap.h"


/* Using for diagnostic record. It store the lastest 20 Errorid. 
   Even this error is recover, it will not clear in this array  */
#if (ED_CFG_LATEST_ERROR_RECORD == STD_ON)
uint16 ED_ErrorIdStatus_au16[EH_REPORT_ERRORID_NUM_MAX] __attribute__((section (".reset_keep")));
uint8 ErrorDiag_LastWillNum __attribute__((section (".reset_keep")));
#endif


#define ERRORDIAG_START_SEC_CODE_ASIL_C
#include "ErrorDiag_MemMap.h"


static const ErrorDiag_ConfigStatus_params_t* ED_GetErrorCfg(uint16 errorId) {
	if (!ED_IS_ASW_ERROR(errorId)) {
		return &ED_ConfigParams_Cfg[errorId];
	} else {
		return &ED_ASW_ConfigParams_Cfg[ED_UNPACK(errorId)];
	}
}


static uint16 ED_GetSuppressionCfg(uint16 suppressIdx, uint16 errorId, uint16 subIdx) {
	if (!ED_IS_ASW_ERROR(errorId)) {
#if ED_SUPPRESS_NUM_BSW > 0
		return ED_ErrSuppress_Cfg[suppressIdx][subIdx];
#else
		return ED_ERRORID_INVALID;
#endif
	} else {
		if (ErrorDiag_Asw_AswSupNum > 0) {
			return ED_ASW_ErrSuppress_Cfg[suppressIdx][subIdx];
		} else {
			return ED_ERRORID_INVALID;
		}
	}
}


static ErrorDiag_Status_params_t* ED_GetErrorStatus(uint16 errorId) {
	if (!ED_IS_ASW_ERROR(errorId)) {
		return &ErrorDiag_ErrorStatus_BSW[errorId];
	} else {
		return &ErrorDiag_ErrorStatus_ASW[ED_UNPACK(errorId)];
	}
}


static boolean ED_IsErrorIdValid(uint16 errorId) {
	if (ED_IS_ASW_ERROR(errorId)) {
		return ED_UNPACK(errorId) < ErrorDiag_Id_Num_Asw;
	} else {
		return errorId < ERRORDIAG_ID_NUM_BSW;
	}
}


#if (ED_CLEARABLE_NUM > 0)
static boolean ED_IsErrorClearable(uint16 errorId) {
	uint16 i;

	if (errorId < ERRORDIAG_ID_NUM_BSW) {
		for (i = 0; i < ED_CLEARABLE_NUM; i++) {
			if (errorId == ED_ClearableCfg[i]) {
				return TRUE;
			}
		}
	}

	return FALSE;
}
#endif


Std_ReturnType ErrorDiag_LoadFromNvm(uint16 *romData) {
#if (ED_CFG_LATEST_ERROR_RECORD == STD_ON)
	uint8 i;
	uint8 newErrNum;
	uint8 romErrNum;

	if (ResetCause_IsPorHappened() == TRUE) {
		// new errors before read from nvm
		newErrNum = ErrorDiag_LastWillNum - ErrorDiag_LastWillNumBak;
		romErrNum = EH_REPORT_ERRORID_NUM_MAX - newErrNum;

		for (i = 0; i < romErrNum; i++) {
			ED_ErrorIdStatus_au16[newErrNum + i] = romData[i];
		}
	} else {
		/* Do nothing */
	}

#endif
	return E_OK;
}



/**
 * Backup LastWillNum from last cycle.
 * Call BEFORE report ANY error.
 */
void ErrorDiag_PreInit(void) {
#if (ED_CFG_LATEST_ERROR_RECORD == STD_ON)
	ErrorDiag_LastWillNumBak = ErrorDiag_LastWillNum;
#endif
}


/*****************************************************************************
** Service Name       : ErrorDiag_Init                                               
** 
**  Description      :  Initial variable of ErrorDiag_Status
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
void ErrorDiag_Init(void)
{
	ErrorDiag_checkLastWill();
}


/*****************************************************************************
** Service Name       : ErrorDiag_Task                                               
** 
**  Description      :  10ms period task to execute the main function of diagnostic task
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
void ErrorDiag_MainFunction(void)
{	
	ErrorDiag_MCU_Runtime_Diag_Task();
	ErrorDiag_DriveCtrl_Monitor_Task();
}


/*****************************************************************************
** Service Name       : ErrorDiag_Get_Config_CountUp                                               
** 
**  Description      :  Get congigured CountUp, when countup equal to max limit, 
                        the error shall be report
**                                                                               
**  Parameters (in)  :  ErrorId                         
**                                                                           
**  Parameters (in)  :  None                           
**    
**  Parameters (out) :  None                                                   
**                                                                            
**  Return value     :  CountUp                                                    
**                                                                            
******************************************************************************/

uint8 ErrorDiag_Get_Config_CountUp(uint16 ErrorId)
{
	uint8 RetVal = ED_INVALID_COUNT;

	if (ED_IsErrorIdValid(ErrorId))
	{
		RetVal = ED_GetErrorCfg(ErrorId)->ED_CountUp;
	}
	else
	{
		/* Do nothing */
	}

	return RetVal;
}


/*****************************************************************************
** Service Name       : ErrorDiag_Get_Config_CountDown                                               
** 
**  Description      :  Get congigured CountDown, 
                        when CountDown equal to max limit, the error shall be fixed
**                                                                               
**  Parameters (in)  :  ErrorId                         
**                                                                           
**  Parameters (in)  :  None                           
**    
**  Parameters (out) :  None                                                   
**                                                                            
**  Return value     :  CountDown                                                    
**                                                                            
******************************************************************************/
uint8 ErrorDiag_Get_Config_CountDown(uint16 ErrorId)
{
	uint8 RetVal = ED_INVALID_COUNT;

	if (ED_IsErrorIdValid(ErrorId))
	{
		RetVal = ED_GetErrorCfg(ErrorId)->ED_CountDown;
	}
	else
	{
		/* Do nothing */
	}

	return RetVal;
}


uint8 ErrorDiag_Get_Config_MaxRecoverTimes(uint16 ErrorId)
{
	uint8 RetVal = ED_INVALID_COUNT;

	if (ED_IsErrorIdValid(ErrorId))
	{
		RetVal = ED_GetErrorCfg(ErrorId)->ED_MaxRecovery;
	}
	else
	{
		/* Do nothing */
	}

	return RetVal;
}


/* Annotate ErrorDiag_IsSuppressed has no side effects */
#pragma PRQA_NO_SIDE_EFFECTS ErrorDiag_IsSuppressed
boolean ErrorDiag_IsSuppressed(uint16 ErrorId)
{
	uint8 i;
	uint16 suppressingId;
	uint8 len;
	boolean result = FALSE;
	const ErrorDiag_ConfigStatus_params_t *config;

	if ((ED_SUPPRESS_NUM_BSW > 0u || ErrorDiag_Asw_AswSupNum > 0u) && ED_IsErrorIdValid(ErrorId))
	{
		config = ED_GetErrorCfg(ErrorId);
		len = config->ED_SuppressionLen;
		for (i = 0u; i < len; i++)
		{
			suppressingId = ED_GetSuppressionCfg(config->ED_SuppressionIdx, ErrorId, i);
			if (ED_IsErrorIdValid(suppressingId)) {
				if (ED_GetErrorStatus(suppressingId)->ED_Status == ED_Status_NOK)
				{
					result = TRUE;
					break;
				} else {
					/* Do nothing */
				}
			} else {
				/* Do nothing */
			}
		}
	}
	else
	{
		/* Do nothing */
	}

	return result;
}

/*****************************************************************************
** Service Name       : ErrorDiag_Send_ErrorStatus                                               
** 
**  Description      :  External interface. It is used to set/clear error status of its errorid
**                                                                               
**  Parameters (in)  :  ErrorId                         
**                                                                           
**  Parameters (in)  :  ReportStatus : 0=ED_Status_OK ,  1= ED_Status_NOK                          
**    
**  Parameters (out) :  None                                                   
**                                                                            
**  Return value     :  None                                                    
**                                                                            
******************************************************************************/
void ErrorDiag_Send_ErrorStatus(uint16 ErrorId, boolean ReportStatus)
{
	uint8 cfgCountUp = 0u;
	uint8 cfgCountDown = 0u;
	uint8 cfgRecoverMax = 0u;
	uint8 cntOccurred_LO = 0u;
	uint8 currentStatus = EH_INVALID_VALUE;
	uint8 currentCount = 0;
	ErrorDiag_Status_params_t *diagErrStatus;

	if (ED_IsErrorIdValid(ErrorId))
	{
		diagErrStatus = ED_GetErrorStatus(ErrorId);

		if (FALSE == ErrorDiag_IsSuppressed(ErrorId))
		{
			currentStatus = diagErrStatus->ED_Status;
			cntOccurred_LO = diagErrStatus->ED_cntOccurred;
			currentCount = diagErrStatus->ED_ErrCount;

			cfgCountUp = ErrorDiag_Get_Config_CountUp(ErrorId);
			cfgCountDown = ErrorDiag_Get_Config_CountDown(ErrorId);
			cfgRecoverMax = ErrorDiag_Get_Config_MaxRecoverTimes(ErrorId);
		}
		else
		{
			/* ErrorId is suppressed. Do not update error status */
			currentStatus = EH_INVALID_VALUE;
		}

		if (currentStatus == ED_Status_OK)
		{
			if (ReportStatus == ED_Status_OK)
			{
				currentCount = 0;
			}
			else if (ReportStatus == ED_Status_NOK)
			{
				currentCount++;
				if (currentCount == cfgCountUp)
				{
#if (ED_CFG_LATEST_ERROR_RECORD == STD_ON)
					ED_Update_ReportId_Variable(ErrorId);
#endif
					currentCount = 0; /* ready for recover count down */
					currentStatus = ED_Status_NOK;
					cntOccurred_LO++;
				}
			}
			else
			{
				/* Do nothing */
			}
		}
		else if (currentStatus == ED_Status_NOK)
		{
			if (ReportStatus == ED_Status_NOK)
			{
				currentCount = 0;
			} else if (ReportStatus == ED_Status_OK && (cfgRecoverMax == 0xFF || (cfgRecoverMax > 0 && cntOccurred_LO <= cfgRecoverMax)))
			{
				currentCount++;
				if (currentCount == cfgCountDown)
				{
					currentCount = 0;
					currentStatus = ED_Status_OK;					
				}
			}
			else
			{
				/* Do nothing */
			}
		}
		else
		{
			/* Do nothing */
		}

		diagErrStatus->ED_Status = currentStatus;
		diagErrStatus->ED_ErrCount = currentCount;
		diagErrStatus->ED_cntOccurred = cntOccurred_LO;
	}
	else
	{
		/*  NA */
	}
}


/*****************************************************************************
** Service Name       : ErrorDiag_Send_ErrorStatus                                               
** 
**  Description      :  External interface. It is used to set/clear error status of its errorid
**                                                                               
**  Parameters (in)  :  ErrorId                         
**                                                                           
**  Parameters (in)  :  ReportStatus : 0=ED_Status_OK ,  1= ED_Status_NOK                          
**    
**  Parameters (out) :  None                                                   
**                                                                            
**  Return value     :  None                                                    
**                                                                            
******************************************************************************/
boolean ErrorDiag_Receive_ErrorStatus(uint16 ErrorId)
{
	boolean ED_Status;

	if (ED_IsErrorIdValid(ErrorId))
	{
		/*ED_GetErrorStatus(ErrorId)->ED_Status = ED_Status_NOK;*/	/*FIXME*/
		ED_Status = (uint8)ED_GetErrorStatus(ErrorId)->ED_Status;
	}
	else
	{
		ED_Status = ED_Status_OK;
	}
	return ED_Status;
}


#if (ED_CLEARABLE_NUM > 0)
Std_ReturnType ErrorDiag_ClearErrorStatus(uint16 ErrorId)
{
	Std_ReturnType ret = E_NOT_OK;
	ErrorDiag_Status_params_t *diagErrStatus;

	if (ED_IsErrorClearable(ErrorId)) {
		diagErrStatus = ED_GetErrorStatus(ErrorId);
		diagErrStatus->ED_cntOccurred = 0;
		diagErrStatus->ED_ErrCount = 0xFF;
		diagErrStatus->ED_Status = ED_Status_OK;

		ret = E_OK;
	}

	return ret;
}
#endif


void SetEventErrDiag_EVPT(uint16 EventId, uint16 ErrorId)
{
	boolean isFault = 0;

	isFault = ErrorDiag_Receive_ErrorStatus(ErrorId);

	Dem_SetEventStatus(EventId, isFault ? DEM_EVENT_STATUS_FAILED : DEM_EVENT_STATUS_PASSED);
}

void DetectErrDiag_Task(void)
{
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160001, ERRORID_HE99MD_OV);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160002, ERRORID_HE99MD_UV);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160003, ERRORID_HE99MD_EXT_HB1_OC);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160004, ERRORID_HE99MD_EXT_HB1_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160005, ERRORID_HE99MD_EXT_HB2_OC);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160006, ERRORID_HE99MD_EXT_HB2_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160007, ERRORID_HE99MD_EXT_HB3_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160008, ERRORID_HE99MD_EXT_HB3_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160009, ERRORID_HE99MD_EXT_HB4_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16000A, ERRORID_HE99MD_EXT_HB4_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16000B, ERRORID_HE99MD_EXT_HB5_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16000C, ERRORID_HE99MD_EXT_HB5_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16000D, ERRORID_HE99MD_EXT_HB6_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16000E, ERRORID_HE99MD_EXT_HB6_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16000F, ERRORID_HE99MD_EXT_HB7_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160010, ERRORID_HE99MD_EXT_HB7_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160011, ERRORID_HE99MD_EXT_HB8_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160012, ERRORID_HE99MD_EXT_HB8_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160013, ERRORID_HELS121D_EXT_D_LS1_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160014, ERRORID_HELS121D_EXT_D_LS1_STB);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160015, ERRORID_HELS121D_EXT_D_LS1_STG);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160016, ERRORID_HELS121D_EXT_D_LS2_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160017, ERRORID_HELS121D_EXT_D_LS2_STB);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160018, ERRORID_HELS121D_EXT_D_LS2_STG);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160019, ERRORID_HELS121D_EXT_D_LS3_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16001A, ERRORID_HELS121D_EXT_D_LS3_STB);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16001B, ERRORID_HELS121D_EXT_D_LS3_STG);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16001C, ERRORID_HELS121D_EXT_D_LS4_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16001D, ERRORID_HELS121D_EXT_D_LS4_STB);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16001E, ERRORID_HELS121D_EXT_D_LS4_STG);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16001F, ERRORID_WSD7020AF_HS1_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160020, ERRORID_WSD7020AF_HS1_STB);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160021, ERRORID_WSD7020AF_HS1_STG);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160022, ERRORID_WSD7020AF_HS2_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160023, ERRORID_WSD7020AF_HS2_STB);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160024, ERRORID_WSD7020AF_HS2_STG);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160025, ERRORID_WSD7020AF_HS3_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160026, ERRORID_WSD7020AF_HS3_STB);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160027, ERRORID_WSD7020AF_HS3_STG);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160028, ERRORID_WSD7020AF_HS4_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160029, ERRORID_WSD7020AF_HS4_STB);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16002A, ERRORID_WSD7020AF_HS4_STG);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16002B, ERRORID_WSD7020AF_HS5_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16002C, ERRORID_WSD7020AF_HS5_STB);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16002D, ERRORID_WSD7020AF_HS5_STG);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16002E, ERRORID_WSD7020AF_HS6_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16002F, ERRORID_WSD7020AF_HS6_STB);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160030, ERRORID_WSD7020AF_HS6_STG);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160031, ERRORID_WSD7020AF_HS7_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160032, ERRORID_WSD7020AF_HS7_STB);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160033, ERRORID_WSD7020AF_HS7_STG);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160034, ERRORID_WSD7020AF_HS8_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160035, ERRORID_WSD7020AF_HS8_STB);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160036, ERRORID_WSD7020AF_HS8_STG);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160037, ERRORID_WSD7020AF_HS9_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160038, ERRORID_WSD7020AF_HS9_STB);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160039, ERRORID_WSD7020AF_HS9_STG);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16003A, ERRORID_WSD7020AF_HS10_OPL);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16003B, ERRORID_WSD7020AF_HS10_STB);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16003C, ERRORID_WSD7020AF_HS10_STG);

	/*
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16003D, ERRORID_DIAG_TEST_ONLY);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16003E, ERRORID_DIAG_TEST_ONLY);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16003F, ERRORID_DIAG_TEST_ONLY);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160040, ERRORID_DIAG_TEST_ONLY);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160041, ERRORID_DIAG_TEST_ONLY);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160042, ERRORID_DIAG_TEST_ONLY);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160043, ERRORID_DIAG_TEST_ONLY);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160044, ERRORID_DIAG_TEST_ONLY);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160045, ERRORID_DIAG_TEST_ONLY);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160046, ERRORID_DIAG_TEST_ONLY);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160047, ERRORID_DIAG_TEST_ONLY);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160048, ERRORID_DIAG_TEST_ONLY);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_160049, ERRORID_DIAG_TEST_ONLY);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16004A, ERRORID_DIAG_TEST_ONLY);
	SetEventErrDiag_EVPT(DEM_Parameters_BSW_16004B, ERRORID_DIAG_TEST_ONLY);
	*/
}


/*****************************************************************************
** Service Name       : EH_Update_ReportId_Variable                                               
** 
**  Description      :  update EH_ReportErrorId_au16[] to store the lastest 20 errorid
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
#if (ED_CFG_LATEST_ERROR_RECORD == STD_ON)
void ED_Update_ReportId_Variable(uint16 ErrorId)
{
	uint8 i;

	if (ED_ErrorIdStatus_au16[0] != ErrorId)
	{
		ErrorDiag_LastWillNum = (ErrorDiag_LastWillNum == EH_REPORT_ERRORID_NUM_MAX) ? EH_REPORT_ERRORID_NUM_MAX : (ErrorDiag_LastWillNum + 1u);
		for (i = (EH_REPORT_ERRORID_NUM_MAX - 1u); i > 0u; i--)
		{
			ED_ErrorIdStatus_au16[i] = ED_ErrorIdStatus_au16[i - 1u];
		}
		ED_ErrorIdStatus_au16[0] = ErrorId;
	}
	else
	{
		/* Same ErrorId as the latest one, ignore */
	}
}
#endif


static void ErrorDiag_checkLastWill(void) {
#if (ED_CFG_LATEST_ERROR_RECORD == STD_ON)
	uint16 lastWIllId;
	uint8 i = 0;
	uint8 lastWillOffset = ErrorDiag_LastWillNum - ErrorDiag_LastWillNumBak;

	for (i = lastWillOffset; i < ErrorDiag_LastWillNumBak; i++) {
		lastWIllId = ED_ErrorIdStatus_au16[i];
		if (ED_IsErrorIdValid(lastWIllId)) {
			ED_GetErrorStatus(lastWIllId)->ED_LastWill = ED_LASTWILL_STATE_ISSUED;
		}
	}
#endif
}


uint8 ErrorDiag_GetLastWill(uint16 ErrorId) {
#if (ED_CFG_LATEST_ERROR_RECORD == STD_ON)
	if (ED_IsErrorIdValid(ErrorId)) {
		return ED_GetErrorStatus(ErrorId)->ED_LastWill;
	} else {
		return 0;
	}
#else
	return 0;
#endif
}


void ErrorDiag_FinishLastWill(uint16 ErrorId) {
#if (ED_CFG_LATEST_ERROR_RECORD == STD_ON)
	if (ED_IsErrorIdValid(ErrorId)) {
		ED_GetErrorStatus(ErrorId)->ED_LastWill = ED_LASTWILL_STATE_REPORTED;
	}
#endif
}


void ErrorDiag_ClearLastWill(uint16 ErrorId) {
#if (ED_CFG_LATEST_ERROR_RECORD == STD_ON)
	if (ED_IsErrorIdValid(ErrorId)) {
		ED_GetErrorStatus(ErrorId)->ED_LastWill = ED_LASTWILL_STATE_NONE;
	}
#endif
}


uint16 ErrorDiag_GetBswNum(void) {
	return ERRORDIAG_ID_NUM_BSW;
}


uint16 ErrorDiag_GetAswNum(void) {
	return ErrorDiag_Id_Num_Asw;
}


#define ERRORDIAG_STOP_SEC_CODE_ASIL_C
#include "ErrorDiag_MemMap.h"
