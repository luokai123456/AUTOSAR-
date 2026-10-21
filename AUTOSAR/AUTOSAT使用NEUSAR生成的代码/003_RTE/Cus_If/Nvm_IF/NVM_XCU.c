
#include "NVM_XCU.h"
#include "PMS_Geely_Interface.h"
#include "User_Func.h"
#include "NvM.h"

extern uint32 TotalMileageLastSaveData;

boolean NVM_XCU_EEWriteFlgBlock54=0;

uint32 NvM_BlockRunTimer 		= 0;//单块读EEprom超时计数
uint32 NvM_TotalBlockRunTimer 	= 0;//总块读EEprom超时计数
uint16 NvM_BlockReadCounter 	= 0;//读EEprom索引

//上电读，下电写 请求标志位
boolean NVM_XCU_EEPowerReqFlgBlock50	= 0;
boolean NVM_XCU_EEPowerReqFlgBlock51	= 0;
boolean NVM_XCU_EEPowerReqFlgBlock52	= 0;
boolean NVM_XCU_EEPowerReqFlgBlock53	= 0;
boolean NVM_XCU_EEPowerReqFlgBlock119	= 0;
boolean NVM_XCU_EEPowerReqFlgBlock128	= 0;
boolean NVM_XCU_EEPowerReqFlgBlock129	= 0;
boolean NVM_XCU_EEPowerReqFlgBlock130	= 0;
boolean NVM_XCU_EEPowerReqFlgBlock131	= 0;

//NvM函数返回值存放地址
boolean NVM_XCU_EEFunRetVal_Block50  = 0;
boolean NVM_XCU_EEFunRetVal_Block51  = 0;
boolean NVM_XCU_EEFunRetVal_Block52  = 0;
boolean NVM_XCU_EEFunRetVal_Block53  = 0;
boolean NVM_XCU_EEFunRetVal_Block54  = 0;
boolean NVM_XCU_EEFunRetVal_Block119 = 0;
boolean NVM_XCU_EEFunRetVal_Block128 = 0;
boolean NVM_XCU_EEFunRetVal_Block129 = 0;
boolean NVM_XCU_EEFunRetVal_Block130 = 0;
boolean NVM_XCU_EEFunRetVal_Block131 = 0;

//立即写表格
XCU_NVMBlockArrayType XCU_NVMBlockImmeArray[] = 
{
	{54		,&NVMBlock54Array[0]	,&NVM_XCU_EEWriteFlgBlock54		,NVM_REQ_OK	,0	,&NVM_XCU_EEFunRetVal_Block54	},
	{119	,&NVMBlock119Array[0]	,&NVM_XCU_EEWriteFlgBlock119	,NVM_REQ_OK	,0	,&NVM_XCU_EEFunRetVal_Block119	},
	{128	,&NVMBlock128Array[0]	,&NVM_XCU_EEWriteFlgBlock128	,NVM_REQ_OK	,0	,&NVM_XCU_EEFunRetVal_Block128	},
	{129	,&NVMBlock129Array[0]	,&NVM_XCU_EEWriteFlgBlock129	,NVM_REQ_OK	,0	,&NVM_XCU_EEFunRetVal_Block129	},
	{130	,&NVMBlock130Array[0]	,&NVM_XCU_EEWriteFlgBlock130	,NVM_REQ_OK	,0	,&NVM_XCU_EEFunRetVal_Block130	},
	{131	,&NVMBlock131Array[0]	,&NVM_XCU_EEWriteFlgBlock131	,NVM_REQ_OK	,0	,&NVM_XCU_EEFunRetVal_Block131	},
};


void NVM_XCU_EEWriteImm(void)
{
	for(uint16 i=0;i<XCU_NVMBLOCKARRAY_SIZE;i++)
	{
		if(XCU_NVMBlockImmeArray[i].RequestFlg[0] == TRUE)
		{
			NvM_GetErrorStatus(XCU_NVMBlockImmeArray[i].BlockID,&XCU_NVMBlockImmeArray[i].BlockSts);
			if(XCU_NVMBlockImmeArray[i].BlockSts != NVM_REQ_PENDING)
			{
				NvM_WriteBlock(XCU_NVMBlockImmeArray[i].BlockID,XCU_NVMBlockImmeArray[i].BlockDataAdrr);
				XCU_NVMBlockImmeArray[i].RequestFlg[0] = FALSE;
			}
		}
	}
}





