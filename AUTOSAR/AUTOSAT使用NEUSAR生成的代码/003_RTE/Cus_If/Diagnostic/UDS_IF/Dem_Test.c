#include "Dem_Test.h"


/********************************SnapshotData*************************/

void Test_Function_SnapshotData(uint32 CanID, uint8 *receive_data,uint8 receive_length)
{
    uint8 DTC_DID_LastEventStatus_Mp = 0U;
    uint32 DtcIdx =0;
    uint32 RxDtcCode_Lo = 0U;      /* 收到的 DTC */
    uint8 DataPtr[8] = {0};
	for(uint8 i = 0; i < receive_length; i++)
	{
		DataPtr[i] = (uint8)receive_data[i];
	}

    if(CanID==0x3C3)
    {
        RxDtcCode_Lo=(((uint32)DataPtr[0] << 16U) |
                      ((uint32)DataPtr[1] << 8U)  |
                      ((uint32)DataPtr[2]));
                      
        DTC_DID_LastEventStatus_Mp = DataPtr[3];

        for (DtcIdx = 1U; DtcIdx <= DEM_CFG_DTC_NUM; DtcIdx++)// 注意：DtcIdx 从 1 开始，因为 0 是无效占位
        {
            if (Dem_CfgUdsDtcValue[DtcIdx] == RxDtcCode_Lo)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)(Dem_CfgEventTable[DtcIdx].awEvtId),(Dem_EventStatusType)DTC_DID_LastEventStatus_Mp);
                break;
            }
        }

        DTC_DID_LastEventStatus_Mp = 0U;
    }

 //==================== CAN ID:0x310  第1组 8个 ====================
if (CanID == 0x247)
{
    DemDataElement_DID_0x0400[0]  = DataPtr[0];
    DemDataElement_DID_0x0402[0]  = DataPtr[1];
    DemDataElement_DID_0x0403[0]  = DataPtr[2];
    DemDataElement_DID_0x0404[0]  = DataPtr[3];
    DemDataElement_DID_0x0405[0]  = DataPtr[4];
    DemDataElement_DID_0x0406[0]  = DataPtr[5];
    DemDataElement_DID_0x0407[0]  = DataPtr[6];
    DemDataElement_DID_0x0408[0]  = DataPtr[7];
}

//==================== CAN ID:0x311  第2组 8个 ====================
if (CanID == 0x27D)
{
    DemDataElement_DID_0x0409[0]  = DataPtr[0];
    DemDataElement_DID_0x040B[0]  = DataPtr[1];
    DemDataElement_DID_0x040C[0]  = DataPtr[2];
    DemDataElement_DID_0x040D[0]  = DataPtr[3];
    DemDataElement_DID_0x04CF[0]  = DataPtr[4];
    DemDataElement_DID_0x0505[0]  = DataPtr[5];
    DemDataElement_DID_0x0525[0]  = DataPtr[6];
    DemDataElement_DID_0x0526[0]  = DataPtr[7];
}

//==================== CAN ID:0x312  第3组 8个 ====================
if (CanID == 0x27E)
{
    DemDataElement_DID_0x0527[0]  = DataPtr[0];
    DemDataElement_DID_0x0528[0]  = DataPtr[1];
    DemDataElement_DID_0x0529[0]  = DataPtr[2];
    DemDataElement_DID_0x052B[0]  = DataPtr[3];
    DemDataElement_DID_0x052D[0]  = DataPtr[4];
    DemDataElement_DID_0x0530[0]  = DataPtr[5];
    DemDataElement_DID_0x0531[0]  = DataPtr[6];
    DemDataElement_DID_0x0532[0]  = DataPtr[7];
}

