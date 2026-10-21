#include "PMS_Geely_Interface.h"
#include "CanBus_Configuration.h"
#include "ErrorDiag_CAN.h"
#include "Dcm_Lcfg.h"
#include "Com.h"
#include "Dcm.h"

extern boolean NVM_XCU_EEWriteFlgBlock54;
extern boolean NVM_XCU_EEWriteFinish;
extern boolean NVM_XCU_EEReadFinish;
extern boolean hvbd_b_tboxIntelChgCmdRaw;
extern boolean CANB_0x3C3_Active;
// extern VAR(uint64, RTE_VAR_INIT) Rte_ComBuffer_PEPS_IMMOCode_PEPS_IMMOCode_N72__PMS_PT_CANFD_20260425_dbc_Rx;

/*GlobalValueDefine*/
uint8 NVMBlock50Array[20] __attribute__((section(".ee_Block50_data")));
uint8 NVMBlock51Array[20] __attribute__((section(".ee_Block51_data")));
uint8 NVMBlock52Array[20] __attribute__((section(".ee_Block52_data")));
uint8 NVMBlock53Array[20] __attribute__((section(".ee_Block53_data")));
uint8 NVMBlock54Array[20] __attribute__((section(".ee_Block54_data")));

uint8 BSW_PEPS_IMMOCode[8]={0};
uint32 TotalMileageLastSaveData=0;

boolean NvmWrite_DSTNOSC_Flg=0;
boolean NvmWrite_DismantleCmd_Flg=0;
boolean NvmWrite_SpdLmtCmd_Flg=0;
boolean NvmWrite_PwrOffCmd_Flg=0;
boolean NvmWrite_InventoryCmd_Flg=0;
boolean NvmWrite_TboxDsmt_Flg=0;

uint8 CANB_0x3C3RecCounter=0;

uint8 PMS_EcuCtrl_SetShutDownReq=0;

boolean PMS_Auth_Req_CanSendFlg=0;
boolean PMS_Auth_Req_CanSendLastFlg=0;

uint64 PMS_PEPSAuth_Data=0;
uint64 PMS_ReqSeed_Data=0;
uint8 PMS_AuthResult_Data=0;
uint8 PMS_RespResult_Data=0;
uint8 PMS_OdoClrCntNum=0;

uint8 Geely_PMS_LinSwtSts = 0;/*0x0:No Request 0x1: Request Off 0x2:Request On*/
uint8 Geely_PMS_CANSwtSts = 0;/*0x0:No Request 0x1: Request Off 0x2:Request On*/
uint8 Geely_PMS_NmWkUp = 0;/*0x0:Sleep 0x1:WakeUp*/  

/*FuncForOther*/
void PMS_Geely_Interface(void)
{

}

/*Func_Geely_EEWrite*/
/*Block50DataStart*/
void mBSW_NvmWrite_DriMod(uint8 EwData)
{
    NVMBlock50Array[0]=EwData;
}
void mBSW_NvmWrite_RegenLvl(uint8 EwData)
{
    NVMBlock50Array[1]=EwData;
}
void mBSW_NvmWrite_RegenLvlEco(uint8 EwData)
{
    NVMBlock50Array[2]=EwData;
}
void mBSW_NvmWrite_RegenLvlSport(uint8 EwData)
{
    NVMBlock50Array[3]=EwData;
}
void mBSW_NvmWrite_Aec(float EwData)
{
    uint32 EwDataTemp;
    EwDataTemp=(uint32)(EwData*100U);
    NVMBlock50Array[4]=EwDataTemp;
    NVMBlock50Array[5]=EwDataTemp>>8;
    NVMBlock50Array[6]=EwDataTemp>>16;
    NVMBlock50Array[7]=EwDataTemp>>24;
}
void mBSW_NvmWrite_Odometer(float EwData)
{
    uint32 EwDataTemp;
    EwDataTemp=(uint32)(EwData*100U);
    NVMBlock50Array[8]=EwDataTemp;
    NVMBlock50Array[9]=EwDataTemp>>8;
    NVMBlock50Array[10]=EwDataTemp>>16;
    NVMBlock50Array[11]=EwDataTemp>>24;
}
/*Block50DataEnd*/

