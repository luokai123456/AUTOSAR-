/*** create info ***********************
*@ Author : wangjiacheng
*@ date :2025-12-04
*@ Description :CAN device functions
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : 
*@ date :2025-12-04
*@ Modification Description :
初始版本
****************************************/

/*========================================== Includes ================================================*/
#include "Can_Device_Prv.h"
#include "Evpt_InterDataWatch_Prv.h"
/*========================================== Global Variables ========================================*/
struct CanController CD_valDevice_Mp = {0, {0}};
static uint8 Can_Device_GetRegStatus(uint8 Can_valControllerId, uint32 Can_valMask, uint8 Can_valShift)
{
    return (uint8)((CD_valDevice_Mp.ctrl[Can_valControllerId].info.status_reg & Can_valMask) >> Can_valShift);
}

#ifndef CAN_TEST_CFG_H_
uint8 Can_Device_NodeMap[CAN_CTRL_NUM_MAX] = {
    CanController_A,
    CanController_B,
    CanController_D,
	CanController_E,
    CanController_F,
	CanController_G,
};
#else
uint8 Can_Device_NodeMap[CAN_CTRL_NUM_MAX] = {
    CanController_A,
    CanController_B,
	CanController_C,
    CanController_D,
	CanController_E,
    CanController_F,
	CanController_G,
};
#endif


/*========================================== Internal Interface ========================================*/

void CAN_Device_MainFunction(void)
{
	uint8 CD_valNode_Lo = 0,CD_MapNode_Lo = 0;
	uint32 CD_valCoreId_Lo = 0U;
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) 	base = NULL_PTR;
	uint8 CD_CanDiagdata_BUSOFF_Lo[CAN_CTRL_NUM_MAX] = {0};
	uint8 CD_CanDiagdata_ERROR_WARNING_Lo[CAN_CTRL_NUM_MAX] = {0};
	uint8 CD_CanDiagdata_ERROR_PASSIVE_Lo[CAN_CTRL_NUM_MAX] = {0};
	uint8 CD_CanDiagdata_BUS_ERROR_Lo[CAN_CTRL_NUM_MAX] = {0};
	uint8 CD_CanDiagdata_CAN_MODE_Lo[CAN_CTRL_NUM_MAX] = {0};
	uint8 CD_CanDiagdata_CAN_RUN_STATE_Lo[CAN_CTRL_NUM_MAX] = {0};
	for(; CD_valNode_Lo < CAN_CTRL_NUM_MAX; CD_valNode_Lo++)
	{
		base = g_mcanBase[CD_valCanIndex_Mp[CD_valNode_Lo]];
		CD_valDevice_Mp.ctrl[CD_valNode_Lo].info.status_reg = base->PSR.R;

		SetActive(&CD_valDevice_Mp.ctrl[CD_valNode_Lo].state, 0);
		CD_CanDiagdata_CAN_MODE_Lo[CD_valNode_Lo] = Mcan_ControllerConfigs[Can_Device_NodeMap[CD_valNode_Lo]].mcanMode;
		CD_CanDiagdata_BUSOFF_Lo[CD_valNode_Lo] = CAN_Device_GetBusOffStatus(CD_valNode_Lo);
		CD_CanDiagdata_ERROR_WARNING_Lo[CD_valNode_Lo] = CAN_Device_GetErrWarnStatus(CD_valNode_Lo);
		CD_CanDiagdata_ERROR_PASSIVE_Lo[CD_valNode_Lo] = CAN_Device_GetErrPassiveStatus(CD_valNode_Lo);
		CD_CanDiagdata_BUS_ERROR_Lo[CD_valNode_Lo] = CAN_Device_GetBusErrStatus(CD_valNode_Lo);
		CD_CanDiagdata_CAN_RUN_STATE_Lo[CD_valNode_Lo] = (base->PSR.R & MCAN_PSR_ACT_MASK) >> MCAN_PSR_ACT_SHIFT;		
	}
	Evpt_DiagDb_SetValue(DIAG_VAR_CAN_BUSOFF_STATE, CD_CanDiagdata_BUSOFF_Lo, sizeof(uint8) * CAN_CTRL_NUM_MAX);
	Evpt_DiagDb_SetValue(DIAG_VAR_CAN_ERROR_WARNING, CD_CanDiagdata_ERROR_WARNING_Lo, sizeof(uint8) * CAN_CTRL_NUM_MAX);
	Evpt_DiagDb_SetValue(DIAG_VAR_CAN_ERROR_PASSIVE, CD_CanDiagdata_ERROR_PASSIVE_Lo, sizeof(uint8) * CAN_CTRL_NUM_MAX);
	Evpt_DiagDb_SetValue(DIAG_VAR_CAN_BUS_ERROR, CD_CanDiagdata_BUS_ERROR_Lo, sizeof(uint8) * CAN_CTRL_NUM_MAX);
	Evpt_DiagDb_SetValue(DIAG_VAR_CAN_WORK_MODE, CD_CanDiagdata_CAN_MODE_Lo, sizeof(uint8) * CAN_CTRL_NUM_MAX);
	Evpt_DiagDb_SetValue(DIAG_VAR_CAN_RUN_STATE, CD_CanDiagdata_CAN_RUN_STATE_Lo, sizeof(uint8) * CAN_CTRL_NUM_MAX);
}

