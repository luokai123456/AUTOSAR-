#include "Xcp_Swc.h"
#include "VX1000If.h"
#include "Can_GeneralTypes.h"
#include "Can.h"

#define CAN_FRAMETYPE_STD			(0U)
#define CAN_FRAMETYPE_EXT			(1U)

#define XcpCANF_TxStartChannelNum	(XCP_CAN_HWObject_TX)//89U
#define XCP_OBS_LIMIT_ENABLE        (0)/*是否开启观测量地址限制：0 - 不开启，1 - 开启*/

const uint32 XCP_valCalRAM_ADDR_MP           = 0x40020000U;
const uint32 XCP_valCalFLASH_ADDR_MP         = 0x40020000U;
const uint32 XCP_valCALRAM_SIZE_MP           = 0U;
const uint32 XCP_valCALRAM_REMAPSIZE_MP      = REMAP_SIZE_256KB;

#if(XCP_OBS_LIMIT_ENABLE == 1)
const uint32 XCP_OBS_LIMIT_MINADDR_MP        = 0x40080000U;
const uint32 XCP_OBS_LIMIT_MAXADDR_MP        = 0x400BFFFFU;
#else
const uint32 XCP_OBS_LIMIT_MINADDR_MP        = 0x0U;
const uint32 XCP_OBS_LIMIT_MAXADDR_MP        = 0xFFFFFFFFU;
#endif

/************************************CAN or CANFD**************************/
const uint8 Const_CRM_CONNECT_LEN              = 8U;
const uint8 Const_CRO_BUILD_CHECKSUM_LEN       = 8U;
const uint8 Const_CRM_BUILD_CHECKSUM_LEN       = 8U;
const uint8 Const_CRO_START_STOP_SYNC_LEN      = 2U;
const uint8 Const_XCP_ODT_COUNT                = 34U;
const uint8 Const_XCP_ODT_ENTRYYS_COUNT        = 7U;
/************************************CAN or CANFD**************************/

/************************************XCP******************************/
#pragma ghs section data =".cal_section"
volatile uint32 Xcp_valCalDataCore1_Mp = 30;
volatile uint32 Xcp_valCalDataCore2_Mp = 30;
#pragma ghs section
#pragma ghs section data =".XCP_CAL"
volatile uint32 Xcp_valCalDataCore3_Mp = 30;
volatile uint32 Xcp_valCalDataCore4_Mp = 30;
volatile uint32 Xcp_valCalDataCore5_Mp = 30;
volatile uint32 Xcp_valCalDataCore6_Mp = 30;
volatile uint32 Xcp_valCalDataCore7_Mp = 30;
volatile uint32 Xcp_valCalDataCore8_Mp = 30;
volatile uint32  Xcp_valCalDataCore41_Mp[100] =
					   {30,30,30,30,30,30,30,30,30,30,
						30,30,30,30,30,30,30,30,30,30,
						30,30,30,30,30,30,30,30,30,30,
						30,30,30,30,30,30,30,30,30,30,
						30,30,30,30,30,30,30,30,30,30,
						30,30,30,30,30,30,30,30,30,30,
						30,30,30,30,30,30,30,30,30,30,
						30,30,30,30,30,30,30,30,30,30,
						30,30,30,30,30,30,30,30,30,30,
						30,30,30,30,30,30,30,30,30,30};
volatile uint32  Xcp_valCalDataCore42_Mp[100] =
					   {30,30,30,30,30,30,30,30,30,30,
						30,30,30,30,30,30,30,30,30,30,
						30,30,30,30,30,30,30,30,30,30,
						30,30,30,30,30,30,30,30,30,30,
						30,30,30,30,30,30,30,30,30,30,
						30,30,30,30,30,30,30,30,30,30,
						30,30,30,30,30,30,30,30,30,30,
						30,30,30,30,30,30,30,30,30,30,
						30,30,30,30,30,30,30,30,30,30,
						30,30,30,30,30,30,30,30,30,30};
#pragma ghs section

#pragma ghs section data =".XCP_OBS"
volatile uint32 Xcp_valMeaDataCore1_Mp;
volatile uint32 Xcp_valMeaDataCore2_Mp;
volatile uint32 Xcp_valMeaDataCore3_Mp;
volatile uint32 Xcp_valMeaDataCore4_Mp;
volatile uint32 Xcp_valMeaDataCore5_Mp;
volatile uint32 Xcp_valMeaDataCore6_Mp;
volatile uint32 Xcp_valMeaDataCore7_Mp;
volatile uint32 Xcp_valMeaDataCore8_Mp;
volatile uint32 Xcp_valMeaDataCore41_Mp[100];
volatile uint32 Xcp_valMeaDataCore42_Mp[100];
volatile uint8 TaskCnt_Core1;
#pragma ghs section

uint8 TaskCnt_Core2 = 0;
uint8 TaskCnt_Core3 = 0;

/************************************VX1000******************************/

void XCPSend_Test(void)
{
    uint8 i = 0;
    for(i = 0; i < 100; i++)
    {
         Xcp_valMeaDataCore41_Mp[i] = Xcp_valCalDataCore41_Mp[i];
         Xcp_valMeaDataCore42_Mp[i] = Xcp_valCalDataCore42_Mp[i];
    }

     Xcp_valMeaDataCore1_Mp = Xcp_valCalDataCore1_Mp;
     Xcp_valMeaDataCore2_Mp = Xcp_valCalDataCore2_Mp;
     Xcp_valMeaDataCore3_Mp = Xcp_valCalDataCore3_Mp;
     Xcp_valMeaDataCore4_Mp = Xcp_valCalDataCore4_Mp;

    if(TaskCnt_Core1 < 50)
    {
         TaskCnt_Core1++;
    }
    else
    {
         TaskCnt_Core1 = 0;
    }

	if(TaskCnt_Core2 < 50)
    {
         TaskCnt_Core2++;
    }
    else
    {
         TaskCnt_Core2 = 0;
    }
}

