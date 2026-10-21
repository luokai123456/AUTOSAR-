#ifndef ASW_TASK_MODULES_H
#define ASW_TASK_MODULES_H


// === Core1 Init ===
void PMS_BswAswRte_Init(void);
void PMS_HWI_Init(void);
void PMS_HWO_Init(void);
void swc_ATAU_Init(void);
void swc_AUXC_Init(void);
void swc_DIAG_Init(void);
void swc_EGYM_Init(void);
void swc_HMIF_Init(void);
void swc_HVSM_Init(void);
void swc_MEST_Init(void);
void swc_OGVL_Init(void);
void swc_RMLK_Init(void);
void swc_SCAP_Init(void);
void swc_SCOO_Init(void);
void swc_TCOO_Init(void);
void swc_THSM_Init(void);
void swc_VCIP_Init(void);
void swc_VCOP_Init(void);
void swc_VOMM_Init(void);

// === Core1 Step ===
void PMS_BswAswRte_Step(void);
void PMS_HWI_Step(void);
void PMS_HWO_Step(void);
void swc_ATAU_Step(void);
void swc_AUXC_Step(void);
void swc_DIAG_Step(void);
void swc_EGYM_Step(void);
void swc_HMIF_Step(void);
void swc_HVSM_Step(void);
void swc_MEST_Step(void);
void swc_OGVL_Step(void);
void swc_RMLK_Step(void);
void swc_SCAP_Step(void);
void swc_SCOO_Step(void);
void swc_TCOO_Step(void);
void swc_THSM_Step(void);
void swc_VCIP_Step(void);
void swc_VCOP_Step(void);
void swc_VOMM_Step(void);

// === Core2 Init ===
void BCC_Init(void);
void BBC_Init(void);
void BCF_Init(void);
void BatProtnIU_Init(void);
void BPP_Init(void);
void BTHM_Init(void);
void BWLD_Init(void);
void BSTC_Init(void);
void CIL_Init(void);
void COL_Init(void);
void CTC_Init(void);
void DEH_Init(void);
void ELHPN_Init(void);
void swc_SetInput_Init(void);
void swc_SetOutputInterface_Init(void);
void swc_SetSendCANMsg_Init(void);

// === Core2 10ms ===
void BCF_10ms(void);
void BSTC_10ms(void);
void CIL_10ms(void);
void COL_10ms(void);
void CTC_10ms(void);
void DEH_10ms(void);
void GetEventStatus_10ms(void);
void NVM_Read_10ms(void);
void swc_SetOutputInterface_10ms(void);
void swc_SetSendCANMsg_10ms(void);
void AC_10ms(void);
void BCC_10ms(void);
void DC_10ms(void);

// === Core2 1000ms ===
void BWLD_1000ms(void);
void COL_1000ms(void);
void DEH_1000ms(void);
void swc_SetSendCANMsg_1000ms(void);

// === Core2 100ms ===
void BBC_100ms(void);
void BCF_100ms(void);
void BPIU_100ms(void);
void BPP_100ms(void);
void BTHM_100ms(void);
void BWLD_100ms(void);
void CIL_100ms(void);
void COL_100ms(void);
void NVM_Write_100ms(void);
void swc_SetInput_100ms(void);
void swc_SetOutputInterface_100ms(void);
void swc_SetSendCANMsg_100ms(void);

// === Core2 50ms ===
void BPIU_50ms(void);
void BPP_50ms(void);
void CIL_50ms(void);
// void COL_50ms(void);
void ELHPN_50ms(void);
void swc_SetInput_50ms(void);
void swc_SetOutputInterface_50ms(void);

// === Core3 Init ===
void ActvDampg_Init(void);
void AngEmDev_Init(void);
void AngOfstCal_Init(void);
void AngSwDecod_Init(void);
void AntiRollBack_Init(void);
void BIfRx_Init(void);
void BIfTx_Init(void);
void ComRx_CAN_1_Init(void);
void Dchrg_Init(void);
void DernCoorn_Init(void);
void DernEm_Init(void);
void DernInv_Init(void);
void DernSys_Init(void);
void Diag_Init(void);
void DynFrq_Init(void);
void EdrvStMac_Init(void);
void EmPwr_Init(void);
void EmTq_Init(void);
void ExtTqDes_Init(void);
void HrmcInj_Init(void);
void HvIntlck_Init(void);
void HvInvDev_Init(void);
void IdqAct_Init(void);
void IdqCtrl_Init(void);
void IdqDes_Init(void);
void MCU_fc_BIfRx_IN_Init(void);
void MCU_fc_BIfRx_OUT_Init(void);
void PhaCurrDev_Init(void);
void TempDev_Init(void);
void TqDemCoorn_Init(void);
void VoltModlnGen_Init(void);
void VoltModlnlnp_Init(void);
void ComTx_Init(void);

// === Core3 Task ===
void fc_ComRx10ms(void);
void fc_ComTx10ms(void);
void fc_DernEm(void);
void fc_EmPwr(void);
void fc_HVIntlck(void);
void fc_TempDev(void);
void fc_ComRx20ms(void);
void fc_ComTx20ms(void);
void fc_ActvDampg(void);
void fc_AntiRollBack(void);
void fc_Dchrg(void);
void fc_DernCoorn(void);
void fc_DernInv(void);
void fc_DernSys(void);
void fc_Diag1ms(void);
void fc_EdrvStMac1ms(void);
void fc_EmTq(void);
void fc_ExtTqDes(void);
void fc_IdqDes(void);
void fc_TqDemCoorn(void);
void fc_AngEmDev(void);
void fc_AngOfstCal(void);
void fc_AngSwDecod(void);
void fc_BIfRx(void);
void fc_Config(void);
void fc_BIfTx(void);
void fc_Diag(void);
void fc_EdrvStMac(void);
void fc_HvInvDev(void);
void fc_IdqAct(void);
void fc_IdqCtrl(void);
void fc_PhaCurrDev(void);
void fc_VoltModlnGen(void);
void fc_VoltModlnInp(void);
void fc_DynFrq(void);
void MCU_fc_BIfRx_IN_100us(void);
void MCU_fc_BIfRx_OUT_100us(void);
void fc_ComTxEvent(void);
void fc_ComRx100ms(void);
void fc_ComTx100ms(void);
void fc_ComRx200ms(void);
void fc_ComRx500ms(void);
void fc_ComTx500ms(void);
void fc_ComRx1000ms(void);
void fc_ComRxEvent(void);

void fc_HrmcInj(void);
void fc_HrmcInj1ms(void);


#endif