void CAN_Device_NetMangeIdConfig(uint8 Can_valControllerId, uint32 Can_valIdMin, uint32 Can_valIdMax)
{
	CD_valDevice_Mp.ctrl[Can_valControllerId].info.rx_nm_id_max = Can_valIdMax;
	CD_valDevice_Mp.ctrl[Can_valControllerId].info.rx_nm_id_min = Can_valIdMin;
}

void CAN_Device_ReceiveNetMangeMessage(uint8 Can_valControllerId, uint32* Can_valMsgId, Can_ReceiveObjNew* Can_valRecObjNew)
{
	*Can_valMsgId = CD_valDevice_Mp.ctrl[Can_valControllerId].info.prior_nm_frame_id;
	*Can_valRecObjNew = CD_valDevice_Mp.ctrl[Can_valControllerId].mailbox.slots[CAN_NETMANGE_CHANNEL].frame;
	CD_valDevice_Mp.ctrl[Can_valControllerId].mailbox.slots[CAN_NETMANGE_CHANNEL].frame.receive_active = 0;
}

uint8 CAN_Device_GetBusOffStatus(uint8 Can_valControllerId)
{
	uint8 CD_valStat_Lo;
	
	CD_valStat_Lo = Can_Device_GetRegStatus(Can_valControllerId, MCAN_PSR_BO_MASK, MCAN_PSR_BO_SHIFT);

	return CD_valStat_Lo;
}

void CAN_Device_BusOffRecover(uint8 Can_valControllerId)
{
	SetBusOff(&CD_valDevice_Mp.ctrl[Can_valControllerId].state, 1);
}

uint8 CAN_Device_GetErrWarnStatus(uint8 Can_valControllerId)
{
	return Can_Device_GetRegStatus(Can_valControllerId, MCAN_PSR_EW_MASK, MCAN_PSR_EW_SHIFT);
}

uint8 CAN_Device_GetErrPassiveStatus(uint8 Can_valControllerId)
{
	return Can_Device_GetRegStatus(Can_valControllerId, MCAN_PSR_EP_MASK, MCAN_PSR_EP_SHIFT);
}

uint8 CAN_Device_GetBusErrStatus(uint8 Can_valControllerId)
{
	uint8 CD_valBusErrStat_Lo = 0;
	static uint8 CD_Last_valBusErrStat_Lo[CAN_CTRL_NUM_MAX] = {0};

	CD_valBusErrStat_Lo = Can_Device_GetRegStatus(Can_valControllerId, MCAN_PSR_LEC_MASK, MCAN_PSR_LEC_SHIFT);
	
	if(CD_valBusErrStat_Lo == 0x7)
	{
		return CD_Last_valBusErrStat_Lo[Can_valControllerId];
	}

	CD_Last_valBusErrStat_Lo[Can_valControllerId] = CD_valBusErrStat_Lo;

	return CD_valBusErrStat_Lo;
}
Std_ReturnType CAN_TransmitFrame(uint8 Can_valControllerId, uint8 Can_valMailBoxId, Can_SendObjNew *Can_valSendObjNew)
{
	Std_ReturnType 	CD_valRetVal_Lo  = E_NOT_OK;	
	Can_PduType canPduInfo;
	
	if(Can_valMailBoxId >= CAN_TX_MAIL_BOX_MAX){
		return CD_valRetVal_Lo;
	}
	else if( NULL_PTR == Can_valSendObjNew){
        return CD_valRetVal_Lo;
    }

	Can_valMailBoxId += Can_valControllerId * 32;

	if(Can_valSendObjNew->is_ext)
	{
		Can_valSendObjNew->message_id = CANIF_EXTENDED_CANID_TYPE | Can_valSendObjNew->message_id;
	}
	else
	{
		Can_valSendObjNew->message_id = CANIF_STANDARD_CANID_TYPE | Can_valSendObjNew->message_id;
	}

#if CANFD_SUPPORT
	if(Can_valSendObjNew->is_fd){
		Can_valSendObjNew->message_id = CANIF_STANDARD_FD_CANID_TYPE | Can_valSendObjNew->message_id;
	}
#endif

    canPduInfo.length = Can_valSendObjNew->data_size;
    canPduInfo.id = Can_valSendObjNew->message_id;
    canPduInfo.swPduHandle = Can_valMailBoxId;
    canPduInfo.sdu = &Can_valSendObjNew->send_data[0];
	CD_valRetVal_Lo = Can_Write(Can_valMailBoxId, &canPduInfo);


	return CD_valRetVal_Lo;
}
void CAN_Device_CancelDataTransmit(uint8 Can_valControllerId, uint8 Can_valTxBuffIdx, uint8 Can_valCanCelEn)
{
	uint32 CT_valMask_Lo = 1 << Can_valTxBuffIdx;

	CD_valDevice_Mp.ctrl[Can_valControllerId].info.cancel_req =
			Can_valCanCelEn ? (CD_valDevice_Mp.ctrl[Can_valControllerId].info.cancel_req | CT_valMask_Lo) :(CD_valDevice_Mp.ctrl[Can_valControllerId].info.cancel_req & ~CT_valMask_Lo);
}

void CAN_Device_SwitchControllerMode(uint8 Can_valControllerId, uint8 Can_valTurnOff)
{
}

void CAN_Device_StopChannlTx(uint8 Can_valControllerId, uint32 Can_valChannlMask)
{
	CD_valDevice_Mp.ctrl[Can_valControllerId].info.silence_req = Can_valChannlMask;
}

uint8 CAN_Device_GetReceiveActiveInf(uint8 Can_valControllerId)
{
	return IsActive(CD_valDevice_Mp.ctrl[Can_valControllerId].state);
}
