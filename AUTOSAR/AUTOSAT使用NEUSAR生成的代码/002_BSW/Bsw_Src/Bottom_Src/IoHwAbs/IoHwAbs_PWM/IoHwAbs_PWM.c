/*** create info ***********************
*@ Author : duqian 
*@ date :2025-12-02
*@ Description :PWM The functional interface of the abstraction layer PWM
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : duqian 
*@ date :2025-12-02
*@ Modification Description :
鍒濆鐗堟湰
****************************************/

/*******************************************************************************
 * Includes
 *******************************************************************************/

#include "IoHwAbs_PWM_Cfg.h"
#include "CCFC3012PT.h"

/*******************************************************************************
 * Global variables
 *******************************************************************************/


void IoHwAbs_Pwm_Init(void)
{
	Pwm_Init(&Pwm_Config);
}
/**
 * 函数名称: Pwm_CheckInputChannel
 * 参数In: Channel - 输入通道 :IoHwAbs_PWM_MCU_PWMOUT_CON1~IoHwAbs_PWM_MCU_Vref_VDC
 * 参数Out: none
 * 返回值: numIndex_LO - 通道索引
 * 描述: 根据输入通道查找对应的配置索引
 */
uint16 Pwm_CheckInputChannel(uint16 Channel)
{
    uint16 numIdx_i;
	uint16 numIndex_LO;

	numIndex_LO = IoHwAbs_PWM_Invalid_Value;
	for(numIdx_i=0; numIdx_i< IOHWABS_PWM_PwmOutChannMax; numIdx_i++)
	{
        if( Channel ==  Pwm_valChannelConfig_STR[numIdx_i].numPwmChannel)
        {
              numIndex_LO = numIdx_i;
			  break;
        }
	}
    return numIndex_LO;
}


typedef struct
{
    uint8  fgUpdate;
    uint32 valFreq;
    uint32 valDuty;
}Pwm_Infor_TDSTR;

Pwm_Infor_TDSTR Pwm_valInfor_STR[IOHWABS_PWM_PwmOutChannMax] = {0};

/**
 * 函数名称: Pwm_SetFreqAndDuty
 * 参数In: numChannel_LO - 通道编号 ：IoHwAbs_PWM_MCU_PWMOUT_CON1~IoHwAbs_PWM_MCU_Vref_VDC
 * 参数In: numFrequency_LO - 频率 ： 50~5000Hz
 * 参数In: numDutyCycle_LO - 占空比 ： 0~100
 * 参数Out: none
 * 返回值: Std_ReturnType 是否成功：E_OK/E_NOT_OK
 * 描述: 设置PWM频率和占空比
 */
Std_ReturnType Pwm_SetFreqAndDuty(uint16 numChannel_LO,uint32 numFrequency_LO,uint32 numDutyCycle_LO)
{
	if(numChannel_LO > IOHWABS_PWM_PwmOutChannMax)
	{
		return E_NOT_OK;
	}
	Pwm_valInfor_STR[numChannel_LO].fgUpdate = TRUE;
	Pwm_valInfor_STR[numChannel_LO].valFreq = numFrequency_LO;
	Pwm_valInfor_STR[numChannel_LO].valDuty = numDutyCycle_LO;
    return E_OK;
}

/**
 * 函数名称: Pwm_SetFreqDutySync
 * 参数In: numChannel_LO - 通道编号 ：IoHwAbs_PWM_MCU_PWMOUT_CON1~IoHwAbs_PWM_MCU_Vref_VDC
 * 参数In: numFrequency_LO - 频率 ： 50~5000Hz
 * 参数In: numDutyCycle_LO - 占空比 ： 0~100
 * 参数Out: none
 * 返回值: Std_ReturnType 是否成功：E_OK/E_NOT_OK
 * 描述: 设置PWM频率和占空比同步
 */
