#include "Std_Types.h"
#include "CanBus_Configuration.h"
#include "ErrorDiag_CAN.h"
#include "CAN_NM_Userdata_fill.h"

#include "Com_Lcfg.h"
#include "Com.h"
#include "CanNm_Cfg.h"
#include "Interface_Test_IO.h"
#include "BMS_User.h"

uint8 BSW_MAJOR_VERSION = BSW_RELEASE_MAJOR_VERSION;
uint8 BSW_MINOR_VERSION = BSW_RELEASE_MINOR_VERSION;
uint8 BSW_TEST_VERSION  = BSW_RELEASE_TEST_VERSION;

//唤醒请求发送 测试报文
// uint8 PMS_WakeUpReq = 0;
// uint8 BMS_WakeUpReq = 0;
// extern uint8 Ea_ShutdownReq;
// extern uint8 PMS_EcuCtrl_SetShutDownReq;
//下电写EEprom等待时间发送 测试报文
// extern uint16 XCU_WaitPoweroffCounter;
// uint8 Send_Data[2] = {0x00, 0x00};
FUNC(void, RTE_CODE) Core4_Runnable_Task_Init(void)
{

}

FUNC(void, RTE_CODE) Core4_Runnable_App_1ms(void)
{
	#ifdef VCU_Test_Code_YXP
	// Test_SetIO_Status_LS12(0);
	#endif
}

FUNC(void, RTE_CODE) Core4_Runnable_App_5ms(void)
{

}

FUNC(void, RTE_CODE) Core4_Runnable_App_10ms(void)
{
	CAN_MsgActive_Update();

	Can_CANFaultPeriodDiag();

	BMS_COM_RelaySwitch();
	
	//NM 测试报文
	// Com_SendSignal(COMCONF_COMSIGNAL_TESTOUTPUT1_GTPS3U_TESTDATA_200_0_TESTOUTPUT1_XCP_AND_TEST_CAN_DBC_TX, &CanNm_NmState[0]);
	// Com_SendSignal(COMCONF_COMSIGNAL_TESTOUTPUT1_GTPS3U_TESTDATA_200_1_TESTOUTPUT1_XCP_AND_TEST_CAN_DBC_TX, &CanNm_NmState[1]);

	//唤醒请求发送 测试报文
	// PMS_WakeUpReq = (!PMS_EcuCtrl_SetShutDownReq) == 1U;
	// BMS_WakeUpReq = Ea_ShutdownReq != 2U;
	// Com_SendSignal(COMCONF_COMSIGNAL_TESTOUTPUT1_GTPS3U_TESTDATA_200_2_TESTOUTPUT1_XCP_AND_TEST_CAN_DBC_TX, &PMS_WakeUpReq);
	// Com_SendSignal(COMCONF_COMSIGNAL_TESTOUTPUT1_GTPS3U_TESTDATA_200_3_TESTOUTPUT1_XCP_AND_TEST_CAN_DBC_TX, &BMS_WakeUpReq);

	//下电EEprom写入等待时间发送 测试报文
	// Send_Data[1] = (uint8)(XCU_WaitPoweroffCounter & 0x00FF);
	// Send_Data[0] = (uint8)((XCU_WaitPoweroffCounter >> 8) & 0x00FF);
	// Com_SendSignal(COMCONF_COMSIGNAL_TESTOUTPUT1_GTPS3U_TESTDATA_200_4_TESTOUTPUT1_XCP_AND_TEST_CAN_DBC_TX, &Send_Data[0]);
	// Com_SendSignal(COMCONF_COMSIGNAL_TESTOUTPUT1_GTPS3U_TESTDATA_200_5_TESTOUTPUT1_XCP_AND_TEST_CAN_DBC_TX, &Send_Data[1]);
	
	//Boot 刷写测试 测试报文
	// uint8 BootFlashTest_Local = 0x50;
	// Com_SendSignal(COMCONF_COMSIGNAL_TESTOUTPUT6_GTPS3U_TESTDATA_205_3_TESTOUTPUT6_XCP_AND_TEST_CAN_DBC_TX, &BootFlashTest_Local);

	//版本号发送
	Com_SendSignal(COMCONF_COMSIGNAL_TESTOUTPUT6_GTPS3U_TESTDATA_205_0_TESTOUTPUT6_XCP_AND_TEST_CAN_DBC_TX, &BSW_MAJOR_VERSION);
	Com_SendSignal(COMCONF_COMSIGNAL_TESTOUTPUT6_GTPS3U_TESTDATA_205_1_TESTOUTPUT6_XCP_AND_TEST_CAN_DBC_TX, &BSW_MINOR_VERSION);
	Com_SendSignal(COMCONF_COMSIGNAL_TESTOUTPUT6_GTPS3U_TESTDATA_205_2_TESTOUTPUT6_XCP_AND_TEST_CAN_DBC_TX, &BSW_TEST_VERSION);

	
}

FUNC(void, RTE_CODE) Core4_Runnable_App_20ms(void)
{

}

FUNC(void, RTE_CODE) Core4_Runnable_App_50ms(void)
{

}

FUNC(void, RTE_CODE) Core4_Runnable_App_100ms(void)
{

}
