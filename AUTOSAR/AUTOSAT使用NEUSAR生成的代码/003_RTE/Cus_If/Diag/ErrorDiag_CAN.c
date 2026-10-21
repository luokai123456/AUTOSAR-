#include "ErrorDiag_CAN.h"
#include "CanBus_Configuration.h"
#include "Can_Device_Prv.h"
#include "Can_Interface.h"
#include "CanIf_Lcfg.h"
#include "CanSM.h"
#include "BswM_Cfg.h"
#include "BswM.h"

uint8 CANIF_PTCANNodeNum=5;
uint16 CANIF_CANNodeNum=0;

extern uint16 XCU_ChargeOnVltg;
extern uint16 XCU_KeyOnVltg;
extern uint16 XCU_KL30Vltg;
extern uint16 CAN_MsgActive_UpdateCounter;

uint8 CANA_stBusoff_LO = 0;
uint8 CANB_stBusoff_LO = 0;
uint8 CAND_stBusoff_LO = 0;

uint8 CANA_stBusoffQuickCouter = 0 ;
uint8 CANB_stBusoffQuickCouter = 0 ;
uint8 CAND_stBusoffQuickCouter = 0 ;
uint8 CANA_stBusoffCouter = 0 ;
uint8 CANB_stBusoffCouter = 0 ;
uint8 CAND_stBusoffCouter = 0 ;
uint8 CANA_stBusoffRecoverCouter = 0 ;
uint8 CANB_stBusoffRecoverCouter = 0 ;
uint8 CAND_stBusoffRecoverCouter = 0 ;
uint8 CANA_stBusoffRecoeryPeriod = 9 ;
uint8 CANB_stBusoffRecoeryPeriod = 9 ;
uint8 CAND_stBusoffRecoeryPeriod = 9 ;

boolean CANA_stBusoffFlg = 0 ;
boolean CANB_stBusoffFlg = 0 ;
boolean CAND_stBusoffFlg = 0 ;


boolean Can_DiagVltgCondFlg = 0 ;
boolean Can_DiagVltgLowErrFlg = 0 ;
boolean Can_DiagVltgHighErrFlg = 0 ;
uint16 Can_DiagVltgLowErrRecoeryCounter = 0 ;
uint16 Can_DiagVltgHighErrRecoeryCounter = 0 ;

boolean Can_KL30VltgLowErrFlg = 0 ;
boolean Can_KL30VltgHighErrFlg = 0 ;
uint16 Can_KL30VltgLowErrRecoeryCounter = 0 ;
uint16 Can_KL30VltgHighErrRecoeryCounter = 0 ;

boolean Can_DiagCondKeyOn = 0;
boolean Can_DiagCondKeyOn3500ms = 0;
boolean Can_DiagCondChargeOn = 0;
boolean Can_DiagCondCANDNoBusoff = 0;
boolean Can_DiagCondCANBNoBusoff = 0;
boolean Can_DiagCondCANANoBusoff = 0;
uint16 KeyOnKeepCounter = 0;
uint16 CANA_BusoffRecoveryCounter = 100;
uint16 CANB_BusoffRecoveryCounter = 100;
uint16 CAND_BusoffRecoveryCounter = 100;

uint16 Can_MsgTimeOut_DiagCounter = 0;
uint8 CAND_0x125_TimeOutCounter = 0;
boolean CAND_0x125_TimeOut = 0;
uint8 CAND_0x128_TimeOutCounter = 0;
boolean CAND_0x128_TimeOut = 0;
uint8 CAND_0x129_TimeOutCounter = 0;
boolean CAND_0x129_TimeOut = 0;
uint8 CANA_0x398_TimeOutCounter = 0;
boolean CANA_0x398_TimeOut = 0;
uint8 CANA_0x145_TimeOutCounter = 0;
boolean CANA_0x145_TimeOut = 0;
uint8 CAND_0x380_TimeOutCounter = 0;
boolean CAND_0x380_TimeOut = 0;
uint8 CANG_0x122_TimeOutCounter = 0;
boolean CANG_0x122_TimeOut = 0;
uint8 CANG_0x128_TimeOutCounter = 0;
boolean CANG_0x128_TimeOut = 0;
uint8 CANB_0x3CA_TimeOutCounter = 0;
boolean CANB_0x3CA_TimeOut = 0;
uint8 CANA_0x220_TimeOutCounter = 0;
boolean CANA_0x220_TimeOut = 0;
uint8 CANB_0x247_TimeOutCounter = 0;
boolean CANB_0x247_TimeOut = 0;
uint8 CANB_0x1E2_TimeOutCounter = 0;
boolean CANB_0x1E2_TimeOut = 0;

uint8 CANA_BusoffRecoveryLevel=0;
uint8 CANB_BusoffRecoveryLevel=0;
uint8 CAND_BusoffRecoveryLevel=0;

boolean PMS_EHB_communication_lost=0;
boolean PMS_DCDC_communication_lost=0;
boolean PMS_EGSM_communication_lost=0;
boolean PMS_MotorSpeed_communication_lost=0;
boolean PMS_Speed_communication_lost=0;
boolean PMS_PEPS_communication_lost=0;
boolean PMS_ACU_communication_lost=0;
boolean PMS_CSM_communication_lost=0;
boolean PMS_BBM_communication_lost=0;
boolean PMS_PEPS_DataInvalidErr=0;
boolean PMS_PDC_DataInvalidErr=0;
uint8 CAND_0x380_CheckSumArray[8]={0};
uint8 CANB_0x3CA_CheckSumArray[8]={0};
uint8 CANB_0x1E2_CheckSumArray[8]={0};
uint8 CANA_0x145_CheckSumArray[8]={0};
uint8 CAND_0x125_CheckSumArray[8]={0};
uint8 CAND_0x2CF_CheckSumArray[8]={0};

