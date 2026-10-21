/******************************************************************************
* 文件名       : Rte_RunnableDefineFunc.c
* 作者         : Sunxq
* 创建日期     : 2026-04-03
* 描述         : RTE runnable define functions
* 版本         : V0.0
* 修改历史     :
*   2026-04-03 Sunxq 初始版本
******************************************************************************/
#include "Rte_RunnableDefineFunc.h"
#include "Pwm3ph.h"
#include "IoHwAbs_ADC.h"
#include "IoHwAbs_ADC_Prv.h"
#include "IoHwAbs_ADC_Filter.h"
#include "Cdd_Afe_Manage.h"
#include "Adc3ph.h"
#include "Cdd_Sa47301.h"
#include "EvptCdd_TPT1145.h"
#include "IoHwAbs_PWM_Prv.h"
#include "EvptCdd_HE99MD_prv.h"
#include "SigResolverAngleDecoder.h"
#include "SigSignalAdapter.h"
#include "SigPreProcessor.h"
#include "Cdd_Imu_Control.h"
#include "Bsw_BootLoader.h"
#include "IoHwAbs_ICU_prv.h"
#include "IoHwAbs_Icu.h"
#include "BswM.h"
#include "EcuM.h"
#include "Os_Monitor.h"
#include "NvM.h"
#include "Fee.h"
#include "Fls.h"
#include "Can_Interface.h"
#include "System_Release.h"
#include "Motor_HwIf.h"
#include "Xcp_Swc.h"
#include "VX1000If.h"
#include "Evpt_System.h"
#include "Can_Device_Prv.h"
#include "Lsd_Control.h"
#include "Hsd_Control.h"
#include "Cdd_Hsd_WSD7020AF.h"
#include "Hsd_Release.h"
#include "Lsd_Release.h"
#include "EvptCdd_HE99MD_prv.h"
#include "Motor_Diag.h"
#include "IoHwAbs_DIO_prv.h"
#include "ErrorDiag_Interface.h"
#include "ErrorDiag_Errorid.h"
#include "SDAdc.h"
#include "RdcDrv.h"
#include "Evpt_InterDataWatch_Prv.h"
#include "WdgM.h"
#include "ExternalWdg_Ctrl.h"
#include "CusM_XCU.h"
#ifdef FUNC_SAFETY
#include "saf_sch.h"
#include "saf_dma.h"
#endif
#ifdef MOTORCTRL_TEST
#include "AswAdapter.h"
#include "CtlDeratingManager.h"
#include "CtlStateOrchestrator.h"
#include "CtlTorqueLoopController.h"
#include "FltFaultDiagnoser.h"
#include "McuFunSafeMonitor.h"
#else

#endif
/**************************Global Varibles*************************** */

void Reserved_WdgM_Function_Core0(void);
void Reserved_WdgM_Function_Core1(void);
void Reserved_WdgM_Function_Core2(void);
void Reserved_WdgM_Function_Core3(void);
void Reserved_WdgM_Function_Core4(void);
void Reserved_WdgM_Function_Core5(void);

/* 描述: 半桥输出函数
 * 参数：
 * 		HB_PwmCtrl: 0: continuous 1: PWM
 * 		HB_Fct: 0:off 1: LS 2: HS
 * 		HB_Freq: 0: 80Hz 1: 100Hz 2: 200Hz 3: 2000Hz
 * 		HB_Duty: 0~100
 */
#ifdef YXL_TEST_CODE
extern uint8 Cdd_HalfBridegeOut_Function(
		uint8 HB_valChannel, uint8 HB_PwmCtrl, uint8 HB_Fct,
		uint8 HB_Freq, uint8 HB_Duty
	);
