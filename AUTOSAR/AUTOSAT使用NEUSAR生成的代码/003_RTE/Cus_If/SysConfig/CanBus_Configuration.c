#include "CanBus_Configuration.h"
#include "ComStack_Types.h"
#include "CanIf_Lcfg.h"

/************************************IMU Calib*******************************/
#define X_POSTIVE  0
#define X_NEGATIVE 1
#define Y_POSTIVE  2
#define Y_NEGATIVE 3
#define Z_POSTIVE  4
#define Z_NEGATIVE 5
const uint8 Cdd_Imu_AxisCalibration[3] = {X_POSTIVE,Y_POSTIVE,Z_POSTIVE};

const uint8		Can_ActiveMode[2] 		= {0,0};			//0：标准帧 1：扩展帧
const uint32	Can_ActiveId[2]			= {0x400,0x400};	//CANA CANB 关心的ID
const uint32	Can_ActiveId_Mask[2] 	= {0x7F,0x7F};		//1：不关心 0：关心

#define Can_valCanArraySize 100

uint8 Can_valNodeId_ArrayCounter=0;
uint8 Can_valMsgId_ArrayCounter=0;

uint8  Can_valNodeId_Array[Can_valCanArraySize]={0};
uint32 Can_valMsgId_Array[Can_valCanArraySize]={0};

boolean CAND_0x125_ActiveRaw = 0;
boolean CAND_0x125_Active = 0;
boolean CAND_0x128_ActiveRaw = 0;
boolean CAND_0x128_Active = 0;
boolean CAND_0x129_ActiveRaw = 0;
boolean CAND_0x129_Active = 0;

boolean CANA_0x398_ActiveRaw = 0;
boolean CANA_0x398_Active = 0;

boolean CANA_0x145_ActiveRaw = 0;
boolean CANA_0x145_Active = 0;

boolean CAND_0x380_ActiveRaw = 0;
boolean CAND_0x380_Active = 0;
boolean CANB_0x3C3_ActiveRaw = 0;
boolean CANB_0x3C3_Active = 0;
boolean CANB_0x3CA_ActiveRaw = 0;
boolean CANB_0x3CA_Active = 0;

boolean CANG_0x122_ActiveRaw = 0;
boolean CANG_0x122_Active = 0;
boolean CANG_0x128_ActiveRaw = 0;
boolean CANG_0x128_Active = 0;
boolean CANE_0x1826F456_ActiveRaw = 0;
boolean CANE_0x1826F456_Active = 0;
boolean CANE_0x1801F456_ActiveRaw = 0;
boolean CANE_0x1801F456_Active = 0;
boolean CANE_0x100AF456_ActiveRaw = 0;
boolean CANE_0x100AF456_Active = 0;
boolean CANE_0x1812F456_ActiveRaw = 0;
boolean CANE_0x1812F456_Active = 0;
boolean CANE_0x1808F456_ActiveRaw = 0;
boolean CANE_0x1808F456_Active = 0;
boolean CANE_0x181DF456_ActiveRaw = 0;
boolean CANE_0x181DF456_Active = 0;
boolean CANE_0x101AF456_ActiveRaw = 0;
boolean CANE_0x101AF456_Active = 0;
boolean CANE_0x81FF456_ActiveRaw = 0;
boolean CANE_0x81FF456_Active = 0;

boolean CANA_0x220_ActiveRaw = 0;
boolean CANA_0x220_Active = 0;

boolean CANB_0x247_ActiveRaw = 0;
boolean CANB_0x247_Active = 0;

boolean CANB_0x1E2_ActiveRaw = 0;
boolean CANB_0x1E2_Active = 0;

boolean CAND_0x2CF_ActiveRaw = 0;
boolean CAND_0x2CF_Active = 0;

