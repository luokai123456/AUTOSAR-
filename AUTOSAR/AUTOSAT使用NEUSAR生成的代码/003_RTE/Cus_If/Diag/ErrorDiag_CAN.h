#include "StandardTypes.h"

extern uint8 CANA_stBusoffQuickCouter;
extern uint8 CANB_stBusoffQuickCouter;
extern uint8 CAND_stBusoffQuickCouter;
extern uint8 CANA_stBusoffCouter;
extern uint8 CANB_stBusoffCouter;
extern uint8 CAND_stBusoffCouter;
extern uint8 CANA_stBusoffRecoverCouter;
extern uint8 CANB_stBusoffRecoverCouter;
extern uint8 CAND_stBusoffRecoverCouter;
extern uint8 CANA_stBusoffRecoeryPeriod;
extern uint8 CANB_stBusoffRecoeryPeriod;
extern uint8 CAND_stBusoffRecoeryPeriod;
extern boolean CANA_stBusoffFlg;
extern boolean CANB_stBusoffFlg;
extern boolean CAND_stBusoffFlg;

extern boolean Can_DiagVltgCondFlg;
extern boolean Can_DiagVltgLowErrFlg;
extern boolean Can_DiagVltgHighErrFlg;
extern uint16 Can_DiagVltgLowErrRecoeryCounter;
extern uint16 Can_DiagVltgHighErrRecoeryCounter;

extern boolean Can_DiagCondKeyOn;
extern boolean Can_DiagCondKeyOn3500ms;
extern boolean Can_DiagCondChargeOn;
extern boolean Can_DiagCondCANDNoBusoff;
extern boolean Can_DiagCondCANBNoBusoff;
extern boolean Can_DiagCondCANANoBusoff;
extern uint16 KeyOnKeepCounter;
extern uint16 CANA_BusoffRecoveryCounter;
extern uint16 CANB_BusoffRecoveryCounter;
extern uint16 CAND_BusoffRecoveryCounter;

extern uint16 Can_MsgTimeOut_DiagCounter;
extern uint8 CAND_0x125_TimeOutCounter;
extern boolean CAND_0x125_TimeOut;
extern uint8 CAND_0x128_TimeOutCounter;
extern boolean CAND_0x128_TimeOut;
extern uint8 CAND_0x129_TimeOutCounter;
extern boolean CAND_0x129_TimeOut;
extern uint8 CANA_0x398_TimeOutCounter;
extern boolean CANA_0x398_TimeOut;
extern uint8 CANA_0x145_TimeOutCounter;
extern boolean CANA_0x145_TimeOut;
extern uint8 CAND_0x380_TimeOutCounter;
extern boolean CAND_0x380_TimeOut;
extern uint8 CANG_0x122_TimeOutCounter;
extern boolean CANG_0x122_TimeOut;
extern uint8 CANG_0x128_TimeOutCounter;
extern boolean CANG_0x128_TimeOut;

extern uint8 CANB_0x3CA_TimeOutCounter;
extern boolean CANB_0x3CA_TimeOut;

extern uint8 CANA_0x220_TimeOutCounter;
extern boolean CANA_0x220_TimeOut;

extern uint8 CANB_0x247_TimeOutCounter;
extern boolean CANB_0x247_TimeOut;

extern uint8 CANB_0x1E2_TimeOutCounter;
extern boolean CANB_0x1E2_TimeOut;

extern boolean PMS_EHB_communication_lost;
extern boolean PMS_DCDC_communication_lost;
extern boolean PMS_EGSM_communication_lost;
extern boolean PMS_MotorSpeed_communication_lost;
extern boolean PMS_Speed_communication_lost;
extern boolean PMS_PEPS_communication_lost;
extern boolean PMS_ACU_communication_lost;
extern boolean PMS_CSM_communication_lost;
extern boolean PMS_BBM_communication_lost;
extern boolean PMS_PEPS_DataInvalidErr;
extern boolean PMS_PDC_DataInvalidErr;
extern uint8 CAND_0x380_CheckSumArray[8];
extern uint8 CANB_0x3CA_CheckSumArray[8];
extern uint8 CANB_0x1E2_CheckSumArray[8];
extern uint8 CANA_0x145_CheckSumArray[8];
extern uint8 CAND_0x125_CheckSumArray[8];
extern uint8 CAND_0x2CF_CheckSumArray[8];