uint8 BTsk_HalfBridgeOut_Ctr[8]={0};
uint8 Diag_Clear_Cal = 0;
uint8 Diag_ClearCh_Cal = ERRORID_HE99MD_EXT_HB1_OC;
volatile uint8 Tsk_valCanTxChannel_Mp = 89;
uint16 Adc_valUbdRawVolt_Mp = 0;
uint16 Adc_valUbdFilterVolt_Mp = 0;
extern void AdcInTest10ms_Function(void);
void CAN_SendHalfErrorStatus_Function(void)
{
	AdcInTest10ms_Function();
	extern boolean ErrorDiag_Receive_ErrorStatus(uint16 ErrorId);
	uint8 DataPtr[8] = {0};
	Can_PduType canPduInfo;
	canPduInfo.sdu = DataPtr;
	canPduInfo.swPduHandle = Tsk_valCanTxChannel_Mp;
	canPduInfo.length = 8;
	canPduInfo.id = 0x325;
	DataPtr[0] = (ErrorDiag_Receive_ErrorStatus(ERRORID_HE99MD_EXT_HB1_OC) << 7)|
				 (ErrorDiag_Receive_ErrorStatus(ERRORID_HE99MD_EXT_HB2_OC) << 6)|
				 (ErrorDiag_Receive_ErrorStatus(ERRORID_HE99MD_EXT_HB3_OC) << 5)|
				 (ErrorDiag_Receive_ErrorStatus(ERRORID_HE99MD_EXT_HB4_OC) << 4)|
				 (ErrorDiag_Receive_ErrorStatus(ERRORID_HE99MD_EXT_HB5_OC) << 3)|
				 (ErrorDiag_Receive_ErrorStatus(ERRORID_HE99MD_EXT_HB6_OC) << 2)|
				 (ErrorDiag_Receive_ErrorStatus(ERRORID_HE99MD_EXT_HB7_OC) << 1)|
				 (ErrorDiag_Receive_ErrorStatus(ERRORID_HE99MD_EXT_HB8_OC) << 0);
	DataPtr[1] = (ErrorDiag_Receive_ErrorStatus(ERRORID_HE99MD_EXT_HB1_OPL) << 7)|
				 (ErrorDiag_Receive_ErrorStatus(ERRORID_HE99MD_EXT_HB2_OPL) << 6)|
				 (ErrorDiag_Receive_ErrorStatus(ERRORID_HE99MD_EXT_HB3_OPL) << 5)|
				 (ErrorDiag_Receive_ErrorStatus(ERRORID_HE99MD_EXT_HB4_OPL) << 4)|
				 (ErrorDiag_Receive_ErrorStatus(ERRORID_HE99MD_EXT_HB5_OPL) << 3)|
				 (ErrorDiag_Receive_ErrorStatus(ERRORID_HE99MD_EXT_HB6_OPL) << 2)|
				 (ErrorDiag_Receive_ErrorStatus(ERRORID_HE99MD_EXT_HB7_OPL) << 1)|
				 (ErrorDiag_Receive_ErrorStatus(ERRORID_HE99MD_EXT_HB8_OPL) << 0);

	DataPtr[2] = (uint8)(Adc_valUbdRawVolt_Mp >> 0)& 0xFF;
	DataPtr[3] = (uint8)(Adc_valUbdRawVolt_Mp >> 8)& 0xFF;
	DataPtr[4] = (uint8)(Adc_valUbdFilterVolt_Mp >> 0)& 0xFF;
	DataPtr[5] = (uint8)(Adc_valUbdFilterVolt_Mp >> 8)& 0xFF;
	Cdd_Hsd_SetLevelFunction(EXT_D_HS_CH_1,true);
	Can_Write(Tsk_valCanTxChannel_Mp, &canPduInfo);
}
void HalfBridgeOutTest10ms_Function(void)
{
	static uint16 numCtrlCnt = 0;
	if(numCtrlCnt < 100)
	{
		numCtrlCnt++;

	}
	else
	{
		numCtrlCnt = 0;
//		BswM_RequestReset(1);
		BTsk_HalfBridgeOut_Ctr[0] = 100 -BTsk_HalfBridgeOut_Ctr[0];
	}
	uint8 numCnt=0;
	for(numCnt=0;numCnt<8;numCnt++)
	{

		Cdd_HalfBridegeOut_Function(numCnt, 1U, 1,1U, BTsk_HalfBridgeOut_Ctr[0]);
	}
	if(Diag_Clear_Cal == 1)
	{
		ErrorDiag_ClearErrorStatus(Diag_ClearCh_Cal);
	}
}
void AdcInTest10ms_Function(void)
{	
	IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_AN_UBD_Mic, &Adc_valUbdRawVolt_Mp);
	IoHwAbs_ADC_GetChannelValue(IOHWABS_ADC_CHANNEL_AN_UBD_Mic, &Adc_valUbdFilterVolt_Mp);
}
void TestCode10ms_MainFunction(void)
{
	HalfBridgeOutTest10ms_Function();
	

}
#endif
volatile static uint16 timer_30ms = 0;
extern uint8 NvM_Sart_Flag;
FUNC(void, RTE_CODE) Core0_Runnable_Bsw_5ms(void)
{
    if(NvM_Sart_Flag == 1)
    {
        NvM_MainFunction();
        Fee_MainFunction();
        Fls_MainFunction();
        NvM_MainFunction();
        Fee_MainFunction();
        Fls_MainFunction();
        NvM_MainFunction();
        Fee_MainFunction();
        Fls_MainFunction();
        NvM_MainFunction();
        Fee_MainFunction();
        Fls_MainFunction();
    }
}

/**
 * name: Core0_Runnable_Bsw_10ms
 * parameter[in]: none
 * parameter[out]: none
 * return value: none
 * brief: the 10ms scheduler of core 0 in the bottom layer
 */

