#ifndef PMS_RTECOMCBK_H_
#define PMS_RTECOMCBK_H_

#include "Rte_Type.h"

FUNC(void, RTE_CODE) Rte_COMCbk_ACU_CrashOutputSts_ACU_ChimeTelltaleReq_TimeoutNotification(void);
FUNC(void, RTE_CODE) Rte_COMCbk_ACU_CrashOutputSts_ACU_ChimeTelltaleReq_ComNotification(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CSM_DriveModeReq_CSM_SwitchSts_TimeoutNotification(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CSM_DriveModeReq_CSM_SwitchSts_ComNotification(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_OutOverCurr_DCDC_FaultInfo_TimeoutNotification(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_OutOverCurr_DCDC_FaultInfo_ComNotification(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EGSM_ParkReq_EGSM_Status_TimeoutNotification(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EGSM_ParkReq_EGSM_Status_ComNotification(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_ABSActive_EHB_Status_TimeoutNotification(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_ABSActive_EHB_Status_ComNotification(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_MbRegenTargetWheel_EHB_Regen_TimeoutNotification(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_MbRegenTargetWheel_EHB_Regen_ComNotification(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_PTTrqDecReq_EHB_PTTorqueRequest_TimeoutNotification(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EHB_PTTrqDecReq_EHB_PTTorqueRequest_ComNotification(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PEPS_PowerModeValidity_PEPS_Message_Sts_TimeoutNotification(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PEPS_PowerModeValidity_PEPS_Message_Sts_ComNotification(void);

FUNC(boolean, RTE_CODE) ACU_ChimeTelltaleReq_CAND_0x380_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
FUNC(boolean, RTE_CODE) CSM_SwitchSts_CANB_0x3CA_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
FUNC(boolean, RTE_CODE) PEPS_Message_Sts_CANB_0x1E2_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
FUNC(boolean, RTE_CODE) EGSM_Status_CANA_0x145_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
FUNC(boolean, RTE_CODE) EHB_Status_CAND_0x125_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
FUNC(boolean, RTE_CODE) PDC_Status_Info_CAND_0x2CF_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);

FUNC(boolean, RTE_CODE) OBC_Sts_CANA_0x220_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
FUNC(boolean, RTE_CODE) Station_Status_CANA_0x157_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
FUNC(boolean, RTE_CODE) EHB_DA_MESSAGE_CAND_0x126_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
FUNC(boolean, RTE_CODE) EHB_FrontWheelSpeedsKPH_CAND_0x122_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
FUNC(boolean, RTE_CODE) EHB_ISARequest_CAND_0x1F9_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
FUNC(boolean, RTE_CODE) EHB_PTTorqueRequest_CAND_0x129_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
FUNC(boolean, RTE_CODE) EHB_RearWheelSpeedsKPH_CAND_0x123_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
FUNC(boolean, RTE_CODE) EHB_Regen_CAND_0x128_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
FUNC(boolean, RTE_CODE) EHB_VLC_TorqueRequest_CAND_0x121_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
FUNC(boolean, RTE_CODE) EHB_WheelSpeedsRC_CAND_0x124_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
FUNC(boolean, RTE_CODE) SAS_Status_CAND_0x0E0_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
FUNC(boolean, RTE_CODE) YRS1_CAND_0x130_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
FUNC(boolean, RTE_CODE) YRS2_CAND_0x131_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
FUNC(boolean, RTE_CODE) HCM_MainRelayValue_CANG_0x122_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
FUNC(boolean, RTE_CODE) HCM_Other2RelayValue_CANG_0x128_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
FUNC(boolean, RTE_CODE) HCM_OtherRelayValue_CANG_0x124_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);
FUNC(boolean, RTE_CODE) HCM_Status_CANG_0x120_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);

#endif