uint8 CANA_0x220_CheckSumArray[8]={0};
uint8 CANA_0x157_CheckSumArray[8]={0};
uint8 CAND_0x126_CheckSumArray[8]={0};
uint8 CAND_0x122_CheckSumArray[8]={0};
uint8 CAND_0x1F9_CheckSumArray[8]={0};
uint8 CAND_0x129_CheckSumArray[8]={0};
uint8 CAND_0x123_CheckSumArray[8]={0};
uint8 CAND_0x128_CheckSumArray[8]={0};
uint8 CAND_0x121_CheckSumArray[8]={0};
uint8 CAND_0x124_CheckSumArray[8]={0};
uint8 CAND_0x0E0_CheckSumArray[8]={0};
uint8 CAND_0x130_CheckSumArray[8]={0};
uint8 CAND_0x131_CheckSumArray[8]={0};
uint8 CANG_0x122_CheckSumArray[8]={0};
uint8 CANG_0x128_CheckSumArray[8]={0};
uint8 CANG_0x124_CheckSumArray[8]={0};
uint8 CANG_0x120_CheckSumArray[8]={0};

boolean CANA_0x220_CheckSumErr  = 0;
boolean CANA_0x157_CheckSumErr  = 0;
boolean CAND_0x126_CheckSumErr  = 0;
boolean CAND_0x122_CheckSumErr  = 0;
boolean CAND_0x1F9_CheckSumErr  = 0;
boolean CAND_0x129_CheckSumErr  = 0;
boolean CAND_0x123_CheckSumErr  = 0;
boolean CAND_0x128_CheckSumErr  = 0;
boolean CAND_0x121_CheckSumErr  = 0;
boolean CAND_0x124_CheckSumErr  = 0;
boolean CAND_0x0E0_CheckSumErr  = 0;
boolean CAND_0x130_CheckSumErr  = 0;
boolean CAND_0x131_CheckSumErr  = 0;
boolean CANG_0x122_CheckSumErr  = 0;
boolean CANG_0x128_CheckSumErr  = 0;
boolean CANG_0x124_CheckSumErr  = 0;
boolean CANG_0x120_CheckSumErr  = 0;


uint16 Can_MsgAliveCnt_DiagCounter = 0;
uint16 Can_MsgCheckSum_DiagCounter = 0;

boolean CAND_0x380_AliveCntErr  = 0;
boolean CAND_0x380_CheckSumErr  = 0;

boolean CANB_0x3CA_AliveCntErr  = 0;
boolean CANB_0x3CA_CheckSumErr  = 0;

boolean CANB_0x1E2_AliveCntErr  = 0;
boolean CANB_0x1E2_CheckSumErr  = 0;

boolean CANA_0x145_AliveCntErr  = 0;
boolean CANA_0x145_CheckSumErr  = 0;

boolean CAND_0x125_AliveCntErr  = 0;
boolean CAND_0x125_CheckSumErr  = 0;

boolean CAND_0x2CF_AliveCntErr  = 0;
boolean CAND_0x2CF_CheckSumErr = 0;

uint8 CANB_0x1E2_AliveCntTemp = 0;
uint8 CANA_0x145_AliveCntTemp = 0;
uint8 CAND_0x125_AliveCntTemp = 0;
uint8 CAND_0x2CF_AliveCntTemp = 0;
uint8 CAND_0x380_AliveCntTemp = 0;
uint8 CANB_0x3CA_AliveCntTemp = 0;



static AliveCnt_StateType alive_state_list[] =
{
    {0x380, CAN_CH_D, 0xFF, 0, &CAND_0x380_AliveCntErr},
    {0x3CA, CAN_CH_B, 0xFF, 0, &CANB_0x3CA_AliveCntErr},
    {0x1E2, CAN_CH_B, 0xFF, 0, &CANB_0x1E2_AliveCntErr},
    {0x145, CAN_CH_A, 0xFF, 0, &CANA_0x145_AliveCntErr},
    {0x125, CAN_CH_D, 0xFF, 0, &CAND_0x125_AliveCntErr},
    {0x2CF, CAN_CH_D, 0xFF, 0, &CAND_0x2CF_AliveCntErr},
};

static CANErrDiag_StateType CANErr_state_list[] =
{
	{1,0,0,0,25,0,&PMS_EHB_communication_lost},
	{2,0,0,0,1,0,&PMS_DCDC_communication_lost},
	{3,0,0,0,25,0,&PMS_EGSM_communication_lost},
	{4,0,0,0,25,0,&PMS_MotorSpeed_communication_lost},//NO DTC
	{5,0,0,0,25,0,&PMS_Speed_communication_lost},
	{6,0,0,0,25,0,&PMS_PEPS_communication_lost},//NO DTC
	{7,0,0,0,1,0,&PMS_ACU_communication_lost},
	{8,0,0,0,1,0,&PMS_CSM_communication_lost},
	{9,0,0,0,25,0,&PMS_PEPS_DataInvalidErr},
	{10,0,0,0,25,0,&PMS_BBM_communication_lost},//NO DTC
	{11,0,0,0,25,0,&PMS_PDC_DataInvalidErr},//NO DTC
};

/* 需要追加CheckSum的所有Tx PDU ID，批量统一管理 */
static const uint16 CheckSumNeedPduIdList[] =
{
    0x26B,
	0x215,
	0x0B9,
	0x0BA,
	0x151,
//	0x123,
//	0x125,
	0x171,
	0x0A8,
	0x0AA,
	0x0A0,
	0x162,
	0x165,
	0x169,
	0x16B,
//	0x0E0,
//	0x145,
	0x0A8,
	0x0AA,
	0x1A5,
	0x0A6,
	0x162,
	0x1A4,
	0x165,
	0x26B,
	0x17A,
	0x217,
	0x215,
	0x178,
	0x0BA,
//	0x145,
	0x0A8,
//	0x220,
	0x0AA,
	0x0A0,
	0x1A5,
	0x0A6,
	0x162,
	0x1A4,
	0x165,
	0x169,
	0x16B,
	0x126,
	0x12A,
};

#define CHECKSUM_PDU_NUM (sizeof(CheckSumNeedPduIdList)/sizeof(CheckSumNeedPduIdList[0]))

