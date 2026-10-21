 
/*
************************************************************************************************************************
*
* File name: Rte_swc_VCOP.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
************************************************************************************************************************
*
* History
*-----------------------------------------------------------------------------------------------------------------------
************************************************************************************************************************
* Version: 3.0
* Author/Date: Gaol/2022.6.14
* Change: New created.
* Cause: New
************************************************************************************************************************
* Version: 4.0
* Author/Date: LanZG/2024.03.18
* Change: Upgrade template.
* Cause: Update
************************************************************************************************************************
*/
#ifndef RTE_SWC_VCOP_H_
#define RTE_SWC_VCOP_H_

#include "Rte_swc_VCOP_Type.h"
#include "Rte_DataHandleType.h"

#ifndef RTE_CORE                                     
#ifdef RTE_APPLICATION_HEADER_FILE                   
# error Multiple application header files included.  
#endif                                               
#define RTE_APPLICATION_HEADER_FILE                  
#ifndef RTE_PTR2ARRAYBASETYPE_PASSING                
#define RTE_PTR2ARRAYBASETYPE_PASSING                
#endif                                               
#endif                                               
                   
#ifdef __cplusplus
extern "C"         
{                  
#endif            

/*
************************************************************************************************************************
*    Buffers for Mode Management
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Rte_Mode_<p>_<m>
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    extern declaration of RTE buffers
************************************************************************************************************************
*/

#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_Heat_LIN_AC_EWP_Heat_LIN;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_HeatrPwrCnsAllwd_LIN_AC_EWP_HeatrPwrCnsAllwd_LIN;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_Run_LIN_AC_EWP_Run_LIN;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_SpeedReq_LIN_AC_EWP_SpeedReq_LIN;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_Temp_LIN_AC_EWP_Temp_LIN;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Battery_Performance_Checksum_BMSH_Battery_Performance_Checksum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_KEY_HS_03_EXT_DO_KEY_HS_03;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_KEY_HS_05_EXT_DO_KEY_HS_05;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_HS_11_EXT_DO_RELAY_HS_11;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_HS_6_EXT_DO_RELAY_HS_6;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_HS_8_EXT_DO_RELAY_HS_8;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_HS_9_EXT_DO_RELAY_HS_9;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_LS_10_EXT_DO_RELAY_LS_10;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_LS_12_EXT_DO_RELAY_LS_12;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_LS_5_EXT_DO_RELAY_LS_5;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_LS_7_EXT_DO_RELAY_LS_7;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_LS_9_EXT_DO_RELAY_LS_9;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_HVIL_1_DutyCycle_EXT_PO_HVIL_1_DutyCycle;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_HVIL_1_Period_EXT_PO_HVIL_1_Period;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_HVIL_2_DutyCycle_EXT_PO_HVIL_2_DutyCycle;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_HVIL_2_Period_EXT_PO_HVIL_2_Period;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_1_DutyCycle_EXT_PO_PWM_1_DutyCycle;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_1_Period_EXT_PO_PWM_1_Period;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_2_DutyCycle_EXT_PO_PWM_2_DutyCycle;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_2_Period_EXT_PO_PWM_2_Period;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_4_DutyCycle_EXT_PO_PWM_4_DutyCycle;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_4_Period_EXT_PO_PWM_4_Period;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_CCWFlg_PMS_FWFV_CCWFlg_PMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_CurrentPos_PMS_FWFV_CurrentPos_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_InitState_PMS_FWFV_InitState_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_MotorState_PMS_FWFV_MotorState_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_OverCurrentFlt_PMS_FWFV_OverCurrentFlt_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_OverTempFlt_PMS_FWFV_OverTempFlt_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_OverVoltageFlt_PMS_FWFV_OverVoltageFlt_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_RESP_ERROR_PMS_FWFV_RESP_ERROR_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_UnderVoltageFlt_PMS_FWFV_UnderVoltageFlt_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_O_S_PIN110_O_S_PIN110;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_O_S_PIN123_O_S_PIN123;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_O_S_PIN83_O_S_PIN83;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_O_S_PIN88_O_S_PIN88;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_O_S_PIN89_O_S_PIN89;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_O_S_PIN98_O_S_PIN98;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN104_Duty_O_T_PIN104_Duty;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN104_Period_O_T_PIN104_Period;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN118_Duty_O_T_PIN118_Duty;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN118_Period_O_T_PIN118_Period;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN14_Duty_O_T_PIN14_Duty;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN14_Period_O_T_PIN14_Period;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN28_Duty_O_T_PIN28_Duty;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN28_Period_O_T_PIN28_Period;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN77_Duty_O_T_PIN77_Duty;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN77_Period_O_T_PIN77_Period;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN82_Duty_O_T_PIN82_Duty;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN82_Period_O_T_PIN82_Period;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ADCCtrlSts_PMS_ADCCtrlSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_APA_BeControlled_Status_PMS_APA_BeControlled_Status;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AppSts_EV_PMS_AppSts_EV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Brake1Switch_PMS_Brake1Switch;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Brake2Switch_PMS_Brake2Switch;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Command_AliveCounter_EV_PMS_Command_AliveCounter_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Command_Checksum_EV_PMS_Command_Checksum_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ControlSetSpeed_PMS_ControlSetSpeed;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CruiseControlSts_PMS_CruiseControlSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CruiseSwitchSts_PMS_CruiseSwitchSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CruisingDstSwtFb_PMS_CruisingDstSwtFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CurrentGearPosition_EV_PMS_CurrentGearPosition_EV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CurrentGearPosition_Valid_EV_PMS_CurrentGearPosition_Valid_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DCDC_Ctrl_AliveCounter_PMS_DCDC_Ctrl_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DCDC_Ctrl_Checksum_PMS_DCDC_Ctrl_Checksum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DM_FailureReasonAndSysFaultFBK_PMS_DM_FailureReasonAndSysFaultFBK;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DcDc1ActvdReq_EV_PMS_DcDc1ActvdReq_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriveCircuitTemp_EV_PMS_DriveCircuitTemp_EV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriverRemind_PMS_DriverRemind;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EDCPEnable_EV_PMS_EDCPEnable_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EDCPPWMCtrl_EV_PMS_EDCPPWMCtrl_EV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EPBClosedReq_PMS_EPBClosedReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EPS_SteeringAngleValueInvalid_PMS_EPS_SteeringAngleValueInvalid;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EPedlDrvrIndcnMsg_PMS_EPedlDrvrIndcnMsg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EpedalActive_PMS_EpedalActive;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ExecuteLockVehResults_PMS_ExecuteLockVehResults;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FWFV_MoveEnable_PMS_FWFV_MoveEnable;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FWFV_MoveEnable_LIN_PMS_FWFV_MoveEnable_LIN;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FWFV_ReqMovePos_PMS_FWFV_ReqMovePos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FWFV_ReqMovePos_LIN_PMS_FWFV_ReqMovePos_LIN;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HvBattCooltLvl_PMS_HvBattCooltLvl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MCUActvdReq_PMS_MCUActvdReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MCUTemp_EV_PMS_MCUTemp_EV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_EnableReq_LIN_PMS_MHGV_EnableReq_LIN;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_PosSet_LIN_PMS_MHGV_PosSet_LIN;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_ReqMotorEmgyStop_LIN_PMS_MHGV_ReqMotorEmgyStop_LIN;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_ReqMotorOptRecovery_LIN_PMS_MHGV_ReqMotorOptRecovery_LIN;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Odometerbackup_PMS_Odometerbackup;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_SlidingmomentrSetReq_PMS_SlidingmomentrSetReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TBOX_HVILState_PMS_TBOX_HVILState;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TBOX_HVILState_3A1_PMS_TBOX_HVILState_3A1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ThermalReq_PMS_ThermalReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTReady_EV_PMS_ePTReady_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTRegencyLevInd_PMS_ePTRegencyLevInd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_st_ShtDown_st_ShtDown;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_vcob_VCOP_BMSH_ChargeLEDCtrl;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_BswAswRte_EXT_DO_RELAY_LS_10_Fb_EXT_DO_RELAY_LS_10_Fb;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_BswAswRte_EXT_DO_RELAY_LS_7_Fb_EXT_DO_RELAY_LS_7_Fb;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_BswAswRte_EXT_DO_RELAY_LS_9_Fb_EXT_DO_RELAY_LS_9_Fb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte0_F190_VIN_Byte0;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte1_F190_VIN_Byte1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte10_F190_VIN_Byte10;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte11_F190_VIN_Byte11;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte12_F190_VIN_Byte12;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte13_F190_VIN_Byte13;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte14_F190_VIN_Byte14;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte15_F190_VIN_Byte15;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte16_F190_VIN_Byte16;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte2_F190_VIN_Byte2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte3_F190_VIN_Byte3;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte4_F190_VIN_Byte4;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte5_F190_VIN_Byte5;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte6_F190_VIN_Byte6;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte7_F190_VIN_Byte7;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte8_F190_VIN_Byte8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte9_F190_VIN_Byte9;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte2_F193_ECUHardwareVersionNumber_Byte2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte3_F193_ECUHardwareVersionNumber_Byte3;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte4_F193_ECUHardwareVersionNumber_Byte4;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte6_F193_ECUHardwareVersionNumber_Byte6;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte7_F193_ECUHardwareVersionNumber_Byte7;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte8_F193_ECUHardwareVersionNumber_Byte8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte2_F195_ECUSoftwareVersionNumber_Byte2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte3_F195_ECUSoftwareVersionNumber_Byte3;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte4_F195_ECUSoftwareVersionNumber_Byte4;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte6_F195_ECUSoftwareVersionNumber_Byte6;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte7_F195_ECUSoftwareVersionNumber_Byte7;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte8_F195_ECUSoftwareVersionNumber_Byte8;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_b_acHvilOpn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_b_acHvilOpnInvld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_b_accPedlPosVld;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosCan_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosSens1_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosSens2_pct;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_b_adcCtrlGearEn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_st_pmsAdcCtrldSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_st_pmsCanBusRecSta;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPressedFromSwitch;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_p_brkVacuumPres_bar;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_x_brkPedlPos_pct;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_cesd_b_acuCrash;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcHvilFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcHvilFltInvld;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_st_gearLvrPosSeql;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_n_mot2ActSpd_rpm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2ActTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_u_busInv2HVAct_V;
extern VAR(ParkingStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_epbd_e_parkingSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvilOpen;
extern VAR(HVBattStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbStatus;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_fact_hvbSOH_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_i_hvbCurr_A;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_hvbChgPwr_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_q_hvbSOC_pct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hvbThermMngReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_tboxIntelChgQuit;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbAvg_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbInCoolTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbMin_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbTemp_C;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_b_vcuSelfChkOk;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_t_ts5SnsrTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_u_batIntSmpl_V;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_fact_trsm2GearRat;
extern VAR(SInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_st_trsm2GearAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_R_posInsIRes_Ohm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_ang_strWhlAng_rad;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_AccyEnReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_AccyFltSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_CCSginal;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_DryAirSwitch;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ResrAirSwitch;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_brkSwt1Actv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_brkSwt2Actv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_cntnrCtrlEnaFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_dcdcStsAlm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_dcdcTempAlm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_disChgSwtSt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_driverEcoModeReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_emgyStopIn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgBatCol;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvCcwFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvInitSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvMotSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvOvrCurrFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvOvrTempFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvOvrVoltFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvRespErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvUndVoltFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hvbHvilFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ignStsOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ignStsStrt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvCcwFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvInitSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvMotSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvOvrCurrFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvOvrTempFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvOvrVoltFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvRespErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvUndVoltFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_obcWakeUpActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_odometerInvalid;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_d_odometer_km;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_i_dcdcInpCurr_A;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_i_hvbCurr_A;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbCellMaxID;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbCellMinID;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbCellSum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbMaxTempID;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbMinTempID;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbTempSum;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_GearPosn;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_HVILReturnPWM;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_WatPmpEP1FbPWM;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_WatPmpEP2FbPWM;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_WatPmpEP3FbPWM;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_fan1Fb;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_fan2Fb;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_fwfvCrtPos;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_mhgvCrtPos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_24vDcdcModAct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_BmsTempOutOfCtrlFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_actWorkSts1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_batLowSoc2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_batOvrSoc2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_batOvrVolt2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_batUdrVolt2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bmsBattPackMatchFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bmsBattPackNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bmsBattSysNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bmsTboxFireAlm;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_cellOverVolt2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_cellUdrVolt2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_dcChgCcSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_eadInv2TempHiAlrm;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ehbBrkSysErrFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_epsEpasFail;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flg2FctCfgVehTyp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgAccy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbBatUniformity;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbBattIsolationSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbCellTempDevFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbCellVoltDevFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgOvrCurr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDCChgPlgNOvrTmp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDCChgPlgPOvrTmp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDCChgProcss;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbInslErr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbOvrChgFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbSocFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbSocJumpFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbStatus;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbStsChgFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbStsDischgFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbTempFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbThermMngReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipuInvTempHighAlm;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipuMotTempHighFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipuMotorOverCurrFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipuMotorOverSpdFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcChgSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcOnBdCCline;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_pepsPduLvl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_pepsPduLvlVld;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxRsrChgSt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_acwpOutptTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbCooltInTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbCooltOutTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbMax_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbMin_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbOutCoolTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbSetTgtTemp_C;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_tm_hvbFnshChgTim_m;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_BmsMaxCellVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_BmsMinCellVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_Brk2_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_Brk_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_TS5sensorFb_mV;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_VacTkEnFb_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_accPdlSens1InpVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_accPdlSens2InpVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_dcdcRelayVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hvbCooltInSnsr_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hvbCooltOutSnsr_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hvbPackVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hvbVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_ipuHVBusVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_a_vscLongitAcce_mps2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ESPActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_vehSpdVld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_vscBrkLghtActv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_st_vscIsgActvDampModReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpdRaw_kph;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_ATAU_vcsb_ATAU_pmmd_b_ePTRelease_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpRlyEn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_brkPmp1Rly;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_p_VacPumpPressure_kPa;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_pscd_b_epsEna;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_pscd_b_epsStopFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_pscd_frq_epsFrqTgt_Hz;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_brpd_b_brkSwtMismatch;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_st_edcpFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_st_hbcpFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_st_vehSysErrLevel;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_accd_pwr_hvAttpwr_kW;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_zeroPwrFb;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_i_bmshAlwChgCurrMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_pct_vcuChgDepReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_pwr_accmHvClPwrAllwd_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_pwr_acwpHeatPwrCnsAllwd;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_pwr_ptcHvHtPwrAllwd_kW;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_st_vcuChgLimResp;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_V_engFuelConsAvg_lp100km;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_CruisingDstSwtFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_HazardReqLmpOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_brkSysFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_ePTFault;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_odoBckpEn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_turtleLmpOn;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_odoTotal_km;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_pmsOdoBckUpMilg_km;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_vehCrsDst_km;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_vehDrvRngEVMod_km;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_vehDrvRngStandard_km;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_num_AecEV_kWhp100km;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_num_errorCode;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_pwr_hvPwrRemain_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_q_hvbSOC_pct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_drvModInd;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_drvPfmncRedn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_drvrOptRmdr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehDrvMode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_bmsd_e_modeTgt;
extern VAR(DCDCMode, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_dccd_e_modeTgt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_dccd_pct_DCDCPwrLmt;
extern VAR(ElMac, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_eadd_e_inv2ModeTgt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_CampModeFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_TakeEleSwtIndReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyHvOnCmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyLvPwrOnCmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyPreRlyCmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyWrkEnCmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_allowChg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_dchaOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_hvbIntelChgExitReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_lvCutOffReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_tmOutFlgCfm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_vcuWkUpCmd;
extern VAR(PmmStatus, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_e_PmmStatus;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_CampModeFbFailrReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_RmChgCmdFailPmt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyPreRlyFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyPreRlySts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyRlyFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyRlySts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyRlyVoltSamSw;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyTakeSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_bbmWrkEnCmd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hcmMaiRlyNegClsReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hvbAssiRlyPosClsReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hvbMaiRlyNegClsReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hvbMaiRlyPosClsReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_otaHvOnOFFReqSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_otaHvOnOffFailInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_ptRdyInd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_tboxChgSftSwCtlStEV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_obcd_b_chargerPlugged;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_MEST_vcsb_MEST_masd_m_vehWeight_kg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_invSpdLmtRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_inventorySpdLmtReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_lifeCnt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_lockVehPer;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_lockVehPerRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_pwrOffCmd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_pwrOffCmdRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_spdLmtLevelReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_spdLmtLvRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_tboxLifeSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_verCvsRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_versionConversion;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_b_LockVehSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_num_FunAnti_DismantleActive;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_num_FunLockVehActive;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_num_LockLimResult;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_num_LockVehType;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_st_LockVehExecutedSts;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_tqld_tq_whlMax_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_tqld_tq_whlMin_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_acc_intAccTgt_mps2;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_acc_vehAccTgt_mps2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_b_accCtrlActv;
extern VAR(CrsBtnErrSts, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsBtnErrSts;
extern VAR(CrsBtnSts, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsBtnSts;
extern VAR(CrModeMngr_e, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsCtrlSpdMode;
extern VAR(CruiseSts_e, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsCtrlSts;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_tq_whlDem_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_v_crsCtrlTgtSpd_kph;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_v_crsTgtSpdQuit_kph;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_vsld_v_vehMaxSpd_kph;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_dtdd_st_RegenLvlDisp;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_dtdd_tq_whlCoastDrgDem_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tdad_tq_whlDemUnlim_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tdad_tq_whlDem_Nm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_b_accPedlPosVirtVld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_b_gpOvrd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_st_ehbOvrdActv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_st_ehbOvrdTyp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_st_whlAcceSupprsn;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_x_accPedlPosVirt_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tvrd_tq_mot2TgtTqReq_Nm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_ActiveCool_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_BalanceHeat_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_PassCool_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_PassHeat_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_accmEnb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_fanRly1Req;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_fanRly2Req;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna3;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna3HW;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEnaHW;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_hvbDeft;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_iptcHtIpuCl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_iptcHtIpuResvHt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_ipuHeatEnableFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_ipuResvHt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_ipuSupHtIptcHt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_tv1V3;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_tv2V2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_wtrPmp1CtrlEnabled;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_wtrPmp2CtrlEnabled;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_FWFVTgt_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_MHGVTgt_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_fan1TgtSpd_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_fan2TgtSpd_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_pmp1TgtSpd_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_pmp2TgtSpd_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_pwr_ipuHeatPwrAllwd_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_q_pmp2FlowFeedback;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_acceRlyVoltSamSwitch;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_acwpHeat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_acwpSpdReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_ptc3ConnStsFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_ptc3RlyFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_ptcConnStsFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_ptcRlyFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_ptcRlyVoltSamSwitch;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_t_acwpTemp_C;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_epbClsdReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_gearPosVld;
extern VAR(DriveDir, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_e_driveDirSel;
extern VAR(GearLeverPos, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_e_gearLvrPos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_st_gearLvrLckInd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_b_engStopReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_hsdFltClear;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_nmSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_pwrHoldReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_vcuAwb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_vcuRmr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_num_vcuAddr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_st_bdCanModeReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_st_ptCanModeReq;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_st_stayAwkReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_st_vcuWkUpReason;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_Heat_AC_EWP_Heat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_HeatrPwrCnsAllwd_AC_EWP_HeatrPwrCnsAllwd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_Run_AC_EWP_Run;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_SpeedReq_AC_EWP_SpeedReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_Temp_AC_EWP_Temp;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_ACChgTimeRemain_BMSH_ACChgTimeRemain;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattCurr_BMSH_BattCurr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattFaultLampState_BMSH_BattFaultLampState;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattPackNum_PMS_BMSH_BattPackNum_PMS;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattRemainEnergy_BMSH_BattRemainEnergy;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattSOC_BMSH_BattSOC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattSOH_BMSH_BattSOH;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattSysNum_PMS_BMSH_BattSysNum_PMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattTempAvg_PT_BMSH_BattTempAvg_PT;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattVolt_BMSH_BattVolt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_CellTemp_Uniformity_BMSH_CellTemp_Uniformity;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_CellVolt_Uniformity_BMSH_CellVolt_Uniformity;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Cell_OverVol_BMSH_Cell_OverVol;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Cell_TotalNum_BMSH_Cell_TotalNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Cell_UnderVol_BMSH_Cell_UnderVol;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_ChargeLEDCtrl_BMSH_ChargeLEDCtrl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_ChargeToBeFinished_BMSH_ChargeToBeFinished;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Charge_Over_Current_BMSH_Charge_Over_Current;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_ChgTimeRemain_BMSH_ChgTimeRemain;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_DCChgminusSocketTempSensing_Failure_BMSH_DCChgminusSocketTempSensing_Failure;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_DCChgplusSocketTempSensing_Failure_BMSH_DCChgplusSocketTempSensing_Failure;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_FastChgCC2ConntState_BMSH_FastChgCC2ConntState;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_HVBusVolt_BMSH_HVBusVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_HvBattCooltTReq_BMSH_HvBattCooltTReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_HvBattThermMod_BMSH_HvBattThermMod;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_HvShutdownReq_BMSH_HvShutdownReq;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_ICU_BatteryElectricDTE_BMSH_ICU_BatteryElectricDTE;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Inlet_WaterTemp_BMSH_Inlet_WaterTemp;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_InsulationRes_BMSH_InsulationRes;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_InsulationRes_Fault_BMSH_InsulationRes_Fault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Low_SOC_BMSH_Low_SOC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Outlet_WaterTemp_BMSH_Outlet_WaterTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Over_SOC_BMSH_Over_SOC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Over_Temperature_BMSH_Over_Temperature;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Pack_OverVoltage_BMSH_Pack_OverVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Pack_UnderVoltage_BMSH_Pack_UnderVoltage;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_SOC_Hop_BMSH_SOC_Hop;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatIsoAlarm2_PT_BMSH_TBOX_BatIsoAlarm2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatIsoAlarm3_PMS_BMSH_TBOX_BatIsoAlarm3_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatLowSOC2_PT_BMSH_TBOX_BatLowSOC2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatLowSOC3_PMS_BMSH_TBOX_BatLowSOC3_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverCharge2_PT_BMSH_TBOX_BatOverCharge2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverCharge3_PMS_BMSH_TBOX_BatOverCharge3_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverSOC2_PT_BMSH_TBOX_BatOverSOC2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverSOC3_PMS_BMSH_TBOX_BatOverSOC3_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverTemp2_PT_BMSH_TBOX_BatOverTemp2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverTemp3_PMS_BMSH_TBOX_BatOverTemp3_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverVoltage2_PT_BMSH_TBOX_BatOverVoltage2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverVoltage3_PMS_BMSH_TBOX_BatOverVoltage3_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatTempUniformity2_PT_BMSH_TBOX_BatTempUniformity2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatTempUniformity3_PMS_BMSH_TBOX_BatTempUniformity3_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatUnderVoltage2_PT_BMSH_TBOX_BatUnderVoltage2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatUnderVoltage3_PMS_BMSH_TBOX_BatUnderVoltage3_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatUniformity2_PT_BMSH_TBOX_BatUniformity2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatUniformity3_PMS_BMSH_TBOX_BatUniformity3_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_CellOverVoltage2_PT_BMSH_TBOX_CellOverVoltage2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_CellOverVoltage3_PMS_BMSH_TBOX_CellOverVoltage3_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_CellUnderVoltage2_PT_BMSH_TBOX_CellUnderVoltage2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_CellUnderVoltage3_PMS_BMSH_TBOX_CellUnderVoltage3_PMS;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_FireAlarm2_PMS_BMSH_TBOX_FireAlarm2_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_SOCHop2_PT_BMSH_TBOX_SOCHop2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_SOCHop3_PMS_BMSH_TBOX_SOCHop3_PMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TempSensor_MaxTemp_BMSH_TempSensor_MaxTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TempSensor_MinTemp_BMSH_TempSensor_MinTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TempSensor_TotalNum_BMSH_TempSensor_TotalNum;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_ThermalOutofControl_BMSH_ThermalOutofControl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Vehicle_HVILSts_PHEV_BMSH_Vehicle_HVILSts_PHEV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_VoltCurr_Checksum_BMSH_VoltCurr_Checksum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_stMode_BMSH_stMode;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMS_BattPackMatchFault_BMS_BattPackMatchFault;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMS_BattPackMatchFault1_PMS_BMS_BattPackMatchFault1_PMS;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMS_MaxCellVolt_BMS_MaxCellVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMS_MaxTemp1SnsNum_BMS_MaxTemp1SnsNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMS_MaxVoltCellNum_BMS_MaxVoltCellNum;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMS_MinCellVolt_BMS_MinCellVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMS_MinVoltCellNum_BMS_MinVoltCellNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMS_MinxTemp1SnsNum_BMS_MinxTemp1SnsNum;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_DrvPfmncRedn_DrvPfmncRedn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_EDCP_Flt_EDCP_Flt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_EDCP_PWMFB_EDCP_PWMFB;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_HBCP_Flt_HBCP_Flt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_HBCP_PWMFB_HBCP_PWMFB;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_IPK_IPKTotalOdometer_EV_IPK_IPKTotalOdometer_EV;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_IPU_HVBusCur_PT_IPU_HVBusCur_PT;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_IPU_HVBusVolt_PT_IPU_HVBusVolt_PT;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_IPU_IPUTAlm_IPU_IPUTAlm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_IPU_MCUTempHighAlarm1_PT_IPU_MCUTempHighAlarm1_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_IPU_MCUTempHighAlarm2_PMS_IPU_MCUTempHighAlarm2_PMS;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_IPU_MotorOverCurrFlt1_PMS_IPU_MotorOverCurrFlt1_PMS;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_IPU_MotorOverSpdFlt1_PMS_IPU_MotorOverSpdFlt1_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_IPU_MotorTempHighFault1_PT_IPU_MotorTempHighFault1_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_IPU_MotorTempHighFault2_PMS_IPU_MotorTempHighFault2_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_CCWFlg_PMS_MHGV_CCWFlg_PMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_CurrentPos_PMS_MHGV_CurrentPos_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_InitState_PMS_MHGV_InitState_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_MotorState_PMS_MHGV_MotorState_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_OverCurrentFlt_PMS_MHGV_OverCurrentFlt_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_OverTempFlt_PMS_MHGV_OverTempFlt_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_OverVoltageFlt_PMS_MHGV_OverVoltageFlt_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_RESP_ERROR_PMS_MHGV_RESP_ERROR_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_UnderVoltageFlt_PMS_MHGV_UnderVoltageFlt_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_ODP_TBOX_DcDcStsAlm_ODP_TBOX_DcDcStsAlm;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_ODP_TBOX_DcDcStsAlm1_PMS_ODP_TBOX_DcDcStsAlm1_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_ODP_TBOX_TDcDcAlm_ODP_TBOX_TDcDcAlm;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_ODP_TBOX_TDcDcAlm1_PMS_ODP_TBOX_TDcDcAlm1_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_0X16A_TimeoutFlag_PMS_0X16A_TimeoutFlag;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_PMS_32960FltNum_PMS_PMS_32960FltNum_PMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ACC1PosVol_PMS_ACC1PosVol;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ACC2PosVol_PMS_ACC2PosVol;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ACCMEnable_PMS_ACCMEnable;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ACC_BeControlled_Status_PMS_ACC_BeControlled_Status;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AcceRelayVoltSampSwich_PMS_AcceRelayVoltSampSwich;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AcceSuppressionSts_PMS_PMS_AcceSuppressionSts_PMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AccelPedalPosition_PMS_AccelPedalPosition;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AccelPedalPositionInvalid_PMS_AccelPedalPositionInvalid;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Acceleration_PMS_Acceleration;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AccessoryConnStsFb_PMS_AccessoryConnStsFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AccessoryCtrlCommand_PMS_AccessoryCtrlCommand;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AccessoryRelayFlt_PMS_AccessoryRelayFlt;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ActualPTTorque_PMS_ActualPTTorque;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ActualPTTorqueInvalid_PMS_ActualPTTorqueInvalid;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AppSts_PMS_AppSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AuthResult_PMS_AuthResult;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AveragePowerConsumption_PMS_AveragePowerConsumption;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BBM1CtrlCmd_PMS_BBM1CtrlCmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BBMAllowEnable_Ctrl_PMS_BBMAllowEnable_Ctrl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BBMPowerSupplyEn_Ctrl_PMS_BBMPowerSupplyEn_Ctrl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BBM_FaultStatus_PMS_BBM_FaultStatus;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BBM_HVReq_PMS_BBM_HVReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BBM_WorkSts_PMS_BBM_WorkSts;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BMSH_BattRemainEnergy_PMS_BMSH_BattRemainEnergy;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BMSH_BattSOCDisp_PMS_BMSH_BattSOCDisp;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BMSH_BattSOH_PMS_BMSH_BattSOH;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BMS_Reignstatus1_PMS_BMS_Reignstatus1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BMS_Reignstatus2_PMS_BMS_Reignstatus2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BatCoolType_PMS_BatCoolType;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BattPackInCoolTempback_EV_PMS_BattPackInCoolTempback_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BattPackOutCoolTempback_EV_PMS_BattPackOutCoolTempback_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BatteryVol_PMS_BatteryVol;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Brake_LightsRequest_PMS_Brake_LightsRequest;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BrkSysErr_PMS_BrkSysErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CANBus_RecSta_PMS_CANBus_RecSta;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CPSREn_PMS_CPSREn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CPSRU_PMS_CPSRU;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CSControl1_CheckSum_PMS_CSControl1_CheckSum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CSControl2_CheckSum_PMS_CSControl2_CheckSum;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CampModeFb_PMS_CampModeFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CampModeFbFailrReason_PMS_CampModeFbFailrReason;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ChargPwr_PMS_ChargPwr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ChargWakeupSts_PMS_ChargWakeupSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ChargeHV_Status_PMS_ChargeHV_Status;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ChargeLimitResponse_PMS_ChargeLimitResponse;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ChargerFault_PMS_ChargerFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Command_AliveCounter_PMS_Command_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Command_Checksum_PMS_Command_Checksum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CoolingFanFaultFB_PMS_CoolingFanFaultFB;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Ctrl_Checksum_PMS_Ctrl_Checksum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CurrentGearPosition_PMS_CurrentGearPosition;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DCDCAwake_HW_PMS_DCDCAwake_HW;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DCDCPwrLmt_PMS_DCDCPwrLmt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DDwaterPump_PWMCtrl_EV_PMS_DDwaterPump_PWMCtrl_EV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DcDcActvdReq_PMS_DcDcActvdReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DisChrgrSwtSt_PMS_DisChrgrSwtSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DischargeEnable_PMS_DischargeEnable;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DoubleFlashLampOn_PMS_DoubleFlashLampOn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriveModeInd_PMS_DriveModeInd;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriverDemandTorque_PMS_DriverDemandTorque;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriverDemandTorqueInvalid_PMS_DriverDemandTorqueInvalid;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriverGearAbort_PMS_DriverGearAbort;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DrivingTakeEleSts_PMS_DrivingTakeEleSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DrvrGearLvrLockIndcn_PMS_DrvrGearLvrLockIndcn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EDCPEnable_PMS_EDCPEnable;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EDCP_FaultFB_PMS_EDCP_FaultFB;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EDCP_PWMCtrl_PMS_EDCP_PWMCtrl;
extern VAR(SInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EPS_SteeringAngleValue_PMS_EPS_SteeringAngleValue;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EVDTEodometer_PMS_EVDTEodometer;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EngControl_CheckSum_PMS_EngControl_CheckSum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EngTrqReqSrc_PMS_EngTrqReqSrc;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ErrCode_PMS_ErrCode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FAN_PWMCtrl_PMS_FAN_PWMCtrl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Fn1GearRlyDrvStsFb_PMS_Fn1GearRlyDrvStsFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Fn2GearRlyDrvStsFb_PMS_Fn2GearRlyDrvStsFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FunAnti_DismantleActive_PMS_FunAnti_DismantleActive;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FunLockVehActive_PMS_FunLockVehActive;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_GP_Ovrd_PMS_GP_Ovrd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_GearOperateErr_PMS_GearOperateErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Gear_intervene_PMS_Gear_intervene;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_GrossComVehWeight_PMS_GrossComVehWeight;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HBCPEnable_PMS_HBCPEnable;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HBCP_FaultFB_PMS_HBCP_FaultFB;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HBCP_PWMCtrl_PMS_HBCP_PWMCtrl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVIL1Sts_PMS_HVIL1Sts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVIL1Sts_UB_PMS_HVIL1Sts_UB;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVIL2Sts_PMS_HVIL2Sts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVIL2Sts_UB_PMS_HVIL2Sts_UB;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVILSts_PMS_HVILSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVILSts_UB_PMS_HVILSts_UB;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVPRASts_PMS_HVPRASts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HardwareMajorVer_PMS_HardwareMajorVer;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HardwareMinorVer_PMS_HardwareMinorVer;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HvCoolgPwrAllwd_PMS_HvCoolgPwrAllwd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HvHeatgPwrAllwd_PMS_HvHeatgPwrAllwd;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IPK_HandBrakeSts_PMS_IPK_HandBrakeSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IgnONSts_PMS_IgnONSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IntelligentChargeExitReq_PMS_IntelligentChargeExitReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IntelligentChargeQuit_PMS_IntelligentChargeQuit;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IntelligentChargeState_PMS_IntelligentChargeState;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_InventorySpdLmtRxSts_PMS_InventorySpdLmtRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_InventorySpdLmtSts_PMS_InventorySpdLmtSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IsgModReq_PMS_IsgModReq;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IsgTqReq_PMS_IsgTqReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LTCoolingFanFB_PMS_LTCoolingFanFB;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Life_PMS_Life;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LimpHomeSts_PMS_LimpHomeSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LockLimResult_PMS_LockLimResult;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LockVehExecutedSts_PMS_LockVehExecutedSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LockVehPerFlag_PMS_LockVehPerFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LockVehPerRxSts_PMS_LockVehPerRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LockVehSts_PMS_LockVehSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LockVehType_PMS_LockVehType;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MCUFlowFeedback_EV_PMS_MCUFlowFeedback_EV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_EnableReq_PMS_MHGV_EnableReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_PosSet_PMS_MHGV_PosSet;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_ReqMotorEmgyStop_PMS_MHGV_ReqMotorEmgyStop;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_ReqMotorOptRecovery_PMS_MHGV_ReqMotorOptRecovery;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MaxPTTorqueAllowed_PMS_MaxPTTorqueAllowed;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MinPTTorqueAllowed_PMS_MinPTTorqueAllowed;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ModeControl_CheckSum_PMS_ModeControl_CheckSum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_NMSts_PMS_NMSts;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_PMS_OTAInstrucStsReminder_PMS_OTAInstrucStsReminder;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_PMS_OTAInstructRxnSts_PMS_OTAInstructRxnSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_OdometerbackupEnable_PMS_OdometerbackupEnable;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PEPSAuth_PMS_PEPSAuth;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PEPS_0x1E2_TimeoutFlag_PMS_PEPS_0x1E2_TimeoutFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PEPS_PowerMode_PMS_PEPS_PowerMode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PEPS_PowerModeValidity_PMS_PEPS_PowerModeValidity;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTC1ConnStsFb_PMS_PTC1ConnStsFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTC1RelayFlt_PMS_PTC1RelayFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTC2Enable_PMS_PTC2Enable;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTC3ConnStsFb_PMS_PTC3ConnStsFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTC3Enable_PMS_PTC3Enable;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTC3RelayFlt_PMS_PTC3RelayFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTCEnable_PMS_PTCEnable;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTCRelayVoltSampSwich_PMS_PTCRelayVoltSampSwich;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PowerOffCmdRxSts_PMS_PowerOffCmdRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PowerOffCmdSts_PMS_PowerOffCmdSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PreAccessoryConnStsFb_PMS_PreAccessoryConnStsFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PreAccessoryRelayFlt_PMS_PreAccessoryRelayFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Real_PedalPosition_PMS_Real_PedalPosition;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RegenTarTrqPot_PMS_RegenTarTrqPot;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RegenTarTrqPotQualifier_PMS_RegenTarTrqPotQualifier;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RegenTrqAct_PMS_RegenTrqAct;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RegenTrqActQualifier_PMS_RegenTrqActQualifier;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RegenTrqPot_PMS_RegenTrqPot;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RegenTrqPotQualifier_PMS_RegenTrqPotQualifier;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RegulationSpeed_PMS_PMS_RegulationSpeed_PMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RemChrgCmdFailrPrompt_PMS_RemChrgCmdFailrPrompt;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ReqSeed_PMS_ReqSeed;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RespResult_PMS_RespResult;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_SelfCheckSts_PMS_SelfCheckSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_SoftwareMajorVer_PMS_SoftwareMajorVer;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_SoftwareMinorVer_PMS_SoftwareMinorVer;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_SpdLmtLevel_PMS_SpdLmtLevel;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_SpdLmtLevelRxSts_PMS_SpdLmtLevelRxSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_StartActive_PMS_StartActive;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Stayawake_reasons_PMS_Stayawake_reasons;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_StsBrkSwitch1_PMS_StsBrkSwitch1;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_StsBrkSwitch1Invalid_PMS_StsBrkSwitch1Invalid;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_StsBrkSwitch1Invalid_PMS_PMS_StsBrkSwitch1Invalid_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_StsBrkSwitch1_PMS_PMS_StsBrkSwitch1_PMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_StsSwap_PMS_StsSwap;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_SwapAuthRelease_EV_PMS_SwapAuthRelease_EV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TBOX_BrkSysErr_PMS_TBOX_BrkSysErr;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TBOX_BrkSysErr1_PMS_PMS_TBOX_BrkSysErr1_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TBOX_HVILSts_PMS_TBOX_HVILSts;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TBOX_HVILSts1_PMS_PMS_TBOX_HVILSts1_PMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TBOX_LifeSts_PMS_TBOX_LifeSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TakeEleSwtIndReq_PMS_TakeEleSwtIndReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Torque_Ovrd_Active_PMS_Torque_Ovrd_Active;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Torque_Ovrd_Type_PMS_Torque_Ovrd_Type;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TurtleLampOn_PMS_TurtleLampOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TurtleLampOn2_PMS_TurtleLampOn2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_V2XDchaSwtFb1_PMS_V2XDchaSwtFb1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINCode1_8_15_S_PMS_VINCode1_8_15_S;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINCode2_9_16_S_PMS_VINCode2_9_16_S;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINCode3_10_17_S_PMS_VINCode3_10_17_S;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINCode4_11_S_PMS_VINCode4_11_S;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINCode5_12_S_PMS_VINCode5_12_S;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINCode6_13_S_PMS_VINCode6_13_S;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINCode7_14_S_PMS_VINCode7_14_S;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINMessageNum_S_PMS_VINMessageNum_S;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VacuumPressure_PMS_VacuumPressure;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VacuumPumpCmd_PMS_VacuumPumpCmd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VacuumPump_FB_PMS_VacuumPump_FB;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VacuumSystemsta_PMS_VacuumSystemsta;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VehicleSpeed_PMS_VehicleSpeed;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VehicleSysErrorLevel_PMS_VehicleSysErrorLevel;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VehicleSysErrorLevelG_PMS_VehicleSysErrorLevelG;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VehicleSysErrorLevelG1_PMS_PMS_VehicleSysErrorLevelG1_PMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VersionConversionFlag_PMS_VersionConversionFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VersionConversionRxSts_PMS_VersionConversionRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Wakeup_reasons_PMS_Wakeup_reasons;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTFault_PMS_ePTFault;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTFault2_PMS_ePTFault2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTModeActual_PMS_ePTModeActual;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTModeSelect_PMS_ePTModeSelect;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTReady_PMS_ePTReady;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTReleaseSig_PMS_ePTReleaseSig;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_TBOX_ChrgSoftSwCtrlst_EV_TBOX_ChrgSoftSwCtrlst_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_TBOX_ReservationChrgnSts_EV_TBOX_ReservationChrgnSts_EV;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_VCU_ActInputVolt_VCU_ActInputVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_Ctrl_CheckSum_VCU_BMSH_Ctrl_CheckSum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_DCChgRelayVolt_VCU_BMSH_DCChgRelayVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_ChargeDepthReq_VCU_ChargeDepthReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_CrashOutputSts_VCU_CrashOutputSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_DCInputCurrent_VCU_DCInputCurrent;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_VCU_Odometerbackup_VCU_Odometerbackup;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_VehicleInfo_CheckSum_VCU_VehicleInfo_CheckSum;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_ts_App1_Task_10ms_Core1_QM, RTE_VAR_NOINIT) Rte_App1_Task_10ms_Core1_QM;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Buffers for inter-runnable variables
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    RTE Helper-Functions prototypes
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*
************************************************************************************************************************
*    API prototypes
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_Switch_<p>_<m>
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Rte_Invalidate_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_IRead_<r>_<p>_<d>
*    Rte_IStatus_<r>_<p>_<d>
*    Rte_IWrite_<r>_<p>_<d>
*    Rte_IWriteRef_<r>_<p>_<d>
*    Rte_IInvalidate_<r>_<p>_<d>
************************************************************************************************************************
*/
#define Rte_IWrite_swc_VCOP_Step_AC_EWP_Heat_AC_EWP_Heat(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_Heat_AC_EWP_Heat.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_AC_EWP_Heat_AC_EWP_Heat() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_Heat_AC_EWP_Heat.value \
)

#define Rte_IWrite_swc_VCOP_Step_AC_EWP_Heat_LIN_AC_EWP_Heat_LIN(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_Heat_LIN_AC_EWP_Heat_LIN.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_AC_EWP_Heat_LIN_AC_EWP_Heat_LIN() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_Heat_LIN_AC_EWP_Heat_LIN.value \
)

#define Rte_IWrite_swc_VCOP_Step_AC_EWP_HeatrPwrCnsAllwd_AC_EWP_HeatrPwrCnsAllwd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_HeatrPwrCnsAllwd_AC_EWP_HeatrPwrCnsAllwd.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_AC_EWP_HeatrPwrCnsAllwd_AC_EWP_HeatrPwrCnsAllwd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_HeatrPwrCnsAllwd_AC_EWP_HeatrPwrCnsAllwd.value \
)

#define Rte_IWrite_swc_VCOP_Step_AC_EWP_HeatrPwrCnsAllwd_LIN_AC_EWP_HeatrPwrCnsAllwd_LIN(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_HeatrPwrCnsAllwd_LIN_AC_EWP_HeatrPwrCnsAllwd_LIN.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_AC_EWP_HeatrPwrCnsAllwd_LIN_AC_EWP_HeatrPwrCnsAllwd_LIN() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_HeatrPwrCnsAllwd_LIN_AC_EWP_HeatrPwrCnsAllwd_LIN.value \
)

#define Rte_IWrite_swc_VCOP_Step_AC_EWP_Run_AC_EWP_Run(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_Run_AC_EWP_Run.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_AC_EWP_Run_AC_EWP_Run() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_Run_AC_EWP_Run.value \
)

#define Rte_IWrite_swc_VCOP_Step_AC_EWP_Run_LIN_AC_EWP_Run_LIN(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_Run_LIN_AC_EWP_Run_LIN.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_AC_EWP_Run_LIN_AC_EWP_Run_LIN() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_Run_LIN_AC_EWP_Run_LIN.value \
)

#define Rte_IWrite_swc_VCOP_Step_AC_EWP_SpeedReq_AC_EWP_SpeedReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_SpeedReq_AC_EWP_SpeedReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_AC_EWP_SpeedReq_AC_EWP_SpeedReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_SpeedReq_AC_EWP_SpeedReq.value \
)

#define Rte_IWrite_swc_VCOP_Step_AC_EWP_SpeedReq_LIN_AC_EWP_SpeedReq_LIN(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_SpeedReq_LIN_AC_EWP_SpeedReq_LIN.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_AC_EWP_SpeedReq_LIN_AC_EWP_SpeedReq_LIN() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_SpeedReq_LIN_AC_EWP_SpeedReq_LIN.value \
)

#define Rte_IWrite_swc_VCOP_Step_AC_EWP_Temp_AC_EWP_Temp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_Temp_AC_EWP_Temp.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_AC_EWP_Temp_AC_EWP_Temp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_Temp_AC_EWP_Temp.value \
)

#define Rte_IWrite_swc_VCOP_Step_AC_EWP_Temp_LIN_AC_EWP_Temp_LIN(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_Temp_LIN_AC_EWP_Temp_LIN.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_AC_EWP_Temp_LIN_AC_EWP_Temp_LIN() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_AC_EWP_Temp_LIN_AC_EWP_Temp_LIN.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_ACChgTimeRemain_BMSH_ACChgTimeRemain(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_ACChgTimeRemain_BMSH_ACChgTimeRemain.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_ACChgTimeRemain_BMSH_ACChgTimeRemain() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_ACChgTimeRemain_BMSH_ACChgTimeRemain.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_BattCurr_BMSH_BattCurr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattCurr_BMSH_BattCurr.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_BattCurr_BMSH_BattCurr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattCurr_BMSH_BattCurr.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_BattFaultLampState_BMSH_BattFaultLampState(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattFaultLampState_BMSH_BattFaultLampState.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_BattFaultLampState_BMSH_BattFaultLampState() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattFaultLampState_BMSH_BattFaultLampState.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_BattPackNum_PMS_BMSH_BattPackNum_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattPackNum_PMS_BMSH_BattPackNum_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_BattPackNum_PMS_BMSH_BattPackNum_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattPackNum_PMS_BMSH_BattPackNum_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_BattRemainEnergy_BMSH_BattRemainEnergy(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattRemainEnergy_BMSH_BattRemainEnergy.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_BattRemainEnergy_BMSH_BattRemainEnergy() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattRemainEnergy_BMSH_BattRemainEnergy.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_BattSOC_BMSH_BattSOC(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattSOC_BMSH_BattSOC.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_BattSOC_BMSH_BattSOC() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattSOC_BMSH_BattSOC.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_BattSOH_BMSH_BattSOH(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattSOH_BMSH_BattSOH.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_BattSOH_BMSH_BattSOH() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattSOH_BMSH_BattSOH.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_BattSysNum_PMS_BMSH_BattSysNum_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattSysNum_PMS_BMSH_BattSysNum_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_BattSysNum_PMS_BMSH_BattSysNum_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattSysNum_PMS_BMSH_BattSysNum_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_BattTempAvg_PT_BMSH_BattTempAvg_PT(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattTempAvg_PT_BMSH_BattTempAvg_PT.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_BattTempAvg_PT_BMSH_BattTempAvg_PT() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattTempAvg_PT_BMSH_BattTempAvg_PT.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_BattVolt_BMSH_BattVolt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattVolt_BMSH_BattVolt.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_BattVolt_BMSH_BattVolt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_BattVolt_BMSH_BattVolt.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_Battery_Performance_Checksum_BMSH_Battery_Performance_Checksum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Battery_Performance_Checksum_BMSH_Battery_Performance_Checksum.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_Battery_Performance_Checksum_BMSH_Battery_Performance_Checksum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Battery_Performance_Checksum_BMSH_Battery_Performance_Checksum.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_CellTemp_Uniformity_BMSH_CellTemp_Uniformity(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_CellTemp_Uniformity_BMSH_CellTemp_Uniformity.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_CellTemp_Uniformity_BMSH_CellTemp_Uniformity() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_CellTemp_Uniformity_BMSH_CellTemp_Uniformity.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_CellVolt_Uniformity_BMSH_CellVolt_Uniformity(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_CellVolt_Uniformity_BMSH_CellVolt_Uniformity.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_CellVolt_Uniformity_BMSH_CellVolt_Uniformity() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_CellVolt_Uniformity_BMSH_CellVolt_Uniformity.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_Cell_OverVol_BMSH_Cell_OverVol(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Cell_OverVol_BMSH_Cell_OverVol.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_Cell_OverVol_BMSH_Cell_OverVol() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Cell_OverVol_BMSH_Cell_OverVol.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_Cell_TotalNum_BMSH_Cell_TotalNum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Cell_TotalNum_BMSH_Cell_TotalNum.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_Cell_TotalNum_BMSH_Cell_TotalNum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Cell_TotalNum_BMSH_Cell_TotalNum.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_Cell_UnderVol_BMSH_Cell_UnderVol(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Cell_UnderVol_BMSH_Cell_UnderVol.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_Cell_UnderVol_BMSH_Cell_UnderVol() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Cell_UnderVol_BMSH_Cell_UnderVol.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_ChargeLEDCtrl_BMSH_ChargeLEDCtrl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_ChargeLEDCtrl_BMSH_ChargeLEDCtrl.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_ChargeLEDCtrl_BMSH_ChargeLEDCtrl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_ChargeLEDCtrl_BMSH_ChargeLEDCtrl.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_ChargeToBeFinished_BMSH_ChargeToBeFinished(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_ChargeToBeFinished_BMSH_ChargeToBeFinished.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_ChargeToBeFinished_BMSH_ChargeToBeFinished() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_ChargeToBeFinished_BMSH_ChargeToBeFinished.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_Charge_Over_Current_BMSH_Charge_Over_Current(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Charge_Over_Current_BMSH_Charge_Over_Current.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_Charge_Over_Current_BMSH_Charge_Over_Current() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Charge_Over_Current_BMSH_Charge_Over_Current.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_ChgTimeRemain_BMSH_ChgTimeRemain(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_ChgTimeRemain_BMSH_ChgTimeRemain.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_ChgTimeRemain_BMSH_ChgTimeRemain() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_ChgTimeRemain_BMSH_ChgTimeRemain.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_DCChgminusSocketTempSensing_Failure_BMSH_DCChgminusSocketTempSensing_Failure(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_DCChgminusSocketTempSensing_Failure_BMSH_DCChgminusSocketTempSensing_Failure.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_DCChgminusSocketTempSensing_Failure_BMSH_DCChgminusSocketTempSensing_Failure() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_DCChgminusSocketTempSensing_Failure_BMSH_DCChgminusSocketTempSensing_Failure.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_DCChgplusSocketTempSensing_Failure_BMSH_DCChgplusSocketTempSensing_Failure(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_DCChgplusSocketTempSensing_Failure_BMSH_DCChgplusSocketTempSensing_Failure.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_DCChgplusSocketTempSensing_Failure_BMSH_DCChgplusSocketTempSensing_Failure() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_DCChgplusSocketTempSensing_Failure_BMSH_DCChgplusSocketTempSensing_Failure.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_FastChgCC2ConntState_BMSH_FastChgCC2ConntState(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_FastChgCC2ConntState_BMSH_FastChgCC2ConntState.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_FastChgCC2ConntState_BMSH_FastChgCC2ConntState() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_FastChgCC2ConntState_BMSH_FastChgCC2ConntState.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_HVBusVolt_BMSH_HVBusVolt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_HVBusVolt_BMSH_HVBusVolt.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_HVBusVolt_BMSH_HVBusVolt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_HVBusVolt_BMSH_HVBusVolt.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_HvBattCooltTReq_BMSH_HvBattCooltTReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_HvBattCooltTReq_BMSH_HvBattCooltTReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_HvBattCooltTReq_BMSH_HvBattCooltTReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_HvBattCooltTReq_BMSH_HvBattCooltTReq.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_HvBattThermMod_BMSH_HvBattThermMod(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_HvBattThermMod_BMSH_HvBattThermMod.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_HvBattThermMod_BMSH_HvBattThermMod() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_HvBattThermMod_BMSH_HvBattThermMod.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_HvShutdownReq_BMSH_HvShutdownReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_HvShutdownReq_BMSH_HvShutdownReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_HvShutdownReq_BMSH_HvShutdownReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_HvShutdownReq_BMSH_HvShutdownReq.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_ICU_BatteryElectricDTE_BMSH_ICU_BatteryElectricDTE(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_ICU_BatteryElectricDTE_BMSH_ICU_BatteryElectricDTE.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_ICU_BatteryElectricDTE_BMSH_ICU_BatteryElectricDTE() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_ICU_BatteryElectricDTE_BMSH_ICU_BatteryElectricDTE.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_Inlet_WaterTemp_BMSH_Inlet_WaterTemp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Inlet_WaterTemp_BMSH_Inlet_WaterTemp.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_Inlet_WaterTemp_BMSH_Inlet_WaterTemp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Inlet_WaterTemp_BMSH_Inlet_WaterTemp.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_InsulationRes_BMSH_InsulationRes(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_InsulationRes_BMSH_InsulationRes.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_InsulationRes_BMSH_InsulationRes() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_InsulationRes_BMSH_InsulationRes.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_InsulationRes_Fault_BMSH_InsulationRes_Fault(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_InsulationRes_Fault_BMSH_InsulationRes_Fault.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_InsulationRes_Fault_BMSH_InsulationRes_Fault() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_InsulationRes_Fault_BMSH_InsulationRes_Fault.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_Low_SOC_BMSH_Low_SOC(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Low_SOC_BMSH_Low_SOC.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_Low_SOC_BMSH_Low_SOC() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Low_SOC_BMSH_Low_SOC.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_Outlet_WaterTemp_BMSH_Outlet_WaterTemp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Outlet_WaterTemp_BMSH_Outlet_WaterTemp.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_Outlet_WaterTemp_BMSH_Outlet_WaterTemp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Outlet_WaterTemp_BMSH_Outlet_WaterTemp.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_Over_SOC_BMSH_Over_SOC(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Over_SOC_BMSH_Over_SOC.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_Over_SOC_BMSH_Over_SOC() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Over_SOC_BMSH_Over_SOC.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_Over_Temperature_BMSH_Over_Temperature(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Over_Temperature_BMSH_Over_Temperature.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_Over_Temperature_BMSH_Over_Temperature() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Over_Temperature_BMSH_Over_Temperature.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_Pack_OverVoltage_BMSH_Pack_OverVoltage(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Pack_OverVoltage_BMSH_Pack_OverVoltage.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_Pack_OverVoltage_BMSH_Pack_OverVoltage() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Pack_OverVoltage_BMSH_Pack_OverVoltage.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_Pack_UnderVoltage_BMSH_Pack_UnderVoltage(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Pack_UnderVoltage_BMSH_Pack_UnderVoltage.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_Pack_UnderVoltage_BMSH_Pack_UnderVoltage() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Pack_UnderVoltage_BMSH_Pack_UnderVoltage.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_SOC_Hop_BMSH_SOC_Hop(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_SOC_Hop_BMSH_SOC_Hop.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_SOC_Hop_BMSH_SOC_Hop() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_SOC_Hop_BMSH_SOC_Hop.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatIsoAlarm2_PT_BMSH_TBOX_BatIsoAlarm2_PT(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatIsoAlarm2_PT_BMSH_TBOX_BatIsoAlarm2_PT.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_BatIsoAlarm2_PT_BMSH_TBOX_BatIsoAlarm2_PT() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatIsoAlarm2_PT_BMSH_TBOX_BatIsoAlarm2_PT.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatIsoAlarm3_PMS_BMSH_TBOX_BatIsoAlarm3_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatIsoAlarm3_PMS_BMSH_TBOX_BatIsoAlarm3_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_BatIsoAlarm3_PMS_BMSH_TBOX_BatIsoAlarm3_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatIsoAlarm3_PMS_BMSH_TBOX_BatIsoAlarm3_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatLowSOC2_PT_BMSH_TBOX_BatLowSOC2_PT(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatLowSOC2_PT_BMSH_TBOX_BatLowSOC2_PT.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_BatLowSOC2_PT_BMSH_TBOX_BatLowSOC2_PT() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatLowSOC2_PT_BMSH_TBOX_BatLowSOC2_PT.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatLowSOC3_PMS_BMSH_TBOX_BatLowSOC3_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatLowSOC3_PMS_BMSH_TBOX_BatLowSOC3_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_BatLowSOC3_PMS_BMSH_TBOX_BatLowSOC3_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatLowSOC3_PMS_BMSH_TBOX_BatLowSOC3_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatOverCharge2_PT_BMSH_TBOX_BatOverCharge2_PT(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverCharge2_PT_BMSH_TBOX_BatOverCharge2_PT.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_BatOverCharge2_PT_BMSH_TBOX_BatOverCharge2_PT() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverCharge2_PT_BMSH_TBOX_BatOverCharge2_PT.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatOverCharge3_PMS_BMSH_TBOX_BatOverCharge3_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverCharge3_PMS_BMSH_TBOX_BatOverCharge3_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_BatOverCharge3_PMS_BMSH_TBOX_BatOverCharge3_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverCharge3_PMS_BMSH_TBOX_BatOverCharge3_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatOverSOC2_PT_BMSH_TBOX_BatOverSOC2_PT(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverSOC2_PT_BMSH_TBOX_BatOverSOC2_PT.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_BatOverSOC2_PT_BMSH_TBOX_BatOverSOC2_PT() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverSOC2_PT_BMSH_TBOX_BatOverSOC2_PT.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatOverSOC3_PMS_BMSH_TBOX_BatOverSOC3_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverSOC3_PMS_BMSH_TBOX_BatOverSOC3_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_BatOverSOC3_PMS_BMSH_TBOX_BatOverSOC3_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverSOC3_PMS_BMSH_TBOX_BatOverSOC3_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatOverTemp2_PT_BMSH_TBOX_BatOverTemp2_PT(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverTemp2_PT_BMSH_TBOX_BatOverTemp2_PT.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_BatOverTemp2_PT_BMSH_TBOX_BatOverTemp2_PT() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverTemp2_PT_BMSH_TBOX_BatOverTemp2_PT.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatOverTemp3_PMS_BMSH_TBOX_BatOverTemp3_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverTemp3_PMS_BMSH_TBOX_BatOverTemp3_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_BatOverTemp3_PMS_BMSH_TBOX_BatOverTemp3_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverTemp3_PMS_BMSH_TBOX_BatOverTemp3_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatOverVoltage2_PT_BMSH_TBOX_BatOverVoltage2_PT(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverVoltage2_PT_BMSH_TBOX_BatOverVoltage2_PT.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_BatOverVoltage2_PT_BMSH_TBOX_BatOverVoltage2_PT() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverVoltage2_PT_BMSH_TBOX_BatOverVoltage2_PT.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatOverVoltage3_PMS_BMSH_TBOX_BatOverVoltage3_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverVoltage3_PMS_BMSH_TBOX_BatOverVoltage3_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_BatOverVoltage3_PMS_BMSH_TBOX_BatOverVoltage3_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatOverVoltage3_PMS_BMSH_TBOX_BatOverVoltage3_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatTempUniformity2_PT_BMSH_TBOX_BatTempUniformity2_PT(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatTempUniformity2_PT_BMSH_TBOX_BatTempUniformity2_PT.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_BatTempUniformity2_PT_BMSH_TBOX_BatTempUniformity2_PT() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatTempUniformity2_PT_BMSH_TBOX_BatTempUniformity2_PT.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatTempUniformity3_PMS_BMSH_TBOX_BatTempUniformity3_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatTempUniformity3_PMS_BMSH_TBOX_BatTempUniformity3_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_BatTempUniformity3_PMS_BMSH_TBOX_BatTempUniformity3_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatTempUniformity3_PMS_BMSH_TBOX_BatTempUniformity3_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatUnderVoltage2_PT_BMSH_TBOX_BatUnderVoltage2_PT(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatUnderVoltage2_PT_BMSH_TBOX_BatUnderVoltage2_PT.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_BatUnderVoltage2_PT_BMSH_TBOX_BatUnderVoltage2_PT() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatUnderVoltage2_PT_BMSH_TBOX_BatUnderVoltage2_PT.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatUnderVoltage3_PMS_BMSH_TBOX_BatUnderVoltage3_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatUnderVoltage3_PMS_BMSH_TBOX_BatUnderVoltage3_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_BatUnderVoltage3_PMS_BMSH_TBOX_BatUnderVoltage3_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatUnderVoltage3_PMS_BMSH_TBOX_BatUnderVoltage3_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatUniformity2_PT_BMSH_TBOX_BatUniformity2_PT(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatUniformity2_PT_BMSH_TBOX_BatUniformity2_PT.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_BatUniformity2_PT_BMSH_TBOX_BatUniformity2_PT() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatUniformity2_PT_BMSH_TBOX_BatUniformity2_PT.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatUniformity3_PMS_BMSH_TBOX_BatUniformity3_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatUniformity3_PMS_BMSH_TBOX_BatUniformity3_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_BatUniformity3_PMS_BMSH_TBOX_BatUniformity3_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_BatUniformity3_PMS_BMSH_TBOX_BatUniformity3_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_CellOverVoltage2_PT_BMSH_TBOX_CellOverVoltage2_PT(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_CellOverVoltage2_PT_BMSH_TBOX_CellOverVoltage2_PT.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_CellOverVoltage2_PT_BMSH_TBOX_CellOverVoltage2_PT() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_CellOverVoltage2_PT_BMSH_TBOX_CellOverVoltage2_PT.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_CellOverVoltage3_PMS_BMSH_TBOX_CellOverVoltage3_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_CellOverVoltage3_PMS_BMSH_TBOX_CellOverVoltage3_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_CellOverVoltage3_PMS_BMSH_TBOX_CellOverVoltage3_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_CellOverVoltage3_PMS_BMSH_TBOX_CellOverVoltage3_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_CellUnderVoltage2_PT_BMSH_TBOX_CellUnderVoltage2_PT(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_CellUnderVoltage2_PT_BMSH_TBOX_CellUnderVoltage2_PT.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_CellUnderVoltage2_PT_BMSH_TBOX_CellUnderVoltage2_PT() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_CellUnderVoltage2_PT_BMSH_TBOX_CellUnderVoltage2_PT.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_CellUnderVoltage3_PMS_BMSH_TBOX_CellUnderVoltage3_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_CellUnderVoltage3_PMS_BMSH_TBOX_CellUnderVoltage3_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_CellUnderVoltage3_PMS_BMSH_TBOX_CellUnderVoltage3_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_CellUnderVoltage3_PMS_BMSH_TBOX_CellUnderVoltage3_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_FireAlarm2_PMS_BMSH_TBOX_FireAlarm2_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_FireAlarm2_PMS_BMSH_TBOX_FireAlarm2_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_FireAlarm2_PMS_BMSH_TBOX_FireAlarm2_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_FireAlarm2_PMS_BMSH_TBOX_FireAlarm2_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_SOCHop2_PT_BMSH_TBOX_SOCHop2_PT(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_SOCHop2_PT_BMSH_TBOX_SOCHop2_PT.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_SOCHop2_PT_BMSH_TBOX_SOCHop2_PT() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_SOCHop2_PT_BMSH_TBOX_SOCHop2_PT.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_SOCHop3_PMS_BMSH_TBOX_SOCHop3_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_SOCHop3_PMS_BMSH_TBOX_SOCHop3_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TBOX_SOCHop3_PMS_BMSH_TBOX_SOCHop3_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TBOX_SOCHop3_PMS_BMSH_TBOX_SOCHop3_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TempSensor_MaxTemp_BMSH_TempSensor_MaxTemp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TempSensor_MaxTemp_BMSH_TempSensor_MaxTemp.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TempSensor_MaxTemp_BMSH_TempSensor_MaxTemp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TempSensor_MaxTemp_BMSH_TempSensor_MaxTemp.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TempSensor_MinTemp_BMSH_TempSensor_MinTemp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TempSensor_MinTemp_BMSH_TempSensor_MinTemp.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TempSensor_MinTemp_BMSH_TempSensor_MinTemp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TempSensor_MinTemp_BMSH_TempSensor_MinTemp.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_TempSensor_TotalNum_BMSH_TempSensor_TotalNum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TempSensor_TotalNum_BMSH_TempSensor_TotalNum.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_TempSensor_TotalNum_BMSH_TempSensor_TotalNum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_TempSensor_TotalNum_BMSH_TempSensor_TotalNum.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_ThermalOutofControl_BMSH_ThermalOutofControl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_ThermalOutofControl_BMSH_ThermalOutofControl.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_ThermalOutofControl_BMSH_ThermalOutofControl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_ThermalOutofControl_BMSH_ThermalOutofControl.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_Vehicle_HVILSts_PHEV_BMSH_Vehicle_HVILSts_PHEV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Vehicle_HVILSts_PHEV_BMSH_Vehicle_HVILSts_PHEV.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_Vehicle_HVILSts_PHEV_BMSH_Vehicle_HVILSts_PHEV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_Vehicle_HVILSts_PHEV_BMSH_Vehicle_HVILSts_PHEV.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_VoltCurr_Checksum_BMSH_VoltCurr_Checksum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_VoltCurr_Checksum_BMSH_VoltCurr_Checksum.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_VoltCurr_Checksum_BMSH_VoltCurr_Checksum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_VoltCurr_Checksum_BMSH_VoltCurr_Checksum.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMSH_stMode_BMSH_stMode(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_stMode_BMSH_stMode.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMSH_stMode_BMSH_stMode() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMSH_stMode_BMSH_stMode.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMS_BattPackMatchFault_BMS_BattPackMatchFault(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_BattPackMatchFault_BMS_BattPackMatchFault.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMS_BattPackMatchFault_BMS_BattPackMatchFault() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_BattPackMatchFault_BMS_BattPackMatchFault.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMS_BattPackMatchFault1_PMS_BMS_BattPackMatchFault1_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_BattPackMatchFault1_PMS_BMS_BattPackMatchFault1_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMS_BattPackMatchFault1_PMS_BMS_BattPackMatchFault1_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_BattPackMatchFault1_PMS_BMS_BattPackMatchFault1_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMS_MaxCellVolt_BMS_MaxCellVolt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_MaxCellVolt_BMS_MaxCellVolt.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMS_MaxCellVolt_BMS_MaxCellVolt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_MaxCellVolt_BMS_MaxCellVolt.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMS_MaxTemp1SnsNum_BMS_MaxTemp1SnsNum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_MaxTemp1SnsNum_BMS_MaxTemp1SnsNum.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMS_MaxTemp1SnsNum_BMS_MaxTemp1SnsNum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_MaxTemp1SnsNum_BMS_MaxTemp1SnsNum.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMS_MaxVoltCellNum_BMS_MaxVoltCellNum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_MaxVoltCellNum_BMS_MaxVoltCellNum.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMS_MaxVoltCellNum_BMS_MaxVoltCellNum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_MaxVoltCellNum_BMS_MaxVoltCellNum.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMS_MinCellVolt_BMS_MinCellVolt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_MinCellVolt_BMS_MinCellVolt.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMS_MinCellVolt_BMS_MinCellVolt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_MinCellVolt_BMS_MinCellVolt.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMS_MinVoltCellNum_BMS_MinVoltCellNum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_MinVoltCellNum_BMS_MinVoltCellNum.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMS_MinVoltCellNum_BMS_MinVoltCellNum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_MinVoltCellNum_BMS_MinVoltCellNum.value \
)

#define Rte_IWrite_swc_VCOP_Step_BMS_MinxTemp1SnsNum_BMS_MinxTemp1SnsNum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_MinxTemp1SnsNum_BMS_MinxTemp1SnsNum.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_BMS_MinxTemp1SnsNum_BMS_MinxTemp1SnsNum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_BMS_MinxTemp1SnsNum_BMS_MinxTemp1SnsNum.value \
)

#define Rte_IWrite_swc_VCOP_Step_DrvPfmncRedn_DrvPfmncRedn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_DrvPfmncRedn_DrvPfmncRedn.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_DrvPfmncRedn_DrvPfmncRedn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_DrvPfmncRedn_DrvPfmncRedn.value \
)

#define Rte_IWrite_swc_VCOP_Step_EDCP_Flt_EDCP_Flt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EDCP_Flt_EDCP_Flt.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EDCP_Flt_EDCP_Flt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EDCP_Flt_EDCP_Flt.value \
)