extern uint8 CANA_0x220_CheckSumArray[8];
extern uint8 CANA_0x157_CheckSumArray[8];
extern uint8 CAND_0x126_CheckSumArray[8];
extern uint8 CAND_0x122_CheckSumArray[8];
extern uint8 CAND_0x1F9_CheckSumArray[8];
extern uint8 CAND_0x129_CheckSumArray[8];
extern uint8 CAND_0x123_CheckSumArray[8];
extern uint8 CAND_0x128_CheckSumArray[8];
extern uint8 CAND_0x121_CheckSumArray[8];
extern uint8 CAND_0x124_CheckSumArray[8];
extern uint8 CAND_0x0E0_CheckSumArray[8];
extern uint8 CAND_0x130_CheckSumArray[8];
extern uint8 CAND_0x131_CheckSumArray[8];
extern uint8 CANG_0x122_CheckSumArray[8];
extern uint8 CANG_0x128_CheckSumArray[8];
extern uint8 CANG_0x124_CheckSumArray[8];
extern uint8 CANG_0x120_CheckSumArray[8];

extern boolean CANA_0x220_CheckSumErr;
extern boolean CANA_0x157_CheckSumErr;
extern boolean CAND_0x126_CheckSumErr;
extern boolean CAND_0x122_CheckSumErr;
extern boolean CAND_0x1F9_CheckSumErr;
extern boolean CAND_0x129_CheckSumErr;
extern boolean CAND_0x123_CheckSumErr;
extern boolean CAND_0x128_CheckSumErr;
extern boolean CAND_0x121_CheckSumErr;
extern boolean CAND_0x124_CheckSumErr;
extern boolean CAND_0x0E0_CheckSumErr;
extern boolean CAND_0x130_CheckSumErr;
extern boolean CAND_0x131_CheckSumErr;
extern boolean CANG_0x122_CheckSumErr;
extern boolean CANG_0x128_CheckSumErr;
extern boolean CANG_0x124_CheckSumErr;
extern boolean CANG_0x120_CheckSumErr;

extern boolean CAND_0x380_AliveCntErr;
extern boolean CAND_0x380_CheckSumErr;
extern boolean CANB_0x3CA_AliveCntErr;
extern boolean CANB_0x3CA_CheckSumErr;
extern boolean CANB_0x1E2_AliveCntErr;
extern boolean CANB_0x1E2_CheckSumErr;
extern boolean CANA_0x145_AliveCntErr;
extern boolean CANA_0x145_CheckSumErr;
extern boolean CAND_0x125_AliveCntErr;
extern boolean CAND_0x125_CheckSumErr;
extern boolean CAND_0x2CF_AliveCntErr;
extern boolean CAND_0x2CF_CheckSumErr;

extern uint16 Can_MsgAliveCnt_DiagCounter;
extern uint16 Can_MsgCheckSum_DiagCounter;

extern uint8 CANB_0x1E2_AliveCntTemp;
extern uint8 CANA_0x145_AliveCntTemp;
extern uint8 CAND_0x125_AliveCntTemp;
extern uint8 CAND_0x2CF_AliveCntTemp;
extern uint8 CAND_0x380_AliveCntTemp;
extern uint8 CANB_0x3CA_AliveCntTemp;

typedef enum
{
    CAN_CH_A = 1,
    CAN_CH_B = 2,
    CAN_CH_C = 3,
    CAN_CH_D = 4
} CAN_ChannelType;

typedef struct
{
    uint32 id;
    CAN_ChannelType channel;
    uint8 last_input;
    uint8 same_count;
    boolean *alive_err_flag;
} AliveCnt_StateType;

typedef struct
{
	uint8 ErrId;
    uint8 ErrCounter;
    uint8 ClearErrCounter;
    uint8 ErrCounterMax;
    uint8 ClearErrCounterMax;
    boolean ErrStateRaw;
    boolean *ErrState;
} CANErrDiag_StateType;

extern void Can_CANFaultPeriodDiag(void);
extern void Can_DiagVltgCondCal(void);
extern void Can_KL30VltgCondCal(void);
extern void Can_BusOffDiag(void);
extern void Can_MsgTimeOutDiag(void);
extern void Can_DiagCondCal(void);
extern void Can_CheckSumErrDiag(void);
extern void Can_AliveCounterErrDiag(void);
extern void Can_ComLostDiag(void);
extern uint8 CalculateCRC8(const uint8 *data_byte_array);
extern void CheckAliveCntErr(CAN_ChannelType channel, uint32 id, uint8 input);
extern void CAN_CheckCRC8(uint8 *pDataArray, uint8 DataLen, boolean *pCheckSumErr);
extern void CANErrDTC_Diag(uint8 ErrID, boolean InputErrState);
extern void CanIf_CheckSumDataAdd_Callout(uint32 txPduId,uint32 SduLength, uint8 *SduDataArray,uint8 txCANNodeID);
extern boolean CanIf_IsNeedCheckSumPdu(uint32 currentPduId);
extern void DiagErr_SetEventStatus(void);