#define ALIVE_STATE_COUNT (sizeof(alive_state_list) / sizeof(alive_state_list[0]))
#define CANErr_STATE_COUNT (sizeof(CANErr_state_list) / sizeof(CANErr_state_list[0]))

void Can_CANFaultPeriodDiag(void)
{
	Can_DiagCondCal();
	Can_DiagVltgCondCal();
	Can_KL30VltgCondCal();

	if(Can_DiagVltgCondFlg==1U&&((Can_DiagCondKeyOn==1U)||(Can_DiagCondChargeOn==1U)))
	{
		Can_BusOffDiag();
	}
	else
	{
		CANA_stBusoffQuickCouter = 0 ;
		CANB_stBusoffQuickCouter = 0 ;
		CAND_stBusoffQuickCouter = 0 ;
		CANA_stBusoffCouter = 0 ;
		CANB_stBusoffCouter = 0 ;
		CAND_stBusoffCouter = 0 ;
		CANA_stBusoffRecoverCouter = 0 ;
		CANB_stBusoffRecoverCouter = 0 ;
		CAND_stBusoffRecoverCouter = 0 ;
		CANA_stBusoffRecoeryPeriod = 9 ;
		CANB_stBusoffRecoeryPeriod = 9 ;
		CAND_stBusoffRecoeryPeriod = 9 ;
	}

	if((Can_DiagVltgCondFlg==1U)&&((Can_DiagCondKeyOn3500ms==1U)||(Can_DiagCondChargeOn==1U)))
	{
		Can_MsgTimeOutDiag();
		Can_AliveCounterErrDiag();
		Can_CheckSumErrDiag();
	}
	else
	{
		Can_MsgTimeOut_DiagCounter = 0;
		CAND_0x125_TimeOutCounter = 0;
		CAND_0x128_TimeOutCounter = 0;
		CAND_0x129_TimeOutCounter = 0;
		CANA_0x398_TimeOutCounter = 0;
		CANA_0x145_TimeOutCounter = 0;
		CAND_0x380_TimeOutCounter = 0;
		CANG_0x122_TimeOutCounter = 0;
		CANG_0x128_TimeOutCounter = 0;
		CANB_0x3CA_TimeOutCounter = 0;
		alive_state_list[0].same_count = 0;
		alive_state_list[1].same_count = 0;
		alive_state_list[2].same_count = 0;
		alive_state_list[3].same_count = 0;
		alive_state_list[4].same_count = 0;
		alive_state_list[5].same_count = 0;
	}

	Can_ComLostDiag();

	DiagErr_SetEventStatus();
}

void Can_DiagVltgCondCal(void)
{

	//诊断欠压
	if(XCU_KL30Vltg < 9000U)
	{
		Can_DiagVltgLowErrFlg = 1;				//诊断低压故障标志位
		Can_DiagVltgLowErrRecoeryCounter = 0;	//诊断低压故障恢复计数
		Can_DiagVltgHighErrFlg = 0;				//诊断清除高压标志位
		Can_DiagVltgHighErrRecoeryCounter = 0;	//诊断清除高压故障恢复计数
	}
	else if(XCU_KL30Vltg > 10000U)
	{
		if(Can_DiagVltgLowErrFlg == 1U)
		{
			if(Can_DiagVltgLowErrRecoeryCounter >= 350U)
			{
				Can_DiagVltgLowErrRecoeryCounter = 0;
				Can_DiagVltgLowErrFlg = 0;
			}
			else
			{
				Can_DiagVltgLowErrRecoeryCounter++;
			}
		}
	}
	else
	{

	}

	//诊断过压
	if(XCU_KL30Vltg > 16000U)
	{
		Can_DiagVltgHighErrFlg = 1;				//高压故障标志位
		Can_DiagVltgHighErrRecoeryCounter = 0;	//高压故障恢复计数

		Can_DiagVltgLowErrFlg = 0;				//清除低压故障标志位
		Can_DiagVltgLowErrRecoeryCounter = 0;	//清除低压故障恢复计数
	}
	else if(XCU_KL30Vltg < 15000U)
	{
		if(Can_DiagVltgHighErrFlg == 1U)
		{
			if(Can_DiagVltgHighErrRecoeryCounter >= 350U)
			{
				Can_DiagVltgHighErrRecoeryCounter = 0;
				Can_DiagVltgHighErrFlg = 0;			
			}
			else
			{
				Can_DiagVltgHighErrRecoeryCounter++;
			}
		}
	}
	else
	{

	}

	//是否开启诊断功能
	if((Can_DiagVltgLowErrFlg == 1)||(Can_DiagVltgHighErrFlg == 1))
	{
		Can_DiagVltgCondFlg = 0;	//关闭诊断功能
	}
	else
	{
		Can_DiagVltgCondFlg = 1;	//打开诊断功能
	}
}