#define Rte_IWrite_swc_VCOP_Step_EDCP_PWMFB_EDCP_PWMFB(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EDCP_PWMFB_EDCP_PWMFB.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EDCP_PWMFB_EDCP_PWMFB() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EDCP_PWMFB_EDCP_PWMFB.value \
)

#define Rte_IWrite_swc_VCOP_Step_EXT_DO_KEY_HS_03_EXT_DO_KEY_HS_03(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_KEY_HS_03_EXT_DO_KEY_HS_03.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EXT_DO_KEY_HS_03_EXT_DO_KEY_HS_03() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_KEY_HS_03_EXT_DO_KEY_HS_03.value \
)

#define Rte_IWrite_swc_VCOP_Step_EXT_DO_KEY_HS_05_EXT_DO_KEY_HS_05(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_KEY_HS_05_EXT_DO_KEY_HS_05.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EXT_DO_KEY_HS_05_EXT_DO_KEY_HS_05() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_KEY_HS_05_EXT_DO_KEY_HS_05.value \
)

#define Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_HS_11_EXT_DO_RELAY_HS_11(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_HS_11_EXT_DO_RELAY_HS_11.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EXT_DO_RELAY_HS_11_EXT_DO_RELAY_HS_11() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_HS_11_EXT_DO_RELAY_HS_11.value \
)