/*Block51DataStart*/
void mBSW_NvmWrite_stdRng(float EwData)
{
    uint32 EwDataTemp;
    EwDataTemp=(uint32)(EwData*100U);
    NVMBlock51Array[0]=EwDataTemp;
    NVMBlock51Array[1]=EwDataTemp>>8;
    NVMBlock51Array[2]=EwDataTemp>>16;
    NVMBlock51Array[3]=EwDataTemp>>24;
}
void mBSW_NvmWrite_FunFfg1Bak(uint32 EwData)
{
    NVMBlock51Array[8]=EwData;
    NVMBlock51Array[9]=EwData>>8;
    NVMBlock51Array[10]=EwData>>16;
    NVMBlock51Array[11]=EwData>>24;
}
void mBSW_NvmWrite_FunFfg2Bak(uint32 EwData)
{
    NVMBlock51Array[12]=EwData;
    NVMBlock51Array[13]=EwData>>8;
    NVMBlock51Array[14]=EwData>>16;
    NVMBlock51Array[15]=EwData>>24;
}
void mBSW_NvmWrite_NetFig1Bak(uint32 EwData)
{
    NVMBlock51Array[16]=EwData;
    NVMBlock51Array[17]=EwData>>8;
    NVMBlock51Array[18]=EwData>>16;
    NVMBlock51Array[19]=EwData>>24;
}
/*Block51DataEnd*/

/*Block52DataStart*/
void mBSW_NvmWrite_OdoClrCnt(uint8 EwData)
{
    NVMBlock52Array[0]=EwData;
    PMS_OdoClrCntNum = NVMBlock52Array[0];
}
void mBSW_NvmWrite_BrkSwtFltCnt(uint8 EwData)
{
    NVMBlock52Array[1]=EwData;
}
void mBSW_NvmWrite_Rdn(uint8 EwData)
{
    NVMBlock52Array[2]=EwData;
}
void mBSW_NvmWrite_KeyOnCnt(uint8 EwData)
{
    NVMBlock52Array[3]=EwData;
}
void mBSW_NvmWrite_BookChrgnTarVal_eep(uint16 EwData)
{
    NVMBlock52Array[4]=EwData;
    NVMBlock52Array[5]=EwData>>8;
}
void mBSW_NvmWrite_KeyOnCntRsvChrg(uint16 EwData)
{
    NVMBlock52Array[6]=EwData;
    NVMBlock52Array[7]=EwData>>8;
}
/*Block52DataEnd*/