boolean CANA_0x157_ActiveRaw = 0;
boolean CAND_0x126_ActiveRaw = 0;
boolean CAND_0x122_ActiveRaw = 0;
boolean CAND_0x1F9_ActiveRaw = 0;
boolean CAND_0x123_ActiveRaw = 0;
boolean CAND_0x121_ActiveRaw = 0;
boolean CAND_0x124_ActiveRaw = 0;
boolean CAND_0x0E0_ActiveRaw = 0;
boolean CAND_0x130_ActiveRaw = 0;
boolean CAND_0x131_ActiveRaw = 0;
boolean CANG_0x124_ActiveRaw = 0;
boolean CANG_0x120_ActiveRaw = 0;

boolean CANA_0x157_Active = 0;
boolean CAND_0x126_Active = 0;
boolean CAND_0x122_Active = 0;
boolean CAND_0x1F9_Active = 0;
boolean CAND_0x123_Active = 0;
boolean CAND_0x121_Active = 0;
boolean CAND_0x124_Active = 0;
boolean CAND_0x0E0_Active = 0;
boolean CAND_0x130_Active = 0;
boolean CAND_0x131_Active = 0;
boolean CANG_0x124_Active = 0;
boolean CANG_0x120_Active = 0;

uint16 CAN_MsgActive_UpdateCounter=0;
void Com_CanSm_CANReceiveInf_callBack(uint8 Can_valNodeId, uint32 Can_valMsgId)
{


	Can_valNodeId_Array[Can_valMsgId_ArrayCounter]=Can_valNodeId;
	Can_valMsgId_Array[Can_valMsgId_ArrayCounter]=Can_valMsgId;

	if(Can_valMsgId_ArrayCounter<(Can_valCanArraySize-1U))
	{
		Can_valMsgId_ArrayCounter++;
	}
	else
	{
		Can_valMsgId_ArrayCounter=0;
	}
}

uint32 AFE_valCellMask_Mp[6] = {0x01FFFF, 0x01FFFF, 0x00FFFF, 0x01FFFF, 0x01FFFF, 0x00FFFF};
uint8 AFE_valTempNumber_Mp[6] =  {6, 6, 6, 6, 6, 6};