#define Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_HS_6_EXT_DO_RELAY_HS_6(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_HS_6_EXT_DO_RELAY_HS_6.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EXT_DO_RELAY_HS_6_EXT_DO_RELAY_HS_6() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_HS_6_EXT_DO_RELAY_HS_6.value \
)

#define Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_HS_8_EXT_DO_RELAY_HS_8(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_HS_8_EXT_DO_RELAY_HS_8.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EXT_DO_RELAY_HS_8_EXT_DO_RELAY_HS_8() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_HS_8_EXT_DO_RELAY_HS_8.value \
)

#define Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_HS_9_EXT_DO_RELAY_HS_9(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_HS_9_EXT_DO_RELAY_HS_9.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EXT_DO_RELAY_HS_9_EXT_DO_RELAY_HS_9() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_HS_9_EXT_DO_RELAY_HS_9.value \
)

#define Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_LS_10_EXT_DO_RELAY_LS_10(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_LS_10_EXT_DO_RELAY_LS_10.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EXT_DO_RELAY_LS_10_EXT_DO_RELAY_LS_10() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_LS_10_EXT_DO_RELAY_LS_10.value \
)

#define Rte_IRead_swc_VCOP_Step_EXT_DO_RELAY_LS_10_Fb_EXT_DO_RELAY_LS_10_Fb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_LS_10_Fb_EXT_DO_RELAY_LS_10_Fb.value)

#define Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_LS_12_EXT_DO_RELAY_LS_12(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_LS_12_EXT_DO_RELAY_LS_12.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EXT_DO_RELAY_LS_12_EXT_DO_RELAY_LS_12() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_LS_12_EXT_DO_RELAY_LS_12.value \
)

#define Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_LS_5_EXT_DO_RELAY_LS_5(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_LS_5_EXT_DO_RELAY_LS_5.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EXT_DO_RELAY_LS_5_EXT_DO_RELAY_LS_5() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_LS_5_EXT_DO_RELAY_LS_5.value \
)

#define Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_LS_7_EXT_DO_RELAY_LS_7(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_LS_7_EXT_DO_RELAY_LS_7.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EXT_DO_RELAY_LS_7_EXT_DO_RELAY_LS_7() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_LS_7_EXT_DO_RELAY_LS_7.value \
)

#define Rte_IRead_swc_VCOP_Step_EXT_DO_RELAY_LS_7_Fb_EXT_DO_RELAY_LS_7_Fb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_LS_7_Fb_EXT_DO_RELAY_LS_7_Fb.value)

#define Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_LS_9_EXT_DO_RELAY_LS_9(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_LS_9_EXT_DO_RELAY_LS_9.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EXT_DO_RELAY_LS_9_EXT_DO_RELAY_LS_9() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_LS_9_EXT_DO_RELAY_LS_9.value \
)

#define Rte_IRead_swc_VCOP_Step_EXT_DO_RELAY_LS_9_Fb_EXT_DO_RELAY_LS_9_Fb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_DO_RELAY_LS_9_Fb_EXT_DO_RELAY_LS_9_Fb.value)

#define Rte_IWrite_swc_VCOP_Step_EXT_PO_HVIL_1_DutyCycle_EXT_PO_HVIL_1_DutyCycle(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_HVIL_1_DutyCycle_EXT_PO_HVIL_1_DutyCycle.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EXT_PO_HVIL_1_DutyCycle_EXT_PO_HVIL_1_DutyCycle() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_HVIL_1_DutyCycle_EXT_PO_HVIL_1_DutyCycle.value \
)

#define Rte_IWrite_swc_VCOP_Step_EXT_PO_HVIL_1_Period_EXT_PO_HVIL_1_Period(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_HVIL_1_Period_EXT_PO_HVIL_1_Period.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EXT_PO_HVIL_1_Period_EXT_PO_HVIL_1_Period() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_HVIL_1_Period_EXT_PO_HVIL_1_Period.value \
)

#define Rte_IWrite_swc_VCOP_Step_EXT_PO_HVIL_2_DutyCycle_EXT_PO_HVIL_2_DutyCycle(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_HVIL_2_DutyCycle_EXT_PO_HVIL_2_DutyCycle.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EXT_PO_HVIL_2_DutyCycle_EXT_PO_HVIL_2_DutyCycle() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_HVIL_2_DutyCycle_EXT_PO_HVIL_2_DutyCycle.value \
)