void Can_KL30VltgCondCal(void)
{

	//欠压
	if(XCU_KL30Vltg < 6300U)
	{
		Can_KL30VltgLowErrFlg = 1;				//低压故障标志位
		Can_KL30VltgLowErrRecoeryCounter = 0;	//低压故障恢复计数
		Can_KL30VltgHighErrFlg = 0;				//清除高压标志位
		Can_KL30VltgHighErrRecoeryCounter = 0;	//清除高压故障恢复计数
	}
	else if(XCU_KL30Vltg > 6500U)
	{
		if(Can_KL30VltgLowErrFlg == 1U)
		{
			if(Can_KL30VltgLowErrRecoeryCounter >= 3U)
			{
				Can_KL30VltgLowErrRecoeryCounter = 0;
				Can_KL30VltgLowErrFlg = 0;
			}
			else
			{
				Can_KL30VltgLowErrRecoeryCounter++;
			}
		}
	}
	else
	{

	}

	//过压
	if(XCU_KL30Vltg > 18300U)
	{
		Can_KL30VltgHighErrFlg = 1;				//高压故障标志位
		Can_KL30VltgHighErrRecoeryCounter = 0;	//高压故障恢复计数

		Can_KL30VltgLowErrFlg = 0;				//清除低压故障标志位
		Can_KL30VltgLowErrRecoeryCounter = 0;	//清除低压故障恢复计数
	}
	else if(XCU_KL30Vltg < 18000U)
	{
		if(Can_KL30VltgHighErrFlg == 1U)
		{
			if(Can_KL30VltgHighErrRecoeryCounter >= 3U)
			{
				Can_KL30VltgHighErrRecoeryCounter = 0;
				Can_KL30VltgHighErrFlg = 0;			
			}
			else
			{
				Can_KL30VltgHighErrRecoeryCounter++;
			}
		}
	}
	else
	{

	}

	//蓄电池状态BSWM请求
	if(Can_KL30VltgLowErrFlg == 1U)//欠压
	{
		BswM_RequestMode(BSWM_GENERIC_RP_ValtState,BSWM_GENERICVALUE_Cond_StatelsValtLow);
	}
	else if(Can_KL30VltgHighErrFlg == 1U)//过压
	{
		BswM_RequestMode(BSWM_GENERIC_RP_ValtState,BSWM_GENERICVALUE_Cond_StatelsValtHigh);
	}
	else//正常
	{
		BswM_RequestMode(BSWM_GENERIC_RP_ValtState,BSWM_GENERICVALUE_Cond_StatelsValtNom);
	}
}

void Can_BusOffDiag(void)
{

	CanSM_GetBusOffRecoveryLevel(2U,&CANA_BusoffRecoveryLevel);
	CanSM_GetBusOffRecoveryLevel(6U,&CANB_BusoffRecoveryLevel);
	CanSM_GetBusOffRecoveryLevel(5U,&CAND_BusoffRecoveryLevel);

	if(CANA_BusoffRecoveryLevel!=0U)
	{
		CANA_stBusoffFlg=1;
	}
	else
	{
		CANA_stBusoffFlg=0;
	}

	if(CANB_BusoffRecoveryLevel!=0U)
	{
		CANB_stBusoffFlg=1;
	}
	else
	{
		CANB_stBusoffFlg=0;
	}

	if(CAND_BusoffRecoveryLevel!=0U)
	{
		CAND_stBusoffFlg=1;
	}
	else
	{
		CAND_stBusoffFlg=0;
	}

}

