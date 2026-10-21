/*** create info *******************************************
*@ filename : IoHwAbs_DIO_prv.h 
*@ Author : pianyongxin 
*@ date :2025-02-12
*@ Description :DIO的接口声明
*** modify info ******************************************* 
*@ version :0.0
*@ Modifier : pianyongxin 
*@ date :2025-02-12
*@ Modification Description :
初始版本
************************************************************/

/********************************************** Include **********************************************/

#include "IoHwAbs_DIO_Prv.h"
#include "IoHwAbs_DIO_Cfg.h"
#include "Cdd_Lsd_HELS121D_prv.h"
#include "Dio_Types.h"
#include "Dio.h".

/******************************************* Global Varibles ******************************************/
/*HELS120D禁用输出标志*/
uint8 Dio_fgLs1DisOutput_Mp = FALSE;
uint8 Dio_fgLs2DisOutput_Mp = FALSE;
uint8 Dio_fgLs3DisOutput_Mp = FALSE;
uint8 Dio_fgLs4DisOutput_Mp = FALSE;

Dio_StInfo_TDSTR Dio_valSetChan_mp[IoHwAbs_DioChannelNum] = {0};
uint8 Dio_valDOUTCtr_mp[Dout_Channel_MaxNum] 		= {0};
uint8 Dio_stDOUTLastCtrl_mp[Dout_Channel_MaxNum] 	= {0};
/********************************************* Function *********************************************/
/**
 * 函数名称: IoHwAbs_DIO_Search_Input_Channel_Check
 * 参数in: 通道
 * 参数out: 
 * 返回值: index通道
 * 描述: 检查通道是否未配置内正确的通道
 */
uint16 IoHwAbs_DIO_Search_Input_Channel_Check(uint16 Channel)
{
	uint16 Dio_indexCnt_i;
	uint16 Dio_valindex_LO;

	Dio_valindex_LO = IoHwAbs_DIO_Invalid_Value;
	for (Dio_indexCnt_i = 0; Dio_indexCnt_i < IoHwAbs_DioChannelNum; Dio_indexCnt_i++)
	{
		if (Channel == Dio_IdxConfig_STR[Dio_indexCnt_i].IoHwAbs_DIO_Index)
		{
			Dio_valindex_LO = Dio_indexCnt_i;
			break;
		}
	}
	return Dio_valindex_LO;
}

/**
 * 函数名称: IoHwAbs_DIO_SetChannelValue
 * 参数in: 通道
 * 参数out: 0：不输出 1：输出
 * 返回值: Dio_retVal_LO：执行成功与否
 * 描述: 设置DIO通道输出与否
 */
Std_ReturnType IoHwAbs_DIO_SetChannelValue(uint16 channel, boolean writeLevel)
{
	Std_ReturnType Dio_retVal_LO;
	uint16 Dio_valInitIndex_LO;
	uint16 Dio_valCfgIndex_LO;
	Dio_Type_TDEM Dio_Type_EM;

	Dio_valCfgIndex_LO = IoHwAbs_DIO_Search_Input_Channel_Check(channel);
	if (Dio_valCfgIndex_LO == IoHwAbs_DIO_Invalid_Value)
	{
		Dio_retVal_LO = E_NOT_OK;
	}
	else
	{
		Dio_Type_EM = Dio_IdxConfig_STR[Dio_valCfgIndex_LO].IoHwAbs_IO_Type_EM;
		if (Dio_Type_EM == IoHwAbs_Dio_Output || Dio_Type_EM == IoHwAbs_Dio_InOut)
		{
			switch(Dio_IdxConfig_STR[Dio_valCfgIndex_LO].IoHwAbs_DIO_Index)
        	 {
        	 case IOHWABS_DIOCHANNEL_MCU_D_LS_1:
        		 writeLevel &= (!Dio_fgLs1DisOutput_Mp);
        		 HELS121D_stDriveOut_Mp[0] = writeLevel;
        		 break;
        	 case IOHWABS_DIOCHANNEL_MCU_D_LS_2:
        		 writeLevel &= (!Dio_fgLs2DisOutput_Mp);
        		 HELS121D_stDriveOut_Mp[1] = writeLevel;
        		 break;
			case IOHWABS_DIOCHANNEL_MCU_D_LS_3:
        		 writeLevel &= (!Dio_fgLs3DisOutput_Mp);
        		 HELS121D_stDriveOut_Mp[2] = writeLevel;
        		 break;
			case IOHWABS_DIOCHANNEL_MCU_D_LS_4:
        		 writeLevel &= (!Dio_fgLs4DisOutput_Mp);
        		 HELS121D_stDriveOut_Mp[3] = writeLevel;
        		 break;
        	 default:
        		 break;
        	 }
			Dio_valInitIndex_LO = Dio_IdxConfig_STR[Dio_valCfgIndex_LO].Initial_DIO_Index;
			Dio_WriteChannel(Dio_valInitIndex_LO, (Dio_LevelType)writeLevel);
			Dio_retVal_LO = E_OK;
		}
		else
		{
			Dio_retVal_LO = E_NOT_OK;
		}
	}
	return Dio_retVal_LO;
}