#define Rte_IWrite_swc_VCOP_Step_EXT_PO_HVIL_2_Period_EXT_PO_HVIL_2_Period(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_HVIL_2_Period_EXT_PO_HVIL_2_Period.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EXT_PO_HVIL_2_Period_EXT_PO_HVIL_2_Period() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_HVIL_2_Period_EXT_PO_HVIL_2_Period.value \
)

#define Rte_IWrite_swc_VCOP_Step_EXT_PO_PWM_1_DutyCycle_EXT_PO_PWM_1_DutyCycle(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_PWM_1_DutyCycle_EXT_PO_PWM_1_DutyCycle.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EXT_PO_PWM_1_DutyCycle_EXT_PO_PWM_1_DutyCycle() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_PWM_1_DutyCycle_EXT_PO_PWM_1_DutyCycle.value \
)

#define Rte_IWrite_swc_VCOP_Step_EXT_PO_PWM_1_Period_EXT_PO_PWM_1_Period(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_PWM_1_Period_EXT_PO_PWM_1_Period.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EXT_PO_PWM_1_Period_EXT_PO_PWM_1_Period() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_PWM_1_Period_EXT_PO_PWM_1_Period.value \
)

#define Rte_IWrite_swc_VCOP_Step_EXT_PO_PWM_2_DutyCycle_EXT_PO_PWM_2_DutyCycle(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_PWM_2_DutyCycle_EXT_PO_PWM_2_DutyCycle.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EXT_PO_PWM_2_DutyCycle_EXT_PO_PWM_2_DutyCycle() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_PWM_2_DutyCycle_EXT_PO_PWM_2_DutyCycle.value \
)

#define Rte_IWrite_swc_VCOP_Step_EXT_PO_PWM_2_Period_EXT_PO_PWM_2_Period(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_PWM_2_Period_EXT_PO_PWM_2_Period.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EXT_PO_PWM_2_Period_EXT_PO_PWM_2_Period() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_PWM_2_Period_EXT_PO_PWM_2_Period.value \
)

#define Rte_IWrite_swc_VCOP_Step_EXT_PO_PWM_4_DutyCycle_EXT_PO_PWM_4_DutyCycle(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_PWM_4_DutyCycle_EXT_PO_PWM_4_DutyCycle.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EXT_PO_PWM_4_DutyCycle_EXT_PO_PWM_4_DutyCycle() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_PWM_4_DutyCycle_EXT_PO_PWM_4_DutyCycle.value \
)

#define Rte_IWrite_swc_VCOP_Step_EXT_PO_PWM_4_Period_EXT_PO_PWM_4_Period(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_PWM_4_Period_EXT_PO_PWM_4_Period.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_EXT_PO_PWM_4_Period_EXT_PO_PWM_4_Period() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_EXT_PO_PWM_4_Period_EXT_PO_PWM_4_Period.value \
)

#define Rte_IRead_swc_VCOP_Step_F190_VIN_Byte0_F190_VIN_Byte0() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte0_F190_VIN_Byte0.value)

#define Rte_IRead_swc_VCOP_Step_F190_VIN_Byte1_F190_VIN_Byte1() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte1_F190_VIN_Byte1.value)

#define Rte_IRead_swc_VCOP_Step_F190_VIN_Byte10_F190_VIN_Byte10() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte10_F190_VIN_Byte10.value)

#define Rte_IRead_swc_VCOP_Step_F190_VIN_Byte11_F190_VIN_Byte11() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte11_F190_VIN_Byte11.value)

#define Rte_IRead_swc_VCOP_Step_F190_VIN_Byte12_F190_VIN_Byte12() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte12_F190_VIN_Byte12.value)

#define Rte_IRead_swc_VCOP_Step_F190_VIN_Byte13_F190_VIN_Byte13() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte13_F190_VIN_Byte13.value)

#define Rte_IRead_swc_VCOP_Step_F190_VIN_Byte14_F190_VIN_Byte14() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte14_F190_VIN_Byte14.value)

#define Rte_IRead_swc_VCOP_Step_F190_VIN_Byte15_F190_VIN_Byte15() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte15_F190_VIN_Byte15.value)

#define Rte_IRead_swc_VCOP_Step_F190_VIN_Byte16_F190_VIN_Byte16() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte16_F190_VIN_Byte16.value)

#define Rte_IRead_swc_VCOP_Step_F190_VIN_Byte2_F190_VIN_Byte2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte2_F190_VIN_Byte2.value)

#define Rte_IRead_swc_VCOP_Step_F190_VIN_Byte3_F190_VIN_Byte3() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte3_F190_VIN_Byte3.value)

#define Rte_IRead_swc_VCOP_Step_F190_VIN_Byte4_F190_VIN_Byte4() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte4_F190_VIN_Byte4.value)

#define Rte_IRead_swc_VCOP_Step_F190_VIN_Byte5_F190_VIN_Byte5() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte5_F190_VIN_Byte5.value)

#define Rte_IRead_swc_VCOP_Step_F190_VIN_Byte6_F190_VIN_Byte6() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte6_F190_VIN_Byte6.value)

#define Rte_IRead_swc_VCOP_Step_F190_VIN_Byte7_F190_VIN_Byte7() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte7_F190_VIN_Byte7.value)

#define Rte_IRead_swc_VCOP_Step_F190_VIN_Byte8_F190_VIN_Byte8() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte8_F190_VIN_Byte8.value)

#define Rte_IRead_swc_VCOP_Step_F190_VIN_Byte9_F190_VIN_Byte9() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F190_VIN_Byte9_F190_VIN_Byte9.value)

#define Rte_IRead_swc_VCOP_Step_F193_ECUHardwareVersionNumber_Byte2_F193_ECUHardwareVersionNumber_Byte2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F193_ECUHardwareVersionNumber_Byte2_F193_ECUHardwareVersionNumber_Byte2.value)

#define Rte_IRead_swc_VCOP_Step_F193_ECUHardwareVersionNumber_Byte3_F193_ECUHardwareVersionNumber_Byte3() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F193_ECUHardwareVersionNumber_Byte3_F193_ECUHardwareVersionNumber_Byte3.value)

#define Rte_IRead_swc_VCOP_Step_F193_ECUHardwareVersionNumber_Byte4_F193_ECUHardwareVersionNumber_Byte4() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F193_ECUHardwareVersionNumber_Byte4_F193_ECUHardwareVersionNumber_Byte4.value)

#define Rte_IRead_swc_VCOP_Step_F193_ECUHardwareVersionNumber_Byte6_F193_ECUHardwareVersionNumber_Byte6() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F193_ECUHardwareVersionNumber_Byte6_F193_ECUHardwareVersionNumber_Byte6.value)

#define Rte_IRead_swc_VCOP_Step_F193_ECUHardwareVersionNumber_Byte7_F193_ECUHardwareVersionNumber_Byte7() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F193_ECUHardwareVersionNumber_Byte7_F193_ECUHardwareVersionNumber_Byte7.value)

#define Rte_IRead_swc_VCOP_Step_F193_ECUHardwareVersionNumber_Byte8_F193_ECUHardwareVersionNumber_Byte8() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F193_ECUHardwareVersionNumber_Byte8_F193_ECUHardwareVersionNumber_Byte8.value)

#define Rte_IRead_swc_VCOP_Step_F195_ECUSoftwareVersionNumber_Byte2_F195_ECUSoftwareVersionNumber_Byte2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F195_ECUSoftwareVersionNumber_Byte2_F195_ECUSoftwareVersionNumber_Byte2.value)

#define Rte_IRead_swc_VCOP_Step_F195_ECUSoftwareVersionNumber_Byte3_F195_ECUSoftwareVersionNumber_Byte3() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F195_ECUSoftwareVersionNumber_Byte3_F195_ECUSoftwareVersionNumber_Byte3.value)

#define Rte_IRead_swc_VCOP_Step_F195_ECUSoftwareVersionNumber_Byte4_F195_ECUSoftwareVersionNumber_Byte4() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F195_ECUSoftwareVersionNumber_Byte4_F195_ECUSoftwareVersionNumber_Byte4.value)

#define Rte_IRead_swc_VCOP_Step_F195_ECUSoftwareVersionNumber_Byte6_F195_ECUSoftwareVersionNumber_Byte6() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F195_ECUSoftwareVersionNumber_Byte6_F195_ECUSoftwareVersionNumber_Byte6.value)

#define Rte_IRead_swc_VCOP_Step_F195_ECUSoftwareVersionNumber_Byte7_F195_ECUSoftwareVersionNumber_Byte7() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F195_ECUSoftwareVersionNumber_Byte7_F195_ECUSoftwareVersionNumber_Byte7.value)

#define Rte_IRead_swc_VCOP_Step_F195_ECUSoftwareVersionNumber_Byte8_F195_ECUSoftwareVersionNumber_Byte8() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_F195_ECUSoftwareVersionNumber_Byte8_F195_ECUSoftwareVersionNumber_Byte8.value)

#define Rte_IWrite_swc_VCOP_Step_FWFV_CCWFlg_PMS_FWFV_CCWFlg_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_CCWFlg_PMS_FWFV_CCWFlg_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_FWFV_CCWFlg_PMS_FWFV_CCWFlg_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_CCWFlg_PMS_FWFV_CCWFlg_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_FWFV_CurrentPos_PMS_FWFV_CurrentPos_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_CurrentPos_PMS_FWFV_CurrentPos_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_FWFV_CurrentPos_PMS_FWFV_CurrentPos_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_CurrentPos_PMS_FWFV_CurrentPos_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_FWFV_InitState_PMS_FWFV_InitState_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_InitState_PMS_FWFV_InitState_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_FWFV_InitState_PMS_FWFV_InitState_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_InitState_PMS_FWFV_InitState_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_FWFV_MotorState_PMS_FWFV_MotorState_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_MotorState_PMS_FWFV_MotorState_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_FWFV_MotorState_PMS_FWFV_MotorState_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_MotorState_PMS_FWFV_MotorState_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_FWFV_OverCurrentFlt_PMS_FWFV_OverCurrentFlt_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_OverCurrentFlt_PMS_FWFV_OverCurrentFlt_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_FWFV_OverCurrentFlt_PMS_FWFV_OverCurrentFlt_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_OverCurrentFlt_PMS_FWFV_OverCurrentFlt_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_FWFV_OverTempFlt_PMS_FWFV_OverTempFlt_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_OverTempFlt_PMS_FWFV_OverTempFlt_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_FWFV_OverTempFlt_PMS_FWFV_OverTempFlt_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_OverTempFlt_PMS_FWFV_OverTempFlt_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_FWFV_OverVoltageFlt_PMS_FWFV_OverVoltageFlt_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_OverVoltageFlt_PMS_FWFV_OverVoltageFlt_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_FWFV_OverVoltageFlt_PMS_FWFV_OverVoltageFlt_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_OverVoltageFlt_PMS_FWFV_OverVoltageFlt_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_FWFV_RESP_ERROR_PMS_FWFV_RESP_ERROR_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_RESP_ERROR_PMS_FWFV_RESP_ERROR_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_FWFV_RESP_ERROR_PMS_FWFV_RESP_ERROR_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_RESP_ERROR_PMS_FWFV_RESP_ERROR_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_FWFV_UnderVoltageFlt_PMS_FWFV_UnderVoltageFlt_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_UnderVoltageFlt_PMS_FWFV_UnderVoltageFlt_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_FWFV_UnderVoltageFlt_PMS_FWFV_UnderVoltageFlt_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_FWFV_UnderVoltageFlt_PMS_FWFV_UnderVoltageFlt_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_HBCP_Flt_HBCP_Flt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_HBCP_Flt_HBCP_Flt.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_HBCP_Flt_HBCP_Flt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_HBCP_Flt_HBCP_Flt.value \
)

#define Rte_IWrite_swc_VCOP_Step_HBCP_PWMFB_HBCP_PWMFB(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_HBCP_PWMFB_HBCP_PWMFB.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_HBCP_PWMFB_HBCP_PWMFB() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_HBCP_PWMFB_HBCP_PWMFB.value \
)

#define Rte_IWrite_swc_VCOP_Step_IPK_IPKTotalOdometer_EV_IPK_IPKTotalOdometer_EV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPK_IPKTotalOdometer_EV_IPK_IPKTotalOdometer_EV.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_IPK_IPKTotalOdometer_EV_IPK_IPKTotalOdometer_EV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPK_IPKTotalOdometer_EV_IPK_IPKTotalOdometer_EV.value \
)

#define Rte_IWrite_swc_VCOP_Step_IPU_HVBusCur_PT_IPU_HVBusCur_PT(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_HVBusCur_PT_IPU_HVBusCur_PT.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_IPU_HVBusCur_PT_IPU_HVBusCur_PT() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_HVBusCur_PT_IPU_HVBusCur_PT.value \
)

#define Rte_IWrite_swc_VCOP_Step_IPU_HVBusVolt_PT_IPU_HVBusVolt_PT(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_HVBusVolt_PT_IPU_HVBusVolt_PT.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_IPU_HVBusVolt_PT_IPU_HVBusVolt_PT() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_HVBusVolt_PT_IPU_HVBusVolt_PT.value \
)

#define Rte_IWrite_swc_VCOP_Step_IPU_IPUTAlm_IPU_IPUTAlm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_IPUTAlm_IPU_IPUTAlm.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_IPU_IPUTAlm_IPU_IPUTAlm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_IPUTAlm_IPU_IPUTAlm.value \
)

#define Rte_IWrite_swc_VCOP_Step_IPU_MCUTempHighAlarm1_PT_IPU_MCUTempHighAlarm1_PT(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_MCUTempHighAlarm1_PT_IPU_MCUTempHighAlarm1_PT.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_IPU_MCUTempHighAlarm1_PT_IPU_MCUTempHighAlarm1_PT() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_MCUTempHighAlarm1_PT_IPU_MCUTempHighAlarm1_PT.value \
)

#define Rte_IWrite_swc_VCOP_Step_IPU_MCUTempHighAlarm2_PMS_IPU_MCUTempHighAlarm2_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_MCUTempHighAlarm2_PMS_IPU_MCUTempHighAlarm2_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_IPU_MCUTempHighAlarm2_PMS_IPU_MCUTempHighAlarm2_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_MCUTempHighAlarm2_PMS_IPU_MCUTempHighAlarm2_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_IPU_MotorOverCurrFlt1_PMS_IPU_MotorOverCurrFlt1_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_MotorOverCurrFlt1_PMS_IPU_MotorOverCurrFlt1_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_IPU_MotorOverCurrFlt1_PMS_IPU_MotorOverCurrFlt1_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_MotorOverCurrFlt1_PMS_IPU_MotorOverCurrFlt1_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_IPU_MotorOverSpdFlt1_PMS_IPU_MotorOverSpdFlt1_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_MotorOverSpdFlt1_PMS_IPU_MotorOverSpdFlt1_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_IPU_MotorOverSpdFlt1_PMS_IPU_MotorOverSpdFlt1_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_MotorOverSpdFlt1_PMS_IPU_MotorOverSpdFlt1_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_IPU_MotorTempHighFault1_PT_IPU_MotorTempHighFault1_PT(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_MotorTempHighFault1_PT_IPU_MotorTempHighFault1_PT.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_IPU_MotorTempHighFault1_PT_IPU_MotorTempHighFault1_PT() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_MotorTempHighFault1_PT_IPU_MotorTempHighFault1_PT.value \
)

#define Rte_IWrite_swc_VCOP_Step_IPU_MotorTempHighFault2_PMS_IPU_MotorTempHighFault2_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_MotorTempHighFault2_PMS_IPU_MotorTempHighFault2_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_IPU_MotorTempHighFault2_PMS_IPU_MotorTempHighFault2_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_IPU_MotorTempHighFault2_PMS_IPU_MotorTempHighFault2_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_MHGV_CCWFlg_PMS_MHGV_CCWFlg_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_CCWFlg_PMS_MHGV_CCWFlg_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_MHGV_CCWFlg_PMS_MHGV_CCWFlg_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_CCWFlg_PMS_MHGV_CCWFlg_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_MHGV_CurrentPos_PMS_MHGV_CurrentPos_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_CurrentPos_PMS_MHGV_CurrentPos_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_MHGV_CurrentPos_PMS_MHGV_CurrentPos_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_CurrentPos_PMS_MHGV_CurrentPos_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_MHGV_InitState_PMS_MHGV_InitState_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_InitState_PMS_MHGV_InitState_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_MHGV_InitState_PMS_MHGV_InitState_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_InitState_PMS_MHGV_InitState_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_MHGV_MotorState_PMS_MHGV_MotorState_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_MotorState_PMS_MHGV_MotorState_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_MHGV_MotorState_PMS_MHGV_MotorState_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_MotorState_PMS_MHGV_MotorState_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_MHGV_OverCurrentFlt_PMS_MHGV_OverCurrentFlt_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_OverCurrentFlt_PMS_MHGV_OverCurrentFlt_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_MHGV_OverCurrentFlt_PMS_MHGV_OverCurrentFlt_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_OverCurrentFlt_PMS_MHGV_OverCurrentFlt_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_MHGV_OverTempFlt_PMS_MHGV_OverTempFlt_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_OverTempFlt_PMS_MHGV_OverTempFlt_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_MHGV_OverTempFlt_PMS_MHGV_OverTempFlt_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_OverTempFlt_PMS_MHGV_OverTempFlt_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_MHGV_OverVoltageFlt_PMS_MHGV_OverVoltageFlt_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_OverVoltageFlt_PMS_MHGV_OverVoltageFlt_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_MHGV_OverVoltageFlt_PMS_MHGV_OverVoltageFlt_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_OverVoltageFlt_PMS_MHGV_OverVoltageFlt_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_MHGV_RESP_ERROR_PMS_MHGV_RESP_ERROR_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_RESP_ERROR_PMS_MHGV_RESP_ERROR_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_MHGV_RESP_ERROR_PMS_MHGV_RESP_ERROR_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_RESP_ERROR_PMS_MHGV_RESP_ERROR_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_MHGV_UnderVoltageFlt_PMS_MHGV_UnderVoltageFlt_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_UnderVoltageFlt_PMS_MHGV_UnderVoltageFlt_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_MHGV_UnderVoltageFlt_PMS_MHGV_UnderVoltageFlt_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_MHGV_UnderVoltageFlt_PMS_MHGV_UnderVoltageFlt_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_ODP_TBOX_DcDcStsAlm_ODP_TBOX_DcDcStsAlm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_ODP_TBOX_DcDcStsAlm_ODP_TBOX_DcDcStsAlm.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_ODP_TBOX_DcDcStsAlm_ODP_TBOX_DcDcStsAlm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_ODP_TBOX_DcDcStsAlm_ODP_TBOX_DcDcStsAlm.value \
)

#define Rte_IWrite_swc_VCOP_Step_ODP_TBOX_DcDcStsAlm1_PMS_ODP_TBOX_DcDcStsAlm1_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_ODP_TBOX_DcDcStsAlm1_PMS_ODP_TBOX_DcDcStsAlm1_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_ODP_TBOX_DcDcStsAlm1_PMS_ODP_TBOX_DcDcStsAlm1_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_ODP_TBOX_DcDcStsAlm1_PMS_ODP_TBOX_DcDcStsAlm1_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_ODP_TBOX_TDcDcAlm_ODP_TBOX_TDcDcAlm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_ODP_TBOX_TDcDcAlm_ODP_TBOX_TDcDcAlm.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_ODP_TBOX_TDcDcAlm_ODP_TBOX_TDcDcAlm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_ODP_TBOX_TDcDcAlm_ODP_TBOX_TDcDcAlm.value \
)

#define Rte_IWrite_swc_VCOP_Step_ODP_TBOX_TDcDcAlm1_PMS_ODP_TBOX_TDcDcAlm1_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_ODP_TBOX_TDcDcAlm1_PMS_ODP_TBOX_TDcDcAlm1_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_ODP_TBOX_TDcDcAlm1_PMS_ODP_TBOX_TDcDcAlm1_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_ODP_TBOX_TDcDcAlm1_PMS_ODP_TBOX_TDcDcAlm1_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_O_S_PIN110_O_S_PIN110(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_S_PIN110_O_S_PIN110.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_O_S_PIN110_O_S_PIN110() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_S_PIN110_O_S_PIN110.value \
)

#define Rte_IWrite_swc_VCOP_Step_O_S_PIN123_O_S_PIN123(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_S_PIN123_O_S_PIN123.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_O_S_PIN123_O_S_PIN123() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_S_PIN123_O_S_PIN123.value \
)

#define Rte_IWrite_swc_VCOP_Step_O_S_PIN83_O_S_PIN83(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_S_PIN83_O_S_PIN83.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_O_S_PIN83_O_S_PIN83() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_S_PIN83_O_S_PIN83.value \
)

#define Rte_IWrite_swc_VCOP_Step_O_S_PIN88_O_S_PIN88(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_S_PIN88_O_S_PIN88.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_O_S_PIN88_O_S_PIN88() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_S_PIN88_O_S_PIN88.value \
)

#define Rte_IWrite_swc_VCOP_Step_O_S_PIN89_O_S_PIN89(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_S_PIN89_O_S_PIN89.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_O_S_PIN89_O_S_PIN89() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_S_PIN89_O_S_PIN89.value \
)

#define Rte_IWrite_swc_VCOP_Step_O_S_PIN98_O_S_PIN98(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_S_PIN98_O_S_PIN98.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_O_S_PIN98_O_S_PIN98() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_S_PIN98_O_S_PIN98.value \
)

#define Rte_IWrite_swc_VCOP_Step_O_T_PIN104_Duty_O_T_PIN104_Duty(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN104_Duty_O_T_PIN104_Duty.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_O_T_PIN104_Duty_O_T_PIN104_Duty() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN104_Duty_O_T_PIN104_Duty.value \
)

#define Rte_IWrite_swc_VCOP_Step_O_T_PIN104_Period_O_T_PIN104_Period(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN104_Period_O_T_PIN104_Period.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_O_T_PIN104_Period_O_T_PIN104_Period() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN104_Period_O_T_PIN104_Period.value \
)

#define Rte_IWrite_swc_VCOP_Step_O_T_PIN118_Duty_O_T_PIN118_Duty(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN118_Duty_O_T_PIN118_Duty.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_O_T_PIN118_Duty_O_T_PIN118_Duty() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN118_Duty_O_T_PIN118_Duty.value \
)

#define Rte_IWrite_swc_VCOP_Step_O_T_PIN118_Period_O_T_PIN118_Period(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN118_Period_O_T_PIN118_Period.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_O_T_PIN118_Period_O_T_PIN118_Period() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN118_Period_O_T_PIN118_Period.value \
)

#define Rte_IWrite_swc_VCOP_Step_O_T_PIN14_Duty_O_T_PIN14_Duty(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN14_Duty_O_T_PIN14_Duty.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_O_T_PIN14_Duty_O_T_PIN14_Duty() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN14_Duty_O_T_PIN14_Duty.value \
)

#define Rte_IWrite_swc_VCOP_Step_O_T_PIN14_Period_O_T_PIN14_Period(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN14_Period_O_T_PIN14_Period.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_O_T_PIN14_Period_O_T_PIN14_Period() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN14_Period_O_T_PIN14_Period.value \
)

#define Rte_IWrite_swc_VCOP_Step_O_T_PIN28_Duty_O_T_PIN28_Duty(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN28_Duty_O_T_PIN28_Duty.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_O_T_PIN28_Duty_O_T_PIN28_Duty() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN28_Duty_O_T_PIN28_Duty.value \
)

#define Rte_IWrite_swc_VCOP_Step_O_T_PIN28_Period_O_T_PIN28_Period(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN28_Period_O_T_PIN28_Period.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_O_T_PIN28_Period_O_T_PIN28_Period() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN28_Period_O_T_PIN28_Period.value \
)

#define Rte_IWrite_swc_VCOP_Step_O_T_PIN77_Duty_O_T_PIN77_Duty(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN77_Duty_O_T_PIN77_Duty.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_O_T_PIN77_Duty_O_T_PIN77_Duty() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN77_Duty_O_T_PIN77_Duty.value \
)

#define Rte_IWrite_swc_VCOP_Step_O_T_PIN77_Period_O_T_PIN77_Period(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN77_Period_O_T_PIN77_Period.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_O_T_PIN77_Period_O_T_PIN77_Period() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN77_Period_O_T_PIN77_Period.value \
)