void Can_MsgTimeOutDiag(void)
{
	// if(Can_MsgTimeOut_DiagCounter<1001U)
	// {
	// 	Can_MsgTimeOut_DiagCounter++;
	// }	
	// else
	// {
	// 	Can_MsgTimeOut_DiagCounter=1;
	// }
	Can_MsgTimeOut_DiagCounter= CAN_MsgActive_UpdateCounter;
	
	if((Can_MsgTimeOut_DiagCounter%1U)==0U)
	{
		if(CANG_0x122_Active==1U)
		{
			CANG_0x122_TimeOutCounter=0;
			CANG_0x122_TimeOut=0;
		}
		else if(CANG_0x122_TimeOutCounter>=4U)
		{
			CANG_0x122_TimeOutCounter=4;
			CANG_0x122_TimeOut=1;
		}
		else
		{
			CANG_0x122_TimeOutCounter++;
			
		}

		if(CANG_0x128_Active==1U)
		{
			CANG_0x128_TimeOutCounter=0;
			CANG_0x128_TimeOut=0;
		}
		else if(CANG_0x128_TimeOutCounter>=4U)
		{
			CANG_0x128_TimeOutCounter=4;
			CANG_0x128_TimeOut=1;
		}
		else
		{
			CANG_0x128_TimeOutCounter++;
			
		}
	}

	if(((Can_MsgTimeOut_DiagCounter%2U)==0U)&&(Can_DiagCondCANDNoBusoff==1U))
	{
		if(CAND_0x125_Active==1U)
		{
			CAND_0x125_TimeOutCounter=0;
			CAND_0x125_TimeOut=0;
		}
		else if(CAND_0x125_TimeOutCounter>=4U)
		{
			CAND_0x125_TimeOutCounter=4;
			CAND_0x125_TimeOut=1;
		}
		else
		{
			CAND_0x125_TimeOutCounter++;
			
		}
		
		if(CAND_0x128_Active==1U)
		{
			CAND_0x128_TimeOutCounter=0;
			CAND_0x128_TimeOut=0;
		}
		else if(CAND_0x128_TimeOutCounter>=4U)
		{
			CAND_0x128_TimeOutCounter=4;
			CAND_0x128_TimeOut=1;
		}
		else
		{
			CAND_0x128_TimeOutCounter++;
			
		}
		
		if(CAND_0x129_Active==1U)
		{
			CAND_0x129_TimeOutCounter=0;
			CAND_0x129_TimeOut=0;
		}
		else if(CAND_0x129_TimeOutCounter>=4U)
		{
			CAND_0x129_TimeOutCounter=4;
			CAND_0x129_TimeOut=1;
		}
		else
		{
			CAND_0x129_TimeOutCounter++;

		}
	}

	if(((Can_MsgTimeOut_DiagCounter%2U)==0U)&&(Can_DiagCondCANANoBusoff==1U))
	{
		if(CANA_0x145_Active==1U)
		{
			CANA_0x145_TimeOutCounter=0;
			CANA_0x145_TimeOut=0;
		}
		else if(CANA_0x145_TimeOutCounter>=4U)
		{
			CANA_0x145_TimeOutCounter=4;
			CANA_0x145_TimeOut=1;
		}
		else
		{
			CANA_0x145_TimeOutCounter++;
			
		}
	}

	if(((Can_MsgTimeOut_DiagCounter%2U)==0U)&&(Can_DiagCondCANBNoBusoff==1U))
		{
			if(CANB_0x1E2_Active==1U)
			{
				CANB_0x1E2_TimeOutCounter=0;
				CANB_0x1E2_TimeOut=0;
			}
			else if(CANB_0x1E2_TimeOutCounter>=4U)
			{
				CANB_0x1E2_TimeOutCounter=4;
				CANB_0x1E2_TimeOut=1;
			}
			else
			{
				CANB_0x1E2_TimeOutCounter++;
				
			}
		}

	if(((Can_MsgTimeOut_DiagCounter%10U)==0U)&&(Can_DiagCondCANANoBusoff==1U))
	{
		if(CANA_0x398_Active==1U)
		{
			CANA_0x398_TimeOutCounter=0;
			CANA_0x398_TimeOut=0;
		}
		else if(CANA_0x398_TimeOutCounter>=4U)
		{
			CANA_0x398_TimeOutCounter=4;
			CANA_0x398_TimeOut=1;
		}
		else
		{
			CANA_0x398_TimeOutCounter++;
			
		}

		if(CANA_0x220_Active==1U)
		{
			CANA_0x220_TimeOutCounter=0;
			CANA_0x220_TimeOut=0;
		}
		else if(CANA_0x220_TimeOutCounter>=4U)
		{
			CANA_0x220_TimeOutCounter=4;
			CANA_0x220_TimeOut=1;
		}
		else
		{
			CANA_0x220_TimeOutCounter++;
			
		}
	}
	if(((Can_MsgTimeOut_DiagCounter%10U)==0U)&&(Can_DiagCondCANBNoBusoff==1U))
	{
		if(CANB_0x3CA_Active==1U)
		{
			CANB_0x3CA_TimeOutCounter=0;
			CANB_0x3CA_TimeOut=0;
		}
		else if(CANB_0x3CA_TimeOutCounter>=4U)
		{
			CANB_0x3CA_TimeOutCounter=4;
			CANB_0x3CA_TimeOut=1;
		}
		else
		{
			CANB_0x3CA_TimeOutCounter++;
			
		}

		if(CANB_0x247_Active==1U)
		{
			CANB_0x247_TimeOutCounter=0;
			CANB_0x247_TimeOut=0;
		}
		else if(CANB_0x247_TimeOutCounter>=4U)
		{
			CANB_0x247_TimeOutCounter=4;
			CANB_0x247_TimeOut=1;
		}
		else
		{
			CANB_0x247_TimeOutCounter++;
			
		}
	}

	if(((Can_MsgTimeOut_DiagCounter%20U)==0U)&&(Can_DiagCondCANDNoBusoff==1U))
	{
		if(CAND_0x380_Active==1U)
		{
			CAND_0x380_TimeOutCounter=0;
			CAND_0x380_TimeOut=0;
		}
		else if(CAND_0x380_TimeOutCounter>=4U)
		{
			CAND_0x380_TimeOutCounter=4;
			CAND_0x380_TimeOut=1;
		}
		else
		{
			CAND_0x380_TimeOutCounter++;
			
		}
	}
}
void Can_DiagCondCal(void)
{
	
	if(XCU_KeyOnVltg>9000U)
	{
		Can_DiagCondKeyOn=1;
		KeyOnKeepCounter++;
	}
	else
	{
		Can_DiagCondKeyOn=0;
		KeyOnKeepCounter=0;
	}

	if(KeyOnKeepCounter>=350U)
	{
		Can_DiagCondKeyOn3500ms=1;
		KeyOnKeepCounter=350;
	}
	else
	{
		Can_DiagCondKeyOn3500ms=0;
	}

	if(XCU_ChargeOnVltg>9000U)
	{
		Can_DiagCondChargeOn=1;
	}
	else
	{
		Can_DiagCondChargeOn=0;
	}

	if(CANA_stBusoffFlg==1U)
	{
		CANA_BusoffRecoveryCounter=0;
		Can_DiagCondCANANoBusoff=0;
	}
	else if(CANA_BusoffRecoveryCounter>=100U)
	{
		Can_DiagCondCANANoBusoff=1;
		CANA_BusoffRecoveryCounter=100;
	}
	else
	{
		CANA_BusoffRecoveryCounter++;
		Can_DiagCondCANANoBusoff=0;
	}

	if(CANB_stBusoffFlg==1U)
	{
		CANB_BusoffRecoveryCounter=0;
		Can_DiagCondCANBNoBusoff=0;
	}
	else if(CANB_BusoffRecoveryCounter>=100U)
	{
		Can_DiagCondCANBNoBusoff=1;
		CANB_BusoffRecoveryCounter=100;
	}
	else
	{
		CANB_BusoffRecoveryCounter++;
		Can_DiagCondCANBNoBusoff=0;
	}

	if(CAND_stBusoffFlg==1U)
	{
		CAND_BusoffRecoveryCounter=0;
		Can_DiagCondCANDNoBusoff=0;
	}
	else if(CAND_BusoffRecoveryCounter>=100U)
	{
		Can_DiagCondCANDNoBusoff=1;
		CAND_BusoffRecoveryCounter=100;
	}
	else
	{
		CAND_BusoffRecoveryCounter++;
		Can_DiagCondCANDNoBusoff=0;
	}
}