/**
 * 函数名称: IoHwAbs_DIO_GetChannelValue
 * 参数in: 通道
 * 参数out: 0：不输出 1：输出
 * 返回值: Dio_retVal_LO：执行成功与否
 * 描述: 获取通道输出状态
 */
Std_ReturnType IoHwAbs_DIO_GetChannelValue(uint16 channel, boolean *readLevel)
{
	Std_ReturnType Dio_retVal_LO;
	uint16 Dio_valInitIndex_LO;
	uint16 Dio_valCfgIndex_LO;
	Dio_Type_TDEM Dio_Type_EM;
	uint8 Dio_valChannelIdLecel_LO = (Dio_LevelType)DIO_LEVEL_LOW;
	uint8 Dio_valu8ChannelIdOldLevel_LO = (Dio_LevelType)DIO_LEVEL_LOW;
	uint8 Dio_Num_i = 0;
	if (readLevel == 0)
	{
		Dio_retVal_LO = E_NOT_OK;
	}

	if (channel >= IOHWABS_DIOCHANNEL_PwmIn_CH1 && channel <= IOHWABS_DIOCHANNEL_ICU_PWM_OUT_FB10_PVF)
    {

		*readLevel = Dio_valSetChan_mp[channel].DIO_ChnLevel;
		return E_OK;
    }

	if(channel >= IOHWABS_DIOCHANNEL_PwmIn_CH8 && channel <= IOHWABS_DIOCHANNEL_ICU_PWM_OUT_FB11_PVF)
	{
		*readLevel = Dio_valSetChan_mp[channel].DIO_ChnLevel;
		return E_OK;
	}


	Dio_valCfgIndex_LO = IoHwAbs_DIO_Search_Input_Channel_Check(channel);
	if (Dio_valCfgIndex_LO == IoHwAbs_DIO_Invalid_Value)
	{
		Dio_retVal_LO = E_NOT_OK;
	}
	else
	{
		Dio_Type_EM = Dio_IdxConfig_STR[Dio_valCfgIndex_LO].IoHwAbs_IO_Type_EM;
		if ((Dio_Type_EM == IoHwAbs_Dio_Input) || (Dio_Type_EM == IoHwAbs_Dio_InOut))
		{
			Dio_valInitIndex_LO = Dio_IdxConfig_STR[Dio_valCfgIndex_LO].Initial_DIO_Index;
#if (STD_ON == DIO_READ_FILTER)
			for (Dio_Num_i = 0; Dio_Num_i < DIO_H_SW_FILTER_NUM; Dio_Num_i++)
			{
				if (Dio_Num_i == 0)
				{
					Dio_valu8ChannelIdOldLevel_LO = Dio_ReadChannel(Dio_valInitIndex_LO);
				}
				else
				{
					Dio_valChannelIdLecel_LO = Dio_ReadChannel(Dio_valInitIndex_LO);
				}
			}
			if (Dio_valu8ChannelIdOldLevel_LO == Dio_valChannelIdLecel_LO)
			{
				*val = Dio_valChannelIdLecel_LO;
				Dio_retVal_LO = E_OK;
			}
			else
			{
				*val = DIO_INVALID_LEVEL;
				Dio_retVal_LO = E_NOT_OK;
			}
#else
			*readLevel = Dio_valSetChan_mp[channel].DIO_ChnLevel;
			Dio_retVal_LO = E_OK;
#endif
		}
		else
		{
			Dio_retVal_LO = E_NOT_OK;
		}
	}
	return Dio_retVal_LO;
}




/**
 * 函数名称: IoHwAbs_DIO_GetPwmChannelValue
 * 参数in: channel - PWM通道号
 * 参数out: readLevel - 读取的电平值
 * 返回值: 执行成功与否
 * 描述: 获取PWM通道的输入电平值（读取GTM寄存器）
 */
Std_ReturnType IoHwAbs_DIO_GetPwmChannelValue(uint16 channel, boolean *readLevel)
{
    uint8 Dio_PwmChannelVal_i;
    
    for (Dio_PwmChannelVal_i = 0; Dio_PwmChannelVal_i < IOHWABS_DIO_GTM_CHANNEL_MAP_SIZE; Dio_PwmChannelVal_i++)
    {
        if (Dio_GtmChannelMap_STR[Dio_PwmChannelVal_i].channel == channel)
        {

            uint8 regValue = GTM4.GLS[Dio_GtmChannelMap_STR[Dio_PwmChannelVal_i].timIndex].TIM.INP_VAL.B.F_OUT;
            uint8 bitMask = (uint8)(1U << Dio_GtmChannelMap_STR[Dio_PwmChannelVal_i].channelIndex);
            
            if ((regValue & bitMask) != 0)
            {
                *readLevel = DIO_LEVEL_HIGH;
            }
            else
            {
                *readLevel = DIO_LEVEL_LOW;
            }
            return E_OK;
        }
    }
    
    return E_NOT_OK;
}


