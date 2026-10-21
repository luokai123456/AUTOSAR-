/*** create info ***********************
*@ Author :
*@ date :2024-12-02
*@ Description :HELS121D drive and fault diagnosis functions 
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : liufengyuan
*@ date :2024-12-02
*@ Modification Description :
初始版本
****************************************/

/*******************************************************************************
 * Includes
 *******************************************************************************/
#include "Cdd_Lsd_HELS121D_prv.h"
// #include "ErrorDiag_Swc.h"
#include "typedefs.h"
#include "IoHwAbs_ADC.h"
// #include "IoHwAbs_PWM.h"
#include "ErrorDiag_Errorid.h"
#include  "ErrorDiag_Swc.h"
#include "IoHwAbs_DIO_prv.h"
#include "ErrorDiag_Cfg.h"
#include "Lsd_Control.h"
/*******************************************************************************
 * Global variables
 *******************************************************************************/
uint16 HELS121D_valVol_Mp[HELS121D_Io_numOutPutMax] = {0};
HELS121D_DiagThrCfg_STR HELS121D_Diagthreshold_Mp[HELS121D_Io_numOutPutMax] =
{
	{
		.valSG_Threshold = 2000,
		.valOL_LowThreshold = 2000,
		.valOL_HighThreshold = 5000,
		.valSB_Threshold = 9000
	},
	{
		.valSG_Threshold = 2000,
		.valOL_LowThreshold = 2000,
		.valOL_HighThreshold = 5000,
		.valSB_Threshold = 9000
	},
	{
		.valSG_Threshold = 2000,
		.valOL_LowThreshold = 2000,
		.valOL_HighThreshold = 5000,
		.valSB_Threshold = 9000
	},
	{
		.valSG_Threshold = 2000,
		.valOL_LowThreshold = 2000,
		.valOL_HighThreshold = 5000,
		.valSB_Threshold = 9000
	}
};

const Lsd_ErrorIdMap_Str HELS121D_ErrorIdMap_Mp[DD_LSD_DIO_CHANNEL_MAX] =
{
		{ERRORID_HELS121D_EXT_D_LS1_OPL, ERRORID_HELS121D_EXT_D_LS1_STB, ERRORID_HELS121D_EXT_D_LS1_STG},
		{ERRORID_HELS121D_EXT_D_LS2_OPL, ERRORID_HELS121D_EXT_D_LS2_STB, ERRORID_HELS121D_EXT_D_LS2_STG},
		{ERRORID_HELS121D_EXT_D_LS3_OPL, ERRORID_HELS121D_EXT_D_LS3_STB, ERRORID_HELS121D_EXT_D_LS3_STG},
		{ERRORID_HELS121D_EXT_D_LS4_OPL, ERRORID_HELS121D_EXT_D_LS4_STB, ERRORID_HELS121D_EXT_D_LS4_STG},
};
uint8 HELS121D_stDriveOut_Mp[HELS121D_Io_numOutPutMax] ={0};


/**
 * 函数名称: HELS121D_DiagThresholdCfg
 * 参数: HELS121D_valChannl_Lo , valThresholdCfg_Lo
 * 返回值: flgOK_LO
 * 描述: description
 */
Std_ReturnType HELS121D_DiagThresholdCfg(uint8 HELS121D_valChannl_Lo ,HELS121D_DiagThrCfg_STR *valThresholdCfg_Lo)
{
	Std_ReturnType flgOK_LO = E_OK;
	if((valThresholdCfg_Lo != NULL) && (HELS121D_valChannl_Lo < HELS121D_Io_numOutPutMax))
	{
		HELS121D_Diagthreshold_Mp[HELS121D_valChannl_Lo] = *valThresholdCfg_Lo;
		flgOK_LO = E_OK;
	}
	else
	{
		flgOK_LO = E_NOT_OK;
	}
	return flgOK_LO;
}



/**
 * 函数名称: ErrHdlr_HELS121D_ErrRecover
 * 参数: void
 * 返回值: void
 * 描述: description
 */
void ErrHdlr_HELS121D_ErrRecover(void)
{
#if 0
	if((ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS1_STG].ED_Status ==ED_Status_OK )
			&&(ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS1_OPL].ED_Status == ED_Status_OK)&&
			(ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS1_STB].ED_Status == ED_Status_OK))
	{
		Dio_fgLs1DisOutput_Mp = FALSE;
	}
	if((ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS2_STG].ED_Status ==ED_Status_OK )
			&&(ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS2_OPL].ED_Status == ED_Status_OK)&&
			(ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS2_STB].ED_Status == ED_Status_OK))
	{
		Dio_fgLs2DisOutput_Mp = FALSE;
	}
	if((ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS3_STG].ED_Status ==ED_Status_OK )
			&&(ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS3_OPL].ED_Status == ED_Status_OK)&&
			(ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS3_STB].ED_Status == ED_Status_OK))
	{
		Dio_fgLs3DisOutput_Mp = FALSE;
	}
	if((ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS4_STG].ED_Status ==ED_Status_OK )
			&&(ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS4_OPL].ED_Status == ED_Status_OK)&&
			(ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS4_STB].ED_Status == ED_Status_OK))
	{
		Dio_fgLs4DisOutput_Mp = FALSE;
	}
#endif
}


/**
 * 函数名称: ErrHdlr_HELS121D_ErrDetect
 * 参数: void
 * 返回值: void
 * 描述: description
 */