void Can_AliveCounterErrDiag(void)
{
	if(Can_MsgAliveCnt_DiagCounter<1001U)
	{
		Can_MsgAliveCnt_DiagCounter++;
	}
	else
	{
		Can_MsgAliveCnt_DiagCounter=1;
	}

	if(((Can_MsgAliveCnt_DiagCounter%2U)==0U)&&(CANA_stBusoffFlg==0U)&&(CANA_0x145_Active==1U))
	{
		CANA_0x145_AliveCntTemp=(CANA_0x145_CheckSumArray[6])&0xFU;
		CheckAliveCntErr(CAN_CH_A, 0x145, CANA_0x145_AliveCntTemp);
	}

	if(((Can_MsgAliveCnt_DiagCounter%2U)==0U)&&(CANB_stBusoffFlg==0U)&&(CANB_0x1E2_Active==1U))
	{
		CANB_0x1E2_AliveCntTemp=(CANB_0x1E2_CheckSumArray[6])&0xFU;
		CheckAliveCntErr(CAN_CH_B, 0x1E2, CANB_0x1E2_AliveCntTemp);
	}

	if(((Can_MsgAliveCnt_DiagCounter%2U)==0U)&&(CAND_stBusoffFlg==0U)&&(CAND_0x125_Active==1U))
	{
		CAND_0x125_AliveCntTemp=(CAND_0x125_CheckSumArray[6])&0xFU;
		CheckAliveCntErr(CAN_CH_D, 0x125, CAND_0x125_AliveCntTemp);
	}

	if(((Can_MsgAliveCnt_DiagCounter%10U)==0U)&&(CAND_stBusoffFlg==0U)&&(CAND_0x2CF_Active==1U))
	{
		CAND_0x2CF_AliveCntTemp=(CAND_0x2CF_CheckSumArray[6])&0xFU;
		CheckAliveCntErr(CAN_CH_D, 0x2CF, CAND_0x2CF_AliveCntTemp);
	}

	if(((Can_MsgAliveCnt_DiagCounter%10U)==0U)&&(CANB_stBusoffFlg==0U)&&(CANB_0x3CA_Active==1U))
	{
		CANB_0x3CA_AliveCntTemp=(CANB_0x3CA_CheckSumArray[6])&0xFU;
		CheckAliveCntErr(CAN_CH_B, 0x3CA, CANB_0x3CA_AliveCntTemp);
	}

	if(((Can_MsgAliveCnt_DiagCounter%20U)==0U)&&(CAND_stBusoffFlg==0U)&&(CAND_0x380_Active==1U))
	{
		CAND_0x380_AliveCntTemp=(CAND_0x380_CheckSumArray[6])&0xFU;
		CheckAliveCntErr(CAN_CH_D, 0x380, CAND_0x380_AliveCntTemp);
	}
}