#define Rte_IWrite_swc_VCOP_Step_O_T_PIN82_Duty_O_T_PIN82_Duty(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN82_Duty_O_T_PIN82_Duty.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_O_T_PIN82_Duty_O_T_PIN82_Duty() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN82_Duty_O_T_PIN82_Duty.value \
)

#define Rte_IWrite_swc_VCOP_Step_O_T_PIN82_Period_O_T_PIN82_Period(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN82_Period_O_T_PIN82_Period.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_O_T_PIN82_Period_O_T_PIN82_Period() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_O_T_PIN82_Period_O_T_PIN82_Period.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_0X16A_TimeoutFlag_PMS_0X16A_TimeoutFlag(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_0X16A_TimeoutFlag_PMS_0X16A_TimeoutFlag.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_0X16A_TimeoutFlag_PMS_0X16A_TimeoutFlag() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_0X16A_TimeoutFlag_PMS_0X16A_TimeoutFlag.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_32960FltNum_PMS_PMS_32960FltNum_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_32960FltNum_PMS_PMS_32960FltNum_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_32960FltNum_PMS_PMS_32960FltNum_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_32960FltNum_PMS_PMS_32960FltNum_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ACC1PosVol_PMS_ACC1PosVol(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ACC1PosVol_PMS_ACC1PosVol.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ACC1PosVol_PMS_ACC1PosVol() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ACC1PosVol_PMS_ACC1PosVol.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ACC2PosVol_PMS_ACC2PosVol(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ACC2PosVol_PMS_ACC2PosVol.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ACC2PosVol_PMS_ACC2PosVol() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ACC2PosVol_PMS_ACC2PosVol.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ACCMEnable_PMS_ACCMEnable(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ACCMEnable_PMS_ACCMEnable.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ACCMEnable_PMS_ACCMEnable() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ACCMEnable_PMS_ACCMEnable.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ACC_BeControlled_Status_PMS_ACC_BeControlled_Status(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ACC_BeControlled_Status_PMS_ACC_BeControlled_Status.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ACC_BeControlled_Status_PMS_ACC_BeControlled_Status() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ACC_BeControlled_Status_PMS_ACC_BeControlled_Status.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ADCCtrlSts_PMS_ADCCtrlSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ADCCtrlSts_PMS_ADCCtrlSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ADCCtrlSts_PMS_ADCCtrlSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ADCCtrlSts_PMS_ADCCtrlSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_APA_BeControlled_Status_PMS_APA_BeControlled_Status(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_APA_BeControlled_Status_PMS_APA_BeControlled_Status.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_APA_BeControlled_Status_PMS_APA_BeControlled_Status() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_APA_BeControlled_Status_PMS_APA_BeControlled_Status.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_AcceRelayVoltSampSwich_PMS_AcceRelayVoltSampSwich(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AcceRelayVoltSampSwich_PMS_AcceRelayVoltSampSwich.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_AcceRelayVoltSampSwich_PMS_AcceRelayVoltSampSwich() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AcceRelayVoltSampSwich_PMS_AcceRelayVoltSampSwich.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_AcceSuppressionSts_PMS_PMS_AcceSuppressionSts_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AcceSuppressionSts_PMS_PMS_AcceSuppressionSts_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_AcceSuppressionSts_PMS_PMS_AcceSuppressionSts_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AcceSuppressionSts_PMS_PMS_AcceSuppressionSts_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_AccelPedalPosition_PMS_AccelPedalPosition(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AccelPedalPosition_PMS_AccelPedalPosition.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_AccelPedalPosition_PMS_AccelPedalPosition() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AccelPedalPosition_PMS_AccelPedalPosition.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_AccelPedalPositionInvalid_PMS_AccelPedalPositionInvalid(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AccelPedalPositionInvalid_PMS_AccelPedalPositionInvalid.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_AccelPedalPositionInvalid_PMS_AccelPedalPositionInvalid() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AccelPedalPositionInvalid_PMS_AccelPedalPositionInvalid.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_Acceleration_PMS_Acceleration(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Acceleration_PMS_Acceleration.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_Acceleration_PMS_Acceleration() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Acceleration_PMS_Acceleration.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_AccessoryConnStsFb_PMS_AccessoryConnStsFb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AccessoryConnStsFb_PMS_AccessoryConnStsFb.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_AccessoryConnStsFb_PMS_AccessoryConnStsFb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AccessoryConnStsFb_PMS_AccessoryConnStsFb.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_AccessoryCtrlCommand_PMS_AccessoryCtrlCommand(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AccessoryCtrlCommand_PMS_AccessoryCtrlCommand.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_AccessoryCtrlCommand_PMS_AccessoryCtrlCommand() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AccessoryCtrlCommand_PMS_AccessoryCtrlCommand.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_AccessoryRelayFlt_PMS_AccessoryRelayFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AccessoryRelayFlt_PMS_AccessoryRelayFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_AccessoryRelayFlt_PMS_AccessoryRelayFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AccessoryRelayFlt_PMS_AccessoryRelayFlt.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ActualPTTorque_PMS_ActualPTTorque(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ActualPTTorque_PMS_ActualPTTorque.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ActualPTTorque_PMS_ActualPTTorque() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ActualPTTorque_PMS_ActualPTTorque.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ActualPTTorqueInvalid_PMS_ActualPTTorqueInvalid(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ActualPTTorqueInvalid_PMS_ActualPTTorqueInvalid.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ActualPTTorqueInvalid_PMS_ActualPTTorqueInvalid() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ActualPTTorqueInvalid_PMS_ActualPTTorqueInvalid.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_AppSts_PMS_AppSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AppSts_PMS_AppSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_AppSts_PMS_AppSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AppSts_PMS_AppSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_AppSts_EV_PMS_AppSts_EV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AppSts_EV_PMS_AppSts_EV.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_AppSts_EV_PMS_AppSts_EV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AppSts_EV_PMS_AppSts_EV.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_AuthResult_PMS_AuthResult(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AuthResult_PMS_AuthResult.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_AuthResult_PMS_AuthResult() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AuthResult_PMS_AuthResult.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_AveragePowerConsumption_PMS_AveragePowerConsumption(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AveragePowerConsumption_PMS_AveragePowerConsumption.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_AveragePowerConsumption_PMS_AveragePowerConsumption() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_AveragePowerConsumption_PMS_AveragePowerConsumption.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_BBM1CtrlCmd_PMS_BBM1CtrlCmd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BBM1CtrlCmd_PMS_BBM1CtrlCmd.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_BBM1CtrlCmd_PMS_BBM1CtrlCmd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BBM1CtrlCmd_PMS_BBM1CtrlCmd.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_BBMAllowEnable_Ctrl_PMS_BBMAllowEnable_Ctrl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BBMAllowEnable_Ctrl_PMS_BBMAllowEnable_Ctrl.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_BBMAllowEnable_Ctrl_PMS_BBMAllowEnable_Ctrl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BBMAllowEnable_Ctrl_PMS_BBMAllowEnable_Ctrl.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_BBMPowerSupplyEn_Ctrl_PMS_BBMPowerSupplyEn_Ctrl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BBMPowerSupplyEn_Ctrl_PMS_BBMPowerSupplyEn_Ctrl.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_BBMPowerSupplyEn_Ctrl_PMS_BBMPowerSupplyEn_Ctrl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BBMPowerSupplyEn_Ctrl_PMS_BBMPowerSupplyEn_Ctrl.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_BBM_FaultStatus_PMS_BBM_FaultStatus(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BBM_FaultStatus_PMS_BBM_FaultStatus.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_BBM_FaultStatus_PMS_BBM_FaultStatus() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BBM_FaultStatus_PMS_BBM_FaultStatus.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_BBM_HVReq_PMS_BBM_HVReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BBM_HVReq_PMS_BBM_HVReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_BBM_HVReq_PMS_BBM_HVReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BBM_HVReq_PMS_BBM_HVReq.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_BBM_WorkSts_PMS_BBM_WorkSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BBM_WorkSts_PMS_BBM_WorkSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_BBM_WorkSts_PMS_BBM_WorkSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BBM_WorkSts_PMS_BBM_WorkSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_BMSH_BattRemainEnergy_PMS_BMSH_BattRemainEnergy(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BMSH_BattRemainEnergy_PMS_BMSH_BattRemainEnergy.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_BMSH_BattRemainEnergy_PMS_BMSH_BattRemainEnergy() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BMSH_BattRemainEnergy_PMS_BMSH_BattRemainEnergy.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_BMSH_BattSOCDisp_PMS_BMSH_BattSOCDisp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BMSH_BattSOCDisp_PMS_BMSH_BattSOCDisp.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_BMSH_BattSOCDisp_PMS_BMSH_BattSOCDisp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BMSH_BattSOCDisp_PMS_BMSH_BattSOCDisp.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_BMSH_BattSOH_PMS_BMSH_BattSOH(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BMSH_BattSOH_PMS_BMSH_BattSOH.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_BMSH_BattSOH_PMS_BMSH_BattSOH() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BMSH_BattSOH_PMS_BMSH_BattSOH.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_BMS_Reignstatus1_PMS_BMS_Reignstatus1(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BMS_Reignstatus1_PMS_BMS_Reignstatus1.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_BMS_Reignstatus1_PMS_BMS_Reignstatus1() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BMS_Reignstatus1_PMS_BMS_Reignstatus1.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_BMS_Reignstatus2_PMS_BMS_Reignstatus2(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BMS_Reignstatus2_PMS_BMS_Reignstatus2.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_BMS_Reignstatus2_PMS_BMS_Reignstatus2() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BMS_Reignstatus2_PMS_BMS_Reignstatus2.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_BatCoolType_PMS_BatCoolType(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BatCoolType_PMS_BatCoolType.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_BatCoolType_PMS_BatCoolType() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BatCoolType_PMS_BatCoolType.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_BattPackInCoolTempback_EV_PMS_BattPackInCoolTempback_EV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BattPackInCoolTempback_EV_PMS_BattPackInCoolTempback_EV.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_BattPackInCoolTempback_EV_PMS_BattPackInCoolTempback_EV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BattPackInCoolTempback_EV_PMS_BattPackInCoolTempback_EV.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_BattPackOutCoolTempback_EV_PMS_BattPackOutCoolTempback_EV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BattPackOutCoolTempback_EV_PMS_BattPackOutCoolTempback_EV.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_BattPackOutCoolTempback_EV_PMS_BattPackOutCoolTempback_EV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BattPackOutCoolTempback_EV_PMS_BattPackOutCoolTempback_EV.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_BatteryVol_PMS_BatteryVol(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BatteryVol_PMS_BatteryVol.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_BatteryVol_PMS_BatteryVol() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BatteryVol_PMS_BatteryVol.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_Brake1Switch_PMS_Brake1Switch(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Brake1Switch_PMS_Brake1Switch.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_Brake1Switch_PMS_Brake1Switch() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Brake1Switch_PMS_Brake1Switch.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_Brake2Switch_PMS_Brake2Switch(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Brake2Switch_PMS_Brake2Switch.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_Brake2Switch_PMS_Brake2Switch() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Brake2Switch_PMS_Brake2Switch.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_Brake_LightsRequest_PMS_Brake_LightsRequest(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Brake_LightsRequest_PMS_Brake_LightsRequest.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_Brake_LightsRequest_PMS_Brake_LightsRequest() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Brake_LightsRequest_PMS_Brake_LightsRequest.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_BrkSysErr_PMS_BrkSysErr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BrkSysErr_PMS_BrkSysErr.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_BrkSysErr_PMS_BrkSysErr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_BrkSysErr_PMS_BrkSysErr.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_CANBus_RecSta_PMS_CANBus_RecSta(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CANBus_RecSta_PMS_CANBus_RecSta.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_CANBus_RecSta_PMS_CANBus_RecSta() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CANBus_RecSta_PMS_CANBus_RecSta.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_CPSREn_PMS_CPSREn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CPSREn_PMS_CPSREn.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_CPSREn_PMS_CPSREn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CPSREn_PMS_CPSREn.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_CPSRU_PMS_CPSRU(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CPSRU_PMS_CPSRU.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_CPSRU_PMS_CPSRU() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CPSRU_PMS_CPSRU.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_CSControl1_CheckSum_PMS_CSControl1_CheckSum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CSControl1_CheckSum_PMS_CSControl1_CheckSum.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_CSControl1_CheckSum_PMS_CSControl1_CheckSum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CSControl1_CheckSum_PMS_CSControl1_CheckSum.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_CSControl2_CheckSum_PMS_CSControl2_CheckSum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CSControl2_CheckSum_PMS_CSControl2_CheckSum.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_CSControl2_CheckSum_PMS_CSControl2_CheckSum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CSControl2_CheckSum_PMS_CSControl2_CheckSum.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_CampModeFb_PMS_CampModeFb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CampModeFb_PMS_CampModeFb.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_CampModeFb_PMS_CampModeFb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CampModeFb_PMS_CampModeFb.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_CampModeFbFailrReason_PMS_CampModeFbFailrReason(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CampModeFbFailrReason_PMS_CampModeFbFailrReason.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_CampModeFbFailrReason_PMS_CampModeFbFailrReason() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CampModeFbFailrReason_PMS_CampModeFbFailrReason.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ChargPwr_PMS_ChargPwr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ChargPwr_PMS_ChargPwr.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ChargPwr_PMS_ChargPwr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ChargPwr_PMS_ChargPwr.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ChargWakeupSts_PMS_ChargWakeupSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ChargWakeupSts_PMS_ChargWakeupSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ChargWakeupSts_PMS_ChargWakeupSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ChargWakeupSts_PMS_ChargWakeupSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ChargeHV_Status_PMS_ChargeHV_Status(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ChargeHV_Status_PMS_ChargeHV_Status.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ChargeHV_Status_PMS_ChargeHV_Status() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ChargeHV_Status_PMS_ChargeHV_Status.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ChargeLimitResponse_PMS_ChargeLimitResponse(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ChargeLimitResponse_PMS_ChargeLimitResponse.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ChargeLimitResponse_PMS_ChargeLimitResponse() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ChargeLimitResponse_PMS_ChargeLimitResponse.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ChargerFault_PMS_ChargerFault(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ChargerFault_PMS_ChargerFault.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ChargerFault_PMS_ChargerFault() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ChargerFault_PMS_ChargerFault.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_Command_AliveCounter_PMS_Command_AliveCounter(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Command_AliveCounter_PMS_Command_AliveCounter.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_Command_AliveCounter_PMS_Command_AliveCounter() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Command_AliveCounter_PMS_Command_AliveCounter.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_Command_AliveCounter_EV_PMS_Command_AliveCounter_EV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Command_AliveCounter_EV_PMS_Command_AliveCounter_EV.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_Command_AliveCounter_EV_PMS_Command_AliveCounter_EV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Command_AliveCounter_EV_PMS_Command_AliveCounter_EV.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_Command_Checksum_PMS_Command_Checksum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Command_Checksum_PMS_Command_Checksum.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_Command_Checksum_PMS_Command_Checksum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Command_Checksum_PMS_Command_Checksum.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_Command_Checksum_EV_PMS_Command_Checksum_EV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Command_Checksum_EV_PMS_Command_Checksum_EV.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_Command_Checksum_EV_PMS_Command_Checksum_EV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Command_Checksum_EV_PMS_Command_Checksum_EV.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ControlSetSpeed_PMS_ControlSetSpeed(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ControlSetSpeed_PMS_ControlSetSpeed.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ControlSetSpeed_PMS_ControlSetSpeed() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ControlSetSpeed_PMS_ControlSetSpeed.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_CoolingFanFaultFB_PMS_CoolingFanFaultFB(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CoolingFanFaultFB_PMS_CoolingFanFaultFB.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_CoolingFanFaultFB_PMS_CoolingFanFaultFB() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CoolingFanFaultFB_PMS_CoolingFanFaultFB.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_CruiseControlSts_PMS_CruiseControlSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CruiseControlSts_PMS_CruiseControlSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_CruiseControlSts_PMS_CruiseControlSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CruiseControlSts_PMS_CruiseControlSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_CruiseSwitchSts_PMS_CruiseSwitchSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CruiseSwitchSts_PMS_CruiseSwitchSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_CruiseSwitchSts_PMS_CruiseSwitchSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CruiseSwitchSts_PMS_CruiseSwitchSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_CruisingDstSwtFb_PMS_CruisingDstSwtFb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CruisingDstSwtFb_PMS_CruisingDstSwtFb.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_CruisingDstSwtFb_PMS_CruisingDstSwtFb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CruisingDstSwtFb_PMS_CruisingDstSwtFb.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_Ctrl_Checksum_PMS_Ctrl_Checksum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Ctrl_Checksum_PMS_Ctrl_Checksum.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_Ctrl_Checksum_PMS_Ctrl_Checksum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Ctrl_Checksum_PMS_Ctrl_Checksum.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_CurrentGearPosition_PMS_CurrentGearPosition(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CurrentGearPosition_PMS_CurrentGearPosition.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_CurrentGearPosition_PMS_CurrentGearPosition() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CurrentGearPosition_PMS_CurrentGearPosition.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_CurrentGearPosition_EV_PMS_CurrentGearPosition_EV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CurrentGearPosition_EV_PMS_CurrentGearPosition_EV.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_CurrentGearPosition_EV_PMS_CurrentGearPosition_EV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CurrentGearPosition_EV_PMS_CurrentGearPosition_EV.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_CurrentGearPosition_Valid_EV_PMS_CurrentGearPosition_Valid_EV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CurrentGearPosition_Valid_EV_PMS_CurrentGearPosition_Valid_EV.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_CurrentGearPosition_Valid_EV_PMS_CurrentGearPosition_Valid_EV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_CurrentGearPosition_Valid_EV_PMS_CurrentGearPosition_Valid_EV.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_DCDCAwake_HW_PMS_DCDCAwake_HW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DCDCAwake_HW_PMS_DCDCAwake_HW.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_DCDCAwake_HW_PMS_DCDCAwake_HW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DCDCAwake_HW_PMS_DCDCAwake_HW.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_DCDCPwrLmt_PMS_DCDCPwrLmt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DCDCPwrLmt_PMS_DCDCPwrLmt.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_DCDCPwrLmt_PMS_DCDCPwrLmt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DCDCPwrLmt_PMS_DCDCPwrLmt.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_DCDC_Ctrl_AliveCounter_PMS_DCDC_Ctrl_AliveCounter(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DCDC_Ctrl_AliveCounter_PMS_DCDC_Ctrl_AliveCounter.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_DCDC_Ctrl_AliveCounter_PMS_DCDC_Ctrl_AliveCounter() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DCDC_Ctrl_AliveCounter_PMS_DCDC_Ctrl_AliveCounter.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_DCDC_Ctrl_Checksum_PMS_DCDC_Ctrl_Checksum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DCDC_Ctrl_Checksum_PMS_DCDC_Ctrl_Checksum.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_DCDC_Ctrl_Checksum_PMS_DCDC_Ctrl_Checksum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DCDC_Ctrl_Checksum_PMS_DCDC_Ctrl_Checksum.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_DDwaterPump_PWMCtrl_EV_PMS_DDwaterPump_PWMCtrl_EV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DDwaterPump_PWMCtrl_EV_PMS_DDwaterPump_PWMCtrl_EV.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_DDwaterPump_PWMCtrl_EV_PMS_DDwaterPump_PWMCtrl_EV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DDwaterPump_PWMCtrl_EV_PMS_DDwaterPump_PWMCtrl_EV.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_DM_FailureReasonAndSysFaultFBK_PMS_DM_FailureReasonAndSysFaultFBK(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DM_FailureReasonAndSysFaultFBK_PMS_DM_FailureReasonAndSysFaultFBK.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_DM_FailureReasonAndSysFaultFBK_PMS_DM_FailureReasonAndSysFaultFBK() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DM_FailureReasonAndSysFaultFBK_PMS_DM_FailureReasonAndSysFaultFBK.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_DcDc1ActvdReq_EV_PMS_DcDc1ActvdReq_EV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DcDc1ActvdReq_EV_PMS_DcDc1ActvdReq_EV.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_DcDc1ActvdReq_EV_PMS_DcDc1ActvdReq_EV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DcDc1ActvdReq_EV_PMS_DcDc1ActvdReq_EV.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_DcDcActvdReq_PMS_DcDcActvdReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DcDcActvdReq_PMS_DcDcActvdReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_DcDcActvdReq_PMS_DcDcActvdReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DcDcActvdReq_PMS_DcDcActvdReq.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_DisChrgrSwtSt_PMS_DisChrgrSwtSt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DisChrgrSwtSt_PMS_DisChrgrSwtSt.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_DisChrgrSwtSt_PMS_DisChrgrSwtSt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DisChrgrSwtSt_PMS_DisChrgrSwtSt.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_DischargeEnable_PMS_DischargeEnable(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DischargeEnable_PMS_DischargeEnable.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_DischargeEnable_PMS_DischargeEnable() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DischargeEnable_PMS_DischargeEnable.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_DoubleFlashLampOn_PMS_DoubleFlashLampOn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DoubleFlashLampOn_PMS_DoubleFlashLampOn.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_DoubleFlashLampOn_PMS_DoubleFlashLampOn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DoubleFlashLampOn_PMS_DoubleFlashLampOn.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_DriveCircuitTemp_EV_PMS_DriveCircuitTemp_EV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DriveCircuitTemp_EV_PMS_DriveCircuitTemp_EV.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_DriveCircuitTemp_EV_PMS_DriveCircuitTemp_EV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DriveCircuitTemp_EV_PMS_DriveCircuitTemp_EV.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_DriveModeInd_PMS_DriveModeInd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DriveModeInd_PMS_DriveModeInd.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_DriveModeInd_PMS_DriveModeInd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DriveModeInd_PMS_DriveModeInd.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_DriverDemandTorque_PMS_DriverDemandTorque(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DriverDemandTorque_PMS_DriverDemandTorque.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_DriverDemandTorque_PMS_DriverDemandTorque() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DriverDemandTorque_PMS_DriverDemandTorque.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_DriverDemandTorqueInvalid_PMS_DriverDemandTorqueInvalid(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DriverDemandTorqueInvalid_PMS_DriverDemandTorqueInvalid.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_DriverDemandTorqueInvalid_PMS_DriverDemandTorqueInvalid() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DriverDemandTorqueInvalid_PMS_DriverDemandTorqueInvalid.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_DriverGearAbort_PMS_DriverGearAbort(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DriverGearAbort_PMS_DriverGearAbort.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_DriverGearAbort_PMS_DriverGearAbort() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DriverGearAbort_PMS_DriverGearAbort.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_DriverRemind_PMS_DriverRemind(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DriverRemind_PMS_DriverRemind.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_DriverRemind_PMS_DriverRemind() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DriverRemind_PMS_DriverRemind.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_DrivingTakeEleSts_PMS_DrivingTakeEleSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DrivingTakeEleSts_PMS_DrivingTakeEleSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_DrivingTakeEleSts_PMS_DrivingTakeEleSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DrivingTakeEleSts_PMS_DrivingTakeEleSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_DrvrGearLvrLockIndcn_PMS_DrvrGearLvrLockIndcn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DrvrGearLvrLockIndcn_PMS_DrvrGearLvrLockIndcn.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_DrvrGearLvrLockIndcn_PMS_DrvrGearLvrLockIndcn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_DrvrGearLvrLockIndcn_PMS_DrvrGearLvrLockIndcn.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_EDCPEnable_PMS_EDCPEnable(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EDCPEnable_PMS_EDCPEnable.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_EDCPEnable_PMS_EDCPEnable() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EDCPEnable_PMS_EDCPEnable.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_EDCPEnable_EV_PMS_EDCPEnable_EV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EDCPEnable_EV_PMS_EDCPEnable_EV.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_EDCPEnable_EV_PMS_EDCPEnable_EV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EDCPEnable_EV_PMS_EDCPEnable_EV.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_EDCPPWMCtrl_EV_PMS_EDCPPWMCtrl_EV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EDCPPWMCtrl_EV_PMS_EDCPPWMCtrl_EV.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_EDCPPWMCtrl_EV_PMS_EDCPPWMCtrl_EV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EDCPPWMCtrl_EV_PMS_EDCPPWMCtrl_EV.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_EDCP_FaultFB_PMS_EDCP_FaultFB(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EDCP_FaultFB_PMS_EDCP_FaultFB.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_EDCP_FaultFB_PMS_EDCP_FaultFB() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EDCP_FaultFB_PMS_EDCP_FaultFB.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_EDCP_PWMCtrl_PMS_EDCP_PWMCtrl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EDCP_PWMCtrl_PMS_EDCP_PWMCtrl.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_EDCP_PWMCtrl_PMS_EDCP_PWMCtrl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EDCP_PWMCtrl_PMS_EDCP_PWMCtrl.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_EPBClosedReq_PMS_EPBClosedReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EPBClosedReq_PMS_EPBClosedReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_EPBClosedReq_PMS_EPBClosedReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EPBClosedReq_PMS_EPBClosedReq.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_EPS_SteeringAngleValue_PMS_EPS_SteeringAngleValue(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EPS_SteeringAngleValue_PMS_EPS_SteeringAngleValue.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_EPS_SteeringAngleValue_PMS_EPS_SteeringAngleValue() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EPS_SteeringAngleValue_PMS_EPS_SteeringAngleValue.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_EPS_SteeringAngleValueInvalid_PMS_EPS_SteeringAngleValueInvalid(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EPS_SteeringAngleValueInvalid_PMS_EPS_SteeringAngleValueInvalid.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_EPS_SteeringAngleValueInvalid_PMS_EPS_SteeringAngleValueInvalid() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EPS_SteeringAngleValueInvalid_PMS_EPS_SteeringAngleValueInvalid.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_EPedlDrvrIndcnMsg_PMS_EPedlDrvrIndcnMsg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EPedlDrvrIndcnMsg_PMS_EPedlDrvrIndcnMsg.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_EPedlDrvrIndcnMsg_PMS_EPedlDrvrIndcnMsg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EPedlDrvrIndcnMsg_PMS_EPedlDrvrIndcnMsg.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_EVDTEodometer_PMS_EVDTEodometer(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EVDTEodometer_PMS_EVDTEodometer.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_EVDTEodometer_PMS_EVDTEodometer() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EVDTEodometer_PMS_EVDTEodometer.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_EngControl_CheckSum_PMS_EngControl_CheckSum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EngControl_CheckSum_PMS_EngControl_CheckSum.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_EngControl_CheckSum_PMS_EngControl_CheckSum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EngControl_CheckSum_PMS_EngControl_CheckSum.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_EngTrqReqSrc_PMS_EngTrqReqSrc(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EngTrqReqSrc_PMS_EngTrqReqSrc.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_EngTrqReqSrc_PMS_EngTrqReqSrc() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EngTrqReqSrc_PMS_EngTrqReqSrc.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_EpedalActive_PMS_EpedalActive(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EpedalActive_PMS_EpedalActive.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_EpedalActive_PMS_EpedalActive() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_EpedalActive_PMS_EpedalActive.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ErrCode_PMS_ErrCode(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ErrCode_PMS_ErrCode.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ErrCode_PMS_ErrCode() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ErrCode_PMS_ErrCode.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ExecuteLockVehResults_PMS_ExecuteLockVehResults(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ExecuteLockVehResults_PMS_ExecuteLockVehResults.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ExecuteLockVehResults_PMS_ExecuteLockVehResults() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ExecuteLockVehResults_PMS_ExecuteLockVehResults.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_FAN_PWMCtrl_PMS_FAN_PWMCtrl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FAN_PWMCtrl_PMS_FAN_PWMCtrl.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_FAN_PWMCtrl_PMS_FAN_PWMCtrl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FAN_PWMCtrl_PMS_FAN_PWMCtrl.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_FWFV_MoveEnable_PMS_FWFV_MoveEnable(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FWFV_MoveEnable_PMS_FWFV_MoveEnable.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_FWFV_MoveEnable_PMS_FWFV_MoveEnable() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FWFV_MoveEnable_PMS_FWFV_MoveEnable.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_FWFV_MoveEnable_LIN_PMS_FWFV_MoveEnable_LIN(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FWFV_MoveEnable_LIN_PMS_FWFV_MoveEnable_LIN.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_FWFV_MoveEnable_LIN_PMS_FWFV_MoveEnable_LIN() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FWFV_MoveEnable_LIN_PMS_FWFV_MoveEnable_LIN.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_FWFV_ReqMovePos_PMS_FWFV_ReqMovePos(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FWFV_ReqMovePos_PMS_FWFV_ReqMovePos.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_FWFV_ReqMovePos_PMS_FWFV_ReqMovePos() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FWFV_ReqMovePos_PMS_FWFV_ReqMovePos.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_FWFV_ReqMovePos_LIN_PMS_FWFV_ReqMovePos_LIN(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FWFV_ReqMovePos_LIN_PMS_FWFV_ReqMovePos_LIN.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_FWFV_ReqMovePos_LIN_PMS_FWFV_ReqMovePos_LIN() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FWFV_ReqMovePos_LIN_PMS_FWFV_ReqMovePos_LIN.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_Fn1GearRlyDrvStsFb_PMS_Fn1GearRlyDrvStsFb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Fn1GearRlyDrvStsFb_PMS_Fn1GearRlyDrvStsFb.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_Fn1GearRlyDrvStsFb_PMS_Fn1GearRlyDrvStsFb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Fn1GearRlyDrvStsFb_PMS_Fn1GearRlyDrvStsFb.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_Fn2GearRlyDrvStsFb_PMS_Fn2GearRlyDrvStsFb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Fn2GearRlyDrvStsFb_PMS_Fn2GearRlyDrvStsFb.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_Fn2GearRlyDrvStsFb_PMS_Fn2GearRlyDrvStsFb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Fn2GearRlyDrvStsFb_PMS_Fn2GearRlyDrvStsFb.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_FunAnti_DismantleActive_PMS_FunAnti_DismantleActive(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FunAnti_DismantleActive_PMS_FunAnti_DismantleActive.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_FunAnti_DismantleActive_PMS_FunAnti_DismantleActive() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FunAnti_DismantleActive_PMS_FunAnti_DismantleActive.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_FunLockVehActive_PMS_FunLockVehActive(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FunLockVehActive_PMS_FunLockVehActive.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_FunLockVehActive_PMS_FunLockVehActive() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_FunLockVehActive_PMS_FunLockVehActive.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_GP_Ovrd_PMS_GP_Ovrd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_GP_Ovrd_PMS_GP_Ovrd.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_GP_Ovrd_PMS_GP_Ovrd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_GP_Ovrd_PMS_GP_Ovrd.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_GearOperateErr_PMS_GearOperateErr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_GearOperateErr_PMS_GearOperateErr.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_GearOperateErr_PMS_GearOperateErr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_GearOperateErr_PMS_GearOperateErr.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_Gear_intervene_PMS_Gear_intervene(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Gear_intervene_PMS_Gear_intervene.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_Gear_intervene_PMS_Gear_intervene() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Gear_intervene_PMS_Gear_intervene.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_GrossComVehWeight_PMS_GrossComVehWeight(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_GrossComVehWeight_PMS_GrossComVehWeight.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_GrossComVehWeight_PMS_GrossComVehWeight() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_GrossComVehWeight_PMS_GrossComVehWeight.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_HBCPEnable_PMS_HBCPEnable(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HBCPEnable_PMS_HBCPEnable.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_HBCPEnable_PMS_HBCPEnable() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HBCPEnable_PMS_HBCPEnable.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_HBCP_FaultFB_PMS_HBCP_FaultFB(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HBCP_FaultFB_PMS_HBCP_FaultFB.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_HBCP_FaultFB_PMS_HBCP_FaultFB() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HBCP_FaultFB_PMS_HBCP_FaultFB.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_HBCP_PWMCtrl_PMS_HBCP_PWMCtrl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HBCP_PWMCtrl_PMS_HBCP_PWMCtrl.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_HBCP_PWMCtrl_PMS_HBCP_PWMCtrl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HBCP_PWMCtrl_PMS_HBCP_PWMCtrl.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_HVIL1Sts_PMS_HVIL1Sts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HVIL1Sts_PMS_HVIL1Sts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_HVIL1Sts_PMS_HVIL1Sts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HVIL1Sts_PMS_HVIL1Sts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_HVIL1Sts_UB_PMS_HVIL1Sts_UB(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HVIL1Sts_UB_PMS_HVIL1Sts_UB.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_HVIL1Sts_UB_PMS_HVIL1Sts_UB() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HVIL1Sts_UB_PMS_HVIL1Sts_UB.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_HVIL2Sts_PMS_HVIL2Sts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HVIL2Sts_PMS_HVIL2Sts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_HVIL2Sts_PMS_HVIL2Sts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HVIL2Sts_PMS_HVIL2Sts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_HVIL2Sts_UB_PMS_HVIL2Sts_UB(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HVIL2Sts_UB_PMS_HVIL2Sts_UB.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_HVIL2Sts_UB_PMS_HVIL2Sts_UB() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HVIL2Sts_UB_PMS_HVIL2Sts_UB.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_HVILSts_PMS_HVILSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HVILSts_PMS_HVILSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_HVILSts_PMS_HVILSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HVILSts_PMS_HVILSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_HVILSts_UB_PMS_HVILSts_UB(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HVILSts_UB_PMS_HVILSts_UB.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_HVILSts_UB_PMS_HVILSts_UB() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HVILSts_UB_PMS_HVILSts_UB.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_HVPRASts_PMS_HVPRASts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HVPRASts_PMS_HVPRASts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_HVPRASts_PMS_HVPRASts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HVPRASts_PMS_HVPRASts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_HardwareMajorVer_PMS_HardwareMajorVer(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HardwareMajorVer_PMS_HardwareMajorVer.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_HardwareMajorVer_PMS_HardwareMajorVer() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HardwareMajorVer_PMS_HardwareMajorVer.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_HardwareMinorVer_PMS_HardwareMinorVer(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HardwareMinorVer_PMS_HardwareMinorVer.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_HardwareMinorVer_PMS_HardwareMinorVer() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HardwareMinorVer_PMS_HardwareMinorVer.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_HvBattCooltLvl_PMS_HvBattCooltLvl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HvBattCooltLvl_PMS_HvBattCooltLvl.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_HvBattCooltLvl_PMS_HvBattCooltLvl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HvBattCooltLvl_PMS_HvBattCooltLvl.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_HvCoolgPwrAllwd_PMS_HvCoolgPwrAllwd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HvCoolgPwrAllwd_PMS_HvCoolgPwrAllwd.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_HvCoolgPwrAllwd_PMS_HvCoolgPwrAllwd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HvCoolgPwrAllwd_PMS_HvCoolgPwrAllwd.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_HvHeatgPwrAllwd_PMS_HvHeatgPwrAllwd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HvHeatgPwrAllwd_PMS_HvHeatgPwrAllwd.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_HvHeatgPwrAllwd_PMS_HvHeatgPwrAllwd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_HvHeatgPwrAllwd_PMS_HvHeatgPwrAllwd.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_IPK_HandBrakeSts_PMS_IPK_HandBrakeSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IPK_HandBrakeSts_PMS_IPK_HandBrakeSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_IPK_HandBrakeSts_PMS_IPK_HandBrakeSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IPK_HandBrakeSts_PMS_IPK_HandBrakeSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_IgnONSts_PMS_IgnONSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IgnONSts_PMS_IgnONSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_IgnONSts_PMS_IgnONSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IgnONSts_PMS_IgnONSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_IntelligentChargeExitReq_PMS_IntelligentChargeExitReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IntelligentChargeExitReq_PMS_IntelligentChargeExitReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_IntelligentChargeExitReq_PMS_IntelligentChargeExitReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IntelligentChargeExitReq_PMS_IntelligentChargeExitReq.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_IntelligentChargeQuit_PMS_IntelligentChargeQuit(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IntelligentChargeQuit_PMS_IntelligentChargeQuit.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_IntelligentChargeQuit_PMS_IntelligentChargeQuit() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IntelligentChargeQuit_PMS_IntelligentChargeQuit.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_IntelligentChargeState_PMS_IntelligentChargeState(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IntelligentChargeState_PMS_IntelligentChargeState.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_IntelligentChargeState_PMS_IntelligentChargeState() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IntelligentChargeState_PMS_IntelligentChargeState.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_InventorySpdLmtRxSts_PMS_InventorySpdLmtRxSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_InventorySpdLmtRxSts_PMS_InventorySpdLmtRxSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_InventorySpdLmtRxSts_PMS_InventorySpdLmtRxSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_InventorySpdLmtRxSts_PMS_InventorySpdLmtRxSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_InventorySpdLmtSts_PMS_InventorySpdLmtSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_InventorySpdLmtSts_PMS_InventorySpdLmtSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_InventorySpdLmtSts_PMS_InventorySpdLmtSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_InventorySpdLmtSts_PMS_InventorySpdLmtSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_IsgModReq_PMS_IsgModReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IsgModReq_PMS_IsgModReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_IsgModReq_PMS_IsgModReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IsgModReq_PMS_IsgModReq.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_IsgTqReq_PMS_IsgTqReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IsgTqReq_PMS_IsgTqReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_IsgTqReq_PMS_IsgTqReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_IsgTqReq_PMS_IsgTqReq.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_LTCoolingFanFB_PMS_LTCoolingFanFB(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LTCoolingFanFB_PMS_LTCoolingFanFB.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_LTCoolingFanFB_PMS_LTCoolingFanFB() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LTCoolingFanFB_PMS_LTCoolingFanFB.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_Life_PMS_Life(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Life_PMS_Life.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_Life_PMS_Life() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Life_PMS_Life.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_LimpHomeSts_PMS_LimpHomeSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LimpHomeSts_PMS_LimpHomeSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_LimpHomeSts_PMS_LimpHomeSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LimpHomeSts_PMS_LimpHomeSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_LockLimResult_PMS_LockLimResult(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LockLimResult_PMS_LockLimResult.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_LockLimResult_PMS_LockLimResult() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LockLimResult_PMS_LockLimResult.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_LockVehExecutedSts_PMS_LockVehExecutedSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LockVehExecutedSts_PMS_LockVehExecutedSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_LockVehExecutedSts_PMS_LockVehExecutedSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LockVehExecutedSts_PMS_LockVehExecutedSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_LockVehPerFlag_PMS_LockVehPerFlag(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LockVehPerFlag_PMS_LockVehPerFlag.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_LockVehPerFlag_PMS_LockVehPerFlag() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LockVehPerFlag_PMS_LockVehPerFlag.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_LockVehPerRxSts_PMS_LockVehPerRxSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LockVehPerRxSts_PMS_LockVehPerRxSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_LockVehPerRxSts_PMS_LockVehPerRxSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LockVehPerRxSts_PMS_LockVehPerRxSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_LockVehSts_PMS_LockVehSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LockVehSts_PMS_LockVehSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_LockVehSts_PMS_LockVehSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LockVehSts_PMS_LockVehSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_LockVehType_PMS_LockVehType(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LockVehType_PMS_LockVehType.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_LockVehType_PMS_LockVehType() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_LockVehType_PMS_LockVehType.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_MCUActvdReq_PMS_MCUActvdReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MCUActvdReq_PMS_MCUActvdReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_MCUActvdReq_PMS_MCUActvdReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MCUActvdReq_PMS_MCUActvdReq.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_MCUFlowFeedback_EV_PMS_MCUFlowFeedback_EV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MCUFlowFeedback_EV_PMS_MCUFlowFeedback_EV.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_MCUFlowFeedback_EV_PMS_MCUFlowFeedback_EV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MCUFlowFeedback_EV_PMS_MCUFlowFeedback_EV.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_MCUTemp_EV_PMS_MCUTemp_EV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MCUTemp_EV_PMS_MCUTemp_EV.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_MCUTemp_EV_PMS_MCUTemp_EV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MCUTemp_EV_PMS_MCUTemp_EV.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_MHGV_EnableReq_PMS_MHGV_EnableReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_EnableReq_PMS_MHGV_EnableReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_MHGV_EnableReq_PMS_MHGV_EnableReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_EnableReq_PMS_MHGV_EnableReq.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_MHGV_EnableReq_LIN_PMS_MHGV_EnableReq_LIN(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_EnableReq_LIN_PMS_MHGV_EnableReq_LIN.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_MHGV_EnableReq_LIN_PMS_MHGV_EnableReq_LIN() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_EnableReq_LIN_PMS_MHGV_EnableReq_LIN.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_MHGV_PosSet_PMS_MHGV_PosSet(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_PosSet_PMS_MHGV_PosSet.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_MHGV_PosSet_PMS_MHGV_PosSet() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_PosSet_PMS_MHGV_PosSet.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_MHGV_PosSet_LIN_PMS_MHGV_PosSet_LIN(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_PosSet_LIN_PMS_MHGV_PosSet_LIN.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_MHGV_PosSet_LIN_PMS_MHGV_PosSet_LIN() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_PosSet_LIN_PMS_MHGV_PosSet_LIN.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_MHGV_ReqMotorEmgyStop_PMS_MHGV_ReqMotorEmgyStop(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_ReqMotorEmgyStop_PMS_MHGV_ReqMotorEmgyStop.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_MHGV_ReqMotorEmgyStop_PMS_MHGV_ReqMotorEmgyStop() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_ReqMotorEmgyStop_PMS_MHGV_ReqMotorEmgyStop.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_MHGV_ReqMotorEmgyStop_LIN_PMS_MHGV_ReqMotorEmgyStop_LIN(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_ReqMotorEmgyStop_LIN_PMS_MHGV_ReqMotorEmgyStop_LIN.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_MHGV_ReqMotorEmgyStop_LIN_PMS_MHGV_ReqMotorEmgyStop_LIN() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_ReqMotorEmgyStop_LIN_PMS_MHGV_ReqMotorEmgyStop_LIN.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_MHGV_ReqMotorOptRecovery_PMS_MHGV_ReqMotorOptRecovery(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_ReqMotorOptRecovery_PMS_MHGV_ReqMotorOptRecovery.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_MHGV_ReqMotorOptRecovery_PMS_MHGV_ReqMotorOptRecovery() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_ReqMotorOptRecovery_PMS_MHGV_ReqMotorOptRecovery.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_MHGV_ReqMotorOptRecovery_LIN_PMS_MHGV_ReqMotorOptRecovery_LIN(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_ReqMotorOptRecovery_LIN_PMS_MHGV_ReqMotorOptRecovery_LIN.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_MHGV_ReqMotorOptRecovery_LIN_PMS_MHGV_ReqMotorOptRecovery_LIN() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MHGV_ReqMotorOptRecovery_LIN_PMS_MHGV_ReqMotorOptRecovery_LIN.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_MaxPTTorqueAllowed_PMS_MaxPTTorqueAllowed(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MaxPTTorqueAllowed_PMS_MaxPTTorqueAllowed.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_MaxPTTorqueAllowed_PMS_MaxPTTorqueAllowed() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MaxPTTorqueAllowed_PMS_MaxPTTorqueAllowed.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_MinPTTorqueAllowed_PMS_MinPTTorqueAllowed(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MinPTTorqueAllowed_PMS_MinPTTorqueAllowed.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_MinPTTorqueAllowed_PMS_MinPTTorqueAllowed() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_MinPTTorqueAllowed_PMS_MinPTTorqueAllowed.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ModeControl_CheckSum_PMS_ModeControl_CheckSum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ModeControl_CheckSum_PMS_ModeControl_CheckSum.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ModeControl_CheckSum_PMS_ModeControl_CheckSum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ModeControl_CheckSum_PMS_ModeControl_CheckSum.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_NMSts_PMS_NMSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_NMSts_PMS_NMSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_NMSts_PMS_NMSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_NMSts_PMS_NMSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_OTAInstrucStsReminder_PMS_OTAInstrucStsReminder(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_OTAInstrucStsReminder_PMS_OTAInstrucStsReminder.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_OTAInstrucStsReminder_PMS_OTAInstrucStsReminder() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_OTAInstrucStsReminder_PMS_OTAInstrucStsReminder.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_OTAInstructRxnSts_PMS_OTAInstructRxnSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_OTAInstructRxnSts_PMS_OTAInstructRxnSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_OTAInstructRxnSts_PMS_OTAInstructRxnSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_OTAInstructRxnSts_PMS_OTAInstructRxnSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_Odometerbackup_PMS_Odometerbackup(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Odometerbackup_PMS_Odometerbackup.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_Odometerbackup_PMS_Odometerbackup() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Odometerbackup_PMS_Odometerbackup.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_OdometerbackupEnable_PMS_OdometerbackupEnable(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_OdometerbackupEnable_PMS_OdometerbackupEnable.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_OdometerbackupEnable_PMS_OdometerbackupEnable() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_OdometerbackupEnable_PMS_OdometerbackupEnable.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_PEPSAuth_PMS_PEPSAuth(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PEPSAuth_PMS_PEPSAuth.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_PEPSAuth_PMS_PEPSAuth() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PEPSAuth_PMS_PEPSAuth.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_PEPS_0x1E2_TimeoutFlag_PMS_PEPS_0x1E2_TimeoutFlag(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PEPS_0x1E2_TimeoutFlag_PMS_PEPS_0x1E2_TimeoutFlag.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_PEPS_0x1E2_TimeoutFlag_PMS_PEPS_0x1E2_TimeoutFlag() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PEPS_0x1E2_TimeoutFlag_PMS_PEPS_0x1E2_TimeoutFlag.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_PEPS_PowerMode_PMS_PEPS_PowerMode(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PEPS_PowerMode_PMS_PEPS_PowerMode.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_PEPS_PowerMode_PMS_PEPS_PowerMode() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PEPS_PowerMode_PMS_PEPS_PowerMode.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_PEPS_PowerModeValidity_PMS_PEPS_PowerModeValidity(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PEPS_PowerModeValidity_PMS_PEPS_PowerModeValidity.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_PEPS_PowerModeValidity_PMS_PEPS_PowerModeValidity() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PEPS_PowerModeValidity_PMS_PEPS_PowerModeValidity.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_PTC1ConnStsFb_PMS_PTC1ConnStsFb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTC1ConnStsFb_PMS_PTC1ConnStsFb.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_PTC1ConnStsFb_PMS_PTC1ConnStsFb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTC1ConnStsFb_PMS_PTC1ConnStsFb.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_PTC1RelayFlt_PMS_PTC1RelayFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTC1RelayFlt_PMS_PTC1RelayFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_PTC1RelayFlt_PMS_PTC1RelayFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTC1RelayFlt_PMS_PTC1RelayFlt.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_PTC2Enable_PMS_PTC2Enable(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTC2Enable_PMS_PTC2Enable.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_PTC2Enable_PMS_PTC2Enable() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTC2Enable_PMS_PTC2Enable.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_PTC3ConnStsFb_PMS_PTC3ConnStsFb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTC3ConnStsFb_PMS_PTC3ConnStsFb.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_PTC3ConnStsFb_PMS_PTC3ConnStsFb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTC3ConnStsFb_PMS_PTC3ConnStsFb.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_PTC3Enable_PMS_PTC3Enable(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTC3Enable_PMS_PTC3Enable.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_PTC3Enable_PMS_PTC3Enable() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTC3Enable_PMS_PTC3Enable.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_PTC3RelayFlt_PMS_PTC3RelayFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTC3RelayFlt_PMS_PTC3RelayFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_PTC3RelayFlt_PMS_PTC3RelayFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTC3RelayFlt_PMS_PTC3RelayFlt.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_PTCEnable_PMS_PTCEnable(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTCEnable_PMS_PTCEnable.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_PTCEnable_PMS_PTCEnable() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTCEnable_PMS_PTCEnable.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_PTCRelayVoltSampSwich_PMS_PTCRelayVoltSampSwich(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTCRelayVoltSampSwich_PMS_PTCRelayVoltSampSwich.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_PTCRelayVoltSampSwich_PMS_PTCRelayVoltSampSwich() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTCRelayVoltSampSwich_PMS_PTCRelayVoltSampSwich.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_PowerOffCmdRxSts_PMS_PowerOffCmdRxSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PowerOffCmdRxSts_PMS_PowerOffCmdRxSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_PowerOffCmdRxSts_PMS_PowerOffCmdRxSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PowerOffCmdRxSts_PMS_PowerOffCmdRxSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_PowerOffCmdSts_PMS_PowerOffCmdSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PowerOffCmdSts_PMS_PowerOffCmdSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_PowerOffCmdSts_PMS_PowerOffCmdSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PowerOffCmdSts_PMS_PowerOffCmdSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_PreAccessoryConnStsFb_PMS_PreAccessoryConnStsFb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PreAccessoryConnStsFb_PMS_PreAccessoryConnStsFb.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_PreAccessoryConnStsFb_PMS_PreAccessoryConnStsFb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PreAccessoryConnStsFb_PMS_PreAccessoryConnStsFb.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_PreAccessoryRelayFlt_PMS_PreAccessoryRelayFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PreAccessoryRelayFlt_PMS_PreAccessoryRelayFlt.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_PreAccessoryRelayFlt_PMS_PreAccessoryRelayFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_PreAccessoryRelayFlt_PMS_PreAccessoryRelayFlt.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_Real_PedalPosition_PMS_Real_PedalPosition(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Real_PedalPosition_PMS_Real_PedalPosition.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_Real_PedalPosition_PMS_Real_PedalPosition() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Real_PedalPosition_PMS_Real_PedalPosition.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_RegenTarTrqPot_PMS_RegenTarTrqPot(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RegenTarTrqPot_PMS_RegenTarTrqPot.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_RegenTarTrqPot_PMS_RegenTarTrqPot() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RegenTarTrqPot_PMS_RegenTarTrqPot.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_RegenTarTrqPotQualifier_PMS_RegenTarTrqPotQualifier(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RegenTarTrqPotQualifier_PMS_RegenTarTrqPotQualifier.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_RegenTarTrqPotQualifier_PMS_RegenTarTrqPotQualifier() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RegenTarTrqPotQualifier_PMS_RegenTarTrqPotQualifier.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_RegenTrqAct_PMS_RegenTrqAct(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RegenTrqAct_PMS_RegenTrqAct.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_RegenTrqAct_PMS_RegenTrqAct() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RegenTrqAct_PMS_RegenTrqAct.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_RegenTrqActQualifier_PMS_RegenTrqActQualifier(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RegenTrqActQualifier_PMS_RegenTrqActQualifier.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_RegenTrqActQualifier_PMS_RegenTrqActQualifier() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RegenTrqActQualifier_PMS_RegenTrqActQualifier.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_RegenTrqPot_PMS_RegenTrqPot(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RegenTrqPot_PMS_RegenTrqPot.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_RegenTrqPot_PMS_RegenTrqPot() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RegenTrqPot_PMS_RegenTrqPot.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_RegenTrqPotQualifier_PMS_RegenTrqPotQualifier(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RegenTrqPotQualifier_PMS_RegenTrqPotQualifier.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_RegenTrqPotQualifier_PMS_RegenTrqPotQualifier() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RegenTrqPotQualifier_PMS_RegenTrqPotQualifier.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_RegulationSpeed_PMS_PMS_RegulationSpeed_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RegulationSpeed_PMS_PMS_RegulationSpeed_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_RegulationSpeed_PMS_PMS_RegulationSpeed_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RegulationSpeed_PMS_PMS_RegulationSpeed_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_RemChrgCmdFailrPrompt_PMS_RemChrgCmdFailrPrompt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RemChrgCmdFailrPrompt_PMS_RemChrgCmdFailrPrompt.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_RemChrgCmdFailrPrompt_PMS_RemChrgCmdFailrPrompt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RemChrgCmdFailrPrompt_PMS_RemChrgCmdFailrPrompt.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ReqSeed_PMS_ReqSeed(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ReqSeed_PMS_ReqSeed.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ReqSeed_PMS_ReqSeed() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ReqSeed_PMS_ReqSeed.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_RespResult_PMS_RespResult(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RespResult_PMS_RespResult.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_RespResult_PMS_RespResult() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_RespResult_PMS_RespResult.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_SelfCheckSts_PMS_SelfCheckSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_SelfCheckSts_PMS_SelfCheckSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_SelfCheckSts_PMS_SelfCheckSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_SelfCheckSts_PMS_SelfCheckSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_SlidingmomentrSetReq_PMS_SlidingmomentrSetReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_SlidingmomentrSetReq_PMS_SlidingmomentrSetReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_SlidingmomentrSetReq_PMS_SlidingmomentrSetReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_SlidingmomentrSetReq_PMS_SlidingmomentrSetReq.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_SoftwareMajorVer_PMS_SoftwareMajorVer(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_SoftwareMajorVer_PMS_SoftwareMajorVer.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_SoftwareMajorVer_PMS_SoftwareMajorVer() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_SoftwareMajorVer_PMS_SoftwareMajorVer.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_SoftwareMinorVer_PMS_SoftwareMinorVer(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_SoftwareMinorVer_PMS_SoftwareMinorVer.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_SoftwareMinorVer_PMS_SoftwareMinorVer() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_SoftwareMinorVer_PMS_SoftwareMinorVer.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_SpdLmtLevel_PMS_SpdLmtLevel(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_SpdLmtLevel_PMS_SpdLmtLevel.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_SpdLmtLevel_PMS_SpdLmtLevel() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_SpdLmtLevel_PMS_SpdLmtLevel.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_SpdLmtLevelRxSts_PMS_SpdLmtLevelRxSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_SpdLmtLevelRxSts_PMS_SpdLmtLevelRxSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_SpdLmtLevelRxSts_PMS_SpdLmtLevelRxSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_SpdLmtLevelRxSts_PMS_SpdLmtLevelRxSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_StartActive_PMS_StartActive(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_StartActive_PMS_StartActive.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_StartActive_PMS_StartActive() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_StartActive_PMS_StartActive.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_Stayawake_reasons_PMS_Stayawake_reasons(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Stayawake_reasons_PMS_Stayawake_reasons.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_Stayawake_reasons_PMS_Stayawake_reasons() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Stayawake_reasons_PMS_Stayawake_reasons.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_StsBrkSwitch1_PMS_StsBrkSwitch1(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_StsBrkSwitch1_PMS_StsBrkSwitch1.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_StsBrkSwitch1_PMS_StsBrkSwitch1() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_StsBrkSwitch1_PMS_StsBrkSwitch1.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_StsBrkSwitch1Invalid_PMS_StsBrkSwitch1Invalid(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_StsBrkSwitch1Invalid_PMS_StsBrkSwitch1Invalid.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_StsBrkSwitch1Invalid_PMS_StsBrkSwitch1Invalid() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_StsBrkSwitch1Invalid_PMS_StsBrkSwitch1Invalid.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_StsBrkSwitch1Invalid_PMS_PMS_StsBrkSwitch1Invalid_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_StsBrkSwitch1Invalid_PMS_PMS_StsBrkSwitch1Invalid_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_StsBrkSwitch1Invalid_PMS_PMS_StsBrkSwitch1Invalid_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_StsBrkSwitch1Invalid_PMS_PMS_StsBrkSwitch1Invalid_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_StsBrkSwitch1_PMS_PMS_StsBrkSwitch1_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_StsBrkSwitch1_PMS_PMS_StsBrkSwitch1_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_StsBrkSwitch1_PMS_PMS_StsBrkSwitch1_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_StsBrkSwitch1_PMS_PMS_StsBrkSwitch1_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_StsSwap_PMS_StsSwap(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_StsSwap_PMS_StsSwap.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_StsSwap_PMS_StsSwap() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_StsSwap_PMS_StsSwap.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_SwapAuthRelease_EV_PMS_SwapAuthRelease_EV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_SwapAuthRelease_EV_PMS_SwapAuthRelease_EV.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_SwapAuthRelease_EV_PMS_SwapAuthRelease_EV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_SwapAuthRelease_EV_PMS_SwapAuthRelease_EV.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_TBOX_BrkSysErr_PMS_TBOX_BrkSysErr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TBOX_BrkSysErr_PMS_TBOX_BrkSysErr.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_TBOX_BrkSysErr_PMS_TBOX_BrkSysErr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TBOX_BrkSysErr_PMS_TBOX_BrkSysErr.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_TBOX_BrkSysErr1_PMS_PMS_TBOX_BrkSysErr1_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TBOX_BrkSysErr1_PMS_PMS_TBOX_BrkSysErr1_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_TBOX_BrkSysErr1_PMS_PMS_TBOX_BrkSysErr1_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TBOX_BrkSysErr1_PMS_PMS_TBOX_BrkSysErr1_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_TBOX_HVILState_PMS_TBOX_HVILState(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TBOX_HVILState_PMS_TBOX_HVILState.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_TBOX_HVILState_PMS_TBOX_HVILState() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TBOX_HVILState_PMS_TBOX_HVILState.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_TBOX_HVILState_3A1_PMS_TBOX_HVILState_3A1(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TBOX_HVILState_3A1_PMS_TBOX_HVILState_3A1.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_TBOX_HVILState_3A1_PMS_TBOX_HVILState_3A1() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TBOX_HVILState_3A1_PMS_TBOX_HVILState_3A1.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_TBOX_HVILSts_PMS_TBOX_HVILSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TBOX_HVILSts_PMS_TBOX_HVILSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_TBOX_HVILSts_PMS_TBOX_HVILSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TBOX_HVILSts_PMS_TBOX_HVILSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_TBOX_HVILSts1_PMS_PMS_TBOX_HVILSts1_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TBOX_HVILSts1_PMS_PMS_TBOX_HVILSts1_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_TBOX_HVILSts1_PMS_PMS_TBOX_HVILSts1_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TBOX_HVILSts1_PMS_PMS_TBOX_HVILSts1_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_TBOX_LifeSts_PMS_TBOX_LifeSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TBOX_LifeSts_PMS_TBOX_LifeSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_TBOX_LifeSts_PMS_TBOX_LifeSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TBOX_LifeSts_PMS_TBOX_LifeSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_TakeEleSwtIndReq_PMS_TakeEleSwtIndReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TakeEleSwtIndReq_PMS_TakeEleSwtIndReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_TakeEleSwtIndReq_PMS_TakeEleSwtIndReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TakeEleSwtIndReq_PMS_TakeEleSwtIndReq.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ThermalReq_PMS_ThermalReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ThermalReq_PMS_ThermalReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ThermalReq_PMS_ThermalReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ThermalReq_PMS_ThermalReq.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_Torque_Ovrd_Active_PMS_Torque_Ovrd_Active(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Torque_Ovrd_Active_PMS_Torque_Ovrd_Active.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_Torque_Ovrd_Active_PMS_Torque_Ovrd_Active() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Torque_Ovrd_Active_PMS_Torque_Ovrd_Active.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_Torque_Ovrd_Type_PMS_Torque_Ovrd_Type(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Torque_Ovrd_Type_PMS_Torque_Ovrd_Type.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_Torque_Ovrd_Type_PMS_Torque_Ovrd_Type() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Torque_Ovrd_Type_PMS_Torque_Ovrd_Type.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_TurtleLampOn_PMS_TurtleLampOn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TurtleLampOn_PMS_TurtleLampOn.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_TurtleLampOn_PMS_TurtleLampOn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TurtleLampOn_PMS_TurtleLampOn.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_TurtleLampOn2_PMS_TurtleLampOn2(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TurtleLampOn2_PMS_TurtleLampOn2.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_TurtleLampOn2_PMS_TurtleLampOn2() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_TurtleLampOn2_PMS_TurtleLampOn2.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_V2XDchaSwtFb1_PMS_V2XDchaSwtFb1(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_V2XDchaSwtFb1_PMS_V2XDchaSwtFb1.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_V2XDchaSwtFb1_PMS_V2XDchaSwtFb1() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_V2XDchaSwtFb1_PMS_V2XDchaSwtFb1.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_VINCode1_8_15_S_PMS_VINCode1_8_15_S(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINCode1_8_15_S_PMS_VINCode1_8_15_S.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_VINCode1_8_15_S_PMS_VINCode1_8_15_S() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINCode1_8_15_S_PMS_VINCode1_8_15_S.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_VINCode2_9_16_S_PMS_VINCode2_9_16_S(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINCode2_9_16_S_PMS_VINCode2_9_16_S.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_VINCode2_9_16_S_PMS_VINCode2_9_16_S() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINCode2_9_16_S_PMS_VINCode2_9_16_S.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_VINCode3_10_17_S_PMS_VINCode3_10_17_S(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINCode3_10_17_S_PMS_VINCode3_10_17_S.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_VINCode3_10_17_S_PMS_VINCode3_10_17_S() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINCode3_10_17_S_PMS_VINCode3_10_17_S.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_VINCode4_11_S_PMS_VINCode4_11_S(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINCode4_11_S_PMS_VINCode4_11_S.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_VINCode4_11_S_PMS_VINCode4_11_S() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINCode4_11_S_PMS_VINCode4_11_S.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_VINCode5_12_S_PMS_VINCode5_12_S(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINCode5_12_S_PMS_VINCode5_12_S.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_VINCode5_12_S_PMS_VINCode5_12_S() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINCode5_12_S_PMS_VINCode5_12_S.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_VINCode6_13_S_PMS_VINCode6_13_S(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINCode6_13_S_PMS_VINCode6_13_S.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_VINCode6_13_S_PMS_VINCode6_13_S() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINCode6_13_S_PMS_VINCode6_13_S.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_VINCode7_14_S_PMS_VINCode7_14_S(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINCode7_14_S_PMS_VINCode7_14_S.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_VINCode7_14_S_PMS_VINCode7_14_S() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINCode7_14_S_PMS_VINCode7_14_S.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_VINMessageNum_S_PMS_VINMessageNum_S(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINMessageNum_S_PMS_VINMessageNum_S.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_VINMessageNum_S_PMS_VINMessageNum_S() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VINMessageNum_S_PMS_VINMessageNum_S.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_VacuumPressure_PMS_VacuumPressure(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VacuumPressure_PMS_VacuumPressure.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_VacuumPressure_PMS_VacuumPressure() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VacuumPressure_PMS_VacuumPressure.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_VacuumPumpCmd_PMS_VacuumPumpCmd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VacuumPumpCmd_PMS_VacuumPumpCmd.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_VacuumPumpCmd_PMS_VacuumPumpCmd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VacuumPumpCmd_PMS_VacuumPumpCmd.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_VacuumPump_FB_PMS_VacuumPump_FB(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VacuumPump_FB_PMS_VacuumPump_FB.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_VacuumPump_FB_PMS_VacuumPump_FB() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VacuumPump_FB_PMS_VacuumPump_FB.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_VacuumSystemsta_PMS_VacuumSystemsta(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VacuumSystemsta_PMS_VacuumSystemsta.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_VacuumSystemsta_PMS_VacuumSystemsta() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VacuumSystemsta_PMS_VacuumSystemsta.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_VehicleSpeed_PMS_VehicleSpeed(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VehicleSpeed_PMS_VehicleSpeed.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_VehicleSpeed_PMS_VehicleSpeed() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VehicleSpeed_PMS_VehicleSpeed.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_VehicleSysErrorLevel_PMS_VehicleSysErrorLevel(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VehicleSysErrorLevel_PMS_VehicleSysErrorLevel.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_VehicleSysErrorLevel_PMS_VehicleSysErrorLevel() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VehicleSysErrorLevel_PMS_VehicleSysErrorLevel.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_VehicleSysErrorLevelG_PMS_VehicleSysErrorLevelG(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VehicleSysErrorLevelG_PMS_VehicleSysErrorLevelG.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_VehicleSysErrorLevelG_PMS_VehicleSysErrorLevelG() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VehicleSysErrorLevelG_PMS_VehicleSysErrorLevelG.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_VehicleSysErrorLevelG1_PMS_PMS_VehicleSysErrorLevelG1_PMS(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VehicleSysErrorLevelG1_PMS_PMS_VehicleSysErrorLevelG1_PMS.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_VehicleSysErrorLevelG1_PMS_PMS_VehicleSysErrorLevelG1_PMS() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VehicleSysErrorLevelG1_PMS_PMS_VehicleSysErrorLevelG1_PMS.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_VersionConversionFlag_PMS_VersionConversionFlag(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VersionConversionFlag_PMS_VersionConversionFlag.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_VersionConversionFlag_PMS_VersionConversionFlag() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VersionConversionFlag_PMS_VersionConversionFlag.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_VersionConversionRxSts_PMS_VersionConversionRxSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VersionConversionRxSts_PMS_VersionConversionRxSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_VersionConversionRxSts_PMS_VersionConversionRxSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_VersionConversionRxSts_PMS_VersionConversionRxSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_Wakeup_reasons_PMS_Wakeup_reasons(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Wakeup_reasons_PMS_Wakeup_reasons.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_Wakeup_reasons_PMS_Wakeup_reasons() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_Wakeup_reasons_PMS_Wakeup_reasons.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ePTFault_PMS_ePTFault(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTFault_PMS_ePTFault.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ePTFault_PMS_ePTFault() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTFault_PMS_ePTFault.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ePTFault2_PMS_ePTFault2(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTFault2_PMS_ePTFault2.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ePTFault2_PMS_ePTFault2() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTFault2_PMS_ePTFault2.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ePTModeActual_PMS_ePTModeActual(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTModeActual_PMS_ePTModeActual.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ePTModeActual_PMS_ePTModeActual() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTModeActual_PMS_ePTModeActual.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ePTModeSelect_PMS_ePTModeSelect(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTModeSelect_PMS_ePTModeSelect.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ePTModeSelect_PMS_ePTModeSelect() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTModeSelect_PMS_ePTModeSelect.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ePTReady_PMS_ePTReady(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTReady_PMS_ePTReady.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ePTReady_PMS_ePTReady() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTReady_PMS_ePTReady.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ePTReady_EV_PMS_ePTReady_EV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTReady_EV_PMS_ePTReady_EV.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ePTReady_EV_PMS_ePTReady_EV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTReady_EV_PMS_ePTReady_EV.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ePTRegencyLevInd_PMS_ePTRegencyLevInd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTRegencyLevInd_PMS_ePTRegencyLevInd.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ePTRegencyLevInd_PMS_ePTRegencyLevInd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTRegencyLevInd_PMS_ePTRegencyLevInd.value \
)

