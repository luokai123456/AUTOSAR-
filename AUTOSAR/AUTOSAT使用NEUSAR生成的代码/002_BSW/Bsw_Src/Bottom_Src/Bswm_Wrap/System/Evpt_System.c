
/*** create info ***********************
*@ Author :yanxinlong 
*@ date :2025-12-04
*@ Description :Power manager functions
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : 
*@ date :2025-12-04
*@ Modification Description :
初始版本
****************************************/
#include "Evpt_System.h"
#include "Evpt_InterDataWatch_Prv.h"

uint32 Sys_tiWakeTime = 0;
boolean Sys_tiWakeTimeEn = false;
uint32 Sys_tiRemainWakeTime = 0;
uint8 Pm_FlgBootJump_Mp = 0;
#if(1)
extern void App_DevicePowerOff_Function(void);
static void Sys_GetSystemTimer_UsInit(void)
{
    static uint32 STM4_CPS_UsINIT = 0;

    if(STM4_CPS_UsINIT == 0)
    {
        Gpt_Stm_LLD_ModuleEnable(STM4);
        Gpt_Stm_LLD_SetPrescaler(STM4, 49);
        STM4_CPS_UsINIT = 1;
    }
}
static void Sys_GetSystemTimer_MsInit(void)
{
    static uint32 STM5_CPS_MsINIT = 0;

    if(STM5_CPS_MsINIT == 0)
    {
        Gpt_Stm_LLD_ModuleEnable(STM5);
        Gpt_Stm_LLD_SetPrescaler(STM5, 199);
        STM5_CPS_MsINIT = 1;
    }
}

uint32 Sys_GetSystemTimer_us(void)
{
    uint32 Current_UCounter_Lo = 0;
    uint32 Time_Us_Lo = 0;
    Sys_GetSystemTimer_UsInit();
    Current_UCounter_Lo = Gpt_Stm_LLD_GetCounter(STM4);
	
    return Current_UCounter_Lo;
}

uint32 Sys_GetSystemTimer_ms(void)
{
    uint32 Current_UCounter_Lo = 0;
    uint32 Time_Ms_Lo = 0;
    Sys_GetSystemTimer_MsInit();
    Current_UCounter_Lo = Gpt_Stm_LLD_GetCounter(STM5);
    Time_Ms_Lo = Current_UCounter_Lo / 250;

    return Time_Ms_Lo;
}
uint8 BswM_GetWakeSource(void)
{
	
	if(Cdd_Sbc_Sa47301_GetWakeSourceFunction().fgCanAWakeUpActive) {
		return 1;
	}else if(Cdd_Sbc_Sa47301_GetWakeSourceFunction().fgCanBWakeUpActive) {
        return 2;
    }else if(Cdd_Sbc_Sa47301_GetWakeSourceFunction().fgKeyWakeUpActive) {
		return 3;
	}else if(Cdd_Sbc_Sa47301_GetWakeSourceFunction().fgAPlus1WakeUpActive) {
		return 4;
	}else if(Cdd_Sbc_Sa47301_GetWakeSourceFunction().fgAPlus2WakeUpActive) {
        return 5;
	}else if(Cdd_Sbc_Sa47301_GetWakeSourceFunction().fgOBCWakeUpActive) {
        return 6;
	}else if(Cdd_Sbc_Sa47301_GetWakeSourceFunction().fgRTCWakeUpActive) {
        return 7;
	}else if(Cdd_Sbc_Sa47301_GetWakeSourceFunction().fgAFEWakeUpActive) {
        return 8;
    }else {
		return 0;
	}
}


/***
 *@ function name : BswM_RequestPwerOff
 *@ Description :请求关闭电源
 *@ param EnPowerOff : BSWM_POWER_STATE_OFF - 关闭电源
 *@ param EnPowerOff : BSWM_POWER_STATE_ON - 开启电源
 *@ return : Std_ReturnType - 函数执行状态
 *@ note :1个Tick = 10ns
***/