Std_ReturnType Pwm_SetFreqDutySync(uint16 numChannel_LO,uint32 numFrequency_LO,uint32 numDutyCycle_LO)
{
	uint16 numCfgIndex_LO  = IoHwAbs_PWM_Invalid_Value;
	Std_ReturnType RetVal_LO = E_OK;
	Pwm_ComponentType_TDEM  PwmType_LO;
	Pwm_GtmOutputType_TDEM	GtmType_LO;
    numCfgIndex_LO  = Pwm_CheckInputChannel(numChannel_LO);
    if(( numCfgIndex_LO  == IoHwAbs_PWM_Invalid_Value)||(numFrequency_LO == 0))
    {
         RetVal_LO = E_NOT_OK;
    }
	else
	{
	    PwmType_LO  =  Pwm_valChannelConfig_STR[numCfgIndex_LO ].numPwmType;
		if( IoHwAbs_eMIOS_PWM == PwmType_LO )
		{

			Pwm_SetPeriodAndDuty(Pwm_valChannelConfig_STR[numCfgIndex_LO ].numPwmChannelCfgId,IOHWABS_PWM_EMIOS_TIMEBASE/numFrequency_LO, numDutyCycle_LO * EMIOS_DUTY_SCALE_FACTOR);
		}
		else if( IoHwAbs_GTM_PWM == PwmType_LO )
		{
		    GtmType_LO  =  Pwm_valChannelConfig_STR[numCfgIndex_LO ].numGtmType;
			if(IoHwAbs_TOM_GTM == GtmType_LO)
			{
				Pwm_SetPeriodAndDuty(Pwm_valChannelConfig_STR[numCfgIndex_LO ].numPwmChannelCfgId, IOHWABS_PWM_GTM_TIMEBASE/numFrequency_LO, IOHWABS_PWM_MAXDUTY*((numDutyCycle_LO)*0.01));
			}
			else if(IoHwAbs_ATOM_GTM == GtmType_LO)
			{
				Pwm_SetPeriodAndDuty(Pwm_valChannelConfig_STR[numCfgIndex_LO ].numPwmChannelCfgId, IOHWABS_PWM_GTM_TIMEBASE/numFrequency_LO, IOHWABS_PWM_MAXDUTY*((numDutyCycle_LO)*0.01));
			}
		}
		else
		{
		   RetVal_LO = E_NOT_OK;
		}
	}
    return RetVal_LO;
}

/**
 * 函数名称: MotorDiag_PwmSetFreqDutySync
 * 参数In: numChannel_LO - 通道编号 ：IoHwAbs_PWM_MCU_VrefPhase_OCP_N~IoHwAbs_PWM_MCU_Vref_VDC
 * 参数In: numFrequency_LO - 频率 ： 50~5000Hz
 * 参数In: numDutyCycle_LO - 占空比 ： 0~1000
 * 参数Out: none
 * 返回值: Std_ReturnType 是否成功：E_OK/E_NOT_OK
 * 描述: 设置电机诊断PWM频率和占空比同步 千分制
 */