FUNC(void, RTE_CODE) Core0_Runnable_Bsw_10ms(void)
{
#ifdef YXL_TEST_CODE
	Cdd_Hsd_SetLevelFunction(EXT_D_HS_CH_2,true);
#endif
	timer_30ms++;
	if ((timer_30ms % 3) == 0)
	{
		ExternalWdg_FeedFWD_Function();
		timer_30ms = 0;
	}

    IoHwAbs_ADC_MainFunction();
    IoHwAbs_ADC_ReFileterValue();
    IoHwAbs_Pwm_Mainfunction();
    IoHwAbs_Icu_MainFunction();
    IoHwAbs_DIO_MainFunction();

    Cdd_Afe_MainFunction_10ms();
    CanTrcv_TPT1145_MainFunction_10ms();
    // Adc3ph_MainFunction();
    Cdd_Sbc_Sa47301_10msMainFunction();
    HBridge_MainFunction();
    Cdd_Imu_MainFunction_10ms();

    EcuM_MainFunction();
    BootLoader_MainFunction_10ms();

    Motor_ADC_MainFunction();
    extern void BswUserCallout_SWC_Delay_PowerOffPort(void);
    BswUserCallout_SWC_Delay_PowerOffPort();
/*new add for diag 0503*/
    ErrorDiag_MainFunction();
    ErrorHandler_MainFunction();
	DetectErrDiag_Task();
    Cdd_Hsd_10msMainFunction();
    Cdd_Lsd_10msMainFunction();
    EH_He99md_DiagFunction();
	Evpt_Diagnostic_Database_NeusarDiagData();
	Evpt_Diagnostic_TaskStackData_Core0();
/*new add for diag 0503 end*/

	Reserved_WdgM_Function_Core0();
    WdgM_MainFunction();

#ifdef FUNC_SAFETY
    SAF_SCH_RuntimeTest();
#endif
#ifdef YXL_TEST_CODE
	TestCode10ms_MainFunction();
#endif
}
/**
 * name: Core1_Runnable_Bsw_10ms
 * parameter[in]: none
 * parameter[out]: none
 * return value: none
 * brief: the 10ms scheduler of core 1 in the bottom layer
 */

FUNC(void, RTE_CODE) Core1_Runnable_Bsw_10ms(void)
{
    EcuM_MainFunction();
	Reserved_WdgM_Function_Core1();
	WdgM_MainFunction();
    Os_Monitor_MainFunction();
	Evpt_Diagnostic_TaskStackData_Core1();
}

/**
 * name: Core2_Runnable_Bsw_10ms
 * parameter[in]: none
 * parameter[out]: none
 * return value: none
 * brief: the 10ms scheduler of core 2 in the bottom layer
 */
FUNC(void, RTE_CODE) Core2_Runnable_Bsw_10ms(void)
{
	EcuM_MainFunction();
	Evpt_Diagnostic_TaskStackData_Core2();
	Reserved_WdgM_Function_Core2();
	WdgM_MainFunction();
}

/**
 * name: Core3_Runnable_Bsw_2ms
 * parameter[in]: none
 * parameter[out]: none
 * return value: none
 * brief: the 2ms scheduler of core 3 in the bottom layer
 */
FUNC(void, RTE_CODE) Core3_Runnable_Bsw_1ms(void)
{
	Motor_Diag_DIOMainFunction();
	SGRD_DiagResolverFault_1ms();
	SGSA_ReadTempVolt_1ms();
	SGPP_ReadTempVolt_1ms();

	#ifdef MOTORCTRL_TEST
	MFSM_FuncSafetyRedundancy_1ms();
	ASWA_ReadProcess_1ms();
	FLDG_DiagFaultResponse_1ms();
	CTSO_ManageStateMode_1ms();
	CTDM_Derating_1ms();
	CTLC_CalcIdIqRef_1ms();

	#else

	#endif

}

/**
 * name: Core3_Runnable_Bsw_5ms
 * parameter[in]: none
 * parameter[out]: none
 * return value: none
 * brief: the 5ms scheduler of core 3 in the bottom layer
 */
FUNC(void, RTE_CODE) Core3_Runnable_Bsw_5ms(void)
{
	EcuM_MainFunction();
	#ifdef MOTORCTRL_TEST
	FLDG_DiagTempSlow_10ms();
	#else

	#endif
}

// /**
//  * name: Core3_Runnable_Bsw_10ms
//  * parameter[in]: none
//  * parameter[out]: none
//  * return value: none
//  * brief: the 10ms scheduler of core 3 in the bottom layer
//  */
// FUNC(void, RTE_CODE) Core3_Runnable_Bsw_10ms(void)
// {

// }

// /**
//  * name: Core3_Runnable_Bsw_20ms 
//  * parameter[in]: none
//  * parameter[out]: none
//  * return value: none
//  * brief: the 20ms scheduler of core 3 in the bottom layer
//  */
// FUNC(void, RTE_CODE) Core3_Runnable_Bsw_20ms(void)
// {

// }
// /**
//  * name: Core3_Runnable_Bsw_50ms
//  * parameter[in]: none
//  * parameter[out]: none
//  * return value: none
//  * brief: the 50ms scheduler of core 3 in the bottom layer
//  */
// FUNC(void, RTE_CODE) Core3_Runnable_Bsw_50ms(void)
// {

// }

// /**
//  * name: Core3_Runnable_Bsw_100ms
//  * parameter[in]: none
//  * parameter[out]: none
//  * return value: none
//  * brief: the 100ms scheduler of core 3 in the bottom layer
//  */
// FUNC(void, RTE_CODE) Core3_Runnable_Bsw_100ms(void)
// {

// }