/*Block53DataStart*/
void mBSW_NvmWrite_FunLockVehActiveReq(uint8 EwData)
{
    NVMBlock53Array[0]=EwData;
}
void mBSW_NvmWrite_FunAnti_DismantleActiveReq(uint8 EwData)
{
    NVMBlock53Array[1]=EwData;
}
void mBSW_NvmWrite_LockLimSetReq(uint8 EwData)
{
    NVMBlock53Array[2]=EwData;
}
void mBSW_NvmWrite_NormLockReq(uint8 EwData)
{
    NVMBlock53Array[3]=EwData;
}
void mBSW_NvmWrite_ChgLockReq(uint8 EwData)
{
    NVMBlock53Array[4]=EwData;
}
void mBSW_NvmWrite_ChgLockExcReq(uint8 EwData)
{
    NVMBlock53Array[5]=EwData;
}
void mBSW_NvmWrite_AntiLockReq(uint8 EwData)
{
    NVMBlock53Array[6]=EwData;
}
void mBSW_NvmWrite_ExcLockVehResultsOldReq(uint8 EwData)
{
    NVMBlock53Array[7]=EwData;
}
void mBSW_NvmWrite_NormLockActv(uint8 EwData)
{
    NVMBlock53Array[8]=EwData;
}
void mBSW_NvmWrite_ExeStsUpdate(uint8 EwData)
{
    NVMBlock53Array[9]=EwData;
}
void mBSW_NvmWrite_ExeStsUpdate1(uint8 EwData)
{
    NVMBlock53Array[10]=EwData;
}
void mBSW_NvmWrite_DSTNOSC_eep(uint8 EwData)
{
    NVMBlock53Array[11]=EwData;
    NvmWrite_DSTNOSC_Flg=1;
}
void mBSW_NvmWrite_DismantleCmd_eep(uint8 EwData)
{
    NVMBlock53Array[12]=EwData;
    NvmWrite_DismantleCmd_Flg=1;
}
void mBSW_NvmWrite_SpdLmtCmd_eep(uint8 EwData)
{
    NVMBlock53Array[13]=EwData;
    NvmWrite_SpdLmtCmd_Flg=1;
}
void mBSW_NvmWrite_PwrOffCmd_eep(uint8 EwData)
{
    NVMBlock53Array[14]=EwData;
    NvmWrite_PwrOffCmd_Flg=1;
}
void mBSW_NvmWrite_InventoryCmd_eep(uint8 EwData)
{
    NVMBlock53Array[15]=EwData;
    NvmWrite_InventoryCmd_Flg=1;
}
void mBSW_NvmWrite_TboxDsmt_eep(uint8 EwData)
{
    NVMBlock53Array[16]=EwData;
    NvmWrite_TboxDsmt_Flg=1;
}
/*Block53DataEnd*/

/*Block54DataStart*/
void mBSW_NvmWrite_Odometer_u32(uint32 EwData)
{
    NVMBlock54Array[0]=EwData;
    NVMBlock54Array[1]=EwData>>8;
    NVMBlock54Array[2]=EwData>>16;
    NVMBlock54Array[3]=EwData>>24;

    if((uint32)(EwData-TotalMileageLastSaveData)>5)
    {
    	NVM_XCU_EEWriteFlgBlock54=1;
    	TotalMileageLastSaveData=EwData;
    }
}
void mBSW_NvmWrite_RmlkIgOnCnt(uint32 EwData)
{
    NVMBlock54Array[4]=EwData;
    NVMBlock54Array[5]=EwData>>8;
    NVMBlock54Array[6]=EwData>>16;
    NVMBlock54Array[7]=EwData>>24;

    NVM_XCU_EEWriteFlgBlock54=1;
}
void mBSW_NvmWrite_FlashCnt(uint32 EwData)
{
    NVMBlock54Array[8]=EwData;
    NVMBlock54Array[9]=EwData>>8;
    NVMBlock54Array[10]=EwData>>16;
    NVMBlock54Array[11]=EwData>>24;

    NVM_XCU_EEWriteFlgBlock54=1;
}
/*Block54DataEnd*/

/*Func_Geely_EERead*/
/*Block50DataStart*/
uint8 mBSW_NvmRead_DriMod(void)
{
    return NVMBlock50Array[0];
}
uint8 mBSW_NvmRead_RegenLvl(void)
{
	return NVMBlock50Array[1];
}
uint8 mBSW_NvmRead_RegenLvlEco(void)
{
	return NVMBlock50Array[2];
}
uint8 mBSW_NvmRead_RegenLvlSport(void)
{
	return NVMBlock50Array[3];
}
float mBSW_NvmRead_Aec(void)
{
    float EEReadTemp;
    EEReadTemp=((float)(NVMBlock50Array[4])
    +(float)((uint32)NVMBlock50Array[5]<<8)
    +(float)((uint32)NVMBlock50Array[6]<<16)
    +(float)((uint32)NVMBlock50Array[7]<<24))*0.01F;
    return EEReadTemp;
}
float mBSW_NvmRead_Odometer(void)
{
    float EEReadTemp;
    EEReadTemp=((float)(NVMBlock50Array[8])
    +(float)((uint32)NVMBlock50Array[9]<<8)
    +(float)((uint32)NVMBlock50Array[10]<<16)
    +(float)((uint32)NVMBlock50Array[11]<<24))*0.01F;
    return EEReadTemp;
}
/*Block50DataEnd*/

