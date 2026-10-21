/*
 * File: swc_SetSendCANMsg.c
 *
 * Code generated for Simulink model 'swc_SetSendCANMsg'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon Jun  8 19:09:54 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "swc_SetSendCANMsg.h"
#include "swc_SetSendCANMsg_private.h"
extern uint8 Ea_fgSendBCLMsg;              /* 请求发送BCL报文报文 */
extern uint8 Ea_fgSendBCPMsg;              /* 请求发送BCP报文报文 */
extern uint8 Ea_fgSendBCPPMsg;             /* 请求发送BCPP报文报文 */
extern uint8 Ea_fgSendBCSMsg;              /* 请求发送BCS报文报文 */
extern uint8 Ea_fgSendBCSPMsg;             /* 请求发送BCSP报文报文 */
extern uint8 Ea_fgSendBDCMsg;              /* 请求发送BDC报文报文 */
extern uint8 Ea_fgSendBEMMsg;              /* 请求发送BEM报文报文 */
extern uint8 Ea_fgSendBHMMsg;              /* 请求发送BHM报文报文 */
extern uint8 Ea_fgSendBMTMsg;              /* 请求发送BMT报文报文 */
extern uint8 Ea_fgSendBMVMsg;              /* 请求发送BMV报文报文 */
extern uint8 Ea_fgSendBRMMsg;              /* 请求发送BRM报文报文 */
extern uint8 Ea_fgSendBROMsg;              /* 请求发送BRO报文报文 */
extern uint8 Ea_fgSendBRDMsg;              /* 请求发送BRD报文报文 */
extern uint8 Ea_fgSendBSDMsg;              /* 请求发送BSD报文报文 */
extern uint8 Ea_fgSendBSMMsg;              /* 请求发送BSM报文报文 */
extern uint8 Ea_fgSendBSPMsg;              /* 请求发送BSP报文报文 */
extern uint8 Ea_fgSendBSTMsg;              /* 请求发送BST报文报文 */
extern uint8 Ea_fgSendFastChgStopInfo;     /* 请求发送BMS_FastChgStopInfo报文 */
/* Model step function for TID1 */
void swc_SetSendCANMsg_10ms(void)    /* Explicit Task: swc_SetSendCANMsg_10ms */
{
  uint16 tmpRead_0;
  uint16 tmpRead_1;
  uint8 tmpRead;
  uint8 tmpRead_2;
  uint8 tmpRead_3;
  uint8 tmpRead_4;
  uint8 tmpRead_5;
  uint8 tmpRead_6;
  uint8 tmpRead_7;
  uint8 tmpRead_8;
  uint8 tmpRead_9;
  uint8 tmpRead_a;
  uint8 tmpRead_b;
  uint8 tmpRead_c;
  uint8 tmpRead_d;
  uint8 tmpRead_e;
  uint8 tmpRead_f;

  /* Inport: '<Root>/R_BST_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay' */
  (void)Rte_Read_R_BST_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay
    (&tmpRead_f);

  /* Inport: '<Root>/R_BST_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection' */
  (void)
    Rte_Read_R_BST_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection
    (&tmpRead_e);

  /* Inport: '<Root>/R_BST_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp' */
  (void)Rte_Read_R_BST_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp
    (&tmpRead_d);

  /* Inport: '<Root>/R_BST_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults' */
  (void)Rte_Read_R_BST_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults
    (&tmpRead_c);

  /* Inport: '<Root>/R_BST_BmsSuspFault_Insulation_BmsSuspFault_Insulation' */
  (void)Rte_Read_R_BST_BmsSuspFault_Insulation_BmsSuspFault_Insulation
    (&tmpRead_b);

  /* Inport: '<Root>/R_BST_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn' */
  (void)Rte_Read_R_BST_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn
    (&tmpRead_a);

  /* Inport: '<Root>/R_BST_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp' */
  (void)Rte_Read_R_BST_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp(&tmpRead_9);

  /* Inport: '<Root>/R_BST_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp' */
  (void)Rte_Read_R_BST_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp
    (&tmpRead_8);

  /* Inport: '<Root>/R_BST_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent' */
  (void)
    Rte_Read_R_BST_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent
    (&tmpRead_7);

  /* Inport: '<Root>/R_BST_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage' */
  (void)Rte_Read_R_BST_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage
    (&tmpRead_6);

  /* Inport: '<Root>/R_BST_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage' */
  (void)Rte_Read_R_BST_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage
    (&tmpRead_5);

  /* Inport: '<Root>/R_BST_BmsSuspCause_SOC_BmsSuspCause_SOC' */
  (void)Rte_Read_R_BST_BmsSuspCause_SOC_BmsSuspCause_SOC(&tmpRead_4);

  /* Inport: '<Root>/R_BST_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage' */
  (void)Rte_Read_R_BST_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage
    (&tmpRead_3);

  /* Inport: '<Root>/R_BST_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend' */
  (void)Rte_Read_R_BST_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend
    (&tmpRead_2);

  /* Inport: '<Root>/R_BCL_VoltageDemand_VoltageDemand' */
  (void)Rte_Read_R_BCL_VoltageDemand_VoltageDemand(&tmpRead_1);

  /* Inport: '<Root>/R_BCL_CurrentDemand_CurrentDemand' */
  (void)Rte_Read_R_BCL_CurrentDemand_CurrentDemand(&tmpRead_0);

  /* Inport: '<Root>/R_BCL_ChargingMode_ChargingMode' */
  (void)Rte_Read_R_BCL_ChargingMode_ChargingMode(&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/swc_SetSendCANMsg_10ms' incorporates:
   *  SubSystem: '<Root>/swc_SetSendCANMsg_10ms_sys'
   */
  if(Ea_fgSendBCLMsg == 1)
  {
  /* Outport: '<Root>/S_BCL_ChargingMode_ChargingMode' incorporates:
   *  SignalConversion generated from: '<S3>/R_BCL_ChargingMode_ChargingMode_read'
   */
  (void)Rte_Write_S_BCL_ChargingMode_ChargingMode(tmpRead);

  /* Outport: '<Root>/S_BCL_CurrentDemand_CurrentDemand' incorporates:
   *  SignalConversion generated from: '<S3>/R_BCL_CurrentDemand_CurrentDemand_read'
   */
  (void)Rte_Write_S_BCL_CurrentDemand_CurrentDemand(tmpRead_0);

  /* Outport: '<Root>/S_BCL_VoltageDemand_VoltageDemand' incorporates:
   *  SignalConversion generated from: '<S3>/R_BCL_VoltageDemand_VoltageDemand_read'
   */
  (void)Rte_Write_S_BCL_VoltageDemand_VoltageDemand(tmpRead_1);
  }

  if(Ea_fgSendBSTMsg == 1)
  {
  /* Outport: '<Root>/S_BST_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend' incorporates:
   *  SignalConversion generated from: '<S3>/R_BST_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend_read'
   */
  (void)Rte_Write_S_BST_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend
    (tmpRead_2);

  /* Outport: '<Root>/S_BST_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage' incorporates:
   *  SignalConversion generated from: '<S3>/R_BST_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage_read'
   */
  (void)Rte_Write_S_BST_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage
    (tmpRead_3);

  /* Outport: '<Root>/S_BST_BmsSuspCause_SOC_BmsSuspCause_SOC' incorporates:
   *  SignalConversion generated from: '<S3>/R_BST_BmsSuspCause_SOC_BmsSuspCause_SOC_read'
   */
  (void)Rte_Write_S_BST_BmsSuspCause_SOC_BmsSuspCause_SOC(tmpRead_4);

  /* Outport: '<Root>/S_BST_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage' incorporates:
   *  SignalConversion generated from: '<S3>/R_BST_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage_read'
   */
  (void)Rte_Write_S_BST_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage
    (tmpRead_5);

  /* Outport: '<Root>/S_BST_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage' incorporates:
   *  SignalConversion generated from: '<S3>/R_BST_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage_read'
   */
  (void)
    Rte_Write_S_BST_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage
    (tmpRead_6);

  /* Outport: '<Root>/S_BST_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent' incorporates:
   *  SignalConversion generated from: '<S3>/R_BST_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent_read'
   */
  (void)
    Rte_Write_S_BST_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent
    (tmpRead_7);

  /* Outport: '<Root>/S_BST_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp' incorporates:
   *  SignalConversion generated from: '<S3>/R_BST_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp_read'
   */
  (void)Rte_Write_S_BST_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp
    (tmpRead_8);

  /* Outport: '<Root>/S_BST_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp' incorporates:
   *  SignalConversion generated from: '<S3>/R_BST_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp_read'
   */
  (void)Rte_Write_S_BST_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp(tmpRead_9);

  /* Outport: '<Root>/S_BST_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn' incorporates:
   *  SignalConversion generated from: '<S3>/R_BST_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn_read'
   */
  (void)Rte_Write_S_BST_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn
    (tmpRead_a);

  /* Outport: '<Root>/S_BST_BmsSuspFault_Insulation_BmsSuspFault_Insulation' incorporates:
   *  SignalConversion generated from: '<S3>/R_BST_BmsSuspFault_Insulation_BmsSuspFault_Insulation_read'
   */
  (void)Rte_Write_S_BST_BmsSuspFault_Insulation_BmsSuspFault_Insulation
    (tmpRead_b);

  /* Outport: '<Root>/S_BST_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults' incorporates:
   *  SignalConversion generated from: '<S3>/R_BST_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults_read'
   */
  (void)Rte_Write_S_BST_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults
    (tmpRead_c);

  /* Outport: '<Root>/S_BST_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp' incorporates:
   *  SignalConversion generated from: '<S3>/R_BST_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp_read'
   */
  (void)Rte_Write_S_BST_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp
    (tmpRead_d);

  /* Outport: '<Root>/S_BST_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection' incorporates:
   *  SignalConversion generated from: '<S3>/R_BST_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection_read'
   */
  (void)
    Rte_Write_S_BST_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection
    (tmpRead_e);

  /* Outport: '<Root>/S_BST_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay' incorporates:
   *  SignalConversion generated from: '<S3>/R_BST_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay_read'
   */
  (void)Rte_Write_S_BST_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay
    (tmpRead_f);
  }

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/swc_SetSendCANMsg_10ms' */
}

/* Model step function for TID2 */
void swc_SetSendCANMsg_100ms(void)  /* Explicit Task: swc_SetSendCANMsg_100ms */
{
  uint32 tmpRead_i;
  uint16 tmpRead;
  uint16 tmpRead_0;
  uint16 tmpRead_1d;
  uint16 tmpRead_1e;
  uint16 tmpRead_1h;
  uint16 tmpRead_1k;
  uint16 tmpRead_1l;
  uint16 tmpRead_1o;
  uint16 tmpRead_1r;
  uint16 tmpRead_1t;
  uint16 tmpRead_2;
  uint16 tmpRead_3;
  uint16 tmpRead_4;
  uint16 tmpRead_5;
  uint16 tmpRead_6;
  uint16 tmpRead_7;
  uint16 tmpRead_8;
  uint16 tmpRead_b;
  uint16 tmpRead_c;
  uint16 tmpRead_d;
  uint16 tmpRead_e;
  uint16 tmpRead_g;
  uint16 tmpRead_h;
  uint16 tmpRead_j;
  uint16 tmpRead_k;
  uint16 tmpRead_l;
  uint16 tmpRead_m;
  uint16 tmpRead_n;
  uint8 tmpRead_1;
  uint8 tmpRead_10;
  uint8 tmpRead_11;
  uint8 tmpRead_12;
  uint8 tmpRead_13;
  uint8 tmpRead_14;
  uint8 tmpRead_15;
  uint8 tmpRead_16;
  uint8 tmpRead_17;
  uint8 tmpRead_18;
  uint8 tmpRead_19;
  uint8 tmpRead_1a;
  uint8 tmpRead_1b;
  uint8 tmpRead_1c;
  uint8 tmpRead_1f;
  uint8 tmpRead_1g;
  uint8 tmpRead_1i;
  uint8 tmpRead_1j;
  uint8 tmpRead_1m;
  uint8 tmpRead_1n;
  uint8 tmpRead_1p;
  uint8 tmpRead_1q;
  uint8 tmpRead_1s;
  uint8 tmpRead_1u;
  uint8 tmpRead_1v;
  uint8 tmpRead_1w;
  uint8 tmpRead_1x;
  uint8 tmpRead_1y;
  uint8 tmpRead_1z;
  uint8 tmpRead_20;
  uint8 tmpRead_21;
  uint8 tmpRead_22;
  uint8 tmpRead_23;
  uint8 tmpRead_24;
  uint8 tmpRead_25;
  uint8 tmpRead_26;
  uint8 tmpRead_9;
  uint8 tmpRead_a;
  uint8 tmpRead_f;
  uint8 tmpRead_o;
  uint8 tmpRead_p;
  uint8 tmpRead_q;
  uint8 tmpRead_r;
  uint8 tmpRead_s;
  uint8 tmpRead_t;
  uint8 tmpRead_u;
  uint8 tmpRead_v;
  uint8 tmpRead_w;
  uint8 tmpRead_x;
  uint8 tmpRead_y;
  uint8 tmpRead_z;

  /* Inport: '<Root>/R_BSM_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState' */
  (void)
    Rte_Read_R_BSM_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState
    (&tmpRead_26);

  /* Inport: '<Root>/R_BSM_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage' */
  (void)Rte_Read_R_BSM_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage
    (&tmpRead_25);

  /* Inport: '<Root>/R_BSM_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo' */
  (void)
    Rte_Read_R_BSM_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo
    (&tmpRead_24);

  /* Inport: '<Root>/R_BSM_BsmChargingPermissible_BsmChargingPermissible' */
  (void)Rte_Read_R_BSM_BsmChargingPermissible_BsmChargingPermissible(&tmpRead_23);

  /* Inport: '<Root>/R_BSM_BatteryOutputConnectorState_BatteryOutputConnectorState' */
  (void)Rte_Read_R_BSM_BatteryOutputConnectorState_BatteryOutputConnectorState
    (&tmpRead_22);

  /* Inport: '<Root>/R_BSM_BatteryLowestTempSerNo_BatteryLowestTempSerNo' */
  (void)Rte_Read_R_BSM_BatteryLowestTempSerNo_BatteryLowestTempSerNo(&tmpRead_21);

  /* Inport: '<Root>/R_BSM_BatteryLowestTemp_BatteryLowestTemp' */
  (void)Rte_Read_R_BSM_BatteryLowestTemp_BatteryLowestTemp(&tmpRead_20);

  /* Inport: '<Root>/R_BSM_BatteryInsulationState_BatteryInsulationState' */
  (void)Rte_Read_R_BSM_BatteryInsulationState_BatteryInsulationState(&tmpRead_1z);

  /* Inport: '<Root>/R_BSM_BatteryHighestTempSerNo_BatteryHighestTempSerNo' */
  (void)Rte_Read_R_BSM_BatteryHighestTempSerNo_BatteryHighestTempSerNo
    (&tmpRead_1y);

  /* Inport: '<Root>/R_BSM_BatteryHighestTemp_BatteryHighestTemp' */
  (void)Rte_Read_R_BSM_BatteryHighestTemp_BatteryHighestTemp(&tmpRead_1x);

  /* Inport: '<Root>/R_BSM_BatteryExcessTemperature_BatteryExcessTemperature' */
  (void)Rte_Read_R_BSM_BatteryExcessTemperature_BatteryExcessTemperature
    (&tmpRead_1w);

  /* Inport: '<Root>/R_BSM_BatteryChargingOvercurrent_BatteryChargingOvercurrent' */
  (void)Rte_Read_R_BSM_BatteryChargingOvercurrent_BatteryChargingOvercurrent
    (&tmpRead_1v);

  /* Inport: '<Root>/R_BSD_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC' */
  (void)Rte_Read_R_BSD_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC
    (&tmpRead_1u);

  /* Inport: '<Root>/R_BSD_SingleBatteryMinVoltage_SingleBatteryMinVoltage' */
  (void)Rte_Read_R_BSD_SingleBatteryMinVoltage_SingleBatteryMinVoltage
    (&tmpRead_1t);

  /* Inport: '<Root>/R_BSD_SingleBatteryMinTemperature_SingleBatteryMinTemperature' */
  (void)Rte_Read_R_BSD_SingleBatteryMinTemperature_SingleBatteryMinTemperature
    (&tmpRead_1s);

  /* Inport: '<Root>/R_BSD_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage' */
  (void)Rte_Read_R_BSD_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage
    (&tmpRead_1r);

  /* Inport: '<Root>/R_BSD_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature' */
  (void)Rte_Read_R_BSD_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature
    (&tmpRead_1q);

  /* Inport: '<Root>/R_BRO_BmsReadyForCharging_BmsReadyForCharging' */
  (void)Rte_Read_R_BRO_BmsReadyForCharging_BmsReadyForCharging(&tmpRead_1p);

  /* Inport: '<Root>/R_BRM_BmsVersion_BmsVersion' */
  (void)Rte_Read_R_BRM_BmsVersion_BmsVersion(&tmpRead_1o);

  /* Inport: '<Root>/R_BRM_BmsRevision_BmsRevision' */
  (void)Rte_Read_R_BRM_BmsRevision_BmsRevision(&tmpRead_1n);

  /* Inport: '<Root>/R_BRM_BatteryType_BatteryType' */
  (void)Rte_Read_R_BRM_BatteryType_BatteryType(&tmpRead_1m);

  /* Inport: '<Root>/R_BRM_BatterySystemVoltage_BatterySystemVoltage' */
  (void)Rte_Read_R_BRM_BatterySystemVoltage_BatterySystemVoltage(&tmpRead_1l);

  /* Inport: '<Root>/R_BRM_BatterySystemCapacity_BatterySystemCapacity' */
  (void)Rte_Read_R_BRM_BatterySystemCapacity_BatterySystemCapacity(&tmpRead_1k);

  /* Inport: '<Root>/R_BMS_CCUStopChgReason_BMS_CCUStopChgReason' */
  (void)Rte_Read_R_BMS_CCUStopChgReason_BMS_CCUStopChgReason(&tmpRead_1j);

  /* Inport: '<Root>/R_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason' */
  (void)Rte_Read_R_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason(&tmpRead_1i);

  /* Inport: '<Root>/R_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason' */
  (void)Rte_Read_R_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason(&tmpRead_1h);

  /* Inport: '<Root>/R_BMS_BMSStopChgReason_BMS_BMSStopChgReason' */
  (void)Rte_Read_R_BMS_BMSStopChgReason_BMS_BMSStopChgReason(&tmpRead_1g);

  /* Inport: '<Root>/R_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason' */
  (void)Rte_Read_R_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason(&tmpRead_1f);

  /* Inport: '<Root>/R_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason' */
  (void)Rte_Read_R_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason(&tmpRead_1e);

  /* Inport: '<Root>/R_BHM_MaxChargingVoltage_MaxChargingVoltage' */
  (void)Rte_Read_R_BHM_MaxChargingVoltage_MaxChargingVoltage(&tmpRead_1d);

  /* Inport: '<Root>/R_BEM_Timeout_CTS_CML_Timeout_CTS_CML' */
  (void)Rte_Read_R_BEM_Timeout_CTS_CML_Timeout_CTS_CML(&tmpRead_1c);

  /* Inport: '<Root>/R_BEM_Timeout_CST_Timeout_CST' */
  (void)Rte_Read_R_BEM_Timeout_CST_Timeout_CST(&tmpRead_1b);

  /* Inport: '<Root>/R_BEM_Timeout_CSD_Timeout_CSD' */
  (void)Rte_Read_R_BEM_Timeout_CSD_Timeout_CSD(&tmpRead_1a);

  /* Inport: '<Root>/R_BEM_Timeout_CRO_Timeout_CRO' */
  (void)Rte_Read_R_BEM_Timeout_CRO_Timeout_CRO(&tmpRead_19);

  /* Inport: '<Root>/R_BEM_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized' */
  (void)Rte_Read_R_BEM_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized
    (&tmpRead_18);

  /* Inport: '<Root>/R_BEM_Timeout_CRM_Recognized_Timeout_CRM_Recognized' */
  (void)Rte_Read_R_BEM_Timeout_CRM_Recognized_Timeout_CRM_Recognized(&tmpRead_17);

  /* Inport: '<Root>/R_BEM_Timeout_CCS_Timeout_CCS' */
  (void)Rte_Read_R_BEM_Timeout_CCS_Timeout_CCS(&tmpRead_16);

  /* Inport: '<Root>/R_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9' */
  (void)Rte_Read_R_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9(&tmpRead_15);

  /* Inport: '<Root>/R_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8' */
  (void)Rte_Read_R_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8(&tmpRead_14);

  /* Inport: '<Root>/R_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7' */
  (void)Rte_Read_R_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7(&tmpRead_13);

  /* Inport: '<Root>/R_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6' */
  (void)Rte_Read_R_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6(&tmpRead_12);

  /* Inport: '<Root>/R_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5' */
  (void)Rte_Read_R_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5(&tmpRead_11);

  /* Inport: '<Root>/R_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4' */
  (void)Rte_Read_R_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4(&tmpRead_10);

  /* Inport: '<Root>/R_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3' */
  (void)Rte_Read_R_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3(&tmpRead_z);

  /* Inport: '<Root>/R_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2' */
  (void)Rte_Read_R_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2(&tmpRead_y);

  /* Inport: '<Root>/R_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17' */
  (void)Rte_Read_R_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17(&tmpRead_x);

  /* Inport: '<Root>/R_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16' */
  (void)Rte_Read_R_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16(&tmpRead_w);

  /* Inport: '<Root>/R_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15' */
  (void)Rte_Read_R_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15(&tmpRead_v);

  /* Inport: '<Root>/R_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14' */
  (void)Rte_Read_R_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14(&tmpRead_u);

  /* Inport: '<Root>/R_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13' */
  (void)Rte_Read_R_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13(&tmpRead_t);

  /* Inport: '<Root>/R_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12' */
  (void)Rte_Read_R_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12(&tmpRead_s);

  /* Inport: '<Root>/R_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11' */
  (void)Rte_Read_R_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11(&tmpRead_r);

  /* Inport: '<Root>/R_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10' */
  (void)Rte_Read_R_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10(&tmpRead_q);

  /* Inport: '<Root>/R_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1' */
  (void)Rte_Read_R_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1(&tmpRead_p);

  /* Inport: '<Root>/R_BDC_Soc_BDC_Soc' */
  (void)Rte_Read_R_BDC_Soc_BDC_Soc(&tmpRead_o);

  /* Inport: '<Root>/R_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate' */
  (void)Rte_Read_R_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate
    (&tmpRead_n);

  /* Inport: '<Root>/R_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange' */
  (void)Rte_Read_R_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange
    (&tmpRead_m);

  /* Inport: '<Root>/R_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate' */
  (void)Rte_Read_R_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate(&tmpRead_l);

  /* Inport: '<Root>/R_BDC_Battery_energy_BDC_Battery_energy' */
  (void)Rte_Read_R_BDC_Battery_energy_BDC_Battery_energy(&tmpRead_k);

  /* Inport: '<Root>/R_BDC_Battery_capacity_BDC_Battery_capacity' */
  (void)Rte_Read_R_BDC_Battery_capacity_BDC_Battery_capacity(&tmpRead_j);

  /* Inport: '<Root>/R_BCSP_reserved_BCSP_reserved' */
  (void)Rte_Read_R_BCSP_reserved_BCSP_reserved(&tmpRead_i);

  /* Inport: '<Root>/R_BCSP_Remaining_range_BCSP_Remaining_range' */
  (void)Rte_Read_R_BCSP_Remaining_range_BCSP_Remaining_range(&tmpRead_h);

  /* Inport: '<Root>/R_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time' */
  (void)Rte_Read_R_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time
    (&tmpRead_g);

  /* Inport: '<Root>/R_BCS_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup' */
  (void)
    Rte_Read_R_BCS_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup
    (&tmpRead_f);

  /* Inport: '<Root>/R_BCS_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage' */
  (void)Rte_Read_R_BCS_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage
    (&tmpRead_e);

  /* Inport: '<Root>/R_BCS_MeasuredChargingVoltage_MeasuredChargingVoltage' */
  (void)Rte_Read_R_BCS_MeasuredChargingVoltage_MeasuredChargingVoltage
    (&tmpRead_d);

  /* Inport: '<Root>/R_BCS_MeasuredChargingCurrent_MeasuredChargingCurrent' */
  (void)Rte_Read_R_BCS_MeasuredChargingCurrent_MeasuredChargingCurrent
    (&tmpRead_c);

  /* Inport: '<Root>/R_BCS_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime' */
  (void)
    Rte_Read_R_BCS_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime
    (&tmpRead_b);

  /* Inport: '<Root>/R_BCS_CurrentChargeState_CurrentChargeState' */
  (void)Rte_Read_R_BCS_CurrentChargeState_CurrentChargeState(&tmpRead_a);

  /* Inport: '<Root>/R_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc' */
  (void)Rte_Read_R_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc(&tmpRead_9);

  /* Inport: '<Root>/R_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV' */
  (void)Rte_Read_R_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV(&tmpRead_8);

  /* Inport: '<Root>/R_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV' */
  (void)Rte_Read_R_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV(&tmpRead_7);

  /* Inport: '<Root>/R_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur' */
  (void)Rte_Read_R_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur(&tmpRead_6);

  /* Inport: '<Root>/R_BCP_TotalNominalEnergy_TotalNominalEnergy' */
  (void)Rte_Read_R_BCP_TotalNominalEnergy_TotalNominalEnergy(&tmpRead_5);

  /* Inport: '<Root>/R_BCP_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage' */
  (void)Rte_Read_R_BCP_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage
    (&tmpRead_4);

  /* Inport: '<Root>/R_BCP_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery' */
  (void)
    Rte_Read_R_BCP_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery
    (&tmpRead_3);

  /* Inport: '<Root>/R_BCP_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage' */
  (void)Rte_Read_R_BCP_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage
    (&tmpRead_2);

  /* Inport: '<Root>/R_BCP_MaxPermTemperature_MaxPermTemperature' */
  (void)Rte_Read_R_BCP_MaxPermTemperature_MaxPermTemperature(&tmpRead_1);

  /* Inport: '<Root>/R_BCP_MaxPermChargingCurrent_MaxPermChargingCurrent' */
  (void)Rte_Read_R_BCP_MaxPermChargingCurrent_MaxPermChargingCurrent(&tmpRead_0);

  /* Inport: '<Root>/R_BCP_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage' */
  (void)Rte_Read_R_BCP_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage
    (&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/swc_SetSendCANMsg_100ms' incorporates:
   *  SubSystem: '<Root>/swc_SetSendCANMsg_100ms_sys'
   */
  if(Ea_fgSendBCPMsg == 1)
  {
  /* Outport: '<Root>/S_BCP_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage' incorporates:
   *  SignalConversion generated from: '<S2>/R_BCP_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage_read'
   */
  (void)
    Rte_Write_S_BCP_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage
    (tmpRead);

  /* Outport: '<Root>/S_BCP_MaxPermChargingCurrent_MaxPermChargingCurrent' incorporates:
   *  SignalConversion generated from: '<S2>/R_BCP_MaxPermChargingCurrent_MaxPermChargingCurrent_read'
   */
  (void)Rte_Write_S_BCP_MaxPermChargingCurrent_MaxPermChargingCurrent(tmpRead_0);

  /* Outport: '<Root>/S_BCP_MaxPermTemperature_MaxPermTemperature' incorporates:
   *  SignalConversion generated from: '<S2>/R_BCP_MaxPermTemperature_MaxPermTemperature_read'
   */
  (void)Rte_Write_S_BCP_MaxPermTemperature_MaxPermTemperature(tmpRead_1);

  /* Outport: '<Root>/S_BCP_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage' incorporates:
   *  SignalConversion generated from: '<S2>/R_BCP_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage_read'
   */
  (void)
    Rte_Write_S_BCP_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage
    (tmpRead_2);

  /* Outport: '<Root>/S_BCP_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery' incorporates:
   *  SignalConversion generated from: '<S2>/R_BCP_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery_read'
   */
  (void)
    Rte_Write_S_BCP_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery
    (tmpRead_3);

  /* Outport: '<Root>/S_BCP_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage' incorporates:
   *  SignalConversion generated from: '<S2>/R_BCP_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage_read'
   */
  (void)Rte_Write_S_BCP_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage
    (tmpRead_4);

  /* Outport: '<Root>/S_BCP_TotalNominalEnergy_TotalNominalEnergy' incorporates:
   *  SignalConversion generated from: '<S2>/R_BCP_TotalNominalEnergy_TotalNominalEnergy_read'
   */
  (void)Rte_Write_S_BCP_TotalNominalEnergy_TotalNominalEnergy(tmpRead_5);
  }
  if(Ea_fgSendBCPPMsg == 1)
  {
  /* Outport: '<Root>/S_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur' incorporates:
   *  SignalConversion generated from: '<S2>/R_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur_read'
   */
  (void)Rte_Write_S_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur(tmpRead_6);

  /* Outport: '<Root>/S_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV' incorporates:
   *  SignalConversion generated from: '<S2>/R_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV_read'
   */
  (void)Rte_Write_S_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV(tmpRead_7);

  /* Outport: '<Root>/S_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV' incorporates:
   *  SignalConversion generated from: '<S2>/R_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV_read'
   */
  (void)Rte_Write_S_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV(tmpRead_8);

  /* Outport: '<Root>/S_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc' incorporates:
   *  SignalConversion generated from: '<S2>/R_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc_read'
   */
  (void)Rte_Write_S_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc(tmpRead_9);
  }
  if(Ea_fgSendBCSMsg == 1)
  {
  /* Outport: '<Root>/S_BCS_CurrentChargeState_CurrentChargeState' incorporates:
   *  SignalConversion generated from: '<S2>/R_BCS_CurrentChargeState_CurrentChargeState_read'
   */
  (void)Rte_Write_S_BCS_CurrentChargeState_CurrentChargeState(tmpRead_a);

  /* Outport: '<Root>/S_BCS_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime' incorporates:
   *  SignalConversion generated from: '<S2>/R_BCS_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime_read'
   */
  (void)
    Rte_Write_S_BCS_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime
    (tmpRead_b);

  /* Outport: '<Root>/S_BCS_MeasuredChargingCurrent_MeasuredChargingCurrent' incorporates:
   *  SignalConversion generated from: '<S2>/R_BCS_MeasuredChargingCurrent_MeasuredChargingCurrent_read'
   */
  (void)Rte_Write_S_BCS_MeasuredChargingCurrent_MeasuredChargingCurrent
    (tmpRead_c);

  /* Outport: '<Root>/S_BCS_MeasuredChargingVoltage_MeasuredChargingVoltage' incorporates:
   *  SignalConversion generated from: '<S2>/R_BCS_MeasuredChargingVoltage_MeasuredChargingVoltage_read'
   */
  (void)Rte_Write_S_BCS_MeasuredChargingVoltage_MeasuredChargingVoltage
    (tmpRead_d);

  /* Outport: '<Root>/S_BCS_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage' incorporates:
   *  SignalConversion generated from: '<S2>/R_BCS_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage_read'
   */
  (void)Rte_Write_S_BCS_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage
    (tmpRead_e);

  /* Outport: '<Root>/S_BCS_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup' incorporates:
   *  SignalConversion generated from: '<S2>/R_BCS_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup_read'
   */
  (void)
    Rte_Write_S_BCS_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup
    (tmpRead_f);
  }
  if(Ea_fgSendBCSPMsg == 1)
  {
  /* Outport: '<Root>/S_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time' incorporates:
   *  SignalConversion generated from: '<S2>/R_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time_read'
   */
  (void)Rte_Write_S_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time
    (tmpRead_g);

  /* Outport: '<Root>/S_BCSP_Remaining_range_BCSP_Remaining_range' incorporates:
   *  SignalConversion generated from: '<S2>/R_BCSP_Remaining_range_BCSP_Remaining_range_read'
   */
  (void)Rte_Write_S_BCSP_Remaining_range_BCSP_Remaining_range(tmpRead_h);

  /* Outport: '<Root>/S_BCSP_reserved_BCSP_reserved' incorporates:
   *  SignalConversion generated from: '<S2>/R_BCSP_reserved_BCSP_reserved_read'
   */
  (void)Rte_Write_S_BCSP_reserved_BCSP_reserved(tmpRead_i);
  }
  if(Ea_fgSendBDCMsg == 1)
  {
  /* Outport: '<Root>/S_BDC_Battery_capacity_BDC_Battery_capacity' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Battery_capacity_BDC_Battery_capacity_read'
   */
  (void)Rte_Write_S_BDC_Battery_capacity_BDC_Battery_capacity(tmpRead_j);

  /* Outport: '<Root>/S_BDC_Battery_energy_BDC_Battery_energy' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Battery_energy_BDC_Battery_energy_read'
   */
  (void)Rte_Write_S_BDC_Battery_energy_BDC_Battery_energy(tmpRead_k);

  /* Outport: '<Root>/S_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate_read'
   */
  (void)Rte_Write_S_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate(tmpRead_l);

  /* Outport: '<Root>/S_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange_read'
   */
  (void)Rte_Write_S_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange
    (tmpRead_m);

  /* Outport: '<Root>/S_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate_read'
   */
  (void)Rte_Write_S_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate
    (tmpRead_n);

  /* Outport: '<Root>/S_BDC_Soc_BDC_Soc' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Soc_BDC_Soc_read'
   */
  (void)Rte_Write_S_BDC_Soc_BDC_Soc(tmpRead_o);

  /* Outport: '<Root>/S_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1_read'
   */
  (void)Rte_Write_S_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1(tmpRead_p);

  /* Outport: '<Root>/S_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10_read'
   */
  (void)Rte_Write_S_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10(tmpRead_q);

  /* Outport: '<Root>/S_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11_read'
   */
  (void)Rte_Write_S_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11(tmpRead_r);

  /* Outport: '<Root>/S_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12_read'
   */
  (void)Rte_Write_S_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12(tmpRead_s);

  /* Outport: '<Root>/S_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13_read'
   */
  (void)Rte_Write_S_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13(tmpRead_t);

  /* Outport: '<Root>/S_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14_read'
   */
  (void)Rte_Write_S_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14(tmpRead_u);

  /* Outport: '<Root>/S_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15_read'
   */
  (void)Rte_Write_S_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15(tmpRead_v);

  /* Outport: '<Root>/S_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16_read'
   */
  (void)Rte_Write_S_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16(tmpRead_w);

  /* Outport: '<Root>/S_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17_read'
   */
  (void)Rte_Write_S_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17(tmpRead_x);

  /* Outport: '<Root>/S_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2_read'
   */
  (void)Rte_Write_S_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2(tmpRead_y);

  /* Outport: '<Root>/S_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3_read'
   */
  (void)Rte_Write_S_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3(tmpRead_z);

  /* Outport: '<Root>/S_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4_read'
   */
  (void)Rte_Write_S_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4(tmpRead_10);

  /* Outport: '<Root>/S_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5_read'
   */
  (void)Rte_Write_S_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5(tmpRead_11);

  /* Outport: '<Root>/S_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6_read'
   */
  (void)Rte_Write_S_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6(tmpRead_12);

  /* Outport: '<Root>/S_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7_read'
   */
  (void)Rte_Write_S_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7(tmpRead_13);

  /* Outport: '<Root>/S_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8_read'
   */
  (void)Rte_Write_S_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8(tmpRead_14);

  /* Outport: '<Root>/S_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9' incorporates:
   *  SignalConversion generated from: '<S2>/R_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9_read'
   */
  (void)Rte_Write_S_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9(tmpRead_15);
  }
  if(Ea_fgSendBEMMsg == 1)
  {
  /* Outport: '<Root>/S_BEM_Timeout_CCS_Timeout_CCS' incorporates:
   *  SignalConversion generated from: '<S2>/R_BEM_Timeout_CCS_Timeout_CCS_read'
   */
  (void)Rte_Write_S_BEM_Timeout_CCS_Timeout_CCS(tmpRead_16);

  /* Outport: '<Root>/S_BEM_Timeout_CRM_Recognized_Timeout_CRM_Recognized' incorporates:
   *  SignalConversion generated from: '<S2>/R_BEM_Timeout_CRM_Recognized_Timeout_CRM_Recognized_read'
   */
  (void)Rte_Write_S_BEM_Timeout_CRM_Recognized_Timeout_CRM_Recognized(tmpRead_17);

  /* Outport: '<Root>/S_BEM_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized' incorporates:
   *  SignalConversion generated from: '<S2>/R_BEM_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized_read'
   */
  (void)Rte_Write_S_BEM_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized
    (tmpRead_18);

  /* Outport: '<Root>/S_BEM_Timeout_CRO_Timeout_CRO' incorporates:
   *  SignalConversion generated from: '<S2>/R_BEM_Timeout_CRO_Timeout_CRO_read'
   */
  (void)Rte_Write_S_BEM_Timeout_CRO_Timeout_CRO(tmpRead_19);

  /* Outport: '<Root>/S_BEM_Timeout_CSD_Timeout_CSD' incorporates:
   *  SignalConversion generated from: '<S2>/R_BEM_Timeout_CSD_Timeout_CSD_read'
   */
  (void)Rte_Write_S_BEM_Timeout_CSD_Timeout_CSD(tmpRead_1a);

  /* Outport: '<Root>/S_BEM_Timeout_CST_Timeout_CST' incorporates:
   *  SignalConversion generated from: '<S2>/R_BEM_Timeout_CST_Timeout_CST_read'
   */
  (void)Rte_Write_S_BEM_Timeout_CST_Timeout_CST(tmpRead_1b);

  /* Outport: '<Root>/S_BEM_Timeout_CTS_CML_Timeout_CTS_CML' incorporates:
   *  SignalConversion generated from: '<S2>/R_BEM_Timeout_CTS_CML_Timeout_CTS_CML_read'
   */
  (void)Rte_Write_S_BEM_Timeout_CTS_CML_Timeout_CTS_CML(tmpRead_1c);
  }
  if(Ea_fgSendBHMMsg == 1)
  {
  /* Outport: '<Root>/S_BHM_MaxChargingVoltage_MaxChargingVoltage' incorporates:
   *  SignalConversion generated from: '<S2>/R_BHM_MaxChargingVoltage_MaxChargingVoltage_read'
   */
  (void)Rte_Write_S_BHM_MaxChargingVoltage_MaxChargingVoltage(tmpRead_1d);
  }
  if(Ea_fgSendFastChgStopInfo == 1)
  {
  /* Outport: '<Root>/S_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason' incorporates:
   *  SignalConversion generated from: '<S2>/R_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason_read'
   */
  (void)Rte_Write_S_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason(tmpRead_1e);

  /* Outport: '<Root>/S_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason' incorporates:
   *  SignalConversion generated from: '<S2>/R_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason_read'
   */
  (void)Rte_Write_S_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason(tmpRead_1f);

  /* Outport: '<Root>/S_BMS_BMSStopChgReason_BMS_BMSStopChgReason' incorporates:
   *  SignalConversion generated from: '<S2>/R_BMS_BMSStopChgReason_BMS_BMSStopChgReason_read'
   */
  (void)Rte_Write_S_BMS_BMSStopChgReason_BMS_BMSStopChgReason(tmpRead_1g);

  /* Outport: '<Root>/S_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason' incorporates:
   *  SignalConversion generated from: '<S2>/R_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason_read'
   */
  (void)Rte_Write_S_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason(tmpRead_1h);

  /* Outport: '<Root>/S_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason' incorporates:
   *  SignalConversion generated from: '<S2>/R_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason_read'
   */
  (void)Rte_Write_S_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason(tmpRead_1i);

  /* Outport: '<Root>/S_BMS_CCUStopChgReason_BMS_CCUStopChgReason' incorporates:
   *  SignalConversion generated from: '<S2>/R_BMS_CCUStopChgReason_BMS_CCUStopChgReason_read'
   */
  (void)Rte_Write_S_BMS_CCUStopChgReason_BMS_CCUStopChgReason(tmpRead_1j);
  }
  if(Ea_fgSendBRMMsg == 1)
  {
  /* Outport: '<Root>/S_BmsProtocolVersion_BmsProtocolVersion' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   *  SignalConversion generated from: '<S2>/R_BRM_BmsVersion_BmsVersion_read'
   */
  // (void)Rte_Write_S_BmsProtocolVersion_BmsProtocolVersion(tmpRead_1o);
  (void)Rte_Write_S_BmsProtocolVersion_BmsProtocolVersion((((uint32)tmpRead_1o << 8) | (uint32)tmpRead_1n));

  /* Outport: '<Root>/S_BRM_BatterySystemCapacity_BatterySystemCapacity' incorporates:
   *  SignalConversion generated from: '<S2>/R_BRM_BatterySystemCapacity_BatterySystemCapacity_read'
   */
  (void)Rte_Write_S_BRM_BatterySystemCapacity_BatterySystemCapacity(tmpRead_1k);

  /* Outport: '<Root>/S_BRM_BatterySystemVoltage_BatterySystemVoltage' incorporates:
   *  SignalConversion generated from: '<S2>/R_BRM_BatterySystemVoltage_BatterySystemVoltage_read'
   */
  (void)Rte_Write_S_BRM_BatterySystemVoltage_BatterySystemVoltage(tmpRead_1l);

  /* Outport: '<Root>/S_BRM_BatteryType_BatteryType' incorporates:
   *  SignalConversion generated from: '<S2>/R_BRM_BatteryType_BatteryType_read'
   */
  (void)Rte_Write_S_BRM_BatteryType_BatteryType(tmpRead_1m);

  /* Outport: '<Root>/S_BRM_BmsRevision_BmsRevision' incorporates:
   *  SignalConversion generated from: '<S2>/R_BRM_BmsRevision_BmsRevision_read'
   */
  // (void)Rte_Write_S_BRM_BmsRevision_BmsRevision(tmpRead_1n);
  
    /* Outport: '<Root>/S_BRM_BmsVersion_BmsVersion' incorporates:
   *  SignalConversion generated from: '<S2>/R_BRM_BmsVersion_BmsVersion_read'
   */
  // (void)Rte_Write_S_BRM_BmsVersion_BmsVersion(tmpRead_1o);
  }
  if(Ea_fgSendBROMsg == 1)
  {
  /* Outport: '<Root>/S_BRO_BmsReadyForCharging_BmsReadyForCharging' incorporates:
   *  SignalConversion generated from: '<S2>/R_BRO_BmsReadyForCharging_BmsReadyForCharging_read'
   */
  (void)Rte_Write_S_BRO_BmsReadyForCharging_BmsReadyForCharging(tmpRead_1p);
  }
  if(Ea_fgSendBSDMsg == 1)
  {
  /* Outport: '<Root>/S_BSD_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature' incorporates:
   *  SignalConversion generated from: '<S2>/R_BSD_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature_read'
   */
  (void)Rte_Write_S_BSD_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature
    (tmpRead_1q);

  /* Outport: '<Root>/S_BSD_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage' incorporates:
   *  SignalConversion generated from: '<S2>/R_BSD_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage_read'
   */
  (void)Rte_Write_S_BSD_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage
    (tmpRead_1r);

  /* Outport: '<Root>/S_BSD_SingleBatteryMinTemperature_SingleBatteryMinTemperature' incorporates:
   *  SignalConversion generated from: '<S2>/R_BSD_SingleBatteryMinTemperature_SingleBatteryMinTemperature_read'
   */
  (void)Rte_Write_S_BSD_SingleBatteryMinTemperature_SingleBatteryMinTemperature
    (tmpRead_1s);

  /* Outport: '<Root>/S_BSD_SingleBatteryMinVoltage_SingleBatteryMinVoltage' incorporates:
   *  SignalConversion generated from: '<S2>/R_BSD_SingleBatteryMinVoltage_SingleBatteryMinVoltage_read'
   */
  (void)Rte_Write_S_BSD_SingleBatteryMinVoltage_SingleBatteryMinVoltage
    (tmpRead_1t);

  /* Outport: '<Root>/S_BSD_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC' incorporates:
   *  SignalConversion generated from: '<S2>/R_BSD_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC_read'
   */
  (void)Rte_Write_S_BSD_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC
    (tmpRead_1u);
  }
  if(Ea_fgSendBSMMsg == 1)
  {
  /* Outport: '<Root>/S_BSM_BatteryChargingOvercurrent_BatteryChargingOvercurrent' incorporates:
   *  SignalConversion generated from: '<S2>/R_BSM_BatteryChargingOvercurrent_BatteryChargingOvercurrent_read'
   */
  (void)Rte_Write_S_BSM_BatteryChargingOvercurrent_BatteryChargingOvercurrent
    (tmpRead_1v);

  /* Outport: '<Root>/S_BSM_BatteryExcessTemperature_BatteryExcessTemperature' incorporates:
   *  SignalConversion generated from: '<S2>/R_BSM_BatteryExcessTemperature_BatteryExcessTemperature_read'
   */
  (void)Rte_Write_S_BSM_BatteryExcessTemperature_BatteryExcessTemperature
    (tmpRead_1w);

  /* Outport: '<Root>/S_BSM_BatteryHighestTemp_BatteryHighestTemp' incorporates:
   *  SignalConversion generated from: '<S2>/R_BSM_BatteryHighestTemp_BatteryHighestTemp_read'
   */
  (void)Rte_Write_S_BSM_BatteryHighestTemp_BatteryHighestTemp(tmpRead_1x);

  /* Outport: '<Root>/S_BSM_BatteryHighestTempSerNo_BatteryHighestTempSerNo' incorporates:
   *  SignalConversion generated from: '<S2>/R_BSM_BatteryHighestTempSerNo_BatteryHighestTempSerNo_read'
   */
  (void)Rte_Write_S_BSM_BatteryHighestTempSerNo_BatteryHighestTempSerNo
    (tmpRead_1y);

  /* Outport: '<Root>/S_BSM_BatteryInsulationState_BatteryInsulationState' incorporates:
   *  SignalConversion generated from: '<S2>/R_BSM_BatteryInsulationState_BatteryInsulationState_read'
   */
  (void)Rte_Write_S_BSM_BatteryInsulationState_BatteryInsulationState(tmpRead_1z);

  /* Outport: '<Root>/S_BSM_BatteryLowestTemp_BatteryLowestTemp' incorporates:
   *  SignalConversion generated from: '<S2>/R_BSM_BatteryLowestTemp_BatteryLowestTemp_read'
   */
  (void)Rte_Write_S_BSM_BatteryLowestTemp_BatteryLowestTemp(tmpRead_20);

  /* Outport: '<Root>/S_BSM_BatteryLowestTempSerNo_BatteryLowestTempSerNo' incorporates:
   *  SignalConversion generated from: '<S2>/R_BSM_BatteryLowestTempSerNo_BatteryLowestTempSerNo_read'
   */
  (void)Rte_Write_S_BSM_BatteryLowestTempSerNo_BatteryLowestTempSerNo(tmpRead_21);

  /* Outport: '<Root>/S_BSM_BatteryOutputConnectorState_BatteryOutputConnectorState' incorporates:
   *  SignalConversion generated from: '<S2>/R_BSM_BatteryOutputConnectorState_BatteryOutputConnectorState_read'
   */
  (void)Rte_Write_S_BSM_BatteryOutputConnectorState_BatteryOutputConnectorState
    (tmpRead_22);

  /* Outport: '<Root>/S_BSM_BsmChargingPermissible_BsmChargingPermissible' incorporates:
   *  SignalConversion generated from: '<S2>/R_BSM_BsmChargingPermissible_BsmChargingPermissible_read'
   */
  (void)Rte_Write_S_BSM_BsmChargingPermissible_BsmChargingPermissible(tmpRead_23);

  /* Outport: '<Root>/S_BSM_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo' incorporates:
   *  SignalConversion generated from: '<S2>/R_BSM_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo_read'
   */
  (void)
    Rte_Write_S_BSM_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo
    (tmpRead_24);

  /* Outport: '<Root>/S_BSM_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage' incorporates:
   *  SignalConversion generated from: '<S2>/R_BSM_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage_read'
   */
  (void)Rte_Write_S_BSM_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage
    (tmpRead_25);

  /* Outport: '<Root>/S_BSM_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState' incorporates:
   *  SignalConversion generated from: '<S2>/R_BSM_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState_read'
   */
  (void)
    Rte_Write_S_BSM_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState
    (tmpRead_26);
  }




  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/swc_SetSendCANMsg_100ms' */
}

/* Model step function for TID3 */
void swc_SetSendCANMsg_1000ms(void)
                                   /* Explicit Task: swc_SetSendCANMsg_1000ms */
{
  /* (no output/update code required) */
}

/* Model initialize function */
void swc_SetSendCANMsg_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