void IoHwAbs_DIO_MainFunction(void)
{
	volatile uint8 Dio_valChanCnt_lo = 0;
	volatile uint8 Dio_Type_lo = 0;
	volatile uint8 Dio_valChannelIdLecel_LO = 0;
	for(Dio_valChanCnt_lo = 0; Dio_valChanCnt_lo < IoHwAbs_DioChannelNum; Dio_valChanCnt_lo++)
	{
		Dio_valChannelIdLecel_LO = IoHwAbs_DIO_Search_Input_Channel_Check(Dio_valChanCnt_lo);
		if(Dio_valChannelIdLecel_LO != IoHwAbs_DIO_Invalid_Value)
		{
			Dio_Type_lo = Dio_IdxConfig_STR[Dio_valChannelIdLecel_LO].IoHwAbs_IO_Type_EM;
		}
		else
		{
			Dio_Type_lo = 0xFF;
		}
		
		if((Dio_valSetChan_mp[Dio_valChanCnt_lo].DIO_ActFlag == TRUE)&&((Dio_Type_lo == IoHwAbs_Dio_Output) || (Dio_Type_lo == IoHwAbs_Dio_InOut)))
		{
			// Dio_WriteChannel(Dio_IdxConfig_STR[Dio_valChanCnt_lo].Initial_DIO_Index, Dio_valSetChan_mp[Dio_valChanCnt_lo].DIO_ChnLevel);
		}
		else if((Dio_Type_lo == IoHwAbs_Dio_Input) || (Dio_Type_lo == IoHwAbs_Dio_InOut))
		{
			if(Dio_valChanCnt_lo == IOHWABS_DIOCHANNEL_MCU_79600_FAULT_IN)
			{
				Dio_valSetChan_mp[Dio_valChanCnt_lo].DIO_ChnLevel = Dio_ReadChannel(Dio_IdxConfig_STR[78].Initial_DIO_Index);
			}
			else if(Dio_valChanCnt_lo == IOHWABS_DIOCHANNEL_F_VPRE_PG)
			{
				Dio_valSetChan_mp[Dio_valChanCnt_lo].DIO_ChnLevel = Dio_ReadChannel(Dio_IdxConfig_STR[79].Initial_DIO_Index);
			}
			else if(Dio_valChanCnt_lo == IOHWABS_DIOCHANNEL_MCU_OCPorOV_RST)
			{
				Dio_valSetChan_mp[Dio_valChanCnt_lo].DIO_ChnLevel = Dio_ReadChannel(Dio_IdxConfig_STR[80].Initial_DIO_Index);
			}
			else
			{
				Dio_valSetChan_mp[Dio_valChanCnt_lo].DIO_ChnLevel = Dio_ReadChannel(Dio_IdxConfig_STR[Dio_valChanCnt_lo].Initial_DIO_Index);
			}

		}
		else
		{
			if (Dio_valChanCnt_lo >= IOHWABS_DIOCHANNEL_PwmIn_CH1 && Dio_valChanCnt_lo <= IOHWABS_DIOCHANNEL_ICU_PWM_OUT_FB10_PVF)
			{
				IoHwAbs_DIO_GetPwmChannelValue(Dio_valChanCnt_lo, &Dio_valSetChan_mp[Dio_valChanCnt_lo].DIO_ChnLevel);
			}

			if(Dio_valChanCnt_lo >= IOHWABS_DIOCHANNEL_PwmIn_CH8 && Dio_valChanCnt_lo <= IOHWABS_DIOCHANNEL_ICU_PWM_OUT_FB11_PVF)
			{
				IoHwAbs_DIO_GetPwmChannelValue(Dio_valChanCnt_lo, &Dio_valSetChan_mp[Dio_valChanCnt_lo].DIO_ChnLevel);
			}
			/* Do nothing */
		}

		for(uint8 Dout_Ch = 0; Dout_Ch < Dout_Channel_MaxNum; Dout_Ch++)
		{
			if(Dio_valDOUTCtr_mp[Dout_Ch] != Dio_stDOUTLastCtrl_mp[Dout_Ch])
			{
				IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_IGBT_ASC + Dout_Ch, Dio_valDOUTCtr_mp[Dout_Ch]);
				Dio_stDOUTLastCtrl_mp[Dout_Ch] = Dio_valDOUTCtr_mp[Dout_Ch];
			}
		}
	}

}

/**
 * 函数名称: Cdd_DOUT_SetLevelFunction
 * 参数in: ValChId - 通道号
 * 		  Ctr: 0：Disable 1：Enable
 * 返回值: 执行成功与否
 * 描述: 设置DOUT通道的输出电平值
 */
Std_ReturnType Cdd_DOUT_SetLevelFunction(uint16 ValChId, uint8 Ctr)
{
	Std_ReturnType RetVal_LO;
	
	if (ValChId == IoHwAbs_DIO_Invalid_Value)
	{
		RetVal_LO = E_NOT_OK;
	}
	else
	{
		Dio_valDOUTCtr_mp[ValChId] = Ctr;
		RetVal_LO = E_OK;
	}
	return RetVal_LO;
}