//==================== CAN ID:0x313  第4组 8个 ====================
if (CanID == 0x27F)
{
    DemDataElement_DID_0x0533[0]  = DataPtr[0];
    DemDataElement_DID_0x0534[0]  = DataPtr[1];
    DemDataElement_DID_0x0535[0]  = DataPtr[2];
    DemDataElement_DID_0x0536[0]  = DataPtr[3];
    DemDataElement_DID_0x0538[0]  = DataPtr[4];
    DemDataElement_DID_0x0539[0]  = DataPtr[5];
    DemDataElement_DID_0x053B[0]  = DataPtr[6];
    DemDataElement_DID_0x053C[0]  = DataPtr[7];
}

//==================== CAN ID:0x314  第5组 8个 ====================
if (CanID == 0x283)
{
    DemDataElement_DID_0x0542[0]  = DataPtr[0];
    DemDataElement_DID_0x0543[0]  = DataPtr[1];
    DemDataElement_DID_0x0544[0]  = DataPtr[2];
    DemDataElement_DID_0x0545[0]  = DataPtr[3];
    DemDataElement_DID_0x0547[0]  = DataPtr[4];
    DemDataElement_DID_0x055A[0]  = DataPtr[5];
    DemDataElement_DID_0x055C[0]  = DataPtr[6];
    DemDataElement_DID_0x0585[0]  = DataPtr[7];
}

//==================== CAN ID:0x315  第6组 8个 ====================
if (CanID == 0x284)
{
    DemDataElement_DID_0x0586[0]  = DataPtr[0];
    DemDataElement_DID_0x0587[0]  = DataPtr[1];
    DemDataElement_DID_0x0588[0]  = DataPtr[2];
    DemDataElement_DID_0x0589[0]  = DataPtr[3];
    DemDataElement_DID_0x058A[0]  = DataPtr[4];
    DemDataElement_DID_0x058C[0]  = DataPtr[5];
    DemDataElement_DID_0x058D[0]  = DataPtr[6];
    DemDataElement_DID_0x058E[0]  = DataPtr[7];
}

//==================== CAN ID:0x316  第7组 8个 ====================
if (CanID == 0x285)
{
    DemDataElement_DID_0x058F[0]  = DataPtr[0];
    DemDataElement_DID_0x0590[0]  = DataPtr[1];
    DemDataElement_DID_0x0592[0]  = DataPtr[2];
    DemDataElement_DID_0x0594[0]  = DataPtr[3];
    DemDataElement_DID_0x0596[0]  = DataPtr[4];
    DemDataElement_DID_0x0597[0]  = DataPtr[5];
    DemDataElement_DID_0x0598[0]  = DataPtr[6];
    DemDataElement_DID_0x0599[0]  = DataPtr[7];
}

//==================== CAN ID:0x317  第8组 8个 ====================
if (CanID == 0x286)
{
    DemDataElement_DID_0x059A[0]  = DataPtr[0];
    DemDataElement_DID_0x059B[0]  = DataPtr[1];
    DemDataElement_DID_0x059C[0]  = DataPtr[2];
    DemDataElement_DID_0x059D[0]  = DataPtr[3];
    DemDataElement_DID_0x059E[0]  = DataPtr[4];
    DemDataElement_DID_0x059F[0]  = DataPtr[5];
    DemDataElement_DID_0x05A1[0]  = DataPtr[6];
    DemDataElement_DID_0x05AA[0]  = DataPtr[7];
}

//==================== CAN ID:0x318  第9组 8个 ====================
if (CanID == 0x287)
{
    DemDataElement_DID_0x05AB[0]  = DataPtr[0];
    DemDataElement_DID_0x05B3[0]  = DataPtr[1];
    DemDataElement_DID_0x05B4[0]  = DataPtr[2];
    DemDataElement_DID_0x05B5[0]  = DataPtr[3];
    DemDataElement_DID_0x05B6[0]  = DataPtr[4];
    DemDataElement_DID_0x05B9[0]  = DataPtr[5];
    DemDataElement_DID_0x05BA[0]  = DataPtr[6];
    DemDataElement_DID_0x05BB[0]  = DataPtr[7];
}