#define Rte_IWrite_swc_VCOP_Step_PMS_ePTReleaseSig_PMS_ePTReleaseSig(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTReleaseSig_PMS_ePTReleaseSig.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_PMS_ePTReleaseSig_PMS_ePTReleaseSig() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_PMS_ePTReleaseSig_PMS_ePTReleaseSig.value \
)

#define Rte_IWrite_swc_VCOP_Step_TBOX_ChrgSoftSwCtrlst_EV_TBOX_ChrgSoftSwCtrlst_EV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_TBOX_ChrgSoftSwCtrlst_EV_TBOX_ChrgSoftSwCtrlst_EV.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_TBOX_ChrgSoftSwCtrlst_EV_TBOX_ChrgSoftSwCtrlst_EV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_TBOX_ChrgSoftSwCtrlst_EV_TBOX_ChrgSoftSwCtrlst_EV.value \
)

#define Rte_IWrite_swc_VCOP_Step_TBOX_ReservationChrgnSts_EV_TBOX_ReservationChrgnSts_EV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_TBOX_ReservationChrgnSts_EV_TBOX_ReservationChrgnSts_EV.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_TBOX_ReservationChrgnSts_EV_TBOX_ReservationChrgnSts_EV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_TBOX_ReservationChrgnSts_EV_TBOX_ReservationChrgnSts_EV.value \
)

