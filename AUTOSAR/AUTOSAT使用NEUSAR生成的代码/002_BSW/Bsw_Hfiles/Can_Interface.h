/*** create info ***********************
*@ Author : wangjiacheng 
*@ date :2025-12-04
*@ Description :CAN interface definitions
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : wangjiacheng 
*@ date :2025-12-04
*@ Modification Description :
初始版本
****************************************/
#ifndef __CAN_TRANSMIT_H_
#define __CAN_TRANSMIT_H_

#include "Std_Types.h"

#define CANFD_SUPPORT					(1U)

#define CAN_ID_STANDARD 	(0)  /* Standard ID */
#define CAN_ID_EXTENDED 	(1)  /* Extended ID */

#define CAN_ID_ISFD 	(1)  /* Is FD Frame */
#define CAN_ID_ISNOFD 	(0)  /* Is FD Frame */

/* Set the node of CanId_cfg in CanBus_Configuration */
#ifndef CAN_TEST_CFG_H_
#define CAN_NODEA						(0U)
#define CAN_NODEB						(1U)
#define CAN_NODEC						(2U)
#define CAN_NODED						(3U)
#define CAN_NODEE						(4U)
#define CAN_NODEF						(5U)
#else
#define CAN_NODEA						(0U)
#define CAN_NODEB						(1U)
#define CAN_NODEC						(2U)
#define CAN_NODED						(3U)
#define CAN_NODEE						(4U)
#define CAN_NODEF						(5U)
#define CAN_NODEG						(6U)
#endif


#define CAN_NODE_BAUDCONFIG_NUM_MAX			(4U)
#define CAN_ZERO_VAL						(0U)
#define CAN_ONE_VAL							(1U)
#define CANCTRL_MODE_MAX					(3U)

#ifndef CAN_TEST_CFG_H_
#define CAN_NODE_MAX						(6U)
#else
#define CAN_NODE_MAX						(7U)
#endif

/* Set Control Mode of for Com_CanSm_SwitchControllerMode() */
#define CANCTRL_MODE_NORMAL			(0U) //正常模式
#define CANCTRL_MODE_LISTEN_ONLY	(1U) //静默模式
#define CANCTRL_MODE_SLEEP			(2U) //睡眠模式

typedef struct {
	uint32 			id;
	uint32			id_mask;
	uint8 			node;
	boolean			is_ext;
} Can_IdCfg;

typedef struct {
    uint32			message_id;
    boolean			is_ext;
    uint8			data_size;
#if CANFD_SUPPORT
    boolean			is_fd;
    uint8 			send_data[64];
#else
    uint8			send_data[8];
#endif
} Can_SendObjNew;

typedef struct {
	const Can_IdCfg*id_info;
	uint16 			cfg_len;
} Can_IdListCfg;

typedef struct {
#if CANFD_SUPPORT
	uint8 			receive_data[64];
#else
	uint8 			receive_data[8];
#endif
	uint8 			data_size;
	uint8 			receive_active;
} Can_ReceiveObjNew;


extern Std_ReturnType Com_CanIfA_SendFunction(uint8 Can_valMailBoxId, Can_SendObjNew *Can_valSendObjNew);
extern Std_ReturnType Com_CanIfB_SendFunction(uint8 Can_valMailBoxId, Can_SendObjNew *Can_valSendObjNew);
extern Std_ReturnType Com_CanIfC_SendFunction(uint8 Can_valMailBoxId, Can_SendObjNew *Can_valSendObjNew);
extern Std_ReturnType Com_CanIfD_SendFunction(uint8 Can_valMailBoxId, Can_SendObjNew *Can_valSendObjNew);
extern Std_ReturnType Com_CanIfE_SendFunction(uint8 Can_valMailBoxId, Can_SendObjNew *Can_valSendObjNew);
extern Std_ReturnType Com_CanIfF_SendFunction(uint8 Can_valMailBoxId, Can_SendObjNew *Can_valSendObjNew);
extern Std_ReturnType Com_CanIfG_SendFunction(uint8 Can_valMailBoxId, Can_SendObjNew* Can_valSendObjNew);
extern Std_ReturnType Com_CanSm_SwitchControllerMode(uint8 Can_valControllerId, uint8 CanCtrl_Mode);
extern void Com_CanSm_GetReceiveActiveInf(uint8 Can_valNodeId, uint8* Can_valActiveInf);

extern void Com_CanSm_GetBusOffStatus(uint8 Can_valNodeId, uint8* Can_retval);
extern void Com_CanSm_GetErrWarnStatus(uint8 Can_valNodeId, uint8* Can_ErrWarn);
extern void Com_CanSm_GetErrPassiveStatus(uint8 Can_valNodeId, uint8* Can_ErrPassive);
extern void Com_CanSm_GetBusErrStatus(uint8 Can_valNodeId, uint8* Can_BusErr);
#endif /*__CAN_TRANSMIT_H_*/