Std_ReturnType BswM_RequestPwerOff(uint8 EnPowerOff)
{
    uint8 RetVal = 0;
   if(EnPowerOff == BSWM_POWER_STATE_OFF)
   {
	   BswM_RequestMode(BSWM_GENERIC_RP_PowerState,BSWM_GENERICVALUE_STATE_POWER_OFF);
   }
   else if(EnPowerOff == BSWM_POWER_STATE_ON)
   {
	   BswM_RequestMode(BSWM_GENERIC_RP_PowerState,BSWM_GENERICVALUE_STATE_POWER_ON);
   }
   else
   {
       RetVal = E_NOT_OK;
   }
    Evpt_DiagDb_SetValue(DIAG_VAR_ASW_POWER_DOWN_FLAG, &EnPowerOff, sizeof(uint8));
   return RetVal;
}




/**
 * 函数名称: Sys_Sensor_CtrlOut_Function
 * 参数: SensorChanel   
 * 参数: valEn_Lo  0:Disable   1:Enable
 * 返回值: return
 * 描述: 此API用于控制Sensor输出
 */

volatile uint8 DevStatus = 1;

void  Sys_SensorCtrlInit_Function(void)
{
	uint8 SensorCh = 0;
	for(SensorCh = 2;SensorCh < 5;SensorCh++)
	{
		Sys_Sensor_CtrlOut_Function(SensorCh,DevStatus);
	}
}
Std_ReturnType Sys_Sensor_CtrlOut_Function(uint8 SensorChanel,uint8 valEn_Lo)
{
	Std_ReturnType valRet = E_OK;
	if(valEn_Lo > 1)
	{
		return E_NOT_OK;
	}
	switch(SensorChanel)
	{
		case SYS_5VSENSOR1_OUTPUT_CH:
		Cdd_Sbc_Sa47301_SetLdoEnFunction(SA47301_LDO_CH_TRK1,valEn_Lo);
		break;
		case SYS_5VSENSOR2_OUTPUT_CH:
		Cdd_Sbc_Sa47301_SetLdoEnFunction(SA47301_LDO_CH_TRK2,valEn_Lo);
		break;
		case SYS_HVDriver_5V_OUTPUT_CH:
		IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_D_HV_5V_EN, valEn_Lo);
		break;
		case SYS_Driver_5V_OUTPUT_CH:
		IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_D_Driver_5V_EN, valEn_Lo);
		break;
		case SYS_12VPOWER_OUTPUT_CH:
		IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_SEPIC_EN, valEn_Lo);
		break;
		default:
		valRet = E_NOT_OK;
		break;
	}
	return valRet;
}
// void ExternalWdg_Ctrl_Cbk_GptNotification(void)
// {

// }
#endif
extern uint8 SA_WdgRestFlag_Mp;
Std_ReturnType BswM_RequestReset(uint8 ValResetMode)
{
	Std_ReturnType ret = E_NOT_OK;
	if(ValResetMode == BSWM_RESET_TYPE_HARD)
	{
        SA_WdgRestFlag_Mp = 1;
		ret = E_OK;
	}
	if(ValResetMode == BSWM_RESET_TYPE_SOFT)
	{
		Mcu_PerformReset();
		ret = E_OK;
	}
    else if(ValResetMode == BSWM_RESET_TYPE_BOOT)
    {
        Pm_FlgBootJump_Mp = 1;
        ret = E_OK;
    }

	return ret;
}

Std_ReturnType Sys_SetWakeTime(uint32 valWakeTime)
{
    if(valWakeTime > 0xFFFFFF)
    {
        return E_NOT_OK;
    }
    else
    {
        Sys_tiWakeTimeEn = true;
        Sys_tiWakeTime= valWakeTime;
    }
    return E_OK;
}

Std_ReturnType Sys_UpdateRemainWakeTime(void)
{
    uint32 RemainWakeTime = 0;
    Cdd_Sbc_Sa47301_GetPoweroffTimeFunction(&RemainWakeTime);

    if (RemainWakeTime <= 0xFFFFFFFF) 
    {
        Sys_tiRemainWakeTime = RemainWakeTime;
        return E_OK;    
    }
    else
    {
        Sys_tiRemainWakeTime = 0;
        return E_NOT_OK;
    }
    return E_OK;
}

Std_ReturnType Sys_GetRemainWakeTime(uint32* valRemainWakeTime)
{
    if(valRemainWakeTime == NULL)
    {
        return E_NOT_OK;
    }

    if(Sys_tiRemainWakeTime > 0xFFFFFF)
    {
        return E_NOT_OK;
    }

    *valRemainWakeTime = Sys_tiRemainWakeTime;

    return E_OK;
}


