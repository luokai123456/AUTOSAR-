/*** create info ***********************
*@ Author : wangjiacheng
*@ date :2025-12-04
*@ Description :CAN interface functions
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : 
*@ date :2025-12-04
*@ Modification Description :
初始版本
****************************************/

#include "Can_Device_Prv.h"
#include "string.h"
/*========================================== Macro ================================================*/
#define SAFE_CALL(ctrlId, funcName, ...) \
	do { \
		if ((ctrlId) < CAN_CTRL_NUM_MAX && \
			CD_valCanTransmit_Fctp_Mp[ctrlId].funcName != NULL_PTR) { \
			CD_valCanTransmit_Fctp_Mp[ctrlId].funcName(__VA_ARGS__); \
		} \
	} while(0)

#define SAFE_CALL_RET(ctrlId, funcName, retVar, ...) \
	do { \
		if ((ctrlId) < CAN_CTRL_NUM_MAX && \
			CD_valCanTransmit_Fctp_Mp[ctrlId].funcName != NULL_PTR) { \
			*(retVar) = CD_valCanTransmit_Fctp_Mp[ctrlId].funcName(__VA_ARGS__); \
		} \
	} while(0)

/*========================================== external Interface ========================================*/


Std_ReturnType Com_CanIfE_SendFunction(uint8 Can_valMailBoxId, Can_SendObjNew* Can_valSendObjNew)
{
	Std_ReturnType CT_valRet_Lo = E_OK;

	if(!IsFrameValid(Can_valSendObjNew)){
		return E_NOT_OK;
	}

	CT_valRet_Lo = CAN_TransmitFrame(Can_Device_NodeMap[CanController_E], Can_valMailBoxId, Can_valSendObjNew);

	return CT_valRet_Lo;
}



Std_ReturnType Com_CanIfF_SendFunction(uint8 Can_valMailBoxId, Can_SendObjNew* Can_valSendObjNew)
{
	Std_ReturnType CT_valRet_Lo = E_OK;

	if(!IsFrameValid(Can_valSendObjNew)){
		return E_NOT_OK;
	}

	CT_valRet_Lo = CAN_TransmitFrame(Can_Device_NodeMap[CanController_F], Can_valMailBoxId, Can_valSendObjNew);

	return CT_valRet_Lo;
}


Std_ReturnType Com_CanIfB_SendFunction(uint8 Can_valMailBoxId, Can_SendObjNew* Can_valSendObjNew)
{
	Std_ReturnType CT_valRet_Lo = E_OK;

	if(!IsFrameValid(Can_valSendObjNew)){
		return E_NOT_OK;
	}

	CT_valRet_Lo = CAN_TransmitFrame(Can_Device_NodeMap[CanController_B], Can_valMailBoxId, Can_valSendObjNew);

	return CT_valRet_Lo;
}

#ifndef CAN_TEST_CFG_H_

#else
Std_ReturnType Com_CanIfC_SendFunction(uint8 Can_valMailBoxId, Can_SendObjNew* Can_valSendObjNew)
{
	Std_ReturnType CT_valRet_Lo = E_OK;

	if(!IsFrameValid(Can_valSendObjNew)){
		return E_NOT_OK;
	}


	CT_valRet_Lo = CAN_TransmitFrame(Can_Device_NodeMap[CanController_C], Can_valMailBoxId, Can_valSendObjNew);

	return CT_valRet_Lo;
}
#endif



Std_ReturnType Com_CanIfA_SendFunction(uint8 Can_valMailBoxId, Can_SendObjNew* Can_valSendObjNew)
{
	Std_ReturnType CT_valRet_Lo = E_OK;

	if(!IsFrameValid(Can_valSendObjNew)){
		return E_NOT_OK;
	}

	CT_valRet_Lo = CAN_TransmitFrame(Can_Device_NodeMap[CanController_A], Can_valMailBoxId, Can_valSendObjNew);

	return CT_valRet_Lo;
}



Std_ReturnType Com_CanIfD_SendFunction(uint8 Can_valMailBoxId, Can_SendObjNew* Can_valSendObjNew)
{
	Std_ReturnType CT_valRet_Lo = E_OK;

	if(!IsFrameValid(Can_valSendObjNew)){
		return E_NOT_OK;
	}

	CT_valRet_Lo = CAN_TransmitFrame(Can_Device_NodeMap[CanController_D], Can_valMailBoxId, Can_valSendObjNew);

	return CT_valRet_Lo;
}