// /**
//  * name: Core3_Runnable_Bsw1_100ms
//  * parameter[in]: none
//  * parameter[out]: none
//  * return value: none
//  * brief: the 100ms scheduler of core 3 in the bottom layer
//  */
// FUNC(void, RTE_CODE) Core3_Runnable_Bsw1_100ms(void)
// {

// }

/**
 * name: Core4_Runnable_Bsw_2ms
 * parameter[in]: none
 * parameter[out]: none
 * return value: none
 * brief: the 2ms scheduler of core 4 in the bottom layer
 */
FUNC(void, RTE_CODE) Core4_Runnable_Bsw_1ms(void)
{

}

/**
 * name: Core4_Runnable_Bsw_5ms
 * parameter[in]: none
 * parameter[out]: none
 * return value: none
 * brief: the 5ms scheduler of core 4 in the bottom layer
 */
FUNC(void, RTE_CODE) Core4_Runnable_Bsw_5ms(void)
{
	XCU_TaskGoRun();

}
/**
 * name: Core4_Runnable_Bsw_10ms
 * parameter[in]: none
 * parameter[out]: none
 * return value: none
 * brief: the 10ms scheduler of core 4 in the bottom layer
 */
FUNC(void, RTE_CODE) Core4_Runnable_Bsw_10ms(void)
{
    EcuM_MainFunction();
	Reserved_WdgM_Function_Core4();
	WdgM_MainFunction();
	XCP_Step();
	VX1000_Step();
	Evpt_Diagnostic_TaskStackData_Core4();
#ifdef YXL_TEST_CODE
    CAN_SendHalfErrorStatus_Function();
#endif
}
/**
 * name: Core4_Runnable_Bsw_20ms
 * parameter[in]: none
 * parameter[out]: none
 * return value: none
 * brief: the 20ms scheduler of core 4 in the bottom layer
 */
FUNC(void, RTE_CODE) Core4_Runnable_Bsw_20ms(void)
{
    CAN_Device_MainFunction();
}

/**
 * name: Core4_Runnable_Bsw_50ms
 * parameter[in]: none
 * parameter[out]: none
 * return value: none
 * brief: the 50ms scheduler of core 4 in the bottom layer
 */
FUNC(void, RTE_CODE) Core4_Runnable_Bsw_50ms(void)
{

}

/**
 * name: Core4_Runnable_Bsw_100ms
 * parameter[in]: none
 * parameter[out]: none
 * return value: none
 * brief: the 100ms scheduler of core 4 in the bottom layer
 */
FUNC(void, RTE_CODE) Core4_Runnable_Bsw_100ms(void)
{

}

/**
 * name: Core5_Runnable_Bsw_10ms
 * parameter[in]: none
 * parameter[out]: none
 * return value: none
 * brief: the 10ms scheduler of core 5 in the bottom layer
 */
FUNC(void, RTE_CODE) Core5_Runnable_Bsw_10ms(void)
{
    EcuM_MainFunction();
	Evpt_Diagnostic_TaskStackData_Core5();
	Reserved_WdgM_Function_Core5();
	WdgM_MainFunction();
}

#ifdef FUNC_SAFETY
uint32 ire_cnt_test = 0;

void SAF_EDMA_LLD_IRQHandler(uint8 chan)
{
    SAF_EDMA_HW_ClearIntStatus(chan);
    SAF_DMA_GetEndTransmissionTime(chan);
    SAF_DMA_AppendDoneTxCount(chan, 1);
}

void DMA0_Ch63_IRQHandler(void)
{
    ire_cnt_test++;
    SAF_EDMA_LLD_IRQHandler(63);
}
#endif