#define Rte_IWrite_swc_VCOP_Step_VCU_ActInputVolt_VCU_ActInputVolt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_ActInputVolt_VCU_ActInputVolt.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_VCU_ActInputVolt_VCU_ActInputVolt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_ActInputVolt_VCU_ActInputVolt.value \
)

#define Rte_IWrite_swc_VCOP_Step_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax.value \
)

#define Rte_IWrite_swc_VCOP_Step_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter.value \
)

#define Rte_IWrite_swc_VCOP_Step_VCU_BMSH_Ctrl_CheckSum_VCU_BMSH_Ctrl_CheckSum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_BMSH_Ctrl_CheckSum_VCU_BMSH_Ctrl_CheckSum.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_VCU_BMSH_Ctrl_CheckSum_VCU_BMSH_Ctrl_CheckSum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_BMSH_Ctrl_CheckSum_VCU_BMSH_Ctrl_CheckSum.value \
)

#define Rte_IWrite_swc_VCOP_Step_VCU_BMSH_DCChgRelayVolt_VCU_BMSH_DCChgRelayVolt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_BMSH_DCChgRelayVolt_VCU_BMSH_DCChgRelayVolt.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_VCU_BMSH_DCChgRelayVolt_VCU_BMSH_DCChgRelayVolt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_BMSH_DCChgRelayVolt_VCU_BMSH_DCChgRelayVolt.value \
)

#define Rte_IWrite_swc_VCOP_Step_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp.value \
)

#define Rte_IWrite_swc_VCOP_Step_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp.value \
)

#define Rte_IWrite_swc_VCOP_Step_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq.value \
)

#define Rte_IWrite_swc_VCOP_Step_VCU_ChargeDepthReq_VCU_ChargeDepthReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_ChargeDepthReq_VCU_ChargeDepthReq.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_VCU_ChargeDepthReq_VCU_ChargeDepthReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_ChargeDepthReq_VCU_ChargeDepthReq.value \
)

#define Rte_IWrite_swc_VCOP_Step_VCU_CrashOutputSts_VCU_CrashOutputSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_CrashOutputSts_VCU_CrashOutputSts.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_VCU_CrashOutputSts_VCU_CrashOutputSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_CrashOutputSts_VCU_CrashOutputSts.value \
)

#define Rte_IWrite_swc_VCOP_Step_VCU_DCInputCurrent_VCU_DCInputCurrent(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_DCInputCurrent_VCU_DCInputCurrent.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_VCU_DCInputCurrent_VCU_DCInputCurrent() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_DCInputCurrent_VCU_DCInputCurrent.value \
)

#define Rte_IWrite_swc_VCOP_Step_VCU_Odometerbackup_VCU_Odometerbackup(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_Odometerbackup_VCU_Odometerbackup.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_VCU_Odometerbackup_VCU_Odometerbackup() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_Odometerbackup_VCU_Odometerbackup.value \
)

#define Rte_IWrite_swc_VCOP_Step_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual.value \
)

#define Rte_IWrite_swc_VCOP_Step_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter.value \
)

#define Rte_IWrite_swc_VCOP_Step_VCU_VehicleInfo_CheckSum_VCU_VehicleInfo_CheckSum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_VehicleInfo_CheckSum_VCU_VehicleInfo_CheckSum.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_VCU_VehicleInfo_CheckSum_VCU_VehicleInfo_CheckSum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_VCU_VehicleInfo_CheckSum_VCU_VehicleInfo_CheckSum.value \
)