uint8 Xcp_InitFlg_MP    = 0;

void XcpCan_Init(void)
{
	CanXcp_Init();
	Xcp_Init();
}

void XcpCAN_RxMessage(uint8 *receive_data,uint8 receive_length)
{
	uint8 DataPtr[8] = {0};
    PduInfoType PduInfoPtrXcp;
    PduInfoPtrXcp.SduDataPtr = DataPtr;

	for(uint8 i = 0; i < receive_length; i++)
	{
		DataPtr[i] = (uint8)receive_data[i];
	}

	PduInfoPtrXcp.SduLength  = receive_length;
	Xcp_CanIfRxIndication(0, &PduInfoPtrXcp);
	CanXcpGetStatus = 1;
}

uint8 XcpCAN_TxMessage_Count = 0;
void XcpCAN_TxMessage(const uint8 *DataPtr, uint8 DataLen)
{
	XcpCAN_TxMessage_Count++;
	uint8 DataPtr_Tx[8] = {0};
	Can_PduType canPduInfo;
	canPduInfo.sdu = DataPtr_Tx;

	#ifndef CAN_TEST_CFG_H_
	canPduInfo.swPduHandle = XcpCANF_TxStartChannelNum;/*正式程序*/
	#else
	canPduInfo.swPduHandle = (XcpCANF_TxStartChannelNum + XcpCAN_TxMessage_Count);/*测试程序*/
	#endif

	canPduInfo.length = DataLen;
	canPduInfo.id = 0x7F1;

	for (uint8 i=0; i < DataLen; i++)
	{
		DataPtr_Tx[i] = DataPtr[i];
	}

	#ifndef CAN_TEST_CFG_H_
    Can_Write(XcpCANF_TxStartChannelNum, &canPduInfo);/*正式程序*/
	#else
	Can_Write((XcpCANF_TxStartChannelNum + XcpCAN_TxMessage_Count), &canPduInfo);/*测试程序*/
	#endif
}

uint16 Xcp_Daq_Count = 0;
void XCP_Step(void)
{
    if(Xcp_Daq_Count < 1000)
    {
        Xcp_Daq_Count++;
    }
    else
    {
        Xcp_Daq_Count = 1;
    }

    if(Xcp_InitFlg_MP == 0)
    {
        XcpCan_Init();
        Xcp_InitFlg_MP = 1;
    }

	XCPSend_Test();
    XcpCAN_TxMessage_Count = 0;
    Xcp_MainFunction();
    Xcp_Daq_Eventchannel1();

    if(Xcp_Daq_Count%5 == 0)
    {
        Xcp_Daq_Eventchannel2();
    }

    if(Xcp_Daq_Count%10 == 0)
    {
        Xcp_Daq_Eventchannel3();
    }

	if(Xcp_Daq_Count%100 == 0)
    {
        Xcp_Daq_Eventchannel4();
    }
}
/*********************************XCP*****************************/

void VX1000Send_Test(void)
{
     Xcp_valMeaDataCore5_Mp = Xcp_valCalDataCore5_Mp;
     Xcp_valMeaDataCore6_Mp = Xcp_valCalDataCore6_Mp;
     Xcp_valMeaDataCore7_Mp = Xcp_valCalDataCore7_Mp;
     Xcp_valMeaDataCore8_Mp = Xcp_valCalDataCore8_Mp;

    if(TaskCnt_Core3 < 50)
    {
         TaskCnt_Core3++;
    }
    else
    {
         TaskCnt_Core3 = 0;
    }
}

void CAN_Send_Demo(void)
{
	uint8 DataPtr[8] = {0};
	Can_PduType canPduInfo;
	canPduInfo.sdu = DataPtr;
	canPduInfo.swPduHandle = XcpCANF_TxStartChannelNum;
	canPduInfo.length = 8;
	canPduInfo.id = 0x666;

	DataPtr[0] = gVX1000.EventTimestamp>>24;
	DataPtr[1] = gVX1000.EventTimestamp>>16;
	DataPtr[2] = gVX1000.EventTimestamp>>8;
	DataPtr[3] = gVX1000.EventTimestamp;
	DataPtr[4] = VX1000If_State;
	DataPtr[5] = VX1000If_ErrorCount;
	DataPtr[6] = Xcp_valCalDataCore3_Mp;
	DataPtr[7] = Xcp_valMeaDataCore3_Mp;

	Can_Write(XcpCANF_TxStartChannelNum, &canPduInfo);
}
/**********************************VX1000*****************************/
volatile boolean VX1000If_DriverActive     = TRUE;

uint16 VX1000_Daq_Count = 0;
void VX1000_Step(void)
{
	// CAN_Send_Demo();
	VX1000If_Event(0x2);

    if(VX1000_Daq_Count < 1000)
    {
    	VX1000_Daq_Count++;
    }
    else
    {
    	VX1000_Daq_Count = 1;
    }

    if(VX1000_Daq_Count%5 == 0)
    {
    	VX1000If_Event(0x3);
    }

    if(VX1000_Daq_Count%10 == 0)
    {
    	VX1000If_Event(0x4);
    }
}
/**********************************VX1000*****************************/