//下电写表格
XCU_NVMBlockArrayType XCU_NVMBlockPowerOffArray[] = 
{
	{50		,&NVMBlock50Array[0]	,&NVM_XCU_EEPowerReqFlgBlock50	,NVM_REQ_OK	,0	,&NVM_XCU_EEFunRetVal_Block50},
	{51		,&NVMBlock51Array[0]	,&NVM_XCU_EEPowerReqFlgBlock51	,NVM_REQ_OK	,0	,&NVM_XCU_EEFunRetVal_Block51},
	{52		,&NVMBlock52Array[0]	,&NVM_XCU_EEPowerReqFlgBlock52	,NVM_REQ_OK	,0	,&NVM_XCU_EEFunRetVal_Block52},
	{53		,&NVMBlock53Array[0]	,&NVM_XCU_EEPowerReqFlgBlock53	,NVM_REQ_OK	,0	,&NVM_XCU_EEFunRetVal_Block53},
	{119	,&NVMBlock119Array[0]	,&NVM_XCU_EEPowerReqFlgBlock119	,NVM_REQ_OK	,0	,&NVM_XCU_EEFunRetVal_Block119},
	{128	,&NVMBlock128Array[0]	,&NVM_XCU_EEPowerReqFlgBlock128	,NVM_REQ_OK	,0	,&NVM_XCU_EEFunRetVal_Block128},
	{129	,&NVMBlock129Array[0]	,&NVM_XCU_EEPowerReqFlgBlock129	,NVM_REQ_OK	,0	,&NVM_XCU_EEFunRetVal_Block129},
	{130	,&NVMBlock130Array[0]	,&NVM_XCU_EEPowerReqFlgBlock130	,NVM_REQ_OK	,0	,&NVM_XCU_EEFunRetVal_Block130},
	{131	,&NVMBlock131Array[0]	,&NVM_XCU_EEPowerReqFlgBlock131	,NVM_REQ_OK	,0	,&NVM_XCU_EEFunRetVal_Block131},
};




uint16 Temp_Counter = 0;

uint8 NVM_XCU_EEWrite(uint8* OpStatus)
{

	uint8  RetVal = FALSE;
	uint16 WriteFinishBlockNum = 0;

	if(OpStatus[0] == 0U)
	{
		NVM_XCU_EEDataPack();
		for(uint16 i = 0;i < XCU_NVMBLOCKPOWEROFFARRAY_SIZE;i++)
		{
			XCU_NVMBlockPowerOffArray[i].RequestFlg[0] 		= TRUE;
			XCU_NVMBlockPowerOffArray[i].RequestFinishFlg 	= FALSE;
		}
		OpStatus[0] = 1U;
	}
	else
	{
		//请求EEprom写入
		for(uint16 i = 0;i < XCU_NVMBLOCKPOWEROFFARRAY_SIZE;i++)
		{
			if(XCU_NVMBlockPowerOffArray[i].RequestFlg[0] == TRUE)
			{
				NvM_GetErrorStatus(XCU_NVMBlockPowerOffArray[i].BlockID,&XCU_NVMBlockPowerOffArray[i].BlockSts);
				if((XCU_NVMBlockPowerOffArray[i].BlockSts != NVM_REQ_PENDING)&&(XCU_NVMBlockPowerOffArray[i].RequestFinishFlg == FALSE))
				{
					NvM_WriteBlock(XCU_NVMBlockPowerOffArray[i].BlockID,XCU_NVMBlockPowerOffArray[i].BlockDataAdrr);
					XCU_NVMBlockPowerOffArray[i].RequestFlg[0] 		= FALSE;
					XCU_NVMBlockPowerOffArray[i].RequestFinishFlg 	= TRUE;
				}
			}
		}

		//统计是否全部写入完成
		for(uint16 i = 0;i < XCU_NVMBLOCKPOWEROFFARRAY_SIZE;i++)
		{
			NvM_GetErrorStatus(XCU_NVMBlockPowerOffArray[i].BlockID,&XCU_NVMBlockPowerOffArray[i].BlockSts);
			if((XCU_NVMBlockPowerOffArray[i].BlockSts != NVM_REQ_PENDING)&&(XCU_NVMBlockPowerOffArray[i].RequestFinishFlg == TRUE))
			{
				WriteFinishBlockNum++;
			}
			else
			{
				break;
			}
		}

		if(WriteFinishBlockNum == XCU_NVMBLOCKPOWEROFFARRAY_SIZE)
		{
			RetVal = TRUE;//写入完成
		}
		else
		{
			RetVal = FALSE;//写入未完成
		}
	}

	return RetVal;

}