void Reserved_WdgM_Function_Core0(void)
{
    /*Alive Start*/
    WdgM_CheckpointReached(WDGM_SE0_AliveCounter_C0,WdgM_SE0_AliveCounter_C0_Mode0_SE0_Alive_CP_C0);
    WdgM_CheckpointReached(WDGM_SE1_AliveCounter_C0,WdgM_SE1_AliveCounter_C0_Mode0_SE1_Alive_CP_C0);
    WdgM_CheckpointReached(WDGM_SE2_AliveCounter_C0,WdgM_SE2_AliveCounter_C0_Mode0_SE2_Alive_CP_C0);
    WdgM_CheckpointReached(WDGM_SE3_AliveCounter_C0,WdgM_SE3_AliveCounter_C0_Mode0_SE3_Alive_CP_C0);
    WdgM_CheckpointReached(WDGM_SE4_AliveCounter_C0,WdgM_SE4_AliveCounter_C0_Mode0_SE4_Alive_CP_C0);
    /*Alive End*/

    /*Deadline Start*/
	WdgM_CheckpointReached(WDGM_SE0_Deadline_C0,WdgM_SE0_Deadline_C0_Mode0_SE0_Deadline_CP1_C0);
    WdgM_CheckpointReached(WDGM_SE1_Deadline_C0,WdgM_SE1_Deadline_C0_Mode0_SE1_Deadline_CP1_C0);
	WdgM_CheckpointReached(WDGM_SE2_Deadline_C0,WdgM_SE2_Deadline_C0_Mode0_SE2_Deadline_CP1_C0);
	WdgM_CheckpointReached(WDGM_SE3_Deadline_C0,WdgM_SE3_Deadline_C0_Mode0_SE3_Deadline_CP1_C0);
	WdgM_CheckpointReached(WDGM_SE4_Deadline_C0,WdgM_SE4_Deadline_C0_Mode0_SE4_Deadline_CP1_C0);
    
	WdgM_CheckpointReached(WDGM_SE0_Deadline_C0,WdgM_SE0_Deadline_C0_Mode0_SE0_Deadline_CP2_C0);
    WdgM_CheckpointReached(WDGM_SE1_Deadline_C0,WdgM_SE1_Deadline_C0_Mode0_SE1_Deadline_CP2_C0);
	WdgM_CheckpointReached(WDGM_SE2_Deadline_C0,WdgM_SE2_Deadline_C0_Mode0_SE2_Deadline_CP2_C0);
	WdgM_CheckpointReached(WDGM_SE3_Deadline_C0,WdgM_SE3_Deadline_C0_Mode0_SE3_Deadline_CP2_C0);
	WdgM_CheckpointReached(WDGM_SE4_Deadline_C0,WdgM_SE4_Deadline_C0_Mode0_SE4_Deadline_CP2_C0);
    /*Deadline End*/

    /*ProgramFlow Start*/
    WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C0,WdgM_SE0_ProgramFlow_C0_Mode0_SE0_Logical_CP1_C0);
	WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C0,WdgM_SE0_ProgramFlow_C0_Mode0_SE0_Logical_CP2_C0);
    WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C0,WdgM_SE0_ProgramFlow_C0_Mode0_SE0_Logical_CP3_C0);
	WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C0,WdgM_SE0_ProgramFlow_C0_Mode0_SE0_Logical_CP4_C0);
    WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C0,WdgM_SE0_ProgramFlow_C0_Mode0_SE0_Logical_CP5_C0);
	WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C0,WdgM_SE0_ProgramFlow_C0_Mode0_SE0_Logical_CP6_C0);
    /*ProgramFlow End*/
}

void Reserved_WdgM_Function_Core1(void)
{
    /*Alive Start*/
    WdgM_CheckpointReached(WDGM_SE0_AliveCounter_C1,WdgM_SE0_AliveCounter_C1_Mode0_SE0_Alive_CP_C1);
    WdgM_CheckpointReached(WDGM_SE1_AliveCounter_C1,WdgM_SE1_AliveCounter_C1_Mode0_SE1_Alive_CP_C1);
    WdgM_CheckpointReached(WDGM_SE2_AliveCounter_C1,WdgM_SE2_AliveCounter_C1_Mode0_SE2_Alive_CP_C1);
    WdgM_CheckpointReached(WDGM_SE3_AliveCounter_C1,WdgM_SE3_AliveCounter_C1_Mode0_SE3_Alive_CP_C1);
    WdgM_CheckpointReached(WDGM_SE4_AliveCounter_C1,WdgM_SE4_AliveCounter_C1_Mode0_SE4_Alive_CP_C1);
    /*Alive End*/

    /*Deadline Start*/
	WdgM_CheckpointReached(WDGM_SE0_Deadline_C1,WdgM_SE0_Deadline_C1_Mode0_SE0_Deadline_CP1_C1);
    WdgM_CheckpointReached(WDGM_SE1_Deadline_C1,WdgM_SE1_Deadline_C1_Mode0_SE1_Deadline_CP1_C1);
	WdgM_CheckpointReached(WDGM_SE2_Deadline_C1,WdgM_SE2_Deadline_C1_Mode0_SE2_Deadline_CP1_C1);
	WdgM_CheckpointReached(WDGM_SE3_Deadline_C1,WdgM_SE3_Deadline_C1_Mode0_SE3_Deadline_CP1_C1);
	WdgM_CheckpointReached(WDGM_SE4_Deadline_C1,WdgM_SE4_Deadline_C1_Mode0_SE4_Deadline_CP1_C1);
    
	WdgM_CheckpointReached(WDGM_SE0_Deadline_C1,WdgM_SE0_Deadline_C1_Mode0_SE0_Deadline_CP2_C1);
    WdgM_CheckpointReached(WDGM_SE1_Deadline_C1,WdgM_SE1_Deadline_C1_Mode0_SE1_Deadline_CP2_C1);
	WdgM_CheckpointReached(WDGM_SE2_Deadline_C1,WdgM_SE2_Deadline_C1_Mode0_SE2_Deadline_CP2_C1);
	WdgM_CheckpointReached(WDGM_SE3_Deadline_C1,WdgM_SE3_Deadline_C1_Mode0_SE3_Deadline_CP2_C1);
	WdgM_CheckpointReached(WDGM_SE4_Deadline_C1,WdgM_SE4_Deadline_C1_Mode0_SE4_Deadline_CP2_C1);
    /*Deadline End*/

    /*ProgramFlow Start*/
    WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C1,WdgM_SE0_ProgramFlow_C1_Mode0_SE0_Logical_CP1_C1);
	WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C1,WdgM_SE0_ProgramFlow_C1_Mode0_SE0_Logical_CP2_C1);
    WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C1,WdgM_SE0_ProgramFlow_C1_Mode0_SE0_Logical_CP3_C1);
	WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C1,WdgM_SE0_ProgramFlow_C1_Mode0_SE0_Logical_CP4_C1);
    WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C1,WdgM_SE0_ProgramFlow_C1_Mode0_SE0_Logical_CP5_C1);
	WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C1,WdgM_SE0_ProgramFlow_C1_Mode0_SE0_Logical_CP6_C1);
    /*ProgramFlow End*/
}