void Can_CheckSumErrDiag(void)
{
	if(Can_MsgCheckSum_DiagCounter<1001U)
	{
		Can_MsgCheckSum_DiagCounter++;
	}
	else
	{
		Can_MsgCheckSum_DiagCounter=1;
	}

	if(((Can_MsgCheckSum_DiagCounter%2U)==0U)&&(CANA_stBusoffFlg==0U)&&(CANA_0x145_Active==1U))
	{
		CAN_CheckCRC8(CANA_0x145_CheckSumArray, 7, &CANA_0x145_CheckSumErr);
	}

	if(((Can_MsgCheckSum_DiagCounter%10U)==0U)&&(CANA_stBusoffFlg==0U)&&(CANA_0x220_Active==1U))
	{
		CAN_CheckCRC8(CANA_0x220_CheckSumArray, 7, &CANA_0x220_CheckSumErr);
	}

	if(((Can_MsgCheckSum_DiagCounter%2U)==0U)&&(CANA_stBusoffFlg==0U)&&(CANA_0x157_Active==1U))
	{
		CAN_CheckCRC8(CANA_0x157_CheckSumArray, 7, &CANA_0x157_CheckSumErr);
	}

	if(((Can_MsgCheckSum_DiagCounter%2U)==0U)&&(CANB_stBusoffFlg==0U)&&(CANB_0x1E2_Active==1U))
	{
		CAN_CheckCRC8(CANB_0x1E2_CheckSumArray, 7, &CANB_0x1E2_CheckSumErr);
	}

	if(((Can_MsgCheckSum_DiagCounter%2U)==0U)&&(CAND_stBusoffFlg==0U)&&(CAND_0x125_Active==1U))
	{
		CAN_CheckCRC8(CAND_0x125_CheckSumArray, 7, &CAND_0x125_CheckSumErr);
	}

	if(((Can_MsgCheckSum_DiagCounter%10U)==0U)&&(CAND_stBusoffFlg==0U)&&(CAND_0x2CF_Active==1U))
	{
		CAN_CheckCRC8(CAND_0x2CF_CheckSumArray, 7, &CAND_0x2CF_CheckSumErr);
	}

	if(((Can_MsgCheckSum_DiagCounter%2U)==0U)&&(CAND_stBusoffFlg==0U)&&(CAND_0x126_Active==1U))
	{
		CAN_CheckCRC8(CAND_0x126_CheckSumArray, 7, &CAND_0x126_CheckSumErr);
	}

	if(((Can_MsgCheckSum_DiagCounter%2U)==0U)&&(CAND_stBusoffFlg==0U)&&(CAND_0x122_Active==1U))
	{
		CAN_CheckCRC8(CAND_0x122_CheckSumArray, 7, &CAND_0x122_CheckSumErr);
	}

	if(((Can_MsgCheckSum_DiagCounter%2U)==0U)&&(CAND_stBusoffFlg==0U)&&(CAND_0x1F9_Active==1U))
	{
		CAN_CheckCRC8(CAND_0x1F9_CheckSumArray, 7, &CAND_0x1F9_CheckSumErr);
	}

	if(((Can_MsgCheckSum_DiagCounter%2U)==0U)&&(CAND_stBusoffFlg==0U)&&(CAND_0x129_Active==1U))
	{
		CAN_CheckCRC8(CAND_0x129_CheckSumArray, 7, &CAND_0x129_CheckSumErr);
	}

	if(((Can_MsgCheckSum_DiagCounter%2U)==0U)&&(CAND_stBusoffFlg==0U)&&(CAND_0x123_Active==1U))
	{
		CAN_CheckCRC8(CAND_0x123_CheckSumArray, 7, &CAND_0x123_CheckSumErr);
	}

	if(((Can_MsgCheckSum_DiagCounter%2U)==0U)&&(CAND_stBusoffFlg==0U)&&(CAND_0x128_Active==1U))
	{
		CAN_CheckCRC8(CAND_0x128_CheckSumArray, 7, &CAND_0x128_CheckSumErr);
	}

	if(((Can_MsgCheckSum_DiagCounter%2U)==0U)&&(CAND_stBusoffFlg==0U)&&(CAND_0x121_Active==1U))
	{
		CAN_CheckCRC8(CAND_0x121_CheckSumArray, 7, &CAND_0x121_CheckSumErr);
	}

	if(((Can_MsgCheckSum_DiagCounter%2U)==0U)&&(CAND_stBusoffFlg==0U)&&(CAND_0x124_Active==1U))
	{
		CAN_CheckCRC8(CAND_0x124_CheckSumArray, 7, &CAND_0x124_CheckSumErr);
	}

	if(((Can_MsgCheckSum_DiagCounter%2U)==0U)&&(CAND_stBusoffFlg==0U)&&(CAND_0x130_Active==1U))
	{
		CAN_CheckCRC8(CAND_0x130_CheckSumArray, 7, &CAND_0x130_CheckSumErr);
	}

	if(((Can_MsgCheckSum_DiagCounter%2U)==0U)&&(CAND_stBusoffFlg==0U)&&(CAND_0x131_Active==1U))
	{
		CAN_CheckCRC8(CAND_0x131_CheckSumArray, 7, &CAND_0x131_CheckSumErr);
	}

	if(((Can_MsgCheckSum_DiagCounter%10U)==0U)&&(CANB_stBusoffFlg==0U)&&(CANB_0x3CA_Active==1U))
	{
		CAN_CheckCRC8(CANB_0x3CA_CheckSumArray, 7, &CANB_0x3CA_CheckSumErr);
	}

	if(((Can_MsgCheckSum_DiagCounter%20U)==0U)&&(CAND_stBusoffFlg==0U)&&(CAND_0x380_Active==1U))
	{
		CAN_CheckCRC8(CAND_0x380_CheckSumArray, 7, &CAND_0x380_CheckSumErr);
	}

	if(((Can_MsgCheckSum_DiagCounter%1U)==0U)&&(CANG_0x122_Active==1U))
	{
		CAN_CheckCRC8(CANG_0x122_CheckSumArray, 7, &CANG_0x122_CheckSumErr);
	}

	if(((Can_MsgCheckSum_DiagCounter%1U)==0U)&&(CANG_0x128_Active==1U))
	{
		CAN_CheckCRC8(CANG_0x128_CheckSumArray, 7, &CANG_0x128_CheckSumErr);
	}

	if(((Can_MsgCheckSum_DiagCounter%1U)==0U)&&(CANG_0x124_Active==1U))
	{
		CAN_CheckCRC8(CANG_0x124_CheckSumArray, 7, &CANG_0x124_CheckSumErr);
	}

	if(((Can_MsgCheckSum_DiagCounter%1U)==0U)&&(CANG_0x120_Active==1U))
	{
		CAN_CheckCRC8(CANG_0x120_CheckSumArray, 7, &CANG_0x120_CheckSumErr);
	}
}
void Can_ComLostDiag(void)
{
	if((Can_DiagCondKeyOn==1U)||(Can_DiagCondChargeOn==1U))
	{
		CANErrDTC_Diag(1,((CAND_0x125_TimeOut==1U)||(CAND_0x128_TimeOut==1U)||(CAND_0x129_TimeOut==1U)));
	}
	else
	{
		CANErrDTC_Diag(1,0);
	}

	if(((Can_DiagCondKeyOn==1U)||(Can_DiagCondChargeOn==1U))&&(Can_DiagVltgCondFlg==1U)
			&&(Can_DiagCondCANBNoBusoff==1U)&&(Can_DiagCondCANANoBusoff==1U))
	{
		CANErrDTC_Diag(2,(CANA_0x398_TimeOut==1U));
	}
	else
	{
		CANErrDTC_Diag(2,0);
	}

	if(((Can_DiagCondKeyOn==1U))&&(Can_DiagVltgCondFlg==1U)
			&&(Can_DiagCondCANBNoBusoff==1U)&&(Can_DiagCondCANANoBusoff==1U))
	{
		CANErrDTC_Diag(3,((CANA_0x145_TimeOut==1U)||(CANA_0x145_AliveCntErr==1U)||(CANA_0x145_CheckSumErr==1U)));
		CANErrDTC_Diag(9,((CANB_0x1E2_TimeOut==1U)||(CANB_0x1E2_AliveCntErr==1U)||(CANB_0x1E2_CheckSumErr==1U)));
	}
	else
	{
		CANErrDTC_Diag(3,0);
		CANErrDTC_Diag(9,0);
	}

	if(((Can_DiagCondKeyOn==1U))&&(Can_DiagVltgCondFlg==1U)
			&&(Can_DiagCondCANDNoBusoff==1U)&&(Can_DiagCondCANANoBusoff==1U))
	{
		CANErrDTC_Diag(5,((CAND_0x125_TimeOut==1U)||(CAND_0x125_AliveCntErr==1U)||(CAND_0x125_CheckSumErr==1U)));
		CANErrDTC_Diag(7,((CAND_0x380_TimeOut==1U)||(CAND_0x380_CheckSumErr==1U)));
		CANErrDTC_Diag(8,((CANB_0x3CA_TimeOut==1U)||(CANB_0x3CA_CheckSumErr==1U)));
	}
	else
	{
		CANErrDTC_Diag(5,0);
		CANErrDTC_Diag(7,0);
		CANErrDTC_Diag(8,0);
	}
}

uint8 CalculateCRC8(const uint8 *data_byte_array)
{
    uint8 crc = 0xFF;
    const uint8 cb_CRC_POLY = 0x2F;
    const uint8 cb_DATA_BYTE_SIZE = 7;
    uint8 byte_index, bit_index;

    for(byte_index = 0; byte_index < cb_DATA_BYTE_SIZE; ++byte_index)
    {
        crc ^= data_byte_array[byte_index];

	for(bit_index = 0; bit_index < 8U; ++bit_index)
        {
            if((crc & 0x80) != 0)
            {
                crc = (crc << 1) ^ cb_CRC_POLY;
            }
            else
            {
                crc = crc << 1;
            }
        }
    }

    return ~crc;
}