/*Block51DataStart*/
float mBSW_NvmRead_stdRng(void)
{
    float EEReadTemp;
    EEReadTemp=((float)(NVMBlock51Array[0])
    +(float)((uint32)NVMBlock51Array[1]<<8)
    +(float)((uint32)NVMBlock51Array[2]<<16)
    +(float)((uint32)NVMBlock51Array[3]<<24))*0.01F;
    return EEReadTemp;
}
uint32 mBSW_NvmRead_FunFfg1Bak(void)
{
    uint32 EEReadTemp;
    EEReadTemp=(uint32)(NVMBlock51Array[8])
    +(uint32)((uint32)NVMBlock51Array[9]<<8)
    +(uint32)((uint32)NVMBlock51Array[10]<<16)
    +(uint32)((uint32)NVMBlock51Array[11]<<24);
    return EEReadTemp;
}
uint32 mBSW_NvmRead_FunFfg2Bak(void)
{
    uint32 EEReadTemp;
    EEReadTemp=(uint32)(NVMBlock51Array[12])
    +(uint32)((uint32)NVMBlock51Array[13]<<8)
    +(uint32)((uint32)NVMBlock51Array[14]<<16)
    +(uint32)((uint32)NVMBlock51Array[15]<<24);
    return EEReadTemp;
}
uint32 mBSW_NvmRead_NetFig1Bak(void)
{
    uint32 EEReadTemp;
    EEReadTemp=(uint32)(NVMBlock51Array[16])
    +(uint32)((uint32)NVMBlock51Array[17]<<8)
    +(uint32)((uint32)NVMBlock51Array[18]<<16)
    +(uint32)((uint32)NVMBlock51Array[19]<<24);
    return EEReadTemp;
}
/*Block51DataEnd*/

/*Block52DataStart*/
uint8 mBSW_NvmRead_OdoClrCnt(void)
{
    PMS_OdoClrCntNum = NVMBlock52Array[0];
	return NVMBlock52Array[0];
}
uint8 mBSW_NvmRead_BrkSwtFltCnt(void)
{
	return NVMBlock52Array[1];
}
uint8 mBSW_NvmRead_Rdn(void)
{
	return NVMBlock52Array[2];
}
uint8 mBSW_NvmRead_KeyOnCnt(void)
{
    return NVMBlock52Array[3];
}
uint16 mBSW_NvmRead_BookChrgnTarVal_eep(void)
{
	return (NVMBlock52Array[4]+(uint16)(NVMBlock52Array[5]<<8));
}
uint16 mBSW_NvmRead_KeyOnCntRsvChrg(void)
{
	return (NVMBlock52Array[6]+(uint16)(NVMBlock52Array[7]<<8));
}
/*Block52DataEnd*/