void CAN_MsgActive_Update(void)
{

	/*	ActualID By Test:
	 * Can_valNodeId
	 * 1:EV_CAN
	 * 5:PT_CAN
	 *  :FastCharg2 CAN
	 * 4:Chassis CAN
	 * 0:FastCharg1CAN
	 *  :XCPCAN)
	 * 3:HCMCAN*/
    uint8 i=0;
    uint32 Can_valMsgId;
	uint8 Can_valNodeId;
    
	for(i=0;i<=(Can_valCanArraySize-1U);i++)
	{
		Can_valMsgId=(Can_valMsgId_Array[i]&(0x1FFFFFFF));
		Can_valNodeId=Can_valNodeId_Array[i];

		Can_valMsgId_Array[i]=0;
		Can_valNodeId_Array[i]=0;

		switch(Can_valMsgId)
		{
		case 0x398:
			if(Can_valNodeId==CANIF_CHANNEL_PMS_EV_CAN_20260427_RMXR12_INDEX)
			{
				CANA_0x398_ActiveRaw=1;
			}	
			break;
		case 0x145:
			if(Can_valNodeId==CANIF_CHANNEL_PMS_EV_CAN_20260427_RMXR12_INDEX)
			{
				CANA_0x145_ActiveRaw=1;
			}
			break;
		case 0x125:
			if(Can_valNodeId==CANIF_CHANNEL_N72__PMS_C_CAN_20260425_FVS55R_INDEX)
			{
				CAND_0x125_ActiveRaw=1;
			}
			break;
		case 0x128:
			if (Can_valNodeId==CANIF_CHANNEL_N72__PMS_C_CAN_20260425_FVS55R_INDEX)
			{
				CAND_0x128_ActiveRaw=1;
			}
			else if(Can_valNodeId==CANIF_CHANNEL_N72_HCM__MATRIX_V1_1_LGFZID_INDEX)
			{
				CANG_0x128_ActiveRaw=1;
			}
			
			break;
		case 0x129:
			if(Can_valNodeId==CANIF_CHANNEL_N72__PMS_C_CAN_20260425_FVS55R_INDEX)
			{
				CAND_0x129_ActiveRaw=1;
			}
			break;
		case 0x380:
			if(Can_valNodeId==CANIF_CHANNEL_N72__PMS_C_CAN_20260425_FVS55R_INDEX)
			{
				CAND_0x380_ActiveRaw=1;
			}
			break;
		case 0x126:
			if(Can_valNodeId==CANIF_CHANNEL_N72__PMS_C_CAN_20260425_FVS55R_INDEX)
			{
				CAND_0x126_ActiveRaw=1;
			}
			break;
		case 0x1F9:
			if(Can_valNodeId==CANIF_CHANNEL_N72__PMS_C_CAN_20260425_FVS55R_INDEX)
			{
				CAND_0x1F9_ActiveRaw=1;
			}
			break;
		case 0x123:
			if(Can_valNodeId==CANIF_CHANNEL_N72__PMS_C_CAN_20260425_FVS55R_INDEX)
			{
				CAND_0x123_ActiveRaw=1;
			}
			break;	
		case 0x121:
			if(Can_valNodeId==CANIF_CHANNEL_N72__PMS_C_CAN_20260425_FVS55R_INDEX)
			{
				CAND_0x121_ActiveRaw=1;
			}
			break;
		case 0x124:
			if(Can_valNodeId==CANIF_CHANNEL_N72__PMS_C_CAN_20260425_FVS55R_INDEX)
			{
				CAND_0x124_ActiveRaw=1;
			}
			if(Can_valNodeId==CANIF_CHANNEL_N72_HCM__MATRIX_V1_1_LGFZID_INDEX)
			{
				CANG_0x124_ActiveRaw=1;
			}
			break;	
		case 0x120:
			if(Can_valNodeId==CANIF_CHANNEL_N72_HCM__MATRIX_V1_1_LGFZID_INDEX)
			{
				CANG_0x120_ActiveRaw=1;
			}
			break;
		case 0x0E0:
			if(Can_valNodeId==CANIF_CHANNEL_N72__PMS_C_CAN_20260425_FVS55R_INDEX)
			{
				CAND_0x0E0_ActiveRaw=1;
			}
			break;
		case 0x130:
			if(Can_valNodeId==CANIF_CHANNEL_N72__PMS_C_CAN_20260425_FVS55R_INDEX)
			{
				CAND_0x130_ActiveRaw=1;
			}
			break;	
		case 0x131:
			if(Can_valNodeId==CANIF_CHANNEL_N72__PMS_C_CAN_20260425_FVS55R_INDEX)
			{
				CAND_0x131_ActiveRaw=1;
			}
			break;			
		case 0x122:
			if(Can_valNodeId==CANIF_CHANNEL_N72_HCM__MATRIX_V1_1_LGFZID_INDEX)
			{
				CANG_0x122_ActiveRaw=1;
			}
			if(Can_valNodeId==CANIF_CHANNEL_N72__PMS_C_CAN_20260425_FVS55R_INDEX)
			{
				CAND_0x122_ActiveRaw=1;
			}
			break;
		case 0x1826F456:
			if(Can_valNodeId==CANIF_CHANNEL_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_10NGGJ_INDEX)
			{
				CANE_0x1826F456_ActiveRaw=1;
			}
			break;
		case 0x1801F456:
			if(Can_valNodeId==CANIF_CHANNEL_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_10NGGJ_INDEX)
			{
				CANE_0x1801F456_ActiveRaw=1;
			}
			break;
		case 0x100AF456:
			if(Can_valNodeId==CANIF_CHANNEL_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_10NGGJ_INDEX)
			{
				CANE_0x100AF456_ActiveRaw=1;
			}
			break;
		case 0x1812F456:
			if(Can_valNodeId==CANIF_CHANNEL_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_10NGGJ_INDEX)
			{
				CANE_0x1812F456_ActiveRaw=1;
			}
			break;
		case 0x1808F456:
			if(Can_valNodeId==CANIF_CHANNEL_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_10NGGJ_INDEX)
			{
				CANE_0x1808F456_ActiveRaw=1;
			}
			break;
		case 0x181DF456:
			if(Can_valNodeId==CANIF_CHANNEL_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_10NGGJ_INDEX)
			{
				CANE_0x181DF456_ActiveRaw=1;
			}
			break;
		case 0x101AF456:
			if(Can_valNodeId==CANIF_CHANNEL_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_10NGGJ_INDEX)
			{
				CANE_0x101AF456_ActiveRaw=1;
			}
			break;
		case 0x81FF456:
			if(Can_valNodeId==CANIF_CHANNEL_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_10NGGJ_INDEX)
			{
				CANE_0x81FF456_ActiveRaw=1;
			}
			break;
		case 0x3C3:
			if(Can_valNodeId==CANIF_CHANNEL_N72__PMS_PT_CANFD_20260425__XQC0B_INDEX)
			{
				CANB_0x3C3_ActiveRaw=1;
			}
			break;
		case 0x3CA:
			if(Can_valNodeId==CANIF_CHANNEL_N72__PMS_PT_CANFD_20260425__XQC0B_INDEX)
			{
				CANB_0x3CA_ActiveRaw=1;
			}
			break;
		case 0x220:
			if(Can_valNodeId==CANIF_CHANNEL_PMS_EV_CAN_20260427_RMXR12_INDEX)
			{
				CANA_0x220_ActiveRaw=1;
			}
			break;
		case 0x157:
			if(Can_valNodeId==CANIF_CHANNEL_PMS_EV_CAN_20260427_RMXR12_INDEX)
			{
				CANA_0x157_ActiveRaw=1;
			}
			break;
		case 0x247:
			if(Can_valNodeId==CANIF_CHANNEL_N72__PMS_PT_CANFD_20260425__XQC0B_INDEX)
			{
				CANB_0x247_ActiveRaw=1;
			}
			break;
		case 0x1E2:
			if(Can_valNodeId==CANIF_CHANNEL_N72__PMS_PT_CANFD_20260425__XQC0B_INDEX)
			{
				CANB_0x1E2_ActiveRaw=1;
			}
			break;

		case 0x2CF:
			if(Can_valNodeId==CANIF_CHANNEL_N72__PMS_C_CAN_20260425_FVS55R_INDEX)
			{
				CAND_0x2CF_ActiveRaw=1;
			}
			break;

		}

	}

	if(CAN_MsgActive_UpdateCounter<1001U)
	{
		CAN_MsgActive_UpdateCounter++;
	}	
	else
	{
		CAN_MsgActive_UpdateCounter=1;
	}

	if((CAN_MsgActive_UpdateCounter%1U)==0)
	{
		CANG_0x122_Active=CANG_0x122_ActiveRaw;
		CANG_0x122_ActiveRaw=0;
		
		CANG_0x128_Active=CANG_0x128_ActiveRaw;
		CANG_0x128_ActiveRaw=0;

		CANE_0x101AF456_Active=CANE_0x101AF456_ActiveRaw;
		CANE_0x101AF456_ActiveRaw=0;

		CANB_0x3C3_Active=CANB_0x3C3_ActiveRaw;
		CANB_0x3C3_ActiveRaw=0;

		CANG_0x124_Active=CANG_0x124_ActiveRaw;
		CANG_0x124_ActiveRaw=0;

		CANG_0x120_Active=CANG_0x120_ActiveRaw;
		CANG_0x120_ActiveRaw=0;

		CAND_0x0E0_Active=CAND_0x0E0_ActiveRaw;
		CAND_0x0E0_ActiveRaw=0;
	}
	if((CAN_MsgActive_UpdateCounter%2U)==0)
	{
		CAND_0x125_Active=CAND_0x125_ActiveRaw;
		CAND_0x125_ActiveRaw=0;

		CAND_0x128_Active=CAND_0x128_ActiveRaw;
		CAND_0x128_ActiveRaw=0;

		CAND_0x129_Active=CAND_0x129_ActiveRaw;
		CAND_0x129_ActiveRaw=0;

		CAND_0x126_Active=CAND_0x126_ActiveRaw;
		CAND_0x126_ActiveRaw=0;

		CAND_0x122_Active=CAND_0x122_ActiveRaw;
		CAND_0x122_ActiveRaw=0;

		CAND_0x1F9_Active=CAND_0x1F9_ActiveRaw;
		CAND_0x1F9_ActiveRaw=0;

		CAND_0x123_Active=CAND_0x123_ActiveRaw;
		CAND_0x123_ActiveRaw=0;

		CAND_0x121_Active=CAND_0x121_ActiveRaw;
		CAND_0x121_ActiveRaw=0;

		CAND_0x124_Active=CAND_0x124_ActiveRaw;
		CAND_0x124_ActiveRaw=0;

		CAND_0x130_Active=CAND_0x130_ActiveRaw;
		CAND_0x130_ActiveRaw=0;

		CAND_0x131_Active=CAND_0x131_ActiveRaw;
		CAND_0x131_ActiveRaw=0;

		CANA_0x145_Active=CANA_0x145_ActiveRaw;
		CANA_0x145_ActiveRaw=0;

		CANA_0x157_Active=CANA_0x157_ActiveRaw;
		CANA_0x157_ActiveRaw=0;

		CANB_0x1E2_Active=CANB_0x1E2_ActiveRaw;
		CANB_0x1E2_ActiveRaw=0;
	}
	if((CAN_MsgActive_UpdateCounter%5U)==0)
	{
		CANE_0x1812F456_Active=CANE_0x1812F456_ActiveRaw;
		CANE_0x1812F456_ActiveRaw=0;
	}
	if((CAN_MsgActive_UpdateCounter%10U)==0)
	{
		CANA_0x398_Active=CANA_0x398_ActiveRaw;
		CANA_0x398_ActiveRaw=0;

		CANE_0x1826F456_Active=CANE_0x1826F456_ActiveRaw;
		CANE_0x1826F456_ActiveRaw=0;

		CANE_0x1801F456_Active=CANE_0x1801F456_ActiveRaw;
		CANE_0x1801F456_ActiveRaw=0;

		CANE_0x100AF456_Active=CANE_0x100AF456_ActiveRaw;
		CANE_0x100AF456_ActiveRaw=0;

		CANE_0x1808F456_Active=CANE_0x1808F456_ActiveRaw;
		CANE_0x1808F456_ActiveRaw=0;

		CANE_0x181DF456_Active=CANE_0x181DF456_ActiveRaw;
		CANE_0x181DF456_ActiveRaw=0;

		CANE_0x81FF456_Active=CANE_0x81FF456_ActiveRaw;
		CANE_0x81FF456_ActiveRaw=0;

		CANB_0x3CA_Active=CANB_0x3CA_ActiveRaw;
		CANB_0x3CA_ActiveRaw=0;

		CANA_0x220_Active=CANA_0x220_ActiveRaw;
		CANA_0x220_ActiveRaw=0;

		CANB_0x247_Active=CANB_0x247_ActiveRaw;
		CANB_0x247_ActiveRaw=0;

		CAND_0x2CF_Active=CAND_0x2CF_ActiveRaw;
		CAND_0x2CF_ActiveRaw=0;
	}
	if((CAN_MsgActive_UpdateCounter%20U)==0)
	{
		CAND_0x380_Active=CAND_0x380_ActiveRaw;
		CAND_0x380_ActiveRaw=0;
	}
	if((CAN_MsgActive_UpdateCounter%50U)==0)
	{

	}
	if((CAN_MsgActive_UpdateCounter%100U)==0)
	{

	}
}