//==================== CAN ID:0x319  第10组 8个 ====================
if (CanID == 0x291)
{
    DemDataElement_DID_0x05BC[0]  = DataPtr[0];
    DemDataElement_DID_0x05BD[0]  = DataPtr[1];
    DemDataElement_DID_0x05BE[0]  = DataPtr[2];
    DemDataElement_DID_0x05C0[0]  = DataPtr[3];
    DemDataElement_DID_0x05C1[0]  = DataPtr[4];
    DemDataElement_DID_0x05C2[0]  = DataPtr[5];
    DemDataElement_DID_0x05C3[0]  = DataPtr[6];
    DemDataElement_DID_0x05C4[0]  = DataPtr[7];
}

//==================== CAN ID:0x31A  第11组 8个 ====================
if (CanID == 0x292)
{
    DemDataElement_DID_0x05C5[0]  = DataPtr[0];
    DemDataElement_DID_0x05C6[0]  = DataPtr[1];
    DemDataElement_DID_0x05C7[0]  = DataPtr[2];
    DemDataElement_DID_0x05C8[0]  = DataPtr[3];
    DemDataElement_DID_0x05C9[0]  = DataPtr[4];
    DemDataElement_DID_0x05CA[0]  = DataPtr[5];
    DemDataElement_DID_0x05CB[0]  = DataPtr[6];
    DemDataElement_DID_0x05CC[0]  = DataPtr[7];
}

//==================== CAN ID:0x31B  第12组 8个 ====================
if (CanID == 0x2A3)
{
    DemDataElement_DID_0x05CD[0]  = DataPtr[0];
    DemDataElement_DID_0x05CE[0]  = DataPtr[1];
    DemDataElement_DID_0x05CF[0]  = DataPtr[2];
    DemDataElement_DID_0x05D0[0]  = DataPtr[3];
    DemDataElement_DID_0x05D1[0]  = DataPtr[4];
    DemDataElement_DID_0x05D2[0]  = DataPtr[5];
    DemDataElement_DID_0x05D3[0]  = DataPtr[6];
    DemDataElement_DID_0x05D4[0]  = DataPtr[7];
}

//==================== CAN ID:0x31C  第13组 8个 ====================
if (CanID == 0x2A6)
{
    DemDataElement_DID_0xCF00[0]  = DataPtr[0];
    DemDataElement_DID_0xCF05[0]  = DataPtr[1];
    DemDataElement_DID_0xCF06[0]  = DataPtr[2];
    DemDataElement_DID_0xCF07[0]  = DataPtr[3];
    DemDataElement_DID_0xDD00[0]  = DataPtr[4];
    DemDataElement_DID_0xDF00[0]  = DataPtr[5];
    DemDataElement_DID_0xDF01[0]  = DataPtr[6];
    DemDataElement_DID_0xDF02[0]  = DataPtr[7];
}

//==================== CAN ID:0x31D  第14组 8个 ====================
if (CanID == 0x2EA)
{
    DemDataElement_DID_0xDF03[0]  = DataPtr[0];
    DemDataElement_DID_0xDF04[0]  = DataPtr[1];
    DemDataElement_DID_0xDF06[0]  = DataPtr[2];
    DemDataElement_DID_0xDF09[0]  = DataPtr[3];
    DemDataElement_DID_0xDF0A[0]  = DataPtr[4];
    DemDataElement_DID_0xDF0B[0]  = DataPtr[5];
    DemDataElement_DID_0xDF0C[0]  = DataPtr[6];
    DemDataElement_DID_0xDF0D[0]  = DataPtr[7];
}

//==================== CAN ID:0x31E  剩余最后1个DID ====================
if (CanID == 0x2F2)
{
    DemDataElement_DID_0xDF0E[0]  = DataPtr[0];
    // DataPtr[1]~DataPtr[7]无对应DID，空置不赋值
}
   

}


/**********************************SnapshotData***********************/
