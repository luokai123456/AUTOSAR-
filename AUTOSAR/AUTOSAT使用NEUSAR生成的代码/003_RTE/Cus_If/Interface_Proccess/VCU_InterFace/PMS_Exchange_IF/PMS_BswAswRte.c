/*
 * File: PMS_BswAswRte.c
 *
 * Code generated for Simulink model 'PMS_BswAswRte'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Aug 14 19:04:18 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PMS_BswAswRte.h"
#include "PMS_BswAswRte_private.h"
#include "ErrorDiag_CAN.h"
#include "Dcm_Lcfg.h"

extern uint8 Ea_ShutdownReq;
extern uint8 PMS_SWCompileTime[3];


/* Model step function for TID1 */
void PMS_BswAswRte_Step(void)          /* Explicit Task: PMS_BswAswRte_Step */
{
  /* Outport: '<Root>/ECU_Fun_Config_Data1_ECU_Fun_Config_Data1' */
  (void)Rte_Write_ECU_Fun_Config_Data1_ECU_Fun_Config_Data1(Dcm_Did_Block009A_Data.Dcm_DidF101Buffer[0]);

  /* Outport: '<Root>/ECU_Fun_Config_Data2_ECU_Fun_Config_Data2' */
  (void)Rte_Write_ECU_Fun_Config_Data2_ECU_Fun_Config_Data2(Dcm_Did_Block009A_Data.Dcm_DidF101Buffer[1]);

  /* Outport: '<Root>/ECU_Net_Config_Data1_ECU_Net_Config_Data1' */
  (void)Rte_Write_ECU_Net_Config_Data1_ECU_Net_Config_Data1(Dcm_Did_Block009B_Data.Dcm_DidF110Buffer[0]);

  /* Outport: '<Root>/ECU_Net_Config_Data2_ECU_Net_Config_Data2' */
  (void)Rte_Write_ECU_Net_Config_Data2_ECU_Net_Config_Data2(Dcm_Did_Block009B_Data.Dcm_DidF110Buffer[1]);

  /* Outport: '<Root>/EXT_DO_RELAY_LS_10_Fb_EXT_DO_RELAY_LS_10_Fb' */
  (void)Rte_Write_EXT_DO_RELAY_LS_10_Fb_EXT_DO_RELAY_LS_10_Fb(0.0F);

  /* Outport: '<Root>/EXT_DO_RELAY_LS_7_Fb_EXT_DO_RELAY_LS_7_Fb' */
  (void)Rte_Write_EXT_DO_RELAY_LS_7_Fb_EXT_DO_RELAY_LS_7_Fb(0.0F);

  /* Outport: '<Root>/EXT_DO_RELAY_LS_9_Fb_EXT_DO_RELAY_LS_9_Fb' */
  (void)Rte_Write_EXT_DO_RELAY_LS_9_Fb_EXT_DO_RELAY_LS_9_Fb(0.0F);

  /* Outport: '<Root>/F190_VIN_Byte0_F190_VIN_Byte0' */
  (void)Rte_Write_F190_VIN_Byte0_F190_VIN_Byte0(Dcm_Did_Block0091_Data.Dcm_DidF190Buffer[0]);

  /* Outport: '<Root>/F190_VIN_Byte1_F190_VIN_Byte1' */
  (void)Rte_Write_F190_VIN_Byte1_F190_VIN_Byte1(Dcm_Did_Block0091_Data.Dcm_DidF190Buffer[1]);

  /* Outport: '<Root>/F190_VIN_Byte10_F190_VIN_Byte10' */
  (void)Rte_Write_F190_VIN_Byte10_F190_VIN_Byte10(Dcm_Did_Block0091_Data.Dcm_DidF190Buffer[10]);

  /* Outport: '<Root>/F190_VIN_Byte11_F190_VIN_Byte11' */
  (void)Rte_Write_F190_VIN_Byte11_F190_VIN_Byte11(Dcm_Did_Block0091_Data.Dcm_DidF190Buffer[11]);

  /* Outport: '<Root>/F190_VIN_Byte12_F190_VIN_Byte12' */
  (void)Rte_Write_F190_VIN_Byte12_F190_VIN_Byte12(Dcm_Did_Block0091_Data.Dcm_DidF190Buffer[12]);

  /* Outport: '<Root>/F190_VIN_Byte13_F190_VIN_Byte13' */
  (void)Rte_Write_F190_VIN_Byte13_F190_VIN_Byte13(Dcm_Did_Block0091_Data.Dcm_DidF190Buffer[13]);

  /* Outport: '<Root>/F190_VIN_Byte14_F190_VIN_Byte14' */
  (void)Rte_Write_F190_VIN_Byte14_F190_VIN_Byte14(Dcm_Did_Block0091_Data.Dcm_DidF190Buffer[14]);

  /* Outport: '<Root>/F190_VIN_Byte15_F190_VIN_Byte15' */
  (void)Rte_Write_F190_VIN_Byte15_F190_VIN_Byte15(Dcm_Did_Block0091_Data.Dcm_DidF190Buffer[15]);

  /* Outport: '<Root>/F190_VIN_Byte16_F190_VIN_Byte16' */
  (void)Rte_Write_F190_VIN_Byte16_F190_VIN_Byte16(Dcm_Did_Block0091_Data.Dcm_DidF190Buffer[16]);

  /* Outport: '<Root>/F190_VIN_Byte2_F190_VIN_Byte2' */
  (void)Rte_Write_F190_VIN_Byte2_F190_VIN_Byte2(Dcm_Did_Block0091_Data.Dcm_DidF190Buffer[2]);

  /* Outport: '<Root>/F190_VIN_Byte3_F190_VIN_Byte3' */
  (void)Rte_Write_F190_VIN_Byte3_F190_VIN_Byte3(Dcm_Did_Block0091_Data.Dcm_DidF190Buffer[3]);

  /* Outport: '<Root>/F190_VIN_Byte4_F190_VIN_Byte4' */
  (void)Rte_Write_F190_VIN_Byte4_F190_VIN_Byte4(Dcm_Did_Block0091_Data.Dcm_DidF190Buffer[4]);

  /* Outport: '<Root>/F190_VIN_Byte5_F190_VIN_Byte5' */
  (void)Rte_Write_F190_VIN_Byte5_F190_VIN_Byte5(Dcm_Did_Block0091_Data.Dcm_DidF190Buffer[5]);

  /* Outport: '<Root>/F190_VIN_Byte6_F190_VIN_Byte6' */
  (void)Rte_Write_F190_VIN_Byte6_F190_VIN_Byte6(Dcm_Did_Block0091_Data.Dcm_DidF190Buffer[6]);

  /* Outport: '<Root>/F190_VIN_Byte7_F190_VIN_Byte7' */
  (void)Rte_Write_F190_VIN_Byte7_F190_VIN_Byte7(Dcm_Did_Block0091_Data.Dcm_DidF190Buffer[7]);

  /* Outport: '<Root>/F190_VIN_Byte8_F190_VIN_Byte8' */
  (void)Rte_Write_F190_VIN_Byte8_F190_VIN_Byte8(Dcm_Did_Block0091_Data.Dcm_DidF190Buffer[8]);

  /* Outport: '<Root>/F190_VIN_Byte9_F190_VIN_Byte9' */
  (void)Rte_Write_F190_VIN_Byte9_F190_VIN_Byte9(Dcm_Did_Block0091_Data.Dcm_DidF190Buffer[9]);

  /* Outport: '<Root>/F193_ECUHardwareVersionNumber_Byte2_F193_ECUHardwareVersionNumber_Byte2' */
  (void)
    Rte_Write_F193_ECUHardwareVersionNumber_Byte2_F193_ECUHardwareVersionNumber_Byte2
    (Dcm_Did_Block00AB_Data.Dcm_DidF193Buffer[2]);

  /* Outport: '<Root>/F193_ECUHardwareVersionNumber_Byte3_F193_ECUHardwareVersionNumber_Byte3' */
  (void)
    Rte_Write_F193_ECUHardwareVersionNumber_Byte3_F193_ECUHardwareVersionNumber_Byte3
    (Dcm_Did_Block00AB_Data.Dcm_DidF193Buffer[3]);

  /* Outport: '<Root>/F193_ECUHardwareVersionNumber_Byte4_F193_ECUHardwareVersionNumber_Byte4' */
  (void)
    Rte_Write_F193_ECUHardwareVersionNumber_Byte4_F193_ECUHardwareVersionNumber_Byte4
    (Dcm_Did_Block00AB_Data.Dcm_DidF193Buffer[4]);

  /* Outport: '<Root>/F193_ECUHardwareVersionNumber_Byte6_F193_ECUHardwareVersionNumber_Byte6' */
  (void)
    Rte_Write_F193_ECUHardwareVersionNumber_Byte6_F193_ECUHardwareVersionNumber_Byte6
    (Dcm_Did_Block00AB_Data.Dcm_DidF193Buffer[6]);

  /* Outport: '<Root>/F193_ECUHardwareVersionNumber_Byte7_F193_ECUHardwareVersionNumber_Byte7' */
  (void)
    Rte_Write_F193_ECUHardwareVersionNumber_Byte7_F193_ECUHardwareVersionNumber_Byte7
    (Dcm_Did_Block00AB_Data.Dcm_DidF193Buffer[7]);

  /* Outport: '<Root>/F193_ECUHardwareVersionNumber_Byte8_F193_ECUHardwareVersionNumber_Byte8' */
  (void)
    Rte_Write_F193_ECUHardwareVersionNumber_Byte8_F193_ECUHardwareVersionNumber_Byte8
    (Dcm_Did_Block00AB_Data.Dcm_DidF193Buffer[8]);

  /* Outport: '<Root>/F195_ECUSoftwareVersionNumber_Byte2_F195_ECUSoftwareVersionNumber_Byte2' */
  (void)
    Rte_Write_F195_ECUSoftwareVersionNumber_Byte2_F195_ECUSoftwareVersionNumber_Byte2
    (Dcm_Did_Block00AC_Data.Dcm_DidF195Buffer[2]);

  /* Outport: '<Root>/F195_ECUSoftwareVersionNumber_Byte3_F195_ECUSoftwareVersionNumber_Byte3' */
  (void)
    Rte_Write_F195_ECUSoftwareVersionNumber_Byte3_F195_ECUSoftwareVersionNumber_Byte3
    (Dcm_Did_Block00AC_Data.Dcm_DidF195Buffer[3]);

  /* Outport: '<Root>/F195_ECUSoftwareVersionNumber_Byte4_F195_ECUSoftwareVersionNumber_Byte4' */
  (void)
    Rte_Write_F195_ECUSoftwareVersionNumber_Byte4_F195_ECUSoftwareVersionNumber_Byte4
    (Dcm_Did_Block00AC_Data.Dcm_DidF195Buffer[4]);

  /* Outport: '<Root>/F195_ECUSoftwareVersionNumber_Byte6_F195_ECUSoftwareVersionNumber_Byte6' */
  (void)
    Rte_Write_F195_ECUSoftwareVersionNumber_Byte6_F195_ECUSoftwareVersionNumber_Byte6
    (Dcm_Did_Block00AC_Data.Dcm_DidF195Buffer[6]);

  /* Outport: '<Root>/F195_ECUSoftwareVersionNumber_Byte7_F195_ECUSoftwareVersionNumber_Byte7' */
  (void)
    Rte_Write_F195_ECUSoftwareVersionNumber_Byte7_F195_ECUSoftwareVersionNumber_Byte7
    (Dcm_Did_Block00AC_Data.Dcm_DidF195Buffer[7]);

  /* Outport: '<Root>/F195_ECUSoftwareVersionNumber_Byte8_F195_ECUSoftwareVersionNumber_Byte8' */
  (void)
    Rte_Write_F195_ECUSoftwareVersionNumber_Byte8_F195_ECUSoftwareVersionNumber_Byte8
    (Dcm_Did_Block00AC_Data.Dcm_DidF195Buffer[8]);

  /* Outport: '<Root>/PDC_Status_CsmErrFlg_PDC_Status_CsmErrFlg' */
  (void)Rte_Write_PDC_Status_CsmErrFlg_PDC_Status_CsmErrFlg(CAND_0x2CF_CheckSumErr);

  /* Outport: '<Root>/PDCStatus_AlvCtrErrFlg_PDCStatus_AlvCtrErrFlg' */
  (void)Rte_Write_PDCStatus_AlvCtrErrFlg_PDCStatus_AlvCtrErrFlg(CAND_0x2CF_AliveCntErr);

  /* Outport: '<Root>/PMS_SWCompileDay_PMS_SWCompileDay' */
  (void)Rte_Write_PMS_SWCompileDay_PMS_SWCompileDay(PMS_SWCompileTime[2]);

  /* Outport: '<Root>/PMS_SWCompileMonth_PMS_SWCompileMonth' */
  (void)Rte_Write_PMS_SWCompileMonth_PMS_SWCompileMonth(PMS_SWCompileTime[1]);

  /* Outport: '<Root>/PMS_SWCompileYear_PMS_SWCompileYear' */
  (void)Rte_Write_PMS_SWCompileYear_PMS_SWCompileYear(PMS_SWCompileTime[0]);

  /* Outport: '<Root>/s2vd_BMS_PmtCutoffLVFb_s2vd_BMS_PmtCutoffLVFb' */
  (void)Rte_Write_s2vd_BMS_PmtCutoffLVFb_s2vd_BMS_PmtCutoffLVFb((Ea_ShutdownReq==2));

  /* Outport: '<Root>/vild_b_adcCanBusOff_vild_b_adcCanBusOff' */
  (void)Rte_Write_vild_b_adcCanBusOff_vild_b_adcCanBusOff(CAND_stBusoffFlg);

  /* Outport: '<Root>/vild_b_evCanBusOff_vild_b_evCanBusOff' */
  (void)Rte_Write_vild_b_evCanBusOff_vild_b_evCanBusOff(CANA_stBusoffFlg);

  /* Outport: '<Root>/vild_b_flgABSMsgErr_vild_b_flgABSMsgErr' */
  (void)Rte_Write_vild_b_flgABSMsgErr_vild_b_flgABSMsgErr(PMS_EHB_communication_lost);

  /* Outport: '<Root>/vild_b_flgABSSpdMsgErr_vild_b_flgABSSpdMsgErr' */
  (void)Rte_Write_vild_b_flgABSSpdMsgErr_vild_b_flgABSSpdMsgErr(PMS_Speed_communication_lost);

  /* Outport: '<Root>/vild_b_flgACUAlvCtrErr_vild_b_flgACUAlvCtrErr' */
  (void)Rte_Write_vild_b_flgACUAlvCtrErr_vild_b_flgACUAlvCtrErr(CAND_0x380_AliveCntErr);

  /* Outport: '<Root>/vild_b_flgACUCsmErr_vild_b_flgACUCsmErr' */
  (void)Rte_Write_vild_b_flgACUCsmErr_vild_b_flgACUCsmErr(CAND_0x380_CheckSumErr);

  /* Outport: '<Root>/vild_b_flgACUMsgErr_vild_b_flgACUMsgErr' */
  (void)Rte_Write_vild_b_flgACUMsgErr_vild_b_flgACUMsgErr(PMS_ACU_communication_lost);

  /* Outport: '<Root>/vild_b_flgBBMMsgErr_vild_b_flgBBMMsgErr' */
  (void)Rte_Write_vild_b_flgBBMMsgErr_vild_b_flgBBMMsgErr(false);

  /* Outport: '<Root>/vild_b_flgBMSAlvCtrErr_vild_b_flgBMSAlvCtrErr' */
  (void)Rte_Write_vild_b_flgBMSAlvCtrErr_vild_b_flgBMSAlvCtrErr(false);

  /* Outport: '<Root>/vild_b_flgBMSCsmErr_vild_b_flgBMSCsmErr' */
  (void)Rte_Write_vild_b_flgBMSCsmErr_vild_b_flgBMSCsmErr(false);

  /* Outport: '<Root>/vild_b_flgBMSMsgErr_vild_b_flgBMSMsgErr' */
  (void)Rte_Write_vild_b_flgBMSMsgErr_vild_b_flgBMSMsgErr(false);

  /* Outport: '<Root>/vild_b_flgClearDTC_vild_b_flgClearDTC' */
  (void)Rte_Write_vild_b_flgClearDTC_vild_b_flgClearDTC(false);

  /* Outport: '<Root>/vild_b_flgCSMAlvCtrErr_vild_b_flgCSMAlvCtrErr' */
  (void)Rte_Write_vild_b_flgCSMAlvCtrErr_vild_b_flgCSMAlvCtrErr(CANB_0x3CA_AliveCntErr);

  /* Outport: '<Root>/vild_b_flgCSMCsmErr_vild_b_flgCSMCsmErr' */
  (void)Rte_Write_vild_b_flgCSMCsmErr_vild_b_flgCSMCsmErr(CANB_0x3CA_CheckSumErr);

  /* Outport: '<Root>/vild_b_flgCSMMsgErr_vild_b_flgCSMMsgErr' */
  (void)Rte_Write_vild_b_flgCSMMsgErr_vild_b_flgCSMMsgErr(PMS_CSM_communication_lost);

  /* Outport: '<Root>/vild_b_flgDCDCMsgErr_vild_b_flgDCDCMsgErr' */
  (void)Rte_Write_vild_b_flgDCDCMsgErr_vild_b_flgDCDCMsgErr(PMS_DCDC_communication_lost);

  /* Outport: '<Root>/vild_b_flgEGSMAlvCtrErr_vild_b_flgEGSMAlvCtrErr' */
  (void)Rte_Write_vild_b_flgEGSMAlvCtrErr_vild_b_flgEGSMAlvCtrErr(CANA_0x145_AliveCntErr);

  /* Outport: '<Root>/vild_b_flgEGSMCsmErr_vild_b_flgEGSMCsmErr' */
  (void)Rte_Write_vild_b_flgEGSMCsmErr_vild_b_flgEGSMCsmErr(CANA_0x145_CheckSumErr);

  /* Outport: '<Root>/vild_b_flgEGSMMsgErr_vild_b_flgEGSMMsgErr' */
  (void)Rte_Write_vild_b_flgEGSMMsgErr_vild_b_flgEGSMMsgErr(PMS_EGSM_communication_lost);

  /* Outport: '<Root>/vild_b_flgEHBAlvCtrErr_vild_b_flgEHBAlvCtrErr' */
  (void)Rte_Write_vild_b_flgEHBAlvCtrErr_vild_b_flgEHBAlvCtrErr(CAND_0x125_AliveCntErr);

  /* Outport: '<Root>/vild_b_flgEHBCsmErr_vild_b_flgEHBCsmErr' */
  (void)Rte_Write_vild_b_flgEHBCsmErr_vild_b_flgEHBCsmErr(CAND_0x125_CheckSumErr);

  /* Outport: '<Root>/vild_b_flgIPUAlvCtrErr_vild_b_flgIPUAlvCtrErr' */
  (void)Rte_Write_vild_b_flgIPUAlvCtrErr_vild_b_flgIPUAlvCtrErr(false);

  /* Outport: '<Root>/vild_b_flgIPUCsmErr_vild_b_flgIPUCsmErr' */
  (void)Rte_Write_vild_b_flgIPUCsmErr_vild_b_flgIPUCsmErr(false);

  /* Outport: '<Root>/vild_b_flgMCUMsgErr_vild_b_flgMCUMsgErr' */
  (void)Rte_Write_vild_b_flgMCUMsgErr_vild_b_flgMCUMsgErr(false);

  /* Outport: '<Root>/vild_b_flgPEPSAlvErr_vild_b_flgPEPSAlvErr' */
  (void)Rte_Write_vild_b_flgPEPSAlvErr_vild_b_flgPEPSAlvErr(CANB_0x1E2_AliveCntErr);

  /* Outport: '<Root>/vild_b_flgPEPSCsmErr_vild_b_flgPEPSCsmErr' */
  (void)Rte_Write_vild_b_flgPEPSCsmErr_vild_b_flgPEPSCsmErr(CANB_0x1E2_CheckSumErr);

  /* Outport: '<Root>/vild_b_flgPEPSMsgErr_vild_b_flgPEPSMsgErr' */
  (void)Rte_Write_vild_b_flgPEPSMsgErr_vild_b_flgPEPSMsgErr(PMS_PEPS_communication_lost);

  /* Outport: '<Root>/vild_b_pmsCanBusOff_vild_b_pmsCanBusOff' */
  (void)Rte_Write_vild_b_pmsCanBusOff_vild_b_pmsCanBusOff(CANB_stBusoffFlg);
}

/* Model initialize function */
void PMS_BswAswRte_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
