/*
 * File: EVPT_XCUInterFace_Map.c
 *
 * Code generated for Simulink model 'EVPT_XCUInterFace_Map'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Tue Sep  8 10:23:07 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "EVPT_XCUInterFace_Map.h"
#include "EVPT_XCUInterFace_Map_private.h"

/* Model step function for TID1 */
void EVPT_XCUInterFace_Map_Runnable(void)
                             /* Explicit Task: EVPT_XCUInterFace_Map_Runnable */
{
  uint16 tmpRead_d;
  uint16 tmpRead_e;
  uint16 tmpRead_g;
  uint16 tmpRead_l;
  uint16 tmpRead_m;
  uint16 tmpRead_n;
  uint8 tmpRead;
  uint8 tmpRead_0;
  uint8 tmpRead_1;
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
  uint8 tmpRead_f;
  uint8 tmpRead_h;
  uint8 tmpRead_i;
  uint8 tmpRead_j;
  uint8 tmpRead_k;
  uint8 tmpRead_o;
  uint8 tmpRead_p;
  uint8 tmpRead_q;
  uint8 tmpRead_r;

  /* Inport: '<Root>/IPU_MotorTempHighFault1_IPU_MotorTempHighFault1' */
  (void)Rte_Read_IPU_MotorTempHighFault1_IPU_MotorTempHighFault1(&tmpRead_r);

  /* Inport: '<Root>/IPU_MotorOverSpdFlt_IPU_MotorOverSpdFlt' */
  (void)Rte_Read_IPU_MotorOverSpdFlt_IPU_MotorOverSpdFlt(&tmpRead_q);

  /* Inport: '<Root>/IPU_MotorOverCurrFlt_IPU_MotorOverCurrFlt' */
  (void)Rte_Read_IPU_MotorOverCurrFlt_IPU_MotorOverCurrFlt(&tmpRead_p);

  /* Inport: '<Root>/IPU_MCUTempHighAlarm1_IPU_MCUTempHighAlarm1' */
  (void)Rte_Read_IPU_MCUTempHighAlarm1_IPU_MCUTempHighAlarm1(&tmpRead_o);

  /* Inport: '<Root>/IPU_HVBusVolt_500_IPU_HVBusVolt_500' */
  (void)Rte_Read_IPU_HVBusVolt_500_IPU_HVBusVolt_500(&tmpRead_n);

  /* Inport: '<Root>/IPU_HVBusVolt_20_IPU_HVBusVolt_20' */
  (void)Rte_Read_IPU_HVBusVolt_20_IPU_HVBusVolt_20(&tmpRead_m);

  /* Inport: '<Root>/IPU_HVBusCur_IPU_HVBusCur' */
  (void)Rte_Read_IPU_HVBusCur_IPU_HVBusCur(&tmpRead_l);

  /* Inport: '<Root>/BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2' */
  (void)Rte_Read_BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2(&tmpRead_k);

  /* Inport: '<Root>/BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm' */
  (void)Rte_Read_BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm(&tmpRead_j);

  /* Inport: '<Root>/BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2' */
  (void)Rte_Read_BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2
    (&tmpRead_i);

  /* Inport: '<Root>/BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2' */
  (void)Rte_Read_BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2
    (&tmpRead_h);

  /* Inport: '<Root>/BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt' */
  (void)Rte_Read_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt(&tmpRead_g);

  /* Inport: '<Root>/BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID' */
  (void)Rte_Read_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID(&tmpRead_f);

  /* Inport: '<Root>/BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt' */
  (void)Rte_Read_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt(&tmpRead_e);

  /* Inport: '<Root>/BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt' */
  (void)Rte_Read_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt(&tmpRead_d);

  /* Inport: '<Root>/BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID' */
  (void)Rte_Read_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID(&tmpRead_c);

  /* Inport: '<Root>/BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2' */
  (void)Rte_Read_BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2(&tmpRead_b);

  /* Inport: '<Root>/BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2' */
  (void)Rte_Read_BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2
    (&tmpRead_a);

  /* Inport: '<Root>/BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2' */
  (void)Rte_Read_BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2
    (&tmpRead_9);

  /* Inport: '<Root>/BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2' */
  (void)Rte_Read_BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2(&tmpRead_8);

  /* Inport: '<Root>/BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2' */
  (void)Rte_Read_BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2(&tmpRead_7);

  /* Inport: '<Root>/BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2' */
  (void)Rte_Read_BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2(&tmpRead_6);

  /* Inport: '<Root>/BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2' */
  (void)Rte_Read_BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2(&tmpRead_5);

  /* Inport: '<Root>/BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2' */
  (void)Rte_Read_BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2(&tmpRead_4);

  /* Inport: '<Root>/BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2' */
  (void)Rte_Read_BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2(&tmpRead_3);

  /* Inport: '<Root>/BMSH_BattTempAvg_BMSH_BattTempAvg' */
  (void)Rte_Read_BMSH_BattTempAvg_BMSH_BattTempAvg(&tmpRead_2);

  /* Inport: '<Root>/BMSH_BattSysNum_BMSH_BattSysNum' */
  (void)Rte_Read_BMSH_BattSysNum_BMSH_BattSysNum(&tmpRead_1);

  /* Inport: '<Root>/BMSH_BattPackNum_BMSH_BattPackNum' */
  (void)Rte_Read_BMSH_BattPackNum_BMSH_BattPackNum(&tmpRead_0);

  /* Inport: '<Root>/BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb' */
  (void)Rte_Read_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb(&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/EVPT_XCUInterFace_Map_Runnable' incorporates:
   *  SubSystem: '<Root>/EVPT_XCUInterFace_Map_Runnable_sys'
   */
  /* Outport: '<Root>/BMS_DelayDataUpldEnb_EV_BMS_DelayDataUpldEnb_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion'
   */
  (void)Rte_Write_BMS_DelayDataUpldEnb_EV_BMS_DelayDataUpldEnb_EV(tmpRead);

  /* Outport: '<Root>/BMSH_BattPackNum_EV_BMSH_BattPackNum_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion1'
   */
  (void)Rte_Write_BMSH_BattPackNum_EV_BMSH_BattPackNum_EV(tmpRead_0);

  /* Outport: '<Root>/BMSH_BattSysNum_EV_BMSH_BattSysNum_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion2'
   */
  (void)Rte_Write_BMSH_BattSysNum_EV_BMSH_BattSysNum_EV(tmpRead_1);

  /* Outport: '<Root>/BMSH_BattTempAvg_EV_BMSH_BattTempAvg_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion3'
   */
  (void)Rte_Write_BMSH_BattTempAvg_EV_BMSH_BattTempAvg_EV(tmpRead_2);

  /* Outport: '<Root>/BMSH_TBOX_BatIsoAlarm2_EV_BMSH_TBOX_BatIsoAlarm2_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion4'
   */
  (void)Rte_Write_BMSH_TBOX_BatIsoAlarm2_EV_BMSH_TBOX_BatIsoAlarm2_EV(tmpRead_3);

  /* Outport: '<Root>/BMSH_TBOX_BatLowSOC2_EV_BMSH_TBOX_BatLowSOC2_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion5'
   */
  (void)Rte_Write_BMSH_TBOX_BatLowSOC2_EV_BMSH_TBOX_BatLowSOC2_EV(tmpRead_4);

  /* Outport: '<Root>/BMSH_TBOX_BatOverCharge2_EV_BMSH_TBOX_BatOverCharge2_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion6'
   */
  (void)Rte_Write_BMSH_TBOX_BatOverCharge2_EV_BMSH_TBOX_BatOverCharge2_EV
    (tmpRead_5);

  /* Outport: '<Root>/BMSH_TBOX_BatOverSOC2_EV_BMSH_TBOX_BatOverSOC2_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion7'
   */
  (void)Rte_Write_BMSH_TBOX_BatOverSOC2_EV_BMSH_TBOX_BatOverSOC2_EV(tmpRead_6);

  /* Outport: '<Root>/BMSH_TBOX_BatOverTemp2_EV_BMSH_TBOX_BatOverTemp2_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion8'
   */
  (void)Rte_Write_BMSH_TBOX_BatOverTemp2_EV_BMSH_TBOX_BatOverTemp2_EV(tmpRead_7);

  /* Outport: '<Root>/BMSH_TBOX_BatOverVoltage2_EV_BMSH_TBOX_BatOverVoltage2_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion9'
   */
  (void)Rte_Write_BMSH_TBOX_BatOverVoltage2_EV_BMSH_TBOX_BatOverVoltage2_EV
    (tmpRead_8);

  /* Outport: '<Root>/BMSH_TBOX_BatTempUniformity2_EV_BMSH_TBOX_BatTempUniformity2_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion10'
   */
  (void)
    Rte_Write_BMSH_TBOX_BatTempUniformity2_EV_BMSH_TBOX_BatTempUniformity2_EV
    (tmpRead_9);

  /* Outport: '<Root>/BMSH_TBOX_BatUnderVoltage2_EV_BMSH_TBOX_BatUnderVoltage2_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion11'
   */
  (void)Rte_Write_BMSH_TBOX_BatUnderVoltage2_EV_BMSH_TBOX_BatUnderVoltage2_EV
    (tmpRead_a);

  /* Outport: '<Root>/BMSH_TBOX_BatUniformity2_EV_BMSH_TBOX_BatUniformity2_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion12'
   */
  (void)Rte_Write_BMSH_TBOX_BatUniformity2_EV_BMSH_TBOX_BatUniformity2_EV
    (tmpRead_b);

  /* Outport: '<Root>/BMSH_TBOX_CellA_ID_EV_BMSH_TBOX_CellA_ID_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion13'
   */
  (void)Rte_Write_BMSH_TBOX_CellA_ID_EV_BMSH_TBOX_CellA_ID_EV(tmpRead_c);

  /* Outport: '<Root>/BMSH_TBOX_CellA_Volt_EV_BMSH_TBOX_CellA_Volt_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion14'
   */
  (void)Rte_Write_BMSH_TBOX_CellA_Volt_EV_BMSH_TBOX_CellA_Volt_EV(tmpRead_d);

  /* Outport: '<Root>/BMSH_TBOX_CellB_Volt_EV_BMSH_TBOX_CellB_Volt_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion15'
   */
  (void)Rte_Write_BMSH_TBOX_CellB_Volt_EV_BMSH_TBOX_CellB_Volt_EV(tmpRead_e);

  /* Outport: '<Root>/BMSH_TBOX_CellC_ID_EV_BMSH_TBOX_CellC_ID_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion16'
   */
  (void)Rte_Write_BMSH_TBOX_CellC_ID_EV_BMSH_TBOX_CellC_ID_EV(tmpRead_f);

  /* Outport: '<Root>/BMSH_TBOX_CellC_Volt_EV_BMSH_TBOX_CellC_Volt_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion17'
   */
  (void)Rte_Write_BMSH_TBOX_CellC_Volt_EV_BMSH_TBOX_CellC_Volt_EV(tmpRead_g);

  /* Outport: '<Root>/BMSH_TBOX_CellOverVoltage2_EV_BMSH_TBOX_CellOverVoltage2_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion18'
   */
  (void)Rte_Write_BMSH_TBOX_CellOverVoltage2_EV_BMSH_TBOX_CellOverVoltage2_EV
    (tmpRead_h);

  /* Outport: '<Root>/BMSH_TBOX_CellUnderVoltage2_EV_BMSH_TBOX_CellUnderVoltage2_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion19'
   */
  (void)Rte_Write_BMSH_TBOX_CellUnderVoltage2_EV_BMSH_TBOX_CellUnderVoltage2_EV
    (tmpRead_i);

  /* Outport: '<Root>/BMSH_TBOX_FireAlarm_EV_BMSH_TBOX_FireAlarm_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion20'
   */
  (void)Rte_Write_BMSH_TBOX_FireAlarm_EV_BMSH_TBOX_FireAlarm_EV(tmpRead_j);

  /* Outport: '<Root>/BMSH_TBOX_SOCHop2_EV_BMSH_TBOX_SOCHop2_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion21'
   */
  (void)Rte_Write_BMSH_TBOX_SOCHop2_EV_BMSH_TBOX_SOCHop2_EV(tmpRead_k);

  /* Outport: '<Root>/IPU_HVBusCur_EV_IPU_HVBusCur_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion22'
   */
  (void)Rte_Write_IPU_HVBusCur_EV_IPU_HVBusCur_EV(tmpRead_l);

  /* Outport: '<Root>/IPU_HVBusVolt_EV_IPU_HVBusVolt_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion24'
   */
  (void)Rte_Write_IPU_HVBusVolt_EV_IPU_HVBusVolt_EV(tmpRead_n);

  /* Outport: '<Root>/IPU_HVBusVolt_IPUSts_IPU_HVBusVolt_IPUSts' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion23'
   */
  (void)Rte_Write_IPU_HVBusVolt_IPUSts_IPU_HVBusVolt_IPUSts(tmpRead_m);

  /* Outport: '<Root>/IPU_MCUTempHighAlarm1_EV_IPU_MCUTempHighAlarm1_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion25'
   */
  (void)Rte_Write_IPU_MCUTempHighAlarm1_EV_IPU_MCUTempHighAlarm1_EV(tmpRead_o);

  /* Outport: '<Root>/IPU_MotorOverCurrFlt_EV_IPU_MotorOverCurrFlt_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion26'
   */
  (void)Rte_Write_IPU_MotorOverCurrFlt_EV_IPU_MotorOverCurrFlt_EV(tmpRead_p);

  /* Outport: '<Root>/IPU_MotorOverSpdFlt_EV_IPU_MotorOverSpdFlt_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion27'
   */
  (void)Rte_Write_IPU_MotorOverSpdFlt_EV_IPU_MotorOverSpdFlt_EV(tmpRead_q);

  /* Outport: '<Root>/IPU_MotorTempHighFault1_EV_IPU_MotorTempHighFault1_EV' incorporates:
   *  SignalConversion generated from: '<S2>/Data Type Conversion28'
   */
  (void)Rte_Write_IPU_MotorTempHighFault1_EV_IPU_MotorTempHighFault1_EV
    (tmpRead_r);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/EVPT_XCUInterFace_Map_Runnable' */
}

/* Model initialize function */
void EVPT_XCUInterFace_Map_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
