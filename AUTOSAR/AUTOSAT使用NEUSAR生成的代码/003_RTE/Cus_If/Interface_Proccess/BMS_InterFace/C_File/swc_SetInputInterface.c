/*
 * File: swc_SetInputInterface.c
 *
 * Code generated for Simulink model 'swc_SetInputInterface'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Thu Jun 18 14:50:52 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "swc_SetInputInterface.h"
#include "swc_SetInputInterface_private.h"
#include "look1_ifId_binlcapw.h"
#include "sMultiWord2sLongSat.h"
#include "sMultiWordMul.h"
#include "sMultiWordShrNear.h"
#include "BMS_AFE_CFG.h"
#ifdef BMS_Test_Code_KYH
sint16 Tset_Cs_BMUTemp[32] = {0};
sint16 Tset_Cs_BMUTemp1[32] = {0};
#endif
/* Model step function for TID1 */
void swc_SetInput_10ms(void)           /* Explicit Task: swc_SetInput_10ms */
{
  uint32 tmpWrite;
  uint16 tmpWrite_0;

  /* RootInportFunctionCallGenerator generated from: '<Root>/swc_SetInput_10ms' incorporates:
   *  SubSystem: '<Root>/swc_SetInput_10ms_sys'
   */
  /* FunctionCaller: '<S2>/BSWIOSP_Get_Com_CST_UpdataTime_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_Com_CST_UpdataTime_CST_UpdataTime'
   */
  Rte_Call_BSWIOSP_Get_Com_CST_UpdataTime_Operation(&tmpWrite);

  /* FunctionCaller: '<S2>/BSWIOSP_Get_Service0x14_Count_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_Service0x14_Count_Service0x14_Count'
   */
  Rte_Call_BSWIOSP_Get_Service0x14_Count_Operation(&tmpWrite_0);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/swc_SetInput_10ms' */

  /* Outport: '<Root>/BSWIOSP_Com_CST_UpdataTime_CST_UpdataTime' */
  (void)Rte_Write_BSWIOSP_Com_CST_UpdataTime_CST_UpdataTime(tmpWrite);

  /* Outport: '<Root>/BSWIOSP_Service0x14_Count_Service0x14_Count' */
  (void)Rte_Write_BSWIOSP_Service0x14_Count_Service0x14_Count(tmpWrite_0);
}

