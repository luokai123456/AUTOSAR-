/*** create info ***********************
*@ Author : wangjiacheng 
*@ date :2025-12-04
*@ Description :CAN device private H file
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : 
*@ date :2025-12-04
*@ Modification Description :
初始版本
****************************************/

#ifndef __CAN_TRANSMIT_PRV_H_
#define __CAN_TRANSMIT_PRV_H_

#include "common.h"
#include "Can_Cfg.h"
#include "CanIf.h"
#include "CanIf_Lcfg.h"
#include "Can_Interface.h"
#include "Can_Device_Cfg.h"
#include "ComStack_Types.h"
#include "Can_LLDriver.h"

#define CanTpRX_PhyID	0x742U
#define CanTpRX_FunID	0x7DFU
#define CanTpTX_PhyID	0x74aU

#define CanTp_RX_PhyMailBoxId0 44//modify:Add a physical address channel to solve the problem of continuous message loss with short interval time
#define CanTp_RX_PhyMailBoxId1 45//modify:Add a physical address channel to solve the problem of continuous message loss with short interval time
#define CanTp_RX_FunMailBoxId 46

#define CanTp_TX_PhyMailBoxId 31
#define UDSCANTP_MAILBOXID_MAX 3


typedef uint8 State;
typedef void (*CAN_CallBack_t)(void);

enum {
    STATE_MODE_MASK      = 0x03,
    STATE_MODE_SHIFT     = 0,
    STATE_BUS_OFF_MASK   = 0x04,
    STATE_BUS_OFF_SHIFT  = 2,
    STATE_ACTIVE_MASK    = 0x08,
    STATE_ACTIVE_SHIFT   = 3
};

typedef struct {
    uint32 rx_nm_id_min;
    uint32 rx_nm_id_max;
    uint32 prior_nm_frame_id;
    uint32 status_reg;
    uint32 cancel_req;
    uint32 silence_req;
} Info;

typedef struct {
    uint32 id;
    Can_ReceiveObjNew frame;
} MailboxSlot;

typedef struct {
    MailboxSlot slots[CAN_REC_MAIL_BOX_MAX];
} Mailbox;

typedef struct {
	Info info;
    Mailbox mailbox;
    State state;
    uint8 padding[3];
} Ctrl;

struct CanController{
    uint32 current_msg_id;
    Ctrl ctrl[CAN_CTRL_NUM_MAX];
};

typedef struct{
	const uint8				node;
	const uint16			node_hwobj_offset;
	mcan_filter_config_t*	filter_config;
	mcan_id_table_t*		id_table_base;
	uint16					id_table_offset_std;
	uint16					id_table_offset_ext;
}CanInit_idFilter_t;

typedef struct{
	Std_ReturnType (*TransmitFrame)(uint8, uint8, Can_SendObjNew*);
	void (*NetMangeidConfig)(uint8, uint32, uint32);
	void (*ReceiveNetMangeMessage)(uint8, uint32*, Can_ReceiveObjNew*);
	uint8 (*GetBusOffStatus)(uint8);
	void (*BusOffRecover)(uint8);
	uint8 (*GetErrWarnStatus)(uint8);
	uint8 (*GetErrPassiveStatus)(uint8);
	uint8 (*GetBuseErrStatus)(uint8);
	void (*CancelDataTransmit)(uint8, uint8, uint8);
	void (*SwitchControllerMode)(uint8, uint8);
	void (*StopChannlTx)(uint8, uint32);
	uint8 (*GetReceiveActiveInf)(uint8);
}CanTransmit_Fctp_t;

extern uint8 Can_Device_NodeMap[CAN_CTRL_NUM_MAX];
extern struct CanController CD_valDevice_Mp;
/* App */
extern const uint8 CT_valCoreId_Mp;
extern const uint8 CT_valCanBaudConfigId_Mp[CAN_NODE_MAX];
extern const Can_IdListCfg Can_valIdListCfg_Mp;

/* Configuration */
extern const MCANModId CD_valCanIndex_Mp[CAN_CTRL_NUM_MAX];
extern CanInit_idFilter_t CD_validFilter_Mp[CAN_CTRL_NUM_MAX];
extern const CanTransmit_Fctp_t CD_valCanTransmit_Fctp_Mp[CAN_CTRL_NUM_MAX];
extern uint8 CT_valModePtr_Mp[CAN_NODE_MAX];//每个CAN节点的当前工作模式