void Reserved_WdgM_Function_Core2(void)
{
    /*Alive Start*/
    WdgM_CheckpointReached(WDGM_SE0_AliveCounter_C2,WdgM_SE0_AliveCounter_C2_Mode0_SE0_Alive_CP_C2);
    WdgM_CheckpointReached(WDGM_SE1_AliveCounter_C2,WdgM_SE1_AliveCounter_C2_Mode0_SE1_Alive_CP_C2);
    WdgM_CheckpointReached(WDGM_SE2_AliveCounter_C2,WdgM_SE2_AliveCounter_C2_Mode0_SE2_Alive_CP_C2);
    WdgM_CheckpointReached(WDGM_SE3_AliveCounter_C2,WdgM_SE3_AliveCounter_C2_Mode0_SE3_Alive_CP_C2);
    WdgM_CheckpointReached(WDGM_SE4_AliveCounter_C2,WdgM_SE4_AliveCounter_C2_Mode0_SE4_Alive_CP_C2);
    /*Alive End*/

    /*Deadline Start*/
	WdgM_CheckpointReached(WDGM_SE0_Deadline_C2,WdgM_SE0_Deadline_C2_Mode0_SE0_Deadline_CP1_C2);
    WdgM_CheckpointReached(WDGM_SE1_Deadline_C2,WdgM_SE1_Deadline_C2_Mode0_SE1_Deadline_CP1_C2);
	WdgM_CheckpointReached(WDGM_SE2_Deadline_C2,WdgM_SE2_Deadline_C2_Mode0_SE2_Deadline_CP1_C2);
	WdgM_CheckpointReached(WDGM_SE3_Deadline_C2,WdgM_SE3_Deadline_C2_Mode0_SE3_Deadline_CP1_C2);
	WdgM_CheckpointReached(WDGM_SE4_Deadline_C2,WdgM_SE4_Deadline_C2_Mode0_SE4_Deadline_CP1_C2);
    
	WdgM_CheckpointReached(WDGM_SE0_Deadline_C2,WdgM_SE0_Deadline_C2_Mode0_SE0_Deadline_CP2_C2);
    WdgM_CheckpointReached(WDGM_SE1_Deadline_C2,WdgM_SE1_Deadline_C2_Mode0_SE1_Deadline_CP2_C2);
	WdgM_CheckpointReached(WDGM_SE2_Deadline_C2,WdgM_SE2_Deadline_C2_Mode0_SE2_Deadline_CP2_C2);
	WdgM_CheckpointReached(WDGM_SE3_Deadline_C2,WdgM_SE3_Deadline_C2_Mode0_SE3_Deadline_CP2_C2);
	WdgM_CheckpointReached(WDGM_SE4_Deadline_C2,WdgM_SE4_Deadline_C2_Mode0_SE4_Deadline_CP2_C2);
    /*Deadline End*/

    /*ProgramFlow Start*/
    WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C2,WdgM_SE0_ProgramFlow_C2_Mode0_SE0_Logical_CP1_C2);
	WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C2,WdgM_SE0_ProgramFlow_C2_Mode0_SE0_Logical_CP2_C2);
    WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C2,WdgM_SE0_ProgramFlow_C2_Mode0_SE0_Logical_CP3_C2);
	WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C2,WdgM_SE0_ProgramFlow_C2_Mode0_SE0_Logical_CP4_C2);
    WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C2,WdgM_SE0_ProgramFlow_C2_Mode0_SE0_Logical_CP5_C2);
	WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C2,WdgM_SE0_ProgramFlow_C2_Mode0_SE0_Logical_CP6_C2);
    /*ProgramFlow End*/
}