void CheckAliveCntErr(CAN_ChannelType channel, uint32 id, uint8 input)
{
    uint8 i;
    AliveCnt_StateType *p_state = NULL;

    for(i = 0; i < ALIVE_STATE_COUNT; i++)
    {
        if((alive_state_list[i].channel == channel) && (alive_state_list[i].id == id))
        {
            p_state = &alive_state_list[i];
            break;
        }
    }

    if(p_state == NULL)
    {
        return;
    }
    *(p_state->alive_err_flag) = false;

    if(input == p_state->last_input)
    {
        if(p_state->same_count < 3U)
        {
            p_state->same_count++;
        }
        if(p_state->same_count >= 3U)
        {
            *(p_state->alive_err_flag) = true;
        }
    }
    else
    {
        p_state->same_count = 0;
        *(p_state->alive_err_flag) = false;
    }
    p_state->last_input = input;
}

void CAN_CheckCRC8(uint8 *pDataArray, uint8 DataLen, boolean *pCheckSumErr)
{
    uint8 i;
    uint8 CheckSumTemp = 0;
    uint8 CheckSumArrayTemp[8] = {0};

    for(i = 0; i < DataLen; i++)
    {
        CheckSumArrayTemp[i] = pDataArray[i];
    }

    CheckSumTemp = CalculateCRC8(CheckSumArrayTemp);

    if(CheckSumTemp == pDataArray[DataLen])
    {
        *pCheckSumErr = false;
    }
    else
    {
        *pCheckSumErr = true;
    }
}

void CANErrDTC_Diag(uint8 ErrID, boolean InputErrState)
{
	CANErrDiag_StateType *p_Errstate = NULL;
	uint8 i;

	for(i = 0; i < CANErr_STATE_COUNT; i++)
	    {
	        if(CANErr_state_list[i].ErrId == ErrID)
	        {
	        	p_Errstate = &CANErr_state_list[i];
	            break;
	        }
	    }

	if(p_Errstate == NULL)
	{
		return;
	}

	if(InputErrState==1U)
	{
		p_Errstate->ClearErrCounter=0;

		if((p_Errstate->ErrCounter)>=(p_Errstate->ErrCounterMax))
		{
			*(p_Errstate->ErrState)=1;
			p_Errstate->ErrStateRaw=1;
		}
		else
		{
			p_Errstate->ErrCounter++;
		}
	}
	else if(p_Errstate->ErrStateRaw==1U)
	{
		p_Errstate->ErrCounter=0;

		if((p_Errstate->ClearErrCounter)>=(p_Errstate->ClearErrCounterMax))
		{
			*(p_Errstate->ErrState)=0;
			p_Errstate->ErrStateRaw=0;
		}
		else
		{
			p_Errstate->ClearErrCounter++;
		}
	}
	else
	{
		p_Errstate->ErrCounter=0;
	}

}

void CanIf_CheckSumDataAdd_Callout(uint32 txPduId,uint32 SduLength, uint8 *SduDataArray,uint8 txCANNodeID)
{
	uint8 i = 0;
	uint8 CheckSumTemp = 0;
    uint8 CheckSumArrayTemp[8] = {0};

	txPduId=txPduId&0xFFFF;

	CANIF_CANNodeNum=txCANNodeID;

	if ((SduLength>=8U)&&(CanIf_IsNeedCheckSumPdu(txPduId)))
	{
		for(i = 0; i < 7U; i++)
		{
			CheckSumArrayTemp[i] = SduDataArray[i];
		}
		CheckSumTemp = CalculateCRC8(CheckSumArrayTemp);
		if((txPduId==0x0B9)&&(txCANNodeID==CANIF_PTCANNodeNum))
		{

		}
		else
		{
			SduDataArray[7]=CheckSumTemp;
		}
		
	}
	else if ((SduLength<8U)&&(CanIf_IsNeedCheckSumPdu(txPduId)))
	{
		for(i = 0; i < (SduLength-1); i++)
		{
			CheckSumArrayTemp[i] = SduDataArray[i];
		}
		CheckSumTemp = CalculateCRC8(CheckSumArrayTemp);
		if((txPduId==0x0B9)&&(txCANNodeID==CANIF_PTCANNodeNum))
		{

		}
		else
		{
			SduDataArray[SduLength]=CheckSumTemp;
		}
	}
	else
	{
		return;
	}
}

boolean CanIf_IsNeedCheckSumPdu(uint32 currentPduId)
{
    uint8 idx = 0U;
    for(idx = 0U; idx < CHECKSUM_PDU_NUM; idx++)
    {
        if(CheckSumNeedPduIdList[idx] == currentPduId)
        {
            return TRUE; 
        }
    }
    return FALSE; 
}

void DiagErr_SetEventStatus(void)
{
	#ifndef VCU_Test_Code_LLH   
	Dem_SetEventStatus(((uint16)32876U), (boolean)Can_DiagVltgLowErrFlg);
	Dem_SetEventStatus(((uint16)32877U), (boolean)Can_DiagVltgHighErrFlg);
	// Dem_SetEventStatus(((uint16)32891U), (boolean)CANB_stBusoffFlg);
	// Dem_SetEventStatus(((uint16)32892U), (boolean)CANA_stBusoffFlg);
	// Dem_SetEventStatus(((uint16)32936U), (boolean)CAND_stBusoffFlg);
	// Dem_ReportErrorStatus(((uint16)32891U), (boolean)CANB_stBusoffFlg);
	// Dem_ReportErrorStatus(((uint16)32892U), (boolean)CANA_stBusoffFlg);
	// Dem_ReportErrorStatus(((uint16)32936U), (boolean)CAND_stBusoffFlg);
	Dem_SetEventStatus(((uint16)32894U), (boolean)PMS_EHB_communication_lost);
	Dem_SetEventStatus(((uint16)32896U), (boolean)PMS_DCDC_communication_lost);
	Dem_SetEventStatus(((uint16)32900U), (boolean)PMS_EGSM_communication_lost);
	Dem_SetEventStatus(((uint16)32902U), (boolean)PMS_Speed_communication_lost);
	Dem_SetEventStatus(((uint16)32975U), (boolean)PMS_CSM_communication_lost/*CANB_0x3CA_TimeOut*/);
	Dem_SetEventStatus(((uint16)32945U), (boolean)PMS_PEPS_DataInvalidErr);
	#endif
}