/* MCAL */
extern VAR(mcan_filter_config_t, CAN_CONST) RX_FILTER_CFG_0;
extern VAR(mcan_filter_config_t, CAN_CONST) RX_FILTER_CFG_1;
extern VAR(mcan_filter_config_t, CAN_CONST) RX_FILTER_CFG_2;
extern VAR(mcan_filter_config_t, CAN_CONST) RX_FILTER_CFG_3;
extern VAR(mcan_filter_config_t, CAN_CONST) RX_FILTER_CFG_4;
extern VAR(mcan_filter_config_t, CAN_CONST) RX_FILTER_CFG_5;
extern VAR(mcan_id_table_t, CAN_CONST) filter_ids_config_0[64U];
extern VAR(mcan_id_table_t, CAN_CONST) filter_ids_config_1[64U];
extern VAR(mcan_id_table_t, CAN_CONST) filter_ids_config_2[64U];
extern VAR(mcan_id_table_t, CAN_CONST) filter_ids_config_3[64U];
extern VAR(mcan_id_table_t, CAN_CONST) filter_ids_config_4[64U];
extern VAR(mcan_id_table_t, CAN_CONST) filter_ids_config_5[64U];
extern VAR(mcan_core_map_t, CAN_CONST) Mcan_CoreMap[CAN_CONTROLLER_COUNT];
extern VAR(CANConfig, CAN_CONST) Mcan_ControllerConfigs[CAN_CONTROLLER_COUNT];
extern VAR(mcan_hwObject_info, CAN_CONST) Mcan_HardWareObjConfigs[CAN_CONTROLLER_COUNT];
extern CONSTP2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) g_mcanBase[MCAN_INSTANCE_COUNT];

extern void Can_Device_RxIndication
(
	uint8 CD_valNode_Lo,
	P2CONST(PduInfoType, AUTOMATIC, CANNM_APPL_CONST) PduInfoPtr
);
extern void Can_Device_Init(void);
extern void CAN_Device_MainFunction_Write(void);
extern void CAN_Device_MainFunction(void);
extern Std_ReturnType CAN_TransmitFrame(uint8 Can_valControllerId, uint8 Can_valMailBoxId, Can_SendObjNew* Can_valSendObjNew);
extern void CAN_Device_NetMangeIdConfig(uint8 Can_valControllerId, uint32 Can_valIdMin, uint32 Can_valIdMax);
extern void CAN_Device_ReceiveNetMangeMessage(uint8 Can_valControllerId, uint32* Can_valMsgId, Can_ReceiveObjNew *Can_valRecObjNew);
extern uint8 CAN_Device_GetBusOffStatus(uint8 Can_valControllerId);
extern void CAN_Device_BusOffRecover(uint8 Can_valControllerId);
extern uint8 CAN_Device_GetErrWarnStatus(uint8 Can_valControllerId);
extern uint8 CAN_Device_GetErrPassiveStatus(uint8 Can_valControllerId);
extern uint8 CAN_Device_GetBusErrStatus(uint8 Can_valControllerId);
extern void CAN_Device_CancelDataTransmit(uint8 Can_valControllerId, uint8 Can_valTxBuffIdx, uint8 Can_valCanCelEn);
extern void CAN_Device_SwitchControllerMode(uint8 Can_valControllerId, uint8 Can_valTurnOff);
extern void CAN_Device_StopChannlTx(uint8 Can_valControllerId, uint32 Can_valChannlMask);
extern uint8 CAN_Device_GetReceiveActiveInf(uint8 Can_valControllerId);


extern Std_ReturnType Can_TxConfirmation(uint8 CanTxPduId);
extern Std_ReturnType CanTp_TransmitToCan(PduIdType CanIfTxSduId, const PduInfoType* CanIfTxInfoPtr);


static inline uint8 GetMode(const State state) {
    return (state & STATE_MODE_MASK) >> STATE_MODE_SHIFT;
}

static inline void SetMode(State *state, uint8 mode) {
    mode &= 0x03;
    *state = (*state & ~STATE_MODE_MASK) |
             ((mode << STATE_MODE_SHIFT) & STATE_MODE_MASK);
}

static inline bool IsBusOff(const State state) {
    return (bool)((state & STATE_BUS_OFF_MASK) >> STATE_BUS_OFF_SHIFT);
}

static inline void SetBusOff(State *state, boolean is_bus_off) {
    *state = (*state & ~STATE_BUS_OFF_MASK) |
             ((is_bus_off << STATE_BUS_OFF_SHIFT) & STATE_BUS_OFF_MASK);
}

static inline boolean IsActive(const State state) {
    return (bool)((state & STATE_ACTIVE_MASK) >> STATE_ACTIVE_SHIFT);
}

static inline void SetActive(State *state, boolean is_active) {
    *state = (*state & ~STATE_ACTIVE_MASK) |
             ((is_active << STATE_ACTIVE_SHIFT) & STATE_ACTIVE_MASK);
}

static inline boolean IsFrameValid(const Can_SendObjNew* Can_valSendObjNew) {
#if CANFD_SUPPORT
    if(Can_valSendObjNew->is_fd)
        return Can_valSendObjNew->data_size <= 64;
#endif
    return Can_valSendObjNew->data_size <= 8;
}

#endif /*__CAN_TRANSMIT_PRV_H_*/