/* Model step function for TID2 */
void swc_SetInput_50ms(void)           /* Explicit Task: swc_SetInput_50ms */
{
  int64m_T tmp;
  int64m_T tmp_0;
  sint32 rtb_HvSysSample_Get_RelayKHVolt;
  sint32 tmpWrite_15;
  uint32 tmpWrite[4];
  uint32 tmpWrite_a;
  uint32 tmpWrite_y;
  uint32 tmp_1;
  uint32 tmp_2;
  uint16 tmpWrite_14;
  uint16 tmpWrite_p;
  uint16 tmpWrite_q;
  uint8 tmpWrite_0;
  uint8 tmpWrite_1;
  uint8 tmpWrite_10;
  uint8 tmpWrite_11;
  uint8 tmpWrite_12;
  uint8 tmpWrite_13;
  uint8 tmpWrite_2;
  uint8 tmpWrite_3;
  uint8 tmpWrite_4;
  uint8 tmpWrite_b;
  uint8 tmpWrite_c;
  uint8 tmpWrite_g;
  uint8 tmpWrite_l;
  uint8 tmpWrite_n;
  uint8 tmpWrite_o;
  uint8 tmpWrite_r;
  uint8 tmpWrite_s;
  uint8 tmpWrite_t;
  uint8 tmpWrite_u;
  uint8 tmpWrite_v;
  uint8 tmpWrite_w;
  uint8 tmpWrite_x;
  uint8 tmpWrite_z;
  boolean tmpWrite_5;
  boolean tmpWrite_6;
  boolean tmpWrite_7;
  boolean tmpWrite_8;
  boolean tmpWrite_9;
  boolean tmpWrite_d;
  boolean tmpWrite_e;
  boolean tmpWrite_f;
  boolean tmpWrite_h;
  boolean tmpWrite_i;
  boolean tmpWrite_j;
  boolean tmpWrite_k;
  boolean tmpWrite_m;

  /* RootInportFunctionCallGenerator generated from: '<Root>/swc_SetInput_50ms' incorporates:
   *  SubSystem: '<Root>/swc_SetInput_50ms_sys'
   */
  /* FunctionCaller: '<S3>/BmuSample_Get_BMUCellVSt_Operation' incorporates:
   *  Outport: '<Root>/BmuSample_BMUCellVSt_BMUCellVSt'
   */
  Rte_Call_BmuSample_Get_BMUCellVSt_Operation(tmpWrite);

  /* FunctionCaller: '<S3>/BmuSample_Get_CellTEffective_Operation' incorporates:
   *  Outport: '<Root>/BmuSample_CellTEffective_CellTEffective'
   */
  Rte_Call_BmuSample_Get_CellTEffective_Operation(&tmpWrite_0);

  /* FunctionCaller: '<S3>/BmuSample_Get_CellTempException_Operation' incorporates:
   *  Outport: '<Root>/BmuSample_CellTempException_CellTempException'
   */
  Rte_Call_BmuSample_Get_CellTempException_Operation(&tmpWrite_1);

  /* FunctionCaller: '<S3>/BmuSample_Get_CellVEffective_Operation' incorporates:
   *  Outport: '<Root>/BmuSample_CellVEffective_CellVEffective'
   */
  Rte_Call_BmuSample_Get_CellVEffective_Operation(&tmpWrite_2);

  /* FunctionCaller: '<S3>/BmuSample_Get_CellVoltException_Operation' incorporates:
   *  Outport: '<Root>/BmuSample_CellVoltException_CellVoltException'
   */
  Rte_Call_BmuSample_Get_CellVoltException_Operation(&tmpWrite_3);

  /* FunctionCaller: '<S3>/BSWIOSP_Get_ACTemp_ErrFLg_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_ACTemp_ErrFLg_ACTemp_ErrFLg'
   */
  Rte_Call_BSWIOSP_Get_ACTemp_ErrFLg_Operation(&tmpWrite_4);

  /* FunctionCaller: '<S3>/BSWIOSP_Get_BalnCtlModl_ErrFLg_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_BalnCtlModl_ErrFLg_BalnCtlModl_ErrFLg'
   */
  Rte_Call_BSWIOSP_Get_BalnCtlModl_ErrFLg_Operation(&tmpWrite_5);

  /* FunctionCaller: '<S3>/BSWIOSP_Get_BattIsoDet_ErrFLg_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_BattIsoDet_ErrFLg_BattIsoDet_ErrFLg'
   */
  Rte_Call_BSWIOSP_Get_BattIsoDet_ErrFLg_Operation(&tmpWrite_6);

  /* FunctionCaller: '<S3>/BSWIOSP_Get_bCANWakeUp_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_bCANWakeUp_bCANWakeUp'
   */
  Rte_Call_BSWIOSP_Get_bCANWakeUp_Operation(&tmpWrite_7);

  /* FunctionCaller: '<S3>/BSWIOSP_Get_BMUTempOver_ErrFLg_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_BMUTempOver_ErrFLg_BMUTempOver_ErrFLg'
   */
  Rte_Call_BSWIOSP_Get_BMUTempOver_ErrFLg_Operation(&tmpWrite_8);

  /* FunctionCaller: '<S3>/BSWIOSP_Get_CellVoltSampleDiscon_ErrFLg_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_CellVoltSampleDiscon_ErrFLg_CellVoltSampleDiscon_ErrFLg'
   */
  Rte_Call_BSWIOSP_Get_CellVoltSampleDiscon_ErrFLg_Operation(&tmpWrite_9);

  /* FunctionCaller: '<S3>/BSWIOSP_Get_Com_CCS_UpdataTime_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_Com_CCS_UpdataTime_CCS_UpdataTime'
   */
  Rte_Call_BSWIOSP_Get_Com_CCS_UpdataTime_Operation(&tmpWrite_a);

  /* FunctionCaller: '<S3>/BSWIOSP_Get_Com_OBC_Sts_Timeout_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_Com_OBC_Sts_Timeout_OBC_Sts_Timeout'
   */
  Rte_Call_BSWIOSP_Get_Com_OBC_Sts_Timeout_Operation(&tmpWrite_b);

  /* FunctionCaller: '<S3>/BSWIOSP_Get_DCTemp_ErrFLg_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_DCTemp_ErrFLg_DCTemp_ErrFLg'
   */
  Rte_Call_BSWIOSP_Get_DCTemp_ErrFLg_Operation(&tmpWrite_c);

  /* FunctionCaller: '<S3>/BSWIOSP_Get_EVCANBusOff_ErrFLg_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_EVCANBusOff_ErrFLg_EVCANBusOff_ErrFLg'
   */
  Rte_Call_BSWIOSP_Get_EVCANBusOff_ErrFLg_Operation(&tmpWrite_d);

  /* FunctionCaller: '<S3>/BSWIOSP_Get_HCMCom_ErrFLg_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_HCMCom_ErrFLg_HCMCom_ErrFLg'
   */
  Rte_Call_BSWIOSP_Get_HCMCom_ErrFLg_Operation(&tmpWrite_e);

  /* FunctionCaller: '<S3>/BSWIOSP_Get_IntCANE2E_ErrFLg_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_IntCANE2E_ErrFLg_IntCANE2E_ErrFLg'
   */
  Rte_Call_BSWIOSP_Get_IntCANE2E_ErrFLg_Operation(&tmpWrite_f);

  /* FunctionCaller: '<S3>/BSWIOSP_Get_NvM_Save_Ok_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_NvM_Save_Ok_NvM_Save_Ok'
   */
  Rte_Call_BSWIOSP_Get_NvM_Save_Ok_Operation(&tmpWrite_g);

  /* FunctionCaller: '<S3>/BSWIOSP_Get_RlyKCVoltSample_ErrFLg_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_RlyKCVoltSample_ErrFLg_RlyKCVoltSample_ErrFLg'
   */
  Rte_Call_BSWIOSP_Get_RlyKCVoltSample_ErrFLg_Operation(&tmpWrite_h);

  /* FunctionCaller: '<S3>/BSWIOSP_Get_RlyKMVoltSample_ErrFLg_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_RlyKMVoltSample_ErrFLg_RlyKMVoltSample_ErrFLg'
   */
  Rte_Call_BSWIOSP_Get_RlyKMVoltSample_ErrFLg_Operation(&tmpWrite_i);

  /* FunctionCaller: '<S3>/BSWIOSP_Get_RlyKNVoltSample_ErrFLg_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_RlyKNVoltSample_ErrFLg_RlyKNVoltSample_ErrFLg'
   */
  Rte_Call_BSWIOSP_Get_RlyKNVoltSample_ErrFLg_Operation(&tmpWrite_j);

  /* FunctionCaller: '<S3>/BSWIOSP_Get_STHW_ErrFLg_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_STHW_ErrFLg_STHW_ErrFLg'
   */
  Rte_Call_BSWIOSP_Get_STHW_ErrFLg_Operation(&tmpWrite_k);

  /* FunctionCaller: '<S3>/BSWIOSP_Get_StsElectroniclockContor_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_StsElectroniclockContor_StsElectroniclockContor'
   */
  Rte_Call_BSWIOSP_Get_StsElectroniclockContor_Operation(&tmpWrite_l);

  /* FunctionCaller: '<S3>/BSWIOSP_Get_VCUCom_ErrFLg_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_VCUCom_ErrFLg_VCUCom_ErrFLg'
   */
  Rte_Call_BSWIOSP_Get_VCUCom_ErrFLg_Operation(&tmpWrite_m);

  /* FunctionCaller: '<S3>/BSWIOSP_Get_WeakUpFlg_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_WeakUpFlg_WeakUpFlg'
   */
  Rte_Call_BSWIOSP_Get_WeakUpFlg_Operation(&tmpWrite_n);

  /* FunctionCaller: '<S3>/HvSysSample_Get_RelayKHVoltage_Operation' */
  Rte_Call_HvSysSample_Get_RelayKHVoltage_Operation
    (&rtb_HvSysSample_Get_RelayKHVolt);

  /* Gain: '<S3>/Gain3' */
  tmp_1 = 1342177280U;
  tmp_2 = (uint32)rtb_HvSysSample_Get_RelayKHVolt;
  sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_0.chunks[0U], 2);

  /* DataTypeConversion: '<S3>/Data Type Conversion10' */
  sMultiWordShrNear(&tmp_0.chunks[0U], 2, 27U, &tmp.chunks[0U], 2);

  /* Outport: '<Root>/HvSysSample_RelayKHVoltage_RelayKHVoltage' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion10'
   */
  (void)Rte_Write_HvSysSample_RelayKHVoltage_RelayKHVoltage(sMultiWord2sLongSat(
    &tmp.chunks[0U], 2));

  /* FunctionCaller: '<S3>/HvSysSample_Get_RelayKNClsSts_U8_Operation' incorporates:
   *  Outport: '<Root>/HvSysSample_RelayKNClsSts_U8_RelayKNClsSts_U8'
   */
  Rte_Call_HvSysSample_Get_RelayKNClsSts_U8_Operation(&tmpWrite_o);

  /* FunctionCaller: '<S3>/HvSysSample_Get_SampleCountCurrent_U16_Operation' incorporates:
   *  Outport: '<Root>/HvSysSample_SampleCountCurrent_U16_SampleCountCurrent_U16'
   */
  Rte_Call_HvSysSample_Get_SampleCountCurrent_U16_Operation(&tmpWrite_p);

  /* FunctionCaller: '<S3>/HvSysSample_Get_SampleCountTotalVol_U16_Operation' incorporates:
   *  Outport: '<Root>/HvSysSample_SampleCountTotalVol_U16_SampleCountTotalVol_U16'
   */
  Rte_Call_HvSysSample_Get_SampleCountTotalVol_U16_Operation(&tmpWrite_q);

  /* FunctionCaller: '<S3>/HvSysSample_Get_SampleValidBat_U8_Operation' incorporates:
   *  Outport: '<Root>/HvSysSample_SampleValidBat_U8_SampleValidBat_U8'
   */
  Rte_Call_HvSysSample_Get_SampleValidBat_U8_Operation(&tmpWrite_r);

  /* FunctionCaller: '<S3>/HvSysSample_Get_SampleValidCurrent_U8_Operation' incorporates:
   *  Outport: '<Root>/HvSysSample_SampleValidCurrent_U8_SampleValidCurrent_U8'
   */
  Rte_Call_HvSysSample_Get_SampleValidCurrent_U8_Operation(&tmpWrite_s);

  /* FunctionCaller: '<S3>/HvSysSample_Get_SampleValidIsolation_U8_Operation' incorporates:
   *  Outport: '<Root>/HvSysSample_SampleValidIsolation_U8_SampleValidIsolation_U8'
   */
  Rte_Call_HvSysSample_Get_SampleValidIsolation_U8_Operation(&tmpWrite_t);

  /* FunctionCaller: '<S3>/HvSysSample_Get_SampleValidKC_U8_Operation' incorporates:
   *  Outport: '<Root>/HvSysSample_SampleValidKC_U8_SampleValidKC_U8'
   */
  Rte_Call_HvSysSample_Get_SampleValidKC_U8_Operation(&tmpWrite_u);

  /* FunctionCaller: '<S3>/HvSysSample_Get_SampleValidKH_U8_Operation' incorporates:
   *  Outport: '<Root>/HvSysSample_SampleValidKH_U8_SampleValidKH_U8'
   */
  Rte_Call_HvSysSample_Get_SampleValidKH_U8_Operation(&tmpWrite_v);

  /* FunctionCaller: '<S3>/HvSysSample_Get_SampleValidKM_U8_Operation' incorporates:
   *  Outport: '<Root>/HvSysSample_SampleValidKM_U8_SampleValidKM_U8'
   */
  Rte_Call_HvSysSample_Get_SampleValidKM_U8_Operation(&tmpWrite_w);

  /* FunctionCaller: '<S3>/HvSysSample_Get_SampleValidKN_U8_Operation' incorporates:
   *  Outport: '<Root>/HvSysSample_SampleValidKN_U8_SampleValidKN_U8'
   */
  Rte_Call_HvSysSample_Get_SampleValidKN_U8_Operation(&tmpWrite_x);

  /* FunctionCaller: '<S3>/RTC_Get_NowSystemTick_Operation' incorporates:
   *  Outport: '<Root>/RTC_NowSystemTick_NowSystemTick'
   */
  Rte_Call_RTC_Get_NowSystemTick_Operation(&tmpWrite_y);

  /* FunctionCaller: '<S3>/RTC_Get_ReadDay_Operation' incorporates:
   *  Outport: '<Root>/RTC_ReadDay_ReadDay'
   */
  Rte_Call_RTC_Get_ReadDay_Operation(&tmpWrite_z);

  /* FunctionCaller: '<S3>/RTC_Get_ReadHour_Operation' incorporates:
   *  Outport: '<Root>/RTC_ReadHour_ReadHour'
   */
  Rte_Call_RTC_Get_ReadHour_Operation(&tmpWrite_10);

  /* FunctionCaller: '<S3>/RTC_Get_ReadMinute_Operation' incorporates:
   *  Outport: '<Root>/RTC_ReadMinute_ReadMinute'
   */
  Rte_Call_RTC_Get_ReadMinute_Operation(&tmpWrite_11);

  /* FunctionCaller: '<S3>/RTC_Get_ReadMonth_Operation' incorporates:
   *  Outport: '<Root>/RTC_ReadMonth_ReadMonth'
   */
  Rte_Call_RTC_Get_ReadMonth_Operation(&tmpWrite_12);

  /* FunctionCaller: '<S3>/RTC_Get_ReadSecond_Operation' incorporates:
   *  Outport: '<Root>/RTC_ReadSecond_ReadSecond'
   */
  Rte_Call_RTC_Get_ReadSecond_Operation(&tmpWrite_13);

  /* FunctionCaller: '<S3>/RTC_Get_ReadYear_Operation' incorporates:
   *  Outport: '<Root>/RTC_ReadYear_ReadYear'
   */
  Rte_Call_RTC_Get_ReadYear_Operation(&tmpWrite_14);

  /* FunctionCaller: '<S3>/RTC_Get_RTCStateFault_Operation' incorporates:
   *  Outport: '<Root>/RTC_RTCStateFault_RTCStateFault'
   */
  Rte_Call_RTC_Get_RTCStateFault_Operation(&tmpWrite_15);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/swc_SetInput_50ms' */

  /* Outport: '<Root>/BmuSample_BMUCellVSt_BMUCellVSt' */
  (void)Rte_Write_BmuSample_BMUCellVSt_BMUCellVSt(tmpWrite);

  /* Outport: '<Root>/BmuSample_CellTEffective_CellTEffective' */
  (void)Rte_Write_BmuSample_CellTEffective_CellTEffective(tmpWrite_0);

  /* Outport: '<Root>/BmuSample_CellTempException_CellTempException' */
  (void)Rte_Write_BmuSample_CellTempException_CellTempException(tmpWrite_1);

  /* Outport: '<Root>/BmuSample_CellVEffective_CellVEffective' */
  (void)Rte_Write_BmuSample_CellVEffective_CellVEffective(tmpWrite_2);

  /* Outport: '<Root>/BmuSample_CellVoltException_CellVoltException' */
  (void)Rte_Write_BmuSample_CellVoltException_CellVoltException(tmpWrite_3);

  /* Outport: '<Root>/BSWIOSP_ACTemp_ErrFLg_ACTemp_ErrFLg' */
  (void)Rte_Write_BSWIOSP_ACTemp_ErrFLg_ACTemp_ErrFLg(tmpWrite_4);

  /* Outport: '<Root>/BSWIOSP_BalnCtlModl_ErrFLg_BalnCtlModl_ErrFLg' */
  (void)Rte_Write_BSWIOSP_BalnCtlModl_ErrFLg_BalnCtlModl_ErrFLg(tmpWrite_5);

  /* Outport: '<Root>/BSWIOSP_BattIsoDet_ErrFLg_BattIsoDet_ErrFLg' */
  (void)Rte_Write_BSWIOSP_BattIsoDet_ErrFLg_BattIsoDet_ErrFLg(tmpWrite_6);

  /* Outport: '<Root>/BSWIOSP_bCANWakeUp_bCANWakeUp' */
  (void)Rte_Write_BSWIOSP_bCANWakeUp_bCANWakeUp(tmpWrite_7);

  /* Outport: '<Root>/BSWIOSP_BMUTempOver_ErrFLg_BMUTempOver_ErrFLg' */
  (void)Rte_Write_BSWIOSP_BMUTempOver_ErrFLg_BMUTempOver_ErrFLg(tmpWrite_8);

  /* Outport: '<Root>/BSWIOSP_CellVoltSampleDiscon_ErrFLg_CellVoltSampleDiscon_ErrFLg' */
  (void)
    Rte_Write_BSWIOSP_CellVoltSampleDiscon_ErrFLg_CellVoltSampleDiscon_ErrFLg
    (tmpWrite_9);

  /* Outport: '<Root>/BSWIOSP_Com_CCS_UpdataTime_CCS_UpdataTime' */
  (void)Rte_Write_BSWIOSP_Com_CCS_UpdataTime_CCS_UpdataTime(tmpWrite_a);

  /* Outport: '<Root>/BSWIOSP_Com_OBC_Sts_Timeout_OBC_Sts_Timeout' */
  (void)Rte_Write_BSWIOSP_Com_OBC_Sts_Timeout_OBC_Sts_Timeout(tmpWrite_b);

  /* Outport: '<Root>/BSWIOSP_DCTemp_ErrFLg_DCTemp_ErrFLg' */
  (void)Rte_Write_BSWIOSP_DCTemp_ErrFLg_DCTemp_ErrFLg(tmpWrite_c);

  /* Outport: '<Root>/BSWIOSP_EVCANBusOff_ErrFLg_EVCANBusOff_ErrFLg' */
  (void)Rte_Write_BSWIOSP_EVCANBusOff_ErrFLg_EVCANBusOff_ErrFLg(tmpWrite_d);

  /* Outport: '<Root>/BSWIOSP_HCMCom_ErrFLg_HCMCom_ErrFLg' */
  (void)Rte_Write_BSWIOSP_HCMCom_ErrFLg_HCMCom_ErrFLg(tmpWrite_e);

  /* Outport: '<Root>/BSWIOSP_IntCANE2E_ErrFLg_IntCANE2E_ErrFLg' */
  (void)Rte_Write_BSWIOSP_IntCANE2E_ErrFLg_IntCANE2E_ErrFLg(tmpWrite_f);

  /* Outport: '<Root>/BSWIOSP_NvM_Save_Ok_NvM_Save_Ok' */
  (void)Rte_Write_BSWIOSP_NvM_Save_Ok_NvM_Save_Ok(tmpWrite_g);

  /* Outport: '<Root>/BSWIOSP_RlyKCVoltSample_ErrFLg_RlyKCVoltSample_ErrFLg' */
  (void)Rte_Write_BSWIOSP_RlyKCVoltSample_ErrFLg_RlyKCVoltSample_ErrFLg
    (tmpWrite_h);

  /* Outport: '<Root>/BSWIOSP_RlyKMVoltSample_ErrFLg_RlyKMVoltSample_ErrFLg' */
  (void)Rte_Write_BSWIOSP_RlyKMVoltSample_ErrFLg_RlyKMVoltSample_ErrFLg
    (tmpWrite_i);

  /* Outport: '<Root>/BSWIOSP_RlyKNVoltSample_ErrFLg_RlyKNVoltSample_ErrFLg' */
  (void)Rte_Write_BSWIOSP_RlyKNVoltSample_ErrFLg_RlyKNVoltSample_ErrFLg
    (tmpWrite_j);

  /* Outport: '<Root>/BSWIOSP_STHW_ErrFLg_STHW_ErrFLg' */
  (void)Rte_Write_BSWIOSP_STHW_ErrFLg_STHW_ErrFLg(tmpWrite_k);

  /* Outport: '<Root>/BSWIOSP_StsElectroniclockContor_StsElectroniclockContor' */
  (void)Rte_Write_BSWIOSP_StsElectroniclockContor_StsElectroniclockContor
    (tmpWrite_l);

  /* Outport: '<Root>/BSWIOSP_VCUCom_ErrFLg_VCUCom_ErrFLg' */
  (void)Rte_Write_BSWIOSP_VCUCom_ErrFLg_VCUCom_ErrFLg(tmpWrite_m);

  /* Outport: '<Root>/BSWIOSP_WeakUpFlg_WeakUpFlg' */
  (void)Rte_Write_BSWIOSP_WeakUpFlg_WeakUpFlg(tmpWrite_n);

  /* Outport: '<Root>/HvSysSample_RelayKNClsSts_U8_RelayKNClsSts_U8' */
  (void)Rte_Write_HvSysSample_RelayKNClsSts_U8_RelayKNClsSts_U8(tmpWrite_o);

  /* Outport: '<Root>/HvSysSample_SampleCountCurrent_U16_SampleCountCurrent_U16' */
  (void)Rte_Write_HvSysSample_SampleCountCurrent_U16_SampleCountCurrent_U16
    (tmpWrite_p);

  /* Outport: '<Root>/HvSysSample_SampleCountTotalVol_U16_SampleCountTotalVol_U16' */
  (void)Rte_Write_HvSysSample_SampleCountTotalVol_U16_SampleCountTotalVol_U16
    (tmpWrite_q);

  /* Outport: '<Root>/HvSysSample_SampleValidBat_U8_SampleValidBat_U8' */
  (void)Rte_Write_HvSysSample_SampleValidBat_U8_SampleValidBat_U8(tmpWrite_r);

  /* Outport: '<Root>/HvSysSample_SampleValidCurrent_U8_SampleValidCurrent_U8' */
  (void)Rte_Write_HvSysSample_SampleValidCurrent_U8_SampleValidCurrent_U8
    (tmpWrite_s);

  /* Outport: '<Root>/HvSysSample_SampleValidIsolation_U8_SampleValidIsolation_U8' */
  (void)Rte_Write_HvSysSample_SampleValidIsolation_U8_SampleValidIsolation_U8
    (tmpWrite_t);

  /* Outport: '<Root>/HvSysSample_SampleValidKC_U8_SampleValidKC_U8' */
  (void)Rte_Write_HvSysSample_SampleValidKC_U8_SampleValidKC_U8(tmpWrite_u);

  /* Outport: '<Root>/HvSysSample_SampleValidKH_U8_SampleValidKH_U8' */
  (void)Rte_Write_HvSysSample_SampleValidKH_U8_SampleValidKH_U8(tmpWrite_v);

  /* Outport: '<Root>/HvSysSample_SampleValidKM_U8_SampleValidKM_U8' */
  (void)Rte_Write_HvSysSample_SampleValidKM_U8_SampleValidKM_U8(tmpWrite_w);

  /* Outport: '<Root>/HvSysSample_SampleValidKN_U8_SampleValidKN_U8' */
  (void)Rte_Write_HvSysSample_SampleValidKN_U8_SampleValidKN_U8(tmpWrite_x);

  /* Outport: '<Root>/RTC_NowSystemTick_NowSystemTick' */
  (void)Rte_Write_RTC_NowSystemTick_NowSystemTick(tmpWrite_y);

  /* Outport: '<Root>/RTC_ReadDay_ReadDay' */
  (void)Rte_Write_RTC_ReadDay_ReadDay(tmpWrite_z);

  /* Outport: '<Root>/RTC_ReadHour_ReadHour' */
  (void)Rte_Write_RTC_ReadHour_ReadHour(tmpWrite_10);

  /* Outport: '<Root>/RTC_ReadMinute_ReadMinute' */
  (void)Rte_Write_RTC_ReadMinute_ReadMinute(tmpWrite_11);

  /* Outport: '<Root>/RTC_ReadMonth_ReadMonth' */
  (void)Rte_Write_RTC_ReadMonth_ReadMonth(tmpWrite_12);

  /* Outport: '<Root>/RTC_ReadSecond_ReadSecond' */
  (void)Rte_Write_RTC_ReadSecond_ReadSecond(tmpWrite_13);

  /* Outport: '<Root>/RTC_ReadYear_ReadYear' */
  (void)Rte_Write_RTC_ReadYear_ReadYear(tmpWrite_14);

  /* Outport: '<Root>/RTC_RTCStateFault_RTCStateFault' */
  (void)Rte_Write_RTC_RTCStateFault_RTCStateFault(tmpWrite_15);
}