void ErrHdlr_HELS121D_ErrDetect(void)
{
#if 0
	if((ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS1_STG].ED_Status ==ED_Status_NOK )
			||(ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS1_OPL].ED_Status == ED_Status_NOK)||
			(ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS1_STB].ED_Status == ED_Status_NOK))
	{
		Dio_fgLs1DisOutput_Mp = TRUE;
	}
	if((ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS2_STG].ED_Status ==ED_Status_NOK )
			||(ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS2_OPL].ED_Status == ED_Status_NOK)||
			(ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS2_STB].ED_Status == ED_Status_NOK))
	{
		Dio_fgLs2DisOutput_Mp = TRUE;
	}
	if((ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS3_STG].ED_Status ==ED_Status_NOK )
			||(ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS3_OPL].ED_Status == ED_Status_NOK)||
			(ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS3_STB].ED_Status == ED_Status_NOK))
	{
		Dio_fgLs3DisOutput_Mp = TRUE;
	}
	if((ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS4_STG].ED_Status ==ED_Status_NOK )
			||(ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS4_OPL].ED_Status == ED_Status_NOK)||
			(ErrorDiag_ErrorStatus_BSW[ERRORID_HELS121D_EXT_D_LS4_STB].ED_Status == ED_Status_NOK))
	{
		Dio_fgLs4DisOutput_Mp = TRUE;
	}
#endif
}




/**
 * 函数名称: HELS121D_ErrAnalysis
 * 参数: args
 * 返回值: return
 * 描述: HELS121D Filtering to determine faults
 */
void HELS121D_ErrAnalysis(void)
{
	uint8 HELS121D_valChannelNum_Lo = 0;
	for(HELS121D_valChannelNum_Lo = 0;HELS121D_valChannelNum_Lo < HELS121D_Io_numOutPutMax;HELS121D_valChannelNum_Lo++)
	{
		/*OFF状态*/
		if(0 == Lsd_valDioCtrl_Mp[HELS121D_valChannelNum_Lo].ch_Level)
		{
			/*短地诊断*/
			if(HELS121D_valVol_Mp[HELS121D_valChannelNum_Lo] < HELS121D_Diagthreshold_Mp[HELS121D_valChannelNum_Lo].valSG_Threshold)
			{
				ErrorDiag_Send_ErrorStatus(HELS121D_ErrorIdMap_Mp[HELS121D_valChannelNum_Lo].STG_Errorid, ED_Status_NOK);
			}
			else
			{
				ErrorDiag_Send_ErrorStatus(HELS121D_ErrorIdMap_Mp[HELS121D_valChannelNum_Lo].STG_Errorid, ED_Status_OK);
			}

			/*开路诊断 */
			if((HELS121D_valVol_Mp[HELS121D_valChannelNum_Lo] >= HELS121D_Diagthreshold_Mp[HELS121D_valChannelNum_Lo].valOL_LowThreshold) &&
					(HELS121D_valVol_Mp[HELS121D_valChannelNum_Lo] <= HELS121D_Diagthreshold_Mp[HELS121D_valChannelNum_Lo].valOL_HighThreshold))
			{
				ErrorDiag_Send_ErrorStatus(HELS121D_ErrorIdMap_Mp[HELS121D_valChannelNum_Lo].OPL_Errorid, ED_Status_NOK);
			}
			else
			{
				ErrorDiag_Send_ErrorStatus(HELS121D_ErrorIdMap_Mp[HELS121D_valChannelNum_Lo].OPL_Errorid, ED_Status_OK);
			}
		}

		/*ON状态*/
		else
		{
			/*短电源诊断 */
			if (HELS121D_valVol_Mp[HELS121D_valChannelNum_Lo] > HELS121D_Diagthreshold_Mp[HELS121D_valChannelNum_Lo].valSB_Threshold)
			{
				ErrorDiag_Send_ErrorStatus(HELS121D_ErrorIdMap_Mp[HELS121D_valChannelNum_Lo].STB_Errorid, ED_Status_NOK);
			}
			else
			{
				ErrorDiag_Send_ErrorStatus(HELS121D_ErrorIdMap_Mp[HELS121D_valChannelNum_Lo].STB_Errorid, ED_Status_OK);
			}
		}
	}
}


/**
 * 函数名称: EH_HELS121D_Diag
 * 参数: void
 * 返回值: void
 * 描述: description
 */
void EH_HELS121D_Diag(void)
{
	uint16 HELS121D_valChannelRes_Lo = 0;
	IoHwAbs_ADC_GetChannelValue(IOHWABS_ADC_CHANNEL_MCU_LS_9_DIAG, &HELS121D_valChannelRes_Lo);
	HELS121D_valVol_Mp[HELS121D_Io_LsOutCh0_Ctrl] = HELS121D_valChannelRes_Lo;
	IoHwAbs_ADC_GetChannelValue(IOHWABS_ADC_CHANNEL_MCU_LS_10_DIAG, &HELS121D_valChannelRes_Lo);
	HELS121D_valVol_Mp[HELS121D_Io_LsOutCh1_Ctrl] = HELS121D_valChannelRes_Lo;
	IoHwAbs_ADC_GetChannelValue(IOHWABS_ADC_CHANNEL_MCU_LS_11_DIAG, &HELS121D_valChannelRes_Lo);
	HELS121D_valVol_Mp[HELS121D_Io_LsOutCh2_Ctrl] = HELS121D_valChannelRes_Lo;
	IoHwAbs_ADC_GetChannelValue(IOHWABS_ADC_CHANNEL_MCU_LS_12_DIAG, &HELS121D_valChannelRes_Lo);
	HELS121D_valVol_Mp[HELS121D_Io_LsOutCh3_Ctrl] = HELS121D_valChannelRes_Lo;
	HELS121D_ErrAnalysis();

}


