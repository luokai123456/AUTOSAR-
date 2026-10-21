/*** create info ***********************
*@ Author : wangjiacheng
*@ date :2025-12-04
*@ Description :CAN device configuration functions
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : 
*@ date :2025-12-04
*@ Modification Description :
初始版本
****************************************/
#include "Can_Device_Prv.h"
#ifndef CAN_TEST_CFG_H_
const MCANModId CD_valCanIndex_Mp[CAN_CTRL_NUM_MAX] = {
	MCAN_MOD_ID_7,
	MCAN_MOD_ID_2,
	MCAN_MOD_ID_9,
	MCAN_MOD_ID_1,
	MCAN_MOD_ID_6,
	MCAN_MOD_ID_11,
};
#else
const MCANModId CD_valCanIndex_Mp[CAN_CTRL_NUM_MAX] = {
	MCAN_MOD_ID_7,
	MCAN_MOD_ID_2,
	MCAN_MOD_ID_3,
	MCAN_MOD_ID_9,
	MCAN_MOD_ID_1,
	MCAN_MOD_ID_6,
	MCAN_MOD_ID_11,
};
#endif


const CanTransmit_Fctp_t CD_valCanTransmit_Fctp_Mp[CAN_CTRL_NUM_MAX] = {
	{
		&CAN_TransmitFrame,
		&CAN_Device_NetMangeIdConfig,
		&CAN_Device_ReceiveNetMangeMessage,
		&CAN_Device_GetBusOffStatus,
		&CAN_Device_BusOffRecover,
		&CAN_Device_GetErrWarnStatus,
		&CAN_Device_GetErrPassiveStatus,
		&CAN_Device_GetBusErrStatus,
		&CAN_Device_CancelDataTransmit,
		&CAN_Device_SwitchControllerMode,
		&CAN_Device_StopChannlTx,
		&CAN_Device_GetReceiveActiveInf,
	},
	{
		&CAN_TransmitFrame,
		&CAN_Device_NetMangeIdConfig,
		&CAN_Device_ReceiveNetMangeMessage,
		&CAN_Device_GetBusOffStatus,
		&CAN_Device_BusOffRecover,
		&CAN_Device_GetErrWarnStatus,
		&CAN_Device_GetErrPassiveStatus,
		&CAN_Device_GetBusErrStatus,
		&CAN_Device_CancelDataTransmit,
		&CAN_Device_SwitchControllerMode,
		&CAN_Device_StopChannlTx,
		&CAN_Device_GetReceiveActiveInf,
	},
	{
		&CAN_TransmitFrame,
		&CAN_Device_NetMangeIdConfig,
		&CAN_Device_ReceiveNetMangeMessage,
		&CAN_Device_GetBusOffStatus,
		&CAN_Device_BusOffRecover,
		&CAN_Device_GetErrWarnStatus,
		&CAN_Device_GetErrPassiveStatus,
		&CAN_Device_GetBusErrStatus,
		&CAN_Device_CancelDataTransmit,
		&CAN_Device_SwitchControllerMode,
		&CAN_Device_StopChannlTx,
		&CAN_Device_GetReceiveActiveInf,
	},
	{
		&CAN_TransmitFrame,
		&CAN_Device_NetMangeIdConfig,
		&CAN_Device_ReceiveNetMangeMessage,
		&CAN_Device_GetBusOffStatus,
		&CAN_Device_BusOffRecover,
		&CAN_Device_GetErrWarnStatus,
		&CAN_Device_GetErrPassiveStatus,
		&CAN_Device_GetBusErrStatus,
		&CAN_Device_CancelDataTransmit,
		&CAN_Device_SwitchControllerMode,
		&CAN_Device_StopChannlTx,
		&CAN_Device_GetReceiveActiveInf,
	},
	{
		&CAN_TransmitFrame,
		&CAN_Device_NetMangeIdConfig,
		&CAN_Device_ReceiveNetMangeMessage,
		&CAN_Device_GetBusOffStatus,
		&CAN_Device_BusOffRecover,
		&CAN_Device_GetErrWarnStatus,
		&CAN_Device_GetErrPassiveStatus,
		&CAN_Device_GetBusErrStatus,
		&CAN_Device_CancelDataTransmit,
		&CAN_Device_SwitchControllerMode,
		&CAN_Device_StopChannlTx,
		&CAN_Device_GetReceiveActiveInf,
	},
	{
		&CAN_TransmitFrame,
		&CAN_Device_NetMangeIdConfig,
		&CAN_Device_ReceiveNetMangeMessage,
		&CAN_Device_GetBusOffStatus,
		&CAN_Device_BusOffRecover,
		&CAN_Device_GetErrWarnStatus,
		&CAN_Device_GetErrPassiveStatus,
		&CAN_Device_GetBusErrStatus,
		&CAN_Device_CancelDataTransmit,
		&CAN_Device_SwitchControllerMode,
		&CAN_Device_StopChannlTx,
		&CAN_Device_GetReceiveActiveInf,
	}
};