#define Rte_IWrite_swc_VCOP_Step_st_ShtDown_st_ShtDown(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_st_ShtDown_st_ShtDown.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_st_ShtDown_st_ShtDown() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_st_ShtDown_st_ShtDown.value \
)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_accd_b_acHvilOpn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_accd_b_acHvilOpn.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_accd_b_acHvilOpnInvld() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_accd_b_acHvilOpnInvld.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_acpd_b_accPedlPosVld() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_acpd_b_accPedlPosVld.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_acpd_x_accPedlPosCan_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_acpd_x_accPedlPosCan_pct.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_acpd_x_accPedlPosSens1_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_acpd_x_accPedlPosSens1_pct.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_acpd_x_accPedlPosSens2_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_acpd_x_accPedlPosSens2_pct.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_adcd_b_adcCtrlGearEn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_adcd_b_adcCtrlGearEn.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_adcd_st_pmsAdcCtrldSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_adcd_st_pmsAdcCtrldSts.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_adcd_st_pmsCanBusRecSta() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_adcd_st_pmsCanBusRecSta.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_brpd_b_brkPressedFromSwitch() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_brpd_b_brkPressedFromSwitch.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_brpd_p_brkVacuumPres_bar() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_brpd_p_brkVacuumPres_bar.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_brpd_x_brkPedlPos_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_brpd_x_brkPedlPos_pct.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_cesd_b_acuCrash() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_cesd_b_acuCrash.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_dccd_b_dcdcHvilFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_dccd_b_dcdcHvilFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_dccd_b_dcdcHvilFltInvld() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_dccd_b_dcdcHvilFltInvld.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_drid_st_gearLvrPosSeql() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_drid_st_gearLvrPosSeql.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_eadd_n_mot2ActSpd_rpm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_eadd_n_mot2ActSpd_rpm.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_eadd_tq_mot2ActTq_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_eadd_tq_mot2ActTq_Nm.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_eadd_u_busInv2HVAct_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_eadd_u_busInv2HVAct_V.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_epbd_e_parkingSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_epbd_e_parkingSts.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_b_hvilOpen() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_b_hvilOpen.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_e_hvbStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_e_hvbStatus.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_fact_hvbSOH_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_fact_hvbSOH_pct.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_i_hvbCurr_A() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_i_hvbCurr_A.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_pwr_hvbChgPwr_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_pwr_hvbChgPwr_kW.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_q_hvbSOC_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_q_hvbSOC_pct.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_st_hvbThermMngReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_st_hvbThermMngReq.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_st_tboxIntelChgQuit() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_st_tboxIntelChgQuit.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_t_hvbAvg_C() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_t_hvbAvg_C.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_t_hvbInCoolTemp_C() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_t_hvbInCoolTemp_C.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_t_hvbMin_C() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_t_hvbMin_C.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_t_hvbTemp_C() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_hvbd_t_hvbTemp_C.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_macd_b_vcuSelfChkOk() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_macd_b_vcuSelfChkOk.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_macd_t_ts5SnsrTemp_C() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_macd_t_ts5SnsrTemp_C.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_macd_u_batIntSmpl_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_macd_u_batIntSmpl_V.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_pmmd_b_ignOn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_tmmd_n_motActSpd_rpm() \
  (0.0F)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_tmmd_tq_motActTq_Nm() \
  (0.0F)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_trad_fact_trsm2GearRat() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_trad_fact_trsm2GearRat.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_trad_st_trsm2GearAct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_trad_st_trsm2GearAct.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_R_posInsIRes_Ohm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_R_posInsIRes_Ohm.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_ang_strWhlAng_rad() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_ang_strWhlAng_rad.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_AccyEnReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_AccyEnReq.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_AccyFltSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_AccyFltSts.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_CCSginal() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_CCSginal.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_DryAirSwitch() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_DryAirSwitch.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_ResrAirSwitch() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_ResrAirSwitch.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_brkSwt1Actv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_brkSwt1Actv.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_brkSwt2Actv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_brkSwt2Actv.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_cntnrCtrlEnaFb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_cntnrCtrlEnaFb.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_dcdcStsAlm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_dcdcStsAlm.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_dcdcTempAlm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_dcdcTempAlm.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_disChgSwtSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_disChgSwtSt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_driverEVModeReq() \
  (FALSE)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_driverEcoModeReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_driverEcoModeReq.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_emgyStopIn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_emgyStopIn.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_flgFctCfgBatCol() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_flgFctCfgBatCol.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_fwfvCcwFlg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_fwfvCcwFlg.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_fwfvInitSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_fwfvInitSts.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_fwfvMotSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_fwfvMotSts.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_fwfvOvrCurrFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_fwfvOvrCurrFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_fwfvOvrTempFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_fwfvOvrTempFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_fwfvOvrVoltFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_fwfvOvrVoltFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_fwfvRespErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_fwfvRespErr.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_fwfvUndVoltFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_fwfvUndVoltFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_hvbHvilFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_hvbHvilFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_ignStsOn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_ignStsOn.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_ignStsStrt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_ignStsStrt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_mhgvCcwFlg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_mhgvCcwFlg.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_mhgvInitSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_mhgvInitSts.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_mhgvMotSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_mhgvMotSts.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_mhgvOvrCurrFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_mhgvOvrCurrFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_mhgvOvrTempFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_mhgvOvrTempFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_mhgvOvrVoltFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_mhgvOvrVoltFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_mhgvRespErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_mhgvRespErr.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_mhgvUndVoltFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_mhgvUndVoltFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_obcWakeUpActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_obcWakeUpActv.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_odometerInvalid() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_b_odometerInvalid.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_d_odometer_km() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_d_odometer_km.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_i_dcdcInpCurr_A() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_i_dcdcInpCurr_A.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_i_hvbCurr_A() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_i_hvbCurr_A.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_num_hvbCellMaxID() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_num_hvbCellMaxID.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_num_hvbCellMinID() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_num_hvbCellMinID.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_num_hvbCellSum() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_num_hvbCellSum.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_num_hvbMaxTempID() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_num_hvbMaxTempID.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_num_hvbMinTempID() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_num_hvbMinTempID.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_num_hvbTempSum() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_num_hvbTempSum.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_pct_GearPosn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_pct_GearPosn.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_pct_HVILReturnPWM() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_pct_HVILReturnPWM.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_pct_WatPmpEP1FbPWM() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_pct_WatPmpEP1FbPWM.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_pct_WatPmpEP2FbPWM() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_pct_WatPmpEP2FbPWM.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_pct_WatPmpEP3FbPWM() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_pct_WatPmpEP3FbPWM.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_pct_fan1Fb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_pct_fan1Fb.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_pct_fan2Fb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_pct_fan2Fb.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_pct_fwfvCrtPos() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_pct_fwfvCrtPos.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_pct_mhgvCrtPos() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_pct_mhgvCrtPos.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_24vDcdcModAct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_24vDcdcModAct.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_BmsTempOutOfCtrlFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_BmsTempOutOfCtrlFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_actWorkSts1() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_actWorkSts1.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_batLowSoc2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_batLowSoc2.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_batOvrSoc2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_batOvrSoc2.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_batOvrVolt2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_batOvrVolt2.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_batUdrVolt2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_batUdrVolt2.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_bmsBattPackMatchFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_bmsBattPackMatchFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_bmsBattPackNum() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_bmsBattPackNum.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_bmsBattSysNum() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_bmsBattSysNum.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_bmsTboxFireAlm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_bmsTboxFireAlm.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_cellOverVolt2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_cellOverVolt2.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_cellUdrVolt2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_cellUdrVolt2.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_dcChgCcSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_dcChgCcSt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_eadInv2TempHiAlrm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_eadInv2TempHiAlrm.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_ehbBrkSysErrFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_ehbBrkSysErrFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_epsEpasFail() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_epsEpasFail.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_flg2FctCfgVehTyp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_flg2FctCfgVehTyp.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_flgFctCfgAccy() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgAccy.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbBatUniformity() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbBatUniformity.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbBattIsolationSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbBattIsolationSts.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbCellTempDevFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbCellTempDevFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbCellVoltDevFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbCellVoltDevFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbChgOvrCurr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbChgOvrCurr.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbDCChgPlgNOvrTmp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbDCChgPlgNOvrTmp.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbDCChgPlgPOvrTmp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbDCChgPlgPOvrTmp.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbDCChgProcss() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbDCChgProcss.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbInslErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbInslErr.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbOvrChgFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbOvrChgFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbSocFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbSocFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbSocJumpFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbSocJumpFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbStatus.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbStsChgFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbStsChgFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbStsDischgFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbStsDischgFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbTempFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbTempFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbThermMngReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_hvbThermMngReq.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_ipuInvTempHighAlm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_ipuInvTempHighAlm.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_ipuMotTempHighFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_ipuMotTempHighFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_ipuMotorOverCurrFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_ipuMotorOverCurrFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_ipuMotorOverSpdFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_ipuMotorOverSpdFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_obcChgSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_obcChgSts.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_obcOnBdCCline() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_obcOnBdCCline.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_pepsPduLvl() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_pepsPduLvl.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_pepsPduLvlVld() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_pepsPduLvlVld.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_tboxRsrChgSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_st_tboxRsrChgSt.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_t_acwpOutptTemp_C() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_t_acwpOutptTemp_C.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_t_hvbCooltInTemp_C() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_t_hvbCooltInTemp_C.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_t_hvbCooltOutTemp_C() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_t_hvbCooltOutTemp_C.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_t_hvbMax_C() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_t_hvbMax_C.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_t_hvbMin_C() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_t_hvbMin_C.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_t_hvbOutCoolTemp_C() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_t_hvbOutCoolTemp_C.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_t_hvbSetTgtTemp_C() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_t_hvbSetTgtTemp_C.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_tm_hvbFnshChgTim_m() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_tm_hvbFnshChgTim_m.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_BmsMaxCellVolt_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_BmsMaxCellVolt_V.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_BmsMinCellVolt_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_BmsMinCellVolt_V.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_Brk2_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_Brk2_V.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_Brk_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_Brk_V.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_TS5sensorFb_mV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_TS5sensorFb_mV.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_VacTkEnFb_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_VacTkEnFb_V.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_accPdlSens1InpVolt_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_accPdlSens1InpVolt_V.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_accPdlSens2InpVolt_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_accPdlSens2InpVolt_V.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_dcdcRelayVolt_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_dcdcRelayVolt_V.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_hvbCooltInSnsr_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_hvbCooltInSnsr_V.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_hvbCooltOutSnsr_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_hvbCooltOutSnsr_V.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_hvbPackVolt_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_hvbPackVolt_V.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_hvbVolt_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_hvbVolt_V.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_ipuHVBusVolt_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vild_u_ipuHVBusVolt_V.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vscd_a_vscLongitAcce_mps2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vscd_a_vscLongitAcce_mps2.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vscd_b_ESPActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vscd_b_ESPActv.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vscd_b_vehSpdVld() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vscd_b_vehSpdVld.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vscd_b_vscBrkLghtActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vscd_b_vscBrkLghtActv.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vscd_st_vscIsgActvDampModReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vscd_st_vscIsgActvDampModReq.value)

#define Rte_IRead_swc_VCOP_Step_vcib_VCIP_vscd_v_vehSpdRaw_kph() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcib_VCIP_vscd_v_vehSpdRaw_kph.value)

#define Rte_IWrite_swc_VCOP_Step_vcob_VCOP_BMSH_ChargeLEDCtrl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcob_VCOP_BMSH_ChargeLEDCtrl.value = (data) \
)

#define Rte_IWriteRef_swc_VCOP_Step_vcob_VCOP_BMSH_ChargeLEDCtrl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcob_VCOP_BMSH_ChargeLEDCtrl.value \
)

#define Rte_IRead_swc_VCOP_Step_vcsb_ATAU_pmmd_b_ePTRelease_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_ATAU_pmmd_b_ePTRelease_flg.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_AUXC_brpd_b_VacPumpRlyEn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_AUXC_brpd_b_VacPumpRlyEn.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_AUXC_brpd_b_brkPmp1Rly() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_AUXC_brpd_b_brkPmp1Rly.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_AUXC_brpd_p_VacPumpPressure_kPa() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_AUXC_brpd_p_VacPumpPressure_kPa.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_AUXC_pscd_b_epsEna() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_AUXC_pscd_b_epsEna.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_AUXC_pscd_b_epsStopFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_AUXC_pscd_b_epsStopFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_AUXC_pscd_frq_epsFrqTgt_Hz() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_AUXC_pscd_frq_epsFrqTgt_Hz.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_DIAG_brpd_b_brkSwtMismatch() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_DIAG_brpd_b_brkSwtMismatch.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_DIAG_digd_st_edcpFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_DIAG_digd_st_edcpFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_DIAG_digd_st_hbcpFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_DIAG_digd_st_hbcpFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_DIAG_digd_st_vehSysErrLevel() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_DIAG_digd_st_vehSysErrLevel.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_EGYM_accd_pwr_hvAttpwr_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_EGYM_accd_pwr_hvAttpwr_kW.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_EGYM_egmd_b_zeroPwrFb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_EGYM_egmd_b_zeroPwrFb.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_EGYM_egmd_i_bmshAlwChgCurrMax() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_EGYM_egmd_i_bmshAlwChgCurrMax.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_EGYM_egmd_pct_vcuChgDepReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_EGYM_egmd_pct_vcuChgDepReq.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_EGYM_egmd_pwr_accmHvClPwrAllwd_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_EGYM_egmd_pwr_accmHvClPwrAllwd_kW.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_EGYM_egmd_pwr_acwpHeatPwrCnsAllwd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_EGYM_egmd_pwr_acwpHeatPwrCnsAllwd.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_EGYM_egmd_pwr_ptcHvHtPwrAllwd_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_EGYM_egmd_pwr_ptcHvHtPwrAllwd_kW.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_EGYM_egmd_st_vcuChgLimResp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_EGYM_egmd_st_vcuChgLimResp.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_V_engFuelConsAvg_lp100km() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_V_engFuelConsAvg_lp100km.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_b_CruisingDstSwtFb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_b_CruisingDstSwtFb.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_b_HazardReqLmpOn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_b_HazardReqLmpOn.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_b_brkSysFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_b_brkSysFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_b_ePTFault() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_b_ePTFault.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_b_odoBckpEn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_b_odoBckpEn.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_b_turtleLmpOn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_b_turtleLmpOn.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_d_odoTotal_km() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_d_odoTotal_km.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_d_pmsOdoBckUpMilg_km() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_d_pmsOdoBckUpMilg_km.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_d_vehCrsDst_km() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_d_vehCrsDst_km.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_d_vehDrvRngEVMod_km() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_d_vehDrvRngEVMod_km.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_d_vehDrvRngStandard_km() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_d_vehDrvRngStandard_km.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_num_AecEV_kWhp100km() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_num_AecEV_kWhp100km.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_num_errorCode() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_num_errorCode.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_pwr_hvPwrRemain_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_pwr_hvPwrRemain_kW.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_q_hvbSOC_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_q_hvbSOC_pct.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_st_drvModInd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_st_drvModInd.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_st_drvPfmncRedn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_st_drvPfmncRedn.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_st_drvrOptRmdr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_st_drvrOptRmdr.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_st_vehDrvMode() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HMIF_dspd_st_vehDrvMode.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_bmsd_e_modeTgt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_bmsd_e_modeTgt.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_dccd_e_modeTgt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_dccd_e_modeTgt.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_dccd_pct_DCDCPwrLmt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_dccd_pct_DCDCPwrLmt.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_eadd_e_inv2ModeTgt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_eadd_e_inv2ModeTgt.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_CampModeFb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_CampModeFb.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_TakeEleSwtIndReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_TakeEleSwtIndReq.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_accyHvOnCmd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_accyHvOnCmd.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_accyLvPwrOnCmd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_accyLvPwrOnCmd.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_accyPreRlyCmd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_accyPreRlyCmd.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_accyWrkEnCmd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_accyWrkEnCmd.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_allowChg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_allowChg.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_dchaOn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_dchaOn.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_hvbIntelChgExitReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_hvbIntelChgExitReq.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_lvCutOffReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_lvCutOffReq.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_tmOutFlgCfm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_tmOutFlgCfm.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_vcuWkUpCmd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_b_vcuWkUpCmd.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_e_PmmStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_e_PmmStatus.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_CampModeFbFailrReason() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_CampModeFbFailrReason.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_RmChgCmdFailPmt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_RmChgCmdFailPmt.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_accyPreRlyFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_accyPreRlyFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_accyPreRlySts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_accyPreRlySts.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_accyRlyFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_accyRlyFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_accyRlySts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_accyRlySts.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_accyRlyVoltSamSw() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_accyRlyVoltSamSw.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_accyTakeSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_accyTakeSts.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_bbmWrkEnCmd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_bbmWrkEnCmd.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_hcmMaiRlyNegClsReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_hcmMaiRlyNegClsReq.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_hvbAssiRlyPosClsReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_hvbAssiRlyPosClsReq.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_hvbMaiRlyNegClsReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_hvbMaiRlyNegClsReq.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_hvbMaiRlyPosClsReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_hvbMaiRlyPosClsReq.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_otaHvOnOFFReqSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_otaHvOnOFFReqSts.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_otaHvOnOffFailInfo() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_otaHvOnOffFailInfo.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_ptRdyInd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_ptRdyInd.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_tboxChgSftSwCtlStEV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_hvbd_st_tboxChgSftSwCtlStEV.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_HVSM_obcd_b_chargerPlugged() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_HVSM_obcd_b_chargerPlugged.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_MEST_masd_m_vehWeight_kg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_MEST_masd_m_vehWeight_kg.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_invSpdLmtRxSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_invSpdLmtRxSts.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_inventorySpdLmtReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_inventorySpdLmtReq.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_lifeCnt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_lifeCnt.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_lockVehPer() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_lockVehPer.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_lockVehPerRxSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_lockVehPerRxSts.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_pwrOffCmd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_pwrOffCmd.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_pwrOffCmdRxSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_pwrOffCmdRxSts.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_spdLmtLevelReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_spdLmtLevelReq.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_spdLmtLvRxSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_spdLmtLvRxSts.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_tboxLifeSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_tboxLifeSts.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_verCvsRxSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_verCvsRxSts.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_versionConversion() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_OGVL_dtld_st_versionConversion.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_RMLK_rlcd_b_LockVehSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_RMLK_rlcd_b_LockVehSts.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_RMLK_rlcd_num_FunAnti_DismantleActive() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_RMLK_rlcd_num_FunAnti_DismantleActive.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_RMLK_rlcd_num_FunLockVehActive() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_RMLK_rlcd_num_FunLockVehActive.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_RMLK_rlcd_num_LockLimResult() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_RMLK_rlcd_num_LockLimResult.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_RMLK_rlcd_num_LockVehType() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_RMLK_rlcd_num_LockVehType.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_RMLK_rlcd_st_LockVehExecutedSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_RMLK_rlcd_st_LockVehExecutedSts.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_SCAP_tqld_tq_whlMax_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCAP_tqld_tq_whlMax_Nm.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_SCAP_tqld_tq_whlMin_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCAP_tqld_tq_whlMin_Nm.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_SCOO_ccdd_acc_intAccTgt_mps2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCOO_ccdd_acc_intAccTgt_mps2.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_SCOO_ccdd_acc_vehAccTgt_mps2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCOO_ccdd_acc_vehAccTgt_mps2.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_SCOO_ccdd_b_accCtrlActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCOO_ccdd_b_accCtrlActv.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_SCOO_ccdd_e_crsBtnErrSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCOO_ccdd_e_crsBtnErrSts.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_SCOO_ccdd_e_crsBtnSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCOO_ccdd_e_crsBtnSts.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_SCOO_ccdd_e_crsCtrlSpdMode() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCOO_ccdd_e_crsCtrlSpdMode.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_SCOO_ccdd_e_crsCtrlSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCOO_ccdd_e_crsCtrlSts.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_SCOO_ccdd_tq_whlDem_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCOO_ccdd_tq_whlDem_Nm.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_SCOO_ccdd_v_crsCtrlTgtSpd_kph() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCOO_ccdd_v_crsCtrlTgtSpd_kph.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_SCOO_ccdd_v_crsTgtSpdQuit_kph() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCOO_ccdd_v_crsTgtSpdQuit_kph.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_SCOO_vsld_v_vehMaxSpd_kph() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_SCOO_vsld_v_vehMaxSpd_kph.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_TCOO_dtdd_st_RegenLvlDisp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_dtdd_st_RegenLvlDisp.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_TCOO_dtdd_tq_whlCoastDrgDem_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_dtdd_tq_whlCoastDrgDem_Nm.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_TCOO_tdad_tq_whlDemUnlim_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_tdad_tq_whlDemUnlim_Nm.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_TCOO_tdad_tq_whlDem_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_tdad_tq_whlDem_Nm.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_TCOO_tqdd_b_accPedlPosVirtVld() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_tqdd_b_accPedlPosVirtVld.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_TCOO_tqdd_b_gpOvrd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_tqdd_b_gpOvrd.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_TCOO_tqdd_st_ehbOvrdActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_tqdd_st_ehbOvrdActv.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_TCOO_tqdd_st_ehbOvrdTyp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_tqdd_st_ehbOvrdTyp.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_TCOO_tqdd_st_whlAcceSupprsn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_tqdd_st_whlAcceSupprsn.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_TCOO_tqdd_x_accPedlPosVirt_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_tqdd_x_accPedlPosVirt_pct.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_TCOO_tvrd_tq_mot2TgtTqReq_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_TCOO_tvrd_tq_mot2TgtTqReq_Nm.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_ActiveCool_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_ActiveCool_flg.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_BalanceHeat_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_BalanceHeat_flg.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_PassCool_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_PassCool_flg.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_PassHeat_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_PassHeat_flg.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_accmEnb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_accmEnb.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_fanRly1Req() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_fanRly1Req.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_fanRly2Req() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_fanRly2Req.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_heaterEna() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_heaterEna.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_heaterEna2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_heaterEna2.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_heaterEna3() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_heaterEna3.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_heaterEna3HW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_heaterEna3HW.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_heaterEnaHW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_heaterEnaHW.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_hvbDeft() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_hvbDeft.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_iptcHtIpuCl() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_iptcHtIpuCl.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_iptcHtIpuResvHt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_iptcHtIpuResvHt.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_ipuHeatEnableFlg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_ipuHeatEnableFlg.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_ipuResvHt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_ipuResvHt.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_ipuSupHtIptcHt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_ipuSupHtIptcHt.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_tv1V3() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_tv1V3.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_tv2V2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_tv2V2.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_wtrPmp1CtrlEnabled() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_wtrPmp1CtrlEnabled.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_wtrPmp2CtrlEnabled() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_b_wtrPmp2CtrlEnabled.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_n_FWFVTgt_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_n_FWFVTgt_pct.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_n_MHGVTgt_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_n_MHGVTgt_pct.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_n_fan1TgtSpd_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_n_fan1TgtSpd_pct.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_n_fan2TgtSpd_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_n_fan2TgtSpd_pct.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_n_pmp1TgtSpd_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_n_pmp1TgtSpd_pct.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_n_pmp2TgtSpd_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_n_pmp2TgtSpd_pct.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_pwr_ipuHeatPwrAllwd_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_pwr_ipuHeatPwrAllwd_kW.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_q_pmp2FlowFeedback() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_q_pmp2FlowFeedback.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_st_acceRlyVoltSamSwitch() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_st_acceRlyVoltSamSwitch.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_st_acwpHeat() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_st_acwpHeat.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_st_acwpSpdReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_st_acwpSpdReq.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_st_ptc3ConnStsFb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_st_ptc3ConnStsFb.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_st_ptc3RlyFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_st_ptc3RlyFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_st_ptcConnStsFb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_st_ptcConnStsFb.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_st_ptcRlyFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_st_ptcRlyFlt.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_st_ptcRlyVoltSamSwitch() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_st_ptcRlyVoltSamSwitch.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_t_acwpTemp_C() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_THSM_thmd_t_acwpTemp_C.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_VOMM_drid_b_epbClsdReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_drid_b_epbClsdReq.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_VOMM_drid_b_gearPosVld() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_drid_b_gearPosVld.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_VOMM_drid_e_driveDirSel() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_drid_e_driveDirSel.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_VOMM_drid_e_gearLvrPos() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_drid_e_gearLvrPos.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_VOMM_drid_st_gearLvrLckInd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_drid_st_gearLvrLckInd.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_VOMM_essd_b_engStopReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_essd_b_engStopReq.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_b_hsdFltClear() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_pmmd_b_hsdFltClear.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_b_nmSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_pmmd_b_nmSts.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_b_pwrHoldReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_pmmd_b_pwrHoldReq.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_b_vcuAwb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_pmmd_b_vcuAwb.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_b_vcuRmr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_pmmd_b_vcuRmr.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_num_vcuAddr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_pmmd_num_vcuAddr.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_st_bdCanModeReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_pmmd_st_bdCanModeReq.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_st_ptCanModeReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_pmmd_st_ptCanModeReq.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_st_stayAwkReason() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_pmmd_st_stayAwkReason.value)

#define Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_st_vcuWkUpReason() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VCOP_swc_VCOP_Step.Rte_vcsb_VOMM_pmmd_st_vcuWkUpReason.value)

/*
************************************************************************************************************************
*    Rte_Receive_<p>_<d> (explicit S/R communication with isQueued = true)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_Send_<p>_<d> (explicit S/R communication with isQueued = true)
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Rte_Trigger_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/


/*
************************************************************************************************************************
*    Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/
#ifndef RTE_CORE
#endif /* !defined(RTE_CORE) */

/*
************************************************************************************************************************
*    Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/
#ifndef RTE_CORE
#endif /* !defined(RTE_CORE) */

/*
************************************************************************************************************************
*    Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/
#ifndef RTE_CORE
#endif /* !defined(RTE_CORE) */

/*
************************************************************************************************************************
*    Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_IrvRead_<p>_<d> and Rte_IrvWrite_<p>_<d> Inter-runnable variables
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    extern declaration of calibration parameters buffers
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_CData (SW-C local calibration parameters) and Rte_Prm (Calibration component calibration parameters)
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    extern declaration of Buffers for Memory Block
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_Pim (Per-Instance Memory)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Runnable entities
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, swc_VCOP_CODE) swc_VCOP_Step(void);
FUNC(void, swc_VCOP_CODE) swc_VCOP_Init(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Operation Invocation Runnable entities
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Exclusive Areas.
************************************************************************************************************************
*/

#ifdef __cplusplus
}                  
#endif            
#endif /* RTE_SWC_VCOP_H_ */
 
 
 