void Reserved_WdgM_Function_Core3(void)
{
    /*Alive Start*/
    WdgM_CheckpointReached(WDGM_SE0_AliveCounter_C3,WdgM_SE0_AliveCounter_C3_Mode0_SE0_Alive_CP_C3);
    WdgM_CheckpointReached(WDGM_SE1_AliveCounter_C3,WdgM_SE1_AliveCounter_C3_Mode0_SE1_Alive_CP_C3);
    WdgM_CheckpointReached(WDGM_SE2_AliveCounter_C3,WdgM_SE2_AliveCounter_C3_Mode0_SE2_Alive_CP_C3);
    WdgM_CheckpointReached(WDGM_SE3_AliveCounter_C3,WdgM_SE3_AliveCounter_C3_Mode0_SE3_Alive_CP_C3);
    WdgM_CheckpointReached(WDGM_SE4_AliveCounter_C3,WdgM_SE4_AliveCounter_C3_Mode0_SE4_Alive_CP_C3);
    /*Alive End*/

    /*Deadline Start*/
	WdgM_CheckpointReached(WDGM_SE0_Deadline_C3,WdgM_SE0_Deadline_C3_Mode0_SE0_Deadline_CP1_C3);
    WdgM_CheckpointReached(WDGM_SE1_Deadline_C3,WdgM_SE1_Deadline_C3_Mode0_SE1_Deadline_CP1_C3);
	WdgM_CheckpointReached(WDGM_SE2_Deadline_C3,WdgM_SE2_Deadline_C3_Mode0_SE2_Deadline_CP1_C3);
	WdgM_CheckpointReached(WDGM_SE3_Deadline_C3,WdgM_SE3_Deadline_C3_Mode0_SE3_Deadline_CP1_C3);
	WdgM_CheckpointReached(WDGM_SE4_Deadline_C3,WdgM_SE4_Deadline_C3_Mode0_SE4_Deadline_CP1_C3);
    
	WdgM_CheckpointReached(WDGM_SE0_Deadline_C3,WdgM_SE0_Deadline_C3_Mode0_SE0_Deadline_CP2_C3);
    WdgM_CheckpointReached(WDGM_SE1_Deadline_C3,WdgM_SE1_Deadline_C3_Mode0_SE1_Deadline_CP2_C3);
	WdgM_CheckpointReached(WDGM_SE2_Deadline_C3,WdgM_SE2_Deadline_C3_Mode0_SE2_Deadline_CP2_C3);
	WdgM_CheckpointReached(WDGM_SE3_Deadline_C3,WdgM_SE3_Deadline_C3_Mode0_SE3_Deadline_CP2_C3);
	WdgM_CheckpointReached(WDGM_SE4_Deadline_C3,WdgM_SE4_Deadline_C3_Mode0_SE4_Deadline_CP2_C3);
    /*Deadline End*/

    /*ProgramFlow Start*/
    WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C3,WdgM_SE0_ProgramFlow_C3_Mode0_SE0_Logical_CP1_C3);
	WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C3,WdgM_SE0_ProgramFlow_C3_Mode0_SE0_Logical_CP2_C3);
    WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C3,WdgM_SE0_ProgramFlow_C3_Mode0_SE0_Logical_CP3_C3);
	WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C3,WdgM_SE0_ProgramFlow_C3_Mode0_SE0_Logical_CP4_C3);
    WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C3,WdgM_SE0_ProgramFlow_C3_Mode0_SE0_Logical_CP5_C3);
	WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C3,WdgM_SE0_ProgramFlow_C3_Mode0_SE0_Logical_CP6_C3);
    /*ProgramFlow End*/
}

void Reserved_WdgM_Function_Core4(void)
{
    /*Alive Start*/
    WdgM_CheckpointReached(WDGM_SE0_AliveCounter_C4,WdgM_SE0_AliveCounter_C4_Mode0_SE0_Alive_CP_C4);
    WdgM_CheckpointReached(WDGM_SE1_AliveCounter_C4,WdgM_SE1_AliveCounter_C4_Mode0_SE1_Alive_CP_C4);
    WdgM_CheckpointReached(WDGM_SE2_AliveCounter_C4,WdgM_SE2_AliveCounter_C4_Mode0_SE2_Alive_CP_C4);
    WdgM_CheckpointReached(WDGM_SE3_AliveCounter_C4,WdgM_SE3_AliveCounter_C4_Mode0_SE3_Alive_CP_C4);
    WdgM_CheckpointReached(WDGM_SE4_AliveCounter_C4,WdgM_SE4_AliveCounter_C4_Mode0_SE4_Alive_CP_C4);
    /*Alive End*/

    /*Deadline Start*/
	WdgM_CheckpointReached(WDGM_SE0_Deadline_C4,WdgM_SE0_Deadline_C4_Mode0_SE0_Deadline_CP1_C4);
    WdgM_CheckpointReached(WDGM_SE1_Deadline_C4,WdgM_SE1_Deadline_C4_Mode0_SE1_Deadline_CP1_C4);
	WdgM_CheckpointReached(WDGM_SE2_Deadline_C4,WdgM_SE2_Deadline_C4_Mode0_SE2_Deadline_CP1_C4);
	WdgM_CheckpointReached(WDGM_SE3_Deadline_C4,WdgM_SE3_Deadline_C4_Mode0_SE3_Deadline_CP1_C4);
	WdgM_CheckpointReached(WDGM_SE4_Deadline_C4,WdgM_SE4_Deadline_C4_Mode0_SE4_Deadline_CP1_C4);
    
	WdgM_CheckpointReached(WDGM_SE0_Deadline_C4,WdgM_SE0_Deadline_C4_Mode0_SE0_Deadline_CP2_C4);
    WdgM_CheckpointReached(WDGM_SE1_Deadline_C4,WdgM_SE1_Deadline_C4_Mode0_SE1_Deadline_CP2_C4);
	WdgM_CheckpointReached(WDGM_SE2_Deadline_C4,WdgM_SE2_Deadline_C4_Mode0_SE2_Deadline_CP2_C4);
	WdgM_CheckpointReached(WDGM_SE3_Deadline_C4,WdgM_SE3_Deadline_C4_Mode0_SE3_Deadline_CP2_C4);
	WdgM_CheckpointReached(WDGM_SE4_Deadline_C4,WdgM_SE4_Deadline_C4_Mode0_SE4_Deadline_CP2_C4);
    /*Deadline End*/

    /*ProgramFlow Start*/
    WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C4,WdgM_SE0_ProgramFlow_C4_Mode0_SE0_Logical_CP1_C4);
	WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C4,WdgM_SE0_ProgramFlow_C4_Mode0_SE0_Logical_CP2_C4);
    WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C4,WdgM_SE0_ProgramFlow_C4_Mode0_SE0_Logical_CP3_C4);
	WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C4,WdgM_SE0_ProgramFlow_C4_Mode0_SE0_Logical_CP4_C4);
    WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C4,WdgM_SE0_ProgramFlow_C4_Mode0_SE0_Logical_CP5_C4);
	WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C4,WdgM_SE0_ProgramFlow_C4_Mode0_SE0_Logical_CP6_C4);
    /*ProgramFlow End*/
}