/*Block53DataStart*/
uint8 mBSW_NvmRead_FunLockVehActiveReq(void)
{
        return NVMBlock53Array[0];     
}
uint8 mBSW_NvmRead_FunAnti_DismantleActiveReq(void)
{
	return NVMBlock53Array[1];
}
uint8 mBSW_NvmRead_LockLimSetReq(void)
{
	return NVMBlock53Array[2];
}
uint8 mBSW_NvmRead_NormLockReq(void)
{
	return NVMBlock53Array[3];
}
uint8 mBSW_NvmRead_ChgLockReq(void)
{
	return NVMBlock53Array[4];
}
uint8 mBSW_NvmRead_ChgLockExcReq(void)
{
	return NVMBlock53Array[5];
}
uint8 mBSW_NvmRead_AntiLockReq(void)
{
	return NVMBlock53Array[6];
}
uint8 mBSW_NvmRead_NormLockActv(void)
{
	return NVMBlock53Array[8];
}
uint8 mBSW_NvmRead_ExeStsUpdate(void)
{
	return NVMBlock53Array[9];
}
uint8 mBSW_NvmRead_ExeStsUpdate1(void)
{
	return NVMBlock53Array[10];
}
uint8 mBSW_NvmRead_DSTNOSC_eep(void)
{
    uint8 EEReadTemp;
    if (NVMBlock53Array[11]==0U)
    {
        EEReadTemp=3U;
    }
    else
    {
       EEReadTemp=NVMBlock53Array[11];
    }
    return EEReadTemp;
}
uint8 mBSW_NvmRead_DismantleCmd_eep(void)
{
    uint8 EEReadTemp;
    if (NVMBlock53Array[12]==0U)
    {
        EEReadTemp=3U;
    }
    else
    {
       EEReadTemp=NVMBlock53Array[12];
    }
    return EEReadTemp;
}
uint8 mBSW_NvmRead_SpdLmtCmd_eep(void)
{
    uint8 EEReadTemp;
    if (NVMBlock53Array[13]==0U)
    {
        EEReadTemp=3U;
    }
    else
    {
       EEReadTemp=NVMBlock53Array[13];
    }
    return EEReadTemp;
}
uint8 mBSW_NvmRead_PwrOffCmd_eep(void)
{
	return NVMBlock53Array[14];
}
uint8 mBSW_NvmRead_InventoryCmd_eep(void)
{
    uint8 EEReadTemp;
    if (NVMBlock53Array[15]==0U)
    {
        EEReadTemp=3U;
    }
    else
    {
       EEReadTemp=NVMBlock53Array[15];
    }
    return EEReadTemp;
}
uint8 mBSW_NvmRead_TboxDsmt_eep(void)
{
	return NVMBlock53Array[16];
}
/*Block53DataEnd*/

/*Block54DataStart*/
uint32 mBSW_NvmRead_Odometer_u32(void)
{
    uint32 EEReadTemp;
    EEReadTemp=(uint32)(NVMBlock54Array[0])
    +(uint32)((uint32)NVMBlock54Array[1]<<8)
    +(uint32)((uint32)NVMBlock54Array[2]<<16)
    +(uint32)((uint32)NVMBlock54Array[3]<<24);
    return EEReadTemp;
}
uint32 mBSW_NvmRead_RmlkIgOnCnt(void)
{
    uint32 EEReadTemp;
    EEReadTemp=(uint32)(NVMBlock54Array[4])
    +(uint32)((uint32)NVMBlock54Array[5]<<8)
    +(uint32)((uint32)NVMBlock54Array[6]<<16)
    +(uint32)((uint32)NVMBlock54Array[7]<<24);
    return EEReadTemp;
}
uint32 mBSW_NvmRead_FlashCnt(void)
{
    uint32 EEReadTemp;
    EEReadTemp=(uint32)(NVMBlock54Array[8])
    +(uint32)((uint32)NVMBlock54Array[9]<<8)
    +(uint32)((uint32)NVMBlock54Array[10]<<16)
    +(uint32)((uint32)NVMBlock54Array[11]<<24);
    return EEReadTemp;
}
/*Block54DataEnd*/

/*Func_Geely_EEOperationFb*/
 boolean mBSW_NvmRead_OdoClrCnt_flg(void)
 {
	return 0;
 }
