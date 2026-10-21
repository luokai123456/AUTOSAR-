
#include "CusM_XCU.h"
#include "System_Release.h"
#include "IoHwAbs_ADC.h"
#include "NVM_XCU.h"

#include "Interface_Test_IO.h"

extern uint8 Ea_ShutdownReq;
extern uint8 PMS_EcuCtrl_SetShutDownReq;

boolean WakeUpFlg				= 0;
boolean WakeUpFlg_Last			= 0;
uint16 XCU_WaitPoweroffCounter	= 0; 
uint16 XCU_ChargeOnVltg			= 0;
uint16 XCU_KeyOnVltg			= 0;
uint8  XCU_PowerOffFlg			= 1;

extern uint8 KL15_Status_MP;	//KL15 IO状态
extern uint8 CHG_Status_MP;		//A+ 1 IO状态
extern uint8 OBC_Status_MP;		//OBC IO状态

boolean NVM_XCU_EEWriteReq 		= 0;	//NVM下电写函数完成标志位 0:未完成 1:已完成
boolean NVM_XCU_EEWriteFinish 	= 0;	//NVM下电写函数完成标志位 0:未完成 1:已完成
uint8 	NvM_WriteOpStatus 		= 0;	//NVM下电写函数进入次数;


void XCU_TaskGoRun(void)
{

	IoHwAbs_ADC_GetChannelRawValue( IOHWABS_ADC_CHANNEL_AN_DC_APlus1_Mic, &XCU_ChargeOnVltg);
	IoHwAbs_ADC_GetChannelRawValue( IOHWABS_ADC_CHANNEL_AN_KEY_Mic, &XCU_KeyOnVltg);

	WakeUpFlg = (CHG_Status_MP == 1U)||(KL15_Status_MP == 1U)||(OBC_Status_MP == 1U)||((!PMS_EcuCtrl_SetShutDownReq) == 1U)||(Ea_ShutdownReq != 2U);//A+和钥匙和OBC变更为更快的采集方式

	if(WakeUpFlg == 1U)
	{
		XCU_WaitPoweroffCounter		= 0;
		XCU_PowerOffFlg				= FALSE;
		NvM_WriteOpStatus 			= 0;
		NVM_XCU_EEWriteFinish		= FALSE;
		NVM_XCU_EEWriteReq			= FALSE;
	}
	else if((WakeUpFlg_Last == 1)&&(WakeUpFlg == 0))//唤醒标志位下降沿
	{
		NVM_XCU_EEWriteReq 			= TRUE;
	}
	else
	{
		// NVM_XCU_EEWriteFinish = NVM_XCU_EEWrite(&NvM_WriteOpStatus);
		if((NVM_XCU_EEWriteReq == TRUE)&&(XCU_WaitPoweroffCounter < 100U))
		{
			XCU_WaitPoweroffCounter++;
			XCU_PowerOffFlg 		= FALSE;
		}
		else
		{
			NVM_XCU_EEWriteReq 		= FALSE;
			XCU_PowerOffFlg 		= TRUE;
		}
	}

	WakeUpFlg_Last = WakeUpFlg;//记录上一时刻的唤醒状态
#ifndef YXL_TEST_CODE
	BswM_RequestPwerOff(XCU_PowerOffFlg);
#endif
}
