#include "Std_Types.h"
#include "NVM_XCU.h"

#include "Adc.h"
#include "Interface_Test_IO.h"
#include "IoHwAbs_ADC_Prv.h"

extern boolean NVM_XCU_EEWriteReq;		//NVM下电写函数完成标志位 0:未完成 1:已完成
extern boolean NVM_XCU_EEWriteFinish;	//NVM下电写函数完成标志位 0:未完成 1:已完成
extern uint8 	NvM_WriteOpStatus;		//NVM下电写函数进入次数;

extern uint16 Adc_valDMAReadBufferGroup15_ARRY[3];
extern uint16 Adc_valResultBufferGroup11_ARRY[4];
extern uint16 Adc_valResultBufferGroup15_ARRY[3];
extern uint16 Adc_valResultBufferGroup7_ARRY[2];

uint8 KL15_Status_MP 	= 0;//KL15 IO状态
uint8 CHG_Status_MP 	= 0;//A+ 1 IO状态
uint8 OBC_Status_MP 	= 0;//OBC IO状态

void Get_WakeUp_ADC(void);

FUNC(void, RTE_CODE) Core0_Runnable_Task_Init(void)
{
	NVM_XCU_EERead();
}

FUNC(void, RTE_CODE) Core0_Runnable_App_1ms(void)
{

	#ifdef VCU_Test_Code_YXP
	Test_SetIO_Status_LS9(0);
	#endif

	Get_WakeUp_ADC();
}

FUNC(void, RTE_CODE) Core0_Runnable_App_5ms(void)
{
    if(NVM_XCU_EEWriteReq == 1)
	{
		NVM_XCU_EEWriteFinish = NVM_XCU_EEWrite(&NvM_WriteOpStatus);
		if(NVM_XCU_EEWriteFinish == 1)
		{
			NVM_XCU_EEWriteReq = 0;
		}
	}
}

FUNC(void, RTE_CODE) Core0_Runnable_App_10ms(void)
{
	NVM_XCU_EEWriteImm();
}

FUNC(void, RTE_CODE) Core0_Runnable_App_20ms(void)
{

}

FUNC(void, RTE_CODE) Core0_Runnable_App_50ms(void)
{

}

FUNC(void, RTE_CODE) Core0_Runnable_App_100ms(void)
{


}


void Get_WakeUp_ADC(void)
{
	//KL15 
	if((IoHwAbs_ADC_ConvertArrayRaw2Mv(Adc_valResultBufferGroup15_ARRY[0])*IoHwAbs_ADC_ChannelFormula_BAT) > 6000)
	{
		KL15_Status_MP = 1;
	}
	else
	{
		KL15_Status_MP = 0;
	}

	//A+ 1
	if((IoHwAbs_ADC_ConvertArrayRaw2Mv(Adc_valResultBufferGroup11_ARRY[0])*IoHwAbs_ADC_ChannelFormula_BAT) > 6000)
	{
		CHG_Status_MP = 1;
	}
	else
	{
		CHG_Status_MP = 0;
	}

	//OBC
	if((IoHwAbs_ADC_ConvertArrayRaw2Mv(Adc_valResultBufferGroup7_ARRY[0])*IoHwAbs_ADC_ChannelFormula_BAT) > 6000)
	{
		OBC_Status_MP = 1;
	}
	else
	{
		OBC_Status_MP = 0;
	}
	
}