void NVM_XCU_EERead(void)
{
	//读EEprom
	do
	{
		NvM_ReadBlock(XCU_NVMBlockPowerOffArray[NvM_BlockReadCounter].BlockID,XCU_NVMBlockPowerOffArray[NvM_BlockReadCounter].BlockDataAdrr);	
		NvM_BlockRunTimer 		= 0;
		NvM_TotalBlockRunTimer 	= 0;
		do
		{
			NvM_GetErrorStatus(XCU_NVMBlockPowerOffArray[NvM_BlockReadCounter].BlockID,&XCU_NVMBlockPowerOffArray[NvM_BlockReadCounter].BlockSts);
			NvM_MainFunction();
			Fee_MainFunction();
			Fls_MainFunction();
			NvM_BlockRunTimer++;		//单块读EEprom超时计数
			NvM_TotalBlockRunTimer++;	//总块读EEprom超时计数
		}while((XCU_NVMBlockPowerOffArray[NvM_BlockReadCounter].BlockSts == NVM_REQ_PENDING) && (NvM_BlockRunTimer < 500U));
		NvM_BlockReadCounter++;//读EEprom索引+1
	}while((NvM_BlockReadCounter < XCU_NVMBLOCKPOWEROFFARRAY_SIZE) && (NvM_TotalBlockRunTimer < 50000U));

	//将EEprom的值赋值到ASW 变量中
	NVM_XCU_EEDataUnPack();
}

void NVM_XCU_EEDataPack(void)
{
	WorkTime_SaveToEEPROM();
	NVMBlock52Array[8]=NvM_256Byte_RAM_Block0[0];
	NVMBlock52Array[9]=NvM_256Byte_RAM_Block0[1];
	NVMBlock52Array[10]=NvM_256Byte_RAM_Block0[2];
	NVMBlock52Array[11]=NvM_256Byte_RAM_Block0[3];
	NVMBlock52Array[12]=NvM_256Byte_RAM_Block0[4];
	NVMBlock52Array[13]=NvM_256Byte_RAM_Block0[5];
	NVMBlock52Array[14]=NvM_256Byte_RAM_Block0[6];
	NVMBlock52Array[15]=NvM_256Byte_RAM_Block0[7];
}
void NVM_XCU_EEDataUnPack(void)
{
	NvM_256Byte_RAM_Block0[0]=NVMBlock52Array[8];
	NvM_256Byte_RAM_Block0[1]=NVMBlock52Array[9];
	NvM_256Byte_RAM_Block0[2]=NVMBlock52Array[10];
	NvM_256Byte_RAM_Block0[3]=NVMBlock52Array[11];
	NvM_256Byte_RAM_Block0[4]=NVMBlock52Array[12];
	NvM_256Byte_RAM_Block0[5]=NVMBlock52Array[13];
	NvM_256Byte_RAM_Block0[6]=NVMBlock52Array[14];
	NvM_256Byte_RAM_Block0[7]=NVMBlock52Array[15];

	TotalMileageLastSaveData=NVMBlock54Array[0]
		+(uint32)((uint32)NVMBlock54Array[1]<<8)
		+(uint32)((uint32)NVMBlock54Array[2]<<16)
		+(uint32)((uint32)NVMBlock54Array[3]<<24);
	for(uint16 i =0;i<256U;i++)
	{
		ASW_NvRam_App1_MP[i] = NVMBlock119Array[i];
		ASW_NvRam_App2_MP[i] = NVMBlock128Array[i];
		ASW_NvRam_App3_MP[i] = NVMBlock129Array[i];
		ASW_NvRam_App4_MP[i] = NVMBlock130Array[i];
		ASW_NvRam_App5_MP[i] = NVMBlock131Array[i];
	}
}