void Reserved_WdgM_Function_Core5(void)
{
    /*Alive Start*/
    WdgM_CheckpointReached(WDGM_SE0_AliveCounter_C5,WdgM_SE0_AliveCounter_C5_Mode0_SE0_Alive_CP_C5);
    WdgM_CheckpointReached(WDGM_SE1_AliveCounter_C5,WdgM_SE1_AliveCounter_C5_Mode0_SE1_Alive_CP_C5);
    WdgM_CheckpointReached(WDGM_SE2_AliveCounter_C5,WdgM_SE2_AliveCounter_C5_Mode0_SE2_Alive_CP_C5);
    WdgM_CheckpointReached(WDGM_SE3_AliveCounter_C5,WdgM_SE3_AliveCounter_C5_Mode0_SE3_Alive_CP_C5);
    WdgM_CheckpointReached(WDGM_SE4_AliveCounter_C5,WdgM_SE4_AliveCounter_C5_Mode0_SE4_Alive_CP_C5);
    /*Alive End*/

    /*Deadline Start*/
	WdgM_CheckpointReached(WDGM_SE0_Deadline_C5,WdgM_SE0_Deadline_C5_Mode0_SE0_Deadline_CP1_C5);
    WdgM_CheckpointReached(WDGM_SE1_Deadline_C5,WdgM_SE1_Deadline_C5_Mode0_SE1_Deadline_CP1_C5);
	WdgM_CheckpointReached(WDGM_SE2_Deadline_C5,WdgM_SE2_Deadline_C5_Mode0_SE2_Deadline_CP1_C5);
	WdgM_CheckpointReached(WDGM_SE3_Deadline_C5,WdgM_SE3_Deadline_C5_Mode0_SE3_Deadline_CP1_C5);
	WdgM_CheckpointReached(WDGM_SE4_Deadline_C5,WdgM_SE4_Deadline_C5_Mode0_SE4_Deadline_CP1_C5);
    
	WdgM_CheckpointReached(WDGM_SE0_Deadline_C5,WdgM_SE0_Deadline_C5_Mode0_SE0_Deadline_CP2_C5);
    WdgM_CheckpointReached(WDGM_SE1_Deadline_C5,WdgM_SE1_Deadline_C5_Mode0_SE1_Deadline_CP2_C5);
	WdgM_CheckpointReached(WDGM_SE2_Deadline_C5,WdgM_SE2_Deadline_C5_Mode0_SE2_Deadline_CP2_C5);
	WdgM_CheckpointReached(WDGM_SE3_Deadline_C5,WdgM_SE3_Deadline_C5_Mode0_SE3_Deadline_CP2_C5);
	WdgM_CheckpointReached(WDGM_SE4_Deadline_C5,WdgM_SE4_Deadline_C5_Mode0_SE4_Deadline_CP2_C5);
    /*Deadline End*/

    /*ProgramFlow Start*/
    WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C5,WdgM_SE0_ProgramFlow_C5_Mode0_SE0_Logical_CP1_C5);
	WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C5,WdgM_SE0_ProgramFlow_C5_Mode0_SE0_Logical_CP2_C5);
    WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C5,WdgM_SE0_ProgramFlow_C5_Mode0_SE0_Logical_CP3_C5);
	WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C5,WdgM_SE0_ProgramFlow_C5_Mode0_SE0_Logical_CP4_C5);
    WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C5,WdgM_SE0_ProgramFlow_C5_Mode0_SE0_Logical_CP5_C5);
	WdgM_CheckpointReached(WDGM_SE0_ProgramFlow_C5,WdgM_SE0_ProgramFlow_C5_Mode0_SE0_Logical_CP6_C5);
    /*ProgramFlow End*/
}