void mBSW_Get_PMS_ESK(uint8 *EEReadData)
{
	uint8 i=0;

    for(i=0; i<16U;i++)
    {
        EEReadData[i]=Dcm_Did_Block009E_Data.Dcm_Did0280Buffer[i];
    }
}
uint8 mBSW_NvmRead_DSTNOSC_retval(void)
{
    uint8 Temp = 0;
	Temp=NvmWrite_DSTNOSC_Flg;
	NvmWrite_DSTNOSC_Flg=0;
    return Temp;
}
uint8 mBSW_NvmRead_DismantleCmd_eep_retval(void)
{
    uint8 Temp = 0;
	Temp=NvmWrite_DismantleCmd_Flg;
	NvmWrite_DismantleCmd_Flg=0;
    return Temp;
}
uint8 mBSW_NvmRead_SpdLmtCmd_eep_retval(void)
{
    uint8 Temp = 0;
	Temp=NvmWrite_SpdLmtCmd_Flg;
	NvmWrite_SpdLmtCmd_Flg=0;
    return Temp;
}
uint8 mBSW_NvmRead_PwrOffCmd_eep_retval(void)
{
    uint8 Temp = 0;
	Temp=NvmWrite_PwrOffCmd_Flg;
	NvmWrite_PwrOffCmd_Flg=0;
    return Temp;
}
uint8 mBSW_NvmRead_InventoryCmd_eep_retval(void)
{
    uint8 Temp = 0;
	Temp=NvmWrite_InventoryCmd_Flg;
	NvmWrite_InventoryCmd_Flg=0;
    return Temp;
}
uint8 mBSW_NvmRead_TboxDsmt_eep_retval(void)
{
    uint8 Temp = 0;
	Temp=NvmWrite_TboxDsmt_Flg;
	NvmWrite_TboxDsmt_Flg=0;
    return Temp;
}

/*Func_Geely_BSWASW*/

void SwSA_flgComRxTout_BBM_StsFB_EV(boolean *Data)
{
	Data[0]=CANB_0x247_Active;
}

void mBSW_Get_PEPS_IMMOCode(uint8 *Data)
{
	for(uint8 i=0; i<8U;i++)
	{
		//  Data[i]=(uint8)(((uint64)(Rte_ComBuffer_PEPS_IMMOCode_PEPS_IMMOCode_N72__PMS_PT_CANFD_20260425_dbc_Rx))>>((7U-i)*8U));

	}
}
void mBSW_Get_TBOX_Key(uint8 *Data)
{
	for(uint8 i=0; i<8U;i++)
	{
		//  Data[i]=(uint8)(((uint64)(Rte_ComBuffer_TBOX_Key_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx))>>((7U-i)*8U));

	}

}
uint8 mBSW_ReceiveCtr_TBOX_Key(void)
{
    if (CANB_0x3C3RecCounter>=255U)
    {
        CANB_0x3C3RecCounter=0;
    }
    if(CANB_0x3C3_Active==1U)
    {
        CANB_0x3C3RecCounter++;
    }

    return CANB_0x3C3RecCounter;
}



void Sws_EcuCtrl_SetShutDownType(uint8 Data)
{
	PMS_EcuCtrl_SetShutDownReq=Data;
}

