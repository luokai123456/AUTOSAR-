/*
 * File: MCU_fc_BIfRx_IN.c
 *
 * Code generated for Simulink model 'MCU_fc_BIfRx_IN'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Apr 24 11:00:19 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MCU_fc_BIfRx_IN.h"
//#include "SigPreProcessor.h"

/* Model step function for TID1 */
void MCU_fc_BIfRx_IN_100us(void)      /* Explicit Task: MCU_fc_BIfRx_IN_100us */
{
  /* Outport: '<Root>/BSW_f32_ChrgWakeup_State_BSW_f32_ChrgWakeup_State' */
  (void)Rte_Write_BSW_f32_ChrgWakeup_State_BSW_f32_ChrgWakeup_State(SGPP_BSW_f32_ChrgWakeup_State);

  /* Outport: '<Root>/BSW_f32_Drive_Error_BSW_f32_Drive_Error' */
  (void)Rte_Write_BSW_f32_Drive_Error_BSW_f32_Drive_Error(SGPP_BSW_f32_Drive_Error);

  /* Outport: '<Root>/BSW_f32_DriveHBridg_Error_BSW_f32_DriveHBridg_Error' */
  (void)Rte_Write_BSW_f32_DriveHBridg_Error_BSW_f32_DriveHBridg_Error(SGPP_BSW_f32_DriveHBridg_Error);

  /* Outport: '<Root>/BSW_f32_DriveLBridg_Error_BSW_f32_DriveLBridg_Error' */
  (void)Rte_Write_BSW_f32_DriveLBridg_Error_BSW_f32_DriveLBridg_Error(SGPP_BSW_f32_DriveLBridg_Error);

  /* Outport: '<Root>/BSW_f32_eAngle_rad_BSW_f32_eAngle_rad' */
  (void)Rte_Write_BSW_f32_eAngle_rad_BSW_f32_eAngle_rad(SGPP_BSW_f32_eAngle_rad);

  /* Outport: '<Root>/BSW_f32_iSmpPhaU_A_BSW_f32_iSmpPhaU_A' */
  (void)Rte_Write_BSW_f32_iSmpPhaU_A_BSW_f32_iSmpPhaU_A(SGPP_BSW_f32_iSmpPhaU_A);

  /* Outport: '<Root>/BSW_f32_iSmpPhaV_A_BSW_f32_iSmpPhaV_A' */
  (void)Rte_Write_BSW_f32_iSmpPhaV_A_BSW_f32_iSmpPhaV_A(SGPP_BSW_f32_iSmpPhaV_A);

  /* Outport: '<Root>/BSW_f32_iSmpPhaW_A_BSW_f32_iSmpPhaW_A' */
  (void)Rte_Write_BSW_f32_iSmpPhaW_A_BSW_f32_iSmpPhaW_A(SGPP_BSW_f32_iSmpPhaW_A);

  /* Outport: '<Root>/BSW_f32_KL15_State_BSW_f32_KL15_State' */
  (void)Rte_Write_BSW_f32_KL15_State_BSW_f32_KL15_State(SGPP_BSW_f32_KL15_State);

  /* Outport: '<Root>/BSW_f32_nRotateSpd_rpm_BSW_f32_nRotateSpd_rpm' */
  (void)Rte_Write_BSW_f32_nRotateSpd_rpm_BSW_f32_nRotateSpd_rpm(SGPP_BSW_f32_nRotateSpd_rpm);

  /* Outport: '<Root>/BSW_f32_RDC_CosEvlp_BSW_f32_RDC_CosEvlp' */
  (void)Rte_Write_BSW_f32_RDC_CosEvlp_BSW_f32_RDC_CosEvlp(SGPP_BSW_f32_RDC_CosEvlp);

  /* Outport: '<Root>/BSW_f32_RDC_SinEvlp_BSW_f32_RDC_SinEvlp' */
  (void)Rte_Write_BSW_f32_RDC_SinEvlp_BSW_f32_RDC_SinEvlp(SGPP_BSW_f32_RDC_SinEvlp);

  /* Outport: '<Root>/BSW_f32_tIGBTTempU_C_BSW_f32_tIGBTTempU_C' */
  (void)Rte_Write_BSW_f32_tIGBTTempU_C_BSW_f32_tIGBTTempU_C(SGPP_BSW_f32_tIGBTTempU_C);

  /* Outport: '<Root>/BSW_f32_tIGBTTempV_C_BSW_f32_tIGBTTempV_C' */
  (void)Rte_Write_BSW_f32_tIGBTTempV_C_BSW_f32_tIGBTTempV_C(SGPP_BSW_f32_tIGBTTempV_C);

  /* Outport: '<Root>/BSW_f32_tIGBTTempW_C_BSW_f32_tIGBTTempW_C' */
  (void)Rte_Write_BSW_f32_tIGBTTempW_C_BSW_f32_tIGBTTempW_C(SGPP_BSW_f32_tIGBTTempW_C);

  /* Outport: '<Root>/BSW_f32_tMotTemp_C_BSW_f32_tMotTemp_C' */
  (void)Rte_Write_BSW_f32_tMotTemp_C_BSW_f32_tMotTemp_C(SGPP_BSW_f32_tMotTemp_C);

  /* Outport: '<Root>/BSW_f32_u12V_V_BSW_f32_u12V_V' */
  (void)Rte_Write_BSW_f32_u12V_V_BSW_f32_u12V_V(SGPP_BSW_f32_u12V_V);

  /* Outport: '<Root>/BSW_f32_u5V_V_BSW_f32_u5V_V' */
  (void)Rte_Write_BSW_f32_u5V_V_BSW_f32_u5V_V(SGPP_BSW_f32_u5V_V);

  /* Outport: '<Root>/BSW_f32_uCurrSnsrRefSmp_V_BSW_f32_uCurrSnsrRefSmp_V' */
  (void)Rte_Write_BSW_f32_uCurrSnsrRefSmp_V_BSW_f32_uCurrSnsrRefSmp_V(SGPP_BSW_f32_uCurrSnsrRefSmp_V);

  /* Outport: '<Root>/BSW_f32_uCurrSnsrUSmp_V_BSW_f32_uCurrSnsrUSmp_V' */
  (void)Rte_Write_BSW_f32_uCurrSnsrUSmp_V_BSW_f32_uCurrSnsrUSmp_V(SGPP_BSW_f32_uCurrSnsrUSmp_V);

  /* Outport: '<Root>/BSW_f32_uCurrSnsrVSmp_V_BSW_f32_uCurrSnsrVSmp_V' */
  (void)Rte_Write_BSW_f32_uCurrSnsrVSmp_V_BSW_f32_uCurrSnsrVSmp_V(SGPP_BSW_f32_uCurrSnsrVSmp_V);

  /* Outport: '<Root>/BSW_f32_uCurrSnsrWSmp_V_BSW_f32_uCurrSnsrWSmp_V' */
  (void)Rte_Write_BSW_f32_uCurrSnsrWSmp_V_BSW_f32_uCurrSnsrWSmp_V(SGPP_BSW_f32_uCurrSnsrWSmp_V);

  /* Outport: '<Root>/BSW_f32_uDCActSmp_V_BSW_f32_uDCActSmp_V' */
  (void)Rte_Write_BSW_f32_uDCActSmp_V_BSW_f32_uDCActSmp_V(SGPP_BSW_f32_uDCActSmp_V);

  /* Outport: '<Root>/BSW_f32_uDcHV_V_BSW_f32_uDcHV_V' */
  (void)Rte_Write_BSW_f32_uDcHV_V_BSW_f32_uDcHV_V(SGPP_BSW_f32_uDcHV_V);

  /* Outport: '<Root>/BSW_f32_uDcHVSmp_V_BSW_f32_uDcHVSmp_V' */
  (void)Rte_Write_BSW_f32_uDcHVSmp_V_BSW_f32_uDcHVSmp_V(SGPP_BSW_f32_uDcHVSmp_V);

  /* Outport: '<Root>/BSW_f32_uIGBTTempUSmp_V_BSW_f32_uIGBTTempUSmp_V' */
  (void)Rte_Write_BSW_f32_uIGBTTempUSmp_V_BSW_f32_uIGBTTempUSmp_V(SGPP_BSW_f32_uIGBTTempUSmp_V);

  /* Outport: '<Root>/BSW_f32_uIGBTTempVSmp_V_BSW_f32_uIGBTTempVSmp_V' */
  (void)Rte_Write_BSW_f32_uIGBTTempVSmp_V_BSW_f32_uIGBTTempVSmp_V(SGPP_BSW_f32_uIGBTTempVSmp_V);

  /* Outport: '<Root>/BSW_f32_uIGBTTempWSmp_V_BSW_f32_uIGBTTempWSmp_V' */
  (void)Rte_Write_BSW_f32_uIGBTTempWSmp_V_BSW_f32_uIGBTTempWSmp_V(SGPP_BSW_f32_uIGBTTempWSmp_V);

  /* Outport: '<Root>/BSW_f32_uMotTempSmp_V_BSW_f32_uMotTempSmp_V' */
  (void)Rte_Write_BSW_f32_uMotTempSmp_V_BSW_f32_uMotTempSmp_V(SGPP_BSW_f32_uMotTempSmp_V);

  /* Outport: '<Root>/BSW_u8_bERCNVFlt_BSW_u8_bERCNVFlt' */
  (void)Rte_Write_BSW_u8_bERCNVFlt_BSW_u8_bERCNVFlt(SGPP_BSW_u8_bERCNVFlt);

  /* Outport: '<Root>/BSW_u8_bERDCNVFlt_BSW_u8_bERDCNVFlt' */
  (void)Rte_Write_BSW_u8_bERDCNVFlt_BSW_u8_bERDCNVFlt(SGPP_BSW_u8_bERDCNVFlt);

  /* Outport: '<Root>/BSW_u8_bERDEXCFlt_BSW_u8_bERDEXCFlt' */
  (void)Rte_Write_BSW_u8_bERDEXCFlt_BSW_u8_bERDEXCFlt(SGPP_BSW_u8_bERDEXCFlt);

  /* Outport: '<Root>/BSW_u8_bERDP2Flt_BSW_u8_bERDP2Flt' */
  (void)Rte_Write_BSW_u8_bERDP2Flt_BSW_u8_bERDP2Flt(SGPP_BSW_u8_bERDP2Flt);

  /* Outport: '<Root>/BSW_u8_bERDSBCFlt_BSW_u8_bERDSBCFlt' */
  (void)Rte_Write_BSW_u8_bERDSBCFlt_BSW_u8_bERDSBCFlt(SGPP_BSW_u8_bERDSBCFlt);

  /* Outport: '<Root>/BSW_u8_bERDSBSFlt_BSW_u8_bERDSBSFlt' */
  (void)Rte_Write_BSW_u8_bERDSBSFlt_BSW_u8_bERDSBSFlt(SGPP_BSW_u8_bERDSBSFlt);

  /* Outport: '<Root>/BSW_u8_bERDSQFlt_BSW_u8_bERDSQFlt' */
  (void)Rte_Write_BSW_u8_bERDSQFlt_BSW_u8_bERDSQFlt(SGPP_BSW_u8_bERDSQFlt);

  /* Outport: '<Root>/BSW_u8_bEREXCFlt_BSW_u8_bEREXCFlt' */
  (void)Rte_Write_BSW_u8_bEREXCFlt_BSW_u8_bEREXCFlt(SGPP_BSW_u8_bEREXCFlt);

  /* Outport: '<Root>/BSW_u8_bERHDFlt_BSW_u8_bERHDFlt' */
  (void)Rte_Write_BSW_u8_bERHDFlt_BSW_u8_bERHDFlt(SGPP_BSW_u8_bERHDFlt);

  /* Outport: '<Root>/BSW_u8_bERP2Flt_BSW_u8_bERP2Flt' */
  (void)Rte_Write_BSW_u8_bERP2Flt_BSW_u8_bERP2Flt(SGPP_BSW_u8_bERP2Flt);

  /* Outport: '<Root>/BSW_u8_bERRFlt_BSW_u8_bERRFlt' */
  (void)Rte_Write_BSW_u8_bERRFlt_BSW_u8_bERRFlt(SGPP_BSW_u8_bERRFlt);

  /* Outport: '<Root>/BSW_u8_bERSBCFlt_BSW_u8_bERSBCFlt' */
  (void)Rte_Write_BSW_u8_bERSBCFlt_BSW_u8_bERSBCFlt(SGPP_BSW_u8_bERSBCFlt);

  /* Outport: '<Root>/BSW_u8_bERSBSFlt_BSW_u8_bERSBSFlt' */
  (void)Rte_Write_BSW_u8_bERSBSFlt_BSW_u8_bERSBSFlt(SGPP_BSW_u8_bERSBSFlt);

  /* Outport: '<Root>/BSW_u8_bERSQFlt_BSW_u8_bERSQFlt' */
  (void)Rte_Write_BSW_u8_bERSQFlt_BSW_u8_bERSQFlt(SGPP_BSW_u8_bERSQFlt);

  /* Outport: '<Root>/BSW_u8_bMcuStorgUnitFlt_BSW_u8_bMcuStorgUnitFlt' */
  (void)Rte_Write_BSW_u8_bMcuStorgUnitFlt_BSW_u8_bMcuStorgUnitFlt(SGPP_BSW_u8_bMcuStorgUnitFlt);

  /* Outport: '<Root>/BSW_u8_bRotyTrfrDosFlt_BSW_u8_bRotyTrfrDosFlt' */
  (void)Rte_Write_BSW_u8_bRotyTrfrDosFlt_BSW_u8_bRotyTrfrDosFlt(SGPP_BSW_u8_bRotyTrfrDosFlt);

  /* Outport: '<Root>/BSW_u8_bRotyTrfrFlt_BSW_u8_bRotyTrfrFlt' */
  (void)Rte_Write_BSW_u8_bRotyTrfrFlt_BSW_u8_bRotyTrfrFlt(SGPP_BSW_u8_bRotyTrfrFlt);

  /* Outport: '<Root>/BSW_u8_bRotyTrfrLosFlt_BSW_u8_bRotyTrfrLosFlt' */
  (void)Rte_Write_BSW_u8_bRotyTrfrLosFlt_BSW_u8_bRotyTrfrLosFlt(SGPP_BSW_u8_bRotyTrfrLosFlt);

  /* Outport: '<Root>/BSW_u8_bRotyTrfrLotFlt_BSW_u8_bRotyTrfrLotFlt' */
  (void)Rte_Write_BSW_u8_bRotyTrfrLotFlt_BSW_u8_bRotyTrfrLotFlt(SGPP_BSW_u8_bRotyTrfrLotFlt);

  /* Outport: '<Root>/BSW_u8_DriFault_UH_BSW_u8_DriFault_UH' */
  (void)Rte_Write_BSW_u8_DriFault_UH_BSW_u8_DriFault_UH(SGPP_BSW_u8_DriFault_UH);

  /* Outport: '<Root>/BSW_u8_DriFault_UL_BSW_u8_DriFault_UL' */
  (void)Rte_Write_BSW_u8_DriFault_UL_BSW_u8_DriFault_UL(SGPP_BSW_u8_DriFault_UL);

  /* Outport: '<Root>/BSW_u8_DriFault_VH_BSW_u8_DriFault_VH' */
  (void)Rte_Write_BSW_u8_DriFault_VH_BSW_u8_DriFault_VH(SGPP_BSW_u8_DriFault_VH);

  /* Outport: '<Root>/BSW_u8_DriFault_VL_BSW_u8_DriFault_VL' */
  (void)Rte_Write_BSW_u8_DriFault_VL_BSW_u8_DriFault_VL(SGPP_BSW_u8_DriFault_VL);

  /* Outport: '<Root>/BSW_u8_DriFault_WH_BSW_u8_DriFault_WH' */
  (void)Rte_Write_BSW_u8_DriFault_WH_BSW_u8_DriFault_WH(SGPP_BSW_u8_DriFault_WH);

  /* Outport: '<Root>/BSW_u8_DriFault_WL_BSW_u8_DriFault_WL' */
  (void)Rte_Write_BSW_u8_DriFault_WL_BSW_u8_DriFault_WL(SGPP_BSW_u8_DriFault_WL);

  /* Outport: '<Root>/BSW_u8_HWOCFlt_BSW_u8_HWOCFlt' */
  (void)Rte_Write_BSW_u8_HWOCFlt_BSW_u8_HWOCFlt(SGPP_BSW_u8_HWOCFlt);

  /* Outport: '<Root>/BSW_u8_HWOVFlt_BSW_u8_HWOVFlt' */
  (void)Rte_Write_BSW_u8_HWOVFlt_BSW_u8_HWOVFlt(SGPP_BSW_u8_HWOVFlt);

  /* Outport: '<Root>/BSW_u8_stPWM_BSW_u8_stPWM' */
  (void)Rte_Write_BSW_u8_stPWM_BSW_u8_stPWM(SGPP_BSW_u8_stPWM);
}

/* Model initialize function */
void MCU_fc_BIfRx_IN_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