/* Model step function for TID3 */
void swc_SetInput_100ms(void)          /* Explicit Task: swc_SetInput_100ms */
{
  float64 rtb_Gain2_1;
  float64 v;
  sint32 i;
  float32 rtb_k[32];
  uint32 tmpWrite_1;
  uint32 tmpWrite_2;
  uint32 tmpWrite_3;
  uint32 tmpWrite_4;
  uint32 tmpWrite_5;
  uint32 tmpWrite_6;
  uint32 tmpWrite_7;
  uint32 tmpWrite_8;
  uint32 tmpWrite_9;
  uint32 tmpWrite_a;
  sint16 rtb_u0[32];
  sint16 rtb_Gain2_0[8];
  uint16 tmpWrite[130];
  uint8 tmpWrite_0[32];

  /* RootInportFunctionCallGenerator generated from: '<Root>/swc_SetInput_100ms' incorporates:
   *  SubSystem: '<Root>/swc_SetInput_100ms_sys'
   */
  /* FunctionCaller: '<S1>/BmuSample_Get_BalanceTemp_Operation' incorporates:
   *  FunctionCaller: '<S1>/BmuSample_Get_BMUTemp_Operation'
   */
  Rte_Call_BmuSample_Get_BalanceTemp_Operation(&rtb_u0[0]);
  for (i = 0; i < 8; i++) {
    /* Gain: '<S1>/Gain' incorporates:
     *  Gain: '<S1>/Gain3'
     *  Gain: '<S1>/Gain5'
     *  Lookup_n-D: '<S1>/1-D Lookup Table'
     */
    rtb_Gain2_1 = look1_ifId_binlcapw(2.0F * (float32)rtb_u0[i] * 0.01F,
      rtCP_uDLookupTable_bp01Data, rtCP_uDLookupTable_tableData, 205U) * 10.0;

    /* DataTypeConversion: '<S1>/Data Type Conversion' */
    v = fabs(rtb_Gain2_1);
    if (v < 4.503599627370496E+15) {
      if (v >= 0.5) {
        rtb_Gain2_1 = floor(rtb_Gain2_1 + 0.5);
      } else {
        rtb_Gain2_1 = 0.0;
      }
    }

    if (rtb_Gain2_1 < 32768.0) {
      if (rtb_Gain2_1 >= -32768.0) {
        rtb_Gain2_0[i] = (sint16)rtb_Gain2_1;
      } else {
        rtb_Gain2_0[i] = ((int16_T)(-32768));
      }
    } else {
      rtb_Gain2_0[i] = ((uint16_T)(65535U));
    }
  }

  /* Outport: '<Root>/BmuSample_BalanceTemp_BalanceTemp' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  for(uint8 i = AFE_NUM ;i<8 ;i++)
  {
    rtb_Gain2_0[i] = 0;
  }
  (void)Rte_Write_BmuSample_BalanceTemp_BalanceTemp(rtb_Gain2_0);

  /* FunctionCaller: '<S1>/BmuSample_Get_BMUCell_Operation' incorporates:
   *  Outport: '<Root>/BmuSample_BMUCell_BMUCell'
   */
  Rte_Call_BmuSample_Get_BMUCell_Operation(tmpWrite);

  /* FunctionCaller: '<S1>/BmuSample_Get_BMUChipTemp_Operation' incorporates:
   *  FunctionCaller: '<S1>/BmuSample_Get_BMUTemp_Operation'
   */
  Rte_Call_BmuSample_Get_BMUChipTemp_Operation(&rtb_u0[0]);
  for (i = 0; i < 8; i++) {
    sint32 rtb_Gain1;

    /* Gain: '<S1>/Gain1' */
    rtb_Gain1 = 20480 * rtb_u0[i];

    /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
     *  Gain: '<S1>/Gain1'
     */
    rtb_Gain1 = ((rtb_Gain1 & 1024U) != 0U) + (rtb_Gain1 >> 11);
    if (rtb_Gain1 > 32767) {
      rtb_Gain1 = 32767;
    } else if (rtb_Gain1 < -32768) {
      rtb_Gain1 = -32768;
    }

    rtb_Gain2_0[i] = (sint16)rtb_Gain1;
  }

  /* Outport: '<Root>/BmuSample_BMUChipTemp_BMUChipTemp' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   */
  (void)Rte_Write_BmuSample_BMUChipTemp_BMUChipTemp(rtb_Gain2_0);

  /* FunctionCaller: '<S1>/BmuSample_Get_BMUTemp_Operation' */
  Rte_Call_BmuSample_Get_BMUTemp_Operation(rtb_u0);
  for (i = 0; i < 32; i++) {
    /* Gain: '<S1>/Gain4' incorporates:
     *  FunctionCaller: '<S1>/BmuSample_Get_BMUTemp_Operation'
     *  Gain: '<S1>/Gain6'
     */
    rtb_k[i] = 2.0F * (float32)rtb_u0[i] * 0.01F;
    #ifdef BMS_Test_Code_KYH
    Tset_Cs_BMUTemp1[i] = rtb_k[i];
    #endif
  }

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/swc_SetInput_100ms' */

  /* Outport: '<Root>/BmuSample_BMUCell_BMUCell' */
  (void)Rte_Write_BmuSample_BMUCell_BMUCell(tmpWrite);

  /* RootInportFunctionCallGenerator generated from: '<Root>/swc_SetInput_100ms' incorporates:
   *  SubSystem: '<Root>/swc_SetInput_100ms_sys'
   */
  for (i = 0; i < 32; i++) {
    /* Gain: '<S1>/Gain2' incorporates:
     *  Gain: '<S1>/Gain4'
     *  Lookup_n-D: '<S1>/1-D Lookup Table1'
     */
    rtb_Gain2_1 = 10.0 * look1_ifId_binlcapw(rtb_k[i],
      rtCP_uDLookupTable1_bp01Data, rtCP_uDLookupTable1_tableData, 165U);

    /* DataTypeConversion: '<S1>/Data Type Conversion3' incorporates:
     *  Gain: '<S1>/Gain2'
     */
    v = fabs(rtb_Gain2_1);
    if (v < 4.503599627370496E+15) {
      if (v >= 0.5) {
        rtb_Gain2_1 = floor(rtb_Gain2_1 + 0.5);
      } else {
        rtb_Gain2_1 = 0.0;
      }
    }

    if (rtb_Gain2_1 < 32768.0) {
      if (rtb_Gain2_1 >= -32768.0) {
        rtb_u0[i] = (sint16)rtb_Gain2_1;
      } else {
        rtb_u0[i] = ((int16_T)(-32768));
      }
    } else {
      rtb_u0[i] = ((int16_T)(32767));
    }
  }

  /* Outport: '<Root>/BmuSample_BMUTemp_BMUTemp' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion3'
   */
  #ifdef BMS_Test_Code_KYH
  for(uint8 ii = 0; ii <32; ii++)
  {
	  Tset_Cs_BMUTemp[ii] = rtb_u0[ii];
  }
  #endif
  for(uint8 i = AFE_NUM * RUN_AFE_TEMP_NUM ;i < 32 ;i++)
  {
    rtb_u0[i] = 0;
  }
  (void)Rte_Write_BmuSample_BMUTemp_BMUTemp(rtb_u0);

  /* FunctionCaller: '<S1>/BmuSample_Get_BMUTempSt_Operation' incorporates:
   *  Outport: '<Root>/BmuSample_BMUTempSt_BMUTempSt'
   */
  Rte_Call_BmuSample_Get_BMUTempSt_Operation(tmpWrite_0);

  /* FunctionCaller: '<S1>/BSWIOSP_Get_Com_CCD_UpdataTime_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_Com_CCD_UpdataTime_CCD_UpdataTime'
   */
  Rte_Call_BSWIOSP_Get_Com_CCD_UpdataTime_Operation(&tmpWrite_1);

  /* FunctionCaller: '<S1>/BSWIOSP_Get_Com_CDC_UpdataTime_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_Com_CDC_UpdataTime_CDC_UpdataTime'
   */
  Rte_Call_BSWIOSP_Get_Com_CDC_UpdataTime_Operation(&tmpWrite_2);

  /* FunctionCaller: '<S1>/BSWIOSP_Get_Com_CEM_UpdataTime_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_Com_CEM_UpdataTime_CEM_UpdataTime'
   */
  Rte_Call_BSWIOSP_Get_Com_CEM_UpdataTime_Operation(&tmpWrite_3);

  /* FunctionCaller: '<S1>/BSWIOSP_Get_Com_CHM_UpdataTime_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_Com_CHM_UpdataTime_CHM_UpdataTime'
   */
  Rte_Call_BSWIOSP_Get_Com_CHM_UpdataTime_Operation(&tmpWrite_4);

  /* FunctionCaller: '<S1>/BSWIOSP_Get_Com_CML_UpdataTime_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_Com_CML_UpdataTime_CML_UpdataTime'
   */
  Rte_Call_BSWIOSP_Get_Com_CML_UpdataTime_Operation(&tmpWrite_5);

  /* FunctionCaller: '<S1>/BSWIOSP_Get_Com_CMLP_UpdataTime_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_Com_CMLP_UpdataTime_CMLP_UpdataTime'
   */
  Rte_Call_BSWIOSP_Get_Com_CMLP_UpdataTime_Operation(&tmpWrite_6);

  /* FunctionCaller: '<S1>/BSWIOSP_Get_Com_CRM_UpdataTime_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_Com_CRM_UpdataTime_CRM_UpdataTime'
   */
  Rte_Call_BSWIOSP_Get_Com_CRM_UpdataTime_Operation(&tmpWrite_7);

  /* FunctionCaller: '<S1>/BSWIOSP_Get_Com_CRO_UpdataTime_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_Com_CRO_UpdataTime_CRO_UpdataTime'
   */
  Rte_Call_BSWIOSP_Get_Com_CRO_UpdataTime_Operation(&tmpWrite_8);

  /* FunctionCaller: '<S1>/BSWIOSP_Get_Com_CSD_UpdataTime_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_Com_CSD_UpdataTime_CSD_UpdataTime'
   */
  Rte_Call_BSWIOSP_Get_Com_CSD_UpdataTime_Operation(&tmpWrite_9);

  /* FunctionCaller: '<S1>/BSWIOSP_Get_Com_CSDP_UpdataTime_Operation' incorporates:
   *  Outport: '<Root>/BSWIOSP_Com_CSDP_UpdataTime_CSDP_UpdataTime'
   */
  Rte_Call_BSWIOSP_Get_Com_CSDP_UpdataTime_Operation(&tmpWrite_a);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/swc_SetInput_100ms' */

  /* Outport: '<Root>/BmuSample_BMUTempSt_BMUTempSt' */
  (void)Rte_Write_BmuSample_BMUTempSt_BMUTempSt(tmpWrite_0);

  /* Outport: '<Root>/BSWIOSP_Com_CCD_UpdataTime_CCD_UpdataTime' */
  (void)Rte_Write_BSWIOSP_Com_CCD_UpdataTime_CCD_UpdataTime(tmpWrite_1);

  /* Outport: '<Root>/BSWIOSP_Com_CDC_UpdataTime_CDC_UpdataTime' */
  (void)Rte_Write_BSWIOSP_Com_CDC_UpdataTime_CDC_UpdataTime(tmpWrite_2);

  /* Outport: '<Root>/BSWIOSP_Com_CEM_UpdataTime_CEM_UpdataTime' */
  (void)Rte_Write_BSWIOSP_Com_CEM_UpdataTime_CEM_UpdataTime(tmpWrite_3);

  /* Outport: '<Root>/BSWIOSP_Com_CHM_UpdataTime_CHM_UpdataTime' */
  (void)Rte_Write_BSWIOSP_Com_CHM_UpdataTime_CHM_UpdataTime(tmpWrite_4);

  /* Outport: '<Root>/BSWIOSP_Com_CML_UpdataTime_CML_UpdataTime' */
  (void)Rte_Write_BSWIOSP_Com_CML_UpdataTime_CML_UpdataTime(tmpWrite_5);

  /* Outport: '<Root>/BSWIOSP_Com_CMLP_UpdataTime_CMLP_UpdataTime' */
  (void)Rte_Write_BSWIOSP_Com_CMLP_UpdataTime_CMLP_UpdataTime(tmpWrite_6);

  /* Outport: '<Root>/BSWIOSP_Com_CRM_UpdataTime_CRM_UpdataTime' */
  (void)Rte_Write_BSWIOSP_Com_CRM_UpdataTime_CRM_UpdataTime(tmpWrite_7);

  /* Outport: '<Root>/BSWIOSP_Com_CRO_UpdataTime_CRO_UpdataTime' */
  (void)Rte_Write_BSWIOSP_Com_CRO_UpdataTime_CRO_UpdataTime(tmpWrite_8);

  /* Outport: '<Root>/BSWIOSP_Com_CSD_UpdataTime_CSD_UpdataTime' */
  (void)Rte_Write_BSWIOSP_Com_CSD_UpdataTime_CSD_UpdataTime(tmpWrite_9);

  /* Outport: '<Root>/BSWIOSP_Com_CSDP_UpdataTime_CSDP_UpdataTime' */
  (void)Rte_Write_BSWIOSP_Com_CSDP_UpdataTime_CSDP_UpdataTime(tmpWrite_a);
}

/* Model initialize function */
void swc_SetInput_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