void mBSW_Set_PMS_Auth_Req(uint8 *Data)
{
	uint8 i;
	boolean PMS_Auth_Req_Flg=0;

	PMS_PEPSAuth_Data=0;

	for(i=0;i<8U;i++)
	{
		if((Data[i]==1U))
		{
			PMS_Auth_Req_Flg = 1;
		}
		PMS_PEPSAuth_Data=PMS_PEPSAuth_Data+((uint64)(Data[i]))<<((7U-i)*8U);
	}
	if((PMS_Auth_Req_Flg==1U)&&(PMS_Auth_Req_CanSendLastFlg==0U))
	{
		PMS_Auth_Req_CanSendFlg=1;
		PMS_Auth_Req_CanSendLastFlg=PMS_Auth_Req_CanSendFlg;
	}
	else if(PMS_Auth_Req_Flg==0U)
	{
		PMS_Auth_Req_CanSendFlg=0;
		PMS_Auth_Req_CanSendLastFlg=PMS_Auth_Req_CanSendFlg;
	}

	if(PMS_Auth_Req_CanSendFlg==1U)
	{
		Com_SendSignal(COMCONF_COMSIGNAL_PMS_PEPSAUTH_RMXR12_PMS_PEPSAUTH_PMS_PEPSAUTH_PMS_EV_CAN_20260427_DBC_TX, &PMS_PEPSAuth_Data);
		Com_SendSignal(COMCONF_COMSIGNAL_PMS_PEPSAUTH__XQC0B_PMS_PEPSAUTH_PMS_PEPSAUTH_N72__PMS_PT_CANFD_20260425_DBC_TX, &PMS_PEPSAuth_Data);
	}


}
void mBSW_Set_PMS_AuthResult(uint8* Data)
{
	PMS_AuthResult_Data=Data[0];
}
void mBSW_Set_PMS_RespResult(uint8* Data)
{
	PMS_RespResult_Data=Data[0];
}
void mBSW_Set_PMS_ReqSeed(uint8 *Data)
{
	uint8 i;

	PMS_ReqSeed_Data=0;

	for(i=0;i<7U;i++)
	{
		PMS_ReqSeed_Data=PMS_ReqSeed_Data+((uint64)(Data[i]))<<((6U-i)*8U);
	}

}
void mBSW_Set_aswAuthUpdate(uint8* Data)
{

	if(Data[0]==1U)
	{
	    Com_SendSignal(COMCONF_COMSIGNAL_PMS_AUTH__XQC0B_PMS_AUTHRESULT_PMS_AUTH_N72__PMS_PT_CANFD_20260425_DBC_TX, &PMS_RespResult_Data);

	    Com_SendSignal(COMCONF_COMSIGNAL_PMS_AUTH__XQC0B_PMS_REQSEED_PMS_AUTH_N72__PMS_PT_CANFD_20260425_DBC_TX, &PMS_ReqSeed_Data);

	    Com_SendSignal(COMCONF_COMSIGNAL_PMS_AUTH__XQC0B_PMS_RESPRESULT_PMS_AUTH_N72__PMS_PT_CANFD_20260425_DBC_TX, &PMS_AuthResult_Data);
	}

}
uint8 uds_GetActiveSession(void)
{
    uint8 SeviceNumGet = Dcm_RepeatedProxyContexts.Dcm_10_ProxyContext.Dcm_ServiceNum;
    uint8 SessionDataTemp = 0;
    SessionDataTemp=(Dcm_10_Dispatcher.Dcm_ServiceInfoTable[SeviceNumGet].Dcm_CurSession)+1;
    return SessionDataTemp;
}
void mBSW_SetHvShutDnResult(uint8* Data)
{
    Dcm_RoutineResult_03E0 = Data[0];
}
void mBSW_SetRoutineResult_03E1(uint8* Data)
{
    Dcm_RoutineResult_03E1 = Data[0];
}
void mBSW_LinSwtOff(void)
{
    Geely_PMS_LinSwtSts = 1;
}
void mBSW_CanSwtOff(void)
{
    Geely_PMS_CANSwtSts = 1;
}
void mBSW_LinSwtOn(void)
{
    Geely_PMS_LinSwtSts = 2;
}
void mBSW_CanSwtOn(void)
{
    Geely_PMS_CANSwtSts = 2;
}
boolean mBSW_RoutineReq_03E4(void)
{
    boolean RetVal = 0;
    RetVal = Dcm_RoutineReq_03E4;
    return RetVal;
}
void mBSW_SetRoutineResult_03E4(uint8 Data)
{
    Dcm_RoutineResult_03E4 = Data;
}
boolean mBSW_HvShutDnReq(void)
{
    boolean RetVal = 0;
    RetVal = Dcm_RoutineReq_03E0;
    return RetVal;
}
boolean mBSW_RoutineReq_03E1(void)
{
    boolean RetVal = 0;
    RetVal = Dcm_RoutineReq_03E1;
    return RetVal;
}
boolean mBSW_NmWkUp(void)
{
    boolean RetVal = 0;
    RetVal = Geely_PMS_NmWkUp;
    return RetVal;
}
void mBSW_SetHvShutDnFailResult(uint8 Data)
{
    Dcm_RoutineFailResult_03E0 = Data;
}
void mBSW_SetHvONFailResult(uint8 Data)
{
    Dcm_RoutineFailResult_03E1 = Data;
}

void mBSW_SetOTAVehSpd(float Data)
{

}