Std_ReturnType MotorDiag_PwmSetFreqDutySync(uint16 numChannel_LO,uint32 numFrequency_LO,uint32 numDutyCycle_LO)
{
	uint16 numCfgIndex_LO  = IoHwAbs_PWM_Invalid_Value;
	Std_ReturnType RetVal_LO = E_OK;
	Pwm_ComponentType_TDEM  PwmType_LO;
	Pwm_GtmOutputType_TDEM	GtmType_LO;
    numCfgIndex_LO  = Pwm_CheckInputChannel(numChannel_LO);
    if(( numCfgIndex_LO  == IoHwAbs_PWM_Invalid_Value)||(numFrequency_LO == 0))
    {
         RetVal_LO = E_NOT_OK;
    }
	else
	{
	    PwmType_LO  =  Pwm_valChannelConfig_STR[numCfgIndex_LO ].numPwmType;
		if( IoHwAbs_eMIOS_PWM == PwmType_LO )
		{
			
			Pwm_SetPeriodAndDuty(Pwm_valChannelConfig_STR[numCfgIndex_LO ].numPwmChannelCfgId,IOHWABS_PWM_EMIOS_TIMEBASE/numFrequency_LO, numDutyCycle_LO * EMIOS_DUTY_SCALE_FACTOR);
		}
		else if( IoHwAbs_GTM_PWM == PwmType_LO )
		{
		    GtmType_LO  =  Pwm_valChannelConfig_STR[numCfgIndex_LO ].numGtmType;
			if(IoHwAbs_TOM_GTM == GtmType_LO)
			{
				Pwm_SetPeriodAndDuty(Pwm_valChannelConfig_STR[numCfgIndex_LO ].numPwmChannelCfgId, IOHWABS_PWM_GTM_TIMEBASE/numFrequency_LO, IOHWABS_PWM_MAXDUTY*((numDutyCycle_LO)*0.001));
			}
			else if(IoHwAbs_ATOM_GTM == GtmType_LO)
			{
				Pwm_SetPeriodAndDuty(Pwm_valChannelConfig_STR[numCfgIndex_LO ].numPwmChannelCfgId, IOHWABS_PWM_GTM_TIMEBASE/numFrequency_LO, IOHWABS_PWM_MAXDUTY*((numDutyCycle_LO)*0.001));
			}
		}
		else
		{
		   RetVal_LO = E_NOT_OK;
		}
	}
    return RetVal_LO;
}

void IoHwAbs_Pwm_Mainfunction(void)
{

	for(uint16 Pwm_numChIdx_lo  = 0; Pwm_numChIdx_lo < IOHWABS_PWM_PwmOutChannMax; Pwm_numChIdx_lo++)
	{
		if(Pwm_numChIdx_lo >= IoHwAbs_PWM_MCU_PWMOUT_CON1 && Pwm_numChIdx_lo <= IoHwAbs_PWM_MCU_PWMOUT_CON10)
		{
			if(Pwm_valInfor_STR[Pwm_numChIdx_lo].fgUpdate == TRUE)
			{
				Pwm_SetFreqDutySync(Pwm_valChannelConfig_STR[Pwm_numChIdx_lo].numPwmChannel, Pwm_valInfor_STR[Pwm_numChIdx_lo].valFreq, Pwm_valInfor_STR[Pwm_numChIdx_lo].valDuty);
				Pwm_valInfor_STR[Pwm_numChIdx_lo].fgUpdate = FALSE;
			}
		}
		else if(Pwm_numChIdx_lo >= IoHwAbs_PWM_MCU_VrefPhase_OCP_N && Pwm_numChIdx_lo <= IoHwAbs_PWM_MCU_Vref_VDC)
		{
			if(Pwm_valInfor_STR[Pwm_numChIdx_lo].fgUpdate == TRUE)
			{
				MotorDiag_PwmSetFreqDutySync(Pwm_valChannelConfig_STR[Pwm_numChIdx_lo].numPwmChannel, Pwm_valInfor_STR[Pwm_numChIdx_lo].valFreq, Pwm_valInfor_STR[Pwm_numChIdx_lo].valDuty);
				Pwm_valInfor_STR[Pwm_numChIdx_lo].fgUpdate = FALSE;
			}
		}
		else if(Pwm_numChIdx_lo >= IoHwAbs_PWM_MCU_PWMOUT_CON7 && Pwm_numChIdx_lo <= IoHwAbs_PWM_MCU_PWMOUT_CON11)
		{
			if(Pwm_valInfor_STR[Pwm_numChIdx_lo].fgUpdate == TRUE)
			{
				Pwm_SetFreqDutySync(Pwm_valChannelConfig_STR[Pwm_numChIdx_lo].numPwmChannel, Pwm_valInfor_STR[Pwm_numChIdx_lo].valFreq, Pwm_valInfor_STR[Pwm_numChIdx_lo].valDuty);
				Pwm_valInfor_STR[Pwm_numChIdx_lo].fgUpdate = FALSE;
			}
		}
		else
		{}
	}
}