Std_ReturnType Com_CanIfG_SendFunction(uint8 Can_valMailBoxId, Can_SendObjNew* Can_valSendObjNew)
{
	Std_ReturnType CT_valRet_Lo = E_OK;

	if(!IsFrameValid(Can_valSendObjNew)){
		return E_NOT_OK;
	}

	CT_valRet_Lo = CAN_TransmitFrame(Can_Device_NodeMap[CanController_G], Can_valMailBoxId, Can_valSendObjNew);

	return CT_valRet_Lo;
}

uint8 CT_valModePtr_Mp[CAN_NODE_MAX] = {0};//每个CAN节点的当前工作模式
/**
 * 函数名称: Com_CanSm_SwitchControllerMode
 * 参数in: Can_valControllerId 0:CanController_A, 1:CanController_B, 2:CanController_C, 3:CanController_D, 4:CanController_E
 * 			CanCtrl_Mode 0:Normal Mode, 1:Listen Only Mode 2: Sleep Mode
 * 参数out: 无
 * 返回值: Std_ReturnType
 * 描述: 该函数用于切换CAN控制器的工作模式。
 */
Std_ReturnType Com_CanSm_SwitchControllerMode(uint8 Can_valControllerId, uint8 CanCtrl_Mode)
{
	Can_valControllerId = Can_Device_NodeMap[Can_valControllerId];

	uint8 CT_valModeChange_Lo = CAN_ZERO_VAL;
	Std_ReturnType CT_flgRetVal_Lo = E_OK;

	if((Can_valControllerId >= CAN_NODE_MAX) || (CanCtrl_Mode >= CANCTRL_MODE_MAX))
		return	E_NOT_OK;

	if((CANCTRL_MODE_LISTEN_ONLY == CanCtrl_Mode)
		&& (CANCTRL_MODE_LISTEN_ONLY != CT_valModePtr_Mp[Can_valControllerId]))
	{
		Mcan_ControllerConfigs[Can_valControllerId].mcanMode = MCAN_LISTEN_ONLY_MODE;
		CT_valModeChange_Lo = CAN_ONE_VAL;
		CT_valModePtr_Mp[Can_valControllerId] = CANCTRL_MODE_LISTEN_ONLY;
	}
	else if((CANCTRL_MODE_NORMAL == CanCtrl_Mode)
			&& (CANCTRL_MODE_NORMAL != CT_valModePtr_Mp[Can_valControllerId]))
	{
		Mcan_ControllerConfigs[Can_valControllerId].mcanMode = MCAN_NORMAL_MODE;
		CT_valModeChange_Lo = CAN_ONE_VAL;
		CT_valModePtr_Mp[Can_valControllerId] = CANCTRL_MODE_NORMAL;
	}
	else if((CANCTRL_MODE_SLEEP == CanCtrl_Mode)
			&& (CANCTRL_MODE_SLEEP != CT_valModePtr_Mp[Can_valControllerId]))
	{
		Mcan_ControllerConfigs[Can_valControllerId].mcanMode = MCAN_DISABLE_MODE;
		CT_valModeChange_Lo = CAN_ONE_VAL;
		CT_valModePtr_Mp[Can_valControllerId] = CANCTRL_MODE_SLEEP;
	}
	else
	{
		CT_flgRetVal_Lo = E_NOT_OK;
	}

	if(CAN_ZERO_VAL != CT_valModeChange_Lo)
	{
		if(CANCTRL_MODE_SLEEP == CanCtrl_Mode)
		{
			Can_SetControllerMode(Can_valControllerId, CANIF_CS_STOPPED);
		}
		else
		{
			Can_SetControllerMode(Can_valControllerId, CANIF_CS_STOPPED);
			Can_SetControllerMode(Can_valControllerId, CANIF_CS_STARTED);
		}
	}

	return CT_flgRetVal_Lo;
}

void Com_CanSm_GetReceiveActiveInf(uint8 Can_valControllerId, uint8* Can_valActiveInf)
{
	*Can_valActiveInf = CAN_Device_GetReceiveActiveInf(Can_valControllerId);
}

void Com_CanSm_GetBusOffStatus(uint8 Can_valControllerId, uint8* Can_retval)
{
	*Can_retval = CAN_Device_GetBusOffStatus(Can_valControllerId);
}

void Com_CanSm_GetErrWarnStatus(uint8 Can_valControllerId, uint8* Can_ErrWarn)
{
	*Can_ErrWarn = CAN_Device_GetErrWarnStatus(Can_valControllerId);
}

void Com_CanSm_GetErrPassiveStatus(uint8 Can_valControllerId, uint8* Can_ErrPassive)
{
	*Can_ErrPassive = CAN_Device_GetErrPassiveStatus(Can_valControllerId);
}

void Com_CanSm_GetBusErrStatus(uint8 Can_valControllerId, uint8* Can_BusErr)
{
	*Can_BusErr = CAN_Device_GetBusErrStatus(Can_valControllerId);
}
